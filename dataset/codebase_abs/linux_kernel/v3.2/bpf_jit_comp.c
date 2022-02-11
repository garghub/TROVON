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
V_15 = 0 ;
V_14 = V_13 ;
if ( V_23 ) {
F_12 ( 0x55 , 0x48 , 0x89 , 0xe5 ) ;
F_12 ( 0x48 , 0x83 , 0xec , 96 ) ;
if ( V_23 & ( V_36 | V_37 ) )
F_12 ( 0x48 , 0x89 , 0x5d , 0xf8 ) ;
if ( V_23 & V_36 )
F_13 () ;
if ( V_23 & V_37 ) {
if ( F_14 ( struct V_38 , V_3 ) <= 127 )
F_12 ( 0x44 , 0x8b , 0x4f , F_14 ( struct V_38 , V_3 ) ) ;
else {
F_15 ( 0x44 , 0x8b , 0x8f ) ;
F_16 ( F_14 ( struct V_38 , V_3 ) , 4 ) ;
}
if ( F_3 ( F_14 ( struct V_38 , V_39 ) ) )
F_12 ( 0x44 , 0x2b , 0x4f , F_14 ( struct V_38 , V_39 ) ) ;
else {
F_15 ( 0x44 , 0x2b , 0x8f ) ;
F_16 ( F_14 ( struct V_38 , V_39 ) , 4 ) ;
}
if ( F_3 ( F_14 ( struct V_38 , V_40 ) ) )
F_12 ( 0x4c , 0x8b , 0x47 , F_14 ( struct V_38 , V_40 ) ) ;
else {
F_15 ( 0x4c , 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_40 ) , 4 ) ;
}
}
}
switch ( V_31 [ 0 ] . V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
break;
default:
F_17 () ;
}
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
unsigned int V_53 = V_31 [ V_18 ] . V_54 ;
switch ( V_31 [ V_18 ] . V_41 ) {
case V_55 :
V_23 |= V_36 ;
F_18 ( 0x01 , 0xd8 ) ;
break;
case V_56 :
if ( ! V_53 )
break;
if ( F_3 ( V_53 ) )
F_15 ( 0x83 , 0xc0 , V_53 ) ;
else
F_19 ( 0x05 , V_53 ) ;
break;
case V_57 :
V_23 |= V_36 ;
F_18 ( 0x29 , 0xd8 ) ;
break;
case V_58 :
if ( ! V_53 )
break;
if ( F_3 ( V_53 ) )
F_15 ( 0x83 , 0xe8 , V_53 ) ;
else
F_19 ( 0x2d , V_53 ) ;
break;
case V_59 :
V_23 |= V_36 ;
F_15 ( 0x0f , 0xaf , 0xc3 ) ;
break;
case V_60 :
if ( F_3 ( V_53 ) )
F_15 ( 0x6b , 0xc0 , V_53 ) ;
else {
F_18 ( 0x69 , 0xc0 ) ;
F_16 ( V_53 , 4 ) ;
}
break;
case V_61 :
V_23 |= V_36 ;
F_18 ( 0x85 , 0xdb ) ;
if ( V_27 != - 1 )
F_20 ( V_62 , V_29 [ V_27 ] - ( V_29 [ V_18 ] - 4 ) ) ;
else {
F_20 ( V_63 , 2 + 5 ) ;
F_17 () ;
F_19 ( 0xe9 , V_28 - ( V_29 [ V_18 ] - 4 ) ) ;
}
F_12 ( 0x31 , 0xd2 , 0xf7 , 0xf3 ) ;
break;
case V_64 :
F_15 ( 0x48 , 0x69 , 0xc0 ) ;
F_16 ( V_53 , 4 ) ;
F_12 ( 0x48 , 0xc1 , 0xe8 , 0x20 ) ;
break;
case V_65 :
V_23 |= V_36 ;
F_18 ( 0x21 , 0xd8 ) ;
break;
case V_66 :
if ( V_53 >= 0xFFFFFF00 ) {
F_18 ( 0x24 , V_53 & 0xFF ) ;
} else if ( V_53 >= 0xFFFF0000 ) {
F_18 ( 0x66 , 0x25 ) ;
F_18 ( V_53 , 2 ) ;
} else {
F_19 ( 0x25 , V_53 ) ;
}
break;
case V_67 :
V_23 |= V_36 ;
F_18 ( 0x09 , 0xd8 ) ;
break;
case V_68 :
if ( F_3 ( V_53 ) )
F_15 ( 0x83 , 0xc8 , V_53 ) ;
else
F_19 ( 0x0d , V_53 ) ;
break;
case V_69 :
V_23 |= V_36 ;
F_12 ( 0x89 , 0xd9 , 0xd3 , 0xe0 ) ;
break;
case V_70 :
if ( V_53 == 0 )
break;
else if ( V_53 == 1 )
F_18 ( 0xd1 , 0xe0 ) ;
else
F_15 ( 0xc1 , 0xe0 , V_53 ) ;
break;
case V_71 :
V_23 |= V_36 ;
F_12 ( 0x89 , 0xd9 , 0xd3 , 0xe8 ) ;
break;
case V_72 :
if ( V_53 == 0 )
break;
else if ( V_53 == 1 )
F_18 ( 0xd1 , 0xe8 ) ;
else
F_15 ( 0xc1 , 0xe8 , V_53 ) ;
break;
case V_73 :
F_18 ( 0xf7 , 0xd8 ) ;
break;
case V_42 :
if ( ! V_53 ) {
if ( V_27 == - 1 )
V_27 = V_18 ;
F_17 () ;
} else {
F_19 ( 0xb8 , V_53 ) ;
}
case V_74 :
if ( V_23 ) {
if ( V_18 != V_33 - 1 ) {
F_21 ( V_28 - V_29 [ V_18 ] ) ;
break;
}
if ( V_23 & V_36 )
F_12 ( 0x48 , 0x8b , 0x5d , 0xf8 ) ;
F_22 ( 0xc9 ) ;
}
F_22 ( 0xc3 ) ;
break;
case V_75 :
V_23 |= V_36 ;
F_18 ( 0x89 , 0xc3 ) ;
break;
case V_76 :
V_23 |= V_36 ;
F_18 ( 0x89 , 0xd8 ) ;
break;
case V_77 :
if ( ! V_53 )
F_17 () ;
else
F_19 ( 0xb8 , V_53 ) ;
break;
case V_78 :
V_23 |= V_36 ;
if ( ! V_53 )
F_13 () ;
else
F_19 ( 0xbb , V_53 ) ;
break;
case V_79 :
V_23 |= V_80 ;
F_15 ( 0x8b , 0x45 , 0xf0 - V_53 * 4 ) ;
break;
case V_81 :
V_23 |= V_36 | V_80 ;
F_15 ( 0x8b , 0x5d , 0xf0 - V_53 * 4 ) ;
break;
case V_82 :
V_23 |= V_80 ;
F_15 ( 0x89 , 0x45 , 0xf0 - V_53 * 4 ) ;
break;
case V_83 :
V_23 |= V_36 | V_80 ;
F_15 ( 0x89 , 0x5d , 0xf0 - V_53 * 4 ) ;
break;
case V_43 :
F_23 ( F_24 ( struct V_38 , V_3 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_38 , V_3 ) ) )
F_15 ( 0x8b , 0x47 , F_14 ( struct V_38 , V_3 ) ) ;
else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_3 ) , 4 ) ;
}
break;
case V_84 :
V_23 |= V_36 ;
if ( F_3 ( F_14 ( struct V_38 , V_3 ) ) )
F_15 ( 0x8b , 0x5f , F_14 ( struct V_38 , V_3 ) ) ;
else {
F_18 ( 0x8b , 0x9f ) ;
F_16 ( F_14 ( struct V_38 , V_3 ) , 4 ) ;
}
break;
case V_44 :
F_23 ( F_24 ( struct V_38 , V_85 ) != 2 ) ;
if ( F_3 ( F_14 ( struct V_38 , V_85 ) ) ) {
F_12 ( 0x0f , 0xb7 , 0x47 , F_14 ( struct V_38 , V_85 ) ) ;
} else {
F_15 ( 0x0f , 0xb7 , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_85 ) , 4 ) ;
}
F_18 ( 0x86 , 0xc4 ) ;
break;
case V_45 :
if ( F_3 ( F_14 ( struct V_38 , V_86 ) ) ) {
F_12 ( 0x48 , 0x8b , 0x47 , F_14 ( struct V_38 , V_86 ) ) ;
} else {
F_15 ( 0x48 , 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_86 ) , 4 ) ;
}
F_15 ( 0x48 , 0x85 , 0xc0 ) ;
F_20 ( V_62 , V_28 - ( V_29 [ V_18 ] - 6 ) ) ;
F_23 ( F_24 ( struct V_87 , V_88 ) != 4 ) ;
F_18 ( 0x8b , 0x80 ) ;
F_16 ( F_14 ( struct V_87 , V_88 ) , 4 ) ;
break;
case V_46 :
F_23 ( F_24 ( struct V_38 , V_89 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_38 , V_89 ) ) ) {
F_15 ( 0x8b , 0x47 , F_14 ( struct V_38 , V_89 ) ) ;
} else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_89 ) , 4 ) ;
}
break;
case V_47 :
F_23 ( F_24 ( struct V_38 , V_90 ) != 4 ) ;
if ( F_3 ( F_14 ( struct V_38 , V_90 ) ) ) {
F_15 ( 0x8b , 0x47 , F_14 ( struct V_38 , V_90 ) ) ;
} else {
F_18 ( 0x8b , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_90 ) , 4 ) ;
}
break;
case V_49 :
F_23 ( F_24 ( struct V_38 , V_91 ) != 2 ) ;
if ( F_3 ( F_14 ( struct V_38 , V_91 ) ) ) {
F_12 ( 0x0f , 0xb7 , 0x47 , F_14 ( struct V_38 , V_91 ) ) ;
} else {
F_15 ( 0x0f , 0xb7 , 0x87 ) ;
F_16 ( F_14 ( struct V_38 , V_91 ) , 4 ) ;
}
break;
case V_48 :
#ifdef F_25
F_12 ( 0x65 , 0x8b , 0x04 , 0x25 ) ;
F_16 ( ( T_2 ) ( unsigned long ) & V_92 , 4 ) ;
#else
F_17 () ;
#endif
break;
case V_50 :
V_26 = V_93 ;
V_94: V_23 |= V_37 ;
if ( ( int ) V_53 < 0 )
goto V_95;
V_19 = V_26 - ( V_25 + V_29 [ V_18 ] ) ;
F_19 ( 0xbe , V_53 ) ;
F_19 ( 0xe8 , V_19 ) ;
break;
case V_51 :
V_26 = V_96 ;
goto V_94;
case V_52 :
V_26 = V_97 ;
goto V_94;
case V_98 :
if ( ( int ) V_53 < 0 ) {
if ( V_27 != - 1 ) {
F_21 ( V_29 [ V_27 ] - V_29 [ V_18 ] ) ;
break;
}
F_17 () ;
F_21 ( V_28 - V_29 [ V_18 ] ) ;
break;
}
V_23 |= V_37 | V_36 ;
V_19 = V_99 - ( V_25 + V_29 [ V_18 ] ) ;
F_19 ( 0xbe , V_53 ) ;
F_19 ( 0xe8 , V_19 ) ;
break;
case V_100 :
V_26 = V_101 ;
V_102: V_23 |= V_37 | V_36 ;
V_19 = V_26 - ( V_25 + V_29 [ V_18 ] ) ;
F_19 ( 0xbe , V_53 ) ;
F_19 ( 0xe8 , V_19 ) ;
break;
case V_103 :
V_26 = V_104 ;
goto V_102;
case V_105 :
V_26 = V_106 ;
goto V_102;
case V_107 :
V_19 = V_29 [ V_18 + V_53 ] - V_29 [ V_18 ] ;
F_21 ( V_19 ) ;
break;
F_26 ( V_108 , V_109 , V_110 ) ;
F_26 ( V_111 , V_112 , V_113 ) ;
F_26 ( V_114 , V_62 , V_63 ) ;
F_26 ( V_115 , V_63 , V_62 ) ;
F_26 ( V_116 , V_109 , V_110 ) ;
F_26 ( V_117 , V_112 , V_113 ) ;
F_26 ( V_118 , V_62 , V_63 ) ;
F_26 ( V_119 , V_63 , V_62 ) ;
V_120: V_20 = V_29 [ V_18 + V_31 [ V_18 ] . V_121 ] - V_29 [ V_18 ] ;
V_19 = V_29 [ V_18 + V_31 [ V_18 ] . V_122 ] - V_29 [ V_18 ] ;
if ( V_31 [ V_18 ] . V_122 == V_31 [ V_18 ] . V_121 ) {
F_21 ( V_19 ) ;
break;
}
switch ( V_31 [ V_18 ] . V_41 ) {
case V_116 :
case V_117 :
case V_118 :
V_23 |= V_36 ;
F_18 ( 0x39 , 0xd8 ) ;
break;
case V_119 :
V_23 |= V_36 ;
F_18 ( 0x85 , 0xd8 ) ;
break;
case V_114 :
if ( V_53 == 0 ) {
F_18 ( 0x85 , 0xc0 ) ;
break;
}
case V_108 :
case V_111 :
if ( V_53 <= 127 )
F_15 ( 0x83 , 0xf8 , V_53 ) ;
else
F_19 ( 0x3d , V_53 ) ;
break;
case V_115 :
if ( V_53 <= 0xFF )
F_18 ( 0xa8 , V_53 ) ;
else if ( ! ( V_53 & 0xFFFF00FF ) )
F_15 ( 0xf6 , 0xc4 , V_53 >> 8 ) ;
else if ( V_53 <= 0xFFFF ) {
F_18 ( 0x66 , 0xa9 ) ;
F_16 ( V_53 , 2 ) ;
} else {
F_19 ( 0xa9 , V_53 ) ;
}
break;
}
if ( V_31 [ V_18 ] . V_122 != 0 ) {
if ( V_31 [ V_18 ] . V_121 && V_20 )
V_19 += F_4 ( V_20 ) ? 2 : 5 ;
F_20 ( V_21 , V_19 ) ;
if ( V_31 [ V_18 ] . V_121 )
F_21 ( V_20 ) ;
break;
}
F_20 ( V_22 , V_20 ) ;
break;
default:
goto V_95;
}
V_17 = V_14 - V_13 ;
if ( V_25 ) {
if ( F_27 ( V_15 + V_17 > V_16 ) ) {
F_28 ( L_1 ) ;
F_29 ( V_29 ) ;
F_30 ( NULL , V_25 ) ;
return;
}
memcpy ( V_25 + V_15 , V_13 , V_17 ) ;
}
V_15 += V_17 ;
V_29 [ V_18 ] = V_15 ;
V_14 = V_13 ;
}
V_28 = V_15 - 1 ;
if ( V_23 )
V_28 -= 1 ;
if ( V_23 & V_36 )
V_28 -= 4 ;
if ( V_25 ) {
F_31 ( V_15 != V_16 ) ;
break;
}
if ( V_15 == V_16 ) {
V_25 = F_32 ( F_33 (unsigned int,
proglen,
sizeof(struct work_struct)) ) ;
if ( ! V_25 )
goto V_95;
}
V_16 = V_15 ;
}
if ( V_34 > 1 )
F_28 ( L_2 ,
V_33 , V_15 , V_24 , V_25 ) ;
if ( V_25 ) {
if ( V_34 > 1 )
F_34 ( V_123 , L_3 , V_124 ,
16 , 1 , V_25 , V_15 , false ) ;
F_5 ( V_25 , V_25 + V_15 ) ;
V_12 -> V_125 = ( void * ) V_25 ;
}
V_95:
F_29 ( V_29 ) ;
return;
}
static void F_35 ( struct V_126 * V_127 )
{
F_30 ( NULL , V_127 ) ;
}
void F_36 ( struct V_11 * V_12 )
{
if ( V_12 -> V_125 != V_128 ) {
struct V_126 * V_129 = (struct V_126 * ) V_12 -> V_125 ;
F_37 ( V_129 , F_35 ) ;
F_38 ( V_129 ) ;
}
}
