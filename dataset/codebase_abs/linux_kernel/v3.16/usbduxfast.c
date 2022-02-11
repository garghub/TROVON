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
static void F_12 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_26 ;
struct V_22 * V_23 = V_2 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_32 , V_33 ;
if ( F_13 ( ! V_7 -> V_20 ) ) {
return;
}
switch ( V_21 -> V_34 ) {
case 0 :
break;
case - V_35 :
case - V_36 :
case - V_37 :
case - V_38 :
V_29 -> V_39 |= V_40 ;
V_29 -> V_39 |= V_41 ;
F_14 ( V_2 , V_23 ) ;
F_7 ( V_2 , 0 ) ;
return;
default:
F_15 ( L_2 ,
V_21 -> V_34 ) ;
V_29 -> V_39 |= V_40 ;
V_29 -> V_39 |= V_41 ;
F_14 ( V_2 , V_23 ) ;
F_7 ( V_2 , 0 ) ;
return;
}
if ( ! V_7 -> V_42 ) {
if ( V_31 -> V_43 == V_44 ) {
V_32 = V_21 -> V_45 / sizeof( V_46 ) ;
if ( F_13 ( V_7 -> V_47 < V_32 ) ) {
unsigned int V_48 ;
V_48 = V_7 -> V_47 *
sizeof( V_46 ) ;
F_16 ( V_23 ,
V_21 -> V_49 ,
V_48 ) ;
F_7 ( V_2 , 0 ) ;
V_29 -> V_39 |= V_40 ;
F_14 ( V_2 , V_23 ) ;
return;
}
V_7 -> V_47 -= V_32 ;
}
V_33 = F_16 ( V_23 , V_21 -> V_49 ,
V_21 -> V_45 ) ;
if ( F_13 ( V_33 == 0 ) ) {
F_7 ( V_2 , 0 ) ;
return;
}
F_14 ( V_2 , V_23 ) ;
} else {
V_7 -> V_42 -- ;
}
V_21 -> V_2 = V_5 ;
V_21 -> V_34 = 0 ;
V_33 = F_17 ( V_21 , V_50 ) ;
if ( V_33 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_3 , V_33 ) ;
V_29 -> V_39 |= V_40 ;
V_29 -> V_39 |= V_41 ;
F_14 ( V_2 , V_23 ) ;
F_7 ( V_2 , 0 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
if ( ! V_7 )
return - V_24 ;
F_19 ( V_7 -> V_21 , V_5 , F_20 ( V_5 , V_51 ) ,
V_7 -> V_52 , V_53 ,
F_12 , V_2 ) ;
V_10 = F_17 ( V_7 -> V_21 , V_50 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_14 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_30 * V_31 )
{
int V_33 = 0 ;
long int V_54 , V_55 ;
int V_56 ;
V_33 |= F_22 ( & V_31 -> V_57 ,
V_58 | V_59 | V_60 ) ;
V_33 |= F_22 ( & V_31 -> V_61 ,
V_62 | V_59 ) ;
V_33 |= F_22 ( & V_31 -> V_63 , V_64 | V_59 ) ;
V_33 |= F_22 ( & V_31 -> V_65 , V_44 ) ;
V_33 |= F_22 ( & V_31 -> V_43 , V_44 | V_66 ) ;
if ( V_33 )
return 1 ;
V_33 |= F_23 ( V_31 -> V_57 ) ;
V_33 |= F_23 ( V_31 -> V_61 ) ;
V_33 |= F_23 ( V_31 -> V_63 ) ;
V_33 |= F_23 ( V_31 -> V_43 ) ;
if ( V_31 -> V_57 == V_59 && V_31 -> V_43 == V_59 )
V_33 |= - V_67 ;
if ( V_33 )
return 2 ;
V_33 |= F_24 ( & V_31 -> V_68 , 0 ) ;
if ( ! V_31 -> V_69 )
V_33 |= - V_67 ;
V_33 |= F_24 ( & V_31 -> V_70 , V_31 -> V_69 ) ;
if ( V_31 -> V_69 == 1 )
V_56 = 1 ;
else
V_56 = V_71 ;
if ( V_31 -> V_63 == V_64 ) {
V_54 = V_31 -> V_72 * 30 ;
if ( V_54 < ( V_56 * 1000 ) )
V_54 = V_56 * 1000 ;
if ( V_54 > ( V_73 * 1000 ) )
V_54 = V_73 * 1000 ;
V_55 = V_54 / 30 ;
V_33 |= F_24 ( & V_31 -> V_72 , V_55 ) ;
}
switch ( V_31 -> V_43 ) {
case V_44 :
V_33 |= F_25 ( & V_31 -> V_74 , 1 ) ;
break;
case V_66 :
V_33 |= F_24 ( & V_31 -> V_74 , 0 ) ;
break;
default:
break;
}
if ( V_33 )
return 3 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
unsigned int V_75 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_30 * V_31 = & V_23 -> V_29 -> V_31 ;
int V_10 ;
if ( ! V_7 )
return - V_24 ;
if ( V_75 != V_31 -> V_68 )
return - V_67 ;
F_10 ( & V_7 -> V_25 ) ;
if ( ! V_7 -> V_20 ) {
V_7 -> V_20 = 1 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_5 , V_10 ) ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_29 -> V_76 = NULL ;
} else {
F_5 ( V_2 -> V_14 , L_6 ) ;
}
F_11 ( & V_7 -> V_25 ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_30 * V_31 = & V_23 -> V_29 -> V_31 ;
unsigned int V_77 , V_78 , V_79 = 0xff ;
int V_80 , V_81 , V_10 ;
int V_82 ;
long V_54 , V_83 ;
if ( ! V_7 )
return - V_24 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 , L_7 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_84 ;
}
V_23 -> V_29 -> V_85 = 0 ;
V_7 -> V_42 = V_86 ;
V_78 = F_28 ( V_31 -> V_87 [ 0 ] ) ;
for ( V_80 = 0 ; V_80 < V_31 -> V_69 ; ++ V_80 ) {
V_77 = F_29 ( V_31 -> V_87 [ V_80 ] ) ;
if ( V_77 != V_80 ) {
F_5 ( V_2 -> V_14 ,
L_8 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( ( V_78 != F_28 ( V_31 -> V_87 [ V_80 ] ) )
&& ( V_31 -> V_69 > 3 ) ) {
F_5 ( V_2 -> V_14 ,
L_9 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( V_80 >= V_88 ) {
F_5 ( V_2 -> V_14 , L_10 ) ;
break;
}
}
V_54 = 0 ;
if ( V_31 -> V_63 == V_64 )
V_54 = ( V_31 -> V_72 * 30 ) / 1000 ;
if ( ( V_54 < V_71 ) && ( V_31 -> V_69 != 1 ) ) {
F_5 ( V_2 -> V_14 ,
L_11 ,
V_54 , V_31 -> V_89 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( V_54 > V_73 ) {
F_5 ( V_2 -> V_14 , L_12 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
if ( ( V_31 -> V_57 == V_59 ) && ( V_31 -> V_69 != 1 )
&& ( V_31 -> V_69 != 16 ) ) {
F_5 ( V_2 -> V_14 ,
L_13 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
switch ( V_31 -> V_69 ) {
case 1 :
if ( F_28 ( V_31 -> V_87 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
if ( V_31 -> V_57 == V_59 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 , V_79 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0x01 , 0x00 , V_79 , 0x00 ) ;
}
if ( V_54 < V_71 ) {
if ( V_54 <= 1 ) {
F_6 ( V_2 , 1 ,
0x89 , 0x03 , V_79 , 0xff ) ;
} else {
F_6 ( V_2 , 1 , V_54 - 1 ,
0x02 , V_79 , 0x00 ) ;
F_6 ( V_2 , 2 ,
0x09 , 0x01 , V_79 , 0xff ) ;
}
} else {
V_54 = V_54 - 1 ;
F_6 ( V_2 , 1 ,
V_54 / 2 , 0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , V_54 - V_54 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 3 ,
0x09 , 0x03 , V_79 , 0xff ) ;
}
break;
case 2 :
if ( F_28 ( V_31 -> V_87 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_83 = V_54 - 1 ;
if ( F_28 ( V_31 -> V_87 [ 1 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 1 , V_83 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , V_83 - V_83 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_83 = V_54 - 2 ;
if ( F_28 ( V_31 -> V_87 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 4 , V_83 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_79 , 0x00 ) ;
F_6 ( V_2 , 5 , V_83 - V_83 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
break;
case 3 :
for ( V_81 = 0 ; V_81 < 1 ; V_81 ++ ) {
int V_15 = V_81 * 2 ;
if ( F_28 ( V_31 -> V_87 [ V_81 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , V_15 , V_54 / 2 ,
0x02 , V_79 , 0x00 ) ;
if ( F_28 ( V_31 -> V_87 [ V_81 + 1 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , V_15 + 1 , V_54 - V_54 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
}
V_83 = V_54 - 2 ;
F_6 ( V_2 , 4 , V_83 / 2 ,
0x02 , V_79 , 0x00 ) ;
if ( F_28 ( V_31 -> V_87 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
F_6 ( V_2 , 5 , V_83 - V_83 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
case 16 :
if ( F_28 ( V_31 -> V_87 [ 0 ] ) > 0 )
V_79 = 0xff - 0x04 ;
else
V_79 = 0xff ;
if ( V_31 -> V_57 == V_59 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 ,
( 0xff - 0x02 ) & V_79 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0xff , 0x00 ,
( 0xff - 0x02 ) & V_79 , 0x00 ) ;
}
F_6 ( V_2 , 1 , 0x01 , 0x02 , V_79 , 0x00 ) ;
V_54 = V_54 - 2 ;
F_6 ( V_2 , 2 , V_54 / 2 ,
0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , V_54 - V_54 / 2 ,
0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x09 , 0x01 , V_79 , 0xff ) ;
break;
default:
F_5 ( V_2 -> V_14 , L_14 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_24 ;
}
V_82 = F_1 ( V_2 , V_90 ) ;
if ( V_82 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_82 ;
}
if ( V_31 -> V_43 == V_44 )
V_7 -> V_47 = V_31 -> V_74 * V_31 -> V_70 ;
else
V_7 -> V_47 = 0 ;
if ( ( V_31 -> V_57 == V_58 ) || ( V_31 -> V_57 == V_59 ) ) {
V_7 -> V_20 = 1 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 ) {
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_29 -> V_76 = NULL ;
} else {
V_23 -> V_29 -> V_76 = F_26 ;
}
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_91 * V_92 ,
unsigned int * V_93 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_77 = F_29 ( V_92 -> V_94 ) ;
unsigned int V_95 = F_28 ( V_92 -> V_94 ) ;
T_1 V_79 = V_95 ? ( 0xff - 0x04 ) : 0xff ;
int V_80 , V_81 , V_32 , V_45 ;
int V_10 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 ,
L_15 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_84 ;
}
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_79 , 0x00 ) ;
F_6 ( V_2 , 1 , 0x0c , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 2 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x01 , 0x00 , 0xfe & V_79 , 0x00 ) ;
F_6 ( V_2 , 5 , 0x0c , 0x00 , V_79 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_79 , 0x00 ) ;
V_10 = F_1 ( V_2 , V_90 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
for ( V_80 = 0 ; V_80 < V_86 ; V_80 ++ ) {
V_10 = F_3 ( V_5 , F_20 ( V_5 , V_51 ) ,
V_7 -> V_52 , V_53 ,
& V_45 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_16 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
}
for ( V_80 = 0 ; V_80 < V_92 -> V_32 ; ) {
V_10 = F_3 ( V_5 , F_20 ( V_5 , V_51 ) ,
V_7 -> V_52 , V_53 ,
& V_45 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_17 , V_10 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_32 = V_45 / sizeof( V_46 ) ;
if ( ( V_32 % 16 ) != 0 ) {
F_5 ( V_2 -> V_14 , L_18 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_67 ;
}
for ( V_81 = V_77 ; ( V_81 < V_32 ) && ( V_80 < V_92 -> V_32 ) ; V_81 = V_81 + 16 ) {
V_93 [ V_80 ] = ( ( V_46 * ) ( V_7 -> V_52 ) ) [ V_81 ] ;
V_80 ++ ;
}
}
F_11 ( & V_7 -> V_25 ) ;
return V_92 -> V_32 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_22 * V_23 ;
int V_10 ;
F_10 ( & V_7 -> V_25 ) ;
V_10 = F_32 ( V_2 , 1 ) ;
if ( V_10 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 = & V_2 -> V_96 [ 0 ] ;
V_2 -> V_27 = V_23 ;
V_23 -> type = V_97 ;
V_23 -> V_98 = V_99 | V_100 | V_101 ;
V_23 -> V_102 = 16 ;
V_23 -> V_103 = 16 ;
V_23 -> V_104 = F_30 ;
V_23 -> V_105 = F_21 ;
V_23 -> V_106 = F_27 ;
V_23 -> V_107 = F_9 ;
V_23 -> V_108 = 0x1000 ;
V_23 -> V_109 = & V_110 ;
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const T_2 * V_93 , T_3 V_111 ,
unsigned long V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_112 ;
unsigned char * V_55 ;
int V_10 ;
if ( ! V_93 )
return 0 ;
if ( V_111 > V_113 ) {
F_5 ( V_2 -> V_14 , L_19 ) ;
return - V_114 ;
}
V_112 = F_34 ( V_93 , V_111 , V_115 ) ;
if ( ! V_112 )
return - V_114 ;
V_55 = F_35 ( 1 , V_115 ) ;
if ( ! V_55 ) {
F_36 ( V_112 ) ;
return - V_114 ;
}
* V_55 = 1 ;
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
V_116 ,
V_117 ,
V_118 , 0x0000 ,
V_55 , 1 ,
V_119 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_20 ) ;
goto V_120;
}
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
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
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
V_116 ,
V_117 ,
V_118 , 0x0000 ,
V_55 , 1 ,
V_119 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_14 , L_22 ) ;
V_120:
F_36 ( V_55 ) ;
F_36 ( V_112 ) ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_121 )
{
struct V_122 * V_123 = F_40 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_10 ;
if ( V_5 -> V_124 != V_125 ) {
F_5 ( V_2 -> V_14 ,
L_23 ) ;
return - V_126 ;
}
V_7 = F_41 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_114 ;
F_42 ( & V_7 -> V_25 , 1 ) ;
F_43 ( V_123 , V_7 ) ;
V_7 -> V_11 = F_35 ( V_13 , V_115 ) ;
if ( ! V_7 -> V_11 )
return - V_114 ;
V_10 = F_44 ( V_5 ,
V_123 -> V_127 -> V_128 . V_129 , 1 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_24 ) ;
return - V_126 ;
}
V_7 -> V_21 = F_45 ( 0 , V_115 ) ;
if ( ! V_7 -> V_21 ) {
F_5 ( V_2 -> V_14 , L_25 ) ;
return - V_114 ;
}
V_7 -> V_52 = F_35 ( V_53 , V_115 ) ;
if ( ! V_7 -> V_52 )
return - V_114 ;
V_10 = F_46 ( V_2 , & V_5 -> V_2 , V_130 ,
F_33 , 0 ) ;
if ( V_10 )
return V_10 ;
return F_31 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = F_40 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_10 ( & V_7 -> V_25 ) ;
F_43 ( V_123 , NULL ) ;
if ( V_7 -> V_21 ) {
F_8 ( V_7 -> V_21 ) ;
F_36 ( V_7 -> V_52 ) ;
V_7 -> V_52 = NULL ;
F_48 ( V_7 -> V_21 ) ;
V_7 -> V_21 = NULL ;
}
F_36 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
}
static int F_49 ( struct V_122 * V_123 ,
const struct V_131 * V_132 )
{
return F_50 ( V_123 , & V_133 , 0 ) ;
}
