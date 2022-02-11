static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static struct V_26 *
F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
#if V_27
if ( V_6 -> V_28 & V_29 ) {
return F_13 ( V_3 , V_6 -> V_30 -> V_31 -> V_32 ) ;
} else
#endif
{
return F_14 ( V_6 ) ;
}
}
static int F_15 ( struct V_2 * V_3 , T_1 V_28 )
{
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , T_1 type ,
struct V_33 * V_34 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_35 :
V_34 -> V_28 = V_36 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = V_40 ;
break;
case V_41 :
V_34 -> V_42 = & V_43 ;
V_34 -> V_44 = V_6 -> V_45 . V_46 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = V_40 ;
V_34 -> V_28 = V_36 | V_47 ;
#if V_27
if ( V_6 -> V_28 & V_29 ) {
if ( ! ( F_17 ( V_6 -> V_30 ) && V_6 -> V_30 -> V_31 ) ) {
F_9 ( L_4 ,
( unsigned ) type ) ;
return - V_48 ;
}
if ( ! V_6 -> V_30 -> V_31 -> V_49 )
V_34 -> V_28 = V_36 ;
V_34 -> V_37 = V_50 |
V_51 ;
V_34 -> V_39 = V_51 ;
}
#endif
break;
case V_52 :
V_34 -> V_42 = & V_43 ;
V_34 -> V_44 = V_6 -> V_45 . V_53 ;
V_34 -> V_28 = V_54 |
V_36 ;
V_34 -> V_37 = V_50 | V_51 ;
V_34 -> V_39 = V_51 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_48 ;
}
return 0 ;
}
static void F_18 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 ;
static T_2 V_61 = V_38 | V_62 ;
if ( ! F_19 ( V_56 ) ) {
V_58 -> V_63 = 0 ;
V_58 -> V_64 = 0 ;
V_58 -> V_58 = & V_61 ;
V_58 -> V_65 = & V_61 ;
V_58 -> V_66 = 1 ;
V_58 -> V_67 = 1 ;
return;
}
V_60 = F_2 ( V_56 , struct V_59 , V_68 ) ;
switch ( V_56 -> V_69 . V_70 ) {
case V_52 :
if ( V_60 -> V_6 -> V_71 . V_72 == false )
F_20 ( V_60 , V_73 ) ;
else
F_20 ( V_60 , V_74 ) ;
break;
case V_41 :
default:
F_20 ( V_60 , V_73 ) ;
}
* V_58 = V_60 -> V_58 ;
}
static int F_21 ( struct V_55 * V_56 , struct V_75 * V_76 )
{
return 0 ;
}
static void F_22 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
struct V_77 * V_79 = & V_56 -> V_69 ;
F_23 ( V_79 -> V_80 != NULL ) ;
* V_79 = * V_78 ;
V_78 -> V_80 = NULL ;
}
static int F_24 ( struct V_55 * V_56 ,
bool V_81 , int V_82 , bool V_83 ,
struct V_77 * V_78 ,
struct V_77 * V_79 )
{
struct V_1 * V_6 ;
T_3 V_84 , V_85 ;
struct V_86 * V_87 ;
int V_11 ;
V_6 = F_1 ( V_56 -> V_3 ) ;
V_11 = F_25 ( V_6 , & V_87 ) ;
if ( F_26 ( V_11 ) ) {
return V_11 ;
}
V_84 = V_79 -> V_88 << V_89 ;
V_85 = V_78 -> V_88 << V_89 ;
switch ( V_79 -> V_70 ) {
case V_52 :
V_84 += V_6 -> V_45 . V_53 ;
break;
case V_41 :
V_84 += V_6 -> V_45 . V_46 ;
break;
default:
F_9 ( L_6 , V_79 -> V_70 ) ;
return - V_48 ;
}
switch ( V_78 -> V_70 ) {
case V_52 :
V_85 += V_6 -> V_45 . V_53 ;
break;
case V_41 :
V_85 += V_6 -> V_45 . V_46 ;
break;
default:
F_9 ( L_6 , V_79 -> V_70 ) ;
return - V_48 ;
}
if ( ! V_6 -> V_71 . V_72 ) {
F_9 ( L_7 ) ;
return - V_48 ;
}
F_27 ( ( V_90 % V_91 ) != 0 ) ;
V_11 = F_28 ( V_6 , V_84 , V_85 ,
V_78 -> V_92 * ( V_90 / V_91 ) ,
V_87 ) ;
V_11 = F_29 ( V_56 , ( void * ) V_87 , NULL ,
V_81 , V_82 , V_83 , V_78 ) ;
F_30 ( & V_87 ) ;
return V_11 ;
}
static int F_31 ( struct V_55 * V_56 ,
bool V_81 , bool V_93 ,
bool V_82 , bool V_83 ,
struct V_77 * V_78 )
{
struct V_1 * V_6 ;
struct V_77 * V_79 = & V_56 -> V_69 ;
struct V_77 V_94 ;
T_2 V_61 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_56 -> V_3 ) ;
V_94 = * V_78 ;
V_94 . V_80 = NULL ;
V_58 . V_63 = 0 ;
V_58 . V_64 = 0 ;
V_58 . V_66 = 1 ;
V_58 . V_58 = & V_61 ;
V_58 . V_67 = 1 ;
V_58 . V_65 = & V_61 ;
V_61 = V_38 | V_95 ;
V_11 = F_32 ( V_56 , & V_58 , & V_94 ,
V_93 , V_82 , V_83 ) ;
if ( F_26 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_33 ( V_56 -> V_96 , V_94 . V_58 ) ;
if ( F_26 ( V_11 ) ) {
goto V_97;
}
V_11 = F_34 ( V_56 -> V_96 , & V_94 ) ;
if ( F_26 ( V_11 ) ) {
goto V_97;
}
V_11 = F_24 ( V_56 , true , V_82 , V_83 , & V_94 , V_79 ) ;
if ( F_26 ( V_11 ) ) {
goto V_97;
}
V_11 = F_35 ( V_56 , true , V_82 , V_83 , V_78 ) ;
V_97:
F_36 ( V_56 , & V_94 ) ;
return V_11 ;
}
static int F_37 ( struct V_55 * V_56 ,
bool V_81 , bool V_93 ,
bool V_82 , bool V_83 ,
struct V_77 * V_78 )
{
struct V_1 * V_6 ;
struct V_77 * V_79 = & V_56 -> V_69 ;
struct V_77 V_94 ;
struct V_57 V_58 ;
T_2 V_61 ;
int V_11 ;
V_6 = F_1 ( V_56 -> V_3 ) ;
V_94 = * V_78 ;
V_94 . V_80 = NULL ;
V_58 . V_63 = 0 ;
V_58 . V_64 = 0 ;
V_58 . V_66 = 1 ;
V_58 . V_58 = & V_61 ;
V_58 . V_67 = 1 ;
V_58 . V_65 = & V_61 ;
V_61 = V_38 | V_95 ;
V_11 = F_32 ( V_56 , & V_58 , & V_94 , V_93 , V_82 , V_83 ) ;
if ( F_26 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_35 ( V_56 , true , V_82 , V_83 , & V_94 ) ;
if ( F_26 ( V_11 ) ) {
goto V_97;
}
V_11 = F_24 ( V_56 , true , V_82 , V_83 , V_78 , V_79 ) ;
if ( F_26 ( V_11 ) ) {
goto V_97;
}
V_97:
F_36 ( V_56 , & V_94 ) ;
return V_11 ;
}
static int F_38 ( struct V_55 * V_56 ,
bool V_81 , bool V_93 ,
bool V_82 , bool V_83 ,
struct V_77 * V_78 )
{
struct V_1 * V_6 ;
struct V_77 * V_79 = & V_56 -> V_69 ;
int V_11 ;
V_6 = F_1 ( V_56 -> V_3 ) ;
if ( V_79 -> V_70 == V_35 && V_56 -> V_96 == NULL ) {
F_22 ( V_56 , V_78 ) ;
return 0 ;
}
if ( ( V_79 -> V_70 == V_41 &&
V_78 -> V_70 == V_35 ) ||
( V_79 -> V_70 == V_35 &&
V_78 -> V_70 == V_41 ) ) {
F_22 ( V_56 , V_78 ) ;
return 0 ;
}
if ( ! V_6 -> V_71 . V_72 || V_6 -> V_98 -> V_99 == NULL ) {
goto memcpy;
}
if ( V_79 -> V_70 == V_52 &&
V_78 -> V_70 == V_35 ) {
V_11 = F_31 ( V_56 , V_81 , V_93 ,
V_82 , V_83 , V_78 ) ;
} else if ( V_79 -> V_70 == V_35 &&
V_78 -> V_70 == V_52 ) {
V_11 = F_37 ( V_56 , V_81 , V_93 ,
V_82 , V_83 , V_78 ) ;
} else {
V_11 = F_24 ( V_56 , V_81 , V_82 , V_83 , V_78 , V_79 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_39 ( V_56 , V_81 , V_82 , V_83 , V_78 ) ;
}
return V_11 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_77 * V_69 )
{
struct V_33 * V_34 = & V_3 -> V_34 [ V_69 -> V_70 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_69 -> V_100 . V_101 = NULL ;
V_69 -> V_100 . V_102 = 0 ;
V_69 -> V_100 . V_16 = V_69 -> V_92 << V_89 ;
V_69 -> V_100 . V_103 = 0 ;
V_69 -> V_100 . V_104 = false ;
if ( ! ( V_34 -> V_28 & V_36 ) )
return - V_48 ;
switch ( V_69 -> V_70 ) {
case V_35 :
return 0 ;
case V_41 :
#if V_27
if ( V_6 -> V_28 & V_29 ) {
V_69 -> V_100 . V_102 = V_69 -> V_88 << V_89 ;
V_69 -> V_100 . V_103 = V_6 -> V_45 . V_105 ;
V_69 -> V_100 . V_104 = ! V_6 -> V_30 -> V_31 -> V_49 ;
}
#endif
break;
case V_52 :
V_69 -> V_100 . V_102 = V_69 -> V_88 << V_89 ;
if ( ( V_69 -> V_100 . V_102 + V_69 -> V_100 . V_16 ) > V_6 -> V_45 . V_106 )
return - V_48 ;
V_69 -> V_100 . V_103 = V_6 -> V_45 . V_107 ;
V_69 -> V_100 . V_104 = true ;
#ifdef F_41
if ( V_69 -> V_58 & V_51 )
V_69 -> V_100 . V_101 =
F_42 ( V_69 -> V_100 . V_103 + V_69 -> V_100 . V_102 ,
V_69 -> V_100 . V_16 ) ;
else
V_69 -> V_100 . V_101 =
F_43 ( V_69 -> V_100 . V_103 + V_69 -> V_100 . V_102 ,
V_69 -> V_100 . V_16 ) ;
V_69 -> V_100 . V_103 = ( V_69 -> V_100 . V_103 & 0x0ffffffffUL ) +
V_6 -> V_30 -> V_108 -> V_109 ;
#endif
break;
default:
return - V_48 ;
}
return 0 ;
}
static void F_44 ( struct V_2 * V_3 , struct V_77 * V_69 )
{
}
static int F_45 ( void * V_110 , void * V_111 ,
bool V_112 , bool V_93 )
{
return F_46 ( (struct V_86 * ) V_110 , V_93 ) ;
}
static int F_47 ( void * V_110 , void * V_111 )
{
return 0 ;
}
static void F_48 ( void * * V_110 )
{
F_30 ( (struct V_86 * * ) V_110 ) ;
}
static void * F_49 ( void * V_110 )
{
return F_50 ( (struct V_86 * ) V_110 ) ;
}
static bool F_51 ( void * V_110 , void * V_111 )
{
return F_52 ( (struct V_86 * ) V_110 ) ;
}
int F_53 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_54 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_113 , V_114 ,
V_6 -> V_115 ) ;
if ( V_11 ) {
F_9 ( L_8 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_116 = true ;
V_11 = F_55 ( & V_6 -> V_5 . V_3 , V_52 ,
V_6 -> V_45 . V_117 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_9 ) ;
return V_11 ;
}
V_11 = F_56 ( V_6 , 256 * 1024 , V_90 , true ,
V_118 ,
& V_6 -> V_119 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_57 ( V_6 -> V_119 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_58 ( V_6 -> V_119 , V_118 , NULL ) ;
F_59 ( V_6 -> V_119 ) ;
if ( V_11 ) {
F_60 ( & V_6 -> V_119 ) ;
return V_11 ;
}
F_61 ( L_10 ,
( unsigned ) V_6 -> V_45 . V_117 / ( 1024 * 1024 ) ) ;
V_11 = F_55 ( & V_6 -> V_5 . V_3 , V_41 ,
V_6 -> V_45 . V_120 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_61 ( L_12 ,
( unsigned ) ( V_6 -> V_45 . V_120 / ( 1024 * 1024 ) ) ) ;
if ( F_26 ( V_6 -> V_5 . V_3 . V_121 == NULL ) ) {
V_6 -> V_5 . V_3 . V_121 = V_6 -> V_30 -> V_121 ;
}
V_11 = F_62 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
return 0 ;
}
void F_63 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_116 )
return;
if ( V_6 -> V_119 ) {
V_11 = F_57 ( V_6 -> V_119 , false ) ;
if ( V_11 == 0 ) {
F_64 ( V_6 -> V_119 ) ;
F_59 ( V_6 -> V_119 ) ;
}
F_60 ( & V_6 -> V_119 ) ;
}
F_65 ( & V_6 -> V_5 . V_3 , V_52 ) ;
F_65 ( & V_6 -> V_5 . V_3 , V_41 ) ;
F_66 ( & V_6 -> V_5 . V_3 ) ;
F_67 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_116 = false ;
F_61 ( L_14 ) ;
}
void F_68 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_33 * V_34 ;
if ( ! V_6 -> V_5 . V_116 )
return;
V_34 = & V_6 -> V_5 . V_3 . V_34 [ V_52 ] ;
V_34 -> V_16 = V_16 >> V_89 ;
}
static int F_69 ( struct V_122 * V_123 , struct V_124 * V_125 )
{
struct V_55 * V_56 ;
struct V_1 * V_6 ;
int V_11 ;
V_56 = (struct V_55 * ) V_123 -> V_126 ;
if ( V_56 == NULL ) {
return V_127 ;
}
V_6 = F_1 ( V_56 -> V_3 ) ;
F_70 ( & V_6 -> V_128 ) ;
V_11 = V_129 -> V_130 ( V_123 , V_125 ) ;
F_71 ( & V_6 -> V_128 ) ;
return V_11 ;
}
int F_72 ( struct V_75 * V_76 , struct V_122 * V_123 )
{
struct V_131 * V_132 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_26 ( V_123 -> V_133 < V_114 ) ) {
return F_73 ( V_76 , V_123 ) ;
}
V_132 = V_76 -> V_134 ;
V_6 = V_132 -> V_135 -> V_136 -> V_137 ;
if ( V_6 == NULL ) {
return - V_48 ;
}
V_11 = F_74 ( V_76 , V_123 , & V_6 -> V_5 . V_3 ) ;
if ( F_26 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_26 ( V_129 == NULL ) ) {
V_129 = V_123 -> V_138 ;
V_139 = * V_129 ;
V_139 . V_130 = & F_69 ;
}
V_123 -> V_138 = & V_139 ;
return 0 ;
}
static int F_75 ( struct V_26 * V_140 ,
unsigned long V_92 ,
struct V_141 * * V_142 ,
struct V_141 * V_143 ,
T_5 * V_144 )
{
struct V_145 * V_146 ;
V_146 = F_2 ( V_140 , struct V_145 , V_140 ) ;
V_146 -> V_142 = V_142 ;
V_146 -> V_144 = V_144 ;
V_146 -> V_92 = V_92 ;
V_146 -> V_143 = V_143 ;
V_146 -> V_147 = true ;
return 0 ;
}
static void F_76 ( struct V_26 * V_140 )
{
struct V_145 * V_146 ;
V_146 = F_2 ( V_140 , struct V_145 , V_140 ) ;
V_146 -> V_142 = NULL ;
V_146 -> V_144 = NULL ;
V_146 -> V_92 = 0 ;
V_146 -> V_143 = NULL ;
V_146 -> V_147 = false ;
V_146 -> V_148 = false ;
}
static int F_77 ( struct V_26 * V_140 ,
struct V_77 * V_149 )
{
struct V_145 * V_146 ;
int V_11 ;
V_146 = F_2 ( V_140 , struct V_145 , V_140 ) ;
V_146 -> V_102 = V_149 -> V_88 << V_89 ;
if ( ! V_146 -> V_92 ) {
F_78 ( 1 , L_15 ,
V_146 -> V_92 , V_149 , V_140 ) ;
}
V_11 = F_79 ( V_146 -> V_6 , V_146 -> V_102 ,
V_146 -> V_92 , V_146 -> V_142 , V_146 -> V_144 ) ;
if ( V_11 ) {
F_9 ( L_16 ,
V_146 -> V_92 , V_146 -> V_102 ) ;
return V_11 ;
}
V_146 -> V_148 = true ;
return 0 ;
}
static int F_80 ( struct V_26 * V_140 )
{
struct V_145 * V_146 ;
V_146 = F_2 ( V_140 , struct V_145 , V_140 ) ;
F_81 ( V_146 -> V_6 , V_146 -> V_102 , V_146 -> V_92 ) ;
V_146 -> V_148 = false ;
return 0 ;
}
static void F_82 ( struct V_26 * V_140 )
{
struct V_145 * V_146 ;
V_146 = F_2 ( V_140 , struct V_145 , V_140 ) ;
if ( V_146 -> V_148 ) {
F_80 ( V_140 ) ;
}
F_83 ( V_146 ) ;
}
struct V_26 * F_14 ( struct V_1 * V_6 )
{
struct V_145 * V_146 ;
V_146 = F_84 ( sizeof( struct V_145 ) , V_150 ) ;
if ( V_146 == NULL ) {
return NULL ;
}
V_146 -> V_140 . V_3 = & V_6 -> V_5 . V_3 ;
V_146 -> V_140 . V_28 = 0 ;
V_146 -> V_140 . V_42 = & V_151 ;
V_146 -> V_6 = V_6 ;
V_146 -> V_142 = NULL ;
V_146 -> V_92 = 0 ;
V_146 -> V_143 = NULL ;
V_146 -> V_147 = false ;
V_146 -> V_148 = false ;
return & V_146 -> V_140 ;
}
static int F_85 ( struct V_152 * V_153 , void * V_154 )
{
struct V_155 * V_156 = (struct V_155 * ) V_153 -> V_157 ;
struct V_158 * V_159 = (struct V_158 * ) V_156 -> V_160 -> V_154 ;
struct V_161 * V_136 = V_156 -> V_135 -> V_136 ;
struct V_1 * V_6 = V_136 -> V_137 ;
int V_162 ;
struct V_23 * V_163 = V_6 -> V_5 . V_3 . V_163 ;
F_86 ( & V_163 -> V_164 ) ;
V_162 = F_87 ( V_153 , V_159 ) ;
F_88 ( & V_163 -> V_164 ) ;
return V_162 ;
}
static int F_62 ( struct V_1 * V_6 )
{
#if F_89 ( V_165 )
static struct V_166 V_167 [ V_168 + 1 ] ;
static char V_169 [ V_168 + 1 ] [ 32 ] ;
unsigned V_170 ;
for ( V_170 = 0 ; V_170 < V_168 ; V_170 ++ ) {
if ( V_170 == 0 )
sprintf ( V_169 [ V_170 ] , L_17 ) ;
else
sprintf ( V_169 [ V_170 ] , L_18 ) ;
V_167 [ V_170 ] . V_171 = V_169 [ V_170 ] ;
V_167 [ V_170 ] . V_172 = & F_85 ;
V_167 [ V_170 ] . V_173 = 0 ;
if ( V_170 == 0 )
V_167 [ V_170 ] . V_154 = V_6 -> V_5 . V_3 . V_34 [ V_52 ] . V_174 ;
else
V_167 [ V_170 ] . V_154 = V_6 -> V_5 . V_3 . V_34 [ V_41 ] . V_174 ;
}
sprintf ( V_169 [ V_170 ] , L_19 ) ;
V_167 [ V_170 ] . V_171 = V_169 [ V_170 ] ;
V_167 [ V_170 ] . V_172 = & V_175 ;
V_167 [ V_170 ] . V_173 = 0 ;
V_167 [ V_170 ] . V_154 = NULL ;
return F_90 ( V_6 , V_167 , V_168 + 1 ) ;
#endif
return 0 ;
}
