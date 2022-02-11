static inline T_1 * F_1 ( T_1 * V_1 , T_2 V_2 , unsigned int V_3 )
{
if ( V_3 == 1 )
* V_1 = V_2 ;
else if ( V_3 == 2 )
* ( V_4 * ) V_1 = V_2 ;
else {
* ( T_2 * ) V_1 = V_2 ;
F_2 () ;
}
return V_1 + V_3 ;
}
static inline bool F_3 ( int V_5 )
{
return V_5 <= 127 && V_5 >= - 128 ;
}
static inline bool F_4 ( int V_6 )
{
return V_6 <= 127 && V_6 >= - 128 ;
}
static inline void F_5 ( void * V_7 , void * V_8 )
{
T_3 V_9 = F_6 () ;
F_7 ( V_10 ) ;
F_8 () ;
F_9 ( ( unsigned long ) V_7 , ( unsigned long ) V_8 ) ;
F_7 ( V_9 ) ;
}
static int F_10 ( void )
{
struct V_11 V_12 = {
. V_13 = ~ 0 ,
} ;
char * V_14 = ( char * ) & V_12 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < sizeof( struct V_11 ) ; V_15 ++ ) {
if ( V_14 [ V_15 ] == V_16 )
return V_15 ;
}
F_11 ( L_1 ) ;
return - 1 ;
}
static struct V_17 * F_12 ( unsigned int V_18 ,
T_1 * * V_19 )
{
unsigned int V_20 , V_21 ;
struct V_17 * V_22 ;
V_20 = F_13 ( V_18 + sizeof( * V_22 ) + 128 , V_23 ) ;
V_22 = F_14 ( V_20 ) ;
if ( ! V_22 )
return NULL ;
memset ( V_22 , 0xcc , V_20 ) ;
V_22 -> V_24 = V_20 / V_23 ;
V_21 = V_20 - ( V_18 + sizeof( * V_22 ) ) ;
* V_19 = & V_22 -> V_25 [ F_15 () % V_21 ] ;
return V_22 ;
}
void F_16 ( struct V_26 * V_27 )
{
T_1 V_28 [ 64 ] ;
T_1 * V_29 ;
unsigned int V_18 , V_30 = 0 ;
int V_31 , V_32 ;
int V_33 , V_34 ;
T_1 V_35 , V_36 , V_37 = 0 , V_38 ;
T_1 * V_25 = NULL ;
struct V_17 * V_22 = NULL ;
T_1 * V_39 ;
int V_40 = - 1 ;
unsigned int V_41 ;
unsigned int * V_42 ;
const struct V_43 * V_44 = V_27 -> V_45 ;
int V_46 = V_27 -> V_3 ;
if ( ! V_47 )
return;
V_42 = F_17 ( V_46 * sizeof( * V_42 ) , V_48 ) ;
if ( V_42 == NULL )
return;
for ( V_18 = 0 , V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_18 += 64 ;
V_42 [ V_32 ] = V_18 ;
}
V_41 = V_18 ;
for ( V_38 = 0 ; V_38 < 10 ; V_38 ++ ) {
T_1 V_49 = ( V_38 == 0 ) ? ( V_50 | V_51 | V_52 ) : V_37 ;
V_18 = 0 ;
V_29 = V_28 ;
if ( V_49 ) {
F_18 ( 0x55 , 0x48 , 0x89 , 0xe5 ) ;
F_18 ( 0x48 , 0x83 , 0xec , 96 ) ;
if ( V_49 & ( V_50 | V_51 ) )
F_18 ( 0x48 , 0x89 , 0x5d , 0xf8 ) ;
if ( V_49 & V_50 )
F_19 () ;
if ( V_49 & V_51 ) {
if ( F_20 ( struct V_11 , V_3 ) <= 127 )
F_18 ( 0x44 , 0x8b , 0x4f , F_20 ( struct V_11 , V_3 ) ) ;
else {
F_21 ( 0x44 , 0x8b , 0x8f ) ;
F_22 ( F_20 ( struct V_11 , V_3 ) , 4 ) ;
}
if ( F_3 ( F_20 ( struct V_11 , V_53 ) ) )
F_18 ( 0x44 , 0x2b , 0x4f , F_20 ( struct V_11 , V_53 ) ) ;
else {
F_21 ( 0x44 , 0x2b , 0x8f ) ;
F_22 ( F_20 ( struct V_11 , V_53 ) , 4 ) ;
}
if ( F_3 ( F_20 ( struct V_11 , V_54 ) ) )
F_18 ( 0x4c , 0x8b , 0x47 , F_20 ( struct V_11 , V_54 ) ) ;
else {
F_21 ( 0x4c , 0x8b , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_54 ) , 4 ) ;
}
}
}
switch ( V_44 [ 0 ] . V_55 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
break;
default:
F_23 () ;
}
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
unsigned int V_70 = V_44 [ V_32 ] . V_71 ;
switch ( V_44 [ V_32 ] . V_55 ) {
case V_72 :
V_37 |= V_50 ;
F_24 ( 0x01 , 0xd8 ) ;
break;
case V_73 :
if ( ! V_70 )
break;
if ( F_3 ( V_70 ) )
F_21 ( 0x83 , 0xc0 , V_70 ) ;
else
F_25 ( 0x05 , V_70 ) ;
break;
case V_74 :
V_37 |= V_50 ;
F_24 ( 0x29 , 0xd8 ) ;
break;
case V_75 :
if ( ! V_70 )
break;
if ( F_3 ( V_70 ) )
F_21 ( 0x83 , 0xe8 , V_70 ) ;
else
F_25 ( 0x2d , V_70 ) ;
break;
case V_76 :
V_37 |= V_50 ;
F_21 ( 0x0f , 0xaf , 0xc3 ) ;
break;
case V_77 :
if ( F_3 ( V_70 ) )
F_21 ( 0x6b , 0xc0 , V_70 ) ;
else {
F_24 ( 0x69 , 0xc0 ) ;
F_22 ( V_70 , 4 ) ;
}
break;
case V_78 :
V_37 |= V_50 ;
F_24 ( 0x85 , 0xdb ) ;
if ( V_40 > 0 ) {
F_26 ( V_79 , V_42 [ V_40 - 1 ] -
( V_42 [ V_32 ] - 4 ) ) ;
} else {
F_26 ( V_80 , 2 + 5 ) ;
F_23 () ;
F_25 ( 0xe9 , V_41 - ( V_42 [ V_32 ] - 4 ) ) ;
}
F_18 ( 0x31 , 0xd2 , 0xf7 , 0xf3 ) ;
break;
case V_81 :
V_37 |= V_50 ;
F_24 ( 0x85 , 0xdb ) ;
if ( V_40 > 0 ) {
F_26 ( V_79 , V_42 [ V_40 - 1 ] -
( V_42 [ V_32 ] - 6 ) ) ;
} else {
F_26 ( V_80 , 2 + 5 ) ;
F_23 () ;
F_25 ( 0xe9 , V_41 - ( V_42 [ V_32 ] - 6 ) ) ;
}
F_24 ( 0x31 , 0xd2 ) ;
F_24 ( 0xf7 , 0xf3 ) ;
F_24 ( 0x89 , 0xd0 ) ;
break;
case V_82 :
F_24 ( 0x31 , 0xd2 ) ;
F_27 ( 0xb9 ) ; F_22 ( V_70 , 4 ) ;
F_24 ( 0xf7 , 0xf1 ) ;
F_24 ( 0x89 , 0xd0 ) ;
break;
case V_83 :
F_21 ( 0x48 , 0x69 , 0xc0 ) ;
F_22 ( V_70 , 4 ) ;
F_18 ( 0x48 , 0xc1 , 0xe8 , 0x20 ) ;
break;
case V_84 :
V_37 |= V_50 ;
F_24 ( 0x21 , 0xd8 ) ;
break;
case V_85 :
if ( V_70 >= 0xFFFFFF00 ) {
F_24 ( 0x24 , V_70 & 0xFF ) ;
} else if ( V_70 >= 0xFFFF0000 ) {
F_24 ( 0x66 , 0x25 ) ;
F_22 ( V_70 , 2 ) ;
} else {
F_25 ( 0x25 , V_70 ) ;
}
break;
case V_86 :
V_37 |= V_50 ;
F_24 ( 0x09 , 0xd8 ) ;
break;
case V_87 :
if ( F_3 ( V_70 ) )
F_21 ( 0x83 , 0xc8 , V_70 ) ;
else
F_25 ( 0x0d , V_70 ) ;
break;
case V_88 :
case V_89 :
V_37 |= V_50 ;
F_24 ( 0x31 , 0xd8 ) ;
break;
case V_90 :
if ( V_70 == 0 )
break;
if ( F_3 ( V_70 ) )
F_21 ( 0x83 , 0xf0 , V_70 ) ;
else
F_25 ( 0x35 , V_70 ) ;
break;
case V_91 :
V_37 |= V_50 ;
F_18 ( 0x89 , 0xd9 , 0xd3 , 0xe0 ) ;
break;
case V_92 :
if ( V_70 == 0 )
break;
else if ( V_70 == 1 )
F_24 ( 0xd1 , 0xe0 ) ;
else
F_21 ( 0xc1 , 0xe0 , V_70 ) ;
break;
case V_93 :
V_37 |= V_50 ;
F_18 ( 0x89 , 0xd9 , 0xd3 , 0xe8 ) ;
break;
case V_94 :
if ( V_70 == 0 )
break;
else if ( V_70 == 1 )
F_24 ( 0xd1 , 0xe8 ) ;
else
F_21 ( 0xc1 , 0xe8 , V_70 ) ;
break;
case V_95 :
F_24 ( 0xf7 , 0xd8 ) ;
break;
case V_56 :
if ( ! V_70 ) {
if ( V_40 == - 1 )
V_40 = V_32 ;
F_23 () ;
} else {
F_25 ( 0xb8 , V_70 ) ;
}
case V_96 :
if ( V_49 ) {
if ( V_32 != V_46 - 1 ) {
F_28 ( V_41 - V_42 [ V_32 ] ) ;
break;
}
if ( V_49 & V_50 )
F_18 ( 0x48 , 0x8b , 0x5d , 0xf8 ) ;
F_27 ( 0xc9 ) ;
}
F_27 ( 0xc3 ) ;
break;
case V_97 :
V_37 |= V_50 ;
F_24 ( 0x89 , 0xc3 ) ;
break;
case V_98 :
V_37 |= V_50 ;
F_24 ( 0x89 , 0xd8 ) ;
break;
case V_99 :
if ( ! V_70 )
F_23 () ;
else
F_25 ( 0xb8 , V_70 ) ;
break;
case V_100 :
V_37 |= V_50 ;
if ( ! V_70 )
F_19 () ;
else
F_25 ( 0xbb , V_70 ) ;
break;
case V_101 :
V_37 |= V_52 ;
F_21 ( 0x8b , 0x45 , 0xf0 - V_70 * 4 ) ;
break;
case V_102 :
V_37 |= V_50 | V_52 ;
F_21 ( 0x8b , 0x5d , 0xf0 - V_70 * 4 ) ;
break;
case V_103 :
V_37 |= V_52 ;
F_21 ( 0x89 , 0x45 , 0xf0 - V_70 * 4 ) ;
break;
case V_104 :
V_37 |= V_50 | V_52 ;
F_21 ( 0x89 , 0x5d , 0xf0 - V_70 * 4 ) ;
break;
case V_57 :
F_29 ( F_30 ( struct V_11 , V_3 ) != 4 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_3 ) ) )
F_21 ( 0x8b , 0x47 , F_20 ( struct V_11 , V_3 ) ) ;
else {
F_24 ( 0x8b , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_3 ) , 4 ) ;
}
break;
case V_105 :
V_37 |= V_50 ;
if ( F_3 ( F_20 ( struct V_11 , V_3 ) ) )
F_21 ( 0x8b , 0x5f , F_20 ( struct V_11 , V_3 ) ) ;
else {
F_24 ( 0x8b , 0x9f ) ;
F_22 ( F_20 ( struct V_11 , V_3 ) , 4 ) ;
}
break;
case V_58 :
F_29 ( F_30 ( struct V_11 , V_106 ) != 2 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_106 ) ) ) {
F_18 ( 0x0f , 0xb7 , 0x47 , F_20 ( struct V_11 , V_106 ) ) ;
} else {
F_21 ( 0x0f , 0xb7 , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_106 ) , 4 ) ;
}
F_24 ( 0x86 , 0xc4 ) ;
break;
case V_59 :
if ( F_3 ( F_20 ( struct V_11 , V_107 ) ) ) {
F_18 ( 0x48 , 0x8b , 0x47 , F_20 ( struct V_11 , V_107 ) ) ;
} else {
F_21 ( 0x48 , 0x8b , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_107 ) , 4 ) ;
}
F_21 ( 0x48 , 0x85 , 0xc0 ) ;
F_26 ( V_79 , V_41 - ( V_42 [ V_32 ] - 6 ) ) ;
F_29 ( F_30 ( struct V_108 , V_109 ) != 4 ) ;
F_24 ( 0x8b , 0x80 ) ;
F_22 ( F_20 ( struct V_108 , V_109 ) , 4 ) ;
break;
case V_60 :
F_29 ( F_30 ( struct V_11 , V_110 ) != 4 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_110 ) ) ) {
F_21 ( 0x8b , 0x47 , F_20 ( struct V_11 , V_110 ) ) ;
} else {
F_24 ( 0x8b , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_110 ) , 4 ) ;
}
break;
case V_61 :
F_29 ( F_30 ( struct V_11 , V_111 ) != 4 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_111 ) ) ) {
F_21 ( 0x8b , 0x47 , F_20 ( struct V_11 , V_111 ) ) ;
} else {
F_24 ( 0x8b , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_111 ) , 4 ) ;
}
break;
case V_65 :
F_29 ( F_30 ( struct V_11 , V_112 ) != 2 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_112 ) ) ) {
F_18 ( 0x0f , 0xb7 , 0x47 , F_20 ( struct V_11 , V_112 ) ) ;
} else {
F_21 ( 0x0f , 0xb7 , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_112 ) , 4 ) ;
}
break;
case V_62 :
#ifdef F_31
F_18 ( 0x65 , 0x8b , 0x04 , 0x25 ) ;
F_22 ( ( T_2 ) ( unsigned long ) & V_113 , 4 ) ;
#else
F_23 () ;
#endif
break;
case V_63 :
case V_64 :
F_29 ( F_30 ( struct V_11 , V_114 ) != 2 ) ;
if ( F_3 ( F_20 ( struct V_11 , V_114 ) ) ) {
F_18 ( 0x0f , 0xb7 , 0x47 , F_20 ( struct V_11 , V_114 ) ) ;
} else {
F_21 ( 0x0f , 0xb7 , 0x87 ) ;
F_22 ( F_20 ( struct V_11 , V_114 ) , 4 ) ;
}
F_29 ( V_115 != 0x1000 ) ;
if ( V_44 [ V_32 ] . V_55 == V_63 ) {
F_21 ( 0x80 , 0xe4 , 0xef ) ;
} else {
F_21 ( 0xc1 , 0xe8 , 0x0c ) ;
F_21 ( 0x83 , 0xe0 , 0x01 ) ;
}
break;
case V_66 :
{
int V_15 = F_10 () ;
if ( V_15 < 0 )
goto V_116;
if ( F_3 ( V_15 ) ) {
F_18 ( 0x0f , 0xb6 , 0x47 , V_15 ) ;
} else {
F_21 ( 0x0f , 0xb6 , 0x87 ) ;
F_22 ( V_15 , 4 ) ;
}
F_21 ( 0x83 , 0xe0 , V_16 ) ;
break;
}
case V_67 :
V_39 = F_32 ( V_70 , V_117 ) ;
V_118: V_37 |= V_51 ;
V_33 = V_39 - ( V_25 + V_42 [ V_32 ] ) ;
F_25 ( 0xbe , V_70 ) ;
F_25 ( 0xe8 , V_33 ) ;
break;
case V_68 :
V_39 = F_32 ( V_70 , V_119 ) ;
goto V_118;
case V_69 :
V_39 = F_32 ( V_70 , V_120 ) ;
goto V_118;
case V_121 :
V_39 = F_32 ( V_70 , V_122 ) ;
V_37 |= V_51 | V_50 ;
V_33 = V_39 - ( V_25 + V_42 [ V_32 ] ) ;
F_25 ( 0xbe , V_70 ) ;
F_25 ( 0xe8 , V_33 ) ;
break;
case V_123 :
V_39 = V_117 ;
V_124: V_37 |= V_51 | V_50 ;
V_33 = V_39 - ( V_25 + V_42 [ V_32 ] ) ;
if ( V_70 ) {
if ( F_3 ( V_70 ) ) {
F_21 ( 0x8d , 0x73 , V_70 ) ;
} else {
F_24 ( 0x8d , 0xb3 ) ;
F_22 ( V_70 , 4 ) ;
}
} else {
F_24 ( 0x89 , 0xde ) ;
}
F_25 ( 0xe8 , V_33 ) ;
break;
case V_125 :
V_39 = V_119 ;
goto V_124;
case V_126 :
V_39 = V_120 ;
goto V_124;
case V_127 :
V_33 = V_42 [ V_32 + V_70 ] - V_42 [ V_32 ] ;
F_28 ( V_33 ) ;
break;
F_33 ( V_128 , V_129 , V_130 ) ;
F_33 ( V_131 , V_132 , V_133 ) ;
F_33 ( V_134 , V_79 , V_80 ) ;
F_33 ( V_135 , V_80 , V_79 ) ;
F_33 ( V_136 , V_129 , V_130 ) ;
F_33 ( V_137 , V_132 , V_133 ) ;
F_33 ( V_138 , V_79 , V_80 ) ;
F_33 ( V_139 , V_80 , V_79 ) ;
V_140: V_34 = V_42 [ V_32 + V_44 [ V_32 ] . V_141 ] - V_42 [ V_32 ] ;
V_33 = V_42 [ V_32 + V_44 [ V_32 ] . V_142 ] - V_42 [ V_32 ] ;
if ( V_44 [ V_32 ] . V_142 == V_44 [ V_32 ] . V_141 ) {
F_28 ( V_33 ) ;
break;
}
switch ( V_44 [ V_32 ] . V_55 ) {
case V_136 :
case V_137 :
case V_138 :
V_37 |= V_50 ;
F_24 ( 0x39 , 0xd8 ) ;
break;
case V_139 :
V_37 |= V_50 ;
F_24 ( 0x85 , 0xd8 ) ;
break;
case V_134 :
if ( V_70 == 0 ) {
F_24 ( 0x85 , 0xc0 ) ;
break;
}
case V_128 :
case V_131 :
if ( V_70 <= 127 )
F_21 ( 0x83 , 0xf8 , V_70 ) ;
else
F_25 ( 0x3d , V_70 ) ;
break;
case V_135 :
if ( V_70 <= 0xFF )
F_24 ( 0xa8 , V_70 ) ;
else if ( ! ( V_70 & 0xFFFF00FF ) )
F_21 ( 0xf6 , 0xc4 , V_70 >> 8 ) ;
else if ( V_70 <= 0xFFFF ) {
F_24 ( 0x66 , 0xa9 ) ;
F_22 ( V_70 , 2 ) ;
} else {
F_25 ( 0xa9 , V_70 ) ;
}
break;
}
if ( V_44 [ V_32 ] . V_142 != 0 ) {
if ( V_44 [ V_32 ] . V_141 && V_34 )
V_33 += F_4 ( V_34 ) ? 2 : 5 ;
F_26 ( V_35 , V_33 ) ;
if ( V_44 [ V_32 ] . V_141 )
F_28 ( V_34 ) ;
break;
}
F_26 ( V_36 , V_34 ) ;
break;
default:
goto V_116;
}
V_31 = V_29 - V_28 ;
if ( V_25 ) {
if ( F_34 ( V_18 + V_31 > V_30 ) ) {
F_35 ( L_2 ) ;
F_36 ( V_42 ) ;
F_37 ( NULL , V_22 ) ;
return;
}
memcpy ( V_25 + V_18 , V_28 , V_31 ) ;
}
V_18 += V_31 ;
V_42 [ V_32 ] = V_18 ;
V_29 = V_28 ;
}
V_41 = V_18 - 1 ;
if ( V_49 )
V_41 -= 1 ;
if ( V_49 & V_50 )
V_41 -= 4 ;
if ( V_25 ) {
if ( V_18 != V_30 )
F_35 ( L_3 , V_18 , V_30 ) ;
break;
}
if ( V_18 == V_30 ) {
V_22 = F_12 ( V_18 , & V_25 ) ;
if ( ! V_22 )
goto V_116;
}
V_30 = V_18 ;
}
if ( V_47 > 1 )
F_38 ( V_46 , V_18 , V_38 , V_25 ) ;
if ( V_25 ) {
F_5 ( V_22 , V_25 + V_18 ) ;
F_39 ( ( unsigned long ) V_22 , V_22 -> V_24 ) ;
V_27 -> V_143 = ( void * ) V_25 ;
}
V_116:
F_36 ( V_42 ) ;
return;
}
static void F_40 ( struct V_144 * V_145 )
{
struct V_26 * V_27 = F_41 ( V_145 , struct V_26 , V_145 ) ;
unsigned long V_146 = ( unsigned long ) V_27 -> V_143 & V_147 ;
struct V_17 * V_22 = ( void * ) V_146 ;
F_42 ( V_146 , V_22 -> V_24 ) ;
F_37 ( NULL , V_22 ) ;
F_36 ( V_27 ) ;
}
void F_43 ( struct V_26 * V_27 )
{
if ( V_27 -> V_143 != V_148 ) {
F_44 ( & V_27 -> V_145 , F_40 ) ;
F_45 ( & V_27 -> V_145 ) ;
}
}
