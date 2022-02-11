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
F_13 ( T_6 V_7 , T_7 * V_51 , int * V_3 ,
T_2 * * V_4 )
{
int V_52 = 0 ;
int V_21 ;
T_8 V_53 [ 6 ] ;
T_9 V_54 ;
T_10 V_55 = FALSE ;
T_10 V_56 = FALSE ;
T_10 V_57 = FALSE ;
do {
V_21 = F_8 ( V_53 , sizeof V_53 , V_7 ) ;
if ( V_21 != ( int ) sizeof V_53 ) {
* V_3 = F_3 ( V_7 , V_4 ) ;
if ( * V_3 == 0 ) {
if ( V_21 > 0 )
* V_3 = V_9 ;
else if ( V_21 == 0 ) {
if ( V_52 != 0 )
* V_3 = V_9 ;
}
}
return 0 ;
}
V_52 += ( int ) sizeof( V_53 ) ;
V_54 = F_14 ( & V_53 [ 0 ] ) ;
switch ( V_54 ) {
case V_58 :
if ( V_55 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_13 ) ;
return 0 ;
}
V_51 -> V_59 = F_15 ( & V_53 [ 2 ] ) ;
V_55 = TRUE ;
break;
case V_60 :
if ( V_56 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_14 ) ;
return 0 ;
}
V_51 -> V_61 . V_62 = F_15 ( & V_53 [ 2 ] ) ;
V_56 = TRUE ;
break;
case V_63 :
if ( V_57 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_15 ) ;
return 0 ;
}
V_51 -> V_61 . V_64 = F_15 ( & V_53 [ 2 ] ) ;
V_57 = TRUE ;
break;
case V_65 :
break;
case V_66 :
V_51 -> V_67 . V_68 = F_15 ( & V_53 [ 2 ] ) ;
break;
case V_69 :
V_51 -> V_67 . V_70 = F_15 ( & V_53 [ 2 ] ) ;
break;
case V_71 :
V_51 -> V_67 . V_72 = F_15 ( & V_53 [ 2 ] ) ;
break;
case V_73 :
break;
case V_74 :
break;
case V_75 :
break;
case V_76 :
break;
case V_77 :
V_51 -> V_78 = F_15 ( & V_53 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_54 != V_77 );
if ( ! V_55 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_16 ) ;
return 0 ;
}
if ( ! V_56 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_17 ) ;
return 0 ;
}
if ( ! V_57 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_18 ) ;
return 0 ;
}
return V_52 ;
}
static T_10 V_39 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_11 * V_79 )
{
T_5 * V_29 = ( T_5 * ) V_1 -> V_44 ;
T_7 V_51 ;
int V_80 ;
double V_81 ;
* V_79 = F_16 ( V_1 -> V_7 ) ;
V_80 = F_13 ( V_1 -> V_7 , & V_51 , V_3 , V_4 ) ;
if ( V_80 == 0 )
return FALSE ;
if ( V_51 . V_78 == 0 )
V_51 . V_78 = V_51 . V_59 ;
if ( V_51 . V_78 > V_82 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_19 ,
V_51 . V_78 , V_82 ) ;
return FALSE ;
}
V_1 -> V_83 . V_84 = V_85 | V_86 ;
V_1 -> V_83 . V_87 = V_51 . V_59 ;
V_1 -> V_83 . V_88 = V_51 . V_78 ;
F_17 ( V_1 -> V_89 , V_51 . V_78 ) ;
F_18 ( F_19 ( V_1 -> V_89 ) ,
V_51 . V_78 , V_1 -> V_7 , V_3 ,
V_4 ) ;
V_81 = ( double ) V_51 . V_61 . V_62 +
( double ) V_51 . V_61 . V_64 * 4294967296.0 ;
V_81 *= 1.0e-9 ;
V_81 -= V_90 ;
V_1 -> V_83 . V_91 . V_92 = ( V_93 ) V_81 ;
V_1 -> V_83 . V_91 . V_94 = ( T_3 ) ( ( V_81 - V_1 -> V_83 . V_91 . V_92 ) * 1000000000 ) ;
switch ( V_1 -> V_25 ) {
case V_28 :
V_1 -> V_83 . V_95 . V_67 = V_51 . V_67 ;
if ( V_29 -> V_48 )
V_1 -> V_83 . V_95 . V_67 . V_96 = 4 ;
else {
V_1 -> V_83 . V_95 . V_67 . V_96 = 0 ;
V_1 -> V_83 . V_87 -= 4 ;
V_1 -> V_83 . V_88 -= 4 ;
}
V_1 -> V_83 . V_95 . V_67 . V_97 = FALSE ;
break;
case V_27 :
V_1 -> V_83 . V_95 . V_98 . V_96 = 0 ;
V_1 -> V_83 . V_87 -= 4 ;
V_1 -> V_83 . V_88 -= 4 ;
break;
}
return TRUE ;
}
static T_10
V_41 ( T_1 * V_1 , T_11 V_99 ,
struct V_100 * V_83 , T_8 * V_101 , int V_59 ,
int * V_3 , T_2 * * V_4 )
{
union V_102 * V_95 = & V_83 -> V_95 ;
T_5 * V_29 = ( T_5 * ) V_1 -> V_44 ;
T_7 V_51 ;
if ( F_11 ( V_1 -> V_103 , V_99 , V_104 , V_3 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 -> V_103 , & V_51 , V_3 , V_4 ) == - 1 )
return FALSE ;
switch ( V_1 -> V_25 ) {
case V_28 :
V_95 -> V_67 = V_51 . V_67 ;
if ( V_29 -> V_48 )
V_95 -> V_67 . V_96 = 4 ;
else
V_95 -> V_67 . V_96 = 0 ;
V_95 -> V_67 . V_97 = FALSE ;
break;
case V_27 :
V_95 -> V_98 . V_96 = 0 ;
break;
}
V_105 = V_106 ;
F_18 ( V_101 , V_59 , V_1 -> V_103 , V_3 , V_4 ) ;
return TRUE ;
}
