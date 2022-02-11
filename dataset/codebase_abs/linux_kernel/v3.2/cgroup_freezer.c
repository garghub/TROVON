static inline struct V_1 * F_1 (
struct V_2 * V_2 )
{
return F_2 (
F_3 ( V_2 , V_3 ) ,
struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_4 ( struct V_5 * V_6 )
{
return F_2 ( F_5 ( V_6 , V_3 ) ,
struct V_1 , V_4 ) ;
}
static inline int F_6 ( struct V_5 * V_6 )
{
enum V_7 V_8 = F_4 ( V_6 ) -> V_8 ;
return ( V_8 == V_9 ) || ( V_8 == V_10 ) ;
}
int F_7 ( struct V_5 * V_6 )
{
int V_11 ;
F_8 ( V_6 ) ;
V_11 = F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
return V_11 ;
}
static struct F_3 * F_10 ( struct V_12 * V_13 ,
struct V_2 * V_2 )
{
struct V_1 * V_1 ;
V_1 = F_11 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_1 )
return F_12 ( - V_15 ) ;
F_13 ( & V_1 -> V_16 ) ;
V_1 -> V_8 = V_17 ;
return & V_1 -> V_4 ;
}
static void F_14 ( struct V_12 * V_13 ,
struct V_2 * V_2 )
{
F_15 ( F_1 ( V_2 ) ) ;
}
static bool F_16 ( struct V_5 * V_6 )
{
return F_17 ( V_6 ) ||
( F_18 ( V_6 ) && F_19 ( V_6 ) ) ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_2 * V_18 ,
struct V_5 * V_6 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_18 ) ;
if ( V_1 -> V_8 != V_17 )
return - V_19 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_20 , struct V_5 * V_21 )
{
F_22 () ;
if ( F_6 ( V_21 ) ) {
F_23 () ;
return - V_19 ;
}
F_23 () ;
return 0 ;
}
static void F_24 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_1 * V_1 ;
F_22 () ;
V_1 = F_4 ( V_6 ) ;
F_23 () ;
if ( ! V_1 -> V_4 . V_2 -> V_22 )
return;
F_25 ( & V_1 -> V_16 ) ;
F_26 ( V_1 -> V_8 == V_10 ) ;
if ( V_1 -> V_8 == V_9 )
F_27 ( V_6 , true ) ;
F_28 ( & V_1 -> V_16 ) ;
}
static void F_29 ( struct V_2 * V_2 ,
struct V_1 * V_1 )
{
struct V_23 V_24 ;
struct V_5 * V_6 ;
unsigned int V_25 = 0 , V_26 = 0 ;
enum V_7 V_27 = V_1 -> V_8 ;
F_30 ( V_2 , & V_24 ) ;
while ( ( V_6 = F_31 ( V_2 , & V_24 ) ) ) {
V_26 ++ ;
if ( F_16 ( V_6 ) )
V_25 ++ ;
}
if ( V_27 == V_17 ) {
F_26 ( V_25 > 0 ) ;
} else if ( V_27 == V_9 ) {
if ( V_25 == V_26 )
V_1 -> V_8 = V_10 ;
} else {
F_26 ( V_25 != V_26 ) ;
}
F_32 ( V_2 , & V_24 ) ;
}
static int F_33 ( struct V_2 * V_2 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 ;
enum V_7 V_8 ;
if ( ! F_34 ( V_2 ) )
return - V_32 ;
V_1 = F_1 ( V_2 ) ;
F_25 ( & V_1 -> V_16 ) ;
V_8 = V_1 -> V_8 ;
if ( V_8 == V_9 ) {
F_29 ( V_2 , V_1 ) ;
V_8 = V_1 -> V_8 ;
}
F_28 ( & V_1 -> V_16 ) ;
F_35 () ;
F_36 ( V_31 , V_33 [ V_8 ] ) ;
F_37 ( V_31 , '\n' ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_23 V_24 ;
struct V_5 * V_6 ;
unsigned int V_34 = 0 ;
V_1 -> V_8 = V_9 ;
F_30 ( V_2 , & V_24 ) ;
while ( ( V_6 = F_31 ( V_2 , & V_24 ) ) ) {
if ( ! F_27 ( V_6 , true ) )
continue;
if ( F_16 ( V_6 ) )
continue;
if ( ! F_19 ( V_6 ) && ! F_39 ( V_6 ) )
V_34 ++ ;
}
F_32 ( V_2 , & V_24 ) ;
return V_34 ? - V_19 : 0 ;
}
static void F_40 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_23 V_24 ;
struct V_5 * V_6 ;
F_30 ( V_2 , & V_24 ) ;
while ( ( V_6 = F_31 ( V_2 , & V_24 ) ) ) {
F_41 ( V_6 ) ;
}
F_32 ( V_2 , & V_24 ) ;
V_1 -> V_8 = V_17 ;
}
static int F_42 ( struct V_2 * V_2 ,
enum V_7 V_35 )
{
struct V_1 * V_1 ;
int V_36 = 0 ;
V_1 = F_1 ( V_2 ) ;
F_25 ( & V_1 -> V_16 ) ;
F_29 ( V_2 , V_1 ) ;
if ( V_35 == V_1 -> V_8 )
goto V_37;
switch ( V_35 ) {
case V_17 :
F_40 ( V_2 , V_1 ) ;
break;
case V_10 :
V_36 = F_38 ( V_2 , V_1 ) ;
break;
default:
F_43 () ;
}
V_37:
F_28 ( & V_1 -> V_16 ) ;
return V_36 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_28 * V_29 ,
const char * V_38 )
{
int V_36 ;
enum V_7 V_35 ;
if ( strcmp ( V_38 , V_33 [ V_17 ] ) == 0 )
V_35 = V_17 ;
else if ( strcmp ( V_38 , V_33 [ V_10 ] ) == 0 )
V_35 = V_10 ;
else
return - V_39 ;
if ( ! F_34 ( V_2 ) )
return - V_32 ;
V_36 = F_42 ( V_2 , V_35 ) ;
F_35 () ;
return V_36 ;
}
static int F_45 ( struct V_12 * V_13 , struct V_2 * V_2 )
{
if ( ! V_2 -> V_22 )
return 0 ;
return F_46 ( V_2 , V_13 , V_40 , F_47 ( V_40 ) ) ;
}
