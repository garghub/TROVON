static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( V_2 -> V_6 || V_2 -> V_7 -> V_8 )
return;
V_4 = F_2 ( V_2 -> V_7 ) ;
if ( ! V_4 )
return;
if ( ! F_3 ( V_9 , V_4 -> V_10 ) )
return;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_2 -> V_12 [ V_5 ] . V_13 = 0 ;
V_2 -> V_12 [ V_5 ] . V_14 = 0 ;
V_2 -> V_12 [ V_5 ] . V_15 = 0 ;
}
F_4 ( & V_2 -> V_2 , L_1 ,
F_5 ( V_2 ) ) ;
}
static int
F_6 ( struct V_3 * V_4 , T_1 V_7 , T_2 V_6 )
{
return ( V_7 != 0 ) ;
}
void T_3 F_7 ( void )
{
struct V_3 * V_4 ;
struct V_12 V_16 ;
void T_4 * V_17 ;
struct V_18 * V_19 ;
V_19 = F_8 ( NULL , V_9 ) ;
if( ! V_19 )
return;
if ( F_9 ( V_19 , 0 , & V_16 ) ) {
F_10 ( L_2 ) ;
return;
}
V_4 = F_11 ( V_19 ) ;
if ( ! V_4 ) {
F_10 ( L_3 ) ;
return;
}
F_12 ( V_4 , V_16 . V_13 + V_20 ,
V_16 . V_13 + V_21 ,
V_22 ) ;
F_13 ( V_4 , 0 , 0 , V_23 , V_24 ) ;
F_14 ( V_4 , 0 , 0 , V_25 , 0xff ) ;
V_17 = F_15 ( V_19 , 0 ) ;
F_16 ( V_17 + V_26 , 0xff ) ;
F_17 ( V_17 ) ;
if ( ! V_27 . V_28 )
V_27 . V_28 = F_6 ;
F_18 ( V_4 , V_19 , 1 ) ;
F_19 ( L_4 ) ;
}
