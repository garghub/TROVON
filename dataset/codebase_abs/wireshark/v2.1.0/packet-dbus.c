static T_1
F_1 ( const char * V_1 )
{
if ( * V_1 != '/' )
return FALSE ;
do {
V_1 ++ ;
if ( * V_1 == '/' )
return FALSE ;
while ( ( * V_1 >= 'A' && * V_1 <= 'Z' ) || ( * V_1 >= 'a' && * V_1 <= 'z' ) || ( * V_1 >= '0' && * V_1 <= '9' ) || * V_1 == '_' )
V_1 ++ ;
if ( * V_1 == '\0' )
return TRUE ;
} while ( * V_1 == '/' );
return FALSE ;
}
static T_1
F_2 ( const char * T_2 V_2 )
{
return TRUE ;
}
static int
F_3 ( char T_2 )
{
switch ( T_2 ) {
case 'y' :
case 'g' :
return 1 ;
case 'n' :
case 'q' :
return 2 ;
case 'i' :
case 'u' :
case 'b' :
case 'o' :
case 'a' :
case 's' :
return 4 ;
case 'x' :
case 't' :
case 'd' :
return 8 ;
default:
return 1 ;
}
}
static int
F_4 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 , char T_2 , T_6 * V_7 )
{
T_7 * V_8 ;
const int V_9 = F_3 ( T_2 ) ;
const int V_10 = ( V_6 + V_9 - 1 ) / V_9 * V_9 ;
V_6 = V_10 ;
switch ( T_2 ) {
case 'y' :
{
T_8 V_11 ;
V_11 = F_5 ( V_3 , V_6 ) ;
V_6 += 1 ;
F_6 ( V_5 , V_12 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_1 , V_11 ) ;
V_7 -> V_14 = V_11 ;
return V_6 ;
}
case 'b' :
{
T_9 V_11 ;
V_11 = V_4 -> V_15 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_8 = F_7 ( V_5 , V_16 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_2 , V_11 ? L_3 : L_4 ) ;
if ( V_11 != 0 && V_11 != 1 ) {
F_8 ( V_4 -> V_17 , V_8 , & V_18 , L_5 , V_11 ) ;
return - 1 ;
}
V_7 -> V_14 = V_11 ;
return V_6 ;
}
case 'n' :
{
T_10 V_11 ;
V_11 = ( T_10 ) V_4 -> V_19 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_6 ( V_5 , V_20 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_6 , V_11 ) ;
return V_6 ;
}
case 'q' :
{
T_11 V_11 ;
V_11 = V_4 -> V_19 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_6 ( V_5 , V_12 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_7 , V_11 ) ;
V_7 -> V_14 = V_11 ;
return V_6 ;
}
case 'i' :
{
T_12 V_11 ;
V_11 = ( T_12 ) V_4 -> V_15 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_9 ( V_5 , V_20 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_8 , V_11 ) ;
return V_6 ;
}
case 'u' :
{
T_9 V_11 ;
V_11 = V_4 -> V_15 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_6 ( V_5 , V_12 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_9 , V_11 ) ;
V_7 -> V_14 = V_11 ;
return V_6 ;
}
case 'x' :
case 't' :
return - 1 ;
case 'd' :
{
T_13 V_11 ;
V_11 = V_4 -> V_21 ( V_3 , V_6 ) ;
V_6 += 8 ;
F_10 ( V_5 , V_22 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_10 F_11 ( V_23 ) L_11 , V_11 ) ;
return V_6 ;
}
case 's' :
case 'o' :
{
T_9 V_24 ;
char * V_11 ;
V_24 = V_4 -> V_15 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_11 = F_12 ( F_13 () , V_3 , V_6 , V_24 , V_25 ) ;
V_6 += ( V_24 + 1 ) ;
if ( T_2 == 's' ) {
V_8 = F_14 ( V_5 , V_26 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_12 , V_11 ) ;
if ( ! F_15 ( V_11 , - 1 , NULL ) ) {
F_16 ( V_4 -> V_17 , V_8 , & V_27 ) ;
return - 1 ;
}
} else {
V_8 = F_14 ( V_5 , V_26 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_13 , V_11 ) ;
if ( ! F_1 ( V_11 ) ) {
F_16 ( V_4 -> V_17 , V_8 , & V_28 ) ;
return - 1 ;
}
}
V_7 -> V_29 = V_11 ;
return V_6 ;
}
case 'g' :
{
T_8 V_24 ;
char * V_11 ;
V_24 = F_5 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_11 = F_12 ( F_13 () , V_3 , V_6 , V_24 , V_25 ) ;
V_6 += ( V_24 + 1 ) ;
V_8 = F_14 ( V_5 , V_26 . V_13 , V_3 , V_10 , V_6 - V_10 , V_11 , L_14 , V_11 ) ;
if ( ! F_2 ( V_11 ) ) {
F_16 ( V_4 -> V_17 , V_8 , & V_30 ) ;
return - 1 ;
}
V_7 -> V_29 = V_11 ;
return V_6 ;
}
}
return - 1 ;
}
static int
F_17 ( T_3 * V_3 , T_14 * V_17 , T_4 * V_4 , T_5 * V_5 , int V_6 , int V_31 )
{
const int V_10 = V_6 ;
T_7 * V_8 ;
T_15 V_32 ;
char * T_2 ;
V_32 = F_5 ( V_3 , V_6 ) ;
V_6 += 1 ;
T_2 = F_12 ( F_13 () , V_3 , V_6 , V_32 , V_25 ) ;
V_6 += ( V_32 + 1 ) ;
V_8 = F_18 ( V_5 , & V_33 , V_3 , V_10 , V_6 - V_10 , T_2 ) ;
if ( ! F_2 ( T_2 ) ) {
F_16 ( V_4 -> V_17 , V_8 , & V_30 ) ;
return - 1 ;
}
switch ( V_31 ) {
case V_34 :
if ( ! strcmp ( T_2 , L_15 ) ) {
T_6 V_35 ;
V_6 = F_4 ( V_3 , V_4 , V_5 , V_6 , 'u' , & V_35 ) ;
if ( V_6 != - 1 )
{ }
return V_6 ;
}
break;
case V_36 :
case V_37 :
if ( ! strcmp ( T_2 , L_16 ) ) {
T_6 V_38 ;
V_6 = F_4 ( V_3 , V_4 , V_5 , V_6 , 's' , & V_38 ) ;
if ( V_6 != - 1 )
F_19 ( ( V_31 == V_36 ) ? & V_4 -> V_17 -> V_39 : & V_4 -> V_17 -> V_40 ,
V_41 , ( int ) strlen ( V_38 . V_29 ) + 1 , F_20 ( V_17 -> V_42 , V_38 . V_29 ) ) ;
return V_6 ;
}
break;
case V_43 :
if ( ! strcmp ( T_2 , L_11 ) ) {
T_6 V_44 ;
V_6 = F_4 ( V_3 , V_4 , V_5 , V_6 , 'g' , & V_44 ) ;
if ( V_6 != - 1 )
V_4 -> V_45 = V_44 . V_29 ;
return V_6 ;
}
break;
}
while ( * T_2 ) {
T_6 V_11 ;
V_6 = F_4 ( V_3 , V_4 , V_5 , V_6 , * T_2 , & V_11 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
return V_6 ;
}
static int
F_21 ( T_3 * V_3 , T_14 * V_17 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
int V_46 ;
V_46 = V_6 + V_4 -> V_47 ;
while ( V_6 < V_46 ) {
T_5 * V_48 ;
T_7 * V_8 ;
T_8 V_31 ;
V_8 = F_22 ( V_5 , & V_49 , V_3 , V_6 , 0 , V_50 ) ;
V_48 = F_23 ( V_8 , V_51 ) ;
V_31 = F_5 ( V_3 , V_6 ) ;
F_22 ( V_48 , & V_52 , V_3 , V_6 , 1 , V_4 -> V_53 ) ;
F_24 ( V_8 , L_17 , F_25 ( V_31 , V_54 , L_18 ) ) ;
V_6 += 1 ;
V_6 = F_17 ( V_3 , V_17 , V_4 , V_48 , V_6 , V_31 ) ;
if ( V_6 == - 1 )
break;
V_6 = ( V_6 + 7 ) & ~ 7 ;
F_26 ( V_8 , V_3 , V_6 ) ;
}
if ( V_6 >= V_46 ) {
}
return V_46 ;
}
static int
F_27 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_55 ;
T_7 * V_8 ;
T_8 type ;
V_8 = F_22 ( V_5 , & V_56 , V_3 , V_6 , 0 , V_50 ) ;
V_55 = F_23 ( V_8 , V_57 ) ;
F_22 ( V_55 , & V_58 , V_3 , V_6 , 1 , V_25 | V_50 ) ;
V_6 += 1 ;
type = F_5 ( V_3 , V_6 ) ;
F_28 ( V_4 -> V_17 -> V_59 , V_60 , F_29 ( type , V_61 , L_19 ) ) ;
F_22 ( V_55 , & V_62 , V_3 , V_6 , 1 , V_4 -> V_53 ) ;
V_6 += 1 ;
F_22 ( V_55 , & V_63 , V_3 , V_6 , 1 , V_4 -> V_53 ) ;
V_6 += 1 ;
F_22 ( V_55 , & V_64 , V_3 , V_6 , 1 , V_4 -> V_53 ) ;
V_6 += 1 ;
V_4 -> V_65 = V_4 -> V_15 ( V_3 , V_6 ) ;
F_22 ( V_55 , & V_66 , V_3 , V_6 , 4 , V_4 -> V_53 ) ;
V_6 += 4 ;
F_22 ( V_55 , & V_67 , V_3 , V_6 , 4 , V_4 -> V_53 ) ;
V_6 += 4 ;
V_4 -> V_47 = V_4 -> V_15 ( V_3 , V_6 ) ;
F_22 ( V_55 , & V_68 , V_3 , V_6 , 4 , V_4 -> V_53 ) ;
V_6 += 4 ;
return V_6 ;
}
static int
F_30 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_69 ;
T_7 * V_8 ;
if ( V_4 -> V_65 && V_4 -> V_45 [ 0 ] ) {
const char * T_2 = V_4 -> V_45 ;
V_8 = F_22 ( V_5 , & V_70 , V_3 , V_6 , 0 , V_50 ) ;
V_69 = F_23 ( V_8 , V_71 ) ;
while ( * T_2 ) {
T_6 V_11 ;
V_6 = F_4 ( V_3 , V_4 , V_69 , V_6 , * T_2 , & V_11 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
F_26 ( V_8 , V_3 , V_6 ) ;
} else if ( V_4 -> V_65 || V_4 -> V_45 [ 0 ] ) {
}
return V_6 ;
}
static int
F_31 ( T_3 * V_3 , T_14 * V_17 , T_5 * V_5 , void * T_16 V_2 )
{
T_5 * V_72 = NULL ;
T_4 V_4 ;
int V_6 ;
F_28 ( V_17 -> V_59 , V_73 , L_20 ) ;
F_32 ( V_17 -> V_59 , V_60 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_17 = V_17 ;
switch ( F_5 ( V_3 , 0 ) ) {
case 'l' :
V_4 . V_53 = V_74 ;
V_4 . V_19 = V_75 ;
V_4 . V_15 = V_76 ;
V_4 . V_21 = V_77 ;
break;
case 'B' :
V_4 . V_53 = V_78 ;
V_4 . V_19 = V_79 ;
V_4 . V_15 = V_80 ;
V_4 . V_21 = V_81 ;
break;
default:
V_4 . V_53 = V_50 ;
V_4 . V_19 = V_79 ;
V_4 . V_15 = V_80 ;
V_4 . V_21 = V_81 ;
}
if ( V_5 ) {
T_7 * V_8 = F_22 ( V_5 , V_82 , V_3 , 0 , - 1 , V_50 ) ;
V_72 = F_23 ( V_8 , V_83 ) ;
}
V_6 = 0 ;
V_6 = F_27 ( V_3 , & V_4 , V_72 , V_6 ) ;
V_6 = F_21 ( V_3 , V_17 , & V_4 , V_72 , V_6 ) ;
V_6 = ( V_6 + 7 ) & ~ 7 ;
if ( ! V_4 . V_45 )
V_4 . V_45 = L_19 ;
V_6 = F_30 ( V_3 , & V_4 , V_72 , V_6 ) ;
return V_6 ;
}
static T_15
F_33 ( T_14 * V_17 V_2 , T_3 * V_3 ,
int V_6 , void * T_16 V_2 )
{
T_9 (* F_34)( T_3 * , const T_17 );
T_9 V_84 , V_85 ;
switch ( F_5 ( V_3 , V_6 ) ) {
case 'l' :
F_34 = V_76 ;
break;
case 'B' :
default:
F_34 = V_80 ;
break;
}
V_85 = V_86 + F_34 ( V_3 , V_6 + 12 ) ;
V_85 = ( V_85 + 7 ) & ~ 7 ;
V_84 = F_34 ( V_3 , V_6 + 4 ) ;
return V_85 + V_84 ;
}
static int
F_35 ( T_3 * V_3 , T_14 * V_17 , T_5 * V_5 , void * T_16 )
{
return F_31 ( V_3 , V_17 , V_5 , T_16 ) ;
}
static int
F_36 ( T_3 * V_3 , T_14 * V_17 , T_5 * V_5 , void * T_16 )
{
F_37 ( V_3 , V_17 , V_5 , V_87 , V_86 , F_33 , F_35 , T_16 ) ;
return F_38 ( V_3 ) ;
}
void
F_39 ( void )
{
#ifndef F_40
static T_18 * V_88 [] = {
& V_56 ,
& V_58 ,
& V_62 ,
& V_63 ,
& V_64 ,
& V_66 ,
& V_67 ,
& V_68 ,
& V_49 ,
& V_52 ,
& V_33 ,
& V_70 ,
& V_16 ,
& V_20 ,
& V_12 ,
& V_26 ,
& V_22 ,
} ;
#endif
static T_17 * V_89 [] = {
& V_83 ,
& V_57 ,
& V_71 ,
& V_51
} ;
static T_19 V_90 [] = {
{ & V_18 , { L_21 , V_91 , V_92 , L_22 , V_93 } } ,
{ & V_27 , { L_23 , V_91 , V_92 , L_24 , V_93 } } ,
{ & V_28 , { L_25 , V_91 , V_92 , L_26 , V_93 } } ,
{ & V_30 , { L_27 , V_91 , V_92 , L_28 , V_93 } } ,
} ;
T_20 * V_94 ;
int V_95 ;
V_95 = F_41 ( L_29 , L_20 , L_30 ) ;
V_82 = F_42 ( V_95 ) ;
F_43 ( V_95 , V_88 , F_44 ( V_88 ) ) ;
F_45 ( V_89 , F_44 ( V_89 ) ) ;
V_94 = F_46 ( V_95 ) ;
F_47 ( V_94 , V_90 , F_44 ( V_90 ) ) ;
V_96 = F_48 ( F_31 , V_95 ) ;
V_97 = F_48 ( F_36 , V_95 ) ;
}
void
F_49 ( void )
{
F_50 ( L_31 , V_98 , V_96 ) ;
F_51 ( L_32 , V_97 ) ;
}
