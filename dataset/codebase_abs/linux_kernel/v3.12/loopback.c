static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
V_2 -> V_8 = F_4 ( V_2 , V_4 ) ;
V_6 = F_5 ( V_4 -> V_9 ) ;
V_7 = V_2 -> V_7 ;
if ( F_6 ( F_7 ( V_2 ) == V_10 ) ) {
F_8 ( & V_6 -> V_11 ) ;
V_6 -> V_12 += V_7 ;
V_6 -> V_13 ++ ;
F_9 ( & V_6 -> V_11 ) ;
}
return V_14 ;
}
static struct V_15 * F_10 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
T_2 V_12 = 0 ;
T_2 V_13 = 0 ;
int V_17 ;
F_11 (i) {
const struct V_5 * V_6 ;
T_2 V_18 , V_19 ;
unsigned int V_20 ;
V_6 = F_12 ( V_4 -> V_9 , V_17 ) ;
do {
V_20 = F_13 ( & V_6 -> V_11 ) ;
V_18 = V_6 -> V_12 ;
V_19 = V_6 -> V_13 ;
} while ( F_14 ( & V_6 -> V_11 , V_20 ) );
V_12 += V_18 ;
V_13 += V_19 ;
}
V_16 -> V_21 = V_13 ;
V_16 -> V_22 = V_13 ;
V_16 -> V_23 = V_12 ;
V_16 -> V_24 = V_12 ;
return V_16 ;
}
static T_3 F_15 ( struct V_3 * V_4 )
{
return 1 ;
}
static int F_16 ( struct V_3 * V_4 )
{
V_4 -> V_9 = F_17 ( struct V_5 ) ;
if ( ! V_4 -> V_9 )
return - V_25 ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
F_19 ( V_4 ) -> V_26 = NULL ;
F_20 ( V_4 -> V_9 ) ;
F_21 ( V_4 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
V_4 -> V_27 = 64 * 1024 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_32 = 0 ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 &= ~ V_37 ;
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_41 = V_42 | V_43
| V_39
| V_40
| V_44
| V_45
| V_46
| V_47
| V_48
| V_49
| V_50 ;
V_4 -> V_51 = & V_52 ;
V_4 -> V_53 = & V_54 ;
V_4 -> V_55 = & V_56 ;
V_4 -> V_57 = F_18 ;
}
static T_4 int F_23 ( struct V_58 * V_58 )
{
struct V_3 * V_4 ;
int V_59 ;
V_59 = - V_25 ;
V_4 = F_24 ( 0 , L_1 , F_22 ) ;
if ( ! V_4 )
goto V_60;
F_25 ( V_4 , V_58 ) ;
V_59 = F_26 ( V_4 ) ;
if ( V_59 )
goto V_61;
F_27 ( V_4 -> V_62 != V_63 ) ;
V_58 -> V_26 = V_4 ;
return 0 ;
V_61:
F_21 ( V_4 ) ;
V_60:
if ( F_28 ( V_58 , & V_64 ) )
F_29 ( L_2 , V_59 ) ;
return V_59 ;
}
