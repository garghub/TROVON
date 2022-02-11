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
if ( V_12 == V_73 ) {
V_12 = V_4 -> V_6 + V_4 -> V_12 - V_5 ;
} else if ( V_5 + V_12 > V_4 -> V_6 + V_4 -> V_12 ) {
F_16 ( L_29 , V_5 ) ;
F_11 ( V_4 ) ;
F_23 ( V_49 , V_47 ) ;
goto V_74;
}
F_70 ( & V_47 -> V_48 ) ;
V_47 -> V_67 = V_5 ;
V_47 -> V_12 = V_12 ;
F_71 ( & V_47 -> V_48 , & V_4 -> V_63 ) ;
V_74:
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
static void T_3 F_73 ( int V_75 , const void * V_5 , V_13 V_12 ,
int V_20 )
{
unsigned long V_21 ;
struct V_76 * log ;
if ( V_77 ) {
V_78 ++ ;
return;
}
if ( V_78 >= F_74 ( V_76 ) ) {
F_39 () ;
return;
}
F_75 ( V_21 ) ;
log = & V_76 [ V_78 ] ;
log -> V_75 = V_75 ;
log -> V_5 = V_5 ;
log -> V_12 = V_12 ;
log -> V_20 = V_20 ;
log -> V_29 = F_33 ( log -> V_30 ) ;
V_78 ++ ;
F_76 ( V_21 ) ;
}
static void F_77 ( struct V_76 * log )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_7 ;
if ( ! V_79 || ! log -> V_5 || F_78 ( log -> V_5 ) )
return;
F_29 () ;
V_4 = F_35 ( ( unsigned long ) log -> V_5 , log -> V_12 ,
log -> V_20 , V_80 ) ;
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
static void F_79 ( struct V_76 * log )
{
unsigned int V_81 ;
const void T_4 * V_5 = log -> V_5 ;
F_80 (cpu) {
log -> V_5 = F_81 ( V_5 , V_81 ) ;
F_77 ( log ) ;
}
}
void T_5 F_82 ( const void * V_5 , V_13 V_12 , int V_20 ,
T_2 V_57 )
{
F_83 ( L_31 , V_82 , V_5 , V_12 , V_20 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_35 ( ( unsigned long ) V_5 , V_12 , V_20 , V_57 ) ;
else if ( V_83 )
F_73 ( V_84 , V_5 , V_12 , V_20 ) ;
}
void T_5 F_84 ( const void T_4 * V_5 , V_13 V_12 )
{
unsigned int V_81 ;
F_83 ( L_32 , V_82 , V_5 , V_12 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_35 ( ( unsigned long ) F_81 ( V_5 , V_81 ) ,
V_12 , 0 , V_69 ) ;
else if ( V_83 )
F_73 ( V_85 , V_5 , V_12 , 0 ) ;
}
void T_5 F_85 ( const void * V_5 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_61 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_73 ( V_86 , V_5 , 0 , 0 ) ;
}
void T_5 F_86 ( const void * V_5 , V_13 V_12 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_63 ( ( unsigned long ) V_5 , V_12 ) ;
else if ( V_83 )
F_73 ( V_87 , V_5 , V_12 , 0 ) ;
}
void T_5 F_87 ( const void T_4 * V_5 )
{
unsigned int V_81 ;
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_80 (cpu)
F_61 ( ( unsigned long ) F_81 ( V_5 ,
V_81 ) ) ;
else if ( V_83 )
F_73 ( V_88 , V_5 , 0 , 0 ) ;
}
void T_5 F_88 ( const void * V_5 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_67 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_73 ( V_89 , V_5 , 0 , 0 ) ;
}
void T_5 F_89 ( const void * V_5 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_68 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_73 ( V_90 , V_5 , 0 , 0 ) ;
}
void T_5 V_46 ( const void * V_5 , V_13 V_12 , T_2 V_57 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && V_12 && ! F_78 ( V_5 ) )
F_69 ( ( unsigned long ) V_5 , V_12 , V_57 ) ;
else if ( V_83 )
F_73 ( V_91 , V_5 , V_12 , 0 ) ;
}
void T_5 F_90 ( const void * V_5 )
{
F_83 ( L_33 , V_82 , V_5 ) ;
if ( V_79 && V_5 && ! F_78 ( V_5 ) )
F_72 ( ( unsigned long ) V_5 ) ;
else if ( V_83 )
F_73 ( V_92 , V_5 , 0 , 0 ) ;
}
static bool F_91 ( struct V_3 * V_4 )
{
T_6 V_93 = V_4 -> V_34 ;
if ( ! F_92 ( V_4 -> V_6 , V_4 -> V_12 ) )
return false ;
V_4 -> V_34 = F_93 ( 0 , ( void * ) V_4 -> V_6 , V_4 -> V_12 ) ;
return V_4 -> V_34 != V_93 ;
}
static int F_94 ( void )
{
if ( ! V_79 )
return 1 ;
if ( V_65 -> V_94 )
return F_95 ( V_65 ) ;
else
return F_96 () ;
return 0 ;
}
static void F_97 ( void * V_95 , void * V_96 ,
struct V_3 * V_97 , int V_98 )
{
unsigned long * V_5 ;
unsigned long * V_67 = F_98 ( V_95 , V_99 ) ;
unsigned long * V_68 = V_96 - ( V_99 - 1 ) ;
for ( V_5 = V_67 ; V_5 < V_68 ; V_5 ++ ) {
struct V_3 * V_4 ;
unsigned long V_21 ;
unsigned long V_6 ;
if ( V_98 )
F_99 () ;
if ( F_94 () )
break;
if ( ! F_92 ( ( unsigned long ) V_5 ,
V_99 ) )
continue;
V_6 = * V_5 ;
V_4 = F_28 ( V_6 , 1 ) ;
if ( ! V_4 )
continue;
if ( V_4 == V_97 ) {
F_24 ( V_4 ) ;
continue;
}
F_100 ( & V_4 -> V_64 , V_21 ,
V_100 ) ;
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
F_97 ( V_67 , F_2 ( V_67 + V_101 , V_68 ) ,
V_4 , 0 ) ;
V_67 += V_101 ;
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
V_4 = F_106 ( V_62 . V_102 , F_107 ( * V_4 ) , V_62 ) ;
while ( & V_4 -> V_62 != & V_62 ) {
F_99 () ;
if ( ! F_94 () )
F_102 ( V_4 ) ;
V_45 = F_106 ( V_4 -> V_62 . V_102 , F_107 ( * V_4 ) ,
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
int V_103 = 0 ;
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
F_97 ( V_104 , V_105 , NULL , 1 ) ;
F_97 ( V_106 , V_107 , NULL , 1 ) ;
#ifdef F_112
F_80 (i)
F_97 ( V_108 + F_113 ( V_7 ) ,
V_109 + F_113 ( V_7 ) , NULL , 1 ) ;
#endif
F_114 () ;
F_115 (i) {
unsigned long V_110 = F_116 ( V_7 ) ;
unsigned long V_111 = F_117 ( V_7 ) ;
unsigned long V_112 ;
for ( V_112 = V_110 ; V_112 < V_111 ; V_112 ++ ) {
struct V_113 * V_113 ;
if ( ! F_118 ( V_112 ) )
continue;
V_113 = F_119 ( V_112 ) ;
if ( F_120 ( V_113 ) == 0 )
continue;
F_97 ( V_113 , V_113 + 1 , NULL , 1 ) ;
}
}
F_121 () ;
if ( V_114 ) {
struct V_115 * V_116 , * V_117 ;
F_122 ( & V_118 ) ;
F_123 (g, p) {
F_97 ( F_124 ( V_116 ) , F_124 ( V_116 ) +
V_119 , NULL , 0 ) ;
} F_125 ( V_117 , V_116 ) ;
F_126 ( & V_118 ) ;
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
! ( V_4 -> V_21 & V_120 ) ) {
V_4 -> V_21 |= V_120 ;
V_103 ++ ;
}
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
if ( V_103 ) {
V_121 = true ;
F_127 ( L_35
L_36 , V_103 ) ;
}
}
static int F_128 ( void * V_122 )
{
static int V_123 = 1 ;
F_127 ( L_37 ) ;
F_129 ( V_65 , 10 ) ;
if ( V_123 ) {
V_123 = 0 ;
F_130 ( V_124 ) ;
}
while ( ! F_96 () ) {
signed long V_125 = V_126 ;
F_131 ( & V_127 ) ;
F_110 () ;
F_132 ( & V_127 ) ;
while ( V_125 && ! F_96 () )
V_125 = F_133 ( V_125 ) ;
}
F_127 ( L_38 ) ;
return 0 ;
}
static void F_134 ( void )
{
if ( V_128 )
return;
V_128 = F_135 ( F_128 , NULL , L_39 ) ;
if ( F_78 ( V_128 ) ) {
F_38 ( L_40 ) ;
V_128 = NULL ;
}
}
static void F_136 ( void )
{
if ( V_128 ) {
F_137 ( V_128 ) ;
V_128 = NULL ;
}
}
static void * F_138 ( struct V_1 * V_2 , T_7 * V_129 )
{
struct V_3 * V_4 ;
T_7 V_130 = * V_129 ;
int V_131 ;
V_131 = F_139 ( & V_127 ) ;
if ( V_131 < 0 )
return F_140 ( V_131 ) ;
F_29 () ;
F_111 (object, &object_list, object_list) {
if ( V_130 -- > 0 )
continue;
if ( F_17 ( V_4 ) )
goto V_66;
}
V_4 = NULL ;
V_66:
return V_4 ;
}
static void * F_141 ( struct V_1 * V_2 , void * V_132 , T_7 * V_129 )
{
struct V_3 * V_133 = V_132 ;
struct V_3 * V_134 = NULL ;
struct V_3 * V_135 = V_133 ;
++ ( * V_129 ) ;
F_142 (obj, &object_list, object_list) {
if ( F_17 ( V_135 ) ) {
V_134 = V_135 ;
break;
}
}
F_24 ( V_133 ) ;
return V_134 ;
}
static void F_143 ( struct V_1 * V_2 , void * V_132 )
{
if ( ! F_78 ( V_132 ) ) {
F_32 () ;
F_132 ( & V_127 ) ;
if ( V_132 )
F_24 ( V_132 ) ;
}
}
static int F_144 ( struct V_1 * V_2 , void * V_132 )
{
struct V_3 * V_4 = V_132 ;
unsigned long V_21 ;
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( ( V_4 -> V_21 & V_120 ) && F_7 ( V_4 ) )
F_9 ( V_2 , V_4 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
return 0 ;
}
static int F_145 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_146 ( V_137 , & V_138 ) ;
}
static int F_147 ( const char * V_139 )
{
unsigned long V_21 ;
struct V_3 * V_4 ;
unsigned long V_140 ;
if ( F_148 ( V_139 , 0 , & V_140 ) )
return - V_141 ;
V_4 = F_28 ( V_140 , 0 ) ;
if ( ! V_4 ) {
F_127 ( L_41 , V_140 ) ;
return - V_141 ;
}
F_59 ( & V_4 -> V_64 , V_21 ) ;
F_11 ( V_4 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static void F_149 ( void )
{
struct V_3 * V_4 ;
unsigned long V_21 ;
F_29 () ;
F_111 (object, &object_list, object_list) {
F_59 ( & V_4 -> V_64 , V_21 ) ;
if ( ( V_4 -> V_21 & V_120 ) &&
F_7 ( V_4 ) )
F_64 ( V_4 , V_72 ) ;
F_60 ( & V_4 -> V_64 , V_21 ) ;
}
F_32 () ;
V_121 = false ;
}
static T_8 F_150 ( struct V_137 * V_137 , const char T_9 * V_142 ,
V_13 V_12 , T_7 * V_143 )
{
char V_144 [ 64 ] ;
int V_145 ;
int V_146 ;
V_145 = F_2 ( V_12 , ( sizeof( V_144 ) - 1 ) ) ;
if ( F_151 ( V_144 , V_142 , V_145 ) < 0 )
return - V_147 ;
V_144 [ V_145 ] = 0 ;
V_146 = F_139 ( & V_127 ) ;
if ( V_146 < 0 )
return V_146 ;
if ( strncmp ( V_144 , L_42 , 5 ) == 0 ) {
if ( V_79 )
F_149 () ;
else
F_152 () ;
goto V_66;
}
if ( ! V_79 ) {
V_146 = - V_148 ;
goto V_66;
}
if ( strncmp ( V_144 , L_43 , 3 ) == 0 )
F_39 () ;
else if ( strncmp ( V_144 , L_44 , 8 ) == 0 )
V_114 = 1 ;
else if ( strncmp ( V_144 , L_45 , 9 ) == 0 )
V_114 = 0 ;
else if ( strncmp ( V_144 , L_46 , 7 ) == 0 )
F_134 () ;
else if ( strncmp ( V_144 , L_47 , 8 ) == 0 )
F_136 () ;
else if ( strncmp ( V_144 , L_48 , 5 ) == 0 ) {
unsigned long V_149 ;
V_146 = F_148 ( V_144 + 5 , 0 , & V_149 ) ;
if ( V_146 < 0 )
goto V_66;
F_136 () ;
if ( V_149 ) {
V_126 = F_153 ( V_149 * 1000 ) ;
F_134 () ;
}
} else if ( strncmp ( V_144 , L_49 , 4 ) == 0 )
F_110 () ;
else if ( strncmp ( V_144 , L_50 , 5 ) == 0 )
V_146 = F_147 ( V_144 + 5 ) ;
else
V_146 = - V_141 ;
V_66:
F_132 ( & V_127 ) ;
if ( V_146 < 0 )
return V_146 ;
* V_143 += V_12 ;
return V_12 ;
}
static void F_152 ( void )
{
struct V_3 * V_4 ;
F_29 () ;
F_111 (object, &object_list, object_list)
F_61 ( V_4 -> V_6 ) ;
F_32 () ;
}
static void F_154 ( struct V_150 * V_151 )
{
F_131 ( & V_127 ) ;
F_136 () ;
if ( ! V_121 )
F_152 () ;
else
F_127 ( L_51
L_52 ) ;
F_132 ( & V_127 ) ;
}
static void F_39 ( void )
{
if ( F_155 ( & V_77 , 0 , 1 ) )
return;
V_79 = 0 ;
if ( V_152 )
F_156 ( & V_153 ) ;
F_127 ( L_53 ) ;
}
static int F_157 ( char * V_139 )
{
if ( ! V_139 )
return - V_141 ;
if ( strcmp ( V_139 , L_43 ) == 0 )
F_39 () ;
else if ( strcmp ( V_139 , L_54 ) == 0 )
V_154 = 1 ;
else
return - V_141 ;
return 0 ;
}
static void T_3 F_158 ( struct V_76 * log )
{
struct V_31 V_30 ;
V_30 . V_32 = log -> V_29 ;
V_30 . V_33 = log -> V_30 ;
F_12 ( L_55 ) ;
F_13 ( & V_30 , 2 ) ;
}
void T_3 F_159 ( void )
{
int V_7 ;
unsigned long V_21 ;
#ifdef F_160
if ( ! V_154 ) {
V_83 = 0 ;
F_39 () ;
return;
}
#endif
V_24 = F_153 ( V_155 ) ;
V_126 = F_153 ( V_156 * 1000 ) ;
V_50 = F_161 ( V_3 , V_157 ) ;
V_49 = F_161 ( V_46 , V_157 ) ;
if ( V_78 >= F_74 ( V_76 ) )
F_38 ( L_56
L_57 , V_78 ) ;
F_75 ( V_21 ) ;
V_83 = 0 ;
if ( V_77 ) {
F_76 ( V_21 ) ;
return;
} else
V_79 = 1 ;
F_76 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_78 ; V_7 ++ ) {
struct V_76 * log = & V_76 [ V_7 ] ;
switch ( log -> V_75 ) {
case V_84 :
F_77 ( log ) ;
break;
case V_85 :
F_79 ( log ) ;
break;
case V_86 :
F_85 ( log -> V_5 ) ;
break;
case V_87 :
F_86 ( log -> V_5 , log -> V_12 ) ;
break;
case V_88 :
F_87 ( log -> V_5 ) ;
break;
case V_89 :
F_88 ( log -> V_5 ) ;
break;
case V_90 :
F_89 ( log -> V_5 ) ;
break;
case V_91 :
V_46 ( log -> V_5 , log -> V_12 , V_69 ) ;
break;
case V_92 :
F_90 ( log -> V_5 ) ;
break;
default:
F_16 ( L_58 ,
log -> V_75 ) ;
}
if ( V_158 ) {
F_158 ( log ) ;
V_158 = 0 ;
}
}
}
static int T_3 F_162 ( void )
{
struct V_159 * V_159 ;
V_152 = 1 ;
if ( V_77 ) {
F_156 ( & V_153 ) ;
return - V_160 ;
}
V_159 = F_163 ( L_39 , V_161 , NULL , NULL ,
& V_162 ) ;
if ( ! V_159 )
F_38 ( L_59 ) ;
F_131 ( & V_127 ) ;
F_134 () ;
F_132 ( & V_127 ) ;
F_127 ( L_60 ) ;
return 0 ;
}
