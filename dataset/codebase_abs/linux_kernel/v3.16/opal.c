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
F_15 ( V_36 ,
0 , V_34 ) ;
V_34 += 128 ;
F_15 ( V_37 , 0 , V_34 ) ;
#endif
return 0 ;
}
int F_16 ( struct V_38 * V_39 )
{
if ( ! V_39 ) {
F_17 ( L_16 ,
V_40 , V_39 ) ;
return - V_41 ;
}
F_18 ( & V_42 , V_39 ) ;
return 0 ;
}
int F_19 ( struct V_38 * V_39 )
{
if ( ! V_39 ) {
F_17 ( L_16 ,
V_40 , V_39 ) ;
return - V_41 ;
}
F_20 ( & V_42 , V_39 ) ;
return 0 ;
}
static void F_21 ( T_3 V_43 )
{
unsigned long V_44 ;
T_3 V_45 ;
if ( F_22 ( & V_46 ) )
return;
F_23 ( & V_47 , V_44 ) ;
V_45 = V_48 ^ V_43 ;
V_48 = V_43 ;
F_24 ( & V_47 , V_44 ) ;
F_25 ( & V_42 ,
V_43 , ( void * ) V_45 ) ;
}
void F_26 ( T_3 V_49 ,
T_3 V_50 )
{
unsigned long V_44 ;
F_23 ( & V_47 , V_44 ) ;
V_48 &= ~ V_49 ;
V_48 |= V_50 ;
F_24 ( & V_47 , V_44 ) ;
}
void F_27 ( void )
{
T_4 V_51 ;
T_5 V_52 = 0 ;
F_28 ( & V_46 , 0 ) ;
V_51 = F_29 ( & V_52 ) ;
if ( V_51 == V_53 && V_52 )
F_21 ( F_30 ( V_52 ) ) ;
}
void F_31 ( void )
{
F_28 ( & V_46 , 1 ) ;
}
int F_32 ( enum V_54 V_55 ,
struct V_38 * V_39 )
{
if ( ! V_39 ) {
F_17 ( L_16 ,
V_40 , V_39 ) ;
return - V_41 ;
}
if ( V_55 > V_56 ) {
F_17 ( L_17 ,
V_40 , V_55 ) ;
return - V_41 ;
}
return F_18 (
& V_57 [ V_55 ] , V_39 ) ;
}
static void F_33 ( T_6 V_55 , void * V_58 )
{
F_25 ( & V_57 [ V_55 ] ,
V_55 , V_58 ) ;
}
static void F_34 ( void )
{
T_7 V_59 ;
static struct V_60 V_58 ;
T_8 type ;
V_59 = F_35 ( F_36 ( & V_58 ) , sizeof( V_58 ) ) ;
if ( V_59 == V_61 )
return;
if ( V_59 ) {
F_17 ( L_18 ,
V_40 , V_59 ) ;
return;
}
type = F_37 ( V_58 . V_55 ) ;
if ( type > V_56 ) {
F_17 ( L_19 , V_40 , type ) ;
return;
}
F_33 ( type , ( void * ) & V_58 ) ;
}
static int F_38 ( struct V_38 * V_39 ,
unsigned long V_43 , void * V_62 )
{
if ( V_43 & V_63 )
F_34 () ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_59 , V_23 ;
for ( V_23 = 0 ; V_23 < V_56 ; V_23 ++ )
F_40 ( & V_57 [ V_23 ] ) ;
V_59 = F_16 ( & V_64 ) ;
if ( V_59 ) {
F_41 ( L_20 ,
V_40 , V_59 ) ;
return V_59 ;
}
return 0 ;
}
int F_42 ( T_6 V_65 , char * V_66 , int V_67 )
{
T_7 V_51 ;
T_5 V_52 , V_68 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_29 ( & V_52 ) ;
if ( ( F_30 ( V_52 ) & V_69 ) == 0 )
return 0 ;
V_68 = F_43 ( V_67 ) ;
V_51 = F_44 ( V_65 , & V_68 , V_66 ) ;
if ( V_51 == V_53 )
return F_30 ( V_68 ) ;
return 0 ;
}
int F_45 ( T_6 V_65 , const char * V_6 , int V_70 )
{
int V_71 = 0 ;
T_5 V_72 ;
T_7 V_68 , V_51 ;
unsigned long V_44 ;
T_5 V_52 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_23 ( & V_73 , V_44 ) ;
if ( F_46 ( V_19 ) ) {
V_51 = F_47 ( V_65 , & V_72 ) ;
V_68 = F_30 ( V_72 ) ;
if ( V_51 || V_68 < V_70 ) {
F_24 ( & V_73 , V_44 ) ;
if ( V_51 )
return V_70 ;
F_29 ( NULL ) ;
return - V_74 ;
}
}
V_51 = V_75 ;
while( V_70 > 0 && ( V_51 == V_75 ||
V_51 == V_76 || V_51 == V_53 ) ) {
V_72 = F_43 ( V_70 ) ;
V_51 = F_48 ( V_65 , & V_72 , V_6 ) ;
V_68 = F_30 ( V_72 ) ;
if ( V_51 != V_53 && V_51 != V_75 &&
V_51 != V_76 ) {
V_71 = V_70 ;
break;
}
if ( V_51 == V_53 ) {
V_70 -= V_68 ;
V_6 += V_68 ;
V_71 += V_68 ;
}
do
F_29 ( & V_52 ) ;
while( V_51 == V_53 &&
( F_30 ( V_52 ) & V_77 ) );
}
F_24 ( & V_73 , V_44 ) ;
return V_71 ;
}
static int F_49 ( struct V_78 * V_79 ,
struct V_80 * V_52 )
{
int V_81 = 0 ;
T_3 V_82 = F_50 ( V_52 ) ;
if ( ! ( V_79 -> V_83 & V_84 ) ) {
V_81 = 0 ;
} else if ( V_52 -> V_85 == V_86 ) {
V_81 = 1 ;
} else if ( V_82 && ! F_51 ( V_82 ) ) {
if ( F_52 ( V_79 ) && ! F_53 ( V_87 ) ) {
F_54 ( V_88 , V_79 , V_89 , V_79 -> V_90 ) ;
V_81 = 1 ;
} else
V_81 = 0 ;
} else if ( F_52 ( V_79 ) && ! F_53 ( V_87 ) &&
V_52 -> V_91 == V_92 ) {
F_54 ( V_88 , V_79 , V_89 , V_79 -> V_90 ) ;
V_81 = 1 ;
}
return V_81 ;
}
int F_55 ( struct V_78 * V_79 )
{
struct V_80 V_52 ;
if ( ! F_56 ( & V_52 , V_93 ) )
return 0 ;
if ( V_52 . V_94 != V_95 ) {
F_41 ( L_21 ,
V_52 . V_94 ) ;
return 0 ;
}
F_57 ( & V_52 ) ;
if ( F_49 ( V_79 , & V_52 ) )
return 1 ;
return 0 ;
}
static T_3 F_58 ( T_3 V_90 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
if ( ( V_90 >= V_28 [ V_23 ] . V_31 ) &&
( V_90 < V_28 [ V_23 ] . V_32 ) )
return V_28 [ V_23 ] . V_33 ;
return 0 ;
}
bool F_59 ( struct V_78 * V_79 )
{
T_3 V_33 = 0 ;
if ( ! V_13 . V_14 || ! V_13 . V_16 )
goto V_96;
if ( ( V_79 -> V_90 >= V_13 . V_14 ) &&
( V_79 -> V_90 <= ( V_13 . V_14 + V_13 . V_16 ) ) )
V_33 = F_58 ( V_79 -> V_90 ) ;
if ( V_33 )
V_79 -> V_90 = V_33 ;
V_96:
return ! ! V_33 ;
}
static T_9 F_60 ( int V_97 , void * V_6 )
{
T_5 V_43 ;
F_61 ( F_62 ( V_97 ) , & V_43 ) ;
F_21 ( F_30 ( V_43 ) ) ;
return V_98 ;
}
static int F_63 ( void )
{
V_99 = F_64 ( L_22 , V_100 ) ;
if ( ! V_99 ) {
F_65 ( L_23 ) ;
return - V_101 ;
}
return 0 ;
}
static int T_1 F_66 ( void )
{
struct V_102 * V_103 , * V_104 ;
const T_2 * V_105 ;
int V_51 , V_23 , V_106 ;
V_107 = F_67 ( L_24 ) ;
if ( ! V_107 ) {
F_65 ( L_25 ) ;
return - V_35 ;
}
if ( F_46 ( V_19 ) )
V_104 = F_67 ( L_26 ) ;
else
V_104 = F_68 ( V_107 ) ;
if ( V_104 ) {
F_69 (consoles, np) {
if ( strcmp ( V_103 -> V_108 , L_27 ) )
continue;
F_70 ( V_103 , NULL , NULL ) ;
}
F_71 ( V_104 ) ;
}
V_105 = F_72 ( V_107 , L_28 , & V_106 ) ;
F_7 ( L_29 ,
V_105 ? ( V_106 / 4 ) : 0 ) ;
V_109 = V_106 / 4 ;
V_110 = F_73 ( V_109 * sizeof( unsigned int ) , V_111 ) ;
for ( V_23 = 0 ; V_105 && V_23 < ( V_106 / 4 ) ; V_23 ++ , V_105 ++ ) {
unsigned int V_112 = F_74 ( V_105 ) ;
unsigned int V_97 = F_75 ( NULL , V_112 ) ;
if ( V_97 == V_113 ) {
F_17 ( L_30 , V_112 ) ;
continue;
}
V_51 = F_76 ( V_97 , F_60 , 0 , L_22 , NULL ) ;
if ( V_51 )
F_17 ( L_31
L_32 , V_51 , V_97 , V_112 ) ;
V_110 [ V_23 ] = V_97 ;
}
V_51 = F_63 () ;
if ( V_51 == 0 ) {
V_51 = F_77 () ;
F_78 () ;
F_79 () ;
F_80 () ;
F_81 () ;
}
return 0 ;
}
void F_82 ( void )
{
unsigned int V_23 ;
long V_51 = V_75 ;
for ( V_23 = 0 ; V_23 < V_109 ; V_23 ++ ) {
if ( V_110 [ V_23 ] )
F_83 ( V_110 [ V_23 ] , NULL ) ;
V_110 [ V_23 ] = 0 ;
}
while ( V_51 == V_75 || V_51 == V_76 ) {
V_51 = F_84 () ;
if ( V_51 == V_75 )
F_29 ( NULL ) ;
else
F_85 ( 10 ) ;
}
}
struct V_114 * F_86 ( void * V_115 ,
unsigned long V_116 )
{
struct V_114 * V_117 , * V_118 = NULL ;
unsigned long V_23 = 0 ;
V_117 = F_73 ( V_119 , V_111 ) ;
if ( ! V_117 )
goto V_120;
V_118 = V_117 ;
while ( V_116 > 0 ) {
T_3 V_6 = F_87 ( V_115 ) << V_121 ;
T_3 V_122 = F_88 ( V_116 , V_119 ) ;
V_117 -> V_15 [ V_23 ] . V_6 = F_43 ( V_6 ) ;
V_117 -> V_15 [ V_23 ] . V_122 = F_43 ( V_122 ) ;
V_23 ++ ;
if ( V_23 >= V_123 ) {
struct V_114 * V_124 ;
V_124 = F_73 ( V_119 , V_111 ) ;
if ( ! V_124 )
goto V_120;
V_117 -> V_122 = F_43 (
V_23 * sizeof( struct V_125 ) + 16 ) ;
V_23 = 0 ;
V_117 -> V_124 = F_43 ( F_36 ( V_124 ) ) ;
V_117 = V_124 ;
}
V_115 += V_122 ;
V_116 -= V_122 ;
}
V_117 -> V_122 = F_43 ( V_23 * sizeof( struct V_125 ) + 16 ) ;
return V_118 ;
V_120:
F_41 ( L_33 , V_40 ) ;
F_89 ( V_118 ) ;
return NULL ;
}
void F_89 ( struct V_114 * V_117 )
{
while ( V_117 ) {
T_3 V_124 = F_30 ( V_117 -> V_124 ) ;
F_90 ( V_117 ) ;
if ( V_124 )
V_117 = F_11 ( V_124 ) ;
else
V_117 = NULL ;
}
}
