static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 * V_5 = ( const T_1 * ) V_4 -> V_6 ;
int V_7 , V_8 , V_9 ;
unsigned char V_10 [ V_11 * 5 ] ;
V_9 = V_8 =
F_2 ( V_4 -> V_12 , ( V_13 ) ( V_14 * V_11 ) ) ;
F_3 ( V_2 , L_1 , V_8 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 += V_11 ) {
int V_15 = F_2 ( V_9 , V_11 ) ;
V_9 -= V_11 ;
F_4 ( V_5 + V_7 , V_15 , V_11 ,
V_16 , V_10 , sizeof( V_10 ) ,
V_17 ) ;
F_3 ( V_2 , L_2 , V_10 ) ;
}
}
static bool F_5 ( const struct V_3 * V_4 )
{
return V_4 -> V_18 != V_19 &&
V_4 -> V_18 < V_4 -> V_20 ;
}
static bool F_6 ( const struct V_3 * V_4 )
{
return V_4 -> V_20 != V_19 &&
V_4 -> V_18 >= V_4 -> V_20 ;
}
static bool F_7 ( struct V_3 * V_4 )
{
return ( F_5 ( V_4 ) && V_4 -> V_21 & V_22 ) &&
F_8 ( V_4 -> V_23 + V_24 ,
V_25 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 ;
unsigned int V_26 = F_10 ( V_23 - V_4 -> V_23 ) ;
F_3 ( V_2 , L_3 ,
V_4 -> V_6 , V_4 -> V_12 ) ;
F_3 ( V_2 , L_4 ,
V_4 -> V_27 , V_4 -> V_28 , V_4 -> V_23 ,
V_26 / 1000 , V_26 % 1000 ) ;
F_1 ( V_2 , V_4 ) ;
F_3 ( V_2 , L_5 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_29 ; V_7 ++ ) {
void * V_5 = ( void * ) V_4 -> V_30 [ V_7 ] ;
F_3 ( V_2 , L_6 , V_5 , V_5 ) ;
}
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_31 V_30 ;
V_30 . V_32 = V_4 -> V_29 ;
V_30 . V_33 = V_4 -> V_30 ;
F_12 ( L_7 ,
V_4 -> V_6 , V_4 -> V_12 ) ;
F_12 ( L_8 ,
V_4 -> V_27 , V_4 -> V_28 , V_4 -> V_23 ) ;
F_12 ( L_9 , V_4 -> V_20 ) ;
F_12 ( L_10 , V_4 -> V_18 ) ;
F_12 ( L_11 , V_4 -> V_21 ) ;
F_12 ( L_12 , V_4 -> V_34 ) ;
F_12 ( L_5 ) ;
F_13 ( & V_30 , 4 ) ;
}
static struct V_3 * F_14 ( unsigned long V_5 , int V_35 )
{
struct V_36 * V_37 = V_38 . V_36 ;
while ( V_37 ) {
struct V_3 * V_4 =
F_15 ( V_37 , struct V_3 , V_36 ) ;
if ( V_5 < V_4 -> V_6 )
V_37 = V_4 -> V_36 . V_39 ;
else if ( V_4 -> V_6 + V_4 -> V_12 <= V_5 )
V_37 = V_4 -> V_36 . V_40 ;
else if ( V_4 -> V_6 == V_5 || V_35 )
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
return F_18 ( & V_4 -> V_41 ) ;
}
static void F_19 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_3 * V_4 =
F_20 ( V_43 , struct V_3 , V_43 ) ;
F_21 (area, tmp, &object->area_list, node) {
F_22 ( & V_47 -> V_48 ) ;
F_23 ( V_49 , V_47 ) ;
}
F_23 ( V_50 , V_4 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( ! F_25 ( & V_4 -> V_41 ) )
return;
F_26 ( V_4 -> V_21 & V_22 ) ;
F_27 ( & V_4 -> V_43 , F_19 ) ;
}
static struct V_3 * F_28 ( unsigned long V_5 , int V_35 )
{
unsigned long V_21 ;
struct V_3 * V_4 = NULL ;
F_29 () ;
F_30 ( & V_51 , V_21 ) ;
V_4 = F_14 ( V_5 , V_35 ) ;
F_31 ( & V_51 , V_21 ) ;
if ( V_4 && ! F_17 ( V_4 ) )
V_4 = NULL ;
F_32 () ;
return V_4 ;
}
static struct V_3 * F_33 ( unsigned long V_5 , int V_35 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
F_34 ( & V_51 , V_21 ) ;
V_4 = F_14 ( V_5 , V_35 ) ;
if ( V_4 ) {
F_35 ( & V_4 -> V_36 , & V_38 ) ;
F_36 ( & V_4 -> V_52 ) ;
}
F_37 ( & V_51 , V_21 ) ;
return V_4 ;
}
static int F_38 ( unsigned long * V_30 )
{
struct V_31 V_31 ;
V_31 . V_53 = V_54 ;
V_31 . V_32 = 0 ;
V_31 . V_33 = V_30 ;
V_31 . V_55 = 2 ;
F_39 ( & V_31 ) ;
return V_31 . V_32 ;
}
static struct V_3 * F_40 ( unsigned long V_5 , V_13 V_12 ,
int V_20 , T_2 V_56 )
{
unsigned long V_21 ;
struct V_3 * V_4 , * V_57 ;
struct V_36 * * V_58 , * V_59 ;
V_4 = F_41 ( V_50 , F_42 ( V_56 ) ) ;
if ( ! V_4 ) {
F_43 ( L_14 ) ;
F_44 () ;
return NULL ;
}
F_45 ( & V_4 -> V_52 ) ;
F_45 ( & V_4 -> V_60 ) ;
F_46 ( & V_4 -> V_61 ) ;
F_47 ( & V_4 -> V_62 ) ;
F_48 ( & V_4 -> V_41 , 1 ) ;
V_4 -> V_21 = V_22 ;
V_4 -> V_6 = V_5 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = 0 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_34 = 0 ;
if ( F_49 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_15 , sizeof( V_4 -> V_27 ) ) ;
} else if ( F_50 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_16 , sizeof( V_4 -> V_27 ) ) ;
} else {
V_4 -> V_28 = V_63 -> V_28 ;
strncpy ( V_4 -> V_27 , V_63 -> V_27 , sizeof( V_4 -> V_27 ) ) ;
}
V_4 -> V_29 = F_38 ( V_4 -> V_30 ) ;
F_34 ( & V_51 , V_21 ) ;
V_64 = F_2 ( V_64 , V_5 ) ;
V_65 = F_51 ( V_65 , V_5 + V_12 ) ;
V_58 = & V_38 . V_36 ;
V_59 = NULL ;
while ( * V_58 ) {
V_59 = * V_58 ;
V_57 = F_15 ( V_59 , struct V_3 , V_36 ) ;
if ( V_5 + V_12 <= V_57 -> V_6 )
V_58 = & V_57 -> V_36 . V_39 ;
else if ( V_57 -> V_6 + V_57 -> V_12 <= V_5 )
V_58 = & V_57 -> V_36 . V_40 ;
else {
F_52 ( L_17
L_18 ,
V_5 ) ;
F_11 ( V_57 ) ;
F_23 ( V_50 , V_4 ) ;
V_4 = NULL ;
goto V_66;
}
}
F_53 ( & V_4 -> V_36 , V_59 , V_58 ) ;
F_54 ( & V_4 -> V_36 , & V_38 ) ;
F_55 ( & V_4 -> V_52 , & V_52 ) ;
V_66:
F_37 ( & V_51 , V_21 ) ;
return V_4 ;
}
static void F_56 ( struct V_3 * V_4 )
{
unsigned long V_21 ;
F_26 ( ! ( V_4 -> V_21 & V_22 ) ) ;
F_26 ( F_57 ( & V_4 -> V_41 ) < 1 ) ;
F_58 ( & V_4 -> V_62 , V_21 ) ;
V_4 -> V_21 &= ~ V_22 ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
F_24 ( V_4 ) ;
}
static void F_60 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_61
F_16 ( L_19 ,
V_5 ) ;
#endif
return;
}
F_56 ( V_4 ) ;
}
static void F_62 ( unsigned long V_5 , V_13 V_12 )
{
struct V_3 * V_4 ;
unsigned long V_67 , V_68 ;
V_4 = F_33 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_61
F_16 ( L_20
L_21 , V_5 , V_12 ) ;
#endif
return;
}
V_67 = V_4 -> V_6 ;
V_68 = V_4 -> V_6 + V_4 -> V_12 ;
if ( V_5 > V_67 )
F_40 ( V_67 , V_5 - V_67 , V_4 -> V_20 ,
V_69 ) ;
if ( V_5 + V_12 < V_68 )
F_40 ( V_5 + V_12 , V_68 - V_5 - V_12 , V_4 -> V_20 ,
V_69 ) ;
F_56 ( V_4 ) ;
}
static void F_63 ( struct V_3 * V_4 , int V_70 )
{
V_4 -> V_20 = V_70 ;
if ( V_70 == V_19 )
V_4 -> V_21 |= V_71 ;
}
static void F_64 ( struct V_3 * V_4 , int V_70 )
{
unsigned long V_21 ;
F_58 ( & V_4 -> V_62 , V_21 ) ;
F_63 ( V_4 , V_70 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
static void F_65 ( unsigned long V_5 , int V_70 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_22
L_23 , V_5 ,
( V_70 == V_72 ) ? L_24 :
( V_70 == V_19 ) ? L_25 : L_26 ) ;
return;
}
F_64 ( V_4 , V_70 ) ;
F_24 ( V_4 ) ;
}
static void F_66 ( unsigned long V_5 )
{
F_65 ( V_5 , V_72 ) ;
}
static void F_67 ( unsigned long V_5 )
{
F_65 ( V_5 , V_19 ) ;
}
static void F_68 ( unsigned long V_5 , V_13 V_12 , T_2 V_56 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
V_4 = F_28 ( V_5 , 1 ) ;
if ( ! V_4 ) {
F_16 ( L_27 ,
V_5 ) ;
return;
}
V_47 = F_41 ( V_49 , F_42 ( V_56 ) ) ;
if ( ! V_47 ) {
F_43 ( L_28 ) ;
goto V_66;
}
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( V_12 == V_73 ) {
V_12 = V_4 -> V_6 + V_4 -> V_12 - V_5 ;
} else if ( V_5 + V_12 > V_4 -> V_6 + V_4 -> V_12 ) {
F_16 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_23 ( V_49 , V_47 ) ;
goto V_74;
}
F_69 ( & V_47 -> V_48 ) ;
V_47 -> V_67 = V_5 ;
V_47 -> V_12 = V_12 ;
F_70 ( & V_47 -> V_48 , & V_4 -> V_61 ) ;
V_74:
F_59 ( & V_4 -> V_62 , V_21 ) ;
V_66:
F_24 ( V_4 ) ;
}
static void F_71 ( unsigned long V_5 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_30 , V_5 ) ;
return;
}
F_58 ( & V_4 -> V_62 , V_21 ) ;
V_4 -> V_21 |= V_71 ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
F_24 ( V_4 ) ;
}
static void T_3 F_72 ( int V_75 , const void * V_5 , V_13 V_12 ,
int V_20 )
{
unsigned long V_21 ;
struct V_76 * log ;
if ( V_77 ) {
V_78 ++ ;
return;
}
if ( V_78 >= F_73 ( V_76 ) ) {
F_44 () ;
return;
}
F_74 ( V_21 ) ;
log = & V_76 [ V_78 ] ;
log -> V_75 = V_75 ;
log -> V_5 = V_5 ;
log -> V_12 = V_12 ;
log -> V_20 = V_20 ;
log -> V_29 = F_38 ( log -> V_30 ) ;
V_78 ++ ;
F_75 ( V_21 ) ;
}
static void F_76 ( struct V_76 * log )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_7 ;
if ( ! V_79 || ! log -> V_5 || F_77 ( log -> V_5 ) )
return;
F_29 () ;
V_4 = F_40 ( ( unsigned long ) log -> V_5 , log -> V_12 ,
log -> V_20 , V_80 ) ;
if ( ! V_4 )
goto V_66;
F_58 ( & V_4 -> V_62 , V_21 ) ;
for ( V_7 = 0 ; V_7 < log -> V_29 ; V_7 ++ )
V_4 -> V_30 [ V_7 ] = log -> V_30 [ V_7 ] ;
V_4 -> V_29 = log -> V_29 ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
V_66:
F_32 () ;
}
static void F_78 ( struct V_76 * log )
{
unsigned int V_81 ;
const void T_4 * V_5 = log -> V_5 ;
F_79 (cpu) {
log -> V_5 = F_80 ( V_5 , V_81 ) ;
F_76 ( log ) ;
}
}
void T_5 F_81 ( const void * V_5 , V_13 V_12 , int V_20 ,
T_2 V_56 )
{
F_82 ( L_31 , V_82 , V_5 , V_12 , V_20 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_40 ( ( unsigned long ) V_5 , V_12 , V_20 , V_56 ) ;
else if ( V_83 )
F_72 ( V_84 , V_5 , V_12 , V_20 ) ;
}
void T_5 F_83 ( const void T_4 * V_5 , V_13 V_12 ,
T_2 V_56 )
{
unsigned int V_81 ;
F_82 ( L_32 , V_82 , V_5 , V_12 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_79 (cpu)
F_40 ( ( unsigned long ) F_80 ( V_5 , V_81 ) ,
V_12 , 0 , V_56 ) ;
else if ( V_83 )
F_72 ( V_85 , V_5 , V_12 , 0 ) ;
}
void T_5 F_84 ( const void * V_5 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_86 && V_5 && ! F_77 ( V_5 ) )
F_60 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_72 ( V_87 , V_5 , 0 , 0 ) ;
}
void T_5 F_85 ( const void * V_5 , V_13 V_12 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_62 ( ( unsigned long ) V_5 , V_12 ) ;
else if ( V_83 )
F_72 ( V_88 , V_5 , V_12 , 0 ) ;
}
void T_5 F_86 ( const void T_4 * V_5 )
{
unsigned int V_81 ;
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_86 && V_5 && ! F_77 ( V_5 ) )
F_79 (cpu)
F_60 ( ( unsigned long ) F_80 ( V_5 ,
V_81 ) ) ;
else if ( V_83 )
F_72 ( V_89 , V_5 , 0 , 0 ) ;
}
void T_5 F_87 ( const void * V_5 )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_82 ( L_33 , V_82 , V_5 ) ;
if ( ! V_79 || F_88 ( V_5 ) )
return;
V_4 = F_28 ( ( unsigned long ) V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_61
F_16 ( L_34 ,
V_5 ) ;
#endif
return;
}
F_58 ( & V_4 -> V_62 , V_21 ) ;
V_4 -> V_29 = F_38 ( V_4 -> V_30 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
F_24 ( V_4 ) ;
}
void T_5 F_89 ( const void * V_5 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_66 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_72 ( V_90 , V_5 , 0 , 0 ) ;
}
void T_5 F_90 ( const void * V_5 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_67 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_72 ( V_91 , V_5 , 0 , 0 ) ;
}
void T_5 V_46 ( const void * V_5 , V_13 V_12 , T_2 V_56 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && V_12 && ! F_77 ( V_5 ) )
F_68 ( ( unsigned long ) V_5 , V_12 , V_56 ) ;
else if ( V_83 )
F_72 ( V_92 , V_5 , V_12 , 0 ) ;
}
void T_5 F_91 ( const void * V_5 )
{
F_82 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_77 ( V_5 ) )
F_71 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_72 ( V_93 , V_5 , 0 , 0 ) ;
}
static bool F_92 ( struct V_3 * V_4 )
{
T_6 V_94 = V_4 -> V_34 ;
if ( ! F_93 ( V_4 -> V_6 , V_4 -> V_12 ) )
return false ;
F_94 () ;
V_4 -> V_34 = F_95 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_12 ) ;
F_96 () ;
return V_4 -> V_34 != V_94 ;
}
static int F_97 ( void )
{
if ( ! V_79 )
return 1 ;
if ( V_63 -> V_95 )
return F_98 ( V_63 ) ;
else
return F_99 () ;
return 0 ;
}
static void F_100 ( void * V_96 , void * V_97 ,
struct V_3 * V_98 )
{
unsigned long * V_5 ;
unsigned long * V_67 = F_101 ( V_96 , V_99 ) ;
unsigned long * V_68 = V_97 - ( V_99 - 1 ) ;
unsigned long V_21 ;
F_30 ( & V_51 , V_21 ) ;
for ( V_5 = V_67 ; V_5 < V_68 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_6 ;
if ( F_97 () )
break;
if ( ! F_93 ( ( unsigned long ) V_5 ,
V_99 ) )
continue;
F_94 () ;
V_6 = * V_5 ;
F_96 () ;
if ( V_6 < V_64 || V_6 >= V_65 )
continue;
V_4 = F_14 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_98 )
continue;
F_102 ( & V_4 -> V_62 , V_100 ) ;
if ( ! F_5 ( V_4 ) ) {
F_103 ( & V_4 -> V_62 ) ;
continue;
}
V_4 -> V_18 ++ ;
if ( F_6 ( V_4 ) ) {
F_26 ( ! F_17 ( V_4 ) ) ;
F_104 ( & V_4 -> V_60 , & V_60 ) ;
}
F_103 ( & V_4 -> V_62 ) ;
}
F_31 ( & V_51 , V_21 ) ;
}
static void F_105 ( void * V_67 , void * V_68 )
{
void * V_101 ;
while ( V_67 < V_68 ) {
V_101 = F_2 ( V_67 + V_102 , V_68 ) ;
F_100 ( V_67 , V_101 , NULL ) ;
V_67 = V_101 ;
F_106 () ;
}
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_46 * V_47 ;
unsigned long V_21 ;
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( V_4 -> V_21 & V_71 )
goto V_66;
if ( ! ( V_4 -> V_21 & V_22 ) )
goto V_66;
if ( F_108 ( & V_4 -> V_61 ) ) {
void * V_67 = ( void * ) V_4 -> V_6 ;
void * V_68 = ( void * ) ( V_4 -> V_6 + V_4 -> V_12 ) ;
void * V_101 ;
do {
V_101 = F_2 ( V_67 + V_102 , V_68 ) ;
F_100 ( V_67 , V_101 , V_4 ) ;
V_67 = V_101 ;
if ( V_67 >= V_68 )
break;
F_59 ( & V_4 -> V_62 , V_21 ) ;
F_106 () ;
F_58 ( & V_4 -> V_62 , V_21 ) ;
} while ( V_4 -> V_21 & V_22 );
} else
F_109 (area, &object->area_list, node)
F_100 ( ( void * ) V_47 -> V_67 ,
( void * ) ( V_47 -> V_67 + V_47 -> V_12 ) ,
V_4 ) ;
V_66:
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
static void F_110 ( void )
{
struct V_3 * V_4 , * V_45 ;
V_4 = F_111 ( V_60 . V_101 , F_112 ( * V_4 ) , V_60 ) ;
while ( & V_4 -> V_60 != & V_60 ) {
F_106 () ;
if ( ! F_97 () )
F_107 ( V_4 ) ;
V_45 = F_111 ( V_4 -> V_60 . V_101 , F_112 ( * V_4 ) ,
V_60 ) ;
F_113 ( & V_4 -> V_60 ) ;
F_24 ( V_4 ) ;
V_4 = V_45 ;
}
F_26 ( ! F_114 ( & V_60 ) ) ;
}
static void F_115 ( void )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
int V_7 ;
int V_103 = 0 ;
V_25 = V_23 ;
F_29 () ;
F_116 (object, &object_list, object_list) {
F_58 ( & V_4 -> V_62 , V_21 ) ;
#ifdef F_61
if ( F_57 ( & V_4 -> V_41 ) > 1 ) {
F_82 ( L_35 ,
F_57 ( & V_4 -> V_41 ) ) ;
F_11 ( V_4 ) ;
}
#endif
V_4 -> V_18 = 0 ;
if ( F_6 ( V_4 ) && F_17 ( V_4 ) )
F_104 ( & V_4 -> V_60 , & V_60 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
F_32 () ;
F_105 ( V_104 , V_105 ) ;
F_105 ( V_106 , V_107 ) ;
#ifdef F_117
F_79 (i)
F_105 ( V_108 + F_118 ( V_7 ) ,
V_109 + F_118 ( V_7 ) ) ;
#endif
F_119 () ;
F_120 (i) {
unsigned long V_110 = F_121 ( V_7 ) ;
unsigned long V_111 = F_122 ( V_7 ) ;
unsigned long V_112 ;
for ( V_112 = V_110 ; V_112 < V_111 ; V_112 ++ ) {
struct V_113 * V_113 ;
if ( ! F_123 ( V_112 ) )
continue;
V_113 = F_124 ( V_112 ) ;
if ( F_125 ( V_113 ) == 0 )
continue;
F_100 ( V_113 , V_113 + 1 , NULL ) ;
}
}
F_126 () ;
if ( V_114 ) {
struct V_115 * V_116 , * V_117 ;
F_127 ( & V_118 ) ;
F_128 (g, p) {
F_100 ( F_129 ( V_116 ) , F_129 ( V_116 ) +
V_119 , NULL ) ;
} F_130 ( V_117 , V_116 ) ;
F_131 ( & V_118 ) ;
}
F_110 () ;
F_29 () ;
F_116 (object, &object_list, object_list) {
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( F_5 ( V_4 ) && ( V_4 -> V_21 & V_22 )
&& F_92 ( V_4 ) && F_17 ( V_4 ) ) {
V_4 -> V_18 = V_4 -> V_20 ;
F_104 ( & V_4 -> V_60 , & V_60 ) ;
}
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
F_32 () ;
F_110 () ;
if ( F_97 () )
return;
F_29 () ;
F_116 (object, &object_list, object_list) {
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( F_7 ( V_4 ) &&
! ( V_4 -> V_21 & V_120 ) ) {
V_4 -> V_21 |= V_120 ;
V_103 ++ ;
}
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
F_32 () ;
if ( V_103 ) {
V_121 = true ;
F_132 ( L_36
L_37 , V_103 ) ;
}
}
static int F_133 ( void * V_122 )
{
static int V_123 = 1 ;
F_132 ( L_38 ) ;
F_134 ( V_63 , 10 ) ;
if ( V_123 ) {
V_123 = 0 ;
F_135 ( V_124 ) ;
}
while ( ! F_99 () ) {
signed long V_125 = V_126 ;
F_136 ( & V_127 ) ;
F_115 () ;
F_137 ( & V_127 ) ;
while ( V_125 && ! F_99 () )
V_125 = F_138 ( V_125 ) ;
}
F_132 ( L_39 ) ;
return 0 ;
}
static void F_139 ( void )
{
if ( V_128 )
return;
V_128 = F_140 ( F_133 , NULL , L_40 ) ;
if ( F_77 ( V_128 ) ) {
F_43 ( L_41 ) ;
V_128 = NULL ;
}
}
static void F_141 ( void )
{
if ( V_128 ) {
F_142 ( V_128 ) ;
V_128 = NULL ;
}
}
static void * F_143 ( struct V_1 * V_2 , T_7 * V_129 )
{
struct V_3 * V_4 ;
T_7 V_130 = * V_129 ;
int V_131 ;
V_131 = F_144 ( & V_127 ) ;
if ( V_131 < 0 )
return F_145 ( V_131 ) ;
F_29 () ;
F_116 (object, &object_list, object_list) {
if ( V_130 -- > 0 )
continue;
if ( F_17 ( V_4 ) )
goto V_66;
}
V_4 = NULL ;
V_66:
return V_4 ;
}
static void * F_146 ( struct V_1 * V_2 , void * V_132 , T_7 * V_129 )
{
struct V_3 * V_133 = V_132 ;
struct V_3 * V_134 = NULL ;
struct V_3 * V_135 = V_133 ;
++ ( * V_129 ) ;
F_147 (obj, &object_list, object_list) {
if ( F_17 ( V_135 ) ) {
V_134 = V_135 ;
break;
}
}
F_24 ( V_133 ) ;
return V_134 ;
}
static void F_148 ( struct V_1 * V_2 , void * V_132 )
{
if ( ! F_77 ( V_132 ) ) {
F_32 () ;
F_137 ( & V_127 ) ;
if ( V_132 )
F_24 ( V_132 ) ;
}
}
static int F_149 ( struct V_1 * V_2 , void * V_132 )
{
struct V_3 * V_4 = V_132 ;
unsigned long V_21 ;
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( ( V_4 -> V_21 & V_120 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
return 0 ;
}
static int F_150 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_151 ( V_137 , & V_138 ) ;
}
static int F_152 ( const char * V_139 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
unsigned long V_140 ;
if ( F_153 ( V_139 , 0 , & V_140 ) )
return - V_141 ;
V_4 = F_28 ( V_140 , 0 ) ;
if ( ! V_4 ) {
F_132 ( L_42 , V_140 ) ;
return - V_141 ;
}
F_58 ( & V_4 -> V_62 , V_21 ) ;
F_11 ( V_4 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static void F_154 ( void )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_29 () ;
F_116 (object, &object_list, object_list) {
F_58 ( & V_4 -> V_62 , V_21 ) ;
if ( ( V_4 -> V_21 & V_120 ) &&
F_7 ( V_4 ) )
F_63 ( V_4 , V_72 ) ;
F_59 ( & V_4 -> V_62 , V_21 ) ;
}
F_32 () ;
V_121 = false ;
}
static T_8 F_155 ( struct V_137 * V_137 , const char T_9 * V_142 ,
V_13 V_12 , T_7 * V_143 )
{
char V_144 [ 64 ] ;
int V_145 ;
int V_146 ;
V_145 = F_2 ( V_12 , ( sizeof( V_144 ) - 1 ) ) ;
if ( F_156 ( V_144 , V_142 , V_145 ) < 0 )
return - V_147 ;
V_144 [ V_145 ] = 0 ;
V_146 = F_144 ( & V_127 ) ;
if ( V_146 < 0 )
return V_146 ;
if ( strncmp ( V_144 , L_43 , 5 ) == 0 ) {
if ( V_79 )
F_154 () ;
else
F_157 () ;
goto V_66;
}
if ( ! V_79 ) {
V_146 = - V_148 ;
goto V_66;
}
if ( strncmp ( V_144 , L_44 , 3 ) == 0 )
F_44 () ;
else if ( strncmp ( V_144 , L_45 , 8 ) == 0 )
V_114 = 1 ;
else if ( strncmp ( V_144 , L_46 , 9 ) == 0 )
V_114 = 0 ;
else if ( strncmp ( V_144 , L_47 , 7 ) == 0 )
F_139 () ;
else if ( strncmp ( V_144 , L_48 , 8 ) == 0 )
F_141 () ;
else if ( strncmp ( V_144 , L_49 , 5 ) == 0 ) {
unsigned long V_149 ;
V_146 = F_153 ( V_144 + 5 , 0 , & V_149 ) ;
if ( V_146 < 0 )
goto V_66;
F_141 () ;
if ( V_149 ) {
V_126 = F_158 ( V_149 * 1000 ) ;
F_139 () ;
}
} else if ( strncmp ( V_144 , L_50 , 4 ) == 0 )
F_115 () ;
else if ( strncmp ( V_144 , L_51 , 5 ) == 0 )
V_146 = F_152 ( V_144 + 5 ) ;
else
V_146 = - V_141 ;
V_66:
F_137 ( & V_127 ) ;
if ( V_146 < 0 )
return V_146 ;
* V_143 += V_12 ;
return V_12 ;
}
static void F_157 ( void )
{
struct V_3 * V_4 ;
F_29 () ;
F_116 (object, &object_list, object_list)
F_60 ( V_4 -> V_6 ) ;
F_32 () ;
}
static void F_159 ( struct V_150 * V_151 )
{
F_141 () ;
V_86 = 0 ;
if ( ! V_121 )
F_157 () ;
else
F_132 ( L_52
L_53 ) ;
}
static void F_44 ( void )
{
if ( F_160 ( & V_77 , 0 , 1 ) )
return;
V_79 = 0 ;
if ( V_152 )
F_161 ( & V_153 ) ;
else
V_86 = 0 ;
F_132 ( L_54 ) ;
}
static int F_162 ( char * V_139 )
{
if ( ! V_139 )
return - V_141 ;
if ( strcmp ( V_139 , L_44 ) == 0 )
F_44 () ;
else if ( strcmp ( V_139 , L_55 ) == 0 )
V_154 = 1 ;
else
return - V_141 ;
return 0 ;
}
static void T_3 F_163 ( struct V_76 * log )
{
struct V_31 V_30 ;
V_30 . V_32 = log -> V_29 ;
V_30 . V_33 = log -> V_30 ;
F_12 ( L_56 ) ;
F_13 ( & V_30 , 2 ) ;
}
void T_3 F_164 ( void )
{
int V_7 ;
unsigned long V_21 ;
#ifdef F_165
if ( ! V_154 ) {
V_83 = 0 ;
F_44 () ;
return;
}
#endif
V_24 = F_158 ( V_155 ) ;
V_126 = F_158 ( V_156 * 1000 ) ;
V_50 = F_166 ( V_3 , V_157 ) ;
V_49 = F_166 ( V_46 , V_157 ) ;
if ( V_78 >= F_73 ( V_76 ) )
F_43 ( L_57
L_58 , V_78 ) ;
F_74 ( V_21 ) ;
V_83 = 0 ;
if ( V_77 ) {
F_75 ( V_21 ) ;
return;
} else {
V_79 = 1 ;
V_86 = 1 ;
}
F_75 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
struct V_76 * log = & V_76 [ V_7 ] ;
switch ( log -> V_75 ) {
case V_84 :
F_76 ( log ) ;
break;
case V_85 :
F_78 ( log ) ;
break;
case V_87 :
F_84 ( log -> V_5 ) ;
break;
case V_88 :
F_85 ( log -> V_5 , log -> V_12 ) ;
break;
case V_89 :
F_86 ( log -> V_5 ) ;
break;
case V_90 :
F_89 ( log -> V_5 ) ;
break;
case V_91 :
F_90 ( log -> V_5 ) ;
break;
case V_92 :
V_46 ( log -> V_5 , log -> V_12 , V_69 ) ;
break;
case V_93 :
F_91 ( log -> V_5 ) ;
break;
default:
F_16 ( L_59 ,
log -> V_75 ) ;
}
if ( V_158 ) {
F_163 ( log ) ;
V_158 = 0 ;
}
}
}
static int T_3 F_167 ( void )
{
struct V_159 * V_159 ;
V_152 = 1 ;
if ( V_77 ) {
F_161 ( & V_153 ) ;
return - V_160 ;
}
V_159 = F_168 ( L_40 , V_161 , NULL , NULL ,
& V_162 ) ;
if ( ! V_159 )
F_43 ( L_60 ) ;
F_136 ( & V_127 ) ;
F_139 () ;
F_137 ( & V_127 ) ;
F_132 ( L_61 ) ;
return 0 ;
}
