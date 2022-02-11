static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
return V_3 * 2 ;
return V_3 ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_11 = 1 ;
if ( F_3 ( V_6 + V_7 ) & F_4 ( V_5 -> V_8 ) )
V_11 = 2 ;
if ( F_6 ( V_2 ) & V_12 ) {
unsigned long V_13 = V_9 / V_11 ;
* V_10 = F_7 ( F_8 ( V_2 ) , V_13 ) ;
}
return * V_10 * V_11 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
return 0 ;
}
static struct V_14 * F_10 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 ,
unsigned long V_19 , T_1 V_8 )
{
struct V_4 * V_5 ;
struct V_20 V_21 ;
struct V_14 * V_14 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_12 ( - V_23 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_25 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_14 = F_13 ( V_16 , & V_5 -> V_2 ) ;
if ( F_14 ( V_14 ) )
F_15 ( V_5 ) ;
return V_14 ;
}
static void F_16 ( const char * V_28 , const char * V_29 )
{
unsigned long V_30 = F_3 ( V_6 + V_31 ) ;
unsigned long V_32 = V_30 & 0x3f ;
unsigned long V_33 = ( V_30 >> 6 ) & 0x1ff ;
unsigned long V_34 = F_4 ( ( ( V_30 >> 16 ) & 3 ) + 1 ) ;
const char * V_35 = V_30 & F_4 ( 22 ) ? V_28 : V_29 ;
unsigned long V_36 = ( V_30 >> 24 ) & 0xf ;
F_17 ( NULL , L_1 , V_35 , 0 , V_33 , V_32 ) ;
F_17 ( NULL , L_2 , L_1 , 0 , 1 , V_34 ) ;
F_17 ( NULL , L_3 , L_1 , 0 , 1 , V_36 ) ;
}
static int F_18 ( T_1 V_37 , T_1 V_38 )
{
T_2 V_39 [ V_40 ] ;
if ( V_37 == 1 ) {
if ( F_19 ( V_38 >= V_41 ) )
return - V_42 ;
return V_38 ;
}
memcpy ( V_39 , V_43 , sizeof( V_39 ) ) ;
if ( F_19 ( V_38 >= V_44 * sizeof( V_39 ) ||
0 == ( V_39 [ F_20 ( V_38 ) ] &
F_21 ( V_38 ) ) ) )
return - V_42 ;
V_39 [ F_20 ( V_38 ) ] &=
F_22 ( V_38 % V_45 , 0 ) ;
return V_41 - 1 + F_23 ( V_39 [ 0 ] ) +
( F_20 ( V_38 ) >= 1 ? F_23 ( V_39 [ 1 ] ) : 0 ) +
( F_20 ( V_38 ) >= 2 ? F_23 ( V_39 [ 2 ] ) : 0 ) ;
}
static struct V_1 *
F_24 ( struct V_46 * V_47 , void * V_48 )
{
int V_49 = F_18 ( V_47 -> args [ 0 ] , V_47 -> args [ 1 ] ) ;
if ( V_49 < 0 )
return F_12 ( - V_42 ) ;
return V_50 [ V_49 ] ;
}
static inline void F_25 ( void )
{
if ( V_51 )
F_26 ( V_51 , 0x00 , ( 1 << 8 ) , ( 1 << 8 ) ) ;
}
static inline void F_27 ( void )
{
if ( V_51 )
F_26 ( V_51 , 0x00 , ( 1 << 8 ) , ( 0 << 8 ) ) ;
}
static inline void F_28 ( void )
{
unsigned long V_52 ;
V_52 = F_3 ( V_6 + V_53 ) ;
F_29 ( V_52 | F_4 ( 16 ) , V_6 + V_53 ) ;
F_29 ( V_52 & ~ F_4 ( 16 ) , V_6 + V_53 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_31 ( V_2 ) ;
struct V_56 * V_57 = F_32 ( V_55 ) ;
T_3 V_58 ;
int V_59 ;
F_25 () ;
V_60 . V_61 ( V_2 ) ;
V_59 = F_33 ( V_55 -> V_58 , V_58 ,
V_58 & V_57 -> V_62 , 1000 , V_63 ) ;
F_27 () ;
return V_59 ;
}
static void F_34 ( struct V_1 * V_2 )
{
V_60 . V_64 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
return V_60 . V_65 ( V_2 ) ;
}
static struct V_1 * F_36 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_4 * V_58 , T_1 V_8 , T_1 V_62 ,
T_1 V_66 , T_5 * V_67 )
{
struct V_56 * V_57 ;
struct V_20 V_21 = { NULL } ;
struct V_1 * V_2 ;
int V_59 ;
V_57 = F_11 ( sizeof( * V_57 ) , V_22 ) ;
if ( ! V_57 )
return F_12 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_68 ;
V_21 . V_19 = V_19 ;
V_21 . V_26 = & V_18 ;
V_21 . V_27 = 1 ;
V_57 -> V_62 = V_62 ;
V_57 -> V_55 . V_67 = V_67 ;
V_57 -> V_55 . V_58 = V_58 ;
V_57 -> V_55 . V_8 = V_8 ;
V_57 -> V_55 . V_2 . V_21 = & V_21 ;
V_2 = & V_57 -> V_55 . V_2 ;
V_59 = F_37 ( V_16 , V_2 ) ;
if ( V_59 ) {
F_15 ( V_57 ) ;
V_2 = F_12 ( V_59 ) ;
}
return V_2 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_59 ;
F_25 () ;
V_59 = V_60 . V_61 ( V_2 ) ;
F_27 () ;
return V_59 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_25 () ;
V_60 . V_64 ( V_2 ) ;
F_27 () ;
}
static int F_40 ( struct V_1 * V_2 )
{
return V_60 . V_65 ( V_2 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
return V_69 . V_70 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_71 )
{
int V_59 ;
F_25 () ;
F_28 () ;
V_59 = V_69 . V_72 ( V_2 , V_71 ) ;
F_27 () ;
return V_59 ;
}
static struct V_1 * F_43 ( struct V_15 * V_16 , const char * V_17 ,
const char * const * V_26 , int V_27 ,
void T_4 * V_58 , T_1 V_8 , T_1 V_73 , unsigned long V_19 ,
T_5 * V_67 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
V_55 = F_11 ( sizeof( * V_55 ) , V_22 ) ;
if ( ! V_55 ) {
V_2 = F_12 ( - V_42 ) ;
goto V_76;
}
V_75 = F_11 ( sizeof( * V_75 ) , V_22 ) ;
if ( ! V_75 ) {
F_15 ( V_55 ) ;
V_2 = F_12 ( - V_42 ) ;
goto V_76;
}
V_55 -> V_58 = V_58 ;
V_55 -> V_8 = V_8 ;
V_55 -> V_19 = 0 ;
V_55 -> V_67 = V_67 ;
V_75 -> V_58 = V_58 ;
V_75 -> V_73 = V_73 ;
V_75 -> V_77 = 3 ;
V_75 -> V_19 = 0 ;
V_2 = F_44 ( V_16 , V_17 , V_26 , V_27 ,
& V_75 -> V_2 , & V_78 ,
NULL , NULL ,
& V_55 -> V_2 , & V_79 ,
V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_55 ) ;
F_15 ( V_75 ) ;
}
V_76:
return V_2 ;
}
static void T_6 F_45 ( struct V_80 * V_81 )
{
const char * V_28 ;
int V_82 ;
const struct V_83 * V_84 ;
const struct V_85 * V_48 ;
V_6 = F_46 ( V_81 , 0 ) ;
if ( ! V_6 ) {
F_47 ( L_4 , V_81 -> V_17 ) ;
return;
}
V_51 = F_48 ( V_81 , L_5 ) ;
if ( F_14 ( V_51 ) ) {
V_51 = NULL ;
F_49 ( L_6 , V_86 ) ;
}
V_84 = F_50 ( V_87 , V_81 ) ;
if ( F_19 ( ! V_84 ) )
return;
V_48 = V_84 -> V_48 ;
V_50 = F_51 ( V_48 -> V_88 + V_41 ,
sizeof( * V_50 ) , V_22 ) ;
if ( ! V_50 )
goto V_76;
V_43 = V_48 -> V_89 ;
V_28 = F_52 ( V_81 , 0 ) ;
F_53 ( NULL , L_7 , NULL , 0 ,
16000000 , 160000 ) ;
F_16 ( V_28 , L_7 ) ;
V_90 [ 1 ] = V_28 ;
F_54 (
NULL , L_8 , V_90 , F_55 ( V_90 ) , 0 ,
V_6 + V_7 , 0 , 3 , 0 , NULL , & V_91 ) ;
F_56 ( NULL , L_9 , L_8 ,
V_12 , V_6 + V_7 ,
4 , 4 , 0 , V_92 , & V_91 ) ;
F_56 ( NULL , L_10 , L_9 ,
V_12 , V_6 + V_7 ,
10 , 3 , 0 , V_93 , & V_91 ) ;
F_10 ( NULL , L_11 , L_10 ,
V_12 , 12 ) ;
F_56 ( NULL , L_12 , L_9 ,
V_12 , V_6 + V_7 ,
13 , 3 , 0 , V_93 , & V_91 ) ;
F_10 ( NULL , L_13 , L_12 ,
V_12 , 15 ) ;
V_50 [ V_94 ] = F_57 ( NULL , L_14 , L_9 ,
0 , 1 , 8 ) ;
V_50 [ V_95 ] = F_57 ( NULL , L_15 , L_9 ,
0 , 1 , 1 ) ;
for ( V_82 = 0 ; V_82 < V_48 -> V_88 ; V_82 ++ ) {
const struct V_96 * V_97 ;
unsigned int V_38 ;
int V_98 ;
V_97 = & V_48 -> V_99 [ V_82 ] ;
V_38 = 8 * ( V_97 -> V_100 - V_101 ) +
V_97 -> V_8 ;
V_98 = F_18 ( 0 , V_38 ) ;
if ( V_98 < 0 )
goto V_76;
V_50 [ V_98 ] = F_58 (
NULL , V_97 -> V_17 , V_97 -> V_18 , V_97 -> V_19 ,
V_6 + V_97 -> V_100 , V_97 -> V_8 , 0 , & V_91 ) ;
if ( F_14 ( V_50 [ V_98 ] ) ) {
F_47 ( L_16 ,
V_81 -> V_102 , V_97 -> V_17 ) ;
goto V_76;
}
}
V_50 [ V_103 ] = F_36 ( NULL , L_17 , L_18 , 0 ,
V_6 + V_104 , 0 , 2 , 0 , & V_91 ) ;
if ( F_14 ( V_50 [ V_103 ] ) ) {
F_47 ( L_19 ) ;
goto V_76;
}
V_50 [ V_105 ] = F_36 ( NULL , L_20 , L_21 , 0 ,
V_6 + V_53 , 0 , 2 , 0 , & V_91 ) ;
if ( F_14 ( V_50 [ V_105 ] ) ) {
F_47 ( L_22 ) ;
goto V_76;
}
V_50 [ V_106 ] = F_59 ( NULL , L_23 , L_24 ,
0 , V_6 + V_7 , 16 , 5 , 0 ,
& V_91 ) ;
if ( F_14 ( V_50 [ V_106 ] ) ) {
F_47 ( L_25 ) ;
goto V_76;
}
V_50 [ V_107 ] = F_43 ( NULL , L_26 , V_108 , 4 ,
V_6 + V_53 , 15 , 8 , 0 , & V_91 ) ;
if ( F_14 ( V_50 [ V_107 ] ) ) {
F_47 ( L_27 ) ;
goto V_76;
}
F_60 ( V_81 , F_24 , NULL ) ;
return;
V_76:
F_15 ( V_50 ) ;
F_61 ( V_6 ) ;
}
