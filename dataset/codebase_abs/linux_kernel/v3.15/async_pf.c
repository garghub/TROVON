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
F_15 ( V_14 ) ;
F_16 ( & V_14 -> V_17 ) ;
F_17 ( V_18 , V_14 , V_15 , 1 , 1 , 0 , NULL , NULL ) ;
F_18 ( & V_14 -> V_17 ) ;
F_1 ( V_2 , V_12 ) ;
F_19 ( V_14 ) ;
F_20 ( & V_2 -> V_7 . V_10 ) ;
F_21 ( & V_12 -> V_19 , & V_2 -> V_7 . V_8 ) ;
F_22 ( & V_2 -> V_7 . V_10 ) ;
F_23 ( V_15 , V_16 ) ;
if ( F_24 ( & V_2 -> V_20 ) )
F_25 ( & V_2 -> V_20 ) ;
F_26 ( V_14 ) ;
F_27 ( V_2 -> V_21 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
while ( ! F_29 ( & V_2 -> V_7 . V_9 ) ) {
struct V_3 * V_4 =
F_30 ( V_2 -> V_7 . V_9 . V_22 ,
F_31 ( * V_4 ) , V_9 ) ;
F_32 ( & V_4 -> V_9 ) ;
#ifdef F_2
F_33 ( & V_4 -> V_4 ) ;
#else
if ( F_34 ( & V_4 -> V_4 ) ) {
F_26 ( V_4 -> V_14 ) ;
F_27 ( V_2 -> V_21 ) ;
F_35 ( V_5 , V_4 ) ;
}
#endif
}
F_20 ( & V_2 -> V_7 . V_10 ) ;
while ( ! F_29 ( & V_2 -> V_7 . V_8 ) ) {
struct V_3 * V_4 =
F_30 ( V_2 -> V_7 . V_8 . V_22 ,
F_31 ( * V_4 ) , V_19 ) ;
F_32 ( & V_4 -> V_19 ) ;
F_35 ( V_5 , V_4 ) ;
}
F_22 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_23 = 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_37 ( & V_2 -> V_7 . V_8 ) &&
F_38 ( V_2 ) ) {
F_20 ( & V_2 -> V_7 . V_10 ) ;
V_4 = F_39 ( & V_2 -> V_7 . V_8 , F_31 ( * V_4 ) ,
V_19 ) ;
F_32 ( & V_4 -> V_19 ) ;
F_22 ( & V_2 -> V_7 . V_10 ) ;
F_40 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_4 ) ;
F_32 ( & V_4 -> V_9 ) ;
V_2 -> V_7 . V_23 -- ;
F_35 ( V_5 , V_4 ) ;
}
}
int F_41 ( struct V_1 * V_2 , T_1 V_16 , unsigned long V_24 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_7 . V_23 >= V_27 )
return 0 ;
V_4 = F_42 ( V_5 , V_28 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_29 = false ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_15 = V_24 ;
V_4 -> V_26 = * V_26 ;
V_4 -> V_14 = V_18 -> V_14 ;
F_43 ( & V_4 -> V_14 -> V_30 ) ;
F_44 ( V_4 -> V_2 -> V_21 ) ;
if ( F_45 ( F_46 ( V_4 -> V_15 ) ) )
goto V_31;
F_47 ( & V_4 -> V_4 , F_12 ) ;
if ( ! F_48 ( & V_4 -> V_4 ) )
goto V_31;
F_21 ( & V_4 -> V_9 , & V_2 -> V_7 . V_9 ) ;
V_2 -> V_7 . V_23 ++ ;
F_49 ( V_2 , V_4 ) ;
return 1 ;
V_31:
F_27 ( V_4 -> V_2 -> V_21 ) ;
F_26 ( V_4 -> V_14 ) ;
F_35 ( V_5 , V_4 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_37 ( & V_2 -> V_7 . V_8 ) )
return 0 ;
V_4 = F_42 ( V_5 , V_32 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_29 = true ;
F_10 ( & V_4 -> V_9 ) ;
F_20 ( & V_2 -> V_7 . V_10 ) ;
F_21 ( & V_4 -> V_19 , & V_2 -> V_7 . V_8 ) ;
F_22 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_23 ++ ;
return 0 ;
}
