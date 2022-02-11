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
if ( V_8 -> V_52 & ( 1 << F_4 ( V_4 ) ) )
V_51 = V_53 ;
else if ( F_10 ( V_8 -> V_54 [ F_4 ( V_4 ) ] ) )
V_51 = V_55 ;
else
V_51 = V_4 -> V_27 -> V_56 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_57 ,
V_4 -> V_27 -> V_56 , V_51 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_36 ;
unsigned int V_51 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) == V_58 )
return 0 ;
V_36 = F_12 ( V_4 -> V_49 , V_4 -> V_27 -> V_57 , & V_51 ) ;
if ( V_36 < 0 )
return V_36 ;
V_8 -> V_52 |= ( 1 << F_4 ( V_4 ) ) ;
if ( ! ( V_51 & V_4 -> V_27 -> V_56 ) )
return 0 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_57 ,
V_4 -> V_27 -> V_56 , V_53 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_57 ,
V_4 -> V_27 -> V_56 , V_55 ) ;
}
static void F_14 ( struct V_59 * V_60 ,
struct V_61 * V_62 , struct V_7 * V_8 )
{
int * V_63 = V_8 -> V_54 ;
unsigned int V_64 ;
unsigned int V_65 [ 3 ] = { V_66 , V_67 ,
V_68 } ;
for ( V_64 = 0 ; V_64 < F_15 ( V_65 ) ; V_64 ++ ) {
unsigned int V_69 = V_65 [ V_64 ] ;
if ( ! V_62 [ V_69 ] . V_70 || ! V_62 [ V_69 ] . V_71 )
continue;
V_63 [ V_69 ] = F_16 ( V_62 [ V_69 ] . V_71 ,
L_2 , 0 ) ;
if ( F_10 ( V_63 [ V_69 ] ) )
F_17 ( & V_60 -> V_50 , L_3 ,
V_63 [ V_69 ] , V_69 , V_62 [ V_69 ] . V_72 ) ;
}
}
static int F_18 ( struct V_59 * V_60 ,
struct V_61 * V_62 , struct V_7 * V_8 ,
enum V_73 V_74 )
{
struct V_75 * V_76 ;
V_76 = F_19 ( V_60 -> V_50 . V_77 -> V_71 , L_4 ) ;
if ( ! V_76 ) {
F_8 ( & V_60 -> V_50 , L_5 ) ;
return - V_78 ;
}
V_61 ( & V_60 -> V_50 , V_76 , V_62 , V_8 -> V_79 ) ;
if ( V_74 == V_80 )
F_14 ( V_60 , V_62 , V_8 ) ;
F_20 ( V_76 ) ;
return 0 ;
}
static int F_21 ( struct V_59 * V_60 )
{
struct V_81 * V_82 = F_22 ( V_60 -> V_50 . V_77 ) ;
struct V_83 * V_84 = NULL ;
struct V_61 * V_62 = NULL ;
struct V_85 V_86 = { } ;
struct V_7 * V_8 ;
int V_64 , V_36 = 0 ;
const struct V_87 * V_88 ;
enum V_73 V_74 ;
V_8 = F_23 ( & V_60 -> V_50 , sizeof( struct V_7 ) ,
V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_74 = F_24 ( V_60 ) -> V_91 ;
switch ( V_74 ) {
case V_92 :
V_8 -> V_79 = F_15 ( V_93 ) ;
V_88 = V_93 ;
break;
case V_80 :
V_8 -> V_79 = F_15 ( V_94 ) ;
V_88 = V_94 ;
break;
default:
F_8 ( & V_60 -> V_50 , L_6 , V_74 ) ;
return - V_78 ;
} ;
V_8 -> V_54 = F_23 ( & V_60 -> V_50 ,
sizeof( * V_8 -> V_54 ) * V_8 -> V_79 ,
V_89 ) ;
if ( ! V_8 -> V_54 )
return - V_90 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_79 ; V_64 ++ )
V_8 -> V_54 [ V_64 ] = - V_78 ;
if ( ! V_82 -> V_50 -> V_71 ) {
if ( V_82 -> V_84 ) {
V_84 = V_82 -> V_84 ;
goto V_95;
} else {
F_8 ( V_60 -> V_50 . V_77 ,
L_7 ) ;
return - V_96 ;
}
}
V_62 = F_25 ( sizeof( * V_62 ) * V_8 -> V_79 , V_89 ) ;
if ( ! V_62 )
return - V_90 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_79 ; V_64 ++ )
V_62 [ V_64 ] . V_72 = V_88 [ V_64 ] . V_72 ;
V_36 = F_18 ( V_60 , V_62 , V_8 , V_74 ) ;
if ( V_36 )
goto V_97;
V_95:
F_26 ( V_60 , V_8 ) ;
V_86 . V_50 = & V_60 -> V_50 ;
V_86 . V_49 = V_82 -> V_98 ;
V_86 . V_91 = V_8 ;
V_86 . V_99 = V_100 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_79 ; V_64 ++ ) {
struct V_3 * V_101 ;
if ( V_84 ) {
V_86 . V_70 = V_84 -> V_88 [ V_64 ] . V_102 ;
V_86 . V_71 = V_84 -> V_88 [ V_64 ] . V_103 ;
} else {
V_86 . V_70 = V_62 [ V_64 ] . V_70 ;
V_86 . V_71 = V_62 [ V_64 ] . V_71 ;
}
V_86 . V_104 = V_8 -> V_54 [ V_64 ] ;
V_101 = F_27 ( & V_60 -> V_50 ,
& V_88 [ V_64 ] , & V_86 ) ;
if ( F_28 ( V_101 ) ) {
V_36 = F_29 ( V_101 ) ;
F_8 ( & V_60 -> V_50 , L_8 ,
V_64 ) ;
goto V_97;
}
if ( F_10 ( V_8 -> V_54 [ V_64 ] ) ) {
V_36 = F_13 ( V_8 ,
V_101 ) ;
if ( V_36 < 0 ) {
F_8 ( & V_60 -> V_50 ,
L_9 ,
V_101 -> V_27 -> V_72 , V_36 ) ;
goto V_97;
}
}
}
V_97:
F_30 ( V_62 ) ;
return V_36 ;
}
static int T_1 F_31 ( void )
{
return F_32 ( & V_105 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_105 ) ;
}
