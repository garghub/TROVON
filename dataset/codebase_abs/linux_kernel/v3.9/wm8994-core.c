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
static int F_23 ( struct V_1 * V_1 , int V_52 )
{
struct V_45 * V_46 ;
struct V_53 * V_53 ;
const struct V_54 * V_55 = NULL ;
const char * V_56 ;
int V_4 , V_57 , V_58 ;
int V_59 = 0 ;
if ( F_24 ( V_1 -> V_10 ) ) {
V_46 = F_24 ( V_1 -> V_10 ) ;
V_1 -> V_46 = * V_46 ;
}
V_46 = & V_1 -> V_46 ;
F_25 ( V_1 -> V_10 , V_1 ) ;
V_4 = F_26 ( V_1 -> V_10 , - 1 ,
V_60 ,
F_27 ( V_60 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_9 , V_4 ) ;
goto V_61;
}
switch ( V_1 -> type ) {
case V_28 :
V_1 -> V_42 = F_27 ( V_62 ) ;
break;
case V_63 :
V_1 -> V_42 = F_27 ( V_64 ) ;
break;
case V_27 :
V_1 -> V_42 = F_27 ( V_65 ) ;
break;
default:
F_28 () ;
goto V_61;
}
V_1 -> V_43 = F_29 ( V_1 -> V_10 ,
sizeof( struct V_66 ) *
V_1 -> V_42 , V_67 ) ;
if ( ! V_1 -> V_43 ) {
V_4 = - V_68 ;
goto V_61;
}
switch ( V_1 -> type ) {
case V_28 :
for ( V_57 = 0 ; V_57 < F_27 ( V_62 ) ; V_57 ++ )
V_1 -> V_43 [ V_57 ] . V_69 = V_62 [ V_57 ] ;
break;
case V_63 :
for ( V_57 = 0 ; V_57 < F_27 ( V_64 ) ; V_57 ++ )
V_1 -> V_43 [ V_57 ] . V_69 = V_64 [ V_57 ] ;
break;
case V_27 :
for ( V_57 = 0 ; V_57 < F_27 ( V_65 ) ; V_57 ++ )
V_1 -> V_43 [ V_57 ] . V_69 = V_65 [ V_57 ] ;
break;
default:
F_28 () ;
goto V_61;
}
V_4 = F_30 ( V_1 -> V_10 , V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_10 , V_4 ) ;
goto V_61;
}
V_4 = F_20 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_7 , V_4 ) ;
goto V_61;
}
V_4 = F_1 ( V_1 , V_37 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_11 ) ;
goto V_44;
}
switch ( V_4 ) {
case 0x1811 :
V_56 = L_12 ;
if ( V_1 -> type != V_28 )
F_31 ( V_1 -> V_10 , L_13 ,
V_1 -> type ) ;
V_1 -> type = V_28 ;
break;
case 0x8994 :
V_56 = L_14 ;
if ( V_1 -> type != V_63 )
F_31 ( V_1 -> V_10 , L_13 ,
V_1 -> type ) ;
V_1 -> type = V_63 ;
break;
case 0x8958 :
V_56 = L_15 ;
if ( V_1 -> type != V_27 )
F_31 ( V_1 -> V_10 , L_13 ,
V_1 -> type ) ;
V_1 -> type = V_27 ;
break;
default:
F_13 ( V_1 -> V_10 , L_16 ,
V_4 ) ;
V_4 = - V_70 ;
goto V_44;
}
V_4 = F_1 ( V_1 , V_71 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_17 ,
V_4 ) ;
goto V_44;
}
V_1 -> V_72 = V_4 & V_73 ;
V_1 -> V_74 = ( V_4 & V_75 ) >> V_76 ;
switch ( V_1 -> type ) {
case V_63 :
switch ( V_1 -> V_72 ) {
case 0 :
case 1 :
F_31 ( V_1 -> V_10 ,
L_18 ,
'A' + V_1 -> V_72 ) ;
break;
case 2 :
case 3 :
default:
V_55 = V_77 ;
V_58 = F_27 ( V_77 ) ;
break;
}
break;
case V_27 :
switch ( V_1 -> V_72 ) {
case 0 :
V_55 = V_78 ;
V_58 = F_27 ( V_78 ) ;
break;
default:
break;
}
break;
case V_28 :
if ( V_1 -> V_72 > 1 )
V_1 -> V_72 ++ ;
V_55 = V_79 ;
V_58 = F_27 ( V_79 ) ;
break;
default:
break;
}
F_32 ( V_1 -> V_10 , L_19 , V_56 ,
'A' + V_1 -> V_72 , V_1 -> V_74 ) ;
switch ( V_1 -> type ) {
case V_28 :
V_53 = & V_80 ;
break;
case V_63 :
V_53 = & V_81 ;
break;
case V_27 :
V_53 = & V_82 ;
break;
default:
F_13 ( V_1 -> V_10 , L_20 , V_1 -> type ) ;
return - V_70 ;
}
V_4 = F_33 ( V_1 -> V_5 , V_53 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_21 ,
V_4 ) ;
return V_4 ;
}
if ( V_55 ) {
V_4 = F_34 ( V_1 -> V_5 , V_55 ,
V_58 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_22 ,
V_4 ) ;
goto V_61;
}
}
V_1 -> V_83 = V_46 -> V_83 ;
V_1 -> V_84 = V_46 -> V_84 ;
for ( V_57 = 0 ; V_57 < F_27 ( V_46 -> V_85 ) ; V_57 ++ ) {
if ( V_46 -> V_85 [ V_57 ] ) {
F_9 ( V_1 , V_38 + V_57 ,
0xffff , V_46 -> V_85 [ V_57 ] ) ;
}
}
V_1 -> V_33 = V_46 -> V_33 ;
if ( V_46 -> V_86 )
V_59 |= V_87 ;
F_9 ( V_1 , V_34 ,
V_35 | V_36 |
V_87 | V_88 ,
V_59 ) ;
for ( V_57 = 0 ; V_57 < V_89 ; V_57 ++ ) {
if ( F_22 ( V_46 , V_57 ) )
F_9 ( V_1 , V_90 + V_57 ,
V_91 , V_91 ) ;
else
F_9 ( V_1 , V_90 + V_57 ,
V_91 , 0 ) ;
}
F_35 ( V_1 ) ;
V_4 = F_26 ( V_1 -> V_10 , - 1 ,
V_92 , F_27 ( V_92 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_9 , V_4 ) ;
goto V_93;
}
F_36 ( V_1 -> V_10 ) ;
F_37 ( V_1 -> V_10 ) ;
return 0 ;
V_93:
F_38 ( V_1 ) ;
V_44:
F_18 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
V_61:
F_39 ( V_1 -> V_10 ) ;
return V_4 ;
}
static void F_40 ( struct V_1 * V_1 )
{
F_41 ( V_1 -> V_10 ) ;
F_39 ( V_1 -> V_10 ) ;
F_38 ( V_1 ) ;
F_18 ( V_1 -> V_42 ,
V_1 -> V_43 ) ;
}
static int F_42 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_1 * V_1 ;
int V_4 ;
V_1 = F_29 ( & V_95 -> V_10 , sizeof( struct V_1 ) , V_67 ) ;
if ( V_1 == NULL )
return - V_68 ;
F_43 ( V_95 , V_1 ) ;
V_1 -> V_10 = & V_95 -> V_10 ;
V_1 -> V_52 = V_95 -> V_52 ;
V_1 -> type = V_97 -> V_98 ;
V_1 -> V_5 = F_44 ( V_95 , & V_99 ) ;
if ( F_45 ( V_1 -> V_5 ) ) {
V_4 = F_46 ( V_1 -> V_5 ) ;
F_13 ( V_1 -> V_10 , L_23 ,
V_4 ) ;
return V_4 ;
}
return F_23 ( V_1 , V_95 -> V_52 ) ;
}
static int F_47 ( struct V_94 * V_95 )
{
struct V_1 * V_1 = F_48 ( V_95 ) ;
F_40 ( V_1 ) ;
return 0 ;
}
