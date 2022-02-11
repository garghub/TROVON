static void T_1 F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 = & V_5 ;
F_2 ( & V_3 . V_6 ) ;
F_3 ( & V_3 . V_7 ) ;
V_2 -> signal -> V_8 = & V_3 ;
}
static inline void F_4 ( struct V_9 * V_4 )
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
}
static inline void F_10 ( struct V_8 * V_10 )
{
F_11 ( & V_10 -> V_6 , F_6 ) ;
}
static inline struct V_8 * F_12 ( struct V_8 * V_10 )
{
F_13 ( & V_10 -> V_6 ) ;
return V_10 ;
}
static inline struct V_8 * F_14 ( struct V_1 * V_13 )
{
struct V_8 * V_10 ;
unsigned long V_14 ;
if ( ! F_15 ( V_13 , & V_14 ) )
return F_12 ( & V_3 ) ;
V_10 = F_12 ( V_13 -> signal -> V_8 ) ;
F_16 ( V_13 , & V_14 ) ;
return V_10 ;
}
static inline struct V_8 * F_17 ( void )
{
struct V_8 * V_10 = F_18 ( sizeof( * V_10 ) , V_15 ) ;
struct V_9 * V_4 ;
if ( ! V_10 )
goto V_16;
V_4 = F_19 ( & V_5 ) ;
if ( F_20 ( V_4 ) )
goto V_17;
F_2 ( & V_10 -> V_6 ) ;
F_3 ( & V_10 -> V_7 ) ;
V_10 -> V_18 = F_21 ( & V_19 ) ;
V_10 -> V_4 = V_4 ;
#ifdef F_8
F_22 ( V_4 ) ;
V_4 -> V_11 = V_5 . V_11 ;
V_4 -> V_12 = V_5 . V_12 ;
#endif
V_4 -> V_8 = V_10 ;
return V_10 ;
V_17:
F_5 ( V_10 ) ;
V_16:
if ( F_23 () ) {
F_24 ( V_20 L_1 ,
V_10 ? L_2 : L_3 ) ;
}
return F_12 ( & V_3 ) ;
}
static inline bool
F_25 ( struct V_1 * V_13 , struct V_9 * V_4 )
{
if ( V_4 != & V_5 )
return false ;
if ( V_13 -> V_21 != & V_22 )
return false ;
if ( V_13 -> V_14 & V_23 )
return false ;
return true ;
}
static inline bool F_26 ( struct V_9 * V_4 )
{
return ! ! V_4 -> V_8 ;
}
static inline struct V_9 *
F_27 ( struct V_1 * V_13 , struct V_9 * V_4 )
{
int V_24 = F_28 ( V_25 ) ;
if ( V_24 && F_25 ( V_13 , V_4 ) )
return V_13 -> signal -> V_8 -> V_4 ;
return V_4 ;
}
static void
F_29 ( struct V_1 * V_13 , struct V_8 * V_10 )
{
struct V_8 * V_26 ;
struct V_1 * V_27 ;
unsigned long V_14 ;
F_30 ( ! F_15 ( V_13 , & V_14 ) ) ;
V_26 = V_13 -> signal -> V_8 ;
if ( V_26 == V_10 ) {
F_16 ( V_13 , & V_14 ) ;
return;
}
V_13 -> signal -> V_8 = F_12 ( V_10 ) ;
if ( ! F_28 ( V_25 ) )
goto V_28;
V_27 = V_13 ;
do {
F_31 ( V_27 ) ;
} while_each_thread(p, t) ;
void F_32 ( struct V_1 * V_13 )
{
F_29 ( V_13 , & V_3 ) ;
}
void F_33 ( struct V_29 * V_30 )
{
V_30 -> V_8 = F_14 ( V_31 ) ;
}
void F_34 ( struct V_29 * V_30 )
{
F_10 ( V_30 -> V_8 ) ;
}
static int T_1 F_35 ( char * V_32 )
{
V_25 = 0 ;
return 1 ;
}
int F_36 ( struct V_1 * V_13 , int * V_33 )
{
static unsigned long V_34 = V_35 ;
struct V_8 * V_10 ;
int V_36 ;
if ( * V_33 < - 20 || * V_33 > 19 )
return - V_37 ;
V_36 = F_37 ( V_31 , * V_33 ) ;
if ( V_36 )
return V_36 ;
if ( * V_33 < 0 && ! F_38 ( V_31 , * V_33 ) )
return - V_38 ;
if ( ! F_39 ( V_39 ) && F_40 ( V_40 , V_34 ) )
return - V_41 ;
V_34 = V_42 / 10 + V_40 ;
V_10 = F_14 ( V_13 ) ;
F_41 ( & V_10 -> V_7 ) ;
V_36 = F_42 ( V_10 -> V_4 , V_43 [ * V_33 + 20 ] ) ;
if ( ! V_36 )
V_10 -> V_33 = * V_33 ;
F_43 ( & V_10 -> V_7 ) ;
F_10 ( V_10 ) ;
return V_36 ;
}
void F_44 ( struct V_1 * V_13 , struct V_44 * V_45 )
{
struct V_8 * V_10 = F_14 ( V_13 ) ;
if ( ! F_26 ( V_10 -> V_4 ) )
goto V_28;
F_45 ( & V_10 -> V_7 ) ;
F_46 ( V_45 , L_4 , V_10 -> V_18 , V_10 -> V_33 ) ;
F_47 ( & V_10 -> V_7 ) ;
V_28:
F_10 ( V_10 ) ;
}
static inline int F_48 ( struct V_9 * V_4 , char * V_46 , int V_47 )
{
if ( ! F_26 ( V_4 ) )
return 0 ;
return snprintf ( V_46 , V_47 , L_5 , L_6 , V_4 -> V_8 -> V_18 ) ;
}
