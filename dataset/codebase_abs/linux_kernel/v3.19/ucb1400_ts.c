static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 | V_6 |
V_7 | V_8 |
V_9 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 | V_6 |
V_7 | V_8 |
V_10 | V_11 ) ;
F_4 ( V_12 ) ;
return F_5 ( V_2 -> V_3 , V_13 , V_14 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_15 | V_6 |
V_10 | V_11 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_15 | V_6 |
V_10 | V_11 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_15 | V_6 |
V_16 | V_11 ) ;
F_4 ( V_17 ) ;
return F_5 ( V_2 -> V_3 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_7 | V_18 |
V_10 | V_11 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_7 | V_18 |
V_10 | V_11 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_7 | V_18 |
V_16 | V_11 ) ;
F_4 ( V_17 ) ;
return F_5 ( V_2 -> V_3 , V_19 , V_14 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_15 | V_6 |
V_10 | V_11 ) ;
return F_5 ( V_2 -> V_3 , 0 , V_14 ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_7 | V_18 |
V_10 | V_11 ) ;
return F_5 ( V_2 -> V_3 , 0 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned short V_20 = F_11 ( V_2 -> V_3 , V_4 ) ;
return V_20 & ( V_21 | V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_23 , V_24 ) ;
F_2 ( V_2 -> V_3 , V_23 , 0 ) ;
F_2 ( V_2 -> V_3 , V_25 , V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_25 , 0 ) ;
}
static void F_14 ( struct V_26 * V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
F_15 ( V_27 , V_31 , V_29 ) ;
F_15 ( V_27 , V_32 , V_30 ) ;
F_15 ( V_27 , V_33 , V_28 ) ;
F_16 ( V_27 , V_34 , 1 ) ;
F_17 ( V_27 ) ;
}
static void F_18 ( struct V_26 * V_27 )
{
F_15 ( V_27 , V_33 , 0 ) ;
F_16 ( V_27 , V_34 , 0 ) ;
F_17 ( V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
V_35 = F_11 ( V_2 -> V_3 , V_36 ) ;
F_2 ( V_2 -> V_3 , V_23 , V_35 ) ;
F_2 ( V_2 -> V_3 , V_23 , 0 ) ;
if ( V_35 & V_24 )
F_13 ( V_2 ) ;
else
F_20 ( & V_2 -> V_37 -> V_38 ,
L_1 , V_35 ) ;
}
static T_2 F_21 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
unsigned int V_29 , V_30 , V_41 ;
bool V_42 ;
if ( F_22 ( V_39 != V_2 -> V_43 ) )
return V_44 ;
F_19 ( V_2 ) ;
F_23 ( V_45 ) ;
while ( ! V_2 -> V_46 && ! ( V_42 = F_10 ( V_2 ) ) ) {
F_24 ( V_2 -> V_3 ) ;
V_29 = F_6 ( V_2 ) ;
V_30 = F_7 ( V_2 ) ;
V_41 = F_3 ( V_2 ) ;
F_25 ( V_2 -> V_3 ) ;
F_14 ( V_2 -> V_37 , V_41 , V_29 , V_30 ) ;
F_26 ( V_2 -> V_47 , V_2 -> V_46 ,
F_27 ( V_45 ) ) ;
}
F_18 ( V_2 -> V_37 ) ;
if ( ! V_2 -> V_46 ) {
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
}
return V_48 ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_46 = true ;
F_29 () ;
F_30 ( & V_2 -> V_47 ) ;
F_31 ( V_2 -> V_43 ) ;
F_13 ( V_2 ) ;
F_2 ( V_2 -> V_3 , V_4 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_46 = false ;
F_29 () ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
F_33 ( V_2 -> V_43 ) ;
}
static int F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_35 ( V_27 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static void F_36 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_35 ( V_27 ) ;
F_28 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
unsigned long V_51 , V_52 ;
V_51 = F_38 () ;
F_2 ( V_2 -> V_3 , V_53 , V_54 ) ;
F_2 ( V_2 -> V_3 , V_25 , V_54 ) ;
F_2 ( V_2 -> V_3 , V_23 , 0xffff ) ;
F_2 ( V_2 -> V_3 , V_23 , 0 ) ;
F_2 ( V_2 -> V_3 , V_55 , V_56 ) ;
F_2 ( V_2 -> V_3 , V_55 , V_56 | V_57 ) ;
V_52 = V_58 + V_59 / 2 ;
while ( ! ( F_11 ( V_2 -> V_3 , V_60 ) &
V_61 ) ) {
F_39 () ;
if ( F_40 ( V_58 , V_52 ) ) {
F_41 ( & V_50 -> V_38 , L_2 ) ;
F_42 ( V_51 ) ;
return - V_62 ;
}
}
F_2 ( V_2 -> V_3 , V_55 , 0 ) ;
F_2 ( V_2 -> V_3 , V_53 , 0 ) ;
F_2 ( V_2 -> V_3 , V_25 , 0 ) ;
F_2 ( V_2 -> V_3 , V_23 , 0xffff ) ;
F_2 ( V_2 -> V_3 , V_23 , 0 ) ;
V_2 -> V_43 = F_42 ( V_51 ) ;
if ( V_2 -> V_43 < 0 || V_2 -> V_43 == V_63 )
return - V_62 ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_44 ( & V_50 -> V_38 ) ;
int error , V_64 , V_65 ;
T_1 V_66 ;
V_2 -> V_37 = F_45 () ;
if ( ! V_2 -> V_37 ) {
error = - V_67 ;
goto V_68;
}
if ( V_2 -> V_43 < 0 ) {
error = F_37 ( V_2 , V_50 ) ;
if ( error ) {
F_41 ( & V_50 -> V_38 , L_3 ) ;
goto V_69;
}
}
F_20 ( & V_50 -> V_38 , L_4 , V_2 -> V_43 ) ;
F_46 ( & V_2 -> V_47 ) ;
F_47 ( V_2 -> V_37 , V_2 ) ;
V_2 -> V_37 -> V_38 . V_70 = & V_50 -> V_38 ;
V_2 -> V_37 -> V_71 = L_5 ;
V_2 -> V_37 -> V_72 . V_73 = F_11 ( V_2 -> V_3 ,
V_74 ) ;
V_2 -> V_37 -> V_72 . V_75 = V_2 -> V_72 ;
V_2 -> V_37 -> V_76 = F_34 ;
V_2 -> V_37 -> V_77 = F_36 ;
V_2 -> V_37 -> V_78 [ 0 ] = F_48 ( V_79 ) | F_48 ( V_80 ) ;
V_2 -> V_37 -> V_81 [ F_49 ( V_34 ) ] = F_48 ( V_34 ) ;
V_66 = F_11 ( V_2 -> V_3 , V_82 ) ;
F_2 ( V_2 -> V_3 , V_82 , V_66 | V_83 ) ;
F_24 ( V_2 -> V_3 ) ;
V_64 = F_8 ( V_2 ) ;
V_65 = F_9 ( V_2 ) ;
F_25 ( V_2 -> V_3 ) ;
F_20 ( & V_50 -> V_38 , L_6 , V_64 , V_65 ) ;
F_50 ( V_2 -> V_37 , V_31 , 0 , V_64 , 0 , 0 ) ;
F_50 ( V_2 -> V_37 , V_32 , 0 , V_65 , 0 , 0 ) ;
F_50 ( V_2 -> V_37 , V_33 , 0 , 0 , 0 , 0 ) ;
F_28 ( V_2 ) ;
error = F_51 ( V_2 -> V_43 , NULL , F_21 ,
V_84 | V_85 ,
L_7 , V_2 ) ;
if ( error ) {
F_41 ( & V_50 -> V_38 ,
L_8 , V_2 -> V_43 , error ) ;
goto V_69;
}
error = F_52 ( V_2 -> V_37 ) ;
if ( error )
goto V_86;
return 0 ;
V_86:
F_53 ( V_2 -> V_43 , V_2 ) ;
V_69:
F_54 ( V_2 -> V_37 ) ;
V_68:
return error ;
}
static int F_55 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_44 ( & V_50 -> V_38 ) ;
F_53 ( V_2 -> V_43 , V_2 ) ;
F_56 ( V_2 -> V_37 ) ;
return 0 ;
}
static int T_3 F_57 ( struct V_87 * V_38 )
{
struct V_1 * V_2 = F_44 ( V_38 ) ;
struct V_26 * V_27 = V_2 -> V_37 ;
F_58 ( & V_27 -> V_88 ) ;
if ( V_27 -> V_89 )
F_32 ( V_2 ) ;
F_59 ( & V_27 -> V_88 ) ;
return 0 ;
}
static int T_3 F_60 ( struct V_87 * V_38 )
{
struct V_1 * V_2 = F_44 ( V_38 ) ;
struct V_26 * V_27 = V_2 -> V_37 ;
F_58 ( & V_27 -> V_88 ) ;
if ( V_27 -> V_89 )
F_28 ( V_2 ) ;
F_59 ( & V_27 -> V_88 ) ;
return 0 ;
}
