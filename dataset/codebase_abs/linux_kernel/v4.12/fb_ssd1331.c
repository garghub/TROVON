static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_2 , 0x15 , V_3 , V_5 ) ;
F_2 ( V_2 , 0x75 , V_4 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_7 , ... )
{
T_1 args ;
int V_8 , V_9 ;
T_2 * V_10 = V_2 -> V_10 ;
if ( F_4 ( V_2 -> V_11 & V_12 ) ) {
va_start ( args , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_10 [ V_8 ] = ( T_2 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_5 ( V_12 , V_2 , V_2 -> V_13 -> V_14 , T_2 , V_10 , V_7 , L_1 , V_15 ) ;
}
va_start ( args , V_7 ) ;
* V_10 = ( T_2 ) va_arg (args, unsigned int) ;
if ( V_2 -> V_16 . V_17 != - 1 )
F_6 ( V_2 -> V_16 . V_17 , 0 ) ;
V_9 = V_2 -> V_18 . V_19 ( V_2 , V_2 -> V_10 , sizeof( T_2 ) ) ;
if ( V_9 < 0 ) {
va_end ( args ) ;
F_7 ( V_2 -> V_13 -> V_14 ,
L_2 , V_9 ) ;
return;
}
V_7 -- ;
if ( V_7 ) {
V_8 = V_7 ;
while ( V_8 -- )
* V_10 ++ = ( T_2 ) va_arg (args, unsigned int) ;
V_9 = V_2 -> V_18 . V_19 ( V_2 , V_2 -> V_10 , V_7 * ( sizeof( T_2 ) ) ) ;
if ( V_9 < 0 ) {
va_end ( args ) ;
F_7 ( V_2 -> V_13 -> V_14 ,
L_2 , V_9 ) ;
return;
}
}
if ( V_2 -> V_16 . V_17 != - 1 )
F_6 ( V_2 -> V_16 . V_17 , 1 ) ;
va_end ( args ) ;
}
static int F_8 ( struct V_1 * V_2 , T_3 * V_20 )
{
unsigned long V_21 [ V_22 * V_23 ] ;
int V_8 , V_24 = 0 ;
for ( V_8 = 0 ; V_8 < 63 ; V_8 ++ ) {
if ( V_8 > 0 && V_20 [ V_8 ] < 2 ) {
F_7 ( V_2 -> V_13 -> V_14 ,
L_3 ,
V_8 ) ;
return - V_25 ;
}
V_24 += V_20 [ V_8 ] ;
V_21 [ V_8 ] = V_24 ;
if ( V_24 > 180 ) {
F_7 ( V_2 -> V_13 -> V_14 ,
L_4 ,
V_8 ) ;
return - V_25 ;
}
}
F_2 ( V_2 , 0xB8 ,
V_21 [ 0 ] , V_21 [ 1 ] , V_21 [ 2 ] , V_21 [ 3 ] , V_21 [ 4 ] , V_21 [ 5 ] , V_21 [ 6 ] ,
V_21 [ 7 ] , V_21 [ 8 ] , V_21 [ 9 ] , V_21 [ 10 ] , V_21 [ 11 ] , V_21 [ 12 ] , V_21 [ 13 ] ,
V_21 [ 14 ] , V_21 [ 15 ] , V_21 [ 16 ] , V_21 [ 17 ] , V_21 [ 18 ] , V_21 [ 19 ] , V_21 [ 20 ] ,
V_21 [ 21 ] , V_21 [ 22 ] , V_21 [ 23 ] , V_21 [ 24 ] , V_21 [ 25 ] , V_21 [ 26 ] , V_21 [ 27 ] ,
V_21 [ 28 ] , V_21 [ 29 ] , V_21 [ 30 ] , V_21 [ 31 ] , V_21 [ 32 ] , V_21 [ 33 ] , V_21 [ 34 ] ,
V_21 [ 35 ] , V_21 [ 36 ] , V_21 [ 37 ] , V_21 [ 38 ] , V_21 [ 39 ] , V_21 [ 40 ] , V_21 [ 41 ] ,
V_21 [ 42 ] , V_21 [ 43 ] , V_21 [ 44 ] , V_21 [ 45 ] , V_21 [ 46 ] , V_21 [ 47 ] , V_21 [ 48 ] ,
V_21 [ 49 ] , V_21 [ 50 ] , V_21 [ 51 ] , V_21 [ 52 ] , V_21 [ 53 ] , V_21 [ 54 ] , V_21 [ 55 ] ,
V_21 [ 56 ] , V_21 [ 57 ] , V_21 [ 58 ] , V_21 [ 59 ] , V_21 [ 60 ] , V_21 [ 61 ] ,
V_21 [ 62 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_26 )
{
F_10 ( V_27 , V_2 , L_5 ,
V_15 , V_26 ? L_6 : L_7 ) ;
if ( V_26 )
F_2 ( V_2 , 0xAE ) ;
else
F_2 ( V_2 , 0xAF ) ;
return 0 ;
}
