static void * F_1 ( int V_1 , T_1 * V_2 , unsigned long V_3 )
{
V_3 >>= V_4 ;
V_3 = ( V_3 << V_5 ) | V_1 ;
V_3 = ( V_3 << V_6 ) | V_2 -> V_7 ;
V_3 = ( V_3 << V_8 ) ;
return ( void * ) ( V_3 | V_9 ) ;
}
static void F_2 ( void * V_10 , int * V_11 , T_1 * * V_2 ,
unsigned long * V_12 )
{
unsigned long V_13 = ( unsigned long ) V_10 ;
int V_1 , V_14 ;
V_13 >>= V_8 ;
V_14 = V_13 & ( ( 1UL << V_6 ) - 1 ) ;
V_13 >>= V_6 ;
V_1 = V_13 & ( ( 1UL << V_5 ) - 1 ) ;
V_13 >>= V_5 ;
* V_11 = V_1 ;
* V_2 = F_3 ( V_14 ) ;
* V_12 = V_13 << V_4 ;
}
void * F_4 ( struct V_15 * V_16 , struct V_17 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_2 = F_6 ( V_17 ) ;
int V_1 = F_7 ( V_19 ) ;
unsigned long V_3 ;
struct V_21 * V_21 ;
F_8 ( F_9 ( V_17 ) , V_17 ) ;
F_8 ( F_10 ( V_17 ) , V_17 ) ;
F_8 ( ! F_11 ( V_17 ) , V_17 ) ;
V_21 = F_12 ( V_2 , V_19 ) ;
V_3 = F_13 ( & V_21 -> V_22 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
bool F_14 ( void * V_10 )
{
unsigned long V_23 ;
unsigned long V_24 ;
struct V_18 * V_19 ;
unsigned long V_3 ;
struct V_21 * V_21 ;
unsigned long V_25 ;
struct V_20 * V_2 ;
int V_1 ;
F_2 ( V_10 , & V_1 , & V_2 , & V_3 ) ;
F_15 () ;
V_19 = F_16 ( V_1 ) ;
if ( ! F_17 () && ! V_19 ) {
F_18 () ;
return false ;
}
V_21 = F_12 ( V_2 , V_19 ) ;
V_25 = F_19 ( & V_21 -> V_22 ) ;
V_24 = F_20 ( V_21 , V_26 ) ;
F_18 () ;
V_23 = ( V_25 - V_3 ) & V_27 ;
F_21 ( V_2 , V_28 ) ;
if ( V_23 <= V_24 ) {
F_21 ( V_2 , V_29 ) ;
return true ;
}
return false ;
}
void F_22 ( struct V_17 * V_17 )
{
struct V_18 * V_19 ;
struct V_21 * V_21 ;
F_15 () ;
V_19 = F_23 ( V_17 ) ;
if ( ! F_17 () && ! V_19 )
goto V_30;
V_21 = F_12 ( F_6 ( V_17 ) , V_19 ) ;
F_24 ( & V_21 -> V_22 ) ;
V_30:
F_18 () ;
}
static unsigned long F_25 ( struct V_31 * V_31 ,
struct V_32 * V_33 )
{
unsigned long V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
F_26 () ;
V_34 = F_27 ( & V_37 , V_33 ) ;
F_28 () ;
if ( F_29 () ) {
V_36 = F_30 ( V_33 -> V_19 , V_33 -> V_14 ,
V_38 ) ;
} else {
V_36 = F_31 ( F_3 ( V_33 -> V_14 ) , V_39 ) +
F_31 ( F_3 ( V_33 -> V_14 ) , V_40 ) ;
}
V_35 = V_36 >> ( 1 + V_41 - 3 ) ;
if ( V_34 <= V_35 )
return 0 ;
return V_34 - V_35 ;
}
static enum V_42 F_32 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_2 * V_47 ,
void * V_48 )
{
struct V_15 * V_16 ;
struct V_49 * V_50 ;
unsigned int V_51 ;
int V_52 ;
V_50 = F_33 ( V_44 , struct V_49 , V_53 ) ;
V_16 = V_50 -> V_54 ;
if ( ! F_34 ( & V_16 -> V_55 ) ) {
F_35 ( V_47 ) ;
V_52 = V_56 ;
goto V_30;
}
F_36 ( V_46 , V_44 ) ;
F_35 ( V_47 ) ;
F_37 ( ! F_38 ( V_50 ) ) ;
F_37 ( F_39 ( V_50 ) ) ;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
if ( V_50 -> V_58 [ V_51 ] ) {
F_37 ( ! F_40 ( V_50 -> V_58 [ V_51 ] ) ) ;
V_50 -> V_58 [ V_51 ] = NULL ;
F_41 ( V_50 ) ;
F_37 ( ! V_16 -> V_59 ) ;
V_16 -> V_59 -- ;
}
}
F_37 ( F_38 ( V_50 ) ) ;
F_21 ( F_6 ( F_42 ( V_50 ) ) , V_60 ) ;
if ( ! F_43 ( & V_16 -> V_61 , V_50 ) )
F_44 () ;
F_35 ( & V_16 -> V_55 ) ;
V_52 = V_62 ;
V_30:
F_28 () ;
F_45 () ;
F_26 () ;
F_46 ( V_47 ) ;
return V_52 ;
}
static unsigned long F_47 ( struct V_31 * V_31 ,
struct V_32 * V_33 )
{
unsigned long V_52 ;
F_26 () ;
V_52 = F_48 ( & V_37 , V_33 ,
F_32 , NULL ) ;
F_28 () ;
return V_52 ;
}
static int T_3 F_49 ( void )
{
unsigned int V_63 ;
unsigned int V_64 ;
int V_52 ;
F_50 ( V_65 < V_66 ) ;
V_63 = V_65 - V_66 ;
V_64 = F_51 ( V_67 - 1 ) ;
if ( V_64 > V_63 )
V_4 = V_64 - V_63 ;
F_52 ( L_1 ,
V_63 , V_64 , V_4 ) ;
V_52 = F_53 ( & V_37 , & V_68 ) ;
if ( V_52 )
goto V_69;
V_52 = F_54 ( & V_70 ) ;
if ( V_52 )
goto V_71;
return 0 ;
V_71:
F_55 ( & V_37 ) ;
V_69:
return V_52 ;
}
