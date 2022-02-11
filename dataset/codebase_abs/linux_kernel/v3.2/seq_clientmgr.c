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
F_39 ( V_45 L_3 ,
V_10 -> V_43 ) ;
break;
case V_46 :
case V_47 :
F_32 ( V_10 ) ;
F_21 ( & V_48 , 1 ) ;
break;
default:
F_39 ( V_49 L_4 ,
V_10 -> V_43 , V_10 -> type ) ;
}
F_40 ( & V_44 ) ;
F_41 ( V_10 -> V_43 ) ;
}
static int F_42 ( struct V_50 * V_50 , struct V_2 * V_2 )
{
int V_37 , V_51 ;
struct V_9 * V_10 ;
struct V_52 * V_53 ;
int V_54 ;
V_54 = F_43 ( V_50 , V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_44 ( & V_44 ) )
return - V_55 ;
V_10 = F_23 ( - 1 , V_56 ) ;
if ( V_10 == NULL ) {
F_40 ( & V_44 ) ;
return - V_57 ;
}
V_51 = F_6 ( V_2 ) ;
if ( V_51 & V_7 )
V_10 -> V_58 = 1 ;
if ( V_51 & V_6 )
V_10 -> V_59 = 1 ;
V_53 = & V_10 -> V_60 . V_53 ;
V_53 -> V_61 = NULL ;
V_53 -> V_62 = 0 ;
if ( V_51 & V_7 ) {
V_53 -> V_62 = V_63 ;
V_53 -> V_61 = F_45 ( V_53 -> V_62 ) ;
if ( V_53 -> V_61 == NULL ) {
F_32 ( V_10 ) ;
F_26 ( V_10 ) ;
F_40 ( & V_44 ) ;
return - V_57 ;
}
}
F_20 ( & V_48 , 1 ) ;
V_10 -> type = V_46 ;
F_40 ( & V_44 ) ;
V_37 = V_10 -> V_43 ;
V_2 -> V_64 = V_10 ;
V_53 -> V_2 = V_2 ;
sprintf ( V_10 -> V_65 , L_5 , V_37 ) ;
F_46 ( V_37 ) ;
return 0 ;
}
static int F_47 ( struct V_50 * V_50 , struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_64 ;
if ( V_10 ) {
F_37 ( V_10 ) ;
if ( V_10 -> V_60 . V_53 . V_61 )
F_48 ( & V_10 -> V_60 . V_53 . V_61 ) ;
F_26 ( V_10 ) ;
}
return 0 ;
}
static T_3 F_49 ( struct V_2 * V_2 , char T_4 * V_66 , T_5 V_67 ,
T_6 * V_68 )
{
struct V_9 * V_10 = V_2 -> V_64 ;
struct V_69 * V_61 ;
int V_54 ;
long V_70 = 0 ;
struct V_71 * V_72 ;
if ( ! ( F_6 ( V_2 ) & V_7 ) )
return - V_73 ;
if ( ! F_50 ( V_74 , V_66 , V_67 ) )
return - V_75 ;
if ( F_51 ( ! V_10 ) )
return - V_73 ;
if ( ! V_10 -> V_58 || ( V_61 = V_10 -> V_60 . V_53 . V_61 ) == NULL )
return - V_73 ;
if ( F_52 ( & V_61 -> V_76 ) > 0 ) {
F_53 ( V_61 ) ;
return - V_77 ;
}
V_72 = NULL ;
V_54 = 0 ;
F_54 ( V_61 ) ;
while ( V_67 >= sizeof( struct V_78 ) ) {
int V_79 ;
V_79 = ( V_2 -> V_80 & V_81 ) || V_70 > 0 ;
if ( ( V_54 = F_55 ( V_61 , & V_72 , V_79 ) ) < 0 ) {
break;
}
if ( F_56 ( & V_72 -> V_82 ) ) {
struct V_78 V_83 ;
V_83 = V_72 -> V_82 ;
V_83 . V_60 . V_84 . V_85 &= ~ V_86 ;
if ( F_57 ( V_66 , & V_83 , sizeof( struct V_78 ) ) ) {
V_54 = - V_75 ;
break;
}
V_67 -= sizeof( struct V_78 ) ;
V_66 += sizeof( struct V_78 ) ;
V_54 = F_58 ( & V_72 -> V_82 , V_67 ,
( char V_87 * ) V_66 , 0 ,
sizeof( struct V_78 ) ) ;
if ( V_54 < 0 )
break;
V_70 += V_54 ;
V_67 -= V_54 ;
V_66 += V_54 ;
} else {
if ( F_57 ( V_66 , & V_72 -> V_82 , sizeof( struct V_78 ) ) ) {
V_54 = - V_75 ;
break;
}
V_67 -= sizeof( struct V_78 ) ;
V_66 += sizeof( struct V_78 ) ;
}
F_59 ( V_72 ) ;
V_72 = NULL ;
V_70 += sizeof( struct V_78 ) ;
}
if ( V_54 < 0 ) {
if ( V_72 )
F_60 ( V_61 , V_72 ) ;
if ( V_54 == - V_88 && V_70 > 0 )
V_54 = 0 ;
}
F_61 ( V_61 ) ;
return ( V_54 < 0 ) ? V_54 : V_70 ;
}
static int F_62 ( struct V_89 * V_90 , unsigned int V_15 )
{
if ( ( V_90 -> V_91 & V_15 ) != V_15 )
return 0 ;
return V_15 ;
}
static struct V_9 * F_63 ( struct V_78 * V_82 ,
int V_92 )
{
struct V_9 * V_93 ;
V_93 = F_11 ( V_82 -> V_93 . V_10 ) ;
if ( V_93 == NULL )
return NULL ;
if ( ! V_93 -> V_58 )
goto V_94;
if ( ( V_93 -> V_92 & V_95 ) &&
! F_64 ( V_82 -> type , V_93 -> V_96 ) )
goto V_94;
if ( V_92 && ! ( V_93 -> V_92 & V_92 ) )
goto V_94;
return V_93 ;
V_94:
F_65 ( V_93 ) ;
return NULL ;
}
static int F_66 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_54 , int V_97 , int V_98 )
{
struct V_78 V_99 ;
int V_70 ;
if ( V_10 == NULL ||
! ( V_10 -> V_92 & V_100 ) ||
! V_10 -> V_58 )
return 0 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . type = V_101 ;
V_99 . V_15 = V_102 ;
V_99 . V_103 = V_104 ;
V_99 . V_105 . V_10 = V_106 ;
V_99 . V_105 . V_90 = V_107 ;
V_99 . V_93 . V_10 = V_10 -> V_43 ;
V_99 . V_93 . V_90 = V_82 -> V_105 . V_90 ;
V_99 . V_60 . V_108 . V_109 = V_82 -> V_93 ;
V_99 . V_60 . V_108 . V_82 = V_82 ;
V_99 . V_60 . V_108 . V_110 = - V_54 ;
V_70 = F_67 ( NULL , & V_99 , 0 , V_97 , V_98 + 1 ) ;
if ( V_70 < 0 ) {
V_10 -> V_111 ++ ;
return V_70 ;
}
return V_70 ;
}
static int F_68 ( struct V_78 * V_82 ,
int V_103 , int V_112 )
{
struct V_113 * V_114 ;
V_114 = F_69 ( V_103 ) ;
if ( ! V_114 )
return 0 ;
V_82 -> V_103 = V_103 ;
V_82 -> V_15 &= ~ V_115 ;
if ( V_112 ) {
V_82 -> time . time = F_70 ( V_114 -> V_116 ) ;
V_82 -> V_15 |= V_117 ;
} else {
V_82 -> time . V_118 = F_71 ( V_114 -> V_116 ) ;
V_82 -> V_15 |= V_119 ;
}
F_72 ( V_114 ) ;
return 1 ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_92 , int V_97 , int V_98 )
{
struct V_9 * V_93 = NULL ;
struct V_89 * V_120 = NULL ;
int V_70 = - V_121 ;
int V_122 ;
V_122 = F_73 ( V_82 ) ;
V_93 = F_63 ( V_82 , V_92 ) ;
if ( V_93 == NULL )
goto V_123;
V_120 = F_74 ( V_93 , V_82 -> V_93 . V_90 ) ;
if ( V_120 == NULL )
goto V_123;
if ( ! F_62 ( V_120 , V_124 ) ) {
V_70 = - V_125 ;
goto V_123;
}
if ( V_120 -> V_126 )
F_68 ( V_82 , V_120 -> V_127 ,
V_120 -> V_128 ) ;
switch ( V_93 -> type ) {
case V_46 :
if ( V_93 -> V_60 . V_53 . V_61 )
V_70 = F_75 ( V_93 -> V_60 . V_53 . V_61 , V_82 ) ;
break;
case V_47 :
if ( V_120 -> V_129 == NULL )
break;
V_70 = V_120 -> V_129 ( V_82 , V_122 ,
V_120 -> V_64 ,
V_97 , V_98 ) ;
break;
default:
break;
}
V_123:
if ( V_120 )
F_76 ( V_120 ) ;
if ( V_93 )
F_65 ( V_93 ) ;
if ( V_70 < 0 && ! V_122 ) {
V_70 = F_66 ( V_10 , V_82 , V_70 , V_97 , V_98 ) ;
}
return V_70 ;
}
static int F_77 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_97 , int V_98 )
{
struct V_130 * V_131 ;
int V_54 = 0 , V_132 = 0 ;
struct V_78 V_133 ;
struct V_89 * V_134 ;
struct V_135 * V_136 ;
V_134 = F_74 ( V_10 , V_82 -> V_105 . V_90 ) ;
if ( V_134 == NULL )
return - V_137 ;
V_133 = * V_82 ;
V_136 = & V_134 -> V_138 ;
if ( V_97 )
F_78 ( & V_136 -> V_139 ) ;
else
F_79 ( & V_136 -> V_140 ) ;
F_80 (subs, &grp->list_head, src_list) {
V_82 -> V_93 = V_131 -> V_141 . V_93 ;
if ( V_131 -> V_141 . V_15 & V_142 )
F_68 ( V_82 , V_131 -> V_141 . V_103 ,
V_131 -> V_141 . V_15 & V_143 ) ;
V_54 = F_67 ( V_10 , V_82 ,
0 , V_97 , V_98 ) ;
if ( V_54 < 0 )
break;
V_132 ++ ;
* V_82 = V_133 ;
}
if ( V_97 )
F_81 ( & V_136 -> V_139 ) ;
else
F_82 ( & V_136 -> V_140 ) ;
* V_82 = V_133 ;
F_76 ( V_134 ) ;
return ( V_54 < 0 ) ? V_54 : V_132 ;
}
static int F_83 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
int V_97 , int V_98 )
{
int V_132 = 0 , V_54 = 0 ;
struct V_9 * V_144 ;
struct V_89 * V_90 ;
V_144 = F_63 ( V_82 , V_145 ) ;
if ( V_144 == NULL )
return 0 ;
F_78 ( & V_144 -> V_40 ) ;
F_80 (port, &dest_client->ports_list_head, list) {
V_82 -> V_93 . V_90 = V_90 -> V_146 . V_90 ;
V_54 = F_67 ( NULL , V_82 ,
V_145 ,
V_97 , V_98 ) ;
if ( V_54 < 0 )
break;
V_132 ++ ;
}
F_81 ( & V_144 -> V_40 ) ;
F_65 ( V_144 ) ;
V_82 -> V_93 . V_90 = V_147 ;
return ( V_54 < 0 ) ? V_54 : V_132 ;
}
static int F_84 ( struct V_9 * V_10 ,
struct V_78 * V_82 , int V_97 , int V_98 )
{
int V_54 = 0 , V_132 = 0 ;
int V_93 ;
struct V_148 V_146 ;
V_146 = V_82 -> V_93 ;
for ( V_93 = 0 ; V_93 < V_13 ; V_93 ++ ) {
if ( V_93 == V_10 -> V_43 )
continue;
V_82 -> V_93 . V_10 = V_93 ;
V_82 -> V_93 . V_90 = V_146 . V_90 ;
if ( V_146 . V_90 == V_147 )
V_54 = F_83 ( V_10 , V_82 , V_97 , V_98 ) ;
else
V_54 = F_67 ( NULL , V_82 ,
V_145 ,
V_97 , V_98 ) ;
if ( V_54 < 0 )
break;
V_132 += V_54 ;
}
V_82 -> V_93 = V_146 ;
return ( V_54 < 0 ) ? V_54 : V_132 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_78 * V_82 ,
int V_97 , int V_98 )
{
F_10 ( L_6 ) ;
return 0 ;
}
static int F_86 ( struct V_9 * V_10 , struct V_78 * V_82 ,
int V_97 , int V_98 )
{
int V_70 ;
V_98 ++ ;
if ( V_98 >= V_149 ) {
F_10 ( L_7 ,
V_82 -> V_105 . V_10 , V_82 -> V_105 . V_90 ,
V_82 -> V_93 . V_10 , V_82 -> V_93 . V_90 ) ;
return - V_150 ;
}
if ( V_82 -> V_103 == V_151 ||
V_82 -> V_93 . V_10 == V_151 )
V_70 = F_77 ( V_10 , V_82 , V_97 , V_98 ) ;
#ifdef F_87
else if ( V_82 -> V_103 == V_147 ||
V_82 -> V_93 . V_10 == V_147 )
V_70 = F_84 ( V_10 , V_82 , V_97 , V_98 ) ;
else if ( V_82 -> V_93 . V_10 >= V_13 )
V_70 = F_85 ( V_10 , V_82 , V_97 , V_98 ) ;
else if ( V_82 -> V_93 . V_90 == V_147 )
V_70 = F_83 ( V_10 , V_82 , V_97 , V_98 ) ;
#endif
else
V_70 = F_67 ( V_10 , V_82 , 0 , V_97 , V_98 ) ;
return V_70 ;
}
int F_88 ( struct V_71 * V_72 , int V_97 , int V_98 )
{
struct V_9 * V_10 ;
int V_70 ;
if ( F_51 ( ! V_72 ) )
return - V_137 ;
V_10 = F_11 ( V_72 -> V_82 . V_105 . V_10 ) ;
if ( V_10 == NULL ) {
F_59 ( V_72 ) ;
return - V_137 ;
}
if ( V_72 -> V_82 . type == V_152 ) {
struct V_78 V_83 , * V_153 ;
V_83 = V_72 -> V_82 ;
V_83 . type = V_154 ;
V_70 = F_86 ( V_10 , & V_83 , V_97 , V_98 ) ;
V_153 = & V_72 -> V_82 ;
V_153 -> type = V_155 ;
V_153 -> V_15 |= V_156 ;
switch ( V_153 -> V_15 & V_115 ) {
case V_119 :
V_153 -> time . V_118 += V_153 -> V_60 . V_157 . V_158 ;
break;
case V_117 :
V_153 -> time . time . V_159 += 1000000 * ( V_153 -> V_60 . V_157 . V_158 % 1000 ) ;
V_153 -> time . time . V_160 += V_153 -> V_60 . V_157 . V_158 / 1000 +
V_153 -> time . time . V_159 / 1000000000 ;
V_153 -> time . time . V_159 %= 1000000000 ;
break;
}
V_153 -> V_60 . V_157 . V_161 = V_153 -> V_60 . V_157 . V_162 ;
if ( F_89 ( V_72 , V_97 , V_98 ) < 0 )
F_59 ( V_72 ) ;
} else {
V_70 = F_86 ( V_10 , & V_72 -> V_82 , V_97 , V_98 ) ;
F_59 ( V_72 ) ;
}
F_65 ( V_10 ) ;
return V_70 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_78 * V_82 ,
struct V_2 * V_2 , int V_163 ,
int V_97 , int V_98 )
{
struct V_71 * V_72 ;
int V_54 ;
if ( V_82 -> V_103 == V_151 ) {
V_82 -> V_93 . V_10 = V_151 ;
V_82 -> V_103 = V_104 ;
} else
#ifdef F_87
if ( V_82 -> V_103 == V_147 ) {
V_82 -> V_93 . V_10 = V_147 ;
V_82 -> V_103 = V_104 ;
}
#endif
if ( V_82 -> V_93 . V_10 == V_151 ) {
struct V_89 * V_134 = F_74 ( V_10 , V_82 -> V_105 . V_90 ) ;
if ( V_134 == NULL )
return - V_137 ;
F_76 ( V_134 ) ;
}
if ( F_73 ( V_82 ) ) {
if ( V_82 -> type == V_152 )
return - V_137 ;
return F_86 ( V_10 , V_82 , V_97 , V_98 ) ;
}
if ( F_91 ( V_82 -> V_103 , V_10 -> V_43 ) <= 0 )
return - V_137 ;
if ( ! F_7 ( V_10 ) )
return - V_73 ;
V_54 = F_92 ( V_10 -> V_11 , V_82 , & V_72 , ! V_163 || V_97 , V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ( V_54 = F_89 ( V_72 , V_97 , V_98 ) ) < 0 ) {
F_59 ( V_72 ) ;
return V_54 ;
}
return 0 ;
}
static int F_93 ( struct V_78 * V_153 )
{
switch ( F_94 ( V_153 ) ) {
case V_102 :
if ( F_95 ( V_153 ) )
return - V_137 ;
break;
case V_164 :
if ( ! F_95 ( V_153 ) ||
( V_153 -> V_60 . V_84 . V_85 & ~ V_86 ) >= V_165 )
return - V_137 ;
break;
case V_166 :
if ( ! F_73 ( V_153 ) )
return - V_137 ;
break;
}
return 0 ;
}
static T_3 F_96 ( struct V_2 * V_2 , const char T_4 * V_66 ,
T_5 V_67 , T_6 * V_68 )
{
struct V_9 * V_10 = V_2 -> V_64 ;
int V_167 = 0 , V_85 ;
int V_54 = - V_137 ;
struct V_78 V_82 ;
if ( ! ( F_6 ( V_2 ) & V_6 ) )
return - V_73 ;
if ( F_51 ( ! V_10 ) )
return - V_73 ;
if ( ! V_10 -> V_59 || V_10 -> V_11 == NULL )
return - V_73 ;
if ( V_10 -> V_11 -> V_168 > 0 && ! F_7 ( V_10 ) ) {
if ( F_97 ( V_10 -> V_11 ) < 0 )
return - V_57 ;
}
while ( V_67 >= sizeof( struct V_78 ) ) {
V_85 = sizeof( V_82 ) ;
if ( F_98 ( & V_82 , V_66 , V_85 ) ) {
V_54 = - V_75 ;
break;
}
V_82 . V_105 . V_10 = V_10 -> V_43 ;
if ( F_93 ( & V_82 ) ) {
V_54 = - V_137 ;
break;
}
if ( V_82 . type == V_169 )
goto V_170;
else if ( F_99 ( & V_82 ) ) {
V_54 = - V_137 ;
break;
}
if ( F_56 ( & V_82 ) ) {
int V_171 = V_82 . V_60 . V_84 . V_85 & ~ V_86 ;
if ( ( T_5 ) ( V_171 + V_85 ) > V_67 ) {
V_54 = - V_137 ;
break;
}
V_82 . V_60 . V_84 . V_85 = V_171 | V_172 ;
V_82 . V_60 . V_84 . V_173 = ( char V_87 * ) V_66
+ sizeof( struct V_78 ) ;
V_85 += V_171 ;
} else {
#ifdef F_100
if ( V_10 -> V_174 && F_101 ( & V_82 ) ) {
void * V_173 = ( void V_87 * ) F_102 ( V_82 . V_60 . V_175 . V_176 [ 1 ] ) ;
V_82 . V_60 . V_84 . V_173 = V_173 ;
}
#endif
}
V_54 = F_90 ( V_10 , & V_82 , V_2 ,
! ( V_2 -> V_80 & V_81 ) ,
0 , 0 ) ;
if ( V_54 < 0 )
break;
V_170:
V_67 -= V_85 ;
V_66 += V_85 ;
V_167 += V_85 ;
}
return V_167 ? V_167 : V_54 ;
}
static unsigned int F_103 ( struct V_2 * V_2 , T_7 * V_177 )
{
struct V_9 * V_10 = V_2 -> V_64 ;
unsigned int V_178 = 0 ;
if ( F_51 ( ! V_10 ) )
return - V_73 ;
if ( ( F_6 ( V_2 ) & V_7 ) &&
V_10 -> V_60 . V_53 . V_61 ) {
if ( F_104 ( V_10 -> V_60 . V_53 . V_61 , V_2 , V_177 ) )
V_178 |= V_179 | V_180 ;
}
if ( F_6 ( V_2 ) & V_6 ) {
if ( ! F_7 ( V_10 ) ||
F_105 ( V_10 -> V_11 , V_2 , V_177 ) )
V_178 |= V_181 | V_182 ;
}
return V_178 ;
}
static int F_106 ( struct V_9 * V_10 , void T_4 * V_183 )
{
struct V_184 V_141 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_185 = V_186 ;
V_141 . V_187 = V_13 ;
V_141 . V_188 = 256 ;
V_141 . V_189 = 256 ;
V_141 . V_190 = V_48 . V_33 ;
V_141 . V_191 = F_107 () ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_108 ( struct V_9 * V_10 , void T_4 * V_183 )
{
struct V_192 V_141 ;
struct V_9 * V_193 ;
int V_54 = 0 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_193 = F_11 ( V_141 . V_10 ) ;
if ( V_193 == NULL )
return - V_121 ;
#ifdef F_109
if ( ! V_141 . V_194 ) {
V_54 = - V_137 ;
goto V_195;
}
#else
if ( V_141 . V_194 ) {
V_54 = - V_137 ;
goto V_195;
}
#endif
if ( V_141 . V_196 > sizeof( long ) ) {
V_54 = - V_137 ;
goto V_195;
}
V_193 -> V_174 = ( V_141 . V_196 < sizeof( long ) ) ;
V_195:
F_65 ( V_193 ) ;
return V_54 ;
}
static void F_110 ( struct V_9 * V_193 ,
struct V_197 * V_141 )
{
V_141 -> V_10 = V_193 -> V_43 ;
V_141 -> type = V_193 -> type ;
strcpy ( V_141 -> V_65 , V_193 -> V_65 ) ;
V_141 -> V_92 = V_193 -> V_92 ;
V_141 -> V_111 = V_193 -> V_111 ;
memcpy ( V_141 -> V_96 , V_193 -> V_96 , 32 ) ;
V_141 -> V_198 = V_193 -> V_198 ;
memset ( V_141 -> V_199 , 0 , sizeof( V_141 -> V_199 ) ) ;
}
static int F_111 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_9 * V_193 ;
struct V_197 V_200 ;
if ( F_98 ( & V_200 , V_183 , sizeof( V_200 ) ) )
return - V_75 ;
V_193 = F_11 ( V_200 . V_10 ) ;
if ( V_193 == NULL )
return - V_121 ;
F_110 ( V_193 , & V_200 ) ;
F_65 ( V_193 ) ;
if ( F_57 ( V_183 , & V_200 , sizeof( V_200 ) ) )
return - V_75 ;
return 0 ;
}
static int F_112 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_197 V_200 ;
if ( F_98 ( & V_200 , V_183 , sizeof( V_200 ) ) )
return - V_75 ;
if ( V_10 -> V_43 != V_200 . V_10 )
return - V_125 ;
if ( V_10 -> type != V_200 . type )
return - V_137 ;
if ( V_200 . V_65 [ 0 ] )
F_113 ( V_10 -> V_65 , V_200 . V_65 , sizeof( V_10 -> V_65 ) ) ;
V_10 -> V_92 = V_200 . V_92 ;
V_10 -> V_111 = V_200 . V_111 ;
memcpy ( V_10 -> V_96 , V_200 . V_96 , 32 ) ;
return 0 ;
}
static int F_114 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_89 * V_90 ;
struct V_201 V_141 ;
struct V_202 * V_203 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_146 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_90 = F_115 ( V_10 , ( V_141 . V_15 & V_204 ) ? V_141 . V_146 . V_90 : - 1 ) ;
if ( V_90 == NULL )
return - V_57 ;
if ( V_10 -> type == V_46 && V_141 . V_205 ) {
F_116 ( V_10 , V_90 -> V_146 . V_90 ) ;
return - V_137 ;
}
if ( V_10 -> type == V_47 ) {
if ( ( V_203 = V_141 . V_205 ) != NULL ) {
if ( V_203 -> V_206 )
V_90 -> V_206 = V_203 -> V_206 ;
V_90 -> V_64 = V_203 -> V_64 ;
V_90 -> V_207 = V_203 -> V_207 ;
V_90 -> V_208 = V_203 -> V_208 ;
V_90 -> V_129 = V_203 -> V_129 ;
V_90 -> V_138 . V_209 = V_203 -> V_210 ;
V_90 -> V_138 . V_211 = V_203 -> V_212 ;
V_90 -> V_213 . V_209 = V_203 -> V_214 ;
V_90 -> V_213 . V_211 = V_203 -> V_215 ;
}
}
V_141 . V_146 = V_90 -> V_146 ;
F_117 ( V_90 , & V_141 ) ;
F_118 ( V_90 -> V_146 . V_10 , V_90 -> V_146 . V_90 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_119 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_201 V_141 ;
int V_54 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_146 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_54 = F_116 ( V_10 , V_141 . V_146 . V_90 ) ;
if ( V_54 >= 0 )
F_120 ( V_10 -> V_43 , V_141 . V_146 . V_90 ) ;
return V_54 ;
}
static int F_121 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_9 * V_193 ;
struct V_89 * V_90 ;
struct V_201 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_193 = F_11 ( V_141 . V_146 . V_10 ) ;
if ( V_193 == NULL )
return - V_73 ;
V_90 = F_74 ( V_193 , V_141 . V_146 . V_90 ) ;
if ( V_90 == NULL ) {
F_65 ( V_193 ) ;
return - V_121 ;
}
F_122 ( V_90 , & V_141 ) ;
F_76 ( V_90 ) ;
F_65 ( V_193 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_123 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_89 * V_90 ;
struct V_201 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_146 . V_10 != V_10 -> V_43 )
return - V_125 ;
V_90 = F_74 ( V_10 , V_141 . V_146 . V_90 ) ;
if ( V_90 ) {
F_117 ( V_90 , & V_141 ) ;
F_76 ( V_90 ) ;
}
return 0 ;
}
static int F_124 ( struct V_9 * V_10 ,
struct V_89 * V_216 ,
struct V_89 * V_217 ,
struct V_218 * V_131 )
{
if ( V_10 -> V_43 != V_131 -> V_219 . V_10 &&
V_10 -> V_43 != V_131 -> V_93 . V_10 ) {
if ( F_62 ( V_216 , V_220 ) )
return - V_125 ;
if ( F_62 ( V_217 , V_220 ) )
return - V_125 ;
}
if ( V_10 -> V_43 != V_131 -> V_219 . V_10 ) {
if ( ! F_62 ( V_216 , V_221 ) )
return - V_125 ;
}
if ( V_10 -> V_43 != V_131 -> V_93 . V_10 ) {
if ( ! F_62 ( V_217 , V_222 ) )
return - V_125 ;
}
return 0 ;
}
int F_125 ( int V_10 , int V_90 ,
struct V_218 * V_141 ,
int V_223 )
{
struct V_78 V_82 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . type = V_223 ;
V_82 . V_60 . V_224 . V_93 = V_141 -> V_93 ;
V_82 . V_60 . V_224 . V_219 = V_141 -> V_219 ;
return F_126 ( V_10 , V_90 , & V_82 ) ;
}
static int F_127 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 = - V_137 ;
struct V_9 * V_225 = NULL , * V_219 = NULL ;
struct V_89 * V_216 = NULL , * V_217 = NULL ;
struct V_218 V_131 ;
if ( F_98 ( & V_131 , V_183 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_225 = F_11 ( V_131 . V_93 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_219 = F_11 ( V_131 . V_219 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_216 = F_74 ( V_219 , V_131 . V_219 . V_90 ) ) == NULL )
goto V_226;
if ( ( V_217 = F_74 ( V_225 , V_131 . V_93 . V_90 ) ) == NULL )
goto V_226;
V_70 = F_124 ( V_10 , V_216 , V_217 , & V_131 ) ;
if ( V_70 < 0 )
goto V_226;
V_70 = F_128 ( V_10 , V_219 , V_216 , V_225 , V_217 , & V_131 ) ;
if ( ! V_70 )
F_125 ( V_151 , 0 ,
& V_131 , V_227 ) ;
V_226:
if ( V_216 )
F_76 ( V_216 ) ;
if ( V_217 )
F_76 ( V_217 ) ;
if ( V_219 )
F_65 ( V_219 ) ;
if ( V_225 )
F_65 ( V_225 ) ;
return V_70 ;
}
static int F_129 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 = - V_73 ;
struct V_9 * V_225 = NULL , * V_219 = NULL ;
struct V_89 * V_216 = NULL , * V_217 = NULL ;
struct V_218 V_131 ;
if ( F_98 ( & V_131 , V_183 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_225 = F_11 ( V_131 . V_93 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_219 = F_11 ( V_131 . V_219 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_216 = F_74 ( V_219 , V_131 . V_219 . V_90 ) ) == NULL )
goto V_226;
if ( ( V_217 = F_74 ( V_225 , V_131 . V_93 . V_90 ) ) == NULL )
goto V_226;
V_70 = F_124 ( V_10 , V_216 , V_217 , & V_131 ) ;
if ( V_70 < 0 )
goto V_226;
V_70 = F_130 ( V_10 , V_219 , V_216 , V_225 , V_217 , & V_131 ) ;
if ( ! V_70 )
F_125 ( V_151 , 0 ,
& V_131 , V_228 ) ;
V_226:
if ( V_216 )
F_76 ( V_216 ) ;
if ( V_217 )
F_76 ( V_217 ) ;
if ( V_219 )
F_65 ( V_219 ) ;
if ( V_225 )
F_65 ( V_225 ) ;
return V_70 ;
}
static int F_131 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_229 V_141 ;
int V_70 ;
struct V_113 * V_114 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_70 = F_132 ( V_10 -> V_43 , V_141 . V_230 , V_141 . V_15 ) ;
if ( V_70 < 0 )
return V_70 ;
V_114 = F_69 ( V_70 ) ;
if ( V_114 == NULL )
return - V_137 ;
V_141 . V_103 = V_114 -> V_103 ;
V_141 . V_230 = V_114 -> V_230 ;
V_141 . V_206 = V_114 -> V_206 ;
if ( ! V_141 . V_65 [ 0 ] )
snprintf ( V_141 . V_65 , sizeof( V_141 . V_65 ) , L_8 , V_114 -> V_103 ) ;
F_113 ( V_114 -> V_65 , V_141 . V_65 , sizeof( V_114 -> V_65 ) ) ;
F_72 ( V_114 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_133 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_229 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
return F_134 ( V_10 -> V_43 , V_141 . V_103 ) ;
}
static int F_135 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_229 V_141 ;
struct V_113 * V_114 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_114 = F_69 ( V_141 . V_103 ) ;
if ( V_114 == NULL )
return - V_137 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_103 = V_114 -> V_103 ;
V_141 . V_206 = V_114 -> V_206 ;
V_141 . V_230 = V_114 -> V_230 ;
F_113 ( V_141 . V_65 , V_114 -> V_65 , sizeof( V_141 . V_65 ) ) ;
F_72 ( V_114 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_136 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_229 V_141 ;
struct V_113 * V_114 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_206 != V_10 -> V_43 )
return - V_137 ;
if ( F_137 ( V_141 . V_103 , V_10 -> V_43 ) ) {
if ( F_138 ( V_141 . V_103 , V_10 -> V_43 , V_141 . V_230 ) < 0 )
return - V_125 ;
if ( V_141 . V_230 )
F_139 ( V_141 . V_103 , V_10 -> V_43 , 1 ) ;
} else {
return - V_125 ;
}
V_114 = F_69 ( V_141 . V_103 ) ;
if ( ! V_114 )
return - V_137 ;
if ( V_114 -> V_206 != V_10 -> V_43 ) {
F_72 ( V_114 ) ;
return - V_125 ;
}
F_113 ( V_114 -> V_65 , V_141 . V_65 , sizeof( V_114 -> V_65 ) ) ;
F_72 ( V_114 ) ;
return 0 ;
}
static int F_140 ( struct V_9 * V_10 , void T_4 * V_183 )
{
struct V_229 V_141 ;
struct V_113 * V_114 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_114 = F_141 ( V_141 . V_65 ) ;
if ( V_114 == NULL )
return - V_137 ;
V_141 . V_103 = V_114 -> V_103 ;
V_141 . V_206 = V_114 -> V_206 ;
V_141 . V_230 = V_114 -> V_230 ;
F_72 ( V_114 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_142 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_231 V_232 ;
struct V_113 * V_103 ;
struct V_233 * V_234 ;
if ( F_98 ( & V_232 , V_183 , sizeof( V_232 ) ) )
return - V_75 ;
V_103 = F_69 ( V_232 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_232 . V_103 = V_103 -> V_103 ;
V_234 = V_103 -> V_116 ;
V_232 . V_235 = V_103 -> V_236 -> V_237 + V_103 -> V_238 -> V_237 ;
V_232 . time = F_70 ( V_234 ) ;
V_232 . V_118 = F_71 ( V_234 ) ;
V_232 . V_239 = V_234 -> V_239 ;
V_232 . V_15 = V_103 -> V_15 ;
F_72 ( V_103 ) ;
if ( F_57 ( V_183 , & V_232 , sizeof( V_232 ) ) )
return - V_75 ;
return 0 ;
}
static int F_143 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_240 V_241 ;
struct V_113 * V_103 ;
struct V_233 * V_234 ;
if ( F_98 ( & V_241 , V_183 , sizeof( V_241 ) ) )
return - V_75 ;
V_103 = F_69 ( V_241 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_103 = V_103 -> V_103 ;
V_234 = V_103 -> V_116 ;
V_241 . V_241 = V_234 -> V_241 ;
V_241 . V_242 = V_234 -> V_242 ;
V_241 . V_243 = V_234 -> V_244 ;
V_241 . V_245 = V_234 -> V_245 ;
F_72 ( V_103 ) ;
if ( F_57 ( V_183 , & V_241 , sizeof( V_241 ) ) )
return - V_75 ;
return 0 ;
}
int F_144 ( int V_10 , struct V_240 * V_241 )
{
if ( ! F_137 ( V_241 -> V_103 , V_10 ) )
return - V_125 ;
return F_145 ( V_241 -> V_103 , V_10 , V_241 ) ;
}
static int F_146 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 ;
struct V_240 V_241 ;
if ( F_98 ( & V_241 , V_183 , sizeof( V_241 ) ) )
return - V_75 ;
V_70 = F_144 ( V_10 -> V_43 , & V_241 ) ;
return V_70 < 0 ? V_70 : 0 ;
}
static int F_147 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_246 V_116 ;
struct V_113 * V_103 ;
struct V_233 * V_234 ;
if ( F_98 ( & V_116 , V_183 , sizeof( V_116 ) ) )
return - V_75 ;
V_103 = F_69 ( V_116 . V_103 ) ;
if ( V_103 == NULL )
return - V_137 ;
if ( F_44 ( & V_103 -> V_247 ) ) {
F_72 ( V_103 ) ;
return - V_55 ;
}
V_234 = V_103 -> V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_103 = V_103 -> V_103 ;
V_116 . type = V_234 -> type ;
if ( V_234 -> type == V_248 ) {
V_116 . V_249 . V_250 . V_251 = V_234 -> V_252 ;
V_116 . V_249 . V_250 . V_253 = V_234 -> V_254 ;
}
F_40 ( & V_103 -> V_247 ) ;
F_72 ( V_103 ) ;
if ( F_57 ( V_183 , & V_116 , sizeof( V_116 ) ) )
return - V_75 ;
return 0 ;
}
static int F_148 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 = 0 ;
struct V_246 V_116 ;
if ( F_98 ( & V_116 , V_183 , sizeof( V_116 ) ) )
return - V_75 ;
if ( V_116 . type != V_248 )
return - V_137 ;
if ( F_137 ( V_116 . V_103 , V_10 -> V_43 ) ) {
struct V_113 * V_114 ;
struct V_233 * V_234 ;
V_114 = F_69 ( V_116 . V_103 ) ;
if ( V_114 == NULL )
return - V_73 ;
if ( F_44 ( & V_114 -> V_247 ) ) {
F_72 ( V_114 ) ;
return - V_55 ;
}
V_234 = V_114 -> V_116 ;
F_149 ( V_116 . V_103 ) ;
V_234 -> type = V_116 . type ;
if ( V_234 -> type == V_248 ) {
V_234 -> V_252 = V_116 . V_249 . V_250 . V_251 ;
V_234 -> V_254 = V_116 . V_249 . V_250 . V_253 ;
}
V_70 = F_150 ( V_116 . V_103 ) ;
F_40 ( & V_114 -> V_247 ) ;
F_72 ( V_114 ) ;
} else {
return - V_125 ;
}
return V_70 ;
}
static int F_151 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_255 V_141 ;
int V_256 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_256 = F_91 ( V_141 . V_103 , V_10 -> V_43 ) ;
if ( V_256 < 0 )
return - V_137 ;
V_141 . V_256 = V_256 ;
V_141 . V_10 = V_10 -> V_43 ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_152 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_54 ;
struct V_255 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_256 >= 0 ) {
V_54 = F_139 ( V_141 . V_103 , V_10 -> V_43 , V_141 . V_256 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return F_151 ( V_10 , V_183 ) ;
}
static int F_153 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_257 V_141 ;
struct V_9 * V_193 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_193 = F_11 ( V_141 . V_10 ) ;
if ( V_193 == NULL )
return - V_121 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_258 = V_193 -> V_11 -> V_168 ;
V_141 . V_259 = V_193 -> V_11 -> V_260 ;
V_141 . V_261 = V_141 . V_258 ;
V_141 . V_261 = F_154 ( V_193 -> V_11 ) ;
if ( V_193 -> type == V_46 ) {
V_141 . V_262 = V_193 -> V_60 . V_53 . V_62 ;
V_141 . V_263 = V_141 . V_262 ;
if ( V_193 -> V_60 . V_53 . V_61 )
V_141 . V_263 = F_154 ( V_193 -> V_60 . V_53 . V_61 -> V_11 ) ;
} else {
V_141 . V_262 = 0 ;
V_141 . V_263 = 0 ;
}
F_65 ( V_193 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_155 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_257 V_141 ;
int V_264 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_10 -> V_43 != V_141 . V_10 )
return - V_137 ;
if ( V_141 . V_258 >= 1 && V_141 . V_258 <= V_265 &&
( ! F_7 ( V_10 ) ||
V_141 . V_258 != V_10 -> V_11 -> V_168 ) ) {
if ( F_7 ( V_10 ) ) {
F_156 ( V_10 -> V_43 ) ;
F_157 ( V_10 -> V_11 ) ;
}
V_10 -> V_11 -> V_168 = V_141 . V_258 ;
V_264 = F_97 ( V_10 -> V_11 ) ;
if ( V_264 < 0 )
return V_264 ;
}
if ( V_10 -> type == V_46 && V_10 -> V_60 . V_53 . V_61 != NULL &&
V_141 . V_262 >= 1 &&
V_141 . V_262 <= V_266 &&
V_141 . V_262 != V_10 -> V_60 . V_53 . V_62 ) {
V_264 = F_158 ( V_10 -> V_60 . V_53 . V_61 , V_141 . V_262 ) ;
if ( V_264 < 0 )
return V_264 ;
V_10 -> V_60 . V_53 . V_62 = V_141 . V_262 ;
}
if ( V_141 . V_259 >= 1 &&
V_141 . V_259 <= V_10 -> V_11 -> V_168 ) {
V_10 -> V_11 -> V_260 = V_141 . V_259 ;
}
return F_153 ( V_10 , V_183 ) ;
}
static int F_159 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_267 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
if ( V_141 . V_268 & V_269 ) {
if ( V_10 -> type == V_46 )
F_53 ( V_10 -> V_60 . V_53 . V_61 ) ;
}
if ( V_141 . V_268 & V_270 )
F_160 ( V_10 -> V_43 , & V_141 ) ;
return 0 ;
}
static int F_161 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 ;
struct V_9 * V_219 = NULL ;
struct V_89 * V_216 = NULL ;
struct V_218 V_131 ;
struct V_130 * V_271 ;
if ( F_98 ( & V_131 , V_183 , sizeof( V_131 ) ) )
return - V_75 ;
V_70 = - V_137 ;
if ( ( V_219 = F_11 ( V_131 . V_219 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_216 = F_74 ( V_219 , V_131 . V_219 . V_90 ) ) == NULL )
goto V_226;
V_271 = F_162 ( & V_216 -> V_138 , & V_131 . V_93 ) ;
if ( V_271 ) {
V_70 = 0 ;
V_131 = V_271 -> V_141 ;
} else
V_70 = - V_121 ;
V_226:
if ( V_216 )
F_76 ( V_216 ) ;
if ( V_219 )
F_65 ( V_219 ) ;
if ( V_70 >= 0 ) {
if ( F_57 ( V_183 , & V_131 , sizeof( V_131 ) ) )
return - V_75 ;
}
return V_70 ;
}
static int F_163 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
int V_70 = - V_73 ;
struct V_9 * V_193 = NULL ;
struct V_89 * V_90 = NULL ;
struct V_272 V_131 ;
struct V_135 * V_273 ;
struct V_274 * V_271 ;
int V_275 ;
if ( F_98 ( & V_131 , V_183 , sizeof( V_131 ) ) )
return - V_75 ;
if ( ( V_193 = F_11 ( V_131 . V_276 . V_10 ) ) == NULL )
goto V_226;
if ( ( V_90 = F_74 ( V_193 , V_131 . V_276 . V_90 ) ) == NULL )
goto V_226;
switch ( V_131 . type ) {
case V_277 :
V_273 = & V_90 -> V_138 ;
break;
case V_278 :
V_273 = & V_90 -> V_213 ;
break;
default:
goto V_226;
}
F_79 ( & V_273 -> V_140 ) ;
V_131 . V_279 = V_273 -> V_67 ;
V_275 = 0 ;
V_70 = - V_121 ;
F_164 (p, &group->list_head) {
if ( V_275 ++ == V_131 . V_280 ) {
struct V_130 * V_281 ;
if ( V_131 . type == V_277 ) {
V_281 = F_165 ( V_271 , struct V_130 , V_282 ) ;
V_131 . V_146 = V_281 -> V_141 . V_93 ;
} else {
V_281 = F_165 ( V_271 , struct V_130 , V_283 ) ;
V_131 . V_146 = V_281 -> V_141 . V_219 ;
}
V_131 . V_15 = V_281 -> V_141 . V_15 ;
V_131 . V_103 = V_281 -> V_141 . V_103 ;
V_70 = 0 ;
break;
}
}
F_82 ( & V_273 -> V_140 ) ;
V_226:
if ( V_90 )
F_76 ( V_90 ) ;
if ( V_193 )
F_65 ( V_193 ) ;
if ( V_70 >= 0 ) {
if ( F_57 ( V_183 , & V_131 , sizeof( V_131 ) ) )
return - V_75 ;
}
return V_70 ;
}
static int F_166 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_9 * V_193 = NULL ;
struct V_197 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_141 . V_10 ++ ;
if ( V_141 . V_10 < 0 )
V_141 . V_10 = 0 ;
for (; V_141 . V_10 < V_13 ; V_141 . V_10 ++ ) {
V_193 = F_11 ( V_141 . V_10 ) ;
if ( V_193 )
break;
}
if ( V_193 == NULL )
return - V_121 ;
F_110 ( V_193 , & V_141 ) ;
F_65 ( V_193 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_167 ( struct V_9 * V_10 ,
void T_4 * V_183 )
{
struct V_9 * V_193 ;
struct V_89 * V_90 = NULL ;
struct V_201 V_141 ;
if ( F_98 ( & V_141 , V_183 , sizeof( V_141 ) ) )
return - V_75 ;
V_193 = F_11 ( V_141 . V_146 . V_10 ) ;
if ( V_193 == NULL )
return - V_73 ;
V_141 . V_146 . V_90 ++ ;
V_90 = F_168 ( V_193 , & V_141 ) ;
if ( V_90 == NULL ) {
F_65 ( V_193 ) ;
return - V_121 ;
}
V_141 . V_146 = V_90 -> V_146 ;
F_122 ( V_90 , & V_141 ) ;
F_76 ( V_90 ) ;
F_65 ( V_193 ) ;
if ( F_57 ( V_183 , & V_141 , sizeof( V_141 ) ) )
return - V_75 ;
return 0 ;
}
static int F_169 ( struct V_9 * V_10 , unsigned int V_284 ,
void T_4 * V_183 )
{
struct V_285 * V_271 ;
switch ( V_284 ) {
case V_286 :
return F_170 ( V_287 , ( int T_4 * ) V_183 ) ? - V_75 : 0 ;
case V_288 :
return F_170 ( V_10 -> V_43 , ( int T_4 * ) V_183 ) ? - V_75 : 0 ;
}
if ( ! V_183 )
return - V_75 ;
for ( V_271 = V_289 ; V_271 -> V_284 ; V_271 ++ ) {
if ( V_271 -> V_284 == V_284 )
return V_271 -> V_290 ( V_10 , V_183 ) ;
}
F_10 ( L_9 ,
V_284 , F_171 ( V_284 ) , F_172 ( V_284 ) ) ;
return - V_291 ;
}
static long F_173 ( struct V_2 * V_2 , unsigned int V_284 , unsigned long V_183 )
{
struct V_9 * V_10 = V_2 -> V_64 ;
if ( F_51 ( ! V_10 ) )
return - V_73 ;
return F_169 ( V_10 , V_284 , ( void T_4 * ) V_183 ) ;
}
int F_174 ( struct V_292 * V_26 , int V_35 ,
const char * V_293 , ... )
{
struct V_9 * V_10 ;
T_8 args ;
if ( F_51 ( F_15 () ) )
return - V_294 ;
if ( V_26 && V_35 >= V_27 )
return - V_137 ;
if ( V_26 == NULL && V_35 >= V_20 )
return - V_137 ;
if ( F_44 ( & V_44 ) )
return - V_55 ;
if ( V_26 ) {
V_35 += V_20
+ V_26 -> V_43 * V_27 ;
if ( V_35 >= V_25 )
V_35 = - 1 ;
}
V_10 = F_23 ( V_35 , 0 ) ;
if ( V_10 == NULL ) {
F_40 ( & V_44 ) ;
return - V_294 ;
}
F_20 ( & V_48 , 1 ) ;
V_10 -> V_58 = 1 ;
V_10 -> V_59 = 1 ;
va_start ( args , V_293 ) ;
vsnprintf ( V_10 -> V_65 , sizeof( V_10 -> V_65 ) , V_293 , args ) ;
va_end ( args ) ;
V_10 -> type = V_47 ;
F_40 ( & V_44 ) ;
F_46 ( V_10 -> V_43 ) ;
return V_10 -> V_43 ;
}
int F_175 ( int V_10 )
{
struct V_9 * V_173 ;
if ( F_51 ( F_15 () ) )
return - V_294 ;
V_173 = F_9 ( V_10 ) ;
if ( V_173 == NULL )
return - V_137 ;
F_37 ( V_173 ) ;
F_26 ( V_173 ) ;
return 0 ;
}
static int F_176 ( int V_10 , struct V_78 * V_153 ,
struct V_2 * V_2 , int V_163 ,
int V_97 , int V_98 )
{
struct V_9 * V_193 ;
int V_70 ;
if ( F_51 ( ! V_153 ) )
return - V_137 ;
if ( V_153 -> type == V_169 )
return 0 ;
if ( V_153 -> type == V_101 )
return - V_137 ;
V_153 -> V_105 . V_10 = V_10 ;
if ( F_93 ( V_153 ) )
return - V_137 ;
V_193 = F_11 ( V_10 ) ;
if ( V_193 == NULL )
return - V_137 ;
if ( ! V_193 -> V_59 )
V_70 = - V_125 ;
else
V_70 = F_90 ( V_193 , V_153 , V_2 , V_163 , V_97 , V_98 ) ;
F_65 ( V_193 ) ;
return V_70 ;
}
int F_177 ( int V_10 , struct V_78 * V_153 ,
int V_97 , int V_98 )
{
return F_176 ( V_10 , V_153 , NULL , 0 , V_97 , V_98 ) ;
}
int F_178 ( int V_10 , struct V_78 * V_153 ,
struct V_2 * V_2 ,
int V_97 , int V_98 )
{
return F_176 ( V_10 , V_153 , V_2 , 1 , V_97 , V_98 ) ;
}
int F_179 ( int V_10 , struct V_78 * V_153 ,
int V_97 , int V_98 )
{
struct V_9 * V_193 ;
int V_70 ;
if ( F_51 ( ! V_153 ) )
return - V_137 ;
V_153 -> V_103 = V_104 ;
V_153 -> V_105 . V_10 = V_10 ;
if ( F_93 ( V_153 ) )
return - V_137 ;
V_193 = F_11 ( V_10 ) ;
if ( V_193 == NULL )
return - V_137 ;
if ( ! V_193 -> V_59 )
V_70 = - V_125 ;
else
V_70 = F_86 ( V_193 , V_153 , V_97 , V_98 ) ;
F_65 ( V_193 ) ;
return V_70 ;
}
int F_180 ( int V_12 , unsigned int V_284 , void * V_183 )
{
struct V_9 * V_10 ;
T_1 V_1 ;
int V_70 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_73 ;
V_1 = F_1 () ;
V_70 = F_169 ( V_10 , V_284 , ( void V_87 T_4 * ) V_183 ) ;
F_5 ( V_1 ) ;
return V_70 ;
}
int F_181 ( int V_12 , struct V_2 * V_2 , T_7 * V_177 )
{
struct V_9 * V_10 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_73 ;
if ( ! F_7 ( V_10 ) )
return 1 ;
if ( F_105 ( V_10 -> V_11 , V_2 , V_177 ) )
return 1 ;
return 0 ;
}
static void F_182 ( struct V_295 * V_296 ,
struct V_135 * V_273 ,
int V_297 , char * V_298 )
{
struct V_274 * V_271 ;
struct V_130 * V_281 ;
int V_67 = 0 ;
F_79 ( & V_273 -> V_140 ) ;
if ( F_183 ( & V_273 -> V_274 ) ) {
F_82 ( & V_273 -> V_140 ) ;
return;
}
F_184 ( V_296 , V_298 ) ;
F_164 (p, &group->list_head) {
if ( V_297 )
V_281 = F_165 ( V_271 , struct V_130 , V_282 ) ;
else
V_281 = F_165 ( V_271 , struct V_130 , V_283 ) ;
if ( V_67 ++ )
F_184 ( V_296 , L_10 ) ;
F_184 ( V_296 , L_11 ,
V_297 ? V_281 -> V_141 . V_93 . V_10 : V_281 -> V_141 . V_219 . V_10 ,
V_297 ? V_281 -> V_141 . V_93 . V_90 : V_281 -> V_141 . V_219 . V_90 ) ;
if ( V_281 -> V_141 . V_15 & V_142 )
F_184 ( V_296 , L_12 , ( ( V_281 -> V_141 . V_15 & V_143 ) ? 'r' : 't' ) , V_281 -> V_141 . V_103 ) ;
if ( V_273 -> V_299 )
F_184 ( V_296 , L_13 ) ;
}
F_82 ( & V_273 -> V_140 ) ;
F_184 ( V_296 , L_14 ) ;
}
static void F_185 ( struct V_295 * V_296 ,
struct V_9 * V_10 )
{
struct V_89 * V_271 ;
F_38 ( & V_10 -> V_41 ) ;
F_80 (p, &client->ports_list_head, list) {
F_184 ( V_296 , L_15 ,
V_271 -> V_146 . V_90 , V_271 -> V_65 ,
F_186 ( V_271 -> V_91 ) ,
F_187 ( V_271 -> V_91 ) ,
F_188 ( V_271 -> V_91 ) ,
F_189 ( V_271 -> V_91 ) ) ;
F_182 ( V_296 , & V_271 -> V_138 , 1 , L_16 ) ;
F_182 ( V_296 , & V_271 -> V_213 , 0 , L_17 ) ;
}
F_40 ( & V_10 -> V_41 ) ;
}
void F_190 ( struct V_300 * V_301 ,
struct V_295 * V_296 )
{
int V_37 ;
struct V_9 * V_10 ;
F_184 ( V_296 , L_18 ) ;
F_184 ( V_296 , L_19 , V_48 . V_33 ) ;
F_184 ( V_296 , L_20 , V_48 . V_34 ) ;
F_184 ( V_296 , L_21 , V_13 ) ;
F_184 ( V_296 , L_14 ) ;
for ( V_37 = 0 ; V_37 < V_13 ; V_37 ++ ) {
V_10 = F_11 ( V_37 ) ;
if ( V_10 == NULL )
continue;
if ( V_10 -> type == V_39 ) {
F_65 ( V_10 ) ;
continue;
}
F_184 ( V_296 , L_22 ,
V_37 , V_10 -> V_65 ,
V_10 -> type == V_46 ? L_23 : L_24 ) ;
F_185 ( V_296 , V_10 ) ;
if ( F_7 ( V_10 ) ) {
F_184 ( V_296 , L_25 ) ;
F_191 ( V_296 , V_10 -> V_11 , L_26 ) ;
}
if ( V_10 -> type == V_46 && V_10 -> V_60 . V_53 . V_61 &&
V_10 -> V_60 . V_53 . V_61 -> V_11 ) {
F_184 ( V_296 , L_27 ) ;
F_191 ( V_296 , V_10 -> V_60 . V_53 . V_61 -> V_11 , L_26 ) ;
}
F_65 ( V_10 ) ;
}
}
int T_2 F_192 ( void )
{
int V_54 ;
if ( F_44 ( & V_44 ) )
return - V_55 ;
if ( ( V_54 = F_193 ( V_302 , NULL , 0 ,
& V_303 , NULL , L_28 ) ) < 0 ) {
F_40 ( & V_44 ) ;
return V_54 ;
}
F_40 ( & V_44 ) ;
return 0 ;
}
void T_9 F_194 ( void )
{
F_195 ( V_302 , NULL , 0 ) ;
}
