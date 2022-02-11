static int F_1 ( int V_1 )
{
unsigned char V_2 = 0 ;
V_1 /= 6250 ;
while ( true ) {
V_1 = V_1 >> 1 ;
if ( V_1 == 0 )
break;
V_2 ++ ;
}
if ( V_2 > 3 )
V_2 = 3 ;
return V_2 ;
}
static int F_2 ( struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_1 = 0 ;
int V_9 , V_10 ;
switch ( F_4 ( V_4 ) ) {
case V_11 :
V_1 = V_8 -> V_12 ;
break;
case V_13 :
case V_14 :
V_1 = V_8 -> V_15 ;
break;
case V_16 :
V_1 = V_8 -> V_17 ;
break;
case V_18 :
case V_19 :
V_1 = V_8 -> V_20 ;
break;
case V_21 :
case V_22 :
case V_23 :
V_1 = V_8 -> V_24 ;
break;
case V_25 :
V_1 = V_8 -> V_26 ;
}
if ( V_1 == 0 )
V_1 = V_4 -> V_27 -> V_1 ;
V_9 = V_4 -> V_27 -> V_28 + ( V_4 -> V_27 -> V_29 * V_5 ) ;
V_10 = V_4 -> V_27 -> V_28 + ( V_4 -> V_27 -> V_29 * V_6 ) ;
return F_5 ( abs ( V_10 - V_9 ) , V_1 ) ;
}
static int F_6 ( struct V_3 * V_4 , int V_1 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_30 , V_31 , V_32 = V_33 ;
unsigned int V_34 = 1 , V_35 = 0 ;
int V_36 ;
switch ( F_4 ( V_4 ) ) {
case V_19 :
if ( V_1 > V_8 -> V_20 )
V_8 -> V_20 = V_1 ;
else
V_1 = V_8 -> V_20 ;
V_31 = V_37 ;
break;
case V_11 :
V_35 = V_38 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
V_8 -> V_12 = V_1 ;
V_31 = V_39 ;
V_32 = V_40 ;
break;
case V_13 :
V_35 = V_41 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_15 )
V_8 -> V_15 = V_1 ;
else
V_1 = V_8 -> V_15 ;
V_31 = V_42 ;
V_32 = V_40 ;
break;
case V_14 :
V_35 = V_43 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_15 )
V_8 -> V_15 = V_1 ;
else
V_1 = V_8 -> V_15 ;
V_31 = V_42 ;
V_32 = V_40 ;
break;
case V_16 :
V_8 -> V_17 = V_1 ;
V_31 = V_44 ;
break;
case V_18 :
V_35 = V_45 ;
if ( ! V_1 ) {
V_34 = 0 ;
break;
}
if ( V_1 > V_8 -> V_20 )
V_8 -> V_20 = V_1 ;
else
V_1 = V_8 -> V_20 ;
V_31 = V_37 ;
break;
case V_21 :
case V_22 :
case V_23 :
if ( V_1 > V_8 -> V_24 )
V_8 -> V_24 = V_1 ;
else
V_1 = V_8 -> V_24 ;
V_31 = V_46 ;
break;
case V_25 :
V_8 -> V_26 = V_1 ;
V_31 = V_47 ;
break;
default:
return 0 ;
}
if ( ! V_34 )
goto V_48;
if ( ( F_4 ( V_4 ) >= V_11 &&
F_4 ( V_4 ) <= V_14 ) ||
F_4 ( V_4 ) == V_18 ) {
V_36 = F_7 ( V_4 -> V_49 , V_40 ,
1 << V_35 , 1 << V_35 ) ;
if ( V_36 ) {
F_8 ( & V_4 -> V_50 , L_1 ) ;
return V_36 ;
}
}
V_30 = F_1 ( V_1 ) ;
return F_7 ( V_4 -> V_49 , V_32 , 0x3 << V_31 ,
V_30 << V_31 ) ;
V_48:
return F_7 ( V_4 -> V_49 , V_40 ,
1 << V_35 , 0 ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_51 ;
switch ( V_8 -> V_52 ) {
case V_53 :
case V_54 :
if ( F_10 ( F_4 ( V_4 ) , V_8 -> V_55 ) )
V_51 = V_56 ;
else if ( F_11 ( V_8 -> V_57 [ F_4 ( V_4 ) ] ) )
V_51 = V_58 ;
else
V_51 = V_4 -> V_27 -> V_59 ;
break;
case V_60 :
if ( F_10 ( F_4 ( V_4 ) , V_8 -> V_55 ) )
V_51 = V_61 ;
else
V_51 = V_4 -> V_27 -> V_59 ;
break;
default:
return - V_62 ;
}
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_63 ,
V_4 -> V_27 -> V_59 , V_51 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
int V_36 ;
unsigned int V_51 , V_64 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_65 = F_4 ( V_4 ) ;
switch ( V_8 -> V_52 ) {
case V_53 :
case V_54 :
switch ( V_65 ) {
case V_66 :
return 0 ;
default:
V_64 = V_56 ;
break;
}
break;
case V_60 :
switch ( V_65 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_64 = V_72 ;
break;
default:
V_64 = V_61 ;
break;
}
break;
default:
return - V_62 ;
}
V_36 = F_13 ( V_4 -> V_49 , V_4 -> V_27 -> V_63 , & V_51 ) ;
if ( V_36 < 0 )
return V_36 ;
F_14 ( F_4 ( V_4 ) , V_8 -> V_55 ) ;
if ( ! ( V_51 & V_4 -> V_27 -> V_59 ) )
return 0 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_63 ,
V_4 -> V_27 -> V_59 , V_64 ) ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_63 ,
V_4 -> V_27 -> V_59 , V_58 ) ;
}
static void F_16 ( struct V_73 * V_74 ,
struct V_75 * V_76 , struct V_7 * V_8 )
{
int * V_77 = V_8 -> V_57 ;
unsigned int V_78 ;
unsigned int V_79 [ 3 ] = { V_80 , V_81 ,
V_82 } ;
for ( V_78 = 0 ; V_78 < F_17 ( V_79 ) ; V_78 ++ ) {
unsigned int V_83 = V_79 [ V_78 ] ;
if ( ! V_76 [ V_83 ] . V_84 || ! V_76 [ V_83 ] . V_85 )
continue;
V_77 [ V_83 ] = F_18 ( V_76 [ V_83 ] . V_85 ,
L_2 , 0 ) ;
if ( F_11 ( V_77 [ V_83 ] ) )
F_19 ( & V_74 -> V_50 , L_3 ,
V_77 [ V_83 ] , V_83 , V_76 [ V_83 ] . V_86 ) ;
}
}
static int F_20 ( struct V_73 * V_74 ,
struct V_75 * V_76 , struct V_7 * V_8 )
{
struct V_87 * V_88 ;
V_88 = F_21 ( V_74 -> V_50 . V_89 -> V_85 , L_4 ) ;
if ( ! V_88 ) {
F_8 ( & V_74 -> V_50 , L_5 ) ;
return - V_62 ;
}
V_75 ( & V_74 -> V_50 , V_88 , V_76 , V_8 -> V_90 ) ;
if ( V_8 -> V_52 == V_54 )
F_16 ( V_74 , V_76 , V_8 ) ;
F_22 ( V_88 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , int V_1 )
{
unsigned int V_30 , V_31 , V_32 ;
switch ( F_4 ( V_4 ) ) {
case V_91 :
V_31 = V_92 ;
break;
case V_93 :
V_31 = V_94 ;
break;
case V_95 :
V_31 = V_96 ;
break;
case V_97 :
V_31 = V_98 ;
break;
default:
return 0 ;
}
V_32 = V_99 ;
V_30 = F_1 ( V_1 ) ;
return F_7 ( V_4 -> V_49 , V_32 ,
V_100 << V_31 ,
V_30 << V_31 ) ;
}
static int F_24 ( struct V_73 * V_74 )
{
struct V_101 * V_102 = F_25 ( V_74 -> V_50 . V_89 ) ;
struct V_103 * V_104 = NULL ;
struct V_75 * V_76 = NULL ;
struct V_105 V_106 = { } ;
struct V_7 * V_8 ;
int V_78 , V_36 = 0 ;
const struct V_107 * V_108 ;
V_8 = F_26 ( & V_74 -> V_50 , sizeof( struct V_7 ) ,
V_109 ) ;
if ( ! V_8 )
return - V_110 ;
V_8 -> V_52 = F_27 ( V_74 ) -> V_111 ;
switch ( V_8 -> V_52 ) {
case V_112 :
V_8 -> V_90 = F_17 ( V_113 ) ;
V_108 = V_113 ;
F_28 ( V_114 < V_8 -> V_90 ) ;
break;
case V_53 :
V_8 -> V_90 = F_17 ( V_115 ) ;
V_108 = V_115 ;
F_28 ( V_114 < V_8 -> V_90 ) ;
break;
case V_54 :
V_8 -> V_90 = F_17 ( V_116 ) ;
V_108 = V_116 ;
F_28 ( V_114 < V_8 -> V_90 ) ;
break;
case V_60 :
V_8 -> V_90 = F_17 ( V_117 ) ;
V_108 = V_117 ;
F_28 ( V_114 < V_8 -> V_90 ) ;
break;
default:
F_8 ( & V_74 -> V_50 , L_6 ,
V_8 -> V_52 ) ;
return - V_62 ;
}
V_8 -> V_57 = F_29 ( & V_74 -> V_50 ,
sizeof( * V_8 -> V_57 ) * V_8 -> V_90 ,
V_109 ) ;
if ( ! V_8 -> V_57 )
return - V_110 ;
for ( V_78 = 0 ; V_78 < V_8 -> V_90 ; V_78 ++ )
V_8 -> V_57 [ V_78 ] = - V_62 ;
if ( ! V_102 -> V_50 -> V_85 ) {
if ( V_102 -> V_104 ) {
V_104 = V_102 -> V_104 ;
goto V_118;
} else {
F_8 ( V_74 -> V_50 . V_89 ,
L_7 ) ;
return - V_119 ;
}
}
V_76 = F_30 ( sizeof( * V_76 ) * V_8 -> V_90 , V_109 ) ;
if ( ! V_76 )
return - V_110 ;
for ( V_78 = 0 ; V_78 < V_8 -> V_90 ; V_78 ++ )
V_76 [ V_78 ] . V_86 = V_108 [ V_78 ] . V_86 ;
V_36 = F_20 ( V_74 , V_76 , V_8 ) ;
if ( V_36 )
goto V_120;
V_118:
F_31 ( V_74 , V_8 ) ;
V_106 . V_50 = & V_74 -> V_50 ;
V_106 . V_49 = V_102 -> V_121 ;
V_106 . V_111 = V_8 ;
V_106 . V_122 = V_123 ;
V_106 . V_124 = true ;
for ( V_78 = 0 ; V_78 < V_8 -> V_90 ; V_78 ++ ) {
struct V_3 * V_125 ;
if ( V_104 ) {
V_106 . V_84 = V_104 -> V_108 [ V_78 ] . V_126 ;
V_106 . V_85 = V_104 -> V_108 [ V_78 ] . V_127 ;
} else {
V_106 . V_84 = V_76 [ V_78 ] . V_84 ;
V_106 . V_85 = V_76 [ V_78 ] . V_85 ;
}
V_106 . V_128 = V_8 -> V_57 [ V_78 ] ;
V_125 = F_32 ( & V_74 -> V_50 ,
& V_108 [ V_78 ] , & V_106 ) ;
if ( F_33 ( V_125 ) ) {
V_36 = F_34 ( V_125 ) ;
F_8 ( & V_74 -> V_50 , L_8 ,
V_78 ) ;
goto V_120;
}
if ( F_11 ( V_8 -> V_57 [ V_78 ] ) ) {
V_36 = F_15 ( V_8 ,
V_125 ) ;
if ( V_36 < 0 ) {
F_8 ( & V_74 -> V_50 ,
L_9 ,
V_125 -> V_27 -> V_86 , V_36 ) ;
goto V_120;
}
}
}
V_120:
F_35 ( V_76 ) ;
return V_36 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_129 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_129 ) ;
}
