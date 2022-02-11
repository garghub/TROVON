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
T_1 V_20 , V_26 ;
V_26 = V_20 = F_1 ( V_2 , V_13 ) ;
V_26 &= ~ ( V_27 | V_28 ) ;
if ( V_17 -> V_29 & V_30 )
V_26 |= V_27 ;
if ( V_17 -> V_29 & V_31 )
V_26 |= V_28 ;
if ( V_26 != V_20 ) {
F_3 ( V_2 , V_6 ,
V_7 ) ;
F_3 ( V_2 , V_13 , V_26 ) ;
F_3 ( V_2 , V_6 ,
V_15 ) ;
}
}
static void F_9 ( struct V_16 * V_17 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
T_1 V_20 , V_34 ;
unsigned long V_35 ;
V_35 = F_10 ( V_2 -> V_36 ) ;
V_20 = F_1 ( V_2 , V_13 ) ;
if ( V_2 -> V_37 != V_33 -> V_37 ) {
V_34 = V_38 ;
while ( ( V_34 < V_39 ) &&
( V_35 / ( 2 << V_34 ) ) > V_33 -> V_37 )
V_34 ++ ;
V_20 &= ~ V_40 ;
V_20 |= V_34 << V_41 ;
V_2 -> V_37 = V_35 / ( 2 << V_34 ) ;
}
F_3 ( V_2 , V_13 , V_20 ) ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_7 ( V_17 -> V_19 ) ;
F_9 ( V_17 , V_33 ) ;
F_12 ( & V_17 -> V_42 , L_1 ,
V_43 , V_17 -> V_29 , V_17 -> V_44 ,
V_2 -> V_37 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_45 = 0 ;
while ( ( V_45 < V_46 ) &&
( V_2 -> V_47 > 0 ) ) {
if ( V_2 -> V_48 )
F_3 ( V_2 , V_49 ,
* V_2 -> V_48 ++ ) ;
else
F_3 ( V_2 , V_49 , 0 ) ;
V_2 -> V_47 -- ;
V_45 ++ ;
}
}
static T_2 F_14 ( int V_50 , void * V_51 )
{
struct V_52 * V_19 = V_51 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
T_1 V_53 , V_54 ;
V_54 = V_55 ;
V_53 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_53 ) ;
if ( V_53 & V_56 ) {
F_3 ( V_2 , V_8 ,
V_57 ) ;
F_15 ( V_19 ) ;
V_54 = V_58 ;
} else if ( V_53 & V_59 ) {
unsigned long V_45 ;
V_45 = V_2 -> V_60 - V_2 -> V_47 ;
while ( V_45 ) {
T_3 V_61 ;
V_61 = F_1 ( V_2 , V_12 ) ;
if ( V_2 -> V_62 )
* V_2 -> V_62 ++ = V_61 ;
V_2 -> V_60 -- ;
V_45 -- ;
}
if ( V_2 -> V_47 ) {
F_13 ( V_2 ) ;
} else {
F_3 ( V_2 , V_8 ,
V_57 ) ;
F_15 ( V_19 ) ;
}
V_54 = V_58 ;
}
return V_54 ;
}
static int F_16 ( struct V_52 * V_19 ,
struct V_63 * V_64 )
{
F_8 ( V_64 -> V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_52 * V_19 ,
struct V_16 * V_17 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
V_2 -> V_48 = V_33 -> V_65 ;
V_2 -> V_62 = V_33 -> V_66 ;
V_2 -> V_47 = V_33 -> V_67 ;
V_2 -> V_60 = V_33 -> V_67 ;
F_11 ( V_17 , V_33 ) ;
F_13 ( V_2 ) ;
F_3 ( V_2 , V_68 ,
V_57 ) ;
return V_33 -> V_67 ;
}
static int F_18 ( struct V_52 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_3 ( V_2 , V_6 ,
V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_52 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_3 ( V_2 , V_6 ,
V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_69 * V_70 )
{
int V_71 = 0 , V_50 ;
struct V_52 * V_19 ;
struct V_1 * V_2 ;
struct V_72 * V_73 ;
T_1 V_74 ;
V_19 = F_21 ( & V_70 -> V_42 , sizeof( * V_2 ) ) ;
if ( V_19 == NULL )
return - V_75 ;
V_2 = F_7 ( V_19 ) ;
V_19 -> V_42 . V_76 = V_70 -> V_42 . V_76 ;
F_22 ( V_70 , V_19 ) ;
V_73 = F_23 ( V_70 , V_77 , 0 ) ;
V_2 -> V_4 = F_24 ( & V_70 -> V_42 , V_73 ) ;
if ( F_25 ( V_2 -> V_4 ) ) {
V_71 = F_26 ( V_2 -> V_4 ) ;
goto V_78;
}
V_2 -> V_79 = F_27 ( & V_70 -> V_42 , L_2 ) ;
if ( F_25 ( V_2 -> V_79 ) ) {
F_28 ( & V_70 -> V_42 , L_3 ) ;
V_71 = F_26 ( V_2 -> V_79 ) ;
goto V_78;
}
V_2 -> V_36 = F_27 ( & V_70 -> V_42 , L_4 ) ;
if ( F_25 ( V_2 -> V_36 ) ) {
F_28 ( & V_70 -> V_42 , L_5 ) ;
V_71 = F_26 ( V_2 -> V_36 ) ;
goto V_78;
}
V_71 = F_29 ( V_2 -> V_79 ) ;
if ( V_71 ) {
F_28 ( & V_70 -> V_42 , L_6 ) ;
goto V_78;
}
V_71 = F_29 ( V_2 -> V_36 ) ;
if ( V_71 ) {
F_28 ( & V_70 -> V_42 , L_7 ) ;
goto V_80;
}
F_5 ( V_2 ) ;
V_50 = F_30 ( V_70 , 0 ) ;
if ( V_50 <= 0 ) {
V_71 = - V_81 ;
F_28 ( & V_70 -> V_42 , L_8 ) ;
goto V_78;
}
V_71 = F_31 ( & V_70 -> V_42 , V_50 , F_14 ,
0 , V_70 -> V_82 , V_19 ) ;
if ( V_71 != 0 ) {
V_71 = - V_81 ;
F_28 ( & V_70 -> V_42 , L_9 ) ;
goto V_78;
}
V_71 = F_32 ( V_70 -> V_42 . V_76 , L_10 , & V_74 ) ;
if ( V_71 < 0 )
V_19 -> V_83 = V_84 ;
else
V_19 -> V_83 = V_74 ;
V_71 = F_32 ( V_70 -> V_42 . V_76 , L_11 ,
& V_2 -> V_22 ) ;
if ( V_71 < 0 )
V_2 -> V_22 = 0 ;
V_19 -> V_85 = F_18 ;
V_19 -> V_86 = F_16 ;
V_19 -> V_87 = F_17 ;
V_19 -> V_88 = F_19 ;
V_19 -> V_89 = F_6 ;
V_19 -> V_90 = V_31 | V_30 ;
V_19 -> V_91 = F_10 ( V_2 -> V_36 ) / 4 ;
V_2 -> V_37 = V_19 -> V_91 ;
V_19 -> V_92 = F_33 ( 8 ) ;
V_71 = F_34 ( V_19 ) ;
if ( V_71 ) {
F_28 ( & V_70 -> V_42 , L_12 ) ;
goto V_93;
}
return V_71 ;
V_93:
F_35 ( V_2 -> V_36 ) ;
V_80:
F_35 ( V_2 -> V_79 ) ;
V_78:
F_36 ( V_19 ) ;
return V_71 ;
}
static int F_37 ( struct V_69 * V_70 )
{
struct V_52 * V_19 = F_38 ( V_70 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_3 ( V_2 , V_6 ,
V_7 ) ;
F_35 ( V_2 -> V_36 ) ;
F_35 ( V_2 -> V_79 ) ;
F_39 ( V_19 ) ;
return 0 ;
}
static int T_4 F_40 ( struct V_94 * V_42 )
{
struct V_69 * V_70 = F_41 ( V_42 ,
struct V_69 , V_42 ) ;
struct V_52 * V_19 = F_38 ( V_70 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_42 ( V_19 ) ;
F_35 ( V_2 -> V_36 ) ;
F_35 ( V_2 -> V_79 ) ;
return 0 ;
}
static int T_4 F_43 ( struct V_94 * V_42 )
{
struct V_69 * V_70 = F_41 ( V_42 ,
struct V_69 , V_42 ) ;
struct V_52 * V_19 = F_38 ( V_70 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_71 = 0 ;
V_71 = F_29 ( V_2 -> V_79 ) ;
if ( V_71 ) {
F_28 ( V_42 , L_13 ) ;
return V_71 ;
}
V_71 = F_29 ( V_2 -> V_36 ) ;
if ( V_71 ) {
F_28 ( V_42 , L_14 ) ;
F_44 ( V_2 -> V_79 ) ;
return V_71 ;
}
F_45 ( V_19 ) ;
return 0 ;
}
