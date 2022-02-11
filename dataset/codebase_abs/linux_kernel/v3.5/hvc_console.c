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
int F_18 ( T_2 V_30 , int V_2 , const struct V_31 * V_32 )
{
struct V_1 * V_3 ;
if ( V_2 < 0 || V_2 >= V_19 )
return - 1 ;
if ( V_20 [ V_2 ] != - 1 )
return - 1 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_19 ( & V_3 -> V_7 ) ;
return - 1 ;
}
V_20 [ V_2 ] = V_30 ;
V_21 [ V_2 ] = V_32 ;
if ( V_33 < V_2 )
V_33 = V_2 ;
if ( V_2 == V_27 . V_2 )
F_13 ( & V_27 ) ;
return 0 ;
}
void F_20 ( void )
{
V_34 = 1 ;
F_21 ( V_35 ) ;
}
static void F_22 ( struct V_36 * V_37 )
{
F_20 () ;
}
static int F_23 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_40 = 0 ;
if ( ! ( V_3 = F_1 ( V_37 -> V_2 ) ) )
return - V_26 ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( V_3 -> V_7 . V_11 ++ > 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_20 () ;
return 0 ;
}
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
V_37 -> V_41 = V_3 ;
F_24 ( & V_3 -> V_7 , V_37 ) ;
if ( V_3 -> V_32 -> V_42 )
V_40 = V_3 -> V_32 -> V_42 ( V_3 , V_3 -> V_43 ) ;
if ( V_40 ) {
F_24 ( & V_3 -> V_7 , NULL ) ;
V_37 -> V_41 = NULL ;
F_19 ( & V_3 -> V_7 ) ;
F_25 ( V_44 L_1 , V_40 ) ;
}
F_20 () ;
return V_40 ;
}
static void F_26 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
if ( F_27 ( V_39 ) )
return;
if ( ! V_37 -> V_41 )
return;
V_3 = V_37 -> V_41 ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( -- V_3 -> V_7 . V_11 == 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_24 ( & V_3 -> V_7 , NULL ) ;
if ( V_3 -> V_32 -> V_45 )
V_3 -> V_32 -> V_45 ( V_3 , V_3 -> V_43 ) ;
F_28 ( & V_3 -> V_46 ) ;
F_29 ( V_37 , V_47 ) ;
} else {
if ( V_3 -> V_7 . V_11 < 0 )
F_25 ( V_44 L_2 ,
V_3 -> V_30 , V_3 -> V_7 . V_11 ) ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
}
F_19 ( & V_3 -> V_7 ) ;
}
static void F_30 ( struct V_36 * V_37 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
unsigned long V_4 ;
int V_48 ;
if ( ! V_3 )
return;
F_28 ( & V_3 -> V_46 ) ;
F_4 ( & V_3 -> V_7 . V_6 , V_4 ) ;
if ( V_3 -> V_7 . V_11 <= 0 ) {
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
return;
}
V_48 = V_3 -> V_7 . V_11 ;
V_3 -> V_7 . V_11 = 0 ;
F_6 ( & V_3 -> V_7 . V_6 , V_4 ) ;
F_24 ( & V_3 -> V_7 , NULL ) ;
V_3 -> V_49 = 0 ;
if ( V_3 -> V_32 -> V_50 )
V_3 -> V_32 -> V_50 ( V_3 , V_3 -> V_43 ) ;
while( V_48 ) {
-- V_48 ;
F_19 ( & V_3 -> V_7 ) ;
}
}
static int F_31 ( struct V_1 * V_3 )
{
int V_16 ;
V_16 = V_3 -> V_32 -> F_9 ( V_3 -> V_30 , V_3 -> V_51 , V_3 -> V_49 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == 0 || V_16 == - V_22 ) {
V_3 -> V_52 = 1 ;
return 0 ;
}
V_3 -> V_49 = 0 ;
} else
V_3 -> V_49 -= V_16 ;
if ( V_3 -> V_49 > 0 )
memmove ( V_3 -> V_51 , V_3 -> V_51 + V_16 , V_3 -> V_49 ) ;
else
V_3 -> V_52 = 1 ;
return V_16 ;
}
static int F_32 ( struct V_36 * V_37 , const unsigned char * V_53 , int V_11 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
unsigned long V_4 ;
int V_54 , V_55 = 0 ;
if ( ! V_3 )
return - V_56 ;
if ( V_3 -> V_7 . V_11 <= 0 )
return - V_57 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_49 > 0 )
F_31 ( V_3 ) ;
while ( V_11 > 0 && ( V_54 = V_3 -> V_58 - V_3 -> V_49 ) > 0 ) {
if ( V_54 > V_11 )
V_54 = V_11 ;
memcpy ( V_3 -> V_51 + V_3 -> V_49 , V_53 , V_54 ) ;
V_11 -= V_54 ;
V_53 += V_54 ;
V_3 -> V_49 += V_54 ;
V_55 += V_54 ;
F_31 ( V_3 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_49 )
F_20 () ;
return V_55 ;
}
static void F_33 ( struct V_59 * V_60 )
{
struct V_1 * V_3 ;
unsigned long V_61 ;
struct V_36 * V_37 ;
struct V_62 V_63 ;
V_3 = F_15 ( V_60 , struct V_1 , V_46 ) ;
V_37 = F_34 ( & V_3 -> V_7 ) ;
if ( ! V_37 )
return;
F_4 ( & V_3 -> V_6 , V_61 ) ;
V_63 = V_3 -> V_63 ;
F_6 ( & V_3 -> V_6 , V_61 ) ;
F_35 ( V_37 , & V_63 ) ;
F_36 ( V_37 ) ;
}
static int F_37 ( struct V_36 * V_37 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
if ( ! V_3 )
return - 1 ;
return V_3 -> V_58 - V_3 -> V_49 ;
}
static int F_38 ( struct V_36 * V_37 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_49 ;
}
int F_39 ( struct V_1 * V_3 )
{
struct V_36 * V_37 ;
int V_15 , V_16 , V_64 = 0 ;
char V_53 [ V_65 ] V_14 ;
unsigned long V_4 ;
int V_66 = 0 ;
int V_67 = 0 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_49 > 0 )
V_67 = F_31 ( V_3 ) ;
if ( V_3 -> V_49 > 0 ) {
V_64 |= V_68 ;
V_69 = ( V_67 ) ? 0 : V_70 ;
}
V_37 = F_34 ( & V_3 -> V_7 ) ;
if ( V_37 == NULL )
goto V_71;
if ( F_40 ( V_72 , & V_37 -> V_4 ) )
goto V_73;
if ( ! V_3 -> V_74 )
V_64 |= V_75 ;
for (; ; ) {
int V_11 = F_41 ( V_37 , V_65 ) ;
if ( V_11 == 0 ) {
V_64 |= V_75 ;
break;
}
V_16 = V_3 -> V_32 -> V_76 ( V_3 -> V_30 , V_53 , V_11 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == - V_56 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_42 ( V_37 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
} else if ( V_16 == - V_22 ) {
V_64 |= V_75 ;
}
break;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
#ifdef F_43
if ( V_3 -> V_2 == V_27 . V_2 ) {
if ( V_53 [ V_15 ] == '\x0f' ) {
V_77 = ! V_77 ;
if ( V_77 )
continue;
} else if ( V_77 ) {
F_44 ( V_53 [ V_15 ] ) ;
V_77 = 0 ;
continue;
}
}
#endif
F_45 ( V_37 , V_53 [ V_15 ] , 0 ) ;
}
V_66 += V_16 ;
}
V_73:
if ( V_3 -> V_52 ) {
V_3 -> V_52 = 0 ;
F_46 ( V_37 ) ;
}
V_71:
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_66 ) {
V_69 = V_70 ;
F_47 ( V_37 ) ;
}
F_36 ( V_37 ) ;
return V_64 ;
}
void F_48 ( struct V_1 * V_3 , struct V_62 V_63 )
{
V_3 -> V_63 = V_63 ;
F_49 ( & V_3 -> V_46 ) ;
}
static int F_50 ( void * V_78 )
{
int V_64 ;
struct V_1 * V_3 ;
F_51 () ;
do {
V_64 = 0 ;
V_34 = 0 ;
F_52 () ;
F_53 () ;
if ( ! F_54 () ) {
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
V_64 |= F_39 ( V_3 ) ;
}
F_7 ( & V_5 ) ;
} else
V_64 |= V_75 ;
if ( V_34 )
continue;
F_55 ( V_79 ) ;
if ( ! V_34 ) {
if ( V_64 == 0 )
F_56 () ;
else {
if ( V_69 < V_80 )
V_69 += ( V_69 >> 6 ) + 1 ;
F_57 ( V_69 ) ;
}
}
F_58 ( V_81 ) ;
} while ( ! F_59 () );
return 0 ;
}
static int F_60 ( struct V_36 * V_37 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_32 -> V_82 )
return - V_83 ;
return V_3 -> V_32 -> V_82 ( V_3 ) ;
}
static int F_61 ( struct V_36 * V_37 ,
unsigned int V_84 , unsigned int V_85 )
{
struct V_1 * V_3 = V_37 -> V_41 ;
if ( ! V_3 || ! V_3 -> V_32 -> V_86 )
return - V_83 ;
return V_3 -> V_32 -> V_86 ( V_3 , V_84 , V_85 ) ;
}
int F_62 ( struct V_23 * V_87 , int line , char * V_25 )
{
return 0 ;
}
static int F_63 ( struct V_23 * V_87 , int line )
{
struct V_36 * V_37 = V_87 -> V_88 [ 0 ] ;
struct V_1 * V_3 = V_37 -> V_41 ;
int V_16 ;
char V_89 ;
V_16 = V_3 -> V_32 -> V_76 ( V_3 -> V_30 , & V_89 , 1 ) ;
if ( V_16 == 0 )
return V_90 ;
return V_89 ;
}
static void F_64 ( struct V_23 * V_87 , int line , char V_89 )
{
struct V_36 * V_37 = V_87 -> V_88 [ 0 ] ;
struct V_1 * V_3 = V_37 -> V_41 ;
int V_16 ;
do {
V_16 = V_3 -> V_32 -> F_9 ( V_3 -> V_30 , & V_89 , 1 ) ;
} while ( V_16 <= 0 );
}
struct V_1 * F_65 ( T_2 V_30 , int V_43 ,
const struct V_31 * V_32 ,
int V_58 )
{
struct V_1 * V_3 ;
int V_15 ;
if ( ! V_24 ) {
int V_91 = F_66 () ;
if ( V_91 )
return F_67 ( V_91 ) ;
}
V_3 = F_68 ( F_69 ( sizeof( * V_3 ) , sizeof( long ) ) + V_58 ,
V_92 ) ;
if ( ! V_3 )
return F_67 ( - V_93 ) ;
V_3 -> V_30 = V_30 ;
V_3 -> V_43 = V_43 ;
V_3 -> V_32 = V_32 ;
V_3 -> V_58 = V_58 ;
V_3 -> V_51 = & ( ( char * ) V_3 ) [ F_69 ( sizeof( * V_3 ) , sizeof( long ) ) ] ;
F_70 ( & V_3 -> V_7 ) ;
V_3 -> V_7 . V_32 = & V_94 ;
F_71 ( & V_3 -> V_46 , F_33 ) ;
F_72 ( & V_3 -> V_6 ) ;
F_2 ( & V_5 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
if ( V_20 [ V_15 ] == V_3 -> V_30 &&
V_21 [ V_15 ] == V_3 -> V_32 )
break;
if ( V_15 >= V_19 )
V_15 = ++ V_33 ;
V_3 -> V_2 = V_15 ;
F_73 ( & ( V_3 -> V_29 ) , & V_95 ) ;
F_7 ( & V_5 ) ;
return V_3 ;
}
int F_74 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
struct V_36 * V_37 ;
V_37 = F_34 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_2 < V_19 )
V_20 [ V_3 -> V_2 ] = - 1 ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_19 ( & V_3 -> V_7 ) ;
if ( V_37 ) {
F_75 ( V_37 ) ;
F_36 ( V_37 ) ;
}
return 0 ;
}
static int F_66 ( void )
{
struct V_23 * V_96 ;
int V_91 ;
V_96 = F_76 ( V_97 ) ;
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
F_77 ( V_96 , & V_110 ) ;
V_35 = F_78 ( F_50 , NULL , L_4 ) ;
if ( F_79 ( V_35 ) ) {
F_25 ( V_44 L_5 ) ;
V_91 = F_80 ( V_35 ) ;
goto V_111;
}
V_91 = F_81 ( V_96 ) ;
if ( V_91 ) {
F_25 ( V_44 L_6 ) ;
goto V_112;
}
F_82 () ;
V_24 = V_96 ;
return 0 ;
V_112:
F_83 ( V_35 ) ;
V_35 = NULL ;
V_111:
F_84 ( V_96 ) ;
V_98:
return V_91 ;
}
static void T_3 F_85 ( void )
{
if ( V_24 ) {
F_83 ( V_35 ) ;
F_86 ( V_24 ) ;
F_84 ( V_24 ) ;
F_87 ( & V_27 ) ;
}
}
