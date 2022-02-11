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
V_10 = F_11 ( F_12 () , V_3 , V_6 , V_23 ) ;
V_6 += ( V_23 + 1 + 3 ) & ~ 3 ;
if ( T_2 == 's' ) {
V_9 = F_13 ( V_5 , V_24 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_12 , V_10 ) ;
if ( ! F_14 ( V_10 , - 1 , NULL ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_25 ) ;
return - 1 ;
}
} else {
V_9 = F_13 ( V_5 , V_24 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_13 , V_10 ) ;
if ( ! F_1 ( V_10 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_26 ) ;
return - 1 ;
}
}
V_7 -> V_27 = V_10 ;
return V_6 ;
}
case 'g' :
{
T_8 V_23 ;
char * V_10 ;
V_23 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_10 = F_11 ( F_12 () , V_3 , V_6 , V_23 ) ;
V_6 += ( V_23 + 1 ) ;
V_9 = F_13 ( V_5 , V_24 . V_12 , V_3 , V_8 , V_6 - V_8 , V_10 , L_14 , V_10 ) ;
if ( ! F_2 ( V_10 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_28 ) ;
return - 1 ;
}
V_7 -> V_27 = V_10 ;
return V_6 ;
}
}
return - 1 ;
}
static int
F_16 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 , int V_29 )
{
const int V_8 = V_6 ;
T_7 * V_9 ;
T_14 V_30 ;
char * T_2 ;
V_30 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
T_2 = F_11 ( F_12 () , V_3 , V_6 , V_30 ) ;
V_6 += ( V_30 + 1 ) ;
V_9 = F_17 ( V_5 , & V_31 , V_3 , V_8 , V_6 - V_8 , T_2 ) ;
if ( ! F_2 ( T_2 ) ) {
F_15 ( V_4 -> V_16 , V_9 , & V_28 ) ;
return - 1 ;
}
switch ( V_29 ) {
case V_32 :
if ( ! strcmp ( T_2 , L_15 ) ) {
T_6 V_33 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'u' , & V_33 ) ;
if ( V_6 != - 1 )
{ }
return V_6 ;
}
break;
case V_34 :
case V_35 :
if ( ! strcmp ( T_2 , L_16 ) ) {
T_6 V_36 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 's' , & V_36 ) ;
if ( V_6 != - 1 )
F_18 ( ( V_29 == V_34 ) ? & V_4 -> V_16 -> V_37 : & V_4 -> V_16 -> V_38 ,
V_39 , ( int ) strlen ( V_36 . V_27 ) + 1 , V_36 . V_27 ) ;
return V_6 ;
}
break;
case V_40 :
if ( ! strcmp ( T_2 , L_11 ) ) {
T_6 V_41 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'g' , & V_41 ) ;
if ( V_6 != - 1 )
V_4 -> V_42 = V_41 . V_27 ;
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
F_19 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
int V_43 ;
V_43 = V_6 + V_4 -> V_44 ;
while ( V_6 < V_43 ) {
T_5 * V_45 ;
T_7 * V_9 ;
T_8 V_29 ;
V_9 = F_20 ( V_5 , & V_46 , V_3 , V_6 , 0 , V_47 ) ;
V_45 = F_21 ( V_9 , V_48 ) ;
V_29 = F_4 ( V_3 , V_6 ) ;
F_20 ( V_45 , & V_49 , V_3 , V_6 , 1 , V_4 -> V_50 ) ;
F_22 ( V_9 , L_17 , F_23 ( V_29 , V_51 , L_18 ) ) ;
V_6 += 1 ;
V_6 = F_16 ( V_3 , V_4 , V_45 , V_6 , V_29 ) ;
if ( V_6 == - 1 )
break;
V_6 = ( V_6 + 7 ) & ~ 7 ;
F_24 ( V_9 , V_3 , V_6 ) ;
}
if ( V_6 >= V_43 ) {
}
return V_43 ;
}
static int
F_25 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_52 ;
T_7 * V_9 ;
T_8 type ;
V_9 = F_20 ( V_5 , & V_53 , V_3 , V_6 , 0 , V_47 ) ;
V_52 = F_21 ( V_9 , V_54 ) ;
F_20 ( V_52 , & V_55 , V_3 , V_6 , 1 , V_56 | V_47 ) ;
V_6 += 1 ;
type = F_4 ( V_3 , V_6 ) ;
F_26 ( V_4 -> V_16 -> V_57 , V_58 , F_27 ( type , V_59 , L_19 ) ) ;
F_20 ( V_52 , & V_60 , V_3 , V_6 , 1 , V_4 -> V_50 ) ;
V_6 += 1 ;
F_20 ( V_52 , & V_61 , V_3 , V_6 , 1 , V_4 -> V_50 ) ;
V_6 += 1 ;
F_20 ( V_52 , & V_62 , V_3 , V_6 , 1 , V_4 -> V_50 ) ;
V_6 += 1 ;
V_4 -> V_63 = V_4 -> V_14 ( V_3 , V_6 ) ;
F_20 ( V_52 , & V_64 , V_3 , V_6 , 4 , V_4 -> V_50 ) ;
V_6 += 4 ;
F_20 ( V_52 , & V_65 , V_3 , V_6 , 4 , V_4 -> V_50 ) ;
V_6 += 4 ;
V_4 -> V_44 = V_4 -> V_14 ( V_3 , V_6 ) ;
F_20 ( V_52 , & V_66 , V_3 , V_6 , 4 , V_4 -> V_50 ) ;
V_6 += 4 ;
return V_6 ;
}
static int
F_28 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_67 ;
T_7 * V_9 ;
if ( V_4 -> V_63 && V_4 -> V_42 [ 0 ] ) {
const char * T_2 = V_4 -> V_42 ;
V_9 = F_20 ( V_5 , & V_68 , V_3 , V_6 , 0 , V_47 ) ;
V_67 = F_21 ( V_9 , V_69 ) ;
while ( * T_2 ) {
T_6 V_10 ;
V_6 = F_3 ( V_3 , V_4 , V_67 , V_6 , * T_2 , & V_10 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
F_24 ( V_9 , V_3 , V_6 ) ;
} else if ( V_4 -> V_63 || V_4 -> V_42 [ 0 ] ) {
}
return V_6 ;
}
static int
F_29 ( T_3 * V_3 , T_15 * V_16 , T_5 * V_5 , void * T_16 V_2 )
{
T_5 * V_70 = NULL ;
T_4 V_4 ;
int V_6 ;
F_30 ( V_16 -> V_57 , V_71 , L_20 ) ;
F_31 ( V_16 -> V_57 , V_58 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_16 ;
switch ( F_4 ( V_3 , 0 ) ) {
case 'l' :
V_4 . V_50 = V_72 ;
V_4 . V_18 = V_73 ;
V_4 . V_14 = V_74 ;
V_4 . V_20 = V_75 ;
break;
case 'B' :
V_4 . V_50 = V_76 ;
V_4 . V_18 = V_77 ;
V_4 . V_14 = V_78 ;
V_4 . V_20 = V_79 ;
break;
default:
V_4 . V_50 = V_47 ;
V_4 . V_18 = V_77 ;
V_4 . V_14 = V_78 ;
V_4 . V_20 = V_79 ;
}
if ( V_5 ) {
T_7 * V_9 = F_20 ( V_5 , V_80 , V_3 , 0 , - 1 , V_47 ) ;
V_70 = F_21 ( V_9 , V_81 ) ;
}
V_6 = 0 ;
V_6 = F_25 ( V_3 , & V_4 , V_70 , V_6 ) ;
V_6 = F_19 ( V_3 , & V_4 , V_70 , V_6 ) ;
V_6 = ( V_6 + 7 ) & ~ 7 ;
if ( ! V_4 . V_42 )
V_4 . V_42 = L_19 ;
V_6 = F_28 ( V_3 , & V_4 , V_70 , V_6 ) ;
return V_6 ;
}
static T_14
F_32 ( T_15 * V_16 V_2 , T_3 * V_3 , int V_6 )
{
T_9 (* F_33)( T_3 * , const T_17 );
T_9 V_82 , V_83 ;
switch ( F_4 ( V_3 , V_6 ) ) {
case 'l' :
F_33 = V_74 ;
break;
case 'B' :
default:
F_33 = V_78 ;
break;
}
V_83 = V_84 + F_33 ( V_3 , V_6 + 12 ) ;
V_83 = ( V_83 + 7 ) & ~ 7 ;
V_82 = F_33 ( V_3 , V_6 + 4 ) ;
return V_83 + V_82 ;
}
static void
F_34 ( T_3 * V_3 , T_15 * V_16 , T_5 * V_5 )
{
F_29 ( V_3 , V_16 , V_5 , NULL ) ;
}
static int
F_35 ( T_3 * V_3 , T_15 * V_16 , T_5 * V_5 , void * T_16 V_2 )
{
F_36 ( V_3 , V_16 , V_5 , V_85 , V_84 , F_32 , F_34 ) ;
return F_37 ( V_3 ) ;
}
void
F_38 ( void )
{
static T_18 * V_86 [] = {
& V_53 ,
& V_55 ,
& V_60 ,
& V_61 ,
& V_62 ,
& V_64 ,
& V_65 ,
& V_66 ,
& V_46 ,
& V_49 ,
& V_31 ,
& V_68 ,
& V_15 ,
& V_19 ,
& V_11 ,
& V_24 ,
& V_21 ,
} ;
static T_17 * V_87 [] = {
& V_81 ,
& V_54 ,
& V_69 ,
& V_48
} ;
static T_19 V_88 [] = {
{ & V_17 , { L_21 , V_89 , V_90 , L_22 , V_91 } } ,
{ & V_25 , { L_23 , V_89 , V_90 , L_24 , V_91 } } ,
{ & V_26 , { L_25 , V_89 , V_90 , L_26 , V_91 } } ,
{ & V_28 , { L_27 , V_89 , V_90 , L_28 , V_91 } } ,
} ;
T_20 * V_92 ;
int V_93 ;
V_93 = F_39 ( L_29 , L_20 , L_30 ) ;
V_80 = F_40 ( V_93 ) ;
F_41 ( V_93 , V_86 , F_42 ( V_86 ) ) ;
F_43 ( V_87 , F_42 ( V_87 ) ) ;
V_92 = F_44 ( V_93 ) ;
F_45 ( V_92 , V_88 , F_42 ( V_88 ) ) ;
V_94 = F_46 ( F_29 , V_93 ) ;
V_95 = F_46 ( F_35 , V_93 ) ;
}
void
F_47 ( void )
{
F_48 ( L_31 , V_96 , V_94 ) ;
F_49 ( L_32 , V_95 ) ;
}
