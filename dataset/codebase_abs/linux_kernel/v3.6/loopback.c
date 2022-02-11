static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( V_2 ) ;
V_2 -> V_8 = F_3 ( V_2 , V_4 ) ;
V_6 = F_4 ( V_4 -> V_9 ) ;
V_7 = V_2 -> V_7 ;
if ( F_5 ( F_6 ( V_2 ) == V_10 ) ) {
F_7 ( & V_6 -> V_11 ) ;
V_6 -> V_12 += V_7 ;
V_6 -> V_13 ++ ;
F_8 ( & V_6 -> V_11 ) ;
}
return V_14 ;
}
static struct V_15 * F_9 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
T_2 V_12 = 0 ;
T_2 V_13 = 0 ;
int V_17 ;
F_10 (i) {
const struct V_5 * V_6 ;
T_2 V_18 , V_19 ;
unsigned int V_20 ;
V_6 = F_11 ( V_4 -> V_9 , V_17 ) ;
do {
V_20 = F_12 ( & V_6 -> V_11 ) ;
V_18 = V_6 -> V_12 ;
V_19 = V_6 -> V_13 ;
} while ( F_13 ( & V_6 -> V_11 , V_20 ) );
V_12 += V_18 ;
V_13 += V_19 ;
}
V_16 -> V_21 = V_13 ;
V_16 -> V_22 = V_13 ;
V_16 -> V_23 = V_12 ;
V_16 -> V_24 = V_12 ;
return V_16 ;
}
static T_3 F_14 ( struct V_3 * V_4 )
{
return 1 ;
}
static int F_15 ( struct V_3 * V_4 )
{
V_4 -> V_9 = F_16 ( struct V_5 ) ;
if ( ! V_4 -> V_9 )
return - V_25 ;
return 0 ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_18 ( V_4 -> V_9 ) ;
F_19 ( V_4 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
V_4 -> V_26 = ( 16 * 1024 ) + 20 + 20 + 12 ;
V_4 -> V_27 = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_31 = 0 ;
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 &= ~ V_36 ;
V_4 -> V_37 = V_38 | V_39 ;
V_4 -> V_40 = V_41 | V_42
| V_38
| V_39
| V_43
| V_44
| V_45
| V_46
| V_47
| V_48
| V_49 ;
V_4 -> V_50 = & V_51 ;
V_4 -> V_52 = & V_53 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_17 ;
}
static T_4 int F_21 ( struct V_57 * V_57 )
{
struct V_3 * V_4 ;
int V_58 ;
V_58 = - V_25 ;
V_4 = F_22 ( 0 , L_1 , F_20 ) ;
if ( ! V_4 )
goto V_59;
F_23 ( V_4 , V_57 ) ;
V_58 = F_24 ( V_4 ) ;
if ( V_58 )
goto V_60;
V_57 -> V_61 = V_4 ;
return 0 ;
V_60:
F_19 ( V_4 ) ;
V_59:
if ( F_25 ( V_57 , & V_62 ) )
F_26 ( L_2 , V_58 ) ;
return V_58 ;
}
