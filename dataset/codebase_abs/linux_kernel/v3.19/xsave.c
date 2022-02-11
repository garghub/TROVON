void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 . V_7 -> V_8 ;
int V_9 = 0x2 ;
T_1 V_10 ;
if ( ! V_4 )
return;
V_10 = V_2 -> V_5 . V_6 . V_7 -> V_11 . V_12 . V_10 ;
if ( ( V_10 & V_13 ) == V_13 )
return;
if ( ! ( V_10 & V_14 ) ) {
V_4 -> V_15 = 0x37f ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = 0 ;
memset ( & V_4 -> V_21 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_10 & V_22 ) )
memset ( & V_4 -> V_23 [ 0 ] , 0 , 256 ) ;
V_10 = ( V_13 & ~ V_10 ) >> 2 ;
while ( V_10 ) {
if ( V_10 & 0x1 ) {
int V_24 = V_25 [ V_9 ] ;
int V_26 = V_27 [ V_9 ] ;
memcpy ( ( ( void * ) V_4 ) + V_24 ,
( ( void * ) V_28 ) + V_24 ,
V_26 ) ;
}
V_10 >>= 1 ;
V_9 ++ ;
}
}
static inline int F_2 ( struct V_3 T_2 * V_29 ,
void T_2 * V_30 ,
struct V_31 * V_32 )
{
int V_33 = sizeof( struct V_3 ) +
sizeof( struct V_34 ) ;
unsigned int V_35 ;
if ( F_3 ( V_32 , & V_29 -> V_36 [ 0 ] , sizeof( * V_32 ) ) )
return - 1 ;
if ( V_32 -> V_37 != V_38 ||
V_32 -> V_39 < V_33 ||
V_32 -> V_39 > V_39 ||
V_32 -> V_39 > V_32 -> V_40 )
return - 1 ;
if ( F_4 ( V_35 , ( V_41 T_2 * ) ( V_30 + V_32 -> V_39 ) )
|| V_35 != V_42 )
return - 1 ;
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , void T_2 * V_29 )
{
if ( F_6 () ) {
struct V_43 * V_11 = & V_2 -> V_5 . V_6 . V_7 -> V_11 ;
struct V_44 V_45 ;
struct V_46 T_2 * V_47 = V_29 ;
F_7 ( & V_45 , V_2 ) ;
if ( F_8 ( V_29 , & V_45 , sizeof( V_45 ) ) ||
F_9 ( V_11 -> V_48 . V_16 , & V_47 -> V_49 ) ||
F_9 ( V_50 , & V_47 -> V_51 ) )
return - 1 ;
} else {
struct V_52 T_2 * V_47 = V_29 ;
T_3 V_16 ;
if ( F_4 ( V_16 , & V_47 -> V_16 ) || F_9 ( V_16 , & V_47 -> V_49 ) )
return - 1 ;
}
return 0 ;
}
static inline int F_10 ( void T_2 * V_29 , int V_53 )
{
struct V_43 T_2 * V_54 = V_29 ;
struct V_31 * V_55 ;
T_3 V_10 ;
int V_56 ;
V_55 = V_53 ? & V_57 : & V_58 ;
V_56 = F_8 ( & V_54 -> V_48 . V_36 , V_55 , sizeof( * V_55 ) ) ;
if ( ! F_11 () )
return V_56 ;
V_56 |= F_9 ( V_42 , ( V_41 * ) ( V_29 + V_39 ) ) ;
V_56 |= F_4 ( V_10 , ( V_41 * ) & V_54 -> V_12 . V_10 ) ;
V_10 |= V_59 ;
V_56 |= F_9 ( V_10 , ( V_41 * ) & V_54 -> V_12 . V_10 ) ;
return V_56 ;
}
static inline int F_12 ( struct V_43 T_2 * V_29 )
{
int V_56 ;
if ( F_11 () )
V_56 = F_13 ( V_29 ) ;
else if ( F_6 () )
V_56 = F_14 ( (struct V_3 T_2 * ) V_29 ) ;
else
V_56 = F_15 ( (struct V_52 T_2 * ) V_29 ) ;
if ( F_16 ( V_56 ) && F_17 ( V_29 , V_39 ) )
V_56 = - V_60 ;
return V_56 ;
}
int F_18 ( void T_2 * V_29 , void T_2 * V_61 , int V_26 )
{
struct V_43 * V_11 = & V_62 -> V_5 . V_6 . V_7 -> V_11 ;
struct V_1 * V_2 = V_62 ;
int V_63 = ( V_29 != V_61 ) ;
V_63 &= ( F_19 ( V_64 ) ||
F_19 ( V_65 ) ) ;
if ( ! F_20 ( V_66 , V_29 , V_26 ) )
return - V_67 ;
if ( ! F_21 ( V_68 ) )
return F_22 ( V_62 , NULL , 0 ,
sizeof( struct V_44 ) , NULL ,
(struct V_46 T_2 * ) V_29 ) ? - 1 : 1 ;
if ( F_23 () ) {
if ( F_12 ( V_61 ) )
return - 1 ;
if ( V_63 )
F_24 ( & V_2 -> V_5 . V_6 ) ;
} else {
F_25 ( V_2 ) ;
if ( F_8 ( V_61 , V_11 , V_39 ) )
return - 1 ;
}
if ( ( V_63 || ! F_6 () ) && F_5 ( V_2 , V_29 ) )
return - 1 ;
if ( F_6 () && F_10 ( V_61 , V_63 ) )
return - 1 ;
return 0 ;
}
static inline void
F_26 ( struct V_1 * V_2 ,
struct V_44 * V_69 ,
T_1 V_10 , int V_70 )
{
struct V_43 * V_11 = & V_2 -> V_5 . V_6 . V_7 -> V_11 ;
struct V_34 * V_12 = & V_11 -> V_12 ;
if ( F_11 () ) {
memset ( V_12 -> V_71 , 0 , 48 ) ;
if ( V_70 )
V_12 -> V_10 = V_59 ;
else
V_12 -> V_10 &= ( V_13 & V_10 ) ;
}
if ( F_6 () ) {
V_11 -> V_48 . V_72 &= V_73 ;
F_27 ( V_2 , V_69 ) ;
}
}
static inline int F_28 ( void T_2 * V_29 , T_1 V_74 , int V_70 )
{
if ( F_11 () ) {
if ( ( unsigned long ) V_29 % 64 || V_70 ) {
T_1 V_75 = V_13 & ~ V_59 ;
F_29 ( V_28 , V_75 ) ;
return F_30 ( V_29 ) ;
} else {
T_1 V_75 = V_13 & ~ V_74 ;
if ( F_16 ( V_75 ) )
F_29 ( V_28 , V_75 ) ;
return F_31 ( V_29 , V_74 ) ;
}
} else if ( F_6 () ) {
return F_30 ( V_29 ) ;
} else
return F_32 ( V_29 ) ;
}
int F_33 ( void T_2 * V_29 , void T_2 * V_61 , int V_26 )
{
int V_63 = ( V_29 != V_61 ) ;
struct V_1 * V_2 = V_62 ;
int V_76 = V_39 ;
T_1 V_10 = 0 ;
int V_70 = 0 ;
V_63 &= ( F_19 ( V_64 ) ||
F_19 ( V_65 ) ) ;
if ( ! V_29 ) {
F_34 ( V_2 ) ;
return 0 ;
}
if ( ! F_20 ( V_77 , V_29 , V_26 ) )
return - V_67 ;
if ( ! F_35 () && F_36 ( V_2 ) )
return - 1 ;
if ( ! F_21 ( V_68 ) )
return F_37 ( V_62 , NULL ,
0 , sizeof( struct V_44 ) ,
NULL , V_29 ) != 0 ;
if ( F_11 () ) {
struct V_31 V_78 ;
if ( F_16 ( F_2 ( V_61 , V_61 , & V_78 ) ) ) {
V_76 = sizeof( struct V_3 ) ;
V_70 = 1 ;
} else {
V_76 = V_78 . V_39 ;
V_10 = V_78 . V_10 ;
}
}
if ( V_63 ) {
struct V_43 * V_11 = & V_2 -> V_5 . V_6 . V_7 -> V_11 ;
struct V_44 V_45 ;
int V_56 = 0 ;
F_38 ( V_2 ) ;
if ( F_3 ( V_11 , V_61 , V_76 ) ||
F_3 ( & V_45 , V_29 , sizeof( V_45 ) ) ) {
V_56 = - 1 ;
} else {
F_26 ( V_2 , & V_45 , V_10 , V_70 ) ;
F_39 () ;
}
if ( F_40 () ) {
F_41 () ;
F_42 () ;
F_43 () ;
}
return V_56 ;
} else {
F_44 () ;
if ( F_28 ( V_61 , V_10 , V_70 ) ) {
F_34 ( V_2 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_45 ( void )
{
int V_79 = sizeof( struct V_52 ) ;
int V_26 = V_39 + V_80 ;
if ( F_19 ( V_64 ) )
V_26 += V_79 ;
V_58 . V_37 = V_38 ;
V_58 . V_40 = V_26 ;
V_58 . V_10 = V_13 ;
V_58 . V_39 = V_39 ;
if ( F_19 ( V_65 ) ) {
V_57 = V_58 ;
V_57 . V_40 += V_79 ;
}
}
static inline void F_46 ( void )
{
F_47 ( V_81 ) ;
F_48 ( V_82 , V_13 ) ;
}
static void T_4 F_49 ( void )
{
int V_83 , V_84 , V_85 , V_86 , V_87 = 0x2 ;
V_88 = F_50 ( V_13 ) ;
V_25 = F_51 ( V_88 * sizeof( int ) ) ;
V_27 = F_51 ( V_88 * sizeof( int ) ) ;
do {
F_52 ( V_89 , V_87 , & V_83 , & V_84 , & V_85 , & V_86 ) ;
if ( V_83 == 0 )
break;
V_25 [ V_87 ] = V_84 ;
V_27 [ V_87 ] = V_83 ;
V_87 ++ ;
} while ( 1 );
}
void F_53 ( void )
{
unsigned int V_90 [ sizeof( V_13 ) * 8 ] ;
int V_91 ;
V_92 [ 0 ] = 0 ;
V_92 [ 1 ] = F_54 ( struct V_3 , V_23 ) ;
if ( ! V_93 ) {
for ( V_91 = 2 ; V_91 < V_88 ; V_91 ++ ) {
if ( F_55 ( V_91 , ( unsigned long * ) & V_13 ) ) {
V_92 [ V_91 ] = V_25 [ V_91 ] ;
V_90 [ V_91 ] = V_27 [ V_91 ] ;
}
}
return;
}
V_92 [ 2 ] = V_94 + V_95 ;
for ( V_91 = 2 ; V_91 < V_88 ; V_91 ++ ) {
if ( F_55 ( V_91 , ( unsigned long * ) & V_13 ) )
V_90 [ V_91 ] = V_27 [ V_91 ] ;
else
V_90 [ V_91 ] = 0 ;
if ( V_91 > 2 )
V_92 [ V_91 ] = V_92 [ V_91 - 1 ]
+ V_90 [ V_91 - 1 ] ;
}
}
static void T_4 F_56 ( void )
{
V_28 = F_57 ( V_39 ,
F_58 ( struct V_43 ) ) ;
F_59 ( & V_28 -> V_48 ) ;
if ( ! V_96 )
return;
F_49 () ;
if ( V_93 ) {
V_28 -> V_12 . V_97 =
( T_1 ) 1 << 63 | V_13 ;
V_28 -> V_12 . V_10 = V_13 ;
}
F_60 ( V_28 , - 1 ) ;
F_61 ( V_28 , - 1 ) ;
}
static int T_4 F_62 ( char * V_98 )
{
if ( ! strcmp ( V_98 , L_1 ) )
V_99 = V_100 ;
else if ( ! strcmp ( V_98 , L_2 ) )
V_99 = V_101 ;
else if ( ! strcmp ( V_98 , L_3 ) )
V_99 = AUTO ;
return 1 ;
}
static void T_4 F_63 ( void )
{
unsigned int V_83 , V_84 , V_85 , V_86 ;
int V_91 ;
if ( ! V_93 ) {
F_52 ( V_89 , 0 , & V_83 , & V_84 , & V_85 , & V_86 ) ;
V_39 = V_84 ;
return;
}
V_39 = V_94 + V_95 ;
for ( V_91 = 2 ; V_91 < 64 ; V_91 ++ ) {
if ( F_55 ( V_91 , ( unsigned long * ) & V_13 ) ) {
F_52 ( V_89 , V_91 , & V_83 , & V_84 , & V_85 , & V_86 ) ;
V_39 += V_83 ;
}
}
}
static void T_4 F_64 ( void )
{
unsigned int V_83 , V_84 , V_85 , V_86 ;
if ( V_102 . V_103 < V_89 ) {
F_65 ( 1 , V_104 L_4 ) ;
return;
}
F_52 ( V_89 , 0 , & V_83 , & V_84 , & V_85 , & V_86 ) ;
V_13 = V_83 + ( ( T_1 ) V_86 << 32 ) ;
if ( ( V_13 & V_59 ) != V_59 ) {
F_66 ( L_5 ,
V_13 ) ;
F_67 () ;
}
V_13 = V_13 & V_105 ;
F_46 () ;
F_63 () ;
F_68 ( V_39 , V_13 ) ;
F_45 () ;
F_56 () ;
if ( V_106 && V_99 != V_101 )
V_99 = V_100 ;
if ( V_13 & V_107 ) {
if ( V_99 == V_101 ) {
F_66 ( L_6 ,
V_13 & V_107 ) ;
V_13 &= ~ V_107 ;
} else {
V_99 = V_100 ;
}
}
F_69 ( L_7 ,
V_13 , V_39 ,
V_93 ? L_8 : L_9 ) ;
}
void F_70 ( void )
{
static T_5 void (* F_71)( void ) = F_64 ;
void (* F_72)( void );
if ( ! V_96 )
return;
F_72 = F_71 ;
F_71 = F_46 ;
F_72 () ;
}
static inline void T_4 F_73 ( void )
{
V_62 -> V_5 . V_6 . V_7 =
F_57 ( V_39 , F_58 ( struct V_43 ) ) ;
if ( ! V_28 )
F_56 () ;
}
void F_74 ( void )
{
static T_5 void (* F_75)( void ) = F_73 ;
F_76 () ;
F_77 () -> V_49 = 0 ;
if ( V_99 == V_100 )
F_78 ( V_108 ) ;
if ( ! V_109 ) {
F_79 () ;
return;
}
if ( F_75 ) {
F_75 () ;
F_75 = NULL ;
}
F_36 ( V_62 ) ;
F_80 ( V_62 ) ;
if ( V_96 )
F_29 ( V_28 , - 1 ) ;
else
F_81 ( & V_28 -> V_48 ) ;
}
void * F_82 ( struct V_43 * V_11 , int V_110 )
{
int V_111 = F_50 ( V_110 ) - 1 ;
if ( ! F_55 ( V_111 , ( unsigned long * ) & V_13 ) )
return NULL ;
return ( void * ) V_11 + V_92 [ V_111 ] ;
}
