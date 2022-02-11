static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 -> V_3 , 0 ) ;
return 0 ;
}
return - V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_5 = V_2 -> V_6 -> V_7 ;
T_1 * V_8 = V_2 -> V_8 ;
int V_9 ;
if ( V_2 -> V_10 ) {
V_9 = V_2 -> V_11 -> V_12 ( V_2 -> V_13 , 1 , V_8 ) ;
if ( V_9 )
return V_9 ;
if ( ! F_5 ( V_2 -> V_10 ) ) {
F_1 ( V_2 ) ;
return - V_14 ;
}
V_8 ++ ;
V_5 -- ;
}
return V_2 -> V_11 -> V_12 ( V_2 -> V_13 , V_5 , V_8 ) ;
}
static T_2 F_6 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = F_7 ( V_18 -> V_19 ) ;
F_2 ( V_2 -> V_20 , 1 ) ;
return V_21 ;
}
static void F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 , struct V_1 ,
V_24 ) ;
struct V_25 * V_19 = F_10 ( V_2 ) ;
int V_9 ;
V_9 = F_4 ( V_2 ) ;
if ( V_9 == 0 )
F_11 ( V_19 , V_2 -> V_8 ,
F_12 ( V_19 ) ) ;
F_2 ( V_2 -> V_20 , 0 ) ;
F_13 ( V_19 -> V_26 ) ;
}
static int F_14 ( struct V_25 * V_19 , unsigned int V_27 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_9 ;
V_2 -> V_28 = false ;
F_2 ( V_2 -> V_20 , 1 ) ;
V_9 = F_15 ( V_2 -> V_29 , V_2 -> V_28 ) ;
if ( V_9 )
goto V_30;
V_9 = F_4 ( V_2 ) ;
if ( V_9 == 0 )
V_9 = V_2 -> V_8 [ V_27 ] ;
V_30:
F_2 ( V_2 -> V_20 , 0 ) ;
return V_9 ;
}
static int F_16 ( struct V_25 * V_19 ,
struct V_31 const * V_32 ,
int * V_33 ,
int * V_34 ,
long V_35 )
{
int V_9 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
switch ( V_35 ) {
case V_36 :
V_9 = F_17 ( V_19 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_14 ( V_19 , V_32 -> V_37 ) ;
F_18 ( V_19 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_33 = ( short ) V_9 ;
return V_38 ;
case V_39 :
* V_33 = V_2 -> V_40 * 2 ;
* V_34 = V_2 -> V_6 -> V_41 [ 0 ] . V_42 . V_43 ;
return V_44 ;
case V_45 :
* V_33 = V_2 -> V_46 ;
return V_38 ;
}
return - V_47 ;
}
static T_3 F_19 ( struct V_48 * V_13 ,
struct V_49 * V_50 , char * V_51 )
{
struct V_25 * V_19 = F_20 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
return sprintf ( V_51 , L_1 , V_2 -> V_40 ) ;
}
static T_3 F_21 ( struct V_48 * V_13 ,
struct V_49 * V_50 ,
const char * V_51 , T_4 V_52 )
{
struct V_25 * V_19 = F_20 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
unsigned long V_53 ;
int V_9 ;
V_9 = F_22 ( V_51 , 10 , & V_53 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_53 == 5000 || V_53 == 10000 ) )
return - V_47 ;
F_23 ( & V_19 -> V_54 ) ;
F_2 ( V_2 -> V_55 , V_53 == 10000 ) ;
V_2 -> V_40 = V_53 ;
F_24 ( & V_19 -> V_54 ) ;
return V_52 ;
}
static int F_25 ( unsigned int V_33 )
{
unsigned char V_56 [] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_57 ;
for ( V_57 = 0 ; V_57 < F_26 ( V_56 ) ; V_57 ++ )
if ( V_33 == V_56 [ V_57 ] )
return V_57 ;
return - V_47 ;
}
static int F_27 ( struct V_25 * V_19 ,
struct V_31 const * V_32 ,
int V_33 ,
int V_34 ,
long V_58 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_59 [ 3 ] ;
int V_9 ;
switch ( V_58 ) {
case V_45 :
if ( V_34 )
return - V_47 ;
V_9 = F_25 ( V_33 ) ;
if ( V_9 < 0 )
return V_9 ;
V_59 [ 0 ] = ( V_9 >> 0 ) & 1 ;
V_59 [ 1 ] = ( V_9 >> 1 ) & 1 ;
V_59 [ 2 ] = ( V_9 >> 2 ) & 1 ;
F_23 ( & V_19 -> V_54 ) ;
F_28 ( F_26 ( V_59 ) , V_2 -> V_60 -> V_61 ,
V_59 ) ;
V_2 -> V_46 = V_33 ;
F_24 ( & V_19 -> V_54 ) ;
return 0 ;
default:
return - V_47 ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_48 * V_13 = V_2 -> V_13 ;
V_2 -> V_20 = F_30 ( V_13 , L_2 ,
V_62 ) ;
if ( F_31 ( V_2 -> V_20 ) )
return F_32 ( V_2 -> V_20 ) ;
V_2 -> V_3 = F_33 ( V_13 , L_3 , V_62 ) ;
if ( F_31 ( V_2 -> V_3 ) )
return F_32 ( V_2 -> V_3 ) ;
V_2 -> V_55 = F_33 ( V_13 , L_4 , V_62 ) ;
if ( F_31 ( V_2 -> V_55 ) )
return F_32 ( V_2 -> V_55 ) ;
V_2 -> V_63 = F_33 ( V_13 , L_5 ,
V_64 ) ;
if ( F_31 ( V_2 -> V_63 ) )
return F_32 ( V_2 -> V_63 ) ;
V_2 -> V_10 = F_33 ( V_13 , L_6 ,
V_65 ) ;
if ( F_31 ( V_2 -> V_10 ) )
return F_32 ( V_2 -> V_10 ) ;
V_2 -> V_60 = F_34 ( V_13 , L_7 ,
V_62 ) ;
return F_35 ( V_2 -> V_60 ) ;
}
static T_2 F_36 ( int V_15 , void * V_66 )
{
struct V_25 * V_19 = V_66 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( F_37 ( V_19 ) ) {
F_38 ( & V_2 -> V_24 ) ;
} else {
V_2 -> V_28 = true ;
F_39 ( & V_2 -> V_29 ) ;
}
return V_21 ;
}
int F_40 ( struct V_48 * V_13 , int V_15 , void T_5 * V_67 ,
const char * V_68 , unsigned int V_69 ,
const struct V_70 * V_11 )
{
struct V_1 * V_2 ;
int V_9 ;
struct V_25 * V_19 ;
V_19 = F_41 ( V_13 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_71 ;
V_2 = F_7 ( V_19 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_40 = 5000 ;
V_2 -> V_46 = 1 ;
F_42 ( & V_2 -> V_24 , & F_8 ) ;
V_2 -> V_72 = F_43 ( V_13 , L_8 ) ;
if ( F_31 ( V_2 -> V_72 ) )
return F_32 ( V_2 -> V_72 ) ;
V_9 = F_44 ( V_2 -> V_72 ) ;
if ( V_9 ) {
F_45 ( V_13 , L_9 ) ;
return V_9 ;
}
V_9 = F_29 ( V_2 ) ;
if ( V_9 )
goto V_73;
V_2 -> V_6 = & V_74 [ V_69 ] ;
V_19 -> V_13 . V_75 = V_13 ;
if ( V_2 -> V_60 ) {
if ( V_2 -> V_55 )
V_19 -> V_76 = & V_77 ;
else
V_19 -> V_76 = & V_78 ;
} else {
if ( V_2 -> V_55 )
V_19 -> V_76 = & V_79 ;
else
V_19 -> V_76 = & V_80 ;
}
V_19 -> V_81 = V_82 ;
V_19 -> V_68 = V_68 ;
V_19 -> V_41 = V_2 -> V_6 -> V_41 ;
V_19 -> V_7 = V_2 -> V_6 -> V_7 ;
F_46 ( & V_2 -> V_29 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_47 ( V_2 -> V_13 , L_10 ) ;
V_9 = F_48 ( V_15 , F_36 , V_83 , V_68 ,
V_19 ) ;
if ( V_9 )
goto V_73;
V_9 = F_49 ( V_19 , & F_6 ,
NULL , NULL ) ;
if ( V_9 )
goto V_84;
V_9 = F_50 ( V_19 ) ;
if ( V_9 )
goto V_85;
F_51 ( V_13 , V_19 ) ;
return 0 ;
V_85:
F_52 ( V_19 ) ;
V_84:
F_53 ( V_15 , V_19 ) ;
V_73:
F_54 ( V_2 -> V_72 ) ;
return V_9 ;
}
int F_55 ( struct V_48 * V_13 , int V_15 )
{
struct V_25 * V_19 = F_56 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_57 ( V_19 ) ;
F_52 ( V_19 ) ;
F_53 ( V_15 , V_19 ) ;
F_54 ( V_2 -> V_72 ) ;
return 0 ;
}
static int F_58 ( struct V_48 * V_13 )
{
struct V_25 * V_19 = F_56 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( V_2 -> V_63 ) {
F_2 ( V_2 -> V_55 , 1 ) ;
F_2 ( V_2 -> V_63 , 0 ) ;
}
return 0 ;
}
static int F_59 ( struct V_48 * V_13 )
{
struct V_25 * V_19 = F_56 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( V_2 -> V_63 ) {
F_2 ( V_2 -> V_55 , V_2 -> V_40 == 10000 ) ;
F_2 ( V_2 -> V_63 , 1 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
