static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = 0 ;
T_1 V_7 ;
F_3 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 & F_4 ( V_3 ) )
V_7 = V_5 -> V_10 ;
else
V_6 = V_5 -> V_11 -> V_12 ( V_5 , & V_7 ) ;
F_5 ( & V_5 -> V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ! ( V_7 & F_4 ( V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_8 ) ;
if ( V_13 )
V_5 -> V_10 |= F_4 ( V_3 ) ;
else
V_5 -> V_10 &= ~ F_4 ( V_3 ) ;
V_5 -> V_11 -> V_14 ( V_5 , V_15 , V_5 -> V_10 ) ;
F_5 ( & V_5 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
F_3 ( & V_5 -> V_8 ) ;
V_5 -> V_9 &= ~ F_4 ( V_3 ) ;
V_5 -> V_16 |= F_4 ( V_3 ) ;
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_17 , V_5 -> V_9 ) ;
if ( V_6 < 0 )
goto V_18;
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_19 , V_5 -> V_16 ) ;
V_18:
F_5 ( & V_5 -> V_8 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
F_3 ( & V_5 -> V_8 ) ;
if ( V_13 )
V_5 -> V_10 |= F_4 ( V_3 ) ;
else
V_5 -> V_10 &= ~ F_4 ( V_3 ) ;
V_5 -> V_16 &= ~ F_4 ( V_3 ) ;
V_5 -> V_9 |= F_4 ( V_3 ) ;
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_15 , V_5 -> V_10 ) ;
if ( V_6 < 0 )
goto V_18;
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_17 , V_5 -> V_9 ) ;
if ( V_6 < 0 )
goto V_18;
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_19 , V_5 -> V_16 ) ;
V_18:
F_5 ( & V_5 -> V_8 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! ( V_5 -> V_20 & F_4 ( V_3 ) ) ) {
F_10 ( V_5 -> V_21 , L_1 ,
V_3 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_20 )
return 0 ;
V_5 -> V_23 . V_24 = F_12 ( V_5 -> V_21 ) ;
V_5 -> V_23 . V_25 = - 1 ;
V_5 -> V_23 . V_26 = 8 ;
V_5 -> V_23 . V_27 = V_5 -> V_21 ;
V_5 -> V_23 . V_28 = true ;
V_5 -> V_23 . V_29 = F_7 ;
V_5 -> V_23 . V_30 = F_8 ;
V_5 -> V_23 . V_31 = F_1 ;
V_5 -> V_23 . V_32 = F_6 ;
V_5 -> V_23 . V_33 = F_9 ;
V_5 -> V_23 . V_34 = V_35 ;
F_13 ( & V_5 -> V_8 ) ;
return F_14 ( & V_5 -> V_23 , V_5 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
if ( V_5 -> V_20 )
F_16 ( & V_5 -> V_23 ) ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_36 * V_37 ;
struct V_38 * V_38 = F_18 ( V_5 ) ;
V_37 = F_19 ( V_5 -> V_21 , L_2 , V_39 ) ;
if ( F_20 ( V_37 ) )
return F_21 ( V_37 ) ;
if ( V_37 ) {
F_22 ( 1 ) ;
F_23 ( V_37 , 1 ) ;
} else {
F_3 ( & V_38 -> V_40 ) ;
V_5 -> V_11 -> V_14 ( V_5 , V_41 , 0xdac ) ;
F_5 ( & V_38 -> V_40 ) ;
}
F_22 ( 250 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_6 ;
if ( V_5 -> V_42 ) {
V_6 = F_25 ( V_5 -> V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_6 / 1000 ;
} else {
return 2500 ;
}
}
static int F_26 ( struct V_4 * V_5 )
{
const struct V_43 * V_11 = V_5 -> V_11 ;
int V_6 ;
unsigned V_44 ;
struct V_38 * V_38 = F_18 ( V_5 ) ;
T_1 V_45 = 0 , V_46 = 0 , V_47 = 0 , V_48 = 0 ;
T_2 V_49 ;
for ( V_44 = 0 ; V_44 < V_5 -> V_50 ; V_44 ++ ) {
switch ( V_5 -> V_51 [ V_44 ] ) {
case V_52 :
V_47 |= F_4 ( V_44 ) ;
break;
case V_53 :
V_48 |= F_4 ( V_44 ) ;
break;
case V_54 :
V_47 |= F_4 ( V_44 ) ;
V_48 |= F_4 ( V_44 ) ;
break;
case V_55 :
V_5 -> V_20 |= F_4 ( V_44 ) ;
V_5 -> V_16 |= F_4 ( V_44 ) ;
break;
case V_56 :
default:
switch ( V_5 -> V_57 [ V_44 ] ) {
case V_58 :
V_46 |= F_4 ( V_44 ) ;
break;
case V_59 :
V_5 -> V_9 |= F_4 ( V_44 ) ;
break;
case V_60 :
V_5 -> V_9 |= F_4 ( V_44 ) ;
V_5 -> V_10 |= F_4 ( V_44 ) ;
break;
case V_61 :
default:
V_45 |= F_4 ( V_44 ) ;
break;
}
}
}
F_3 ( & V_38 -> V_40 ) ;
V_6 = V_11 -> V_14 ( V_5 , V_62 , V_45 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_63 , V_46 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_64 , V_47 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_65 , V_48 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_15 , V_5 -> V_10 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_17 , V_5 -> V_9 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_14 ( V_5 , V_19 , V_5 -> V_16 ) ;
if ( V_6 )
goto V_18;
V_6 = V_11 -> V_66 ( V_5 , V_65 , & V_49 ) ;
if ( ! V_6 && ( V_49 & 0xff ) != V_48 )
V_6 = - V_67 ;
V_18:
F_5 ( & V_38 -> V_40 ) ;
return V_6 ;
}
static int F_27 ( struct V_4 * V_5 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_28 ( V_5 -> V_51 ) ; V_44 ++ )
V_5 -> V_51 [ V_44 ] = V_56 ;
return F_26 ( V_5 ) ;
}
static int F_29 ( struct V_38 * V_38 ,
struct V_68 const * V_69 , int V_7 , int V_70 , long V_71 )
{
struct V_4 * V_5 = F_30 ( V_38 ) ;
int V_6 ;
switch ( V_71 ) {
case V_72 :
if ( V_7 >= ( 1 << V_69 -> V_73 . V_74 ) || V_7 < 0 )
return - V_75 ;
if ( ! V_69 -> V_76 )
return - V_75 ;
F_3 ( & V_38 -> V_40 ) ;
V_6 = V_5 -> V_11 -> V_77 ( V_5 , V_69 -> V_78 , V_7 ) ;
if ( ! V_6 )
V_5 -> V_79 [ V_69 -> V_78 ] = V_7 ;
F_5 ( & V_38 -> V_40 ) ;
return V_6 ;
case V_80 :
if ( V_69 -> type == V_81 ) {
bool V_82 ;
if ( V_7 == V_5 -> V_83 [ 0 ] [ 0 ] &&
V_70 == V_5 -> V_83 [ 0 ] [ 1 ] )
V_82 = false ;
else if ( V_7 == V_5 -> V_83 [ 1 ] [ 0 ] &&
V_70 == V_5 -> V_83 [ 1 ] [ 1 ] )
V_82 = true ;
else
return - V_75 ;
F_3 ( & V_38 -> V_40 ) ;
V_6 = V_5 -> V_11 -> V_66 ( V_5 , V_84 ,
& V_5 -> V_85 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_38 -> V_40 ) ;
return V_6 ;
}
if ( V_69 -> V_76 ) {
if ( V_82 )
V_5 -> V_85 |=
V_86 ;
else
V_5 -> V_85 &=
~ V_86 ;
} else {
if ( V_82 )
V_5 -> V_85 |=
V_87 ;
else
V_5 -> V_85 &=
~ V_87 ;
}
V_6 = V_5 -> V_11 -> V_14 ( V_5 , V_84 ,
V_5 -> V_85 ) ;
F_5 ( & V_38 -> V_40 ) ;
return V_6 ;
}
break;
default:
return - V_75 ;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_38 ,
struct V_68 const * V_69 ,
int * V_7 , int * V_70 , long V_88 )
{
struct V_4 * V_5 = F_30 ( V_38 ) ;
T_2 V_89 ;
int V_6 ;
switch ( V_88 ) {
case V_72 :
F_3 ( & V_38 -> V_40 ) ;
if ( ! V_69 -> V_76 ) {
V_6 = V_5 -> V_11 -> V_90 ( V_5 , V_69 -> V_78 , & V_89 ) ;
if ( V_6 )
goto V_91;
if ( ( V_89 >> 12 & 0x7 ) != ( V_69 -> V_78 & 0x7 ) ) {
F_10 ( V_5 -> V_21 , L_3 ,
V_69 -> V_78 ) ;
V_6 = - V_67 ;
goto V_91;
}
V_89 &= F_32 ( 11 , 0 ) ;
} else {
V_89 = V_5 -> V_79 [ V_69 -> V_78 ] ;
}
F_33 ( V_5 -> V_21 , L_4 ,
V_69 -> V_78 , V_89 ) ;
* V_7 = ( int ) V_89 ;
V_6 = V_92 ;
break;
case V_80 :
* V_7 = F_24 ( V_5 ) ;
if ( V_69 -> type == V_93 ) {
T_3 V_94 = * V_7 * ( 3767897513LL / 25LL ) ;
* V_7 = F_34 ( V_94 , 1000000000LL , V_70 ) ;
V_6 = V_95 ;
} else {
int V_96 ;
F_3 ( & V_38 -> V_40 ) ;
if ( V_69 -> V_76 )
V_96 = ! ! ( V_5 -> V_85 &
V_86 ) ;
else
V_96 = ! ! ( V_5 -> V_85 &
V_87 ) ;
* V_7 *= ++ V_96 ;
* V_70 = V_69 -> V_73 . V_74 ;
V_6 = V_97 ;
}
break;
case V_98 :
V_6 = F_24 ( V_5 ) ;
F_3 ( & V_38 -> V_40 ) ;
if ( V_5 -> V_85 & V_87 )
* V_7 = ( - 34365 * 25 ) / V_6 ;
else
* V_7 = ( - 75365 * 25 ) / V_6 ;
V_6 = V_92 ;
break;
default:
V_6 = - V_75 ;
}
V_91:
F_5 ( & V_38 -> V_40 ) ;
return V_6 ;
}
static int F_35 ( struct V_38 * V_99 ,
struct V_68 const * V_69 , long V_71 )
{
switch ( V_71 ) {
case V_80 :
return V_100 ;
default:
return V_95 ;
}
return - V_75 ;
}
static T_4 F_36 ( struct V_38 * V_38 ,
T_5 V_101 ,
const struct V_68 * V_69 ,
char * V_102 )
{
struct V_4 * V_5 = F_30 ( V_38 ) ;
return sprintf ( V_102 , L_5 ,
V_5 -> V_83 [ 0 ] [ 0 ] , V_5 -> V_83 [ 0 ] [ 1 ] ,
V_5 -> V_83 [ 1 ] [ 0 ] , V_5 -> V_83 [ 1 ] [ 1 ] ) ;
}
static void F_37 ( struct V_38 * V_38 ,
struct V_68 * V_69 , bool V_76 , unsigned V_103 )
{
V_69 -> type = V_81 ;
V_69 -> V_104 = 1 ;
V_69 -> V_76 = V_76 ;
V_69 -> V_78 = V_103 ;
V_69 -> V_105 = F_4 ( V_72 ) ;
V_69 -> V_106 = F_4 ( V_80 ) ;
V_69 -> V_73 . V_107 = 'u' ;
V_69 -> V_73 . V_74 = 12 ;
V_69 -> V_73 . V_108 = 16 ;
V_69 -> V_109 = V_110 ;
}
static int F_38 ( struct V_4 * V_5 )
{
unsigned V_44 , V_111 = 0 ,
V_50 = V_5 -> V_50 ;
struct V_38 * V_38 = F_18 ( V_5 ) ;
struct V_68 * V_112 ;
struct V_113 * V_114 ;
T_6 V_42 , V_94 ;
int V_6 ;
F_39 (st->dev, child) {
V_6 = F_40 ( V_114 , L_6 , & V_42 ) ;
if ( V_6 || V_42 >= F_28 ( V_5 -> V_51 ) )
continue;
V_6 = F_40 ( V_114 , L_7 , & V_94 ) ;
if ( ! V_6 )
V_5 -> V_51 [ V_42 ] = V_94 ;
F_40 ( V_114 , L_8 , & V_94 ) ;
if ( ! V_6 )
V_5 -> V_57 [ V_42 ] = V_94 ;
}
V_112 = F_41 ( V_5 -> V_21 ,
( 1 + 2 * V_50 ) * sizeof( * V_112 ) , V_115 ) ;
if ( ! V_112 )
return - V_116 ;
for ( V_44 = 0 ; V_44 < V_50 ; V_44 ++ ) {
switch ( V_5 -> V_51 [ V_44 ] ) {
case V_52 :
F_37 ( V_38 , & V_112 [ V_111 ] ,
true , V_44 ) ;
V_111 ++ ;
break;
case V_53 :
F_37 ( V_38 , & V_112 [ V_111 ] ,
false , V_44 ) ;
V_111 ++ ;
break;
case V_54 :
F_37 ( V_38 , & V_112 [ V_111 ] ,
true , V_44 ) ;
V_111 ++ ;
F_37 ( V_38 , & V_112 [ V_111 ] ,
false , V_44 ) ;
V_111 ++ ;
break;
default:
continue;
}
}
V_112 [ V_111 ] . type = V_93 ;
V_112 [ V_111 ] . V_78 = 8 ;
V_112 [ V_111 ] . V_105 = F_4 ( V_72 ) |
F_4 ( V_80 ) |
F_4 ( V_98 ) ;
V_111 ++ ;
V_38 -> V_50 = V_111 ;
V_38 -> V_112 = V_112 ;
return 0 ;
}
static void F_42 ( struct V_4 * V_5 , int V_117 )
{
T_3 V_94 = ( T_3 ) V_117 * 1000000000LL >> 12 ;
V_5 -> V_83 [ 0 ] [ 0 ] =
F_34 ( V_94 , 1000000000LL , & V_5 -> V_83 [ 0 ] [ 1 ] ) ;
V_5 -> V_83 [ 1 ] [ 0 ] =
F_34 ( V_94 * 2 , 1000000000LL , & V_5 -> V_83 [ 1 ] [ 1 ] ) ;
}
int F_43 ( struct V_118 * V_21 , const char * V_119 ,
const struct V_43 * V_11 )
{
struct V_38 * V_38 ;
struct V_4 * V_5 ;
int V_6 ;
V_38 = F_44 ( V_21 , sizeof( * V_5 ) ) ;
if ( ! V_38 )
return - V_116 ;
V_5 = F_30 ( V_38 ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_50 = 8 ;
F_45 ( V_21 , V_38 ) ;
V_5 -> V_42 = F_46 ( V_21 , L_9 ) ;
if ( F_20 ( V_5 -> V_42 ) ) {
if ( ( F_21 ( V_5 -> V_42 ) != - V_22 ) && V_21 -> V_120 )
return F_21 ( V_5 -> V_42 ) ;
V_5 -> V_42 = NULL ;
} else {
V_6 = F_47 ( V_5 -> V_42 ) ;
if ( V_6 )
return V_6 ;
}
V_38 -> V_21 . V_27 = V_21 ;
V_38 -> V_119 = V_119 ;
V_38 -> V_121 = & V_122 ;
V_38 -> V_123 = V_124 ;
F_42 ( V_5 , F_24 ( V_5 ) ) ;
V_6 = F_17 ( V_5 ) ;
if ( V_6 )
goto V_125;
V_6 = V_11 -> V_14 ( V_5 , V_126 ,
( V_5 -> V_42 == NULL ) ? V_127 : 0 ) ;
if ( V_6 )
goto V_125;
V_6 = F_38 ( V_5 ) ;
if ( V_6 )
goto V_125;
V_6 = F_26 ( V_5 ) ;
if ( V_6 )
goto V_128;
V_6 = F_48 ( V_38 ) ;
if ( V_6 )
goto V_128;
V_6 = F_11 ( V_5 ) ;
if ( V_6 )
goto V_129;
return 0 ;
V_129:
F_49 ( V_38 ) ;
V_128:
F_27 ( V_5 ) ;
V_125:
if ( V_5 -> V_42 )
F_50 ( V_5 -> V_42 ) ;
return V_6 ;
}
int F_51 ( struct V_118 * V_21 )
{
struct V_38 * V_38 = F_52 ( V_21 ) ;
struct V_4 * V_5 = F_30 ( V_38 ) ;
F_49 ( V_38 ) ;
F_27 ( V_5 ) ;
F_15 ( V_5 ) ;
if ( V_5 -> V_42 )
F_50 ( V_5 -> V_42 ) ;
return 0 ;
}
