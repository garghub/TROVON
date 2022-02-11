static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 5 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 ,
sizeof( V_9 ) , V_12 ,
V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_1 , V_10 ) ;
return V_10 ;
}
V_9 [ 1 ] &= ~ ( 1 << V_3 ) ;
V_9 [ 2 ] = V_14 ;
V_10 = F_3 ( V_8 , V_11 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 3 ] ;
int V_10 ;
V_9 [ 0 ] = V_17 ;
V_9 [ 1 ] = V_16 ? 0xff : 0 ;
V_9 [ 2 ] = 1 << V_3 ;
V_10 = F_3 ( V_8 , V_17 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 )
F_4 ( V_8 , L_3 , V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_18 , V_9 , sizeof( V_9 ) ,
V_12 , V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_4 , V_10 ) ;
return V_10 ;
}
return ( V_9 [ 1 ] >> V_3 ) & 1 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 5 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 ,
sizeof( V_9 ) , V_12 ,
V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_1 , V_10 ) ;
return V_10 ;
}
V_9 [ 1 ] |= 1 << V_3 ;
V_9 [ 2 ] = V_14 ;
V_10 = F_3 ( V_8 , V_11 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_2 , V_10 ) ;
return V_10 ;
}
F_5 ( V_2 , V_3 , V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , unsigned char V_19 ,
T_1 * V_20 , T_2 V_21 , unsigned char V_22 )
{
T_1 * V_9 ;
int V_10 ;
V_9 = F_9 ( V_21 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_10 = F_3 ( V_8 , V_19 , V_9 , V_21 ,
V_22 , V_13 ) ;
memcpy ( V_20 , V_9 , V_21 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static int F_11 ( struct V_7 * V_8 , T_1 * V_20 , T_2 V_21 ,
unsigned char V_22 )
{
T_1 * V_9 ;
int V_10 ;
V_9 = F_12 ( V_20 , V_21 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
if ( V_22 == V_25 )
V_10 = F_13 ( V_8 , V_9 , V_21 ) ;
else
V_10 = F_3 ( V_8 , V_9 [ 0 ] , V_9 , V_21 , V_22 ,
V_15 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static int F_14 ( struct V_4 * V_5 , T_3 * V_26 )
{
int V_10 = 0 ;
V_10 = F_15 ( V_5 -> V_27 ,
F_16 ( V_26 ) , F_17 ( V_28 ) ) ;
if ( - V_29 == V_10 )
return V_10 ;
if ( ! V_10 )
return - V_30 ;
F_18 ( V_26 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] = V_31 ;
V_9 [ 1 ] = 0x01 ;
F_18 ( & V_5 -> V_32 , 0 ) ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_5 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_5 , & V_5 -> V_32 ) ;
if ( V_10 )
return V_10 ;
return V_5 -> V_33 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 * V_20 , T_2 V_34 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_35 V_36 ;
int V_10 ;
if ( V_34 > sizeof( V_5 -> V_37 ) )
V_34 = sizeof( V_5 -> V_37 ) ;
V_36 . V_36 = V_38 ;
V_36 . V_39 = F_22 ( V_34 ) ;
F_18 ( & V_5 -> V_40 , 0 ) ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , sizeof( V_36 ) ,
V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_5 , & V_5 -> V_40 ) ;
if ( V_10 )
return V_10 ;
F_23 ( V_8 , L_7 ,
V_5 -> V_41 , V_34 ) ;
if ( V_34 > V_5 -> V_41 )
V_34 = V_5 -> V_41 ;
memcpy ( V_20 , V_5 -> V_37 , V_34 ) ;
return V_5 -> V_41 ;
}
static int F_24 ( void * V_9 , T_1 V_42 , T_4 V_39 )
{
struct V_43 * V_36 = V_9 ;
if ( V_39 < 1 || V_39 > 512 )
return - V_44 ;
V_36 -> V_36 = V_45 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = F_22 ( V_39 ) ;
return sizeof( * V_36 ) ;
}
static int F_25 ( void * V_9 , T_1 V_42 , T_4 V_39 ,
T_1 V_46 , T_1 * V_20 , T_1 V_47 )
{
struct V_48 * V_36 = V_9 ;
if ( V_39 < 1 || V_39 > 512
|| V_47 > sizeof( V_36 -> V_49 ) - 1 )
return - V_44 ;
V_36 -> V_36 = V_50 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = F_22 ( V_39 ) ;
V_36 -> V_51 = V_47 + 1 ;
V_36 -> V_49 [ 0 ] = V_46 ;
memcpy ( & V_36 -> V_49 [ 1 ] , V_20 , V_47 ) ;
return V_47 + 6 ;
}
static int F_26 ( void * V_9 , T_1 V_42 , T_1 V_46 , T_1 * V_20 ,
T_1 V_47 )
{
struct V_52 * V_36 = V_9 ;
if ( V_47 > sizeof( V_36 -> V_20 ) - 1 )
return - V_44 ;
V_36 -> V_36 = V_53 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = V_47 + 1 ;
V_36 -> V_20 [ 0 ] = V_46 ;
memcpy ( & V_36 -> V_20 [ 1 ] , V_20 , V_47 ) ;
return V_47 + 4 ;
}
static int F_27 ( void * V_9 , T_1 V_42 , T_1 * V_20 ,
T_1 V_47 )
{
struct V_52 * V_36 = V_9 ;
if ( V_47 > sizeof( V_36 -> V_20 ) )
return - V_44 ;
V_36 -> V_36 = V_53 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = V_47 ;
memcpy ( V_36 -> V_20 , V_20 , V_47 ) ;
return V_47 + 3 ;
}
static int F_28 ( void * V_9 , T_1 V_42 ,
T_1 * V_54 , int V_55 ,
int V_41 )
{
struct V_48 * V_36 = V_9 ;
if ( V_41 < 1 || V_41 > 512 ||
V_55 > sizeof( V_36 -> V_49 ) )
return - V_44 ;
V_36 -> V_36 = V_50 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = F_22 ( V_41 ) ;
V_36 -> V_51 = V_55 ;
memcpy ( V_36 -> V_49 , V_54 , V_55 ) ;
return V_55 + 5 ;
}
static int F_29 ( struct V_56 * V_57 , struct V_58 * V_59 ,
int V_60 )
{
struct V_4 * V_5 = (struct V_4 * ) V_57 -> V_61 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 64 ] ;
T_5 V_21 ;
T_5 V_41 = 0 ;
T_1 * V_62 = NULL ;
unsigned int V_63 ;
int V_10 ;
F_23 ( V_8 , L_8 , V_60 ) ;
if ( V_60 == 1 ) {
if ( V_59 -> V_64 & V_65 ) {
F_23 ( V_8 , L_9 ,
V_59 -> V_54 , V_59 -> V_66 ) ;
V_41 = V_59 -> V_66 ;
V_62 = V_59 -> V_9 ;
V_21 = F_24 ( V_9 , V_59 -> V_54 , V_59 -> V_66 ) ;
} else {
F_23 ( V_8 , L_10 ,
V_59 -> V_54 , V_59 -> V_66 ) ;
V_21 = F_27 ( V_9 , V_59 -> V_54 ,
V_59 -> V_9 , V_59 -> V_66 ) ;
}
if ( V_21 < 0 )
return V_21 ;
} else if ( V_5 -> V_67 > 1 &&
V_60 == 2 &&
V_59 [ 0 ] . V_54 == V_59 [ 1 ] . V_54 &&
! ( V_59 [ 0 ] . V_64 & V_65 ) && ( V_59 [ 1 ] . V_64 & V_65 ) ) {
F_23 ( V_8 , L_11 ,
V_59 [ 0 ] . V_54 , V_59 [ 0 ] . V_66 , V_59 [ 1 ] . V_66 ) ;
V_41 = V_59 [ 1 ] . V_66 ;
V_62 = V_59 [ 1 ] . V_9 ;
V_21 = F_28 ( V_9 , V_59 [ 0 ] . V_54 ,
V_59 [ 0 ] . V_9 , V_59 [ 0 ] . V_66 , V_59 [ 1 ] . V_66 ) ;
if ( V_21 < 0 )
return V_21 ;
} else {
F_4 ( V_8 ,
L_12 ) ;
return - V_68 ;
}
V_10 = F_30 ( V_8 , V_69 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_8 , V_9 , V_21 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_14 , V_10 ) ;
goto V_70;
}
for ( V_63 = 0 ; V_63 < V_71 ; ++ V_63 ) {
V_10 = F_19 ( V_5 ) ;
if ( - V_72 == V_10 )
continue;
if ( V_10 < 0 )
goto V_70;
break;
}
if ( V_71 <= V_63 ) {
F_20 ( V_8 , L_15 ) ;
V_9 [ 0 ] = V_73 ;
V_9 [ 1 ] = 0x01 ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 )
F_20 ( V_8 , L_16 ,
V_10 ) ;
V_10 = - V_30 ;
goto V_70;
}
for ( V_21 = 0 ; V_21 < V_41 ; ) {
V_10 = F_21 ( V_5 , V_62 + V_21 , V_41 - V_21 ) ;
if ( V_10 < 0 )
goto V_70;
if ( V_10 == 0 ) {
F_4 ( V_8 , L_17 ) ;
V_10 = - V_74 ;
goto V_70;
}
V_21 += V_10 ;
if ( V_21 > V_41 ) {
F_4 ( V_8 , L_18 ,
V_10 , V_41 - V_21 + V_10 ) ;
V_10 = - V_74 ;
goto V_70;
}
}
V_10 = V_60 ;
V_70:
F_30 ( V_8 , V_75 ) ;
F_23 ( V_8 , L_19 , V_10 ) ;
return V_10 ;
}
static int F_31 ( struct V_56 * V_57 , T_4 V_54 ,
unsigned short V_64 , char V_76 , T_1 V_46 ,
int V_34 , union V_77 * V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_57 -> V_61 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 64 ] ;
T_6 V_78 ;
T_5 V_21 ;
T_2 V_41 = 0 ;
unsigned int V_63 ;
int V_10 ;
F_23 ( V_8 , L_20 ,
V_76 == V_79 ? L_21 : L_22 ,
V_54 , V_64 , V_46 , V_34 ) ;
switch ( V_34 ) {
case V_80 :
V_41 = 1 ;
if ( V_81 == V_76 )
V_21 = F_24 ( V_9 , V_54 , V_41 ) ;
else
V_21 = F_26 ( V_9 , V_54 , V_46 , NULL ,
0 ) ;
break;
case V_82 :
V_41 = 1 ;
if ( V_81 == V_76 )
V_21 = F_25 ( V_9 , V_54 , V_41 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_54 , V_46 ,
& V_20 -> V_83 , 1 ) ;
break;
case V_84 :
V_41 = 2 ;
V_78 = F_32 ( V_20 -> V_78 ) ;
if ( V_81 == V_76 )
V_21 = F_25 ( V_9 , V_54 , V_41 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_54 , V_46 ,
( T_1 * ) & V_78 , 2 ) ;
break;
case V_85 :
V_34 = V_84 ;
V_76 = V_81 ;
V_41 = 2 ;
V_78 = F_32 ( V_20 -> V_78 ) ;
V_21 = F_25 ( V_9 , V_54 , V_41 , V_46 ,
( T_1 * ) & V_78 , 2 ) ;
break;
case V_86 :
V_34 = V_87 ;
case V_87 :
if ( V_81 == V_76 ) {
V_21 = F_25 ( V_9 , V_54 ,
V_88 ,
V_46 , NULL , 0 ) ;
} else {
V_21 = F_26 ( V_9 , V_54 , V_46 ,
V_20 -> V_89 ,
V_20 -> V_89 [ 0 ] + 1 ) ;
}
break;
case V_90 :
V_34 = V_87 ;
V_76 = V_81 ;
V_21 = F_25 ( V_9 , V_54 , V_88 ,
V_46 , V_20 -> V_89 ,
V_20 -> V_89 [ 0 ] + 1 ) ;
break;
default:
F_20 ( V_8 , L_23 , V_34 ) ;
return - V_68 ;
}
if ( V_21 < 0 )
return V_21 ;
V_10 = F_30 ( V_8 , V_69 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_8 , V_9 , V_21 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_14 , V_10 ) ;
goto V_70;
}
for ( V_63 = 0 ; V_63 < V_71 ; ++ V_63 ) {
V_10 = F_19 ( V_5 ) ;
if ( - V_72 == V_10 )
continue;
if ( V_10 < 0 )
goto V_70;
break;
}
if ( V_71 <= V_63 ) {
F_20 ( V_8 , L_15 ) ;
V_9 [ 0 ] = V_73 ;
V_9 [ 1 ] = 0x01 ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 )
F_20 ( V_8 , L_16 ,
V_10 ) ;
V_10 = - V_30 ;
goto V_70;
}
if ( V_79 == V_76 ) {
V_10 = 0 ;
goto V_70;
}
if ( V_87 == V_34 )
V_41 = V_10 ;
V_10 = F_21 ( V_5 , V_9 , V_41 ) ;
if ( V_10 < 0 )
goto V_70;
if ( V_10 != V_41 ) {
F_20 ( V_8 , L_24 , V_10 , V_41 ) ;
V_10 = - V_74 ;
goto V_70;
}
switch ( V_34 ) {
case V_80 :
case V_82 :
V_20 -> V_83 = V_9 [ 0 ] ;
break;
case V_84 :
V_20 -> V_78 = F_33 ( ( T_6 * ) V_9 ) ;
break;
case V_87 :
if ( V_41 > V_88 ) {
V_10 = - V_91 ;
goto V_70;
}
memcpy ( V_20 -> V_89 , V_9 , V_41 ) ;
break;
}
V_10 = 0 ;
V_70:
F_30 ( V_8 , V_75 ) ;
F_23 ( V_8 , L_25 , V_10 ) ;
return V_10 ;
}
static T_7 F_34 ( struct V_56 * V_57 )
{
return V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_100 * V_101 )
{
int V_10 ;
V_10 = F_8 ( V_8 , V_102 , ( T_1 * ) V_101 , sizeof( * V_101 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_101 ) ) {
F_4 ( V_8 , L_26 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_74 ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 ,
struct V_100 * V_101 )
{
int V_10 ;
F_37 ( V_101 -> V_36 != V_102 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) V_101 , sizeof( * V_101 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_101 ) ) {
F_4 ( V_8 , L_27 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_74 ;
}
return 0 ;
}
static T_5 F_38 ( struct V_103 * V_104 ,
struct V_105 * V_106 , const char * V_9 ,
T_2 V_21 )
{
struct V_7 * V_8 = F_2 ( V_104 , struct V_7 , V_5 ) ;
struct V_107 * V_108 =
F_2 ( V_106 , struct V_107 , V_108 ) ;
struct V_109 V_36 ;
int V_10 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_10 = F_39 ( V_9 , V_21 , V_110 ,
V_36 . string , F_40 ( V_36 . string ) ) ;
V_36 . V_36 = V_108 -> V_36 ;
V_36 . V_39 = V_10 * sizeof( V_36 . string [ 0 ] ) + 2 ;
V_36 . type = V_111 ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , V_36 . V_39 + 1 ,
V_12 ) ;
if ( V_10 != V_36 . V_39 + 1 ) {
F_4 ( V_8 , L_28 , V_106 -> V_108 . V_112 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_74 ;
}
F_41 ( V_8 ) ;
return V_21 ;
}
static T_5 F_42 ( struct V_103 * V_104 ,
struct V_105 * V_106 , char * V_9 )
{
struct V_7 * V_8 = F_2 ( V_104 , struct V_7 , V_5 ) ;
struct V_107 * V_108 =
F_2 ( V_106 , struct V_107 , V_108 ) ;
struct V_109 V_36 ;
T_1 V_39 ;
int V_10 ;
V_10 = F_8 ( V_8 , V_108 -> V_36 , & V_36 . V_36 ,
sizeof( V_36 ) - 1 , V_12 ) ;
if ( V_10 < 3 ) {
F_4 ( V_8 , L_29 , V_106 -> V_108 . V_112 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_74 ;
}
if ( V_36 . V_39 < 2 ) {
F_4 ( V_8 , L_30 ,
V_106 -> V_108 . V_112 , V_36 . V_39 ) ;
return - V_74 ;
}
V_39 = V_36 . V_39 > V_10 - 1 ? V_10 - 1 : V_36 . V_39 ;
V_39 = ( V_39 - 2 ) / sizeof( V_36 . string [ 0 ] ) ;
V_10 = F_43 ( V_36 . string , V_39 , V_110 , V_9 ,
V_113 - 1 ) ;
V_9 [ V_10 ++ ] = '\n' ;
return V_10 ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_114 * * V_108 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_10 = F_8 ( V_8 , V_115 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_31 , V_10 ) ;
return;
}
for ( V_108 = V_116 . V_117 ; * V_108 ; ++ V_108 ) {
T_8 V_118 = ( V_9 [ 1 ] & 1 ) ? V_119 | V_120 : V_120 ;
V_10 = F_44 ( & V_8 -> V_5 . V_121 , * V_108 , V_118 ) ;
if ( V_10 < 0 )
F_4 ( V_8 , L_32 ,
( * V_108 ) -> V_112 ) ;
V_9 [ 1 ] >>= 1 ;
}
}
static int F_45 ( struct V_7 * V_8 , const struct V_122 * V_123 )
{
struct V_4 * V_5 ;
T_1 V_9 [ 3 ] ;
struct V_124 V_125 ;
int V_10 ;
V_10 = F_46 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_33 ) ;
return V_10 ;
}
V_10 = F_47 ( V_8 , V_126 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_34 ) ;
return V_10 ;
}
V_10 = F_48 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_35 ) ;
goto V_127;
}
V_10 = F_30 ( V_8 , V_69 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_13 , V_10 ) ;
goto V_128;
}
V_10 = F_8 ( V_8 , V_129 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_36 ) ;
if ( V_10 >= 0 )
V_10 = - V_74 ;
goto V_130;
}
F_49 ( V_8 , L_37 ,
V_9 [ 1 ] , V_9 [ 2 ] ) ;
V_10 = F_8 ( V_8 , V_131 , ( T_1 * ) & V_125 ,
sizeof( V_125 ) , V_12 ) ;
if ( V_10 != sizeof( V_125 ) ) {
F_4 ( V_8 , L_38 ) ;
if ( V_10 >= 0 )
V_10 = - V_74 ;
goto V_130;
}
V_125 . V_132 = F_22 ( 1 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) & V_125 , sizeof( V_125 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_125 ) ) {
F_4 ( V_8 , L_39 ) ;
if ( V_10 >= 0 )
V_10 = - V_74 ;
goto V_130;
}
V_5 = F_50 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
V_10 = - V_24 ;
goto V_130;
}
F_51 ( V_8 , ( void * ) V_5 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_57 . V_133 = V_134 ;
V_5 -> V_57 . V_135 = V_136 ;
V_5 -> V_57 . V_137 = & V_138 ;
V_5 -> V_57 . V_61 = V_5 ;
V_5 -> V_57 . V_5 . V_139 = & V_8 -> V_5 ;
snprintf ( V_5 -> V_57 . V_112 , sizeof( V_5 -> V_57 . V_112 ) ,
L_40 , V_8 -> V_140 ) ;
V_5 -> V_67 = V_9 [ 2 ] ;
F_52 ( & V_5 -> V_27 ) ;
F_53 ( V_8 ) ;
V_10 = F_54 ( & V_5 -> V_57 ) ;
F_55 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_41 ) ;
goto V_141;
}
F_23 ( V_8 , L_42 ) ;
V_5 -> V_6 . V_142 = L_43 ;
V_5 -> V_6 . V_143 = F_1 ;
V_5 -> V_6 . V_144 = F_7 ;
V_5 -> V_6 . V_145 = F_5 ;
V_5 -> V_6 . V_146 = F_6 ;
V_5 -> V_6 . V_147 = - 1 ;
V_5 -> V_6 . V_148 = 8 ;
V_5 -> V_6 . V_149 = 1 ;
V_5 -> V_6 . V_5 = & V_8 -> V_5 ;
V_10 = F_56 ( & V_5 -> V_6 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_44 ) ;
goto V_150;
}
V_10 = F_57 ( & V_8 -> V_5 . V_121 , & V_116 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_45 ) ;
goto V_151;
}
F_41 ( V_8 ) ;
F_30 ( V_8 , V_75 ) ;
return V_10 ;
V_151:
F_58 ( & V_5 -> V_6 ) ;
V_150:
F_59 ( & V_5 -> V_57 ) ;
V_141:
F_10 ( V_5 ) ;
V_130:
F_30 ( V_8 , V_75 ) ;
V_128:
F_60 ( V_8 ) ;
V_127:
F_61 ( V_8 ) ;
return V_10 ;
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_63 ( V_8 ) ;
F_64 ( & V_8 -> V_5 . V_121 , & V_116 ) ;
F_58 ( & V_5 -> V_6 ) ;
F_59 ( & V_5 -> V_57 ) ;
F_60 ( V_8 ) ;
F_61 ( V_8 ) ;
F_10 ( V_5 ) ;
}
static int F_65 ( struct V_7 * V_8 , struct V_152 * V_36 ,
T_1 * V_20 , int V_34 )
{
struct V_4 * V_5 = F_63 ( V_8 ) ;
struct V_153 * V_154 = ( void * ) V_20 ;
switch ( V_20 [ 0 ] ) {
case V_155 :
F_23 ( V_8 , L_46 ,
V_154 -> V_156 , V_154 -> V_157 ,
F_66 ( V_154 -> V_63 ) , F_66 ( V_154 -> V_39 ) ) ;
switch ( V_154 -> V_156 ) {
case V_158 :
V_5 -> V_33 = - V_159 ;
break;
case V_160 :
V_5 -> V_33 = - V_72 ;
break;
case V_161 :
V_5 -> V_33 = F_66 ( V_154 -> V_39 ) ;
break;
case V_162 :
switch ( V_154 -> V_157 ) {
case V_163 :
case V_164 :
V_5 -> V_33 = - V_30 ;
break;
default:
V_5 -> V_33 = - V_74 ;
break;
}
break;
default:
V_5 -> V_33 = - V_44 ;
break;
}
F_18 ( & V_5 -> V_32 , 1 ) ;
break;
case V_165 :
F_23 ( V_8 , L_47 , V_20 [ 1 ] , V_20 [ 2 ] ) ;
V_5 -> V_41 = V_20 [ 2 ] ;
if ( V_5 -> V_41 > sizeof( V_5 -> V_37 ) )
V_5 -> V_41 = sizeof( V_5 -> V_37 ) ;
memcpy ( V_5 -> V_37 , & V_20 [ 3 ] , V_5 -> V_41 ) ;
F_18 ( & V_5 -> V_40 , 1 ) ;
break;
default:
F_4 ( V_8 , L_48 ) ;
return 0 ;
}
F_67 ( & V_5 -> V_27 ) ;
return 1 ;
}
