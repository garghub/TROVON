static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > V_4 )
V_2 -> V_5 = V_4 ;
else
V_2 -> V_5 = V_2 -> V_3 ;
if ( V_2 -> V_3 < V_4 ) {
V_2 -> V_5 = V_4 ;
} else {
V_2 -> V_5 = V_2 -> V_3 ;
}
F_2 ( ( V_6
L_1 ,
& V_2 -> V_7 -> V_2 , V_2 -> V_5 , V_2 -> V_8 -> V_9 ,
V_10 , & V_2 -> V_11 ) ) ;
V_2 -> V_12 = F_3 ( & V_2 -> V_7 -> V_2 ,
( V_2 -> V_5 + sizeof( struct V_13 ) )
* ( V_2 -> V_8 -> V_9 + V_10 ) + ( V_14 - 1 ) ,
& V_2 -> V_11 , V_15 ) ;
if ( V_2 -> V_12 == NULL )
return - V_16 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_17 ;
T_1 V_18 ;
int V_19 ;
if( ! V_2 -> V_12 || ! V_2 -> V_5 )
return;
V_19 = V_2 -> V_8 -> V_9 + V_10 ;
V_18 = V_2 -> V_3 + sizeof( struct V_13 ) ;
V_17 = V_18 * V_19 + V_14 - 1 ;
F_5 ( & V_2 -> V_7 -> V_2 , V_17 , V_2 -> V_12 ,
V_2 -> V_11 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_11 = 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_2 V_20 = 0 ;
T_2 V_21 = 1 ;
struct V_22 * V_23 = NULL ;
for ( V_20 = 0 , V_23 = & V_2 -> V_24 [ V_20 ] ;
V_20 < ( V_2 -> V_8 -> V_9 + V_10 ) ;
V_20 ++ , V_23 ++ ) {
if ( ( V_2 -> V_25 == 1 ) ||
( V_20 > ( ( V_2 -> V_8 -> V_9 + V_10 - 1 )
- V_2 -> V_26 ) ) ) {
V_23 -> V_27 = 0 ;
} else {
V_23 -> V_27 = V_21 ;
V_21 ++ ;
if ( V_21 == V_2 -> V_25 )
V_21 = 1 ;
}
}
}
int F_7 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_28 * V_28 ;
T_3 V_11 ;
int V_20 ;
T_2 V_29 ;
while ( ( ( V_20 = F_1 ( V_2 ) ) == - V_16 )
&& ( V_2 -> V_8 -> V_9 > ( 64 - V_10 ) ) ) {
V_29 = ( V_2 -> V_8 -> V_9 + V_10 ) >> 1 ;
V_2 -> V_8 -> V_9 = V_29 - V_10 ;
if ( V_2 -> V_30 != V_31 )
V_2 -> V_32 -> V_33 . V_34 = F_8 ( V_29 ) ;
}
if ( V_20 < 0 )
return - V_16 ;
memset ( V_2 -> V_12 , 0 ,
( V_2 -> V_5 + sizeof( struct V_13 ) ) *
( V_2 -> V_8 -> V_9 + V_10 ) ) ;
V_11 = ( V_2 -> V_11 + ( V_14 - 1 ) ) & ~ ( V_14 - 1 ) ;
V_28 = (struct V_28 * ) ( ( unsigned char * ) V_2 -> V_12 +
( V_11 - V_2 -> V_11 ) ) ;
V_28 = (struct V_28 * ) ( ( unsigned char * ) V_28 +
sizeof( struct V_13 ) ) ;
V_11 += sizeof( struct V_13 ) ;
for ( V_20 = 0 , V_23 = & V_2 -> V_24 [ V_20 ] ;
V_20 < ( V_2 -> V_8 -> V_9 + V_10 ) ;
V_20 ++ , V_23 ++ )
{
V_23 -> V_35 = 0 ;
V_23 -> V_36 = sizeof( struct V_22 ) ;
V_23 -> V_2 = V_2 ;
V_23 -> V_12 = V_28 ;
V_23 -> V_37 = ( void * ) V_23 -> V_12 -> V_37 ;
V_23 -> V_38 = V_23 + 1 ;
F_9 ( & V_23 -> V_39 , 0 ) ;
F_10 ( & V_23 -> V_40 ) ;
V_28 -> V_41 . V_42 = F_8 ( 0xffffffff ) ;
V_28 -> V_41 . V_43 =
F_11 ( V_2 -> V_3 ) ;
V_23 -> V_11 = V_11 ;
V_23 -> V_44 = V_11 +
F_12 ( struct V_45 , V_46 [ 2 ] ) ;
V_23 -> V_47 = V_11 +
F_12 ( struct V_48 , V_49 . V_50 [ 0 ] ) ;
V_28 = (struct V_28 * ) ( ( unsigned char * ) V_28 +
V_2 -> V_5 + sizeof( struct V_13 ) ) ;
V_11 = V_11 +
V_2 -> V_5 + sizeof( struct V_13 ) ;
}
F_6 ( V_2 ) ;
V_2 -> V_24 [ V_2 -> V_8 -> V_9 + V_10 - 1 ] . V_38 = NULL ;
V_2 -> V_51 = & V_2 -> V_24 [ V_2 -> V_8 -> V_9 ] ;
return 0 ;
}
struct V_22 * F_13 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_22 * V_23 ;
V_23 = & V_2 -> V_24 [ V_53 -> V_54 -> V_55 ] ;
V_23 -> V_12 -> V_41 . V_42 = 0 ;
V_23 -> type = V_56 ;
V_23 -> V_57 = NULL ;
V_23 -> V_58 = NULL ;
return V_23 ;
}
struct V_22 * F_14 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
unsigned long V_35 ;
F_15 ( & V_2 -> V_59 , V_35 ) ;
V_23 = V_2 -> V_51 ;
if( ! V_23 ) {
F_16 ( & V_2 -> V_59 , V_35 ) ;
return V_23 ;
}
V_2 -> V_51 = V_23 -> V_38 ;
F_16 ( & V_2 -> V_59 , V_35 ) ;
V_23 -> type = V_56 ;
V_23 -> V_36 = sizeof( struct V_22 ) ;
V_23 -> V_12 -> V_41 . V_42 = 0 ;
V_23 -> V_35 = 0 ;
V_23 -> V_58 = NULL ;
V_23 -> V_57 = NULL ;
return V_23 ;
}
void F_17 ( struct V_22 * V_23 )
{
unsigned long V_35 ;
if ( V_23 -> V_60 == 2 )
return;
F_15 ( & V_23 -> V_2 -> V_59 , V_35 ) ;
if ( F_18 ( V_23 -> V_35 & V_61 ) )
V_62 . V_63 ++ ;
if ( ! ( V_23 -> V_35 & V_64 ) &&
V_23 -> V_12 -> V_41 . V_42 != 0 ) {
F_19 ( V_65 L_2 ,
( void * ) V_23 ,
F_20 ( V_23 -> V_12 -> V_41 . V_42 ) ) ;
}
V_23 -> V_38 = V_23 -> V_2 -> V_51 ;
V_23 -> V_2 -> V_51 = V_23 ;
F_16 ( & V_23 -> V_2 -> V_59 , V_35 ) ;
}
void F_21 ( struct V_22 * V_23 )
{
struct V_28 * V_28 = V_23 -> V_12 ;
memset ( & V_28 -> V_41 , 0 , sizeof( struct V_66 ) ) ;
V_28 -> V_41 . V_67 = V_68 ;
V_28 -> V_41 . V_69 = F_11 ( V_23 -> V_2 -> V_3 ) ;
V_28 -> V_41 . V_42 = F_8 ( V_70 | V_71 | V_72 | V_73 ) ;
V_28 -> V_41 . V_74 . V_75 = F_8 ( V_23 -> V_11 ) ;
V_28 -> V_41 . V_43 = F_11 ( V_23 -> V_2 -> V_3 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
struct V_28 * V_28 = V_23 -> V_12 ;
V_28 -> V_41 . V_42 = 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_76 , struct V_77 * * V_78 , T_2 * V_79 , unsigned long * V_80 )
{
struct V_81 * V_82 ;
unsigned long V_83 ;
V_82 = & V_2 -> V_84 -> V_85 [ V_76 ] ;
V_83 = * V_79 = F_20 ( * ( V_82 -> V_86 . V_87 ) ) ;
if ( V_83 != F_20 ( * ( V_82 -> V_86 . V_88 ) ) ) {
if ( -- V_83 == 0 ) {
if ( V_76 == V_89 )
V_83 = V_90 ;
else
V_83 = V_91 ;
}
if ( V_83 != F_20 ( * ( V_82 -> V_86 . V_88 ) ) )
* V_80 = 1 ;
}
if ( V_76 == V_89 ) {
if ( * V_79 >= V_90 )
* V_79 = 0 ;
} else {
if ( * V_79 >= V_91 )
* V_79 = 0 ;
}
if ( ( * V_79 + 1 ) == F_20 ( * ( V_82 -> V_86 . V_88 ) ) ) {
F_19 ( V_65 L_3 ,
V_76 , F_24 ( & V_82 -> V_92 ) ) ;
return 0 ;
} else {
* V_78 = V_82 -> V_93 + * V_79 ;
return 1 ;
}
}
int F_25 ( struct V_1 * V_2 , T_2 * V_79 , T_2 V_76 , struct V_28 * V_28 , int V_94 , struct V_22 * V_23 , unsigned long * V_80 )
{
struct V_77 * V_78 = NULL ;
int V_95 = 0 ;
if ( V_76 == V_89 ) {
while ( ! F_23 ( V_2 , V_76 , & V_78 , V_79 , V_80 ) ) {
F_19 ( V_96 L_4 ) ;
}
V_78 -> V_36 = F_8 ( F_26 ( V_28 -> V_41 . V_69 ) ) ;
V_95 = 1 ;
} else {
while ( ! F_23 ( V_2 , V_76 , & V_78 , V_79 , V_80 ) ) {
}
V_78 -> V_36 = F_8 ( F_26 ( V_28 -> V_41 . V_69 ) ) ;
V_78 -> V_97 = V_28 -> V_41 . V_98 ;
V_28 -> V_41 . V_74 . V_75 = V_28 -> V_41 . V_98 ;
V_95 = 0 ;
}
if ( V_95 )
V_78 -> V_97 = F_8 ( V_23 -> V_11 ) ;
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = F_28 ( V_2 -> V_7 ) ;
if ( F_29 ( V_100 ) ) {
return 1 ;
}
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_30 ( T_4 V_101 , struct V_22 * V_23 , unsigned long V_36 ,
int V_102 , int V_94 , int V_103 , T_5 V_58 ,
void * V_57 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_28 * V_28 = V_23 -> V_12 ;
unsigned long V_35 = 0 ;
unsigned long V_104 = 0 ;
unsigned long V_105 = 0 ;
if ( ! ( V_28 -> V_41 . V_42 & F_8 ( V_70 ) ) )
return - V_106 ;
if ( V_28 -> V_41 . V_42 & F_8 ( V_107 ) )
return - V_108 ;
V_23 -> V_35 = 0 ;
if ( V_94 && ! V_103 ) {
return - V_108 ;
} else if ( ! V_94 && V_103 ) {
V_28 -> V_41 . V_42 |= F_8 ( V_109 | V_110 ) ;
F_31 ( V_62 . V_111 ) ;
} else if ( ! V_94 && ! V_103 ) {
V_28 -> V_41 . V_42 |= F_8 ( V_112 ) ;
F_31 ( V_62 . V_113 ) ;
} else if ( V_94 && V_103 ) {
V_28 -> V_41 . V_42 |= F_8 ( V_110 ) ;
F_31 ( V_62 . V_114 ) ;
}
V_28 -> V_41 . V_98 =
F_8 ( ( ( T_2 ) ( V_23 - V_2 -> V_24 ) ) << 2 ) ;
V_28 -> V_41 . V_115 =
F_8 ( ( ( ( T_2 ) ( V_23 - V_2 -> V_24 ) ) << 2 ) + 1 ) ;
V_28 -> V_41 . V_116 = F_11 ( V_101 ) ;
V_28 -> V_41 . V_42 |= F_8 ( V_117 ) ;
V_28 -> V_41 . V_69 = F_11 ( sizeof( struct V_66 ) + V_36 ) ;
if ( F_26 ( V_28 -> V_41 . V_69 ) > F_26 ( V_28 -> V_41 . V_43 ) ) {
return - V_118 ;
}
V_28 -> V_41 . V_42 |= F_8 ( V_119 ) ;
if ( ! V_94 ) {
V_23 -> V_58 = V_58 ;
V_23 -> V_57 = V_57 ;
V_23 -> V_35 = V_120 ;
}
V_23 -> V_60 = 0 ;
F_31 ( V_62 . V_121 ) ;
F_2 ( ( V_122 L_5 ) ) ;
F_2 ( ( V_122 L_6 , F_20 ( V_28 -> V_41 . V_116 ) ) ) ;
F_2 ( ( V_122 L_7 , F_20 ( ( (struct V_123 * ) F_32 ( V_23 ) ) -> V_101 ) ) ) ;
F_2 ( ( V_122 L_8 , F_20 ( V_28 -> V_41 . V_42 ) ) ) ;
F_2 ( ( V_122 L_9 , V_23 -> V_12 ) ) ;
F_2 ( ( V_122 L_10 , ( V_124 ) V_23 -> V_11 ) ) ;
F_2 ( ( V_122 L_11 , V_23 ) ) ;
if ( ! V_2 -> V_84 )
return - V_106 ;
if ( V_94 ) {
F_15 ( & V_2 -> V_125 , V_104 ) ;
if ( V_2 -> V_126 >= V_10 ) {
F_19 ( V_6 L_12 ,
V_2 -> V_126 ) ;
F_16 ( & V_2 -> V_125 , V_104 ) ;
return - V_106 ;
}
V_2 -> V_126 ++ ;
F_16 ( & V_2 -> V_125 , V_104 ) ;
F_15 ( & V_23 -> V_40 , V_35 ) ;
}
if ( V_2 -> V_127 ) {
if ( V_94 )
F_16 ( & V_23 -> V_40 , V_35 ) ;
F_15 ( & V_2 -> V_128 , V_105 ) ;
if ( V_2 -> V_129 ) {
F_33 ( & V_23 -> V_130 , & V_2 -> V_131 ) ;
F_16 ( & V_2 -> V_128 , V_105 ) ;
} else {
V_2 -> V_129 = V_23 ;
F_16 ( & V_2 -> V_128 , V_105 ) ;
F_34 ( V_2 , V_132 ,
( T_2 ) V_23 -> V_11 , 0 , 0 , 0 , 0 , 0 ,
NULL , NULL , NULL , NULL , NULL ) ;
}
if ( V_94 ) {
V_23 -> V_35 |= V_133 ;
if ( F_35 ( & V_23 -> V_39 ) ) {
V_23 -> V_35 &= ~ V_133 ;
return - V_134 ;
}
return 0 ;
}
return - V_135 ;
}
if ( F_36 ( V_23 ) != 0 ) {
F_19 ( V_96 L_13 ) ;
if ( V_94 ) {
F_16 ( & V_23 -> V_40 , V_35 ) ;
F_15 ( & V_2 -> V_125 , V_104 ) ;
V_2 -> V_126 -- ;
F_16 ( & V_2 -> V_125 , V_104 ) ;
}
return - V_106 ;
}
if ( V_94 ) {
F_16 ( & V_23 -> V_40 , V_35 ) ;
if ( V_94 < 0 ) {
unsigned long V_136 = V_137 + ( 180 * V_138 ) ;
while ( F_37 ( & V_23 -> V_39 ) ) {
int V_139 ;
if ( F_38 ( V_136 ) ) {
struct V_81 * V_82 = & V_2 -> V_84 -> V_85 [ V_89 ] ;
F_39 ( & V_82 -> V_92 ) ;
if ( V_94 == - 1 ) {
F_19 ( V_96 L_14
L_15
L_16
L_17 ) ;
}
return - V_140 ;
}
if ( F_27 ( V_2 ) )
return - V_134 ;
if ( ( V_139 = F_40 ( V_2 ) ) > 0 ) {
if ( V_94 == - 1 ) {
F_19 ( V_96 L_18
L_19 ,
V_139 ) ;
}
return - V_134 ;
}
F_41 () ;
}
} else if ( F_35 ( & V_23 -> V_39 ) ) {
}
F_15 ( & V_23 -> V_40 , V_35 ) ;
if ( V_23 -> V_60 == 0 ) {
V_23 -> V_60 = 2 ;
F_16 ( & V_23 -> V_40 , V_35 ) ;
return - V_141 ;
}
F_16 ( & V_23 -> V_40 , V_35 ) ;
F_42 ( V_23 -> V_60 == 0 ) ;
if( F_18 ( V_23 -> V_35 & V_61 ) )
return - V_140 ;
return 0 ;
}
if ( V_103 )
return - V_135 ;
else
return 0 ;
}
int F_43 ( T_6 V_101 , struct V_22 * V_23 , T_5 V_58 ,
void * V_57 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
int V_94 ;
unsigned long V_35 = 0 ;
unsigned long V_104 = 0 ;
V_23 -> V_35 = ( V_120 | V_64 ) ;
if ( V_58 ) {
V_94 = 0 ;
V_23 -> V_58 = V_58 ;
V_23 -> V_57 = V_57 ;
} else
V_94 = 1 ;
if ( V_101 == V_142 ) {
struct V_45 * V_143 =
(struct V_45 * ) V_23 -> V_12 ;
V_143 -> V_144 = V_101 ;
V_143 -> V_145 =
F_8 ( ( ( ( T_2 ) ( V_23 - V_2 -> V_24 ) ) << 2 ) + 1 ) ;
V_23 -> V_35 |= V_146 ;
} else if ( V_101 != V_147 )
return - V_108 ;
if ( V_94 ) {
F_15 ( & V_2 -> V_125 , V_104 ) ;
if ( V_2 -> V_126 >= V_10 ) {
F_16 ( & V_2 -> V_125 , V_104 ) ;
return - V_106 ;
}
V_2 -> V_126 ++ ;
F_16 ( & V_2 -> V_125 , V_104 ) ;
F_15 ( & V_23 -> V_40 , V_35 ) ;
}
if ( F_36 ( V_23 ) != 0 ) {
if ( V_94 ) {
F_16 ( & V_23 -> V_40 , V_35 ) ;
F_15 ( & V_2 -> V_125 , V_104 ) ;
V_2 -> V_126 -- ;
F_16 ( & V_2 -> V_125 , V_104 ) ;
}
return - V_106 ;
}
F_31 ( V_62 . V_148 ) ;
if ( V_94 ) {
F_16 ( & V_23 -> V_40 , V_35 ) ;
if ( F_27 ( V_2 ) )
return - V_134 ;
V_23 -> V_35 |= V_133 ;
if ( F_35 ( & V_23 -> V_39 ) )
V_23 -> V_60 = 2 ;
V_23 -> V_35 &= ~ ( V_133 ) ;
F_15 ( & V_23 -> V_40 , V_35 ) ;
if ( ( V_23 -> V_60 == 0 ) || ( V_23 -> V_60 == 2 ) ) {
V_23 -> V_60 = 2 ;
F_16 ( & V_23 -> V_40 , V_35 ) ;
return - V_141 ;
}
F_16 ( & V_23 -> V_40 , V_35 ) ;
F_44 ( V_23 -> V_60 == 0 ) ;
if ( F_18 ( V_23 -> V_35 & V_61 ) )
return - V_140 ;
return 0 ;
}
return - V_135 ;
}
int F_45 ( struct V_1 * V_2 , struct V_81 * V_82 , struct V_77 * * V_78 )
{
T_2 V_79 ;
int V_149 ;
if ( F_20 ( * V_82 -> V_86 . V_87 ) == F_20 ( * V_82 -> V_86 . V_88 ) ) {
V_149 = 0 ;
} else {
if ( F_20 ( * V_82 -> V_86 . V_88 ) >= V_82 -> V_150 )
V_79 = 0 ;
else
V_79 = F_20 ( * V_82 -> V_86 . V_88 ) ;
* V_78 = V_82 -> V_93 + V_79 ;
V_149 = 1 ;
}
return ( V_149 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_81 * V_82 , T_2 V_76 )
{
int V_151 = 0 ;
T_2 V_152 ;
if ( ( F_20 ( * V_82 -> V_86 . V_87 ) + 1 ) == F_20 ( * V_82 -> V_86 . V_88 ) )
V_151 = 1 ;
if ( F_20 ( * V_82 -> V_86 . V_88 ) >= V_82 -> V_150 )
* V_82 -> V_86 . V_88 = F_8 ( 1 ) ;
else
F_47 ( V_82 -> V_86 . V_88 , 1 ) ;
if ( V_151 ) {
switch ( V_76 ) {
case V_153 :
V_152 = V_154 ;
break;
case V_155 :
V_152 = V_156 ;
break;
default:
F_48 () ;
return;
}
F_49 ( V_2 , V_152 ) ;
}
}
int F_50 ( struct V_22 * V_23 , unsigned short V_36 )
{
struct V_28 * V_28 = V_23 -> V_12 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_81 * V_82 ;
unsigned long V_157 = 0 ;
unsigned long V_158 ;
if ( V_2 -> V_30 == V_159 ||
V_2 -> V_30 == V_160 ||
V_2 -> V_30 == V_31 ) {
F_51 ( V_28 ) ;
return 0 ;
}
if ( V_28 -> V_41 . V_42 == 0 ) {
if ( V_2 -> V_30 == V_161 )
F_51 ( V_28 ) ;
return 0 ;
}
if ( V_28 -> V_41 . V_67 != V_68 &&
V_28 -> V_41 . V_67 != V_162 &&
V_28 -> V_41 . V_67 != V_163 ) {
if ( V_2 -> V_30 == V_161 )
F_51 ( V_28 ) ;
return - V_108 ;
}
if ( V_28 -> V_41 . V_42 & F_8 ( V_164 ) ) {
if ( V_2 -> V_30 == V_161 ) {
F_51 ( V_28 ) ;
} else {
T_2 V_79 ;
V_28 -> V_41 . V_42 |= F_8 ( V_165 ) ;
if ( V_36 ) {
V_36 += sizeof( struct V_66 ) ;
if ( V_36 > F_26 ( V_28 -> V_41 . V_43 ) )
return - V_118 ;
V_28 -> V_41 . V_69 = F_11 ( V_36 ) ;
}
V_82 = & V_2 -> V_84 -> V_85 [ V_166 ] ;
F_15 ( V_82 -> V_167 , V_158 ) ;
F_25 ( V_2 , & V_79 , V_166 , V_28 , 1 , NULL , & V_157 ) ;
* ( V_82 -> V_86 . V_87 ) = F_8 ( V_79 + 1 ) ;
F_16 ( V_82 -> V_167 , V_158 ) ;
if ( ! ( V_157 & ( int ) V_62 . V_168 ) )
F_49 ( V_2 , V_166 ) ;
}
} else {
F_19 ( V_65 L_20
L_21 ) ;
F_48 () ;
}
return 0 ;
}
int F_52 ( struct V_22 * V_23 )
{
struct V_28 * V_28 = V_23 -> V_12 ;
if ( V_23 -> V_35 & V_64 ) {
F_22 ( V_23 ) ;
return 0 ;
}
if ( V_28 -> V_41 . V_42 == 0 || V_23 -> V_60 == 2 )
return 0 ;
if ( V_28 -> V_41 . V_67 != V_68 &&
V_28 -> V_41 . V_67 != V_162 &&
V_28 -> V_41 . V_67 != V_163 )
return - V_108 ;
if( ( V_28 -> V_41 . V_42 & F_8 ( V_117 ) ) &&
( V_28 -> V_41 . V_42 & F_8 ( V_107 ) ) )
{
F_22 ( V_23 ) ;
}
else if( V_28 -> V_41 . V_42 & F_8 ( V_117 ) )
{
F_22 ( V_23 ) ;
} else if( V_28 -> V_41 . V_42 & F_8 ( V_70 ) ) {
F_22 ( V_23 ) ;
} else {
F_48 () ;
}
return 0 ;
}
void F_53 ( struct V_1 * V_2 , T_2 V_169 )
{
char * V_170 = V_2 -> V_171 ;
if ( V_2 -> V_172 )
{
int V_173 = V_169 & 0xffff ;
int V_174 = ( V_169 >> 16 ) & 0xffff ;
if ( V_173 > 255 )
V_173 = 255 ;
if ( V_170 [ V_173 ] != 0 )
V_170 [ V_173 ] = 0 ;
if ( V_174 == V_175 )
F_19 ( V_65 L_22 , V_2 -> V_176 , V_170 ) ;
else
F_19 ( V_6 L_22 , V_2 -> V_176 , V_170 ) ;
}
memset ( V_170 , 0 , 256 ) ;
}
static inline int F_54 ( struct V_177 * V_178 , T_7 V_79 )
{
return F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ V_79 ] ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_177 * V_178 )
{
switch ( F_54 ( V_178 , 1 ) ) {
case V_180 :
if ( F_54 ( V_178 , 2 ) )
F_56 ( & V_2 -> V_7 -> V_2 , L_23 ,
F_54 ( V_178 , 2 ) ) ;
else
F_56 ( & V_2 -> V_7 -> V_2 , L_24 ) ;
break;
case V_181 :
if ( F_54 ( V_178 , 2 ) )
F_56 ( & V_2 -> V_7 -> V_2 , L_25 ,
F_54 ( V_178 , 2 ) ) ;
else
F_56 ( & V_2 -> V_7 -> V_2 , L_26 ) ;
break;
}
}
static void F_57 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_28 * V_28 = V_23 -> V_12 ;
struct V_177 * V_178 = (struct V_177 * ) V_28 -> V_37 ;
T_2 V_182 , V_183 , V_184 , V_185 ;
struct V_186 * V_187 ;
enum {
V_188 ,
V_189 ,
V_190 ,
V_191
} V_192 = V_188 ;
if ( ! V_2 || ! V_2 -> V_193 )
return;
V_185 = V_182 = V_183 = V_184 = ( T_2 ) - 1 ;
switch ( F_20 ( V_178 -> V_101 ) ) {
case V_194 :
switch ( F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 0 ] ) ) {
case V_195 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( ( V_185 >> 28 ) ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_182 = ( V_185 >> 24 ) & 0xF ;
if ( V_182 >= V_2 -> V_196 ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_183 = V_185 & 0xFFFF ;
if ( V_183 >= V_2 -> V_197 ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_184 = ( V_185 >> 16 ) & 0xFF ;
V_185 = ( T_2 ) - 1 ;
V_182 = F_58 ( V_182 ) ;
V_192 = V_189 ;
break;
case V_198 :
case V_199 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( V_185 >= V_2 -> V_200 )
break;
if ( ( V_2 != NULL ) && ( V_2 -> V_8 != NULL ) ) {
V_187 = F_59 ( V_2 -> V_8 ,
F_60 ( V_185 ) ,
F_61 ( V_185 ) ,
F_62 ( V_185 ) ) ;
if ( V_187 ) {
V_2 -> V_193 [ V_185 ] . V_201 = V_191 ;
V_2 -> V_193 [ V_185 ] . V_202 = V_203 ;
V_2 -> V_193 [ V_185 ] . V_204 = V_137 ;
F_63 ( V_187 ) ;
}
}
}
if ( V_185 != ( T_2 ) - 1 ) {
if ( V_185 >= V_2 -> V_200 )
break;
if ( ( V_2 -> V_193 [ V_185 ] . V_202 ==
F_20 ( * ( V_179 * ) V_178 -> V_37 ) ) &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) )
V_2 -> V_193 [ V_185 ] . V_202 = 0 ;
} else for ( V_185 = 0 ;
V_185 < V_2 -> V_200 ; ++ V_185 ) {
if ( ( V_2 -> V_193 [ V_185 ] . V_202 ==
F_20 ( * ( V_179 * ) V_178 -> V_37 ) ) &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) )
V_2 -> V_193 [ V_185 ] . V_202 = 0 ;
}
break;
case V_206 :
switch ( F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 0 ] ) ) {
case V_207 :
V_2 -> V_208 =
( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] == F_8 ( 3 ) ) ;
break;
case V_209 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( V_185 >= V_2 -> V_200 )
break;
V_2 -> V_193 [ V_185 ] . V_201 = V_190 ;
V_2 -> V_193 [ V_185 ] . V_202 =
V_203 ;
V_2 -> V_193 [ V_185 ] . V_204 = V_137 ;
break;
case V_210 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( V_185 >= V_2 -> V_200 )
break;
V_2 -> V_193 [ V_185 ] . V_201 = V_189 ;
V_2 -> V_193 [ V_185 ] . V_202 =
V_203 ;
V_2 -> V_193 [ V_185 ] . V_204 = V_137 ;
break;
case V_211 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( V_185 >= V_2 -> V_200 )
break;
if ( V_2 -> V_193 [ V_185 ] . V_202 &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) )
break;
V_2 -> V_193 [ V_185 ] . V_201 = V_191 ;
V_2 -> V_193 [ V_185 ] . V_202 =
V_203 ;
V_2 -> V_193 [ V_185 ] . V_204 = V_137 ;
break;
case V_203 :
break;
case V_212 :
case V_213 :
V_185 = F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] ) ;
if ( ( V_185 >> 28 ) ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_182 = ( V_185 >> 24 ) & 0xF ;
if ( V_182 >= V_2 -> V_196 ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_183 = V_185 & 0xFFFF ;
if ( V_183 >= V_2 -> V_197 ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_184 = ( V_185 >> 16 ) & 0xFF ;
V_185 = ( T_2 ) - 1 ;
V_182 = F_58 ( V_182 ) ;
V_192 =
( ( ( V_179 * ) V_178 -> V_37 ) [ 0 ] ==
F_8 ( V_212 ) ) ? V_190 : V_189 ;
if ( V_192 == V_190 ) {
V_187 = F_59 ( V_2 -> V_8 ,
V_182 ,
V_183 ,
V_184 ) ;
if ( V_187 ) {
F_65 ( V_187 ) ;
F_63 ( V_187 ) ;
}
}
break;
case V_214 :
if ( V_2 -> V_215 )
break;
switch ( F_20 ( ( ( V_179 * ) V_178 -> V_37 ) [ 3 ] ) ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_185 = F_20 (
( ( V_179 * ) V_178 -> V_37 ) [ 2 ] ) ;
if ( ( V_185 >> 28 ) ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_182 = ( V_185 >> 24 ) & 0xF ;
if ( V_182 >= V_2 -> V_196 ) {
V_185 = ( T_2 ) - 1 ;
break;
}
V_183 = V_185 & 0xFFFF ;
V_184 = ( V_185 >> 16 ) & 0xFF ;
V_185 = ( T_2 ) - 1 ;
if ( V_183 >= V_2 -> V_197 ) {
if ( ( 0x2000 <= V_183 ) || V_184 || V_182 ||
( ( V_182 = ( V_183 >> 7 ) & 0x3F ) >=
V_2 -> V_196 ) )
break;
V_184 = ( V_183 >> 4 ) & 7 ;
V_183 &= 0xF ;
}
V_182 = F_58 ( V_182 ) ;
V_192 =
( ( ( ( V_179 * ) V_178 -> V_37 ) [ 3 ]
== F_8 ( V_216 ) ) ||
( ( ( V_179 * ) V_178 -> V_37 ) [ 3 ]
== F_8 ( V_218 ) ) ) ?
V_190 : V_189 ;
break;
}
case V_220 :
F_55 ( V_2 , V_178 ) ;
break;
}
if ( V_185 != ( T_2 ) - 1 ) {
if ( V_185 >= V_2 -> V_200 )
break;
if ( ( V_2 -> V_193 [ V_185 ] . V_202 ==
F_20 ( * ( V_179 * ) V_178 -> V_37 ) ) &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) )
V_2 -> V_193 [ V_185 ] . V_202 = 0 ;
} else for ( V_185 = 0 ;
V_185 < V_2 -> V_200 ; ++ V_185 ) {
if ( ( V_2 -> V_193 [ V_185 ] . V_202 ==
F_20 ( * ( V_179 * ) V_178 -> V_37 ) ) &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) )
V_2 -> V_193 [ V_185 ] . V_202 = 0 ;
}
break;
case V_221 :
if ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] == F_8 ( V_222 ) &&
( ( ( V_179 * ) V_178 -> V_37 ) [ 6 ] == ( ( V_179 * ) V_178 -> V_37 ) [ 5 ] ||
( ( V_179 * ) V_178 -> V_37 ) [ 4 ] == F_8 ( V_223 ) ) ) {
for ( V_185 = 0 ;
V_185 < V_2 -> V_200 ;
++ V_185 ) {
V_2 -> V_193 [ V_185 ] . V_202 =
V_211 ;
V_2 -> V_193 [ V_185 ] . V_201 = V_190 ;
V_2 -> V_193 [ V_185 ] . V_204 =
V_137 ;
}
}
if ( ( ( V_179 * ) V_178 -> V_37 ) [ 1 ] == F_8 ( V_222 ) &&
( ( V_179 * ) V_178 -> V_37 ) [ 6 ] == 0 &&
( ( V_179 * ) V_178 -> V_37 ) [ 4 ] == F_8 ( V_224 ) ) {
for ( V_185 = 0 ;
V_185 < V_2 -> V_200 ;
++ V_185 ) {
V_2 -> V_193 [ V_185 ] . V_202 =
V_211 ;
V_2 -> V_193 [ V_185 ] . V_201 = V_189 ;
V_2 -> V_193 [ V_185 ] . V_204 =
V_137 ;
}
}
break;
}
V_185 = 0 ;
V_225:
if ( V_192 == V_188 )
for (; V_185 < V_2 -> V_200 ; ++ V_185 ) {
if ( ( V_2 -> V_193 [ V_185 ] . V_202 == 0 ) &&
( V_2 -> V_193 [ V_185 ] . V_201 != V_188 ) &&
F_64 ( V_137 , V_2 -> V_193 [ V_185 ] . V_204 + V_205 ) ) {
V_192 =
V_2 -> V_193 [ V_185 ] . V_201 ;
V_2 -> V_193 [ V_185 ] . V_201 = V_188 ;
V_182 = F_60 ( V_185 ) ;
V_183 = F_61 ( V_185 ) ;
V_184 = F_62 ( V_185 ) ;
break;
}
}
if ( V_192 == V_188 )
return;
if ( ! V_2 || ! V_2 -> V_8 )
return;
if ( ( V_182 == V_226 ) &&
( V_192 != V_188 ) ) {
if ( V_2 -> V_193 [ V_185 ] . V_227 == 1 )
V_2 -> V_193 [ V_185 ] . V_227 = 2 ;
F_66 ( V_2 , V_185 ) ;
}
V_187 = F_59 ( V_2 -> V_8 , V_182 , V_183 , V_184 ) ;
if ( V_187 ) {
switch ( V_192 ) {
case V_189 :
#if ( F_67 ( V_228 ) )
F_65 ( V_187 ) ;
#else
if ( F_68 ( V_187 ) ) {
F_69 ( V_187 , V_229 ) ;
F_70 ( V_6 , V_187 ,
L_27 ,
( V_182 == V_226 ) ?
L_28 :
L_29 ) ;
}
#endif
break;
case V_190 :
if ( ! F_68 ( V_187 ) ) {
F_70 ( V_6 , V_187 ,
L_30 ,
( V_182 == V_226 ) ?
L_31 :
L_29 ) ;
F_69 ( V_187 , V_230 ) ;
}
case V_191 :
if ( ( V_182 == V_226 )
&& ( ! V_2 -> V_193 [ V_185 ] . V_227 ) ) {
#if ( F_67 ( V_228 ) )
F_65 ( V_187 ) ;
#else
if ( ! F_68 ( V_187 ) )
break;
F_69 ( V_187 , V_229 ) ;
F_70 ( V_6 , V_187 ,
L_27 ,
L_32 ) ;
#endif
break;
}
F_71 ( & V_187 -> V_231 ) ;
default:
break;
}
F_63 ( V_187 ) ;
V_192 = V_188 ;
}
if ( V_192 == V_190 )
F_72 ( V_2 -> V_8 , V_182 , V_183 , V_184 ) ;
if ( V_182 == V_226 ) {
V_185 ++ ;
V_192 = V_188 ;
goto V_225;
}
}
static int F_73 ( struct V_1 * V_232 , int V_233 , T_6 V_234 )
{
int V_79 , V_235 ;
int V_236 ;
struct V_237 * V_238 ;
struct V_186 * V_2 ;
struct V_52 * V_101 ;
struct V_52 * V_239 ;
int V_240 = 0 ;
int V_241 ;
T_8 V_242 ;
int V_243 = 0 ;
V_238 = V_232 -> V_8 ;
F_74 ( V_238 ) ;
F_75 ( V_232 ) ;
if ( V_232 -> V_244 -> V_245 != V_246 -> V_245 ) {
F_76 ( V_238 -> V_247 ) ;
F_77 ( V_232 -> V_244 ) ;
V_240 = 1 ;
}
V_241 = V_233 ? 0 : F_40 ( V_232 ) ;
V_236 = F_78 ( V_232 , V_241 , V_234 ) ;
if ( V_236 )
goto V_248;
V_236 = 1 ;
V_243 = V_232 -> V_8 -> V_9 + V_10 ;
for ( V_79 = 0 ; V_79 < V_243 ; V_79 ++ ) {
struct V_22 * V_22 = & V_232 -> V_24 [ V_79 ] ;
V_179 V_42 = V_22 -> V_12 -> V_41 . V_42 ;
bool V_249 = false ;
if ( ! ( V_42 & F_8 ( V_112 | V_109 ) ) &&
( V_42 & F_8 ( V_110 ) ) )
V_249 = true ;
if ( V_249
|| V_22 -> V_35 & V_133 ) {
unsigned long V_250 ;
F_15 ( & V_22 -> V_40 , V_250 ) ;
F_79 ( & V_22 -> V_39 ) ;
F_16 ( & V_22 -> V_40 , V_250 ) ;
F_41 () ;
V_236 = 0 ;
}
}
if ( V_236 == 0 )
F_80 ( 2 ) ;
V_79 = V_232 -> V_251 ;
F_4 ( V_232 ) ;
F_5 ( & V_232 -> V_7 -> V_2 , V_232 -> V_252 , V_232 -> V_253 ,
V_232 -> V_254 ) ;
V_232 -> V_253 = NULL ;
V_232 -> V_254 = 0 ;
F_51 ( V_232 -> V_84 ) ;
V_232 -> V_84 = NULL ;
F_81 ( V_232 ) ;
F_51 ( V_232 -> V_193 ) ;
V_232 -> V_193 = NULL ;
V_242 = F_82 ( 32 ) ;
V_235 = F_83 ( V_79 ) -> V_235 ;
if ( V_235 & V_255 )
V_236 = F_84 ( V_232 -> V_7 , V_242 ) ;
else if ( ! ( V_235 & V_256 ) )
V_236 = F_84 ( V_232 -> V_7 , V_242 ) ;
else
V_236 = F_85 ( V_232 -> V_7 , V_242 ) ;
if ( V_235 & V_255 && ! V_236 ) {
V_242 = F_82 ( 31 ) ;
V_236 = F_85 ( V_232 -> V_7 , V_242 ) ;
}
if ( V_236 )
goto V_248;
if ( ( V_236 = ( * ( F_83 ( V_79 ) -> V_32 ) ) ( V_232 ) ) )
goto V_248;
if ( V_240 ) {
V_232 -> V_244 = F_86 ( V_257 , V_232 , L_33 ,
V_232 -> V_176 ) ;
if ( F_87 ( V_232 -> V_244 ) ) {
V_236 = F_88 ( V_232 -> V_244 ) ;
goto V_248;
}
}
( void ) F_89 ( V_232 ) ;
if ( ( V_235 & V_258 ) && ( V_238 -> V_259 > 34 ) ) {
V_238 -> V_259 = 34 ;
V_238 -> V_260 = ( V_238 -> V_259 * 8 ) + 112 ;
}
if ( ( V_235 & V_261 ) && ( V_238 -> V_259 > 17 ) ) {
V_238 -> V_259 = 17 ;
V_238 -> V_260 = ( V_238 -> V_259 * 8 ) + 112 ;
}
F_90 ( V_232 , 1 ) ;
F_91 ( V_232 ) ;
V_239 = NULL ;
F_92 (dev, host) {
unsigned long V_35 ;
F_15 ( & V_2 -> V_262 , V_35 ) ;
F_93 (command, &dev->cmd_list, list)
if ( V_101 -> V_263 . V_264 == V_265 ) {
V_101 -> V_263 . V_266 = (struct V_267 * ) V_239 ;
V_239 = V_101 ;
}
F_16 ( & V_2 -> V_262 , V_35 ) ;
}
while ( ( V_101 = V_239 ) ) {
V_239 = (struct V_52 * ) V_101 -> V_263 . V_266 ;
V_101 -> V_263 . V_266 = NULL ;
V_101 -> V_268 = V_269 << 16
| V_270 << 8
| V_271 ;
V_101 -> V_263 . V_264 = V_272 ;
V_101 -> V_273 ( V_101 ) ;
}
F_92 (dev, host) {
if ( ! F_68 ( V_2 ) ) {
F_70 ( V_6 , V_2 , L_34 ) ;
F_65 ( V_2 ) ;
F_63 ( V_2 ) ;
}
}
V_236 = 0 ;
V_248:
V_232 -> V_274 = 0 ;
F_94 ( V_238 ) ;
if ( ! V_236 ) {
F_56 ( & V_232 -> V_7 -> V_2 , L_35 ) ;
F_95 ( V_238 ) ;
}
if ( V_240 ) {
F_96 ( V_238 -> V_247 ) ;
}
return V_236 ;
}
int F_97 ( struct V_1 * V_232 , int V_233 , T_6 V_234 )
{
unsigned long V_250 = 0 ;
int V_236 ;
struct V_237 * V_238 ;
int V_241 ;
if ( F_98 ( & V_232 -> V_59 , V_250 ) == 0 )
return - V_106 ;
if ( V_232 -> V_274 ) {
F_16 ( & V_232 -> V_59 , V_250 ) ;
return - V_106 ;
}
V_232 -> V_274 = 1 ;
F_16 ( & V_232 -> V_59 , V_250 ) ;
V_238 = V_232 -> V_8 ;
F_74 ( V_238 ) ;
if ( V_233 < 2 ) for ( V_236 = 60 ; V_236 ; -- V_236 ) {
struct V_186 * V_2 ;
struct V_52 * V_101 ;
int V_275 = 0 ;
F_92 (dev, host) {
F_15 ( & V_2 -> V_262 , V_250 ) ;
F_93 (command, &dev->cmd_list, list) {
if ( V_101 -> V_263 . V_264 == V_265 ) {
V_275 ++ ;
break;
}
}
F_16 ( & V_2 -> V_262 , V_250 ) ;
if ( V_275 )
break;
}
if ( V_275 == 0 )
break;
F_80 ( 1 ) ;
}
if ( V_233 < 2 )
F_99 ( V_232 ) ;
F_15 ( V_238 -> V_247 , V_250 ) ;
V_241 = V_233 ? V_233 :
( V_276 != 0 && V_276 != 1 ) ;
V_236 = F_73 ( V_232 , V_241 , V_234 ) ;
F_16 ( V_238 -> V_247 , V_250 ) ;
if ( ( V_233 < 2 ) && ( V_236 == - V_277 ) ) {
struct V_22 * V_278 = F_14 ( V_232 ) ;
if ( V_278 ) {
struct V_279 * V_280 ;
int V_149 ;
F_21 ( V_278 ) ;
V_280 = (struct V_279 * ) F_32 ( V_278 ) ;
V_280 -> V_101 = F_8 ( V_281 ) ;
V_280 -> type = F_8 ( V_282 ) ;
V_280 -> V_136 = F_8 ( 1 ) ;
V_280 -> V_283 = F_8 ( 1 ) ;
V_280 -> V_284 = F_8 ( 1 ) ;
V_280 -> V_285 = F_8 ( 0 ) ;
V_149 = F_30 ( V_286 ,
V_278 ,
sizeof( struct V_279 ) ,
V_287 ,
- 2 , 1 ,
NULL , NULL ) ;
if ( V_149 >= 0 )
F_52 ( V_278 ) ;
if ( V_149 != - V_141 )
F_17 ( V_278 ) ;
}
}
return V_236 ;
}
int F_100 ( struct V_1 * V_232 )
{
int V_288 ;
unsigned long V_289 , V_250 = 0 ;
struct V_290 * V_78 ;
if ( F_98 ( & V_232 -> V_59 , V_250 ) == 0 )
return 0 ;
if ( V_232 -> V_274 || ! ( V_288 = F_40 ( V_232 ) ) ) {
F_16 ( & V_232 -> V_59 , V_250 ) ;
return 0 ;
}
V_232 -> V_274 = 1 ;
V_289 = V_137 / V_138 ;
V_78 = V_232 -> V_291 . V_38 ;
while ( V_78 != & V_232 -> V_291 ) {
struct V_292 * V_278 = F_101 ( V_78 , struct V_292 , V_38 ) ;
struct V_28 * V_28 ;
struct V_22 * V_22 ;
if ( V_278 -> V_285 > 20 ) {
T_2 V_293 = V_278 -> V_137 ;
if ( ( V_289 - V_293 ) > V_294 ) {
V_78 = V_78 -> V_38 ;
F_102 ( V_232 , V_278 ) ;
continue;
}
}
V_28 = F_103 ( sizeof( struct V_28 ) , V_295 ) ;
V_22 = F_103 ( sizeof( struct V_22 ) , V_295 ) ;
if ( V_22 && V_28 ) {
struct V_177 * V_296 ;
V_22 -> V_12 = V_28 ;
V_22 -> V_2 = V_232 ;
F_21 ( V_22 ) ;
V_22 -> type = V_56 ;
V_22 -> V_36 = sizeof ( struct V_22 ) ;
V_22 -> V_37 = V_28 -> V_37 ;
V_296 = (struct V_177 * ) V_28 -> V_37 ;
V_296 -> V_101 = F_8 ( V_206 ) ;
V_296 -> V_297 = F_8 ( 0xFFFFFFFF ) ;
( ( V_179 * ) V_296 -> V_37 ) [ 0 ] = F_8 ( V_298 ) ;
( ( V_179 * ) V_296 -> V_37 ) [ 1 ] = F_8 ( V_299 ) ;
( ( V_179 * ) V_296 -> V_37 ) [ 2 ] = F_8 ( V_300 ) ;
( ( V_179 * ) V_296 -> V_37 ) [ 3 ] = F_8 ( V_288 ) ;
F_33 ( & V_22 -> V_130 , & V_278 -> V_291 ) ;
V_278 -> V_285 ++ ;
F_79 ( & V_278 -> V_301 ) ;
} else {
F_19 ( V_65 L_36 ) ;
F_51 ( V_22 ) ;
F_51 ( V_28 ) ;
}
V_78 = V_78 -> V_38 ;
}
F_16 ( & V_232 -> V_59 , V_250 ) ;
if ( V_288 < 0 ) {
F_19 ( V_96 L_37 ,
V_232 -> V_176 , V_288 ) ;
goto V_248;
}
F_19 ( V_96 L_38 , V_232 -> V_176 , V_288 ) ;
V_248:
V_232 -> V_274 = 0 ;
return V_288 ;
}
static void F_104 ( struct V_1 * V_2 )
{
int V_302 , V_303 , V_182 ;
struct V_186 * V_304 ;
T_6 V_305 ;
T_6 V_306 ;
for ( V_302 = 0 ; V_302 < V_307 ; V_302 ++ ) {
for ( V_303 = 0 ; V_303 < V_308 ; V_303 ++ ) {
if ( V_302 == V_226 )
V_182 = V_226 ;
else
V_182 = F_58 ( V_302 ) ;
V_305 = V_2 -> V_309 [ V_302 ] [ V_303 ] . V_305 ;
V_306 = V_2 -> V_309 [ V_302 ] [ V_303 ] . V_306 ;
V_304 = F_59 ( V_2 -> V_8 , V_182 ,
V_303 , 0 ) ;
if ( ! V_304 && V_306 )
F_72 ( V_2 -> V_8 , V_182 ,
V_303 , 0 ) ;
else if ( V_304 && V_306 != V_305 )
F_65 ( V_304 ) ;
else if ( V_304 && V_306 == V_305 )
F_71 ( & V_304 -> V_231 ) ;
if ( V_304 )
F_63 ( V_304 ) ;
V_2 -> V_309 [ V_302 ] [ V_303 ] . V_305 = V_306 ;
}
}
}
static void F_105 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_20 , V_302 , V_303 , V_185 , V_310 = 0 ;
T_2 V_311 = 0 ;
struct V_22 * V_22 ;
struct V_186 * V_304 ;
if ( V_23 -> V_312 & V_313 )
V_311 = V_313 ;
else if ( V_23 -> V_312 & V_314 )
V_311 = V_314 ;
else if ( V_23 -> V_312 & V_315 )
V_311 = V_315 ;
else if ( V_23 -> V_312 & V_316 )
V_311 = V_316 ;
else if ( V_23 -> V_312 & V_317 )
V_311 = V_317 ;
else if ( V_23 -> V_312 & V_318 )
V_311 = V_318 ;
switch ( V_311 ) {
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_318 :
V_22 = F_14 ( V_2 ) ;
if ( ! V_22 ) {
F_106 ( L_39 ) ;
return;
}
for ( V_302 = 0 ; V_302 < V_307 ; V_302 ++ )
for ( V_303 = 0 ; V_303 < V_308 ; V_303 ++ )
V_2 -> V_309 [ V_302 ] [ V_303 ] . V_306 = 0 ;
V_310 = F_107 ( V_2 , V_22 , V_319 ) ;
if ( V_310 != - V_141 )
F_17 ( V_22 ) ;
F_104 ( V_2 ) ;
if ( V_311 == V_316 ||
V_311 == V_318 ) {
F_91 ( V_2 ) ;
for ( V_185 = 0 ; V_185 <
V_2 -> V_200 ; ++ V_185 ) {
V_304 = F_59 ( V_2 -> V_8 ,
V_226 ,
V_185 , 0 ) ;
if ( V_2 -> V_193 [ V_185 ] . V_227 && ! V_304 ) {
F_72 ( V_2 -> V_8 ,
V_226 ,
V_185 , 0 ) ;
} else if ( ! V_2 -> V_193 [ V_185 ] . V_227 &&
V_304 ) {
F_65 ( V_304 ) ;
F_63 ( V_304 ) ;
} else if ( V_304 ) {
F_71 ( & V_304 -> V_231 ) ;
F_63 ( V_304 ) ;
}
}
}
break;
case V_317 :
break;
}
for ( V_20 = 1 ; V_20 <= 10 ; ++ V_20 ) {
V_311 = F_108 ( V_2 , V_320 . V_321 ) ;
if ( V_311 & ( 1 << 23 ) ) {
F_109 ( L_40 ,
V_20 , 10 ) ;
F_80 ( 1 ) ;
}
}
}
static int F_110 ( struct V_1 * V_2 )
{
unsigned int V_322 = 0 ;
struct V_290 * V_78 ;
unsigned long V_250 ;
V_322 = F_20 ( V_2 -> V_32 -> V_33 . V_323 )
/ sizeof( struct V_28 ) ;
F_15 ( & V_2 -> V_59 , V_250 ) ;
V_78 = V_2 -> V_291 . V_38 ;
while ( V_78 != & V_2 -> V_291 ) {
V_78 = V_78 -> V_38 ;
++ V_322 ;
}
F_16 ( & V_2 -> V_59 , V_250 ) ;
return V_322 ;
}
static int F_111 ( struct V_1 * V_2 , struct V_28 * * V_324 ,
struct V_22 * * V_325 ,
unsigned int V_322 )
{
struct V_28 * * V_326 ;
struct V_22 * * V_327 ;
V_326 = V_324 ;
V_327 = V_325 ;
while ( V_326 < & V_324 [ V_322 ] ) {
* ( V_326 ) = F_112 ( sizeof( struct V_28 ) , V_15 ) ;
if ( ! ( * ( V_326 ++ ) ) ) {
-- V_326 ;
break;
}
* ( V_327 ) = F_112 ( sizeof( struct V_22 ) , V_15 ) ;
if ( ! ( * ( V_327 ++ ) ) ) {
F_51 ( * ( -- V_326 ) ) ;
break;
}
}
V_322 = V_326 - V_324 ;
return V_322 ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_28 * * V_324 ,
struct V_22 * * V_325 ,
struct V_22 * V_22 ,
struct V_28 * V_28 ,
unsigned int V_322 )
{
unsigned long V_250 ;
struct V_290 * V_78 ;
struct V_28 * * V_326 ;
struct V_22 * * V_327 ;
T_2 V_289 , V_293 ;
struct V_28 * V_328 ;
struct V_22 * V_329 ;
struct V_292 * V_278 ;
V_289 = V_137 / V_138 ;
F_15 ( & V_2 -> V_59 , V_250 ) ;
V_78 = V_2 -> V_291 . V_38 ;
V_326 = V_324 ;
V_327 = V_325 ;
while ( V_78 != & V_2 -> V_291 ) {
V_278 = F_101 ( V_78 , struct V_292 ,
V_38 ) ;
if ( V_278 -> V_285 > 20 ) {
V_293 = V_278 -> V_137 ;
if ( ( V_289 - V_293 ) > V_294 ) {
V_78 = V_78 -> V_38 ;
F_102 ( V_2 , V_278 ) ;
continue;
}
}
if ( V_326 >= & V_324 [ V_322 ] ) {
F_109 ( L_41 ) ;
V_78 = V_78 -> V_38 ;
continue;
}
V_328 = * V_326 ;
* ( V_326 ++ ) = NULL ;
V_329 = * V_327 ;
* ( V_327 ++ ) = NULL ;
memcpy ( V_328 , V_28 , sizeof( struct V_28 ) ) ;
memcpy ( V_329 , V_22 , sizeof( struct V_22 ) ) ;
V_329 -> V_12 = V_328 ;
F_33 ( & V_329 -> V_130 , & V_278 -> V_291 ) ;
V_278 -> V_285 ++ ;
F_79 ( & V_278 -> V_301 ) ;
V_78 = V_78 -> V_38 ;
}
* ( V_179 * ) V_28 -> V_37 = F_8 ( V_330 ) ;
F_50 ( V_22 , sizeof( T_2 ) ) ;
F_16 ( & V_2 -> V_59 , V_250 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_28 * V_28 ;
struct V_22 * V_22 ;
unsigned long V_35 ;
T_9 * V_331 ;
V_331 = V_2 -> V_84 -> V_85 [ V_153 ] . V_167 ;
F_15 ( V_331 , V_35 ) ;
while ( ! F_115 ( & ( V_2 -> V_84 -> V_85 [ V_153 ] . V_332 ) ) ) {
struct V_290 * V_78 ;
struct V_177 * V_178 ;
unsigned int V_322 ;
struct V_28 * * V_324 , * * V_326 ;
struct V_22 * * V_325 , * * V_327 ;
F_116 ( V_333 ) ;
V_78 = V_2 -> V_84 -> V_85 [ V_153 ] . V_332 . V_38 ;
F_117 ( V_78 ) ;
V_331 = V_2 -> V_84 -> V_85 [ V_153 ] . V_167 ;
F_16 ( V_331 , V_35 ) ;
V_22 = F_101 ( V_78 , struct V_22 , V_130 ) ;
V_28 = V_22 -> V_12 ;
if ( V_2 -> V_334 ) {
F_105 ( V_2 , V_22 ) ;
F_50 ( V_22 , ( T_4 ) sizeof( T_2 ) ) ;
goto V_51;
}
memset ( V_22 , 0 , sizeof( struct V_22 ) ) ;
V_22 -> type = V_56 ;
V_22 -> V_36 = sizeof( struct V_22 ) ;
V_22 -> V_12 = V_28 ;
V_22 -> V_37 = V_28 -> V_37 ;
V_22 -> V_2 = V_2 ;
V_178 = (struct V_177 * ) V_28 -> V_37 ;
if ( V_178 -> V_101 == F_8 ( V_194 ) ) {
F_57 ( V_2 , V_22 ) ;
* ( V_179 * ) V_28 -> V_37 = F_8 ( V_330 ) ;
F_50 ( V_22 , ( T_4 ) sizeof( T_2 ) ) ;
goto V_51;
}
if ( V_178 -> V_101 == F_8 ( V_206 )
|| V_178 -> V_101 == F_8 ( V_221 ) ) {
F_57 ( V_2 , V_22 ) ;
}
V_322 = F_110 ( V_2 ) ;
if ( ! V_322 )
goto V_51;
V_324 = F_118 ( V_322 , sizeof( struct V_28 * ) ,
V_15 ) ;
if ( ! V_324 )
goto V_51;
V_325 = F_118 ( V_322 , sizeof( struct V_22 * ) , V_15 ) ;
if ( ! V_325 )
goto V_335;
V_322 = F_111 ( V_2 , V_324 , V_325 , V_322 ) ;
if ( ! V_322 )
goto V_336;
F_113 ( V_2 , V_324 , V_325 ,
V_22 , V_28 , V_322 ) ;
V_336:
V_326 = V_324 ;
V_327 = V_325 ;
while ( V_326 < & V_324 [ V_322 ] ) {
F_51 ( * V_326 ) ;
F_51 ( * V_327 ) ;
++ V_327 ;
++ V_326 ;
}
F_51 ( V_325 ) ;
V_335:
F_51 ( V_324 ) ;
V_51:
F_51 ( V_22 ) ;
V_331 = V_2 -> V_84 -> V_85 [ V_153 ] . V_167 ;
F_15 ( V_331 , V_35 ) ;
}
V_331 = V_2 -> V_84 -> V_85 [ V_153 ] . V_167 ;
F_16 ( V_331 , V_35 ) ;
}
static int F_119 ( struct V_1 * V_2 , char * V_337 ,
T_2 V_338 )
{
struct V_339 * V_340 ;
struct V_341 * V_342 ;
T_3 V_97 ;
char * V_343 ;
struct V_22 * V_23 ;
int V_344 = - V_16 ;
T_2 V_345 , V_346 ;
V_23 = F_14 ( V_2 ) ;
if ( ! V_23 )
goto V_248;
V_343 = F_3 ( & V_2 -> V_7 -> V_2 , V_338 , & V_97 ,
V_15 ) ;
if ( ! V_343 )
goto V_347;
F_21 ( V_23 ) ;
V_345 = ( T_2 ) F_26 ( V_2 -> V_348 . V_349 ) ;
V_346 = ( T_2 ) F_26 ( V_2 -> V_348 . V_350 ) ;
V_340 = (struct V_339 * ) F_32 ( V_23 ) ;
V_340 -> V_351 = F_8 ( V_352 ) ;
V_340 -> V_182 = F_8 ( V_345 ) ;
V_340 -> V_183 = F_8 ( V_346 ) ;
V_340 -> V_184 = 0 ;
V_340 -> V_35 = F_8 ( V_353 ) ;
V_340 -> V_136 = F_8 ( 10 ) ;
V_340 -> V_354 = 0 ;
V_340 -> V_355 = F_8 ( 12 ) ;
V_340 -> V_285 = F_8 ( V_338 ) ;
memset ( V_340 -> V_356 , 0 , sizeof( V_340 -> V_356 ) ) ;
V_340 -> V_356 [ 0 ] = V_357 ;
V_340 -> V_356 [ 6 ] = V_358 ;
memcpy ( V_343 , ( char * ) V_337 , V_338 ) ;
V_342 = (struct V_341 * ) & V_340 -> V_359 ;
V_342 -> V_285 = F_8 ( 1 ) ;
V_342 -> V_359 [ 0 ] . V_97 [ 1 ] = F_8 ( ( T_2 ) ( ( ( V_97 ) >> 16 ) >> 16 ) ) ;
V_342 -> V_359 [ 0 ] . V_97 [ 0 ] = F_8 ( ( T_2 ) ( V_97 & 0xffffffff ) ) ;
V_342 -> V_359 [ 0 ] . V_285 = F_8 ( V_338 ) ;
V_344 = F_30 ( V_360 , V_23 , sizeof( struct V_339 ) ,
V_287 , 1 , 1 , NULL , NULL ) ;
F_5 ( & V_2 -> V_7 -> V_2 , V_338 , V_343 , V_97 ) ;
if ( V_344 >= 0 )
F_52 ( V_23 ) ;
if ( V_344 != - V_141 )
goto V_347;
V_248:
return V_344 ;
V_347:
F_17 ( V_23 ) ;
goto V_248;
}
int F_120 ( struct V_1 * V_2 , struct V_361 * V_362 )
{
struct V_363 V_364 ;
char V_337 [] = L_42 ;
T_2 V_338 = sizeof( V_337 ) ;
unsigned long V_365 ;
int V_344 = - V_277 ;
if ( ! V_2 -> V_334 )
goto V_248;
V_365 = ( T_2 ) ( V_362 -> V_366 - ( V_367 . V_368 * 60 ) ) ;
F_121 ( V_365 , 0 , & V_364 ) ;
V_364 . V_369 += 1 ;
V_364 . V_370 += 1900 ;
V_337 [ 8 ] = F_122 ( V_364 . V_371 ) ;
V_337 [ 9 ] = F_122 ( V_364 . V_372 ) ;
V_337 [ 10 ] = F_122 ( V_364 . V_373 ) ;
V_337 [ 12 ] = F_122 ( V_364 . V_369 ) ;
V_337 [ 13 ] = F_122 ( V_364 . V_374 ) ;
V_337 [ 14 ] = F_122 ( V_364 . V_370 / 100 ) ;
V_337 [ 15 ] = F_122 ( V_364 . V_370 % 100 ) ;
V_344 = F_119 ( V_2 , V_337 , V_338 ) ;
V_248:
return V_344 ;
}
int F_123 ( struct V_1 * V_2 , struct V_361 * V_362 )
{
int V_344 = - V_16 ;
struct V_22 * V_23 ;
V_179 * V_375 ;
V_23 = F_14 ( V_2 ) ;
if ( ! V_23 )
goto V_248;
F_21 ( V_23 ) ;
V_375 = ( V_179 * ) F_32 ( V_23 ) ;
* V_375 = F_8 ( V_362 -> V_366 ) ;
V_344 = F_30 ( V_376 , V_23 , sizeof( * V_375 ) , V_287 ,
1 , 1 , NULL , NULL ) ;
if ( V_344 >= 0 )
F_52 ( V_23 ) ;
if ( V_344 != - V_141 )
F_17 ( V_23 ) ;
V_248:
return V_344 ;
}
int V_257 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
F_124 ( V_94 , V_246 ) ;
unsigned long V_377 = V_137 + V_138 ;
unsigned long V_378 = V_377 ;
long V_379 = V_138 ;
if ( V_2 -> V_380 )
return - V_108 ;
V_2 -> V_380 = 1 ;
F_125 ( & V_2 -> V_84 -> V_85 [ V_153 ] . V_381 , & V_94 ) ;
F_116 ( V_382 ) ;
F_2 ( ( V_6 L_43 ) ) ;
while ( 1 ) {
F_114 ( V_2 ) ;
if ( ( F_64 ( V_378 , V_377 ) )
&& ( ( V_379 = V_378 - V_137 ) <= 0 ) ) {
V_378 = V_377 ;
if ( F_40 ( V_2 ) == 0 ) {
V_379 = ( ( long ) ( unsigned ) V_383 )
* V_138 ;
V_378 = V_137 + V_379 ;
} else if ( ! V_2 -> V_84 )
break;
}
if ( ! F_64 ( V_378 , V_377 )
&& ( ( V_379 = V_377 - V_137 ) <= 0 ) ) {
struct V_361 V_362 ;
int V_344 ;
V_344 = F_40 ( V_2 ) ;
if ( V_344 || ! V_2 -> V_84 )
break;
V_378 = V_137
+ ( ( long ) ( unsigned ) V_383 )
* V_138 ;
F_126 ( & V_362 ) ;
if ( ( ( 1000000 - ( 1000000 / V_138 ) ) > V_362 . V_384 )
&& ( V_362 . V_384 > ( 1000000 / V_138 ) ) )
V_379 = ( ( ( 1000000 - V_362 . V_384 ) * V_138 )
+ 500000 ) / 1000000 ;
else {
if ( V_362 . V_384 > 500000 )
++ V_362 . V_366 ;
if ( V_2 -> V_334 )
V_344 =
F_120 ( V_2 , & V_362 ) ;
else
V_344 = F_123 ( V_2 , & V_362 ) ;
V_379 = ( long ) ( unsigned ) V_385 * V_138 ;
}
V_377 = V_137 + V_379 ;
if ( F_64 ( V_378 , V_377 ) )
V_379 = V_378 - V_137 ;
}
if ( V_379 <= 0 )
V_379 = 1 ;
F_116 ( V_382 ) ;
if ( F_127 () )
break;
F_128 ( V_379 ) ;
if ( F_127 () )
break;
}
if ( V_2 -> V_84 )
F_129 ( & V_2 -> V_84 -> V_85 [ V_153 ] . V_381 , & V_94 ) ;
V_2 -> V_380 = 0 ;
return 0 ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_20 ;
int V_386 ;
int V_344 = 0 ;
if ( ! V_2 -> V_127 && V_2 -> V_387 && V_2 -> V_25 > 1 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_25 ; V_20 ++ ) {
V_2 -> V_388 [ V_20 ] . V_27 = V_20 ;
V_2 -> V_388 [ V_20 ] . V_2 = V_2 ;
if ( F_131 ( F_132 ( V_2 -> V_7 , V_20 ) ,
V_2 -> V_389 . V_390 ,
0 , L_44 , & ( V_2 -> V_388 [ V_20 ] ) ) ) {
F_19 ( V_96 L_45 ,
V_2 -> V_176 , V_2 -> V_183 , V_20 ) ;
for ( V_386 = 0 ; V_386 < V_20 ; V_386 ++ )
F_133 ( F_132 ( V_2 -> V_7 , V_386 ) ,
& ( V_2 -> V_388 [ V_386 ] ) ) ;
F_134 ( V_2 -> V_7 ) ;
V_344 = - 1 ;
}
}
} else {
V_2 -> V_388 [ 0 ] . V_27 = 0 ;
V_2 -> V_388 [ 0 ] . V_2 = V_2 ;
if ( F_131 ( V_2 -> V_7 -> V_391 , V_2 -> V_389 . V_390 ,
V_392 , L_44 ,
& ( V_2 -> V_388 [ 0 ] ) ) < 0 ) {
if ( V_2 -> V_393 )
F_135 ( V_2 -> V_7 ) ;
F_19 ( V_96 L_46 ,
V_2 -> V_176 , V_2 -> V_183 ) ;
V_344 = - 1 ;
}
}
return V_344 ;
}
void F_81 ( struct V_1 * V_2 )
{
int V_20 ;
int V_394 ;
V_394 = F_136 ( V_395 ) ;
if ( F_137 ( V_2 ) ) {
if ( V_2 -> V_25 > 1 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_25 ; V_20 ++ )
F_133 ( F_132 ( V_2 -> V_7 , V_20 ) ,
& ( V_2 -> V_388 [ V_20 ] ) ) ;
} else {
F_133 ( V_2 -> V_7 -> V_391 , & ( V_2 -> V_388 [ 0 ] ) ) ;
}
} else {
F_133 ( V_2 -> V_7 -> V_391 , V_2 ) ;
}
if ( V_2 -> V_393 )
F_135 ( V_2 -> V_7 ) ;
else if ( V_2 -> V_25 > 1 )
F_134 ( V_2 -> V_7 ) ;
}
