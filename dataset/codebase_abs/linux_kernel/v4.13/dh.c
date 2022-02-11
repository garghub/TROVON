static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_4 ( const struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
return F_5 ( V_7 , V_6 , V_2 -> V_5 , V_2 -> V_3 ) ;
}
static inline struct V_1 * F_6 ( struct V_8 * V_9 )
{
return F_7 ( V_9 ) ;
}
static int F_8 ( unsigned int V_10 )
{
return ( V_10 < 1536 ) ? - V_11 : 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( F_10 ( ! V_13 -> V_3 || ! V_13 -> V_4 ) )
return - V_11 ;
if ( F_8 ( V_13 -> V_14 << 3 ) )
return - V_11 ;
V_2 -> V_3 = F_11 ( V_13 -> V_3 , V_13 -> V_14 ) ;
if ( ! V_2 -> V_3 )
return - V_11 ;
V_2 -> V_4 = F_11 ( V_13 -> V_4 , V_13 -> V_15 ) ;
if ( ! V_2 -> V_4 ) {
F_2 ( V_2 -> V_3 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_12 ( struct V_8 * V_9 , const void * V_16 ,
unsigned int V_17 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_12 V_13 ;
F_3 ( V_2 ) ;
if ( F_13 ( V_16 , V_17 , & V_13 ) < 0 )
return - V_11 ;
if ( F_9 ( V_2 , & V_13 ) < 0 )
return - V_11 ;
V_2 -> V_5 = F_11 ( V_13 . V_18 , V_13 . V_19 ) ;
if ( ! V_2 -> V_5 ) {
F_1 ( V_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = F_15 ( V_21 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_6 , V_7 = F_16 ( 0 ) ;
int V_22 = 0 ;
int V_23 ;
if ( ! V_7 )
return - V_24 ;
if ( F_10 ( ! V_2 -> V_5 ) ) {
V_22 = - V_11 ;
goto V_25;
}
if ( V_21 -> V_26 ) {
V_6 = F_17 ( V_21 -> V_26 , V_21 -> V_27 ) ;
if ( ! V_6 ) {
V_22 = - V_11 ;
goto V_25;
}
} else {
V_6 = V_2 -> V_4 ;
}
V_22 = F_4 ( V_2 , V_6 , V_7 ) ;
if ( V_22 )
goto V_28;
V_22 = F_18 ( V_7 , V_21 -> V_29 , V_21 -> V_30 , & V_23 ) ;
if ( V_22 )
goto V_28;
if ( V_23 < 0 )
V_22 = - V_31 ;
V_28:
if ( V_21 -> V_26 )
F_2 ( V_6 ) ;
V_25:
F_2 ( V_7 ) ;
return V_22 ;
}
static unsigned int F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return F_20 ( V_2 -> V_3 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_3 ( V_2 ) ;
}
static int F_22 ( void )
{
return F_23 ( & V_12 ) ;
}
static void F_24 ( void )
{
F_25 ( & V_12 ) ;
}
