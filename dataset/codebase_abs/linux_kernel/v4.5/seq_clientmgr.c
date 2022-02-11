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
F_47 ( V_37 ) ;
return 0 ;
}
static int F_48 ( struct V_48 * V_48 , struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
if ( V_10 ) {
F_37 ( V_10 ) ;
if ( V_10 -> V_58 . V_51 . V_59 )
F_49 ( & V_10 -> V_58 . V_51 . V_59 ) ;
F_26 ( V_10 ) ;
}
return 0 ;
}
static T_3 F_50 ( struct V_2 * V_2 , char T_4 * V_64 , T_5 V_65 ,
T_6 * V_66 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
struct V_67 * V_59 ;
int V_52 ;
long V_68 = 0 ;
struct V_69 * V_70 ;
if ( ! ( F_6 ( V_2 ) & V_7 ) )
return - V_71 ;
if ( ! F_51 ( V_72 , V_64 , V_65 ) )
return - V_73 ;
if ( F_52 ( ! V_10 ) )
return - V_71 ;
if ( ! V_10 -> V_56 || ( V_59 = V_10 -> V_58 . V_51 . V_59 ) == NULL )
return - V_71 ;
if ( F_53 ( & V_59 -> V_74 ) > 0 ) {
F_54 ( V_59 ) ;
return - V_75 ;
}
V_70 = NULL ;
V_52 = 0 ;
F_55 ( V_59 ) ;
while ( V_65 >= sizeof( struct V_76 ) ) {
int V_77 ;
V_77 = ( V_2 -> V_78 & V_79 ) || V_68 > 0 ;
if ( ( V_52 = F_56 ( V_59 , & V_70 , V_77 ) ) < 0 ) {
break;
}
if ( F_57 ( & V_70 -> V_80 ) ) {
struct V_76 V_81 ;
V_81 = V_70 -> V_80 ;
V_81 . V_58 . V_82 . V_83 &= ~ V_84 ;
if ( F_58 ( V_64 , & V_81 , sizeof( struct V_76 ) ) ) {
V_52 = - V_73 ;
break;
}
V_65 -= sizeof( struct V_76 ) ;
V_64 += sizeof( struct V_76 ) ;
V_52 = F_59 ( & V_70 -> V_80 , V_65 ,
( char V_85 * ) V_64 , 0 ,
sizeof( struct V_76 ) ) ;
if ( V_52 < 0 )
break;
V_68 += V_52 ;
V_65 -= V_52 ;
V_64 += V_52 ;
} else {
if ( F_58 ( V_64 , & V_70 -> V_80 , sizeof( struct V_76 ) ) ) {
V_52 = - V_73 ;
break;
}
V_65 -= sizeof( struct V_76 ) ;
V_64 += sizeof( struct V_76 ) ;
}
F_60 ( V_70 ) ;
V_70 = NULL ;
V_68 += sizeof( struct V_76 ) ;
}
if ( V_52 < 0 ) {
if ( V_70 )
F_61 ( V_59 , V_70 ) ;
if ( V_52 == - V_86 && V_68 > 0 )
V_52 = 0 ;
}
F_62 ( V_59 ) ;
return ( V_52 < 0 ) ? V_52 : V_68 ;
}
static int F_63 ( struct V_87 * V_88 , unsigned int V_15 )
{
if ( ( V_88 -> V_89 & V_15 ) != V_15 )
return 0 ;
return V_15 ;
}
static struct V_9 * F_64 ( struct V_76 * V_80 ,
int V_90 )
{
struct V_9 * V_91 ;
V_91 = F_11 ( V_80 -> V_91 . V_10 ) ;
if ( V_91 == NULL )
return NULL ;
if ( ! V_91 -> V_56 )
goto V_92;
if ( ( V_91 -> V_90 & V_93 ) &&
! F_65 ( V_80 -> type , V_91 -> V_94 ) )
goto V_92;
if ( V_90 && ! ( V_91 -> V_90 & V_90 ) )
goto V_92;
return V_91 ;
V_92:
F_66 ( V_91 ) ;
return NULL ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_76 * V_80 ,
int V_52 , int V_95 , int V_96 )
{
struct V_76 V_97 ;
int V_68 ;
if ( V_10 == NULL ||
! ( V_10 -> V_90 & V_98 ) ||
! V_10 -> V_56 )
return 0 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . type = V_99 ;
V_97 . V_15 = V_100 ;
V_97 . V_101 = V_102 ;
V_97 . V_103 . V_10 = V_104 ;
V_97 . V_103 . V_88 = V_105 ;
V_97 . V_91 . V_10 = V_10 -> V_43 ;
V_97 . V_91 . V_88 = V_80 -> V_103 . V_88 ;
V_97 . V_58 . V_106 . V_107 = V_80 -> V_91 ;
V_97 . V_58 . V_106 . V_80 = V_80 ;
V_97 . V_58 . V_106 . V_108 = - V_52 ;
V_68 = F_68 ( NULL , & V_97 , 0 , V_95 , V_96 + 1 ) ;
if ( V_68 < 0 ) {
V_10 -> V_109 ++ ;
return V_68 ;
}
return V_68 ;
}
static int F_69 ( struct V_76 * V_80 ,
int V_101 , int V_110 )
{
struct V_111 * V_112 ;
V_112 = F_70 ( V_101 ) ;
if ( ! V_112 )
return 0 ;
V_80 -> V_101 = V_101 ;
V_80 -> V_15 &= ~ V_113 ;
if ( V_110 ) {
V_80 -> time . time = F_71 ( V_112 -> V_114 ) ;
V_80 -> V_15 |= V_115 ;
} else {
V_80 -> time . V_116 = F_72 ( V_112 -> V_114 ) ;
V_80 -> V_15 |= V_117 ;
}
F_73 ( V_112 ) ;
return 1 ;
}
static int F_68 ( struct V_9 * V_10 ,
struct V_76 * V_80 ,
int V_90 , int V_95 , int V_96 )
{
struct V_9 * V_91 = NULL ;
struct V_87 * V_118 = NULL ;
int V_68 = - V_119 ;
int V_120 ;
V_120 = F_74 ( V_80 ) ;
V_91 = F_64 ( V_80 , V_90 ) ;
if ( V_91 == NULL )
goto V_121;
V_118 = F_75 ( V_91 , V_80 -> V_91 . V_88 ) ;
if ( V_118 == NULL )
goto V_121;
if ( ! F_63 ( V_118 , V_122 ) ) {
V_68 = - V_123 ;
goto V_121;
}
if ( V_118 -> V_124 )
F_69 ( V_80 , V_118 -> V_125 ,
V_118 -> V_126 ) ;
switch ( V_91 -> type ) {
case V_45 :
if ( V_91 -> V_58 . V_51 . V_59 )
V_68 = F_76 ( V_91 -> V_58 . V_51 . V_59 , V_80 ) ;
break;
case V_46 :
if ( V_118 -> V_127 == NULL )
break;
V_68 = V_118 -> V_127 ( V_80 , V_120 ,
V_118 -> V_62 ,
V_95 , V_96 ) ;
break;
default:
break;
}
V_121:
if ( V_118 )
F_77 ( V_118 ) ;
if ( V_91 )
F_66 ( V_91 ) ;
if ( V_68 < 0 && ! V_120 ) {
V_68 = F_67 ( V_10 , V_80 , V_68 , V_95 , V_96 ) ;
}
return V_68 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_76 * V_80 ,
int V_95 , int V_96 )
{
struct V_128 * V_129 ;
int V_52 , V_68 = 0 , V_130 = 0 ;
struct V_76 V_131 ;
struct V_87 * V_132 ;
struct V_133 * V_134 ;
V_132 = F_75 ( V_10 , V_80 -> V_103 . V_88 ) ;
if ( V_132 == NULL )
return - V_135 ;
V_131 = * V_80 ;
V_134 = & V_132 -> V_136 ;
if ( V_95 )
F_79 ( & V_134 -> V_137 ) ;
else
F_80 ( & V_134 -> V_138 ) ;
F_81 (subs, &grp->list_head, src_list) {
if ( F_53 ( & V_129 -> V_139 ) != 2 )
continue;
V_80 -> V_91 = V_129 -> V_140 . V_91 ;
if ( V_129 -> V_140 . V_15 & V_141 )
F_69 ( V_80 , V_129 -> V_140 . V_101 ,
V_129 -> V_140 . V_15 & V_142 ) ;
V_52 = F_68 ( V_10 , V_80 ,
0 , V_95 , V_96 ) ;
if ( V_52 < 0 ) {
if ( ! V_68 )
V_68 = V_52 ;
continue;
}
V_130 ++ ;
* V_80 = V_131 ;
}
if ( V_95 )
F_82 ( & V_134 -> V_137 ) ;
else
F_83 ( & V_134 -> V_138 ) ;
* V_80 = V_131 ;
F_77 ( V_132 ) ;
return ( V_68 < 0 ) ? V_68 : V_130 ;
}
static int F_84 ( struct V_9 * V_10 ,
struct V_76 * V_80 ,
int V_95 , int V_96 )
{
int V_130 = 0 , V_52 , V_68 = 0 ;
struct V_9 * V_143 ;
struct V_87 * V_88 ;
V_143 = F_64 ( V_80 , V_144 ) ;
if ( V_143 == NULL )
return 0 ;
F_79 ( & V_143 -> V_40 ) ;
F_81 (port, &dest_client->ports_list_head, list) {
V_80 -> V_91 . V_88 = V_88 -> V_145 . V_88 ;
V_52 = F_68 ( NULL , V_80 ,
V_144 ,
V_95 , V_96 ) ;
if ( V_52 < 0 ) {
if ( ! V_68 )
V_68 = V_52 ;
continue;
}
V_130 ++ ;
}
F_82 ( & V_143 -> V_40 ) ;
F_66 ( V_143 ) ;
V_80 -> V_91 . V_88 = V_146 ;
return ( V_68 < 0 ) ? V_68 : V_130 ;
}
static int F_85 ( struct V_9 * V_10 ,
struct V_76 * V_80 , int V_95 , int V_96 )
{
int V_52 , V_68 = 0 , V_130 = 0 ;
int V_91 ;
struct V_147 V_145 ;
V_145 = V_80 -> V_91 ;
for ( V_91 = 0 ; V_91 < V_13 ; V_91 ++ ) {
if ( V_91 == V_10 -> V_43 )
continue;
V_80 -> V_91 . V_10 = V_91 ;
V_80 -> V_91 . V_88 = V_145 . V_88 ;
if ( V_145 . V_88 == V_146 )
V_52 = F_84 ( V_10 , V_80 , V_95 , V_96 ) ;
else
V_52 = F_68 ( NULL , V_80 ,
V_144 ,
V_95 , V_96 ) ;
if ( V_52 < 0 ) {
if ( ! V_68 )
V_68 = V_52 ;
continue;
}
V_130 += V_52 ;
}
V_80 -> V_91 = V_145 ;
return ( V_68 < 0 ) ? V_68 : V_130 ;
}
static int F_86 ( struct V_9 * V_10 , struct V_76 * V_80 ,
int V_95 , int V_96 )
{
F_10 ( L_6 ) ;
return 0 ;
}
static int F_87 ( struct V_9 * V_10 , struct V_76 * V_80 ,
int V_95 , int V_96 )
{
int V_68 ;
V_96 ++ ;
if ( V_96 >= V_148 ) {
F_10 ( L_7 ,
V_80 -> V_103 . V_10 , V_80 -> V_103 . V_88 ,
V_80 -> V_91 . V_10 , V_80 -> V_91 . V_88 ) ;
return - V_149 ;
}
if ( V_80 -> V_101 == V_150 ||
V_80 -> V_91 . V_10 == V_150 )
V_68 = F_78 ( V_10 , V_80 , V_95 , V_96 ) ;
#ifdef F_88
else if ( V_80 -> V_101 == V_146 ||
V_80 -> V_91 . V_10 == V_146 )
V_68 = F_85 ( V_10 , V_80 , V_95 , V_96 ) ;
else if ( V_80 -> V_91 . V_10 >= V_13 )
V_68 = F_86 ( V_10 , V_80 , V_95 , V_96 ) ;
else if ( V_80 -> V_91 . V_88 == V_146 )
V_68 = F_84 ( V_10 , V_80 , V_95 , V_96 ) ;
#endif
else
V_68 = F_68 ( V_10 , V_80 , 0 , V_95 , V_96 ) ;
return V_68 ;
}
int F_89 ( struct V_69 * V_70 , int V_95 , int V_96 )
{
struct V_9 * V_10 ;
int V_68 ;
if ( F_52 ( ! V_70 ) )
return - V_135 ;
V_10 = F_11 ( V_70 -> V_80 . V_103 . V_10 ) ;
if ( V_10 == NULL ) {
F_60 ( V_70 ) ;
return - V_135 ;
}
if ( V_70 -> V_80 . type == V_151 ) {
struct V_76 V_81 , * V_152 ;
V_81 = V_70 -> V_80 ;
V_81 . type = V_153 ;
V_68 = F_87 ( V_10 , & V_81 , V_95 , V_96 ) ;
V_152 = & V_70 -> V_80 ;
V_152 -> type = V_154 ;
V_152 -> V_15 |= V_155 ;
switch ( V_152 -> V_15 & V_113 ) {
case V_117 :
V_152 -> time . V_116 += V_152 -> V_58 . V_156 . V_157 ;
break;
case V_115 :
V_152 -> time . time . V_158 += 1000000 * ( V_152 -> V_58 . V_156 . V_157 % 1000 ) ;
V_152 -> time . time . V_159 += V_152 -> V_58 . V_156 . V_157 / 1000 +
V_152 -> time . time . V_158 / 1000000000 ;
V_152 -> time . time . V_158 %= 1000000000 ;
break;
}
V_152 -> V_58 . V_156 . V_160 = V_152 -> V_58 . V_156 . V_161 ;
if ( F_90 ( V_70 , V_95 , V_96 ) < 0 )
F_60 ( V_70 ) ;
} else {
V_68 = F_87 ( V_10 , & V_70 -> V_80 , V_95 , V_96 ) ;
F_60 ( V_70 ) ;
}
F_66 ( V_10 ) ;
return V_68 ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_76 * V_80 ,
struct V_2 * V_2 , int V_162 ,
int V_95 , int V_96 )
{
struct V_69 * V_70 ;
int V_52 ;
if ( V_80 -> V_101 == V_150 ) {
V_80 -> V_91 . V_10 = V_150 ;
V_80 -> V_101 = V_102 ;
} else
#ifdef F_88
if ( V_80 -> V_101 == V_146 ) {
V_80 -> V_91 . V_10 = V_146 ;
V_80 -> V_101 = V_102 ;
}
#endif
if ( V_80 -> V_91 . V_10 == V_150 ) {
struct V_87 * V_132 = F_75 ( V_10 , V_80 -> V_103 . V_88 ) ;
if ( V_132 == NULL )
return - V_135 ;
F_77 ( V_132 ) ;
}
if ( F_74 ( V_80 ) ) {
if ( V_80 -> type == V_151 )
return - V_135 ;
return F_87 ( V_10 , V_80 , V_95 , V_96 ) ;
}
if ( F_92 ( V_80 -> V_101 , V_10 -> V_43 ) <= 0 )
return - V_135 ;
if ( ! F_7 ( V_10 ) )
return - V_71 ;
V_52 = F_93 ( V_10 -> V_11 , V_80 , & V_70 , ! V_162 || V_95 , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ( V_52 = F_90 ( V_70 , V_95 , V_96 ) ) < 0 ) {
F_60 ( V_70 ) ;
return V_52 ;
}
return 0 ;
}
static int F_94 ( struct V_76 * V_152 )
{
switch ( F_95 ( V_152 ) ) {
case V_100 :
if ( F_96 ( V_152 ) )
return - V_135 ;
break;
case V_163 :
if ( ! F_96 ( V_152 ) ||
( V_152 -> V_58 . V_82 . V_83 & ~ V_84 ) >= V_164 )
return - V_135 ;
break;
case V_165 :
if ( ! F_74 ( V_152 ) )
return - V_135 ;
break;
}
return 0 ;
}
static T_3 F_97 ( struct V_2 * V_2 , const char T_4 * V_64 ,
T_5 V_65 , T_6 * V_66 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
int V_166 = 0 , V_83 ;
int V_52 = - V_135 ;
struct V_76 V_80 ;
if ( ! ( F_6 ( V_2 ) & V_6 ) )
return - V_71 ;
if ( F_52 ( ! V_10 ) )
return - V_71 ;
if ( ! V_10 -> V_57 || V_10 -> V_11 == NULL )
return - V_71 ;
if ( V_10 -> V_11 -> V_167 > 0 && ! F_7 ( V_10 ) ) {
if ( F_98 ( V_10 -> V_11 ) < 0 )
return - V_55 ;
}
while ( V_65 >= sizeof( struct V_76 ) ) {
V_83 = sizeof( V_80 ) ;
if ( F_99 ( & V_80 , V_64 , V_83 ) ) {
V_52 = - V_73 ;
break;
}
V_80 . V_103 . V_10 = V_10 -> V_43 ;
if ( F_94 ( & V_80 ) ) {
V_52 = - V_135 ;
break;
}
if ( V_80 . type == V_168 )
goto V_169;
else if ( F_100 ( & V_80 ) ) {
V_52 = - V_135 ;
break;
}
if ( F_57 ( & V_80 ) ) {
int V_170 = V_80 . V_58 . V_82 . V_83 & ~ V_84 ;
if ( ( T_5 ) ( V_170 + V_83 ) > V_65 ) {
V_52 = - V_135 ;
break;
}
V_80 . V_58 . V_82 . V_83 = V_170 | V_171 ;
V_80 . V_58 . V_82 . V_172 = ( char V_85 * ) V_64
+ sizeof( struct V_76 ) ;
V_83 += V_170 ;
} else {
#ifdef F_101
if ( V_10 -> V_173 && F_102 ( & V_80 ) ) {
void * V_172 = ( void V_85 * ) F_103 ( V_80 . V_58 . V_174 . V_175 [ 1 ] ) ;
V_80 . V_58 . V_82 . V_172 = V_172 ;
}
#endif
}
V_52 = F_91 ( V_10 , & V_80 , V_2 ,
! ( V_2 -> V_78 & V_79 ) ,
0 , 0 ) ;
if ( V_52 < 0 )
break;
V_169:
V_65 -= V_83 ;
V_64 += V_83 ;
V_166 += V_83 ;
}
return V_166 ? V_166 : V_52 ;
}
static unsigned int F_104 ( struct V_2 * V_2 , T_7 * V_176 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
unsigned int V_177 = 0 ;
if ( F_52 ( ! V_10 ) )
return - V_71 ;
if ( ( F_6 ( V_2 ) & V_7 ) &&
V_10 -> V_58 . V_51 . V_59 ) {
if ( F_105 ( V_10 -> V_58 . V_51 . V_59 , V_2 , V_176 ) )
V_177 |= V_178 | V_179 ;
}
if ( F_6 ( V_2 ) & V_6 ) {
if ( ! F_7 ( V_10 ) ||
F_106 ( V_10 -> V_11 , V_2 , V_176 ) )
V_177 |= V_180 | V_181 ;
}
return V_177 ;
}
static int F_107 ( struct V_9 * V_10 , void T_4 * V_182 )
{
struct V_183 V_140 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_184 = V_185 ;
V_140 . V_186 = V_13 ;
V_140 . V_187 = V_188 ;
V_140 . V_189 = 256 ;
V_140 . V_190 = V_47 . V_33 ;
V_140 . V_191 = F_108 () ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_109 ( struct V_9 * V_10 , void T_4 * V_182 )
{
struct V_192 V_140 ;
struct V_9 * V_193 ;
int V_52 = 0 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_193 = F_11 ( V_140 . V_10 ) ;
if ( V_193 == NULL )
return - V_119 ;
#ifdef F_110
if ( ! V_140 . V_194 ) {
V_52 = - V_135 ;
goto V_195;
}
#else
if ( V_140 . V_194 ) {
V_52 = - V_135 ;
goto V_195;
}
#endif
if ( V_140 . V_196 > sizeof( long ) ) {
V_52 = - V_135 ;
goto V_195;
}
V_193 -> V_173 = ( V_140 . V_196 < sizeof( long ) ) ;
V_195:
F_66 ( V_193 ) ;
return V_52 ;
}
static void F_111 ( struct V_9 * V_193 ,
struct V_197 * V_140 )
{
V_140 -> V_10 = V_193 -> V_43 ;
V_140 -> type = V_193 -> type ;
strcpy ( V_140 -> V_63 , V_193 -> V_63 ) ;
V_140 -> V_90 = V_193 -> V_90 ;
V_140 -> V_109 = V_193 -> V_109 ;
memcpy ( V_140 -> V_94 , V_193 -> V_94 , 32 ) ;
V_140 -> V_198 = V_193 -> V_198 ;
memset ( V_140 -> V_199 , 0 , sizeof( V_140 -> V_199 ) ) ;
}
static int F_112 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_9 * V_193 ;
struct V_197 V_200 ;
if ( F_99 ( & V_200 , V_182 , sizeof( V_200 ) ) )
return - V_73 ;
V_193 = F_11 ( V_200 . V_10 ) ;
if ( V_193 == NULL )
return - V_119 ;
F_111 ( V_193 , & V_200 ) ;
F_66 ( V_193 ) ;
if ( F_58 ( V_182 , & V_200 , sizeof( V_200 ) ) )
return - V_73 ;
return 0 ;
}
static int F_113 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_197 V_200 ;
if ( F_99 ( & V_200 , V_182 , sizeof( V_200 ) ) )
return - V_73 ;
if ( V_10 -> V_43 != V_200 . V_10 )
return - V_123 ;
if ( V_10 -> type != V_200 . type )
return - V_135 ;
if ( V_200 . V_63 [ 0 ] )
F_114 ( V_10 -> V_63 , V_200 . V_63 , sizeof( V_10 -> V_63 ) ) ;
V_10 -> V_90 = V_200 . V_90 ;
V_10 -> V_109 = V_200 . V_109 ;
memcpy ( V_10 -> V_94 , V_200 . V_94 , 32 ) ;
return 0 ;
}
static int F_115 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_87 * V_88 ;
struct V_201 V_140 ;
struct V_202 * V_203 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_145 . V_10 != V_10 -> V_43 )
return - V_123 ;
V_88 = F_116 ( V_10 , ( V_140 . V_15 & V_204 ) ? V_140 . V_145 . V_88 : - 1 ) ;
if ( V_88 == NULL )
return - V_55 ;
if ( V_10 -> type == V_45 && V_140 . V_205 ) {
F_117 ( V_10 , V_88 -> V_145 . V_88 ) ;
return - V_135 ;
}
if ( V_10 -> type == V_46 ) {
if ( ( V_203 = V_140 . V_205 ) != NULL ) {
if ( V_203 -> V_206 )
V_88 -> V_206 = V_203 -> V_206 ;
V_88 -> V_62 = V_203 -> V_62 ;
V_88 -> V_207 = V_203 -> V_207 ;
V_88 -> V_127 = V_203 -> V_127 ;
V_88 -> V_136 . V_208 = V_203 -> V_209 ;
V_88 -> V_136 . V_210 = V_203 -> V_211 ;
V_88 -> V_212 . V_208 = V_203 -> V_213 ;
V_88 -> V_212 . V_210 = V_203 -> V_214 ;
}
}
V_140 . V_145 = V_88 -> V_145 ;
F_118 ( V_88 , & V_140 ) ;
F_119 ( V_88 -> V_145 . V_10 , V_88 -> V_145 . V_88 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_120 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_201 V_140 ;
int V_52 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_145 . V_10 != V_10 -> V_43 )
return - V_123 ;
V_52 = F_117 ( V_10 , V_140 . V_145 . V_88 ) ;
if ( V_52 >= 0 )
F_121 ( V_10 -> V_43 , V_140 . V_145 . V_88 ) ;
return V_52 ;
}
static int F_122 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_9 * V_193 ;
struct V_87 * V_88 ;
struct V_201 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_193 = F_11 ( V_140 . V_145 . V_10 ) ;
if ( V_193 == NULL )
return - V_71 ;
V_88 = F_75 ( V_193 , V_140 . V_145 . V_88 ) ;
if ( V_88 == NULL ) {
F_66 ( V_193 ) ;
return - V_119 ;
}
F_123 ( V_88 , & V_140 ) ;
F_77 ( V_88 ) ;
F_66 ( V_193 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_124 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_87 * V_88 ;
struct V_201 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_145 . V_10 != V_10 -> V_43 )
return - V_123 ;
V_88 = F_75 ( V_10 , V_140 . V_145 . V_88 ) ;
if ( V_88 ) {
F_118 ( V_88 , & V_140 ) ;
F_77 ( V_88 ) ;
}
return 0 ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_87 * V_215 ,
struct V_87 * V_216 ,
struct V_217 * V_129 )
{
if ( V_10 -> V_43 != V_129 -> V_218 . V_10 &&
V_10 -> V_43 != V_129 -> V_91 . V_10 ) {
if ( F_63 ( V_215 , V_219 ) )
return - V_123 ;
if ( F_63 ( V_216 , V_219 ) )
return - V_123 ;
}
if ( V_10 -> V_43 != V_129 -> V_218 . V_10 ) {
if ( ! F_63 ( V_215 , V_220 ) )
return - V_123 ;
}
if ( V_10 -> V_43 != V_129 -> V_91 . V_10 ) {
if ( ! F_63 ( V_216 , V_221 ) )
return - V_123 ;
}
return 0 ;
}
int F_126 ( int V_10 , int V_88 ,
struct V_217 * V_140 ,
int V_222 )
{
struct V_76 V_80 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . type = V_222 ;
V_80 . V_58 . V_223 . V_91 = V_140 -> V_91 ;
V_80 . V_58 . V_223 . V_218 = V_140 -> V_218 ;
return F_127 ( V_10 , V_88 , & V_80 ) ;
}
static int F_128 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 = - V_135 ;
struct V_9 * V_224 = NULL , * V_218 = NULL ;
struct V_87 * V_215 = NULL , * V_216 = NULL ;
struct V_217 V_129 ;
if ( F_99 ( & V_129 , V_182 , sizeof( V_129 ) ) )
return - V_73 ;
if ( ( V_224 = F_11 ( V_129 . V_91 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_218 = F_11 ( V_129 . V_218 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_215 = F_75 ( V_218 , V_129 . V_218 . V_88 ) ) == NULL )
goto V_225;
if ( ( V_216 = F_75 ( V_224 , V_129 . V_91 . V_88 ) ) == NULL )
goto V_225;
V_68 = F_125 ( V_10 , V_215 , V_216 , & V_129 ) ;
if ( V_68 < 0 )
goto V_225;
V_68 = F_129 ( V_10 , V_218 , V_215 , V_224 , V_216 , & V_129 ) ;
if ( ! V_68 )
F_126 ( V_150 , 0 ,
& V_129 , V_226 ) ;
V_225:
if ( V_215 )
F_77 ( V_215 ) ;
if ( V_216 )
F_77 ( V_216 ) ;
if ( V_218 )
F_66 ( V_218 ) ;
if ( V_224 )
F_66 ( V_224 ) ;
return V_68 ;
}
static int F_130 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 = - V_71 ;
struct V_9 * V_224 = NULL , * V_218 = NULL ;
struct V_87 * V_215 = NULL , * V_216 = NULL ;
struct V_217 V_129 ;
if ( F_99 ( & V_129 , V_182 , sizeof( V_129 ) ) )
return - V_73 ;
if ( ( V_224 = F_11 ( V_129 . V_91 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_218 = F_11 ( V_129 . V_218 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_215 = F_75 ( V_218 , V_129 . V_218 . V_88 ) ) == NULL )
goto V_225;
if ( ( V_216 = F_75 ( V_224 , V_129 . V_91 . V_88 ) ) == NULL )
goto V_225;
V_68 = F_125 ( V_10 , V_215 , V_216 , & V_129 ) ;
if ( V_68 < 0 )
goto V_225;
V_68 = F_131 ( V_10 , V_218 , V_215 , V_224 , V_216 , & V_129 ) ;
if ( ! V_68 )
F_126 ( V_150 , 0 ,
& V_129 , V_227 ) ;
V_225:
if ( V_215 )
F_77 ( V_215 ) ;
if ( V_216 )
F_77 ( V_216 ) ;
if ( V_218 )
F_66 ( V_218 ) ;
if ( V_224 )
F_66 ( V_224 ) ;
return V_68 ;
}
static int F_132 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_228 V_140 ;
int V_68 ;
struct V_111 * V_112 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_68 = F_133 ( V_10 -> V_43 , V_140 . V_229 , V_140 . V_15 ) ;
if ( V_68 < 0 )
return V_68 ;
V_112 = F_70 ( V_68 ) ;
if ( V_112 == NULL )
return - V_135 ;
V_140 . V_101 = V_112 -> V_101 ;
V_140 . V_229 = V_112 -> V_229 ;
V_140 . V_206 = V_112 -> V_206 ;
if ( ! V_140 . V_63 [ 0 ] )
snprintf ( V_140 . V_63 , sizeof( V_140 . V_63 ) , L_8 , V_112 -> V_101 ) ;
F_114 ( V_112 -> V_63 , V_140 . V_63 , sizeof( V_112 -> V_63 ) ) ;
F_73 ( V_112 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_134 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_228 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
return F_135 ( V_10 -> V_43 , V_140 . V_101 ) ;
}
static int F_136 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_228 V_140 ;
struct V_111 * V_112 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_112 = F_70 ( V_140 . V_101 ) ;
if ( V_112 == NULL )
return - V_135 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_101 = V_112 -> V_101 ;
V_140 . V_206 = V_112 -> V_206 ;
V_140 . V_229 = V_112 -> V_229 ;
F_114 ( V_140 . V_63 , V_112 -> V_63 , sizeof( V_140 . V_63 ) ) ;
F_73 ( V_112 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_137 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_228 V_140 ;
struct V_111 * V_112 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_206 != V_10 -> V_43 )
return - V_135 ;
if ( F_138 ( V_140 . V_101 , V_10 -> V_43 ) ) {
if ( F_139 ( V_140 . V_101 , V_10 -> V_43 , V_140 . V_229 ) < 0 )
return - V_123 ;
if ( V_140 . V_229 )
F_140 ( V_140 . V_101 , V_10 -> V_43 , 1 ) ;
} else {
return - V_123 ;
}
V_112 = F_70 ( V_140 . V_101 ) ;
if ( ! V_112 )
return - V_135 ;
if ( V_112 -> V_206 != V_10 -> V_43 ) {
F_73 ( V_112 ) ;
return - V_123 ;
}
F_114 ( V_112 -> V_63 , V_140 . V_63 , sizeof( V_112 -> V_63 ) ) ;
F_73 ( V_112 ) ;
return 0 ;
}
static int F_141 ( struct V_9 * V_10 , void T_4 * V_182 )
{
struct V_228 V_140 ;
struct V_111 * V_112 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_112 = F_142 ( V_140 . V_63 ) ;
if ( V_112 == NULL )
return - V_135 ;
V_140 . V_101 = V_112 -> V_101 ;
V_140 . V_206 = V_112 -> V_206 ;
V_140 . V_229 = V_112 -> V_229 ;
F_73 ( V_112 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_143 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_230 V_231 ;
struct V_111 * V_101 ;
struct V_232 * V_233 ;
if ( F_99 ( & V_231 , V_182 , sizeof( V_231 ) ) )
return - V_73 ;
V_101 = F_70 ( V_231 . V_101 ) ;
if ( V_101 == NULL )
return - V_135 ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . V_101 = V_101 -> V_101 ;
V_233 = V_101 -> V_114 ;
V_231 . V_234 = V_101 -> V_235 -> V_236 + V_101 -> V_237 -> V_236 ;
V_231 . time = F_71 ( V_233 ) ;
V_231 . V_116 = F_72 ( V_233 ) ;
V_231 . V_238 = V_233 -> V_238 ;
V_231 . V_15 = V_101 -> V_15 ;
F_73 ( V_101 ) ;
if ( F_58 ( V_182 , & V_231 , sizeof( V_231 ) ) )
return - V_73 ;
return 0 ;
}
static int F_144 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_239 V_240 ;
struct V_111 * V_101 ;
struct V_232 * V_233 ;
if ( F_99 ( & V_240 , V_182 , sizeof( V_240 ) ) )
return - V_73 ;
V_101 = F_70 ( V_240 . V_101 ) ;
if ( V_101 == NULL )
return - V_135 ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_101 = V_101 -> V_101 ;
V_233 = V_101 -> V_114 ;
V_240 . V_240 = V_233 -> V_240 ;
V_240 . V_241 = V_233 -> V_241 ;
V_240 . V_242 = V_233 -> V_243 ;
V_240 . V_244 = V_233 -> V_244 ;
F_73 ( V_101 ) ;
if ( F_58 ( V_182 , & V_240 , sizeof( V_240 ) ) )
return - V_73 ;
return 0 ;
}
int F_145 ( int V_10 , struct V_239 * V_240 )
{
if ( ! F_138 ( V_240 -> V_101 , V_10 ) )
return - V_123 ;
return F_146 ( V_240 -> V_101 , V_10 , V_240 ) ;
}
static int F_147 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 ;
struct V_239 V_240 ;
if ( F_99 ( & V_240 , V_182 , sizeof( V_240 ) ) )
return - V_73 ;
V_68 = F_145 ( V_10 -> V_43 , & V_240 ) ;
return V_68 < 0 ? V_68 : 0 ;
}
static int F_148 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_245 V_114 ;
struct V_111 * V_101 ;
struct V_232 * V_233 ;
if ( F_99 ( & V_114 , V_182 , sizeof( V_114 ) ) )
return - V_73 ;
V_101 = F_70 ( V_114 . V_101 ) ;
if ( V_101 == NULL )
return - V_135 ;
if ( F_45 ( & V_101 -> V_246 ) ) {
F_73 ( V_101 ) ;
return - V_53 ;
}
V_233 = V_101 -> V_114 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_101 = V_101 -> V_101 ;
V_114 . type = V_233 -> type ;
if ( V_233 -> type == V_247 ) {
V_114 . V_248 . V_249 . V_250 = V_233 -> V_251 ;
V_114 . V_248 . V_249 . V_252 = V_233 -> V_253 ;
}
F_41 ( & V_101 -> V_246 ) ;
F_73 ( V_101 ) ;
if ( F_58 ( V_182 , & V_114 , sizeof( V_114 ) ) )
return - V_73 ;
return 0 ;
}
static int F_149 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 = 0 ;
struct V_245 V_114 ;
if ( F_99 ( & V_114 , V_182 , sizeof( V_114 ) ) )
return - V_73 ;
if ( V_114 . type != V_247 )
return - V_135 ;
if ( F_138 ( V_114 . V_101 , V_10 -> V_43 ) ) {
struct V_111 * V_112 ;
struct V_232 * V_233 ;
V_112 = F_70 ( V_114 . V_101 ) ;
if ( V_112 == NULL )
return - V_71 ;
if ( F_45 ( & V_112 -> V_246 ) ) {
F_73 ( V_112 ) ;
return - V_53 ;
}
V_233 = V_112 -> V_114 ;
F_150 ( V_114 . V_101 ) ;
V_233 -> type = V_114 . type ;
if ( V_233 -> type == V_247 ) {
V_233 -> V_251 = V_114 . V_248 . V_249 . V_250 ;
V_233 -> V_253 = V_114 . V_248 . V_249 . V_252 ;
}
V_68 = F_151 ( V_114 . V_101 ) ;
F_41 ( & V_112 -> V_246 ) ;
F_73 ( V_112 ) ;
} else {
return - V_123 ;
}
return V_68 ;
}
static int F_152 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_254 V_140 ;
int V_255 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_255 = F_92 ( V_140 . V_101 , V_10 -> V_43 ) ;
if ( V_255 < 0 )
return - V_135 ;
V_140 . V_255 = V_255 ;
V_140 . V_10 = V_10 -> V_43 ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_153 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_52 ;
struct V_254 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_255 >= 0 ) {
V_52 = F_140 ( V_140 . V_101 , V_10 -> V_43 , V_140 . V_255 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return F_152 ( V_10 , V_182 ) ;
}
static int F_154 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_256 V_140 ;
struct V_9 * V_193 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_193 = F_11 ( V_140 . V_10 ) ;
if ( V_193 == NULL )
return - V_119 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_10 = V_193 -> V_43 ;
V_140 . V_257 = V_193 -> V_11 -> V_167 ;
V_140 . V_258 = V_193 -> V_11 -> V_259 ;
V_140 . V_260 = V_140 . V_257 ;
V_140 . V_260 = F_155 ( V_193 -> V_11 ) ;
if ( V_193 -> type == V_45 ) {
V_140 . V_261 = V_193 -> V_58 . V_51 . V_60 ;
V_140 . V_262 = V_140 . V_261 ;
if ( V_193 -> V_58 . V_51 . V_59 )
V_140 . V_262 = F_155 ( V_193 -> V_58 . V_51 . V_59 -> V_11 ) ;
} else {
V_140 . V_261 = 0 ;
V_140 . V_262 = 0 ;
}
F_66 ( V_193 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_156 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_256 V_140 ;
int V_263 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_10 -> V_43 != V_140 . V_10 )
return - V_135 ;
if ( V_140 . V_257 >= 1 && V_140 . V_257 <= V_264 &&
( ! F_7 ( V_10 ) ||
V_140 . V_257 != V_10 -> V_11 -> V_167 ) ) {
if ( F_7 ( V_10 ) ) {
F_157 ( V_10 -> V_43 ) ;
F_158 ( V_10 -> V_11 ) ;
}
V_10 -> V_11 -> V_167 = V_140 . V_257 ;
V_263 = F_98 ( V_10 -> V_11 ) ;
if ( V_263 < 0 )
return V_263 ;
}
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 != NULL &&
V_140 . V_261 >= 1 &&
V_140 . V_261 <= V_265 &&
V_140 . V_261 != V_10 -> V_58 . V_51 . V_60 ) {
V_263 = F_159 ( V_10 -> V_58 . V_51 . V_59 , V_140 . V_261 ) ;
if ( V_263 < 0 )
return V_263 ;
V_10 -> V_58 . V_51 . V_60 = V_140 . V_261 ;
}
if ( V_140 . V_258 >= 1 &&
V_140 . V_258 <= V_10 -> V_11 -> V_167 ) {
V_10 -> V_11 -> V_259 = V_140 . V_258 ;
}
return F_154 ( V_10 , V_182 ) ;
}
static int F_160 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_266 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
if ( V_140 . V_267 & V_268 ) {
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 )
F_54 ( V_10 -> V_58 . V_51 . V_59 ) ;
}
if ( V_140 . V_267 & V_269 )
F_161 ( V_10 -> V_43 , & V_140 ) ;
return 0 ;
}
static int F_162 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 ;
struct V_9 * V_218 = NULL ;
struct V_87 * V_215 = NULL ;
struct V_217 V_129 ;
struct V_128 * V_270 ;
if ( F_99 ( & V_129 , V_182 , sizeof( V_129 ) ) )
return - V_73 ;
V_68 = - V_135 ;
if ( ( V_218 = F_11 ( V_129 . V_218 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_215 = F_75 ( V_218 , V_129 . V_218 . V_88 ) ) == NULL )
goto V_225;
V_270 = F_163 ( & V_215 -> V_136 , & V_129 . V_91 ) ;
if ( V_270 ) {
V_68 = 0 ;
V_129 = V_270 -> V_140 ;
} else
V_68 = - V_119 ;
V_225:
if ( V_215 )
F_77 ( V_215 ) ;
if ( V_218 )
F_66 ( V_218 ) ;
if ( V_68 >= 0 ) {
if ( F_58 ( V_182 , & V_129 , sizeof( V_129 ) ) )
return - V_73 ;
}
return V_68 ;
}
static int F_164 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
int V_68 = - V_71 ;
struct V_9 * V_193 = NULL ;
struct V_87 * V_88 = NULL ;
struct V_271 V_129 ;
struct V_133 * V_272 ;
struct V_273 * V_270 ;
int V_274 ;
if ( F_99 ( & V_129 , V_182 , sizeof( V_129 ) ) )
return - V_73 ;
if ( ( V_193 = F_11 ( V_129 . V_275 . V_10 ) ) == NULL )
goto V_225;
if ( ( V_88 = F_75 ( V_193 , V_129 . V_275 . V_88 ) ) == NULL )
goto V_225;
switch ( V_129 . type ) {
case V_276 :
V_272 = & V_88 -> V_136 ;
break;
case V_277 :
V_272 = & V_88 -> V_212 ;
break;
default:
goto V_225;
}
F_80 ( & V_272 -> V_138 ) ;
V_129 . V_278 = V_272 -> V_65 ;
V_274 = 0 ;
V_68 = - V_119 ;
F_165 (p, &group->list_head) {
if ( V_274 ++ == V_129 . V_279 ) {
struct V_128 * V_280 ;
if ( V_129 . type == V_276 ) {
V_280 = F_166 ( V_270 , struct V_128 , V_281 ) ;
V_129 . V_145 = V_280 -> V_140 . V_91 ;
} else {
V_280 = F_166 ( V_270 , struct V_128 , V_282 ) ;
V_129 . V_145 = V_280 -> V_140 . V_218 ;
}
V_129 . V_15 = V_280 -> V_140 . V_15 ;
V_129 . V_101 = V_280 -> V_140 . V_101 ;
V_68 = 0 ;
break;
}
}
F_83 ( & V_272 -> V_138 ) ;
V_225:
if ( V_88 )
F_77 ( V_88 ) ;
if ( V_193 )
F_66 ( V_193 ) ;
if ( V_68 >= 0 ) {
if ( F_58 ( V_182 , & V_129 , sizeof( V_129 ) ) )
return - V_73 ;
}
return V_68 ;
}
static int F_167 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_9 * V_193 = NULL ;
struct V_197 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_140 . V_10 ++ ;
if ( V_140 . V_10 < 0 )
V_140 . V_10 = 0 ;
for (; V_140 . V_10 < V_13 ; V_140 . V_10 ++ ) {
V_193 = F_11 ( V_140 . V_10 ) ;
if ( V_193 )
break;
}
if ( V_193 == NULL )
return - V_119 ;
F_111 ( V_193 , & V_140 ) ;
F_66 ( V_193 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_168 ( struct V_9 * V_10 ,
void T_4 * V_182 )
{
struct V_9 * V_193 ;
struct V_87 * V_88 = NULL ;
struct V_201 V_140 ;
if ( F_99 ( & V_140 , V_182 , sizeof( V_140 ) ) )
return - V_73 ;
V_193 = F_11 ( V_140 . V_145 . V_10 ) ;
if ( V_193 == NULL )
return - V_71 ;
V_140 . V_145 . V_88 ++ ;
V_88 = F_169 ( V_193 , & V_140 ) ;
if ( V_88 == NULL ) {
F_66 ( V_193 ) ;
return - V_119 ;
}
V_140 . V_145 = V_88 -> V_145 ;
F_123 ( V_88 , & V_140 ) ;
F_77 ( V_88 ) ;
F_66 ( V_193 ) ;
if ( F_58 ( V_182 , & V_140 , sizeof( V_140 ) ) )
return - V_73 ;
return 0 ;
}
static int F_170 ( struct V_9 * V_10 , unsigned int V_283 ,
void T_4 * V_182 )
{
struct V_284 * V_270 ;
switch ( V_283 ) {
case V_285 :
return F_171 ( V_286 , ( int T_4 * ) V_182 ) ? - V_73 : 0 ;
case V_287 :
return F_171 ( V_10 -> V_43 , ( int T_4 * ) V_182 ) ? - V_73 : 0 ;
}
if ( ! V_182 )
return - V_73 ;
for ( V_270 = V_288 ; V_270 -> V_283 ; V_270 ++ ) {
if ( V_270 -> V_283 == V_283 )
return V_270 -> V_289 ( V_10 , V_182 ) ;
}
F_10 ( L_9 ,
V_283 , F_172 ( V_283 ) , F_173 ( V_283 ) ) ;
return - V_290 ;
}
static long F_174 ( struct V_2 * V_2 , unsigned int V_283 , unsigned long V_182 )
{
struct V_9 * V_10 = V_2 -> V_62 ;
if ( F_52 ( ! V_10 ) )
return - V_71 ;
return F_170 ( V_10 , V_283 , ( void T_4 * ) V_182 ) ;
}
int F_175 ( struct V_291 * V_26 , int V_35 ,
const char * V_292 , ... )
{
struct V_9 * V_10 ;
T_8 args ;
if ( F_52 ( F_15 () ) )
return - V_293 ;
if ( V_26 && V_35 >= V_27 )
return - V_135 ;
if ( V_26 == NULL && V_35 >= V_20 )
return - V_135 ;
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
return - V_293 ;
}
F_20 ( & V_47 , 1 ) ;
V_10 -> V_56 = 1 ;
V_10 -> V_57 = 1 ;
va_start ( args , V_292 ) ;
vsnprintf ( V_10 -> V_63 , sizeof( V_10 -> V_63 ) , V_292 , args ) ;
va_end ( args ) ;
V_10 -> type = V_46 ;
F_41 ( & V_44 ) ;
F_47 ( V_10 -> V_43 ) ;
return V_10 -> V_43 ;
}
int F_176 ( int V_10 )
{
struct V_9 * V_172 ;
if ( F_52 ( F_15 () ) )
return - V_293 ;
V_172 = F_9 ( V_10 ) ;
if ( V_172 == NULL )
return - V_135 ;
F_37 ( V_172 ) ;
F_26 ( V_172 ) ;
return 0 ;
}
static int F_177 ( int V_10 , struct V_76 * V_152 ,
struct V_2 * V_2 , int V_162 ,
int V_95 , int V_96 )
{
struct V_9 * V_193 ;
int V_68 ;
if ( F_52 ( ! V_152 ) )
return - V_135 ;
if ( V_152 -> type == V_168 )
return 0 ;
if ( V_152 -> type == V_99 )
return - V_135 ;
V_152 -> V_103 . V_10 = V_10 ;
if ( F_94 ( V_152 ) )
return - V_135 ;
V_193 = F_11 ( V_10 ) ;
if ( V_193 == NULL )
return - V_135 ;
if ( ! V_193 -> V_57 )
V_68 = - V_123 ;
else
V_68 = F_91 ( V_193 , V_152 , V_2 , V_162 , V_95 , V_96 ) ;
F_66 ( V_193 ) ;
return V_68 ;
}
int F_178 ( int V_10 , struct V_76 * V_152 ,
int V_95 , int V_96 )
{
return F_177 ( V_10 , V_152 , NULL , 0 , V_95 , V_96 ) ;
}
int F_179 ( int V_10 , struct V_76 * V_152 ,
struct V_2 * V_2 ,
int V_95 , int V_96 )
{
return F_177 ( V_10 , V_152 , V_2 , 1 , V_95 , V_96 ) ;
}
int F_180 ( int V_10 , struct V_76 * V_152 ,
int V_95 , int V_96 )
{
struct V_9 * V_193 ;
int V_68 ;
if ( F_52 ( ! V_152 ) )
return - V_135 ;
V_152 -> V_101 = V_102 ;
V_152 -> V_103 . V_10 = V_10 ;
if ( F_94 ( V_152 ) )
return - V_135 ;
V_193 = F_11 ( V_10 ) ;
if ( V_193 == NULL )
return - V_135 ;
if ( ! V_193 -> V_57 )
V_68 = - V_123 ;
else
V_68 = F_87 ( V_193 , V_152 , V_95 , V_96 ) ;
F_66 ( V_193 ) ;
return V_68 ;
}
int F_181 ( int V_12 , unsigned int V_283 , void * V_182 )
{
struct V_9 * V_10 ;
T_1 V_1 ;
int V_68 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_71 ;
V_1 = F_1 () ;
V_68 = F_170 ( V_10 , V_283 , ( void V_85 T_4 * ) V_182 ) ;
F_5 ( V_1 ) ;
return V_68 ;
}
int F_182 ( int V_12 , struct V_2 * V_2 , T_7 * V_176 )
{
struct V_9 * V_10 ;
V_10 = F_9 ( V_12 ) ;
if ( V_10 == NULL )
return - V_71 ;
if ( ! F_7 ( V_10 ) )
return 1 ;
if ( F_106 ( V_10 -> V_11 , V_2 , V_176 ) )
return 1 ;
return 0 ;
}
static void F_183 ( struct V_294 * V_295 ,
struct V_133 * V_272 ,
int V_296 , char * V_297 )
{
struct V_273 * V_270 ;
struct V_128 * V_280 ;
int V_65 = 0 ;
F_80 ( & V_272 -> V_138 ) ;
if ( F_184 ( & V_272 -> V_273 ) ) {
F_83 ( & V_272 -> V_138 ) ;
return;
}
F_185 ( V_295 , V_297 ) ;
F_165 (p, &group->list_head) {
if ( V_296 )
V_280 = F_166 ( V_270 , struct V_128 , V_281 ) ;
else
V_280 = F_166 ( V_270 , struct V_128 , V_282 ) ;
if ( V_65 ++ )
F_185 ( V_295 , L_10 ) ;
F_185 ( V_295 , L_11 ,
V_296 ? V_280 -> V_140 . V_91 . V_10 : V_280 -> V_140 . V_218 . V_10 ,
V_296 ? V_280 -> V_140 . V_91 . V_88 : V_280 -> V_140 . V_218 . V_88 ) ;
if ( V_280 -> V_140 . V_15 & V_141 )
F_185 ( V_295 , L_12 , ( ( V_280 -> V_140 . V_15 & V_142 ) ? 'r' : 't' ) , V_280 -> V_140 . V_101 ) ;
if ( V_272 -> V_298 )
F_185 ( V_295 , L_13 ) ;
}
F_83 ( & V_272 -> V_138 ) ;
F_185 ( V_295 , L_14 ) ;
}
static void F_186 ( struct V_294 * V_295 ,
struct V_9 * V_10 )
{
struct V_87 * V_270 ;
F_38 ( & V_10 -> V_41 ) ;
F_81 (p, &client->ports_list_head, list) {
F_185 ( V_295 , L_15 ,
V_270 -> V_145 . V_88 , V_270 -> V_63 ,
F_187 ( V_270 -> V_89 ) ,
F_188 ( V_270 -> V_89 ) ,
F_189 ( V_270 -> V_89 ) ,
F_190 ( V_270 -> V_89 ) ) ;
F_183 ( V_295 , & V_270 -> V_136 , 1 , L_16 ) ;
F_183 ( V_295 , & V_270 -> V_212 , 0 , L_17 ) ;
}
F_41 ( & V_10 -> V_41 ) ;
}
void F_191 ( struct V_299 * V_300 ,
struct V_294 * V_295 )
{
int V_37 ;
struct V_9 * V_10 ;
F_185 ( V_295 , L_18 ) ;
F_185 ( V_295 , L_19 , V_47 . V_33 ) ;
F_185 ( V_295 , L_20 , V_47 . V_34 ) ;
F_185 ( V_295 , L_21 , V_13 ) ;
F_185 ( V_295 , L_14 ) ;
for ( V_37 = 0 ; V_37 < V_13 ; V_37 ++ ) {
V_10 = F_11 ( V_37 ) ;
if ( V_10 == NULL )
continue;
if ( V_10 -> type == V_39 ) {
F_66 ( V_10 ) ;
continue;
}
F_185 ( V_295 , L_22 ,
V_37 , V_10 -> V_63 ,
V_10 -> type == V_45 ? L_23 : L_24 ) ;
F_186 ( V_295 , V_10 ) ;
if ( F_7 ( V_10 ) ) {
F_185 ( V_295 , L_25 ) ;
F_192 ( V_295 , V_10 -> V_11 , L_26 ) ;
}
if ( V_10 -> type == V_45 && V_10 -> V_58 . V_51 . V_59 &&
V_10 -> V_58 . V_51 . V_59 -> V_11 ) {
F_185 ( V_295 , L_27 ) ;
F_192 ( V_295 , V_10 -> V_58 . V_51 . V_59 -> V_11 , L_26 ) ;
}
F_66 ( V_10 ) ;
}
}
int T_2 F_193 ( void )
{
int V_52 ;
F_194 ( & V_301 , NULL ) ;
F_195 ( & V_301 , L_28 ) ;
if ( F_45 ( & V_44 ) )
return - V_53 ;
V_52 = F_196 ( V_302 , NULL , 0 ,
& V_303 , NULL , & V_301 ) ;
if ( V_52 < 0 ) {
F_41 ( & V_44 ) ;
F_197 ( & V_301 ) ;
return V_52 ;
}
F_41 ( & V_44 ) ;
return 0 ;
}
void T_9 F_198 ( void )
{
F_199 ( & V_301 ) ;
F_197 ( & V_301 ) ;
}
