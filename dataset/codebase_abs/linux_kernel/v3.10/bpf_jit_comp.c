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
void F_12 ( struct V_17 * V_18 )
{
T_1 V_19 [ 64 ] ;
T_1 * V_20 ;
unsigned int V_21 , V_22 = 0 ;
int V_23 , V_24 ;
int V_25 , V_26 ;
T_1 V_27 , V_28 , V_29 = 0 , V_30 ;
T_1 * V_31 = NULL ;
T_1 * V_32 ;
int V_33 = - 1 ;
unsigned int V_34 ;
unsigned int * V_35 ;
const struct V_36 * V_37 = V_18 -> V_38 ;
int V_39 = V_18 -> V_3 ;
if ( ! V_40 )
return;
V_35 = F_13 ( V_39 * sizeof( * V_35 ) , V_41 ) ;
if ( V_35 == NULL )
return;
for ( V_21 = 0 , V_24 = 0 ; V_24 < V_39 ; V_24 ++ ) {
V_21 += 64 ;
V_35 [ V_24 ] = V_21 ;
}
V_34 = V_21 ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
T_1 V_42 = ( V_30 == 0 ) ? ( V_43 | V_44 | V_45 ) : V_29 ;
V_21 = 0 ;
V_20 = V_19 ;
if ( V_42 ) {
F_14 ( 0x55 , 0x48 , 0x89 , 0xe5 ) ;
F_14 ( 0x48 , 0x83 , 0xec , 96 ) ;
if ( V_42 & ( V_43 | V_44 ) )
F_14 ( 0x48 , 0x89 , 0x5d , 0xf8 ) ;
if ( V_42 & V_43 )
F_15 () ;
if ( V_42 & V_44 ) {
if ( F_16 ( struct V_11 , V_3 ) <= 127 )
F_14 ( 0x44 , 0x8b , 0x4f , F_16 ( struct V_11 , V_3 ) ) ;
else {
F_17 ( 0x44 , 0x8b , 0x8f ) ;
F_18 ( F_16 ( struct V_11 , V_3 ) , 4 ) ;
}
if ( F_3 ( F_16 ( struct V_11 , V_46 ) ) )
F_14 ( 0x44 , 0x2b , 0x4f , F_16 ( struct V_11 , V_46 ) ) ;
else {
F_17 ( 0x44 , 0x2b , 0x8f ) ;
F_18 ( F_16 ( struct V_11 , V_46 ) , 4 ) ;
}
if ( F_3 ( F_16 ( struct V_11 , V_47 ) ) )
F_14 ( 0x4c , 0x8b , 0x47 , F_16 ( struct V_11 , V_47 ) ) ;
else {
F_17 ( 0x4c , 0x8b , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_47 ) , 4 ) ;
}
}
}
switch ( V_37 [ 0 ] . V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
break;
default:
F_19 () ;
}
for ( V_24 = 0 ; V_24 < V_39 ; V_24 ++ ) {
unsigned int V_63 = V_37 [ V_24 ] . V_64 ;
switch ( V_37 [ V_24 ] . V_48 ) {
case V_65 :
V_29 |= V_43 ;
F_20 ( 0x01 , 0xd8 ) ;
break;
case V_66 :
if ( ! V_63 )
break;
if ( F_3 ( V_63 ) )
F_17 ( 0x83 , 0xc0 , V_63 ) ;
else
F_21 ( 0x05 , V_63 ) ;
break;
case V_67 :
V_29 |= V_43 ;
F_20 ( 0x29 , 0xd8 ) ;
break;
case V_68 :
if ( ! V_63 )
break;
if ( F_3 ( V_63 ) )
F_17 ( 0x83 , 0xe8 , V_63 ) ;
else
F_21 ( 0x2d , V_63 ) ;
break;
case V_69 :
V_29 |= V_43 ;
F_17 ( 0x0f , 0xaf , 0xc3 ) ;
break;
case V_70 :
if ( F_3 ( V_63 ) )
F_17 ( 0x6b , 0xc0 , V_63 ) ;
else {
F_20 ( 0x69 , 0xc0 ) ;
F_18 ( V_63 , 4 ) ;
}
break;
case V_71 :
V_29 |= V_43 ;
F_20 ( 0x85 , 0xdb ) ;
if ( V_33 > 0 ) {
F_22 ( V_72 , V_35 [ V_33 - 1 ] -
( V_35 [ V_24 ] - 4 ) ) ;
} else {
F_22 ( V_73 , 2 + 5 ) ;
F_19 () ;
F_21 ( 0xe9 , V_34 - ( V_35 [ V_24 ] - 4 ) ) ;
}
F_14 ( 0x31 , 0xd2 , 0xf7 , 0xf3 ) ;
break;
case V_74 :
V_29 |= V_43 ;
F_20 ( 0x85 , 0xdb ) ;
if ( V_33 > 0 ) {
F_22 ( V_72 , V_35 [ V_33 - 1 ] -
( V_35 [ V_24 ] - 6 ) ) ;
} else {
F_22 ( V_73 , 2 + 5 ) ;
F_19 () ;
F_21 ( 0xe9 , V_34 - ( V_35 [ V_24 ] - 6 ) ) ;
}
F_20 ( 0x31 , 0xd2 ) ;
F_20 ( 0xf7 , 0xf3 ) ;
F_20 ( 0x89 , 0xd0 ) ;
break;
case V_75 :
F_20 ( 0x31 , 0xd2 ) ;
F_23 ( 0xb9 ) ; F_18 ( V_63 , 4 ) ;
F_20 ( 0xf7 , 0xf1 ) ;
F_20 ( 0x89 , 0xd0 ) ;
break;
case V_76 :
F_17 ( 0x48 , 0x69 , 0xc0 ) ;
F_18 ( V_63 , 4 ) ;
F_14 ( 0x48 , 0xc1 , 0xe8 , 0x20 ) ;
break;
case V_77 :
V_29 |= V_43 ;
F_20 ( 0x21 , 0xd8 ) ;
break;
case V_78 :
if ( V_63 >= 0xFFFFFF00 ) {
F_20 ( 0x24 , V_63 & 0xFF ) ;
} else if ( V_63 >= 0xFFFF0000 ) {
F_20 ( 0x66 , 0x25 ) ;
F_18 ( V_63 , 2 ) ;
} else {
F_21 ( 0x25 , V_63 ) ;
}
break;
case V_79 :
V_29 |= V_43 ;
F_20 ( 0x09 , 0xd8 ) ;
break;
case V_80 :
if ( F_3 ( V_63 ) )
F_17 ( 0x83 , 0xc8 , V_63 ) ;
else
F_21 ( 0x0d , V_63 ) ;
break;
case V_81 :
case V_82 :
V_29 |= V_43 ;
F_20 ( 0x31 , 0xd8 ) ;
break;
case V_83 :
if ( V_63 == 0 )
break;
if ( F_3 ( V_63 ) )
F_17 ( 0x83 , 0xf0 , V_63 ) ;
else
F_21 ( 0x35 , V_63 ) ;
break;
case V_84 :
V_29 |= V_43 ;
F_14 ( 0x89 , 0xd9 , 0xd3 , 0xe0 ) ;
break;
case V_85 :
if ( V_63 == 0 )
break;
else if ( V_63 == 1 )
F_20 ( 0xd1 , 0xe0 ) ;
else
F_17 ( 0xc1 , 0xe0 , V_63 ) ;
break;
case V_86 :
V_29 |= V_43 ;
F_14 ( 0x89 , 0xd9 , 0xd3 , 0xe8 ) ;
break;
case V_87 :
if ( V_63 == 0 )
break;
else if ( V_63 == 1 )
F_20 ( 0xd1 , 0xe8 ) ;
else
F_17 ( 0xc1 , 0xe8 , V_63 ) ;
break;
case V_88 :
F_20 ( 0xf7 , 0xd8 ) ;
break;
case V_49 :
if ( ! V_63 ) {
if ( V_33 == - 1 )
V_33 = V_24 ;
F_19 () ;
} else {
F_21 ( 0xb8 , V_63 ) ;
}
case V_89 :
if ( V_42 ) {
if ( V_24 != V_39 - 1 ) {
F_24 ( V_34 - V_35 [ V_24 ] ) ;
break;
}
if ( V_42 & V_43 )
F_14 ( 0x48 , 0x8b , 0x5d , 0xf8 ) ;
F_23 ( 0xc9 ) ;
}
F_23 ( 0xc3 ) ;
break;
case V_90 :
V_29 |= V_43 ;
F_20 ( 0x89 , 0xc3 ) ;
break;
case V_91 :
V_29 |= V_43 ;
F_20 ( 0x89 , 0xd8 ) ;
break;
case V_92 :
if ( ! V_63 )
F_19 () ;
else
F_21 ( 0xb8 , V_63 ) ;
break;
case V_93 :
V_29 |= V_43 ;
if ( ! V_63 )
F_15 () ;
else
F_21 ( 0xbb , V_63 ) ;
break;
case V_94 :
V_29 |= V_45 ;
F_17 ( 0x8b , 0x45 , 0xf0 - V_63 * 4 ) ;
break;
case V_95 :
V_29 |= V_43 | V_45 ;
F_17 ( 0x8b , 0x5d , 0xf0 - V_63 * 4 ) ;
break;
case V_96 :
V_29 |= V_45 ;
F_17 ( 0x89 , 0x45 , 0xf0 - V_63 * 4 ) ;
break;
case V_97 :
V_29 |= V_43 | V_45 ;
F_17 ( 0x89 , 0x5d , 0xf0 - V_63 * 4 ) ;
break;
case V_50 :
F_25 ( F_26 ( struct V_11 , V_3 ) != 4 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_3 ) ) )
F_17 ( 0x8b , 0x47 , F_16 ( struct V_11 , V_3 ) ) ;
else {
F_20 ( 0x8b , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_3 ) , 4 ) ;
}
break;
case V_98 :
V_29 |= V_43 ;
if ( F_3 ( F_16 ( struct V_11 , V_3 ) ) )
F_17 ( 0x8b , 0x5f , F_16 ( struct V_11 , V_3 ) ) ;
else {
F_20 ( 0x8b , 0x9f ) ;
F_18 ( F_16 ( struct V_11 , V_3 ) , 4 ) ;
}
break;
case V_51 :
F_25 ( F_26 ( struct V_11 , V_99 ) != 2 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_99 ) ) ) {
F_14 ( 0x0f , 0xb7 , 0x47 , F_16 ( struct V_11 , V_99 ) ) ;
} else {
F_17 ( 0x0f , 0xb7 , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_99 ) , 4 ) ;
}
F_20 ( 0x86 , 0xc4 ) ;
break;
case V_52 :
if ( F_3 ( F_16 ( struct V_11 , V_100 ) ) ) {
F_14 ( 0x48 , 0x8b , 0x47 , F_16 ( struct V_11 , V_100 ) ) ;
} else {
F_17 ( 0x48 , 0x8b , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_100 ) , 4 ) ;
}
F_17 ( 0x48 , 0x85 , 0xc0 ) ;
F_22 ( V_72 , V_34 - ( V_35 [ V_24 ] - 6 ) ) ;
F_25 ( F_26 ( struct V_101 , V_102 ) != 4 ) ;
F_20 ( 0x8b , 0x80 ) ;
F_18 ( F_16 ( struct V_101 , V_102 ) , 4 ) ;
break;
case V_53 :
F_25 ( F_26 ( struct V_11 , V_103 ) != 4 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_103 ) ) ) {
F_17 ( 0x8b , 0x47 , F_16 ( struct V_11 , V_103 ) ) ;
} else {
F_20 ( 0x8b , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_103 ) , 4 ) ;
}
break;
case V_54 :
F_25 ( F_26 ( struct V_11 , V_104 ) != 4 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_104 ) ) ) {
F_17 ( 0x8b , 0x47 , F_16 ( struct V_11 , V_104 ) ) ;
} else {
F_20 ( 0x8b , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_104 ) , 4 ) ;
}
break;
case V_58 :
F_25 ( F_26 ( struct V_11 , V_105 ) != 2 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_105 ) ) ) {
F_14 ( 0x0f , 0xb7 , 0x47 , F_16 ( struct V_11 , V_105 ) ) ;
} else {
F_17 ( 0x0f , 0xb7 , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_105 ) , 4 ) ;
}
break;
case V_55 :
#ifdef F_27
F_14 ( 0x65 , 0x8b , 0x04 , 0x25 ) ;
F_18 ( ( T_2 ) ( unsigned long ) & V_106 , 4 ) ;
#else
F_19 () ;
#endif
break;
case V_56 :
case V_57 :
F_25 ( F_26 ( struct V_11 , V_107 ) != 2 ) ;
if ( F_3 ( F_16 ( struct V_11 , V_107 ) ) ) {
F_14 ( 0x0f , 0xb7 , 0x47 , F_16 ( struct V_11 , V_107 ) ) ;
} else {
F_17 ( 0x0f , 0xb7 , 0x87 ) ;
F_18 ( F_16 ( struct V_11 , V_107 ) , 4 ) ;
}
F_25 ( V_108 != 0x1000 ) ;
if ( V_37 [ V_24 ] . V_48 == V_56 ) {
F_17 ( 0x80 , 0xe4 , 0xef ) ;
} else {
F_17 ( 0xc1 , 0xe8 , 0x0c ) ;
F_17 ( 0x83 , 0xe0 , 0x01 ) ;
}
break;
case V_59 :
{
int V_15 = F_10 () ;
if ( V_15 < 0 )
goto V_109;
if ( F_3 ( V_15 ) ) {
F_14 ( 0x0f , 0xb6 , 0x47 , V_15 ) ;
} else {
F_17 ( 0x0f , 0xb6 , 0x87 ) ;
F_18 ( V_15 , 4 ) ;
}
F_17 ( 0x83 , 0xe0 , V_16 ) ;
break;
}
case V_60 :
V_32 = F_28 ( V_63 , V_110 ) ;
V_111: V_29 |= V_44 ;
V_25 = V_32 - ( V_31 + V_35 [ V_24 ] ) ;
F_21 ( 0xbe , V_63 ) ;
F_21 ( 0xe8 , V_25 ) ;
break;
case V_61 :
V_32 = F_28 ( V_63 , V_112 ) ;
goto V_111;
case V_62 :
V_32 = F_28 ( V_63 , V_113 ) ;
goto V_111;
case V_114 :
V_32 = F_28 ( V_63 , V_115 ) ;
V_29 |= V_44 | V_43 ;
V_25 = V_32 - ( V_31 + V_35 [ V_24 ] ) ;
F_21 ( 0xbe , V_63 ) ;
F_21 ( 0xe8 , V_25 ) ;
break;
case V_116 :
V_32 = V_110 ;
V_117: V_29 |= V_44 | V_43 ;
V_25 = V_32 - ( V_31 + V_35 [ V_24 ] ) ;
if ( V_63 ) {
if ( F_3 ( V_63 ) ) {
F_17 ( 0x8d , 0x73 , V_63 ) ;
} else {
F_20 ( 0x8d , 0xb3 ) ;
F_18 ( V_63 , 4 ) ;
}
} else {
F_20 ( 0x89 , 0xde ) ;
}
F_21 ( 0xe8 , V_25 ) ;
break;
case V_118 :
V_32 = V_112 ;
goto V_117;
case V_119 :
V_32 = V_113 ;
goto V_117;
case V_120 :
V_25 = V_35 [ V_24 + V_63 ] - V_35 [ V_24 ] ;
F_24 ( V_25 ) ;
break;
F_29 ( V_121 , V_122 , V_123 ) ;
F_29 ( V_124 , V_125 , V_126 ) ;
F_29 ( V_127 , V_72 , V_73 ) ;
F_29 ( V_128 , V_73 , V_72 ) ;
F_29 ( V_129 , V_122 , V_123 ) ;
F_29 ( V_130 , V_125 , V_126 ) ;
F_29 ( V_131 , V_72 , V_73 ) ;
F_29 ( V_132 , V_73 , V_72 ) ;
V_133: V_26 = V_35 [ V_24 + V_37 [ V_24 ] . V_134 ] - V_35 [ V_24 ] ;
V_25 = V_35 [ V_24 + V_37 [ V_24 ] . V_135 ] - V_35 [ V_24 ] ;
if ( V_37 [ V_24 ] . V_135 == V_37 [ V_24 ] . V_134 ) {
F_24 ( V_25 ) ;
break;
}
switch ( V_37 [ V_24 ] . V_48 ) {
case V_129 :
case V_130 :
case V_131 :
V_29 |= V_43 ;
F_20 ( 0x39 , 0xd8 ) ;
break;
case V_132 :
V_29 |= V_43 ;
F_20 ( 0x85 , 0xd8 ) ;
break;
case V_127 :
if ( V_63 == 0 ) {
F_20 ( 0x85 , 0xc0 ) ;
break;
}
case V_121 :
case V_124 :
if ( V_63 <= 127 )
F_17 ( 0x83 , 0xf8 , V_63 ) ;
else
F_21 ( 0x3d , V_63 ) ;
break;
case V_128 :
if ( V_63 <= 0xFF )
F_20 ( 0xa8 , V_63 ) ;
else if ( ! ( V_63 & 0xFFFF00FF ) )
F_17 ( 0xf6 , 0xc4 , V_63 >> 8 ) ;
else if ( V_63 <= 0xFFFF ) {
F_20 ( 0x66 , 0xa9 ) ;
F_18 ( V_63 , 2 ) ;
} else {
F_21 ( 0xa9 , V_63 ) ;
}
break;
}
if ( V_37 [ V_24 ] . V_135 != 0 ) {
if ( V_37 [ V_24 ] . V_134 && V_26 )
V_25 += F_4 ( V_26 ) ? 2 : 5 ;
F_22 ( V_27 , V_25 ) ;
if ( V_37 [ V_24 ] . V_134 )
F_24 ( V_26 ) ;
break;
}
F_22 ( V_28 , V_26 ) ;
break;
default:
goto V_109;
}
V_23 = V_20 - V_19 ;
if ( V_31 ) {
if ( F_30 ( V_21 + V_23 > V_22 ) ) {
F_31 ( L_2 ) ;
F_32 ( V_35 ) ;
F_33 ( NULL , V_31 ) ;
return;
}
memcpy ( V_31 + V_21 , V_19 , V_23 ) ;
}
V_21 += V_23 ;
V_35 [ V_24 ] = V_21 ;
V_20 = V_19 ;
}
V_34 = V_21 - 1 ;
if ( V_42 )
V_34 -= 1 ;
if ( V_42 & V_43 )
V_34 -= 4 ;
if ( V_31 ) {
if ( V_21 != V_22 )
F_31 ( L_3 , V_21 , V_22 ) ;
break;
}
if ( V_21 == V_22 ) {
V_31 = F_34 ( F_35 (unsigned int,
proglen,
sizeof(struct work_struct)) ) ;
if ( ! V_31 )
goto V_109;
}
V_22 = V_21 ;
}
if ( V_40 > 1 )
F_36 ( V_39 , V_21 , V_30 , V_31 ) ;
if ( V_31 ) {
F_5 ( V_31 , V_31 + V_21 ) ;
V_18 -> V_136 = ( void * ) V_31 ;
}
V_109:
F_32 ( V_35 ) ;
return;
}
static void F_37 ( struct V_137 * V_138 )
{
F_33 ( NULL , V_138 ) ;
}
void F_38 ( struct V_17 * V_18 )
{
if ( V_18 -> V_136 != V_139 ) {
struct V_137 * V_140 = (struct V_137 * ) V_18 -> V_136 ;
F_39 ( V_140 , F_37 ) ;
F_40 ( V_140 ) ;
}
}
