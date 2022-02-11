static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 * V_5 = ( const T_1 * ) V_4 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( T_2 , V_4 -> V_8 , V_9 * V_10 ) ;
F_3 ( V_2 , L_1 , V_7 ) ;
F_4 () ;
F_5 ( V_2 , L_2 , V_11 , V_10 ,
V_12 , V_5 , V_7 , V_13 ) ;
F_6 () ;
}
static bool F_7 ( const struct V_3 * V_4 )
{
return V_4 -> V_14 != V_15 &&
V_4 -> V_14 < V_4 -> V_16 ;
}
static bool F_8 ( const struct V_3 * V_4 )
{
return V_4 -> V_16 != V_15 &&
V_4 -> V_14 >= V_4 -> V_16 ;
}
static bool F_9 ( struct V_3 * V_4 )
{
return ( F_7 ( V_4 ) && V_4 -> V_17 & V_18 ) &&
F_10 ( V_4 -> V_19 + V_20 ,
V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_22 ;
unsigned int V_23 = F_12 ( V_19 - V_4 -> V_19 ) ;
F_3 ( V_2 , L_3 ,
V_4 -> V_6 , V_4 -> V_8 ) ;
F_3 ( V_2 , L_4 ,
V_4 -> V_24 , V_4 -> V_25 , V_4 -> V_19 ,
V_23 / 1000 , V_23 % 1000 ) ;
F_1 ( V_2 , V_4 ) ;
F_3 ( V_2 , L_5 ) ;
for ( V_22 = 0 ; V_22 < V_4 -> V_26 ; V_22 ++ ) {
void * V_5 = ( void * ) V_4 -> V_27 [ V_22 ] ;
F_3 ( V_2 , L_6 , V_5 , V_5 ) ;
}
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_28 V_27 ;
V_27 . V_29 = V_4 -> V_26 ;
V_27 . V_30 = V_4 -> V_27 ;
F_14 ( L_7 ,
V_4 -> V_6 , V_4 -> V_8 ) ;
F_14 ( L_8 ,
V_4 -> V_24 , V_4 -> V_25 , V_4 -> V_19 ) ;
F_14 ( L_9 , V_4 -> V_16 ) ;
F_14 ( L_10 , V_4 -> V_14 ) ;
F_14 ( L_11 , V_4 -> V_17 ) ;
F_14 ( L_12 , V_4 -> V_31 ) ;
F_14 ( L_5 ) ;
F_15 ( & V_27 , 4 ) ;
}
static struct V_3 * F_16 ( unsigned long V_5 , int V_32 )
{
struct V_33 * V_34 = V_35 . V_33 ;
while ( V_34 ) {
struct V_3 * V_4 =
F_17 ( V_34 , struct V_3 , V_33 ) ;
if ( V_5 < V_4 -> V_6 )
V_34 = V_4 -> V_33 . V_36 ;
else if ( V_4 -> V_6 + V_4 -> V_8 <= V_5 )
V_34 = V_4 -> V_33 . V_37 ;
else if ( V_4 -> V_6 == V_5 || V_32 )
return V_4 ;
else {
F_18 ( L_13 ,
V_5 ) ;
F_13 ( V_4 ) ;
break;
}
}
return NULL ;
}
static int F_19 ( struct V_3 * V_4 )
{
return F_20 ( & V_4 -> V_38 ) ;
}
static void F_21 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_3 * V_4 =
F_22 ( V_40 , struct V_3 , V_40 ) ;
F_23 (area, tmp, &object->area_list, node) {
F_24 ( & V_44 -> V_45 ) ;
F_25 ( V_46 , V_44 ) ;
}
F_25 ( V_47 , V_4 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
if ( ! F_27 ( & V_4 -> V_38 ) )
return;
F_28 ( V_4 -> V_17 & V_18 ) ;
F_29 ( & V_4 -> V_40 , F_21 ) ;
}
static struct V_3 * F_30 ( unsigned long V_5 , int V_32 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
F_31 () ;
F_32 ( & V_48 , V_17 ) ;
V_4 = F_16 ( V_5 , V_32 ) ;
F_33 ( & V_48 , V_17 ) ;
if ( V_4 && ! F_19 ( V_4 ) )
V_4 = NULL ;
F_34 () ;
return V_4 ;
}
static struct V_3 * F_35 ( unsigned long V_5 , int V_32 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
F_36 ( & V_48 , V_17 ) ;
V_4 = F_16 ( V_5 , V_32 ) ;
if ( V_4 ) {
F_37 ( & V_4 -> V_33 , & V_35 ) ;
F_38 ( & V_4 -> V_49 ) ;
}
F_39 ( & V_48 , V_17 ) ;
return V_4 ;
}
static int F_40 ( unsigned long * V_27 )
{
struct V_28 V_28 ;
V_28 . V_50 = V_51 ;
V_28 . V_29 = 0 ;
V_28 . V_30 = V_27 ;
V_28 . V_52 = 2 ;
F_41 ( & V_28 ) ;
return V_28 . V_29 ;
}
static struct V_3 * F_42 ( unsigned long V_5 , T_2 V_8 ,
int V_16 , T_3 V_53 )
{
unsigned long V_17 ;
struct V_3 * V_4 , * V_54 ;
struct V_33 * * V_55 , * V_56 ;
V_4 = F_43 ( V_47 , F_44 ( V_53 ) ) ;
if ( ! V_4 ) {
F_45 ( L_14 ) ;
F_46 () ;
return NULL ;
}
F_47 ( & V_4 -> V_49 ) ;
F_47 ( & V_4 -> V_57 ) ;
F_48 ( & V_4 -> V_58 ) ;
F_49 ( & V_4 -> V_59 ) ;
F_50 ( & V_4 -> V_38 , 1 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_6 = V_5 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_60 = 0 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_14 = 0 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_31 = 0 ;
if ( F_51 () ) {
V_4 -> V_25 = 0 ;
strncpy ( V_4 -> V_24 , L_15 , sizeof( V_4 -> V_24 ) ) ;
} else if ( F_52 () ) {
V_4 -> V_25 = 0 ;
strncpy ( V_4 -> V_24 , L_16 , sizeof( V_4 -> V_24 ) ) ;
} else {
V_4 -> V_25 = V_61 -> V_25 ;
strncpy ( V_4 -> V_24 , V_61 -> V_24 , sizeof( V_4 -> V_24 ) ) ;
}
V_4 -> V_26 = F_40 ( V_4 -> V_27 ) ;
F_36 ( & V_48 , V_17 ) ;
V_62 = F_53 ( V_62 , V_5 ) ;
V_63 = F_54 ( V_63 , V_5 + V_8 ) ;
V_55 = & V_35 . V_33 ;
V_56 = NULL ;
while ( * V_55 ) {
V_56 = * V_55 ;
V_54 = F_17 ( V_56 , struct V_3 , V_33 ) ;
if ( V_5 + V_8 <= V_54 -> V_6 )
V_55 = & V_54 -> V_33 . V_36 ;
else if ( V_54 -> V_6 + V_54 -> V_8 <= V_5 )
V_55 = & V_54 -> V_33 . V_37 ;
else {
F_55 ( L_17 ,
V_5 ) ;
F_13 ( V_54 ) ;
F_25 ( V_47 , V_4 ) ;
V_4 = NULL ;
goto V_64;
}
}
F_56 ( & V_4 -> V_33 , V_56 , V_55 ) ;
F_57 ( & V_4 -> V_33 , & V_35 ) ;
F_58 ( & V_4 -> V_49 , & V_49 ) ;
V_64:
F_39 ( & V_48 , V_17 ) ;
return V_4 ;
}
static void F_59 ( struct V_3 * V_4 )
{
unsigned long V_17 ;
F_28 ( ! ( V_4 -> V_17 & V_18 ) ) ;
F_28 ( F_60 ( & V_4 -> V_38 ) < 1 ) ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_17 &= ~ V_18 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
static void F_63 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_18 ,
V_5 ) ;
#endif
return;
}
F_59 ( V_4 ) ;
}
static void F_65 ( unsigned long V_5 , T_2 V_8 )
{
struct V_3 * V_4 ;
unsigned long V_65 , V_66 ;
V_4 = F_35 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_19 ,
V_5 , V_8 ) ;
#endif
return;
}
V_65 = V_4 -> V_6 ;
V_66 = V_4 -> V_6 + V_4 -> V_8 ;
if ( V_5 > V_65 )
F_42 ( V_65 , V_5 - V_65 , V_4 -> V_16 ,
V_67 ) ;
if ( V_5 + V_8 < V_66 )
F_42 ( V_5 + V_8 , V_66 - V_5 - V_8 , V_4 -> V_16 ,
V_67 ) ;
F_59 ( V_4 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_68 )
{
V_4 -> V_16 = V_68 ;
if ( V_68 == V_15 )
V_4 -> V_17 |= V_69 ;
}
static void F_67 ( struct V_3 * V_4 , int V_68 )
{
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
F_66 ( V_4 , V_68 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_68 ( unsigned long V_5 , int V_68 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_20 ,
V_5 ,
( V_68 == V_70 ) ? L_21 :
( V_68 == V_15 ) ? L_22 : L_23 ) ;
return;
}
F_67 ( V_4 , V_68 ) ;
F_26 ( V_4 ) ;
}
static void F_69 ( unsigned long V_5 )
{
F_68 ( V_5 , V_70 ) ;
}
static void F_70 ( unsigned long V_5 )
{
F_68 ( V_5 , V_15 ) ;
}
static void F_71 ( unsigned long V_5 , T_2 V_8 , T_3 V_53 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
V_4 = F_30 ( V_5 , 1 ) ;
if ( ! V_4 ) {
F_18 ( L_24 ,
V_5 ) ;
return;
}
V_44 = F_43 ( V_46 , F_44 ( V_53 ) ) ;
if ( ! V_44 ) {
F_45 ( L_25 ) ;
goto V_64;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( V_8 == V_71 ) {
V_8 = V_4 -> V_6 + V_4 -> V_8 - V_5 ;
} else if ( V_5 + V_8 > V_4 -> V_6 + V_4 -> V_8 ) {
F_18 ( L_26 , V_5 ) ;
F_13 ( V_4 ) ;
F_25 ( V_46 , V_44 ) ;
goto V_72;
}
F_72 ( & V_44 -> V_45 ) ;
V_44 -> V_65 = V_5 ;
V_44 -> V_8 = V_8 ;
F_73 ( & V_44 -> V_45 , & V_4 -> V_58 ) ;
V_72:
F_62 ( & V_4 -> V_59 , V_17 ) ;
V_64:
F_26 ( V_4 ) ;
}
static void F_74 ( unsigned long V_5 , unsigned long V_60 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_27 ,
V_5 ) ;
return;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_60 = V_60 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
static void F_75 ( unsigned long V_5 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_28 , V_5 ) ;
return;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_17 |= V_69 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
static void T_4 F_76 ( int V_73 , const void * V_5 , T_2 V_8 ,
int V_16 )
{
unsigned long V_17 ;
struct V_74 * log ;
if ( V_75 ) {
V_76 ++ ;
return;
}
if ( V_76 >= F_77 ( V_74 ) ) {
V_76 ++ ;
F_46 () ;
return;
}
F_78 ( V_17 ) ;
log = & V_74 [ V_76 ] ;
log -> V_73 = V_73 ;
log -> V_5 = V_5 ;
log -> V_8 = V_8 ;
log -> V_16 = V_16 ;
log -> V_26 = F_40 ( log -> V_27 ) ;
V_76 ++ ;
F_79 ( V_17 ) ;
}
static void F_80 ( struct V_74 * log )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_22 ;
if ( ! V_77 || ! log -> V_5 || F_81 ( log -> V_5 ) )
return;
F_31 () ;
V_4 = F_42 ( ( unsigned long ) log -> V_5 , log -> V_8 ,
log -> V_16 , V_78 ) ;
if ( ! V_4 )
goto V_64;
F_61 ( & V_4 -> V_59 , V_17 ) ;
for ( V_22 = 0 ; V_22 < log -> V_26 ; V_22 ++ )
V_4 -> V_27 [ V_22 ] = log -> V_27 [ V_22 ] ;
V_4 -> V_26 = log -> V_26 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
V_64:
F_34 () ;
}
static void F_82 ( struct V_74 * log )
{
unsigned int V_79 ;
const void T_5 * V_5 = log -> V_5 ;
F_83 (cpu) {
log -> V_5 = F_84 ( V_5 , V_79 ) ;
F_80 ( log ) ;
}
}
void T_6 F_85 ( const void * V_5 , T_2 V_8 , int V_16 ,
T_3 V_53 )
{
F_86 ( L_29 , V_80 , V_5 , V_8 , V_16 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_42 ( ( unsigned long ) V_5 , V_8 , V_16 , V_53 ) ;
else if ( V_81 )
F_76 ( V_82 , V_5 , V_8 , V_16 ) ;
}
void T_6 F_87 ( const void T_5 * V_5 , T_2 V_8 ,
T_3 V_53 )
{
unsigned int V_79 ;
F_86 ( L_30 , V_80 , V_5 , V_8 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_83 (cpu)
F_42 ( ( unsigned long ) F_84 ( V_5 , V_79 ) ,
V_8 , 0 , V_53 ) ;
else if ( V_81 )
F_76 ( V_83 , V_5 , V_8 , 0 ) ;
}
void T_6 F_88 ( const struct V_84 * V_44 , T_2 V_8 , T_3 V_53 )
{
F_86 ( L_30 , V_80 , V_44 , V_8 ) ;
if ( V_77 ) {
F_42 ( ( unsigned long ) V_44 -> V_85 , V_8 , 2 , V_53 ) ;
F_74 ( ( unsigned long ) V_44 ,
( unsigned long ) V_44 -> V_85 ) ;
} else if ( V_81 ) {
F_76 ( V_82 , V_44 -> V_85 , V_8 , 2 ) ;
F_76 ( V_86 ,
V_44 , ( unsigned long ) V_44 -> V_85 , 0 ) ;
}
}
void T_6 F_89 ( const void * V_5 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_87 && V_5 && ! F_81 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 ) ;
else if ( V_81 )
F_76 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_6 F_90 ( const void * V_5 , T_2 V_8 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_65 ( ( unsigned long ) V_5 , V_8 ) ;
else if ( V_81 )
F_76 ( V_89 , V_5 , V_8 , 0 ) ;
}
void T_6 F_91 ( const void T_5 * V_5 )
{
unsigned int V_79 ;
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_87 && V_5 && ! F_81 ( V_5 ) )
F_83 (cpu)
F_63 ( ( unsigned long ) F_84 ( V_5 ,
V_79 ) ) ;
else if ( V_81 )
F_76 ( V_90 , V_5 , 0 , 0 ) ;
}
void T_6 F_92 ( const void * V_5 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_86 ( L_31 , V_80 , V_5 ) ;
if ( ! V_77 || F_93 ( V_5 ) )
return;
V_4 = F_30 ( ( unsigned long ) V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_32 ,
V_5 ) ;
#endif
return;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_26 = F_40 ( V_4 -> V_27 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
void T_6 F_94 ( const void * V_5 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 ) ;
else if ( V_81 )
F_76 ( V_91 , V_5 , 0 , 0 ) ;
}
void T_6 F_95 ( const void * V_5 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_70 ( ( unsigned long ) V_5 ) ;
else if ( V_81 )
F_76 ( V_92 , V_5 , 0 , 0 ) ;
}
void T_6 V_43 ( const void * V_5 , T_2 V_8 , T_3 V_53 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_77 && V_5 && V_8 && ! F_81 ( V_5 ) )
F_71 ( ( unsigned long ) V_5 , V_8 , V_53 ) ;
else if ( V_81 )
F_76 ( V_93 , V_5 , V_8 , 0 ) ;
}
void T_6 F_96 ( const void * V_5 )
{
F_86 ( L_31 , V_80 , V_5 ) ;
if ( V_77 && V_5 && ! F_81 ( V_5 ) )
F_75 ( ( unsigned long ) V_5 ) ;
else if ( V_81 )
F_76 ( V_94 , V_5 , 0 , 0 ) ;
}
void T_6 F_97 ( T_7 V_95 , T_2 V_8 , int V_16 ,
T_3 V_53 )
{
if ( ! F_98 ( V_96 ) || F_99 ( V_95 ) < V_97 )
F_85 ( F_100 ( V_95 ) , V_8 , V_16 , V_53 ) ;
}
void T_6 F_101 ( T_7 V_95 , T_2 V_8 )
{
if ( ! F_98 ( V_96 ) || F_99 ( V_95 ) < V_97 )
F_90 ( F_100 ( V_95 ) , V_8 ) ;
}
void T_6 F_102 ( T_7 V_95 )
{
if ( ! F_98 ( V_96 ) || F_99 ( V_95 ) < V_97 )
F_94 ( F_100 ( V_95 ) ) ;
}
void T_6 F_103 ( T_7 V_95 )
{
if ( ! F_98 ( V_96 ) || F_99 ( V_95 ) < V_97 )
F_95 ( F_100 ( V_95 ) ) ;
}
static bool F_104 ( struct V_3 * V_4 )
{
T_8 V_98 = V_4 -> V_31 ;
if ( ! F_105 ( V_4 -> V_6 , V_4 -> V_8 ) )
return false ;
F_4 () ;
V_4 -> V_31 = F_106 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_8 ) ;
F_6 () ;
return V_4 -> V_31 != V_98 ;
}
static void F_107 ( struct V_3 * V_4 )
{
if ( ! F_7 ( V_4 ) ) {
return;
}
V_4 -> V_14 ++ ;
if ( F_8 ( V_4 ) ) {
F_28 ( ! F_19 ( V_4 ) ) ;
F_108 ( & V_4 -> V_57 , & V_57 ) ;
}
}
static int F_109 ( void )
{
if ( ! V_77 )
return 1 ;
if ( V_61 -> V_99 )
return F_110 ( V_61 ) ;
else
return F_111 () ;
return 0 ;
}
static void F_112 ( void * V_100 , void * V_101 ,
struct V_3 * V_102 )
{
unsigned long * V_5 ;
unsigned long * V_65 = F_113 ( V_100 , V_103 ) ;
unsigned long * V_66 = V_101 - ( V_103 - 1 ) ;
unsigned long V_17 ;
F_32 ( & V_48 , V_17 ) ;
for ( V_5 = V_65 ; V_5 < V_66 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_6 ;
unsigned long V_60 ;
if ( F_109 () )
break;
if ( ! F_105 ( ( unsigned long ) V_5 ,
V_103 ) )
continue;
F_4 () ;
V_6 = * V_5 ;
F_6 () ;
if ( V_6 < V_62 || V_6 >= V_63 )
continue;
V_4 = F_16 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_102 )
continue;
F_114 ( & V_4 -> V_59 , V_104 ) ;
if ( F_8 ( V_4 ) ) {
V_60 = V_4 -> V_60 ;
} else {
V_60 = 0 ;
F_107 ( V_4 ) ;
}
F_115 ( & V_4 -> V_59 ) ;
if ( V_60 ) {
V_4 = F_16 ( V_60 , 0 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_102 )
continue;
F_114 ( & V_4 -> V_59 , V_104 ) ;
F_107 ( V_4 ) ;
F_115 ( & V_4 -> V_59 ) ;
}
}
F_33 ( & V_48 , V_17 ) ;
}
static void F_116 ( void * V_65 , void * V_66 )
{
void * V_105 ;
while ( V_65 < V_66 ) {
V_105 = F_53 ( V_65 + V_106 , V_66 ) ;
F_112 ( V_65 , V_105 , NULL ) ;
V_65 = V_105 ;
F_117 () ;
}
}
static void F_118 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( V_4 -> V_17 & V_69 )
goto V_64;
if ( ! ( V_4 -> V_17 & V_18 ) )
goto V_64;
if ( F_119 ( & V_4 -> V_58 ) ) {
void * V_65 = ( void * ) V_4 -> V_6 ;
void * V_66 = ( void * ) ( V_4 -> V_6 + V_4 -> V_8 ) ;
void * V_105 ;
do {
V_105 = F_53 ( V_65 + V_106 , V_66 ) ;
F_112 ( V_65 , V_105 , V_4 ) ;
V_65 = V_105 ;
if ( V_65 >= V_66 )
break;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_117 () ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
} while ( V_4 -> V_17 & V_18 );
} else
F_120 (area, &object->area_list, node)
F_112 ( ( void * ) V_44 -> V_65 ,
( void * ) ( V_44 -> V_65 + V_44 -> V_8 ) ,
V_4 ) ;
V_64:
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_121 ( void )
{
struct V_3 * V_4 , * V_42 ;
V_4 = F_122 ( V_57 . V_105 , F_123 ( * V_4 ) , V_57 ) ;
while ( & V_4 -> V_57 != & V_57 ) {
F_117 () ;
if ( ! F_109 () )
F_118 ( V_4 ) ;
V_42 = F_122 ( V_4 -> V_57 . V_105 , F_123 ( * V_4 ) ,
V_57 ) ;
F_124 ( & V_4 -> V_57 ) ;
F_26 ( V_4 ) ;
V_4 = V_42 ;
}
F_28 ( ! F_125 ( & V_57 ) ) ;
}
static void F_126 ( void )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
int V_22 ;
int V_107 = 0 ;
V_21 = V_19 ;
F_31 () ;
F_127 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
#ifdef F_64
if ( F_60 ( & V_4 -> V_38 ) > 1 ) {
F_86 ( L_33 ,
F_60 ( & V_4 -> V_38 ) ) ;
F_13 ( V_4 ) ;
}
#endif
V_4 -> V_14 = 0 ;
if ( F_8 ( V_4 ) && F_19 ( V_4 ) )
F_108 ( & V_4 -> V_57 , & V_57 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
F_116 ( V_108 , V_109 ) ;
F_116 ( V_110 , V_111 ) ;
F_116 ( V_112 , V_113 ) ;
#ifdef F_128
F_83 (i)
F_116 ( V_114 + F_129 ( V_22 ) ,
V_115 + F_129 ( V_22 ) ) ;
#endif
F_130 () ;
F_131 (i) {
unsigned long V_116 = F_132 ( V_22 ) ;
unsigned long V_117 = F_133 ( V_22 ) ;
unsigned long V_118 ;
for ( V_118 = V_116 ; V_118 < V_117 ; V_118 ++ ) {
struct V_119 * V_119 ;
if ( ! F_134 ( V_118 ) )
continue;
V_119 = F_135 ( V_118 ) ;
if ( F_136 ( V_119 ) == 0 )
continue;
F_112 ( V_119 , V_119 + 1 , NULL ) ;
}
}
F_137 () ;
if ( V_120 ) {
struct V_121 * V_122 , * V_123 ;
F_138 ( & V_124 ) ;
F_139 (g, p) {
void * V_125 = F_140 ( V_122 ) ;
if ( V_125 ) {
F_112 ( V_125 , V_125 + V_126 , NULL ) ;
F_141 ( V_122 ) ;
}
} F_142 ( V_123 , V_122 ) ;
F_143 ( & V_124 ) ;
}
F_121 () ;
F_31 () ;
F_127 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( F_7 ( V_4 ) && ( V_4 -> V_17 & V_18 )
&& F_104 ( V_4 ) && F_19 ( V_4 ) ) {
V_4 -> V_14 = V_4 -> V_16 ;
F_108 ( & V_4 -> V_57 , & V_57 ) ;
}
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
F_121 () ;
if ( F_109 () )
return;
F_31 () ;
F_127 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( F_9 ( V_4 ) &&
! ( V_4 -> V_17 & V_127 ) ) {
V_4 -> V_17 |= V_127 ;
V_107 ++ ;
}
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
if ( V_107 ) {
V_128 = true ;
F_144 ( L_34 ,
V_107 ) ;
}
}
static int F_145 ( void * V_129 )
{
static int V_130 = 1 ;
F_144 ( L_35 ) ;
F_146 ( V_61 , 10 ) ;
if ( V_130 ) {
signed long V_131 = F_147 ( V_132 * 1000 ) ;
V_130 = 0 ;
while ( V_131 && ! F_111 () )
V_131 = F_148 ( V_131 ) ;
}
while ( ! F_111 () ) {
signed long V_131 = V_133 ;
F_149 ( & V_134 ) ;
F_126 () ;
F_150 ( & V_134 ) ;
while ( V_131 && ! F_111 () )
V_131 = F_148 ( V_131 ) ;
}
F_144 ( L_36 ) ;
return 0 ;
}
static void F_151 ( void )
{
if ( V_135 )
return;
V_135 = F_152 ( F_145 , NULL , L_37 ) ;
if ( F_81 ( V_135 ) ) {
F_45 ( L_38 ) ;
V_135 = NULL ;
}
}
static void F_153 ( void )
{
if ( V_135 ) {
F_154 ( V_135 ) ;
V_135 = NULL ;
}
}
static void * F_155 ( struct V_1 * V_2 , T_9 * V_136 )
{
struct V_3 * V_4 ;
T_9 V_137 = * V_136 ;
int V_138 ;
V_138 = F_156 ( & V_134 ) ;
if ( V_138 < 0 )
return F_157 ( V_138 ) ;
F_31 () ;
F_127 (object, &object_list, object_list) {
if ( V_137 -- > 0 )
continue;
if ( F_19 ( V_4 ) )
goto V_64;
}
V_4 = NULL ;
V_64:
return V_4 ;
}
static void * F_158 ( struct V_1 * V_2 , void * V_139 , T_9 * V_136 )
{
struct V_3 * V_140 = V_139 ;
struct V_3 * V_141 = NULL ;
struct V_3 * V_142 = V_140 ;
++ ( * V_136 ) ;
F_159 (obj, &object_list, object_list) {
if ( F_19 ( V_142 ) ) {
V_141 = V_142 ;
break;
}
}
F_26 ( V_140 ) ;
return V_141 ;
}
static void F_160 ( struct V_1 * V_2 , void * V_139 )
{
if ( ! F_81 ( V_139 ) ) {
F_34 () ;
F_150 ( & V_134 ) ;
if ( V_139 )
F_26 ( V_139 ) ;
}
}
static int F_161 ( struct V_1 * V_2 , void * V_139 )
{
struct V_3 * V_4 = V_139 ;
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_127 ) && F_9 ( V_4 ) )
F_11 ( V_2 , V_4 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
return 0 ;
}
static int F_162 ( struct V_143 * V_143 , struct V_144 * V_144 )
{
return F_163 ( V_144 , & V_145 ) ;
}
static int F_164 ( const char * V_146 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
unsigned long V_85 ;
if ( F_165 ( V_146 , 0 , & V_85 ) )
return - V_147 ;
V_4 = F_30 ( V_85 , 0 ) ;
if ( ! V_4 ) {
F_144 ( L_39 , V_85 ) ;
return - V_147 ;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
F_13 ( V_4 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static void F_166 ( void )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_31 () ;
F_127 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_127 ) &&
F_9 ( V_4 ) )
F_66 ( V_4 , V_70 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
V_128 = false ;
}
static T_10 F_167 ( struct V_144 * V_144 , const char T_11 * V_148 ,
T_2 V_8 , T_9 * V_149 )
{
char V_150 [ 64 ] ;
int V_151 ;
int V_152 ;
V_151 = F_53 ( V_8 , ( sizeof( V_150 ) - 1 ) ) ;
if ( F_168 ( V_150 , V_148 , V_151 ) < 0 )
return - V_153 ;
V_150 [ V_151 ] = 0 ;
V_152 = F_156 ( & V_134 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( strncmp ( V_150 , L_40 , 5 ) == 0 ) {
if ( V_77 )
F_166 () ;
else
F_169 () ;
goto V_64;
}
if ( ! V_77 ) {
V_152 = - V_154 ;
goto V_64;
}
if ( strncmp ( V_150 , L_41 , 3 ) == 0 )
F_46 () ;
else if ( strncmp ( V_150 , L_42 , 8 ) == 0 )
V_120 = 1 ;
else if ( strncmp ( V_150 , L_43 , 9 ) == 0 )
V_120 = 0 ;
else if ( strncmp ( V_150 , L_44 , 7 ) == 0 )
F_151 () ;
else if ( strncmp ( V_150 , L_45 , 8 ) == 0 )
F_153 () ;
else if ( strncmp ( V_150 , L_46 , 5 ) == 0 ) {
unsigned long V_155 ;
V_152 = F_165 ( V_150 + 5 , 0 , & V_155 ) ;
if ( V_152 < 0 )
goto V_64;
F_153 () ;
if ( V_155 ) {
V_133 = F_147 ( V_155 * 1000 ) ;
F_151 () ;
}
} else if ( strncmp ( V_150 , L_47 , 4 ) == 0 )
F_126 () ;
else if ( strncmp ( V_150 , L_48 , 5 ) == 0 )
V_152 = F_164 ( V_150 + 5 ) ;
else
V_152 = - V_147 ;
V_64:
F_150 ( & V_134 ) ;
if ( V_152 < 0 )
return V_152 ;
* V_149 += V_8 ;
return V_8 ;
}
static void F_169 ( void )
{
struct V_3 * V_4 ;
F_31 () ;
F_127 (object, &object_list, object_list)
F_63 ( V_4 -> V_6 ) ;
F_34 () ;
}
static void F_170 ( struct V_156 * V_157 )
{
F_153 () ;
V_87 = 0 ;
if ( ! V_128 )
F_169 () ;
else
F_144 ( L_49 ) ;
}
static void F_46 ( void )
{
if ( F_171 ( & V_75 , 0 , 1 ) )
return;
V_77 = 0 ;
if ( V_158 )
F_172 ( & V_159 ) ;
else
V_87 = 0 ;
F_144 ( L_50 ) ;
}
static int F_173 ( char * V_146 )
{
if ( ! V_146 )
return - V_147 ;
if ( strcmp ( V_146 , L_41 ) == 0 )
F_46 () ;
else if ( strcmp ( V_146 , L_51 ) == 0 )
V_160 = 1 ;
else
return - V_147 ;
return 0 ;
}
static void T_4 F_174 ( struct V_74 * log )
{
struct V_28 V_27 ;
V_27 . V_29 = log -> V_26 ;
V_27 . V_30 = log -> V_27 ;
F_14 ( L_52 ) ;
F_15 ( & V_27 , 2 ) ;
}
void T_4 F_175 ( void )
{
int V_22 ;
unsigned long V_17 ;
#ifdef F_176
if ( ! V_160 ) {
V_81 = 0 ;
F_46 () ;
return;
}
#endif
V_20 = F_147 ( V_161 ) ;
V_133 = F_147 ( V_162 * 1000 ) ;
V_47 = F_177 ( V_3 , V_163 ) ;
V_46 = F_177 ( V_43 , V_163 ) ;
if ( V_76 > F_77 ( V_74 ) )
F_45 ( L_53 ,
V_76 ) ;
F_78 ( V_17 ) ;
V_81 = 0 ;
if ( V_75 ) {
F_79 ( V_17 ) ;
return;
} else {
V_77 = 1 ;
V_87 = 1 ;
}
F_79 ( V_17 ) ;
for ( V_22 = 0 ; V_22 < V_76 ; V_22 ++ ) {
struct V_74 * log = & V_74 [ V_22 ] ;
switch ( log -> V_73 ) {
case V_82 :
F_80 ( log ) ;
break;
case V_83 :
F_82 ( log ) ;
break;
case V_88 :
F_89 ( log -> V_5 ) ;
break;
case V_89 :
F_90 ( log -> V_5 , log -> V_8 ) ;
break;
case V_90 :
F_91 ( log -> V_5 ) ;
break;
case V_91 :
F_94 ( log -> V_5 ) ;
break;
case V_92 :
F_95 ( log -> V_5 ) ;
break;
case V_93 :
V_43 ( log -> V_5 , log -> V_8 , V_67 ) ;
break;
case V_94 :
F_96 ( log -> V_5 ) ;
break;
case V_86 :
F_74 ( ( unsigned long ) log -> V_5 ,
log -> V_60 ) ;
break;
default:
F_18 ( L_54 ,
log -> V_73 ) ;
}
if ( V_164 ) {
F_174 ( log ) ;
V_164 = 0 ;
}
}
}
static int T_4 F_178 ( void )
{
struct V_165 * V_165 ;
V_158 = 1 ;
if ( V_75 ) {
F_172 ( & V_159 ) ;
return - V_166 ;
}
V_165 = F_179 ( L_37 , V_167 , NULL , NULL ,
& V_168 ) ;
if ( ! V_165 )
F_45 ( L_55 ) ;
F_149 ( & V_134 ) ;
F_151 () ;
F_150 ( & V_134 ) ;
F_144 ( L_56 ) ;
return 0 ;
}
