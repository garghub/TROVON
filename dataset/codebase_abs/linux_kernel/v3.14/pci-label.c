static T_1
F_1 ( struct V_1 * V_2 , char * V_3 ,
enum V_4 V_5 )
{
const struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
V_10 = V_2 -> V_10 -> V_12 ;
V_11 = V_2 -> V_11 ;
V_7 = NULL ;
while ( ( V_7 = F_2 ( V_13 ,
NULL , V_7 ) ) != NULL ) {
V_9 = V_7 -> V_14 ;
if ( V_9 && V_9 -> V_10 == V_10 &&
V_9 -> V_11 == V_11 ) {
if ( V_3 ) {
if ( V_5 == V_15 )
return F_3 ( V_3 , V_16 ,
L_1 ,
V_9 -> V_17 ) ;
else if ( V_5 == V_18 )
return F_3 ( V_3 , V_16 ,
L_2 ,
V_7 -> V_19 ) ;
}
return strlen ( V_7 -> V_19 ) ;
}
}
return 0 ;
}
static T_2
F_4 ( struct V_20 * V_21 , struct V_5 * V_22 ,
int V_23 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_25 = F_5 ( V_21 , struct V_24 , V_21 ) ;
V_2 = F_6 ( V_25 ) ;
return F_1 ( V_2 , NULL , V_26 ) ?
V_27 : 0 ;
}
static T_3
F_7 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_25 ) ;
return F_1 ( V_2 , V_3 ,
V_18 ) ;
}
static T_3
F_8 ( struct V_24 * V_25 ,
struct V_28 * V_22 , char * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_25 ) ;
return F_1 ( V_2 , V_3 ,
V_15 ) ;
}
static int
F_9 ( struct V_1 * V_2 )
{
return F_10 ( & V_2 -> V_25 . V_21 , & V_29 ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_25 . V_21 , & V_29 ) ;
}
static inline int
F_9 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline void
F_11 ( struct V_1 * V_2 )
{
}
static void F_13 ( union V_30 * V_31 , char * V_3 )
{
int V_32 ;
V_32 = F_14 ( ( const V_33 * ) V_31 -> string . V_34 ,
V_31 -> string . V_35 ,
V_36 ,
V_3 , V_16 ) ;
V_3 [ V_32 ] = '\n' ;
}
static int
F_15 ( struct V_24 * V_25 , char * V_3 , enum V_37 V_22 )
{
T_4 V_38 ;
union V_30 * V_31 , * V_39 ;
int V_32 = - 1 ;
V_38 = F_16 ( V_25 ) ;
if ( ! V_38 )
return - 1 ;
V_31 = F_17 ( V_38 , V_40 , 0x2 ,
V_41 , NULL ) ;
if ( ! V_31 )
return - 1 ;
V_39 = V_31 -> V_42 . V_43 ;
if ( V_31 -> type == V_44 && V_31 -> V_42 . V_45 == 2 &&
V_39 [ 0 ] . type == V_46 &&
V_39 [ 1 ] . type == V_47 ) {
if ( V_22 == V_48 )
F_3 ( V_3 , V_16 , L_3 , V_39 -> integer . V_49 ) ;
else if ( V_22 == V_50 )
F_13 ( V_39 + 1 , V_3 ) ;
V_32 = strlen ( V_3 ) > 0 ? strlen ( V_3 ) : - 1 ;
}
F_18 ( V_31 ) ;
return V_32 ;
}
static bool
F_19 ( struct V_24 * V_25 )
{
T_4 V_38 ;
V_38 = F_16 ( V_25 ) ;
if ( ! V_38 )
return false ;
return ! ! F_20 ( V_38 , V_40 , 0x2 ,
1 << V_41 ) ;
}
static T_2
F_21 ( struct V_20 * V_21 , struct V_5 * V_22 , int V_23 )
{
struct V_24 * V_25 ;
V_25 = F_5 ( V_21 , struct V_24 , V_21 ) ;
if ( F_19 ( V_25 ) )
return V_27 ;
return 0 ;
}
static T_3
F_22 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
return F_15 ( V_25 , V_3 , V_50 ) ;
}
static T_3
F_23 ( struct V_24 * V_25 , struct V_28 * V_22 , char * V_3 )
{
return F_15 ( V_25 , V_3 , V_48 ) ;
}
static int
F_24 ( struct V_1 * V_2 )
{
return F_10 ( & V_2 -> V_25 . V_21 , & V_51 ) ;
}
static int
F_25 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_25 . V_21 , & V_51 ) ;
return 0 ;
}
static inline int
F_24 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline int
F_25 ( struct V_1 * V_2 )
{
return - 1 ;
}
static inline bool
F_19 ( struct V_24 * V_25 )
{
return false ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_19 ( & V_2 -> V_25 ) )
F_24 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( F_19 ( & V_2 -> V_25 ) )
F_25 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
