static void F_1 ( void )
{
#ifdef F_2
F_3 ( V_1 ) ;
#else
F_3 ( V_2 ) ;
#endif
}
int T_1 F_4 ( unsigned long V_3 ,
const char * V_4 , int V_5 , void * V_6 )
{
const void * V_7 , * V_8 , * V_9 ;
int V_10 , V_11 , V_12 ;
if ( V_5 != 1 || strcmp ( V_4 , L_1 ) != 0 )
return 0 ;
V_7 = F_5 ( V_3 , L_2 , & V_10 ) ;
V_8 = F_5 ( V_3 , L_3 , & V_11 ) ;
V_9 = F_5 ( V_3 , L_4 , & V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_9 )
return 1 ;
V_13 . V_14 = F_6 ( V_7 , V_10 / 4 ) ;
V_13 . V_15 = F_6 ( V_8 , V_11 / 4 ) ;
V_13 . V_16 = F_6 ( V_9 , V_12 / 4 ) ;
F_7 ( L_5 ,
V_13 . V_14 , V_7 , V_10 ) ;
F_7 ( L_6 ,
V_13 . V_15 , V_8 , V_11 ) ;
F_7 ( L_7 ,
V_13 . V_16 , V_9 , V_12 ) ;
V_17 |= V_18 ;
if ( F_8 ( V_3 , L_8 ) ) {
V_17 |= V_19 ;
V_17 |= V_20 ;
F_9 ( L_9 ) ;
} else if ( F_8 ( V_3 , L_10 ) ) {
V_17 |= V_19 ;
F_9 ( L_11 ) ;
} else {
F_9 ( L_12 ) ;
}
F_1 () ;
if ( V_21 -> V_22 )
V_21 -> V_22 () ;
return 1 ;
}
int T_1 F_10 ( unsigned long V_3 ,
const char * V_4 , int V_5 , void * V_6 )
{
int V_23 , V_24 , V_16 ;
const T_2 * V_25 ;
if ( V_5 != 1 || strcmp ( V_4 , L_1 ) != 0 )
return 0 ;
V_25 = F_5 ( V_3 , L_13 , & V_24 ) ;
if ( ! V_25 )
return 1 ;
F_7 ( L_14 ) ;
V_26 = V_24 / ( sizeof( * V_25 ) * 5 ) ;
if ( ! V_26 )
return 1 ;
V_16 = V_26 *
sizeof( struct V_27 ) ;
V_28 = F_11 ( F_12 ( V_16 , F_13 ( V_29 ) ,
V_30 ) ) ;
memset ( V_28 , 0 , V_16 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_28 [ V_23 ] . V_31 =
F_6 ( V_25 + ( V_23 * 5 ) + 0 , 2 ) ;
V_28 [ V_23 ] . V_32 =
V_28 [ V_23 ] . V_31 +
F_6 ( V_25 + ( V_23 * 5 ) + 2 , 1 ) ;
V_28 [ V_23 ] . V_33 =
F_6 ( V_25 + ( V_23 * 5 ) + 3 , 2 ) ;
F_7 ( L_15 ,
V_28 [ V_23 ] . V_31 ,
V_28 [ V_23 ] . V_32 ,
V_28 [ V_23 ] . V_33 ) ;
}
return 1 ;
}
static int T_1 F_14 ( void )
{
#ifdef F_2
V_29 V_34 ;
if ( ! ( V_17 & V_18 ) )
return - V_35 ;
V_34 = 0x7000 ;
F_15 ( V_36 , 0 , V_34 ) ;
#endif
return 0 ;
}
int F_16 ( struct V_37 * V_38 )
{
if ( ! V_38 ) {
F_17 ( L_16 ,
V_39 , V_38 ) ;
return - V_40 ;
}
F_18 ( & V_41 , V_38 ) ;
return 0 ;
}
int F_19 ( struct V_37 * V_38 )
{
if ( ! V_38 ) {
F_17 ( L_16 ,
V_39 , V_38 ) ;
return - V_40 ;
}
F_20 ( & V_41 , V_38 ) ;
return 0 ;
}
static void F_21 ( T_3 V_42 )
{
unsigned long V_43 ;
T_3 V_44 ;
if ( F_22 ( & V_45 ) )
return;
F_23 ( & V_46 , V_43 ) ;
V_44 = V_47 ^ V_42 ;
V_47 = V_42 ;
F_24 ( & V_46 , V_43 ) ;
F_25 ( & V_41 ,
V_42 , ( void * ) V_44 ) ;
}
void F_26 ( T_3 V_48 ,
T_3 V_49 )
{
unsigned long V_43 ;
F_23 ( & V_46 , V_43 ) ;
V_47 &= ~ V_48 ;
V_47 |= V_49 ;
F_24 ( & V_46 , V_43 ) ;
}
void F_27 ( void )
{
T_4 V_50 ;
T_5 V_51 = 0 ;
F_28 ( & V_45 , 0 ) ;
V_50 = F_29 ( & V_51 ) ;
if ( V_50 == V_52 && V_51 )
F_21 ( F_30 ( V_51 ) ) ;
}
void F_31 ( void )
{
F_28 ( & V_45 , 1 ) ;
}
int F_32 ( enum V_53 V_54 ,
struct V_37 * V_38 )
{
if ( ! V_38 ) {
F_17 ( L_16 ,
V_39 , V_38 ) ;
return - V_40 ;
}
if ( V_54 > V_55 ) {
F_17 ( L_17 ,
V_39 , V_54 ) ;
return - V_40 ;
}
return F_18 (
& V_56 [ V_54 ] , V_38 ) ;
}
static void F_33 ( T_6 V_54 , void * V_57 )
{
F_25 ( & V_56 [ V_54 ] ,
V_54 , V_57 ) ;
}
static void F_34 ( void )
{
T_7 V_58 ;
static struct V_59 V_57 ;
T_8 type ;
V_58 = F_35 ( F_36 ( & V_57 ) , sizeof( V_57 ) ) ;
if ( V_58 == V_60 )
return;
if ( V_58 ) {
F_17 ( L_18 ,
V_39 , V_58 ) ;
return;
}
type = F_37 ( V_57 . V_54 ) ;
if ( type > V_55 ) {
F_17 ( L_19 , V_39 , type ) ;
return;
}
F_33 ( type , ( void * ) & V_57 ) ;
}
static int F_38 ( struct V_37 * V_38 ,
unsigned long V_42 , void * V_61 )
{
if ( V_42 & V_62 )
F_34 () ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_58 , V_23 ;
for ( V_23 = 0 ; V_23 < V_55 ; V_23 ++ )
F_40 ( & V_56 [ V_23 ] ) ;
V_58 = F_16 ( & V_63 ) ;
if ( V_58 ) {
F_41 ( L_20 ,
V_39 , V_58 ) ;
return V_58 ;
}
return 0 ;
}
int F_42 ( T_6 V_64 , char * V_65 , int V_66 )
{
T_7 V_50 ;
T_5 V_51 , V_67 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_29 ( & V_51 ) ;
if ( ( F_30 ( V_51 ) & V_68 ) == 0 )
return 0 ;
V_67 = F_43 ( V_66 ) ;
V_50 = F_44 ( V_64 , & V_67 , V_65 ) ;
if ( V_50 == V_52 )
return F_30 ( V_67 ) ;
return 0 ;
}
int F_45 ( T_6 V_64 , const char * V_6 , int V_69 )
{
int V_70 = 0 ;
T_5 V_71 ;
T_7 V_67 , V_50 ;
unsigned long V_43 ;
T_5 V_51 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_23 ( & V_72 , V_43 ) ;
if ( F_46 ( V_19 ) ) {
V_50 = F_47 ( V_64 , & V_71 ) ;
V_67 = F_30 ( V_71 ) ;
if ( V_50 || V_67 < V_69 ) {
F_24 ( & V_72 , V_43 ) ;
if ( V_50 )
return V_69 ;
F_29 ( NULL ) ;
return - V_73 ;
}
}
V_50 = V_74 ;
while( V_69 > 0 && ( V_50 == V_74 ||
V_50 == V_75 || V_50 == V_52 ) ) {
V_71 = F_43 ( V_69 ) ;
V_50 = F_48 ( V_64 , & V_71 , V_6 ) ;
V_67 = F_30 ( V_71 ) ;
if ( V_50 != V_52 && V_50 != V_74 &&
V_50 != V_75 ) {
V_70 = V_69 ;
break;
}
if ( V_50 == V_52 ) {
V_69 -= V_67 ;
V_6 += V_67 ;
V_70 += V_67 ;
}
do
F_29 ( & V_51 ) ;
while( V_50 == V_52 &&
( F_30 ( V_51 ) & V_76 ) );
}
F_24 ( & V_72 , V_43 ) ;
return V_70 ;
}
static int F_49 ( struct V_77 * V_78 ,
struct V_79 * V_51 )
{
int V_80 = 0 ;
T_3 V_81 = F_50 ( V_51 ) ;
if ( ! ( V_78 -> V_82 & V_83 ) ) {
V_80 = 0 ;
} else if ( V_51 -> V_84 == V_85 ) {
V_80 = 1 ;
} else if ( V_81 && ! F_51 ( V_81 ) ) {
if ( F_52 ( V_78 ) && ! F_53 ( V_86 ) ) {
F_54 ( V_87 , V_78 , V_88 , V_78 -> V_89 ) ;
V_80 = 1 ;
} else
V_80 = 0 ;
} else if ( F_52 ( V_78 ) && ! F_53 ( V_86 ) &&
V_51 -> V_90 == V_91 ) {
F_54 ( V_87 , V_78 , V_88 , V_78 -> V_89 ) ;
V_80 = 1 ;
}
return V_80 ;
}
int F_55 ( struct V_77 * V_78 )
{
struct V_79 V_51 ;
if ( ! F_56 ( & V_51 , V_92 ) )
return 0 ;
if ( V_51 . V_93 != V_94 ) {
F_41 ( L_21 ,
V_51 . V_93 ) ;
return 0 ;
}
F_57 ( & V_51 ) ;
if ( F_49 ( V_78 , & V_51 ) )
return 1 ;
return 0 ;
}
int F_58 ( struct V_77 * V_78 )
{
T_7 V_50 ;
V_50 = F_59 () ;
if ( V_50 == V_52 ) {
V_95 -> V_96 = 1 ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_77 * V_78 )
{
T_7 V_50 ;
T_5 V_51 = 0 ;
if ( ! V_95 -> V_96 )
return 0 ;
V_95 -> V_96 = 0 ;
V_50 = F_29 ( & V_51 ) ;
if ( V_50 == V_52 && V_51 )
F_21 ( F_30 ( V_51 ) ) ;
return 1 ;
}
static T_3 F_61 ( T_3 V_89 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
if ( ( V_89 >= V_28 [ V_23 ] . V_31 ) &&
( V_89 < V_28 [ V_23 ] . V_32 ) )
return V_28 [ V_23 ] . V_33 ;
return 0 ;
}
bool F_62 ( struct V_77 * V_78 )
{
T_3 V_33 = 0 ;
if ( ! V_13 . V_14 || ! V_13 . V_16 )
goto V_97;
if ( ( V_78 -> V_89 >= V_13 . V_14 ) &&
( V_78 -> V_89 <= ( V_13 . V_14 + V_13 . V_16 ) ) )
V_33 = F_61 ( V_78 -> V_89 ) ;
if ( V_33 )
V_78 -> V_89 = V_33 ;
V_97:
return ! ! V_33 ;
}
static T_9 F_63 ( int V_98 , void * V_6 )
{
T_5 V_42 ;
F_64 ( F_65 ( V_98 ) , & V_42 ) ;
F_21 ( F_30 ( V_42 ) ) ;
return V_99 ;
}
static int F_66 ( void )
{
V_100 = F_67 ( L_22 , V_101 ) ;
if ( ! V_100 ) {
F_68 ( L_23 ) ;
return - V_102 ;
}
return 0 ;
}
static void T_1 F_69 ( void )
{
void * V_103 ;
T_3 V_16 ;
int V_50 ;
V_103 = F_70 () ;
V_16 = F_71 () ;
V_50 = F_72 ( V_104 ,
F_36 ( V_103 ) , V_16 ) ;
if ( V_50 && V_50 != V_105 )
F_68 ( L_24
L_25 , V_50 ) ;
}
static int T_1 F_73 ( void )
{
struct V_106 * V_107 , * V_108 ;
const T_2 * V_109 ;
int V_50 , V_23 , V_110 ;
V_111 = F_74 ( L_26 ) ;
if ( ! V_111 ) {
F_68 ( L_27 ) ;
return - V_35 ;
}
if ( F_46 ( V_19 ) )
V_108 = F_74 ( L_28 ) ;
else
V_108 = F_75 ( V_111 ) ;
if ( V_108 ) {
F_76 (consoles, np) {
if ( strcmp ( V_107 -> V_112 , L_29 ) )
continue;
F_77 ( V_107 , NULL , NULL ) ;
}
F_78 ( V_108 ) ;
}
V_109 = F_79 ( V_111 , L_30 , & V_110 ) ;
F_7 ( L_31 ,
V_109 ? ( V_110 / 4 ) : 0 ) ;
V_113 = V_110 / 4 ;
V_114 = F_80 ( V_113 * sizeof( unsigned int ) , V_115 ) ;
for ( V_23 = 0 ; V_109 && V_23 < ( V_110 / 4 ) ; V_23 ++ , V_109 ++ ) {
unsigned int V_116 = F_81 ( V_109 ) ;
unsigned int V_98 = F_82 ( NULL , V_116 ) ;
if ( V_98 == V_117 ) {
F_17 ( L_32 , V_116 ) ;
continue;
}
V_50 = F_83 ( V_98 , F_63 , 0 , L_22 , NULL ) ;
if ( V_50 )
F_17 ( L_33
L_34 , V_50 , V_98 , V_116 ) ;
V_114 [ V_23 ] = V_98 ;
}
V_50 = F_66 () ;
if ( V_50 == 0 ) {
F_69 () ;
V_50 = F_84 () ;
F_85 () ;
F_86 () ;
F_87 () ;
F_88 () ;
}
return 0 ;
}
void F_89 ( void )
{
unsigned int V_23 ;
long V_50 = V_74 ;
for ( V_23 = 0 ; V_23 < V_113 ; V_23 ++ ) {
if ( V_114 [ V_23 ] )
F_90 ( V_114 [ V_23 ] , NULL ) ;
V_114 [ V_23 ] = 0 ;
}
while ( V_50 == V_74 || V_50 == V_75 ) {
V_50 = F_91 () ;
if ( V_50 == V_74 )
F_29 ( NULL ) ;
else
F_92 ( 10 ) ;
}
F_93 ( V_104 ) ;
}
struct V_118 * F_94 ( void * V_119 ,
unsigned long V_120 )
{
struct V_118 * V_121 , * V_122 = NULL ;
unsigned long V_23 = 0 ;
V_121 = F_80 ( V_123 , V_115 ) ;
if ( ! V_121 )
goto V_124;
V_122 = V_121 ;
while ( V_120 > 0 ) {
T_3 V_6 = F_95 ( V_119 ) << V_125 ;
T_3 V_126 = F_96 ( V_120 , V_123 ) ;
V_121 -> V_15 [ V_23 ] . V_6 = F_43 ( V_6 ) ;
V_121 -> V_15 [ V_23 ] . V_126 = F_43 ( V_126 ) ;
V_23 ++ ;
if ( V_23 >= V_127 ) {
struct V_118 * V_128 ;
V_128 = F_80 ( V_123 , V_115 ) ;
if ( ! V_128 )
goto V_124;
V_121 -> V_126 = F_43 (
V_23 * sizeof( struct V_129 ) + 16 ) ;
V_23 = 0 ;
V_121 -> V_128 = F_43 ( F_36 ( V_128 ) ) ;
V_121 = V_128 ;
}
V_119 += V_126 ;
V_120 -= V_126 ;
}
V_121 -> V_126 = F_43 ( V_23 * sizeof( struct V_129 ) + 16 ) ;
return V_122 ;
V_124:
F_41 ( L_35 , V_39 ) ;
F_97 ( V_122 ) ;
return NULL ;
}
void F_97 ( struct V_118 * V_121 )
{
while ( V_121 ) {
T_3 V_128 = F_30 ( V_121 -> V_128 ) ;
F_98 ( V_121 ) ;
if ( V_128 )
V_121 = F_11 ( V_128 ) ;
else
V_121 = NULL ;
}
}
