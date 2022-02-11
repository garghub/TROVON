static inline void F_1 ( void )
{
F_2 ( ( 1LLU << V_1 ) > V_2 ) ;
}
static void F_3 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_4 ( & V_8 . V_9 ) ;
if ( ! V_8 . V_10 ) {
F_5 ( & V_8 . V_9 ) ;
goto V_11;
}
V_7 = F_6 ( sizeof( * V_7 ) , V_12 ) ;
if ( ! V_7 ) {
F_7 ( & V_8 . V_13 -> V_14 ,
L_1 ) ;
F_5 ( & V_8 . V_9 ) ;
goto V_11;
}
V_7 -> V_15 = V_3 ;
F_8 ( & V_7 -> V_16 , V_5 ) ;
F_5 ( & V_8 . V_9 ) ;
F_9 ( & V_8 . V_17 ) ;
F_10 ( & V_8 . V_18 , V_19 , V_20 ) ;
V_11:
return;
}
static T_1 F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
T_1 V_21 ;
V_7 = F_12 ( V_5 -> V_22 , struct V_6 , V_16 ) ;
V_21 = V_7 -> V_15 ;
F_13 ( & V_7 -> V_16 ) ;
F_14 ( V_7 ) ;
return V_21 ;
}
static void F_15 ( T_1 V_3 )
{
F_3 ( V_3 , & V_8 . V_23 ) ;
}
static void F_16 ( T_1 V_3 , int V_24 )
{
F_3 ( V_3 , & V_8 . V_25 ) ;
F_4 ( & V_8 . V_9 ) ;
V_8 . V_26 ++ ;
while ( V_8 . V_26 > V_24 &&
! F_17 ( & V_8 . V_25 ) ) {
F_18 ( & V_8 . V_13 -> V_14 , L_2
L_3 , V_8 . V_26 ) ;
F_11 ( & V_8 . V_25 ) ;
V_8 . V_26 -- ;
}
F_5 ( & V_8 . V_9 ) ;
}
static inline void F_19 ( struct V_27 * V_15 , T_1 V_28 )
{
T_1 * V_21 = F_20 ( V_15 -> V_29 . V_30 ) ;
* V_21 = V_28 ;
}
static inline T_1 F_21 ( struct V_27 * V_15 )
{
T_1 * V_21 = F_20 ( V_15 -> V_29 . V_30 ) ;
return * V_21 ;
}
static void F_22 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_8 ( & V_15 -> V_34 , & V_32 -> V_35 ) ;
}
static void F_23 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_4 ( & V_32 -> V_9 ) ;
F_18 ( & V_8 . V_13 -> V_14 , L_4 ) ;
if ( V_32 -> V_36 != V_37 )
F_7 ( & V_32 -> V_13 -> V_14 , L_5 ) ;
if ( V_15 -> V_38 == V_39 )
V_32 -> V_40 &=
~ ( V_41 | V_42 ) ;
else if ( V_15 -> V_38 == V_43 &&
V_32 -> V_40 & V_44 )
V_32 -> V_40 &= ~ V_44 ;
F_22 ( V_15 ) ;
F_5 ( & V_32 -> V_9 ) ;
}
static struct V_27 * F_24 ( struct V_31 * V_45 )
{
struct V_27 * V_15 ;
F_25 ( F_17 ( & V_45 -> V_35 ) ) ;
V_15 = F_26 ( & V_45 -> V_35 , struct V_27 , V_34 ) ;
F_13 ( & V_15 -> V_34 ) ;
V_15 -> V_46 = F_23 ;
return V_15 ;
}
static void F_27 ( struct V_31 * V_45 )
{
struct V_27 * V_15 , * V_47 ;
F_28 (msg, tmp, &ssi->cmdqueue, link) {
F_13 ( & V_15 -> V_34 ) ;
V_15 -> V_46 = NULL ;
F_14 ( F_20 ( V_15 -> V_29 . V_30 ) ) ;
F_29 ( V_15 ) ;
}
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_27 * V_15 ;
T_1 * V_48 ;
unsigned int V_49 ;
F_31 ( & V_32 -> V_35 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_15 = F_32 ( 1 , V_51 ) ;
if ( ! V_15 )
goto V_11;
V_48 = F_6 ( sizeof( * V_48 ) , V_51 ) ;
if ( ! V_48 ) {
F_29 ( V_15 ) ;
goto V_11;
}
F_33 ( V_15 -> V_29 . V_30 , V_48 , sizeof( * V_48 ) ) ;
V_15 -> V_52 = V_8 . V_53 ;
V_15 -> V_33 = V_32 ;
F_8 ( & V_15 -> V_34 , & V_32 -> V_35 ) ;
}
return 0 ;
V_11:
F_27 ( V_32 ) ;
return - V_54 ;
}
static void F_34 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
const char * V_55 = ( V_15 -> V_38 == V_39 ) ? L_6 : L_7 ;
F_18 ( & V_8 . V_13 -> V_14 , L_8 , V_55 ) ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_36 != V_37 )
F_7 ( & V_8 . V_13 -> V_14 ,
L_9 , V_55 ) ;
if ( V_15 -> V_38 == V_39 )
V_32 -> V_56 &=
~ ( V_41 | V_42 ) ;
else
V_32 -> V_56 &= ~ V_44 ;
V_15 -> V_57 = V_58 ;
if ( F_35 ( F_36 ( & V_32 -> V_59 ) ) )
F_9 ( & V_32 -> V_59 ) ;
F_5 ( & V_32 -> V_9 ) ;
}
static int F_37 ( struct V_31 * V_32 )
{
struct V_27 * V_60 , * V_61 ;
int V_62 = 0 ;
V_61 = F_32 ( 1 , V_51 ) ;
if ( ! V_61 ) {
V_62 = - V_54 ;
goto V_63;
}
V_61 -> V_52 = V_8 . V_64 ;
V_61 -> V_46 = F_34 ;
V_61 -> V_33 = V_32 ;
V_60 = F_32 ( 1 , V_51 ) ;
if ( ! V_60 ) {
V_62 = - V_54 ;
goto V_65;
}
V_60 -> V_52 = V_8 . V_64 ;
V_60 -> V_46 = F_34 ;
V_60 -> V_33 = V_32 ;
V_32 -> V_66 = V_61 ;
V_32 -> V_67 = V_60 ;
return 0 ;
V_65:
F_29 ( V_61 ) ;
V_63:
return V_62 ;
}
static void F_38 ( struct V_27 * V_15 )
{
F_39 ( V_15 -> V_57 != V_58 &&
V_15 -> V_57 != V_68 ) ;
F_29 ( V_15 ) ;
}
static void F_40 ( struct V_31 * V_32 )
{
F_38 ( V_32 -> V_66 ) ;
F_38 ( V_32 -> V_67 ) ;
}
static inline void F_41 ( struct V_31 * V_32 ,
struct V_27 * V_15 , const char * V_69 ,
unsigned int * V_70 )
{
F_4 ( & V_32 -> V_9 ) ;
F_7 ( & V_32 -> V_13 -> V_14 , L_10 ,
V_69 , V_15 -> V_57 , * V_70 ) ;
}
static inline void F_42 ( struct V_31 * V_32 )
{
F_5 ( & V_32 -> V_9 ) ;
}
static inline void F_43 ( unsigned int * V_70 )
{
* V_70 |= V_71 ;
* V_70 &= ~ ( V_42 | V_41 ) ;
}
static inline void F_44 ( unsigned int * V_70 )
{
* V_70 |= V_71 ;
* V_70 &= ~ V_44 ;
}
static void F_45 ( struct V_31 * V_32 ,
struct V_27 * V_15 )
{
F_41 ( V_32 , V_15 , L_11 , & V_32 -> V_40 ) ;
F_22 ( V_15 ) ;
F_43 ( & V_32 -> V_40 ) ;
F_42 ( V_32 ) ;
}
static void F_46 ( struct V_31 * V_32 ,
struct V_27 * V_15 )
{
F_41 ( V_32 , V_15 , L_12 , & V_32 -> V_40 ) ;
F_22 ( V_15 ) ;
F_44 ( & V_32 -> V_40 ) ;
F_42 ( V_32 ) ;
}
static void F_47 ( struct V_31 * V_32 , struct V_27 * V_15 )
{
F_41 ( V_32 , V_15 , L_13 , & V_32 -> V_56 ) ;
F_43 ( & V_32 -> V_56 ) ;
F_42 ( V_32 ) ;
}
static void F_48 ( struct V_31 * V_32 ,
struct V_27 * V_15 )
{
F_41 ( V_32 , V_15 , L_14 , & V_32 -> V_56 ) ;
F_44 ( & V_32 -> V_56 ) ;
F_42 ( V_32 ) ;
}
static void F_49 ( struct V_27 * V_15 )
{
T_1 V_28 = F_21 ( V_15 ) ;
struct V_31 * V_32 = V_15 -> V_33 ;
F_4 ( & V_32 -> V_9 ) ;
V_32 -> V_40 &= ~ V_42 ;
if ( V_15 -> V_57 == V_68 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_15 ) ;
F_5 ( & V_32 -> V_9 ) ;
F_45 ( V_32 , V_15 ) ;
goto V_11;
}
F_18 ( & V_32 -> V_13 -> V_14 , L_16 , V_28 ) ;
F_22 ( V_15 ) ;
if ( V_32 -> V_72 & V_73 ) {
struct V_74 V_75 ;
struct V_76 * V_77 =
& V_32 -> V_78 -> V_79 ;
F_50 ( & V_75 ) ;
V_77 -> V_80 = ( V_81 ) V_75 . V_80 ;
V_77 -> V_82 = ( V_81 ) V_75 . V_82 ;
}
F_5 ( & V_32 -> V_9 ) ;
F_15 ( V_28 ) ;
V_11:
F_51 ( V_32 ) ;
}
static void F_52 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_83 ;
if ( V_15 -> V_57 == V_68 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_17 ) ;
F_45 ( V_32 , V_15 ) ;
return;
}
F_39 ( ! ( V_32 -> V_40 & V_42 ) ) ;
F_18 ( & V_32 -> V_13 -> V_14 , L_18 ) ;
V_15 -> V_29 . V_84 = 1 ;
V_15 -> V_85 = F_49 ;
V_83 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_83 )
F_45 ( V_32 , V_15 ) ;
}
static void F_51 ( struct V_31 * V_32 )
{
struct V_27 * V_15 ;
int V_83 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_40 & V_42 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_19 ,
V_32 -> V_40 ) ;
F_5 ( & V_32 -> V_9 ) ;
return;
}
if ( V_32 -> V_40 & V_71 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_20 ,
V_32 -> V_40 ) ;
F_5 ( & V_32 -> V_9 ) ;
return;
}
V_32 -> V_40 |= V_42 ;
F_18 ( & V_32 -> V_13 -> V_14 , L_21 ) ;
V_15 = F_24 ( V_32 ) ;
F_5 ( & V_32 -> V_9 ) ;
V_15 -> V_29 . V_84 = 0 ;
V_15 -> V_85 = F_52 ;
V_83 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_83 )
F_45 ( V_32 , V_15 ) ;
}
static void F_54 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_15 -> V_57 == V_58 ) {
F_4 ( & V_32 -> V_9 ) ;
V_32 -> V_40 &= ~ V_44 ;
F_22 ( V_15 ) ;
F_5 ( & V_32 -> V_9 ) ;
} else if ( V_15 -> V_57 == V_68 ) {
F_46 ( V_32 , V_15 ) ;
} else {
F_7 ( & V_32 -> V_13 -> V_14 ,
L_22 ,
V_15 -> V_57 ) ;
}
}
static int F_55 ( struct V_31 * V_32 , T_1 V_3 )
{
struct V_27 * V_15 ;
int V_83 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_40 & V_71 ) {
F_5 ( & V_32 -> V_9 ) ;
return - V_86 ;
}
if ( V_32 -> V_40 & V_44 ) {
F_7 ( & V_32 -> V_13 -> V_14 ,
L_23 ) ;
F_5 ( & V_32 -> V_9 ) ;
return - V_87 ;
}
V_32 -> V_40 |= V_44 ;
V_15 = F_24 ( V_32 ) ;
F_5 ( & V_32 -> V_9 ) ;
F_19 ( V_15 , V_3 ) ;
V_15 -> V_29 . V_84 = 1 ;
V_15 -> V_85 = F_54 ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_24 , V_3 ) ;
V_83 = F_56 ( V_32 -> V_13 , V_15 ) ;
if ( V_83 ) {
F_7 ( & V_32 -> V_13 -> V_14 ,
L_25 , V_83 ) ;
F_46 ( V_32 , V_15 ) ;
}
if ( ! ( V_32 -> V_40 & V_42 ) ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_26 ) ;
F_51 ( V_32 ) ;
}
return 0 ;
}
static void F_57 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 V_88 ;
if ( F_35 ( V_15 -> V_57 == V_68 ) ) {
F_47 ( V_32 , V_15 ) ;
return;
}
F_4 ( & V_32 -> V_9 ) ;
F_39 ( ! ( V_32 -> V_56 & V_42 ) ) ;
V_32 -> V_56 &= ~ V_42 ;
V_88 = V_89 ;
V_88 |= V_32 -> V_90 ;
V_32 -> V_90 ++ ;
V_32 -> V_90 %= V_32 -> V_91 ;
V_32 -> V_78 -> V_92 = V_32 -> V_90 ;
if ( F_35 ( F_36 ( & V_32 -> V_59 ) ) )
F_9 ( & V_32 -> V_59 ) ;
F_5 ( & V_32 -> V_9 ) ;
F_16 ( V_88 , V_32 -> V_93 ) ;
F_58 ( V_32 ) ;
}
static void F_59 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 * V_94 ;
int V_83 ;
if ( F_35 ( V_15 -> V_57 == V_68 ) ) {
F_47 ( V_32 , V_15 ) ;
return;
}
if ( F_35 ( V_32 -> V_36 != V_95 ) ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_27 ) ;
F_47 ( V_32 , V_15 ) ;
return;
}
F_4 ( & V_32 -> V_9 ) ;
F_39 ( ! ( V_32 -> V_56 & V_41 ) ) ;
V_32 -> V_56 &= ~ V_41 ;
V_32 -> V_56 |= V_42 ;
F_5 ( & V_32 -> V_9 ) ;
V_94 = ( T_1 * ) ( V_32 -> V_96 +
V_32 -> V_97 [ V_32 -> V_90 % V_32 -> V_93 ] ) ;
F_33 ( V_15 -> V_29 . V_30 , V_94 , V_32 -> V_98 ) ;
V_15 -> V_29 . V_84 = 1 ;
V_15 -> V_85 = F_57 ;
V_83 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_83 )
F_47 ( V_32 , V_15 ) ;
}
static inline int F_60 ( unsigned int V_70 )
{
return ( V_70 & V_44 ) ||
( V_70 & V_42 ) ;
}
static inline int F_61 ( unsigned int V_70 )
{
return ! ( V_70 & ~ V_71 ) ;
}
static void F_58 ( struct V_31 * V_32 )
{
struct V_27 * V_61 ;
int V_83 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_56 &
( V_42 | V_41 ) ) {
F_18 ( & V_32 -> V_13 -> V_14 , L_28 ,
V_32 -> V_56 ) ;
F_5 ( & V_32 -> V_9 ) ;
return;
}
V_32 -> V_56 |= V_41 ;
F_5 ( & V_32 -> V_9 ) ;
V_61 = V_32 -> V_66 ;
F_33 ( V_61 -> V_29 . V_30 , ( void * ) V_32 -> V_96 , 0 ) ;
V_61 -> V_29 . V_84 = 0 ;
V_61 -> V_85 = F_59 ;
V_83 = F_53 ( V_32 -> V_13 , V_61 ) ;
if ( V_83 )
F_47 ( V_32 , V_61 ) ;
}
static void F_62 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
if ( V_15 -> V_57 == V_58 ) {
F_4 ( & V_32 -> V_9 ) ;
V_32 -> V_56 &= ~ V_44 ;
if ( F_35 ( F_36 ( & V_32 -> V_59 ) ) )
F_9 ( & V_32 -> V_59 ) ;
F_5 ( & V_32 -> V_9 ) ;
} else {
F_48 ( V_32 , V_15 ) ;
}
}
static int F_63 ( struct V_31 * V_32 , unsigned int V_99 )
{
T_1 * V_94 ;
struct V_27 * V_60 ;
int V_83 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_36 != V_95 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_29 ) ;
V_83 = - V_100 ;
goto error;
}
if ( V_32 -> V_56 & V_71 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_30 ) ;
V_83 = - V_86 ;
goto error;
}
if ( V_32 -> V_56 & V_44 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_31 ) ;
V_83 = - V_87 ;
goto error;
}
V_32 -> V_56 |= V_44 ;
F_5 ( & V_32 -> V_9 ) ;
V_32 -> V_101 = V_99 ;
V_94 = ( T_1 * ) ( V_32 -> V_96 + V_32 -> V_102 [ V_32 -> V_101 ] ) ;
V_60 = V_32 -> V_67 ;
F_33 ( V_60 -> V_29 . V_30 , V_94 , V_32 -> V_98 ) ;
V_60 -> V_85 = F_62 ;
V_83 = F_56 ( V_32 -> V_13 , V_60 ) ;
if ( V_83 )
F_48 ( V_32 , V_60 ) ;
return V_83 ;
error:
F_5 ( & V_32 -> V_9 ) ;
if ( V_83 == - V_86 )
F_48 ( V_32 , V_32 -> V_67 ) ;
return V_83 ;
}
static unsigned int F_64 ( struct V_31 * V_32 )
{
return V_32 -> V_36 ;
}
static int F_65 ( struct V_31 * V_32 , T_1 V_28 )
{
int V_83 = 0 ;
F_66 () ;
switch ( V_28 & V_103 ) {
case V_104 :
V_83 = F_55 ( V_32 , V_28 ) ;
break;
case V_105 :
if ( ( V_28 & V_106 ) == V_107 )
V_83 = F_63 ( V_32 , V_28 & V_108 ) ;
else
V_83 = - V_100 ;
break;
default:
V_83 = - V_100 ;
break;
}
F_67 () ;
return V_83 ;
}
static void F_68 ( struct V_31 * V_32 , bool V_109 )
{
int V_110 = 0 ;
F_69 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_111 != V_109 ) {
V_32 -> V_111 = V_109 ;
V_110 = 1 ;
F_18 ( & V_32 -> V_13 -> V_14 , L_32 ,
V_109 , V_32 -> V_13 ) ;
}
F_70 ( & V_32 -> V_9 ) ;
if ( V_110 ) {
if ( V_109 )
F_71 ( V_32 -> V_112 ) ;
else
F_72 ( V_32 -> V_112 ) ;
}
F_18 ( & V_32 -> V_13 -> V_14 , L_33 ,
V_109 , V_32 -> V_13 ) ;
}
static void F_73 ( struct V_31 * V_32 , int V_93 , int V_113 )
{
V_32 -> V_93 = V_93 ;
V_32 -> V_113 = V_113 ;
V_32 -> V_78 -> V_93 = V_93 ;
V_32 -> V_78 -> V_113 = V_113 ;
if ( V_32 -> V_72 & V_114 ) {
V_32 -> V_91 = ( V_93 << V_115 ) ;
V_32 -> V_78 -> V_91 = V_32 -> V_91 ;
} else {
V_32 -> V_91 = V_32 -> V_93 ;
}
}
static int F_74 ( struct V_31 * V_32 ,
const struct V_116 * V_117 )
{
T_2 V_118 = F_75 ( V_117 -> V_98 ) *
( V_117 -> V_93 + V_117 -> V_113 ) ;
T_2 V_119 = F_75 ( sizeof( * V_32 -> V_78 ) ) ;
int V_120 = 0 ;
if ( V_117 -> V_93 > V_121 ||
V_117 -> V_113 > V_121 ) {
V_120 = - V_100 ;
} else if ( ( V_118 + V_119 ) >= V_32 -> V_122 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_34
L_35 ) ;
V_120 = - V_123 ;
}
return V_120 ;
}
static int F_76 ( struct V_31 * V_32 )
{
int V_120 = 0 ;
F_69 ( & V_32 -> V_9 ) ;
if ( ! F_60 ( V_32 -> V_56 ) ) {
F_18 ( & V_32 -> V_13 -> V_14 , L_36 ) ;
goto V_11;
}
for (; ; ) {
int V_124 ;
F_77 ( V_17 ) ;
if ( ! F_60 ( V_32 -> V_56 ) )
goto V_11;
if ( F_78 ( V_125 ) ) {
V_120 = - V_126 ;
goto V_11;
}
F_79 ( & V_32 -> V_59 , & V_17 , V_127 ) ;
F_70 ( & V_32 -> V_9 ) ;
V_124 = F_80 (
F_81 ( V_128 ) ) ;
F_69 ( & V_32 -> V_9 ) ;
F_82 ( & V_32 -> V_59 , & V_17 ) ;
if ( ! V_124 ) {
F_18 ( & V_32 -> V_13 -> V_14 ,
L_37 ,
V_128 ) ;
V_120 = - V_86 ;
goto V_11;
}
}
V_11:
F_70 ( & V_32 -> V_9 ) ;
F_18 ( & V_32 -> V_13 -> V_14 , L_38 , V_120 ) ;
return V_120 ;
}
static void F_83 ( struct V_31 * V_32 ,
struct V_116 * V_117 )
{
unsigned int V_129 , V_49 ;
F_25 ( V_32 -> V_98 == 0 ) ;
F_73 ( V_32 , V_117 -> V_93 , V_117 -> V_113 ) ;
V_32 -> V_130 = F_75 ( V_32 -> V_98 ) ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_39 ,
V_32 -> V_130 , V_32 -> V_98 , V_131 ) ;
V_129 = F_75 ( sizeof( * V_32 -> V_78 ) ) ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_40 ,
V_129 , sizeof( * V_32 -> V_78 ) , V_131 ) ;
for ( V_49 = 0 ; V_49 < V_32 -> V_78 -> V_93 ; V_49 ++ ) {
V_32 -> V_97 [ V_49 ] = V_129 + V_49 * V_32 -> V_130 ;
V_32 -> V_78 -> V_97 [ V_49 ] = V_32 -> V_97 [ V_49 ] ;
F_18 ( & V_32 -> V_13 -> V_14 , L_41 ,
V_49 , V_32 -> V_97 [ V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_32 -> V_78 -> V_113 ; V_49 ++ ) {
V_32 -> V_102 [ V_49 ] = V_129 +
( V_49 + V_32 -> V_78 -> V_93 ) * V_32 -> V_130 ;
V_32 -> V_78 -> V_102 [ V_49 ] = V_32 -> V_102 [ V_49 ] ;
F_18 ( & V_32 -> V_13 -> V_14 , L_42 ,
V_49 , V_32 -> V_97 [ V_49 ] ) ;
}
V_32 -> V_36 = V_95 ;
}
static void F_84 ( struct V_31 * V_32 , int V_132 )
{
if ( V_132 == V_95 ) {
F_18 ( & V_32 -> V_13 -> V_14 ,
L_43 ) ;
V_32 -> V_36 = V_133 ;
}
}
static int F_85 ( struct V_31 * V_32 ,
struct V_116 * V_117 )
{
int V_120 = 0 ;
unsigned int V_132 = V_32 -> V_36 ;
F_69 ( & V_32 -> V_9 ) ;
if ( V_132 == V_95 )
V_32 -> V_36 = V_133 ;
F_70 ( & V_32 -> V_9 ) ;
V_120 = F_76 ( V_32 ) ;
if ( V_120 < 0 )
return V_120 ;
F_39 ( F_60 ( V_32 -> V_56 ) ) ;
F_69 ( & V_32 -> V_9 ) ;
V_120 = F_74 ( V_32 , V_117 ) ;
if ( V_120 < 0 )
goto error;
V_32 -> V_98 = V_117 -> V_98 ;
V_32 -> V_78 -> V_98 = V_32 -> V_98 ;
V_32 -> V_72 = V_117 -> V_72 ;
V_32 -> V_90 = 0 ;
V_32 -> V_101 = 0 ;
V_32 -> V_130 = 0 ;
if ( V_32 -> V_98 )
F_83 ( V_32 , V_117 ) ;
else
F_84 ( V_32 , V_132 ) ;
F_70 ( & V_32 -> V_9 ) ;
if ( V_132 != V_32 -> V_36 ) {
if ( V_32 -> V_36 == V_95 ) {
F_86 ( & V_32 -> V_134 ,
V_135 ,
V_136 ) ;
F_66 () ;
F_58 ( V_32 ) ;
F_67 () ;
} else if ( V_132 == V_95 ) {
F_87 ( & V_32 -> V_134 ) ;
}
}
return V_120 ;
error:
F_70 ( & V_32 -> V_9 ) ;
return V_120 ;
}
static int F_88 ( struct V_31 * * V_32 , struct V_137 * V_13 ,
unsigned long V_96 , unsigned long V_122 )
{
int V_138 = 0 ;
struct V_31 * V_139 = F_89 ( sizeof( * V_139 ) , V_51 ) ;
F_18 ( & V_13 -> V_14 , L_44 ) ;
if ( ! V_139 ) {
V_138 = - V_54 ;
goto V_140;
}
F_90 ( & V_139 -> V_9 ) ;
V_139 -> V_13 = V_13 ;
V_139 -> V_36 = V_37 ;
V_139 -> V_78 = (struct V_141 * ) V_96 ;
V_139 -> V_96 = V_96 ;
V_139 -> V_122 = V_122 ;
memset ( V_139 -> V_78 , 0 , sizeof( * V_139 -> V_78 ) ) ;
F_91 ( & V_139 -> V_59 ) ;
V_138 = F_30 ( V_139 ) ;
if ( V_138 < 0 ) {
F_7 ( & V_13 -> V_14 , L_45 ) ;
goto V_142;
}
V_138 = F_37 ( V_139 ) ;
if ( V_138 < 0 ) {
F_7 ( & V_13 -> V_14 , L_46 ) ;
goto V_143;
}
V_138 = F_92 ( V_13 , 1 ) ;
if ( V_138 < 0 ) {
F_7 ( & V_13 -> V_14 ,
L_47 ) ;
goto V_144;
}
V_139 -> V_112 = F_93 ( V_13 ) ;
if ( F_94 ( V_139 -> V_112 ) ) {
V_138 = F_95 ( V_139 -> V_112 ) ;
F_7 ( & V_13 -> V_14 , L_48 ) ;
goto V_145;
}
if ( ! F_96 ( V_139 -> V_112 ) ) {
V_138 = - V_146 ;
F_7 ( & V_13 -> V_14 ,
L_49 ) ;
goto V_145;
}
V_139 -> V_36 = V_133 ;
F_66 () ;
F_51 ( V_139 ) ;
F_67 () ;
F_18 ( & V_13 -> V_14 , L_50 ) ;
F_25 ( ! V_32 ) ;
* V_32 = V_139 ;
return 0 ;
V_145:
F_97 ( V_13 ) ;
V_144:
F_40 ( V_139 ) ;
V_143:
F_27 ( V_139 ) ;
V_142:
F_14 ( V_139 ) ;
V_140:
F_18 ( & V_13 -> V_14 , L_51 ) ;
return V_138 ;
}
static void F_98 ( struct V_31 * V_32 )
{
F_18 ( & V_32 -> V_13 -> V_14 , L_52 ) ;
F_68 ( V_32 , 0 ) ;
F_99 ( V_32 -> V_112 ) ;
V_32 -> V_36 = V_37 ;
F_97 ( V_32 -> V_13 ) ;
F_39 ( ! F_61 ( V_32 -> V_40 ) ) ;
F_39 ( ! F_61 ( V_32 -> V_56 ) ) ;
if ( F_100 ( & V_32 -> V_134 ) )
F_87 ( & V_32 -> V_134 ) ;
F_69 ( & V_32 -> V_9 ) ;
F_40 ( V_32 ) ;
F_27 ( V_32 ) ;
F_70 ( & V_32 -> V_9 ) ;
F_14 ( V_32 ) ;
}
static int F_101 ( struct V_147 * V_148 )
{
struct V_149 * V_150 = V_148 -> V_151 -> V_152 ;
struct V_153 * V_153 ;
V_153 = F_102 ( V_150 -> V_96 ) ;
F_103 ( V_153 ) ;
V_148 -> V_153 = V_153 ;
return 0 ;
}
static int F_104 ( int V_154 , struct V_155 * V_155 , int V_156 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
if ( F_105 ( V_154 , V_155 , V_156 , & V_150 -> V_18 ) < 0 )
return - V_86 ;
return 0 ;
}
static unsigned int F_106 ( struct V_155 * V_155 , T_3 * V_17 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
unsigned int V_83 = 0 ;
F_107 ( V_155 , & V_8 . V_17 , V_17 ) ;
F_69 ( & V_150 -> V_9 ) ;
if ( ! F_17 ( & V_150 -> V_23 ) )
V_83 = V_158 | V_159 ;
else if ( ! F_17 ( & V_150 -> V_25 ) )
V_83 = V_158 | V_159 ;
F_70 ( & V_150 -> V_9 ) ;
return V_83 ;
}
static T_4 F_108 ( struct V_155 * V_155 , char T_5 * V_48 , T_2 V_160 ,
T_6 * V_161 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
T_1 V_21 ;
T_4 V_162 ;
if ( V_160 < sizeof( V_21 ) )
return - V_100 ;
for (; ; ) {
F_77 ( V_17 ) ;
F_69 ( & V_150 -> V_9 ) ;
if ( ! F_17 ( & V_150 -> V_23 ) ) {
V_21 = F_11 ( & V_150 -> V_23 ) ;
} else if ( ! F_17 ( & V_150 -> V_25 ) ) {
V_21 = F_11 ( & V_150 -> V_25 ) ;
V_150 -> V_26 -- ;
} else {
V_21 = 0 ;
}
F_70 ( & V_150 -> V_9 ) ;
if ( V_21 )
break;
if ( V_155 -> V_163 & V_164 ) {
V_162 = - V_165 ;
goto V_11;
} else if ( F_78 ( V_125 ) ) {
V_162 = - V_126 ;
goto V_11;
}
F_109 ( & V_150 -> V_17 , & V_17 ,
V_127 ) ;
F_110 () ;
F_82 ( & V_150 -> V_17 , & V_17 ) ;
}
V_162 = F_111 ( V_21 , ( T_1 T_5 * ) V_48 ) ;
if ( ! V_162 )
V_162 = sizeof( V_21 ) ;
V_11:
return V_162 ;
}
static T_4 F_112 ( struct V_155 * V_155 , const char T_5 * V_48 ,
T_2 V_160 , T_6 * V_161 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
T_1 V_21 ;
int V_138 ;
T_4 V_162 ;
if ( V_160 < sizeof( V_21 ) )
return - V_100 ;
if ( F_113 ( V_21 , ( T_1 T_5 * ) V_48 ) )
V_162 = - V_166 ;
else
V_162 = V_160 ;
V_138 = F_65 ( V_150 -> V_32 , V_21 ) ;
if ( V_138 < 0 )
V_162 = V_138 ;
return V_162 ;
}
static long F_114 ( struct V_155 * V_155 , unsigned int V_28 ,
unsigned long V_167 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
int V_120 = 0 ;
switch ( V_28 ) {
case V_168 : {
unsigned int V_70 ;
V_70 = F_64 ( V_150 -> V_32 ) ;
if ( F_115 ( ( void T_5 * ) V_167 , & V_70 , sizeof( V_70 ) ) )
V_120 = - V_166 ;
break;
}
case V_169 : {
unsigned int V_70 ;
if ( F_116 ( & V_70 , ( void T_5 * ) V_167 , sizeof( V_70 ) ) ) {
V_120 = - V_166 ;
break;
}
if ( V_70 > 1 ) {
V_120 = - V_100 ;
break;
}
F_68 ( V_150 -> V_32 , ! ! V_70 ) ;
break;
}
case V_170 : {
unsigned int V_171 = V_172 ;
if ( F_115 ( ( void T_5 * ) V_167 , & V_171 , sizeof( V_171 ) ) )
V_120 = - V_166 ;
break;
}
case V_173 : {
struct V_116 V_117 ;
if ( F_116 ( & V_117 , ( void T_5 * ) V_167 ,
sizeof( V_117 ) ) )
V_120 = - V_166 ;
else
V_120 = F_85 ( V_150 -> V_32 , & V_117 ) ;
break;
}
default:
V_120 = - V_174 ;
break;
}
return V_120 ;
}
static int F_117 ( struct V_155 * V_155 , struct V_175 * V_151 )
{
if ( V_151 -> V_176 < V_151 -> V_177 )
return - V_100 ;
if ( F_118 ( V_151 ) != 1 )
return - V_100 ;
V_151 -> V_178 |= V_179 | V_180 | V_181 ;
V_151 -> V_182 = & V_183 ;
V_151 -> V_152 = V_155 -> V_157 ;
return 0 ;
}
static int F_119 ( struct V_184 * V_161 , struct V_155 * V_155 )
{
int V_83 = 0 ;
unsigned long V_185 ;
F_69 ( & V_8 . V_9 ) ;
if ( V_8 . V_10 ) {
V_83 = - V_87 ;
F_70 ( & V_8 . V_9 ) ;
goto V_63;
}
V_8 . V_10 = 1 ;
V_8 . V_26 = 0 ;
F_70 ( & V_8 . V_9 ) ;
V_185 = F_120 ( V_51 ) ;
if ( ! V_185 ) {
V_83 = - V_54 ;
goto V_65;
}
V_83 = F_88 ( & V_8 . V_32 , V_8 . V_13 , V_185 , V_186 ) ;
if ( V_83 ) {
F_7 ( & V_8 . V_13 -> V_14 , L_53 ) ;
goto V_187;
}
V_8 . V_96 = V_185 ;
V_8 . V_122 = V_186 ;
V_155 -> V_157 = & V_8 ;
return 0 ;
V_187:
F_121 ( V_185 ) ;
V_65:
F_69 ( & V_8 . V_9 ) ;
V_8 . V_10 = 0 ;
F_70 ( & V_8 . V_9 ) ;
V_63:
return V_83 ;
}
static void F_122 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_4 * V_188 , * V_22 ;
if ( ! F_17 ( V_5 ) ) {
F_123 (cursor, next, head) {
V_7 = F_12 ( V_188 , struct V_6 , V_16 ) ;
F_13 ( & V_7 -> V_16 ) ;
F_14 ( V_7 ) ;
}
}
}
static int F_124 ( struct V_184 * V_161 , struct V_155 * V_155 )
{
struct V_149 * V_150 = V_155 -> V_157 ;
F_98 ( V_150 -> V_32 ) ;
F_69 ( & V_150 -> V_9 ) ;
V_150 -> V_32 = NULL ;
F_121 ( V_150 -> V_96 ) ;
F_122 ( & V_150 -> V_23 ) ;
F_122 ( & V_150 -> V_25 ) ;
V_150 -> V_10 = 0 ;
F_70 ( & V_150 -> V_9 ) ;
return 0 ;
}
static int F_125 ( struct V_14 * V_189 )
{
int V_138 = 0 ;
struct V_137 * V_13 = F_126 ( V_189 ) ;
F_18 ( V_189 , L_54 ) ;
F_91 ( & V_8 . V_17 ) ;
F_90 ( & V_8 . V_9 ) ;
V_8 . V_10 = 0 ;
V_8 . V_13 = V_13 ;
V_8 . V_32 = NULL ;
F_31 ( & V_8 . V_23 ) ;
F_31 ( & V_8 . V_25 ) ;
V_8 . V_53 = F_127 ( V_13 ,
L_55 ) ;
if ( V_8 . V_53 < 0 ) {
V_138 = V_8 . V_53 ;
F_7 ( V_189 , L_56 , V_138 ) ;
return V_138 ;
}
V_8 . V_64 = F_127 ( V_13 ,
L_57 ) ;
if ( V_8 . V_64 < 0 ) {
V_138 = V_8 . V_64 ;
F_7 ( V_189 , L_58 , V_138 ) ;
return V_138 ;
}
V_138 = F_128 ( & V_190 ) ;
if ( V_138 )
F_7 ( V_189 , L_59 , V_138 ) ;
return V_138 ;
}
static int F_129 ( struct V_14 * V_189 )
{
struct V_31 * V_32 ;
F_18 ( V_189 , L_60 ) ;
F_130 ( & V_190 ) ;
F_69 ( & V_8 . V_9 ) ;
V_32 = V_8 . V_32 ;
V_8 . V_32 = NULL ;
F_70 ( & V_8 . V_9 ) ;
if ( V_32 )
F_98 ( V_32 ) ;
return 0 ;
}
static int T_7 F_131 ( void )
{
F_132 ( L_61 ) ;
return F_133 ( & V_191 ) ;
}
static void T_8 F_134 ( void )
{
F_135 ( & V_191 ) ;
F_132 ( L_62 ) ;
}
