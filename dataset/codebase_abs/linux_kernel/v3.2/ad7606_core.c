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
static int F_5 ( struct V_6 * V_7 , unsigned V_8 )
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
unsigned int V_27 ;
switch ( V_26 ) {
case 0 :
F_10 ( & V_7 -> V_28 ) ;
if ( F_11 ( V_7 ) )
V_9 = F_12 ( V_7 , V_23 -> V_29 ) ;
else
V_9 = F_5 ( V_7 , V_23 -> V_29 ) ;
F_13 ( & V_7 -> V_28 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_24 = ( short ) V_9 ;
return V_30 ;
case ( 1 << V_31 ) :
V_27 = ( V_2 -> V_32 * 1000 * 2 )
>> V_2 -> V_20 -> V_33 [ 0 ] . V_34 . V_35 ;
* V_24 = V_27 / 1000 ;
* V_25 = ( V_27 % 1000 ) * 1000 ;
return V_36 ;
}
return - V_37 ;
}
static T_1 F_14 ( struct V_38 * V_17 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_6 * V_7 = F_15 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_41 , L_1 , V_2 -> V_32 ) ;
}
static T_1 F_16 ( struct V_38 * V_17 ,
struct V_39 * V_40 , const char * V_41 , T_2 V_42 )
{
struct V_6 * V_7 = F_15 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_43 ;
if ( F_17 ( V_41 , 10 , & V_43 ) )
return - V_37 ;
if ( ! ( V_43 == 5000 || V_43 == 10000 ) ) {
F_18 ( V_17 , L_2 ) ;
return - V_37 ;
}
F_10 ( & V_7 -> V_28 ) ;
F_3 ( V_2 -> V_3 -> V_44 , V_43 == 10000 ) ;
V_2 -> V_32 = V_43 ;
F_13 ( & V_7 -> V_28 ) ;
return V_42 ;
}
static T_1 F_19 ( struct V_38 * V_17 ,
struct V_39 * V_40 , char * V_41 )
{
struct V_6 * V_7 = F_15 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_41 , L_1 , V_2 -> V_45 ) ;
}
static int F_20 ( unsigned V_24 )
{
unsigned char V_46 [] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_21 ( V_46 ) ; V_47 ++ )
if ( V_24 == V_46 [ V_47 ] )
return V_47 ;
return - V_37 ;
}
static T_1 F_22 ( struct V_38 * V_17 ,
struct V_39 * V_40 , const char * V_41 , T_2 V_42 )
{
struct V_6 * V_7 = F_15 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_43 ;
int V_9 ;
if ( F_17 ( V_41 , 10 , & V_43 ) )
return - V_37 ;
V_9 = F_20 ( V_43 ) ;
if ( V_9 < 0 ) {
F_18 ( V_17 , L_3 , V_43 ) ;
return V_9 ;
}
F_10 ( & V_7 -> V_28 ) ;
F_3 ( V_2 -> V_3 -> V_48 , ( V_9 >> 0 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_49 , ( V_9 >> 1 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_49 , ( V_9 >> 2 ) & 1 ) ;
V_2 -> V_45 = V_43 ;
F_13 ( & V_7 -> V_28 ) ;
return V_42 ;
}
static T_3 F_23 ( struct V_50 * V_51 ,
struct V_52 * V_40 , int V_53 )
{
struct V_38 * V_17 = F_24 ( V_51 , struct V_38 , V_51 ) ;
struct V_6 * V_7 = F_15 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_3 V_54 = V_40 -> V_54 ;
if ( ! ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_55 ) ) &&
( V_40 == & V_56 . V_57 . V_40 ||
V_40 ==
& V_58 . V_57 . V_40 ) )
V_54 = 0 ;
else if ( ! F_2 ( V_2 -> V_3 -> V_44 ) &&
( V_40 == & V_59 . V_57 . V_40 ||
V_40 ==
& V_60 . V_57 . V_40 ) )
V_54 = 0 ;
return V_54 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_61 V_62 [ 3 ] = {
[ 0 ] = {
. V_61 = V_2 -> V_3 -> V_48 ,
. V_63 = V_64 | ( ( V_2 -> V_45 & 1 ) ?
V_65 : V_66 ) ,
. V_67 = L_4 ,
} ,
[ 1 ] = {
. V_61 = V_2 -> V_3 -> V_49 ,
. V_63 = V_64 | ( ( V_2 -> V_45 & 2 ) ?
V_65 : V_66 ) ,
. V_67 = L_5 ,
} ,
[ 2 ] = {
. V_61 = V_2 -> V_3 -> V_55 ,
. V_63 = V_64 | ( ( V_2 -> V_45 & 4 ) ?
V_65 : V_66 ) ,
. V_67 = L_6 ,
} ,
} ;
int V_9 ;
if ( F_2 ( V_2 -> V_3 -> V_11 ) ) {
V_9 = F_26 ( V_2 -> V_3 -> V_11 ,
V_68 ,
L_7 ) ;
if ( V_9 ) {
F_18 ( V_2 -> V_17 , L_8 ) ;
goto V_13;
}
} else {
V_9 = - V_19 ;
goto V_13;
}
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_55 ) ) {
V_9 = F_27 ( V_62 , F_21 ( V_62 ) ) ;
if ( V_9 < 0 )
goto V_69;
}
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_9 = F_26 ( V_2 -> V_3 -> V_4 ,
V_68 ,
L_9 ) ;
if ( V_9 < 0 )
goto V_70;
}
if ( F_2 ( V_2 -> V_3 -> V_44 ) ) {
V_9 = F_26 ( V_2 -> V_3 -> V_44 , V_64 |
( ( V_2 -> V_32 == 10000 ) ? V_65 :
V_66 ) , L_10 ) ;
if ( V_9 < 0 )
goto V_71;
}
if ( F_2 ( V_2 -> V_3 -> V_72 ) ) {
V_9 = F_26 ( V_2 -> V_3 -> V_72 ,
V_73 ,
L_11 ) ;
if ( V_9 < 0 )
goto V_74;
}
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = F_26 ( V_2 -> V_3 -> V_14 , V_75 ,
L_12 ) ;
if ( V_9 < 0 )
goto V_76;
}
return 0 ;
V_76:
if ( F_2 ( V_2 -> V_3 -> V_72 ) )
F_28 ( V_2 -> V_3 -> V_72 ) ;
V_74:
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_28 ( V_2 -> V_3 -> V_44 ) ;
V_71:
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_28 ( V_2 -> V_3 -> V_4 ) ;
V_70:
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_55 ) )
F_29 ( V_62 , F_21 ( V_62 ) ) ;
V_69:
F_28 ( V_2 -> V_3 -> V_11 ) ;
V_13:
return V_9 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_14 ) )
F_28 ( V_2 -> V_3 -> V_14 ) ;
if ( F_2 ( V_2 -> V_3 -> V_72 ) )
F_28 ( V_2 -> V_3 -> V_72 ) ;
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_28 ( V_2 -> V_3 -> V_44 ) ;
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_28 ( V_2 -> V_3 -> V_4 ) ;
if ( F_2 ( V_2 -> V_3 -> V_48 ) &&
F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_55 ) ) {
F_28 ( V_2 -> V_3 -> V_55 ) ;
F_28 ( V_2 -> V_3 -> V_49 ) ;
F_28 ( V_2 -> V_3 -> V_48 ) ;
}
F_28 ( V_2 -> V_3 -> V_11 ) ;
}
static T_4 F_31 ( int V_77 , void * V_78 )
{
struct V_6 * V_7 = V_78 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_11 ( V_7 ) ) {
if ( ! F_32 ( & V_2 -> V_79 ) )
F_33 ( & V_2 -> V_79 ) ;
} else {
V_2 -> V_10 = true ;
F_34 ( & V_2 -> V_12 ) ;
}
return V_80 ;
}
struct V_6 * F_35 ( struct V_38 * V_17 , int V_77 ,
void T_5 * V_81 ,
unsigned V_82 ,
const struct V_83 * V_15 )
{
struct V_84 * V_3 = V_17 -> V_85 ;
struct V_1 * V_2 ;
int V_9 ;
struct V_6 * V_7 = F_36 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_9 = - V_86 ;
goto V_13;
}
V_2 = F_6 ( V_7 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_32 = V_3 -> V_87 == 10000 ? 10000 : 5000 ;
V_9 = F_20 ( V_3 -> V_88 ) ;
if ( V_9 < 0 ) {
F_37 ( V_17 , L_13 ,
V_3 -> V_88 ) ;
V_2 -> V_45 = 0 ;
} else {
V_2 -> V_45 = V_3 -> V_88 ;
}
V_2 -> V_89 = F_38 ( V_17 , L_14 ) ;
if ( ! F_39 ( V_2 -> V_89 ) ) {
V_9 = F_40 ( V_2 -> V_89 ) ;
if ( V_9 )
goto V_90;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_20 = & V_91 [ V_82 ] ;
V_7 -> V_17 . V_92 = V_17 ;
V_7 -> V_93 = & V_94 ;
V_7 -> V_95 = V_96 ;
V_7 -> V_97 = V_2 -> V_20 -> V_97 ;
V_7 -> V_33 = V_2 -> V_20 -> V_33 ;
V_7 -> V_21 = V_2 -> V_20 -> V_21 ;
F_41 ( & V_2 -> V_12 ) ;
V_9 = F_25 ( V_2 ) ;
if ( V_9 )
goto V_98;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_37 ( V_2 -> V_17 , L_15 ) ;
V_9 = F_42 ( V_77 , F_31 ,
V_99 , V_2 -> V_20 -> V_97 , V_7 ) ;
if ( V_9 )
goto V_100;
V_9 = F_43 ( V_7 ) ;
if ( V_9 )
goto V_101;
V_9 = F_44 ( V_7 ,
V_7 -> V_33 ,
V_7 -> V_21 ) ;
if ( V_9 )
goto V_102;
V_9 = F_45 ( V_7 ) ;
if ( V_9 )
goto V_103;
return V_7 ;
V_103:
F_46 ( V_7 ) ;
V_102:
F_47 ( V_7 ) ;
V_101:
F_48 ( V_77 , V_7 ) ;
V_100:
F_30 ( V_2 ) ;
V_98:
if ( ! F_39 ( V_2 -> V_89 ) )
F_49 ( V_2 -> V_89 ) ;
V_90:
if ( ! F_39 ( V_2 -> V_89 ) )
F_50 ( V_2 -> V_89 ) ;
F_51 ( V_7 ) ;
V_13:
return F_52 ( V_9 ) ;
}
int F_53 ( struct V_6 * V_7 , int V_77 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_54 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_7 ) ;
F_48 ( V_77 , V_7 ) ;
if ( ! F_39 ( V_2 -> V_89 ) ) {
F_49 ( V_2 -> V_89 ) ;
F_50 ( V_2 -> V_89 ) ;
}
F_30 ( V_2 ) ;
F_51 ( V_7 ) ;
return 0 ;
}
void F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_72 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_3 ( V_2 -> V_3 -> V_44 , 1 ) ;
F_3 ( V_2 -> V_3 -> V_72 , 0 ) ;
}
}
void F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_72 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_44 ) )
F_3 ( V_2 -> V_3 -> V_44 ,
V_2 -> V_32 == 10000 ) ;
F_3 ( V_2 -> V_3 -> V_72 , 1 ) ;
F_1 ( V_2 ) ;
}
}
