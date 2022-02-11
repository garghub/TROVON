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
V_35 = F_7 ( V_10 , V_1 , V_17 ) ;
if ( ( V_35 & V_36 ) && F_8 ( V_8 ) )
goto V_21;
if ( F_9 ( V_35 & V_37 ) ) {
if ( V_35 & V_38 ) {
goto V_39;
} else if ( V_35 & V_40 ) {
goto V_25;
} else if ( V_35 & V_41 ) {
V_15 = - V_42 ;
goto V_25;
}
F_10 () ;
}
if ( V_17 & V_18 ) {
if ( V_35 & V_43 )
V_8 -> V_44 ++ ;
else
V_8 -> V_45 ++ ;
if ( V_35 & V_36 ) {
V_17 &= ~ V_18 ;
V_17 |= V_46 ;
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
static void F_19 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_8 ;
struct V_51 * V_52 = F_20 ( V_48 ) ;
if ( ! F_21 ( V_50 , V_53 ) )
return;
if ( ! F_22 () )
return;
F_23 ( L_1 ,
F_24 ( V_50 ) > 1 ? V_54 : V_55 ,
V_50 -> V_56 , F_24 ( V_50 ) , F_25 ( * V_52 ) ,
( void * ) F_26 ( V_48 ) , ( void * ) F_27 ( V_48 ) ,
V_52 -> V_57 ) ;
F_28 ( V_58 L_2 , F_26 ( V_48 ) ) ;
F_23 ( V_58 L_3 ) ;
}
static void F_29 ( struct V_51 V_52 , unsigned long V_2 )
{
struct V_59 V_60 ;
V_60 . V_61 = V_53 ;
V_60 . V_62 = V_30 ;
V_60 . V_63 = ( void V_64 * ) F_25 ( V_52 ) ;
V_8 -> V_65 . V_66 . V_51 = V_52 ;
F_30 ( V_53 , & V_60 , V_8 ) ;
}
void F_31 ( void )
{
F_32 ( V_53 , V_8 ) ;
F_33 ( & V_8 -> V_65 . V_48 ) ;
F_34 () ;
}
void F_35 ( int V_67 , struct V_59 * V_68 , struct V_47 * V_48 )
{
struct V_51 * V_52 = F_20 ( V_48 ) ;
if ( F_36 ( V_48 ) && ! F_37 ( V_52 ) ) {
F_19 ( V_48 ) ;
F_29 ( * V_52 , F_26 ( V_48 ) ) ;
return;
}
F_38 ( * V_52 , F_26 ( V_48 ) , F_36 ( V_48 ) , V_48 ) ;
}
unsigned long F_38 ( struct V_51 V_52 , unsigned long V_2 , int V_4 ,
struct V_47 * V_48 )
{
struct V_59 V_60 ;
T_5 * V_69 ;
int V_15 ;
int V_3 = F_39 ( V_52 ) ;
unsigned long V_1 = F_25 ( V_52 ) ;
if ( ! V_4 && V_48 )
V_8 -> V_65 . V_70 = F_40 ( V_48 , struct V_71 , V_48 ) ;
if ( ! V_4 && ( V_1 >= V_72 ) && ( V_1 < V_73 ) ) {
F_41 () ;
goto V_25;
}
else if ( V_8 -> V_7 == NULL ) {
F_42 ( F_40 ( V_48 , struct V_71 , V_48 ) ) ;
F_43 ( L_4 ) ;
}
else if ( ! V_4 && V_1 > V_74 && V_1 < V_75 ) {
F_42 ( F_40 ( V_48 , struct V_71 , V_48 ) ) ;
F_43 ( L_5 ,
V_1 , V_2 ) ;
}
if ( F_37 ( & V_52 ) )
V_15 = F_1 ( V_1 , V_2 , V_3 , V_4 ,
& V_60 . V_62 ) ;
else {
V_15 = - V_16 ;
V_1 = 0 ;
}
V_69 = V_8 -> V_65 . V_76 ;
if ( ! V_15 )
goto V_25;
else if ( V_69 != NULL ) {
V_8 -> V_65 . V_77 = ( void * ) V_1 ;
F_44 ( V_69 , 1 ) ;
}
else if ( V_8 -> V_65 . V_77 != NULL )
F_43 ( L_6 ) ;
else if ( ! V_4 && F_45 ( V_2 , V_48 ) )
goto V_25;
if ( ! V_4 ) {
F_42 ( F_40 ( V_48 , struct V_71 , V_48 ) ) ;
F_43 ( L_7 ,
V_1 , V_2 ) ;
}
F_19 ( V_48 ) ;
if ( V_15 == - V_42 ) {
V_60 . V_61 = V_78 ;
V_60 . V_79 = 0 ;
V_60 . V_62 = V_80 ;
V_60 . V_63 = ( void V_64 * ) V_1 ;
V_8 -> V_65 . V_66 . V_51 = V_52 ;
F_30 ( V_78 , & V_60 , V_8 ) ;
} else {
F_46 ( V_15 != - V_16 ) ;
V_60 . V_61 = V_53 ;
V_60 . V_63 = ( void V_64 * ) V_1 ;
V_8 -> V_65 . V_66 . V_51 = V_52 ;
F_30 ( V_53 , & V_60 , V_8 ) ;
}
V_25:
if ( V_48 )
V_8 -> V_65 . V_70 = NULL ;
return 0 ;
}
void F_47 ( int V_67 , struct V_59 * V_60 , struct V_47 * V_48 )
{
struct V_51 * V_52 ;
struct V_59 V_81 ;
if ( ! F_36 ( V_48 ) ) {
if ( V_67 == V_78 )
F_23 ( V_82 L_8
L_9 ) ;
F_43 ( L_10 , V_67 ) ;
}
F_48 ( V_67 , V_48 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_61 = V_60 -> V_61 ;
V_81 . V_79 = V_60 -> V_79 ;
V_81 . V_62 = V_60 -> V_62 ;
switch ( V_67 ) {
case V_83 :
case V_84 :
case V_53 :
case V_78 :
case V_85 :
V_52 = F_20 ( V_48 ) ;
V_81 . V_63 = ( void V_64 * ) F_25 ( * V_52 ) ;
V_8 -> V_65 . V_66 . V_51 = * V_52 ;
#ifdef F_49
V_81 . V_86 = V_60 -> V_86 ;
#endif
break;
default:
F_23 ( V_82 L_11 ,
V_67 , V_60 -> V_62 ) ;
}
F_30 ( V_67 , & V_81 , V_8 ) ;
}
void F_50 ( int V_67 , struct V_59 * V_60 , struct V_47 * V_48 )
{
if ( V_8 -> V_65 . V_76 != NULL )
F_44 ( V_8 -> V_65 . V_76 , 1 ) ;
else
F_47 ( V_67 , V_60 , V_48 ) ;
}
void F_51 ( int V_67 , struct V_59 * V_68 , struct V_47 * V_48 )
{
F_52 ( V_87 , V_48 ) ;
}
void F_53 ( void )
{
}
