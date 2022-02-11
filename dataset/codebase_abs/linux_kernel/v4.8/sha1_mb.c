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
T_1 V_21 )
{
T_1 V_22 = V_21 & ( V_20 - 1 ) ;
memset ( & V_19 [ V_22 ] , 0 , V_20 ) ;
V_19 [ V_22 ] = 0x80 ;
V_22 += ( ( V_20 - 1 ) &
( 0 - ( V_21 + V_23 + 1 ) ) )
+ 1 + V_23 ;
#if V_23 == 16
* ( ( V_24 * ) & V_19 [ V_22 - 16 ] ) = 0 ;
#endif
* ( ( V_24 * ) & V_19 [ V_22 - 8 ] ) = F_7 ( V_21 << 3 ) ;
return V_22 >> V_25 ;
}
static struct V_2 * F_8 ( struct V_26 * V_27 ,
struct V_2 * V_7 )
{
while ( V_7 ) {
if ( V_7 -> V_28 & V_29 ) {
V_7 -> V_28 = V_29 ;
return V_7 ;
}
if ( V_7 -> V_30 == 0 &&
V_7 -> V_31 ) {
const void * V_32 = V_7 -> V_33 ;
T_1 V_34 = V_7 -> V_31 ;
T_1 V_35 ;
V_35 = V_34 & ( V_20 - 1 ) ;
if ( V_35 ) {
V_34 -= V_35 ;
memcpy ( V_7 -> V_36 ,
( ( const char * ) V_32 + V_34 ) ,
V_35 ) ;
V_7 -> V_30 = V_35 ;
}
V_7 -> V_31 = 0 ;
assert ( ( V_34 % V_20 ) == 0 ) ;
V_34 >>= V_25 ;
if ( V_34 ) {
V_7 -> V_37 . V_32 = ( T_2 * ) V_32 ;
V_7 -> V_37 . V_34 = V_34 ;
V_7 = (struct V_2 * ) F_9 ( & V_27 -> V_27 ,
& V_7 -> V_37 ) ;
continue;
}
}
if ( V_7 -> V_28 & V_38 ) {
T_2 * V_39 = V_7 -> V_36 ;
T_1 V_40 =
F_6 ( V_39 , V_7 -> V_41 ) ;
V_7 -> V_28 = ( V_42 |
V_29 ) ;
V_7 -> V_37 . V_32 = V_39 ;
V_7 -> V_37 . V_34 = ( T_1 ) V_40 ;
V_7 = (struct V_2 * )
F_9 ( & V_27 -> V_27 , & V_7 -> V_37 ) ;
continue;
}
V_7 -> V_28 = V_43 ;
return V_7 ;
}
return NULL ;
}
static struct V_2
* F_10 ( struct V_26 * V_27 )
{
struct V_2 * V_7 ;
V_7 = (struct V_2 * ) F_11 ( & V_27 -> V_27 ) ;
return F_8 ( V_27 , V_7 ) ;
}
static void F_12 ( struct V_26 * V_27 )
{
F_13 ( & V_27 -> V_27 ) ;
}
static struct V_2 * F_14 ( struct V_26 * V_27 ,
struct V_2 * V_7 ,
const void * V_32 ,
T_1 V_34 ,
int V_44 )
{
if ( V_44 & ( ~ V_45 ) ) {
V_7 -> error = V_46 ;
return V_7 ;
}
if ( V_7 -> V_28 & V_42 ) {
V_7 -> error = V_47 ;
return V_7 ;
}
if ( ( V_7 -> V_28 & V_29 ) && ! ( V_44 & V_48 ) ) {
V_7 -> error = V_49 ;
return V_7 ;
}
if ( V_44 & V_48 ) {
F_5 ( V_7 -> V_37 . V_50 ) ;
V_7 -> V_41 = 0 ;
V_7 -> V_30 = 0 ;
}
V_7 -> error = V_51 ;
V_7 -> V_33 = V_32 ;
V_7 -> V_31 = V_34 ;
V_7 -> V_28 = ( V_44 & V_52 ) ?
( V_42 | V_38 ) :
V_42 ;
V_7 -> V_41 += V_34 ;
if ( V_7 -> V_30 || V_34 < V_20 ) {
T_1 V_35 = V_20 -
V_7 -> V_30 ;
if ( V_34 < V_35 )
V_35 = V_34 ;
if ( V_35 ) {
memcpy ( & V_7 -> V_36 [ V_7 -> V_30 ] ,
V_32 , V_35 ) ;
V_7 -> V_30 += V_35 ;
V_7 -> V_33 = ( const void * )
( ( const char * ) V_32 + V_35 ) ;
V_7 -> V_31 = V_34 - V_35 ;
}
assert ( V_7 -> V_30 <= V_20 ) ;
if ( V_7 -> V_30 >= V_20 ) {
V_7 -> V_30 = 0 ;
V_7 -> V_37 . V_32 = V_7 -> V_36 ;
V_7 -> V_37 . V_34 = 1 ;
V_7 = (struct V_2 * )
F_9 ( & V_27 -> V_27 , & V_7 -> V_37 ) ;
}
}
return F_8 ( V_27 , V_7 ) ;
}
static struct V_2 * F_15 ( struct V_26 * V_27 )
{
struct V_2 * V_7 ;
while ( 1 ) {
V_7 = (struct V_2 * ) F_16 ( & V_27 -> V_27 ) ;
if ( ! V_7 )
return NULL ;
V_7 = F_8 ( V_27 , V_7 ) ;
if ( V_7 )
return V_7 ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_53 = F_18 ( V_5 ) ;
F_19 ( V_53 ) ;
V_53 -> V_37 . V_50 [ 0 ] = V_14 ;
V_53 -> V_37 . V_50 [ 1 ] = V_15 ;
V_53 -> V_37 . V_50 [ 2 ] = V_16 ;
V_53 -> V_37 . V_50 [ 3 ] = V_17 ;
V_53 -> V_37 . V_50 [ 4 ] = V_18 ;
V_53 -> V_41 = 0 ;
V_53 -> V_30 = 0 ;
V_53 -> V_28 = V_43 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_8 )
{
int V_22 ;
struct V_2 * V_53 = F_18 ( & V_8 -> V_5 ) ;
T_3 * V_54 = ( T_3 * ) V_8 -> V_55 ;
for ( V_22 = 0 ; V_22 < 5 ; ++ V_22 )
V_54 [ V_22 ] = F_21 ( V_53 -> V_37 . V_50 [ V_22 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * * V_56 ,
struct V_57 * V_58 , bool V_59 )
{
int V_9 = V_10 ;
int V_60 , V_61 = 0 ;
struct V_1 * V_8 = * V_56 ;
struct V_2 * V_62 ;
while ( ! ( V_8 -> V_9 & V_63 ) ) {
V_60 = F_23 ( & V_8 -> V_64 , 0 ) ;
if ( V_60 < 0 ) {
V_61 = V_60 ;
goto V_55;
}
if ( F_24 ( & V_8 -> V_64 ) ) {
V_8 -> V_9 |= V_63 ;
if ( V_8 -> V_9 & V_65 )
V_9 |= V_52 ;
}
V_62 = (struct V_2 * )
F_18 ( & V_8 -> V_5 ) ;
F_25 () ;
V_62 = F_14 ( V_58 -> V_27 , V_62 ,
V_8 -> V_64 . V_66 , V_60 , V_9 ) ;
if ( ! V_62 ) {
if ( V_59 )
V_62 = F_15 ( V_58 -> V_27 ) ;
}
F_26 () ;
if ( V_62 )
V_8 = F_1 ( V_62 ) ;
else {
V_8 = NULL ;
goto V_55;
}
}
if ( V_8 -> V_9 & V_65 )
F_20 ( V_8 ) ;
V_55:
* V_56 = V_8 ;
return V_61 ;
}
static int F_27 ( struct V_1 * V_8 ,
struct V_57 * V_58 ,
int V_61 )
{
struct V_4 * V_67 = F_3 ( V_8 ) ;
struct V_2 * V_62 ;
struct V_1 * V_68 ;
int V_69 ;
F_28 ( & V_58 -> V_70 ) ;
F_29 ( & V_8 -> V_71 ) ;
F_30 ( & V_58 -> V_70 ) ;
if ( F_31 () )
V_8 -> V_72 ( & V_67 -> V_73 , V_61 ) ;
else {
F_32 () ;
V_8 -> V_72 ( & V_67 -> V_73 , V_61 ) ;
F_33 () ;
}
V_62 = F_10 ( V_58 -> V_27 ) ;
while ( V_62 ) {
V_68 = F_1 ( V_62 ) ;
V_69 = F_22 ( & V_68 , V_58 , false ) ;
if ( V_68 ) {
F_28 ( & V_58 -> V_70 ) ;
F_29 ( & V_68 -> V_71 ) ;
F_30 ( & V_58 -> V_70 ) ;
V_67 = F_3 ( V_68 ) ;
if ( F_31 () )
V_68 -> V_72 ( & V_67 -> V_73 , V_69 ) ;
else {
F_32 () ;
V_68 -> V_72 ( & V_67 -> V_73 , V_69 ) ;
F_33 () ;
}
}
V_62 = F_10 ( V_58 -> V_27 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_8 ,
struct V_57 * V_58 )
{
unsigned long V_74 ;
unsigned long V_75 = F_35 ( V_76 ) ;
V_8 -> V_77 . V_78 = V_79 ;
V_8 -> V_77 . V_80 = V_58 -> V_81 ++ ;
V_74 = V_8 -> V_77 . V_78 + V_75 ;
V_8 -> V_77 . V_82 = V_74 ;
F_28 ( & V_58 -> V_70 ) ;
F_36 ( & V_8 -> V_71 , & V_58 -> V_83 ) ;
F_30 ( & V_58 -> V_70 ) ;
F_37 ( V_58 , V_75 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_57 * V_58 =
F_39 ( V_84 . V_85 ) ;
struct V_4 * V_67 = F_3 ( V_8 ) ;
struct V_2 * V_62 ;
int V_69 = 0 , V_60 ;
if ( V_8 -> V_77 . V_86 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_87;
}
F_4 ( V_8 , V_5 ) ;
V_60 = F_42 ( V_67 , & V_8 -> V_64 ) ;
if ( V_60 < 0 ) {
V_69 = V_60 ;
goto V_87;
}
if ( F_24 ( & V_8 -> V_64 ) )
V_8 -> V_9 |= V_63 ;
V_62 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_58 ) ;
F_25 () ;
V_62 = F_14 ( V_58 -> V_27 , V_62 , V_8 -> V_64 . V_66 ,
V_60 , V_10 ) ;
F_26 () ;
if ( ! V_62 )
return - V_88 ;
if ( V_62 -> error ) {
V_69 = V_62 -> error ;
V_8 = F_1 ( V_62 ) ;
goto V_87;
}
V_8 = F_1 ( V_62 ) ;
V_69 = F_22 ( & V_8 , V_58 , false ) ;
if ( ! V_8 )
return - V_88 ;
V_87:
F_27 ( V_8 , V_58 , V_69 ) ;
return V_69 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_57 * V_58 =
F_39 ( V_84 . V_85 ) ;
struct V_4 * V_67 = F_3 ( V_8 ) ;
struct V_2 * V_62 ;
int V_69 = 0 , V_9 = V_10 , V_60 ;
if ( V_8 -> V_77 . V_86 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_87;
}
F_4 ( V_8 , V_5 ) ;
V_60 = F_42 ( V_67 , & V_8 -> V_64 ) ;
if ( V_60 < 0 ) {
V_69 = V_60 ;
goto V_87;
}
if ( F_24 ( & V_8 -> V_64 ) ) {
V_8 -> V_9 |= V_63 ;
V_9 = V_52 ;
}
V_8 -> V_9 |= V_65 ;
V_62 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_58 ) ;
F_25 () ;
V_62 = F_14 ( V_58 -> V_27 , V_62 , V_8 -> V_64 . V_66 ,
V_60 , V_9 ) ;
F_26 () ;
if ( ! V_62 )
return - V_88 ;
if ( V_62 -> error ) {
V_69 = V_62 -> error ;
goto V_87;
}
V_8 = F_1 ( V_62 ) ;
V_69 = F_22 ( & V_8 , V_58 , false ) ;
if ( ! V_8 )
return - V_88 ;
V_87:
F_27 ( V_8 , V_58 , V_69 ) ;
return V_69 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 , V_5 ) ;
struct V_57 * V_58 =
F_39 ( V_84 . V_85 ) ;
struct V_2 * V_62 ;
int V_69 = 0 ;
T_4 V_66 ;
if ( V_8 -> V_77 . V_86 != F_40 () ) {
F_41 ( L_1 ) ;
goto V_87;
}
F_4 ( V_8 , V_5 ) ;
V_8 -> V_9 |= V_63 | V_65 ;
V_62 = (struct V_2 * ) F_18 ( V_5 ) ;
F_34 ( V_8 , V_58 ) ;
F_25 () ;
V_62 = F_14 ( V_58 -> V_27 , V_62 , & V_66 , 0 ,
V_52 ) ;
F_26 () ;
if ( ! V_62 )
return - V_88 ;
if ( V_62 -> error ) {
V_69 = V_62 -> error ;
V_8 = F_1 ( V_62 ) ;
goto V_87;
}
V_8 = F_1 ( V_62 ) ;
V_69 = F_22 ( & V_8 , V_58 , false ) ;
if ( ! V_8 )
return - V_88 ;
V_87:
F_27 ( V_8 , V_58 , V_69 ) ;
return V_69 ;
}
static int F_45 ( struct V_4 * V_5 , void * V_55 )
{
struct V_2 * V_53 = F_18 ( V_5 ) ;
memcpy ( V_55 , V_53 , sizeof( * V_53 ) ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , const void * V_89 )
{
struct V_2 * V_53 = F_18 ( V_5 ) ;
memcpy ( V_53 , V_89 , sizeof( * V_53 ) ) ;
return 0 ;
}
static int F_47 ( struct V_90 * V_91 )
{
struct V_92 * V_93 ;
struct V_94 * V_7 = F_48 ( V_91 ) ;
struct V_95 * V_96 ;
V_93 = F_49 ( L_2 ,
V_97 ,
V_97 ) ;
if ( F_50 ( V_93 ) )
return F_51 ( V_93 ) ;
V_96 = F_52 ( & V_93 -> V_73 ) ;
V_96 -> V_98 = & V_84 ;
V_7 -> V_93 = V_93 ;
F_53 ( F_54 ( V_91 ) ,
sizeof( struct V_4 ) +
F_55 ( & V_93 -> V_73 ) ) ;
return 0 ;
}
static void F_56 ( struct V_90 * V_91 )
{
struct V_94 * V_7 = F_48 ( V_91 ) ;
F_57 ( V_7 -> V_93 ) ;
}
static int F_58 ( struct V_90 * V_91 )
{
F_53 ( F_54 ( V_91 ) ,
sizeof( struct V_4 ) +
sizeof( struct V_2 ) ) ;
return 0 ;
}
static void F_59 ( struct V_90 * V_91 )
{
struct V_94 * V_7 = F_48 ( V_91 ) ;
F_57 ( V_7 -> V_93 ) ;
}
static int F_60 ( struct V_4 * V_67 )
{
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_63 ( V_100 ) ;
}
static int F_64 ( struct V_4 * V_67 )
{
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_65 ( V_100 ) ;
}
static int F_66 ( struct V_4 * V_67 )
{
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_67 ( V_100 ) ;
}
static int F_68 ( struct V_4 * V_67 )
{
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_69 ( V_100 ) ;
}
static int F_70 ( struct V_4 * V_67 )
{
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_71 ( V_100 ) ;
}
static int F_72 ( struct V_4 * V_67 , void * V_55 )
{
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
return F_73 ( V_100 , V_55 ) ;
}
static int F_74 ( struct V_4 * V_67 , const void * V_89 )
{
struct V_4 * V_100 = F_18 ( V_67 ) ;
struct V_99 * V_91 = F_61 ( V_67 ) ;
struct V_94 * V_7 = F_52 ( V_91 ) ;
struct V_92 * V_93 = V_7 -> V_93 ;
struct V_99 * V_101 = F_75 ( V_93 ) ;
struct V_1 * V_8 ;
struct V_4 * V_5 ;
memcpy ( V_100 , V_67 , sizeof( * V_67 ) ) ;
F_62 ( V_100 , & V_93 -> V_73 ) ;
V_8 = F_18 ( V_100 ) ;
V_5 = & V_8 -> V_5 ;
F_62 ( V_5 , V_101 ) ;
F_76 ( V_5 , V_102 ,
V_8 -> V_72 , V_67 ) ;
return F_77 ( V_100 , V_89 ) ;
}
static unsigned long F_78 ( struct V_57 * V_58 )
{
struct V_1 * V_8 ;
unsigned long V_103 ;
unsigned long V_74 = 0 ;
struct V_2 * V_62 ;
V_103 = V_79 ;
while ( ! F_79 ( & V_58 -> V_83 ) ) {
V_8 = F_80 ( V_58 -> V_83 . V_104 ,
struct V_1 , V_71 ) ;
if ( F_81 ( V_103 , V_8 -> V_77 . V_82 ) )
break;
F_25 () ;
V_62 = (struct V_2 * )
F_15 ( V_58 -> V_27 ) ;
F_26 () ;
if ( ! V_62 ) {
F_41 ( L_3 ) ;
break;
}
V_8 = F_1 ( V_62 ) ;
F_22 ( & V_8 , V_58 , true ) ;
F_27 ( V_8 , V_58 , 0 ) ;
}
if ( ! F_79 ( & V_58 -> V_83 ) ) {
V_8 = F_80 ( V_58 -> V_83 . V_104 ,
struct V_1 , V_71 ) ;
V_74 = V_8 -> V_77 . V_82 ;
F_37 ( V_58 , F_82 ( V_74 ) ) ;
}
return V_74 ;
}
static int T_5 F_83 ( void )
{
int V_86 ;
int V_61 ;
struct V_57 * V_105 ;
if ( ! F_84 ( V_106 ) ||
! F_84 ( V_107 ) )
return - V_108 ;
V_84 . V_85 = F_85 ( struct V_57 ) ;
F_13 = V_109 ;
F_9 = V_110 ;
F_16 = V_111 ;
F_11 = V_112 ;
if ( ! V_84 . V_85 )
return - V_113 ;
F_86 (cpu) {
V_105 = F_87 ( V_84 . V_85 , V_86 ) ;
V_105 -> V_74 = 0 ;
V_105 -> V_81 = 0 ;
V_105 -> V_114 = false ;
F_88 ( & V_105 -> V_59 , V_115 ) ;
V_105 -> V_86 = V_86 ;
V_105 -> V_98 = & V_84 ;
V_105 -> V_27 = F_89 ( sizeof( struct V_26 ) ,
V_116 ) ;
if ( ! V_105 -> V_27 )
goto V_117;
F_12 ( V_105 -> V_27 ) ;
F_90 ( & V_105 -> V_83 ) ;
F_91 ( & V_105 -> V_70 ) ;
}
V_84 . V_118 = & F_78 ;
V_61 = F_92 ( & V_119 ) ;
if ( V_61 )
goto V_117;
V_61 = F_92 ( & V_120 ) ;
if ( V_61 )
goto V_121;
return 0 ;
V_121:
F_93 ( & V_119 ) ;
V_117:
F_86 (cpu) {
V_105 = F_87 ( V_84 . V_85 , V_86 ) ;
F_94 ( V_105 -> V_27 ) ;
}
F_95 ( V_84 . V_85 ) ;
return - V_108 ;
}
static void T_6 F_96 ( void )
{
int V_86 ;
struct V_57 * V_105 ;
F_93 ( & V_120 ) ;
F_93 ( & V_119 ) ;
F_86 (cpu) {
V_105 = F_87 ( V_84 . V_85 , V_86 ) ;
F_94 ( V_105 -> V_27 ) ;
}
F_95 ( V_84 . V_85 ) ;
}
