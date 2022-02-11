static void F_1 ( struct V_1 * V_2 , char V_3 ,
char V_4 , char V_5 , char V_6 , char V_7 ,
char V_8 , char V_9 )
{
memset ( V_2 , 0 , sizeof( struct V_10 ) ) ;
V_2 -> V_11 . V_12 = 0x55 ;
V_2 -> V_11 . V_13 = 0xaa ;
V_2 -> V_11 . V_3 = V_3 ;
V_2 -> V_11 . V_4 = V_4 ;
V_2 -> V_11 . V_5 = V_5 ;
V_2 -> V_11 . V_6 = V_6 ;
V_2 -> V_11 . V_7 = V_7 ;
V_2 -> V_11 . V_8 = V_8 ;
V_2 -> V_11 . V_9 = V_9 ;
}
static void F_2 ( struct V_14 * V_15 , T_1 V_16 )
{
int V_17 ;
int V_18 ;
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 ) {
F_4 ( & V_15 -> V_20 -> V_21 , L_1 ) ;
return;
}
F_1 ( V_2 , 0x20 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ) ;
if ( V_16 )
V_2 -> V_22 [ 0 ] = 0xaf ;
else
V_2 -> V_22 [ 0 ] = 0xae ;
V_17 = F_5 ( V_15 -> V_20 ,
F_6 ( V_15 -> V_20 , 2 ) ,
V_2 ,
sizeof( struct V_10 ) + 1 ,
& V_18 ,
- 1 ) ;
if ( V_17 )
F_7 ( & V_15 -> V_20 -> V_21 , L_2 , V_17 ) ;
V_15 -> V_23 = V_16 ;
F_8 ( V_2 ) ;
}
static T_2 F_9 ( struct V_24 * V_21 , struct V_25 * V_26 ,
const char * V_27 , T_3 V_28 )
{
struct V_29 * V_30 = F_10 ( V_21 ) ;
struct V_14 * V_15 = F_11 ( V_30 ) ;
unsigned long V_31 ;
if ( F_12 ( V_27 , 10 , & V_31 ) )
return - V_32 ;
F_2 ( V_15 , V_31 ) ;
return V_28 ;
}
static T_2 F_13 ( struct V_24 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 , T_3 V_28 )
{
struct V_14 * V_15 =
(struct V_14 * ) F_14 ( V_24 ) ;
unsigned long V_31 ;
if ( F_12 ( V_27 , 10 , & V_31 ) )
return - V_32 ;
F_2 ( V_15 , V_31 ) ;
return V_28 ;
}
static T_2 F_15 ( struct V_24 * V_21 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_29 * V_30 = F_10 ( V_21 ) ;
struct V_14 * V_15 = F_11 ( V_30 ) ;
return sprintf ( V_27 , L_3 , V_15 -> V_23 ) ;
}
static T_2 F_16 ( struct V_24 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_14 * V_15 =
(struct V_14 * ) F_14 ( V_24 ) ;
return sprintf ( V_27 , L_3 , V_15 -> V_23 ) ;
}
static void F_17 ( struct V_33 * V_20 ,
struct V_1 * V_2 ,
char * V_27 , T_1 V_34 , T_3 V_35 )
{
T_3 V_36 ;
int V_18 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
int V_17 ;
switch ( V_34 ) {
case V_37 :
F_1 ( V_2 , 0x40 , 0x80 , V_35 ,
V_36 + 1 , 0x00 , 0x01 , 0xff ) ;
break;
case V_38 :
F_1 ( V_2 , 0x10 + V_36 , 0x80 , 0x01 ,
0x01 , 0x00 , 0x01 , 0x00 ) ;
break;
case V_39 :
F_1 ( V_2 , 0x10 + V_36 , 0x80 , 0x01 ,
0x01 , 0x00 , 0x00 , 0xff ) ;
break;
}
memcpy ( V_2 -> V_22 , V_27 + ( V_40 * V_36 ) ,
V_40 ) ;
V_17 = F_5 ( V_20 , F_18 ( V_20 , 2 ) ,
V_2 , sizeof( struct V_1 ) ,
& V_18 , - 1 ) ;
if ( V_17 )
F_7 ( & V_20 -> V_21 , L_2 , V_17 ) ;
}
}
static void F_19 ( struct V_33 * V_20 ,
struct V_1 * V_2 ,
T_3 V_41 , T_3 V_42 , char * V_27 , T_1 V_43 ,
T_1 V_44 , T_1 V_45 , T_1 V_46 , T_1 V_47 ,
T_1 V_48 ) {
int V_17 ;
int V_18 ;
F_1 ( V_2 , V_43 , V_44 , V_45 , V_46 , V_47 , V_48 , 0x00 ) ;
memcpy ( V_2 -> V_22 , V_27 + V_41 , V_42 ) ;
V_17 = F_5 ( V_20 ,
F_18 ( V_20 , 2 ) ,
V_2 ,
sizeof( struct V_1 ) ,
& V_18 ,
- 1 ) ;
if ( V_17 )
F_7 ( & V_20 -> V_21 , L_2 , V_17 ) ;
}
static void F_20 ( struct V_33 * V_20 ,
struct V_1 * V_2 , char * V_27 )
{
F_19 ( V_20 , V_2 , 0 , 0x100 , V_27 ,
0x10 , 0x00 , 0x02 , 0x01 , 0x00 , 0x01 ) ;
F_19 ( V_20 , V_2 , 0x100 , 0x080 , V_27 ,
0x10 , 0x00 , 0x02 , 0x02 , 0x80 , 0x00 ) ;
F_19 ( V_20 , V_2 , 0x180 , 0x100 , V_27 ,
0x11 , 0x00 , 0x03 , 0x01 , 0x00 , 0x01 ) ;
F_19 ( V_20 , V_2 , 0x280 , 0x100 , V_27 ,
0x11 , 0x00 , 0x03 , 0x02 , 0x00 , 0x01 ) ;
F_19 ( V_20 , V_2 , 0x380 , 0x080 , V_27 ,
0x11 , 0x00 , 0x03 , 0x03 , 0x80 , 0x00 ) ;
}
static void F_21 ( struct V_14 * V_15 )
{
T_3 V_49 = V_15 -> V_50 / V_40 ;
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 ) {
F_4 ( & V_15 -> V_20 -> V_21 , L_1 ) ;
return;
}
if ( V_15 -> V_51 == V_52 ) {
if ( V_15 -> V_53 == V_37 )
F_17 ( V_15 -> V_20 , V_2 , V_15 -> V_27 ,
V_38 , 2 ) ;
if ( V_15 -> V_53 != V_37 && V_49 > 2 )
V_49 = 2 ;
F_17 ( V_15 -> V_20 , V_2 , V_15 -> V_27 ,
V_15 -> V_53 , V_49 ) ;
} else if ( V_15 -> V_51 == V_54 ) {
F_20 ( V_15 -> V_20 , V_2 , V_15 -> V_27 ) ;
}
F_8 ( V_2 ) ;
}
static int F_22 ( struct V_14 * V_15 , T_1 V_55 , T_3 V_28 )
{
V_15 -> V_56 = V_55 ;
if ( V_55 == 0 ) {
V_15 -> V_57 += V_28 ;
return 0 ;
}
while ( V_28 -- > 0 ) {
T_3 V_58 = V_15 -> V_57 % V_15 -> V_59 ;
T_3 V_60 = V_15 -> V_57 / V_15 -> V_59 ;
T_3 V_36 ;
V_58 += V_15 -> V_61 ;
V_60 += V_15 -> V_62 ;
switch ( V_15 -> V_51 ) {
case V_52 :
V_36 = ( V_58 / V_15 -> V_63 ) * 640 +
V_15 -> V_63 - 1 - V_58 +
( V_60 / 8 ) * V_15 -> V_63 ;
break;
case V_54 :
V_36 = ( V_15 -> V_63 - 1 - V_58 ) / 8 + V_60 * V_15 -> V_63 / 8 ;
break;
default:
V_36 = 0 ;
F_23 ( V_64 L_4 ,
V_15 -> V_51 ) ;
break;
}
if ( V_36 >= V_15 -> V_50 ) {
F_23 ( V_64 L_5
L_6 ,
( int ) V_15 -> V_57 , ( int ) V_15 -> V_50 ,
( int ) V_36 , ( int ) V_58 , ( int ) V_60 ) ;
return - V_65 ;
}
switch ( V_15 -> V_51 ) {
case V_52 :
V_15 -> V_27 [ V_36 ] &= ~ ( 1 << ( V_60 % 8 ) ) ;
break;
case V_54 :
V_15 -> V_27 [ V_36 ] &= ~ ( 1 << ( V_58 % 8 ) ) ;
break;
default:
;
}
V_15 -> V_57 ++ ;
}
return 0 ;
}
static T_2 F_24 ( struct V_14 * V_15 ,
const char * V_27 , T_3 V_28 )
{
T_3 V_66 = 0 , V_67 ;
if ( V_28 < 1 )
return 0 ;
if ( tolower ( V_27 [ 0 ] ) == 'b' ) {
T_3 V_36 ;
V_15 -> V_50 = ( V_15 -> V_63 * V_68 ) / 8 ;
F_8 ( V_15 -> V_27 ) ;
V_15 -> V_27 = F_25 ( V_15 -> V_50 , V_19 ) ;
if ( V_15 -> V_27 == NULL ) {
V_15 -> V_50 = 0 ;
F_23 ( V_64 L_7 ) ;
return - V_69 ;
}
memset ( V_15 -> V_27 , 0xff , V_15 -> V_50 ) ;
for ( V_36 = 1 ; V_36 < V_28 && V_36 <= 32 * 32 ; V_36 ++ ) {
V_15 -> V_27 [ V_36 - 1 ] = V_27 [ V_36 ] ;
V_15 -> V_57 = V_36 - 1 ;
}
V_15 -> V_59 = V_15 -> V_63 / 8 ;
V_15 -> V_70 = V_68 ;
V_15 -> V_61 = 0 ;
V_15 -> V_62 = 0 ;
V_15 -> V_56 = 0 ;
F_21 ( V_15 ) ;
return V_28 ;
}
if ( V_27 [ 0 ] == '<' ) {
T_3 V_36 ;
T_3 V_71 = 0 , V_72 = 0 ;
T_3 V_73 , V_74 ;
if ( V_28 < 10 || V_27 [ 2 ] != ':' )
goto V_75;
switch ( tolower ( V_27 [ 1 ] ) ) {
case V_38 :
case V_37 :
case V_39 :
V_15 -> V_53 = V_27 [ 1 ] ;
break;
default:
F_23 ( V_64 L_8 ,
V_27 [ 1 ] ) ;
return - V_65 ;
break;
}
for ( V_36 = 3 ; V_36 < V_28 ; ++ V_36 ) {
if ( V_27 [ V_36 ] >= '0' && V_27 [ V_36 ] <= '9' ) {
V_71 = 10 * V_71 + ( V_27 [ V_36 ] - '0' ) ;
if ( V_71 > V_76 )
goto V_77;
} else if ( tolower ( V_27 [ V_36 ] ) == 'x' ) {
break;
} else {
goto V_77;
}
}
for ( ++ V_36 ; V_36 < V_28 ; ++ V_36 ) {
if ( V_27 [ V_36 ] >= '0' && V_27 [ V_36 ] <= '9' ) {
V_72 = 10 * V_72 + ( V_27 [ V_36 ] - '0' ) ;
if ( V_72 > V_68 )
goto V_78;
} else if ( tolower ( V_27 [ V_36 ] ) == '>' ) {
break;
} else {
goto V_78;
}
}
if ( V_71 < 1 || V_71 > V_76 )
goto V_77;
if ( V_72 < 1 || V_72 > V_68 )
goto V_78;
if ( V_36 >= V_28 || V_27 [ V_36 ] != '>' )
goto V_75;
V_66 = V_36 + 1 ;
if ( V_71 % ( V_15 -> V_63 ) != 0 )
V_73 = ( V_71 / ( V_15 -> V_63 ) + 1 ) * ( V_15 -> V_63 ) ;
else
V_73 = V_71 ;
if ( V_72 < V_68 )
V_74 = V_68 ;
else
V_74 = V_72 ;
V_15 -> V_50 = V_73 * V_74 / 8 ;
F_8 ( V_15 -> V_27 ) ;
V_15 -> V_27 = F_25 ( V_15 -> V_50 , V_19 ) ;
if ( V_15 -> V_27 == NULL ) {
V_15 -> V_50 = 0 ;
F_23 ( V_64 L_7 ) ;
return - V_69 ;
}
memset ( V_15 -> V_27 , 0xff , V_15 -> V_50 ) ;
V_15 -> V_57 = 0 ;
V_15 -> V_59 = V_71 ;
V_15 -> V_70 = V_72 ;
V_15 -> V_61 = 0 ;
V_15 -> V_62 = 0 ;
V_15 -> V_56 = 0 ;
if ( V_15 -> V_53 == V_39 ) {
if ( V_72 < V_68 / 2 )
V_15 -> V_62 = ( V_68 / 2 - V_72 ) / 2 ;
} else {
if ( V_72 < V_68 )
V_15 -> V_62 = ( V_68 - V_72 ) / 2 ;
}
if ( V_71 < ( V_15 -> V_63 ) )
V_15 -> V_61 = ( ( V_15 -> V_63 ) - V_71 ) / 2 ;
}
V_67 = V_15 -> V_59 * V_15 -> V_70 ;
while ( V_66 < V_28 && V_15 -> V_57 < V_67 ) {
int V_79 = 0 ;
if ( V_27 [ V_66 ] == '1' || V_27 [ V_66 ] == '#' ) {
V_79 = F_22 ( V_15 , 1 , 1 ) ;
if ( V_79 < 0 )
return V_79 ;
} else if ( V_27 [ V_66 ] == '0' || V_27 [ V_66 ] == ' ' ) {
V_79 = F_22 ( V_15 , 0 , 1 ) ;
if ( V_79 < 0 )
return V_79 ;
} else if ( V_27 [ V_66 ] == '\n' ) {
if ( V_15 -> V_57 % V_15 -> V_59 != 0 )
V_79 = F_22 ( V_15 , V_15 -> V_56 ,
V_15 -> V_59 -
( V_15 -> V_57 %
V_15 -> V_59 ) ) ;
if ( V_79 < 0 )
return V_79 ;
}
V_66 ++ ;
}
if ( V_15 -> V_57 >= V_67 )
F_21 ( V_15 ) ;
return V_28 ;
V_77:
F_23 ( V_64 L_9 ) ;
return - V_65 ;
V_78:
F_23 ( V_64 L_10 ) ;
return - V_65 ;
V_75:
F_23 ( V_64 L_11 ) ;
return - V_65 ;
}
static T_2 F_26 ( struct V_24 * V_21 , struct V_25 * V_26 ,
const char * V_27 , T_3 V_28 )
{
struct V_29 * V_30 = F_10 ( V_21 ) ;
return F_24 ( F_11 ( V_30 ) , V_27 , V_28 ) ;
}
static T_2 F_27 ( struct V_24 * V_24 ,
struct V_25 * V_26 ,
const char * V_27 , T_3 V_28 )
{
return F_24 ( (struct V_14 * )
F_14 ( V_24 ) , V_27 , V_28 ) ;
}
static int F_28 ( struct V_29 * V_80 ,
const struct V_81 * V_82 )
{
struct V_33 * V_20 = F_29 ( V_80 ) ;
struct V_14 * V_15 = NULL ;
int V_17 = - V_69 ;
T_4 V_63 = 0 ;
enum V_83 V_51 = V_84 ;
const struct V_85 * V_86 = V_87 ;
const char * V_88 = NULL ;
if ( ! V_82 ) {
F_4 ( & V_80 -> V_21 , L_12 ) ;
return - V_89 ;
}
for (; V_86 -> V_90 ; V_86 ++ ) {
if ( V_86 -> V_90 == V_82 -> V_90
&& V_86 -> V_91 == V_82 -> V_91 ) {
V_63 = V_86 -> V_92 ;
V_88 = V_86 -> V_93 ;
V_51 = V_86 -> V_94 ;
break;
}
}
if ( ! V_88 || V_63 < 1 || V_51 == V_84 ) {
F_4 ( & V_80 -> V_21 ,
L_13 ) ;
return - V_89 ;
}
V_15 = F_3 ( sizeof( struct V_14 ) , V_19 ) ;
if ( V_15 == NULL ) {
F_4 ( & V_80 -> V_21 , L_14 ) ;
return - V_69 ;
}
V_15 -> V_20 = F_30 ( V_20 ) ;
V_15 -> V_53 = V_38 ;
V_15 -> V_63 = V_63 ;
V_15 -> V_51 = V_51 ;
V_15 -> V_70 = 0 ;
V_15 -> V_59 = 0 ;
V_15 -> V_61 = 0 ;
V_15 -> V_62 = 0 ;
V_15 -> V_57 = 0 ;
V_15 -> V_50 = 0 ;
V_15 -> V_56 = 0 ;
V_15 -> V_27 = NULL ;
V_15 -> V_23 = 1 ;
V_15 -> V_21 = NULL ;
F_31 ( V_80 , V_15 ) ;
V_17 = F_32 ( & V_80 -> V_21 ,
& F_33 ( V_23 ) ) ;
if ( V_17 )
goto V_95;
V_17 = F_32 ( & V_80 -> V_21 ,
& F_33 ( V_96 ) ) ;
if ( V_17 )
goto V_95;
V_15 -> V_21 = F_34 ( V_97 , & V_80 -> V_21 , F_35 ( 0 , 0 ) ,
NULL , L_15 , ++ V_98 ) ;
if ( F_36 ( V_15 -> V_21 ) ) {
V_17 = F_37 ( V_15 -> V_21 ) ;
goto V_95;
}
F_38 ( V_15 -> V_21 , V_15 ) ;
V_17 = F_32 ( V_15 -> V_21 , & V_99 ) ;
if ( V_17 )
goto V_100;
V_17 = F_32 ( V_15 -> V_21 , & V_101 ) ;
if ( V_17 )
goto V_102;
F_39 ( & V_80 -> V_21 ,
L_16 ,
V_88 , V_15 -> V_63 , V_15 -> V_51 ) ;
if ( V_103 )
F_2 ( V_15 , 0 ) ;
return 0 ;
V_102:
F_40 ( V_15 -> V_21 , & V_101 ) ;
V_100:
F_40 ( V_15 -> V_21 , & V_99 ) ;
F_41 ( V_15 -> V_21 ) ;
V_95:
F_40 ( & V_80 -> V_21 , & F_33 ( V_23 ) ) ;
F_40 ( & V_80 -> V_21 , & F_33 ( V_96 ) ) ;
F_31 ( V_80 , NULL ) ;
F_42 ( V_15 -> V_20 ) ;
F_8 ( V_15 ) ;
return V_17 ;
}
static void F_43 ( struct V_29 * V_80 )
{
struct V_14 * V_15 ;
V_15 = F_11 ( V_80 ) ;
F_31 ( V_80 , NULL ) ;
F_40 ( V_15 -> V_21 , & V_101 ) ;
F_40 ( V_15 -> V_21 , & V_99 ) ;
F_41 ( V_15 -> V_21 ) ;
F_40 ( & V_80 -> V_21 , & F_33 ( V_96 ) ) ;
F_40 ( & V_80 -> V_21 , & F_33 ( V_23 ) ) ;
F_42 ( V_15 -> V_20 ) ;
F_8 ( V_15 -> V_27 ) ;
F_8 ( V_15 ) ;
F_39 ( & V_80 -> V_21 , L_17 ) ;
}
static int T_5 F_44 ( void )
{
int V_17 = 0 ;
V_97 = F_45 ( V_104 , V_105 ) ;
if ( F_36 ( V_97 ) ) {
F_46 ( L_18 V_105 L_19 ) ;
return F_37 ( V_97 ) ;
}
V_17 = F_47 ( V_97 , & V_106 . V_26 ) ;
if ( V_17 ) {
F_46 ( L_20 ) ;
goto error;
}
V_17 = F_48 ( & V_107 ) ;
if ( V_17 ) {
F_46 ( L_21 , V_17 ) ;
goto error;
}
return V_17 ;
error:
F_49 ( V_97 ) ;
return V_17 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_107 ) ;
F_52 ( V_97 , & V_106 . V_26 ) ;
F_49 ( V_97 ) ;
}
