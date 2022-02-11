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
static int F_22 ( struct V_1 * V_2 )
{
struct V_51 V_52 [ 3 ] = {
[ 0 ] = {
. V_51 = V_2 -> V_3 -> V_49 ,
. V_53 = V_54 | ( ( V_2 -> V_46 & 1 ) ?
V_55 : V_56 ) ,
. V_57 = L_4 ,
} ,
[ 1 ] = {
. V_51 = V_2 -> V_3 -> V_50 ,
. V_53 = V_54 | ( ( V_2 -> V_46 & 2 ) ?
V_55 : V_56 ) ,
. V_57 = L_5 ,
} ,
[ 2 ] = {
. V_51 = V_2 -> V_3 -> V_58 ,
. V_53 = V_54 | ( ( V_2 -> V_46 & 4 ) ?
V_55 : V_56 ) ,
. V_57 = L_6 ,
} ,
} ;
int V_9 ;
if ( F_2 ( V_2 -> V_3 -> V_11 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_11 ,
V_59 ,
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
F_2 ( V_2 -> V_3 -> V_58 ) ) {
V_9 = F_24 ( V_52 , F_20 ( V_52 ) ) ;
if ( V_9 < 0 )
goto V_60;
}
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_4 ,
V_59 ,
L_9 ) ;
if ( V_9 < 0 )
goto V_61;
}
if ( F_2 ( V_2 -> V_3 -> V_45 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_45 , V_54 |
( ( V_2 -> V_33 == 10000 ) ? V_55 :
V_56 ) , L_10 ) ;
if ( V_9 < 0 )
goto V_62;
}
if ( F_2 ( V_2 -> V_3 -> V_63 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_63 ,
V_64 ,
L_11 ) ;
if ( V_9 < 0 )
goto V_65;
}
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_14 , V_66 ,
L_12 ) ;
if ( V_9 < 0 )
goto V_67;
}
return 0 ;
V_67:
if ( F_2 ( V_2 -> V_3 -> V_63 ) )
F_25 ( V_2 -> V_3 -> V_63 ) ;
V_65:
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_25 ( V_2 -> V_3 -> V_45 ) ;
V_62:
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_25 ( V_2 -> V_3 -> V_4 ) ;
V_61:
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_58 ) )
F_26 ( V_52 , F_20 ( V_52 ) ) ;
V_60:
F_25 ( V_2 -> V_3 -> V_11 ) ;
V_13:
return V_9 ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_14 ) )
F_25 ( V_2 -> V_3 -> V_14 ) ;
if ( F_2 ( V_2 -> V_3 -> V_63 ) )
F_25 ( V_2 -> V_3 -> V_63 ) ;
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_25 ( V_2 -> V_3 -> V_45 ) ;
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_25 ( V_2 -> V_3 -> V_4 ) ;
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_58 ) ) {
F_25 ( V_2 -> V_3 -> V_58 ) ;
F_25 ( V_2 -> V_3 -> V_50 ) ;
F_25 ( V_2 -> V_3 -> V_49 ) ;
}
F_25 ( V_2 -> V_3 -> V_11 ) ;
}
static T_3 F_28 ( int V_68 , void * V_69 )
{
struct V_6 * V_7 = V_69 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_11 ( V_7 ) ) {
if ( ! F_29 ( & V_2 -> V_70 ) )
F_30 ( & V_2 -> V_70 ) ;
} else {
V_2 -> V_10 = true ;
F_31 ( & V_2 -> V_12 ) ;
}
return V_71 ;
}
struct V_6 * F_32 ( struct V_39 * V_17 , int V_68 ,
void T_4 * V_72 ,
unsigned V_73 ,
const struct V_74 * V_15 )
{
struct V_75 * V_3 = V_17 -> V_76 ;
struct V_1 * V_2 ;
int V_9 ;
struct V_6 * V_7 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_9 = - V_77 ;
goto V_13;
}
V_2 = F_6 ( V_7 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_33 = V_3 -> V_78 == 10000 ? 10000 : 5000 ;
V_9 = F_19 ( V_3 -> V_79 ) ;
if ( V_9 < 0 ) {
F_34 ( V_17 , L_13 ,
V_3 -> V_79 ) ;
V_2 -> V_46 = 0 ;
} else {
V_2 -> V_46 = V_3 -> V_79 ;
}
V_2 -> V_80 = F_35 ( V_17 , L_14 ) ;
if ( ! F_36 ( V_2 -> V_80 ) ) {
V_9 = F_37 ( V_2 -> V_80 ) ;
if ( V_9 )
goto V_81;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_20 = & V_82 [ V_73 ] ;
V_7 -> V_17 . V_83 = V_17 ;
if ( F_2 ( V_2 -> V_3 -> V_49 ) &&
F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_58 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
V_7 -> V_84 = & V_85 ;
else
V_7 -> V_84 = & V_86 ;
} else {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
V_7 -> V_84 = & V_87 ;
else
V_7 -> V_84 = & V_88 ;
}
V_7 -> V_89 = V_90 ;
V_7 -> V_91 = V_2 -> V_20 -> V_91 ;
V_7 -> V_34 = V_2 -> V_20 -> V_34 ;
V_7 -> V_21 = V_2 -> V_20 -> V_21 ;
F_38 ( & V_2 -> V_12 ) ;
V_9 = F_22 ( V_2 ) ;
if ( V_9 )
goto V_92;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_34 ( V_2 -> V_17 , L_15 ) ;
V_9 = F_39 ( V_68 , F_28 ,
V_93 , V_2 -> V_20 -> V_91 , V_7 ) ;
if ( V_9 )
goto V_94;
V_9 = F_40 ( V_7 ) ;
if ( V_9 )
goto V_95;
V_9 = F_41 ( V_7 ,
V_7 -> V_34 ,
V_7 -> V_21 ) ;
if ( V_9 )
goto V_96;
V_9 = F_42 ( V_7 ) ;
if ( V_9 )
goto V_97;
return V_7 ;
V_97:
F_43 ( V_7 ) ;
V_96:
F_44 ( V_7 ) ;
V_95:
F_45 ( V_68 , V_7 ) ;
V_94:
F_27 ( V_2 ) ;
V_92:
if ( ! F_36 ( V_2 -> V_80 ) )
F_46 ( V_2 -> V_80 ) ;
V_81:
if ( ! F_36 ( V_2 -> V_80 ) )
F_47 ( V_2 -> V_80 ) ;
F_48 ( V_7 ) ;
V_13:
return F_49 ( V_9 ) ;
}
int F_50 ( struct V_6 * V_7 , int V_68 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_51 ( V_7 ) ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
F_45 ( V_68 , V_7 ) ;
if ( ! F_36 ( V_2 -> V_80 ) ) {
F_46 ( V_2 -> V_80 ) ;
F_47 ( V_2 -> V_80 ) ;
}
F_27 ( V_2 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
void F_52 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_63 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_3 ( V_2 -> V_3 -> V_45 , 1 ) ;
F_3 ( V_2 -> V_3 -> V_63 , 0 ) ;
}
}
void F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_63 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_45 ) )
F_3 ( V_2 -> V_3 -> V_45 ,
V_2 -> V_33 == 10000 ) ;
F_3 ( V_2 -> V_3 -> V_63 , 1 ) ;
F_1 ( V_2 ) ;
}
}
