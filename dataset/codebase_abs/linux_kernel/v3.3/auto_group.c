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
bool F_25 ( struct V_1 * V_13 , struct V_9 * V_4 )
{
if ( V_4 != & V_5 )
return false ;
if ( V_13 -> V_21 != & V_22 )
return false ;
if ( V_13 -> V_14 & V_23 )
return false ;
return true ;
}
static void
F_26 ( struct V_1 * V_13 , struct V_8 * V_10 )
{
struct V_8 * V_24 ;
struct V_1 * V_25 ;
unsigned long V_14 ;
F_27 ( ! F_15 ( V_13 , & V_14 ) ) ;
V_24 = V_13 -> signal -> V_8 ;
if ( V_24 == V_10 ) {
F_16 ( V_13 , & V_14 ) ;
return;
}
V_13 -> signal -> V_8 = F_12 ( V_10 ) ;
if ( ! F_28 ( V_26 ) )
goto V_27;
V_25 = V_13 ;
do {
F_29 ( V_25 ) ;
} while_each_thread(p, t) ;
void F_30 ( struct V_1 * V_13 )
{
F_26 ( V_13 , & V_3 ) ;
}
void F_31 ( struct V_28 * V_29 )
{
V_29 -> V_8 = F_14 ( V_30 ) ;
}
void F_32 ( struct V_28 * V_29 )
{
F_10 ( V_29 -> V_8 ) ;
}
static int T_1 F_33 ( char * V_31 )
{
V_26 = 0 ;
return 1 ;
}
int F_34 ( struct V_1 * V_13 , int * V_32 )
{
static unsigned long V_33 = V_34 ;
struct V_8 * V_10 ;
int V_35 ;
if ( * V_32 < - 20 || * V_32 > 19 )
return - V_36 ;
V_35 = F_35 ( V_30 , * V_32 ) ;
if ( V_35 )
return V_35 ;
if ( * V_32 < 0 && ! F_36 ( V_30 , * V_32 ) )
return - V_37 ;
if ( ! F_37 ( V_38 ) && F_38 ( V_39 , V_33 ) )
return - V_40 ;
V_33 = V_41 / 10 + V_39 ;
V_10 = F_14 ( V_13 ) ;
F_39 ( & V_10 -> V_7 ) ;
V_35 = F_40 ( V_10 -> V_4 , V_42 [ * V_32 + 20 ] ) ;
if ( ! V_35 )
V_10 -> V_32 = * V_32 ;
F_41 ( & V_10 -> V_7 ) ;
F_10 ( V_10 ) ;
return V_35 ;
}
void F_42 ( struct V_1 * V_13 , struct V_43 * V_44 )
{
struct V_8 * V_10 = F_14 ( V_13 ) ;
if ( ! F_43 ( V_10 -> V_4 ) )
goto V_27;
F_44 ( & V_10 -> V_7 ) ;
F_45 ( V_44 , L_4 , V_10 -> V_18 , V_10 -> V_32 ) ;
F_46 ( & V_10 -> V_7 ) ;
V_27:
F_10 ( V_10 ) ;
}
int F_47 ( struct V_9 * V_4 , char * V_45 , int V_46 )
{
if ( ! F_43 ( V_4 ) )
return 0 ;
return snprintf ( V_45 , V_46 , L_5 , L_6 , V_4 -> V_8 -> V_18 ) ;
}
