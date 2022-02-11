static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_4 = NULL ;
int V_5 , V_6 , V_7 ;
V_3 = F_2 ( F_3 ( V_8 ) ) ;
if ( V_3 )
V_4 = V_3 -> V_9 . V_10 ;
for ( V_5 = V_8 ;
V_5 <= V_11 ; V_5 ++ ) {
V_6 = F_3 ( V_5 ) ;
V_7 = V_12 [ V_13 + V_5 ] ;
while ( V_14 [ V_5 ] < V_7 ) {
if ( V_5 != V_8 ) {
struct V_9 * V_15 = F_4 ( V_6 ) ;
if ( V_4 && V_4 -> V_16 )
V_4 -> V_16 ( V_15 ) ;
}
F_5 ( V_6 ) ;
V_14 [ V_5 ] ++ ;
}
}
return V_17 ;
}
void T_2 F_6 ( void )
{
void * V_18 ;
unsigned int V_19 ;
struct V_20 V_21 ;
unsigned long V_22 , V_23 ;
int V_24 , V_25 ;
V_18 = & V_26 ;
V_19 = & V_27 - & V_26 ;
F_7 ( L_1 ,
V_18 , V_19 ) ;
V_25 = F_8 ( & V_28 ) ;
if ( V_25 ) {
F_9 ( L_2 ,
V_25 ) ;
return;
}
V_25 = F_10 ( V_29 , F_1 ,
V_30 , L_3 , 0 ) ;
if ( V_25 < 0 ) {
F_9 ( L_4 , V_25 ) ;
F_11 ( & V_28 ) ;
return;
}
V_23 = V_31 + V_29 * 0x4 ;
V_22 = F_12 ( V_32 + V_23 ) & ~ ( 1 << 1 ) ;
F_13 ( V_22 , V_32 + V_23 ) ;
F_14 ( V_18 , V_19 ) ;
V_12 [ V_33 ] = 0 ;
V_12 [ V_34 ] = 0 ;
V_12 [ V_35 ] = 0 ;
V_12 [ V_36 ] = 0 ;
V_12 [ V_37 ] = 0 ;
V_12 [ V_38 ] = 0 ;
V_12 [ V_39 ] = 0 ;
V_12 [ V_40 ] = 0 ;
V_12 [ V_41 ] = 256 ;
V_12 [ V_42 ] = 0 ;
V_12 [ V_43 ] =
( unsigned int ) & V_12 [ V_44 ] ;
for ( V_24 = V_13 ; V_24 <= V_45 ; V_24 ++ )
V_12 [ V_24 ] = 0 ;
V_21 . V_46 = ( unsigned int ) V_12 ;
F_15 ( & V_21 ) ;
F_7 ( L_5 , V_12 ) ;
V_23 = V_31 + V_47 * 0x4 ;
V_22 = F_12 ( V_48 + V_23 ) | 1 ;
F_13 ( V_22 , V_48 + V_23 ) ;
}
