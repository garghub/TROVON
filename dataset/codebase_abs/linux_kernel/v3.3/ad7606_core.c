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
V_9 = - V_29 ;
else
V_9 = F_5 ( V_7 , V_23 -> V_30 ) ;
F_12 ( & V_7 -> V_28 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_24 = ( short ) V_9 ;
return V_31 ;
case V_32 :
V_27 = ( V_2 -> V_33 * 1000 * 2 )
>> V_2 -> V_20 -> V_34 [ 0 ] . V_35 . V_36 ;
* V_24 = V_27 / 1000 ;
* V_25 = ( V_27 % 1000 ) * 1000 ;
return V_37 ;
}
return - V_38 ;
}
static T_1 F_13 ( struct V_39 * V_17 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_42 , L_1 , V_2 -> V_33 ) ;
}
static T_1 F_15 ( struct V_39 * V_17 ,
struct V_40 * V_41 , const char * V_42 , T_2 V_43 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_44 ;
if ( F_16 ( V_42 , 10 , & V_44 ) )
return - V_38 ;
if ( ! ( V_44 == 5000 || V_44 == 10000 ) ) {
F_17 ( V_17 , L_2 ) ;
return - V_38 ;
}
F_10 ( & V_7 -> V_28 ) ;
F_3 ( V_2 -> V_3 -> V_45 , V_44 == 10000 ) ;
V_2 -> V_33 = V_44 ;
F_12 ( & V_7 -> V_28 ) ;
return V_43 ;
}
static T_1 F_18 ( struct V_39 * V_17 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_42 , L_1 , V_2 -> V_46 ) ;
}
static int F_19 ( unsigned V_24 )
{
unsigned char V_47 [] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_48 ;
for ( V_48 = 0 ; V_48 < F_20 ( V_47 ) ; V_48 ++ )
if ( V_24 == V_47 [ V_48 ] )
return V_48 ;
return - V_38 ;
}
static T_1 F_21 ( struct V_39 * V_17 ,
struct V_40 * V_41 , const char * V_42 , T_2 V_43 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_44 ;
int V_9 ;
if ( F_16 ( V_42 , 10 , & V_44 ) )
return - V_38 ;
V_9 = F_19 ( V_44 ) ;
if ( V_9 < 0 ) {
F_17 ( V_17 , L_3 , V_44 ) ;
return V_9 ;
}
F_10 ( & V_7 -> V_28 ) ;
F_3 ( V_2 -> V_3 -> V_49 , ( V_9 >> 0 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_50 , ( V_9 >> 1 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_50 , ( V_9 >> 2 ) & 1 ) ;
V_2 -> V_46 = V_44 ;
F_12 ( & V_7 -> V_28 ) ;
return V_43 ;
}
static T_3 F_22 ( struct V_51 * V_52 ,
struct V_53 * V_41 , int V_54 )
{
struct V_39 * V_17 = F_23 ( V_52 , struct V_39 , V_52 ) ;
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_3 V_55 = V_41 -> V_55 ;
if ( ! ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_56 ) ) &&
( V_41 == & V_57 . V_58 . V_41 ||
V_41 ==
& V_59 . V_58 . V_41 ) )
V_55 = 0 ;
else if ( ! F_2 ( V_2 -> V_3 -> V_45 ) &&
( V_41 == & V_60 . V_58 . V_41 ||
V_41 ==
& V_61 . V_58 . V_41 ) )
V_55 = 0 ;
return V_55 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_62 V_63 [ 3 ] = {
[ 0 ] = {
. V_62 = V_2 -> V_3 -> V_49 ,
. V_64 = V_65 | ( ( V_2 -> V_46 & 1 ) ?
V_66 : V_67 ) ,
. V_68 = L_4 ,
} ,
[ 1 ] = {
. V_62 = V_2 -> V_3 -> V_50 ,
. V_64 = V_65 | ( ( V_2 -> V_46 & 2 ) ?
V_66 : V_67 ) ,
. V_68 = L_5 ,
} ,
[ 2 ] = {
. V_62 = V_2 -> V_3 -> V_56 ,
. V_64 = V_65 | ( ( V_2 -> V_46 & 4 ) ?
V_66 : V_67 ) ,
. V_68 = L_6 ,
} ,
} ;
int V_9 ;
if ( F_2 ( V_2 -> V_3 -> V_11 ) ) {
V_9 = F_25 ( V_2 -> V_3 -> V_11 ,
V_69 ,
L_7 ) ;
if ( V_9 ) {
F_17 ( V_2 -> V_17 , L_8 ) ;
goto V_13;
}
} else {
V_9 = - V_19 ;
goto V_13;
}
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_56 ) ) {
V_9 = F_26 ( V_63 , F_20 ( V_63 ) ) ;
if ( V_9 < 0 )
goto V_70;
}
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_9 = F_25 ( V_2 -> V_3 -> V_4 ,
V_69 ,
L_9 ) ;
if ( V_9 < 0 )
goto V_71;
}
if ( F_2 ( V_2 -> V_3 -> V_45 ) ) {
V_9 = F_25 ( V_2 -> V_3 -> V_45 , V_65 |
( ( V_2 -> V_33 == 10000 ) ? V_66 :
V_67 ) , L_10 ) ;
if ( V_9 < 0 )
goto V_72;
}
if ( F_2 ( V_2 -> V_3 -> V_73 ) ) {
V_9 = F_25 ( V_2 -> V_3 -> V_73 ,
V_74 ,
L_11 ) ;
if ( V_9 < 0 )
goto V_75;
}
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = F_25 ( V_2 -> V_3 -> V_14 , V_76 ,
L_12 ) ;
if ( V_9 < 0 )
goto V_77;
}
return 0 ;
V_77:
if ( F_2 ( V_2 -> V_3 -> V_73 ) )
F_27 ( V_2 -> V_3 -> V_73 ) ;
V_75:
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_27 ( V_2 -> V_3 -> V_45 ) ;
V_72:
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_27 ( V_2 -> V_3 -> V_4 ) ;
V_71:
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_56 ) )
F_28 ( V_63 , F_20 ( V_63 ) ) ;
V_70:
F_27 ( V_2 -> V_3 -> V_11 ) ;
V_13:
return V_9 ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_14 ) )
F_27 ( V_2 -> V_3 -> V_14 ) ;
if ( F_2 ( V_2 -> V_3 -> V_73 ) )
F_27 ( V_2 -> V_3 -> V_73 ) ;
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_27 ( V_2 -> V_3 -> V_45 ) ;
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_27 ( V_2 -> V_3 -> V_4 ) ;
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_56 ) ) {
F_27 ( V_2 -> V_3 -> V_56 ) ;
F_27 ( V_2 -> V_3 -> V_50 ) ;
F_27 ( V_2 -> V_3 -> V_49 ) ;
}
F_27 ( V_2 -> V_3 -> V_11 ) ;
}
static T_4 F_30 ( int V_78 , void * V_79 )
{
struct V_6 * V_7 = V_79 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_11 ( V_7 ) ) {
if ( ! F_31 ( & V_2 -> V_80 ) )
F_32 ( & V_2 -> V_80 ) ;
} else {
V_2 -> V_10 = true ;
F_33 ( & V_2 -> V_12 ) ;
}
return V_81 ;
}
struct V_6 * F_34 ( struct V_39 * V_17 , int V_78 ,
void T_5 * V_82 ,
unsigned V_83 ,
const struct V_84 * V_15 )
{
struct V_85 * V_3 = V_17 -> V_86 ;
struct V_1 * V_2 ;
int V_9 ;
struct V_6 * V_7 = F_35 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_9 = - V_87 ;
goto V_13;
}
V_2 = F_6 ( V_7 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_33 = V_3 -> V_88 == 10000 ? 10000 : 5000 ;
V_9 = F_19 ( V_3 -> V_89 ) ;
if ( V_9 < 0 ) {
F_36 ( V_17 , L_13 ,
V_3 -> V_89 ) ;
V_2 -> V_46 = 0 ;
} else {
V_2 -> V_46 = V_3 -> V_89 ;
}
V_2 -> V_90 = F_37 ( V_17 , L_14 ) ;
if ( ! F_38 ( V_2 -> V_90 ) ) {
V_9 = F_39 ( V_2 -> V_90 ) ;
if ( V_9 )
goto V_91;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_20 = & V_92 [ V_83 ] ;
V_7 -> V_17 . V_93 = V_17 ;
V_7 -> V_94 = & V_95 ;
V_7 -> V_96 = V_97 ;
V_7 -> V_98 = V_2 -> V_20 -> V_98 ;
V_7 -> V_34 = V_2 -> V_20 -> V_34 ;
V_7 -> V_21 = V_2 -> V_20 -> V_21 ;
F_40 ( & V_2 -> V_12 ) ;
V_9 = F_24 ( V_2 ) ;
if ( V_9 )
goto V_99;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_36 ( V_2 -> V_17 , L_15 ) ;
V_9 = F_41 ( V_78 , F_30 ,
V_100 , V_2 -> V_20 -> V_98 , V_7 ) ;
if ( V_9 )
goto V_101;
V_9 = F_42 ( V_7 ) ;
if ( V_9 )
goto V_102;
V_9 = F_43 ( V_7 ,
V_7 -> V_34 ,
V_7 -> V_21 ) ;
if ( V_9 )
goto V_103;
V_9 = F_44 ( V_7 ) ;
if ( V_9 )
goto V_104;
return V_7 ;
V_104:
F_45 ( V_7 ) ;
V_103:
F_46 ( V_7 ) ;
V_102:
F_47 ( V_78 , V_7 ) ;
V_101:
F_29 ( V_2 ) ;
V_99:
if ( ! F_38 ( V_2 -> V_90 ) )
F_48 ( V_2 -> V_90 ) ;
V_91:
if ( ! F_38 ( V_2 -> V_90 ) )
F_49 ( V_2 -> V_90 ) ;
F_50 ( V_7 ) ;
V_13:
return F_51 ( V_9 ) ;
}
int F_52 ( struct V_6 * V_7 , int V_78 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_53 ( V_7 ) ;
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_78 , V_7 ) ;
if ( ! F_38 ( V_2 -> V_90 ) ) {
F_48 ( V_2 -> V_90 ) ;
F_49 ( V_2 -> V_90 ) ;
}
F_29 ( V_2 ) ;
F_50 ( V_7 ) ;
return 0 ;
}
void F_54 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_73 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_3 ( V_2 -> V_3 -> V_45 , 1 ) ;
F_3 ( V_2 -> V_3 -> V_73 , 0 ) ;
}
}
void F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_73 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_3 ( V_2 -> V_3 -> V_45 ,
V_2 -> V_33 == 10000 ) ;
F_3 ( V_2 -> V_3 -> V_73 , 1 ) ;
F_1 ( V_2 ) ;
}
}
