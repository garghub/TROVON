static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_8 + V_9 ) ;
if ( V_4 )
V_2 -> V_10 = V_6 | V_3 ;
else
V_2 -> V_10 = V_6 & ~ V_3 ;
F_4 ( V_2 -> V_10 , V_2 -> V_8 + V_9 ) ;
F_5 ( & V_2 -> V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_6 = F_3 ( V_2 -> V_8 + V_11 ) ;
F_4 ( V_6 | V_3 , V_2 -> V_8 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_12 = F_3 ( V_2 -> V_8 + V_13 ) ;
F_4 ( V_12 & ~ V_14 , V_2 -> V_8 + V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_12 = F_3 ( V_2 -> V_8 + V_13 ) ;
F_4 ( V_12 | V_14 , V_2 -> V_8 + V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_4 ( V_15 , V_2 -> V_8 + V_16 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_17 = F_12 ( V_2 -> V_18 ) / V_2 -> V_19 ;
T_1 V_20 = F_12 ( V_2 -> V_18 ) / 1000000 ;
T_1 V_12 = ( V_21 << V_22 ) |
( V_21 << V_23 ) ;
T_1 V_24 , V_25 ;
if ( V_2 -> V_19 <= 100000 ) {
V_12 &= ~ V_26 ;
V_24 = V_17 * 1 / 2 ;
V_25 = V_17 * 1 / 2 ;
} else {
V_12 |= V_26 ;
V_24 = V_17 * 1 / 3 ;
V_25 = V_17 * 2 / 3 ;
}
F_4 ( V_12 , V_2 -> V_8 + V_13 ) ;
F_13 ( V_2 -> V_27 , L_1 ,
V_2 -> V_19 , V_20 , V_17 ) ;
F_9 ( V_2 ) ;
F_4 ( V_24 , V_2 -> V_8 + V_28 ) ;
F_4 ( V_25 , V_2 -> V_8 + V_29 ) ;
F_4 ( F_14 ( 300 * V_20 , 1000 ) , V_2 -> V_8 + V_30 ) ;
F_1 ( V_2 , V_31 , false ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( V_2 -> V_33 == 1 )
V_32 |= V_15 ;
if ( V_2 -> V_33 > 0 )
F_4 ( V_32 , V_2 -> V_8 + V_16 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_34 = F_3 ( V_2 -> V_8 + V_35 ) ;
int V_36 = F_17 ( V_34 , V_2 -> V_33 ) ;
while ( V_36 -- > 0 ) {
* V_2 -> V_37 ++ = F_3 ( V_2 -> V_8 + V_38 ) ;
V_2 -> V_33 -- ;
F_15 ( V_2 , 0 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_39 = V_2 -> V_40 - F_3 ( V_2 -> V_8 +
V_41 ) ;
int V_36 = F_17 ( V_39 , V_2 -> V_33 ) ;
int V_42 = V_2 -> V_33 - V_36 ;
while ( V_36 -- > 0 ) {
F_15 ( V_2 , * V_2 -> V_37 ++ ) ;
V_2 -> V_33 -- ;
}
return V_42 ;
}
static T_3 F_19 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
T_3 V_42 = V_45 ;
V_2 -> V_46 = F_3 ( V_2 -> V_8 + V_11 ) & V_2 -> V_10 ;
if ( V_2 -> V_46 )
V_42 = V_47 ;
return V_42 ;
}
static T_3 F_20 ( int V_43 , void * V_44 )
{
int V_42 ;
bool V_48 , V_49 = false ;
struct V_1 * V_2 = V_44 ;
T_1 V_50 = V_2 -> V_46 ;
if ( ! V_2 -> V_51 ) {
F_21 ( V_2 -> V_27 , L_2 ) ;
F_6 ( V_2 , V_31 ) ;
return V_45 ;
}
V_48 = ( V_2 -> V_51 -> V_5 & V_52 ) != 0 ;
if ( F_22 ( V_50 & V_53 ) ) {
F_6 ( V_2 , V_53 ) ;
V_2 -> V_54 = - V_55 ;
V_49 = true ;
} else if ( F_22 ( V_50 & V_56 ) ) {
F_13 ( V_2 -> V_27 , L_3 ) ;
V_2 -> V_54 = - V_57 ;
F_6 ( V_2 , V_56 ) ;
F_10 ( V_2 ) ;
V_49 = true ;
} else if ( V_48 && F_22 ( V_50 & V_58 ) ) {
F_16 ( V_2 ) ;
F_6 ( V_2 , V_59 ) ;
F_10 ( V_2 ) ;
F_23 ( V_2 -> V_27 , L_4 ) ;
V_49 = true ;
} else if ( V_48 && ( V_50 & V_59 ) ) {
F_16 ( V_2 ) ;
F_6 ( V_2 , V_59 ) ;
if ( ! V_2 -> V_33 )
V_49 = true ;
} else if ( ! V_48 && ( V_50 & V_60 ) ) {
F_6 ( V_2 , V_60 ) ;
if ( V_2 -> V_33 > 0 )
F_18 ( V_2 ) ;
else
V_49 = true ;
} else {
F_21 ( V_2 -> V_27 , L_5 , V_50 ) ;
F_6 ( V_2 , V_31 ) ;
}
if ( V_49 ) {
V_42 = F_24 ( V_2 -> V_8 + V_61 ,
V_50 ,
! ( V_50 & V_62 ) ,
1 , V_63 ) ;
if ( V_42 )
F_23 ( V_2 -> V_27 , L_6 ) ;
F_1 ( V_2 , V_31 , false ) ;
F_6 ( V_2 , V_31 ) ;
F_25 ( & V_2 -> V_64 ) ;
F_13 ( V_2 -> V_27 , L_7 ) ;
}
return V_45 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_65 * V_51 )
{
T_1 V_66 = V_58 | V_53 | V_56 ;
unsigned long V_67 ;
T_1 V_68 ;
T_4 V_69 = F_27 ( V_51 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_33 = V_51 -> V_70 ;
V_2 -> V_37 = V_51 -> V_37 ;
V_2 -> V_54 = 0 ;
F_28 ( & V_2 -> V_64 ) ;
F_8 ( V_2 ) ;
do {
F_3 ( V_2 -> V_8 + V_38 ) ;
} while ( F_3 ( V_2 -> V_8 + V_35 ) );
F_4 ( V_71 | V_69 , V_2 -> V_8 + V_16 ) ;
if ( ( V_51 -> V_5 & V_52 ) != 0 ) {
V_66 |= V_72 | V_73 ;
F_1 ( V_2 , V_66 , true ) ;
F_15 ( V_2 , 0 ) ;
} else {
V_66 |= V_60 ;
F_1 ( V_2 , V_66 , true ) ;
F_18 ( V_2 ) ;
}
V_67 = F_29 ( & V_2 -> V_64 ,
V_74 ) ;
F_1 ( V_2 , V_66 , false ) ;
V_68 = F_3 ( V_2 -> V_8 + V_61 ) & V_62 ;
if ( V_68 )
F_23 ( V_2 -> V_27 , L_8 ) ;
if ( V_67 == 0 ) {
V_2 -> V_54 = - V_75 ;
F_13 ( V_2 -> V_27 , L_9 ) ;
}
F_7 ( V_2 ) ;
return V_2 -> V_54 ;
}
static int
F_30 ( struct V_76 * V_77 , struct V_65 * V_78 , int V_79 )
{
struct V_1 * V_2 = F_31 ( V_77 ) ;
int V_80 , V_42 ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_42 = F_26 ( V_2 , V_78 ++ ) ;
if ( V_42 )
return V_42 ;
}
return V_79 ;
}
static T_1 F_32 ( struct V_76 * V_77 )
{
return V_81 | V_82 ;
}
static int F_33 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = NULL ;
struct V_85 * V_86 ;
int V_43 , V_42 ;
T_1 V_87 ;
V_2 = F_34 ( & V_84 -> V_27 , sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_86 = F_35 ( V_84 , V_90 , 0 ) ;
V_2 -> V_8 = F_36 ( & V_84 -> V_27 , V_86 ) ;
if ( F_37 ( V_2 -> V_8 ) )
return F_38 ( V_2 -> V_8 ) ;
V_43 = F_39 ( V_84 , 0 ) ;
if ( V_43 < 0 ) {
F_23 ( & V_84 -> V_27 , L_10 ) ;
return V_43 ;
}
V_2 -> V_18 = F_40 ( & V_84 -> V_27 , NULL ) ;
if ( F_37 ( V_2 -> V_18 ) ) {
F_23 ( & V_84 -> V_27 , L_11 ) ;
return F_38 ( V_2 -> V_18 ) ;
}
V_2 -> V_27 = & V_84 -> V_27 ;
F_41 ( & V_2 -> V_64 ) ;
F_42 ( & V_2 -> V_7 ) ;
V_87 = F_43 ( V_2 -> V_27 , L_12 ,
& V_2 -> V_40 ) ;
if ( V_87 ) {
F_23 ( & V_84 -> V_27 , L_13 ,
V_91 ) ;
V_2 -> V_40 = V_91 ;
}
V_87 = F_43 ( V_2 -> V_27 , L_14 ,
& V_2 -> V_19 ) ;
if ( V_87 ) {
F_23 ( & V_84 -> V_27 , L_15 ) ;
V_2 -> V_19 = 100000 ;
}
if ( V_2 -> V_19 > 400000 ) {
F_23 ( & V_84 -> V_27 , L_16 ,
V_2 -> V_19 ) ;
return - V_92 ;
}
V_42 = F_44 ( & V_84 -> V_27 , V_43 , F_19 ,
F_20 , V_93 ,
V_84 -> V_94 , V_2 ) ;
if ( V_42 ) {
F_23 ( & V_84 -> V_27 , L_17 , V_43 ) ;
return V_42 ;
}
V_42 = F_45 ( V_2 -> V_18 ) ;
if ( V_42 ) {
F_23 ( & V_84 -> V_27 , L_18 ) ;
return V_42 ;
}
F_11 ( V_2 ) ;
F_46 ( & V_2 -> V_95 , V_2 ) ;
F_47 ( V_2 -> V_95 . V_94 , V_84 -> V_94 , sizeof( V_2 -> V_95 . V_94 ) ) ;
V_2 -> V_95 . V_96 = V_97 ;
V_2 -> V_95 . V_98 = & V_99 ;
V_2 -> V_95 . V_27 . V_100 = & V_84 -> V_27 ;
V_2 -> V_95 . V_27 . V_101 = V_84 -> V_27 . V_101 ;
F_48 ( V_84 , V_2 ) ;
V_42 = F_49 ( & V_2 -> V_95 ) ;
if ( V_42 ) {
F_50 ( V_2 -> V_18 ) ;
return V_42 ;
}
F_51 ( & V_84 -> V_27 , L_19 ) ;
return 0 ;
}
static int F_52 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_53 ( V_84 ) ;
F_50 ( V_2 -> V_18 ) ;
F_54 ( & V_2 -> V_95 ) ;
return 0 ;
}
