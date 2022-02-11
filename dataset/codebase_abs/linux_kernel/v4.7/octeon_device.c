static void F_1 ( int V_1 , int V_2 )
{
if ( V_2 < 0 || V_2 > ( V_3 - 1 ) )
V_2 = V_4 ;
V_5 [ V_1 ] . V_2 = V_2 ;
}
void F_2 ( int V_2 )
{
int V_6 ;
memset ( V_7 , 0 , ( sizeof( void * ) * V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_1 ( V_6 , V_2 ) ;
}
static void * F_3 ( struct V_7 * V_9 ,
T_1 V_10 )
{
T_2 V_1 = V_9 -> V_11 ;
void * V_12 = NULL ;
switch ( V_5 [ V_1 ] . V_2 ) {
case V_4 :
if ( V_9 -> V_13 == V_14 ) {
V_12 = ( void * ) & V_15 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_17 ) ) {
V_12 = ( void * ) & V_18 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_19 ) ) {
V_12 = ( void * ) & V_20 ;
}
break;
default:
break;
}
return V_12 ;
}
static int F_4 ( struct V_7 * V_9 , void * V_21 )
{
switch ( V_9 -> V_13 ) {
case V_14 :
case V_16 :
return F_5 ( V_9 , V_21 ) ;
default:
break;
}
return 1 ;
}
void * F_6 ( struct V_7 * V_9 , T_1 V_10 )
{
void * V_21 = NULL ;
V_21 = F_3 ( V_9 , V_10 ) ;
if ( ! V_21 )
return NULL ;
if ( F_4 ( V_9 , V_21 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_1 ) ;
return NULL ;
}
return V_21 ;
}
char * F_8 ( T_3 * V_24 )
{
T_4 V_25 = ( T_4 ) F_9 ( V_24 ) ;
if ( V_25 > V_26 || V_25 < 0 )
return V_27 [ V_28 ] ;
return V_27 [ V_25 ] ;
}
static char * F_10 ( T_2 V_29 )
{
if ( V_29 <= V_30 )
return V_31 [ V_29 - V_32 ] ;
return V_31 [ V_33 - V_32 ] ;
}
int F_11 ( struct V_7 * V_9 , const T_5 * V_34 ,
T_6 V_35 )
{
int V_12 = 0 ;
T_5 * V_36 ;
T_5 * V_37 ;
T_2 V_38 ;
T_7 V_39 ;
T_2 V_40 ;
struct V_41 * V_42 ;
T_2 V_6 ;
if ( V_35 < sizeof( struct V_41 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_2 ,
( T_2 ) V_35 ,
( T_2 ) sizeof( struct V_41 ) ) ;
return - V_43 ;
}
V_42 = (struct V_41 * ) V_34 ;
if ( F_12 ( V_42 -> V_44 ) != V_45 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_3 ) ;
return - V_43 ;
}
V_38 =
F_13 ( ~ 0 , V_34 ,
sizeof( struct V_41 ) -
sizeof( T_2 ) ) ^ ~ 0U ;
if ( V_38 != F_12 ( V_42 -> F_13 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_4 ,
V_38 , F_12 ( V_42 -> F_13 ) ) ;
return - V_43 ;
}
if ( memcmp ( V_46 , V_42 -> V_47 , strlen ( V_46 ) ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_5 ,
V_46 , V_42 -> V_47 ) ;
return - V_43 ;
}
if ( F_12 ( V_42 -> V_48 ) > V_49 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_6 ,
F_12 ( V_42 -> V_48 ) ) ;
return - V_43 ;
}
F_14 ( & V_9 -> V_22 -> V_23 , L_7 , V_42 -> V_47 ) ;
snprintf ( V_9 -> V_50 . V_51 , 32 , L_8 ,
V_42 -> V_47 ) ;
V_37 = F_15 ( V_34 , V_35 , V_52 ) ;
if ( ! V_37 )
return - V_53 ;
V_36 = V_37 + sizeof( struct V_41 ) ;
for ( V_6 = 0 ; V_6 < F_12 ( V_42 -> V_48 ) ; V_6 ++ ) {
V_39 = F_16 ( V_42 -> V_54 [ V_6 ] . V_55 ) ;
V_40 = F_12 ( V_42 -> V_54 [ V_6 ] . V_56 ) ;
V_38 = F_13 ( ~ 0 , V_36 , V_40 ) ^ ~ 0U ;
if ( V_38 != F_12 ( V_42 -> V_54 [ V_6 ] . F_13 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_9 ,
V_6 , V_38 ,
F_12 ( V_42 -> V_54 [ V_6 ] . F_13 ) ) ;
V_12 = - V_43 ;
goto V_57;
}
F_17 ( V_9 , V_39 , V_36 , V_40 ) ;
V_36 += V_40 ;
F_18 ( & V_9 -> V_22 -> V_23 ,
L_10 ,
V_6 , V_40 , V_39 ) ;
}
V_12 = F_19 ( V_9 , V_42 -> V_58 , 50 ) ;
V_57:
F_20 ( V_37 ) ;
return V_12 ;
}
void F_21 ( struct V_7 * V_9 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_59 ; V_6 ++ ) {
F_22 ( V_9 -> V_60 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_61 ; V_6 ++ ) {
F_22 ( V_9 -> V_62 [ V_6 ] ) ;
}
V_6 = V_9 -> V_11 ;
F_22 ( V_9 ) ;
V_7 [ V_6 ] = NULL ;
V_63 -- ;
}
static struct V_7 * F_23 ( T_2 V_64 ,
T_2 V_65 )
{
struct V_7 * V_9 ;
T_5 * V_66 = NULL ;
T_2 V_67 = 0 , V_68 = 0 , V_35 ;
switch ( V_64 ) {
case V_16 :
case V_14 :
V_68 = sizeof( struct V_69 ) ;
break;
default:
F_24 ( L_11 ,
V_70 ,
V_64 ) ;
return NULL ;
}
if ( V_68 & 0x7 )
V_68 += ( 8 - ( V_68 & 0x7 ) ) ;
V_67 = sizeof( struct V_7 ) ;
if ( V_67 & 0x7 )
V_67 += ( 8 - ( V_67 & 0x7 ) ) ;
if ( V_65 & 0x7 )
V_65 += ( 8 - ( V_65 & 0x7 ) ) ;
V_35 = V_67 + V_65 + V_68 +
( sizeof( struct V_71 ) * V_72 ) ;
V_66 = F_25 ( V_35 ) ;
if ( ! V_66 )
return NULL ;
memset ( V_66 , 0 , V_35 ) ;
V_9 = (struct V_7 * ) V_66 ;
V_9 -> V_73 = ( void * ) ( V_66 + V_67 ) ;
V_9 -> V_74 = ( void * ) ( V_66 + V_67 + V_65 ) ;
V_9 -> V_75 . V_76 = (struct V_71 * )
( V_66 + V_67 + V_65 + V_68 ) ;
return V_9 ;
}
struct V_7 * F_26 ( T_2 V_64 ,
T_2 V_65 )
{
T_2 V_77 = 0 ;
struct V_7 * V_9 = NULL ;
for ( V_77 = 0 ; V_77 < V_8 ; V_77 ++ )
if ( ! V_7 [ V_77 ] )
break;
if ( V_77 == V_8 )
return NULL ;
V_9 = F_23 ( V_64 , V_65 ) ;
if ( ! V_9 )
return NULL ;
F_27 ( & V_9 -> V_78 ) ;
F_27 ( & V_9 -> V_79 ) ;
V_63 ++ ;
V_7 [ V_77 ] = V_9 ;
V_9 -> V_11 = V_77 ;
snprintf ( ( V_9 -> V_80 ) , sizeof( V_9 -> V_80 ) ,
L_12 , ( V_9 -> V_11 ) ) ;
return V_9 ;
}
int F_28 ( struct V_7 * V_9 )
{
T_2 V_6 , V_81 = 0 ;
T_2 V_82 = 0 ;
if ( F_29 ( V_9 ) ) {
V_81 = 1 ;
V_82 =
F_30 ( F_31 ( V_9 , V_83 , V_21 ) ) ;
}
V_9 -> V_81 = 0 ;
for ( V_6 = 0 ; V_6 < V_81 ; V_6 ++ ) {
V_9 -> V_62 [ V_6 ] =
F_25 ( sizeof( struct V_84 ) ) ;
if ( ! V_9 -> V_62 [ V_6 ] )
return 1 ;
memset ( V_9 -> V_62 [ V_6 ] , 0 ,
sizeof( struct V_84 ) ) ;
V_9 -> V_62 [ V_6 ] -> V_85 = ( void * ) ( T_6 ) V_6 ;
if ( F_32 ( V_9 , V_6 , V_82 ) )
return 1 ;
V_9 -> V_81 ++ ;
}
return 0 ;
}
int F_33 ( struct V_7 * V_9 )
{
T_2 V_6 , V_86 = 0 ;
T_2 V_82 = 0 ;
T_2 V_87 = 0 ;
if ( F_29 ( V_9 ) ) {
V_86 = 1 ;
V_82 =
F_34 ( F_31 ( V_9 , V_83 , V_21 ) ) ;
V_87 =
F_35 ( F_31 ( V_9 , V_83 , V_21 ) ) ;
}
V_9 -> V_86 = 0 ;
for ( V_6 = 0 ; V_6 < V_86 ; V_6 ++ ) {
V_9 -> V_60 [ V_6 ] = F_25 ( sizeof( * V_9 -> V_60 [ V_6 ] ) ) ;
if ( ! V_9 -> V_60 [ V_6 ] )
return 1 ;
memset ( V_9 -> V_60 [ V_6 ] , 0 , sizeof( struct V_88 ) ) ;
if ( F_36 ( V_9 , V_6 , V_82 , V_87 , NULL ) )
return 1 ;
V_9 -> V_86 ++ ;
}
return 0 ;
}
void F_37 ( struct V_7 * V_9 )
{
F_38 ( V_9 , V_89 , 0 ) ;
F_38 ( V_9 , V_90 , 0 ) ;
}
void F_39 ( struct V_7 * V_9 ,
T_2 V_91 ,
T_2 V_92 )
{
T_2 V_93 = 0 ;
V_93 = F_40 ( V_9 , V_90 ) ;
if ( V_92 )
V_93 = V_93 | ( 1 << V_91 ) ;
else
V_93 = V_93 & ( ~ ( 1 << V_91 ) ) ;
F_38 ( V_9 , V_90 , V_93 ) ;
}
int F_41 ( struct V_7 * V_9 )
{
T_2 V_6 ;
V_9 -> V_75 . V_94 = 0 ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ ) {
V_9 -> V_75 . V_76 [ V_6 ] . V_95 = 0 ;
F_42 ( & V_9 -> V_75 . V_76 [ V_6 ] . V_96 ) ;
}
for ( V_6 = 0 ; V_6 <= V_97 ; V_6 ++ )
F_43 ( V_9 , V_6 , NULL ) ;
F_27 ( & V_9 -> V_75 . V_98 ) ;
return 0 ;
}
void F_44 ( struct V_7 * V_9 )
{
T_2 V_6 ;
struct V_99 V_100 , * V_101 , * V_102 ;
F_42 ( & V_100 ) ;
F_45 ( & V_9 -> V_75 . V_98 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ ) {
struct V_99 * V_75 ;
V_75 = & V_9 -> V_75 . V_76 [ V_6 ] . V_96 ;
while ( V_75 -> V_103 != V_75 ) {
V_101 = V_75 -> V_103 ;
F_46 ( V_101 ) ;
F_47 ( V_101 , & V_100 ) ;
}
V_9 -> V_75 . V_76 [ V_6 ] . V_95 = 0 ;
}
V_9 -> V_75 . V_94 = 0 ;
F_48 ( & V_9 -> V_75 . V_98 ) ;
F_49 (temp, tmp2, &freelist) {
F_46 ( V_101 ) ;
F_22 ( V_101 ) ;
}
}
T_8
F_50 ( struct V_7 * V_104 , T_1 V_95 ,
T_1 V_105 )
{
T_2 V_106 ;
struct V_99 * V_75 ;
T_8 V_107 = NULL ;
T_1 V_108 = F_51 ( V_95 , V_105 ) ;
V_106 = V_108 & V_109 ;
F_45 ( & V_104 -> V_75 . V_98 ) ;
if ( V_104 -> V_75 . V_94 == 0 ) {
F_48 ( & V_104 -> V_75 . V_98 ) ;
return NULL ;
}
if ( ! ( V_104 -> V_75 . V_76 [ V_106 ] . V_95 ) ) {
F_48 ( & V_104 -> V_75 . V_98 ) ;
return NULL ;
}
if ( V_104 -> V_75 . V_76 [ V_106 ] . V_95 == V_108 ) {
V_107 = V_104 -> V_75 . V_76 [ V_106 ] . V_110 ;
} else {
F_52 (dispatch,
&octeon_dev->dispatch.dlist[idx].list) {
if ( ( (struct V_71 * ) V_75 ) -> V_95 ==
V_108 ) {
V_107 = ( (struct V_71 * )
V_75 ) -> V_110 ;
break;
}
}
}
F_48 ( & V_104 -> V_75 . V_98 ) ;
return V_107 ;
}
int
F_53 ( struct V_7 * V_9 ,
T_1 V_95 ,
T_1 V_105 ,
T_8 V_107 , void * V_111 )
{
T_2 V_106 ;
T_8 V_112 ;
T_1 V_108 = F_51 ( V_95 , V_105 ) ;
V_106 = V_108 & V_109 ;
F_45 ( & V_9 -> V_75 . V_98 ) ;
if ( V_9 -> V_75 . V_76 [ V_106 ] . V_95 == 0 ) {
V_9 -> V_75 . V_76 [ V_106 ] . V_95 = V_108 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_110 = V_107 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_113 = V_111 ;
V_9 -> V_75 . V_94 ++ ;
F_48 ( & V_9 -> V_75 . V_98 ) ;
return 0 ;
}
F_48 ( & V_9 -> V_75 . V_98 ) ;
V_112 = F_50 ( V_9 , V_95 , V_105 ) ;
if ( ! V_112 ) {
struct V_71 * V_75 ;
F_18 ( & V_9 -> V_22 -> V_23 ,
L_13 ) ;
V_75 = (struct V_71 * )
F_25 ( sizeof( struct V_71 ) ) ;
if ( ! V_75 ) {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_14 ) ;
return 1 ;
}
V_75 -> V_95 = V_108 ;
V_75 -> V_110 = V_107 ;
V_75 -> V_113 = V_111 ;
F_45 ( & V_9 -> V_75 . V_98 ) ;
F_54 ( & V_75 -> V_96 , & V_9 -> V_75 . V_76 [ V_106 ] . V_96 ) ;
V_9 -> V_75 . V_94 ++ ;
F_48 ( & V_9 -> V_75 . V_98 ) ;
} else {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_15 ,
V_95 , V_105 ) ;
return 1 ;
}
return 0 ;
}
int
F_55 ( struct V_7 * V_9 , T_1 V_95 ,
T_1 V_105 )
{
int V_114 = 0 ;
T_2 V_106 ;
struct V_99 * V_75 , * V_115 = NULL , * V_102 ;
T_1 V_108 = F_51 ( V_95 , V_105 ) ;
V_106 = V_108 & V_109 ;
F_45 ( & V_9 -> V_75 . V_98 ) ;
if ( V_9 -> V_75 . V_94 == 0 ) {
F_48 ( & V_9 -> V_75 . V_98 ) ;
F_7 ( & V_9 -> V_22 -> V_23 ,
L_16 ) ;
return 1 ;
}
if ( V_9 -> V_75 . V_76 [ V_106 ] . V_95 == V_108 ) {
V_75 = & V_9 -> V_75 . V_76 [ V_106 ] . V_96 ;
if ( V_75 -> V_103 != V_75 ) {
V_75 = V_75 -> V_103 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_95 =
( (struct V_71 * ) V_75 ) -> V_95 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_110 =
( (struct V_71 * )
V_75 ) -> V_110 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_113 =
( (struct V_71 * ) V_75 ) -> V_113 ;
F_46 ( V_75 ) ;
V_115 = V_75 ;
} else {
V_9 -> V_75 . V_76 [ V_106 ] . V_95 = 0 ;
V_9 -> V_75 . V_76 [ V_106 ] . V_110 = NULL ;
V_9 -> V_75 . V_76 [ V_106 ] . V_113 = NULL ;
}
} else {
V_114 = 1 ;
F_49 (dispatch, tmp2,
&(oct->dispatch.dlist[idx].
list)) {
if ( ( (struct V_71 * ) V_75 ) -> V_95 ==
V_108 ) {
F_46 ( V_75 ) ;
V_115 = V_75 ;
V_114 = 0 ;
}
}
}
if ( ! V_114 )
V_9 -> V_75 . V_94 -- ;
F_48 ( & V_9 -> V_75 . V_98 ) ;
F_22 ( V_115 ) ;
return V_114 ;
}
int F_56 ( struct V_116 * V_117 , void * V_66 )
{
T_2 V_6 ;
char V_118 [ 16 ] ;
struct V_7 * V_9 = (struct V_7 * ) V_66 ;
struct V_119 * V_120 = V_117 -> V_120 ;
struct V_121 * V_122 = NULL ;
T_2 V_123 = 0 ;
if ( F_29 ( V_9 ) )
V_123 =
F_57 ( F_31 ( V_9 , V_83 , V_21 ) ) ;
if ( F_9 ( & V_9 -> V_124 ) >= V_125 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_17 ,
F_9 ( & V_9 -> V_124 ) ) ;
goto V_126;
}
strncpy ( V_118 ,
F_10 (
( T_2 ) V_120 -> V_127 . V_128 . V_29 ) ,
sizeof( V_118 ) - 1 ) ;
V_9 -> V_29 = ( T_2 ) V_120 -> V_127 . V_128 . V_29 ;
if ( V_120 -> V_127 . V_128 . V_29 == V_129 ) {
V_9 -> V_50 . V_130 =
( T_2 ) V_120 -> V_127 . V_128 . V_130 ;
V_9 -> V_50 . V_131 =
( T_2 ) V_120 -> V_127 . V_128 . V_131 ;
}
if ( V_9 -> V_50 . V_130 < V_123 ) {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_18 ,
V_123 , V_9 -> V_50 . V_130 ) ;
goto V_126;
}
V_9 -> V_50 . V_132 = V_120 -> V_127 . V_128 . V_132 ;
V_9 -> V_50 . V_29 = ( T_2 ) V_120 -> V_127 . V_128 . V_29 ;
F_58 ( & V_9 -> V_124 , V_133 ) ;
V_122 = & V_134 [ V_9 -> V_11 ] ;
if ( V_120 -> V_135 [ 0 ] != sizeof( * V_122 ) ) {
F_18 ( & V_9 -> V_22 -> V_23 , L_19 ,
( T_2 ) sizeof( * V_122 ) ,
V_120 -> V_135 [ 0 ] ) ;
}
memcpy ( V_122 , F_59 ( V_120 -> V_136 [ 0 ] ) , sizeof( * V_122 ) ) ;
strncpy ( V_9 -> V_137 . V_138 , V_122 -> V_139 , V_140 ) ;
strncpy ( V_9 -> V_137 . V_141 , V_122 -> V_142 ,
V_143 ) ;
F_60 ( ( T_7 * ) V_122 , ( sizeof( * V_122 ) >> 3 ) ) ;
V_9 -> V_137 . V_144 = V_122 -> V_145 ;
V_9 -> V_137 . V_146 = V_122 -> V_147 ;
F_14 ( & V_9 -> V_22 -> V_23 ,
L_20 ,
V_118 , F_61 ( V_122 -> V_148 ) ) ;
V_126:
for ( V_6 = 0 ; V_6 < V_120 -> V_149 ; V_6 ++ )
F_62 ( V_120 -> V_136 [ V_6 ] ) ;
F_63 ( V_117 ) ;
return 0 ;
}
int F_64 ( struct V_7 * V_9 , T_2 V_91 )
{
if ( V_9 && ( V_91 < V_61 ) &&
( V_9 -> V_150 . V_151 & ( 1UL << V_91 ) ) )
return V_9 -> V_62 [ V_91 ] -> V_152 ;
return - 1 ;
}
int F_65 ( struct V_7 * V_9 , T_2 V_91 )
{
if ( V_9 && ( V_91 < V_59 ) &&
( V_9 -> V_150 . V_153 & ( 1UL << V_91 ) ) )
return V_9 -> V_60 [ V_91 ] -> V_152 ;
return - 1 ;
}
struct V_154 * F_66 ( struct V_7 * V_9 )
{
struct V_154 * V_155 = NULL ;
if ( F_29 ( V_9 ) ) {
V_155 =
(struct V_154 * ) ( F_31 ( V_9 , V_83 , V_21 ) ) ;
}
return V_155 ;
}
struct V_7 * F_67 ( T_2 V_11 )
{
if ( V_11 >= V_8 )
return NULL ;
else
return V_7 [ V_11 ] ;
}
T_7 F_68 ( struct V_7 * V_9 , T_7 V_55 )
{
T_7 V_156 ;
unsigned long V_157 ;
T_2 V_158 , V_159 ;
F_69 ( & V_9 -> V_78 , V_157 ) ;
V_159 = ( V_55 >> 32 ) ;
if ( ( V_9 -> V_13 == V_14 ) || ( V_9 -> V_13 == V_16 ) )
V_159 |= 0x00060000 ;
F_70 ( V_159 , V_9 -> V_160 . V_161 ) ;
V_158 = F_71 ( V_9 -> V_160 . V_161 ) ;
F_70 ( V_55 & 0xffffffff , V_9 -> V_160 . V_162 ) ;
V_158 = F_71 ( V_9 -> V_160 . V_162 ) ;
V_156 = F_72 ( V_9 -> V_160 . V_163 ) ;
F_73 ( & V_9 -> V_78 , V_157 ) ;
return V_156 ;
}
void F_74 ( struct V_7 * V_9 ,
T_7 V_164 ,
T_7 V_55 )
{
T_2 V_158 ;
unsigned long V_157 ;
F_69 ( & V_9 -> V_78 , V_157 ) ;
F_75 ( V_55 , V_9 -> V_160 . V_165 ) ;
F_70 ( V_164 >> 32 , V_9 -> V_160 . V_166 ) ;
V_158 = F_71 ( V_9 -> V_160 . V_166 ) ;
F_70 ( V_164 & 0xffffffff , V_9 -> V_160 . V_167 ) ;
F_73 ( & V_9 -> V_78 , V_157 ) ;
}
int F_76 ( struct V_7 * V_9 )
{
T_7 V_168 = 0 ;
T_7 V_169 = F_68 ( V_9 , V_170 ) ;
V_168 = ( V_169 & V_171 ) ;
return V_168 ? 0 : 1 ;
}
int F_77 ( struct V_7 * V_9 , T_2 * V_172 )
{
int V_12 = 1 ;
T_2 V_173 ;
if ( ! V_172 )
return V_12 ;
while ( * V_172 == 0 )
F_78 ( V_174 / 10 ) ;
for ( V_173 = 0 ; ( V_12 != 0 ) && ( ( * V_172 == 0 ) || ( V_173 <= * V_172 ) ) ;
V_173 += V_174 / 10 ) {
V_12 = F_76 ( V_9 ) ;
if ( V_12 )
F_78 ( V_174 / 10 ) ;
}
return V_12 ;
}
int F_79 ( void * V_23 )
{
struct V_7 * V_104 = (struct V_7 * ) V_23 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( V_7 [ V_6 ] == V_104 )
return V_104 -> V_11 ;
return - 1 ;
}
