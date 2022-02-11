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
F_2 ( & ( V_8 -> V_17 ) ) ;
F_2 ( & ( V_8 -> V_18 ) ) ;
F_3 ( & ( V_8 -> V_19 ) ) ;
F_3 ( & ( V_8 -> V_20 ) ) ;
F_4 ( V_8 , 0 ) ;
memset ( & V_8 -> V_21 , 0 , sizeof( struct V_22 ) ) ;
V_4 = F_5 ( V_23 * ( sizeof( struct V_5 ) ) ) ;
if ( V_4 == NULL )
return V_24 ;
V_8 -> V_25 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
F_6 ( & ( V_6 -> V_26 ) ) ;
F_7 ( & ( V_6 -> V_26 ) ,
& ( V_8 -> V_19 . V_27 ) ) ;
V_6 ++ ;
}
V_8 -> V_28 . V_29 = 0 ;
V_8 -> V_28 . V_30 = 0 ;
V_8 -> V_28 . V_31 = false ;
F_8 ( V_2 ) ;
return V_32 ;
}
struct V_5 * F_9 ( struct V_7 * V_8 )
{
unsigned long V_33 ;
struct V_5 * V_6 ;
struct V_34 * V_35 = & V_8 -> V_19 ;
struct V_36 * V_37 = NULL ;
if ( F_10 ( V_35 ) == true )
return NULL ;
F_11 ( & V_35 -> V_17 , V_33 ) ;
V_37 = F_12 ( & ( V_35 -> V_27 ) ) ;
V_6 = F_13 ( V_37 , struct V_5 , V_26 ) ;
F_14 ( & V_6 -> V_26 ) ;
V_6 -> V_38 = V_39 ;
V_8 -> V_40 ++ ;
F_15 ( & V_35 -> V_17 , V_33 ) ;
return V_6 ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_41 , V_42 ;
unsigned long V_33 ;
struct V_34 * V_35 = & ( V_8 -> V_19 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_43 == true )
return;
V_41 = V_39 ;
V_42 = ( V_41 - ( T_3 ) V_6 -> V_38 ) / V_44 ;
if ( V_42 < V_45 )
return;
F_11 ( & V_35 -> V_17 , V_33 ) ;
F_14 ( & V_6 -> V_26 ) ;
F_7 ( & V_6 -> V_26 , & V_35 -> V_27 ) ;
V_8 -> V_40 -- ;
F_15 ( & V_35 -> V_17 , V_33 ) ;
}
static void F_17 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_34 * V_35 = & V_8 -> V_19 ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_43 == true )
return;
F_14 ( & V_6 -> V_26 ) ;
F_7 ( & V_6 -> V_26 , F_18 ( V_35 ) ) ;
V_8 -> V_40 -- ;
}
static struct V_5 * F_19 ( struct V_34 * V_20 ,
T_2 * V_46 )
{
unsigned long V_33 ;
struct V_36 * V_47 , * V_37 ;
struct V_5 * V_6 = NULL ;
T_2 V_48 [ V_49 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( ! memcmp ( V_48 , V_46 , V_49 ) )
return NULL ;
F_11 ( & V_20 -> V_17 , V_33 ) ;
V_47 = F_18 ( V_20 ) ;
V_37 = F_12 ( V_47 ) ;
while ( V_37 != V_47 ) {
V_6 = F_13 ( V_37 , struct V_5 , V_26 ) ;
V_37 = F_12 ( V_37 ) ;
if ( ! memcmp ( V_46 , V_6 -> V_14 . V_50 , V_49 ) )
break;
}
F_15 ( & V_20 -> V_17 , V_33 ) ;
return V_6 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
struct V_36 * V_47 , * V_37 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_34 * V_20 = & V_8 -> V_20 ;
F_11 ( & V_20 -> V_17 , V_33 ) ;
V_47 = F_18 ( V_20 ) ;
V_37 = F_12 ( V_47 ) ;
while ( F_21 ( V_47 , V_37 ) == false ) {
V_6 = F_13 ( V_37 , struct V_5 , V_26 ) ;
V_37 = F_12 ( V_37 ) ;
F_16 ( V_8 , V_6 ) ;
}
F_15 ( & V_20 -> V_17 , V_33 ) ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_51 ;
if ( V_2 -> V_52 || V_2 -> V_53 ||
( F_23 ( & V_2 -> V_9 , V_54 ) == false ) ) {
V_51 = false ;
} else
V_51 = true ;
return V_51 ;
}
void F_24 ( T_2 * V_55 )
{
T_3 V_56 = V_39 ;
V_55 [ 0 ] = 0x02 ;
V_55 [ 1 ] = 0x11 ;
V_55 [ 2 ] = 0x87 ;
V_55 [ 3 ] = ( T_2 ) ( V_56 & 0xff ) ;
V_55 [ 4 ] = ( T_2 ) ( ( V_56 >> 8 ) & 0xff ) ;
V_55 [ 5 ] = ( T_2 ) ( ( V_56 >> 16 ) & 0xff ) ;
}
T_4 F_25 ( struct V_57 * V_58 )
{
T_4 V_59 ;
V_59 = sizeof( T_3 ) + 6 * sizeof( unsigned long ) + 2 +
sizeof( struct V_22 ) + sizeof( T_3 ) +
sizeof( V_60 ) +
sizeof( enum V_61 ) +
sizeof( struct V_62 ) +
sizeof( enum V_63 ) +
sizeof( V_64 ) +
sizeof( T_3 ) + V_58 -> V_65 ;
return V_59 ;
}
T_2 * F_26 ( T_2 * V_66 )
{
return V_66 + 8 + 2 ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
F_29 ( V_8 -> V_25 ) ;
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
void F_32 ( struct V_1 * V_67 )
{
F_20 ( V_67 ) ;
}
static struct V_5 * F_33 ( struct V_34 * V_20 ,
T_2 * V_46 )
{
struct V_5 * V_6 = F_19 ( V_20 ,
V_46 ) ;
return V_6 ;
}
int F_34 ( struct V_1 * V_68 , struct V_5 * V_6 )
{
int V_69 = true ;
struct V_70 * V_71 = & V_68 -> V_72 ;
if ( ( V_71 -> V_73 != V_74 ) &&
( V_6 -> V_14 . V_75 == 0 ) )
V_69 = false ;
else if ( ( V_71 -> V_73 == V_74 ) &&
( V_6 -> V_14 . V_75 == 1 ) )
V_69 = false ;
else
V_69 = true ;
return V_69 ;
}
static int F_35 ( struct V_57 * V_76 ,
struct V_57 * V_77 )
{
T_5 V_78 , V_79 ;
memcpy ( ( T_2 * ) & V_78 , F_26 ( V_76 -> V_80 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_79 , F_26 ( V_77 -> V_80 ) , 2 ) ;
return ( V_76 -> V_81 . V_82 == V_77 -> V_81 . V_82 ) &&
( V_76 -> V_83 . V_84 ==
V_77 -> V_83 . V_84 ) &&
( ( ! memcmp ( V_76 -> V_50 , V_77 -> V_50 ,
V_49 ) ) ) &&
( ( ! memcmp ( V_76 -> V_81 . V_81 ,
V_77 -> V_81 . V_81 ,
V_76 -> V_81 . V_82 ) ) ) &&
( ( V_78 & V_85 ) ==
( V_79 & V_85 ) ) &&
( ( V_78 & V_86 ) ==
( V_79 & V_86 ) ) ;
}
struct V_5 * F_36 (
struct V_34 * V_20 )
{
struct V_36 * V_37 , * V_47 ;
struct V_5 * V_87 = NULL ;
struct V_5 * V_88 = NULL ;
V_47 = F_18 ( V_20 ) ;
V_37 = F_12 ( V_47 ) ;
while ( 1 ) {
if ( F_21 ( V_47 , V_37 ) == true )
break;
V_87 = F_13 ( V_37 , struct V_5 , V_26 ) ;
if ( V_87 -> V_43 != true ) {
if ( V_88 == NULL ||
F_37 ( ( unsigned long ) V_88 -> V_38 ,
( unsigned long ) V_87 -> V_38 ) )
V_88 = V_87 ;
}
V_37 = F_12 ( V_37 ) ;
}
return V_88 ;
}
static void F_38 ( struct V_57 * V_77 ,
struct V_57 * V_76 ,
struct V_1 * V_2 )
{
T_3 V_89 = 0 , V_90 ;
if ( F_23 ( & V_2 -> V_9 , V_54 ) &&
F_35 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_76 ) ) {
if ( V_2 -> V_91 . V_92 . V_93 ++ >=
V_94 ) {
V_2 -> V_91 . V_92 . V_93 =
V_94 ;
V_89 = V_2 -> V_91 . V_92 .
V_95 [ V_2 -> V_91 .
V_92 . V_96 ] ;
V_2 -> V_91 . V_92 . V_97 -=
V_89 ;
}
V_2 -> V_91 . V_92 . V_97 += V_76 -> V_98 ;
V_2 -> V_91 . V_92 .
V_95 [ V_2 -> V_91 . V_92 .
V_96 ++ ] = V_76 -> V_98 ;
if ( V_2 -> V_91 . V_92 . V_96 >=
V_94 )
V_2 -> V_91 . V_92 . V_96 = 0 ;
V_90 = V_2 -> V_91 . V_92 . V_97 /
V_2 -> V_91 . V_92 . V_93 ;
V_2 -> V_91 . signal = ( T_2 ) V_90 ;
V_76 -> V_98 = V_2 -> V_91 . signal ;
} else
V_76 -> V_98 = ( V_76 -> V_98 + V_77 -> V_98 ) / 2 ;
memcpy ( ( T_2 * ) V_77 , ( T_2 * ) V_76 , F_25 ( V_76 ) ) ;
}
static void F_39 ( struct V_1 * V_68 ,
struct V_57 * V_6 )
{
struct V_7 * V_8 = & V_68 -> V_9 ;
if ( F_35 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_38 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_68 ) ;
F_40 ( V_68 ,
( V_8 -> V_13 . V_14 . V_80 ) +
sizeof( struct V_99 ) ,
V_8 -> V_13 . V_14 . V_65 ) ;
}
}
static void F_41 ( struct V_1 * V_68 ,
struct V_57 * V_100 )
{
struct V_36 * V_37 , * V_47 ;
T_3 V_101 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_34 * V_27 = & V_8 -> V_20 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_88 = NULL ;
V_47 = F_18 ( V_27 ) ;
V_37 = F_12 ( V_47 ) ;
while ( 1 ) {
if ( F_21 ( V_47 , V_37 ) == true )
break;
V_6 = F_13 ( V_37 , struct V_5 , V_26 ) ;
if ( F_35 ( & V_6 -> V_14 , V_100 ) )
break;
if ( ( V_88 == ( (struct V_5 * ) 0 ) ) ||
F_37 ( ( unsigned long ) V_88 -> V_38 ,
( unsigned long ) V_6 -> V_38 ) )
V_88 = V_6 ;
V_37 = F_12 ( V_37 ) ;
}
if ( F_21 ( V_47 , V_37 ) == true ) {
if ( F_10 ( & V_8 -> V_19 ) == true ) {
V_6 = V_88 ;
V_100 -> V_98 = ( V_6 -> V_14 . V_98 +
V_100 -> V_98 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_100 ,
F_25 ( V_100 ) ) ;
V_6 -> V_38 = V_39 ;
} else {
V_6 = F_30 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_101 = F_25 ( V_100 ) ;
V_100 -> V_102 = V_101 ;
memcpy ( & V_6 -> V_14 , V_100 , V_101 ) ;
F_7 ( & V_6 -> V_26 , & V_27 -> V_27 ) ;
}
} else {
F_38 ( & V_6 -> V_14 , V_100 , V_68 ) ;
V_6 -> V_38 = V_39 ;
}
}
static void F_42 ( struct V_1 * V_68 ,
struct V_57 * V_6 )
{
unsigned long V_33 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_68 ) -> V_9 ) ;
struct V_34 * V_27 = & V_8 -> V_20 ;
F_11 ( & V_27 -> V_17 , V_33 ) ;
F_39 ( V_68 , V_6 ) ;
F_41 ( V_68 , V_6 ) ;
F_15 ( & V_27 -> V_17 , V_33 ) ;
}
static int F_43 ( struct V_1 * V_68 ,
struct V_5 * V_6 )
{
T_2 V_103 [ 512 ] ;
T_4 V_104 ;
int V_105 = true ;
struct V_70 * V_71 = & V_68 -> V_72 ;
if ( V_71 -> V_106 == true ) {
if ( F_44 ( V_6 -> V_14 . V_80 ,
V_6 -> V_14 . V_65 , V_103 ,
& V_104 ) == true )
return true ;
else
return false ;
}
if ( ( V_71 -> V_73 != V_74 ) &&
( V_6 -> V_14 . V_75 == 0 ) )
V_105 = false ;
return V_105 ;
}
void F_45 ( struct V_1 * V_68 , T_2 * V_4 )
{
}
void F_46 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_107 ;
T_3 V_108 ;
struct V_57 * V_6 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
V_6 = (struct V_57 * ) V_4 ;
#ifdef F_47
V_6 -> V_102 = F_48 ( V_6 -> V_102 ) ;
V_6 -> V_81 . V_82 = F_48 ( V_6 -> V_81 . V_82 ) ;
V_6 -> V_75 = F_48 ( V_6 -> V_75 ) ;
V_6 -> V_98 = F_48 ( V_6 -> V_98 ) ;
V_6 -> V_109 = F_48 ( V_6 -> V_109 ) ;
V_6 -> V_83 . V_110 =
F_48 ( V_6 -> V_83 . V_110 ) ;
V_6 -> V_83 . V_111 =
F_48 ( V_6 -> V_83 . V_111 ) ;
V_6 -> V_83 . V_84 =
F_48 ( V_6 -> V_83 . V_84 ) ;
V_6 -> V_83 . V_112 . V_113 =
F_48 ( V_6 -> V_83 . V_112 . V_113 ) ;
V_6 -> V_83 . V_112 . V_114 =
F_48 ( V_6 -> V_83 . V_112 . V_114 ) ;
V_6 -> V_83 . V_112 . V_115 =
F_48 ( V_6 -> V_83 . V_112 . V_115 ) ;
V_6 -> V_83 . V_112 . V_102 =
F_48 ( V_6 -> V_83 . V_112 . V_102 ) ;
V_6 -> V_83 . V_102 =
F_48 ( V_6 -> V_83 . V_102 ) ;
V_6 -> V_15 =
F_48 ( V_6 -> V_15 ) ;
V_6 -> V_65 = F_48 ( V_6 -> V_65 ) ;
#endif
V_108 = F_25 ( V_6 ) ;
if ( V_108 > sizeof( struct V_116 ) )
return;
F_11 ( & V_8 -> V_18 , V_107 ) ;
if ( F_23 ( V_8 , V_117 ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_50 ) ,
V_6 -> V_50 , V_49 ) ) {
struct V_5 * V_118 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_80 ,
V_6 -> V_80 , 8 ) ;
V_118 = F_33 (
& V_8 -> V_20 ,
V_6 -> V_50 ) ;
if ( ! V_118 ) {
memcpy ( V_118 -> V_14 . V_80 ,
V_6 -> V_80 , 8 ) ;
goto exit;
}
}
}
if ( F_23 ( V_8 , V_119 ) == false ) {
if ( V_6 -> V_81 . V_81 [ 0 ] != 0 )
F_42 ( V_68 , V_6 ) ;
else {
V_6 -> V_81 . V_82 = 8 ;
memcpy ( V_6 -> V_81 . V_81 , L_1 , 8 ) ;
F_42 ( V_68 , V_6 ) ;
}
}
exit:
F_15 ( & V_8 -> V_18 , V_107 ) ;
}
void F_49 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_33 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
F_11 ( & V_8 -> V_17 , V_33 ) ;
if ( F_23 ( V_8 , V_120 ) == true ) {
T_2 V_121 ;
F_50 ( & V_8 -> V_122 , & V_121 ) ;
F_51 ( V_8 , V_120 ) ;
}
if ( V_8 -> V_123 == true ) {
if ( ( F_23 ( V_8 , V_124 ) == true ) ) {
if ( F_23 ( V_8 , V_54 ) == false ) {
F_52 ( V_8 , V_119 ) ;
if ( F_53 ( V_8 )
== V_32 )
F_54 ( & V_8 -> V_125 ,
V_126 ) ;
else {
struct V_116 * V_127 =
& ( V_68 -> V_128 . V_129 ) ;
T_2 * V_55 =
V_68 -> V_128 .
V_129 . V_50 ;
V_8 -> V_12 ^= V_120 ;
memset ( & V_127 -> V_81 , 0 ,
sizeof( struct
V_22 ) ) ;
memcpy ( & V_127 -> V_81 ,
& V_8 -> V_21 ,
sizeof( struct
V_22 ) ) ;
F_55
( V_68 ) ;
F_24 ( V_55 ) ;
V_8 -> V_12 =
V_117 ;
V_8 -> V_123 = false ;
}
}
} else {
V_8 -> V_123 = false ;
F_52 ( V_8 , V_119 ) ;
if ( F_53 ( V_8 ) ==
V_32 )
F_54 ( & V_8 -> V_125 ,
V_126 ) ;
else
F_51 ( V_8 , V_119 ) ;
}
}
F_15 ( & V_8 -> V_17 , V_33 ) ;
}
void F_56 ( struct V_1 * V_68 )
{
unsigned long V_33 ;
struct V_5 * V_87 = NULL ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_5 * V_133 = & V_8 -> V_13 ;
V_87 = F_33 ( & V_8 -> V_20 ,
V_133 -> V_14 . V_50 ) ;
if ( F_23 ( V_8 , V_134 | V_135 ) ) {
struct V_136 * V_137 ;
V_137 = F_57 ( & V_68 -> V_132 ,
V_133 -> V_14 . V_50 ) ;
F_11 ( & V_131 -> V_138 , V_33 ) ;
F_58 ( V_68 , V_137 ) ;
F_15 ( & V_131 -> V_138 , V_33 ) ;
}
if ( F_23 ( V_8 ,
V_124 | V_117 | V_135 ) )
F_59 ( V_68 ) ;
if ( V_87 )
V_87 -> V_43 = false ;
if ( ( ( F_23 ( V_8 , V_117 ) ) &&
( V_68 -> V_132 . V_139 == 1 ) ) )
F_31 ( V_8 , V_87 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_123 = false ;
F_52 ( V_8 , V_54 ) ;
V_2 -> V_140 . V_141 ( V_2 , V_142 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_128 . V_143 > V_144 )
F_54 ( & V_8 -> V_145 , 60000 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_51 ( V_8 , V_54 ) ;
V_2 -> V_140 . V_141 ( V_2 , V_146 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_147 . V_148 !=
V_2 -> V_128 . V_143 ) {
F_64 ( & V_8 -> V_145 ) ;
F_65 ( V_2 , V_2 -> V_128 . V_143 ,
V_2 -> V_128 . V_149 ) ;
}
}
void F_66 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_33 = 0 , V_150 ;
T_2 V_121 ;
struct V_136 * V_151 = NULL , * V_152 = NULL ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_153 = NULL , * V_154 = NULL ;
unsigned int V_155 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_36 ) == 4 * sizeof( T_3 ) ) {
V_6 = (struct V_5 * )
F_5 ( sizeof( struct V_5 ) ) ;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else
V_6 = (struct V_5 * ) V_4 ;
#ifdef F_47
V_6 -> V_156 = F_48 ( V_6 -> V_156 ) ;
V_6 -> V_157 = F_48 ( V_6 -> V_157 ) ;
V_6 -> V_14 . V_102 = F_48 ( V_6 -> V_14 . V_102 ) ;
V_6 -> V_14 . V_81 . V_82 =
F_48 ( V_6 -> V_14 . V_81 . V_82 ) ;
V_6 -> V_14 . V_75 = F_48 ( V_6 -> V_14 . V_75 ) ;
V_6 -> V_14 . V_98 = F_48 ( V_6 -> V_14 . V_98 ) ;
V_6 -> V_14 . V_109 =
F_48 ( V_6 -> V_14 . V_109 ) ;
V_6 -> V_14 . V_83 . V_110 =
F_48 ( V_6 -> V_14 . V_83 . V_110 ) ;
V_6 -> V_14 . V_83 . V_111 =
F_48 ( V_6 -> V_14 . V_83 . V_111 ) ;
V_6 -> V_14 . V_83 . V_84 =
F_48 ( V_6 -> V_14 . V_83 . V_84 ) ;
V_6 -> V_14 . V_83 . V_112 . V_113 =
F_48 ( V_6 -> V_14 . V_83 . V_112 .
V_113 ) ;
V_6 -> V_14 . V_83 . V_112 . V_114 =
F_48 ( V_6 -> V_14 . V_83 .
V_112 . V_114 ) ;
V_6 -> V_14 . V_83 . V_112 . V_115 =
F_48 ( V_6 -> V_14 . V_83 . V_112 . V_115 ) ;
V_6 -> V_14 . V_83 . V_112 . V_102 =
F_48 ( V_6 -> V_14 . V_83 . V_112 . V_102 ) ;
V_6 -> V_14 . V_83 . V_102 =
F_48 ( V_6 -> V_14 . V_83 . V_102 ) ;
V_6 -> V_14 . V_15 =
F_48 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_65 = F_48 ( V_6 -> V_14 . V_65 ) ;
#endif
V_155 = ! memcmp ( V_6 -> V_14 . V_50 ,
V_13 -> V_14 . V_50 , V_49 ) ;
V_6 -> V_14 . V_102 =
F_25 ( & V_6 -> V_14 ) ;
F_11 ( & V_8 -> V_17 , V_33 ) ;
if ( V_6 -> V_14 . V_102 > sizeof( struct V_116 ) )
goto V_158;
if ( V_6 -> V_156 > 0 ) {
if ( F_23 ( V_8 , V_119 ) == true ) {
if ( F_23 ( V_8 , V_54 ) == true ) {
if ( V_155 == true )
V_154 =
F_33 ( & V_8 ->
V_20 ,
V_13 -> V_14 . V_50 ) ;
else {
V_153 =
F_33 ( & V_8 ->
V_20 ,
V_13 -> V_14 . V_50 ) ;
V_153 -> V_43 = false ;
V_152 = F_57 ( V_131 ,
V_13 -> V_14 . V_50 ) ;
F_11 ( & V_131 ->
V_138 , V_150 ) ;
F_58 ( V_68 , V_152 ) ;
F_15 ( & ( V_131 ->
V_138 ) , V_150 ) ;
V_154 =
F_33 ( & V_8 ->
V_20 ,
V_6 -> V_14 .
V_50 ) ;
if ( V_154 )
V_154 -> V_43 = true ;
}
} else {
V_154 = F_33 ( & V_8 ->
V_20 ,
V_6 -> V_14 . V_50 ) ;
if ( V_154 )
V_154 -> V_43 = true ;
}
if ( V_154 == NULL ) {
if ( F_23 ( V_8 ,
V_119 ) )
V_8 -> V_12 ^=
V_119 ;
goto V_158;
}
if ( F_23 ( V_8 , V_134 ) ) {
if ( V_155 == true ) {
V_151 =
F_57 ( V_131 ,
V_6 -> V_14 . V_50 ) ;
if ( V_151 == NULL )
V_151 =
F_67 ( V_131 ,
V_6 -> V_14 . V_50 ) ;
} else
V_151 =
F_67 ( V_131 ,
V_6 -> V_14 . V_50 ) ;
if ( V_151 ) {
V_151 -> V_159 = V_6 -> V_156 ;
V_151 -> V_160 = 1 ;
V_151 -> V_161 = 5 ;
if ( V_68 -> V_72 .
V_162 == 2 ) {
V_68 -> V_72 .
V_163 =
false ;
V_68 -> V_72 .
V_164 =
false ;
V_68 -> V_72 .
V_165 =
false ;
V_151 -> V_166
= true ;
V_151 -> V_167 =
V_68 -> V_72 .
V_73 ;
memset ( ( T_2 * ) & V_151 ->
V_168 ,
0 ,
sizeof( union V_169 ) ) ;
memset ( ( T_2 * ) & V_151 ->
V_170 ,
0 ,
sizeof( union V_169 ) ) ;
memset ( ( T_2 * ) & V_151 ->
V_171 ,
0 ,
sizeof( union V_169 ) ) ;
memset ( ( T_2 * ) & V_151 ->
V_172 , 0 ,
sizeof( union V_173 ) ) ;
memset ( ( T_2 * ) & V_151 ->
V_174 , 0 ,
sizeof( union V_173 ) ) ;
}
} else {
if ( F_23 ( V_8 ,
V_119 ) )
V_8 -> V_12 ^=
V_119 ;
goto V_158;
}
}
memcpy ( & V_13 -> V_14 , & V_6 -> V_14 ,
V_6 -> V_14 . V_102 ) ;
V_13 -> V_159 = V_6 -> V_156 ;
switch ( V_6 -> V_14 . V_15 ) {
case V_175 :
V_8 -> V_12 = V_134 ;
break;
case V_176 :
V_8 -> V_12 = V_124 ;
break;
default:
V_8 -> V_12 = V_177 ;
break;
}
F_40 ( V_68 ,
( V_13 -> V_14 . V_80 ) +
sizeof( struct V_99 ) ,
( V_13 -> V_14 . V_65 ) ) ;
F_68 ( V_68 , V_13 -> V_14 . V_80 ,
V_13 -> V_14 . V_65 ) ;
if ( F_23 ( V_8 , V_134 )
== true )
F_60 ( V_68 ) ;
F_50 ( & V_8 -> V_125 ,
& V_121 ) ;
} else
goto V_158;
} else {
if ( F_23 ( V_8 , V_119 ) == true ) {
F_54 ( & V_8 -> V_125 , 1 ) ;
F_51 ( V_8 , V_119 ) ;
}
}
V_158:
F_15 ( & V_8 -> V_17 , V_33 ) ;
if ( sizeof( struct V_36 ) == 4 * sizeof( T_3 ) )
F_29 ( ( T_2 * ) V_6 ) ;
}
void F_69 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_33 ;
struct V_136 * V_137 ;
struct V_7 * V_8 = & ( V_68 -> V_9 ) ;
struct V_178 * V_179 = (struct V_178 * ) V_4 ;
if ( F_70 ( & V_68 -> V_180 , V_179 -> V_181 ) == false )
return;
V_137 = F_57 ( & V_68 -> V_132 , V_179 -> V_181 ) ;
if ( V_137 != NULL ) {
return;
}
V_137 = F_67 ( & V_68 -> V_132 , V_179 -> V_181 ) ;
if ( V_137 == NULL )
return;
V_137 -> V_160 = 0 ;
V_137 -> V_161 = F_48 ( ( T_4 ) V_179 -> V_182 ) ;
if ( V_68 -> V_72 . V_162 == 2 )
V_137 -> V_167 = V_68 -> V_72 . V_73 ;
V_137 -> V_166 = false ;
F_11 ( & V_8 -> V_17 , V_33 ) ;
if ( ( F_23 ( V_8 , V_117 ) == true ) ||
( F_23 ( V_8 , V_124 ) == true ) ) {
if ( V_68 -> V_132 . V_139 == 2 ) {
F_60 ( V_68 ) ;
}
}
F_15 ( & V_8 -> V_17 , V_33 ) ;
}
void F_71 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_33 , V_150 ;
struct V_136 * V_137 ;
struct V_5 * V_87 = NULL ;
struct V_116 * V_127 = NULL ;
T_2 * V_55 = NULL ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_183 * V_184 = (struct V_183 * ) V_4 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_5 * V_133 = & V_8 -> V_13 ;
F_11 ( & V_8 -> V_17 , V_150 ) ;
if ( F_23 ( V_8 , V_134 ) == true ) {
F_62 ( V_68 ) ;
F_56 ( V_68 ) ;
}
if ( F_23 ( V_8 , V_117 |
V_124 ) ) {
V_137 = F_57 ( & V_68 -> V_132 , V_184 -> V_181 ) ;
F_11 ( & V_131 -> V_138 , V_33 ) ;
F_58 ( V_68 , V_137 ) ;
F_15 ( & V_131 -> V_138 , V_33 ) ;
if ( V_68 -> V_132 . V_139 == 1 ) {
V_87 = F_33 ( & V_8 -> V_20 ,
V_133 -> V_14 . V_50 ) ;
if ( V_87 ) {
V_87 -> V_43 = false ;
F_31 ( V_8 , V_87 ) ;
}
V_127 = & ( V_68 -> V_128 . V_129 ) ;
V_55 = V_68 -> V_128 . V_129 . V_50 ;
memcpy ( V_127 , & V_133 -> V_14 ,
F_25 ( & V_133 ->
V_14 ) ) ;
memset ( & V_127 -> V_81 , 0 ,
sizeof( struct V_22 ) ) ;
memcpy ( & V_127 -> V_81 ,
& V_8 -> V_21 ,
sizeof( struct V_22 ) ) ;
F_55 ( V_68 ) ;
F_24 ( V_55 ) ;
if ( F_23 ( V_8 , V_124 ) ) {
F_51 ( V_8 , V_124 ) ;
F_52 ( V_8 , V_117 ) ;
}
}
}
F_15 ( & V_8 -> V_17 , V_150 ) ;
}
void F_72 ( struct V_1 * V_68 , T_2 * V_4 )
{
struct V_185 * V_186 =
(struct V_185 * ) V_4 ;
V_186 -> V_187 |= ( T_2 ) ( V_68 -> V_147 . V_188 + 0x80 ) ;
F_73 ( V_68 , V_186 ) ;
}
void F_74 ( struct V_1 * V_68 , T_2 * V_4 )
{
struct V_189 * V_190 =
(struct V_189 * ) V_4 ;
struct V_136 * V_137 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_191 * V_192 = NULL ;
F_75 ( V_193 L_2 ,
V_194 , V_190 -> V_50 ,
V_190 -> V_195 , V_190 -> V_196 ) ;
V_137 = F_57 ( V_131 , V_190 -> V_50 ) ;
if ( V_137 ) {
V_192 =
& V_137 -> V_197 [ V_190 -> V_196 ] ;
V_192 -> V_198 = 0xffff ;
}
}
void F_76 ( struct V_1 * V_68 , T_2 * V_4 )
{
if ( V_68 -> V_72 . V_199 == false )
V_68 -> V_72 . V_199 = true ;
}
void F_77 ( struct V_1 * V_68 )
{
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_200 * V_201 = & V_8 -> V_28 ;
struct V_202 * V_203 = & V_68 -> V_128 ;
T_6 V_204 ;
T_4 V_205 ;
V_204 = ( V_68 -> V_206 . V_207 ) -
( V_201 -> V_30 ) ;
V_205 = ( V_68 -> V_91 . V_208 ) -
( V_201 -> V_29 ) ;
V_201 -> V_30 = V_68 -> V_206 . V_207 ;
V_201 -> V_29 = V_68 -> V_91 . V_208 ;
if ( ( V_204 > V_203 -> V_209 ) ||
( V_205 > V_203 -> V_209 ) )
V_201 -> V_31 = true ;
else
V_201 -> V_31 = false ;
}
void F_78 ( struct V_1 * V_68 )
{
unsigned long V_33 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
if ( V_68 -> V_52 || V_68 -> V_53 )
return;
F_11 ( & V_8 -> V_17 , V_33 ) ;
F_51 ( V_8 , V_119 ) ;
V_8 -> V_123 = false ;
if ( F_23 ( V_8 , V_54 ) == true ) {
F_63 ( V_68 ) ;
F_51 ( V_8 , V_54 ) ;
}
if ( V_68 -> V_147 . V_148 != V_68 -> V_128 . V_143 ) {
F_65 ( V_68 , V_68 -> V_128 . V_143 ,
V_68 -> V_128 . V_149 ) ;
}
F_15 ( & V_8 -> V_17 , V_33 ) ;
}
void F_79 ( struct V_1 * V_68 )
{
unsigned long V_33 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
F_11 ( & V_8 -> V_17 , V_33 ) ;
F_51 ( V_8 , V_120 ) ;
V_8 -> V_123 = false ;
F_15 ( & V_8 -> V_17 , V_33 ) ;
}
void F_80 ( struct V_1 * V_68 )
{
if ( V_68 -> V_52 || V_68 -> V_53 )
return;
if ( V_68 -> V_147 . V_148 != V_68 -> V_128 . V_143 )
F_65 ( V_68 , V_68 -> V_128 . V_143 ,
V_68 -> V_128 . V_149 ) ;
}
void F_81 ( struct V_1 * V_68 )
{
F_82 ( V_68 ) ;
}
int F_53 ( struct V_7 * V_8 )
{
struct V_36 * V_47 ;
unsigned char * V_210 , * V_211 ;
struct V_1 * V_68 ;
struct V_34 * V_27 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_212 = NULL ;
V_68 = (struct V_1 * ) V_8 -> V_10 ;
V_27 = & V_8 -> V_20 ;
V_47 = F_18 ( V_27 ) ;
V_8 -> V_11 = F_12 ( V_47 ) ;
while ( 1 ) {
if ( F_21 ( V_47 , V_8 -> V_11 ) == true ) {
if ( ( V_8 -> V_213 == true ) &&
( V_212 != NULL ) ) {
V_6 = V_212 ;
goto V_214;
}
return V_24 ;
}
V_6 = F_13 ( V_8 -> V_11 ,
struct V_5 , V_26 ) ;
if ( V_6 == NULL )
return V_24 ;
V_8 -> V_11 = F_12 ( V_8 -> V_11 ) ;
if ( V_8 -> V_215 == true ) {
V_210 = V_6 -> V_14 . V_50 ;
V_211 = V_8 -> V_216 ;
if ( ! memcmp ( V_210 , V_211 , V_49 ) ) {
if ( F_23 ( V_8 , V_54 ) ) {
if ( F_35 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_51 ( V_8 ,
V_119 ) ;
F_60 ( V_68 ) ;
return 2 ;
}
F_83 ( V_68 ) ;
F_62 ( V_68 ) ;
F_56 ( V_68 ) ;
}
goto V_214;
}
} else if ( V_8 -> V_21 . V_82 == 0 )
goto V_214;
V_210 = V_6 -> V_14 . V_81 . V_81 ;
V_211 = V_8 -> V_21 . V_81 ;
if ( ( V_6 -> V_14 . V_81 . V_82 ==
V_8 -> V_21 . V_82 ) &&
( ! memcmp ( V_210 , V_211 ,
V_8 -> V_21 . V_82 ) ) ) {
if ( V_8 -> V_213 == true ) {
if ( V_212 ) {
if ( V_6 -> V_14 . V_98 >
V_212 -> V_14 . V_98 )
V_212 = V_6 ;
} else
V_212 = V_6 ;
} else if ( F_43 ( V_68 , V_6 ) ) {
if ( F_23 ( V_8 , V_54 ) ) {
F_83 ( V_68 ) ;
F_56 ( V_68 ) ;
}
goto V_214;
}
}
}
return V_24 ;
V_214:
return F_84 ( V_68 , V_6 ) ;
}
T_1 F_85 ( struct V_1 * V_68 ,
struct V_70 * V_71 )
{
struct V_217 * V_218 = & V_68 -> V_219 ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
T_1 V_69 = V_32 ;
V_221 = (struct V_220 * ) F_5 ( sizeof( struct V_220 ) ) ;
if ( V_221 == NULL )
return V_24 ;
V_223 = (struct V_222 * ) F_5 (
sizeof( struct V_222 ) ) ;
if ( V_223 == NULL ) {
F_29 ( ( unsigned char * ) V_221 ) ;
return V_24 ;
}
memset ( V_223 , 0 , sizeof( struct V_222 ) ) ;
V_223 -> V_224 = ( T_2 ) V_71 -> V_162 ;
V_221 -> V_225 = V_226 ;
V_221 -> V_227 = ( unsigned char * ) V_223 ;
V_221 -> V_228 = sizeof( struct V_222 ) ;
V_221 -> V_229 = NULL ;
V_221 -> V_230 = 0 ;
F_6 ( & V_221 -> V_26 ) ;
F_86 ( V_218 , V_221 ) ;
return V_69 ;
}
T_1 F_87 ( struct V_1 * V_68 ,
struct V_70 * V_71 ,
T_1 V_231 )
{
struct V_217 * V_218 = & V_68 -> V_219 ;
struct V_220 * V_221 ;
struct V_232 * V_233 ;
T_2 V_234 ;
V_221 = (struct V_220 * ) F_5 ( sizeof( struct V_220 ) ) ;
if ( V_221 == NULL )
return V_24 ;
V_233 = (struct V_232 * ) F_5 ( sizeof( struct V_232 ) ) ;
if ( V_233 == NULL ) {
F_29 ( ( unsigned char * ) V_221 ) ;
return V_24 ;
}
memset ( V_233 , 0 , sizeof( struct V_232 ) ) ;
if ( V_71 -> V_162 == 2 ) {
V_233 -> V_235 =
( T_2 ) V_71 -> V_236 ;
} else {
V_233 -> V_235 =
( T_2 ) V_71 -> V_73 ;
}
V_233 -> V_231 = ( T_2 ) V_231 ;
switch ( V_233 -> V_235 ) {
case V_237 :
V_234 = 5 ;
memcpy ( V_233 -> V_238 ,
V_71 -> V_239 [ V_231 ] . V_240 , V_234 ) ;
break;
case V_241 :
V_234 = 13 ;
memcpy ( V_233 -> V_238 ,
V_71 -> V_239 [ V_231 ] . V_240 , V_234 ) ;
break;
case V_242 :
V_234 = 16 ;
memcpy ( V_233 -> V_238 ,
& V_71 -> V_243 [ V_231 - 1 ] , V_234 ) ;
V_233 -> V_244 = 1 ;
break;
case V_245 :
V_234 = 16 ;
memcpy ( V_233 -> V_238 ,
& V_71 -> V_243 [ V_231 - 1 ] , V_234 ) ;
V_233 -> V_244 = 1 ;
break;
default:
return V_24 ;
}
V_221 -> V_225 = V_246 ;
V_221 -> V_227 = ( T_2 * ) V_233 ;
V_221 -> V_228 = ( sizeof( struct V_232 ) ) ;
V_221 -> V_229 = NULL ;
V_221 -> V_230 = 0 ;
F_6 ( & V_221 -> V_26 ) ;
F_86 ( V_218 , V_221 ) ;
return V_32 ;
}
int F_88 ( struct V_1 * V_68 , T_2 * V_247 , T_2 * V_248 ,
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
static int F_89 ( struct V_1 * V_253 , T_2 * V_254 )
{
struct V_70 * V_71 = & V_253 -> V_72 ;
int V_3 = 0 ;
do {
if ( V_71 -> V_255 [ V_3 ] . V_256 &&
( ! memcmp ( V_71 -> V_255 [ V_3 ] . V_257 ,
V_254 , V_49 ) ) )
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
T_1 F_90 ( struct V_1 * V_68 , T_2 * V_247 ,
T_2 * V_248 , T_4 V_249 )
{
T_2 V_259 = 0 , V_260 , V_261 ;
T_2 V_262 [ 255 ] , V_263 [ 4 ] , V_264 [ 255 ] ;
T_2 V_265 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_251 , V_266 , V_267 ;
int V_268 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_70 * V_71 = & V_68 -> V_72 ;
T_4 V_269 = V_71 -> V_270 ;
T_4 V_271 = V_71 -> V_272 ;
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
V_260 = V_237 ;
V_263 [ 3 ] = 0x1 ;
break;
case V_281 :
case V_282 :
V_260 = V_242 ;
V_263 [ 3 ] = 0x2 ;
break;
case V_283 :
case V_284 :
V_260 = V_245 ;
V_263 [ 3 ] = 0x4 ;
break;
default:
V_260 = V_74 ;
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
V_71 -> V_236 =
V_74 ;
break;
case 0x1 :
V_71 -> V_236 =
V_237 ;
break;
case 0x2 :
V_71 -> V_236 =
V_242 ;
break;
case 0x3 :
case 0x4 :
V_71 -> V_236 =
V_245 ;
break;
case 0x5 :
V_71 -> V_236 =
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
if ( V_259 == V_278 ) {
while ( true ) {
if ( ( V_262 [ 2 ] != 0x01 ) || ( V_262 [ 3 ] != 0x0 ) ) {
V_261 = false ;
break;
}
if ( ! memcmp ( & V_262 [ 4 ] , & V_263 [ 0 ] , 3 ) ) {
switch ( V_262 [ 7 ] ) {
case 0x1 :
V_71 -> V_236 =
V_237 ;
break;
case 0x2 :
V_71 -> V_236 =
V_242 ;
break;
case 0x4 :
V_71 -> V_236 =
V_245 ;
break;
case 0x5 :
V_71 -> V_236 =
V_241 ;
break;
default:
V_71 -> V_236 =
V_74 ;
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
F_91 ( V_68 , V_259 , V_262 ) ;
}
} else {
memcpy ( V_248 , V_247 , 12 ) ;
V_251 = 12 ;
if ( V_71 -> V_106 == true ) {
memcpy ( V_248 + V_251 , V_71 -> V_103 ,
V_71 -> V_285 ) ;
V_251 += V_71 -> V_285 ;
}
}
V_268 = F_89 ( V_68 , V_8 -> V_216 ) ;
if ( V_268 < 0 )
return V_251 ;
else {
if ( V_259 == V_278 ) {
V_248 [ V_251 ] = 1 ;
V_251 ++ ;
V_248 [ V_251 ] = 0 ;
V_251 ++ ;
memcpy ( & V_248 [ V_251 ] ,
& V_71 -> V_255 [ V_268 ] . V_286 , 16 ) ;
V_251 += 16 ;
V_248 [ 13 ] += 18 ;
}
}
return V_251 ;
}
void F_92 ( struct V_1 * V_68 )
{
struct V_202 * V_203 = & V_68 -> V_128 ;
struct V_287 * V_288 = & V_68 -> V_289 ;
struct V_116 * V_127 = & V_203 -> V_129 ;
T_2 * V_290 = F_93 ( V_288 ) ;
memcpy ( V_127 -> V_50 , V_290 , V_49 ) ;
memcpy ( & V_127 -> V_81 , & V_203 -> V_291 ,
sizeof( struct V_22 ) ) ;
V_127 -> V_83 . V_102 =
sizeof( struct V_62 ) ;
V_127 -> V_83 . V_111 = 100 ;
V_127 -> V_83 . V_112 . V_102 = 0 ;
V_127 -> V_83 . V_112 . V_114 = 0 ;
V_127 -> V_83 . V_112 . V_115 = 0 ;
V_127 -> V_83 . V_112 . V_113 = 0 ;
}
void F_55 ( struct V_1 * V_68 )
{
int V_292 = 0 ;
struct V_202 * V_203 = & V_68 -> V_128 ;
struct V_116 * V_127 = & V_203 -> V_129 ;
struct V_70 * V_71 = & V_68 -> V_72 ;
struct V_5 * V_13 = & V_68 -> V_9 . V_13 ;
V_127 -> V_75 = F_94 ( V_71 -> V_73
> 0 ? 1 : 0 ) ;
V_127 -> V_98 = 0 ;
switch ( V_203 -> V_293 ) {
case V_294 :
V_127 -> V_109 = F_94 ( V_295 ) ;
break;
case V_296 :
case V_297 :
V_127 -> V_109 = F_94 ( V_298 ) ;
break;
case V_299 :
V_127 -> V_109 = F_94 ( V_300 ) ;
break;
default:
break;
}
V_127 -> V_83 . V_84 = F_94 (
V_203 -> V_301 ) ;
if ( V_13 -> V_14 . V_15 == V_176 )
V_127 -> V_83 . V_110 = F_94 ( 3 ) ;
V_127 -> V_15 = F_94 (
V_13 -> V_14 . V_15 ) ;
V_292 = F_95 ( V_203 , V_68 ) ;
V_127 -> V_65 = V_292 ;
V_127 -> V_102 = F_25 (
(struct V_57 * ) V_127 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
V_303 -> V_305 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_303 -> V_306 [ V_3 ] = false ;
if ( V_303 -> V_307 ) {
F_97 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_97 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_98 ( struct V_1 * V_2 , T_2 * V_247 ,
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
V_311 = F_99 ( V_247 + 12 , V_319 , & V_309 , V_249 - 12 ) ;
if ( V_311 && ( V_309 > 0 ) ) {
if ( V_317 -> V_160 == 0 ) {
V_310 = * V_308 ;
V_312 = F_100 ( V_248 + V_310 ,
V_320 ,
V_321 ,
V_315 , V_308 ) ;
V_317 -> V_160 = 1 ;
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
V_312 = F_100 ( V_248 + V_310 , V_319 ,
sizeof( struct V_313 ) ,
( unsigned char * ) & V_314 , V_308 ) ;
V_303 -> V_307 = 1 ;
}
return V_303 -> V_307 ;
}
static void F_68 ( struct V_1 * V_2 , T_2 * V_332 , T_4 V_333 )
{
T_2 * V_311 , V_334 ;
int V_3 , V_108 ;
struct V_136 * V_335 , * V_137 ;
struct V_313 * V_336 ;
struct V_337 * V_338 ;
struct V_191 * V_339 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
struct V_202 * V_203 = & V_2 -> V_128 ;
struct V_5 * V_340 = & ( V_8 -> V_13 ) ;
if ( ! V_303 -> V_307 )
return;
if ( ( V_303 -> V_305 == false ) &&
( V_203 -> V_305 == 1 ) )
V_303 -> V_305 = true ;
V_108 = 0 ;
V_311 = F_99 ( V_332 + sizeof( struct V_99 ) ,
V_319 ,
& V_108 , V_333 -
sizeof( struct V_99 ) ) ;
if ( V_311 && V_108 > 0 ) {
V_336 = (struct V_313 * ) ( V_311 + 2 ) ;
V_334 = ( V_336 -> V_329 &
V_330 ) ;
V_334 = 1 << ( V_334 + 3 ) ;
V_303 -> V_341 = V_334 ;
}
V_335 = F_101 ( V_2 ) ;
if ( V_335 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_339 = & V_335 -> V_197 [ V_3 ] ;
V_339 -> V_198 = 0xffff ;
V_339 -> V_342 = 0xffff ;
}
}
V_137 = F_57 ( & V_2 -> V_132 ,
V_340 -> V_14 . V_50 ) ;
if ( V_137 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_339 = & V_137 -> V_197 [ V_3 ] ;
V_339 -> V_198 = 0xffff ;
V_339 -> V_342 = 0xffff ;
}
}
V_108 = 0 ;
V_311 = F_99 ( V_332 + sizeof( struct V_99 ) ,
V_343 , & V_108 ,
V_333 - sizeof( struct V_99 ) ) ;
if ( V_311 && V_108 > 0 )
V_338 = (struct V_337 * ) ( V_311 + 2 ) ;
}
void F_102 ( struct V_1 * V_2 , int V_344 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
if ( ( V_303 -> V_307 == 1 ) && ( V_303 -> V_305 == true ) ) {
if ( V_303 -> V_306 [ V_344 ] == false ) {
F_103 ( V_2 , ( T_2 ) V_344 ) ;
V_303 -> V_306 [ V_344 ] = true ;
}
}
}
unsigned int F_104 ( struct V_1 * V_2 ,
T_2 * V_247 , T_2 * V_248 ,
T_4 V_249 , T_4 * V_308 )
{
T_3 V_309 , V_310 = 0 ;
unsigned char * V_311 , * V_312 ;
struct V_337 V_345 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_302 * V_303 = & V_8 -> V_304 ;
struct V_202 * V_203 = & V_2 -> V_128 ;
V_310 = * V_308 ;
if ( V_203 -> V_346 == 1 ) {
V_311 = F_99 ( V_247 + 12 , V_343 ,
& V_309 , V_249 - 12 ) ;
if ( V_311 && ( V_309 > 0 ) ) {
;
} else {
if ( V_311 == NULL ) {
int V_292 = sizeof( struct V_337 ) ;
memset ( & V_345 , 0 , V_292 ) ;
V_345 . V_347 =
V_203 -> V_301 ;
V_312 = F_100 ( V_248 + V_310 ,
V_343 ,
V_292 ,
( unsigned char * ) & V_345 ,
V_308 ) ;
}
}
}
return V_303 -> V_307 ;
}
