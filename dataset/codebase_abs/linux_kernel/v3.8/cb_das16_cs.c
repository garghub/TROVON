static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
int V_14 = F_3 ( V_9 -> V_15 ) ;
int V_16 = F_4 ( V_9 -> V_15 ) ;
int V_17 = F_5 ( V_9 -> V_15 ) ;
int V_18 ;
int V_19 ;
F_6 ( V_14 , V_5 -> V_20 + V_21 ) ;
V_12 -> V_22 &= ~ 0xf320 ;
V_12 -> V_22 |= ( V_17 == V_23 ) ? 0 : 0x0020 ;
F_6 ( V_12 -> V_22 , V_5 -> V_20 + V_24 ) ;
V_12 -> V_25 &= ~ 0xff00 ;
switch ( V_16 ) {
case 0 :
V_12 -> V_25 |= 0x800 ;
break;
case 1 :
V_12 -> V_25 |= 0x000 ;
break;
case 2 :
V_12 -> V_25 |= 0x100 ;
break;
case 3 :
V_12 -> V_25 |= 0x200 ;
break;
}
F_6 ( V_12 -> V_25 , V_5 -> V_20 + V_26 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_27 ; V_18 ++ ) {
F_6 ( 0 , V_5 -> V_20 + V_28 ) ;
#define F_7 1000
for ( V_19 = 0 ; V_19 < F_7 ; V_19 ++ ) {
if ( F_8 ( V_5 -> V_20 + V_24 ) & 0x0080 )
break;
}
if ( V_19 == F_7 ) {
F_9 ( V_5 -> V_29 , L_1 ) ;
return - V_30 ;
}
V_10 [ V_18 ] = F_8 ( V_5 -> V_20 + V_28 ) ;
}
return V_18 ;
}
static int F_10 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
return - V_31 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_32 * V_33 )
{
int V_34 = 0 ;
int V_35 ;
V_34 |= F_12 ( & V_33 -> V_36 , V_37 ) ;
V_34 |= F_12 ( & V_33 -> V_38 ,
V_39 | V_40 ) ;
V_34 |= F_12 ( & V_33 -> V_41 ,
V_39 | V_40 ) ;
V_34 |= F_12 ( & V_33 -> V_42 , V_43 ) ;
V_34 |= F_12 ( & V_33 -> V_44 , V_43 | V_45 ) ;
if ( V_34 )
return 1 ;
V_34 |= F_13 ( V_33 -> V_38 ) ;
V_34 |= F_13 ( V_33 -> V_41 ) ;
V_34 |= F_13 ( V_33 -> V_44 ) ;
if ( V_34 )
return 2 ;
V_34 |= F_14 ( & V_33 -> V_46 , 0 ) ;
#define F_15 10000
#define F_16 1000000000
if ( V_33 -> V_38 == V_39 ) {
V_34 |= F_17 ( & V_33 -> V_47 ,
F_15 ) ;
V_34 |= F_18 ( & V_33 -> V_47 ,
F_16 ) ;
} else {
V_34 |= F_18 ( & V_33 -> V_47 , 9 ) ;
}
if ( V_33 -> V_41 == V_39 ) {
V_34 |= F_17 ( & V_33 -> V_48 ,
F_15 ) ;
V_34 |= F_18 ( & V_33 -> V_48 ,
F_16 ) ;
} else {
V_34 |= F_18 ( & V_33 -> V_48 , 9 ) ;
}
V_34 |= F_14 ( & V_33 -> V_49 , V_33 -> V_50 ) ;
if ( V_33 -> V_44 == V_43 )
V_34 |= F_18 ( & V_33 -> V_51 , 0x00ffffff ) ;
else
V_34 |= F_14 ( & V_33 -> V_51 , 0 ) ;
if ( V_34 )
return 3 ;
if ( V_33 -> V_38 == V_39 ) {
unsigned int V_52 = 0 , V_53 = 0 ;
V_35 = V_33 -> V_47 ;
F_19 ( 100 , & V_52 , & V_53 ,
& V_33 -> V_47 ,
V_33 -> V_54 & V_55 ) ;
if ( V_35 != V_33 -> V_47 )
V_34 ++ ;
}
if ( V_33 -> V_41 == V_39 ) {
unsigned int V_52 = 0 , V_53 = 0 ;
V_35 = V_33 -> V_48 ;
F_19 ( 100 , & V_52 , & V_53 ,
& V_33 -> V_47 ,
V_33 -> V_54 & V_55 ) ;
if ( V_35 != V_33 -> V_48 )
V_34 ++ ;
if ( V_33 -> V_38 == V_39 &&
V_33 -> V_47 <
V_33 -> V_48 * V_33 -> V_49 ) {
V_33 -> V_47 =
V_33 -> V_48 * V_33 -> V_49 ;
V_34 ++ ;
}
}
if ( V_34 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
int V_18 ;
int V_14 = F_3 ( V_9 -> V_15 ) ;
unsigned short V_22 ;
unsigned short V_2 ;
int V_56 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_27 ; V_18 ++ ) {
V_12 -> V_57 [ V_14 ] = V_10 [ V_18 ] ;
V_2 = V_10 [ V_18 ] ;
F_6 ( V_12 -> V_22 , V_5 -> V_20 + V_24 ) ;
F_21 ( 1 ) ;
V_22 = V_12 -> V_22 & ~ 0xf ;
if ( V_14 )
V_22 |= 0x0001 ;
else
V_22 |= 0x0008 ;
F_6 ( V_22 , V_5 -> V_20 + V_24 ) ;
F_21 ( 1 ) ;
for ( V_56 = 15 ; V_56 >= 0 ; V_56 -- ) {
int V_58 = ( V_2 >> V_56 ) & 0x1 ;
V_58 <<= 1 ;
F_6 ( V_22 | V_58 | 0x0000 , V_5 -> V_20 + V_24 ) ;
F_21 ( 1 ) ;
F_6 ( V_22 | V_58 | 0x0004 , V_5 -> V_20 + V_24 ) ;
F_21 ( 1 ) ;
}
F_6 ( V_22 | 0x9 , V_5 -> V_20 + V_24 ) ;
}
return V_18 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
int V_18 ;
int V_14 = F_3 ( V_9 -> V_15 ) ;
for ( V_18 = 0 ; V_18 < V_9 -> V_27 ; V_18 ++ )
V_10 [ V_18 ] = V_12 -> V_57 [ V_14 ] ;
return V_18 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
if ( V_10 [ 0 ] ) {
V_7 -> V_59 &= ~ V_10 [ 0 ] ;
V_7 -> V_59 |= V_10 [ 0 ] & V_10 [ 1 ] ;
F_6 ( V_7 -> V_59 , V_5 -> V_20 + V_60 ) ;
}
V_10 [ 1 ] = F_8 ( V_5 -> V_20 + V_60 ) ;
return V_9 -> V_27 ;
}
static int F_24 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 , unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
int V_14 = F_3 ( V_9 -> V_15 ) ;
int V_61 ;
if ( V_14 < 4 )
V_61 = 0x0f ;
else
V_61 = 0xf0 ;
switch ( V_10 [ 0 ] ) {
case V_62 :
V_7 -> V_63 |= V_61 ;
break;
case V_64 :
V_7 -> V_63 &= V_61 ;
break;
case V_65 :
V_10 [ 1 ] =
( V_7 -> V_63 & ( 1 << V_14 ) ) ? V_66 : V_67 ;
return V_9 -> V_27 ;
break;
default:
return - V_31 ;
break;
}
V_12 -> V_25 &= ~ 0x00c0 ;
V_12 -> V_25 |= ( V_7 -> V_63 & 0xf0 ) ? 0x0080 : 0 ;
V_12 -> V_25 |= ( V_7 -> V_63 & 0x0f ) ? 0x0040 : 0 ;
F_6 ( V_12 -> V_25 , V_5 -> V_20 + V_26 ) ;
return V_9 -> V_27 ;
}
static const struct V_68 * F_25 ( struct V_4 * V_5 ,
struct V_69 * V_70 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_26 ( V_71 ) ; V_18 ++ ) {
if ( V_71 [ V_18 ] . V_72 == V_70 -> V_73 )
return V_71 + V_18 ;
}
F_9 ( V_5 -> V_29 , L_2 ) ;
return NULL ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_74 * V_75 )
{
const struct V_68 * V_76 ;
struct V_11 * V_12 ;
struct V_69 * V_70 ;
struct V_6 * V_7 ;
int V_77 ;
V_70 = V_78 ;
if ( ! V_70 )
return - V_79 ;
V_5 -> V_80 = F_25 ( V_5 , V_70 ) ;
if ( ! V_5 -> V_80 )
return - V_79 ;
V_76 = F_28 ( V_5 ) ;
V_5 -> V_81 = V_76 -> V_82 ;
V_5 -> V_20 = V_70 -> V_83 [ 0 ] -> V_84 ;
V_77 = F_29 ( V_70 -> V_1 , F_1 ,
V_85 , L_3 , V_5 ) ;
if ( V_77 < 0 )
return V_77 ;
V_5 -> V_1 = V_70 -> V_1 ;
V_12 = F_30 ( sizeof( * V_12 ) , V_86 ) ;
if ( ! V_12 )
return - V_87 ;
V_5 -> V_13 = V_12 ;
V_77 = F_31 ( V_5 , 3 ) ;
if ( V_77 )
return V_77 ;
V_7 = & V_5 -> V_88 [ 0 ] ;
V_5 -> V_89 = V_7 ;
V_7 -> type = V_90 ;
V_7 -> V_91 = V_92 | V_93 | V_94 | V_95 ;
V_7 -> V_96 = 16 ;
V_7 -> V_97 = 0xffff ;
V_7 -> V_98 = & V_99 ;
V_7 -> V_100 = 16 ;
V_7 -> V_101 = F_2 ;
V_7 -> V_102 = F_10 ;
V_7 -> V_103 = F_11 ;
V_7 = & V_5 -> V_88 [ 1 ] ;
if ( V_76 -> V_104 ) {
V_7 -> type = V_105 ;
V_7 -> V_91 = V_106 ;
V_7 -> V_96 = V_76 -> V_104 ;
V_7 -> V_97 = 0xffff ;
V_7 -> V_98 = & V_107 ;
V_7 -> V_108 = & F_20 ;
V_7 -> V_101 = & F_22 ;
} else {
V_7 -> type = V_109 ;
}
V_7 = & V_5 -> V_88 [ 2 ] ;
V_7 -> type = V_110 ;
V_7 -> V_91 = V_92 | V_106 ;
V_7 -> V_96 = 8 ;
V_7 -> V_97 = 1 ;
V_7 -> V_98 = & V_111 ;
V_7 -> V_112 = F_23 ;
V_7 -> V_113 = F_24 ;
F_32 ( V_5 -> V_29 , L_4 ,
V_5 -> V_114 -> V_115 , V_5 -> V_81 ,
V_5 -> V_20 , V_5 -> V_1 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1 )
F_34 ( V_5 -> V_1 , V_5 ) ;
}
static int F_35 ( struct V_69 * V_116 ,
void * V_117 )
{
if ( V_116 -> V_118 == 0 )
return - V_31 ;
return F_36 ( V_116 ) ;
}
static int F_37 ( struct V_69 * V_70 )
{
int V_77 ;
V_70 -> V_119 |= V_120 | V_121 ;
V_77 = F_38 ( V_70 , F_35 , NULL ) ;
if ( V_77 )
goto V_122;
if ( ! V_70 -> V_1 )
goto V_122;
V_77 = F_39 ( V_70 ) ;
if ( V_77 )
goto V_122;
V_78 = V_70 ;
return 0 ;
V_122:
F_40 ( V_70 ) ;
return V_77 ;
}
static void F_41 ( struct V_69 * V_70 )
{
F_40 ( V_70 ) ;
V_78 = NULL ;
}
static int T_2 F_42 ( void )
{
int V_77 ;
V_77 = F_43 ( & V_123 ) ;
if ( V_77 < 0 )
return V_77 ;
V_77 = F_44 ( & V_124 ) ;
if ( V_77 < 0 ) {
F_45 ( & V_123 ) ;
return V_77 ;
}
return 0 ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_124 ) ;
F_45 ( & V_123 ) ;
}
