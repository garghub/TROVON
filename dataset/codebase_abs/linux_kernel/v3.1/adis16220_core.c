static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = V_4 ;
V_5 = F_6 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_13 ,
T_2 V_14 )
{
int V_5 ;
struct V_15 V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_17 V_18 [] = {
{
. V_19 = V_9 -> V_11 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 35 ,
} , {
. V_19 = V_9 -> V_11 + 2 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 35 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_13 ) ;
V_9 -> V_11 [ 1 ] = V_14 & 0xFF ;
V_9 -> V_11 [ 2 ] = F_5 ( V_13 + 1 ) ;
V_9 -> V_11 [ 3 ] = ( V_14 >> 8 ) & 0xFF ;
F_9 ( & V_16 ) ;
F_10 ( & V_18 [ 0 ] , & V_16 ) ;
F_10 ( & V_18 [ 1 ] , & V_16 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_16 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_13 ,
T_2 * V_4 )
{
struct V_15 V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_17 V_18 [] = {
{
. V_19 = V_9 -> V_11 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 35 ,
} , {
. V_24 = V_9 -> V_25 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 35 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_13 ( V_13 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
F_9 ( & V_16 ) ;
F_10 ( & V_18 [ 0 ] , & V_16 ) ;
F_10 ( & V_18 [ 1 ] , & V_16 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_16 ) ;
if ( V_5 ) {
F_14 ( & V_9 -> V_12 -> V_2 ,
L_1 ,
V_13 ) ;
goto V_26;
}
* V_4 = ( V_9 -> V_25 [ 0 ] << 8 ) | V_9 -> V_25 [ 1 ] ;
V_26:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_3 F_15 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
char * V_29 ,
unsigned V_30 )
{
int V_5 ;
T_4 V_4 = 0 ;
unsigned V_31 = 16 - V_30 ;
struct V_32 * V_33 = F_16 ( V_28 ) ;
V_5 = F_12 ( V_2 , V_33 -> V_34 , ( T_2 * ) & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 = ( ( T_4 ) ( V_4 << V_31 ) >> V_31 ) ;
return sprintf ( V_29 , L_2 , V_4 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
char * V_29 )
{
int V_5 ;
T_2 V_4 = 0 ;
struct V_32 * V_33 = F_16 ( V_28 ) ;
V_5 = F_12 ( V_2 , V_33 -> V_34 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_29 , L_3 , V_4 & 0x0FFF ) ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_5 ;
F_4 ( & V_7 -> V_35 ) ;
V_5 = F_15 ( V_2 , V_28 , V_29 , 16 ) ;
F_7 ( & V_7 -> V_35 ) ;
return V_5 ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_5 V_21 )
{
struct V_32 * V_33 = F_16 ( V_28 ) ;
int V_5 ;
long V_4 ;
V_5 = F_20 ( V_29 , 10 , & V_4 ) ;
if ( V_5 )
goto V_26;
V_5 = F_8 ( V_2 , V_33 -> V_34 , V_4 ) ;
V_26:
return V_5 ? V_5 : V_21 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_8 ( V_2 ,
V_36 ,
0xBF08 ) ;
if ( V_5 )
F_14 ( V_2 , L_4 ) ;
F_22 ( 10 ) ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_36 ,
V_37 ) ;
if ( V_5 )
F_14 ( V_2 , L_5 ) ;
return V_5 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
const char * V_29 , T_5 V_21 )
{
if ( V_21 < 1 )
return - 1 ;
switch ( V_29 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_23 ( V_2 ) == 0 ? V_21 : - V_38 ;
}
return - 1 ;
}
static T_3 F_25 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
const char * V_29 , T_5 V_21 )
{
if ( V_21 < 1 )
return - 1 ;
switch ( V_29 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_21 ( V_2 ) == 0 ? V_21 : - V_38 ;
}
return - 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_2 V_39 ;
int V_5 ;
V_5 = F_12 ( V_2 , V_40 , & V_39 ) ;
if ( V_5 < 0 ) {
F_14 ( V_2 , L_6 ) ;
goto V_26;
}
V_5 = V_39 & 0x7F ;
if ( V_39 & V_41 )
F_14 ( V_2 , L_7 ) ;
if ( V_39 & V_42 )
F_14 ( V_2 , L_8 ) ;
if ( V_39 & V_43 )
F_14 ( V_2 , L_9 ) ;
if ( V_39 & V_44 )
F_14 ( V_2 , L_10 ) ;
if ( V_39 & V_45 )
F_14 ( V_2 , L_11 ) ;
V_26:
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_8 ( V_2 ,
V_46 ,
V_47 ) ;
if ( V_5 ) {
F_14 ( V_2 , L_12 ) ;
goto V_48;
}
F_26 ( V_2 ) ;
V_48:
return V_5 ;
}
static int F_28 ( struct V_6 * V_7 )
{
int V_5 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 ) {
F_14 ( V_2 , L_13 ) ;
goto V_48;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 ) ;
F_14 ( V_2 , L_14 ) ;
F_22 ( V_49 ) ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 ) {
F_14 ( V_2 , L_15 ) ;
goto V_48;
}
}
V_48:
return V_5 ;
}
static T_3 F_29 ( struct V_6 * V_7 ,
char * V_29 ,
T_6 V_50 ,
T_5 V_51 ,
int V_52 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 V_16 ;
struct V_17 V_18 [] = {
{
. V_19 = V_9 -> V_11 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 25 ,
} , {
. V_19 = V_9 -> V_11 ,
. V_24 = V_9 -> V_25 ,
. V_20 = 8 ,
. V_22 = 1 ,
. V_23 = 25 ,
} ,
} ;
int V_5 ;
int V_53 ;
if ( F_30 ( ! V_51 ) )
return V_51 ;
if ( ( V_50 >= V_54 ) || ( V_51 & 1 ) || ( V_50 & 1 ) )
return - V_55 ;
if ( V_50 + V_51 > V_54 )
V_51 = V_54 - V_50 ;
V_5 = F_8 ( & V_7 -> V_2 ,
V_56 ,
V_50 > 1 ) ;
if ( V_5 )
return - V_38 ;
F_4 ( & V_9 -> V_10 ) ;
for ( V_53 = 0 ; V_53 < V_51 ; V_53 += 2 ) {
V_9 -> V_11 [ V_53 ] = F_13 ( V_52 ) ;
V_9 -> V_11 [ V_53 + 1 ] = 0 ;
}
V_18 [ 1 ] . V_21 = V_51 ;
F_9 ( & V_16 ) ;
F_10 ( & V_18 [ 0 ] , & V_16 ) ;
F_10 ( & V_18 [ 1 ] , & V_16 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_16 ) ;
if ( V_5 ) {
F_7 ( & V_9 -> V_10 ) ;
return - V_38 ;
}
memcpy ( V_29 , V_9 -> V_25 , V_51 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_51 ;
}
static T_3 F_31 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_61 * V_28 ,
char * V_29 ,
T_6 V_50 ,
T_5 V_51 )
{
struct V_1 * V_2 = F_32 ( V_60 , struct V_1 , V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_29 ( V_7 , V_29 ,
V_50 , V_51 ,
V_62 ) ;
}
static T_3 F_33 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_61 * V_28 ,
char * V_29 , T_6 V_50 ,
T_5 V_51 )
{
struct V_1 * V_2 = F_32 ( V_60 , struct V_1 , V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_29 ( V_7 , V_29 ,
V_50 , V_51 ,
V_63 ) ;
}
static T_3 F_34 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_61 * V_28 ,
char * V_29 , T_6 V_50 ,
T_5 V_51 )
{
struct V_1 * V_2 = F_32 ( V_60 , struct V_1 , V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_29 ( V_7 , V_29 ,
V_50 , V_51 ,
V_64 ) ;
}
static int T_7 F_35 ( struct V_65 * V_66 )
{
int V_5 , V_67 = 0 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_36 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
V_5 = - V_68 ;
goto V_26;
}
V_9 = F_3 ( V_7 ) ;
F_37 ( V_66 , V_7 ) ;
V_9 -> V_12 = V_66 ;
F_38 ( & V_9 -> V_10 ) ;
V_7 -> V_69 = V_66 -> V_2 . V_70 -> V_69 ;
V_7 -> V_2 . V_71 = & V_66 -> V_2 ;
V_7 -> V_72 = & V_73 ;
V_7 -> V_74 = V_75 ;
V_5 = F_39 ( V_7 ) ;
if ( V_5 )
goto V_76;
V_67 = 1 ;
V_5 = F_40 ( & V_7 -> V_2 . V_60 , & V_77 ) ;
if ( V_5 )
goto V_76;
V_5 = F_40 ( & V_7 -> V_2 . V_60 , & V_78 ) ;
if ( V_5 )
goto V_79;
V_5 = F_40 ( & V_7 -> V_2 . V_60 , & V_80 ) ;
if ( V_5 )
goto V_81;
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
goto V_82;
return 0 ;
V_82:
F_41 ( & V_7 -> V_2 . V_60 , & V_80 ) ;
V_81:
F_41 ( & V_7 -> V_2 . V_60 , & V_78 ) ;
V_79:
F_41 ( & V_7 -> V_2 . V_60 , & V_77 ) ;
V_76:
if ( V_67 )
F_42 ( V_7 ) ;
else
F_43 ( V_7 ) ;
V_26:
return V_5 ;
}
static int F_44 ( struct V_65 * V_66 )
{
struct V_6 * V_7 = F_45 ( V_66 ) ;
F_46 () ;
F_41 ( & V_7 -> V_2 . V_60 , & V_80 ) ;
F_41 ( & V_7 -> V_2 . V_60 , & V_78 ) ;
F_41 ( & V_7 -> V_2 . V_60 , & V_77 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
static T_8 int F_47 ( void )
{
return F_48 ( & V_83 ) ;
}
static T_9 void F_49 ( void )
{
F_50 ( & V_83 ) ;
}
