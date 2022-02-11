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
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ ) {
F_8 ( & V_5 -> V_28 [ V_7 ] . V_30 ) ;
F_9 ( & V_5 -> V_28 [ V_7 ] . V_31 ) ;
}
F_10 ( & V_5 -> V_32 , 0 ) ;
return & V_5 -> V_10 ;
V_15:
F_11 ( V_5 ) ;
return F_3 ( V_6 ) ;
}
static inline T_1 F_12 ( const void * V_33 , T_1 V_34 )
{
return F_13 ( V_33 , V_34 , 0 ) ;
}
static inline struct V_23 * F_14 ( struct V_4 * V_5 , T_1 V_35 )
{
return & V_5 -> V_28 [ V_35 & ( V_5 -> V_16 - 1 ) ] ;
}
static inline struct V_36 * F_15 ( struct V_4 * V_5 , T_1 V_35 )
{
return & F_14 ( V_5 , V_35 ) -> V_30 ;
}
static struct V_20 * F_16 ( struct V_36 * V_30 , T_1 V_35 ,
void * V_33 , T_1 V_11 )
{
struct V_20 * V_37 ;
F_17 (l, head, hash_node)
if ( V_37 -> V_35 == V_35 && ! memcmp ( & V_37 -> V_33 , V_33 , V_11 ) )
return V_37 ;
return NULL ;
}
static void * F_18 ( struct V_1 * V_10 , void * V_33 )
{
struct V_4 * V_5 = F_19 ( V_10 , struct V_4 , V_10 ) ;
struct V_36 * V_30 ;
struct V_20 * V_37 ;
T_1 V_35 , V_11 ;
F_20 ( ! F_21 () ) ;
V_11 = V_10 -> V_11 ;
V_35 = F_12 ( V_33 , V_11 ) ;
V_30 = F_15 ( V_5 , V_35 ) ;
V_37 = F_16 ( V_30 , V_35 , V_33 , V_11 ) ;
if ( V_37 )
return V_37 -> V_33 + F_5 ( V_10 -> V_11 , 8 ) ;
return NULL ;
}
static int F_22 ( struct V_1 * V_10 , void * V_33 , void * V_38 )
{
struct V_4 * V_5 = F_19 ( V_10 , struct V_4 , V_10 ) ;
struct V_36 * V_30 ;
struct V_20 * V_37 , * V_39 ;
T_1 V_35 , V_11 ;
int V_7 ;
F_20 ( ! F_21 () ) ;
V_11 = V_10 -> V_11 ;
V_35 = F_12 ( V_33 , V_11 ) ;
V_30 = F_15 ( V_5 , V_35 ) ;
V_37 = F_16 ( V_30 , V_35 , V_33 , V_11 ) ;
if ( ! V_37 ) {
V_7 = 0 ;
goto V_40;
}
V_39 = F_23 ( F_24 ( F_25 ( & V_37 -> V_41 ) ) ,
struct V_20 , V_41 ) ;
if ( V_39 ) {
memcpy ( V_38 , V_39 -> V_33 , V_11 ) ;
return 0 ;
}
V_7 = V_35 & ( V_5 -> V_16 - 1 ) ;
V_7 ++ ;
V_40:
for (; V_7 < V_5 -> V_16 ; V_7 ++ ) {
V_30 = F_15 ( V_5 , V_7 ) ;
V_39 = F_23 ( F_24 ( F_26 ( V_30 ) ) ,
struct V_20 , V_41 ) ;
if ( V_39 ) {
memcpy ( V_38 , V_39 -> V_33 , V_11 ) ;
return 0 ;
}
}
return - V_42 ;
}
static int F_27 ( struct V_1 * V_10 , void * V_33 , void * V_43 ,
V_24 V_44 )
{
struct V_4 * V_5 = F_19 ( V_10 , struct V_4 , V_10 ) ;
struct V_20 * V_45 , * V_46 ;
struct V_36 * V_30 ;
struct V_23 * V_47 ;
unsigned long V_48 ;
T_1 V_11 ;
int V_49 ;
if ( V_44 > V_50 )
return - V_14 ;
F_20 ( ! F_21 () ) ;
V_45 = F_28 ( V_5 -> V_21 , V_51 | V_29 ) ;
if ( ! V_45 )
return - V_9 ;
V_11 = V_10 -> V_11 ;
memcpy ( V_45 -> V_33 , V_33 , V_11 ) ;
memcpy ( V_45 -> V_33 + F_5 ( V_11 , 8 ) , V_43 , V_10 -> V_12 ) ;
V_45 -> V_35 = F_12 ( V_45 -> V_33 , V_11 ) ;
V_47 = F_14 ( V_5 , V_45 -> V_35 ) ;
V_30 = & V_47 -> V_30 ;
F_29 ( & V_47 -> V_31 , V_48 ) ;
V_46 = F_16 ( V_30 , V_45 -> V_35 , V_33 , V_11 ) ;
if ( ! V_46 && F_30 ( F_31 ( & V_5 -> V_32 ) >= V_10 -> V_13 ) ) {
V_49 = - V_17 ;
goto V_6;
}
if ( V_46 && V_44 == V_52 ) {
V_49 = - V_53 ;
goto V_6;
}
if ( ! V_46 && V_44 == V_50 ) {
V_49 = - V_42 ;
goto V_6;
}
F_32 ( & V_45 -> V_41 , V_30 ) ;
if ( V_46 ) {
F_33 ( & V_46 -> V_41 ) ;
F_34 ( V_46 , V_54 ) ;
} else {
F_35 ( & V_5 -> V_32 ) ;
}
F_36 ( & V_47 -> V_31 , V_48 ) ;
return 0 ;
V_6:
F_36 ( & V_47 -> V_31 , V_48 ) ;
F_11 ( V_45 ) ;
return V_49 ;
}
static int F_37 ( struct V_1 * V_10 , void * V_33 )
{
struct V_4 * V_5 = F_19 ( V_10 , struct V_4 , V_10 ) ;
struct V_36 * V_30 ;
struct V_23 * V_47 ;
struct V_20 * V_37 ;
unsigned long V_48 ;
T_1 V_35 , V_11 ;
int V_49 = - V_42 ;
F_20 ( ! F_21 () ) ;
V_11 = V_10 -> V_11 ;
V_35 = F_12 ( V_33 , V_11 ) ;
V_47 = F_14 ( V_5 , V_35 ) ;
V_30 = & V_47 -> V_30 ;
F_29 ( & V_47 -> V_31 , V_48 ) ;
V_37 = F_16 ( V_30 , V_35 , V_33 , V_11 ) ;
if ( V_37 ) {
F_33 ( & V_37 -> V_41 ) ;
F_38 ( & V_5 -> V_32 ) ;
F_34 ( V_37 , V_54 ) ;
V_49 = 0 ;
}
F_36 ( & V_47 -> V_31 , V_48 ) ;
return V_49 ;
}
static void F_39 ( struct V_4 * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ ) {
struct V_36 * V_30 = F_15 ( V_5 , V_7 ) ;
struct V_55 * V_56 ;
struct V_20 * V_37 ;
F_40 (l, n, head, hash_node) {
F_33 ( & V_37 -> V_41 ) ;
F_38 ( & V_5 -> V_32 ) ;
F_11 ( V_37 ) ;
}
}
}
static void F_41 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = F_19 ( V_10 , struct V_4 , V_10 ) ;
F_42 () ;
F_39 ( V_5 ) ;
F_43 ( V_5 -> V_28 ) ;
F_11 ( V_5 ) ;
}
static int T_2 F_44 ( void )
{
F_45 ( & V_57 ) ;
return 0 ;
}
