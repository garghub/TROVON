int F_1 ( void )
{
int V_1 ;
int V_2 ;
V_3:
if ( ! F_2 ( & V_4 , V_5 ) )
return - V_6 ;
F_3 ( & V_7 ) ;
V_2 = F_4 ( & V_4 , 1 , & V_1 ) ;
F_5 ( & V_7 ) ;
if ( V_2 == - V_8 )
goto V_3;
else if ( V_2 )
return V_2 ;
if ( V_1 > V_9 ) {
F_3 ( & V_7 ) ;
F_6 ( & V_4 , V_1 ) ;
F_5 ( & V_7 ) ;
return - V_6 ;
}
return V_1 ;
}
static int F_7 ( struct V_10 * V_11 , int V_1 )
{
unsigned long V_12 ;
V_12 = F_8 () ;
V_13 [ V_1 ] . V_14 = F_9 ( V_12 | F_10 ( V_11 -> V_15 ) | V_16 ) ;
return 0 ;
}
int F_11 ( struct V_17 * V_18 , struct V_10 * V_11 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 < 0 )
return V_1 ;
if ( F_12 () ) {
F_7 ( V_11 , V_1 ) ;
} else {
if ( V_11 -> V_19 . V_20 == 0 )
F_13 ( V_11 , V_21 ) ;
F_14 ( V_11 ) ;
}
V_11 -> V_19 . V_20 = V_1 ;
#ifdef F_15
V_11 -> V_19 . V_22 = F_16 ( sizeof( V_23 ) , V_5 ) ;
if ( ! V_11 -> V_19 . V_22 ) {
F_17 ( V_1 ) ;
F_18 ( V_11 ) ;
V_11 -> V_19 . V_20 = V_24 ;
return - V_6 ;
}
F_19 ( V_11 -> V_19 . V_22 ) ;
#endif
#ifdef F_20
V_11 -> V_19 . V_25 = NULL ;
#endif
#ifdef F_21
F_22 ( & V_11 -> V_19 ) ;
#endif
return 0 ;
}
void F_17 ( int V_26 )
{
F_3 ( & V_7 ) ;
F_6 ( & V_4 , V_26 ) ;
F_5 ( & V_7 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
int V_27 ;
void * V_25 ;
struct V_28 * V_28 ;
V_25 = V_11 -> V_19 . V_25 ;
if ( ! V_25 )
return;
V_28 = F_24 ( V_25 ) ;
V_27 = ( ( unsigned long ) V_25 & ~ V_29 ) >> V_30 ;
if ( F_25 ( V_28 , V_31 - V_27 ) ) {
F_26 ( V_28 ) ;
F_27 ( V_28 , 0 ) ;
}
}
static inline void F_23 ( struct V_10 * V_11 )
{
return;
}
void F_28 ( struct V_10 * V_11 )
{
#ifdef F_21
F_29 ( & V_11 -> V_19 ) ;
#endif
#ifdef F_15
F_30 ( V_11 -> V_19 . V_32 , V_11 ) ;
F_31 ( V_11 -> V_19 . V_22 ) ;
V_11 -> V_19 . V_22 = NULL ;
#endif
if ( F_12 () )
V_13 [ V_11 -> V_19 . V_20 ] . V_33 = 0 ;
else
F_18 ( V_11 ) ;
F_23 ( V_11 ) ;
F_17 ( V_11 -> V_19 . V_20 ) ;
V_11 -> V_19 . V_20 = V_24 ;
}
void F_32 ( struct V_10 * V_34 , struct V_10 * V_35 )
{
F_33 ( V_36 , V_35 -> V_19 . V_20 ) ;
asm volatile("isync": : :"memory");
}
