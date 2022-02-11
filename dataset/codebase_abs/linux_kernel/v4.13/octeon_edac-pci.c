static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
V_4 . V_5 = F_2 ( V_6 ) ;
if ( V_4 . V_7 . V_8 ) {
F_3 ( V_2 , V_2 -> V_9 ) ;
V_4 . V_7 . V_8 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
if ( V_4 . V_7 . V_10 ) {
F_5 ( V_2 , L_1 ) ;
V_4 . V_7 . V_10 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
if ( V_4 . V_7 . V_11 ) {
F_5 ( V_2 , L_2 ) ;
V_4 . V_7 . V_11 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
if ( V_4 . V_7 . V_12 ) {
F_5 ( V_2 , L_3 ) ;
V_4 . V_7 . V_12 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
if ( V_4 . V_7 . V_13 ) {
F_5 ( V_2 , L_4 ) ;
V_4 . V_7 . V_13 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
if ( V_4 . V_7 . V_14 ) {
F_5 ( V_2 , L_5 ) ;
V_4 . V_7 . V_14 = 1 ;
F_4 ( V_6 , V_4 . V_5 ) ;
}
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_7 ( 0 , L_6 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_19 = & V_16 -> V_19 ;
F_8 ( V_16 , V_2 ) ;
V_2 -> V_20 = V_20 ( & V_16 -> V_19 ) ;
V_2 -> V_21 = L_7 ;
V_2 -> V_9 = L_6 ;
V_2 -> V_22 = F_1 ;
if ( F_9 ( V_2 , 0 ) > 0 ) {
F_10 ( L_8 , V_23 ) ;
goto V_24;
}
return 0 ;
V_24:
F_11 ( V_2 ) ;
return V_17 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_13 ( V_16 ) ;
F_14 ( & V_16 -> V_19 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
