static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= 4 && V_2 -> V_4 [ 0 ] == 0 && V_2 -> V_4 [ 1 ] == 0 ) {
switch ( V_2 -> V_4 [ 3 ] ) {
case V_5 :
V_2 -> V_6 = true ;
case V_7 :
case V_8 :
case V_9 :
F_2 ( & V_2 -> V_10 ) ;
break;
case V_11 :
F_3 ( V_2 -> V_12 , L_1 ) ;
break;
default:
F_3 ( V_2 -> V_12 , L_2 ,
V_2 -> V_4 [ 3 ] ) ;
break;
}
} else if ( V_3 >= 7 ) {
F_4 ( V_13 ) ;
unsigned V_14 ;
F_5 ( & V_13 ) ;
for ( V_14 = 0 ; V_14 < 7 ; V_14 ++ ) {
if ( V_2 -> V_4 [ V_14 ] == 0x80 ) {
V_13 . V_15 = false ;
V_13 . V_16 = F_6 ( 21845 ) ;
} else {
V_13 . V_15 = ( V_2 -> V_4 [ V_14 ] & 0x80 ) == 0 ;
V_13 . V_16 = ( ( V_2 -> V_4 [ V_14 ] & 0x7f ) + 1 ) *
21330 ;
}
F_7 ( V_2 -> V_17 , & V_13 ) ;
}
F_8 ( V_2 -> V_17 ) ;
}
}
static void F_9 ( struct V_18 * V_18 )
{
struct V_1 * V_2 ;
if ( ! V_18 )
return;
V_2 = V_18 -> V_19 ;
if ( ! V_2 ) {
F_10 ( V_18 ) ;
return;
}
switch ( V_18 -> V_20 ) {
case 0 :
F_1 ( V_2 , V_18 -> V_21 ) ;
break;
case - V_22 :
case - V_23 :
case - V_24 :
F_10 ( V_18 ) ;
return;
case - V_25 :
default:
F_11 ( V_2 -> V_12 , L_3 , V_18 -> V_20 ) ;
break;
}
F_12 ( V_18 , V_26 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_27 , unsigned V_28 ,
struct V_29 * V_30 , unsigned * V_31 )
{
unsigned V_32 , V_3 ;
int V_17 , V_33 ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 += V_34 ) {
V_3 = F_14 ( V_28 - V_32 , V_34 ) ;
if ( V_2 -> V_6 )
return - V_35 ;
V_17 = F_15 ( V_2 -> V_36 , V_2 -> V_37 , V_27 + V_32 ,
V_3 , & V_33 , V_38 ) ;
if ( V_17 )
return V_17 ;
if ( V_33 != V_3 )
return - V_39 ;
}
if ( V_30 ) {
V_17 = F_15 ( V_2 -> V_36 , V_2 -> V_40 , V_30 ,
sizeof( * V_30 ) , V_31 , V_38 ) ;
}
return V_17 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_41 V_41 ;
struct V_29 V_30 ;
int V_17 , V_3 ;
V_41 . V_42 = 0 ;
V_41 . V_43 = V_44 ;
V_41 . V_45 = V_46 ;
V_17 = F_13 ( V_2 , & V_41 , sizeof( V_41 ) , & V_30 , & V_3 ) ;
if ( V_17 ) {
F_17 ( V_2 -> V_12 , L_4 ) ;
goto V_47;
}
if ( V_3 != 6 ) {
F_17 ( V_2 -> V_12 , L_4 ) ;
V_17 = - V_39 ;
goto V_47;
}
V_2 -> V_48 [ 0 ] = V_30 . V_27 [ 0 ] ;
V_2 -> V_48 [ 1 ] = V_30 . V_27 [ 1 ] ;
V_2 -> V_49 = 150 ;
V_2 -> V_50 = 65 ;
V_41 . V_45 = V_51 ;
V_17 = F_13 ( V_2 , & V_41 , sizeof( V_41 ) , & V_30 , & V_3 ) ;
if ( V_17 ) {
F_17 ( V_2 -> V_12 , L_5 ) ;
goto V_47;
}
if ( V_3 != 5 ) {
F_17 ( V_2 -> V_12 , L_5 ) ;
V_17 = - V_39 ;
goto V_47;
}
V_2 -> V_49 = V_30 . V_27 [ 0 ] ;
if ( V_2 -> V_48 [ 0 ] == 0 || V_2 -> V_48 [ 1 ] == 0 )
goto V_47;
V_41 . V_45 = V_52 ;
V_17 = F_13 ( V_2 , & V_41 , sizeof( V_41 ) , & V_30 , & V_3 ) ;
if ( V_17 ) {
F_17 ( V_2 -> V_12 , L_6 ) ;
goto V_47;
}
if ( V_3 < 5 ) {
F_17 ( V_2 -> V_12 , L_6 ) ;
V_17 = - V_39 ;
goto V_47;
}
if ( V_3 > 5 && V_2 -> V_48 [ 0 ] >= 4 )
V_2 -> V_50 = V_30 . V_27 [ 1 ] ;
V_47:
return V_17 ;
}
static int F_18 ( struct V_1 * V_2 , bool V_53 )
{
struct V_41 V_41 = { 0 , V_44 , V_53 ?
V_8 : V_7 } ;
int V_17 ;
F_19 ( V_2 -> V_10 ) ;
V_17 = F_13 ( V_2 , & V_41 , sizeof( V_41 ) , NULL , NULL ) ;
if ( V_17 )
return V_17 ;
F_20 ( & V_2 -> V_10 , V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_54 * V_12 , T_1 V_55 )
{
struct V_1 * V_2 = V_12 -> V_56 ;
if ( V_55 < 25000 || V_55 > 150000 )
return - V_57 ;
F_22 ( & V_2 -> V_58 ) ;
if ( V_55 != V_2 -> V_55 ) {
T_1 V_59 , V_60 , V_61 ;
V_2 -> V_55 = V_55 ;
V_59 = F_23 ( 24000000 , V_55 * 2 ) -
V_2 -> V_50 ;
switch ( V_59 & 3 ) {
case 0 :
V_61 = 0 ;
break;
case 1 :
V_61 = 3 ;
break;
case 2 :
V_61 = 2 ;
break;
case 3 :
V_61 = 1 ;
break;
}
V_60 = ( V_59 - V_61 * 7 ) / 4 ;
V_2 -> V_62 = ( 4 - V_61 ) * 2 ;
V_2 -> V_63 = 110 - V_60 ;
}
F_24 ( & V_2 -> V_58 ) ;
return V_55 ;
}
static int F_25 ( struct V_54 * V_12 , T_1 V_64 )
{
struct V_1 * V_2 = V_12 -> V_56 ;
if ( V_64 > 15 )
return 4 ;
F_22 ( & V_2 -> V_58 ) ;
V_2 -> V_65 = V_64 ;
F_24 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_26 ( struct V_54 * V_12 , unsigned * V_66 , unsigned V_67 )
{
struct V_1 * V_2 = V_12 -> V_56 ;
T_2 V_68 , * V_69 ;
unsigned V_14 , V_28 , V_17 ;
struct V_70 * V_41 ;
F_22 ( & V_2 -> V_58 ) ;
for ( V_14 = V_28 = 0 ; V_14 < V_67 ; V_14 ++ ) {
V_66 [ V_14 ] = F_23 ( V_66 [ V_14 ] * V_2 -> V_55 , 1000000 ) ;
V_28 += ( V_66 [ V_14 ] + 126 ) / 127 ;
}
V_41 = F_27 ( sizeof( * V_41 ) + V_28 , V_71 ) ;
if ( ! V_41 ) {
V_17 = - V_72 ;
goto V_47;
}
if ( V_28 > V_2 -> V_49 ) {
V_17 = - V_73 ;
goto V_47;
}
V_41 -> V_74 . V_42 = 0 ;
V_41 -> V_74 . V_43 = V_44 ;
V_41 -> V_74 . V_45 = V_9 ;
V_41 -> V_75 = V_28 ;
V_41 -> V_65 = V_2 -> V_65 << 4 ;
V_41 -> V_62 = V_2 -> V_62 ;
V_41 -> V_63 = V_2 -> V_63 ;
V_68 = 0 ;
V_69 = V_41 -> V_69 ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ ) {
unsigned V_76 = V_66 [ V_14 ] ;
while ( V_76 > 127 ) {
* V_69 ++ = 127 | V_68 ;
V_76 -= 127 ;
}
* V_69 ++ = V_76 | V_68 ;
V_68 ^= 0x80 ;
}
if ( V_2 -> V_77 ) {
V_17 = F_18 ( V_2 , false ) ;
if ( V_17 ) {
F_3 ( V_2 -> V_12 , L_7 ) ;
goto V_47;
}
}
V_2 -> V_6 = false ;
F_19 ( V_2 -> V_10 ) ;
V_17 = F_13 ( V_2 , V_41 , V_28 + 8 , NULL , NULL ) ;
if ( V_17 == 0 ) {
F_20 ( & V_2 -> V_10 , V_38 ) ;
if ( V_2 -> V_6 )
V_17 = - V_35 ;
}
V_2 -> V_6 = false ;
if ( V_2 -> V_77 ) {
if ( F_18 ( V_2 , true ) )
F_3 ( V_2 -> V_12 , L_8 ) ;
}
V_47:
F_24 ( & V_2 -> V_58 ) ;
F_28 ( V_41 ) ;
return V_17 ;
}
static int F_29 ( struct V_54 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_56 ;
int V_17 ;
F_22 ( & V_2 -> V_58 ) ;
F_12 ( V_2 -> V_79 , V_71 ) ;
F_30 ( V_2 -> V_77 ) ;
V_17 = F_18 ( V_2 , true ) ;
if ( V_17 == 0 )
V_2 -> V_77 = true ;
F_24 ( & V_2 -> V_58 ) ;
return V_17 ;
}
static void F_31 ( struct V_54 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_56 ;
int V_17 ;
F_22 ( & V_2 -> V_58 ) ;
V_17 = F_18 ( V_2 , false ) ;
V_2 -> V_77 = false ;
if ( V_17 )
F_3 ( V_2 -> V_12 , L_9 , V_17 ) ;
F_32 ( V_2 -> V_79 ) ;
F_24 ( & V_2 -> V_58 ) ;
}
static int T_3 F_33 ( struct V_80 * V_81 ,
const struct V_82 * V_83 )
{
struct V_84 * V_36 = F_34 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_54 * V_17 ;
int V_85 ;
struct V_86 * V_87 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_71 ) ;
V_17 = F_36 () ;
if ( ! V_2 || ! V_17 ) {
V_85 = V_72 ;
goto V_47;
}
V_2 -> V_4 = F_37 ( V_36 , V_34 , V_26 ,
& V_2 -> V_88 ) ;
V_2 -> V_79 = F_38 ( 0 , V_71 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_79 ) {
V_85 = V_72 ;
goto V_47;
}
V_87 = V_81 -> V_89 ;
if ( V_87 -> V_90 . V_91 < 2 ) {
V_85 = - V_92 ;
goto V_47;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_12 = & V_81 -> V_12 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_40 = F_39 ( V_36 ,
V_87 -> V_93 [ 0 ] . V_90 . V_94 ) ;
V_2 -> V_37 = F_40 ( V_36 ,
V_87 -> V_93 [ 1 ] . V_90 . V_94 ) ;
F_41 ( & V_2 -> V_58 ) ;
F_42 ( & V_2 -> V_10 ) ;
V_85 = F_16 ( V_2 ) ;
if ( V_85 ) {
F_3 ( & V_81 -> V_12 , L_10 ) ;
goto V_47;
}
F_43 ( V_2 -> V_79 , V_2 -> V_36 , V_2 -> V_40 , V_2 -> V_4 ,
V_34 , F_9 , V_2 ,
V_87 -> V_93 [ 0 ] . V_90 . V_95 ) ;
V_2 -> V_79 -> V_96 = V_2 -> V_88 ;
V_2 -> V_79 -> V_97 |= V_98 ;
snprintf ( V_2 -> V_99 , sizeof( V_2 -> V_99 ) ,
L_11 ,
V_2 -> V_48 [ 0 ] , V_2 -> V_48 [ 1 ] ) ;
F_44 ( V_2 -> V_36 , V_2 -> V_100 , sizeof( V_2 -> V_100 ) ) ;
V_17 -> V_101 = V_2 -> V_99 ;
V_17 -> V_102 = V_2 -> V_100 ;
F_45 ( V_2 -> V_36 , & V_17 -> V_103 ) ;
V_17 -> V_12 . V_104 = & V_81 -> V_12 ;
V_17 -> V_105 = V_106 ;
V_17 -> V_107 = V_108 ;
V_17 -> V_56 = V_2 ;
V_17 -> V_109 = F_29 ;
V_17 -> V_110 = F_31 ;
V_17 -> V_111 = F_25 ;
V_17 -> V_112 = F_21 ;
V_17 -> V_113 = F_26 ;
V_17 -> V_114 = V_115 ;
V_17 -> V_116 = V_117 ;
F_21 ( V_17 , 38000 ) ;
V_85 = F_46 ( V_17 ) ;
if ( V_85 < 0 ) {
F_47 ( & V_81 -> V_12 , L_12 , V_85 ) ;
goto V_47;
}
F_48 ( V_81 , V_2 ) ;
F_17 ( & V_81 -> V_12 , L_13 , V_2 -> V_99 ) ;
return 0 ;
V_47:
if ( V_2 ) {
F_49 ( V_2 -> V_79 ) ;
F_50 ( V_36 , V_34 , V_2 -> V_4 ,
V_2 -> V_88 ) ;
}
F_51 ( V_17 ) ;
F_28 ( V_2 ) ;
return V_85 ;
}
static void T_4 F_52 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_53 ( V_81 ) ;
F_48 ( V_81 , NULL ) ;
F_32 ( V_2 -> V_79 ) ;
F_49 ( V_2 -> V_79 ) ;
F_50 ( V_2 -> V_36 , V_34 , V_2 -> V_4 , V_2 -> V_88 ) ;
F_54 ( V_2 -> V_17 ) ;
F_28 ( V_2 ) ;
}
static int F_55 ( struct V_80 * V_81 , T_5 V_118 )
{
struct V_1 * V_2 = F_53 ( V_81 ) ;
int V_17 = 0 ;
F_22 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_77 ) {
V_17 = F_18 ( V_2 , false ) ;
if ( V_17 )
F_3 ( V_2 -> V_12 , L_14 ) ;
}
F_24 ( & V_2 -> V_58 ) ;
return V_17 ;
}
static int F_56 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_53 ( V_81 ) ;
int V_17 = 0 ;
F_22 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_77 ) {
V_17 = F_18 ( V_2 , true ) ;
if ( V_17 )
F_3 ( V_2 -> V_12 , L_15 ) ;
}
F_24 ( & V_2 -> V_58 ) ;
return V_17 ;
}
