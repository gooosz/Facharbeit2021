import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;

public class Rechnung {

	public static void main(String[] args) {
		/*BigDecimal log = BigDecimal.valueOf(Math.log10(2));
    	BigDecimal x = BigDecimal.valueOf(2048);
    	BigDecimal simplification = new BigDecimal("3.7685889929166");
    	simplification = simplification.pow(501);
    	BigDecimal simplification2 = simplification.multiply(simplification);
    	BigDecimal solution = x.multiply(simplification2).multiply(log);
    	System.out.println(solution);
        
        BigDecimal zeit = BigDecimal.valueOf(25);
        zeit.movePointRight(11);
        BigDecimal zeit2 = solution.multiply(zeit);
        
        BigDecimal inMinuten = BigDecimal.valueOf(60);
        BigDecimal minute = zeit2.divide(inMinuten, RoundingMode.HALF_UP);
        System.out.println("minuten: " + minute);
        
        BigDecimal inStunden = BigDecimal.valueOf(60);
        BigDecimal stunde = minute.divide(inStunden, RoundingMode.HALF_UP);
        System.out.println("Stunden: " + stunde);
        
        BigDecimal inTagen = BigDecimal.valueOf(24);
        BigDecimal tage = stunde.divide(inTagen, RoundingMode.HALF_UP);
        System.out.println("Tage: " + tage);
        
        BigDecimal inJahren = BigDecimal.valueOf(365);
        BigDecimal jahre = tage.divide(inJahren, RoundingMode.HALF_UP);
        System.out.println("Jahre: " + jahre);
        System.out.println(jahre.toString().length());
        
        BigDecimal log = BigDecimal.valueOf(Math.log10(2));
    	BigDecimal x = BigDecimal.valueOf(2048);
    	BigDecimal simplification = new BigDecimal("3.7685889929166");
    	simplification = simplification.pow(501);
    	BigDecimal simplification2 = simplification.multiply(simplification);
    	BigDecimal solution = x.multiply(simplification2).multiply(log);
    	System.out.println(solution);*/
    	
    	// eins * zwei * drei
		// (log 2^2048)^2 * (log log 2^2048) * (log log log 2^2048)
		BigDecimal n = BigDecimal.valueOf(2);
		n = n.pow(2048);
		BigDecimal loga = log(10, n);
		BigDecimal eins = loga.pow(2);
		System.out.println(eins);
		BigDecimal zwei = log(10, loga);
		System.out.println(zwei);
		BigDecimal drei = log(10, zwei);
		System.out.println(drei);
		
		BigDecimal ergebnis = eins.multiply(zwei);
		ergebnis.multiply(drei);
		System.out.println(ergebnis);
    }
    

    public static BigDecimal log(int base_int, BigDecimal x) {
        BigDecimal result = BigDecimal.ZERO;

        BigDecimal input = new BigDecimal(x.toString());
        int decimalPlaces = 100;
        int scale = input.precision() + decimalPlaces;

        int maxite = 10000;
        int ite = 0;
        BigDecimal maxError_BigDecimal = new BigDecimal(BigInteger.ONE,decimalPlaces + 1);
        System.out.println("maxError_BigDecimal " + maxError_BigDecimal);
        System.out.println("scale " + scale);

        RoundingMode a_RoundingMode = RoundingMode.UP;

        BigDecimal two_BigDecimal = new BigDecimal("2");
        BigDecimal base_BigDecimal = new BigDecimal(base_int);

        while (input.compareTo(base_BigDecimal) == 1) {
            result = result.add(BigDecimal.ONE);
            input = input.divide(base_BigDecimal, scale, a_RoundingMode);
        }

        BigDecimal fraction = new BigDecimal("0.5");
        input = input.multiply(input);
        BigDecimal resultplusfraction = result.add(fraction);
        while (((resultplusfraction).compareTo(result) == 1)
                && (input.compareTo(BigDecimal.ONE) == 1)) {
            if (input.compareTo(base_BigDecimal) == 1) {
                input = input.divide(base_BigDecimal, scale, a_RoundingMode);
                result = result.add(fraction);
            }
            input = input.multiply(input);
            fraction = fraction.divide(two_BigDecimal, scale, a_RoundingMode);
            resultplusfraction = result.add(fraction);
            if (fraction.abs().compareTo(maxError_BigDecimal) == -1){
                break;
            }
            if (maxite == ite){
                break;
            }
            ite ++;
        }

        MathContext a_MathContext = new MathContext(((decimalPlaces - 1) + (result.precision() - result.scale())),RoundingMode.HALF_UP);
        BigDecimal roundedResult = result.round(a_MathContext);
        BigDecimal strippedRoundedResult = roundedResult.stripTrailingZeros();
        //return result;
        //return result.round(a_MathContext);
        return strippedRoundedResult;
    }

}
