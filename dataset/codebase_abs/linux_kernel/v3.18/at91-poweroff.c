static void T_1 F_1 ( void )
{
T_2 V_1 = F_2 ( V_2 + V_3 ) ;
char * V_4 = L_1 ;
if ( ! V_1 )
return;
if ( V_1 & V_5 )
V_4 = L_2 ;
else if ( V_1 & V_6 )
V_4 = L_3 ;
F_3 ( L_4 , V_4 ) ;
}
static void F_4 ( void )
{
F_5 ( V_7 | V_8 , V_2 + V_9 ) ;
}
const enum V_10 F_6 ( struct V_11 * V_12 )
{
const char * V_13 ;
int V_14 , V_15 ;
V_14 = F_7 ( V_12 , L_5 , & V_13 ) ;
if ( V_14 < 0 )
return V_16 ;
for ( V_15 = 0 ; V_15 < F_8 ( V_17 ) ; V_15 ++ )
if ( ! strcasecmp ( V_13 , V_17 [ V_15 ] ) )
return V_15 ;
return - V_18 ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = V_20 -> V_21 . V_22 ;
enum V_10 V_23 ;
T_2 V_24 = 0 , V_25 ;
V_23 = F_6 ( V_12 ) ;
if ( V_23 < 0 ) {
F_10 ( & V_20 -> V_21 , L_6 ) ;
return;
}
if ( ! F_11 ( V_12 , L_7 , & V_25 ) ) {
if ( V_25 > V_26 ) {
F_10 ( & V_20 -> V_21 ,
L_8 ,
V_25 , V_26 , V_26 ) ;
V_25 = V_26 ;
}
V_24 |= F_12 ( V_25 ) ;
}
if ( F_13 ( V_12 , L_9 ) )
V_24 |= V_27 ;
if ( F_13 ( V_12 , L_10 ) )
V_24 |= V_28 ;
F_5 ( V_23 | V_24 , V_2 + V_29 ) ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_20 , V_32 , 0 ) ;
V_2 = F_16 ( & V_20 -> V_21 , V_31 ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( & V_20 -> V_21 , L_11 ) ;
return F_19 ( V_2 ) ;
}
F_1 () ;
if ( V_20 -> V_21 . V_22 )
F_9 ( V_20 ) ;
V_33 = F_4 ;
return 0 ;
}
