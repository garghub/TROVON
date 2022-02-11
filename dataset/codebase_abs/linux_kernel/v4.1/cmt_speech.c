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
F_45 ( V_32 , V_15 ) ;
F_5 ( & V_32 -> V_9 ) ;
goto V_11;
}
F_18 ( & V_32 -> V_13 -> V_14 , L_16 , V_28 ) ;
F_22 ( V_15 ) ;
if ( V_32 -> V_72 & V_73 ) {
struct V_74 * V_75 =
& V_32 -> V_76 -> V_77 ;
F_50 ( V_75 ) ;
}
F_5 ( & V_32 -> V_9 ) ;
F_15 ( V_28 ) ;
V_11:
F_51 ( V_32 ) ;
}
static void F_52 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
int V_78 ;
if ( V_15 -> V_57 == V_68 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_17 ) ;
F_45 ( V_32 , V_15 ) ;
return;
}
F_39 ( ! ( V_32 -> V_40 & V_42 ) ) ;
F_18 ( & V_32 -> V_13 -> V_14 , L_18 ) ;
V_15 -> V_29 . V_79 = 1 ;
V_15 -> V_80 = F_49 ;
V_78 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_78 )
F_45 ( V_32 , V_15 ) ;
}
static void F_51 ( struct V_31 * V_32 )
{
struct V_27 * V_15 ;
int V_78 ;
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
V_15 -> V_29 . V_79 = 0 ;
V_15 -> V_80 = F_52 ;
V_78 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_78 )
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
int V_78 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_40 & V_71 ) {
F_5 ( & V_32 -> V_9 ) ;
return - V_81 ;
}
if ( V_32 -> V_40 & V_44 ) {
F_7 ( & V_32 -> V_13 -> V_14 ,
L_23 ) ;
F_5 ( & V_32 -> V_9 ) ;
return - V_82 ;
}
V_32 -> V_40 |= V_44 ;
V_15 = F_24 ( V_32 ) ;
F_5 ( & V_32 -> V_9 ) ;
F_19 ( V_15 , V_3 ) ;
V_15 -> V_29 . V_79 = 1 ;
V_15 -> V_80 = F_54 ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_24 , V_3 ) ;
V_78 = F_56 ( V_32 -> V_13 , V_15 ) ;
if ( V_78 ) {
F_7 ( & V_32 -> V_13 -> V_14 ,
L_25 , V_78 ) ;
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
T_1 V_83 ;
if ( F_35 ( V_15 -> V_57 == V_68 ) ) {
F_47 ( V_32 , V_15 ) ;
return;
}
F_4 ( & V_32 -> V_9 ) ;
F_39 ( ! ( V_32 -> V_56 & V_42 ) ) ;
V_32 -> V_56 &= ~ V_42 ;
V_83 = V_84 ;
V_83 |= V_32 -> V_85 ;
V_32 -> V_85 ++ ;
V_32 -> V_85 %= V_32 -> V_86 ;
V_32 -> V_76 -> V_87 = V_32 -> V_85 ;
if ( F_35 ( F_36 ( & V_32 -> V_59 ) ) )
F_9 ( & V_32 -> V_59 ) ;
F_5 ( & V_32 -> V_9 ) ;
F_16 ( V_83 , V_32 -> V_88 ) ;
F_58 ( V_32 ) ;
}
static void F_59 ( struct V_27 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
T_1 * V_89 ;
int V_78 ;
if ( F_35 ( V_15 -> V_57 == V_68 ) ) {
F_47 ( V_32 , V_15 ) ;
return;
}
if ( F_35 ( V_32 -> V_36 != V_90 ) ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_27 ) ;
F_47 ( V_32 , V_15 ) ;
return;
}
F_4 ( & V_32 -> V_9 ) ;
F_39 ( ! ( V_32 -> V_56 & V_41 ) ) ;
V_32 -> V_56 &= ~ V_41 ;
V_32 -> V_56 |= V_42 ;
F_5 ( & V_32 -> V_9 ) ;
V_89 = ( T_1 * ) ( V_32 -> V_91 +
V_32 -> V_92 [ V_32 -> V_85 % V_32 -> V_88 ] ) ;
F_33 ( V_15 -> V_29 . V_30 , V_89 , V_32 -> V_93 ) ;
V_15 -> V_29 . V_79 = 1 ;
V_15 -> V_80 = F_57 ;
V_78 = F_53 ( V_32 -> V_13 , V_15 ) ;
if ( V_78 )
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
int V_78 ;
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
F_33 ( V_61 -> V_29 . V_30 , ( void * ) V_32 -> V_91 , 0 ) ;
V_61 -> V_29 . V_79 = 0 ;
V_61 -> V_80 = F_59 ;
V_78 = F_53 ( V_32 -> V_13 , V_61 ) ;
if ( V_78 )
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
static int F_63 ( struct V_31 * V_32 , unsigned int V_94 )
{
T_1 * V_89 ;
struct V_27 * V_60 ;
int V_78 ;
F_4 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_36 != V_90 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_29 ) ;
V_78 = - V_95 ;
goto error;
}
if ( V_32 -> V_56 & V_71 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_30 ) ;
V_78 = - V_81 ;
goto error;
}
if ( V_32 -> V_56 & V_44 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_31 ) ;
V_78 = - V_82 ;
goto error;
}
V_32 -> V_56 |= V_44 ;
F_5 ( & V_32 -> V_9 ) ;
V_32 -> V_96 = V_94 ;
V_89 = ( T_1 * ) ( V_32 -> V_91 + V_32 -> V_97 [ V_32 -> V_96 ] ) ;
V_60 = V_32 -> V_67 ;
F_33 ( V_60 -> V_29 . V_30 , V_89 , V_32 -> V_93 ) ;
V_60 -> V_80 = F_62 ;
V_78 = F_56 ( V_32 -> V_13 , V_60 ) ;
if ( V_78 )
F_48 ( V_32 , V_60 ) ;
return V_78 ;
error:
F_5 ( & V_32 -> V_9 ) ;
if ( V_78 == - V_81 )
F_48 ( V_32 , V_32 -> V_67 ) ;
return V_78 ;
}
static unsigned int F_64 ( struct V_31 * V_32 )
{
return V_32 -> V_36 ;
}
static int F_65 ( struct V_31 * V_32 , T_1 V_28 )
{
int V_78 = 0 ;
F_66 () ;
switch ( V_28 & V_98 ) {
case V_99 :
V_78 = F_55 ( V_32 , V_28 ) ;
break;
case V_100 :
if ( ( V_28 & V_101 ) == V_102 )
V_78 = F_63 ( V_32 , V_28 & V_103 ) ;
else
V_78 = - V_95 ;
break;
default:
V_78 = - V_95 ;
break;
}
F_67 () ;
return V_78 ;
}
static void F_68 ( struct V_31 * V_32 , bool V_104 )
{
int V_105 = 0 ;
F_69 ( & V_32 -> V_9 ) ;
if ( V_32 -> V_106 != V_104 ) {
V_32 -> V_106 = V_104 ;
V_105 = 1 ;
F_18 ( & V_32 -> V_13 -> V_14 , L_32 ,
V_104 , V_32 -> V_13 ) ;
}
F_70 ( & V_32 -> V_9 ) ;
if ( V_105 ) {
if ( V_104 )
F_71 ( V_32 -> V_107 ) ;
else
F_72 ( V_32 -> V_107 ) ;
}
F_18 ( & V_32 -> V_13 -> V_14 , L_33 ,
V_104 , V_32 -> V_13 ) ;
}
static void F_73 ( struct V_31 * V_32 , int V_88 , int V_108 )
{
V_32 -> V_88 = V_88 ;
V_32 -> V_108 = V_108 ;
V_32 -> V_76 -> V_88 = V_88 ;
V_32 -> V_76 -> V_108 = V_108 ;
if ( V_32 -> V_72 & V_109 ) {
V_32 -> V_86 = ( V_88 << V_110 ) ;
V_32 -> V_76 -> V_86 = V_32 -> V_86 ;
} else {
V_32 -> V_86 = V_32 -> V_88 ;
}
}
static int F_74 ( struct V_31 * V_32 ,
const struct V_111 * V_112 )
{
T_2 V_113 = F_75 ( V_112 -> V_93 ) *
( V_112 -> V_88 + V_112 -> V_108 ) ;
T_2 V_114 = F_75 ( sizeof( * V_32 -> V_76 ) ) ;
int V_115 = 0 ;
if ( V_112 -> V_88 > V_116 ||
V_112 -> V_108 > V_116 ) {
V_115 = - V_95 ;
} else if ( ( V_113 + V_114 ) >= V_32 -> V_117 ) {
F_7 ( & V_32 -> V_13 -> V_14 , L_34
L_35 ) ;
V_115 = - V_118 ;
}
return V_115 ;
}
static int F_76 ( struct V_31 * V_32 )
{
int V_115 = 0 ;
F_69 ( & V_32 -> V_9 ) ;
if ( ! F_60 ( V_32 -> V_56 ) ) {
F_18 ( & V_32 -> V_13 -> V_14 , L_36 ) ;
goto V_11;
}
for (; ; ) {
int V_119 ;
F_77 ( V_17 ) ;
if ( ! F_60 ( V_32 -> V_56 ) )
goto V_11;
if ( F_78 ( V_120 ) ) {
V_115 = - V_121 ;
goto V_11;
}
F_79 ( & V_32 -> V_59 , & V_17 , V_122 ) ;
F_70 ( & V_32 -> V_9 ) ;
V_119 = F_80 (
F_81 ( V_123 ) ) ;
F_69 ( & V_32 -> V_9 ) ;
F_82 ( & V_32 -> V_59 , & V_17 ) ;
if ( ! V_119 ) {
F_18 ( & V_32 -> V_13 -> V_14 ,
L_37 ,
V_123 ) ;
V_115 = - V_81 ;
goto V_11;
}
}
V_11:
F_70 ( & V_32 -> V_9 ) ;
F_18 ( & V_32 -> V_13 -> V_14 , L_38 , V_115 ) ;
return V_115 ;
}
static void F_83 ( struct V_31 * V_32 ,
struct V_111 * V_112 )
{
unsigned int V_124 , V_49 ;
F_25 ( V_32 -> V_93 == 0 ) ;
F_73 ( V_32 , V_112 -> V_88 , V_112 -> V_108 ) ;
V_32 -> V_125 = F_75 ( V_32 -> V_93 ) ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_39 ,
V_32 -> V_125 , V_32 -> V_93 , V_126 ) ;
V_124 = F_75 ( sizeof( * V_32 -> V_76 ) ) ;
F_18 ( & V_32 -> V_13 -> V_14 ,
L_40 ,
V_124 , sizeof( * V_32 -> V_76 ) , V_126 ) ;
for ( V_49 = 0 ; V_49 < V_32 -> V_76 -> V_88 ; V_49 ++ ) {
V_32 -> V_92 [ V_49 ] = V_124 + V_49 * V_32 -> V_125 ;
V_32 -> V_76 -> V_92 [ V_49 ] = V_32 -> V_92 [ V_49 ] ;
F_18 ( & V_32 -> V_13 -> V_14 , L_41 ,
V_49 , V_32 -> V_92 [ V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_32 -> V_76 -> V_108 ; V_49 ++ ) {
V_32 -> V_97 [ V_49 ] = V_124 +
( V_49 + V_32 -> V_76 -> V_88 ) * V_32 -> V_125 ;
V_32 -> V_76 -> V_97 [ V_49 ] = V_32 -> V_97 [ V_49 ] ;
F_18 ( & V_32 -> V_13 -> V_14 , L_42 ,
V_49 , V_32 -> V_92 [ V_49 ] ) ;
}
V_32 -> V_36 = V_90 ;
}
static void F_84 ( struct V_31 * V_32 , int V_127 )
{
if ( V_127 == V_90 ) {
F_18 ( & V_32 -> V_13 -> V_14 ,
L_43 ) ;
V_32 -> V_36 = V_128 ;
}
}
static int F_85 ( struct V_31 * V_32 ,
struct V_111 * V_112 )
{
int V_115 = 0 ;
unsigned int V_127 = V_32 -> V_36 ;
F_69 ( & V_32 -> V_9 ) ;
if ( V_127 == V_90 )
V_32 -> V_36 = V_128 ;
F_70 ( & V_32 -> V_9 ) ;
V_115 = F_76 ( V_32 ) ;
if ( V_115 < 0 )
return V_115 ;
F_39 ( F_60 ( V_32 -> V_56 ) ) ;
F_69 ( & V_32 -> V_9 ) ;
V_115 = F_74 ( V_32 , V_112 ) ;
if ( V_115 < 0 )
goto error;
V_32 -> V_93 = V_112 -> V_93 ;
V_32 -> V_76 -> V_93 = V_32 -> V_93 ;
V_32 -> V_72 = V_112 -> V_72 ;
V_32 -> V_85 = 0 ;
V_32 -> V_96 = 0 ;
V_32 -> V_125 = 0 ;
if ( V_32 -> V_93 )
F_83 ( V_32 , V_112 ) ;
else
F_84 ( V_32 , V_127 ) ;
F_70 ( & V_32 -> V_9 ) ;
if ( V_127 != V_32 -> V_36 ) {
if ( V_32 -> V_36 == V_90 ) {
F_86 ( & V_32 -> V_129 ,
V_130 ,
V_131 ) ;
F_66 () ;
F_58 ( V_32 ) ;
F_67 () ;
} else if ( V_127 == V_90 ) {
F_87 ( & V_32 -> V_129 ) ;
}
}
return V_115 ;
error:
F_70 ( & V_32 -> V_9 ) ;
return V_115 ;
}
static int F_88 ( struct V_31 * * V_32 , struct V_132 * V_13 ,
unsigned long V_91 , unsigned long V_117 )
{
int V_133 = 0 ;
struct V_31 * V_134 = F_89 ( sizeof( * V_134 ) , V_51 ) ;
F_18 ( & V_13 -> V_14 , L_44 ) ;
if ( ! V_134 ) {
V_133 = - V_54 ;
goto V_135;
}
F_90 ( & V_134 -> V_9 ) ;
V_134 -> V_13 = V_13 ;
V_134 -> V_36 = V_37 ;
V_134 -> V_76 = (struct V_136 * ) V_91 ;
V_134 -> V_91 = V_91 ;
V_134 -> V_117 = V_117 ;
memset ( V_134 -> V_76 , 0 , sizeof( * V_134 -> V_76 ) ) ;
F_91 ( & V_134 -> V_59 ) ;
V_133 = F_30 ( V_134 ) ;
if ( V_133 < 0 ) {
F_7 ( & V_13 -> V_14 , L_45 ) ;
goto V_137;
}
V_133 = F_37 ( V_134 ) ;
if ( V_133 < 0 ) {
F_7 ( & V_13 -> V_14 , L_46 ) ;
goto V_138;
}
V_133 = F_92 ( V_13 , 1 ) ;
if ( V_133 < 0 ) {
F_7 ( & V_13 -> V_14 ,
L_47 ) ;
goto V_139;
}
V_134 -> V_107 = F_93 ( V_13 ) ;
if ( F_94 ( V_134 -> V_107 ) ) {
V_133 = F_95 ( V_134 -> V_107 ) ;
F_7 ( & V_13 -> V_14 , L_48 ) ;
goto V_140;
}
if ( ! F_96 ( V_134 -> V_107 ) ) {
V_133 = - V_141 ;
F_7 ( & V_13 -> V_14 ,
L_49 ) ;
goto V_140;
}
V_134 -> V_36 = V_128 ;
F_66 () ;
F_51 ( V_134 ) ;
F_67 () ;
F_18 ( & V_13 -> V_14 , L_50 ) ;
F_25 ( ! V_32 ) ;
* V_32 = V_134 ;
return 0 ;
V_140:
F_97 ( V_13 ) ;
V_139:
F_40 ( V_134 ) ;
V_138:
F_27 ( V_134 ) ;
V_137:
F_14 ( V_134 ) ;
V_135:
F_18 ( & V_13 -> V_14 , L_51 ) ;
return V_133 ;
}
static void F_98 ( struct V_31 * V_32 )
{
F_18 ( & V_32 -> V_13 -> V_14 , L_52 ) ;
F_68 ( V_32 , 0 ) ;
F_99 ( V_32 -> V_107 ) ;
V_32 -> V_36 = V_37 ;
F_97 ( V_32 -> V_13 ) ;
F_39 ( ! F_61 ( V_32 -> V_40 ) ) ;
F_39 ( ! F_61 ( V_32 -> V_56 ) ) ;
if ( F_100 ( & V_32 -> V_129 ) )
F_87 ( & V_32 -> V_129 ) ;
F_69 ( & V_32 -> V_9 ) ;
F_40 ( V_32 ) ;
F_27 ( V_32 ) ;
F_70 ( & V_32 -> V_9 ) ;
F_14 ( V_32 ) ;
}
static int F_101 ( struct V_142 * V_143 , struct V_144 * V_145 )
{
struct V_146 * V_147 = V_143 -> V_148 ;
struct V_149 * V_149 ;
V_149 = F_102 ( V_147 -> V_91 ) ;
F_103 ( V_149 ) ;
V_145 -> V_149 = V_149 ;
return 0 ;
}
static int F_104 ( int V_150 , struct V_151 * V_151 , int V_152 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
if ( F_105 ( V_150 , V_151 , V_152 , & V_147 -> V_18 ) < 0 )
return - V_81 ;
return 0 ;
}
static unsigned int F_106 ( struct V_151 * V_151 , T_3 * V_17 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
unsigned int V_78 = 0 ;
F_107 ( V_151 , & V_8 . V_17 , V_17 ) ;
F_69 ( & V_147 -> V_9 ) ;
if ( ! F_17 ( & V_147 -> V_23 ) )
V_78 = V_154 | V_155 ;
else if ( ! F_17 ( & V_147 -> V_25 ) )
V_78 = V_154 | V_155 ;
F_70 ( & V_147 -> V_9 ) ;
return V_78 ;
}
static T_4 F_108 ( struct V_151 * V_151 , char T_5 * V_48 , T_2 V_156 ,
T_6 * V_157 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
T_1 V_21 ;
T_4 V_158 ;
if ( V_156 < sizeof( V_21 ) )
return - V_95 ;
for (; ; ) {
F_77 ( V_17 ) ;
F_69 ( & V_147 -> V_9 ) ;
if ( ! F_17 ( & V_147 -> V_23 ) ) {
V_21 = F_11 ( & V_147 -> V_23 ) ;
} else if ( ! F_17 ( & V_147 -> V_25 ) ) {
V_21 = F_11 ( & V_147 -> V_25 ) ;
V_147 -> V_26 -- ;
} else {
V_21 = 0 ;
}
F_70 ( & V_147 -> V_9 ) ;
if ( V_21 )
break;
if ( V_151 -> V_159 & V_160 ) {
V_158 = - V_161 ;
goto V_11;
} else if ( F_78 ( V_120 ) ) {
V_158 = - V_121 ;
goto V_11;
}
F_109 ( & V_147 -> V_17 , & V_17 ,
V_122 ) ;
F_110 () ;
F_82 ( & V_147 -> V_17 , & V_17 ) ;
}
V_158 = F_111 ( V_21 , ( T_1 T_5 * ) V_48 ) ;
if ( ! V_158 )
V_158 = sizeof( V_21 ) ;
V_11:
return V_158 ;
}
static T_4 F_112 ( struct V_151 * V_151 , const char T_5 * V_48 ,
T_2 V_156 , T_6 * V_157 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
T_1 V_21 ;
int V_133 ;
T_4 V_158 ;
if ( V_156 < sizeof( V_21 ) )
return - V_95 ;
if ( F_113 ( V_21 , ( T_1 T_5 * ) V_48 ) )
V_158 = - V_162 ;
else
V_158 = V_156 ;
V_133 = F_65 ( V_147 -> V_32 , V_21 ) ;
if ( V_133 < 0 )
V_158 = V_133 ;
return V_158 ;
}
static long F_114 ( struct V_151 * V_151 , unsigned int V_28 ,
unsigned long V_163 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
int V_115 = 0 ;
switch ( V_28 ) {
case V_164 : {
unsigned int V_70 ;
V_70 = F_64 ( V_147 -> V_32 ) ;
if ( F_115 ( ( void T_5 * ) V_163 , & V_70 , sizeof( V_70 ) ) )
V_115 = - V_162 ;
break;
}
case V_165 : {
unsigned int V_70 ;
if ( F_116 ( & V_70 , ( void T_5 * ) V_163 , sizeof( V_70 ) ) ) {
V_115 = - V_162 ;
break;
}
if ( V_70 > 1 ) {
V_115 = - V_95 ;
break;
}
F_68 ( V_147 -> V_32 , ! ! V_70 ) ;
break;
}
case V_166 : {
unsigned int V_167 = V_168 ;
if ( F_115 ( ( void T_5 * ) V_163 , & V_167 , sizeof( V_167 ) ) )
V_115 = - V_162 ;
break;
}
case V_169 : {
struct V_111 V_112 ;
if ( F_116 ( & V_112 , ( void T_5 * ) V_163 ,
sizeof( V_112 ) ) )
V_115 = - V_162 ;
else
V_115 = F_85 ( V_147 -> V_32 , & V_112 ) ;
break;
}
default:
V_115 = - V_170 ;
break;
}
return V_115 ;
}
static int F_117 ( struct V_151 * V_151 , struct V_142 * V_143 )
{
if ( V_143 -> V_171 < V_143 -> V_172 )
return - V_95 ;
if ( ( ( V_143 -> V_171 - V_143 -> V_172 ) >> V_173 ) != 1 )
return - V_95 ;
V_143 -> V_174 |= V_175 | V_176 | V_177 ;
V_143 -> V_178 = & V_179 ;
V_143 -> V_148 = V_151 -> V_153 ;
return 0 ;
}
static int F_118 ( struct V_180 * V_157 , struct V_151 * V_151 )
{
int V_78 = 0 ;
unsigned long V_181 ;
F_69 ( & V_8 . V_9 ) ;
if ( V_8 . V_10 ) {
V_78 = - V_82 ;
F_70 ( & V_8 . V_9 ) ;
goto V_63;
}
V_8 . V_10 = 1 ;
V_8 . V_26 = 0 ;
F_70 ( & V_8 . V_9 ) ;
V_181 = F_119 ( V_51 ) ;
if ( ! V_181 ) {
V_78 = - V_54 ;
goto V_65;
}
V_78 = F_88 ( & V_8 . V_32 , V_8 . V_13 , V_181 , V_182 ) ;
if ( V_78 ) {
F_7 ( & V_8 . V_13 -> V_14 , L_53 ) ;
goto V_183;
}
V_8 . V_91 = V_181 ;
V_8 . V_117 = V_182 ;
V_151 -> V_153 = & V_8 ;
return 0 ;
V_183:
F_120 ( V_181 ) ;
V_65:
F_69 ( & V_8 . V_9 ) ;
V_8 . V_10 = 0 ;
F_70 ( & V_8 . V_9 ) ;
V_63:
return V_78 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_4 * V_184 , * V_22 ;
if ( ! F_17 ( V_5 ) ) {
F_122 (cursor, next, head) {
V_7 = F_12 ( V_184 , struct V_6 , V_16 ) ;
F_13 ( & V_7 -> V_16 ) ;
F_14 ( V_7 ) ;
}
}
}
static int F_123 ( struct V_180 * V_157 , struct V_151 * V_151 )
{
struct V_146 * V_147 = V_151 -> V_153 ;
F_98 ( V_147 -> V_32 ) ;
F_69 ( & V_147 -> V_9 ) ;
V_147 -> V_32 = NULL ;
F_120 ( V_147 -> V_91 ) ;
F_121 ( & V_147 -> V_23 ) ;
F_121 ( & V_147 -> V_25 ) ;
V_147 -> V_10 = 0 ;
F_70 ( & V_147 -> V_9 ) ;
return 0 ;
}
static int F_124 ( struct V_14 * V_185 )
{
int V_133 = 0 ;
struct V_132 * V_13 = F_125 ( V_185 ) ;
F_18 ( V_185 , L_54 ) ;
F_91 ( & V_8 . V_17 ) ;
F_90 ( & V_8 . V_9 ) ;
V_8 . V_10 = 0 ;
V_8 . V_13 = V_13 ;
V_8 . V_32 = NULL ;
F_31 ( & V_8 . V_23 ) ;
F_31 ( & V_8 . V_25 ) ;
V_8 . V_53 = F_126 ( V_13 ,
L_55 ) ;
if ( V_8 . V_53 < 0 ) {
V_133 = V_8 . V_53 ;
F_7 ( V_185 , L_56 , V_133 ) ;
return V_133 ;
}
V_8 . V_64 = F_126 ( V_13 ,
L_57 ) ;
if ( V_8 . V_64 < 0 ) {
V_133 = V_8 . V_64 ;
F_7 ( V_185 , L_58 , V_133 ) ;
return V_133 ;
}
V_133 = F_127 ( & V_186 ) ;
if ( V_133 )
F_7 ( V_185 , L_59 , V_133 ) ;
return V_133 ;
}
static int F_128 ( struct V_14 * V_185 )
{
struct V_31 * V_32 ;
F_18 ( V_185 , L_60 ) ;
F_129 ( & V_186 ) ;
F_69 ( & V_8 . V_9 ) ;
V_32 = V_8 . V_32 ;
V_8 . V_32 = NULL ;
F_70 ( & V_8 . V_9 ) ;
if ( V_32 )
F_98 ( V_32 ) ;
return 0 ;
}
static int T_7 F_130 ( void )
{
F_131 ( L_61 ) ;
return F_132 ( & V_187 ) ;
}
static void T_8 F_133 ( void )
{
F_134 ( & V_187 ) ;
F_131 ( L_62 ) ;
}
