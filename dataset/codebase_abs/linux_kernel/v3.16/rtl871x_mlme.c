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
if ( F_10 ( V_37 ) == true )
return NULL ;
F_11 ( & V_37 -> V_18 , V_35 ) ;
V_39 = F_12 ( & ( V_37 -> V_29 ) ) ;
V_6 = F_13 ( V_39 , struct V_5 , V_28 ) ;
F_14 ( & V_6 -> V_28 ) ;
V_6 -> V_40 = V_41 ;
V_8 -> V_42 ++ ;
F_15 ( & V_37 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_43 , V_44 ;
unsigned long V_35 ;
struct V_36 * V_37 = & ( V_8 -> V_20 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_45 == true )
return;
V_43 = V_41 ;
V_44 = ( V_43 - ( T_3 ) V_6 -> V_40 ) / V_46 ;
if ( V_44 < V_47 )
return;
F_11 ( & V_37 -> V_18 , V_35 ) ;
F_14 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , & V_37 -> V_29 ) ;
V_8 -> V_42 -- ;
F_15 ( & V_37 -> V_18 , V_35 ) ;
}
static void F_17 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_36 * V_37 = & V_8 -> V_20 ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_45 == true )
return;
F_14 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , F_18 ( V_37 ) ) ;
V_8 -> V_42 -- ;
}
static struct V_5 * F_19 ( struct V_36 * V_21 ,
T_2 * V_48 )
{
unsigned long V_35 ;
struct V_38 * V_49 , * V_39 ;
struct V_5 * V_6 = NULL ;
if ( F_20 ( V_48 ) )
return NULL ;
F_11 ( & V_21 -> V_18 , V_35 ) ;
V_49 = F_18 ( V_21 ) ;
V_39 = F_12 ( V_49 ) ;
while ( V_39 != V_49 ) {
V_6 = F_13 ( V_39 , struct V_5 , V_28 ) ;
V_39 = F_12 ( V_39 ) ;
if ( ! memcmp ( V_48 , V_6 -> V_14 . V_50 , V_51 ) )
break;
}
F_15 ( & V_21 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_38 * V_49 , * V_39 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_36 * V_21 = & V_8 -> V_21 ;
F_11 ( & V_21 -> V_18 , V_35 ) ;
V_49 = F_18 ( V_21 ) ;
V_39 = F_12 ( V_49 ) ;
while ( F_22 ( V_49 , V_39 ) == false ) {
V_6 = F_13 ( V_39 , struct V_5 , V_28 ) ;
V_39 = F_12 ( V_39 ) ;
F_16 ( V_8 , V_6 ) ;
}
F_15 ( & V_21 -> V_18 , V_35 ) ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
T_1 V_52 ;
if ( V_2 -> V_53 || V_2 -> V_54 ||
( F_24 ( & V_2 -> V_9 , V_55 ) == false ) ) {
V_52 = false ;
} else
V_52 = true ;
return V_52 ;
}
void F_25 ( T_2 * V_56 )
{
T_3 V_57 = V_41 ;
V_56 [ 0 ] = 0x02 ;
V_56 [ 1 ] = 0x11 ;
V_56 [ 2 ] = 0x87 ;
V_56 [ 3 ] = ( T_2 ) ( V_57 & 0xff ) ;
V_56 [ 4 ] = ( T_2 ) ( ( V_57 >> 8 ) & 0xff ) ;
V_56 [ 5 ] = ( T_2 ) ( ( V_57 >> 16 ) & 0xff ) ;
}
T_4 F_26 ( struct V_58 * V_59 )
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
T_2 * F_27 ( T_2 * V_67 )
{
return V_67 + 8 + 2 ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
F_30 ( V_8 -> V_27 ) ;
}
static struct V_5 * F_31 ( struct V_7 * V_8 )
{
return F_9 ( V_8 ) ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_17 ( V_8 , V_6 ) ;
}
void F_33 ( struct V_1 * V_68 )
{
F_21 ( V_68 ) ;
}
static struct V_5 * F_34 ( struct V_36 * V_21 ,
T_2 * V_48 )
{
struct V_5 * V_6 = F_19 ( V_21 ,
V_48 ) ;
return V_6 ;
}
int F_35 ( struct V_1 * V_69 , struct V_5 * V_6 )
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
static int F_36 ( struct V_58 * V_77 ,
struct V_58 * V_78 )
{
T_5 V_79 , V_80 ;
memcpy ( ( T_2 * ) & V_79 , F_27 ( V_77 -> V_81 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_80 , F_27 ( V_78 -> V_81 ) , 2 ) ;
return ( V_77 -> V_82 . V_83 == V_78 -> V_82 . V_83 ) &&
( V_77 -> V_84 . V_85 ==
V_78 -> V_84 . V_85 ) &&
( ( ! memcmp ( V_77 -> V_50 , V_78 -> V_50 ,
V_51 ) ) ) &&
( ( ! memcmp ( V_77 -> V_82 . V_82 ,
V_78 -> V_82 . V_82 ,
V_77 -> V_82 . V_83 ) ) ) &&
( ( V_79 & V_86 ) ==
( V_80 & V_86 ) ) &&
( ( V_79 & V_87 ) ==
( V_80 & V_87 ) ) ;
}
struct V_5 * F_37 (
struct V_36 * V_21 )
{
struct V_38 * V_39 , * V_49 ;
struct V_5 * V_88 = NULL ;
struct V_5 * V_89 = NULL ;
V_49 = F_18 ( V_21 ) ;
V_39 = F_12 ( V_49 ) ;
while ( 1 ) {
if ( F_22 ( V_49 , V_39 ) == true )
break;
V_88 = F_13 ( V_39 , struct V_5 , V_28 ) ;
if ( V_88 -> V_45 != true ) {
if ( V_89 == NULL ||
F_38 ( ( unsigned long ) V_89 -> V_40 ,
( unsigned long ) V_88 -> V_40 ) )
V_89 = V_88 ;
}
V_39 = F_12 ( V_39 ) ;
}
return V_89 ;
}
static void F_39 ( struct V_58 * V_78 ,
struct V_58 * V_77 ,
struct V_1 * V_2 )
{
T_3 V_90 = 0 , V_91 ;
if ( F_24 ( & V_2 -> V_9 , V_55 ) &&
F_36 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_77 ) ) {
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
memcpy ( ( T_2 * ) V_78 , ( T_2 * ) V_77 , F_26 ( V_77 ) ) ;
}
static void F_40 ( struct V_1 * V_69 ,
struct V_58 * V_6 )
{
struct V_7 * V_8 = & V_69 -> V_9 ;
if ( F_36 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_39 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_69 ) ;
F_41 ( V_69 ,
( V_8 -> V_13 . V_14 . V_81 ) +
sizeof( struct V_100 ) ,
V_8 -> V_13 . V_14 . V_66 ) ;
}
}
static void F_42 ( struct V_1 * V_69 ,
struct V_58 * V_101 )
{
struct V_38 * V_39 , * V_49 ;
T_3 V_102 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_36 * V_29 = & V_8 -> V_21 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_89 = NULL ;
V_49 = F_18 ( V_29 ) ;
V_39 = F_12 ( V_49 ) ;
while ( 1 ) {
if ( F_22 ( V_49 , V_39 ) == true )
break;
V_6 = F_13 ( V_39 , struct V_5 , V_28 ) ;
if ( F_36 ( & V_6 -> V_14 , V_101 ) )
break;
if ( ( V_89 == ( (struct V_5 * ) 0 ) ) ||
F_38 ( ( unsigned long ) V_89 -> V_40 ,
( unsigned long ) V_6 -> V_40 ) )
V_89 = V_6 ;
V_39 = F_12 ( V_39 ) ;
}
if ( F_22 ( V_49 , V_39 ) == true ) {
if ( F_10 ( & V_8 -> V_20 ) == true ) {
V_6 = V_89 ;
V_101 -> V_99 = ( V_6 -> V_14 . V_99 +
V_101 -> V_99 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_101 ,
F_26 ( V_101 ) ) ;
V_6 -> V_40 = V_41 ;
} else {
V_6 = F_31 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_102 = F_26 ( V_101 ) ;
V_101 -> V_103 = V_102 ;
memcpy ( & V_6 -> V_14 , V_101 , V_102 ) ;
F_7 ( & V_6 -> V_28 , & V_29 -> V_29 ) ;
}
} else {
F_39 ( & V_6 -> V_14 , V_101 , V_69 ) ;
V_6 -> V_40 = V_41 ;
}
}
static void F_43 ( struct V_1 * V_69 ,
struct V_58 * V_6 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_69 ) -> V_9 ) ;
struct V_36 * V_29 = & V_8 -> V_21 ;
F_11 ( & V_29 -> V_18 , V_35 ) ;
F_40 ( V_69 , V_6 ) ;
F_42 ( V_69 , V_6 ) ;
F_15 ( & V_29 -> V_18 , V_35 ) ;
}
static int F_44 ( struct V_1 * V_69 ,
struct V_5 * V_6 )
{
T_2 V_104 [ 512 ] ;
T_4 V_105 ;
int V_106 = true ;
struct V_71 * V_72 = & V_69 -> V_73 ;
if ( V_72 -> V_107 == true ) {
if ( F_45 ( V_6 -> V_14 . V_81 ,
V_6 -> V_14 . V_66 , V_104 ,
& V_105 ) == true )
return true ;
else
return false ;
}
if ( ( V_72 -> V_74 != V_75 ) &&
( V_6 -> V_14 . V_76 == 0 ) )
V_106 = false ;
if ( F_24 ( & V_69 -> V_9 , V_108 ) == true ) {
if ( V_6 -> V_14 . V_15 !=
V_69 -> V_9 . V_13 . V_14 .
V_15 )
V_106 = false ;
}
return V_106 ;
}
void F_46 ( struct V_1 * V_69 , T_2 * V_4 )
{
}
void F_47 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_109 ;
T_3 V_110 ;
struct V_58 * V_6 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
V_6 = (struct V_58 * ) V_4 ;
#ifdef F_48
V_6 -> V_103 = F_49 ( V_6 -> V_103 ) ;
V_6 -> V_82 . V_83 = F_49 ( V_6 -> V_82 . V_83 ) ;
V_6 -> V_76 = F_49 ( V_6 -> V_76 ) ;
V_6 -> V_99 = F_49 ( V_6 -> V_99 ) ;
V_6 -> V_111 = F_49 ( V_6 -> V_111 ) ;
V_6 -> V_84 . V_112 =
F_49 ( V_6 -> V_84 . V_112 ) ;
V_6 -> V_84 . V_113 =
F_49 ( V_6 -> V_84 . V_113 ) ;
V_6 -> V_84 . V_85 =
F_49 ( V_6 -> V_84 . V_85 ) ;
V_6 -> V_84 . V_114 . V_115 =
F_49 ( V_6 -> V_84 . V_114 . V_115 ) ;
V_6 -> V_84 . V_114 . V_116 =
F_49 ( V_6 -> V_84 . V_114 . V_116 ) ;
V_6 -> V_84 . V_114 . V_117 =
F_49 ( V_6 -> V_84 . V_114 . V_117 ) ;
V_6 -> V_84 . V_114 . V_103 =
F_49 ( V_6 -> V_84 . V_114 . V_103 ) ;
V_6 -> V_84 . V_103 =
F_49 ( V_6 -> V_84 . V_103 ) ;
V_6 -> V_15 =
F_49 ( V_6 -> V_15 ) ;
V_6 -> V_66 = F_49 ( V_6 -> V_66 ) ;
#endif
V_110 = F_26 ( V_6 ) ;
if ( V_110 > sizeof( struct V_118 ) )
return;
F_11 ( & V_8 -> V_19 , V_109 ) ;
if ( F_24 ( V_8 , V_119 ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_50 ) ,
V_6 -> V_50 , V_51 ) ) {
struct V_5 * V_120 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_81 ,
V_6 -> V_81 , 8 ) ;
V_120 = F_34 (
& V_8 -> V_21 ,
V_6 -> V_50 ) ;
if ( V_120 ) {
memcpy ( V_120 -> V_14 . V_81 ,
V_6 -> V_81 , 8 ) ;
goto exit;
}
}
}
if ( F_24 ( V_8 , V_121 ) == false ) {
if ( V_6 -> V_82 . V_82 [ 0 ] != 0 )
F_43 ( V_69 , V_6 ) ;
else {
V_6 -> V_82 . V_83 = 8 ;
memcpy ( V_6 -> V_82 . V_82 , L_1 , 8 ) ;
F_43 ( V_69 , V_6 ) ;
}
}
exit:
F_15 ( & V_8 -> V_19 , V_109 ) ;
}
void F_50 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( F_24 ( V_8 , V_122 ) == true ) {
T_2 V_123 ;
F_51 ( & V_8 -> V_124 , & V_123 ) ;
F_52 ( V_8 , V_122 ) ;
}
if ( V_8 -> V_125 == true ) {
if ( ( F_24 ( V_8 , V_108 ) == true ) ) {
if ( F_24 ( V_8 , V_55 ) == false ) {
F_53 ( V_8 , V_121 ) ;
if ( F_54 ( V_8 )
== V_34 )
F_55 ( & V_8 -> V_126 ,
V_127 ) ;
else {
struct V_118 * V_128 =
& ( V_69 -> V_129 . V_130 ) ;
T_2 * V_56 =
V_69 -> V_129 .
V_130 . V_50 ;
V_8 -> V_12 ^= V_122 ;
memcpy ( & V_128 -> V_82 ,
& V_8 -> V_22 ,
sizeof( struct
V_23 ) ) ;
F_56
( V_69 ) ;
F_25 ( V_56 ) ;
V_8 -> V_12 =
V_119 ;
V_8 -> V_125 = false ;
}
}
} else {
V_8 -> V_125 = false ;
F_53 ( V_8 , V_121 ) ;
if ( F_54 ( V_8 ) ==
V_34 )
F_55 ( & V_8 -> V_126 ,
V_127 ) ;
else
F_52 ( V_8 , V_121 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_35 ) ;
}
void F_57 ( struct V_1 * V_69 )
{
unsigned long V_35 ;
struct V_5 * V_88 = NULL ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_5 * V_134 = & V_8 -> V_13 ;
V_88 = F_34 ( & V_8 -> V_21 ,
V_134 -> V_14 . V_50 ) ;
if ( F_24 ( V_8 , V_135 | V_136 ) ) {
struct V_137 * V_138 ;
V_138 = F_58 ( & V_69 -> V_133 ,
V_134 -> V_14 . V_50 ) ;
F_11 ( & V_132 -> V_139 , V_35 ) ;
F_59 ( V_69 , V_138 ) ;
F_15 ( & V_132 -> V_139 , V_35 ) ;
}
if ( F_24 ( V_8 ,
V_108 | V_119 | V_136 ) )
F_60 ( V_69 ) ;
if ( V_88 )
V_88 -> V_45 = false ;
if ( ( ( F_24 ( V_8 , V_119 ) ) &&
( V_69 -> V_133 . V_140 == 1 ) ) )
F_32 ( V_8 , V_88 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_125 = false ;
F_53 ( V_8 , V_55 ) ;
V_2 -> V_141 . V_142 ( V_2 , V_143 ) ;
F_62 ( V_2 ) ;
if ( V_2 -> V_129 . V_144 > V_145 )
F_55 ( & V_8 -> V_146 , 60000 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( F_24 ( V_8 , V_55 ) == true ) {
F_52 ( V_8 , V_55 ) ;
V_2 -> V_141 . V_142 ( V_2 , V_147 ) ;
F_64 ( V_2 ) ;
}
if ( V_2 -> V_148 . V_149 !=
V_2 -> V_129 . V_144 ) {
F_65 ( & V_8 -> V_146 ) ;
F_66 ( V_2 , V_2 -> V_129 . V_144 ,
V_2 -> V_129 . V_150 ) ;
}
}
void F_67 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_35 = 0 , V_151 ;
T_2 V_123 ;
struct V_137 * V_152 = NULL , * V_153 = NULL ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_154 = NULL , * V_155 = NULL ;
unsigned int V_156 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_38 ) == 4 * sizeof( T_3 ) ) {
V_6 = F_5 ( sizeof( struct V_5 ) , V_25 ) ;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else
V_6 = (struct V_5 * ) V_4 ;
#ifdef F_48
V_6 -> V_157 = F_49 ( V_6 -> V_157 ) ;
V_6 -> V_158 = F_49 ( V_6 -> V_158 ) ;
V_6 -> V_14 . V_103 = F_49 ( V_6 -> V_14 . V_103 ) ;
V_6 -> V_14 . V_82 . V_83 =
F_49 ( V_6 -> V_14 . V_82 . V_83 ) ;
V_6 -> V_14 . V_76 = F_49 ( V_6 -> V_14 . V_76 ) ;
V_6 -> V_14 . V_99 = F_49 ( V_6 -> V_14 . V_99 ) ;
V_6 -> V_14 . V_111 =
F_49 ( V_6 -> V_14 . V_111 ) ;
V_6 -> V_14 . V_84 . V_112 =
F_49 ( V_6 -> V_14 . V_84 . V_112 ) ;
V_6 -> V_14 . V_84 . V_113 =
F_49 ( V_6 -> V_14 . V_84 . V_113 ) ;
V_6 -> V_14 . V_84 . V_85 =
F_49 ( V_6 -> V_14 . V_84 . V_85 ) ;
V_6 -> V_14 . V_84 . V_114 . V_115 =
F_49 ( V_6 -> V_14 . V_84 . V_114 .
V_115 ) ;
V_6 -> V_14 . V_84 . V_114 . V_116 =
F_49 ( V_6 -> V_14 . V_84 .
V_114 . V_116 ) ;
V_6 -> V_14 . V_84 . V_114 . V_117 =
F_49 ( V_6 -> V_14 . V_84 . V_114 . V_117 ) ;
V_6 -> V_14 . V_84 . V_114 . V_103 =
F_49 ( V_6 -> V_14 . V_84 . V_114 . V_103 ) ;
V_6 -> V_14 . V_84 . V_103 =
F_49 ( V_6 -> V_14 . V_84 . V_103 ) ;
V_6 -> V_14 . V_15 =
F_49 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_66 = F_49 ( V_6 -> V_14 . V_66 ) ;
#endif
V_156 = ! memcmp ( V_6 -> V_14 . V_50 ,
V_13 -> V_14 . V_50 , V_51 ) ;
V_6 -> V_14 . V_103 =
F_26 ( & V_6 -> V_14 ) ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( V_6 -> V_14 . V_103 > sizeof( struct V_118 ) )
goto V_159;
if ( V_6 -> V_157 > 0 ) {
if ( F_24 ( V_8 , V_121 ) == true ) {
if ( F_24 ( V_8 , V_55 ) == true ) {
if ( V_156 == true )
V_155 =
F_34 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_50 ) ;
else {
V_154 =
F_34 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_50 ) ;
V_154 -> V_45 = false ;
V_153 = F_58 ( V_132 ,
V_13 -> V_14 . V_50 ) ;
F_11 ( & V_132 ->
V_139 , V_151 ) ;
F_59 ( V_69 , V_153 ) ;
F_15 ( & ( V_132 ->
V_139 ) , V_151 ) ;
V_155 =
F_34 ( & V_8 ->
V_21 ,
V_6 -> V_14 .
V_50 ) ;
if ( V_155 )
V_155 -> V_45 = true ;
}
} else {
V_155 = F_34 ( & V_8 ->
V_21 ,
V_6 -> V_14 . V_50 ) ;
if ( V_155 )
V_155 -> V_45 = true ;
}
if ( V_155 == NULL ) {
if ( F_24 ( V_8 ,
V_121 ) )
V_8 -> V_12 ^=
V_121 ;
goto V_159;
}
if ( F_24 ( V_8 , V_135 ) ) {
if ( V_156 == true ) {
V_152 =
F_58 ( V_132 ,
V_6 -> V_14 . V_50 ) ;
if ( V_152 == NULL )
V_152 =
F_68 ( V_132 ,
V_6 -> V_14 . V_50 ) ;
} else
V_152 =
F_68 ( V_132 ,
V_6 -> V_14 . V_50 ) ;
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
if ( F_24 ( V_8 ,
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
F_41 ( V_69 ,
( V_13 -> V_14 . V_81 ) +
sizeof( struct V_100 ) ,
( V_13 -> V_14 . V_66 ) ) ;
F_69 ( V_69 , V_13 -> V_14 . V_81 ,
V_13 -> V_14 . V_66 ) ;
if ( F_24 ( V_8 , V_135 )
== true )
F_61 ( V_69 ) ;
F_51 ( & V_8 -> V_126 ,
& V_123 ) ;
} else
goto V_159;
} else {
if ( F_24 ( V_8 , V_121 ) == true ) {
F_55 ( & V_8 -> V_126 , 1 ) ;
F_52 ( V_8 , V_121 ) ;
}
}
V_159:
F_15 ( & V_8 -> V_18 , V_35 ) ;
if ( sizeof( struct V_38 ) == 4 * sizeof( T_3 ) )
F_30 ( ( T_2 * ) V_6 ) ;
}
void F_70 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_137 * V_138 ;
struct V_7 * V_8 = & ( V_69 -> V_9 ) ;
struct V_179 * V_180 = (struct V_179 * ) V_4 ;
if ( F_71 ( & V_69 -> V_181 , V_180 -> V_182 ) == false )
return;
V_138 = F_58 ( & V_69 -> V_133 , V_180 -> V_182 ) ;
if ( V_138 != NULL ) {
return;
}
V_138 = F_68 ( & V_69 -> V_133 , V_180 -> V_182 ) ;
if ( V_138 == NULL )
return;
V_138 -> V_161 = 0 ;
V_138 -> V_162 = F_49 ( ( T_4 ) V_180 -> V_183 ) ;
if ( V_69 -> V_73 . V_163 == 2 )
V_138 -> V_168 = V_69 -> V_73 . V_74 ;
V_138 -> V_167 = false ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
if ( ( F_24 ( V_8 , V_119 ) == true ) ||
( F_24 ( V_8 , V_108 ) == true ) ) {
if ( V_69 -> V_133 . V_140 == 2 ) {
F_61 ( V_69 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_35 ) ;
}
void F_72 ( struct V_1 * V_69 , T_2 * V_4 )
{
unsigned long V_35 , V_151 ;
struct V_137 * V_138 ;
struct V_5 * V_88 = NULL ;
struct V_118 * V_128 = NULL ;
T_2 * V_56 = NULL ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_184 * V_185 = (struct V_184 * ) V_4 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_5 * V_134 = & V_8 -> V_13 ;
F_11 ( & V_8 -> V_18 , V_151 ) ;
if ( F_24 ( V_8 , V_135 ) == true ) {
F_63 ( V_69 ) ;
F_57 ( V_69 ) ;
}
if ( F_24 ( V_8 , V_119 |
V_108 ) ) {
V_138 = F_58 ( & V_69 -> V_133 , V_185 -> V_182 ) ;
F_11 ( & V_132 -> V_139 , V_35 ) ;
F_59 ( V_69 , V_138 ) ;
F_15 ( & V_132 -> V_139 , V_35 ) ;
if ( V_69 -> V_133 . V_140 == 1 ) {
V_88 = F_34 ( & V_8 -> V_21 ,
V_134 -> V_14 . V_50 ) ;
if ( V_88 ) {
V_88 -> V_45 = false ;
F_32 ( V_8 , V_88 ) ;
}
V_128 = & ( V_69 -> V_129 . V_130 ) ;
V_56 = V_69 -> V_129 . V_130 . V_50 ;
memcpy ( V_128 , & V_134 -> V_14 ,
F_26 ( & V_134 ->
V_14 ) ) ;
memcpy ( & V_128 -> V_82 ,
& V_8 -> V_22 ,
sizeof( struct V_23 ) ) ;
F_56 ( V_69 ) ;
F_25 ( V_56 ) ;
if ( F_24 ( V_8 , V_108 ) ) {
F_52 ( V_8 , V_108 ) ;
F_53 ( V_8 , V_119 ) ;
}
}
}
F_15 ( & V_8 -> V_18 , V_151 ) ;
}
void F_73 ( struct V_1 * V_69 , T_2 * V_4 )
{
struct V_186 * V_187 =
(struct V_186 * ) V_4 ;
V_187 -> V_188 |= ( T_2 ) ( V_69 -> V_148 . V_189 + 0x80 ) ;
F_74 ( V_69 , V_187 ) ;
}
void F_75 ( struct V_1 * V_69 , T_2 * V_4 )
{
struct V_190 * V_191 =
(struct V_190 * ) V_4 ;
struct V_137 * V_138 ;
struct V_131 * V_132 = & V_69 -> V_133 ;
struct V_192 * V_193 = NULL ;
V_138 = F_58 ( V_132 , V_191 -> V_50 ) ;
if ( V_138 ) {
V_193 =
& V_138 -> V_194 [ V_191 -> V_195 ] ;
V_193 -> V_196 = 0xffff ;
}
}
void F_76 ( struct V_1 * V_69 , T_2 * V_4 )
{
if ( V_69 -> V_73 . V_197 == false )
V_69 -> V_73 . V_197 = true ;
}
void F_77 ( struct V_1 * V_69 )
{
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_198 * V_199 = & V_8 -> V_30 ;
struct V_200 * V_201 = & V_69 -> V_129 ;
T_6 V_202 ;
T_4 V_203 ;
V_202 = ( V_69 -> V_204 . V_205 ) -
( V_199 -> V_32 ) ;
V_203 = ( V_69 -> V_92 . V_206 ) -
( V_199 -> V_31 ) ;
V_199 -> V_32 = V_69 -> V_204 . V_205 ;
V_199 -> V_31 = V_69 -> V_92 . V_206 ;
if ( ( V_202 > V_201 -> V_207 ) ||
( V_203 > V_201 -> V_207 ) )
V_199 -> V_33 = true ;
else
V_199 -> V_33 = false ;
}
void F_78 ( struct V_1 * V_69 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
if ( V_69 -> V_53 || V_69 -> V_54 )
return;
F_11 ( & V_8 -> V_18 , V_35 ) ;
F_52 ( V_8 , V_121 ) ;
V_8 -> V_125 = false ;
if ( F_24 ( V_8 , V_55 ) == true ) {
F_64 ( V_69 ) ;
F_52 ( V_8 , V_55 ) ;
}
if ( V_69 -> V_148 . V_149 != V_69 -> V_129 . V_144 ) {
F_66 ( V_69 , V_69 -> V_129 . V_144 ,
V_69 -> V_129 . V_150 ) ;
}
F_15 ( & V_8 -> V_18 , V_35 ) ;
}
void F_79 ( struct V_1 * V_69 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_35 ) ;
F_52 ( V_8 , V_122 ) ;
V_8 -> V_125 = false ;
F_15 ( & V_8 -> V_18 , V_35 ) ;
}
void F_80 ( struct V_1 * V_69 )
{
if ( V_69 -> V_53 || V_69 -> V_54 )
return;
if ( V_69 -> V_148 . V_149 != V_69 -> V_129 . V_144 )
F_66 ( V_69 , V_69 -> V_129 . V_144 ,
V_69 -> V_129 . V_150 ) ;
}
void F_81 ( struct V_1 * V_69 )
{
F_82 ( V_69 ) ;
}
int F_54 ( struct V_7 * V_8 )
{
struct V_38 * V_49 ;
unsigned char * V_208 , * V_209 ;
struct V_1 * V_69 ;
struct V_36 * V_29 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_210 = NULL ;
V_69 = (struct V_1 * ) V_8 -> V_10 ;
V_29 = & V_8 -> V_21 ;
V_49 = F_18 ( V_29 ) ;
V_8 -> V_11 = F_12 ( V_49 ) ;
while ( 1 ) {
if ( F_22 ( V_49 , V_8 -> V_11 ) == true ) {
if ( ( V_8 -> V_211 == true ) &&
( V_210 != NULL ) ) {
V_6 = V_210 ;
goto V_212;
}
return V_26 ;
}
V_6 = F_13 ( V_8 -> V_11 ,
struct V_5 , V_28 ) ;
if ( V_6 == NULL )
return V_26 ;
V_8 -> V_11 = F_12 ( V_8 -> V_11 ) ;
if ( V_8 -> V_213 == true ) {
V_208 = V_6 -> V_14 . V_50 ;
V_209 = V_8 -> V_214 ;
if ( ! memcmp ( V_208 , V_209 , V_51 ) ) {
if ( F_24 ( V_8 , V_55 ) ) {
if ( F_36 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_52 ( V_8 ,
V_121 ) ;
F_61 ( V_69 ) ;
return 2 ;
}
F_83 ( V_69 ) ;
F_63 ( V_69 ) ;
F_57 ( V_69 ) ;
}
goto V_212;
}
} else if ( V_8 -> V_22 . V_83 == 0 )
goto V_212;
V_208 = V_6 -> V_14 . V_82 . V_82 ;
V_209 = V_8 -> V_22 . V_82 ;
if ( ( V_6 -> V_14 . V_82 . V_83 ==
V_8 -> V_22 . V_83 ) &&
( ! memcmp ( V_208 , V_209 ,
V_8 -> V_22 . V_83 ) ) ) {
if ( V_8 -> V_211 == true ) {
if ( V_210 ) {
if ( V_6 -> V_14 . V_99 >
V_210 -> V_14 . V_99 )
V_210 = V_6 ;
} else
V_210 = V_6 ;
} else if ( F_44 ( V_69 , V_6 ) ) {
if ( F_24 ( V_8 , V_55 ) ) {
F_83 ( V_69 ) ;
F_57 ( V_69 ) ;
}
goto V_212;
}
}
}
return V_26 ;
V_212:
return F_84 ( V_69 , V_6 ) ;
}
T_1 F_85 ( struct V_1 * V_69 ,
struct V_71 * V_72 )
{
struct V_215 * V_216 = & V_69 -> V_217 ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
V_219 = F_5 ( sizeof( struct V_218 ) , V_25 ) ;
if ( V_219 == NULL )
return V_26 ;
V_221 = F_86 ( sizeof( struct V_220 ) , V_25 ) ;
if ( V_221 == NULL ) {
F_30 ( ( unsigned char * ) V_219 ) ;
return V_26 ;
}
V_221 -> V_222 = ( T_2 ) V_72 -> V_163 ;
V_219 -> V_223 = V_224 ;
V_219 -> V_225 = ( unsigned char * ) V_221 ;
V_219 -> V_226 = sizeof( struct V_220 ) ;
V_219 -> V_227 = NULL ;
V_219 -> V_228 = 0 ;
F_6 ( & V_219 -> V_28 ) ;
F_87 ( V_216 , V_219 ) ;
return V_34 ;
}
T_1 F_88 ( struct V_1 * V_69 ,
struct V_71 * V_72 ,
T_1 V_229 )
{
struct V_215 * V_216 = & V_69 -> V_217 ;
struct V_218 * V_219 ;
struct V_230 * V_231 ;
T_2 V_232 ;
T_1 V_70 = V_34 ;
V_219 = F_5 ( sizeof( struct V_218 ) , V_25 ) ;
if ( V_219 == NULL )
return V_26 ;
V_231 = F_86 ( sizeof( struct V_230 ) , V_25 ) ;
if ( V_231 == NULL ) {
V_70 = V_26 ;
goto V_233;
}
if ( V_72 -> V_163 == 2 ) {
V_231 -> V_234 =
( T_2 ) V_72 -> V_235 ;
} else {
V_231 -> V_234 =
( T_2 ) V_72 -> V_74 ;
}
V_231 -> V_229 = ( T_2 ) V_229 ;
switch ( V_231 -> V_234 ) {
case V_236 :
V_232 = 5 ;
memcpy ( V_231 -> V_237 ,
V_72 -> V_238 [ V_229 ] . V_239 , V_232 ) ;
break;
case V_240 :
V_232 = 13 ;
memcpy ( V_231 -> V_237 ,
V_72 -> V_238 [ V_229 ] . V_239 , V_232 ) ;
break;
case V_241 :
if ( V_229 < 1 || V_229 > 2 ) {
V_70 = V_26 ;
goto V_242;
}
V_232 = 16 ;
memcpy ( V_231 -> V_237 ,
& V_72 -> V_243 [ V_229 - 1 ] , V_232 ) ;
V_231 -> V_244 = 1 ;
break;
case V_245 :
if ( V_229 < 1 || V_229 > 2 ) {
V_70 = V_26 ;
goto V_242;
}
V_232 = 16 ;
memcpy ( V_231 -> V_237 ,
& V_72 -> V_243 [ V_229 - 1 ] , V_232 ) ;
V_231 -> V_244 = 1 ;
break;
default:
V_70 = V_26 ;
goto V_242;
}
V_219 -> V_223 = V_246 ;
V_219 -> V_225 = ( T_2 * ) V_231 ;
V_219 -> V_226 = ( sizeof( struct V_230 ) ) ;
V_219 -> V_227 = NULL ;
V_219 -> V_228 = 0 ;
F_6 ( & V_219 -> V_28 ) ;
F_87 ( V_216 , V_219 ) ;
return V_70 ;
V_242:
F_30 ( V_231 ) ;
V_233:
F_30 ( V_219 ) ;
return V_70 ;
}
int F_89 ( struct V_1 * V_69 , T_2 * V_247 , T_2 * V_248 ,
T_4 V_249 , T_4 V_250 )
{
unsigned int V_251 = 0 ;
unsigned int V_3 , V_252 ;
V_3 = 12 ;
while ( V_3 < V_249 ) {
V_251 = V_250 ;
if ( V_247 [ V_3 ] == 0xDD && V_247 [ V_3 + 2 ] == 0x00 &&
V_247 [ V_3 + 3 ] == 0x50 && V_247 [ V_3 + 4 ] == 0xF2 &&
V_247 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_249 ) {
for ( V_252 = V_3 ; V_252 < V_3 + 9 ; V_252 ++ ) {
V_248 [ V_251 ] = V_247 [ V_252 ] ;
V_251 ++ ;
}
V_248 [ V_250 + 1 ] = 0x07 ;
V_248 [ V_250 + 6 ] = 0x00 ;
V_248 [ V_250 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_247 [ V_3 + 1 ] + 2 ) ;
}
return V_251 ;
}
static int F_90 ( struct V_1 * V_253 , T_2 * V_254 )
{
struct V_71 * V_72 = & V_253 -> V_73 ;
int V_3 = 0 ;
do {
if ( V_72 -> V_255 [ V_3 ] . V_256 &&
( ! memcmp ( V_72 -> V_255 [ V_3 ] . V_257 ,
V_254 , V_51 ) ) )
break;
else
V_3 ++ ;
} while ( V_3 < V_258 );
if ( V_3 == V_258 ) {
V_3 = - 1 ;
} else {
;
}
return V_3 ;
}
T_1 F_91 ( struct V_1 * V_69 , T_2 * V_247 ,
T_2 * V_248 , T_4 V_249 )
{
T_2 V_259 = 0 , V_260 , V_261 ;
T_2 V_262 [ 255 ] , V_263 [ 4 ] , V_264 [ 255 ] ;
T_2 V_265 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_251 , V_266 , V_267 ;
int V_268 ;
struct V_7 * V_8 = & V_69 -> V_9 ;
struct V_71 * V_72 = & V_69 -> V_73 ;
T_4 V_269 = V_72 -> V_270 ;
T_4 V_271 = V_72 -> V_272 ;
if ( ( V_269 == V_273 ) ||
( V_269 == V_274 ) ) {
V_259 = V_275 ;
V_263 [ 0 ] = 0x0 ;
V_263 [ 1 ] = 0x50 ;
V_263 [ 2 ] = 0xf2 ;
}
if ( ( V_269 == V_276 ) ||
( V_269 == V_277 ) ) {
V_259 = V_278 ;
V_263 [ 0 ] = 0x0 ;
V_263 [ 1 ] = 0x0f ;
V_263 [ 2 ] = 0xac ;
}
switch ( V_271 ) {
case V_279 :
case V_280 :
V_260 = V_236 ;
V_263 [ 3 ] = 0x1 ;
break;
case V_281 :
case V_282 :
V_260 = V_241 ;
V_263 [ 3 ] = 0x2 ;
break;
case V_283 :
case V_284 :
V_260 = V_245 ;
V_263 [ 3 ] = 0x4 ;
break;
default:
V_260 = V_75 ;
break;
}
V_266 = 12 ;
V_261 = false ;
while ( V_266 < V_249 ) {
if ( V_247 [ V_266 ] == V_259 ) {
if ( ( V_259 == V_275 ) &&
( ! memcmp ( & V_247 [ V_266 + 2 ] , & V_265 [ 0 ] , 4 ) ) ) {
memcpy ( & V_262 [ 0 ] , & V_247 [ V_266 ] ,
V_247 [ V_266 + 1 ] + 2 ) ;
V_261 = true ;
break;
}
if ( V_259 == V_278 ) {
memcpy ( & V_262 [ 0 ] , & V_247 [ V_266 ] ,
V_247 [ V_266 + 1 ] + 2 ) ;
V_261 = true ;
break;
}
if ( ( ( V_259 == V_275 ) &&
( ! memcmp ( & V_247 [ V_266 + 2 ] , & V_265 [ 0 ] , 4 ) ) ) ||
( V_259 == V_278 ) )
memcpy ( & V_264 [ 0 ] , & V_247 [ V_266 ] ,
V_247 [ V_266 + 1 ] + 2 ) ;
}
V_266 += V_247 [ V_266 + 1 ] + 2 ;
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
V_72 -> V_235 =
V_75 ;
break;
case 0x1 :
V_72 -> V_235 =
V_236 ;
break;
case 0x2 :
V_72 -> V_235 =
V_241 ;
break;
case 0x3 :
case 0x4 :
V_72 -> V_235 =
V_245 ;
break;
case 0x5 :
V_72 -> V_235 =
V_240 ;
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
if ( V_259 == V_278 ) {
while ( true ) {
if ( ( V_262 [ 2 ] != 0x01 ) || ( V_262 [ 3 ] != 0x0 ) ) {
V_261 = false ;
break;
}
if ( ! memcmp ( & V_262 [ 4 ] , & V_263 [ 0 ] , 3 ) ) {
switch ( V_262 [ 7 ] ) {
case 0x1 :
V_72 -> V_235 =
V_236 ;
break;
case 0x2 :
V_72 -> V_235 =
V_241 ;
break;
case 0x4 :
V_72 -> V_235 =
V_245 ;
break;
case 0x5 :
V_72 -> V_235 =
V_240 ;
break;
default:
V_72 -> V_235 =
V_75 ;
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
if ( ( V_259 == V_275 ) || ( V_259 == V_278 ) ) {
memcpy ( V_248 , V_247 , 12 ) ;
V_251 = 12 ;
if ( V_261 == true ) {
memcpy ( & V_248 [ V_251 ] , & V_262 [ 0 ] , V_262 [ 1 ] + 2 ) ;
V_251 += V_262 [ 1 ] + 2 ;
if ( V_259 == V_278 ) {
V_248 [ V_251 - 1 ] = 0 ;
V_248 [ V_251 - 2 ] = 0 ;
}
F_92 ( V_69 , V_259 , V_262 ) ;
}
} else {
memcpy ( V_248 , V_247 , 12 ) ;
V_251 = 12 ;
if ( V_72 -> V_107 == true ) {
memcpy ( V_248 + V_251 , V_72 -> V_104 ,
V_72 -> V_285 ) ;
V_251 += V_72 -> V_285 ;
}
}
V_268 = F_90 ( V_69 , V_8 -> V_214 ) ;
if ( V_268 < 0 )
return V_251 ;
else {
if ( V_259 == V_278 ) {
V_248 [ V_251 ] = 1 ;
V_251 ++ ;
V_248 [ V_251 ] = 0 ;
V_251 ++ ;
memcpy ( & V_248 [ V_251 ] ,
& V_72 -> V_255 [ V_268 ] . V_286 , 16 ) ;
V_251 += 16 ;
V_248 [ 13 ] += 18 ;
}
}
return V_251 ;
}
void F_93 ( struct V_1 * V_69 )
{
struct V_200 * V_201 = & V_69 -> V_129 ;
struct V_287 * V_288 = & V_69 -> V_289 ;
struct V_118 * V_128 = & V_201 -> V_130 ;
T_2 * V_290 = F_94 ( V_288 ) ;
memcpy ( V_128 -> V_50 , V_290 , V_51 ) ;
memcpy ( & V_128 -> V_82 , & V_201 -> V_291 ,
sizeof( struct V_23 ) ) ;
V_128 -> V_84 . V_103 =
sizeof( struct V_63 ) ;
V_128 -> V_84 . V_113 = 100 ;
V_128 -> V_84 . V_114 . V_103 = 0 ;
V_128 -> V_84 . V_114 . V_116 = 0 ;
V_128 -> V_84 . V_114 . V_117 = 0 ;
V_128 -> V_84 . V_114 . V_115 = 0 ;
}
void F_56 ( struct V_1 * V_69 )
{
int V_292 = 0 ;
struct V_200 * V_201 = & V_69 -> V_129 ;
struct V_118 * V_128 = & V_201 -> V_130 ;
struct V_71 * V_72 = & V_69 -> V_73 ;
struct V_5 * V_13 = & V_69 -> V_9 . V_13 ;
V_128 -> V_76 = F_95 ( V_72 -> V_74
> 0 ? 1 : 0 ) ;
V_128 -> V_99 = 0 ;
switch ( V_201 -> V_293 ) {
case V_294 :
V_128 -> V_111 = F_95 ( V_295 ) ;
break;
case V_296 :
case V_297 :
V_128 -> V_111 = F_95 ( V_298 ) ;
break;
case V_299 :
V_128 -> V_111 = F_95 ( V_300 ) ;
break;
default:
break;
}
V_128 -> V_84 . V_85 = F_95 (
V_201 -> V_301 ) ;
if ( V_13 -> V_14 . V_15 == V_177 )
V_128 -> V_84 . V_112 = F_95 ( 3 ) ;
V_128 -> V_15 = F_95 (
V_13 -> V_14 . V_15 ) ;
V_292 = F_96 ( V_201 ) ;
V_128 -> V_66 = V_292 ;
V_128 -> V_103 = F_26 (
(struct V_58 * ) V_128 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
V_303 -> V_305 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_303 -> V_306 [ V_3 ] = false ;
if ( V_303 -> V_307 ) {
F_98 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_98 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_99 ( struct V_1 * V_2 , T_2 * V_247 ,
T_2 * V_248 , T_4 V_249 , T_4 * V_308 )
{
T_3 V_309 , V_310 ;
unsigned char * V_311 , * V_312 ;
struct V_313 V_314 ;
unsigned char V_315 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_316 * V_317 = & V_8 -> V_318 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
V_303 -> V_307 = 0 ;
V_311 = F_100 ( V_247 + 12 , V_319 , & V_309 , V_249 - 12 ) ;
if ( V_311 && ( V_309 > 0 ) ) {
if ( V_317 -> V_161 == 0 ) {
V_310 = * V_308 ;
V_312 = F_101 ( V_248 + V_310 ,
V_320 ,
V_321 ,
V_315 , V_308 ) ;
V_317 -> V_161 = 1 ;
}
V_310 = * V_308 ;
memset ( & V_314 , 0 , sizeof( struct V_313 ) ) ;
V_314 . V_322 = V_323 |
V_324 |
V_325 |
V_326 |
V_327 |
V_328 ;
V_314 . V_329 = ( V_330 &
0x03 ) | ( V_331 & 0x00 ) ;
V_312 = F_101 ( V_248 + V_310 , V_319 ,
sizeof( struct V_313 ) ,
( unsigned char * ) & V_314 , V_308 ) ;
V_303 -> V_307 = 1 ;
}
return V_303 -> V_307 ;
}
static void F_69 ( struct V_1 * V_2 , T_2 * V_332 , T_4 V_333 )
{
T_2 * V_311 , V_334 ;
int V_3 , V_110 ;
struct V_137 * V_335 , * V_138 ;
struct V_313 * V_336 ;
struct V_337 * V_338 ;
struct V_192 * V_339 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
struct V_200 * V_201 = & V_2 -> V_129 ;
struct V_5 * V_340 = & ( V_8 -> V_13 ) ;
if ( ! V_303 -> V_307 )
return;
if ( ( V_303 -> V_305 == false ) &&
( V_201 -> V_305 == 1 ) )
V_303 -> V_305 = true ;
V_110 = 0 ;
V_311 = F_100 ( V_332 + sizeof( struct V_100 ) ,
V_319 ,
& V_110 , V_333 -
sizeof( struct V_100 ) ) ;
if ( V_311 && V_110 > 0 ) {
V_336 = (struct V_313 * ) ( V_311 + 2 ) ;
V_334 = ( V_336 -> V_329 &
V_330 ) ;
V_334 = 1 << ( V_334 + 3 ) ;
V_303 -> V_341 = V_334 ;
}
V_335 = F_102 ( V_2 ) ;
if ( V_335 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_339 = & V_335 -> V_194 [ V_3 ] ;
V_339 -> V_196 = 0xffff ;
V_339 -> V_342 = 0xffff ;
}
}
V_138 = F_58 ( & V_2 -> V_133 ,
V_340 -> V_14 . V_50 ) ;
if ( V_138 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_339 = & V_138 -> V_194 [ V_3 ] ;
V_339 -> V_196 = 0xffff ;
V_339 -> V_342 = 0xffff ;
}
}
V_110 = 0 ;
V_311 = F_100 ( V_332 + sizeof( struct V_100 ) ,
V_343 , & V_110 ,
V_333 - sizeof( struct V_100 ) ) ;
if ( V_311 && V_110 > 0 )
V_338 = (struct V_337 * ) ( V_311 + 2 ) ;
}
void F_103 ( struct V_1 * V_2 , int V_344 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
if ( ( V_303 -> V_307 == 1 ) && ( V_303 -> V_305 == true ) ) {
if ( V_303 -> V_306 [ V_344 ] == false ) {
F_104 ( V_2 , ( T_2 ) V_344 ) ;
V_303 -> V_306 [ V_344 ] = true ;
}
}
}
