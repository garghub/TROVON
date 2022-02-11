void T_1 F_1 ( void )
{
int V_1 ;
if ( V_2 < V_3 )
return;
F_2 (nid) {
T_2 * V_4 = F_3 ( V_1 ) ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_9 , V_10 , V_11 ;
F_4 ( V_12 > 2 ) ;
for ( V_9 = 0 ; V_9 < V_12 * V_13 ; V_9 ++ ) {
V_11 = V_9 % V_13 ;
V_10 = V_9 / V_13 ;
V_8 = & V_4 -> V_14 [ V_10 ] ;
V_5 = & V_4 -> V_15 [ V_11 ] ;
if ( ! F_5 ( V_5 ) )
continue;
F_6 ( V_16 L_1 ,
V_10 > 0 ? L_2 : L_3 , V_1 ,
V_5 -> V_17 ) ;
F_7 (zone, z, zonelist, zoneid) {
#ifdef F_8
F_9 ( L_4 , V_5 -> V_18 , V_5 -> V_17 ) ;
#else
F_9 ( L_5 , V_5 -> V_17 ) ;
#endif
}
F_9 ( L_6 ) ;
}
}
}
void T_1 F_10 ( void )
{
int V_19 , V_20 ;
unsigned long V_21 , V_22 ;
V_19 = 8 * sizeof( unsigned long ) ;
V_20 = V_19 - V_23 - V_24 - V_25 - V_26 ;
F_11 ( V_27 , L_7 ,
L_8 ,
V_23 ,
V_24 ,
V_25 ,
V_28 ,
V_29 ) ;
F_11 ( V_27 , L_9 ,
L_10 ,
V_30 ,
V_31 ,
V_32 ,
V_26 ) ;
F_11 ( V_27 , L_11 ,
L_12 ,
( unsigned long ) V_33 ,
( unsigned long ) V_34 ,
( unsigned long ) V_35 ,
( unsigned long ) V_36 ) ;
F_11 ( V_27 , L_13 ,
L_14 ,
( unsigned long ) ( V_37 + V_38 ) ,
( unsigned long ) V_37 ) ;
F_11 ( V_27 , L_15 ,
L_16 ,
V_19 , V_20 , V_20 , V_29 , V_29 , 0 ) ;
#ifdef F_12
F_11 ( V_27 , L_17 ,
L_18 ) ;
#endif
#ifdef F_13
F_11 ( V_27 , L_17 ,
L_19 ) ;
#endif
if ( V_23 ) {
V_19 -= V_23 ;
F_4 ( V_19 != V_33 ) ;
}
if ( V_24 ) {
V_19 -= V_24 ;
F_4 ( V_19 != V_34 ) ;
}
if ( V_25 ) {
V_19 -= V_25 ;
F_4 ( V_19 != V_35 ) ;
}
V_21 = ( V_39 << V_35 ) |
( V_40 << V_34 ) |
( V_41 << V_33 ) ;
V_22 = ( V_39 << V_35 ) +
( V_40 << V_34 ) +
( V_41 << V_33 ) ;
F_4 ( V_21 != V_22 ) ;
}
static T_1 int F_14 ( char * V_42 )
{
F_15 ( & V_42 , & V_2 ) ;
return 0 ;
}
static void T_3 F_16 ( void )
{
T_4 V_43 ;
T_5 V_44 = F_17 () ;
T_5 V_45 = F_18 ( T_5 , V_44 * 2 , 32 ) ;
V_43 = F_19 ( T_4 , ( V_46 / V_44 ) / 256 , 0x7fffffff ) ;
V_47 = F_18 ( T_5 , V_43 , V_45 ) ;
}
static int T_3 F_20 ( struct V_48 * V_49 ,
unsigned long V_50 , void * V_51 )
{
switch ( V_50 ) {
case V_52 :
case V_53 :
F_16 () ;
default:
break;
}
return V_54 ;
}
static int T_1 F_21 ( void )
{
F_16 () ;
F_22 ( & V_55 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
V_56 = F_24 ( L_20 , V_57 ) ;
if ( ! V_56 )
return - V_58 ;
return 0 ;
}
