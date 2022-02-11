static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 = - 1 ;
V_3 = F_2 ( V_5 ) ;
if ( V_3 < V_6 ) {
F_3 ( V_7 . V_2 [ V_3 ] , V_2 ) ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = F_4 ( & V_7 . V_2 [ V_3 ] ) ;
V_4 = V_3 ;
}
F_5 ( V_3 > V_6 ) ;
return V_4 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_8 != 0 &&
F_7 ( V_7 . V_2 [ V_2 -> V_8 ] ) == V_2 &&
V_2 -> V_9 == F_4 ( & V_7 . V_2 [ V_2 -> V_8 ] ) )
return V_2 -> V_8 ;
return - 1 ;
}
static inline void F_8 ( void )
{
F_3 ( V_5 , 0 ) ;
memset ( F_4 ( & V_7 ) , 0 , sizeof( V_7 ) ) ;
}
static void * F_9 ( struct V_10 * V_11 )
{
V_11 -> V_12 = F_10 ( sizeof( struct V_13 ) , V_14 ) ;
return V_11 -> V_12 ;
}
static void F_11 ( struct V_10 * V_11 )
{
F_12 ( V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 () ;
V_11 -> V_15 . V_16 . V_17 = F_15 ( V_11 ,
F_16 ( & V_11 -> V_15 ) ,
F_17 ( & V_11 -> V_15 ) ,
F_18 ( & V_11 -> V_15 ) , 1 ) ;
V_11 -> V_15 . V_16 . V_18 = F_15 ( V_11 ,
F_16 ( & V_11 -> V_15 ) , 0 ,
F_18 ( & V_11 -> V_15 ) , 1 ) ;
F_19 () ;
}
static void F_20 ( struct V_10 * V_11 )
{
memset ( V_11 -> V_12 , 0 , sizeof( struct V_13 ) ) ;
F_13 ( V_11 ) ;
}
static inline void F_21 (
struct V_10 * V_11 ,
int V_19 , int V_20 , int V_21 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
F_22 ( V_19 >= 2 ) ;
F_22 ( V_20 >= V_6 ) ;
F_22 ( V_21 >= 2 ) ;
V_12 -> V_1 [ V_19 ] [ V_20 ] [ V_21 ] . V_8 = 0 ;
V_12 -> V_1 [ V_19 ] [ V_20 ] [ V_21 ] . V_9 = NULL ;
F_13 ( V_11 ) ;
}
unsigned int F_15 ( struct V_10 * V_11 ,
unsigned int V_19 , unsigned int V_22 ,
unsigned int V_21 , int V_23 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
int V_3 ;
F_22 ( V_19 >= 2 ) ;
F_22 ( V_22 >= V_6 ) ;
F_22 ( V_21 >= 2 ) ;
V_3 = F_6 ( & V_12 -> V_1 [ V_19 ] [ V_22 ] [ V_21 ] ) ;
while ( V_3 <= 0 ) {
V_3 = F_1 ( & V_12 -> V_1 [ V_19 ] [ V_22 ] [ V_21 ] ) ;
if ( V_3 <= 0 ) {
F_23 () ;
F_8 () ;
}
if ( ! V_23 )
F_13 ( V_11 ) ;
}
return V_3 ;
}
unsigned int F_24 ( struct V_24 * V_15 ,
struct V_25 * V_26 )
{
return F_15 ( F_25 ( V_15 ) , F_26 ( V_26 ) ,
F_27 ( V_26 ) , F_18 ( V_15 ) , 0 ) ;
}
void F_28 ( struct V_24 * V_15 , T_1 V_20 )
{
struct V_10 * V_11 = F_25 ( V_15 ) ;
if ( V_15 -> V_16 . V_20 != V_20 ) {
V_11 -> V_20 [ 0 ] = V_15 -> V_16 . V_20 = V_20 ;
F_13 ( V_11 ) ;
}
}
void F_29 ( struct V_10 * V_11 ,
struct V_25 * V_26 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
unsigned int V_21 , V_27 , V_28 ;
int V_20 ;
T_1 V_8 , V_29 ;
unsigned long V_30 ;
V_28 = F_26 ( V_26 ) ;
V_27 = F_27 ( V_26 ) ;
F_14 () ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_20 = F_6 ( & V_12 -> V_1 [ V_28 ] [ V_27 ] [ V_21 ] ) ;
if ( V_20 <= 0 ) {
F_21 ( V_11 , V_28 , V_27 , V_21 ) ;
continue;
}
V_8 = ( V_20 << V_31 ) | V_32 ;
V_29 = F_30 ( V_26 ) ;
F_31 ( V_30 ) ;
F_32 ( V_33 , V_8 ) ;
asm volatile("tlbsx 0, %[eaddr]" : : [eaddr] "r" (eaddr));
V_8 = F_33 ( V_34 ) ;
if ( V_8 & V_35 ) {
F_32 ( V_34 , V_8 & ~ V_35 ) ;
asm volatile("tlbwe");
}
F_34 ( V_30 ) ;
}
F_19 () ;
}
void F_35 ( struct V_10 * V_11 )
{
F_20 ( V_11 ) ;
}
void F_36 ( struct V_24 * V_15 , T_1 V_36 )
{
F_13 ( F_25 ( V_15 ) ) ;
}
static void F_37 ( struct V_24 * V_15 , int V_37 )
{
F_38 ( V_15 , V_37 ) ;
F_13 ( F_25 ( V_15 ) ) ;
}
static void F_39 ( struct V_24 * V_15 )
{
#ifdef F_40
if ( V_15 -> V_16 . V_38 & V_39 )
F_41 ( V_15 ) ;
#endif
F_42 ( V_15 ) ;
}
int F_43 ( void )
{
int V_40 ;
if ( strcmp ( V_41 -> V_42 , L_1 ) == 0 )
V_40 = 0 ;
else
V_40 = - V_43 ;
return V_40 ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_25 * V_44 ;
V_44 = F_45 ( V_11 , 1 , 0 ) ;
V_44 -> V_45 = V_35 | F_46 ( V_46 ) ;
V_44 -> V_47 = 0 ;
V_44 -> V_48 = V_49 ;
V_44 = F_45 ( V_11 , 1 , 1 ) ;
V_44 -> V_45 = V_35 | F_46 ( V_50 ) ;
V_44 -> V_47 = ( 0xe0004500 & 0xFFFFF000 ) | V_51 | V_52 ;
V_44 -> V_48 = ( 0xe0004500 & 0xFFFFF000 ) | V_49 ;
}
int F_47 ( struct V_24 * V_15 )
{
struct V_10 * V_11 = F_25 ( V_15 ) ;
F_44 ( V_11 ) ;
V_15 -> V_16 . V_53 = F_33 ( V_54 ) ;
V_11 -> V_55 = F_33 ( V_56 ) ;
V_15 -> V_16 . V_57 = V_58 ;
return 0 ;
}
static int F_48 ( struct V_24 * V_15 ,
struct V_59 * V_60 )
{
struct V_10 * V_11 = F_25 ( V_15 ) ;
V_60 -> V_61 . V_62 . V_63 |= V_64 | V_65 |
V_66 ;
V_60 -> V_61 . V_62 . V_67 = V_68 ;
V_60 -> V_61 . V_62 . V_69 . V_70 . V_63 = 0 ;
V_60 -> V_61 . V_62 . V_69 . V_70 . V_55 = V_11 -> V_55 ;
V_60 -> V_61 . V_62 . V_69 . V_70 . V_71 = V_11 -> V_71 ;
V_60 -> V_61 . V_62 . V_69 . V_70 . V_72 = V_11 -> V_72 ;
V_60 -> V_61 . V_62 . V_73 [ 0 ] = V_15 -> V_16 . V_74 [ V_75 ] ;
V_60 -> V_61 . V_62 . V_73 [ 1 ] = V_15 -> V_16 . V_74 [ V_76 ] ;
V_60 -> V_61 . V_62 . V_73 [ 2 ] = V_15 -> V_16 . V_74 [ V_77 ] ;
V_60 -> V_61 . V_62 . V_73 [ 3 ] =
V_15 -> V_16 . V_74 [ V_78 ] ;
F_49 ( V_15 , V_60 ) ;
F_50 ( V_15 , V_60 ) ;
return 0 ;
}
static int F_51 ( struct V_24 * V_15 ,
struct V_59 * V_60 )
{
struct V_10 * V_11 = F_25 ( V_15 ) ;
int V_4 ;
if ( V_60 -> V_61 . V_62 . V_67 == V_68 ) {
V_11 -> V_55 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_55 ;
V_11 -> V_71 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_71 ;
V_11 -> V_72 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_72 ;
}
V_4 = F_52 ( V_15 , V_60 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_60 -> V_61 . V_62 . V_63 & V_79 ) )
return 0 ;
if ( V_60 -> V_61 . V_62 . V_63 & V_65 ) {
V_15 -> V_16 . V_74 [ V_75 ] =
V_60 -> V_61 . V_62 . V_73 [ 0 ] ;
V_15 -> V_16 . V_74 [ V_76 ] =
V_60 -> V_61 . V_62 . V_73 [ 1 ] ;
V_15 -> V_16 . V_74 [ V_77 ] =
V_60 -> V_61 . V_62 . V_73 [ 2 ] ;
}
if ( V_60 -> V_61 . V_62 . V_63 & V_66 ) {
V_15 -> V_16 . V_74 [ V_78 ] =
V_60 -> V_61 . V_62 . V_73 [ 3 ] ;
}
return F_53 ( V_15 , V_60 ) ;
}
static int F_54 ( struct V_24 * V_15 , T_2 V_1 ,
union V_80 * V_8 )
{
int V_40 = F_55 ( V_15 , V_1 , V_8 ) ;
return V_40 ;
}
static int F_56 ( struct V_24 * V_15 , T_2 V_1 ,
union V_80 * V_8 )
{
int V_40 = F_55 ( V_15 , V_1 , V_8 ) ;
return V_40 ;
}
static struct V_24 * F_57 ( struct V_81 * V_81 ,
unsigned int V_1 )
{
struct V_10 * V_11 ;
struct V_24 * V_15 ;
int V_82 ;
V_11 = F_58 ( V_83 , V_14 ) ;
if ( ! V_11 ) {
V_82 = - V_84 ;
goto V_85;
}
V_15 = & V_11 -> V_15 ;
V_82 = F_59 ( V_15 , V_81 , V_1 ) ;
if ( V_82 )
goto V_86;
if ( F_9 ( V_11 ) == NULL )
goto V_87;
V_82 = F_60 ( V_11 ) ;
if ( V_82 )
goto V_88;
V_15 -> V_16 . V_89 = ( void * ) F_61 ( V_14 | V_90 ) ;
if ( ! V_15 -> V_16 . V_89 )
goto V_91;
return V_15 ;
V_91:
F_62 ( V_11 ) ;
V_88:
F_11 ( V_11 ) ;
V_87:
F_63 ( V_15 ) ;
V_86:
F_64 ( V_83 , V_11 ) ;
V_85:
return F_65 ( V_82 ) ;
}
static void F_66 ( struct V_24 * V_15 )
{
struct V_10 * V_11 = F_25 ( V_15 ) ;
F_67 ( ( unsigned long ) V_15 -> V_16 . V_89 ) ;
F_62 ( V_11 ) ;
F_11 ( V_11 ) ;
F_63 ( V_15 ) ;
F_64 ( V_83 , V_11 ) ;
}
static int F_68 ( struct V_81 * V_81 )
{
return 0 ;
}
static void F_69 ( struct V_81 * V_81 )
{
}
static int T_3 F_70 ( void )
{
int V_40 , V_92 ;
unsigned long V_74 [ 3 ] ;
unsigned long * V_93 = & V_94 [ 16 ] ;
unsigned long V_95 ;
unsigned long V_96 = 0 ;
V_40 = F_43 () ;
if ( V_40 )
goto V_97;
V_40 = F_71 () ;
if ( V_40 )
goto V_97;
V_74 [ 0 ] = F_33 ( V_98 ) ;
V_74 [ 1 ] = F_33 ( V_99 ) ;
V_74 [ 2 ] = F_33 ( V_100 ) ;
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ ) {
if ( V_74 [ V_92 ] > V_74 [ V_96 ] )
V_96 = V_92 ;
V_95 = V_93 [ V_92 + 1 ] - V_93 [ V_92 ] ;
memcpy ( ( void * ) V_101 + V_74 [ V_92 ] ,
( void * ) V_93 [ V_92 ] , V_95 ) ;
}
V_95 = V_93 [ V_96 + 1 ] - V_93 [ V_96 ] ;
F_72 ( V_101 , V_101 +
V_74 [ V_96 ] + V_95 ) ;
V_40 = F_73 ( NULL , sizeof( struct V_10 ) , 0 , V_102 ) ;
if ( V_40 )
goto V_97;
V_103 . V_104 = V_102 ;
V_105 = & V_103 ;
V_97:
return V_40 ;
}
static void T_4 F_74 ( void )
{
V_105 = NULL ;
F_75 () ;
}
