static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 , V_4 , V_5 ;
struct V_6 * V_6 ;
V_6 = F_2 ( F_3 ( V_7 ) ) ;
for ( V_3 = V_7 ;
V_3 <= V_8 ; V_3 ++ ) {
V_4 = F_3 ( V_3 ) ;
V_5 = V_9 [ V_10 + V_3 ] ;
while ( V_11 [ V_3 ] < V_5 ) {
if ( V_3 != V_7 ) {
struct V_12 * V_13 = F_4 ( V_4 ) ;
if ( V_6 && V_6 -> V_14 )
V_6 -> V_14 ( V_13 ) ;
}
F_5 ( V_4 ) ;
V_11 [ V_3 ] ++ ;
}
}
return V_15 ;
}
void T_2 F_6 ( void )
{
void * V_16 ;
unsigned int V_17 ;
struct V_18 V_19 ;
unsigned long V_20 , V_21 ;
int V_22 , V_23 ;
V_16 = & V_24 ;
V_17 = & V_25 - & V_24 ;
F_7 ( L_1 ,
V_16 , V_17 ) ;
V_23 = F_8 ( & V_26 ) ;
if ( V_23 ) {
F_9 ( L_2 ,
V_23 ) ;
return;
}
V_23 = F_10 ( V_27 , F_1 ,
V_28 , L_3 , NULL ) ;
if ( V_23 < 0 ) {
F_9 ( L_4 , V_23 ) ;
F_11 ( & V_26 ) ;
return;
}
V_21 = V_29 + V_27 * 0x4 ;
V_20 = F_12 ( V_30 + V_21 ) & ~ ( 1 << 1 ) ;
F_13 ( V_20 , V_30 + V_21 ) ;
F_14 ( V_16 , V_17 ) ;
V_9 [ V_31 ] = 0 ;
V_9 [ V_32 ] = 0 ;
V_9 [ V_33 ] = 0 ;
V_9 [ V_34 ] = 0 ;
V_9 [ V_35 ] = 0 ;
V_9 [ V_36 ] = 0 ;
V_9 [ V_37 ] = 0 ;
V_9 [ V_38 ] = 0 ;
V_9 [ V_39 ] = 256 ;
V_9 [ V_40 ] = 0 ;
V_9 [ V_41 ] =
( unsigned int ) & V_9 [ V_42 ] ;
for ( V_22 = V_10 ; V_22 <= V_43 ; V_22 ++ )
V_9 [ V_22 ] = 0 ;
V_19 . V_44 = ( unsigned int ) V_9 ;
F_15 ( & V_19 ) ;
F_7 ( L_5 , V_9 ) ;
V_21 = V_29 + V_45 * 0x4 ;
V_20 = F_12 ( V_46 + V_21 ) | 1 ;
F_13 ( V_20 , V_46 + V_21 ) ;
}
