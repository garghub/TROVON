static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
unsigned char V_4 [ 2 ] ;
int V_5 = 0 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 , 2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_3 = ( ( V_4 [ 0 ] & 0xff ) << 4 ) | ( V_4 [ 1 ] & 0x0f ) ;
* V_3 = ( ( * V_3 & 0xfff ) * 9 * 125 ) >> 9 ;
F_3 ( V_2 -> V_8 , L_1 , V_9 , * V_3 ) ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 ,
int V_10 , int V_11 )
{
int V_3 ;
if ( V_10 <= 0 )
V_3 = 0 ;
else
V_3 = ( V_10 << 5 ) / 1125 ;
F_5 ( V_2 -> V_6 , V_12 , V_3 ) ;
F_3 ( V_2 -> V_8 , L_2 , V_10 , V_3 ) ;
if ( V_11 <= 0 )
V_3 = 0xff ;
else
V_3 = ( V_11 << 5 ) / 1125 ;
F_5 ( V_2 -> V_6 , V_13 , V_3 ) ;
F_3 ( V_2 -> V_8 , L_3 , V_11 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_10 , int V_11 )
{
int V_3 ;
if ( V_10 <= 0 )
V_3 = 0 ;
else
V_3 = ( V_10 << 5 ) / 675 ;
F_5 ( V_2 -> V_6 , V_14 , V_3 ) ;
F_3 ( V_2 -> V_8 , L_4 , V_10 , V_3 ) ;
if ( V_11 <= 0 )
V_3 = 0xff ;
else
V_3 = ( V_11 << 5 ) / 675 ;
F_5 ( V_2 -> V_6 , V_15 , V_3 ) ;
F_3 ( V_2 -> V_8 , L_5 , V_11 , V_3 ) ;
return;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
F_3 ( V_2 -> V_8 , L_6 ) ;
F_6 ( V_2 , 0 , 0 ) ;
V_5 = F_5 ( V_2 -> V_16 , V_17 ,
V_18 | V_19 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_21 , 3 ,
V_22 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_23 , ( 0xf << 4 ) ,
V_24 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_5 ( V_2 -> V_6 , V_25 ,
V_26 | V_27 |
V_28 | V_29 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_30 ,
V_31 | V_32 ,
V_31 | V_32 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_21 , 3 ,
V_33 ) ;
V_20:
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
F_3 ( V_2 -> V_8 , L_7 ) ;
V_5 = F_5 ( V_2 -> V_6 , V_21 ,
V_22 | V_34 |
V_35 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_5 ( V_2 -> V_16 , V_17 ,
V_36 | V_19 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_37 , 0x1f ,
V_38 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_23 , ( 0xf << 4 ) ,
V_24 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_25 ,
V_28 | V_29 ,
V_28 | V_29 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_39 ,
V_40 | V_41 |
V_42 ,
V_40 | V_41 |
V_42 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_30 ,
V_31 | V_32 ,
V_31 | V_32 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_8 ( V_2 -> V_6 , V_21 , 3 ,
V_43 ) ;
F_4 ( V_2 , V_44 , V_45 ) ;
V_20:
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , int V_46 )
{
F_3 ( V_2 -> V_8 , L_8 ) ;
F_8 ( V_2 -> V_6 , V_21 , 3 , V_22 ) ;
if ( V_46 > V_47 && V_2 -> V_48 )
F_6 ( V_2 , V_47 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_8 , L_9 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
union V_51 V_3 ;
unsigned char V_52 [] [ 16 ] = { L_10 , L_11 , L_12 ,
L_13 ,
} ;
int V_5 ;
int V_46 ;
V_50 = F_13 ( V_53 [ 0 ] ) ;
if ( ! V_50 )
return - V_54 ;
V_5 = V_50 -> V_55 ( V_50 , V_56 , & V_3 ) ;
if ( V_5 )
return V_5 ;
V_46 = V_3 . V_57 / 1000 ;
V_5 = V_50 -> V_55 ( V_50 , V_58 , & V_3 ) ;
if ( V_5 )
return V_5 ;
F_14 ( & V_2 -> V_59 ) ;
V_2 -> V_60 = V_3 . V_57 ;
F_3 ( V_2 -> V_8 , L_14
L_15 ,
& V_52 [ V_2 -> V_61 ] [ 0 ] ,
( V_2 -> V_48 ) ? L_16 : L_17 ,
( V_2 -> V_60 ) ? L_18 : L_17 , V_2 -> V_62 ) ;
F_3 ( V_2 -> V_8 , L_19 , V_46 ) ;
switch ( V_2 -> V_61 ) {
case V_63 :
if ( V_2 -> V_48 && V_2 -> V_60 && V_2 -> V_62 ) {
if ( V_46 < V_64 ) {
V_2 -> V_61 = V_65 ;
F_7 ( V_2 ) ;
} else if ( V_46 > V_66 ) {
V_2 -> V_61 = V_67 ;
F_10 ( V_2 , V_46 ) ;
} else if ( V_46 < V_66 ) {
V_2 -> V_61 = V_68 ;
F_9 ( V_2 ) ;
}
} else {
if ( V_46 < V_69 ) {
F_11 ( V_2 ) ;
} else {
V_2 -> V_61 = V_67 ;
F_10 ( V_2 , V_46 ) ;
}
}
break;
case V_65 :
if ( V_2 -> V_48 && V_2 -> V_60 && V_2 -> V_62 ) {
if ( V_46 > V_64 ) {
V_2 -> V_61 = V_68 ;
F_9 ( V_2 ) ;
}
} else {
V_2 -> V_61 = V_67 ;
F_10 ( V_2 , V_46 ) ;
}
break;
case V_68 :
if ( V_2 -> V_48 && V_2 -> V_60 && V_2 -> V_62 ) {
if ( V_46 < V_64 ) {
V_2 -> V_61 = V_65 ;
F_7 ( V_2 ) ;
}
} else {
V_2 -> V_61 = V_67 ;
F_10 ( V_2 , V_46 ) ;
}
break;
case V_67 :
if ( V_2 -> V_48 && V_2 -> V_60 && V_2 -> V_62 ) {
if ( V_46 < V_64 ) {
V_2 -> V_61 = V_65 ;
F_7 ( V_2 ) ;
} else if ( V_46 < V_66 ) {
V_2 -> V_61 = V_68 ;
F_9 ( V_2 ) ;
}
} else {
if ( V_46 < V_69 )
F_11 ( V_2 ) ;
else if ( V_46 > V_47 && V_2 -> V_48 )
F_6 ( V_2 , V_47 , 0 ) ;
}
break;
default:
F_15 ( V_2 -> V_8 , L_20 ,
V_2 -> V_61 ) ;
break;
}
F_3 ( V_2 -> V_8 ,
L_21 ,
& V_52 [ V_2 -> V_61 ] [ 0 ] ,
( V_2 -> V_48 ) ? L_16 : L_17 ,
( V_2 -> V_60 ) ? L_18 : L_17 , V_2 -> V_62 ) ;
F_16 ( & V_2 -> V_59 ) ;
return 0 ;
}
static T_1 F_17 ( int V_70 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
int V_5 ;
F_14 ( & V_2 -> V_59 ) ;
V_5 = F_18 ( V_2 -> V_6 , V_71 ) ;
if ( V_5 < 0 ) {
F_16 ( & V_2 -> V_59 ) ;
goto V_20;
}
if ( V_5 & V_72 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_62 = 1 ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_62 = 0 ;
}
F_16 ( & V_2 -> V_59 ) ;
F_3 ( V_2 -> V_8 , L_22 , V_9 ,
( V_2 -> V_48 ) ? L_16 : L_17 , V_2 -> V_62 ) ;
F_12 ( V_2 ) ;
F_19 ( & V_2 -> V_73 ) ;
V_20:
return V_74 ;
}
static T_1 F_20 ( int V_70 , void * V_3 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_3 ;
union V_51 V_75 ;
int V_76 ;
int V_5 ;
V_50 = F_13 ( V_53 [ 0 ] ) ;
if ( ! V_50 )
goto V_20;
V_5 = V_50 -> V_55 ( V_50 , V_77 , & V_75 ) ;
if ( V_5 )
goto V_20;
V_76 = V_75 . V_57 / 10 ;
F_14 ( & V_2 -> V_59 ) ;
if ( V_76 < - 10 || V_76 > 40 )
V_2 -> V_62 = 0 ;
else
V_2 -> V_62 = 1 ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_62 ) ;
F_16 ( & V_2 -> V_59 ) ;
F_12 ( V_2 ) ;
V_20:
return V_74 ;
}
static T_1 F_21 ( int V_70 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
F_14 ( & V_2 -> V_59 ) ;
V_2 -> V_62 = 0 ;
F_16 ( & V_2 -> V_59 ) ;
F_3 ( V_2 -> V_8 , L_24 , V_9 , V_70 ) ;
F_12 ( V_2 ) ;
return V_74 ;
}
static T_1 F_22 ( int V_70 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
struct V_49 * V_50 ;
union V_51 V_78 ;
int V_5 ;
int V_46 ;
F_14 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_61 == V_65 ) {
V_2 -> V_62 = 1 ;
goto V_20;
}
F_23 ( 5 ) ;
V_2 -> V_62 = 0 ;
V_50 = F_13 ( V_53 [ 0 ] ) ;
if ( ! V_50 )
goto V_20;
V_5 = V_50 -> V_55 ( V_50 , V_56 , & V_78 ) ;
if ( V_5 )
goto V_20;
V_46 = V_78 . V_57 / 1000 ;
V_5 = F_18 ( V_2 -> V_6 , V_71 ) ;
if ( V_5 < 0 )
goto V_20;
if ( V_46 > V_47 && V_5 & V_72 )
V_50 -> V_79 ( V_50 , V_80 , & V_78 ) ;
V_20:
F_16 ( & V_2 -> V_59 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_62 ) ;
F_12 ( V_2 ) ;
return V_74 ;
}
static T_1 F_24 ( int V_70 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
F_14 ( & V_2 -> V_59 ) ;
F_6 ( V_2 , 0 , 0 ) ;
if ( V_2 -> V_60 && V_2 -> V_48 )
V_2 -> V_62 = 1 ;
else
V_2 -> V_62 = 0 ;
F_16 ( & V_2 -> V_59 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_62 ) ;
F_12 ( V_2 ) ;
return V_74 ;
}
static T_1 F_25 ( int V_70 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
int V_81 = 0 ;
if ( V_2 -> V_60 )
goto V_20;
F_1 ( V_2 , & V_81 ) ;
F_14 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_48 ) {
int V_82 ;
V_82 = F_18 ( V_2 -> V_16 , V_83 ) ;
if ( V_82 & V_84 ) {
F_8 ( V_2 -> V_16 , V_83 ,
V_84 , V_84 ) ;
F_8 ( V_2 -> V_16 ,
V_85 ,
V_86 ,
V_86 ) ;
F_3 ( V_2 -> V_8 ,
L_25 , V_9 ) ;
}
}
if ( V_81 > V_87 ) {
F_4 ( V_2 , V_88 , 0 ) ;
V_2 -> V_62 = 0 ;
F_3 ( V_2 -> V_8 ,
L_26 ,
V_9 , V_81 ) ;
} else if ( V_81 < V_88 ) {
F_4 ( V_2 , V_44 ,
V_45 ) ;
V_2 -> V_62 = 1 ;
F_3 ( V_2 -> V_8 ,
L_27 ,
V_9 , V_81 ) ;
}
F_16 ( & V_2 -> V_59 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_62 ) ;
F_12 ( V_2 ) ;
V_20:
return V_74 ;
}
static int F_26 ( struct V_49 * V_50 ,
enum V_89 V_90 ,
union V_51 * V_78 )
{
struct V_1 * V_2 =
F_27 ( V_50 -> V_8 -> V_91 ) ;
switch ( V_90 ) {
case V_92 :
if ( V_2 -> V_61 == V_68 ||
V_2 -> V_61 == V_65 )
V_78 -> V_57 = V_93 ;
else
V_78 -> V_57 = V_94 ;
break;
case V_95 :
V_78 -> V_57 = V_2 -> V_48 ;
break;
default:
return - V_96 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_18 ( V_2 -> V_6 , V_71 ) ;
if ( V_5 < 0 )
return V_5 ;
F_14 ( & V_2 -> V_59 ) ;
V_2 -> V_61 = V_63 ;
if ( V_5 & V_72 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_62 = 1 ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_62 = 0 ;
}
F_16 ( & V_2 -> V_59 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = F_27 ( V_98 -> V_8 . V_91 ) ;
struct V_1 * V_2 ;
int V_5 ;
int V_101 ;
int V_102 ;
int V_103 ;
V_2 = F_30 ( & V_98 -> V_8 , sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
V_101 = V_98 -> V_106 ;
for ( V_102 = 0 , V_103 = 0 ; V_102 < V_101 ; V_102 ++ ) {
V_2 -> V_70 [ V_103 ] = F_31 ( V_98 , V_102 ) ;
if ( V_2 -> V_70 [ V_103 ] < 0 )
continue;
V_103 ++ ;
}
V_2 -> V_107 = V_103 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_6 =
( V_100 -> V_108 == V_109 ) ? V_100 -> V_110 : V_100 -> V_111 ;
V_2 -> V_16 =
( V_100 -> V_108 == V_109 ) ? V_100 -> V_111 : V_100 -> V_110 ;
if ( ! V_2 -> V_16 ) {
F_32 ( & V_98 -> V_8 , L_28 ) ;
V_5 = - V_54 ;
goto V_20;
}
V_2 -> V_8 = & V_98 -> V_8 ;
F_4 ( V_2 , V_44 , V_88 ) ;
F_33 ( & V_2 -> V_59 ) ;
F_34 ( V_98 , V_2 ) ;
V_2 -> V_73 . V_112 = L_29 ;
V_2 -> V_73 . type = V_113 ;
V_2 -> V_73 . V_114 = V_53 ;
V_2 -> V_73 . V_115 = F_35 ( V_53 ) ;
V_2 -> V_73 . V_116 = V_117 ;
V_2 -> V_73 . V_118 = F_35 ( V_117 ) ;
V_2 -> V_73 . V_55 = F_26 ;
V_5 = F_36 ( & V_98 -> V_8 , & V_2 -> V_73 ) ;
if ( V_5 )
goto V_20;
F_28 ( V_2 ) ;
for ( V_102 = 0 ; V_102 < F_35 ( V_2 -> V_70 ) ; V_102 ++ ) {
V_5 = F_37 ( V_2 -> V_70 [ V_102 ] , NULL ,
V_119 [ V_102 ] . V_120 ,
V_121 , V_119 [ V_102 ] . V_112 , V_2 ) ;
if ( V_5 < 0 ) {
F_32 ( V_100 -> V_8 , L_30 ,
V_2 -> V_70 [ V_102 ] , V_5 ) ;
goto V_122;
}
}
return 0 ;
V_122:
while ( -- V_102 >= 0 )
F_38 ( V_2 -> V_70 [ V_102 ] , V_2 ) ;
V_20:
F_39 ( V_2 ) ;
return V_5 ;
}
static int F_40 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_41 ( V_98 ) ;
int V_102 ;
F_34 ( V_98 , NULL ) ;
F_42 ( & V_2 -> V_73 ) ;
F_38 ( V_2 -> V_70 [ 0 ] , V_2 ) ;
for ( V_102 = 0 ; V_102 < V_2 -> V_107 ; V_102 ++ )
F_38 ( V_2 -> V_70 [ V_102 ] , V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
