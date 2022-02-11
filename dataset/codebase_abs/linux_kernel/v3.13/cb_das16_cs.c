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
F_19 ( V_54 ,
& V_52 , & V_53 ,
& V_33 -> V_47 , V_33 -> V_55 ) ;
if ( V_35 != V_33 -> V_47 )
V_34 ++ ;
}
if ( V_33 -> V_41 == V_39 ) {
unsigned int V_52 = 0 , V_53 = 0 ;
V_35 = V_33 -> V_48 ;
F_19 ( V_54 ,
& V_52 , & V_53 ,
& V_33 -> V_47 , V_33 -> V_55 ) ;
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
struct V_8 * V_9 ,
unsigned int * V_10 )
{
if ( F_24 ( V_7 , V_10 ) )
F_6 ( V_7 -> V_59 , V_5 -> V_20 + V_60 ) ;
V_10 [ 1 ] = F_8 ( V_5 -> V_20 + V_60 ) ;
return V_9 -> V_27 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
unsigned int V_14 = F_3 ( V_9 -> V_15 ) ;
unsigned int V_61 ;
int V_62 ;
if ( V_14 < 4 )
V_61 = 0x0f ;
else
V_61 = 0xf0 ;
V_62 = F_26 ( V_5 , V_7 , V_9 , V_10 , V_61 ) ;
if ( V_62 )
return V_62 ;
V_12 -> V_25 &= ~ 0x00c0 ;
V_12 -> V_25 |= ( V_7 -> V_63 & 0xf0 ) ? 0x0080 : 0 ;
V_12 -> V_25 |= ( V_7 -> V_63 & 0x0f ) ? 0x0040 : 0 ;
F_6 ( V_12 -> V_25 , V_5 -> V_20 + V_26 ) ;
return V_9 -> V_27 ;
}
static const void * F_27 ( struct V_4 * V_5 ,
struct V_64 * V_65 )
{
const struct V_66 * V_67 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_28 ( V_68 ) ; V_18 ++ ) {
V_67 = & V_68 [ V_18 ] ;
if ( V_67 -> V_69 == V_65 -> V_70 )
return V_67 ;
}
return NULL ;
}
static int F_29 ( struct V_4 * V_5 ,
unsigned long V_71 )
{
struct V_64 * V_65 = F_30 ( V_5 ) ;
const struct V_66 * V_67 ;
struct V_11 * V_12 ;
struct V_6 * V_7 ;
int V_62 ;
V_67 = F_27 ( V_5 , V_65 ) ;
if ( ! V_67 )
return - V_72 ;
V_5 -> V_73 = V_67 ;
V_5 -> V_74 = V_67 -> V_75 ;
V_65 -> V_76 |= V_77 | V_78 ;
V_62 = F_31 ( V_5 , NULL ) ;
if ( V_62 )
return V_62 ;
V_5 -> V_20 = V_65 -> V_79 [ 0 ] -> V_80 ;
V_65 -> V_81 = V_5 ;
V_62 = F_32 ( V_65 , F_1 ) ;
if ( V_62 )
return V_62 ;
V_5 -> V_1 = V_65 -> V_1 ;
V_12 = F_33 ( V_5 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
return - V_82 ;
V_62 = F_34 ( V_5 , 3 ) ;
if ( V_62 )
return V_62 ;
V_7 = & V_5 -> V_83 [ 0 ] ;
V_5 -> V_84 = V_7 ;
V_7 -> type = V_85 ;
V_7 -> V_86 = V_87 | V_88 | V_89 | V_90 ;
V_7 -> V_91 = 16 ;
V_7 -> V_92 = 0xffff ;
V_7 -> V_93 = & V_94 ;
V_7 -> V_95 = 16 ;
V_7 -> V_96 = F_2 ;
V_7 -> V_97 = F_10 ;
V_7 -> V_98 = F_11 ;
V_7 = & V_5 -> V_83 [ 1 ] ;
if ( V_67 -> V_99 ) {
V_7 -> type = V_100 ;
V_7 -> V_86 = V_101 ;
V_7 -> V_91 = V_67 -> V_99 ;
V_7 -> V_92 = 0xffff ;
V_7 -> V_93 = & V_102 ;
V_7 -> V_103 = & F_20 ;
V_7 -> V_96 = & F_22 ;
} else {
V_7 -> type = V_104 ;
}
V_7 = & V_5 -> V_83 [ 2 ] ;
V_7 -> type = V_105 ;
V_7 -> V_86 = V_87 | V_101 ;
V_7 -> V_91 = 8 ;
V_7 -> V_92 = 1 ;
V_7 -> V_93 = & V_106 ;
V_7 -> V_107 = F_23 ;
V_7 -> V_108 = F_25 ;
F_35 ( V_5 -> V_29 , L_2 ,
V_5 -> V_109 -> V_110 , V_5 -> V_74 ,
V_5 -> V_20 , V_5 -> V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_64 * V_65 )
{
return F_37 ( V_65 , & V_111 ) ;
}
