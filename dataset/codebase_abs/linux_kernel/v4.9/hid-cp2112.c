static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( & V_5 -> V_12 , V_10 ) ;
V_11 = F_4 ( V_7 , V_13 , V_8 ,
V_14 , V_15 ,
V_16 ) ;
if ( V_11 != V_14 ) {
F_5 ( V_7 , L_1 , V_11 ) ;
goto exit;
}
V_8 [ 1 ] &= ~ ( 1 << V_3 ) ;
V_8 [ 2 ] = V_17 ;
V_11 = F_4 ( V_7 , V_13 , V_8 ,
V_14 , V_15 ,
V_18 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_2 , V_11 ) ;
goto exit;
}
V_11 = 0 ;
exit:
F_6 ( & V_5 -> V_12 , V_10 ) ;
return V_11 <= 0 ? V_11 : - V_19 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_20 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( & V_5 -> V_12 , V_10 ) ;
V_8 [ 0 ] = V_21 ;
V_8 [ 1 ] = V_20 ? 0xff : 0 ;
V_8 [ 2 ] = 1 << V_3 ;
V_11 = F_4 ( V_7 , V_21 , V_8 ,
V_22 , V_15 ,
V_18 ) ;
if ( V_11 < 0 )
F_5 ( V_7 , L_3 , V_11 ) ;
F_6 ( & V_5 -> V_12 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( & V_5 -> V_12 , V_10 ) ;
V_11 = F_4 ( V_7 , V_23 , V_8 ,
V_24 , V_15 ,
V_16 ) ;
if ( V_11 != V_24 ) {
F_5 ( V_7 , L_4 , V_11 ) ;
V_11 = V_11 < 0 ? V_11 : - V_19 ;
goto exit;
}
V_11 = ( V_8 [ 1 ] >> V_3 ) & 1 ;
exit:
F_6 ( & V_5 -> V_12 , V_10 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_20 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 * V_8 = V_5 -> V_9 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( & V_5 -> V_12 , V_10 ) ;
V_11 = F_4 ( V_7 , V_13 , V_8 ,
V_14 , V_15 ,
V_16 ) ;
if ( V_11 != V_14 ) {
F_5 ( V_7 , L_1 , V_11 ) ;
goto V_25;
}
V_8 [ 1 ] |= 1 << V_3 ;
V_8 [ 2 ] = V_17 ;
V_11 = F_4 ( V_7 , V_13 , V_8 ,
V_14 , V_15 ,
V_18 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_2 , V_11 ) ;
goto V_25;
}
F_6 ( & V_5 -> V_12 , V_10 ) ;
F_7 ( V_2 , V_3 , V_20 ) ;
return 0 ;
V_25:
F_6 ( & V_5 -> V_12 , V_10 ) ;
return V_11 < 0 ? V_11 : - V_19 ;
}
static int F_10 ( struct V_6 * V_7 , unsigned char V_26 ,
T_1 * V_27 , T_2 V_28 , unsigned char V_29 )
{
T_1 * V_8 ;
int V_11 ;
V_8 = F_11 ( V_28 , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
V_11 = F_4 ( V_7 , V_26 , V_8 , V_28 ,
V_29 , V_16 ) ;
memcpy ( V_27 , V_8 , V_28 ) ;
F_12 ( V_8 ) ;
return V_11 ;
}
static int F_13 ( struct V_6 * V_7 , T_1 * V_27 , T_2 V_28 ,
unsigned char V_29 )
{
T_1 * V_8 ;
int V_11 ;
V_8 = F_14 ( V_27 , V_28 , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
if ( V_29 == V_32 )
V_11 = F_15 ( V_7 , V_8 , V_28 ) ;
else
V_11 = F_4 ( V_7 , V_8 [ 0 ] , V_8 , V_28 , V_29 ,
V_18 ) ;
F_12 ( V_8 ) ;
return V_11 ;
}
static int F_16 ( struct V_4 * V_5 , T_3 * V_33 )
{
int V_11 = 0 ;
V_11 = F_17 ( V_5 -> V_34 ,
F_18 ( V_33 ) , F_19 ( V_35 ) ) ;
if ( - V_36 == V_11 )
return V_11 ;
if ( ! V_11 )
return - V_37 ;
F_20 ( V_33 , 0 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 2 ] ;
int V_11 ;
V_8 [ 0 ] = V_38 ;
V_8 [ 1 ] = 0x01 ;
F_20 ( & V_5 -> V_39 , 0 ) ;
V_11 = F_13 ( V_7 , V_8 , 2 , V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_7 , L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_5 , & V_5 -> V_39 ) ;
if ( V_11 )
return V_11 ;
return V_5 -> V_40 ;
}
static int F_23 ( struct V_4 * V_5 , T_1 * V_27 , T_2 V_41 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_42 V_43 ;
int V_11 ;
if ( V_41 > sizeof( V_5 -> V_44 ) )
V_41 = sizeof( V_5 -> V_44 ) ;
V_43 . V_43 = V_45 ;
V_43 . V_46 = F_24 ( V_41 ) ;
F_20 ( & V_5 -> V_47 , 0 ) ;
V_11 = F_13 ( V_7 , & V_43 . V_43 , sizeof( V_43 ) ,
V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_7 , L_6 , V_11 ) ;
return V_11 ;
}
V_11 = F_16 ( V_5 , & V_5 -> V_47 ) ;
if ( V_11 )
return V_11 ;
F_25 ( V_7 , L_7 ,
V_5 -> V_48 , V_41 ) ;
if ( V_41 > V_5 -> V_48 )
V_41 = V_5 -> V_48 ;
memcpy ( V_27 , V_5 -> V_44 , V_41 ) ;
return V_5 -> V_48 ;
}
static int F_26 ( void * V_8 , T_1 V_49 , T_4 V_46 )
{
struct V_50 * V_43 = V_8 ;
if ( V_46 < 1 || V_46 > 512 )
return - V_51 ;
V_43 -> V_43 = V_52 ;
V_43 -> V_49 = V_49 << 1 ;
V_43 -> V_46 = F_24 ( V_46 ) ;
return sizeof( * V_43 ) ;
}
static int F_27 ( void * V_8 , T_1 V_49 , T_4 V_46 ,
T_1 V_53 , T_1 * V_27 , T_1 V_54 )
{
struct V_55 * V_43 = V_8 ;
if ( V_46 < 1 || V_46 > 512
|| V_54 > sizeof( V_43 -> V_56 ) - 1 )
return - V_51 ;
V_43 -> V_43 = V_57 ;
V_43 -> V_49 = V_49 << 1 ;
V_43 -> V_46 = F_24 ( V_46 ) ;
V_43 -> V_58 = V_54 + 1 ;
V_43 -> V_56 [ 0 ] = V_53 ;
memcpy ( & V_43 -> V_56 [ 1 ] , V_27 , V_54 ) ;
return V_54 + 6 ;
}
static int F_28 ( void * V_8 , T_1 V_49 , T_1 V_53 , T_1 * V_27 ,
T_1 V_54 )
{
struct V_59 * V_43 = V_8 ;
if ( V_54 > sizeof( V_43 -> V_27 ) - 1 )
return - V_51 ;
V_43 -> V_43 = V_60 ;
V_43 -> V_49 = V_49 << 1 ;
V_43 -> V_46 = V_54 + 1 ;
V_43 -> V_27 [ 0 ] = V_53 ;
memcpy ( & V_43 -> V_27 [ 1 ] , V_27 , V_54 ) ;
return V_54 + 4 ;
}
static int F_29 ( void * V_8 , T_1 V_49 , T_1 * V_27 ,
T_1 V_54 )
{
struct V_59 * V_43 = V_8 ;
if ( V_54 > sizeof( V_43 -> V_27 ) )
return - V_51 ;
V_43 -> V_43 = V_60 ;
V_43 -> V_49 = V_49 << 1 ;
V_43 -> V_46 = V_54 ;
memcpy ( V_43 -> V_27 , V_27 , V_54 ) ;
return V_54 + 3 ;
}
static int F_30 ( void * V_8 , T_1 V_49 ,
T_1 * V_61 , int V_62 ,
int V_48 )
{
struct V_55 * V_43 = V_8 ;
if ( V_48 < 1 || V_48 > 512 ||
V_62 > sizeof( V_43 -> V_56 ) )
return - V_51 ;
V_43 -> V_43 = V_57 ;
V_43 -> V_49 = V_49 << 1 ;
V_43 -> V_46 = F_24 ( V_48 ) ;
V_43 -> V_58 = V_62 ;
memcpy ( V_43 -> V_56 , V_61 , V_62 ) ;
return V_62 + 5 ;
}
static int F_31 ( struct V_63 * V_64 , struct V_65 * V_66 ,
int V_67 )
{
struct V_4 * V_5 = (struct V_4 * ) V_64 -> V_68 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_5 V_28 ;
T_5 V_48 = 0 ;
T_1 * V_69 = NULL ;
unsigned int V_70 ;
int V_11 ;
F_25 ( V_7 , L_8 , V_67 ) ;
if ( V_67 == 1 ) {
if ( V_66 -> V_10 & V_71 ) {
F_25 ( V_7 , L_9 ,
V_66 -> V_61 , V_66 -> V_72 ) ;
V_48 = V_66 -> V_72 ;
V_69 = V_66 -> V_8 ;
V_28 = F_26 ( V_8 , V_66 -> V_61 , V_66 -> V_72 ) ;
} else {
F_25 ( V_7 , L_10 ,
V_66 -> V_61 , V_66 -> V_72 ) ;
V_28 = F_29 ( V_8 , V_66 -> V_61 ,
V_66 -> V_8 , V_66 -> V_72 ) ;
}
if ( V_28 < 0 )
return V_28 ;
} else if ( V_5 -> V_73 > 1 &&
V_67 == 2 &&
V_66 [ 0 ] . V_61 == V_66 [ 1 ] . V_61 &&
! ( V_66 [ 0 ] . V_10 & V_71 ) && ( V_66 [ 1 ] . V_10 & V_71 ) ) {
F_25 ( V_7 , L_11 ,
V_66 [ 0 ] . V_61 , V_66 [ 0 ] . V_72 , V_66 [ 1 ] . V_72 ) ;
V_48 = V_66 [ 1 ] . V_72 ;
V_69 = V_66 [ 1 ] . V_8 ;
V_28 = F_30 ( V_8 , V_66 [ 0 ] . V_61 ,
V_66 [ 0 ] . V_8 , V_66 [ 0 ] . V_72 , V_66 [ 1 ] . V_72 ) ;
if ( V_28 < 0 )
return V_28 ;
} else {
F_5 ( V_7 ,
L_12 ) ;
return - V_74 ;
}
V_11 = F_32 ( V_7 , V_75 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_13 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_7 , V_8 , V_28 , V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_7 , L_14 , V_11 ) ;
goto V_76;
}
for ( V_70 = 0 ; V_70 < V_77 ; ++ V_70 ) {
V_11 = F_21 ( V_5 ) ;
if ( - V_78 == V_11 )
continue;
if ( V_11 < 0 )
goto V_76;
break;
}
if ( V_77 <= V_70 ) {
F_22 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_79 ;
V_8 [ 1 ] = 0x01 ;
V_11 = F_13 ( V_7 , V_8 , 2 , V_32 ) ;
if ( V_11 < 0 )
F_22 ( V_7 , L_16 ,
V_11 ) ;
V_11 = - V_37 ;
goto V_76;
}
for ( V_28 = 0 ; V_28 < V_48 ; ) {
V_11 = F_23 ( V_5 , V_69 + V_28 , V_48 - V_28 ) ;
if ( V_11 < 0 )
goto V_76;
if ( V_11 == 0 ) {
F_5 ( V_7 , L_17 ) ;
V_11 = - V_19 ;
goto V_76;
}
V_28 += V_11 ;
if ( V_28 > V_48 ) {
F_5 ( V_7 , L_18 ,
V_11 , V_48 - V_28 + V_11 ) ;
V_11 = - V_19 ;
goto V_76;
}
}
V_11 = V_67 ;
V_76:
F_32 ( V_7 , V_80 ) ;
F_25 ( V_7 , L_19 , V_11 ) ;
return V_11 ;
}
static int F_33 ( struct V_63 * V_64 , T_4 V_61 ,
unsigned short V_10 , char V_81 , T_1 V_53 ,
int V_41 , union V_82 * V_27 )
{
struct V_4 * V_5 = (struct V_4 * ) V_64 -> V_68 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 [ 64 ] ;
T_6 V_83 ;
T_5 V_28 ;
T_2 V_48 = 0 ;
unsigned int V_70 ;
int V_11 ;
F_25 ( V_7 , L_20 ,
V_81 == V_84 ? L_21 : L_22 ,
V_61 , V_10 , V_53 , V_41 ) ;
switch ( V_41 ) {
case V_85 :
V_48 = 1 ;
if ( V_86 == V_81 )
V_28 = F_26 ( V_8 , V_61 , V_48 ) ;
else
V_28 = F_28 ( V_8 , V_61 , V_53 , NULL ,
0 ) ;
break;
case V_87 :
V_48 = 1 ;
if ( V_86 == V_81 )
V_28 = F_27 ( V_8 , V_61 , V_48 ,
V_53 , NULL , 0 ) ;
else
V_28 = F_28 ( V_8 , V_61 , V_53 ,
& V_27 -> V_88 , 1 ) ;
break;
case V_89 :
V_48 = 2 ;
V_83 = F_34 ( V_27 -> V_83 ) ;
if ( V_86 == V_81 )
V_28 = F_27 ( V_8 , V_61 , V_48 ,
V_53 , NULL , 0 ) ;
else
V_28 = F_28 ( V_8 , V_61 , V_53 ,
( T_1 * ) & V_83 , 2 ) ;
break;
case V_90 :
V_41 = V_89 ;
V_81 = V_86 ;
V_48 = 2 ;
V_83 = F_34 ( V_27 -> V_83 ) ;
V_28 = F_27 ( V_8 , V_61 , V_48 , V_53 ,
( T_1 * ) & V_83 , 2 ) ;
break;
case V_91 :
V_41 = V_92 ;
case V_92 :
if ( V_86 == V_81 ) {
V_28 = F_27 ( V_8 , V_61 ,
V_93 ,
V_53 , NULL , 0 ) ;
} else {
V_28 = F_28 ( V_8 , V_61 , V_53 ,
V_27 -> V_94 ,
V_27 -> V_94 [ 0 ] + 1 ) ;
}
break;
case V_95 :
V_41 = V_92 ;
V_81 = V_86 ;
V_28 = F_27 ( V_8 , V_61 , V_93 ,
V_53 , V_27 -> V_94 ,
V_27 -> V_94 [ 0 ] + 1 ) ;
break;
default:
F_22 ( V_7 , L_23 , V_41 ) ;
return - V_74 ;
}
if ( V_28 < 0 )
return V_28 ;
V_11 = F_32 ( V_7 , V_75 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_13 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_7 , V_8 , V_28 , V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_7 , L_14 , V_11 ) ;
goto V_76;
}
for ( V_70 = 0 ; V_70 < V_77 ; ++ V_70 ) {
V_11 = F_21 ( V_5 ) ;
if ( - V_78 == V_11 )
continue;
if ( V_11 < 0 )
goto V_76;
break;
}
if ( V_77 <= V_70 ) {
F_22 ( V_7 , L_15 ) ;
V_8 [ 0 ] = V_79 ;
V_8 [ 1 ] = 0x01 ;
V_11 = F_13 ( V_7 , V_8 , 2 , V_32 ) ;
if ( V_11 < 0 )
F_22 ( V_7 , L_16 ,
V_11 ) ;
V_11 = - V_37 ;
goto V_76;
}
if ( V_84 == V_81 ) {
V_11 = 0 ;
goto V_76;
}
if ( V_92 == V_41 )
V_48 = V_11 ;
V_11 = F_23 ( V_5 , V_8 , V_48 ) ;
if ( V_11 < 0 )
goto V_76;
if ( V_11 != V_48 ) {
F_22 ( V_7 , L_24 , V_11 , V_48 ) ;
V_11 = - V_19 ;
goto V_76;
}
switch ( V_41 ) {
case V_85 :
case V_87 :
V_27 -> V_88 = V_8 [ 0 ] ;
break;
case V_89 :
V_27 -> V_83 = F_35 ( ( T_6 * ) V_8 ) ;
break;
case V_92 :
if ( V_48 > V_93 ) {
V_11 = - V_96 ;
goto V_76;
}
memcpy ( V_27 -> V_94 , V_8 , V_48 ) ;
break;
}
V_11 = 0 ;
V_76:
F_32 ( V_7 , V_80 ) ;
F_25 ( V_7 , L_25 , V_11 ) ;
return V_11 ;
}
static T_7 F_36 ( struct V_63 * V_64 )
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
static int F_37 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
int V_11 ;
V_11 = F_10 ( V_7 , V_107 , ( T_1 * ) V_106 , sizeof( * V_106 ) ,
V_15 ) ;
if ( V_11 != sizeof( * V_106 ) ) {
F_5 ( V_7 , L_26 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_19 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
int V_11 ;
F_39 ( V_106 -> V_43 != V_107 ) ;
V_11 = F_13 ( V_7 , ( T_1 * ) V_106 , sizeof( * V_106 ) ,
V_15 ) ;
if ( V_11 != sizeof( * V_106 ) ) {
F_5 ( V_7 , L_27 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_19 ;
}
return 0 ;
}
static T_5 F_40 ( struct V_108 * V_109 ,
struct V_110 * V_111 , const char * V_8 ,
T_2 V_28 )
{
struct V_6 * V_7 = F_41 ( V_109 ) ;
struct V_112 * V_113 =
F_42 ( V_111 , struct V_112 , V_113 ) ;
struct V_114 V_43 ;
int V_11 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_11 = F_43 ( V_8 , V_28 , V_115 ,
V_43 . string , F_44 ( V_43 . string ) ) ;
V_43 . V_43 = V_113 -> V_43 ;
V_43 . V_46 = V_11 * sizeof( V_43 . string [ 0 ] ) + 2 ;
V_43 . type = V_116 ;
V_11 = F_13 ( V_7 , & V_43 . V_43 , V_43 . V_46 + 1 ,
V_15 ) ;
if ( V_11 != V_43 . V_46 + 1 ) {
F_5 ( V_7 , L_28 , V_111 -> V_113 . V_117 ,
V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_19 ;
}
F_45 ( V_7 ) ;
return V_28 ;
}
static T_5 F_46 ( struct V_108 * V_109 ,
struct V_110 * V_111 , char * V_8 )
{
struct V_6 * V_7 = F_41 ( V_109 ) ;
struct V_112 * V_113 =
F_42 ( V_111 , struct V_112 , V_113 ) ;
struct V_114 V_43 ;
T_1 V_46 ;
int V_11 ;
V_11 = F_10 ( V_7 , V_113 -> V_43 , & V_43 . V_43 ,
sizeof( V_43 ) - 1 , V_15 ) ;
if ( V_11 < 3 ) {
F_5 ( V_7 , L_29 , V_111 -> V_113 . V_117 ,
V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_19 ;
}
if ( V_43 . V_46 < 2 ) {
F_5 ( V_7 , L_30 ,
V_111 -> V_113 . V_117 , V_43 . V_46 ) ;
return - V_19 ;
}
V_46 = V_43 . V_46 > V_11 - 1 ? V_11 - 1 : V_43 . V_46 ;
V_46 = ( V_46 - 2 ) / sizeof( V_43 . string [ 0 ] ) ;
V_11 = F_47 ( V_43 . string , V_46 , V_115 , V_8 ,
V_118 - 1 ) ;
V_8 [ V_11 ++ ] = '\n' ;
return V_11 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_119 * * V_113 ;
T_1 V_8 [ 2 ] ;
int V_11 ;
V_11 = F_10 ( V_7 , V_120 , V_8 , sizeof( V_8 ) ,
V_15 ) ;
if ( V_11 != sizeof( V_8 ) ) {
F_5 ( V_7 , L_31 , V_11 ) ;
return;
}
for ( V_113 = V_121 . V_122 ; * V_113 ; ++ V_113 ) {
T_8 V_123 = ( V_8 [ 1 ] & 1 ) ? V_124 | V_125 : V_125 ;
V_11 = F_48 ( & V_7 -> V_5 . V_126 , * V_113 , V_123 ) ;
if ( V_11 < 0 )
F_5 ( V_7 , L_32 ,
( * V_113 ) -> V_117 ) ;
V_8 [ 1 ] >>= 1 ;
}
}
static int F_49 ( struct V_6 * V_7 , const struct V_127 * V_128 )
{
struct V_4 * V_5 ;
T_1 V_8 [ 3 ] ;
struct V_129 V_130 ;
int V_11 ;
V_5 = F_50 ( & V_7 -> V_5 , sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 )
return - V_31 ;
V_5 -> V_9 = F_50 ( & V_7 -> V_5 , V_131 ,
V_30 ) ;
if ( ! V_5 -> V_9 )
return - V_31 ;
F_51 ( & V_5 -> V_12 ) ;
V_11 = F_52 ( V_7 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_33 ) ;
return V_11 ;
}
V_11 = F_53 ( V_7 , V_132 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_34 ) ;
return V_11 ;
}
V_11 = F_54 ( V_7 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_35 ) ;
goto V_133;
}
V_11 = F_32 ( V_7 , V_75 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_13 , V_11 ) ;
goto V_134;
}
V_11 = F_10 ( V_7 , V_135 , V_8 , sizeof( V_8 ) ,
V_15 ) ;
if ( V_11 != sizeof( V_8 ) ) {
F_5 ( V_7 , L_36 ) ;
if ( V_11 >= 0 )
V_11 = - V_19 ;
goto V_136;
}
F_55 ( V_7 , L_37 ,
V_8 [ 1 ] , V_8 [ 2 ] ) ;
V_11 = F_10 ( V_7 , V_137 , ( T_1 * ) & V_130 ,
sizeof( V_130 ) , V_15 ) ;
if ( V_11 != sizeof( V_130 ) ) {
F_5 ( V_7 , L_38 ) ;
if ( V_11 >= 0 )
V_11 = - V_19 ;
goto V_136;
}
V_130 . V_138 = F_24 ( 1 ) ;
V_11 = F_13 ( V_7 , ( T_1 * ) & V_130 , sizeof( V_130 ) ,
V_15 ) ;
if ( V_11 != sizeof( V_130 ) ) {
F_5 ( V_7 , L_39 ) ;
if ( V_11 >= 0 )
V_11 = - V_19 ;
goto V_136;
}
F_56 ( V_7 , ( void * ) V_5 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_64 . V_139 = V_140 ;
V_5 -> V_64 . V_141 = V_142 ;
V_5 -> V_64 . V_143 = & V_144 ;
V_5 -> V_64 . V_68 = V_5 ;
V_5 -> V_64 . V_5 . V_145 = & V_7 -> V_5 ;
snprintf ( V_5 -> V_64 . V_117 , sizeof( V_5 -> V_64 . V_117 ) ,
L_40 , V_7 -> V_146 ) ;
V_5 -> V_73 = V_8 [ 2 ] ;
F_57 ( & V_5 -> V_34 ) ;
F_58 ( V_7 ) ;
V_11 = F_59 ( & V_5 -> V_64 ) ;
F_60 ( V_7 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_41 ) ;
goto V_136;
}
F_25 ( V_7 , L_42 ) ;
V_5 -> V_147 . V_148 = L_43 ;
V_5 -> V_147 . V_149 = F_1 ;
V_5 -> V_147 . V_150 = F_9 ;
V_5 -> V_147 . V_151 = F_7 ;
V_5 -> V_147 . V_152 = F_8 ;
V_5 -> V_147 . V_153 = - 1 ;
V_5 -> V_147 . V_154 = 8 ;
V_5 -> V_147 . V_155 = 1 ;
V_5 -> V_147 . V_145 = & V_7 -> V_5 ;
V_11 = F_61 ( & V_5 -> V_147 , V_5 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_44 ) ;
goto V_156;
}
V_11 = F_62 ( & V_7 -> V_5 . V_126 , & V_121 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_45 ) ;
goto V_157;
}
F_45 ( V_7 ) ;
F_32 ( V_7 , V_80 ) ;
return V_11 ;
V_157:
F_63 ( & V_5 -> V_147 ) ;
V_156:
F_64 ( & V_5 -> V_64 ) ;
V_136:
F_32 ( V_7 , V_80 ) ;
V_134:
F_65 ( V_7 ) ;
V_133:
F_66 ( V_7 ) ;
return V_11 ;
}
static void F_67 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_68 ( V_7 ) ;
F_69 ( & V_7 -> V_5 . V_126 , & V_121 ) ;
F_63 ( & V_5 -> V_147 ) ;
F_64 ( & V_5 -> V_64 ) ;
F_65 ( V_7 ) ;
F_66 ( V_7 ) ;
}
static int F_70 ( struct V_6 * V_7 , struct V_158 * V_43 ,
T_1 * V_27 , int V_41 )
{
struct V_4 * V_5 = F_68 ( V_7 ) ;
struct V_159 * V_160 = ( void * ) V_27 ;
switch ( V_27 [ 0 ] ) {
case V_161 :
F_25 ( V_7 , L_46 ,
V_160 -> V_162 , V_160 -> V_163 ,
F_71 ( V_160 -> V_70 ) , F_71 ( V_160 -> V_46 ) ) ;
switch ( V_160 -> V_162 ) {
case V_164 :
V_5 -> V_40 = - V_165 ;
break;
case V_166 :
V_5 -> V_40 = - V_78 ;
break;
case V_167 :
V_5 -> V_40 = F_71 ( V_160 -> V_46 ) ;
break;
case V_168 :
switch ( V_160 -> V_163 ) {
case V_169 :
case V_170 :
V_5 -> V_40 = - V_37 ;
break;
default:
V_5 -> V_40 = - V_19 ;
break;
}
break;
default:
V_5 -> V_40 = - V_51 ;
break;
}
F_20 ( & V_5 -> V_39 , 1 ) ;
break;
case V_171 :
F_25 ( V_7 , L_47 , V_27 [ 1 ] , V_27 [ 2 ] ) ;
V_5 -> V_48 = V_27 [ 2 ] ;
if ( V_5 -> V_48 > sizeof( V_5 -> V_44 ) )
V_5 -> V_48 = sizeof( V_5 -> V_44 ) ;
memcpy ( V_5 -> V_44 , & V_27 [ 3 ] , V_5 -> V_48 ) ;
F_20 ( & V_5 -> V_47 , 1 ) ;
break;
default:
F_5 ( V_7 , L_48 ) ;
return 0 ;
}
F_72 ( & V_5 -> V_34 ) ;
return 1 ;
}
