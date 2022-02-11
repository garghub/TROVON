int F_1 ( T_1 * V_1 , unsigned char * V_2 , int * V_3 ,
int V_4 )
{
if ( V_2 ) {
if ( ( V_1 -> V_5 -> V_6 + 1 ) > V_4 ) {
F_2 ( V_7 ,
V_8 ) ;
return 0 ;
}
* V_2 = V_1 -> V_5 -> V_6 ;
V_2 ++ ;
memcpy ( V_2 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ;
#ifdef F_3
fprintf ( V_10 , L_1 ,
V_1 -> V_5 -> V_6 ? L_2 : L_3 ) ;
#endif
}
* V_3 = V_1 -> V_5 -> V_6 + 1 ;
return 1 ;
}
int F_4 ( T_1 * V_1 , unsigned char * V_11 , int V_3 ,
int * V_12 )
{
int V_13 ;
if ( V_3 < 1 ) {
F_2 ( V_14 ,
V_15 ) ;
* V_12 = V_16 ;
return 0 ;
}
V_13 = * V_11 ;
V_11 ++ ;
if ( ( V_13 + 1 ) != V_3 ) {
F_2 ( V_14 ,
V_15 ) ;
* V_12 = V_16 ;
return 0 ;
}
if ( V_13 != V_1 -> V_5 -> V_6 ) {
F_2 ( V_14 ,
V_17 ) ;
* V_12 = V_18 ;
return 0 ;
}
if ( memcmp ( V_11 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ) {
F_2 ( V_14 ,
V_17 ) ;
* V_12 = V_18 ;
return 0 ;
}
#ifdef F_3
fprintf ( V_10 , L_4 ,
V_13 ? L_2 : L_3 ) ;
#endif
V_1 -> V_5 -> V_19 = 1 ;
return 1 ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_2 , int * V_3 ,
int V_4 )
{
if ( V_2 ) {
if ( ( V_1 -> V_5 -> V_6 +
V_1 -> V_5 -> V_20 + 1 ) > V_4 ) {
F_2 ( V_21 ,
V_8 ) ;
return 0 ;
}
* V_2 = V_1 -> V_5 -> V_6 +
V_1 -> V_5 -> V_20 ;
V_2 ++ ;
memcpy ( V_2 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ;
V_2 += V_1 -> V_5 -> V_6 ;
memcpy ( V_2 , V_1 -> V_5 -> V_22 ,
V_1 -> V_5 -> V_20 ) ;
#ifdef F_3
fprintf ( V_10 , L_5 ,
V_1 -> V_5 -> V_6 ? L_2 : L_3 ) ;
#endif
}
* V_3 = V_1 -> V_5 -> V_6
+ V_1 -> V_5 -> V_20 + 1 ;
return 1 ;
}
int F_6 ( T_1 * V_1 , unsigned char * V_11 , int V_3 ,
int * V_12 )
{
int V_23 = V_1 -> V_5 -> V_6
+ V_1 -> V_5 -> V_20 ;
int V_13 ;
F_7 ( ! V_23 || V_1 -> V_5 -> V_6 ) ;
F_7 ( ! V_23 || V_1 -> V_5 -> V_20 ) ;
if ( V_3 < 1 ) {
F_2 ( V_24 ,
V_15 ) ;
* V_12 = V_16 ;
return 0 ;
}
V_13 = * V_11 ;
V_11 ++ ;
if ( V_13 + 1 != V_3 ) {
F_2 ( V_24 ,
V_15 ) ;
* V_12 = V_16 ;
return 0 ;
}
if ( V_13 != V_23 ) {
F_2 ( V_24 ,
V_17 ) ;
* V_12 = V_18 ;
return 0 ;
}
if ( memcmp ( V_11 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ) {
F_2 ( V_24 ,
V_17 ) ;
* V_12 = V_18 ;
return 0 ;
}
V_11 += V_1 -> V_5 -> V_6 ;
if ( memcmp ( V_11 , V_1 -> V_5 -> V_22 ,
V_1 -> V_5 -> V_20 ) ) {
F_2 ( V_24 ,
V_17 ) ;
* V_12 = V_16 ;
return 0 ;
}
#ifdef F_3
fprintf ( V_10 , L_6 ,
V_13 ? L_2 : L_3 ) ;
#endif
V_1 -> V_5 -> V_19 = 1 ;
return 1 ;
}
