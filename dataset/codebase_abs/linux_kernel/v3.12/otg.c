enum V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 , V_5 , ~ 0 ) ;
enum V_1 V_6 = V_4 & V_7
? V_8
: V_9 ;
return V_6 ;
}
void F_3 ( struct V_2 * V_3 )
{
T_1 V_10 ;
if ( ! V_3 -> V_11 )
return;
V_10 = F_2 ( V_3 , V_5 , ~ 0 ) ;
if ( V_10 & V_12 )
F_4 ( & V_3 -> V_13 ) ;
else
F_5 ( & V_3 -> V_13 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
enum V_1 V_6 = F_1 ( V_3 ) ;
if ( V_6 != V_3 -> V_6 ) {
F_7 ( V_3 -> V_14 , L_1 ,
V_1 ( V_3 ) -> V_15 , V_3 -> V_16 [ V_6 ] -> V_15 ) ;
F_8 ( V_3 ) ;
F_9 ( V_3 , V_5 , V_12 , 0 ,
V_17 ) ;
F_10 ( V_3 , V_6 ) ;
}
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_12 ( V_19 , struct V_2 , V_19 ) ;
if ( V_3 -> V_20 ) {
V_3 -> V_20 = false ;
F_6 ( V_3 ) ;
} else if ( V_3 -> V_21 ) {
V_3 -> V_21 = false ;
F_3 ( V_3 ) ;
} else
F_13 ( V_3 -> V_14 , L_2 , V_22 ) ;
F_14 ( V_3 -> V_23 ) ;
}
int F_15 ( struct V_2 * V_3 )
{
F_16 ( & V_3 -> V_19 , F_11 ) ;
V_3 -> V_24 = F_17 ( L_3 ) ;
if ( ! V_3 -> V_24 ) {
F_13 ( V_3 -> V_14 , L_4 ) ;
return - V_25 ;
}
return 0 ;
}
void F_18 ( struct V_2 * V_3 )
{
if ( V_3 -> V_24 ) {
F_19 ( V_3 -> V_24 ) ;
F_20 ( V_3 -> V_24 ) ;
}
F_21 ( V_3 , V_26 ) ;
F_22 ( V_3 , V_27 ) ;
}
