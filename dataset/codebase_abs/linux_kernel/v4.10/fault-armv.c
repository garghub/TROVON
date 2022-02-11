static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , T_1 * V_5 )
{
T_1 V_6 = * V_5 ;
int V_7 ;
V_7 = F_2 ( V_6 ) ;
if ( V_7 && ( F_3 ( V_6 ) & V_8 ) != V_9 ) {
F_4 ( V_2 , V_3 , V_4 ) ;
F_5 ( ( V_4 << V_10 ) ,
( V_4 << V_10 ) + V_11 ) ;
F_3 ( V_6 ) &= ~ V_8 ;
F_3 ( V_6 ) |= V_9 ;
F_6 ( V_2 -> V_12 , V_3 , V_5 , V_6 ) ;
F_7 ( V_2 , V_3 ) ;
}
return V_7 ;
}
static inline void F_8 ( T_2 * V_13 )
{
F_9 ( V_13 , V_14 ) ;
}
static inline void F_10 ( T_2 * V_13 )
{
F_11 ( V_13 ) ;
}
static inline void F_8 ( T_2 * V_13 ) {}
static inline void F_10 ( T_2 * V_13 ) {}
static int F_12 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
T_2 * V_13 ;
T_3 * V_15 ;
T_4 * V_16 ;
T_5 * V_17 ;
T_1 * V_18 ;
int V_7 ;
V_15 = F_13 ( V_2 -> V_12 , V_3 ) ;
if ( F_14 ( V_15 ) )
return 0 ;
V_16 = F_15 ( V_15 , V_3 ) ;
if ( F_16 ( V_16 ) )
return 0 ;
V_17 = F_17 ( V_16 , V_3 ) ;
if ( F_18 ( V_17 ) )
return 0 ;
V_13 = F_19 ( V_2 -> V_12 , V_17 ) ;
V_18 = F_20 ( V_17 , V_3 ) ;
F_8 ( V_13 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
F_10 ( V_13 ) ;
F_21 ( V_18 ) ;
return V_7 ;
}
static void
F_22 ( struct V_19 * V_20 , struct V_1 * V_2 ,
unsigned long V_21 , T_1 * V_5 , unsigned long V_4 )
{
struct V_22 * V_23 = V_2 -> V_12 ;
struct V_1 * V_24 ;
unsigned long V_25 ;
T_6 V_26 ;
int V_27 = 0 ;
V_26 = V_2 -> V_28 + ( ( V_21 - V_2 -> V_29 ) >> V_10 ) ;
F_23 ( V_20 ) ;
F_24 (mpnt, &mapping->i_mmap, pgoff, pgoff) {
if ( V_24 -> V_12 != V_23 || V_24 == V_2 )
continue;
if ( ! ( V_24 -> V_30 & V_31 ) )
continue;
V_25 = ( V_26 - V_24 -> V_28 ) << V_10 ;
V_27 += F_12 ( V_24 , V_24 -> V_29 + V_25 , V_4 ) ;
}
F_25 ( V_20 ) ;
if ( V_27 )
F_1 ( V_2 , V_21 , V_4 , V_5 ) ;
}
void F_26 ( struct V_1 * V_2 , unsigned long V_21 ,
T_1 * V_5 )
{
unsigned long V_4 = F_27 ( * V_5 ) ;
struct V_19 * V_20 ;
struct V_32 * V_32 ;
if ( ! F_28 ( V_4 ) )
return;
V_32 = F_29 ( V_4 ) ;
if ( V_32 == F_30 ( 0 ) )
return;
V_20 = F_31 ( V_32 ) ;
if ( ! F_32 ( V_33 , & V_32 -> V_34 ) )
F_33 ( V_20 , V_32 ) ;
if ( V_20 ) {
if ( F_34 () )
F_22 ( V_20 , V_2 , V_21 , V_5 , V_4 ) ;
else if ( V_2 -> V_30 & V_35 )
F_35 () ;
}
}
static int T_7 F_36 ( unsigned long * V_36 , unsigned long * V_37 )
{
register unsigned long V_38 = 0 , V_39 = 1 , V_40 ;
F_37 () ;
F_38 () ;
* V_36 = V_39 ;
F_38 () ;
* V_37 = V_38 ;
F_38 () ;
V_40 = * V_36 ;
F_38 () ;
F_39 () ;
return V_40 != V_38 ;
}
void T_7 F_40 ( void )
{
struct V_32 * V_32 ;
const char * V_41 ;
unsigned long V_42 = 1 ;
F_41 ( L_1 ) ;
V_32 = F_42 ( V_43 ) ;
if ( V_32 ) {
unsigned long * V_36 , * V_37 ;
T_8 V_44 = F_43 ( V_45 ,
V_8 , V_46 ) ;
V_36 = F_44 ( & V_32 , 1 , V_47 , V_44 ) ;
V_37 = F_44 ( & V_32 , 1 , V_47 , V_44 ) ;
if ( V_36 && V_37 ) {
V_42 = F_36 ( V_36 , V_37 ) ;
V_41 = L_2 ;
} else {
V_41 = L_3 ;
}
F_45 ( V_36 ) ;
F_45 ( V_37 ) ;
F_46 ( V_32 ) ;
} else {
V_41 = L_4 ;
}
if ( V_42 ) {
F_47 ( L_5 , V_41 ) ;
V_9 = V_48 ;
} else {
F_47 ( L_6 ) ;
}
}
