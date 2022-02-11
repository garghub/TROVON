static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = NULL ;
F_2 () ;
V_2 = F_3 ( V_1 ) ;
if ( V_2 && ! F_4 ( V_2 -> V_3 ) )
V_2 = NULL ;
F_5 () ;
return V_2 ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 != V_1 ) ;
F_8 ( V_1 -> V_3 ) ;
}
static inline struct V_1 * F_1 ( void )
{
return V_1 ;
}
static inline void F_6 ( struct V_1 * V_2 ) { }
T_1 long F_9 ( const char T_2 * V_4 ,
unsigned int V_5 , T_3 V_6 , int V_7 )
{
long V_8 ;
struct V_9 * V_10 ;
int V_11 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_12 ;
if ( V_5 & V_13 ) {
V_8 = - V_14 ;
V_10 = F_10 ( V_7 , & V_11 ) ;
if ( V_10 ) {
V_8 = V_2 -> V_15 ( V_4 , V_5 , V_6 , V_10 ) ;
F_11 ( V_10 , V_11 ) ;
}
} else
V_8 = V_2 -> V_15 ( V_4 , V_5 , V_6 , NULL ) ;
F_6 ( V_2 ) ;
return V_8 ;
}
T_1 long F_12 ( int V_16 , T_4 T_2 * V_17 , T_4 T_2 * V_18 )
{
long V_8 ;
struct V_9 * V_19 ;
int V_11 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_12 ;
V_8 = - V_14 ;
V_19 = F_10 ( V_16 , & V_11 ) ;
if ( V_19 ) {
V_8 = V_2 -> V_20 ( V_19 , V_17 , V_18 ) ;
F_11 ( V_19 , V_11 ) ;
}
F_6 ( V_2 ) ;
return V_8 ;
}
int F_13 ( void )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_1 () ;
if ( ! V_2 )
return 0 ;
V_8 = V_2 -> V_21 () ;
F_6 ( V_2 ) ;
return V_8 ;
}
int F_14 ( struct V_9 * V_9 , T_5 * V_22 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_1 () ;
if ( ! V_2 )
return 0 ;
V_8 = V_2 -> V_23 ( V_9 , V_22 ) ;
F_6 ( V_2 ) ;
return V_8 ;
}
void F_15 ( void )
{
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return;
V_2 -> F_15 () ;
F_6 ( V_2 ) ;
return;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_1 )
return - V_24 ;
F_17 ( V_1 , V_2 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_7 ( V_1 -> V_3 != V_2 -> V_3 ) ;
F_17 ( V_1 , NULL ) ;
F_19 () ;
}
