static int F_1 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_4 )
{
return F_2 ( V_1 -> V_5 , V_2 , V_4 , V_3 ) ;
}
int F_3 ( struct V_1 * V_1 , unsigned short V_2 )
{
unsigned int V_6 ;
int V_7 ;
V_7 = F_4 ( V_1 -> V_5 , V_2 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
else
return V_6 ;
}
int F_5 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_8 , T_1 * V_9 )
{
return F_6 ( V_1 -> V_5 , V_2 , V_9 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , const void * V_10 )
{
return F_8 ( V_1 -> V_5 , V_2 , V_10 , V_3 ) ;
}
int F_9 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_6 )
{
return F_10 ( V_1 -> V_5 , V_2 , V_6 ) ;
}
int F_11 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_8 , const T_1 * V_9 )
{
return F_8 ( V_1 -> V_5 , V_2 , V_9 , V_8 * sizeof( T_1 ) ) ;
}
int F_12 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_11 , unsigned short V_6 )
{
return F_13 ( V_1 -> V_5 , V_2 , V_11 , V_6 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_15 ( V_13 ) ;
int V_7 ;
V_7 = F_3 ( V_1 , V_14 ) ;
if ( V_7 < 0 ) {
F_16 ( V_13 , L_1 , V_7 ) ;
} else if ( V_7 & V_15 ) {
F_17 ( V_13 , L_2 ) ;
return 0 ;
}
V_7 = F_3 ( V_1 , V_16 ) ;
if ( V_7 < 0 ) {
F_16 ( V_13 , L_1 , V_7 ) ;
} else if ( V_7 & ( V_17 | V_18 |
V_19 | V_20 |
V_21 | V_22 ) ) {
F_17 ( V_13 , L_2 ) ;
return 0 ;
}
V_7 = F_3 ( V_1 , V_23 ) ;
if ( V_7 < 0 ) {
F_16 ( V_13 , L_1 , V_7 ) ;
} else if ( V_7 & ( V_24 | V_25 |
V_26 | V_27 |
V_28 | V_29 ) ) {
F_17 ( V_13 , L_2 ) ;
return 0 ;
}
switch ( V_1 -> type ) {
case V_30 :
case V_31 :
V_7 = F_3 ( V_1 , V_32 ) ;
if ( V_7 < 0 ) {
F_16 ( V_13 , L_1 , V_7 ) ;
} else if ( V_7 & V_33 ) {
F_17 ( V_13 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
if ( ! V_1 -> V_34 )
F_12 ( V_1 , V_35 ,
V_36 | V_37 ,
V_36 | V_37 ) ;
V_7 = F_1 ( V_1 , V_38 , V_39 * 2 ,
& V_1 -> V_40 ) ;
if ( V_7 < 0 )
F_16 ( V_13 , L_3 , V_7 ) ;
V_7 = F_1 ( V_1 , V_41 , V_42 * 2 ,
& V_1 -> V_43 ) ;
if ( V_7 < 0 )
F_16 ( V_13 , L_4 , V_7 ) ;
F_9 ( V_1 , V_44 , 0x8994 ) ;
V_1 -> V_45 = true ;
V_7 = F_18 ( V_1 -> V_46 ,
V_1 -> V_47 ) ;
if ( V_7 != 0 ) {
F_16 ( V_13 , L_5 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_15 ( V_13 ) ;
int V_7 , V_48 ;
if ( ! V_1 -> V_45 )
return 0 ;
V_7 = F_20 ( V_1 -> V_46 ,
V_1 -> V_47 ) ;
if ( V_7 != 0 ) {
F_16 ( V_13 , L_6 , V_7 ) ;
return V_7 ;
}
for ( V_48 = 0 ; V_48 < F_21 ( V_1 -> V_49 ) ; V_48 ++ ) {
V_7 = F_9 ( V_1 , V_50
+ V_48 , V_1 -> V_49 [ V_48 ] ) ;
if ( V_7 < 0 )
F_16 ( V_13 , L_7 ,
V_7 ) ;
}
V_7 = F_7 ( V_1 , V_41 , V_42 * 2 ,
& V_1 -> V_43 ) ;
if ( V_7 < 0 )
F_16 ( V_13 , L_8 , V_7 ) ;
V_7 = F_7 ( V_1 , V_38 , V_39 * 2 ,
& V_1 -> V_40 ) ;
if ( V_7 < 0 )
F_16 ( V_13 , L_9 , V_7 ) ;
F_12 ( V_1 , V_35 ,
V_36 | V_37 ,
0 ) ;
V_1 -> V_45 = false ;
return 0 ;
}
static int F_22 ( struct V_51 * V_52 , int V_53 )
{
struct V_54 * V_55 ;
if ( ! V_52 )
return 0 ;
V_55 = & V_52 -> V_53 [ V_53 ] ;
if ( ! V_55 -> V_56 )
return 0 ;
return V_55 -> V_56 -> V_57 != 0 ;
}
static int F_22 ( struct V_51 * V_52 , int V_53 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , int V_58 )
{
struct V_51 * V_52 = V_1 -> V_13 -> V_59 ;
const char * V_60 ;
int V_7 , V_48 ;
F_24 ( V_1 -> V_13 , V_1 ) ;
V_7 = F_25 ( V_1 -> V_13 , - 1 ,
V_61 ,
F_21 ( V_61 ) ,
NULL , 0 ) ;
if ( V_7 != 0 ) {
F_16 ( V_1 -> V_13 , L_10 , V_7 ) ;
goto V_62;
}
switch ( V_1 -> type ) {
case V_31 :
V_1 -> V_46 = F_21 ( V_63 ) ;
break;
case V_64 :
V_1 -> V_46 = F_21 ( V_65 ) ;
break;
case V_30 :
V_1 -> V_46 = F_21 ( V_66 ) ;
break;
default:
F_26 () ;
goto V_62;
}
V_1 -> V_47 = F_27 ( sizeof( struct V_67 ) *
V_1 -> V_46 ,
V_68 ) ;
if ( ! V_1 -> V_47 ) {
V_7 = - V_69 ;
goto V_62;
}
switch ( V_1 -> type ) {
case V_31 :
for ( V_48 = 0 ; V_48 < F_21 ( V_63 ) ; V_48 ++ )
V_1 -> V_47 [ V_48 ] . V_70 = V_63 [ V_48 ] ;
break;
case V_64 :
for ( V_48 = 0 ; V_48 < F_21 ( V_65 ) ; V_48 ++ )
V_1 -> V_47 [ V_48 ] . V_70 = V_65 [ V_48 ] ;
break;
case V_30 :
for ( V_48 = 0 ; V_48 < F_21 ( V_66 ) ; V_48 ++ )
V_1 -> V_47 [ V_48 ] . V_70 = V_66 [ V_48 ] ;
break;
default:
F_26 () ;
goto V_62;
}
V_7 = F_28 ( V_1 -> V_13 , V_1 -> V_46 ,
V_1 -> V_47 ) ;
if ( V_7 != 0 ) {
F_16 ( V_1 -> V_13 , L_11 , V_7 ) ;
goto V_71;
}
V_7 = F_20 ( V_1 -> V_46 ,
V_1 -> V_47 ) ;
if ( V_7 != 0 ) {
F_16 ( V_1 -> V_13 , L_6 , V_7 ) ;
goto V_72;
}
V_7 = F_3 ( V_1 , V_44 ) ;
if ( V_7 < 0 ) {
F_16 ( V_1 -> V_13 , L_12 ) ;
goto V_73;
}
switch ( V_7 ) {
case 0x1811 :
V_60 = L_13 ;
if ( V_1 -> type != V_31 )
F_29 ( V_1 -> V_13 , L_14 ,
V_1 -> type ) ;
V_1 -> type = V_31 ;
break;
case 0x8994 :
V_60 = L_15 ;
if ( V_1 -> type != V_64 )
F_29 ( V_1 -> V_13 , L_14 ,
V_1 -> type ) ;
V_1 -> type = V_64 ;
break;
case 0x8958 :
V_60 = L_16 ;
if ( V_1 -> type != V_30 )
F_29 ( V_1 -> V_13 , L_14 ,
V_1 -> type ) ;
V_1 -> type = V_30 ;
break;
default:
F_16 ( V_1 -> V_13 , L_17 ,
V_7 ) ;
V_7 = - V_74 ;
goto V_73;
}
V_7 = F_3 ( V_1 , V_75 ) ;
if ( V_7 < 0 ) {
F_16 ( V_1 -> V_13 , L_18 ,
V_7 ) ;
goto V_73;
}
switch ( V_1 -> type ) {
case V_64 :
switch ( V_7 ) {
case 0 :
case 1 :
F_29 ( V_1 -> V_13 ,
L_19 ,
'A' + V_7 ) ;
break;
default:
break;
}
break;
default:
break;
}
F_30 ( V_1 -> V_13 , L_20 , V_60 , 'A' + V_7 ) ;
if ( V_52 ) {
V_1 -> V_76 = V_52 -> V_76 ;
V_1 -> V_77 = V_52 -> V_77 ;
for ( V_48 = 0 ; V_48 < F_21 ( V_52 -> V_78 ) ; V_48 ++ ) {
if ( V_52 -> V_78 [ V_48 ] ) {
F_12 ( V_1 , V_38 + V_48 ,
0xffff ,
V_52 -> V_78 [ V_48 ] ) ;
}
}
V_1 -> V_34 = V_52 -> V_34 ;
}
F_12 ( V_1 , V_35 ,
V_36 | V_37 ,
0 ) ;
for ( V_48 = 0 ; V_48 < V_42 ; V_48 ++ ) {
if ( F_22 ( V_52 , V_48 ) )
F_12 ( V_1 , V_41 + V_48 ,
V_79 , V_79 ) ;
else
F_12 ( V_1 , V_41 + V_48 ,
V_79 , 0 ) ;
}
F_31 ( V_1 ) ;
V_7 = F_25 ( V_1 -> V_13 , - 1 ,
V_80 , F_21 ( V_80 ) ,
NULL , 0 ) ;
if ( V_7 != 0 ) {
F_16 ( V_1 -> V_13 , L_10 , V_7 ) ;
goto V_81;
}
F_32 ( V_1 -> V_13 ) ;
F_33 ( V_1 -> V_13 ) ;
return 0 ;
V_81:
F_34 ( V_1 ) ;
V_73:
F_18 ( V_1 -> V_46 ,
V_1 -> V_47 ) ;
V_72:
F_35 ( V_1 -> V_46 , V_1 -> V_47 ) ;
V_71:
F_36 ( V_1 -> V_47 ) ;
V_62:
F_37 ( V_1 -> V_5 ) ;
F_38 ( V_1 -> V_13 ) ;
F_36 ( V_1 ) ;
return V_7 ;
}
static void F_39 ( struct V_1 * V_1 )
{
F_40 ( V_1 -> V_13 ) ;
F_38 ( V_1 -> V_13 ) ;
F_34 ( V_1 ) ;
F_18 ( V_1 -> V_46 ,
V_1 -> V_47 ) ;
F_35 ( V_1 -> V_46 , V_1 -> V_47 ) ;
F_36 ( V_1 -> V_47 ) ;
F_37 ( V_1 -> V_5 ) ;
F_36 ( V_1 ) ;
}
static int F_41 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_27 ( sizeof( struct V_1 ) , V_68 ) ;
if ( V_1 == NULL )
return - V_69 ;
F_42 ( V_83 , V_1 ) ;
V_1 -> V_13 = & V_83 -> V_13 ;
V_1 -> V_58 = V_83 -> V_58 ;
V_1 -> type = V_85 -> V_86 ;
V_1 -> V_5 = F_43 ( V_83 , & V_87 ) ;
if ( F_44 ( V_1 -> V_5 ) ) {
V_7 = F_45 ( V_1 -> V_5 ) ;
F_16 ( V_1 -> V_13 , L_21 ,
V_7 ) ;
F_36 ( V_1 ) ;
return V_7 ;
}
return F_23 ( V_1 , V_83 -> V_58 ) ;
}
static int F_46 ( struct V_82 * V_83 )
{
struct V_1 * V_1 = F_47 ( V_83 ) ;
F_39 ( V_1 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
int V_7 ;
V_7 = F_49 ( & V_88 ) ;
if ( V_7 != 0 )
F_50 ( L_22 , V_7 ) ;
return V_7 ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_88 ) ;
}
