static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( & V_4 -> V_6 -> V_7 -> V_8 ) ;
V_4 -> V_9 = V_3 ;
if ( V_3 ) {
V_5 = F_3 ( V_4 -> V_10 ,
V_11 ,
V_12 |
V_13 , 0 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 ,
L_1 ,
V_5 ) ;
}
V_5 = F_3 ( V_4 -> V_10 , 0x225 , 0x4000 ,
V_3 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 , L_2 ,
V_5 ) ;
V_5 = F_3 ( V_4 -> V_10 , 0x226 , 0x4000 ,
V_3 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 , L_2 ,
V_5 ) ;
if ( ! V_3 ) {
V_5 = F_3 ( V_4 -> V_10 ,
V_11 ,
V_12 |
V_13 , V_4 -> V_15 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 ,
L_3 ,
V_5 ) ;
}
F_5 ( & V_4 -> V_6 -> V_7 -> V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
V_16 %= V_2 -> V_17 ;
if ( V_4 -> V_18 . V_19 > 0 )
F_7 ( V_4 -> V_18 . V_19 ,
V_2 -> V_20 [ V_16 ] . V_21 ) ;
F_3 ( V_4 -> V_10 , V_22 ,
V_23 ,
V_2 -> V_20 [ V_16 ] . V_24 <<
V_25 ) ;
F_3 ( V_4 -> V_10 , V_26 ,
V_27 , V_2 -> V_20 [ V_16 ] . V_28 ) ;
V_2 -> V_29 = V_16 ;
F_8 ( V_4 -> V_14 , L_4 , V_16 ) ;
}
static const char * F_9 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_20 [ 0 ] . V_24 ) {
case 1 :
return L_5 ;
case 2 :
return L_6 ;
case 3 :
return L_7 ;
default:
return L_8 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
const char * V_30 = F_9 ( V_2 ) ;
struct V_31 * V_6 = V_4 -> V_6 ;
int V_5 ;
V_5 = F_11 ( V_6 , V_30 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 , L_9 ,
V_30 , V_5 ) ;
F_12 ( V_6 ) ;
if ( ! V_4 -> V_18 . V_32 ) {
V_5 = F_13 ( V_4 -> V_6 , V_30 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 , L_10 ,
V_30 , V_5 ) ;
F_12 ( V_6 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
bool V_33 ;
int V_5 ;
F_15 ( V_2 -> V_14 ) ;
if ( V_2 -> V_34 ) {
V_5 = F_16 ( V_2 -> V_35 , false ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 ,
L_11 ,
V_5 ) ;
}
}
V_5 = F_18 ( V_2 -> V_35 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_12 ,
V_5 ) ;
}
if ( V_2 -> V_36 ) {
F_19 ( V_4 -> V_10 , 0x80 , 0x3 ) ;
F_19 ( V_4 -> V_10 , 0x294 , 0 ) ;
F_19 ( V_4 -> V_10 , 0x80 , 0x0 ) ;
}
F_3 ( V_4 -> V_10 ,
V_26 ,
V_37 , V_38 ) ;
F_10 ( V_2 ) ;
F_20 ( V_4 -> V_10 , V_22 ,
V_39 , V_39 ,
& V_33 ) ;
if ( ! V_33 ) {
F_21 ( V_2 -> V_35 ) ;
F_22 ( V_2 -> V_14 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
const char * V_30 = F_9 ( V_2 ) ;
struct V_31 * V_6 = V_4 -> V_6 ;
bool V_33 ;
int V_5 ;
F_20 ( V_4 -> V_10 , V_22 ,
V_39 , 0 ,
& V_33 ) ;
V_5 = F_13 ( V_6 , V_30 ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 ,
L_10 ,
V_30 , V_5 ) ;
F_12 ( V_6 ) ;
if ( V_2 -> V_36 ) {
F_19 ( V_4 -> V_10 , 0x80 , 0x3 ) ;
F_19 ( V_4 -> V_10 , 0x294 , 2 ) ;
F_19 ( V_4 -> V_10 , 0x80 , 0x0 ) ;
}
V_5 = F_16 ( V_2 -> V_35 , true ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_13 ,
V_5 ) ;
}
if ( V_33 ) {
F_21 ( V_2 -> V_35 ) ;
F_24 ( V_2 -> V_14 ) ;
F_22 ( V_2 -> V_14 ) ;
}
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_40 , V_41 ;
int V_5 ;
V_5 = F_26 ( V_4 -> V_10 , V_42 , & V_40 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_14 ,
V_5 ) ;
return V_5 ;
}
switch ( V_2 -> V_43 ) {
case 0 :
if ( ! ( V_40 & V_44 ) ) {
F_17 ( V_4 -> V_14 , L_15 ,
V_40 ) ;
return - V_45 ;
}
V_40 &= V_46 ;
break;
case 1 :
if ( ! ( V_40 & V_47 ) ) {
F_17 ( V_4 -> V_14 , L_15 ,
V_40 ) ;
return - V_45 ;
}
V_5 = F_26 ( V_4 -> V_10 , V_48 , & V_40 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_16 ,
V_5 ) ;
return - V_45 ;
}
F_26 ( V_4 -> V_10 , V_49 ,
& V_41 ) ;
V_41 = ( V_41 & V_50 )
>> V_51 ;
if ( V_41 < F_27 ( V_52 ) - 1 &&
( V_40 < 100 || V_40 >= 0x3fb ) ) {
V_41 ++ ;
F_8 ( V_4 -> V_14 , L_17 ,
V_41 ) ;
F_3 ( V_4 -> V_10 ,
V_49 ,
V_50 ,
V_41 <<
V_51 ) ;
return - V_45 ;
}
if ( V_40 < 100 || V_40 >= 0x3fb ) {
F_8 ( V_4 -> V_14 , L_18 ) ;
return V_53 ;
}
F_8 ( V_4 -> V_14 , L_19 ,
V_40 , V_41 ) ;
V_40 = V_52 [ V_41 ] . V_54
/ ( ( V_40 * 100 ) -
V_52 [ V_41 ] . V_55 ) ;
break;
default:
F_4 ( V_4 -> V_14 , L_20 ,
V_2 -> V_43 ) ;
case 2 :
if ( ! ( V_40 & V_47 ) ) {
F_17 ( V_4 -> V_14 , L_15 ,
V_40 ) ;
return - V_45 ;
}
V_40 &= V_56 ;
V_40 /= 2 ;
F_26 ( V_4 -> V_10 , V_49 ,
& V_41 ) ;
V_41 = ( V_41 & V_50 )
>> V_51 ;
if ( V_41 < F_27 ( V_57 ) - 1 &&
( V_40 >= V_57 [ V_41 ] . V_58 ) ) {
V_41 ++ ;
F_8 ( V_4 -> V_14 , L_21 ,
V_57 [ V_41 ] . V_59 ,
V_57 [ V_41 ] . V_58 ) ;
F_3 ( V_4 -> V_10 ,
V_49 ,
V_50 ,
V_41 <<
V_51 ) ;
return - V_45 ;
}
if ( V_41 && ( V_40 < V_57 [ V_41 ] . V_59 ) ) {
F_8 ( V_4 -> V_14 , L_22 ,
V_57 [ V_41 ] . V_59 ) ;
V_40 = V_57 [ V_41 ] . V_59 ;
}
}
F_8 ( V_4 -> V_14 , L_23 , V_40 ) ;
return V_40 ;
}
static int F_28 ( struct V_1 * V_2 , int * V_60 ,
bool * V_61 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_62 = V_4 -> V_18 . V_63 ;
if ( V_4 -> V_18 . V_64 ) {
V_2 -> V_65 [ V_2 -> V_66 ++ ] = * V_60 ;
if ( V_62 && V_2 -> V_66 == 1 ) {
F_8 ( V_4 -> V_14 , L_24 ) ;
F_3 ( V_4 -> V_10 ,
V_26 ,
V_37 |
V_27 ,
V_67 |
V_2 -> V_20 [ 0 ] . V_28 ) ;
F_7 ( V_62 , 1 ) ;
F_3 ( V_4 -> V_10 ,
V_49 ,
V_68 , V_68 ) ;
return - V_45 ;
}
F_8 ( V_4 -> V_14 , L_25 ,
V_2 -> V_65 [ 0 ] , V_2 -> V_65 [ 1 ] ) ;
* V_60 = V_2 -> V_65 [ 0 ] ;
if ( * V_60 >= V_53 && ! V_2 -> V_69 ) {
F_8 ( V_4 -> V_14 , L_26 ) ;
V_2 -> V_66 = 0 ;
V_2 -> V_69 = true ;
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_14 ) ;
return - V_45 ;
}
if ( ! V_62 || V_2 -> V_65 [ 1 ] > 50 ) {
F_8 ( V_4 -> V_14 , L_27 ) ;
* V_61 = true ;
V_2 -> V_34 = true ;
} else {
F_8 ( V_4 -> V_14 , L_28 ) ;
}
F_3 ( V_4 -> V_10 ,
V_26 ,
V_27 ,
V_2 -> V_20 [ 0 ] . V_28 ) ;
}
return 0 ;
}
static T_1 F_31 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_62 = V_4 -> V_18 . V_63 ;
int V_72 = V_73 ;
int V_5 , V_60 ;
bool V_61 = false ;
F_2 ( & V_2 -> V_74 ) ;
if ( ! V_2 -> V_75 ) {
F_4 ( V_4 -> V_14 , L_29 ) ;
F_5 ( & V_2 -> V_74 ) ;
return V_76 ;
}
V_5 = F_32 ( & V_2 -> V_77 , V_78 ) ;
if ( V_5 < 0 ) {
F_17 ( V_4 -> V_14 , L_30 ,
V_5 ) ;
goto V_79;
} else if ( ! V_5 ) {
F_8 ( V_4 -> V_14 , L_31 ) ;
goto V_80;
}
V_5 = F_25 ( V_2 ) ;
if ( V_5 == - V_45 )
goto V_79;
else if ( V_5 < 0 )
goto V_80;
V_60 = V_5 ;
F_3 ( V_4 -> V_10 ,
V_49 ,
V_50 | V_68 ,
0 ) ;
V_5 = F_28 ( V_2 , & V_60 , & V_61 ) ;
if ( V_5 == - V_45 )
goto V_79;
else if ( V_5 < 0 )
goto V_80;
if ( V_60 >= 5000 )
V_72 = V_81 ;
else
V_72 = V_73 ;
V_5 = F_33 ( & V_2 -> V_77 , V_72 , true ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_32 ,
V_5 ) ;
V_80:
F_3 ( V_4 -> V_10 ,
V_49 ,
V_50 | V_68 ,
0 ) ;
F_1 ( V_2 , 0 ) ;
if ( V_62 )
F_7 ( V_62 , 0 ) ;
F_3 ( V_4 -> V_10 ,
V_26 ,
V_37 , V_38 ) ;
if ( V_61 || V_2 -> V_61 )
F_14 ( V_2 ) ;
if ( V_2 -> V_75 ) {
F_22 ( V_2 -> V_14 ) ;
V_2 -> V_75 = false ;
}
V_2 -> V_82 = true ;
V_79:
F_5 ( & V_2 -> V_74 ) ;
return V_83 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( V_2 -> V_82 )
return;
F_8 ( V_4 -> V_14 , L_33 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_75 = true ;
if ( V_2 -> V_61 )
F_23 ( V_2 ) ;
F_1 ( V_2 , 0x4000 ) ;
V_5 = F_3 ( V_4 -> V_10 ,
V_26 ,
V_37 ,
V_84 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_34 , V_5 ) ;
goto V_85;
}
V_5 = F_3 ( V_4 -> V_10 , V_49 ,
V_68 , V_68 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_35 ,
V_5 ) ;
goto V_85;
}
return;
V_85:
F_3 ( V_4 -> V_10 , V_26 ,
V_37 , V_38 ) ;
V_5 = F_35 ( & V_2 -> V_77 ,
1 << V_73 ,
1 << V_73 ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_36 , V_5 ) ;
if ( V_2 -> V_61 )
F_14 ( V_2 ) ;
V_2 -> V_75 = false ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_86 = 32 ;
bool V_61 ;
int V_5 ;
F_8 ( V_4 -> V_14 , L_37 ) ;
F_36 ( V_2 -> V_14 ) ;
V_2 -> V_75 = true ;
F_1 ( V_2 , 0x4000 ) ;
V_5 = F_3 ( V_4 -> V_10 ,
V_26 ,
V_27 | V_37 ,
V_2 -> V_20 [ 0 ] . V_28 |
V_84 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_34 , V_5 ) ;
goto V_85;
}
if ( V_4 -> V_18 . V_87 ) {
V_5 = F_3 ( V_4 -> V_10 ,
V_49 ,
V_68 , V_68 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 ,
L_35 ,
V_5 ) ;
goto V_85;
}
} else {
F_28 ( V_2 , & V_86 , & V_61 ) ;
}
return;
V_85:
F_3 ( V_4 -> V_10 , V_26 ,
V_37 , V_38 ) ;
V_5 = F_35 ( & V_2 -> V_77 ,
1 << V_73 ,
1 << V_73 ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_36 , V_5 ) ;
V_2 -> V_75 = false ;
}
static void F_37 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_38 ( V_89 ,
struct V_1 ,
V_90 . V_89 ) ;
F_2 ( & V_2 -> V_74 ) ;
F_8 ( V_2 -> V_4 -> V_14 , L_38 ) ;
F_34 ( V_2 ) ;
V_2 -> V_34 = false ;
F_23 ( V_2 ) ;
F_5 ( & V_2 -> V_74 ) ;
}
static void F_39 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_38 ( V_89 ,
struct V_1 ,
V_91 . V_89 ) ;
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_40 = 0 , V_92 ;
int V_5 , V_93 , V_94 ;
F_40 ( & V_2 -> V_90 ) ;
F_2 ( & V_2 -> V_74 ) ;
V_5 = F_32 ( & V_2 -> V_77 , V_78 ) ;
if ( V_5 < 0 ) {
F_17 ( V_4 -> V_14 , L_30 ,
V_5 ) ;
F_5 ( & V_2 -> V_74 ) ;
return;
} else if ( ! V_5 ) {
F_8 ( V_4 -> V_14 , L_39 ) ;
F_5 ( & V_2 -> V_74 ) ;
return;
}
for ( V_93 = 0 ; V_93 < 10 && ! ( V_40 & V_95 ) ; V_93 ++ ) {
V_5 = F_26 ( V_4 -> V_10 , V_96 , & V_40 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 ,
L_40 , V_5 ) ;
F_5 ( & V_2 -> V_74 ) ;
return;
}
F_8 ( V_4 -> V_14 , L_41 , V_40 ) ;
if ( ! ( V_40 & V_97 ) ) {
F_4 ( V_4 -> V_14 ,
L_42 ) ;
F_5 ( & V_2 -> V_74 ) ;
return;
}
}
if ( V_93 == 10 && ! ( V_40 & V_95 ) ) {
F_17 ( V_4 -> V_14 , L_43 ) ;
F_5 ( & V_2 -> V_74 ) ;
return;
}
if ( ! ( V_40 & V_98 ) ) {
F_4 ( V_4 -> V_14 , L_44 ) ;
V_2 -> V_34 = false ;
goto V_99;
}
if ( V_2 -> V_34 && ( V_40 & V_100 ) ) {
F_34 ( V_2 ) ;
V_5 = F_35 ( & V_2 -> V_77 ,
1 << V_101 ,
1 << V_101 ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_45 ,
V_5 ) ;
V_5 = F_16 ( V_2 -> V_35 , false ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_13 ,
V_5 ) ;
}
V_2 -> V_61 = true ;
V_2 -> V_34 = false ;
goto V_99;
}
if ( V_2 -> V_34 && ( V_40 & V_102 ) ) {
if ( V_2 -> V_103 >= V_2 -> V_17 * 10 ) {
F_8 ( V_4 -> V_14 , L_46 ) ;
F_34 ( V_2 ) ;
V_2 -> V_34 = false ;
F_23 ( V_2 ) ;
} else {
V_2 -> V_29 ++ ;
if ( V_2 -> V_29 == V_2 -> V_17 )
V_2 -> V_29 = 0 ;
F_6 ( V_2 , V_2 -> V_29 ) ;
V_2 -> V_103 ++ ;
}
goto V_99;
}
if ( V_40 & V_104 ) {
if ( V_2 -> V_61 ) {
F_8 ( V_4 -> V_14 , L_47 ) ;
V_92 = V_40 & V_105 ;
V_92 >>= V_106 ;
for ( V_93 = 0 ; V_93 < V_2 -> V_107 ; V_93 ++ )
F_41 ( V_2 -> V_108 ,
V_2 -> V_109 [ V_93 ] . V_94 , 0 ) ;
F_42 ( ! V_92 ) ;
F_42 ( F_43 ( V_92 ) - 1 >= V_2 -> V_107 ) ;
if ( V_92 && F_43 ( V_92 ) - 1 < V_2 -> V_107 ) {
V_94 = V_2 -> V_109 [ F_43 ( V_92 ) - 1 ] . V_94 ;
F_41 ( V_2 -> V_108 , V_94 , 1 ) ;
F_44 ( V_2 -> V_108 ) ;
}
} else if ( V_2 -> V_34 ) {
F_8 ( V_4 -> V_14 , L_48 ) ;
V_2 -> V_34 = false ;
F_23 ( V_2 ) ;
F_34 ( V_2 ) ;
} else {
F_4 ( V_4 -> V_14 , L_49 ,
V_40 ) ;
}
} else {
F_8 ( V_4 -> V_14 , L_50 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_107 ; V_93 ++ )
F_41 ( V_2 -> V_108 ,
V_2 -> V_109 [ V_93 ] . V_94 , 0 ) ;
F_44 ( V_2 -> V_108 ) ;
F_10 ( V_2 ) ;
}
V_99:
if ( V_2 -> V_34 )
F_45 ( V_110 ,
& V_2 -> V_90 ,
F_46 ( V_2 -> V_111 ) ) ;
F_24 ( V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_74 ) ;
}
static T_1 F_47 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_112 = V_4 -> V_18 . V_113 ;
F_40 ( & V_2 -> V_91 ) ;
F_40 ( & V_2 -> V_90 ) ;
F_2 ( & V_2 -> V_74 ) ;
if ( ! V_2 -> V_34 )
V_112 = 0 ;
F_5 ( & V_2 -> V_74 ) ;
if ( V_112 )
F_45 ( V_110 ,
& V_2 -> V_91 ,
F_46 ( V_112 ) ) ;
else
F_39 ( & V_2 -> V_91 . V_89 ) ;
return V_83 ;
}
static void F_48 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_38 ( V_89 ,
struct V_1 ,
V_114 . V_89 ) ;
F_2 ( & V_2 -> V_74 ) ;
F_29 ( V_2 ) ;
F_5 ( & V_2 -> V_74 ) ;
}
static T_1 F_49 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_40 , V_115 , V_116 ;
bool V_117 , V_118 ;
int V_5 , V_93 ;
V_117 = F_40 ( & V_2 -> V_114 ) ;
V_118 = F_40 ( & V_2 -> V_90 ) ;
F_36 ( V_2 -> V_14 ) ;
F_2 ( & V_2 -> V_74 ) ;
if ( V_4 -> V_18 . V_119 ) {
V_116 = V_120 ;
V_115 = 0 ;
} else {
V_116 = V_121 ;
V_115 = V_121 ;
}
V_5 = F_26 ( V_4 -> V_10 , V_122 , & V_40 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_51 ,
V_5 ) ;
F_5 ( & V_2 -> V_74 ) ;
F_22 ( V_2 -> V_14 ) ;
return V_76 ;
}
V_40 &= V_116 ;
if ( V_40 == V_2 -> V_123 ) {
F_8 ( V_4 -> V_14 , L_52 ) ;
if ( V_117 )
F_45 ( V_110 ,
& V_2 -> V_114 ,
F_46 ( V_124 ) ) ;
if ( V_118 ) {
int V_111 = V_2 -> V_111 ;
F_45 ( V_110 ,
& V_2 -> V_90 ,
F_46 ( V_111 ) ) ;
}
goto V_79;
}
V_2 -> V_123 = V_40 ;
if ( V_2 -> V_123 == V_115 ) {
F_8 ( V_4 -> V_14 , L_53 ) ;
V_5 = F_33 ( & V_2 -> V_77 ,
V_78 , true ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_54 ,
V_5 ) ;
if ( ! V_4 -> V_18 . V_64 ) {
V_2 -> V_34 = true ;
V_2 -> V_61 = false ;
V_2 -> V_103 = 0 ;
F_14 ( V_2 ) ;
} else {
F_45 ( V_110 ,
& V_2 -> V_114 ,
F_46 ( V_124 ) ) ;
}
F_3 ( V_4 -> V_10 ,
V_125 ,
V_126 | V_127 , 0 ) ;
} else {
F_8 ( V_4 -> V_14 , L_55 ) ;
F_23 ( V_2 ) ;
V_2 -> V_66 = 0 ;
for ( V_93 = 0 ; V_93 < F_27 ( V_2 -> V_65 ) ; V_93 ++ )
V_2 -> V_65 [ V_93 ] = 0 ;
V_2 -> V_61 = false ;
V_2 -> V_82 = false ;
V_2 -> V_69 = false ;
for ( V_93 = 0 ; V_93 < V_2 -> V_107 ; V_93 ++ )
F_41 ( V_2 -> V_108 ,
V_2 -> V_109 [ V_93 ] . V_94 , 0 ) ;
F_44 ( V_2 -> V_108 ) ;
V_5 = F_35 ( & V_2 -> V_77 , 0xffffffff , 0 ) ;
if ( V_5 != 0 )
F_17 ( V_4 -> V_14 , L_56 ,
V_5 ) ;
F_3 ( V_4 -> V_10 ,
V_125 ,
V_126 | V_127 ,
V_126 | V_127 ) ;
}
if ( V_4 -> V_18 . V_111 )
V_2 -> V_111 = V_4 -> V_18 . V_111 ;
else
V_2 -> V_111 = V_128 ;
V_79:
F_19 ( V_4 -> V_10 , V_129 ,
V_130 |
V_131 |
V_132 |
V_133 ) ;
F_5 ( & V_2 -> V_74 ) ;
F_24 ( V_2 -> V_14 ) ;
F_22 ( V_2 -> V_14 ) ;
return V_83 ;
}
static void F_50 ( struct V_4 * V_4 , int V_134 ,
unsigned int V_135 )
{
int V_136 ;
unsigned int V_116 ;
V_136 = V_137 - ( V_134 / 2 ) ;
if ( ! ( V_134 % 2 ) ) {
V_116 = 0x3f00 ;
V_135 <<= 8 ;
} else {
V_116 = 0x3f ;
}
F_3 ( V_4 -> V_10 , V_136 , V_116 , V_135 ) ;
}
static int F_51 ( struct V_138 * V_139 )
{
struct V_4 * V_4 = F_52 ( V_139 -> V_14 . V_140 ) ;
struct V_141 * V_18 = & V_4 -> V_18 ;
struct V_1 * V_2 ;
unsigned int V_40 ;
int V_142 , V_143 ;
int V_5 , V_16 , V_93 , V_144 ;
if ( ! V_4 -> V_6 || ! V_4 -> V_6 -> V_7 )
return - V_145 ;
V_2 = F_53 ( & V_139 -> V_14 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 ) {
F_17 ( & V_139 -> V_14 , L_57 ) ;
V_5 = - V_147 ;
goto V_85;
}
V_2 -> V_35 = F_54 ( V_4 -> V_14 , L_8 ) ;
if ( F_55 ( V_2 -> V_35 ) ) {
V_5 = F_56 ( V_2 -> V_35 ) ;
F_17 ( V_4 -> V_14 , L_58 , V_5 ) ;
goto V_85;
}
F_57 ( & V_2 -> V_74 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = & V_139 -> V_14 ;
V_2 -> V_123 = ~ ( V_120 | V_121 ) ;
F_58 ( & V_2 -> V_114 , F_48 ) ;
F_58 ( & V_2 -> V_91 , F_39 ) ;
F_58 ( & V_2 -> V_90 , F_37 ) ;
F_59 ( V_139 , V_2 ) ;
switch ( V_4 -> type ) {
case V_148 :
switch ( V_4 -> V_149 ) {
case 0 :
V_2 -> V_36 = true ;
break;
default:
V_2 -> V_150 = true ;
V_2 -> V_43 = 1 ;
break;
}
break;
case V_151 :
switch ( V_4 -> V_149 ) {
case 0 ... 2 :
break;
default:
V_2 -> V_150 = true ;
V_2 -> V_43 = 2 ;
break;
}
break;
default:
break;
}
V_2 -> V_77 . V_152 = L_59 ;
V_2 -> V_77 . V_14 . V_140 = V_4 -> V_14 ;
V_2 -> V_77 . V_153 = V_154 ;
V_5 = F_60 ( & V_2 -> V_77 ) ;
if ( V_5 < 0 ) {
F_17 ( V_4 -> V_14 , L_60 ,
V_5 ) ;
goto V_85;
}
V_2 -> V_108 = F_61 ( & V_139 -> V_14 ) ;
if ( ! V_2 -> V_108 ) {
F_17 ( V_4 -> V_14 , L_61 ) ;
V_5 = - V_147 ;
goto V_155;
}
V_2 -> V_108 -> V_152 = L_62 ;
V_2 -> V_108 -> V_156 = L_63 ;
V_2 -> V_108 -> V_14 . V_140 = & V_139 -> V_14 ;
if ( V_18 -> V_157 ) {
V_2 -> V_20 = V_18 -> V_158 ;
V_2 -> V_17 = V_18 -> V_157 ;
} else {
V_2 -> V_20 = V_159 ;
V_2 -> V_17 = F_27 ( V_159 ) ;
}
if ( V_4 -> V_18 . V_19 > 0 ) {
if ( V_2 -> V_20 [ 0 ] . V_21 )
V_16 = V_160 ;
else
V_16 = V_161 ;
V_5 = F_62 ( & V_139 -> V_14 ,
V_4 -> V_18 . V_19 ,
V_16 ,
L_64 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_65 ,
V_4 -> V_18 . V_19 , V_5 ) ;
goto V_155;
}
}
if ( V_4 -> V_18 . V_63 > 0 ) {
V_5 = F_62 ( & V_139 -> V_14 ,
V_4 -> V_18 . V_63 ,
V_161 ,
L_66 ) ;
if ( V_5 != 0 ) {
F_17 ( V_4 -> V_14 , L_65 ,
V_4 -> V_18 . V_63 , V_5 ) ;
goto V_155;
}
}
if ( V_4 -> V_18 . V_162 )
F_3 ( V_4 -> V_10 , V_22 ,
V_163 ,
V_4 -> V_18 . V_162
<< V_164 ) ;
if ( V_4 -> V_18 . V_165 )
F_3 ( V_4 -> V_10 , V_22 ,
V_166 ,
V_4 -> V_18 . V_165
<< V_167 ) ;
if ( V_4 -> V_18 . V_168 )
F_3 ( V_4 -> V_10 , V_22 ,
V_169 ,
V_4 -> V_18 . V_168
<< V_170 ) ;
F_63 ( F_27 ( V_171 ) != 0x40 ) ;
if ( V_4 -> V_18 . V_107 ) {
V_2 -> V_109 = V_18 -> V_109 ;
V_2 -> V_107 = V_18 -> V_107 ;
} else {
V_2 -> V_109 = V_172 ;
V_2 -> V_107 = F_27 ( V_172 ) ;
}
if ( V_4 -> V_18 . V_107 > V_173 ) {
F_17 ( V_4 -> V_14 , L_67 ,
V_4 -> V_18 . V_107 ) ;
}
if ( V_2 -> V_107 > 1 ) {
for ( V_93 = 1 ; V_93 < V_2 -> V_107 ; V_93 ++ ) {
if ( V_2 -> V_109 [ V_93 - 1 ] . V_58 >
V_2 -> V_109 [ V_93 ] . V_58 ) {
F_17 ( V_4 -> V_14 ,
L_68 ) ;
V_5 = - V_174 ;
goto V_175;
}
}
}
F_3 ( V_4 -> V_10 , V_176 ,
V_177 , 0x81 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_107 ; V_93 ++ ) {
for ( V_144 = 0 ; V_144 < F_27 ( V_171 ) ; V_144 ++ )
if ( V_171 [ V_144 ] >= V_2 -> V_109 [ V_93 ] . V_58 )
break;
if ( V_144 == F_27 ( V_171 ) ) {
F_17 ( V_4 -> V_14 , L_69 ,
V_2 -> V_109 [ V_93 ] . V_58 ) ;
V_5 = - V_174 ;
goto V_175;
}
F_8 ( V_4 -> V_14 , L_70 ,
V_171 [ V_144 ] , V_93 ) ;
F_50 ( V_4 , V_93 , V_144 ) ;
F_64 ( V_2 -> V_108 , V_178 ,
V_2 -> V_109 [ V_93 ] . V_94 ) ;
F_3 ( V_4 -> V_10 , V_176 ,
1 << V_93 , 1 << V_93 ) ;
}
for (; V_93 < V_173 ; V_93 ++ )
F_50 ( V_4 , V_93 , 0x3f ) ;
if ( V_2 -> V_150 ) {
if ( V_4 -> V_18 . V_119 ) {
V_40 = 0xc101 ;
if ( V_4 -> V_18 . V_179 )
V_40 &= ~ V_180 ;
F_19 ( V_4 -> V_10 , V_181 ,
V_40 ) ;
F_3 ( V_4 -> V_10 ,
V_182 ,
V_183 , 0x9 ) ;
} else {
F_3 ( V_4 -> V_10 ,
V_182 ,
V_183 , 0x4 ) ;
}
F_3 ( V_4 -> V_10 ,
V_125 ,
V_126 ,
V_126 ) ;
}
F_6 ( V_2 , 0 ) ;
F_65 ( & V_139 -> V_14 ) ;
F_66 ( & V_139 -> V_14 ) ;
F_36 ( & V_139 -> V_14 ) ;
if ( V_4 -> V_18 . V_119 ) {
V_143 = V_184 ;
V_142 = V_185 ;
} else {
V_143 = V_186 ;
V_142 = V_187 ;
}
V_5 = F_67 ( V_4 , V_143 ,
L_71 , F_49 , V_2 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_72 ,
V_5 ) ;
goto V_175;
}
V_5 = F_68 ( V_4 , V_143 , 1 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_73 ,
V_5 ) ;
goto V_188;
}
V_5 = F_67 ( V_4 , V_142 ,
L_74 , F_49 , V_2 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_75 , V_5 ) ;
goto V_189;
}
V_5 = F_68 ( V_4 , V_142 , 1 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_76 ,
V_5 ) ;
goto V_190;
}
V_5 = F_67 ( V_4 , V_191 ,
L_77 , F_47 , V_2 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_78 , V_5 ) ;
goto V_192;
}
V_5 = F_67 ( V_4 , V_193 ,
L_66 , F_31 , V_2 ) ;
if ( V_5 != 0 ) {
F_17 ( & V_139 -> V_14 , L_79 , V_5 ) ;
goto V_194;
}
F_69 ( V_4 ) ;
F_3 ( V_4 -> V_10 , V_125 ,
V_127 , V_127 ) ;
F_3 ( V_4 -> V_10 , V_195 ,
V_196 , V_196 ) ;
V_5 = F_16 ( V_2 -> V_35 , true ) ;
if ( V_5 != 0 )
F_4 ( V_4 -> V_14 , L_80 ,
V_5 ) ;
F_30 ( & V_139 -> V_14 ) ;
V_5 = F_70 ( V_2 -> V_108 ) ;
if ( V_5 ) {
F_17 ( & V_139 -> V_14 , L_81 , V_5 ) ;
goto V_197;
}
return 0 ;
V_197:
F_71 ( V_4 , V_193 , V_2 ) ;
V_194:
F_71 ( V_4 , V_191 , V_2 ) ;
V_192:
F_68 ( V_4 , V_142 , 0 ) ;
V_190:
F_71 ( V_4 , V_142 , V_2 ) ;
V_189:
F_68 ( V_4 , V_143 , 0 ) ;
V_188:
F_71 ( V_4 , V_143 , V_2 ) ;
V_175:
V_155:
F_72 ( & V_139 -> V_14 ) ;
F_73 ( & V_2 -> V_77 ) ;
V_85:
return V_5 ;
}
static int F_74 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_75 ( V_139 ) ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_143 , V_142 ;
F_72 ( & V_139 -> V_14 ) ;
F_3 ( V_4 -> V_10 ,
V_182 ,
V_183 , 0 ) ;
if ( V_4 -> V_18 . V_119 ) {
V_143 = V_184 ;
V_142 = V_185 ;
} else {
V_143 = V_186 ;
V_142 = V_187 ;
}
F_68 ( V_4 , V_143 , 0 ) ;
F_68 ( V_4 , V_142 , 0 ) ;
F_71 ( V_4 , V_193 , V_2 ) ;
F_71 ( V_4 , V_191 , V_2 ) ;
F_71 ( V_4 , V_143 , V_2 ) ;
F_71 ( V_4 , V_142 , V_2 ) ;
F_40 ( & V_2 -> V_114 ) ;
F_3 ( V_4 -> V_10 , V_195 ,
V_196 , 0 ) ;
F_76 ( V_4 ) ;
F_73 ( & V_2 -> V_77 ) ;
return 0 ;
}
