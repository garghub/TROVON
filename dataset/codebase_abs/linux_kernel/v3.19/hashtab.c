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
V_6 = - V_9 ;
if ( V_5 -> V_16 == 0 ||
V_5 -> V_16 > V_19 / sizeof( struct V_20 ) )
goto V_15;
V_5 -> V_21 = F_5 ( V_5 -> V_16 , sizeof( struct V_20 ) ,
V_8 | V_22 ) ;
if ( ! V_5 -> V_21 ) {
V_5 -> V_21 = F_6 ( V_5 -> V_16 * sizeof( struct V_20 ) ) ;
if ( ! V_5 -> V_21 )
goto V_15;
}
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ )
F_7 ( & V_5 -> V_21 [ V_7 ] ) ;
F_8 ( & V_5 -> V_23 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_25 = sizeof( struct V_26 ) +
F_9 ( V_5 -> V_10 . V_11 , 8 ) +
V_5 -> V_10 . V_12 ;
return & V_5 -> V_10 ;
V_15:
F_10 ( V_5 ) ;
return F_3 ( V_6 ) ;
}
static inline T_1 F_11 ( const void * V_27 , T_1 V_28 )
{
return F_12 ( V_27 , V_28 , 0 ) ;
}
static inline struct V_20 * F_13 ( struct V_4 * V_5 , T_1 V_29 )
{
return & V_5 -> V_21 [ V_29 & ( V_5 -> V_16 - 1 ) ] ;
}
static struct V_26 * F_14 ( struct V_20 * V_30 , T_1 V_29 ,
void * V_27 , T_1 V_11 )
{
struct V_26 * V_31 ;
F_15 (l, head, hash_node)
if ( V_31 -> V_29 == V_29 && ! memcmp ( & V_31 -> V_27 , V_27 , V_11 ) )
return V_31 ;
return NULL ;
}
static void * F_16 ( struct V_1 * V_10 , void * V_27 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_20 * V_30 ;
struct V_26 * V_31 ;
T_1 V_29 , V_11 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_29 = F_11 ( V_27 , V_11 ) ;
V_30 = F_13 ( V_5 , V_29 ) ;
V_31 = F_14 ( V_30 , V_29 , V_27 , V_11 ) ;
if ( V_31 )
return V_31 -> V_27 + F_9 ( V_10 -> V_11 , 8 ) ;
return NULL ;
}
static int F_20 ( struct V_1 * V_10 , void * V_27 , void * V_32 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_20 * V_30 ;
struct V_26 * V_31 , * V_33 ;
T_1 V_29 , V_11 ;
int V_7 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_29 = F_11 ( V_27 , V_11 ) ;
V_30 = F_13 ( V_5 , V_29 ) ;
V_31 = F_14 ( V_30 , V_29 , V_27 , V_11 ) ;
if ( ! V_31 ) {
V_7 = 0 ;
goto V_34;
}
V_33 = F_21 ( F_22 ( F_23 ( & V_31 -> V_35 ) ) ,
struct V_26 , V_35 ) ;
if ( V_33 ) {
memcpy ( V_32 , V_33 -> V_27 , V_11 ) ;
return 0 ;
}
V_7 = V_29 & ( V_5 -> V_16 - 1 ) ;
V_7 ++ ;
V_34:
for (; V_7 < V_5 -> V_16 ; V_7 ++ ) {
V_30 = F_13 ( V_5 , V_7 ) ;
V_33 = F_21 ( F_22 ( F_24 ( V_30 ) ) ,
struct V_26 , V_35 ) ;
if ( V_33 ) {
memcpy ( V_32 , V_33 -> V_27 , V_11 ) ;
return 0 ;
}
}
return - V_36 ;
}
static int F_25 ( struct V_1 * V_10 , void * V_27 , void * V_37 ,
T_2 V_38 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_26 * V_39 , * V_40 ;
struct V_20 * V_30 ;
unsigned long V_41 ;
T_1 V_11 ;
int V_42 ;
if ( V_38 > V_43 )
return - V_14 ;
F_18 ( ! F_19 () ) ;
V_39 = F_26 ( V_5 -> V_25 , V_44 ) ;
if ( ! V_39 )
return - V_9 ;
V_11 = V_10 -> V_11 ;
memcpy ( V_39 -> V_27 , V_27 , V_11 ) ;
memcpy ( V_39 -> V_27 + F_9 ( V_11 , 8 ) , V_37 , V_10 -> V_12 ) ;
V_39 -> V_29 = F_11 ( V_39 -> V_27 , V_11 ) ;
F_27 ( & V_5 -> V_23 , V_41 ) ;
V_30 = F_13 ( V_5 , V_39 -> V_29 ) ;
V_40 = F_14 ( V_30 , V_39 -> V_29 , V_27 , V_11 ) ;
if ( ! V_40 && F_28 ( V_5 -> V_24 >= V_10 -> V_13 ) ) {
V_42 = - V_17 ;
goto V_6;
}
if ( V_40 && V_38 == V_45 ) {
V_42 = - V_46 ;
goto V_6;
}
if ( ! V_40 && V_38 == V_43 ) {
V_42 = - V_36 ;
goto V_6;
}
F_29 ( & V_39 -> V_35 , V_30 ) ;
if ( V_40 ) {
F_30 ( & V_40 -> V_35 ) ;
F_31 ( V_40 , V_47 ) ;
} else {
V_5 -> V_24 ++ ;
}
F_32 ( & V_5 -> V_23 , V_41 ) ;
return 0 ;
V_6:
F_32 ( & V_5 -> V_23 , V_41 ) ;
F_10 ( V_39 ) ;
return V_42 ;
}
static int F_33 ( struct V_1 * V_10 , void * V_27 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
struct V_20 * V_30 ;
struct V_26 * V_31 ;
unsigned long V_41 ;
T_1 V_29 , V_11 ;
int V_42 = - V_36 ;
F_18 ( ! F_19 () ) ;
V_11 = V_10 -> V_11 ;
V_29 = F_11 ( V_27 , V_11 ) ;
F_27 ( & V_5 -> V_23 , V_41 ) ;
V_30 = F_13 ( V_5 , V_29 ) ;
V_31 = F_14 ( V_30 , V_29 , V_27 , V_11 ) ;
if ( V_31 ) {
F_30 ( & V_31 -> V_35 ) ;
V_5 -> V_24 -- ;
F_31 ( V_31 , V_47 ) ;
V_42 = 0 ;
}
F_32 ( & V_5 -> V_23 , V_41 ) ;
return V_42 ;
}
static void F_34 ( struct V_4 * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; V_7 ++ ) {
struct V_20 * V_30 = F_13 ( V_5 , V_7 ) ;
struct V_48 * V_49 ;
struct V_26 * V_31 ;
F_35 (l, n, head, hash_node) {
F_30 ( & V_31 -> V_35 ) ;
V_5 -> V_24 -- ;
F_10 ( V_31 ) ;
}
}
}
static void F_36 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = F_17 ( V_10 , struct V_4 , V_10 ) ;
F_37 () ;
F_34 ( V_5 ) ;
F_38 ( V_5 -> V_21 ) ;
F_10 ( V_5 ) ;
}
static int T_3 F_39 ( void )
{
F_40 ( & V_50 ) ;
return 0 ;
}
