static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_7 = F_2 ( sizeof( struct V_6 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_7 -> V_20 = 0 ;
V_7 -> V_21 = 0 ;
V_7 -> V_22 = F_3 ( V_5 -> V_23 -> V_24 . V_25 ) ;
switch ( V_7 -> V_22 ) {
case V_26 :
F_4 ( & V_5 -> V_23 -> V_23 , L_1 ) ;
break;
case V_27 :
F_4 ( & V_5 -> V_23 -> V_23 , L_2 ) ;
break;
case V_28 :
F_4 ( & V_5 -> V_23 -> V_23 , L_3 ) ;
break;
case V_29 :
F_4 ( & V_5 -> V_23 -> V_23 , L_4 ) ;
break;
}
F_5 ( V_2 , V_7 ) ;
V_9 = V_5 -> V_23 ;
V_11 = V_9 -> V_11 ;
V_13 = V_11 -> V_13 [ 0 ] ;
V_15 = V_13 -> V_30 ;
V_17 = V_15 -> V_17 ;
for ( V_3 = 0 ; V_3 < V_15 -> V_31 . V_32 ; V_3 ++ ) {
V_17 = & V_15 -> V_17 [ V_3 ] ;
if ( F_6 ( & V_17 -> V_31 ) ) {
F_4 ( & V_5 -> V_23 -> V_23 ,
L_5 ,
V_33 , V_17 -> V_31 . V_34 ) ;
V_7 -> V_35 =
V_17 -> V_31 . V_34 ;
}
if ( F_7 ( & V_17 -> V_31 ) ) {
F_4 ( & V_5 -> V_23 -> V_23 ,
L_6 ,
V_33 , V_17 -> V_31 . V_34 ) ;
V_7 -> V_36 =
V_17 -> V_31 . V_34 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_2 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
static void F_11 ( struct V_37 * V_38 )
{
V_38 -> V_39 . V_40 = 0 ;
V_38 -> V_39 . V_41 &= ~ ( V_42 | V_43 | V_44 | V_45 | V_46 ) ;
V_38 -> V_39 . V_41 |= V_47 | V_48 | V_49 ;
V_38 -> V_39 . V_50 &= ~ V_51 ;
}
static int F_12 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
struct V_52 * V_23 = & V_2 -> V_23 ;
int V_53 = 0 ;
struct V_6 * V_7 ;
unsigned char * V_54 ;
int V_55 = 8 ;
int V_56 = 8 ;
V_7 = F_9 ( V_2 ) ;
V_54 = F_13 ( V_55 , V_18 ) ;
if ( ! V_54 )
return - V_19 ;
if ( ! V_2 -> V_57 ) {
F_4 ( V_23 , L_7 , V_33 ) ;
V_2 -> V_57 = F_14 ( 0 , V_18 ) ;
if ( ! V_2 -> V_57 ) {
F_4 ( V_23 , L_8 , V_33 ) ;
F_10 ( V_54 ) ;
return - V_19 ;
}
}
V_2 -> V_57 -> V_54 =
F_2 ( V_56 , V_18 ) ;
if ( ! V_2 -> V_57 -> V_54 ) {
F_10 ( V_54 ) ;
F_15 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
return - V_19 ;
}
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_58 ,
V_59 | V_60 | V_61 ,
V_62 ,
0 ,
V_54 ,
V_55 ,
V_63
) ;
F_4 ( V_23 , L_9 , V_33 , V_53 ) ;
F_4 ( V_23 , L_10 , V_54 [ 0 ] ,
V_54 [ 1 ] , V_54 [ 2 ] ) ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_58 ,
V_59 | V_60 | V_61 ,
V_64 ,
0 ,
V_54 ,
V_55 ,
V_63
) ;
F_4 ( V_23 , L_11 , V_33 , V_53 ) ;
F_4 ( V_23 , L_12 , V_54 [ 0 ] ,
V_54 [ 1 ] , V_54 [ 2 ] ) ;
if ( V_7 -> V_22 == V_26 ||
V_7 -> V_22 == V_27 ) {
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_65 ,
V_59 | V_60 | V_66 ,
V_67 | V_68 |
V_69 ,
0 ,
V_54 ,
0 ,
V_63
) ;
F_4 ( V_23 , L_13 , V_33 , V_53 ) ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_70 ,
V_59 | V_60 | V_66 ,
V_71 ,
0 ,
V_54 ,
0 ,
V_63
) ;
F_4 ( V_23 , L_14 , V_33 , V_53 ) ;
}
if ( V_7 -> V_22 == V_28 ||
V_7 -> V_22 == V_26 ||
V_7 -> V_22 == V_29 ) {
V_53 = F_18 ( V_2 -> V_72 , V_73 ) ;
F_4 ( V_23 , L_15 , V_33 , V_53 ) ;
}
F_10 ( V_54 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 ) {
F_20 ( V_2 -> V_57 ) ;
F_10 ( V_2 -> V_57 -> V_54 ) ;
F_15 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
F_21 ( V_2 -> V_72 ) ;
}
static void F_22 ( struct V_74 * V_74 )
{
int V_53 ;
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_37 * V_38 ;
unsigned char * V_76 = V_74 -> V_54 ;
int V_77 = V_74 -> V_77 ;
if ( V_77 ) {
F_4 ( & V_2 -> V_23 , L_16 , V_33 , V_77 ) ;
return;
}
V_38 = F_23 ( & V_2 -> V_2 ) ;
if ( V_38 && V_74 -> V_78 ) {
F_24 ( V_38 , V_76 , V_74 -> V_78 ) ;
F_25 ( V_38 ) ;
}
F_26 ( V_38 ) ;
V_53 = F_18 ( V_2 -> V_72 , V_73 ) ;
F_4 ( & V_2 -> V_23 , L_15 , V_33 , V_53 ) ;
}
static void F_27 ( struct V_74 * V_79 )
{
}
static int F_28 ( struct V_37 * V_38 , struct V_1 * V_2 ,
const unsigned char * V_80 , int V_81 )
{
int V_82 = 0 ;
int V_53 = 0 ;
int V_83 = 0 ;
struct V_6 * V_7 ;
if ( V_81 == 0 ) {
F_4 ( & V_2 -> V_23 , L_17 , V_33 ) ;
return 0 ;
}
V_7 = F_9 ( V_2 ) ;
if ( V_81 > ( V_84 - V_7 -> V_20 ) ) {
F_4 ( & V_2 -> V_23 , L_18 , V_33 ) ;
return - V_19 ;
}
memcpy ( V_7 -> V_80 + V_7 -> V_20 , V_80 , V_81 ) ;
F_29 ( & V_2 -> V_23 , V_33 , V_81 , V_7 -> V_80 + V_7 -> V_20 ) ;
V_7 -> V_20 = V_7 -> V_20 + V_81 ;
if ( ( ( V_7 -> V_22 != V_26 ) && ( V_7 -> V_20 > 2 ) && ( V_7 -> V_20 >= ( V_7 -> V_80 [ 1 ] + 3 ) ) ) ||
( ( V_7 -> V_22 == V_26 ) && ( V_7 -> V_20 > 3 ) && ( V_7 -> V_20 >= ( V_7 -> V_80 [ 2 ] + 4 ) ) ) ) {
if ( ( V_7 -> V_22 == V_26 )
|| ( V_7 -> V_22 == V_27 ) )
F_21 ( V_2 -> V_72 ) ;
V_83 = V_7 -> V_20 - V_7 -> V_21 ;
while ( V_83 > 0 ) {
V_82 = ( V_83 < 8 ) ? V_83 : 8 ;
memcpy ( V_2 -> V_57 -> V_54 ,
V_7 -> V_80 + V_7 -> V_21 , V_82 ) ;
F_30 ( V_2 -> V_57 ,
V_2 -> V_5 -> V_23 ,
F_31 ( V_2 -> V_5 -> V_23 ,
V_7 -> V_35 ) ,
V_2 -> V_57 -> V_54 ,
V_82 ,
F_27 ,
V_2 ,
8
) ;
V_7 -> V_21 = V_7 -> V_21 + V_82 ;
V_53 = F_18 ( V_2 -> V_57 , V_85 ) ;
F_4 ( & V_2 -> V_23 , L_19 , V_33 , V_53 ) ;
V_83 = V_7 -> V_20 - V_7 -> V_21 ;
if ( V_83 > 0 )
F_32 ( 24 ) ;
}
V_7 -> V_20 = 0 ;
V_7 -> V_21 = 0 ;
if ( V_7 -> V_22 == V_26 ||
V_7 -> V_22 == V_27 ) {
V_53 = F_18 ( V_2 -> V_72 ,
V_85 ) ;
F_4 ( & V_2 -> V_23 , L_15 , V_33 , V_53 ) ;
}
}
return V_81 ;
}
static int F_33 ( struct V_37 * V_38 )
{
return 8 ;
}
static int F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_86 ;
struct V_6 * V_7 ;
int V_53 ;
unsigned char * V_54 ;
int V_55 = 8 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 -> V_22 == V_28
|| V_7 -> V_22 == V_29 ) {
return - V_87 ;
}
V_54 = F_13 ( V_55 , V_18 ) ;
if ( ! V_54 )
return - V_19 ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_88 ,
V_59 | V_60 | V_61 ,
0 ,
0 ,
V_54 ,
V_55 ,
V_63 ) ;
F_4 ( & V_2 -> V_23 , L_20 ,
V_33 , V_53 , V_54 [ 0 ] ) ;
V_53 = 0 ;
if ( ( V_54 [ 0 ] & V_89 ) != 0 )
V_53 = V_90 ;
F_10 ( V_54 ) ;
return V_53 ;
}
static int F_35 ( struct V_37 * V_38 ,
unsigned int V_91 , unsigned int V_92 )
{
struct V_1 * V_2 = V_38 -> V_86 ;
struct V_52 * V_23 = & V_2 -> V_23 ;
struct V_6 * V_7 ;
int V_53 ;
int V_93 = 0 ;
int V_94 = 0 ;
unsigned char * V_54 ;
int V_55 = 8 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 -> V_22 == V_28
|| V_7 -> V_22 == V_29 ) {
return - V_87 ;
}
V_54 = F_13 ( V_55 , V_18 ) ;
if ( ! V_54 )
return - V_19 ;
if ( V_91 & V_95 )
V_94 = 1 ;
if ( V_91 & V_96 )
V_93 = 1 ;
if ( V_92 & V_95 )
V_94 = 0 ;
if ( V_92 & V_96 )
V_93 = 0 ;
if ( V_7 -> V_22 == V_26 ) {
if ( V_93 != 0 )
F_4 ( V_23 , L_21 , V_33 ) ;
else
F_4 ( V_23 , L_22 , V_33 ) ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_97 ,
V_59 | V_60 | V_66 ,
( ( V_93 != 0 ) ? V_98 : V_99 ) ,
0 ,
V_54 ,
0 ,
V_63 ) ;
} else {
if ( V_94 != 0 )
F_4 ( V_23 , L_23 , V_33 ) ;
else
F_4 ( V_23 , L_24 , V_33 ) ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_97 ,
V_59 | V_60 | V_66 ,
( ( V_94 != 0 ) ? V_100 : V_101 ) ,
0 ,
V_54 ,
0 ,
V_63 ) ;
}
F_4 ( V_23 , L_25 , V_33 , V_53 ) ;
F_10 ( V_54 ) ;
return ( V_53 < 0 ) ? V_53 : 0 ;
}
static void F_36 ( struct V_37 * V_38 ,
struct V_1 * V_2 , struct V_102 * V_103 )
{
struct V_6 * V_7 ;
int V_53 ;
unsigned short V_104 = 0 ;
int V_105 = V_38 -> V_39 . V_105 ;
T_1 V_106 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 -> V_22 == V_28 ||
V_7 -> V_22 == V_29 ) {
F_37 ( & V_38 -> V_39 , V_103 ) ;
return;
}
V_106 = F_38 ( V_38 ) ;
switch ( V_106 ) {
case 1200 :
V_104 = V_107 ;
break;
default:
V_106 = 9600 ;
case 9600 :
V_104 = V_67 ;
break;
}
V_104 |= ( V_105 & V_108 ) ? V_109 :
V_69 ;
if ( V_105 & V_110 ) {
if ( V_105 & V_111 )
V_104 |= V_112 ;
else
V_104 |= V_68 ;
} else
V_104 |= V_113 ;
V_38 -> V_39 . V_105 &= ~ V_114 ;
F_39 ( V_38 , V_106 , V_106 ) ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_65 ,
V_59 | V_60 | V_66 ,
V_104 ,
0 ,
NULL ,
0 ,
V_63
) ;
}
static int F_40 ( struct V_37 * V_38 ,
unsigned int V_115 , unsigned long V_116 )
{
struct V_1 * V_2 = V_38 -> V_86 ;
struct V_6 * V_7 = F_9 ( V_2 ) ;
unsigned char * V_54 ;
int V_55 = 8 ;
int V_53 ;
if ( V_7 -> V_22 == V_28 ||
V_7 -> V_22 == V_29 )
return - V_117 ;
switch ( V_115 ) {
case V_118 :
V_54 = F_2 ( V_55 , V_18 ) ;
if ( ! V_54 )
return - V_119 ;
V_53 = F_16 ( V_2 -> V_5 -> V_23 ,
F_17 ( V_2 -> V_5 -> V_23 , 0 ) ,
V_70 ,
V_59 | V_60 | V_66 ,
V_71 ,
0 ,
NULL ,
0 ,
V_63
) ;
F_4 ( & V_2 -> V_23 ,
L_26 , V_33 , V_53 ) ;
F_10 ( V_54 ) ;
return ( V_53 < 0 ) ? - V_120 : 0 ;
default:
return - V_117 ;
}
}
