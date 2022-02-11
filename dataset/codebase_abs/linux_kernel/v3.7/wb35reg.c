unsigned char F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 V_5 , T_3 V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
T_1 V_12 ;
struct V_13 * V_14 ;
T_1 V_15 , V_16 = V_5 * 4 ;
if ( V_2 -> V_17 )
return false ;
V_12 = sizeof( struct V_10 ) + V_16 + sizeof( struct V_13 ) ;
V_11 = F_2 ( V_12 , V_18 ) ;
V_9 = F_3 ( 0 , V_18 ) ;
if ( V_9 && V_11 ) {
V_11 -> V_19 = 2 ;
V_11 -> V_20 = V_3 ;
V_11 -> V_21 = ( T_2 * ) ( ( T_3 * ) V_11 + sizeof( struct V_10 ) ) ;
memcpy ( V_11 -> V_21 , V_4 , V_16 ) ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ )
V_11 -> V_21 [ V_15 ] = F_4 ( V_11 -> V_21 [ V_15 ] ) ;
V_14 = (struct V_13 * ) ( ( T_3 * ) V_11 + sizeof( struct V_10 ) + V_16 ) ;
V_14 -> V_22 = V_23 | V_24 | V_25 ;
V_14 -> V_26 = 0x04 ;
V_14 -> V_27 = F_5 ( V_6 ) ;
V_14 -> V_28 = F_5 ( V_3 ) ;
V_14 -> V_29 = F_5 ( V_16 ) ;
V_11 -> V_30 = NULL ;
V_11 -> V_31 = V_14 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_8 -> V_32 ) ;
if ( V_8 -> V_33 == NULL )
V_8 -> V_33 = V_11 ;
else
V_8 -> V_34 -> V_30 = V_11 ;
V_8 -> V_34 = V_11 ;
F_7 ( & V_8 -> V_32 ) ;
F_8 ( V_2 ) ;
return true ;
} else {
if ( V_9 )
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
return false ;
}
return false ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_35 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
switch ( V_3 ) {
case 0x3b0 : V_8 -> V_36 = V_35 ; break;
case 0x3bc : V_8 -> V_37 = V_35 ; break;
case 0x400 : V_8 -> V_38 = V_35 ; break;
case 0x800 : V_8 -> V_39 = V_35 ; break;
case 0x804 : V_8 -> V_40 = V_35 ; break;
case 0x808 : V_8 -> V_41 = V_35 ; break;
case 0x824 : V_8 -> V_42 = V_35 ; break;
case 0x828 : V_8 -> V_43 = V_35 ; break;
case 0x82c : V_8 -> V_44 = V_35 ; break;
case 0x838 : V_8 -> V_45 = V_35 ; break;
case 0x840 : V_8 -> V_46 = V_35 ; break;
case 0x844 : V_8 -> V_47 = V_35 ; break;
case 0x848 : V_8 -> V_48 = V_35 ; break;
case 0x84c : V_8 -> V_49 = V_35 ; break;
case 0x860 : V_8 -> V_50 = V_35 ; break;
case 0x868 : V_8 -> V_51 = V_35 ; break;
case 0x870 : V_8 -> V_52 = V_35 ; break;
case 0x874 : V_8 -> V_53 = V_35 ; break;
case 0x878 : V_8 -> V_54 = V_35 ; break;
case 0x87C : V_8 -> V_55 = V_35 ; break;
case 0x880 : V_8 -> V_56 = V_35 ; break;
case 0x884 : V_8 -> V_57 = V_35 ; break;
case 0x888 : V_8 -> V_58 = V_35 ; break;
case 0x898 : V_8 -> V_59 = V_35 ; break;
case 0x100c : V_8 -> V_60 = V_35 ; break;
case 0x102c : V_8 -> V_61 = V_35 ; break;
case 0x1030 : V_8 -> V_62 = V_35 ; break;
case 0x103c : V_8 -> V_63 = V_35 ; break;
case 0x1048 : V_8 -> V_64 = V_35 ; break;
case 0x104c : V_8 -> V_65 = V_35 ; break;
case 0x1050 : V_8 -> V_66 = V_35 ; break;
case 0x1054 : V_8 -> V_67 = V_35 ; break;
case 0x1058 : V_8 -> V_68 = V_35 ; break;
case 0x105c : V_8 -> V_69 = V_35 ; break;
case 0x1060 : V_8 -> V_70 = V_35 ; break;
}
}
unsigned char F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_35 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_71 = - 1 ;
if ( V_2 -> V_17 )
return false ;
V_35 = F_4 ( V_35 ) ;
V_8 -> V_72 = 1 ;
while ( V_8 -> V_73 != V_74 )
F_13 ( 10 ) ;
V_8 -> V_73 = V_75 ;
V_71 = F_14 ( V_2 -> V_76 ,
F_15 ( V_2 -> V_76 , 0 ) ,
0x03 , V_23 | V_25 | V_24 ,
0x0 , V_3 , & V_35 , 4 , V_77 * 100 ) ;
V_8 -> V_73 = V_74 ;
V_8 -> V_72 = 0 ;
F_8 ( V_2 ) ;
if ( V_71 < 0 ) {
F_16 ( L_1 ) ;
V_2 -> V_17 = 1 ;
return false ;
}
return true ;
}
unsigned char F_17 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_35 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_13 * V_14 ;
struct V_9 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
T_1 V_12 ;
if ( V_2 -> V_17 )
return false ;
V_12 = sizeof( struct V_10 ) + sizeof( struct V_13 ) ;
V_11 = F_2 ( V_12 , V_18 ) ;
V_9 = F_3 ( 0 , V_18 ) ;
if ( V_9 && V_11 ) {
V_11 -> V_19 = 1 ;
V_11 -> V_20 = V_3 ;
V_11 -> V_78 = F_4 ( V_35 ) ;
V_11 -> V_79 = false ;
V_14 = (struct V_13 * ) ( ( T_3 * ) V_11 + sizeof( struct V_10 ) ) ;
V_14 -> V_22 = V_23 | V_24 | V_25 ;
V_14 -> V_26 = 0x03 ;
V_14 -> V_27 = F_5 ( 0x0 ) ;
V_14 -> V_28 = F_5 ( V_3 ) ;
V_14 -> V_29 = F_5 ( 4 ) ;
V_11 -> V_30 = NULL ;
V_11 -> V_31 = V_14 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_8 -> V_32 ) ;
if ( V_8 -> V_33 == NULL )
V_8 -> V_33 = V_11 ;
else
V_8 -> V_34 -> V_30 = V_11 ;
V_8 -> V_34 = V_11 ;
F_7 ( & V_8 -> V_32 ) ;
F_8 ( V_2 ) ;
return true ;
} else {
if ( V_9 )
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
return false ;
}
}
unsigned char F_18 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_35 ,
T_4 * V_80 ,
T_4 V_81 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_13 * V_14 ;
struct V_9 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
T_1 V_12 ;
if ( V_2 -> V_17 )
return false ;
V_12 = sizeof( struct V_10 ) + sizeof( struct V_13 ) ;
V_11 = F_2 ( V_12 , V_18 ) ;
V_9 = F_3 ( 0 , V_18 ) ;
if ( V_9 && V_11 ) {
V_11 -> V_19 = 1 ;
V_11 -> V_20 = V_3 ;
V_11 -> V_78 = F_4 ( V_35 ) ;
memcpy ( V_11 -> V_82 , V_80 , V_81 ) ;
V_11 -> V_79 = true ;
V_14 = (struct V_13 * ) ( ( T_3 * ) V_11 + sizeof( struct V_10 ) ) ;
V_14 -> V_22 = V_23 | V_24 | V_25 ;
V_14 -> V_26 = 0x03 ;
V_14 -> V_27 = F_5 ( 0x0 ) ;
V_14 -> V_28 = F_5 ( V_3 ) ;
V_14 -> V_29 = F_5 ( 4 ) ;
V_11 -> V_30 = NULL ;
V_11 -> V_31 = V_14 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_8 -> V_32 ) ;
if ( V_8 -> V_33 == NULL )
V_8 -> V_33 = V_11 ;
else
V_8 -> V_34 -> V_30 = V_11 ;
V_8 -> V_34 = V_11 ;
F_7 ( & V_8 -> V_32 ) ;
F_8 ( V_2 ) ;
return true ;
} else {
if ( V_9 )
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
return false ;
}
}
unsigned char F_19 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_83 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 * V_84 = V_83 ;
int V_71 = - 1 ;
if ( V_2 -> V_17 )
return false ;
V_8 -> V_72 = 1 ;
while ( V_8 -> V_73 != V_74 )
F_13 ( 10 ) ;
V_8 -> V_73 = V_75 ;
V_71 = F_14 ( V_2 -> V_76 ,
F_20 ( V_2 -> V_76 , 0 ) ,
0x01 , V_23 | V_25 | V_85 ,
0x0 , V_3 , V_84 , 4 , V_77 * 100 ) ;
* V_83 = F_4 ( * V_84 ) ;
V_8 -> V_73 = V_74 ;
F_11 ( V_2 , V_3 , * V_83 ) ;
V_8 -> V_72 = 0 ;
F_8 ( V_2 ) ;
if ( V_71 < 0 ) {
F_16 ( L_2 ) ;
V_2 -> V_17 = 1 ;
return false ;
}
return true ;
}
unsigned char F_21 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_83 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_13 * V_14 ;
struct V_9 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
if ( V_2 -> V_17 )
return false ;
V_12 = sizeof( struct V_10 ) + sizeof( struct V_13 ) ;
V_11 = F_2 ( V_12 , V_18 ) ;
V_9 = F_3 ( 0 , V_18 ) ;
if ( V_9 && V_11 ) {
V_11 -> V_19 = 0 ;
V_11 -> V_20 = V_3 ;
V_11 -> V_21 = V_83 ;
V_14 = (struct V_13 * ) ( ( T_3 * ) V_11 + sizeof( struct V_10 ) ) ;
V_14 -> V_22 = V_23 | V_25 | V_85 ;
V_14 -> V_26 = 0x01 ;
V_14 -> V_27 = F_5 ( 0x0 ) ;
V_14 -> V_28 = F_5 ( V_3 ) ;
V_14 -> V_29 = F_5 ( 4 ) ;
V_11 -> V_30 = NULL ;
V_11 -> V_31 = V_14 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_8 -> V_32 ) ;
if ( V_8 -> V_33 == NULL )
V_8 -> V_33 = V_11 ;
else
V_8 -> V_34 -> V_30 = V_11 ;
V_8 -> V_34 = V_11 ;
F_7 ( & V_8 -> V_32 ) ;
F_8 ( V_2 ) ;
return true ;
} else {
if ( V_9 )
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
return false ;
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
if ( F_22 ( & V_8 -> V_86 ) == 1 ) {
V_8 -> V_73 = V_75 ;
F_23 ( V_2 ) ;
} else
F_24 ( & V_8 -> V_86 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_9 ;
struct V_13 * V_14 ;
T_2 * V_21 ;
int V_71 = - 1 ;
struct V_10 * V_11 ;
if ( V_8 -> V_72 )
goto V_87;
if ( V_2 -> V_17 )
goto V_87;
F_6 ( & V_8 -> V_32 ) ;
V_11 = V_8 -> V_33 ;
F_7 ( & V_8 -> V_32 ) ;
if ( ! V_11 )
goto V_87;
V_9 = (struct V_9 * ) V_11 -> V_9 ;
V_14 = V_11 -> V_31 ;
V_9 = V_11 -> V_9 ;
V_21 = V_11 -> V_21 ;
if ( V_11 -> V_19 == 1 )
V_21 = & V_11 -> V_78 ;
F_25 ( V_9 , V_2 -> V_76 ,
F_26 ( V_2 -> V_76 , V_11 ) ,
( T_3 * ) V_14 , V_21 , F_5 ( V_14 -> V_29 ) ,
V_88 , ( void * ) V_2 ) ;
V_8 -> V_73 = V_75 ;
V_71 = F_27 ( V_9 , V_18 ) ;
if ( V_71 < 0 ) {
F_16 ( L_3 ) ;
goto V_87;
}
return;
V_87:
V_8 -> V_73 = V_74 ;
F_24 ( & V_8 -> V_86 ) ;
}
void V_88 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 -> V_89 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_10 * V_11 ;
V_8 -> V_73 = V_90 ;
V_8 -> V_91 = V_9 -> V_92 ;
if ( V_2 -> V_17 ) {
V_8 -> V_73 = V_74 ;
F_24 ( & V_8 -> V_86 ) ;
} else {
F_6 ( & V_8 -> V_32 ) ;
V_11 = V_8 -> V_33 ;
if ( V_11 == V_8 -> V_34 )
V_8 -> V_34 = NULL ;
V_8 -> V_33 = V_8 -> V_33 -> V_30 ;
F_7 ( & V_8 -> V_32 ) ;
if ( V_8 -> V_91 ) {
F_16 ( L_4 ) ;
V_8 -> V_73 = V_74 ;
V_2 -> V_17 = 1 ;
} else {
F_23 ( V_2 ) ;
}
F_10 ( V_11 ) ;
}
F_9 ( V_9 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_9 ;
struct V_10 * V_11 ;
F_29 ( V_2 ) ;
do {
F_13 ( 10 ) ;
} while ( V_8 -> V_73 != V_74 );
F_13 ( 10 ) ;
F_6 ( & V_8 -> V_32 ) ;
V_11 = V_8 -> V_33 ;
while ( V_11 ) {
if ( V_11 == V_8 -> V_34 )
V_8 -> V_34 = NULL ;
V_8 -> V_33 = V_8 -> V_33 -> V_30 ;
V_9 = V_11 -> V_9 ;
F_7 ( & V_8 -> V_32 ) ;
if ( V_9 ) {
F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
} else {
F_16 ( L_5 ) ;
}
F_6 ( & V_8 -> V_32 ) ;
V_11 = V_8 -> V_33 ;
}
F_7 ( & V_8 -> V_32 ) ;
}
unsigned char F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_93 ;
T_2 V_94 , V_95 , V_96 , V_97 ;
F_31 ( & V_8 -> V_32 ) ;
F_12 ( V_2 , 0x03b4 , 0x080d0000 ) ;
F_19 ( V_2 , 0x03b4 , & V_93 ) ;
V_8 -> V_98 = ( T_3 ) ( V_93 & 0xff ) ;
if ( V_8 -> V_98 != V_99 ) {
if ( ( V_8 -> V_98 == V_100 ) ||
( V_8 -> V_98 == V_101 ) ||
( V_8 -> V_98 == V_102 ) ||
( V_8 -> V_98 == V_103 ) ||
( V_8 -> V_98 == V_104 ) ||
( V_8 -> V_98 == V_105 ) ||
( V_8 -> V_98 == V_106 ) ||
( V_8 -> V_98 == V_107 ) ||
( V_8 -> V_98 == V_108 ) ||
( V_8 -> V_98 == V_109 ) )
V_2 -> V_110 = V_8 -> V_98 ;
}
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_12 ( V_2 , 0x03b4 , 0x08200000 ) ;
F_19 ( V_2 , 0x03b4 , & V_95 ) ;
F_12 ( V_2 , 0x03b4 , 0x08210000 ) ;
F_19 ( V_2 , 0x03b4 , & V_94 ) ;
F_12 ( V_2 , 0x03b4 , 0x08100000 ) ;
F_19 ( V_2 , 0x03b4 , & V_96 ) ;
F_12 ( V_2 , 0x03b4 , 0x081d0000 ) ;
F_19 ( V_2 , 0x03b4 , & V_97 ) ;
memcpy ( V_2 -> V_111 , V_2 -> V_112 , V_113 ) ;
V_2 -> V_94 = ( T_1 ) ( V_94 & 0xffff ) ;
V_96 &= 0x000000ff ;
V_2 -> V_114 = ( T_3 ) V_96 ;
V_2 -> V_95 = ( T_3 ) V_95 & 0xff ;
if ( V_2 -> V_95 == 0xff )
V_2 -> V_95 = 0x28 ;
V_8 -> V_115 = ( T_3 ) ( V_97 >> 8 ) ;
if ( V_8 -> V_115 < 1 || V_8 -> V_115 > 6 )
V_8 -> V_115 = V_116 ;
F_34 ( V_2 ) ;
V_2 -> V_117 = ( T_3 ) ( V_97 & 0xff ) * 10 ;
if ( ( V_2 -> V_117 == 2550 ) || ( V_2 -> V_117 < 10 ) )
V_2 -> V_117 = V_118 ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_17 )
return false ;
else
return true ;
}
T_2 F_40 ( T_3 * V_119 , T_2 V_120 )
{
T_2 V_121 , V_122 ;
T_2 V_15 , V_123 ;
T_3 V_124 ;
V_121 = 0xffffffff ;
for ( V_15 = 0 ; V_15 < V_120 ; V_15 ++ ) {
V_124 = V_119 [ V_15 ] ;
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ ) {
V_122 = ( ( V_121 & 0x80000000 ) ? 1 : 0 ) ^ ( V_124 & 0x01 ) ;
V_121 <<= 1 ;
V_124 >>= 1 ;
if ( V_122 )
V_121 = ( V_121 ^ 0x04c11db6 ) | V_122 ;
}
}
return V_121 ;
}
T_2 F_41 ( T_2 V_125 , T_2 V_126 )
{
T_2 V_127 , V_15 , V_123 ;
T_2 V_128 , V_129 ;
if ( V_126 <= 0 )
return 0 ;
V_125 = V_125 & ( 0xffffffff >> ( 32 - V_126 ) ) ;
V_127 = V_126 / 2 ;
for ( V_15 = 0 , V_123 = V_126 - 1 ; V_15 < V_127 ; V_15 ++ , V_123 -- ) {
V_128 = F_42 ( V_125 , V_15 ) ;
V_129 = F_42 ( V_125 , V_123 ) ;
if ( V_128 && ! V_129 ) {
V_125 = F_43 ( V_125 , V_15 ) ;
V_125 = F_44 ( V_125 , V_123 ) ;
} else if ( ! V_128 && V_129 ) {
V_125 = F_44 ( V_125 , V_15 ) ;
V_125 = F_43 ( V_125 , V_123 ) ;
} else {
}
}
return V_125 ;
}
void F_37 ( struct V_1 * V_2 )
{
T_2 V_130 , V_67 ;
if ( ( V_2 -> V_110 == V_108 ) ||
( V_2 -> V_110 == V_109 ) ) {
F_45 ( V_2 , 2412 ) ;
F_19 ( V_2 , 0x103c , & V_130 ) ;
F_19 ( V_2 , 0x1054 , & V_67 ) ;
V_2 -> V_131 = V_130 ;
V_2 -> V_132 = V_67 ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_12 ( V_2 , 0x103c , V_130 ) ;
F_12 ( V_2 , 0x1054 , V_67 ) ;
}
}
