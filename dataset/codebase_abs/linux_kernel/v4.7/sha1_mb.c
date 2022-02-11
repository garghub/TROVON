static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( ( void * ) V_3 , struct V_4 , V_6 ) ;
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline struct V_7 * F_3 ( struct V_1 * V_8 )
{
return F_2 ( ( void * ) V_8 , struct V_7 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_9 ,
struct V_4 * V_5 )
{
V_9 -> V_10 = V_11 ;
}
static inline void F_5 ( T_1 * V_12 )
{
static const T_1 V_13 [ V_14 ] = { V_15 ,
V_16 , V_17 , V_18 , V_19 } ;
memcpy ( V_12 , V_13 , sizeof( V_13 ) ) ;
}
static inline T_1 F_6 ( T_2 V_20 [ V_21 * 2 ] ,
T_1 V_22 )
{
T_1 V_23 = V_22 & ( V_21 - 1 ) ;
memset ( & V_20 [ V_23 ] , 0 , V_21 ) ;
V_20 [ V_23 ] = 0x80 ;
V_23 += ( ( V_21 - 1 ) &
( 0 - ( V_22 + V_24 + 1 ) ) )
+ 1 + V_24 ;
#if V_24 == 16
* ( ( V_25 * ) & V_20 [ V_23 - 16 ] ) = 0 ;
#endif
* ( ( V_25 * ) & V_20 [ V_23 - 8 ] ) = F_7 ( V_22 << 3 ) ;
return V_23 >> V_26 ;
}
static struct V_2 * F_8 ( struct V_27 * V_28 , struct V_2 * V_8 )
{
while ( V_8 ) {
if ( V_8 -> V_29 & V_30 ) {
V_8 -> V_29 = V_30 ;
return V_8 ;
}
if ( V_8 -> V_31 == 0 &&
V_8 -> V_32 ) {
const void * V_33 = V_8 -> V_34 ;
T_1 V_35 = V_8 -> V_32 ;
T_1 V_36 ;
V_36 = V_35 & ( V_21 - 1 ) ;
if ( V_36 ) {
V_35 -= V_36 ;
memcpy ( V_8 -> V_37 ,
( ( const char * ) V_33 + V_35 ) ,
V_36 ) ;
V_8 -> V_31 = V_36 ;
}
V_8 -> V_32 = 0 ;
assert ( ( V_35 % V_21 ) == 0 ) ;
V_35 >>= V_26 ;
if ( V_35 ) {
V_8 -> V_38 . V_33 = ( T_2 * ) V_33 ;
V_8 -> V_38 . V_35 = V_35 ;
V_8 = (struct V_2 * ) F_9 ( & V_28 -> V_28 ,
& V_8 -> V_38 ) ;
continue;
}
}
if ( V_8 -> V_29 & V_39 ) {
T_2 * V_40 = V_8 -> V_37 ;
T_1 V_41 = F_6 ( V_40 , V_8 -> V_42 ) ;
V_8 -> V_29 = ( V_43 |
V_30 ) ;
V_8 -> V_38 . V_33 = V_40 ;
V_8 -> V_38 . V_35 = ( T_1 ) V_41 ;
V_8 = (struct V_2 * ) F_9 ( & V_28 -> V_28 , & V_8 -> V_38 ) ;
continue;
}
V_8 -> V_29 = V_44 ;
return V_8 ;
}
return NULL ;
}
static struct V_2 * F_10 ( struct V_27 * V_28 )
{
struct V_2 * V_8 ;
V_8 = (struct V_2 * ) F_11 ( & V_28 -> V_28 ) ;
return F_8 ( V_28 , V_8 ) ;
}
static void F_12 ( struct V_27 * V_28 )
{
F_13 ( & V_28 -> V_28 ) ;
}
static struct V_2 * F_14 ( struct V_27 * V_28 ,
struct V_2 * V_8 ,
const void * V_33 ,
T_1 V_35 ,
int V_45 )
{
if ( V_45 & ( ~ V_46 ) ) {
V_8 -> error = V_47 ;
return V_8 ;
}
if ( V_8 -> V_29 & V_43 ) {
V_8 -> error = V_48 ;
return V_8 ;
}
if ( ( V_8 -> V_29 & V_30 ) && ! ( V_45 & V_49 ) ) {
V_8 -> error = V_50 ;
return V_8 ;
}
if ( V_45 & V_49 ) {
F_5 ( V_8 -> V_38 . V_51 ) ;
V_8 -> V_42 = 0 ;
V_8 -> V_31 = 0 ;
}
V_8 -> error = V_52 ;
V_8 -> V_34 = V_33 ;
V_8 -> V_32 = V_35 ;
V_8 -> V_29 = ( V_45 & V_53 ) ?
( V_43 | V_39 ) :
V_43 ;
V_8 -> V_42 += V_35 ;
if ( ( V_8 -> V_31 ) | ( V_35 < V_21 ) ) {
T_1 V_36 = V_21 - V_8 -> V_31 ;
if ( V_35 < V_36 )
V_36 = V_35 ;
if ( V_36 ) {
memcpy ( & V_8 -> V_37 [ V_8 -> V_31 ] ,
V_33 , V_36 ) ;
V_8 -> V_31 += V_36 ;
V_8 -> V_34 = ( const void * ) ( ( const char * ) V_33 + V_36 ) ;
V_8 -> V_32 = V_35 - V_36 ;
}
assert ( V_8 -> V_31 <= V_21 ) ;
if ( V_8 -> V_31 >= V_21 ) {
V_8 -> V_31 = 0 ;
V_8 -> V_38 . V_33 = V_8 -> V_37 ;
V_8 -> V_38 . V_35 = 1 ;
V_8 = (struct V_2 * ) F_9 ( & V_28 -> V_28 , & V_8 -> V_38 ) ;
}
}
return F_8 ( V_28 , V_8 ) ;
}
static struct V_2 * F_15 ( struct V_27 * V_28 )
{
struct V_2 * V_8 ;
while ( 1 ) {
V_8 = (struct V_2 * ) F_16 ( & V_28 -> V_28 ) ;
if ( ! V_8 )
return NULL ;
V_8 = F_8 ( V_28 , V_8 ) ;
if ( V_8 )
return V_8 ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_54 = F_18 ( V_5 ) ;
F_19 ( V_54 ) ;
V_54 -> V_38 . V_51 [ 0 ] = V_15 ;
V_54 -> V_38 . V_51 [ 1 ] = V_16 ;
V_54 -> V_38 . V_51 [ 2 ] = V_17 ;
V_54 -> V_38 . V_51 [ 3 ] = V_18 ;
V_54 -> V_38 . V_51 [ 4 ] = V_19 ;
V_54 -> V_42 = 0 ;
V_54 -> V_31 = 0 ;
V_54 -> V_29 = V_44 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_9 )
{
int V_23 ;
struct V_2 * V_54 = F_18 ( & V_9 -> V_5 ) ;
T_3 * V_55 = ( T_3 * ) V_9 -> V_56 ;
for ( V_23 = 0 ; V_23 < 5 ; ++ V_23 )
V_55 [ V_23 ] = F_21 ( V_54 -> V_38 . V_51 [ V_23 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * * V_57 ,
struct V_58 * V_59 , bool V_60 )
{
int V_10 = V_11 ;
int V_61 , V_62 = 0 ;
struct V_1 * V_9 = * V_57 ;
struct V_2 * V_63 ;
while ( ! ( V_9 -> V_10 & V_64 ) ) {
V_61 = F_23 ( & V_9 -> V_65 , 0 ) ;
if ( V_61 < 0 ) {
V_62 = V_61 ;
goto V_56;
}
if ( F_24 ( & V_9 -> V_65 ) ) {
V_9 -> V_10 |= V_64 ;
if ( V_9 -> V_10 & V_66 )
V_10 |= V_53 ;
}
V_63 = (struct V_2 * ) F_18 ( & V_9 -> V_5 ) ;
F_25 () ;
V_63 = F_14 ( V_59 -> V_28 , V_63 , V_9 -> V_65 . V_67 , V_61 , V_10 ) ;
if ( ! V_63 ) {
if ( V_60 )
V_63 = F_15 ( V_59 -> V_28 ) ;
}
F_26 () ;
if ( V_63 )
V_9 = F_1 ( V_63 ) ;
else {
V_9 = NULL ;
goto V_56;
}
}
if ( V_9 -> V_10 & V_66 )
F_20 ( V_9 ) ;
V_56:
* V_57 = V_9 ;
return V_62 ;
}
static int F_27 ( struct V_1 * V_9 ,
struct V_58 * V_59 ,
int V_62 )
{
struct V_7 * V_68 = F_3 ( V_9 ) ;
struct V_2 * V_63 ;
struct V_1 * V_69 ;
int V_70 ;
F_28 ( & V_59 -> V_71 ) ;
F_29 ( & V_9 -> V_72 ) ;
F_30 ( & V_59 -> V_71 ) ;
if ( F_31 () )
V_9 -> V_73 ( & V_68 -> V_74 , V_62 ) ;
else {
F_32 () ;
V_9 -> V_73 ( & V_68 -> V_74 , V_62 ) ;
F_33 () ;
}
V_63 = F_10 ( V_59 -> V_28 ) ;
while ( V_63 ) {
V_69 = F_1 ( V_63 ) ;
V_70 = F_22 ( & V_69 , V_59 , false ) ;
if ( V_69 ) {
F_28 ( & V_59 -> V_71 ) ;
F_29 ( & V_69 -> V_72 ) ;
F_30 ( & V_59 -> V_71 ) ;
V_68 = F_3 ( V_69 ) ;
if ( F_31 () )
V_69 -> V_73 ( & V_68 -> V_74 , V_70 ) ;
else {
F_32 () ;
V_69 -> V_73 ( & V_68 -> V_74 , V_70 ) ;
F_33 () ;
}
}
V_63 = F_10 ( V_59 -> V_28 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_9 ,
struct V_58 * V_59 )
{
unsigned long V_75 ;
unsigned long V_76 = F_35 ( V_77 ) ;
V_9 -> V_78 . V_79 = V_80 ;
V_9 -> V_78 . V_81 = V_59 -> V_82 ++ ;
V_75 = V_9 -> V_78 . V_79 + V_76 ;
V_9 -> V_78 . V_83 = V_75 ;
F_28 ( & V_59 -> V_71 ) ;
F_36 ( & V_9 -> V_72 , & V_59 -> V_84 ) ;
F_30 ( & V_59 -> V_71 ) ;
F_37 ( V_59 , V_76 ) ;
}
static int F_38 ( struct V_4 * V_5 , const T_4 * V_67 ,
unsigned int V_35 )
{
struct V_1 * V_9 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_58 * V_59 =
F_39 ( V_85 . V_86 ) ;
struct V_7 * V_68 = F_3 ( V_9 ) ;
struct V_2 * V_63 ;
int V_70 = 0 , V_61 ;
if ( V_9 -> V_78 . V_87 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_88;
}
F_4 ( V_9 , V_5 ) ;
V_61 = F_42 ( V_68 , & V_9 -> V_65 ) ;
if ( V_61 < 0 ) {
V_70 = V_61 ;
goto V_88;
}
if ( F_24 ( & V_9 -> V_65 ) )
V_9 -> V_10 |= V_64 ;
V_63 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_9 , V_59 ) ;
F_25 () ;
V_63 = F_14 ( V_59 -> V_28 , V_63 , V_9 -> V_65 . V_67 , V_61 , V_11 ) ;
F_26 () ;
if ( ! V_63 )
return - V_89 ;
if ( V_63 -> error ) {
V_70 = V_63 -> error ;
V_9 = F_1 ( V_63 ) ;
goto V_88;
}
V_9 = F_1 ( V_63 ) ;
V_70 = F_22 ( & V_9 , V_59 , false ) ;
if ( ! V_9 )
return - V_89 ;
V_88:
F_27 ( V_9 , V_59 , V_70 ) ;
return V_70 ;
}
static int F_43 ( struct V_4 * V_5 , const T_4 * V_67 ,
unsigned int V_35 , T_4 * V_56 )
{
struct V_1 * V_9 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_58 * V_59 =
F_39 ( V_85 . V_86 ) ;
struct V_7 * V_68 = F_3 ( V_9 ) ;
struct V_2 * V_63 ;
int V_70 = 0 , V_10 = V_11 , V_61 ;
if ( V_9 -> V_78 . V_87 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_88;
}
F_4 ( V_9 , V_5 ) ;
V_61 = F_42 ( V_68 , & V_9 -> V_65 ) ;
if ( V_61 < 0 ) {
V_70 = V_61 ;
goto V_88;
}
if ( F_24 ( & V_9 -> V_65 ) ) {
V_9 -> V_10 |= V_64 ;
V_10 = V_53 ;
}
V_9 -> V_56 = V_56 ;
V_9 -> V_10 |= V_66 ;
V_63 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_9 , V_59 ) ;
F_25 () ;
V_63 = F_14 ( V_59 -> V_28 , V_63 , V_9 -> V_65 . V_67 , V_61 , V_10 ) ;
F_26 () ;
if ( ! V_63 )
return - V_89 ;
if ( V_63 -> error ) {
V_70 = V_63 -> error ;
goto V_88;
}
V_9 = F_1 ( V_63 ) ;
V_70 = F_22 ( & V_9 , V_59 , false ) ;
if ( ! V_9 )
return - V_89 ;
V_88:
F_27 ( V_9 , V_59 , V_70 ) ;
return V_70 ;
}
static int F_44 ( struct V_4 * V_5 , T_4 * V_56 )
{
struct V_1 * V_9 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_58 * V_59 =
F_39 ( V_85 . V_86 ) ;
struct V_2 * V_63 ;
int V_70 = 0 ;
T_4 V_67 ;
if ( V_9 -> V_78 . V_87 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_88;
}
F_4 ( V_9 , V_5 ) ;
V_9 -> V_56 = V_56 ;
V_9 -> V_10 |= V_64 | V_66 ;
V_63 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_9 , V_59 ) ;
F_25 () ;
V_63 = F_14 ( V_59 -> V_28 , V_63 , & V_67 , 0 , V_53 ) ;
F_26 () ;
if ( ! V_63 )
return - V_89 ;
if ( V_63 -> error ) {
V_70 = V_63 -> error ;
V_9 = F_1 ( V_63 ) ;
goto V_88;
}
V_9 = F_1 ( V_63 ) ;
V_70 = F_22 ( & V_9 , V_59 , false ) ;
if ( ! V_9 )
return - V_89 ;
V_88:
F_27 ( V_9 , V_59 , V_70 ) ;
return V_70 ;
}
static int F_45 ( struct V_4 * V_5 , void * V_56 )
{
struct V_2 * V_54 = F_18 ( V_5 ) ;
memcpy ( V_56 , V_54 , sizeof( * V_54 ) ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , const void * V_90 )
{
struct V_2 * V_54 = F_18 ( V_5 ) ;
memcpy ( V_54 , V_90 , sizeof( * V_54 ) ) ;
return 0 ;
}
static int F_47 ( struct V_7 * V_68 )
{
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_52 ( V_94 ) ;
}
static int F_53 ( struct V_7 * V_68 )
{
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_54 ( V_94 ) ;
}
static int F_55 ( struct V_7 * V_68 )
{
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_56 ( V_94 ) ;
}
static int F_57 ( struct V_7 * V_68 )
{
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_58 ( V_94 ) ;
}
static int F_59 ( struct V_7 * V_68 )
{
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_60 ( V_94 ) ;
}
static int F_61 ( struct V_7 * V_68 , void * V_56 )
{
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
return F_62 ( V_94 , V_56 ) ;
}
static int F_63 ( struct V_7 * V_68 , const void * V_90 )
{
struct V_7 * V_94 = F_50 ( V_68 ) ;
struct V_91 * V_92 = F_48 ( V_68 ) ;
struct V_93 * V_8 = F_49 ( V_92 ) ;
struct V_95 * V_96 = V_8 -> V_96 ;
struct V_97 * V_98 = F_64 ( V_96 ) ;
struct V_1 * V_9 ;
struct V_4 * V_5 ;
memcpy ( V_94 , V_68 , sizeof( * V_68 ) ) ;
F_51 ( V_94 , & V_96 -> V_74 ) ;
V_9 = F_50 ( V_94 ) ;
V_5 = & V_9 -> V_5 ;
V_5 -> V_92 = V_98 ;
V_5 -> V_45 = V_99 ;
return F_65 ( V_94 , V_90 ) ;
}
static int F_66 ( struct V_100 * V_92 )
{
struct V_95 * V_96 ;
struct V_93 * V_8 = F_67 ( V_92 ) ;
struct V_101 * V_102 ;
V_96 = F_68 ( L_2 ,
V_103 ,
V_103 ) ;
if ( F_69 ( V_96 ) )
return F_70 ( V_96 ) ;
V_102 = F_49 ( & V_96 -> V_74 ) ;
V_102 -> V_104 = & V_85 ;
V_8 -> V_96 = V_96 ;
F_71 ( F_72 ( V_92 ) ,
sizeof( struct V_7 ) +
F_73 ( & V_96 -> V_74 ) ) ;
return 0 ;
}
static void F_74 ( struct V_100 * V_92 )
{
struct V_93 * V_8 = F_67 ( V_92 ) ;
F_75 ( V_8 -> V_96 ) ;
}
static unsigned long F_76 ( struct V_58 * V_59 )
{
struct V_1 * V_9 ;
unsigned long V_105 ;
unsigned long V_75 = 0 ;
struct V_2 * V_63 ;
V_105 = V_80 ;
while ( ! F_77 ( & V_59 -> V_84 ) ) {
V_9 = F_78 ( V_59 -> V_84 . V_106 ,
struct V_1 , V_72 ) ;
if ( F_79 ( V_105 , V_9 -> V_78 . V_83 ) )
break;
F_25 () ;
V_63 = (struct V_2 * ) F_15 ( V_59 -> V_28 ) ;
F_26 () ;
if ( ! V_63 ) {
F_41 ( L_3 ) ;
break;
}
V_9 = F_1 ( V_63 ) ;
F_22 ( & V_9 , V_59 , true ) ;
F_27 ( V_9 , V_59 , 0 ) ;
}
if ( ! F_77 ( & V_59 -> V_84 ) ) {
V_9 = F_78 ( V_59 -> V_84 . V_106 ,
struct V_1 , V_72 ) ;
V_75 = V_9 -> V_78 . V_83 ;
F_37 ( V_59 , F_80 ( V_75 ) ) ;
}
return V_75 ;
}
static int T_5 F_81 ( void )
{
int V_87 ;
int V_62 ;
struct V_58 * V_107 ;
if ( ! F_82 ( V_108 ) ||
! F_82 ( V_109 ) )
return - V_110 ;
V_85 . V_86 = F_83 ( struct V_58 ) ;
F_13 = V_111 ;
F_9 = V_112 ;
F_16 = V_113 ;
F_11 = V_114 ;
if ( ! V_85 . V_86 )
return - V_115 ;
F_84 (cpu) {
V_107 = F_85 ( V_85 . V_86 , V_87 ) ;
V_107 -> V_75 = 0 ;
V_107 -> V_82 = 0 ;
V_107 -> V_116 = false ;
F_86 ( & V_107 -> V_60 , V_117 ) ;
V_107 -> V_87 = V_87 ;
V_107 -> V_104 = & V_85 ;
V_107 -> V_28 = F_87 ( sizeof( struct V_27 ) ,
V_118 ) ;
if ( ! V_107 -> V_28 )
goto V_119;
F_12 ( V_107 -> V_28 ) ;
F_88 ( & V_107 -> V_84 ) ;
F_89 ( & V_107 -> V_71 ) ;
}
V_85 . V_120 = & F_76 ;
V_62 = F_90 ( & V_121 ) ;
if ( V_62 )
goto V_119;
V_62 = F_91 ( & V_122 ) ;
if ( V_62 )
goto V_123;
return 0 ;
V_123:
F_92 ( & V_121 ) ;
V_119:
F_84 (cpu) {
V_107 = F_85 ( V_85 . V_86 , V_87 ) ;
F_93 ( V_107 -> V_28 ) ;
}
F_94 ( V_85 . V_86 ) ;
return - V_110 ;
}
static void T_6 F_95 ( void )
{
int V_87 ;
struct V_58 * V_107 ;
F_96 ( & V_122 ) ;
F_92 ( & V_121 ) ;
F_84 (cpu) {
V_107 = F_85 ( V_85 . V_86 , V_87 ) ;
F_93 ( V_107 -> V_28 ) ;
}
F_94 ( V_85 . V_86 ) ;
}
