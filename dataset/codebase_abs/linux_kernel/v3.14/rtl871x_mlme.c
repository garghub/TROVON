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
if ( F_20 ( V_47 ) )
return NULL ;
F_11 ( & V_21 -> V_18 , V_34 ) ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( V_38 != V_48 ) {
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
V_38 = F_12 ( V_38 ) ;
if ( ! memcmp ( V_47 , V_6 -> V_14 . V_49 , V_50 ) )
break;
}
F_15 ( & V_21 -> V_18 , V_34 ) ;
return V_6 ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
struct V_37 * V_48 , * V_38 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_35 * V_21 = & V_8 -> V_21 ;
F_11 ( & V_21 -> V_18 , V_34 ) ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( F_22 ( V_48 , V_38 ) == false ) {
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
V_38 = F_12 ( V_38 ) ;
F_16 ( V_8 , V_6 ) ;
}
F_15 ( & V_21 -> V_18 , V_34 ) ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
T_1 V_51 ;
if ( V_2 -> V_52 || V_2 -> V_53 ||
( F_24 ( & V_2 -> V_9 , V_54 ) == false ) ) {
V_51 = false ;
} else
V_51 = true ;
return V_51 ;
}
void F_25 ( T_2 * V_55 )
{
T_3 V_56 = V_40 ;
V_55 [ 0 ] = 0x02 ;
V_55 [ 1 ] = 0x11 ;
V_55 [ 2 ] = 0x87 ;
V_55 [ 3 ] = ( T_2 ) ( V_56 & 0xff ) ;
V_55 [ 4 ] = ( T_2 ) ( ( V_56 >> 8 ) & 0xff ) ;
V_55 [ 5 ] = ( T_2 ) ( ( V_56 >> 16 ) & 0xff ) ;
}
T_4 F_26 ( struct V_57 * V_58 )
{
T_4 V_59 ;
V_59 = sizeof( T_3 ) + 6 * sizeof( unsigned long ) + 2 +
sizeof( struct V_23 ) + sizeof( T_3 ) +
sizeof( V_60 ) +
sizeof( enum V_61 ) +
sizeof( struct V_62 ) +
sizeof( enum V_63 ) +
sizeof( V_64 ) +
sizeof( T_3 ) + V_58 -> V_65 ;
return V_59 ;
}
T_2 * F_27 ( T_2 * V_66 )
{
return V_66 + 8 + 2 ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
F_30 ( V_8 -> V_26 ) ;
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
void F_33 ( struct V_1 * V_67 )
{
F_21 ( V_67 ) ;
}
static struct V_5 * F_34 ( struct V_35 * V_21 ,
T_2 * V_47 )
{
struct V_5 * V_6 = F_19 ( V_21 ,
V_47 ) ;
return V_6 ;
}
int F_35 ( struct V_1 * V_68 , struct V_5 * V_6 )
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
static int F_36 ( struct V_57 * V_76 ,
struct V_57 * V_77 )
{
T_5 V_78 , V_79 ;
memcpy ( ( T_2 * ) & V_78 , F_27 ( V_76 -> V_80 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_79 , F_27 ( V_77 -> V_80 ) , 2 ) ;
return ( V_76 -> V_81 . V_82 == V_77 -> V_81 . V_82 ) &&
( V_76 -> V_83 . V_84 ==
V_77 -> V_83 . V_84 ) &&
( ( ! memcmp ( V_76 -> V_49 , V_77 -> V_49 ,
V_50 ) ) ) &&
( ( ! memcmp ( V_76 -> V_81 . V_81 ,
V_77 -> V_81 . V_81 ,
V_76 -> V_81 . V_82 ) ) ) &&
( ( V_78 & V_85 ) ==
( V_79 & V_85 ) ) &&
( ( V_78 & V_86 ) ==
( V_79 & V_86 ) ) ;
}
struct V_5 * F_37 (
struct V_35 * V_21 )
{
struct V_37 * V_38 , * V_48 ;
struct V_5 * V_87 = NULL ;
struct V_5 * V_88 = NULL ;
V_48 = F_18 ( V_21 ) ;
V_38 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_22 ( V_48 , V_38 ) == true )
break;
V_87 = F_13 ( V_38 , struct V_5 , V_27 ) ;
if ( V_87 -> V_44 != true ) {
if ( V_88 == NULL ||
F_38 ( ( unsigned long ) V_88 -> V_39 ,
( unsigned long ) V_87 -> V_39 ) )
V_88 = V_87 ;
}
V_38 = F_12 ( V_38 ) ;
}
return V_88 ;
}
static void F_39 ( struct V_57 * V_77 ,
struct V_57 * V_76 ,
struct V_1 * V_2 )
{
T_3 V_89 = 0 , V_90 ;
if ( F_24 ( & V_2 -> V_9 , V_54 ) &&
F_36 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_76 ) ) {
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
memcpy ( ( T_2 * ) V_77 , ( T_2 * ) V_76 , F_26 ( V_76 ) ) ;
}
static void F_40 ( struct V_1 * V_68 ,
struct V_57 * V_6 )
{
struct V_7 * V_8 = & V_68 -> V_9 ;
if ( F_36 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_39 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_68 ) ;
F_41 ( V_68 ,
( V_8 -> V_13 . V_14 . V_80 ) +
sizeof( struct V_99 ) ,
V_8 -> V_13 . V_14 . V_65 ) ;
}
}
static void F_42 ( struct V_1 * V_68 ,
struct V_57 * V_100 )
{
struct V_37 * V_38 , * V_48 ;
T_3 V_101 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_35 * V_28 = & V_8 -> V_21 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_88 = NULL ;
V_48 = F_18 ( V_28 ) ;
V_38 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_22 ( V_48 , V_38 ) == true )
break;
V_6 = F_13 ( V_38 , struct V_5 , V_27 ) ;
if ( F_36 ( & V_6 -> V_14 , V_100 ) )
break;
if ( ( V_88 == ( (struct V_5 * ) 0 ) ) ||
F_38 ( ( unsigned long ) V_88 -> V_39 ,
( unsigned long ) V_6 -> V_39 ) )
V_88 = V_6 ;
V_38 = F_12 ( V_38 ) ;
}
if ( F_22 ( V_48 , V_38 ) == true ) {
if ( F_10 ( & V_8 -> V_20 ) == true ) {
V_6 = V_88 ;
V_100 -> V_98 = ( V_6 -> V_14 . V_98 +
V_100 -> V_98 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_100 ,
F_26 ( V_100 ) ) ;
V_6 -> V_39 = V_40 ;
} else {
V_6 = F_31 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_101 = F_26 ( V_100 ) ;
V_100 -> V_102 = V_101 ;
memcpy ( & V_6 -> V_14 , V_100 , V_101 ) ;
F_7 ( & V_6 -> V_27 , & V_28 -> V_28 ) ;
}
} else {
F_39 ( & V_6 -> V_14 , V_100 , V_68 ) ;
V_6 -> V_39 = V_40 ;
}
}
static void F_43 ( struct V_1 * V_68 ,
struct V_57 * V_6 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_68 ) -> V_9 ) ;
struct V_35 * V_28 = & V_8 -> V_21 ;
F_11 ( & V_28 -> V_18 , V_34 ) ;
F_40 ( V_68 , V_6 ) ;
F_42 ( V_68 , V_6 ) ;
F_15 ( & V_28 -> V_18 , V_34 ) ;
}
static int F_44 ( struct V_1 * V_68 ,
struct V_5 * V_6 )
{
T_2 V_103 [ 512 ] ;
T_4 V_104 ;
int V_105 = true ;
struct V_70 * V_71 = & V_68 -> V_72 ;
if ( V_71 -> V_106 == true ) {
if ( F_45 ( V_6 -> V_14 . V_80 ,
V_6 -> V_14 . V_65 , V_103 ,
& V_104 ) == true )
return true ;
else
return false ;
}
if ( ( V_71 -> V_73 != V_74 ) &&
( V_6 -> V_14 . V_75 == 0 ) )
V_105 = false ;
if ( F_24 ( & V_68 -> V_9 , V_107 ) == true ) {
if ( V_6 -> V_14 . V_15 !=
V_68 -> V_9 . V_13 . V_14 .
V_15 )
V_105 = false ;
}
return V_105 ;
}
void F_46 ( struct V_1 * V_68 , T_2 * V_4 )
{
}
void F_47 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_108 ;
T_3 V_109 ;
struct V_57 * V_6 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
V_6 = (struct V_57 * ) V_4 ;
#ifdef F_48
V_6 -> V_102 = F_49 ( V_6 -> V_102 ) ;
V_6 -> V_81 . V_82 = F_49 ( V_6 -> V_81 . V_82 ) ;
V_6 -> V_75 = F_49 ( V_6 -> V_75 ) ;
V_6 -> V_98 = F_49 ( V_6 -> V_98 ) ;
V_6 -> V_110 = F_49 ( V_6 -> V_110 ) ;
V_6 -> V_83 . V_111 =
F_49 ( V_6 -> V_83 . V_111 ) ;
V_6 -> V_83 . V_112 =
F_49 ( V_6 -> V_83 . V_112 ) ;
V_6 -> V_83 . V_84 =
F_49 ( V_6 -> V_83 . V_84 ) ;
V_6 -> V_83 . V_113 . V_114 =
F_49 ( V_6 -> V_83 . V_113 . V_114 ) ;
V_6 -> V_83 . V_113 . V_115 =
F_49 ( V_6 -> V_83 . V_113 . V_115 ) ;
V_6 -> V_83 . V_113 . V_116 =
F_49 ( V_6 -> V_83 . V_113 . V_116 ) ;
V_6 -> V_83 . V_113 . V_102 =
F_49 ( V_6 -> V_83 . V_113 . V_102 ) ;
V_6 -> V_83 . V_102 =
F_49 ( V_6 -> V_83 . V_102 ) ;
V_6 -> V_15 =
F_49 ( V_6 -> V_15 ) ;
V_6 -> V_65 = F_49 ( V_6 -> V_65 ) ;
#endif
V_109 = F_26 ( V_6 ) ;
if ( V_109 > sizeof( struct V_117 ) )
return;
F_11 ( & V_8 -> V_19 , V_108 ) ;
if ( F_24 ( V_8 , V_118 ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_49 ) ,
V_6 -> V_49 , V_50 ) ) {
struct V_5 * V_119 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_80 ,
V_6 -> V_80 , 8 ) ;
V_119 = F_34 (
& V_8 -> V_21 ,
V_6 -> V_49 ) ;
if ( V_119 ) {
memcpy ( V_119 -> V_14 . V_80 ,
V_6 -> V_80 , 8 ) ;
goto exit;
}
}
}
if ( F_24 ( V_8 , V_120 ) == false ) {
if ( V_6 -> V_81 . V_81 [ 0 ] != 0 )
F_43 ( V_68 , V_6 ) ;
else {
V_6 -> V_81 . V_82 = 8 ;
memcpy ( V_6 -> V_81 . V_81 , L_1 , 8 ) ;
F_43 ( V_68 , V_6 ) ;
}
}
exit:
F_15 ( & V_8 -> V_19 , V_108 ) ;
}
void F_50 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( F_24 ( V_8 , V_121 ) == true ) {
T_2 V_122 ;
F_51 ( & V_8 -> V_123 , & V_122 ) ;
F_52 ( V_8 , V_121 ) ;
}
if ( V_8 -> V_124 == true ) {
if ( ( F_24 ( V_8 , V_107 ) == true ) ) {
if ( F_24 ( V_8 , V_54 ) == false ) {
F_53 ( V_8 , V_120 ) ;
if ( F_54 ( V_8 )
== V_33 )
F_55 ( & V_8 -> V_125 ,
V_126 ) ;
else {
struct V_117 * V_127 =
& ( V_68 -> V_128 . V_129 ) ;
T_2 * V_55 =
V_68 -> V_128 .
V_129 . V_49 ;
V_8 -> V_12 ^= V_121 ;
memcpy ( & V_127 -> V_81 ,
& V_8 -> V_22 ,
sizeof( struct
V_23 ) ) ;
F_56
( V_68 ) ;
F_25 ( V_55 ) ;
V_8 -> V_12 =
V_118 ;
V_8 -> V_124 = false ;
}
}
} else {
V_8 -> V_124 = false ;
F_53 ( V_8 , V_120 ) ;
if ( F_54 ( V_8 ) ==
V_33 )
F_55 ( & V_8 -> V_125 ,
V_126 ) ;
else
F_52 ( V_8 , V_120 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_57 ( struct V_1 * V_68 )
{
unsigned long V_34 ;
struct V_5 * V_87 = NULL ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_5 * V_133 = & V_8 -> V_13 ;
V_87 = F_34 ( & V_8 -> V_21 ,
V_133 -> V_14 . V_49 ) ;
if ( F_24 ( V_8 , V_134 | V_135 ) ) {
struct V_136 * V_137 ;
V_137 = F_58 ( & V_68 -> V_132 ,
V_133 -> V_14 . V_49 ) ;
F_11 ( & V_131 -> V_138 , V_34 ) ;
F_59 ( V_68 , V_137 ) ;
F_15 ( & V_131 -> V_138 , V_34 ) ;
}
if ( F_24 ( V_8 ,
V_107 | V_118 | V_135 ) )
F_60 ( V_68 ) ;
if ( V_87 )
V_87 -> V_44 = false ;
if ( ( ( F_24 ( V_8 , V_118 ) ) &&
( V_68 -> V_132 . V_139 == 1 ) ) )
F_32 ( V_8 , V_87 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_124 = false ;
F_53 ( V_8 , V_54 ) ;
V_2 -> V_140 . V_141 ( V_2 , V_142 ) ;
F_62 ( V_2 ) ;
if ( V_2 -> V_128 . V_143 > V_144 )
F_55 ( & V_8 -> V_145 , 60000 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( F_24 ( V_8 , V_54 ) == true ) {
F_52 ( V_8 , V_54 ) ;
V_2 -> V_140 . V_141 ( V_2 , V_146 ) ;
F_64 ( V_2 ) ;
}
if ( V_2 -> V_147 . V_148 !=
V_2 -> V_128 . V_143 ) {
F_65 ( & V_8 -> V_145 ) ;
F_66 ( V_2 , V_2 -> V_128 . V_143 ,
V_2 -> V_128 . V_149 ) ;
}
}
void F_67 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_34 = 0 , V_150 ;
T_2 V_122 ;
struct V_136 * V_151 = NULL , * V_152 = NULL ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_153 = NULL , * V_154 = NULL ;
unsigned int V_155 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_37 ) == 4 * sizeof( T_3 ) ) {
V_6 = (struct V_5 * )
F_5 ( sizeof( struct V_5 ) ) ;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else
V_6 = (struct V_5 * ) V_4 ;
#ifdef F_48
V_6 -> V_156 = F_49 ( V_6 -> V_156 ) ;
V_6 -> V_157 = F_49 ( V_6 -> V_157 ) ;
V_6 -> V_14 . V_102 = F_49 ( V_6 -> V_14 . V_102 ) ;
V_6 -> V_14 . V_81 . V_82 =
F_49 ( V_6 -> V_14 . V_81 . V_82 ) ;
V_6 -> V_14 . V_75 = F_49 ( V_6 -> V_14 . V_75 ) ;
V_6 -> V_14 . V_98 = F_49 ( V_6 -> V_14 . V_98 ) ;
V_6 -> V_14 . V_110 =
F_49 ( V_6 -> V_14 . V_110 ) ;
V_6 -> V_14 . V_83 . V_111 =
F_49 ( V_6 -> V_14 . V_83 . V_111 ) ;
V_6 -> V_14 . V_83 . V_112 =
F_49 ( V_6 -> V_14 . V_83 . V_112 ) ;
V_6 -> V_14 . V_83 . V_84 =
F_49 ( V_6 -> V_14 . V_83 . V_84 ) ;
V_6 -> V_14 . V_83 . V_113 . V_114 =
F_49 ( V_6 -> V_14 . V_83 . V_113 .
V_114 ) ;
V_6 -> V_14 . V_83 . V_113 . V_115 =
F_49 ( V_6 -> V_14 . V_83 .
V_113 . V_115 ) ;
V_6 -> V_14 . V_83 . V_113 . V_116 =
F_49 ( V_6 -> V_14 . V_83 . V_113 . V_116 ) ;
V_6 -> V_14 . V_83 . V_113 . V_102 =
F_49 ( V_6 -> V_14 . V_83 . V_113 . V_102 ) ;
V_6 -> V_14 . V_83 . V_102 =
F_49 ( V_6 -> V_14 . V_83 . V_102 ) ;
V_6 -> V_14 . V_15 =
F_49 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_65 = F_49 ( V_6 -> V_14 . V_65 ) ;
#endif
V_155 = ! memcmp ( V_6 -> V_14 . V_49 ,
V_13 -> V_14 . V_49 , V_50 ) ;
V_6 -> V_14 . V_102 =
F_26 ( & V_6 -> V_14 ) ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( V_6 -> V_14 . V_102 > sizeof( struct V_117 ) )
goto V_158;
if ( V_6 -> V_156 > 0 ) {
if ( F_24 ( V_8 , V_120 ) == true ) {
if ( F_24 ( V_8 , V_54 ) == true ) {
if ( V_155 == true )
V_154 =
F_34 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_49 ) ;
else {
V_153 =
F_34 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_49 ) ;
V_153 -> V_44 = false ;
V_152 = F_58 ( V_131 ,
V_13 -> V_14 . V_49 ) ;
F_11 ( & V_131 ->
V_138 , V_150 ) ;
F_59 ( V_68 , V_152 ) ;
F_15 ( & ( V_131 ->
V_138 ) , V_150 ) ;
V_154 =
F_34 ( & V_8 ->
V_21 ,
V_6 -> V_14 .
V_49 ) ;
if ( V_154 )
V_154 -> V_44 = true ;
}
} else {
V_154 = F_34 ( & V_8 ->
V_21 ,
V_6 -> V_14 . V_49 ) ;
if ( V_154 )
V_154 -> V_44 = true ;
}
if ( V_154 == NULL ) {
if ( F_24 ( V_8 ,
V_120 ) )
V_8 -> V_12 ^=
V_120 ;
goto V_158;
}
if ( F_24 ( V_8 , V_134 ) ) {
if ( V_155 == true ) {
V_151 =
F_58 ( V_131 ,
V_6 -> V_14 . V_49 ) ;
if ( V_151 == NULL )
V_151 =
F_68 ( V_131 ,
V_6 -> V_14 . V_49 ) ;
} else
V_151 =
F_68 ( V_131 ,
V_6 -> V_14 . V_49 ) ;
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
if ( F_24 ( V_8 ,
V_120 ) )
V_8 -> V_12 ^=
V_120 ;
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
V_8 -> V_12 = V_107 ;
break;
default:
V_8 -> V_12 = V_177 ;
break;
}
F_41 ( V_68 ,
( V_13 -> V_14 . V_80 ) +
sizeof( struct V_99 ) ,
( V_13 -> V_14 . V_65 ) ) ;
F_69 ( V_68 , V_13 -> V_14 . V_80 ,
V_13 -> V_14 . V_65 ) ;
if ( F_24 ( V_8 , V_134 )
== true )
F_61 ( V_68 ) ;
F_51 ( & V_8 -> V_125 ,
& V_122 ) ;
} else
goto V_158;
} else {
if ( F_24 ( V_8 , V_120 ) == true ) {
F_55 ( & V_8 -> V_125 , 1 ) ;
F_52 ( V_8 , V_120 ) ;
}
}
V_158:
F_15 ( & V_8 -> V_18 , V_34 ) ;
if ( sizeof( struct V_37 ) == 4 * sizeof( T_3 ) )
F_30 ( ( T_2 * ) V_6 ) ;
}
void F_70 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_34 ;
struct V_136 * V_137 ;
struct V_7 * V_8 = & ( V_68 -> V_9 ) ;
struct V_178 * V_179 = (struct V_178 * ) V_4 ;
if ( F_71 ( & V_68 -> V_180 , V_179 -> V_181 ) == false )
return;
V_137 = F_58 ( & V_68 -> V_132 , V_179 -> V_181 ) ;
if ( V_137 != NULL ) {
return;
}
V_137 = F_68 ( & V_68 -> V_132 , V_179 -> V_181 ) ;
if ( V_137 == NULL )
return;
V_137 -> V_160 = 0 ;
V_137 -> V_161 = F_49 ( ( T_4 ) V_179 -> V_182 ) ;
if ( V_68 -> V_72 . V_162 == 2 )
V_137 -> V_167 = V_68 -> V_72 . V_73 ;
V_137 -> V_166 = false ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
if ( ( F_24 ( V_8 , V_118 ) == true ) ||
( F_24 ( V_8 , V_107 ) == true ) ) {
if ( V_68 -> V_132 . V_139 == 2 ) {
F_61 ( V_68 ) ;
}
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_72 ( struct V_1 * V_68 , T_2 * V_4 )
{
unsigned long V_34 , V_150 ;
struct V_136 * V_137 ;
struct V_5 * V_87 = NULL ;
struct V_117 * V_127 = NULL ;
T_2 * V_55 = NULL ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_183 * V_184 = (struct V_183 * ) V_4 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_5 * V_133 = & V_8 -> V_13 ;
F_11 ( & V_8 -> V_18 , V_150 ) ;
if ( F_24 ( V_8 , V_134 ) == true ) {
F_63 ( V_68 ) ;
F_57 ( V_68 ) ;
}
if ( F_24 ( V_8 , V_118 |
V_107 ) ) {
V_137 = F_58 ( & V_68 -> V_132 , V_184 -> V_181 ) ;
F_11 ( & V_131 -> V_138 , V_34 ) ;
F_59 ( V_68 , V_137 ) ;
F_15 ( & V_131 -> V_138 , V_34 ) ;
if ( V_68 -> V_132 . V_139 == 1 ) {
V_87 = F_34 ( & V_8 -> V_21 ,
V_133 -> V_14 . V_49 ) ;
if ( V_87 ) {
V_87 -> V_44 = false ;
F_32 ( V_8 , V_87 ) ;
}
V_127 = & ( V_68 -> V_128 . V_129 ) ;
V_55 = V_68 -> V_128 . V_129 . V_49 ;
memcpy ( V_127 , & V_133 -> V_14 ,
F_26 ( & V_133 ->
V_14 ) ) ;
memcpy ( & V_127 -> V_81 ,
& V_8 -> V_22 ,
sizeof( struct V_23 ) ) ;
F_56 ( V_68 ) ;
F_25 ( V_55 ) ;
if ( F_24 ( V_8 , V_107 ) ) {
F_52 ( V_8 , V_107 ) ;
F_53 ( V_8 , V_118 ) ;
}
}
}
F_15 ( & V_8 -> V_18 , V_150 ) ;
}
void F_73 ( struct V_1 * V_68 , T_2 * V_4 )
{
struct V_185 * V_186 =
(struct V_185 * ) V_4 ;
V_186 -> V_187 |= ( T_2 ) ( V_68 -> V_147 . V_188 + 0x80 ) ;
F_74 ( V_68 , V_186 ) ;
}
void F_75 ( struct V_1 * V_68 , T_2 * V_4 )
{
struct V_189 * V_190 =
(struct V_189 * ) V_4 ;
struct V_136 * V_137 ;
struct V_130 * V_131 = & V_68 -> V_132 ;
struct V_191 * V_192 = NULL ;
V_137 = F_58 ( V_131 , V_190 -> V_49 ) ;
if ( V_137 ) {
V_192 =
& V_137 -> V_193 [ V_190 -> V_194 ] ;
V_192 -> V_195 = 0xffff ;
}
}
void F_76 ( struct V_1 * V_68 , T_2 * V_4 )
{
if ( V_68 -> V_72 . V_196 == false )
V_68 -> V_72 . V_196 = true ;
}
void F_77 ( struct V_1 * V_68 )
{
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_197 * V_198 = & V_8 -> V_29 ;
struct V_199 * V_200 = & V_68 -> V_128 ;
T_6 V_201 ;
T_4 V_202 ;
V_201 = ( V_68 -> V_203 . V_204 ) -
( V_198 -> V_31 ) ;
V_202 = ( V_68 -> V_91 . V_205 ) -
( V_198 -> V_30 ) ;
V_198 -> V_31 = V_68 -> V_203 . V_204 ;
V_198 -> V_30 = V_68 -> V_91 . V_205 ;
if ( ( V_201 > V_200 -> V_206 ) ||
( V_202 > V_200 -> V_206 ) )
V_198 -> V_32 = true ;
else
V_198 -> V_32 = false ;
}
void F_78 ( struct V_1 * V_68 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
if ( V_68 -> V_52 || V_68 -> V_53 )
return;
F_11 ( & V_8 -> V_18 , V_34 ) ;
F_52 ( V_8 , V_120 ) ;
V_8 -> V_124 = false ;
if ( F_24 ( V_8 , V_54 ) == true ) {
F_64 ( V_68 ) ;
F_52 ( V_8 , V_54 ) ;
}
if ( V_68 -> V_147 . V_148 != V_68 -> V_128 . V_143 ) {
F_66 ( V_68 , V_68 -> V_128 . V_143 ,
V_68 -> V_128 . V_149 ) ;
}
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_79 ( struct V_1 * V_68 )
{
unsigned long V_34 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
F_11 ( & V_8 -> V_18 , V_34 ) ;
F_52 ( V_8 , V_121 ) ;
V_8 -> V_124 = false ;
F_15 ( & V_8 -> V_18 , V_34 ) ;
}
void F_80 ( struct V_1 * V_68 )
{
if ( V_68 -> V_52 || V_68 -> V_53 )
return;
if ( V_68 -> V_147 . V_148 != V_68 -> V_128 . V_143 )
F_66 ( V_68 , V_68 -> V_128 . V_143 ,
V_68 -> V_128 . V_149 ) ;
}
void F_81 ( struct V_1 * V_68 )
{
F_82 ( V_68 ) ;
}
int F_54 ( struct V_7 * V_8 )
{
struct V_37 * V_48 ;
unsigned char * V_207 , * V_208 ;
struct V_1 * V_68 ;
struct V_35 * V_28 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_209 = NULL ;
V_68 = (struct V_1 * ) V_8 -> V_10 ;
V_28 = & V_8 -> V_21 ;
V_48 = F_18 ( V_28 ) ;
V_8 -> V_11 = F_12 ( V_48 ) ;
while ( 1 ) {
if ( F_22 ( V_48 , V_8 -> V_11 ) == true ) {
if ( ( V_8 -> V_210 == true ) &&
( V_209 != NULL ) ) {
V_6 = V_209 ;
goto V_211;
}
return V_25 ;
}
V_6 = F_13 ( V_8 -> V_11 ,
struct V_5 , V_27 ) ;
if ( V_6 == NULL )
return V_25 ;
V_8 -> V_11 = F_12 ( V_8 -> V_11 ) ;
if ( V_8 -> V_212 == true ) {
V_207 = V_6 -> V_14 . V_49 ;
V_208 = V_8 -> V_213 ;
if ( ! memcmp ( V_207 , V_208 , V_50 ) ) {
if ( F_24 ( V_8 , V_54 ) ) {
if ( F_36 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_52 ( V_8 ,
V_120 ) ;
F_61 ( V_68 ) ;
return 2 ;
}
F_83 ( V_68 ) ;
F_63 ( V_68 ) ;
F_57 ( V_68 ) ;
}
goto V_211;
}
} else if ( V_8 -> V_22 . V_82 == 0 )
goto V_211;
V_207 = V_6 -> V_14 . V_81 . V_81 ;
V_208 = V_8 -> V_22 . V_81 ;
if ( ( V_6 -> V_14 . V_81 . V_82 ==
V_8 -> V_22 . V_82 ) &&
( ! memcmp ( V_207 , V_208 ,
V_8 -> V_22 . V_82 ) ) ) {
if ( V_8 -> V_210 == true ) {
if ( V_209 ) {
if ( V_6 -> V_14 . V_98 >
V_209 -> V_14 . V_98 )
V_209 = V_6 ;
} else
V_209 = V_6 ;
} else if ( F_44 ( V_68 , V_6 ) ) {
if ( F_24 ( V_8 , V_54 ) ) {
F_83 ( V_68 ) ;
F_57 ( V_68 ) ;
}
goto V_211;
}
}
}
return V_25 ;
V_211:
return F_84 ( V_68 , V_6 ) ;
}
T_1 F_85 ( struct V_1 * V_68 ,
struct V_70 * V_71 )
{
struct V_214 * V_215 = & V_68 -> V_216 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
T_1 V_69 = V_33 ;
V_218 = (struct V_217 * ) F_5 ( sizeof( struct V_217 ) ) ;
if ( V_218 == NULL )
return V_25 ;
V_220 = (struct V_219 * ) F_5 (
sizeof( struct V_219 ) ) ;
if ( V_220 == NULL ) {
F_30 ( ( unsigned char * ) V_218 ) ;
return V_25 ;
}
memset ( V_220 , 0 , sizeof( struct V_219 ) ) ;
V_220 -> V_221 = ( T_2 ) V_71 -> V_162 ;
V_218 -> V_222 = V_223 ;
V_218 -> V_224 = ( unsigned char * ) V_220 ;
V_218 -> V_225 = sizeof( struct V_219 ) ;
V_218 -> V_226 = NULL ;
V_218 -> V_227 = 0 ;
F_6 ( & V_218 -> V_27 ) ;
F_86 ( V_215 , V_218 ) ;
return V_69 ;
}
T_1 F_87 ( struct V_1 * V_68 ,
struct V_70 * V_71 ,
T_1 V_228 )
{
struct V_214 * V_215 = & V_68 -> V_216 ;
struct V_217 * V_218 ;
struct V_229 * V_230 ;
T_2 V_231 ;
V_218 = (struct V_217 * ) F_5 ( sizeof( struct V_217 ) ) ;
if ( V_218 == NULL )
return V_25 ;
V_230 = (struct V_229 * ) F_5 ( sizeof( struct V_229 ) ) ;
if ( V_230 == NULL ) {
F_30 ( ( unsigned char * ) V_218 ) ;
return V_25 ;
}
memset ( V_230 , 0 , sizeof( struct V_229 ) ) ;
if ( V_71 -> V_162 == 2 ) {
V_230 -> V_232 =
( T_2 ) V_71 -> V_233 ;
} else {
V_230 -> V_232 =
( T_2 ) V_71 -> V_73 ;
}
V_230 -> V_228 = ( T_2 ) V_228 ;
switch ( V_230 -> V_232 ) {
case V_234 :
V_231 = 5 ;
memcpy ( V_230 -> V_235 ,
V_71 -> V_236 [ V_228 ] . V_237 , V_231 ) ;
break;
case V_238 :
V_231 = 13 ;
memcpy ( V_230 -> V_235 ,
V_71 -> V_236 [ V_228 ] . V_237 , V_231 ) ;
break;
case V_239 :
if ( V_228 < 1 || V_228 > 2 )
return V_25 ;
V_231 = 16 ;
memcpy ( V_230 -> V_235 ,
& V_71 -> V_240 [ V_228 - 1 ] , V_231 ) ;
V_230 -> V_241 = 1 ;
break;
case V_242 :
if ( V_228 < 1 || V_228 > 2 )
return V_25 ;
V_231 = 16 ;
memcpy ( V_230 -> V_235 ,
& V_71 -> V_240 [ V_228 - 1 ] , V_231 ) ;
V_230 -> V_241 = 1 ;
break;
default:
return V_25 ;
}
V_218 -> V_222 = V_243 ;
V_218 -> V_224 = ( T_2 * ) V_230 ;
V_218 -> V_225 = ( sizeof( struct V_229 ) ) ;
V_218 -> V_226 = NULL ;
V_218 -> V_227 = 0 ;
F_6 ( & V_218 -> V_27 ) ;
F_86 ( V_215 , V_218 ) ;
return V_33 ;
}
int F_88 ( struct V_1 * V_68 , T_2 * V_244 , T_2 * V_245 ,
T_4 V_246 , T_4 V_247 )
{
unsigned int V_248 = 0 ;
unsigned int V_3 , V_249 ;
V_3 = 12 ;
while ( V_3 < V_246 ) {
V_248 = V_247 ;
if ( V_244 [ V_3 ] == 0xDD && V_244 [ V_3 + 2 ] == 0x00 &&
V_244 [ V_3 + 3 ] == 0x50 && V_244 [ V_3 + 4 ] == 0xF2 &&
V_244 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_246 ) {
for ( V_249 = V_3 ; V_249 < V_3 + 9 ; V_249 ++ ) {
V_245 [ V_248 ] = V_244 [ V_249 ] ;
V_248 ++ ;
}
V_245 [ V_247 + 1 ] = 0x07 ;
V_245 [ V_247 + 6 ] = 0x00 ;
V_245 [ V_247 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_244 [ V_3 + 1 ] + 2 ) ;
}
return V_248 ;
}
static int F_89 ( struct V_1 * V_250 , T_2 * V_251 )
{
struct V_70 * V_71 = & V_250 -> V_72 ;
int V_3 = 0 ;
do {
if ( V_71 -> V_252 [ V_3 ] . V_253 &&
( ! memcmp ( V_71 -> V_252 [ V_3 ] . V_254 ,
V_251 , V_50 ) ) )
break;
else
V_3 ++ ;
} while ( V_3 < V_255 );
if ( V_3 == V_255 ) {
V_3 = - 1 ;
} else {
;
}
return V_3 ;
}
T_1 F_90 ( struct V_1 * V_68 , T_2 * V_244 ,
T_2 * V_245 , T_4 V_246 )
{
T_2 V_256 = 0 , V_257 , V_258 ;
T_2 V_259 [ 255 ] , V_260 [ 4 ] , V_261 [ 255 ] ;
T_2 V_262 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_248 , V_263 , V_264 ;
int V_265 ;
struct V_7 * V_8 = & V_68 -> V_9 ;
struct V_70 * V_71 = & V_68 -> V_72 ;
T_4 V_266 = V_71 -> V_267 ;
T_4 V_268 = V_71 -> V_269 ;
if ( ( V_266 == V_270 ) ||
( V_266 == V_271 ) ) {
V_256 = V_272 ;
V_260 [ 0 ] = 0x0 ;
V_260 [ 1 ] = 0x50 ;
V_260 [ 2 ] = 0xf2 ;
}
if ( ( V_266 == V_273 ) ||
( V_266 == V_274 ) ) {
V_256 = V_275 ;
V_260 [ 0 ] = 0x0 ;
V_260 [ 1 ] = 0x0f ;
V_260 [ 2 ] = 0xac ;
}
switch ( V_268 ) {
case V_276 :
case V_277 :
V_257 = V_234 ;
V_260 [ 3 ] = 0x1 ;
break;
case V_278 :
case V_279 :
V_257 = V_239 ;
V_260 [ 3 ] = 0x2 ;
break;
case V_280 :
case V_281 :
V_257 = V_242 ;
V_260 [ 3 ] = 0x4 ;
break;
default:
V_257 = V_74 ;
break;
}
V_263 = 12 ;
V_258 = false ;
while ( V_263 < V_246 ) {
if ( V_244 [ V_263 ] == V_256 ) {
if ( ( V_256 == V_272 ) &&
( ! memcmp ( & V_244 [ V_263 + 2 ] , & V_262 [ 0 ] , 4 ) ) ) {
memcpy ( & V_259 [ 0 ] , & V_244 [ V_263 ] ,
V_244 [ V_263 + 1 ] + 2 ) ;
V_258 = true ;
break;
}
if ( V_256 == V_275 ) {
memcpy ( & V_259 [ 0 ] , & V_244 [ V_263 ] ,
V_244 [ V_263 + 1 ] + 2 ) ;
V_258 = true ;
break;
}
if ( ( ( V_256 == V_272 ) &&
( ! memcmp ( & V_244 [ V_263 + 2 ] , & V_262 [ 0 ] , 4 ) ) ) ||
( V_256 == V_275 ) )
memcpy ( & V_261 [ 0 ] , & V_244 [ V_263 ] ,
V_244 [ V_263 + 1 ] + 2 ) ;
}
V_263 += V_244 [ V_263 + 1 ] + 2 ;
}
if ( V_258 == true ) {
if ( V_259 [ 0 ] == V_272 ) {
while ( true ) {
if ( memcmp ( & V_259 [ 2 ] , & V_262 [ 0 ] , 4 ) ) {
V_258 = false ;
break;
}
if ( ( V_259 [ 6 ] != 0x01 ) || ( V_259 [ 7 ] != 0x0 ) ) {
V_258 = false ;
break;
}
if ( ! memcmp ( & V_259 [ 8 ] , & V_262 [ 0 ] , 3 ) ) {
switch ( V_259 [ 11 ] ) {
case 0x0 :
V_71 -> V_233 =
V_74 ;
break;
case 0x1 :
V_71 -> V_233 =
V_234 ;
break;
case 0x2 :
V_71 -> V_233 =
V_239 ;
break;
case 0x3 :
case 0x4 :
V_71 -> V_233 =
V_242 ;
break;
case 0x5 :
V_71 -> V_233 =
V_238 ;
break;
}
} else {
V_258 = false ;
break;
}
if ( V_259 [ 12 ] == 0x01 ) {
if ( memcmp ( & V_259 [ 14 ] ,
& V_260 [ 0 ] , 4 ) ) {
V_258 = false ;
break;
}
} else {
V_263 = V_259 [ 12 ] ;
V_264 = ( V_263 - 1 ) * 4 ;
V_259 [ 12 ] = 0x01 ;
memcpy ( & V_259 [ 14 ] , & V_260 [ 0 ] , 4 ) ;
memcpy ( & V_259 [ 18 ] ,
& V_259 [ 18 + V_264 ] ,
V_259 [ 1 ] - 18 + 2 -
V_264 ) ;
V_259 [ 1 ] = V_259 [ 1 ] - V_264 ;
}
break;
}
}
if ( V_256 == V_275 ) {
while ( true ) {
if ( ( V_259 [ 2 ] != 0x01 ) || ( V_259 [ 3 ] != 0x0 ) ) {
V_258 = false ;
break;
}
if ( ! memcmp ( & V_259 [ 4 ] , & V_260 [ 0 ] , 3 ) ) {
switch ( V_259 [ 7 ] ) {
case 0x1 :
V_71 -> V_233 =
V_234 ;
break;
case 0x2 :
V_71 -> V_233 =
V_239 ;
break;
case 0x4 :
V_71 -> V_233 =
V_242 ;
break;
case 0x5 :
V_71 -> V_233 =
V_238 ;
break;
default:
V_71 -> V_233 =
V_74 ;
break;
}
} else {
V_258 = false ;
break;
}
if ( V_259 [ 8 ] == 0x01 ) {
if ( memcmp ( & V_259 [ 10 ] ,
& V_260 [ 0 ] , 4 ) ) {
V_258 = false ;
break;
}
} else {
V_263 = V_259 [ 8 ] ;
V_264 = ( V_263 - 1 ) * 4 ;
V_259 [ 8 ] = 0x01 ;
memcpy ( & V_259 [ 10 ] , & V_260 [ 0 ] , 4 ) ;
memcpy ( & V_259 [ 14 ] ,
& V_259 [ 14 + V_264 ] ,
( V_259 [ 1 ] - 14 + 2 -
V_264 ) ) ;
V_259 [ 1 ] = V_259 [ 1 ] - V_264 ;
}
break;
}
}
}
if ( ( V_256 == V_272 ) || ( V_256 == V_275 ) ) {
memcpy ( V_245 , V_244 , 12 ) ;
V_248 = 12 ;
if ( V_258 == true ) {
memcpy ( & V_245 [ V_248 ] , & V_259 [ 0 ] , V_259 [ 1 ] + 2 ) ;
V_248 += V_259 [ 1 ] + 2 ;
if ( V_256 == V_275 ) {
V_245 [ V_248 - 1 ] = 0 ;
V_245 [ V_248 - 2 ] = 0 ;
}
F_91 ( V_68 , V_256 , V_259 ) ;
}
} else {
memcpy ( V_245 , V_244 , 12 ) ;
V_248 = 12 ;
if ( V_71 -> V_106 == true ) {
memcpy ( V_245 + V_248 , V_71 -> V_103 ,
V_71 -> V_282 ) ;
V_248 += V_71 -> V_282 ;
}
}
V_265 = F_89 ( V_68 , V_8 -> V_213 ) ;
if ( V_265 < 0 )
return V_248 ;
else {
if ( V_256 == V_275 ) {
V_245 [ V_248 ] = 1 ;
V_248 ++ ;
V_245 [ V_248 ] = 0 ;
V_248 ++ ;
memcpy ( & V_245 [ V_248 ] ,
& V_71 -> V_252 [ V_265 ] . V_283 , 16 ) ;
V_248 += 16 ;
V_245 [ 13 ] += 18 ;
}
}
return V_248 ;
}
void F_92 ( struct V_1 * V_68 )
{
struct V_199 * V_200 = & V_68 -> V_128 ;
struct V_284 * V_285 = & V_68 -> V_286 ;
struct V_117 * V_127 = & V_200 -> V_129 ;
T_2 * V_287 = F_93 ( V_285 ) ;
memcpy ( V_127 -> V_49 , V_287 , V_50 ) ;
memcpy ( & V_127 -> V_81 , & V_200 -> V_288 ,
sizeof( struct V_23 ) ) ;
V_127 -> V_83 . V_102 =
sizeof( struct V_62 ) ;
V_127 -> V_83 . V_112 = 100 ;
V_127 -> V_83 . V_113 . V_102 = 0 ;
V_127 -> V_83 . V_113 . V_115 = 0 ;
V_127 -> V_83 . V_113 . V_116 = 0 ;
V_127 -> V_83 . V_113 . V_114 = 0 ;
}
void F_56 ( struct V_1 * V_68 )
{
int V_289 = 0 ;
struct V_199 * V_200 = & V_68 -> V_128 ;
struct V_117 * V_127 = & V_200 -> V_129 ;
struct V_70 * V_71 = & V_68 -> V_72 ;
struct V_5 * V_13 = & V_68 -> V_9 . V_13 ;
V_127 -> V_75 = F_94 ( V_71 -> V_73
> 0 ? 1 : 0 ) ;
V_127 -> V_98 = 0 ;
switch ( V_200 -> V_290 ) {
case V_291 :
V_127 -> V_110 = F_94 ( V_292 ) ;
break;
case V_293 :
case V_294 :
V_127 -> V_110 = F_94 ( V_295 ) ;
break;
case V_296 :
V_127 -> V_110 = F_94 ( V_297 ) ;
break;
default:
break;
}
V_127 -> V_83 . V_84 = F_94 (
V_200 -> V_298 ) ;
if ( V_13 -> V_14 . V_15 == V_176 )
V_127 -> V_83 . V_111 = F_94 ( 3 ) ;
V_127 -> V_15 = F_94 (
V_13 -> V_14 . V_15 ) ;
V_289 = F_95 ( V_200 ) ;
V_127 -> V_65 = V_289 ;
V_127 -> V_102 = F_26 (
(struct V_57 * ) V_127 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_299 * V_300 = & V_8 -> V_301 ;
V_300 -> V_302 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_300 -> V_303 [ V_3 ] = false ;
if ( V_300 -> V_304 ) {
F_97 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_97 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_98 ( struct V_1 * V_2 , T_2 * V_244 ,
T_2 * V_245 , T_4 V_246 , T_4 * V_305 )
{
T_3 V_306 , V_307 ;
unsigned char * V_308 , * V_309 ;
struct V_310 V_311 ;
unsigned char V_312 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_313 * V_314 = & V_8 -> V_315 ;
struct V_299 * V_300 = & V_8 -> V_301 ;
V_300 -> V_304 = 0 ;
V_308 = F_99 ( V_244 + 12 , V_316 , & V_306 , V_246 - 12 ) ;
if ( V_308 && ( V_306 > 0 ) ) {
if ( V_314 -> V_160 == 0 ) {
V_307 = * V_305 ;
V_309 = F_100 ( V_245 + V_307 ,
V_317 ,
V_318 ,
V_312 , V_305 ) ;
V_314 -> V_160 = 1 ;
}
V_307 = * V_305 ;
memset ( & V_311 , 0 , sizeof( struct V_310 ) ) ;
V_311 . V_319 = V_320 |
V_321 |
V_322 |
V_323 |
V_324 |
V_325 ;
V_311 . V_326 = ( V_327 &
0x03 ) | ( V_328 & 0x00 ) ;
V_309 = F_100 ( V_245 + V_307 , V_316 ,
sizeof( struct V_310 ) ,
( unsigned char * ) & V_311 , V_305 ) ;
V_300 -> V_304 = 1 ;
}
return V_300 -> V_304 ;
}
static void F_69 ( struct V_1 * V_2 , T_2 * V_329 , T_4 V_330 )
{
T_2 * V_308 , V_331 ;
int V_3 , V_109 ;
struct V_136 * V_332 , * V_137 ;
struct V_310 * V_333 ;
struct V_334 * V_335 ;
struct V_191 * V_336 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_299 * V_300 = & V_8 -> V_301 ;
struct V_199 * V_200 = & V_2 -> V_128 ;
struct V_5 * V_337 = & ( V_8 -> V_13 ) ;
if ( ! V_300 -> V_304 )
return;
if ( ( V_300 -> V_302 == false ) &&
( V_200 -> V_302 == 1 ) )
V_300 -> V_302 = true ;
V_109 = 0 ;
V_308 = F_99 ( V_329 + sizeof( struct V_99 ) ,
V_316 ,
& V_109 , V_330 -
sizeof( struct V_99 ) ) ;
if ( V_308 && V_109 > 0 ) {
V_333 = (struct V_310 * ) ( V_308 + 2 ) ;
V_331 = ( V_333 -> V_326 &
V_327 ) ;
V_331 = 1 << ( V_331 + 3 ) ;
V_300 -> V_338 = V_331 ;
}
V_332 = F_101 ( V_2 ) ;
if ( V_332 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_336 = & V_332 -> V_193 [ V_3 ] ;
V_336 -> V_195 = 0xffff ;
V_336 -> V_339 = 0xffff ;
}
}
V_137 = F_58 ( & V_2 -> V_132 ,
V_337 -> V_14 . V_49 ) ;
if ( V_137 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_336 = & V_137 -> V_193 [ V_3 ] ;
V_336 -> V_195 = 0xffff ;
V_336 -> V_339 = 0xffff ;
}
}
V_109 = 0 ;
V_308 = F_99 ( V_329 + sizeof( struct V_99 ) ,
V_340 , & V_109 ,
V_330 - sizeof( struct V_99 ) ) ;
if ( V_308 && V_109 > 0 )
V_335 = (struct V_334 * ) ( V_308 + 2 ) ;
}
void F_102 ( struct V_1 * V_2 , int V_341 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_299 * V_300 = & V_8 -> V_301 ;
if ( ( V_300 -> V_304 == 1 ) && ( V_300 -> V_302 == true ) ) {
if ( V_300 -> V_303 [ V_341 ] == false ) {
F_103 ( V_2 , ( T_2 ) V_341 ) ;
V_300 -> V_303 [ V_341 ] = true ;
}
}
}
