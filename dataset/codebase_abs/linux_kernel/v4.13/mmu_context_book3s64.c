static int F_1 ( int V_1 , int V_2 )
{
int V_3 , V_4 ;
V_5:
if ( ! F_2 ( & V_6 , V_7 ) )
return - V_8 ;
F_3 ( & V_9 ) ;
V_4 = F_4 ( & V_6 , V_1 , & V_3 ) ;
F_5 ( & V_9 ) ;
if ( V_4 == - V_10 )
goto V_5;
else if ( V_4 )
return V_4 ;
if ( V_3 > V_2 ) {
F_3 ( & V_9 ) ;
F_6 ( & V_6 , V_3 ) ;
F_5 ( & V_9 ) ;
return - V_8 ;
}
return V_3 ;
}
void F_7 ( int V_11 )
{
int V_12 , V_13 = 0 ;
do {
if ( ! F_2 ( & V_6 , V_7 ) )
break;
F_3 ( & V_9 ) ;
V_12 = F_4 ( & V_6 , V_11 , & V_13 ) ;
F_5 ( & V_9 ) ;
} while ( V_12 == - V_10 );
F_8 ( V_13 != V_11 , L_1 , V_11 , V_13 ) ;
}
int F_9 ( void )
{
unsigned long V_14 ;
if ( F_10 ( V_15 ) )
V_14 = V_16 ;
else
V_14 = V_17 ;
return F_1 ( V_18 , V_14 ) ;
}
static int F_11 ( struct V_19 * V_20 )
{
int V_3 ;
V_3 = F_9 () ;
if ( V_3 < 0 )
return V_3 ;
V_20 -> V_21 . V_22 = V_23 ;
if ( V_20 -> V_21 . V_11 == 0 )
F_12 ( V_20 , V_24 ) ;
F_13 ( V_20 ) ;
return V_3 ;
}
static int F_14 ( struct V_19 * V_20 )
{
unsigned long V_25 ;
int V_3 , V_2 ;
V_2 = ( 1 << V_26 ) - 1 ;
V_3 = F_1 ( V_27 , V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_25 = F_15 () ;
V_28 [ V_3 ] . V_29 = F_16 ( V_25 | F_17 ( V_20 -> V_30 ) | V_31 ) ;
asm volatile("ptesync;isync" : : : "memory");
V_20 -> V_21 . V_32 = NULL ;
return V_3 ;
}
int F_18 ( struct V_33 * V_34 , struct V_19 * V_20 )
{
int V_3 ;
if ( F_19 () )
V_3 = F_14 ( V_20 ) ;
else
V_3 = F_11 ( V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_20 -> V_21 . V_11 = V_3 ;
#ifdef F_20
V_20 -> V_21 . V_35 = F_21 ( sizeof( V_36 ) , V_7 ) ;
if ( ! V_20 -> V_21 . V_35 ) {
F_22 ( V_3 ) ;
F_23 ( V_20 ) ;
V_20 -> V_21 . V_11 = V_37 ;
return - V_8 ;
}
F_24 ( V_20 -> V_21 . V_35 ) ;
#endif
#ifdef F_25
V_20 -> V_21 . V_38 = NULL ;
#endif
#ifdef F_26
F_27 ( V_20 ) ;
#endif
return 0 ;
}
void F_22 ( int V_39 )
{
F_3 ( & V_9 ) ;
F_6 ( & V_6 , V_39 ) ;
F_5 ( & V_9 ) ;
}
static void F_28 ( struct V_19 * V_20 )
{
int V_40 ;
void * V_38 ;
struct V_41 * V_41 ;
V_38 = V_20 -> V_21 . V_38 ;
if ( ! V_38 )
return;
V_41 = F_29 ( V_38 ) ;
V_40 = ( ( unsigned long ) V_38 & ~ V_42 ) >> V_43 ;
if ( F_30 ( V_41 , V_44 - V_40 ) ) {
F_31 ( V_41 ) ;
F_32 ( V_41 , 0 ) ;
}
}
static inline void F_28 ( struct V_19 * V_20 )
{
return;
}
void F_33 ( struct V_19 * V_20 )
{
#ifdef F_26
F_34 ( ! F_35 ( & V_20 -> V_21 . V_45 ) ) ;
#endif
#ifdef F_20
F_36 ( V_20 -> V_21 . V_46 , V_20 ) ;
F_37 ( V_20 -> V_21 . V_35 ) ;
V_20 -> V_21 . V_35 = NULL ;
#endif
if ( F_19 () ) {
V_28 [ V_20 -> V_21 . V_11 ] . V_29 = 0 ;
} else
F_23 ( V_20 ) ;
F_28 ( V_20 ) ;
F_22 ( V_20 -> V_21 . V_11 ) ;
V_20 -> V_21 . V_11 = V_37 ;
}
void F_38 ( struct V_19 * V_47 , struct V_19 * V_48 )
{
if ( F_39 ( V_49 ) ) {
F_40 () ;
F_41 ( V_50 , V_48 -> V_21 . V_11 ) ;
F_40 () ;
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
} else {
F_41 ( V_50 , V_48 -> V_21 . V_11 ) ;
F_40 () ;
}
}
