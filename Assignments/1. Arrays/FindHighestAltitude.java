public class FindHighestAltitude {
    static int largestAltitude(int[] gain) {
        int[] altitude = new int[gain.length+1];
        altitude[0] = 0;
        int len = altitude.length;
        for(int i = 1; i < len; i++){
            altitude[i] = altitude[i-1] + gain[i-1];
        }
        int highestAltitude = altitude[0];
        for(int i = 0; i < len; i++){
            if(altitude[i] > highestAltitude){
                highestAltitude = altitude[i];
            }
        }
        return highestAltitude;
    }
}
