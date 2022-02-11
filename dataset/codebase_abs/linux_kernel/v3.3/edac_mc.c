static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
F_2 ( L_2 , V_2 -> V_3 ) ;
F_2 ( L_3 , V_2 -> V_4 ) ;
F_2 ( L_4 , V_2 -> V_5 ) ;
F_2 ( L_5 , V_2 -> V_6 ) ;
}
static void F_3 ( struct V_7 * V_6 )
{
F_2 ( L_6 , V_6 ) ;
F_2 ( L_7 , V_6 -> V_8 ) ;
F_2 ( L_8 , V_6 -> V_9 ) ;
F_2 ( L_9 , V_6 -> V_10 ) ;
F_2 ( L_10 , V_6 -> V_11 ) ;
F_2 ( L_11 , V_6 -> V_12 ) ;
F_2 ( L_12 , V_6 -> V_13 ) ;
F_2 ( L_13 , V_6 -> V_14 ) ;
F_2 ( L_14 , V_6 -> V_15 ) ;
}
static void F_4 ( struct V_16 * V_15 )
{
F_5 ( L_15 , V_15 ) ;
F_5 ( L_16 , V_15 -> V_17 ) ;
F_5 ( L_17 , V_15 -> V_18 ) ;
F_5 ( L_18 , V_15 -> V_19 ) ;
F_2 ( L_19 , V_15 -> V_20 ) ;
F_5 ( L_20 ,
V_15 -> V_21 , V_15 -> V_22 ) ;
F_5 ( L_21 , V_15 -> V_23 ) ;
F_5 ( L_22 , V_15 -> V_24 , V_15 -> V_25 ) ;
F_5 ( L_23 , V_15 -> V_26 ) ;
}
void * F_6 ( void * V_27 , unsigned V_28 )
{
unsigned V_29 , V_30 ;
if ( V_28 > sizeof( long ) )
V_29 = sizeof( long long ) ;
else if ( V_28 > sizeof( int ) )
V_29 = sizeof( long ) ;
else if ( V_28 > sizeof( short ) )
V_29 = sizeof( int ) ;
else if ( V_28 > sizeof( char ) )
V_29 = sizeof( short ) ;
else
return ( char * ) V_27 ;
V_30 = V_28 % V_29 ;
if ( V_30 == 0 )
return ( char * ) V_27 ;
return ( void * ) ( ( ( unsigned long ) V_27 ) + V_29 - V_30 ) ;
}
struct V_16 * F_7 ( unsigned V_31 , unsigned V_21 ,
unsigned V_32 , int V_33 )
{
struct V_16 * V_15 ;
struct V_7 * V_34 , * V_6 ;
struct V_1 * V_35 , * V_36 , * V_2 ;
void * V_37 ;
unsigned V_28 ;
int V_38 , V_39 ;
int V_40 ;
V_15 = (struct V_16 * ) 0 ;
V_34 = F_6 ( & V_15 [ 1 ] , sizeof( * V_34 ) ) ;
V_35 = F_6 ( & V_34 [ V_21 ] , sizeof( * V_35 ) ) ;
V_37 = F_6 ( & V_35 [ V_32 * V_21 ] , V_31 ) ;
V_28 = ( ( unsigned long ) V_37 ) + V_31 ;
V_15 = F_8 ( V_28 , V_41 ) ;
if ( V_15 == NULL )
return NULL ;
V_34 = (struct V_7 * ) ( ( ( char * ) V_15 ) + ( ( unsigned long ) V_34 ) ) ;
V_35 = (struct V_1 * ) ( ( ( char * ) V_15 ) + ( ( unsigned long ) V_35 ) ) ;
V_37 = V_31 ? ( ( ( char * ) V_15 ) + ( ( unsigned long ) V_37 ) ) : NULL ;
V_15 -> V_42 = V_33 ;
V_15 -> V_22 = V_34 ;
V_15 -> V_26 = V_37 ;
V_15 -> V_21 = V_21 ;
for ( V_38 = 0 ; V_38 < V_21 ; V_38 ++ ) {
V_6 = & V_34 [ V_38 ] ;
V_6 -> V_8 = V_38 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_13 = V_32 ;
V_36 = & V_35 [ V_38 * V_32 ] ;
V_6 -> V_14 = V_36 ;
for ( V_39 = 0 ; V_39 < V_32 ; V_39 ++ ) {
V_2 = & V_36 [ V_39 ] ;
V_2 -> V_3 = V_39 ;
V_2 -> V_6 = V_6 ;
}
}
V_15 -> V_43 = V_44 ;
F_9 ( & V_15 -> V_45 ) ;
V_40 = F_10 ( V_15 ) ;
if ( V_40 ) {
F_11 ( V_15 ) ;
return NULL ;
}
return V_15 ;
}
void F_12 ( struct V_16 * V_15 )
{
F_13 ( L_24 , V_46 ) ;
F_14 ( V_15 ) ;
F_11 ( V_15 ) ;
}
struct V_16 * F_15 ( struct V_47 * V_23 )
{
struct V_16 * V_15 ;
struct V_48 * V_49 ;
F_5 ( L_24 , V_46 ) ;
F_16 (item, &mc_devices) {
V_15 = F_17 ( V_49 , struct V_16 , V_50 ) ;
if ( V_15 -> V_23 == V_23 )
return V_15 ;
}
return NULL ;
}
static int F_18 ( void )
{
int V_51 ;
if ( V_52 == V_53 )
return 1 ;
V_51 = V_54 ;
V_54 = 0 ;
return V_51 ;
}
static void F_19 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_20 ( V_56 ) ;
struct V_16 * V_15 = F_21 ( V_58 ) ;
F_22 ( & V_59 ) ;
if ( V_15 -> V_43 == V_60 ) {
F_23 ( & V_59 ) ;
return;
}
if ( F_18 () && ( V_15 -> V_20 != NULL ) )
V_15 -> V_20 ( V_15 ) ;
F_23 ( & V_59 ) ;
F_24 ( V_61 , & V_15 -> V_62 ,
F_25 ( F_26 () ) ) ;
}
static void F_27 ( struct V_16 * V_15 , unsigned V_63 )
{
F_28 ( L_24 , V_46 ) ;
if ( V_15 -> V_43 != V_64 )
return;
F_29 ( & V_15 -> V_62 , F_19 ) ;
F_24 ( V_61 , & V_15 -> V_62 , F_25 ( V_63 ) ) ;
}
static void F_30 ( struct V_16 * V_15 )
{
int V_65 ;
if ( V_15 -> V_43 != V_64 )
return;
V_65 = F_31 ( & V_15 -> V_62 ) ;
if ( V_65 == 0 ) {
F_28 ( L_25 ,
V_46 ) ;
F_32 ( V_61 ) ;
}
}
void F_33 ( int V_66 )
{
struct V_16 * V_15 ;
struct V_48 * V_49 ;
F_22 ( & V_59 ) ;
F_16 (item, &mc_devices) {
V_15 = F_17 ( V_49 , struct V_16 , V_50 ) ;
if ( V_15 -> V_43 == V_64 )
F_31 ( & V_15 -> V_62 ) ;
}
F_23 ( & V_59 ) ;
F_22 ( & V_59 ) ;
F_16 (item, &mc_devices) {
V_15 = F_17 ( V_49 , struct V_16 , V_50 ) ;
F_27 ( V_15 , ( unsigned long ) V_66 ) ;
}
F_23 ( & V_59 ) ;
}
static int F_34 ( struct V_16 * V_15 )
{
struct V_48 * V_49 , * V_67 ;
struct V_16 * V_68 ;
V_67 = & V_69 ;
V_68 = F_15 ( V_15 -> V_23 ) ;
if ( F_35 ( V_68 != NULL ) )
goto V_70;
F_16 (item, &mc_devices) {
V_68 = F_17 ( V_49 , struct V_16 , V_50 ) ;
if ( V_68 -> V_42 >= V_15 -> V_42 ) {
if ( F_35 ( V_68 -> V_42 == V_15 -> V_42 ) )
goto V_71;
V_67 = V_49 ;
break;
}
}
F_36 ( & V_15 -> V_50 , V_67 ) ;
F_37 ( & V_72 ) ;
return 0 ;
V_70:
F_38 ( V_73 , V_74 ,
L_26 , F_39 ( V_68 -> V_23 ) ,
F_40 ( V_15 ) , V_68 -> V_24 , V_68 -> V_25 , V_68 -> V_42 ) ;
return 1 ;
V_71:
F_38 ( V_73 , V_74 ,
L_27
L_28 , V_68 -> V_42 , V_46 ) ;
return 1 ;
}
static void F_41 ( struct V_16 * V_15 )
{
F_42 ( & V_72 ) ;
F_43 ( & V_15 -> V_50 ) ;
F_44 () ;
F_9 ( & V_15 -> V_50 ) ;
}
struct V_16 * F_45 ( int V_75 )
{
struct V_48 * V_49 ;
struct V_16 * V_15 ;
F_16 (item, &mc_devices) {
V_15 = F_17 ( V_49 , struct V_16 , V_50 ) ;
if ( V_15 -> V_42 >= V_75 ) {
if ( V_15 -> V_42 == V_75 )
return V_15 ;
break;
}
}
return NULL ;
}
int F_46 ( struct V_16 * V_15 )
{
F_28 ( L_24 , V_46 ) ;
#ifdef F_47
if ( V_76 >= 3 )
F_4 ( V_15 ) ;
if ( V_76 >= 4 ) {
int V_77 ;
for ( V_77 = 0 ; V_77 < V_15 -> V_21 ; V_77 ++ ) {
int V_78 ;
F_3 ( & V_15 -> V_22 [ V_77 ] ) ;
for ( V_78 = 0 ; V_78 < V_15 -> V_22 [ V_77 ] . V_13 ; V_78 ++ )
F_1 ( & V_15 -> V_22 [ V_77 ] .
V_14 [ V_78 ] ) ;
}
}
#endif
F_22 ( & V_59 ) ;
if ( F_34 ( V_15 ) )
goto V_70;
V_15 -> V_79 = V_80 ;
if ( F_48 ( V_15 ) ) {
F_49 ( V_15 , V_73 ,
L_29 ) ;
goto V_71;
}
if ( V_15 -> V_20 != NULL ) {
V_15 -> V_43 = V_64 ;
F_27 ( V_15 , F_26 () ) ;
} else {
V_15 -> V_43 = V_81 ;
}
F_49 ( V_15 , V_82 , L_30
L_31 , V_15 -> V_24 , V_15 -> V_25 , F_40 ( V_15 ) ) ;
F_23 ( & V_59 ) ;
return 0 ;
V_71:
F_41 ( V_15 ) ;
V_70:
F_23 ( & V_59 ) ;
return 1 ;
}
struct V_16 * F_50 ( struct V_47 * V_23 )
{
struct V_16 * V_15 ;
F_28 ( L_24 , V_46 ) ;
F_22 ( & V_59 ) ;
V_15 = F_15 ( V_23 ) ;
if ( V_15 == NULL ) {
F_23 ( & V_59 ) ;
return NULL ;
}
F_41 ( V_15 ) ;
F_23 ( & V_59 ) ;
F_30 ( V_15 ) ;
V_15 -> V_43 = V_60 ;
F_51 ( V_15 ) ;
F_38 ( V_82 , V_74 ,
L_32 , V_15 -> V_42 ,
V_15 -> V_24 , V_15 -> V_25 , F_40 ( V_15 ) ) ;
return V_15 ;
}
static void F_52 ( unsigned long V_83 , unsigned long V_84 ,
T_1 V_28 )
{
struct V_83 * V_85 ;
void * V_86 ;
unsigned long V_87 = 0 ;
F_5 ( L_24 , V_46 ) ;
if ( ! F_53 ( V_83 ) )
return;
V_85 = F_54 ( V_83 ) ;
if ( F_55 ( V_85 ) )
F_56 ( V_87 ) ;
V_86 = F_57 ( V_85 , V_88 ) ;
F_58 ( V_86 + V_84 , V_28 ) ;
F_59 ( V_86 , V_88 ) ;
if ( F_55 ( V_85 ) )
F_60 ( V_87 ) ;
}
int F_61 ( struct V_16 * V_15 , unsigned long V_83 )
{
struct V_7 * V_22 = V_15 -> V_22 ;
int V_38 , V_77 ;
F_13 ( L_33 , V_15 -> V_42 , V_46 , V_83 ) ;
V_38 = - 1 ;
for ( V_77 = 0 ; V_77 < V_15 -> V_21 ; V_77 ++ ) {
struct V_7 * V_6 = & V_22 [ V_77 ] ;
if ( V_6 -> V_12 == 0 )
continue;
F_5 ( L_34
L_35 , V_15 -> V_42 , V_46 ,
V_6 -> V_9 , V_83 , V_6 -> V_10 ,
V_6 -> V_11 ) ;
if ( ( V_83 >= V_6 -> V_9 ) &&
( V_83 <= V_6 -> V_10 ) &&
( ( V_83 & V_6 -> V_11 ) ==
( V_6 -> V_9 & V_6 -> V_11 ) ) ) {
V_38 = V_77 ;
break;
}
}
if ( V_38 == - 1 )
F_49 ( V_15 , V_89 ,
L_36 ,
( unsigned long ) V_83 ) ;
return V_38 ;
}
void F_62 ( struct V_16 * V_15 ,
unsigned long V_90 ,
unsigned long V_91 , unsigned long V_92 ,
int V_38 , int V_93 , const char * V_94 )
{
unsigned long V_95 ;
F_5 ( L_37 , V_15 -> V_42 , V_46 ) ;
if ( V_38 >= V_15 -> V_21 || V_38 < 0 ) {
F_49 ( V_15 , V_89 ,
L_38
L_39 , V_38 , V_15 -> V_21 ) ;
F_63 ( V_15 , L_40 ) ;
return;
}
if ( V_93 >= V_15 -> V_22 [ V_38 ] . V_13 || V_93 < 0 ) {
F_49 ( V_15 , V_89 ,
L_41
L_39 , V_93 ,
V_15 -> V_22 [ V_38 ] . V_13 ) ;
F_63 ( V_15 , L_40 ) ;
return;
}
if ( F_64 () )
F_49 ( V_15 , V_73 ,
L_42
L_43 ,
V_90 , V_91 ,
V_15 -> V_22 [ V_38 ] . V_96 , V_92 , V_38 , V_93 ,
V_15 -> V_22 [ V_38 ] . V_14 [ V_93 ] . V_5 , V_94 ) ;
V_15 -> V_4 ++ ;
V_15 -> V_22 [ V_38 ] . V_4 ++ ;
V_15 -> V_22 [ V_38 ] . V_14 [ V_93 ] . V_4 ++ ;
if ( V_15 -> V_97 & V_98 ) {
V_95 = V_15 -> V_99 ?
V_15 -> V_99 ( V_15 , V_90 ) :
V_90 ;
F_52 ( V_95 , V_91 ,
V_15 -> V_22 [ V_38 ] . V_96 ) ;
}
}
void F_63 ( struct V_16 * V_15 , const char * V_94 )
{
if ( F_64 () )
F_49 ( V_15 , V_73 ,
L_44 , V_94 ) ;
V_15 -> V_100 ++ ;
V_15 -> V_4 ++ ;
}
void F_65 ( struct V_16 * V_15 ,
unsigned long V_90 ,
unsigned long V_91 , int V_38 , const char * V_94 )
{
int V_101 = V_102 * 4 ;
char V_103 [ V_101 + 1 ] ;
char * V_104 = V_103 ;
int V_2 ;
int V_105 ;
F_5 ( L_37 , V_15 -> V_42 , V_46 ) ;
if ( V_38 >= V_15 -> V_21 || V_38 < 0 ) {
F_49 ( V_15 , V_89 ,
L_38
L_39 , V_38 , V_15 -> V_21 ) ;
F_66 ( V_15 , L_40 ) ;
return;
}
V_105 = snprintf ( V_104 , V_101 + 1 , L_45 ,
V_15 -> V_22 [ V_38 ] . V_14 [ 0 ] . V_5 ) ;
V_101 -= V_105 ;
V_104 += V_105 ;
for ( V_2 = 1 ; ( V_2 < V_15 -> V_22 [ V_38 ] . V_13 ) && ( V_101 > 0 ) ;
V_2 ++ ) {
V_105 = snprintf ( V_104 , V_101 + 1 , L_46 ,
V_15 -> V_22 [ V_38 ] . V_14 [ V_2 ] . V_5 ) ;
V_101 -= V_105 ;
V_104 += V_105 ;
}
if ( F_67 () )
F_49 ( V_15 , V_106 ,
L_47
L_48 , V_90 ,
V_91 , V_15 -> V_22 [ V_38 ] . V_96 , V_38 ,
V_103 , V_94 ) ;
if ( F_68 () )
F_69 ( L_49
L_50 , V_15 -> V_42 ,
V_90 , V_91 ,
V_15 -> V_22 [ V_38 ] . V_96 , V_38 , V_103 , V_94 ) ;
V_15 -> V_107 ++ ;
V_15 -> V_22 [ V_38 ] . V_107 ++ ;
}
void F_66 ( struct V_16 * V_15 , const char * V_94 )
{
if ( F_68 () )
F_69 ( L_51 , V_15 -> V_42 ) ;
if ( F_67 () )
F_49 ( V_15 , V_73 ,
L_52 , V_94 ) ;
V_15 -> V_108 ++ ;
V_15 -> V_107 ++ ;
}
void F_70 ( struct V_16 * V_15 ,
unsigned int V_6 ,
unsigned int V_109 ,
unsigned int V_110 , char * V_94 )
{
int V_101 = V_102 * 4 ;
char V_103 [ V_101 + 1 ] ;
char * V_104 = V_103 ;
int V_105 ;
if ( V_6 >= V_15 -> V_21 ) {
F_49 ( V_15 , V_89 ,
L_53 ,
V_6 , V_15 -> V_21 ) ;
F_66 ( V_15 , L_40 ) ;
return;
}
if ( V_109 >= V_15 -> V_22 [ V_6 ] . V_13 ) {
F_49 ( V_15 , V_89 ,
L_54
L_39 ,
V_109 , V_15 -> V_22 [ V_6 ] . V_13 ) ;
F_66 ( V_15 , L_40 ) ;
return;
}
if ( V_110 >= V_15 -> V_22 [ V_6 ] . V_13 ) {
F_49 ( V_15 , V_89 ,
L_55
L_39 ,
V_110 , V_15 -> V_22 [ V_6 ] . V_13 ) ;
F_66 ( V_15 , L_40 ) ;
return;
}
V_15 -> V_107 ++ ;
V_15 -> V_22 [ V_6 ] . V_107 ++ ;
V_105 = snprintf ( V_104 , V_101 + 1 , L_45 ,
V_15 -> V_22 [ V_6 ] . V_14 [ V_109 ] . V_5 ) ;
V_101 -= V_105 ;
V_104 += V_105 ;
V_105 = snprintf ( V_104 , V_101 + 1 , L_56 ,
V_15 -> V_22 [ V_6 ] . V_14 [ V_110 ] . V_5 ) ;
if ( F_67 () )
F_49 ( V_15 , V_106 ,
L_57
L_48 , V_6 , V_109 , V_110 ,
V_103 , V_94 ) ;
if ( F_68 () )
F_69 ( L_57
L_48 , V_6 , V_109 ,
V_110 , V_103 , V_94 ) ;
}
void F_71 ( struct V_16 * V_15 ,
unsigned int V_6 , unsigned int V_93 , char * V_94 )
{
if ( V_6 >= V_15 -> V_21 ) {
F_49 ( V_15 , V_89 ,
L_53 ,
V_6 , V_15 -> V_21 ) ;
F_63 ( V_15 , L_40 ) ;
return;
}
if ( V_93 >= V_15 -> V_22 [ V_6 ] . V_13 ) {
F_49 ( V_15 , V_89 ,
L_58 ,
V_93 , V_15 -> V_22 [ V_6 ] . V_13 ) ;
F_63 ( V_15 , L_40 ) ;
return;
}
if ( F_64 () )
F_49 ( V_15 , V_73 ,
L_59 ,
V_6 , V_93 ,
V_15 -> V_22 [ V_6 ] . V_14 [ V_93 ] . V_5 , V_94 ) ;
V_15 -> V_4 ++ ;
V_15 -> V_22 [ V_6 ] . V_4 ++ ;
V_15 -> V_22 [ V_6 ] . V_14 [ V_93 ] . V_4 ++ ;
}
