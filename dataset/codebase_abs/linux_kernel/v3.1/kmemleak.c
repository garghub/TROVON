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
F_18 ( L_13 , V_5 ) ;
F_19 () ;
F_11 ( V_4 ) ;
V_4 = NULL ;
}
} else
V_4 = NULL ;
return V_4 ;
}
static int F_20 ( struct V_3 * V_4 )
{
return F_21 ( & V_4 -> V_43 ) ;
}
static void F_22 ( struct V_44 * V_45 )
{
struct V_46 * V_47 , * V_48 ;
struct V_49 * V_50 ;
struct V_3 * V_4 =
F_23 ( V_45 , struct V_3 , V_45 ) ;
F_24 (area, elem, tmp, &object->area_list, node) {
F_25 ( V_47 ) ;
F_26 ( V_51 , V_50 ) ;
}
F_26 ( V_52 , V_4 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
if ( ! F_28 ( & V_4 -> V_43 ) )
return;
F_29 ( V_4 -> V_21 & V_22 ) ;
F_30 ( & V_4 -> V_45 , F_22 ) ;
}
static struct V_3 * F_31 ( unsigned long V_5 , int V_37 )
{
unsigned long V_21 ;
struct V_3 * V_4 = NULL ;
F_32 () ;
F_33 ( & V_53 , V_21 ) ;
if ( V_5 >= V_54 && V_5 < V_55 )
V_4 = F_14 ( V_5 , V_37 ) ;
F_34 ( & V_53 , V_21 ) ;
if ( V_4 && ! F_20 ( V_4 ) )
V_4 = NULL ;
F_35 () ;
return V_4 ;
}
static int F_36 ( unsigned long * V_30 )
{
struct V_31 V_31 ;
V_31 . V_56 = V_57 ;
V_31 . V_32 = 0 ;
V_31 . V_33 = V_30 ;
V_31 . V_58 = 2 ;
F_37 ( & V_31 ) ;
return V_31 . V_32 ;
}
static struct V_3 * F_38 ( unsigned long V_5 , V_13 V_12 ,
int V_20 , T_2 V_59 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
V_4 = F_39 ( V_52 , F_40 ( V_59 ) ) ;
if ( ! V_4 ) {
F_18 ( L_14 ) ;
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
V_4 -> V_29 = F_36 ( V_4 -> V_30 ) ;
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
F_29 ( ! ( V_4 -> V_21 & V_22 ) ) ;
F_29 ( F_60 ( & V_4 -> V_43 ) < 2 ) ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
V_4 -> V_21 &= ~ V_22 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_27 ( V_4 ) ;
}
static void F_63 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_65 ( L_19 ,
V_5 ) ;
#endif
return;
}
F_57 ( V_4 ) ;
F_27 ( V_4 ) ;
}
static void F_66 ( unsigned long V_5 , V_13 V_12 )
{
struct V_3 * V_4 ;
unsigned long V_35 , V_67 ;
V_4 = F_31 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_65 ( L_20
L_21 , V_5 , V_12 ) ;
#endif
return;
}
F_57 ( V_4 ) ;
V_35 = V_4 -> V_6 ;
V_67 = V_4 -> V_6 + V_4 -> V_12 ;
if ( V_5 > V_35 )
F_38 ( V_35 , V_5 - V_35 , V_4 -> V_20 ,
V_68 ) ;
if ( V_5 + V_12 < V_67 )
F_38 ( V_5 + V_12 , V_67 - V_5 - V_12 , V_4 -> V_20 ,
V_68 ) ;
F_27 ( V_4 ) ;
}
static void F_67 ( struct V_3 * V_4 , int V_69 )
{
V_4 -> V_20 = V_69 ;
if ( V_69 == V_19 )
V_4 -> V_21 |= V_70 ;
}
static void F_68 ( struct V_3 * V_4 , int V_69 )
{
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
F_67 ( V_4 , V_69 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
static void F_69 ( unsigned long V_5 , int V_69 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_65 ( L_22
L_23 , V_5 ,
( V_69 == V_71 ) ? L_24 :
( V_69 == V_19 ) ? L_25 : L_26 ) ;
return;
}
F_68 ( V_4 , V_69 ) ;
F_27 ( V_4 ) ;
}
static void F_70 ( unsigned long V_5 )
{
F_69 ( V_5 , V_71 ) ;
}
static void F_71 ( unsigned long V_5 )
{
F_69 ( V_5 , V_19 ) ;
}
static void F_72 ( unsigned long V_5 , V_13 V_12 , T_2 V_59 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
V_4 = F_31 ( V_5 , 1 ) ;
if ( ! V_4 ) {
F_65 ( L_27 ,
V_5 ) ;
return;
}
V_50 = F_39 ( V_51 , F_40 ( V_59 ) ) ;
if ( ! V_50 ) {
F_18 ( L_28 ) ;
goto V_66;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( V_5 + V_12 > V_4 -> V_6 + V_4 -> V_12 ) {
F_65 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_26 ( V_51 , V_50 ) ;
goto V_72;
}
F_73 ( & V_50 -> V_39 ) ;
V_50 -> V_35 = V_5 ;
V_50 -> V_12 = V_12 ;
F_74 ( & V_50 -> V_39 , & V_4 -> V_62 ) ;
V_72:
F_62 ( & V_4 -> V_63 , V_21 ) ;
V_66:
F_27 ( V_4 ) ;
}
static void F_75 ( unsigned long V_5 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
V_4 = F_31 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_65 ( L_30 , V_5 ) ;
return;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
V_4 -> V_21 |= V_70 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_27 ( V_4 ) ;
}
static void T_3 F_76 ( int V_73 , const void * V_5 , V_13 V_12 ,
int V_20 )
{
unsigned long V_21 ;
struct V_74 * log ;
if ( V_75 >= F_77 ( V_74 ) ) {
F_18 ( L_31
L_32 ) ;
F_41 () ;
return;
}
F_78 ( V_21 ) ;
log = & V_74 [ V_75 ] ;
log -> V_73 = V_73 ;
log -> V_5 = V_5 ;
log -> V_12 = V_12 ;
log -> V_20 = V_20 ;
if ( V_73 == V_76 )
log -> V_29 = F_36 ( log -> V_30 ) ;
V_75 ++ ;
F_79 ( V_21 ) ;
}
static void F_80 ( struct V_74 * log )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_7 ;
if ( ! F_60 ( & V_77 ) || ! log -> V_5 || F_81 ( log -> V_5 ) )
return;
F_32 () ;
V_4 = F_38 ( ( unsigned long ) log -> V_5 , log -> V_12 ,
log -> V_20 , V_78 ) ;
if ( ! V_4 )
goto V_66;
F_61 ( & V_4 -> V_63 , V_21 ) ;
for ( V_7 = 0 ; V_7 < log -> V_29 ; V_7 ++ )
V_4 -> V_30 [ V_7 ] = log -> V_30 [ V_7 ] ;
V_4 -> V_29 = log -> V_29 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
V_66:
F_35 () ;
}
void T_4 F_82 ( const void * V_5 , V_13 V_12 , int V_20 ,
T_2 V_59 )
{
F_83 ( L_33 , V_79 , V_5 , V_12 , V_20 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_38 ( ( unsigned long ) V_5 , V_12 , V_20 , V_59 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_76 , V_5 , V_12 , V_20 ) ;
}
void T_4 F_84 ( const void * V_5 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_81 , V_5 , 0 , 0 ) ;
}
void T_4 F_85 ( const void * V_5 , V_13 V_12 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_66 ( ( unsigned long ) V_5 , V_12 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_82 , V_5 , V_12 , 0 ) ;
}
void T_4 F_86 ( const void * V_5 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_70 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_83 , V_5 , 0 , 0 ) ;
}
void T_4 F_87 ( const void * V_5 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_71 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_84 , V_5 , 0 , 0 ) ;
}
void T_4 V_49 ( const void * V_5 , V_13 V_12 , T_2 V_59 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_72 ( ( unsigned long ) V_5 , V_12 , V_59 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_85 , V_5 , V_12 , 0 ) ;
}
void T_4 F_88 ( const void * V_5 )
{
F_83 ( L_34 , V_79 , V_5 ) ;
if ( F_60 ( & V_77 ) && V_5 && ! F_81 ( V_5 ) )
F_75 ( ( unsigned long ) V_5 ) ;
else if ( F_60 ( & V_80 ) )
F_76 ( V_86 , V_5 , 0 , 0 ) ;
}
static bool F_89 ( struct V_3 * V_4 )
{
T_5 V_87 = V_4 -> V_36 ;
if ( ! F_90 ( V_4 -> V_6 , V_4 -> V_12 ) )
return false ;
V_4 -> V_36 = F_91 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_12 ) ;
return V_4 -> V_36 != V_87 ;
}
static int F_92 ( void )
{
if ( ! F_60 ( & V_77 ) )
return 1 ;
if ( V_64 -> V_88 )
return F_93 ( V_64 ) ;
else
return F_94 () ;
return 0 ;
}
static void F_95 ( void * V_89 , void * V_90 ,
struct V_3 * V_91 , int V_92 )
{
unsigned long * V_5 ;
unsigned long * V_35 = F_96 ( V_89 , V_93 ) ;
unsigned long * V_67 = V_90 - ( V_93 - 1 ) ;
for ( V_5 = V_35 ; V_5 < V_67 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_21 ;
unsigned long V_6 ;
if ( V_92 )
F_97 () ;
if ( F_92 () )
break;
if ( ! F_90 ( ( unsigned long ) V_5 ,
V_93 ) )
continue;
V_6 = * V_5 ;
V_4 = F_31 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_91 ) {
F_27 ( V_4 ) ;
continue;
}
F_98 ( & V_4 -> V_63 , V_21 ,
V_94 ) ;
if ( ! F_5 ( V_4 ) ) {
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_27 ( V_4 ) ;
continue;
}
V_4 -> V_18 ++ ;
if ( F_6 ( V_4 ) ) {
F_99 ( & V_4 -> V_61 , & V_61 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
continue;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_27 ( V_4 ) ;
}
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_49 * V_50 ;
struct V_46 * V_47 ;
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( V_4 -> V_21 & V_70 )
goto V_66;
if ( ! ( V_4 -> V_21 & V_22 ) )
goto V_66;
if ( F_101 ( & V_4 -> V_62 ) ) {
void * V_35 = ( void * ) V_4 -> V_6 ;
void * V_67 = ( void * ) ( V_4 -> V_6 + V_4 -> V_12 ) ;
while ( V_35 < V_67 && ( V_4 -> V_21 & V_22 ) &&
! ( V_4 -> V_21 & V_70 ) ) {
F_95 ( V_35 , F_2 ( V_35 + V_95 , V_67 ) ,
V_4 , 0 ) ;
V_35 += V_95 ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_97 () ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
}
} else
F_102 (area, elem, &object->area_list, node)
F_95 ( ( void * ) V_50 -> V_35 ,
( void * ) ( V_50 -> V_35 + V_50 -> V_12 ) ,
V_4 , 0 ) ;
V_66:
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
static void F_103 ( void )
{
struct V_3 * V_4 , * V_48 ;
V_4 = F_104 ( V_61 . V_96 , F_105 ( * V_4 ) , V_61 ) ;
while ( & V_4 -> V_61 != & V_61 ) {
F_97 () ;
if ( ! F_92 () )
F_100 ( V_4 ) ;
V_48 = F_104 ( V_4 -> V_61 . V_96 , F_105 ( * V_4 ) ,
V_61 ) ;
F_106 ( & V_4 -> V_61 ) ;
F_27 ( V_4 ) ;
V_4 = V_48 ;
}
F_29 ( ! F_107 ( & V_61 ) ) ;
}
static void F_108 ( void )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
int V_7 ;
int V_97 = 0 ;
V_25 = V_23 ;
F_32 () ;
F_109 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
#ifdef F_64
if ( F_60 ( & V_4 -> V_43 ) > 1 ) {
F_83 ( L_35 ,
F_60 ( & V_4 -> V_43 ) ) ;
F_11 ( V_4 ) ;
}
#endif
V_4 -> V_18 = 0 ;
if ( F_6 ( V_4 ) && F_20 ( V_4 ) )
F_99 ( & V_4 -> V_61 , & V_61 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_35 () ;
F_95 ( V_98 , V_99 , NULL , 1 ) ;
F_95 ( V_100 , V_101 , NULL , 1 ) ;
#ifdef F_110
F_111 (i)
F_95 ( V_102 + F_112 ( V_7 ) ,
V_103 + F_112 ( V_7 ) , NULL , 1 ) ;
#endif
F_113 (i) {
T_6 * V_104 = F_114 ( V_7 ) ;
unsigned long V_105 = V_104 -> V_106 ;
unsigned long V_107 = V_105 + V_104 -> V_108 ;
unsigned long V_109 ;
for ( V_109 = V_105 ; V_109 < V_107 ; V_109 ++ ) {
struct V_110 * V_110 ;
if ( ! F_115 ( V_109 ) )
continue;
V_110 = F_116 ( V_109 ) ;
if ( F_117 ( V_110 ) == 0 )
continue;
F_95 ( V_110 , V_110 + 1 , NULL , 1 ) ;
}
}
if ( V_111 ) {
struct V_112 * V_113 , * V_114 ;
F_118 ( & V_115 ) ;
F_119 (g, p) {
F_95 ( F_120 ( V_113 ) , F_120 ( V_113 ) +
V_116 , NULL , 0 ) ;
} F_121 ( V_114 , V_113 ) ;
F_122 ( & V_115 ) ;
}
F_103 () ;
F_32 () ;
F_109 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( F_5 ( V_4 ) && ( V_4 -> V_21 & V_22 )
&& F_89 ( V_4 ) && F_20 ( V_4 ) ) {
V_4 -> V_18 = V_4 -> V_20 ;
F_99 ( & V_4 -> V_61 , & V_61 ) ;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_35 () ;
F_103 () ;
if ( F_92 () )
return;
F_32 () ;
F_109 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( F_7 ( V_4 ) &&
! ( V_4 -> V_21 & V_117 ) ) {
V_4 -> V_21 |= V_117 ;
V_97 ++ ;
}
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_35 () ;
if ( V_97 )
F_123 ( L_36
L_37 , V_97 ) ;
}
static int F_124 ( void * V_118 )
{
static int V_119 = 1 ;
F_123 ( L_38 ) ;
F_125 ( V_64 , 10 ) ;
if ( V_119 ) {
V_119 = 0 ;
F_126 ( V_120 ) ;
}
while ( ! F_94 () ) {
signed long V_121 = V_122 ;
F_127 ( & V_123 ) ;
F_108 () ;
F_128 ( & V_123 ) ;
while ( V_121 && ! F_94 () )
V_121 = F_129 ( V_121 ) ;
}
F_123 ( L_39 ) ;
return 0 ;
}
static void F_130 ( void )
{
if ( V_124 )
return;
V_124 = F_131 ( F_124 , NULL , L_40 ) ;
if ( F_81 ( V_124 ) ) {
F_18 ( L_41 ) ;
V_124 = NULL ;
}
}
static void F_132 ( void )
{
if ( V_124 ) {
F_133 ( V_124 ) ;
V_124 = NULL ;
}
}
static void * F_134 ( struct V_1 * V_2 , T_7 * V_125 )
{
struct V_3 * V_4 ;
T_7 V_126 = * V_125 ;
int V_127 ;
V_127 = F_135 ( & V_123 ) ;
if ( V_127 < 0 )
return F_136 ( V_127 ) ;
F_32 () ;
F_109 (object, &object_list, object_list) {
if ( V_126 -- > 0 )
continue;
if ( F_20 ( V_4 ) )
goto V_66;
}
V_4 = NULL ;
V_66:
return V_4 ;
}
static void * F_137 ( struct V_1 * V_2 , void * V_128 , T_7 * V_125 )
{
struct V_3 * V_129 = V_128 ;
struct V_3 * V_130 = NULL ;
struct V_131 * V_126 = & V_129 -> V_60 ;
++ ( * V_125 ) ;
F_138 (n, &object_list) {
struct V_3 * V_132 =
F_104 ( V_126 , struct V_3 , V_60 ) ;
if ( F_20 ( V_132 ) ) {
V_130 = V_132 ;
break;
}
}
F_27 ( V_129 ) ;
return V_130 ;
}
static void F_139 ( struct V_1 * V_2 , void * V_128 )
{
if ( ! F_81 ( V_128 ) ) {
F_35 () ;
F_128 ( & V_123 ) ;
if ( V_128 )
F_27 ( V_128 ) ;
}
}
static int F_140 ( struct V_1 * V_2 , void * V_128 )
{
struct V_3 * V_4 = V_128 ;
unsigned long V_21 ;
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( ( V_4 -> V_21 & V_117 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
return 0 ;
}
static int F_141 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
if ( ! F_60 ( & V_77 ) )
return - V_135 ;
return F_142 ( V_134 , & V_136 ) ;
}
static int F_143 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_144 ( V_133 , V_134 ) ;
}
static int F_145 ( const char * V_137 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
unsigned long V_138 ;
V_138 = F_146 ( V_137 , NULL , 0 ) ;
V_4 = F_31 ( V_138 , 0 ) ;
if ( ! V_4 ) {
F_123 ( L_42 , V_138 ) ;
return - V_139 ;
}
F_61 ( & V_4 -> V_63 , V_21 ) ;
F_11 ( V_4 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static void F_147 ( void )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_32 () ;
F_109 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_63 , V_21 ) ;
if ( ( V_4 -> V_21 & V_117 ) &&
F_7 ( V_4 ) )
F_67 ( V_4 , V_71 ) ;
F_62 ( & V_4 -> V_63 , V_21 ) ;
}
F_35 () ;
}
static T_8 F_148 ( struct V_134 * V_134 , const char T_9 * V_140 ,
V_13 V_12 , T_7 * V_141 )
{
char V_142 [ 64 ] ;
int V_143 ;
int V_144 ;
V_143 = F_2 ( V_12 , ( sizeof( V_142 ) - 1 ) ) ;
if ( F_149 ( V_142 , V_140 , V_143 ) < 0 )
return - V_145 ;
V_142 [ V_143 ] = 0 ;
V_144 = F_135 ( & V_123 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( strncmp ( V_142 , L_43 , 3 ) == 0 )
F_41 () ;
else if ( strncmp ( V_142 , L_44 , 8 ) == 0 )
V_111 = 1 ;
else if ( strncmp ( V_142 , L_45 , 9 ) == 0 )
V_111 = 0 ;
else if ( strncmp ( V_142 , L_46 , 7 ) == 0 )
F_130 () ;
else if ( strncmp ( V_142 , L_47 , 8 ) == 0 )
F_132 () ;
else if ( strncmp ( V_142 , L_48 , 5 ) == 0 ) {
unsigned long V_146 ;
V_144 = F_150 ( V_142 + 5 , 0 , & V_146 ) ;
if ( V_144 < 0 )
goto V_66;
F_132 () ;
if ( V_146 ) {
V_122 = F_151 ( V_146 * 1000 ) ;
F_130 () ;
}
} else if ( strncmp ( V_142 , L_49 , 4 ) == 0 )
F_108 () ;
else if ( strncmp ( V_142 , L_50 , 5 ) == 0 )
F_147 () ;
else if ( strncmp ( V_142 , L_51 , 5 ) == 0 )
V_144 = F_145 ( V_142 + 5 ) ;
else
V_144 = - V_139 ;
V_66:
F_128 ( & V_123 ) ;
if ( V_144 < 0 )
return V_144 ;
* V_141 += V_12 ;
return V_12 ;
}
static void F_152 ( struct V_147 * V_148 )
{
struct V_3 * V_4 ;
F_127 ( & V_123 ) ;
F_132 () ;
F_32 () ;
F_109 (object, &object_list, object_list)
F_63 ( V_4 -> V_6 ) ;
F_35 () ;
F_128 ( & V_123 ) ;
}
static void F_41 ( void )
{
if ( F_153 ( & V_149 , 0 , 1 ) )
return;
F_45 ( & V_80 , 0 ) ;
F_45 ( & V_77 , 0 ) ;
if ( F_60 ( & V_150 ) )
F_154 ( & V_151 ) ;
F_123 ( L_52 ) ;
}
static int F_155 ( char * V_137 )
{
if ( ! V_137 )
return - V_139 ;
if ( strcmp ( V_137 , L_43 ) == 0 )
F_41 () ;
else if ( strcmp ( V_137 , L_53 ) == 0 )
V_152 = 1 ;
else
return - V_139 ;
return 0 ;
}
void T_3 F_156 ( void )
{
int V_7 ;
unsigned long V_21 ;
#ifdef F_157
if ( ! V_152 ) {
F_41 () ;
return;
}
#endif
V_24 = F_151 ( V_153 ) ;
V_122 = F_151 ( V_154 * 1000 ) ;
V_52 = F_158 ( V_3 , V_155 ) ;
V_51 = F_158 ( V_49 , V_155 ) ;
F_159 ( & V_42 ) ;
F_78 ( V_21 ) ;
if ( ! F_60 ( & V_149 ) ) {
F_45 ( & V_77 , 1 ) ;
F_45 ( & V_80 , 0 ) ;
}
F_79 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_75 ; V_7 ++ ) {
struct V_74 * log = & V_74 [ V_7 ] ;
switch ( log -> V_73 ) {
case V_76 :
F_80 ( log ) ;
break;
case V_81 :
F_84 ( log -> V_5 ) ;
break;
case V_82 :
F_85 ( log -> V_5 , log -> V_12 ) ;
break;
case V_83 :
F_86 ( log -> V_5 ) ;
break;
case V_84 :
F_87 ( log -> V_5 ) ;
break;
case V_85 :
V_49 ( log -> V_5 , log -> V_12 , V_68 ) ;
break;
case V_86 :
F_88 ( log -> V_5 ) ;
break;
default:
F_29 ( 1 ) ;
}
}
}
static int T_3 F_160 ( void )
{
struct V_156 * V_156 ;
F_45 ( & V_150 , 1 ) ;
if ( F_60 ( & V_149 ) ) {
F_154 ( & V_151 ) ;
return - V_157 ;
}
V_156 = F_161 ( L_40 , V_158 , NULL , NULL ,
& V_159 ) ;
if ( ! V_156 )
F_18 ( L_54 ) ;
F_127 ( & V_123 ) ;
F_130 () ;
F_128 ( & V_123 ) ;
F_123 ( L_55 ) ;
return 0 ;
}
