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
F_15 ( V_1 -> V_5 , true ) ;
F_16 ( V_1 -> V_5 ) ;
V_1 -> V_38 = true ;
V_4 = F_17 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_4 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_4 ;
if ( ! V_1 -> V_38 )
return 0 ;
V_4 = F_19 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_5 , V_4 ) ;
return V_4 ;
}
F_15 ( V_1 -> V_5 , false ) ;
V_4 = F_20 ( V_1 -> V_5 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_6 , V_4 ) ;
goto V_41;
}
F_9 ( V_1 , V_34 ,
V_35 | V_36 ,
0 ) ;
V_1 -> V_38 = false ;
return 0 ;
V_41:
F_17 ( V_1 -> V_39 , V_1 -> V_40 ) ;
return V_4 ;
}
static int F_21 ( struct V_42 * V_43 , int V_44 )
{
struct V_45 * V_46 ;
if ( ! V_43 )
return 0 ;
V_46 = & V_43 -> V_44 [ V_44 ] ;
if ( ! V_46 -> V_47 )
return 0 ;
return V_46 -> V_47 -> V_48 != 0 ;
}
static int F_21 ( struct V_42 * V_43 , int V_44 )
{
return 0 ;
}
static T_2 int F_22 ( struct V_1 * V_1 , int V_49 )
{
struct V_42 * V_43 = V_1 -> V_10 -> V_50 ;
struct V_51 * V_51 ;
const struct V_52 * V_53 = NULL ;
const char * V_54 ;
int V_4 , V_55 , V_56 ;
int V_57 = 0 ;
F_23 ( V_1 -> V_10 , V_1 ) ;
V_4 = F_24 ( V_1 -> V_10 , - 1 ,
V_58 ,
F_25 ( V_58 ) ,
NULL , 0 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_59;
}
switch ( V_1 -> type ) {
case V_28 :
V_1 -> V_39 = F_25 ( V_60 ) ;
break;
case V_61 :
V_1 -> V_39 = F_25 ( V_62 ) ;
break;
case V_27 :
V_1 -> V_39 = F_25 ( V_63 ) ;
break;
default:
F_26 () ;
goto V_59;
}
V_1 -> V_40 = F_27 ( V_1 -> V_10 ,
sizeof( struct V_64 ) *
V_1 -> V_39 , V_65 ) ;
if ( ! V_1 -> V_40 ) {
V_4 = - V_66 ;
goto V_59;
}
switch ( V_1 -> type ) {
case V_28 :
for ( V_55 = 0 ; V_55 < F_25 ( V_60 ) ; V_55 ++ )
V_1 -> V_40 [ V_55 ] . V_67 = V_60 [ V_55 ] ;
break;
case V_61 :
for ( V_55 = 0 ; V_55 < F_25 ( V_62 ) ; V_55 ++ )
V_1 -> V_40 [ V_55 ] . V_67 = V_62 [ V_55 ] ;
break;
case V_27 :
for ( V_55 = 0 ; V_55 < F_25 ( V_63 ) ; V_55 ++ )
V_1 -> V_40 [ V_55 ] . V_67 = V_63 [ V_55 ] ;
break;
default:
F_26 () ;
goto V_59;
}
V_4 = F_28 ( V_1 -> V_10 , V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_8 , V_4 ) ;
goto V_59;
}
V_4 = F_19 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_5 , V_4 ) ;
goto V_68;
}
V_4 = F_1 ( V_1 , V_37 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_9 ) ;
goto V_41;
}
switch ( V_4 ) {
case 0x1811 :
V_54 = L_10 ;
if ( V_1 -> type != V_28 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_28 ;
break;
case 0x8994 :
V_54 = L_12 ;
if ( V_1 -> type != V_61 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_61 ;
break;
case 0x8958 :
V_54 = L_13 ;
if ( V_1 -> type != V_27 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_27 ;
break;
default:
F_13 ( V_1 -> V_10 , L_14 ,
V_4 ) ;
V_4 = - V_69 ;
goto V_41;
}
V_4 = F_1 ( V_1 , V_70 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_15 ,
V_4 ) ;
goto V_41;
}
V_1 -> V_71 = V_4 ;
switch ( V_1 -> type ) {
case V_61 :
switch ( V_1 -> V_71 ) {
case 0 :
case 1 :
F_29 ( V_1 -> V_10 ,
L_16 ,
'A' + V_1 -> V_71 ) ;
break;
case 2 :
case 3 :
V_53 = V_72 ;
V_56 = F_25 ( V_72 ) ;
break;
default:
break;
}
break;
case V_27 :
switch ( V_1 -> V_71 ) {
case 0 :
V_53 = V_73 ;
V_56 = F_25 ( V_73 ) ;
break;
default:
break;
}
break;
case V_28 :
if ( V_1 -> V_71 > 1 )
V_1 -> V_71 ++ ;
switch ( V_1 -> V_71 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_53 = V_74 ;
V_56 = F_25 ( V_74 ) ;
break;
default:
break;
}
break;
default:
break;
}
F_30 ( V_1 -> V_10 , L_17 , V_54 ,
'A' + V_1 -> V_71 ) ;
switch ( V_1 -> type ) {
case V_28 :
V_51 = & V_75 ;
break;
case V_61 :
V_51 = & V_76 ;
break;
case V_27 :
V_51 = & V_77 ;
break;
default:
F_13 ( V_1 -> V_10 , L_18 , V_1 -> type ) ;
return - V_69 ;
}
V_4 = F_31 ( V_1 -> V_5 , V_51 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_19 ,
V_4 ) ;
return V_4 ;
}
if ( V_53 ) {
V_4 = F_32 ( V_1 -> V_5 , V_53 ,
V_56 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_20 ,
V_4 ) ;
goto V_59;
}
}
if ( V_43 ) {
V_1 -> V_78 = V_43 -> V_78 ;
V_1 -> V_79 = V_43 -> V_79 ;
for ( V_55 = 0 ; V_55 < F_25 ( V_43 -> V_80 ) ; V_55 ++ ) {
if ( V_43 -> V_80 [ V_55 ] ) {
F_9 ( V_1 , V_81 + V_55 ,
0xffff ,
V_43 -> V_80 [ V_55 ] ) ;
}
}
V_1 -> V_33 = V_43 -> V_33 ;
if ( V_43 -> V_82 )
V_57 |= V_83 ;
}
F_9 ( V_1 , V_34 ,
V_35 | V_36 |
V_83 | V_84 ,
V_57 ) ;
for ( V_55 = 0 ; V_55 < V_85 ; V_55 ++ ) {
if ( F_21 ( V_43 , V_55 ) )
F_9 ( V_1 , V_86 + V_55 ,
V_87 , V_87 ) ;
else
F_9 ( V_1 , V_86 + V_55 ,
V_87 , 0 ) ;
}
F_33 ( V_1 ) ;
V_4 = F_24 ( V_1 -> V_10 , - 1 ,
V_88 , F_25 ( V_88 ) ,
NULL , 0 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_89;
}
F_34 ( V_1 -> V_10 ) ;
F_35 ( V_1 -> V_10 ) ;
return 0 ;
V_89:
F_36 ( V_1 ) ;
V_41:
F_17 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
V_68:
F_37 ( V_1 -> V_39 , V_1 -> V_40 ) ;
V_59:
F_38 ( V_1 -> V_10 ) ;
return V_4 ;
}
static T_3 void F_39 ( struct V_1 * V_1 )
{
F_40 ( V_1 -> V_10 ) ;
F_38 ( V_1 -> V_10 ) ;
F_36 ( V_1 ) ;
F_17 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
F_37 ( V_1 -> V_39 , V_1 -> V_40 ) ;
}
static T_2 int F_41 ( struct V_90 * V_91 ,
const struct V_92 * V_93 )
{
struct V_1 * V_1 ;
int V_4 ;
V_1 = F_27 ( & V_91 -> V_10 , sizeof( struct V_1 ) , V_65 ) ;
if ( V_1 == NULL )
return - V_66 ;
F_42 ( V_91 , V_1 ) ;
V_1 -> V_10 = & V_91 -> V_10 ;
V_1 -> V_49 = V_91 -> V_49 ;
V_1 -> type = V_93 -> V_94 ;
V_1 -> V_5 = F_43 ( V_91 , & V_95 ) ;
if ( F_44 ( V_1 -> V_5 ) ) {
V_4 = F_45 ( V_1 -> V_5 ) ;
F_13 ( V_1 -> V_10 , L_21 ,
V_4 ) ;
return V_4 ;
}
return F_22 ( V_1 , V_91 -> V_49 ) ;
}
static T_3 int F_46 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = F_47 ( V_91 ) ;
F_39 ( V_1 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
int V_4 ;
V_4 = F_49 ( & V_96 ) ;
if ( V_4 != 0 )
F_50 ( L_22 , V_4 ) ;
return V_4 ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_96 ) ;
}
