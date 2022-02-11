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
V_5 = F_14 ( V_50 , V_55 ,
& V_3 ) ;
if ( V_5 ) {
F_15 ( V_50 ) ;
return V_5 ;
}
V_46 = V_3 . V_56 / 1000 ;
V_5 = F_14 ( V_50 , V_57 , & V_3 ) ;
if ( V_5 ) {
F_15 ( V_50 ) ;
return V_5 ;
}
F_15 ( V_50 ) ;
F_16 ( & V_2 -> V_58 ) ;
V_2 -> V_59 = V_3 . V_56 ;
F_3 ( V_2 -> V_8 , L_14
L_15 ,
& V_52 [ V_2 -> V_60 ] [ 0 ] ,
( V_2 -> V_48 ) ? L_16 : L_17 ,
( V_2 -> V_59 ) ? L_18 : L_17 , V_2 -> V_61 ) ;
F_3 ( V_2 -> V_8 , L_19 , V_46 ) ;
switch ( V_2 -> V_60 ) {
case V_62 :
if ( V_2 -> V_48 && V_2 -> V_59 && V_2 -> V_61 ) {
if ( V_46 < V_63 ) {
V_2 -> V_60 = V_64 ;
F_7 ( V_2 ) ;
} else if ( V_46 > V_65 ) {
V_2 -> V_60 = V_66 ;
F_10 ( V_2 , V_46 ) ;
} else if ( V_46 < V_65 ) {
V_2 -> V_60 = V_67 ;
F_9 ( V_2 ) ;
}
} else {
if ( V_46 < V_68 ) {
F_11 ( V_2 ) ;
} else {
V_2 -> V_60 = V_66 ;
F_10 ( V_2 , V_46 ) ;
}
}
break;
case V_64 :
if ( V_2 -> V_48 && V_2 -> V_59 && V_2 -> V_61 ) {
if ( V_46 > V_63 ) {
V_2 -> V_60 = V_67 ;
F_9 ( V_2 ) ;
}
} else {
V_2 -> V_60 = V_66 ;
F_10 ( V_2 , V_46 ) ;
}
break;
case V_67 :
if ( V_2 -> V_48 && V_2 -> V_59 && V_2 -> V_61 ) {
if ( V_46 < V_63 ) {
V_2 -> V_60 = V_64 ;
F_7 ( V_2 ) ;
}
} else {
V_2 -> V_60 = V_66 ;
F_10 ( V_2 , V_46 ) ;
}
break;
case V_66 :
if ( V_2 -> V_48 && V_2 -> V_59 && V_2 -> V_61 ) {
if ( V_46 < V_63 ) {
V_2 -> V_60 = V_64 ;
F_7 ( V_2 ) ;
} else if ( V_46 < V_65 ) {
V_2 -> V_60 = V_67 ;
F_9 ( V_2 ) ;
}
} else {
if ( V_46 < V_68 )
F_11 ( V_2 ) ;
else if ( V_46 > V_47 && V_2 -> V_48 )
F_6 ( V_2 , V_47 , 0 ) ;
}
break;
default:
F_17 ( V_2 -> V_8 , L_20 ,
V_2 -> V_60 ) ;
break;
}
F_3 ( V_2 -> V_8 ,
L_21 ,
& V_52 [ V_2 -> V_60 ] [ 0 ] ,
( V_2 -> V_48 ) ? L_16 : L_17 ,
( V_2 -> V_59 ) ? L_18 : L_17 , V_2 -> V_61 ) ;
F_18 ( & V_2 -> V_58 ) ;
return 0 ;
}
static T_1 F_19 ( int V_69 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
int V_5 ;
F_16 ( & V_2 -> V_58 ) ;
V_5 = F_20 ( V_2 -> V_6 , V_70 ) ;
if ( V_5 < 0 ) {
F_18 ( & V_2 -> V_58 ) ;
goto V_20;
}
if ( V_5 & V_71 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_61 = 1 ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_61 = 0 ;
}
F_18 ( & V_2 -> V_58 ) ;
F_3 ( V_2 -> V_8 , L_22 , V_9 ,
( V_2 -> V_48 ) ? L_16 : L_17 , V_2 -> V_61 ) ;
F_12 ( V_2 ) ;
F_21 ( V_2 -> V_72 ) ;
V_20:
return V_73 ;
}
static T_1 F_22 ( int V_69 , void * V_3 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_3 ;
union V_51 V_74 ;
int V_75 ;
int V_5 ;
V_50 = F_13 ( V_53 [ 0 ] ) ;
if ( ! V_50 )
return V_73 ;
V_5 = F_14 ( V_50 , V_76 , & V_74 ) ;
if ( V_5 )
goto V_20;
V_75 = V_74 . V_56 / 10 ;
F_16 ( & V_2 -> V_58 ) ;
if ( V_75 < - 10 || V_75 > 40 )
V_2 -> V_61 = 0 ;
else
V_2 -> V_61 = 1 ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_61 ) ;
F_18 ( & V_2 -> V_58 ) ;
F_12 ( V_2 ) ;
V_20:
F_15 ( V_50 ) ;
return V_73 ;
}
static T_1 F_23 ( int V_69 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
F_16 ( & V_2 -> V_58 ) ;
V_2 -> V_61 = 0 ;
F_18 ( & V_2 -> V_58 ) ;
F_3 ( V_2 -> V_8 , L_24 , V_9 , V_69 ) ;
F_12 ( V_2 ) ;
return V_73 ;
}
static T_1 F_24 ( int V_69 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
struct V_49 * V_50 ;
union V_51 V_77 ;
int V_5 ;
int V_46 ;
F_16 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_60 == V_64 ) {
V_2 -> V_61 = 1 ;
goto V_20;
}
F_25 ( 5 ) ;
V_2 -> V_61 = 0 ;
V_50 = F_13 ( V_53 [ 0 ] ) ;
if ( ! V_50 )
goto V_20;
V_5 = F_14 ( V_50 , V_55 ,
& V_77 ) ;
if ( V_5 )
goto V_78;
V_46 = V_77 . V_56 / 1000 ;
V_5 = F_20 ( V_2 -> V_6 , V_70 ) ;
if ( V_5 < 0 )
goto V_78;
if ( V_46 > V_47 && V_5 & V_71 )
F_26 ( V_50 , V_79 ,
& V_77 ) ;
V_78:
F_15 ( V_50 ) ;
V_20:
F_18 ( & V_2 -> V_58 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_61 ) ;
F_12 ( V_2 ) ;
return V_73 ;
}
static T_1 F_27 ( int V_69 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
F_16 ( & V_2 -> V_58 ) ;
F_6 ( V_2 , 0 , 0 ) ;
if ( V_2 -> V_59 && V_2 -> V_48 )
V_2 -> V_61 = 1 ;
else
V_2 -> V_61 = 0 ;
F_18 ( & V_2 -> V_58 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_61 ) ;
F_12 ( V_2 ) ;
return V_73 ;
}
static T_1 F_28 ( int V_69 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
int V_80 = 0 ;
if ( V_2 -> V_59 )
goto V_20;
F_1 ( V_2 , & V_80 ) ;
F_16 ( & V_2 -> V_58 ) ;
if ( ! V_2 -> V_48 ) {
int V_81 ;
V_81 = F_20 ( V_2 -> V_16 , V_82 ) ;
if ( V_81 & V_83 ) {
F_8 ( V_2 -> V_16 , V_82 ,
V_83 , V_83 ) ;
F_8 ( V_2 -> V_16 ,
V_84 ,
V_85 ,
V_85 ) ;
F_3 ( V_2 -> V_8 ,
L_25 , V_9 ) ;
}
}
if ( V_80 > V_86 ) {
F_4 ( V_2 , V_87 , 0 ) ;
V_2 -> V_61 = 0 ;
F_3 ( V_2 -> V_8 ,
L_26 ,
V_9 , V_80 ) ;
} else if ( V_80 < V_87 ) {
F_4 ( V_2 , V_44 ,
V_45 ) ;
V_2 -> V_61 = 1 ;
F_3 ( V_2 -> V_8 ,
L_27 ,
V_9 , V_80 ) ;
}
F_18 ( & V_2 -> V_58 ) ;
F_3 ( V_2 -> V_8 , L_23 , V_9 , V_2 -> V_61 ) ;
F_12 ( V_2 ) ;
V_20:
return V_73 ;
}
static int F_29 ( struct V_49 * V_50 ,
enum V_88 V_89 ,
union V_51 * V_77 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
switch ( V_89 ) {
case V_90 :
if ( V_2 -> V_60 == V_67 ||
V_2 -> V_60 == V_64 )
V_77 -> V_56 = V_91 ;
else
V_77 -> V_56 = V_92 ;
break;
case V_93 :
V_77 -> V_56 = V_2 -> V_48 ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_20 ( V_2 -> V_6 , V_70 ) ;
if ( V_5 < 0 )
return V_5 ;
F_16 ( & V_2 -> V_58 ) ;
V_2 -> V_60 = V_62 ;
if ( V_5 & V_71 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_61 = 1 ;
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_61 = 0 ;
}
F_18 ( & V_2 -> V_58 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = F_33 ( V_96 -> V_8 . V_99 ) ;
struct V_100 V_101 = {} ;
struct V_1 * V_2 ;
int V_5 ;
int V_102 ;
int V_103 ;
int V_104 ;
V_2 = F_34 ( & V_96 -> V_8 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_106 ;
V_102 = V_96 -> V_107 ;
for ( V_103 = 0 , V_104 = 0 ; V_103 < V_102 ; V_103 ++ ) {
V_2 -> V_69 [ V_104 ] = F_35 ( V_96 , V_103 ) ;
if ( V_2 -> V_69 [ V_104 ] < 0 )
continue;
V_104 ++ ;
}
V_2 -> V_108 = V_104 ;
V_2 -> V_98 = V_98 ;
V_2 -> V_6 =
( V_98 -> V_109 == V_110 ) ? V_98 -> V_111 : V_98 -> V_112 ;
V_2 -> V_16 =
( V_98 -> V_109 == V_110 ) ? V_98 -> V_112 : V_98 -> V_111 ;
if ( ! V_2 -> V_16 ) {
F_36 ( & V_96 -> V_8 , L_28 ) ;
V_5 = - V_54 ;
goto V_20;
}
V_2 -> V_8 = & V_96 -> V_8 ;
F_4 ( V_2 , V_44 , V_87 ) ;
F_37 ( & V_2 -> V_58 ) ;
F_38 ( V_96 , V_2 ) ;
V_101 . V_113 = V_2 ;
V_101 . V_114 = V_53 ;
V_101 . V_115 = F_39 ( V_53 ) ;
V_2 -> V_72 = F_40 ( & V_96 -> V_8 , & V_116 ,
& V_101 ) ;
if ( F_41 ( V_2 -> V_72 ) ) {
V_5 = F_42 ( V_2 -> V_72 ) ;
goto V_20;
}
F_31 ( V_2 ) ;
for ( V_103 = 0 ; V_103 < F_39 ( V_2 -> V_69 ) ; V_103 ++ ) {
V_5 = F_43 ( V_2 -> V_69 [ V_103 ] , NULL ,
V_117 [ V_103 ] . V_118 ,
V_119 , V_117 [ V_103 ] . V_120 , V_2 ) ;
if ( V_5 < 0 ) {
F_36 ( V_98 -> V_8 , L_29 ,
V_2 -> V_69 [ V_103 ] , V_5 ) ;
goto V_121;
}
}
return 0 ;
V_121:
F_44 ( V_2 -> V_72 ) ;
while ( -- V_103 >= 0 )
F_45 ( V_2 -> V_69 [ V_103 ] , V_2 ) ;
V_20:
return V_5 ;
}
static int F_46 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_47 ( V_96 ) ;
int V_103 ;
F_44 ( V_2 -> V_72 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_108 ; V_103 ++ )
F_45 ( V_2 -> V_69 [ V_103 ] , V_2 ) ;
return 0 ;
}
