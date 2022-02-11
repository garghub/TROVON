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
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_41 , T_2 * V_4 )
{
void T_1 * V_42 = V_2 -> V_43 +
V_41 ;
* V_4 = F_9 ( V_42 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_41 , T_2 V_4 )
{
void T_1 * V_42 = V_2 -> V_43 +
( V_41 & V_44 ) ;
int V_10 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_5 ;
V_46 = ( V_41 % 4 ) * 8 ;
V_5 = ~ ( 0xFF << V_46 ) ;
F_2 ( V_47 ,
V_2 -> V_43 + V_48 ) ;
V_45 = F_3 ( V_42 ) ;
F_2 ( ( V_45 & V_5 ) | ( V_49 ) V_4 << V_46 , V_42 ) ;
V_10 = 0 ;
while ( F_9 ( V_2 -> V_43 +
V_50 ) != 0x00 ) {
F_11 ( 1 ) ;
if ( V_10 == V_51 )
return - V_52 ;
V_10 ++ ;
}
F_2 ( V_53 ,
V_2 -> V_43 + V_48 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_41 , T_2 * V_4 )
{
unsigned int V_42 ;
V_42 = V_2 -> V_54 +
V_55 [ V_41 ] ;
F_8 ( V_2 , V_42 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_41 , T_2 V_4 )
{
int V_56 ;
unsigned int V_42 ;
V_42 = V_2 -> V_54 +
V_55 [ V_41 ] ;
V_56 = F_10 ( V_2 , V_42 , V_4 ) ;
return V_56 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_10 ( V_2 , 0x0b , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x0a , 0x10 ) ;
V_56 |= F_10 ( V_2 , 0x09 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x08 , 0x02 ) ;
V_56 |= F_10 ( V_2 , 0x0f , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x0e , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x0d , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x0c , 0x80 ) ;
V_56 |= F_10 ( V_2 , 0x13 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x12 , 0x10 ) ;
V_56 |= F_10 ( V_2 , 0x11 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x10 , 0x18 ) ;
V_56 |= F_10 ( V_2 , 0x1b , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x1a , 0x10 ) ;
V_56 |= F_10 ( V_2 , 0x19 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x18 , 0x19 ) ;
V_56 |= F_10 ( V_2 , 0x23 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x22 , 0x10 ) ;
V_56 |= F_10 ( V_2 , 0x21 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x20 , 0x3a ) ;
V_56 |= F_10 ( V_2 , 0x27 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x26 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x25 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x24 , 0x00 ) ;
return V_56 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_56 ;
V_49 V_57 ;
V_57 = 0x200 ;
V_56 = F_10 ( V_2 , 0x03 + V_57 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x02 + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x01 + V_57 , 0x40 ) ;
V_56 |= F_10 ( V_2 , 0x00 + V_57 , 0x02 ) ;
V_56 |= F_10 ( V_2 , 0x07 + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x06 + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x05 + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x04 + V_57 , 0x80 ) ;
V_56 |= F_10 ( V_2 , 0x0b + V_57 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x0a + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x09 + V_57 , 0x40 ) ;
V_56 |= F_10 ( V_2 , 0x08 + V_57 , 0x18 ) ;
V_56 |= F_10 ( V_2 , 0x13 + V_57 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x12 + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x11 + V_57 , 0x40 ) ;
V_56 |= F_10 ( V_2 , 0x10 + V_57 , 0x19 ) ;
V_56 |= F_10 ( V_2 , 0x1b + V_57 , 0xbc ) ;
V_56 |= F_10 ( V_2 , 0x1a + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x19 + V_57 , 0x40 ) ;
V_56 |= F_10 ( V_2 , 0x18 + V_57 , 0x3a ) ;
V_56 |= F_10 ( V_2 , 0x1f + V_57 , 0x01 ) ;
V_56 |= F_10 ( V_2 , 0x1e + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x1d + V_57 , 0x00 ) ;
V_56 |= F_10 ( V_2 , 0x1c + V_57 , 0x00 ) ;
return V_56 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_58 ; V_10 ++ )
F_12 ( V_2 , V_10 , & V_4 [ V_10 ] ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_56 ;
int V_10 ;
if ( V_2 -> V_59 == 1 )
V_56 = F_14 ( V_2 ) ;
else
V_56 = F_15 ( V_2 ) ;
if ( V_56 )
return V_56 ;
for ( V_10 = 0 ; V_10 < V_58 ; V_10 ++ ) {
V_56 = F_13 ( V_2 , V_10 , V_4 [ V_10 ] ) ;
if ( V_56 )
return V_56 ;
}
return V_56 ;
}
static T_3 F_18 ( struct V_60 * V_61 , struct V_62 * V_63 ,
struct V_64 * V_65 , char * V_66 ,
T_4 V_67 , T_5 V_68 )
{
unsigned int V_69 ;
unsigned char V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
int V_74 ;
int V_75 ;
struct V_1 * V_2 =
F_19 ( F_20 ( V_63 , struct V_76 , V_63 ) ) ;
V_74 = F_21 ( & V_77 ) ;
if ( V_74 ) {
V_75 = - V_78 ;
goto V_79;
}
F_8 ( V_2 , V_2 -> V_80 ,
( unsigned char * ) & V_69 ) ;
V_69 &= 0xff ;
F_8 ( V_2 , V_2 -> V_80 + 1 ,
( unsigned char * ) & V_71 ) ;
V_69 |= ( V_71 & 0xff ) << 8 ;
if ( V_69 == 0xAA55 ) {
F_8 ( V_2 ,
V_2 -> V_80 + 2 ,
& V_70 ) ;
V_73 = V_70 * 512 ;
if ( V_73 < V_67 ) {
V_72 = 0 ;
goto V_81;
}
if ( V_73 < V_68 ) {
V_72 = 0 ;
goto V_81;
}
for ( V_72 = 0 ; V_72 < V_68 ; V_72 ++ ) {
F_8 ( V_2 ,
V_2 -> V_80 + V_72 + V_67 ,
& V_66 [ V_72 ] ) ;
}
} else {
V_75 = - V_82 ;
goto V_83;
}
V_81:
F_22 ( & V_77 ) ;
return V_72 ;
V_83:
F_22 ( & V_77 ) ;
V_79:
return V_75 ;
}
static T_3 F_23 ( struct V_60 * V_61 , struct V_62 * V_63 ,
struct V_64 * V_65 ,
char * V_66 , T_4 V_67 , T_5 V_68 )
{
int V_75 ;
unsigned int V_72 ;
int V_74 ;
struct V_1 * V_2 =
F_19 ( F_20 ( V_63 , struct V_76 , V_63 ) ) ;
V_74 = F_21 ( & V_77 ) ;
if ( V_74 )
return - V_78 ;
if ( V_67 > V_84 ) {
V_72 = 0 ;
goto V_81;
}
if ( V_68 > V_84 ) {
V_72 = 0 ;
goto V_81;
}
for ( V_72 = 0 ; V_72 < V_68 ; V_72 ++ ) {
if ( V_84 < V_67 + V_72 )
goto V_81;
V_74 = F_10 ( V_2 ,
V_2 -> V_80 + V_72 + V_67 ,
V_66 [ V_72 ] ) ;
if ( V_74 ) {
V_75 = V_74 ;
goto V_83;
}
}
V_81:
F_22 ( & V_77 ) ;
return V_72 ;
V_83:
F_22 ( & V_77 ) ;
return V_75 ;
}
static T_3 F_24 ( struct V_76 * V_34 , struct V_85 * V_65 ,
char * V_66 )
{
T_2 V_86 [ 8 ] ;
struct V_1 * V_2 = F_19 ( V_34 ) ;
F_16 ( V_2 , V_86 ) ;
return sprintf ( V_66 , L_14 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] , V_86 [ 3 ] , V_86 [ 4 ] , V_86 [ 5 ] ) ;
}
static T_3 F_25 ( struct V_76 * V_34 , struct V_85 * V_65 ,
const char * V_66 , T_5 V_68 )
{
T_2 V_86 [ 6 ] ;
struct V_1 * V_2 = F_19 ( V_34 ) ;
if ( V_68 != 18 )
return - V_87 ;
sscanf ( V_66 , L_15 ,
( V_49 * ) & V_86 [ 0 ] , ( V_49 * ) & V_86 [ 1 ] , ( V_49 * ) & V_86 [ 2 ] , ( V_49 * ) & V_86 [ 3 ] ,
( V_49 * ) & V_86 [ 4 ] , ( V_49 * ) & V_86 [ 5 ] ) ;
F_17 ( V_2 , V_86 ) ;
return V_68 ;
}
static int T_6 F_26 ( struct V_8 * V_9 ,
const struct V_88 * V_89 )
{
int V_56 ;
int V_74 ;
T_3 V_90 ;
struct V_1 * V_2 ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_91 ) ;
if ( V_2 == NULL )
return - V_92 ;
V_74 = F_28 ( V_9 ) ;
if ( V_74 ) {
F_29 ( & V_9 -> V_34 ,
L_16 , V_35 , V_74 ) ;
goto V_93;
}
F_6 ( & V_9 -> V_34 , L_17 , V_35 ,
V_74 ) ;
V_74 = F_30 ( V_9 , V_94 ) ;
if ( V_74 ) {
F_29 ( & V_9 -> V_34 ,
L_18 , V_35 , V_74 ) ;
goto V_95;
}
F_6 ( & V_9 -> V_34 , L_1
L_19 , V_35 , V_74 ) ;
V_2 -> V_7 = F_31 ( V_9 , 1 , 0 ) ;
if ( V_2 -> V_7 == 0 ) {
F_29 ( & V_9 -> V_34 , L_20 , V_35 ) ;
V_74 = - V_92 ;
goto V_96;
}
F_6 ( & V_9 -> V_34 , L_21
L_22 , V_35 ,
V_2 -> V_7 ) ;
if ( V_89 -> V_97 != 3 ) {
V_2 -> V_43 =\
F_32 ( V_9 , & V_90 ) ;
if ( V_2 -> V_43 == 0 ) {
F_29 ( & V_9 -> V_34 , L_23 , V_35 ) ;
V_74 = - V_92 ;
goto V_98;
}
F_6 ( & V_9 -> V_34 , L_1
L_24
L_25 ,
V_35 , V_2 -> V_43 ) ;
}
if ( V_89 -> V_97 == 1 ) {
const char * V_99 ;
V_56 = F_33 ( & V_9 -> V_34 . V_63 ,
& V_100 . V_65 ) ;
if ( V_56 )
goto V_101;
V_56 = F_34 ( & V_9 -> V_34 . V_63 , & V_102 ) ;
if ( V_56 )
goto V_103;
F_1 ( V_2 ,
( unsigned int ) V_40 ,
V_104 ,
V_105 ) ;
V_99 = F_35 ( V_106 ) ;
if ( V_99 && strstr ( V_99 , L_26 ) )
F_1 ( V_2 ,
( unsigned int ) V_40 ,
V_107 | V_108 |
V_109 | V_110 ,
V_111 ) ;
F_2 ( 0x000affaa , V_2 -> V_7 + 0x14 ) ;
F_2 ( 0x25 , V_2 -> V_7 + 0x44 ) ;
V_2 -> V_80 = V_112 ;
V_2 -> V_54 = V_113 ;
} else if ( V_89 -> V_97 == 2 ) {
V_56 = F_34 ( & V_9 -> V_34 . V_63 , & V_102 ) ;
if ( V_56 )
goto V_101;
F_2 ( 0x000affa0 , V_2 -> V_7 + 0x14 ) ;
V_2 -> V_80 =\
V_114 ;
} else if ( V_89 -> V_97 == 3 ) {
F_2 ( 0x000a0000 , V_2 -> V_7 + 0x14 ) ;
F_2 ( 0x25 , V_2 -> V_7 + 0x140 ) ;
V_2 -> V_80 =\
V_115 ;
V_2 -> V_54 = V_116 ;
} else if ( V_89 -> V_97 == 4 ) {
V_56 = F_33 ( & V_9 -> V_34 . V_63 ,
& V_100 . V_65 ) ;
if ( V_56 )
goto V_101;
V_56 = F_34 ( & V_9 -> V_34 . V_63 , & V_102 ) ;
if ( V_56 )
goto V_103;
F_2 ( 0x0000ffa0 , V_2 -> V_7 + 0x14 ) ;
V_2 -> V_80 =\
V_115 ;
V_2 -> V_54 = V_116 ;
}
V_2 -> V_59 = V_89 -> V_97 ;
F_36 ( V_9 , V_2 ) ;
return 0 ;
V_103:
F_37 ( & V_9 -> V_34 . V_63 , & V_100 . V_65 ) ;
V_101:
F_38 ( V_9 , V_2 -> V_43 ) ;
V_98:
F_39 ( V_9 , V_2 -> V_7 ) ;
V_96:
F_40 ( V_9 ) ;
V_95:
F_41 ( V_9 ) ;
V_93:
F_42 ( V_2 ) ;
F_29 ( & V_9 -> V_34 , L_27 , V_35 , V_74 ) ;
return V_74 ;
}
static void T_7 F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_37 ( & V_9 -> V_34 . V_63 , & V_100 . V_65 ) ;
F_44 ( & V_9 -> V_34 . V_63 , & V_102 ) ;
F_38 ( V_9 , V_2 -> V_43 ) ;
F_39 ( V_9 , V_2 -> V_7 ) ;
F_40 ( V_9 ) ;
F_41 ( V_9 ) ;
F_42 ( V_2 ) ;
}
static int F_45 ( struct V_8 * V_9 , T_8 V_117 )
{
int V_74 ;
F_4 ( V_9 ) ;
V_74 = F_46 ( V_9 ) ;
if ( V_74 ) {
F_29 ( & V_9 -> V_34 ,
L_28 , V_35 , V_74 ) ;
return V_74 ;
}
F_47 ( V_9 , V_118 , 0 ) ;
F_41 ( V_9 ) ;
F_48 ( V_9 , F_49 ( V_9 , V_117 ) ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
int V_74 ;
F_48 ( V_9 , V_119 ) ;
F_51 ( V_9 ) ;
V_74 = F_28 ( V_9 ) ;
if ( V_74 ) {
F_29 ( & V_9 -> V_34 ,
L_29 , V_35 , V_74 ) ;
return V_74 ;
}
F_47 ( V_9 , V_118 , 0 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static int T_9 F_52 ( void )
{
return F_53 ( & V_120 ) ;
}
static void T_10 F_54 ( void )
{
F_55 ( & V_120 ) ;
}
