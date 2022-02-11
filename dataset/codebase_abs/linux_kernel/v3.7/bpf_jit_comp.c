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
void F_10 ( struct V_11 * V_12 )
{
T_1 V_13 [ 64 ] ;
T_1 * V_14 ;
unsigned int V_15 , V_16 = 0 ;
int V_17 , V_18 ;
int V_19 , V_20 ;
T_1 V_21 , V_22 , V_23 = 0 , V_24 ;
T_1 * V_25 = NULL ;
T_1 * V_26 ;
int V_27 = - 1 ;
unsigned int V_28 ;
unsigned int * V_29 ;
const struct V_30 * V_31 = V_12 -> V_32 ;
int V_33 = V_12 -> V_3 ;
if ( ! V_34 )
return;
V_29 = F_11 ( V_33 * sizeof( * V_29 ) , V_35 ) ;
if ( V_29 == NULL )
return;
for ( V_15 = 0 , V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_15 += 64 ;
V_29 [ V_18 ] = V_15 ;
}
V_28 = V_15 ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
T_1 V_36 = ( V_24 == 0 ) ? ( V_37 | V_38 | V_39 ) : V_23 ;
V_15 = 0 ;
V_14 = V_13 ;
if ( V_36 ) {
F_12 ( 0x55 , 0x48 , 0x89 , 0xe5 ) ;
F_12 ( 0x48 , 0x83 , 0xec , 96 ) ;
if ( V_36 & ( V_37 | V_38 ) )
F_12 ( 0x48 , 0x89 , 0x5d , 0xf8 ) ;
if ( V_36 & V_37 )
F_13 () ;
if ( V_36 & V_38 ) {
if ( F_14 ( struct V_40 , V_3 ) <= 127 )
F_12 ( 0x44 , 0x8b , 0x4f , F_14 ( struct V_40 , V_3 ) ) ;
else {
F_15 ( 0x44 , 0x8b , 0x8f ) ;
F_16 ( F_14 ( struct V_40 , V_3 ) , 4 ) ;
}
if ( F_3 ( F_14 ( struct V_40 , V_41 ) ) )
F_12 ( 0x44 , 0x2b , 0x4f , F_14 ( struct V_40 , V_41 ) ) ;
else {
F_15 ( 0x44 , 0x2b , 0x8f ) ;
F_16 ( F_14 ( struct V_40 , V_41 ) , 4 ) ;
}
if ( F_3 ( F_14 ( struct V_40 , V_42 ) ) )
F_12 ( 0x4c , 0x8b , 0x47 , F_14 ( struct V_40 , V_42 ) ) ;
else {
F_15 ( 0x4c , 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_42 ) , 4 ) ;
}
}
}
switch ( V_31 [ 0 ] . V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
default:
F_17 () ;
}
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
unsigned int V_55 = V_31 [ V_18 ] . V_56 ;
switch ( V_31 [ V_18 ] . V_43 ) {
case V_57 :
V_23 |= V_37 ;
F_18 ( 0x01 , 0xd8 ) ;
break;
case V_58 :
if ( ! V_55 )
break;
if ( F_3 ( V_55 ) )
F_15 ( 0x83 , 0xc0 , V_55 ) ;
else
F_19 ( 0x05 , V_55 ) ;
break;
case V_59 :
V_23 |= V_37 ;
F_18 ( 0x29 , 0xd8 ) ;
break;
case V_60 :
if ( ! V_55 )
break;
if ( F_3 ( V_55 ) )
F_15 ( 0x83 , 0xe8 , V_55 ) ;
else
F_19 ( 0x2d , V_55 ) ;
break;
case V_61 :
V_23 |= V_37 ;
F_15 ( 0x0f , 0xaf , 0xc3 ) ;
break;
case V_62 :
if ( F_3 ( V_55 ) )
F_15 ( 0x6b , 0xc0 , V_55 ) ;
else {
F_18 ( 0x69 , 0xc0 ) ;
F_16 ( V_55 , 4 ) ;
}
break;
case V_63 :
V_23 |= V_37 ;
F_18 ( 0x85 , 0xdb ) ;
if ( V_27 > 0 ) {
F_20 ( V_64 , V_29 [ V_27 - 1 ] -
( V_29 [ V_18 ] - 4 ) ) ;
} else {
F_20 ( V_65 , 2 + 5 ) ;
F_17 () ;
F_19 ( 0xe9 , V_28 - ( V_29 [ V_18 ] - 4 ) ) ;
}
F_12 ( 0x31 , 0xd2 , 0xf7 , 0xf3 ) ;
break;
case V_66 :
V_23 |= V_37 ;
F_18 ( 0x85 , 0xdb ) ;
if ( V_27 > 0 ) {
F_20 ( V_64 , V_29 [ V_27 - 1 ] -
( V_29 [ V_18 ] - 6 ) ) ;
} else {
F_20 ( V_65 , 2 + 5 ) ;
F_17 () ;
F_19 ( 0xe9 , V_28 - ( V_29 [ V_18 ] - 6 ) ) ;
}
F_18 ( 0x31 , 0xd2 ) ;
F_18 ( 0xf7 , 0xf3 ) ;
F_18 ( 0x89 , 0xd0 ) ;
break;
case V_67 :
F_18 ( 0x31 , 0xd2 ) ;
F_21 ( 0xb9 ) ; F_16 ( V_55 , 4 ) ;
F_18 ( 0xf7 , 0xf1 ) ;
F_18 ( 0x89 , 0xd0 ) ;
break;
case V_68 :
F_15 ( 0x48 , 0x69 , 0xc0 ) ;
F_16 ( V_55 , 4 ) ;
F_12 ( 0x48 , 0xc1 , 0xe8 , 0x20 ) ;
break;
case V_69 :
V_23 |= V_37 ;
F_18 ( 0x21 , 0xd8 ) ;
break;
case V_70 :
if ( V_55 >= 0xFFFFFF00 ) {
F_18 ( 0x24 , V_55 & 0xFF ) ;
} else if ( V_55 >= 0xFFFF0000 ) {
F_18 ( 0x66 , 0x25 ) ;
F_16 ( V_55 , 2 ) ;
} else {
F_19 ( 0x25 , V_55 ) ;
}
break;
case V_71 :
V_23 |= V_37 ;
F_18 ( 0x09 , 0xd8 ) ;
break;
case V_72 :
if ( F_3 ( V_55 ) )
F_15 ( 0x83 , 0xc8 , V_55 ) ;
else
F_19 ( 0x0d , V_55 ) ;
break;
case V_73 :
case V_74 :
V_23 |= V_37 ;
F_18 ( 0x31 , 0xd8 ) ;
break;
case V_75 :
if ( V_55 == 0 )
break;
if ( F_3 ( V_55 ) )
F_15 ( 0x83 , 0xf0 , V_55 ) ;
else
F_19 ( 0x35 , V_55 ) ;
break;
case V_76 :
V_23 |= V_37 ;
F_12 ( 0x89 , 0xd9 , 0xd3 , 0xe0 ) ;
break;
case V_77 :
if ( V_55 == 0 )
break;
else if ( V_55 == 1 )
F_18 ( 0xd1 , 0xe0 ) ;
else
F_15 ( 0xc1 , 0xe0 , V_55 ) ;
break;
case V_78 :
V_23 |= V_37 ;
F_12 ( 0x89 , 0xd9 , 0xd3 , 0xe8 ) ;
break;
case V_79 :
if ( V_55 == 0 )
break;
else if ( V_55 == 1 )
F_18 ( 0xd1 , 0xe8 ) ;
else
F_15 ( 0xc1 , 0xe8 , V_55 ) ;
break;
case V_80 :
F_18 ( 0xf7 , 0xd8 ) ;
break;
case V_44 :
if ( ! V_55 ) {
if ( V_27 == - 1 )
V_27 = V_18 ;
F_17 () ;
} else {
F_19 ( 0xb8 , V_55 ) ;
}
case V_81 :
if ( V_36 ) {
if ( V_18 != V_33 - 1 ) {
F_22 ( V_28 - V_29 [ V_18 ] ) ;
break;
}
if ( V_36 & V_37 )
F_12 ( 0x48 , 0x8b , 0x5d , 0xf8 ) ;
F_21 ( 0xc9 ) ;
}
F_21 ( 0xc3 ) ;
break;
case V_82 :
V_23 |= V_37 ;
F_18 ( 0x89 , 0xc3 ) ;
break;
case V_83 :
V_23 |= V_37 ;
F_18 ( 0x89 , 0xd8 ) ;
break;
case V_84 :
if ( ! V_55 )
F_17 () ;
else
F_19 ( 0xb8 , V_55 ) ;
break;
case V_85 :
V_23 |= V_37 ;
if ( ! V_55 )
F_13 () ;
else
F_19 ( 0xbb , V_55 ) ;
break;
case V_86 :
V_23 |= V_39 ;
F_15 ( 0x8b , 0x45 , 0xf0 - V_55 * 4 ) ;
break;
case V_87 :
V_23 |= V_37 | V_39 ;
F_15 ( 0x8b , 0x5d , 0xf0 - V_55 * 4 ) ;
break;
case V_88 :
V_23 |= V_39 ;
F_15 ( 0x89 , 0x45 , 0xf0 - V_55 * 4 ) ;
break;
case V_89 :
V_23 |= V_37 | V_39 ;
F_15 ( 0x89 , 0x5d , 0xf0 - V_55 * 4 ) ;
break;
case V_45 :
F_23 ( F_24 ( struct V_40 , V_3 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_40 , V_3 ) ) )
F_15 ( 0x8b , 0x47 , F_14 ( struct V_40 , V_3 ) ) ;
else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_3 ) , 4 ) ;
}
break;
case V_90 :
V_23 |= V_37 ;
if ( F_3 ( F_14 ( struct V_40 , V_3 ) ) )
F_15 ( 0x8b , 0x5f , F_14 ( struct V_40 , V_3 ) ) ;
else {
F_18 ( 0x8b , 0x9f ) ;
F_16 ( F_14 ( struct V_40 , V_3 ) , 4 ) ;
}
break;
case V_46 :
F_23 ( F_24 ( struct V_40 , V_91 ) != 2 ) ;
if ( F_3 ( F_14 ( struct V_40 , V_91 ) ) ) {
F_12 ( 0x0f , 0xb7 , 0x47 , F_14 ( struct V_40 , V_91 ) ) ;
} else {
F_15 ( 0x0f , 0xb7 , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_91 ) , 4 ) ;
}
F_18 ( 0x86 , 0xc4 ) ;
break;
case V_47 :
if ( F_3 ( F_14 ( struct V_40 , V_92 ) ) ) {
F_12 ( 0x48 , 0x8b , 0x47 , F_14 ( struct V_40 , V_92 ) ) ;
} else {
F_15 ( 0x48 , 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_92 ) , 4 ) ;
}
F_15 ( 0x48 , 0x85 , 0xc0 ) ;
F_20 ( V_64 , V_28 - ( V_29 [ V_18 ] - 6 ) ) ;
F_23 ( F_24 ( struct V_93 , V_94 ) != 4 ) ;
F_18 ( 0x8b , 0x80 ) ;
F_16 ( F_14 ( struct V_93 , V_94 ) , 4 ) ;
break;
case V_48 :
F_23 ( F_24 ( struct V_40 , V_95 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_40 , V_95 ) ) ) {
F_15 ( 0x8b , 0x47 , F_14 ( struct V_40 , V_95 ) ) ;
} else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_95 ) , 4 ) ;
}
break;
case V_49 :
F_23 ( F_24 ( struct V_40 , V_96 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_40 , V_96 ) ) ) {
F_15 ( 0x8b , 0x47 , F_14 ( struct V_40 , V_96 ) ) ;
} else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_96 ) , 4 ) ;
}
break;
case V_51 :
F_23 ( F_24 ( struct V_40 , V_97 ) != 2 ) ;
if ( F_3 ( F_14 ( struct V_40 , V_97 ) ) ) {
F_12 ( 0x0f , 0xb7 , 0x47 , F_14 ( struct V_40 , V_97 ) ) ;
} else {
F_15 ( 0x0f , 0xb7 , 0x87 ) ;
F_16 ( F_14 ( struct V_40 , V_97 ) , 4 ) ;
}
break;
case V_50 :
#ifdef F_25
F_12 ( 0x65 , 0x8b , 0x04 , 0x25 ) ;
F_16 ( ( T_2 ) ( unsigned long ) & V_98 , 4 ) ;
#else
F_17 () ;
#endif
break;
case V_52 :
V_26 = F_26 ( V_55 , V_99 ) ;
V_100: V_23 |= V_38 ;
V_19 = V_26 - ( V_25 + V_29 [ V_18 ] ) ;
F_19 ( 0xbe , V_55 ) ;
F_19 ( 0xe8 , V_19 ) ;
break;
case V_53 :
V_26 = F_26 ( V_55 , V_101 ) ;
goto V_100;
case V_54 :
V_26 = F_26 ( V_55 , V_102 ) ;
goto V_100;
case V_103 :
V_26 = F_26 ( V_55 , V_104 ) ;
V_23 |= V_38 | V_37 ;
V_19 = V_26 - ( V_25 + V_29 [ V_18 ] ) ;
F_19 ( 0xbe , V_55 ) ;
F_19 ( 0xe8 , V_19 ) ;
break;
case V_105 :
V_26 = V_99 ;
V_106: V_23 |= V_38 | V_37 ;
V_19 = V_26 - ( V_25 + V_29 [ V_18 ] ) ;
if ( V_55 ) {
if ( F_3 ( V_55 ) ) {
F_15 ( 0x8d , 0x73 , V_55 ) ;
} else {
F_18 ( 0x8d , 0xb3 ) ;
F_16 ( V_55 , 4 ) ;
}
} else {
F_18 ( 0x89 , 0xde ) ;
}
F_19 ( 0xe8 , V_19 ) ;
break;
case V_107 :
V_26 = V_101 ;
goto V_106;
case V_108 :
V_26 = V_102 ;
goto V_106;
case V_109 :
V_19 = V_29 [ V_18 + V_55 ] - V_29 [ V_18 ] ;
F_22 ( V_19 ) ;
break;
F_27 ( V_110 , V_111 , V_112 ) ;
F_27 ( V_113 , V_114 , V_115 ) ;
F_27 ( V_116 , V_64 , V_65 ) ;
F_27 ( V_117 , V_65 , V_64 ) ;
F_27 ( V_118 , V_111 , V_112 ) ;
F_27 ( V_119 , V_114 , V_115 ) ;
F_27 ( V_120 , V_64 , V_65 ) ;
F_27 ( V_121 , V_65 , V_64 ) ;
V_122: V_20 = V_29 [ V_18 + V_31 [ V_18 ] . V_123 ] - V_29 [ V_18 ] ;
V_19 = V_29 [ V_18 + V_31 [ V_18 ] . V_124 ] - V_29 [ V_18 ] ;
if ( V_31 [ V_18 ] . V_124 == V_31 [ V_18 ] . V_123 ) {
F_22 ( V_19 ) ;
break;
}
switch ( V_31 [ V_18 ] . V_43 ) {
case V_118 :
case V_119 :
case V_120 :
V_23 |= V_37 ;
F_18 ( 0x39 , 0xd8 ) ;
break;
case V_121 :
V_23 |= V_37 ;
F_18 ( 0x85 , 0xd8 ) ;
break;
case V_116 :
if ( V_55 == 0 ) {
F_18 ( 0x85 , 0xc0 ) ;
break;
}
case V_110 :
case V_113 :
if ( V_55 <= 127 )
F_15 ( 0x83 , 0xf8 , V_55 ) ;
else
F_19 ( 0x3d , V_55 ) ;
break;
case V_117 :
if ( V_55 <= 0xFF )
F_18 ( 0xa8 , V_55 ) ;
else if ( ! ( V_55 & 0xFFFF00FF ) )
F_15 ( 0xf6 , 0xc4 , V_55 >> 8 ) ;
else if ( V_55 <= 0xFFFF ) {
F_18 ( 0x66 , 0xa9 ) ;
F_16 ( V_55 , 2 ) ;
} else {
F_19 ( 0xa9 , V_55 ) ;
}
break;
}
if ( V_31 [ V_18 ] . V_124 != 0 ) {
if ( V_31 [ V_18 ] . V_123 && V_20 )
V_19 += F_4 ( V_20 ) ? 2 : 5 ;
F_20 ( V_21 , V_19 ) ;
if ( V_31 [ V_18 ] . V_123 )
F_22 ( V_20 ) ;
break;
}
F_20 ( V_22 , V_20 ) ;
break;
default:
goto V_125;
}
V_17 = V_14 - V_13 ;
if ( V_25 ) {
if ( F_28 ( V_15 + V_17 > V_16 ) ) {
F_29 ( L_1 ) ;
F_30 ( V_29 ) ;
F_31 ( NULL , V_25 ) ;
return;
}
memcpy ( V_25 + V_15 , V_13 , V_17 ) ;
}
V_15 += V_17 ;
V_29 [ V_18 ] = V_15 ;
V_14 = V_13 ;
}
V_28 = V_15 - 1 ;
if ( V_36 )
V_28 -= 1 ;
if ( V_36 & V_37 )
V_28 -= 4 ;
if ( V_25 ) {
if ( V_15 != V_16 )
F_29 ( L_2 , V_15 , V_16 ) ;
break;
}
if ( V_15 == V_16 ) {
V_25 = F_32 ( F_33 (unsigned int,
proglen,
sizeof(struct work_struct)) ) ;
if ( ! V_25 )
goto V_125;
}
V_16 = V_15 ;
}
if ( V_34 > 1 )
F_29 ( L_3 ,
V_33 , V_15 , V_24 , V_25 ) ;
if ( V_25 ) {
if ( V_34 > 1 )
F_34 ( V_126 , L_4 , V_127 ,
16 , 1 , V_25 , V_15 , false ) ;
F_5 ( V_25 , V_25 + V_15 ) ;
V_12 -> V_128 = ( void * ) V_25 ;
}
V_125:
F_30 ( V_29 ) ;
return;
}
static void F_35 ( struct V_129 * V_130 )
{
F_31 ( NULL , V_130 ) ;
}
void F_36 ( struct V_11 * V_12 )
{
if ( V_12 -> V_128 != V_131 ) {
struct V_129 * V_132 = (struct V_129 * ) V_12 -> V_128 ;
F_37 ( V_132 , F_35 ) ;
F_38 ( V_132 ) ;
}
}
