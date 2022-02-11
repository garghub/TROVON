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
T_1 V_7 , V_6 = 0 ;
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
if ( V_2 -> V_9 & V_18 ) {
V_7 |= V_22 | V_23 ;
V_6 = V_22 | V_24 ;
}
if ( V_2 -> V_9 & V_25 )
V_7 |= V_26 ;
V_6 |= V_21 | V_26 |
V_27 ;
F_5 ( V_2 , F_13 ( V_2 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_28 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_29 -> V_30 ;
if ( V_2 -> V_31 != NULL )
V_7 |= V_2 -> V_29 -> V_32 ;
if ( V_2 -> V_33 != NULL )
V_7 |= V_2 -> V_29 -> V_34 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_28 )
{
F_3 ( V_2 , F_17 ( 0 ) , V_28 ) ;
F_3 ( V_2 , F_17 ( 1 ) , 0 ) ;
F_14 ( V_2 , V_28 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_15 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_19 ( struct V_35 * V_14 )
{
struct V_1 * V_2 = NULL , * V_36 ;
F_20 ( & V_37 ) ;
if ( ! V_14 -> V_2 ) {
F_21 (tmp, &dev_list, list) {
V_2 = V_36 ;
break;
}
V_14 -> V_2 = V_2 ;
} else {
V_2 = V_14 -> V_2 ;
}
F_22 ( & V_37 ) ;
return V_2 ;
}
static void F_23 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
F_24 ( & V_2 -> V_39 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_11 = - V_40 ;
T_2 V_6 ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
F_26 ( V_6 ) ;
F_27 ( V_41 , V_6 ) ;
V_2 -> V_33 = F_28 ( V_6 ,
V_42 ,
& V_2 -> V_43 ,
V_2 -> V_44 , L_1 ) ;
if ( ! V_2 -> V_33 ) {
F_29 ( V_2 -> V_44 , L_2 ) ;
goto V_45;
}
V_2 -> V_31 = F_28 ( V_6 ,
V_42 ,
& V_2 -> V_46 ,
V_2 -> V_44 , L_3 ) ;
if ( ! V_2 -> V_31 ) {
F_29 ( V_2 -> V_44 , L_4 ) ;
goto V_47;
}
return 0 ;
V_47:
F_30 ( V_2 -> V_33 ) ;
V_45:
if ( V_11 )
F_31 ( L_5 , V_11 ) ;
return V_11 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_31 ) ;
F_30 ( V_2 -> V_33 ) ;
}
static void F_33 ( void * V_48 , struct V_49 * V_50 ,
unsigned int V_51 , unsigned int V_52 , int V_53 )
{
struct V_54 V_55 ;
if ( ! V_52 )
return;
F_34 ( & V_55 , V_50 ) ;
F_35 ( & V_55 , V_51 ) ;
F_36 ( V_48 , & V_55 , V_52 , V_53 ) ;
F_37 ( & V_55 , V_53 , 0 ) ;
}
static int F_38 ( struct V_56 * V_57 ,
struct V_49 * V_58 , struct V_49 * V_59 ,
int V_60 , int V_61 )
{
struct V_35 * V_14 = F_39 ( V_57 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_62 * V_63 , * V_64 ;
struct V_65 V_66 ;
int V_67 ;
if ( V_2 -> V_68 ) {
F_34 ( & V_2 -> V_69 , V_2 -> V_58 ) ;
F_34 ( & V_2 -> V_70 , V_2 -> V_59 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_41 ( V_2 -> V_44 , V_2 -> V_58 , V_60 , V_71 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_72 = V_2 -> V_73 + F_42 ( V_2 , 0 ) ;
V_66 . V_74 = V_2 -> V_73 + F_42 ( V_2 , 0 ) ;
V_66 . V_75 = V_76 ;
V_66 . V_77 = V_76 ;
V_66 . V_78 = V_79 ;
V_66 . V_80 = V_79 ;
V_67 = F_43 ( V_2 -> V_33 , & V_66 ) ;
if ( V_67 ) {
F_29 ( V_2 -> V_44 , L_6 ,
V_67 ) ;
return V_67 ;
}
V_63 = F_44 ( V_2 -> V_33 , V_58 , V_60 ,
V_81 ,
V_82 | V_83 ) ;
if ( ! V_63 ) {
F_29 ( V_2 -> V_44 , L_7 ) ;
return - V_84 ;
}
V_63 -> V_85 = V_2 ;
V_67 = F_43 ( V_2 -> V_31 , & V_66 ) ;
if ( V_67 ) {
F_29 ( V_2 -> V_44 , L_8 ,
V_67 ) ;
return V_67 ;
}
V_64 = F_44 ( V_2 -> V_31 , V_59 , V_61 ,
V_86 ,
V_82 | V_83 ) ;
if ( ! V_64 ) {
F_29 ( V_2 -> V_44 , L_9 ) ;
return - V_84 ;
}
V_64 -> V_87 = F_23 ;
V_64 -> V_85 = V_2 ;
F_45 ( V_63 ) ;
F_45 ( V_64 ) ;
F_46 ( V_2 -> V_33 ) ;
F_46 ( V_2 -> V_31 ) ;
V_2 -> V_29 -> V_88 ( V_2 , V_2 -> V_89 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_48 (
F_49 ( V_2 -> V_19 ) ) ;
int V_11 ;
F_50 ( L_10 , V_2 -> V_89 ) ;
if ( ! V_2 -> V_68 ) {
V_11 = F_51 ( V_2 -> V_44 , V_2 -> V_58 , V_2 -> V_60 ,
V_71 ) ;
if ( ! V_11 ) {
F_29 ( V_2 -> V_44 , L_11 ) ;
return - V_84 ;
}
V_11 = F_51 ( V_2 -> V_44 , V_2 -> V_59 , V_2 -> V_61 ,
V_90 ) ;
if ( ! V_11 ) {
F_29 ( V_2 -> V_44 , L_11 ) ;
return - V_84 ;
}
}
V_11 = F_38 ( V_57 , V_2 -> V_58 , V_2 -> V_59 , V_2 -> V_60 ,
V_2 -> V_61 ) ;
if ( V_11 && ! V_2 -> V_68 ) {
F_52 ( V_2 -> V_44 , V_2 -> V_58 , V_2 -> V_60 , V_71 ) ;
F_52 ( V_2 -> V_44 , V_2 -> V_59 , V_2 -> V_61 ,
V_90 ) ;
}
return V_11 ;
}
static void F_53 ( struct V_1 * V_2 , int V_11 )
{
struct V_91 * V_19 = V_2 -> V_19 ;
F_50 ( L_12 , V_11 ) ;
V_2 -> V_9 &= ~ V_92 ;
V_19 -> V_93 . V_94 ( & V_19 -> V_93 , V_11 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_50 ( L_10 , V_2 -> V_89 ) ;
F_18 ( V_2 ) ;
F_55 ( V_2 -> V_33 ) ;
F_55 ( V_2 -> V_31 ) ;
return V_11 ;
}
int F_56 ( struct V_49 * V_50 )
{
while ( V_50 ) {
if ( ! F_57 ( V_50 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_57 ( V_50 -> V_28 , V_95 ) )
return - 1 ;
V_50 = F_58 ( V_50 ) ;
}
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
void * V_96 , * V_97 ;
int V_98 ;
V_98 = F_60 ( V_2 -> V_89 ) ;
V_96 = ( void * ) F_61 ( V_99 , V_98 ) ;
V_97 = ( void * ) F_61 ( V_99 , V_98 ) ;
if ( ! V_96 || ! V_97 ) {
F_31 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_100 = V_2 -> V_59 ;
F_33 ( V_96 , V_2 -> V_58 , 0 , V_2 -> V_89 , 0 ) ;
F_62 ( & V_2 -> V_101 , 1 ) ;
F_63 ( & V_2 -> V_101 , V_96 , V_2 -> V_89 ) ;
V_2 -> V_58 = & V_2 -> V_101 ;
F_62 ( & V_2 -> V_102 , 1 ) ;
F_63 ( & V_2 -> V_102 , V_97 , V_2 -> V_89 ) ;
V_2 -> V_59 = & V_2 -> V_102 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_91 * V_19 )
{
struct V_103 * V_104 , * V_105 ;
struct V_35 * V_14 ;
struct V_106 * V_107 ;
unsigned long V_9 ;
int V_11 , V_67 = 0 ;
F_65 ( & V_2 -> V_108 , V_9 ) ;
if ( V_19 )
V_67 = F_66 ( & V_2 -> V_109 , V_19 ) ;
if ( V_2 -> V_9 & V_92 ) {
F_67 ( & V_2 -> V_108 , V_9 ) ;
return V_67 ;
}
V_105 = F_68 ( & V_2 -> V_109 ) ;
V_104 = F_69 ( & V_2 -> V_109 ) ;
if ( V_104 )
V_2 -> V_9 |= V_92 ;
F_67 ( & V_2 -> V_108 , V_9 ) ;
if ( ! V_104 )
return V_67 ;
if ( V_105 )
V_105 -> V_94 ( V_105 , - V_110 ) ;
V_19 = F_70 ( V_104 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_89 = V_19 -> V_52 ;
V_2 -> V_111 = V_19 -> V_52 ;
V_2 -> V_58 = V_19 -> V_112 ;
V_2 -> V_59 = V_19 -> V_113 ;
if ( F_56 ( V_2 -> V_58 ) ||
F_56 ( V_2 -> V_59 ) ) {
if ( F_59 ( V_2 ) )
F_31 ( L_14 ) ;
V_2 -> V_114 = 1 ;
} else {
V_2 -> V_114 = 0 ;
}
V_2 -> V_60 = F_71 ( V_2 -> V_58 , V_2 -> V_89 ) ;
V_2 -> V_61 = F_71 ( V_2 -> V_59 , V_2 -> V_89 ) ;
F_72 ( V_2 -> V_60 < 0 || V_2 -> V_61 < 0 ) ;
V_107 = F_73 ( V_19 ) ;
V_14 = F_74 ( F_49 ( V_19 ) ) ;
V_107 -> V_115 &= V_116 ;
V_2 -> V_9 = ( V_2 -> V_9 & ~ V_116 ) | V_107 -> V_115 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
V_11 = F_8 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_47 ( V_2 ) ;
if ( V_11 ) {
F_53 ( V_2 , V_11 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
return V_67 ;
}
static void F_75 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
void * V_96 , * V_97 ;
int V_98 ;
F_50 ( L_15 ) ;
if ( ! V_2 -> V_68 ) {
F_41 ( V_2 -> V_44 , V_2 -> V_59 , V_2 -> V_61 ,
V_90 ) ;
F_52 ( V_2 -> V_44 , V_2 -> V_58 , V_2 -> V_60 , V_71 ) ;
F_52 ( V_2 -> V_44 , V_2 -> V_59 , V_2 -> V_61 ,
V_90 ) ;
F_54 ( V_2 ) ;
}
if ( V_2 -> V_114 ) {
V_96 = F_76 ( & V_2 -> V_101 ) ;
V_97 = F_76 ( & V_2 -> V_102 ) ;
F_33 ( V_97 , V_2 -> V_100 , 0 , V_2 -> V_111 , 1 ) ;
V_98 = F_60 ( V_2 -> V_111 ) ;
F_77 ( ( unsigned long ) V_96 , V_98 ) ;
F_77 ( ( unsigned long ) V_97 , V_98 ) ;
}
F_53 ( V_2 , 0 ) ;
F_64 ( V_2 , NULL ) ;
F_50 ( L_16 ) ;
}
static void F_78 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_64 ( V_2 , NULL ) ;
}
static int F_79 ( struct V_91 * V_19 , unsigned long V_115 )
{
struct V_35 * V_14 = F_74 (
F_49 ( V_19 ) ) ;
struct V_106 * V_107 = F_73 ( V_19 ) ;
struct V_1 * V_2 ;
F_50 ( L_17 , V_19 -> V_52 ,
! ! ( V_115 & V_25 ) ,
! ! ( V_115 & V_17 ) ) ;
if ( ! F_57 ( V_19 -> V_52 , V_95 ) ) {
F_31 ( L_18 ) ;
return - V_84 ;
}
V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_118 ;
V_107 -> V_115 = V_115 ;
return F_64 ( V_2 , V_19 ) ;
}
static int F_80 ( struct V_119 * V_57 , const T_3 * V_16 ,
unsigned int V_15 )
{
struct V_35 * V_14 = F_74 ( V_57 ) ;
if ( V_15 != V_120 && V_15 != V_121 &&
V_15 != V_122 )
return - V_84 ;
F_50 ( L_19 , V_15 ) ;
memcpy ( V_14 -> V_16 , V_16 , V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static int F_81 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , V_25 ) ;
}
static int F_82 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , 0 ) ;
}
static int F_83 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , V_25 | V_17 ) ;
}
static int F_84 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , V_17 ) ;
}
static int F_85 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , V_25 | V_18 ) ;
}
static int F_86 ( struct V_91 * V_19 )
{
return F_79 ( V_19 , V_18 ) ;
}
static int F_87 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_37 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_37 ) ;
F_88 ( V_2 -> V_44 ) ;
V_57 -> V_123 . V_124 = sizeof( struct V_106 ) ;
return 0 ;
}
static void F_89 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_37 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_37 ) ;
F_90 ( V_2 -> V_44 ) ;
}
static T_4 F_91 ( int V_125 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
T_1 V_127 , V_13 ;
T_1 * V_112 , * V_113 ;
V_127 = F_1 ( V_2 , F_92 ( V_2 ) ) ;
if ( V_127 & V_128 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_72 ( ! V_2 -> V_58 ) ;
F_72 ( F_93 ( V_129 ) > V_2 -> V_58 -> V_28 ) ;
V_112 = F_76 ( V_2 -> V_58 ) + F_93 ( V_129 ) ;
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
F_3 ( V_2 , F_42 ( V_2 , V_13 ) , * V_112 ) ;
F_35 ( & V_2 -> V_69 , 4 ) ;
if ( V_2 -> V_58 -> V_28 == F_93 ( V_129 ) ) {
V_2 -> V_58 = F_94 ( V_2 -> V_58 ) ;
if ( V_2 -> V_58 ) {
F_34 ( & V_2 -> V_69 ,
V_2 -> V_58 ) ;
V_112 = F_76 ( V_2 -> V_58 ) +
F_93 ( V_129 ) ;
}
} else {
V_112 ++ ;
}
}
V_127 &= ~ V_128 ;
F_3 ( V_2 , F_92 ( V_2 ) , V_127 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x4 ) ;
} else if ( V_127 & V_131 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_72 ( ! V_2 -> V_59 ) ;
F_72 ( F_93 ( V_53 ) > V_2 -> V_59 -> V_28 ) ;
V_113 = F_76 ( V_2 -> V_59 ) + F_93 ( V_53 ) ;
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
* V_113 = F_1 ( V_2 , F_42 ( V_2 , V_13 ) ) ;
F_35 ( & V_2 -> V_70 , 4 ) ;
if ( V_2 -> V_59 -> V_28 == F_93 ( V_53 ) ) {
V_2 -> V_59 = F_94 ( V_2 -> V_59 ) ;
if ( V_2 -> V_59 ) {
F_34 ( & V_2 -> V_70 ,
V_2 -> V_59 ) ;
V_113 = F_76 ( V_2 -> V_59 ) +
F_93 ( V_53 ) ;
}
} else {
V_113 ++ ;
}
}
V_2 -> V_89 -= V_95 ;
F_72 ( V_2 -> V_89 < 0 ) ;
V_127 &= ~ V_131 ;
F_3 ( V_2 , F_92 ( V_2 ) , V_127 ) ;
if ( ! V_2 -> V_89 )
F_24 ( & V_2 -> V_39 ) ;
else
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
}
return V_132 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_133 * V_44 , struct V_134 * V_135 )
{
struct V_136 * V_137 = V_44 -> V_138 ;
const struct V_139 * V_140 ;
int V_11 = 0 ;
V_140 = F_96 ( F_97 ( V_141 ) , V_44 ) ;
if ( ! V_140 ) {
F_29 ( V_44 , L_20 ) ;
V_11 = - V_84 ;
goto V_11;
}
V_11 = F_98 ( V_137 , 0 , V_135 ) ;
if ( V_11 < 0 ) {
F_29 ( V_44 , L_21 ) ;
V_11 = - V_84 ;
goto V_11;
}
V_2 -> V_46 = - 1 ;
V_2 -> V_43 = - 1 ;
V_2 -> V_29 = V_140 -> V_38 ;
V_11:
return V_11 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_133 * V_44 , struct V_134 * V_135 )
{
return - V_84 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_142 * V_143 , struct V_134 * V_135 )
{
struct V_133 * V_44 = & V_143 -> V_44 ;
struct V_134 * V_144 ;
int V_11 = 0 ;
V_144 = F_100 ( V_143 , V_145 , 0 ) ;
if ( ! V_144 ) {
F_29 ( V_44 , L_22 ) ;
V_11 = - V_118 ;
goto V_11;
}
memcpy ( V_135 , V_144 , sizeof( * V_135 ) ) ;
V_144 = F_100 ( V_143 , V_146 , 0 ) ;
if ( ! V_144 ) {
F_29 ( V_44 , L_23 ) ;
V_11 = - V_118 ;
goto V_11;
}
V_2 -> V_46 = V_144 -> V_51 ;
V_144 = F_100 ( V_143 , V_146 , 1 ) ;
if ( ! V_144 ) {
F_29 ( V_44 , L_24 ) ;
V_11 = - V_118 ;
goto V_11;
}
V_2 -> V_43 = V_144 -> V_51 ;
V_2 -> V_29 = & V_147 ;
V_11:
return V_11 ;
}
static int F_101 ( struct V_142 * V_143 )
{
struct V_133 * V_44 = & V_143 -> V_44 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
struct V_134 V_135 ;
int V_11 = - V_40 , V_13 , V_150 , V_125 = - 1 ;
T_1 V_151 ;
V_2 = F_102 ( V_44 , sizeof( struct V_1 ) , V_152 ) ;
if ( V_2 == NULL ) {
F_29 ( V_44 , L_25 ) ;
goto V_153;
}
V_2 -> V_44 = V_44 ;
F_103 ( V_143 , V_2 ) ;
F_104 ( & V_2 -> V_108 ) ;
F_105 ( & V_2 -> V_109 , V_154 ) ;
V_11 = ( V_44 -> V_138 ) ? F_95 ( V_2 , V_44 , & V_135 ) :
F_99 ( V_2 , V_143 , & V_135 ) ;
if ( V_11 )
goto V_155;
V_2 -> V_4 = F_106 ( V_44 , & V_135 ) ;
if ( F_107 ( V_2 -> V_4 ) ) {
V_11 = F_108 ( V_2 -> V_4 ) ;
goto V_155;
}
V_2 -> V_73 = V_135 . V_51 ;
F_109 ( V_44 ) ;
F_88 ( V_44 ) ;
F_18 ( V_2 ) ;
V_151 = F_1 ( V_2 , F_110 ( V_2 ) ) ;
F_90 ( V_44 ) ;
F_111 ( V_44 , L_26 ,
( V_151 & V_2 -> V_29 -> V_156 ) >> V_2 -> V_29 -> V_157 ,
( V_151 & V_2 -> V_29 -> V_158 ) >> V_2 -> V_29 -> V_159 ) ;
F_112 ( & V_2 -> V_39 , F_75 , ( unsigned long ) V_2 ) ;
F_112 ( & V_2 -> V_117 , F_78 , ( unsigned long ) V_2 ) ;
V_11 = F_25 ( V_2 ) ;
if ( V_11 && F_92 ( V_2 ) && F_40 ( V_2 ) ) {
V_2 -> V_68 = 1 ;
V_125 = F_113 ( V_143 , 0 ) ;
if ( V_125 < 0 ) {
F_29 ( V_44 , L_27 ) ;
goto V_160;
}
V_11 = F_114 ( V_44 , V_125 , F_91 , 0 ,
F_115 ( V_44 ) , V_2 ) ;
if ( V_11 ) {
F_29 ( V_44 , L_28 ) ;
goto V_160;
}
}
F_116 ( & V_2 -> V_161 ) ;
F_117 ( & V_37 ) ;
F_118 ( & V_2 -> V_161 , & V_162 ) ;
F_119 ( & V_37 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_29 -> V_163 ; V_13 ++ ) {
for ( V_150 = 0 ; V_150 < V_2 -> V_29 -> V_164 [ V_13 ] . V_165 ; V_150 ++ ) {
V_149 = & V_2 -> V_29 -> V_164 [ V_13 ] . V_166 [ V_150 ] ;
F_50 ( L_29 , V_149 -> V_167 ) ;
F_116 ( & V_149 -> V_168 ) ;
V_11 = F_120 ( V_149 ) ;
if ( V_11 )
goto V_169;
V_2 -> V_29 -> V_164 [ V_13 ] . V_170 ++ ;
}
}
return 0 ;
V_169:
for ( V_13 = V_2 -> V_29 -> V_163 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_150 = V_2 -> V_29 -> V_164 [ V_13 ] . V_170 - 1 ; V_150 >= 0 ; V_150 -- )
F_121 (
& V_2 -> V_29 -> V_164 [ V_13 ] . V_166 [ V_150 ] ) ;
if ( ! V_2 -> V_68 )
F_32 ( V_2 ) ;
V_160:
F_122 ( & V_2 -> V_39 ) ;
F_122 ( & V_2 -> V_117 ) ;
F_123 ( V_44 ) ;
V_155:
V_2 = NULL ;
V_153:
F_29 ( V_44 , L_30 ) ;
return V_11 ;
}
static int F_124 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_125 ( V_143 ) ;
int V_13 , V_150 ;
if ( ! V_2 )
return - V_118 ;
F_117 ( & V_37 ) ;
F_126 ( & V_2 -> V_161 ) ;
F_119 ( & V_37 ) ;
for ( V_13 = V_2 -> V_29 -> V_163 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_150 = V_2 -> V_29 -> V_164 [ V_13 ] . V_170 - 1 ; V_150 >= 0 ; V_150 -- )
F_121 (
& V_2 -> V_29 -> V_164 [ V_13 ] . V_166 [ V_150 ] ) ;
F_122 ( & V_2 -> V_39 ) ;
F_122 ( & V_2 -> V_117 ) ;
F_32 ( V_2 ) ;
F_123 ( V_2 -> V_44 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_127 ( struct V_133 * V_44 )
{
F_90 ( V_44 ) ;
return 0 ;
}
static int F_128 ( struct V_133 * V_44 )
{
F_88 ( V_44 ) ;
return 0 ;
}
