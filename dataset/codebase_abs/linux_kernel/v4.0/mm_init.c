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
F_6 ( V_18 L_4 ,
V_5 -> V_19 , V_5 -> V_17 ) ;
#else
F_6 ( V_18 L_5 , V_5 -> V_17 ) ;
#endif
}
F_6 ( V_18 L_6 ) ;
}
}
}
void T_1 F_9 ( void )
{
int V_20 , V_21 ;
unsigned long V_22 , V_23 ;
V_20 = 8 * sizeof( unsigned long ) ;
V_21 = V_20 - V_24 - V_25 - V_26 - V_27 ;
F_10 ( V_28 , L_7 ,
L_8 ,
V_24 ,
V_25 ,
V_26 ,
V_29 ,
V_30 ) ;
F_10 ( V_28 , L_9 ,
L_10 ,
V_31 ,
V_32 ,
V_33 ,
V_27 ) ;
F_10 ( V_28 , L_11 ,
L_12 ,
( unsigned long ) V_34 ,
( unsigned long ) V_35 ,
( unsigned long ) V_36 ,
( unsigned long ) V_37 ) ;
F_10 ( V_28 , L_13 ,
L_14 ,
( unsigned long ) ( V_38 + V_39 ) ,
( unsigned long ) V_38 ) ;
F_10 ( V_28 , L_15 ,
L_16 ,
V_20 , V_21 , V_21 , V_30 , V_30 , 0 ) ;
#ifdef F_11
F_10 ( V_28 , L_17 ,
L_18 ) ;
#endif
#ifdef F_12
F_10 ( V_28 , L_17 ,
L_19 ) ;
#endif
if ( V_24 ) {
V_20 -= V_24 ;
F_4 ( V_20 != V_34 ) ;
}
if ( V_25 ) {
V_20 -= V_25 ;
F_4 ( V_20 != V_35 ) ;
}
if ( V_26 ) {
V_20 -= V_26 ;
F_4 ( V_20 != V_36 ) ;
}
V_22 = ( V_40 << V_36 ) |
( V_41 << V_35 ) |
( V_42 << V_34 ) ;
V_23 = ( V_40 << V_36 ) +
( V_41 << V_35 ) +
( V_42 << V_34 ) ;
F_4 ( V_22 != V_23 ) ;
}
void T_3 F_13 ( struct V_43 * V_43 , enum V_44 V_5 ,
unsigned long V_1 , unsigned long V_45 )
{
F_4 ( F_14 ( V_43 ) != V_1 ) ;
F_4 ( F_15 ( V_43 ) != V_5 ) ;
F_4 ( F_16 ( V_43 ) != V_45 ) ;
}
static T_1 int F_17 ( char * V_46 )
{
F_18 ( & V_46 , & V_2 ) ;
return 0 ;
}
static void T_3 F_19 ( void )
{
T_4 V_47 ;
T_5 V_48 = F_20 () ;
T_5 V_49 = F_21 ( T_5 , V_48 * 2 , 32 ) ;
V_47 = F_22 ( T_4 , ( V_50 / V_48 ) / 256 , 0x7fffffff ) ;
V_51 = F_21 ( T_5 , V_47 , V_49 ) ;
}
static int T_3 F_23 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
switch ( V_54 ) {
case V_56 :
case V_57 :
F_19 () ;
default:
break;
}
return V_58 ;
}
static int T_1 F_24 ( void )
{
F_19 () ;
F_25 ( & V_59 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
V_60 = F_27 ( L_20 , V_61 ) ;
if ( ! V_60 )
return - V_62 ;
return 0 ;
}
