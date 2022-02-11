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
int V_19 ;
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_20 ) ;
if ( ! V_2 ) {
F_4 ( & V_15 -> V_21 -> V_22 , L_1 ) ;
return;
}
F_1 ( V_2 , 0x20 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 ) ;
if ( V_16 )
V_2 -> V_23 [ 0 ] = 0xaf ;
else
V_2 -> V_23 [ 0 ] = 0xae ;
for ( V_17 = 0 ; V_17 < 1 ; V_17 ++ ) {
V_18 = F_5 ( V_15 -> V_21 ,
F_6 ( V_15 -> V_21 , 2 ) ,
V_2 ,
sizeof( struct V_10 ) + 1 ,
& V_19 ,
- 1 ) ;
if ( V_18 )
F_7 ( & V_15 -> V_21 -> V_22 , L_2 , V_18 ) ;
}
V_15 -> V_24 = V_16 ;
F_8 ( V_2 ) ;
}
static T_2 F_9 ( struct V_25 * V_22 , struct V_26 * V_27 ,
const char * V_28 , T_3 V_29 )
{
struct V_30 * V_31 = F_10 ( V_22 ) ;
struct V_14 * V_15 = F_11 ( V_31 ) ;
unsigned long V_32 ;
if ( F_12 ( V_28 , 10 , & V_32 ) )
return - V_33 ;
F_2 ( V_15 , V_32 ) ;
return V_29 ;
}
static T_2 F_13 ( struct V_25 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_3 V_29 )
{
struct V_14 * V_15 =
(struct V_14 * ) F_14 ( V_25 ) ;
unsigned long V_32 ;
if ( F_12 ( V_28 , 10 , & V_32 ) )
return - V_33 ;
F_2 ( V_15 , V_32 ) ;
return V_29 ;
}
static T_2 F_15 ( struct V_25 * V_22 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_30 * V_31 = F_10 ( V_22 ) ;
struct V_14 * V_15 = F_11 ( V_31 ) ;
return sprintf ( V_28 , L_3 , V_15 -> V_24 ) ;
}
static T_2 F_16 ( struct V_25 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_14 * V_15 =
(struct V_14 * ) F_14 ( V_25 ) ;
return sprintf ( V_28 , L_3 , V_15 -> V_24 ) ;
}
static void F_17 ( struct V_34 * V_21 ,
struct V_1 * V_2 ,
char * V_28 , T_1 V_35 , T_3 V_36 )
{
T_3 V_37 ;
int V_19 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
int V_18 ;
switch ( V_35 ) {
case V_38 :
F_1 ( V_2 , 0x40 , 0x80 , V_36 ,
V_37 + 1 , 0x00 , 0x01 , 0xff ) ;
break;
case V_39 :
F_1 ( V_2 , 0x10 + V_37 , 0x80 , 0x01 ,
0x01 , 0x00 , 0x01 , 0x00 ) ;
break;
case V_40 :
F_1 ( V_2 , 0x10 + V_37 , 0x80 , 0x01 ,
0x01 , 0x00 , 0x00 , 0xff ) ;
break;
}
memcpy ( V_2 -> V_23 , V_28 + ( V_41 * V_37 ) ,
V_41 ) ;
V_18 = F_5 ( V_21 , F_18 ( V_21 , 2 ) ,
V_2 , sizeof( struct V_1 ) ,
& V_19 , - 1 ) ;
if ( V_18 )
F_7 ( & V_21 -> V_22 , L_2 , V_18 ) ;
}
}
static void F_19 ( struct V_34 * V_21 ,
struct V_1 * V_2 ,
T_3 V_42 , T_3 V_43 , char * V_28 , T_1 V_44 ,
T_1 V_45 , T_1 V_46 , T_1 V_47 , T_1 V_48 ,
T_1 V_49 ) {
int V_18 ;
int V_19 ;
F_1 ( V_2 , V_44 , V_45 , V_46 , V_47 , V_48 , V_49 , 0x00 ) ;
memcpy ( V_2 -> V_23 , V_28 + V_42 , V_43 ) ;
V_18 = F_5 ( V_21 ,
F_18 ( V_21 , 2 ) ,
V_2 ,
sizeof( struct V_1 ) ,
& V_19 ,
- 1 ) ;
if ( V_18 )
F_7 ( & V_21 -> V_22 , L_2 , V_18 ) ;
}
static void F_20 ( struct V_34 * V_21 ,
struct V_1 * V_2 , char * V_28 )
{
F_19 ( V_21 , V_2 , 0 , 0x100 , V_28 ,
0x10 , 0x00 , 0x02 , 0x01 , 0x00 , 0x01 ) ;
F_19 ( V_21 , V_2 , 0x100 , 0x080 , V_28 ,
0x10 , 0x00 , 0x02 , 0x02 , 0x80 , 0x00 ) ;
F_19 ( V_21 , V_2 , 0x180 , 0x100 , V_28 ,
0x11 , 0x00 , 0x03 , 0x01 , 0x00 , 0x01 ) ;
F_19 ( V_21 , V_2 , 0x280 , 0x100 , V_28 ,
0x11 , 0x00 , 0x03 , 0x02 , 0x00 , 0x01 ) ;
F_19 ( V_21 , V_2 , 0x380 , 0x080 , V_28 ,
0x11 , 0x00 , 0x03 , 0x03 , 0x80 , 0x00 ) ;
}
static void F_21 ( struct V_14 * V_15 )
{
T_3 V_50 = V_15 -> V_51 / V_41 ;
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_20 ) ;
if ( ! V_2 ) {
F_4 ( & V_15 -> V_21 -> V_22 , L_1 ) ;
return;
}
if ( V_15 -> V_52 == V_53 ) {
if ( V_15 -> V_54 == V_38 )
F_17 ( V_15 -> V_21 , V_2 , V_15 -> V_28 ,
V_39 , 2 ) ;
if ( V_15 -> V_54 != V_38 && V_50 > 2 )
V_50 = 2 ;
F_17 ( V_15 -> V_21 , V_2 , V_15 -> V_28 ,
V_15 -> V_54 , V_50 ) ;
} else if ( V_15 -> V_52 == V_55 ) {
F_20 ( V_15 -> V_21 , V_2 , V_15 -> V_28 ) ;
}
F_8 ( V_2 ) ;
}
static int F_22 ( struct V_14 * V_15 , T_1 V_56 , T_3 V_29 )
{
V_15 -> V_57 = V_56 ;
if ( V_56 == 0 ) {
V_15 -> V_58 += V_29 ;
return 0 ;
}
while ( V_29 -- > 0 ) {
T_3 V_59 = V_15 -> V_58 % V_15 -> V_60 ;
T_3 V_61 = V_15 -> V_58 / V_15 -> V_60 ;
T_3 V_37 ;
V_59 += V_15 -> V_62 ;
V_61 += V_15 -> V_63 ;
switch ( V_15 -> V_52 ) {
case V_53 :
V_37 = ( V_59 / V_15 -> V_64 ) * 640 +
V_15 -> V_64 - 1 - V_59 +
( V_61 / 8 ) * V_15 -> V_64 ;
break;
case V_55 :
V_37 = ( V_15 -> V_64 - 1 - V_59 ) / 8 + V_61 * V_15 -> V_64 / 8 ;
break;
default:
V_37 = 0 ;
F_23 ( V_65 L_4 ,
V_15 -> V_52 ) ;
break;
}
if ( V_37 >= V_15 -> V_51 ) {
F_23 ( V_65 L_5
L_6 ,
( int ) V_15 -> V_58 , ( int ) V_15 -> V_51 ,
( int ) V_37 , ( int ) V_59 , ( int ) V_61 ) ;
return - V_66 ;
}
switch ( V_15 -> V_52 ) {
case V_53 :
V_15 -> V_28 [ V_37 ] &= ~ ( 1 << ( V_61 % 8 ) ) ;
break;
case V_55 :
V_15 -> V_28 [ V_37 ] &= ~ ( 1 << ( V_59 % 8 ) ) ;
break;
default:
;
}
V_15 -> V_58 ++ ;
}
return 0 ;
}
static T_2 F_24 ( struct V_14 * V_15 ,
const char * V_28 , T_3 V_29 )
{
T_3 V_67 = 0 , V_68 ;
if ( V_29 < 1 )
return 0 ;
if ( tolower ( V_28 [ 0 ] ) == 'b' ) {
T_3 V_37 ;
V_15 -> V_51 = ( V_15 -> V_64 * V_69 ) / 8 ;
F_8 ( V_15 -> V_28 ) ;
V_15 -> V_28 = F_25 ( V_15 -> V_51 , V_20 ) ;
if ( V_15 -> V_28 == NULL ) {
V_15 -> V_51 = 0 ;
F_23 ( V_65 L_7 ) ;
return - V_70 ;
}
memset ( V_15 -> V_28 , 0xff , V_15 -> V_51 ) ;
for ( V_37 = 1 ; V_37 < V_29 && V_37 <= 32 * 32 ; V_37 ++ ) {
V_15 -> V_28 [ V_37 - 1 ] = V_28 [ V_37 ] ;
V_15 -> V_58 = V_37 - 1 ;
}
V_15 -> V_60 = V_15 -> V_64 / 8 ;
V_15 -> V_71 = V_69 ;
V_15 -> V_62 = 0 ;
V_15 -> V_63 = 0 ;
V_15 -> V_57 = 0 ;
F_21 ( V_15 ) ;
return V_29 ;
}
if ( V_28 [ 0 ] == '<' ) {
T_3 V_37 ;
T_3 V_72 = 0 , V_73 = 0 ;
T_3 V_74 , V_75 ;
if ( V_29 < 10 || V_28 [ 2 ] != ':' )
goto V_76;
switch ( tolower ( V_28 [ 1 ] ) ) {
case V_39 :
case V_38 :
case V_40 :
V_15 -> V_54 = V_28 [ 1 ] ;
break;
default:
F_23 ( V_65 L_8 ,
V_28 [ 1 ] ) ;
return - V_66 ;
break;
}
for ( V_37 = 3 ; V_37 < V_29 ; ++ V_37 ) {
if ( V_28 [ V_37 ] >= '0' && V_28 [ V_37 ] <= '9' ) {
V_72 = 10 * V_72 + ( V_28 [ V_37 ] - '0' ) ;
if ( V_72 > V_77 )
goto V_78;
} else if ( tolower ( V_28 [ V_37 ] ) == 'x' ) {
break;
} else {
goto V_78;
}
}
for ( ++ V_37 ; V_37 < V_29 ; ++ V_37 ) {
if ( V_28 [ V_37 ] >= '0' && V_28 [ V_37 ] <= '9' ) {
V_73 = 10 * V_73 + ( V_28 [ V_37 ] - '0' ) ;
if ( V_73 > V_69 )
goto V_79;
} else if ( tolower ( V_28 [ V_37 ] ) == '>' ) {
break;
} else {
goto V_79;
}
}
if ( V_72 < 1 || V_72 > V_77 )
goto V_78;
if ( V_73 < 1 || V_73 > V_69 )
goto V_79;
if ( V_37 >= V_29 || V_28 [ V_37 ] != '>' )
goto V_76;
V_67 = V_37 + 1 ;
if ( V_72 % ( V_15 -> V_64 ) != 0 )
V_74 = ( V_72 / ( V_15 -> V_64 ) + 1 ) * ( V_15 -> V_64 ) ;
else
V_74 = V_72 ;
if ( V_73 < V_69 )
V_75 = V_69 ;
else
V_75 = V_73 ;
V_15 -> V_51 = V_74 * V_75 / 8 ;
F_8 ( V_15 -> V_28 ) ;
V_15 -> V_28 = F_25 ( V_15 -> V_51 , V_20 ) ;
if ( V_15 -> V_28 == NULL ) {
V_15 -> V_51 = 0 ;
F_23 ( V_65 L_7 ) ;
return - V_70 ;
}
memset ( V_15 -> V_28 , 0xff , V_15 -> V_51 ) ;
V_15 -> V_58 = 0 ;
V_15 -> V_60 = V_72 ;
V_15 -> V_71 = V_73 ;
V_15 -> V_62 = 0 ;
V_15 -> V_63 = 0 ;
V_15 -> V_57 = 0 ;
if ( V_15 -> V_54 == V_40 ) {
if ( V_73 < V_69 / 2 )
V_15 -> V_63 = ( V_69 / 2 - V_73 ) / 2 ;
} else {
if ( V_73 < V_69 )
V_15 -> V_63 = ( V_69 - V_73 ) / 2 ;
}
if ( V_72 < ( V_15 -> V_64 ) )
V_15 -> V_62 = ( ( V_15 -> V_64 ) - V_72 ) / 2 ;
}
V_68 = V_15 -> V_60 * V_15 -> V_71 ;
while ( V_67 < V_29 && V_15 -> V_58 < V_68 ) {
int V_80 = 0 ;
if ( V_28 [ V_67 ] == '1' || V_28 [ V_67 ] == '#' ) {
V_80 = F_22 ( V_15 , 1 , 1 ) ;
if ( V_80 < 0 )
return V_80 ;
} else if ( V_28 [ V_67 ] == '0' || V_28 [ V_67 ] == ' ' ) {
V_80 = F_22 ( V_15 , 0 , 1 ) ;
if ( V_80 < 0 )
return V_80 ;
} else if ( V_28 [ V_67 ] == '\n' ) {
if ( V_15 -> V_58 % V_15 -> V_60 != 0 )
V_80 = F_22 ( V_15 , V_15 -> V_57 ,
V_15 -> V_60 -
( V_15 -> V_58 %
V_15 -> V_60 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
V_67 ++ ;
}
if ( V_15 -> V_58 >= V_68 )
F_21 ( V_15 ) ;
return V_29 ;
V_78:
F_23 ( V_65 L_9 ) ;
return - V_66 ;
V_79:
F_23 ( V_65 L_10 ) ;
return - V_66 ;
V_76:
F_23 ( V_65 L_11 ) ;
return - V_66 ;
}
static T_2 F_26 ( struct V_25 * V_22 , struct V_26 * V_27 ,
const char * V_28 , T_3 V_29 )
{
struct V_30 * V_31 = F_10 ( V_22 ) ;
return F_24 ( F_11 ( V_31 ) , V_28 , V_29 ) ;
}
static T_2 F_27 ( struct V_25 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_3 V_29 )
{
return F_24 ( (struct V_14 * )
F_14 ( V_25 ) , V_28 , V_29 ) ;
}
static int F_28 ( struct V_30 * V_81 ,
const struct V_82 * V_83 )
{
struct V_34 * V_21 = F_29 ( V_81 ) ;
struct V_14 * V_15 = NULL ;
int V_18 = - V_70 ;
T_4 V_64 = 0 ;
enum V_84 V_52 = V_85 ;
const struct V_86 * V_87 = V_88 ;
const char * V_89 = NULL ;
if ( ! V_83 ) {
F_4 ( & V_81 -> V_22 , L_12 ) ;
return - V_90 ;
}
for (; V_87 -> V_91 ; V_87 ++ ) {
if ( V_87 -> V_91 == V_83 -> V_91
&& V_87 -> V_92 == V_83 -> V_92 ) {
V_64 = V_87 -> V_93 ;
V_89 = V_87 -> V_94 ;
V_52 = V_87 -> V_95 ;
break;
}
}
if ( ! V_89 || V_64 < 1 || V_52 == V_85 ) {
F_4 ( & V_81 -> V_22 ,
L_13 ) ;
return - V_90 ;
}
V_15 = F_3 ( sizeof( struct V_14 ) , V_20 ) ;
if ( V_15 == NULL ) {
F_4 ( & V_81 -> V_22 , L_14 ) ;
return - V_70 ;
}
V_15 -> V_21 = F_30 ( V_21 ) ;
V_15 -> V_54 = V_39 ;
V_15 -> V_64 = V_64 ;
V_15 -> V_52 = V_52 ;
V_15 -> V_71 = 0 ;
V_15 -> V_60 = 0 ;
V_15 -> V_62 = 0 ;
V_15 -> V_63 = 0 ;
V_15 -> V_58 = 0 ;
V_15 -> V_51 = 0 ;
V_15 -> V_57 = 0 ;
V_15 -> V_28 = NULL ;
V_15 -> V_24 = 1 ;
V_15 -> V_22 = NULL ;
F_31 ( V_81 , V_15 ) ;
V_18 = F_32 ( & V_81 -> V_22 ,
& F_33 ( V_24 ) ) ;
if ( V_18 )
goto V_96;
V_18 = F_32 ( & V_81 -> V_22 ,
& F_33 ( V_97 ) ) ;
if ( V_18 )
goto V_96;
V_15 -> V_22 = F_34 ( V_98 , & V_81 -> V_22 , F_35 ( 0 , 0 ) ,
NULL , L_15 , ++ V_99 ) ;
if ( F_36 ( V_15 -> V_22 ) ) {
V_18 = F_37 ( V_15 -> V_22 ) ;
goto V_96;
}
F_38 ( V_15 -> V_22 , V_15 ) ;
V_18 = F_32 ( V_15 -> V_22 , & V_100 ) ;
if ( V_18 )
goto V_101;
V_18 = F_32 ( V_15 -> V_22 , & V_102 ) ;
if ( V_18 )
goto V_103;
F_39 ( & V_81 -> V_22 ,
L_16 ,
V_89 , V_15 -> V_64 , V_15 -> V_52 ) ;
if ( V_104 )
F_2 ( V_15 , 0 ) ;
return 0 ;
V_103:
F_40 ( V_15 -> V_22 , & V_102 ) ;
V_101:
F_40 ( V_15 -> V_22 , & V_100 ) ;
F_41 ( V_15 -> V_22 ) ;
V_96:
F_40 ( & V_81 -> V_22 , & F_33 ( V_24 ) ) ;
F_40 ( & V_81 -> V_22 , & F_33 ( V_97 ) ) ;
F_31 ( V_81 , NULL ) ;
F_42 ( V_15 -> V_21 ) ;
F_8 ( V_15 ) ;
return V_18 ;
}
static void F_43 ( struct V_30 * V_81 )
{
struct V_14 * V_15 ;
V_15 = F_11 ( V_81 ) ;
F_31 ( V_81 , NULL ) ;
F_40 ( V_15 -> V_22 , & V_102 ) ;
F_40 ( V_15 -> V_22 , & V_100 ) ;
F_41 ( V_15 -> V_22 ) ;
F_40 ( & V_81 -> V_22 , & F_33 ( V_97 ) ) ;
F_40 ( & V_81 -> V_22 , & F_33 ( V_24 ) ) ;
F_42 ( V_15 -> V_21 ) ;
F_8 ( V_15 -> V_28 ) ;
F_8 ( V_15 ) ;
F_39 ( & V_81 -> V_22 , L_17 ) ;
}
static int T_5 F_44 ( void )
{
int V_18 = 0 ;
V_98 = F_45 ( V_105 , V_106 ) ;
if ( F_36 ( V_98 ) ) {
F_46 ( L_18 V_106 L_19 ) ;
return F_37 ( V_98 ) ;
}
V_18 = F_47 ( V_98 , & V_107 . V_27 ) ;
if ( V_18 ) {
F_46 ( L_20 ) ;
goto error;
}
V_18 = F_48 ( & V_108 ) ;
if ( V_18 ) {
F_46 ( L_21 , V_18 ) ;
goto error;
}
return V_18 ;
error:
F_49 ( V_98 ) ;
return V_18 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_108 ) ;
F_52 ( V_98 , & V_107 . V_27 ) ;
F_49 ( V_98 ) ;
}
