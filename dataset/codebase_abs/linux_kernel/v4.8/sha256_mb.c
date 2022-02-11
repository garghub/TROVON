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
V_14 , V_15 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_21 } ;
memcpy ( V_11 , V_12 , sizeof( V_12 ) ) ;
}
inline T_1 F_6 ( T_2 V_22 [ V_23 * 2 ] ,
T_1 V_24 )
{
T_1 V_25 = V_24 & ( V_23 - 1 ) ;
memset ( & V_22 [ V_25 ] , 0 , V_23 ) ;
V_22 [ V_25 ] = 0x80 ;
V_25 += ( ( V_23 - 1 ) &
( 0 - ( V_24 + V_26 + 1 ) ) )
+ 1 + V_26 ;
#if V_26 == 16
* ( ( V_27 * ) & V_22 [ V_25 - 16 ] ) = 0 ;
#endif
* ( ( V_27 * ) & V_22 [ V_25 - 8 ] ) = F_7 ( V_24 << 3 ) ;
return V_25 >> V_28 ;
}
static struct V_2
* F_8 ( struct V_29 * V_30 ,
struct V_2 * V_7 )
{
while ( V_7 ) {
if ( V_7 -> V_31 & V_32 ) {
V_7 -> V_31 = V_32 ;
return V_7 ;
}
if ( V_7 -> V_33 == 0 &&
V_7 -> V_34 ) {
const void * V_35 = V_7 -> V_36 ;
T_1 V_37 = V_7 -> V_34 ;
T_1 V_38 ;
V_38 = V_37 & ( V_23 - 1 ) ;
if ( V_38 ) {
V_37 -= V_38 ;
memcpy ( V_7 -> V_39 ,
( ( const char * ) V_35 + V_37 ) ,
V_38 ) ;
V_7 -> V_33 = V_38 ;
}
V_7 -> V_34 = 0 ;
assert ( ( V_37 % V_23 ) == 0 ) ;
V_37 >>= V_28 ;
if ( V_37 ) {
V_7 -> V_40 . V_35 = ( T_2 * ) V_35 ;
V_7 -> V_40 . V_37 = V_37 ;
V_7 = (struct V_2 * )
F_9 ( & V_30 -> V_30 , & V_7 -> V_40 ) ;
continue;
}
}
if ( V_7 -> V_31 & V_41 ) {
T_2 * V_42 = V_7 -> V_39 ;
T_1 V_43 =
F_6 ( V_42 , V_7 -> V_44 ) ;
V_7 -> V_31 = ( V_45 |
V_32 ) ;
V_7 -> V_40 . V_35 = V_42 ;
V_7 -> V_40 . V_37 = ( T_1 ) V_43 ;
V_7 = (struct V_2 * )
F_9 ( & V_30 -> V_30 , & V_7 -> V_40 ) ;
continue;
}
V_7 -> V_31 = V_46 ;
return V_7 ;
}
return NULL ;
}
static struct V_2
* F_10 ( struct V_29 * V_30 )
{
struct V_2 * V_7 ;
V_7 = (struct V_2 * ) F_11 ( & V_30 -> V_30 ) ;
return F_8 ( V_30 , V_7 ) ;
}
static void F_12 ( struct V_29 * V_30 )
{
F_13 ( & V_30 -> V_30 ) ;
}
static struct V_2 * F_14 ( struct V_29 * V_30 ,
struct V_2 * V_7 ,
const void * V_35 ,
T_1 V_37 ,
int V_47 )
{
if ( V_47 & ( ~ V_48 ) ) {
V_7 -> error = V_49 ;
return V_7 ;
}
if ( V_7 -> V_31 & V_45 ) {
V_7 -> error = V_50 ;
return V_7 ;
}
if ( ( V_7 -> V_31 & V_32 ) && ! ( V_47 & V_51 ) ) {
V_7 -> error = V_52 ;
return V_7 ;
}
if ( V_47 & V_51 ) {
F_5 ( V_7 -> V_40 . V_53 ) ;
V_7 -> V_44 = 0 ;
V_7 -> V_33 = 0 ;
}
V_7 -> error = V_54 ;
V_7 -> V_36 = V_35 ;
V_7 -> V_34 = V_37 ;
V_7 -> V_31 = ( V_47 & V_55 ) ?
( V_45 | V_41 ) :
V_45 ;
V_7 -> V_44 += V_37 ;
if ( V_7 -> V_33 || V_37 < V_23 ) {
T_1 V_38 = V_23 -
V_7 -> V_33 ;
if ( V_37 < V_38 )
V_38 = V_37 ;
if ( V_38 ) {
memcpy (
& V_7 -> V_39 [ V_7 -> V_33 ] ,
V_35 , V_38 ) ;
V_7 -> V_33 += V_38 ;
V_7 -> V_36 = ( const void * )
( ( const char * ) V_35 + V_38 ) ;
V_7 -> V_34 = V_37 - V_38 ;
}
assert ( V_7 -> V_33 <= V_23 ) ;
if ( V_7 -> V_33 >= V_23 ) {
V_7 -> V_33 = 0 ;
V_7 -> V_40 . V_35 = V_7 -> V_39 ;
V_7 -> V_40 . V_37 = 1 ;
V_7 = (struct V_2 * )
F_9 ( & V_30 -> V_30 , & V_7 -> V_40 ) ;
}
}
return F_8 ( V_30 , V_7 ) ;
}
static struct V_2 * F_15 ( struct V_29 * V_30 )
{
struct V_2 * V_7 ;
while ( 1 ) {
V_7 = (struct V_2 * )
F_16 ( & V_30 -> V_30 ) ;
if ( ! V_7 )
return NULL ;
V_7 = F_8 ( V_30 , V_7 ) ;
if ( V_7 )
return V_7 ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_56 = F_18 ( V_5 ) ;
F_19 ( V_56 ) ;
V_56 -> V_40 . V_53 [ 0 ] = V_14 ;
V_56 -> V_40 . V_53 [ 1 ] = V_15 ;
V_56 -> V_40 . V_53 [ 2 ] = V_16 ;
V_56 -> V_40 . V_53 [ 3 ] = V_17 ;
V_56 -> V_40 . V_53 [ 4 ] = V_18 ;
V_56 -> V_40 . V_53 [ 5 ] = V_19 ;
V_56 -> V_40 . V_53 [ 6 ] = V_20 ;
V_56 -> V_40 . V_53 [ 7 ] = V_21 ;
V_56 -> V_44 = 0 ;
V_56 -> V_33 = 0 ;
V_56 -> V_31 = V_46 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_8 )
{
int V_25 ;
struct V_2 * V_56 = F_18 ( & V_8 -> V_5 ) ;
T_3 * V_57 = ( T_3 * ) V_8 -> V_58 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 )
V_57 [ V_25 ] = F_21 ( V_56 -> V_40 . V_53 [ V_25 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * * V_59 ,
struct V_60 * V_61 , bool V_62 )
{
int V_9 = V_10 ;
int V_63 , V_64 = 0 ;
struct V_1 * V_8 = * V_59 ;
struct V_2 * V_65 ;
while ( ! ( V_8 -> V_9 & V_66 ) ) {
V_63 = F_23 ( & V_8 -> V_67 , 0 ) ;
if ( V_63 < 0 ) {
V_64 = V_63 ;
goto V_58;
}
if ( F_24 ( & V_8 -> V_67 ) ) {
V_8 -> V_9 |= V_66 ;
if ( V_8 -> V_9 & V_68 )
V_9 |= V_55 ;
}
V_65 = (struct V_2 * )
F_18 ( & V_8 -> V_5 ) ;
F_25 () ;
V_65 = F_14 ( V_61 -> V_30 , V_65 ,
V_8 -> V_67 . V_69 , V_63 , V_9 ) ;
if ( ! V_65 ) {
if ( V_62 )
V_65 = F_15 ( V_61 -> V_30 ) ;
}
F_26 () ;
if ( V_65 )
V_8 = F_1 ( V_65 ) ;
else {
V_8 = NULL ;
goto V_58;
}
}
if ( V_8 -> V_9 & V_68 )
F_20 ( V_8 ) ;
V_58:
* V_59 = V_8 ;
return V_64 ;
}
static int F_27 ( struct V_1 * V_8 ,
struct V_60 * V_61 ,
int V_64 )
{
struct V_4 * V_70 = F_3 ( V_8 ) ;
struct V_2 * V_65 ;
struct V_1 * V_71 ;
int V_72 ;
F_28 ( & V_61 -> V_73 ) ;
F_29 ( & V_8 -> V_74 ) ;
F_30 ( & V_61 -> V_73 ) ;
if ( F_31 () )
V_8 -> V_75 ( & V_70 -> V_76 , V_64 ) ;
else {
F_32 () ;
V_8 -> V_75 ( & V_70 -> V_76 , V_64 ) ;
F_33 () ;
}
V_65 = F_10 ( V_61 -> V_30 ) ;
while ( V_65 ) {
V_71 = F_1 ( V_65 ) ;
V_72 = F_22 ( & V_71 , V_61 , false ) ;
if ( V_71 ) {
F_28 ( & V_61 -> V_73 ) ;
F_29 ( & V_71 -> V_74 ) ;
F_30 ( & V_61 -> V_73 ) ;
V_70 = F_3 ( V_71 ) ;
if ( F_31 () )
V_71 -> V_75 ( & V_70 -> V_76 , V_72 ) ;
else {
F_32 () ;
V_71 -> V_75 ( & V_70 -> V_76 , V_72 ) ;
F_33 () ;
}
}
V_65 = F_10 ( V_61 -> V_30 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_8 ,
struct V_60 * V_61 )
{
unsigned long V_77 ;
unsigned long V_78 = F_35 ( V_79 ) ;
V_8 -> V_80 . V_81 = V_82 ;
V_8 -> V_80 . V_83 = V_61 -> V_84 ++ ;
V_77 = V_8 -> V_80 . V_81 + V_78 ;
V_8 -> V_80 . V_85 = V_77 ;
F_28 ( & V_61 -> V_73 ) ;
F_36 ( & V_8 -> V_74 , & V_61 -> V_86 ) ;
F_30 ( & V_61 -> V_73 ) ;
F_37 ( V_61 , V_78 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_60 * V_61 =
F_39 ( V_87 . V_88 ) ;
struct V_4 * V_70 = F_3 ( V_8 ) ;
struct V_2 * V_65 ;
int V_72 = 0 , V_63 ;
if ( V_8 -> V_80 . V_89 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_90;
}
F_4 ( V_8 , V_5 ) ;
V_63 = F_42 ( V_70 , & V_8 -> V_67 ) ;
if ( V_63 < 0 ) {
V_72 = V_63 ;
goto V_90;
}
if ( F_24 ( & V_8 -> V_67 ) )
V_8 -> V_9 |= V_66 ;
V_65 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_61 ) ;
F_25 () ;
V_65 = F_14 ( V_61 -> V_30 , V_65 , V_8 -> V_67 . V_69 ,
V_63 , V_10 ) ;
F_26 () ;
if ( ! V_65 )
return - V_91 ;
if ( V_65 -> error ) {
V_72 = V_65 -> error ;
V_8 = F_1 ( V_65 ) ;
goto V_90;
}
V_8 = F_1 ( V_65 ) ;
V_72 = F_22 ( & V_8 , V_61 , false ) ;
if ( ! V_8 )
return - V_91 ;
V_90:
F_27 ( V_8 , V_61 , V_72 ) ;
return V_72 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_60 * V_61 =
F_39 ( V_87 . V_88 ) ;
struct V_4 * V_70 = F_3 ( V_8 ) ;
struct V_2 * V_65 ;
int V_72 = 0 , V_9 = V_10 , V_63 ;
if ( V_8 -> V_80 . V_89 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_90;
}
F_4 ( V_8 , V_5 ) ;
V_63 = F_42 ( V_70 , & V_8 -> V_67 ) ;
if ( V_63 < 0 ) {
V_72 = V_63 ;
goto V_90;
}
if ( F_24 ( & V_8 -> V_67 ) ) {
V_8 -> V_9 |= V_66 ;
V_9 = V_55 ;
}
V_8 -> V_9 |= V_68 ;
V_65 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_61 ) ;
F_25 () ;
V_65 = F_14 ( V_61 -> V_30 , V_65 , V_8 -> V_67 . V_69 ,
V_63 , V_9 ) ;
F_26 () ;
if ( ! V_65 )
return - V_91 ;
if ( V_65 -> error ) {
V_72 = V_65 -> error ;
goto V_90;
}
V_8 = F_1 ( V_65 ) ;
V_72 = F_22 ( & V_8 , V_61 , false ) ;
if ( ! V_8 )
return - V_91 ;
V_90:
F_27 ( V_8 , V_61 , V_72 ) ;
return V_72 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_60 * V_61 =
F_39 ( V_87 . V_88 ) ;
struct V_2 * V_65 ;
int V_72 = 0 ;
T_4 V_69 ;
if ( V_8 -> V_80 . V_89 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_90;
}
F_4 ( V_8 , V_5 ) ;
V_8 -> V_9 |= V_66 | V_68 ;
V_65 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_61 ) ;
F_25 () ;
V_65 = F_14 ( V_61 -> V_30 , V_65 , & V_69 , 0 ,
V_55 ) ;
F_26 () ;
if ( ! V_65 )
return - V_91 ;
if ( V_65 -> error ) {
V_72 = V_65 -> error ;
V_8 = F_1 ( V_65 ) ;
goto V_90;
}
V_8 = F_1 ( V_65 ) ;
V_72 = F_22 ( & V_8 , V_61 , false ) ;
if ( ! V_8 )
return - V_91 ;
V_90:
F_27 ( V_8 , V_61 , V_72 ) ;
return V_72 ;
}
static int F_45 ( struct V_4 * V_5 , void * V_58 )
{
struct V_2 * V_56 = F_18 ( V_5 ) ;
memcpy ( V_58 , V_56 , sizeof( * V_56 ) ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , const void * V_92 )
{
struct V_2 * V_56 = F_18 ( V_5 ) ;
memcpy ( V_56 , V_92 , sizeof( * V_56 ) ) ;
return 0 ;
}
static int F_47 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_97 * V_7 = F_48 ( V_94 ) ;
struct V_98 * V_99 ;
V_96 = F_49 ( L_2 ,
V_100 ,
V_100 ) ;
if ( F_50 ( V_96 ) )
return F_51 ( V_96 ) ;
V_99 = F_52 ( & V_96 -> V_76 ) ;
V_99 -> V_101 = & V_87 ;
V_7 -> V_96 = V_96 ;
F_53 ( F_54 ( V_94 ) ,
sizeof( struct V_4 ) +
F_55 ( & V_96 -> V_76 ) ) ;
return 0 ;
}
static void F_56 ( struct V_93 * V_94 )
{
struct V_97 * V_7 = F_48 ( V_94 ) ;
F_57 ( V_7 -> V_96 ) ;
}
static int F_58 ( struct V_93 * V_94 )
{
F_53 ( F_54 ( V_94 ) ,
sizeof( struct V_4 ) +
sizeof( struct V_2 ) ) ;
return 0 ;
}
static void F_59 ( struct V_93 * V_94 )
{
struct V_97 * V_7 = F_48 ( V_94 ) ;
F_57 ( V_7 -> V_96 ) ;
}
static int F_60 ( struct V_4 * V_70 )
{
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_63 ( V_103 ) ;
}
static int F_64 ( struct V_4 * V_70 )
{
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_65 ( V_103 ) ;
}
static int F_66 ( struct V_4 * V_70 )
{
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_67 ( V_103 ) ;
}
static int F_68 ( struct V_4 * V_70 )
{
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_69 ( V_103 ) ;
}
static int F_70 ( struct V_4 * V_70 )
{
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_71 ( V_103 ) ;
}
static int F_72 ( struct V_4 * V_70 , void * V_58 )
{
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
return F_73 ( V_103 , V_58 ) ;
}
static int F_74 ( struct V_4 * V_70 , const void * V_92 )
{
struct V_4 * V_103 = F_18 ( V_70 ) ;
struct V_102 * V_94 = F_61 ( V_70 ) ;
struct V_97 * V_7 = F_52 ( V_94 ) ;
struct V_95 * V_96 = V_7 -> V_96 ;
struct V_102 * V_104 = F_75 ( V_96 ) ;
struct V_1 * V_8 ;
struct V_4 * V_5 ;
memcpy ( V_103 , V_70 , sizeof( * V_70 ) ) ;
F_62 ( V_103 , & V_96 -> V_76 ) ;
V_8 = F_18 ( V_103 ) ;
V_5 = & V_8 -> V_5 ;
F_62 ( V_5 , V_104 ) ;
F_76 ( V_5 , V_105 ,
V_8 -> V_75 , V_70 ) ;
return F_77 ( V_103 , V_92 ) ;
}
static unsigned long F_78 ( struct V_60 * V_61 )
{
struct V_1 * V_8 ;
unsigned long V_106 ;
unsigned long V_77 = 0 ;
struct V_2 * V_65 ;
V_106 = V_82 ;
while ( ! F_79 ( & V_61 -> V_86 ) ) {
V_8 = F_80 ( V_61 -> V_86 . V_107 ,
struct V_1 , V_74 ) ;
if ( F_81 ( V_106 , V_8 -> V_80 . V_85 ) )
break;
F_25 () ;
V_65 = (struct V_2 * )
F_15 ( V_61 -> V_30 ) ;
F_26 () ;
if ( ! V_65 ) {
F_41 ( L_3
L_4 ) ;
break;
}
V_8 = F_1 ( V_65 ) ;
F_22 ( & V_8 , V_61 , true ) ;
F_27 ( V_8 , V_61 , 0 ) ;
}
if ( ! F_79 ( & V_61 -> V_86 ) ) {
V_8 = F_80 ( V_61 -> V_86 . V_107 ,
struct V_1 , V_74 ) ;
V_77 = V_8 -> V_80 . V_85 ;
F_37 ( V_61 , F_82 ( V_77 ) ) ;
}
return V_77 ;
}
static int T_5 F_83 ( void )
{
int V_89 ;
int V_64 ;
struct V_60 * V_108 ;
if ( ! F_84 ( V_109 ) ||
! F_84 ( V_110 ) )
return - V_111 ;
V_87 . V_88 = F_85
( struct V_60 ) ;
F_13 = V_112 ;
F_9 = V_113 ;
F_16 = V_114 ;
F_11 = V_115 ;
if ( ! V_87 . V_88 )
return - V_116 ;
F_86 (cpu) {
V_108 = F_87 ( V_87 . V_88 , V_89 ) ;
V_108 -> V_77 = 0 ;
V_108 -> V_84 = 0 ;
V_108 -> V_117 = false ;
F_88 ( & V_108 -> V_62 , V_118 ) ;
V_108 -> V_89 = V_89 ;
V_108 -> V_101 = & V_87 ;
V_108 -> V_30 = F_89 ( sizeof( struct V_29 ) ,
V_119 ) ;
if ( ! V_108 -> V_30 )
goto V_120;
F_12 ( V_108 -> V_30 ) ;
F_90 ( & V_108 -> V_86 ) ;
F_91 ( & V_108 -> V_73 ) ;
}
V_87 . V_121 = & F_78 ;
V_64 = F_92 ( & V_122 ) ;
if ( V_64 )
goto V_120;
V_64 = F_92 ( & V_123 ) ;
if ( V_64 )
goto V_124;
return 0 ;
V_124:
F_93 ( & V_122 ) ;
V_120:
F_86 (cpu) {
V_108 = F_87 ( V_87 . V_88 , V_89 ) ;
F_94 ( V_108 -> V_30 ) ;
}
F_95 ( V_87 . V_88 ) ;
return - V_111 ;
}
static void T_6 F_96 ( void )
{
int V_89 ;
struct V_60 * V_108 ;
F_93 ( & V_123 ) ;
F_93 ( & V_122 ) ;
F_86 (cpu) {
V_108 = F_87 ( V_87 . V_88 , V_89 ) ;
F_94 ( V_108 -> V_30 ) ;
}
F_95 ( V_87 . V_88 ) ;
}
