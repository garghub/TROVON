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
switch ( V_1 -> type ) {
case V_11 :
case V_12 :
V_4 = F_1 ( V_1 , V_13 ) ;
if ( V_4 < 0 ) {
F_13 ( V_10 , L_1 , V_4 ) ;
} else if ( V_4 & V_14 ) {
F_14 ( V_10 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
if ( ! V_1 -> V_15 )
F_9 ( V_1 , V_16 ,
V_17 | V_18 ,
V_17 | V_18 ) ;
F_5 ( V_1 , V_19 ,
F_1 ( V_1 , V_19 ) ) ;
F_15 ( V_1 -> V_5 ) ;
V_4 = F_16 ( V_1 -> V_5 , V_20 ,
V_21 ) ;
if ( V_4 != 0 )
F_13 ( V_10 , L_3 , V_4 ) ;
V_4 = F_16 ( V_1 -> V_5 ,
V_22 ,
V_22 ) ;
if ( V_4 != 0 )
F_13 ( V_10 , L_4 , V_4 ) ;
F_17 ( V_1 -> V_5 , true ) ;
V_1 -> V_23 = true ;
V_4 = F_18 ( V_1 -> V_24 ,
V_1 -> V_25 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_5 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_12 ( V_10 ) ;
int V_4 ;
if ( ! V_1 -> V_23 )
return 0 ;
V_4 = F_20 ( V_1 -> V_24 ,
V_1 -> V_25 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_6 , V_4 ) ;
return V_4 ;
}
F_17 ( V_1 -> V_5 , false ) ;
V_4 = F_21 ( V_1 -> V_5 ) ;
if ( V_4 != 0 ) {
F_13 ( V_10 , L_7 , V_4 ) ;
goto V_26;
}
F_9 ( V_1 , V_16 ,
V_17 | V_18 ,
0 ) ;
V_1 -> V_23 = false ;
return 0 ;
V_26:
F_18 ( V_1 -> V_24 , V_1 -> V_25 ) ;
return V_4 ;
}
static int F_22 ( struct V_27 * V_28 , int V_29 )
{
struct V_30 * V_31 ;
if ( ! V_28 )
return 0 ;
V_31 = & V_28 -> V_29 [ V_29 ] ;
if ( ! V_31 -> V_32 )
return 0 ;
return V_31 -> V_32 -> V_33 != 0 ;
}
static int F_22 ( struct V_27 * V_28 , int V_29 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_34 * V_35 = V_1 -> V_10 -> V_36 ;
struct V_27 * V_28 = & V_1 -> V_28 ;
int V_37 ;
if ( ! V_35 )
return 0 ;
if ( F_24 ( V_35 , L_8 , V_28 -> V_38 ,
F_25 ( V_28 -> V_38 ) ) >= 0 ) {
for ( V_37 = 0 ; V_37 < F_25 ( V_28 -> V_38 ) ; V_37 ++ ) {
if ( V_1 -> V_28 . V_38 [ V_37 ] == 0 )
V_28 -> V_38 [ V_37 ]
= V_39 ;
}
}
F_24 ( V_35 , L_9 , V_28 -> V_40 ,
F_25 ( V_28 -> V_40 ) ) ;
V_28 -> V_41 = true ;
V_28 -> V_42 = true ;
if ( F_26 ( V_35 , L_10 , NULL ) )
V_28 -> V_41 = false ;
if ( F_26 ( V_35 , L_11 , NULL ) )
V_28 -> V_42 = false ;
if ( F_26 ( V_35 , L_12 , NULL ) )
V_28 -> V_43 = true ;
if ( F_26 ( V_35 , L_13 , NULL ) )
V_28 -> V_44 = true ;
if ( F_26 ( V_35 , L_14 , NULL ) )
V_28 -> V_44 = true ;
V_28 -> V_29 [ 0 ] . V_45 = F_27 ( V_35 , L_15 , 0 ) ;
if ( V_28 -> V_29 [ 0 ] . V_45 < 0 )
V_28 -> V_29 [ 0 ] . V_45 = 0 ;
V_28 -> V_29 [ 1 ] . V_45 = F_27 ( V_35 , L_16 , 0 ) ;
if ( V_28 -> V_29 [ 1 ] . V_45 < 0 )
V_28 -> V_29 [ 1 ] . V_45 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , int V_46 )
{
struct V_27 * V_28 ;
struct V_47 * V_47 ;
const struct V_48 * V_49 = NULL ;
const char * V_50 ;
int V_4 , V_37 , V_51 = 0 ;
int V_52 = 0 ;
if ( F_29 ( V_1 -> V_10 ) ) {
V_28 = F_29 ( V_1 -> V_10 ) ;
V_1 -> V_28 = * V_28 ;
}
V_28 = & V_1 -> V_28 ;
V_4 = F_23 ( V_1 ) ;
if ( V_4 != 0 )
return V_4 ;
F_30 ( V_1 -> V_10 , V_1 ) ;
V_4 = F_31 ( V_1 -> V_10 , - 1 ,
V_53 ,
F_25 ( V_53 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_17 , V_4 ) ;
goto V_54;
}
switch ( V_1 -> type ) {
case V_12 :
V_1 -> V_24 = F_25 ( V_55 ) ;
break;
case V_56 :
V_1 -> V_24 = F_25 ( V_57 ) ;
break;
case V_11 :
V_1 -> V_24 = F_25 ( V_58 ) ;
break;
default:
F_32 () ;
goto V_54;
}
V_1 -> V_25 = F_33 ( V_1 -> V_10 ,
sizeof( struct V_59 ) *
V_1 -> V_24 , V_60 ) ;
if ( ! V_1 -> V_25 ) {
V_4 = - V_61 ;
goto V_54;
}
switch ( V_1 -> type ) {
case V_12 :
for ( V_37 = 0 ; V_37 < F_25 ( V_55 ) ; V_37 ++ )
V_1 -> V_25 [ V_37 ] . V_62 = V_55 [ V_37 ] ;
break;
case V_56 :
for ( V_37 = 0 ; V_37 < F_25 ( V_57 ) ; V_37 ++ )
V_1 -> V_25 [ V_37 ] . V_62 = V_57 [ V_37 ] ;
break;
case V_11 :
for ( V_37 = 0 ; V_37 < F_25 ( V_58 ) ; V_37 ++ )
V_1 -> V_25 [ V_37 ] . V_62 = V_58 [ V_37 ] ;
break;
default:
F_32 () ;
goto V_54;
}
V_4 = F_34 ( V_1 -> V_10 , V_1 -> V_24 ,
V_1 -> V_25 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_18 , V_4 ) ;
goto V_54;
}
V_4 = F_20 ( V_1 -> V_24 ,
V_1 -> V_25 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_6 , V_4 ) ;
goto V_54;
}
V_4 = F_1 ( V_1 , V_19 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_19 ) ;
goto V_26;
}
switch ( V_4 ) {
case 0x1811 :
V_50 = L_20 ;
if ( V_1 -> type != V_12 )
F_35 ( V_1 -> V_10 , L_21 ,
V_1 -> type ) ;
V_1 -> type = V_12 ;
break;
case 0x8994 :
V_50 = L_22 ;
if ( V_1 -> type != V_56 )
F_35 ( V_1 -> V_10 , L_21 ,
V_1 -> type ) ;
V_1 -> type = V_56 ;
break;
case 0x8958 :
V_50 = L_23 ;
if ( V_1 -> type != V_11 )
F_35 ( V_1 -> V_10 , L_21 ,
V_1 -> type ) ;
V_1 -> type = V_11 ;
break;
default:
F_13 ( V_1 -> V_10 , L_24 ,
V_4 ) ;
V_4 = - V_63 ;
goto V_26;
}
V_4 = F_1 ( V_1 , V_64 ) ;
if ( V_4 < 0 ) {
F_13 ( V_1 -> V_10 , L_25 ,
V_4 ) ;
goto V_26;
}
V_1 -> V_65 = V_4 & V_66 ;
V_1 -> V_67 = ( V_4 & V_68 ) >> V_69 ;
switch ( V_1 -> type ) {
case V_56 :
switch ( V_1 -> V_65 ) {
case 0 :
case 1 :
F_35 ( V_1 -> V_10 ,
L_26 ,
'A' + V_1 -> V_65 ) ;
break;
case 2 :
case 3 :
default:
V_49 = V_70 ;
V_51 = F_25 ( V_70 ) ;
break;
}
break;
case V_11 :
switch ( V_1 -> V_65 ) {
case 0 :
V_49 = V_71 ;
V_51 = F_25 ( V_71 ) ;
break;
default:
break;
}
break;
case V_12 :
if ( V_1 -> V_65 > 1 )
V_1 -> V_65 ++ ;
V_49 = V_72 ;
V_51 = F_25 ( V_72 ) ;
break;
default:
break;
}
F_36 ( V_1 -> V_10 , L_27 , V_50 ,
'A' + V_1 -> V_65 , V_1 -> V_67 ) ;
switch ( V_1 -> type ) {
case V_12 :
V_47 = & V_73 ;
break;
case V_56 :
V_47 = & V_74 ;
break;
case V_11 :
V_47 = & V_75 ;
break;
default:
F_13 ( V_1 -> V_10 , L_28 , V_1 -> type ) ;
return - V_63 ;
}
V_4 = F_37 ( V_1 -> V_5 , V_47 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_29 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_5 ( V_1 , V_19 ,
F_1 ( V_1 , V_19 ) ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_30 , V_4 ) ;
return V_4 ;
}
if ( V_49 ) {
V_4 = F_38 ( V_1 -> V_5 , V_49 ,
V_51 ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_31 ,
V_4 ) ;
goto V_54;
}
}
V_1 -> V_76 = V_28 -> V_76 ;
V_1 -> V_77 = V_28 -> V_77 ;
for ( V_37 = 0 ; V_37 < F_25 ( V_28 -> V_38 ) ; V_37 ++ ) {
if ( V_28 -> V_38 [ V_37 ] ) {
F_9 ( V_1 , V_20 + V_37 ,
0xffff , V_28 -> V_38 [ V_37 ] ) ;
}
}
V_1 -> V_15 = V_28 -> V_15 ;
if ( V_28 -> V_78 )
V_52 |= V_79 ;
F_9 ( V_1 , V_16 ,
V_17 | V_18 |
V_79 | V_80 ,
V_52 ) ;
for ( V_37 = 0 ; V_37 < V_81 ; V_37 ++ ) {
if ( F_22 ( V_28 , V_37 ) )
F_9 ( V_1 , V_82 + V_37 ,
V_83 , V_83 ) ;
else
F_9 ( V_1 , V_82 + V_37 ,
V_83 , 0 ) ;
}
F_39 ( V_1 ) ;
V_4 = F_31 ( V_1 -> V_10 , - 1 ,
V_84 , F_25 ( V_84 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_13 ( V_1 -> V_10 , L_17 , V_4 ) ;
goto V_85;
}
F_40 ( V_1 -> V_10 ) ;
F_41 ( V_1 -> V_10 ) ;
return 0 ;
V_85:
F_42 ( V_1 ) ;
V_26:
F_18 ( V_1 -> V_24 ,
V_1 -> V_25 ) ;
V_54:
F_43 ( V_1 -> V_10 ) ;
return V_4 ;
}
static void F_44 ( struct V_1 * V_1 )
{
F_45 ( V_1 -> V_10 ) ;
F_43 ( V_1 -> V_10 ) ;
F_42 ( V_1 ) ;
F_18 ( V_1 -> V_24 ,
V_1 -> V_25 ) ;
}
static int F_46 ( struct V_86 * V_87 ,
const struct V_88 * V_89 )
{
const struct V_90 * V_91 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = F_33 ( & V_87 -> V_10 , sizeof( struct V_1 ) , V_60 ) ;
if ( V_1 == NULL )
return - V_61 ;
F_47 ( V_87 , V_1 ) ;
V_1 -> V_10 = & V_87 -> V_10 ;
V_1 -> V_46 = V_87 -> V_46 ;
if ( V_87 -> V_10 . V_36 ) {
V_91 = F_48 ( V_92 , & V_87 -> V_10 ) ;
if ( V_91 )
V_1 -> type = ( int ) V_91 -> V_93 ;
} else {
V_1 -> type = V_89 -> V_94 ;
}
V_1 -> V_5 = F_49 ( V_87 , & V_95 ) ;
if ( F_50 ( V_1 -> V_5 ) ) {
V_4 = F_51 ( V_1 -> V_5 ) ;
F_13 ( V_1 -> V_10 , L_32 ,
V_4 ) ;
return V_4 ;
}
return F_28 ( V_1 , V_87 -> V_46 ) ;
}
static int F_52 ( struct V_86 * V_87 )
{
struct V_1 * V_1 = F_53 ( V_87 ) ;
F_44 ( V_1 ) ;
return 0 ;
}
