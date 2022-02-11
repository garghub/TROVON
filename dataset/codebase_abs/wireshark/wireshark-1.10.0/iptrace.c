int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ 12 ] ;
V_6 = V_7 ;
V_4 = F_2 ( V_5 , 11 , V_1 -> V_8 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_8 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_9 )
return - 1 ;
return 0 ;
}
V_5 [ 11 ] = '\0' ;
if ( strcmp ( V_5 , L_1 ) == 0 ) {
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
}
else if ( strcmp ( V_5 , L_2 ) == 0 ) {
V_1 -> V_10 = V_18 ;
V_1 -> V_12 = V_19 ;
V_1 -> V_14 = V_20 ;
V_1 -> V_16 = V_21 ;
}
else {
return 0 ;
}
return 1 ;
}
static T_3 V_13 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_22 )
{
int V_23 ;
T_5 V_24 ;
T_6 V_25 [ V_26 ] ;
T_6 * V_27 ;
T_7 V_28 ;
T_6 V_29 [ 3 ] ;
* V_22 = F_4 ( V_1 -> V_8 ) ;
V_23 = F_5 ( V_1 -> V_8 , V_25 , V_26 ,
V_2 , V_3 ) ;
if ( V_23 <= 0 ) {
return FALSE ;
}
V_28 . V_30 = V_25 [ 28 ] ;
V_1 -> V_31 . V_32 = F_6 ( V_28 . V_30 ) ;
V_24 = F_7 ( & V_25 [ 0 ] ) ;
if ( V_24 < V_33 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_3 ,
V_24 ) ;
return FALSE ;
}
V_24 -= V_33 ;
if ( V_1 -> V_31 . V_32 == V_35 ) {
if ( V_24 < 3 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_3 ,
V_24 + V_33 ) ;
return FALSE ;
}
V_24 -= 3 ;
if ( ! F_9 ( V_1 -> V_8 , V_29 , 3 , V_2 ,
V_3 ) )
return FALSE ;
}
if ( V_24 > V_36 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_4 ,
V_24 , V_36 ) ;
return FALSE ;
}
F_10 ( V_1 -> V_37 , V_24 ) ;
V_27 = F_11 ( V_1 -> V_37 ) ;
if ( ! F_9 ( V_1 -> V_8 , V_27 , V_24 , V_2 ,
V_3 ) )
return FALSE ;
V_1 -> V_31 . V_38 = V_39 ;
V_1 -> V_31 . V_40 = V_24 ;
V_1 -> V_31 . V_41 = V_24 ;
V_1 -> V_31 . V_42 . V_43 = F_7 ( & V_25 [ 4 ] ) ;
V_1 -> V_31 . V_42 . V_44 = 0 ;
if ( V_1 -> V_31 . V_32 == V_45 ) {
* V_2 = V_46 ;
* V_3 = F_8 ( L_5 ,
V_28 . V_30 ) ;
return FALSE ;
}
F_12 ( V_1 -> V_31 . V_32 , V_27 , V_1 -> V_31 . V_41 ,
& V_1 -> V_31 . V_47 , V_25 ) ;
if ( V_1 -> V_48 == V_45 )
V_1 -> V_48 = V_1 -> V_31 . V_32 ;
else {
if ( V_1 -> V_48 != V_1 -> V_31 . V_32 )
V_1 -> V_48 = V_49 ;
}
return TRUE ;
}
static T_3 V_15 ( T_1 * V_1 , T_4 V_50 ,
struct V_51 * V_31 , T_6 * V_52 , int V_24 ,
int * V_2 , T_2 * * V_3 )
{
union V_53 * V_47 = & V_31 -> V_47 ;
int V_23 ;
T_6 V_25 [ V_26 ] ;
int V_32 ;
T_6 V_29 [ 3 ] ;
if ( F_13 ( V_1 -> V_54 , V_50 , V_55 , V_2 ) == - 1 )
return FALSE ;
V_23 = F_5 ( V_1 -> V_54 , V_25 ,
V_26 , V_2 , V_3 ) ;
if ( V_23 <= 0 ) {
if ( V_23 == 0 ) {
* V_2 = V_9 ;
}
return FALSE ;
}
V_32 = F_6 ( V_25 [ 28 ] ) ;
if ( V_32 == V_35 ) {
if ( ! F_9 ( V_1 -> V_54 , V_29 , 3 ,
V_2 , V_3 ) )
return FALSE ;
}
if ( ! F_9 ( V_1 -> V_54 , V_52 , V_24 , V_2 ,
V_3 ) )
return FALSE ;
F_12 ( V_32 , V_52 , V_24 , V_47 ,
V_25 ) ;
return TRUE ;
}
static T_3 V_19 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_22 )
{
int V_23 ;
T_5 V_24 ;
T_6 V_25 [ V_56 ] ;
T_6 * V_27 ;
T_8 V_28 ;
T_6 V_29 [ 3 ] ;
* V_22 = F_4 ( V_1 -> V_8 ) ;
V_23 = F_5 ( V_1 -> V_8 , V_25 , V_56 ,
V_2 , V_3 ) ;
if ( V_23 <= 0 ) {
return FALSE ;
}
V_28 . V_30 = V_25 [ 28 ] ;
V_1 -> V_31 . V_32 = F_6 ( V_28 . V_30 ) ;
V_24 = F_7 ( & V_25 [ 0 ] ) ;
if ( V_24 < V_57 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_3 ,
V_24 ) ;
return FALSE ;
}
V_24 -= V_57 ;
if ( V_1 -> V_31 . V_32 == V_35 ) {
if ( V_24 < 3 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_3 ,
V_24 + V_57 ) ;
return FALSE ;
}
V_24 -= 3 ;
if ( ! F_9 ( V_1 -> V_8 , V_29 , 3 , V_2 ,
V_3 ) )
return FALSE ;
}
if ( V_24 > V_36 ) {
* V_2 = V_34 ;
* V_3 = F_8 ( L_4 ,
V_24 , V_36 ) ;
return FALSE ;
}
F_10 ( V_1 -> V_37 , V_24 ) ;
V_27 = F_11 ( V_1 -> V_37 ) ;
if ( ! F_9 ( V_1 -> V_8 , V_27 , V_24 , V_2 ,
V_3 ) )
return FALSE ;
V_1 -> V_31 . V_38 = V_39 ;
V_1 -> V_31 . V_40 = V_24 ;
V_1 -> V_31 . V_41 = V_24 ;
V_1 -> V_31 . V_42 . V_43 = F_7 ( & V_25 [ 32 ] ) ;
V_1 -> V_31 . V_42 . V_44 = F_7 ( & V_25 [ 36 ] ) ;
F_12 ( V_1 -> V_31 . V_32 , V_27 , V_1 -> V_31 . V_41 ,
& V_1 -> V_31 . V_47 , V_25 ) ;
if ( V_1 -> V_48 == V_45 )
V_1 -> V_48 = V_1 -> V_31 . V_32 ;
else {
if ( V_1 -> V_48 != V_1 -> V_31 . V_32 )
V_1 -> V_48 = V_49 ;
}
return TRUE ;
}
static T_3 V_20 ( T_1 * V_1 , T_4 V_50 ,
struct V_51 * V_31 , T_6 * V_52 , int V_24 ,
int * V_2 , T_2 * * V_3 )
{
union V_53 * V_47 = & V_31 -> V_47 ;
int V_23 ;
T_6 V_25 [ V_56 ] ;
int V_32 ;
T_6 V_29 [ 3 ] ;
if ( F_13 ( V_1 -> V_54 , V_50 , V_55 , V_2 ) == - 1 )
return FALSE ;
V_23 = F_5 ( V_1 -> V_54 , V_25 ,
V_56 , V_2 , V_3 ) ;
if ( V_23 <= 0 ) {
if ( V_23 == 0 ) {
* V_2 = V_9 ;
}
return FALSE ;
}
V_32 = F_6 ( V_25 [ 28 ] ) ;
if ( V_32 == V_35 ) {
if ( ! F_9 ( V_1 -> V_54 , V_29 , 3 ,
V_2 , V_3 ) )
return FALSE ;
}
if ( ! F_9 ( V_1 -> V_54 , V_52 , V_24 , V_2 ,
V_3 ) )
return FALSE ;
F_12 ( V_32 , V_52 , V_24 , V_47 ,
V_25 ) ;
return TRUE ;
}
static int
F_5 ( T_9 V_8 , T_6 * V_25 , int V_58 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_6 = V_7 ;
V_4 = F_2 ( V_25 , V_58 , V_8 ) ;
if ( V_4 != V_58 ) {
* V_2 = F_3 ( V_8 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_9 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static T_3
F_9 ( T_9 V_8 , T_6 * V_27 , int V_24 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_6 = V_7 ;
V_4 = F_2 ( V_27 , V_24 , V_8 ) ;
if ( V_4 != V_24 ) {
* V_2 = F_3 ( V_8 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_9 ;
return FALSE ;
}
return TRUE ;
}
static void
F_12 ( int V_59 , const T_6 * V_52 , T_5 V_40 ,
union V_53 * V_47 , T_6 * V_25 )
{
char V_60 [ 9 ] ;
char * V_61 ;
int V_62 = 0 ;
int V_63 = 0 ;
switch ( V_59 ) {
case V_64 :
memcpy ( V_60 , & V_25 [ 20 ] , 8 ) ;
V_60 [ 8 ] = '\0' ;
V_61 = strchr ( V_60 , '.' ) ;
if ( V_61 ) {
* V_61 = '\0' ;
V_62 = ( int ) strtoul ( V_60 , NULL , 10 ) ;
V_61 ++ ;
V_63 = ( int ) strtoul ( V_61 , NULL , 10 ) ;
}
V_47 -> V_65 . V_66 = V_25 [ 29 ] ;
V_47 -> V_65 . V_67 = V_62 ;
V_47 -> V_65 . V_68 = V_63 ;
F_14 ( V_52 , V_40 , V_47 ) ;
V_47 -> V_65 . V_69 = 0 ;
V_47 -> V_65 . V_70 = 0 ;
V_47 -> V_65 . V_71 = 0 ;
V_47 -> V_65 . V_72 = 0 ;
V_47 -> V_65 . V_73 = 0 ;
break;
case V_74 :
V_47 -> V_75 . V_76 = 0 ;
break;
}
}
static int
F_6 ( unsigned int V_77 )
{
static const int V_78 [] = {
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_79 ,
V_45 ,
V_74 ,
V_74 ,
V_45 ,
V_80 ,
V_45 ,
V_45 ,
V_79 ,
V_45 ,
V_45 ,
V_35 ,
V_81 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_79 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_45 ,
V_64 ,
} ;
#define F_15 (sizeof ift_encap / sizeof ift_encap[0])
if ( V_77 < F_15 ) {
return V_78 [ V_77 ] ;
}
else {
switch( V_77 ) {
case V_82 :
return V_83 ;
break;
case V_84 :
return V_79 ;
break;
default:
return V_45 ;
}
}
}
