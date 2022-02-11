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
static int F_11 ( struct V_8 * V_9 , char * V_25 )
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
} else
if ( F_29 ( V_38 ) )
if ( V_3 -> V_33 -> V_47 )
V_3 -> V_33 -> V_47 ( V_3 , 1 ) ;
F_21 () ;
return V_40 ;
}
static void F_30 ( struct V_37 * V_38 , struct V_42 * V_43 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
if ( F_31 ( V_43 ) )
return;
if ( ! V_38 -> V_41 )
return;
V_3 = V_38 -> V_41 ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( -- V_3 -> V_7 . V_11 == 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_27 ( & V_3 -> V_7 , NULL ) ;
if ( F_32 ( V_38 ) )
if ( V_3 -> V_33 -> V_47 )
V_3 -> V_33 -> V_47 ( V_3 , 0 ) ;
if ( V_3 -> V_33 -> V_48 )
V_3 -> V_33 -> V_48 ( V_3 , V_3 -> V_45 ) ;
F_33 ( & V_3 -> V_49 ) ;
F_34 ( V_38 , V_50 ) ;
} else {
if ( V_3 -> V_7 . V_11 < 0 )
F_28 ( V_46 L_2 ,
V_3 -> V_31 , V_3 -> V_7 . V_11 ) ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
}
}
static void F_35 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
F_20 ( & V_3 -> V_7 ) ;
}
static void F_36 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
unsigned long V_4 ;
if ( ! V_3 )
return;
F_33 ( & V_3 -> V_49 ) ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( V_3 -> V_7 . V_11 <= 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
return;
}
V_3 -> V_7 . V_11 = 0 ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_27 ( & V_3 -> V_7 , NULL ) ;
V_3 -> V_51 = 0 ;
if ( V_3 -> V_33 -> V_52 )
V_3 -> V_33 -> V_52 ( V_3 , V_3 -> V_45 ) ;
}
static int F_37 ( struct V_1 * V_3 )
{
int V_16 ;
V_16 = V_3 -> V_33 -> F_9 ( V_3 -> V_31 , V_3 -> V_53 , V_3 -> V_51 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == 0 || V_16 == - V_22 ) {
V_3 -> V_54 = 1 ;
return 0 ;
}
V_3 -> V_51 = 0 ;
} else
V_3 -> V_51 -= V_16 ;
if ( V_3 -> V_51 > 0 )
memmove ( V_3 -> V_53 , V_3 -> V_53 + V_16 , V_3 -> V_51 ) ;
else
V_3 -> V_54 = 1 ;
return V_16 ;
}
static int F_38 ( struct V_37 * V_38 , const unsigned char * V_55 , int V_11 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
unsigned long V_4 ;
int V_56 , V_57 = 0 ;
if ( ! V_3 )
return - V_58 ;
if ( V_3 -> V_7 . V_11 <= 0 )
return - V_59 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_51 > 0 )
F_37 ( V_3 ) ;
while ( V_11 > 0 && ( V_56 = V_3 -> V_60 - V_3 -> V_51 ) > 0 ) {
if ( V_56 > V_11 )
V_56 = V_11 ;
memcpy ( V_3 -> V_53 + V_3 -> V_51 , V_55 , V_56 ) ;
V_11 -= V_56 ;
V_55 += V_56 ;
V_3 -> V_51 += V_56 ;
V_57 += V_56 ;
F_37 ( V_3 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_51 )
F_21 () ;
return V_57 ;
}
static void F_39 ( struct V_61 * V_62 )
{
struct V_1 * V_3 ;
unsigned long V_63 ;
struct V_37 * V_38 ;
struct V_64 V_65 ;
V_3 = F_15 ( V_62 , struct V_1 , V_49 ) ;
V_38 = F_40 ( & V_3 -> V_7 ) ;
if ( ! V_38 )
return;
F_4 ( & V_3 -> V_6 , V_63 ) ;
V_65 = V_3 -> V_65 ;
F_6 ( & V_3 -> V_6 , V_63 ) ;
F_41 ( V_38 , & V_65 ) ;
F_42 ( V_38 ) ;
}
static int F_43 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_60 - V_3 -> V_51 ;
}
static int F_44 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_51 ;
}
int F_45 ( struct V_1 * V_3 )
{
struct V_37 * V_38 ;
int V_15 , V_16 , V_66 = 0 ;
char V_55 [ V_67 ] V_14 ;
unsigned long V_4 ;
int V_68 = 0 ;
int V_69 = 0 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_51 > 0 )
V_69 = F_37 ( V_3 ) ;
if ( V_3 -> V_51 > 0 ) {
V_66 |= V_70 ;
V_71 = ( V_69 ) ? 0 : V_72 ;
}
V_38 = F_40 ( & V_3 -> V_7 ) ;
if ( V_38 == NULL )
goto V_73;
if ( F_46 ( V_74 , & V_38 -> V_4 ) )
goto V_75;
if ( ! V_3 -> V_76 )
V_66 |= V_77 ;
for (; ; ) {
int V_11 = F_47 ( & V_3 -> V_7 , V_67 ) ;
if ( V_11 == 0 ) {
V_66 |= V_77 ;
break;
}
V_16 = V_3 -> V_33 -> V_78 ( V_3 -> V_31 , V_55 , V_11 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == - V_58 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_48 ( V_38 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
} else if ( V_16 == - V_22 ) {
V_66 |= V_77 ;
}
break;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
#ifdef F_49
if ( V_3 -> V_2 == V_27 . V_2 ) {
if ( V_55 [ V_15 ] == '\x0f' ) {
V_79 = ! V_79 ;
if ( V_79 )
continue;
} else if ( V_79 ) {
F_50 ( V_55 [ V_15 ] ) ;
V_79 = 0 ;
continue;
}
}
#endif
F_51 ( & V_3 -> V_7 , V_55 [ V_15 ] , 0 ) ;
}
V_68 += V_16 ;
}
V_75:
if ( V_3 -> V_54 ) {
V_3 -> V_54 = 0 ;
F_52 ( V_38 ) ;
}
V_73:
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_68 ) {
V_71 = V_72 ;
F_53 ( & V_3 -> V_7 ) ;
}
F_42 ( V_38 ) ;
return V_66 ;
}
void F_54 ( struct V_1 * V_3 , struct V_64 V_65 )
{
V_3 -> V_65 = V_65 ;
F_55 ( & V_3 -> V_49 ) ;
}
static int F_56 ( void * V_80 )
{
int V_66 ;
struct V_1 * V_3 ;
F_57 () ;
do {
V_66 = 0 ;
V_35 = 0 ;
F_58 () ;
F_59 () ;
if ( ! F_60 () ) {
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
V_66 |= F_45 ( V_3 ) ;
}
F_7 ( & V_5 ) ;
} else
V_66 |= V_77 ;
if ( V_35 )
continue;
F_61 ( V_81 ) ;
if ( ! V_35 ) {
if ( V_66 == 0 )
F_62 () ;
else {
unsigned long V_82 ;
if ( V_71 < V_83 )
V_71 += ( V_71 >> 6 ) + 1 ;
V_82 = F_63 ( V_71 ) + 1 ;
F_64 ( V_82 ) ;
}
}
F_65 ( V_84 ) ;
} while ( ! F_66 () );
return 0 ;
}
static int F_67 ( struct V_37 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_33 -> V_85 )
return - V_86 ;
return V_3 -> V_33 -> V_85 ( V_3 ) ;
}
static int F_68 ( struct V_37 * V_38 ,
unsigned int V_87 , unsigned int V_88 )
{
struct V_1 * V_3 = V_38 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_33 -> V_89 )
return - V_86 ;
return V_3 -> V_33 -> V_89 ( V_3 , V_87 , V_88 ) ;
}
static int F_69 ( struct V_23 * V_39 , int line , char * V_25 )
{
return 0 ;
}
static int F_70 ( struct V_23 * V_39 , int line )
{
struct V_37 * V_38 = V_39 -> V_90 [ 0 ] ;
struct V_1 * V_3 = V_38 -> V_41 ;
int V_16 ;
char V_91 ;
V_16 = V_3 -> V_33 -> V_78 ( V_3 -> V_31 , & V_91 , 1 ) ;
if ( V_16 == 0 )
return V_92 ;
return V_91 ;
}
static void F_71 ( struct V_23 * V_39 , int line , char V_91 )
{
struct V_37 * V_38 = V_39 -> V_90 [ 0 ] ;
struct V_1 * V_3 = V_38 -> V_41 ;
int V_16 ;
do {
V_16 = V_3 -> V_33 -> F_9 ( V_3 -> V_31 , & V_91 , 1 ) ;
} while ( V_16 <= 0 );
}
struct V_1 * F_72 ( T_2 V_31 , int V_45 ,
const struct V_32 * V_33 ,
int V_60 )
{
struct V_1 * V_3 ;
int V_15 ;
if ( F_73 ( & V_93 ) ) {
int V_94 = F_74 () ;
if ( V_94 )
return F_75 ( V_94 ) ;
}
V_3 = F_76 ( F_77 ( sizeof( * V_3 ) , sizeof( long ) ) + V_60 ,
V_95 ) ;
if ( ! V_3 )
return F_75 ( - V_96 ) ;
V_3 -> V_31 = V_31 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_33 = V_33 ;
V_3 -> V_60 = V_60 ;
V_3 -> V_53 = & ( ( char * ) V_3 ) [ F_77 ( sizeof( * V_3 ) , sizeof( long ) ) ] ;
F_78 ( & V_3 -> V_7 ) ;
V_3 -> V_7 . V_33 = & V_97 ;
F_79 ( & V_3 -> V_49 , F_39 ) ;
F_80 ( & V_3 -> V_6 ) ;
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
F_81 ( & ( V_3 -> V_29 ) , & V_98 ) ;
F_7 ( & V_5 ) ;
F_18 ( V_15 ) ;
return V_3 ;
}
int F_82 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
struct V_37 * V_38 ;
V_38 = F_40 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_2 < V_19 ) {
F_83 () ;
V_20 [ V_3 -> V_2 ] = - 1 ;
V_21 [ V_3 -> V_2 ] = NULL ;
F_84 () ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_20 ( & V_3 -> V_7 ) ;
if ( V_38 ) {
F_85 ( V_38 ) ;
F_42 ( V_38 ) ;
}
return 0 ;
}
static int F_74 ( void )
{
struct V_23 * V_99 ;
int V_94 ;
V_99 = F_86 ( V_100 ) ;
if ( ! V_99 ) {
V_94 = - V_96 ;
goto V_101;
}
V_99 -> V_102 = L_3 ;
V_99 -> V_103 = L_3 ;
V_99 -> V_104 = V_105 ;
V_99 -> V_106 = V_107 ;
V_99 -> type = V_108 ;
V_99 -> V_109 = V_110 ;
V_99 -> V_4 = V_111 | V_112 ;
F_87 ( V_99 , & V_113 ) ;
V_36 = F_88 ( F_56 , NULL , L_4 ) ;
if ( F_89 ( V_36 ) ) {
F_28 ( V_46 L_5 ) ;
V_94 = F_90 ( V_36 ) ;
goto V_114;
}
V_94 = F_91 ( V_99 ) ;
if ( V_94 ) {
F_28 ( V_46 L_6 ) ;
goto V_115;
}
F_92 () ;
V_24 = V_99 ;
return 0 ;
V_115:
F_93 ( V_36 ) ;
V_36 = NULL ;
V_114:
F_94 ( V_99 ) ;
V_101:
return V_94 ;
}
static void T_3 F_95 ( void )
{
if ( V_24 ) {
F_93 ( V_36 ) ;
F_96 ( V_24 ) ;
F_94 ( V_24 ) ;
F_97 ( & V_27 ) ;
}
}
