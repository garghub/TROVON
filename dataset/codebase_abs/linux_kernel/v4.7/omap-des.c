static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
V_7 &= ~ V_6 ;
V_7 |= V_5 ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , int V_8 )
{
for (; V_8 -- ; V_5 ++ , V_3 += 4 )
F_3 ( V_2 , V_3 , * V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_8 ( V_2 -> V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_2 -> V_10 ) ;
F_10 ( V_2 -> V_10 , L_1 , V_11 , V_9 ) ;
return V_9 ;
}
if ( ! ( V_2 -> V_12 & V_13 ) ) {
V_2 -> V_12 |= V_13 ;
V_2 -> V_9 = 0 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned int V_14 ;
int V_15 , V_9 ;
T_1 V_7 = 0 , V_6 = 0 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_14 = V_2 -> V_16 -> V_17 / sizeof( T_1 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
F_3 ( V_2 , F_12 ( V_2 , V_15 ) ,
F_13 ( V_2 -> V_16 -> V_18 [ V_15 ] ) ) ;
}
if ( ( V_2 -> V_12 & V_19 ) && V_2 -> V_20 -> V_21 )
F_6 ( V_2 , F_14 ( V_2 , 0 ) , V_2 -> V_20 -> V_21 , 2 ) ;
if ( V_2 -> V_12 & V_19 )
V_7 |= V_22 ;
if ( V_2 -> V_12 & V_23 )
V_7 |= V_24 ;
if ( V_14 == 6 )
V_7 |= V_25 ;
V_6 |= V_22 | V_24 | V_25 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_26 )
{
T_1 V_6 , V_7 ;
F_3 ( V_2 , F_17 ( 0 ) , V_26 ) ;
V_7 = V_2 -> V_27 -> V_28 ;
if ( V_2 -> V_29 != NULL )
V_7 |= V_2 -> V_27 -> V_30 ;
if ( V_2 -> V_31 != NULL )
V_7 |= V_2 -> V_27 -> V_32 ;
V_6 = V_2 -> V_27 -> V_30 | V_2 -> V_27 -> V_32 |
V_2 -> V_27 -> V_28 ;
F_5 ( V_2 , F_18 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_27 -> V_30 | V_2 -> V_27 -> V_32 |
V_2 -> V_27 -> V_28 ;
F_5 ( V_2 , F_18 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_20 ( struct V_33 * V_16 )
{
struct V_1 * V_2 = NULL , * V_34 ;
F_21 ( & V_35 ) ;
if ( ! V_16 -> V_2 ) {
F_22 (tmp, &dev_list, list) {
V_2 = V_34 ;
break;
}
V_16 -> V_2 = V_2 ;
} else {
V_2 = V_16 -> V_2 ;
}
F_23 ( & V_35 ) ;
return V_2 ;
}
static void F_24 ( void * V_36 )
{
struct V_1 * V_2 = V_36 ;
F_25 ( & V_2 -> V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_9 ;
V_2 -> V_29 = NULL ;
V_2 -> V_31 = NULL ;
V_2 -> V_31 = F_27 ( V_2 -> V_10 , L_2 ) ;
if ( F_28 ( V_2 -> V_31 ) ) {
F_10 ( V_2 -> V_10 , L_3 ) ;
return F_29 ( V_2 -> V_31 ) ;
}
V_2 -> V_29 = F_27 ( V_2 -> V_10 , L_4 ) ;
if ( F_28 ( V_2 -> V_29 ) ) {
F_10 ( V_2 -> V_10 , L_5 ) ;
V_9 = F_29 ( V_2 -> V_29 ) ;
goto V_38;
}
return 0 ;
V_38:
F_30 ( V_2 -> V_31 ) ;
return V_9 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 )
return;
F_30 ( V_2 -> V_29 ) ;
F_30 ( V_2 -> V_31 ) ;
}
static void F_32 ( void * V_40 , struct V_41 * V_42 ,
unsigned int V_43 , unsigned int V_44 , int V_45 )
{
struct V_46 V_47 ;
if ( ! V_44 )
return;
F_33 ( & V_47 , V_42 ) ;
F_34 ( & V_47 , V_43 ) ;
F_35 ( V_40 , & V_47 , V_44 , V_45 ) ;
F_36 ( & V_47 , V_45 , 0 ) ;
}
static int F_37 ( struct V_48 * V_49 ,
struct V_41 * V_50 , struct V_41 * V_51 ,
int V_52 , int V_53 )
{
struct V_33 * V_16 = F_38 ( V_49 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_54 * V_55 , * V_56 ;
struct V_57 V_58 ;
int V_59 ;
if ( V_2 -> V_39 ) {
F_33 ( & V_2 -> V_60 , V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_61 , V_2 -> V_51 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_40 ( V_2 -> V_10 , V_2 -> V_50 , V_52 , V_62 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_63 = V_2 -> V_64 + F_41 ( V_2 , 0 ) ;
V_58 . V_65 = V_2 -> V_64 + F_41 ( V_2 , 0 ) ;
V_58 . V_66 = V_67 ;
V_58 . V_68 = V_67 ;
V_58 . V_69 = V_70 ;
V_58 . V_71 = V_70 ;
V_59 = F_42 ( V_2 -> V_31 , & V_58 ) ;
if ( V_59 ) {
F_10 ( V_2 -> V_10 , L_6 ,
V_59 ) ;
return V_59 ;
}
V_55 = F_43 ( V_2 -> V_31 , V_50 , V_52 ,
V_72 ,
V_73 | V_74 ) ;
if ( ! V_55 ) {
F_10 ( V_2 -> V_10 , L_7 ) ;
return - V_75 ;
}
V_55 -> V_76 = V_2 ;
V_59 = F_42 ( V_2 -> V_29 , & V_58 ) ;
if ( V_59 ) {
F_10 ( V_2 -> V_10 , L_8 ,
V_59 ) ;
return V_59 ;
}
V_56 = F_43 ( V_2 -> V_29 , V_51 , V_53 ,
V_77 ,
V_73 | V_74 ) ;
if ( ! V_56 ) {
F_10 ( V_2 -> V_10 , L_9 ) ;
return - V_75 ;
}
V_56 -> V_78 = F_24 ;
V_56 -> V_76 = V_2 ;
F_44 ( V_55 ) ;
F_44 ( V_56 ) ;
F_45 ( V_2 -> V_31 ) ;
F_45 ( V_2 -> V_29 ) ;
V_2 -> V_27 -> V_79 ( V_2 , V_2 -> V_80 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = F_47 (
F_48 ( V_2 -> V_20 ) ) ;
int V_9 ;
F_49 ( L_10 , V_2 -> V_80 ) ;
if ( ! V_2 -> V_39 ) {
V_9 = F_50 ( V_2 -> V_10 , V_2 -> V_50 , V_2 -> V_52 ,
V_62 ) ;
if ( ! V_9 ) {
F_10 ( V_2 -> V_10 , L_11 ) ;
return - V_75 ;
}
V_9 = F_50 ( V_2 -> V_10 , V_2 -> V_51 , V_2 -> V_53 ,
V_81 ) ;
if ( ! V_9 ) {
F_10 ( V_2 -> V_10 , L_11 ) ;
return - V_75 ;
}
}
V_9 = F_37 ( V_49 , V_2 -> V_50 , V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_53 ) ;
if ( V_9 && ! V_2 -> V_39 ) {
F_51 ( V_2 -> V_10 , V_2 -> V_50 , V_2 -> V_52 , V_62 ) ;
F_51 ( V_2 -> V_10 , V_2 -> V_51 , V_2 -> V_53 ,
V_81 ) ;
}
return V_9 ;
}
static void F_52 ( struct V_1 * V_2 , int V_9 )
{
struct V_82 * V_20 = V_2 -> V_20 ;
F_49 ( L_12 , V_9 ) ;
F_53 ( V_2 -> V_10 ) ;
F_54 ( V_2 -> V_83 , V_20 , V_9 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_49 ( L_10 , V_2 -> V_80 ) ;
F_19 ( V_2 ) ;
F_56 ( V_2 -> V_31 ) ;
F_56 ( V_2 -> V_29 ) ;
return 0 ;
}
static int F_57 ( struct V_41 * V_42 )
{
while ( V_42 ) {
if ( ! F_58 ( V_42 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_58 ( V_42 -> V_26 , V_84 ) )
return - 1 ;
V_42 = F_59 ( V_42 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
void * V_85 , * V_86 ;
int V_87 ;
V_87 = V_2 -> V_80 >> V_88 ;
if ( V_2 -> V_80 & ( V_89 - 1 ) )
V_87 ++ ;
F_61 ( ! V_87 ) ;
V_85 = ( void * ) F_62 ( V_90 , V_87 ) ;
V_86 = ( void * ) F_62 ( V_90 , V_87 ) ;
if ( ! V_85 || ! V_86 ) {
F_63 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_91 = V_2 -> V_51 ;
F_32 ( V_85 , V_2 -> V_50 , 0 , V_2 -> V_80 , 0 ) ;
F_64 ( & V_2 -> V_92 , 1 ) ;
F_65 ( & V_2 -> V_92 , V_85 , V_2 -> V_80 ) ;
V_2 -> V_50 = & V_2 -> V_92 ;
F_64 ( & V_2 -> V_93 , 1 ) ;
F_65 ( & V_2 -> V_93 , V_86 , V_2 -> V_80 ) ;
V_2 -> V_51 = & V_2 -> V_93 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_82 * V_20 )
{
if ( V_20 )
return F_67 ( V_2 -> V_83 , V_20 ) ;
return 0 ;
}
static int F_68 ( struct V_94 * V_83 ,
struct V_82 * V_20 )
{
struct V_33 * V_16 = F_69 (
F_48 ( V_20 ) ) ;
struct V_1 * V_2 = F_20 ( V_16 ) ;
struct V_95 * V_96 ;
if ( ! V_2 )
return - V_97 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_80 = V_20 -> V_44 ;
V_2 -> V_98 = V_20 -> V_44 ;
V_2 -> V_50 = V_20 -> V_99 ;
V_2 -> V_51 = V_20 -> V_100 ;
if ( F_57 ( V_2 -> V_50 ) ||
F_57 ( V_2 -> V_51 ) ) {
if ( F_60 ( V_2 ) )
F_63 ( L_14 ) ;
V_2 -> V_101 = 1 ;
} else {
V_2 -> V_101 = 0 ;
}
V_2 -> V_52 = F_70 ( V_2 -> V_50 , V_2 -> V_80 ) ;
V_2 -> V_53 = F_70 ( V_2 -> V_51 , V_2 -> V_80 ) ;
F_61 ( V_2 -> V_52 < 0 || V_2 -> V_53 < 0 ) ;
V_96 = F_71 ( V_20 ) ;
V_16 = F_69 ( F_48 ( V_20 ) ) ;
V_96 -> V_102 &= V_103 ;
V_2 -> V_12 = ( V_2 -> V_12 & ~ V_103 ) | V_96 -> V_102 ;
V_2 -> V_16 = V_16 ;
V_16 -> V_2 = V_2 ;
return F_11 ( V_2 ) ;
}
static int F_72 ( struct V_94 * V_83 ,
struct V_82 * V_20 )
{
struct V_33 * V_16 = F_69 (
F_48 ( V_20 ) ) ;
struct V_1 * V_2 = F_20 ( V_16 ) ;
if ( ! V_2 )
return - V_97 ;
return F_46 ( V_2 ) ;
}
static void F_73 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
void * V_85 , * V_86 ;
int V_87 ;
F_49 ( L_15 ) ;
if ( ! V_2 -> V_39 ) {
F_40 ( V_2 -> V_10 , V_2 -> V_51 , V_2 -> V_53 ,
V_81 ) ;
F_51 ( V_2 -> V_10 , V_2 -> V_50 , V_2 -> V_52 , V_62 ) ;
F_51 ( V_2 -> V_10 , V_2 -> V_51 , V_2 -> V_53 ,
V_81 ) ;
F_55 ( V_2 ) ;
}
if ( V_2 -> V_101 ) {
V_85 = F_74 ( & V_2 -> V_92 ) ;
V_86 = F_74 ( & V_2 -> V_93 ) ;
F_32 ( V_86 , V_2 -> V_91 , 0 , V_2 -> V_98 , 1 ) ;
V_87 = F_75 ( V_2 -> V_98 ) ;
F_76 ( ( unsigned long ) V_85 , V_87 ) ;
F_76 ( ( unsigned long ) V_86 , V_87 ) ;
}
F_52 ( V_2 , 0 ) ;
F_49 ( L_16 ) ;
}
static int F_77 ( struct V_82 * V_20 , unsigned long V_102 )
{
struct V_33 * V_16 = F_69 (
F_48 ( V_20 ) ) ;
struct V_95 * V_96 = F_71 ( V_20 ) ;
struct V_1 * V_2 ;
F_49 ( L_17 , V_20 -> V_44 ,
! ! ( V_102 & V_23 ) ,
! ! ( V_102 & V_19 ) ) ;
if ( ! F_58 ( V_20 -> V_44 , V_84 ) ) {
F_63 ( L_18 ) ;
return - V_75 ;
}
V_2 = F_20 ( V_16 ) ;
if ( ! V_2 )
return - V_97 ;
V_96 -> V_102 = V_102 ;
return F_66 ( V_2 , V_20 ) ;
}
static int F_78 ( struct V_104 * V_49 , const T_2 * V_18 ,
unsigned int V_17 )
{
struct V_33 * V_16 = F_69 ( V_49 ) ;
if ( V_17 != V_105 && V_17 != ( 3 * V_105 ) )
return - V_75 ;
F_49 ( L_19 , V_17 ) ;
memcpy ( V_16 -> V_18 , V_18 , V_17 ) ;
V_16 -> V_17 = V_17 ;
return 0 ;
}
static int F_79 ( struct V_82 * V_20 )
{
return F_77 ( V_20 , V_23 ) ;
}
static int F_80 ( struct V_82 * V_20 )
{
return F_77 ( V_20 , 0 ) ;
}
static int F_81 ( struct V_82 * V_20 )
{
return F_77 ( V_20 , V_23 | V_19 ) ;
}
static int F_82 ( struct V_82 * V_20 )
{
return F_77 ( V_20 , V_19 ) ;
}
static int F_83 ( struct V_48 * V_49 )
{
F_49 ( L_20 ) ;
V_49 -> V_106 . V_107 = sizeof( struct V_95 ) ;
return 0 ;
}
static void F_84 ( struct V_48 * V_49 )
{
F_49 ( L_20 ) ;
}
static T_3 F_85 ( int V_108 , void * V_109 )
{
struct V_1 * V_2 = V_109 ;
T_1 V_110 , V_15 ;
T_1 * V_99 , * V_100 ;
V_110 = F_1 ( V_2 , F_86 ( V_2 ) ) ;
if ( V_110 & V_111 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_61 ( ! V_2 -> V_50 ) ;
F_61 ( F_87 ( V_112 ) > V_2 -> V_50 -> V_26 ) ;
V_99 = F_74 ( V_2 -> V_50 ) + F_87 ( V_112 ) ;
for ( V_15 = 0 ; V_15 < V_113 ; V_15 ++ ) {
F_3 ( V_2 , F_41 ( V_2 , V_15 ) , * V_99 ) ;
F_34 ( & V_2 -> V_60 , 4 ) ;
if ( V_2 -> V_50 -> V_26 == F_87 ( V_112 ) ) {
V_2 -> V_50 = F_59 ( V_2 -> V_50 ) ;
if ( V_2 -> V_50 ) {
F_33 ( & V_2 -> V_60 ,
V_2 -> V_50 ) ;
V_99 = F_74 ( V_2 -> V_50 ) +
F_87 ( V_112 ) ;
}
} else {
V_99 ++ ;
}
}
V_110 &= ~ V_111 ;
F_3 ( V_2 , F_86 ( V_2 ) , V_110 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x4 ) ;
} else if ( V_110 & V_114 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_61 ( ! V_2 -> V_51 ) ;
F_61 ( F_87 ( V_45 ) > V_2 -> V_51 -> V_26 ) ;
V_100 = F_74 ( V_2 -> V_51 ) + F_87 ( V_45 ) ;
for ( V_15 = 0 ; V_15 < V_113 ; V_15 ++ ) {
* V_100 = F_1 ( V_2 , F_41 ( V_2 , V_15 ) ) ;
F_34 ( & V_2 -> V_61 , 4 ) ;
if ( V_2 -> V_51 -> V_26 == F_87 ( V_45 ) ) {
V_2 -> V_51 = F_59 ( V_2 -> V_51 ) ;
if ( V_2 -> V_51 ) {
F_33 ( & V_2 -> V_61 ,
V_2 -> V_51 ) ;
V_100 = F_74 ( V_2 -> V_51 ) +
F_87 ( V_45 ) ;
}
} else {
V_100 ++ ;
}
}
F_61 ( V_2 -> V_80 < V_84 ) ;
V_2 -> V_80 -= V_84 ;
V_110 &= ~ V_114 ;
F_3 ( V_2 , F_86 ( V_2 ) , V_110 ) ;
if ( ! V_2 -> V_80 )
F_25 ( & V_2 -> V_37 ) ;
else
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
}
return V_115 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
const struct V_118 * V_119 ;
V_119 = F_89 ( F_90 ( V_120 ) , & V_117 -> V_10 ) ;
if ( ! V_119 ) {
F_10 ( & V_117 -> V_10 , L_21 ) ;
return - V_75 ;
}
V_2 -> V_27 = V_119 -> V_36 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_121 * V_10 )
{
return - V_75 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
V_2 -> V_27 = V_117 -> V_10 . V_122 ;
return 0 ;
}
static int F_92 ( struct V_116 * V_117 )
{
struct V_121 * V_10 = & V_117 -> V_10 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
int V_9 = - V_127 , V_15 , V_128 , V_108 = - 1 ;
T_1 V_129 ;
V_2 = F_93 ( V_10 , sizeof( struct V_1 ) , V_130 ) ;
if ( V_2 == NULL ) {
F_10 ( V_10 , L_22 ) ;
goto V_131;
}
V_2 -> V_10 = V_10 ;
F_94 ( V_117 , V_2 ) ;
V_126 = F_95 ( V_117 , V_132 , 0 ) ;
if ( ! V_126 ) {
F_10 ( V_10 , L_23 ) ;
goto V_133;
}
V_9 = ( V_10 -> V_134 ) ? F_88 ( V_2 , V_117 ) :
F_91 ( V_2 , V_117 ) ;
if ( V_9 )
goto V_133;
V_2 -> V_4 = F_96 ( V_10 , V_126 ) ;
if ( F_28 ( V_2 -> V_4 ) ) {
V_9 = F_29 ( V_2 -> V_4 ) ;
goto V_133;
}
V_2 -> V_64 = V_126 -> V_43 ;
F_97 ( V_10 ) ;
F_98 ( V_10 ) ;
V_9 = F_8 ( V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_10 ) ;
F_10 ( V_2 -> V_10 , L_1 , V_11 , V_9 ) ;
goto V_135;
}
F_19 ( V_2 ) ;
V_129 = F_1 ( V_2 , F_99 ( V_2 ) ) ;
F_100 ( V_10 ) ;
F_101 ( V_10 , L_24 ,
( V_129 & V_2 -> V_27 -> V_136 ) >> V_2 -> V_27 -> V_137 ,
( V_129 & V_2 -> V_27 -> V_138 ) >> V_2 -> V_27 -> V_139 ) ;
F_102 ( & V_2 -> V_37 , F_73 , ( unsigned long ) V_2 ) ;
V_9 = F_26 ( V_2 ) ;
if ( V_9 == - V_140 ) {
goto V_141;
} else if ( V_9 && F_86 ( V_2 ) && F_39 ( V_2 ) ) {
V_2 -> V_39 = 1 ;
V_108 = F_103 ( V_117 , 0 ) ;
if ( V_108 < 0 ) {
F_10 ( V_10 , L_25 ) ;
goto V_141;
}
V_9 = F_104 ( V_10 , V_108 , F_85 , 0 ,
F_105 ( V_10 ) , V_2 ) ;
if ( V_9 ) {
F_10 ( V_10 , L_26 ) ;
goto V_141;
}
}
F_106 ( & V_2 -> V_142 ) ;
F_107 ( & V_35 ) ;
F_108 ( & V_2 -> V_142 , & V_143 ) ;
F_109 ( & V_35 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_27 -> V_144 ; V_15 ++ ) {
for ( V_128 = 0 ; V_128 < V_2 -> V_27 -> V_145 [ V_15 ] . V_146 ; V_128 ++ ) {
V_124 = & V_2 -> V_27 -> V_145 [ V_15 ] . V_147 [ V_128 ] ;
F_49 ( L_27 , V_124 -> V_148 ) ;
F_106 ( & V_124 -> V_149 ) ;
V_9 = F_110 ( V_124 ) ;
if ( V_9 )
goto V_150;
V_2 -> V_27 -> V_145 [ V_15 ] . V_151 ++ ;
}
}
V_2 -> V_83 = F_111 ( V_10 , 1 ) ;
if ( ! V_2 -> V_83 )
goto V_150;
V_2 -> V_83 -> V_152 = F_68 ;
V_2 -> V_83 -> V_153 = F_72 ;
V_9 = F_112 ( V_2 -> V_83 ) ;
if ( V_9 )
goto V_154;
return 0 ;
V_154:
F_113 ( V_2 -> V_83 ) ;
V_150:
for ( V_15 = V_2 -> V_27 -> V_144 - 1 ; V_15 >= 0 ; V_15 -- )
for ( V_128 = V_2 -> V_27 -> V_145 [ V_15 ] . V_151 - 1 ; V_128 >= 0 ; V_128 -- )
F_114 (
& V_2 -> V_27 -> V_145 [ V_15 ] . V_147 [ V_128 ] ) ;
F_31 ( V_2 ) ;
V_141:
F_115 ( & V_2 -> V_37 ) ;
V_135:
F_116 ( V_10 ) ;
V_133:
V_2 = NULL ;
V_131:
F_10 ( V_10 , L_28 ) ;
return V_9 ;
}
static int F_117 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_118 ( V_117 ) ;
int V_15 , V_128 ;
if ( ! V_2 )
return - V_97 ;
F_107 ( & V_35 ) ;
F_119 ( & V_2 -> V_142 ) ;
F_109 ( & V_35 ) ;
for ( V_15 = V_2 -> V_27 -> V_144 - 1 ; V_15 >= 0 ; V_15 -- )
for ( V_128 = V_2 -> V_27 -> V_145 [ V_15 ] . V_151 - 1 ; V_128 >= 0 ; V_128 -- )
F_114 (
& V_2 -> V_27 -> V_145 [ V_15 ] . V_147 [ V_128 ] ) ;
F_115 ( & V_2 -> V_37 ) ;
F_31 ( V_2 ) ;
F_116 ( V_2 -> V_10 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_120 ( struct V_121 * V_10 )
{
F_100 ( V_10 ) ;
return 0 ;
}
static int F_121 ( struct V_121 * V_10 )
{
int V_9 ;
V_9 = F_8 ( V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 , L_1 , V_11 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
