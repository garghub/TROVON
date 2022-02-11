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
V_4 -> V_34 . V_35 , V_4 -> V_12 ) ;
F_12 ( L_8 ,
V_4 -> V_27 , V_4 -> V_28 , V_4 -> V_23 ) ;
F_12 ( L_9 , V_4 -> V_20 ) ;
F_12 ( L_10 , V_4 -> V_18 ) ;
F_12 ( L_11 , V_4 -> V_21 ) ;
F_12 ( L_12 , V_4 -> V_36 ) ;
F_12 ( L_5 ) ;
F_13 ( & V_30 , 4 ) ;
}
static struct V_3 * F_14 ( unsigned long V_5 , int V_37 )
{
struct V_38 * V_39 ;
struct V_40 V_41 ;
struct V_3 * V_4 ;
F_15 ( & V_41 , & V_42 , V_5 , V_5 ) ;
V_39 = F_16 ( & V_41 ) ;
if ( V_39 ) {
V_4 = F_17 ( V_39 , struct V_3 ,
V_34 ) ;
if ( ! V_37 && V_4 -> V_6 != V_5 ) {
F_18 ( L_13 ,
V_5 ) ;
F_11 ( V_4 ) ;
V_4 = NULL ;
}
} else
V_4 = NULL ;
return V_4 ;
}
static int F_19 ( struct V_3 * V_4 )
{
return F_20 ( & V_4 -> V_43 ) ;
}
static void F_21 ( struct V_44 * V_45 )
{
struct V_46 * V_47 , * V_48 ;
struct V_49 * V_50 ;
struct V_3 * V_4 =
F_22 ( V_45 , struct V_3 , V_45 ) ;
F_23 (area, elem, tmp, &object->area_list, node) {
F_24 ( V_47 ) ;
F_25 ( V_51 , V_50 ) ;
}
F_25 ( V_52 , V_4 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
if ( ! F_27 ( & V_4 -> V_43 ) )
return;
F_28 ( V_4 -> V_21 & V_22 ) ;
F_29 ( & V_4 -> V_45 , F_21 ) ;
}
static struct V_3 * F_30 ( unsigned long V_5 , int V_37 )
{
unsigned long V_21 ;
struct V_3 * V_4 = NULL ;
F_31 () ;
F_32 ( & V_53 , V_21 ) ;
if ( V_5 >= V_54 && V_5 < V_55 )
V_4 = F_14 ( V_5 , V_37 ) ;
F_33 ( & V_53 , V_21 ) ;
if ( V_4 && ! F_19 ( V_4 ) )
V_4 = NULL ;
F_34 () ;
return V_4 ;
}
static int F_35 ( unsigned long * V_30 )
{
struct V_31 V_31 ;
V_31 . V_56 = V_57 ;
V_31 . V_32 = 0 ;
V_31 . V_33 = V_30 ;
V_31 . V_58 = 2 ;
F_36 ( & V_31 ) ;
return V_31 . V_32 ;
}
static struct V_3 * F_37 ( unsigned long V_5 , V_13 V_12 ,
int V_20 , T_2 V_59 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
V_4 = F_38 ( V_52 , F_39 ( V_59 ) ) ;
if ( ! V_4 ) {
F_40 ( L_14 ) ;
F_41 () ;
return NULL ;
}
F_42 ( & V_4 -> V_60 ) ;
F_42 ( & V_4 -> V_61 ) ;
F_43 ( & V_4 -> V_62 ) ;
F_44 ( & V_4 -> V_63 ) ;
F_45 ( & V_4 -> V_43 , 1 ) ;
V_4 -> V_21 = V_22 ;
V_4 -> V_6 = V_5 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = 0 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_36 = 0 ;
if ( F_46 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_15 , sizeof( V_4 -> V_27 ) ) ;
} else if ( F_47 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_16 , sizeof( V_4 -> V_27 ) ) ;
} else {
V_4 -> V_28 = V_64 -> V_28 ;
strncpy ( V_4 -> V_27 , V_64 -> V_27 , sizeof( V_4 -> V_27 ) ) ;
}
V_4 -> V_29 = F_35 ( V_4 -> V_30 ) ;
F_48 ( & V_4 -> V_34 ) ;
V_4 -> V_34 . V_35 = V_5 ;
V_4 -> V_34 . V_65 = V_5 + V_12 - 1 ;
F_49 ( & V_53 , V_21 ) ;
V_54 = F_2 ( V_54 , V_5 ) ;
V_55 = F_50 ( V_55 , V_5 + V_12 ) ;
V_39 = F_51 ( & V_42 , & V_4 -> V_34 ) ;
if ( V_39 != & V_4 -> V_34 ) {
F_52 ( L_17
L_18 , V_5 ) ;
V_4 = F_14 ( V_5 , 1 ) ;
F_53 ( & V_4 -> V_63 ) ;
F_11 ( V_4 ) ;
F_54 ( & V_4 -> V_63 ) ;
goto V_66;
}
F_55 ( & V_4 -> V_60 , & V_60 ) ;
V_66:
F_56 ( & V_53 , V_21 ) ;
return V_4 ;
}
static void F_57 ( struct V_3 * V_4 )
{
unsigned long V_21 ;
F_49 ( & V_53 , V_21 ) ;
F_58 ( & V_42 , & V_4 -> V_34 ) ;
F_59 ( & V_4 -> V_60 ) ;
F_56 ( & V_53 , V_21 ) ;
F_28 ( ! ( V_4 -> V_21 & V_22 ) ) ;
F_28 ( F_60 ( & V_4 -> V_43 ) < 2 ) ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
V_4 -> V_21 &= ~ V_22 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_26 ( V_4 ) ;
}
static void F_63 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_19 ,
V_5 ) ;
#endif
return;
}
F_57 ( V_4 ) ;
F_26 ( V_4 ) ;
}
static void F_65 ( unsigned long V_5 , V_13 V_12 )
{
struct V_3 * V_4 ;
unsigned long V_35 , V_67 ;
V_4 = F_30 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_20
L_21 , V_5 , V_12 ) ;
#endif
return;
}
F_57 ( V_4 ) ;
V_35 = V_4 -> V_6 ;
V_67 = V_4 -> V_6 + V_4 -> V_12 ;
if ( V_5 > V_35 )
F_37 ( V_35 , V_5 - V_35 , V_4 -> V_20 ,
V_68 ) ;
if ( V_5 + V_12 < V_67 )
F_37 ( V_5 + V_12 , V_67 - V_5 - V_12 , V_4 -> V_20 ,
V_68 ) ;
F_26 ( V_4 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_69 )
{
V_4 -> V_20 = V_69 ;
if ( V_69 == V_19 )
V_4 -> V_21 |= V_70 ;
}
static void F_67 ( struct V_3 * V_4 , int V_69 )
{
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
F_66 ( V_4 , V_69 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
static void F_68 ( unsigned long V_5 , int V_69 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_22
L_23 , V_5 ,
( V_69 == V_71 ) ? L_24 :
( V_69 == V_19 ) ? L_25 : L_26 ) ;
return;
}
F_67 ( V_4 , V_69 ) ;
F_26 ( V_4 ) ;
}
static void F_69 ( unsigned long V_5 )
{
F_68 ( V_5 , V_71 ) ;
}
static void F_70 ( unsigned long V_5 )
{
F_68 ( V_5 , V_19 ) ;
}
static void F_71 ( unsigned long V_5 , V_13 V_12 , T_2 V_59 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
V_4 = F_30 ( V_5 , 1 ) ;
if ( ! V_4 ) {
F_18 ( L_27 ,
V_5 ) ;
return;
}
V_50 = F_38 ( V_51 , F_39 ( V_59 ) ) ;
if ( ! V_50 ) {
F_40 ( L_28 ) ;
goto V_66;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( V_5 + V_12 > V_4 -> V_6 + V_4 -> V_12 ) {
F_18 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_25 ( V_51 , V_50 ) ;
goto V_72;
}
F_72 ( & V_50 -> V_39 ) ;
V_50 -> V_35 = V_5 ;
V_50 -> V_12 = V_12 ;
F_73 ( & V_50 -> V_39 , & V_4 -> V_62 ) ;
V_72:
F_62 ( & V_4 -> V_63 , V_21 ) ;
V_66:
F_26 ( V_4 ) ;
}
static void F_74 ( unsigned long V_5 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_30 , V_5 ) ;
return;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
V_4 -> V_21 |= V_70 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_26 ( V_4 ) ;
}
static void T_3 F_75 ( int V_73 , const void * V_5 , V_13 V_12 ,
int V_20 )
{
unsigned long V_21 ;
struct V_74 * log ;
if ( F_60 ( & V_75 ) ) {
V_76 ++ ;
return;
}
if ( V_76 >= F_76 ( V_74 ) ) {
F_41 () ;
return;
}
F_77 ( V_21 ) ;
log = & V_74 [ V_76 ] ;
log -> V_73 = V_73 ;
log -> V_5 = V_5 ;
log -> V_12 = V_12 ;
log -> V_20 = V_20 ;
log -> V_29 = F_35 ( log -> V_30 ) ;
V_76 ++ ;
F_78 ( V_21 ) ;
}
static void F_79 ( struct V_74 * log )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_7 ;
if ( ! F_60 ( & V_77 ) || ! log -> V_5 || F_80 ( log -> V_5 ) )
return;
F_31 () ;
V_4 = F_37 ( ( unsigned long ) log -> V_5 , log -> V_12 ,
log -> V_20 , V_78 ) ;
if ( ! V_4 )
goto V_66;
F_61 ( & V_4 -> V_63 , V_21 ) ;
for ( V_7 = 0 ; V_7 < log -> V_29 ; V_7 ++ )
V_4 -> V_30 [ V_7 ] = log -> V_30 [ V_7 ] ;
V_4 -> V_29 = log -> V_29 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
V_66:
F_34 () ;
}
static void F_81 ( struct V_74 * log )
{
unsigned int V_79 ;
const void T_4 * V_5 = log -> V_5 ;
F_82 (cpu) {
log -> V_5 = F_83 ( V_5 , V_79 ) ;
F_79 ( log ) ;
}
}
void T_5 F_84 ( const void * V_5 , V_13 V_12 , int V_20 ,
T_2 V_59 )
{
F_85 ( L_31 , V_80 , V_5 , V_12 , V_20 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_37 ( ( unsigned long ) V_5 , V_12 , V_20 , V_59 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_82 , V_5 , V_12 , V_20 ) ;
}
void T_5 F_86 ( const void T_4 * V_5 , V_13 V_12 )
{
unsigned int V_79 ;
F_85 ( L_32 , V_80 , V_5 , V_12 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_82 (cpu)
F_37 ( ( unsigned long ) F_83 ( V_5 , V_79 ) ,
V_12 , 0 , V_68 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_83 , V_5 , V_12 , 0 ) ;
}
void T_5 F_87 ( const void * V_5 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_84 , V_5 , 0 , 0 ) ;
}
void T_5 F_88 ( const void * V_5 , V_13 V_12 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_65 ( ( unsigned long ) V_5 , V_12 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_85 , V_5 , V_12 , 0 ) ;
}
void T_5 F_89 ( const void T_4 * V_5 )
{
unsigned int V_79 ;
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_82 (cpu)
F_63 ( ( unsigned long ) F_83 ( V_5 ,
V_79 ) ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_86 , V_5 , 0 , 0 ) ;
}
void T_5 F_90 ( const void * V_5 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_87 , V_5 , 0 , 0 ) ;
}
void T_5 F_91 ( const void * V_5 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_70 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_5 V_49 ( const void * V_5 , V_13 V_12 , T_2 V_59 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && V_12 && ! F_80 ( V_5 ) )
F_71 ( ( unsigned long ) V_5 , V_12 , V_59 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_89 , V_5 , V_12 , 0 ) ;
}
void T_5 F_92 ( const void * V_5 )
{
F_85 ( L_33 , V_80 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_80 ( V_5 ) )
F_74 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_81 ) )
F_75 ( V_90 , V_5 , 0 , 0 ) ;
}
static bool F_93 ( struct V_3 * V_4 )
{
T_6 V_91 = V_4 -> V_36 ;
if ( ! F_94 ( V_4 -> V_6 , V_4 -> V_12 ) )
return false ;
V_4 -> V_36 = F_95 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_12 ) ;
return V_4 -> V_36 != V_91 ;
}
static int F_96 ( void )
{
if ( ! F_60 ( & V_77 ) )
return 1 ;
if ( V_64 -> V_92 )
return F_97 ( V_64 ) ;
else
return F_98 () ;
return 0 ;
}
static void F_99 ( void * V_93 , void * V_94 ,
struct V_3 * V_95 , int V_96 )
{
unsigned long * V_5 ;
unsigned long * V_35 = F_100 ( V_93 , V_97 ) ;
unsigned long * V_67 = V_94 - ( V_97 - 1 ) ;
for ( V_5 = V_35 ; V_5 < V_67 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_21 ;
unsigned long V_6 ;
if ( V_96 )
F_101 () ;
if ( F_96 () )
break;
if ( ! F_94 ( ( unsigned long ) V_5 ,
V_97 ) )
continue;
V_6 = * V_5 ;
V_4 = F_30 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_95 ) {
F_26 ( V_4 ) ;
continue;
}
F_102 ( & V_4 -> V_63 , V_21 ,
V_98 ) ;
if ( ! F_5 ( V_4 ) ) {
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_26 ( V_4 ) ;
continue;
}
V_4 -> V_18 ++ ;
if ( F_6 ( V_4 ) ) {
F_103 ( & V_4 -> V_61 , & V_61 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
continue;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_26 ( V_4 ) ;
}
}
static void F_104 ( struct V_3 * V_4 )
{
struct V_49 * V_50 ;
struct V_46 * V_47 ;
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( V_4 -> V_21 & V_70 )
goto V_66;
if ( ! ( V_4 -> V_21 & V_22 ) )
goto V_66;
if ( F_105 ( & V_4 -> V_62 ) ) {
void * V_35 = ( void * ) V_4 -> V_6 ;
void * V_67 = ( void * ) ( V_4 -> V_6 + V_4 -> V_12 ) ;
while ( V_35 < V_67 && ( V_4 -> V_21 & V_22 ) &&
! ( V_4 -> V_21 & V_70 ) ) {
F_99 ( V_35 , F_2 ( V_35 + V_99 , V_67 ) ,
V_4 , 0 ) ;
V_35 += V_99 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_101 () ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
}
} else
F_106 (area, elem, &object->area_list, node)
F_99 ( ( void * ) V_50 -> V_35 ,
( void * ) ( V_50 -> V_35 + V_50 -> V_12 ) ,
V_4 , 0 ) ;
V_66:
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
static void F_107 ( void )
{
struct V_3 * V_4 , * V_48 ;
V_4 = F_108 ( V_61 . V_100 , F_109 ( * V_4 ) , V_61 ) ;
while ( & V_4 -> V_61 != & V_61 ) {
F_101 () ;
if ( ! F_96 () )
F_104 ( V_4 ) ;
V_48 = F_108 ( V_4 -> V_61 . V_100 , F_109 ( * V_4 ) ,
V_61 ) ;
F_110 ( & V_4 -> V_61 ) ;
F_26 ( V_4 ) ;
V_4 = V_48 ;
}
F_28 ( ! F_111 ( & V_61 ) ) ;
}
static void F_112 ( void )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
int V_7 ;
int V_101 = 0 ;
V_25 = V_23 ;
F_31 () ;
F_113 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
#ifdef F_64
if ( F_60 ( & V_4 -> V_43 ) > 1 ) {
F_85 ( L_34 ,
F_60 ( & V_4 -> V_43 ) ) ;
F_11 ( V_4 ) ;
}
#endif
V_4 -> V_18 = 0 ;
if ( F_6 ( V_4 ) && F_19 ( V_4 ) )
F_103 ( & V_4 -> V_61 , & V_61 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_34 () ;
F_99 ( V_102 , V_103 , NULL , 1 ) ;
F_99 ( V_104 , V_105 , NULL , 1 ) ;
#ifdef F_114
F_82 (i)
F_99 ( V_106 + F_115 ( V_7 ) ,
V_107 + F_115 ( V_7 ) , NULL , 1 ) ;
#endif
F_116 () ;
F_117 (i) {
T_7 * V_108 = F_118 ( V_7 ) ;
unsigned long V_109 = V_108 -> V_110 ;
unsigned long V_111 = V_109 + V_108 -> V_112 ;
unsigned long V_113 ;
for ( V_113 = V_109 ; V_113 < V_111 ; V_113 ++ ) {
struct V_114 * V_114 ;
if ( ! F_119 ( V_113 ) )
continue;
V_114 = F_120 ( V_113 ) ;
if ( F_121 ( V_114 ) == 0 )
continue;
F_99 ( V_114 , V_114 + 1 , NULL , 1 ) ;
}
}
F_122 () ;
if ( V_115 ) {
struct V_116 * V_117 , * V_118 ;
F_123 ( & V_119 ) ;
F_124 (g, p) {
F_99 ( F_125 ( V_117 ) , F_125 ( V_117 ) +
V_120 , NULL , 0 ) ;
} F_126 ( V_118 , V_117 ) ;
F_127 ( & V_119 ) ;
}
F_107 () ;
F_31 () ;
F_113 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( F_5 ( V_4 ) && ( V_4 -> V_21 & V_22 )
&& F_93 ( V_4 ) && F_19 ( V_4 ) ) {
V_4 -> V_18 = V_4 -> V_20 ;
F_103 ( & V_4 -> V_61 , & V_61 ) ;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_34 () ;
F_107 () ;
if ( F_96 () )
return;
F_31 () ;
F_113 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( F_7 ( V_4 ) &&
! ( V_4 -> V_21 & V_121 ) ) {
V_4 -> V_21 |= V_121 ;
V_101 ++ ;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_34 () ;
if ( V_101 )
F_128 ( L_35
L_36 , V_101 ) ;
}
static int F_129 ( void * V_122 )
{
static int V_123 = 1 ;
F_128 ( L_37 ) ;
F_130 ( V_64 , 10 ) ;
if ( V_123 ) {
V_123 = 0 ;
F_131 ( V_124 ) ;
}
while ( ! F_98 () ) {
signed long V_125 = V_126 ;
F_132 ( & V_127 ) ;
F_112 () ;
F_133 ( & V_127 ) ;
while ( V_125 && ! F_98 () )
V_125 = F_134 ( V_125 ) ;
}
F_128 ( L_38 ) ;
return 0 ;
}
static void F_135 ( void )
{
if ( V_128 )
return;
V_128 = F_136 ( F_129 , NULL , L_39 ) ;
if ( F_80 ( V_128 ) ) {
F_40 ( L_40 ) ;
V_128 = NULL ;
}
}
static void F_137 ( void )
{
if ( V_128 ) {
F_138 ( V_128 ) ;
V_128 = NULL ;
}
}
static void * F_139 ( struct V_1 * V_2 , T_8 * V_129 )
{
struct V_3 * V_4 ;
T_8 V_130 = * V_129 ;
int V_131 ;
V_131 = F_140 ( & V_127 ) ;
if ( V_131 < 0 )
return F_141 ( V_131 ) ;
F_31 () ;
F_113 (object, &object_list, object_list) {
if ( V_130 -- > 0 )
continue;
if ( F_19 ( V_4 ) )
goto V_66;
}
V_4 = NULL ;
V_66:
return V_4 ;
}
static void * F_142 ( struct V_1 * V_2 , void * V_132 , T_8 * V_129 )
{
struct V_3 * V_133 = V_132 ;
struct V_3 * V_134 = NULL ;
struct V_135 * V_130 = & V_133 -> V_60 ;
++ ( * V_129 ) ;
F_143 (n, &object_list) {
struct V_3 * V_136 =
F_108 ( V_130 , struct V_3 , V_60 ) ;
if ( F_19 ( V_136 ) ) {
V_134 = V_136 ;
break;
}
}
F_26 ( V_133 ) ;
return V_134 ;
}
static void F_144 ( struct V_1 * V_2 , void * V_132 )
{
if ( ! F_80 ( V_132 ) ) {
F_34 () ;
F_133 ( & V_127 ) ;
if ( V_132 )
F_26 ( V_132 ) ;
}
}
static int F_145 ( struct V_1 * V_2 , void * V_132 )
{
struct V_3 * V_4 = V_132 ;
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( ( V_4 -> V_21 & V_121 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
return 0 ;
}
static int F_146 ( struct V_137 * V_137 , struct V_138 * V_138 )
{
return F_147 ( V_138 , & V_139 ) ;
}
static int F_148 ( struct V_137 * V_137 , struct V_138 * V_138 )
{
return F_149 ( V_137 , V_138 ) ;
}
static int F_150 ( const char * V_140 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
unsigned long V_141 ;
V_141 = F_151 ( V_140 , NULL , 0 ) ;
V_4 = F_30 ( V_141 , 0 ) ;
if ( ! V_4 ) {
F_128 ( L_41 , V_141 ) ;
return - V_142 ;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
F_11 ( V_4 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static void F_152 ( void )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_31 () ;
F_113 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( ( V_4 -> V_21 & V_121 ) &&
F_7 ( V_4 ) )
F_66 ( V_4 , V_71 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_34 () ;
}
static T_9 F_153 ( struct V_138 * V_138 , const char T_10 * V_143 ,
V_13 V_12 , T_8 * V_144 )
{
char V_145 [ 64 ] ;
int V_146 ;
int V_147 ;
if ( ! F_60 ( & V_77 ) )
return - V_148 ;
V_146 = F_2 ( V_12 , ( sizeof( V_145 ) - 1 ) ) ;
if ( F_154 ( V_145 , V_143 , V_146 ) < 0 )
return - V_149 ;
V_145 [ V_146 ] = 0 ;
V_147 = F_140 ( & V_127 ) ;
if ( V_147 < 0 )
return V_147 ;
if ( strncmp ( V_145 , L_42 , 3 ) == 0 )
F_41 () ;
else if ( strncmp ( V_145 , L_43 , 8 ) == 0 )
V_115 = 1 ;
else if ( strncmp ( V_145 , L_44 , 9 ) == 0 )
V_115 = 0 ;
else if ( strncmp ( V_145 , L_45 , 7 ) == 0 )
F_135 () ;
else if ( strncmp ( V_145 , L_46 , 8 ) == 0 )
F_137 () ;
else if ( strncmp ( V_145 , L_47 , 5 ) == 0 ) {
unsigned long V_150 ;
V_147 = F_155 ( V_145 + 5 , 0 , & V_150 ) ;
if ( V_147 < 0 )
goto V_66;
F_137 () ;
if ( V_150 ) {
V_126 = F_156 ( V_150 * 1000 ) ;
F_135 () ;
}
} else if ( strncmp ( V_145 , L_48 , 4 ) == 0 )
F_112 () ;
else if ( strncmp ( V_145 , L_49 , 5 ) == 0 )
F_152 () ;
else if ( strncmp ( V_145 , L_50 , 5 ) == 0 )
V_147 = F_150 ( V_145 + 5 ) ;
else
V_147 = - V_142 ;
V_66:
F_133 ( & V_127 ) ;
if ( V_147 < 0 )
return V_147 ;
* V_144 += V_12 ;
return V_12 ;
}
static void F_157 ( struct V_151 * V_152 )
{
struct V_3 * V_4 ;
bool V_153 = V_128 == NULL ;
F_132 ( & V_127 ) ;
F_137 () ;
if ( V_153 ) {
F_31 () ;
F_113 (object, &object_list, object_list)
F_63 ( V_4 -> V_6 ) ;
F_34 () ;
}
F_133 ( & V_127 ) ;
}
static void F_41 ( void )
{
if ( F_158 ( & V_75 , 0 , 1 ) )
return;
F_45 ( & V_77 , 0 ) ;
if ( F_60 ( & V_154 ) )
F_159 ( & V_155 ) ;
F_128 ( L_51 ) ;
}
static int F_160 ( char * V_140 )
{
if ( ! V_140 )
return - V_142 ;
if ( strcmp ( V_140 , L_42 ) == 0 )
F_41 () ;
else if ( strcmp ( V_140 , L_52 ) == 0 )
V_156 = 1 ;
else
return - V_142 ;
return 0 ;
}
static void T_3 F_161 ( struct V_74 * log )
{
struct V_31 V_30 ;
V_30 . V_32 = log -> V_29 ;
V_30 . V_33 = log -> V_30 ;
F_12 ( L_53 ) ;
F_13 ( & V_30 , 2 ) ;
}
void T_3 F_162 ( void )
{
int V_7 ;
unsigned long V_21 ;
#ifdef F_163
if ( ! V_156 ) {
F_45 ( & V_81 , 0 ) ;
F_41 () ;
return;
}
#endif
V_24 = F_156 ( V_157 ) ;
V_126 = F_156 ( V_158 * 1000 ) ;
V_52 = F_164 ( V_3 , V_159 ) ;
V_51 = F_164 ( V_49 , V_159 ) ;
F_165 ( & V_42 ) ;
if ( V_76 >= F_76 ( V_74 ) )
F_40 ( L_54
L_55 , V_76 ) ;
F_77 ( V_21 ) ;
F_45 ( & V_81 , 0 ) ;
if ( F_60 ( & V_75 ) ) {
F_78 ( V_21 ) ;
return;
} else
F_45 ( & V_77 , 1 ) ;
F_78 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_76 ; V_7 ++ ) {
struct V_74 * log = & V_74 [ V_7 ] ;
switch ( log -> V_73 ) {
case V_82 :
F_79 ( log ) ;
break;
case V_83 :
F_81 ( log ) ;
break;
case V_84 :
F_87 ( log -> V_5 ) ;
break;
case V_85 :
F_88 ( log -> V_5 , log -> V_12 ) ;
break;
case V_86 :
F_89 ( log -> V_5 ) ;
break;
case V_87 :
F_90 ( log -> V_5 ) ;
break;
case V_88 :
F_91 ( log -> V_5 ) ;
break;
case V_89 :
V_49 ( log -> V_5 , log -> V_12 , V_68 ) ;
break;
case V_90 :
F_92 ( log -> V_5 ) ;
break;
default:
F_18 ( L_56 ,
log -> V_73 ) ;
}
if ( F_60 ( & V_160 ) ) {
F_161 ( log ) ;
F_45 ( & V_160 , 0 ) ;
}
}
}
static int T_3 F_166 ( void )
{
struct V_161 * V_161 ;
F_45 ( & V_154 , 1 ) ;
if ( F_60 ( & V_75 ) ) {
F_159 ( & V_155 ) ;
return - V_162 ;
}
V_161 = F_167 ( L_39 , V_163 , NULL , NULL ,
& V_164 ) ;
if ( ! V_161 )
F_40 ( L_57 ) ;
F_132 ( & V_127 ) ;
F_135 () ;
F_133 ( & V_127 ) ;
F_128 ( L_58 ) ;
return 0 ;
}
