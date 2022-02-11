static T_1 F_1 ( const T_2 * V_1 ) {
static T_1 V_2 [] = L_1 ;
if ( * V_1 >= ( T_2 ) sizeof( V_2 ) )
return '?' ;
return V_2 [ ( int ) * V_1 ] ;
}
static T_1 * F_2 ( const struct V_3 * V_4 , T_3 V_5 ,
T_4 V_6 , T_4 V_7 , T_4 V_8 , T_1 V_1 , const T_1 * V_9 ,
const T_1 * log )
{
T_1 V_10 [ 15 ] ;
T_5 V_11 ;
V_11 = ( T_5 ) V_5 ;
switch ( V_4 -> type ) {
case V_12 :
return F_3 ( L_2 ,
V_1 , V_9 , V_7 , log ) ;
case V_13 :
return F_3 ( L_3 ,
V_1 , V_7 , log , V_9 ) ;
case V_14 :
return F_3 ( L_4 ,
V_1 , V_9 , log ) ;
case V_15 :
return F_3 ( L_5 ,
V_1 , V_7 , V_8 , log ) ;
case V_16 :
strftime ( V_10 , sizeof( V_10 ) , L_6 ,
gmtime ( & V_11 ) ) ;
return F_3 ( L_7 ,
V_10 , V_6 , V_1 , V_9 , V_7 , log ) ;
case V_17 :
strftime ( V_10 , sizeof( V_10 ) , L_6 ,
gmtime ( & V_11 ) ) ;
return F_3 ( L_8 ,
V_10 , V_6 , V_7 , V_8 , V_1 , V_9 , log ) ;
case V_18 :
strftime ( V_10 , sizeof( V_10 ) , L_6 ,
gmtime ( & V_11 ) ) ;
return F_3 ( L_9 ,
V_10 , V_6 , V_7 , V_8 , V_1 , V_9 , log ) ;
default:
return NULL ;
}
}
static T_4 F_4 ( T_6 * V_19 , int * V_20 , T_1 * * V_21 )
{
T_4 V_22 ;
T_7 V_23 ;
T_7 V_24 ;
T_2 * V_25 ;
T_8 V_26 ;
T_3 V_27 ;
T_3 V_28 ;
T_7 V_29 ;
V_26 = F_5 ( V_19 -> V_30 ) ;
V_22 = F_6 ( & V_29 , 2 , V_19 -> V_30 ) ;
if ( V_22 != 2 ) {
* V_20 = F_7 ( V_19 -> V_30 , V_21 ) ;
if ( * V_20 == 0 && V_22 != 0 )
* V_20 = V_31 ;
return - 1 ;
}
V_23 = F_8 ( & V_29 ) ;
V_22 = F_6 ( & V_29 , 2 , V_19 -> V_30 ) ;
if ( V_22 != 2 ) {
* V_20 = F_7 ( V_19 -> V_30 , V_21 ) ;
if ( * V_20 == 0 && V_22 != 0 )
* V_20 = V_31 ;
return - 1 ;
}
V_24 = F_8 ( & V_29 ) ;
V_25 = ( T_2 * ) F_9 ( 5 * 4 + V_23 ) ;
V_22 = F_6 ( V_25 , 5 * 4 + V_23 , V_19 -> V_30 ) ;
if ( V_22 != 5 * 4 + V_23 ) {
if ( V_22 != 4 * 4 + V_23 ) {
* V_20 = F_7 ( V_19 -> V_30 , V_21 ) ;
if ( * V_20 == 0 && V_22 != 0 )
* V_20 = V_31 ;
F_10 ( V_25 ) ;
return - 1 ;
}
}
if ( V_24 == 24 ) {
V_28 = ( T_3 ) strlen ( V_25 + 5 * 4 + 1 ) + 1 ;
V_27 = ( T_3 ) strlen ( V_25 + 5 * 4 + 1 + V_28 ) + 1 ;
if ( V_23 == 1 + V_28 + V_27 ) {
F_10 ( V_25 ) ;
return 2 ;
}
}
V_28 = ( T_3 ) strlen ( V_25 + 4 * 4 + 1 ) + 1 ;
V_27 = ( T_3 ) strlen ( V_25 + 4 * 4 + 1 + V_28 ) + 1 ;
if ( V_23 == 1 + V_28 + V_27 ) {
if ( F_11 ( V_19 -> V_30 , V_26 + 4 * 4 + 1 + V_28 + V_27 , V_32 , V_20 ) == - 1 ) {
F_10 ( V_25 ) ;
return - 1 ;
}
F_10 ( V_25 ) ;
return 1 ;
}
F_10 ( V_25 ) ;
return 0 ;
}
static T_9 F_12 ( struct V_33 * V_34 , T_10 V_30 ,
struct V_35 * V_36 , T_11 * V_37 , int * V_20 , T_1 * * V_21 )
{
T_4 V_22 ;
T_4 V_38 ;
T_7 V_23 ;
T_12 V_29 [ 2 ] ;
T_2 * V_39 ;
V_22 = F_6 ( & V_29 , 2 , V_30 ) ;
if ( V_22 != 2 ) {
* V_20 = F_7 ( V_30 , V_21 ) ;
if ( * V_20 == 0 && V_22 != 0 )
* V_20 = V_31 ;
return FALSE ;
}
V_23 = F_8 ( V_29 ) ;
if ( V_34 -> V_40 == 1 ) {
V_38 = 5 * 4 + V_23 ;
} else if ( V_34 -> V_40 == 2 ) {
V_38 = 6 * 4 + V_23 ;
} else {
return FALSE ;
}
F_13 ( V_37 , V_38 ) ;
V_39 = F_14 ( V_37 ) ;
memcpy ( V_39 , V_29 , 2 ) ;
V_22 = F_6 ( V_39 + 2 , V_38 - 2 , V_30 ) ;
if ( V_22 != V_38 - 2 ) {
* V_20 = F_7 ( V_30 , V_21 ) ;
if ( * V_20 == 0 )
* V_20 = V_31 ;
return FALSE ;
}
V_36 -> V_41 = V_42 ;
V_36 -> V_43 = V_44 ;
V_36 -> V_45 . V_46 = ( T_5 ) F_15 ( V_39 + 12 ) ;
V_36 -> V_45 . V_47 = ( int ) F_15 ( V_39 + 16 ) ;
V_36 -> V_48 = V_38 ;
V_36 -> V_49 = V_38 ;
V_36 -> V_50 . V_34 . V_40 = V_34 -> V_40 ;
return TRUE ;
}
static T_9 F_16 ( T_6 * V_19 , int * V_20 , T_1 * * V_21 ,
T_8 * V_51 )
{
* V_51 = F_5 ( V_19 -> V_30 ) ;
return F_12 ( (struct V_33 * ) V_19 -> V_52 , V_19 -> V_30 ,
& V_19 -> V_36 , V_19 -> V_53 , V_20 , V_21 ) ;
}
static T_9 F_17 ( T_6 * V_19 , T_8 V_54 ,
struct V_35 * V_36 , T_11 * V_37 ,
int * V_20 , T_1 * * V_21 )
{
if ( F_11 ( V_19 -> V_55 , V_54 , V_32 , V_20 ) == - 1 )
return FALSE ;
if ( ! F_12 ( (struct V_33 * ) V_19 -> V_52 , V_19 -> V_55 ,
V_36 , V_37 , V_20 , V_21 ) ) {
if ( * V_20 == 0 )
* V_20 = V_31 ;
return FALSE ;
}
return TRUE ;
}
int F_18 ( T_6 * V_19 , int * V_20 , T_1 * * V_21 V_56 )
{
int V_57 ;
T_1 * V_58 ;
T_4 V_40 ;
T_4 V_59 ;
struct V_33 * V_34 ;
V_40 = F_4 ( V_19 , & V_57 , & V_58 ) ;
if ( V_40 <= 0 )
return 0 ;
V_59 = F_4 ( V_19 , & V_57 , & V_58 ) ;
if ( V_59 < 0 && ! F_19 ( V_19 -> V_30 ) ) {
return 0 ;
} else if ( V_59 > 0 ) {
if ( V_59 != V_40 )
return 0 ;
V_59 = F_4 ( V_19 , & V_57 , & V_58 ) ;
if ( V_59 != V_40 && ! F_19 ( V_19 -> V_30 ) )
return 0 ;
}
if ( F_11 ( V_19 -> V_30 , 0 , V_32 , V_20 ) == - 1 )
return - 1 ;
V_34 = (struct V_33 * ) F_9 ( sizeof( struct V_33 ) ) ;
V_34 -> V_40 = V_40 ;
V_19 -> V_52 = V_34 ;
V_19 -> V_60 = V_61 ;
V_19 -> V_62 = V_63 ;
V_19 -> V_64 = 0 ;
V_19 -> V_65 = F_16 ;
V_19 -> V_66 = F_17 ;
V_19 -> V_67 = V_68 ;
return 1 ;
}
int F_20 ( int V_69 )
{
if ( V_69 == V_70 )
return V_71 ;
if ( V_69 != V_63 )
return V_72 ;
return 0 ;
}
static T_9 F_21 ( T_13 * V_73 ,
const struct V_35 * V_36 ,
const T_2 * V_39 , int * V_20 )
{
if ( V_36 -> V_41 != V_42 ) {
* V_20 = V_74 ;
return FALSE ;
}
if ( ! F_22 ( V_73 , V_39 , V_36 -> V_48 , V_20 ) )
return FALSE ;
V_73 -> V_75 += V_36 -> V_48 ;
return TRUE ;
}
T_9 F_23 ( T_13 * V_73 , int * V_20 )
{
V_73 -> V_76 = F_21 ;
V_73 -> V_77 = NULL ;
switch ( V_73 -> V_60 ) {
case V_61 :
V_73 -> V_67 = V_68 ;
break;
default:
* V_20 = V_78 ;
return FALSE ;
}
return TRUE ;
}
static T_9 F_24 ( T_13 * V_73 ,
const struct V_35 * V_36 ,
const T_2 * V_39 , int * V_20 )
{
T_1 * V_37 ;
T_4 V_79 ;
T_1 V_1 ;
const T_1 * V_9 ;
const T_4 * V_7 ;
const T_4 * V_8 ;
const T_1 * log ;
T_1 * V_80 ;
const T_1 * V_81 ;
const T_1 * V_82 ;
const T_3 * V_11 ;
const T_3 * V_83 ;
const union V_84 * V_50 = & V_36 -> V_50 ;
const struct V_3 * V_4 = ( const struct V_3 * ) V_73 -> V_52 ;
if ( V_36 -> V_41 != V_42 ) {
* V_20 = V_74 ;
return FALSE ;
}
if ( V_50 -> V_34 . V_40 == 1 ) {
V_7 = ( const T_4 * ) ( V_39 + 4 ) ;
V_8 = ( const T_4 * ) ( V_39 + 2 * 4 ) ;
V_11 = ( const T_3 * ) ( V_39 + 3 * 4 ) ;
V_83 = ( const T_3 * ) ( V_39 + 4 * 4 ) ;
V_1 = F_1 ( ( const T_2 * ) ( V_39 + 5 * 4 ) ) ;
V_9 = ( const T_1 * ) ( V_39 + 5 * 4 + 1 ) ;
log = V_9 + strlen ( V_9 ) + 1 ;
} else if ( V_50 -> V_34 . V_40 == 2 ) {
V_7 = ( const T_4 * ) ( V_39 + 4 ) ;
V_8 = ( const T_4 * ) ( V_39 + 2 * 4 ) ;
V_11 = ( const T_3 * ) ( V_39 + 3 * 4 ) ;
V_83 = ( const T_3 * ) ( V_39 + 4 * 4 ) ;
V_1 = F_1 ( ( const T_2 * ) ( V_39 + 6 * 4 ) ) ;
V_9 = ( const char * ) ( V_39 + 6 * 4 + 1 ) ;
log = V_9 + strlen ( V_9 ) + 1 ;
} else {
* V_20 = V_85 ;
return FALSE ;
}
V_81 = V_82 = log ;
while ( V_4 -> type != V_18 && ( V_82 = strchr ( V_81 , '\n' ) ) ) {
V_80 = ( T_1 * ) F_9 ( V_82 - V_81 + 1 ) ;
F_25 ( V_80 , V_81 , V_82 - V_81 ) ;
V_80 [ V_82 - V_81 ] = '\0' ;
V_81 = V_82 + 1 ;
V_37 = F_2 ( V_4 , * V_11 , * V_83 / 1000000 , * V_7 , * V_8 ,
V_1 , V_9 , V_80 ) ;
if ( ! V_37 ) {
F_10 ( V_80 ) ;
return FALSE ;
}
F_10 ( V_80 ) ;
V_79 = ( T_3 ) strlen ( V_37 ) ;
if ( ! F_22 ( V_73 , V_37 , V_79 , V_20 ) ) {
F_10 ( V_37 ) ;
return FALSE ;
}
V_73 -> V_75 += V_79 ;
F_10 ( V_37 ) ;
}
if ( * V_81 != '\0' ) {
V_80 = ( T_1 * ) F_9 ( strlen ( V_81 ) + 1 ) ;
F_25 ( V_80 , V_81 , strlen ( V_81 ) ) ;
V_80 [ strlen ( V_81 ) ] = '\0' ;
V_37 = F_2 ( V_4 , * V_11 , * V_83 / 1000000 , * V_7 , * V_8 ,
V_1 , V_9 , V_80 ) ;
if ( ! V_37 ) {
F_10 ( V_80 ) ;
return FALSE ;
}
F_10 ( V_80 ) ;
V_79 = ( T_3 ) strlen ( V_37 ) ;
if ( ! F_22 ( V_73 , V_37 , V_79 , V_20 ) ) {
F_10 ( V_37 ) ;
return FALSE ;
}
V_73 -> V_75 += V_79 ;
F_10 ( V_37 ) ;
}
return TRUE ;
}
T_9 F_26 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_12 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_27 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_13 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_28 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_14 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_29 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_16 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_30 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_15 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_31 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_17 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
T_9 F_32 ( T_13 * V_73 , int * V_20 V_56 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_9 ( sizeof( struct V_3 ) ) ;
V_4 -> type = V_18 ;
V_73 -> V_52 = V_4 ;
V_73 -> V_76 = F_24 ;
V_73 -> V_77 = NULL ;
return TRUE ;
}
