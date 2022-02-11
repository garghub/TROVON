static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_4 = NULL ;
int V_5 , V_6 , V_7 ;
V_3 = F_2 ( V_8 ) ;
if ( V_3 )
V_4 = V_3 -> V_9 . V_10 ;
for ( V_5 = V_11 ;
V_5 <= V_12 ; V_5 ++ ) {
V_6 = F_3 ( V_5 ) ;
V_7 = V_13 [ V_14 + V_5 ] ;
while ( V_15 [ V_5 ] < V_7 ) {
if ( V_5 != V_11 ) {
struct V_9 * V_16 = F_4 ( V_6 ) ;
if ( V_4 && V_4 -> V_17 )
V_4 -> V_17 ( V_16 ) ;
}
F_5 ( V_6 ) ;
V_15 [ V_5 ] ++ ;
}
}
return V_18 ;
}
void T_2 F_6 ( void )
{
void * V_19 ;
unsigned int V_20 ;
struct V_21 V_22 ;
unsigned long V_23 , V_24 ;
int V_25 , V_26 ;
V_19 = & V_27 ;
V_20 = & V_28 - & V_27 ;
F_7 ( L_1 ,
V_19 , V_20 ) ;
V_26 = F_8 ( & V_29 ) ;
if ( V_26 ) {
F_9 ( L_2 ,
V_26 ) ;
return;
}
V_26 = F_10 ( V_30 , F_1 ,
V_31 , L_3 , 0 ) ;
if ( V_26 < 0 ) {
F_9 ( L_4 , V_26 ) ;
F_11 ( & V_29 ) ;
return;
}
V_24 = V_32 + V_30 * 0x4 ;
V_23 = F_12 ( V_33 + V_24 ) & ~ ( 1 << 1 ) ;
F_13 ( V_23 , V_33 + V_24 ) ;
F_14 ( V_19 , V_20 ) ;
V_13 [ V_34 ] = 0 ;
V_13 [ V_35 ] = 0 ;
V_13 [ V_36 ] = 0 ;
V_13 [ V_37 ] = 0 ;
V_13 [ V_38 ] = 0 ;
V_13 [ V_39 ] = 0 ;
V_13 [ V_40 ] = 0 ;
V_13 [ V_41 ] = 0 ;
V_13 [ V_42 ] = 256 ;
V_13 [ V_43 ] = 0 ;
V_13 [ V_44 ] =
( unsigned int ) & V_13 [ V_45 ] ;
for ( V_25 = V_14 ; V_25 <= V_46 ; V_25 ++ )
V_13 [ V_25 ] = 0 ;
V_22 . V_47 = ( unsigned int ) V_13 ;
F_15 ( & V_22 ) ;
F_7 ( L_5 , V_13 ) ;
V_24 = V_32 + V_48 * 0x4 ;
V_23 = F_12 ( V_49 + V_24 ) | 1 ;
F_13 ( V_23 , V_49 + V_24 ) ;
}
