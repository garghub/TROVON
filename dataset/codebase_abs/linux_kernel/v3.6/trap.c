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
unsigned int V_17 = V_18 | V_19 |
( V_3 ? V_20 : 0 ) ;
* V_5 = V_21 ;
if ( F_2 () )
goto V_22;
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
if ( V_3 && ! ( V_10 -> V_28 & V_31 ) )
goto V_25;
if ( ! V_3 && ! ( V_10 -> V_28 & ( V_32 | V_33 ) ) )
goto V_25;
do {
int V_34 ;
V_34 = F_7 ( V_7 , V_10 , V_1 , V_17 ) ;
if ( ( V_34 & V_35 ) && F_8 ( V_8 ) )
goto V_22;
if ( F_9 ( V_34 & V_36 ) ) {
if ( V_34 & V_37 ) {
goto V_38;
} else if ( V_34 & V_39 ) {
V_15 = - V_40 ;
goto V_25;
}
F_10 () ;
}
if ( V_17 & V_18 ) {
if ( V_34 & V_41 )
V_8 -> V_42 ++ ;
else
V_8 -> V_43 ++ ;
if ( V_34 & V_35 ) {
V_17 &= ~ V_18 ;
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
V_22:
return V_15 ;
V_38:
F_17 ( & V_7 -> V_24 ) ;
F_18 () ;
return 0 ;
}
static void F_19 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_8 ;
struct V_48 * V_49 = F_20 ( V_45 ) ;
if ( ! F_21 ( V_47 , V_50 ) )
return;
if ( ! F_22 () )
return;
F_23 ( L_1 ,
F_24 ( V_47 ) > 1 ? V_51 : V_52 ,
V_47 -> V_53 , F_24 ( V_47 ) , F_25 ( * V_49 ) ,
( void * ) F_26 ( V_45 ) , ( void * ) F_27 ( V_45 ) ,
V_49 -> V_54 ) ;
F_28 ( V_55 L_2 , F_26 ( V_45 ) ) ;
F_23 ( V_55 L_3 ) ;
}
static void F_29 ( struct V_48 V_49 , unsigned long V_2 )
{
struct V_56 V_57 ;
V_57 . V_58 = V_50 ;
V_57 . V_59 = V_30 ;
V_57 . V_60 = ( void V_61 * ) F_25 ( V_49 ) ;
V_8 -> V_62 . V_63 . V_48 = V_49 ;
F_30 ( V_50 , & V_57 , V_8 ) ;
}
void F_31 ( void )
{
F_32 ( V_50 , V_8 ) ;
F_33 () ;
F_34 () ;
}
void F_35 ( int V_64 , struct V_56 * V_65 , struct V_44 * V_45 )
{
struct V_48 * V_49 = F_20 ( V_45 ) ;
if ( F_36 ( V_45 ) && ! F_37 ( V_49 ) ) {
F_19 ( V_45 ) ;
F_29 ( * V_49 , F_26 ( V_45 ) ) ;
return;
}
F_38 ( * V_49 , F_26 ( V_45 ) , F_36 ( V_45 ) , V_45 ) ;
}
unsigned long F_38 ( struct V_48 V_49 , unsigned long V_2 , int V_4 ,
struct V_44 * V_45 )
{
struct V_56 V_57 ;
T_5 * V_66 ;
int V_15 ;
int V_3 = F_39 ( V_49 ) ;
unsigned long V_1 = F_25 ( V_49 ) ;
if ( ! V_4 && ( V_1 >= V_67 ) && ( V_1 < V_68 ) ) {
F_40 () ;
return 0 ;
}
else if ( V_8 -> V_7 == NULL ) {
F_41 ( F_42 ( V_45 , struct V_69 , V_45 ) ) ;
F_43 ( L_4 ) ;
}
if ( F_37 ( & V_49 ) || F_44 ( & V_49 ) )
V_15 = F_1 ( V_1 , V_2 , V_3 , V_4 ,
& V_57 . V_59 ) ;
else {
V_15 = - V_16 ;
V_1 = 0 ;
}
V_66 = V_8 -> V_62 . V_70 ;
if ( ! V_15 )
return 0 ;
else if ( V_66 != NULL ) {
V_8 -> V_62 . V_71 = ( void * ) V_1 ;
F_45 ( V_66 , 1 ) ;
}
else if ( V_8 -> V_62 . V_71 != NULL )
F_43 ( L_5 ) ;
else if ( ! V_4 && F_46 ( V_2 , V_45 ) )
return 0 ;
if ( ! V_4 ) {
F_41 ( F_42 ( V_45 , struct V_69 , V_45 ) ) ;
F_43 ( L_6 ,
V_1 , V_2 ) ;
}
F_19 ( V_45 ) ;
if ( V_15 == - V_40 ) {
V_57 . V_58 = V_72 ;
V_57 . V_73 = 0 ;
V_57 . V_59 = V_74 ;
V_57 . V_60 = ( void V_61 * ) V_1 ;
V_8 -> V_62 . V_63 . V_48 = V_49 ;
F_30 ( V_72 , & V_57 , V_8 ) ;
} else {
F_47 ( V_15 != - V_16 ) ;
V_57 . V_58 = V_50 ;
V_57 . V_60 = ( void V_61 * ) V_1 ;
V_8 -> V_62 . V_63 . V_48 = V_49 ;
F_30 ( V_50 , & V_57 , V_8 ) ;
}
return 0 ;
}
void F_48 ( int V_64 , struct V_56 * V_57 , struct V_44 * V_45 )
{
struct V_48 * V_49 ;
struct V_56 V_75 ;
if ( ! F_36 ( V_45 ) ) {
if ( V_64 == V_72 )
F_23 ( V_76 L_7
L_8 ) ;
F_43 ( L_9 , V_64 ) ;
}
F_49 ( V_64 , V_45 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_58 = V_57 -> V_58 ;
V_75 . V_73 = V_57 -> V_73 ;
V_75 . V_59 = V_57 -> V_59 ;
switch ( V_64 ) {
case V_77 :
case V_78 :
case V_50 :
case V_72 :
case V_79 :
V_49 = F_20 ( V_45 ) ;
V_75 . V_60 = ( void V_61 * ) F_25 ( * V_49 ) ;
V_8 -> V_62 . V_63 . V_48 = * V_49 ;
#ifdef F_50
V_75 . V_80 = V_57 -> V_80 ;
#endif
break;
default:
F_23 ( V_76 L_10 ,
V_64 , V_57 -> V_59 ) ;
}
F_30 ( V_64 , & V_75 , V_8 ) ;
}
void F_51 ( int V_64 , struct V_56 * V_57 , struct V_44 * V_45 )
{
if ( V_8 -> V_62 . V_70 != NULL )
F_45 ( V_8 -> V_62 . V_70 , 1 ) ;
else
F_48 ( V_64 , V_57 , V_45 ) ;
}
void F_52 ( int V_64 , struct V_56 * V_65 , struct V_44 * V_45 )
{
F_53 ( V_81 , V_45 ) ;
}
void F_54 ( void )
{
}
