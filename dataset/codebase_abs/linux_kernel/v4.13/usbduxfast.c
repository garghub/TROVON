static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
int V_10 ;
V_7 -> V_11 [ 0 ] = V_3 ;
V_10 = F_3 ( V_5 , F_4 ( V_5 , V_12 ) ,
V_7 -> V_11 , V_13 ,
& V_9 , 10000 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_14 ,
L_1 ,
V_10 ) ;
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 , int V_15 ,
T_1 V_16 , T_1 V_17 , T_1 V_18 , T_1 log )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_11 [ 1 + 0x00 + V_15 ] = V_16 ;
V_7 -> V_11 [ 1 + 0x08 + V_15 ] = V_17 ;
V_7 -> V_11 [ 1 + 0x10 + V_15 ] = V_18 ;
V_7 -> V_11 [ 1 + 0x18 + V_15 ] = log ;
}
static int F_7 ( struct V_1 * V_2 , int V_19 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_20 = 0 ;
if ( V_19 && V_7 -> V_21 ) {
F_8 ( V_7 -> V_21 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
F_10 ( & V_7 -> V_24 ) ;
V_10 = F_7 ( V_2 , 1 ) ;
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_21 * V_21 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_25 * V_26 = V_23 -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
int V_10 ;
if ( V_7 -> V_29 ) {
V_7 -> V_29 -- ;
} else {
unsigned int V_30 ;
V_30 = F_13 ( V_23 , V_21 -> V_31 ) ;
V_30 = F_14 ( V_23 , V_30 ) ;
F_15 ( V_23 , V_21 -> V_32 , V_30 ) ;
if ( V_28 -> V_33 == V_34 &&
V_26 -> V_35 >= V_28 -> V_36 )
V_26 -> V_37 |= V_38 ;
}
if ( ! ( V_26 -> V_37 & V_39 ) ) {
V_21 -> V_2 = F_2 ( V_2 ) ;
V_21 -> V_40 = 0 ;
V_10 = F_16 ( V_21 , V_41 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_2 , V_10 ) ;
V_26 -> V_37 |= V_42 ;
}
}
}
static void F_17 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_43 ;
struct V_22 * V_23 = V_2 -> V_44 ;
struct V_25 * V_26 = V_23 -> V_26 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 -> V_20 )
return;
switch ( V_21 -> V_40 ) {
case 0 :
F_12 ( V_2 , V_23 , V_21 ) ;
break;
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
V_26 -> V_37 |= V_42 ;
break;
default:
F_5 ( V_2 -> V_14 ,
L_3 ,
V_21 -> V_40 ) ;
V_26 -> V_37 |= V_42 ;
break;
}
if ( V_26 -> V_37 & V_39 )
F_7 ( V_2 , 0 ) ;
F_18 ( V_2 , V_23 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
F_20 ( V_7 -> V_21 , V_5 , F_21 ( V_5 , V_49 ) ,
V_7 -> V_50 , V_51 ,
F_17 , V_2 ) ;
V_10 = F_16 ( V_7 -> V_21 , V_41 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_14 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_27 * V_28 )
{
unsigned int V_52 = F_23 ( V_28 -> V_53 [ 0 ] ) ;
int V_54 ;
if ( V_28 -> V_55 > 3 && V_28 -> V_55 != 16 ) {
F_5 ( V_2 -> V_14 , L_5 ) ;
return - V_56 ;
}
for ( V_54 = 0 ; V_54 < V_28 -> V_55 ; ++ V_54 ) {
unsigned int V_57 = F_24 ( V_28 -> V_53 [ V_54 ] ) ;
unsigned int V_58 = F_23 ( V_28 -> V_53 [ V_54 ] ) ;
if ( V_57 != V_54 ) {
F_5 ( V_2 -> V_14 ,
L_6 ) ;
return - V_56 ;
}
if ( V_58 != V_52 && V_28 -> V_55 > 3 ) {
F_5 ( V_2 -> V_14 ,
L_7 ) ;
return - V_56 ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_27 * V_28 )
{
int V_59 = 0 ;
unsigned int V_60 ;
unsigned int V_61 ;
V_59 |= F_26 ( & V_28 -> V_62 ,
V_63 | V_64 | V_65 ) ;
V_59 |= F_26 ( & V_28 -> V_66 , V_67 ) ;
V_59 |= F_26 ( & V_28 -> V_68 , V_69 ) ;
V_59 |= F_26 ( & V_28 -> V_70 , V_34 ) ;
V_59 |= F_26 ( & V_28 -> V_33 , V_34 | V_71 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_27 ( V_28 -> V_62 ) ;
V_59 |= F_27 ( V_28 -> V_33 ) ;
if ( V_59 )
return 2 ;
V_59 |= F_28 ( & V_28 -> V_72 , 0 ) ;
if ( ! V_28 -> V_55 )
V_59 |= - V_56 ;
if ( V_28 -> V_62 == V_64 &&
V_28 -> V_55 != 1 && V_28 -> V_55 != 16 )
V_59 |= - V_56 ;
V_59 |= F_28 ( & V_28 -> V_73 ,
V_28 -> V_55 ) ;
V_60 = ( V_28 -> V_74 * 30 ) / 1000 ;
if ( V_28 -> V_55 != 1 )
V_59 |= F_29 ( & V_60 ,
V_75 ) ;
V_59 |= F_30 ( & V_60 , V_76 ) ;
V_61 = ( V_60 * 1000 ) / 30 ;
V_59 |= F_28 ( & V_28 -> V_74 , V_61 ) ;
if ( V_28 -> V_33 == V_34 )
V_59 |= F_29 ( & V_28 -> V_36 , 1 ) ;
else
V_59 |= F_28 ( & V_28 -> V_36 , 0 ) ;
if ( V_59 )
return 3 ;
if ( V_28 -> V_53 && V_28 -> V_55 > 0 )
V_59 |= F_22 ( V_2 , V_23 , V_28 ) ;
if ( V_59 )
return 5 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
unsigned int V_77 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = & V_23 -> V_26 -> V_28 ;
int V_10 ;
if ( V_77 != V_28 -> V_72 )
return - V_56 ;
F_10 ( & V_7 -> V_24 ) ;
if ( ! V_7 -> V_20 ) {
V_7 -> V_20 = 1 ;
V_10 = F_19 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_8 , V_10 ) ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
V_23 -> V_26 -> V_78 = NULL ;
} else {
F_5 ( V_2 -> V_14 , L_9 ) ;
}
F_11 ( & V_7 -> V_24 ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = & V_23 -> V_26 -> V_28 ;
unsigned int V_79 = 0xff ;
int V_80 , V_10 ;
long V_60 , V_81 ;
F_10 ( & V_7 -> V_24 ) ;
if ( V_7 -> V_20 ) {
V_10 = - V_82 ;
goto V_83;
}
V_7 -> V_29 = V_84 ;
V_60 = ( V_28 -> V_74 * 30 ) / 1000 ;
switch ( V_28 -> V_55 ) {
case 1 :
if ( F_23 ( V_28 -> V_53 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
if ( V_28 -> V_62 == V_64 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 , V_79 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0x01 , 0x00 , V_79 , 0x00 ) ;
}
if ( V_60 < V_75 ) {
if ( V_60 <= 1 ) {
F_6 ( V_2 , 1 ,
0x89 , 0x03 , V_79 , 0xff ) ;
} else {
F_6 ( V_2 , 1 , V_60 - 1 ,
0x02 , V_79 , 0x00 ) ;
F_6 ( V_2 , 2 ,
0x09 , 0x01 , V_79 , 0xff ) ;
}
} else {
V_60 = V_60 - 1 ;
F_6 ( V_2 , 1 ,
V_60 / 2 , 0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , V_60 - V_60 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 3 ,
0x09 , 0x03 , V_79 , 0xff ) ;
}
break;
case 2 :
if ( F_23 ( V_28 -> V_53 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_81 = V_60 - 1 ;
if ( F_23 ( V_28 -> V_53 [ 1 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 1 , V_81 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , V_81 - V_81 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_81 = V_60 - 2 ;
if ( F_23 ( V_28 -> V_53 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 4 , V_81 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_79 , 0x00 ) ;
F_6 ( V_2 , 5 , V_81 - V_81 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
break;
case 3 :
for ( V_80 = 0 ; V_80 < 1 ; V_80 ++ ) {
int V_15 = V_80 * 2 ;
if ( F_23 ( V_28 -> V_53 [ V_80 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , V_15 , V_60 / 2 ,
0x02 , V_79 , 0x00 ) ;
if ( F_23 ( V_28 -> V_53 [ V_80 + 1 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , V_15 + 1 , V_60 - V_60 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
}
V_81 = V_60 - 2 ;
F_6 ( V_2 , 4 , V_81 / 2 ,
0x02 , V_79 , 0x00 ) ;
if ( F_23 ( V_28 -> V_53 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 5 , V_81 - V_81 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
break;
case 16 :
if ( F_23 ( V_28 -> V_53 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
if ( V_28 -> V_62 == V_64 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 ,
( 0xff - 0x02 ) & V_79 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0xff , 0x00 ,
( 0xff - 0x02 ) & V_79 , 0x00 ) ;
}
F_6 ( V_2 , 1 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_60 = V_60 - 2 ;
F_6 ( V_2 , 2 , V_60 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , V_60 - V_60 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x09 , 0x01 , V_79 , 0xff ) ;
break;
}
V_10 = F_1 ( V_2 , V_85 ) ;
if ( V_10 < 0 )
goto V_83;
if ( ( V_28 -> V_62 == V_63 ) || ( V_28 -> V_62 == V_64 ) ) {
V_7 -> V_20 = 1 ;
V_10 = F_19 ( V_2 ) ;
if ( V_10 < 0 ) {
V_7 -> V_20 = 0 ;
goto V_83;
}
V_23 -> V_26 -> V_78 = NULL ;
} else {
V_23 -> V_26 -> V_78 = F_31 ;
}
V_83:
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_86 * V_87 ,
unsigned int * V_88 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_57 = F_24 ( V_87 -> V_89 ) ;
unsigned int V_90 = F_23 ( V_87 -> V_89 ) ;
T_1 V_79 = V_90 ? ( 0xff - 0x04 ) : 0xff ;
int V_54 , V_80 , V_91 , V_31 ;
int V_10 ;
F_10 ( & V_7 -> V_24 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 ,
L_10 ) ;
F_11 ( & V_7 -> V_24 ) ;
return - V_82 ;
}
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_79 , 0x00 ) ;
F_6 ( V_2 , 1 , 0x0c , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 5 , 0x0c , 0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
V_10 = F_1 ( V_2 , V_85 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
for ( V_54 = 0 ; V_54 < V_84 ; V_54 ++ ) {
V_10 = F_3 ( V_5 , F_21 ( V_5 , V_49 ) ,
V_7 -> V_50 , V_51 ,
& V_31 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_11 ) ;
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
}
for ( V_54 = 0 ; V_54 < V_87 -> V_91 ; ) {
V_10 = F_3 ( V_5 , F_21 ( V_5 , V_49 ) ,
V_7 -> V_50 , V_51 ,
& V_31 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_12 , V_10 ) ;
F_11 ( & V_7 -> V_24 ) ;
return V_10 ;
}
V_91 = V_31 / sizeof( V_92 ) ;
if ( ( V_91 % 16 ) != 0 ) {
F_5 ( V_2 -> V_14 , L_13 ) ;
F_11 ( & V_7 -> V_24 ) ;
return - V_56 ;
}
for ( V_80 = V_57 ; ( V_80 < V_91 ) && ( V_54 < V_87 -> V_91 ) ; V_80 = V_80 + 16 ) {
V_88 [ V_54 ] = ( ( V_92 * ) ( V_7 -> V_50 ) ) [ V_80 ] ;
V_54 ++ ;
}
}
F_11 ( & V_7 -> V_24 ) ;
return V_87 -> V_91 ;
}
static int F_34 ( struct V_1 * V_2 ,
const T_1 * V_88 , T_2 V_93 ,
unsigned long V_43 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_94 ;
unsigned char * V_95 ;
int V_10 ;
if ( ! V_88 )
return 0 ;
if ( V_93 > V_96 ) {
F_5 ( V_2 -> V_14 , L_14 ) ;
return - V_97 ;
}
V_94 = F_35 ( V_88 , V_93 , V_98 ) ;
if ( ! V_94 )
return - V_97 ;
V_95 = F_36 ( 1 , V_98 ) ;
if ( ! V_95 ) {
F_37 ( V_94 ) ;
return - V_97 ;
}
* V_95 = 1 ;
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_99 ,
V_100 ,
V_101 , 0x0000 ,
V_95 , 1 ,
V_102 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_15 ) ;
goto V_103;
}
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_99 ,
V_100 ,
0 , 0x0000 ,
V_94 , V_93 ,
V_102 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_16 ) ;
goto V_103;
}
* V_95 = 0 ;
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_99 ,
V_100 ,
V_101 , 0x0000 ,
V_95 , 1 ,
V_102 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_14 , L_17 ) ;
V_103:
F_37 ( V_95 ) ;
F_37 ( V_94 ) ;
return V_10 ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned long V_104 )
{
struct V_105 * V_106 = F_41 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_22 * V_23 ;
int V_10 ;
if ( V_5 -> V_107 != V_108 ) {
F_5 ( V_2 -> V_14 ,
L_18 ) ;
return - V_109 ;
}
V_7 = F_42 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_97 ;
F_43 ( & V_7 -> V_24 ) ;
F_44 ( V_106 , V_7 ) ;
V_7 -> V_11 = F_36 ( V_13 , V_98 ) ;
if ( ! V_7 -> V_11 )
return - V_97 ;
V_10 = F_45 ( V_5 ,
V_106 -> V_110 -> V_111 . V_112 , 1 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_19 ) ;
return - V_109 ;
}
V_7 -> V_21 = F_46 ( 0 , V_98 ) ;
if ( ! V_7 -> V_21 )
return - V_97 ;
V_7 -> V_50 = F_36 ( V_51 , V_98 ) ;
if ( ! V_7 -> V_50 )
return - V_97 ;
V_10 = F_47 ( V_2 , & V_5 -> V_2 , V_113 ,
F_34 , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_48 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
V_23 = & V_2 -> V_114 [ 0 ] ;
V_2 -> V_44 = V_23 ;
V_23 -> type = V_115 ;
V_23 -> V_116 = V_117 | V_118 | V_119 ;
V_23 -> V_120 = 16 ;
V_23 -> V_121 = 0x1000 ;
V_23 -> V_122 = & V_123 ;
V_23 -> V_124 = F_33 ;
V_23 -> V_125 = V_23 -> V_120 ;
V_23 -> V_126 = F_25 ;
V_23 -> V_127 = F_32 ;
V_23 -> V_128 = F_9 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = F_41 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_10 ( & V_7 -> V_24 ) ;
F_44 ( V_106 , NULL ) ;
if ( V_7 -> V_21 ) {
F_8 ( V_7 -> V_21 ) ;
F_37 ( V_7 -> V_50 ) ;
F_50 ( V_7 -> V_21 ) ;
}
F_37 ( V_7 -> V_11 ) ;
F_11 ( & V_7 -> V_24 ) ;
}
static int F_51 ( struct V_105 * V_106 ,
const struct V_129 * V_130 )
{
return F_52 ( V_106 , & V_131 , 0 ) ;
}
