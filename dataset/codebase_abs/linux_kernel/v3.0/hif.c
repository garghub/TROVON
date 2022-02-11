static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
#if V_6
V_4 -> V_7 = F_3 ( V_8 , V_5 ) ;
#endif
V_4 -> V_3 = V_3 ;
V_4 -> V_9 = V_10 ;
F_4 ( V_3 , V_4 ) ;
return V_4 ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_6 ( V_3 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
const struct V_11 * V_12 )
{
int V_13 ;
struct V_1 * V_14 ;
int V_15 ;
F_8 ( V_16 ,
( L_1
L_2 ,
V_3 -> V_17 , V_3 -> V_18 , V_3 -> V_14 ,
V_3 -> V_19 , V_3 -> V_20 ) ) ;
F_1 ( V_3 ) ;
V_14 = F_5 ( V_3 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_21 = true ;
F_9 ( & V_14 -> V_22 ) ;
F_9 ( & V_14 -> V_23 ) ;
F_10 ( & V_14 -> V_24 ) ;
if ( ! V_25 )
V_14 -> V_26 = true ;
F_11 ( V_14 -> V_27 , sizeof( V_14 -> V_27 ) ) ;
for ( V_15 = 0 ; V_15 < V_28 ; V_15 ++ ) {
F_12 ( & V_14 -> V_27 [ V_15 ] . V_29 , 0 ) ;
F_13 ( V_14 , & V_14 -> V_27 [ V_15 ] ) ;
}
F_12 ( & V_14 -> V_30 , 0 ) ;
V_13 = F_14 ( V_14 , V_3 ) ;
return V_13 ;
}
static void F_15 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
struct V_1 * V_14 ;
V_14 = F_5 ( V_3 ) ;
if ( V_14 -> V_32 != NULL )
V_31 = V_33 .
V_34 ( V_14 -> V_32 , V_14 ) ;
if ( V_14 -> V_21 )
V_14 -> V_21 = false ;
else
V_31 = F_16 ( V_14 , V_3 ) ;
F_17 ( V_14 ) ;
F_18 ( V_14 ) ;
}
static int F_19 ( struct V_14 * V_35 )
{
struct V_2 * V_3 = F_20 ( V_35 ) ;
int V_31 = 0 ;
struct V_1 * V_14 ;
V_14 = F_5 ( V_3 ) ;
if ( V_14 && V_14 -> V_32 &&
V_33 . V_36 ) {
V_14 -> V_37 = true ;
V_31 = V_33 .
V_36 ( V_14 -> V_32 ) ;
if ( V_31 )
V_14 -> V_37 = false ;
}
F_17 ( V_14 ) ;
switch ( V_31 ) {
case 0 :
return 0 ;
case V_38 :
return - V_39 ;
default:
return - 1 ;
}
}
static int F_21 ( struct V_14 * V_35 )
{
struct V_2 * V_3 = F_20 ( V_35 ) ;
int V_31 = 0 ;
struct V_1 * V_14 ;
V_14 = F_5 ( V_3 ) ;
if ( V_14 && V_14 -> V_32 &&
V_33 . V_36 ) {
V_31 = V_33 .
V_40 ( V_14 -> V_32 ) ;
if ( V_31 == 0 )
V_14 -> V_37 = false ;
}
return V_31 ;
}
int F_22 ( T_1 * V_41 )
{
int V_42 ;
F_23 ( V_41 != NULL ) ;
F_24 ( V_43 ) ;
V_33 = * V_41 ;
V_44 = 1 ;
V_42 = F_25 ( & V_45 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_14 ,
T_2 V_46 ,
T_3 * V_47 ,
T_2 V_48 ,
T_2 V_49 ,
void * V_50 )
{
T_3 V_51 ;
int V_31 = 0 ;
int V_13 ;
T_3 * V_52 ;
bool V_53 = false ;
F_23 ( V_14 != NULL ) ;
F_23 ( V_14 -> V_3 != NULL ) ;
F_8 ( V_16 , ( L_3 ,
V_14 , V_47 , V_46 ) ) ;
do {
if ( V_49 & V_54 ) {
} else {
F_8 ( V_55 ,
( L_4 , V_49 ) ) ;
V_31 = V_56 ;
break;
}
if ( V_49 & V_57 ) {
V_48 = ( V_48 / V_58 ) * V_58 ;
F_8 ( V_16 ,
( L_5 ,
V_48 ) ) ;
} else if ( V_49 & V_59 ) {
F_8 ( V_16 ,
( L_6 ,
V_48 ) ) ;
} else {
F_8 ( V_55 ,
( L_7 , V_49 ) ) ;
V_31 = V_56 ;
break;
}
#if 0
if (length & 0x3) {
A_PRINTF(KERN_ALERT"AR6000: HIF (%s) is not a multiple of 4 bytes, addr:0x%X, len:%d\n",
request & HIF_WRITE ? "write":"read", address, length);
}
#endif
if ( V_49 & V_60 ) {
if ( ( V_46 >= F_27 ( 0 ) ) &&
( V_46 <= F_28 ( 3 ) ) )
{
F_23 ( V_48 <= V_61 ) ;
V_46 += ( V_61 - V_48 ) ;
}
}
if ( V_49 & V_62 ) {
V_51 = V_63 ;
F_8 ( V_16 , ( L_8 , V_46 ) ) ;
} else if ( V_49 & V_64 ) {
V_51 = V_65 ;
F_8 ( V_16 , ( L_9 , V_46 ) ) ;
} else {
F_8 ( V_55 ,
( L_10 , V_49 ) ) ;
V_31 = V_56 ;
break;
}
if ( V_49 & V_60 ) {
#if V_6
if ( F_29 ( V_47 ) ) {
F_23 ( V_14 -> V_7 != NULL ) ;
V_52 = V_14 -> V_7 ;
F_23 ( V_48 <= V_8 ) ;
memcpy ( V_52 , V_47 , V_48 ) ;
V_53 = true ;
} else {
V_52 = V_47 ;
}
#else
V_52 = V_47 ;
#endif
if ( V_51 == V_63 ) {
V_13 = F_30 ( V_14 -> V_3 , V_46 , V_52 , V_48 ) ;
F_8 ( V_16 , ( L_11 ,
V_13 , V_46 , V_48 , * ( int * ) V_52 ) ) ;
} else {
V_13 = F_31 ( V_14 -> V_3 , V_46 , V_52 , V_48 ) ;
F_8 ( V_16 , ( L_12 ,
V_13 , V_46 , V_48 , * ( int * ) V_52 ) ) ;
}
} else if ( V_49 & V_66 ) {
#if V_6
if ( F_29 ( V_47 ) ) {
F_23 ( V_14 -> V_7 != NULL ) ;
F_23 ( V_48 <= V_8 ) ;
V_52 = V_14 -> V_7 ;
V_53 = true ;
} else {
V_52 = V_47 ;
}
#else
V_52 = V_47 ;
#endif
if ( V_51 == V_63 ) {
V_13 = F_32 ( V_14 -> V_3 , V_52 , V_46 , V_48 ) ;
F_8 ( V_16 , ( L_13 ,
V_13 , V_46 , V_48 , * ( int * ) V_52 ) ) ;
} else {
V_13 = F_33 ( V_14 -> V_3 , V_52 , V_46 , V_48 ) ;
F_8 ( V_16 , ( L_14 ,
V_13 , V_46 , V_48 , * ( int * ) V_52 ) ) ;
}
#if V_6
if ( V_53 ) {
memcpy ( V_47 , V_52 , V_48 ) ;
}
#endif
} else {
F_8 ( V_55 ,
( L_15 , V_49 ) ) ;
V_31 = V_56 ;
break;
}
if ( V_13 ) {
F_8 ( V_55 ,
( L_16 , V_13 ) ) ;
V_31 = V_67 ;
}
} while ( false );
return V_31 ;
}
void F_34 ( struct V_1 * V_14 , T_4 * V_68 )
{
unsigned long V_69 ;
T_4 * V_70 ;
T_4 * V_71 ;
F_35 ( & V_14 -> V_23 , V_69 ) ;
V_71 = V_14 -> V_72 ;
if ( V_71 == NULL ) {
V_14 -> V_72 = V_68 ;
V_14 -> V_72 -> V_73 = NULL ;
} else {
for ( V_70 = V_14 -> V_72 ;
V_70 != NULL ;
V_70 = V_70 -> V_73 ) {
V_71 = V_70 ;
}
V_71 -> V_73 = V_68 ;
V_68 -> V_73 = NULL ;
}
F_36 ( & V_14 -> V_23 , V_69 ) ;
}
int
F_37 ( struct V_1 * V_14 ,
T_2 V_46 ,
T_3 * V_47 ,
T_2 V_48 ,
T_2 V_49 ,
void * V_50 )
{
int V_31 = 0 ;
T_4 * V_68 ;
F_23 ( V_14 != NULL ) ;
F_23 ( V_14 -> V_3 != NULL ) ;
F_8 ( V_16 , ( L_17 , V_14 , V_46 ) ) ;
do {
if ( ( V_49 & V_74 ) || ( V_49 & V_75 ) ) {
F_8 ( V_16 , ( L_18 ,
( V_49 & V_74 ) ? L_19 : L_20 ) ) ;
V_68 = F_38 ( V_14 ) ;
if ( V_68 == NULL ) {
F_8 ( V_55 ,
( L_21 ,
V_49 & V_66 ? L_22 : L_23 , V_46 , V_48 ) ) ;
return V_67 ;
}
V_68 -> V_46 = V_46 ;
V_68 -> V_47 = V_47 ;
V_68 -> V_48 = V_48 ;
V_68 -> V_49 = V_49 ;
V_68 -> V_50 = V_50 ;
F_34 ( V_14 , V_68 ) ;
if ( V_49 & V_75 ) {
F_8 ( V_16 , ( L_24 , ( unsigned long ) V_68 ) ) ;
F_39 ( & V_14 -> V_30 ) ;
if ( F_40 ( & V_68 -> V_29 ) != 0 ) {
return V_67 ;
} else {
int V_31 = V_68 -> V_31 ;
F_8 ( V_16 , ( L_25 ,
( unsigned long ) V_68 , V_68 -> V_31 ) ) ;
F_8 ( V_16 , ( L_26 , ( unsigned int ) V_49 ) ) ;
F_13 ( V_14 , V_68 ) ;
return V_31 ;
}
} else {
F_8 ( V_16 , ( L_27 , ( unsigned long ) V_68 ) ) ;
F_39 ( & V_14 -> V_30 ) ;
return V_76 ;
}
} else {
F_8 ( V_55 ,
( L_28 , ( unsigned int ) V_49 ) ) ;
V_31 = V_56 ;
break;
}
} while( 0 );
return V_31 ;
}
static int F_41 ( void * V_77 )
{
struct V_1 * V_14 ;
T_4 * V_49 ;
int V_31 ;
unsigned long V_69 ;
V_14 = (struct V_1 * ) V_77 ;
F_8 ( V_16 , ( L_29 ) ) ;
F_42 ( V_78 ) ;
while( ! V_14 -> V_79 ) {
if ( F_40 ( & V_14 -> V_30 ) != 0 ) {
F_8 ( V_16 , ( L_30 ) ) ;
break;
}
if ( V_14 -> V_79 ) {
F_8 ( V_16 , ( L_31 ) ) ;
break;
}
F_43 ( V_14 -> V_3 ) ;
F_35 ( & V_14 -> V_23 , V_69 ) ;
while ( V_14 -> V_72 != NULL ) {
V_49 = V_14 -> V_72 ;
if ( V_49 -> V_73 != NULL ) {
V_14 -> V_72 = V_49 -> V_73 ;
} else {
V_14 -> V_72 = NULL ;
}
F_36 ( & V_14 -> V_23 , V_69 ) ;
F_8 ( V_16 , ( L_32 , ( unsigned long ) V_49 ) ) ;
if ( V_49 -> V_80 != NULL ) {
F_44 ( V_14 -> V_26 ) ;
V_31 = F_45 ( V_14 , V_49 ) ;
} else {
V_31 = F_26 ( V_14 , V_49 -> V_46 , V_49 -> V_47 ,
V_49 -> V_48 , V_49 -> V_49 & ~ V_75 , NULL ) ;
if ( V_49 -> V_49 & V_74 ) {
void * V_50 = V_49 -> V_50 ;
F_8 ( V_16 , ( L_33 , ( unsigned long ) V_49 ) ) ;
F_13 ( V_14 , V_49 ) ;
F_8 ( V_16 , ( L_34 , ( unsigned long ) V_49 ) ) ;
V_14 -> V_81 . V_82 ( V_50 , V_31 ) ;
} else {
F_8 ( V_16 , ( L_35 , ( unsigned long ) V_49 ) ) ;
V_49 -> V_31 = V_31 ;
F_39 ( & V_49 -> V_29 ) ;
}
}
F_35 ( & V_14 -> V_23 , V_69 ) ;
}
F_36 ( & V_14 -> V_23 , V_69 ) ;
F_46 ( V_14 -> V_3 ) ;
}
F_47 ( & V_14 -> V_83 , 0 ) ;
return 0 ;
}
static T_5 F_48 ( struct V_1 * V_14 , T_2 V_51 , T_2 V_84 , T_2 V_69 , T_2 * V_85 )
{
struct V_86 V_87 ;
T_5 V_88 ;
struct V_89 * V_90 ;
struct V_2 * V_3 ;
V_3 = V_14 -> V_3 ;
V_90 = V_3 -> V_91 -> V_90 ;
memset ( & V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 . V_51 = V_51 ;
V_87 . V_84 = V_84 ;
V_87 . V_69 = V_69 ;
V_88 = F_49 ( V_90 , & V_87 , 3 ) ;
if ( ( ! V_88 ) && ( V_85 ) ) {
* V_85 = V_87 . V_85 [ 0 ] ;
}
return V_88 ;
}
int F_50 ( struct V_1 * V_14 )
{
T_5 V_88 ;
struct V_89 * V_90 ;
struct V_92 * V_91 ;
struct V_2 * V_3 ;
T_3 V_93 ;
T_2 clock ;
V_3 = V_14 -> V_3 ;
V_91 = V_3 -> V_91 ;
V_90 = V_91 -> V_90 ;
F_8 ( V_16 , ( L_36 ) ) ;
F_43 ( V_3 ) ;
do {
if ( ! V_14 -> V_37 ) {
T_2 V_85 ;
T_6 V_94 ;
T_2 V_95 ;
int V_96 = F_51 ( V_90 -> V_97 ) - 1 ;
V_90 -> V_98 . V_99 = V_96 ;
V_90 -> V_98 . V_100 = V_101 ;
V_90 -> V_98 . V_102 = V_103 ;
V_90 -> V_98 . V_104 = V_105 ;
V_90 -> V_98 . V_106 = V_107 ;
V_90 -> V_98 . V_108 = V_109 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
F_52 ( 2 ) ;
V_90 -> V_98 . clock = V_90 -> V_112 ;
V_90 -> V_98 . V_104 = V_113 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
F_52 ( 2 ) ;
V_90 -> V_98 . V_100 = V_114 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
F_52 ( 1 ) ;
V_88 = F_48 ( V_14 , V_115 , 0 , ( V_116 | V_117 ) , NULL ) ;
V_90 -> V_98 . V_100 = V_101 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
F_52 ( 1 ) ;
V_90 -> V_118 = 0 ;
if ( V_88 ) {
F_8 ( V_119 , ( L_37 , V_88 ) ) ;
break;
}
if ( ! V_90 -> V_120 ) {
V_88 = F_48 ( V_14 , V_121 , 0 , ( V_122 | V_123 ) , & V_85 ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_38 , V_88 ) ) ;
break;
}
V_90 -> V_120 = V_85 ;
}
for ( V_95 = 0 ; V_95 < 100 ; V_95 ++ ) {
V_88 = F_48 ( V_14 , V_121 , V_90 -> V_120 , ( V_122 | V_123 ) , & V_85 ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_38 , V_88 ) ) ;
break;
}
if ( V_85 & V_124 ) {
break;
}
F_52 ( 10 ) ;
}
if ( ( V_95 == 100 ) || ( V_88 ) ) {
F_8 ( V_119 , ( L_39 , V_95 , V_88 ) ) ;
break;
}
V_88 = F_48 ( V_14 , V_125 , 0 , V_126 | V_123 , & V_85 ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_40 , V_88 ) ) ;
break;
}
V_94 = V_85 >> 16 ;
V_90 -> V_98 . V_102 = V_127 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
V_88 = F_48 ( V_14 , V_128 , ( V_94 << 16 ) , V_129 | V_130 , NULL ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_41 , V_88 ) ) ;
break;
}
}
if ( V_91 -> V_90 -> V_131 & V_132 ) {
F_8 ( V_16 , ( L_42 ) ) ;
V_88 = F_53 ( V_91 , V_133 , & V_93 ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_43 , V_88 ) ) ;
V_91 -> V_134 &= ~ V_135 ;
} else {
V_88 = F_54 ( V_91 , V_133 , ( V_93 | V_136 ) ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_44 , V_88 ) ) ;
break;
}
F_55 ( V_91 ) ;
V_90 -> V_98 . V_108 = V_137 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
}
}
if ( F_56 ( V_91 ) ) {
clock = 50000000 ;
} else {
clock = V_91 -> V_138 . V_139 ;
}
if ( clock > V_90 -> V_140 ) {
clock = V_90 -> V_140 ;
}
V_90 -> V_98 . clock = clock ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
if ( V_91 -> V_90 -> V_131 & V_141 ) {
V_88 = F_54 ( V_91 , V_142 , V_143 | V_144 ) ;
if ( V_88 ) {
F_8 ( V_119 , ( L_45 , V_88 ) ) ;
break;
}
V_90 -> V_98 . V_106 = V_145 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
}
} while ( 0 );
F_46 ( V_3 ) ;
F_8 ( V_16 , ( L_46 ) ) ;
return ( V_88 ) ? V_67 : 0 ;
}
int
F_57 ( struct V_1 * V_14 , T_7 V_146 )
{
int V_31 = 0 ;
#if F_58 ( V_147 )
struct V_2 * V_3 = V_14 -> V_3 ;
int V_148 ;
F_8 ( V_16 , ( L_47 , V_146 ) ) ;
switch ( V_146 ) {
case V_149 :
case V_150 :
V_148 = V_151 ;
V_151 = 1 ;
V_31 = F_16 ( V_14 , V_3 ) ;
V_151 = V_148 ;
if ( ! V_14 -> V_37 ) {
struct V_89 * V_90 = V_3 -> V_91 -> V_90 ;
V_90 -> V_98 . clock = 0 ;
V_90 -> V_98 . V_99 = 0 ;
V_90 -> V_98 . V_102 = V_103 ;
V_90 -> V_98 . V_100 = V_101 ;
V_90 -> V_98 . V_104 = V_152 ;
V_90 -> V_98 . V_106 = V_107 ;
V_90 -> V_98 . V_108 = V_109 ;
V_90 -> V_110 -> V_111 ( V_90 , & V_90 -> V_98 ) ;
}
break;
case V_10 :
if ( V_14 -> V_9 == V_150 ) {
V_31 = F_50 ( V_14 ) ;
}
if ( V_31 == 0 ) {
V_31 = F_14 ( V_14 , V_3 ) ;
}
break;
}
V_14 -> V_9 = V_146 ;
F_8 ( V_16 , ( L_48 ) ) ;
#endif
return V_31 ;
}
int
F_59 ( struct V_1 * V_14 , T_8 V_51 ,
void * V_146 , T_2 V_153 )
{
T_2 V_15 ;
int V_31 = 0 ;
switch( V_51 ) {
case V_154 :
( ( T_2 * ) V_146 ) [ 0 ] = V_155 ;
( ( T_2 * ) V_146 ) [ 1 ] = V_156 ;
( ( T_2 * ) V_146 ) [ 2 ] = V_157 ;
( ( T_2 * ) V_146 ) [ 3 ] = V_158 ;
break;
case V_159 :
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
( ( T_2 * ) V_146 ) [ V_15 ] = F_27 ( V_15 ) ;
}
if ( V_153 >= sizeof( struct V_160 ) ) {
F_60 ( ( T_6 ) V_14 -> V_3 -> V_14 ,
(struct V_160 * ) V_146 ) ;
}
break;
case V_161 :
* ( ( V_162 * ) V_146 ) = V_163 ;
break;
case V_164 :
if ( ! V_14 -> V_26 ) {
return V_165 ;
}
V_31 = F_61 ( V_14 , (struct V_166 * ) V_146 ) ;
if ( V_31 ) {
V_14 -> V_26 = false ;
}
break;
case V_167 :
( (struct V_168 * ) V_146 ) -> V_169 = & V_14 -> V_3 -> V_35 ;
break;
case V_170 :
V_31 = F_57 ( V_14 , * ( T_7 * ) V_146 ) ;
break;
default:
F_8 ( V_171 ,
( L_49 , V_51 ) ) ;
V_31 = V_67 ;
}
return V_31 ;
}
void
F_62 ( struct V_1 * V_14 )
{
F_8 ( V_16 , ( L_50 ) ) ;
if ( V_14 != NULL ) {
F_23 ( V_14 -> V_3 != NULL ) ;
} else {
F_8 ( V_16 , ( L_51 ) ) ;
F_63 () ;
if ( V_44 ) {
V_44 = 0 ;
F_8 ( V_16 ,
( L_52 ) ) ;
F_64 ( & V_45 ) ;
F_8 ( V_16 ,
( L_53 ) ) ;
}
}
F_8 ( V_16 , ( L_54 ) ) ;
}
static void
F_65 ( struct V_2 * V_3 )
{
int V_31 ;
struct V_1 * V_14 ;
F_8 ( V_16 , ( L_55 ) ) ;
V_14 = F_5 ( V_3 ) ;
F_66 ( & V_14 -> V_172 , 1 ) ;
F_46 ( V_14 -> V_3 ) ;
V_31 = V_14 -> V_81 . V_173 ( V_14 -> V_81 . V_50 ) ;
F_43 ( V_14 -> V_3 ) ;
F_66 ( & V_14 -> V_172 , 0 ) ;
F_23 ( V_31 == 0 || V_31 == V_174 ) ;
F_8 ( V_16 , ( L_56 ) ) ;
}
static int F_67 ( void * V_77 )
{
struct V_1 * V_14 ;
V_14 = (struct V_1 * ) V_77 ;
F_8 ( V_16 , ( L_57 ) ) ;
if ( ( V_33 . V_175 ( V_33 . V_50 , V_14 ) ) != 0 ) {
F_8 ( V_16 , ( L_58 ) ) ;
}
return 0 ;
}
static int F_68 ( void * V_77 )
{
struct V_1 * V_14 ;
V_14 = (struct V_1 * ) V_77 ;
F_8 ( V_16 , ( L_59 ) ) ;
if ( V_14 &&
V_14 -> V_32 &&
V_33 . V_176 &&
V_33 . V_176 ( V_14 -> V_32 , V_10 ) != 0 )
{
F_8 ( V_16 , ( L_58 ) ) ;
}
return 0 ;
}
void
F_69 ( struct V_1 * V_14 )
{
F_23 ( V_14 != NULL ) ;
}
void
F_70 ( struct V_1 * V_14 )
{
int V_13 ;
F_23 ( V_14 != NULL ) ;
F_23 ( V_14 -> V_3 != NULL ) ;
F_8 ( V_16 , ( L_60 ) ) ;
F_43 ( V_14 -> V_3 ) ;
V_13 = F_71 ( V_14 -> V_3 , F_65 ) ;
F_46 ( V_14 -> V_3 ) ;
F_23 ( V_13 == 0 ) ;
}
void F_72 ( struct V_1 * V_14 )
{
int V_13 ;
F_23 ( V_14 != NULL ) ;
F_23 ( V_14 -> V_3 != NULL ) ;
F_8 ( V_16 , ( L_61 ) ) ;
F_43 ( V_14 -> V_3 ) ;
while ( F_73 ( & V_14 -> V_172 ) ) {
F_46 ( V_14 -> V_3 ) ;
F_74 ( V_177 / 10 ) ;
F_43 ( V_14 -> V_3 ) ;
}
V_13 = F_75 ( V_14 -> V_3 ) ;
F_46 ( V_14 -> V_3 ) ;
F_23 ( V_13 == 0 ) ;
}
T_4 * F_38 ( struct V_1 * V_14 )
{
T_4 * V_68 ;
unsigned long V_178 ;
F_35 ( & V_14 -> V_22 , V_178 ) ;
if( ( V_68 = V_14 -> V_179 ) != NULL )
{
V_14 -> V_179 = V_68 -> V_180 ;
}
F_36 ( & V_14 -> V_22 , V_178 ) ;
F_8 ( V_16 , ( L_62 , V_68 ) ) ;
return V_68 ;
}
void
F_13 ( struct V_1 * V_14 , T_4 * V_68 )
{
unsigned long V_178 ;
F_23 ( V_68 != NULL ) ;
F_8 ( V_16 , ( L_63 , V_68 ) ) ;
F_35 ( & V_14 -> V_22 , V_178 ) ;
V_68 -> V_180 = V_14 -> V_179 ;
V_68 -> V_73 = NULL ;
V_14 -> V_179 = V_68 ;
F_36 ( & V_14 -> V_22 , V_178 ) ;
}
static int F_16 ( struct V_1 * V_14 , struct V_2 * V_3 )
{
int V_13 ;
int V_31 = 0 ;
F_8 ( V_16 , ( L_64 ) ) ;
V_14 = F_5 ( V_3 ) ;
if ( ! F_76 ( V_14 -> F_41 ) ) {
F_77 ( & V_14 -> V_83 ) ;
V_14 -> V_79 = 1 ;
F_39 ( & V_14 -> V_30 ) ;
F_78 ( & V_14 -> V_83 ) ;
V_14 -> F_41 = NULL ;
}
F_43 ( V_14 -> V_3 ) ;
V_13 = F_79 ( V_14 -> V_3 ) ;
if ( V_13 ) {
V_31 = V_67 ;
}
if ( V_151 ) {
F_8 ( V_171 , ( L_65 ) ) ;
V_13 = F_54 ( V_14 -> V_3 -> V_91 , V_181 , ( 1 << 3 ) ) ;
if ( V_13 ) {
V_31 = V_67 ;
F_8 ( V_119 , ( L_66 , V_13 ) ) ;
}
}
F_46 ( V_14 -> V_3 ) ;
if ( V_31 == 0 ) {
V_14 -> V_21 = true ;
}
F_8 ( V_16 , ( L_67 ) ) ;
return V_31 ;
}
static int F_14 ( struct V_1 * V_14 , struct V_2 * V_3 )
{
struct V_182 * V_183 ;
const char * V_184 = NULL ;
int (* F_80)( void * ) = NULL ;
int V_13 = 0 ;
F_8 ( V_16 , ( L_68 ) ) ;
V_14 = F_5 ( V_3 ) ;
if ( V_14 -> V_21 ) {
F_43 ( V_3 ) ;
if ( ( V_14 -> V_12 -> V_14 & V_185 ) >= V_186 ) {
V_13 = F_54 ( V_3 -> V_91 , V_187 , V_188 ) ;
if ( V_13 ) {
F_8 ( V_119 , ( L_69 , V_13 ) ) ;
F_46 ( V_3 ) ;
return V_13 ;
}
F_8 ( V_16 , ( L_70 ) ) ;
}
V_3 -> V_189 = 100 ;
V_13 = F_81 ( V_3 ) ;
if ( V_13 ) {
F_8 ( V_55 , ( L_71 ,
V_190 , V_13 ) ) ;
F_46 ( V_3 ) ;
return V_13 ;
}
V_13 = F_82 ( V_3 , V_58 ) ;
F_46 ( V_3 ) ;
if ( V_13 ) {
F_8 ( V_55 , ( L_72 ,
V_190 , V_58 , V_13 ) ) ;
return V_13 ;
}
V_14 -> V_21 = false ;
if ( ! V_14 -> F_41 ) {
V_14 -> V_79 = 0 ;
V_14 -> F_41 = F_83 ( F_41 ,
( void * ) V_14 ,
L_73 ) ;
if ( F_76 ( V_14 -> F_41 ) ) {
F_8 ( V_55 , ( L_74 , V_190 ) ) ;
return - V_191 ;
}
F_8 ( V_16 , ( L_75 ) ) ;
F_84 ( V_14 -> F_41 ) ;
}
}
if ( ! V_14 -> V_32 ) {
F_80 = F_67 ;
V_184 = L_76 ;
V_13 = 0 ;
#if F_58 ( V_147 )
} else {
F_80 = F_68 ;
V_184 = L_77 ;
V_13 = - V_191 ;
#endif
}
V_183 = F_83 ( F_80 , ( void * ) V_14 , V_184 ) ;
if ( F_76 ( V_183 ) ) {
F_8 ( V_55 , ( L_78 , V_190 ) ) ;
return - V_191 ;
}
F_84 ( V_183 ) ;
F_8 ( V_16 , ( L_79 ) ) ;
return V_13 ;
}
int F_85 ( struct V_1 * V_14 )
{
T_5 V_192 = 10 ;
T_3 V_193 ;
int V_31 = 0 ;
do {
while ( F_73 ( & V_14 -> V_172 ) ) {
F_74 ( V_177 / 10 ) ;
}
V_193 = 0 ;
V_31 = F_37 ( V_14 , V_194 ,
( T_3 * ) & V_193 , sizeof( V_193 ) ,
V_195 , NULL ) ;
V_193 = ! V_31 ? ( V_193 & ( 1 << 0 ) ) : 0 ;
if ( V_193 ) {
F_86 () ;
}
} while ( V_193 && -- V_192 > 0 );
if ( V_193 && V_192 == 0 ) {
F_8 ( V_55 ,
( L_80 , V_190 ) ) ;
}
return 0 ;
}
static void
F_18 ( struct V_1 * V_14 )
{
F_23 ( V_14 != NULL ) ;
F_8 ( V_16 , ( L_81 , V_14 ) ) ;
F_87 ( V_14 -> V_7 ) ;
F_87 ( V_14 ) ;
}
static void F_63 ( void )
{
}
void F_88 ( struct V_1 * V_14 , void * V_50 )
{
V_14 -> V_32 = V_50 ;
}
void F_89 ( struct V_1 * V_14 )
{
V_14 -> V_32 = NULL ;
}
int F_90 ( struct V_1 * V_14 , T_9 * V_41 )
{
if ( V_14 -> V_81 . V_50 != NULL ) {
return V_67 ;
}
V_14 -> V_81 = * V_41 ;
return 0 ;
}
void F_91 ( struct V_1 * V_14 )
{
F_11 ( & V_14 -> V_81 , sizeof( V_14 -> V_81 ) ) ;
}
static int F_54 ( struct V_92 * V_91 , unsigned int V_46 , unsigned char V_196 )
{
struct V_86 V_197 ;
unsigned long V_84 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
F_92 ( V_84 , 0 , V_46 , V_196 ) ;
V_197 . V_51 = V_198 ;
V_197 . V_84 = V_84 ;
V_197 . V_69 = V_199 | V_130 ;
return F_49 ( V_91 -> V_90 , & V_197 , 0 ) ;
}
static int F_53 ( struct V_92 * V_91 , unsigned int V_46 , unsigned char * V_196 )
{
struct V_86 V_197 ;
unsigned long V_84 ;
T_5 V_88 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
F_93 ( V_84 , 0 , V_46 ) ;
V_197 . V_51 = V_198 ;
V_197 . V_84 = V_84 ;
V_197 . V_69 = V_199 | V_130 ;
V_88 = F_49 ( V_91 -> V_90 , & V_197 , 0 ) ;
if ( ( ! V_88 ) && ( V_196 ) ) {
* V_196 = V_197 . V_85 [ 0 ] & 0xFF ;
}
return V_88 ;
}
