static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_2 == V_2 ) {
F_5 ( & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_7 ( & V_5 ) ;
return V_3 ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
V_3 = NULL ;
F_7 ( & V_5 ) ;
return V_3 ;
}
static void F_8 ( struct V_8 * V_9 , const char * V_10 ,
unsigned V_11 )
{
char V_12 [ V_13 ] V_14 ;
unsigned V_15 = 0 , V_16 = 0 ;
int V_17 , V_18 = 0 , V_2 = V_9 -> V_2 ;
if ( V_2 >= V_19 )
return;
if ( V_20 [ V_2 ] == - 1 )
return;
while ( V_11 > 0 || V_15 > 0 ) {
if ( V_11 > 0 && V_15 < sizeof( V_12 ) ) {
if ( V_10 [ V_16 ] == '\n' && ! V_18 ) {
V_12 [ V_15 ++ ] = '\r' ;
V_18 = 1 ;
} else {
V_12 [ V_15 ++ ] = V_10 [ V_16 ++ ] ;
V_18 = 0 ;
-- V_11 ;
}
} else {
V_17 = V_21 [ V_2 ] -> F_9 ( V_20 [ V_2 ] , V_12 , V_15 ) ;
if ( V_17 <= 0 ) {
if ( V_17 != - V_22 )
V_15 = 0 ;
} else if ( V_17 > 0 ) {
V_15 -= V_17 ;
if ( V_15 > 0 )
memmove ( V_12 , V_12 + V_17 , V_15 ) ;
}
}
}
}
static struct V_23 * F_10 ( struct V_8 * V_12 , int * V_2 )
{
if ( V_20 [ V_12 -> V_2 ] == - 1 )
return NULL ;
* V_2 = V_12 -> V_2 ;
return V_24 ;
}
static int T_1 F_11 ( struct V_8 * V_9 , char * V_25 )
{
if ( V_9 -> V_2 < 0 || V_9 -> V_2 >= V_19 )
return - V_26 ;
if ( V_20 [ V_9 -> V_2 ] == - 1 )
return - V_26 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_27 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_7 )
{
struct V_1 * V_3 = F_15 ( V_7 , struct V_1 , V_7 ) ;
unsigned long V_4 ;
F_2 ( & V_5 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
F_16 ( & ( V_3 -> V_28 ) ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_7 ( & V_5 ) ;
F_17 ( V_3 ) ;
}
int F_18 ( T_2 V_29 , int V_2 , const struct V_30 * V_31 )
{
struct V_1 * V_3 ;
if ( V_2 < 0 || V_2 >= V_19 )
return - 1 ;
if ( V_20 [ V_2 ] != - 1 )
return - 1 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_19 ( & V_3 -> V_7 , F_14 ) ;
return - 1 ;
}
V_20 [ V_2 ] = V_29 ;
V_21 [ V_2 ] = V_31 ;
if ( V_32 < V_2 )
V_32 = V_2 ;
if ( V_2 == V_27 . V_2 )
F_13 ( & V_27 ) ;
return 0 ;
}
void F_20 ( void )
{
V_33 = 1 ;
F_21 ( V_34 ) ;
}
static void F_22 ( struct V_35 * V_36 )
{
F_20 () ;
}
static int F_23 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_39 = 0 ;
if ( ! ( V_3 = F_1 ( V_36 -> V_2 ) ) )
return - V_26 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_11 ++ > 0 ) {
F_24 ( V_36 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_20 () ;
return 0 ;
}
V_36 -> V_40 = V_3 ;
V_3 -> V_36 = F_24 ( V_36 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_31 -> V_41 )
V_39 = V_3 -> V_31 -> V_41 ( V_3 , V_3 -> V_42 ) ;
if ( V_39 ) {
F_4 ( & V_3 -> V_6 , V_4 ) ;
V_3 -> V_36 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_25 ( V_36 ) ;
V_36 -> V_40 = NULL ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
F_26 ( V_43 L_1 , V_39 ) ;
}
F_20 () ;
return V_39 ;
}
static void F_27 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
if ( F_28 ( V_38 ) )
return;
if ( ! V_36 -> V_40 )
return;
V_3 = V_36 -> V_40 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( -- V_3 -> V_11 == 0 ) {
V_3 -> V_36 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_31 -> V_44 )
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_42 ) ;
F_29 ( & V_3 -> V_45 ) ;
F_30 ( V_36 , V_46 ) ;
} else {
if ( V_3 -> V_11 < 0 )
F_26 ( V_43 L_2 ,
V_3 -> V_29 , V_3 -> V_11 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
F_25 ( V_36 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
unsigned long V_4 ;
int V_47 ;
if ( ! V_3 )
return;
F_29 ( & V_3 -> V_45 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_11 <= 0 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
return;
}
V_47 = V_3 -> V_11 ;
V_3 -> V_11 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_36 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_31 -> V_49 )
V_3 -> V_31 -> V_49 ( V_3 , V_3 -> V_42 ) ;
while( V_47 ) {
-- V_47 ;
F_25 ( V_36 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
}
}
static int F_32 ( struct V_1 * V_3 )
{
int V_16 ;
V_16 = V_3 -> V_31 -> F_9 ( V_3 -> V_29 , V_3 -> V_50 , V_3 -> V_48 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == 0 || V_16 == - V_22 ) {
V_3 -> V_51 = 1 ;
return 0 ;
}
V_3 -> V_48 = 0 ;
} else
V_3 -> V_48 -= V_16 ;
if ( V_3 -> V_48 > 0 )
memmove ( V_3 -> V_50 , V_3 -> V_50 + V_16 , V_3 -> V_48 ) ;
else
V_3 -> V_51 = 1 ;
return V_16 ;
}
static int F_33 ( struct V_35 * V_36 , const unsigned char * V_52 , int V_11 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
unsigned long V_4 ;
int V_53 , V_54 = 0 ;
if ( ! V_3 )
return - V_55 ;
if ( V_3 -> V_11 <= 0 )
return - V_56 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_48 > 0 )
F_32 ( V_3 ) ;
while ( V_11 > 0 && ( V_53 = V_3 -> V_57 - V_3 -> V_48 ) > 0 ) {
if ( V_53 > V_11 )
V_53 = V_11 ;
memcpy ( V_3 -> V_50 + V_3 -> V_48 , V_52 , V_53 ) ;
V_11 -= V_53 ;
V_52 += V_53 ;
V_3 -> V_48 += V_53 ;
V_54 += V_53 ;
F_32 ( V_3 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_48 )
F_20 () ;
return V_54 ;
}
static void F_34 ( struct V_58 * V_59 )
{
struct V_1 * V_3 ;
unsigned long V_60 ;
struct V_35 * V_36 ;
struct V_61 V_62 ;
V_3 = F_15 ( V_59 , struct V_1 , V_45 ) ;
F_4 ( & V_3 -> V_6 , V_60 ) ;
if ( ! V_3 -> V_36 ) {
F_6 ( & V_3 -> V_6 , V_60 ) ;
return;
}
V_62 = V_3 -> V_62 ;
V_36 = F_24 ( V_3 -> V_36 ) ;
F_6 ( & V_3 -> V_6 , V_60 ) ;
F_35 ( V_36 , & V_62 ) ;
F_25 ( V_36 ) ;
}
static int F_36 ( struct V_35 * V_36 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
if ( ! V_3 )
return - 1 ;
return V_3 -> V_57 - V_3 -> V_48 ;
}
static int F_37 ( struct V_35 * V_36 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_48 ;
}
int F_38 ( struct V_1 * V_3 )
{
struct V_35 * V_36 ;
int V_15 , V_16 , V_63 = 0 ;
char V_52 [ V_64 ] V_14 ;
unsigned long V_4 ;
int V_65 = 0 ;
int V_66 = 0 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_48 > 0 )
V_66 = F_32 ( V_3 ) ;
if ( V_3 -> V_48 > 0 ) {
V_63 |= V_67 ;
V_68 = ( V_66 ) ? 0 : V_69 ;
}
V_36 = F_24 ( V_3 -> V_36 ) ;
if ( V_36 == NULL )
goto V_70;
if ( F_39 ( V_71 , & V_36 -> V_4 ) )
goto V_72;
if ( ! V_3 -> V_73 )
V_63 |= V_74 ;
for (; ; ) {
int V_11 = F_40 ( V_36 , V_64 ) ;
if ( V_11 == 0 ) {
V_63 |= V_74 ;
break;
}
V_16 = V_3 -> V_31 -> V_75 ( V_3 -> V_29 , V_52 , V_11 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == - V_55 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_41 ( V_36 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
} else if ( V_16 == - V_22 ) {
V_63 |= V_74 ;
}
break;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
#ifdef F_42
if ( V_3 -> V_2 == V_27 . V_2 ) {
if ( V_52 [ V_15 ] == '\x0f' ) {
V_76 = ! V_76 ;
if ( V_76 )
continue;
} else if ( V_76 ) {
F_43 ( V_52 [ V_15 ] ) ;
V_76 = 0 ;
continue;
}
}
#endif
F_44 ( V_36 , V_52 [ V_15 ] , 0 ) ;
}
V_65 += V_16 ;
}
V_72:
if ( V_3 -> V_51 ) {
V_3 -> V_51 = 0 ;
F_45 ( V_36 ) ;
}
V_70:
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_65 ) {
V_68 = V_69 ;
F_46 ( V_36 ) ;
}
if ( V_36 )
F_25 ( V_36 ) ;
return V_63 ;
}
void F_47 ( struct V_1 * V_3 , struct V_61 V_62 )
{
V_3 -> V_62 = V_62 ;
F_48 ( & V_3 -> V_45 ) ;
}
static int F_49 ( void * V_77 )
{
int V_63 ;
struct V_1 * V_3 ;
F_50 () ;
do {
V_63 = 0 ;
V_33 = 0 ;
F_51 () ;
F_52 () ;
if ( ! F_53 () ) {
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
V_63 |= F_38 ( V_3 ) ;
}
F_7 ( & V_5 ) ;
} else
V_63 |= V_74 ;
if ( V_33 )
continue;
F_54 ( V_78 ) ;
if ( ! V_33 ) {
if ( V_63 == 0 )
F_55 () ;
else {
if ( V_68 < V_79 )
V_68 += ( V_68 >> 6 ) + 1 ;
F_56 ( V_68 ) ;
}
}
F_57 ( V_80 ) ;
} while ( ! F_58 () );
return 0 ;
}
static int F_59 ( struct V_35 * V_36 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
if ( ! V_3 || ! V_3 -> V_31 -> V_81 )
return - V_82 ;
return V_3 -> V_31 -> V_81 ( V_3 ) ;
}
static int F_60 ( struct V_35 * V_36 ,
unsigned int V_83 , unsigned int V_84 )
{
struct V_1 * V_3 = V_36 -> V_40 ;
if ( ! V_3 || ! V_3 -> V_31 -> V_85 )
return - V_82 ;
return V_3 -> V_31 -> V_85 ( V_3 , V_83 , V_84 ) ;
}
int F_61 ( struct V_23 * V_86 , int line , char * V_25 )
{
return 0 ;
}
static int F_62 ( struct V_23 * V_86 , int line )
{
struct V_35 * V_36 = V_86 -> V_87 [ 0 ] ;
struct V_1 * V_3 = V_36 -> V_40 ;
int V_16 ;
char V_88 ;
V_16 = V_3 -> V_31 -> V_75 ( V_3 -> V_29 , & V_88 , 1 ) ;
if ( V_16 == 0 )
return V_89 ;
return V_88 ;
}
static void F_63 ( struct V_23 * V_86 , int line , char V_88 )
{
struct V_35 * V_36 = V_86 -> V_87 [ 0 ] ;
struct V_1 * V_3 = V_36 -> V_40 ;
int V_16 ;
do {
V_16 = V_3 -> V_31 -> F_9 ( V_3 -> V_29 , & V_88 , 1 ) ;
} while ( V_16 <= 0 );
}
struct V_1 * F_64 ( T_2 V_29 , int V_42 ,
const struct V_30 * V_31 ,
int V_57 )
{
struct V_1 * V_3 ;
int V_15 ;
if ( ! V_24 ) {
int V_90 = F_65 () ;
if ( V_90 )
return F_66 ( V_90 ) ;
}
V_3 = F_67 ( F_68 ( sizeof( * V_3 ) , sizeof( long ) ) + V_57 ,
V_91 ) ;
if ( ! V_3 )
return F_66 ( - V_92 ) ;
V_3 -> V_29 = V_29 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_57 = V_57 ;
V_3 -> V_50 = & ( ( char * ) V_3 ) [ F_68 ( sizeof( * V_3 ) , sizeof( long ) ) ] ;
F_69 ( & V_3 -> V_7 ) ;
F_70 ( & V_3 -> V_45 , F_34 ) ;
F_71 ( & V_3 -> V_6 ) ;
F_2 ( & V_5 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
if ( V_20 [ V_15 ] == V_3 -> V_29 &&
V_21 [ V_15 ] == V_3 -> V_31 )
break;
if ( V_15 >= V_19 )
V_15 = ++ V_32 ;
V_3 -> V_2 = V_15 ;
F_72 ( & ( V_3 -> V_28 ) , & V_93 ) ;
F_7 ( & V_5 ) ;
return V_3 ;
}
int F_73 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
struct V_35 * V_36 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
V_36 = F_24 ( V_3 -> V_36 ) ;
if ( V_3 -> V_2 < V_19 )
V_20 [ V_3 -> V_2 ] = - 1 ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
if ( V_36 ) {
F_74 ( V_36 ) ;
F_25 ( V_36 ) ;
}
return 0 ;
}
static int F_65 ( void )
{
struct V_23 * V_94 ;
int V_90 ;
V_94 = F_75 ( V_95 ) ;
if ( ! V_94 ) {
V_90 = - V_92 ;
goto V_96;
}
V_94 -> V_97 = L_3 ;
V_94 -> V_98 = L_3 ;
V_94 -> V_99 = V_100 ;
V_94 -> V_101 = V_102 ;
V_94 -> type = V_103 ;
V_94 -> V_104 = V_105 ;
V_94 -> V_4 = V_106 | V_107 ;
F_76 ( V_94 , & V_108 ) ;
V_34 = F_77 ( F_49 , NULL , L_4 ) ;
if ( F_78 ( V_34 ) ) {
F_26 ( V_43 L_5 ) ;
V_90 = F_79 ( V_34 ) ;
goto V_109;
}
V_90 = F_80 ( V_94 ) ;
if ( V_90 ) {
F_26 ( V_43 L_6 ) ;
goto V_110;
}
F_81 () ;
V_24 = V_94 ;
return 0 ;
V_110:
F_82 ( V_34 ) ;
V_34 = NULL ;
V_109:
F_83 ( V_94 ) ;
V_96:
return V_90 ;
}
static void T_3 F_84 ( void )
{
if ( V_24 ) {
F_82 ( V_34 ) ;
F_85 ( V_24 ) ;
F_83 ( V_24 ) ;
F_86 ( & V_27 ) ;
}
}
