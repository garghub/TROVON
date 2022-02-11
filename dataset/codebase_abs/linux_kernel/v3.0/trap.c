int F_1 ( unsigned long V_1 , unsigned long V_2 ,
int V_3 , int V_4 , int * V_5 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_9 * V_10 ;
T_1 * V_11 ;
T_2 * V_12 ;
T_3 * V_13 ;
T_4 * V_14 ;
int V_15 = - V_16 ;
* V_5 = V_17 ;
if ( F_2 () )
goto V_18;
F_3 ( & V_7 -> V_19 ) ;
V_10 = F_4 ( V_7 , V_1 ) ;
if ( ! V_10 )
goto V_20;
else if ( V_10 -> V_21 <= V_1 )
goto V_22;
else if ( ! ( V_10 -> V_23 & V_24 ) )
goto V_20;
else if ( V_4 && ! F_5 ( V_1 ) )
goto V_20;
else if ( F_6 ( V_10 , V_1 ) )
goto V_20;
V_22:
* V_5 = V_25 ;
if ( V_3 && ! ( V_10 -> V_23 & V_26 ) )
goto V_20;
if ( ! V_3 && ! ( V_10 -> V_23 & ( V_27 | V_28 ) ) )
goto V_20;
do {
int V_29 ;
V_29 = F_7 ( V_7 , V_10 , V_1 , V_3 ? V_30 : 0 ) ;
if ( F_8 ( V_29 & V_31 ) ) {
if ( V_29 & V_32 ) {
goto V_33;
} else if ( V_29 & V_34 ) {
V_15 = - V_35 ;
goto V_20;
}
F_9 () ;
}
if ( V_29 & V_36 )
V_8 -> V_37 ++ ;
else
V_8 -> V_38 ++ ;
V_11 = F_10 ( V_7 , V_1 ) ;
V_12 = F_11 ( V_11 , V_1 ) ;
V_13 = F_12 ( V_12 , V_1 ) ;
V_14 = F_13 ( V_13 , V_1 ) ;
} while ( ! F_14 ( * V_14 ) );
V_15 = 0 ;
#if 0
WARN_ON(!pte_young(*pte) || (is_write && !pte_dirty(*pte)));
#endif
F_15 ( V_10 , V_1 ) ;
V_20:
F_16 ( & V_7 -> V_19 ) ;
V_18:
return V_15 ;
V_33:
F_16 ( & V_7 -> V_19 ) ;
F_17 () ;
return 0 ;
}
static void F_18 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_8 ;
struct V_43 * V_44 = F_19 ( V_40 ) ;
if ( ! F_20 ( V_42 , V_45 ) )
return;
if ( ! F_21 () )
return;
F_22 ( L_1 ,
F_23 ( V_42 ) > 1 ? V_46 : V_47 ,
V_42 -> V_48 , F_23 ( V_42 ) , F_24 ( * V_44 ) ,
( void * ) F_25 ( V_40 ) , ( void * ) F_26 ( V_40 ) ,
V_44 -> V_49 ) ;
F_27 ( V_50 L_2 , F_25 ( V_40 ) ) ;
F_22 ( V_50 L_3 ) ;
}
static void F_28 ( struct V_43 V_44 , unsigned long V_2 )
{
struct V_51 V_52 ;
V_52 . V_53 = V_45 ;
V_52 . V_54 = V_25 ;
V_52 . V_55 = ( void V_56 * ) F_24 ( V_44 ) ;
V_8 -> V_57 . V_58 . V_43 = V_44 ;
F_29 ( V_45 , & V_52 , V_8 ) ;
}
void F_30 ( void )
{
F_31 ( V_45 , V_8 ) ;
F_32 () ;
F_33 () ;
}
void F_34 ( int V_59 , struct V_39 * V_40 )
{
struct V_43 * V_44 = F_19 ( V_40 ) ;
if ( F_35 ( V_40 ) && ! F_36 ( V_44 ) ) {
F_18 ( V_40 ) ;
F_28 ( * V_44 , F_25 ( V_40 ) ) ;
return;
}
F_37 ( * V_44 , F_25 ( V_40 ) , F_35 ( V_40 ) , V_40 ) ;
}
unsigned long F_37 ( struct V_43 V_44 , unsigned long V_2 , int V_4 ,
struct V_39 * V_40 )
{
struct V_51 V_52 ;
T_5 * V_60 ;
int V_15 ;
int V_3 = F_38 ( V_44 ) ;
unsigned long V_1 = F_24 ( V_44 ) ;
if ( ! V_4 && ( V_1 >= V_61 ) && ( V_1 < V_62 ) ) {
F_39 () ;
return 0 ;
}
else if ( V_8 -> V_7 == NULL ) {
F_40 ( F_41 ( V_40 , struct V_63 , V_40 ) ) ;
F_42 ( L_4 ) ;
}
if ( F_36 ( & V_44 ) || F_43 ( & V_44 ) )
V_15 = F_1 ( V_1 , V_2 , V_3 , V_4 ,
& V_52 . V_54 ) ;
else {
V_15 = - V_16 ;
V_1 = 0 ;
}
V_60 = V_8 -> V_57 . V_64 ;
if ( ! V_15 )
return 0 ;
else if ( V_60 != NULL ) {
V_8 -> V_57 . V_65 = ( void * ) V_1 ;
F_44 ( V_60 , 1 ) ;
}
else if ( V_8 -> V_57 . V_65 != NULL )
F_42 ( L_5 ) ;
else if ( ! V_4 && F_45 ( V_2 , V_40 ) )
return 0 ;
if ( ! V_4 ) {
F_40 ( F_41 ( V_40 , struct V_63 , V_40 ) ) ;
F_42 ( L_6 ,
V_1 , V_2 ) ;
}
F_18 ( V_40 ) ;
if ( V_15 == - V_35 ) {
V_52 . V_53 = V_66 ;
V_52 . V_67 = 0 ;
V_52 . V_54 = V_68 ;
V_52 . V_55 = ( void V_56 * ) V_1 ;
V_8 -> V_57 . V_58 . V_43 = V_44 ;
F_29 ( V_66 , & V_52 , V_8 ) ;
} else {
F_46 ( V_15 != - V_16 ) ;
V_52 . V_53 = V_45 ;
V_52 . V_55 = ( void V_56 * ) V_1 ;
V_8 -> V_57 . V_58 . V_43 = V_44 ;
F_29 ( V_45 , & V_52 , V_8 ) ;
}
return 0 ;
}
void F_47 ( int V_59 , struct V_39 * V_40 )
{
if ( ! F_35 ( V_40 ) ) {
if ( V_59 == V_66 )
F_22 ( V_69 L_7
L_8 ) ;
F_42 ( L_9 , V_59 ) ;
}
F_48 ( V_59 , V_40 ) ;
V_8 -> V_57 . V_58 . V_43 = * F_19 ( V_40 ) ;
F_49 ( V_59 , V_8 ) ;
}
void F_50 ( int V_59 , struct V_39 * V_40 )
{
if ( V_8 -> V_57 . V_64 != NULL )
F_44 ( V_8 -> V_57 . V_64 , 1 ) ;
else F_47 ( V_59 , V_40 ) ;
}
void F_51 ( int V_59 , struct V_39 * V_40 )
{
F_52 ( V_70 , V_40 ) ;
}
void F_53 ( void )
{
}
