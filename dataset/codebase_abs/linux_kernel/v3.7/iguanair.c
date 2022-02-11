static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= 4 && V_2 -> V_4 [ 0 ] == 0 && V_2 -> V_4 [ 1 ] == 0 ) {
switch ( V_2 -> V_4 [ 3 ] ) {
case V_5 :
if ( V_3 == 6 ) {
V_2 -> V_6 = ( V_2 -> V_4 [ 5 ] << 8 ) |
V_2 -> V_4 [ 4 ] ;
F_2 ( & V_2 -> V_7 ) ;
}
break;
case V_8 :
if ( V_3 >= 5 ) {
V_2 -> V_9 = V_2 -> V_4 [ 4 ] ;
F_2 ( & V_2 -> V_7 ) ;
}
break;
case V_10 :
if ( V_3 > 5 ) {
V_2 -> V_11 = V_2 -> V_4 [ 5 ] ;
F_2 ( & V_2 -> V_7 ) ;
}
break;
case V_12 :
V_2 -> V_13 = true ;
case V_14 :
case V_15 :
case V_16 :
F_2 ( & V_2 -> V_7 ) ;
break;
case V_17 :
F_3 ( V_2 -> V_18 , L_1 ) ;
F_4 ( V_2 -> V_19 ) ;
break;
default:
F_3 ( V_2 -> V_18 , L_2 ,
V_2 -> V_4 [ 3 ] ) ;
break;
}
} else if ( V_3 >= 7 ) {
F_5 ( V_20 ) ;
unsigned V_21 ;
bool V_22 = false ;
F_6 ( & V_20 ) ;
for ( V_21 = 0 ; V_21 < 7 ; V_21 ++ ) {
if ( V_2 -> V_4 [ V_21 ] == 0x80 ) {
V_20 . V_23 = false ;
V_20 . V_24 = F_7 ( 21845 ) ;
} else {
V_20 . V_23 = ( V_2 -> V_4 [ V_21 ] & 0x80 ) == 0 ;
V_20 . V_24 = ( ( V_2 -> V_4 [ V_21 ] & 0x7f ) + 1 ) *
V_25 ;
}
if ( F_8 ( V_2 -> V_19 , & V_20 ) )
V_22 = true ;
}
if ( V_22 )
F_9 ( V_2 -> V_19 ) ;
}
}
static void F_10 ( struct V_26 * V_26 )
{
struct V_1 * V_2 ;
int V_19 ;
if ( ! V_26 )
return;
V_2 = V_26 -> V_27 ;
if ( ! V_2 ) {
F_11 ( V_26 ) ;
return;
}
switch ( V_26 -> V_28 ) {
case 0 :
F_1 ( V_2 , V_26 -> V_29 ) ;
break;
case - V_30 :
case - V_31 :
case - V_32 :
F_11 ( V_26 ) ;
return;
case - V_33 :
default:
F_12 ( V_2 -> V_18 , L_3 , V_26 -> V_28 ) ;
break;
}
V_19 = F_13 ( V_26 , V_34 ) ;
if ( V_19 && V_19 != - V_35 )
F_3 ( V_2 -> V_18 , L_4 , V_19 ) ;
}
static void F_14 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
if ( V_26 -> V_28 )
F_12 ( V_2 -> V_18 , L_5 , V_26 -> V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_36 )
{
int V_19 ;
F_16 ( V_2 -> V_7 ) ;
V_2 -> V_37 -> V_38 = V_36 ;
V_19 = F_13 ( V_2 -> V_37 , V_39 ) ;
if ( V_19 )
return V_19 ;
if ( F_17 ( & V_2 -> V_7 , V_40 ) == 0 )
return - V_41 ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_42 -> V_43 . V_44 = 0 ;
V_2 -> V_42 -> V_43 . V_45 = V_46 ;
V_2 -> V_42 -> V_43 . V_47 = V_5 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_42 -> V_43 ) ) ;
if ( V_19 ) {
F_19 ( V_2 -> V_18 , L_6 ) ;
goto V_48;
}
if ( V_2 -> V_6 < 0x205 ) {
F_20 ( V_2 -> V_18 , L_7 , V_2 -> V_6 ) ;
V_19 = - V_35 ;
goto V_48;
}
V_2 -> V_9 = 150 ;
V_2 -> V_11 = 65 ;
V_2 -> V_42 -> V_43 . V_47 = V_8 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_42 -> V_43 ) ) ;
if ( V_19 ) {
F_19 ( V_2 -> V_18 , L_8 ) ;
goto V_48;
}
if ( V_2 -> V_9 > V_49 ) {
F_19 ( V_2 -> V_18 , L_9 ,
V_2 -> V_9 ) ;
V_2 -> V_9 = V_49 ;
}
V_2 -> V_42 -> V_43 . V_47 = V_10 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_42 -> V_43 ) ) ;
if ( V_19 ) {
F_19 ( V_2 -> V_18 , L_10 ) ;
goto V_48;
}
V_48:
return V_19 ;
}
static int F_21 ( struct V_1 * V_2 , bool V_50 )
{
int V_19 ;
V_2 -> V_42 -> V_43 . V_44 = 0 ;
V_2 -> V_42 -> V_43 . V_45 = V_46 ;
V_2 -> V_42 -> V_43 . V_47 = V_50 ? V_15 : V_14 ;
if ( V_50 )
F_4 ( V_2 -> V_19 ) ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_42 -> V_43 ) ) ;
return V_19 ;
}
static int F_22 ( struct V_51 * V_18 , T_1 V_52 )
{
struct V_1 * V_2 = V_18 -> V_53 ;
if ( V_52 < 25000 || V_52 > 150000 )
return - V_54 ;
F_23 ( & V_2 -> V_55 ) ;
if ( V_52 != V_2 -> V_52 ) {
T_1 V_56 , V_57 , V_58 ;
V_2 -> V_52 = V_52 ;
V_56 = F_24 ( 24000000 , V_52 * 2 ) -
V_2 -> V_11 ;
switch ( V_56 & 3 ) {
case 0 :
V_58 = 0 ;
break;
case 1 :
V_58 = 3 ;
break;
case 2 :
V_58 = 2 ;
break;
case 3 :
V_58 = 1 ;
break;
}
V_57 = ( V_56 - V_58 * 7 ) / 4 ;
V_2 -> V_42 -> V_59 = ( 4 - V_58 ) * 2 ;
V_2 -> V_42 -> V_60 = 110 - V_57 ;
}
F_25 ( & V_2 -> V_55 ) ;
return V_52 ;
}
static int F_26 ( struct V_51 * V_18 , T_1 V_61 )
{
struct V_1 * V_2 = V_18 -> V_53 ;
if ( V_61 > 15 )
return 4 ;
F_23 ( & V_2 -> V_55 ) ;
V_2 -> V_42 -> V_62 = V_61 << 4 ;
F_25 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_18 , unsigned * V_63 , unsigned V_64 )
{
struct V_1 * V_2 = V_18 -> V_53 ;
T_2 V_65 ;
unsigned V_21 , V_36 , V_66 , V_67 ;
int V_19 ;
F_23 ( & V_2 -> V_55 ) ;
for ( V_21 = V_65 = V_36 = 0 ; V_21 < V_64 ; V_21 ++ ) {
V_66 = F_24 ( V_63 [ V_21 ] * V_2 -> V_52 , 1000000 ) ;
V_67 = F_28 ( V_66 , 127 ) ;
if ( V_36 + V_67 > V_2 -> V_9 ) {
V_64 = V_21 ;
break;
}
while ( V_66 > 127 ) {
V_2 -> V_42 -> V_68 [ V_36 ++ ] = 127 | V_65 ;
V_66 -= 127 ;
}
V_2 -> V_42 -> V_68 [ V_36 ++ ] = V_66 | V_65 ;
V_65 ^= 0x80 ;
}
if ( V_64 == 0 ) {
V_19 = - V_54 ;
goto V_48;
}
V_2 -> V_42 -> V_43 . V_44 = 0 ;
V_2 -> V_42 -> V_43 . V_45 = V_46 ;
V_2 -> V_42 -> V_43 . V_47 = V_16 ;
V_2 -> V_42 -> V_69 = V_36 ;
V_2 -> V_13 = false ;
V_19 = F_15 ( V_2 , sizeof( * V_2 -> V_42 ) + V_36 ) ;
if ( V_19 == 0 && V_2 -> V_13 )
V_19 = - V_70 ;
V_48:
F_25 ( & V_2 -> V_55 ) ;
return V_19 ? V_19 : V_64 ;
}
static int F_29 ( struct V_51 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_53 ;
int V_19 ;
F_23 ( & V_2 -> V_55 ) ;
V_19 = F_21 ( V_2 , true ) ;
if ( V_19 == 0 )
V_2 -> V_72 = true ;
F_25 ( & V_2 -> V_55 ) ;
return V_19 ;
}
static void F_30 ( struct V_51 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_53 ;
int V_19 ;
F_23 ( & V_2 -> V_55 ) ;
V_19 = F_21 ( V_2 , false ) ;
V_2 -> V_72 = false ;
if ( V_19 && V_19 != - V_35 )
F_3 ( V_2 -> V_18 , L_11 , V_19 ) ;
F_25 ( & V_2 -> V_55 ) ;
}
static int T_3 F_31 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 = F_32 ( V_74 ) ;
struct V_1 * V_2 ;
struct V_51 * V_19 ;
int V_79 , V_80 , V_81 ;
struct V_82 * V_83 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_39 ) ;
V_19 = F_34 () ;
if ( ! V_2 || ! V_19 ) {
V_79 = - V_84 ;
goto V_48;
}
V_2 -> V_4 = F_35 ( V_78 , V_85 , V_39 ,
& V_2 -> V_86 ) ;
V_2 -> V_42 = F_35 ( V_78 , V_87 , V_39 ,
& V_2 -> V_88 ) ;
V_2 -> V_89 = F_36 ( 0 , V_39 ) ;
V_2 -> V_37 = F_36 ( 0 , V_39 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_42 || ! V_2 -> V_89 || ! V_2 -> V_37 ) {
V_79 = - V_84 ;
goto V_48;
}
V_83 = V_74 -> V_90 ;
if ( V_83 -> V_91 . V_92 < 2 ) {
V_79 = - V_35 ;
goto V_48;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = & V_74 -> V_18 ;
V_2 -> V_78 = V_78 ;
F_37 ( & V_2 -> V_55 ) ;
F_38 ( & V_2 -> V_7 ) ;
V_81 = F_39 ( V_78 ,
V_83 -> V_93 [ 1 ] . V_91 . V_94 ) ;
F_40 ( V_2 -> V_37 , V_78 , V_81 , V_2 -> V_42 , V_87 ,
F_14 , V_2 , 1 ) ;
V_2 -> V_37 -> V_95 = V_2 -> V_88 ;
V_2 -> V_37 -> V_96 |= V_97 ;
V_80 = F_41 ( V_78 , V_83 -> V_93 [ 0 ] . V_91 . V_94 ) ;
F_40 ( V_2 -> V_89 , V_78 , V_80 , V_2 -> V_4 , V_85 ,
F_10 , V_2 , 1 ) ;
V_2 -> V_89 -> V_95 = V_2 -> V_86 ;
V_2 -> V_89 -> V_96 |= V_97 ;
V_79 = F_13 ( V_2 -> V_89 , V_39 ) ;
if ( V_79 ) {
F_3 ( & V_74 -> V_18 , L_12 , V_79 ) ;
goto V_48;
}
V_79 = F_18 ( V_2 ) ;
if ( V_79 )
goto V_98;
snprintf ( V_2 -> V_99 , sizeof( V_2 -> V_99 ) ,
L_13 , V_2 -> V_6 ) ;
F_42 ( V_2 -> V_78 , V_2 -> V_100 , sizeof( V_2 -> V_100 ) ) ;
V_19 -> V_101 = V_2 -> V_99 ;
V_19 -> V_102 = V_2 -> V_100 ;
F_43 ( V_2 -> V_78 , & V_19 -> V_103 ) ;
V_19 -> V_18 . V_104 = & V_74 -> V_18 ;
V_19 -> V_105 = V_106 ;
V_19 -> V_107 = V_108 ;
V_19 -> V_53 = V_2 ;
V_19 -> V_109 = F_29 ;
V_19 -> V_110 = F_30 ;
V_19 -> V_111 = F_26 ;
V_19 -> V_112 = F_22 ;
V_19 -> V_113 = F_27 ;
V_19 -> V_114 = V_115 ;
V_19 -> V_116 = V_117 ;
V_19 -> V_118 = F_44 ( 100 ) ;
V_19 -> V_119 = V_25 ;
F_22 ( V_19 , 38000 ) ;
V_79 = F_45 ( V_19 ) ;
if ( V_79 < 0 ) {
F_20 ( & V_74 -> V_18 , L_14 , V_79 ) ;
goto V_98;
}
F_46 ( V_74 , V_2 ) ;
return 0 ;
V_98:
F_47 ( V_2 -> V_89 ) ;
F_47 ( V_2 -> V_37 ) ;
V_48:
if ( V_2 ) {
F_48 ( V_2 -> V_89 ) ;
F_48 ( V_2 -> V_37 ) ;
F_49 ( V_78 , V_85 , V_2 -> V_4 , V_2 -> V_86 ) ;
F_49 ( V_78 , V_87 , V_2 -> V_42 ,
V_2 -> V_88 ) ;
}
F_50 ( V_19 ) ;
F_51 ( V_2 ) ;
return V_79 ;
}
static void T_4 F_52 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_53 ( V_74 ) ;
F_54 ( V_2 -> V_19 ) ;
F_46 ( V_74 , NULL ) ;
F_47 ( V_2 -> V_89 ) ;
F_47 ( V_2 -> V_37 ) ;
F_48 ( V_2 -> V_89 ) ;
F_48 ( V_2 -> V_37 ) ;
F_49 ( V_2 -> V_78 , V_85 , V_2 -> V_4 , V_2 -> V_86 ) ;
F_49 ( V_2 -> V_78 , V_87 , V_2 -> V_42 , V_2 -> V_88 ) ;
F_51 ( V_2 ) ;
}
static int F_55 ( struct V_73 * V_74 , T_5 V_120 )
{
struct V_1 * V_2 = F_53 ( V_74 ) ;
int V_19 = 0 ;
F_23 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_72 ) {
V_19 = F_21 ( V_2 , false ) ;
if ( V_19 )
F_3 ( V_2 -> V_18 , L_15 ) ;
}
F_47 ( V_2 -> V_89 ) ;
F_47 ( V_2 -> V_37 ) ;
F_25 ( & V_2 -> V_55 ) ;
return V_19 ;
}
static int F_56 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_53 ( V_74 ) ;
int V_19 = 0 ;
F_23 ( & V_2 -> V_55 ) ;
V_19 = F_13 ( V_2 -> V_89 , V_39 ) ;
if ( V_19 )
F_3 ( & V_74 -> V_18 , L_12 , V_19 ) ;
if ( V_2 -> V_72 ) {
V_19 = F_21 ( V_2 , true ) ;
if ( V_19 )
F_3 ( V_2 -> V_18 , L_16 ) ;
}
F_25 ( & V_2 -> V_55 ) ;
return V_19 ;
}
