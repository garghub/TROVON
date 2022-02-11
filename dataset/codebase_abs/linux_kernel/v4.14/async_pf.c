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
int V_17 = 1 ;
F_14 () ;
F_15 ( & V_14 -> V_18 ) ;
F_16 ( NULL , V_14 , V_15 , 1 , V_19 , NULL , NULL ,
& V_17 ) ;
if ( V_17 )
F_17 ( & V_14 -> V_18 ) ;
F_1 ( V_2 , V_12 ) ;
F_18 ( & V_2 -> V_7 . V_10 ) ;
F_19 ( & V_12 -> V_20 , & V_2 -> V_7 . V_8 ) ;
V_12 -> V_2 = NULL ;
F_20 ( & V_2 -> V_7 . V_10 ) ;
F_21 ( V_15 , V_16 ) ;
if ( F_22 ( & V_2 -> V_21 ) )
F_23 ( & V_2 -> V_21 ) ;
F_24 ( V_14 ) ;
F_25 ( V_2 -> V_22 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_7 . V_10 ) ;
while ( ! F_27 ( & V_2 -> V_7 . V_9 ) ) {
struct V_3 * V_4 =
F_28 ( & V_2 -> V_7 . V_9 ,
F_29 ( * V_4 ) , V_9 ) ;
F_30 ( & V_4 -> V_9 ) ;
if ( ! V_4 -> V_2 )
continue;
F_20 ( & V_2 -> V_7 . V_10 ) ;
#ifdef F_2
F_31 ( & V_4 -> V_4 ) ;
#else
if ( F_32 ( & V_4 -> V_4 ) ) {
F_24 ( V_4 -> V_14 ) ;
F_25 ( V_2 -> V_22 ) ;
F_33 ( V_5 , V_4 ) ;
}
#endif
F_18 ( & V_2 -> V_7 . V_10 ) ;
}
while ( ! F_27 ( & V_2 -> V_7 . V_8 ) ) {
struct V_3 * V_4 =
F_28 ( & V_2 -> V_7 . V_8 ,
F_29 ( * V_4 ) , V_20 ) ;
F_30 ( & V_4 -> V_20 ) ;
F_33 ( V_5 , V_4 ) ;
}
F_20 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_23 = 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_35 ( & V_2 -> V_7 . V_8 ) &&
F_36 ( V_2 ) ) {
F_18 ( & V_2 -> V_7 . V_10 ) ;
V_4 = F_28 ( & V_2 -> V_7 . V_8 , F_29 ( * V_4 ) ,
V_20 ) ;
F_30 ( & V_4 -> V_20 ) ;
F_20 ( & V_2 -> V_7 . V_10 ) ;
F_37 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_4 ) ;
F_30 ( & V_4 -> V_9 ) ;
V_2 -> V_7 . V_23 -- ;
F_33 ( V_5 , V_4 ) ;
}
}
int F_38 ( struct V_1 * V_2 , T_1 V_16 , unsigned long V_24 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_7 . V_23 >= V_27 )
return 0 ;
V_4 = F_39 ( V_5 , V_28 | V_29 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_30 = false ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_15 = V_24 ;
V_4 -> V_26 = * V_26 ;
V_4 -> V_14 = V_31 -> V_14 ;
F_40 ( V_4 -> V_14 ) ;
F_41 ( V_4 -> V_2 -> V_22 ) ;
if ( F_42 ( F_43 ( V_4 -> V_15 ) ) )
goto V_32;
F_44 ( & V_4 -> V_4 , F_12 ) ;
if ( ! F_45 ( & V_4 -> V_4 ) )
goto V_32;
F_19 ( & V_4 -> V_9 , & V_2 -> V_7 . V_9 ) ;
V_2 -> V_7 . V_23 ++ ;
F_46 ( V_2 , V_4 ) ;
return 1 ;
V_32:
F_25 ( V_4 -> V_2 -> V_22 ) ;
F_24 ( V_4 -> V_14 ) ;
F_33 ( V_5 , V_4 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_35 ( & V_2 -> V_7 . V_8 ) )
return 0 ;
V_4 = F_39 ( V_5 , V_33 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_30 = true ;
F_10 ( & V_4 -> V_9 ) ;
F_18 ( & V_2 -> V_7 . V_10 ) ;
F_19 ( & V_4 -> V_20 , & V_2 -> V_7 . V_8 ) ;
F_20 ( & V_2 -> V_7 . V_10 ) ;
V_2 -> V_7 . V_23 ++ ;
return 0 ;
}
