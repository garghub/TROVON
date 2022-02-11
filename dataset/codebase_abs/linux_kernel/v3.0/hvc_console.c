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
V_15 = 0 ;
} else if ( V_17 > 0 ) {
V_15 -= V_17 ;
if ( V_15 > 0 )
memmove ( V_12 , V_12 + V_17 , V_15 ) ;
}
}
}
}
static struct V_22 * F_10 ( struct V_8 * V_12 , int * V_2 )
{
if ( V_20 [ V_12 -> V_2 ] == - 1 )
return NULL ;
* V_2 = V_12 -> V_2 ;
return V_23 ;
}
static int T_1 F_11 ( struct V_8 * V_9 , char * V_24 )
{
if ( V_9 -> V_2 < 0 || V_9 -> V_2 >= V_19 )
return - V_25 ;
if ( V_20 [ V_9 -> V_2 ] == - 1 )
return - V_25 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
F_13 ( & V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_7 )
{
struct V_1 * V_3 = F_15 ( V_7 , struct V_1 , V_7 ) ;
unsigned long V_4 ;
F_2 ( & V_5 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
F_16 ( & ( V_3 -> V_27 ) ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_7 ( & V_5 ) ;
F_17 ( V_3 ) ;
}
int F_18 ( T_2 V_28 , int V_2 , const struct V_29 * V_30 )
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
V_20 [ V_2 ] = V_28 ;
V_21 [ V_2 ] = V_30 ;
if ( V_31 < V_2 )
V_31 = V_2 ;
if ( V_2 == V_26 . V_2 )
F_13 ( & V_26 ) ;
return 0 ;
}
void F_20 ( void )
{
V_32 = 1 ;
F_21 ( V_33 ) ;
}
static void F_22 ( struct V_34 * V_35 )
{
F_20 () ;
}
static int F_23 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_38 = 0 ;
if ( ! ( V_3 = F_1 ( V_35 -> V_2 ) ) )
return - V_25 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_11 ++ > 0 ) {
F_24 ( V_35 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_20 () ;
return 0 ;
}
V_35 -> V_39 = V_3 ;
V_3 -> V_35 = F_24 ( V_35 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_30 -> V_40 )
V_38 = V_3 -> V_30 -> V_40 ( V_3 , V_3 -> V_41 ) ;
if ( V_38 ) {
F_4 ( & V_3 -> V_6 , V_4 ) ;
V_3 -> V_35 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_25 ( V_35 ) ;
V_35 -> V_39 = NULL ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
F_26 ( V_42 L_1 , V_38 ) ;
}
F_20 () ;
return V_38 ;
}
static void F_27 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
if ( F_28 ( V_37 ) )
return;
if ( ! V_35 -> V_39 )
return;
V_3 = V_35 -> V_39 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( -- V_3 -> V_11 == 0 ) {
V_3 -> V_35 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_30 -> V_43 )
V_3 -> V_30 -> V_43 ( V_3 , V_3 -> V_41 ) ;
F_29 ( & V_3 -> V_44 ) ;
F_30 ( V_35 , V_45 ) ;
} else {
if ( V_3 -> V_11 < 0 )
F_26 ( V_42 L_2 ,
V_3 -> V_28 , V_3 -> V_11 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
F_25 ( V_35 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_1 * V_3 = V_35 -> V_39 ;
unsigned long V_4 ;
int V_46 ;
if ( ! V_3 )
return;
F_29 ( & V_3 -> V_44 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_11 <= 0 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
return;
}
V_46 = V_3 -> V_11 ;
V_3 -> V_11 = 0 ;
V_3 -> V_47 = 0 ;
V_3 -> V_35 = NULL ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_30 -> V_48 )
V_3 -> V_30 -> V_48 ( V_3 , V_3 -> V_41 ) ;
while( V_46 ) {
-- V_46 ;
F_25 ( V_35 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
}
}
static int F_32 ( struct V_1 * V_3 )
{
int V_16 ;
V_16 = V_3 -> V_30 -> F_9 ( V_3 -> V_28 , V_3 -> V_49 , V_3 -> V_47 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == 0 ) {
V_3 -> V_50 = 1 ;
return 0 ;
}
V_3 -> V_47 = 0 ;
} else
V_3 -> V_47 -= V_16 ;
if ( V_3 -> V_47 > 0 )
memmove ( V_3 -> V_49 , V_3 -> V_49 + V_16 , V_3 -> V_47 ) ;
else
V_3 -> V_50 = 1 ;
return V_16 ;
}
static int F_33 ( struct V_34 * V_35 , const unsigned char * V_51 , int V_11 )
{
struct V_1 * V_3 = V_35 -> V_39 ;
unsigned long V_4 ;
int V_52 , V_53 = 0 ;
if ( ! V_3 )
return - V_54 ;
if ( V_3 -> V_11 <= 0 )
return - V_55 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_47 > 0 )
F_32 ( V_3 ) ;
while ( V_11 > 0 && ( V_52 = V_3 -> V_56 - V_3 -> V_47 ) > 0 ) {
if ( V_52 > V_11 )
V_52 = V_11 ;
memcpy ( V_3 -> V_49 + V_3 -> V_47 , V_51 , V_52 ) ;
V_11 -= V_52 ;
V_51 += V_52 ;
V_3 -> V_47 += V_52 ;
V_53 += V_52 ;
F_32 ( V_3 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_47 )
F_20 () ;
return V_53 ;
}
static void F_34 ( struct V_57 * V_58 )
{
struct V_1 * V_3 ;
unsigned long V_59 ;
struct V_34 * V_35 ;
struct V_60 V_61 ;
V_3 = F_15 ( V_58 , struct V_1 , V_44 ) ;
F_4 ( & V_3 -> V_6 , V_59 ) ;
if ( ! V_3 -> V_35 ) {
F_6 ( & V_3 -> V_6 , V_59 ) ;
return;
}
V_61 = V_3 -> V_61 ;
V_35 = F_24 ( V_3 -> V_35 ) ;
F_6 ( & V_3 -> V_6 , V_59 ) ;
F_35 ( V_35 , & V_61 ) ;
F_25 ( V_35 ) ;
}
static int F_36 ( struct V_34 * V_35 )
{
struct V_1 * V_3 = V_35 -> V_39 ;
if ( ! V_3 )
return - 1 ;
return V_3 -> V_56 - V_3 -> V_47 ;
}
static int F_37 ( struct V_34 * V_35 )
{
struct V_1 * V_3 = V_35 -> V_39 ;
if ( ! V_3 )
return 0 ;
return V_3 -> V_47 ;
}
int F_38 ( struct V_1 * V_3 )
{
struct V_34 * V_35 ;
int V_15 , V_16 , V_62 = 0 ;
char V_51 [ V_63 ] V_14 ;
unsigned long V_4 ;
int V_64 = 0 ;
int V_65 = 0 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_47 > 0 )
V_65 = F_32 ( V_3 ) ;
if ( V_3 -> V_47 > 0 ) {
V_62 |= V_66 ;
V_67 = ( V_65 ) ? 0 : V_68 ;
}
V_35 = F_24 ( V_3 -> V_35 ) ;
if ( V_35 == NULL )
goto V_69;
if ( F_39 ( V_70 , & V_35 -> V_4 ) )
goto V_71;
if ( ! V_3 -> V_72 )
V_62 |= V_73 ;
for (; ; ) {
int V_11 = F_40 ( V_35 , V_63 ) ;
if ( V_11 == 0 ) {
V_62 |= V_73 ;
break;
}
V_16 = V_3 -> V_30 -> V_74 ( V_3 -> V_28 , V_51 , V_11 ) ;
if ( V_16 <= 0 ) {
if ( V_16 == - V_54 ) {
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_41 ( V_35 ) ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
} else if ( V_16 == - V_75 ) {
V_62 |= V_73 ;
}
break;
}
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
#ifdef F_42
if ( V_3 -> V_2 == V_26 . V_2 ) {
if ( V_51 [ V_15 ] == '\x0f' ) {
V_76 = ! V_76 ;
if ( V_76 )
continue;
} else if ( V_76 ) {
F_43 ( V_51 [ V_15 ] ) ;
V_76 = 0 ;
continue;
}
}
#endif
F_44 ( V_35 , V_51 [ V_15 ] , 0 ) ;
}
V_64 += V_16 ;
}
V_71:
if ( V_3 -> V_50 ) {
V_3 -> V_50 = 0 ;
F_45 ( V_35 ) ;
}
V_69:
F_6 ( & V_3 -> V_6 , V_4 ) ;
if ( V_64 ) {
V_67 = V_68 ;
F_46 ( V_35 ) ;
}
if ( V_35 )
F_25 ( V_35 ) ;
return V_62 ;
}
void F_47 ( struct V_1 * V_3 , struct V_60 V_61 )
{
V_3 -> V_61 = V_61 ;
F_48 ( & V_3 -> V_44 ) ;
}
static int F_49 ( void * V_77 )
{
int V_62 ;
struct V_1 * V_3 ;
F_50 () ;
do {
V_62 = 0 ;
V_32 = 0 ;
F_51 () ;
F_52 () ;
if ( ! F_53 () ) {
F_2 ( & V_5 ) ;
F_3 (hp, &hvc_structs, next) {
V_62 |= F_38 ( V_3 ) ;
}
F_7 ( & V_5 ) ;
} else
V_62 |= V_73 ;
if ( V_32 )
continue;
F_54 ( V_78 ) ;
if ( ! V_32 ) {
if ( V_62 == 0 )
F_55 () ;
else {
if ( V_67 < V_79 )
V_67 += ( V_67 >> 6 ) + 1 ;
F_56 ( V_67 ) ;
}
}
F_57 ( V_80 ) ;
} while ( ! F_58 () );
return 0 ;
}
struct V_1 * F_59 ( T_2 V_28 , int V_41 ,
const struct V_29 * V_30 ,
int V_56 )
{
struct V_1 * V_3 ;
int V_15 ;
if ( ! V_23 ) {
int V_81 = F_60 () ;
if ( V_81 )
return F_61 ( V_81 ) ;
}
V_3 = F_62 ( F_63 ( sizeof( * V_3 ) , sizeof( long ) ) + V_56 ,
V_82 ) ;
if ( ! V_3 )
return F_61 ( - V_83 ) ;
V_3 -> V_28 = V_28 ;
V_3 -> V_41 = V_41 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_56 = V_56 ;
V_3 -> V_49 = & ( ( char * ) V_3 ) [ F_63 ( sizeof( * V_3 ) , sizeof( long ) ) ] ;
F_64 ( & V_3 -> V_7 ) ;
F_65 ( & V_3 -> V_44 , F_34 ) ;
F_66 ( & V_3 -> V_6 ) ;
F_2 ( & V_5 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ )
if ( V_20 [ V_15 ] == V_3 -> V_28 &&
V_21 [ V_15 ] == V_3 -> V_30 )
break;
if ( V_15 >= V_19 )
V_15 = ++ V_31 ;
V_3 -> V_2 = V_15 ;
F_67 ( & ( V_3 -> V_27 ) , & V_84 ) ;
F_7 ( & V_5 ) ;
return V_3 ;
}
int F_68 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
struct V_34 * V_35 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
V_35 = F_24 ( V_3 -> V_35 ) ;
if ( V_3 -> V_2 < V_19 )
V_20 [ V_3 -> V_2 ] = - 1 ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
F_19 ( & V_3 -> V_7 , F_14 ) ;
if ( V_35 ) {
F_69 ( V_35 ) ;
F_25 ( V_35 ) ;
}
return 0 ;
}
static int F_60 ( void )
{
struct V_22 * V_85 ;
int V_81 ;
V_85 = F_70 ( V_86 ) ;
if ( ! V_85 ) {
V_81 = - V_83 ;
goto V_87;
}
V_85 -> V_88 = V_89 ;
V_85 -> V_90 = L_3 ;
V_85 -> V_91 = L_3 ;
V_85 -> V_92 = V_93 ;
V_85 -> V_94 = V_95 ;
V_85 -> type = V_96 ;
V_85 -> V_97 = V_98 ;
V_85 -> V_4 = V_99 | V_100 ;
F_71 ( V_85 , & V_101 ) ;
V_33 = F_72 ( F_49 , NULL , L_4 ) ;
if ( F_73 ( V_33 ) ) {
F_26 ( V_42 L_5 ) ;
V_81 = F_74 ( V_33 ) ;
goto V_102;
}
V_81 = F_75 ( V_85 ) ;
if ( V_81 ) {
F_26 ( V_42 L_6 ) ;
goto V_103;
}
F_76 () ;
V_23 = V_85 ;
return 0 ;
V_103:
F_77 ( V_33 ) ;
V_33 = NULL ;
V_102:
F_78 ( V_85 ) ;
V_87:
return V_81 ;
}
static void T_3 F_79 ( void )
{
if ( V_23 ) {
F_77 ( V_33 ) ;
F_80 ( V_23 ) ;
F_78 ( V_23 ) ;
F_81 ( & V_26 ) ;
}
}
