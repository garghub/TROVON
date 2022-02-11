T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 = F_2 ( V_2 , V_7 , V_3 ) ;
V_5 = & V_2 -> V_8 -> V_9 ;
if ( ! F_3 ( V_5 -> V_10 ) ) {
if ( V_5 -> V_11 )
V_6 |= V_12 ;
else
V_6 &= ~ V_12 ;
V_5 -> V_11 = false ;
if ( V_5 -> V_13 )
V_6 |= V_14 ;
else
V_6 &= ~ V_14 ;
}
V_5 = & V_2 -> V_8 -> V_15 ;
if ( ! F_3 ( V_5 -> V_10 ) ) {
if ( V_5 -> V_11 )
V_6 |= V_16 ;
else
V_6 &= ~ V_16 ;
V_5 -> V_11 = false ;
if ( V_5 -> V_13 )
V_6 |= V_17 ;
else
V_6 &= ~ V_17 ;
}
return V_6 ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_18 )
{
F_5 ( V_2 , V_7 , V_3 | V_19 , V_18 ) ;
}
enum V_20 F_6 ( struct V_1 * V_2 )
{
enum V_20 V_21 = F_1 ( V_2 , V_17 )
? V_22
: V_23 ;
return V_21 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
if ( F_1 ( V_2 , V_14 ) )
F_8 ( & V_2 -> V_25 ) ;
else
F_9 ( & V_2 -> V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
enum V_20 V_21 = F_6 ( V_2 ) ;
if ( V_21 != V_2 -> V_21 ) {
F_11 ( V_2 -> V_26 , L_1 ,
V_20 ( V_2 ) -> V_27 , V_2 -> V_28 [ V_21 ] -> V_27 ) ;
F_12 ( V_2 ) ;
if ( V_21 == V_22 )
F_13 ( V_2 , V_7 , V_14 , 0 ,
V_29 ) ;
F_14 ( V_2 , V_21 ) ;
}
}
static void F_15 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_16 ( V_31 , struct V_1 , V_31 ) ;
if ( F_17 ( V_2 ) && ! F_18 ( V_2 ) ) {
F_19 ( V_2 -> V_32 ) ;
return;
}
F_20 ( V_2 -> V_26 ) ;
if ( V_2 -> V_33 ) {
V_2 -> V_33 = false ;
F_10 ( V_2 ) ;
} else if ( V_2 -> V_34 ) {
V_2 -> V_34 = false ;
F_7 ( V_2 ) ;
} else
F_21 ( V_2 -> V_26 , L_2 , V_35 ) ;
F_22 ( V_2 -> V_26 ) ;
F_19 ( V_2 -> V_32 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_31 , F_15 ) ;
V_2 -> V_36 = F_25 ( L_3 ) ;
if ( ! V_2 -> V_36 ) {
F_21 ( V_2 -> V_26 , L_4 ) ;
return - V_37 ;
}
if ( F_17 ( V_2 ) )
return F_26 ( V_2 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 ) {
F_28 ( V_2 -> V_36 ) ;
F_29 ( V_2 -> V_36 ) ;
}
F_4 ( V_2 , V_38 | V_19 ,
V_19 ) ;
if ( F_17 ( V_2 ) )
F_30 ( V_2 ) ;
}
