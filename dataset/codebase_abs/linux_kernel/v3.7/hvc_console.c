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
static void F_14 ( struct V_28 * V_7 )
{
struct V_1 * V_3 = F_15 ( V_7 , struct V_1 , V_7 ) ;
unsigned long V_4 ;
F_2 ( & V_5 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
F_16 ( & ( V_3 -> V_29 ) ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_7 ( & V_5 ) ;
F_17 ( V_3 ) ;
}
static void F_18 ( int V_2 )
{
if ( V_27 . V_4 & V_30 )
return;
if ( V_2 == V_27 . V_2 )
F_13 ( & V_27 ) ;
}
int F_19 ( T_2 V_31 , int V_2 , const struct V_32 * V_33 )
{
struct V_1 * V_3 ;
if ( V_2 < 0 || V_2 >= V_19 )
return - 1 ;
if ( V_20 [ V_2 ] != - 1 )
return - 1 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_20 ( & V_3 -> V_7 ) ;
return - 1 ;
}
V_20 [ V_2 ] = V_31 ;
V_21 [ V_2 ] = V_33 ;
if ( V_34 < V_2 )
V_34 = V_2 ;
F_18 ( V_2 ) ;
return 0 ;
}
void F_21 ( void )
{
V_35 = 1 ;
F_22 ( V_36 ) ;
}
static void F_23 ( struct V_37 * V_38 )
{
F_21 () ;
}
static int F_24 ( struct V_23 * V_39 , struct V_37 * V_38 )
{
struct V_1 * V_3 ;
int V_40 ;
if ( ! ( V_3 = F_1 ( V_38 -> V_2 ) ) )
return - V_26 ;
V_38 -> V_41 = V_3 ;
V_40 = F_25 ( & V_3 -> V_7 , V_39 , V_38 ) ;
if ( V_40 )
F_20 ( & V_3 -> V_7 ) ;
return V_40 ;
}
static int F_26 ( struct V_37 * V_38 , struct V_42 * V_43 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
unsigned long V_4 ;
int V_40 = 0 ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( V_3 -> V_7 . V_11 ++ > 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_21 () ;
return 0 ;
}
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_27 ( & V_3 -> V_7 , V_38 ) ;
if ( V_3 -> V_33 -> V_44 )
V_40 = V_3 -> V_33 -> V_44 ( V_3 , V_3 -> V_45 ) ;
if ( V_40 ) {
F_27 ( & V_3 -> V_7 , NULL ) ;
V_38 -> V_41 = NULL ;
F_20 ( & V_3 -> V_7 ) ;
F_28 ( V_46 L_1 , V_40 ) ;
}
F_21 () ;
return V_40 ;
}
static void F_29 ( struct V_37 * V_38 , struct V_42 * V_43 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
if ( F_30 ( V_43 ) )
return;
if ( ! V_38 -> V_41 )
return;
V_3 = V_38 -> V_41 ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( -- V_3 -> V_7 . V_11 == 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_27 ( & V_3 -> V_7 , NULL ) ;
if ( V_3 -> V_33 -> V_47 )
V_3 -> V_33 -> V_47 ( V_3 , V_3 -> V_45 ) ;
F_31 ( & V_3 -> V_48 ) ;
F_32 ( V_38 , V_49 ) ;
} else {
if ( V_3 -> V_7 . V_11 < 0 )
F_28 ( V_46 L_2 ,
V_3 -> V_31 , V_3 -> V_7 . V_11 ) ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
}
}
static void F_33 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
F_20 ( & V_3 -> V_7 ) ;
}
static void F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
unsigned long V_4 ;
if ( ! V_3 )
return;
F_31 ( & V_3 -> V_48 ) ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( V_3 -> V_7 . V_11 <= 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
return;
}
V_3 -> V_7 . V_11 = 0 ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_27 ( & V_3 -> V_7 , NULL ) ;
V_3 -> V_50 = 0 ;
if ( V_3 -> V_33 -> V_51 )
V_3 -> V_33 -> V_51 ( V_3 , V_3 -> V_45 ) ;
}
static int F_35 ( struct V_1 * V_3 )
{
int V_16 ;
V_16 = V_3 -> V_33 -> F_9 ( V_3 -> V_31 , V_3 -> V_52 , V_3 -> V_50 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == 0 || V_16 == - V_22 ) {
V_3 -> V_53 = 1 ;
return 0 ;
}
V_3 -> V_50 = 0 ;
} else
V_3 -> V_50 -= V_16 ;
if ( V_3 -> V_50 > 0 )
memmove ( V_3 -> V_52 , V_3 -> V_52 + V_16 , V_3 -> V_50 ) ;
else
V_3 -> V_53 = 1 ;
return V_16 ;
}
static int F_36 ( struct V_37 * V_38 , const unsigned char * V_54 , int V_11 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
unsigned long V_4 ;
int V_55 , V_56 = 0 ;
if ( ! V_3 )
return - V_57 ;
if ( V_3 -> V_7 . V_11 <= 0 )
return - V_58 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_50 > 0 )
F_35 ( V_3 ) ;
while ( V_11 > 0 && ( V_55 = V_3 -> V_59 - V_3 -> V_50 ) > 0 ) {
if ( V_55 > V_11 )
V_55 = V_11 ;
memcpy ( V_3 -> V_52 + V_3 -> V_50 , V_54 , V_55 ) ;
V_11 -= V_55 ;
V_54 += V_55 ;
V_3 -> V_50 += V_55 ;
V_56 += V_55 ;
F_35 ( V_3 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_50 )
F_21 () ;
return V_56 ;
}
static void F_37 ( struct V_60 * V_61 )
{
struct V_1 * V_3 ;
unsigned long V_62 ;
struct V_37 * V_38 ;
struct V_63 V_64 ;
V_3 = F_15 ( V_61 , struct V_1 , V_48 ) ;
V_38 = F_38 ( & V_3 -> V_7 ) ;
if ( ! V_38 )
return;
F_4 ( & V_3 -> V_6 , V_62 ) ;
V_64 = V_3 -> V_64 ;
F_6 ( & V_3 -> V_6 , V_62 ) ;
F_39 ( V_38 , & V_64 ) ;
F_40 ( V_38 ) ;
}
static int F_41 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_59 - V_3 -> V_50 ;
}
static int F_42 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_50 ;
}
int F_43 ( struct V_1 * V_3 )
{
struct V_37 * V_38 ;
int V_15 , V_16 , V_65 = 0 ;
char V_54 [ V_66 ] V_14 ;
unsigned long V_4 ;
int V_67 = 0 ;
int V_68 = 0 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_50 > 0 )
V_68 = F_35 ( V_3 ) ;
if ( V_3 -> V_50 > 0 ) {
V_65 |= V_69 ;
V_70 = ( V_68 ) ? 0 : V_71 ;
}
V_38 = F_38 ( & V_3 -> V_7 ) ;
if ( V_38 == NULL )
goto V_72;
if ( F_44 ( V_73 , & V_38 -> V_4 ) )
goto V_74;
if ( ! V_3 -> V_75 )
V_65 |= V_76 ;
for (; ; ) {
int V_11 = F_45 ( V_38 , V_66 ) ;
if ( V_11 == 0 ) {
V_65 |= V_76 ;
break;
}
V_16 = V_3 -> V_33 -> V_77 ( V_3 -> V_31 , V_54 , V_11 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == - V_57 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_46 ( V_38 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
} else if ( V_16 == - V_22 ) {
V_65 |= V_76 ;
}
break;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
#ifdef F_47
if ( V_3 -> V_2 == V_27 . V_2 ) {
if ( V_54 [ V_15 ] == '\x0f' ) {
V_78 = ! V_78 ;
if ( V_78 )
continue;
} else if ( V_78 ) {
F_48 ( V_54 [ V_15 ] ) ;
V_78 = 0 ;
continue;
}
}
#endif
F_49 ( V_38 , V_54 [ V_15 ] , 0 ) ;
}
V_67 += V_16 ;
}
V_74:
if ( V_3 -> V_53 ) {
V_3 -> V_53 = 0 ;
F_50 ( V_38 ) ;
}
V_72:
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_67 ) {
V_70 = V_71 ;
F_51 ( V_38 ) ;
}
F_40 ( V_38 ) ;
return V_65 ;
}
void F_52 ( struct V_1 * V_3 , struct V_63 V_64 )
{
V_3 -> V_64 = V_64 ;
F_53 ( & V_3 -> V_48 ) ;
}
static int F_54 ( void * V_79 )
{
int V_65 ;
struct V_1 * V_3 ;
F_55 () ;
do {
V_65 = 0 ;
V_35 = 0 ;
F_56 () ;
F_57 () ;
if ( ! F_58 () ) {
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
V_65 |= F_43 ( V_3 ) ;
}
F_7 ( & V_5 ) ;
} else
V_65 |= V_76 ;
if ( V_35 )
continue;
F_59 ( V_80 ) ;
if ( ! V_35 ) {
if ( V_65 == 0 )
F_60 () ;
else {
if ( V_70 < V_81 )
V_70 += ( V_70 >> 6 ) + 1 ;
F_61 ( V_70 ) ;
}
}
F_62 ( V_82 ) ;
} while ( ! F_63 () );
return 0 ;
}
static int F_64 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_33 -> V_83 )
return - V_84 ;
return V_3 -> V_33 -> V_83 ( V_3 ) ;
}
static int F_65 ( struct V_37 * V_38 ,
unsigned int V_85 , unsigned int V_86 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_33 -> V_87 )
return - V_84 ;
return V_3 -> V_33 -> V_87 ( V_3 , V_85 , V_86 ) ;
}
int F_66 ( struct V_23 * V_39 , int line , char * V_25 )
{
return 0 ;
}
static int F_67 ( struct V_23 * V_39 , int line )
{
struct V_37 * V_38 = V_39 -> V_88 [ 0 ] ;
struct V_1 * V_3 = V_38 -> V_41 ;
int V_16 ;
char V_89 ;
V_16 = V_3 -> V_33 -> V_77 ( V_3 -> V_31 , & V_89 , 1 ) ;
if ( V_16 == 0 )
return V_90 ;
return V_89 ;
}
static void F_68 ( struct V_23 * V_39 , int line , char V_89 )
{
struct V_37 * V_38 = V_39 -> V_88 [ 0 ] ;
struct V_1 * V_3 = V_38 -> V_41 ;
int V_16 ;
do {
V_16 = V_3 -> V_33 -> F_9 ( V_3 -> V_31 , & V_89 , 1 ) ;
} while ( V_16 <= 0 );
}
struct V_1 * F_69 ( T_2 V_31 , int V_45 ,
const struct V_32 * V_33 ,
int V_59 )
{
struct V_1 * V_3 ;
int V_15 ;
if ( ! V_24 ) {
int V_91 = F_70 () ;
if ( V_91 )
return F_71 ( V_91 ) ;
}
V_3 = F_72 ( F_73 ( sizeof( * V_3 ) , sizeof( long ) ) + V_59 ,
V_92 ) ;
if ( ! V_3 )
return F_71 ( - V_93 ) ;
V_3 -> V_31 = V_31 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_33 = V_33 ;
V_3 -> V_59 = V_59 ;
V_3 -> V_52 = & ( ( char * ) V_3 ) [ F_73 ( sizeof( * V_3 ) , sizeof( long ) ) ] ;
F_74 ( & V_3 -> V_7 ) ;
V_3 -> V_7 . V_33 = & V_94 ;
F_75 ( & V_3 -> V_48 , F_37 ) ;
F_76 ( & V_3 -> V_6 ) ;
F_2 ( & V_5 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
if ( V_20 [ V_15 ] == V_3 -> V_31 &&
V_21 [ V_15 ] == V_3 -> V_33 )
break;
if ( V_15 >= V_19 )
V_15 = ++ V_34 ;
V_3 -> V_2 = V_15 ;
V_21 [ V_15 ] = V_33 ;
V_20 [ V_15 ] = V_31 ;
F_77 ( & ( V_3 -> V_29 ) , & V_95 ) ;
F_7 ( & V_5 ) ;
F_18 ( V_15 ) ;
return V_3 ;
}
int F_78 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
struct V_37 * V_38 ;
V_38 = F_38 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_2 < V_19 ) {
F_79 () ;
V_20 [ V_3 -> V_2 ] = - 1 ;
V_21 [ V_3 -> V_2 ] = NULL ;
F_80 () ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_20 ( & V_3 -> V_7 ) ;
if ( V_38 ) {
F_81 ( V_38 ) ;
F_40 ( V_38 ) ;
}
return 0 ;
}
static int F_70 ( void )
{
struct V_23 * V_96 ;
int V_91 ;
V_96 = F_82 ( V_97 ) ;
if ( ! V_96 ) {
V_91 = - V_93 ;
goto V_98;
}
V_96 -> V_99 = L_3 ;
V_96 -> V_100 = L_3 ;
V_96 -> V_101 = V_102 ;
V_96 -> V_103 = V_104 ;
V_96 -> type = V_105 ;
V_96 -> V_106 = V_107 ;
V_96 -> V_4 = V_108 | V_109 ;
F_83 ( V_96 , & V_110 ) ;
V_36 = F_84 ( F_54 , NULL , L_4 ) ;
if ( F_85 ( V_36 ) ) {
F_28 ( V_46 L_5 ) ;
V_91 = F_86 ( V_36 ) ;
goto V_111;
}
V_91 = F_87 ( V_96 ) ;
if ( V_91 ) {
F_28 ( V_46 L_6 ) ;
goto V_112;
}
F_88 () ;
V_24 = V_96 ;
return 0 ;
V_112:
F_89 ( V_36 ) ;
V_36 = NULL ;
V_111:
F_90 ( V_96 ) ;
V_98:
return V_91 ;
}
static void T_3 F_91 ( void )
{
if ( V_24 ) {
F_89 ( V_36 ) ;
F_92 ( V_24 ) ;
F_90 ( V_24 ) ;
F_93 ( & V_27 ) ;
}
}
