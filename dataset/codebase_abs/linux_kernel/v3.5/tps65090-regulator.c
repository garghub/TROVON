static inline struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = & V_5 [ V_4 ] ;
if ( V_3 -> V_6 . V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
static int T_1 F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 -> V_11 . V_12 ) ;
struct V_1 * V_3 = NULL ;
struct V_13 V_14 = { } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_2 = V_8 -> V_2 ;
F_5 ( & V_8 -> V_11 , L_1 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 == NULL ) {
F_6 ( & V_8 -> V_11 , L_2 ) ;
return - V_19 ;
}
V_18 = V_8 -> V_11 . V_20 ;
V_3 -> V_11 = & V_8 -> V_11 ;
V_14 . V_11 = & V_8 -> V_11 ;
V_14 . V_21 = & V_18 -> V_22 ;
V_14 . V_23 = V_3 ;
V_14 . V_24 = V_10 -> V_25 ;
V_16 = F_7 ( & V_3 -> V_6 , & V_14 ) ;
if ( F_8 ( V_16 ) ) {
F_6 ( & V_8 -> V_11 , L_3 ,
V_3 -> V_6 . V_26 ) ;
return F_9 ( V_16 ) ;
}
F_10 ( V_8 , V_16 ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_12 ( V_8 ) ;
F_13 ( V_16 ) ;
return 0 ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_27 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_27 ) ;
}
