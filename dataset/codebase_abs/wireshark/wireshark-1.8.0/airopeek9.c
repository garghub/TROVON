static int F_1 ( T_1 * V_1 , const char * V_2 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
const char * V_6 ;
V_6 = V_2 ;
while ( * V_6 )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 ) {
if ( F_3 ( V_1 -> V_7 ) )
return 0 ;
else {
* V_3 = F_4 ( V_1 -> V_7 , V_4 ) ;
return - 1 ;
}
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
static int F_5 ( T_1 * V_1 , char * V_9 , int V_10 ,
const char * V_11 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
char * V_6 ;
int V_12 ;
for ( V_6 = V_9 , V_12 = 0 ; V_12 < V_10 ; V_12 ++ , V_6 ++ )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 ) {
if ( F_3 ( V_1 -> V_7 ) )
return 0 ;
else {
* V_3 = F_4 ( V_1 -> V_7 , V_4 ) ;
return - 1 ;
}
}
if ( strchr ( V_11 , V_5 ) != NULL )
{
* V_6 = '\0' ;
break;
}
else
* V_6 = V_5 ;
}
return V_12 ;
}
static int F_6 ( T_1 * V_1 , T_3 * V_13 , int * V_3 ,
T_2 * * V_4 )
{
int V_14 ;
char V_15 [ 12 ] ;
unsigned long V_16 ;
char * V_17 ;
V_14 = F_5 ( V_1 , V_15 , sizeof ( V_15 ) - 1 , L_1 ,
V_3 , V_4 ) ;
if ( V_14 != 1 ) {
return V_14 ;
}
V_16 = strtoul ( V_15 , & V_17 , 10 ) ;
if ( V_17 == V_15 || V_16 > V_18 )
return 0 ;
* V_13 = ( T_3 ) V_16 ;
return 1 ;
}
int F_7 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 )
{
T_4 V_19 ;
int V_14 ;
T_3 V_20 ;
T_3 V_21 ;
T_3 V_22 = 0 ;
int V_23 ;
static const int V_24 [] = {
V_25 ,
V_26 ,
V_26 ,
V_26
} ;
#define F_8 (sizeof airopeek9_encap / sizeof airopeek9_encap[0])
T_5 * V_27 ;
F_9 ( & V_19 , sizeof( V_19 ) , V_1 -> V_7 , V_3 ,
V_4 ) ;
if ( memcmp ( V_19 . V_28 , L_2 , sizeof( V_19 . V_28 ) ) != 0 )
return 0 ;
V_14 = F_1 ( V_1 , L_3 , V_3 , V_4 ) ;
if ( V_14 != 1 ) {
return V_14 ;
}
V_14 = F_6 ( V_1 , & V_20 , V_3 , V_4 ) ;
if ( V_14 != 1 ) {
return V_14 ;
}
if ( V_20 != 9 ) {
* V_3 = V_29 ;
* V_4 = F_10 ( L_4 ,
V_20 ) ;
return - 1 ;
}
V_14 = F_1 ( V_1 , L_5 , V_3 , V_4 ) ;
if ( V_14 == - 1 )
return - 1 ;
if ( V_14 == 0 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_6 ) ;
return - 1 ;
}
V_14 = F_6 ( V_1 , & V_21 , V_3 , V_4 ) ;
if ( V_14 == - 1 )
return - 1 ;
if ( V_14 == 0 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_7 ) ;
return - 1 ;
}
V_14 = F_1 ( V_1 , L_8 , V_3 , V_4 ) ;
if ( V_14 == - 1 )
return - 1 ;
if ( V_14 == 0 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_9 ) ;
return - 1 ;
}
V_14 = F_6 ( V_1 , & V_22 , V_3 , V_4 ) ;
if ( V_14 == - 1 )
return - 1 ;
if ( V_14 == 0 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_10 ) ;
return - 1 ;
}
if ( V_22 >= F_8
|| V_24 [ V_22 ] == V_31 ) {
* V_3 = V_32 ;
* V_4 = F_10 ( L_11 ,
V_22 ) ;
return - 1 ;
}
V_14 = F_1 ( V_1 , L_12 , V_3 , V_4 ) ;
if ( V_14 == - 1 )
return - 1 ;
if ( V_14 == 0 ) {
* V_3 = V_33 ;
return - 1 ;
}
if ( F_12 ( V_1 -> V_7 , 8L , V_34 , V_3 ) == - 1 )
return 0 ;
V_23 = V_24 [ V_22 ] ;
V_1 -> V_35 = V_36 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 = V_42 ;
V_27 = ( T_5 * ) F_13 ( sizeof( T_5 ) ) ;
V_1 -> V_43 = ( void * ) V_27 ;
switch ( V_22 ) {
case V_44 :
case V_45 :
case V_46 :
V_27 -> V_47 = FALSE ;
break;
case V_48 :
V_27 -> V_47 = TRUE ;
break;
}
V_1 -> V_49 = 0 ;
return 1 ;
}
static int
F_14 ( T_6 V_7 , T_7 * V_50 , int * V_3 ,
T_2 * * V_4 )
{
int V_51 = 0 ;
int V_52 ;
T_8 V_53 [ 6 ] ;
T_9 V_54 ;
T_10 V_55 = FALSE ;
T_10 V_56 = FALSE ;
T_10 V_57 = FALSE ;
do {
V_52 = F_15 ( V_53 , sizeof V_53 , V_7 ) ;
if ( V_52 != ( int ) sizeof V_53 ) {
* V_3 = F_4 ( V_7 , V_4 ) ;
if ( * V_3 == 0 ) {
if ( V_52 > 0 )
* V_3 = V_33 ;
else if ( V_52 == 0 ) {
if ( V_51 != 0 )
* V_3 = V_33 ;
}
}
return 0 ;
}
V_51 += ( int ) sizeof( V_53 ) ;
V_54 = F_16 ( & V_53 [ 0 ] ) ;
switch ( V_54 ) {
case V_58 :
if ( V_55 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_13 ) ;
return 0 ;
}
V_50 -> V_59 = F_17 ( & V_53 [ 2 ] ) ;
V_55 = TRUE ;
break;
case V_60 :
if ( V_56 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_14 ) ;
return 0 ;
}
V_50 -> V_61 . V_62 = F_17 ( & V_53 [ 2 ] ) ;
V_56 = TRUE ;
break;
case V_63 :
if ( V_57 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_15 ) ;
return 0 ;
}
V_50 -> V_61 . V_64 = F_17 ( & V_53 [ 2 ] ) ;
V_57 = TRUE ;
break;
case V_65 :
break;
case V_66 :
V_50 -> V_67 . V_68 = F_17 ( & V_53 [ 2 ] ) ;
break;
case V_69 :
V_50 -> V_67 . V_70 = F_17 ( & V_53 [ 2 ] ) ;
break;
case V_71 :
V_50 -> V_67 . V_72 = F_17 ( & V_53 [ 2 ] ) ;
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
V_50 -> V_78 = F_17 ( & V_53 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_54 != V_77 );
if ( ! V_55 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_16 ) ;
return 0 ;
}
if ( ! V_56 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_17 ) ;
return 0 ;
}
if ( ! V_57 ) {
* V_3 = V_30 ;
* V_4 = F_11 ( L_18 ) ;
return 0 ;
}
return V_51 ;
}
static T_10 V_38 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_11 * V_79 )
{
T_5 * V_27 = ( T_5 * ) V_1 -> V_43 ;
T_7 V_50 ;
int V_80 ;
double V_81 ;
* V_79 = F_18 ( V_1 -> V_7 ) ;
V_80 = F_14 ( V_1 -> V_7 , & V_50 , V_3 , V_4 ) ;
if ( V_80 == 0 )
return FALSE ;
if ( V_50 . V_78 == 0 )
V_50 . V_78 = V_50 . V_59 ;
if ( V_50 . V_78 > V_82 ) {
* V_3 = V_30 ;
* V_4 = F_10 ( L_19 ,
V_50 . V_78 , V_82 ) ;
return FALSE ;
}
V_1 -> V_83 . V_84 = V_85 | V_86 ;
V_1 -> V_83 . V_87 = V_50 . V_59 ;
V_1 -> V_83 . V_88 = V_50 . V_78 ;
F_19 ( V_1 -> V_89 , V_50 . V_78 ) ;
F_20 ( F_21 ( V_1 -> V_89 ) ,
V_50 . V_78 , V_1 -> V_7 , V_3 ,
V_4 ) ;
V_81 = ( double ) V_50 . V_61 . V_62 +
( double ) V_50 . V_61 . V_64 * 4294967296.0 ;
V_81 *= 1.0e-9 ;
V_81 -= V_90 ;
V_1 -> V_83 . V_91 . V_92 = ( V_93 ) V_81 ;
V_1 -> V_83 . V_91 . V_94 = ( T_3 ) ( ( V_81 - V_1 -> V_83 . V_91 . V_92 ) * 1000000000 ) ;
switch ( V_1 -> V_23 ) {
case V_26 :
V_1 -> V_95 . V_67 = V_50 . V_67 ;
if ( V_27 -> V_47 )
V_1 -> V_95 . V_67 . V_96 = 4 ;
else {
V_1 -> V_95 . V_67 . V_96 = 0 ;
V_1 -> V_83 . V_87 -= 4 ;
V_1 -> V_83 . V_88 -= 4 ;
}
break;
case V_25 :
V_1 -> V_95 . V_97 . V_96 = 0 ;
V_1 -> V_83 . V_87 -= 4 ;
V_1 -> V_83 . V_88 -= 4 ;
break;
}
return TRUE ;
}
static T_10
V_40 ( T_1 * V_1 , T_11 V_98 ,
union V_99 * V_95 , T_8 * V_100 , int V_59 ,
int * V_3 , T_2 * * V_4 )
{
T_5 * V_27 = ( T_5 * ) V_1 -> V_43 ;
T_7 V_50 ;
if ( F_12 ( V_1 -> V_101 , V_98 , V_102 , V_3 ) == - 1 )
return FALSE ;
if ( F_14 ( V_1 -> V_101 , & V_50 , V_3 , V_4 ) == - 1 )
return FALSE ;
switch ( V_1 -> V_23 ) {
case V_26 :
V_95 -> V_67 = V_50 . V_67 ;
if ( V_27 -> V_47 )
V_95 -> V_67 . V_96 = 4 ;
else
V_95 -> V_67 . V_96 = 0 ;
break;
case V_25 :
V_95 -> V_97 . V_96 = 0 ;
break;
}
V_103 = V_104 ;
F_20 ( V_100 , V_59 , V_1 -> V_101 , V_3 , V_4 ) ;
return TRUE ;
}
