static int F_1 ( T_1 * V_1 , const char * V_2 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
const char * V_6 ;
V_6 = V_2 ;
while ( * V_6 )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 )
{
* V_3 = F_3 ( V_1 -> V_7 , V_4 ) ;
if ( * V_3 != 0 && * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( V_5 == * V_6 )
V_6 ++ ;
else
{
if ( V_5 == V_2 [ 0 ] )
V_6 = & V_2 [ 1 ] ;
else
V_6 = V_2 ;
}
}
return ( * V_6 == '\0' ? 1 : 0 ) ;
}
static int F_4 ( T_1 * V_1 , char * V_10 , int V_11 ,
const char * V_12 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
char * V_6 ;
int V_13 ;
for ( V_6 = V_10 , V_13 = 0 ; V_13 < V_11 ; V_13 ++ , V_6 ++ )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 )
{
* V_3 = F_3 ( V_1 -> V_7 , V_4 ) ;
if ( * V_3 != 0 && * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( strchr ( V_12 , V_5 ) != NULL )
{
* V_6 = '\0' ;
break;
}
else
* V_6 = V_5 ;
}
return V_13 ;
}
static int F_5 ( T_1 * V_1 , T_3 * V_14 , int * V_3 ,
T_2 * * V_4 )
{
int V_15 ;
char V_16 [ 12 ] ;
unsigned long V_17 ;
char * V_18 ;
V_15 = F_4 ( V_1 , V_16 , sizeof ( V_16 ) - 1 , L_1 ,
V_3 , V_4 ) ;
if ( V_15 != 1 ) {
return V_15 ;
}
V_17 = strtoul ( V_16 , & V_18 , 10 ) ;
if ( V_18 == V_16 || V_17 > V_19 )
return 0 ;
* V_14 = ( T_3 ) V_17 ;
return 1 ;
}
int F_6 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 )
{
T_4 V_20 ;
int V_21 ;
int V_15 ;
T_3 V_22 ;
T_3 V_23 ;
T_3 V_24 = 0 ;
int V_25 ;
static const int V_26 [] = {
V_27 ,
V_28 ,
V_28 ,
V_28
} ;
#define F_7 (sizeof peektagged_encap / sizeof peektagged_encap[0])
T_5 * V_29 ;
V_21 = F_8 ( & V_20 , ( int ) sizeof( V_20 ) , V_1 -> V_7 ) ;
if ( V_21 != ( int ) sizeof( V_20 ) ) {
* V_3 = F_3 ( V_1 -> V_7 , V_4 ) ;
if ( * V_3 != 0 && * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_20 . V_30 , L_2 , sizeof( V_20 . V_30 ) ) != 0 )
return 0 ;
V_15 = F_1 ( V_1 , L_3 , V_3 , V_4 ) ;
if ( V_15 != 1 ) {
return V_15 ;
}
V_15 = F_5 ( V_1 , & V_22 , V_3 , V_4 ) ;
if ( V_15 != 1 ) {
return V_15 ;
}
if ( V_22 != 9 ) {
* V_3 = V_31 ;
* V_4 = F_9 ( L_4 ,
V_22 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_5 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_6 ) ;
return - 1 ;
}
V_15 = F_5 ( V_1 , & V_23 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_7 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_8 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_9 ) ;
return - 1 ;
}
V_15 = F_5 ( V_1 , & V_24 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_10 ) ;
return - 1 ;
}
if ( V_24 >= F_7
|| V_26 [ V_24 ] == V_33 ) {
* V_3 = V_34 ;
* V_4 = F_9 ( L_11 ,
V_24 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_12 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_9 ;
return - 1 ;
}
if ( F_11 ( V_1 -> V_7 , 8L , V_35 , V_3 ) == - 1 )
return 0 ;
V_25 = V_26 [ V_24 ] ;
V_1 -> V_36 = V_37 ;
V_1 -> V_25 = V_25 ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_43 ;
V_29 = ( T_5 * ) F_12 ( sizeof( T_5 ) ) ;
V_1 -> V_44 = ( void * ) V_29 ;
switch ( V_24 ) {
case V_45 :
case V_46 :
case V_47 :
V_29 -> V_48 = FALSE ;
break;
case V_49 :
V_29 -> V_48 = TRUE ;
break;
}
V_1 -> V_50 = 0 ;
return 1 ;
}
static int
F_13 ( T_1 * V_1 , T_6 V_7 , struct V_51 * V_52 ,
T_7 * V_53 , int * V_3 , T_2 * * V_4 )
{
T_5 * V_29 = ( T_5 * ) V_1 -> V_44 ;
T_8 V_54 ;
int V_55 = 0 ;
int V_21 ;
T_9 V_56 [ 6 ] ;
T_10 V_57 ;
T_11 V_58 = FALSE ;
T_11 V_59 = FALSE ;
T_11 V_60 = FALSE ;
int V_61 = 0 ;
double V_62 ;
memset ( & V_54 , 0 , sizeof( T_8 ) ) ;
do {
V_21 = F_8 ( V_56 , sizeof V_56 , V_7 ) ;
if ( V_21 != ( int ) sizeof V_56 ) {
* V_3 = F_3 ( V_7 , V_4 ) ;
if ( * V_3 == 0 ) {
if ( V_21 > 0 )
* V_3 = V_9 ;
else if ( V_21 == 0 ) {
if ( V_55 != 0 )
* V_3 = V_9 ;
}
}
return - 1 ;
}
V_55 += ( int ) sizeof( V_56 ) ;
V_57 = F_14 ( & V_56 [ 0 ] ) ;
switch ( V_57 ) {
case V_63 :
if ( V_58 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_13 ) ;
return - 1 ;
}
V_54 . V_64 = F_15 ( & V_56 [ 2 ] ) ;
V_58 = TRUE ;
break;
case V_65 :
if ( V_59 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_14 ) ;
return - 1 ;
}
V_54 . V_66 . V_67 = F_15 ( & V_56 [ 2 ] ) ;
V_59 = TRUE ;
break;
case V_68 :
if ( V_60 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_15 ) ;
return - 1 ;
}
V_54 . V_66 . V_69 = F_15 ( & V_56 [ 2 ] ) ;
V_60 = TRUE ;
break;
case V_70 :
break;
case V_71 :
V_54 . V_72 . V_73 = F_15 ( & V_56 [ 2 ] ) ;
break;
case V_74 :
V_54 . V_72 . V_75 = F_15 ( & V_56 [ 2 ] ) ;
break;
case V_76 :
V_54 . V_72 . V_77 = F_15 ( & V_56 [ 2 ] ) ;
break;
case V_78 :
break;
case V_79 :
break;
case V_80 :
break;
case V_81 :
break;
case V_82 :
V_54 . V_83 = F_15 ( & V_56 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_57 != V_82 );
if ( ! V_58 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_16 ) ;
return - 1 ;
}
if ( ! V_59 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_17 ) ;
return - 1 ;
}
if ( ! V_60 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_18 ) ;
return - 1 ;
}
if ( V_54 . V_83 == 0 )
V_54 . V_83 = V_54 . V_64 ;
if ( V_54 . V_83 > V_84 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_19 ,
V_54 . V_83 , V_84 ) ;
return - 1 ;
}
V_52 -> V_85 = V_86 | V_87 ;
V_52 -> V_88 = V_54 . V_64 ;
V_52 -> V_89 = V_54 . V_83 ;
V_62 = ( double ) V_54 . V_66 . V_67 +
( double ) V_54 . V_66 . V_69 * 4294967296.0 ;
V_62 *= 1.0e-9 ;
V_62 -= V_90 ;
V_52 -> V_91 . V_92 = ( V_93 ) V_62 ;
V_52 -> V_91 . V_94 = ( T_3 ) ( ( V_62 - V_52 -> V_91 . V_92 ) * 1000000000 ) ;
switch ( V_1 -> V_25 ) {
case V_28 :
V_52 -> V_95 . V_72 = V_54 . V_72 ;
if ( V_29 -> V_48 )
V_52 -> V_95 . V_72 . V_96 = 4 ;
else {
if ( V_52 -> V_88 < 4 || V_52 -> V_89 < 4 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_20 ) ;
return FALSE ;
}
V_52 -> V_95 . V_72 . V_96 = 0 ;
V_52 -> V_88 -= 4 ;
V_52 -> V_89 -= 4 ;
V_61 = 4 ;
}
V_52 -> V_95 . V_72 . V_97 = FALSE ;
break;
case V_27 :
if ( V_52 -> V_88 < 4 || V_52 -> V_89 < 4 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_21 ) ;
return FALSE ;
}
V_52 -> V_95 . V_98 . V_96 = 0 ;
V_52 -> V_88 -= 4 ;
V_52 -> V_89 -= 4 ;
V_61 = 4 ;
break;
}
if ( ! F_16 ( V_7 , V_53 , V_52 -> V_89 , V_3 , V_4 ) )
return - 1 ;
return V_61 ;
}
static T_11 V_39 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_12 * V_99 )
{
int V_61 ;
* V_99 = F_17 ( V_1 -> V_7 ) ;
V_61 = F_13 ( V_1 , V_1 -> V_7 , & V_1 -> V_52 ,
V_1 -> V_100 , V_3 , V_4 ) ;
if ( V_61 == - 1 )
return FALSE ;
if ( V_61 != 0 ) {
if ( ! F_18 ( V_1 -> V_7 , V_61 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_11
V_41 ( T_1 * V_1 , T_12 V_101 ,
struct V_51 * V_52 , T_7 * V_53 , int V_64 V_102 ,
int * V_3 , T_2 * * V_4 )
{
if ( F_11 ( V_1 -> V_103 , V_101 , V_104 , V_3 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 , V_1 -> V_103 , V_52 , V_53 , V_3 , V_4 ) == - 1 ) {
if ( * V_3 == 0 )
* V_3 = V_9 ;
return FALSE ;
}
return TRUE ;
}
