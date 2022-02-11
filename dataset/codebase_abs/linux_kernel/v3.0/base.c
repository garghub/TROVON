void F_1 ( struct V_1 * V_2 )
{
static unsigned int V_3 ;
F_2 ( & V_4 ) ;
if ( V_3 == 0 ) {
V_3 = V_2 -> V_5 ;
F_3 ( L_1 , V_3 ) ;
}
V_2 -> V_6 = V_7 ;
V_7 = V_2 ;
if ( V_8 )
F_4 ( V_9 , V_2 ) ;
F_5 ( & V_4 ) ;
}
void F_6 ( void )
{
}
void F_7 ( T_1 * V_10 , unsigned int V_11 )
{
}
void F_8 ( T_1 * V_10 , unsigned int V_11 )
{
}
void F_9 ( T_1 * V_10 , unsigned int V_11 )
{
}
void F_10 ( void )
{
struct V_1 * V_2 ;
F_2 ( & V_4 ) ;
V_8 = 1 ;
for ( V_2 = V_7 ; V_2 ; V_2 = V_2 -> V_6 )
F_4 ( V_9 , V_2 ) ;
F_5 ( & V_4 ) ;
}
static inline int F_11 ( void * V_12 , void * V_13 , unsigned long V_14 )
{
return ( ( V_12 >= V_13 ) && ( V_12 < V_13 + V_14 ) ) ;
}
static int F_12 ( struct V_15 * V_16 , unsigned long V_17 ,
void * V_18 )
{
struct V_19 * V_20 = V_18 ;
struct V_1 * V_2 ;
struct V_1 * V_21 ;
if ( V_17 != V_22 )
return V_23 ;
F_2 ( & V_4 ) ;
V_21 = NULL ;
for ( V_2 = V_7 ; V_2 ; V_2 = V_2 -> V_6 ) {
if ( F_11 ( V_2 , V_20 -> V_24 , V_20 -> V_25 ) ) {
if ( V_21 )
V_21 -> V_6 = V_2 -> V_6 ;
else
V_7 = V_2 -> V_6 ;
if ( V_8 )
F_4 ( V_26 , V_2 ) ;
} else
V_21 = V_2 ;
}
F_5 ( & V_4 ) ;
return V_23 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_27 ) ;
}
