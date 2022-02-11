static int F_1 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_4 )
{
int V_5 , V_6 ;
T_1 * V_7 = V_4 ;
F_2 ( V_3 % 2 ) ;
F_2 ( V_3 <= 0 ) ;
V_5 = V_1 -> V_8 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_3 / 2 ; V_6 ++ ) {
F_3 ( V_1 -> V_9 , L_1 ,
F_4 ( V_7 [ V_6 ] ) , V_2 + V_6 , V_2 + V_6 ) ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_1 , unsigned short V_2 )
{
unsigned short V_10 ;
int V_5 ;
F_6 ( & V_1 -> V_11 ) ;
V_5 = F_1 ( V_1 , V_2 , 2 , & V_10 ) ;
F_7 ( & V_1 -> V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return F_4 ( V_10 ) ;
}
int F_8 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_12 , T_1 * V_7 )
{
int V_5 ;
F_6 ( & V_1 -> V_11 ) ;
V_5 = F_1 ( V_1 , V_2 , V_12 * 2 , V_7 ) ;
F_7 ( & V_1 -> V_11 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , const void * V_13 )
{
const T_1 * V_7 = V_13 ;
int V_6 ;
F_2 ( V_3 % 2 ) ;
F_2 ( V_3 <= 0 ) ;
for ( V_6 = 0 ; V_6 < V_3 / 2 ; V_6 ++ ) {
F_3 ( V_1 -> V_9 , L_2 ,
F_4 ( V_7 [ V_6 ] ) , V_2 + V_6 , V_2 + V_6 ) ;
}
return V_1 -> V_14 ( V_1 , V_2 , V_3 , V_13 ) ;
}
int F_10 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_10 )
{
int V_5 ;
V_10 = F_11 ( V_10 ) ;
F_6 ( & V_1 -> V_11 ) ;
V_5 = F_9 ( V_1 , V_2 , 2 , & V_10 ) ;
F_7 ( & V_1 -> V_11 ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_12 , const T_1 * V_7 )
{
int V_5 ;
F_6 ( & V_1 -> V_11 ) ;
V_5 = F_9 ( V_1 , V_2 , V_12 * 2 , V_7 ) ;
F_7 ( & V_1 -> V_11 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_15 , unsigned short V_10 )
{
int V_5 ;
T_1 V_16 ;
F_6 ( & V_1 -> V_11 ) ;
V_5 = F_1 ( V_1 , V_2 , 2 , & V_16 ) ;
if ( V_5 < 0 )
goto V_17;
V_16 = F_4 ( V_16 ) ;
V_16 &= ~ V_15 ;
V_16 |= V_10 ;
V_16 = F_11 ( V_16 ) ;
V_5 = F_9 ( V_1 , V_2 , 2 , & V_16 ) ;
V_17:
F_7 ( & V_1 -> V_11 ) ;
return V_5 ;
}
static int F_14 ( struct V_18 * V_9 )
{
struct V_1 * V_1 = F_15 ( V_9 ) ;
int V_5 ;
V_5 = F_5 ( V_1 , V_19 ) ;
if ( V_5 < 0 ) {
F_16 ( V_9 , L_3 , V_5 ) ;
} else if ( V_5 & V_20 ) {
F_17 ( V_9 , L_4 ) ;
return 0 ;
}
V_5 = F_1 ( V_1 , V_21 , V_22 * 2 ,
& V_1 -> V_23 ) ;
if ( V_5 < 0 )
F_16 ( V_9 , L_5 , V_5 ) ;
V_5 = F_1 ( V_1 , V_24 , V_25 * 2 ,
& V_1 -> V_26 ) ;
if ( V_5 < 0 )
F_16 ( V_9 , L_6 , V_5 ) ;
F_10 ( V_1 , V_27 , 0x8994 ) ;
V_1 -> V_28 = true ;
V_5 = F_18 ( V_1 -> V_29 ,
V_1 -> V_30 ) ;
if ( V_5 != 0 ) {
F_16 ( V_9 , L_7 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_19 ( struct V_18 * V_9 )
{
struct V_1 * V_1 = F_15 ( V_9 ) ;
int V_5 , V_6 ;
if ( ! V_1 -> V_28 )
return 0 ;
V_5 = F_20 ( V_1 -> V_29 ,
V_1 -> V_30 ) ;
if ( V_5 != 0 ) {
F_16 ( V_9 , L_8 , V_5 ) ;
return V_5 ;
}
for ( V_6 = 0 ; V_6 < F_21 ( V_1 -> V_31 ) ; V_6 ++ ) {
V_5 = F_10 ( V_1 , V_32
+ V_6 , V_1 -> V_31 [ V_6 ] ) ;
if ( V_5 < 0 )
F_16 ( V_9 , L_9 ,
V_5 ) ;
}
V_5 = F_9 ( V_1 , V_24 , V_25 * 2 ,
& V_1 -> V_26 ) ;
if ( V_5 < 0 )
F_16 ( V_9 , L_10 , V_5 ) ;
V_5 = F_9 ( V_1 , V_21 , V_22 * 2 ,
& V_1 -> V_23 ) ;
if ( V_5 < 0 )
F_16 ( V_9 , L_11 , V_5 ) ;
V_1 -> V_28 = false ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 , int V_35 )
{
struct V_36 * V_37 ;
if ( ! V_34 )
return 0 ;
V_37 = & V_34 -> V_35 [ V_35 ] ;
if ( ! V_37 -> V_38 )
return 0 ;
return V_37 -> V_38 -> V_39 != 0 ;
}
static int F_22 ( struct V_33 * V_34 , int V_35 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , int V_40 )
{
struct V_33 * V_34 = V_1 -> V_9 -> V_41 ;
const char * V_42 ;
int V_5 , V_6 ;
F_24 ( & V_1 -> V_11 ) ;
F_25 ( V_1 -> V_9 , V_1 ) ;
V_5 = F_26 ( V_1 -> V_9 , - 1 ,
V_43 ,
F_21 ( V_43 ) ,
NULL , 0 ) ;
if ( V_5 != 0 ) {
F_16 ( V_1 -> V_9 , L_12 , V_5 ) ;
goto V_44;
}
switch ( V_1 -> type ) {
case V_45 :
V_1 -> V_29 = F_21 ( V_46 ) ;
break;
case V_47 :
V_1 -> V_29 = F_21 ( V_48 ) ;
break;
default:
F_27 () ;
goto V_44;
}
V_1 -> V_30 = F_28 ( sizeof( struct V_49 ) *
V_1 -> V_29 ,
V_50 ) ;
if ( ! V_1 -> V_30 ) {
V_5 = - V_51 ;
goto V_44;
}
switch ( V_1 -> type ) {
case V_45 :
for ( V_6 = 0 ; V_6 < F_21 ( V_46 ) ; V_6 ++ )
V_1 -> V_30 [ V_6 ] . V_52 = V_46 [ V_6 ] ;
break;
case V_47 :
for ( V_6 = 0 ; V_6 < F_21 ( V_48 ) ; V_6 ++ )
V_1 -> V_30 [ V_6 ] . V_52 = V_48 [ V_6 ] ;
break;
default:
F_27 () ;
goto V_44;
}
V_5 = F_29 ( V_1 -> V_9 , V_1 -> V_29 ,
V_1 -> V_30 ) ;
if ( V_5 != 0 ) {
F_16 ( V_1 -> V_9 , L_13 , V_5 ) ;
goto V_53;
}
V_5 = F_20 ( V_1 -> V_29 ,
V_1 -> V_30 ) ;
if ( V_5 != 0 ) {
F_16 ( V_1 -> V_9 , L_8 , V_5 ) ;
goto V_54;
}
V_5 = F_5 ( V_1 , V_27 ) ;
if ( V_5 < 0 ) {
F_16 ( V_1 -> V_9 , L_14 ) ;
goto V_55;
}
switch ( V_5 ) {
case 0x8994 :
V_42 = L_15 ;
if ( V_1 -> type != V_45 )
F_30 ( V_1 -> V_9 , L_16 ,
V_1 -> type ) ;
V_1 -> type = V_45 ;
break;
case 0x8958 :
V_42 = L_17 ;
if ( V_1 -> type != V_47 )
F_30 ( V_1 -> V_9 , L_16 ,
V_1 -> type ) ;
V_1 -> type = V_47 ;
break;
default:
F_16 ( V_1 -> V_9 , L_18 ,
V_5 ) ;
V_5 = - V_56 ;
goto V_55;
}
V_5 = F_5 ( V_1 , V_57 ) ;
if ( V_5 < 0 ) {
F_16 ( V_1 -> V_9 , L_19 ,
V_5 ) ;
goto V_55;
}
switch ( V_1 -> type ) {
case V_45 :
switch ( V_5 ) {
case 0 :
case 1 :
F_30 ( V_1 -> V_9 ,
L_20 ,
'A' + V_5 ) ;
break;
default:
break;
}
break;
default:
break;
}
F_31 ( V_1 -> V_9 , L_21 , V_42 , 'A' + V_5 ) ;
if ( V_34 ) {
V_1 -> V_58 = V_34 -> V_58 ;
V_1 -> V_59 = V_34 -> V_59 ;
for ( V_6 = 0 ; V_6 < F_21 ( V_34 -> V_60 ) ; V_6 ++ ) {
if ( V_34 -> V_60 [ V_6 ] ) {
F_13 ( V_1 , V_21 + V_6 ,
0xffff ,
V_34 -> V_60 [ V_6 ] ) ;
}
}
}
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ ) {
if ( F_22 ( V_34 , V_6 ) )
F_13 ( V_1 , V_24 + V_6 ,
V_61 , V_61 ) ;
else
F_13 ( V_1 , V_24 + V_6 ,
V_61 , 0 ) ;
}
F_32 ( V_1 ) ;
V_5 = F_26 ( V_1 -> V_9 , - 1 ,
V_62 , F_21 ( V_62 ) ,
NULL , 0 ) ;
if ( V_5 != 0 ) {
F_16 ( V_1 -> V_9 , L_12 , V_5 ) ;
goto V_63;
}
F_33 ( V_1 -> V_9 ) ;
F_34 ( V_1 -> V_9 ) ;
return 0 ;
V_63:
F_35 ( V_1 ) ;
V_55:
F_18 ( V_1 -> V_29 ,
V_1 -> V_30 ) ;
V_54:
F_36 ( V_1 -> V_29 , V_1 -> V_30 ) ;
V_53:
F_37 ( V_1 -> V_30 ) ;
V_44:
F_38 ( V_1 -> V_9 ) ;
F_37 ( V_1 ) ;
return V_5 ;
}
static void F_39 ( struct V_1 * V_1 )
{
F_40 ( V_1 -> V_9 ) ;
F_38 ( V_1 -> V_9 ) ;
F_35 ( V_1 ) ;
F_18 ( V_1 -> V_29 ,
V_1 -> V_30 ) ;
F_36 ( V_1 -> V_29 , V_1 -> V_30 ) ;
F_37 ( V_1 -> V_30 ) ;
F_37 ( V_1 ) ;
}
static int F_41 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_4 )
{
struct V_64 * V_65 = V_1 -> V_66 ;
int V_5 ;
T_1 V_16 = F_11 ( V_2 ) ;
V_5 = F_42 ( V_65 , ( unsigned char * ) & V_16 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_67 ;
V_5 = F_43 ( V_65 , V_4 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_3 )
return - V_67 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , const void * V_13 )
{
struct V_64 * V_65 = V_1 -> V_66 ;
struct V_68 V_69 [ 2 ] ;
int V_5 ;
V_2 = F_11 ( V_2 ) ;
V_69 [ 0 ] . V_70 = V_65 -> V_70 ;
V_69 [ 0 ] . V_71 = 0 ;
V_69 [ 0 ] . V_72 = 2 ;
V_69 [ 0 ] . V_7 = ( char * ) & V_2 ;
V_69 [ 1 ] . V_70 = V_65 -> V_70 ;
V_69 [ 1 ] . V_71 = V_73 ;
V_69 [ 1 ] . V_72 = V_3 ;
V_69 [ 1 ] . V_7 = ( char * ) V_13 ;
V_5 = F_45 ( V_65 -> V_74 , V_69 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_67 ;
return 0 ;
}
static int F_46 ( struct V_64 * V_65 ,
const struct V_75 * V_76 )
{
struct V_1 * V_1 ;
V_1 = F_28 ( sizeof( struct V_1 ) , V_50 ) ;
if ( V_1 == NULL )
return - V_51 ;
F_47 ( V_65 , V_1 ) ;
V_1 -> V_9 = & V_65 -> V_9 ;
V_1 -> V_66 = V_65 ;
V_1 -> V_8 = F_41 ;
V_1 -> V_14 = F_44 ;
V_1 -> V_40 = V_65 -> V_40 ;
V_1 -> type = V_76 -> V_77 ;
return F_23 ( V_1 , V_65 -> V_40 ) ;
}
static int F_48 ( struct V_64 * V_65 )
{
struct V_1 * V_1 = F_49 ( V_65 ) ;
F_39 ( V_1 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
int V_5 ;
V_5 = F_51 ( & V_78 ) ;
if ( V_5 != 0 )
F_52 ( L_22 , V_5 ) ;
return V_5 ;
}
static void T_3 F_53 ( void )
{
F_54 ( & V_78 ) ;
}
