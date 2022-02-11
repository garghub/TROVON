int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ 12 ] ;
V_6 = V_7 ;
V_4 = F_2 ( V_5 , 11 , V_1 -> V_8 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_8 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_5 [ 11 ] = 0 ;
if ( strcmp ( V_5 , L_1 ) == 0 ) {
V_1 -> V_9 = V_10 ;
V_1 -> V_11 = V_12 ;
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
}
else if ( strcmp ( V_5 , L_2 ) == 0 ) {
V_1 -> V_9 = V_17 ;
V_1 -> V_11 = V_18 ;
V_1 -> V_13 = V_19 ;
V_1 -> V_15 = V_20 ;
}
else {
return 0 ;
}
return 1 ;
}
static T_3 V_12 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_21 )
{
int V_22 ;
T_5 V_23 ;
T_6 V_24 [ V_25 ] ;
T_6 * V_26 ;
T_7 V_27 ;
T_6 V_28 [ 3 ] ;
* V_21 = F_4 ( V_1 -> V_8 ) ;
V_22 = F_5 ( V_1 -> V_8 , V_24 , V_25 ,
V_2 , V_3 ) ;
if ( V_22 <= 0 ) {
return FALSE ;
}
V_27 . V_29 = V_24 [ 28 ] ;
V_1 -> V_30 . V_31 = F_6 ( V_27 . V_29 ) ;
V_23 = F_7 ( & V_24 [ 0 ] ) ;
if ( V_23 < V_32 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_3 ,
V_23 ) ;
return FALSE ;
}
V_23 -= V_32 ;
if ( V_1 -> V_30 . V_31 == V_34 ) {
if ( V_23 < 3 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_3 ,
V_23 + V_32 ) ;
return FALSE ;
}
V_23 -= 3 ;
if ( ! F_9 ( V_1 -> V_8 , V_28 , 3 , V_2 ,
V_3 ) )
return FALSE ;
}
if ( V_23 > V_35 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_4 ,
V_23 , V_35 ) ;
return FALSE ;
}
F_10 ( V_1 -> V_36 , V_23 ) ;
V_26 = F_11 ( V_1 -> V_36 ) ;
if ( ! F_9 ( V_1 -> V_8 , V_26 , V_23 , V_2 ,
V_3 ) )
return FALSE ;
V_1 -> V_30 . V_37 = V_38 ;
V_1 -> V_30 . V_39 = V_23 ;
V_1 -> V_30 . V_40 = V_23 ;
V_1 -> V_30 . V_41 . V_42 = F_7 ( & V_24 [ 4 ] ) ;
V_1 -> V_30 . V_41 . V_43 = 0 ;
if ( V_1 -> V_30 . V_31 == V_44 ) {
* V_2 = V_45 ;
* V_3 = F_8 ( L_5 ,
V_27 . V_29 ) ;
return FALSE ;
}
F_12 ( V_1 -> V_30 . V_31 , V_26 , V_1 -> V_30 . V_40 ,
& V_1 -> V_46 , V_24 ) ;
if ( V_1 -> V_47 == V_44 )
V_1 -> V_47 = V_1 -> V_30 . V_31 ;
else {
if ( V_1 -> V_47 != V_1 -> V_30 . V_31 )
V_1 -> V_47 = V_48 ;
}
return TRUE ;
}
static T_3 V_14 ( T_1 * V_1 , T_4 V_49 ,
union V_50 * V_46 , T_6 * V_51 , int V_23 ,
int * V_2 , T_2 * * V_3 )
{
int V_22 ;
T_6 V_24 [ V_25 ] ;
int V_31 ;
T_6 V_28 [ 3 ] ;
if ( F_13 ( V_1 -> V_52 , V_49 , V_53 , V_2 ) == - 1 )
return FALSE ;
V_22 = F_5 ( V_1 -> V_52 , V_24 ,
V_25 , V_2 , V_3 ) ;
if ( V_22 <= 0 ) {
if ( V_22 == 0 ) {
* V_2 = V_54 ;
}
return FALSE ;
}
V_31 = F_6 ( V_24 [ 28 ] ) ;
if ( V_31 == V_34 ) {
if ( ! F_9 ( V_1 -> V_52 , V_28 , 3 ,
V_2 , V_3 ) )
return FALSE ;
}
if ( ! F_9 ( V_1 -> V_52 , V_51 , V_23 , V_2 ,
V_3 ) )
return FALSE ;
F_12 ( V_31 , V_51 , V_23 , V_46 ,
V_24 ) ;
return TRUE ;
}
static T_3 V_18 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_21 )
{
int V_22 ;
T_5 V_23 ;
T_6 V_24 [ V_55 ] ;
T_6 * V_26 ;
T_8 V_27 ;
T_6 V_28 [ 3 ] ;
* V_21 = F_4 ( V_1 -> V_8 ) ;
V_22 = F_5 ( V_1 -> V_8 , V_24 , V_55 ,
V_2 , V_3 ) ;
if ( V_22 <= 0 ) {
return FALSE ;
}
V_27 . V_29 = V_24 [ 28 ] ;
V_1 -> V_30 . V_31 = F_6 ( V_27 . V_29 ) ;
V_23 = F_7 ( & V_24 [ 0 ] ) ;
if ( V_23 < V_56 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_3 ,
V_23 ) ;
return FALSE ;
}
V_23 -= V_56 ;
if ( V_1 -> V_30 . V_31 == V_34 ) {
if ( V_23 < 3 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_3 ,
V_23 + V_56 ) ;
return FALSE ;
}
V_23 -= 3 ;
if ( ! F_9 ( V_1 -> V_8 , V_28 , 3 , V_2 ,
V_3 ) )
return FALSE ;
}
if ( V_23 > V_35 ) {
* V_2 = V_33 ;
* V_3 = F_8 ( L_4 ,
V_23 , V_35 ) ;
return FALSE ;
}
F_10 ( V_1 -> V_36 , V_23 ) ;
V_26 = F_11 ( V_1 -> V_36 ) ;
if ( ! F_9 ( V_1 -> V_8 , V_26 , V_23 , V_2 ,
V_3 ) )
return FALSE ;
V_1 -> V_30 . V_37 = V_38 ;
V_1 -> V_30 . V_39 = V_23 ;
V_1 -> V_30 . V_40 = V_23 ;
V_1 -> V_30 . V_41 . V_42 = F_7 ( & V_24 [ 32 ] ) ;
V_1 -> V_30 . V_41 . V_43 = F_7 ( & V_24 [ 36 ] ) ;
if ( V_1 -> V_30 . V_31 == V_44 ) {
* V_2 = V_45 ;
* V_3 = F_8 ( L_5 ,
V_27 . V_29 ) ;
return FALSE ;
}
F_12 ( V_1 -> V_30 . V_31 , V_26 , V_1 -> V_30 . V_40 ,
& V_1 -> V_46 , V_24 ) ;
if ( V_1 -> V_47 == V_44 )
V_1 -> V_47 = V_1 -> V_30 . V_31 ;
else {
if ( V_1 -> V_47 != V_1 -> V_30 . V_31 )
V_1 -> V_47 = V_48 ;
}
return TRUE ;
}
static T_3 V_19 ( T_1 * V_1 , T_4 V_49 ,
union V_50 * V_46 , T_6 * V_51 , int V_23 ,
int * V_2 , T_2 * * V_3 )
{
int V_22 ;
T_6 V_24 [ V_55 ] ;
int V_31 ;
T_6 V_28 [ 3 ] ;
if ( F_13 ( V_1 -> V_52 , V_49 , V_53 , V_2 ) == - 1 )
return FALSE ;
V_22 = F_5 ( V_1 -> V_52 , V_24 ,
V_55 , V_2 , V_3 ) ;
if ( V_22 <= 0 ) {
if ( V_22 == 0 ) {
* V_2 = V_54 ;
}
return FALSE ;
}
V_31 = F_6 ( V_24 [ 28 ] ) ;
if ( V_31 == V_34 ) {
if ( ! F_9 ( V_1 -> V_52 , V_28 , 3 ,
V_2 , V_3 ) )
return FALSE ;
}
if ( ! F_9 ( V_1 -> V_52 , V_51 , V_23 , V_2 ,
V_3 ) )
return FALSE ;
F_12 ( V_31 , V_51 , V_23 , V_46 ,
V_24 ) ;
return TRUE ;
}
static int
F_5 ( T_9 V_8 , T_6 * V_24 , int V_57 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_6 = V_7 ;
V_4 = F_2 ( V_24 , V_57 , V_8 ) ;
if ( V_4 != V_57 ) {
* V_2 = F_3 ( V_8 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_54 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static T_3
F_9 ( T_9 V_8 , T_6 * V_26 , int V_23 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_6 = V_7 ;
V_4 = F_2 ( V_26 , V_23 , V_8 ) ;
if ( V_4 != V_23 ) {
* V_2 = F_3 ( V_8 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_54 ;
return FALSE ;
}
return TRUE ;
}
static void
F_12 ( int V_58 , const T_6 * V_51 , T_5 V_39 ,
union V_50 * V_46 , T_6 * V_24 )
{
char V_59 [ 9 ] ;
char * V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
switch ( V_58 ) {
case V_63 :
memcpy ( V_59 , & V_24 [ 20 ] , 8 ) ;
V_59 [ 8 ] = '\0' ;
V_60 = strchr ( V_59 , '.' ) ;
if ( V_60 ) {
* V_60 = '\0' ;
V_61 = ( int ) strtoul ( V_59 , NULL , 10 ) ;
V_60 ++ ;
V_62 = ( int ) strtoul ( V_60 , NULL , 10 ) ;
}
V_46 -> V_64 . V_65 = V_24 [ 29 ] ;
V_46 -> V_64 . V_66 = V_61 ;
V_46 -> V_64 . V_67 = V_62 ;
F_14 ( V_51 , V_39 , V_46 ) ;
V_46 -> V_64 . V_68 = 0 ;
V_46 -> V_64 . V_69 = 0 ;
V_46 -> V_64 . V_70 = 0 ;
V_46 -> V_64 . V_71 = 0 ;
V_46 -> V_64 . V_72 = 0 ;
break;
case V_73 :
V_46 -> V_74 . V_75 = 0 ;
break;
}
}
static int
F_6 ( unsigned int V_76 )
{
static const int V_77 [] = {
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_78 ,
V_44 ,
V_73 ,
V_73 ,
V_44 ,
V_79 ,
V_44 ,
V_44 ,
V_78 ,
V_44 ,
V_44 ,
V_34 ,
V_80 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_78 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_44 ,
V_63 ,
} ;
#define F_15 (sizeof ift_encap / sizeof ift_encap[0])
if ( V_76 < F_15 ) {
return V_77 [ V_76 ] ;
}
else {
return V_44 ;
}
}
