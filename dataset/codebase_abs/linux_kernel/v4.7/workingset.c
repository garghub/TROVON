static void * F_1 ( int V_1 , struct V_2 * V_2 , unsigned long V_3 )
{
V_3 >>= V_4 ;
V_3 = ( V_3 << V_5 ) | V_1 ;
V_3 = ( V_3 << V_6 ) | F_2 ( V_2 ) ;
V_3 = ( V_3 << V_7 ) | F_3 ( V_2 ) ;
V_3 = ( V_3 << V_8 ) ;
return ( void * ) ( V_3 | V_9 ) ;
}
static void F_4 ( void * V_10 , int * V_11 , struct V_2 * * V_12 ,
unsigned long * V_13 )
{
unsigned long V_14 = ( unsigned long ) V_10 ;
int V_1 , V_15 , V_16 ;
V_14 >>= V_8 ;
V_16 = V_14 & ( ( 1UL << V_7 ) - 1 ) ;
V_14 >>= V_7 ;
V_15 = V_14 & ( ( 1UL << V_6 ) - 1 ) ;
V_14 >>= V_6 ;
V_1 = V_14 & ( ( 1UL << V_5 ) - 1 ) ;
V_14 >>= V_5 ;
* V_11 = V_1 ;
* V_12 = F_5 ( V_15 ) -> V_17 + V_16 ;
* V_13 = V_14 << V_4 ;
}
void * F_6 ( struct V_18 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_7 ( V_20 ) ;
struct V_2 * V_2 = F_8 ( V_20 ) ;
int V_1 = F_9 ( V_22 ) ;
unsigned long V_3 ;
struct V_23 * V_23 ;
F_10 ( F_11 ( V_20 ) , V_20 ) ;
F_10 ( F_12 ( V_20 ) , V_20 ) ;
F_10 ( ! F_13 ( V_20 ) , V_20 ) ;
V_23 = F_14 ( V_2 , V_22 ) ;
V_3 = F_15 ( & V_23 -> V_24 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
bool F_16 ( void * V_10 )
{
unsigned long V_25 ;
unsigned long V_26 ;
struct V_21 * V_22 ;
unsigned long V_3 ;
struct V_23 * V_23 ;
unsigned long V_27 ;
struct V_2 * V_2 ;
int V_1 ;
F_4 ( V_10 , & V_1 , & V_2 , & V_3 ) ;
F_17 () ;
V_22 = F_18 ( V_1 ) ;
if ( ! F_19 () && ! V_22 ) {
F_20 () ;
return false ;
}
V_23 = F_14 ( V_2 , V_22 ) ;
V_27 = F_21 ( & V_23 -> V_24 ) ;
V_26 = F_22 ( V_23 , V_28 ) ;
F_20 () ;
V_25 = ( V_27 - V_3 ) & V_29 ;
F_23 ( V_2 , V_30 ) ;
if ( V_25 <= V_26 ) {
F_23 ( V_2 , V_31 ) ;
return true ;
}
return false ;
}
void F_24 ( struct V_20 * V_20 )
{
struct V_23 * V_23 ;
F_25 ( V_20 ) ;
if ( ! F_19 () && ! F_7 ( V_20 ) )
goto V_32;
V_23 = F_14 ( F_8 ( V_20 ) , F_7 ( V_20 ) ) ;
F_26 ( & V_23 -> V_24 ) ;
V_32:
F_27 ( V_20 ) ;
}
static unsigned long F_28 ( struct V_33 * V_33 ,
struct V_34 * V_35 )
{
unsigned long V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
F_29 () ;
V_36 = F_30 ( & V_39 , V_35 ) ;
F_31 () ;
if ( F_32 () )
V_38 = F_33 ( V_35 -> V_22 , V_35 -> V_15 ,
V_40 ) ;
else
V_38 = F_34 ( V_35 -> V_15 , V_41 ) +
F_34 ( V_35 -> V_15 , V_42 ) ;
V_37 = V_38 >> ( 1 + V_43 - 3 ) ;
if ( V_36 <= V_37 )
return 0 ;
return V_36 - V_37 ;
}
static enum V_44 F_35 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
T_1 * V_49 ,
void * V_50 )
{
struct V_18 * V_19 ;
struct V_51 * V_52 ;
unsigned int V_53 ;
int V_54 ;
V_52 = F_36 ( V_46 , struct V_51 , V_55 ) ;
V_19 = V_52 -> V_56 ;
if ( ! F_37 ( & V_19 -> V_57 ) ) {
F_38 ( V_49 ) ;
V_54 = V_58 ;
goto V_32;
}
F_39 ( V_48 , V_46 ) ;
F_38 ( V_49 ) ;
F_40 ( ! V_52 -> V_59 ) ;
F_40 ( V_52 -> V_59 & V_60 ) ;
for ( V_53 = 0 ; V_53 < V_61 ; V_53 ++ ) {
if ( V_52 -> V_62 [ V_53 ] ) {
F_40 ( ! F_41 ( V_52 -> V_62 [ V_53 ] ) ) ;
V_52 -> V_62 [ V_53 ] = NULL ;
F_40 ( V_52 -> V_59 < ( 1U << V_63 ) ) ;
V_52 -> V_59 -= 1U << V_63 ;
F_40 ( ! V_19 -> V_64 ) ;
V_19 -> V_64 -- ;
}
}
F_40 ( V_52 -> V_59 ) ;
F_23 ( F_8 ( F_42 ( V_52 ) ) , V_65 ) ;
if ( ! F_43 ( & V_19 -> V_66 , V_52 ) )
F_44 () ;
F_38 ( & V_19 -> V_57 ) ;
V_54 = V_67 ;
V_32:
F_31 () ;
F_45 () ;
F_29 () ;
F_46 ( V_49 ) ;
return V_54 ;
}
static unsigned long F_47 ( struct V_33 * V_33 ,
struct V_34 * V_35 )
{
unsigned long V_54 ;
F_29 () ;
V_54 = F_48 ( & V_39 , V_35 ,
F_35 , NULL ) ;
F_31 () ;
return V_54 ;
}
static int T_2 F_49 ( void )
{
unsigned int V_68 ;
unsigned int V_69 ;
int V_54 ;
F_50 ( V_70 < V_71 ) ;
V_68 = V_70 - V_71 ;
V_69 = F_51 ( V_72 - 1 ) ;
if ( V_69 > V_68 )
V_4 = V_69 - V_68 ;
F_52 ( L_1 ,
V_68 , V_69 , V_4 ) ;
V_54 = F_53 ( & V_39 , & V_73 ) ;
if ( V_54 )
goto V_74;
V_54 = F_54 ( & V_75 ) ;
if ( V_54 )
goto V_76;
return 0 ;
V_76:
F_55 ( & V_39 ) ;
V_74:
return V_54 ;
}
