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
if ( V_5 >= V_52 && V_5 < V_53 )
V_4 = F_14 ( V_5 , V_35 ) ;
F_31 ( & V_51 , V_21 ) ;
if ( V_4 && ! F_17 ( V_4 ) )
V_4 = NULL ;
F_32 () ;
return V_4 ;
}
static int F_33 ( unsigned long * V_30 )
{
struct V_31 V_31 ;
V_31 . V_54 = V_55 ;
V_31 . V_32 = 0 ;
V_31 . V_33 = V_30 ;
V_31 . V_56 = 2 ;
F_34 ( & V_31 ) ;
return V_31 . V_32 ;
}
static struct V_3 * F_35 ( unsigned long V_5 , V_13 V_12 ,
int V_20 , T_2 V_57 )
{
unsigned long V_21 ;
struct V_3 * V_4 , * V_58 ;
struct V_36 * * V_59 , * V_60 ;
V_4 = F_36 ( V_50 , F_37 ( V_57 ) ) ;
if ( ! V_4 ) {
F_38 ( L_14 ) ;
F_39 () ;
return NULL ;
}
F_40 ( & V_4 -> V_61 ) ;
F_40 ( & V_4 -> V_62 ) ;
F_41 ( & V_4 -> V_63 ) ;
F_42 ( & V_4 -> V_64 ) ;
F_43 ( & V_4 -> V_41 , 1 ) ;
V_4 -> V_21 = V_22 ;
V_4 -> V_6 = V_5 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = 0 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_34 = 0 ;
if ( F_44 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_15 , sizeof( V_4 -> V_27 ) ) ;
} else if ( F_45 () ) {
V_4 -> V_28 = 0 ;
strncpy ( V_4 -> V_27 , L_16 , sizeof( V_4 -> V_27 ) ) ;
} else {
V_4 -> V_28 = V_65 -> V_28 ;
strncpy ( V_4 -> V_27 , V_65 -> V_27 , sizeof( V_4 -> V_27 ) ) ;
}
V_4 -> V_29 = F_33 ( V_4 -> V_30 ) ;
F_46 ( & V_51 , V_21 ) ;
V_52 = F_2 ( V_52 , V_5 ) ;
V_53 = F_47 ( V_53 , V_5 + V_12 ) ;
V_59 = & V_38 . V_36 ;
V_60 = NULL ;
while ( * V_59 ) {
V_60 = * V_59 ;
V_58 = F_15 ( V_60 , struct V_3 , V_36 ) ;
if ( V_5 + V_12 <= V_58 -> V_6 )
V_59 = & V_58 -> V_36 . V_39 ;
else if ( V_58 -> V_6 + V_58 -> V_12 <= V_5 )
V_59 = & V_58 -> V_36 . V_40 ;
else {
F_48 ( L_17
L_18 ,
V_5 ) ;
F_23 ( V_50 , V_4 ) ;
V_4 = V_58 ;
F_49 ( & V_4 -> V_64 ) ;
F_11 ( V_4 ) ;
F_50 ( & V_4 -> V_64 ) ;
goto V_66;
}
}
F_51 ( & V_4 -> V_36 , V_60 , V_59 ) ;
F_52 ( & V_4 -> V_36 , & V_38 ) ;
F_53 ( & V_4 -> V_61 , & V_61 ) ;
V_66:
F_54 ( & V_51 , V_21 ) ;
return V_4 ;
}
static void F_55 ( struct V_3 * V_4 )
{
unsigned long V_21 ;
F_46 ( & V_51 , V_21 ) ;
F_56 ( & V_4 -> V_36 , & V_38 ) ;
F_57 ( & V_4 -> V_61 ) ;
F_54 ( & V_51 , V_21 ) ;
F_26 ( ! ( V_4 -> V_21 & V_22 ) ) ;
F_26 ( F_58 ( & V_4 -> V_41 ) < 2 ) ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
V_4 -> V_21 &= ~ V_22 ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
}
static void F_61 ( unsigned long V_5 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
#ifdef F_62
F_16 ( L_19 ,
V_5 ) ;
#endif
return;
}
F_55 ( V_4 ) ;
F_24 ( V_4 ) ;
}
static void F_63 ( unsigned long V_5 , V_13 V_12 )
{
struct V_3 * V_4 ;
unsigned long V_67 , V_68 ;
V_4 = F_28 ( V_5 , 1 ) ;
if ( ! V_4 ) {
#ifdef F_62
F_16 ( L_20
L_21 , V_5 , V_12 ) ;
#endif
return;
}
F_55 ( V_4 ) ;
V_67 = V_4 -> V_6 ;
V_68 = V_4 -> V_6 + V_4 -> V_12 ;
if ( V_5 > V_67 )
F_35 ( V_67 , V_5 - V_67 , V_4 -> V_20 ,
V_69 ) ;
if ( V_5 + V_12 < V_68 )
F_35 ( V_5 + V_12 , V_68 - V_5 - V_12 , V_4 -> V_20 ,
V_69 ) ;
F_24 ( V_4 ) ;
}
static void F_64 ( struct V_3 * V_4 , int V_70 )
{
V_4 -> V_20 = V_70 ;
if ( V_70 == V_19 )
V_4 -> V_21 |= V_71 ;
}
static void F_65 ( struct V_3 * V_4 , int V_70 )
{
unsigned long V_21 ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
F_64 ( V_4 , V_70 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
static void F_66 ( unsigned long V_5 , int V_70 )
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
F_65 ( V_4 , V_70 ) ;
F_24 ( V_4 ) ;
}
static void F_67 ( unsigned long V_5 )
{
F_66 ( V_5 , V_72 ) ;
}
static void F_68 ( unsigned long V_5 )
{
F_66 ( V_5 , V_19 ) ;
}
static void F_69 ( unsigned long V_5 , V_13 V_12 , T_2 V_57 )
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
V_47 = F_36 ( V_49 , F_37 ( V_57 ) ) ;
if ( ! V_47 ) {
F_38 ( L_28 ) ;
goto V_66;
}
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( V_5 + V_12 > V_4 -> V_6 + V_4 -> V_12 ) {
F_16 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_23 ( V_49 , V_47 ) ;
goto V_73;
}
F_70 ( & V_47 -> V_48 ) ;
V_47 -> V_67 = V_5 ;
V_47 -> V_12 = V_12 ;
F_71 ( & V_47 -> V_48 , & V_4 -> V_63 ) ;
V_73:
F_60 ( & V_4 -> V_64 , V_21 ) ;
V_66:
F_24 ( V_4 ) ;
}
static void F_72 ( unsigned long V_5 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
V_4 = F_28 ( V_5 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_30 , V_5 ) ;
return;
}
F_59 ( & V_4 -> V_64 , V_21 ) ;
V_4 -> V_21 |= V_71 ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
}
static void T_3 F_73 ( int V_74 , const void * V_5 , V_13 V_12 ,
int V_20 )
{
unsigned long V_21 ;
struct V_75 * log ;
if ( F_58 ( & V_76 ) ) {
V_77 ++ ;
return;
}
if ( V_77 >= F_74 ( V_75 ) ) {
F_39 () ;
return;
}
F_75 ( V_21 ) ;
log = & V_75 [ V_77 ] ;
log -> V_74 = V_74 ;
log -> V_5 = V_5 ;
log -> V_12 = V_12 ;
log -> V_20 = V_20 ;
log -> V_29 = F_33 ( log -> V_30 ) ;
V_77 ++ ;
F_76 ( V_21 ) ;
}
static void F_77 ( struct V_75 * log )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_7 ;
if ( ! F_58 ( & V_78 ) || ! log -> V_5 || F_78 ( log -> V_5 ) )
return;
F_29 () ;
V_4 = F_35 ( ( unsigned long ) log -> V_5 , log -> V_12 ,
log -> V_20 , V_79 ) ;
if ( ! V_4 )
goto V_66;
F_59 ( & V_4 -> V_64 , V_21 ) ;
for ( V_7 = 0 ; V_7 < log -> V_29 ; V_7 ++ )
V_4 -> V_30 [ V_7 ] = log -> V_30 [ V_7 ] ;
V_4 -> V_29 = log -> V_29 ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
V_66:
F_32 () ;
}
static void F_79 ( struct V_75 * log )
{
unsigned int V_80 ;
const void T_4 * V_5 = log -> V_5 ;
F_80 (cpu) {
log -> V_5 = F_81 ( V_5 , V_80 ) ;
F_77 ( log ) ;
}
}
void T_5 F_82 ( const void * V_5 , V_13 V_12 , int V_20 ,
T_2 V_57 )
{
F_83 ( L_31 , V_81 , V_5 , V_12 , V_20 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_35 ( ( unsigned long ) V_5 , V_12 , V_20 , V_57 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_83 , V_5 , V_12 , V_20 ) ;
}
void T_5 F_84 ( const void T_4 * V_5 , V_13 V_12 )
{
unsigned int V_80 ;
F_83 ( L_32 , V_81 , V_5 , V_12 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_35 ( ( unsigned long ) F_81 ( V_5 , V_80 ) ,
V_12 , 0 , V_69 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_84 , V_5 , V_12 , 0 ) ;
}
void T_5 F_85 ( const void * V_5 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_61 ( ( unsigned long ) V_5 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_85 , V_5 , 0 , 0 ) ;
}
void T_5 F_86 ( const void * V_5 , V_13 V_12 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 , V_12 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_86 , V_5 , V_12 , 0 ) ;
}
void T_5 F_87 ( const void T_4 * V_5 )
{
unsigned int V_80 ;
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_61 ( ( unsigned long ) F_81 ( V_5 ,
V_80 ) ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_87 , V_5 , 0 , 0 ) ;
}
void T_5 F_88 ( const void * V_5 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_67 ( ( unsigned long ) V_5 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_5 F_89 ( const void * V_5 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_68 ( ( unsigned long ) V_5 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_89 , V_5 , 0 , 0 ) ;
}
void T_5 V_46 ( const void * V_5 , V_13 V_12 , T_2 V_57 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && V_12 && ! F_78 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 , V_12 , V_57 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_90 , V_5 , V_12 , 0 ) ;
}
void T_5 F_90 ( const void * V_5 )
{
F_83 ( L_33 , V_81 , V_5 ) ;
if ( F_58 ( & V_78 ) && V_5 && ! F_78 ( V_5 ) )
F_72 ( ( unsigned long ) V_5 ) ;
else if ( F_58 ( & V_82 ) )
F_73 ( V_91 , V_5 , 0 , 0 ) ;
}
static bool F_91 ( struct V_3 * V_4 )
{
T_6 V_92 = V_4 -> V_34 ;
if ( ! F_92 ( V_4 -> V_6 , V_4 -> V_12 ) )
return false ;
V_4 -> V_34 = F_93 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_12 ) ;
return V_4 -> V_34 != V_92 ;
}
static int F_94 ( void )
{
if ( ! F_58 ( & V_78 ) )
return 1 ;
if ( V_65 -> V_93 )
return F_95 ( V_65 ) ;
else
return F_96 () ;
return 0 ;
}
static void F_97 ( void * V_94 , void * V_95 ,
struct V_3 * V_96 , int V_97 )
{
unsigned long * V_5 ;
unsigned long * V_67 = F_98 ( V_94 , V_98 ) ;
unsigned long * V_68 = V_95 - ( V_98 - 1 ) ;
for ( V_5 = V_67 ; V_5 < V_68 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_21 ;
unsigned long V_6 ;
if ( V_97 )
F_99 () ;
if ( F_94 () )
break;
if ( ! F_92 ( ( unsigned long ) V_5 ,
V_98 ) )
continue;
V_6 = * V_5 ;
V_4 = F_28 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_96 ) {
F_24 ( V_4 ) ;
continue;
}
F_100 ( & V_4 -> V_64 , V_21 ,
V_99 ) ;
if ( ! F_5 ( V_4 ) ) {
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
continue;
}
V_4 -> V_18 ++ ;
if ( F_6 ( V_4 ) ) {
F_101 ( & V_4 -> V_62 , & V_62 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
continue;
}
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
}
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_46 * V_47 ;
unsigned long V_21 ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( V_4 -> V_21 & V_71 )
goto V_66;
if ( ! ( V_4 -> V_21 & V_22 ) )
goto V_66;
if ( F_103 ( & V_4 -> V_63 ) ) {
void * V_67 = ( void * ) V_4 -> V_6 ;
void * V_68 = ( void * ) ( V_4 -> V_6 + V_4 -> V_12 ) ;
while ( V_67 < V_68 && ( V_4 -> V_21 & V_22 ) &&
! ( V_4 -> V_21 & V_71 ) ) {
F_97 ( V_67 , F_2 ( V_67 + V_100 , V_68 ) ,
V_4 , 0 ) ;
V_67 += V_100 ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_99 () ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
}
} else
F_104 (area, &object->area_list, node)
F_97 ( ( void * ) V_47 -> V_67 ,
( void * ) ( V_47 -> V_67 + V_47 -> V_12 ) ,
V_4 , 0 ) ;
V_66:
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
static void F_105 ( void )
{
struct V_3 * V_4 , * V_45 ;
V_4 = F_106 ( V_62 . V_101 , F_107 ( * V_4 ) , V_62 ) ;
while ( & V_4 -> V_62 != & V_62 ) {
F_99 () ;
if ( ! F_94 () )
F_102 ( V_4 ) ;
V_45 = F_106 ( V_4 -> V_62 . V_101 , F_107 ( * V_4 ) ,
V_62 ) ;
F_108 ( & V_4 -> V_62 ) ;
F_24 ( V_4 ) ;
V_4 = V_45 ;
}
F_26 ( ! F_109 ( & V_62 ) ) ;
}
static void F_110 ( void )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
int V_7 ;
int V_102 = 0 ;
V_25 = V_23 ;
F_29 () ;
F_111 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_64 , V_21 ) ;
#ifdef F_62
if ( F_58 ( & V_4 -> V_41 ) > 1 ) {
F_83 ( L_34 ,
F_58 ( & V_4 -> V_41 ) ) ;
F_11 ( V_4 ) ;
}
#endif
V_4 -> V_18 = 0 ;
if ( F_6 ( V_4 ) && F_17 ( V_4 ) )
F_101 ( & V_4 -> V_62 , & V_62 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
F_97 ( V_103 , V_104 , NULL , 1 ) ;
F_97 ( V_105 , V_106 , NULL , 1 ) ;
#ifdef F_112
F_80 (i)
F_97 ( V_107 + F_113 ( V_7 ) ,
V_108 + F_113 ( V_7 ) , NULL , 1 ) ;
#endif
F_114 () ;
F_115 (i) {
unsigned long V_109 = F_116 ( V_7 ) ;
unsigned long V_110 = F_117 ( V_7 ) ;
unsigned long V_111 ;
for ( V_111 = V_109 ; V_111 < V_110 ; V_111 ++ ) {
struct V_112 * V_112 ;
if ( ! F_118 ( V_111 ) )
continue;
V_112 = F_119 ( V_111 ) ;
if ( F_120 ( V_112 ) == 0 )
continue;
F_97 ( V_112 , V_112 + 1 , NULL , 1 ) ;
}
}
F_121 () ;
if ( V_113 ) {
struct V_114 * V_115 , * V_116 ;
F_122 ( & V_117 ) ;
F_123 (g, p) {
F_97 ( F_124 ( V_115 ) , F_124 ( V_115 ) +
V_118 , NULL , 0 ) ;
} F_125 ( V_116 , V_115 ) ;
F_126 ( & V_117 ) ;
}
F_105 () ;
F_29 () ;
F_111 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( F_5 ( V_4 ) && ( V_4 -> V_21 & V_22 )
&& F_91 ( V_4 ) && F_17 ( V_4 ) ) {
V_4 -> V_18 = V_4 -> V_20 ;
F_101 ( & V_4 -> V_62 , & V_62 ) ;
}
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
F_105 () ;
if ( F_94 () )
return;
F_29 () ;
F_111 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( F_7 ( V_4 ) &&
! ( V_4 -> V_21 & V_119 ) ) {
V_4 -> V_21 |= V_119 ;
V_102 ++ ;
}
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
if ( V_102 )
F_127 ( L_35
L_36 , V_102 ) ;
}
static int F_128 ( void * V_120 )
{
static int V_121 = 1 ;
F_127 ( L_37 ) ;
F_129 ( V_65 , 10 ) ;
if ( V_121 ) {
V_121 = 0 ;
F_130 ( V_122 ) ;
}
while ( ! F_96 () ) {
signed long V_123 = V_124 ;
F_131 ( & V_125 ) ;
F_110 () ;
F_132 ( & V_125 ) ;
while ( V_123 && ! F_96 () )
V_123 = F_133 ( V_123 ) ;
}
F_127 ( L_38 ) ;
return 0 ;
}
static void F_134 ( void )
{
if ( V_126 )
return;
V_126 = F_135 ( F_128 , NULL , L_39 ) ;
if ( F_78 ( V_126 ) ) {
F_38 ( L_40 ) ;
V_126 = NULL ;
}
}
static void F_136 ( void )
{
if ( V_126 ) {
F_137 ( V_126 ) ;
V_126 = NULL ;
}
}
static void * F_138 ( struct V_1 * V_2 , T_7 * V_127 )
{
struct V_3 * V_4 ;
T_7 V_128 = * V_127 ;
int V_129 ;
V_129 = F_139 ( & V_125 ) ;
if ( V_129 < 0 )
return F_140 ( V_129 ) ;
F_29 () ;
F_111 (object, &object_list, object_list) {
if ( V_128 -- > 0 )
continue;
if ( F_17 ( V_4 ) )
goto V_66;
}
V_4 = NULL ;
V_66:
return V_4 ;
}
static void * F_141 ( struct V_1 * V_2 , void * V_130 , T_7 * V_127 )
{
struct V_3 * V_131 = V_130 ;
struct V_3 * V_132 = NULL ;
struct V_3 * V_133 = V_131 ;
++ ( * V_127 ) ;
F_142 (obj, &object_list, object_list) {
if ( F_17 ( V_133 ) ) {
V_132 = V_133 ;
break;
}
}
F_24 ( V_131 ) ;
return V_132 ;
}
static void F_143 ( struct V_1 * V_2 , void * V_130 )
{
if ( ! F_78 ( V_130 ) ) {
F_32 () ;
F_132 ( & V_125 ) ;
if ( V_130 )
F_24 ( V_130 ) ;
}
}
static int F_144 ( struct V_1 * V_2 , void * V_130 )
{
struct V_3 * V_4 = V_130 ;
unsigned long V_21 ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( ( V_4 -> V_21 & V_119 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
return 0 ;
}
static int F_145 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
return F_146 ( V_135 , & V_136 ) ;
}
static int F_147 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
return F_148 ( V_134 , V_135 ) ;
}
static int F_149 ( const char * V_137 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
unsigned long V_138 ;
if ( F_150 ( V_137 , 0 , & V_138 ) )
return - V_139 ;
V_4 = F_28 ( V_138 , 0 ) ;
if ( ! V_4 ) {
F_127 ( L_41 , V_138 ) ;
return - V_139 ;
}
F_59 ( & V_4 -> V_64 , V_21 ) ;
F_11 ( V_4 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static void F_151 ( void )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_29 () ;
F_111 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( ( V_4 -> V_21 & V_119 ) &&
F_7 ( V_4 ) )
F_64 ( V_4 , V_72 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
}
static T_8 F_152 ( struct V_135 * V_135 , const char T_9 * V_140 ,
V_13 V_12 , T_7 * V_141 )
{
char V_142 [ 64 ] ;
int V_143 ;
int V_144 ;
if ( ! F_58 ( & V_78 ) )
return - V_145 ;
V_143 = F_2 ( V_12 , ( sizeof( V_142 ) - 1 ) ) ;
if ( F_153 ( V_142 , V_140 , V_143 ) < 0 )
return - V_146 ;
V_142 [ V_143 ] = 0 ;
V_144 = F_139 ( & V_125 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( strncmp ( V_142 , L_42 , 3 ) == 0 )
F_39 () ;
else if ( strncmp ( V_142 , L_43 , 8 ) == 0 )
V_113 = 1 ;
else if ( strncmp ( V_142 , L_44 , 9 ) == 0 )
V_113 = 0 ;
else if ( strncmp ( V_142 , L_45 , 7 ) == 0 )
F_134 () ;
else if ( strncmp ( V_142 , L_46 , 8 ) == 0 )
F_136 () ;
else if ( strncmp ( V_142 , L_47 , 5 ) == 0 ) {
unsigned long V_147 ;
V_144 = F_150 ( V_142 + 5 , 0 , & V_147 ) ;
if ( V_144 < 0 )
goto V_66;
F_136 () ;
if ( V_147 ) {
V_124 = F_154 ( V_147 * 1000 ) ;
F_134 () ;
}
} else if ( strncmp ( V_142 , L_48 , 4 ) == 0 )
F_110 () ;
else if ( strncmp ( V_142 , L_49 , 5 ) == 0 )
F_151 () ;
else if ( strncmp ( V_142 , L_50 , 5 ) == 0 )
V_144 = F_149 ( V_142 + 5 ) ;
else
V_144 = - V_139 ;
V_66:
F_132 ( & V_125 ) ;
if ( V_144 < 0 )
return V_144 ;
* V_141 += V_12 ;
return V_12 ;
}
static void F_155 ( struct V_148 * V_149 )
{
struct V_3 * V_4 ;
bool V_150 = V_126 == NULL ;
F_131 ( & V_125 ) ;
F_136 () ;
if ( V_150 ) {
F_29 () ;
F_111 (object, &object_list, object_list)
F_61 ( V_4 -> V_6 ) ;
F_32 () ;
}
F_132 ( & V_125 ) ;
}
static void F_39 ( void )
{
if ( F_156 ( & V_76 , 0 , 1 ) )
return;
F_43 ( & V_78 , 0 ) ;
if ( F_58 ( & V_151 ) )
F_157 ( & V_152 ) ;
F_127 ( L_51 ) ;
}
static int F_158 ( char * V_137 )
{
if ( ! V_137 )
return - V_139 ;
if ( strcmp ( V_137 , L_42 ) == 0 )
F_39 () ;
else if ( strcmp ( V_137 , L_52 ) == 0 )
V_153 = 1 ;
else
return - V_139 ;
return 0 ;
}
static void T_3 F_159 ( struct V_75 * log )
{
struct V_31 V_30 ;
V_30 . V_32 = log -> V_29 ;
V_30 . V_33 = log -> V_30 ;
F_12 ( L_53 ) ;
F_13 ( & V_30 , 2 ) ;
}
void T_3 F_160 ( void )
{
int V_7 ;
unsigned long V_21 ;
#ifdef F_161
if ( ! V_153 ) {
F_43 ( & V_82 , 0 ) ;
F_39 () ;
return;
}
#endif
V_24 = F_154 ( V_154 ) ;
V_124 = F_154 ( V_155 * 1000 ) ;
V_50 = F_162 ( V_3 , V_156 ) ;
V_49 = F_162 ( V_46 , V_156 ) ;
if ( V_77 >= F_74 ( V_75 ) )
F_38 ( L_54
L_55 , V_77 ) ;
F_75 ( V_21 ) ;
F_43 ( & V_82 , 0 ) ;
if ( F_58 ( & V_76 ) ) {
F_76 ( V_21 ) ;
return;
} else
F_43 ( & V_78 , 1 ) ;
F_76 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_77 ; V_7 ++ ) {
struct V_75 * log = & V_75 [ V_7 ] ;
switch ( log -> V_74 ) {
case V_83 :
F_77 ( log ) ;
break;
case V_84 :
F_79 ( log ) ;
break;
case V_85 :
F_85 ( log -> V_5 ) ;
break;
case V_86 :
F_86 ( log -> V_5 , log -> V_12 ) ;
break;
case V_87 :
F_87 ( log -> V_5 ) ;
break;
case V_88 :
F_88 ( log -> V_5 ) ;
break;
case V_89 :
F_89 ( log -> V_5 ) ;
break;
case V_90 :
V_46 ( log -> V_5 , log -> V_12 , V_69 ) ;
break;
case V_91 :
F_90 ( log -> V_5 ) ;
break;
default:
F_16 ( L_56 ,
log -> V_74 ) ;
}
if ( F_58 ( & V_157 ) ) {
F_159 ( log ) ;
F_43 ( & V_157 , 0 ) ;
}
}
}
static int T_3 F_163 ( void )
{
struct V_158 * V_158 ;
F_43 ( & V_151 , 1 ) ;
if ( F_58 ( & V_76 ) ) {
F_157 ( & V_152 ) ;
return - V_159 ;
}
V_158 = F_164 ( L_39 , V_160 , NULL , NULL ,
& V_161 ) ;
if ( ! V_158 )
F_38 ( L_57 ) ;
F_131 ( & V_125 ) ;
F_134 () ;
F_132 ( & V_125 ) ;
F_127 ( L_58 ) ;
return 0 ;
}
