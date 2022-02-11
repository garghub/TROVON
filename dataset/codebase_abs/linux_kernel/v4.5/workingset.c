static void * F_1 ( unsigned long V_1 , struct V_2 * V_2 )
{
V_1 = ( V_1 << V_3 ) | F_2 ( V_2 ) ;
V_1 = ( V_1 << V_4 ) | F_3 ( V_2 ) ;
V_1 = ( V_1 << V_5 ) ;
return ( void * ) ( V_1 | V_6 ) ;
}
static void F_4 ( void * V_7 ,
struct V_2 * * V_2 ,
unsigned long * V_8 )
{
unsigned long V_9 = ( unsigned long ) V_7 ;
unsigned long V_1 ;
unsigned long V_10 ;
unsigned long V_11 ;
int V_12 , V_13 ;
V_9 >>= V_5 ;
V_12 = V_9 & ( ( 1UL << V_4 ) - 1 ) ;
V_9 >>= V_4 ;
V_13 = V_9 & ( ( 1UL << V_3 ) - 1 ) ;
V_9 >>= V_3 ;
V_1 = V_9 ;
* V_2 = F_5 ( V_13 ) -> V_14 + V_12 ;
V_10 = F_6 ( & ( * V_2 ) -> V_15 ) ;
V_11 = ~ 0UL >> ( V_3 + V_4 +
V_5 ) ;
* V_8 = ( V_10 - V_1 ) & V_11 ;
}
void * F_7 ( struct V_16 * V_17 , struct V_18 * V_18 )
{
struct V_2 * V_2 = F_8 ( V_18 ) ;
unsigned long V_1 ;
V_1 = F_9 ( & V_2 -> V_15 ) ;
return F_1 ( V_1 , V_2 ) ;
}
bool F_10 ( void * V_7 )
{
unsigned long V_19 ;
struct V_2 * V_2 ;
F_4 ( V_7 , & V_2 , & V_19 ) ;
F_11 ( V_2 , V_20 ) ;
if ( V_19 <= F_12 ( V_2 , V_21 ) ) {
F_11 ( V_2 , V_22 ) ;
return true ;
}
return false ;
}
void F_13 ( struct V_18 * V_18 )
{
F_14 ( & F_8 ( V_18 ) -> V_15 ) ;
}
static unsigned long F_15 ( struct V_23 * V_23 ,
struct V_24 * V_25 )
{
unsigned long V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
F_16 () ;
V_26 = F_17 ( & V_29 , V_25 ) ;
F_18 () ;
V_28 = F_19 ( V_25 -> V_13 ) ;
V_27 = V_28 >> ( 1 + V_30 - 3 ) ;
if ( V_26 <= V_27 )
return 0 ;
return V_26 - V_27 ;
}
static enum V_31 F_20 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
T_1 * V_36 ,
void * V_37 )
{
struct V_16 * V_17 ;
struct V_38 * V_39 ;
unsigned int V_40 ;
int V_41 ;
V_39 = F_21 ( V_33 , struct V_38 , V_42 ) ;
V_17 = V_39 -> V_43 ;
if ( ! F_22 ( & V_17 -> V_44 ) ) {
F_23 ( V_36 ) ;
V_41 = V_45 ;
goto V_46;
}
F_24 ( V_35 , V_33 ) ;
F_23 ( V_36 ) ;
F_25 ( ! V_39 -> V_47 ) ;
F_25 ( V_39 -> V_47 & V_48 ) ;
for ( V_40 = 0 ; V_40 < V_49 ; V_40 ++ ) {
if ( V_39 -> V_50 [ V_40 ] ) {
F_25 ( ! F_26 ( V_39 -> V_50 [ V_40 ] ) ) ;
V_39 -> V_50 [ V_40 ] = NULL ;
F_25 ( V_39 -> V_47 < ( 1U << V_51 ) ) ;
V_39 -> V_47 -= 1U << V_51 ;
F_25 ( ! V_17 -> V_52 ) ;
V_17 -> V_52 -- ;
}
}
F_25 ( V_39 -> V_47 ) ;
F_11 ( F_8 ( F_27 ( V_39 ) ) , V_53 ) ;
if ( ! F_28 ( & V_17 -> V_54 , V_39 ) )
F_29 () ;
F_23 ( & V_17 -> V_44 ) ;
V_41 = V_55 ;
V_46:
F_18 () ;
F_30 () ;
F_16 () ;
F_31 ( V_36 ) ;
return V_41 ;
}
static unsigned long F_32 ( struct V_23 * V_23 ,
struct V_24 * V_25 )
{
unsigned long V_41 ;
F_16 () ;
V_41 = F_33 ( & V_29 , V_25 ,
F_20 , NULL ) ;
F_18 () ;
return V_41 ;
}
static int T_2 F_34 ( void )
{
int V_41 ;
V_41 = F_35 ( & V_29 , & V_56 ) ;
if ( V_41 )
goto V_57;
V_41 = F_36 ( & V_58 ) ;
if ( V_41 )
goto V_59;
return 0 ;
V_59:
F_37 ( & V_29 ) ;
V_57:
return V_41 ;
}
