static inline struct V_1
* F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( ( void * ) V_3 , struct V_4 , V_6 ) ;
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline struct V_4
* F_3 ( struct V_1 * V_7 )
{
return F_2 ( ( void * ) V_7 , struct V_4 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_8 ,
struct V_4 * V_5 )
{
V_8 -> V_9 = V_10 ;
}
static inline void F_5 ( T_1 * V_11 )
{
static const T_1 V_12 [ V_13 ] = { V_14 ,
V_15 , V_16 , V_17 , V_18 } ;
memcpy ( V_11 , V_12 , sizeof( V_12 ) ) ;
}
static inline T_1 F_6 ( T_2 V_19 [ V_20 * 2 ] ,
T_3 V_21 )
{
T_1 V_22 = V_21 & ( V_20 - 1 ) ;
memset ( & V_19 [ V_22 ] , 0 , V_20 ) ;
V_19 [ V_22 ] = 0x80 ;
V_22 += ( ( V_20 - 1 ) &
( 0 - ( V_21 + V_23 + 1 ) ) )
+ 1 + V_23 ;
#if V_23 == 16
* ( ( T_3 * ) & V_19 [ V_22 - 16 ] ) = 0 ;
#endif
* ( ( T_3 * ) & V_19 [ V_22 - 8 ] ) = F_7 ( V_21 << 3 ) ;
return V_22 >> V_24 ;
}
static struct V_2 * F_8 ( struct V_25 * V_26 ,
struct V_2 * V_7 )
{
while ( V_7 ) {
if ( V_7 -> V_27 & V_28 ) {
V_7 -> V_27 = V_28 ;
return V_7 ;
}
if ( V_7 -> V_29 == 0 &&
V_7 -> V_30 ) {
const void * V_31 = V_7 -> V_32 ;
T_1 V_33 = V_7 -> V_30 ;
T_1 V_34 ;
V_34 = V_33 & ( V_20 - 1 ) ;
if ( V_34 ) {
V_33 -= V_34 ;
memcpy ( V_7 -> V_35 ,
( ( const char * ) V_31 + V_33 ) ,
V_34 ) ;
V_7 -> V_29 = V_34 ;
}
V_7 -> V_30 = 0 ;
assert ( ( V_33 % V_20 ) == 0 ) ;
V_33 >>= V_24 ;
if ( V_33 ) {
V_7 -> V_36 . V_31 = ( T_2 * ) V_31 ;
V_7 -> V_36 . V_33 = V_33 ;
V_7 = (struct V_2 * ) F_9 ( & V_26 -> V_26 ,
& V_7 -> V_36 ) ;
continue;
}
}
if ( V_7 -> V_27 & V_37 ) {
T_2 * V_38 = V_7 -> V_35 ;
T_1 V_39 =
F_6 ( V_38 , V_7 -> V_40 ) ;
V_7 -> V_27 = ( V_41 |
V_28 ) ;
V_7 -> V_36 . V_31 = V_38 ;
V_7 -> V_36 . V_33 = ( T_1 ) V_39 ;
V_7 = (struct V_2 * )
F_9 ( & V_26 -> V_26 , & V_7 -> V_36 ) ;
continue;
}
V_7 -> V_27 = V_42 ;
return V_7 ;
}
return NULL ;
}
static struct V_2
* F_10 ( struct V_25 * V_26 )
{
struct V_2 * V_7 ;
V_7 = (struct V_2 * ) F_11 ( & V_26 -> V_26 ) ;
return F_8 ( V_26 , V_7 ) ;
}
static void F_12 ( struct V_25 * V_26 )
{
F_13 ( & V_26 -> V_26 ) ;
}
static struct V_2 * F_14 ( struct V_25 * V_26 ,
struct V_2 * V_7 ,
const void * V_31 ,
T_1 V_33 ,
int V_43 )
{
if ( V_43 & ( ~ V_44 ) ) {
V_7 -> error = V_45 ;
return V_7 ;
}
if ( V_7 -> V_27 & V_41 ) {
V_7 -> error = V_46 ;
return V_7 ;
}
if ( ( V_7 -> V_27 & V_28 ) && ! ( V_43 & V_47 ) ) {
V_7 -> error = V_48 ;
return V_7 ;
}
if ( V_43 & V_47 ) {
F_5 ( V_7 -> V_36 . V_49 ) ;
V_7 -> V_40 = 0 ;
V_7 -> V_29 = 0 ;
}
V_7 -> error = V_50 ;
V_7 -> V_32 = V_31 ;
V_7 -> V_30 = V_33 ;
V_7 -> V_27 = ( V_43 & V_51 ) ?
( V_41 | V_37 ) :
V_41 ;
V_7 -> V_40 += V_33 ;
if ( V_7 -> V_29 || V_33 < V_20 ) {
T_1 V_34 = V_20 -
V_7 -> V_29 ;
if ( V_33 < V_34 )
V_34 = V_33 ;
if ( V_34 ) {
memcpy ( & V_7 -> V_35 [ V_7 -> V_29 ] ,
V_31 , V_34 ) ;
V_7 -> V_29 += V_34 ;
V_7 -> V_32 = ( const void * )
( ( const char * ) V_31 + V_34 ) ;
V_7 -> V_30 = V_33 - V_34 ;
}
assert ( V_7 -> V_29 <= V_20 ) ;
if ( V_7 -> V_29 >= V_20 ) {
V_7 -> V_29 = 0 ;
V_7 -> V_36 . V_31 = V_7 -> V_35 ;
V_7 -> V_36 . V_33 = 1 ;
V_7 = (struct V_2 * )
F_9 ( & V_26 -> V_26 , & V_7 -> V_36 ) ;
}
}
return F_8 ( V_26 , V_7 ) ;
}
static struct V_2 * F_15 ( struct V_25 * V_26 )
{
struct V_2 * V_7 ;
while ( 1 ) {
V_7 = (struct V_2 * ) F_16 ( & V_26 -> V_26 ) ;
if ( ! V_7 )
return NULL ;
V_7 = F_8 ( V_26 , V_7 ) ;
if ( V_7 )
return V_7 ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_52 = F_18 ( V_5 ) ;
F_19 ( V_52 ) ;
V_52 -> V_36 . V_49 [ 0 ] = V_14 ;
V_52 -> V_36 . V_49 [ 1 ] = V_15 ;
V_52 -> V_36 . V_49 [ 2 ] = V_16 ;
V_52 -> V_36 . V_49 [ 3 ] = V_17 ;
V_52 -> V_36 . V_49 [ 4 ] = V_18 ;
V_52 -> V_40 = 0 ;
V_52 -> V_29 = 0 ;
V_52 -> V_27 = V_42 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_8 )
{
int V_22 ;
struct V_2 * V_52 = F_18 ( & V_8 -> V_5 ) ;
T_4 * V_53 = ( T_4 * ) V_8 -> V_54 ;
for ( V_22 = 0 ; V_22 < 5 ; ++ V_22 )
V_53 [ V_22 ] = F_21 ( V_52 -> V_36 . V_49 [ V_22 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * * V_55 ,
struct V_56 * V_57 , bool V_58 )
{
int V_9 = V_10 ;
int V_59 , V_60 = 0 ;
struct V_1 * V_8 = * V_55 ;
struct V_2 * V_61 ;
while ( ! ( V_8 -> V_9 & V_62 ) ) {
V_59 = F_23 ( & V_8 -> V_63 , 0 ) ;
if ( V_59 < 0 ) {
V_60 = V_59 ;
goto V_54;
}
if ( F_24 ( & V_8 -> V_63 ) ) {
V_8 -> V_9 |= V_62 ;
if ( V_8 -> V_9 & V_64 )
V_9 |= V_51 ;
}
V_61 = (struct V_2 * )
F_18 ( & V_8 -> V_5 ) ;
F_25 () ;
V_61 = F_14 ( V_57 -> V_26 , V_61 ,
V_8 -> V_63 . V_65 , V_59 , V_9 ) ;
if ( ! V_61 ) {
if ( V_58 )
V_61 = F_15 ( V_57 -> V_26 ) ;
}
F_26 () ;
if ( V_61 )
V_8 = F_1 ( V_61 ) ;
else {
V_8 = NULL ;
goto V_54;
}
}
if ( V_8 -> V_9 & V_64 )
F_20 ( V_8 ) ;
V_54:
* V_55 = V_8 ;
return V_60 ;
}
static int F_27 ( struct V_1 * V_8 ,
struct V_56 * V_57 ,
int V_60 )
{
struct V_4 * V_66 = F_3 ( V_8 ) ;
struct V_2 * V_61 ;
struct V_1 * V_67 ;
int V_68 ;
F_28 ( & V_57 -> V_69 ) ;
F_29 ( & V_8 -> V_70 ) ;
F_30 ( & V_57 -> V_69 ) ;
if ( F_31 () )
V_8 -> V_71 ( & V_66 -> V_72 , V_60 ) ;
else {
F_32 () ;
V_8 -> V_71 ( & V_66 -> V_72 , V_60 ) ;
F_33 () ;
}
V_61 = F_10 ( V_57 -> V_26 ) ;
while ( V_61 ) {
V_67 = F_1 ( V_61 ) ;
V_68 = F_22 ( & V_67 , V_57 , false ) ;
if ( V_67 ) {
F_28 ( & V_57 -> V_69 ) ;
F_29 ( & V_67 -> V_70 ) ;
F_30 ( & V_57 -> V_69 ) ;
V_66 = F_3 ( V_67 ) ;
if ( F_31 () )
V_67 -> V_71 ( & V_66 -> V_72 , V_68 ) ;
else {
F_32 () ;
V_67 -> V_71 ( & V_66 -> V_72 , V_68 ) ;
F_33 () ;
}
}
V_61 = F_10 ( V_57 -> V_26 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_8 ,
struct V_56 * V_57 )
{
unsigned long V_73 ;
unsigned long V_74 = F_35 ( V_75 ) ;
V_8 -> V_76 . V_77 = V_78 ;
V_8 -> V_76 . V_79 = V_57 -> V_80 ++ ;
V_73 = V_8 -> V_76 . V_77 + V_74 ;
V_8 -> V_76 . V_81 = V_73 ;
F_28 ( & V_57 -> V_69 ) ;
F_36 ( & V_8 -> V_70 , & V_57 -> V_82 ) ;
F_30 ( & V_57 -> V_69 ) ;
F_37 ( V_57 , V_74 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_56 * V_57 =
F_39 ( V_83 . V_84 ) ;
struct V_4 * V_66 = F_3 ( V_8 ) ;
struct V_2 * V_61 ;
int V_68 = 0 , V_59 ;
if ( V_8 -> V_76 . V_85 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_86;
}
F_4 ( V_8 , V_5 ) ;
V_59 = F_42 ( V_66 , & V_8 -> V_63 ) ;
if ( V_59 < 0 ) {
V_68 = V_59 ;
goto V_86;
}
if ( F_24 ( & V_8 -> V_63 ) )
V_8 -> V_9 |= V_62 ;
V_61 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_57 ) ;
F_25 () ;
V_61 = F_14 ( V_57 -> V_26 , V_61 , V_8 -> V_63 . V_65 ,
V_59 , V_10 ) ;
F_26 () ;
if ( ! V_61 )
return - V_87 ;
if ( V_61 -> error ) {
V_68 = V_61 -> error ;
V_8 = F_1 ( V_61 ) ;
goto V_86;
}
V_8 = F_1 ( V_61 ) ;
V_68 = F_22 ( & V_8 , V_57 , false ) ;
if ( ! V_8 )
return - V_87 ;
V_86:
F_27 ( V_8 , V_57 , V_68 ) ;
return V_68 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_56 * V_57 =
F_39 ( V_83 . V_84 ) ;
struct V_4 * V_66 = F_3 ( V_8 ) ;
struct V_2 * V_61 ;
int V_68 = 0 , V_9 = V_10 , V_59 ;
if ( V_8 -> V_76 . V_85 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_86;
}
F_4 ( V_8 , V_5 ) ;
V_59 = F_42 ( V_66 , & V_8 -> V_63 ) ;
if ( V_59 < 0 ) {
V_68 = V_59 ;
goto V_86;
}
if ( F_24 ( & V_8 -> V_63 ) ) {
V_8 -> V_9 |= V_62 ;
V_9 = V_51 ;
}
V_8 -> V_9 |= V_64 ;
V_61 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_57 ) ;
F_25 () ;
V_61 = F_14 ( V_57 -> V_26 , V_61 , V_8 -> V_63 . V_65 ,
V_59 , V_9 ) ;
F_26 () ;
if ( ! V_61 )
return - V_87 ;
if ( V_61 -> error ) {
V_68 = V_61 -> error ;
goto V_86;
}
V_8 = F_1 ( V_61 ) ;
V_68 = F_22 ( & V_8 , V_57 , false ) ;
if ( ! V_8 )
return - V_87 ;
V_86:
F_27 ( V_8 , V_57 , V_68 ) ;
return V_68 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_56 * V_57 =
F_39 ( V_83 . V_84 ) ;
struct V_2 * V_61 ;
int V_68 = 0 ;
T_5 V_65 ;
if ( V_8 -> V_76 . V_85 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_86;
}
F_4 ( V_8 , V_5 ) ;
V_8 -> V_9 |= V_62 | V_64 ;
V_61 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_57 ) ;
F_25 () ;
V_61 = F_14 ( V_57 -> V_26 , V_61 , & V_65 , 0 ,
V_51 ) ;
F_26 () ;
if ( ! V_61 )
return - V_87 ;
if ( V_61 -> error ) {
V_68 = V_61 -> error ;
V_8 = F_1 ( V_61 ) ;
goto V_86;
}
V_8 = F_1 ( V_61 ) ;
V_68 = F_22 ( & V_8 , V_57 , false ) ;
if ( ! V_8 )
return - V_87 ;
V_86:
F_27 ( V_8 , V_57 , V_68 ) ;
return V_68 ;
}
static int F_45 ( struct V_4 * V_5 , void * V_54 )
{
struct V_2 * V_52 = F_18 ( V_5 ) ;
memcpy ( V_54 , V_52 , sizeof( * V_52 ) ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , const void * V_88 )
{
struct V_2 * V_52 = F_18 ( V_5 ) ;
memcpy ( V_52 , V_88 , sizeof( * V_52 ) ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_93 * V_7 = F_48 ( V_90 ) ;
struct V_94 * V_95 ;
V_92 = F_49 ( L_2 ,
V_96 ,
V_96 ) ;
if ( F_50 ( V_92 ) )
return F_51 ( V_92 ) ;
V_95 = F_52 ( & V_92 -> V_72 ) ;
V_95 -> V_97 = & V_83 ;
V_7 -> V_92 = V_92 ;
F_53 ( F_54 ( V_90 ) ,
sizeof( struct V_4 ) +
F_55 ( & V_92 -> V_72 ) ) ;
return 0 ;
}
static void F_56 ( struct V_89 * V_90 )
{
struct V_93 * V_7 = F_48 ( V_90 ) ;
F_57 ( V_7 -> V_92 ) ;
}
static int F_58 ( struct V_89 * V_90 )
{
F_53 ( F_54 ( V_90 ) ,
sizeof( struct V_4 ) +
sizeof( struct V_2 ) ) ;
return 0 ;
}
static void F_59 ( struct V_89 * V_90 )
{
struct V_93 * V_7 = F_48 ( V_90 ) ;
F_57 ( V_7 -> V_92 ) ;
}
static int F_60 ( struct V_4 * V_66 )
{
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_63 ( V_99 ) ;
}
static int F_64 ( struct V_4 * V_66 )
{
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_65 ( V_99 ) ;
}
static int F_66 ( struct V_4 * V_66 )
{
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_67 ( V_99 ) ;
}
static int F_68 ( struct V_4 * V_66 )
{
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_69 ( V_99 ) ;
}
static int F_70 ( struct V_4 * V_66 )
{
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_71 ( V_99 ) ;
}
static int F_72 ( struct V_4 * V_66 , void * V_54 )
{
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
return F_73 ( V_99 , V_54 ) ;
}
static int F_74 ( struct V_4 * V_66 , const void * V_88 )
{
struct V_4 * V_99 = F_18 ( V_66 ) ;
struct V_98 * V_90 = F_61 ( V_66 ) ;
struct V_93 * V_7 = F_52 ( V_90 ) ;
struct V_91 * V_92 = V_7 -> V_92 ;
struct V_98 * V_100 = F_75 ( V_92 ) ;
struct V_1 * V_8 ;
struct V_4 * V_5 ;
memcpy ( V_99 , V_66 , sizeof( * V_66 ) ) ;
F_62 ( V_99 , & V_92 -> V_72 ) ;
V_8 = F_18 ( V_99 ) ;
V_5 = & V_8 -> V_5 ;
F_62 ( V_5 , V_100 ) ;
F_76 ( V_5 , V_101 ,
V_8 -> V_71 , V_66 ) ;
return F_77 ( V_99 , V_88 ) ;
}
static unsigned long F_78 ( struct V_56 * V_57 )
{
struct V_1 * V_8 ;
unsigned long V_102 ;
unsigned long V_73 = 0 ;
struct V_2 * V_61 ;
V_102 = V_78 ;
while ( ! F_79 ( & V_57 -> V_82 ) ) {
V_8 = F_80 ( V_57 -> V_82 . V_103 ,
struct V_1 , V_70 ) ;
if ( F_81 ( V_102 , V_8 -> V_76 . V_81 ) )
break;
F_25 () ;
V_61 = (struct V_2 * )
F_15 ( V_57 -> V_26 ) ;
F_26 () ;
if ( ! V_61 ) {
F_41 ( L_3 ) ;
break;
}
V_8 = F_1 ( V_61 ) ;
F_22 ( & V_8 , V_57 , true ) ;
F_27 ( V_8 , V_57 , 0 ) ;
}
if ( ! F_79 ( & V_57 -> V_82 ) ) {
V_8 = F_80 ( V_57 -> V_82 . V_103 ,
struct V_1 , V_70 ) ;
V_73 = V_8 -> V_76 . V_81 ;
F_37 ( V_57 , F_82 ( V_73 ) ) ;
}
return V_73 ;
}
static int T_6 F_83 ( void )
{
int V_85 ;
int V_60 ;
struct V_56 * V_104 ;
if ( ! F_84 ( V_105 ) ||
! F_84 ( V_106 ) )
return - V_107 ;
V_83 . V_84 = F_85 ( struct V_56 ) ;
F_13 = V_108 ;
F_9 = V_109 ;
F_16 = V_110 ;
F_11 = V_111 ;
if ( ! V_83 . V_84 )
return - V_112 ;
F_86 (cpu) {
V_104 = F_87 ( V_83 . V_84 , V_85 ) ;
V_104 -> V_73 = 0 ;
V_104 -> V_80 = 0 ;
V_104 -> V_113 = false ;
F_88 ( & V_104 -> V_58 , V_114 ) ;
V_104 -> V_85 = V_85 ;
V_104 -> V_97 = & V_83 ;
V_104 -> V_26 = F_89 ( sizeof( struct V_25 ) ,
V_115 ) ;
if ( ! V_104 -> V_26 )
goto V_116;
F_12 ( V_104 -> V_26 ) ;
F_90 ( & V_104 -> V_82 ) ;
F_91 ( & V_104 -> V_69 ) ;
}
V_83 . V_117 = & F_78 ;
V_60 = F_92 ( & V_118 ) ;
if ( V_60 )
goto V_116;
V_60 = F_92 ( & V_119 ) ;
if ( V_60 )
goto V_120;
return 0 ;
V_120:
F_93 ( & V_118 ) ;
V_116:
F_86 (cpu) {
V_104 = F_87 ( V_83 . V_84 , V_85 ) ;
F_94 ( V_104 -> V_26 ) ;
}
F_95 ( V_83 . V_84 ) ;
return - V_107 ;
}
static void T_7 F_96 ( void )
{
int V_85 ;
struct V_56 * V_104 ;
F_93 ( & V_119 ) ;
F_93 ( & V_118 ) ;
F_86 (cpu) {
V_104 = F_87 ( V_83 . V_84 , V_85 ) ;
F_94 ( V_104 -> V_26 ) ;
}
F_95 ( V_83 . V_84 ) ;
}
