static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 , V_8 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_2 , 0x15 , V_3 , V_5 ) ;
F_3 ( V_2 , 0x75 , V_4 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_9 , ... )
{
T_1 args ;
int V_10 , V_11 ;
T_2 * V_12 = ( T_2 * ) V_2 -> V_12 ;
if ( F_5 ( V_2 -> V_13 & V_14 ) ) {
va_start ( args , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_12 [ V_10 ] = ( T_2 ) va_arg (args, unsigned int) ;
va_end ( args ) ;
F_6 ( V_14 , V_2 , V_2 -> V_15 -> V_16 , T_2 , V_12 , V_9 , L_2 , V_8 ) ;
}
va_start ( args , V_9 ) ;
* V_12 = ( T_2 ) va_arg (args, unsigned int) ;
if ( V_2 -> V_17 . V_18 != - 1 )
F_7 ( V_2 -> V_17 . V_18 , 0 ) ;
V_11 = V_2 -> V_19 . V_20 ( V_2 , V_2 -> V_12 , sizeof( T_2 ) ) ;
if ( V_11 < 0 ) {
va_end ( args ) ;
F_8 ( V_2 -> V_15 -> V_16 ,
L_3 , V_11 ) ;
return;
}
V_9 -- ;
if ( V_9 ) {
V_10 = V_9 ;
while ( V_10 -- )
* V_12 ++ = ( T_2 ) va_arg (args, unsigned int) ;
V_11 = V_2 -> V_19 . V_20 ( V_2 , V_2 -> V_12 , V_9 * ( sizeof( T_2 ) ) ) ;
if ( V_11 < 0 ) {
va_end ( args ) ;
F_8 ( V_2 -> V_15 -> V_16 ,
L_3 , V_11 ) ;
return;
}
}
if ( V_2 -> V_17 . V_18 != - 1 )
F_7 ( V_2 -> V_17 . V_18 , 1 ) ;
va_end ( args ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long * V_21 )
{
unsigned long V_22 [ V_23 * V_24 ] ;
int V_10 , V_25 = 0 ;
F_2 ( V_26 , V_2 , L_4 , V_8 ) ;
for ( V_10 = 0 ; V_10 < 63 ; V_10 ++ ) {
if ( V_10 > 0 && V_21 [ V_10 ] < 2 ) {
F_8 ( V_2 -> V_15 -> V_16 ,
L_5 \
L_6 , V_10 ) ;
return - V_27 ;
}
V_25 += V_21 [ V_10 ] ;
V_22 [ V_10 ] = V_25 ;
if ( V_25 > 180 ) {
F_8 ( V_2 -> V_15 -> V_16 ,
L_7 \
L_8 , V_10 ) ;
return - V_27 ;
}
}
F_3 ( V_2 , 0xB8 ,
V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] , V_22 [ 4 ] , V_22 [ 5 ] , V_22 [ 6 ] , V_22 [ 7 ] ,
V_22 [ 8 ] , V_22 [ 9 ] , V_22 [ 10 ] , V_22 [ 11 ] , V_22 [ 12 ] , V_22 [ 13 ] , V_22 [ 14 ] , V_22 [ 15 ] ,
V_22 [ 16 ] , V_22 [ 17 ] , V_22 [ 18 ] , V_22 [ 19 ] , V_22 [ 20 ] , V_22 [ 21 ] , V_22 [ 22 ] , V_22 [ 23 ] ,
V_22 [ 24 ] , V_22 [ 25 ] , V_22 [ 26 ] , V_22 [ 27 ] , V_22 [ 28 ] , V_22 [ 29 ] , V_22 [ 30 ] , V_22 [ 31 ] ,
V_22 [ 32 ] , V_22 [ 33 ] , V_22 [ 34 ] , V_22 [ 35 ] , V_22 [ 36 ] , V_22 [ 37 ] , V_22 [ 38 ] , V_22 [ 39 ] ,
V_22 [ 40 ] , V_22 [ 41 ] , V_22 [ 42 ] , V_22 [ 43 ] , V_22 [ 44 ] , V_22 [ 45 ] , V_22 [ 46 ] , V_22 [ 47 ] ,
V_22 [ 48 ] , V_22 [ 49 ] , V_22 [ 50 ] , V_22 [ 51 ] , V_22 [ 52 ] , V_22 [ 53 ] , V_22 [ 54 ] , V_22 [ 55 ] ,
V_22 [ 56 ] , V_22 [ 57 ] , V_22 [ 58 ] , V_22 [ 59 ] , V_22 [ 60 ] , V_22 [ 61 ] , V_22 [ 62 ] ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_28 )
{
F_2 ( V_29 , V_2 , L_9 ,
V_8 , V_28 ? L_10 : L_11 ) ;
if ( V_28 )
F_3 ( V_2 , 0xAE ) ;
else
F_3 ( V_2 , 0xAF ) ;
return 0 ;
}
