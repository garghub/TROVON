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
V_4 = F_5 ( V_24 , sizeof( struct V_5 ) ,
V_25 ) ;
if ( ! V_4 )
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
F_10 ( & V_37 -> V_18 , V_35 ) ;
V_6 = F_11 ( & V_37 -> V_29 ,
struct V_5 , V_28 ) ;
if ( V_6 ) {
F_12 ( & V_6 -> V_28 ) ;
V_6 -> V_38 = V_39 ;
V_8 -> V_40 ++ ;
}
F_13 ( & V_37 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_41 , V_42 ;
unsigned long V_35 ;
struct V_36 * V_37 = & ( V_8 -> V_20 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_43 )
return;
V_41 = V_39 ;
V_42 = ( V_41 - ( T_3 ) V_6 -> V_38 ) / V_44 ;
if ( V_42 < V_45 )
return;
F_10 ( & V_37 -> V_18 , V_35 ) ;
F_12 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , & V_37 -> V_29 ) ;
V_8 -> V_40 -- ;
F_13 ( & V_37 -> V_18 , V_35 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_36 * V_37 = & V_8 -> V_20 ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_43 )
return;
F_12 ( & V_6 -> V_28 ) ;
F_7 ( & V_6 -> V_28 , & V_37 -> V_29 ) ;
V_8 -> V_40 -- ;
}
static struct V_5 * F_16 ( struct V_36 * V_21 ,
T_2 * V_46 )
{
unsigned long V_35 ;
struct V_47 * V_48 , * V_49 ;
struct V_5 * V_6 = NULL ;
if ( F_17 ( V_46 ) )
return NULL ;
F_10 ( & V_21 -> V_18 , V_35 ) ;
V_48 = & V_21 -> V_29 ;
V_49 = V_48 -> V_50 ;
while ( V_49 != V_48 ) {
V_6 = F_18 ( V_49 , struct V_5 , V_28 ) ;
V_49 = V_49 -> V_50 ;
if ( ! memcmp ( V_46 , V_6 -> V_14 . V_51 , V_52 ) )
break;
}
F_13 ( & V_21 -> V_18 , V_35 ) ;
return V_6 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_47 * V_48 , * V_49 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_36 * V_21 = & V_8 -> V_21 ;
F_10 ( & V_21 -> V_18 , V_35 ) ;
V_48 = & V_21 -> V_29 ;
V_49 = V_48 -> V_50 ;
while ( ! F_20 ( V_48 , V_49 ) ) {
V_6 = F_18 ( V_49 , struct V_5 , V_28 ) ;
V_49 = V_49 -> V_50 ;
F_14 ( V_8 , V_6 ) ;
}
F_13 ( & V_21 -> V_18 , V_35 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_53 ;
if ( V_2 -> V_54 || V_2 -> V_55 ||
! F_22 ( & V_2 -> V_9 , V_56 ) ) {
V_53 = false ;
} else {
V_53 = true ;
}
return V_53 ;
}
void F_23 ( T_2 * V_57 )
{
T_3 V_58 = V_39 ;
V_57 [ 0 ] = 0x02 ;
V_57 [ 1 ] = 0x11 ;
V_57 [ 2 ] = 0x87 ;
V_57 [ 3 ] = ( T_2 ) ( V_58 & 0xff ) ;
V_57 [ 4 ] = ( T_2 ) ( ( V_58 >> 8 ) & 0xff ) ;
V_57 [ 5 ] = ( T_2 ) ( ( V_58 >> 16 ) & 0xff ) ;
}
T_4 F_24 ( struct V_59 * V_60 )
{
return sizeof( * V_60 ) + V_60 -> V_61 - V_62 ;
}
T_2 * F_25 ( T_2 * V_63 )
{
return V_63 + 8 + 2 ;
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
void F_30 ( struct V_1 * V_64 )
{
F_19 ( V_64 ) ;
}
static struct V_5 * F_31 ( struct V_36 * V_21 ,
T_2 * V_46 )
{
struct V_5 * V_6 = F_16 ( V_21 ,
V_46 ) ;
return V_6 ;
}
int F_32 ( struct V_1 * V_65 , struct V_5 * V_6 )
{
int V_66 = true ;
struct V_67 * V_68 = & V_65 -> V_69 ;
if ( ( V_68 -> V_70 != V_71 ) &&
( V_6 -> V_14 . V_72 == 0 ) )
V_66 = false ;
else if ( ( V_68 -> V_70 == V_71 ) &&
( V_6 -> V_14 . V_72 == 1 ) )
V_66 = false ;
else
V_66 = true ;
return V_66 ;
}
static int F_33 ( struct V_59 * V_73 ,
struct V_59 * V_74 )
{
T_5 V_75 , V_76 ;
memcpy ( ( T_2 * ) & V_75 , F_25 ( V_73 -> V_77 ) , 2 ) ;
memcpy ( ( T_2 * ) & V_76 , F_25 ( V_74 -> V_77 ) , 2 ) ;
return ( V_73 -> V_78 . V_79 == V_74 -> V_78 . V_79 ) &&
( V_73 -> V_80 . V_81 ==
V_74 -> V_80 . V_81 ) &&
( ( ! memcmp ( V_73 -> V_51 , V_74 -> V_51 ,
V_52 ) ) ) &&
( ( ! memcmp ( V_73 -> V_78 . V_78 ,
V_74 -> V_78 . V_78 ,
V_73 -> V_78 . V_79 ) ) ) &&
( ( V_75 & V_82 ) ==
( V_76 & V_82 ) ) &&
( ( V_75 & V_83 ) ==
( V_76 & V_83 ) ) ;
}
struct V_5 * F_34 (
struct V_36 * V_21 )
{
struct V_47 * V_49 , * V_48 ;
struct V_5 * V_84 = NULL ;
struct V_5 * V_85 = NULL ;
V_48 = & V_21 -> V_29 ;
V_49 = V_48 -> V_50 ;
while ( 1 ) {
if ( F_20 ( V_48 , V_49 ) == true )
break;
V_84 = F_18 ( V_49 , struct V_5 , V_28 ) ;
if ( V_84 -> V_43 != true ) {
if ( V_85 == NULL ||
F_35 ( ( unsigned long ) V_85 -> V_38 ,
( unsigned long ) V_84 -> V_38 ) )
V_85 = V_84 ;
}
V_49 = V_49 -> V_50 ;
}
return V_85 ;
}
static void F_36 ( struct V_59 * V_74 ,
struct V_59 * V_73 ,
struct V_1 * V_2 )
{
T_3 V_86 = 0 , V_87 ;
if ( F_22 ( & V_2 -> V_9 , V_56 ) &&
F_33 ( & ( V_2 -> V_9 . V_13 . V_14 ) , V_73 ) ) {
if ( V_2 -> V_88 . V_89 . V_90 ++ >=
V_91 ) {
V_2 -> V_88 . V_89 . V_90 =
V_91 ;
V_86 = V_2 -> V_88 . V_89 .
V_92 [ V_2 -> V_88 .
V_89 . V_93 ] ;
V_2 -> V_88 . V_89 . V_94 -=
V_86 ;
}
V_2 -> V_88 . V_89 . V_94 += V_73 -> V_95 ;
V_2 -> V_88 . V_89 .
V_92 [ V_2 -> V_88 . V_89 .
V_93 ++ ] = V_73 -> V_95 ;
if ( V_2 -> V_88 . V_89 . V_93 >=
V_91 )
V_2 -> V_88 . V_89 . V_93 = 0 ;
V_87 = V_2 -> V_88 . V_89 . V_94 /
V_2 -> V_88 . V_89 . V_90 ;
V_2 -> V_88 . signal = ( T_2 ) V_87 ;
V_73 -> V_95 = V_2 -> V_88 . signal ;
} else {
V_73 -> V_95 = ( V_73 -> V_95 + V_74 -> V_95 ) / 2 ;
}
memcpy ( ( T_2 * ) V_74 , ( T_2 * ) V_73 , F_24 ( V_73 ) ) ;
}
static void F_37 ( struct V_1 * V_65 ,
struct V_59 * V_6 )
{
struct V_7 * V_8 = & V_65 -> V_9 ;
if ( F_33 ( & ( V_8 -> V_13 . V_14 ) , V_6 ) ) {
F_36 ( & ( V_8 -> V_13 . V_14 ) ,
V_6 , V_65 ) ;
F_38 ( V_65 ,
( V_8 -> V_13 . V_14 . V_77 ) +
sizeof( struct V_96 ) ,
V_8 -> V_13 . V_14 . V_61 ) ;
}
}
static void F_39 ( struct V_1 * V_65 ,
struct V_59 * V_97 )
{
struct V_47 * V_49 , * V_48 ;
T_3 V_98 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_36 * V_29 = & V_8 -> V_21 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_85 = NULL ;
V_48 = & V_29 -> V_29 ;
V_49 = V_48 -> V_50 ;
while ( 1 ) {
if ( F_20 ( V_48 , V_49 ) )
break;
V_6 = F_18 ( V_49 , struct V_5 , V_28 ) ;
if ( F_33 ( & V_6 -> V_14 , V_97 ) )
break;
if ( ( V_85 == ( (struct V_5 * ) 0 ) ) ||
F_35 ( ( unsigned long ) V_85 -> V_38 ,
( unsigned long ) V_6 -> V_38 ) )
V_85 = V_6 ;
V_49 = V_49 -> V_50 ;
}
if ( F_20 ( V_48 , V_49 ) ) {
if ( F_40 ( & V_8 -> V_20 . V_29 ) ) {
V_6 = V_85 ;
V_97 -> V_95 = ( V_6 -> V_14 . V_95 +
V_97 -> V_95 ) / 2 ;
memcpy ( & V_6 -> V_14 , V_97 ,
F_24 ( V_97 ) ) ;
V_6 -> V_38 = V_39 ;
} else {
V_6 = F_29 ( V_8 ) ;
if ( V_6 == NULL )
return;
V_98 = F_24 ( V_97 ) ;
V_97 -> V_99 = V_98 ;
memcpy ( & V_6 -> V_14 , V_97 , V_98 ) ;
F_7 ( & V_6 -> V_28 , & V_29 -> V_29 ) ;
}
} else {
F_36 ( & V_6 -> V_14 , V_97 , V_65 ) ;
V_6 -> V_38 = V_39 ;
}
}
static void F_41 ( struct V_1 * V_65 ,
struct V_59 * V_6 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & ( ( (struct V_1 * ) V_65 ) -> V_9 ) ;
struct V_36 * V_29 = & V_8 -> V_21 ;
F_10 ( & V_29 -> V_18 , V_35 ) ;
F_37 ( V_65 , V_6 ) ;
F_39 ( V_65 , V_6 ) ;
F_13 ( & V_29 -> V_18 , V_35 ) ;
}
static int F_42 ( struct V_1 * V_65 ,
struct V_5 * V_6 )
{
T_2 V_100 [ 512 ] ;
T_4 V_101 ;
int V_102 = true ;
struct V_67 * V_68 = & V_65 -> V_69 ;
if ( V_68 -> V_103 ) {
if ( F_43 ( V_6 -> V_14 . V_77 ,
V_6 -> V_14 . V_61 , V_100 ,
& V_101 ) )
return true ;
return false ;
}
if ( ( V_68 -> V_70 != V_71 ) &&
( V_6 -> V_14 . V_72 == 0 ) )
V_102 = false ;
if ( F_22 ( & V_65 -> V_9 , V_104 ) ) {
if ( V_6 -> V_14 . V_15 !=
V_65 -> V_9 . V_13 . V_14 .
V_15 )
V_102 = false ;
}
return V_102 ;
}
void F_44 ( struct V_1 * V_65 , T_2 * V_4 )
{
}
void F_45 ( struct V_1 * V_65 , T_2 * V_4 )
{
unsigned long V_105 ;
T_3 V_106 ;
struct V_59 * V_6 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
V_6 = (struct V_59 * ) V_4 ;
#ifdef F_46
V_6 -> V_99 = F_47 ( V_6 -> V_99 ) ;
V_6 -> V_78 . V_79 = F_47 ( V_6 -> V_78 . V_79 ) ;
V_6 -> V_72 = F_47 ( V_6 -> V_72 ) ;
V_6 -> V_95 = F_47 ( V_6 -> V_95 ) ;
V_6 -> V_107 = F_47 ( V_6 -> V_107 ) ;
V_6 -> V_80 . V_108 =
F_47 ( V_6 -> V_80 . V_108 ) ;
V_6 -> V_80 . V_109 =
F_47 ( V_6 -> V_80 . V_109 ) ;
V_6 -> V_80 . V_81 =
F_47 ( V_6 -> V_80 . V_81 ) ;
V_6 -> V_80 . V_110 . V_111 =
F_47 ( V_6 -> V_80 . V_110 . V_111 ) ;
V_6 -> V_80 . V_110 . V_112 =
F_47 ( V_6 -> V_80 . V_110 . V_112 ) ;
V_6 -> V_80 . V_110 . V_113 =
F_47 ( V_6 -> V_80 . V_110 . V_113 ) ;
V_6 -> V_80 . V_110 . V_99 =
F_47 ( V_6 -> V_80 . V_110 . V_99 ) ;
V_6 -> V_80 . V_99 =
F_47 ( V_6 -> V_80 . V_99 ) ;
V_6 -> V_15 =
F_47 ( V_6 -> V_15 ) ;
V_6 -> V_61 = F_47 ( V_6 -> V_61 ) ;
#endif
V_106 = F_24 ( V_6 ) ;
if ( V_106 > sizeof( struct V_59 ) )
return;
F_10 ( & V_8 -> V_19 , V_105 ) ;
if ( F_22 ( V_8 , V_114 ) ) {
if ( ! memcmp ( & ( V_8 -> V_13 . V_14 . V_51 ) ,
V_6 -> V_51 , V_52 ) ) {
struct V_5 * V_115 = NULL ;
memcpy ( V_8 -> V_13 . V_14 . V_77 ,
V_6 -> V_77 , 8 ) ;
V_115 = F_31 (
& V_8 -> V_21 ,
V_6 -> V_51 ) ;
if ( V_115 ) {
memcpy ( V_115 -> V_14 . V_77 ,
V_6 -> V_77 , 8 ) ;
goto exit;
}
}
}
if ( ! F_22 ( V_8 , V_116 ) ) {
if ( V_6 -> V_78 . V_78 [ 0 ] != 0 ) {
F_41 ( V_65 , V_6 ) ;
} else {
V_6 -> V_78 . V_79 = 8 ;
memcpy ( V_6 -> V_78 . V_78 , L_1 , 8 ) ;
F_41 ( V_65 , V_6 ) ;
}
}
exit:
F_13 ( & V_8 -> V_19 , V_105 ) ;
}
void F_48 ( struct V_1 * V_65 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
F_10 ( & V_8 -> V_18 , V_35 ) ;
if ( F_22 ( V_8 , V_117 ) ) {
F_49 ( & V_8 -> V_118 ) ;
F_50 ( V_8 , V_117 ) ;
}
if ( V_8 -> V_119 ) {
if ( F_22 ( V_8 , V_104 ) ) {
if ( ! F_22 ( V_8 , V_56 ) ) {
F_51 ( V_8 , V_116 ) ;
if ( F_52 ( V_8 )
== V_34 )
F_53 ( & V_8 -> V_120 , V_39 +
F_54 ( V_121 ) ) ;
else {
struct V_59 * V_122 =
& ( V_65 -> V_123 . V_124 ) ;
T_2 * V_57 =
V_65 -> V_123 .
V_124 . V_51 ;
V_8 -> V_12 ^= V_117 ;
memcpy ( & V_122 -> V_78 ,
& V_8 -> V_22 ,
sizeof( struct
V_23 ) ) ;
F_55
( V_65 ) ;
F_23 ( V_57 ) ;
V_8 -> V_12 =
V_114 ;
V_8 -> V_119 = false ;
}
}
} else {
V_8 -> V_119 = false ;
F_51 ( V_8 , V_116 ) ;
if ( F_52 ( V_8 ) ==
V_34 )
F_53 ( & V_8 -> V_120 , V_39 +
F_54 ( V_121 ) ) ;
else
F_50 ( V_8 , V_116 ) ;
}
}
F_13 ( & V_8 -> V_18 , V_35 ) ;
}
void F_56 ( struct V_1 * V_65 )
{
unsigned long V_35 ;
struct V_5 * V_84 = NULL ;
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_125 * V_126 = & V_65 -> V_127 ;
struct V_5 * V_128 = & V_8 -> V_13 ;
V_84 = F_31 ( & V_8 -> V_21 ,
V_128 -> V_14 . V_51 ) ;
if ( F_22 ( V_8 , V_129 | V_130 ) ) {
struct V_131 * V_132 ;
V_132 = F_57 ( & V_65 -> V_127 ,
V_128 -> V_14 . V_51 ) ;
F_10 ( & V_126 -> V_133 , V_35 ) ;
F_58 ( V_65 , V_132 ) ;
F_13 ( & V_126 -> V_133 , V_35 ) ;
}
if ( F_22 ( V_8 ,
V_104 | V_114 | V_130 ) )
F_59 ( V_65 ) ;
if ( V_84 )
V_84 -> V_43 = false ;
if ( ( ( F_22 ( V_8 , V_114 ) ) &&
( V_65 -> V_127 . V_134 == 1 ) ) )
F_15 ( V_8 , V_84 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
V_8 -> V_119 = false ;
F_51 ( V_8 , V_56 ) ;
V_2 -> V_135 . V_136 ( V_2 , V_137 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_123 . V_138 > V_139 )
F_53 ( & V_8 -> V_140 ,
V_39 + F_54 ( 60000 ) ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( F_22 ( V_8 , V_56 ) ) {
F_50 ( V_8 , V_56 ) ;
V_2 -> V_135 . V_136 ( V_2 , V_141 ) ;
F_63 ( V_2 ) ;
}
if ( V_2 -> V_142 . V_143 !=
V_2 -> V_123 . V_138 ) {
F_49 ( & V_8 -> V_140 ) ;
F_64 ( V_2 , V_2 -> V_123 . V_138 ,
V_2 -> V_123 . V_144 ) ;
}
}
void F_65 ( struct V_1 * V_65 , T_2 * V_4 )
{
unsigned long V_35 = 0 , V_145 ;
struct V_131 * V_146 = NULL , * V_147 = NULL ;
struct V_125 * V_126 = & V_65 -> V_127 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_5 * V_13 = & V_8 -> V_13 ;
struct V_5 * V_148 = NULL , * V_149 = NULL ;
unsigned int V_150 = false ;
struct V_5 * V_6 ;
if ( sizeof( struct V_47 ) == 4 * sizeof( T_3 ) ) {
V_6 = F_66 ( sizeof( struct V_5 ) , V_25 ) ;
if ( ! V_6 )
return;
memcpy ( ( T_2 * ) V_6 + 16 , ( T_2 * ) V_4 + 8 ,
sizeof( struct V_5 ) - 16 ) ;
} else {
V_6 = (struct V_5 * ) V_4 ;
}
#ifdef F_46
V_6 -> V_151 = F_47 ( V_6 -> V_151 ) ;
V_6 -> V_152 = F_47 ( V_6 -> V_152 ) ;
V_6 -> V_14 . V_99 = F_47 ( V_6 -> V_14 . V_99 ) ;
V_6 -> V_14 . V_78 . V_79 =
F_47 ( V_6 -> V_14 . V_78 . V_79 ) ;
V_6 -> V_14 . V_72 = F_47 ( V_6 -> V_14 . V_72 ) ;
V_6 -> V_14 . V_95 = F_47 ( V_6 -> V_14 . V_95 ) ;
V_6 -> V_14 . V_107 =
F_47 ( V_6 -> V_14 . V_107 ) ;
V_6 -> V_14 . V_80 . V_108 =
F_47 ( V_6 -> V_14 . V_80 . V_108 ) ;
V_6 -> V_14 . V_80 . V_109 =
F_47 ( V_6 -> V_14 . V_80 . V_109 ) ;
V_6 -> V_14 . V_80 . V_81 =
F_47 ( V_6 -> V_14 . V_80 . V_81 ) ;
V_6 -> V_14 . V_80 . V_110 . V_111 =
F_47 ( V_6 -> V_14 . V_80 . V_110 .
V_111 ) ;
V_6 -> V_14 . V_80 . V_110 . V_112 =
F_47 ( V_6 -> V_14 . V_80 .
V_110 . V_112 ) ;
V_6 -> V_14 . V_80 . V_110 . V_113 =
F_47 ( V_6 -> V_14 . V_80 . V_110 . V_113 ) ;
V_6 -> V_14 . V_80 . V_110 . V_99 =
F_47 ( V_6 -> V_14 . V_80 . V_110 . V_99 ) ;
V_6 -> V_14 . V_80 . V_99 =
F_47 ( V_6 -> V_14 . V_80 . V_99 ) ;
V_6 -> V_14 . V_15 =
F_47 ( V_6 -> V_14 . V_15 ) ;
V_6 -> V_14 . V_61 = F_47 ( V_6 -> V_14 . V_61 ) ;
#endif
V_150 = ! memcmp ( V_6 -> V_14 . V_51 ,
V_13 -> V_14 . V_51 , V_52 ) ;
V_6 -> V_14 . V_99 =
F_24 ( & V_6 -> V_14 ) ;
F_10 ( & V_8 -> V_18 , V_35 ) ;
if ( V_6 -> V_14 . V_99 > sizeof( struct V_59 ) )
goto V_153;
if ( V_6 -> V_151 > 0 ) {
if ( F_22 ( V_8 , V_116 ) ) {
if ( F_22 ( V_8 , V_56 ) ) {
if ( V_150 ) {
V_149 =
F_31 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
} else {
V_148 =
F_31 ( & V_8 ->
V_21 ,
V_13 -> V_14 . V_51 ) ;
V_148 -> V_43 = false ;
V_147 = F_57 ( V_126 ,
V_13 -> V_14 . V_51 ) ;
F_10 ( & V_126 ->
V_133 , V_145 ) ;
F_58 ( V_65 , V_147 ) ;
F_13 ( & ( V_126 ->
V_133 ) , V_145 ) ;
V_149 =
F_31 ( & V_8 ->
V_21 ,
V_6 -> V_14 .
V_51 ) ;
if ( V_149 )
V_149 -> V_43 = true ;
}
} else {
V_149 = F_31 ( & V_8 ->
V_21 ,
V_6 -> V_14 . V_51 ) ;
if ( V_149 )
V_149 -> V_43 = true ;
}
if ( V_149 == NULL ) {
if ( F_22 ( V_8 ,
V_116 ) )
V_8 -> V_12 ^=
V_116 ;
goto V_153;
}
if ( F_22 ( V_8 , V_129 ) ) {
if ( V_150 ) {
V_146 =
F_57 ( V_126 ,
V_6 -> V_14 . V_51 ) ;
if ( V_146 == NULL )
V_146 =
F_67 ( V_126 ,
V_6 -> V_14 . V_51 ) ;
} else {
V_146 =
F_67 ( V_126 ,
V_6 -> V_14 . V_51 ) ;
}
if ( V_146 ) {
V_146 -> V_154 = V_6 -> V_151 ;
V_146 -> V_155 = 1 ;
V_146 -> V_156 = 5 ;
if ( V_65 -> V_69 .
V_157 == 2 ) {
V_65 -> V_69 .
V_158 =
false ;
V_65 -> V_69 .
V_159 =
false ;
V_65 -> V_69 .
V_160 =
false ;
V_146 -> V_161
= true ;
V_146 -> V_162 =
V_65 -> V_69 .
V_70 ;
memset ( ( T_2 * ) & V_146 ->
V_163 ,
0 ,
sizeof( union V_164 ) ) ;
memset ( ( T_2 * ) & V_146 ->
V_165 ,
0 ,
sizeof( union V_164 ) ) ;
memset ( ( T_2 * ) & V_146 ->
V_166 ,
0 ,
sizeof( union V_164 ) ) ;
memset ( ( T_2 * ) & V_146 ->
V_167 , 0 ,
sizeof( union V_168 ) ) ;
memset ( ( T_2 * ) & V_146 ->
V_169 , 0 ,
sizeof( union V_168 ) ) ;
}
} else {
if ( F_22 ( V_8 ,
V_116 ) )
V_8 -> V_12 ^=
V_116 ;
goto V_153;
}
}
memcpy ( & V_13 -> V_14 , & V_6 -> V_14 ,
V_6 -> V_14 . V_99 ) ;
V_13 -> V_154 = V_6 -> V_151 ;
switch ( V_6 -> V_14 . V_15 ) {
case V_170 :
V_8 -> V_12 = V_129 ;
break;
case V_171 :
V_8 -> V_12 = V_104 ;
break;
default:
V_8 -> V_12 = V_172 ;
break;
}
F_38 ( V_65 ,
( V_13 -> V_14 . V_77 ) +
sizeof( struct V_96 ) ,
( V_13 -> V_14 . V_61 ) ) ;
F_68 ( V_65 , V_13 -> V_14 . V_77 ,
V_13 -> V_14 . V_61 ) ;
if ( F_22 ( V_8 , V_129 ) )
F_60 ( V_65 ) ;
F_49 ( & V_8 -> V_120 ) ;
} else {
goto V_153;
}
} else {
if ( F_22 ( V_8 , V_116 ) ) {
F_53 ( & V_8 -> V_120 ,
V_39 + F_54 ( 1 ) ) ;
F_50 ( V_8 , V_116 ) ;
}
}
V_153:
F_13 ( & V_8 -> V_18 , V_35 ) ;
if ( sizeof( struct V_47 ) == 4 * sizeof( T_3 ) )
F_28 ( V_6 ) ;
}
void F_69 ( struct V_1 * V_65 , T_2 * V_4 )
{
unsigned long V_35 ;
struct V_131 * V_132 ;
struct V_7 * V_8 = & ( V_65 -> V_9 ) ;
struct V_173 * V_174 = (struct V_173 * ) V_4 ;
if ( ! F_70 ( & V_65 -> V_175 , V_174 -> V_176 ) )
return;
V_132 = F_57 ( & V_65 -> V_127 , V_174 -> V_176 ) ;
if ( V_132 != NULL ) {
return;
}
V_132 = F_67 ( & V_65 -> V_127 , V_174 -> V_176 ) ;
if ( V_132 == NULL )
return;
V_132 -> V_155 = 0 ;
V_132 -> V_156 = F_47 ( ( T_4 ) V_174 -> V_177 ) ;
if ( V_65 -> V_69 . V_157 == 2 )
V_132 -> V_162 = V_65 -> V_69 . V_70 ;
V_132 -> V_161 = false ;
F_10 ( & V_8 -> V_18 , V_35 ) ;
if ( F_22 ( V_8 , V_114 ) ||
F_22 ( V_8 , V_104 ) ) {
if ( V_65 -> V_127 . V_134 == 2 ) {
F_60 ( V_65 ) ;
}
}
F_13 ( & V_8 -> V_18 , V_35 ) ;
}
void F_71 ( struct V_1 * V_65 , T_2 * V_4 )
{
unsigned long V_35 , V_145 ;
struct V_131 * V_132 ;
struct V_5 * V_84 = NULL ;
struct V_59 * V_122 = NULL ;
T_2 * V_57 = NULL ;
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_178 * V_179 = (struct V_178 * ) V_4 ;
struct V_125 * V_126 = & V_65 -> V_127 ;
struct V_5 * V_128 = & V_8 -> V_13 ;
F_10 ( & V_8 -> V_18 , V_145 ) ;
if ( F_22 ( V_8 , V_129 ) ) {
F_62 ( V_65 ) ;
F_56 ( V_65 ) ;
}
if ( F_22 ( V_8 , V_114 |
V_104 ) ) {
V_132 = F_57 ( & V_65 -> V_127 , V_179 -> V_176 ) ;
F_10 ( & V_126 -> V_133 , V_35 ) ;
F_58 ( V_65 , V_132 ) ;
F_13 ( & V_126 -> V_133 , V_35 ) ;
if ( V_65 -> V_127 . V_134 == 1 ) {
V_84 = F_31 ( & V_8 -> V_21 ,
V_128 -> V_14 . V_51 ) ;
if ( V_84 ) {
V_84 -> V_43 = false ;
F_15 ( V_8 , V_84 ) ;
}
V_122 = & ( V_65 -> V_123 . V_124 ) ;
V_57 = V_65 -> V_123 . V_124 . V_51 ;
memcpy ( V_122 , & V_128 -> V_14 ,
F_24 ( & V_128 ->
V_14 ) ) ;
memcpy ( & V_122 -> V_78 ,
& V_8 -> V_22 ,
sizeof( struct V_23 ) ) ;
F_55 ( V_65 ) ;
F_23 ( V_57 ) ;
if ( F_22 ( V_8 , V_104 ) ) {
F_50 ( V_8 , V_104 ) ;
F_51 ( V_8 , V_114 ) ;
}
}
}
F_13 ( & V_8 -> V_18 , V_145 ) ;
}
void F_72 ( struct V_1 * V_65 , T_2 * V_4 )
{
struct V_180 * V_181 =
(struct V_180 * ) V_4 ;
V_181 -> V_182 |= ( T_2 ) ( V_65 -> V_142 . V_183 + 0x80 ) ;
F_73 ( V_65 , V_181 ) ;
}
void F_74 ( struct V_1 * V_65 , T_2 * V_4 )
{
struct V_184 * V_185 =
(struct V_184 * ) V_4 ;
struct V_131 * V_132 ;
struct V_125 * V_126 = & V_65 -> V_127 ;
struct V_186 * V_187 = NULL ;
V_132 = F_57 ( V_126 , V_185 -> V_51 ) ;
if ( V_132 ) {
V_187 =
& V_132 -> V_188 [ V_185 -> V_189 ] ;
V_187 -> V_190 = 0xffff ;
}
}
void F_75 ( struct V_1 * V_65 , T_2 * V_4 )
{
if ( ! V_65 -> V_69 . V_191 )
V_65 -> V_69 . V_191 = true ;
}
void F_76 ( struct V_1 * V_65 )
{
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_192 * V_193 = & V_8 -> V_30 ;
struct V_194 * V_195 = & V_65 -> V_123 ;
T_6 V_196 ;
T_4 V_197 ;
V_196 = ( V_65 -> V_198 . V_199 ) -
( V_193 -> V_32 ) ;
V_197 = ( V_65 -> V_88 . V_200 ) -
( V_193 -> V_31 ) ;
V_193 -> V_32 = V_65 -> V_198 . V_199 ;
V_193 -> V_31 = V_65 -> V_88 . V_200 ;
if ( ( V_196 > V_195 -> V_201 ) ||
( V_197 > V_195 -> V_201 ) )
V_193 -> V_33 = true ;
else
V_193 -> V_33 = false ;
}
void F_77 ( struct V_1 * V_65 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
if ( V_65 -> V_54 || V_65 -> V_55 )
return;
F_10 ( & V_8 -> V_18 , V_35 ) ;
F_50 ( V_8 , V_116 ) ;
V_8 -> V_119 = false ;
if ( F_22 ( V_8 , V_56 ) ) {
F_63 ( V_65 ) ;
F_50 ( V_8 , V_56 ) ;
}
if ( V_65 -> V_142 . V_143 != V_65 -> V_123 . V_138 ) {
F_64 ( V_65 , V_65 -> V_123 . V_138 ,
V_65 -> V_123 . V_144 ) ;
}
F_13 ( & V_8 -> V_18 , V_35 ) ;
}
void F_78 ( struct V_1 * V_65 )
{
unsigned long V_35 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
F_10 ( & V_8 -> V_18 , V_35 ) ;
F_50 ( V_8 , V_117 ) ;
V_8 -> V_119 = false ;
F_13 ( & V_8 -> V_18 , V_35 ) ;
}
void F_79 ( struct V_1 * V_65 )
{
if ( V_65 -> V_54 || V_65 -> V_55 )
return;
if ( V_65 -> V_142 . V_143 != V_65 -> V_123 . V_138 )
F_64 ( V_65 , V_65 -> V_123 . V_138 ,
V_65 -> V_123 . V_144 ) ;
}
void F_80 ( struct V_1 * V_65 )
{
F_81 ( V_65 ) ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_47 * V_48 ;
unsigned char * V_202 , * V_203 ;
struct V_1 * V_65 ;
struct V_36 * V_29 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_204 = NULL ;
V_65 = (struct V_1 * ) V_8 -> V_10 ;
V_29 = & V_8 -> V_21 ;
V_48 = & V_29 -> V_29 ;
V_8 -> V_11 = V_48 -> V_50 ;
while ( 1 ) {
if ( F_20 ( V_48 , V_8 -> V_11 ) ) {
if ( ( V_8 -> V_205 ) &&
( V_204 != NULL ) ) {
V_6 = V_204 ;
goto V_206;
}
return V_26 ;
}
V_6 = F_18 ( V_8 -> V_11 ,
struct V_5 , V_28 ) ;
if ( V_6 == NULL )
return V_26 ;
V_8 -> V_11 = V_8 -> V_11 -> V_50 ;
if ( V_8 -> V_207 ) {
V_202 = V_6 -> V_14 . V_51 ;
V_203 = V_8 -> V_208 ;
if ( ! memcmp ( V_202 , V_203 , V_52 ) ) {
if ( F_22 ( V_8 , V_56 ) ) {
if ( F_33 ( & V_8 ->
V_13 . V_14 ,
& V_6 -> V_14 ) ) {
F_50 ( V_8 ,
V_116 ) ;
F_60 ( V_65 ) ;
return 2 ;
}
F_82 ( V_65 ) ;
F_62 ( V_65 ) ;
F_56 ( V_65 ) ;
}
goto V_206;
}
} else if ( V_8 -> V_22 . V_79 == 0 ) {
goto V_206;
}
V_202 = V_6 -> V_14 . V_78 . V_78 ;
V_203 = V_8 -> V_22 . V_78 ;
if ( ( V_6 -> V_14 . V_78 . V_79 ==
V_8 -> V_22 . V_79 ) &&
( ! memcmp ( V_202 , V_203 ,
V_8 -> V_22 . V_79 ) ) ) {
if ( V_8 -> V_205 ) {
if ( V_204 ) {
if ( V_6 -> V_14 . V_95 >
V_204 -> V_14 . V_95 )
V_204 = V_6 ;
} else {
V_204 = V_6 ;
}
} else if ( F_42 ( V_65 , V_6 ) ) {
if ( F_22 ( V_8 , V_56 ) ) {
F_82 ( V_65 ) ;
F_56 ( V_65 ) ;
}
goto V_206;
}
}
}
V_206:
return F_83 ( V_65 , V_6 ) ;
}
T_1 F_84 ( struct V_1 * V_65 ,
struct V_67 * V_68 )
{
struct V_209 * V_210 = & V_65 -> V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
V_213 = F_66 ( sizeof( * V_213 ) , V_25 ) ;
if ( ! V_213 )
return V_26 ;
V_215 = F_85 ( sizeof( * V_215 ) , V_25 ) ;
if ( ! V_215 ) {
F_28 ( V_213 ) ;
return V_26 ;
}
V_215 -> V_216 = ( T_2 ) V_68 -> V_157 ;
V_213 -> V_217 = V_218 ;
V_213 -> V_219 = ( unsigned char * ) V_215 ;
V_213 -> V_220 = sizeof( struct V_214 ) ;
V_213 -> V_221 = NULL ;
V_213 -> V_222 = 0 ;
F_6 ( & V_213 -> V_28 ) ;
F_86 ( V_210 , V_213 ) ;
return V_34 ;
}
T_1 F_87 ( struct V_1 * V_65 ,
struct V_67 * V_68 ,
T_1 V_223 )
{
struct V_209 * V_210 = & V_65 -> V_211 ;
struct V_212 * V_213 ;
struct V_224 * V_225 ;
T_2 V_226 ;
T_1 V_66 = V_34 ;
V_213 = F_66 ( sizeof( * V_213 ) , V_25 ) ;
if ( ! V_213 )
return V_26 ;
V_225 = F_85 ( sizeof( * V_225 ) , V_25 ) ;
if ( ! V_225 ) {
V_66 = V_26 ;
goto V_227;
}
if ( V_68 -> V_157 == 2 ) {
V_225 -> V_228 =
( T_2 ) V_68 -> V_229 ;
} else {
V_225 -> V_228 =
( T_2 ) V_68 -> V_70 ;
}
V_225 -> V_223 = ( T_2 ) V_223 ;
switch ( V_225 -> V_228 ) {
case V_230 :
V_226 = 5 ;
memcpy ( V_225 -> V_231 ,
V_68 -> V_232 [ V_223 ] . V_233 , V_226 ) ;
break;
case V_234 :
V_226 = 13 ;
memcpy ( V_225 -> V_231 ,
V_68 -> V_232 [ V_223 ] . V_233 , V_226 ) ;
break;
case V_235 :
if ( V_223 < 1 || V_223 > 2 ) {
V_66 = V_26 ;
goto V_236;
}
V_226 = 16 ;
memcpy ( V_225 -> V_231 ,
& V_68 -> V_237 [ V_223 - 1 ] , V_226 ) ;
V_225 -> V_238 = 1 ;
break;
case V_239 :
if ( V_223 < 1 || V_223 > 2 ) {
V_66 = V_26 ;
goto V_236;
}
V_226 = 16 ;
memcpy ( V_225 -> V_231 ,
& V_68 -> V_237 [ V_223 - 1 ] , V_226 ) ;
V_225 -> V_238 = 1 ;
break;
default:
V_66 = V_26 ;
goto V_236;
}
V_213 -> V_217 = V_240 ;
V_213 -> V_219 = ( T_2 * ) V_225 ;
V_213 -> V_220 = ( sizeof( struct V_224 ) ) ;
V_213 -> V_221 = NULL ;
V_213 -> V_222 = 0 ;
F_6 ( & V_213 -> V_28 ) ;
F_86 ( V_210 , V_213 ) ;
return V_66 ;
V_236:
F_28 ( V_225 ) ;
V_227:
F_28 ( V_213 ) ;
return V_66 ;
}
int F_88 ( struct V_1 * V_65 , T_2 * V_241 , T_2 * V_242 ,
T_4 V_243 , T_4 V_244 )
{
unsigned int V_245 = 0 ;
unsigned int V_3 , V_246 ;
V_3 = 12 ;
while ( V_3 < V_243 ) {
V_245 = V_244 ;
if ( V_241 [ V_3 ] == 0xDD && V_241 [ V_3 + 2 ] == 0x00 &&
V_241 [ V_3 + 3 ] == 0x50 && V_241 [ V_3 + 4 ] == 0xF2 &&
V_241 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_243 ) {
for ( V_246 = V_3 ; V_246 < V_3 + 9 ; V_246 ++ ) {
V_242 [ V_245 ] = V_241 [ V_246 ] ;
V_245 ++ ;
}
V_242 [ V_244 + 1 ] = 0x07 ;
V_242 [ V_244 + 6 ] = 0x00 ;
V_242 [ V_244 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_241 [ V_3 + 1 ] + 2 ) ;
}
return V_245 ;
}
static int F_89 ( struct V_1 * V_247 , T_2 * V_248 )
{
struct V_67 * V_68 = & V_247 -> V_69 ;
int V_3 = 0 ;
do {
if ( V_68 -> V_249 [ V_3 ] . V_250 &&
( ! memcmp ( V_68 -> V_249 [ V_3 ] . V_251 ,
V_248 , V_52 ) ) )
break;
else
V_3 ++ ;
} while ( V_3 < V_252 );
if ( V_3 == V_252 ) {
V_3 = - 1 ;
} else {
;
}
return V_3 ;
}
T_1 F_90 ( struct V_1 * V_65 , T_2 * V_241 ,
T_2 * V_242 , T_4 V_243 )
{
T_2 V_253 = 0 , V_254 ;
T_2 V_255 [ 255 ] , V_256 [ 4 ] , V_257 [ 255 ] ;
T_2 V_258 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_4 V_245 , V_259 , V_260 ;
int V_261 ;
struct V_7 * V_8 = & V_65 -> V_9 ;
struct V_67 * V_68 = & V_65 -> V_69 ;
T_4 V_262 = V_68 -> V_263 ;
T_4 V_264 = V_68 -> V_265 ;
if ( ( V_262 == V_266 ) ||
( V_262 == V_267 ) ) {
V_253 = V_268 ;
V_256 [ 0 ] = 0x0 ;
V_256 [ 1 ] = 0x50 ;
V_256 [ 2 ] = 0xf2 ;
}
if ( ( V_262 == V_269 ) ||
( V_262 == V_270 ) ) {
V_253 = V_271 ;
V_256 [ 0 ] = 0x0 ;
V_256 [ 1 ] = 0x0f ;
V_256 [ 2 ] = 0xac ;
}
switch ( V_264 ) {
case V_272 :
case V_273 :
V_256 [ 3 ] = 0x1 ;
break;
case V_274 :
case V_275 :
V_256 [ 3 ] = 0x2 ;
break;
case V_276 :
case V_277 :
V_256 [ 3 ] = 0x4 ;
break;
default:
break;
}
V_259 = 12 ;
V_254 = false ;
while ( V_259 < V_243 ) {
if ( V_241 [ V_259 ] == V_253 ) {
if ( ( V_253 == V_268 ) &&
( ! memcmp ( & V_241 [ V_259 + 2 ] , & V_258 [ 0 ] , 4 ) ) ) {
memcpy ( & V_255 [ 0 ] , & V_241 [ V_259 ] ,
V_241 [ V_259 + 1 ] + 2 ) ;
V_254 = true ;
break;
}
if ( V_253 == V_271 ) {
memcpy ( & V_255 [ 0 ] , & V_241 [ V_259 ] ,
V_241 [ V_259 + 1 ] + 2 ) ;
V_254 = true ;
break;
}
if ( ( ( V_253 == V_268 ) &&
( ! memcmp ( & V_241 [ V_259 + 2 ] , & V_258 [ 0 ] , 4 ) ) ) ||
( V_253 == V_271 ) )
memcpy ( & V_257 [ 0 ] , & V_241 [ V_259 ] ,
V_241 [ V_259 + 1 ] + 2 ) ;
}
V_259 += V_241 [ V_259 + 1 ] + 2 ;
}
if ( V_254 ) {
if ( V_255 [ 0 ] == V_268 ) {
while ( true ) {
if ( memcmp ( & V_255 [ 2 ] , & V_258 [ 0 ] , 4 ) ) {
V_254 = false ;
break;
}
if ( ( V_255 [ 6 ] != 0x01 ) || ( V_255 [ 7 ] != 0x0 ) ) {
V_254 = false ;
break;
}
if ( ! memcmp ( & V_255 [ 8 ] , & V_258 [ 0 ] , 3 ) ) {
switch ( V_255 [ 11 ] ) {
case 0x0 :
V_68 -> V_229 =
V_71 ;
break;
case 0x1 :
V_68 -> V_229 =
V_230 ;
break;
case 0x2 :
V_68 -> V_229 =
V_235 ;
break;
case 0x3 :
case 0x4 :
V_68 -> V_229 =
V_239 ;
break;
case 0x5 :
V_68 -> V_229 =
V_234 ;
break;
}
} else {
V_254 = false ;
break;
}
if ( V_255 [ 12 ] == 0x01 ) {
if ( memcmp ( & V_255 [ 14 ] ,
& V_256 [ 0 ] , 4 ) ) {
V_254 = false ;
break;
}
} else {
V_259 = V_255 [ 12 ] ;
V_260 = ( V_259 - 1 ) * 4 ;
V_255 [ 12 ] = 0x01 ;
memcpy ( & V_255 [ 14 ] , & V_256 [ 0 ] , 4 ) ;
memcpy ( & V_255 [ 18 ] ,
& V_255 [ 18 + V_260 ] ,
V_255 [ 1 ] - 18 + 2 -
V_260 ) ;
V_255 [ 1 ] = V_255 [ 1 ] - V_260 ;
}
break;
}
}
if ( V_253 == V_271 ) {
while ( true ) {
if ( ( V_255 [ 2 ] != 0x01 ) || ( V_255 [ 3 ] != 0x0 ) ) {
V_254 = false ;
break;
}
if ( ! memcmp ( & V_255 [ 4 ] , & V_256 [ 0 ] , 3 ) ) {
switch ( V_255 [ 7 ] ) {
case 0x1 :
V_68 -> V_229 =
V_230 ;
break;
case 0x2 :
V_68 -> V_229 =
V_235 ;
break;
case 0x4 :
V_68 -> V_229 =
V_239 ;
break;
case 0x5 :
V_68 -> V_229 =
V_234 ;
break;
default:
V_68 -> V_229 =
V_71 ;
break;
}
} else {
V_254 = false ;
break;
}
if ( V_255 [ 8 ] == 0x01 ) {
if ( memcmp ( & V_255 [ 10 ] ,
& V_256 [ 0 ] , 4 ) ) {
V_254 = false ;
break;
}
} else {
V_259 = V_255 [ 8 ] ;
V_260 = ( V_259 - 1 ) * 4 ;
V_255 [ 8 ] = 0x01 ;
memcpy ( & V_255 [ 10 ] , & V_256 [ 0 ] , 4 ) ;
memcpy ( & V_255 [ 14 ] ,
& V_255 [ 14 + V_260 ] ,
( V_255 [ 1 ] - 14 + 2 -
V_260 ) ) ;
V_255 [ 1 ] = V_255 [ 1 ] - V_260 ;
}
break;
}
}
}
if ( ( V_253 == V_268 ) || ( V_253 == V_271 ) ) {
memcpy ( V_242 , V_241 , 12 ) ;
V_245 = 12 ;
if ( V_254 ) {
memcpy ( & V_242 [ V_245 ] , & V_255 [ 0 ] , V_255 [ 1 ] + 2 ) ;
V_245 += V_255 [ 1 ] + 2 ;
if ( V_253 == V_271 ) {
V_242 [ V_245 - 1 ] = 0 ;
V_242 [ V_245 - 2 ] = 0 ;
}
F_91 ( V_65 , V_253 , V_255 ) ;
}
} else {
memcpy ( V_242 , V_241 , 12 ) ;
V_245 = 12 ;
if ( V_68 -> V_103 ) {
memcpy ( V_242 + V_245 , V_68 -> V_100 ,
V_68 -> V_278 ) ;
V_245 += V_68 -> V_278 ;
}
}
V_261 = F_89 ( V_65 , V_8 -> V_208 ) ;
if ( V_261 < 0 )
return V_245 ;
if ( V_253 == V_271 ) {
V_242 [ V_245 ] = 1 ;
V_245 ++ ;
V_242 [ V_245 ] = 0 ;
V_245 ++ ;
memcpy ( & V_242 [ V_245 ] ,
& V_68 -> V_249 [ V_261 ] . V_279 , 16 ) ;
V_245 += 16 ;
V_242 [ 13 ] += 18 ;
}
return V_245 ;
}
void F_92 ( struct V_1 * V_65 )
{
struct V_194 * V_195 = & V_65 -> V_123 ;
struct V_280 * V_281 = & V_65 -> V_282 ;
struct V_59 * V_122 = & V_195 -> V_124 ;
T_2 * V_283 = F_93 ( V_281 ) ;
memcpy ( V_122 -> V_51 , V_283 , V_52 ) ;
memcpy ( & V_122 -> V_78 , & V_195 -> V_284 ,
sizeof( struct V_23 ) ) ;
V_122 -> V_80 . V_99 =
sizeof( struct V_285 ) ;
V_122 -> V_80 . V_109 = 100 ;
V_122 -> V_80 . V_110 . V_99 = 0 ;
V_122 -> V_80 . V_110 . V_112 = 0 ;
V_122 -> V_80 . V_110 . V_113 = 0 ;
V_122 -> V_80 . V_110 . V_111 = 0 ;
}
void F_55 ( struct V_1 * V_65 )
{
int V_286 = 0 ;
struct V_194 * V_195 = & V_65 -> V_123 ;
struct V_59 * V_122 = & V_195 -> V_124 ;
struct V_67 * V_68 = & V_65 -> V_69 ;
struct V_5 * V_13 = & V_65 -> V_9 . V_13 ;
V_122 -> V_72 = F_94 ( V_68 -> V_70
> 0 ? 1 : 0 ) ;
V_122 -> V_95 = 0 ;
switch ( V_195 -> V_287 ) {
case V_288 :
V_122 -> V_107 = F_94 ( V_289 ) ;
break;
case V_290 :
case V_291 :
V_122 -> V_107 = F_94 ( V_292 ) ;
break;
case V_293 :
V_122 -> V_107 = F_94 ( V_294 ) ;
break;
default:
break;
}
V_122 -> V_80 . V_81 = F_94 (
V_195 -> V_295 ) ;
if ( V_13 -> V_14 . V_15 == V_171 )
V_122 -> V_80 . V_108 = F_94 ( 3 ) ;
V_122 -> V_15 = F_94 (
V_13 -> V_14 . V_15 ) ;
V_286 = F_95 ( V_195 ) ;
V_122 -> V_61 = V_286 ;
V_122 -> V_99 = F_24 ( V_122 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_296 * V_297 = & V_8 -> V_298 ;
V_297 -> V_299 = false ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_297 -> V_300 [ V_3 ] = false ;
if ( V_297 -> V_301 ) {
F_97 ( V_2 , 0x102500D9 , 48 ) ;
} else {
F_97 ( V_2 , 0x102500D9 , 1 ) ;
}
}
unsigned int F_98 ( struct V_1 * V_2 , T_2 * V_241 ,
T_2 * V_242 , T_4 V_243 , T_4 * V_302 )
{
T_3 V_303 , V_304 ;
unsigned char * V_305 ;
struct V_306 V_307 ;
unsigned char V_308 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_309 * V_310 = & V_8 -> V_311 ;
struct V_296 * V_297 = & V_8 -> V_298 ;
V_297 -> V_301 = 0 ;
V_305 = F_99 ( V_241 + 12 , V_312 , & V_303 , V_243 - 12 ) ;
if ( V_305 && ( V_303 > 0 ) ) {
if ( V_310 -> V_155 == 0 ) {
V_304 = * V_302 ;
F_100 ( V_242 + V_304 , V_313 ,
V_314 , V_308 , V_302 ) ;
V_310 -> V_155 = 1 ;
}
V_304 = * V_302 ;
memset ( & V_307 , 0 , sizeof( struct V_306 ) ) ;
V_307 . V_315 = V_316 |
V_317 |
V_318 |
V_319 |
V_320 |
V_321 ;
V_307 . V_322 = ( V_323 &
0x03 ) | ( V_324 & 0x00 ) ;
F_100 ( V_242 + V_304 , V_312 ,
sizeof( struct V_306 ) ,
( unsigned char * ) & V_307 , V_302 ) ;
V_297 -> V_301 = 1 ;
}
return V_297 -> V_301 ;
}
static void F_68 ( struct V_1 * V_2 , T_2 * V_325 , T_4 V_326 )
{
T_2 * V_305 , V_327 ;
int V_3 , V_106 ;
struct V_131 * V_328 , * V_132 ;
struct V_306 * V_329 ;
struct V_186 * V_330 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_296 * V_297 = & V_8 -> V_298 ;
struct V_194 * V_195 = & V_2 -> V_123 ;
struct V_5 * V_331 = & ( V_8 -> V_13 ) ;
if ( ! V_297 -> V_301 )
return;
if ( ! V_297 -> V_299 &&
( V_195 -> V_299 == 1 ) )
V_297 -> V_299 = true ;
V_106 = 0 ;
V_305 = F_99 ( V_325 + sizeof( struct V_96 ) ,
V_312 ,
& V_106 , V_326 -
sizeof( struct V_96 ) ) ;
if ( V_305 && V_106 > 0 ) {
V_329 = (struct V_306 * ) ( V_305 + 2 ) ;
V_327 = ( V_329 -> V_322 &
V_323 ) ;
V_327 = 1 << ( V_327 + 3 ) ;
V_297 -> V_332 = V_327 ;
}
V_328 = F_101 ( V_2 ) ;
if ( V_328 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_330 = & V_328 -> V_188 [ V_3 ] ;
V_330 -> V_190 = 0xffff ;
V_330 -> V_333 = 0xffff ;
}
}
V_132 = F_57 ( & V_2 -> V_127 ,
V_331 -> V_14 . V_51 ) ;
if ( V_132 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_330 = & V_132 -> V_188 [ V_3 ] ;
V_330 -> V_190 = 0xffff ;
V_330 -> V_333 = 0xffff ;
}
}
V_106 = 0 ;
V_305 = F_99 ( V_325 + sizeof( struct V_96 ) ,
V_334 , & V_106 ,
V_326 - sizeof( struct V_96 ) ) ;
}
void F_102 ( struct V_1 * V_2 , int V_335 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_296 * V_297 = & V_8 -> V_298 ;
if ( ( V_297 -> V_301 == 1 ) && ( V_297 -> V_299 ) ) {
if ( ! V_297 -> V_300 [ V_335 ] ) {
F_103 ( V_2 , ( T_2 ) V_335 ) ;
V_297 -> V_300 [ V_335 ] = true ;
}
}
}
