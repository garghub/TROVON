static inline T_1 F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( F_4 () ) ;
return V_1 ;
}
static inline void F_5 ( T_1 V_1 )
{
F_3 ( V_1 ) ;
}
static inline unsigned short F_6 ( struct V_2 * V_2 )
{
switch ( V_2 -> V_3 & ( V_4 | V_5 ) ) {
case V_5 :
return V_6 ;
case V_4 :
return V_7 ;
default:
return V_8 ;
}
}
static inline int F_7 ( struct V_9 * V_10 )
{
return F_8 ( V_10 -> V_11 ) > 0 ;
}
static struct V_9 * F_9 ( int V_12 )
{
if ( V_12 < 0 || V_12 >= V_13 ) {
F_10 ( L_1 ,
V_12 ) ;
return NULL ;
}
return V_14 [ V_12 ] ;
}
struct V_9 * F_11 ( int V_12 )
{
unsigned long V_15 ;
struct V_9 * V_10 ;
if ( V_12 < 0 || V_12 >= V_13 ) {
F_10 ( L_1 ,
V_12 ) ;
return NULL ;
}
F_12 ( & V_16 , V_15 ) ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 )
goto V_17;
if ( V_18 [ V_12 ] ) {
F_13 ( & V_16 , V_15 ) ;
return NULL ;
}
F_13 ( & V_16 , V_15 ) ;
#ifdef F_14
if ( ! F_15 () ) {
static char V_19 [ V_20 ] ;
static char V_21 [ V_22 ] ;
if ( V_12 < V_20 ) {
int V_23 ;
if ( ! V_19 [ V_12 ] ) {
V_19 [ V_12 ] = 1 ;
for ( V_23 = 0 ; V_23 < 15 ; V_23 ++ ) {
if ( V_24 [ V_23 ] < 0 )
break;
if ( V_24 [ V_23 ] == V_12 ) {
F_16 ( L_2 ,
V_12 ) ;
break;
}
}
}
} else if ( V_12 < V_25 ) {
int V_26 = ( V_12 - V_20 ) /
V_27 ;
if ( V_26 < V_28 ) {
if ( ! V_21 [ V_26 ] ) {
V_21 [ V_26 ] = 1 ;
F_17 ( V_26 ) ;
}
F_18 () ;
}
}
F_12 ( & V_16 , V_15 ) ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 )
goto V_17;
F_13 ( & V_16 , V_15 ) ;
}
#endif
return NULL ;
V_17:
F_19 ( & V_10 -> V_29 ) ;
F_13 ( & V_16 , V_15 ) ;
return V_10 ;
}
static void F_20 ( struct V_30 * V_31 , int V_32 )
{
V_31 -> V_33 += V_32 ;
if ( V_31 -> V_33 > V_31 -> V_34 )
V_31 -> V_34 = V_31 -> V_33 ;
}
static void F_21 ( struct V_30 * V_31 , int V_32 )
{
V_31 -> V_33 -= V_32 ;
}
int T_2 F_22 ( void )
{
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
return 0 ;
}
static struct V_9 * F_23 ( int V_35 , int V_36 )
{
unsigned long V_15 ;
int V_37 ;
struct V_9 * V_10 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_38 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_11 = F_25 ( V_36 ) ;
if ( V_10 -> V_11 == NULL ) {
F_26 ( V_10 ) ;
return NULL ;
}
V_10 -> type = V_39 ;
F_27 ( & V_10 -> V_29 ) ;
F_28 ( & V_10 -> V_40 ) ;
F_29 ( & V_10 -> V_41 ) ;
F_30 ( & V_10 -> V_42 ) ;
F_12 ( & V_16 , V_15 ) ;
if ( V_35 < 0 ) {
for ( V_37 = V_25 ;
V_37 < V_13 ;
V_37 ++ ) {
if ( V_14 [ V_37 ] || V_18 [ V_37 ] )
continue;
V_14 [ V_10 -> V_43 = V_37 ] = V_10 ;
F_13 ( & V_16 , V_15 ) ;
return V_10 ;
}
} else {
if ( V_14 [ V_35 ] == NULL && ! V_18 [ V_35 ] ) {
V_14 [ V_10 -> V_43 = V_35 ] = V_10 ;
F_13 ( & V_16 , V_15 ) ;
return V_10 ;
}
}
F_13 ( & V_16 , V_15 ) ;
F_31 ( & V_10 -> V_11 ) ;
F_26 ( V_10 ) ;
return NULL ;
}
static int F_32 ( struct V_9 * V_10 )
{
unsigned long V_15 ;
if ( ! V_10 )
return 0 ;
F_33 ( V_10 ) ;
F_34 ( V_10 -> V_43 ) ;
F_12 ( & V_16 , V_15 ) ;
V_18 [ V_10 -> V_43 ] = 1 ;
V_14 [ V_10 -> V_43 ] = NULL ;
F_13 ( & V_16 , V_15 ) ;
F_35 ( & V_10 -> V_29 ) ;
F_36 ( V_10 -> V_43 ) ;
if ( V_10 -> V_11 )
F_31 ( & V_10 -> V_11 ) ;
F_12 ( & V_16 , V_15 ) ;
V_18 [ V_10 -> V_43 ] = 0 ;
F_13 ( & V_16 , V_15 ) ;
return 0 ;
}
static void F_37 ( struct V_9 * V_10 )
{
F_38 ( & V_44 ) ;
switch ( V_10 -> type ) {
case V_39 :
F_39 ( L_3 ,
V_10 -> V_43 ) ;
break;
case V_45 :
case V_46 :
F_32 ( V_10 ) ;
F_21 ( & V_47 , 1 ) ;
break;
default:
F_40 ( L_4 ,
V_10 -> V_43 , V_10 -> type ) ;
}
F_41 ( & V_44 ) ;
F_42 ( V_10 -> V_43 ) ;
}
static int F_43 ( struct V_48 * V_48 , struct V_2 * V_2 )
{
int V_37 , V_49 ;
struct V_9 * V_10 ;
struct V_50 * V_51 ;
int V_52 ;
V_52 = F_44 ( V_48 , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_45 ( & V_44 ) )
return - V_53 ;
V_10 = F_23 ( - 1 , V_54 ) ;
if ( V_10 == NULL ) {
F_41 ( & V_44 ) ;
return - V_55 ;
}
V_49 = F_6 ( V_2 ) ;
if ( V_49 & V_7 )
V_10 -> V_56 = 1 ;
if ( V_49 & V_6 )
V_10 -> V_57 = 1 ;
V_51 = & V_10 -> V_58 . V_51 ;
V_51 -> V_59 = NULL ;
V_51 -> V_60 = 0 ;
if ( V_49 & V_7 ) {
V_51 -> V_60 = V_61 ;
V_51 -> V_59 = F_46 ( V_51 -> V_60 ) ;
if ( V_51 -> V_59 == NULL ) {
F_32 ( V_10 ) ;
F_26 ( V_10 ) ;
F_41 ( & V_44 ) ;
return - V_55 ;
}
}
F_20 ( & V_47 , 1 ) ;
V_10 -> type = V_45 ;
F_41 ( & V_44 ) ;
V_37 = V_10 -> V_43 ;
V_2 -> V_62 = V_10 ;
V_51 -> V_2 = V_2 ;
sprintf ( V_10 -> V_63 , L_5 , V_37 ) ;
V_10 -> V_58 . V_51 . V_64 = F_47 ( F_48 ( V_65 ) ) ;
F_49 ( V_37 ) ;
return 0 ;
}
static int F_50 ( struct V_48 * V_48 , struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
if ( V_10 ) {
F_37 ( V_10 ) ;
if ( V_10 -> V_58 . V_51 . V_59 )
F_51 ( & V_10 -> V_58 . V_51 . V_59 ) ;
F_52 ( V_10 -> V_58 . V_51 . V_64 ) ;
F_26 ( V_10 ) ;
}
return 0 ;
}
static T_3 F_53 ( struct V_2 * V_2 , char T_4 * V_66 , T_5 V_67 ,
T_6 * V_68 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
struct V_69 * V_59 ;
int V_52 ;
long V_70 = 0 ;
struct V_71 * V_72 ;
if ( ! ( F_6 ( V_2 ) & V_7 ) )
return - V_73 ;
if ( ! F_54 ( V_74 , V_66 , V_67 ) )
return - V_75 ;
if ( F_55 ( ! V_10 ) )
return - V_73 ;
if ( ! V_10 -> V_56 || ( V_59 = V_10 -> V_58 . V_51 . V_59 ) == NULL )
return - V_73 ;
if ( F_56 ( & V_59 -> V_76 ) > 0 ) {
F_57 ( V_59 ) ;
return - V_77 ;
}
V_72 = NULL ;
V_52 = 0 ;
F_58 ( V_59 ) ;
while ( V_67 >= sizeof( struct V_78 ) ) {
int V_79 ;
V_79 = ( V_2 -> V_80 & V_81 ) || V_70 > 0 ;
if ( ( V_52 = F_59 ( V_59 , & V_72 , V_79 ) ) < 0 ) {
break;
}
if ( F_60 ( & V_72 -> V_82 ) ) {
struct V_78 V_83 ;
V_83 = V_72 -> V_82 ;
V_83 . V_58 . V_84 . V_85 &= ~ V_86 ;
if ( F_61 ( V_66 , & V_83 , sizeof( struct V_78 ) ) ) {
V_52 = - V_75 ;
break;
}
V_67 -= sizeof( struct V_78 ) ;
V_66 += sizeof( struct V_78 ) ;
V_52 = F_62 ( & V_72 -> V_82 , V_67 ,
( char V_87 * ) V_66 , 0 ,
sizeof( struct V_78 ) ) ;
if ( V_52 < 0 )
break;
V_70 += V_52 ;
V_67 -= V_52 ;
V_66 += V_52 ;
} else {
if ( F_61 ( V_66 , & V_72 -> V_82 , sizeof( struct V_78 ) ) ) {
V_52 = - V_75 ;
break;
}
V_67 -= sizeof( struct V_78 ) ;
V_66 += sizeof( struct V_78 ) ;
}
F_63 ( V_72 ) ;
V_72 = NULL ;
V_70 += sizeof( struct V_78 ) ;
}
if ( V_52 < 0 ) {
if ( V_72 )
F_64 ( V_59 , V_72 ) ;
if ( V_52 == - V_88 && V_70 > 0 )
V_52 = 0 ;
}
F_65 ( V_59 ) ;
return ( V_52 < 0 ) ? V_52 : V_70 ;
}
static int F_66 ( struct V_89 * V_90 , unsigned int V_15 )
{
if ( ( V_90 -> V_91 & V_15 ) != V_15 )
return 0 ;
return V_15 ;
}
static struct V_9 * F_67 ( struct V_78 * V_82 ,
int V_92 )
{
struct V_9 * V_93 ;
V_93 = F_11 ( V_82 -> V_93 . V_10 ) ;
if ( V_93 == NULL )
return NULL ;
if ( ! V_93 -> V_56 )
goto V_94;
if ( ( V_93 -> V_92 & V_95 ) &&
! F_68 ( V_82 -> type , V_93 -> V_96 ) )
goto V_94;
if ( V_92 && ! ( V_93 -> V_92 & V_92 ) )
goto V_94;
return V_93 ;
V_94:
F_69 ( V_93 ) ;
return NULL ;
}
static int F_70 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_52 , int V_97 , int V_98 )
{
struct V_78 V_99 ;
int V_70 ;
if ( V_10 == NULL ||
! ( V_10 -> V_92 & V_100 ) ||
! V_10 -> V_56 )
return 0 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . type = V_101 ;
V_99 . V_15 = V_102 ;
V_99 . V_103 = V_104 ;
V_99 . V_105 . V_10 = V_106 ;
V_99 . V_105 . V_90 = V_107 ;
V_99 . V_93 . V_10 = V_10 -> V_43 ;
V_99 . V_93 . V_90 = V_82 -> V_105 . V_90 ;
V_99 . V_58 . V_108 . V_109 = V_82 -> V_93 ;
V_99 . V_58 . V_108 . V_82 = V_82 ;
V_99 . V_58 . V_108 . V_110 = - V_52 ;
V_70 = F_71 ( NULL , & V_99 , 0 , V_97 , V_98 + 1 ) ;
if ( V_70 < 0 ) {
V_10 -> V_111 ++ ;
return V_70 ;
}
return V_70 ;
}
static int F_72 ( struct V_78 * V_82 ,
int V_103 , int V_112 )
{
struct V_113 * V_114 ;
V_114 = F_73 ( V_103 ) ;
if ( ! V_114 )
return 0 ;
V_82 -> V_103 = V_103 ;
V_82 -> V_15 &= ~ V_115 ;
if ( V_112 ) {
V_82 -> time . time = F_74 ( V_114 -> V_116 ) ;
V_82 -> V_15 |= V_117 ;
} else {
V_82 -> time . V_118 = F_75 ( V_114 -> V_116 ) ;
V_82 -> V_15 |= V_119 ;
}
F_76 ( V_114 ) ;
return 1 ;
}
static int F_71 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_92 , int V_97 , int V_98 )
{
struct V_9 * V_93 = NULL ;
struct V_89 * V_120 = NULL ;
int V_70 = - V_121 ;
int V_122 ;
V_122 = F_77 ( V_82 ) ;
V_93 = F_67 ( V_82 , V_92 ) ;
if ( V_93 == NULL )
goto V_123;
V_120 = F_78 ( V_93 , V_82 -> V_93 . V_90 ) ;
if ( V_120 == NULL )
goto V_123;
if ( ! F_66 ( V_120 , V_124 ) ) {
V_70 = - V_125 ;
goto V_123;
}
if ( V_120 -> V_126 )
F_72 ( V_82 , V_120 -> V_127 ,
V_120 -> V_128 ) ;
switch ( V_93 -> type ) {
case V_45 :
if ( V_93 -> V_58 . V_51 . V_59 )
V_70 = F_79 ( V_93 -> V_58 . V_51 . V_59 , V_82 ) ;
break;
case V_46 :
if ( V_120 -> V_129 == NULL )
break;
V_70 = V_120 -> V_129 ( V_82 , V_122 ,
V_120 -> V_62 ,
V_97 , V_98 ) ;
break;
default:
break;
}
V_123:
if ( V_120 )
F_80 ( V_120 ) ;
if ( V_93 )
F_69 ( V_93 ) ;
if ( V_70 < 0 && ! V_122 ) {
V_70 = F_70 ( V_10 , V_82 , V_70 , V_97 , V_98 ) ;
}
return V_70 ;
}
static int F_81 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_97 , int V_98 )
{
struct V_130 * V_131 ;
int V_52 , V_70 = 0 , V_132 = 0 ;
struct V_78 V_133 ;
struct V_89 * V_134 ;
struct V_135 * V_136 ;
V_134 = F_78 ( V_10 , V_82 -> V_105 . V_90 ) ;
if ( V_134 == NULL )
return - V_137 ;
V_133 = * V_82 ;
V_136 = & V_134 -> V_138 ;
if ( V_97 )
F_82 ( & V_136 -> V_139 ) ;
else
F_83 ( & V_136 -> V_140 ) ;
F_84 (subs, &grp->list_head, src_list) {
if ( F_56 ( & V_131 -> V_141 ) != 2 )
continue;
V_82 -> V_93 = V_131 -> V_142 . V_93 ;
if ( V_131 -> V_142 . V_15 & V_143 )
F_72 ( V_82 , V_131 -> V_142 . V_103 ,
V_131 -> V_142 . V_15 & V_144 ) ;
V_52 = F_71 ( V_10 , V_82 ,
0 , V_97 , V_98 ) ;
if ( V_52 < 0 ) {
if ( ! V_70 )
V_70 = V_52 ;
continue;
}
V_132 ++ ;
* V_82 = V_133 ;
}
if ( V_97 )
F_85 ( & V_136 -> V_139 ) ;
else
F_86 ( & V_136 -> V_140 ) ;
* V_82 = V_133 ;
F_80 ( V_134 ) ;
return ( V_70 < 0 ) ? V_70 : V_132 ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_97 , int V_98 )
{
int V_132 = 0 , V_52 , V_70 = 0 ;
struct V_9 * V_145 ;
struct V_89 * V_90 ;
V_145 = F_67 ( V_82 , V_146 ) ;
if ( V_145 == NULL )
return 0 ;
F_82 ( & V_145 -> V_40 ) ;
F_84 (port, &dest_client->ports_list_head, list) {
V_82 -> V_93 . V_90 = V_90 -> V_147 . V_90 ;
V_52 = F_71 ( NULL , V_82 ,
V_146 ,
V_97 , V_98 ) ;
if ( V_52 < 0 ) {
if ( ! V_70 )
V_70 = V_52 ;
continue;
}
V_132 ++ ;
}
F_85 ( & V_145 -> V_40 ) ;
F_69 ( V_145 ) ;
V_82 -> V_93 . V_90 = V_148 ;
return ( V_70 < 0 ) ? V_70 : V_132 ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_78 * V_82 , int V_97 , int V_98 )
{
int V_52 , V_70 = 0 , V_132 = 0 ;
int V_93 ;
struct V_149 V_147 ;
V_147 = V_82 -> V_93 ;
for ( V_93 = 0 ; V_93 < V_13 ; V_93 ++ ) {
if ( V_93 == V_10 -> V_43 )
continue;
V_82 -> V_93 . V_10 = V_93 ;
V_82 -> V_93 . V_90 = V_147 . V_90 ;
if ( V_147 . V_90 == V_148 )
V_52 = F_87 ( V_10 , V_82 , V_97 , V_98 ) ;
else
V_52 = F_71 ( NULL , V_82 ,
V_146 ,
V_97 , V_98 ) ;
if ( V_52 < 0 ) {
if ( ! V_70 )
V_70 = V_52 ;
continue;
}
V_132 += V_52 ;
}
V_82 -> V_93 = V_147 ;
return ( V_70 < 0 ) ? V_70 : V_132 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_78 * V_82 ,
int V_97 , int V_98 )
{
F_10 ( L_6 ) ;
return 0 ;
}
static int F_90 ( struct V_9 * V_10 , struct V_78 * V_82 ,
int V_97 , int V_98 )
{
int V_70 ;
V_98 ++ ;
if ( V_98 >= V_150 ) {
F_10 ( L_7 ,
V_82 -> V_105 . V_10 , V_82 -> V_105 . V_90 ,
V_82 -> V_93 . V_10 , V_82 -> V_93 . V_90 ) ;
return - V_151 ;
}
if ( V_82 -> V_103 == V_152 ||
V_82 -> V_93 . V_10 == V_152 )
V_70 = F_81 ( V_10 , V_82 , V_97 , V_98 ) ;
#ifdef F_91
else if ( V_82 -> V_103 == V_148 ||
V_82 -> V_93 . V_10 == V_148 )
V_70 = F_88 ( V_10 , V_82 , V_97 , V_98 ) ;
else if ( V_82 -> V_93 . V_10 >= V_13 )
V_70 = F_89 ( V_10 , V_82 , V_97 , V_98 ) ;
else if ( V_82 -> V_93 . V_90 == V_148 )
V_70 = F_87 ( V_10 , V_82 , V_97 , V_98 ) ;
#endif
else
V_70 = F_71 ( V_10 , V_82 , 0 , V_97 , V_98 ) ;
return V_70 ;
}
int F_92 ( struct V_71 * V_72 , int V_97 , int V_98 )
{
struct V_9 * V_10 ;
int V_70 ;
if ( F_55 ( ! V_72 ) )
return - V_137 ;
V_10 = F_11 ( V_72 -> V_82 . V_105 . V_10 ) ;
if ( V_10 == NULL ) {
F_63 ( V_72 ) ;
return - V_137 ;
}
if ( V_72 -> V_82 . type == V_153 ) {
struct V_78 V_83 , * V_154 ;
V_83 = V_72 -> V_82 ;
V_83 . type = V_155 ;
V_70 = F_90 ( V_10 , & V_83 , V_97 , V_98 ) ;
V_154 = & V_72 -> V_82 ;
V_154 -> type = V_156 ;
V_154 -> V_15 |= V_157 ;
switch ( V_154 -> V_15 & V_115 ) {
case V_119 :
V_154 -> time . V_118 += V_154 -> V_58 . V_158 . V_159 ;
break;
case V_117 :
V_154 -> time . time . V_160 += 1000000 * ( V_154 -> V_58 . V_158 . V_159 % 1000 ) ;
V_154 -> time . time . V_161 += V_154 -> V_58 . V_158 . V_159 / 1000 +
V_154 -> time . time . V_160 / 1000000000 ;
V_154 -> time . time . V_160 %= 1000000000 ;
break;
}
V_154 -> V_58 . V_158 . V_162 = V_154 -> V_58 . V_158 . V_163 ;
if ( F_93 ( V_72 , V_97 , V_98 ) < 0 )
F_63 ( V_72 ) ;
} else {
V_70 = F_90 ( V_10 , & V_72 -> V_82 , V_97 , V_98 ) ;
F_63 ( V_72 ) ;
}
F_69 ( V_10 ) ;
return V_70 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
struct V_2 * V_2 , int V_164 ,
int V_97 , int V_98 )
{
struct V_71 * V_72 ;
int V_52 ;
if ( V_82 -> V_103 == V_152 ) {
V_82 -> V_93 . V_10 = V_152 ;
V_82 -> V_103 = V_104 ;
} else
#ifdef F_91
if ( V_82 -> V_103 == V_148 ) {
V_82 -> V_93 . V_10 = V_148 ;
V_82 -> V_103 = V_104 ;
}
#endif
if ( V_82 -> V_93 . V_10 == V_152 ) {
struct V_89 * V_134 = F_78 ( V_10 , V_82 -> V_105 . V_90 ) ;
if ( V_134 == NULL )
return - V_137 ;
F_80 ( V_134 ) ;
}
if ( F_77 ( V_82 ) ) {
if ( V_82 -> type == V_153 )
return - V_137 ;
return F_90 ( V_10 , V_82 , V_97 , V_98 ) ;
}
if ( F_95 ( V_82 -> V_103 , V_10 -> V_43 ) <= 0 )
return - V_137 ;
if ( ! F_7 ( V_10 ) )
return - V_73 ;
V_52 = F_96 ( V_10 -> V_11 , V_82 , & V_72 , ! V_164 || V_97 , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ( V_52 = F_93 ( V_72 , V_97 , V_98 ) ) < 0 ) {
F_63 ( V_72 ) ;
return V_52 ;
}
return 0 ;
}
static int F_97 ( struct V_78 * V_154 )
{
switch ( F_98 ( V_154 ) ) {
case V_102 :
if ( F_99 ( V_154 ) )
return - V_137 ;
break;
case V_165 :
if ( ! F_99 ( V_154 ) ||
( V_154 -> V_58 . V_84 . V_85 & ~ V_86 ) >= V_166 )
return - V_137 ;
break;
case V_167 :
if ( ! F_77 ( V_154 ) )
return - V_137 ;
break;
}
return 0 ;
}
static T_3 F_100 ( struct V_2 * V_2 , const char T_4 * V_66 ,
T_5 V_67 , T_6 * V_68 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
int V_168 = 0 , V_85 ;
int V_52 = - V_137 ;
struct V_78 V_82 ;
if ( ! ( F_6 ( V_2 ) & V_6 ) )
return - V_73 ;
if ( F_55 ( ! V_10 ) )
return - V_73 ;
if ( ! V_10 -> V_57 || V_10 -> V_11 == NULL )
return - V_73 ;
if ( V_10 -> V_11 -> V_169 > 0 && ! F_7 ( V_10 ) ) {
if ( F_101 ( V_10 -> V_11 ) < 0 )
return - V_55 ;
}
while ( V_67 >= sizeof( struct V_78 ) ) {
V_85 = sizeof( V_82 ) ;
if ( F_102 ( & V_82 , V_66 , V_85 ) ) {
V_52 = - V_75 ;
break;
}
V_82 . V_105 . V_10 = V_10 -> V_43 ;
if ( F_97 ( & V_82 ) ) {
V_52 = - V_137 ;
break;
}
if ( V_82 . type == V_170 )
goto V_171;
else if ( F_103 ( & V_82 ) ) {
V_52 = - V_137 ;
break;
}
if ( F_60 ( & V_82 ) ) {
int V_172 = V_82 . V_58 . V_84 . V_85 & ~ V_86 ;
if ( ( T_5 ) ( V_172 + V_85 ) > V_67 ) {
V_52 = - V_137 ;
break;
}
V_82 . V_58 . V_84 . V_85 = V_172 | V_173 ;
V_82 . V_58 . V_84 . V_174 = ( char V_87 * ) V_66
+ sizeof( struct V_78 ) ;
V_85 += V_172 ;
} else {
#ifdef F_104
if ( V_10 -> V_175 && F_105 ( & V_82 ) ) {
void * V_174 = ( void V_87 * ) F_106 ( V_82 . V_58 . V_176 . V_177 [ 1 ] ) ;
V_82 . V_58 . V_84 . V_174 = V_174 ;
}
#endif
}
V_52 = F_94 ( V_10 , & V_82 , V_2 ,
! ( V_2 -> V_80 & V_81 ) ,
0 , 0 ) ;
if ( V_52 < 0 )
break;
V_171:
V_67 -= V_85 ;
V_66 += V_85 ;
V_168 += V_85 ;
}
return V_168 ? V_168 : V_52 ;
}
static unsigned int F_107 ( struct V_2 * V_2 , T_7 * V_178 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
unsigned int V_179 = 0 ;
if ( F_55 ( ! V_10 ) )
return - V_73 ;
if ( ( F_6 ( V_2 ) & V_7 ) &&
V_10 -> V_58 . V_51 . V_59 ) {
if ( F_108 ( V_10 -> V_58 . V_51 . V_59 , V_2 , V_178 ) )
V_179 |= V_180 | V_181 ;
}
if ( F_6 ( V_2 ) & V_6 ) {
if ( ! F_7 ( V_10 ) ||
F_109 ( V_10 -> V_11 , V_2 , V_178 ) )
V_179 |= V_182 | V_183 ;
}
return V_179 ;
}
static int F_110 ( struct V_9 * V_10 , void T_4 * V_184 )
{
struct V_185 V_142 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_186 = V_187 ;
V_142 . V_188 = V_13 ;
V_142 . V_189 = V_190 ;
V_142 . V_191 = 256 ;
V_142 . V_192 = V_47 . V_33 ;
V_142 . V_193 = F_111 () ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_112 ( struct V_9 * V_10 , void T_4 * V_184 )
{
struct V_194 V_142 ;
struct V_9 * V_195 ;
int V_52 = 0 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_195 = F_11 ( V_142 . V_10 ) ;
if ( V_195 == NULL )
return - V_121 ;
#ifdef F_113
if ( ! V_142 . V_196 ) {
V_52 = - V_137 ;
goto V_197;
}
#else
if ( V_142 . V_196 ) {
V_52 = - V_137 ;
goto V_197;
}
#endif
if ( V_142 . V_198 > sizeof( long ) ) {
V_52 = - V_137 ;
goto V_197;
}
V_195 -> V_175 = ( V_142 . V_198 < sizeof( long ) ) ;
V_197:
F_69 ( V_195 ) ;
return V_52 ;
}
static void F_114 ( struct V_9 * V_195 ,
struct V_199 * V_142 )
{
V_142 -> V_10 = V_195 -> V_43 ;
V_142 -> type = V_195 -> type ;
strcpy ( V_142 -> V_63 , V_195 -> V_63 ) ;
V_142 -> V_92 = V_195 -> V_92 ;
V_142 -> V_111 = V_195 -> V_111 ;
memcpy ( V_142 -> V_96 , V_195 -> V_96 , 32 ) ;
V_142 -> V_200 = V_195 -> V_200 ;
if ( V_195 -> type == V_45 )
V_142 -> V_201 = F_115 ( V_195 -> V_58 . V_51 . V_64 ) ;
else
V_142 -> V_201 = - 1 ;
if ( V_195 -> type == V_46 )
V_142 -> V_26 = V_195 -> V_58 . V_202 . V_26 ? V_195 -> V_58 . V_202 . V_26 -> V_43 : - 1 ;
else
V_142 -> V_26 = - 1 ;
memset ( V_142 -> V_203 , 0 , sizeof( V_142 -> V_203 ) ) ;
}
static int F_116 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_9 * V_195 ;
struct V_199 V_204 ;
if ( F_102 ( & V_204 , V_184 , sizeof( V_204 ) ) )
return - V_75 ;
V_195 = F_11 ( V_204 . V_10 ) ;
if ( V_195 == NULL )
return - V_121 ;
F_114 ( V_195 , & V_204 ) ;
F_69 ( V_195 ) ;
if ( F_61 ( V_184 , & V_204 , sizeof( V_204 ) ) )
return - V_75 ;
return 0 ;
}
static int F_117 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_199 V_204 ;
if ( F_102 ( & V_204 , V_184 , sizeof( V_204 ) ) )
return - V_75 ;
if ( V_10 -> V_43 != V_204 . V_10 )
return - V_125 ;
if ( V_10 -> type != V_204 . type )
return - V_137 ;
if ( V_204 . V_63 [ 0 ] )
F_118 ( V_10 -> V_63 , V_204 . V_63 , sizeof( V_10 -> V_63 ) ) ;
V_10 -> V_92 = V_204 . V_92 ;
V_10 -> V_111 = V_204 . V_111 ;
memcpy ( V_10 -> V_96 , V_204 . V_96 , 32 ) ;
return 0 ;
}
static int F_119 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_89 * V_90 ;
struct V_205 V_142 ;
struct V_206 * V_207 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_147 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_90 = F_120 ( V_10 , ( V_142 . V_15 & V_208 ) ? V_142 . V_147 . V_90 : - 1 ) ;
if ( V_90 == NULL )
return - V_55 ;
if ( V_10 -> type == V_45 && V_142 . V_202 ) {
F_121 ( V_10 , V_90 -> V_147 . V_90 ) ;
return - V_137 ;
}
if ( V_10 -> type == V_46 ) {
if ( ( V_207 = V_142 . V_202 ) != NULL ) {
if ( V_207 -> V_64 )
V_90 -> V_64 = V_207 -> V_64 ;
V_90 -> V_62 = V_207 -> V_62 ;
V_90 -> V_209 = V_207 -> V_209 ;
V_90 -> V_129 = V_207 -> V_129 ;
V_90 -> V_138 . V_210 = V_207 -> V_211 ;
V_90 -> V_138 . V_212 = V_207 -> V_213 ;
V_90 -> V_214 . V_210 = V_207 -> V_215 ;
V_90 -> V_214 . V_212 = V_207 -> V_216 ;
}
}
V_142 . V_147 = V_90 -> V_147 ;
F_122 ( V_90 , & V_142 ) ;
F_123 ( V_90 -> V_147 . V_10 , V_90 -> V_147 . V_90 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_124 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_205 V_142 ;
int V_52 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_147 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_52 = F_121 ( V_10 , V_142 . V_147 . V_90 ) ;
if ( V_52 >= 0 )
F_125 ( V_10 -> V_43 , V_142 . V_147 . V_90 ) ;
return V_52 ;
}
static int F_126 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_9 * V_195 ;
struct V_89 * V_90 ;
struct V_205 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_195 = F_11 ( V_142 . V_147 . V_10 ) ;
if ( V_195 == NULL )
return - V_73 ;
V_90 = F_78 ( V_195 , V_142 . V_147 . V_90 ) ;
if ( V_90 == NULL ) {
F_69 ( V_195 ) ;
return - V_121 ;
}
F_127 ( V_90 , & V_142 ) ;
F_80 ( V_90 ) ;
F_69 ( V_195 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_128 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_89 * V_90 ;
struct V_205 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_147 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_90 = F_78 ( V_10 , V_142 . V_147 . V_90 ) ;
if ( V_90 ) {
F_122 ( V_90 , & V_142 ) ;
F_80 ( V_90 ) ;
}
return 0 ;
}
static int F_129 ( struct V_9 * V_10 ,
struct V_89 * V_217 ,
struct V_89 * V_218 ,
struct V_219 * V_131 )
{
if ( V_10 -> V_43 != V_131 -> V_220 . V_10 &&
V_10 -> V_43 != V_131 -> V_93 . V_10 ) {
if ( F_66 ( V_217 , V_221 ) )
return - V_125 ;
if ( F_66 ( V_218 , V_221 ) )
return - V_125 ;
}
if ( V_10 -> V_43 != V_131 -> V_220 . V_10 ) {
if ( ! F_66 ( V_217 , V_222 ) )
return - V_125 ;
}
if ( V_10 -> V_43 != V_131 -> V_93 . V_10 ) {
if ( ! F_66 ( V_218 , V_223 ) )
return - V_125 ;
}
return 0 ;
}
int F_130 ( int V_10 , int V_90 ,
struct V_219 * V_142 ,
int V_224 )
{
struct V_78 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . type = V_224 ;
V_82 . V_58 . V_225 . V_93 = V_142 -> V_93 ;
V_82 . V_58 . V_225 . V_220 = V_142 -> V_220 ;
return F_131 ( V_10 , V_90 , & V_82 ) ;
}
static int F_132 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 = - V_137 ;
struct V_9 * V_226 = NULL , * V_220 = NULL ;
struct V_89 * V_217 = NULL , * V_218 = NULL ;
struct V_219 V_131 ;
if ( F_102 ( & V_131 , V_184 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_226 = F_11 ( V_131 . V_93 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_220 = F_11 ( V_131 . V_220 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_217 = F_78 ( V_220 , V_131 . V_220 . V_90 ) ) == NULL )
goto V_227;
if ( ( V_218 = F_78 ( V_226 , V_131 . V_93 . V_90 ) ) == NULL )
goto V_227;
V_70 = F_129 ( V_10 , V_217 , V_218 , & V_131 ) ;
if ( V_70 < 0 )
goto V_227;
V_70 = F_133 ( V_10 , V_220 , V_217 , V_226 , V_218 , & V_131 ) ;
if ( ! V_70 )
F_130 ( V_152 , 0 ,
& V_131 , V_228 ) ;
V_227:
if ( V_217 )
F_80 ( V_217 ) ;
if ( V_218 )
F_80 ( V_218 ) ;
if ( V_220 )
F_69 ( V_220 ) ;
if ( V_226 )
F_69 ( V_226 ) ;
return V_70 ;
}
static int F_134 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 = - V_73 ;
struct V_9 * V_226 = NULL , * V_220 = NULL ;
struct V_89 * V_217 = NULL , * V_218 = NULL ;
struct V_219 V_131 ;
if ( F_102 ( & V_131 , V_184 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_226 = F_11 ( V_131 . V_93 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_220 = F_11 ( V_131 . V_220 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_217 = F_78 ( V_220 , V_131 . V_220 . V_90 ) ) == NULL )
goto V_227;
if ( ( V_218 = F_78 ( V_226 , V_131 . V_93 . V_90 ) ) == NULL )
goto V_227;
V_70 = F_129 ( V_10 , V_217 , V_218 , & V_131 ) ;
if ( V_70 < 0 )
goto V_227;
V_70 = F_135 ( V_10 , V_220 , V_217 , V_226 , V_218 , & V_131 ) ;
if ( ! V_70 )
F_130 ( V_152 , 0 ,
& V_131 , V_229 ) ;
V_227:
if ( V_217 )
F_80 ( V_217 ) ;
if ( V_218 )
F_80 ( V_218 ) ;
if ( V_220 )
F_69 ( V_220 ) ;
if ( V_226 )
F_69 ( V_226 ) ;
return V_70 ;
}
static int F_136 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_230 V_142 ;
int V_70 ;
struct V_113 * V_114 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_70 = F_137 ( V_10 -> V_43 , V_142 . V_231 , V_142 . V_15 ) ;
if ( V_70 < 0 )
return V_70 ;
V_114 = F_73 ( V_70 ) ;
if ( V_114 == NULL )
return - V_137 ;
V_142 . V_103 = V_114 -> V_103 ;
V_142 . V_231 = V_114 -> V_231 ;
V_142 . V_64 = V_114 -> V_64 ;
if ( ! V_142 . V_63 [ 0 ] )
snprintf ( V_142 . V_63 , sizeof( V_142 . V_63 ) , L_8 , V_114 -> V_103 ) ;
F_118 ( V_114 -> V_63 , V_142 . V_63 , sizeof( V_114 -> V_63 ) ) ;
F_76 ( V_114 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_138 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_230 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
return F_139 ( V_10 -> V_43 , V_142 . V_103 ) ;
}
static int F_140 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_230 V_142 ;
struct V_113 * V_114 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_114 = F_73 ( V_142 . V_103 ) ;
if ( V_114 == NULL )
return - V_137 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_103 = V_114 -> V_103 ;
V_142 . V_64 = V_114 -> V_64 ;
V_142 . V_231 = V_114 -> V_231 ;
F_118 ( V_142 . V_63 , V_114 -> V_63 , sizeof( V_142 . V_63 ) ) ;
F_76 ( V_114 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_141 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_230 V_142 ;
struct V_113 * V_114 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_64 != V_10 -> V_43 )
return - V_137 ;
if ( F_142 ( V_142 . V_103 , V_10 -> V_43 ) ) {
if ( F_143 ( V_142 . V_103 , V_10 -> V_43 , V_142 . V_231 ) < 0 )
return - V_125 ;
if ( V_142 . V_231 )
F_144 ( V_142 . V_103 , V_10 -> V_43 , 1 ) ;
} else {
return - V_125 ;
}
V_114 = F_73 ( V_142 . V_103 ) ;
if ( ! V_114 )
return - V_137 ;
if ( V_114 -> V_64 != V_10 -> V_43 ) {
F_76 ( V_114 ) ;
return - V_125 ;
}
F_118 ( V_114 -> V_63 , V_142 . V_63 , sizeof( V_114 -> V_63 ) ) ;
F_76 ( V_114 ) ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 , void T_4 * V_184 )
{
struct V_230 V_142 ;
struct V_113 * V_114 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_114 = F_146 ( V_142 . V_63 ) ;
if ( V_114 == NULL )
return - V_137 ;
V_142 . V_103 = V_114 -> V_103 ;
V_142 . V_64 = V_114 -> V_64 ;
V_142 . V_231 = V_114 -> V_231 ;
F_76 ( V_114 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_147 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_232 V_233 ;
struct V_113 * V_103 ;
struct V_234 * V_235 ;
if ( F_102 ( & V_233 , V_184 , sizeof( V_233 ) ) )
return - V_75 ;
V_103 = F_73 ( V_233 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
V_233 . V_103 = V_103 -> V_103 ;
V_235 = V_103 -> V_116 ;
V_233 . V_236 = V_103 -> V_237 -> V_238 + V_103 -> V_239 -> V_238 ;
V_233 . time = F_74 ( V_235 ) ;
V_233 . V_118 = F_75 ( V_235 ) ;
V_233 . V_240 = V_235 -> V_240 ;
V_233 . V_15 = V_103 -> V_15 ;
F_76 ( V_103 ) ;
if ( F_61 ( V_184 , & V_233 , sizeof( V_233 ) ) )
return - V_75 ;
return 0 ;
}
static int F_148 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_241 V_242 ;
struct V_113 * V_103 ;
struct V_234 * V_235 ;
if ( F_102 ( & V_242 , V_184 , sizeof( V_242 ) ) )
return - V_75 ;
V_103 = F_73 ( V_242 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_242 . V_103 = V_103 -> V_103 ;
V_235 = V_103 -> V_116 ;
V_242 . V_242 = V_235 -> V_242 ;
V_242 . V_243 = V_235 -> V_243 ;
V_242 . V_244 = V_235 -> V_245 ;
V_242 . V_246 = V_235 -> V_246 ;
F_76 ( V_103 ) ;
if ( F_61 ( V_184 , & V_242 , sizeof( V_242 ) ) )
return - V_75 ;
return 0 ;
}
int F_149 ( int V_10 , struct V_241 * V_242 )
{
if ( ! F_142 ( V_242 -> V_103 , V_10 ) )
return - V_125 ;
return F_150 ( V_242 -> V_103 , V_10 , V_242 ) ;
}
static int F_151 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 ;
struct V_241 V_242 ;
if ( F_102 ( & V_242 , V_184 , sizeof( V_242 ) ) )
return - V_75 ;
V_70 = F_149 ( V_10 -> V_43 , & V_242 ) ;
return V_70 < 0 ? V_70 : 0 ;
}
static int F_152 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_247 V_116 ;
struct V_113 * V_103 ;
struct V_234 * V_235 ;
if ( F_102 ( & V_116 , V_184 , sizeof( V_116 ) ) )
return - V_75 ;
V_103 = F_73 ( V_116 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
if ( F_45 ( & V_103 -> V_248 ) ) {
F_76 ( V_103 ) ;
return - V_53 ;
}
V_235 = V_103 -> V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_103 = V_103 -> V_103 ;
V_116 . type = V_235 -> type ;
if ( V_235 -> type == V_249 ) {
V_116 . V_250 . V_251 . V_252 = V_235 -> V_253 ;
V_116 . V_250 . V_251 . V_254 = V_235 -> V_255 ;
}
F_41 ( & V_103 -> V_248 ) ;
F_76 ( V_103 ) ;
if ( F_61 ( V_184 , & V_116 , sizeof( V_116 ) ) )
return - V_75 ;
return 0 ;
}
static int F_153 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 = 0 ;
struct V_247 V_116 ;
if ( F_102 ( & V_116 , V_184 , sizeof( V_116 ) ) )
return - V_75 ;
if ( V_116 . type != V_249 )
return - V_137 ;
if ( F_142 ( V_116 . V_103 , V_10 -> V_43 ) ) {
struct V_113 * V_114 ;
struct V_234 * V_235 ;
V_114 = F_73 ( V_116 . V_103 ) ;
if ( V_114 == NULL )
return - V_73 ;
if ( F_45 ( & V_114 -> V_248 ) ) {
F_76 ( V_114 ) ;
return - V_53 ;
}
V_235 = V_114 -> V_116 ;
F_154 ( V_116 . V_103 ) ;
V_235 -> type = V_116 . type ;
if ( V_235 -> type == V_249 ) {
V_235 -> V_253 = V_116 . V_250 . V_251 . V_252 ;
V_235 -> V_255 = V_116 . V_250 . V_251 . V_254 ;
}
V_70 = F_155 ( V_116 . V_103 ) ;
F_41 ( & V_114 -> V_248 ) ;
F_76 ( V_114 ) ;
} else {
return - V_125 ;
}
return V_70 ;
}
static int F_156 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_256 V_142 ;
int V_257 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_257 = F_95 ( V_142 . V_103 , V_10 -> V_43 ) ;
if ( V_257 < 0 )
return - V_137 ;
V_142 . V_257 = V_257 ;
V_142 . V_10 = V_10 -> V_43 ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_157 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_52 ;
struct V_256 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_257 >= 0 ) {
V_52 = F_144 ( V_142 . V_103 , V_10 -> V_43 , V_142 . V_257 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return F_156 ( V_10 , V_184 ) ;
}
static int F_158 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_258 V_142 ;
struct V_9 * V_195 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_195 = F_11 ( V_142 . V_10 ) ;
if ( V_195 == NULL )
return - V_121 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_10 = V_195 -> V_43 ;
V_142 . V_259 = V_195 -> V_11 -> V_169 ;
V_142 . V_260 = V_195 -> V_11 -> V_261 ;
V_142 . V_262 = V_142 . V_259 ;
V_142 . V_262 = F_159 ( V_195 -> V_11 ) ;
if ( V_195 -> type == V_45 ) {
V_142 . V_263 = V_195 -> V_58 . V_51 . V_60 ;
V_142 . V_264 = V_142 . V_263 ;
if ( V_195 -> V_58 . V_51 . V_59 )
V_142 . V_264 = F_159 ( V_195 -> V_58 . V_51 . V_59 -> V_11 ) ;
} else {
V_142 . V_263 = 0 ;
V_142 . V_264 = 0 ;
}
F_69 ( V_195 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_160 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_258 V_142 ;
int V_265 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_10 -> V_43 != V_142 . V_10 )
return - V_137 ;
if ( V_142 . V_259 >= 1 && V_142 . V_259 <= V_266 &&
( ! F_7 ( V_10 ) ||
V_142 . V_259 != V_10 -> V_11 -> V_169 ) ) {
if ( F_7 ( V_10 ) ) {
F_161 ( V_10 -> V_43 ) ;
F_162 ( V_10 -> V_11 ) ;
}
V_10 -> V_11 -> V_169 = V_142 . V_259 ;
V_265 = F_101 ( V_10 -> V_11 ) ;
if ( V_265 < 0 )
return V_265 ;
}
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 != NULL &&
V_142 . V_263 >= 1 &&
V_142 . V_263 <= V_267 &&
V_142 . V_263 != V_10 -> V_58 . V_51 . V_60 ) {
V_265 = F_163 ( V_10 -> V_58 . V_51 . V_59 , V_142 . V_263 ) ;
if ( V_265 < 0 )
return V_265 ;
V_10 -> V_58 . V_51 . V_60 = V_142 . V_263 ;
}
if ( V_142 . V_260 >= 1 &&
V_142 . V_260 <= V_10 -> V_11 -> V_169 ) {
V_10 -> V_11 -> V_261 = V_142 . V_260 ;
}
return F_158 ( V_10 , V_184 ) ;
}
static int F_164 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_268 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
if ( V_142 . V_269 & V_270 ) {
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 )
F_57 ( V_10 -> V_58 . V_51 . V_59 ) ;
}
if ( V_142 . V_269 & V_271 )
F_165 ( V_10 -> V_43 , & V_142 ) ;
return 0 ;
}
static int F_166 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 ;
struct V_9 * V_220 = NULL ;
struct V_89 * V_217 = NULL ;
struct V_219 V_131 ;
struct V_130 * V_272 ;
if ( F_102 ( & V_131 , V_184 , sizeof( V_131 ) ) )
return - V_75 ;
V_70 = - V_137 ;
if ( ( V_220 = F_11 ( V_131 . V_220 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_217 = F_78 ( V_220 , V_131 . V_220 . V_90 ) ) == NULL )
goto V_227;
V_272 = F_167 ( & V_217 -> V_138 , & V_131 . V_93 ) ;
if ( V_272 ) {
V_70 = 0 ;
V_131 = V_272 -> V_142 ;
} else
V_70 = - V_121 ;
V_227:
if ( V_217 )
F_80 ( V_217 ) ;
if ( V_220 )
F_69 ( V_220 ) ;
if ( V_70 >= 0 ) {
if ( F_61 ( V_184 , & V_131 , sizeof( V_131 ) ) )
return - V_75 ;
}
return V_70 ;
}
static int F_168 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
int V_70 = - V_73 ;
struct V_9 * V_195 = NULL ;
struct V_89 * V_90 = NULL ;
struct V_273 V_131 ;
struct V_135 * V_274 ;
struct V_275 * V_272 ;
int V_276 ;
if ( F_102 ( & V_131 , V_184 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_195 = F_11 ( V_131 . V_277 . V_10 ) ) == NULL )
goto V_227;
if ( ( V_90 = F_78 ( V_195 , V_131 . V_277 . V_90 ) ) == NULL )
goto V_227;
switch ( V_131 . type ) {
case V_278 :
V_274 = & V_90 -> V_138 ;
break;
case V_279 :
V_274 = & V_90 -> V_214 ;
break;
default:
goto V_227;
}
F_83 ( & V_274 -> V_140 ) ;
V_131 . V_280 = V_274 -> V_67 ;
V_276 = 0 ;
V_70 = - V_121 ;
F_169 (p, &group->list_head) {
if ( V_276 ++ == V_131 . V_281 ) {
struct V_130 * V_282 ;
if ( V_131 . type == V_278 ) {
V_282 = F_170 ( V_272 , struct V_130 , V_283 ) ;
V_131 . V_147 = V_282 -> V_142 . V_93 ;
} else {
V_282 = F_170 ( V_272 , struct V_130 , V_284 ) ;
V_131 . V_147 = V_282 -> V_142 . V_220 ;
}
V_131 . V_15 = V_282 -> V_142 . V_15 ;
V_131 . V_103 = V_282 -> V_142 . V_103 ;
V_70 = 0 ;
break;
}
}
F_86 ( & V_274 -> V_140 ) ;
V_227:
if ( V_90 )
F_80 ( V_90 ) ;
if ( V_195 )
F_69 ( V_195 ) ;
if ( V_70 >= 0 ) {
if ( F_61 ( V_184 , & V_131 , sizeof( V_131 ) ) )
return - V_75 ;
}
return V_70 ;
}
static int F_171 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_9 * V_195 = NULL ;
struct V_199 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_142 . V_10 ++ ;
if ( V_142 . V_10 < 0 )
V_142 . V_10 = 0 ;
for (; V_142 . V_10 < V_13 ; V_142 . V_10 ++ ) {
V_195 = F_11 ( V_142 . V_10 ) ;
if ( V_195 )
break;
}
if ( V_195 == NULL )
return - V_121 ;
F_114 ( V_195 , & V_142 ) ;
F_69 ( V_195 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_172 ( struct V_9 * V_10 ,
void T_4 * V_184 )
{
struct V_9 * V_195 ;
struct V_89 * V_90 = NULL ;
struct V_205 V_142 ;
if ( F_102 ( & V_142 , V_184 , sizeof( V_142 ) ) )
return - V_75 ;
V_195 = F_11 ( V_142 . V_147 . V_10 ) ;
if ( V_195 == NULL )
return - V_73 ;
V_142 . V_147 . V_90 ++ ;
V_90 = F_173 ( V_195 , & V_142 ) ;
if ( V_90 == NULL ) {
F_69 ( V_195 ) ;
return - V_121 ;
}
V_142 . V_147 = V_90 -> V_147 ;
F_127 ( V_90 , & V_142 ) ;
F_80 ( V_90 ) ;
F_69 ( V_195 ) ;
if ( F_61 ( V_184 , & V_142 , sizeof( V_142 ) ) )
return - V_75 ;
return 0 ;
}
static int F_174 ( struct V_9 * V_10 , unsigned int V_285 ,
void T_4 * V_184 )
{
struct V_286 * V_272 ;
switch ( V_285 ) {
case V_287 :
return F_175 ( V_288 , ( int T_4 * ) V_184 ) ? - V_75 : 0 ;
case V_289 :
return F_175 ( V_10 -> V_43 , ( int T_4 * ) V_184 ) ? - V_75 : 0 ;
}
if ( ! V_184 )
return - V_75 ;
for ( V_272 = V_290 ; V_272 -> V_285 ; V_272 ++ ) {
if ( V_272 -> V_285 == V_285 )
return V_272 -> V_291 ( V_10 , V_184 ) ;
}
F_10 ( L_9 ,
V_285 , F_176 ( V_285 ) , F_177 ( V_285 ) ) ;
return - V_292 ;
}
static long F_178 ( struct V_2 * V_2 , unsigned int V_285 , unsigned long V_184 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
if ( F_55 ( ! V_10 ) )
return - V_73 ;
return F_174 ( V_10 , V_285 , ( void T_4 * ) V_184 ) ;
}
int F_179 ( struct V_293 * V_26 , int V_35 ,
const char * V_294 , ... )
{
struct V_9 * V_10 ;
T_8 args ;
if ( F_55 ( F_15 () ) )
return - V_295 ;
if ( V_26 && V_35 >= V_27 )
return - V_137 ;
if ( V_26 == NULL && V_35 >= V_20 )
return - V_137 ;
if ( F_45 ( & V_44 ) )
return - V_53 ;
if ( V_26 ) {
V_35 += V_20
+ V_26 -> V_43 * V_27 ;
if ( V_35 >= V_25 )
V_35 = - 1 ;
}
V_10 = F_23 ( V_35 , 0 ) ;
if ( V_10 == NULL ) {
F_41 ( & V_44 ) ;
return - V_295 ;
}
F_20 ( & V_47 , 1 ) ;
V_10 -> V_56 = 1 ;
V_10 -> V_57 = 1 ;
V_10 -> V_58 . V_202 . V_26 = V_26 ;
va_start ( args , V_294 ) ;
vsnprintf ( V_10 -> V_63 , sizeof( V_10 -> V_63 ) , V_294 , args ) ;
va_end ( args ) ;
V_10 -> type = V_46 ;
F_41 ( & V_44 ) ;
F_49 ( V_10 -> V_43 ) ;
return V_10 -> V_43 ;
}
int F_180 ( int V_10 )
{
struct V_9 * V_174 ;
if ( F_55 ( F_15 () ) )
return - V_295 ;
V_174 = F_9 ( V_10 ) ;
if ( V_174 == NULL )
return - V_137 ;
F_37 ( V_174 ) ;
F_26 ( V_174 ) ;
return 0 ;
}
static int F_181 ( int V_10 , struct V_78 * V_154 ,
struct V_2 * V_2 , int V_164 ,
int V_97 , int V_98 )
{
struct V_9 * V_195 ;
int V_70 ;
if ( F_55 ( ! V_154 ) )
return - V_137 ;
if ( V_154 -> type == V_170 )
return 0 ;
if ( V_154 -> type == V_101 )
return - V_137 ;
V_154 -> V_105 . V_10 = V_10 ;
if ( F_97 ( V_154 ) )
return - V_137 ;
V_195 = F_11 ( V_10 ) ;
if ( V_195 == NULL )
return - V_137 ;
if ( ! V_195 -> V_57 )
V_70 = - V_125 ;
else
V_70 = F_94 ( V_195 , V_154 , V_2 , V_164 , V_97 , V_98 ) ;
F_69 ( V_195 ) ;
return V_70 ;
}
int F_182 ( int V_10 , struct V_78 * V_154 ,
int V_97 , int V_98 )
{
return F_181 ( V_10 , V_154 , NULL , 0 , V_97 , V_98 ) ;
}
int F_183 ( int V_10 , struct V_78 * V_154 ,
struct V_2 * V_2 ,
int V_97 , int V_98 )
{
return F_181 ( V_10 , V_154 , V_2 , 1 , V_97 , V_98 ) ;
}
int F_184 ( int V_10 , struct V_78 * V_154 ,
int V_97 , int V_98 )
{
struct V_9 * V_195 ;
int V_70 ;
if ( F_55 ( ! V_154 ) )
return - V_137 ;
V_154 -> V_103 = V_104 ;
V_154 -> V_105 . V_10 = V_10 ;
if ( F_97 ( V_154 ) )
return - V_137 ;
V_195 = F_11 ( V_10 ) ;
if ( V_195 == NULL )
return - V_137 ;
if ( ! V_195 -> V_57 )
V_70 = - V_125 ;
else
V_70 = F_90 ( V_195 , V_154 , V_97 , V_98 ) ;
F_69 ( V_195 ) ;
return V_70 ;
}
int F_185 ( int V_12 , unsigned int V_285 , void * V_184 )
{
struct V_9 * V_10 ;
T_1 V_1 ;
int V_70 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_73 ;
V_1 = F_1 () ;
V_70 = F_174 ( V_10 , V_285 , ( void V_87 T_4 * ) V_184 ) ;
F_5 ( V_1 ) ;
return V_70 ;
}
int F_186 ( int V_12 , struct V_2 * V_2 , T_7 * V_178 )
{
struct V_9 * V_10 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_73 ;
if ( ! F_7 ( V_10 ) )
return 1 ;
if ( F_109 ( V_10 -> V_11 , V_2 , V_178 ) )
return 1 ;
return 0 ;
}
static void F_187 ( struct V_296 * V_297 ,
struct V_135 * V_274 ,
int V_298 , char * V_299 )
{
struct V_275 * V_272 ;
struct V_130 * V_282 ;
int V_67 = 0 ;
F_83 ( & V_274 -> V_140 ) ;
if ( F_188 ( & V_274 -> V_275 ) ) {
F_86 ( & V_274 -> V_140 ) ;
return;
}
F_189 ( V_297 , V_299 ) ;
F_169 (p, &group->list_head) {
if ( V_298 )
V_282 = F_170 ( V_272 , struct V_130 , V_283 ) ;
else
V_282 = F_170 ( V_272 , struct V_130 , V_284 ) ;
if ( V_67 ++ )
F_189 ( V_297 , L_10 ) ;
F_189 ( V_297 , L_11 ,
V_298 ? V_282 -> V_142 . V_93 . V_10 : V_282 -> V_142 . V_220 . V_10 ,
V_298 ? V_282 -> V_142 . V_93 . V_90 : V_282 -> V_142 . V_220 . V_90 ) ;
if ( V_282 -> V_142 . V_15 & V_143 )
F_189 ( V_297 , L_12 , ( ( V_282 -> V_142 . V_15 & V_144 ) ? 'r' : 't' ) , V_282 -> V_142 . V_103 ) ;
if ( V_274 -> V_300 )
F_189 ( V_297 , L_13 ) ;
}
F_86 ( & V_274 -> V_140 ) ;
F_189 ( V_297 , L_14 ) ;
}
static void F_190 ( struct V_296 * V_297 ,
struct V_9 * V_10 )
{
struct V_89 * V_272 ;
F_38 ( & V_10 -> V_41 ) ;
F_84 (p, &client->ports_list_head, list) {
F_189 ( V_297 , L_15 ,
V_272 -> V_147 . V_90 , V_272 -> V_63 ,
F_191 ( V_272 -> V_91 ) ,
F_192 ( V_272 -> V_91 ) ,
F_193 ( V_272 -> V_91 ) ,
F_194 ( V_272 -> V_91 ) ) ;
F_187 ( V_297 , & V_272 -> V_138 , 1 , L_16 ) ;
F_187 ( V_297 , & V_272 -> V_214 , 0 , L_17 ) ;
}
F_41 ( & V_10 -> V_41 ) ;
}
void F_195 ( struct V_301 * V_302 ,
struct V_296 * V_297 )
{
int V_37 ;
struct V_9 * V_10 ;
F_189 ( V_297 , L_18 ) ;
F_189 ( V_297 , L_19 , V_47 . V_33 ) ;
F_189 ( V_297 , L_20 , V_47 . V_34 ) ;
F_189 ( V_297 , L_21 , V_13 ) ;
F_189 ( V_297 , L_14 ) ;
for ( V_37 = 0 ; V_37 < V_13 ; V_37 ++ ) {
V_10 = F_11 ( V_37 ) ;
if ( V_10 == NULL )
continue;
if ( V_10 -> type == V_39 ) {
F_69 ( V_10 ) ;
continue;
}
F_189 ( V_297 , L_22 ,
V_37 , V_10 -> V_63 ,
V_10 -> type == V_45 ? L_23 : L_24 ) ;
F_190 ( V_297 , V_10 ) ;
if ( F_7 ( V_10 ) ) {
F_189 ( V_297 , L_25 ) ;
F_196 ( V_297 , V_10 -> V_11 , L_26 ) ;
}
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 &&
V_10 -> V_58 . V_51 . V_59 -> V_11 ) {
F_189 ( V_297 , L_27 ) ;
F_196 ( V_297 , V_10 -> V_58 . V_51 . V_59 -> V_11 , L_26 ) ;
}
F_69 ( V_10 ) ;
}
}
int T_2 F_197 ( void )
{
int V_52 ;
F_198 ( & V_303 , NULL ) ;
F_199 ( & V_303 , L_28 ) ;
if ( F_45 ( & V_44 ) )
return - V_53 ;
V_52 = F_200 ( V_304 , NULL , 0 ,
& V_305 , NULL , & V_303 ) ;
if ( V_52 < 0 ) {
F_41 ( & V_44 ) ;
F_201 ( & V_303 ) ;
return V_52 ;
}
F_41 ( & V_44 ) ;
return 0 ;
}
void T_9 F_202 ( void )
{
F_203 ( & V_303 ) ;
F_201 ( & V_303 ) ;
}
