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
* V_33 = V_40 [ V_2 -> V_41 ] [ 0 ] ;
* V_34 = V_40 [ V_2 -> V_41 ] [ 1 ] ;
return V_42 ;
case V_43 :
* V_33 = V_2 -> V_44 ;
return V_38 ;
}
return - V_45 ;
}
static T_3 F_19 ( struct V_46 * V_13 ,
struct V_47 * V_48 ,
char * V_49 )
{
int V_50 , V_51 = 0 ;
for ( V_50 = 0 ; V_50 < F_20 ( V_40 ) ; V_50 ++ )
V_51 += F_21 ( V_49 + V_51 , V_52 - V_51 , L_1 ,
V_40 [ V_50 ] [ 0 ] , V_40 [ V_50 ] [ 1 ] ) ;
V_49 [ V_51 - 1 ] = '\n' ;
return V_51 ;
}
static int F_22 ( unsigned int V_33 )
{
unsigned char V_53 [] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 } ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_20 ( V_53 ) ; V_50 ++ )
if ( V_33 == V_53 [ V_50 ] )
return V_50 ;
return - V_45 ;
}
static int F_23 ( struct V_25 * V_19 ,
struct V_31 const * V_32 ,
int V_33 ,
int V_34 ,
long V_54 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_55 [ 3 ] ;
int V_9 , V_50 ;
switch ( V_54 ) {
case V_39 :
V_9 = - V_45 ;
F_24 ( & V_19 -> V_56 ) ;
for ( V_50 = 0 ; V_50 < F_20 ( V_40 ) ; V_50 ++ )
if ( V_34 == V_40 [ V_50 ] [ 1 ] ) {
F_2 ( V_2 -> V_57 , V_50 ) ;
V_2 -> V_41 = V_50 ;
V_9 = 0 ;
break;
}
F_25 ( & V_19 -> V_56 ) ;
return V_9 ;
case V_43 :
if ( V_34 )
return - V_45 ;
V_9 = F_22 ( V_33 ) ;
if ( V_9 < 0 )
return V_9 ;
V_55 [ 0 ] = ( V_9 >> 0 ) & 1 ;
V_55 [ 1 ] = ( V_9 >> 1 ) & 1 ;
V_55 [ 2 ] = ( V_9 >> 2 ) & 1 ;
F_24 ( & V_19 -> V_56 ) ;
F_26 ( F_20 ( V_55 ) , V_2 -> V_58 -> V_59 ,
V_55 ) ;
V_2 -> V_44 = V_33 ;
F_25 ( & V_19 -> V_56 ) ;
return 0 ;
default:
return - V_45 ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_46 * V_13 = V_2 -> V_13 ;
V_2 -> V_20 = F_28 ( V_13 , L_2 ,
V_60 ) ;
if ( F_29 ( V_2 -> V_20 ) )
return F_30 ( V_2 -> V_20 ) ;
V_2 -> V_3 = F_31 ( V_13 , L_3 , V_60 ) ;
if ( F_29 ( V_2 -> V_3 ) )
return F_30 ( V_2 -> V_3 ) ;
V_2 -> V_57 = F_31 ( V_13 , L_4 , V_60 ) ;
if ( F_29 ( V_2 -> V_57 ) )
return F_30 ( V_2 -> V_57 ) ;
V_2 -> V_61 = F_31 ( V_13 , L_5 ,
V_62 ) ;
if ( F_29 ( V_2 -> V_61 ) )
return F_30 ( V_2 -> V_61 ) ;
V_2 -> V_10 = F_31 ( V_13 , L_6 ,
V_63 ) ;
if ( F_29 ( V_2 -> V_10 ) )
return F_30 ( V_2 -> V_10 ) ;
V_2 -> V_58 = F_32 ( V_13 , L_7 ,
V_60 ) ;
return F_33 ( V_2 -> V_58 ) ;
}
static T_2 F_34 ( int V_15 , void * V_64 )
{
struct V_25 * V_19 = V_64 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
F_36 ( & V_2 -> V_24 ) ;
} else {
V_2 -> V_28 = true ;
F_37 ( & V_2 -> V_29 ) ;
}
return V_21 ;
}
int F_38 ( struct V_46 * V_13 , int V_15 , void T_4 * V_65 ,
const char * V_66 , unsigned int V_67 ,
const struct V_68 * V_11 )
{
struct V_1 * V_2 ;
int V_9 ;
struct V_25 * V_19 ;
V_19 = F_39 ( V_13 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_69 ;
V_2 = F_7 ( V_19 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_41 = 0 ;
V_2 -> V_44 = 1 ;
F_40 ( & V_2 -> V_24 , & F_8 ) ;
V_2 -> V_70 = F_41 ( V_13 , L_8 ) ;
if ( F_29 ( V_2 -> V_70 ) )
return F_30 ( V_2 -> V_70 ) ;
V_9 = F_42 ( V_2 -> V_70 ) ;
if ( V_9 ) {
F_43 ( V_13 , L_9 ) ;
return V_9 ;
}
V_9 = F_27 ( V_2 ) ;
if ( V_9 )
goto V_71;
V_2 -> V_6 = & V_72 [ V_67 ] ;
V_19 -> V_13 . V_73 = V_13 ;
if ( V_2 -> V_58 ) {
if ( V_2 -> V_57 )
V_19 -> V_74 = & V_75 ;
else
V_19 -> V_74 = & V_76 ;
} else {
if ( V_2 -> V_57 )
V_19 -> V_74 = & V_77 ;
else
V_19 -> V_74 = & V_78 ;
}
V_19 -> V_79 = V_80 ;
V_19 -> V_66 = V_66 ;
V_19 -> V_81 = V_2 -> V_6 -> V_81 ;
V_19 -> V_7 = V_2 -> V_6 -> V_7 ;
F_44 ( & V_2 -> V_29 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_45 ( V_2 -> V_13 , L_10 ) ;
V_9 = F_46 ( V_15 , F_34 , V_82 , V_66 ,
V_19 ) ;
if ( V_9 )
goto V_71;
V_9 = F_47 ( V_19 , & F_6 ,
NULL , NULL ) ;
if ( V_9 )
goto V_83;
V_9 = F_48 ( V_19 ) ;
if ( V_9 )
goto V_84;
F_49 ( V_13 , V_19 ) ;
return 0 ;
V_84:
F_50 ( V_19 ) ;
V_83:
F_51 ( V_15 , V_19 ) ;
V_71:
F_52 ( V_2 -> V_70 ) ;
return V_9 ;
}
int F_53 ( struct V_46 * V_13 , int V_15 )
{
struct V_25 * V_19 = F_54 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
F_55 ( V_19 ) ;
F_50 ( V_19 ) ;
F_51 ( V_15 , V_19 ) ;
F_52 ( V_2 -> V_70 ) ;
return 0 ;
}
static int F_56 ( struct V_46 * V_13 )
{
struct V_25 * V_19 = F_54 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( V_2 -> V_61 ) {
F_2 ( V_2 -> V_57 , 1 ) ;
F_2 ( V_2 -> V_61 , 0 ) ;
}
return 0 ;
}
static int F_57 ( struct V_46 * V_13 )
{
struct V_25 * V_19 = F_54 ( V_13 ) ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
if ( V_2 -> V_61 ) {
F_2 ( V_2 -> V_57 , V_2 -> V_41 ) ;
F_2 ( V_2 -> V_61 , 1 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
