static void F_1 ( const char * V_1 ,
const char * V_2 ,
int V_3 , int V_4 )
{
F_2 ( V_5
L_1
L_2 ,
V_1 , V_2 ,
V_4 / 10 , V_4 % 10 ,
V_2 ,
V_3 / 10 , V_3 % 10 ) ;
}
static int
F_3 ( struct V_6 * V_7 , const T_1 * V_8 )
{
int V_9 ;
switch ( V_7 -> V_10 ) {
case 0 :
if ( ( V_8 -> V_11 != 0 ) &&
( V_8 -> V_11 != V_12 ) ) {
F_1 ( V_13 , L_3 ,
V_12 , V_8 -> V_11 ) ;
}
if ( ( V_8 -> V_14 != 0 ) &&
( V_8 -> V_14 != V_15 ) ) {
F_1 ( V_13 , L_4 ,
V_15 , V_8 -> V_14 ) ;
return - 1 ;
}
break;
case 1 :
if ( ( V_8 -> V_11 != 0 ) &&
( V_8 -> V_11 != V_16 ) ) {
F_1 ( V_13 , L_5 ,
V_16 , V_8 -> V_11 ) ;
return - 1 ;
}
break;
default:
return - 1 ;
}
V_9 = F_4 ( V_7 , V_8 ) ;
if ( V_9 == 0 ) {
unsigned long V_17 ;
int V_18 ;
F_5 ( V_17 ) ;
V_18 = ( ( V_8 -> V_11 == 50 ) || ( V_8 -> V_14 == 50 ) ) ;
F_6 ( F_7 ( V_7 -> V_10 ) , V_18 ) ;
F_8 ( V_17 ) ;
}
return V_9 ;
}
int F_9 ( struct V_19 * V_20 )
{
F_2 ( V_21
L_6 ,
V_13 ,
V_12 , V_15 , V_16 ) ;
F_10 ( & V_22 ) ;
return F_11 ( V_20 , & V_22 ,
V_23 ) ;
}
static int T_2 F_12 ( char * V_24 )
{
int V_25 [ 4 ] ;
V_24 = F_13 ( V_24 , F_14 ( V_25 ) , V_25 ) ;
if ( V_25 [ 0 ] >= 1 ) V_12 = V_25 [ 1 ] ;
if ( V_25 [ 0 ] >= 2 ) V_15 = V_25 [ 2 ] ;
if ( V_25 [ 0 ] >= 3 ) V_16 = V_25 [ 3 ] ;
return 1 ;
}
