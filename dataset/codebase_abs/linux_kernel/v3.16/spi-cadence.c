static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 ,
V_7 ) ;
F_3 ( V_2 , V_8 ,
V_9 ) ;
while ( F_1 ( V_2 , V_10 ) &
V_11 )
F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_10 ,
V_9 ) ;
F_3 ( V_2 , V_13 ,
V_14 ) ;
F_3 ( V_2 , V_6 ,
V_15 ) ;
}
static void F_6 ( struct V_16 * V_17 , bool V_18 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
T_1 V_20 ;
V_20 = F_1 ( V_2 , V_13 ) ;
if ( V_18 ) {
V_20 |= V_21 ;
} else {
V_20 &= ~ V_21 ;
if ( ! ( V_2 -> V_22 ) )
V_20 |= ( ( ~ ( V_23 << V_17 -> V_24 ) ) <<
V_25 ) &
V_21 ;
else
V_20 |= ( V_17 -> V_24 << V_25 ) &
V_21 ;
}
F_3 ( V_2 , V_13 , V_20 ) ;
}
static void F_8 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
T_1 V_20 ;
V_20 = F_1 ( V_2 , V_13 ) ;
V_20 &= ~ ( V_26 | V_27 ) ;
if ( V_17 -> V_28 & V_29 )
V_20 |= V_26 ;
if ( V_17 -> V_28 & V_30 )
V_20 |= V_27 ;
F_3 ( V_2 , V_13 , V_20 ) ;
}
static void F_9 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
T_1 V_20 , V_33 ;
unsigned long V_34 ;
V_34 = F_10 ( V_2 -> V_35 ) ;
V_20 = F_1 ( V_2 , V_13 ) ;
if ( V_2 -> V_36 != V_32 -> V_36 ) {
V_33 = V_37 ;
while ( ( V_33 < V_38 ) &&
( V_34 / ( 2 << V_33 ) ) > V_32 -> V_36 )
V_33 ++ ;
V_20 &= ~ V_39 ;
V_20 |= V_33 << V_40 ;
V_2 -> V_36 = V_34 / ( 2 << V_33 ) ;
}
F_3 ( V_2 , V_13 , V_20 ) ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
F_9 ( V_17 , V_32 ) ;
F_12 ( & V_17 -> V_41 , L_1 ,
V_42 , V_17 -> V_28 , V_17 -> V_43 ,
V_2 -> V_36 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_44 = 0 ;
while ( ( V_44 < V_45 ) &&
( V_2 -> V_46 > 0 ) ) {
if ( V_2 -> V_47 )
F_3 ( V_2 , V_48 ,
* V_2 -> V_47 ++ ) ;
else
F_3 ( V_2 , V_48 , 0 ) ;
V_2 -> V_46 -- ;
V_44 ++ ;
}
}
static T_2 F_14 ( int V_49 , void * V_50 )
{
struct V_51 * V_19 = V_50 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
T_1 V_52 , V_53 ;
V_53 = V_54 ;
V_52 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_52 ) ;
if ( V_52 & V_55 ) {
F_3 ( V_2 , V_8 ,
V_56 ) ;
F_15 ( V_19 ) ;
V_53 = V_57 ;
} else if ( V_52 & V_58 ) {
unsigned long V_44 ;
V_44 = V_2 -> V_59 - V_2 -> V_46 ;
while ( V_44 ) {
T_3 V_60 ;
V_60 = F_1 ( V_2 , V_12 ) ;
if ( V_2 -> V_61 )
* V_2 -> V_61 ++ = V_60 ;
V_2 -> V_59 -- ;
V_44 -- ;
}
if ( V_2 -> V_46 ) {
F_13 ( V_2 ) ;
} else {
F_3 ( V_2 , V_8 ,
V_56 ) ;
F_15 ( V_19 ) ;
}
V_53 = V_57 ;
}
return V_53 ;
}
static int F_16 ( struct V_51 * V_19 ,
struct V_16 * V_17 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
V_2 -> V_47 = V_32 -> V_62 ;
V_2 -> V_61 = V_32 -> V_63 ;
V_2 -> V_46 = V_32 -> V_64 ;
V_2 -> V_59 = V_32 -> V_64 ;
F_11 ( V_17 , V_32 ) ;
F_13 ( V_2 ) ;
F_3 ( V_2 , V_65 ,
V_56 ) ;
return V_32 -> V_64 ;
}
static int F_17 ( struct V_51 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_8 ( V_19 -> V_66 -> V_17 ) ;
F_3 ( V_2 , V_6 ,
V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_51 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_3 ( V_2 , V_6 ,
V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_67 * V_68 )
{
int V_69 = 0 , V_49 ;
struct V_51 * V_19 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
T_1 V_72 ;
V_19 = F_20 ( & V_68 -> V_41 , sizeof( * V_2 ) ) ;
if ( V_19 == NULL )
return - V_73 ;
V_2 = F_7 ( V_19 ) ;
V_19 -> V_41 . V_74 = V_68 -> V_41 . V_74 ;
F_21 ( V_68 , V_19 ) ;
V_71 = F_22 ( V_68 , V_75 , 0 ) ;
V_2 -> V_4 = F_23 ( & V_68 -> V_41 , V_71 ) ;
if ( F_24 ( V_2 -> V_4 ) ) {
V_69 = F_25 ( V_2 -> V_4 ) ;
goto V_76;
}
V_2 -> V_77 = F_26 ( & V_68 -> V_41 , L_2 ) ;
if ( F_24 ( V_2 -> V_77 ) ) {
F_27 ( & V_68 -> V_41 , L_3 ) ;
V_69 = F_25 ( V_2 -> V_77 ) ;
goto V_76;
}
V_2 -> V_35 = F_26 ( & V_68 -> V_41 , L_4 ) ;
if ( F_24 ( V_2 -> V_35 ) ) {
F_27 ( & V_68 -> V_41 , L_5 ) ;
V_69 = F_25 ( V_2 -> V_35 ) ;
goto V_76;
}
V_69 = F_28 ( V_2 -> V_77 ) ;
if ( V_69 ) {
F_27 ( & V_68 -> V_41 , L_6 ) ;
goto V_76;
}
V_69 = F_28 ( V_2 -> V_35 ) ;
if ( V_69 ) {
F_27 ( & V_68 -> V_41 , L_7 ) ;
goto V_78;
}
F_5 ( V_2 ) ;
V_49 = F_29 ( V_68 , 0 ) ;
if ( V_49 <= 0 ) {
V_69 = - V_79 ;
F_27 ( & V_68 -> V_41 , L_8 ) ;
goto V_76;
}
V_69 = F_30 ( & V_68 -> V_41 , V_49 , F_14 ,
0 , V_68 -> V_80 , V_19 ) ;
if ( V_69 != 0 ) {
V_69 = - V_79 ;
F_27 ( & V_68 -> V_41 , L_9 ) ;
goto V_76;
}
V_69 = F_31 ( V_68 -> V_41 . V_74 , L_10 , & V_72 ) ;
if ( V_69 < 0 )
V_19 -> V_81 = V_82 ;
else
V_19 -> V_81 = V_72 ;
V_69 = F_31 ( V_68 -> V_41 . V_74 , L_11 ,
& V_2 -> V_22 ) ;
if ( V_69 < 0 )
V_2 -> V_22 = 0 ;
V_19 -> V_83 = F_17 ;
V_19 -> V_84 = F_16 ;
V_19 -> V_85 = F_18 ;
V_19 -> V_86 = F_6 ;
V_19 -> V_87 = V_30 | V_29 ;
V_19 -> V_88 = F_10 ( V_2 -> V_35 ) / 4 ;
V_2 -> V_36 = V_19 -> V_88 ;
V_19 -> V_89 = F_32 ( 8 ) ;
V_69 = F_33 ( V_19 ) ;
if ( V_69 ) {
F_27 ( & V_68 -> V_41 , L_12 ) ;
goto V_90;
}
return V_69 ;
V_90:
F_34 ( V_2 -> V_35 ) ;
V_78:
F_34 ( V_2 -> V_77 ) ;
V_76:
F_35 ( V_19 ) ;
return V_69 ;
}
static int F_36 ( struct V_67 * V_68 )
{
struct V_51 * V_19 = F_37 ( V_68 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_3 ( V_2 , V_6 ,
V_7 ) ;
F_34 ( V_2 -> V_35 ) ;
F_34 ( V_2 -> V_77 ) ;
F_38 ( V_19 ) ;
return 0 ;
}
static int T_4 F_39 ( struct V_91 * V_41 )
{
struct V_67 * V_68 = F_40 ( V_41 ,
struct V_67 , V_41 ) ;
struct V_51 * V_19 = F_37 ( V_68 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_41 ( V_19 ) ;
F_34 ( V_2 -> V_35 ) ;
F_34 ( V_2 -> V_77 ) ;
return 0 ;
}
static int T_4 F_42 ( struct V_91 * V_41 )
{
struct V_67 * V_68 = F_40 ( V_41 ,
struct V_67 , V_41 ) ;
struct V_51 * V_19 = F_37 ( V_68 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_69 = 0 ;
V_69 = F_28 ( V_2 -> V_77 ) ;
if ( V_69 ) {
F_27 ( V_41 , L_13 ) ;
return V_69 ;
}
V_69 = F_28 ( V_2 -> V_35 ) ;
if ( V_69 ) {
F_27 ( V_41 , L_14 ) ;
F_43 ( V_2 -> V_77 ) ;
return V_69 ;
}
F_44 ( V_19 ) ;
return 0 ;
}
