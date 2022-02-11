int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( V_2 -> V_4 -> V_5 , 1 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 -> V_4 -> V_5 , 0 ) ;
return 0 ;
}
return - V_6 ;
}
static int F_4 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_10 ;
V_2 -> V_11 = false ;
F_2 ( V_2 -> V_4 -> V_12 , 1 ) ;
V_10 = F_6 ( V_2 -> V_13 , V_2 -> V_11 ) ;
if ( V_10 )
goto V_14;
if ( V_2 -> V_15 ) {
V_10 = V_2 -> V_16 -> V_17 ( V_2 -> V_18 , 1 , V_2 -> V_19 ) ;
if ( V_10 )
goto V_14;
if ( ! F_7 ( V_2 -> V_4 -> V_20 ) ) {
F_1 ( V_2 ) ;
V_10 = - V_21 ;
goto V_14;
}
V_10 = V_2 -> V_16 -> V_17 ( V_2 -> V_18 ,
V_2 -> V_22 -> V_23 - 1 , & V_2 -> V_19 [ 1 ] ) ;
if ( V_10 )
goto V_14;
} else {
V_10 = V_2 -> V_16 -> V_17 ( V_2 -> V_18 ,
V_2 -> V_22 -> V_23 , V_2 -> V_19 ) ;
if ( V_10 )
goto V_14;
}
V_10 = V_2 -> V_19 [ V_9 ] ;
V_14:
F_2 ( V_2 -> V_4 -> V_12 , 0 ) ;
return V_10 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_24 const * V_25 ,
int * V_26 ,
int * V_27 ,
long V_28 )
{
int V_10 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
unsigned int V_29 ;
switch ( V_28 ) {
case 0 :
F_9 ( & V_8 -> V_30 ) ;
if ( F_10 ( V_8 ) )
V_10 = F_11 ( V_8 , V_25 -> V_31 ) ;
else
V_10 = F_4 ( V_8 , V_25 -> V_31 ) ;
F_12 ( & V_8 -> V_30 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_26 = ( short ) V_10 ;
return V_32 ;
case ( 1 << V_33 ) :
V_29 = ( V_2 -> V_34 * 1000 * 2 )
>> V_2 -> V_22 -> V_35 [ 0 ] . V_36 . V_37 ;
* V_26 = V_29 / 1000 ;
* V_27 = ( V_29 % 1000 ) * 1000 ;
return V_38 ;
}
return - V_39 ;
}
static T_1 F_13 ( struct V_40 * V_18 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
return sprintf ( V_43 , L_1 , V_2 -> V_34 ) ;
}
static T_1 F_15 ( struct V_40 * V_18 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_44 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
unsigned long V_45 ;
if ( F_16 ( V_43 , 10 , & V_45 ) )
return - V_39 ;
if ( ! ( V_45 == 5000 || V_45 == 10000 ) ) {
F_17 ( V_18 , L_2 ) ;
return - V_39 ;
}
F_9 ( & V_8 -> V_30 ) ;
F_2 ( V_2 -> V_4 -> V_46 , V_45 == 10000 ) ;
V_2 -> V_34 = V_45 ;
F_12 ( & V_8 -> V_30 ) ;
return V_44 ;
}
static T_1 F_18 ( struct V_40 * V_18 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
return sprintf ( V_43 , L_1 , V_2 -> V_47 ) ;
}
static int F_19 ( unsigned V_26 )
{
unsigned char V_48 [] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_20 ( V_48 ) ; V_49 ++ )
if ( V_26 == V_48 [ V_49 ] )
return V_49 ;
return - V_39 ;
}
static T_1 F_21 ( struct V_40 * V_18 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_44 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
unsigned long V_45 ;
int V_10 ;
if ( F_16 ( V_43 , 10 , & V_45 ) )
return - V_39 ;
V_10 = F_19 ( V_45 ) ;
if ( V_10 < 0 ) {
F_17 ( V_18 , L_3 , V_45 ) ;
return V_10 ;
}
F_9 ( & V_8 -> V_30 ) ;
F_2 ( V_2 -> V_4 -> V_50 , ( V_10 >> 0 ) & 1 ) ;
F_2 ( V_2 -> V_4 -> V_51 , ( V_10 >> 1 ) & 1 ) ;
F_2 ( V_2 -> V_4 -> V_51 , ( V_10 >> 2 ) & 1 ) ;
V_2 -> V_47 = V_45 ;
F_12 ( & V_8 -> V_30 ) ;
return V_44 ;
}
static T_3 F_22 ( struct V_52 * V_53 ,
struct V_54 * V_42 , int V_55 )
{
struct V_40 * V_18 = F_23 ( V_53 , struct V_40 , V_53 ) ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
T_3 V_56 = V_42 -> V_56 ;
if ( ! V_2 -> V_57 &&
( V_42 == & V_58 . V_59 . V_42 ||
V_42 ==
& V_60 . V_59 . V_42 ) )
V_56 = 0 ;
else if ( ! V_2 -> V_61 &&
( V_42 == & V_62 . V_59 . V_42 ||
V_42 == & V_63 . V_59 . V_42 ) )
V_56 = 0 ;
return V_56 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_64 V_65 [ 3 ] = {
[ 0 ] = {
. V_64 = V_2 -> V_4 -> V_50 ,
. V_66 = V_67 | ( ( V_2 -> V_47 & 1 ) ?
V_68 : V_69 ) ,
. V_70 = L_4 ,
} ,
[ 1 ] = {
. V_64 = V_2 -> V_4 -> V_51 ,
. V_66 = V_67 | ( ( V_2 -> V_47 & 2 ) ?
V_68 : V_69 ) ,
. V_70 = L_5 ,
} ,
[ 2 ] = {
. V_64 = V_2 -> V_4 -> V_71 ,
. V_66 = V_67 | ( ( V_2 -> V_47 & 4 ) ?
V_68 : V_69 ) ,
. V_70 = L_6 ,
} ,
} ;
int V_10 ;
V_10 = F_25 ( V_2 -> V_4 -> V_12 , V_72 ,
L_7 ) ;
if ( V_10 ) {
F_17 ( V_2 -> V_18 , L_8 ) ;
return V_10 ;
}
V_10 = F_26 ( V_65 , F_20 ( V_65 ) ) ;
if ( ! V_10 ) {
V_2 -> V_57 = true ;
}
V_10 = F_25 ( V_2 -> V_4 -> V_5 , V_72 ,
L_9 ) ;
if ( ! V_10 )
V_2 -> V_3 = true ;
V_10 = F_25 ( V_2 -> V_4 -> V_46 , V_67 |
( ( V_2 -> V_34 == 10000 ) ? V_68 :
V_69 ) , L_10 ) ;
if ( ! V_10 )
V_2 -> V_61 = true ;
V_10 = F_25 ( V_2 -> V_4 -> V_73 , V_74 ,
L_11 ) ;
if ( ! V_10 )
V_2 -> V_75 = true ;
if ( F_27 ( V_2 -> V_4 -> V_20 ) ) {
V_10 = F_25 ( V_2 -> V_4 -> V_20 , V_76 ,
L_12 ) ;
if ( ! V_10 )
V_2 -> V_15 = true ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 )
F_29 ( V_2 -> V_4 -> V_46 ) ;
if ( V_2 -> V_75 )
F_29 ( V_2 -> V_4 -> V_73 ) ;
if ( V_2 -> V_57 ) {
F_29 ( V_2 -> V_4 -> V_50 ) ;
F_29 ( V_2 -> V_4 -> V_51 ) ;
F_29 ( V_2 -> V_4 -> V_71 ) ;
}
if ( V_2 -> V_3 )
F_29 ( V_2 -> V_4 -> V_5 ) ;
if ( V_2 -> V_15 )
F_29 ( V_2 -> V_4 -> V_20 ) ;
F_29 ( V_2 -> V_4 -> V_12 ) ;
}
static T_4 F_30 ( int V_77 , void * V_78 )
{
struct V_7 * V_8 = V_78 ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( F_10 ( V_8 ) ) {
if ( ! F_31 ( & V_2 -> V_79 ) )
F_32 ( & V_2 -> V_79 ) ;
} else {
V_2 -> V_11 = true ;
F_33 ( & V_2 -> V_13 ) ;
}
return V_80 ;
}
struct V_7 * F_34 ( struct V_40 * V_18 , int V_77 ,
void T_5 * V_81 ,
unsigned V_82 ,
const struct V_83 * V_16 )
{
struct V_84 * V_4 = V_18 -> V_85 ;
struct V_1 * V_2 ;
int V_10 , V_86 = 0 ;
struct V_7 * V_8 = F_35 ( sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
V_10 = - V_87 ;
goto V_14;
}
V_2 = F_5 ( V_8 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_34 = V_4 -> V_88 == 10000 ? 10000 : 5000 ;
V_10 = F_19 ( V_4 -> V_89 ) ;
if ( V_10 < 0 ) {
F_36 ( V_18 , L_13 ,
V_4 -> V_89 ) ;
V_2 -> V_47 = 0 ;
} else {
V_2 -> V_47 = V_4 -> V_89 ;
}
V_2 -> V_90 = F_37 ( V_18 , L_14 ) ;
if ( ! F_38 ( V_2 -> V_90 ) ) {
V_10 = F_39 ( V_2 -> V_90 ) ;
if ( V_10 )
goto V_91;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_22 = & V_92 [ V_82 ] ;
V_8 -> V_18 . V_93 = V_18 ;
V_8 -> V_94 = & V_95 ;
V_8 -> V_96 = V_97 ;
V_8 -> V_98 = V_2 -> V_22 -> V_98 ;
V_8 -> V_35 = V_2 -> V_22 -> V_35 ;
V_8 -> V_23 = V_2 -> V_22 -> V_23 ;
F_40 ( & V_2 -> V_13 ) ;
V_10 = F_24 ( V_2 ) ;
if ( V_10 )
goto V_99;
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
F_36 ( V_2 -> V_18 , L_15 ) ;
V_10 = F_41 ( V_2 -> V_77 , F_30 ,
V_100 , V_2 -> V_22 -> V_98 , V_8 ) ;
if ( V_10 )
goto V_101;
V_10 = F_42 ( V_8 ) ;
if ( V_10 )
goto V_102;
V_10 = F_43 ( V_8 ) ;
if ( V_10 )
goto V_102;
V_86 = 1 ;
V_10 = F_44 ( V_8 -> V_103 , 0 ,
V_8 -> V_35 ,
V_8 -> V_23 ) ;
if ( V_10 )
goto V_104;
return V_8 ;
V_104:
F_45 ( V_8 ) ;
V_102:
F_46 ( V_2 -> V_77 , V_8 ) ;
V_101:
F_28 ( V_2 ) ;
V_99:
if ( ! F_38 ( V_2 -> V_90 ) )
F_47 ( V_2 -> V_90 ) ;
V_91:
if ( ! F_38 ( V_2 -> V_90 ) )
F_48 ( V_2 -> V_90 ) ;
if ( V_86 )
F_49 ( V_8 ) ;
else
F_50 ( V_8 ) ;
V_14:
return F_51 ( V_10 ) ;
}
int F_52 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
F_53 ( V_8 -> V_103 ) ;
F_45 ( V_8 ) ;
F_46 ( V_2 -> V_77 , V_8 ) ;
if ( ! F_38 ( V_2 -> V_90 ) ) {
F_47 ( V_2 -> V_90 ) ;
F_48 ( V_2 -> V_90 ) ;
}
F_28 ( V_2 ) ;
F_49 ( V_8 ) ;
return 0 ;
}
void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_61 )
F_2 ( V_2 -> V_4 -> V_46 , 1 ) ;
F_2 ( V_2 -> V_4 -> V_73 , 0 ) ;
}
}
void F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_61 )
F_2 ( V_2 -> V_4 -> V_46 ,
V_2 -> V_34 == 10000 ) ;
F_2 ( V_2 -> V_4 -> V_73 , 1 ) ;
F_1 ( V_2 ) ;
}
}
