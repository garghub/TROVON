void F_1 ( void )
{
int V_1 ;
if ( V_2 < V_3 )
return;
F_2 (nid) {
T_1 * V_4 = F_3 ( V_1 ) ;
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
void T_2 F_9 ( void )
{
int V_20 , V_21 ;
unsigned long V_22 , V_23 ;
V_20 = 8 * sizeof( unsigned long ) ;
V_21 = V_20 - V_24 - V_25 - V_26 ;
F_10 ( V_27 , L_7 ,
L_8 ,
V_24 ,
V_25 ,
V_26 ,
V_28 ) ;
F_10 ( V_27 , L_9 ,
L_10 ,
V_29 ,
V_30 ,
V_31 ) ;
F_10 ( V_27 , L_11 ,
L_12 ,
( unsigned long ) V_32 ,
( unsigned long ) V_33 ,
( unsigned long ) V_34 ) ;
F_10 ( V_27 , L_13 ,
L_14 ,
( unsigned long ) V_35 ,
( unsigned long ) ( V_35 + V_36 ) ) ;
F_10 ( V_27 , L_15 ,
L_16 ,
V_20 , V_21 , V_21 , V_28 , V_28 , 0 ) ;
#ifdef F_11
F_10 ( V_27 , L_17 ,
L_18 ) ;
#endif
if ( V_24 ) {
V_20 -= V_24 ;
F_4 ( V_20 != V_32 ) ;
}
if ( V_25 ) {
V_20 -= V_25 ;
F_4 ( V_20 != V_33 ) ;
}
if ( V_26 ) {
V_20 -= V_26 ;
F_4 ( V_20 != V_34 ) ;
}
V_22 = ( V_37 << V_34 ) |
( V_38 << V_33 ) |
( V_39 << V_32 ) ;
V_23 = ( V_37 << V_34 ) +
( V_38 << V_33 ) +
( V_39 << V_32 ) ;
F_4 ( V_22 != V_23 ) ;
}
void T_3 F_12 ( struct V_40 * V_40 , enum V_41 V_5 ,
unsigned long V_1 , unsigned long V_42 )
{
F_4 ( F_13 ( V_40 ) != V_1 ) ;
F_4 ( F_14 ( V_40 ) != V_5 ) ;
F_4 ( F_15 ( V_40 ) != V_42 ) ;
}
static T_2 int F_16 ( char * V_43 )
{
F_17 ( & V_43 , & V_2 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
V_44 = F_19 ( L_19 , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
return 0 ;
}
