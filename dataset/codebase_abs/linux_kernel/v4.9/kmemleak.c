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
V_4 -> V_25 = V_60 -> V_25 ;
strncpy ( V_4 -> V_24 , V_60 -> V_24 , sizeof( V_4 -> V_24 ) ) ;
}
V_4 -> V_26 = F_40 ( V_4 -> V_27 ) ;
F_36 ( & V_48 , V_17 ) ;
V_61 = F_53 ( V_61 , V_5 ) ;
V_62 = F_54 ( V_62 , V_5 + V_8 ) ;
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
goto V_63;
}
}
F_56 ( & V_4 -> V_33 , V_56 , V_55 ) ;
F_57 ( & V_4 -> V_33 , & V_35 ) ;
F_58 ( & V_4 -> V_49 , & V_49 ) ;
V_63:
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
unsigned long V_64 , V_65 ;
V_4 = F_35 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_19 ,
V_5 , V_8 ) ;
#endif
return;
}
V_64 = V_4 -> V_6 ;
V_65 = V_4 -> V_6 + V_4 -> V_8 ;
if ( V_5 > V_64 )
F_42 ( V_64 , V_5 - V_64 , V_4 -> V_16 ,
V_66 ) ;
if ( V_5 + V_8 < V_65 )
F_42 ( V_5 + V_8 , V_65 - V_5 - V_8 , V_4 -> V_16 ,
V_66 ) ;
F_59 ( V_4 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_67 )
{
V_4 -> V_16 = V_67 ;
if ( V_67 == V_15 )
V_4 -> V_17 |= V_68 ;
}
static void F_67 ( struct V_3 * V_4 , int V_67 )
{
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
F_66 ( V_4 , V_67 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_68 ( unsigned long V_5 , int V_67 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_20 ,
V_5 ,
( V_67 == V_69 ) ? L_21 :
( V_67 == V_15 ) ? L_22 : L_23 ) ;
return;
}
F_67 ( V_4 , V_67 ) ;
F_26 ( V_4 ) ;
}
static void F_69 ( unsigned long V_5 )
{
F_68 ( V_5 , V_69 ) ;
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
goto V_63;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( V_8 == V_70 ) {
V_8 = V_4 -> V_6 + V_4 -> V_8 - V_5 ;
} else if ( V_5 + V_8 > V_4 -> V_6 + V_4 -> V_8 ) {
F_18 ( L_26 , V_5 ) ;
F_13 ( V_4 ) ;
F_25 ( V_46 , V_44 ) ;
goto V_71;
}
F_72 ( & V_44 -> V_45 ) ;
V_44 -> V_64 = V_5 ;
V_44 -> V_8 = V_8 ;
F_73 ( & V_44 -> V_45 , & V_4 -> V_58 ) ;
V_71:
F_62 ( & V_4 -> V_59 , V_17 ) ;
V_63:
F_26 ( V_4 ) ;
}
static void F_74 ( unsigned long V_5 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
V_4 = F_30 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_18 ( L_27 , V_5 ) ;
return;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_17 |= V_68 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
static void T_4 F_75 ( int V_72 , const void * V_5 , T_2 V_8 ,
int V_16 )
{
unsigned long V_17 ;
struct V_73 * log ;
if ( V_74 ) {
V_75 ++ ;
return;
}
if ( V_75 >= F_76 ( V_73 ) ) {
V_75 ++ ;
F_46 () ;
return;
}
F_77 ( V_17 ) ;
log = & V_73 [ V_75 ] ;
log -> V_72 = V_72 ;
log -> V_5 = V_5 ;
log -> V_8 = V_8 ;
log -> V_16 = V_16 ;
log -> V_26 = F_40 ( log -> V_27 ) ;
V_75 ++ ;
F_78 ( V_17 ) ;
}
static void F_79 ( struct V_73 * log )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_22 ;
if ( ! V_76 || ! log -> V_5 || F_80 ( log -> V_5 ) )
return;
F_31 () ;
V_4 = F_42 ( ( unsigned long ) log -> V_5 , log -> V_8 ,
log -> V_16 , V_77 ) ;
if ( ! V_4 )
goto V_63;
F_61 ( & V_4 -> V_59 , V_17 ) ;
for ( V_22 = 0 ; V_22 < log -> V_26 ; V_22 ++ )
V_4 -> V_27 [ V_22 ] = log -> V_27 [ V_22 ] ;
V_4 -> V_26 = log -> V_26 ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
V_63:
F_34 () ;
}
static void F_81 ( struct V_73 * log )
{
unsigned int V_78 ;
const void T_5 * V_5 = log -> V_5 ;
F_82 (cpu) {
log -> V_5 = F_83 ( V_5 , V_78 ) ;
F_79 ( log ) ;
}
}
void T_6 F_84 ( const void * V_5 , T_2 V_8 , int V_16 ,
T_3 V_53 )
{
F_85 ( L_28 , V_79 , V_5 , V_8 , V_16 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_42 ( ( unsigned long ) V_5 , V_8 , V_16 , V_53 ) ;
else if ( V_80 )
F_75 ( V_81 , V_5 , V_8 , V_16 ) ;
}
void T_6 F_86 ( const void T_5 * V_5 , T_2 V_8 ,
T_3 V_53 )
{
unsigned int V_78 ;
F_85 ( L_29 , V_79 , V_5 , V_8 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_82 (cpu)
F_42 ( ( unsigned long ) F_83 ( V_5 , V_78 ) ,
V_8 , 0 , V_53 ) ;
else if ( V_80 )
F_75 ( V_82 , V_5 , V_8 , 0 ) ;
}
void T_6 F_87 ( const void * V_5 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_83 && V_5 && ! F_80 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_75 ( V_84 , V_5 , 0 , 0 ) ;
}
void T_6 F_88 ( const void * V_5 , T_2 V_8 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_65 ( ( unsigned long ) V_5 , V_8 ) ;
else if ( V_80 )
F_75 ( V_85 , V_5 , V_8 , 0 ) ;
}
void T_6 F_89 ( const void T_5 * V_5 )
{
unsigned int V_78 ;
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_83 && V_5 && ! F_80 ( V_5 ) )
F_82 (cpu)
F_63 ( ( unsigned long ) F_83 ( V_5 ,
V_78 ) ) ;
else if ( V_80 )
F_75 ( V_86 , V_5 , 0 , 0 ) ;
}
void T_6 F_90 ( const void * V_5 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_85 ( L_30 , V_79 , V_5 ) ;
if ( ! V_76 || F_91 ( V_5 ) )
return;
V_4 = F_30 ( ( unsigned long ) V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_64
F_18 ( L_31 ,
V_5 ) ;
#endif
return;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
V_4 -> V_26 = F_40 ( V_4 -> V_27 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
}
void T_6 F_92 ( const void * V_5 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_75 ( V_87 , V_5 , 0 , 0 ) ;
}
void T_6 F_93 ( const void * V_5 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_70 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_75 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_6 V_43 ( const void * V_5 , T_2 V_8 , T_3 V_53 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_76 && V_5 && V_8 && ! F_80 ( V_5 ) )
F_71 ( ( unsigned long ) V_5 , V_8 , V_53 ) ;
else if ( V_80 )
F_75 ( V_89 , V_5 , V_8 , 0 ) ;
}
void T_6 F_94 ( const void * V_5 )
{
F_85 ( L_30 , V_79 , V_5 ) ;
if ( V_76 && V_5 && ! F_80 ( V_5 ) )
F_74 ( ( unsigned long ) V_5 ) ;
else if ( V_80 )
F_75 ( V_90 , V_5 , 0 , 0 ) ;
}
void T_6 F_95 ( T_7 V_91 , T_2 V_8 , int V_16 ,
T_3 V_53 )
{
if ( ! F_96 ( V_92 ) || F_97 ( V_91 ) < V_93 )
F_84 ( F_98 ( V_91 ) , V_8 , V_16 , V_53 ) ;
}
void T_6 F_99 ( T_7 V_91 , T_2 V_8 )
{
if ( ! F_96 ( V_92 ) || F_97 ( V_91 ) < V_93 )
F_88 ( F_98 ( V_91 ) , V_8 ) ;
}
void T_6 F_100 ( T_7 V_91 )
{
if ( ! F_96 ( V_92 ) || F_97 ( V_91 ) < V_93 )
F_92 ( F_98 ( V_91 ) ) ;
}
void T_6 F_101 ( T_7 V_91 )
{
if ( ! F_96 ( V_92 ) || F_97 ( V_91 ) < V_93 )
F_93 ( F_98 ( V_91 ) ) ;
}
static bool F_102 ( struct V_3 * V_4 )
{
T_8 V_94 = V_4 -> V_31 ;
if ( ! F_103 ( V_4 -> V_6 , V_4 -> V_8 ) )
return false ;
F_4 () ;
V_4 -> V_31 = F_104 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_8 ) ;
F_6 () ;
return V_4 -> V_31 != V_94 ;
}
static int F_105 ( void )
{
if ( ! V_76 )
return 1 ;
if ( V_60 -> V_95 )
return F_106 ( V_60 ) ;
else
return F_107 () ;
return 0 ;
}
static void F_108 ( void * V_96 , void * V_97 ,
struct V_3 * V_98 )
{
unsigned long * V_5 ;
unsigned long * V_64 = F_109 ( V_96 , V_99 ) ;
unsigned long * V_65 = V_97 - ( V_99 - 1 ) ;
unsigned long V_17 ;
F_32 ( & V_48 , V_17 ) ;
for ( V_5 = V_64 ; V_5 < V_65 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_6 ;
if ( F_105 () )
break;
if ( ! F_103 ( ( unsigned long ) V_5 ,
V_99 ) )
continue;
F_4 () ;
V_6 = * V_5 ;
F_6 () ;
if ( V_6 < V_61 || V_6 >= V_62 )
continue;
V_4 = F_16 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_98 )
continue;
F_110 ( & V_4 -> V_59 , V_100 ) ;
if ( ! F_7 ( V_4 ) ) {
F_111 ( & V_4 -> V_59 ) ;
continue;
}
V_4 -> V_14 ++ ;
if ( F_8 ( V_4 ) ) {
F_28 ( ! F_19 ( V_4 ) ) ;
F_112 ( & V_4 -> V_57 , & V_57 ) ;
}
F_111 ( & V_4 -> V_59 ) ;
}
F_33 ( & V_48 , V_17 ) ;
}
static void F_113 ( void * V_64 , void * V_65 )
{
void * V_101 ;
while ( V_64 < V_65 ) {
V_101 = F_53 ( V_64 + V_102 , V_65 ) ;
F_108 ( V_64 , V_101 , NULL ) ;
V_64 = V_101 ;
F_114 () ;
}
}
static void F_115 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( V_4 -> V_17 & V_68 )
goto V_63;
if ( ! ( V_4 -> V_17 & V_18 ) )
goto V_63;
if ( F_116 ( & V_4 -> V_58 ) ) {
void * V_64 = ( void * ) V_4 -> V_6 ;
void * V_65 = ( void * ) ( V_4 -> V_6 + V_4 -> V_8 ) ;
void * V_101 ;
do {
V_101 = F_53 ( V_64 + V_102 , V_65 ) ;
F_108 ( V_64 , V_101 , V_4 ) ;
V_64 = V_101 ;
if ( V_64 >= V_65 )
break;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_114 () ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
} while ( V_4 -> V_17 & V_18 );
} else
F_117 (area, &object->area_list, node)
F_108 ( ( void * ) V_44 -> V_64 ,
( void * ) ( V_44 -> V_64 + V_44 -> V_8 ) ,
V_4 ) ;
V_63:
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
static void F_118 ( void )
{
struct V_3 * V_4 , * V_42 ;
V_4 = F_119 ( V_57 . V_101 , F_120 ( * V_4 ) , V_57 ) ;
while ( & V_4 -> V_57 != & V_57 ) {
F_114 () ;
if ( ! F_105 () )
F_115 ( V_4 ) ;
V_42 = F_119 ( V_4 -> V_57 . V_101 , F_120 ( * V_4 ) ,
V_57 ) ;
F_121 ( & V_4 -> V_57 ) ;
F_26 ( V_4 ) ;
V_4 = V_42 ;
}
F_28 ( ! F_122 ( & V_57 ) ) ;
}
static void F_123 ( void )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
int V_22 ;
int V_103 = 0 ;
V_21 = V_19 ;
F_31 () ;
F_124 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
#ifdef F_64
if ( F_60 ( & V_4 -> V_38 ) > 1 ) {
F_85 ( L_32 ,
F_60 ( & V_4 -> V_38 ) ) ;
F_13 ( V_4 ) ;
}
#endif
V_4 -> V_14 = 0 ;
if ( F_8 ( V_4 ) && F_19 ( V_4 ) )
F_112 ( & V_4 -> V_57 , & V_57 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
F_113 ( V_104 , V_105 ) ;
F_113 ( V_106 , V_107 ) ;
F_113 ( V_108 , V_109 ) ;
#ifdef F_125
F_82 (i)
F_113 ( V_110 + F_126 ( V_22 ) ,
V_111 + F_126 ( V_22 ) ) ;
#endif
F_127 () ;
F_128 (i) {
unsigned long V_112 = F_129 ( V_22 ) ;
unsigned long V_113 = F_130 ( V_22 ) ;
unsigned long V_114 ;
for ( V_114 = V_112 ; V_114 < V_113 ; V_114 ++ ) {
struct V_115 * V_115 ;
if ( ! F_131 ( V_114 ) )
continue;
V_115 = F_132 ( V_114 ) ;
if ( F_133 ( V_115 ) == 0 )
continue;
F_108 ( V_115 , V_115 + 1 , NULL ) ;
}
}
F_134 () ;
if ( V_116 ) {
struct V_117 * V_118 , * V_119 ;
F_135 ( & V_120 ) ;
F_136 (g, p) {
void * V_121 = F_137 ( V_118 ) ;
if ( V_121 ) {
F_108 ( V_121 , V_121 + V_122 , NULL ) ;
F_138 ( V_118 ) ;
}
} F_139 ( V_119 , V_118 ) ;
F_140 ( & V_120 ) ;
}
F_118 () ;
F_31 () ;
F_124 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( F_7 ( V_4 ) && ( V_4 -> V_17 & V_18 )
&& F_102 ( V_4 ) && F_19 ( V_4 ) ) {
V_4 -> V_14 = V_4 -> V_16 ;
F_112 ( & V_4 -> V_57 , & V_57 ) ;
}
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
F_118 () ;
if ( F_105 () )
return;
F_31 () ;
F_124 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( F_9 ( V_4 ) &&
! ( V_4 -> V_17 & V_123 ) ) {
V_4 -> V_17 |= V_123 ;
V_103 ++ ;
}
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
if ( V_103 ) {
V_124 = true ;
F_141 ( L_33 ,
V_103 ) ;
}
}
static int F_142 ( void * V_125 )
{
static int V_126 = 1 ;
F_141 ( L_34 ) ;
F_143 ( V_60 , 10 ) ;
if ( V_126 ) {
signed long V_127 = F_144 ( V_128 * 1000 ) ;
V_126 = 0 ;
while ( V_127 && ! F_107 () )
V_127 = F_145 ( V_127 ) ;
}
while ( ! F_107 () ) {
signed long V_127 = V_129 ;
F_146 ( & V_130 ) ;
F_123 () ;
F_147 ( & V_130 ) ;
while ( V_127 && ! F_107 () )
V_127 = F_145 ( V_127 ) ;
}
F_141 ( L_35 ) ;
return 0 ;
}
static void F_148 ( void )
{
if ( V_131 )
return;
V_131 = F_149 ( F_142 , NULL , L_36 ) ;
if ( F_80 ( V_131 ) ) {
F_45 ( L_37 ) ;
V_131 = NULL ;
}
}
static void F_150 ( void )
{
if ( V_131 ) {
F_151 ( V_131 ) ;
V_131 = NULL ;
}
}
static void * F_152 ( struct V_1 * V_2 , T_9 * V_132 )
{
struct V_3 * V_4 ;
T_9 V_133 = * V_132 ;
int V_134 ;
V_134 = F_153 ( & V_130 ) ;
if ( V_134 < 0 )
return F_154 ( V_134 ) ;
F_31 () ;
F_124 (object, &object_list, object_list) {
if ( V_133 -- > 0 )
continue;
if ( F_19 ( V_4 ) )
goto V_63;
}
V_4 = NULL ;
V_63:
return V_4 ;
}
static void * F_155 ( struct V_1 * V_2 , void * V_135 , T_9 * V_132 )
{
struct V_3 * V_136 = V_135 ;
struct V_3 * V_137 = NULL ;
struct V_3 * V_138 = V_136 ;
++ ( * V_132 ) ;
F_156 (obj, &object_list, object_list) {
if ( F_19 ( V_138 ) ) {
V_137 = V_138 ;
break;
}
}
F_26 ( V_136 ) ;
return V_137 ;
}
static void F_157 ( struct V_1 * V_2 , void * V_135 )
{
if ( ! F_80 ( V_135 ) ) {
F_34 () ;
F_147 ( & V_130 ) ;
if ( V_135 )
F_26 ( V_135 ) ;
}
}
static int F_158 ( struct V_1 * V_2 , void * V_135 )
{
struct V_3 * V_4 = V_135 ;
unsigned long V_17 ;
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_123 ) && F_9 ( V_4 ) )
F_11 ( V_2 , V_4 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
return 0 ;
}
static int F_159 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
return F_160 ( V_140 , & V_141 ) ;
}
static int F_161 ( const char * V_142 )
{
unsigned long V_17 ;
struct V_3 * V_4 ;
unsigned long V_143 ;
if ( F_162 ( V_142 , 0 , & V_143 ) )
return - V_144 ;
V_4 = F_30 ( V_143 , 0 ) ;
if ( ! V_4 ) {
F_141 ( L_38 , V_143 ) ;
return - V_144 ;
}
F_61 ( & V_4 -> V_59 , V_17 ) ;
F_13 ( V_4 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static void F_163 ( void )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
F_31 () ;
F_124 (object, &object_list, object_list) {
F_61 ( & V_4 -> V_59 , V_17 ) ;
if ( ( V_4 -> V_17 & V_123 ) &&
F_9 ( V_4 ) )
F_66 ( V_4 , V_69 ) ;
F_62 ( & V_4 -> V_59 , V_17 ) ;
}
F_34 () ;
V_124 = false ;
}
static T_10 F_164 ( struct V_140 * V_140 , const char T_11 * V_145 ,
T_2 V_8 , T_9 * V_146 )
{
char V_147 [ 64 ] ;
int V_148 ;
int V_149 ;
V_148 = F_53 ( V_8 , ( sizeof( V_147 ) - 1 ) ) ;
if ( F_165 ( V_147 , V_145 , V_148 ) < 0 )
return - V_150 ;
V_147 [ V_148 ] = 0 ;
V_149 = F_153 ( & V_130 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( strncmp ( V_147 , L_39 , 5 ) == 0 ) {
if ( V_76 )
F_163 () ;
else
F_166 () ;
goto V_63;
}
if ( ! V_76 ) {
V_149 = - V_151 ;
goto V_63;
}
if ( strncmp ( V_147 , L_40 , 3 ) == 0 )
F_46 () ;
else if ( strncmp ( V_147 , L_41 , 8 ) == 0 )
V_116 = 1 ;
else if ( strncmp ( V_147 , L_42 , 9 ) == 0 )
V_116 = 0 ;
else if ( strncmp ( V_147 , L_43 , 7 ) == 0 )
F_148 () ;
else if ( strncmp ( V_147 , L_44 , 8 ) == 0 )
F_150 () ;
else if ( strncmp ( V_147 , L_45 , 5 ) == 0 ) {
unsigned long V_152 ;
V_149 = F_162 ( V_147 + 5 , 0 , & V_152 ) ;
if ( V_149 < 0 )
goto V_63;
F_150 () ;
if ( V_152 ) {
V_129 = F_144 ( V_152 * 1000 ) ;
F_148 () ;
}
} else if ( strncmp ( V_147 , L_46 , 4 ) == 0 )
F_123 () ;
else if ( strncmp ( V_147 , L_47 , 5 ) == 0 )
V_149 = F_161 ( V_147 + 5 ) ;
else
V_149 = - V_144 ;
V_63:
F_147 ( & V_130 ) ;
if ( V_149 < 0 )
return V_149 ;
* V_146 += V_8 ;
return V_8 ;
}
static void F_166 ( void )
{
struct V_3 * V_4 ;
F_31 () ;
F_124 (object, &object_list, object_list)
F_63 ( V_4 -> V_6 ) ;
F_34 () ;
}
static void F_167 ( struct V_153 * V_154 )
{
F_150 () ;
V_83 = 0 ;
if ( ! V_124 )
F_166 () ;
else
F_141 ( L_48 ) ;
}
static void F_46 ( void )
{
if ( F_168 ( & V_74 , 0 , 1 ) )
return;
V_76 = 0 ;
if ( V_155 )
F_169 ( & V_156 ) ;
else
V_83 = 0 ;
F_141 ( L_49 ) ;
}
static int F_170 ( char * V_142 )
{
if ( ! V_142 )
return - V_144 ;
if ( strcmp ( V_142 , L_40 ) == 0 )
F_46 () ;
else if ( strcmp ( V_142 , L_50 ) == 0 )
V_157 = 1 ;
else
return - V_144 ;
return 0 ;
}
static void T_4 F_171 ( struct V_73 * log )
{
struct V_28 V_27 ;
V_27 . V_29 = log -> V_26 ;
V_27 . V_30 = log -> V_27 ;
F_14 ( L_51 ) ;
F_15 ( & V_27 , 2 ) ;
}
void T_4 F_172 ( void )
{
int V_22 ;
unsigned long V_17 ;
#ifdef F_173
if ( ! V_157 ) {
V_80 = 0 ;
F_46 () ;
return;
}
#endif
V_20 = F_144 ( V_158 ) ;
V_129 = F_144 ( V_159 * 1000 ) ;
V_47 = F_174 ( V_3 , V_160 ) ;
V_46 = F_174 ( V_43 , V_160 ) ;
if ( V_75 > F_76 ( V_73 ) )
F_45 ( L_52 ,
V_75 ) ;
F_77 ( V_17 ) ;
V_80 = 0 ;
if ( V_74 ) {
F_78 ( V_17 ) ;
return;
} else {
V_76 = 1 ;
V_83 = 1 ;
}
F_78 ( V_17 ) ;
for ( V_22 = 0 ; V_22 < V_75 ; V_22 ++ ) {
struct V_73 * log = & V_73 [ V_22 ] ;
switch ( log -> V_72 ) {
case V_81 :
F_79 ( log ) ;
break;
case V_82 :
F_81 ( log ) ;
break;
case V_84 :
F_87 ( log -> V_5 ) ;
break;
case V_85 :
F_88 ( log -> V_5 , log -> V_8 ) ;
break;
case V_86 :
F_89 ( log -> V_5 ) ;
break;
case V_87 :
F_92 ( log -> V_5 ) ;
break;
case V_88 :
F_93 ( log -> V_5 ) ;
break;
case V_89 :
V_43 ( log -> V_5 , log -> V_8 , V_66 ) ;
break;
case V_90 :
F_94 ( log -> V_5 ) ;
break;
default:
F_18 ( L_53 ,
log -> V_72 ) ;
}
if ( V_161 ) {
F_171 ( log ) ;
V_161 = 0 ;
}
}
}
static int T_4 F_175 ( void )
{
struct V_162 * V_162 ;
V_155 = 1 ;
if ( V_74 ) {
F_169 ( & V_156 ) ;
return - V_163 ;
}
V_162 = F_176 ( L_36 , V_164 , NULL , NULL ,
& V_165 ) ;
if ( ! V_162 )
F_45 ( L_54 ) ;
F_146 ( & V_130 ) ;
F_148 () ;
F_147 ( & V_130 ) ;
F_141 ( L_55 ) ;
return 0 ;
}
