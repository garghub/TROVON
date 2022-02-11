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
V_4 = F_5 ( V_24 * ( sizeof( struct V_5 ) ) ) ;
if ( V_4 == NULL )
return V_25 ;
V_8 -> V_26 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ ) {
F_6 ( & ( V_6 -> V_27 ) ) ;
F_7 ( & ( V_6 -> V_27 ) ,
& ( V_8 -> V_20 . V_28 ) ) ;
V_6 ++ ;
}
V_8 -> V_29 . V_30 = 0 ;
V_8 -> V_29 . V_31 = 0 ;
V_8 -> V_29 . V_32 = false ;
F_8 ( V_2 ) ;
return V_33 ;
}
struct V_5 * F_9 ( struct V_7 * V_8 )
{
unsigned long V_34 ;
struct V_5 * V_6 ;
struct V_35 * V_36 = & V_8 -> V_20 ;
struct V_37 * V_38 = NULL ;
if ( F_10 ( V_36 ) == true )
return NULL ;
F_11 ( & V_36 -> V_18 , V_34 ) ;
V_38 = F_12 ( & ( V_36 -> V_28 ) ) ;
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
F_14 ( & V_6 -> V_27 ) ;
V_6 -> V_39 = V_40 ;
V_8 -> V_41 ++ ;
F_15 ( & V_36 -> V_18 , V_34 ) ;
return V_6 ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_42 , V_43 ;
unsigned long V_34 ;
struct V_35 * V_36 = & ( V_8 -> V_20 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_44 == true )
return;
V_42 = V_40 ;
V_43 = ( V_42 - ( T_3 ) V_6 -> V_39 ) / V_45 ;
if ( V_43 < V_46 )
return;
F_11 ( & V_36 -> V_18 , V_34 ) ;
F_14 ( & V_6 -> V_27 ) ;
F_7 ( & V_6 -> V_27 , & V_36 -> V_28 ) ;
V_8 -> V_41 -- ;
F_15 ( & V_36 -> V_18 , V_34 ) ;
}
static void F_17 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_35 * V_36 = & V_8 -> V_20 ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_44 == true )
return;
F_14 ( & V_6 -> V_27 ) ;
F_7 ( & V_6 -> V_27 , F_18 ( V_36 ) ) ;
V_8 -> V_41 -- ;
}
static struct V_5 * F_19 ( struct V_35 * V_21 ,
T_2 * V_47 )
{
unsigned long V_34 ;
struct V_37 * V_48 , * V_38 ;
struct V_5 * V_6 = NULL ;
T_2 V_49 [ V_50 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( ! memcmp ( V_49 , V_47 , V_50 ) )
return NULL ;
F_11 ( & V_21 -> V_18 , V_34 ) ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( V_38 != V_48 ) {
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
V_38 = F_12 ( V_38 ) ;
if ( ! memcmp ( V_47 , V_6 -> V_14 . V_51 , V_50 ) )
break;
}
F_15 ( & V_21 -> V_18 , V_34 ) ;
return V_6 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
struct V_37 * V_48 , * V_38 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_35 * V_21 = & V_8 -> V_21 ;
F_11 ( & V_21 -> V_18 , V_34 ) ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( F_21 ( V_48 , V_38 ) == false ) {
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
V_38 = F_12 ( V_38 ) ;
F_16 ( V_8 , V_6 ) ;
}
F_15 ( & V_21 -> V_18 , V_34 ) ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_52 ;
if ( V_2 -> V_53 || V_2 -> V_54 ||
( F_23 ( & V_2 -> V_9 , V_55 ) == false ) ) {
V_52 = false ;
} else
V_52 = true ;
return V_52 ;
}
void F_24 ( T_2 * V_56 )
{
T_3 V_57 = V_40 ;
V_56 [ 0 ] = 0x02 ;
V_56 [ 1 ] = 0x11 ;
V_56 [ 2 ] = 0x87 ;
V_56 [ 3 ] = ( T_2 ) ( V_57 & 0xff ) ;
V_56 [ 4 ] = ( T_2 ) ( ( V_57 >> 8 ) & 0xff ) ;
V_56 [ 5 ] = ( T_2 ) ( ( V_57 >> 16 ) & 0xff ) ;
}
T_4 F_25 ( struct V_58 * V_59 )
{
T_4 V_60 ;
V_60 = sizeof( T_3 ) + 6 * sizeof( unsigned long ) + 2 +
sizeof( struct V_23 ) + sizeof( T_3 ) +
sizeof( V_61 ) +
sizeof( enum V_62 ) +
sizeof( struct V_63 ) +
sizeof( enum V_64 ) +
sizeof( V_65 ) +
sizeof( T_3 ) + V_59 -> V_66 ;
return V_60 ;
}
T_2 * F_26 ( T_2 * V_67 )
{
return V_67 + 8 + 2 ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
F_29 ( V_8 -> V_26 ) ;
}
static struct V_5 * F_30 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_17 ( V_8 , V_6 ) ;
}
void F_32 ( struct V_1 * V_68 )
{
F_20 ( V_68 ) ;
}
static struct V_5 * F_33 ( struct V_35 * V_21 ,
T_2 * V_47 )
{
struct V_5 * V_6 = F_19 ( V_21 ,
V_47 ) ;
return V_6 ;
}
int F_34 ( struct V_1 * V_69 , struct V_5 * V_6 )
{
int V_70 = true ;
struct V_71 * V_72 = & V_69 -> V_73 ;
if ( ( V_72 -> V_74 != V_75 ) &&
( V_6 -> V_14 . V_76 == 0 ) )
V_70 = false ;
else if ( ( V_72 -> V_74 == V_75 ) &&
( V_6 -> V_14 . V_76 == 1 ) )
V_70 = false ;
else
V_70 = true ;
return V_70 ;
}
static int F_35 ( struct V_58 * V_77 ,
struct V_58 * V_78 )
{
T_5 V_79 , V_80 ;
memcpy ( ( T_2 * ) & V_79 , F_26 ( V_77 -> V_81 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_80 , F_26 ( V_78 -> V_81 ) , 2 ) ;
return ( V_77 -> V_82 . V_83 == V_78 -> V_82 . V_83 ) &&
( V_77 -> V_84 . V_85 ==
V_78 -> V_84 . V_85 ) &&
( ( ! memcmp ( V_77 -> V_51 , V_78 -> V_51 ,
V_50 ) ) ) &&
( ( ! memcmp ( V_77 -> V_82 . V_82 ,
V_78 -> V_82 . V_82 ,
V_77 -> V_82 . V_83 ) ) ) &&
( ( V_79 & V_86 ) ==
( V_80 & V_86 ) ) &&
( ( V_79 & V_87 ) ==
( V_80 & V_87 ) ) ;
}
struct V_5 * F_36 (
struct V_35 * V_21 )
{
struct V_37 * V_38 , * V_48 ;
struct V_5 * V_88 = NULL ;
struct V_5 * V_89 = NULL ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_21 ( V_48 , V_38 ) == true )
break;
V_88 = F_13 ( V_38 , struct V_5 , V_27 ) ;
if ( V_88 -> V_44 != true ) {
if ( V_89 == NULL ||
F_37 ( ( unsigned long ) V_89 -> V_39 ,
( unsigned long ) V_88 -> V_39 ) )
V_89 = V_88 ;
}
V_38 = F_12 ( V_38 ) ;
}
return V_89 ;
}
static void F_38 ( struct V_58 * V_78 ,
struct V_58 * V_77 ,
struct V_1 * V_2 )
{
T_3 V_90 = 0 , V_91 ;
if ( F_23 ( & V_2 -> V_9 , V_55 ) &&
F_35 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_77 ) ) {
if ( V_2 -> V_92 . V_93 . V_94 ++ >=
V_95 ) {
V_2 -> V_92 . V_93 . V_94 =
V_95 ;
V_90 = V_2 -> V_92 . V_93 .
V_96 [ V_2 -> V_92 .
V_93 . V_97 ] ;
V_2 -> V_92 . V_93 . V_98 -=
V_90 ;
}
V_2 -> V_92 . V_93 . V_98 += V_77 -> V_99 ;
V_2 -> V_92 . V_93 .
V_96 [ V_2 -> V_92 . V_93 .
V_97 ++ ] = V_77 -> V_99 ;
if ( V_2 -> V_92 . V_93 . V_97 >=
V_95 )
V_2 -> V_92 . V_93 . V_97 = 0 ;
V_91 = V_2 -> V_92 . V_93 . V_98 /
V_2 -> V_92 . V_93 . V_94 ;
V_2 -> V_92 . signal = ( T_2 ) V_91 ;
V_77 -> V_99 = V_2 -> V_92 . signal ;
} else
V_77 -> V_99 = ( V_77 -> V_99 + V_78 -> V_99 ) / 2 ;
memcpy ( ( T_2 * ) V_78 , ( T_2 * ) V_77 , F_25 ( V_77 ) ) ;
}
static void F_39 ( struct V_1 * V_69 ,
struct V_58 * V_6 )
{
struct V_7 * V_8 = & V_69 -> V_9 ;
if ( F_35 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_38 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_69 ) ;
F_40 ( V_69 ,
( V_8 -> V_13 . V_14 . V_81 ) +
sizeof( struct V_100 ) ,
V_8 -> V_13 . V_14 . V_66 ) ;
}
}
static void F_41 ( struct V_1 * V_69 ,
struct V_58 * V_101 )
{
struct V_37 * V_38 , * V_48 ;
T_3 V_102 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_35 * V_28 = & V_8 -> V_21 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_89 = NULL ;
V_48 = F_18 ( V_28 ) ;
V_38 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_21 ( V_48 , V_38 ) == true )
break;
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
if ( F_35 ( & V_6 -> V_14 , V_101 ) )
break;
if ( ( V_89 == ( (struct V_5 * ) 0 ) ) ||
F_37 ( ( unsigned long ) V_89 -> V_39 ,
( unsigned long ) V_6 -> V_39 ) )
V_89 = V_6 ;
V_38 = F_12 ( V_38 ) ;
}
if ( F_21 ( V_48 , V_38 ) == true ) {
if ( F_10 ( & V_8 -> V_20 ) == true ) {
V_6 = V_89 ;
V_101 -> V_99 = ( V_6 -> V_14 . V_99 +
V_101 -> V_99 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_101 ,
F_25 ( V_101 ) ) ;
V_6 -> V_39 = V_40 ;
} else {
V_6 = F_30 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_102 = F_25 ( V_101 ) ;
V_101 -> V_103 = V_102 ;
memcpy ( & V_6 -> V_14 , V_101 , V_102 ) ;
F_7 ( & V_6 -> V_27 , & V_28 -> V_28 ) ;
}
} else {
F_38 ( & V_6 -> V_14 , V_101 , V_69 ) ;
V_6 -> V_39 = V_40 ;
}
}
static void F_42 ( struct V_1 * V_69 ,
struct V_58 * V_6 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_69 ) -> V_9 ) ;
struct V_35 * V_28 = & V_8 -> V_21 ;
F_11 ( & V_28 -> V_18 , V_34 ) ;
F_39 ( V_69 , V_6 ) ;
F_41 ( V_69 , V_6 ) ;
F_15 ( & V_28 -> V_18 , V_34 ) ;
}
static int F_43 ( struct V_1 * V_69 ,
struct V_5 * V_6 )
{
T_2 V_104 [ 512 ] ;
T_4 V_105 ;
int V_106 = true ;
struct V_71 * V_72 = & V_69 -> V_73 ;
if ( V_72 -> V_107 == true ) {
if ( F_44 ( V_6 -> V_14 . V_81 ,
V_6 -> V_14 . V_66 , V_104 ,
& V_105 ) == true )
return true ;
else
return false ;
}
if ( ( V_72 -> V_74 != V_75 ) &&
( V_6 -> V_14 . V_76 == 0 ) )
V_106 = false ;
if ( F_23 ( & V_69 -> V_9 , V_108 ) == true ) {
if ( V_6 -> V_14 . V_15 !=
V_69 -> V_9 . V_13 . V_14 .
V_15 )
V_106 = false ;
}
return V_106 ;
}
void F_45 ( struct V_1 * V_69 , T_2 * V_4 )
{
}
void F_46 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_109 ;
T_3 V_110 ;
struct V_58 * V_6 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
V_6 = (struct V_58 * ) V_4 ;
#ifdef F_47
V_6 -> V_103 = F_48 ( V_6 -> V_103 ) ;
V_6 -> V_82 . V_83 = F_48 ( V_6 -> V_82 . V_83 ) ;
V_6 -> V_76 = F_48 ( V_6 -> V_76 ) ;
V_6 -> V_99 = F_48 ( V_6 -> V_99 ) ;
V_6 -> V_111 = F_48 ( V_6 -> V_111 ) ;
V_6 -> V_84 . V_112 =
F_48 ( V_6 -> V_84 . V_112 ) ;
V_6 -> V_84 . V_113 =
F_48 ( V_6 -> V_84 . V_113 ) ;
V_6 -> V_84 . V_85 =
F_48 ( V_6 -> V_84 . V_85 ) ;
V_6 -> V_84 . V_114 . V_115 =
F_48 ( V_6 -> V_84 . V_114 . V_115 ) ;
V_6 -> V_84 . V_114 . V_116 =
F_48 ( V_6 -> V_84 . V_114 . V_116 ) ;
V_6 -> V_84 . V_114 . V_117 =
F_48 ( V_6 -> V_84 . V_114 . V_117 ) ;
V_6 -> V_84 . V_114 . V_103 =
F_48 ( V_6 -> V_84 . V_114 . V_103 ) ;
V_6 -> V_84 . V_103 =
F_48 ( V_6 -> V_84 . V_103 ) ;
V_6 -> V_15 =
F_48 ( V_6 -> V_15 ) ;
V_6 -> V_66 = F_48 ( V_6 -> V_66 ) ;
#endif
V_110 = F_25 ( V_6 ) ;
if ( V_110 > sizeof( struct V_118 ) )
return;
F_11 ( & V_8 -> V_19 , V_109 ) ;
if ( F_23 ( V_8 , V_119 ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_51 ) ,
V_6 -> V_51 , V_50 ) ) {
struct V_5 * V_120 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_81 ,
V_6 -> V_81 , 8 ) ;
V_120 = F_33 (
& V_8 -> V_21 ,
V_6 -> V_51 ) ;
if ( ! V_120 ) {
memcpy ( V_120 -> V_14 . V_81 ,
V_6 -> V_81 , 8 ) ;
goto exit;
}
}
}
if ( F_23 ( V_8 , V_121 ) == false ) {
if ( V_6 -> V_82 . V_82 [ 0 ] != 0 )
F_42 ( V_69 , V_6 ) ;
else {
V_6 -> V_82 . V_83 = 8 ;
memcpy ( V_6 -> V_82 . V_82 , L_1 , 8 ) ;
F_42 ( V_69 , V_6 ) ;
}
}
exit:
F_15 ( & V_8 -> V_19 , V_109 ) ;
}
void F_49 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( F_23 ( V_8 , V_122 ) == true ) {
T_2 V_123 ;
F_50 ( & V_8 -> V_124 , & V_123 ) ;
F_51 ( V_8 , V_122 ) ;
}
if ( V_8 -> V_125 == true ) {
if ( ( F_23 ( V_8 , V_108 ) == true ) ) {
if ( F_23 ( V_8 , V_55 ) == false ) {
F_52 ( V_8 , V_121 ) ;
if ( F_53 ( V_8 )
== V_33 )
F_54 ( & V_8 -> V_126 ,
V_127 ) ;
else {
struct V_118 * V_128 =
& ( V_69 -> V_129 . V_130 ) ;
T_2 * V_56 =
V_69 -> V_129 .
V_130 . V_51 ;
V_8 -> V_12 ^= V_122 ;
memset ( & V_128 -> V_82 , 0 ,
sizeof( struct
V_23 ) ) ;
memcpy ( & V_128 -> V_82 ,
& V_8 -> V_22 ,
sizeof( struct
V_23 ) ) ;
F_55
( V_69 ) ;
F_24 ( V_56 ) ;
V_8 -> V_12 =
V_119 ;
V_8 -> V_125 = false ;
}
}
} else {
V_8 -> V_125 = false ;
F_52 ( V_8 , V_121 ) ;
if ( F_53 ( V_8 ) ==
V_33 )
F_54 ( & V_8 -> V_126 ,
V_127 ) ;
else
F_51 ( V_8 , V_121 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_56 ( struct V_1 * V_69 )
{
unsigned long V_34 ;
struct V_5 * V_88 = NULL ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_5 * V_134 = & V_8 -> V_13 ;
V_88 = F_33 ( & V_8 -> V_21 ,
V_134 -> V_14 . V_51 ) ;
if ( F_23 ( V_8 , V_135 | V_136 ) ) {
struct V_137 * V_138 ;
V_138 = F_57 ( & V_69 -> V_133 ,
V_134 -> V_14 . V_51 ) ;
F_11 ( & V_132 -> V_139 , V_34 ) ;
F_58 ( V_69 , V_138 ) ;
F_15 ( & V_132 -> V_139 , V_34 ) ;
}
if ( F_23 ( V_8 ,
V_108 | V_119 | V_136 ) )
F_59 ( V_69 ) ;
if ( V_88 )
V_88 -> V_44 = false ;
if ( ( ( F_23 ( V_8 , V_119 ) ) &&
( V_69 -> V_133 . V_140 == 1 ) ) )
F_31 ( V_8 , V_88 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_125 = false ;
F_52 ( V_8 , V_55 ) ;
V_2 -> V_141 . V_142 ( V_2 , V_143 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_129 . V_144 > V_145 )
F_54 ( & V_8 -> V_146 , 60000 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( F_23 ( V_8 , V_55 ) == true ) {
F_51 ( V_8 , V_55 ) ;
V_2 -> V_141 . V_142 ( V_2 , V_147 ) ;
F_63 ( V_2 ) ;
}
if ( V_2 -> V_148 . V_149 !=
V_2 -> V_129 . V_144 ) {
F_64 ( & V_8 -> V_146 ) ;
F_65 ( V_2 , V_2 -> V_129 . V_144 ,
V_2 -> V_129 . V_150 ) ;
}
}
void F_66 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_34 = 0 , V_151 ;
T_2 V_123 ;
struct V_137 * V_152 = NULL , * V_153 = NULL ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_154 = NULL , * V_155 = NULL ;
unsigned int V_156 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_37 ) == 4 * sizeof( T_3 ) ) {
V_6 = (struct V_5 * )
F_5 ( sizeof( struct V_5 ) ) ;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else
V_6 = (struct V_5 * ) V_4 ;
#ifdef F_47
V_6 -> V_157 = F_48 ( V_6 -> V_157 ) ;
V_6 -> V_158 = F_48 ( V_6 -> V_158 ) ;
V_6 -> V_14 . V_103 = F_48 ( V_6 -> V_14 . V_103 ) ;
V_6 -> V_14 . V_82 . V_83 =
F_48 ( V_6 -> V_14 . V_82 . V_83 ) ;
V_6 -> V_14 . V_76 = F_48 ( V_6 -> V_14 . V_76 ) ;
V_6 -> V_14 . V_99 = F_48 ( V_6 -> V_14 . V_99 ) ;
V_6 -> V_14 . V_111 =
F_48 ( V_6 -> V_14 . V_111 ) ;
V_6 -> V_14 . V_84 . V_112 =
F_48 ( V_6 -> V_14 . V_84 . V_112 ) ;
V_6 -> V_14 . V_84 . V_113 =
F_48 ( V_6 -> V_14 . V_84 . V_113 ) ;
V_6 -> V_14 . V_84 . V_85 =
F_48 ( V_6 -> V_14 . V_84 . V_85 ) ;
V_6 -> V_14 . V_84 . V_114 . V_115 =
F_48 ( V_6 -> V_14 . V_84 . V_114 .
V_115 ) ;
V_6 -> V_14 . V_84 . V_114 . V_116 =
F_48 ( V_6 -> V_14 . V_84 .
V_114 . V_116 ) ;
V_6 -> V_14 . V_84 . V_114 . V_117 =
F_48 ( V_6 -> V_14 . V_84 . V_114 . V_117 ) ;
V_6 -> V_14 . V_84 . V_114 . V_103 =
F_48 ( V_6 -> V_14 . V_84 . V_114 . V_103 ) ;
V_6 -> V_14 . V_84 . V_103 =
F_48 ( V_6 -> V_14 . V_84 . V_103 ) ;
V_6 -> V_14 . V_15 =
F_48 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_66 = F_48 ( V_6 -> V_14 . V_66 ) ;
#endif
V_156 = ! memcmp ( V_6 -> V_14 . V_51 ,
V_13 -> V_14 . V_51 , V_50 ) ;
V_6 -> V_14 . V_103 =
F_25 ( & V_6 -> V_14 ) ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( V_6 -> V_14 . V_103 > sizeof( struct V_118 ) )
goto V_159;
if ( V_6 -> V_157 > 0 ) {
if ( F_23 ( V_8 , V_121 ) == true ) {
if ( F_23 ( V_8 , V_55 ) == true ) {
if ( V_156 == true )
V_155 =
F_33 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
else {
V_154 =
F_33 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
V_154 -> V_44 = false ;
V_153 = F_57 ( V_132 ,
V_13 -> V_14 . V_51 ) ;
F_11 ( & V_132 ->
V_139 , V_151 ) ;
F_58 ( V_69 , V_153 ) ;
F_15 ( & ( V_132 ->
V_139 ) , V_151 ) ;
V_155 =
F_33 ( & V_8 ->
V_21 ,
V_6 -> V_14 .
V_51 ) ;
if ( V_155 )
V_155 -> V_44 = true ;
}
} else {
V_155 = F_33 ( & V_8 ->
V_21 ,
V_6 -> V_14 . V_51 ) ;
if ( V_155 )
V_155 -> V_44 = true ;
}
if ( V_155 == NULL ) {
if ( F_23 ( V_8 ,
V_121 ) )
V_8 -> V_12 ^=
V_121 ;
goto V_159;
}
if ( F_23 ( V_8 , V_135 ) ) {
if ( V_156 == true ) {
V_152 =
F_57 ( V_132 ,
V_6 -> V_14 . V_51 ) ;
if ( V_152 == NULL )
V_152 =
F_67 ( V_132 ,
V_6 -> V_14 . V_51 ) ;
} else
V_152 =
F_67 ( V_132 ,
V_6 -> V_14 . V_51 ) ;
if ( V_152 ) {
V_152 -> V_160 = V_6 -> V_157 ;
V_152 -> V_161 = 1 ;
V_152 -> V_162 = 5 ;
if ( V_69 -> V_73 .
V_163 == 2 ) {
V_69 -> V_73 .
V_164 =
false ;
V_69 -> V_73 .
V_165 =
false ;
V_69 -> V_73 .
V_166 =
false ;
V_152 -> V_167
= true ;
V_152 -> V_168 =
V_69 -> V_73 .
V_74 ;
memset ( ( T_2 * ) & V_152 ->
V_169 ,
0 ,
sizeof( union V_170 ) ) ;
memset ( ( T_2 * ) & V_152 ->
V_171 ,
0 ,
sizeof( union V_170 ) ) ;
memset ( ( T_2 * ) & V_152 ->
V_172 ,
0 ,
sizeof( union V_170 ) ) ;
memset ( ( T_2 * ) & V_152 ->
V_173 , 0 ,
sizeof( union V_174 ) ) ;
memset ( ( T_2 * ) & V_152 ->
V_175 , 0 ,
sizeof( union V_174 ) ) ;
}
} else {
if ( F_23 ( V_8 ,
V_121 ) )
V_8 -> V_12 ^=
V_121 ;
goto V_159;
}
}
memcpy ( & V_13 -> V_14 , & V_6 -> V_14 ,
V_6 -> V_14 . V_103 ) ;
V_13 -> V_160 = V_6 -> V_157 ;
switch ( V_6 -> V_14 . V_15 ) {
case V_176 :
V_8 -> V_12 = V_135 ;
break;
case V_177 :
V_8 -> V_12 = V_108 ;
break;
default:
V_8 -> V_12 = V_178 ;
break;
}
F_40 ( V_69 ,
( V_13 -> V_14 . V_81 ) +
sizeof( struct V_100 ) ,
( V_13 -> V_14 . V_66 ) ) ;
F_68 ( V_69 , V_13 -> V_14 . V_81 ,
V_13 -> V_14 . V_66 ) ;
if ( F_23 ( V_8 , V_135 )
== true )
F_60 ( V_69 ) ;
F_50 ( & V_8 -> V_126 ,
& V_123 ) ;
} else
goto V_159;
} else {
if ( F_23 ( V_8 , V_121 ) == true ) {
F_54 ( & V_8 -> V_126 , 1 ) ;
F_51 ( V_8 , V_121 ) ;
}
}
V_159:
F_15 ( & V_8 -> V_18 , V_34 ) ;
if ( sizeof( struct V_37 ) == 4 * sizeof( T_3 ) )
F_29 ( ( T_2 * ) V_6 ) ;
}
void F_69 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_34 ;
struct V_137 * V_138 ;
struct V_7 * V_8 = & ( V_69 -> V_9 ) ;
struct V_179 * V_180 = (struct V_179 * ) V_4 ;
if ( F_70 ( & V_69 -> V_181 , V_180 -> V_182 ) == false )
return;
V_138 = F_57 ( & V_69 -> V_133 , V_180 -> V_182 ) ;
if ( V_138 != NULL ) {
return;
}
V_138 = F_67 ( & V_69 -> V_133 , V_180 -> V_182 ) ;
if ( V_138 == NULL )
return;
V_138 -> V_161 = 0 ;
V_138 -> V_162 = F_48 ( ( T_4 ) V_180 -> V_183 ) ;
if ( V_69 -> V_73 . V_163 == 2 )
V_138 -> V_168 = V_69 -> V_73 . V_74 ;
V_138 -> V_167 = false ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( ( F_23 ( V_8 , V_119 ) == true ) ||
( F_23 ( V_8 , V_108 ) == true ) ) {
if ( V_69 -> V_133 . V_140 == 2 ) {
F_60 ( V_69 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_71 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_34 , V_151 ;
struct V_137 * V_138 ;
struct V_5 * V_88 = NULL ;
struct V_118 * V_128 = NULL ;
T_2 * V_56 = NULL ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_184 * V_185 = (struct V_184 * ) V_4 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_5 * V_134 = & V_8 -> V_13 ;
F_11 ( & V_8 -> V_18 , V_151 ) ;
if ( F_23 ( V_8 , V_135 ) == true ) {
F_62 ( V_69 ) ;
F_56 ( V_69 ) ;
}
if ( F_23 ( V_8 , V_119 |
V_108 ) ) {
V_138 = F_57 ( & V_69 -> V_133 , V_185 -> V_182 ) ;
F_11 ( & V_132 -> V_139 , V_34 ) ;
F_58 ( V_69 , V_138 ) ;
F_15 ( & V_132 -> V_139 , V_34 ) ;
if ( V_69 -> V_133 . V_140 == 1 ) {
V_88 = F_33 ( & V_8 -> V_21 ,
V_134 -> V_14 . V_51 ) ;
if ( V_88 ) {
V_88 -> V_44 = false ;
F_31 ( V_8 , V_88 ) ;
}
V_128 = & ( V_69 -> V_129 . V_130 ) ;
V_56 = V_69 -> V_129 . V_130 . V_51 ;
memcpy ( V_128 , & V_134 -> V_14 ,
F_25 ( & V_134 ->
V_14 ) ) ;
memset ( & V_128 -> V_82 , 0 ,
sizeof( struct V_23 ) ) ;
memcpy ( & V_128 -> V_82 ,
& V_8 -> V_22 ,
sizeof( struct V_23 ) ) ;
F_55 ( V_69 ) ;
F_24 ( V_56 ) ;
if ( F_23 ( V_8 , V_108 ) ) {
F_51 ( V_8 , V_108 ) ;
F_52 ( V_8 , V_119 ) ;
}
}
}
F_15 ( & V_8 -> V_18 , V_151 ) ;
}
void F_72 ( struct V_1 * V_69 , T_2 * V_4 )
{
struct V_186 * V_187 =
(struct V_186 * ) V_4 ;
V_187 -> V_188 |= ( T_2 ) ( V_69 -> V_148 . V_189 + 0x80 ) ;
F_73 ( V_69 , V_187 ) ;
}
void F_74 ( struct V_1 * V_69 , T_2 * V_4 )
{
struct V_190 * V_191 =
(struct V_190 * ) V_4 ;
struct V_137 * V_138 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_192 * V_193 = NULL ;
F_75 ( V_194 L_2 ,
V_195 , V_191 -> V_51 ,
V_191 -> V_196 , V_191 -> V_197 ) ;
V_138 = F_57 ( V_132 , V_191 -> V_51 ) ;
if ( V_138 ) {
V_193 =
& V_138 -> V_198 [ V_191 -> V_197 ] ;
V_193 -> V_199 = 0xffff ;
}
}
void F_76 ( struct V_1 * V_69 , T_2 * V_4 )
{
if ( V_69 -> V_73 . V_200 == false )
V_69 -> V_73 . V_200 = true ;
}
void F_77 ( struct V_1 * V_69 )
{
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_201 * V_202 = & V_8 -> V_29 ;
struct V_203 * V_204 = & V_69 -> V_129 ;
T_6 V_205 ;
T_4 V_206 ;
V_205 = ( V_69 -> V_207 . V_208 ) -
( V_202 -> V_31 ) ;
V_206 = ( V_69 -> V_92 . V_209 ) -
( V_202 -> V_30 ) ;
V_202 -> V_31 = V_69 -> V_207 . V_208 ;
V_202 -> V_30 = V_69 -> V_92 . V_209 ;
if ( ( V_205 > V_204 -> V_210 ) ||
( V_206 > V_204 -> V_210 ) )
V_202 -> V_32 = true ;
else
V_202 -> V_32 = false ;
}
void F_78 ( struct V_1 * V_69 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
if ( V_69 -> V_53 || V_69 -> V_54 )
return;
F_11 ( & V_8 -> V_18 , V_34 ) ;
F_51 ( V_8 , V_121 ) ;
V_8 -> V_125 = false ;
if ( F_23 ( V_8 , V_55 ) == true ) {
F_63 ( V_69 ) ;
F_51 ( V_8 , V_55 ) ;
}
if ( V_69 -> V_148 . V_149 != V_69 -> V_129 . V_144 ) {
F_65 ( V_69 , V_69 -> V_129 . V_144 ,
V_69 -> V_129 . V_150 ) ;
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_79 ( struct V_1 * V_69 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
F_51 ( V_8 , V_122 ) ;
V_8 -> V_125 = false ;
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_80 ( struct V_1 * V_69 )
{
if ( V_69 -> V_53 || V_69 -> V_54 )
return;
if ( V_69 -> V_148 . V_149 != V_69 -> V_129 . V_144 )
F_65 ( V_69 , V_69 -> V_129 . V_144 ,
V_69 -> V_129 . V_150 ) ;
}
void F_81 ( struct V_1 * V_69 )
{
F_82 ( V_69 ) ;
}
int F_53 ( struct V_7 * V_8 )
{
struct V_37 * V_48 ;
unsigned char * V_211 , * V_212 ;
struct V_1 * V_69 ;
struct V_35 * V_28 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_213 = NULL ;
V_69 = (struct V_1 * ) V_8 -> V_10 ;
V_28 = & V_8 -> V_21 ;
V_48 = F_18 ( V_28 ) ;
V_8 -> V_11 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_21 ( V_48 , V_8 -> V_11 ) == true ) {
if ( ( V_8 -> V_214 == true ) &&
( V_213 != NULL ) ) {
V_6 = V_213 ;
goto V_215;
}
return V_25 ;
}
V_6 = F_13 ( V_8 -> V_11 ,
struct V_5 , V_27 ) ;
if ( V_6 == NULL )
return V_25 ;
V_8 -> V_11 = F_12 ( V_8 -> V_11 ) ;
if ( V_8 -> V_216 == true ) {
V_211 = V_6 -> V_14 . V_51 ;
V_212 = V_8 -> V_217 ;
if ( ! memcmp ( V_211 , V_212 , V_50 ) ) {
if ( F_23 ( V_8 , V_55 ) ) {
if ( F_35 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_51 ( V_8 ,
V_121 ) ;
F_60 ( V_69 ) ;
return 2 ;
}
F_83 ( V_69 ) ;
F_62 ( V_69 ) ;
F_56 ( V_69 ) ;
}
goto V_215;
}
} else if ( V_8 -> V_22 . V_83 == 0 )
goto V_215;
V_211 = V_6 -> V_14 . V_82 . V_82 ;
V_212 = V_8 -> V_22 . V_82 ;
if ( ( V_6 -> V_14 . V_82 . V_83 ==
V_8 -> V_22 . V_83 ) &&
( ! memcmp ( V_211 , V_212 ,
V_8 -> V_22 . V_83 ) ) ) {
if ( V_8 -> V_214 == true ) {
if ( V_213 ) {
if ( V_6 -> V_14 . V_99 >
V_213 -> V_14 . V_99 )
V_213 = V_6 ;
} else
V_213 = V_6 ;
} else if ( F_43 ( V_69 , V_6 ) ) {
if ( F_23 ( V_8 , V_55 ) ) {
F_83 ( V_69 ) ;
F_56 ( V_69 ) ;
}
goto V_215;
}
}
}
return V_25 ;
V_215:
return F_84 ( V_69 , V_6 ) ;
}
T_1 F_85 ( struct V_1 * V_69 ,
struct V_71 * V_72 )
{
struct V_218 * V_219 = & V_69 -> V_220 ;
struct V_221 * V_222 ;
struct V_223 * V_224 ;
T_1 V_70 = V_33 ;
V_222 = (struct V_221 * ) F_5 ( sizeof( struct V_221 ) ) ;
if ( V_222 == NULL )
return V_25 ;
V_224 = (struct V_223 * ) F_5 (
sizeof( struct V_223 ) ) ;
if ( V_224 == NULL ) {
F_29 ( ( unsigned char * ) V_222 ) ;
return V_25 ;
}
memset ( V_224 , 0 , sizeof( struct V_223 ) ) ;
V_224 -> V_225 = ( T_2 ) V_72 -> V_163 ;
V_222 -> V_226 = V_227 ;
V_222 -> V_228 = ( unsigned char * ) V_224 ;
V_222 -> V_229 = sizeof( struct V_223 ) ;
V_222 -> V_230 = NULL ;
V_222 -> V_231 = 0 ;
F_6 ( & V_222 -> V_27 ) ;
F_86 ( V_219 , V_222 ) ;
return V_70 ;
}
T_1 F_87 ( struct V_1 * V_69 ,
struct V_71 * V_72 ,
T_1 V_232 )
{
struct V_218 * V_219 = & V_69 -> V_220 ;
struct V_221 * V_222 ;
struct V_233 * V_234 ;
T_2 V_235 ;
V_222 = (struct V_221 * ) F_5 ( sizeof( struct V_221 ) ) ;
if ( V_222 == NULL )
return V_25 ;
V_234 = (struct V_233 * ) F_5 ( sizeof( struct V_233 ) ) ;
if ( V_234 == NULL ) {
F_29 ( ( unsigned char * ) V_222 ) ;
return V_25 ;
}
memset ( V_234 , 0 , sizeof( struct V_233 ) ) ;
if ( V_72 -> V_163 == 2 ) {
V_234 -> V_236 =
( T_2 ) V_72 -> V_237 ;
} else {
V_234 -> V_236 =
( T_2 ) V_72 -> V_74 ;
}
V_234 -> V_232 = ( T_2 ) V_232 ;
switch ( V_234 -> V_236 ) {
case V_238 :
V_235 = 5 ;
memcpy ( V_234 -> V_239 ,
V_72 -> V_240 [ V_232 ] . V_241 , V_235 ) ;
break;
case V_242 :
V_235 = 13 ;
memcpy ( V_234 -> V_239 ,
V_72 -> V_240 [ V_232 ] . V_241 , V_235 ) ;
break;
case V_243 :
if ( V_232 < 1 || V_232 > 2 )
return V_25 ;
V_235 = 16 ;
memcpy ( V_234 -> V_239 ,
& V_72 -> V_244 [ V_232 - 1 ] , V_235 ) ;
V_234 -> V_245 = 1 ;
break;
case V_246 :
if ( V_232 < 1 || V_232 > 2 )
return V_25 ;
V_235 = 16 ;
memcpy ( V_234 -> V_239 ,
& V_72 -> V_244 [ V_232 - 1 ] , V_235 ) ;
V_234 -> V_245 = 1 ;
break;
default:
return V_25 ;
}
V_222 -> V_226 = V_247 ;
V_222 -> V_228 = ( T_2 * ) V_234 ;
V_222 -> V_229 = ( sizeof( struct V_233 ) ) ;
V_222 -> V_230 = NULL ;
V_222 -> V_231 = 0 ;
F_6 ( & V_222 -> V_27 ) ;
F_86 ( V_219 , V_222 ) ;
return V_33 ;
}
int F_88 ( struct V_1 * V_69 , T_2 * V_248 , T_2 * V_249 ,
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
static int F_89 ( struct V_1 * V_254 , T_2 * V_255 )
{
struct V_71 * V_72 = & V_254 -> V_73 ;
int V_3 = 0 ;
do {
if ( V_72 -> V_256 [ V_3 ] . V_257 &&
( ! memcmp ( V_72 -> V_256 [ V_3 ] . V_258 ,
V_255 , V_50 ) ) )
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
T_1 F_90 ( struct V_1 * V_69 , T_2 * V_248 ,
T_2 * V_249 , T_4 V_250 )
{
T_2 V_260 = 0 , V_261 , V_262 ;
T_2 V_263 [ 255 ] , V_264 [ 4 ] , V_265 [ 255 ] ;
T_2 V_266 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_252 , V_267 , V_268 ;
int V_269 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_71 * V_72 = & V_69 -> V_73 ;
T_4 V_270 = V_72 -> V_271 ;
T_4 V_272 = V_72 -> V_273 ;
if ( ( V_270 == V_274 ) ||
( V_270 == V_275 ) ) {
V_260 = V_276 ;
V_264 [ 0 ] = 0x0 ;
V_264 [ 1 ] = 0x50 ;
V_264 [ 2 ] = 0xf2 ;
}
if ( ( V_270 == V_277 ) ||
( V_270 == V_278 ) ) {
V_260 = V_279 ;
V_264 [ 0 ] = 0x0 ;
V_264 [ 1 ] = 0x0f ;
V_264 [ 2 ] = 0xac ;
}
switch ( V_272 ) {
case V_280 :
case V_281 :
V_261 = V_238 ;
V_264 [ 3 ] = 0x1 ;
break;
case V_282 :
case V_283 :
V_261 = V_243 ;
V_264 [ 3 ] = 0x2 ;
break;
case V_284 :
case V_285 :
V_261 = V_246 ;
V_264 [ 3 ] = 0x4 ;
break;
default:
V_261 = V_75 ;
break;
}
V_267 = 12 ;
V_262 = false ;
while ( V_267 < V_250 ) {
if ( V_248 [ V_267 ] == V_260 ) {
if ( ( V_260 == V_276 ) &&
( ! memcmp ( & V_248 [ V_267 + 2 ] , & V_266 [ 0 ] , 4 ) ) ) {
memcpy ( & V_263 [ 0 ] , & V_248 [ V_267 ] ,
V_248 [ V_267 + 1 ] + 2 ) ;
V_262 = true ;
break;
}
if ( V_260 == V_279 ) {
memcpy ( & V_263 [ 0 ] , & V_248 [ V_267 ] ,
V_248 [ V_267 + 1 ] + 2 ) ;
V_262 = true ;
break;
}
if ( ( ( V_260 == V_276 ) &&
( ! memcmp ( & V_248 [ V_267 + 2 ] , & V_266 [ 0 ] , 4 ) ) ) ||
( V_260 == V_279 ) )
memcpy ( & V_265 [ 0 ] , & V_248 [ V_267 ] ,
V_248 [ V_267 + 1 ] + 2 ) ;
}
V_267 += V_248 [ V_267 + 1 ] + 2 ;
}
if ( V_262 == true ) {
if ( V_263 [ 0 ] == V_276 ) {
while ( true ) {
if ( memcmp ( & V_263 [ 2 ] , & V_266 [ 0 ] , 4 ) ) {
V_262 = false ;
break;
}
if ( ( V_263 [ 6 ] != 0x01 ) || ( V_263 [ 7 ] != 0x0 ) ) {
V_262 = false ;
break;
}
if ( ! memcmp ( & V_263 [ 8 ] , & V_266 [ 0 ] , 3 ) ) {
switch ( V_263 [ 11 ] ) {
case 0x0 :
V_72 -> V_237 =
V_75 ;
break;
case 0x1 :
V_72 -> V_237 =
V_238 ;
break;
case 0x2 :
V_72 -> V_237 =
V_243 ;
break;
case 0x3 :
case 0x4 :
V_72 -> V_237 =
V_246 ;
break;
case 0x5 :
V_72 -> V_237 =
V_242 ;
break;
}
} else {
V_262 = false ;
break;
}
if ( V_263 [ 12 ] == 0x01 ) {
if ( memcmp ( & V_263 [ 14 ] ,
& V_264 [ 0 ] , 4 ) ) {
V_262 = false ;
break;
}
} else {
V_267 = V_263 [ 12 ] ;
V_268 = ( V_267 - 1 ) * 4 ;
V_263 [ 12 ] = 0x01 ;
memcpy ( & V_263 [ 14 ] , & V_264 [ 0 ] , 4 ) ;
memcpy ( & V_263 [ 18 ] ,
& V_263 [ 18 + V_268 ] ,
V_263 [ 1 ] - 18 + 2 -
V_268 ) ;
V_263 [ 1 ] = V_263 [ 1 ] - V_268 ;
}
break;
}
}
if ( V_260 == V_279 ) {
while ( true ) {
if ( ( V_263 [ 2 ] != 0x01 ) || ( V_263 [ 3 ] != 0x0 ) ) {
V_262 = false ;
break;
}
if ( ! memcmp ( & V_263 [ 4 ] , & V_264 [ 0 ] , 3 ) ) {
switch ( V_263 [ 7 ] ) {
case 0x1 :
V_72 -> V_237 =
V_238 ;
break;
case 0x2 :
V_72 -> V_237 =
V_243 ;
break;
case 0x4 :
V_72 -> V_237 =
V_246 ;
break;
case 0x5 :
V_72 -> V_237 =
V_242 ;
break;
default:
V_72 -> V_237 =
V_75 ;
break;
}
} else {
V_262 = false ;
break;
}
if ( V_263 [ 8 ] == 0x01 ) {
if ( memcmp ( & V_263 [ 10 ] ,
& V_264 [ 0 ] , 4 ) ) {
V_262 = false ;
break;
}
} else {
V_267 = V_263 [ 8 ] ;
V_268 = ( V_267 - 1 ) * 4 ;
V_263 [ 8 ] = 0x01 ;
memcpy ( & V_263 [ 10 ] , & V_264 [ 0 ] , 4 ) ;
memcpy ( & V_263 [ 14 ] ,
& V_263 [ 14 + V_268 ] ,
( V_263 [ 1 ] - 14 + 2 -
V_268 ) ) ;
V_263 [ 1 ] = V_263 [ 1 ] - V_268 ;
}
break;
}
}
}
if ( ( V_260 == V_276 ) || ( V_260 == V_279 ) ) {
memcpy ( V_249 , V_248 , 12 ) ;
V_252 = 12 ;
if ( V_262 == true ) {
memcpy ( & V_249 [ V_252 ] , & V_263 [ 0 ] , V_263 [ 1 ] + 2 ) ;
V_252 += V_263 [ 1 ] + 2 ;
if ( V_260 == V_279 ) {
V_249 [ V_252 - 1 ] = 0 ;
V_249 [ V_252 - 2 ] = 0 ;
}
F_91 ( V_69 , V_260 , V_263 ) ;
}
} else {
memcpy ( V_249 , V_248 , 12 ) ;
V_252 = 12 ;
if ( V_72 -> V_107 == true ) {
memcpy ( V_249 + V_252 , V_72 -> V_104 ,
V_72 -> V_286 ) ;
V_252 += V_72 -> V_286 ;
}
}
V_269 = F_89 ( V_69 , V_8 -> V_217 ) ;
if ( V_269 < 0 )
return V_252 ;
else {
if ( V_260 == V_279 ) {
V_249 [ V_252 ] = 1 ;
V_252 ++ ;
V_249 [ V_252 ] = 0 ;
V_252 ++ ;
memcpy ( & V_249 [ V_252 ] ,
& V_72 -> V_256 [ V_269 ] . V_287 , 16 ) ;
V_252 += 16 ;
V_249 [ 13 ] += 18 ;
}
}
return V_252 ;
}
void F_92 ( struct V_1 * V_69 )
{
struct V_203 * V_204 = & V_69 -> V_129 ;
struct V_288 * V_289 = & V_69 -> V_290 ;
struct V_118 * V_128 = & V_204 -> V_130 ;
T_2 * V_291 = F_93 ( V_289 ) ;
memcpy ( V_128 -> V_51 , V_291 , V_50 ) ;
memcpy ( & V_128 -> V_82 , & V_204 -> V_292 ,
sizeof( struct V_23 ) ) ;
V_128 -> V_84 . V_103 =
sizeof( struct V_63 ) ;
V_128 -> V_84 . V_113 = 100 ;
V_128 -> V_84 . V_114 . V_103 = 0 ;
V_128 -> V_84 . V_114 . V_116 = 0 ;
V_128 -> V_84 . V_114 . V_117 = 0 ;
V_128 -> V_84 . V_114 . V_115 = 0 ;
}
void F_55 ( struct V_1 * V_69 )
{
int V_293 = 0 ;
struct V_203 * V_204 = & V_69 -> V_129 ;
struct V_118 * V_128 = & V_204 -> V_130 ;
struct V_71 * V_72 = & V_69 -> V_73 ;
struct V_5 * V_13 = & V_69 -> V_9 . V_13 ;
V_128 -> V_76 = F_94 ( V_72 -> V_74
> 0 ? 1 : 0 ) ;
V_128 -> V_99 = 0 ;
switch ( V_204 -> V_294 ) {
case V_295 :
V_128 -> V_111 = F_94 ( V_296 ) ;
break;
case V_297 :
case V_298 :
V_128 -> V_111 = F_94 ( V_299 ) ;
break;
case V_300 :
V_128 -> V_111 = F_94 ( V_301 ) ;
break;
default:
break;
}
V_128 -> V_84 . V_85 = F_94 (
V_204 -> V_302 ) ;
if ( V_13 -> V_14 . V_15 == V_177 )
V_128 -> V_84 . V_112 = F_94 ( 3 ) ;
V_128 -> V_15 = F_94 (
V_13 -> V_14 . V_15 ) ;
V_293 = F_95 ( V_204 ) ;
V_128 -> V_66 = V_293 ;
V_128 -> V_103 = F_25 (
(struct V_58 * ) V_128 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_303 * V_304 = & V_8 -> V_305 ;
V_304 -> V_306 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_304 -> V_307 [ V_3 ] = false ;
if ( V_304 -> V_308 ) {
F_97 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_97 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_98 ( struct V_1 * V_2 , T_2 * V_248 ,
T_2 * V_249 , T_4 V_250 , T_4 * V_309 )
{
T_3 V_310 , V_311 ;
unsigned char * V_312 , * V_313 ;
struct V_314 V_315 ;
unsigned char V_316 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_317 * V_318 = & V_8 -> V_319 ;
struct V_303 * V_304 = & V_8 -> V_305 ;
V_304 -> V_308 = 0 ;
V_312 = F_99 ( V_248 + 12 , V_320 , & V_310 , V_250 - 12 ) ;
if ( V_312 && ( V_310 > 0 ) ) {
if ( V_318 -> V_161 == 0 ) {
V_311 = * V_309 ;
V_313 = F_100 ( V_249 + V_311 ,
V_321 ,
V_322 ,
V_316 , V_309 ) ;
V_318 -> V_161 = 1 ;
}
V_311 = * V_309 ;
memset ( & V_315 , 0 , sizeof( struct V_314 ) ) ;
V_315 . V_323 = V_324 |
V_325 |
V_326 |
V_327 |
V_328 |
V_329 ;
V_315 . V_330 = ( V_331 &
0x03 ) | ( V_332 & 0x00 ) ;
V_313 = F_100 ( V_249 + V_311 , V_320 ,
sizeof( struct V_314 ) ,
( unsigned char * ) & V_315 , V_309 ) ;
V_304 -> V_308 = 1 ;
}
return V_304 -> V_308 ;
}
static void F_68 ( struct V_1 * V_2 , T_2 * V_333 , T_4 V_334 )
{
T_2 * V_312 , V_335 ;
int V_3 , V_110 ;
struct V_137 * V_336 , * V_138 ;
struct V_314 * V_337 ;
struct V_338 * V_339 ;
struct V_192 * V_340 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_303 * V_304 = & V_8 -> V_305 ;
struct V_203 * V_204 = & V_2 -> V_129 ;
struct V_5 * V_341 = & ( V_8 -> V_13 ) ;
if ( ! V_304 -> V_308 )
return;
if ( ( V_304 -> V_306 == false ) &&
( V_204 -> V_306 == 1 ) )
V_304 -> V_306 = true ;
V_110 = 0 ;
V_312 = F_99 ( V_333 + sizeof( struct V_100 ) ,
V_320 ,
& V_110 , V_334 -
sizeof( struct V_100 ) ) ;
if ( V_312 && V_110 > 0 ) {
V_337 = (struct V_314 * ) ( V_312 + 2 ) ;
V_335 = ( V_337 -> V_330 &
V_331 ) ;
V_335 = 1 << ( V_335 + 3 ) ;
V_304 -> V_342 = V_335 ;
}
V_336 = F_101 ( V_2 ) ;
if ( V_336 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_340 = & V_336 -> V_198 [ V_3 ] ;
V_340 -> V_199 = 0xffff ;
V_340 -> V_343 = 0xffff ;
}
}
V_138 = F_57 ( & V_2 -> V_133 ,
V_341 -> V_14 . V_51 ) ;
if ( V_138 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_340 = & V_138 -> V_198 [ V_3 ] ;
V_340 -> V_199 = 0xffff ;
V_340 -> V_343 = 0xffff ;
}
}
V_110 = 0 ;
V_312 = F_99 ( V_333 + sizeof( struct V_100 ) ,
V_344 , & V_110 ,
V_334 - sizeof( struct V_100 ) ) ;
if ( V_312 && V_110 > 0 )
V_339 = (struct V_338 * ) ( V_312 + 2 ) ;
}
void F_102 ( struct V_1 * V_2 , int V_345 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_303 * V_304 = & V_8 -> V_305 ;
if ( ( V_304 -> V_308 == 1 ) && ( V_304 -> V_306 == true ) ) {
if ( V_304 -> V_307 [ V_345 ] == false ) {
F_103 ( V_2 , ( T_2 ) V_345 ) ;
V_304 -> V_307 [ V_345 ] = true ;
}
}
}
