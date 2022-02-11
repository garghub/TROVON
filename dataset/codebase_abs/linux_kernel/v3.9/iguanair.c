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
if ( V_26 -> V_28 == 0 && V_2 -> V_36 -> V_37 . V_38 == V_39 )
F_2 ( & V_2 -> V_7 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_40 )
{
int V_19 ;
F_16 ( V_2 -> V_7 ) ;
V_2 -> V_41 -> V_42 = V_40 ;
V_19 = F_13 ( V_2 -> V_41 , V_43 ) ;
if ( V_19 )
return V_19 ;
if ( F_17 ( & V_2 -> V_7 , V_44 ) == 0 )
return - V_45 ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_36 -> V_37 . V_46 = 0 ;
V_2 -> V_36 -> V_37 . V_47 = V_48 ;
V_2 -> V_36 -> V_37 . V_38 = V_39 ;
F_15 ( V_2 , sizeof( V_2 -> V_36 -> V_37 ) ) ;
V_2 -> V_36 -> V_37 . V_38 = V_5 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_36 -> V_37 ) ) ;
if ( V_19 ) {
F_19 ( V_2 -> V_18 , L_6 ) ;
goto V_49;
}
if ( V_2 -> V_6 < 0x205 ) {
F_20 ( V_2 -> V_18 , L_7 , V_2 -> V_6 ) ;
V_19 = - V_35 ;
goto V_49;
}
V_2 -> V_9 = 150 ;
V_2 -> V_11 = 65 ;
V_2 -> V_36 -> V_37 . V_38 = V_8 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_36 -> V_37 ) ) ;
if ( V_19 ) {
F_19 ( V_2 -> V_18 , L_8 ) ;
goto V_49;
}
if ( V_2 -> V_9 > V_50 ) {
F_19 ( V_2 -> V_18 , L_9 ,
V_2 -> V_9 ) ;
V_2 -> V_9 = V_50 ;
}
V_2 -> V_36 -> V_37 . V_38 = V_10 ;
V_19 = F_15 ( V_2 , sizeof( V_2 -> V_36 -> V_37 ) ) ;
if ( V_19 )
F_19 ( V_2 -> V_18 , L_10 ) ;
V_49:
return V_19 ;
}
static int F_21 ( struct V_1 * V_2 , bool V_51 )
{
V_2 -> V_36 -> V_37 . V_46 = 0 ;
V_2 -> V_36 -> V_37 . V_47 = V_48 ;
V_2 -> V_36 -> V_37 . V_38 = V_51 ? V_15 : V_14 ;
if ( V_51 )
F_4 ( V_2 -> V_19 ) ;
return F_15 ( V_2 , sizeof( V_2 -> V_36 -> V_37 ) ) ;
}
static int F_22 ( struct V_52 * V_18 , T_1 V_53 )
{
struct V_1 * V_2 = V_18 -> V_54 ;
if ( V_53 < 25000 || V_53 > 150000 )
return - V_55 ;
F_23 ( & V_2 -> V_56 ) ;
if ( V_53 != V_2 -> V_53 ) {
T_1 V_57 , V_58 , V_59 ;
V_2 -> V_53 = V_53 ;
V_57 = F_24 ( 24000000 , V_53 * 2 ) -
V_2 -> V_11 ;
switch ( V_57 & 3 ) {
case 0 :
V_59 = 0 ;
break;
case 1 :
V_59 = 3 ;
break;
case 2 :
V_59 = 2 ;
break;
case 3 :
V_59 = 1 ;
break;
}
V_58 = ( V_57 - V_59 * 7 ) / 4 ;
V_2 -> V_36 -> V_60 = ( 4 - V_59 ) * 2 ;
V_2 -> V_36 -> V_61 = 110 - V_58 ;
}
F_25 ( & V_2 -> V_56 ) ;
return V_53 ;
}
static int F_26 ( struct V_52 * V_18 , T_1 V_62 )
{
struct V_1 * V_2 = V_18 -> V_54 ;
if ( V_62 > 15 )
return 4 ;
F_23 ( & V_2 -> V_56 ) ;
V_2 -> V_36 -> V_63 = V_62 << 4 ;
F_25 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_18 , unsigned * V_64 , unsigned V_65 )
{
struct V_1 * V_2 = V_18 -> V_54 ;
T_2 V_66 ;
unsigned V_21 , V_40 , V_67 , V_68 ;
int V_19 ;
F_23 ( & V_2 -> V_56 ) ;
for ( V_21 = V_66 = V_40 = 0 ; V_21 < V_65 ; V_21 ++ ) {
V_67 = F_24 ( V_64 [ V_21 ] * V_2 -> V_53 , 1000000 ) ;
V_68 = F_28 ( V_67 , 127 ) ;
if ( V_40 + V_68 > V_2 -> V_9 ) {
V_65 = V_21 ;
break;
}
while ( V_67 > 127 ) {
V_2 -> V_36 -> V_69 [ V_40 ++ ] = 127 | V_66 ;
V_67 -= 127 ;
}
V_2 -> V_36 -> V_69 [ V_40 ++ ] = V_67 | V_66 ;
V_66 ^= 0x80 ;
}
if ( V_65 == 0 ) {
V_19 = - V_55 ;
goto V_49;
}
V_2 -> V_36 -> V_37 . V_46 = 0 ;
V_2 -> V_36 -> V_37 . V_47 = V_48 ;
V_2 -> V_36 -> V_37 . V_38 = V_16 ;
V_2 -> V_36 -> V_70 = V_40 ;
V_2 -> V_13 = false ;
V_19 = F_15 ( V_2 , sizeof( * V_2 -> V_36 ) + V_40 ) ;
if ( V_19 == 0 && V_2 -> V_13 )
V_19 = - V_71 ;
V_49:
F_25 ( & V_2 -> V_56 ) ;
return V_19 ? V_19 : V_65 ;
}
static int F_29 ( struct V_52 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_54 ;
int V_19 ;
F_23 ( & V_2 -> V_56 ) ;
V_19 = F_21 ( V_2 , true ) ;
if ( V_19 == 0 )
V_2 -> V_73 = true ;
F_25 ( & V_2 -> V_56 ) ;
return V_19 ;
}
static void F_30 ( struct V_52 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_54 ;
int V_19 ;
F_23 ( & V_2 -> V_56 ) ;
V_19 = F_21 ( V_2 , false ) ;
V_2 -> V_73 = false ;
if ( V_19 && V_19 != - V_35 )
F_3 ( V_2 -> V_18 , L_11 , V_19 ) ;
F_25 ( & V_2 -> V_56 ) ;
}
static int F_31 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_78 * V_79 = F_32 ( V_75 ) ;
struct V_1 * V_2 ;
struct V_52 * V_19 ;
int V_80 , V_81 , V_82 ;
struct V_83 * V_84 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_43 ) ;
V_19 = F_34 () ;
if ( ! V_2 || ! V_19 ) {
V_80 = - V_85 ;
goto V_49;
}
V_2 -> V_4 = F_35 ( V_79 , V_86 , V_43 ,
& V_2 -> V_87 ) ;
V_2 -> V_36 = F_35 ( V_79 , V_88 , V_43 ,
& V_2 -> V_89 ) ;
V_2 -> V_90 = F_36 ( 0 , V_43 ) ;
V_2 -> V_41 = F_36 ( 0 , V_43 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_36 || ! V_2 -> V_90 || ! V_2 -> V_41 ) {
V_80 = - V_85 ;
goto V_49;
}
V_84 = V_75 -> V_91 ;
if ( V_84 -> V_92 . V_93 < 2 ) {
V_80 = - V_35 ;
goto V_49;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = & V_75 -> V_18 ;
V_2 -> V_79 = V_79 ;
F_37 ( & V_2 -> V_56 ) ;
F_38 ( & V_2 -> V_7 ) ;
V_82 = F_39 ( V_79 ,
V_84 -> V_94 [ 1 ] . V_92 . V_95 ) ;
F_40 ( V_2 -> V_41 , V_79 , V_82 , V_2 -> V_36 , V_88 ,
F_14 , V_2 , 1 ) ;
V_2 -> V_41 -> V_96 = V_2 -> V_89 ;
V_2 -> V_41 -> V_97 |= V_98 ;
V_81 = F_41 ( V_79 , V_84 -> V_94 [ 0 ] . V_92 . V_95 ) ;
F_40 ( V_2 -> V_90 , V_79 , V_81 , V_2 -> V_4 , V_86 ,
F_10 , V_2 , 1 ) ;
V_2 -> V_90 -> V_96 = V_2 -> V_87 ;
V_2 -> V_90 -> V_97 |= V_98 ;
V_80 = F_13 ( V_2 -> V_90 , V_43 ) ;
if ( V_80 ) {
F_3 ( & V_75 -> V_18 , L_12 , V_80 ) ;
goto V_49;
}
V_80 = F_18 ( V_2 ) ;
if ( V_80 )
goto V_99;
snprintf ( V_2 -> V_100 , sizeof( V_2 -> V_100 ) ,
L_13 , V_2 -> V_6 ) ;
F_42 ( V_2 -> V_79 , V_2 -> V_101 , sizeof( V_2 -> V_101 ) ) ;
V_19 -> V_102 = V_2 -> V_100 ;
V_19 -> V_103 = V_2 -> V_101 ;
F_43 ( V_2 -> V_79 , & V_19 -> V_104 ) ;
V_19 -> V_18 . V_105 = & V_75 -> V_18 ;
V_19 -> V_106 = V_107 ;
V_19 -> V_108 = V_109 ;
V_19 -> V_54 = V_2 ;
V_19 -> V_110 = F_29 ;
V_19 -> V_111 = F_30 ;
V_19 -> V_112 = F_26 ;
V_19 -> V_113 = F_22 ;
V_19 -> V_114 = F_27 ;
V_19 -> V_115 = V_116 ;
V_19 -> V_117 = V_118 ;
V_19 -> V_119 = F_44 ( 100 ) ;
V_19 -> V_120 = V_25 ;
F_22 ( V_19 , 38000 ) ;
F_26 ( V_19 , 0 ) ;
V_80 = F_45 ( V_19 ) ;
if ( V_80 < 0 ) {
F_20 ( & V_75 -> V_18 , L_14 , V_80 ) ;
goto V_99;
}
F_46 ( V_75 , V_2 ) ;
return 0 ;
V_99:
F_47 ( V_2 -> V_90 ) ;
F_47 ( V_2 -> V_41 ) ;
V_49:
if ( V_2 ) {
F_48 ( V_2 -> V_90 ) ;
F_48 ( V_2 -> V_41 ) ;
F_49 ( V_79 , V_86 , V_2 -> V_4 , V_2 -> V_87 ) ;
F_49 ( V_79 , V_88 , V_2 -> V_36 ,
V_2 -> V_89 ) ;
}
F_50 ( V_19 ) ;
F_51 ( V_2 ) ;
return V_80 ;
}
static void F_52 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_53 ( V_75 ) ;
F_54 ( V_2 -> V_19 ) ;
F_46 ( V_75 , NULL ) ;
F_47 ( V_2 -> V_90 ) ;
F_47 ( V_2 -> V_41 ) ;
F_48 ( V_2 -> V_90 ) ;
F_48 ( V_2 -> V_41 ) ;
F_49 ( V_2 -> V_79 , V_86 , V_2 -> V_4 , V_2 -> V_87 ) ;
F_49 ( V_2 -> V_79 , V_88 , V_2 -> V_36 , V_2 -> V_89 ) ;
F_51 ( V_2 ) ;
}
static int F_55 ( struct V_74 * V_75 , T_3 V_121 )
{
struct V_1 * V_2 = F_53 ( V_75 ) ;
int V_19 = 0 ;
F_23 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_73 ) {
V_19 = F_21 ( V_2 , false ) ;
if ( V_19 )
F_3 ( V_2 -> V_18 , L_15 ) ;
}
F_47 ( V_2 -> V_90 ) ;
F_47 ( V_2 -> V_41 ) ;
F_25 ( & V_2 -> V_56 ) ;
return V_19 ;
}
static int F_56 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_53 ( V_75 ) ;
int V_19 = 0 ;
F_23 ( & V_2 -> V_56 ) ;
V_19 = F_13 ( V_2 -> V_90 , V_43 ) ;
if ( V_19 )
F_3 ( & V_75 -> V_18 , L_12 , V_19 ) ;
if ( V_2 -> V_73 ) {
V_19 = F_21 ( V_2 , true ) ;
if ( V_19 )
F_3 ( V_2 -> V_18 , L_16 ) ;
}
F_25 ( & V_2 -> V_56 ) ;
return V_19 ;
}
