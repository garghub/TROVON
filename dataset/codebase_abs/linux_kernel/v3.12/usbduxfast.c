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
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_30 , V_31 ;
if ( F_13 ( ! V_7 -> V_20 ) ) {
return;
}
switch ( V_21 -> V_32 ) {
case 0 :
break;
case - V_33 :
case - V_34 :
case - V_35 :
case - V_36 :
V_29 -> V_37 |= V_38 ;
V_29 -> V_37 |= V_39 ;
F_14 ( V_2 , V_23 ) ;
F_7 ( V_2 , 0 ) ;
return;
default:
F_15 ( L_2 ,
V_21 -> V_32 ) ;
V_29 -> V_37 |= V_38 ;
V_29 -> V_37 |= V_39 ;
F_14 ( V_2 , V_23 ) ;
F_7 ( V_2 , 0 ) ;
return;
}
if ( ! V_7 -> V_40 ) {
if ( ! V_7 -> V_41 ) {
V_30 = V_21 -> V_42 / sizeof( V_43 ) ;
if ( F_13 ( V_7 -> V_44 < V_30 ) ) {
unsigned int V_45 ;
V_45 = V_7 -> V_44 *
sizeof( V_43 ) ;
F_16 ( V_23 ,
V_21 -> V_46 ,
V_45 ) ;
F_7 ( V_2 , 0 ) ;
V_29 -> V_37 |= V_38 ;
F_14 ( V_2 , V_23 ) ;
return;
}
V_7 -> V_44 -= V_30 ;
}
V_31 = F_16 ( V_23 , V_21 -> V_46 ,
V_21 -> V_42 ) ;
if ( F_13 ( V_31 == 0 ) ) {
F_7 ( V_2 , 0 ) ;
return;
}
F_14 ( V_2 , V_23 ) ;
} else {
V_7 -> V_40 -- ;
}
V_21 -> V_2 = V_5 ;
V_21 -> V_32 = 0 ;
V_31 = F_17 ( V_21 , V_47 ) ;
if ( V_31 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_3 , V_31 ) ;
V_29 -> V_37 |= V_38 ;
V_29 -> V_37 |= V_39 ;
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
F_19 ( V_7 -> V_21 , V_5 , F_20 ( V_5 , V_48 ) ,
V_7 -> V_49 , V_50 ,
F_12 , V_2 ) ;
V_10 = F_17 ( V_7 -> V_21 , V_47 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_14 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_51 * V_52 )
{
int V_31 = 0 ;
long int V_53 , V_54 ;
int V_55 ;
V_31 |= F_22 ( & V_52 -> V_56 ,
V_57 | V_58 | V_59 ) ;
V_31 |= F_22 ( & V_52 -> V_60 ,
V_61 | V_62 | V_58 ) ;
V_31 |= F_22 ( & V_52 -> V_63 , V_61 | V_58 ) ;
V_31 |= F_22 ( & V_52 -> V_64 , V_65 ) ;
V_31 |= F_22 ( & V_52 -> V_66 , V_65 | V_67 ) ;
if ( V_31 )
return 1 ;
V_31 |= F_23 ( V_52 -> V_56 ) ;
V_31 |= F_23 ( V_52 -> V_60 ) ;
V_31 |= F_23 ( V_52 -> V_63 ) ;
V_31 |= F_23 ( V_52 -> V_66 ) ;
if ( V_52 -> V_56 == V_58 && V_52 -> V_66 == V_58 )
V_31 |= - V_68 ;
if ( V_31 )
return 2 ;
if ( V_52 -> V_56 == V_57 )
V_31 |= F_24 ( & V_52 -> V_69 , 0 ) ;
if ( ! V_52 -> V_70 )
V_31 |= - V_68 ;
V_31 |= F_24 ( & V_52 -> V_71 , V_52 -> V_70 ) ;
if ( V_52 -> V_70 == 1 )
V_55 = 1 ;
else
V_55 = V_72 ;
if ( V_52 -> V_63 == V_61 ) {
V_53 = V_52 -> V_73 * 30 ;
if ( V_53 < ( V_55 * 1000 ) )
V_53 = V_55 * 1000 ;
if ( V_53 > ( V_74 * 1000 ) )
V_53 = V_74 * 1000 ;
V_54 = V_53 / 30 ;
V_31 |= F_24 ( & V_52 -> V_73 , V_54 ) ;
}
if ( V_52 -> V_60 == V_61 )
V_31 |= - V_68 ;
switch ( V_52 -> V_66 ) {
case V_65 :
V_31 |= F_25 ( & V_52 -> V_75 , 1 ) ;
break;
case V_67 :
V_31 |= F_24 ( & V_52 -> V_75 , 0 ) ;
break;
default:
break;
}
if ( V_31 )
return 3 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
unsigned int V_76 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
if ( ! V_7 )
return - V_24 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_76 != 0 ) {
F_5 ( V_2 -> V_14 , L_5 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( ! V_7 -> V_20 ) {
V_7 -> V_20 = 1 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_6 , V_10 ) ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_29 -> V_77 = NULL ;
} else {
F_5 ( V_2 -> V_14 , L_7 ) ;
}
F_11 ( & V_7 -> V_25 ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_51 * V_52 = & V_23 -> V_29 -> V_52 ;
unsigned int V_78 , V_79 , V_80 = 0xff ;
int V_81 , V_82 , V_10 ;
int V_83 ;
long V_53 , V_84 ;
if ( ! V_7 )
return - V_24 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 , L_8 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_85 ;
}
V_23 -> V_29 -> V_86 = 0 ;
V_7 -> V_40 = V_87 ;
if ( V_52 -> V_70 > 0 ) {
V_79 = F_28 ( V_52 -> V_88 [ 0 ] ) ;
for ( V_81 = 0 ; V_81 < V_52 -> V_70 ; ++ V_81 ) {
V_78 = F_29 ( V_52 -> V_88 [ V_81 ] ) ;
if ( V_78 != V_81 ) {
F_5 ( V_2 -> V_14 ,
L_9 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( ( V_79 != F_28 ( V_52 -> V_88 [ V_81 ] ) )
&& ( V_52 -> V_70 > 3 ) ) {
F_5 ( V_2 -> V_14 ,
L_10 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( V_81 >= V_89 ) {
F_5 ( V_2 -> V_14 , L_11 ) ;
break;
}
}
}
V_53 = 0 ;
if ( V_52 -> V_60 == V_61 ) {
F_5 ( V_2 -> V_14 ,
L_12 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( V_52 -> V_63 == V_61 )
V_53 = ( V_52 -> V_73 * 30 ) / 1000 ;
if ( ( V_53 < V_72 ) && ( V_52 -> V_70 != 1 ) ) {
F_5 ( V_2 -> V_14 ,
L_13 ,
V_53 , V_52 -> V_90 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( V_53 > V_74 ) {
F_5 ( V_2 -> V_14 , L_14 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
if ( ( V_52 -> V_56 == V_58 ) && ( V_52 -> V_70 != 1 )
&& ( V_52 -> V_70 != 16 ) ) {
F_5 ( V_2 -> V_14 ,
L_15 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
switch ( V_52 -> V_70 ) {
case 1 :
if ( F_28 ( V_52 -> V_88 [ 0 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
if ( V_52 -> V_56 == V_58 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 , V_80 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0x01 , 0x00 , V_80 , 0x00 ) ;
}
if ( V_53 < V_72 ) {
if ( V_53 <= 1 ) {
F_6 ( V_2 , 1 ,
0x89 , 0x03 , V_80 , 0xff ) ;
} else {
F_6 ( V_2 , 1 , V_53 - 1 ,
0x02 , V_80 , 0x00 ) ;
F_6 ( V_2 , 2 ,
0x09 , 0x01 , V_80 , 0xff ) ;
}
} else {
V_53 = V_53 - 1 ;
F_6 ( V_2 , 1 ,
V_53 / 2 , 0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 2 , V_53 - V_53 / 2 ,
0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 3 ,
0x09 , 0x03 , V_80 , 0xff ) ;
}
break;
case 2 :
if ( F_28 ( V_52 -> V_88 [ 0 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_80 , 0x00 ) ;
V_84 = V_53 - 1 ;
if ( F_28 ( V_52 -> V_88 [ 1 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , 1 , V_84 / 2 ,
0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 2 , V_84 - V_84 / 2 ,
0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x02 , V_80 , 0x00 ) ;
V_84 = V_53 - 2 ;
if ( F_28 ( V_52 -> V_88 [ 0 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , 4 , V_84 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_80 , 0x00 ) ;
F_6 ( V_2 , 5 , V_84 - V_84 / 2 ,
0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_80 , 0x00 ) ;
break;
case 3 :
for ( V_82 = 0 ; V_82 < 1 ; V_82 ++ ) {
int V_15 = V_82 * 2 ;
if ( F_28 ( V_52 -> V_88 [ V_82 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , V_15 , V_53 / 2 ,
0x02 , V_80 , 0x00 ) ;
if ( F_28 ( V_52 -> V_88 [ V_82 + 1 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , V_15 + 1 , V_53 - V_53 / 2 ,
0x00 , 0xfe & V_80 , 0x00 ) ;
}
V_84 = V_53 - 2 ;
F_6 ( V_2 , 4 , V_84 / 2 ,
0x02 , V_80 , 0x00 ) ;
if ( F_28 ( V_52 -> V_88 [ 0 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
F_6 ( V_2 , 5 , V_84 - V_84 / 2 ,
0x00 , ( 0xff - 0x02 ) & V_80 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_80 , 0x00 ) ;
case 16 :
if ( F_28 ( V_52 -> V_88 [ 0 ] ) > 0 )
V_80 = 0xff - 0x04 ;
else
V_80 = 0xff ;
if ( V_52 -> V_56 == V_58 ) {
F_6 ( V_2 , 0 , 0x01 , 0x01 ,
( 0xff - 0x02 ) & V_80 , 0x00 ) ;
} else {
F_6 ( V_2 , 0 , 0xff , 0x00 ,
( 0xff - 0x02 ) & V_80 , 0x00 ) ;
}
F_6 ( V_2 , 1 , 0x01 , 0x02 , V_80 , 0x00 ) ;
V_53 = V_53 - 2 ;
F_6 ( V_2 , 2 , V_53 / 2 ,
0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 3 , V_53 - V_53 / 2 ,
0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x09 , 0x01 , V_80 , 0xff ) ;
break;
default:
F_5 ( V_2 -> V_14 , L_16 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_24 ;
}
V_83 = F_1 ( V_2 , V_91 ) ;
if ( V_83 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_83 ;
}
if ( V_52 -> V_66 == V_65 ) {
V_7 -> V_44 = V_52 -> V_75 * V_52 -> V_71 ;
if ( V_7 -> V_44 < 1 ) {
F_5 ( V_2 -> V_14 ,
L_17 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_24 ;
}
V_7 -> V_41 = 0 ;
} else {
V_7 -> V_41 = 1 ;
V_7 -> V_44 = 0 ;
}
if ( ( V_52 -> V_56 == V_57 ) || ( V_52 -> V_56 == V_58 ) ) {
V_7 -> V_20 = 1 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 ) {
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_23 -> V_29 -> V_77 = NULL ;
} else {
V_23 -> V_29 -> V_77 = F_26 ;
}
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_92 * V_93 ,
unsigned int * V_94 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_78 = F_29 ( V_93 -> V_95 ) ;
unsigned int V_96 = F_28 ( V_93 -> V_95 ) ;
T_1 V_80 = V_96 ? ( 0xff - 0x04 ) : 0xff ;
int V_81 , V_82 , V_30 , V_42 ;
int V_10 ;
F_10 ( & V_7 -> V_25 ) ;
if ( V_7 -> V_20 ) {
F_5 ( V_2 -> V_14 ,
L_18 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_85 ;
}
F_6 ( V_2 , 0 , 0x01 , 0x02 , V_80 , 0x00 ) ;
F_6 ( V_2 , 1 , 0x0c , 0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 2 , 0x01 , 0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 3 , 0x01 , 0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 4 , 0x01 , 0x00 , 0xfe & V_80 , 0x00 ) ;
F_6 ( V_2 , 5 , 0x0c , 0x00 , V_80 , 0x00 ) ;
F_6 ( V_2 , 6 , 0x01 , 0x00 , V_80 , 0x00 ) ;
V_10 = F_1 ( V_2 , V_91 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
for ( V_81 = 0 ; V_81 < V_87 ; V_81 ++ ) {
V_10 = F_3 ( V_5 , F_20 ( V_5 , V_48 ) ,
V_7 -> V_49 , V_50 ,
& V_42 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_19 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
}
for ( V_81 = 0 ; V_81 < V_93 -> V_30 ; ) {
V_10 = F_3 ( V_5 , F_20 ( V_5 , V_48 ) ,
V_7 -> V_49 , V_50 ,
& V_42 , 10000 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_20 , V_10 ) ;
F_11 ( & V_7 -> V_25 ) ;
return V_10 ;
}
V_30 = V_42 / sizeof( V_43 ) ;
if ( ( V_30 % 16 ) != 0 ) {
F_5 ( V_2 -> V_14 , L_21 ) ;
F_11 ( & V_7 -> V_25 ) ;
return - V_68 ;
}
for ( V_82 = V_78 ; ( V_82 < V_30 ) && ( V_81 < V_93 -> V_30 ) ; V_82 = V_82 + 16 ) {
V_94 [ V_81 ] = ( ( V_43 * ) ( V_7 -> V_49 ) ) [ V_82 ] ;
V_81 ++ ;
}
}
F_11 ( & V_7 -> V_25 ) ;
return V_93 -> V_30 ;
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
V_23 = & V_2 -> V_97 [ 0 ] ;
V_2 -> V_27 = V_23 ;
V_23 -> type = V_98 ;
V_23 -> V_99 = V_100 | V_101 | V_102 ;
V_23 -> V_103 = 16 ;
V_23 -> V_104 = 16 ;
V_23 -> V_105 = F_30 ;
V_23 -> V_106 = F_21 ;
V_23 -> V_107 = F_27 ;
V_23 -> V_108 = F_9 ;
V_23 -> V_109 = 0x1000 ;
V_23 -> V_110 = & V_111 ;
F_11 ( & V_7 -> V_25 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const T_2 * V_94 , T_3 V_112 ,
unsigned long V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_113 ;
unsigned char * V_54 ;
int V_10 ;
if ( ! V_94 )
return 0 ;
if ( V_112 > V_114 ) {
F_5 ( V_2 -> V_14 , L_22 ) ;
return - V_115 ;
}
V_113 = F_34 ( V_94 , V_112 , V_116 ) ;
if ( ! V_113 )
return - V_115 ;
V_54 = F_35 ( 1 , V_116 ) ;
if ( ! V_54 ) {
F_36 ( V_113 ) ;
return - V_115 ;
}
* V_54 = 1 ;
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
V_117 ,
V_118 ,
V_119 , 0x0000 ,
V_54 , 1 ,
V_120 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_23 ) ;
goto V_121;
}
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
V_117 ,
V_118 ,
0 , 0x0000 ,
V_113 , V_112 ,
V_120 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 , L_24 ) ;
goto V_121;
}
* V_54 = 0 ;
V_10 = F_37 ( V_5 , F_38 ( V_5 , 0 ) ,
V_117 ,
V_118 ,
V_119 , 0x0000 ,
V_54 , 1 ,
V_120 ) ;
if ( V_10 < 0 )
F_5 ( V_2 -> V_14 , L_25 ) ;
V_121:
F_36 ( V_54 ) ;
F_36 ( V_113 ) ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_122 )
{
struct V_123 * V_124 = F_40 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_10 ;
if ( V_5 -> V_125 != V_126 ) {
F_5 ( V_2 -> V_14 ,
L_26 ) ;
return - V_127 ;
}
V_7 = F_41 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_115 ;
F_42 ( & V_7 -> V_25 , 1 ) ;
F_43 ( V_124 , V_7 ) ;
V_7 -> V_11 = F_35 ( V_13 , V_116 ) ;
if ( ! V_7 -> V_11 )
return - V_115 ;
V_10 = F_44 ( V_5 ,
V_124 -> V_128 -> V_129 . V_130 , 1 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 -> V_14 ,
L_27 ) ;
return - V_127 ;
}
V_7 -> V_21 = F_45 ( 0 , V_116 ) ;
if ( ! V_7 -> V_21 ) {
F_5 ( V_2 -> V_14 , L_28 ) ;
return - V_115 ;
}
V_7 -> V_49 = F_35 ( V_50 , V_116 ) ;
if ( ! V_7 -> V_49 )
return - V_115 ;
V_10 = F_46 ( V_2 , & V_5 -> V_2 , V_131 ,
F_33 , 0 ) ;
if ( V_10 )
return V_10 ;
return F_31 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = F_40 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_10 ( & V_7 -> V_25 ) ;
F_43 ( V_124 , NULL ) ;
if ( V_7 -> V_21 ) {
F_8 ( V_7 -> V_21 ) ;
F_36 ( V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
F_48 ( V_7 -> V_21 ) ;
V_7 -> V_21 = NULL ;
}
F_36 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_20 = 0 ;
F_11 ( & V_7 -> V_25 ) ;
}
static int F_49 ( struct V_123 * V_124 ,
const struct V_132 * V_133 )
{
return F_50 ( V_124 , & V_134 , 0 ) ;
}
