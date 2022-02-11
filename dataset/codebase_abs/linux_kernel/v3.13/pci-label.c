static inline int
F_1 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline void
F_2 ( struct V_1 * V_2 )
{
}
static T_1
F_3 ( struct V_1 * V_2 , char * V_3 ,
enum V_4 V_5 )
{
const struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
V_10 = V_2 -> V_10 -> V_12 ;
V_11 = V_2 -> V_11 ;
V_7 = NULL ;
while ( ( V_7 = F_4 ( V_13 ,
NULL , V_7 ) ) != NULL ) {
V_9 = V_7 -> V_14 ;
if ( V_9 && V_9 -> V_10 == V_10 &&
V_9 -> V_11 == V_11 ) {
if ( V_3 ) {
if ( V_5 == V_15 )
return F_5 ( V_3 , V_16 ,
L_1 ,
V_9 -> V_17 ) ;
else if ( V_5 == V_18 )
return F_5 ( V_3 , V_16 ,
L_2 ,
V_7 -> V_19 ) ;
}
return strlen ( V_7 -> V_19 ) ;
}
}
return 0 ;
}
static T_2
F_6 ( struct V_20 * V_21 , struct V_5 * V_22 ,
int V_23 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_25 = F_7 ( V_21 , struct V_24 , V_21 ) ;
V_2 = F_8 ( V_25 ) ;
return F_3 ( V_2 , NULL , V_26 ) ?
V_27 : 0 ;
}
static T_3
F_9 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_25 ) ;
return F_3 ( V_2 , V_3 ,
V_18 ) ;
}
static T_3
F_10 ( struct V_24 * V_25 ,
struct V_28 * V_22 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_25 ) ;
return F_3 ( V_2 , V_3 ,
V_15 ) ;
}
static int
F_1 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_25 . V_21 , & V_29 ) ;
}
static void
F_2 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_25 . V_21 , & V_29 ) ;
}
static inline int
F_13 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline int
F_14 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline bool
F_15 ( struct V_24 * V_25 )
{
return false ;
}
static void F_16 ( union V_30 * V_31 , char * V_3 )
{
int V_32 ;
V_32 = F_17 ( ( const V_33 * ) V_31 ->
V_34 . V_35 [ 1 ] . string . V_36 ,
V_31 -> V_34 . V_35 [ 1 ] . string . V_37 ,
V_38 ,
V_3 , V_16 ) ;
V_3 [ V_32 ] = '\n' ;
}
static int
F_18 ( T_4 V_39 , int V_40 ,
struct V_41 * V_42 ,
char * V_3 , enum V_43 V_5 )
{
struct V_44 V_45 ;
union V_30 V_46 [ 4 ] ;
union V_30 * V_31 ;
int V_32 = 0 ;
int V_47 ;
V_45 . V_48 = 4 ;
V_45 . V_36 = V_46 ;
V_46 [ 0 ] . type = V_49 ;
V_46 [ 0 ] . V_50 . V_37 = sizeof( V_51 ) ;
V_46 [ 0 ] . V_50 . V_36 = ( char * ) V_51 ;
V_46 [ 1 ] . type = V_52 ;
V_46 [ 1 ] . integer . V_53 = 0x02 ;
V_46 [ 2 ] . type = V_52 ;
V_46 [ 2 ] . integer . V_53 = V_40 ;
V_46 [ 3 ] . type = V_54 ;
V_46 [ 3 ] . V_34 . V_48 = 0 ;
V_46 [ 3 ] . V_34 . V_35 = NULL ;
V_47 = F_19 ( V_39 , L_3 , & V_45 , V_42 ) ;
if ( V_47 )
return - 1 ;
V_31 = (union V_30 * ) V_42 -> V_36 ;
switch ( V_31 -> type ) {
case V_54 :
if ( V_31 -> V_34 . V_48 != 2 )
break;
V_32 = V_31 -> V_34 . V_35 [ 0 ] . integer . V_53 ;
if ( V_3 ) {
if ( V_5 == V_55 )
F_5 ( V_3 , V_16 , L_4 ,
V_31 -> V_34 . V_35 [ 0 ] . integer . V_53 ) ;
else if ( V_5 == V_56 )
F_16 ( V_31 , V_3 ) ;
F_20 ( V_42 -> V_36 ) ;
return strlen ( V_3 ) ;
}
F_20 ( V_42 -> V_36 ) ;
return V_32 ;
break;
default:
F_20 ( V_42 -> V_36 ) ;
}
return - 1 ;
}
static bool
F_15 ( struct V_24 * V_25 )
{
T_4 V_39 ;
struct V_41 V_42 = { V_57 , NULL } ;
V_39 = F_21 ( V_25 ) ;
if ( ! V_39 )
return FALSE ;
if ( F_18 ( V_39 , V_58 , & V_42 , NULL ,
V_59 ) > 0 )
return TRUE ;
return FALSE ;
}
static T_2
F_22 ( struct V_20 * V_21 , struct V_5 * V_22 , int V_23 )
{
struct V_24 * V_25 ;
V_25 = F_7 ( V_21 , struct V_24 , V_21 ) ;
if ( F_15 ( V_25 ) )
return V_27 ;
return 0 ;
}
static T_3
F_23 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
struct V_41 V_42 = { V_57 , NULL } ;
T_4 V_39 ;
int V_37 ;
V_39 = F_21 ( V_25 ) ;
if ( ! V_39 )
return - 1 ;
V_37 = F_18 ( V_39 , V_58 ,
& V_42 , V_3 , V_56 ) ;
if ( V_37 < 1 )
return - 1 ;
return V_37 ;
}
static T_3
F_24 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
struct V_41 V_42 = { V_57 , NULL } ;
T_4 V_39 ;
int V_37 ;
V_39 = F_21 ( V_25 ) ;
if ( ! V_39 )
return - 1 ;
V_37 = F_18 ( V_39 , V_58 ,
& V_42 , V_3 , V_55 ) ;
if ( V_37 < 0 )
return - 1 ;
return V_37 ;
}
static int
F_13 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_25 . V_21 , & V_60 ) ;
}
static int
F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_25 . V_21 , & V_60 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_15 ( & V_2 -> V_25 ) )
F_13 ( V_2 ) ;
else
F_1 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_15 ( & V_2 -> V_25 ) )
F_14 ( V_2 ) ;
else
F_2 ( V_2 ) ;
}
