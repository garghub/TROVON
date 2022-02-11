static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_2 ( V_4 , V_2 -> V_7 + V_3 + 3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_8 ;
if ( V_2 -> V_5 == V_6 )
V_8 = F_4 ( V_2 -> V_7 + V_3 ) ;
else
V_8 = F_4 ( V_2 -> V_7 + V_3 + 3 ) ;
return V_8 ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_6 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_7 ( V_4 , V_2 -> V_7 + V_3 + 2 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_9 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_10 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static inline int F_11 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_8 ;
if ( V_2 -> V_5 == V_6 )
V_8 = F_12 ( V_2 -> V_7 + V_3 ) ;
else
V_8 = F_13 ( V_2 -> V_7 + V_3 ) ;
return V_8 ;
}
static inline void F_14 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_10 = F_11 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_11 , V_10 & ~ V_9 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_10 = F_11 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_11 , V_10 | V_9 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_12 = F_11 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_13 , V_12 & V_9 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_3 V_9 )
{
F_16 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_9 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_14 ;
for ( V_14 = F_3 ( V_2 , V_15 ) ;
! ( V_14 & V_16 ) ;
V_14 = F_3 ( V_2 , V_15 ) )
F_3 ( V_2 , V_17 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_1 ( V_2 , V_20 , V_21 - 1 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
F_1 ( V_2 , V_22 , V_24 ) ;
F_18 ( V_2 ) ;
F_8 ( V_2 , V_25 , V_26 ) ;
F_17 ( V_2 , V_27 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_28 ;
F_8 ( V_2 , V_18 , V_19 ) ;
V_28 = F_3 ( V_2 , V_22 ) ;
F_1 ( V_2 , V_22 , V_28 & ~ V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_29 ;
int V_30 ;
V_29 = F_3 ( V_2 , V_31 ) + 1 ;
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_1 ,
V_35 , V_29 , F_23 ( V_2 ) ,
F_3 ( V_2 , V_15 ) ,
F_3 ( V_2 , V_22 ) ) ;
if ( V_29 > F_23 ( V_2 ) )
V_29 = F_23 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
V_2 -> V_36 -> V_37 [ V_2 -> V_38 ++ ] =
F_3 ( V_2 , V_17 ) ;
F_1 ( V_2 , V_20 ,
( F_23 ( V_2 ) > V_21 ) ?
V_21 - 1 : F_23 ( V_2 ) - 1 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return V_39 - F_3 ( V_2 , V_40 ) - 1 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_41 = F_24 ( V_2 ) ;
int V_42 = F_26 ( V_2 ) ;
V_42 = ( V_42 > V_41 ) ? V_41 : V_42 ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_2 ,
V_35 , V_42 , V_41 ) ;
while ( V_42 -- ) {
T_2 V_43 = V_2 -> V_44 -> V_37 [ V_2 -> V_45 ++ ] ;
if ( ( F_26 ( V_2 ) == 0 ) && ( V_2 -> V_46 == 1 ) ) {
V_43 |= V_47 ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_3 , V_35 ) ;
}
F_5 ( V_2 , V_48 , V_43 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_49 )
{
V_2 -> V_44 = NULL ;
V_2 -> V_36 = NULL ;
V_2 -> V_46 = 0 ;
V_2 -> V_50 = V_49 ;
F_28 ( & V_2 -> V_51 ) ;
}
static T_4 F_29 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
T_3 V_54 , V_12 , V_10 ;
T_3 V_55 = 0 ;
F_30 ( & V_2 -> V_56 ) ;
V_12 = F_11 ( V_2 , V_13 ) ;
V_10 = F_11 ( V_2 , V_11 ) ;
V_54 = V_12 & V_10 ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_4 ,
V_35 , V_10 , V_12 , V_54 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_5 ,
V_35 , F_3 ( V_2 , V_15 ) ,
V_2 -> V_44 , V_2 -> V_46 ) ;
if ( ( V_54 & V_27 ) ||
( ( V_54 & V_57 ) &&
! ( V_54 & V_58 ) ) ) {
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_6 , V_35 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_36 )
F_27 ( V_2 , V_59 ) ;
if ( V_2 -> V_44 )
F_27 ( V_2 , V_59 ) ;
}
if ( V_54 & V_58 ) {
V_55 |= V_58 ;
if ( ! V_2 -> V_36 ) {
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_7 , V_35 ) ;
F_18 ( V_2 ) ;
goto V_60;
}
F_21 ( V_2 ) ;
if ( F_23 ( V_2 ) == 0 ) {
V_2 -> V_36 = NULL ;
V_55 |= ( V_12 & V_57 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_8 ,
V_35 , V_2 -> V_46 ) ;
if ( V_2 -> V_46 > 1 ) {
V_2 -> V_46 -- ;
V_2 -> V_44 ++ ;
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_9 , V_35 ) ;
F_31 ( V_2 ) ;
}
}
}
if ( V_54 & V_61 ) {
V_55 |= V_61 ;
F_14 ( V_2 , V_61 ) ;
if ( ! V_2 -> V_44 )
goto V_60;
if ( ( V_2 -> V_46 == 1 ) && ! V_2 -> V_36 &&
F_26 ( V_2 ) == 0 )
F_27 ( V_2 , V_62 ) ;
else
F_27 ( V_2 , V_59 ) ;
}
if ( V_54 & ( V_63 | V_64 ) ) {
V_55 |= ( V_54 &
( V_63 | V_64 ) ) ;
if ( ! V_2 -> V_44 ) {
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_10 , V_35 ) ;
goto V_60;
}
F_25 ( V_2 ) ;
if ( ! F_26 ( V_2 ) && F_24 ( V_2 ) >= 2 ) {
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_11 ,
V_35 , V_2 -> V_46 ) ;
if ( V_2 -> V_46 > 1 ) {
V_2 -> V_46 -- ;
V_2 -> V_44 ++ ;
F_31 ( V_2 ) ;
} else {
F_14 ( V_2 , V_64 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 ,
L_12 ,
V_35 ) ;
}
} else if ( ! F_26 ( V_2 ) && ( V_2 -> V_46 == 1 ) )
F_14 ( V_2 , V_64 ) ;
}
V_60:
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_13 , V_35 , V_55 ) ;
F_8 ( V_2 , V_13 , V_55 ) ;
F_32 ( & V_2 -> V_56 ) ;
return V_65 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_14 = F_3 ( V_2 , V_15 ) ;
return ( V_14 & V_66 ) ? - V_67 : 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_68 = 3 ;
int V_69 ;
if ( V_2 -> V_44 )
return - V_67 ;
V_69 = F_33 ( V_2 ) ;
while ( V_69 && V_68 -- ) {
F_35 ( 1 ) ;
V_69 = F_33 ( V_2 ) ;
}
return V_69 ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_70 ;
struct V_71 * V_72 = V_2 -> V_36 = V_2 -> V_44 ;
F_17 ( V_2 , V_58 | V_57 ) ;
V_70 = V_72 -> V_42 ;
if ( V_70 > V_21 )
V_70 = V_21 ;
F_1 ( V_2 , V_20 , V_70 - 1 ) ;
if ( ! ( V_72 -> V_73 & V_74 ) )
F_5 ( V_2 , V_48 ,
( V_72 -> V_75 << 1 ) | V_76 |
V_77 ) ;
F_17 ( V_2 , V_61 ) ;
F_5 ( V_2 , V_48 ,
V_72 -> V_42 | ( ( V_2 -> V_46 == 1 ) ? V_47 : 0 ) ) ;
if ( V_2 -> V_46 == 1 )
F_17 ( V_2 , V_61 ) ;
V_2 -> V_45 = V_72 -> V_42 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = V_2 -> V_44 ;
F_16 ( V_2 , V_57 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_14 ,
V_35 , V_72 , V_72 -> V_42 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_15 ,
V_35 , F_11 ( V_2 , V_13 ) ,
F_3 ( V_2 , V_22 ) ) ;
if ( ! ( V_72 -> V_73 & V_74 ) ) {
T_2 V_43 = ( ( V_72 -> V_75 << 1 ) & 0xfe ) | V_78 |
V_77 ;
if ( ( V_2 -> V_46 == 1 ) && V_72 -> V_42 == 0 )
V_43 |= V_47 ;
F_5 ( V_2 , V_48 , V_43 ) ;
}
F_25 ( V_2 ) ;
F_17 ( V_2 , V_63 | V_57 |
V_61 ) ;
}
static T_4 F_38 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
T_3 V_54 , V_12 , V_10 ;
T_4 V_8 = V_79 ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_16 , V_35 ) ;
V_12 = F_11 ( V_2 , V_13 ) ;
V_10 = F_11 ( V_2 , V_11 ) ;
V_54 = V_12 & V_10 ;
if ( V_54 )
V_8 = V_80 ;
return V_8 ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_81 = 1 ;
int V_41 = F_24 ( V_2 ) ;
F_22 ( V_2 -> V_32 . V_33 . V_34 , L_17 ,
V_35 , V_2 -> V_44 , V_41 ) ;
if ( ! V_2 -> V_44 )
return;
V_2 -> V_38 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_50 = V_82 ;
while ( ( V_41 >= 2 ) && ( V_81 || ( V_2 -> V_46 > 1 ) ) ) {
if ( ! V_81 ) {
V_2 -> V_46 -- ;
V_2 -> V_44 ++ ;
V_2 -> V_45 = 0 ;
} else
V_81 = 0 ;
if ( V_2 -> V_44 -> V_73 & V_83 ) {
F_36 ( V_2 ) ;
return;
} else {
F_37 ( V_2 ) ;
if ( F_26 ( V_2 ) != 0 ) {
break;
}
}
V_41 = F_24 ( V_2 ) ;
}
if ( V_2 -> V_46 > 1 || F_26 ( V_2 ) )
F_17 ( V_2 , V_64 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
}
static int F_40 ( struct V_84 * V_32 , struct V_71 * V_85 , int V_86 )
{
struct V_1 * V_2 = F_41 ( V_32 ) ;
int V_69 ;
F_22 ( V_32 -> V_33 . V_34 , L_18 , V_35 ,
F_3 ( V_2 , V_15 ) ) ;
V_69 = F_34 ( V_2 ) ;
if ( V_69 )
return V_69 ;
V_2 -> V_44 = V_85 ;
V_2 -> V_46 = V_86 ;
F_39 ( V_2 ) ;
if ( F_42 ( V_2 -> V_51 , ( V_2 -> V_50 == V_59 ) ||
( V_2 -> V_50 == V_62 ) , V_87 ) )
return ( V_2 -> V_50 == V_62 ) ? V_86 : - V_88 ;
else {
V_2 -> V_44 = NULL ;
V_2 -> V_36 = NULL ;
V_2 -> V_46 = 0 ;
return - V_89 ;
}
}
static T_3 F_43 ( struct V_84 * V_32 )
{
return V_90 | V_91 ;
}
static int F_44 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
int V_8 , V_52 ;
T_1 V_30 ;
T_3 V_14 ;
V_2 = F_45 ( & V_93 -> V_33 , sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
V_97 = F_46 ( V_93 , V_100 , 0 ) ;
V_2 -> V_7 = F_47 ( & V_93 -> V_33 , V_97 ) ;
if ( F_48 ( V_2 -> V_7 ) )
return F_49 ( V_2 -> V_7 ) ;
V_52 = F_50 ( V_93 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
V_95 = F_51 ( & V_93 -> V_33 ) ;
F_52 ( V_93 , V_2 ) ;
V_2 -> V_32 = V_101 ;
F_53 ( & V_2 -> V_32 , V_2 ) ;
V_2 -> V_32 . V_33 . V_34 = & V_93 -> V_33 ;
V_2 -> V_32 . V_33 . V_102 = V_93 -> V_33 . V_102 ;
F_54 ( & V_2 -> V_56 ) ;
F_55 ( & V_2 -> V_51 ) ;
V_8 = F_56 ( & V_93 -> V_33 , V_52 , F_38 ,
F_29 , V_103 ,
V_93 -> V_104 , V_2 ) ;
if ( V_8 < 0 ) {
F_57 ( & V_93 -> V_33 , L_19 ) ;
return V_8 ;
}
V_2 -> V_5 = V_6 ;
F_8 ( V_2 , V_22 , V_23 ) ;
V_14 = F_11 ( V_2 , V_15 ) ;
if ( ! ( V_14 & V_105 ) )
V_2 -> V_5 = V_106 ;
F_19 ( V_2 ) ;
V_8 = F_58 ( & V_2 -> V_32 ) ;
if ( V_8 ) {
F_57 ( & V_93 -> V_33 , L_20 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
if ( V_95 ) {
for ( V_30 = 0 ; V_30 < V_95 -> V_107 ; V_30 ++ )
F_59 ( & V_2 -> V_32 , V_95 -> V_108 + V_30 ) ;
}
return 0 ;
}
static int F_60 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_61 ( V_93 ) ;
F_62 ( & V_2 -> V_32 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
