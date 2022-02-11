static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 * V_5 = ( const T_1 * ) V_4 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( T_2 , V_4 -> V_8 , V_9 * V_10 ) ;
F_3 ( V_2 , L_1 , V_7 ) ;
F_4 ( V_2 , L_2 , V_11 , V_10 ,
V_12 , V_5 , V_7 , V_13 ) ;
}
static bool F_5 ( const struct V_3 * V_4 )
{
return V_4 -> V_14 != V_15 &&
V_4 -> V_14 < V_4 -> V_16 ;
}
static bool F_6 ( const struct V_3 * V_4 )
{
return V_4 -> V_16 != V_15 &&
V_4 -> V_14 >= V_4 -> V_16 ;
}
static bool F_7 ( struct V_3 * V_4 )
{
return ( F_5 ( V_4 ) && V_4 -> V_17 & V_18 ) &&
F_8 ( V_4 -> V_19 + V_20 ,
V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_22 ;
unsigned int V_23 = F_10 ( V_19 - V_4 -> V_19 ) ;
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
static void F_11 ( struct V_3 * V_4 )
{
struct V_28 V_27 ;
V_27 . V_29 = V_4 -> V_26 ;
V_27 . V_30 = V_4 -> V_27 ;
F_12 ( L_7 ,
V_4 -> V_6 , V_4 -> V_8 ) ;
F_12 ( L_8 ,
V_4 -> V_24 , V_4 -> V_25 , V_4 -> V_19 ) ;
F_12 ( L_9 , V_4 -> V_16 ) ;
F_12 ( L_10 , V_4 -> V_14 ) ;
F_12 ( L_11 , V_4 -> V_17 ) ;
F_12 ( L_12 , V_4 -> V_31 ) ;
F_12 ( L_5 ) ;
F_13 ( & V_27 , 4 ) ;
}
static struct V_3 * F_14 ( unsigned long V_5 , int V_32 )
{
struct V_33 * V_34 = V_35 . V_33 ;
while ( V_34 ) {
struct V_3 * V_4 =
F_15 ( V_34 , struct V_3 , V_33 ) ;
if ( V_5 < V_4 -> V_6 )
V_34 = V_4 -> V_33 . V_36 ;
else if ( V_4 -> V_6 + V_4 -> V_8 <= V_5 )
V_34 = V_4 -> V_33 . V_37 ;
else if ( V_4 -> V_6 == V_5 || V_32 )
return V_4 ;
else {
F_16 ( L_13 ,
V_5 ) ;
F_11 ( V_4 ) ;
break;
}
}
return NULL ;
}
static int F_17 ( struct V_3 * V_4 )
{
return F_18 ( & V_4 -> V_38 ) ;
}
static void F_19 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_3 * V_4 =
F_20 ( V_40 , struct V_3 , V_40 ) ;
F_21 (area, tmp, &object->area_list, node) {
F_22 ( & V_44 -> V_45 ) ;
F_23 ( V_46 , V_44 ) ;
}
F_23 ( V_47 , V_4 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( ! F_25 ( & V_4 -> V_38 ) )
return;
F_26 ( V_4 -> V_17 & V_18 ) ;
F_27 ( & V_4 -> V_40 , F_19 ) ;
}
static struct V_3 * F_28 ( unsigned long V_5 , int V_32 )
{
unsigned long V_17 ;
struct V_3 * V_4 = NULL ;
F_29 () ;
F_30 ( & V_48 , V_17 ) ;
V_4 = F_14 ( V_5 , V_32 ) ;
F_31 ( & V_48 , V_17 ) ;
if ( V_4 && ! F_17 ( V_4 ) )
V_4 = NULL ;
F_32 () ;
return V_4 ;
}
static struct V_3 * F_33 ( unsigned long V_5 , int V_32 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
F_34 ( & V_48 , V_17 ) ;
V_4 = F_14 ( V_5 , V_32 ) ;
if ( V_4 ) {
F_35 ( & V_4 -> V_33 , & V_35 ) ;
F_36 ( & V_4 -> V_49 ) ;
}
F_37 ( & V_48 , V_17 ) ;
return V_4 ;
}
static int F_38 ( unsigned long * V_27 )
{
struct V_28 V_28 ;
V_28 . V_50 = V_51 ;
V_28 . V_29 = 0 ;
V_28 . V_30 = V_27 ;
V_28 . V_52 = 2 ;
F_39 ( & V_28 ) ;
return V_28 . V_29 ;
}
static struct V_3 * F_40 ( unsigned long V_5 , T_2 V_8 ,
int V_16 , T_3 V_53 )
{
unsigned long V_17 ;
struct V_3 * V_4 , * V_54 ;
struct V_33 * * V_55 , * V_56 ;
V_4 = F_41 ( V_47 , F_42 ( V_53 ) ) ;
if ( ! V_4 ) {
F_43 ( L_14 ) ;
F_44 () ;
return NULL ;
}
F_45 ( & V_4 -> V_49 ) ;
F_45 ( & V_4 -> V_57 ) ;
F_46 ( & V_4 -> V_58 ) ;
F_47 ( & V_4 -> V_59 ) ;
F_48 ( & V_4 -> V_38 , 1 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_6 = V_5 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_14 = 0 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_31 = 0 ;
if ( F_49 () ) {
V_4 -> V_25 = 0 ;
strncpy ( V_4 -> V_24 , L_15 , sizeof( V_4 -> V_24 ) ) ;
} else if ( F_50 () ) {
V_4 -> V_25 = 0 ;
strncpy ( V_4 -> V_24 , L_16 , sizeof( V_4 -> V_24 ) ) ;
} else {
V_4 -> V_25 = V_60 -> V_25 ;
strncpy ( V_4 -> V_24 , V_60 -> V_24 , sizeof( V_4 -> V_24 ) ) ;
}
V_4 -> V_26 = F_38 ( V_4 -> V_27 ) ;
F_34 ( & V_48 , V_17 ) ;
V_61 = F_51 ( V_61 , V_5 ) ;
V_62 = F_52 ( V_62 , V_5 + V_8 ) ;
V_55 = & V_35 . V_33 ;
V_56 = NULL ;
while ( * V_55 ) {
V_56 = * V_55 ;
V_54 = F_15 ( V_56 , struct V_3 , V_33 ) ;
if ( V_5 + V_8 <= V_54 -> V_6 )
V_55 = & V_54 -> V_33 . V_36 ;
else if ( V_54 -> V_6 + V_54 -> V_8 <= V_5 )
V_55 = & V_54 -> V_33 . V_37 ;
else {
F_53 ( L_17
L_18 ,
V_5 ) ;
F_11 ( V_54 ) ;
F_23 ( V_47 , V_4 ) ;
V_4 = NULL ;
goto V_63;
}
}
F_54 ( & V_4 -> V_33 , V_56 , V_55 ) ;
F_55 ( & V_4 -> V_33 , & V_35 ) ;
F_56 ( & V_4 -> V_49 , & V_49 ) ;
V_63:
F_37 ( & V_48 , V_17 ) ;
return V_4 ;
}
static void F_57 ( struct V_3 * V_4 )
{
unsigned long V_17 ;
F_26 ( ! ( V_4 -> V_17 & V_18 ) ) ;
F_26 ( F_58 ( & V_4 -> V_38 ) < 1 ) ;
F_59 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_17 &= ~ V_18 ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
F_24 ( V_4 ) ;
}
static void F_61 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_62
F_16 ( L_19 ,
V_5 ) ;
#endif
return;
}
F_57 ( V_4 ) ;
}
static void F_63 ( unsigned long V_5 , T_2 V_8 )
{
struct V_3 * V_4 ;
unsigned long V_64 , V_65 ;
V_4 = F_33 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_62
F_16 ( L_20
L_21 , V_5 , V_8 ) ;
#endif
return;
}
V_64 = V_4 -> V_6 ;
V_65 = V_4 -> V_6 + V_4 -> V_8 ;
if ( V_5 > V_64 )
F_40 ( V_64 , V_5 - V_64 , V_4 -> V_16 ,
V_66 ) ;
if ( V_5 + V_8 < V_65 )
F_40 ( V_5 + V_8 , V_65 - V_5 - V_8 , V_4 -> V_16 ,
V_66 ) ;
F_57 ( V_4 ) ;
}
static void F_64 ( struct V_3 * V_4 , int V_67 )
{
V_4 -> V_16 = V_67 ;
if ( V_67 == V_15 )
V_4 -> V_17 |= V_68 ;
}
static void F_65 ( struct V_3 * V_4 , int V_67 )
{
unsigned long V_17 ;
F_59 ( & V_4 -> V_59 , V_17 ) ;
F_64 ( V_4 , V_67 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_66 ( unsigned long V_5 , int V_67 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_22
L_23 , V_5 ,
( V_67 == V_69 ) ? L_24 :
( V_67 == V_15 ) ? L_25 : L_26 ) ;
return;
}
F_65 ( V_4 , V_67 ) ;
F_24 ( V_4 ) ;
}
static void F_67 ( unsigned long V_5 )
{
F_66 ( V_5 , V_69 ) ;
}
static void F_68 ( unsigned long V_5 )
{
F_66 ( V_5 , V_15 ) ;
}
static void F_69 ( unsigned long V_5 , T_2 V_8 , T_3 V_53 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
V_4 = F_28 ( V_5 , 1 ) ;
if ( ! V_4 ) {
F_16 ( L_27 ,
V_5 ) ;
return;
}
V_44 = F_41 ( V_46 , F_42 ( V_53 ) ) ;
if ( ! V_44 ) {
F_43 ( L_28 ) ;
goto V_63;
}
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( V_8 == V_70 ) {
V_8 = V_4 -> V_6 + V_4 -> V_8 - V_5 ;
} else if ( V_5 + V_8 > V_4 -> V_6 + V_4 -> V_8 ) {
F_16 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_23 ( V_46 , V_44 ) ;
goto V_71;
}
F_70 ( & V_44 -> V_45 ) ;
V_44 -> V_64 = V_5 ;
V_44 -> V_8 = V_8 ;
F_71 ( & V_44 -> V_45 , & V_4 -> V_58 ) ;
V_71:
F_60 ( & V_4 -> V_59 , V_17 ) ;
V_63:
F_24 ( V_4 ) ;
}
static void F_72 ( unsigned long V_5 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_30 , V_5 ) ;
return;
}
F_59 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_17 |= V_68 ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
F_24 ( V_4 ) ;
}
static void T_4 F_73 ( int V_72 , const void * V_5 , T_2 V_8 ,
int V_16 )
{
unsigned long V_17 ;
struct V_73 * log ;
if ( V_74 ) {
V_75 ++ ;
return;
}
if ( V_75 >= F_74 ( V_73 ) ) {
V_75 ++ ;
F_44 () ;
return;
}
F_75 ( V_17 ) ;
log = & V_73 [ V_75 ] ;
log -> V_72 = V_72 ;
log -> V_5 = V_5 ;
log -> V_8 = V_8 ;
log -> V_16 = V_16 ;
log -> V_26 = F_38 ( log -> V_27 ) ;
V_75 ++ ;
F_76 ( V_17 ) ;
}
static void F_77 ( struct V_73 * log )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_22 ;
if ( ! V_76 || ! log -> V_5 || F_78 ( log -> V_5 ) )
return;
F_29 () ;
V_4 = F_40 ( ( unsigned long ) log -> V_5 , log -> V_8 ,
log -> V_16 , V_77 ) ;
if ( ! V_4 )
goto V_63;
F_59 ( & V_4 -> V_59 , V_17 ) ;
for ( V_22 = 0 ; V_22 < log -> V_26 ; V_22 ++ )
V_4 -> V_27 [ V_22 ] = log -> V_27 [ V_22 ] ;
V_4 -> V_26 = log -> V_26 ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
V_63:
F_32 () ;
}
static void F_79 ( struct V_73 * log )
{
unsigned int V_78 ;
const void T_5 * V_5 = log -> V_5 ;
F_80 (cpu) {
log -> V_5 = F_81 ( V_5 , V_78 ) ;
F_77 ( log ) ;
}
}
void T_6 F_82 ( const void * V_5 , T_2 V_8 , int V_16 ,
T_3 V_53 )
{
F_83 ( L_31 , V_79 , V_5 , V_8 , V_16 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_40 ( ( unsigned long ) V_5 , V_8 , V_16 , V_53 ) ;
else if ( V_80 )
F_73 ( V_81 , V_5 , V_8 , V_16 ) ;
}
void T_6 F_84 ( const void T_5 * V_5 , T_2 V_8 ,
T_3 V_53 )
{
unsigned int V_78 ;
F_83 ( L_32 , V_79 , V_5 , V_8 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_40 ( ( unsigned long ) F_81 ( V_5 , V_78 ) ,
V_8 , 0 , V_53 ) ;
else if ( V_80 )
F_73 ( V_82 , V_5 , V_8 , 0 ) ;
}
void T_6 F_85 ( const void * V_5 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_83 && V_5 && ! F_78 ( V_5 ) )
F_61 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_73 ( V_84 , V_5 , 0 , 0 ) ;
}
void T_6 F_86 ( const void * V_5 , T_2 V_8 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 , V_8 ) ;
else if ( V_80 )
F_73 ( V_85 , V_5 , V_8 , 0 ) ;
}
void T_6 F_87 ( const void T_5 * V_5 )
{
unsigned int V_78 ;
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_83 && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_61 ( ( unsigned long ) F_81 ( V_5 ,
V_78 ) ) ;
else if ( V_80 )
F_73 ( V_86 , V_5 , 0 , 0 ) ;
}
void T_6 F_88 ( const void * V_5 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_83 ( L_33 , V_79 , V_5 ) ;
if ( ! V_76 || F_89 ( V_5 ) )
return;
V_4 = F_28 ( ( unsigned long ) V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_62
F_16 ( L_34 ,
V_5 ) ;
#endif
return;
}
F_59 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_26 = F_38 ( V_4 -> V_27 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
F_24 ( V_4 ) ;
}
void T_6 F_90 ( const void * V_5 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_67 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_73 ( V_87 , V_5 , 0 , 0 ) ;
}
void T_6 F_91 ( const void * V_5 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_68 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_73 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_6 V_43 ( const void * V_5 , T_2 V_8 , T_3 V_53 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_76 && V_5 && V_8 && ! F_78 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 , V_8 , V_53 ) ;
else if ( V_80 )
F_73 ( V_89 , V_5 , V_8 , 0 ) ;
}
void T_6 F_92 ( const void * V_5 )
{
F_83 ( L_33 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_78 ( V_5 ) )
F_72 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_73 ( V_90 , V_5 , 0 , 0 ) ;
}
static bool F_93 ( struct V_3 * V_4 )
{
T_7 V_91 = V_4 -> V_31 ;
if ( ! F_94 ( V_4 -> V_6 , V_4 -> V_8 ) )
return false ;
F_95 () ;
V_4 -> V_31 = F_96 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_8 ) ;
F_97 () ;
return V_4 -> V_31 != V_91 ;
}
static int F_98 ( void )
{
if ( ! V_76 )
return 1 ;
if ( V_60 -> V_92 )
return F_99 ( V_60 ) ;
else
return F_100 () ;
return 0 ;
}
static void F_101 ( void * V_93 , void * V_94 ,
struct V_3 * V_95 )
{
unsigned long * V_5 ;
unsigned long * V_64 = F_102 ( V_93 , V_96 ) ;
unsigned long * V_65 = V_94 - ( V_96 - 1 ) ;
unsigned long V_17 ;
F_30 ( & V_48 , V_17 ) ;
for ( V_5 = V_64 ; V_5 < V_65 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_6 ;
if ( F_98 () )
break;
if ( ! F_94 ( ( unsigned long ) V_5 ,
V_96 ) )
continue;
F_95 () ;
V_6 = * V_5 ;
F_97 () ;
if ( V_6 < V_61 || V_6 >= V_62 )
continue;
V_4 = F_14 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_95 )
continue;
F_103 ( & V_4 -> V_59 , V_97 ) ;
if ( ! F_5 ( V_4 ) ) {
F_104 ( & V_4 -> V_59 ) ;
continue;
}
V_4 -> V_14 ++ ;
if ( F_6 ( V_4 ) ) {
F_26 ( ! F_17 ( V_4 ) ) ;
F_105 ( & V_4 -> V_57 , & V_57 ) ;
}
F_104 ( & V_4 -> V_59 ) ;
}
F_31 ( & V_48 , V_17 ) ;
}
static void F_106 ( void * V_64 , void * V_65 )
{
void * V_98 ;
while ( V_64 < V_65 ) {
V_98 = F_51 ( V_64 + V_99 , V_65 ) ;
F_101 ( V_64 , V_98 , NULL ) ;
V_64 = V_98 ;
F_107 () ;
}
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
unsigned long V_17 ;
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( V_4 -> V_17 & V_68 )
goto V_63;
if ( ! ( V_4 -> V_17 & V_18 ) )
goto V_63;
if ( F_109 ( & V_4 -> V_58 ) ) {
void * V_64 = ( void * ) V_4 -> V_6 ;
void * V_65 = ( void * ) ( V_4 -> V_6 + V_4 -> V_8 ) ;
void * V_98 ;
do {
V_98 = F_51 ( V_64 + V_99 , V_65 ) ;
F_101 ( V_64 , V_98 , V_4 ) ;
V_64 = V_98 ;
if ( V_64 >= V_65 )
break;
F_60 ( & V_4 -> V_59 , V_17 ) ;
F_107 () ;
F_59 ( & V_4 -> V_59 , V_17 ) ;
} while ( V_4 -> V_17 & V_18 );
} else
F_110 (area, &object->area_list, node)
F_101 ( ( void * ) V_44 -> V_64 ,
( void * ) ( V_44 -> V_64 + V_44 -> V_8 ) ,
V_4 ) ;
V_63:
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_111 ( void )
{
struct V_3 * V_4 , * V_42 ;
V_4 = F_112 ( V_57 . V_98 , F_113 ( * V_4 ) , V_57 ) ;
while ( & V_4 -> V_57 != & V_57 ) {
F_107 () ;
if ( ! F_98 () )
F_108 ( V_4 ) ;
V_42 = F_112 ( V_4 -> V_57 . V_98 , F_113 ( * V_4 ) ,
V_57 ) ;
F_114 ( & V_4 -> V_57 ) ;
F_24 ( V_4 ) ;
V_4 = V_42 ;
}
F_26 ( ! F_115 ( & V_57 ) ) ;
}
static void F_116 ( void )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
int V_22 ;
int V_100 = 0 ;
V_21 = V_19 ;
F_29 () ;
F_117 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_59 , V_17 ) ;
#ifdef F_62
if ( F_58 ( & V_4 -> V_38 ) > 1 ) {
F_83 ( L_35 ,
F_58 ( & V_4 -> V_38 ) ) ;
F_11 ( V_4 ) ;
}
#endif
V_4 -> V_14 = 0 ;
if ( F_6 ( V_4 ) && F_17 ( V_4 ) )
F_105 ( & V_4 -> V_57 , & V_57 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
F_32 () ;
F_106 ( V_101 , V_102 ) ;
F_106 ( V_103 , V_104 ) ;
#ifdef F_118
F_80 (i)
F_106 ( V_105 + F_119 ( V_22 ) ,
V_106 + F_119 ( V_22 ) ) ;
#endif
F_120 () ;
F_121 (i) {
unsigned long V_107 = F_122 ( V_22 ) ;
unsigned long V_108 = F_123 ( V_22 ) ;
unsigned long V_109 ;
for ( V_109 = V_107 ; V_109 < V_108 ; V_109 ++ ) {
struct V_110 * V_110 ;
if ( ! F_124 ( V_109 ) )
continue;
V_110 = F_125 ( V_109 ) ;
if ( F_126 ( V_110 ) == 0 )
continue;
F_101 ( V_110 , V_110 + 1 , NULL ) ;
}
}
F_127 () ;
if ( V_111 ) {
struct V_112 * V_113 , * V_114 ;
F_128 ( & V_115 ) ;
F_129 (g, p) {
F_101 ( F_130 ( V_113 ) , F_130 ( V_113 ) +
V_116 , NULL ) ;
} F_131 ( V_114 , V_113 ) ;
F_132 ( & V_115 ) ;
}
F_111 () ;
F_29 () ;
F_117 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( F_5 ( V_4 ) && ( V_4 -> V_17 & V_18 )
&& F_93 ( V_4 ) && F_17 ( V_4 ) ) {
V_4 -> V_14 = V_4 -> V_16 ;
F_105 ( & V_4 -> V_57 , & V_57 ) ;
}
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
F_32 () ;
F_111 () ;
if ( F_98 () )
return;
F_29 () ;
F_117 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( F_7 ( V_4 ) &&
! ( V_4 -> V_17 & V_117 ) ) {
V_4 -> V_17 |= V_117 ;
V_100 ++ ;
}
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
F_32 () ;
if ( V_100 ) {
V_118 = true ;
F_133 ( L_36
L_37 , V_100 ) ;
}
}
static int F_134 ( void * V_119 )
{
static int V_120 = 1 ;
F_133 ( L_38 ) ;
F_135 ( V_60 , 10 ) ;
if ( V_120 ) {
V_120 = 0 ;
F_136 ( V_121 ) ;
}
while ( ! F_100 () ) {
signed long V_122 = V_123 ;
F_137 ( & V_124 ) ;
F_116 () ;
F_138 ( & V_124 ) ;
while ( V_122 && ! F_100 () )
V_122 = F_139 ( V_122 ) ;
}
F_133 ( L_39 ) ;
return 0 ;
}
static void F_140 ( void )
{
if ( V_125 )
return;
V_125 = F_141 ( F_134 , NULL , L_40 ) ;
if ( F_78 ( V_125 ) ) {
F_43 ( L_41 ) ;
V_125 = NULL ;
}
}
static void F_142 ( void )
{
if ( V_125 ) {
F_143 ( V_125 ) ;
V_125 = NULL ;
}
}
static void * F_144 ( struct V_1 * V_2 , T_8 * V_126 )
{
struct V_3 * V_4 ;
T_8 V_127 = * V_126 ;
int V_128 ;
V_128 = F_145 ( & V_124 ) ;
if ( V_128 < 0 )
return F_146 ( V_128 ) ;
F_29 () ;
F_117 (object, &object_list, object_list) {
if ( V_127 -- > 0 )
continue;
if ( F_17 ( V_4 ) )
goto V_63;
}
V_4 = NULL ;
V_63:
return V_4 ;
}
static void * F_147 ( struct V_1 * V_2 , void * V_129 , T_8 * V_126 )
{
struct V_3 * V_130 = V_129 ;
struct V_3 * V_131 = NULL ;
struct V_3 * V_132 = V_130 ;
++ ( * V_126 ) ;
F_148 (obj, &object_list, object_list) {
if ( F_17 ( V_132 ) ) {
V_131 = V_132 ;
break;
}
}
F_24 ( V_130 ) ;
return V_131 ;
}
static void F_149 ( struct V_1 * V_2 , void * V_129 )
{
if ( ! F_78 ( V_129 ) ) {
F_32 () ;
F_138 ( & V_124 ) ;
if ( V_129 )
F_24 ( V_129 ) ;
}
}
static int F_150 ( struct V_1 * V_2 , void * V_129 )
{
struct V_3 * V_4 = V_129 ;
unsigned long V_17 ;
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_117 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
return 0 ;
}
static int F_151 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_152 ( V_134 , & V_135 ) ;
}
static int F_153 ( const char * V_136 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
unsigned long V_137 ;
if ( F_154 ( V_136 , 0 , & V_137 ) )
return - V_138 ;
V_4 = F_28 ( V_137 , 0 ) ;
if ( ! V_4 ) {
F_133 ( L_42 , V_137 ) ;
return - V_138 ;
}
F_59 ( & V_4 -> V_59 , V_17 ) ;
F_11 ( V_4 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static void F_155 ( void )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_29 () ;
F_117 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_117 ) &&
F_7 ( V_4 ) )
F_64 ( V_4 , V_69 ) ;
F_60 ( & V_4 -> V_59 , V_17 ) ;
}
F_32 () ;
V_118 = false ;
}
static T_9 F_156 ( struct V_134 * V_134 , const char T_10 * V_139 ,
T_2 V_8 , T_8 * V_140 )
{
char V_141 [ 64 ] ;
int V_142 ;
int V_143 ;
V_142 = F_51 ( V_8 , ( sizeof( V_141 ) - 1 ) ) ;
if ( F_157 ( V_141 , V_139 , V_142 ) < 0 )
return - V_144 ;
V_141 [ V_142 ] = 0 ;
V_143 = F_145 ( & V_124 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( strncmp ( V_141 , L_43 , 5 ) == 0 ) {
if ( V_76 )
F_155 () ;
else
F_158 () ;
goto V_63;
}
if ( ! V_76 ) {
V_143 = - V_145 ;
goto V_63;
}
if ( strncmp ( V_141 , L_44 , 3 ) == 0 )
F_44 () ;
else if ( strncmp ( V_141 , L_45 , 8 ) == 0 )
V_111 = 1 ;
else if ( strncmp ( V_141 , L_46 , 9 ) == 0 )
V_111 = 0 ;
else if ( strncmp ( V_141 , L_47 , 7 ) == 0 )
F_140 () ;
else if ( strncmp ( V_141 , L_48 , 8 ) == 0 )
F_142 () ;
else if ( strncmp ( V_141 , L_49 , 5 ) == 0 ) {
unsigned long V_146 ;
V_143 = F_154 ( V_141 + 5 , 0 , & V_146 ) ;
if ( V_143 < 0 )
goto V_63;
F_142 () ;
if ( V_146 ) {
V_123 = F_159 ( V_146 * 1000 ) ;
F_140 () ;
}
} else if ( strncmp ( V_141 , L_50 , 4 ) == 0 )
F_116 () ;
else if ( strncmp ( V_141 , L_51 , 5 ) == 0 )
V_143 = F_153 ( V_141 + 5 ) ;
else
V_143 = - V_138 ;
V_63:
F_138 ( & V_124 ) ;
if ( V_143 < 0 )
return V_143 ;
* V_140 += V_8 ;
return V_8 ;
}
static void F_158 ( void )
{
struct V_3 * V_4 ;
F_29 () ;
F_117 (object, &object_list, object_list)
F_61 ( V_4 -> V_6 ) ;
F_32 () ;
}
static void F_160 ( struct V_147 * V_148 )
{
F_142 () ;
V_83 = 0 ;
if ( ! V_118 )
F_158 () ;
else
F_133 ( L_52
L_53 ) ;
}
static void F_44 ( void )
{
if ( F_161 ( & V_74 , 0 , 1 ) )
return;
V_76 = 0 ;
if ( V_149 )
F_162 ( & V_150 ) ;
else
V_83 = 0 ;
F_133 ( L_54 ) ;
}
static int F_163 ( char * V_136 )
{
if ( ! V_136 )
return - V_138 ;
if ( strcmp ( V_136 , L_44 ) == 0 )
F_44 () ;
else if ( strcmp ( V_136 , L_55 ) == 0 )
V_151 = 1 ;
else
return - V_138 ;
return 0 ;
}
static void T_4 F_164 ( struct V_73 * log )
{
struct V_28 V_27 ;
V_27 . V_29 = log -> V_26 ;
V_27 . V_30 = log -> V_27 ;
F_12 ( L_56 ) ;
F_13 ( & V_27 , 2 ) ;
}
void T_4 F_165 ( void )
{
int V_22 ;
unsigned long V_17 ;
#ifdef F_166
if ( ! V_151 ) {
V_80 = 0 ;
F_44 () ;
return;
}
#endif
V_20 = F_159 ( V_152 ) ;
V_123 = F_159 ( V_153 * 1000 ) ;
V_47 = F_167 ( V_3 , V_154 ) ;
V_46 = F_167 ( V_43 , V_154 ) ;
if ( V_75 > F_74 ( V_73 ) )
F_43 ( L_57
L_58 , V_75 ) ;
F_75 ( V_17 ) ;
V_80 = 0 ;
if ( V_74 ) {
F_76 ( V_17 ) ;
return;
} else {
V_76 = 1 ;
V_83 = 1 ;
}
F_76 ( V_17 ) ;
for ( V_22 = 0 ; V_22 < V_75 ; V_22 ++ ) {
struct V_73 * log = & V_73 [ V_22 ] ;
switch ( log -> V_72 ) {
case V_81 :
F_77 ( log ) ;
break;
case V_82 :
F_79 ( log ) ;
break;
case V_84 :
F_85 ( log -> V_5 ) ;
break;
case V_85 :
F_86 ( log -> V_5 , log -> V_8 ) ;
break;
case V_86 :
F_87 ( log -> V_5 ) ;
break;
case V_87 :
F_90 ( log -> V_5 ) ;
break;
case V_88 :
F_91 ( log -> V_5 ) ;
break;
case V_89 :
V_43 ( log -> V_5 , log -> V_8 , V_66 ) ;
break;
case V_90 :
F_92 ( log -> V_5 ) ;
break;
default:
F_16 ( L_59 ,
log -> V_72 ) ;
}
if ( V_155 ) {
F_164 ( log ) ;
V_155 = 0 ;
}
}
}
static int T_4 F_168 ( void )
{
struct V_156 * V_156 ;
V_149 = 1 ;
if ( V_74 ) {
F_162 ( & V_150 ) ;
return - V_157 ;
}
V_156 = F_169 ( L_40 , V_158 , NULL , NULL ,
& V_159 ) ;
if ( ! V_156 )
F_43 ( L_60 ) ;
F_137 ( & V_124 ) ;
F_140 () ;
F_138 ( & V_124 ) ;
F_133 ( L_61 ) ;
return 0 ;
}
