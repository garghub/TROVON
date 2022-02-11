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
return 0 ;
}
int F_9 ( struct V_19 * V_20 )
{
int V_9 = - V_21 ;
if ( F_10 () ) {
F_2 ( V_22
L_6 ,
V_13 ,
V_12 , V_15 , V_16 ) ;
F_11 ( & V_23 ) ;
V_9 = F_12 ( V_20 , & V_23 ,
V_24 ) ;
}
return V_9 ;
}
static int T_2 F_13 ( char * V_25 )
{
int V_26 [ 4 ] ;
V_25 = F_14 ( V_25 , F_15 ( V_26 ) , V_26 ) ;
if ( V_26 [ 0 ] >= 1 ) V_12 = V_26 [ 1 ] ;
if ( V_26 [ 0 ] >= 2 ) V_15 = V_26 [ 2 ] ;
if ( V_26 [ 0 ] >= 3 ) V_16 = V_26 [ 3 ] ;
return 1 ;
}
