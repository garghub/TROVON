static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static inline struct V_2 * F_2 (
struct V_1 * V_3 )
{
return (struct V_2 * ) V_3 ;
}
static int T_1 F_3 ( struct V_1 * V_3 )
{
struct V_4 V_5 = V_6 ;
int V_7 , V_8 ;
void * V_9 ;
V_10 = (struct V_11 * ) V_3 ;
V_7 = F_4 ( V_10 , V_12 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_9 = F_5 ( V_10 -> V_13 [ V_8 ] , & V_5 ) ;
if ( F_6 ( V_9 ) ) {
F_7 () ;
return - 1 ;
}
}
return 0 ;
}
int T_1 F_8 ( void )
{
struct V_4 V_14 = { . V_15 = V_16 } ;
F_9 ( V_16 , NULL , NULL , F_3 ) ;
V_10 = (struct V_11 * ) F_10 ( & V_14 ) ;
return 0 ;
}
static struct V_2 * F_11 ( struct V_4 * V_5 )
{
T_2 V_7 , V_8 ;
void * V_9 ;
V_7 = F_4 ( V_10 , V_12 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_9 = F_5 ( V_10 -> V_13 [ V_8 ] , V_5 ) ;
if ( ! F_6 ( V_9 ) && V_9 )
return F_2 ( V_9 ) ;
}
return NULL ;
}
static void F_12 ( struct V_2 * V_17 )
{
F_13 ( F_1 ( V_17 ) ) ;
}
int F_14 ( char * V_18 , char * V_19 , char * V_20 ,
int (* F_15)( struct V_2 * ) )
{
struct V_2 * V_17 = NULL ;
struct V_4 V_5 ;
int V_9 = 0 ;
if ( V_21 )
return - 1 ;
V_5 . V_15 = V_18 ;
V_5 . V_19 = V_19 ;
V_5 . V_20 = V_20 ;
V_17 = F_11 ( & V_5 ) ;
if ( ! V_17 )
return - V_22 ;
V_9 = F_15 ( V_17 ) ;
F_12 ( V_17 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 ,
T_4 V_30 , T_5 V_31 )
{
struct V_32 * V_33 =
F_17 ( V_28 , struct V_32 , V_34 ) ;
struct V_2 * V_3 = NULL ;
struct V_4 V_5 ;
T_3 V_35 ;
V_5 . V_15 = V_33 -> V_36 ;
V_5 . V_19 = NULL ;
V_5 . V_20 = NULL ;
V_3 = F_11 ( & V_5 ) ;
if ( ! V_3 )
return 0 ;
V_35 = F_18 ( V_29 , V_31 , & V_30 ,
V_3 , V_3 -> V_37 ) ;
F_12 ( V_3 ) ;
return V_35 ;
}
void T_1 F_19 ( void )
{
T_2 V_7 , V_8 ;
struct V_32 * V_33 ;
V_7 = F_4 ( V_10 , V_12 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_33 =
F_20 ( V_10 -> V_13 [ V_8 ] ) ;
V_33 -> V_34 . V_38 = F_16 ;
}
return;
}
