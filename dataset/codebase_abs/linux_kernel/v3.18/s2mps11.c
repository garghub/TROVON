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
if ( V_8 -> V_54 & ( 1 << F_4 ( V_4 ) ) )
V_51 = V_55 ;
else if ( F_10 ( V_8 -> V_56 [ F_4 ( V_4 ) ] ) )
V_51 = V_57 ;
else
V_51 = V_4 -> V_27 -> V_58 ;
break;
case V_59 :
if ( V_8 -> V_54 & ( 1 << F_4 ( V_4 ) ) )
V_51 = V_60 ;
else
V_51 = V_4 -> V_27 -> V_58 ;
break;
default:
return - V_61 ;
} ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_62 ,
V_4 -> V_27 -> V_58 , V_51 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_36 ;
unsigned int V_51 , V_63 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_64 = F_4 ( V_4 ) ;
switch ( V_8 -> V_52 ) {
case V_53 :
switch ( V_64 ) {
case V_65 :
return 0 ;
default:
V_63 = V_55 ;
break;
} ;
break;
case V_59 :
switch ( V_64 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_63 = V_71 ;
break;
default:
V_63 = V_60 ;
break;
} ;
break;
default:
return - V_61 ;
} ;
V_36 = F_12 ( V_4 -> V_49 , V_4 -> V_27 -> V_62 , & V_51 ) ;
if ( V_36 < 0 )
return V_36 ;
V_8 -> V_54 |= ( 1 << F_4 ( V_4 ) ) ;
if ( ! ( V_51 & V_4 -> V_27 -> V_58 ) )
return 0 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_62 ,
V_4 -> V_27 -> V_58 , V_63 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_62 ,
V_4 -> V_27 -> V_58 , V_57 ) ;
}
static void F_14 ( struct V_72 * V_73 ,
struct V_74 * V_75 , struct V_7 * V_8 )
{
int * V_76 = V_8 -> V_56 ;
unsigned int V_77 ;
unsigned int V_78 [ 3 ] = { V_79 , V_80 ,
V_81 } ;
for ( V_77 = 0 ; V_77 < F_15 ( V_78 ) ; V_77 ++ ) {
unsigned int V_82 = V_78 [ V_77 ] ;
if ( ! V_75 [ V_82 ] . V_83 || ! V_75 [ V_82 ] . V_84 )
continue;
V_76 [ V_82 ] = F_16 ( V_75 [ V_82 ] . V_84 ,
L_2 , 0 ) ;
if ( F_10 ( V_76 [ V_82 ] ) )
F_17 ( & V_73 -> V_50 , L_3 ,
V_76 [ V_82 ] , V_82 , V_75 [ V_82 ] . V_85 ) ;
}
}
static int F_18 ( struct V_72 * V_73 ,
struct V_74 * V_75 , struct V_7 * V_8 )
{
struct V_86 * V_87 ;
V_87 = F_19 ( V_73 -> V_50 . V_88 -> V_84 , L_4 ) ;
if ( ! V_87 ) {
F_8 ( & V_73 -> V_50 , L_5 ) ;
return - V_61 ;
}
V_74 ( & V_73 -> V_50 , V_87 , V_75 , V_8 -> V_89 ) ;
if ( V_8 -> V_52 == V_53 )
F_14 ( V_73 , V_75 , V_8 ) ;
F_20 ( V_87 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 , int V_1 )
{
unsigned int V_30 , V_31 , V_32 ;
switch ( F_4 ( V_4 ) ) {
case V_90 :
V_31 = V_91 ;
break;
case V_92 :
V_31 = V_93 ;
break;
case V_94 :
V_31 = V_95 ;
break;
case V_96 :
V_31 = V_97 ;
break;
default:
return 0 ;
}
V_32 = V_98 ;
V_30 = F_1 ( V_1 ) ;
return F_7 ( V_4 -> V_49 , V_32 ,
V_99 << V_31 ,
V_30 << V_31 ) ;
}
static int F_22 ( struct V_72 * V_73 )
{
struct V_100 * V_101 = F_23 ( V_73 -> V_50 . V_88 ) ;
struct V_102 * V_103 = NULL ;
struct V_74 * V_75 = NULL ;
struct V_104 V_105 = { } ;
struct V_7 * V_8 ;
int V_77 , V_36 = 0 ;
const struct V_106 * V_107 ;
V_8 = F_24 ( & V_73 -> V_50 , sizeof( struct V_7 ) ,
V_108 ) ;
if ( ! V_8 )
return - V_109 ;
V_8 -> V_52 = F_25 ( V_73 ) -> V_110 ;
switch ( V_8 -> V_52 ) {
case V_111 :
V_8 -> V_89 = F_15 ( V_112 ) ;
V_107 = V_112 ;
break;
case V_53 :
V_8 -> V_89 = F_15 ( V_113 ) ;
V_107 = V_113 ;
break;
case V_59 :
V_8 -> V_89 = F_15 ( V_114 ) ;
V_107 = V_114 ;
break;
default:
F_8 ( & V_73 -> V_50 , L_6 ,
V_8 -> V_52 ) ;
return - V_61 ;
} ;
V_8 -> V_56 = F_24 ( & V_73 -> V_50 ,
sizeof( * V_8 -> V_56 ) * V_8 -> V_89 ,
V_108 ) ;
if ( ! V_8 -> V_56 )
return - V_109 ;
for ( V_77 = 0 ; V_77 < V_8 -> V_89 ; V_77 ++ )
V_8 -> V_56 [ V_77 ] = - V_61 ;
if ( ! V_101 -> V_50 -> V_84 ) {
if ( V_101 -> V_103 ) {
V_103 = V_101 -> V_103 ;
goto V_115;
} else {
F_8 ( V_73 -> V_50 . V_88 ,
L_7 ) ;
return - V_116 ;
}
}
V_75 = F_26 ( sizeof( * V_75 ) * V_8 -> V_89 , V_108 ) ;
if ( ! V_75 )
return - V_109 ;
for ( V_77 = 0 ; V_77 < V_8 -> V_89 ; V_77 ++ )
V_75 [ V_77 ] . V_85 = V_107 [ V_77 ] . V_85 ;
V_36 = F_18 ( V_73 , V_75 , V_8 ) ;
if ( V_36 )
goto V_117;
V_115:
F_27 ( V_73 , V_8 ) ;
V_105 . V_50 = & V_73 -> V_50 ;
V_105 . V_49 = V_101 -> V_118 ;
V_105 . V_110 = V_8 ;
V_105 . V_119 = V_120 ;
for ( V_77 = 0 ; V_77 < V_8 -> V_89 ; V_77 ++ ) {
struct V_3 * V_121 ;
if ( V_103 ) {
V_105 . V_83 = V_103 -> V_107 [ V_77 ] . V_122 ;
V_105 . V_84 = V_103 -> V_107 [ V_77 ] . V_123 ;
} else {
V_105 . V_83 = V_75 [ V_77 ] . V_83 ;
V_105 . V_84 = V_75 [ V_77 ] . V_84 ;
}
V_105 . V_124 = V_8 -> V_56 [ V_77 ] ;
V_121 = F_28 ( & V_73 -> V_50 ,
& V_107 [ V_77 ] , & V_105 ) ;
if ( F_29 ( V_121 ) ) {
V_36 = F_30 ( V_121 ) ;
F_8 ( & V_73 -> V_50 , L_8 ,
V_77 ) ;
goto V_117;
}
if ( F_10 ( V_8 -> V_56 [ V_77 ] ) ) {
V_36 = F_13 ( V_8 ,
V_121 ) ;
if ( V_36 < 0 ) {
F_8 ( & V_73 -> V_50 ,
L_9 ,
V_121 -> V_27 -> V_85 , V_36 ) ;
goto V_117;
}
}
}
V_117:
F_31 ( V_75 ) ;
return V_36 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_125 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_125 ) ;
}
