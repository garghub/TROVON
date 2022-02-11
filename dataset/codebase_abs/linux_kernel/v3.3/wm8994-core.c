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
static int F_22 ( struct V_1 * V_1 , int V_49 )
{
struct V_42 * V_43 = V_1 -> V_10 -> V_50 ;
struct V_51 * V_51 ;
const char * V_52 ;
int V_4 , V_53 ;
int V_54 = 0 ;
F_23 ( V_1 -> V_10 , V_1 ) ;
V_4 = F_24 ( V_1 -> V_10 , - 1 ,
V_55 ,
F_25 ( V_55 ) ,
NULL , 0 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_56;
}
switch ( V_1 -> type ) {
case V_28 :
V_1 -> V_39 = F_25 ( V_57 ) ;
break;
case V_58 :
V_1 -> V_39 = F_25 ( V_59 ) ;
break;
case V_27 :
V_1 -> V_39 = F_25 ( V_60 ) ;
break;
default:
F_26 () ;
goto V_56;
}
V_1 -> V_40 = F_27 ( V_1 -> V_10 ,
sizeof( struct V_61 ) *
V_1 -> V_39 , V_62 ) ;
if ( ! V_1 -> V_40 ) {
V_4 = - V_63 ;
goto V_56;
}
switch ( V_1 -> type ) {
case V_28 :
for ( V_53 = 0 ; V_53 < F_25 ( V_57 ) ; V_53 ++ )
V_1 -> V_40 [ V_53 ] . V_64 = V_57 [ V_53 ] ;
break;
case V_58 :
for ( V_53 = 0 ; V_53 < F_25 ( V_59 ) ; V_53 ++ )
V_1 -> V_40 [ V_53 ] . V_64 = V_59 [ V_53 ] ;
break;
case V_27 :
for ( V_53 = 0 ; V_53 < F_25 ( V_60 ) ; V_53 ++ )
V_1 -> V_40 [ V_53 ] . V_64 = V_60 [ V_53 ] ;
break;
default:
F_26 () ;
goto V_56;
}
V_4 = F_28 ( V_1 -> V_10 , V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_8 , V_4 ) ;
goto V_56;
}
V_4 = F_19 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_5 , V_4 ) ;
goto V_65;
}
V_4 = F_1 ( V_1 , V_37 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_9 ) ;
goto V_41;
}
switch ( V_4 ) {
case 0x1811 :
V_52 = L_10 ;
if ( V_1 -> type != V_28 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_28 ;
break;
case 0x8994 :
V_52 = L_12 ;
if ( V_1 -> type != V_58 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_58 ;
break;
case 0x8958 :
V_52 = L_13 ;
if ( V_1 -> type != V_27 )
F_29 ( V_1 -> V_10 , L_11 ,
V_1 -> type ) ;
V_1 -> type = V_27 ;
break;
default:
F_13 ( V_1 -> V_10 , L_14 ,
V_4 ) ;
V_4 = - V_66 ;
goto V_41;
}
V_4 = F_1 ( V_1 , V_67 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_15 ,
V_4 ) ;
goto V_41;
}
V_1 -> V_68 = V_4 ;
switch ( V_1 -> type ) {
case V_58 :
switch ( V_1 -> V_68 ) {
case 0 :
case 1 :
F_29 ( V_1 -> V_10 ,
L_16 ,
'A' + V_1 -> V_68 ) ;
break;
default:
break;
}
break;
case V_28 :
if ( V_1 -> V_68 > 1 )
V_1 -> V_68 ++ ;
break;
default:
break;
}
F_30 ( V_1 -> V_10 , L_17 , V_52 ,
'A' + V_1 -> V_68 ) ;
switch ( V_1 -> type ) {
case V_28 :
V_51 = & V_69 ;
break;
case V_58 :
V_51 = & V_70 ;
break;
case V_27 :
V_51 = & V_71 ;
break;
default:
F_13 ( V_1 -> V_10 , L_18 , V_1 -> type ) ;
return - V_66 ;
}
V_4 = F_31 ( V_1 -> V_5 , V_51 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_19 ,
V_4 ) ;
return V_4 ;
}
if ( V_43 ) {
V_1 -> V_72 = V_43 -> V_72 ;
V_1 -> V_73 = V_43 -> V_73 ;
for ( V_53 = 0 ; V_53 < F_25 ( V_43 -> V_74 ) ; V_53 ++ ) {
if ( V_43 -> V_74 [ V_53 ] ) {
F_9 ( V_1 , V_75 + V_53 ,
0xffff ,
V_43 -> V_74 [ V_53 ] ) ;
}
}
V_1 -> V_33 = V_43 -> V_33 ;
if ( V_43 -> V_76 )
V_54 |= V_77 ;
}
F_9 ( V_1 , V_34 ,
V_35 | V_36 |
V_77 | V_78 ,
V_54 ) ;
for ( V_53 = 0 ; V_53 < V_79 ; V_53 ++ ) {
if ( F_21 ( V_43 , V_53 ) )
F_9 ( V_1 , V_80 + V_53 ,
V_81 , V_81 ) ;
else
F_9 ( V_1 , V_80 + V_53 ,
V_81 , 0 ) ;
}
F_32 ( V_1 ) ;
V_4 = F_24 ( V_1 -> V_10 , - 1 ,
V_82 , F_25 ( V_82 ) ,
NULL , 0 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_83;
}
F_33 ( V_1 -> V_10 ) ;
F_34 ( V_1 -> V_10 ) ;
return 0 ;
V_83:
F_35 ( V_1 ) ;
V_41:
F_17 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
V_65:
F_36 ( V_1 -> V_39 , V_1 -> V_40 ) ;
V_56:
F_37 ( V_1 -> V_5 ) ;
F_38 ( V_1 -> V_10 ) ;
return V_4 ;
}
static void F_39 ( struct V_1 * V_1 )
{
F_40 ( V_1 -> V_10 ) ;
F_38 ( V_1 -> V_10 ) ;
F_35 ( V_1 ) ;
F_17 ( V_1 -> V_39 ,
V_1 -> V_40 ) ;
F_36 ( V_1 -> V_39 , V_1 -> V_40 ) ;
F_37 ( V_1 -> V_5 ) ;
}
static int F_41 ( struct V_84 * V_85 ,
const struct V_86 * V_87 )
{
struct V_1 * V_1 ;
int V_4 ;
V_1 = F_27 ( & V_85 -> V_10 , sizeof( struct V_1 ) , V_62 ) ;
if ( V_1 == NULL )
return - V_63 ;
F_42 ( V_85 , V_1 ) ;
V_1 -> V_10 = & V_85 -> V_10 ;
V_1 -> V_49 = V_85 -> V_49 ;
V_1 -> type = V_87 -> V_88 ;
V_1 -> V_5 = F_43 ( V_85 , & V_89 ) ;
if ( F_44 ( V_1 -> V_5 ) ) {
V_4 = F_45 ( V_1 -> V_5 ) ;
F_13 ( V_1 -> V_10 , L_20 ,
V_4 ) ;
return V_4 ;
}
return F_22 ( V_1 , V_85 -> V_49 ) ;
}
static int F_46 ( struct V_84 * V_85 )
{
struct V_1 * V_1 = F_47 ( V_85 ) ;
F_39 ( V_1 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
int V_4 ;
V_4 = F_49 ( & V_90 ) ;
if ( V_4 != 0 )
F_50 ( L_21 , V_4 ) ;
return V_4 ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_90 ) ;
}
