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
static void T_3 F_7 ( struct V_3 * V_4 )
{
T_4 V_7 = 0 ;
T_4 V_16 , V_2 , V_17 , V_18 ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ ) {
for ( V_17 = 0 ; V_17 < 1 ; V_17 ++ ) {
F_8 ( L_2 , V_7 , V_2 , V_17 ) ;
for ( V_18 = 0 ; V_18 < 64 ; V_18 += 4 ) {
F_9 ( V_4 , V_7 ,
F_10 ( V_2 , V_17 ) , V_18 , & V_16 ) ;
if ( V_18 == 0 && V_16 == 0xFFFFFFFF ) {
F_11 ( L_3 ) ;
break;
}
if ( ! ( V_18 % 0x10 ) )
F_11 ( L_4 , V_18 ) ;
F_11 ( L_5 , V_16 ) ;
}
F_8 ( L_6 ) ;
}
}
}
static void T_3 F_7 ( struct V_3 * V_4 )
{
}
void T_3 F_12 ( void )
{
struct V_3 * V_4 ;
struct V_12 V_19 ;
void T_5 * V_20 ;
struct V_21 * V_22 ;
V_22 = F_13 ( NULL , V_9 ) ;
if ( ! V_22 )
return;
if ( F_14 ( V_22 , 0 , & V_19 ) ) {
F_15 ( L_7 ) ;
return;
}
V_4 = F_16 ( V_22 ) ;
if ( ! V_4 ) {
F_15 ( L_8 ) ;
return;
}
F_17 ( V_4 , V_19 . V_13 + V_23 ,
V_19 . V_13 + V_24 ,
V_25 ) ;
F_18 ( V_4 , 0 , 0 , V_26 , V_27 ) ;
F_19 ( V_4 , 0 , 0 , V_28 , 0xff ) ;
V_20 = F_20 ( V_22 , 0 ) ;
F_21 ( V_20 + V_29 , 0x000000ff ) ;
F_22 ( V_20 ) ;
F_23 ( V_4 , V_22 ,
V_25 ) ;
F_8 ( L_9 ) ;
F_7 ( V_4 ) ;
}
