static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_3 ( & V_5 -> V_11 ) ;
V_10 = F_4 ( V_7 , V_12 , V_8 ,
V_13 , V_14 ,
V_15 ) ;
if ( V_10 != V_13 ) {
F_5 ( V_7 , L_1 , V_10 ) ;
goto exit;
}
V_8 [ 1 ] &= ~ ( 1 << V_3 ) ;
V_8 [ 2 ] = V_16 ;
V_10 = F_4 ( V_7 , V_12 , V_8 ,
V_13 , V_14 ,
V_17 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_2 , V_10 ) ;
goto exit;
}
V_10 = 0 ;
exit:
F_6 ( & V_5 -> V_11 ) ;
return V_10 < 0 ? V_10 : - V_18 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_3 ( & V_5 -> V_11 ) ;
V_8 [ 0 ] = V_20 ;
V_8 [ 1 ] = V_19 ? 0xff : 0 ;
V_8 [ 2 ] = 1 << V_3 ;
V_10 = F_4 ( V_7 , V_20 , V_8 ,
V_21 , V_14 ,
V_17 ) ;
if ( V_10 < 0 )
F_5 ( V_7 , L_3 , V_10 ) ;
F_6 ( & V_5 -> V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_3 ( & V_5 -> V_11 ) ;
V_10 = F_4 ( V_7 , V_22 , V_8 ,
V_23 , V_14 ,
V_15 ) ;
if ( V_10 != V_23 ) {
F_5 ( V_7 , L_4 , V_10 ) ;
V_10 = V_10 < 0 ? V_10 : - V_18 ;
goto exit;
}
V_10 = V_8 [ 1 ] ;
exit:
F_6 ( & V_5 -> V_11 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_10 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( V_10 >> V_3 ) & 1 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_3 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
int V_10 ;
F_3 ( & V_5 -> V_11 ) ;
V_10 = F_4 ( V_7 , V_12 , V_8 ,
V_13 , V_14 ,
V_15 ) ;
if ( V_10 != V_13 ) {
F_5 ( V_7 , L_1 , V_10 ) ;
goto V_24;
}
V_8 [ 1 ] |= 1 << V_3 ;
V_8 [ 2 ] = V_16 ;
V_10 = F_4 ( V_7 , V_12 , V_8 ,
V_13 , V_14 ,
V_17 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_2 , V_10 ) ;
goto V_24;
}
F_6 ( & V_5 -> V_11 ) ;
F_7 ( V_2 , V_3 , V_19 ) ;
return 0 ;
V_24:
F_6 ( & V_5 -> V_11 ) ;
return V_10 < 0 ? V_10 : - V_18 ;
}
static int F_11 ( struct V_6 * V_7 , unsigned char V_25 ,
T_1 * V_26 , T_2 V_27 , unsigned char V_28 )
{
T_1 * V_8 ;
int V_10 ;
V_8 = F_12 ( V_27 , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_10 = F_4 ( V_7 , V_25 , V_8 , V_27 ,
V_28 , V_15 ) ;
memcpy ( V_26 , V_8 , V_27 ) ;
F_13 ( V_8 ) ;
return V_10 ;
}
static int F_14 ( struct V_6 * V_7 , T_1 * V_26 , T_2 V_27 ,
unsigned char V_28 )
{
T_1 * V_8 ;
int V_10 ;
V_8 = F_15 ( V_26 , V_27 , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
if ( V_28 == V_31 )
V_10 = F_16 ( V_7 , V_8 , V_27 ) ;
else
V_10 = F_4 ( V_7 , V_8 [ 0 ] , V_8 , V_27 , V_28 ,
V_17 ) ;
F_13 ( V_8 ) ;
return V_10 ;
}
static int F_17 ( struct V_4 * V_5 , T_3 * V_32 )
{
int V_10 = 0 ;
V_10 = F_18 ( V_5 -> V_33 ,
F_19 ( V_32 ) , F_20 ( V_34 ) ) ;
if ( - V_35 == V_10 )
return V_10 ;
if ( ! V_10 )
return - V_36 ;
F_21 ( V_32 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 2 ] ;
int V_10 ;
V_8 [ 0 ] = V_37 ;
V_8 [ 1 ] = 0x01 ;
F_21 ( & V_5 -> V_38 , 0 ) ;
V_10 = F_14 ( V_7 , V_8 , 2 , V_31 ) ;
if ( V_10 < 0 ) {
F_23 ( V_7 , L_5 , V_10 ) ;
return V_10 ;
}
V_10 = F_17 ( V_5 , & V_5 -> V_38 ) ;
if ( V_10 )
return V_10 ;
return V_5 -> V_39 ;
}
static int F_24 ( struct V_4 * V_5 , T_1 * V_26 , T_2 V_40 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_41 V_42 ;
int V_10 ;
if ( V_40 > sizeof( V_5 -> V_43 ) )
V_40 = sizeof( V_5 -> V_43 ) ;
V_42 . V_42 = V_44 ;
V_42 . V_45 = F_25 ( V_40 ) ;
F_21 ( & V_5 -> V_46 , 0 ) ;
V_10 = F_14 ( V_7 , & V_42 . V_42 , sizeof( V_42 ) ,
V_31 ) ;
if ( V_10 < 0 ) {
F_23 ( V_7 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_17 ( V_5 , & V_5 -> V_46 ) ;
if ( V_10 )
return V_10 ;
F_26 ( V_7 , L_7 ,
V_5 -> V_47 , V_40 ) ;
if ( V_40 > V_5 -> V_47 )
V_40 = V_5 -> V_47 ;
memcpy ( V_26 , V_5 -> V_43 , V_40 ) ;
return V_5 -> V_47 ;
}
static int F_27 ( void * V_8 , T_1 V_48 , T_4 V_45 )
{
struct V_49 * V_42 = V_8 ;
if ( V_45 < 1 || V_45 > 512 )
return - V_50 ;
V_42 -> V_42 = V_51 ;
V_42 -> V_48 = V_48 << 1 ;
V_42 -> V_45 = F_25 ( V_45 ) ;
return sizeof( * V_42 ) ;
}
static int F_28 ( void * V_8 , T_1 V_48 , T_4 V_45 ,
T_1 V_52 , T_1 * V_26 , T_1 V_53 )
{
struct V_54 * V_42 = V_8 ;
if ( V_45 < 1 || V_45 > 512
|| V_53 > sizeof( V_42 -> V_55 ) - 1 )
return - V_50 ;
V_42 -> V_42 = V_56 ;
V_42 -> V_48 = V_48 << 1 ;
V_42 -> V_45 = F_25 ( V_45 ) ;
V_42 -> V_57 = V_53 + 1 ;
V_42 -> V_55 [ 0 ] = V_52 ;
memcpy ( & V_42 -> V_55 [ 1 ] , V_26 , V_53 ) ;
return V_53 + 6 ;
}
static int F_29 ( void * V_8 , T_1 V_48 , T_1 V_52 , T_1 * V_26 ,
T_1 V_53 )
{
struct V_58 * V_42 = V_8 ;
if ( V_53 > sizeof( V_42 -> V_26 ) - 1 )
return - V_50 ;
V_42 -> V_42 = V_59 ;
V_42 -> V_48 = V_48 << 1 ;
V_42 -> V_45 = V_53 + 1 ;
V_42 -> V_26 [ 0 ] = V_52 ;
memcpy ( & V_42 -> V_26 [ 1 ] , V_26 , V_53 ) ;
return V_53 + 4 ;
}
static int F_30 ( void * V_8 , T_1 V_48 , T_1 * V_26 ,
T_1 V_53 )
{
struct V_58 * V_42 = V_8 ;
if ( V_53 > sizeof( V_42 -> V_26 ) )
return - V_50 ;
V_42 -> V_42 = V_59 ;
V_42 -> V_48 = V_48 << 1 ;
V_42 -> V_45 = V_53 ;
memcpy ( V_42 -> V_26 , V_26 , V_53 ) ;
return V_53 + 3 ;
}
static int F_31 ( void * V_8 , T_1 V_48 ,
T_1 * V_60 , int V_61 ,
int V_47 )
{
struct V_54 * V_42 = V_8 ;
if ( V_47 < 1 || V_47 > 512 ||
V_61 > sizeof( V_42 -> V_55 ) )
return - V_50 ;
V_42 -> V_42 = V_56 ;
V_42 -> V_48 = V_48 << 1 ;
V_42 -> V_45 = F_25 ( V_47 ) ;
V_42 -> V_57 = V_61 ;
memcpy ( V_42 -> V_55 , V_60 , V_61 ) ;
return V_61 + 5 ;
}
static int F_32 ( struct V_62 * V_63 , struct V_64 * V_65 ,
int V_66 )
{
struct V_4 * V_5 = (struct V_4 * ) V_63 -> V_67 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_5 V_27 ;
T_5 V_47 = 0 ;
T_1 * V_68 = NULL ;
unsigned int V_69 ;
int V_10 ;
F_26 ( V_7 , L_8 , V_66 ) ;
if ( V_66 == 1 ) {
if ( V_65 -> V_70 & V_71 ) {
F_26 ( V_7 , L_9 ,
V_65 -> V_60 , V_65 -> V_72 ) ;
V_47 = V_65 -> V_72 ;
V_68 = V_65 -> V_8 ;
V_27 = F_27 ( V_8 , V_65 -> V_60 , V_65 -> V_72 ) ;
} else {
F_26 ( V_7 , L_10 ,
V_65 -> V_60 , V_65 -> V_72 ) ;
V_27 = F_30 ( V_8 , V_65 -> V_60 ,
V_65 -> V_8 , V_65 -> V_72 ) ;
}
if ( V_27 < 0 )
return V_27 ;
} else if ( V_5 -> V_73 > 1 &&
V_66 == 2 &&
V_65 [ 0 ] . V_60 == V_65 [ 1 ] . V_60 &&
! ( V_65 [ 0 ] . V_70 & V_71 ) && ( V_65 [ 1 ] . V_70 & V_71 ) ) {
F_26 ( V_7 , L_11 ,
V_65 [ 0 ] . V_60 , V_65 [ 0 ] . V_72 , V_65 [ 1 ] . V_72 ) ;
V_47 = V_65 [ 1 ] . V_72 ;
V_68 = V_65 [ 1 ] . V_8 ;
V_27 = F_31 ( V_8 , V_65 [ 0 ] . V_60 ,
V_65 [ 0 ] . V_8 , V_65 [ 0 ] . V_72 , V_65 [ 1 ] . V_72 ) ;
if ( V_27 < 0 )
return V_27 ;
} else {
F_5 ( V_7 ,
L_12 ) ;
return - V_74 ;
}
V_10 = F_33 ( V_7 , V_75 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_7 , V_8 , V_27 , V_31 ) ;
if ( V_10 < 0 ) {
F_23 ( V_7 , L_14 , V_10 ) ;
goto V_76;
}
for ( V_69 = 0 ; V_69 < V_77 ; ++ V_69 ) {
V_10 = F_22 ( V_5 ) ;
if ( - V_78 == V_10 )
continue;
if ( V_10 < 0 )
goto V_76;
break;
}
if ( V_77 <= V_69 ) {
F_23 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_79 ;
V_8 [ 1 ] = 0x01 ;
V_10 = F_14 ( V_7 , V_8 , 2 , V_31 ) ;
if ( V_10 < 0 )
F_23 ( V_7 , L_16 ,
V_10 ) ;
V_10 = - V_36 ;
goto V_76;
}
for ( V_27 = 0 ; V_27 < V_47 ; ) {
V_10 = F_24 ( V_5 , V_68 + V_27 , V_47 - V_27 ) ;
if ( V_10 < 0 )
goto V_76;
if ( V_10 == 0 ) {
F_5 ( V_7 , L_17 ) ;
V_10 = - V_18 ;
goto V_76;
}
V_27 += V_10 ;
if ( V_27 > V_47 ) {
F_5 ( V_7 , L_18 ,
V_10 , V_47 - V_27 + V_10 ) ;
V_10 = - V_18 ;
goto V_76;
}
}
V_10 = V_66 ;
V_76:
F_33 ( V_7 , V_80 ) ;
F_26 ( V_7 , L_19 , V_10 ) ;
return V_10 ;
}
static int F_34 ( struct V_62 * V_63 , T_4 V_60 ,
unsigned short V_70 , char V_81 , T_1 V_52 ,
int V_40 , union V_82 * V_26 )
{
struct V_4 * V_5 = (struct V_4 * ) V_63 -> V_67 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_6 V_83 ;
T_5 V_27 ;
T_2 V_47 = 0 ;
unsigned int V_69 ;
int V_10 ;
F_26 ( V_7 , L_20 ,
V_81 == V_84 ? L_21 : L_22 ,
V_60 , V_70 , V_52 , V_40 ) ;
switch ( V_40 ) {
case V_85 :
V_47 = 1 ;
if ( V_86 == V_81 )
V_27 = F_27 ( V_8 , V_60 , V_47 ) ;
else
V_27 = F_29 ( V_8 , V_60 , V_52 , NULL ,
0 ) ;
break;
case V_87 :
V_47 = 1 ;
if ( V_86 == V_81 )
V_27 = F_28 ( V_8 , V_60 , V_47 ,
V_52 , NULL , 0 ) ;
else
V_27 = F_29 ( V_8 , V_60 , V_52 ,
& V_26 -> V_88 , 1 ) ;
break;
case V_89 :
V_47 = 2 ;
V_83 = F_35 ( V_26 -> V_83 ) ;
if ( V_86 == V_81 )
V_27 = F_28 ( V_8 , V_60 , V_47 ,
V_52 , NULL , 0 ) ;
else
V_27 = F_29 ( V_8 , V_60 , V_52 ,
( T_1 * ) & V_83 , 2 ) ;
break;
case V_90 :
V_40 = V_89 ;
V_81 = V_86 ;
V_47 = 2 ;
V_83 = F_35 ( V_26 -> V_83 ) ;
V_27 = F_28 ( V_8 , V_60 , V_47 , V_52 ,
( T_1 * ) & V_83 , 2 ) ;
break;
case V_91 :
V_40 = V_92 ;
case V_92 :
if ( V_86 == V_81 ) {
V_27 = F_28 ( V_8 , V_60 ,
V_93 ,
V_52 , NULL , 0 ) ;
} else {
V_27 = F_29 ( V_8 , V_60 , V_52 ,
V_26 -> V_94 ,
V_26 -> V_94 [ 0 ] + 1 ) ;
}
break;
case V_95 :
V_40 = V_92 ;
V_81 = V_86 ;
V_27 = F_28 ( V_8 , V_60 , V_93 ,
V_52 , V_26 -> V_94 ,
V_26 -> V_94 [ 0 ] + 1 ) ;
break;
default:
F_23 ( V_7 , L_23 , V_40 ) ;
return - V_74 ;
}
if ( V_27 < 0 )
return V_27 ;
V_10 = F_33 ( V_7 , V_75 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_7 , V_8 , V_27 , V_31 ) ;
if ( V_10 < 0 ) {
F_23 ( V_7 , L_14 , V_10 ) ;
goto V_76;
}
for ( V_69 = 0 ; V_69 < V_77 ; ++ V_69 ) {
V_10 = F_22 ( V_5 ) ;
if ( - V_78 == V_10 )
continue;
if ( V_10 < 0 )
goto V_76;
break;
}
if ( V_77 <= V_69 ) {
F_23 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_79 ;
V_8 [ 1 ] = 0x01 ;
V_10 = F_14 ( V_7 , V_8 , 2 , V_31 ) ;
if ( V_10 < 0 )
F_23 ( V_7 , L_16 ,
V_10 ) ;
V_10 = - V_36 ;
goto V_76;
}
if ( V_84 == V_81 ) {
V_10 = 0 ;
goto V_76;
}
if ( V_92 == V_40 )
V_47 = V_10 ;
V_10 = F_24 ( V_5 , V_8 , V_47 ) ;
if ( V_10 < 0 )
goto V_76;
if ( V_10 != V_47 ) {
F_23 ( V_7 , L_24 , V_10 , V_47 ) ;
V_10 = - V_18 ;
goto V_76;
}
switch ( V_40 ) {
case V_85 :
case V_87 :
V_26 -> V_88 = V_8 [ 0 ] ;
break;
case V_89 :
V_26 -> V_83 = F_36 ( ( T_6 * ) V_8 ) ;
break;
case V_92 :
if ( V_47 > V_93 ) {
V_10 = - V_96 ;
goto V_76;
}
memcpy ( V_26 -> V_94 , V_8 , V_47 ) ;
break;
}
V_10 = 0 ;
V_76:
F_33 ( V_7 , V_80 ) ;
F_26 ( V_7 , L_25 , V_10 ) ;
return V_10 ;
}
static T_7 F_37 ( struct V_62 * V_63 )
{
return V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
int V_10 ;
V_10 = F_11 ( V_7 , V_107 , ( T_1 * ) V_106 , sizeof( * V_106 ) ,
V_14 ) ;
if ( V_10 != sizeof( * V_106 ) ) {
F_5 ( V_7 , L_26 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_18 ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
int V_10 ;
F_40 ( V_106 -> V_42 != V_107 ) ;
V_10 = F_14 ( V_7 , ( T_1 * ) V_106 , sizeof( * V_106 ) ,
V_14 ) ;
if ( V_10 != sizeof( * V_106 ) ) {
F_5 ( V_7 , L_27 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_18 ;
}
return 0 ;
}
static T_5 F_41 ( struct V_108 * V_109 ,
struct V_110 * V_111 , const char * V_8 ,
T_2 V_27 )
{
struct V_6 * V_7 = F_42 ( V_109 ) ;
struct V_112 * V_113 =
F_43 ( V_111 , struct V_112 , V_113 ) ;
struct V_114 V_42 ;
int V_10 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_10 = F_44 ( V_8 , V_27 , V_115 ,
V_42 . string , F_45 ( V_42 . string ) ) ;
V_42 . V_42 = V_113 -> V_42 ;
V_42 . V_45 = V_10 * sizeof( V_42 . string [ 0 ] ) + 2 ;
V_42 . type = V_116 ;
V_10 = F_14 ( V_7 , & V_42 . V_42 , V_42 . V_45 + 1 ,
V_14 ) ;
if ( V_10 != V_42 . V_45 + 1 ) {
F_5 ( V_7 , L_28 , V_111 -> V_113 . V_117 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_18 ;
}
F_46 ( V_7 ) ;
return V_27 ;
}
static T_5 F_47 ( struct V_108 * V_109 ,
struct V_110 * V_111 , char * V_8 )
{
struct V_6 * V_7 = F_42 ( V_109 ) ;
struct V_112 * V_113 =
F_43 ( V_111 , struct V_112 , V_113 ) ;
struct V_114 V_42 ;
T_1 V_45 ;
int V_10 ;
V_10 = F_11 ( V_7 , V_113 -> V_42 , & V_42 . V_42 ,
sizeof( V_42 ) - 1 , V_14 ) ;
if ( V_10 < 3 ) {
F_5 ( V_7 , L_29 , V_111 -> V_113 . V_117 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_18 ;
}
if ( V_42 . V_45 < 2 ) {
F_5 ( V_7 , L_30 ,
V_111 -> V_113 . V_117 , V_42 . V_45 ) ;
return - V_18 ;
}
V_45 = V_42 . V_45 > V_10 - 1 ? V_10 - 1 : V_42 . V_45 ;
V_45 = ( V_45 - 2 ) / sizeof( V_42 . string [ 0 ] ) ;
V_10 = F_48 ( V_42 . string , V_45 , V_115 , V_8 ,
V_118 - 1 ) ;
V_8 [ V_10 ++ ] = '\n' ;
return V_10 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_119 * * V_113 ;
T_1 V_8 [ 2 ] ;
int V_10 ;
V_10 = F_11 ( V_7 , V_120 , V_8 , sizeof( V_8 ) ,
V_14 ) ;
if ( V_10 != sizeof( V_8 ) ) {
F_5 ( V_7 , L_31 , V_10 ) ;
return;
}
for ( V_113 = V_121 . V_122 ; * V_113 ; ++ V_113 ) {
T_8 V_123 = ( V_8 [ 1 ] & 1 ) ? V_124 | V_125 : V_125 ;
V_10 = F_49 ( & V_7 -> V_5 . V_126 , * V_113 , V_123 ) ;
if ( V_10 < 0 )
F_5 ( V_7 , L_32 ,
( * V_113 ) -> V_117 ) ;
V_8 [ 1 ] >>= 1 ;
}
}
static void F_50 ( struct V_127 * V_128 )
{
}
static void F_51 ( struct V_127 * V_128 )
{
struct V_1 * V_129 = F_52 ( V_128 ) ;
struct V_4 * V_5 = F_2 ( V_129 ) ;
F_53 ( V_128 -> V_130 , & V_5 -> V_131 ) ;
}
static void F_54 ( struct V_127 * V_128 )
{
struct V_1 * V_129 = F_52 ( V_128 ) ;
struct V_4 * V_5 = F_2 ( V_129 ) ;
F_55 ( V_128 -> V_130 , & V_5 -> V_131 ) ;
}
static void F_56 ( struct V_132 * V_133 )
{
struct V_4 * V_5 = F_43 ( V_133 , struct V_4 ,
V_134 . V_133 ) ;
struct V_127 * V_128 ;
T_1 V_135 ;
T_1 V_136 = ( T_1 ) V_5 -> V_131 ;
T_7 V_137 ;
int V_138 , V_139 , V_10 ;
V_10 = F_8 ( & V_5 -> V_129 ) ;
if ( V_10 == - V_140 )
return;
if ( V_10 < 0 )
goto exit;
V_135 = V_10 ;
while ( V_136 ) {
V_139 = F_57 ( V_136 ) - 1 ;
V_136 &= ~ F_58 ( V_139 ) ;
if ( ! V_5 -> V_129 . V_141 )
break;
V_138 = V_5 -> V_129 . V_141 ( & V_5 -> V_129 , V_139 ) ;
V_128 = F_59 ( V_138 ) ;
if ( ! V_128 )
continue;
V_137 = F_60 ( V_128 ) ;
if ( V_135 & F_58 ( V_139 ) ) {
if ( V_137 & V_142 )
F_61 ( V_138 ) ;
if ( ( V_137 & V_143 ) &&
! ( V_5 -> V_144 & F_58 ( V_139 ) ) )
F_61 ( V_138 ) ;
} else {
if ( V_137 & V_145 )
F_61 ( V_138 ) ;
if ( ( V_137 & V_146 ) &&
( V_5 -> V_144 & F_58 ( V_139 ) ) )
F_61 ( V_138 ) ;
}
}
V_5 -> V_144 = V_135 ;
exit:
if ( V_5 -> V_147 )
F_62 ( & V_5 -> V_134 , 10 ) ;
}
static unsigned int F_63 ( struct V_127 * V_128 )
{
struct V_1 * V_129 = F_52 ( V_128 ) ;
struct V_4 * V_5 = F_2 ( V_129 ) ;
F_64 ( & V_5 -> V_134 , F_56 ) ;
F_1 ( V_129 , V_128 -> V_130 ) ;
if ( ! V_5 -> V_147 ) {
V_5 -> V_147 = true ;
F_62 ( & V_5 -> V_134 , 0 ) ;
}
F_54 ( V_128 ) ;
return 0 ;
}
static void F_65 ( struct V_127 * V_128 )
{
struct V_1 * V_129 = F_52 ( V_128 ) ;
struct V_4 * V_5 = F_2 ( V_129 ) ;
F_66 ( & V_5 -> V_134 ) ;
}
static int F_67 ( struct V_127 * V_128 , unsigned int type )
{
return 0 ;
}
static int T_9 F_68 ( struct V_4 * V_5 ,
int V_148 )
{
int V_10 ;
if ( V_5 -> V_149 [ V_148 ] )
return - V_50 ;
V_5 -> V_149 [ V_148 ] = F_69 ( & V_5 -> V_129 , V_148 ,
L_33 ) ;
if ( F_70 ( V_5 -> V_149 [ V_148 ] ) ) {
F_71 ( V_5 -> V_129 . V_150 , L_34 ) ;
return F_72 ( V_5 -> V_149 [ V_148 ] ) ;
}
V_10 = F_73 ( & V_5 -> V_129 , V_148 ) ;
if ( V_10 ) {
F_71 ( V_5 -> V_129 . V_150 , L_35 ) ;
goto V_151;
}
V_10 = F_74 ( V_5 -> V_149 [ V_148 ] ) ;
if ( V_10 < 0 ) {
F_71 ( V_5 -> V_129 . V_150 , L_36 ) ;
goto V_152;
}
return V_10 ;
V_152:
F_75 ( & V_5 -> V_129 , V_148 ) ;
V_151:
F_76 ( V_5 -> V_149 [ V_148 ] ) ;
V_5 -> V_149 [ V_148 ] = NULL ;
return V_10 ;
}
static int F_77 ( struct V_6 * V_7 , const struct V_153 * V_154 )
{
struct V_4 * V_5 ;
T_1 V_8 [ 3 ] ;
struct V_155 V_156 ;
int V_10 ;
V_5 = F_78 ( & V_7 -> V_5 , sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_5 -> V_9 = F_78 ( & V_7 -> V_5 , V_157 ,
V_29 ) ;
if ( ! V_5 -> V_9 )
return - V_30 ;
F_79 ( & V_5 -> V_11 ) ;
V_10 = F_80 ( V_7 ) ;
if ( V_10 ) {
F_5 ( V_7 , L_37 ) ;
return V_10 ;
}
V_10 = F_81 ( V_7 , V_158 ) ;
if ( V_10 ) {
F_5 ( V_7 , L_38 ) ;
return V_10 ;
}
V_10 = F_82 ( V_7 ) ;
if ( V_10 ) {
F_5 ( V_7 , L_39 ) ;
goto V_159;
}
V_10 = F_33 ( V_7 , V_75 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_13 , V_10 ) ;
goto V_160;
}
V_10 = F_11 ( V_7 , V_161 , V_8 , sizeof( V_8 ) ,
V_14 ) ;
if ( V_10 != sizeof( V_8 ) ) {
F_5 ( V_7 , L_40 ) ;
if ( V_10 >= 0 )
V_10 = - V_18 ;
goto V_162;
}
F_83 ( V_7 , L_41 ,
V_8 [ 1 ] , V_8 [ 2 ] ) ;
V_10 = F_11 ( V_7 , V_163 , ( T_1 * ) & V_156 ,
sizeof( V_156 ) , V_14 ) ;
if ( V_10 != sizeof( V_156 ) ) {
F_5 ( V_7 , L_42 ) ;
if ( V_10 >= 0 )
V_10 = - V_18 ;
goto V_162;
}
V_156 . V_164 = F_25 ( 1 ) ;
V_10 = F_14 ( V_7 , ( T_1 * ) & V_156 , sizeof( V_156 ) ,
V_14 ) ;
if ( V_10 != sizeof( V_156 ) ) {
F_5 ( V_7 , L_43 ) ;
if ( V_10 >= 0 )
V_10 = - V_18 ;
goto V_162;
}
F_84 ( V_7 , ( void * ) V_5 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_63 . V_165 = V_166 ;
V_5 -> V_63 . V_167 = V_168 ;
V_5 -> V_63 . V_169 = & V_170 ;
V_5 -> V_63 . V_67 = V_5 ;
V_5 -> V_63 . V_5 . V_150 = & V_7 -> V_5 ;
snprintf ( V_5 -> V_63 . V_117 , sizeof( V_5 -> V_63 . V_117 ) ,
L_44 ,
( (struct V_171 * ) V_7 -> V_171 ) -> V_172 ) ;
V_5 -> V_73 = V_8 [ 2 ] ;
F_85 ( & V_5 -> V_33 ) ;
F_86 ( V_7 ) ;
V_10 = F_87 ( & V_5 -> V_63 ) ;
F_88 ( V_7 ) ;
if ( V_10 ) {
F_5 ( V_7 , L_45 ) ;
goto V_162;
}
F_26 ( V_7 , L_46 ) ;
V_5 -> V_129 . V_173 = L_47 ;
V_5 -> V_129 . V_174 = F_1 ;
V_5 -> V_129 . V_175 = F_10 ;
V_5 -> V_129 . V_176 = F_7 ;
V_5 -> V_129 . V_177 = F_9 ;
V_5 -> V_129 . V_178 = - 1 ;
V_5 -> V_129 . V_179 = 8 ;
V_5 -> V_129 . V_180 = 1 ;
V_5 -> V_129 . V_150 = & V_7 -> V_5 ;
V_10 = F_89 ( & V_5 -> V_129 , V_5 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_48 ) ;
goto V_181;
}
V_10 = F_90 ( & V_7 -> V_5 . V_126 , & V_121 ) ;
if ( V_10 < 0 ) {
F_5 ( V_7 , L_49 ) ;
goto V_182;
}
F_46 ( V_7 ) ;
F_33 ( V_7 , V_80 ) ;
V_10 = F_91 ( & V_5 -> V_129 , & V_183 , 0 ,
V_184 , V_185 ) ;
if ( V_10 ) {
F_71 ( V_5 -> V_129 . V_150 , L_50 ) ;
goto V_186;
}
return V_10 ;
V_186:
F_92 ( & V_7 -> V_5 . V_126 , & V_121 ) ;
V_182:
F_93 ( & V_5 -> V_129 ) ;
V_181:
F_94 ( & V_5 -> V_63 ) ;
V_162:
F_33 ( V_7 , V_80 ) ;
V_160:
F_95 ( V_7 ) ;
V_159:
F_96 ( V_7 ) ;
return V_10 ;
}
static void F_97 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_98 ( V_7 ) ;
int V_187 ;
F_92 ( & V_7 -> V_5 . V_126 , & V_121 ) ;
F_94 ( & V_5 -> V_63 ) ;
if ( V_5 -> V_147 ) {
V_5 -> V_147 = false ;
F_66 ( & V_5 -> V_134 ) ;
}
for ( V_187 = 0 ; V_187 < F_45 ( V_5 -> V_149 ) ; V_187 ++ ) {
F_75 ( & V_5 -> V_129 , V_187 ) ;
F_76 ( V_5 -> V_149 [ V_187 ] ) ;
}
F_93 ( & V_5 -> V_129 ) ;
F_95 ( V_7 ) ;
F_96 ( V_7 ) ;
}
static int F_99 ( struct V_6 * V_7 , struct V_188 * V_42 ,
T_1 * V_26 , int V_40 )
{
struct V_4 * V_5 = F_98 ( V_7 ) ;
struct V_189 * V_190 = ( void * ) V_26 ;
switch ( V_26 [ 0 ] ) {
case V_191 :
F_26 ( V_7 , L_51 ,
V_190 -> V_192 , V_190 -> V_193 ,
F_100 ( V_190 -> V_69 ) , F_100 ( V_190 -> V_45 ) ) ;
switch ( V_190 -> V_192 ) {
case V_194 :
V_5 -> V_39 = - V_195 ;
break;
case V_196 :
V_5 -> V_39 = - V_78 ;
break;
case V_197 :
V_5 -> V_39 = F_100 ( V_190 -> V_45 ) ;
break;
case V_198 :
switch ( V_190 -> V_193 ) {
case V_199 :
case V_200 :
V_5 -> V_39 = - V_36 ;
break;
default:
V_5 -> V_39 = - V_18 ;
break;
}
break;
default:
V_5 -> V_39 = - V_50 ;
break;
}
F_21 ( & V_5 -> V_38 , 1 ) ;
break;
case V_201 :
F_26 ( V_7 , L_52 , V_26 [ 1 ] , V_26 [ 2 ] ) ;
V_5 -> V_47 = V_26 [ 2 ] ;
if ( V_5 -> V_47 > sizeof( V_5 -> V_43 ) )
V_5 -> V_47 = sizeof( V_5 -> V_43 ) ;
memcpy ( V_5 -> V_43 , & V_26 [ 3 ] , V_5 -> V_47 ) ;
F_21 ( & V_5 -> V_46 , 1 ) ;
break;
default:
F_5 ( V_7 , L_53 ) ;
return 0 ;
}
F_101 ( & V_5 -> V_33 ) ;
return 1 ;
}
