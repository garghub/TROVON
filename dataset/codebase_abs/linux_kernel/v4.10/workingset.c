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
void F_25 ( struct V_31 * V_32 , void * V_33 )
{
struct V_15 * V_16 = V_33 ;
if ( F_26 ( V_16 ) || F_27 ( V_16 ) )
return;
if ( V_32 -> V_34 && V_32 -> V_34 == V_32 -> V_35 ) {
if ( F_28 ( & V_32 -> V_36 ) ) {
V_32 -> V_37 = V_16 ;
F_29 ( & V_38 , & V_32 -> V_36 ) ;
}
} else {
if ( ! F_28 ( & V_32 -> V_36 ) )
F_30 ( & V_38 , & V_32 -> V_36 ) ;
}
}
static unsigned long F_31 ( struct V_39 * V_39 ,
struct V_40 * V_41 )
{
unsigned long V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
F_32 () ;
V_43 = F_33 ( & V_38 , V_41 ) ;
F_34 () ;
if ( V_41 -> V_19 ) {
V_44 = F_35 ( V_41 -> V_19 , V_41 -> V_14 ,
V_45 ) ;
} else {
V_44 = F_36 ( F_3 ( V_41 -> V_14 ) , V_46 ) +
F_36 ( F_3 ( V_41 -> V_14 ) , V_47 ) ;
}
V_42 = V_44 >> ( V_48 - 3 ) ;
if ( V_43 <= V_42 )
return 0 ;
return V_43 - V_42 ;
}
static enum V_49 F_37 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
T_2 * V_54 ,
void * V_55 )
{
struct V_15 * V_16 ;
struct V_31 * V_32 ;
unsigned int V_56 ;
int V_57 ;
V_32 = F_38 ( V_51 , struct V_31 , V_36 ) ;
V_16 = V_32 -> V_37 ;
if ( ! F_39 ( & V_16 -> V_58 ) ) {
F_40 ( V_54 ) ;
V_57 = V_59 ;
goto V_30;
}
F_41 ( V_53 , V_51 ) ;
F_40 ( V_54 ) ;
if ( F_42 ( ! V_32 -> V_35 ) )
goto V_60;
if ( F_42 ( V_32 -> V_34 != V_32 -> V_35 ) )
goto V_60;
for ( V_56 = 0 ; V_56 < V_61 ; V_56 ++ ) {
if ( V_32 -> V_62 [ V_56 ] ) {
if ( F_42 ( ! F_43 ( V_32 -> V_62 [ V_56 ] ) ) )
goto V_60;
if ( F_42 ( ! V_32 -> V_35 ) )
goto V_60;
if ( F_42 ( ! V_16 -> V_63 ) )
goto V_60;
V_32 -> V_62 [ V_56 ] = NULL ;
V_32 -> V_35 -- ;
V_32 -> V_34 -- ;
V_16 -> V_63 -- ;
}
}
if ( F_42 ( V_32 -> V_35 ) )
goto V_60;
F_21 ( F_6 ( F_44 ( V_32 ) ) , V_64 ) ;
F_45 ( & V_16 -> V_65 , V_32 ,
F_25 , V_16 ) ;
V_60:
F_40 ( & V_16 -> V_58 ) ;
V_57 = V_66 ;
V_30:
F_34 () ;
F_46 () ;
F_32 () ;
F_47 ( V_54 ) ;
return V_57 ;
}
static unsigned long F_48 ( struct V_39 * V_39 ,
struct V_40 * V_41 )
{
unsigned long V_57 ;
F_32 () ;
V_57 = F_49 ( & V_38 , V_41 , F_37 , NULL ) ;
F_34 () ;
return V_57 ;
}
static int T_3 F_50 ( void )
{
unsigned int V_67 ;
unsigned int V_68 ;
int V_57 ;
F_51 ( V_69 < V_70 ) ;
V_67 = V_69 - V_70 ;
V_68 = F_52 ( V_71 - 1 ) ;
if ( V_68 > V_67 )
V_4 = V_68 - V_67 ;
F_53 ( L_1 ,
V_67 , V_68 , V_4 ) ;
V_57 = F_54 ( & V_38 , & V_72 ) ;
if ( V_57 )
goto V_73;
V_57 = F_55 ( & V_74 ) ;
if ( V_57 )
goto V_75;
return 0 ;
V_75:
F_56 ( & V_38 ) ;
V_73:
return V_57 ;
}
