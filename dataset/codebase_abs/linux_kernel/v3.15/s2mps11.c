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
V_36 = F_7 ( V_4 -> V_49 , V_40 ,
1 << V_35 , 1 << V_35 ) ;
if ( V_36 ) {
F_8 ( & V_4 -> V_50 , L_1 ) ;
return V_36 ;
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
else
V_51 = V_4 -> V_27 -> V_54 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_55 ,
V_4 -> V_27 -> V_54 , V_51 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
int V_36 ;
unsigned int V_51 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) == V_56 )
return 0 ;
V_36 = F_11 ( V_4 -> V_49 , V_4 -> V_27 -> V_55 , & V_51 ) ;
if ( V_36 < 0 )
return V_36 ;
V_8 -> V_52 |= ( 1 << F_4 ( V_4 ) ) ;
if ( ! ( V_51 & V_4 -> V_27 -> V_54 ) )
return 0 ;
return F_7 ( V_4 -> V_49 , V_4 -> V_27 -> V_55 ,
V_4 -> V_27 -> V_54 , V_53 ) ;
}
static int F_12 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_13 ( V_58 -> V_50 . V_61 ) ;
struct V_62 * V_63 = V_60 -> V_63 ;
struct V_64 * V_65 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_68 V_69 = { } ;
struct V_7 * V_8 ;
int V_70 , V_36 = 0 ;
const struct V_71 * V_72 ;
enum V_73 V_74 ;
V_8 = F_14 ( & V_58 -> V_50 , sizeof( struct V_7 ) ,
V_75 ) ;
if ( ! V_8 )
return - V_76 ;
V_74 = F_15 ( V_58 ) -> V_77 ;
switch ( V_74 ) {
case V_78 :
V_8 -> V_79 = F_16 ( V_80 ) ;
V_72 = V_80 ;
break;
case V_81 :
V_8 -> V_79 = F_16 ( V_82 ) ;
V_72 = V_82 ;
break;
default:
F_8 ( & V_58 -> V_50 , L_2 , V_74 ) ;
return - V_83 ;
} ;
if ( ! V_60 -> V_50 -> V_84 ) {
if ( V_63 ) {
goto V_85;
} else {
F_8 ( V_58 -> V_50 . V_61 ,
L_3 ) ;
return - V_86 ;
}
}
V_65 = F_17 ( sizeof( * V_65 ) * V_8 -> V_79 , V_75 ) ;
if ( ! V_65 )
return - V_76 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_79 ; V_70 ++ )
V_65 [ V_70 ] . V_87 = V_72 [ V_70 ] . V_87 ;
V_67 = F_18 ( V_60 -> V_50 -> V_84 , L_4 ) ;
if ( ! V_67 ) {
F_8 ( & V_58 -> V_50 , L_5 ) ;
V_36 = - V_83 ;
goto V_88;
}
V_64 ( & V_58 -> V_50 , V_67 , V_65 , V_8 -> V_79 ) ;
F_19 ( V_67 ) ;
V_85:
F_20 ( V_58 , V_8 ) ;
V_69 . V_50 = & V_58 -> V_50 ;
V_69 . V_49 = V_60 -> V_89 ;
V_69 . V_77 = V_8 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_79 ; V_70 ++ ) {
struct V_3 * V_90 ;
if ( ! V_67 ) {
V_69 . V_91 = V_63 -> V_72 [ V_70 ] . V_92 ;
V_69 . V_84 = V_63 -> V_72 [ V_70 ] . V_93 ;
} else {
V_69 . V_91 = V_65 [ V_70 ] . V_91 ;
V_69 . V_84 = V_65 [ V_70 ] . V_84 ;
}
V_90 = F_21 ( & V_58 -> V_50 ,
& V_72 [ V_70 ] , & V_69 ) ;
if ( F_22 ( V_90 ) ) {
V_36 = F_23 ( V_90 ) ;
F_8 ( & V_58 -> V_50 , L_6 ,
V_70 ) ;
goto V_88;
}
}
V_88:
F_24 ( V_65 ) ;
return V_36 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_94 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_94 ) ;
}
