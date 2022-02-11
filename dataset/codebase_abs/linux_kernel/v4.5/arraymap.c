static struct V_1 * F_1 ( union V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 , V_7 ;
if ( V_3 -> V_8 == 0 || V_3 -> V_9 != 4 ||
V_3 -> V_10 == 0 )
return F_2 ( - V_11 ) ;
if ( V_3 -> V_10 >= 1 << ( V_12 - 1 ) )
return F_2 ( - V_13 ) ;
V_6 = F_3 ( V_3 -> V_10 , 8 ) ;
if ( V_6 == 0 ||
V_3 -> V_8 > ( V_14 - V_15 - sizeof( * V_5 ) ) / V_6 )
return F_2 ( - V_16 ) ;
V_7 = sizeof( * V_5 ) + V_3 -> V_8 * V_6 ;
V_5 = F_4 ( V_7 , V_17 | V_18 ) ;
if ( ! V_5 ) {
V_5 = F_5 ( V_7 ) ;
if ( ! V_5 )
return F_2 ( - V_16 ) ;
}
V_5 -> V_19 . V_9 = V_3 -> V_9 ;
V_5 -> V_19 . V_10 = V_3 -> V_10 ;
V_5 -> V_19 . V_8 = V_3 -> V_8 ;
V_5 -> V_19 . V_20 = F_3 ( V_7 , V_15 ) >> V_21 ;
V_5 -> V_6 = V_6 ;
return & V_5 -> V_19 ;
}
static void * F_6 ( struct V_1 * V_19 , void * V_22 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
T_1 V_23 = * ( T_1 * ) V_22 ;
if ( V_23 >= V_5 -> V_19 . V_8 )
return NULL ;
return V_5 -> V_24 + V_5 -> V_6 * V_23 ;
}
static int F_8 ( struct V_1 * V_19 , void * V_22 , void * V_25 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
T_1 V_23 = * ( T_1 * ) V_22 ;
T_1 * V_26 = ( T_1 * ) V_25 ;
if ( V_23 >= V_5 -> V_19 . V_8 ) {
* V_26 = 0 ;
return 0 ;
}
if ( V_23 == V_5 -> V_19 . V_8 - 1 )
return - V_27 ;
* V_26 = V_23 + 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_19 , void * V_22 , void * V_24 ,
T_2 V_28 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
T_1 V_23 = * ( T_1 * ) V_22 ;
if ( V_28 > V_29 )
return - V_11 ;
if ( V_23 >= V_5 -> V_19 . V_8 )
return - V_13 ;
if ( V_28 == V_30 )
return - V_31 ;
memcpy ( V_5 -> V_24 + V_5 -> V_6 * V_23 , V_24 , V_19 -> V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_19 , void * V_22 )
{
return - V_11 ;
}
static void F_11 ( struct V_1 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
F_12 () ;
F_13 ( V_5 ) ;
}
static int T_3 F_14 ( void )
{
F_15 ( & V_32 ) ;
return 0 ;
}
static struct V_1 * F_16 ( union V_2 * V_3 )
{
if ( V_3 -> V_10 != sizeof( T_1 ) )
return F_2 ( - V_11 ) ;
return F_1 ( V_3 ) ;
}
static void F_17 ( struct V_1 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
int V_33 ;
F_12 () ;
for ( V_33 = 0 ; V_33 < V_5 -> V_19 . V_8 ; V_33 ++ )
F_18 ( V_5 -> V_34 [ V_33 ] != NULL ) ;
F_13 ( V_5 ) ;
}
static void * F_19 ( struct V_1 * V_19 , void * V_22 )
{
return NULL ;
}
static int F_20 ( struct V_1 * V_19 , void * V_22 ,
void * V_24 , T_2 V_28 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
void * V_35 , * V_36 ;
T_1 V_23 = * ( T_1 * ) V_22 , V_37 ;
if ( V_28 != V_38 )
return - V_11 ;
if ( V_23 >= V_5 -> V_19 . V_8 )
return - V_13 ;
V_37 = * ( T_1 * ) V_24 ;
V_35 = V_19 -> V_39 -> V_40 ( V_19 , V_37 ) ;
if ( F_21 ( V_35 ) )
return F_22 ( V_35 ) ;
V_36 = F_23 ( V_5 -> V_34 + V_23 , V_35 ) ;
if ( V_36 )
V_19 -> V_39 -> V_41 ( V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_19 , void * V_22 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
void * V_36 ;
T_1 V_23 = * ( T_1 * ) V_22 ;
if ( V_23 >= V_5 -> V_19 . V_8 )
return - V_13 ;
V_36 = F_23 ( V_5 -> V_34 + V_23 , NULL ) ;
if ( V_36 ) {
V_19 -> V_39 -> V_41 ( V_36 ) ;
return 0 ;
} else {
return - V_27 ;
}
}
static void * F_25 ( struct V_1 * V_19 , int V_42 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
struct V_43 * V_44 = F_26 ( V_42 ) ;
if ( F_21 ( V_44 ) )
return V_44 ;
if ( ! F_27 ( V_5 , V_44 ) ) {
F_28 ( V_44 ) ;
return F_2 ( - V_11 ) ;
}
return V_44 ;
}
static void F_29 ( void * V_45 )
{
struct V_43 * V_44 = V_45 ;
F_30 ( V_44 ) ;
}
void F_31 ( struct V_1 * V_19 )
{
struct V_4 * V_5 = F_7 ( V_19 , struct V_4 , V_19 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_5 -> V_19 . V_8 ; V_33 ++ )
F_24 ( V_19 , & V_33 ) ;
}
static int T_3 F_32 ( void )
{
F_15 ( & V_46 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_19 )
{
F_31 ( V_19 ) ;
F_17 ( V_19 ) ;
}
static void * F_34 ( struct V_1 * V_19 , int V_42 )
{
struct V_47 * V_48 ;
const struct V_49 * V_3 ;
struct V_50 * V_50 ;
V_50 = F_35 ( V_42 ) ;
if ( F_21 ( V_50 ) )
return V_50 ;
V_48 = V_50 -> V_51 ;
V_3 = F_36 ( V_48 ) ;
if ( F_21 ( V_3 ) )
goto V_52;
if ( V_3 -> V_53 )
goto V_52;
if ( V_3 -> type == V_54 )
return V_50 ;
if ( V_3 -> type == V_55 )
return V_50 ;
if ( V_3 -> type == V_56 &&
V_3 -> V_57 == V_58 )
return V_50 ;
V_52:
F_37 ( V_50 ) ;
return F_2 ( - V_11 ) ;
}
static void F_38 ( void * V_45 )
{
F_37 ( (struct V_50 * ) V_45 ) ;
}
static int T_3 F_39 ( void )
{
F_15 ( & V_59 ) ;
return 0 ;
}
