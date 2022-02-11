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
case V_28 :
F_10 ( & V_7 -> V_29 ) ;
if ( F_11 ( V_7 ) )
V_9 = - V_30 ;
else
V_9 = F_5 ( V_7 , V_23 -> V_31 ) ;
F_12 ( & V_7 -> V_29 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_24 = ( short ) V_9 ;
return V_32 ;
case V_33 :
V_27 = ( V_2 -> V_34 * 1000 * 2 )
>> V_2 -> V_20 -> V_35 [ 0 ] . V_36 . V_37 ;
* V_24 = V_27 / 1000 ;
* V_25 = ( V_27 % 1000 ) * 1000 ;
return V_38 ;
}
return - V_39 ;
}
static T_1 F_13 ( struct V_40 * V_17 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_43 , L_1 , V_2 -> V_34 ) ;
}
static T_1 F_15 ( struct V_40 * V_17 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_44 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_45 ;
int V_9 ;
V_9 = F_16 ( V_43 , 10 , & V_45 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_45 == 5000 || V_45 == 10000 ) ) {
F_17 ( V_17 , L_2 ) ;
return - V_39 ;
}
F_10 ( & V_7 -> V_29 ) ;
F_3 ( V_2 -> V_3 -> V_46 , V_45 == 10000 ) ;
V_2 -> V_34 = V_45 ;
F_12 ( & V_7 -> V_29 ) ;
return V_44 ;
}
static T_1 F_18 ( struct V_40 * V_17 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_43 , L_1 , V_2 -> V_47 ) ;
}
static int F_19 ( unsigned V_24 )
{
unsigned char V_48 [] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_20 ( V_48 ) ; V_49 ++ )
if ( V_24 == V_48 [ V_49 ] )
return V_49 ;
return - V_39 ;
}
static T_1 F_21 ( struct V_40 * V_17 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_44 )
{
struct V_6 * V_7 = F_14 ( V_17 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_45 ;
int V_9 ;
V_9 = F_16 ( V_43 , 10 , & V_45 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_19 ( V_45 ) ;
if ( V_9 < 0 ) {
F_17 ( V_17 , L_3 , V_45 ) ;
return V_9 ;
}
F_10 ( & V_7 -> V_29 ) ;
F_3 ( V_2 -> V_3 -> V_50 , ( V_9 >> 0 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_51 , ( V_9 >> 1 ) & 1 ) ;
F_3 ( V_2 -> V_3 -> V_51 , ( V_9 >> 2 ) & 1 ) ;
V_2 -> V_47 = V_45 ;
F_12 ( & V_7 -> V_29 ) ;
return V_44 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_52 V_53 [ 3 ] = {
[ 0 ] = {
. V_52 = V_2 -> V_3 -> V_50 ,
. V_54 = V_55 | ( ( V_2 -> V_47 & 1 ) ?
V_56 : V_57 ) ,
. V_58 = L_4 ,
} ,
[ 1 ] = {
. V_52 = V_2 -> V_3 -> V_51 ,
. V_54 = V_55 | ( ( V_2 -> V_47 & 2 ) ?
V_56 : V_57 ) ,
. V_58 = L_5 ,
} ,
[ 2 ] = {
. V_52 = V_2 -> V_3 -> V_59 ,
. V_54 = V_55 | ( ( V_2 -> V_47 & 4 ) ?
V_56 : V_57 ) ,
. V_58 = L_6 ,
} ,
} ;
int V_9 ;
if ( F_2 ( V_2 -> V_3 -> V_11 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_11 ,
V_60 ,
L_7 ) ;
if ( V_9 ) {
F_17 ( V_2 -> V_17 , L_8 ) ;
goto V_13;
}
} else {
V_9 = - V_19 ;
goto V_13;
}
if ( F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_51 ) &&
F_2 ( V_2 -> V_3 -> V_59 ) ) {
V_9 = F_24 ( V_53 , F_20 ( V_53 ) ) ;
if ( V_9 < 0 )
goto V_61;
}
if ( F_2 ( V_2 -> V_3 -> V_4 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_4 ,
V_60 ,
L_9 ) ;
if ( V_9 < 0 )
goto V_62;
}
if ( F_2 ( V_2 -> V_3 -> V_46 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_46 , V_55 |
( ( V_2 -> V_34 == 10000 ) ? V_56 :
V_57 ) , L_10 ) ;
if ( V_9 < 0 )
goto V_63;
}
if ( F_2 ( V_2 -> V_3 -> V_64 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_64 ,
V_65 ,
L_11 ) ;
if ( V_9 < 0 )
goto V_66;
}
if ( F_2 ( V_2 -> V_3 -> V_14 ) ) {
V_9 = F_23 ( V_2 -> V_3 -> V_14 , V_67 ,
L_12 ) ;
if ( V_9 < 0 )
goto V_68;
}
return 0 ;
V_68:
if ( F_2 ( V_2 -> V_3 -> V_64 ) )
F_25 ( V_2 -> V_3 -> V_64 ) ;
V_66:
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
F_25 ( V_2 -> V_3 -> V_46 ) ;
V_63:
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_25 ( V_2 -> V_3 -> V_4 ) ;
V_62:
if ( F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_51 ) &&
F_2 ( V_2 -> V_3 -> V_59 ) )
F_26 ( V_53 , F_20 ( V_53 ) ) ;
V_61:
F_25 ( V_2 -> V_3 -> V_11 ) ;
V_13:
return V_9 ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> V_14 ) )
F_25 ( V_2 -> V_3 -> V_14 ) ;
if ( F_2 ( V_2 -> V_3 -> V_64 ) )
F_25 ( V_2 -> V_3 -> V_64 ) ;
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
F_25 ( V_2 -> V_3 -> V_46 ) ;
if ( F_2 ( V_2 -> V_3 -> V_4 ) )
F_25 ( V_2 -> V_3 -> V_4 ) ;
if ( F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_51 ) &&
F_2 ( V_2 -> V_3 -> V_59 ) ) {
F_25 ( V_2 -> V_3 -> V_59 ) ;
F_25 ( V_2 -> V_3 -> V_51 ) ;
F_25 ( V_2 -> V_3 -> V_50 ) ;
}
F_25 ( V_2 -> V_3 -> V_11 ) ;
}
static T_3 F_28 ( int V_69 , void * V_70 )
{
struct V_6 * V_7 = V_70 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_11 ( V_7 ) ) {
if ( ! F_29 ( & V_2 -> V_71 ) )
F_30 ( & V_2 -> V_71 ) ;
} else {
V_2 -> V_10 = true ;
F_31 ( & V_2 -> V_12 ) ;
}
return V_72 ;
}
struct V_6 * F_32 ( struct V_40 * V_17 , int V_69 ,
void T_4 * V_73 ,
unsigned V_74 ,
const struct V_75 * V_15 )
{
struct V_76 * V_3 = V_17 -> V_77 ;
struct V_1 * V_2 ;
int V_9 ;
struct V_6 * V_7 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_9 = - V_78 ;
goto V_13;
}
V_2 = F_6 ( V_7 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_34 = V_3 -> V_79 == 10000 ? 10000 : 5000 ;
V_9 = F_19 ( V_3 -> V_80 ) ;
if ( V_9 < 0 ) {
F_34 ( V_17 , L_13 ,
V_3 -> V_80 ) ;
V_2 -> V_47 = 0 ;
} else {
V_2 -> V_47 = V_3 -> V_80 ;
}
V_2 -> V_81 = F_35 ( V_17 , L_14 ) ;
if ( ! F_36 ( V_2 -> V_81 ) ) {
V_9 = F_37 ( V_2 -> V_81 ) ;
if ( V_9 )
goto V_82;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_20 = & V_83 [ V_74 ] ;
V_7 -> V_17 . V_84 = V_17 ;
if ( F_2 ( V_2 -> V_3 -> V_50 ) &&
F_2 ( V_2 -> V_3 -> V_51 ) &&
F_2 ( V_2 -> V_3 -> V_59 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
V_7 -> V_85 = & V_86 ;
else
V_7 -> V_85 = & V_87 ;
} else {
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
V_7 -> V_85 = & V_88 ;
else
V_7 -> V_85 = & V_89 ;
}
V_7 -> V_90 = V_91 ;
V_7 -> V_92 = V_2 -> V_20 -> V_92 ;
V_7 -> V_35 = V_2 -> V_20 -> V_35 ;
V_7 -> V_21 = V_2 -> V_20 -> V_21 ;
F_38 ( & V_2 -> V_12 ) ;
V_9 = F_22 ( V_2 ) ;
if ( V_9 )
goto V_93;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_34 ( V_2 -> V_17 , L_15 ) ;
V_9 = F_39 ( V_69 , F_28 ,
V_94 , V_2 -> V_20 -> V_92 , V_7 ) ;
if ( V_9 )
goto V_95;
V_9 = F_40 ( V_7 ) ;
if ( V_9 )
goto V_96;
V_9 = F_41 ( V_7 ) ;
if ( V_9 )
goto V_97;
return V_7 ;
V_97:
F_42 ( V_7 ) ;
V_96:
F_43 ( V_69 , V_7 ) ;
V_95:
F_27 ( V_2 ) ;
V_93:
if ( ! F_36 ( V_2 -> V_81 ) )
F_44 ( V_2 -> V_81 ) ;
V_82:
if ( ! F_36 ( V_2 -> V_81 ) )
F_45 ( V_2 -> V_81 ) ;
F_46 ( V_7 ) ;
V_13:
return F_47 ( V_9 ) ;
}
int F_48 ( struct V_6 * V_7 , int V_69 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_49 ( V_7 ) ;
F_42 ( V_7 ) ;
F_43 ( V_69 , V_7 ) ;
if ( ! F_36 ( V_2 -> V_81 ) ) {
F_44 ( V_2 -> V_81 ) ;
F_45 ( V_2 -> V_81 ) ;
}
F_27 ( V_2 ) ;
F_46 ( V_7 ) ;
return 0 ;
}
void F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_64 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
F_3 ( V_2 -> V_3 -> V_46 , 1 ) ;
F_3 ( V_2 -> V_3 -> V_64 , 0 ) ;
}
}
void F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( F_2 ( V_2 -> V_3 -> V_64 ) ) {
if ( F_2 ( V_2 -> V_3 -> V_46 ) )
F_3 ( V_2 -> V_3 -> V_46 ,
V_2 -> V_34 == 10000 ) ;
F_3 ( V_2 -> V_3 -> V_64 , 1 ) ;
F_1 ( V_2 ) ;
}
}
