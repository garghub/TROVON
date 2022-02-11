int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
F_3 ( V_2 -> V_3 -> V_4 , 1 ) ;
F_4 ( 100 ) ;
F_3 ( V_2 -> V_3 -> V_4 , 0 ) ;
return 0 ;
}
return - V_5 ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_9 ;
V_2 -> V_10 = false ;
F_3 ( V_2 -> V_3 -> V_11 , 1 ) ;
V_9 = F_7 ( V_2 -> V_12 , V_2 -> V_10 ) ;
if ( V_9 )
goto V_13;
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = V_2 -> V_15 -> V_16 ( V_2 -> V_17 , 1 , V_2 -> V_18 ) ;
if ( V_9 )
goto V_13;
if ( ! F_8 ( V_2 -> V_3 -> V_14 ) ) {
F_1 ( V_2 ) ;
V_9 = - V_19 ;
goto V_13;
}
V_9 = V_2 -> V_15 -> V_16 ( V_2 -> V_17 ,
V_2 -> V_20 -> V_21 - 1 , & V_2 -> V_18 [ 1 ] ) ;
if ( V_9 )
goto V_13;
} else {
V_9 = V_2 -> V_15 -> V_16 ( V_2 -> V_17 ,
V_2 -> V_20 -> V_21 , V_2 -> V_18 ) ;
if ( V_9 )
goto V_13;
}
V_9 = V_2 -> V_18 [ V_8 ] ;
V_13:
F_3 ( V_2 -> V_3 -> V_11 , 0 ) ;
return V_9 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_22 const * V_23 ,
int * V_24 ,
int * V_25 ,
long V_26 )
{
int V_9 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
switch ( V_26 ) {
case V_27 :
V_9 = F_10 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_7 , V_23 -> V_28 ) ;
F_11 ( V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_24 = ( short ) V_9 ;
return V_29 ;
case V_30 :
* V_24 = V_2 -> V_31 * 2 ;
* V_25 = V_2 -> V_20 -> V_32 [ 0 ] . V_33 . V_34 ;
return V_35 ;
}
return - V_36 ;
}
static T_1 F_12 ( struct V_37 * V_17 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_6 * V_7 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_40 , L_1 , V_2 -> V_31 ) ;
}
static T_1 F_14 ( struct V_37 * V_17 ,
struct V_38 * V_39 ,
const char * V_40 , T_2 V_41 )
{
struct V_6 * V_7 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_42 ;
int V_9 ;
V_9 = F_15 ( V_40 , 10 , & V_42 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_42 == 5000 || V_42 == 10000 ) ) {
F_16 ( V_17 , L_2 ) ;
return - V_36 ;
}
F_17 ( & V_7 -> V_43 ) ;
F_3 ( V_2 -> V_3 -> V_44 , V_42 == 10000 ) ;
V_2 -> V_31 = V_42 ;
F_18 ( & V_7 -> V_43 ) ;
return V_41 ;
}
static T_1 F_19 ( struct V_37 * V_17 ,
struct V_38 * V_39 ,
char * V_40 )
{
struct V_6 * V_7 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_40 , L_1 , V_2 -> V_45 ) ;
}
static int F_20 ( unsigned int V_24 )
{
unsigned char V_46 [] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_21 ( V_46 ) ; V_47 ++ )
if ( V_24 == V_46 [ V_47 ] )
return V_47 ;
return - V_36 ;
}
static T_1 F_22 ( struct V_37 * V_17 ,
struct V_38 * V_39 ,
const char * V_40 , T_2 V_41 )
{
struct V_6 * V_7 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_42 ;
int V_9 ;
V_9 = F_15 ( V_40 , 10 , & V_42 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_20 ( V_42 ) ;
if ( V_9 < 0 ) {
F_16 ( V_17 , L_3 , V_42 ) ;
return V_9 ;
}
F_17 ( & V_7 -> V_43 ) ;
F_3 ( V_2 -> V_3 -> V_48 , ( V_9 >> 0 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_49 , ( V_9 >> 1 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_49 , ( V_9 >> 2 ) & 1 ) ;
V_2 -> V_45 = V_42 ;
F_18 ( & V_7 -> V_43 ) ;
return V_41 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_50 V_51 [ 3 ] = {
[ 0 ] = {
. V_50 = V_2 -> V_3 -> V_48 ,
. V_52 = V_53 | ( ( V_2 -> V_45 & 1 ) ?
V_54 : V_55 ) ,
. V_56 = L_4 ,
} ,
[ 1 ] = {
. V_50 = V_2 -> V_3 -> V_49 ,
. V_52 = V_53 | ( ( V_2 -> V_45 & 2 ) ?
V_54 : V_55 ) ,
. V_56 = L_5 ,
} ,
[ 2 ] = {
. V_50 = V_2 -> V_3 -> V_57 ,
. V_52 = V_53 | ( ( V_2 -> V_45 & 4 ) ?
V_54 : V_55 ) ,
. V_56 = L_6 ,
} ,
} ;
int V_9 ;
if ( F_2 ( V_2 -> V_3 -> V_11 ) ) {
V_9 = F_24 ( V_2 -> V_3 -> V_11 ,
V_58 ,
L_7 ) ;
if ( V_9 ) {
F_16 ( V_2 -> V_17 , L_8 ) ;
goto V_13;
}
} else {
V_9 = - V_19 ;
goto V_13;
}
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_57 ) ) {
V_9 = F_25 ( V_51 , F_21 ( V_51 ) ) ;
if ( V_9 < 0 )
goto V_59;
}
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_9 = F_24 ( V_2 -> V_3 -> V_4 ,
V_58 ,
L_9 ) ;
if ( V_9 < 0 )
goto V_60;
}
if ( F_2 ( V_2 -> V_3 -> V_44 ) ) {
V_9 = F_24 ( V_2 -> V_3 -> V_44 , V_53 |
( ( V_2 -> V_31 == 10000 ) ? V_54 :
V_55 ) , L_10 ) ;
if ( V_9 < 0 )
goto V_61;
}
if ( F_2 ( V_2 -> V_3 -> V_62 ) ) {
V_9 = F_24 ( V_2 -> V_3 -> V_62 ,
V_63 ,
L_11 ) ;
if ( V_9 < 0 )
goto V_64;
}
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = F_24 ( V_2 -> V_3 -> V_14 , V_65 ,
L_12 ) ;
if ( V_9 < 0 )
goto V_66;
}
return 0 ;
V_66:
if ( F_2 ( V_2 -> V_3 -> V_62 ) )
F_26 ( V_2 -> V_3 -> V_62 ) ;
V_64:
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_26 ( V_2 -> V_3 -> V_44 ) ;
V_61:
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_26 ( V_2 -> V_3 -> V_4 ) ;
V_60:
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_57 ) )
F_27 ( V_51 , F_21 ( V_51 ) ) ;
V_59:
F_26 ( V_2 -> V_3 -> V_11 ) ;
V_13:
return V_9 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_14 ) )
F_26 ( V_2 -> V_3 -> V_14 ) ;
if ( F_2 ( V_2 -> V_3 -> V_62 ) )
F_26 ( V_2 -> V_3 -> V_62 ) ;
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_26 ( V_2 -> V_3 -> V_44 ) ;
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_26 ( V_2 -> V_3 -> V_4 ) ;
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_57 ) ) {
F_26 ( V_2 -> V_3 -> V_57 ) ;
F_26 ( V_2 -> V_3 -> V_49 ) ;
F_26 ( V_2 -> V_3 -> V_48 ) ;
}
F_26 ( V_2 -> V_3 -> V_11 ) ;
}
static T_3 F_29 ( int V_67 , void * V_68 )
{
struct V_6 * V_7 = V_68 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_30 ( V_7 ) ) {
F_31 ( & V_2 -> V_69 ) ;
} else {
V_2 -> V_10 = true ;
F_32 ( & V_2 -> V_12 ) ;
}
return V_70 ;
}
struct V_6 * F_33 ( struct V_37 * V_17 , int V_67 ,
void T_4 * V_71 ,
unsigned int V_72 ,
const struct V_73 * V_15 )
{
struct V_74 * V_3 = V_17 -> V_75 ;
struct V_1 * V_2 ;
int V_9 ;
struct V_6 * V_7 ;
V_7 = F_34 ( V_17 , sizeof( * V_2 ) ) ;
if ( ! V_7 )
return F_35 ( - V_76 ) ;
V_2 = F_6 ( V_7 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_31 = V_3 -> V_77 == 10000 ? 10000 : 5000 ;
V_9 = F_20 ( V_3 -> V_78 ) ;
if ( V_9 < 0 ) {
F_36 ( V_17 , L_13 ,
V_3 -> V_78 ) ;
V_2 -> V_45 = 0 ;
} else {
V_2 -> V_45 = V_3 -> V_78 ;
}
V_2 -> V_79 = F_37 ( V_17 , L_14 ) ;
if ( ! F_38 ( V_2 -> V_79 ) ) {
V_9 = F_39 ( V_2 -> V_79 ) ;
if ( V_9 )
return F_35 ( V_9 ) ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_20 = & V_80 [ V_72 ] ;
V_7 -> V_17 . V_81 = V_17 ;
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_57 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
V_7 -> V_82 = & V_83 ;
else
V_7 -> V_82 = & V_84 ;
} else {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
V_7 -> V_82 = & V_85 ;
else
V_7 -> V_82 = & V_86 ;
}
V_7 -> V_87 = V_88 ;
V_7 -> V_89 = V_2 -> V_20 -> V_89 ;
V_7 -> V_32 = V_2 -> V_20 -> V_32 ;
V_7 -> V_21 = V_2 -> V_20 -> V_21 ;
F_40 ( & V_2 -> V_12 ) ;
V_9 = F_23 ( V_2 ) ;
if ( V_9 )
goto V_90;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_36 ( V_2 -> V_17 , L_15 ) ;
V_9 = F_41 ( V_67 , F_29 ,
V_91 , V_2 -> V_20 -> V_89 , V_7 ) ;
if ( V_9 )
goto V_92;
V_9 = F_42 ( V_7 ) ;
if ( V_9 )
goto V_93;
V_9 = F_43 ( V_7 ) ;
if ( V_9 )
goto V_94;
return V_7 ;
V_94:
F_44 ( V_7 ) ;
V_93:
F_45 ( V_67 , V_7 ) ;
V_92:
F_28 ( V_2 ) ;
V_90:
if ( ! F_38 ( V_2 -> V_79 ) )
F_46 ( V_2 -> V_79 ) ;
return F_35 ( V_9 ) ;
}
int F_47 ( struct V_6 * V_7 , int V_67 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_48 ( V_7 ) ;
F_44 ( V_7 ) ;
F_45 ( V_67 , V_7 ) ;
if ( ! F_38 ( V_2 -> V_79 ) )
F_46 ( V_2 -> V_79 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_37 * V_17 )
{
struct V_6 * V_7 = F_50 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_62 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_3 ( V_2 -> V_3 -> V_44 , 1 ) ;
F_3 ( V_2 -> V_3 -> V_62 , 0 ) ;
}
return 0 ;
}
static int F_51 ( struct V_37 * V_17 )
{
struct V_6 * V_7 = F_50 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_62 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_3 ( V_2 -> V_3 -> V_44 ,
V_2 -> V_31 == 10000 ) ;
F_3 ( V_2 -> V_3 -> V_62 , 1 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
