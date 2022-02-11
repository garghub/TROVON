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
F_3 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 , char T_2 , T_6 * V_7 )
{
const int V_8 = V_6 ;
T_7 * V_9 ;
switch ( T_2 ) {
case 'y' :
{
T_8 V_10 ;
V_10 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
F_5 ( V_5 , V_11 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_1 , V_10 ) ;
V_7 -> V_13 = V_10 ;
return V_6 ;
}
case 'b' :
{
T_9 V_10 ;
V_10 = V_4 -> V_14 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_9 = F_6 ( V_5 , V_15 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_2 , V_10 ? L_3 : L_4 ) ;
if ( V_10 != 0 && V_10 != 1 ) {
F_7 ( V_4 -> V_16 , V_9 , & V_17 , L_5 , V_10 ) ;
return - 1 ;
}
V_7 -> V_13 = V_10 ;
return V_6 ;
}
case 'n' :
{
T_10 V_10 ;
V_10 = ( T_10 ) V_4 -> V_18 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_5 ( V_5 , V_19 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_6 , V_10 ) ;
return V_6 ;
}
case 'q' :
{
T_11 V_10 ;
V_10 = V_4 -> V_18 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_5 ( V_5 , V_11 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_7 , V_10 ) ;
V_7 -> V_13 = V_10 ;
return V_6 ;
}
case 'i' :
{
T_12 V_10 ;
V_10 = ( T_12 ) V_4 -> V_14 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_8 ( V_5 , V_19 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_8 , V_10 ) ;
return V_6 ;
}
case 'u' :
{
T_9 V_10 ;
V_10 = V_4 -> V_14 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_5 ( V_5 , V_11 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_9 , V_10 ) ;
V_7 -> V_13 = V_10 ;
return V_6 ;
}
case 'x' :
case 't' :
return - 1 ;
case 'd' :
{
T_13 V_10 ;
V_10 = V_4 -> V_20 ( V_3 , V_6 ) ;
V_6 += 8 ;
F_9 ( V_5 , V_21 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_10 F_10 ( V_22 ) L_11 , V_10 ) ;
return V_6 ;
}
case 's' :
case 'o' :
{
T_9 V_23 ;
char * V_10 ;
V_23 = V_4 -> V_14 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_10 = F_11 ( F_12 () , V_3 , V_6 , V_23 , V_24 ) ;
V_6 += ( V_23 + 1 + 3 ) & ~ 3 ;
if ( T_2 == 's' ) {
V_9 = F_13 ( V_5 , V_25 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_12 , V_10 ) ;
if ( ! F_14 ( V_10 , - 1 , NULL ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_26 ) ;
return - 1 ;
}
} else {
V_9 = F_13 ( V_5 , V_25 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_13 , V_10 ) ;
if ( ! F_1 ( V_10 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_27 ) ;
return - 1 ;
}
}
V_7 -> V_28 = V_10 ;
return V_6 ;
}
case 'g' :
{
T_8 V_23 ;
char * V_10 ;
V_23 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_10 = F_11 ( F_12 () , V_3 , V_6 , V_23 , V_24 ) ;
V_6 += ( V_23 + 1 ) ;
V_9 = F_13 ( V_5 , V_25 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_14 , V_10 ) ;
if ( ! F_2 ( V_10 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_29 ) ;
return - 1 ;
}
V_7 -> V_28 = V_10 ;
return V_6 ;
}
}
return - 1 ;
}
static int
F_16 ( T_3 * V_3 , T_14 * V_16 , T_4 * V_4 , T_5 * V_5 , int V_6 , int V_30 )
{
const int V_8 = V_6 ;
T_7 * V_9 ;
T_15 V_31 ;
char * T_2 ;
V_31 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
T_2 = F_11 ( F_12 () , V_3 , V_6 , V_31 , V_24 ) ;
V_6 += ( V_31 + 1 ) ;
V_9 = F_17 ( V_5 , & V_32 , V_3 , V_8 , V_6 - V_8 , T_2 ) ;
if ( ! F_2 ( T_2 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_29 ) ;
return - 1 ;
}
switch ( V_30 ) {
case V_33 :
if ( ! strcmp ( T_2 , L_15 ) ) {
T_6 V_34 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'u' , & V_34 ) ;
if ( V_6 != - 1 )
{ }
return V_6 ;
}
break;
case V_35 :
case V_36 :
if ( ! strcmp ( T_2 , L_16 ) ) {
T_6 V_37 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 's' , & V_37 ) ;
if ( V_6 != - 1 )
F_18 ( ( V_30 == V_35 ) ? & V_4 -> V_16 -> V_38 : & V_4 -> V_16 -> V_39 ,
V_40 , ( int ) strlen ( V_37 . V_28 ) + 1 , F_19 ( V_16 -> V_41 , V_37 . V_28 ) ) ;
return V_6 ;
}
break;
case V_42 :
if ( ! strcmp ( T_2 , L_11 ) ) {
T_6 V_43 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'g' , & V_43 ) ;
if ( V_6 != - 1 )
V_4 -> V_44 = V_43 . V_28 ;
return V_6 ;
}
break;
}
while ( * T_2 ) {
T_6 V_10 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , * T_2 , & V_10 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
return V_6 ;
}
static int
F_20 ( T_3 * V_3 , T_14 * V_16 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
int V_45 ;
V_45 = V_6 + V_4 -> V_46 ;
while ( V_6 < V_45 ) {
T_5 * V_47 ;
T_7 * V_9 ;
T_8 V_30 ;
V_9 = F_21 ( V_5 , & V_48 , V_3 , V_6 , 0 , V_49 ) ;
V_47 = F_22 ( V_9 , V_50 ) ;
V_30 = F_4 ( V_3 , V_6 ) ;
F_21 ( V_47 , & V_51 , V_3 , V_6 , 1 , V_4 -> V_52 ) ;
F_23 ( V_9 , L_17 , F_24 ( V_30 , V_53 , L_18 ) ) ;
V_6 += 1 ;
V_6 = F_16 ( V_3 , V_16 , V_4 , V_47 , V_6 , V_30 ) ;
if ( V_6 == - 1 )
break;
V_6 = ( V_6 + 7 ) & ~ 7 ;
F_25 ( V_9 , V_3 , V_6 ) ;
}
if ( V_6 >= V_45 ) {
}
return V_45 ;
}
static int
F_26 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_54 ;
T_7 * V_9 ;
T_8 type ;
V_9 = F_21 ( V_5 , & V_55 , V_3 , V_6 , 0 , V_49 ) ;
V_54 = F_22 ( V_9 , V_56 ) ;
F_21 ( V_54 , & V_57 , V_3 , V_6 , 1 , V_24 | V_49 ) ;
V_6 += 1 ;
type = F_4 ( V_3 , V_6 ) ;
F_27 ( V_4 -> V_16 -> V_58 , V_59 , F_28 ( type , V_60 , L_19 ) ) ;
F_21 ( V_54 , & V_61 , V_3 , V_6 , 1 , V_4 -> V_52 ) ;
V_6 += 1 ;
F_21 ( V_54 , & V_62 , V_3 , V_6 , 1 , V_4 -> V_52 ) ;
V_6 += 1 ;
F_21 ( V_54 , & V_63 , V_3 , V_6 , 1 , V_4 -> V_52 ) ;
V_6 += 1 ;
V_4 -> V_64 = V_4 -> V_14 ( V_3 , V_6 ) ;
F_21 ( V_54 , & V_65 , V_3 , V_6 , 4 , V_4 -> V_52 ) ;
V_6 += 4 ;
F_21 ( V_54 , & V_66 , V_3 , V_6 , 4 , V_4 -> V_52 ) ;
V_6 += 4 ;
V_4 -> V_46 = V_4 -> V_14 ( V_3 , V_6 ) ;
F_21 ( V_54 , & V_67 , V_3 , V_6 , 4 , V_4 -> V_52 ) ;
V_6 += 4 ;
return V_6 ;
}
static int
F_29 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_68 ;
T_7 * V_9 ;
if ( V_4 -> V_64 && V_4 -> V_44 [ 0 ] ) {
const char * T_2 = V_4 -> V_44 ;
V_9 = F_21 ( V_5 , & V_69 , V_3 , V_6 , 0 , V_49 ) ;
V_68 = F_22 ( V_9 , V_70 ) ;
while ( * T_2 ) {
T_6 V_10 ;
V_6 = F_3 ( V_3 , V_4 , V_68 , V_6 , * T_2 , & V_10 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
F_25 ( V_9 , V_3 , V_6 ) ;
} else if ( V_4 -> V_64 || V_4 -> V_44 [ 0 ] ) {
}
return V_6 ;
}
static int
F_30 ( T_3 * V_3 , T_14 * V_16 , T_5 * V_5 , void * T_16 V_2 )
{
T_5 * V_71 = NULL ;
T_4 V_4 ;
int V_6 ;
F_27 ( V_16 -> V_58 , V_72 , L_20 ) ;
F_31 ( V_16 -> V_58 , V_59 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_16 ;
switch ( F_4 ( V_3 , 0 ) ) {
case 'l' :
V_4 . V_52 = V_73 ;
V_4 . V_18 = V_74 ;
V_4 . V_14 = V_75 ;
V_4 . V_20 = V_76 ;
break;
case 'B' :
V_4 . V_52 = V_77 ;
V_4 . V_18 = V_78 ;
V_4 . V_14 = V_79 ;
V_4 . V_20 = V_80 ;
break;
default:
V_4 . V_52 = V_49 ;
V_4 . V_18 = V_78 ;
V_4 . V_14 = V_79 ;
V_4 . V_20 = V_80 ;
}
if ( V_5 ) {
T_7 * V_9 = F_21 ( V_5 , V_81 , V_3 , 0 , - 1 , V_49 ) ;
V_71 = F_22 ( V_9 , V_82 ) ;
}
V_6 = 0 ;
V_6 = F_26 ( V_3 , & V_4 , V_71 , V_6 ) ;
V_6 = F_20 ( V_3 , V_16 , & V_4 , V_71 , V_6 ) ;
V_6 = ( V_6 + 7 ) & ~ 7 ;
if ( ! V_4 . V_44 )
V_4 . V_44 = L_19 ;
V_6 = F_29 ( V_3 , & V_4 , V_71 , V_6 ) ;
return V_6 ;
}
static T_15
F_32 ( T_14 * V_16 V_2 , T_3 * V_3 ,
int V_6 , void * T_16 V_2 )
{
T_9 (* F_33)( T_3 * , const T_17 );
T_9 V_83 , V_84 ;
switch ( F_4 ( V_3 , V_6 ) ) {
case 'l' :
F_33 = V_75 ;
break;
case 'B' :
default:
F_33 = V_79 ;
break;
}
V_84 = V_85 + F_33 ( V_3 , V_6 + 12 ) ;
V_84 = ( V_84 + 7 ) & ~ 7 ;
V_83 = F_33 ( V_3 , V_6 + 4 ) ;
return V_84 + V_83 ;
}
static int
F_34 ( T_3 * V_3 , T_14 * V_16 , T_5 * V_5 , void * T_16 )
{
return F_30 ( V_3 , V_16 , V_5 , T_16 ) ;
}
static int
F_35 ( T_3 * V_3 , T_14 * V_16 , T_5 * V_5 , void * T_16 )
{
F_36 ( V_3 , V_16 , V_5 , V_86 , V_85 , F_32 , F_34 , T_16 ) ;
return F_37 ( V_3 ) ;
}
void
F_38 ( void )
{
#ifndef F_39
static T_18 * V_87 [] = {
& V_55 ,
& V_57 ,
& V_61 ,
& V_62 ,
& V_63 ,
& V_65 ,
& V_66 ,
& V_67 ,
& V_48 ,
& V_51 ,
& V_32 ,
& V_69 ,
& V_15 ,
& V_19 ,
& V_11 ,
& V_25 ,
& V_21 ,
} ;
#endif
static T_17 * V_88 [] = {
& V_82 ,
& V_56 ,
& V_70 ,
& V_50
} ;
static T_19 V_89 [] = {
{ & V_17 , { L_21 , V_90 , V_91 , L_22 , V_92 } } ,
{ & V_26 , { L_23 , V_90 , V_91 , L_24 , V_92 } } ,
{ & V_27 , { L_25 , V_90 , V_91 , L_26 , V_92 } } ,
{ & V_29 , { L_27 , V_90 , V_91 , L_28 , V_92 } } ,
} ;
T_20 * V_93 ;
int V_94 ;
V_94 = F_40 ( L_29 , L_20 , L_30 ) ;
V_81 = F_41 ( V_94 ) ;
F_42 ( V_94 , V_87 , F_43 ( V_87 ) ) ;
F_44 ( V_88 , F_43 ( V_88 ) ) ;
V_93 = F_45 ( V_94 ) ;
F_46 ( V_93 , V_89 , F_43 ( V_89 ) ) ;
V_95 = F_47 ( F_30 , V_94 ) ;
V_96 = F_47 ( F_35 , V_94 ) ;
}
void
F_48 ( void )
{
F_49 ( L_31 , V_97 , V_95 ) ;
F_50 ( L_32 , V_96 ) ;
}
