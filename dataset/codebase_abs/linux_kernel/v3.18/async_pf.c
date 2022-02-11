static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_2
F_3 ( V_2 , V_4 ) ;
#endif
}
static inline void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifndef F_2
F_3 ( V_2 , V_4 ) ;
#endif
}
int F_5 ( void )
{
V_5 = F_6 ( V_3 , 0 ) ;
if ( ! V_5 )
return - V_6 ;
return 0 ;
}
void F_7 ( void )
{
if ( V_5 )
F_8 ( V_5 ) ;
V_5 = NULL ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_7 . V_8 ) ;
F_10 ( & V_2 -> V_7 . V_9 ) ;
F_11 ( & V_2 -> V_7 . V_10 ) ;
}
static void F_12 ( struct V_11 * V_4 )
{
struct V_3 * V_12 =
F_13 ( V_4 , struct V_3 , V_4 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_15 = V_12 -> V_15 ;
T_1 V_16 = V_12 -> V_16 ;
F_14 () ;
F_15 ( NULL , V_14 , V_15 , 1 , NULL ) ;
F_1 ( V_2 , V_12 ) ;
F_16 ( & V_2 -> V_7 . V_10 ) ;
F_17 ( & V_12 -> V_17 , & V_2 -> V_7 . V_8 ) ;
F_18 ( & V_2 -> V_7 . V_10 ) ;
F_19 ( V_15 , V_16 ) ;
if ( F_20 ( & V_2 -> V_18 ) )
F_21 ( & V_2 -> V_18 ) ;
F_22 ( V_14 ) ;
F_23 ( V_2 -> V_19 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
while ( ! F_25 ( & V_2 -> V_7 . V_9 ) ) {
struct V_3 * V_4 =
F_26 ( V_2 -> V_7 . V_9 . V_20 ,
F_27 ( * V_4 ) , V_9 ) ;
F_28 ( & V_4 -> V_9 ) ;
#ifdef F_2
F_29 ( & V_4 -> V_4 ) ;
#else
if ( F_30 ( & V_4 -> V_4 ) ) {
F_22 ( V_4 -> V_14 ) ;
F_23 ( V_2 -> V_19 ) ;
F_31 ( V_5 , V_4 ) ;
}
#endif
}
F_16 ( & V_2 -> V_7 . V_10 ) ;
while ( ! F_25 ( & V_2 -> V_7 . V_8 ) ) {
struct V_3 * V_4 =
F_26 ( V_2 -> V_7 . V_8 . V_20 ,
F_27 ( * V_4 ) , V_17 ) ;
F_28 ( & V_4 -> V_17 ) ;
F_31 ( V_5 , V_4 ) ;
}
F_18 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_21 = 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_33 ( & V_2 -> V_7 . V_8 ) &&
F_34 ( V_2 ) ) {
F_16 ( & V_2 -> V_7 . V_10 ) ;
V_4 = F_35 ( & V_2 -> V_7 . V_8 , F_27 ( * V_4 ) ,
V_17 ) ;
F_28 ( & V_4 -> V_17 ) ;
F_18 ( & V_2 -> V_7 . V_10 ) ;
F_36 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_4 ) ;
F_28 ( & V_4 -> V_9 ) ;
V_2 -> V_7 . V_21 -- ;
F_31 ( V_5 , V_4 ) ;
}
}
int F_37 ( struct V_1 * V_2 , T_1 V_16 , unsigned long V_22 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_7 . V_21 >= V_25 )
return 0 ;
V_4 = F_38 ( V_5 , V_26 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_27 = false ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_15 = V_22 ;
V_4 -> V_24 = * V_24 ;
V_4 -> V_14 = V_28 -> V_14 ;
F_39 ( & V_4 -> V_14 -> V_29 ) ;
F_40 ( V_4 -> V_2 -> V_19 ) ;
if ( F_41 ( F_42 ( V_4 -> V_15 ) ) )
goto V_30;
F_43 ( & V_4 -> V_4 , F_12 ) ;
if ( ! F_44 ( & V_4 -> V_4 ) )
goto V_30;
F_17 ( & V_4 -> V_9 , & V_2 -> V_7 . V_9 ) ;
V_2 -> V_7 . V_21 ++ ;
F_45 ( V_2 , V_4 ) ;
return 1 ;
V_30:
F_23 ( V_4 -> V_2 -> V_19 ) ;
F_22 ( V_4 -> V_14 ) ;
F_31 ( V_5 , V_4 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_33 ( & V_2 -> V_7 . V_8 ) )
return 0 ;
V_4 = F_38 ( V_5 , V_31 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_27 = true ;
F_10 ( & V_4 -> V_9 ) ;
F_16 ( & V_2 -> V_7 . V_10 ) ;
F_17 ( & V_4 -> V_17 , & V_2 -> V_7 . V_8 ) ;
F_18 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_21 ++ ;
return 0 ;
}
