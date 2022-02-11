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
int V_15 ;
T_3 V_21 ;
T_3 V_22 ;
T_3 V_23 = 0 ;
int V_24 ;
static const int V_25 [] = {
V_26 ,
V_27 ,
V_27 ,
V_27
} ;
#define F_7 (sizeof peektagged_encap / sizeof peektagged_encap[0])
T_5 * V_28 ;
if ( ! F_8 ( V_1 -> V_7 , & V_20 , ( int ) sizeof( V_20 ) , V_3 , V_4 ) ) {
if ( * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_20 . V_29 , L_2 , sizeof( V_20 . V_29 ) ) != 0 )
return 0 ;
V_15 = F_1 ( V_1 , L_3 , V_3 , V_4 ) ;
if ( V_15 != 1 ) {
return V_15 ;
}
V_15 = F_5 ( V_1 , & V_21 , V_3 , V_4 ) ;
if ( V_15 != 1 ) {
return V_15 ;
}
if ( V_21 != 9 ) {
* V_3 = V_30 ;
* V_4 = F_9 ( L_4 ,
V_21 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_5 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_6 ) ;
return - 1 ;
}
V_15 = F_5 ( V_1 , & V_22 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_7 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_8 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_9 ) ;
return - 1 ;
}
V_15 = F_5 ( V_1 , & V_23 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_10 ) ;
return - 1 ;
}
if ( V_23 >= F_7
|| V_25 [ V_23 ] == V_32 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_11 ,
V_23 ) ;
return - 1 ;
}
V_15 = F_1 ( V_1 , L_12 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return - 1 ;
if ( V_15 == 0 ) {
* V_3 = V_9 ;
return - 1 ;
}
if ( F_11 ( V_1 -> V_7 , 8L , V_34 , V_3 ) == - 1 )
return 0 ;
V_24 = V_25 [ V_23 ] ;
V_1 -> V_35 = V_36 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 = V_42 ;
V_28 = ( T_5 * ) F_12 ( sizeof( T_5 ) ) ;
V_1 -> V_43 = ( void * ) V_28 ;
switch ( V_23 ) {
case V_44 :
case V_45 :
case V_46 :
V_28 -> V_47 = FALSE ;
break;
case V_48 :
V_28 -> V_47 = TRUE ;
break;
}
V_1 -> V_49 = 0 ;
return 1 ;
}
static int
F_13 ( T_1 * V_1 , T_6 V_7 , struct V_50 * V_51 ,
T_7 * V_52 , int * V_3 , T_2 * * V_4 )
{
T_5 * V_28 = ( T_5 * ) V_1 -> V_43 ;
T_8 V_53 ;
int V_54 = 0 ;
T_9 V_55 [ 6 ] ;
T_10 V_56 ;
T_11 V_57 = FALSE ;
T_11 V_58 = FALSE ;
T_11 V_59 = FALSE ;
int V_60 = 0 ;
double V_61 ;
memset ( & V_53 , 0 , sizeof( T_8 ) ) ;
do {
if ( ! F_14 ( V_7 , V_55 , sizeof V_55 , V_3 , V_4 ) ) {
if ( * V_3 == 0 ) {
if ( V_54 != 0 )
* V_3 = V_9 ;
}
return - 1 ;
}
V_54 += ( int ) sizeof( V_55 ) ;
V_56 = F_15 ( & V_55 [ 0 ] ) ;
switch ( V_56 ) {
case V_62 :
if ( V_57 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_13 ) ;
return - 1 ;
}
V_53 . V_63 = F_16 ( & V_55 [ 2 ] ) ;
V_57 = TRUE ;
break;
case V_64 :
if ( V_58 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_14 ) ;
return - 1 ;
}
V_53 . V_65 . V_66 = F_16 ( & V_55 [ 2 ] ) ;
V_58 = TRUE ;
break;
case V_67 :
if ( V_59 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_15 ) ;
return - 1 ;
}
V_53 . V_65 . V_68 = F_16 ( & V_55 [ 2 ] ) ;
V_59 = TRUE ;
break;
case V_69 :
break;
case V_70 :
V_53 . V_71 . V_72 = F_16 ( & V_55 [ 2 ] ) ;
break;
case V_73 :
V_53 . V_71 . V_74 = F_16 ( & V_55 [ 2 ] ) ;
break;
case V_75 :
V_53 . V_71 . V_76 = F_16 ( & V_55 [ 2 ] ) ;
break;
case V_77 :
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
break;
case V_83 :
break;
case V_84 :
break;
case V_85 :
break;
case V_86 :
break;
case V_87 :
break;
case V_88 :
break;
case V_89 :
break;
case V_90 :
V_53 . V_91 = F_16 ( & V_55 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_56 != V_90 );
if ( ! V_57 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_16 ) ;
return - 1 ;
}
if ( ! V_58 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_17 ) ;
return - 1 ;
}
if ( ! V_59 ) {
* V_3 = V_31 ;
* V_4 = F_10 ( L_18 ) ;
return - 1 ;
}
if ( V_53 . V_91 == 0 )
V_53 . V_91 = V_53 . V_63 ;
if ( V_53 . V_91 > V_92 ) {
* V_3 = V_31 ;
* V_4 = F_9 ( L_19 ,
V_53 . V_91 , V_92 ) ;
return - 1 ;
}
V_51 -> V_93 = V_94 ;
V_51 -> V_95 = V_96 | V_97 ;
V_51 -> V_98 = V_53 . V_63 ;
V_51 -> V_99 = V_53 . V_91 ;
V_61 = ( double ) V_53 . V_65 . V_66 +
( double ) V_53 . V_65 . V_68 * 4294967296.0 ;
V_61 *= 1.0e-9 ;
V_61 -= V_100 ;
V_51 -> V_101 . V_102 = ( V_103 ) V_61 ;
V_51 -> V_101 . V_104 = ( T_3 ) ( ( V_61 - V_51 -> V_101 . V_102 ) * 1000000000 ) ;
switch ( V_1 -> V_24 ) {
case V_27 :
V_51 -> V_105 . V_71 = V_53 . V_71 ;
if ( V_28 -> V_47 )
V_51 -> V_105 . V_71 . V_106 = 4 ;
else {
if ( V_51 -> V_98 < 4 || V_51 -> V_99 < 4 ) {
* V_3 = V_31 ;
* V_4 = F_9 ( L_20 ) ;
return FALSE ;
}
V_51 -> V_105 . V_71 . V_106 = 0 ;
V_51 -> V_98 -= 4 ;
V_51 -> V_99 -= 4 ;
V_60 = 4 ;
}
V_51 -> V_105 . V_71 . V_107 = FALSE ;
break;
case V_26 :
if ( V_51 -> V_98 < 4 || V_51 -> V_99 < 4 ) {
* V_3 = V_31 ;
* V_4 = F_9 ( L_21 ) ;
return FALSE ;
}
V_51 -> V_105 . V_108 . V_106 = 0 ;
V_51 -> V_98 -= 4 ;
V_51 -> V_99 -= 4 ;
V_60 = 4 ;
break;
}
if ( ! F_17 ( V_7 , V_52 , V_51 -> V_99 , V_3 , V_4 ) )
return - 1 ;
return V_60 ;
}
static T_11 V_38 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_12 * V_109 )
{
int V_60 ;
* V_109 = F_18 ( V_1 -> V_7 ) ;
V_60 = F_13 ( V_1 , V_1 -> V_7 , & V_1 -> V_51 ,
V_1 -> V_110 , V_3 , V_4 ) ;
if ( V_60 == - 1 )
return FALSE ;
if ( V_60 != 0 ) {
if ( ! F_19 ( V_1 -> V_7 , V_60 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_11
V_40 ( T_1 * V_1 , T_12 V_111 ,
struct V_50 * V_51 , T_7 * V_52 , int * V_3 , T_2 * * V_4 )
{
if ( F_11 ( V_1 -> V_112 , V_111 , V_113 , V_3 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 , V_1 -> V_112 , V_51 , V_52 , V_3 , V_4 ) == - 1 ) {
if ( * V_3 == 0 )
* V_3 = V_9 ;
return FALSE ;
}
return TRUE ;
}
