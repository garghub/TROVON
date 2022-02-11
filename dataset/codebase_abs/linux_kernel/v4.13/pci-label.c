static T_1 F_1 ( struct V_1 * V_2 , char * V_3 ,
enum V_4 V_5 )
{
const struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
V_10 = F_2 ( V_2 -> V_11 ) ;
V_11 = V_2 -> V_11 -> V_13 ;
V_12 = V_2 -> V_12 ;
V_7 = NULL ;
while ( ( V_7 = F_3 ( V_14 ,
NULL , V_7 ) ) != NULL ) {
V_9 = V_7 -> V_15 ;
if ( V_9 && V_9 -> V_16 == V_10 &&
V_9 -> V_11 == V_11 &&
V_9 -> V_12 == V_12 ) {
if ( V_3 ) {
if ( V_5 == V_17 )
return F_4 ( V_3 , V_18 ,
L_1 ,
V_9 -> V_19 ) ;
else if ( V_5 == V_20 )
return F_4 ( V_3 , V_18 ,
L_2 ,
V_7 -> V_21 ) ;
}
return strlen ( V_7 -> V_21 ) ;
}
}
return 0 ;
}
static T_2 F_5 ( struct V_22 * V_23 ,
struct V_5 * V_24 , int V_25 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
V_27 = F_6 ( V_23 ) ;
V_2 = F_7 ( V_27 ) ;
return F_1 ( V_2 , NULL , V_28 ) ?
V_29 : 0 ;
}
static T_3 F_8 ( struct V_26 * V_27 ,
struct V_30 * V_24 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_27 ) ;
return F_1 ( V_2 , V_3 ,
V_20 ) ;
}
static T_3 F_9 ( struct V_26 * V_27 ,
struct V_30 * V_24 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_27 ) ;
return F_1 ( V_2 , V_3 ,
V_17 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_27 . V_23 , & V_31 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_27 . V_23 , & V_31 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
}
static void F_14 ( union V_32 * V_33 , char * V_3 )
{
int V_34 ;
V_34 = F_15 ( ( const V_35 * ) V_33 -> V_36 . V_37 ,
V_33 -> V_36 . V_38 ,
V_39 ,
V_3 , V_18 ) ;
V_3 [ V_34 ] = '\n' ;
}
static int F_16 ( struct V_26 * V_27 , char * V_3 ,
enum V_40 V_24 )
{
T_4 V_41 ;
union V_32 * V_33 , * V_42 ;
int V_34 = - 1 ;
V_41 = F_17 ( V_27 ) ;
if ( ! V_41 )
return - 1 ;
V_33 = F_18 ( V_41 , & V_43 , 0x2 ,
V_44 , NULL ) ;
if ( ! V_33 )
return - 1 ;
V_42 = V_33 -> V_45 . V_46 ;
if ( V_33 -> type == V_47 && V_33 -> V_45 . V_48 == 2 &&
V_42 [ 0 ] . type == V_49 &&
( V_42 [ 1 ] . type == V_50 ||
V_42 [ 1 ] . type == V_51 ) ) {
if ( V_24 == V_52 ) {
F_4 ( V_3 , V_18 , L_3 , V_42 -> integer . V_53 ) ;
} else if ( V_24 == V_54 ) {
if ( V_42 [ 1 ] . type == V_50 )
F_4 ( V_3 , V_18 , L_2 ,
V_42 [ 1 ] . string . V_37 ) ;
else if ( V_42 [ 1 ] . type == V_51 )
F_14 ( V_42 + 1 , V_3 ) ;
}
V_34 = strlen ( V_3 ) > 0 ? strlen ( V_3 ) : - 1 ;
}
F_19 ( V_33 ) ;
return V_34 ;
}
static bool F_20 ( struct V_26 * V_27 )
{
T_4 V_41 ;
V_41 = F_17 ( V_27 ) ;
if ( ! V_41 )
return false ;
return ! ! F_21 ( V_41 , & V_43 , 0x2 ,
1 << V_44 ) ;
}
static T_2 F_22 ( struct V_22 * V_23 ,
struct V_5 * V_24 , int V_25 )
{
struct V_26 * V_27 ;
V_27 = F_6 ( V_23 ) ;
if ( F_20 ( V_27 ) )
return V_29 ;
return 0 ;
}
static T_3 F_23 ( struct V_26 * V_27 ,
struct V_30 * V_24 , char * V_3 )
{
return F_16 ( V_27 , V_3 , V_54 ) ;
}
static T_3 F_24 ( struct V_26 * V_27 ,
struct V_30 * V_24 , char * V_3 )
{
return F_16 ( V_27 , V_3 , V_52 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_27 . V_23 , & V_55 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_27 . V_23 , & V_55 ) ;
return 0 ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline bool F_20 ( struct V_26 * V_27 )
{
return false ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( F_20 ( & V_2 -> V_27 ) )
F_25 ( V_2 ) ;
else
F_10 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( F_20 ( & V_2 -> V_27 ) )
F_26 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
