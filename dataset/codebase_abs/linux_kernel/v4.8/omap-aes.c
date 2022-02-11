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
if ( ! ( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_9 |= V_10 ;
V_2 -> V_11 = 0 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_13 , V_11 ;
T_1 V_7 ;
V_11 = F_7 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_12 = V_2 -> V_14 -> V_15 / sizeof( T_1 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_3 ( V_2 , F_9 ( V_2 , V_13 ) ,
F_10 ( V_2 -> V_14 -> V_16 [ V_13 ] ) ) ;
}
if ( ( V_2 -> V_9 & ( V_17 | V_18 ) ) && V_2 -> V_19 -> V_20 )
F_6 ( V_2 , F_11 ( V_2 , 0 ) , V_2 -> V_19 -> V_20 , 4 ) ;
V_7 = F_12 ( ( ( V_2 -> V_14 -> V_15 >> 3 ) - 1 ) , 4 , 3 ) ;
if ( V_2 -> V_9 & V_17 )
V_7 |= V_21 ;
if ( V_2 -> V_9 & V_18 )
V_7 |= V_22 | V_23 ;
if ( V_2 -> V_9 & V_24 )
V_7 |= V_25 ;
F_5 ( V_2 , F_13 ( V_2 ) , V_7 , V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_27 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_28 -> V_29 ;
if ( V_2 -> V_30 != NULL )
V_7 |= V_2 -> V_28 -> V_31 ;
if ( V_2 -> V_32 != NULL )
V_7 |= V_2 -> V_28 -> V_33 ;
V_6 = V_2 -> V_28 -> V_31 | V_2 -> V_28 -> V_33 |
V_2 -> V_28 -> V_29 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_27 )
{
F_3 ( V_2 , F_17 ( 0 ) , V_27 ) ;
F_3 ( V_2 , F_17 ( 1 ) , 0 ) ;
F_14 ( V_2 , V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_28 -> V_31 | V_2 -> V_28 -> V_33 |
V_2 -> V_28 -> V_29 ;
F_5 ( V_2 , F_15 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_19 ( struct V_34 * V_14 )
{
struct V_1 * V_2 = NULL , * V_35 ;
F_20 ( & V_36 ) ;
if ( ! V_14 -> V_2 ) {
F_21 (tmp, &dev_list, list) {
V_2 = V_35 ;
break;
}
V_14 -> V_2 = V_2 ;
} else {
V_2 = V_14 -> V_2 ;
}
F_22 ( & V_36 ) ;
return V_2 ;
}
static void F_23 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
F_24 ( & V_2 -> V_38 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_11 ;
V_2 -> V_30 = NULL ;
V_2 -> V_32 = NULL ;
V_2 -> V_32 = F_26 ( V_2 -> V_39 , L_1 ) ;
if ( F_27 ( V_2 -> V_32 ) ) {
F_28 ( V_2 -> V_39 , L_2 ) ;
return F_29 ( V_2 -> V_32 ) ;
}
V_2 -> V_30 = F_26 ( V_2 -> V_39 , L_3 ) ;
if ( F_27 ( V_2 -> V_30 ) ) {
F_28 ( V_2 -> V_39 , L_4 ) ;
V_11 = F_29 ( V_2 -> V_30 ) ;
goto V_40;
}
return 0 ;
V_40:
F_30 ( V_2 -> V_32 ) ;
return V_11 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
return;
F_30 ( V_2 -> V_30 ) ;
F_30 ( V_2 -> V_32 ) ;
}
static void F_32 ( void * V_42 , struct V_43 * V_44 ,
unsigned int V_45 , unsigned int V_46 , int V_47 )
{
struct V_48 V_49 ;
if ( ! V_46 )
return;
F_33 ( & V_49 , V_44 ) ;
F_34 ( & V_49 , V_45 ) ;
F_35 ( V_42 , & V_49 , V_46 , V_47 ) ;
F_36 ( & V_49 , V_47 , 0 ) ;
}
static int F_37 ( struct V_50 * V_51 ,
struct V_43 * V_52 , struct V_43 * V_53 ,
int V_54 , int V_55 )
{
struct V_34 * V_14 = F_38 ( V_51 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_56 * V_57 , * V_58 ;
struct V_59 V_60 ;
int V_61 ;
if ( V_2 -> V_41 ) {
F_33 ( & V_2 -> V_62 , V_2 -> V_52 ) ;
F_33 ( & V_2 -> V_63 , V_2 -> V_53 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_40 ( V_2 -> V_39 , V_2 -> V_52 , V_54 , V_64 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_2 -> V_66 + F_41 ( V_2 , 0 ) ;
V_60 . V_67 = V_2 -> V_66 + F_41 ( V_2 , 0 ) ;
V_60 . V_68 = V_69 ;
V_60 . V_70 = V_69 ;
V_60 . V_71 = V_72 ;
V_60 . V_73 = V_72 ;
V_61 = F_42 ( V_2 -> V_32 , & V_60 ) ;
if ( V_61 ) {
F_28 ( V_2 -> V_39 , L_5 ,
V_61 ) ;
return V_61 ;
}
V_57 = F_43 ( V_2 -> V_32 , V_52 , V_54 ,
V_74 ,
V_75 | V_76 ) ;
if ( ! V_57 ) {
F_28 ( V_2 -> V_39 , L_6 ) ;
return - V_77 ;
}
V_57 -> V_78 = V_2 ;
V_61 = F_42 ( V_2 -> V_30 , & V_60 ) ;
if ( V_61 ) {
F_28 ( V_2 -> V_39 , L_7 ,
V_61 ) ;
return V_61 ;
}
V_58 = F_43 ( V_2 -> V_30 , V_53 , V_55 ,
V_79 ,
V_75 | V_76 ) ;
if ( ! V_58 ) {
F_28 ( V_2 -> V_39 , L_8 ) ;
return - V_77 ;
}
V_58 -> V_80 = F_23 ;
V_58 -> V_78 = V_2 ;
F_44 ( V_57 ) ;
F_44 ( V_58 ) ;
F_45 ( V_2 -> V_32 ) ;
F_45 ( V_2 -> V_30 ) ;
V_2 -> V_28 -> V_81 ( V_2 , V_2 -> V_82 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_47 (
F_48 ( V_2 -> V_19 ) ) ;
int V_11 ;
F_49 ( L_9 , V_2 -> V_82 ) ;
if ( ! V_2 -> V_41 ) {
V_11 = F_50 ( V_2 -> V_39 , V_2 -> V_52 , V_2 -> V_54 ,
V_64 ) ;
if ( ! V_11 ) {
F_28 ( V_2 -> V_39 , L_10 ) ;
return - V_77 ;
}
V_11 = F_50 ( V_2 -> V_39 , V_2 -> V_53 , V_2 -> V_55 ,
V_83 ) ;
if ( ! V_11 ) {
F_28 ( V_2 -> V_39 , L_10 ) ;
return - V_77 ;
}
}
V_11 = F_37 ( V_51 , V_2 -> V_52 , V_2 -> V_53 , V_2 -> V_54 ,
V_2 -> V_55 ) ;
if ( V_11 && ! V_2 -> V_41 ) {
F_51 ( V_2 -> V_39 , V_2 -> V_52 , V_2 -> V_54 , V_64 ) ;
F_51 ( V_2 -> V_39 , V_2 -> V_53 , V_2 -> V_55 ,
V_83 ) ;
}
return V_11 ;
}
static void F_52 ( struct V_1 * V_2 , int V_11 )
{
struct V_84 * V_19 = V_2 -> V_19 ;
F_49 ( L_11 , V_11 ) ;
F_53 ( V_2 -> V_85 , V_19 , V_11 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_49 ( L_9 , V_2 -> V_82 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_43 * V_44 , int V_82 )
{
int V_86 = 0 ;
if ( ! F_56 ( V_82 , V_87 ) )
return - V_77 ;
while ( V_44 ) {
if ( ! F_56 ( V_44 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_56 ( V_44 -> V_27 , V_87 ) )
return - 1 ;
V_86 += V_44 -> V_27 ;
V_44 = F_57 ( V_44 ) ;
}
if ( V_86 != V_82 )
return - 1 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
void * V_88 , * V_89 ;
int V_90 , V_82 ;
V_82 = F_59 ( V_2 -> V_82 , V_87 ) ;
V_90 = F_60 ( V_82 ) ;
V_88 = ( void * ) F_61 ( V_91 , V_90 ) ;
V_89 = ( void * ) F_61 ( V_91 , V_90 ) ;
if ( ! V_88 || ! V_89 ) {
F_62 ( L_12 ) ;
return - 1 ;
}
V_2 -> V_92 = V_2 -> V_53 ;
F_32 ( V_88 , V_2 -> V_52 , 0 , V_2 -> V_82 , 0 ) ;
F_63 ( & V_2 -> V_93 , 1 ) ;
F_64 ( & V_2 -> V_93 , V_88 , V_82 ) ;
V_2 -> V_52 = & V_2 -> V_93 ;
V_2 -> V_54 = 1 ;
F_63 ( & V_2 -> V_94 , 1 ) ;
F_64 ( & V_2 -> V_94 , V_89 , V_82 ) ;
V_2 -> V_53 = & V_2 -> V_94 ;
V_2 -> V_55 = 1 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_84 * V_19 )
{
if ( V_19 )
return F_66 ( V_2 -> V_85 , V_19 ) ;
return 0 ;
}
static int F_67 ( struct V_95 * V_85 ,
struct V_84 * V_19 )
{
struct V_34 * V_14 = F_68 (
F_48 ( V_19 ) ) ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
struct V_96 * V_97 ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_82 = V_19 -> V_46 ;
V_2 -> V_99 = V_19 -> V_46 ;
V_2 -> V_52 = V_19 -> V_100 ;
V_2 -> V_53 = V_19 -> V_101 ;
V_2 -> V_54 = F_69 ( V_2 -> V_52 , V_2 -> V_82 ) ;
if ( V_2 -> V_54 < 0 )
return V_2 -> V_54 ;
V_2 -> V_55 = F_69 ( V_2 -> V_53 , V_2 -> V_82 ) ;
if ( V_2 -> V_55 < 0 )
return V_2 -> V_55 ;
if ( F_55 ( V_2 -> V_52 , V_2 -> V_82 ) ||
F_55 ( V_2 -> V_53 , V_2 -> V_82 ) ) {
if ( F_58 ( V_2 ) )
F_62 ( L_13 ) ;
V_2 -> V_102 = 1 ;
} else {
V_2 -> V_102 = 0 ;
}
V_97 = F_70 ( V_19 ) ;
V_14 = F_68 ( F_48 ( V_19 ) ) ;
V_97 -> V_103 &= V_104 ;
V_2 -> V_9 = ( V_2 -> V_9 & ~ V_104 ) | V_97 -> V_103 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
return F_8 ( V_2 ) ;
}
static int F_71 ( struct V_95 * V_85 ,
struct V_84 * V_19 )
{
struct V_34 * V_14 = F_68 (
F_48 ( V_19 ) ) ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_98 ;
return F_46 ( V_2 ) ;
}
static void F_72 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
void * V_88 , * V_89 ;
int V_90 , V_86 ;
F_49 ( L_14 ) ;
if ( ! V_2 -> V_41 ) {
F_40 ( V_2 -> V_39 , V_2 -> V_53 , V_2 -> V_55 ,
V_83 ) ;
F_51 ( V_2 -> V_39 , V_2 -> V_52 , V_2 -> V_54 , V_64 ) ;
F_51 ( V_2 -> V_39 , V_2 -> V_53 , V_2 -> V_55 ,
V_83 ) ;
F_54 ( V_2 ) ;
}
if ( V_2 -> V_102 ) {
V_88 = F_73 ( & V_2 -> V_93 ) ;
V_89 = F_73 ( & V_2 -> V_94 ) ;
F_32 ( V_89 , V_2 -> V_92 , 0 , V_2 -> V_99 , 1 ) ;
V_86 = F_59 ( V_2 -> V_99 , V_87 ) ;
V_90 = F_60 ( V_86 ) ;
F_74 ( ( unsigned long ) V_88 , V_90 ) ;
F_74 ( ( unsigned long ) V_89 , V_90 ) ;
}
F_52 ( V_2 , 0 ) ;
F_49 ( L_15 ) ;
}
static int F_75 ( struct V_84 * V_19 , unsigned long V_103 )
{
struct V_34 * V_14 = F_68 (
F_48 ( V_19 ) ) ;
struct V_96 * V_97 = F_70 ( V_19 ) ;
struct V_1 * V_2 ;
F_49 ( L_16 , V_19 -> V_46 ,
! ! ( V_103 & V_24 ) ,
! ! ( V_103 & V_17 ) ) ;
V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_98 ;
V_97 -> V_103 = V_103 ;
return F_65 ( V_2 , V_19 ) ;
}
static int F_76 ( struct V_105 * V_51 , const T_2 * V_16 ,
unsigned int V_15 )
{
struct V_34 * V_14 = F_68 ( V_51 ) ;
if ( V_15 != V_106 && V_15 != V_107 &&
V_15 != V_108 )
return - V_77 ;
F_49 ( L_17 , V_15 ) ;
memcpy ( V_14 -> V_16 , V_16 , V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static int F_77 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , V_24 ) ;
}
static int F_78 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , 0 ) ;
}
static int F_79 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , V_24 | V_17 ) ;
}
static int F_80 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , V_17 ) ;
}
static int F_81 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , V_24 | V_18 ) ;
}
static int F_82 ( struct V_84 * V_19 )
{
return F_75 ( V_19 , V_18 ) ;
}
static int F_83 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = NULL ;
int V_11 ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
V_11 = F_84 ( V_2 -> V_39 ) ;
if ( V_11 < 0 ) {
F_28 ( V_2 -> V_39 , L_18 ,
V_109 , V_11 ) ;
return V_11 ;
}
V_51 -> V_110 . V_111 = sizeof( struct V_96 ) ;
return 0 ;
}
static void F_85 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
F_86 ( V_2 -> V_39 ) ;
}
static T_3 F_87 ( int V_112 , void * V_113 )
{
struct V_1 * V_2 = V_113 ;
T_1 V_114 , V_13 ;
T_1 * V_100 , * V_101 ;
V_114 = F_1 ( V_2 , F_88 ( V_2 ) ) ;
if ( V_114 & V_115 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_89 ( ! V_2 -> V_52 ) ;
F_89 ( F_90 ( V_116 ) > V_2 -> V_52 -> V_27 ) ;
V_100 = F_73 ( V_2 -> V_52 ) + F_90 ( V_116 ) ;
for ( V_13 = 0 ; V_13 < V_117 ; V_13 ++ ) {
F_3 ( V_2 , F_41 ( V_2 , V_13 ) , * V_100 ) ;
F_34 ( & V_2 -> V_62 , 4 ) ;
if ( V_2 -> V_52 -> V_27 == F_90 ( V_116 ) ) {
V_2 -> V_52 = F_57 ( V_2 -> V_52 ) ;
if ( V_2 -> V_52 ) {
F_33 ( & V_2 -> V_62 ,
V_2 -> V_52 ) ;
V_100 = F_73 ( V_2 -> V_52 ) +
F_90 ( V_116 ) ;
}
} else {
V_100 ++ ;
}
}
V_114 &= ~ V_115 ;
F_3 ( V_2 , F_88 ( V_2 ) , V_114 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x4 ) ;
} else if ( V_114 & V_118 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_89 ( ! V_2 -> V_53 ) ;
F_89 ( F_90 ( V_47 ) > V_2 -> V_53 -> V_27 ) ;
V_101 = F_73 ( V_2 -> V_53 ) + F_90 ( V_47 ) ;
for ( V_13 = 0 ; V_13 < V_117 ; V_13 ++ ) {
* V_101 = F_1 ( V_2 , F_41 ( V_2 , V_13 ) ) ;
F_34 ( & V_2 -> V_63 , 4 ) ;
if ( V_2 -> V_53 -> V_27 == F_90 ( V_47 ) ) {
V_2 -> V_53 = F_57 ( V_2 -> V_53 ) ;
if ( V_2 -> V_53 ) {
F_33 ( & V_2 -> V_63 ,
V_2 -> V_53 ) ;
V_101 = F_73 ( V_2 -> V_53 ) +
F_90 ( V_47 ) ;
}
} else {
V_101 ++ ;
}
}
V_2 -> V_82 -= F_91 ( V_119 , V_87 , V_2 -> V_82 ) ;
V_114 &= ~ V_118 ;
F_3 ( V_2 , F_88 ( V_2 ) , V_114 ) ;
if ( ! V_2 -> V_82 )
F_24 ( & V_2 -> V_38 ) ;
else
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
}
return V_120 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_121 * V_39 , struct V_122 * V_123 )
{
struct V_124 * V_125 = V_39 -> V_126 ;
const struct V_127 * V_128 ;
int V_11 = 0 ;
V_128 = F_93 ( F_94 ( V_129 ) , V_39 ) ;
if ( ! V_128 ) {
F_28 ( V_39 , L_19 ) ;
V_11 = - V_77 ;
goto V_11;
}
V_11 = F_95 ( V_125 , 0 , V_123 ) ;
if ( V_11 < 0 ) {
F_28 ( V_39 , L_20 ) ;
V_11 = - V_77 ;
goto V_11;
}
V_2 -> V_28 = V_128 -> V_37 ;
V_11:
return V_11 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_121 * V_39 , struct V_122 * V_123 )
{
return - V_77 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_130 * V_131 , struct V_122 * V_123 )
{
struct V_121 * V_39 = & V_131 -> V_39 ;
struct V_122 * V_132 ;
int V_11 = 0 ;
V_132 = F_97 ( V_131 , V_133 , 0 ) ;
if ( ! V_132 ) {
F_28 ( V_39 , L_21 ) ;
V_11 = - V_98 ;
goto V_11;
}
memcpy ( V_123 , V_132 , sizeof( * V_123 ) ) ;
V_2 -> V_28 = & V_134 ;
V_11:
return V_11 ;
}
static int F_98 ( struct V_130 * V_131 )
{
struct V_121 * V_39 = & V_131 -> V_39 ;
struct V_1 * V_2 ;
struct V_135 * V_136 ;
struct V_122 V_123 ;
int V_11 = - V_137 , V_13 , V_138 , V_112 = - 1 ;
T_1 V_139 ;
V_2 = F_99 ( V_39 , sizeof( struct V_1 ) , V_140 ) ;
if ( V_2 == NULL ) {
F_28 ( V_39 , L_22 ) ;
goto V_141;
}
V_2 -> V_39 = V_39 ;
F_100 ( V_131 , V_2 ) ;
V_11 = ( V_39 -> V_126 ) ? F_92 ( V_2 , V_39 , & V_123 ) :
F_96 ( V_2 , V_131 , & V_123 ) ;
if ( V_11 )
goto V_142;
V_2 -> V_4 = F_101 ( V_39 , & V_123 ) ;
if ( F_27 ( V_2 -> V_4 ) ) {
V_11 = F_29 ( V_2 -> V_4 ) ;
goto V_142;
}
V_2 -> V_66 = V_123 . V_45 ;
F_102 ( V_39 ) ;
V_11 = F_84 ( V_39 ) ;
if ( V_11 < 0 ) {
F_28 ( V_39 , L_18 ,
V_109 , V_11 ) ;
goto V_142;
}
F_18 ( V_2 ) ;
V_139 = F_1 ( V_2 , F_103 ( V_2 ) ) ;
F_86 ( V_39 ) ;
F_104 ( V_39 , L_23 ,
( V_139 & V_2 -> V_28 -> V_143 ) >> V_2 -> V_28 -> V_144 ,
( V_139 & V_2 -> V_28 -> V_145 ) >> V_2 -> V_28 -> V_146 ) ;
F_105 ( & V_2 -> V_38 , F_72 , ( unsigned long ) V_2 ) ;
V_11 = F_25 ( V_2 ) ;
if ( V_11 == - V_147 ) {
goto V_148;
} else if ( V_11 && F_88 ( V_2 ) && F_39 ( V_2 ) ) {
V_2 -> V_41 = 1 ;
V_112 = F_106 ( V_131 , 0 ) ;
if ( V_112 < 0 ) {
F_28 ( V_39 , L_24 ) ;
goto V_148;
}
V_11 = F_107 ( V_39 , V_112 , F_87 , 0 ,
F_108 ( V_39 ) , V_2 ) ;
if ( V_11 ) {
F_28 ( V_39 , L_25 ) ;
goto V_148;
}
}
F_109 ( & V_2 -> V_149 ) ;
F_110 ( & V_36 ) ;
F_111 ( & V_2 -> V_149 , & V_150 ) ;
F_112 ( & V_36 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_28 -> V_151 ; V_13 ++ ) {
if ( ! V_2 -> V_28 -> V_152 [ V_13 ] . V_153 ) {
for ( V_138 = 0 ; V_138 < V_2 -> V_28 -> V_152 [ V_13 ] . V_154 ; V_138 ++ ) {
V_136 = & V_2 -> V_28 -> V_152 [ V_13 ] . V_155 [ V_138 ] ;
F_49 ( L_26 , V_136 -> V_156 ) ;
F_109 ( & V_136 -> V_157 ) ;
V_11 = F_113 ( V_136 ) ;
if ( V_11 )
goto V_158;
V_2 -> V_28 -> V_152 [ V_13 ] . V_153 ++ ;
}
}
}
V_2 -> V_85 = F_114 ( V_39 , 1 ) ;
if ( ! V_2 -> V_85 )
goto V_158;
V_2 -> V_85 -> V_159 = F_67 ;
V_2 -> V_85 -> V_160 = F_71 ;
V_11 = F_115 ( V_2 -> V_85 ) ;
if ( V_11 )
goto V_161;
return 0 ;
V_161:
F_116 ( V_2 -> V_85 ) ;
V_158:
for ( V_13 = V_2 -> V_28 -> V_151 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_138 = V_2 -> V_28 -> V_152 [ V_13 ] . V_153 - 1 ; V_138 >= 0 ; V_138 -- )
F_117 (
& V_2 -> V_28 -> V_152 [ V_13 ] . V_155 [ V_138 ] ) ;
F_31 ( V_2 ) ;
V_148:
F_118 ( & V_2 -> V_38 ) ;
F_119 ( V_39 ) ;
V_142:
V_2 = NULL ;
V_141:
F_28 ( V_39 , L_27 ) ;
return V_11 ;
}
static int F_120 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_121 ( V_131 ) ;
int V_13 , V_138 ;
if ( ! V_2 )
return - V_98 ;
F_110 ( & V_36 ) ;
F_122 ( & V_2 -> V_149 ) ;
F_112 ( & V_36 ) ;
for ( V_13 = V_2 -> V_28 -> V_151 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_138 = V_2 -> V_28 -> V_152 [ V_13 ] . V_153 - 1 ; V_138 >= 0 ; V_138 -- )
F_117 (
& V_2 -> V_28 -> V_152 [ V_13 ] . V_155 [ V_138 ] ) ;
F_116 ( V_2 -> V_85 ) ;
F_118 ( & V_2 -> V_38 ) ;
F_31 ( V_2 ) ;
F_119 ( V_2 -> V_39 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_123 ( struct V_121 * V_39 )
{
F_86 ( V_39 ) ;
return 0 ;
}
static int F_124 ( struct V_121 * V_39 )
{
F_84 ( V_39 ) ;
return 0 ;
}
