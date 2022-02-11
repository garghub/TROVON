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
inline void F_5 ( T_1 * V_11 )
{
static const T_1 V_12 [ V_13 ] = {
V_14 , V_15 , V_16 ,
V_17 , V_18 , V_19 ,
V_20 , V_21 } ;
memcpy ( V_11 , V_12 , sizeof( V_12 ) ) ;
}
inline T_2 F_6 ( T_3 V_22 [ V_23 * 2 ] ,
T_1 V_24 )
{
T_2 V_25 = V_24 & ( V_23 - 1 ) ;
memset ( & V_22 [ V_25 ] , 0 , V_23 ) ;
V_22 [ V_25 ] = 0x80 ;
V_25 += ( ( V_23 - 1 ) &
( 0 - ( V_24 + V_26 + 1 ) ) )
+ 1 + V_26 ;
#if V_26 == 16
* ( ( T_1 * ) & V_22 [ V_25 - 16 ] ) = 0 ;
#endif
* ( ( T_1 * ) & V_22 [ V_25 - 8 ] ) = F_7 ( V_24 << 3 ) ;
return V_25 >> V_27 ;
}
static struct V_2 * F_8
( struct V_28 * V_29 , struct V_2 * V_7 )
{
while ( V_7 ) {
if ( V_7 -> V_30 & V_31 ) {
V_7 -> V_30 = V_31 ;
return V_7 ;
}
if ( V_7 -> V_32 == 0 &&
V_7 -> V_33 ) {
const void * V_34 = V_7 -> V_35 ;
T_2 V_36 = V_7 -> V_33 ;
T_2 V_37 ;
V_37 = V_36 & ( V_23 - 1 ) ;
if ( V_37 ) {
V_36 -= V_37 ;
memcpy ( V_7 -> V_38 ,
( ( const char * ) V_34 + V_36 ) ,
V_37 ) ;
V_7 -> V_32 = V_37 ;
}
V_7 -> V_33 = 0 ;
assert ( ( V_36 % V_23 ) == 0 ) ;
V_36 >>= V_27 ;
if ( V_36 ) {
V_7 -> V_39 . V_34 = ( T_3 * ) V_34 ;
V_7 -> V_39 . V_36 = V_36 ;
V_7 = (struct V_2 * )
F_9 ( & V_29 -> V_29 ,
& V_7 -> V_39 ) ;
continue;
}
}
if ( V_7 -> V_30 & V_40 ) {
T_3 * V_41 = V_7 -> V_38 ;
T_2 V_42 =
F_6 ( V_41 , V_7 -> V_43 ) ;
V_7 -> V_30 = ( V_44 |
V_31 ) ;
V_7 -> V_39 . V_34 = V_41 ;
V_7 -> V_39 . V_36 = ( T_2 ) V_42 ;
V_7 = (struct V_2 * )
F_9 ( & V_29 -> V_29 , & V_7 -> V_39 ) ;
continue;
}
if ( V_7 )
V_7 -> V_30 = V_45 ;
return V_7 ;
}
return NULL ;
}
static struct V_2
* F_10 ( struct V_28 * V_29 )
{
struct V_2 * V_7 ;
V_7 = (struct V_2 * )
F_11 ( & V_29 -> V_29 ) ;
return F_8 ( V_29 , V_7 ) ;
}
static void F_12 ( struct V_28 * V_29 )
{
F_13 ( & V_29 -> V_29 ) ;
}
static struct V_2
* F_14 ( struct V_28 * V_29 ,
struct V_2 * V_7 ,
const void * V_34 ,
T_2 V_36 ,
int V_46 )
{
if ( V_46 & ( ~ V_47 ) ) {
V_7 -> error = V_48 ;
return V_7 ;
}
if ( V_7 -> V_30 & V_44 ) {
V_7 -> error = V_49 ;
return V_7 ;
}
if ( ( V_7 -> V_30 & V_31 ) && ! ( V_46 & V_50 ) ) {
V_7 -> error = V_51 ;
return V_7 ;
}
if ( V_46 & V_50 ) {
F_5 ( V_7 -> V_39 . V_52 ) ;
V_7 -> V_43 = 0 ;
V_7 -> V_32 = 0 ;
}
V_7 -> error = V_53 ;
V_7 -> V_35 = V_34 ;
V_7 -> V_33 = V_36 ;
V_7 -> V_30 = ( V_46 & V_54 ) ?
( V_44 | V_40 ) :
V_44 ;
V_7 -> V_43 += V_36 ;
if ( V_7 -> V_32 || V_36 < V_23 ) {
T_2 V_37 = V_23 -
V_7 -> V_32 ;
if ( V_36 < V_37 )
V_37 = V_36 ;
if ( V_37 ) {
memcpy
( & V_7 -> V_38 [ V_7 -> V_32 ] ,
V_34 , V_37 ) ;
V_7 -> V_32 += V_37 ;
V_7 -> V_35 = ( const void * )
( ( const char * ) V_34 + V_37 ) ;
V_7 -> V_33 = V_36 - V_37 ;
}
assert ( V_7 -> V_32 <= V_23 ) ;
if ( V_7 -> V_32 >= V_23 ) {
V_7 -> V_32 = 0 ;
V_7 -> V_39 . V_34 = V_7 -> V_38 ;
V_7 -> V_39 . V_36 = 1 ;
V_7 = (struct V_2 * )
F_9 ( & V_29 -> V_29 , & V_7 -> V_39 ) ;
}
}
return F_8 ( V_29 , V_7 ) ;
}
static struct V_2 * F_15 ( struct V_28 * V_29 )
{
struct V_2 * V_7 ;
while ( 1 ) {
V_7 = (struct V_2 * )
F_16 ( & V_29 -> V_29 ) ;
if ( ! V_7 )
return NULL ;
V_7 = F_8 ( V_29 , V_7 ) ;
if ( V_7 )
return V_7 ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_55 = F_18 ( V_5 ) ;
F_19 ( V_55 ) ;
V_55 -> V_39 . V_52 [ 0 ] = V_14 ;
V_55 -> V_39 . V_52 [ 1 ] = V_15 ;
V_55 -> V_39 . V_52 [ 2 ] = V_16 ;
V_55 -> V_39 . V_52 [ 3 ] = V_17 ;
V_55 -> V_39 . V_52 [ 4 ] = V_18 ;
V_55 -> V_39 . V_52 [ 5 ] = V_19 ;
V_55 -> V_39 . V_52 [ 6 ] = V_20 ;
V_55 -> V_39 . V_52 [ 7 ] = V_21 ;
V_55 -> V_43 = 0 ;
V_55 -> V_32 = 0 ;
V_55 -> V_30 = V_45 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_8 )
{
int V_25 ;
struct V_2 * V_55 = F_18 ( & V_8 -> V_5 ) ;
T_4 * V_56 = ( T_4 * ) V_8 -> V_57 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 )
V_56 [ V_25 ] = F_7 ( V_55 -> V_39 . V_52 [ V_25 ] ) ;
return 0 ;
}
static int F_21 ( struct V_1 * * V_58 ,
struct V_59 * V_60 , bool V_61 )
{
int V_9 = V_10 ;
int V_62 , V_63 = 0 ;
struct V_1 * V_8 = * V_58 ;
struct V_2 * V_64 ;
while ( ! ( V_8 -> V_9 & V_65 ) ) {
V_62 = F_22 ( & V_8 -> V_66 , 0 ) ;
if ( V_62 < 0 ) {
V_63 = V_62 ;
goto V_57;
}
if ( F_23 ( & V_8 -> V_66 ) ) {
V_8 -> V_9 |= V_65 ;
if ( V_8 -> V_9 & V_67 )
V_9 |= V_54 ;
}
V_64 = (struct V_2 * )
F_18 ( & V_8 -> V_5 ) ;
F_24 () ;
V_64 = F_14 ( V_60 -> V_29 , V_64 ,
V_8 -> V_66 . V_68 , V_62 , V_9 ) ;
if ( ! V_64 ) {
if ( V_61 )
V_64 = F_15 ( V_60 -> V_29 ) ;
}
F_25 () ;
if ( V_64 )
V_8 = F_1 ( V_64 ) ;
else {
V_8 = NULL ;
goto V_57;
}
}
if ( V_8 -> V_9 & V_67 )
F_20 ( V_8 ) ;
V_57:
* V_58 = V_8 ;
return V_63 ;
}
static int F_26 ( struct V_1 * V_8 ,
struct V_59 * V_60 ,
int V_63 )
{
struct V_4 * V_69 = F_3 ( V_8 ) ;
struct V_2 * V_64 ;
struct V_1 * V_70 ;
int V_71 ;
F_27 ( & V_60 -> V_72 ) ;
F_28 ( & V_8 -> V_73 ) ;
F_29 ( & V_60 -> V_72 ) ;
if ( F_30 () )
V_8 -> V_74 ( & V_69 -> V_75 , V_63 ) ;
else {
F_31 () ;
V_8 -> V_74 ( & V_69 -> V_75 , V_63 ) ;
F_32 () ;
}
V_64 = F_10 ( V_60 -> V_29 ) ;
while ( V_64 ) {
V_70 = F_1 ( V_64 ) ;
V_71 = F_21 ( & V_70 , V_60 , false ) ;
if ( V_70 ) {
F_27 ( & V_60 -> V_72 ) ;
F_28 ( & V_70 -> V_73 ) ;
F_29 ( & V_60 -> V_72 ) ;
V_69 = F_3 ( V_70 ) ;
if ( F_30 () )
V_70 -> V_74 ( & V_69 -> V_75 , V_71 ) ;
else {
F_31 () ;
V_70 -> V_74 ( & V_69 -> V_75 , V_71 ) ;
F_32 () ;
}
}
V_64 = F_10 ( V_60 -> V_29 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_8 ,
struct V_59 * V_60 )
{
unsigned long V_76 ;
unsigned long V_77 = F_34 ( V_78 ) ;
V_8 -> V_79 . V_80 = V_81 ;
V_8 -> V_79 . V_82 = V_60 -> V_83 ++ ;
V_76 = V_8 -> V_79 . V_80 + V_77 ;
V_8 -> V_79 . V_84 = V_76 ;
F_27 ( & V_60 -> V_72 ) ;
F_35 ( & V_8 -> V_73 , & V_60 -> V_85 ) ;
F_29 ( & V_60 -> V_72 ) ;
F_36 ( V_60 , V_77 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_59 * V_60 =
F_38 ( V_86 . V_87 ) ;
struct V_4 * V_69 = F_3 ( V_8 ) ;
struct V_2 * V_64 ;
int V_71 = 0 , V_62 ;
if ( V_8 -> V_79 . V_88 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_89;
}
F_4 ( V_8 , V_5 ) ;
V_62 = F_41 ( V_69 , & V_8 -> V_66 ) ;
if ( V_62 < 0 ) {
V_71 = V_62 ;
goto V_89;
}
if ( F_23 ( & V_8 -> V_66 ) )
V_8 -> V_9 |= V_65 ;
V_64 = (struct V_2 * ) F_18 ( V_5 ) ;
F_33 ( V_8 , V_60 ) ;
F_24 () ;
V_64 = F_14 ( V_60 -> V_29 , V_64 , V_8 -> V_66 . V_68 ,
V_62 , V_10 ) ;
F_25 () ;
if ( ! V_64 )
return - V_90 ;
if ( V_64 -> error ) {
V_71 = V_64 -> error ;
V_8 = F_1 ( V_64 ) ;
goto V_89;
}
V_8 = F_1 ( V_64 ) ;
V_71 = F_21 ( & V_8 , V_60 , false ) ;
if ( ! V_8 )
return - V_90 ;
V_89:
F_26 ( V_8 , V_60 , V_71 ) ;
return V_71 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_59 * V_60 =
F_38 ( V_86 . V_87 ) ;
struct V_4 * V_69 = F_3 ( V_8 ) ;
struct V_2 * V_64 ;
int V_71 = 0 , V_9 = V_10 , V_62 ;
if ( V_8 -> V_79 . V_88 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_89;
}
F_4 ( V_8 , V_5 ) ;
V_62 = F_41 ( V_69 , & V_8 -> V_66 ) ;
if ( V_62 < 0 ) {
V_71 = V_62 ;
goto V_89;
}
if ( F_23 ( & V_8 -> V_66 ) ) {
V_8 -> V_9 |= V_65 ;
V_9 = V_54 ;
}
V_8 -> V_9 |= V_67 ;
V_64 = (struct V_2 * ) F_18 ( V_5 ) ;
F_33 ( V_8 , V_60 ) ;
F_24 () ;
V_64 = F_14 ( V_60 -> V_29 , V_64 , V_8 -> V_66 . V_68 ,
V_62 , V_9 ) ;
F_25 () ;
if ( ! V_64 )
return - V_90 ;
if ( V_64 -> error ) {
V_71 = V_64 -> error ;
goto V_89;
}
V_8 = F_1 ( V_64 ) ;
V_71 = F_21 ( & V_8 , V_60 , false ) ;
if ( ! V_8 )
return - V_90 ;
V_89:
F_26 ( V_8 , V_60 , V_71 ) ;
return V_71 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_59 * V_60 =
F_38 ( V_86 . V_87 ) ;
struct V_2 * V_64 ;
int V_71 = 0 ;
T_5 V_68 ;
if ( V_8 -> V_79 . V_88 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_89;
}
F_4 ( V_8 , V_5 ) ;
V_8 -> V_9 |= V_65 | V_67 ;
V_64 = (struct V_2 * ) F_18 ( V_5 ) ;
F_33 ( V_8 , V_60 ) ;
F_24 () ;
V_64 = F_14 ( V_60 -> V_29 , V_64 , & V_68 , 0 ,
V_54 ) ;
F_25 () ;
if ( ! V_64 )
return - V_90 ;
if ( V_64 -> error ) {
V_71 = V_64 -> error ;
V_8 = F_1 ( V_64 ) ;
goto V_89;
}
V_8 = F_1 ( V_64 ) ;
V_71 = F_21 ( & V_8 , V_60 , false ) ;
if ( ! V_8 )
return - V_90 ;
V_89:
F_26 ( V_8 , V_60 , V_71 ) ;
return V_71 ;
}
static int F_44 ( struct V_4 * V_5 , void * V_57 )
{
struct V_2 * V_55 = F_18 ( V_5 ) ;
memcpy ( V_57 , V_55 , sizeof( * V_55 ) ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 , const void * V_91 )
{
struct V_2 * V_55 = F_18 ( V_5 ) ;
memcpy ( V_55 , V_91 , sizeof( * V_55 ) ) ;
return 0 ;
}
static int F_46 ( struct V_92 * V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_7 = F_47 ( V_93 ) ;
struct V_97 * V_98 ;
V_95 = F_48 ( L_2 ,
V_99 ,
V_99 ) ;
if ( F_49 ( V_95 ) )
return F_50 ( V_95 ) ;
V_98 = F_51 ( & V_95 -> V_75 ) ;
V_98 -> V_100 = & V_86 ;
V_7 -> V_95 = V_95 ;
F_52 ( F_53 ( V_93 ) ,
sizeof( struct V_4 ) +
F_54 ( & V_95 -> V_75 ) ) ;
return 0 ;
}
static void F_55 ( struct V_92 * V_93 )
{
struct V_96 * V_7 = F_47 ( V_93 ) ;
F_56 ( V_7 -> V_95 ) ;
}
static int F_57 ( struct V_92 * V_93 )
{
F_52 ( F_53 ( V_93 ) ,
sizeof( struct V_4 ) +
sizeof( struct V_2 ) ) ;
return 0 ;
}
static void F_58 ( struct V_92 * V_93 )
{
struct V_96 * V_7 = F_47 ( V_93 ) ;
F_56 ( V_7 -> V_95 ) ;
}
static int F_59 ( struct V_4 * V_69 )
{
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_62 ( V_102 ) ;
}
static int F_63 ( struct V_4 * V_69 )
{
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_64 ( V_102 ) ;
}
static int F_65 ( struct V_4 * V_69 )
{
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_66 ( V_102 ) ;
}
static int F_67 ( struct V_4 * V_69 )
{
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_68 ( V_102 ) ;
}
static int F_69 ( struct V_4 * V_69 )
{
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_70 ( V_102 ) ;
}
static int F_71 ( struct V_4 * V_69 , void * V_57 )
{
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
return F_72 ( V_102 , V_57 ) ;
}
static int F_73 ( struct V_4 * V_69 , const void * V_91 )
{
struct V_4 * V_102 = F_18 ( V_69 ) ;
struct V_101 * V_93 = F_60 ( V_69 ) ;
struct V_96 * V_7 = F_51 ( V_93 ) ;
struct V_94 * V_95 = V_7 -> V_95 ;
struct V_101 * V_103 = F_74 ( V_95 ) ;
struct V_1 * V_8 ;
struct V_4 * V_5 ;
memcpy ( V_102 , V_69 , sizeof( * V_69 ) ) ;
F_61 ( V_102 , & V_95 -> V_75 ) ;
V_8 = F_18 ( V_102 ) ;
V_5 = & V_8 -> V_5 ;
F_61 ( V_5 , V_103 ) ;
F_75 ( V_5 , V_104 ,
V_8 -> V_74 , V_69 ) ;
return F_76 ( V_102 , V_91 ) ;
}
static unsigned long F_77 ( struct V_59 * V_60 )
{
struct V_1 * V_8 ;
unsigned long V_105 ;
unsigned long V_76 = 0 ;
struct V_2 * V_64 ;
V_105 = V_81 ;
while ( ! F_78 ( & V_60 -> V_85 ) ) {
V_8 = F_79 ( V_60 -> V_85 . V_106 ,
struct V_1 , V_73 ) ;
if time_before( V_105 , V_8 -> V_79 . V_84 )
break;
F_24 () ;
V_64 = (struct V_2 * )
F_15 ( V_60 -> V_29 ) ;
F_25 () ;
if ( ! V_64 ) {
F_40 ( L_3
L_4 ) ;
break;
}
V_8 = F_1 ( V_64 ) ;
F_21 ( & V_8 , V_60 , true ) ;
F_26 ( V_8 , V_60 , 0 ) ;
}
if ( ! F_78 ( & V_60 -> V_85 ) ) {
V_8 = F_79 ( V_60 -> V_85 . V_106 ,
struct V_1 , V_73 ) ;
V_76 = V_8 -> V_79 . V_84 ;
F_36 ( V_60 , F_80 ( V_76 ) ) ;
}
return V_76 ;
}
static int T_6 F_81 ( void )
{
int V_88 ;
int V_63 ;
struct V_59 * V_107 ;
if ( ! F_82 ( V_108 ) ||
! F_82 ( V_109 ) )
return - V_110 ;
V_86 . V_87 =
F_83 ( struct V_59 ) ;
F_13 = V_111 ;
F_9 = V_112 ;
F_16 = V_113 ;
F_11 = V_114 ;
if ( ! V_86 . V_87 )
return - V_115 ;
F_84 (cpu) {
V_107 = F_85 ( V_86 . V_87 , V_88 ) ;
V_107 -> V_76 = 0 ;
V_107 -> V_83 = 0 ;
V_107 -> V_116 = false ;
F_86 ( & V_107 -> V_61 , V_117 ) ;
V_107 -> V_88 = V_88 ;
V_107 -> V_100 = & V_86 ;
V_107 -> V_29 = F_87 ( sizeof( struct V_28 ) ,
V_118 ) ;
if ( ! V_107 -> V_29 )
goto V_119;
F_12 ( V_107 -> V_29 ) ;
F_88 ( & V_107 -> V_85 ) ;
F_89 ( & V_107 -> V_72 ) ;
}
V_86 . V_120 = & F_77 ;
V_63 = F_90 ( & V_121 ) ;
if ( V_63 )
goto V_119;
V_63 = F_90 ( & V_122 ) ;
if ( V_63 )
goto V_123;
return 0 ;
V_123:
F_91 ( & V_121 ) ;
V_119:
F_84 (cpu) {
V_107 = F_85 ( V_86 . V_87 , V_88 ) ;
F_92 ( V_107 -> V_29 ) ;
}
F_93 ( V_86 . V_87 ) ;
return - V_110 ;
}
static void T_7 F_94 ( void )
{
int V_88 ;
struct V_59 * V_107 ;
F_91 ( & V_122 ) ;
F_91 ( & V_121 ) ;
F_84 (cpu) {
V_107 = F_85 ( V_86 . V_87 , V_88 ) ;
F_92 ( V_107 -> V_29 ) ;
}
F_93 ( V_86 . V_87 ) ;
}
