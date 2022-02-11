static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
memset ( ( T_2 * ) V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_10 = ( T_2 * ) V_2 ;
V_8 -> V_11 = NULL ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 . V_14 . V_15 =
V_16 ;
V_8 -> V_17 = 1 ;
F_2 ( & ( V_8 -> V_18 ) ) ;
F_2 ( & ( V_8 -> V_19 ) ) ;
F_3 ( & ( V_8 -> V_20 ) ) ;
F_3 ( & ( V_8 -> V_21 ) ) ;
F_4 ( V_8 , 0 ) ;
memset ( & V_8 -> V_22 , 0 , sizeof( struct V_23 ) ) ;
V_4 = F_5 ( V_24 * ( sizeof( struct V_5 ) ) ,
V_25 ) ;
if ( V_4 == NULL )
return V_26 ;
V_8 -> V_27 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ ) {
F_6 ( & ( V_6 -> V_28 ) ) ;
F_7 ( & ( V_6 -> V_28 ) ,
& ( V_8 -> V_20 . V_29 ) ) ;
V_6 ++ ;
}
V_8 -> V_30 . V_31 = 0 ;
V_8 -> V_30 . V_32 = 0 ;
V_8 -> V_30 . V_33 = false ;
F_8 ( V_2 ) ;
return V_34 ;
}
struct V_5 * F_9 ( struct V_7 * V_8 )
{
unsigned long V_35 ;
struct V_5 * V_6 ;
struct V_36 * V_37 = & V_8 -> V_20 ;
struct V_38 * V_39 = NULL ;
if ( F_10 ( & V_37 -> V_29 ) )
return NULL ;
F_11 ( & V_37 -> V_18 , V_35 ) ;
V_39 = V_37 -> V_29 . V_40 ;
V_6 = F_12 ( V_39 , struct V_5 , V_28 ) ;
F_13 ( & V_6 -> V_28 ) ;
V_6 -> V_41 = V_42 ;
V_8 -> V_43 ++ ;
F_14 ( & V_37 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_15 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_44 , V_45 ;
unsigned long V_35 ;
struct V_36 * V_37 = & ( V_8 -> V_20 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_46 == true )
return;
V_44 = V_42 ;
V_45 = ( V_44 - ( T_3 ) V_6 -> V_41 ) / V_47 ;
if ( V_45 < V_48 )
return;
F_11 ( & V_37 -> V_18 , V_35 ) ;
F_13 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , & V_37 -> V_29 ) ;
V_8 -> V_43 -- ;
F_14 ( & V_37 -> V_18 , V_35 ) ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_36 * V_37 = & V_8 -> V_20 ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_46 == true )
return;
F_13 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , & V_37 -> V_29 ) ;
V_8 -> V_43 -- ;
}
static struct V_5 * F_17 ( struct V_36 * V_21 ,
T_2 * V_49 )
{
unsigned long V_35 ;
struct V_38 * V_50 , * V_39 ;
struct V_5 * V_6 = NULL ;
if ( F_18 ( V_49 ) )
return NULL ;
F_11 ( & V_21 -> V_18 , V_35 ) ;
V_50 = & V_21 -> V_29 ;
V_39 = V_50 -> V_40 ;
while ( V_39 != V_50 ) {
V_6 = F_12 ( V_39 , struct V_5 , V_28 ) ;
V_39 = V_39 -> V_40 ;
if ( ! memcmp ( V_49 , V_6 -> V_14 . V_51 , V_52 ) )
break;
}
F_14 ( & V_21 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_38 * V_50 , * V_39 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_36 * V_21 = & V_8 -> V_21 ;
F_11 ( & V_21 -> V_18 , V_35 ) ;
V_50 = & V_21 -> V_29 ;
V_39 = V_50 -> V_40 ;
while ( F_20 ( V_50 , V_39 ) == false ) {
V_6 = F_12 ( V_39 , struct V_5 , V_28 ) ;
V_39 = V_39 -> V_40 ;
F_15 ( V_8 , V_6 ) ;
}
F_14 ( & V_21 -> V_18 , V_35 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_53 ;
if ( V_2 -> V_54 || V_2 -> V_55 ||
( F_22 ( & V_2 -> V_9 , V_56 ) == false ) ) {
V_53 = false ;
} else
V_53 = true ;
return V_53 ;
}
void F_23 ( T_2 * V_57 )
{
T_3 V_58 = V_42 ;
V_57 [ 0 ] = 0x02 ;
V_57 [ 1 ] = 0x11 ;
V_57 [ 2 ] = 0x87 ;
V_57 [ 3 ] = ( T_2 ) ( V_58 & 0xff ) ;
V_57 [ 4 ] = ( T_2 ) ( ( V_58 >> 8 ) & 0xff ) ;
V_57 [ 5 ] = ( T_2 ) ( ( V_58 >> 16 ) & 0xff ) ;
}
T_4 F_24 ( struct V_59 * V_60 )
{
T_4 V_61 ;
V_61 = sizeof( T_3 ) + 6 * sizeof( unsigned long ) + 2 +
sizeof( struct V_23 ) + sizeof( T_3 ) +
sizeof( V_62 ) +
sizeof( enum V_63 ) +
sizeof( struct V_64 ) +
sizeof( enum V_65 ) +
sizeof( V_66 ) +
sizeof( T_3 ) + V_60 -> V_67 ;
return V_61 ;
}
T_2 * F_25 ( T_2 * V_68 )
{
return V_68 + 8 + 2 ;
}
int F_26 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_27 ( struct V_7 * V_8 )
{
F_28 ( V_8 -> V_27 ) ;
}
static struct V_5 * F_29 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) ;
}
static void F_30 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_16 ( V_8 , V_6 ) ;
}
void F_31 ( struct V_1 * V_69 )
{
F_19 ( V_69 ) ;
}
static struct V_5 * F_32 ( struct V_36 * V_21 ,
T_2 * V_49 )
{
struct V_5 * V_6 = F_17 ( V_21 ,
V_49 ) ;
return V_6 ;
}
int F_33 ( struct V_1 * V_70 , struct V_5 * V_6 )
{
int V_71 = true ;
struct V_72 * V_73 = & V_70 -> V_74 ;
if ( ( V_73 -> V_75 != V_76 ) &&
( V_6 -> V_14 . V_77 == 0 ) )
V_71 = false ;
else if ( ( V_73 -> V_75 == V_76 ) &&
( V_6 -> V_14 . V_77 == 1 ) )
V_71 = false ;
else
V_71 = true ;
return V_71 ;
}
static int F_34 ( struct V_59 * V_78 ,
struct V_59 * V_79 )
{
T_5 V_80 , V_81 ;
memcpy ( ( T_2 * ) & V_80 , F_25 ( V_78 -> V_82 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_81 , F_25 ( V_79 -> V_82 ) , 2 ) ;
return ( V_78 -> V_83 . V_84 == V_79 -> V_83 . V_84 ) &&
( V_78 -> V_85 . V_86 ==
V_79 -> V_85 . V_86 ) &&
( ( ! memcmp ( V_78 -> V_51 , V_79 -> V_51 ,
V_52 ) ) ) &&
( ( ! memcmp ( V_78 -> V_83 . V_83 ,
V_79 -> V_83 . V_83 ,
V_78 -> V_83 . V_84 ) ) ) &&
( ( V_80 & V_87 ) ==
( V_81 & V_87 ) ) &&
( ( V_80 & V_88 ) ==
( V_81 & V_88 ) ) ;
}
struct V_5 * F_35 (
struct V_36 * V_21 )
{
struct V_38 * V_39 , * V_50 ;
struct V_5 * V_89 = NULL ;
struct V_5 * V_90 = NULL ;
V_50 = & V_21 -> V_29 ;
V_39 = V_50 -> V_40 ;
while ( 1 ) {
if ( F_20 ( V_50 , V_39 ) == true )
break;
V_89 = F_12 ( V_39 , struct V_5 , V_28 ) ;
if ( V_89 -> V_46 != true ) {
if ( V_90 == NULL ||
F_36 ( ( unsigned long ) V_90 -> V_41 ,
( unsigned long ) V_89 -> V_41 ) )
V_90 = V_89 ;
}
V_39 = V_39 -> V_40 ;
}
return V_90 ;
}
static void F_37 ( struct V_59 * V_79 ,
struct V_59 * V_78 ,
struct V_1 * V_2 )
{
T_3 V_91 = 0 , V_92 ;
if ( F_22 ( & V_2 -> V_9 , V_56 ) &&
F_34 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_78 ) ) {
if ( V_2 -> V_93 . V_94 . V_95 ++ >=
V_96 ) {
V_2 -> V_93 . V_94 . V_95 =
V_96 ;
V_91 = V_2 -> V_93 . V_94 .
V_97 [ V_2 -> V_93 .
V_94 . V_98 ] ;
V_2 -> V_93 . V_94 . V_99 -=
V_91 ;
}
V_2 -> V_93 . V_94 . V_99 += V_78 -> V_100 ;
V_2 -> V_93 . V_94 .
V_97 [ V_2 -> V_93 . V_94 .
V_98 ++ ] = V_78 -> V_100 ;
if ( V_2 -> V_93 . V_94 . V_98 >=
V_96 )
V_2 -> V_93 . V_94 . V_98 = 0 ;
V_92 = V_2 -> V_93 . V_94 . V_99 /
V_2 -> V_93 . V_94 . V_95 ;
V_2 -> V_93 . signal = ( T_2 ) V_92 ;
V_78 -> V_100 = V_2 -> V_93 . signal ;
} else
V_78 -> V_100 = ( V_78 -> V_100 + V_79 -> V_100 ) / 2 ;
memcpy ( ( T_2 * ) V_79 , ( T_2 * ) V_78 , F_24 ( V_78 ) ) ;
}
static void F_38 ( struct V_1 * V_70 ,
struct V_59 * V_6 )
{
struct V_7 * V_8 = & V_70 -> V_9 ;
if ( F_34 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_37 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_70 ) ;
F_39 ( V_70 ,
( V_8 -> V_13 . V_14 . V_82 ) +
sizeof( struct V_101 ) ,
V_8 -> V_13 . V_14 . V_67 ) ;
}
}
static void F_40 ( struct V_1 * V_70 ,
struct V_59 * V_102 )
{
struct V_38 * V_39 , * V_50 ;
T_3 V_103 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_36 * V_29 = & V_8 -> V_21 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_90 = NULL ;
V_50 = & V_29 -> V_29 ;
V_39 = V_50 -> V_40 ;
while ( 1 ) {
if ( F_20 ( V_50 , V_39 ) == true )
break;
V_6 = F_12 ( V_39 , struct V_5 , V_28 ) ;
if ( F_34 ( & V_6 -> V_14 , V_102 ) )
break;
if ( ( V_90 == ( (struct V_5 * ) 0 ) ) ||
F_36 ( ( unsigned long ) V_90 -> V_41 ,
( unsigned long ) V_6 -> V_41 ) )
V_90 = V_6 ;
V_39 = V_39 -> V_40 ;
}
if ( F_20 ( V_50 , V_39 ) == true ) {
if ( F_10 ( & V_8 -> V_20 . V_29 ) ) {
V_6 = V_90 ;
V_102 -> V_100 = ( V_6 -> V_14 . V_100 +
V_102 -> V_100 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_102 ,
F_24 ( V_102 ) ) ;
V_6 -> V_41 = V_42 ;
} else {
V_6 = F_29 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_103 = F_24 ( V_102 ) ;
V_102 -> V_104 = V_103 ;
memcpy ( & V_6 -> V_14 , V_102 , V_103 ) ;
F_7 ( & V_6 -> V_28 , & V_29 -> V_29 ) ;
}
} else {
F_37 ( & V_6 -> V_14 , V_102 , V_70 ) ;
V_6 -> V_41 = V_42 ;
}
}
static void F_41 ( struct V_1 * V_70 ,
struct V_59 * V_6 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_70 ) -> V_9 ) ;
struct V_36 * V_29 = & V_8 -> V_21 ;
F_11 ( & V_29 -> V_18 , V_35 ) ;
F_38 ( V_70 , V_6 ) ;
F_40 ( V_70 , V_6 ) ;
F_14 ( & V_29 -> V_18 , V_35 ) ;
}
static int F_42 ( struct V_1 * V_70 ,
struct V_5 * V_6 )
{
T_2 V_105 [ 512 ] ;
T_4 V_106 ;
int V_107 = true ;
struct V_72 * V_73 = & V_70 -> V_74 ;
if ( V_73 -> V_108 == true ) {
if ( F_43 ( V_6 -> V_14 . V_82 ,
V_6 -> V_14 . V_67 , V_105 ,
& V_106 ) == true )
return true ;
else
return false ;
}
if ( ( V_73 -> V_75 != V_76 ) &&
( V_6 -> V_14 . V_77 == 0 ) )
V_107 = false ;
if ( F_22 ( & V_70 -> V_9 , V_109 ) == true ) {
if ( V_6 -> V_14 . V_15 !=
V_70 -> V_9 . V_13 . V_14 .
V_15 )
V_107 = false ;
}
return V_107 ;
}
void F_44 ( struct V_1 * V_70 , T_2 * V_4 )
{
}
void F_45 ( struct V_1 * V_70 , T_2 * V_4 )
{
unsigned long V_110 ;
T_3 V_111 ;
struct V_59 * V_6 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
V_6 = (struct V_59 * ) V_4 ;
#ifdef F_46
V_6 -> V_104 = F_47 ( V_6 -> V_104 ) ;
V_6 -> V_83 . V_84 = F_47 ( V_6 -> V_83 . V_84 ) ;
V_6 -> V_77 = F_47 ( V_6 -> V_77 ) ;
V_6 -> V_100 = F_47 ( V_6 -> V_100 ) ;
V_6 -> V_112 = F_47 ( V_6 -> V_112 ) ;
V_6 -> V_85 . V_113 =
F_47 ( V_6 -> V_85 . V_113 ) ;
V_6 -> V_85 . V_114 =
F_47 ( V_6 -> V_85 . V_114 ) ;
V_6 -> V_85 . V_86 =
F_47 ( V_6 -> V_85 . V_86 ) ;
V_6 -> V_85 . V_115 . V_116 =
F_47 ( V_6 -> V_85 . V_115 . V_116 ) ;
V_6 -> V_85 . V_115 . V_117 =
F_47 ( V_6 -> V_85 . V_115 . V_117 ) ;
V_6 -> V_85 . V_115 . V_118 =
F_47 ( V_6 -> V_85 . V_115 . V_118 ) ;
V_6 -> V_85 . V_115 . V_104 =
F_47 ( V_6 -> V_85 . V_115 . V_104 ) ;
V_6 -> V_85 . V_104 =
F_47 ( V_6 -> V_85 . V_104 ) ;
V_6 -> V_15 =
F_47 ( V_6 -> V_15 ) ;
V_6 -> V_67 = F_47 ( V_6 -> V_67 ) ;
#endif
V_111 = F_24 ( V_6 ) ;
if ( V_111 > sizeof( struct V_119 ) )
return;
F_11 ( & V_8 -> V_19 , V_110 ) ;
if ( F_22 ( V_8 , V_120 ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_51 ) ,
V_6 -> V_51 , V_52 ) ) {
struct V_5 * V_121 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_82 ,
V_6 -> V_82 , 8 ) ;
V_121 = F_32 (
& V_8 -> V_21 ,
V_6 -> V_51 ) ;
if ( V_121 ) {
memcpy ( V_121 -> V_14 . V_82 ,
V_6 -> V_82 , 8 ) ;
goto exit;
}
}
}
if ( F_22 ( V_8 , V_122 ) == false ) {
if ( V_6 -> V_83 . V_83 [ 0 ] != 0 )
F_41 ( V_70 , V_6 ) ;
else {
V_6 -> V_83 . V_84 = 8 ;
memcpy ( V_6 -> V_83 . V_83 , L_1 , 8 ) ;
F_41 ( V_70 , V_6 ) ;
}
}
exit:
F_14 ( & V_8 -> V_19 , V_110 ) ;
}
void F_48 ( struct V_1 * V_70 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( F_22 ( V_8 , V_123 ) == true ) {
T_2 V_124 ;
F_49 ( & V_8 -> V_125 , & V_124 ) ;
F_50 ( V_8 , V_123 ) ;
}
if ( V_8 -> V_126 == true ) {
if ( F_22 ( V_8 , V_109 ) == true ) {
if ( F_22 ( V_8 , V_56 ) == false ) {
F_51 ( V_8 , V_122 ) ;
if ( F_52 ( V_8 )
== V_34 )
F_53 ( & V_8 -> V_127 ,
V_128 ) ;
else {
struct V_119 * V_129 =
& ( V_70 -> V_130 . V_131 ) ;
T_2 * V_57 =
V_70 -> V_130 .
V_131 . V_51 ;
V_8 -> V_12 ^= V_123 ;
memcpy ( & V_129 -> V_83 ,
& V_8 -> V_22 ,
sizeof( struct
V_23 ) ) ;
F_54
( V_70 ) ;
F_23 ( V_57 ) ;
V_8 -> V_12 =
V_120 ;
V_8 -> V_126 = false ;
}
}
} else {
V_8 -> V_126 = false ;
F_51 ( V_8 , V_122 ) ;
if ( F_52 ( V_8 ) ==
V_34 )
F_53 ( & V_8 -> V_127 ,
V_128 ) ;
else
F_50 ( V_8 , V_122 ) ;
}
}
F_14 ( & V_8 -> V_18 , V_35 ) ;
}
void F_55 ( struct V_1 * V_70 )
{
unsigned long V_35 ;
struct V_5 * V_89 = NULL ;
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_132 * V_133 = & V_70 -> V_134 ;
struct V_5 * V_135 = & V_8 -> V_13 ;
V_89 = F_32 ( & V_8 -> V_21 ,
V_135 -> V_14 . V_51 ) ;
if ( F_22 ( V_8 , V_136 | V_137 ) ) {
struct V_138 * V_139 ;
V_139 = F_56 ( & V_70 -> V_134 ,
V_135 -> V_14 . V_51 ) ;
F_11 ( & V_133 -> V_140 , V_35 ) ;
F_57 ( V_70 , V_139 ) ;
F_14 ( & V_133 -> V_140 , V_35 ) ;
}
if ( F_22 ( V_8 ,
V_109 | V_120 | V_137 ) )
F_58 ( V_70 ) ;
if ( V_89 )
V_89 -> V_46 = false ;
if ( ( ( F_22 ( V_8 , V_120 ) ) &&
( V_70 -> V_134 . V_141 == 1 ) ) )
F_30 ( V_8 , V_89 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_126 = false ;
F_51 ( V_8 , V_56 ) ;
V_2 -> V_142 . V_143 ( V_2 , V_144 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_130 . V_145 > V_146 )
F_53 ( & V_8 -> V_147 , 60000 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( F_22 ( V_8 , V_56 ) == true ) {
F_50 ( V_8 , V_56 ) ;
V_2 -> V_142 . V_143 ( V_2 , V_148 ) ;
F_62 ( V_2 ) ;
}
if ( V_2 -> V_149 . V_150 !=
V_2 -> V_130 . V_145 ) {
F_63 ( & V_8 -> V_147 ) ;
F_64 ( V_2 , V_2 -> V_130 . V_145 ,
V_2 -> V_130 . V_151 ) ;
}
}
void F_65 ( struct V_1 * V_70 , T_2 * V_4 )
{
unsigned long V_35 = 0 , V_152 ;
T_2 V_124 ;
struct V_138 * V_153 = NULL , * V_154 = NULL ;
struct V_132 * V_133 = & V_70 -> V_134 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_155 = NULL , * V_156 = NULL ;
unsigned int V_157 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_38 ) == 4 * sizeof( T_3 ) ) {
V_6 = F_5 ( sizeof( struct V_5 ) , V_25 ) ;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else
V_6 = (struct V_5 * ) V_4 ;
#ifdef F_46
V_6 -> V_158 = F_47 ( V_6 -> V_158 ) ;
V_6 -> V_159 = F_47 ( V_6 -> V_159 ) ;
V_6 -> V_14 . V_104 = F_47 ( V_6 -> V_14 . V_104 ) ;
V_6 -> V_14 . V_83 . V_84 =
F_47 ( V_6 -> V_14 . V_83 . V_84 ) ;
V_6 -> V_14 . V_77 = F_47 ( V_6 -> V_14 . V_77 ) ;
V_6 -> V_14 . V_100 = F_47 ( V_6 -> V_14 . V_100 ) ;
V_6 -> V_14 . V_112 =
F_47 ( V_6 -> V_14 . V_112 ) ;
V_6 -> V_14 . V_85 . V_113 =
F_47 ( V_6 -> V_14 . V_85 . V_113 ) ;
V_6 -> V_14 . V_85 . V_114 =
F_47 ( V_6 -> V_14 . V_85 . V_114 ) ;
V_6 -> V_14 . V_85 . V_86 =
F_47 ( V_6 -> V_14 . V_85 . V_86 ) ;
V_6 -> V_14 . V_85 . V_115 . V_116 =
F_47 ( V_6 -> V_14 . V_85 . V_115 .
V_116 ) ;
V_6 -> V_14 . V_85 . V_115 . V_117 =
F_47 ( V_6 -> V_14 . V_85 .
V_115 . V_117 ) ;
V_6 -> V_14 . V_85 . V_115 . V_118 =
F_47 ( V_6 -> V_14 . V_85 . V_115 . V_118 ) ;
V_6 -> V_14 . V_85 . V_115 . V_104 =
F_47 ( V_6 -> V_14 . V_85 . V_115 . V_104 ) ;
V_6 -> V_14 . V_85 . V_104 =
F_47 ( V_6 -> V_14 . V_85 . V_104 ) ;
V_6 -> V_14 . V_15 =
F_47 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_67 = F_47 ( V_6 -> V_14 . V_67 ) ;
#endif
V_157 = ! memcmp ( V_6 -> V_14 . V_51 ,
V_13 -> V_14 . V_51 , V_52 ) ;
V_6 -> V_14 . V_104 =
F_24 ( & V_6 -> V_14 ) ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( V_6 -> V_14 . V_104 > sizeof( struct V_119 ) )
goto V_160;
if ( V_6 -> V_158 > 0 ) {
if ( F_22 ( V_8 , V_122 ) == true ) {
if ( F_22 ( V_8 , V_56 ) == true ) {
if ( V_157 == true )
V_156 =
F_32 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
else {
V_155 =
F_32 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
V_155 -> V_46 = false ;
V_154 = F_56 ( V_133 ,
V_13 -> V_14 . V_51 ) ;
F_11 ( & V_133 ->
V_140 , V_152 ) ;
F_57 ( V_70 , V_154 ) ;
F_14 ( & ( V_133 ->
V_140 ) , V_152 ) ;
V_156 =
F_32 ( & V_8 ->
V_21 ,
V_6 -> V_14 .
V_51 ) ;
if ( V_156 )
V_156 -> V_46 = true ;
}
} else {
V_156 = F_32 ( & V_8 ->
V_21 ,
V_6 -> V_14 . V_51 ) ;
if ( V_156 )
V_156 -> V_46 = true ;
}
if ( V_156 == NULL ) {
if ( F_22 ( V_8 ,
V_122 ) )
V_8 -> V_12 ^=
V_122 ;
goto V_160;
}
if ( F_22 ( V_8 , V_136 ) ) {
if ( V_157 == true ) {
V_153 =
F_56 ( V_133 ,
V_6 -> V_14 . V_51 ) ;
if ( V_153 == NULL )
V_153 =
F_66 ( V_133 ,
V_6 -> V_14 . V_51 ) ;
} else
V_153 =
F_66 ( V_133 ,
V_6 -> V_14 . V_51 ) ;
if ( V_153 ) {
V_153 -> V_161 = V_6 -> V_158 ;
V_153 -> V_162 = 1 ;
V_153 -> V_163 = 5 ;
if ( V_70 -> V_74 .
V_164 == 2 ) {
V_70 -> V_74 .
V_165 =
false ;
V_70 -> V_74 .
V_166 =
false ;
V_70 -> V_74 .
V_167 =
false ;
V_153 -> V_168
= true ;
V_153 -> V_169 =
V_70 -> V_74 .
V_75 ;
memset ( ( T_2 * ) & V_153 ->
V_170 ,
0 ,
sizeof( union V_171 ) ) ;
memset ( ( T_2 * ) & V_153 ->
V_172 ,
0 ,
sizeof( union V_171 ) ) ;
memset ( ( T_2 * ) & V_153 ->
V_173 ,
0 ,
sizeof( union V_171 ) ) ;
memset ( ( T_2 * ) & V_153 ->
V_174 , 0 ,
sizeof( union V_175 ) ) ;
memset ( ( T_2 * ) & V_153 ->
V_176 , 0 ,
sizeof( union V_175 ) ) ;
}
} else {
if ( F_22 ( V_8 ,
V_122 ) )
V_8 -> V_12 ^=
V_122 ;
goto V_160;
}
}
memcpy ( & V_13 -> V_14 , & V_6 -> V_14 ,
V_6 -> V_14 . V_104 ) ;
V_13 -> V_161 = V_6 -> V_158 ;
switch ( V_6 -> V_14 . V_15 ) {
case V_177 :
V_8 -> V_12 = V_136 ;
break;
case V_178 :
V_8 -> V_12 = V_109 ;
break;
default:
V_8 -> V_12 = V_179 ;
break;
}
F_39 ( V_70 ,
( V_13 -> V_14 . V_82 ) +
sizeof( struct V_101 ) ,
( V_13 -> V_14 . V_67 ) ) ;
F_67 ( V_70 , V_13 -> V_14 . V_82 ,
V_13 -> V_14 . V_67 ) ;
if ( F_22 ( V_8 , V_136 )
== true )
F_59 ( V_70 ) ;
F_49 ( & V_8 -> V_127 ,
& V_124 ) ;
} else
goto V_160;
} else {
if ( F_22 ( V_8 , V_122 ) == true ) {
F_53 ( & V_8 -> V_127 , 1 ) ;
F_50 ( V_8 , V_122 ) ;
}
}
V_160:
F_14 ( & V_8 -> V_18 , V_35 ) ;
if ( sizeof( struct V_38 ) == 4 * sizeof( T_3 ) )
F_28 ( V_6 ) ;
}
void F_68 ( struct V_1 * V_70 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_138 * V_139 ;
struct V_7 * V_8 = & ( V_70 -> V_9 ) ;
struct V_180 * V_181 = (struct V_180 * ) V_4 ;
if ( F_69 ( & V_70 -> V_182 , V_181 -> V_183 ) == false )
return;
V_139 = F_56 ( & V_70 -> V_134 , V_181 -> V_183 ) ;
if ( V_139 != NULL ) {
return;
}
V_139 = F_66 ( & V_70 -> V_134 , V_181 -> V_183 ) ;
if ( V_139 == NULL )
return;
V_139 -> V_162 = 0 ;
V_139 -> V_163 = F_47 ( ( T_4 ) V_181 -> V_184 ) ;
if ( V_70 -> V_74 . V_164 == 2 )
V_139 -> V_169 = V_70 -> V_74 . V_75 ;
V_139 -> V_168 = false ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( ( F_22 ( V_8 , V_120 ) == true ) ||
( F_22 ( V_8 , V_109 ) == true ) ) {
if ( V_70 -> V_134 . V_141 == 2 ) {
F_59 ( V_70 ) ;
}
}
F_14 ( & V_8 -> V_18 , V_35 ) ;
}
void F_70 ( struct V_1 * V_70 , T_2 * V_4 )
{
unsigned long V_35 , V_152 ;
struct V_138 * V_139 ;
struct V_5 * V_89 = NULL ;
struct V_119 * V_129 = NULL ;
T_2 * V_57 = NULL ;
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_185 * V_186 = (struct V_185 * ) V_4 ;
struct V_132 * V_133 = & V_70 -> V_134 ;
struct V_5 * V_135 = & V_8 -> V_13 ;
F_11 ( & V_8 -> V_18 , V_152 ) ;
if ( F_22 ( V_8 , V_136 ) == true ) {
F_61 ( V_70 ) ;
F_55 ( V_70 ) ;
}
if ( F_22 ( V_8 , V_120 |
V_109 ) ) {
V_139 = F_56 ( & V_70 -> V_134 , V_186 -> V_183 ) ;
F_11 ( & V_133 -> V_140 , V_35 ) ;
F_57 ( V_70 , V_139 ) ;
F_14 ( & V_133 -> V_140 , V_35 ) ;
if ( V_70 -> V_134 . V_141 == 1 ) {
V_89 = F_32 ( & V_8 -> V_21 ,
V_135 -> V_14 . V_51 ) ;
if ( V_89 ) {
V_89 -> V_46 = false ;
F_30 ( V_8 , V_89 ) ;
}
V_129 = & ( V_70 -> V_130 . V_131 ) ;
V_57 = V_70 -> V_130 . V_131 . V_51 ;
memcpy ( V_129 , & V_135 -> V_14 ,
F_24 ( & V_135 ->
V_14 ) ) ;
memcpy ( & V_129 -> V_83 ,
& V_8 -> V_22 ,
sizeof( struct V_23 ) ) ;
F_54 ( V_70 ) ;
F_23 ( V_57 ) ;
if ( F_22 ( V_8 , V_109 ) ) {
F_50 ( V_8 , V_109 ) ;
F_51 ( V_8 , V_120 ) ;
}
}
}
F_14 ( & V_8 -> V_18 , V_152 ) ;
}
void F_71 ( struct V_1 * V_70 , T_2 * V_4 )
{
struct V_187 * V_188 =
(struct V_187 * ) V_4 ;
V_188 -> V_189 |= ( T_2 ) ( V_70 -> V_149 . V_190 + 0x80 ) ;
F_72 ( V_70 , V_188 ) ;
}
void F_73 ( struct V_1 * V_70 , T_2 * V_4 )
{
struct V_191 * V_192 =
(struct V_191 * ) V_4 ;
struct V_138 * V_139 ;
struct V_132 * V_133 = & V_70 -> V_134 ;
struct V_193 * V_194 = NULL ;
V_139 = F_56 ( V_133 , V_192 -> V_51 ) ;
if ( V_139 ) {
V_194 =
& V_139 -> V_195 [ V_192 -> V_196 ] ;
V_194 -> V_197 = 0xffff ;
}
}
void F_74 ( struct V_1 * V_70 , T_2 * V_4 )
{
if ( V_70 -> V_74 . V_198 == false )
V_70 -> V_74 . V_198 = true ;
}
void F_75 ( struct V_1 * V_70 )
{
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_199 * V_200 = & V_8 -> V_30 ;
struct V_201 * V_202 = & V_70 -> V_130 ;
T_6 V_203 ;
T_4 V_204 ;
V_203 = ( V_70 -> V_205 . V_206 ) -
( V_200 -> V_32 ) ;
V_204 = ( V_70 -> V_93 . V_207 ) -
( V_200 -> V_31 ) ;
V_200 -> V_32 = V_70 -> V_205 . V_206 ;
V_200 -> V_31 = V_70 -> V_93 . V_207 ;
if ( ( V_203 > V_202 -> V_208 ) ||
( V_204 > V_202 -> V_208 ) )
V_200 -> V_33 = true ;
else
V_200 -> V_33 = false ;
}
void F_76 ( struct V_1 * V_70 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
if ( V_70 -> V_54 || V_70 -> V_55 )
return;
F_11 ( & V_8 -> V_18 , V_35 ) ;
F_50 ( V_8 , V_122 ) ;
V_8 -> V_126 = false ;
if ( F_22 ( V_8 , V_56 ) == true ) {
F_62 ( V_70 ) ;
F_50 ( V_8 , V_56 ) ;
}
if ( V_70 -> V_149 . V_150 != V_70 -> V_130 . V_145 ) {
F_64 ( V_70 , V_70 -> V_130 . V_145 ,
V_70 -> V_130 . V_151 ) ;
}
F_14 ( & V_8 -> V_18 , V_35 ) ;
}
void F_77 ( struct V_1 * V_70 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
F_50 ( V_8 , V_123 ) ;
V_8 -> V_126 = false ;
F_14 ( & V_8 -> V_18 , V_35 ) ;
}
void F_78 ( struct V_1 * V_70 )
{
if ( V_70 -> V_54 || V_70 -> V_55 )
return;
if ( V_70 -> V_149 . V_150 != V_70 -> V_130 . V_145 )
F_64 ( V_70 , V_70 -> V_130 . V_145 ,
V_70 -> V_130 . V_151 ) ;
}
void F_79 ( struct V_1 * V_70 )
{
F_80 ( V_70 ) ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_38 * V_50 ;
unsigned char * V_209 , * V_210 ;
struct V_1 * V_70 ;
struct V_36 * V_29 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_211 = NULL ;
V_70 = (struct V_1 * ) V_8 -> V_10 ;
V_29 = & V_8 -> V_21 ;
V_50 = & V_29 -> V_29 ;
V_8 -> V_11 = V_50 -> V_40 ;
while ( 1 ) {
if ( F_20 ( V_50 , V_8 -> V_11 ) == true ) {
if ( ( V_8 -> V_212 == true ) &&
( V_211 != NULL ) ) {
V_6 = V_211 ;
goto V_213;
}
return V_26 ;
}
V_6 = F_12 ( V_8 -> V_11 ,
struct V_5 , V_28 ) ;
if ( V_6 == NULL )
return V_26 ;
V_8 -> V_11 = V_8 -> V_11 -> V_40 ;
if ( V_8 -> V_214 == true ) {
V_209 = V_6 -> V_14 . V_51 ;
V_210 = V_8 -> V_215 ;
if ( ! memcmp ( V_209 , V_210 , V_52 ) ) {
if ( F_22 ( V_8 , V_56 ) ) {
if ( F_34 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_50 ( V_8 ,
V_122 ) ;
F_59 ( V_70 ) ;
return 2 ;
}
F_81 ( V_70 ) ;
F_61 ( V_70 ) ;
F_55 ( V_70 ) ;
}
goto V_213;
}
} else if ( V_8 -> V_22 . V_84 == 0 )
goto V_213;
V_209 = V_6 -> V_14 . V_83 . V_83 ;
V_210 = V_8 -> V_22 . V_83 ;
if ( ( V_6 -> V_14 . V_83 . V_84 ==
V_8 -> V_22 . V_84 ) &&
( ! memcmp ( V_209 , V_210 ,
V_8 -> V_22 . V_84 ) ) ) {
if ( V_8 -> V_212 == true ) {
if ( V_211 ) {
if ( V_6 -> V_14 . V_100 >
V_211 -> V_14 . V_100 )
V_211 = V_6 ;
} else
V_211 = V_6 ;
} else if ( F_42 ( V_70 , V_6 ) ) {
if ( F_22 ( V_8 , V_56 ) ) {
F_81 ( V_70 ) ;
F_55 ( V_70 ) ;
}
goto V_213;
}
}
}
return V_26 ;
V_213:
return F_82 ( V_70 , V_6 ) ;
}
T_1 F_83 ( struct V_1 * V_70 ,
struct V_72 * V_73 )
{
struct V_216 * V_217 = & V_70 -> V_218 ;
struct V_219 * V_220 ;
struct V_221 * V_222 ;
V_220 = F_5 ( sizeof( * V_220 ) , V_25 ) ;
if ( V_220 == NULL )
return V_26 ;
V_222 = F_84 ( sizeof( * V_222 ) , V_25 ) ;
if ( V_222 == NULL ) {
F_28 ( V_220 ) ;
return V_26 ;
}
V_222 -> V_223 = ( T_2 ) V_73 -> V_164 ;
V_220 -> V_224 = V_225 ;
V_220 -> V_226 = ( unsigned char * ) V_222 ;
V_220 -> V_227 = sizeof( struct V_221 ) ;
V_220 -> V_228 = NULL ;
V_220 -> V_229 = 0 ;
F_6 ( & V_220 -> V_28 ) ;
F_85 ( V_217 , V_220 ) ;
return V_34 ;
}
T_1 F_86 ( struct V_1 * V_70 ,
struct V_72 * V_73 ,
T_1 V_230 )
{
struct V_216 * V_217 = & V_70 -> V_218 ;
struct V_219 * V_220 ;
struct V_231 * V_232 ;
T_2 V_233 ;
T_1 V_71 = V_34 ;
V_220 = F_5 ( sizeof( * V_220 ) , V_25 ) ;
if ( V_220 == NULL )
return V_26 ;
V_232 = F_84 ( sizeof( * V_232 ) , V_25 ) ;
if ( V_232 == NULL ) {
V_71 = V_26 ;
goto V_234;
}
if ( V_73 -> V_164 == 2 ) {
V_232 -> V_235 =
( T_2 ) V_73 -> V_236 ;
} else {
V_232 -> V_235 =
( T_2 ) V_73 -> V_75 ;
}
V_232 -> V_230 = ( T_2 ) V_230 ;
switch ( V_232 -> V_235 ) {
case V_237 :
V_233 = 5 ;
memcpy ( V_232 -> V_238 ,
V_73 -> V_239 [ V_230 ] . V_240 , V_233 ) ;
break;
case V_241 :
V_233 = 13 ;
memcpy ( V_232 -> V_238 ,
V_73 -> V_239 [ V_230 ] . V_240 , V_233 ) ;
break;
case V_242 :
if ( V_230 < 1 || V_230 > 2 ) {
V_71 = V_26 ;
goto V_243;
}
V_233 = 16 ;
memcpy ( V_232 -> V_238 ,
& V_73 -> V_244 [ V_230 - 1 ] , V_233 ) ;
V_232 -> V_245 = 1 ;
break;
case V_246 :
if ( V_230 < 1 || V_230 > 2 ) {
V_71 = V_26 ;
goto V_243;
}
V_233 = 16 ;
memcpy ( V_232 -> V_238 ,
& V_73 -> V_244 [ V_230 - 1 ] , V_233 ) ;
V_232 -> V_245 = 1 ;
break;
default:
V_71 = V_26 ;
goto V_243;
}
V_220 -> V_224 = V_247 ;
V_220 -> V_226 = ( T_2 * ) V_232 ;
V_220 -> V_227 = ( sizeof( struct V_231 ) ) ;
V_220 -> V_228 = NULL ;
V_220 -> V_229 = 0 ;
F_6 ( & V_220 -> V_28 ) ;
F_85 ( V_217 , V_220 ) ;
return V_71 ;
V_243:
F_28 ( V_232 ) ;
V_234:
F_28 ( V_220 ) ;
return V_71 ;
}
int F_87 ( struct V_1 * V_70 , T_2 * V_248 , T_2 * V_249 ,
T_4 V_250 , T_4 V_251 )
{
unsigned int V_252 = 0 ;
unsigned int V_3 , V_253 ;
V_3 = 12 ;
while ( V_3 < V_250 ) {
V_252 = V_251 ;
if ( V_248 [ V_3 ] == 0xDD && V_248 [ V_3 + 2 ] == 0x00 &&
V_248 [ V_3 + 3 ] == 0x50 && V_248 [ V_3 + 4 ] == 0xF2 &&
V_248 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_250 ) {
for ( V_253 = V_3 ; V_253 < V_3 + 9 ; V_253 ++ ) {
V_249 [ V_252 ] = V_248 [ V_253 ] ;
V_252 ++ ;
}
V_249 [ V_251 + 1 ] = 0x07 ;
V_249 [ V_251 + 6 ] = 0x00 ;
V_249 [ V_251 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_248 [ V_3 + 1 ] + 2 ) ;
}
return V_252 ;
}
static int F_88 ( struct V_1 * V_254 , T_2 * V_255 )
{
struct V_72 * V_73 = & V_254 -> V_74 ;
int V_3 = 0 ;
do {
if ( V_73 -> V_256 [ V_3 ] . V_257 &&
( ! memcmp ( V_73 -> V_256 [ V_3 ] . V_258 ,
V_255 , V_52 ) ) )
break;
else
V_3 ++ ;
} while ( V_3 < V_259 );
if ( V_3 == V_259 ) {
V_3 = - 1 ;
} else {
;
}
return V_3 ;
}
T_1 F_89 ( struct V_1 * V_70 , T_2 * V_248 ,
T_2 * V_249 , T_4 V_250 )
{
T_2 V_260 = 0 , V_261 ;
T_2 V_262 [ 255 ] , V_263 [ 4 ] , V_264 [ 255 ] ;
T_2 V_265 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_252 , V_266 , V_267 ;
int V_268 ;
struct V_7 * V_8 = & V_70 -> V_9 ;
struct V_72 * V_73 = & V_70 -> V_74 ;
T_4 V_269 = V_73 -> V_270 ;
T_4 V_271 = V_73 -> V_272 ;
if ( ( V_269 == V_273 ) ||
( V_269 == V_274 ) ) {
V_260 = V_275 ;
V_263 [ 0 ] = 0x0 ;
V_263 [ 1 ] = 0x50 ;
V_263 [ 2 ] = 0xf2 ;
}
if ( ( V_269 == V_276 ) ||
( V_269 == V_277 ) ) {
V_260 = V_278 ;
V_263 [ 0 ] = 0x0 ;
V_263 [ 1 ] = 0x0f ;
V_263 [ 2 ] = 0xac ;
}
switch ( V_271 ) {
case V_279 :
case V_280 :
V_263 [ 3 ] = 0x1 ;
break;
case V_281 :
case V_282 :
V_263 [ 3 ] = 0x2 ;
break;
case V_283 :
case V_284 :
V_263 [ 3 ] = 0x4 ;
break;
default:
break;
}
V_266 = 12 ;
V_261 = false ;
while ( V_266 < V_250 ) {
if ( V_248 [ V_266 ] == V_260 ) {
if ( ( V_260 == V_275 ) &&
( ! memcmp ( & V_248 [ V_266 + 2 ] , & V_265 [ 0 ] , 4 ) ) ) {
memcpy ( & V_262 [ 0 ] , & V_248 [ V_266 ] ,
V_248 [ V_266 + 1 ] + 2 ) ;
V_261 = true ;
break;
}
if ( V_260 == V_278 ) {
memcpy ( & V_262 [ 0 ] , & V_248 [ V_266 ] ,
V_248 [ V_266 + 1 ] + 2 ) ;
V_261 = true ;
break;
}
if ( ( ( V_260 == V_275 ) &&
( ! memcmp ( & V_248 [ V_266 + 2 ] , & V_265 [ 0 ] , 4 ) ) ) ||
( V_260 == V_278 ) )
memcpy ( & V_264 [ 0 ] , & V_248 [ V_266 ] ,
V_248 [ V_266 + 1 ] + 2 ) ;
}
V_266 += V_248 [ V_266 + 1 ] + 2 ;
}
if ( V_261 == true ) {
if ( V_262 [ 0 ] == V_275 ) {
while ( true ) {
if ( memcmp ( & V_262 [ 2 ] , & V_265 [ 0 ] , 4 ) ) {
V_261 = false ;
break;
}
if ( ( V_262 [ 6 ] != 0x01 ) || ( V_262 [ 7 ] != 0x0 ) ) {
V_261 = false ;
break;
}
if ( ! memcmp ( & V_262 [ 8 ] , & V_265 [ 0 ] , 3 ) ) {
switch ( V_262 [ 11 ] ) {
case 0x0 :
V_73 -> V_236 =
V_76 ;
break;
case 0x1 :
V_73 -> V_236 =
V_237 ;
break;
case 0x2 :
V_73 -> V_236 =
V_242 ;
break;
case 0x3 :
case 0x4 :
V_73 -> V_236 =
V_246 ;
break;
case 0x5 :
V_73 -> V_236 =
V_241 ;
break;
}
} else {
V_261 = false ;
break;
}
if ( V_262 [ 12 ] == 0x01 ) {
if ( memcmp ( & V_262 [ 14 ] ,
& V_263 [ 0 ] , 4 ) ) {
V_261 = false ;
break;
}
} else {
V_266 = V_262 [ 12 ] ;
V_267 = ( V_266 - 1 ) * 4 ;
V_262 [ 12 ] = 0x01 ;
memcpy ( & V_262 [ 14 ] , & V_263 [ 0 ] , 4 ) ;
memcpy ( & V_262 [ 18 ] ,
& V_262 [ 18 + V_267 ] ,
V_262 [ 1 ] - 18 + 2 -
V_267 ) ;
V_262 [ 1 ] = V_262 [ 1 ] - V_267 ;
}
break;
}
}
if ( V_260 == V_278 ) {
while ( true ) {
if ( ( V_262 [ 2 ] != 0x01 ) || ( V_262 [ 3 ] != 0x0 ) ) {
V_261 = false ;
break;
}
if ( ! memcmp ( & V_262 [ 4 ] , & V_263 [ 0 ] , 3 ) ) {
switch ( V_262 [ 7 ] ) {
case 0x1 :
V_73 -> V_236 =
V_237 ;
break;
case 0x2 :
V_73 -> V_236 =
V_242 ;
break;
case 0x4 :
V_73 -> V_236 =
V_246 ;
break;
case 0x5 :
V_73 -> V_236 =
V_241 ;
break;
default:
V_73 -> V_236 =
V_76 ;
break;
}
} else {
V_261 = false ;
break;
}
if ( V_262 [ 8 ] == 0x01 ) {
if ( memcmp ( & V_262 [ 10 ] ,
& V_263 [ 0 ] , 4 ) ) {
V_261 = false ;
break;
}
} else {
V_266 = V_262 [ 8 ] ;
V_267 = ( V_266 - 1 ) * 4 ;
V_262 [ 8 ] = 0x01 ;
memcpy ( & V_262 [ 10 ] , & V_263 [ 0 ] , 4 ) ;
memcpy ( & V_262 [ 14 ] ,
& V_262 [ 14 + V_267 ] ,
( V_262 [ 1 ] - 14 + 2 -
V_267 ) ) ;
V_262 [ 1 ] = V_262 [ 1 ] - V_267 ;
}
break;
}
}
}
if ( ( V_260 == V_275 ) || ( V_260 == V_278 ) ) {
memcpy ( V_249 , V_248 , 12 ) ;
V_252 = 12 ;
if ( V_261 == true ) {
memcpy ( & V_249 [ V_252 ] , & V_262 [ 0 ] , V_262 [ 1 ] + 2 ) ;
V_252 += V_262 [ 1 ] + 2 ;
if ( V_260 == V_278 ) {
V_249 [ V_252 - 1 ] = 0 ;
V_249 [ V_252 - 2 ] = 0 ;
}
F_90 ( V_70 , V_260 , V_262 ) ;
}
} else {
memcpy ( V_249 , V_248 , 12 ) ;
V_252 = 12 ;
if ( V_73 -> V_108 == true ) {
memcpy ( V_249 + V_252 , V_73 -> V_105 ,
V_73 -> V_285 ) ;
V_252 += V_73 -> V_285 ;
}
}
V_268 = F_88 ( V_70 , V_8 -> V_215 ) ;
if ( V_268 < 0 )
return V_252 ;
else {
if ( V_260 == V_278 ) {
V_249 [ V_252 ] = 1 ;
V_252 ++ ;
V_249 [ V_252 ] = 0 ;
V_252 ++ ;
memcpy ( & V_249 [ V_252 ] ,
& V_73 -> V_256 [ V_268 ] . V_286 , 16 ) ;
V_252 += 16 ;
V_249 [ 13 ] += 18 ;
}
}
return V_252 ;
}
void F_91 ( struct V_1 * V_70 )
{
struct V_201 * V_202 = & V_70 -> V_130 ;
struct V_287 * V_288 = & V_70 -> V_289 ;
struct V_119 * V_129 = & V_202 -> V_131 ;
T_2 * V_290 = F_92 ( V_288 ) ;
memcpy ( V_129 -> V_51 , V_290 , V_52 ) ;
memcpy ( & V_129 -> V_83 , & V_202 -> V_291 ,
sizeof( struct V_23 ) ) ;
V_129 -> V_85 . V_104 =
sizeof( struct V_64 ) ;
V_129 -> V_85 . V_114 = 100 ;
V_129 -> V_85 . V_115 . V_104 = 0 ;
V_129 -> V_85 . V_115 . V_117 = 0 ;
V_129 -> V_85 . V_115 . V_118 = 0 ;
V_129 -> V_85 . V_115 . V_116 = 0 ;
}
void F_54 ( struct V_1 * V_70 )
{
int V_292 = 0 ;
struct V_201 * V_202 = & V_70 -> V_130 ;
struct V_119 * V_129 = & V_202 -> V_131 ;
struct V_72 * V_73 = & V_70 -> V_74 ;
struct V_5 * V_13 = & V_70 -> V_9 . V_13 ;
V_129 -> V_77 = F_93 ( V_73 -> V_75
> 0 ? 1 : 0 ) ;
V_129 -> V_100 = 0 ;
switch ( V_202 -> V_293 ) {
case V_294 :
V_129 -> V_112 = F_93 ( V_295 ) ;
break;
case V_296 :
case V_297 :
V_129 -> V_112 = F_93 ( V_298 ) ;
break;
case V_299 :
V_129 -> V_112 = F_93 ( V_300 ) ;
break;
default:
break;
}
V_129 -> V_85 . V_86 = F_93 (
V_202 -> V_301 ) ;
if ( V_13 -> V_14 . V_15 == V_178 )
V_129 -> V_85 . V_113 = F_93 ( 3 ) ;
V_129 -> V_15 = F_93 (
V_13 -> V_14 . V_15 ) ;
V_292 = F_94 ( V_202 ) ;
V_129 -> V_67 = V_292 ;
V_129 -> V_104 = F_24 (
(struct V_59 * ) V_129 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
V_303 -> V_305 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_303 -> V_306 [ V_3 ] = false ;
if ( V_303 -> V_307 ) {
F_96 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_96 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_97 ( struct V_1 * V_2 , T_2 * V_248 ,
T_2 * V_249 , T_4 V_250 , T_4 * V_308 )
{
T_3 V_309 , V_310 ;
unsigned char * V_311 ;
struct V_312 V_313 ;
unsigned char V_314 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_315 * V_316 = & V_8 -> V_317 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
V_303 -> V_307 = 0 ;
V_311 = F_98 ( V_248 + 12 , V_318 , & V_309 , V_250 - 12 ) ;
if ( V_311 && ( V_309 > 0 ) ) {
if ( V_316 -> V_162 == 0 ) {
V_310 = * V_308 ;
F_99 ( V_249 + V_310 , V_319 ,
V_320 , V_314 , V_308 ) ;
V_316 -> V_162 = 1 ;
}
V_310 = * V_308 ;
memset ( & V_313 , 0 , sizeof( struct V_312 ) ) ;
V_313 . V_321 = V_322 |
V_323 |
V_324 |
V_325 |
V_326 |
V_327 ;
V_313 . V_328 = ( V_329 &
0x03 ) | ( V_330 & 0x00 ) ;
F_99 ( V_249 + V_310 , V_318 ,
sizeof( struct V_312 ) ,
( unsigned char * ) & V_313 , V_308 ) ;
V_303 -> V_307 = 1 ;
}
return V_303 -> V_307 ;
}
static void F_67 ( struct V_1 * V_2 , T_2 * V_331 , T_4 V_332 )
{
T_2 * V_311 , V_333 ;
int V_3 , V_111 ;
struct V_138 * V_334 , * V_139 ;
struct V_312 * V_335 ;
struct V_193 * V_336 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
struct V_201 * V_202 = & V_2 -> V_130 ;
struct V_5 * V_337 = & ( V_8 -> V_13 ) ;
if ( ! V_303 -> V_307 )
return;
if ( ( V_303 -> V_305 == false ) &&
( V_202 -> V_305 == 1 ) )
V_303 -> V_305 = true ;
V_111 = 0 ;
V_311 = F_98 ( V_331 + sizeof( struct V_101 ) ,
V_318 ,
& V_111 , V_332 -
sizeof( struct V_101 ) ) ;
if ( V_311 && V_111 > 0 ) {
V_335 = (struct V_312 * ) ( V_311 + 2 ) ;
V_333 = ( V_335 -> V_328 &
V_329 ) ;
V_333 = 1 << ( V_333 + 3 ) ;
V_303 -> V_338 = V_333 ;
}
V_334 = F_100 ( V_2 ) ;
if ( V_334 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_336 = & V_334 -> V_195 [ V_3 ] ;
V_336 -> V_197 = 0xffff ;
V_336 -> V_339 = 0xffff ;
}
}
V_139 = F_56 ( & V_2 -> V_134 ,
V_337 -> V_14 . V_51 ) ;
if ( V_139 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_336 = & V_139 -> V_195 [ V_3 ] ;
V_336 -> V_197 = 0xffff ;
V_336 -> V_339 = 0xffff ;
}
}
V_111 = 0 ;
V_311 = F_98 ( V_331 + sizeof( struct V_101 ) ,
V_340 , & V_111 ,
V_332 - sizeof( struct V_101 ) ) ;
}
void F_101 ( struct V_1 * V_2 , int V_341 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
if ( ( V_303 -> V_307 == 1 ) && ( V_303 -> V_305 == true ) ) {
if ( V_303 -> V_306 [ V_341 ] == false ) {
F_102 ( V_2 , ( T_2 ) V_341 ) ;
V_303 -> V_306 [ V_341 ] = true ;
}
}
}
