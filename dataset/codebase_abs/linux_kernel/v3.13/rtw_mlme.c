int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_10 = V_11 ;
V_12 ;
V_8 -> V_13 = ( T_1 * ) V_2 ;
V_8 -> V_14 = NULL ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 . V_17 . V_18 = V_19 ;
V_8 -> V_20 = V_21 ;
F_2 ( & ( V_8 -> V_22 ) ) ;
F_3 ( & ( V_8 -> V_23 ) ) ;
F_3 ( & ( V_8 -> V_24 ) ) ;
F_4 ( V_8 , 0 ) ;
F_5 ( & V_8 -> V_25 , 0 , sizeof( struct V_26 ) ) ;
V_4 = F_6 ( V_27 * ( sizeof( struct V_5 ) ) ) ;
if ( V_4 == NULL ) {
V_10 = V_28 ;
goto exit;
}
V_8 -> V_29 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_27 ; V_3 ++ ) {
F_7 ( & ( V_6 -> V_30 ) ) ;
F_8 ( & ( V_6 -> V_30 ) , & ( V_8 -> V_23 . V_31 ) ) ;
V_6 ++ ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
exit:
V_32 ;
return V_10 ;
}
static void F_11 ( struct V_7 * V_8 )
{
F_12 ( & V_8 -> V_22 ) ;
F_12 ( & ( V_8 -> V_23 . V_22 ) ) ;
F_12 ( & ( V_8 -> V_24 . V_22 ) ) ;
}
static void F_13 ( T_1 * * V_33 , T_2 * V_34 )
{
F_14 ( * V_33 ) ;
* V_34 = 0 ;
* V_33 = NULL ;
}
void F_15 ( struct V_7 * V_8 )
{
F_16 ( & V_8 -> V_35 , & V_8 -> V_36 ) ;
F_16 ( & V_8 -> V_37 , & V_8 -> V_38 ) ;
F_13 ( & V_8 -> V_39 , & V_8 -> V_40 ) ;
F_13 ( & V_8 -> V_41 , & V_8 -> V_42 ) ;
F_13 ( & V_8 -> V_43 , & V_8 -> V_44 ) ;
F_13 ( & V_8 -> V_45 , & V_8 -> V_46 ) ;
F_13 ( & V_8 -> V_47 , & V_8 -> V_48 ) ;
F_13 ( & V_8 -> V_49 , & V_8 -> V_50 ) ;
F_13 ( & V_8 -> V_51 , & V_8 -> V_52 ) ;
F_13 ( & V_8 -> V_53 , & V_8 -> V_54 ) ;
F_13 ( & V_8 -> V_55 , & V_8 -> V_56 ) ;
}
void F_15 ( struct V_7 * V_8 )
{
}
void F_17 ( struct V_7 * V_8 )
{
V_12 ;
F_15 ( V_8 ) ;
if ( V_8 ) {
F_11 ( V_8 ) ;
if ( V_8 -> V_29 ) {
F_18 ( V_8 -> V_29 , V_27 * sizeof( struct V_5 ) ) ;
}
}
V_32 ;
}
int F_19 ( struct V_57 * V_31 , struct V_5 * V_6 )
{
unsigned long V_58 ;
V_12 ;
if ( V_6 == NULL )
goto exit;
F_20 ( & V_31 -> V_22 , & V_58 ) ;
F_8 ( & V_6 -> V_30 , & V_31 -> V_31 ) ;
F_21 ( & V_31 -> V_22 , & V_58 ) ;
exit:
V_32 ;
return V_11 ;
}
struct V_5 * F_22 ( struct V_57 * V_31 )
{
unsigned long V_58 ;
struct V_5 * V_6 ;
V_12 ;
F_20 ( & V_31 -> V_22 , & V_58 ) ;
if ( F_23 ( V_31 ) ) {
V_6 = NULL ;
} else {
V_6 = F_24 ( F_25 ( & V_31 -> V_31 ) , struct V_5 , V_30 ) ;
F_26 ( & ( V_6 -> V_30 ) ) ;
}
F_21 ( & V_31 -> V_22 , & V_58 ) ;
V_32 ;
return V_6 ;
}
struct V_5 * F_27 ( struct V_7 * V_8 )
{
unsigned long V_58 ;
struct V_5 * V_6 ;
struct V_57 * V_59 = & V_8 -> V_23 ;
struct V_60 * V_61 = NULL ;
V_12 ;
F_20 ( & V_59 -> V_22 , & V_58 ) ;
if ( F_23 ( V_59 ) == true ) {
V_6 = NULL ;
goto exit;
}
V_61 = F_25 ( & ( V_59 -> V_31 ) ) ;
V_6 = F_24 ( V_61 , struct V_5 , V_30 ) ;
F_26 ( & V_6 -> V_30 ) ;
F_28 ( V_62 , V_63 , ( L_1 , V_61 ) ) ;
V_6 -> V_64 = 0 ;
V_6 -> V_65 = false ;
V_6 -> V_66 = F_29 () ;
V_6 -> V_67 = 0 ;
V_6 -> V_68 = 0 ;
V_8 -> V_69 ++ ;
exit:
F_21 ( & V_59 -> V_22 , & V_58 ) ;
V_32 ;
return V_6 ;
}
void F_30 ( struct V_7 * V_8 , struct V_5 * V_6 , T_1 V_70 )
{
T_2 V_71 , V_72 ;
T_2 V_73 = V_74 ;
unsigned long V_58 ;
struct V_57 * V_59 = & ( V_8 -> V_23 ) ;
V_12 ;
if ( V_6 == NULL )
goto exit;
if ( V_6 -> V_65 )
goto exit;
V_71 = F_29 () ;
if ( ( F_31 ( V_8 , V_75 ) ) ||
( F_31 ( V_8 , V_76 ) ) )
V_73 = 1 ;
if ( ! V_70 ) {
V_72 = ( V_71 - V_6 -> V_66 ) / V_77 ;
if ( V_72 < V_73 )
goto exit;
}
F_20 ( & V_59 -> V_22 , & V_58 ) ;
F_26 ( & ( V_6 -> V_30 ) ) ;
F_8 ( & ( V_6 -> V_30 ) , & ( V_59 -> V_31 ) ) ;
V_8 -> V_69 -- ;
F_21 ( & V_59 -> V_22 , & V_58 ) ;
exit:
V_32 ;
}
void F_32 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_57 * V_59 = & ( V_8 -> V_23 ) ;
V_12 ;
if ( V_6 == NULL )
goto exit;
if ( V_6 -> V_65 )
goto exit;
F_26 ( & ( V_6 -> V_30 ) ) ;
F_8 ( & ( V_6 -> V_30 ) , F_33 ( V_59 ) ) ;
V_8 -> V_69 -- ;
exit:
V_32 ;
}
struct V_5 * F_34 ( struct V_57 * V_24 , T_1 * V_78 )
{
struct V_60 * V_79 , * V_61 ;
struct V_5 * V_6 = NULL ;
T_1 V_80 [ V_81 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
V_12 ;
if ( F_35 ( V_80 , V_78 , V_81 ) ) {
V_6 = NULL ;
goto exit;
}
V_79 = F_33 ( V_24 ) ;
V_61 = F_25 ( V_79 ) ;
while ( V_61 != V_79 ) {
V_6 = F_24 ( V_61 , struct V_5 , V_30 ) ;
if ( F_35 ( V_78 , V_6 -> V_17 . V_82 , V_81 ) == true )
break;
V_61 = F_25 ( V_61 ) ;
}
if ( V_61 == V_79 )
V_6 = NULL ;
exit:
V_32 ;
return V_6 ;
}
void F_36 ( struct V_1 * V_2 , T_1 V_70 )
{
unsigned long V_58 ;
struct V_60 * V_79 , * V_61 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_57 * V_24 = & V_8 -> V_24 ;
V_12 ;
F_20 ( & V_24 -> V_22 , & V_58 ) ;
V_79 = F_33 ( V_24 ) ;
V_61 = F_25 ( V_79 ) ;
while ( F_37 ( V_79 , V_61 ) == false ) {
V_6 = F_24 ( V_61 , struct V_5 , V_30 ) ;
V_61 = F_25 ( V_61 ) ;
F_30 ( V_8 , V_6 , V_70 ) ;
}
F_21 ( & V_24 -> V_22 , & V_58 ) ;
V_32 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_10 ;
V_12 ;
if ( V_2 -> V_83 || V_2 -> V_84 ||
( F_31 ( & V_2 -> V_9 , V_85 ) == false ) ) {
F_28 ( V_62 , V_63 ,
( L_2 ,
V_2 -> V_83 , V_2 -> V_84 ) ) ;
V_10 = false ;
} else {
V_10 = true ;
}
V_32 ;
return V_10 ;
}
void F_39 ( T_1 * V_86 )
{
T_2 V_87 = F_29 () ;
V_12 ;
V_86 [ 0 ] = 0x02 ;
V_86 [ 1 ] = 0x11 ;
V_86 [ 2 ] = 0x87 ;
V_86 [ 3 ] = ( T_1 ) ( V_87 & 0xff ) ;
V_86 [ 4 ] = ( T_1 ) ( ( V_87 >> 8 ) & 0xff ) ;
V_86 [ 5 ] = ( T_1 ) ( ( V_87 >> 16 ) & 0xff ) ;
V_32 ;
return;
}
T_1 * F_40 ( T_1 * V_88 )
{
return V_88 + 8 + 2 ;
}
T_3 F_41 ( struct V_89 * V_90 )
{
T_4 V_91 ;
V_12 ;
memcpy ( ( T_1 * ) & V_91 , F_40 ( V_90 -> V_92 ) , 2 ) ;
V_32 ;
return F_42 ( V_91 ) ;
}
T_1 * F_43 ( T_1 * V_88 )
{
return V_88 + 0 ;
}
T_1 * F_44 ( T_1 * V_88 )
{
return V_88 + 8 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_10 ;
V_12 ;
V_10 = F_1 ( V_2 ) ;
V_32 ;
return V_10 ;
}
void F_46 ( struct V_7 * V_8 )
{
V_12 ;
F_28 ( V_62 , V_93 , ( L_3 ) ) ;
F_17 ( V_8 ) ;
V_32 ;
}
static struct V_5 * F_47 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
V_12 ;
V_6 = F_27 ( V_8 ) ;
V_32 ;
return V_6 ;
}
static void F_48 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
V_12 ;
F_32 ( V_8 , V_6 ) ;
V_32 ;
}
void F_49 ( struct V_1 * V_94 , T_1 V_70 )
{
V_12 ;
F_36 ( V_94 , V_70 ) ;
V_32 ;
}
struct V_5 * F_50 ( struct V_57 * V_24 , T_1 * V_78 )
{
struct V_5 * V_6 = F_34 ( V_24 , V_78 ) ;
return V_6 ;
}
int F_51 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
int V_95 = true ;
struct V_96 * V_97 = & V_1 -> V_98 ;
if ( ( V_97 -> V_99 != V_100 ) &&
( V_6 -> V_17 . V_101 == 0 ) )
V_95 = false ;
else if ( ( V_97 -> V_99 == V_100 ) &&
( V_6 -> V_17 . V_101 == 1 ) )
V_95 = false ;
else
V_95 = true ;
return V_95 ;
}
static int F_52 ( struct V_89 * V_102 , struct V_89 * V_103 )
{
return ( V_102 -> V_104 . V_105 == V_103 -> V_104 . V_105 ) &&
F_35 ( V_102 -> V_104 . V_104 , V_103 -> V_104 . V_104 , V_102 -> V_104 . V_105 ) ;
}
int F_53 ( struct V_89 * V_106 , struct V_89 * V_107 )
{
T_3 V_108 , V_109 ;
T_4 V_110 , V_111 ;
V_12 ;
memcpy ( ( T_1 * ) & V_110 , F_40 ( V_106 -> V_92 ) , 2 ) ;
memcpy ( ( T_1 * ) & V_111 , F_40 ( V_107 -> V_92 ) , 2 ) ;
V_108 = F_42 ( V_110 ) ;
V_109 = F_42 ( V_111 ) ;
V_32 ;
return ( ( V_106 -> V_104 . V_105 == V_107 -> V_104 . V_105 ) &&
( ( F_35 ( V_106 -> V_82 , V_107 -> V_82 , V_81 ) ) == true ) &&
( ( F_35 ( V_106 -> V_104 . V_104 , V_107 -> V_104 . V_104 , V_106 -> V_104 . V_105 ) ) == true ) &&
( ( V_108 & V_112 ) ==
( V_109 & V_112 ) ) &&
( ( V_108 & V_113 ) ==
( V_109 & V_113 ) ) ) ;
}
struct V_5 * F_54 ( struct V_57 * V_24 )
{
struct V_60 * V_61 , * V_79 ;
struct V_5 * V_114 = NULL ;
struct V_5 * V_115 = NULL ;
V_12 ;
V_79 = F_33 ( V_24 ) ;
V_61 = F_25 ( V_79 ) ;
while ( 1 ) {
if ( F_37 ( V_79 , V_61 ) == true )
break;
V_114 = F_24 ( V_61 , struct V_5 , V_30 ) ;
if ( ! V_114 -> V_65 ) {
if ( V_115 == NULL || F_55 ( V_115 -> V_66 , V_114 -> V_66 ) )
V_115 = V_114 ;
}
V_61 = F_25 ( V_61 ) ;
}
V_32 ;
return V_115 ;
}
void F_56 ( struct V_89 * V_107 , struct V_89 * V_106 ,
struct V_1 * V_2 , bool V_116 )
{
long V_117 = V_107 -> V_118 ;
T_1 V_119 = V_106 -> V_120 . V_121 ;
T_1 V_122 ;
T_1 V_123 ;
long V_124 ;
V_12 ;
F_57 ( V_2 , V_107 , V_106 ) ;
if ( F_31 ( & V_2 -> V_9 , V_85 ) && F_53 ( & ( V_2 -> V_9 . V_16 . V_17 ) , V_106 ) ) {
V_122 = V_2 -> V_125 . V_126 ;
V_123 = V_2 -> V_125 . V_127 ;
if ( V_119 != 101 )
V_124 = ( V_106 -> V_118 + V_107 -> V_118 * 4 ) / 5 ;
else
V_124 = V_117 ;
} else {
if ( V_119 != 101 ) {
V_122 = ( ( T_2 ) ( V_106 -> V_120 . V_128 ) + ( T_2 ) ( V_107 -> V_120 . V_128 ) * 4 ) / 5 ;
V_123 = ( ( T_2 ) ( V_106 -> V_120 . V_121 ) + ( T_2 ) ( V_107 -> V_120 . V_121 ) * 4 ) / 5 ;
V_124 = ( V_106 -> V_118 + V_107 -> V_118 * 4 ) / 5 ;
} else {
V_122 = V_107 -> V_120 . V_128 ;
V_123 = V_107 -> V_120 . V_121 ;
V_124 = V_107 -> V_118 ;
}
}
if ( V_116 )
memcpy ( ( T_1 * ) V_107 , ( T_1 * ) V_106 , F_58 ( V_106 ) ) ;
V_107 -> V_120 . V_128 = V_122 ;
V_107 -> V_120 . V_121 = V_123 ;
V_107 -> V_118 = V_124 ;
V_32 ;
}
static void F_59 ( struct V_1 * V_1 , struct V_89 * V_6 )
{
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
V_12 ;
if ( ( F_31 ( V_8 , V_85 ) == true ) &&
( F_53 ( & ( V_8 -> V_16 . V_17 ) , V_6 ) ) ) {
F_56 ( & ( V_8 -> V_16 . V_17 ) , V_6 , V_1 , true ) ;
F_60 ( V_1 , ( V_8 -> V_16 . V_17 . V_92 ) + sizeof( struct V_129 ) ,
V_8 -> V_16 . V_17 . V_130 ) ;
}
V_32 ;
}
void F_61 ( struct V_1 * V_1 , struct V_89 * V_131 )
{
unsigned long V_58 ;
struct V_60 * V_61 , * V_79 ;
T_2 V_132 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_57 * V_31 = & ( V_8 -> V_24 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_115 = NULL ;
V_12 ;
F_20 ( & V_31 -> V_22 , & V_58 ) ;
V_79 = F_33 ( V_31 ) ;
V_61 = F_25 ( V_79 ) ;
while ( 1 ) {
if ( F_37 ( V_79 , V_61 ) == true )
break;
V_6 = F_24 ( V_61 , struct V_5 , V_30 ) ;
if ( F_53 ( & ( V_6 -> V_17 ) , V_131 ) )
break;
if ( ( V_115 == ( (struct V_5 * ) 0 ) ) ||
F_55 ( V_115 -> V_66 , V_6 -> V_66 ) )
V_115 = V_6 ;
V_61 = F_25 ( V_61 ) ;
}
if ( F_37 ( V_79 , V_61 ) == true ) {
if ( F_23 ( & ( V_8 -> V_23 ) ) == true ) {
V_6 = V_115 ;
F_62 ( V_1 , V_133 , & ( V_131 -> V_120 . V_134 ) ) ;
memcpy ( & ( V_6 -> V_17 ) , V_131 , F_58 ( V_131 ) ) ;
V_6 -> V_65 = false ;
V_6 -> V_66 = F_29 () ;
V_6 -> V_64 = 0 ;
V_6 -> V_67 = 0 ;
V_6 -> V_68 = 0 ;
if ( V_6 -> V_17 . V_120 . V_121 == 101 )
V_6 -> V_17 . V_120 . V_121 = 0 ;
} else {
V_6 = F_47 ( V_8 ) ;
if ( V_6 == NULL ) {
F_28 ( V_62 , V_93 , ( L_4 ) ) ;
goto exit;
}
V_132 = F_58 ( V_131 ) ;
V_131 -> V_135 = V_132 ;
F_62 ( V_1 , V_133 , & ( V_131 -> V_120 . V_134 ) ) ;
memcpy ( & ( V_6 -> V_17 ) , V_131 , V_132 ) ;
V_6 -> V_66 = F_29 () ;
if ( V_6 -> V_17 . V_120 . V_121 == 101 )
V_6 -> V_17 . V_120 . V_121 = 0 ;
F_8 ( & ( V_6 -> V_30 ) , & ( V_31 -> V_31 ) ) ;
}
} else {
bool V_116 = true ;
V_6 -> V_66 = F_29 () ;
if ( ( V_6 -> V_17 . V_130 > V_131 -> V_130 ) && ( V_131 -> V_136 [ 0 ] == 1 ) )
V_116 = false ;
F_56 ( & ( V_6 -> V_17 ) , V_131 , V_1 , V_116 ) ;
}
exit:
F_21 ( & V_31 -> V_22 , & V_58 ) ;
V_32 ;
}
static void F_63 ( struct V_1 * V_1 ,
struct V_89 * V_6 )
{
V_12 ;
#if F_64 ( V_137 )
F_65 ( V_6 , V_138 ) ;
#endif
F_59 ( V_1 , V_6 ) ;
F_61 ( V_1 , V_6 ) ;
V_32 ;
}
static int F_66 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_96 * V_97 = & V_1 -> V_98 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
T_2 V_139 ;
T_2 V_140 ;
T_5 V_141 ;
int V_142 = true ;
V_139 = V_97 -> V_143 ;
V_140 = V_6 -> V_17 . V_101 ;
if ( F_31 ( V_8 , V_144 ) ) {
if ( F_67 ( V_6 -> V_17 . V_92 + V_145 , V_6 -> V_17 . V_130 - V_145 , NULL , & V_141 ) != NULL )
return true ;
else
return false ;
}
if ( V_1 -> V_146 . V_147 == 1 ) {
if ( ( V_139 == V_148 ) && ( V_140 != 0 ) )
V_142 = false ;
}
if ( ( V_139 != V_148 ) && ( V_140 == 0 ) ) {
F_68 ( L_5 , V_139 , V_140 ) ;
V_142 = false ;
}
if ( F_31 ( V_8 , V_76 ) == true ) {
if ( V_6 -> V_17 . V_18 != V_8 -> V_16 . V_17 . V_18 )
V_142 = false ;
}
return V_142 ;
}
void F_69 ( struct V_1 * V_1 , T_1 * V_4 )
{
V_12 ;
F_28 ( V_62 , V_93 , ( L_6 ) ) ;
V_32 ;
return;
}
void F_70 ( struct V_1 * V_1 , T_1 * V_4 )
{
unsigned long V_58 ;
T_2 V_149 ;
struct V_89 * V_6 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
V_12 ;
V_6 = (struct V_89 * ) V_4 ;
F_28 ( V_62 , V_63 , ( L_7 , V_6 -> V_104 . V_104 ) ) ;
V_149 = F_58 ( V_6 ) ;
if ( V_149 > ( sizeof( struct V_89 ) ) ) {
F_28 ( V_62 , V_93 , ( L_8 ) ) ;
return;
}
F_20 ( & V_8 -> V_22 , & V_58 ) ;
if ( ( F_31 ( V_8 , V_75 ) ) == true ) {
if ( F_35 ( & ( V_8 -> V_16 . V_17 . V_82 ) , V_6 -> V_82 , V_81 ) ) {
struct V_5 * V_150 = NULL ;
unsigned long V_58 ;
memcpy ( V_8 -> V_16 . V_17 . V_92 , V_6 -> V_92 , 8 ) ;
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_150 = F_50 ( & V_8 -> V_24 , V_6 -> V_82 ) ;
if ( V_150 ) {
memcpy ( V_150 -> V_17 . V_92 , V_6 -> V_92 , 8 ) ;
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
goto exit;
}
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
}
}
if ( ( F_31 ( V_8 , V_151 ) ) == false ) {
if ( V_6 -> V_104 . V_104 [ 0 ] == 0 )
V_6 -> V_104 . V_105 = 0 ;
F_63 ( V_1 , V_6 ) ;
}
exit:
F_21 ( & V_8 -> V_22 , & V_58 ) ;
V_32 ;
return;
}
void F_71 ( struct V_1 * V_1 , T_1 * V_4 )
{
unsigned long V_58 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_152 * V_153 ;
V_12 ;
F_20 ( & V_8 -> V_22 , & V_58 ) ;
if ( V_8 -> V_41 ) {
V_8 -> V_42 = 0 ;
F_14 ( V_8 -> V_41 ) ;
V_8 -> V_41 = NULL ;
}
F_28 ( V_62 , V_63 , ( L_9 , F_72 ( V_8 ) ) ) ;
if ( F_31 ( V_8 , V_154 ) ) {
T_1 V_155 ;
F_73 ( & V_8 -> V_156 , & V_155 ) ;
F_74 ( V_8 , V_154 ) ;
} else {
F_28 ( V_62 , V_93 , ( L_10 , F_72 ( V_8 ) ) ) ;
}
F_75 ( & V_1 -> V_125 ) ;
if ( V_8 -> V_157 ) {
if ( ( F_31 ( V_8 , V_76 ) == true ) ) {
if ( F_31 ( V_8 , V_85 ) == false ) {
F_76 ( V_8 , V_151 ) ;
if ( F_77 ( V_8 ) == V_11 ) {
F_78 ( & V_8 -> V_158 , V_159 ) ;
} else {
struct V_89 * V_160 = & ( V_1 -> V_146 . V_161 ) ;
T_1 * V_86 = V_1 -> V_146 . V_161 . V_82 ;
F_74 ( V_8 , V_154 ) ;
F_28 ( V_62 , V_93 , ( L_11 ) ) ;
F_5 ( & V_160 -> V_104 , 0 , sizeof( struct V_26 ) ) ;
memcpy ( & V_160 -> V_104 , & V_8 -> V_25 , sizeof( struct V_26 ) ) ;
F_79 ( V_1 ) ;
F_39 ( V_86 ) ;
V_8 -> V_15 = V_75 ;
if ( F_80 ( V_1 ) != V_11 )
F_28 ( V_62 , V_93 , ( L_12 ) ) ;
V_8 -> V_157 = false ;
}
}
} else {
int V_162 ;
F_76 ( V_8 , V_151 ) ;
V_8 -> V_157 = false ;
V_162 = F_77 ( V_8 ) ;
if ( V_11 == V_162 ) {
F_78 ( & V_8 -> V_158 , V_159 ) ;
} else if ( V_162 == 2 ) {
F_74 ( V_8 , V_151 ) ;
F_81 ( V_1 ) ;
} else {
F_68 ( L_13 , V_8 -> V_163 ) ;
if ( V_8 -> V_163 != 0 ) {
if ( -- V_8 -> V_163 == 0 ||
V_11 != F_82 ( V_1 , & V_8 -> V_25 , 1 , NULL , 0 ) ) {
V_8 -> V_163 = 0 ;
F_83 ( V_1 , 1 ) ;
F_84 ( V_1 ) ;
} else {
V_8 -> V_157 = true ;
}
}
F_74 ( V_8 , V_151 ) ;
}
}
}
F_85 ( V_1 ) ;
F_21 ( & V_8 -> V_22 , & V_58 ) ;
if ( F_31 ( V_8 , V_85 ) == true )
F_86 ( V_1 , V_164 , 0 ) ;
F_87 ( V_1 ) ;
V_153 = & V_1 -> V_165 ;
if ( V_153 -> V_166 . V_167 == 0 )
F_88 ( V_1 ) ;
V_32 ;
}
void F_89 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
void F_90 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
static void F_91 ( struct V_7 * V_8 )
{
unsigned long V_58 , V_168 ;
struct V_57 * V_59 = & V_8 -> V_23 ;
struct V_57 * V_169 = & V_8 -> V_24 ;
struct V_60 * V_61 , * V_79 , * V_170 ;
V_12 ;
F_28 ( V_62 , V_171 , ( L_14 ) ) ;
F_20 ( & V_169 -> V_22 , & V_168 ) ;
F_20 ( & V_59 -> V_22 , & V_58 ) ;
V_79 = F_33 ( V_169 ) ;
V_61 = F_25 ( V_79 ) ;
while ( V_61 != V_79 ) {
V_170 = F_25 ( V_61 ) ;
F_26 ( V_61 ) ;
F_8 ( V_61 , & V_59 -> V_31 ) ;
V_61 = V_170 ;
V_8 -> V_69 -- ;
}
F_21 ( & V_59 -> V_22 , & V_58 ) ;
F_21 ( & V_169 -> V_22 , & V_168 ) ;
V_32 ;
}
void F_83 ( struct V_1 * V_1 , int V_172 )
{
unsigned long V_58 ;
struct V_5 * V_114 = NULL ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_173 * V_174 = & V_1 -> V_175 ;
struct V_5 * V_176 = & V_8 -> V_16 ;
V_12 ;
F_28 ( V_62 , V_171 , ( L_15 ) ) ;
F_28 ( V_62 , V_63 ,
( L_16 ,
V_176 -> V_17 . V_82 , V_176 -> V_17 . V_104 . V_104 ) ) ;
if ( F_31 ( V_8 , V_177 | V_178 ) ) {
struct V_179 * V_180 ;
V_180 = F_92 ( & V_1 -> V_175 , V_176 -> V_17 . V_82 ) ;
F_20 ( & ( V_174 -> V_181 ) , & V_58 ) ;
F_93 ( V_1 , V_180 ) ;
F_21 ( & ( V_174 -> V_181 ) , & V_58 ) ;
}
if ( F_31 ( V_8 , V_76 | V_75 | V_178 ) ) {
struct V_179 * V_180 ;
F_94 ( V_1 ) ;
V_180 = F_95 ( V_1 ) ;
F_20 ( & ( V_174 -> V_181 ) , & V_58 ) ;
F_93 ( V_1 , V_180 ) ;
F_21 ( & ( V_174 -> V_181 ) , & V_58 ) ;
F_96 ( V_1 ) ;
}
if ( V_172 )
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_114 = F_50 ( & V_8 -> V_24 , V_176 -> V_17 . V_82 ) ;
if ( V_114 )
V_114 -> V_65 = false ;
else
F_28 ( V_62 , V_93 , ( L_17 ) ) ;
if ( ( F_31 ( V_8 , V_75 ) && ( V_1 -> V_175 . V_182 == 1 ) ) )
F_48 ( V_8 , V_114 ) ;
if ( V_172 )
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_8 -> V_183 = 0 ;
V_32 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_12 ;
F_28 ( V_62 , V_93 , ( L_18 ) ) ;
V_8 -> V_157 = false ;
if ( ! F_31 ( & V_2 -> V_9 , V_85 ) ) {
F_76 ( V_8 , V_85 ) ;
F_97 ( V_2 , V_184 ) ;
F_98 ( V_2 ) ;
}
V_8 -> V_163 = 0 ;
F_99 ( V_2 , 3000 ) ;
F_28 ( V_62 , V_93 , ( L_19 , F_72 ( V_8 ) ) ) ;
V_32 ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_12 ;
F_28 ( V_62 , V_93 , ( L_20 ) ) ;
F_74 ( V_8 , V_151 | V_144 ) ;
if ( V_8 -> V_163 > 0 )
F_74 ( V_8 , V_85 ) ;
if ( F_31 ( & V_2 -> V_9 , V_85 ) ||
( V_8 -> V_163 <= 0 ) ) {
F_100 ( V_2 ) ;
F_74 ( V_8 , V_85 ) ;
F_97 ( V_2 , V_185 ) ;
F_9 ( V_2 ) ;
}
F_86 ( V_2 , V_186 , 1 ) ;
F_101 ( V_2 , V_187 , 1 ) ;
V_32 ;
}
inline void F_102 ( struct V_1 * V_2 , bool V_188 )
{
F_103 ( V_2 , V_188 ) ;
}
void F_104 ( struct V_1 * V_1 )
{
T_2 V_189 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_152 * V_153 = & ( V_1 -> V_165 ) ;
V_189 = F_29 () ;
V_153 -> V_190 = true ;
while ( F_31 ( V_8 , V_154 ) &&
F_105 ( V_189 ) <= 200 ) {
if ( V_1 -> V_83 || V_1 -> V_84 )
break;
F_68 ( V_191 L_21 , F_106 ( V_1 -> V_192 ) ) ;
F_107 ( 20 ) ;
}
if ( F_31 ( V_8 , V_154 ) ) {
if ( ! V_1 -> V_83 && ! V_1 -> V_84 )
F_68 ( V_191 L_22 , F_106 ( V_1 -> V_192 ) ) ;
F_102 ( V_1 , true ) ;
}
V_153 -> V_190 = false ;
}
static struct V_179 * F_108 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_3 ;
struct V_179 * V_193 , * V_180 = NULL ;
struct V_194 * V_195 ;
struct V_173 * V_174 = & V_2 -> V_175 ;
V_180 = F_92 ( V_174 , V_6 -> V_17 . V_82 ) ;
if ( V_180 == NULL )
V_180 = F_109 ( V_174 , V_6 -> V_17 . V_82 ) ;
if ( V_180 ) {
F_68 ( L_23 , V_196 ) ;
V_180 -> V_67 = V_6 -> V_68 ;
V_180 -> V_197 = 0 ;
F_110 ( V_2 , V_198 , V_180 , true ) ;
if ( V_2 -> V_98 . V_199 == V_200 ) {
V_2 -> V_98 . V_201 = false ;
V_2 -> V_98 . V_202 = false ;
V_2 -> V_98 . V_203 = false ;
V_180 -> V_204 = true ;
V_180 -> V_205 = V_2 -> V_98 . V_99 ;
F_5 ( ( T_1 * ) & V_180 -> V_206 , 0 , sizeof( union V_207 ) ) ;
F_5 ( ( T_1 * ) & V_180 -> V_208 , 0 , sizeof( union V_207 ) ) ;
F_5 ( ( T_1 * ) & V_180 -> V_209 , 0 , sizeof( union V_207 ) ) ;
F_5 ( ( T_1 * ) & V_180 -> V_210 , 0 , sizeof( union V_211 ) ) ;
F_5 ( ( T_1 * ) & V_180 -> V_212 , 0 , sizeof( union V_211 ) ) ;
}
if ( V_2 -> V_98 . V_213 != 0 ) {
V_180 -> V_204 = true ;
V_2 -> V_98 . V_213 = 0 ;
}
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_195 = & V_180 -> V_214 [ V_3 ] ;
V_195 -> V_215 = false ;
V_195 -> V_216 = 0xffff ;
V_195 -> V_217 = 0xffff ;
V_195 -> V_218 = 64 ;
}
V_193 = F_95 ( V_2 ) ;
if ( V_193 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_195 = & V_193 -> V_214 [ V_3 ] ;
V_195 -> V_215 = false ;
V_195 -> V_216 = 0xffff ;
V_195 -> V_217 = 0xffff ;
V_195 -> V_218 = 64 ;
}
}
F_111 ( V_2 , V_180 ) ;
}
return V_180 ;
}
static void F_112 ( struct V_1 * V_2 , struct V_5 * V_219 , struct V_5 * V_6 )
{
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_5 * V_16 = & ( V_8 -> V_16 ) ;
F_68 ( L_23 , V_196 ) ;
F_28 ( V_62 , V_63 ,
( L_24 ,
F_72 ( V_8 ) , V_6 -> V_17 . V_82 ) ) ;
memcpy ( & V_16 -> V_17 , & V_6 -> V_17 , V_6 -> V_17 . V_135 ) ;
V_16 -> V_17 . V_130 = V_219 -> V_17 . V_130 ;
memcpy ( & V_16 -> V_17 . V_92 [ 0 ] , & V_219 -> V_17 . V_92 [ 0 ] , V_220 ) ;
V_16 -> V_67 = V_6 -> V_68 ;
F_75 ( & V_2 -> V_125 ) ;
V_2 -> V_125 . V_126 = V_219 -> V_17 . V_120 . V_128 ;
V_2 -> V_125 . V_127 = V_219 -> V_17 . V_120 . V_121 ;
V_2 -> V_125 . V_221 = F_113 ( V_219 -> V_17 . V_120 . V_128 ) ;
F_75 ( & V_2 -> V_125 ) ;
switch ( V_6 -> V_17 . V_18 ) {
case V_222 :
if ( V_8 -> V_15 & V_144 )
V_8 -> V_15 = V_177 | V_144 ;
else
V_8 -> V_15 = V_177 ;
break;
case V_223 :
V_8 -> V_15 = V_76 ;
break;
default:
V_8 -> V_15 = V_224 ;
F_28 ( V_62 , V_93 , ( L_25 ) ) ;
break;
}
F_60 ( V_2 , ( V_16 -> V_17 . V_92 ) +
sizeof( struct V_129 ) ,
( V_16 -> V_17 . V_130 ) ) ;
F_114 ( V_2 , V_16 -> V_17 . V_92 , V_16 -> V_17 . V_130 ) ;
}
void F_115 ( struct V_1 * V_1 , T_1 * V_4 )
{
unsigned long V_58 , V_225 ;
T_1 V_155 ;
struct V_179 * V_226 = NULL , * V_227 = NULL ;
struct V_173 * V_174 = & V_1 -> V_175 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
struct V_5 * V_16 = & ( V_8 -> V_16 ) ;
struct V_5 * V_228 = NULL , * V_219 = NULL ;
unsigned int V_229 = false ;
V_12 ;
F_28 ( V_62 , V_63 , ( L_26 , V_6 -> V_68 ) ) ;
F_116 ( V_1 ) ;
if ( V_8 -> V_25 . V_105 == 0 )
F_28 ( V_62 , V_93 , ( L_27 ) ) ;
else
F_28 ( V_62 , V_93 , ( L_28 , V_8 -> V_25 . V_104 ) ) ;
V_229 = F_35 ( V_6 -> V_17 . V_82 , V_16 -> V_17 . V_82 , V_81 ) ;
V_6 -> V_17 . V_135 = F_58 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_17 . V_135 > sizeof( struct V_89 ) ) {
F_28 ( V_62 , V_93 , ( L_29 ) ) ;
goto V_230;
}
F_20 ( & V_8 -> V_22 , & V_58 ) ;
F_28 ( V_62 , V_63 , ( L_30 ) ) ;
if ( V_6 -> V_68 > 0 ) {
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
if ( F_31 ( V_8 , V_151 ) ) {
if ( F_31 ( V_8 , V_85 ) ) {
if ( V_229 ) {
V_219 = F_50 ( & V_8 -> V_24 , V_16 -> V_17 . V_82 ) ;
} else {
V_228 = F_50 ( & V_8 -> V_24 , V_16 -> V_17 . V_82 ) ;
if ( V_228 )
V_228 -> V_65 = false ;
V_227 = F_92 ( V_174 , V_16 -> V_17 . V_82 ) ;
if ( V_227 ) {
F_20 ( & ( V_174 -> V_181 ) , & V_225 ) ;
F_93 ( V_1 , V_227 ) ;
F_21 ( & ( V_174 -> V_181 ) , & V_225 ) ;
}
V_219 = F_50 ( & V_8 -> V_24 , V_6 -> V_17 . V_82 ) ;
if ( F_31 ( V_8 , V_177 ) == true ) {
if ( V_219 )
V_219 -> V_65 = true ;
}
}
} else {
V_219 = F_50 ( & V_8 -> V_24 , V_6 -> V_17 . V_82 ) ;
if ( F_31 ( V_8 , V_177 ) == true ) {
if ( V_219 )
V_219 -> V_65 = true ;
}
}
if ( V_219 ) {
F_112 ( V_1 , V_219 , V_6 ) ;
} else {
F_28 ( V_62 , V_93 , ( L_31 ) ) ;
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
goto V_231;
}
if ( F_31 ( V_8 , V_177 ) == true ) {
V_226 = F_108 ( V_1 , V_6 ) ;
if ( V_226 == NULL ) {
F_28 ( V_62 , V_93 , ( L_32 ) ) ;
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
goto V_231;
}
}
if ( F_31 ( V_8 , V_177 ) == true ) {
F_81 ( V_1 ) ;
} else {
F_28 ( V_62 , V_63 , ( L_33 , F_72 ( V_8 ) ) ) ;
}
F_73 ( & V_8 -> V_158 , & V_155 ) ;
F_28 ( V_62 , V_63 , ( L_34 ) ) ;
} else {
F_28 ( V_62 , V_93 , ( L_35 , F_72 ( V_8 ) ) ) ;
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
goto V_231;
}
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
} else if ( V_6 -> V_68 == - 4 ) {
F_117 ( V_1 ) ;
F_78 ( & V_8 -> V_158 , 1 ) ;
if ( ( F_31 ( V_8 , V_151 ) ) == true ) {
F_28 ( V_62 , V_93 , ( L_36 , F_72 ( V_8 ) ) ) ;
F_74 ( V_8 , V_151 ) ;
}
} else {
F_78 ( & V_8 -> V_158 , 1 ) ;
F_74 ( V_8 , V_151 ) ;
}
V_231:
F_21 ( & V_8 -> V_22 , & V_58 ) ;
V_230:
V_32 ;
}
void F_118 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
V_12 ;
F_119 ( V_1 , V_6 -> V_68 ) ;
F_87 ( V_1 ) ;
V_32 ;
}
static T_1 F_120 ( struct V_1 * V_2 )
{
T_1 V_197 ;
#if F_64 ( V_232 )
T_1 V_67 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_173 * V_174 = & V_2 -> V_175 ;
#endif
struct V_152 * V_153 = & ( V_2 -> V_165 ) ;
struct V_233 * V_234 = & ( V_153 -> V_235 ) ;
#if F_64 ( V_232 )
if ( F_31 ( V_8 , V_178 ) ) {
for ( V_67 = ( V_174 -> V_236 ) ; V_67 > 0 ; V_67 -- ) {
if ( V_174 -> V_237 [ V_67 - 1 ] != NULL )
break;
}
V_197 = V_67 + 1 ;
} else
#endif
{
for ( V_197 = ( V_238 - 1 ) ; V_197 >= V_239 ; V_197 -- ) {
if ( V_234 -> V_240 [ V_197 ] . V_241 == 1 )
break;
}
}
return V_197 ;
}
void F_121 ( struct V_1 * V_1 , struct V_179 * V_180 )
{
T_3 V_242 ;
T_1 V_243 ;
if ( V_180 == NULL )
return;
V_243 = F_120 ( V_1 ) ;
F_122 ( V_1 , V_244 , ( T_1 * ) & V_243 ) ;
V_242 = ( V_180 -> V_197 << 8 ) | 1 ;
F_122 ( V_1 , V_245 , ( T_1 * ) & V_242 ) ;
}
void F_123 ( struct V_1 * V_1 , T_1 * V_4 )
{
unsigned long V_58 ;
struct V_179 * V_180 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_246 * V_247 = (struct V_246 * ) V_4 ;
struct V_5 * V_16 = & ( V_8 -> V_16 ) ;
struct V_5 * V_219 = NULL ;
V_12 ;
if ( F_124 ( V_1 , V_247 -> V_248 ) == false )
return;
#if F_64 ( V_232 )
if ( F_31 ( V_8 , V_178 ) ) {
V_180 = F_92 ( & V_1 -> V_175 , V_247 -> V_248 ) ;
if ( V_180 ) {
F_125 ( V_1 , V_180 ) ;
F_121 ( V_1 , V_180 ) ;
}
goto exit;
}
#endif
V_180 = F_92 ( & V_1 -> V_175 , V_247 -> V_248 ) ;
if ( V_180 != NULL ) {
F_28 ( V_62 , V_93 , ( L_37 ) ) ;
goto exit;
}
V_180 = F_109 ( & V_1 -> V_175 , V_247 -> V_248 ) ;
if ( V_180 == NULL ) {
F_28 ( V_62 , V_93 , ( L_38 ) ) ;
goto exit;
}
V_180 -> V_249 = 0 ;
V_180 -> V_197 = ( T_5 ) V_247 -> V_250 ;
F_68 ( L_23 , V_196 ) ;
F_110 ( V_1 , V_198 , V_180 , true ) ;
F_121 ( V_1 , V_180 ) ;
if ( V_1 -> V_98 . V_199 == V_200 )
V_180 -> V_205 = V_1 -> V_98 . V_99 ;
V_180 -> V_204 = false ;
F_20 ( & V_8 -> V_22 , & V_58 ) ;
if ( ( F_31 ( V_8 , V_75 ) ) ||
( F_31 ( V_8 , V_76 ) ) ) {
if ( V_1 -> V_175 . V_182 == 2 ) {
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_219 = F_50 ( & V_8 -> V_24 , V_16 -> V_17 . V_82 ) ;
if ( V_219 )
V_219 -> V_65 = true ;
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
F_81 ( V_1 ) ;
}
}
F_21 ( & V_8 -> V_22 , & V_58 ) ;
F_126 ( V_1 , V_180 ) ;
exit:
V_32 ;
}
void F_127 ( struct V_1 * V_1 , T_1 * V_4 )
{
unsigned long V_58 , V_225 ;
int V_197 = - 1 ;
struct V_179 * V_180 ;
struct V_5 * V_114 = NULL ;
struct V_89 * V_160 = NULL ;
T_1 * V_86 = NULL ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_4 ;
struct V_173 * V_174 = & V_1 -> V_175 ;
struct V_5 * V_176 = & ( V_8 -> V_16 ) ;
V_12 ;
V_180 = F_92 ( & V_1 -> V_175 , V_252 -> V_248 ) ;
if ( V_180 )
V_197 = V_180 -> V_197 ;
else
V_197 = V_252 -> V_197 ;
F_68 ( L_39 , V_196 , V_197 , V_252 -> V_248 ) ;
if ( V_197 >= 0 ) {
T_3 V_242 ;
V_242 = ( V_197 << 8 ) | 0 ;
F_122 ( V_1 , V_245 , ( T_1 * ) & V_242 ) ;
}
if ( F_31 ( V_8 , V_178 ) )
return;
F_128 ( V_1 ) ;
F_20 ( & V_8 -> V_22 , & V_225 ) ;
if ( F_31 ( V_8 , V_177 ) ) {
if ( V_8 -> V_163 > 0 )
V_8 -> V_163 -- ;
else if ( V_8 -> V_163 == 0 )
V_8 -> V_163 = V_1 -> V_146 . V_253 ;
if ( * ( ( unsigned short * ) ( V_252 -> V_254 ) ) != V_255 )
V_8 -> V_163 = 0 ;
F_129 ( V_1 ) ;
F_83 ( V_1 , 1 ) ;
F_84 ( V_1 ) ;
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_114 = F_50 ( & V_8 -> V_24 , V_176 -> V_17 . V_82 ) ;
if ( V_114 ) {
V_114 -> V_65 = false ;
F_48 ( V_8 , V_114 ) ;
}
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
F_130 ( V_1 , V_176 ) ;
}
if ( F_31 ( V_8 , V_75 ) ||
F_31 ( V_8 , V_76 ) ) {
F_20 ( & ( V_174 -> V_181 ) , & V_58 ) ;
F_93 ( V_1 , V_180 ) ;
F_21 ( & ( V_174 -> V_181 ) , & V_58 ) ;
if ( V_1 -> V_175 . V_182 == 1 ) {
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_114 = F_50 ( & V_8 -> V_24 , V_176 -> V_17 . V_82 ) ;
if ( V_114 ) {
V_114 -> V_65 = false ;
F_48 ( V_8 , V_114 ) ;
}
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_160 = & ( V_1 -> V_146 . V_161 ) ;
V_86 = V_1 -> V_146 . V_161 . V_82 ;
memcpy ( V_160 , & V_176 -> V_17 , F_58 ( & V_176 -> V_17 ) ) ;
F_5 ( & V_160 -> V_104 , 0 , sizeof( struct V_26 ) ) ;
memcpy ( & V_160 -> V_104 , & V_8 -> V_25 , sizeof( struct V_26 ) ) ;
F_79 ( V_1 ) ;
F_39 ( V_86 ) ;
if ( F_31 ( V_8 , V_76 ) ) {
F_76 ( V_8 , V_75 ) ;
F_74 ( V_8 , V_76 ) ;
}
if ( F_80 ( V_1 ) != V_11 )
F_28 ( V_256 , V_93 , ( L_40 ) ) ;
}
}
F_21 ( & V_8 -> V_22 , & V_225 ) ;
V_32 ;
}
void F_131 ( struct V_1 * V_2 , T_1 * V_4 )
{
V_12 ;
F_28 ( V_62 , V_93 , ( L_41 ) ) ;
V_32 ;
}
void F_132 ( struct V_1 * V_1 )
{
unsigned long V_58 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
int V_257 ;
V_12 ;
F_68 ( L_42 , V_196 , F_72 ( V_8 ) ) ;
if ( V_1 -> V_83 || V_1 -> V_84 )
return;
F_20 ( & V_8 -> V_22 , & V_58 ) ;
if ( V_8 -> V_163 > 0 ) {
while ( 1 ) {
V_8 -> V_163 -- ;
if ( V_8 -> V_163 != 0 ) {
F_68 ( L_43 , V_196 ) ;
V_257 = F_133 ( V_1 ) ;
if ( V_11 != V_257 ) {
F_68 ( L_44 , V_196 , V_257 ) ;
continue;
}
break;
} else {
F_68 ( L_45 , V_196 ) ;
F_84 ( V_1 ) ;
break;
}
}
} else {
F_84 ( V_1 ) ;
F_91 ( V_8 ) ;
}
F_21 ( & V_8 -> V_22 , & V_58 ) ;
V_32 ;
}
void F_134 ( struct V_1 * V_1 )
{
unsigned long V_58 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
F_68 ( V_258 L_46 , F_135 ( V_1 ) , F_72 ( V_8 ) ) ;
F_20 ( & V_8 -> V_22 , & V_58 ) ;
F_74 ( V_8 , V_154 ) ;
F_21 ( & V_8 -> V_22 , & V_58 ) ;
F_102 ( V_1 , true ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( V_8 -> V_259 > 0 ) {
V_8 -> V_259 -- ;
if ( V_8 -> V_259 == 0 ) {
F_68 ( L_23 , V_196 ) ;
F_137 ( V_2 , NULL , 0 ) ;
V_8 -> V_259 = V_260 ;
}
}
}
void F_138 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_261 * V_262 = & V_1 -> V_146 ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_263 )
return;
if ( ( V_1 -> V_83 ) || ( V_1 -> V_84 ) )
return;
if ( V_1 -> V_264 )
return;
F_139 ( V_1 ) ;
if ( V_262 -> V_147 == 1 ) {
#ifdef V_137
struct V_265 * V_266 = & V_1 -> V_267 ;
if ( F_140 ( V_266 , V_268 ) )
#endif
{
F_136 ( V_1 ) ;
}
}
F_141 () ;
if ( F_142 ( V_1 -> V_192 -> V_269 ) &&
( F_31 ( V_8 , V_177 | V_76 ) == true ) ) {
F_143 ( V_1 ) ;
if ( V_1 -> V_270 > 0 ) {
V_1 -> V_270 -- ;
}
if ( V_1 -> V_270 > 0 ) {
V_1 -> V_270 -- ;
}
}
F_144 () ;
}
static int F_145 ( struct V_7 * V_8
, struct V_5 * * V_271 , struct V_5 * V_272 )
{
int V_273 = false ;
struct V_1 * V_1 = F_146 ( V_8 , struct V_1 , V_9 ) ;
if ( V_8 -> V_274 ) {
if ( ! F_35 ( V_272 -> V_17 . V_82 , V_8 -> V_275 , V_81 ) )
goto exit;
}
if ( V_8 -> V_25 . V_104 && V_8 -> V_25 . V_105 ) {
if ( V_272 -> V_17 . V_104 . V_105 != V_8 -> V_25 . V_105 ||
F_35 ( V_272 -> V_17 . V_104 . V_104 , V_8 -> V_25 . V_104 , V_8 -> V_25 . V_105 ) == false )
goto exit;
}
if ( F_66 ( V_1 , V_272 ) == false )
goto exit;
if ( V_8 -> V_163 ) {
if ( F_105 ( ( T_2 ) V_272 -> V_66 ) >= V_276 ||
F_52 ( & V_272 -> V_17 , & V_8 -> V_16 . V_17 ) == false )
goto exit;
}
if ( * V_271 == NULL || ( * V_271 ) -> V_17 . V_118 < V_272 -> V_17 . V_118 ) {
* V_271 = V_272 ;
V_273 = true ;
}
if ( V_273 ) {
F_68 ( L_47 ,
V_8 -> V_274 ,
V_8 -> V_25 . V_104 ,
( * V_271 ) -> V_17 . V_104 . V_104 ,
( * V_271 ) -> V_17 . V_82 ,
( int ) ( * V_271 ) -> V_17 . V_118 ) ;
F_68 ( L_48 , V_8 -> V_163 ) ;
}
exit:
return V_273 ;
}
int F_77 ( struct V_7 * V_8 )
{
unsigned long V_58 ;
int V_95 ;
struct V_60 * V_79 ;
struct V_1 * V_1 ;
struct V_57 * V_31 = & ( V_8 -> V_24 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_271 = NULL ;
T_1 V_277 = false ;
V_12 ;
F_20 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_79 = F_33 ( V_31 ) ;
V_1 = (struct V_1 * ) V_8 -> V_13 ;
V_8 -> V_14 = F_25 ( V_79 ) ;
while ( ! F_37 ( V_79 , V_8 -> V_14 ) ) {
V_6 = F_24 ( V_8 -> V_14 , struct V_5 , V_30 ) ;
if ( V_6 == NULL ) {
F_28 ( V_62 , V_93 , ( L_49 , V_196 ) ) ;
V_95 = V_28 ;
goto exit;
}
V_8 -> V_14 = F_25 ( V_8 -> V_14 ) ;
F_145 ( V_8 , & V_271 , V_6 ) ;
}
if ( V_271 == NULL ) {
F_68 ( L_50 , V_196 ) ;
V_95 = V_28 ;
goto exit;
} else {
F_68 ( L_51 , V_196 ,
V_271 -> V_17 . V_104 . V_104 , V_271 -> V_17 . V_82 ,
V_271 -> V_17 . V_278 . V_279 ) ;
}
if ( F_31 ( V_8 , V_85 ) == true ) {
F_68 ( L_52 , V_196 ) ;
F_147 ( V_1 , 0 , true ) ;
F_84 ( V_1 ) ;
F_83 ( V_1 , 0 ) ;
}
F_62 ( V_1 , V_280 , & ( V_277 ) ) ;
if ( V_277 ) {
T_1 V_281 ;
F_62 ( V_1 , V_133 , & ( V_281 ) ) ;
F_68 ( L_53 ,
( 2 == V_271 -> V_17 . V_120 . V_134 ) ? L_54 : L_55 ,
( 2 == V_281 ) ? L_54 : L_55
) ;
}
V_95 = F_148 ( V_1 , V_271 ) ;
exit:
F_21 ( & ( V_8 -> V_24 . V_22 ) , & V_58 ) ;
V_32 ;
return V_95 ;
}
int F_149 ( struct V_1 * V_1 , struct V_96 * V_97 )
{
struct V_282 * V_283 ;
struct V_284 * V_285 ;
struct V_286 * V_287 = & ( V_1 -> V_288 ) ;
int V_10 = V_11 ;
V_12 ;
V_283 = (struct V_282 * ) F_150 ( sizeof( struct V_282 ) ) ;
if ( V_283 == NULL ) {
V_10 = V_28 ;
goto exit;
}
V_285 = (struct V_284 * ) F_150 ( sizeof( struct V_284 ) ) ;
if ( V_285 == NULL ) {
F_14 ( V_283 ) ;
V_10 = V_28 ;
goto exit;
}
F_5 ( V_285 , 0 , sizeof( struct V_284 ) ) ;
V_285 -> V_289 = ( unsigned char ) V_97 -> V_199 ;
V_283 -> V_290 = V_291 ;
V_283 -> V_292 = ( unsigned char * ) V_285 ;
V_283 -> V_293 = ( sizeof( struct V_284 ) ) ;
V_283 -> V_294 = NULL ;
V_283 -> V_295 = 0 ;
F_7 ( & V_283 -> V_30 ) ;
F_28 ( V_62 , V_93 ,
( L_56 ,
V_97 -> V_199 ) ) ;
V_10 = F_151 ( V_287 , V_283 ) ;
exit:
V_32 ;
return V_10 ;
}
int F_152 ( struct V_1 * V_1 , struct V_96 * V_97 , int V_296 , T_1 V_297 )
{
T_1 V_298 ;
struct V_282 * V_283 ;
struct V_299 * V_300 ;
struct V_286 * V_287 = & ( V_1 -> V_288 ) ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
int V_10 = V_11 ;
V_12 ;
V_283 = (struct V_282 * ) F_150 ( sizeof( struct V_282 ) ) ;
if ( V_283 == NULL ) {
V_10 = V_28 ;
goto exit;
}
V_300 = (struct V_299 * ) F_150 ( sizeof( struct V_299 ) ) ;
if ( V_300 == NULL ) {
F_14 ( V_283 ) ;
V_10 = V_28 ;
goto exit;
}
F_5 ( V_300 , 0 , sizeof( struct V_299 ) ) ;
if ( V_97 -> V_199 == V_200 ) {
V_300 -> V_301 = ( unsigned char ) V_97 -> V_302 ;
F_28 ( V_62 , V_93 ,
( L_57 ,
V_300 -> V_301 ) ) ;
} else {
V_300 -> V_301 = ( T_1 ) V_97 -> V_99 ;
F_28 ( V_62 , V_93 ,
( L_58 ,
V_300 -> V_301 ) ) ;
}
V_300 -> V_296 = ( T_1 ) V_296 ;
V_300 -> V_297 = V_297 ;
V_8 -> V_183 |= F_153 ( V_300 -> V_296 ) ;
F_68 ( L_59 ,
V_300 -> V_301 , V_300 -> V_296 , V_8 -> V_183 ) ;
F_28 ( V_62 , V_93 ,
( L_60 ,
V_300 -> V_301 , V_296 ) ) ;
switch ( V_300 -> V_301 ) {
case V_303 :
V_298 = 5 ;
memcpy ( & ( V_300 -> V_304 [ 0 ] ) , & ( V_97 -> V_305 [ V_296 ] . V_306 [ 0 ] ) , V_298 ) ;
break;
case V_307 :
V_298 = 13 ;
memcpy ( & ( V_300 -> V_304 [ 0 ] ) , & ( V_97 -> V_305 [ V_296 ] . V_306 [ 0 ] ) , V_298 ) ;
break;
case V_308 :
V_298 = 16 ;
memcpy ( & V_300 -> V_304 , & V_97 -> V_309 [ V_296 ] , V_298 ) ;
V_300 -> V_310 = 1 ;
break;
case V_311 :
V_298 = 16 ;
memcpy ( & V_300 -> V_304 , & V_97 -> V_309 [ V_296 ] , V_298 ) ;
V_300 -> V_310 = 1 ;
break;
default:
F_28 ( V_62 , V_93 ,
( L_61 ,
V_97 -> V_99 ) ) ;
V_10 = V_28 ;
goto exit;
}
V_283 -> V_290 = V_312 ;
V_283 -> V_292 = ( T_1 * ) V_300 ;
V_283 -> V_293 = ( sizeof( struct V_299 ) ) ;
V_283 -> V_294 = NULL ;
V_283 -> V_295 = 0 ;
F_7 ( & V_283 -> V_30 ) ;
V_10 = F_151 ( V_287 , V_283 ) ;
exit:
V_32 ;
return V_10 ;
}
int F_154 ( struct V_1 * V_1 , T_1 * V_313 , T_1 * V_314 , T_5 V_315 , T_5 V_316 )
{
unsigned int V_317 = 0 ;
unsigned int V_3 , V_318 ;
V_3 = 12 ;
while ( V_3 < V_315 ) {
V_317 = V_316 ;
if ( V_313 [ V_3 ] == 0xDD && V_313 [ V_3 + 2 ] == 0x00 && V_313 [ V_3 + 3 ] == 0x50 && V_313 [ V_3 + 4 ] == 0xF2 && V_313 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_315 ) {
for ( V_318 = V_3 ; V_318 < V_3 + 9 ; V_318 ++ ) {
V_314 [ V_317 ] = V_313 [ V_318 ] ;
V_317 ++ ;
}
V_314 [ V_316 + 1 ] = 0x07 ;
V_314 [ V_316 + 6 ] = 0x00 ;
V_314 [ V_316 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_313 [ V_3 + 1 ] + 2 ) ;
}
return V_317 ;
}
static int F_155 ( struct V_1 * V_319 , T_1 * V_320 )
{
struct V_96 * V_97 = & V_319 -> V_98 ;
int V_3 = 0 ;
do {
if ( ( V_97 -> V_321 [ V_3 ] . V_322 ) &&
( F_35 ( V_97 -> V_321 [ V_3 ] . V_323 , V_320 , V_81 ) == true ) ) {
break;
} else {
V_3 ++ ;
}
} while ( V_3 < V_324 );
if ( V_3 == V_324 ) {
V_3 = - 1 ;
} else {
}
return V_3 ;
}
static int F_156 ( struct V_1 * V_319 , int V_325 , T_1 * V_88 , T_5 V_326 )
{
struct V_96 * V_97 = & V_319 -> V_98 ;
if ( V_88 [ 13 ] <= 20 ) {
V_88 [ V_326 ] = 1 ;
V_326 ++ ;
V_88 [ V_326 ] = 0 ;
V_326 ++ ;
memcpy ( & V_88 [ V_326 ] , & V_97 -> V_321 [ V_325 ] . V_327 , 16 ) ;
V_326 += 16 ;
V_88 [ 13 ] += 18 ;
}
return V_326 ;
}
int F_157 ( struct V_1 * V_1 , T_1 * V_313 , T_1 * V_314 , T_5 V_315 )
{
T_1 V_328 ;
T_5 V_317 ;
int V_325 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_96 * V_97 = & V_1 -> V_98 ;
T_5 V_329 = V_97 -> V_330 ;
T_5 V_331 = V_97 -> V_143 ;
V_12 ;
F_28 ( V_62 , V_171 ,
( L_62 ,
V_329 , V_331 ) ) ;
memcpy ( V_314 , V_313 , 12 ) ;
V_317 = 12 ;
if ( ( V_329 == V_332 ) ||
( V_329 == V_333 ) )
V_328 = V_334 ;
if ( ( V_329 == V_335 ) ||
( V_329 == V_336 ) )
V_328 = V_337 ;
if ( F_31 ( V_8 , V_144 ) ) {
memcpy ( V_314 + V_317 , V_97 -> V_338 , V_97 -> V_213 ) ;
V_317 += V_97 -> V_213 ;
} else if ( ( V_328 == V_334 ) || ( V_328 == V_337 ) ) {
memcpy ( & V_314 [ V_317 ] , & V_97 -> V_339 [ 0 ] , V_97 -> V_339 [ 1 ] + 2 ) ;
V_317 += V_97 -> V_339 [ 1 ] + 2 ;
F_158 ( V_1 , V_328 , V_97 -> V_339 ) ;
}
V_325 = F_155 ( V_1 , V_8 -> V_275 ) ;
if ( V_325 < 0 ) {
return V_317 ;
} else {
if ( V_328 == V_337 )
V_317 = F_156 ( V_1 , V_325 , V_314 , V_317 ) ;
}
V_32 ;
return V_317 ;
}
void F_159 ( struct V_1 * V_1 )
{
struct V_261 * V_262 = & V_1 -> V_146 ;
struct V_340 * V_341 = & V_1 -> V_342 ;
struct V_89 * V_160 = & V_262 -> V_161 ;
T_1 * V_343 = F_160 ( V_341 ) ;
V_12 ;
memcpy ( V_160 -> V_82 , V_343 , V_81 ) ;
memcpy ( & V_160 -> V_104 , & V_262 -> V_344 , sizeof( struct V_26 ) ) ;
V_160 -> V_278 . V_135 = sizeof( struct V_345 ) ;
V_160 -> V_278 . V_346 = 100 ;
V_160 -> V_278 . V_347 . V_135 = 0 ;
V_160 -> V_278 . V_347 . V_348 = 0 ;
V_160 -> V_278 . V_347 . V_349 = 0 ;
V_160 -> V_278 . V_347 . V_350 = 0 ;
V_32 ;
}
void F_79 ( struct V_1 * V_1 )
{
int V_351 = 0 ;
struct V_261 * V_262 = & V_1 -> V_146 ;
struct V_89 * V_160 = & V_262 -> V_161 ;
struct V_96 * V_97 = & V_1 -> V_98 ;
struct V_5 * V_16 = & V_1 -> V_9 . V_16 ;
V_12 ;
V_160 -> V_101 = ( V_97 -> V_99 > 0 ? 1 : 0 ) ;
V_160 -> V_118 = 0 ;
switch ( V_262 -> V_352 ) {
case V_353 :
V_160 -> V_354 = ( V_355 ) ;
break;
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
V_160 -> V_354 = ( V_361 ) ;
break;
case V_362 :
case V_363 :
V_160 -> V_354 = ( V_364 ) ;
break;
case V_365 :
if ( V_262 -> V_366 > 14 )
V_160 -> V_354 = ( V_364 ) ;
else
V_160 -> V_354 = ( V_361 ) ;
break;
default:
break;
}
V_160 -> V_278 . V_279 = ( V_262 -> V_366 ) ;
F_28 ( V_62 , V_63 ,
( L_63 ,
V_262 -> V_366 , V_160 -> V_278 . V_279 ) ) ;
if ( V_16 -> V_17 . V_18 == V_223 )
V_160 -> V_278 . V_367 = ( 0 ) ;
V_160 -> V_18 = ( V_16 -> V_17 . V_18 ) ;
V_351 = F_161 ( V_262 ) ;
V_160 -> V_130 = V_351 ;
V_160 -> V_135 = F_58 ( (struct V_89 * ) V_160 ) ;
V_32 ;
}
void F_116 ( struct V_1 * V_1 )
{
V_12 ;
V_32 ;
}
void F_162 ( struct V_1 * V_2 )
{
T_1 V_368 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_369 * V_370 = & V_8 -> V_371 ;
V_8 -> V_372 = 0 ;
V_8 -> V_373 = 0 ;
V_370 -> V_374 = false ;
if ( V_370 -> V_375 ) {
if ( V_2 -> V_146 . V_147 == 1 )
V_368 = 1 ;
else
V_368 = 0 ;
F_122 ( V_2 , V_376 , ( T_1 * ) ( & V_368 ) ) ;
} else {
V_368 = 1 ;
F_122 ( V_2 , V_376 , ( T_1 * ) ( & V_368 ) ) ;
}
}
unsigned int F_163 ( struct V_1 * V_2 , T_1 * V_313 , T_1 * V_314 , T_5 V_315 , T_5 * V_377 )
{
T_2 V_378 , V_379 ;
enum V_380 V_381 ;
unsigned char * V_382 ;
struct V_383 V_384 ;
unsigned char V_385 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_386 * V_387 = & V_8 -> V_388 ;
struct V_369 * V_370 = & V_8 -> V_371 ;
T_2 V_389 , V_390 ;
V_370 -> V_375 = false ;
V_382 = F_164 ( V_313 + 12 , V_391 , & V_378 , V_315 - 12 ) ;
if ( V_382 && V_378 > 0 ) {
if ( V_387 -> V_249 == 0 ) {
V_379 = * V_377 ;
F_165 ( V_314 + V_379 , V_392 ,
V_393 , V_385 , V_377 ) ;
V_387 -> V_249 = 1 ;
}
V_379 = * V_377 ;
F_5 ( & V_384 , 0 , sizeof( struct V_383 ) ) ;
V_384 . V_394 = V_395 |
V_396 |
V_397 |
V_398 |
V_399 ;
F_62 ( V_2 , V_400 , & V_389 ) ;
F_62 ( V_2 , V_401 , & V_390 ) ;
F_62 ( V_2 , V_402 , & V_381 ) ;
V_384 . V_403 = ( V_381 & 0x03 ) ;
if ( V_2 -> V_98 . V_99 == V_311 )
V_384 . V_403 |= ( V_404 & ( 0x07 << 2 ) ) ;
else
V_384 . V_403 |= ( V_404 & 0x00 ) ;
F_165 ( V_314 + V_379 , V_391 ,
sizeof( struct V_383 ) , ( unsigned char * ) & V_384 , V_377 ) ;
V_370 -> V_375 = true ;
V_382 = F_164 ( V_313 + 12 , V_405 , & V_378 , V_315 - 12 ) ;
if ( V_382 && ( V_378 == sizeof( struct V_406 ) ) ) {
V_379 = * V_377 ;
F_165 ( V_314 + V_379 , V_405 , V_378 , V_382 + 2 , V_377 ) ;
}
}
return V_370 -> V_375 ;
}
void F_114 ( struct V_1 * V_2 , T_1 * V_407 , T_5 V_326 )
{
T_1 * V_382 , V_408 ;
int V_149 ;
struct V_383 * V_409 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_369 * V_370 = & V_8 -> V_371 ;
struct V_261 * V_262 = & V_2 -> V_146 ;
struct V_152 * V_153 = & V_2 -> V_165 ;
struct V_233 * V_234 = & ( V_153 -> V_235 ) ;
if ( ! V_370 -> V_375 )
return;
if ( ( ! V_234 -> V_410 ) || ( ! V_234 -> V_411 ) )
return;
F_68 ( L_64 ) ;
if ( ( ! V_370 -> V_374 ) && ( V_262 -> V_374 == 1 ) ) {
if ( V_262 -> V_147 == 1 )
V_370 -> V_374 = false ;
else
V_370 -> V_374 = true ;
} else if ( V_262 -> V_374 == 2 ) {
V_370 -> V_374 = true ;
}
V_149 = 0 ;
V_382 = F_164 ( V_407 + sizeof( struct V_129 ) , V_391 , & V_149 , V_326 - sizeof( struct V_129 ) ) ;
if ( V_382 && V_149 > 0 ) {
V_409 = (struct V_383 * ) ( V_382 + 2 ) ;
V_408 = ( V_409 -> V_403 & V_412 ) ;
V_408 = 1 << ( V_408 + 3 ) ;
V_370 -> V_413 = V_408 ;
}
V_149 = 0 ;
V_382 = F_164 ( V_407 + sizeof( struct V_129 ) , V_405 , & V_149 , V_326 - sizeof( struct V_129 ) ) ;
if ( ( V_262 -> V_414 ) &&
( F_42 ( V_234 -> V_415 . V_416 . V_417 . V_418 ) & F_153 ( 1 ) ) &&
( V_234 -> V_419 . V_420 [ 0 ] & F_153 ( 2 ) ) ) {
int V_3 ;
T_1 V_421 ;
V_2 -> V_422 . V_423 ( V_2 , V_424 , ( T_1 * ) ( & V_421 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( V_421 == V_425 ) || ( V_421 == V_426 ) )
V_234 -> V_415 . V_416 . V_417 . V_427 [ V_3 ] &= V_428 [ V_3 ] ;
else
V_234 -> V_415 . V_416 . V_417 . V_427 [ V_3 ] &= V_429 [ V_3 ] ;
}
V_153 -> V_430 = V_431 ;
switch ( ( V_234 -> V_419 . V_420 [ 0 ] & 0x3 ) ) {
case V_432 :
V_153 -> V_433 = V_434 ;
break;
case V_435 :
V_153 -> V_433 = V_436 ;
break;
default:
V_153 -> V_433 = V_437 ;
break;
}
}
V_234 -> V_438 = ( F_42 ( V_234 -> V_415 . V_416 . V_417 . V_418 ) & 0x0C ) >> 2 ;
if ( V_234 -> V_438 == V_439 )
F_68 ( L_65 , V_196 ) ;
V_234 -> V_440 = V_234 -> V_419 . V_420 [ 1 ] & 0x3 ;
}
void F_166 ( struct V_1 * V_2 , struct V_441 * V_442 )
{
T_1 V_443 ;
int V_444 ;
struct V_179 * V_180 = NULL ;
struct V_369 * V_370 ;
struct V_445 * V_446 = & V_442 -> V_447 ;
T_6 V_448 = F_167 ( V_446 -> V_449 ) ;
if ( V_448 || ( V_2 -> V_9 . V_450 . V_451 < 100 ) )
return;
V_444 = V_446 -> V_444 ;
if ( V_446 -> V_180 )
V_180 = V_446 -> V_180 ;
else
V_180 = F_92 ( & V_2 -> V_175 , V_446 -> V_449 ) ;
if ( V_180 == NULL )
return;
V_370 = & V_180 -> V_371 ;
if ( ( V_370 -> V_375 ) && ( V_370 -> V_374 ) ) {
V_443 = ( V_370 -> V_452 >> V_444 ) & 0x1 ;
V_443 |= ( V_370 -> V_453 >> V_444 ) & 0x1 ;
if ( 0 == V_443 ) {
F_68 ( L_66 , V_444 ) ;
V_180 -> V_371 . V_453 |= F_153 ( ( T_1 ) V_444 ) ;
F_168 ( V_2 , ( T_1 ) V_444 , V_446 -> V_449 ) ;
}
}
}
void F_169 ( struct V_1 * V_2 , struct V_5 * V_176 )
{
unsigned long V_58 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
F_20 ( & V_8 -> V_22 , & V_58 ) ;
F_130 ( V_2 , V_176 ) ;
F_21 ( & V_8 -> V_22 , & V_58 ) ;
}
void F_130 ( struct V_1 * V_2 , struct V_5 * V_176 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_257 ;
struct V_5 * V_6 ;
if ( V_176 != NULL )
V_6 = V_176 ;
else
V_6 = & V_8 -> V_16 ;
if ( 0 < V_8 -> V_163 ) {
F_68 ( L_67 ,
V_6 -> V_17 . V_104 . V_104 , V_6 -> V_17 . V_82 ,
V_6 -> V_17 . V_104 . V_105 ) ;
memcpy ( & V_8 -> V_25 , & V_6 -> V_17 . V_104 , sizeof( struct V_26 ) ) ;
V_8 -> V_274 = false ;
while ( 1 ) {
V_257 = F_133 ( V_2 ) ;
if ( V_11 == V_257 ) {
break;
} else {
F_68 ( L_68 , V_257 ) ;
V_8 -> V_163 -- ;
if ( 0 < V_8 -> V_163 ) {
continue;
} else {
F_68 ( L_69 , V_196 , __LINE__ ) ;
F_84 ( V_2 ) ;
break;
}
}
}
}
}
