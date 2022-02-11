static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 ;
if ( V_3 < 0x8 )
V_4 = F_2 ( V_3 ) ;
else {
F_3 ( V_2 , 1 ) ;
V_4 = F_2 ( V_3 ) ;
F_3 ( V_2 , 0 ) ;
}
return V_4 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
if ( V_3 < 0x8 )
F_5 ( V_5 , V_3 ) ;
else {
F_3 ( V_2 , 1 ) ;
F_5 ( V_5 , V_3 ) ;
F_3 ( V_2 , 0 ) ;
}
}
static unsigned short F_6 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 ;
if ( V_3 < 0x8 )
V_4 = F_7 ( V_3 ) ;
else {
F_3 ( V_2 , 1 ) ;
V_4 = F_7 ( V_3 ) ;
F_3 ( V_2 , 0 ) ;
}
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
if ( V_3 < 0x8 )
F_9 ( V_5 , V_3 ) ;
else {
F_3 ( V_2 , 1 ) ;
F_9 ( V_5 , V_3 ) ;
F_3 ( V_2 , 0 ) ;
}
}
static int T_1 F_10 ( struct V_6 * V_6 )
{
static int V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 = F_11 ( V_6 ) ;
int V_4 = 0 ;
if ( V_7 ++ == 0 )
F_12 ( L_1 , V_14 ) ;
if( F_13 ( V_13 ) )
return - V_15 ;
F_14 ( V_13 , 1 ) ;
V_2 = F_15 ( sizeof( struct V_8 ) ) ;
if ( ! V_2 ) {
F_12 ( L_2 ) ;
F_14 ( V_13 , 0 ) ;
V_4 = - V_16 ;
goto V_17;
}
V_2 -> V_18 = & V_19 ;
V_11 = F_16 ( sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL ) {
V_4 = - V_16 ;
goto V_21;
}
V_2 -> V_22 = 0x0a20 +
( ( V_13 -> V_23 [ 2 ] & V_24 ) ? 0x0400 : 0 ) +
( ( V_13 -> V_23 [ 0 ] & V_25 ) ? 0x1000 : 0 ) +
( ( V_13 -> V_23 [ 3 ] & V_26 ) ? 0x2000 : 0 ) ;
switch( V_13 -> V_23 [ 0 ] >> 6 ) {
case 0x1 : V_2 -> V_27 = 3 ; break;
case 0x2 : V_2 -> V_27 = 9 ; break;
case 0x3 : V_2 -> V_27 = 10 ; break;
default: V_2 -> V_27 = 0 ; break;
}
if ( V_2 -> V_27 == 0 ) {
F_12 ( L_3 , V_2 -> V_28 ) ;
V_4 = - V_15 ;
goto V_29;
}
if ( ! F_17 ( V_2 -> V_22 , V_30 ,
L_4 ) ) {
F_12 ( V_31 L_5 , V_13 -> V_32 , V_2 -> V_22 ) ;
V_2 -> V_22 += V_33 ;
V_4 = - V_15 ;
goto V_29;
}
V_2 -> V_22 += V_33 ;
V_11 -> V_34 = ( ( V_13 -> V_23 [ 0 ] >> 1 ) & 0x7 ) + 8 ;
V_11 -> V_35 = ( ( V_13 -> V_23 [ 2 ] >> 6 ) & 0x3 ) ;
V_11 -> V_36 = ( ( V_13 -> V_23 [ 2 ] >> 4 ) & 0x1 ) ;
if ( ( V_13 -> V_23 [ 1 ] >> 2 ) & 0x1 )
V_11 -> V_37 = 2 ;
else if ( ( V_13 -> V_23 [ 2 ] >> 5 ) & 0x1 )
V_11 -> V_37 = 1 ;
else
V_11 -> V_37 = 0 ;
if ( ( V_13 -> V_23 [ 1 ] >> 6 ) & 0x1 )
V_11 -> V_38 = 1 ;
else
V_11 -> V_38 = 0 ;
F_18 ( V_2 , V_11 ) ;
if ( V_11 -> V_39 != 0x4d ) {
F_12 ( V_31 L_6 , V_2 -> V_28 , V_11 -> V_39 ) ;
goto V_40;
}
if ( ( V_11 -> V_41 != 0x08 ) && ( V_11 -> V_41 != 0x0d ) ) {
F_12 ( V_31 L_7 , V_2 -> V_28 , V_11 -> V_41 ) ;
V_4 = - V_42 ;
goto V_40;
}
if ( ( V_11 -> V_41 == 0x08 ) && ( V_11 -> V_43 <= 0x01 ) )
V_11 -> V_44 = 128 ;
else
V_11 -> V_44 = 256 ;
F_12 ( L_8 ,
V_2 -> V_28 ,
( V_11 -> V_41 == 0x08 ) ? V_45 :
V_46 , V_11 -> V_43 ,
V_2 -> V_22 , V_2 -> V_27 ) ;
if ( V_11 -> V_41 == 0x0d )
F_12 ( L_9 , V_2 -> V_28 ) ;
if ( V_11 -> V_37 == 2 ) {
F_12 ( L_10 , V_2 -> V_28 ) ;
V_11 -> V_37 = 1 ;
}
F_12 ( L_11 , V_2 -> V_28 , V_11 -> V_44 ) ;
F_12 ( L_12 , V_2 -> V_28 ,
( V_11 -> V_37 ) ? 16 : 4 ,
V_11 -> V_38 ? L_13 : L_14 ) ;
F_12 ( L_15 , V_2 -> V_28 ,
V_11 -> V_34 ) ;
F_12 ( L_16 , V_2 -> V_28 ) ;
switch( V_11 -> V_35 ) {
case 0 : F_12 ( L_17 ) ; break;
case 1 : F_12 ( L_18 ) ; break;
case 2 : F_12 ( L_19 ) ; break;
case 3 : F_12 ( L_20 ) ; break;
}
F_12 ( L_21 , ( V_11 -> V_36 ) ? L_22 : L_23 ) ;
F_19 ( 0 , V_2 -> V_22 + V_47 ) ;
F_20 ( V_2 , 1 ) ;
if ( F_21 ( V_2 -> V_27 , V_48 , V_49 ,
L_4 , V_2 ) ) {
V_4 = - V_15 ;
goto V_40;
}
F_22 ( V_2 ) ;
F_23 ( V_2 , V_11 -> V_38 ) ;
F_24 ( V_13 , ( V_11 -> V_41 == 0x08 ) ? V_45 : V_46 ) ;
F_25 ( V_13 -> V_32 , V_50 , V_2 ) ;
F_12 ( L_24 ,
V_2 -> V_28 , V_2 -> V_51 ) ;
if ( F_26 ( V_2 , V_6 ) ) {
F_12 ( L_25 ,
V_2 -> V_28 ) ;
V_4 = - V_16 ;
goto V_52;
}
V_9 = F_27 ( V_2 ) ;
V_9 -> V_53 = V_54 ;
V_9 -> V_55 = F_4 ;
V_9 -> V_56 = F_1 ;
V_9 -> V_57 = F_8 ;
V_9 -> V_58 = F_6 ;
V_9 -> V_59 = ( V_11 -> V_37 ) ? V_60 : V_61 ;
memcpy ( V_9 -> V_62 , L_26 , V_63 + 1 ) ;
V_9 -> V_64 = V_11 ;
F_28 ( V_6 , V_2 ) ;
if ( F_29 ( V_2 ) == 0 )
return 0 ;
F_28 ( V_6 , NULL ) ;
V_4 = - V_16 ;
V_52:
F_30 ( V_2 -> V_27 , V_2 ) ;
V_40:
F_31 ( V_2 -> V_22 - V_33 ,
V_30 ) ;
V_29:
F_32 ( V_11 ) ;
V_21:
F_33 ( V_2 ) ;
V_17:
F_14 ( V_13 , 0 ) ;
return V_4 ;
}
static T_2 V_48 ( int V_27 , void * V_65 )
{
int V_66 , V_67 ;
struct V_1 * V_2 ;
if ( ! V_65 ) {
F_12 ( L_27 ) ;
return V_68 ;
}
V_2 = V_65 ;
V_66 = F_34 ( V_2 -> V_22 + V_47 ) ;
if ( ! ( V_66 & V_69 ) )
return V_68 ;
V_66 = V_70 ;
do {
if ( V_66 & V_70 ) {
V_67 = F_34 ( V_2 -> V_22 + V_71 ) ;
F_19 ( V_67 ^ V_72 ,
V_2 -> V_22 + V_71 ) ;
F_19 ( V_67 , V_2 -> V_22 + V_71 ) ;
F_35 ( V_27 , V_65 ) ;
V_66 = F_7 ( V_73 ) ;
} else
return V_74 ;
} while ( 1 );
return V_74 ;
}
static unsigned short V_54 ( struct V_1 * V_2 )
{
unsigned char V_67 ;
struct V_8 * V_9 = F_27 ( V_2 ) ;
V_67 = F_34 ( V_2 -> V_22 + V_71 ) ;
if( V_9 -> V_59 == V_60 )
V_67 |= V_75 ;
else if ( V_67 & V_75 )
V_67 ^= V_75 ;
F_19 ( V_67 , V_2 -> V_22 + V_71 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_76 )
{
static int V_67 ;
V_67 = F_34 ( V_2 -> V_22 + V_71 ) ;
if ( ( V_76 == 0 ) && ( V_67 & V_77 ) ) {
F_19 ( V_67 ^ V_77 ,
V_2 -> V_22 + V_71 ) ;
}
else if ( V_76 == 1 ) {
F_19 ( V_67 | V_77 ,
V_2 -> V_22 + V_71 ) ;
}
V_67 = F_34 ( V_2 -> V_22 + V_71 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_5 )
{
unsigned int V_78 ;
V_78 = F_34 ( V_2 -> V_22 + V_47 ) ;
if ( ( V_5 == 0 ) && ( V_78 & V_79 ) ) {
F_19 ( V_78 ^ V_79 ,
V_2 -> V_22 + V_47 ) ;
} else if ( V_5 == 1 ) {
F_19 ( V_78 | V_79 ,
V_2 -> V_22 + V_47 ) ;
}
V_78 = F_34 ( V_2 -> V_22 + V_47 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_5 )
{
unsigned int V_67 ;
V_67 = F_34 ( V_2 -> V_22 + V_71 ) ;
if ( ( V_5 == 0 ) && ( V_67 & V_72 ) ) {
F_19 ( V_67 ^ V_72 ,
V_2 -> V_22 + V_71 ) ;
} else if ( V_5 == 1 ) {
F_19 ( V_67 | V_72 ,
V_2 -> V_22 + V_71 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , int type )
{
F_19 ( ( type == 0 ) ? V_80 : V_81 ,
V_2 -> V_22 + V_82 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_19 ( 0 , V_2 -> V_22 + V_71 ) ;
F_37 ( 100 ) ;
F_19 ( V_83 , V_2 -> V_22 + V_71 ) ;
F_20 ( V_2 , 1 ) ;
F_36 ( V_2 , 1 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_36 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
unsigned long V_84 ;
unsigned char V_78 , V_67 , V_85 , V_86 ;
V_84 = V_2 -> V_22 ;
V_78 = F_34 ( V_84 + V_47 ) ;
V_67 = F_34 ( V_84 + V_71 ) ;
V_85 = V_78 & ~ ( V_87 + V_79 ) ;
F_19 ( V_85 , V_84 + V_47 ) ;
V_11 -> V_39 = F_34 ( V_84 + V_88 ) ;
V_11 -> V_41 = F_34 ( V_84 + V_89 ) ;
V_11 -> V_43 = F_34 ( V_84 + V_90 ) ;
F_19 ( V_85 | V_87 , V_84 + V_47 ) ;
V_2 -> V_91 = 6 ;
for ( V_86 = 0 ; V_86 < 6 ; V_86 ++ )
V_2 -> V_51 [ V_86 ] = F_34 ( V_84 + V_92 + V_86 ) ;
F_19 ( V_78 , V_84 + V_47 ) ;
F_19 ( V_67 , V_84 + V_71 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int V_50 ( char * V_93 , int V_32 , void * V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
struct V_8 * V_9 = F_27 ( V_2 ) ;
struct V_10 * V_95 = V_9 -> V_64 ;
int V_96 = 0 ;
V_96 += sprintf ( V_93 + V_96 , L_28 ) ;
if ( V_95 ) {
V_96 += sprintf ( V_93 + V_96 , L_29 , V_95 -> V_43 ) ;
V_96 += sprintf ( V_93 + V_96 , L_30 , V_95 -> V_44 ) ;
V_96 += sprintf ( V_93 + V_96 , L_31 , ( V_95 -> V_38 ) ? L_13 : L_14 ) ;
V_96 += sprintf ( V_93 + V_96 , L_32 , ( V_95 -> V_37 ) ? 16 : 4 ) ;
V_96 += sprintf ( V_93 + V_96 , L_33 , ( V_9 -> V_59 == V_60 ) ? 16 : 4 ) ;
V_96 += sprintf ( V_93 + V_96 , L_34 , V_2 -> V_28 ) ;
V_96 += sprintf ( V_93 + V_96 , L_35 , V_2 -> V_22 ) ;
V_96 += sprintf ( V_93 + V_96 , L_36 , V_2 -> V_27 ) ;
V_96 += sprintf ( V_93 + V_96 , L_37 , V_95 -> V_34 ) ;
V_96 += sprintf ( V_93 + V_96 , L_38 ) ;
switch( V_95 -> V_35 ) {
case 0 : V_96 += sprintf ( V_93 + V_96 , L_17 ) ; break;
case 1 : V_96 += sprintf ( V_93 + V_96 , L_18 ) ; break;
case 2 : V_96 += sprintf ( V_93 + V_96 , L_19 ) ; break;
case 3 : V_96 += sprintf ( V_93 + V_96 , L_20 ) ; break;
}
V_96 += sprintf ( V_93 + V_96 , L_21 , ( V_95 -> V_36 ) ? L_22 : L_23 ) ;
V_96 += sprintf ( V_93 + V_96 , L_39 ,
V_2 -> V_51 ) ;
} else
V_96 += sprintf ( V_93 + V_96 , L_40 ) ;
return V_96 ;
}
static int T_3 F_43 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_45 ( ! V_2 ) ;
V_9 = F_27 ( V_2 ) ;
V_11 = V_9 -> V_64 ;
F_32 ( V_11 ) ;
V_9 -> V_64 = NULL ;
F_46 ( V_2 ) ;
F_31 ( V_2 -> V_22 - V_33 , V_30 ) ;
F_30 ( V_2 -> V_27 , V_2 ) ;
F_47 ( V_2 ) ;
F_33 ( V_2 ) ;
F_28 ( V_6 , NULL ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
V_19 = V_97 ;
V_19 . V_98 = F_39 ;
V_19 . V_99 = F_41 ;
return F_49 ( & V_100 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_100 ) ;
}
