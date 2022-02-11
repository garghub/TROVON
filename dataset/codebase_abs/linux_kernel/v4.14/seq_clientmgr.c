static inline unsigned short F_1 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_2 & ( V_3 | V_4 ) ) {
case V_4 :
return V_5 ;
case V_3 :
return V_6 ;
default:
return V_7 ;
}
}
static inline int F_2 ( struct V_8 * V_9 )
{
return F_3 ( V_9 -> V_10 ) > 0 ;
}
static struct V_8 * F_4 ( int V_11 )
{
if ( V_11 < 0 || V_11 >= V_12 ) {
F_5 ( L_1 ,
V_11 ) ;
return NULL ;
}
return V_13 [ V_11 ] ;
}
struct V_8 * F_6 ( int V_11 )
{
unsigned long V_14 ;
struct V_8 * V_9 ;
if ( V_11 < 0 || V_11 >= V_12 ) {
F_5 ( L_1 ,
V_11 ) ;
return NULL ;
}
F_7 ( & V_15 , V_14 ) ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 )
goto V_16;
if ( V_17 [ V_11 ] ) {
F_8 ( & V_15 , V_14 ) ;
return NULL ;
}
F_8 ( & V_15 , V_14 ) ;
#ifdef F_9
if ( ! F_10 () ) {
static char V_18 [ V_19 ] ;
static char V_20 [ V_21 ] ;
if ( V_11 < V_19 ) {
int V_22 ;
if ( ! V_18 [ V_11 ] ) {
V_18 [ V_11 ] = 1 ;
for ( V_22 = 0 ; V_22 < 15 ; V_22 ++ ) {
if ( V_23 [ V_22 ] < 0 )
break;
if ( V_23 [ V_22 ] == V_11 ) {
F_11 ( L_2 ,
V_11 ) ;
break;
}
}
}
} else if ( V_11 < V_24 ) {
int V_25 = ( V_11 - V_19 ) /
V_26 ;
if ( V_25 < V_27 ) {
if ( ! V_20 [ V_25 ] ) {
V_20 [ V_25 ] = 1 ;
F_12 ( V_25 ) ;
}
F_13 () ;
}
}
F_7 ( & V_15 , V_14 ) ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 )
goto V_16;
F_8 ( & V_15 , V_14 ) ;
}
#endif
return NULL ;
V_16:
F_14 ( & V_9 -> V_28 ) ;
F_8 ( & V_15 , V_14 ) ;
return V_9 ;
}
static void F_15 ( struct V_29 * V_30 , int V_31 )
{
V_30 -> V_32 += V_31 ;
if ( V_30 -> V_32 > V_30 -> V_33 )
V_30 -> V_33 = V_30 -> V_32 ;
}
static void F_16 ( struct V_29 * V_30 , int V_31 )
{
V_30 -> V_32 -= V_31 ;
}
int T_1 F_17 ( void )
{
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
return 0 ;
}
static struct V_8 * F_18 ( int V_34 , int V_35 )
{
unsigned long V_14 ;
int V_36 ;
struct V_8 * V_9 ;
V_9 = F_19 ( sizeof( * V_9 ) , V_37 ) ;
if ( V_9 == NULL )
return NULL ;
V_9 -> V_10 = F_20 ( V_35 ) ;
if ( V_9 -> V_10 == NULL ) {
F_21 ( V_9 ) ;
return NULL ;
}
V_9 -> type = V_38 ;
F_22 ( & V_9 -> V_28 ) ;
F_23 ( & V_9 -> V_39 ) ;
F_24 ( & V_9 -> V_40 ) ;
F_25 ( & V_9 -> V_41 ) ;
F_7 ( & V_15 , V_14 ) ;
if ( V_34 < 0 ) {
for ( V_36 = V_24 ;
V_36 < V_12 ;
V_36 ++ ) {
if ( V_13 [ V_36 ] || V_17 [ V_36 ] )
continue;
V_13 [ V_9 -> V_42 = V_36 ] = V_9 ;
F_8 ( & V_15 , V_14 ) ;
return V_9 ;
}
} else {
if ( V_13 [ V_34 ] == NULL && ! V_17 [ V_34 ] ) {
V_13 [ V_9 -> V_42 = V_34 ] = V_9 ;
F_8 ( & V_15 , V_14 ) ;
return V_9 ;
}
}
F_8 ( & V_15 , V_14 ) ;
F_26 ( & V_9 -> V_10 ) ;
F_21 ( V_9 ) ;
return NULL ;
}
static int F_27 ( struct V_8 * V_9 )
{
unsigned long V_14 ;
if ( ! V_9 )
return 0 ;
F_28 ( V_9 ) ;
F_29 ( V_9 -> V_42 ) ;
F_7 ( & V_15 , V_14 ) ;
V_17 [ V_9 -> V_42 ] = 1 ;
V_13 [ V_9 -> V_42 ] = NULL ;
F_8 ( & V_15 , V_14 ) ;
F_30 ( & V_9 -> V_28 ) ;
F_31 ( V_9 -> V_42 ) ;
if ( V_9 -> V_10 )
F_26 ( & V_9 -> V_10 ) ;
F_7 ( & V_15 , V_14 ) ;
V_17 [ V_9 -> V_42 ] = 0 ;
F_8 ( & V_15 , V_14 ) ;
return 0 ;
}
static void F_32 ( struct V_8 * V_9 )
{
F_33 ( & V_43 ) ;
switch ( V_9 -> type ) {
case V_38 :
F_34 ( L_3 ,
V_9 -> V_42 ) ;
break;
case V_44 :
case V_45 :
F_27 ( V_9 ) ;
F_16 ( & V_46 , 1 ) ;
break;
default:
F_35 ( L_4 ,
V_9 -> V_42 , V_9 -> type ) ;
}
F_36 ( & V_43 ) ;
F_37 ( V_9 -> V_42 ) ;
}
static int F_38 ( struct V_47 * V_47 , struct V_1 * V_1 )
{
int V_36 , V_48 ;
struct V_8 * V_9 ;
struct V_49 * V_50 ;
int V_51 ;
V_51 = F_39 ( V_47 , V_1 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_40 ( & V_43 ) )
return - V_52 ;
V_9 = F_18 ( - 1 , V_53 ) ;
if ( V_9 == NULL ) {
F_36 ( & V_43 ) ;
return - V_54 ;
}
V_48 = F_1 ( V_1 ) ;
if ( V_48 & V_6 )
V_9 -> V_55 = 1 ;
if ( V_48 & V_5 )
V_9 -> V_56 = 1 ;
V_50 = & V_9 -> V_57 . V_50 ;
V_50 -> V_58 = NULL ;
V_50 -> V_59 = 0 ;
if ( V_48 & V_6 ) {
V_50 -> V_59 = V_60 ;
V_50 -> V_58 = F_41 ( V_50 -> V_59 ) ;
if ( V_50 -> V_58 == NULL ) {
F_27 ( V_9 ) ;
F_21 ( V_9 ) ;
F_36 ( & V_43 ) ;
return - V_54 ;
}
}
F_15 ( & V_46 , 1 ) ;
V_9 -> type = V_44 ;
F_36 ( & V_43 ) ;
V_36 = V_9 -> V_42 ;
V_1 -> V_61 = V_9 ;
V_50 -> V_1 = V_1 ;
sprintf ( V_9 -> V_62 , L_5 , V_36 ) ;
V_9 -> V_57 . V_50 . V_63 = F_42 ( F_43 ( V_64 ) ) ;
F_44 ( V_36 ) ;
return 0 ;
}
static int F_45 ( struct V_47 * V_47 , struct V_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_61 ;
if ( V_9 ) {
F_32 ( V_9 ) ;
if ( V_9 -> V_57 . V_50 . V_58 )
F_46 ( & V_9 -> V_57 . V_50 . V_58 ) ;
F_47 ( V_9 -> V_57 . V_50 . V_63 ) ;
F_21 ( V_9 ) ;
}
return 0 ;
}
static T_2 F_48 ( struct V_1 * V_1 , char T_3 * V_65 , T_4 V_66 ,
T_5 * V_67 )
{
struct V_8 * V_9 = V_1 -> V_61 ;
struct V_68 * V_58 ;
int V_51 ;
long V_69 = 0 ;
struct V_70 * V_71 ;
if ( ! ( F_1 ( V_1 ) & V_6 ) )
return - V_72 ;
if ( ! F_49 ( V_73 , V_65 , V_66 ) )
return - V_74 ;
if ( F_50 ( ! V_9 ) )
return - V_72 ;
if ( ! V_9 -> V_55 || ( V_58 = V_9 -> V_57 . V_50 . V_58 ) == NULL )
return - V_72 ;
if ( F_51 ( & V_58 -> V_75 ) > 0 ) {
F_52 ( V_58 ) ;
return - V_76 ;
}
V_71 = NULL ;
V_51 = 0 ;
F_53 ( V_58 ) ;
while ( V_66 >= sizeof( struct V_77 ) ) {
int V_78 ;
V_78 = ( V_1 -> V_79 & V_80 ) || V_69 > 0 ;
if ( ( V_51 = F_54 ( V_58 , & V_71 , V_78 ) ) < 0 ) {
break;
}
if ( F_55 ( & V_71 -> V_81 ) ) {
struct V_77 V_82 ;
V_82 = V_71 -> V_81 ;
V_82 . V_57 . V_83 . V_84 &= ~ V_85 ;
if ( F_56 ( V_65 , & V_82 , sizeof( struct V_77 ) ) ) {
V_51 = - V_74 ;
break;
}
V_66 -= sizeof( struct V_77 ) ;
V_65 += sizeof( struct V_77 ) ;
V_51 = F_57 ( & V_71 -> V_81 , V_66 ,
( char V_86 * ) V_65 , 0 ,
sizeof( struct V_77 ) ) ;
if ( V_51 < 0 )
break;
V_69 += V_51 ;
V_66 -= V_51 ;
V_65 += V_51 ;
} else {
if ( F_56 ( V_65 , & V_71 -> V_81 , sizeof( struct V_77 ) ) ) {
V_51 = - V_74 ;
break;
}
V_66 -= sizeof( struct V_77 ) ;
V_65 += sizeof( struct V_77 ) ;
}
F_58 ( V_71 ) ;
V_71 = NULL ;
V_69 += sizeof( struct V_77 ) ;
}
if ( V_51 < 0 ) {
if ( V_71 )
F_59 ( V_58 , V_71 ) ;
if ( V_51 == - V_87 && V_69 > 0 )
V_51 = 0 ;
}
F_60 ( V_58 ) ;
return ( V_51 < 0 ) ? V_51 : V_69 ;
}
static int F_61 ( struct V_88 * V_89 , unsigned int V_14 )
{
if ( ( V_89 -> V_90 & V_14 ) != V_14 )
return 0 ;
return V_14 ;
}
static struct V_8 * F_62 ( struct V_77 * V_81 ,
int V_91 )
{
struct V_8 * V_92 ;
V_92 = F_6 ( V_81 -> V_92 . V_9 ) ;
if ( V_92 == NULL )
return NULL ;
if ( ! V_92 -> V_55 )
goto V_93;
if ( ( V_92 -> V_91 & V_94 ) &&
! F_63 ( V_81 -> type , V_92 -> V_95 ) )
goto V_93;
if ( V_91 && ! ( V_92 -> V_91 & V_91 ) )
goto V_93;
return V_92 ;
V_93:
F_64 ( V_92 ) ;
return NULL ;
}
static int F_65 ( struct V_8 * V_9 ,
struct V_77 * V_81 ,
int V_51 , int V_96 , int V_97 )
{
struct V_77 V_98 ;
int V_69 ;
if ( V_9 == NULL ||
! ( V_9 -> V_91 & V_99 ) ||
! V_9 -> V_55 )
return 0 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . type = V_100 ;
V_98 . V_14 = V_101 ;
V_98 . V_102 = V_103 ;
V_98 . V_104 . V_9 = V_105 ;
V_98 . V_104 . V_89 = V_106 ;
V_98 . V_92 . V_9 = V_9 -> V_42 ;
V_98 . V_92 . V_89 = V_81 -> V_104 . V_89 ;
V_98 . V_57 . V_107 . V_108 = V_81 -> V_92 ;
V_98 . V_57 . V_107 . V_81 = V_81 ;
V_98 . V_57 . V_107 . V_109 = - V_51 ;
V_69 = F_66 ( NULL , & V_98 , 0 , V_96 , V_97 + 1 ) ;
if ( V_69 < 0 ) {
V_9 -> V_110 ++ ;
return V_69 ;
}
return V_69 ;
}
static int F_67 ( struct V_77 * V_81 ,
int V_102 , int V_111 )
{
struct V_112 * V_113 ;
V_113 = F_68 ( V_102 ) ;
if ( ! V_113 )
return 0 ;
V_81 -> V_102 = V_102 ;
V_81 -> V_14 &= ~ V_114 ;
if ( V_111 ) {
V_81 -> time . time = F_69 ( V_113 -> V_115 ) ;
V_81 -> V_14 |= V_116 ;
} else {
V_81 -> time . V_117 = F_70 ( V_113 -> V_115 ) ;
V_81 -> V_14 |= V_118 ;
}
F_71 ( V_113 ) ;
return 1 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_77 * V_81 ,
int V_91 , int V_96 , int V_97 )
{
struct V_8 * V_92 = NULL ;
struct V_88 * V_119 = NULL ;
int V_69 = - V_120 ;
int V_121 ;
V_121 = F_72 ( V_81 ) ;
V_92 = F_62 ( V_81 , V_91 ) ;
if ( V_92 == NULL )
goto V_122;
V_119 = F_73 ( V_92 , V_81 -> V_92 . V_89 ) ;
if ( V_119 == NULL )
goto V_122;
if ( ! F_61 ( V_119 , V_123 ) ) {
V_69 = - V_124 ;
goto V_122;
}
if ( V_119 -> V_125 )
F_67 ( V_81 , V_119 -> V_126 ,
V_119 -> V_127 ) ;
switch ( V_92 -> type ) {
case V_44 :
if ( V_92 -> V_57 . V_50 . V_58 )
V_69 = F_74 ( V_92 -> V_57 . V_50 . V_58 , V_81 ) ;
break;
case V_45 :
if ( V_119 -> V_128 == NULL )
break;
V_69 = V_119 -> V_128 ( V_81 , V_121 ,
V_119 -> V_61 ,
V_96 , V_97 ) ;
break;
default:
break;
}
V_122:
if ( V_119 )
F_75 ( V_119 ) ;
if ( V_92 )
F_64 ( V_92 ) ;
if ( V_69 < 0 && ! V_121 ) {
V_69 = F_65 ( V_9 , V_81 , V_69 , V_96 , V_97 ) ;
}
return V_69 ;
}
static int F_76 ( struct V_8 * V_9 ,
struct V_77 * V_81 ,
int V_96 , int V_97 )
{
struct V_129 * V_130 ;
int V_51 , V_69 = 0 , V_131 = 0 ;
struct V_77 V_132 ;
struct V_88 * V_133 ;
struct V_134 * V_135 ;
V_133 = F_73 ( V_9 , V_81 -> V_104 . V_89 ) ;
if ( V_133 == NULL )
return - V_136 ;
V_132 = * V_81 ;
V_135 = & V_133 -> V_137 ;
if ( V_96 )
F_77 ( & V_135 -> V_138 ) ;
else
F_78 ( & V_135 -> V_139 , V_97 ) ;
F_79 (subs, &grp->list_head, src_list) {
if ( F_51 ( & V_130 -> V_140 ) != 2 )
continue;
V_81 -> V_92 = V_130 -> V_141 . V_92 ;
if ( V_130 -> V_141 . V_14 & V_142 )
F_67 ( V_81 , V_130 -> V_141 . V_102 ,
V_130 -> V_141 . V_14 & V_143 ) ;
V_51 = F_66 ( V_9 , V_81 ,
0 , V_96 , V_97 ) ;
if ( V_51 < 0 ) {
if ( ! V_69 )
V_69 = V_51 ;
continue;
}
V_131 ++ ;
* V_81 = V_132 ;
}
if ( V_96 )
F_80 ( & V_135 -> V_138 ) ;
else
F_81 ( & V_135 -> V_139 ) ;
* V_81 = V_132 ;
F_75 ( V_133 ) ;
return ( V_69 < 0 ) ? V_69 : V_131 ;
}
static int F_82 ( struct V_8 * V_9 ,
struct V_77 * V_81 ,
int V_96 , int V_97 )
{
int V_131 = 0 , V_51 , V_69 = 0 ;
struct V_8 * V_144 ;
struct V_88 * V_89 ;
V_144 = F_62 ( V_81 , V_145 ) ;
if ( V_144 == NULL )
return 0 ;
F_77 ( & V_144 -> V_39 ) ;
F_79 (port, &dest_client->ports_list_head, list) {
V_81 -> V_92 . V_89 = V_89 -> V_146 . V_89 ;
V_51 = F_66 ( NULL , V_81 ,
V_145 ,
V_96 , V_97 ) ;
if ( V_51 < 0 ) {
if ( ! V_69 )
V_69 = V_51 ;
continue;
}
V_131 ++ ;
}
F_80 ( & V_144 -> V_39 ) ;
F_64 ( V_144 ) ;
V_81 -> V_92 . V_89 = V_147 ;
return ( V_69 < 0 ) ? V_69 : V_131 ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_77 * V_81 , int V_96 , int V_97 )
{
int V_51 , V_69 = 0 , V_131 = 0 ;
int V_92 ;
struct V_148 V_146 ;
V_146 = V_81 -> V_92 ;
for ( V_92 = 0 ; V_92 < V_12 ; V_92 ++ ) {
if ( V_92 == V_9 -> V_42 )
continue;
V_81 -> V_92 . V_9 = V_92 ;
V_81 -> V_92 . V_89 = V_146 . V_89 ;
if ( V_146 . V_89 == V_147 )
V_51 = F_82 ( V_9 , V_81 , V_96 , V_97 ) ;
else
V_51 = F_66 ( NULL , V_81 ,
V_145 ,
V_96 , V_97 ) ;
if ( V_51 < 0 ) {
if ( ! V_69 )
V_69 = V_51 ;
continue;
}
V_131 += V_51 ;
}
V_81 -> V_92 = V_146 ;
return ( V_69 < 0 ) ? V_69 : V_131 ;
}
static int F_84 ( struct V_8 * V_9 , struct V_77 * V_81 ,
int V_96 , int V_97 )
{
F_5 ( L_6 ) ;
return 0 ;
}
static int F_85 ( struct V_8 * V_9 , struct V_77 * V_81 ,
int V_96 , int V_97 )
{
int V_69 ;
V_97 ++ ;
if ( V_97 >= V_149 ) {
F_5 ( L_7 ,
V_81 -> V_104 . V_9 , V_81 -> V_104 . V_89 ,
V_81 -> V_92 . V_9 , V_81 -> V_92 . V_89 ) ;
return - V_150 ;
}
if ( V_81 -> V_102 == V_151 ||
V_81 -> V_92 . V_9 == V_151 )
V_69 = F_76 ( V_9 , V_81 , V_96 , V_97 ) ;
#ifdef F_86
else if ( V_81 -> V_102 == V_147 ||
V_81 -> V_92 . V_9 == V_147 )
V_69 = F_83 ( V_9 , V_81 , V_96 , V_97 ) ;
else if ( V_81 -> V_92 . V_9 >= V_12 )
V_69 = F_84 ( V_9 , V_81 , V_96 , V_97 ) ;
else if ( V_81 -> V_92 . V_89 == V_147 )
V_69 = F_82 ( V_9 , V_81 , V_96 , V_97 ) ;
#endif
else
V_69 = F_66 ( V_9 , V_81 , 0 , V_96 , V_97 ) ;
return V_69 ;
}
int F_87 ( struct V_70 * V_71 , int V_96 , int V_97 )
{
struct V_8 * V_9 ;
int V_69 ;
if ( F_50 ( ! V_71 ) )
return - V_136 ;
V_9 = F_6 ( V_71 -> V_81 . V_104 . V_9 ) ;
if ( V_9 == NULL ) {
F_58 ( V_71 ) ;
return - V_136 ;
}
if ( V_71 -> V_81 . type == V_152 ) {
struct V_77 V_82 , * V_153 ;
V_82 = V_71 -> V_81 ;
V_82 . type = V_154 ;
V_69 = F_85 ( V_9 , & V_82 , V_96 , V_97 ) ;
V_153 = & V_71 -> V_81 ;
V_153 -> type = V_155 ;
V_153 -> V_14 |= V_156 ;
switch ( V_153 -> V_14 & V_114 ) {
case V_118 :
V_153 -> time . V_117 += V_153 -> V_57 . V_157 . V_158 ;
break;
case V_116 :
V_153 -> time . time . V_159 += 1000000 * ( V_153 -> V_57 . V_157 . V_158 % 1000 ) ;
V_153 -> time . time . V_160 += V_153 -> V_57 . V_157 . V_158 / 1000 +
V_153 -> time . time . V_159 / 1000000000 ;
V_153 -> time . time . V_159 %= 1000000000 ;
break;
}
V_153 -> V_57 . V_157 . V_161 = V_153 -> V_57 . V_157 . V_162 ;
if ( F_88 ( V_71 , V_96 , V_97 ) < 0 )
F_58 ( V_71 ) ;
} else {
V_69 = F_85 ( V_9 , & V_71 -> V_81 , V_96 , V_97 ) ;
F_58 ( V_71 ) ;
}
F_64 ( V_9 ) ;
return V_69 ;
}
static int F_89 ( struct V_8 * V_9 ,
struct V_77 * V_81 ,
struct V_1 * V_1 , int V_163 ,
int V_96 , int V_97 )
{
struct V_70 * V_71 ;
int V_51 ;
if ( V_81 -> V_102 == V_151 ) {
V_81 -> V_92 . V_9 = V_151 ;
V_81 -> V_102 = V_103 ;
} else
#ifdef F_86
if ( V_81 -> V_102 == V_147 ) {
V_81 -> V_92 . V_9 = V_147 ;
V_81 -> V_102 = V_103 ;
}
#endif
if ( V_81 -> V_92 . V_9 == V_151 ) {
struct V_88 * V_133 = F_73 ( V_9 , V_81 -> V_104 . V_89 ) ;
if ( V_133 == NULL )
return - V_136 ;
F_75 ( V_133 ) ;
}
if ( F_72 ( V_81 ) ) {
if ( V_81 -> type == V_152 )
return - V_136 ;
return F_85 ( V_9 , V_81 , V_96 , V_97 ) ;
}
if ( F_90 ( V_81 -> V_102 , V_9 -> V_42 ) <= 0 )
return - V_136 ;
if ( ! F_2 ( V_9 ) )
return - V_72 ;
V_51 = F_91 ( V_9 -> V_10 , V_81 , & V_71 , ! V_163 || V_96 , V_1 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ( V_51 = F_88 ( V_71 , V_96 , V_97 ) ) < 0 ) {
F_58 ( V_71 ) ;
return V_51 ;
}
return 0 ;
}
static int F_92 ( struct V_77 * V_153 )
{
switch ( F_93 ( V_153 ) ) {
case V_101 :
if ( F_94 ( V_153 ) )
return - V_136 ;
break;
case V_164 :
if ( ! F_94 ( V_153 ) ||
( V_153 -> V_57 . V_83 . V_84 & ~ V_85 ) >= V_165 )
return - V_136 ;
break;
case V_166 :
if ( ! F_72 ( V_153 ) )
return - V_136 ;
break;
}
return 0 ;
}
static T_2 F_95 ( struct V_1 * V_1 , const char T_3 * V_65 ,
T_4 V_66 , T_5 * V_67 )
{
struct V_8 * V_9 = V_1 -> V_61 ;
int V_167 = 0 , V_84 ;
int V_51 = - V_136 ;
struct V_77 V_81 ;
if ( ! ( F_1 ( V_1 ) & V_5 ) )
return - V_72 ;
if ( F_50 ( ! V_9 ) )
return - V_72 ;
if ( ! V_9 -> V_56 || V_9 -> V_10 == NULL )
return - V_72 ;
if ( V_9 -> V_10 -> V_168 > 0 && ! F_2 ( V_9 ) ) {
if ( F_96 ( V_9 -> V_10 ) < 0 )
return - V_54 ;
}
while ( V_66 >= sizeof( struct V_77 ) ) {
V_84 = sizeof( V_81 ) ;
if ( F_97 ( & V_81 , V_65 , V_84 ) ) {
V_51 = - V_74 ;
break;
}
V_81 . V_104 . V_9 = V_9 -> V_42 ;
if ( F_92 ( & V_81 ) ) {
V_51 = - V_136 ;
break;
}
if ( V_81 . type == V_169 )
goto V_170;
else if ( F_98 ( & V_81 ) ) {
V_51 = - V_136 ;
break;
}
if ( F_55 ( & V_81 ) ) {
int V_171 = V_81 . V_57 . V_83 . V_84 & ~ V_85 ;
if ( ( T_4 ) ( V_171 + V_84 ) > V_66 ) {
V_51 = - V_136 ;
break;
}
V_81 . V_57 . V_83 . V_84 = V_171 | V_172 ;
V_81 . V_57 . V_83 . V_173 = ( char V_86 * ) V_65
+ sizeof( struct V_77 ) ;
V_84 += V_171 ;
} else {
#ifdef F_99
if ( V_9 -> V_174 && F_100 ( & V_81 ) ) {
void * V_173 = ( void V_86 * ) F_101 ( V_81 . V_57 . V_175 . V_176 [ 1 ] ) ;
V_81 . V_57 . V_83 . V_173 = V_173 ;
}
#endif
}
V_51 = F_89 ( V_9 , & V_81 , V_1 ,
! ( V_1 -> V_79 & V_80 ) ,
0 , 0 ) ;
if ( V_51 < 0 )
break;
V_170:
V_66 -= V_84 ;
V_65 += V_84 ;
V_167 += V_84 ;
}
return V_167 ? V_167 : V_51 ;
}
static unsigned int F_102 ( struct V_1 * V_1 , T_6 * V_177 )
{
struct V_8 * V_9 = V_1 -> V_61 ;
unsigned int V_178 = 0 ;
if ( F_50 ( ! V_9 ) )
return - V_72 ;
if ( ( F_1 ( V_1 ) & V_6 ) &&
V_9 -> V_57 . V_50 . V_58 ) {
if ( F_103 ( V_9 -> V_57 . V_50 . V_58 , V_1 , V_177 ) )
V_178 |= V_179 | V_180 ;
}
if ( F_1 ( V_1 ) & V_5 ) {
if ( ! F_2 ( V_9 ) ||
F_104 ( V_9 -> V_10 , V_1 , V_177 ) )
V_178 |= V_181 | V_182 ;
}
return V_178 ;
}
static int F_105 ( struct V_8 * V_9 , void * V_183 )
{
int * V_184 = V_183 ;
* V_184 = V_185 ;
return 0 ;
}
static int F_106 ( struct V_8 * V_9 , void * V_183 )
{
int * V_186 = V_183 ;
* V_186 = V_9 -> V_42 ;
return 0 ;
}
static int F_107 ( struct V_8 * V_9 , void * V_183 )
{
struct V_187 * V_141 = V_183 ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_188 = V_189 ;
V_141 -> V_190 = V_12 ;
V_141 -> V_191 = V_192 ;
V_141 -> V_193 = 256 ;
V_141 -> V_194 = V_46 . V_32 ;
V_141 -> V_195 = F_108 () ;
return 0 ;
}
static int F_109 ( struct V_8 * V_9 , void * V_183 )
{
struct V_196 * V_141 = V_183 ;
struct V_8 * V_197 ;
int V_51 = 0 ;
V_197 = F_6 ( V_141 -> V_9 ) ;
if ( V_197 == NULL )
return - V_120 ;
#ifdef F_110
if ( ! V_141 -> V_198 ) {
V_51 = - V_136 ;
goto V_199;
}
#else
if ( V_141 -> V_198 ) {
V_51 = - V_136 ;
goto V_199;
}
#endif
if ( V_141 -> V_200 > sizeof( long ) ) {
V_51 = - V_136 ;
goto V_199;
}
V_197 -> V_174 = ( V_141 -> V_200 < sizeof( long ) ) ;
V_199:
F_64 ( V_197 ) ;
return V_51 ;
}
static void F_111 ( struct V_8 * V_197 ,
struct V_201 * V_141 )
{
V_141 -> V_9 = V_197 -> V_42 ;
V_141 -> type = V_197 -> type ;
strcpy ( V_141 -> V_62 , V_197 -> V_62 ) ;
V_141 -> V_91 = V_197 -> V_91 ;
V_141 -> V_110 = V_197 -> V_110 ;
memcpy ( V_141 -> V_95 , V_197 -> V_95 , 32 ) ;
V_141 -> V_202 = V_197 -> V_202 ;
if ( V_197 -> type == V_44 )
V_141 -> V_203 = F_112 ( V_197 -> V_57 . V_50 . V_63 ) ;
else
V_141 -> V_203 = - 1 ;
if ( V_197 -> type == V_45 )
V_141 -> V_25 = V_197 -> V_57 . V_204 . V_25 ? V_197 -> V_57 . V_204 . V_25 -> V_42 : - 1 ;
else
V_141 -> V_25 = - 1 ;
memset ( V_141 -> V_205 , 0 , sizeof( V_141 -> V_205 ) ) ;
}
static int F_113 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_201 * V_206 = V_183 ;
struct V_8 * V_197 ;
V_197 = F_6 ( V_206 -> V_9 ) ;
if ( V_197 == NULL )
return - V_120 ;
F_111 ( V_197 , V_206 ) ;
F_64 ( V_197 ) ;
return 0 ;
}
static int F_114 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_201 * V_206 = V_183 ;
if ( V_9 -> V_42 != V_206 -> V_9 )
return - V_124 ;
if ( V_9 -> type != V_206 -> type )
return - V_136 ;
if ( V_206 -> V_62 [ 0 ] )
F_115 ( V_9 -> V_62 , V_206 -> V_62 , sizeof( V_9 -> V_62 ) ) ;
V_9 -> V_91 = V_206 -> V_91 ;
V_9 -> V_110 = V_206 -> V_110 ;
memcpy ( V_9 -> V_95 , V_206 -> V_95 , 32 ) ;
return 0 ;
}
static int F_116 ( struct V_8 * V_9 , void * V_183 )
{
struct V_207 * V_141 = V_183 ;
struct V_88 * V_89 ;
struct V_208 * V_209 ;
int V_210 ;
if ( V_141 -> V_146 . V_9 != V_9 -> V_42 )
return - V_124 ;
V_89 = F_117 ( V_9 , ( V_141 -> V_14 & V_211 ) ? V_141 -> V_146 . V_89 : - 1 ) ;
if ( V_89 == NULL )
return - V_54 ;
if ( V_9 -> type == V_44 && V_141 -> V_204 ) {
V_210 = V_89 -> V_146 . V_89 ;
F_75 ( V_89 ) ;
F_118 ( V_9 , V_210 ) ;
return - V_136 ;
}
if ( V_9 -> type == V_45 ) {
if ( ( V_209 = V_141 -> V_204 ) != NULL ) {
if ( V_209 -> V_63 )
V_89 -> V_63 = V_209 -> V_63 ;
V_89 -> V_61 = V_209 -> V_61 ;
V_89 -> V_212 = V_209 -> V_212 ;
V_89 -> V_128 = V_209 -> V_128 ;
V_89 -> V_137 . V_213 = V_209 -> V_214 ;
V_89 -> V_137 . V_215 = V_209 -> V_216 ;
V_89 -> V_217 . V_213 = V_209 -> V_218 ;
V_89 -> V_217 . V_215 = V_209 -> V_219 ;
}
}
V_141 -> V_146 = V_89 -> V_146 ;
F_119 ( V_89 , V_141 ) ;
F_120 ( V_89 -> V_146 . V_9 , V_89 -> V_146 . V_89 ) ;
F_75 ( V_89 ) ;
return 0 ;
}
static int F_121 ( struct V_8 * V_9 , void * V_183 )
{
struct V_207 * V_141 = V_183 ;
int V_51 ;
if ( V_141 -> V_146 . V_9 != V_9 -> V_42 )
return - V_124 ;
V_51 = F_118 ( V_9 , V_141 -> V_146 . V_89 ) ;
if ( V_51 >= 0 )
F_122 ( V_9 -> V_42 , V_141 -> V_146 . V_89 ) ;
return V_51 ;
}
static int F_123 ( struct V_8 * V_9 , void * V_183 )
{
struct V_207 * V_141 = V_183 ;
struct V_8 * V_197 ;
struct V_88 * V_89 ;
V_197 = F_6 ( V_141 -> V_146 . V_9 ) ;
if ( V_197 == NULL )
return - V_72 ;
V_89 = F_73 ( V_197 , V_141 -> V_146 . V_89 ) ;
if ( V_89 == NULL ) {
F_64 ( V_197 ) ;
return - V_120 ;
}
F_124 ( V_89 , V_141 ) ;
F_75 ( V_89 ) ;
F_64 ( V_197 ) ;
return 0 ;
}
static int F_125 ( struct V_8 * V_9 , void * V_183 )
{
struct V_207 * V_141 = V_183 ;
struct V_88 * V_89 ;
if ( V_141 -> V_146 . V_9 != V_9 -> V_42 )
return - V_124 ;
V_89 = F_73 ( V_9 , V_141 -> V_146 . V_89 ) ;
if ( V_89 ) {
F_119 ( V_89 , V_141 ) ;
F_75 ( V_89 ) ;
}
return 0 ;
}
static int F_126 ( struct V_8 * V_9 ,
struct V_88 * V_220 ,
struct V_88 * V_221 ,
struct V_222 * V_130 )
{
if ( V_9 -> V_42 != V_130 -> V_223 . V_9 &&
V_9 -> V_42 != V_130 -> V_92 . V_9 ) {
if ( F_61 ( V_220 , V_224 ) )
return - V_124 ;
if ( F_61 ( V_221 , V_224 ) )
return - V_124 ;
}
if ( V_9 -> V_42 != V_130 -> V_223 . V_9 ) {
if ( ! F_61 ( V_220 , V_225 ) )
return - V_124 ;
}
if ( V_9 -> V_42 != V_130 -> V_92 . V_9 ) {
if ( ! F_61 ( V_221 , V_226 ) )
return - V_124 ;
}
return 0 ;
}
int F_127 ( int V_9 , int V_89 ,
struct V_222 * V_141 ,
int V_227 )
{
struct V_77 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . type = V_227 ;
V_81 . V_57 . V_228 . V_92 = V_141 -> V_92 ;
V_81 . V_57 . V_228 . V_223 = V_141 -> V_223 ;
return F_128 ( V_9 , V_89 , & V_81 ) ;
}
static int F_129 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_222 * V_130 = V_183 ;
int V_69 = - V_136 ;
struct V_8 * V_229 = NULL , * V_223 = NULL ;
struct V_88 * V_220 = NULL , * V_221 = NULL ;
if ( ( V_229 = F_6 ( V_130 -> V_92 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_223 = F_6 ( V_130 -> V_223 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_220 = F_73 ( V_223 , V_130 -> V_223 . V_89 ) ) == NULL )
goto V_230;
if ( ( V_221 = F_73 ( V_229 , V_130 -> V_92 . V_89 ) ) == NULL )
goto V_230;
V_69 = F_126 ( V_9 , V_220 , V_221 , V_130 ) ;
if ( V_69 < 0 )
goto V_230;
V_69 = F_130 ( V_9 , V_223 , V_220 , V_229 , V_221 , V_130 ) ;
if ( ! V_69 )
F_127 ( V_151 , 0 ,
V_130 , V_231 ) ;
V_230:
if ( V_220 )
F_75 ( V_220 ) ;
if ( V_221 )
F_75 ( V_221 ) ;
if ( V_223 )
F_64 ( V_223 ) ;
if ( V_229 )
F_64 ( V_229 ) ;
return V_69 ;
}
static int F_131 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_222 * V_130 = V_183 ;
int V_69 = - V_72 ;
struct V_8 * V_229 = NULL , * V_223 = NULL ;
struct V_88 * V_220 = NULL , * V_221 = NULL ;
if ( ( V_229 = F_6 ( V_130 -> V_92 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_223 = F_6 ( V_130 -> V_223 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_220 = F_73 ( V_223 , V_130 -> V_223 . V_89 ) ) == NULL )
goto V_230;
if ( ( V_221 = F_73 ( V_229 , V_130 -> V_92 . V_89 ) ) == NULL )
goto V_230;
V_69 = F_126 ( V_9 , V_220 , V_221 , V_130 ) ;
if ( V_69 < 0 )
goto V_230;
V_69 = F_132 ( V_9 , V_223 , V_220 , V_229 , V_221 , V_130 ) ;
if ( ! V_69 )
F_127 ( V_151 , 0 ,
V_130 , V_232 ) ;
V_230:
if ( V_220 )
F_75 ( V_220 ) ;
if ( V_221 )
F_75 ( V_221 ) ;
if ( V_223 )
F_64 ( V_223 ) ;
if ( V_229 )
F_64 ( V_229 ) ;
return V_69 ;
}
static int F_133 ( struct V_8 * V_9 , void * V_183 )
{
struct V_233 * V_141 = V_183 ;
struct V_112 * V_113 ;
V_113 = F_134 ( V_9 -> V_42 , V_141 -> V_234 , V_141 -> V_14 ) ;
if ( F_135 ( V_113 ) )
return F_136 ( V_113 ) ;
V_141 -> V_102 = V_113 -> V_102 ;
V_141 -> V_234 = V_113 -> V_234 ;
V_141 -> V_63 = V_113 -> V_63 ;
if ( ! V_141 -> V_62 [ 0 ] )
snprintf ( V_141 -> V_62 , sizeof( V_141 -> V_62 ) , L_8 , V_113 -> V_102 ) ;
F_115 ( V_113 -> V_62 , V_141 -> V_62 , sizeof( V_113 -> V_62 ) ) ;
F_137 ( & V_113 -> V_28 ) ;
return 0 ;
}
static int F_138 ( struct V_8 * V_9 , void * V_183 )
{
struct V_233 * V_141 = V_183 ;
return F_139 ( V_9 -> V_42 , V_141 -> V_102 ) ;
}
static int F_140 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_233 * V_141 = V_183 ;
struct V_112 * V_113 ;
V_113 = F_68 ( V_141 -> V_102 ) ;
if ( V_113 == NULL )
return - V_136 ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_102 = V_113 -> V_102 ;
V_141 -> V_63 = V_113 -> V_63 ;
V_141 -> V_234 = V_113 -> V_234 ;
F_115 ( V_141 -> V_62 , V_113 -> V_62 , sizeof( V_141 -> V_62 ) ) ;
F_71 ( V_113 ) ;
return 0 ;
}
static int F_141 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_233 * V_141 = V_183 ;
struct V_112 * V_113 ;
if ( V_141 -> V_63 != V_9 -> V_42 )
return - V_136 ;
if ( F_142 ( V_141 -> V_102 , V_9 -> V_42 ) ) {
if ( F_143 ( V_141 -> V_102 , V_9 -> V_42 , V_141 -> V_234 ) < 0 )
return - V_124 ;
if ( V_141 -> V_234 )
F_144 ( V_141 -> V_102 , V_9 -> V_42 , 1 ) ;
} else {
return - V_124 ;
}
V_113 = F_68 ( V_141 -> V_102 ) ;
if ( ! V_113 )
return - V_136 ;
if ( V_113 -> V_63 != V_9 -> V_42 ) {
F_71 ( V_113 ) ;
return - V_124 ;
}
F_115 ( V_113 -> V_62 , V_141 -> V_62 , sizeof( V_113 -> V_62 ) ) ;
F_71 ( V_113 ) ;
return 0 ;
}
static int F_145 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_233 * V_141 = V_183 ;
struct V_112 * V_113 ;
V_113 = F_146 ( V_141 -> V_62 ) ;
if ( V_113 == NULL )
return - V_136 ;
V_141 -> V_102 = V_113 -> V_102 ;
V_141 -> V_63 = V_113 -> V_63 ;
V_141 -> V_234 = V_113 -> V_234 ;
F_71 ( V_113 ) ;
return 0 ;
}
static int F_147 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_235 * V_236 = V_183 ;
struct V_112 * V_102 ;
struct V_237 * V_238 ;
V_102 = F_68 ( V_236 -> V_102 ) ;
if ( V_102 == NULL )
return - V_136 ;
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
V_236 -> V_102 = V_102 -> V_102 ;
V_238 = V_102 -> V_115 ;
V_236 -> V_239 = V_102 -> V_240 -> V_241 + V_102 -> V_242 -> V_241 ;
V_236 -> time = F_69 ( V_238 ) ;
V_236 -> V_117 = F_70 ( V_238 ) ;
V_236 -> V_243 = V_238 -> V_243 ;
V_236 -> V_14 = V_102 -> V_14 ;
F_71 ( V_102 ) ;
return 0 ;
}
static int F_148 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_244 * V_245 = V_183 ;
struct V_112 * V_102 ;
struct V_237 * V_238 ;
V_102 = F_68 ( V_245 -> V_102 ) ;
if ( V_102 == NULL )
return - V_136 ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_102 = V_102 -> V_102 ;
V_238 = V_102 -> V_115 ;
V_245 -> V_245 = V_238 -> V_245 ;
V_245 -> V_246 = V_238 -> V_246 ;
V_245 -> V_247 = V_238 -> V_248 ;
V_245 -> V_249 = V_238 -> V_249 ;
F_71 ( V_102 ) ;
return 0 ;
}
int F_149 ( int V_9 , struct V_244 * V_245 )
{
if ( ! F_142 ( V_245 -> V_102 , V_9 ) )
return - V_124 ;
return F_150 ( V_245 -> V_102 , V_9 , V_245 ) ;
}
static int F_151 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_244 * V_245 = V_183 ;
int V_69 ;
V_69 = F_149 ( V_9 -> V_42 , V_245 ) ;
return V_69 < 0 ? V_69 : 0 ;
}
static int F_152 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_250 * V_115 = V_183 ;
struct V_112 * V_102 ;
struct V_237 * V_238 ;
V_102 = F_68 ( V_115 -> V_102 ) ;
if ( V_102 == NULL )
return - V_136 ;
if ( F_40 ( & V_102 -> V_251 ) ) {
F_71 ( V_102 ) ;
return - V_52 ;
}
V_238 = V_102 -> V_115 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_102 = V_102 -> V_102 ;
V_115 -> type = V_238 -> type ;
if ( V_238 -> type == V_252 ) {
V_115 -> V_253 . V_254 . V_255 = V_238 -> V_256 ;
V_115 -> V_253 . V_254 . V_257 = V_238 -> V_258 ;
}
F_36 ( & V_102 -> V_251 ) ;
F_71 ( V_102 ) ;
return 0 ;
}
static int F_153 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_250 * V_115 = V_183 ;
int V_69 = 0 ;
if ( V_115 -> type != V_252 )
return - V_136 ;
if ( F_142 ( V_115 -> V_102 , V_9 -> V_42 ) ) {
struct V_112 * V_113 ;
struct V_237 * V_238 ;
V_113 = F_68 ( V_115 -> V_102 ) ;
if ( V_113 == NULL )
return - V_72 ;
if ( F_40 ( & V_113 -> V_251 ) ) {
F_71 ( V_113 ) ;
return - V_52 ;
}
V_238 = V_113 -> V_115 ;
F_154 ( V_115 -> V_102 ) ;
V_238 -> type = V_115 -> type ;
if ( V_238 -> type == V_252 ) {
V_238 -> V_256 = V_115 -> V_253 . V_254 . V_255 ;
V_238 -> V_258 = V_115 -> V_253 . V_254 . V_257 ;
}
V_69 = F_155 ( V_115 -> V_102 ) ;
F_36 ( & V_113 -> V_251 ) ;
F_71 ( V_113 ) ;
} else {
return - V_124 ;
}
return V_69 ;
}
static int F_156 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_259 * V_141 = V_183 ;
int V_260 ;
V_260 = F_90 ( V_141 -> V_102 , V_9 -> V_42 ) ;
if ( V_260 < 0 )
return - V_136 ;
V_141 -> V_260 = V_260 ;
V_141 -> V_9 = V_9 -> V_42 ;
return 0 ;
}
static int F_157 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_259 * V_141 = V_183 ;
int V_51 ;
if ( V_141 -> V_260 >= 0 ) {
V_51 = F_144 ( V_141 -> V_102 , V_9 -> V_42 , V_141 -> V_260 ) ;
if ( V_51 < 0 )
return V_51 ;
}
return F_156 ( V_9 , V_183 ) ;
}
static int F_158 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_261 * V_141 = V_183 ;
struct V_8 * V_197 ;
V_197 = F_6 ( V_141 -> V_9 ) ;
if ( V_197 == NULL )
return - V_120 ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_9 = V_197 -> V_42 ;
V_141 -> V_262 = V_197 -> V_10 -> V_168 ;
V_141 -> V_263 = V_197 -> V_10 -> V_264 ;
V_141 -> V_265 = V_141 -> V_262 ;
V_141 -> V_265 = F_159 ( V_197 -> V_10 ) ;
if ( V_197 -> type == V_44 ) {
V_141 -> V_266 = V_197 -> V_57 . V_50 . V_59 ;
V_141 -> V_267 = V_141 -> V_266 ;
if ( V_197 -> V_57 . V_50 . V_58 )
V_141 -> V_267 = F_159 ( V_197 -> V_57 . V_50 . V_58 -> V_10 ) ;
} else {
V_141 -> V_266 = 0 ;
V_141 -> V_267 = 0 ;
}
F_64 ( V_197 ) ;
return 0 ;
}
static int F_160 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_261 * V_141 = V_183 ;
int V_268 ;
if ( V_9 -> V_42 != V_141 -> V_9 )
return - V_136 ;
if ( V_141 -> V_262 >= 1 && V_141 -> V_262 <= V_269 &&
( ! F_2 ( V_9 ) ||
V_141 -> V_262 != V_9 -> V_10 -> V_168 ) ) {
if ( F_2 ( V_9 ) ) {
F_161 ( V_9 -> V_10 ) ;
F_162 ( V_9 -> V_42 ) ;
F_163 ( V_9 -> V_10 ) ;
}
V_9 -> V_10 -> V_168 = V_141 -> V_262 ;
V_268 = F_96 ( V_9 -> V_10 ) ;
if ( V_268 < 0 )
return V_268 ;
}
if ( V_9 -> type == V_44 && V_9 -> V_57 . V_50 . V_58 != NULL &&
V_141 -> V_266 >= 1 &&
V_141 -> V_266 <= V_270 &&
V_141 -> V_266 != V_9 -> V_57 . V_50 . V_59 ) {
V_268 = F_164 ( V_9 -> V_57 . V_50 . V_58 , V_141 -> V_266 ) ;
if ( V_268 < 0 )
return V_268 ;
V_9 -> V_57 . V_50 . V_59 = V_141 -> V_266 ;
}
if ( V_141 -> V_263 >= 1 &&
V_141 -> V_263 <= V_9 -> V_10 -> V_168 ) {
V_9 -> V_10 -> V_264 = V_141 -> V_263 ;
}
return F_158 ( V_9 , V_183 ) ;
}
static int F_165 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_271 * V_141 = V_183 ;
if ( V_141 -> V_272 & V_273 ) {
if ( V_9 -> type == V_44 && V_9 -> V_57 . V_50 . V_58 )
F_52 ( V_9 -> V_57 . V_50 . V_58 ) ;
}
if ( V_141 -> V_272 & V_274 )
F_166 ( V_9 -> V_42 , V_141 ) ;
return 0 ;
}
static int F_167 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_222 * V_130 = V_183 ;
int V_69 ;
struct V_8 * V_223 = NULL ;
struct V_88 * V_220 = NULL ;
struct V_129 * V_275 ;
V_69 = - V_136 ;
if ( ( V_223 = F_6 ( V_130 -> V_223 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_220 = F_73 ( V_223 , V_130 -> V_223 . V_89 ) ) == NULL )
goto V_230;
V_275 = F_168 ( & V_220 -> V_137 , & V_130 -> V_92 ) ;
if ( V_275 ) {
V_69 = 0 ;
* V_130 = V_275 -> V_141 ;
} else
V_69 = - V_120 ;
V_230:
if ( V_220 )
F_75 ( V_220 ) ;
if ( V_223 )
F_64 ( V_223 ) ;
return V_69 ;
}
static int F_169 ( struct V_8 * V_9 , void * V_183 )
{
struct V_276 * V_130 = V_183 ;
int V_69 = - V_72 ;
struct V_8 * V_197 = NULL ;
struct V_88 * V_89 = NULL ;
struct V_134 * V_277 ;
struct V_278 * V_275 ;
int V_279 ;
if ( ( V_197 = F_6 ( V_130 -> V_280 . V_9 ) ) == NULL )
goto V_230;
if ( ( V_89 = F_73 ( V_197 , V_130 -> V_280 . V_89 ) ) == NULL )
goto V_230;
switch ( V_130 -> type ) {
case V_281 :
V_277 = & V_89 -> V_137 ;
break;
case V_282 :
V_277 = & V_89 -> V_217 ;
break;
default:
goto V_230;
}
F_170 ( & V_277 -> V_139 ) ;
V_130 -> V_283 = V_277 -> V_66 ;
V_279 = 0 ;
V_69 = - V_120 ;
F_171 (p, &group->list_head) {
if ( V_279 ++ == V_130 -> V_284 ) {
struct V_129 * V_285 ;
if ( V_130 -> type == V_281 ) {
V_285 = F_172 ( V_275 , struct V_129 , V_286 ) ;
V_130 -> V_146 = V_285 -> V_141 . V_92 ;
} else {
V_285 = F_172 ( V_275 , struct V_129 , V_287 ) ;
V_130 -> V_146 = V_285 -> V_141 . V_223 ;
}
V_130 -> V_14 = V_285 -> V_141 . V_14 ;
V_130 -> V_102 = V_285 -> V_141 . V_102 ;
V_69 = 0 ;
break;
}
}
F_81 ( & V_277 -> V_139 ) ;
V_230:
if ( V_89 )
F_75 ( V_89 ) ;
if ( V_197 )
F_64 ( V_197 ) ;
return V_69 ;
}
static int F_173 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_201 * V_141 = V_183 ;
struct V_8 * V_197 = NULL ;
V_141 -> V_9 ++ ;
if ( V_141 -> V_9 < 0 )
V_141 -> V_9 = 0 ;
for (; V_141 -> V_9 < V_12 ; V_141 -> V_9 ++ ) {
V_197 = F_6 ( V_141 -> V_9 ) ;
if ( V_197 )
break;
}
if ( V_197 == NULL )
return - V_120 ;
F_111 ( V_197 , V_141 ) ;
F_64 ( V_197 ) ;
return 0 ;
}
static int F_174 ( struct V_8 * V_9 ,
void * V_183 )
{
struct V_207 * V_141 = V_183 ;
struct V_8 * V_197 ;
struct V_88 * V_89 = NULL ;
V_197 = F_6 ( V_141 -> V_146 . V_9 ) ;
if ( V_197 == NULL )
return - V_72 ;
V_141 -> V_146 . V_89 ++ ;
V_89 = F_175 ( V_197 , V_141 ) ;
if ( V_89 == NULL ) {
F_64 ( V_197 ) ;
return - V_120 ;
}
V_141 -> V_146 = V_89 -> V_146 ;
F_124 ( V_89 , V_141 ) ;
F_75 ( V_89 ) ;
F_64 ( V_197 ) ;
return 0 ;
}
static long F_176 ( struct V_1 * V_1 , unsigned int V_288 ,
unsigned long V_183 )
{
struct V_8 * V_9 = V_1 -> V_61 ;
union {
int V_184 ;
int V_186 ;
struct V_187 V_289 ;
struct V_196 V_290 ;
struct V_201 V_206 ;
struct V_207 V_291 ;
struct V_222 V_292 ;
struct V_233 V_293 ;
struct V_235 V_294 ;
struct V_244 V_245 ;
struct V_250 V_295 ;
struct V_259 V_296 ;
struct V_261 V_297 ;
struct V_271 V_298 ;
struct V_276 V_299 ;
} V_65 ;
const struct V_300 * V_301 ;
unsigned long V_168 ;
int V_51 ;
if ( F_50 ( ! V_9 ) )
return - V_72 ;
for ( V_301 = V_302 ; V_301 -> V_288 > 0 ; ++ V_301 ) {
if ( V_301 -> V_288 == V_288 )
break;
}
if ( V_301 -> V_288 == 0 )
return - V_303 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_168 = F_177 ( V_301 -> V_288 ) ;
if ( V_301 -> V_288 & V_304 ) {
if ( F_97 ( & V_65 , ( const void T_3 * ) V_183 , V_168 ) )
return - V_74 ;
}
V_51 = V_301 -> V_305 ( V_9 , & V_65 ) ;
if ( V_51 >= 0 ) {
if ( V_301 -> V_288 == V_306 ||
V_301 -> V_288 == V_307 ||
( V_301 -> V_288 & V_308 ) )
if ( F_56 ( ( void T_3 * ) V_183 , & V_65 , V_168 ) )
return - V_74 ;
}
return V_51 ;
}
int F_178 ( struct V_309 * V_25 , int V_34 ,
const char * V_310 , ... )
{
struct V_8 * V_9 ;
T_7 args ;
if ( F_50 ( F_10 () ) )
return - V_311 ;
if ( V_25 && V_34 >= V_26 )
return - V_136 ;
if ( V_25 == NULL && V_34 >= V_19 )
return - V_136 ;
if ( F_40 ( & V_43 ) )
return - V_52 ;
if ( V_25 ) {
V_34 += V_19
+ V_25 -> V_42 * V_26 ;
if ( V_34 >= V_24 )
V_34 = - 1 ;
}
V_9 = F_18 ( V_34 , 0 ) ;
if ( V_9 == NULL ) {
F_36 ( & V_43 ) ;
return - V_311 ;
}
F_15 ( & V_46 , 1 ) ;
V_9 -> V_55 = 1 ;
V_9 -> V_56 = 1 ;
V_9 -> V_57 . V_204 . V_25 = V_25 ;
va_start ( args , V_310 ) ;
vsnprintf ( V_9 -> V_62 , sizeof( V_9 -> V_62 ) , V_310 , args ) ;
va_end ( args ) ;
V_9 -> type = V_45 ;
F_36 ( & V_43 ) ;
F_44 ( V_9 -> V_42 ) ;
return V_9 -> V_42 ;
}
int F_179 ( int V_9 )
{
struct V_8 * V_173 ;
if ( F_50 ( F_10 () ) )
return - V_311 ;
V_173 = F_4 ( V_9 ) ;
if ( V_173 == NULL )
return - V_136 ;
F_32 ( V_173 ) ;
F_21 ( V_173 ) ;
return 0 ;
}
static int F_180 ( int V_9 , struct V_77 * V_153 ,
struct V_1 * V_1 , int V_163 ,
int V_96 , int V_97 )
{
struct V_8 * V_197 ;
int V_69 ;
if ( F_50 ( ! V_153 ) )
return - V_136 ;
if ( V_153 -> type == V_169 )
return 0 ;
if ( V_153 -> type == V_100 )
return - V_136 ;
V_153 -> V_104 . V_9 = V_9 ;
if ( F_92 ( V_153 ) )
return - V_136 ;
V_197 = F_6 ( V_9 ) ;
if ( V_197 == NULL )
return - V_136 ;
if ( ! V_197 -> V_56 )
V_69 = - V_124 ;
else
V_69 = F_89 ( V_197 , V_153 , V_1 , V_163 , V_96 , V_97 ) ;
F_64 ( V_197 ) ;
return V_69 ;
}
int F_181 ( int V_9 , struct V_77 * V_153 ,
int V_96 , int V_97 )
{
return F_180 ( V_9 , V_153 , NULL , 0 , V_96 , V_97 ) ;
}
int F_182 ( int V_9 , struct V_77 * V_153 ,
struct V_1 * V_1 ,
int V_96 , int V_97 )
{
return F_180 ( V_9 , V_153 , V_1 , 1 , V_96 , V_97 ) ;
}
int F_183 ( int V_9 , struct V_77 * V_153 ,
int V_96 , int V_97 )
{
struct V_8 * V_197 ;
int V_69 ;
if ( F_50 ( ! V_153 ) )
return - V_136 ;
V_153 -> V_102 = V_103 ;
V_153 -> V_104 . V_9 = V_9 ;
if ( F_92 ( V_153 ) )
return - V_136 ;
V_197 = F_6 ( V_9 ) ;
if ( V_197 == NULL )
return - V_136 ;
if ( ! V_197 -> V_56 )
V_69 = - V_124 ;
else
V_69 = F_85 ( V_197 , V_153 , V_96 , V_97 ) ;
F_64 ( V_197 ) ;
return V_69 ;
}
int F_184 ( int V_11 , unsigned int V_288 , void * V_183 )
{
const struct V_300 * V_301 ;
struct V_8 * V_9 ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 == NULL )
return - V_72 ;
for ( V_301 = V_302 ; V_301 -> V_288 > 0 ; ++ V_301 ) {
if ( V_301 -> V_288 == V_288 )
return V_301 -> V_305 ( V_9 , V_183 ) ;
}
F_5 ( L_9 ,
V_288 , F_185 ( V_288 ) , F_186 ( V_288 ) ) ;
return - V_303 ;
}
int F_187 ( int V_11 , struct V_1 * V_1 , T_6 * V_177 )
{
struct V_8 * V_9 ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 == NULL )
return - V_72 ;
if ( ! F_2 ( V_9 ) )
return 1 ;
if ( F_104 ( V_9 -> V_10 , V_1 , V_177 ) )
return 1 ;
return 0 ;
}
static void F_188 ( struct V_312 * V_313 ,
struct V_134 * V_277 ,
int V_314 , char * V_315 )
{
struct V_278 * V_275 ;
struct V_129 * V_285 ;
int V_66 = 0 ;
F_170 ( & V_277 -> V_139 ) ;
if ( F_189 ( & V_277 -> V_278 ) ) {
F_81 ( & V_277 -> V_139 ) ;
return;
}
F_190 ( V_313 , V_315 ) ;
F_171 (p, &group->list_head) {
if ( V_314 )
V_285 = F_172 ( V_275 , struct V_129 , V_286 ) ;
else
V_285 = F_172 ( V_275 , struct V_129 , V_287 ) ;
if ( V_66 ++ )
F_190 ( V_313 , L_10 ) ;
F_190 ( V_313 , L_11 ,
V_314 ? V_285 -> V_141 . V_92 . V_9 : V_285 -> V_141 . V_223 . V_9 ,
V_314 ? V_285 -> V_141 . V_92 . V_89 : V_285 -> V_141 . V_223 . V_89 ) ;
if ( V_285 -> V_141 . V_14 & V_142 )
F_190 ( V_313 , L_12 , ( ( V_285 -> V_141 . V_14 & V_143 ) ? 'r' : 't' ) , V_285 -> V_141 . V_102 ) ;
if ( V_277 -> V_316 )
F_190 ( V_313 , L_13 ) ;
}
F_81 ( & V_277 -> V_139 ) ;
F_190 ( V_313 , L_14 ) ;
}
static void F_191 ( struct V_312 * V_313 ,
struct V_8 * V_9 )
{
struct V_88 * V_275 ;
F_33 ( & V_9 -> V_40 ) ;
F_79 (p, &client->ports_list_head, list) {
F_190 ( V_313 , L_15 ,
V_275 -> V_146 . V_89 , V_275 -> V_62 ,
F_192 ( V_275 -> V_90 ) ,
F_193 ( V_275 -> V_90 ) ,
F_194 ( V_275 -> V_90 ) ,
F_195 ( V_275 -> V_90 ) ) ;
F_188 ( V_313 , & V_275 -> V_137 , 1 , L_16 ) ;
F_188 ( V_313 , & V_275 -> V_217 , 0 , L_17 ) ;
}
F_36 ( & V_9 -> V_40 ) ;
}
void F_196 ( struct V_317 * V_318 ,
struct V_312 * V_313 )
{
int V_36 ;
struct V_8 * V_9 ;
F_190 ( V_313 , L_18 ) ;
F_190 ( V_313 , L_19 , V_46 . V_32 ) ;
F_190 ( V_313 , L_20 , V_46 . V_33 ) ;
F_190 ( V_313 , L_21 , V_12 ) ;
F_190 ( V_313 , L_14 ) ;
for ( V_36 = 0 ; V_36 < V_12 ; V_36 ++ ) {
V_9 = F_6 ( V_36 ) ;
if ( V_9 == NULL )
continue;
if ( V_9 -> type == V_38 ) {
F_64 ( V_9 ) ;
continue;
}
F_190 ( V_313 , L_22 ,
V_36 , V_9 -> V_62 ,
V_9 -> type == V_44 ? L_23 : L_24 ) ;
F_191 ( V_313 , V_9 ) ;
if ( F_2 ( V_9 ) ) {
F_190 ( V_313 , L_25 ) ;
F_197 ( V_313 , V_9 -> V_10 , L_26 ) ;
}
if ( V_9 -> type == V_44 && V_9 -> V_57 . V_50 . V_58 &&
V_9 -> V_57 . V_50 . V_58 -> V_10 ) {
F_190 ( V_313 , L_27 ) ;
F_197 ( V_313 , V_9 -> V_57 . V_50 . V_58 -> V_10 , L_26 ) ;
}
F_64 ( V_9 ) ;
}
}
int T_1 F_198 ( void )
{
int V_51 ;
F_199 ( & V_319 , NULL ) ;
F_200 ( & V_319 , L_28 ) ;
if ( F_40 ( & V_43 ) )
return - V_52 ;
V_51 = F_201 ( V_320 , NULL , 0 ,
& V_321 , NULL , & V_319 ) ;
if ( V_51 < 0 ) {
F_36 ( & V_43 ) ;
F_202 ( & V_319 ) ;
return V_51 ;
}
F_36 ( & V_43 ) ;
return 0 ;
}
void T_8 F_203 ( void )
{
F_204 ( & V_319 ) ;
F_202 ( & V_319 ) ;
}
