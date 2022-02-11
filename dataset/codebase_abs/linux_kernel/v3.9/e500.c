static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 = - 1 ;
V_3 = ++ ( F_2 ( V_5 ) ) ;
if ( V_3 < V_6 ) {
F_2 ( V_7 ) . V_2 [ V_3 ] = V_2 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = & F_2 ( V_7 ) . V_2 [ V_3 ] ;
V_4 = V_3 ;
}
F_3 ( V_3 > V_6 ) ;
return V_4 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_8 != 0 &&
F_2 ( V_7 ) . V_2 [ V_2 -> V_8 ] == V_2 &&
V_2 -> V_9 == & F_2 ( V_7 ) . V_2 [ V_2 -> V_8 ] )
return V_2 -> V_8 ;
return - 1 ;
}
static inline void F_5 ( void )
{
F_2 ( V_5 ) = 0 ;
memset ( & F_2 ( V_7 ) , 0 , sizeof( F_2 ( V_7 ) ) ) ;
}
static void * F_6 ( struct V_10 * V_11 )
{
V_11 -> V_12 = F_7 ( sizeof( struct V_13 ) , V_14 ) ;
return V_11 -> V_12 ;
}
static void F_8 ( struct V_10 * V_11 )
{
F_9 ( V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
}
static void F_10 ( struct V_10 * V_11 )
{
F_11 () ;
V_11 -> V_15 . V_16 . V_17 = F_12 ( V_11 ,
F_13 ( & V_11 -> V_15 ) ,
F_14 ( & V_11 -> V_15 ) ,
F_15 ( & V_11 -> V_15 ) , 1 ) ;
V_11 -> V_15 . V_16 . V_18 = F_12 ( V_11 ,
F_13 ( & V_11 -> V_15 ) , 0 ,
F_15 ( & V_11 -> V_15 ) , 1 ) ;
F_16 () ;
}
static void F_17 ( struct V_10 * V_11 )
{
memset ( V_11 -> V_12 , 0 , sizeof( struct V_13 ) ) ;
F_10 ( V_11 ) ;
}
static inline void F_18 (
struct V_10 * V_11 ,
int V_19 , int V_20 , int V_21 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
F_19 ( V_19 >= 2 ) ;
F_19 ( V_20 >= V_6 ) ;
F_19 ( V_21 >= 2 ) ;
V_12 -> V_1 [ V_19 ] [ V_20 ] [ V_21 ] . V_8 = 0 ;
V_12 -> V_1 [ V_19 ] [ V_20 ] [ V_21 ] . V_9 = NULL ;
F_10 ( V_11 ) ;
}
unsigned int F_12 ( struct V_10 * V_11 ,
unsigned int V_19 , unsigned int V_22 ,
unsigned int V_21 , int V_23 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
int V_3 ;
F_19 ( V_19 >= 2 ) ;
F_19 ( V_22 >= V_6 ) ;
F_19 ( V_21 >= 2 ) ;
V_3 = F_4 ( & V_12 -> V_1 [ V_19 ] [ V_22 ] [ V_21 ] ) ;
while ( V_3 <= 0 ) {
V_3 = F_1 ( & V_12 -> V_1 [ V_19 ] [ V_22 ] [ V_21 ] ) ;
if ( V_3 <= 0 ) {
F_20 () ;
F_5 () ;
}
if ( ! V_23 )
F_10 ( V_11 ) ;
}
return V_3 ;
}
unsigned int F_21 ( struct V_24 * V_15 ,
struct V_25 * V_26 )
{
return F_12 ( F_22 ( V_15 ) , F_23 ( V_26 ) ,
F_24 ( V_26 ) , F_15 ( V_15 ) , 0 ) ;
}
void F_25 ( struct V_24 * V_15 , T_1 V_20 )
{
struct V_10 * V_11 = F_22 ( V_15 ) ;
if ( V_15 -> V_16 . V_20 != V_20 ) {
V_11 -> V_20 [ 0 ] = V_15 -> V_16 . V_20 = V_20 ;
F_10 ( V_11 ) ;
}
}
void F_26 ( struct V_10 * V_11 ,
struct V_25 * V_26 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
unsigned int V_21 , V_27 , V_28 , V_20 ;
T_1 V_8 , V_29 ;
unsigned long V_30 ;
V_28 = F_23 ( V_26 ) ;
V_27 = F_24 ( V_26 ) ;
F_11 () ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_20 = F_4 ( & V_12 -> V_1 [ V_28 ] [ V_27 ] [ V_21 ] ) ;
if ( V_20 <= 0 ) {
F_18 ( V_11 , V_28 , V_27 , V_21 ) ;
continue;
}
V_8 = ( V_20 << V_31 ) | V_32 ;
V_29 = F_27 ( V_26 ) ;
F_28 ( V_30 ) ;
F_29 ( V_33 , V_8 ) ;
asm volatile("tlbsx 0, %[eaddr]" : : [eaddr] "r" (eaddr));
V_8 = F_30 ( V_34 ) ;
if ( V_8 & V_35 ) {
F_29 ( V_34 , V_8 & ~ V_35 ) ;
asm volatile("tlbwe");
}
F_31 ( V_30 ) ;
}
F_16 () ;
}
void F_32 ( struct V_10 * V_11 )
{
F_17 ( V_11 ) ;
}
void F_33 ( struct V_24 * V_15 , T_1 V_36 )
{
F_10 ( F_22 ( V_15 ) ) ;
}
void F_34 ( struct V_24 * V_15 )
{
}
void F_35 ( struct V_24 * V_15 )
{
}
void F_36 ( struct V_24 * V_15 , int V_37 )
{
F_37 ( V_15 , V_37 ) ;
F_10 ( F_22 ( V_15 ) ) ;
}
void F_38 ( struct V_24 * V_15 )
{
#ifdef F_39
if ( V_15 -> V_16 . V_38 & V_39 )
F_40 ( V_15 ) ;
#endif
F_41 ( V_15 ) ;
}
int F_42 ( void )
{
int V_40 ;
if ( strcmp ( V_41 -> V_42 , L_1 ) == 0 )
V_40 = 0 ;
else
V_40 = - V_43 ;
return V_40 ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_25 * V_44 ;
V_44 = F_44 ( V_11 , 1 , 0 ) ;
V_44 -> V_45 = V_35 | F_45 ( V_46 ) ;
V_44 -> V_47 = 0 ;
V_44 -> V_48 = V_49 ;
V_44 = F_44 ( V_11 , 1 , 1 ) ;
V_44 -> V_45 = V_35 | F_45 ( V_50 ) ;
V_44 -> V_47 = ( 0xe0004500 & 0xFFFFF000 ) | V_51 | V_52 ;
V_44 -> V_48 = ( 0xe0004500 & 0xFFFFF000 ) | V_49 ;
}
int F_46 ( struct V_24 * V_15 )
{
struct V_10 * V_11 = F_22 ( V_15 ) ;
F_43 ( V_11 ) ;
V_15 -> V_16 . V_53 = F_30 ( V_54 ) ;
V_11 -> V_55 = F_30 ( V_56 ) ;
V_15 -> V_16 . V_57 = V_58 ;
return 0 ;
}
void F_47 ( struct V_24 * V_15 , struct V_59 * V_60 )
{
struct V_10 * V_11 = F_22 ( V_15 ) ;
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
F_48 ( V_15 , V_60 ) ;
F_49 ( V_15 , V_60 ) ;
}
int F_50 ( struct V_24 * V_15 , struct V_59 * V_60 )
{
struct V_10 * V_11 = F_22 ( V_15 ) ;
int V_4 ;
if ( V_60 -> V_61 . V_62 . V_67 == V_68 ) {
V_11 -> V_55 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_55 ;
V_11 -> V_71 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_71 ;
V_11 -> V_72 = V_60 -> V_61 . V_62 . V_69 . V_70 . V_72 ;
}
V_4 = F_51 ( V_15 , V_60 ) ;
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
return F_52 ( V_15 , V_60 ) ;
}
struct V_24 * F_53 ( struct V_80 * V_80 , unsigned int V_1 )
{
struct V_10 * V_11 ;
struct V_24 * V_15 ;
int V_81 ;
V_11 = F_54 ( V_82 , V_14 ) ;
if ( ! V_11 ) {
V_81 = - V_83 ;
goto V_84;
}
V_15 = & V_11 -> V_15 ;
V_81 = F_55 ( V_15 , V_80 , V_1 ) ;
if ( V_81 )
goto V_85;
if ( F_6 ( V_11 ) == NULL )
goto V_86;
V_81 = F_56 ( V_11 ) ;
if ( V_81 )
goto V_87;
V_15 -> V_16 . V_88 = ( void * ) F_57 ( V_14 | V_89 ) ;
if ( ! V_15 -> V_16 . V_88 )
goto V_90;
return V_15 ;
V_90:
F_58 ( V_11 ) ;
V_87:
F_8 ( V_11 ) ;
V_86:
F_59 ( V_15 ) ;
V_85:
F_60 ( V_82 , V_11 ) ;
V_84:
return F_61 ( V_81 ) ;
}
void F_62 ( struct V_24 * V_15 )
{
struct V_10 * V_11 = F_22 ( V_15 ) ;
F_63 ( ( unsigned long ) V_15 -> V_16 . V_88 ) ;
F_58 ( V_11 ) ;
F_8 ( V_11 ) ;
F_59 ( V_15 ) ;
F_60 ( V_82 , V_11 ) ;
}
int F_64 ( struct V_80 * V_80 )
{
return 0 ;
}
void F_65 ( struct V_80 * V_80 )
{
}
static int T_2 F_66 ( void )
{
int V_40 , V_91 ;
unsigned long V_74 [ 3 ] ;
unsigned long * V_92 = & V_93 [ 16 ] ;
unsigned long V_94 ;
unsigned long V_95 = 0 ;
V_40 = F_42 () ;
if ( V_40 )
return V_40 ;
V_40 = F_67 () ;
if ( V_40 )
return V_40 ;
V_74 [ 0 ] = F_30 ( V_96 ) ;
V_74 [ 1 ] = F_30 ( V_97 ) ;
V_74 [ 2 ] = F_30 ( V_98 ) ;
for ( V_91 = 0 ; V_91 < 3 ; V_91 ++ ) {
if ( V_74 [ V_91 ] > V_74 [ V_95 ] )
V_95 = V_91 ;
V_94 = V_92 [ V_91 + 1 ] - V_92 [ V_91 ] ;
memcpy ( ( void * ) V_99 + V_74 [ V_91 ] ,
( void * ) V_92 [ V_91 ] , V_94 ) ;
}
V_94 = V_92 [ V_95 + 1 ] - V_92 [ V_95 ] ;
F_68 ( V_99 , V_99 +
V_74 [ V_95 ] + V_94 ) ;
return F_69 ( NULL , sizeof( struct V_10 ) , 0 , V_100 ) ;
}
static void T_3 F_70 ( void )
{
F_71 () ;
}
