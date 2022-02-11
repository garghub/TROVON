static struct V_1 * F_1 ( union V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 , V_7 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
V_5 -> V_10 . V_11 = V_3 -> V_11 ;
V_5 -> V_10 . V_12 = V_3 -> V_12 ;
V_5 -> V_10 . V_13 = V_3 -> V_13 ;
V_6 = - V_14 ;
if ( V_5 -> V_10 . V_13 == 0 || V_5 -> V_10 . V_11 == 0 ||
V_5 -> V_10 . V_12 == 0 )
goto V_15;
V_5 -> V_16 = F_4 ( V_5 -> V_10 . V_13 ) ;
V_6 = - V_17 ;
if ( V_5 -> V_10 . V_11 > V_18 )
goto V_15;
if ( V_5 -> V_10 . V_12 >= ( 1 << ( V_19 - 1 ) ) -
V_18 - sizeof( struct V_20 ) )
goto V_15;
V_5 -> V_21 = sizeof( struct V_20 ) +
F_5 ( V_5 -> V_10 . V_11 , 8 ) +
V_5 -> V_10 . V_12 ;
if ( V_5 -> V_16 == 0 ||
V_5 -> V_16 > V_22 / sizeof( struct V_23 ) )
goto V_15;
if ( ( V_24 ) V_5 -> V_16 * sizeof( struct V_23 ) +
( V_24 ) V_5 -> V_21 * V_5 -> V_10 . V_13 >=
V_22 - V_25 )
goto V_15;
V_5 -> V_10 . V_26 = F_5 ( V_5 -> V_16 * sizeof( struct V_23 ) +
V_5 -> V_21 * V_5 -> V_10 . V_13 ,
V_25 ) >> V_27 ;
V_6 = - V_9 ;
V_5 -> V_28 = F_6 ( V_5 -> V_16 , sizeof( struct V_23 ) ,
V_8 | V_29 ) ;
if ( ! V_5 -> V_28 ) {
V_5 -> V_28 = F_7 ( V_5 -> V_16 * sizeof( struct V_23 ) ) ;
if ( ! V_5 -> V_28 )
goto V_15;
}
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ )
F_8 ( & V_5 -> V_28 [ V_7 ] ) ;
F_9 ( & V_5 -> V_30 ) ;
V_5 -> V_31 = 0 ;
return & V_5 -> V_10 ;
V_15:
F_10 ( V_5 ) ;
return F_3 ( V_6 ) ;
}
static inline T_1 F_11 ( const void * V_32 , T_1 V_33 )
{
return F_12 ( V_32 , V_33 , 0 ) ;
}
static inline struct V_23 * F_13 ( struct V_4 * V_5 , T_1 V_34 )
{
return & V_5 -> V_28 [ V_34 & ( V_5 -> V_16 - 1 ) ] ;
}
static struct V_20 * F_14 ( struct V_23 * V_35 , T_1 V_34 ,
void * V_32 , T_1 V_11 )
{
struct V_20 * V_36 ;
F_15 (l, head, hash_node)
if ( V_36 -> V_34 == V_34 && ! memcmp ( & V_36 -> V_32 , V_32 , V_11 ) )
return V_36 ;
return NULL ;
}
static void * F_16 ( struct V_1 * V_10 , void * V_32 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_23 * V_35 ;
struct V_20 * V_36 ;
T_1 V_34 , V_11 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_34 = F_11 ( V_32 , V_11 ) ;
V_35 = F_13 ( V_5 , V_34 ) ;
V_36 = F_14 ( V_35 , V_34 , V_32 , V_11 ) ;
if ( V_36 )
return V_36 -> V_32 + F_5 ( V_10 -> V_11 , 8 ) ;
return NULL ;
}
static int F_20 ( struct V_1 * V_10 , void * V_32 , void * V_37 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_23 * V_35 ;
struct V_20 * V_36 , * V_38 ;
T_1 V_34 , V_11 ;
int V_7 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_34 = F_11 ( V_32 , V_11 ) ;
V_35 = F_13 ( V_5 , V_34 ) ;
V_36 = F_14 ( V_35 , V_34 , V_32 , V_11 ) ;
if ( ! V_36 ) {
V_7 = 0 ;
goto V_39;
}
V_38 = F_21 ( F_22 ( F_23 ( & V_36 -> V_40 ) ) ,
struct V_20 , V_40 ) ;
if ( V_38 ) {
memcpy ( V_37 , V_38 -> V_32 , V_11 ) ;
return 0 ;
}
V_7 = V_34 & ( V_5 -> V_16 - 1 ) ;
V_7 ++ ;
V_39:
for (; V_7 < V_5 -> V_16 ; V_7 ++ ) {
V_35 = F_13 ( V_5 , V_7 ) ;
V_38 = F_21 ( F_22 ( F_24 ( V_35 ) ) ,
struct V_20 , V_40 ) ;
if ( V_38 ) {
memcpy ( V_37 , V_38 -> V_32 , V_11 ) ;
return 0 ;
}
}
return - V_41 ;
}
static int F_25 ( struct V_1 * V_10 , void * V_32 , void * V_42 ,
V_24 V_43 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_20 * V_44 , * V_45 ;
struct V_23 * V_35 ;
unsigned long V_46 ;
T_1 V_11 ;
int V_47 ;
if ( V_43 > V_48 )
return - V_14 ;
F_18 ( ! F_19 () ) ;
V_44 = F_26 ( V_5 -> V_21 , V_49 | V_29 ) ;
if ( ! V_44 )
return - V_9 ;
V_11 = V_10 -> V_11 ;
memcpy ( V_44 -> V_32 , V_32 , V_11 ) ;
memcpy ( V_44 -> V_32 + F_5 ( V_11 , 8 ) , V_42 , V_10 -> V_12 ) ;
V_44 -> V_34 = F_11 ( V_44 -> V_32 , V_11 ) ;
F_27 ( & V_5 -> V_30 , V_46 ) ;
V_35 = F_13 ( V_5 , V_44 -> V_34 ) ;
V_45 = F_14 ( V_35 , V_44 -> V_34 , V_32 , V_11 ) ;
if ( ! V_45 && F_28 ( V_5 -> V_31 >= V_10 -> V_13 ) ) {
V_47 = - V_17 ;
goto V_6;
}
if ( V_45 && V_43 == V_50 ) {
V_47 = - V_51 ;
goto V_6;
}
if ( ! V_45 && V_43 == V_48 ) {
V_47 = - V_41 ;
goto V_6;
}
F_29 ( & V_44 -> V_40 , V_35 ) ;
if ( V_45 ) {
F_30 ( & V_45 -> V_40 ) ;
F_31 ( V_45 , V_52 ) ;
} else {
V_5 -> V_31 ++ ;
}
F_32 ( & V_5 -> V_30 , V_46 ) ;
return 0 ;
V_6:
F_32 ( & V_5 -> V_30 , V_46 ) ;
F_10 ( V_44 ) ;
return V_47 ;
}
static int F_33 ( struct V_1 * V_10 , void * V_32 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_23 * V_35 ;
struct V_20 * V_36 ;
unsigned long V_46 ;
T_1 V_34 , V_11 ;
int V_47 = - V_41 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_34 = F_11 ( V_32 , V_11 ) ;
F_27 ( & V_5 -> V_30 , V_46 ) ;
V_35 = F_13 ( V_5 , V_34 ) ;
V_36 = F_14 ( V_35 , V_34 , V_32 , V_11 ) ;
if ( V_36 ) {
F_30 ( & V_36 -> V_40 ) ;
V_5 -> V_31 -- ;
F_31 ( V_36 , V_52 ) ;
V_47 = 0 ;
}
F_32 ( & V_5 -> V_30 , V_46 ) ;
return V_47 ;
}
static void F_34 ( struct V_4 * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ ) {
struct V_23 * V_35 = F_13 ( V_5 , V_7 ) ;
struct V_53 * V_54 ;
struct V_20 * V_36 ;
F_35 (l, n, head, hash_node) {
F_30 ( & V_36 -> V_40 ) ;
V_5 -> V_31 -- ;
F_10 ( V_36 ) ;
}
}
}
static void F_36 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
F_37 () ;
F_34 ( V_5 ) ;
F_38 ( V_5 -> V_28 ) ;
F_10 ( V_5 ) ;
}
static int T_2 F_39 ( void )
{
F_40 ( & V_55 ) ;
return 0 ;
}
