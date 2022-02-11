static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_8 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline int F_9 ( struct V_1 * V_2 , int V_3 )
{
return F_10 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_3 V_6 )
{
T_3 V_7 = F_9 ( V_2 , V_8 ) ;
F_7 ( V_2 , V_8 , V_7 & ~ V_6 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , T_3 V_6 )
{
T_3 V_7 = F_9 ( V_2 , V_8 ) ;
F_7 ( V_2 , V_8 , V_7 | V_6 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , T_3 V_6 )
{
T_3 V_9 = F_9 ( V_2 , V_10 ) ;
F_7 ( V_2 , V_10 , V_9 & V_6 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_3 V_6 )
{
F_13 ( V_2 , V_6 ) ;
F_12 ( V_2 , V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_11 ;
for ( V_11 = F_3 ( V_2 , V_12 ) ;
! ( V_11 & V_13 ) ;
V_11 = F_3 ( V_2 , V_12 ) )
F_3 ( V_2 , V_14 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_15 , V_16 ) ;
F_1 ( V_2 , V_17 , V_18 - 1 ) ;
F_1 ( V_2 , V_19 , V_20 ) ;
F_1 ( V_2 , V_19 , V_21 ) ;
F_15 ( V_2 ) ;
F_7 ( V_2 , V_22 , V_23 ) ;
F_14 ( V_2 , V_24 | V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_26 ;
F_7 ( V_2 , V_15 , V_16 ) ;
V_26 = F_3 ( V_2 , V_19 ) ;
F_1 ( V_2 , V_19 , V_26 & ~ V_21 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_27 ;
int V_28 ;
V_27 = F_3 ( V_2 , V_29 ) + 1 ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_1
L_2 ,
V_33 , V_27 , F_20 ( V_2 ) ,
F_3 ( V_2 , V_12 ) ,
F_3 ( V_2 , V_19 ) ) ;
if ( V_27 > F_20 ( V_2 ) )
V_27 = F_20 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
V_2 -> V_34 -> V_35 [ V_2 -> V_36 ++ ] =
F_3 ( V_2 , V_14 ) ;
F_1 ( V_2 , V_17 ,
( F_20 ( V_2 ) > V_18 ) ?
V_18 - 1 : F_20 ( V_2 ) - 1 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return V_37 - F_3 ( V_2 , V_38 ) - 1 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_39 = F_21 ( V_2 ) ;
int V_40 = F_23 ( V_2 ) ;
V_40 = ( V_40 > V_39 ) ? V_39 : V_40 ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_3 ,
V_33 , V_40 , V_39 ) ;
while ( V_40 -- ) {
T_2 V_41 = V_2 -> V_42 -> V_35 [ V_2 -> V_43 ++ ] ;
if ( ( F_23 ( V_2 ) == 0 ) && ( V_2 -> V_44 == 1 ) ) {
V_41 |= V_45 ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_4 , V_33 ) ;
}
F_5 ( V_2 , V_46 , V_41 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_47 )
{
V_2 -> V_42 = NULL ;
V_2 -> V_34 = NULL ;
V_2 -> V_44 = 0 ;
V_2 -> V_48 = V_47 ;
F_25 ( & V_2 -> V_49 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_3 V_50 , V_9 , V_7 ;
T_3 V_51 = 0 ;
V_9 = F_9 ( V_2 , V_10 ) ;
V_7 = F_9 ( V_2 , V_8 ) ;
V_50 = V_9 & V_7 ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_5
L_6 ,
V_33 , V_7 , V_9 , V_50 , F_3 ( V_2 , V_12 ) ,
V_2 -> V_42 , V_2 -> V_44 ) ;
if ( ! V_50 )
return;
if ( ( V_50 & V_25 ) ||
( ( V_50 & V_52 ) &&
! ( V_50 & V_53 ) ) ) {
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_7 , V_33 ) ;
F_16 ( V_2 ) ;
if ( V_2 -> V_42 )
F_24 ( V_2 , V_54 ) ;
} else if ( V_50 & V_53 ) {
V_51 = V_53 ;
if ( ! V_2 -> V_34 ) {
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_8 , V_33 ) ;
F_15 ( V_2 ) ;
goto V_55;
}
F_18 ( V_2 ) ;
if ( F_20 ( V_2 ) == 0 ) {
V_2 -> V_34 = NULL ;
V_51 |= ( V_9 & V_52 ) ;
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_9 ,
V_33 , V_2 -> V_44 ) ;
if ( V_2 -> V_44 > 1 ) {
V_2 -> V_44 -- ;
V_2 -> V_42 ++ ;
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_10 , V_33 ) ;
F_27 ( V_2 ) ;
}
}
} else if ( V_50 & V_56 ) {
V_51 = V_56 ;
F_11 ( V_2 , V_56 ) ;
if ( ! V_2 -> V_42 )
goto V_55;
if ( ( V_2 -> V_44 == 1 ) && ! V_2 -> V_34 &&
F_23 ( V_2 ) == 0 )
F_24 ( V_2 , V_57 ) ;
else
F_24 ( V_2 , V_54 ) ;
} else if ( V_50 & ( V_58 | V_59 ) ) {
V_51 = V_50 &
( V_58 | V_59 ) ;
if ( ! V_2 -> V_42 ) {
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_11 , V_33 ) ;
goto V_55;
}
F_22 ( V_2 ) ;
if ( ! F_23 ( V_2 ) && F_21 ( V_2 ) >= 2 ) {
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_12 ,
V_33 , V_2 -> V_44 ) ;
if ( V_2 -> V_44 > 1 ) {
V_2 -> V_44 -- ;
V_2 -> V_42 ++ ;
F_27 ( V_2 ) ;
} else {
F_11 ( V_2 , V_59 ) ;
F_19 ( V_2 -> V_30 . V_31 . V_32 ,
L_13 ,
V_33 ) ;
}
} else if ( ! F_23 ( V_2 ) && ( V_2 -> V_44 == 1 ) )
F_11 ( V_2 , V_59 ) ;
} else {
F_28 ( V_2 -> V_30 . V_31 . V_32 , L_14 ,
V_33 ) ;
V_51 = V_50 ;
}
V_55:
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_15 , V_33 , V_51 ) ;
F_7 ( V_2 , V_10 , V_51 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_11 = F_3 ( V_2 , V_12 ) ;
return ( V_11 & V_60 ) ? - V_61 : 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_62 = 3 ;
int V_63 ;
if ( V_2 -> V_42 )
return - V_61 ;
V_63 = F_29 ( V_2 ) ;
while ( V_63 && V_62 -- ) {
F_31 ( 1 ) ;
V_63 = F_29 ( V_2 ) ;
}
return V_63 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_64 ;
struct V_65 * V_66 = V_2 -> V_34 = V_2 -> V_42 ;
F_14 ( V_2 , V_53 | V_52 ) ;
V_64 = V_66 -> V_40 ;
if ( V_64 > V_18 )
V_64 = V_18 ;
F_1 ( V_2 , V_17 , V_64 - 1 ) ;
if ( ! ( V_66 -> V_67 & V_68 ) )
F_5 ( V_2 , V_46 ,
( V_66 -> V_69 << 1 ) | V_70 |
V_71 ) ;
F_14 ( V_2 , V_56 ) ;
F_5 ( V_2 , V_46 ,
V_66 -> V_40 | ( ( V_2 -> V_44 == 1 ) ? V_45 : 0 ) ) ;
if ( V_2 -> V_44 == 1 )
F_14 ( V_2 , V_56 ) ;
V_2 -> V_43 = V_66 -> V_40 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_42 ;
F_13 ( V_2 , V_52 ) ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_16
L_17 ,
V_33 , V_66 , V_66 -> V_40 , F_9 ( V_2 , V_10 ) ,
F_3 ( V_2 , V_19 ) ) ;
if ( ! ( V_66 -> V_67 & V_68 ) ) {
T_2 V_41 = ( ( V_66 -> V_69 << 1 ) & 0xfe ) | V_72 |
V_71 ;
if ( ( V_2 -> V_44 == 1 ) && V_66 -> V_40 == 0 )
V_41 |= V_45 ;
F_5 ( V_2 , V_46 , V_41 ) ;
}
F_22 ( V_2 ) ;
F_14 ( V_2 , V_58 | V_52 |
V_56 ) ;
}
static T_4 F_34 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
F_35 ( & V_2 -> V_75 ) ;
F_7 ( V_2 , V_22 , 0 ) ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_18 , V_33 ) ;
F_26 ( V_2 ) ;
F_7 ( V_2 , V_22 , V_23 ) ;
F_36 ( & V_2 -> V_75 ) ;
return V_76 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_77 = 1 ;
int V_39 = F_21 ( V_2 ) ;
F_19 ( V_2 -> V_30 . V_31 . V_32 , L_19 ,
V_33 , V_2 -> V_42 , V_39 ) ;
if ( ! V_2 -> V_42 )
return;
V_2 -> V_36 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_48 = V_78 ;
while ( ( V_39 >= 2 ) && ( V_77 || ( V_2 -> V_44 > 1 ) ) ) {
if ( ! V_77 ) {
V_2 -> V_44 -- ;
V_2 -> V_42 ++ ;
V_2 -> V_43 = 0 ;
} else
V_77 = 0 ;
if ( V_2 -> V_42 -> V_67 & V_79 ) {
F_32 ( V_2 ) ;
return;
} else {
F_33 ( V_2 ) ;
if ( F_23 ( V_2 ) != 0 ) {
break;
}
}
V_39 = F_21 ( V_2 ) ;
}
if ( V_2 -> V_44 > 1 || F_23 ( V_2 ) )
F_14 ( V_2 , V_59 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned long V_67 ;
F_38 ( & V_2 -> V_75 , V_67 ) ;
F_16 ( V_2 ) ;
F_7 ( V_2 , V_22 , 0 ) ;
F_39 ( & V_2 -> V_75 , V_67 ) ;
F_27 ( V_2 ) ;
F_7 ( V_2 , V_22 , V_23 ) ;
}
static int F_40 ( struct V_80 * V_30 , struct V_65 * V_81 , int V_82 )
{
struct V_1 * V_2 = F_41 ( V_30 ) ;
int V_63 ;
F_19 ( V_30 -> V_31 . V_32 , L_20 , V_33 ,
F_3 ( V_2 , V_12 ) ) ;
V_63 = F_30 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_42 = V_81 ;
V_2 -> V_44 = V_82 ;
F_37 ( V_2 ) ;
if ( F_42 ( V_2 -> V_49 , ( V_2 -> V_48 == V_54 ) ||
( V_2 -> V_48 == V_57 ) , V_83 ) )
return ( V_2 -> V_48 == V_57 ) ? V_82 : - V_84 ;
else {
V_2 -> V_42 = NULL ;
V_2 -> V_34 = NULL ;
V_2 -> V_44 = 0 ;
return - V_85 ;
}
}
static T_3 F_43 ( struct V_80 * V_30 )
{
return V_86 | V_87 ;
}
static int F_44 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
int V_94 , V_73 ;
T_1 V_28 ;
V_93 = F_45 ( V_89 , V_95 , 0 ) ;
if ( ! V_93 )
goto V_96;
V_73 = F_46 ( V_89 , 0 ) ;
if ( V_73 < 0 )
goto V_96;
V_91 = F_47 ( & V_89 -> V_31 ) ;
V_2 = F_48 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
if ( ! F_49 ( V_93 -> V_99 , F_50 ( V_93 ) , V_89 -> V_100 ) ) {
F_28 ( & V_89 -> V_31 , L_21 ) ;
V_94 = - V_61 ;
goto V_101;
}
V_2 -> V_5 = F_51 ( V_93 -> V_99 , F_50 ( V_93 ) ) ;
if ( ! V_2 -> V_5 ) {
F_28 ( & V_89 -> V_31 , L_22 ) ;
V_94 = - V_84 ;
goto V_102;
}
F_52 ( V_89 , V_2 ) ;
V_2 -> V_30 = V_103 ;
F_53 ( & V_2 -> V_30 , V_2 ) ;
V_2 -> V_30 . V_31 . V_32 = & V_89 -> V_31 ;
V_2 -> V_30 . V_31 . V_104 = V_89 -> V_31 . V_104 ;
F_16 ( V_2 ) ;
F_54 ( & V_2 -> V_75 ) ;
F_55 ( & V_2 -> V_49 ) ;
V_94 = F_56 ( V_73 , F_34 , 0 , V_89 -> V_100 , V_2 ) ;
if ( V_94 ) {
F_28 ( & V_89 -> V_31 , L_23 ) ;
goto V_105;
}
V_94 = F_57 ( & V_2 -> V_30 ) ;
if ( V_94 ) {
F_28 ( & V_89 -> V_31 , L_24 ) ;
goto V_106;
}
if ( V_91 ) {
for ( V_28 = 0 ; V_28 < V_91 -> V_107 ; V_28 ++ )
F_58 ( & V_2 -> V_30 , V_91 -> V_108 + V_28 ) ;
}
return 0 ;
V_106:
F_59 ( V_73 , V_2 ) ;
V_105:
F_17 ( V_2 ) ;
F_60 ( V_2 -> V_5 ) ;
V_102:
F_61 ( V_93 -> V_99 , F_50 ( V_93 ) ) ;
V_101:
F_62 ( V_2 ) ;
return V_94 ;
V_96:
F_28 ( & V_89 -> V_31 , L_25 ) ;
return - V_109 ;
}
static int F_63 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_64 ( V_89 ) ;
struct V_92 * V_93 ;
F_65 ( & V_2 -> V_30 ) ;
F_17 ( V_2 ) ;
F_59 ( F_46 ( V_89 , 0 ) , V_2 ) ;
F_60 ( V_2 -> V_5 ) ;
V_93 = F_45 ( V_89 , V_95 , 0 ) ;
if ( V_93 )
F_61 ( V_93 -> V_99 , F_50 ( V_93 ) ) ;
F_62 ( V_2 ) ;
return 0 ;
}
