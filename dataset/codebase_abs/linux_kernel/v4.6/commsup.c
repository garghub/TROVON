static int F_1 ( struct V_1 * V_2 )
{
F_2 ( ( V_3
L_1 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 -> V_7 ,
V_8 , & V_2 -> V_9 ) ) ;
V_2 -> V_10 = F_3 ( V_2 -> V_4 ,
( V_2 -> V_5 + sizeof( struct V_11 ) )
* ( V_2 -> V_6 -> V_7 + V_8 ) + ( V_12 - 1 ) ,
& V_2 -> V_9 ) ;
if ( V_2 -> V_10 == NULL )
return - V_13 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 && V_2 -> V_5 ) {
F_5 ( V_2 -> V_4 ,
( V_2 -> V_5 *
( V_2 -> V_6 -> V_7 + V_8 ) ) ,
V_2 -> V_10 , V_2 -> V_9 ) ;
}
V_2 -> V_10 = NULL ;
V_2 -> V_9 = 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_14 = 0 ;
T_1 V_15 = 1 ;
struct V_16 * V_17 = NULL ;
for ( V_14 = 0 , V_17 = & V_2 -> V_18 [ V_14 ] ;
V_14 < ( V_2 -> V_6 -> V_7 + V_8 ) ;
V_14 ++ , V_17 ++ ) {
if ( ( V_2 -> V_19 == 1 ) ||
( V_14 > ( ( V_2 -> V_6 -> V_7 + V_8 - 1 )
- V_2 -> V_20 ) ) ) {
V_17 -> V_21 = 0 ;
} else {
V_17 -> V_21 = V_15 ;
V_15 ++ ;
if ( V_15 == V_2 -> V_19 )
V_15 = 1 ;
}
}
}
int F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_22 * V_22 ;
T_2 V_9 ;
int V_14 ;
while ( ( ( V_14 = F_1 ( V_2 ) ) == - V_13 )
&& ( V_2 -> V_6 -> V_7 > ( 64 - V_8 ) ) ) {
V_2 -> V_23 -> V_24 = F_8 ( ( V_2 -> V_6 -> V_7 + V_8 ) >> 1 ) ;
V_2 -> V_6 -> V_7 = F_9 ( V_2 -> V_23 -> V_24 ) - V_8 ;
}
if ( V_14 < 0 )
return - V_13 ;
V_9 = ( V_2 -> V_9 + ( V_12 - 1 ) ) & ~ ( V_12 - 1 ) ;
V_2 -> V_10 = (struct V_22 * ) ( ( unsigned char * ) V_2 -> V_10 +
( V_9 - V_2 -> V_9 ) ) ;
V_2 -> V_9 = V_9 ;
memset ( V_2 -> V_10 , 0 ,
( V_2 -> V_5 + sizeof( struct V_11 ) ) *
( V_2 -> V_6 -> V_7 + V_8 ) ) ;
V_2 -> V_10 = (struct V_22 * ) ( ( unsigned char * ) V_2 -> V_10 +
sizeof( struct V_11 ) ) ;
V_2 -> V_9 += sizeof( struct V_11 ) ;
V_22 = V_2 -> V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_14 = 0 , V_17 = & V_2 -> V_18 [ V_14 ] ;
V_14 < ( V_2 -> V_6 -> V_7 + V_8 ) ;
V_14 ++ , V_17 ++ )
{
V_17 -> V_25 = 0 ;
V_17 -> V_26 = sizeof( struct V_16 ) ;
V_17 -> V_2 = V_2 ;
V_17 -> V_10 = V_22 ;
V_17 -> V_27 = ( void * ) V_17 -> V_10 -> V_27 ;
V_17 -> V_28 = V_17 + 1 ;
F_10 ( & V_17 -> V_29 , 0 ) ;
F_11 ( & V_17 -> V_30 ) ;
V_22 -> V_31 . V_32 = F_8 ( 0xffffffff ) ;
V_22 -> V_31 . V_33 = F_12 ( V_2 -> V_5 ) ;
V_17 -> V_9 = V_9 ;
V_22 = (struct V_22 * ) ( ( unsigned char * ) V_22 +
V_2 -> V_5 + sizeof( struct V_11 ) ) ;
V_9 = V_9 +
V_2 -> V_5 + sizeof( struct V_11 ) ;
}
F_6 ( V_2 ) ;
V_2 -> V_18 [ V_2 -> V_6 -> V_7 + V_8 - 1 ] . V_28 = NULL ;
V_2 -> V_34 = & V_2 -> V_18 [ V_2 -> V_6 -> V_7 ] ;
return 0 ;
}
struct V_16 * F_13 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_16 * V_17 ;
V_17 = & V_2 -> V_18 [ V_36 -> V_37 -> V_38 ] ;
V_17 -> V_10 -> V_31 . V_32 = 0 ;
V_17 -> type = V_39 ;
V_17 -> V_40 = NULL ;
V_17 -> V_41 = NULL ;
return V_17 ;
}
struct V_16 * F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
unsigned long V_25 ;
F_15 ( & V_2 -> V_42 , V_25 ) ;
V_17 = V_2 -> V_34 ;
if( ! V_17 ) {
F_16 ( & V_2 -> V_42 , V_25 ) ;
return V_17 ;
}
V_2 -> V_34 = V_17 -> V_28 ;
F_16 ( & V_2 -> V_42 , V_25 ) ;
V_17 -> type = V_39 ;
V_17 -> V_26 = sizeof( struct V_16 ) ;
V_17 -> V_10 -> V_31 . V_32 = 0 ;
V_17 -> V_25 = 0 ;
V_17 -> V_41 = NULL ;
V_17 -> V_40 = NULL ;
return V_17 ;
}
void F_17 ( struct V_16 * V_17 )
{
unsigned long V_25 ;
if ( V_17 -> V_43 == 2 )
return;
F_15 ( & V_17 -> V_2 -> V_42 , V_25 ) ;
if ( F_18 ( V_17 -> V_25 & V_44 ) )
V_45 . V_46 ++ ;
if ( V_17 -> V_10 -> V_31 . V_32 != 0 ) {
F_19 ( V_47 L_2 ,
( void * ) V_17 ,
F_9 ( V_17 -> V_10 -> V_31 . V_32 ) ) ;
}
V_17 -> V_28 = V_17 -> V_2 -> V_34 ;
V_17 -> V_2 -> V_34 = V_17 ;
F_16 ( & V_17 -> V_2 -> V_42 , V_25 ) ;
}
void F_20 ( struct V_16 * V_17 )
{
struct V_22 * V_22 = V_17 -> V_10 ;
memset ( & V_22 -> V_31 , 0 , sizeof( struct V_48 ) ) ;
V_22 -> V_31 . V_49 = V_50 ;
V_22 -> V_31 . V_51 = F_12 ( V_17 -> V_2 -> V_5 ) ;
V_22 -> V_31 . V_32 = F_8 ( V_52 | V_53 | V_54 | V_55 ) ;
V_22 -> V_31 . V_56 . V_57 = F_8 ( V_17 -> V_9 ) ;
V_22 -> V_31 . V_33 = F_12 ( V_17 -> V_2 -> V_5 ) ;
}
static void F_21 ( struct V_16 * V_17 )
{
struct V_22 * V_22 = V_17 -> V_10 ;
V_22 -> V_31 . V_32 = 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_58 , struct V_59 * * V_60 , T_1 * V_61 , unsigned long * V_62 )
{
struct V_63 * V_64 ;
unsigned long V_65 ;
V_64 = & V_2 -> V_66 -> V_67 [ V_58 ] ;
V_65 = * V_61 = F_9 ( * ( V_64 -> V_68 . V_69 ) ) ;
if ( V_65 != F_9 ( * ( V_64 -> V_68 . V_70 ) ) ) {
if ( -- V_65 == 0 ) {
if ( V_58 == V_71 )
V_65 = V_72 ;
else
V_65 = V_73 ;
}
if ( V_65 != F_9 ( * ( V_64 -> V_68 . V_70 ) ) )
* V_62 = 1 ;
}
if ( V_58 == V_71 ) {
if ( * V_61 >= V_72 )
* V_61 = 0 ;
} else {
if ( * V_61 >= V_73 )
* V_61 = 0 ;
}
if ( ( * V_61 + 1 ) == F_9 ( * ( V_64 -> V_68 . V_70 ) ) ) {
F_19 ( V_47 L_3 ,
V_58 , F_23 ( & V_64 -> V_74 ) ) ;
return 0 ;
} else {
* V_60 = V_64 -> V_75 + * V_61 ;
return 1 ;
}
}
int F_24 ( struct V_1 * V_2 , T_1 * V_61 , T_1 V_58 , struct V_22 * V_22 , int V_76 , struct V_16 * V_17 , unsigned long * V_62 )
{
struct V_59 * V_60 = NULL ;
int V_77 = 0 ;
if ( V_58 == V_71 ) {
while ( ! F_22 ( V_2 , V_58 , & V_60 , V_61 , V_62 ) ) {
F_19 ( V_78 L_4 ) ;
}
V_60 -> V_26 = F_8 ( F_25 ( V_22 -> V_31 . V_51 ) ) ;
V_77 = 1 ;
} else {
while ( ! F_22 ( V_2 , V_58 , & V_60 , V_61 , V_62 ) ) {
}
V_60 -> V_26 = F_8 ( F_25 ( V_22 -> V_31 . V_51 ) ) ;
V_60 -> V_79 = V_22 -> V_31 . V_80 ;
V_22 -> V_31 . V_56 . V_57 = V_22 -> V_31 . V_80 ;
V_77 = 0 ;
}
if ( V_77 )
V_60 -> V_79 = F_8 ( V_17 -> V_9 ) ;
return 0 ;
}
int F_26 ( T_3 V_81 , struct V_16 * V_17 , unsigned long V_26 ,
int V_82 , int V_76 , int V_83 , T_4 V_41 ,
void * V_40 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_22 * V_22 = V_17 -> V_10 ;
unsigned long V_25 = 0 ;
unsigned long V_84 = 0 ;
unsigned long V_85 = 0 ;
if ( ! ( V_22 -> V_31 . V_32 & F_8 ( V_52 ) ) )
return - V_86 ;
V_17 -> V_25 = 0 ;
if ( V_76 && ! V_83 ) {
return - V_87 ;
} else if ( ! V_76 && V_83 ) {
V_22 -> V_31 . V_32 |= F_8 ( V_88 | V_89 ) ;
F_27 ( V_45 . V_90 ) ;
} else if ( ! V_76 && ! V_83 ) {
V_22 -> V_31 . V_32 |= F_8 ( V_91 ) ;
F_27 ( V_45 . V_92 ) ;
} else if ( V_76 && V_83 ) {
V_22 -> V_31 . V_32 |= F_8 ( V_89 ) ;
F_27 ( V_45 . V_93 ) ;
}
V_22 -> V_31 . V_80 = F_8 ( ( ( T_1 ) ( V_17 - V_2 -> V_18 ) ) << 2 ) ;
V_22 -> V_31 . V_94 = ( T_1 ) ( V_17 - V_2 -> V_18 ) + 1 ;
V_22 -> V_31 . V_95 = F_12 ( V_81 ) ;
V_22 -> V_31 . V_32 |= F_8 ( V_96 ) ;
V_22 -> V_31 . V_51 = F_12 ( sizeof( struct V_48 ) + V_26 ) ;
if ( F_25 ( V_22 -> V_31 . V_51 ) > F_25 ( V_22 -> V_31 . V_33 ) ) {
return - V_97 ;
}
V_22 -> V_31 . V_32 |= F_8 ( V_98 ) ;
if ( ! V_76 ) {
V_17 -> V_41 = V_41 ;
V_17 -> V_40 = V_40 ;
V_17 -> V_25 = V_99 ;
}
V_17 -> V_43 = 0 ;
F_27 ( V_45 . V_100 ) ;
F_2 ( ( V_101 L_5 ) ) ;
F_2 ( ( V_101 L_6 , F_9 ( V_22 -> V_31 . V_95 ) ) ) ;
F_2 ( ( V_101 L_7 , F_9 ( ( (struct V_102 * ) F_28 ( V_17 ) ) -> V_81 ) ) ) ;
F_2 ( ( V_101 L_8 , F_9 ( V_22 -> V_31 . V_32 ) ) ) ;
F_2 ( ( V_101 L_9 , V_17 -> V_10 ) ) ;
F_2 ( ( V_101 L_10 , ( V_103 ) V_17 -> V_9 ) ) ;
F_2 ( ( V_101 L_11 , V_17 ) ) ;
if ( ! V_2 -> V_66 )
return - V_86 ;
if ( V_76 ) {
F_15 ( & V_2 -> V_104 , V_84 ) ;
if ( V_2 -> V_105 >= V_8 ) {
F_19 ( V_3 L_12 ,
V_2 -> V_105 ) ;
F_16 ( & V_2 -> V_104 , V_84 ) ;
return - V_86 ;
}
V_2 -> V_105 ++ ;
F_16 ( & V_2 -> V_104 , V_84 ) ;
F_15 ( & V_17 -> V_30 , V_25 ) ;
}
if ( V_2 -> V_106 ) {
if ( V_76 )
F_16 ( & V_17 -> V_30 , V_25 ) ;
F_15 ( & V_2 -> V_107 , V_85 ) ;
if ( V_2 -> V_108 ) {
F_29 ( & V_17 -> V_109 , & V_2 -> V_110 ) ;
F_16 ( & V_2 -> V_107 , V_85 ) ;
} else {
V_2 -> V_108 = V_17 ;
F_16 ( & V_2 -> V_107 , V_85 ) ;
F_30 ( V_2 , V_111 ,
( T_1 ) V_17 -> V_9 , 0 , 0 , 0 , 0 , 0 ,
NULL , NULL , NULL , NULL , NULL ) ;
}
if ( V_76 ) {
V_17 -> V_25 |= V_112 ;
if ( F_31 ( & V_17 -> V_29 ) ) {
V_17 -> V_25 &= ~ V_112 ;
return - V_113 ;
}
return 0 ;
}
return - V_114 ;
}
if ( F_32 ( V_17 ) != 0 ) {
F_19 ( V_78 L_13 ) ;
if ( V_76 ) {
F_16 ( & V_17 -> V_30 , V_25 ) ;
F_15 ( & V_2 -> V_104 , V_84 ) ;
V_2 -> V_105 -- ;
F_16 ( & V_2 -> V_104 , V_84 ) ;
}
return - V_86 ;
}
if ( V_76 ) {
F_16 ( & V_17 -> V_30 , V_25 ) ;
if ( V_76 < 0 ) {
unsigned long V_115 = V_116 + ( 180 * V_117 ) ;
while ( F_33 ( & V_17 -> V_29 ) ) {
int V_118 ;
if ( F_34 ( V_115 ) ) {
struct V_63 * V_64 = & V_2 -> V_66 -> V_67 [ V_71 ] ;
F_35 ( & V_64 -> V_74 ) ;
if ( V_76 == - 1 ) {
F_19 ( V_78 L_14
L_15
L_16
L_17 ) ;
}
return - V_119 ;
}
if ( ( V_118 = F_36 ( V_2 ) ) > 0 ) {
if ( V_76 == - 1 ) {
F_19 ( V_78 L_18
L_19 ,
V_118 ) ;
}
return - V_113 ;
}
F_37 () ;
}
} else if ( F_31 ( & V_17 -> V_29 ) ) {
}
F_15 ( & V_17 -> V_30 , V_25 ) ;
if ( V_17 -> V_43 == 0 ) {
V_17 -> V_43 = 2 ;
F_16 ( & V_17 -> V_30 , V_25 ) ;
return - V_120 ;
}
F_16 ( & V_17 -> V_30 , V_25 ) ;
F_38 ( V_17 -> V_43 == 0 ) ;
if( F_18 ( V_17 -> V_25 & V_44 ) )
return - V_119 ;
return 0 ;
}
if ( V_83 )
return - V_114 ;
else
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct V_63 * V_64 , struct V_59 * * V_60 )
{
T_1 V_61 ;
int V_121 ;
if ( F_9 ( * V_64 -> V_68 . V_69 ) == F_9 ( * V_64 -> V_68 . V_70 ) ) {
V_121 = 0 ;
} else {
if ( F_9 ( * V_64 -> V_68 . V_70 ) >= V_64 -> V_122 )
V_61 = 0 ;
else
V_61 = F_9 ( * V_64 -> V_68 . V_70 ) ;
* V_60 = V_64 -> V_75 + V_61 ;
V_121 = 1 ;
}
return ( V_121 ) ;
}
void F_40 ( struct V_1 * V_2 , struct V_63 * V_64 , T_1 V_58 )
{
int V_123 = 0 ;
T_1 V_124 ;
if ( ( F_9 ( * V_64 -> V_68 . V_69 ) + 1 ) == F_9 ( * V_64 -> V_68 . V_70 ) )
V_123 = 1 ;
if ( F_9 ( * V_64 -> V_68 . V_70 ) >= V_64 -> V_122 )
* V_64 -> V_68 . V_70 = F_8 ( 1 ) ;
else
F_41 ( V_64 -> V_68 . V_70 , 1 ) ;
if ( V_123 ) {
switch ( V_58 ) {
case V_125 :
V_124 = V_126 ;
break;
case V_127 :
V_124 = V_128 ;
break;
default:
F_42 () ;
return;
}
F_43 ( V_2 , V_124 ) ;
}
}
int F_44 ( struct V_16 * V_17 , unsigned short V_26 )
{
struct V_22 * V_22 = V_17 -> V_10 ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_63 * V_64 ;
unsigned long V_129 = 0 ;
unsigned long V_130 ;
if ( V_2 -> V_131 == V_132 ||
V_2 -> V_131 == V_133 ) {
F_45 ( V_22 ) ;
return 0 ;
}
if ( V_22 -> V_31 . V_32 == 0 ) {
if ( V_2 -> V_131 == V_134 )
F_45 ( V_22 ) ;
return 0 ;
}
if ( V_22 -> V_31 . V_49 != V_50 &&
V_22 -> V_31 . V_49 != V_135 &&
V_22 -> V_31 . V_49 != V_136 ) {
if ( V_2 -> V_131 == V_134 )
F_45 ( V_22 ) ;
return - V_87 ;
}
if ( V_22 -> V_31 . V_32 & F_8 ( V_137 ) ) {
if ( V_2 -> V_131 == V_134 ) {
F_45 ( V_22 ) ;
} else {
T_1 V_61 ;
V_22 -> V_31 . V_32 |= F_8 ( V_138 ) ;
if ( V_26 ) {
V_26 += sizeof( struct V_48 ) ;
if ( V_26 > F_25 ( V_22 -> V_31 . V_33 ) )
return - V_97 ;
V_22 -> V_31 . V_51 = F_12 ( V_26 ) ;
}
V_64 = & V_2 -> V_66 -> V_67 [ V_139 ] ;
F_15 ( V_64 -> V_140 , V_130 ) ;
F_24 ( V_2 , & V_61 , V_139 , V_22 , 1 , NULL , & V_129 ) ;
* ( V_64 -> V_68 . V_69 ) = F_8 ( V_61 + 1 ) ;
F_16 ( V_64 -> V_140 , V_130 ) ;
if ( ! ( V_129 & ( int ) V_45 . V_141 ) )
F_43 ( V_2 , V_139 ) ;
}
} else {
F_19 ( V_47 L_20
L_21 ) ;
F_42 () ;
}
return 0 ;
}
int F_46 ( struct V_16 * V_17 )
{
struct V_22 * V_22 = V_17 -> V_10 ;
if ( V_22 -> V_31 . V_32 == 0 )
return 0 ;
if ( V_22 -> V_31 . V_49 != V_50 &&
V_22 -> V_31 . V_49 != V_135 &&
V_22 -> V_31 . V_49 != V_136 )
return - V_87 ;
if( ( V_22 -> V_31 . V_32 & F_8 ( V_96 ) ) &&
( V_22 -> V_31 . V_32 & F_8 ( V_142 ) ) )
{
F_21 ( V_17 ) ;
}
else if( V_22 -> V_31 . V_32 & F_8 ( V_96 ) )
{
F_21 ( V_17 ) ;
} else if( V_22 -> V_31 . V_32 & F_8 ( V_52 ) ) {
F_21 ( V_17 ) ;
} else {
F_42 () ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 , T_1 V_143 )
{
char * V_144 = V_2 -> V_145 ;
if ( V_2 -> V_146 )
{
int V_147 = V_143 & 0xffff ;
int V_148 = ( V_143 >> 16 ) & 0xffff ;
if ( V_147 > 255 )
V_147 = 255 ;
if ( V_144 [ V_147 ] != 0 )
V_144 [ V_147 ] = 0 ;
if ( V_148 == V_149 )
F_19 ( V_47 L_22 , V_2 -> V_150 , V_144 ) ;
else
F_19 ( V_3 L_22 , V_2 -> V_150 , V_144 ) ;
}
memset ( V_144 , 0 , 256 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_22 * V_22 = V_17 -> V_10 ;
struct V_151 * V_152 = (struct V_151 * ) V_22 -> V_27 ;
T_1 V_153 , V_154 , V_155 , V_156 ;
struct V_157 * V_158 ;
enum {
V_159 ,
V_160 ,
V_161 ,
V_162
} V_163 = V_159 ;
if ( ! V_2 || ! V_2 -> V_164 )
return;
V_156 = V_153 = V_154 = V_155 = ( T_1 ) - 1 ;
switch ( F_9 ( V_152 -> V_81 ) ) {
case V_165 :
switch ( F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 0 ] ) ) {
case V_167 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( ( V_156 >> 28 ) ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_153 = ( V_156 >> 24 ) & 0xF ;
if ( V_153 >= V_2 -> V_168 ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_154 = V_156 & 0xFFFF ;
if ( V_154 >= V_2 -> V_169 ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_155 = ( V_156 >> 16 ) & 0xFF ;
V_156 = ( T_1 ) - 1 ;
V_153 = F_49 ( V_153 ) ;
V_163 =
( ( ( V_166 * ) V_152 -> V_27 ) [ 0 ] ==
F_8 ( V_167 ) ) ? V_160 : V_161 ;
if ( V_163 == V_161 ) {
V_158 = F_50 (
V_2 -> V_6 ,
V_153 , V_154 , V_155 ) ;
if ( V_158 ) {
F_51 ( V_158 ) ;
F_52 ( V_158 ) ;
}
}
break;
case V_170 :
case V_171 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( V_156 >= V_2 -> V_172 )
break;
if ( ( V_2 != NULL ) && ( V_2 -> V_6 != NULL ) ) {
V_158 = F_50 ( V_2 -> V_6 ,
F_53 ( V_156 ) ,
F_54 ( V_156 ) ,
F_55 ( V_156 ) ) ;
if ( V_158 ) {
V_2 -> V_164 [ V_156 ] . V_173 = V_162 ;
V_2 -> V_164 [ V_156 ] . V_174 = V_175 ;
V_2 -> V_164 [ V_156 ] . V_176 = V_116 ;
F_52 ( V_158 ) ;
}
}
}
if ( V_156 != ( T_1 ) - 1 ) {
if ( V_156 >= V_2 -> V_172 )
break;
if ( ( V_2 -> V_164 [ V_156 ] . V_174 ==
F_9 ( * ( V_166 * ) V_152 -> V_27 ) ) &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) )
V_2 -> V_164 [ V_156 ] . V_174 = 0 ;
} else for ( V_156 = 0 ;
V_156 < V_2 -> V_172 ; ++ V_156 ) {
if ( ( V_2 -> V_164 [ V_156 ] . V_174 ==
F_9 ( * ( V_166 * ) V_152 -> V_27 ) ) &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) )
V_2 -> V_164 [ V_156 ] . V_174 = 0 ;
}
break;
case V_178 :
switch ( F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 0 ] ) ) {
case V_179 :
V_2 -> V_180 =
( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] == F_8 ( 3 ) ) ;
break;
case V_181 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( V_156 >= V_2 -> V_172 )
break;
V_2 -> V_164 [ V_156 ] . V_173 = V_161 ;
V_2 -> V_164 [ V_156 ] . V_174 =
V_175 ;
V_2 -> V_164 [ V_156 ] . V_176 = V_116 ;
break;
case V_182 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( V_156 >= V_2 -> V_172 )
break;
V_2 -> V_164 [ V_156 ] . V_173 = V_160 ;
V_2 -> V_164 [ V_156 ] . V_174 =
V_175 ;
V_2 -> V_164 [ V_156 ] . V_176 = V_116 ;
break;
case V_183 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( V_156 >= V_2 -> V_172 )
break;
if ( V_2 -> V_164 [ V_156 ] . V_174 &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) )
break;
V_2 -> V_164 [ V_156 ] . V_173 = V_162 ;
V_2 -> V_164 [ V_156 ] . V_174 =
V_175 ;
V_2 -> V_164 [ V_156 ] . V_176 = V_116 ;
break;
case V_175 :
break;
case V_184 :
case V_185 :
V_156 = F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] ) ;
if ( ( V_156 >> 28 ) ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_153 = ( V_156 >> 24 ) & 0xF ;
if ( V_153 >= V_2 -> V_168 ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_154 = V_156 & 0xFFFF ;
if ( V_154 >= V_2 -> V_169 ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_155 = ( V_156 >> 16 ) & 0xFF ;
V_156 = ( T_1 ) - 1 ;
V_153 = F_49 ( V_153 ) ;
V_163 =
( ( ( V_166 * ) V_152 -> V_27 ) [ 0 ] ==
F_8 ( V_184 ) ) ? V_161 : V_160 ;
if ( V_163 == V_161 ) {
V_158 = F_50 ( V_2 -> V_6 ,
V_153 ,
V_154 ,
V_155 ) ;
if ( V_158 ) {
F_51 ( V_158 ) ;
F_52 ( V_158 ) ;
}
}
break;
case V_186 :
if ( V_2 -> V_187 )
break;
switch ( F_9 ( ( ( V_166 * ) V_152 -> V_27 ) [ 3 ] ) ) {
case V_188 :
case V_189 :
case V_190 :
case V_191 :
V_156 = F_9 (
( ( V_166 * ) V_152 -> V_27 ) [ 2 ] ) ;
if ( ( V_156 >> 28 ) ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_153 = ( V_156 >> 24 ) & 0xF ;
if ( V_153 >= V_2 -> V_168 ) {
V_156 = ( T_1 ) - 1 ;
break;
}
V_154 = V_156 & 0xFFFF ;
V_155 = ( V_156 >> 16 ) & 0xFF ;
V_156 = ( T_1 ) - 1 ;
if ( V_154 >= V_2 -> V_169 ) {
if ( ( 0x2000 <= V_154 ) || V_155 || V_153 ||
( ( V_153 = ( V_154 >> 7 ) & 0x3F ) >=
V_2 -> V_168 ) )
break;
V_155 = ( V_154 >> 4 ) & 7 ;
V_154 &= 0xF ;
}
V_153 = F_49 ( V_153 ) ;
V_163 =
( ( ( ( V_166 * ) V_152 -> V_27 ) [ 3 ]
== F_8 ( V_188 ) ) ||
( ( ( V_166 * ) V_152 -> V_27 ) [ 3 ]
== F_8 ( V_190 ) ) ) ?
V_161 : V_160 ;
break;
}
break;
}
if ( V_156 != ( T_1 ) - 1 ) {
if ( V_156 >= V_2 -> V_172 )
break;
if ( ( V_2 -> V_164 [ V_156 ] . V_174 ==
F_9 ( * ( V_166 * ) V_152 -> V_27 ) ) &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) )
V_2 -> V_164 [ V_156 ] . V_174 = 0 ;
} else for ( V_156 = 0 ;
V_156 < V_2 -> V_172 ; ++ V_156 ) {
if ( ( V_2 -> V_164 [ V_156 ] . V_174 ==
F_9 ( * ( V_166 * ) V_152 -> V_27 ) ) &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) )
V_2 -> V_164 [ V_156 ] . V_174 = 0 ;
}
break;
case V_192 :
if ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] == F_8 ( V_193 ) &&
( ( ( V_166 * ) V_152 -> V_27 ) [ 6 ] == ( ( V_166 * ) V_152 -> V_27 ) [ 5 ] ||
( ( V_166 * ) V_152 -> V_27 ) [ 4 ] == F_8 ( V_194 ) ) ) {
for ( V_156 = 0 ;
V_156 < V_2 -> V_172 ;
++ V_156 ) {
V_2 -> V_164 [ V_156 ] . V_174 =
V_183 ;
V_2 -> V_164 [ V_156 ] . V_173 = V_161 ;
V_2 -> V_164 [ V_156 ] . V_176 =
V_116 ;
}
}
if ( ( ( V_166 * ) V_152 -> V_27 ) [ 1 ] == F_8 ( V_193 ) &&
( ( V_166 * ) V_152 -> V_27 ) [ 6 ] == 0 &&
( ( V_166 * ) V_152 -> V_27 ) [ 4 ] == F_8 ( V_195 ) ) {
for ( V_156 = 0 ;
V_156 < V_2 -> V_172 ;
++ V_156 ) {
V_2 -> V_164 [ V_156 ] . V_174 =
V_183 ;
V_2 -> V_164 [ V_156 ] . V_173 = V_160 ;
V_2 -> V_164 [ V_156 ] . V_176 =
V_116 ;
}
}
break;
}
V_156 = 0 ;
V_196:
if ( V_163 == V_159 )
for (; V_156 < V_2 -> V_172 ; ++ V_156 ) {
if ( ( V_2 -> V_164 [ V_156 ] . V_174 == 0 ) &&
( V_2 -> V_164 [ V_156 ] . V_173 != V_159 ) &&
F_56 ( V_116 , V_2 -> V_164 [ V_156 ] . V_176 + V_177 ) ) {
V_163 =
V_2 -> V_164 [ V_156 ] . V_173 ;
V_2 -> V_164 [ V_156 ] . V_173 = V_159 ;
V_153 = F_53 ( V_156 ) ;
V_154 = F_54 ( V_156 ) ;
V_155 = F_55 ( V_156 ) ;
break;
}
}
if ( V_163 == V_159 )
return;
if ( ! V_2 || ! V_2 -> V_6 )
return;
if ( ( V_153 == V_197 ) &&
( V_163 != V_159 ) ) {
if ( V_2 -> V_164 [ V_156 ] . V_198 == 1 )
V_2 -> V_164 [ V_156 ] . V_198 = 2 ;
F_57 ( V_2 , V_156 ) ;
}
V_158 = F_50 ( V_2 -> V_6 , V_153 , V_154 , V_155 ) ;
if ( V_158 ) {
switch ( V_163 ) {
case V_160 :
#if ( F_58 ( V_199 ) )
F_51 ( V_158 ) ;
#else
if ( F_59 ( V_158 ) ) {
F_60 ( V_158 , V_200 ) ;
F_61 ( V_3 , V_158 ,
L_23 ,
( V_153 == V_197 ) ?
L_24 :
L_25 ) ;
}
#endif
break;
case V_161 :
if ( ! F_59 ( V_158 ) ) {
F_61 ( V_3 , V_158 ,
L_26 ,
( V_153 == V_197 ) ?
L_27 :
L_25 ) ;
F_60 ( V_158 , V_201 ) ;
}
case V_162 :
if ( ( V_153 == V_197 )
&& ( ! V_2 -> V_164 [ V_156 ] . V_198 ) ) {
#if ( F_58 ( V_199 ) )
F_51 ( V_158 ) ;
#else
if ( ! F_59 ( V_158 ) )
break;
F_60 ( V_158 , V_200 ) ;
F_61 ( V_3 , V_158 ,
L_23 ,
L_28 ) ;
#endif
break;
}
F_62 ( & V_158 -> V_202 ) ;
default:
break;
}
F_52 ( V_158 ) ;
V_163 = V_159 ;
}
if ( V_163 == V_161 )
F_63 ( V_2 -> V_6 , V_153 , V_154 , V_155 ) ;
if ( V_153 == V_197 ) {
V_156 ++ ;
V_163 = V_159 ;
goto V_196;
}
}
static int F_64 ( struct V_1 * V_203 , int V_204 )
{
int V_61 , V_205 ;
int V_206 ;
struct V_207 * V_208 ;
struct V_157 * V_2 ;
struct V_35 * V_81 ;
struct V_35 * V_209 ;
int V_210 = 0 ;
V_208 = V_203 -> V_6 ;
F_65 ( V_208 ) ;
F_66 ( V_203 ) ;
if ( V_203 -> V_211 -> V_212 != V_213 -> V_212 ) {
F_67 ( V_208 -> V_214 ) ;
F_68 ( V_203 -> V_211 ) ;
V_210 = 1 ;
}
V_206 = F_69 ( V_203 , V_204 ? 0 : F_36 ( V_203 ) ) ;
if ( V_206 )
goto V_215;
for ( V_206 = 1 , V_61 = 0 ; V_61 < ( V_203 -> V_6 -> V_7 + V_8 ) ; V_61 ++ ) {
struct V_16 * V_16 = & V_203 -> V_18 [ V_61 ] ;
if ( ! ( V_16 -> V_10 -> V_31 . V_32 & F_8 ( V_91 | V_88 ) ) &&
( V_16 -> V_10 -> V_31 . V_32 & F_8 ( V_89 ) ) ) {
unsigned long V_216 ;
F_15 ( & V_16 -> V_30 , V_216 ) ;
F_70 ( & V_16 -> V_29 ) ;
F_16 ( & V_16 -> V_30 , V_216 ) ;
F_71 () ;
V_206 = 0 ;
}
}
if ( V_206 == 0 )
F_72 ( 2 ) ;
V_61 = V_203 -> V_217 ;
F_4 ( V_203 ) ;
F_5 ( V_203 -> V_4 , V_203 -> V_218 , V_203 -> V_219 , V_203 -> V_220 ) ;
V_203 -> V_219 = NULL ;
V_203 -> V_220 = 0 ;
F_45 ( V_203 -> V_66 ) ;
V_203 -> V_66 = NULL ;
F_73 ( V_203 ) ;
F_45 ( V_203 -> V_164 ) ;
V_203 -> V_164 = NULL ;
V_205 = F_74 ( V_61 ) -> V_205 ;
if ( V_205 & V_221 ) {
if ( ( ( V_206 = F_75 ( V_203 -> V_4 , F_76 ( 31 ) ) ) ) ||
( ( V_206 = F_77 ( V_203 -> V_4 , F_76 ( 31 ) ) ) ) )
goto V_215;
} else {
if ( ( ( V_206 = F_75 ( V_203 -> V_4 , F_76 ( 32 ) ) ) ) ||
( ( V_206 = F_77 ( V_203 -> V_4 , F_76 ( 32 ) ) ) ) )
goto V_215;
}
if ( ( V_206 = ( * ( F_74 ( V_61 ) -> V_23 ) ) ( V_203 ) ) )
goto V_215;
if ( V_205 & V_221 )
if ( ( V_206 = F_75 ( V_203 -> V_4 , F_76 ( 32 ) ) ) )
goto V_215;
if ( V_210 ) {
V_203 -> V_211 = F_78 ( V_222 , V_203 , L_29 ,
V_203 -> V_150 ) ;
if ( F_79 ( V_203 -> V_211 ) ) {
V_206 = F_80 ( V_203 -> V_211 ) ;
goto V_215;
}
}
( void ) F_81 ( V_203 ) ;
if ( ( V_205 & V_223 ) && ( V_208 -> V_224 > 34 ) ) {
V_208 -> V_224 = 34 ;
V_208 -> V_225 = ( V_208 -> V_224 * 8 ) + 112 ;
}
if ( ( V_205 & V_226 ) && ( V_208 -> V_224 > 17 ) ) {
V_208 -> V_224 = 17 ;
V_208 -> V_225 = ( V_208 -> V_224 * 8 ) + 112 ;
}
F_82 ( V_203 , 1 ) ;
F_83 ( V_203 ) ;
V_209 = NULL ;
F_84 (dev, host) {
unsigned long V_25 ;
F_15 ( & V_2 -> V_227 , V_25 ) ;
F_85 (command, &dev->cmd_list, list)
if ( V_81 -> V_228 . V_229 == V_230 ) {
V_81 -> V_228 . V_231 = (struct V_232 * ) V_209 ;
V_209 = V_81 ;
}
F_16 ( & V_2 -> V_227 , V_25 ) ;
}
while ( ( V_81 = V_209 ) ) {
V_209 = (struct V_35 * ) V_81 -> V_228 . V_231 ;
V_81 -> V_228 . V_231 = NULL ;
V_81 -> V_233 = V_234 << 16
| V_235 << 8
| V_236 ;
V_81 -> V_228 . V_229 = V_237 ;
V_81 -> V_238 ( V_81 ) ;
}
V_206 = 0 ;
V_215:
V_203 -> V_239 = 0 ;
F_86 ( V_208 ) ;
if ( V_210 ) {
F_87 ( V_208 -> V_214 ) ;
}
return V_206 ;
}
int F_88 ( struct V_1 * V_203 , int V_204 )
{
unsigned long V_216 = 0 ;
int V_206 ;
struct V_207 * V_208 ;
if ( F_89 ( & V_203 -> V_42 , V_216 ) == 0 )
return - V_86 ;
if ( V_203 -> V_239 ) {
F_16 ( & V_203 -> V_42 , V_216 ) ;
return - V_86 ;
}
V_203 -> V_239 = 1 ;
F_16 ( & V_203 -> V_42 , V_216 ) ;
V_208 = V_203 -> V_6 ;
F_65 ( V_208 ) ;
if ( V_204 < 2 ) for ( V_206 = 60 ; V_206 ; -- V_206 ) {
struct V_157 * V_2 ;
struct V_35 * V_81 ;
int V_240 = 0 ;
F_84 (dev, host) {
F_15 ( & V_2 -> V_227 , V_216 ) ;
F_85 (command, &dev->cmd_list, list) {
if ( V_81 -> V_228 . V_229 == V_230 ) {
V_240 ++ ;
break;
}
}
F_16 ( & V_2 -> V_227 , V_216 ) ;
if ( V_240 )
break;
}
if ( V_240 == 0 )
break;
F_72 ( 1 ) ;
}
if ( V_204 < 2 )
F_90 ( V_203 ) ;
F_15 ( V_208 -> V_214 , V_216 ) ;
V_206 = F_64 ( V_203 , V_204 ? V_204 : ( ( V_241 != 0 ) && ( V_241 != 1 ) ) ) ;
F_16 ( V_208 -> V_214 , V_216 ) ;
if ( ( V_204 < 2 ) && ( V_206 == - V_242 ) ) {
struct V_16 * V_243 = F_14 ( V_203 ) ;
if ( V_243 ) {
struct V_244 * V_245 ;
int V_121 ;
F_20 ( V_243 ) ;
V_245 = (struct V_244 * ) F_28 ( V_243 ) ;
V_245 -> V_81 = F_8 ( V_246 ) ;
V_245 -> type = F_8 ( V_247 ) ;
V_245 -> V_115 = F_8 ( 1 ) ;
V_245 -> V_248 = F_8 ( 1 ) ;
V_245 -> V_249 = F_8 ( 1 ) ;
V_245 -> V_250 = F_8 ( 0 ) ;
V_121 = F_26 ( V_251 ,
V_243 ,
sizeof( struct V_244 ) ,
V_252 ,
- 2 , 1 ,
NULL , NULL ) ;
if ( V_121 >= 0 )
F_46 ( V_243 ) ;
if ( V_121 != - V_120 )
F_17 ( V_243 ) ;
}
}
return V_206 ;
}
int F_91 ( struct V_1 * V_203 )
{
int V_253 ;
unsigned long V_254 , V_216 = 0 ;
struct V_255 * V_60 ;
struct V_207 * V_208 ;
if ( F_89 ( & V_203 -> V_42 , V_216 ) == 0 )
return 0 ;
if ( V_203 -> V_239 || ! ( V_253 = F_36 ( V_203 ) ) ) {
F_16 ( & V_203 -> V_42 , V_216 ) ;
return 0 ;
}
V_203 -> V_239 = 1 ;
V_254 = V_116 / V_117 ;
V_60 = V_203 -> V_256 . V_28 ;
while ( V_60 != & V_203 -> V_256 ) {
struct V_257 * V_243 = F_92 ( V_60 , struct V_257 , V_28 ) ;
struct V_22 * V_22 ;
struct V_16 * V_16 ;
if ( V_243 -> V_250 > 20 ) {
T_1 V_258 = V_243 -> V_116 ;
if ( ( V_254 - V_258 ) > V_259 ) {
V_60 = V_60 -> V_28 ;
F_93 ( V_203 , V_243 ) ;
continue;
}
}
V_22 = F_94 ( sizeof( struct V_22 ) , V_260 ) ;
V_16 = F_94 ( sizeof( struct V_16 ) , V_260 ) ;
if ( V_16 && V_22 ) {
struct V_151 * V_261 ;
V_16 -> V_10 = V_22 ;
V_16 -> V_2 = V_203 ;
F_20 ( V_16 ) ;
V_16 -> type = V_39 ;
V_16 -> V_26 = sizeof ( struct V_16 ) ;
V_16 -> V_27 = V_22 -> V_27 ;
V_261 = (struct V_151 * ) V_22 -> V_27 ;
V_261 -> V_81 = F_8 ( V_178 ) ;
V_261 -> V_262 = F_8 ( 0xFFFFFFFF ) ;
( ( V_166 * ) V_261 -> V_27 ) [ 0 ] = F_8 ( V_263 ) ;
( ( V_166 * ) V_261 -> V_27 ) [ 1 ] = F_8 ( V_264 ) ;
( ( V_166 * ) V_261 -> V_27 ) [ 2 ] = F_8 ( V_265 ) ;
( ( V_166 * ) V_261 -> V_27 ) [ 3 ] = F_8 ( V_253 ) ;
F_29 ( & V_16 -> V_109 , & V_243 -> V_256 ) ;
V_243 -> V_250 ++ ;
F_70 ( & V_243 -> V_266 ) ;
} else {
F_19 ( V_47 L_30 ) ;
F_45 ( V_16 ) ;
F_45 ( V_22 ) ;
}
V_60 = V_60 -> V_28 ;
}
F_16 ( & V_203 -> V_42 , V_216 ) ;
if ( V_253 < 0 ) {
F_19 ( V_78 L_31 , V_203 -> V_150 , V_253 ) ;
goto V_215;
}
F_19 ( V_78 L_32 , V_203 -> V_150 , V_253 ) ;
if ( ! V_241 || ( ( V_241 == 1 ) &&
( V_203 -> V_267 . V_268 &
V_269 ) ) )
goto V_215;
V_208 = V_203 -> V_6 ;
if ( V_203 -> V_211 -> V_212 != V_213 -> V_212 )
F_15 ( V_208 -> V_214 , V_216 ) ;
V_253 = F_64 ( V_203 , V_241 != 1 ) ;
if ( V_203 -> V_211 -> V_212 != V_213 -> V_212 )
F_16 ( V_208 -> V_214 , V_216 ) ;
return V_253 ;
V_215:
V_203 -> V_239 = 0 ;
return V_253 ;
}
int V_222 ( void * V_27 )
{
struct V_1 * V_2 = V_27 ;
struct V_22 * V_22 , * V_270 ;
struct V_16 * V_16 , * V_271 ;
struct V_257 * V_243 ;
unsigned long V_25 ;
F_95 ( V_76 , V_213 ) ;
unsigned long V_272 = V_116 + V_117 ;
unsigned long V_273 = V_272 ;
long V_274 = V_117 ;
if ( V_2 -> V_275 )
return - V_87 ;
V_2 -> V_275 = 1 ;
F_96 ( & V_2 -> V_66 -> V_67 [ V_125 ] . V_276 , & V_76 ) ;
F_97 ( V_277 ) ;
F_2 ( ( V_3 L_33 ) ) ;
while ( 1 ) {
F_15 ( V_2 -> V_66 -> V_67 [ V_125 ] . V_140 , V_25 ) ;
while( ! F_98 ( & ( V_2 -> V_66 -> V_67 [ V_125 ] . V_278 ) ) ) {
struct V_255 * V_60 ;
struct V_151 * V_152 ;
F_97 ( V_279 ) ;
V_60 = V_2 -> V_66 -> V_67 [ V_125 ] . V_278 . V_28 ;
F_99 ( V_60 ) ;
F_16 ( V_2 -> V_66 -> V_67 [ V_125 ] . V_140 , V_25 ) ;
V_16 = F_92 ( V_60 , struct V_16 , V_109 ) ;
V_22 = V_16 -> V_10 ;
memset ( V_16 , 0 , sizeof( struct V_16 ) ) ;
V_16 -> type = V_39 ;
V_16 -> V_26 = sizeof( struct V_16 ) ;
V_16 -> V_10 = V_22 ;
V_16 -> V_27 = V_22 -> V_27 ;
V_16 -> V_2 = V_2 ;
V_152 = (struct V_151 * ) V_22 -> V_27 ;
if ( V_152 -> V_81 == F_8 ( V_165 ) ) {
F_48 ( V_2 , V_16 ) ;
* ( V_166 * ) V_22 -> V_27 = F_8 ( V_280 ) ;
F_44 ( V_16 , ( T_3 ) sizeof( T_1 ) ) ;
} else {
T_1 V_254 , V_258 ;
unsigned long V_216 ;
unsigned V_281 ;
struct V_22 * * V_282 , * * V_283 ;
struct V_16 * * V_284 , * * V_285 ;
if ( ( V_152 -> V_81 ==
F_8 ( V_178 ) ) ||
( V_152 -> V_81 ==
F_8 ( V_192 ) ) ) {
F_48 ( V_2 , V_16 ) ;
}
V_254 = V_116 / V_117 ;
V_281 = F_9 ( V_2 -> V_23 -> V_286 )
/ sizeof( struct V_22 ) ;
F_15 ( & V_2 -> V_42 , V_216 ) ;
V_60 = V_2 -> V_256 . V_28 ;
while ( V_60 != & V_2 -> V_256 ) {
V_60 = V_60 -> V_28 ;
++ V_281 ;
}
F_16 ( & V_2 -> V_42 , V_216 ) ;
V_282 = NULL ;
V_284 = NULL ;
if ( V_281
&& ( ( V_282 = F_100 ( sizeof( struct V_22 * ) * V_281 , V_287 ) ) )
&& ( ( V_284 = F_100 ( sizeof( struct V_16 * ) * V_281 , V_287 ) ) ) ) {
V_283 = V_282 ;
V_285 = V_284 ;
while ( V_283 < & V_282 [ V_281 ] ) {
if ( ! ( * ( V_283 ++ ) = F_100 ( sizeof( struct V_22 ) , V_287 ) ) ) {
-- V_283 ;
break;
}
if ( ! ( * ( V_285 ++ ) = F_100 ( sizeof( struct V_16 ) , V_287 ) ) ) {
F_45 ( * ( -- V_283 ) ) ;
break;
}
}
if ( ( V_281 = V_283 - V_282 ) == 0 ) {
F_45 ( V_284 ) ;
V_284 = NULL ;
F_45 ( V_282 ) ;
V_282 = NULL ;
}
} else {
F_45 ( V_282 ) ;
V_282 = NULL ;
}
F_15 ( & V_2 -> V_42 , V_216 ) ;
V_60 = V_2 -> V_256 . V_28 ;
V_283 = V_282 ;
V_285 = V_284 ;
while ( V_60 != & V_2 -> V_256 ) {
V_243 = F_92 ( V_60 , struct V_257 , V_28 ) ;
if ( V_243 -> V_250 > 20 )
{
V_258 = V_243 -> V_116 ;
if ( ( V_254 - V_258 ) > V_259 ) {
V_60 = V_60 -> V_28 ;
F_93 ( V_2 , V_243 ) ;
continue;
}
}
if ( V_283 < & V_282 [ V_281 ] ) {
V_270 = * V_283 ;
* ( V_283 ++ ) = NULL ;
V_271 = * V_285 ;
* ( V_285 ++ ) = NULL ;
memcpy ( V_270 , V_22 , sizeof( struct V_22 ) ) ;
memcpy ( V_271 , V_16 , sizeof( struct V_16 ) ) ;
V_271 -> V_10 = V_270 ;
F_29 ( & V_271 -> V_109 , & V_243 -> V_256 ) ;
V_243 -> V_250 ++ ;
F_70 ( & V_243 -> V_266 ) ;
} else {
F_19 ( V_47 L_30 ) ;
}
V_60 = V_60 -> V_28 ;
}
* ( V_166 * ) V_22 -> V_27 = F_8 ( V_280 ) ;
F_44 ( V_16 , sizeof( T_1 ) ) ;
F_16 ( & V_2 -> V_42 , V_216 ) ;
V_283 = V_282 ;
V_285 = V_284 ;
while ( V_283 < & V_282 [ V_281 ] ) {
F_45 ( * V_283 ) ;
F_45 ( * V_285 ) ;
++ V_285 ;
++ V_283 ;
}
F_45 ( V_282 ) ;
F_45 ( V_284 ) ;
}
F_45 ( V_16 ) ;
F_15 ( V_2 -> V_66 -> V_67 [ V_125 ] . V_140 , V_25 ) ;
}
F_16 ( V_2 -> V_66 -> V_67 [ V_125 ] . V_140 , V_25 ) ;
if ( ( F_56 ( V_273 , V_272 ) )
&& ( ( V_274 = V_273 - V_116 ) <= 0 ) ) {
V_273 = V_272 ;
if ( F_91 ( V_2 ) == 0 ) {
V_274 = ( ( long ) ( unsigned ) V_288 )
* V_117 ;
V_273 = V_116 + V_274 ;
} else if ( ! V_2 -> V_66 )
break;
}
if ( ! F_56 ( V_273 , V_272 )
&& ( ( V_274 = V_272 - V_116 ) <= 0 ) ) {
struct V_289 V_290 ;
int V_291 ;
V_291 = F_91 ( V_2 ) ;
if ( ! V_291 && ! V_2 -> V_66 )
break;
V_273 = V_116
+ ( ( long ) ( unsigned ) V_288 )
* V_117 ;
F_101 ( & V_290 ) ;
if ( ( ( 1000000 - ( 1000000 / V_117 ) ) > V_290 . V_292 )
&& ( V_290 . V_292 > ( 1000000 / V_117 ) ) )
V_274 = ( ( ( 1000000 - V_290 . V_292 ) * V_117 )
+ 500000 ) / 1000000 ;
else if ( V_291 == 0 ) {
struct V_16 * V_17 ;
if ( ( V_17 = F_14 ( V_2 ) ) ) {
int V_121 ;
V_166 * V_293 ;
F_20 ( V_17 ) ;
V_293 = ( V_166 * ) F_28 ( V_17 ) ;
if ( V_290 . V_292 > 500000 )
++ V_290 . V_294 ;
* V_293 = F_8 ( V_290 . V_294 ) ;
V_121 = F_26 ( V_295 ,
V_17 ,
sizeof( * V_293 ) ,
V_252 ,
1 , 1 ,
NULL ,
NULL ) ;
if ( V_121 >= 0 )
F_46 ( V_17 ) ;
if ( V_121 != - V_120 )
F_17 ( V_17 ) ;
}
V_274 = ( long ) ( unsigned ) V_296 * V_117 ;
} else {
V_274 = 10 * V_117 ;
}
V_272 = V_116 + V_274 ;
if ( F_56 ( V_273 , V_272 ) )
V_274 = V_273 - V_116 ;
}
if ( V_274 <= 0 )
V_274 = 1 ;
F_97 ( V_277 ) ;
F_102 ( V_274 ) ;
if ( F_103 () )
break;
}
if ( V_2 -> V_66 )
F_104 ( & V_2 -> V_66 -> V_67 [ V_125 ] . V_276 , & V_76 ) ;
V_2 -> V_275 = 0 ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_14 ;
int V_297 ;
int V_291 = 0 ;
int V_298 ;
V_298 = F_106 ( V_299 ) ;
if ( ! V_2 -> V_106 && V_2 -> V_300 && V_2 -> V_19 > 1 ) {
for ( V_14 = 0 ; V_14 < V_2 -> V_19 ; V_14 ++ ) {
V_2 -> V_301 [ V_14 ] . V_21 = V_14 ;
V_2 -> V_301 [ V_14 ] . V_2 = V_2 ;
if ( F_107 ( V_2 -> V_302 [ V_14 ] . V_15 ,
V_2 -> V_303 . V_304 ,
0 , L_34 , & ( V_2 -> V_301 [ V_14 ] ) ) ) {
F_19 ( V_78 L_35 ,
V_2 -> V_150 , V_2 -> V_154 , V_14 ) ;
for ( V_297 = 0 ; V_297 < V_14 ; V_297 ++ )
F_108 ( V_2 -> V_302 [ V_297 ] . V_15 ,
& ( V_2 -> V_301 [ V_297 ] ) ) ;
F_109 ( V_2 -> V_4 ) ;
V_291 = - 1 ;
}
if ( F_110 ( V_2 -> V_302 [ V_14 ] . V_15 ,
F_111 ( V_298 ) ) ) {
F_19 ( V_78 L_36 ,
V_2 -> V_150 , V_2 -> V_154 , V_298 ) ;
}
V_298 = F_112 ( V_298 , V_299 ) ;
}
} else {
V_2 -> V_301 [ 0 ] . V_21 = 0 ;
V_2 -> V_301 [ 0 ] . V_2 = V_2 ;
if ( F_107 ( V_2 -> V_4 -> V_305 , V_2 -> V_303 . V_304 ,
V_306 , L_34 ,
& ( V_2 -> V_301 [ 0 ] ) ) < 0 ) {
if ( V_2 -> V_307 )
F_113 ( V_2 -> V_4 ) ;
F_19 ( V_78 L_37 ,
V_2 -> V_150 , V_2 -> V_154 ) ;
V_291 = - 1 ;
}
}
return V_291 ;
}
void F_73 ( struct V_1 * V_2 )
{
int V_14 ;
int V_298 ;
V_298 = F_106 ( V_299 ) ;
if ( V_2 -> V_4 -> V_158 == V_308 ||
V_2 -> V_4 -> V_158 == V_309 ||
V_2 -> V_4 -> V_158 == V_310 ||
V_2 -> V_4 -> V_158 == V_311 ) {
if ( V_2 -> V_19 > 1 ) {
for ( V_14 = 0 ; V_14 < V_2 -> V_19 ; V_14 ++ ) {
if ( F_110 (
V_2 -> V_302 [ V_14 ] . V_15 , NULL ) ) {
F_19 ( V_78 L_38 ,
V_2 -> V_150 , V_2 -> V_154 , V_298 ) ;
}
V_298 = F_112 ( V_298 , V_299 ) ;
F_108 ( V_2 -> V_302 [ V_14 ] . V_15 ,
& ( V_2 -> V_301 [ V_14 ] ) ) ;
}
} else {
F_108 ( V_2 -> V_4 -> V_305 , & ( V_2 -> V_301 [ 0 ] ) ) ;
}
} else {
F_108 ( V_2 -> V_4 -> V_305 , V_2 ) ;
}
if ( V_2 -> V_307 )
F_113 ( V_2 -> V_4 ) ;
else if ( V_2 -> V_19 > 1 )
F_109 ( V_2 -> V_4 ) ;
}
