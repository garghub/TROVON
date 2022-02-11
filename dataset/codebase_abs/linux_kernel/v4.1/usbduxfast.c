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
T_1 V_16 , T_1 V_17 , T_1 V_18 ,
T_1 log )
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
if ( ! V_7 )
return - V_24 ;
F_10 ( & V_7 -> V_25 ) ;
V_10 = F_7 ( V_2 , 1 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_21 * V_21 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_26 * V_27 = V_23 -> V_27 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
int V_10 ;
if ( V_7 -> V_30 ) {
V_7 -> V_30 -- ;
} else {
unsigned int V_31 ;
V_31 = F_13 ( V_23 , V_21 -> V_32 ) ;
V_31 = F_14 ( V_23 , V_31 ) ;
F_15 ( V_23 , V_21 -> V_33 , V_31 ) ;
if ( V_29 -> V_34 == V_35 &&
V_27 -> V_36 >= V_29 -> V_37 )
V_27 -> V_38 |= V_39 ;
}
if ( ! ( V_27 -> V_38 & V_40 ) ) {
V_21 -> V_2 = F_2 ( V_2 ) ;
V_21 -> V_41 = 0 ;
V_10 = F_16 ( V_21 , V_42 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_2 , V_10 ) ;
V_27 -> V_38 |= V_43 ;
}
}
}
static void F_17 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_44 ;
struct V_22 * V_23 = V_2 -> V_45 ;
struct V_26 * V_27 = V_23 -> V_27 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 -> V_20 )
return;
switch ( V_21 -> V_41 ) {
case 0 :
F_12 ( V_2 , V_23 , V_21 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_27 -> V_38 |= V_43 ;
break;
default:
F_5 ( V_2 -> V_14 ,
L_3 ,
V_21 -> V_41 ) ;
V_27 -> V_38 |= V_43 ;
break;
}
if ( V_27 -> V_38 & V_40 )
F_7 ( V_2 , 0 ) ;
F_18 ( V_2 , V_23 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
if ( ! V_7 )
return - V_24 ;
F_20 ( V_7 -> V_21 , V_5 , F_21 ( V_5 , V_50 ) ,
V_7 -> V_51 , V_52 ,
F_17 , V_2 ) ;
V_10 = F_16 ( V_7 -> V_21 , V_42 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_14 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_28 * V_29 )
{
int V_53 = 0 ;
long int V_54 , V_55 ;
int V_56 ;
V_53 |= F_23 ( & V_29 -> V_57 ,
V_58 | V_59 | V_60 ) ;
V_53 |= F_23 ( & V_29 -> V_61 ,
V_62 | V_59 ) ;
V_53 |= F_23 ( & V_29 -> V_63 ,
V_64 | V_59 ) ;
V_53 |= F_23 ( & V_29 -> V_65 , V_35 ) ;
V_53 |= F_23 ( & V_29 -> V_34 , V_35 | V_66 ) ;
if ( V_53 )
return 1 ;
V_53 |= F_24 ( V_29 -> V_57 ) ;
V_53 |= F_24 ( V_29 -> V_61 ) ;
V_53 |= F_24 ( V_29 -> V_63 ) ;
V_53 |= F_24 ( V_29 -> V_34 ) ;
if ( V_29 -> V_57 == V_59 && V_29 -> V_34 == V_59 )
V_53 |= - V_67 ;
if ( V_53 )
return 2 ;
V_53 |= F_25 ( & V_29 -> V_68 , 0 ) ;
if ( ! V_29 -> V_69 )
V_53 |= - V_67 ;
V_53 |= F_25 ( & V_29 -> V_70 ,
V_29 -> V_69 ) ;
if ( V_29 -> V_69 == 1 )
V_56 = 1 ;
else
V_56 = V_71 ;
if ( V_29 -> V_63 == V_64 ) {
V_54 = V_29 -> V_72 * 30 ;
if ( V_54 < ( V_56 * 1000 ) )
V_54 = V_56 * 1000 ;
if ( V_54 > ( V_73 * 1000 ) )
V_54 = V_73 * 1000 ;
V_55 = V_54 / 30 ;
V_53 |= F_25 ( & V_29 -> V_72 , V_55 ) ;
}
switch ( V_29 -> V_34 ) {
case V_35 :
V_53 |= F_26 ( & V_29 -> V_37 , 1 ) ;
break;
case V_66 :
V_53 |= F_25 ( & V_29 -> V_37 , 0 ) ;
break;
default:
break;
}
if ( V_53 )
return 3 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
unsigned int V_74 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_28 * V_29 = & V_23 -> V_27 -> V_29 ;
int V_10 ;
if ( ! V_7 )
return - V_24 ;
if ( V_74 != V_29 -> V_68 )
return - V_67 ;
F_10 ( & V_7 -> V_25 ) ;
if ( ! V_7 -> V_20 ) {
V_7 -> V_20 = 1 ;
V_10 = F_19 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_5 , V_10 ) ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_27 -> V_75 = NULL ;
} else {
F_5 ( V_2 -> V_14 , L_6 ) ;
}
F_11 ( & V_7 -> V_25 ) ;
return 1 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_28 * V_29 = & V_23 -> V_27 -> V_29 ;
unsigned int V_76 , V_77 , V_78 = 0xff ;
int V_79 , V_80 , V_10 ;
int V_81 ;
long V_54 , V_82 ;
if ( ! V_7 )
return - V_24 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 , L_7 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_83 ;
}
V_7 -> V_30 = V_84 ;
V_77 = F_29 ( V_29 -> V_85 [ 0 ] ) ;
for ( V_79 = 0 ; V_79 < V_29 -> V_69 ; ++ V_79 ) {
V_76 = F_30 ( V_29 -> V_85 [ V_79 ] ) ;
if ( V_76 != V_79 ) {
F_5 ( V_2 -> V_14 ,
L_8 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( ( V_77 != F_29 ( V_29 -> V_85 [ V_79 ] ) )
&& ( V_29 -> V_69 > 3 ) ) {
F_5 ( V_2 -> V_14 ,
L_9 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( V_79 >= V_86 ) {
F_5 ( V_2 -> V_14 , L_10 ) ;
break;
}
}
V_54 = 0 ;
if ( V_29 -> V_63 == V_64 )
V_54 = ( V_29 -> V_72 * 30 ) / 1000 ;
if ( ( V_54 < V_71 ) && ( V_29 -> V_69 != 1 ) ) {
F_5 ( V_2 -> V_14 ,
L_11 ,
V_54 , V_29 -> V_87 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( V_54 > V_73 ) {
F_5 ( V_2 -> V_14 , L_12 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( ( V_29 -> V_57 == V_59 ) && ( V_29 -> V_69 != 1 )
&& ( V_29 -> V_69 != 16 ) ) {
F_5 ( V_2 -> V_14 ,
L_13 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
switch ( V_29 -> V_69 ) {
case 1 :
if ( F_29 ( V_29 -> V_85 [ 0 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
if ( V_29 -> V_57 == V_59 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 , V_78 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0x01 , 0x00 , V_78 , 0x00 ) ;
}
if ( V_54 < V_71 ) {
if ( V_54 <= 1 ) {
F_6 ( V_2 , 1 ,
0x89 , 0x03 , V_78 , 0xff ) ;
} else {
F_6 ( V_2 , 1 , V_54 - 1 ,
0x02 , V_78 , 0x00 ) ;
F_6 ( V_2 , 2 ,
0x09 , 0x01 , V_78 , 0xff ) ;
}
} else {
V_54 = V_54 - 1 ;
F_6 ( V_2 , 1 ,
V_54 / 2 , 0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 2 , V_54 - V_54 / 2 ,
0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 3 ,
0x09 , 0x03 , V_78 , 0xff ) ;
}
break;
case 2 :
if ( F_29 ( V_29 -> V_85 [ 0 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_78 , 0x00 ) ;
V_82 = V_54 - 1 ;
if ( F_29 ( V_29 -> V_85 [ 1 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , 1 , V_82 / 2 ,
0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 2 , V_82 - V_82 / 2 ,
0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x02 , V_78 , 0x00 ) ;
V_82 = V_54 - 2 ;
if ( F_29 ( V_29 -> V_85 [ 0 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , 4 , V_82 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_78 , 0x00 ) ;
F_6 ( V_2 , 5 , V_82 - V_82 / 2 ,
0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_78 , 0x00 ) ;
break;
case 3 :
for ( V_80 = 0 ; V_80 < 1 ; V_80 ++ ) {
int V_15 = V_80 * 2 ;
if ( F_29 ( V_29 -> V_85 [ V_80 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , V_15 , V_54 / 2 ,
0x02 , V_78 , 0x00 ) ;
if ( F_29 ( V_29 -> V_85 [ V_80 + 1 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , V_15 + 1 , V_54 - V_54 / 2 ,
0x00 , 0xfe & V_78 , 0x00 ) ;
}
V_82 = V_54 - 2 ;
F_6 ( V_2 , 4 , V_82 / 2 ,
0x02 , V_78 , 0x00 ) ;
if ( F_29 ( V_29 -> V_85 [ 0 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
F_6 ( V_2 , 5 , V_82 - V_82 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_78 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_78 , 0x00 ) ;
break;
case 16 :
if ( F_29 ( V_29 -> V_85 [ 0 ] ) > 0 )
V_78 = 0xff - 0x04 ;
else
V_78 = 0xff ;
if ( V_29 -> V_57 == V_59 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 ,
( 0xff - 0x02 ) & V_78 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0xff , 0x00 ,
( 0xff - 0x02 ) & V_78 , 0x00 ) ;
}
F_6 ( V_2 , 1 , 0x01 , 0x02 , V_78 , 0x00 ) ;
V_54 = V_54 - 2 ;
F_6 ( V_2 , 2 , V_54 / 2 ,
0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 3 , V_54 - V_54 / 2 ,
0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x09 , 0x01 , V_78 , 0xff ) ;
break;
default:
F_5 ( V_2 -> V_14 , L_14 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_24 ;
}
V_81 = F_1 ( V_2 , V_88 ) ;
if ( V_81 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_81 ;
}
if ( ( V_29 -> V_57 == V_58 ) || ( V_29 -> V_57 == V_59 ) ) {
V_7 -> V_20 = 1 ;
V_10 = F_19 ( V_2 ) ;
if ( V_10 < 0 ) {
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_27 -> V_75 = NULL ;
} else {
V_23 -> V_27 -> V_75 = F_27 ;
}
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_89 * V_90 ,
unsigned int * V_91 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_76 = F_30 ( V_90 -> V_92 ) ;
unsigned int V_93 = F_29 ( V_90 -> V_92 ) ;
T_1 V_78 = V_93 ? ( 0xff - 0x04 ) : 0xff ;
int V_79 , V_80 , V_94 , V_32 ;
int V_10 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 ,
L_15 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_83 ;
}
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_78 , 0x00 ) ;
F_6 ( V_2 , 1 , 0x0c , 0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 2 , 0x01 , 0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x01 , 0x00 , 0xfe & V_78 , 0x00 ) ;
F_6 ( V_2 , 5 , 0x0c , 0x00 , V_78 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_78 , 0x00 ) ;
V_10 = F_1 ( V_2 , V_88 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
for ( V_79 = 0 ; V_79 < V_84 ; V_79 ++ ) {
V_10 = F_3 ( V_5 , F_21 ( V_5 , V_50 ) ,
V_7 -> V_51 , V_52 ,
& V_32 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_16 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
}
for ( V_79 = 0 ; V_79 < V_90 -> V_94 ; ) {
V_10 = F_3 ( V_5 , F_21 ( V_5 , V_50 ) ,
V_7 -> V_51 , V_52 ,
& V_32 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_17 , V_10 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_94 = V_32 / sizeof( V_95 ) ;
if ( ( V_94 % 16 ) != 0 ) {
F_5 ( V_2 -> V_14 , L_18 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
for ( V_80 = V_76 ; ( V_80 < V_94 ) && ( V_79 < V_90 -> V_94 ) ; V_80 = V_80 + 16 ) {
V_91 [ V_79 ] = ( ( V_95 * ) ( V_7 -> V_51 ) ) [ V_80 ] ;
V_79 ++ ;
}
}
F_11 ( & V_7 -> V_25 ) ;
return V_90 -> V_94 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_22 * V_23 ;
int V_10 ;
F_10 ( & V_7 -> V_25 ) ;
V_10 = F_33 ( V_2 , 1 ) ;
if ( V_10 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 = & V_2 -> V_96 [ 0 ] ;
V_2 -> V_45 = V_23 ;
V_23 -> type = V_97 ;
V_23 -> V_98 = V_99 | V_100 | V_101 ;
V_23 -> V_102 = 16 ;
V_23 -> V_103 = 16 ;
V_23 -> V_104 = F_31 ;
V_23 -> V_105 = F_22 ;
V_23 -> V_106 = F_28 ;
V_23 -> V_107 = F_9 ;
V_23 -> V_108 = 0x1000 ;
V_23 -> V_109 = & V_110 ;
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const T_2 * V_91 , T_3 V_111 ,
unsigned long V_44 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_112 ;
unsigned char * V_55 ;
int V_10 ;
if ( ! V_91 )
return 0 ;
if ( V_111 > V_113 ) {
F_5 ( V_2 -> V_14 , L_19 ) ;
return - V_114 ;
}
V_112 = F_35 ( V_91 , V_111 , V_115 ) ;
if ( ! V_112 )
return - V_114 ;
V_55 = F_36 ( 1 , V_115 ) ;
if ( ! V_55 ) {
F_37 ( V_112 ) ;
return - V_114 ;
}
* V_55 = 1 ;
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_116 ,
V_117 ,
V_118 , 0x0000 ,
V_55 , 1 ,
V_119 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_20 ) ;
goto V_120;
}
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_116 ,
V_117 ,
0 , 0x0000 ,
V_112 , V_111 ,
V_119 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_21 ) ;
goto V_120;
}
* V_55 = 0 ;
V_10 = F_38 ( V_5 , F_39 ( V_5 , 0 ) ,
V_116 ,
V_117 ,
V_118 , 0x0000 ,
V_55 , 1 ,
V_119 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_14 , L_22 ) ;
V_120:
F_37 ( V_55 ) ;
F_37 ( V_112 ) ;
return V_10 ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned long V_121 )
{
struct V_122 * V_123 = F_41 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_10 ;
if ( V_5 -> V_124 != V_125 ) {
F_5 ( V_2 -> V_14 ,
L_23 ) ;
return - V_126 ;
}
V_7 = F_42 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_114 ;
F_43 ( & V_7 -> V_25 , 1 ) ;
F_44 ( V_123 , V_7 ) ;
V_7 -> V_11 = F_36 ( V_13 , V_115 ) ;
if ( ! V_7 -> V_11 )
return - V_114 ;
V_10 = F_45 ( V_5 ,
V_123 -> V_127 -> V_128 . V_129 , 1 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_24 ) ;
return - V_126 ;
}
V_7 -> V_21 = F_46 ( 0 , V_115 ) ;
if ( ! V_7 -> V_21 ) {
F_5 ( V_2 -> V_14 , L_25 ) ;
return - V_114 ;
}
V_7 -> V_51 = F_36 ( V_52 , V_115 ) ;
if ( ! V_7 -> V_51 )
return - V_114 ;
V_10 = F_47 ( V_2 , & V_5 -> V_2 , V_130 ,
F_34 , 0 ) ;
if ( V_10 )
return V_10 ;
return F_32 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = F_41 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_10 ( & V_7 -> V_25 ) ;
F_44 ( V_123 , NULL ) ;
if ( V_7 -> V_21 ) {
F_8 ( V_7 -> V_21 ) ;
F_37 ( V_7 -> V_51 ) ;
V_7 -> V_51 = NULL ;
F_49 ( V_7 -> V_21 ) ;
V_7 -> V_21 = NULL ;
}
F_37 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
}
static int F_50 ( struct V_122 * V_123 ,
const struct V_131 * V_132 )
{
return F_51 ( V_123 , & V_133 , 0 ) ;
}
