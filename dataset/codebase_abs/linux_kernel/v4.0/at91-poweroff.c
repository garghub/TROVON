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
static int F_6 ( struct V_10 * V_11 )
{
const char * V_12 ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_7 ( V_11 , L_5 , & V_12 ) ;
if ( V_14 < 0 )
return V_15 ;
for ( V_13 = 0 ; V_13 < F_8 ( V_16 ) ; V_13 ++ )
if ( ! strcasecmp ( V_12 , V_16 [ V_13 ] ) )
return V_13 ;
return - V_17 ;
}
static void F_9 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = V_19 -> V_20 . V_21 ;
int V_22 ;
T_2 V_23 = 0 , V_24 ;
V_22 = F_6 ( V_11 ) ;
if ( V_22 < 0 ) {
F_10 ( & V_19 -> V_20 , L_6 ) ;
return;
}
if ( ! F_11 ( V_11 , L_7 , & V_24 ) ) {
if ( V_24 > V_25 ) {
F_10 ( & V_19 -> V_20 ,
L_8 ,
V_24 , V_25 , V_25 ) ;
V_24 = V_25 ;
}
V_23 |= F_12 ( V_24 ) ;
}
if ( F_13 ( V_11 , L_9 ) )
V_23 |= V_26 ;
if ( F_13 ( V_11 , L_10 ) )
V_23 |= V_27 ;
F_5 ( V_22 | V_23 , V_2 + V_28 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_29 * V_30 ;
V_30 = F_15 ( V_19 , V_31 , 0 ) ;
V_2 = F_16 ( & V_19 -> V_20 , V_30 ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( & V_19 -> V_20 , L_11 ) ;
return F_19 ( V_2 ) ;
}
F_1 () ;
if ( V_19 -> V_20 . V_21 )
F_9 ( V_19 ) ;
V_32 = F_4 ;
return 0 ;
}
