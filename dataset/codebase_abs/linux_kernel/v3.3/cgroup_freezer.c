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
bool F_6 ( struct V_5 * V_6 )
{
enum V_7 V_8 ;
bool V_9 ;
F_7 () ;
V_8 = F_4 ( V_6 ) -> V_8 ;
V_9 = V_8 == V_10 || V_8 == V_11 ;
F_8 () ;
return V_9 ;
}
static struct F_3 * F_9 ( struct V_12 * V_13 ,
struct V_2 * V_2 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_1 )
return F_11 ( - V_15 ) ;
F_12 ( & V_1 -> V_16 ) ;
V_1 -> V_8 = V_17 ;
return & V_1 -> V_4 ;
}
static void F_13 ( struct V_12 * V_13 ,
struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( V_1 -> V_8 != V_17 )
F_14 ( & V_18 ) ;
F_15 ( V_1 ) ;
}
static bool F_16 ( struct V_5 * V_6 )
{
return F_17 ( V_6 ) ||
( F_18 ( V_6 ) && F_19 ( V_6 ) ) ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_2 * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_21 (task, new_cgroup, tset)
if ( F_6 ( V_6 ) )
return - V_22 ;
V_1 = F_1 ( V_19 ) ;
if ( V_1 -> V_8 != V_17 )
return - V_22 ;
return 0 ;
}
static void F_22 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_1 * V_1 ;
F_7 () ;
V_1 = F_4 ( V_6 ) ;
F_8 () ;
if ( ! V_1 -> V_4 . V_2 -> V_23 )
return;
F_23 ( & V_1 -> V_16 ) ;
F_24 ( V_1 -> V_8 == V_11 ) ;
if ( V_1 -> V_8 == V_10 )
F_25 ( V_6 ) ;
F_26 ( & V_1 -> V_16 ) ;
}
static void F_27 ( struct V_2 * V_2 ,
struct V_1 * V_1 )
{
struct V_24 V_25 ;
struct V_5 * V_6 ;
unsigned int V_26 = 0 , V_27 = 0 ;
enum V_7 V_28 = V_1 -> V_8 ;
F_28 ( V_2 , & V_25 ) ;
while ( ( V_6 = F_29 ( V_2 , & V_25 ) ) ) {
V_27 ++ ;
if ( F_19 ( V_6 ) && F_16 ( V_6 ) )
V_26 ++ ;
}
if ( V_28 == V_17 ) {
F_24 ( V_26 > 0 ) ;
} else if ( V_28 == V_10 ) {
if ( V_26 == V_27 )
V_1 -> V_8 = V_11 ;
} else {
F_24 ( V_26 != V_27 ) ;
}
F_30 ( V_2 , & V_25 ) ;
}
static int F_31 ( struct V_2 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_1 ;
enum V_7 V_8 ;
if ( ! F_32 ( V_2 ) )
return - V_33 ;
V_1 = F_1 ( V_2 ) ;
F_23 ( & V_1 -> V_16 ) ;
V_8 = V_1 -> V_8 ;
if ( V_8 == V_10 ) {
F_27 ( V_2 , V_1 ) ;
V_8 = V_1 -> V_8 ;
}
F_26 ( & V_1 -> V_16 ) ;
F_33 () ;
F_34 ( V_32 , V_34 [ V_8 ] ) ;
F_35 ( V_32 , '\n' ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_24 V_25 ;
struct V_5 * V_6 ;
unsigned int V_35 = 0 ;
F_28 ( V_2 , & V_25 ) ;
while ( ( V_6 = F_29 ( V_2 , & V_25 ) ) ) {
if ( ! F_25 ( V_6 ) )
continue;
if ( F_16 ( V_6 ) )
continue;
if ( ! F_19 ( V_6 ) && ! F_37 ( V_6 ) )
V_35 ++ ;
}
F_30 ( V_2 , & V_25 ) ;
return V_35 ? - V_22 : 0 ;
}
static void F_38 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_24 V_25 ;
struct V_5 * V_6 ;
F_28 ( V_2 , & V_25 ) ;
while ( ( V_6 = F_29 ( V_2 , & V_25 ) ) )
F_39 ( V_6 ) ;
F_30 ( V_2 , & V_25 ) ;
}
static int F_40 ( struct V_2 * V_2 ,
enum V_7 V_36 )
{
struct V_1 * V_1 ;
int V_37 = 0 ;
V_1 = F_1 ( V_2 ) ;
F_23 ( & V_1 -> V_16 ) ;
F_27 ( V_2 , V_1 ) ;
switch ( V_36 ) {
case V_17 :
if ( V_1 -> V_8 != V_17 )
F_14 ( & V_18 ) ;
V_1 -> V_8 = V_17 ;
F_38 ( V_2 , V_1 ) ;
break;
case V_11 :
if ( V_1 -> V_8 == V_17 )
F_41 ( & V_18 ) ;
V_1 -> V_8 = V_10 ;
V_37 = F_36 ( V_2 , V_1 ) ;
break;
default:
F_42 () ;
}
F_26 ( & V_1 -> V_16 ) ;
return V_37 ;
}
static int F_43 ( struct V_2 * V_2 ,
struct V_29 * V_30 ,
const char * V_38 )
{
int V_37 ;
enum V_7 V_36 ;
if ( strcmp ( V_38 , V_34 [ V_17 ] ) == 0 )
V_36 = V_17 ;
else if ( strcmp ( V_38 , V_34 [ V_11 ] ) == 0 )
V_36 = V_11 ;
else
return - V_39 ;
if ( ! F_32 ( V_2 ) )
return - V_33 ;
V_37 = F_40 ( V_2 , V_36 ) ;
F_33 () ;
return V_37 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_2 * V_2 )
{
if ( ! V_2 -> V_23 )
return 0 ;
return F_45 ( V_2 , V_13 , V_40 , F_46 ( V_40 ) ) ;
}
