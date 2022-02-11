static T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & V_2 ) >> ( F_2 ( V_2 ) - 1 ) ;
}
static void T_2 F_3 ( struct V_3 * V_4 )
{
unsigned long V_5 , V_6 , V_7 ;
T_3 V_8 , V_9 , V_10 , V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
V_14 = F_4 ( V_4 -> V_18 ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( L_1 ) ;
return;
}
V_17 = F_7 ( V_14 , V_19 , & V_8 ) ;
if ( V_17 ) {
F_6 ( L_2 , V_17 ) ;
return;
}
V_5 = F_1 ( V_8 , V_20 ) * 1000000 ;
V_9 = F_1 ( V_8 , V_21 ) ;
V_11 = F_1 ( V_8 , V_22 ) ;
V_7 = F_8 ( V_5 , V_9 , V_11 ) ;
V_10 = F_1 ( V_8 , V_23 ) ;
V_6 = F_8 ( V_5 , V_9 , V_10 ) ;
V_13 = F_9 ( sizeof( * V_13 ) +
( V_24 * sizeof( struct V_15 * ) ) ,
V_25 ) ;
if ( ! V_13 )
return;
V_13 -> V_26 = V_24 ;
V_16 = F_10 ( NULL , L_3 , NULL , 0 , V_5 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( L_4 , F_11 ( V_16 ) ) ;
return;
}
V_13 -> V_27 [ V_28 ] = V_16 ;
V_16 = F_10 ( NULL , L_5 , L_3 , 0 , V_7 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( L_6 , F_11 ( V_16 ) ) ;
return;
}
V_13 -> V_27 [ V_29 ] = V_16 ;
V_16 = F_10 ( NULL , L_7 , L_3 , 0 , V_6 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( L_8 , F_11 ( V_16 ) ) ;
return;
}
V_13 -> V_27 [ V_30 ] = V_16 ;
V_17 = F_12 ( V_4 , V_31 , V_13 ) ;
if ( V_17 )
F_6 ( L_9 , V_17 ) ;
}
