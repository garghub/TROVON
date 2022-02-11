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
T_1 long F_9 ( int V_4 , T_2 T_3 * V_5 , T_2 T_3 * V_6 )
{
long V_7 ;
struct V_4 V_8 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_9 ;
V_7 = - V_10 ;
V_8 = F_10 ( V_4 ) ;
if ( V_8 . V_11 ) {
V_7 = V_2 -> V_12 ( V_8 . V_11 , V_5 , V_6 ) ;
F_11 ( V_8 ) ;
}
F_6 ( V_2 ) ;
return V_7 ;
}
int F_12 ( void )
{
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_1 () ;
if ( ! V_2 )
return 0 ;
V_7 = V_2 -> V_13 () ;
F_6 ( V_2 ) ;
return V_7 ;
}
int F_13 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_1 () ;
if ( ! V_2 )
return 0 ;
V_7 = V_2 -> V_16 ( V_15 ) ;
F_6 ( V_2 ) ;
return V_7 ;
}
void F_14 ( void )
{
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 )
return;
V_2 -> F_14 () ;
F_6 ( V_2 ) ;
return;
}
int F_15 ( struct V_1 * V_2 )
{
if ( V_1 )
return - V_17 ;
F_16 ( V_1 , V_2 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_7 ( V_1 -> V_3 != V_2 -> V_3 ) ;
F_16 ( V_1 , NULL ) ;
F_18 () ;
}
