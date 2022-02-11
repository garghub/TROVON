static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
void T_1 * V_6 = V_2 -> V_7 + V_3 ;
F_2 ( ( ( F_3 ( V_6 ) & ~ V_5 ) ) | V_4 , V_6 ) ;
}
static void F_4 ( struct V_8 * V_9 )
{
unsigned int V_10 ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
void T_1 * V_11 = V_2 -> V_7 ;
V_2 -> V_12 = F_3 ( V_11 + V_13 ) ;
V_2 -> V_14 = F_3 ( V_11 + V_15 ) ;
V_2 -> V_16 = F_3 ( V_11 + V_17 ) ;
V_2 -> V_18 = F_3 ( V_11 + V_19 ) ;
V_2 -> V_20 =
F_3 ( V_11 + V_21 ) ;
V_2 -> V_22 =
F_3 ( V_11 + V_23 ) ;
V_2 -> V_24 =
F_3 ( V_11 + V_25 ) ;
V_2 -> V_26 =
F_3 ( V_11 + V_27 ) ;
V_2 -> V_28 =
F_3 ( V_11 + V_29 ) ;
V_2 -> V_30 =
F_3 ( V_11 + V_31 ) ;
V_2 -> V_32 =
F_3 ( V_11 + V_33 ) ;
F_6 ( & V_9 -> V_34 , L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12 , V_35 ,
V_2 -> V_12 ,
V_2 -> V_14 ,
V_2 -> V_16 ,
V_2 -> V_18 ,
V_2 -> V_20 ,
V_2 -> V_22 ,
V_2 -> V_24 ,
V_2 -> V_26 ,
V_2 -> V_28 ,
V_2 -> V_30 ,
V_2 -> V_32 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
V_2 -> V_37 [ V_10 ] =
F_3 ( V_11 + V_38 + 4 * V_10 ) ;
F_6 ( & V_9 -> V_34 , L_1
L_13 ,
V_35 , V_10 , V_2 -> V_37 [ V_10 ] ) ;
}
V_2 -> V_39 = F_3 ( V_11 + V_40 ) ;
if ( ( V_2 -> V_41 == 2 ) || ( V_2 -> V_41 == 4 ) )
V_2 -> V_42 = F_3 ( V_11 + V_43 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
unsigned int V_10 ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
void T_1 * V_11 ;
V_11 = V_2 -> V_7 ;
F_2 ( V_2 -> V_12 , V_11 + V_13 ) ;
F_2 ( V_2 -> V_14 , V_11 + V_15 ) ;
F_2 ( V_2 -> V_16 , V_11 + V_17 ) ;
F_2 ( V_2 -> V_18 , V_11 + V_19 ) ;
F_2 ( V_2 -> V_20 ,
V_11 + V_21 ) ;
F_2 ( V_2 -> V_22 ,
V_11 + V_23 ) ;
F_2 ( V_2 -> V_24 ,
V_11 + V_25 ) ;
F_2 ( V_2 -> V_26 ,
V_11 + V_27 ) ;
F_2 ( V_2 -> V_28 ,
V_11 + V_29 ) ;
F_2 ( V_2 -> V_30 ,
V_11 + V_31 ) ;
F_2 ( V_2 -> V_32 ,
V_11 + V_33 ) ;
F_6 ( & V_9 -> V_34 , L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12 , V_35 ,
V_2 -> V_12 ,
V_2 -> V_14 ,
V_2 -> V_16 ,
V_2 -> V_18 ,
V_2 -> V_20 ,
V_2 -> V_22 ,
V_2 -> V_24 ,
V_2 -> V_26 ,
V_2 -> V_28 ,
V_2 -> V_30 ,
V_2 -> V_32 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_2 ( V_2 -> V_37 [ V_10 ] ,
V_11 + V_38 + 4 * V_10 ) ;
F_6 ( & V_9 -> V_34 , L_1
L_13 ,
V_35 , V_10 , V_2 -> V_37 [ V_10 ] ) ;
}
F_2 ( V_2 -> V_39 , V_11 + V_40 ) ;
if ( ( V_2 -> V_41 == 2 ) || ( V_2 -> V_41 == 4 ) )
F_2 ( V_2 -> V_42 , V_11 + V_43 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_44 , T_2 * V_4 )
{
void T_1 * V_45 = V_2 -> V_46 +
V_44 ;
* V_4 = F_9 ( V_45 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_44 , T_2 V_4 )
{
void T_1 * V_45 = V_2 -> V_46 +
( V_44 & V_47 ) ;
int V_10 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_5 ;
V_49 = ( V_44 % 4 ) * 8 ;
V_5 = ~ ( 0xFF << V_49 ) ;
F_2 ( V_50 ,
V_2 -> V_46 + V_51 ) ;
V_48 = F_3 ( V_45 ) ;
F_2 ( ( V_48 & V_5 ) | ( V_52 ) V_4 << V_49 , V_45 ) ;
V_10 = 0 ;
while ( F_9 ( V_2 -> V_46 +
V_53 ) != 0x00 ) {
F_11 ( 1 ) ;
if ( V_10 == V_54 )
return - V_55 ;
V_10 ++ ;
}
F_2 ( V_56 ,
V_2 -> V_46 + V_51 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_44 , T_2 * V_4 )
{
unsigned int V_45 ;
V_45 = V_2 -> V_57 +
V_58 [ V_44 ] ;
F_8 ( V_2 , V_45 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_44 , T_2 V_4 )
{
int V_59 ;
unsigned int V_45 ;
V_45 = V_2 -> V_57 +
V_58 [ V_44 ] ;
V_59 = F_10 ( V_2 , V_45 , V_4 ) ;
return V_59 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_10 ( V_2 , 0x0b , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x0a , 0x10 ) ;
V_59 |= F_10 ( V_2 , 0x09 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x08 , 0x02 ) ;
V_59 |= F_10 ( V_2 , 0x0f , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x0e , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x0d , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x0c , 0x80 ) ;
V_59 |= F_10 ( V_2 , 0x13 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x12 , 0x10 ) ;
V_59 |= F_10 ( V_2 , 0x11 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x10 , 0x18 ) ;
V_59 |= F_10 ( V_2 , 0x1b , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x1a , 0x10 ) ;
V_59 |= F_10 ( V_2 , 0x19 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x18 , 0x19 ) ;
V_59 |= F_10 ( V_2 , 0x23 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x22 , 0x10 ) ;
V_59 |= F_10 ( V_2 , 0x21 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x20 , 0x3a ) ;
V_59 |= F_10 ( V_2 , 0x27 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x26 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x25 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x24 , 0x00 ) ;
return V_59 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_59 ;
V_52 V_60 ;
V_60 = 0x200 ;
V_59 = F_10 ( V_2 , 0x03 + V_60 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x02 + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x01 + V_60 , 0x40 ) ;
V_59 |= F_10 ( V_2 , 0x00 + V_60 , 0x02 ) ;
V_59 |= F_10 ( V_2 , 0x07 + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x06 + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x05 + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x04 + V_60 , 0x80 ) ;
V_59 |= F_10 ( V_2 , 0x0b + V_60 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x0a + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x09 + V_60 , 0x40 ) ;
V_59 |= F_10 ( V_2 , 0x08 + V_60 , 0x18 ) ;
V_59 |= F_10 ( V_2 , 0x13 + V_60 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x12 + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x11 + V_60 , 0x40 ) ;
V_59 |= F_10 ( V_2 , 0x10 + V_60 , 0x19 ) ;
V_59 |= F_10 ( V_2 , 0x1b + V_60 , 0xbc ) ;
V_59 |= F_10 ( V_2 , 0x1a + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x19 + V_60 , 0x40 ) ;
V_59 |= F_10 ( V_2 , 0x18 + V_60 , 0x3a ) ;
V_59 |= F_10 ( V_2 , 0x1f + V_60 , 0x01 ) ;
V_59 |= F_10 ( V_2 , 0x1e + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x1d + V_60 , 0x00 ) ;
V_59 |= F_10 ( V_2 , 0x1c + V_60 , 0x00 ) ;
return V_59 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_61 ; V_10 ++ )
F_12 ( V_2 , V_10 , & V_4 [ V_10 ] ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_59 ;
int V_10 ;
if ( ( V_2 -> V_41 == 1 ) || ( V_2 -> V_41 == 5 ) )
V_59 = F_14 ( V_2 ) ;
else
V_59 = F_15 ( V_2 ) ;
if ( V_59 )
return V_59 ;
for ( V_10 = 0 ; V_10 < V_61 ; V_10 ++ ) {
V_59 = F_13 ( V_2 , V_10 , V_4 [ V_10 ] ) ;
if ( V_59 )
return V_59 ;
}
return V_59 ;
}
static T_3 F_18 ( struct V_62 * V_63 , struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 ,
T_4 V_69 , T_5 V_70 )
{
unsigned int V_71 ;
unsigned char V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
int V_76 ;
int V_77 ;
T_3 V_78 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_65 ) ) ;
V_76 = F_21 ( & V_79 ) ;
if ( V_76 ) {
V_77 = - V_80 ;
goto V_81;
}
V_2 -> V_46 = F_22 ( V_2 -> V_9 , & V_78 ) ;
if ( ! V_2 -> V_46 ) {
V_77 = - V_82 ;
goto V_83;
}
F_8 ( V_2 , V_2 -> V_84 ,
( unsigned char * ) & V_71 ) ;
V_71 &= 0xff ;
F_8 ( V_2 , V_2 -> V_84 + 1 ,
( unsigned char * ) & V_73 ) ;
V_71 |= ( V_73 & 0xff ) << 8 ;
if ( V_71 == 0xAA55 ) {
F_8 ( V_2 ,
V_2 -> V_84 + 2 ,
& V_72 ) ;
V_75 = V_72 * 512 ;
if ( V_75 < V_69 ) {
V_74 = 0 ;
goto V_85;
}
if ( V_75 < V_70 ) {
V_74 = 0 ;
goto V_85;
}
for ( V_74 = 0 ; V_74 < V_70 ; V_74 ++ ) {
F_8 ( V_2 ,
V_2 -> V_84 + V_74 + V_69 ,
& V_68 [ V_74 ] ) ;
}
} else {
V_77 = - V_82 ;
goto V_86;
}
V_85:
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
F_24 ( & V_79 ) ;
return V_74 ;
V_86:
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
V_83:
F_24 ( & V_79 ) ;
V_81:
return V_77 ;
}
static T_3 F_25 ( struct V_62 * V_63 , struct V_64 * V_65 ,
struct V_66 * V_67 ,
char * V_68 , T_4 V_69 , T_5 V_70 )
{
int V_77 ;
unsigned int V_74 ;
int V_76 ;
T_3 V_78 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_65 ) ) ;
V_76 = F_21 ( & V_79 ) ;
if ( V_76 )
return - V_80 ;
if ( V_69 > V_87 ) {
V_74 = 0 ;
goto V_85;
}
if ( V_70 > V_87 ) {
V_74 = 0 ;
goto V_85;
}
V_2 -> V_46 = F_22 ( V_2 -> V_9 , & V_78 ) ;
if ( ! V_2 -> V_46 ) {
V_77 = - V_88 ;
goto V_83;
}
for ( V_74 = 0 ; V_74 < V_70 ; V_74 ++ ) {
if ( V_87 < V_69 + V_74 )
goto V_85;
V_76 = F_10 ( V_2 ,
V_2 -> V_84 + V_74 + V_69 ,
V_68 [ V_74 ] ) ;
if ( V_76 ) {
V_77 = V_76 ;
goto V_86;
}
}
V_85:
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
F_24 ( & V_79 ) ;
return V_74 ;
V_86:
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
V_83:
F_24 ( & V_79 ) ;
return V_77 ;
}
static T_3 F_26 ( struct V_89 * V_34 , struct V_90 * V_67 ,
char * V_68 )
{
T_2 V_91 [ 8 ] ;
struct V_1 * V_2 = F_19 ( V_34 ) ;
T_3 V_78 ;
V_2 -> V_46 = F_22 ( V_2 -> V_9 , & V_78 ) ;
if ( ! V_2 -> V_46 )
return - V_88 ;
F_16 ( V_2 , V_91 ) ;
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
return sprintf ( V_68 , L_14 , V_91 ) ;
}
static T_3 F_27 ( struct V_89 * V_34 , struct V_90 * V_67 ,
const char * V_68 , T_5 V_70 )
{
T_2 V_91 [ V_61 ] ;
T_3 V_78 ;
struct V_1 * V_2 = F_19 ( V_34 ) ;
int V_76 ;
if ( ! F_28 ( V_68 , V_91 ) )
return - V_92 ;
V_2 -> V_46 = F_22 ( V_2 -> V_9 , & V_78 ) ;
if ( ! V_2 -> V_46 )
return - V_88 ;
V_76 = F_17 ( V_2 , V_91 ) ;
F_23 ( V_2 -> V_9 , V_2 -> V_46 ) ;
if ( V_76 )
return V_76 ;
return V_70 ;
}
static int F_29 ( struct V_8 * V_9 ,
const struct V_93 * V_94 )
{
int V_76 ;
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_95 ) ;
if ( V_2 == NULL )
return - V_88 ;
V_76 = F_31 ( V_9 ) ;
if ( V_76 ) {
F_32 ( & V_9 -> V_34 ,
L_15 , V_35 , V_76 ) ;
goto V_96;
}
F_6 ( & V_9 -> V_34 , L_16 , V_35 ,
V_76 ) ;
V_76 = F_33 ( V_9 , V_97 ) ;
if ( V_76 ) {
F_32 ( & V_9 -> V_34 ,
L_17 , V_35 , V_76 ) ;
goto V_98;
}
F_6 ( & V_9 -> V_34 , L_1
L_18 , V_35 , V_76 ) ;
V_2 -> V_7 = F_34 ( V_9 , 1 , 0 ) ;
if ( V_2 -> V_7 == NULL ) {
F_32 ( & V_9 -> V_34 , L_19 , V_35 ) ;
V_76 = - V_88 ;
goto V_99;
}
F_6 ( & V_9 -> V_34 , L_20
L_21 , V_35 ,
V_2 -> V_7 ) ;
V_2 -> V_9 = V_9 ;
if ( V_94 -> V_100 == 1 ) {
const char * V_101 ;
unsigned int V_102 = 0x000affaa ;
if ( V_9 -> V_34 . V_103 )
F_35 ( V_9 -> V_34 . V_103 ,
L_22 ,
& V_102 ) ;
V_76 = F_36 ( & V_9 -> V_34 . V_65 ,
& V_104 . V_67 ) ;
if ( V_76 )
goto V_105;
V_76 = F_37 ( & V_9 -> V_34 . V_65 , & V_106 ) ;
if ( V_76 )
goto V_107;
F_1 ( V_2 ,
( unsigned int ) V_40 ,
V_108 ,
V_109 ) ;
V_101 = F_38 ( V_110 ) ;
if ( V_101 && strstr ( V_101 , L_23 ) )
F_1 ( V_2 ,
( unsigned int ) V_40 ,
V_111 | V_112 |
V_113 | V_114 ,
V_115 ) ;
F_2 ( V_102 , V_2 -> V_7 + 0x14 ) ;
F_2 ( 0x25 , V_2 -> V_7 + 0x44 ) ;
V_2 -> V_84 = V_116 ;
V_2 -> V_57 = V_117 ;
if ( V_9 -> V_34 . V_103 ) {
if ( F_39 ( L_24 ) ) {
F_1 ( V_2 ,
( unsigned int ) V_40 ,
V_118 ,
V_115 ) ;
}
}
} else if ( V_94 -> V_100 == 2 ) {
V_76 = F_37 ( & V_9 -> V_34 . V_65 , & V_106 ) ;
if ( V_76 )
goto V_105;
F_2 ( 0x000affa0 , V_2 -> V_7 + 0x14 ) ;
V_2 -> V_84 =\
V_119 ;
} else if ( V_94 -> V_100 == 3 ) {
F_2 ( 0x000a0000 , V_2 -> V_7 + 0x14 ) ;
F_2 ( 0x25 , V_2 -> V_7 + 0x140 ) ;
V_2 -> V_84 =\
V_120 ;
V_2 -> V_57 = V_121 ;
} else if ( V_94 -> V_100 == 4 ) {
V_76 = F_36 ( & V_9 -> V_34 . V_65 ,
& V_104 . V_67 ) ;
if ( V_76 )
goto V_105;
V_76 = F_37 ( & V_9 -> V_34 . V_65 , & V_106 ) ;
if ( V_76 )
goto V_107;
F_2 ( 0x0000ffa0 , V_2 -> V_7 + 0x14 ) ;
V_2 -> V_84 =\
V_120 ;
V_2 -> V_57 = V_121 ;
} else if ( V_94 -> V_100 == 5 ) {
V_76 = F_36 ( & V_9 -> V_34 . V_65 ,
& V_104 . V_67 ) ;
if ( V_76 )
goto V_105;
V_76 = F_37 ( & V_9 -> V_34 . V_65 , & V_106 ) ;
if ( V_76 )
goto V_107;
F_2 ( 0x000affaa , V_2 -> V_7 + 0x14 ) ;
F_2 ( 0x25 , V_2 -> V_7 + 0x44 ) ;
V_2 -> V_84 = V_116 ;
V_2 -> V_57 = V_117 ;
}
V_2 -> V_41 = V_94 -> V_100 ;
F_40 ( V_9 , V_2 ) ;
return 0 ;
V_107:
F_41 ( & V_9 -> V_34 . V_65 , & V_104 . V_67 ) ;
V_105:
F_42 ( V_9 , V_2 -> V_7 ) ;
V_99:
F_43 ( V_9 ) ;
V_98:
F_44 ( V_9 ) ;
V_96:
F_45 ( V_2 ) ;
F_32 ( & V_9 -> V_34 , L_25 , V_35 , V_76 ) ;
return V_76 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_41 ( & V_9 -> V_34 . V_65 , & V_104 . V_67 ) ;
F_47 ( & V_9 -> V_34 . V_65 , & V_106 ) ;
F_42 ( V_9 , V_2 -> V_7 ) ;
F_43 ( V_9 ) ;
F_44 ( V_9 ) ;
F_45 ( V_2 ) ;
}
static int F_48 ( struct V_8 * V_9 , T_6 V_122 )
{
int V_76 ;
F_4 ( V_9 ) ;
V_76 = F_49 ( V_9 ) ;
if ( V_76 ) {
F_32 ( & V_9 -> V_34 ,
L_26 , V_35 , V_76 ) ;
return V_76 ;
}
F_50 ( V_9 , V_123 , 0 ) ;
F_44 ( V_9 ) ;
F_51 ( V_9 , F_52 ( V_9 , V_122 ) ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_76 ;
F_51 ( V_9 , V_124 ) ;
F_54 ( V_9 ) ;
V_76 = F_31 ( V_9 ) ;
if ( V_76 ) {
F_32 ( & V_9 -> V_34 ,
L_27 , V_35 , V_76 ) ;
return V_76 ;
}
F_50 ( V_9 , V_123 , 0 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
