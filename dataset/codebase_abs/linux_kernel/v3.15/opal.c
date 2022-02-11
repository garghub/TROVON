int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
const void * V_5 , * V_6 , * V_7 ;
unsigned long V_8 , V_9 , V_10 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_5 = F_2 ( V_1 , L_2 , & V_8 ) ;
V_6 = F_2 ( V_1 , L_3 , & V_9 ) ;
V_7 = F_2 ( V_1 , L_4 , & V_10 ) ;
if ( ! V_5 || ! V_6 || ! V_7 )
return 1 ;
V_11 . V_12 = F_3 ( V_5 , V_8 / 4 ) ;
V_11 . V_13 = F_3 ( V_6 , V_9 / 4 ) ;
V_11 . V_14 = F_3 ( V_7 , V_10 / 4 ) ;
F_4 ( L_5 ,
V_11 . V_12 , V_5 , V_8 ) ;
F_4 ( L_6 ,
V_11 . V_13 , V_6 , V_9 ) ;
F_4 ( L_7 ,
V_11 . V_14 , V_7 , V_10 ) ;
V_15 |= V_16 ;
if ( F_5 ( V_1 , L_8 ) ) {
V_15 |= V_17 ;
V_15 |= V_18 ;
F_6 ( L_9 ) ;
} else if ( F_5 ( V_1 , L_10 ) ) {
V_15 |= V_17 ;
F_6 ( L_11 ) ;
} else {
F_6 ( L_12 ) ;
}
return 1 ;
}
int T_1 F_7 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
unsigned long V_19 , V_20 , V_14 ;
const T_2 * V_21 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_21 = F_2 ( V_1 , L_13 , & V_20 ) ;
if ( ! V_21 )
return 1 ;
F_4 ( L_14 ) ;
V_22 = V_20 / ( sizeof( * V_21 ) * 5 ) ;
if ( ! V_22 )
return 1 ;
V_14 = V_22 *
sizeof( struct V_23 ) ;
V_24 = F_8 ( F_9 ( V_14 , F_10 ( V_25 ) ,
V_26 ) ) ;
memset ( V_24 , 0 , V_14 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_24 [ V_19 ] . V_27 =
F_3 ( V_21 + ( V_19 * 5 ) + 0 , 2 ) ;
V_24 [ V_19 ] . V_28 =
V_24 [ V_19 ] . V_27 +
F_3 ( V_21 + ( V_19 * 5 ) + 2 , 1 ) ;
V_24 [ V_19 ] . V_29 =
F_3 ( V_21 + ( V_19 * 5 ) + 3 , 2 ) ;
F_4 ( L_15 ,
V_24 [ V_19 ] . V_27 ,
V_24 [ V_19 ] . V_28 ,
V_24 [ V_19 ] . V_29 ) ;
}
return 1 ;
}
static int T_1 F_11 ( void )
{
#ifdef F_12
V_25 V_30 ;
if ( ! ( V_15 & V_16 ) )
return - V_31 ;
V_30 = 0x7000 ;
F_13 ( V_32 ,
0 , V_30 ) ;
V_30 += 128 ;
F_13 ( V_33 , 0 , V_30 ) ;
#endif
return 0 ;
}
int F_14 ( struct V_34 * V_35 )
{
if ( ! V_35 ) {
F_15 ( L_16 ,
V_36 , V_35 ) ;
return - V_37 ;
}
F_16 ( & V_38 , V_35 ) ;
return 0 ;
}
int F_17 ( struct V_34 * V_35 )
{
if ( ! V_35 ) {
F_15 ( L_16 ,
V_36 , V_35 ) ;
return - V_37 ;
}
F_18 ( & V_38 , V_35 ) ;
return 0 ;
}
static void F_19 ( T_3 V_39 )
{
unsigned long V_40 ;
T_3 V_41 ;
if ( F_20 ( & V_42 ) )
return;
F_21 ( & V_43 , V_40 ) ;
V_41 = V_44 ^ V_39 ;
V_44 = V_39 ;
F_22 ( & V_43 , V_40 ) ;
F_23 ( & V_38 ,
V_39 , ( void * ) V_41 ) ;
}
void F_24 ( T_3 V_45 ,
T_3 V_46 )
{
unsigned long V_40 ;
F_21 ( & V_43 , V_40 ) ;
V_44 &= ~ V_45 ;
V_44 |= V_46 ;
F_22 ( & V_43 , V_40 ) ;
}
void F_25 ( void )
{
T_4 V_47 ;
T_5 V_48 = 0 ;
F_26 ( & V_42 , 0 ) ;
V_47 = F_27 ( & V_48 ) ;
if ( V_47 == V_49 && V_48 )
F_19 ( F_28 ( V_48 ) ) ;
}
void F_29 ( void )
{
F_26 ( & V_42 , 1 ) ;
}
int F_30 ( enum V_50 V_51 ,
struct V_34 * V_35 )
{
if ( ! V_35 ) {
F_15 ( L_16 ,
V_36 , V_35 ) ;
return - V_37 ;
}
if ( V_51 > V_52 ) {
F_15 ( L_17 ,
V_36 , V_51 ) ;
return - V_37 ;
}
return F_16 (
& V_53 [ V_51 ] , V_35 ) ;
}
static void F_31 ( T_6 V_51 , void * V_54 )
{
F_23 ( & V_53 [ V_51 ] ,
V_51 , V_54 ) ;
}
static void F_32 ( void )
{
T_7 V_55 ;
static struct V_56 V_54 ;
T_8 type ;
V_55 = F_33 ( F_34 ( & V_54 ) , sizeof( V_54 ) ) ;
if ( V_55 == V_57 )
return;
if ( V_55 ) {
F_15 ( L_18 ,
V_36 , V_55 ) ;
return;
}
type = F_35 ( V_54 . V_51 ) ;
if ( type > V_52 ) {
F_15 ( L_19 , V_36 , type ) ;
return;
}
F_31 ( type , ( void * ) & V_54 ) ;
}
static int F_36 ( struct V_34 * V_35 ,
unsigned long V_39 , void * V_58 )
{
if ( V_39 & V_59 )
F_32 () ;
return 0 ;
}
static int T_1 F_37 ( void )
{
int V_55 , V_19 ;
for ( V_19 = 0 ; V_19 < V_52 ; V_19 ++ )
F_38 ( & V_53 [ V_19 ] ) ;
V_55 = F_14 ( & V_60 ) ;
if ( V_55 ) {
F_39 ( L_20 ,
V_36 , V_55 ) ;
return V_55 ;
}
return 0 ;
}
int F_40 ( T_6 V_61 , char * V_62 , int V_63 )
{
T_7 V_47 ;
T_5 V_48 , V_64 ;
if ( ! V_11 . V_13 )
return - V_31 ;
F_27 ( & V_48 ) ;
if ( ( F_28 ( V_48 ) & V_65 ) == 0 )
return 0 ;
V_64 = F_41 ( V_63 ) ;
V_47 = F_42 ( V_61 , & V_64 , V_62 ) ;
if ( V_47 == V_49 )
return F_28 ( V_64 ) ;
return 0 ;
}
int F_43 ( T_6 V_61 , const char * V_4 , int V_66 )
{
int V_67 = 0 ;
T_5 V_68 ;
T_7 V_64 , V_47 ;
unsigned long V_40 ;
T_5 V_48 ;
if ( ! V_11 . V_13 )
return - V_31 ;
F_21 ( & V_69 , V_40 ) ;
if ( F_44 ( V_17 ) ) {
V_47 = F_45 ( V_61 , & V_68 ) ;
V_64 = F_28 ( V_68 ) ;
if ( V_47 || V_64 < V_66 ) {
F_22 ( & V_69 , V_40 ) ;
if ( V_47 )
return V_66 ;
F_27 ( NULL ) ;
return - V_70 ;
}
}
V_47 = V_71 ;
while( V_66 > 0 && ( V_47 == V_71 ||
V_47 == V_72 || V_47 == V_49 ) ) {
V_68 = F_41 ( V_66 ) ;
V_47 = F_46 ( V_61 , & V_68 , V_4 ) ;
V_64 = F_28 ( V_68 ) ;
if ( V_47 != V_49 && V_47 != V_71 &&
V_47 != V_72 ) {
V_67 = V_66 ;
break;
}
if ( V_47 == V_49 ) {
V_66 -= V_64 ;
V_4 += V_64 ;
V_67 += V_64 ;
}
do
F_27 ( & V_48 ) ;
while( V_47 == V_49 &&
( F_28 ( V_48 ) & V_73 ) );
}
F_22 ( & V_69 , V_40 ) ;
return V_67 ;
}
static int F_47 ( struct V_74 * V_75 ,
struct V_76 * V_48 )
{
int V_77 = 0 ;
T_3 V_78 = F_48 ( V_48 ) ;
if ( ! ( V_75 -> V_79 & V_80 ) ) {
V_77 = 0 ;
} else if ( V_48 -> V_81 == V_82 ) {
V_77 = 1 ;
} else if ( V_78 && ! F_49 ( V_78 ) ) {
if ( F_50 ( V_75 ) && ! F_51 ( V_83 ) ) {
F_52 ( V_84 , V_75 , V_85 , V_75 -> V_86 ) ;
V_77 = 1 ;
} else
V_77 = 0 ;
} else if ( F_50 ( V_75 ) && ! F_51 ( V_83 ) &&
V_48 -> V_87 == V_88 ) {
F_52 ( V_84 , V_75 , V_85 , V_75 -> V_86 ) ;
V_77 = 1 ;
}
return V_77 ;
}
int F_53 ( struct V_74 * V_75 )
{
struct V_76 V_48 ;
if ( ! F_54 ( & V_48 , V_89 ) )
return 0 ;
if ( V_48 . V_90 != V_91 ) {
F_39 ( L_21 ,
V_48 . V_90 ) ;
return 0 ;
}
F_55 ( & V_48 ) ;
if ( F_47 ( V_75 , & V_48 ) )
return 1 ;
return 0 ;
}
static T_3 F_56 ( T_3 V_86 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
if ( ( V_86 >= V_24 [ V_19 ] . V_27 ) &&
( V_86 < V_24 [ V_19 ] . V_28 ) )
return V_24 [ V_19 ] . V_29 ;
return 0 ;
}
bool F_57 ( struct V_74 * V_75 )
{
T_3 V_29 = 0 ;
if ( ! V_11 . V_12 || ! V_11 . V_14 )
goto V_92;
if ( ( V_75 -> V_86 >= V_11 . V_12 ) &&
( V_75 -> V_86 <= ( V_11 . V_12 + V_11 . V_14 ) ) )
V_29 = F_56 ( V_75 -> V_86 ) ;
if ( V_29 )
V_75 -> V_86 = V_29 ;
V_92:
return ! ! V_29 ;
}
static T_9 F_58 ( int V_93 , void * V_4 )
{
T_5 V_39 ;
F_59 ( F_60 ( V_93 ) , & V_39 ) ;
F_19 ( F_28 ( V_39 ) ) ;
return V_94 ;
}
static int F_61 ( void )
{
V_95 = F_62 ( L_22 , V_96 ) ;
if ( ! V_95 ) {
F_63 ( L_23 ) ;
return - V_97 ;
}
return 0 ;
}
static int T_1 F_64 ( void )
{
struct V_98 * V_99 , * V_100 ;
const T_2 * V_101 ;
int V_47 , V_19 , V_102 ;
V_103 = F_65 ( L_24 ) ;
if ( ! V_103 ) {
F_63 ( L_25 ) ;
return - V_31 ;
}
if ( F_44 ( V_17 ) )
V_100 = F_65 ( L_26 ) ;
else
V_100 = F_66 ( V_103 ) ;
if ( V_100 ) {
F_67 (consoles, np) {
if ( strcmp ( V_99 -> V_104 , L_27 ) )
continue;
F_68 ( V_99 , NULL , NULL ) ;
}
F_69 ( V_100 ) ;
}
V_101 = F_70 ( V_103 , L_28 , & V_102 ) ;
F_4 ( L_29 ,
V_101 ? ( V_102 / 4 ) : 0 ) ;
V_105 = V_102 / 4 ;
V_106 = F_71 ( V_105 * sizeof( unsigned int ) , V_107 ) ;
for ( V_19 = 0 ; V_101 && V_19 < ( V_102 / 4 ) ; V_19 ++ , V_101 ++ ) {
unsigned int V_108 = F_72 ( V_101 ) ;
unsigned int V_93 = F_73 ( NULL , V_108 ) ;
if ( V_93 == V_109 ) {
F_15 ( L_30 , V_108 ) ;
continue;
}
V_47 = F_74 ( V_93 , F_58 , 0 , L_22 , NULL ) ;
if ( V_47 )
F_15 ( L_31
L_32 , V_47 , V_93 , V_108 ) ;
V_106 [ V_19 ] = V_93 ;
}
V_47 = F_61 () ;
if ( V_47 == 0 ) {
V_47 = F_75 () ;
F_76 () ;
F_77 () ;
F_78 () ;
F_79 () ;
}
return 0 ;
}
void F_80 ( void )
{
unsigned int V_19 ;
long V_47 = V_71 ;
for ( V_19 = 0 ; V_19 < V_105 ; V_19 ++ ) {
if ( V_106 [ V_19 ] )
F_81 ( V_106 [ V_19 ] , NULL ) ;
V_106 [ V_19 ] = 0 ;
}
while ( V_47 == V_71 || V_47 == V_72 ) {
V_47 = F_82 () ;
if ( V_47 == V_71 )
F_27 ( NULL ) ;
else
F_83 ( 10 ) ;
}
}
struct V_110 * F_84 ( void * V_111 ,
unsigned long V_112 )
{
struct V_110 * V_113 , * V_114 = NULL ;
unsigned long V_19 = 0 ;
V_113 = F_71 ( V_115 , V_107 ) ;
if ( ! V_113 )
goto V_116;
V_114 = V_113 ;
while ( V_112 > 0 ) {
T_3 V_4 = F_85 ( V_111 ) << V_117 ;
T_3 V_118 = F_86 ( V_112 , V_115 ) ;
V_113 -> V_13 [ V_19 ] . V_4 = F_41 ( V_4 ) ;
V_113 -> V_13 [ V_19 ] . V_118 = F_41 ( V_118 ) ;
V_19 ++ ;
if ( V_19 >= V_119 ) {
struct V_110 * V_120 ;
V_120 = F_71 ( V_115 , V_107 ) ;
if ( ! V_120 )
goto V_116;
V_113 -> V_118 = F_41 (
V_19 * sizeof( struct V_121 ) + 16 ) ;
V_19 = 0 ;
V_113 -> V_120 = F_41 ( F_34 ( V_120 ) ) ;
V_113 = V_120 ;
}
V_111 += V_118 ;
V_112 -= V_118 ;
}
V_113 -> V_118 = F_41 ( V_19 * sizeof( struct V_121 ) + 16 ) ;
return V_114 ;
V_116:
F_39 ( L_33 , V_36 ) ;
F_87 ( V_114 ) ;
return NULL ;
}
void F_87 ( struct V_110 * V_113 )
{
while ( V_113 ) {
T_3 V_120 = F_28 ( V_113 -> V_120 ) ;
F_88 ( V_113 ) ;
if ( V_120 )
V_113 = F_8 ( V_120 ) ;
else
V_113 = NULL ;
}
}
