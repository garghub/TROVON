static unsigned long F_1 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned long V_3 = 0 , V_4 = 1 , V_5 = 1 ;
unsigned long V_6 = V_7 , V_8 ;
T_1 V_9 ;
if ( F_2 ( ! V_1 -> V_10 ) )
return V_1 -> V_11 ;
if ( ! V_12 ) {
void T_2 * V_9 ;
V_9 = F_3 ( V_13 , V_14 ) ;
if ( F_4 ( ! V_9 , L_1 ) )
return V_1 -> V_15 ? V_1 -> V_15 -> V_11 : 0 ;
for ( V_2 = 0 ; V_2 < V_16 ; V_2 ++ )
V_17 [ V_2 ] = V_9 + V_18 [ V_2 ] ;
V_12 = V_9 ;
}
V_2 = V_1 -> V_10 -> V_19 ;
V_9 = F_5 ( & V_12 -> V_20 ) ;
if ( ! ( V_9 & V_21 [ V_2 ] ) ) {
V_3 = F_5 ( & V_17 [ V_2 ] -> V_22 ) ;
V_4 = F_5 ( & V_17 [ V_2 ] -> V_23 ) + 1 ;
V_5 = F_5 ( & V_17 [ V_2 ] -> V_24 ) + 1 ;
}
V_9 = F_5 ( V_1 -> V_10 -> V_25 + V_26 ) ;
if ( V_9 & V_27 )
V_6 = V_28 [ V_2 ] ;
V_1 -> V_10 -> V_29 = V_6 ;
V_9 = F_5 ( V_1 -> V_10 -> V_25 + V_26 ) ;
if ( ! ( V_9 & V_30 ) )
return V_6 ;
V_8 = V_6 ;
if ( V_3 )
V_8 += ( ( unsigned long long ) V_6 * V_3 ) / 256 ;
V_8 /= ( V_4 * V_5 ) ;
return V_8 ;
}
static void F_6 ( struct V_31 * V_32 )
{
struct V_33 T_2 * V_34 ;
V_34 = F_3 ( V_32 -> V_35 [ 0 ] . V_36 , V_14 ) ;
F_7 ( 0x7777 , & V_34 -> V_37 ) ;
F_7 ( 0xcccc , & V_34 -> V_37 ) ;
F_7 ( 0xdddd , & V_34 -> V_37 ) ;
F_7 ( 0 , & V_34 -> V_38 ) ;
F_7 ( 0x5a5a , & V_34 -> V_39 ) ;
F_7 ( 0xa5a5 , & V_34 -> V_39 ) ;
F_7 ( 0 , & V_34 -> V_40 ) ;
F_7 ( 0x6666 , & V_34 -> V_41 ) ;
F_7 ( 0xbbbb , & V_34 -> V_41 ) ;
F_7 ( 1 , & V_34 -> V_42 ) ;
F_7 ( 0x7777 , & V_34 -> V_37 ) ;
F_7 ( 0xcccc , & V_34 -> V_37 ) ;
F_7 ( 0xdddd , & V_34 -> V_37 ) ;
F_7 ( 1 , & V_34 -> V_38 ) ;
F_7 ( 0x5555 , & V_34 -> V_43 ) ;
F_7 ( 0xaaaa , & V_34 -> V_43 ) ;
F_7 ( 1 , & V_34 -> V_44 ) ;
}
void F_8 ( char V_45 , const char * V_46 )
{
F_6 ( & V_47 ) ;
}
void T_3 F_9 ( void )
{
F_10 ( & V_48 ) ;
}
