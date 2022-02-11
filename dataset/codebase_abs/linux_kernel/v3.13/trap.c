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
unsigned int V_17 = V_18 | V_19 ;
* V_5 = V_20 ;
if ( F_2 () )
goto V_21;
if ( V_4 )
V_17 |= V_22 ;
V_23:
F_3 ( & V_7 -> V_24 ) ;
V_10 = F_4 ( V_7 , V_1 ) ;
if ( ! V_10 )
goto V_25;
else if ( V_10 -> V_26 <= V_1 )
goto V_27;
else if ( ! ( V_10 -> V_28 & V_29 ) )
goto V_25;
else if ( V_4 && ! F_5 ( V_1 ) )
goto V_25;
else if ( F_6 ( V_10 , V_1 ) )
goto V_25;
V_27:
* V_5 = V_30 ;
if ( V_3 ) {
if ( ! ( V_10 -> V_28 & V_31 ) )
goto V_25;
V_17 |= V_32 ;
} else {
if ( ! ( V_10 -> V_28 & ( V_33 | V_34 ) ) )
goto V_25;
}
do {
int V_35 ;
V_35 = F_7 ( V_7 , V_10 , V_1 , V_17 ) ;
if ( ( V_35 & V_36 ) && F_8 ( V_8 ) )
goto V_21;
if ( F_9 ( V_35 & V_37 ) ) {
if ( V_35 & V_38 ) {
goto V_39;
} else if ( V_35 & V_40 ) {
V_15 = - V_41 ;
goto V_25;
}
F_10 () ;
}
if ( V_17 & V_18 ) {
if ( V_35 & V_42 )
V_8 -> V_43 ++ ;
else
V_8 -> V_44 ++ ;
if ( V_35 & V_36 ) {
V_17 &= ~ V_18 ;
V_17 |= V_45 ;
goto V_23;
}
}
V_11 = F_11 ( V_7 , V_1 ) ;
V_12 = F_12 ( V_11 , V_1 ) ;
V_13 = F_13 ( V_12 , V_1 ) ;
V_14 = F_14 ( V_13 , V_1 ) ;
} while ( ! F_15 ( * V_14 ) );
V_15 = 0 ;
#if 0
WARN_ON(!pte_young(*pte) || (is_write && !pte_dirty(*pte)));
#endif
F_16 ( V_10 , V_1 ) ;
V_25:
F_17 ( & V_7 -> V_24 ) ;
V_21:
return V_15 ;
V_39:
F_17 ( & V_7 -> V_24 ) ;
if ( ! V_4 )
goto V_21;
F_18 () ;
return 0 ;
}
static void F_19 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_8 ;
struct V_50 * V_51 = F_20 ( V_47 ) ;
if ( ! F_21 ( V_49 , V_52 ) )
return;
if ( ! F_22 () )
return;
F_23 ( L_1 ,
F_24 ( V_49 ) > 1 ? V_53 : V_54 ,
V_49 -> V_55 , F_24 ( V_49 ) , F_25 ( * V_51 ) ,
( void * ) F_26 ( V_47 ) , ( void * ) F_27 ( V_47 ) ,
V_51 -> V_56 ) ;
F_28 ( V_57 L_2 , F_26 ( V_47 ) ) ;
F_23 ( V_57 L_3 ) ;
}
static void F_29 ( struct V_50 V_51 , unsigned long V_2 )
{
struct V_58 V_59 ;
V_59 . V_60 = V_52 ;
V_59 . V_61 = V_30 ;
V_59 . V_62 = ( void V_63 * ) F_25 ( V_51 ) ;
V_8 -> V_64 . V_65 . V_50 = V_51 ;
F_30 ( V_52 , & V_59 , V_8 ) ;
}
void F_31 ( void )
{
F_32 ( V_52 , V_8 ) ;
F_33 () ;
F_34 () ;
}
void F_35 ( int V_66 , struct V_58 * V_67 , struct V_46 * V_47 )
{
struct V_50 * V_51 = F_20 ( V_47 ) ;
if ( F_36 ( V_47 ) && ! F_37 ( V_51 ) ) {
F_19 ( V_47 ) ;
F_29 ( * V_51 , F_26 ( V_47 ) ) ;
return;
}
F_38 ( * V_51 , F_26 ( V_47 ) , F_36 ( V_47 ) , V_47 ) ;
}
unsigned long F_38 ( struct V_50 V_51 , unsigned long V_2 , int V_4 ,
struct V_46 * V_47 )
{
struct V_58 V_59 ;
T_5 * V_68 ;
int V_15 ;
int V_3 = F_39 ( V_51 ) ;
unsigned long V_1 = F_25 ( V_51 ) ;
if ( V_47 )
V_8 -> V_64 . V_69 = F_40 ( V_47 , struct V_70 , V_47 ) ;
if ( ! V_4 && ( V_1 >= V_71 ) && ( V_1 < V_72 ) ) {
F_41 () ;
goto V_25;
}
else if ( V_8 -> V_7 == NULL ) {
F_42 ( F_40 ( V_47 , struct V_70 , V_47 ) ) ;
F_43 ( L_4 ) ;
}
if ( F_37 ( & V_51 ) || F_44 ( & V_51 ) )
V_15 = F_1 ( V_1 , V_2 , V_3 , V_4 ,
& V_59 . V_61 ) ;
else {
V_15 = - V_16 ;
V_1 = 0 ;
}
V_68 = V_8 -> V_64 . V_73 ;
if ( ! V_15 )
goto V_25;
else if ( V_68 != NULL ) {
V_8 -> V_64 . V_74 = ( void * ) V_1 ;
F_45 ( V_68 , 1 ) ;
}
else if ( V_8 -> V_64 . V_74 != NULL )
F_43 ( L_5 ) ;
else if ( ! V_4 && F_46 ( V_2 , V_47 ) )
goto V_25;
if ( ! V_4 ) {
F_42 ( F_40 ( V_47 , struct V_70 , V_47 ) ) ;
F_43 ( L_6 ,
V_1 , V_2 ) ;
}
F_19 ( V_47 ) ;
if ( V_15 == - V_41 ) {
V_59 . V_60 = V_75 ;
V_59 . V_76 = 0 ;
V_59 . V_61 = V_77 ;
V_59 . V_62 = ( void V_63 * ) V_1 ;
V_8 -> V_64 . V_65 . V_50 = V_51 ;
F_30 ( V_75 , & V_59 , V_8 ) ;
} else {
F_47 ( V_15 != - V_16 ) ;
V_59 . V_60 = V_52 ;
V_59 . V_62 = ( void V_63 * ) V_1 ;
V_8 -> V_64 . V_65 . V_50 = V_51 ;
F_30 ( V_52 , & V_59 , V_8 ) ;
}
V_25:
if ( V_47 )
V_8 -> V_64 . V_69 = NULL ;
return 0 ;
}
void F_48 ( int V_66 , struct V_58 * V_59 , struct V_46 * V_47 )
{
struct V_50 * V_51 ;
struct V_58 V_78 ;
if ( ! F_36 ( V_47 ) ) {
if ( V_66 == V_75 )
F_23 ( V_79 L_7
L_8 ) ;
F_43 ( L_9 , V_66 ) ;
}
F_49 ( V_66 , V_47 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_60 = V_59 -> V_60 ;
V_78 . V_76 = V_59 -> V_76 ;
V_78 . V_61 = V_59 -> V_61 ;
switch ( V_66 ) {
case V_80 :
case V_81 :
case V_52 :
case V_75 :
case V_82 :
V_51 = F_20 ( V_47 ) ;
V_78 . V_62 = ( void V_63 * ) F_25 ( * V_51 ) ;
V_8 -> V_64 . V_65 . V_50 = * V_51 ;
#ifdef F_50
V_78 . V_83 = V_59 -> V_83 ;
#endif
break;
default:
F_23 ( V_79 L_10 ,
V_66 , V_59 -> V_61 ) ;
}
F_30 ( V_66 , & V_78 , V_8 ) ;
}
void F_51 ( int V_66 , struct V_58 * V_59 , struct V_46 * V_47 )
{
if ( V_8 -> V_64 . V_73 != NULL )
F_45 ( V_8 -> V_64 . V_73 , 1 ) ;
else
F_48 ( V_66 , V_59 , V_47 ) ;
}
void F_52 ( int V_66 , struct V_58 * V_67 , struct V_46 * V_47 )
{
F_53 ( V_84 , V_47 ) ;
}
void F_54 ( void )
{
}
