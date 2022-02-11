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
* F_10 ( struct V_46 * V_47 )
{
struct V_28 * V_29 ;
struct V_2 * V_7 ;
unsigned long V_48 ;
V_29 = V_47 -> V_29 ;
F_11 ( & V_47 -> V_49 , V_48 ) ;
V_7 = (struct V_2 * )
F_12 ( & V_29 -> V_29 ) ;
V_7 = F_8 ( V_29 , V_7 ) ;
F_13 ( & V_47 -> V_49 , V_48 ) ;
return V_7 ;
}
static void F_14 ( struct V_28 * V_29 )
{
F_15 ( & V_29 -> V_29 ) ;
}
static struct V_2
* F_16 ( struct V_46 * V_47 ,
struct V_2 * V_7 ,
const void * V_34 ,
T_2 V_36 ,
int V_48 )
{
struct V_28 * V_29 ;
unsigned long V_50 ;
V_29 = V_47 -> V_29 ;
F_11 ( & V_47 -> V_49 , V_50 ) ;
if ( V_48 & ( ~ V_51 ) ) {
V_7 -> error = V_52 ;
goto V_53;
}
if ( V_7 -> V_30 & V_44 ) {
V_7 -> error = V_54 ;
goto V_53;
}
if ( ( V_7 -> V_30 & V_31 ) && ! ( V_48 & V_55 ) ) {
V_7 -> error = V_56 ;
goto V_53;
}
if ( V_48 & V_55 ) {
F_5 ( V_7 -> V_39 . V_57 ) ;
V_7 -> V_43 = 0 ;
V_7 -> V_32 = 0 ;
}
V_7 -> error = V_58 ;
V_7 -> V_35 = V_34 ;
V_7 -> V_33 = V_36 ;
V_7 -> V_30 = ( V_48 & V_59 ) ?
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
V_7 = F_8 ( V_29 , V_7 ) ;
V_53:
F_13 ( & V_47 -> V_49 , V_50 ) ;
return V_7 ;
}
static struct V_2 * F_17 ( struct V_46 * V_47 )
{
struct V_28 * V_29 ;
struct V_2 * V_7 ;
unsigned long V_48 ;
V_29 = V_47 -> V_29 ;
F_11 ( & V_47 -> V_49 , V_48 ) ;
while ( 1 ) {
V_7 = (struct V_2 * )
F_18 ( & V_29 -> V_29 ) ;
if ( ! V_7 )
break;
V_7 = F_8 ( V_29 , V_7 ) ;
if ( V_7 )
break;
}
F_13 ( & V_47 -> V_49 , V_48 ) ;
return V_7 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_60 = F_20 ( V_5 ) ;
F_21 ( V_60 ) ;
V_60 -> V_39 . V_57 [ 0 ] = V_14 ;
V_60 -> V_39 . V_57 [ 1 ] = V_15 ;
V_60 -> V_39 . V_57 [ 2 ] = V_16 ;
V_60 -> V_39 . V_57 [ 3 ] = V_17 ;
V_60 -> V_39 . V_57 [ 4 ] = V_18 ;
V_60 -> V_39 . V_57 [ 5 ] = V_19 ;
V_60 -> V_39 . V_57 [ 6 ] = V_20 ;
V_60 -> V_39 . V_57 [ 7 ] = V_21 ;
V_60 -> V_43 = 0 ;
V_60 -> V_32 = 0 ;
V_60 -> V_30 = V_45 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_8 )
{
int V_25 ;
struct V_2 * V_60 = F_20 ( & V_8 -> V_5 ) ;
T_4 * V_61 = ( T_4 * ) V_8 -> V_62 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 )
V_61 [ V_25 ] = F_7 ( V_60 -> V_39 . V_57 [ V_25 ] ) ;
return 0 ;
}
static int F_23 ( struct V_1 * * V_63 ,
struct V_46 * V_47 , bool V_64 )
{
int V_9 = V_10 ;
int V_65 , V_66 = 0 ;
struct V_1 * V_8 = * V_63 ;
struct V_2 * V_67 ;
while ( ! ( V_8 -> V_9 & V_68 ) ) {
V_65 = F_24 ( & V_8 -> V_69 , 0 ) ;
if ( V_65 < 0 ) {
V_66 = V_65 ;
goto V_62;
}
if ( F_25 ( & V_8 -> V_69 ) ) {
V_8 -> V_9 |= V_68 ;
if ( V_8 -> V_9 & V_70 )
V_9 |= V_59 ;
}
V_67 = (struct V_2 * )
F_20 ( & V_8 -> V_5 ) ;
F_26 () ;
V_67 = F_16 ( V_47 , V_67 ,
V_8 -> V_69 . V_71 , V_65 , V_9 ) ;
if ( ! V_67 ) {
if ( V_64 )
V_67 = F_17 ( V_47 ) ;
}
F_27 () ;
if ( V_67 )
V_8 = F_1 ( V_67 ) ;
else {
V_8 = NULL ;
goto V_62;
}
}
if ( V_8 -> V_9 & V_70 )
F_22 ( V_8 ) ;
V_62:
* V_63 = V_8 ;
return V_66 ;
}
static int F_28 ( struct V_1 * V_8 ,
struct V_46 * V_47 ,
int V_66 )
{
struct V_4 * V_72 = F_3 ( V_8 ) ;
struct V_2 * V_67 ;
struct V_1 * V_73 ;
int V_74 ;
unsigned long V_48 ;
F_11 ( & V_47 -> V_49 , V_48 ) ;
F_29 ( & V_8 -> V_75 ) ;
F_13 ( & V_47 -> V_49 , V_48 ) ;
if ( F_30 () )
V_8 -> V_76 ( & V_72 -> V_77 , V_66 ) ;
else {
F_31 () ;
V_8 -> V_76 ( & V_72 -> V_77 , V_66 ) ;
F_32 () ;
}
V_67 = F_10 ( V_47 ) ;
while ( V_67 ) {
V_73 = F_1 ( V_67 ) ;
V_74 = F_23 ( & V_73 , V_47 , false ) ;
if ( V_73 ) {
F_11 ( & V_47 -> V_49 , V_48 ) ;
F_29 ( & V_73 -> V_75 ) ;
F_13 ( & V_47 -> V_49 , V_48 ) ;
V_72 = F_3 ( V_73 ) ;
if ( F_30 () )
V_73 -> V_76 ( & V_72 -> V_77 , V_74 ) ;
else {
F_31 () ;
V_73 -> V_76 ( & V_72 -> V_77 , V_74 ) ;
F_32 () ;
}
}
V_67 = F_10 ( V_47 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_8 ,
struct V_46 * V_47 )
{
unsigned long V_78 ;
unsigned long V_79 = F_34 ( V_80 ) ;
unsigned long V_48 ;
V_8 -> V_81 . V_82 = V_83 ;
V_8 -> V_81 . V_84 = V_47 -> V_85 ++ ;
V_78 = V_8 -> V_81 . V_82 + V_79 ;
V_8 -> V_81 . V_86 = V_78 ;
F_11 ( & V_47 -> V_49 , V_48 ) ;
F_35 ( & V_8 -> V_75 , & V_47 -> V_87 ) ;
F_13 ( & V_47 -> V_49 , V_48 ) ;
F_36 ( V_47 , V_79 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_46 * V_47 =
F_38 ( V_88 . V_89 ) ;
struct V_4 * V_72 = F_3 ( V_8 ) ;
struct V_2 * V_67 ;
int V_74 = 0 , V_65 ;
if ( V_8 -> V_81 . V_90 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_91;
}
F_4 ( V_8 , V_5 ) ;
V_65 = F_41 ( V_72 , & V_8 -> V_69 ) ;
if ( V_65 < 0 ) {
V_74 = V_65 ;
goto V_91;
}
if ( F_25 ( & V_8 -> V_69 ) )
V_8 -> V_9 |= V_68 ;
V_67 = (struct V_2 * ) F_20 ( V_5 ) ;
F_33 ( V_8 , V_47 ) ;
F_26 () ;
V_67 = F_16 ( V_47 , V_67 , V_8 -> V_69 . V_71 ,
V_65 , V_10 ) ;
F_27 () ;
if ( ! V_67 )
return - V_92 ;
if ( V_67 -> error ) {
V_74 = V_67 -> error ;
V_8 = F_1 ( V_67 ) ;
goto V_91;
}
V_8 = F_1 ( V_67 ) ;
V_74 = F_23 ( & V_8 , V_47 , false ) ;
if ( ! V_8 )
return - V_92 ;
V_91:
F_28 ( V_8 , V_47 , V_74 ) ;
return V_74 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_46 * V_47 =
F_38 ( V_88 . V_89 ) ;
struct V_4 * V_72 = F_3 ( V_8 ) ;
struct V_2 * V_67 ;
int V_74 = 0 , V_9 = V_10 , V_65 ;
if ( V_8 -> V_81 . V_90 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_91;
}
F_4 ( V_8 , V_5 ) ;
V_65 = F_41 ( V_72 , & V_8 -> V_69 ) ;
if ( V_65 < 0 ) {
V_74 = V_65 ;
goto V_91;
}
if ( F_25 ( & V_8 -> V_69 ) ) {
V_8 -> V_9 |= V_68 ;
V_9 = V_59 ;
}
V_8 -> V_9 |= V_70 ;
V_67 = (struct V_2 * ) F_20 ( V_5 ) ;
F_33 ( V_8 , V_47 ) ;
F_26 () ;
V_67 = F_16 ( V_47 , V_67 , V_8 -> V_69 . V_71 ,
V_65 , V_9 ) ;
F_27 () ;
if ( ! V_67 )
return - V_92 ;
if ( V_67 -> error ) {
V_74 = V_67 -> error ;
goto V_91;
}
V_8 = F_1 ( V_67 ) ;
V_74 = F_23 ( & V_8 , V_47 , false ) ;
if ( ! V_8 )
return - V_92 ;
V_91:
F_28 ( V_8 , V_47 , V_74 ) ;
return V_74 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_1 * V_8 =
F_2 ( V_5 , struct V_1 ,
V_5 ) ;
struct V_46 * V_47 =
F_38 ( V_88 . V_89 ) ;
struct V_2 * V_67 ;
int V_74 = 0 ;
T_5 V_71 ;
if ( V_8 -> V_81 . V_90 != F_39 () ) {
F_40 ( L_1 ) ;
goto V_91;
}
F_4 ( V_8 , V_5 ) ;
V_8 -> V_9 |= V_68 | V_70 ;
V_67 = (struct V_2 * ) F_20 ( V_5 ) ;
F_33 ( V_8 , V_47 ) ;
F_26 () ;
V_67 = F_16 ( V_47 , V_67 , & V_71 , 0 , V_59 ) ;
F_27 () ;
if ( ! V_67 )
return - V_92 ;
if ( V_67 -> error ) {
V_74 = V_67 -> error ;
V_8 = F_1 ( V_67 ) ;
goto V_91;
}
V_8 = F_1 ( V_67 ) ;
V_74 = F_23 ( & V_8 , V_47 , false ) ;
if ( ! V_8 )
return - V_92 ;
V_91:
F_28 ( V_8 , V_47 , V_74 ) ;
return V_74 ;
}
static int F_44 ( struct V_4 * V_5 , void * V_62 )
{
struct V_2 * V_60 = F_20 ( V_5 ) ;
memcpy ( V_62 , V_60 , sizeof( * V_60 ) ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 , const void * V_93 )
{
struct V_2 * V_60 = F_20 ( V_5 ) ;
memcpy ( V_60 , V_93 , sizeof( * V_60 ) ) ;
return 0 ;
}
static int F_46 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_98 * V_7 = F_47 ( V_95 ) ;
struct V_99 * V_100 ;
V_97 = F_48 ( L_2 ,
V_101 ,
V_101 ) ;
if ( F_49 ( V_97 ) )
return F_50 ( V_97 ) ;
V_100 = F_51 ( & V_97 -> V_77 ) ;
V_100 -> V_102 = & V_88 ;
V_7 -> V_97 = V_97 ;
F_52 ( F_53 ( V_95 ) ,
sizeof( struct V_4 ) +
F_54 ( & V_97 -> V_77 ) ) ;
return 0 ;
}
static void F_55 ( struct V_94 * V_95 )
{
struct V_98 * V_7 = F_47 ( V_95 ) ;
F_56 ( V_7 -> V_97 ) ;
}
static int F_57 ( struct V_94 * V_95 )
{
F_52 ( F_53 ( V_95 ) ,
sizeof( struct V_4 ) +
sizeof( struct V_2 ) ) ;
return 0 ;
}
static void F_58 ( struct V_94 * V_95 )
{
struct V_98 * V_7 = F_47 ( V_95 ) ;
F_56 ( V_7 -> V_97 ) ;
}
static int F_59 ( struct V_4 * V_72 )
{
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_62 ( V_104 ) ;
}
static int F_63 ( struct V_4 * V_72 )
{
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_64 ( V_104 ) ;
}
static int F_65 ( struct V_4 * V_72 )
{
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_66 ( V_104 ) ;
}
static int F_67 ( struct V_4 * V_72 )
{
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_68 ( V_104 ) ;
}
static int F_69 ( struct V_4 * V_72 )
{
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_70 ( V_104 ) ;
}
static int F_71 ( struct V_4 * V_72 , void * V_62 )
{
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
return F_72 ( V_104 , V_62 ) ;
}
static int F_73 ( struct V_4 * V_72 , const void * V_93 )
{
struct V_4 * V_104 = F_20 ( V_72 ) ;
struct V_103 * V_95 = F_60 ( V_72 ) ;
struct V_98 * V_7 = F_51 ( V_95 ) ;
struct V_96 * V_97 = V_7 -> V_97 ;
struct V_103 * V_105 = F_74 ( V_97 ) ;
struct V_1 * V_8 ;
struct V_4 * V_5 ;
memcpy ( V_104 , V_72 , sizeof( * V_72 ) ) ;
F_61 ( V_104 , & V_97 -> V_77 ) ;
V_8 = F_20 ( V_104 ) ;
V_5 = & V_8 -> V_5 ;
F_61 ( V_5 , V_105 ) ;
F_75 ( V_5 , V_106 ,
V_8 -> V_76 , V_72 ) ;
return F_76 ( V_104 , V_93 ) ;
}
static unsigned long F_77 ( struct V_46 * V_47 )
{
struct V_1 * V_8 ;
unsigned long V_107 ;
unsigned long V_78 = 0 ;
struct V_2 * V_67 ;
V_107 = V_83 ;
while ( ! F_78 ( & V_47 -> V_87 ) ) {
V_8 = F_79 ( V_47 -> V_87 . V_108 ,
struct V_1 , V_75 ) ;
if time_before( V_107 , V_8 -> V_81 . V_86 )
break;
F_26 () ;
V_67 = (struct V_2 * )
F_17 ( V_47 ) ;
F_27 () ;
if ( ! V_67 ) {
F_40 ( L_3
L_4 ) ;
break;
}
V_8 = F_1 ( V_67 ) ;
F_23 ( & V_8 , V_47 , true ) ;
F_28 ( V_8 , V_47 , 0 ) ;
}
if ( ! F_78 ( & V_47 -> V_87 ) ) {
V_8 = F_79 ( V_47 -> V_87 . V_108 ,
struct V_1 , V_75 ) ;
V_78 = V_8 -> V_81 . V_86 ;
F_36 ( V_47 , F_80 ( V_78 ) ) ;
}
return V_78 ;
}
static int T_6 F_81 ( void )
{
int V_90 ;
int V_66 ;
struct V_46 * V_109 ;
if ( ! F_82 ( V_110 ) ||
! F_82 ( V_111 ) )
return - V_112 ;
V_88 . V_89 =
F_83 ( struct V_46 ) ;
F_15 = V_113 ;
F_9 = V_114 ;
F_18 = V_115 ;
F_12 = V_116 ;
if ( ! V_88 . V_89 )
return - V_117 ;
F_84 (cpu) {
V_109 = F_85 ( V_88 . V_89 , V_90 ) ;
V_109 -> V_78 = 0 ;
V_109 -> V_85 = 0 ;
V_109 -> V_118 = false ;
F_86 ( & V_109 -> V_64 , V_119 ) ;
V_109 -> V_90 = V_90 ;
V_109 -> V_102 = & V_88 ;
V_109 -> V_29 = F_87 ( sizeof( struct V_28 ) ,
V_120 ) ;
if ( ! V_109 -> V_29 )
goto V_121;
F_14 ( V_109 -> V_29 ) ;
F_88 ( & V_109 -> V_87 ) ;
F_89 ( & V_109 -> V_49 ) ;
}
V_88 . V_122 = & F_77 ;
V_66 = F_90 ( & V_123 ) ;
if ( V_66 )
goto V_121;
V_66 = F_90 ( & V_124 ) ;
if ( V_66 )
goto V_125;
return 0 ;
V_125:
F_91 ( & V_123 ) ;
V_121:
F_84 (cpu) {
V_109 = F_85 ( V_88 . V_89 , V_90 ) ;
F_92 ( V_109 -> V_29 ) ;
}
F_93 ( V_88 . V_89 ) ;
return - V_112 ;
}
static void T_7 F_94 ( void )
{
int V_90 ;
struct V_46 * V_109 ;
F_91 ( & V_124 ) ;
F_91 ( & V_123 ) ;
F_84 (cpu) {
V_109 = F_85 ( V_88 . V_89 , V_90 ) ;
F_92 ( V_109 -> V_29 ) ;
}
F_93 ( V_88 . V_89 ) ;
}
