void T_1 F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 = & V_5 ;
F_2 ( & V_3 . V_6 ) ;
F_3 ( & V_3 . V_7 ) ;
V_2 -> signal -> V_8 = & V_3 ;
}
void F_4 ( struct V_9 * V_4 )
{
F_5 ( V_4 -> V_8 ) ;
}
static inline void F_6 ( struct V_6 * V_6 )
{
struct V_8 * V_10 = F_7 ( V_6 , struct V_8 , V_6 ) ;
#ifdef F_8
V_10 -> V_4 -> V_11 = NULL ;
V_10 -> V_4 -> V_12 = NULL ;
#endif
F_9 ( V_10 -> V_4 ) ;
F_10 ( V_10 -> V_4 ) ;
}
static inline void F_11 ( struct V_8 * V_10 )
{
F_12 ( & V_10 -> V_6 , F_6 ) ;
}
static inline struct V_8 * F_13 ( struct V_8 * V_10 )
{
F_14 ( & V_10 -> V_6 ) ;
return V_10 ;
}
static inline struct V_8 * F_15 ( struct V_1 * V_13 )
{
struct V_8 * V_10 ;
unsigned long V_14 ;
if ( ! F_16 ( V_13 , & V_14 ) )
return F_13 ( & V_3 ) ;
V_10 = F_13 ( V_13 -> signal -> V_8 ) ;
F_17 ( V_13 , & V_14 ) ;
return V_10 ;
}
static inline struct V_8 * F_18 ( void )
{
struct V_8 * V_10 = F_19 ( sizeof( * V_10 ) , V_15 ) ;
struct V_9 * V_4 ;
if ( ! V_10 )
goto V_16;
V_4 = F_20 ( & V_5 ) ;
if ( F_21 ( V_4 ) )
goto V_17;
F_2 ( & V_10 -> V_6 ) ;
F_3 ( & V_10 -> V_7 ) ;
V_10 -> V_18 = F_22 ( & V_19 ) ;
V_10 -> V_4 = V_4 ;
#ifdef F_8
F_23 ( V_4 ) ;
V_4 -> V_11 = V_5 . V_11 ;
V_4 -> V_12 = V_5 . V_12 ;
#endif
V_4 -> V_8 = V_10 ;
F_24 ( V_4 , & V_5 ) ;
return V_10 ;
V_17:
F_5 ( V_10 ) ;
V_16:
if ( F_25 () ) {
F_26 ( V_20 L_1 ,
V_10 ? L_2 : L_3 ) ;
}
return F_13 ( & V_3 ) ;
}
bool F_27 ( struct V_1 * V_13 , struct V_9 * V_4 )
{
if ( V_4 != & V_5 )
return false ;
if ( V_13 -> V_14 & V_21 )
return false ;
return true ;
}
static void
F_28 ( struct V_1 * V_13 , struct V_8 * V_10 )
{
struct V_8 * V_22 ;
struct V_1 * V_23 ;
unsigned long V_14 ;
F_29 ( ! F_16 ( V_13 , & V_14 ) ) ;
V_22 = V_13 -> signal -> V_8 ;
if ( V_22 == V_10 ) {
F_17 ( V_13 , & V_14 ) ;
return;
}
V_13 -> signal -> V_8 = F_13 ( V_10 ) ;
if ( ! F_30 ( V_24 ) )
goto V_25;
F_31 (p, t)
F_32 ( V_23 ) ;
V_25:
F_17 ( V_13 , & V_14 ) ;
F_11 ( V_22 ) ;
}
void F_33 ( struct V_1 * V_13 )
{
struct V_8 * V_10 = F_18 () ;
F_28 ( V_13 , V_10 ) ;
F_11 ( V_10 ) ;
}
void F_34 ( struct V_1 * V_13 )
{
F_28 ( V_13 , & V_3 ) ;
}
void F_35 ( struct V_26 * V_27 )
{
V_27 -> V_8 = F_15 ( V_28 ) ;
}
void F_36 ( struct V_26 * V_27 )
{
F_11 ( V_27 -> V_8 ) ;
}
static int T_1 F_37 ( char * V_29 )
{
V_24 = 0 ;
return 1 ;
}
int F_38 ( struct V_1 * V_13 , int V_30 )
{
static unsigned long V_31 = V_32 ;
struct V_8 * V_10 ;
int V_33 ;
if ( V_30 < V_34 || V_30 > V_35 )
return - V_36 ;
V_33 = F_39 ( V_28 , V_30 ) ;
if ( V_33 )
return V_33 ;
if ( V_30 < 0 && ! F_40 ( V_28 , V_30 ) )
return - V_37 ;
if ( ! F_41 ( V_38 ) && F_42 ( V_39 , V_31 ) )
return - V_40 ;
V_31 = V_41 / 10 + V_39 ;
V_10 = F_15 ( V_13 ) ;
F_43 ( & V_10 -> V_7 ) ;
V_33 = F_44 ( V_10 -> V_4 , V_42 [ V_30 + 20 ] ) ;
if ( ! V_33 )
V_10 -> V_30 = V_30 ;
F_45 ( & V_10 -> V_7 ) ;
F_11 ( V_10 ) ;
return V_33 ;
}
void F_46 ( struct V_1 * V_13 , struct V_43 * V_44 )
{
struct V_8 * V_10 = F_15 ( V_13 ) ;
if ( ! F_47 ( V_10 -> V_4 ) )
goto V_25;
F_48 ( & V_10 -> V_7 ) ;
F_49 ( V_44 , L_4 , V_10 -> V_18 , V_10 -> V_30 ) ;
F_50 ( & V_10 -> V_7 ) ;
V_25:
F_11 ( V_10 ) ;
}
int F_51 ( struct V_9 * V_4 , char * V_45 , int V_46 )
{
if ( ! F_47 ( V_4 ) )
return 0 ;
return snprintf ( V_45 , V_46 , L_5 , L_6 , V_4 -> V_8 -> V_18 ) ;
}
