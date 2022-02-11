int F_1 ( struct V_1 * V_1 , unsigned short V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_1 -> V_5 , V_2 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
else
return V_3 ;
}
int F_3 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_6 , T_1 * V_7 )
{
return F_4 ( V_1 -> V_5 , V_2 , V_7 , V_6 ) ;
}
int F_5 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_3 )
{
return F_6 ( V_1 -> V_5 , V_2 , V_3 ) ;
}
int F_7 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_6 , const T_1 * V_7 )
{
return F_8 ( V_1 -> V_5 , V_2 , V_7 , V_6 * sizeof( T_1 ) ) ;
}
int F_9 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_8 , unsigned short V_3 )
{
return F_10 ( V_1 -> V_5 , V_2 , V_8 , V_3 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_4 ;
V_4 = F_1 ( V_1 , V_11 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_1 , V_4 ) ;
} else if ( V_4 & V_12 ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
V_4 = F_1 ( V_1 , V_13 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_1 , V_4 ) ;
} else if ( V_4 & ( V_14 | V_15 |
V_16 | V_17 |
V_18 | V_19 ) ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
V_4 = F_1 ( V_1 , V_20 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_1 , V_4 ) ;
} else if ( V_4 & ( V_21 | V_22 |
V_23 | V_24 |
V_25 | V_26 ) ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
switch ( V_1 -> type ) {
case V_27 :
case V_28 :
V_4 = F_1 ( V_1 , V_29 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_1 , V_4 ) ;
} else if ( V_4 & V_30 ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
switch ( V_1 -> type ) {
case V_28 :
V_4 = F_1 ( V_1 , V_31 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_3 , V_4 ) ;
} else if ( V_4 & V_32 ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
switch ( V_1 -> type ) {
case V_28 :
V_4 = F_1 ( V_1 , V_31 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_3 , V_4 ) ;
} else if ( V_4 & V_32 ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
if ( ! V_1 -> V_33 )
F_9 ( V_1 , V_34 ,
V_35 | V_36 ,
V_35 | V_36 ) ;
F_5 ( V_1 , V_37 ,
F_1 ( V_1 , V_37 ) ) ;
F_15 ( V_1 -> V_5 ) ;
V_4 = F_16 ( V_1 -> V_5 , V_38 ,
V_39 ) ;
if ( V_4 != 0 )
F_13 ( V_10 , L_4 , V_4 ) ;
V_4 = F_16 ( V_1 -> V_5 ,
V_40 ,
V_40 ) ;
if ( V_4 != 0 )
F_13 ( V_10 , L_5 , V_4 ) ;
F_17 ( V_1 -> V_5 , true ) ;
V_1 -> V_41 = true ;
V_4 = F_18 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_6 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_4 ;
if ( ! V_1 -> V_41 )
return 0 ;
V_4 = F_20 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_7 , V_4 ) ;
return V_4 ;
}
F_17 ( V_1 -> V_5 , false ) ;
V_4 = F_21 ( V_1 -> V_5 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_8 , V_4 ) ;
goto V_44;
}
F_9 ( V_1 , V_34 ,
V_35 | V_36 ,
0 ) ;
V_1 -> V_41 = false ;
return 0 ;
V_44:
F_18 ( V_1 -> V_42 , V_1 -> V_43 ) ;
return V_4 ;
}
static int F_22 ( struct V_45 * V_46 , int V_47 )
{
struct V_48 * V_49 ;
if ( ! V_46 )
return 0 ;
V_49 = & V_46 -> V_47 [ V_47 ] ;
if ( ! V_49 -> V_50 )
return 0 ;
return V_49 -> V_50 -> V_51 != 0 ;
}
static int F_22 ( struct V_45 * V_46 , int V_47 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_52 * V_53 = V_1 -> V_10 -> V_54 ;
struct V_45 * V_46 = & V_1 -> V_46 ;
int V_55 ;
if ( ! V_53 )
return 0 ;
if ( F_24 ( V_53 , L_9 , V_46 -> V_56 ,
F_25 ( V_46 -> V_56 ) ) >= 0 ) {
for ( V_55 = 0 ; V_55 < F_25 ( V_46 -> V_56 ) ; V_55 ++ ) {
if ( V_1 -> V_46 . V_56 [ V_55 ] == 0 )
V_46 -> V_56 [ V_55 ]
= V_57 ;
}
}
F_24 ( V_53 , L_10 , V_46 -> V_58 ,
F_25 ( V_46 -> V_58 ) ) ;
V_46 -> V_59 = true ;
V_46 -> V_60 = true ;
if ( F_26 ( V_53 , L_11 , NULL ) )
V_46 -> V_59 = false ;
if ( F_26 ( V_53 , L_12 , NULL ) )
V_46 -> V_60 = false ;
if ( F_26 ( V_53 , L_13 , NULL ) )
V_46 -> V_61 = true ;
if ( F_26 ( V_53 , L_14 , NULL ) )
V_46 -> V_62 = true ;
if ( F_26 ( V_53 , L_15 , NULL ) )
V_46 -> V_62 = true ;
V_46 -> V_47 [ 0 ] . V_63 = F_27 ( V_53 , L_16 , 0 ) ;
if ( V_46 -> V_47 [ 0 ] . V_63 < 0 )
V_46 -> V_47 [ 0 ] . V_63 = 0 ;
V_46 -> V_47 [ 1 ] . V_63 = F_27 ( V_53 , L_17 , 0 ) ;
if ( V_46 -> V_47 [ 1 ] . V_63 < 0 )
V_46 -> V_47 [ 1 ] . V_63 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , int V_64 )
{
struct V_45 * V_46 ;
struct V_65 * V_65 ;
const struct V_66 * V_67 = NULL ;
const char * V_68 ;
int V_4 , V_55 , V_69 = 0 ;
int V_70 = 0 ;
if ( F_29 ( V_1 -> V_10 ) ) {
V_46 = F_29 ( V_1 -> V_10 ) ;
V_1 -> V_46 = * V_46 ;
}
V_46 = & V_1 -> V_46 ;
V_4 = F_23 ( V_1 ) ;
if ( V_4 != 0 )
return V_4 ;
F_30 ( V_1 -> V_10 , V_1 ) ;
V_4 = F_31 ( V_1 -> V_10 , - 1 ,
V_71 ,
F_25 ( V_71 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_18 , V_4 ) ;
goto V_72;
}
switch ( V_1 -> type ) {
case V_28 :
V_1 -> V_42 = F_25 ( V_73 ) ;
break;
case V_74 :
V_1 -> V_42 = F_25 ( V_75 ) ;
break;
case V_27 :
V_1 -> V_42 = F_25 ( V_76 ) ;
break;
default:
F_32 () ;
goto V_72;
}
V_1 -> V_43 = F_33 ( V_1 -> V_10 ,
sizeof( struct V_77 ) *
V_1 -> V_42 , V_78 ) ;
if ( ! V_1 -> V_43 ) {
V_4 = - V_79 ;
goto V_72;
}
switch ( V_1 -> type ) {
case V_28 :
for ( V_55 = 0 ; V_55 < F_25 ( V_73 ) ; V_55 ++ )
V_1 -> V_43 [ V_55 ] . V_80 = V_73 [ V_55 ] ;
break;
case V_74 :
for ( V_55 = 0 ; V_55 < F_25 ( V_75 ) ; V_55 ++ )
V_1 -> V_43 [ V_55 ] . V_80 = V_75 [ V_55 ] ;
break;
case V_27 :
for ( V_55 = 0 ; V_55 < F_25 ( V_76 ) ; V_55 ++ )
V_1 -> V_43 [ V_55 ] . V_80 = V_76 [ V_55 ] ;
break;
default:
F_32 () ;
goto V_72;
}
V_4 = F_34 ( V_1 -> V_10 , V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_19 , V_4 ) ;
goto V_72;
}
V_4 = F_20 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_72;
}
V_4 = F_1 ( V_1 , V_37 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_20 ) ;
goto V_44;
}
switch ( V_4 ) {
case 0x1811 :
V_68 = L_21 ;
if ( V_1 -> type != V_28 )
F_35 ( V_1 -> V_10 , L_22 ,
V_1 -> type ) ;
V_1 -> type = V_28 ;
break;
case 0x8994 :
V_68 = L_23 ;
if ( V_1 -> type != V_74 )
F_35 ( V_1 -> V_10 , L_22 ,
V_1 -> type ) ;
V_1 -> type = V_74 ;
break;
case 0x8958 :
V_68 = L_24 ;
if ( V_1 -> type != V_27 )
F_35 ( V_1 -> V_10 , L_22 ,
V_1 -> type ) ;
V_1 -> type = V_27 ;
break;
default:
F_13 ( V_1 -> V_10 , L_25 ,
V_4 ) ;
V_4 = - V_81 ;
goto V_44;
}
V_4 = F_1 ( V_1 , V_82 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_26 ,
V_4 ) ;
goto V_44;
}
V_1 -> V_83 = V_4 & V_84 ;
V_1 -> V_85 = ( V_4 & V_86 ) >> V_87 ;
switch ( V_1 -> type ) {
case V_74 :
switch ( V_1 -> V_83 ) {
case 0 :
case 1 :
F_35 ( V_1 -> V_10 ,
L_27 ,
'A' + V_1 -> V_83 ) ;
break;
case 2 :
case 3 :
default:
V_67 = V_88 ;
V_69 = F_25 ( V_88 ) ;
break;
}
break;
case V_27 :
switch ( V_1 -> V_83 ) {
case 0 :
V_67 = V_89 ;
V_69 = F_25 ( V_89 ) ;
break;
default:
break;
}
break;
case V_28 :
if ( V_1 -> V_83 > 1 )
V_1 -> V_83 ++ ;
V_67 = V_90 ;
V_69 = F_25 ( V_90 ) ;
break;
default:
break;
}
F_36 ( V_1 -> V_10 , L_28 , V_68 ,
'A' + V_1 -> V_83 , V_1 -> V_85 ) ;
switch ( V_1 -> type ) {
case V_28 :
V_65 = & V_91 ;
break;
case V_74 :
V_65 = & V_92 ;
break;
case V_27 :
V_65 = & V_93 ;
break;
default:
F_13 ( V_1 -> V_10 , L_29 , V_1 -> type ) ;
return - V_81 ;
}
V_4 = F_37 ( V_1 -> V_5 , V_65 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_30 ,
V_4 ) ;
return V_4 ;
}
if ( V_67 ) {
V_4 = F_38 ( V_1 -> V_5 , V_67 ,
V_69 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_31 ,
V_4 ) ;
goto V_72;
}
}
V_1 -> V_94 = V_46 -> V_94 ;
V_1 -> V_95 = V_46 -> V_95 ;
for ( V_55 = 0 ; V_55 < F_25 ( V_46 -> V_56 ) ; V_55 ++ ) {
if ( V_46 -> V_56 [ V_55 ] ) {
F_9 ( V_1 , V_38 + V_55 ,
0xffff , V_46 -> V_56 [ V_55 ] ) ;
}
}
V_1 -> V_33 = V_46 -> V_33 ;
if ( V_46 -> V_96 )
V_70 |= V_97 ;
F_9 ( V_1 , V_34 ,
V_35 | V_36 |
V_97 | V_98 ,
V_70 ) ;
for ( V_55 = 0 ; V_55 < V_99 ; V_55 ++ ) {
if ( F_22 ( V_46 , V_55 ) )
F_9 ( V_1 , V_100 + V_55 ,
V_101 , V_101 ) ;
else
F_9 ( V_1 , V_100 + V_55 ,
V_101 , 0 ) ;
}
F_39 ( V_1 ) ;
V_4 = F_31 ( V_1 -> V_10 , - 1 ,
V_102 , F_25 ( V_102 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_18 , V_4 ) ;
goto V_103;
}
F_40 ( V_1 -> V_10 ) ;
F_41 ( V_1 -> V_10 ) ;
return 0 ;
V_103:
F_42 ( V_1 ) ;
V_44:
F_18 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
V_72:
F_43 ( V_1 -> V_10 ) ;
return V_4 ;
}
static void F_44 ( struct V_1 * V_1 )
{
F_45 ( V_1 -> V_10 ) ;
F_43 ( V_1 -> V_10 ) ;
F_42 ( V_1 ) ;
F_18 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
}
static int F_46 ( struct V_104 * V_105 ,
const struct V_106 * V_107 )
{
const struct V_108 * V_109 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = F_33 ( & V_105 -> V_10 , sizeof( struct V_1 ) , V_78 ) ;
if ( V_1 == NULL )
return - V_79 ;
F_47 ( V_105 , V_1 ) ;
V_1 -> V_10 = & V_105 -> V_10 ;
V_1 -> V_64 = V_105 -> V_64 ;
if ( V_105 -> V_10 . V_54 ) {
V_109 = F_48 ( V_110 , & V_105 -> V_10 ) ;
if ( V_109 )
V_1 -> type = ( int ) V_109 -> V_111 ;
} else {
V_1 -> type = V_107 -> V_112 ;
}
V_1 -> V_5 = F_49 ( V_105 , & V_113 ) ;
if ( F_50 ( V_1 -> V_5 ) ) {
V_4 = F_51 ( V_1 -> V_5 ) ;
F_13 ( V_1 -> V_10 , L_32 ,
V_4 ) ;
return V_4 ;
}
return F_28 ( V_1 , V_105 -> V_64 ) ;
}
static int F_52 ( struct V_104 * V_105 )
{
struct V_1 * V_1 = F_53 ( V_105 ) ;
F_44 ( V_1 ) ;
return 0 ;
}
