static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 5 ] ;
int V_9 ;
V_9 = F_3 ( V_7 , V_10 , V_8 ,
sizeof( V_8 ) , V_11 ,
V_12 ) ;
if ( V_9 != sizeof( V_8 ) ) {
F_4 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
V_8 [ 1 ] &= ~ ( 1 << V_3 ) ;
V_8 [ 2 ] = V_13 ;
V_9 = F_3 ( V_7 , V_10 , V_8 , sizeof( V_8 ) ,
V_11 , V_14 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 3 ] ;
int V_9 ;
V_8 [ 0 ] = V_16 ;
V_8 [ 1 ] = V_15 ? 0xff : 0 ;
V_8 [ 2 ] = 1 << V_3 ;
V_9 = F_3 ( V_7 , V_16 , V_8 , sizeof( V_8 ) ,
V_11 , V_14 ) ;
if ( V_9 < 0 )
F_4 ( V_7 , L_3 , V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 2 ] ;
int V_9 ;
V_9 = F_3 ( V_7 , V_17 , V_8 , sizeof( V_8 ) ,
V_11 , V_12 ) ;
if ( V_9 != sizeof( V_8 ) ) {
F_4 ( V_7 , L_4 , V_9 ) ;
return V_9 ;
}
return ( V_8 [ 1 ] >> V_3 ) & 1 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 5 ] ;
int V_9 ;
V_9 = F_3 ( V_7 , V_10 , V_8 ,
sizeof( V_8 ) , V_11 ,
V_12 ) ;
if ( V_9 != sizeof( V_8 ) ) {
F_4 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
V_8 [ 1 ] |= 1 << V_3 ;
V_8 [ 2 ] = V_13 ;
V_9 = F_3 ( V_7 , V_10 , V_8 , sizeof( V_8 ) ,
V_11 , V_14 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
F_5 ( V_2 , V_3 , V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , unsigned char V_18 ,
T_1 * V_19 , T_2 V_20 , unsigned char V_21 )
{
T_1 * V_8 ;
int V_9 ;
V_8 = F_9 ( V_20 , V_22 ) ;
if ( ! V_8 )
return - V_23 ;
V_9 = F_3 ( V_7 , V_18 , V_8 , V_20 ,
V_21 , V_12 ) ;
memcpy ( V_19 , V_8 , V_20 ) ;
F_10 ( V_8 ) ;
return V_9 ;
}
static int F_11 ( struct V_6 * V_7 , T_1 * V_19 , T_2 V_20 ,
unsigned char V_21 )
{
T_1 * V_8 ;
int V_9 ;
V_8 = F_12 ( V_19 , V_20 , V_22 ) ;
if ( ! V_8 )
return - V_23 ;
if ( V_21 == V_24 )
V_9 = F_13 ( V_7 , V_8 , V_20 ) ;
else
V_9 = F_3 ( V_7 , V_8 [ 0 ] , V_8 , V_20 , V_21 ,
V_14 ) ;
F_10 ( V_8 ) ;
return V_9 ;
}
static int F_14 ( struct V_4 * V_5 , T_3 * V_25 )
{
int V_9 = 0 ;
V_9 = F_15 ( V_5 -> V_26 ,
F_16 ( V_25 ) , F_17 ( V_27 ) ) ;
if ( - V_28 == V_9 )
return V_9 ;
if ( ! V_9 )
return - V_29 ;
F_18 ( V_25 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 2 ] ;
int V_9 ;
V_8 [ 0 ] = V_30 ;
V_8 [ 1 ] = 0x01 ;
F_18 ( & V_5 -> V_31 , 0 ) ;
V_9 = F_11 ( V_7 , V_8 , 2 , V_24 ) ;
if ( V_9 < 0 ) {
F_20 ( V_7 , L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_14 ( V_5 , & V_5 -> V_31 ) ;
if ( V_9 )
return V_9 ;
return V_5 -> V_32 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 * V_19 , T_2 V_33 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_34 V_35 ;
int V_9 ;
if ( V_33 > sizeof( V_5 -> V_36 ) )
V_33 = sizeof( V_5 -> V_36 ) ;
V_35 . V_35 = V_37 ;
V_35 . V_38 = F_22 ( V_33 ) ;
F_18 ( & V_5 -> V_39 , 0 ) ;
V_9 = F_11 ( V_7 , & V_35 . V_35 , sizeof( V_35 ) ,
V_24 ) ;
if ( V_9 < 0 ) {
F_20 ( V_7 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_14 ( V_5 , & V_5 -> V_39 ) ;
if ( V_9 )
return V_9 ;
F_23 ( V_7 , L_7 ,
V_5 -> V_40 , V_33 ) ;
if ( V_33 > V_5 -> V_40 )
V_33 = V_5 -> V_40 ;
memcpy ( V_19 , V_5 -> V_36 , V_33 ) ;
return V_5 -> V_40 ;
}
static int F_24 ( void * V_8 , T_1 V_41 , T_4 V_38 )
{
struct V_42 * V_35 = V_8 ;
if ( V_38 < 1 || V_38 > 512 )
return - V_43 ;
V_35 -> V_35 = V_44 ;
V_35 -> V_41 = V_41 << 1 ;
V_35 -> V_38 = F_22 ( V_38 ) ;
return sizeof( * V_35 ) ;
}
static int F_25 ( void * V_8 , T_1 V_41 , T_4 V_38 ,
T_1 V_45 , T_1 * V_19 , T_1 V_46 )
{
struct V_47 * V_35 = V_8 ;
if ( V_38 < 1 || V_38 > 512
|| V_46 > sizeof( V_35 -> V_48 ) - 1 )
return - V_43 ;
V_35 -> V_35 = V_49 ;
V_35 -> V_41 = V_41 << 1 ;
V_35 -> V_38 = F_22 ( V_38 ) ;
V_35 -> V_50 = V_46 + 1 ;
V_35 -> V_48 [ 0 ] = V_45 ;
memcpy ( & V_35 -> V_48 [ 1 ] , V_19 , V_46 ) ;
return V_46 + 6 ;
}
static int F_26 ( void * V_8 , T_1 V_41 , T_1 V_45 , T_1 * V_19 ,
T_1 V_46 )
{
struct V_51 * V_35 = V_8 ;
if ( V_46 > sizeof( V_35 -> V_19 ) - 1 )
return - V_43 ;
V_35 -> V_35 = V_52 ;
V_35 -> V_41 = V_41 << 1 ;
V_35 -> V_38 = V_46 + 1 ;
V_35 -> V_19 [ 0 ] = V_45 ;
memcpy ( & V_35 -> V_19 [ 1 ] , V_19 , V_46 ) ;
return V_46 + 4 ;
}
static int F_27 ( void * V_8 , T_1 V_41 , T_1 * V_19 ,
T_1 V_46 )
{
struct V_51 * V_35 = V_8 ;
if ( V_46 > sizeof( V_35 -> V_19 ) )
return - V_43 ;
V_35 -> V_35 = V_52 ;
V_35 -> V_41 = V_41 << 1 ;
V_35 -> V_38 = V_46 ;
memcpy ( V_35 -> V_19 , V_19 , V_46 ) ;
return V_46 + 3 ;
}
static int F_28 ( void * V_8 , T_1 V_41 ,
T_1 * V_53 , int V_54 ,
int V_40 )
{
struct V_47 * V_35 = V_8 ;
if ( V_40 < 1 || V_40 > 512 ||
V_54 > sizeof( V_35 -> V_48 ) )
return - V_43 ;
V_35 -> V_35 = V_49 ;
V_35 -> V_41 = V_41 << 1 ;
V_35 -> V_38 = F_22 ( V_40 ) ;
V_35 -> V_50 = V_54 ;
memcpy ( V_35 -> V_48 , V_53 , V_54 ) ;
return V_54 + 5 ;
}
static int F_29 ( struct V_55 * V_56 , struct V_57 * V_58 ,
int V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_56 -> V_60 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_5 V_20 ;
T_5 V_40 = 0 ;
T_1 * V_61 = NULL ;
unsigned int V_62 ;
int V_9 ;
F_23 ( V_7 , L_8 , V_59 ) ;
if ( V_59 == 1 ) {
if ( V_58 -> V_63 & V_64 ) {
F_23 ( V_7 , L_9 ,
V_58 -> V_53 , V_58 -> V_65 ) ;
V_40 = V_58 -> V_65 ;
V_61 = V_58 -> V_8 ;
V_20 = F_24 ( V_8 , V_58 -> V_53 , V_58 -> V_65 ) ;
} else {
F_23 ( V_7 , L_10 ,
V_58 -> V_53 , V_58 -> V_65 ) ;
V_20 = F_27 ( V_8 , V_58 -> V_53 ,
V_58 -> V_8 , V_58 -> V_65 ) ;
}
if ( V_20 < 0 )
return V_20 ;
} else if ( V_5 -> V_66 > 1 &&
V_59 == 2 &&
V_58 [ 0 ] . V_53 == V_58 [ 1 ] . V_53 &&
! ( V_58 [ 0 ] . V_63 & V_64 ) && ( V_58 [ 1 ] . V_63 & V_64 ) ) {
F_23 ( V_7 , L_11 ,
V_58 [ 0 ] . V_53 , V_58 [ 0 ] . V_65 , V_58 [ 1 ] . V_65 ) ;
V_40 = V_58 [ 1 ] . V_65 ;
V_61 = V_58 [ 1 ] . V_8 ;
V_20 = F_28 ( V_8 , V_58 [ 0 ] . V_53 ,
V_58 [ 0 ] . V_8 , V_58 [ 0 ] . V_65 , V_58 [ 1 ] . V_65 ) ;
if ( V_20 < 0 )
return V_20 ;
} else {
F_4 ( V_7 ,
L_12 ) ;
return - V_67 ;
}
V_9 = F_30 ( V_7 , V_68 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_13 , V_9 ) ;
return V_9 ;
}
V_9 = F_11 ( V_7 , V_8 , V_20 , V_24 ) ;
if ( V_9 < 0 ) {
F_20 ( V_7 , L_14 , V_9 ) ;
goto V_69;
}
for ( V_62 = 0 ; V_62 < V_70 ; ++ V_62 ) {
V_9 = F_19 ( V_5 ) ;
if ( - V_71 == V_9 )
continue;
if ( V_9 < 0 )
goto V_69;
break;
}
if ( V_70 <= V_62 ) {
F_20 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_72 ;
V_8 [ 1 ] = 0x01 ;
V_9 = F_11 ( V_7 , V_8 , 2 , V_24 ) ;
if ( V_9 < 0 )
F_20 ( V_7 , L_16 ,
V_9 ) ;
V_9 = - V_29 ;
goto V_69;
}
for ( V_20 = 0 ; V_20 < V_40 ; ) {
V_9 = F_21 ( V_5 , V_61 + V_20 , V_40 - V_20 ) ;
if ( V_9 < 0 )
goto V_69;
if ( V_9 == 0 ) {
F_4 ( V_7 , L_17 ) ;
V_9 = - V_73 ;
goto V_69;
}
V_20 += V_9 ;
if ( V_20 > V_40 ) {
F_4 ( V_7 , L_18 ,
V_9 , V_40 - V_20 + V_9 ) ;
V_9 = - V_73 ;
goto V_69;
}
}
V_9 = V_59 ;
V_69:
F_30 ( V_7 , V_74 ) ;
F_23 ( V_7 , L_19 , V_9 ) ;
return V_9 ;
}
static int F_31 ( struct V_55 * V_56 , T_4 V_53 ,
unsigned short V_63 , char V_75 , T_1 V_45 ,
int V_33 , union V_76 * V_19 )
{
struct V_4 * V_5 = (struct V_4 * ) V_56 -> V_60 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_6 V_77 ;
T_5 V_20 ;
T_2 V_40 = 0 ;
unsigned int V_62 ;
int V_9 ;
F_23 ( V_7 , L_20 ,
V_75 == V_78 ? L_21 : L_22 ,
V_53 , V_63 , V_45 , V_33 ) ;
switch ( V_33 ) {
case V_79 :
V_40 = 1 ;
if ( V_80 == V_75 )
V_20 = F_24 ( V_8 , V_53 , V_40 ) ;
else
V_20 = F_26 ( V_8 , V_53 , V_45 , NULL ,
0 ) ;
break;
case V_81 :
V_40 = 1 ;
if ( V_80 == V_75 )
V_20 = F_25 ( V_8 , V_53 , V_40 ,
V_45 , NULL , 0 ) ;
else
V_20 = F_26 ( V_8 , V_53 , V_45 ,
& V_19 -> V_82 , 1 ) ;
break;
case V_83 :
V_40 = 2 ;
V_77 = F_32 ( V_19 -> V_77 ) ;
if ( V_80 == V_75 )
V_20 = F_25 ( V_8 , V_53 , V_40 ,
V_45 , NULL , 0 ) ;
else
V_20 = F_26 ( V_8 , V_53 , V_45 ,
( T_1 * ) & V_77 , 2 ) ;
break;
case V_84 :
V_33 = V_83 ;
V_75 = V_80 ;
V_40 = 2 ;
V_77 = F_32 ( V_19 -> V_77 ) ;
V_20 = F_25 ( V_8 , V_53 , V_40 , V_45 ,
( T_1 * ) & V_77 , 2 ) ;
break;
case V_85 :
V_33 = V_86 ;
case V_86 :
if ( V_80 == V_75 ) {
V_20 = F_25 ( V_8 , V_53 ,
V_87 ,
V_45 , NULL , 0 ) ;
} else {
V_20 = F_26 ( V_8 , V_53 , V_45 ,
V_19 -> V_88 ,
V_19 -> V_88 [ 0 ] + 1 ) ;
}
break;
case V_89 :
V_33 = V_86 ;
V_75 = V_80 ;
V_20 = F_25 ( V_8 , V_53 , V_87 ,
V_45 , V_19 -> V_88 ,
V_19 -> V_88 [ 0 ] + 1 ) ;
break;
default:
F_20 ( V_7 , L_23 , V_33 ) ;
return - V_67 ;
}
if ( V_20 < 0 )
return V_20 ;
V_9 = F_30 ( V_7 , V_68 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_13 , V_9 ) ;
return V_9 ;
}
V_9 = F_11 ( V_7 , V_8 , V_20 , V_24 ) ;
if ( V_9 < 0 ) {
F_20 ( V_7 , L_14 , V_9 ) ;
goto V_69;
}
for ( V_62 = 0 ; V_62 < V_70 ; ++ V_62 ) {
V_9 = F_19 ( V_5 ) ;
if ( - V_71 == V_9 )
continue;
if ( V_9 < 0 )
goto V_69;
break;
}
if ( V_70 <= V_62 ) {
F_20 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_72 ;
V_8 [ 1 ] = 0x01 ;
V_9 = F_11 ( V_7 , V_8 , 2 , V_24 ) ;
if ( V_9 < 0 )
F_20 ( V_7 , L_16 ,
V_9 ) ;
V_9 = - V_29 ;
goto V_69;
}
if ( V_78 == V_75 ) {
V_9 = 0 ;
goto V_69;
}
if ( V_86 == V_33 )
V_40 = V_9 ;
V_9 = F_21 ( V_5 , V_8 , V_40 ) ;
if ( V_9 < 0 )
goto V_69;
if ( V_9 != V_40 ) {
F_20 ( V_7 , L_24 , V_9 , V_40 ) ;
V_9 = - V_73 ;
goto V_69;
}
switch ( V_33 ) {
case V_79 :
case V_81 :
V_19 -> V_82 = V_8 [ 0 ] ;
break;
case V_83 :
V_19 -> V_77 = F_33 ( ( T_6 * ) V_8 ) ;
break;
case V_86 :
if ( V_40 > V_87 ) {
V_9 = - V_90 ;
goto V_69;
}
memcpy ( V_19 -> V_88 , V_8 , V_40 ) ;
break;
}
V_9 = 0 ;
V_69:
F_30 ( V_7 , V_74 ) ;
F_23 ( V_7 , L_25 , V_9 ) ;
return V_9 ;
}
static T_7 F_34 ( struct V_55 * V_56 )
{
return V_91 |
V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_99 * V_100 )
{
int V_9 ;
V_9 = F_8 ( V_7 , V_101 , ( T_1 * ) V_100 , sizeof( * V_100 ) ,
V_11 ) ;
if ( V_9 != sizeof( * V_100 ) ) {
F_4 ( V_7 , L_26 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return - V_73 ;
}
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_99 * V_100 )
{
int V_9 ;
F_37 ( V_100 -> V_35 != V_101 ) ;
V_9 = F_11 ( V_7 , ( T_1 * ) V_100 , sizeof( * V_100 ) ,
V_11 ) ;
if ( V_9 != sizeof( * V_100 ) ) {
F_4 ( V_7 , L_27 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return - V_73 ;
}
return 0 ;
}
static T_5 F_38 ( struct V_102 * V_103 ,
struct V_104 * V_105 , const char * V_8 ,
T_2 V_20 )
{
struct V_6 * V_7 = F_39 ( V_103 ) ;
struct V_106 * V_107 =
F_40 ( V_105 , struct V_106 , V_107 ) ;
struct V_108 V_35 ;
int V_9 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_9 = F_41 ( V_8 , V_20 , V_109 ,
V_35 . string , F_42 ( V_35 . string ) ) ;
V_35 . V_35 = V_107 -> V_35 ;
V_35 . V_38 = V_9 * sizeof( V_35 . string [ 0 ] ) + 2 ;
V_35 . type = V_110 ;
V_9 = F_11 ( V_7 , & V_35 . V_35 , V_35 . V_38 + 1 ,
V_11 ) ;
if ( V_9 != V_35 . V_38 + 1 ) {
F_4 ( V_7 , L_28 , V_105 -> V_107 . V_111 ,
V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return - V_73 ;
}
F_43 ( V_7 ) ;
return V_20 ;
}
static T_5 F_44 ( struct V_102 * V_103 ,
struct V_104 * V_105 , char * V_8 )
{
struct V_6 * V_7 = F_39 ( V_103 ) ;
struct V_106 * V_107 =
F_40 ( V_105 , struct V_106 , V_107 ) ;
struct V_108 V_35 ;
T_1 V_38 ;
int V_9 ;
V_9 = F_8 ( V_7 , V_107 -> V_35 , & V_35 . V_35 ,
sizeof( V_35 ) - 1 , V_11 ) ;
if ( V_9 < 3 ) {
F_4 ( V_7 , L_29 , V_105 -> V_107 . V_111 ,
V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return - V_73 ;
}
if ( V_35 . V_38 < 2 ) {
F_4 ( V_7 , L_30 ,
V_105 -> V_107 . V_111 , V_35 . V_38 ) ;
return - V_73 ;
}
V_38 = V_35 . V_38 > V_9 - 1 ? V_9 - 1 : V_35 . V_38 ;
V_38 = ( V_38 - 2 ) / sizeof( V_35 . string [ 0 ] ) ;
V_9 = F_45 ( V_35 . string , V_38 , V_109 , V_8 ,
V_112 - 1 ) ;
V_8 [ V_9 ++ ] = '\n' ;
return V_9 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_113 * * V_107 ;
T_1 V_8 [ 2 ] ;
int V_9 ;
V_9 = F_8 ( V_7 , V_114 , V_8 , sizeof( V_8 ) ,
V_11 ) ;
if ( V_9 != sizeof( V_8 ) ) {
F_4 ( V_7 , L_31 , V_9 ) ;
return;
}
for ( V_107 = V_115 . V_116 ; * V_107 ; ++ V_107 ) {
T_8 V_117 = ( V_8 [ 1 ] & 1 ) ? V_118 | V_119 : V_119 ;
V_9 = F_46 ( & V_7 -> V_5 . V_120 , * V_107 , V_117 ) ;
if ( V_9 < 0 )
F_4 ( V_7 , L_32 ,
( * V_107 ) -> V_111 ) ;
V_8 [ 1 ] >>= 1 ;
}
}
static int F_47 ( struct V_6 * V_7 , const struct V_121 * V_122 )
{
struct V_4 * V_5 ;
T_1 V_8 [ 3 ] ;
struct V_123 V_124 ;
int V_9 ;
V_9 = F_48 ( V_7 ) ;
if ( V_9 ) {
F_4 ( V_7 , L_33 ) ;
return V_9 ;
}
V_9 = F_49 ( V_7 , V_125 ) ;
if ( V_9 ) {
F_4 ( V_7 , L_34 ) ;
return V_9 ;
}
V_9 = F_50 ( V_7 ) ;
if ( V_9 ) {
F_4 ( V_7 , L_35 ) ;
goto V_126;
}
V_9 = F_30 ( V_7 , V_68 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_13 , V_9 ) ;
goto V_127;
}
V_9 = F_8 ( V_7 , V_128 , V_8 , sizeof( V_8 ) ,
V_11 ) ;
if ( V_9 != sizeof( V_8 ) ) {
F_4 ( V_7 , L_36 ) ;
if ( V_9 >= 0 )
V_9 = - V_73 ;
goto V_129;
}
F_51 ( V_7 , L_37 ,
V_8 [ 1 ] , V_8 [ 2 ] ) ;
V_9 = F_8 ( V_7 , V_130 , ( T_1 * ) & V_124 ,
sizeof( V_124 ) , V_11 ) ;
if ( V_9 != sizeof( V_124 ) ) {
F_4 ( V_7 , L_38 ) ;
if ( V_9 >= 0 )
V_9 = - V_73 ;
goto V_129;
}
V_124 . V_131 = F_22 ( 1 ) ;
V_9 = F_11 ( V_7 , ( T_1 * ) & V_124 , sizeof( V_124 ) ,
V_11 ) ;
if ( V_9 != sizeof( V_124 ) ) {
F_4 ( V_7 , L_39 ) ;
if ( V_9 >= 0 )
V_9 = - V_73 ;
goto V_129;
}
V_5 = F_52 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 ) {
V_9 = - V_23 ;
goto V_129;
}
F_53 ( V_7 , ( void * ) V_5 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_56 . V_132 = V_133 ;
V_5 -> V_56 . V_134 = V_135 ;
V_5 -> V_56 . V_136 = & V_137 ;
V_5 -> V_56 . V_60 = V_5 ;
V_5 -> V_56 . V_5 . V_138 = & V_7 -> V_5 ;
snprintf ( V_5 -> V_56 . V_111 , sizeof( V_5 -> V_56 . V_111 ) ,
L_40 , V_7 -> V_139 ) ;
V_5 -> V_66 = V_8 [ 2 ] ;
F_54 ( & V_5 -> V_26 ) ;
F_55 ( V_7 ) ;
V_9 = F_56 ( & V_5 -> V_56 ) ;
F_57 ( V_7 ) ;
if ( V_9 ) {
F_4 ( V_7 , L_41 ) ;
goto V_140;
}
F_23 ( V_7 , L_42 ) ;
V_5 -> V_141 . V_142 = L_43 ;
V_5 -> V_141 . V_143 = F_1 ;
V_5 -> V_141 . V_144 = F_7 ;
V_5 -> V_141 . V_145 = F_5 ;
V_5 -> V_141 . V_146 = F_6 ;
V_5 -> V_141 . V_147 = - 1 ;
V_5 -> V_141 . V_148 = 8 ;
V_5 -> V_141 . V_149 = 1 ;
V_5 -> V_141 . V_138 = & V_7 -> V_5 ;
V_9 = F_58 ( & V_5 -> V_141 , V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_44 ) ;
goto V_150;
}
V_9 = F_59 ( & V_7 -> V_5 . V_120 , & V_115 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_45 ) ;
goto V_151;
}
F_43 ( V_7 ) ;
F_30 ( V_7 , V_74 ) ;
return V_9 ;
V_151:
F_60 ( & V_5 -> V_141 ) ;
V_150:
F_61 ( & V_5 -> V_56 ) ;
V_140:
F_10 ( V_5 ) ;
V_129:
F_30 ( V_7 , V_74 ) ;
V_127:
F_62 ( V_7 ) ;
V_126:
F_63 ( V_7 ) ;
return V_9 ;
}
static void F_64 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_65 ( V_7 ) ;
F_66 ( & V_7 -> V_5 . V_120 , & V_115 ) ;
F_60 ( & V_5 -> V_141 ) ;
F_61 ( & V_5 -> V_56 ) ;
F_62 ( V_7 ) ;
F_63 ( V_7 ) ;
F_10 ( V_5 ) ;
}
static int F_67 ( struct V_6 * V_7 , struct V_152 * V_35 ,
T_1 * V_19 , int V_33 )
{
struct V_4 * V_5 = F_65 ( V_7 ) ;
struct V_153 * V_154 = ( void * ) V_19 ;
switch ( V_19 [ 0 ] ) {
case V_155 :
F_23 ( V_7 , L_46 ,
V_154 -> V_156 , V_154 -> V_157 ,
F_68 ( V_154 -> V_62 ) , F_68 ( V_154 -> V_38 ) ) ;
switch ( V_154 -> V_156 ) {
case V_158 :
V_5 -> V_32 = - V_159 ;
break;
case V_160 :
V_5 -> V_32 = - V_71 ;
break;
case V_161 :
V_5 -> V_32 = F_68 ( V_154 -> V_38 ) ;
break;
case V_162 :
switch ( V_154 -> V_157 ) {
case V_163 :
case V_164 :
V_5 -> V_32 = - V_29 ;
break;
default:
V_5 -> V_32 = - V_73 ;
break;
}
break;
default:
V_5 -> V_32 = - V_43 ;
break;
}
F_18 ( & V_5 -> V_31 , 1 ) ;
break;
case V_165 :
F_23 ( V_7 , L_47 , V_19 [ 1 ] , V_19 [ 2 ] ) ;
V_5 -> V_40 = V_19 [ 2 ] ;
if ( V_5 -> V_40 > sizeof( V_5 -> V_36 ) )
V_5 -> V_40 = sizeof( V_5 -> V_36 ) ;
memcpy ( V_5 -> V_36 , & V_19 [ 3 ] , V_5 -> V_40 ) ;
F_18 ( & V_5 -> V_39 , 1 ) ;
break;
default:
F_4 ( V_7 , L_48 ) ;
return 0 ;
}
F_69 ( & V_5 -> V_26 ) ;
return 1 ;
}
