static void
F_1 ( void )
{
if ( V_1 )
F_2 ( V_1 ) ;
if ( V_2 )
F_2 ( V_2 ) ;
}
static int
F_3 ( void )
{
V_1 = F_4 ( L_1 , 2 , 1 , 8 ) ;
V_2 = F_4 ( L_2 , 4 , 1 , 8 ) ;
if ( V_1 == NULL || V_2 == NULL ) {
F_5 ( L_3 ) ;
F_1 () ;
return - V_3 ;
}
F_6 ( V_1 , & V_4 ) ;
F_7 ( V_1 , 2 ) ;
F_6 ( V_2 , & V_4 ) ;
F_7 ( V_2 , 2 ) ;
return 0 ;
}
static int
F_8 ( struct V_5 * V_6 )
{
int V_7 ;
F_9 ( 2 , V_8 , L_4 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_6 -> V_10 [ V_7 ] . V_11 =
F_10 ( V_12 , V_13 | V_14 ) ;
if ( V_6 -> V_10 [ V_7 ] . V_11 == NULL )
break;
V_6 -> V_10 [ V_7 ] . V_15 = V_16 ;
}
if ( V_7 < V_9 ) {
F_9 ( 2 , V_8 , L_5 ) ;
while ( V_7 -- > 0 )
F_11 ( V_6 -> V_10 [ V_7 ] . V_11 ) ;
return - V_3 ;
}
return 0 ;
}
static void
F_12 ( struct V_5 * V_6 )
{
int V_7 ;
F_9 ( 2 , V_8 , L_6 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
F_11 ( V_6 -> V_10 [ V_7 ] . V_11 ) ;
V_6 -> V_10 [ V_7 ] . V_11 = NULL ;
}
}
static void
F_13 ( struct V_5 * V_6 )
{
F_9 ( 3 , V_8 , L_7 ) ;
F_14 ( & V_6 -> V_17 ) ;
F_12 ( V_6 ) ;
}
static void
F_15 ( struct V_18 * V_19 )
{
F_9 ( 2 , V_8 , L_8 ) ;
F_16 ( 2 , V_8 , & V_19 , sizeof( void * ) ) ;
F_11 ( V_19 ) ;
}
static struct V_18 *
F_17 ( void )
{
struct V_18 * V_19 ;
int V_20 ;
F_9 ( 2 , V_8 , L_9 ) ;
V_19 = F_10 ( sizeof( struct V_18 ) , V_14 | V_13 ) ;
if ( V_19 == NULL )
return NULL ;
V_19 -> V_21 = V_22 ;
V_19 -> V_23 = 0 ;
V_19 -> V_24 = V_25 ;
V_20 = F_8 ( & V_19 -> V_26 ) ;
if ( V_20 ) {
F_9 ( 2 , V_8 , L_10 ) ;
F_15 ( V_19 ) ;
return NULL ;
}
V_20 = F_8 ( & V_19 -> V_27 ) ;
if ( V_20 ) {
F_9 ( 2 , V_8 , L_10 ) ;
F_13 ( & V_19 -> V_26 ) ;
F_15 ( V_19 ) ;
return NULL ;
}
#ifdef F_18
F_19 ( & V_19 -> V_28 ) ;
#endif
F_16 ( 2 , V_8 , & V_19 , sizeof( void * ) ) ;
return V_19 ;
}
static void
F_20 ( struct V_18 * V_19 )
{
int V_7 ;
F_9 ( 2 , V_8 , L_11 ) ;
memset ( V_19 -> V_26 . V_29 , 0 , sizeof ( struct V_30 ) * ( V_9 + 1 ) ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_19 -> V_26 . V_29 [ V_7 ] . V_31 = V_32 ;
V_19 -> V_26 . V_29 [ V_7 ] . V_33 = V_12 ;
V_19 -> V_26 . V_29 [ V_7 ] . V_34 =
V_35 | V_36 | V_37 ;
V_19 -> V_26 . V_29 [ V_7 ] . V_38 =
( V_39 ) F_21 ( V_19 -> V_26 . V_10 [ V_7 ] . V_11 ) ;
( (struct V_40 * )
V_19 -> V_26 . V_10 [ V_7 ] . V_11 ) -> V_41 = V_42 ;
V_19 -> V_26 . V_10 [ V_7 ] . V_43 = V_44 ;
V_19 -> V_26 . V_10 [ V_7 ] . V_15 = V_45 ;
V_19 -> V_26 . V_10 [ V_7 ] . V_33 = V_12 ;
}
V_19 -> V_26 . V_29 [ 0 ] . V_34 &= ~ V_37 ;
V_19 -> V_26 . V_29 [ V_9 - 1 ] . V_34 &= ~ V_37 ;
V_19 -> V_26 . V_29 [ V_9 - 1 ] . V_34 |= V_46 ;
V_19 -> V_26 . V_29 [ V_9 ] . V_31 = V_47 ;
V_19 -> V_26 . V_29 [ V_9 ] . V_38 =
( V_39 ) F_21 ( V_19 -> V_26 . V_29 ) ;
V_19 -> V_26 . V_15 = V_48 ;
V_19 -> V_26 . V_49 = 0 ;
V_19 -> V_26 . V_50 = 0 ;
}
static void
F_22 ( struct V_18 * V_19 )
{
F_9 ( 3 , V_8 , L_12 ) ;
F_20 ( V_19 ) ;
V_19 -> V_26 . V_17 . V_11 = ( unsigned long ) & V_19 -> V_26 ;
V_19 -> V_26 . V_17 . V_51 = V_52 ;
F_23 ( & V_19 -> V_26 . V_53 ) ;
}
static void
F_24 ( struct V_18 * V_19 )
{
int V_7 ;
F_9 ( 3 , V_8 , L_13 ) ;
memset ( V_19 -> V_27 . V_29 , 0 , sizeof( struct V_30 ) * ( V_9 + 1 ) ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_19 -> V_27 . V_29 [ V_7 ] . V_31 = V_54 ;
V_19 -> V_27 . V_29 [ V_7 ] . V_33 = 0 ;
V_19 -> V_27 . V_29 [ V_7 ] . V_34 =
V_46 | V_35 | V_36 ;
V_19 -> V_27 . V_29 [ V_7 ] . V_38 =
( V_39 ) F_21 ( V_19 -> V_27 . V_10 [ V_7 ] . V_11 ) ;
}
V_19 -> V_27 . V_29 [ V_9 ] . V_31 = V_47 ;
V_19 -> V_27 . V_29 [ V_9 ] . V_38 =
( V_39 ) F_21 ( V_19 -> V_27 . V_29 ) ;
V_19 -> V_26 . V_15 = V_48 ;
V_19 -> V_27 . V_49 = 0 ;
V_19 -> V_27 . V_50 = 0 ;
}
static void
F_25 ( struct V_18 * V_19 )
{
F_9 ( 3 , V_8 , L_14 ) ;
F_24 ( V_19 ) ;
V_19 -> V_27 . V_17 . V_11 = ( unsigned long ) & V_19 -> V_27 ;
V_19 -> V_27 . V_17 . V_51 = V_52 ;
F_23 ( & V_19 -> V_27 . V_53 ) ;
}
static void
F_26 ( struct V_18 * V_19 , unsigned long V_55 )
{
unsigned long V_34 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
V_19 -> V_57 = V_55 ;
F_28 ( & V_19 -> V_56 , V_34 ) ;
F_29 ( & V_19 -> V_53 ) ;
}
static inline int
F_30 ( struct V_18 * V_19 , unsigned long V_55 )
{
unsigned long V_34 ;
int V_20 = 0 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
V_20 = ( V_19 -> V_58 & V_55 ) ;
F_28 ( & V_19 -> V_56 , V_34 ) ;
return V_20 ;
}
static int
F_31 ( struct V_18 * V_19 , unsigned long V_55 )
{
return F_32 ( V_19 -> V_53 ,
F_30 ( V_19 , V_55 ) == 0 ) ;
}
static inline int
F_33 ( struct V_18 * V_19 , unsigned long V_59 )
{
unsigned long V_34 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
if ( ! ( V_19 -> V_57 & V_59 ) ||
( V_19 -> V_60 & V_59 ) ) {
F_28 ( & V_19 -> V_56 , V_34 ) ;
return - V_61 ;
}
V_19 -> V_60 |= V_59 ;
F_28 ( & V_19 -> V_56 , V_34 ) ;
return 0 ;
}
static void
F_34 ( struct V_18 * V_19 , unsigned long V_59 )
{
unsigned long V_34 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
V_19 -> V_58 &= ~ V_59 ;
F_28 ( & V_19 -> V_56 , V_34 ) ;
F_29 ( & V_19 -> V_53 ) ;
}
static inline int
F_35 ( struct V_18 * V_19 , unsigned long V_59 )
{
unsigned long V_34 ;
int V_20 = 0 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
if ( V_19 -> V_60 & V_59 ) {
if ( ( V_19 -> V_57 & V_59 ) &&
! ( V_19 -> V_58 & V_59 ) ) {
V_20 = 1 ;
V_19 -> V_60 &= ~ V_59 ;
V_19 -> V_58 |= V_59 ;
} else
V_20 = - V_61 ;
}
F_28 ( & V_19 -> V_56 , V_34 ) ;
return V_20 ;
}
static int
F_36 ( struct V_18 * V_19 , unsigned long V_59 )
{
int V_20 = 0 ;
F_37 ( V_19 -> V_53 ,
( V_20 = F_35 ( V_19 , V_59 ) ) >= 0 ) ;
return V_20 ;
}
static int
F_38 ( struct V_18 * V_19 , unsigned long V_59 )
{
unsigned long V_34 ;
int V_20 = 0 ;
F_27 ( & V_19 -> V_56 , V_34 ) ;
F_39 ( 4 , V_62 , L_15 ,
( V_63 ) V_19 -> V_60 ,
( V_63 ) V_19 -> V_57 ,
( V_63 ) V_19 -> V_58 ) ;
V_20 = ( V_19 -> V_60 & V_59 ) ;
F_28 ( & V_19 -> V_56 , V_34 ) ;
return V_20 ;
}
static void
F_40 ( struct V_18 * V_19 )
{
F_9 ( 2 , V_8 , L_16 ) ;
F_16 ( 2 , V_8 , & V_19 , sizeof( void * ) ) ;
F_22 ( V_19 ) ;
F_25 ( V_19 ) ;
V_19 -> V_15 = V_64 ;
V_19 -> V_65 = NULL ;
V_19 -> V_66 = 0 ;
F_23 ( & V_19 -> V_53 ) ;
F_41 ( & V_19 -> V_67 ) ;
F_41 ( & V_19 -> V_68 ) ;
F_41 ( & V_19 -> V_56 ) ;
#ifdef F_18
F_19 ( & V_19 -> V_28 ) ;
#endif
F_19 ( & V_19 -> V_69 ) ;
}
static inline void
F_42 ( struct V_18 * V_19 )
{
#ifdef F_18
struct V_70 * V_71 ;
unsigned long V_34 ;
F_9 ( 3 , V_8 , L_17 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
while ( ! F_43 ( & V_19 -> V_28 ) ) {
V_71 = F_44 ( V_19 -> V_28 . V_72 ,
struct V_70 , V_73 ) ;
F_45 ( & V_71 -> V_73 ) ;
if ( V_71 -> V_74 != V_75 ) {
F_28 ( & V_19 -> V_68 , V_34 ) ;
F_46 ( V_19 , V_71 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
}
F_11 ( V_71 ) ;
}
F_28 ( & V_19 -> V_68 , V_34 ) ;
#endif
}
static void
F_47 ( struct V_18 * V_19 )
{
F_9 ( 3 , V_8 , L_18 ) ;
F_16 ( 2 , V_8 , & V_19 , sizeof( void * ) ) ;
if ( V_19 -> V_76 != NULL )
F_48 ( V_19 -> V_76 ) ;
F_13 ( & V_19 -> V_27 ) ;
F_13 ( & V_19 -> V_26 ) ;
}
static int
F_49 ( struct V_5 * V_6 )
{
unsigned long V_34 ;
int V_20 ;
F_39 ( 4 , V_62 , L_19 , F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_20 = F_52 ( V_6 -> V_77 ,
V_6 -> V_29 + V_6 -> V_49 , 0 , 0 ,
V_78 | V_79 ) ;
if ( V_20 == 0 )
V_6 -> V_15 = V_80 ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
if ( V_20 ) {
F_39 ( 4 , V_62 , L_20 ,
F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
F_53 ( & V_6 -> V_77 -> V_76 ,
L_21
L_22 , V_20 ) ;
}
return V_20 ;
}
static int
F_54 ( struct V_5 * V_6 )
{
unsigned long V_34 ;
int V_20 ;
F_9 ( 4 , V_62 , L_23 ) ;
F_39 ( 4 , V_62 , L_24 , F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_20 = F_55 ( V_6 -> V_77 , ( V_81 ) V_6 ) ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
if ( V_20 ) {
F_39 ( 4 , V_62 , L_25 ,
F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
return V_20 ;
}
F_37 ( V_6 -> V_53 , ( V_6 -> V_15 == V_82 ) ) ;
V_6 -> V_15 = V_83 ;
return V_20 ;
}
static int
F_56 ( struct V_5 * V_6 )
{
unsigned long V_34 ;
int V_20 ;
if ( V_6 -> V_15 == V_83 )
return 0 ;
F_9 ( 4 , V_62 , L_26 ) ;
F_39 ( 4 , V_62 , L_24 , F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
V_6 -> V_15 = V_48 ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_20 = F_57 ( V_6 -> V_77 , ( V_81 ) V_6 ) ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
if ( V_20 ) {
F_39 ( 4 , V_62 , L_27 ,
F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
return V_20 ;
}
F_37 ( V_6 -> V_53 , ( V_6 -> V_15 == V_84 ) ) ;
F_54 ( V_6 ) ;
return 0 ;
}
static int
F_58 ( struct V_18 * V_19 )
{
int V_20 ;
F_9 ( 2 , V_62 , L_28 ) ;
V_20 = F_49 ( & V_19 -> V_26 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_49 ( & V_19 -> V_27 ) ;
if ( V_20 )
F_56 ( & V_19 -> V_26 ) ;
return V_20 ;
}
static int
F_59 ( struct V_18 * V_19 )
{
F_9 ( 2 , V_62 , L_29 ) ;
F_56 ( & V_19 -> V_26 ) ;
F_56 ( & V_19 -> V_27 ) ;
return 0 ;
}
static struct V_85 *
F_60 ( struct V_5 * V_6 )
{
int V_86 ;
F_9 ( 5 , V_62 , L_30 ) ;
V_86 = V_6 -> V_49 ;
do {
if ( V_6 -> V_10 [ V_86 ] . V_15 == V_16 ) {
V_6 -> V_10 [ V_86 ] . V_15 = V_87 ;
return V_6 -> V_10 + V_86 ;
}
V_86 = ( V_86 + 1 ) & ( V_9 - 1 ) ;
} while ( V_86 != V_6 -> V_49 );
return NULL ;
}
static struct V_85 *
F_61 ( struct V_5 * V_6 )
{
struct V_85 * V_88 ;
unsigned long V_34 ;
F_9 ( 5 , V_62 , L_31 ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_88 = F_60 ( V_6 ) ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
return V_88 ;
}
static int
F_62 ( struct V_5 * V_6 )
{
int V_20 ;
if ( V_6 -> V_15 != V_89 )
return 0 ;
if ( V_6 -> V_29 [ V_6 -> V_49 ] . V_34 & V_46 )
return 0 ;
F_39 ( 5 , V_62 , L_32 , F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
V_20 = F_63 ( V_6 -> V_77 ) ;
if ( V_20 ) {
F_39 ( 4 , V_62 , L_33 ,
F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
F_53 ( & V_6 -> V_77 -> V_76 ,
L_34
L_35 , V_20 ) ;
} else
V_6 -> V_15 = V_80 ;
return V_20 ;
}
static inline void
F_64 ( struct V_5 * V_6 , int V_86 )
{
int V_90 , V_72 ;
F_9 ( 5 , V_62 , L_36 ) ;
V_90 = ( V_86 - 1 ) & ( V_9 - 1 ) ;
V_72 = ( V_86 + 1 ) & ( V_9 - 1 ) ;
if ( V_6 -> V_29 [ V_72 ] . V_34 & V_46 ) {
if ( ! ( V_6 -> V_29 [ V_90 ] . V_34 & V_46 ) )
V_6 -> V_29 [ V_86 ] . V_34 |= V_37 ;
V_6 -> V_29 [ V_86 ] . V_34 &= ~ V_46 ;
}
}
static int
F_65 ( struct V_5 * V_6 , struct V_85 * V_88 )
{
unsigned long V_34 ;
int V_86 , V_20 ;
F_9 ( 5 , V_62 , L_37 ) ;
F_66 ( V_88 -> V_15 != V_87 &&
V_88 -> V_15 != V_91 ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_88 -> V_15 = V_45 ;
V_86 = V_88 - V_6 -> V_10 ;
V_6 -> V_29 [ V_86 ] . V_33 = V_88 -> V_33 ;
F_64 ( V_6 , V_86 ) ;
V_20 = F_62 ( V_6 ) ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
return V_20 ;
}
static int
F_67 ( struct V_5 * V_6 , struct V_85 * V_88 )
{
int V_86 , V_90 , V_72 ;
F_9 ( 5 , V_62 , L_38 ) ;
F_66 ( V_88 -> V_15 != V_45 ) ;
V_88 -> V_15 = V_91 ;
V_86 = V_88 - V_6 -> V_10 ;
V_90 = ( V_86 - 1 ) & ( V_9 - 1 ) ;
V_72 = ( V_86 + 1 ) & ( V_9 - 1 ) ;
V_6 -> V_29 [ V_86 ] . V_34 |= V_46 ;
V_6 -> V_29 [ V_86 ] . V_34 &= ~ V_37 ;
if ( V_6 -> V_10 [ V_90 ] . V_15 == V_45 ) {
F_64 ( V_6 , V_90 ) ;
}
V_6 -> V_29 [ V_72 ] . V_34 &= ~ V_37 ;
return F_62 ( V_6 ) ;
}
static void
F_68 ( struct V_5 * V_6 , struct V_85 * V_88 )
{
unsigned long V_34 ;
F_9 ( 5 , V_62 , L_39 ) ;
F_66 ( V_88 -> V_15 != V_87 &&
V_88 -> V_15 != V_91 ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
V_88 -> V_15 = V_16 ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
}
static struct V_85 *
F_69 ( struct V_18 * V_19 , int V_33 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 4 , V_62 , L_40 ) ;
F_37 ( V_19 -> V_27 . V_53 ,
( ( V_88 = F_61 ( & V_19 -> V_27 ) ) != NULL ) ) ;
V_33 += sizeof( struct V_40 ) ;
* ( V_94 * ) ( V_88 -> V_11 + V_33 ) = 0 ;
V_88 -> V_33 = V_33 + sizeof( V_94 ) ;
V_88 -> V_43 = F_68 ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_41 = V_33 ;
V_93 -> type = V_95 ;
V_93 -> V_96 = 0 ;
return V_88 ;
}
static void
F_70 ( struct V_97 * V_98 )
{
F_71 ( F_72 ( & V_98 -> V_99 ) <= 0 ) ;
F_73 ( & V_98 -> V_99 ) ;
}
static void
F_74 ( struct V_97 * V_98 )
{
F_71 ( F_72 ( & V_98 -> V_99 ) <= 0 ) ;
if ( F_75 ( & V_98 -> V_99 ) ) {
F_11 ( V_98 ) ;
}
}
static struct V_97 *
F_76 ( struct V_92 * V_93 )
{
struct V_97 * V_98 ;
F_9 ( 4 , V_62 , L_41 ) ;
V_98 = F_10 ( sizeof( struct V_97 ) , V_100 ) ;
if ( ! V_98 )
return NULL ;
F_77 ( & V_98 -> V_99 , 1 ) ;
V_98 -> V_101 = V_93 -> V_101 ;
V_98 -> V_102 = 0 ;
V_98 -> V_20 = 0 ;
F_23 ( & V_98 -> V_53 ) ;
return V_98 ;
}
static void
F_78 ( struct V_18 * V_19 , struct V_92 * V_93 )
{
struct V_103 * V_104 , * V_105 ;
struct V_97 * V_98 ;
F_9 ( 4 , V_62 , L_42 ) ;
F_79 ( & V_19 -> V_67 ) ;
F_80 (l, n, &card->lancmd_waiters) {
V_98 = F_44 ( V_104 , struct V_97 , V_73 ) ;
if ( V_98 -> V_101 == V_93 -> V_101 ) {
F_70 ( V_98 ) ;
F_81 ( & V_98 -> V_73 ) ;
if ( V_98 -> V_43 != NULL )
V_98 -> V_43 ( V_19 , V_93 ) ;
V_98 -> V_102 = 1 ;
V_98 -> V_20 = V_93 -> V_106 ;
F_29 ( & V_98 -> V_53 ) ;
F_74 ( V_98 ) ;
break;
}
}
F_82 ( & V_19 -> V_67 ) ;
}
static void
F_83 ( unsigned long V_11 )
{
struct V_97 * V_98 , * V_107 , * V_108 ;
unsigned long V_34 ;
F_9 ( 4 , V_62 , L_43 ) ;
V_98 = (struct V_97 * ) V_11 ;
F_27 ( & V_98 -> V_19 -> V_67 , V_34 ) ;
F_84 (list_reply, r,
&reply->card->lancmd_waiters,list) {
if ( V_98 == V_107 ) {
F_70 ( V_98 ) ;
F_81 ( & V_98 -> V_73 ) ;
F_28 ( & V_98 -> V_19 -> V_67 , V_34 ) ;
V_98 -> V_102 = 1 ;
V_98 -> V_20 = - V_109 ;
F_29 ( & V_98 -> V_53 ) ;
F_74 ( V_98 ) ;
return;
}
}
F_28 ( & V_98 -> V_19 -> V_67 , V_34 ) ;
}
static int
F_85 ( struct V_18 * V_19 , struct V_85 * V_88 ,
void (* F_86)( struct V_18 * , struct V_92 * ) )
{
struct V_97 * V_98 ;
struct V_92 * V_93 ;
struct V_110 V_111 ;
unsigned long V_34 ;
int V_20 ;
F_9 ( 4 , V_62 , L_44 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_106 = 0 ;
V_93 -> V_101 = V_19 -> V_101 ++ ;
V_98 = F_76 ( V_93 ) ;
if ( ! V_98 )
return - V_3 ;
V_98 -> V_43 = F_86 ;
V_98 -> V_19 = V_19 ;
F_27 ( & V_19 -> V_67 , V_34 ) ;
F_87 ( & V_98 -> V_73 , & V_19 -> V_69 ) ;
F_28 ( & V_19 -> V_67 , V_34 ) ;
V_88 -> V_43 = F_68 ;
V_20 = F_65 ( & V_19 -> V_27 , V_88 ) ;
if ( V_20 )
return V_20 ;
F_88 ( & V_111 ) ;
V_111 . V_112 = F_83 ;
V_111 . V_11 = ( unsigned long ) V_98 ;
V_111 . V_113 = V_114 + V_115 * V_19 -> V_24 ;
F_89 ( & V_111 ) ;
F_37 ( V_98 -> V_53 , V_98 -> V_102 ) ;
F_90 ( & V_111 ) ;
F_91 ( & V_111 ) ;
F_39 ( 4 , V_62 , L_45 , V_98 -> V_20 ) ;
V_20 = V_98 -> V_20 ;
F_74 ( V_98 ) ;
return V_20 ? - V_116 : 0 ;
}
static int
F_92 ( struct V_18 * V_19 , T_1 V_117 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_46 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_119 ;
V_93 -> V_117 = V_117 ;
V_93 -> V_93 . V_120 . V_121 = V_12 ;
return F_85 ( V_19 , V_88 , NULL ) ;
}
static int
F_93 ( struct V_18 * V_19 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_47 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_122 ;
V_93 -> V_117 = V_123 ;
return F_85 ( V_19 , V_88 , NULL ) ;
}
static void
F_94 ( struct V_18 * V_19 , struct V_92 * V_93 )
{
F_9 ( 2 , V_62 , L_48 ) ;
memcpy ( V_19 -> V_124 , V_93 -> V_93 . V_125 . V_126 , V_127 ) ;
}
static int
F_95 ( struct V_18 * V_19 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_49 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_128 ;
V_93 -> V_117 = V_123 ;
V_93 -> V_93 . V_129 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_129 . V_130 = V_19 -> V_130 ;
return F_85 ( V_19 , V_88 , F_94 ) ;
}
static int
F_96 ( struct V_18 * V_19 , T_1 V_117 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_50 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_131 ;
V_93 -> V_117 = V_117 ;
V_93 -> V_93 . V_129 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_129 . V_130 = V_19 -> V_130 ;
return F_85 ( V_19 , V_88 , NULL ) ;
}
static void
F_97 ( struct V_18 * V_19 , struct V_92 * V_93 )
{
F_9 ( 2 , V_62 , L_51 ) ;
V_19 -> V_21 = V_93 -> V_93 . V_129 . V_21 ;
V_19 -> V_130 = V_93 -> V_93 . V_129 . V_130 ;
}
static int
F_98 ( struct V_18 * V_19 , T_1 V_117 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_52 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_132 ;
V_93 -> V_117 = V_117 ;
V_93 -> V_93 . V_129 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_129 . V_130 = V_19 -> V_130 ;
return F_85 ( V_19 , V_88 , F_97 ) ;
}
static int
F_99 ( struct V_18 * V_19 , struct V_70 * V_28 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_53 ) ;
V_88 = F_69 ( V_19 , V_133 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_134 ;
V_93 -> V_117 = V_123 ;
V_93 -> V_93 . V_135 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_135 . V_130 = V_19 -> V_130 ;
V_93 -> V_93 . V_135 . V_136 = 4 ;
V_93 -> V_93 . V_135 . V_137 = 1 ;
memcpy ( V_93 -> V_93 . V_135 . V_138 . V_139 ,
& V_28 -> V_71 , sizeof ( struct V_140 ) ) ;
F_39 ( 2 , V_62 , L_54 , V_28 -> V_71 . V_141 ) ;
return F_85 ( V_19 , V_88 , NULL ) ;
}
static int
F_46 ( struct V_18 * V_19 , struct V_70 * V_28 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
F_9 ( 2 , V_62 , L_55 ) ;
V_88 = F_69 ( V_19 , V_133 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_142 ;
V_93 -> V_117 = V_123 ;
V_93 -> V_93 . V_135 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_135 . V_130 = V_19 -> V_130 ;
V_93 -> V_93 . V_135 . V_136 = 4 ;
V_93 -> V_93 . V_135 . V_137 = 1 ;
memcpy ( V_93 -> V_93 . V_135 . V_138 . V_139 ,
& V_28 -> V_71 , sizeof ( struct V_140 ) ) ;
F_39 ( 2 , V_62 , L_54 , V_28 -> V_71 . V_141 ) ;
return F_85 ( V_19 , V_88 , NULL ) ;
}
static void
F_100 ( struct V_18 * V_19 , struct V_92 * V_93 )
{
F_9 ( 2 , V_62 , L_56 ) ;
V_19 -> V_143 =
V_93 -> V_93 . V_135 . V_143 ;
V_19 -> V_144 =
V_93 -> V_93 . V_135 . V_144 ;
}
static int
F_101 ( struct V_18 * V_19 )
{
struct V_85 * V_88 ;
struct V_92 * V_93 ;
int V_20 ;
F_9 ( 2 , V_62 , L_57 ) ;
V_88 = F_69 ( V_19 , V_118 ) ;
V_93 = (struct V_92 * ) V_88 -> V_11 ;
V_93 -> V_31 = V_145 ;
V_93 -> V_117 = V_123 ;
V_93 -> V_93 . V_135 . V_21 = V_19 -> V_21 ;
V_93 -> V_93 . V_135 . V_130 = V_19 -> V_130 ;
V_93 -> V_93 . V_135 . V_136 = 4 ;
V_93 -> V_93 . V_135 . V_137 = 1 ;
V_20 = F_85 ( V_19 , V_88 , F_100 ) ;
if ( V_20 != 0 ) {
F_5 ( L_58 ) ;
return - V_146 ;
}
if ( V_19 -> V_143 & V_147 )
return 0 ;
return - V_146 ;
}
static void
F_102 ( struct V_18 * V_19 )
{
struct V_103 V_148 ;
struct V_70 * V_71 , * V_149 ;
unsigned long V_34 ;
int V_20 ;
F_9 ( 4 , V_62 , L_59 ) ;
F_19 ( & V_148 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
V_150:
F_84 (ipm, tmp, &card->ipm_list, list) {
switch ( V_71 -> V_74 ) {
case V_75 :
F_81 ( & V_71 -> V_73 ) ;
F_28 ( & V_19 -> V_68 , V_34 ) ;
V_20 = F_99 ( V_19 , V_71 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
if ( V_20 ) {
F_103 ( L_60
L_61 ) ;
F_87 ( & V_71 -> V_73 , & V_148 ) ;
} else {
V_71 -> V_74 = V_151 ;
F_87 ( & V_71 -> V_73 , & V_19 -> V_28 ) ;
}
goto V_150;
case V_152 :
F_45 ( & V_71 -> V_73 ) ;
F_28 ( & V_19 -> V_68 , V_34 ) ;
F_46 ( V_19 , V_71 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
F_11 ( V_71 ) ;
goto V_150;
case V_151 :
break;
}
}
F_84 (ipm, tmp, &failed_list, list)
F_104 ( & V_71 -> V_73 , & V_19 -> V_28 ) ;
F_28 ( & V_19 -> V_68 , V_34 ) ;
}
static void
F_105 ( T_2 V_71 , char * V_124 , struct V_153 * V_76 )
{
F_9 ( 4 , V_62 , L_62 ) ;
F_106 ( V_71 , V_124 ) ;
}
static inline void
F_107 ( struct V_18 * V_19 , struct V_154 * V_155 )
{
struct V_156 * V_157 ;
struct V_103 * V_104 ;
struct V_70 * V_71 ;
unsigned long V_34 ;
char V_158 [ V_159 ] ;
F_9 ( 4 , V_62 , L_63 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
F_108 (l, &card->ipm_list) {
V_71 = F_44 ( V_104 , struct V_70 , V_73 ) ;
for ( V_157 = F_109 ( V_155 -> V_160 ) ;
V_157 != NULL ; V_157 = F_109 ( V_157 -> V_161 ) ) {
F_105 ( V_157 -> V_162 , V_158 , V_19 -> V_76 ) ;
if ( ( V_71 -> V_71 . V_141 == V_157 -> V_162 ) &&
( memcmp ( V_158 , & V_71 -> V_71 . V_126 ,
V_127 ) == 0 ) )
break;
}
if ( V_157 == NULL )
V_71 -> V_74 = V_152 ;
}
F_28 ( & V_19 -> V_68 , V_34 ) ;
}
static inline struct V_70 *
F_110 ( struct V_18 * V_19 , struct V_156 * V_157 , char * V_158 )
{
struct V_70 * V_149 , * V_71 = NULL ;
struct V_103 * V_104 ;
unsigned long V_34 ;
F_9 ( 4 , V_62 , L_64 ) ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
F_108 (l, &card->ipm_list) {
V_149 = F_44 ( V_104 , struct V_70 , V_73 ) ;
if ( ( V_149 -> V_71 . V_141 == V_157 -> V_162 ) &&
( memcmp ( V_158 , & V_149 -> V_71 . V_126 ,
V_127 ) == 0 ) ) {
V_71 = V_149 ;
break;
}
}
F_28 ( & V_19 -> V_68 , V_34 ) ;
return V_71 ;
}
static inline void
F_111 ( struct V_18 * V_19 , struct V_154 * V_155 )
{
struct V_156 * V_157 ;
struct V_70 * V_71 ;
char V_158 [ V_159 ] ;
unsigned long V_34 ;
F_9 ( 4 , V_62 , L_65 ) ;
for ( V_157 = F_109 ( V_155 -> V_160 ) ; V_157 != NULL ;
V_157 = F_109 ( V_157 -> V_161 ) ) {
F_105 ( V_157 -> V_162 , V_158 , V_19 -> V_76 ) ;
V_71 = F_110 ( V_19 , V_157 , V_158 ) ;
if ( V_71 != NULL )
continue;
V_71 = F_10 ( sizeof( struct V_70 ) , V_100 ) ;
if ( V_71 == NULL ) {
F_103 ( L_66
L_67 ) ;
break;
}
memcpy ( & V_71 -> V_71 . V_126 , V_158 , V_127 ) ;
V_71 -> V_71 . V_141 = V_157 -> V_162 ;
V_71 -> V_74 = V_75 ;
F_27 ( & V_19 -> V_68 , V_34 ) ;
F_16 ( 2 , V_62 , & V_71 -> V_71 . V_141 , 4 ) ;
F_112 ( & V_71 -> V_73 , & V_19 -> V_28 ) ;
F_28 ( & V_19 -> V_68 , V_34 ) ;
}
}
static int
F_113 ( void * V_11 )
{
struct V_18 * V_19 ;
struct V_154 * V_155 ;
V_19 = (struct V_18 * ) V_11 ;
if ( ! F_36 ( V_19 , V_163 ) )
return 0 ;
F_9 ( 4 , V_62 , L_68 ) ;
V_155 = F_114 ( V_19 -> V_76 ) ;
if ( V_155 == NULL )
goto V_164;
F_115 () ;
F_107 ( V_19 , V_155 ) ;
F_111 ( V_19 , V_155 ) ;
F_116 () ;
F_117 ( V_155 ) ;
F_118 ( V_19 -> V_76 ) ;
F_119 ( V_19 -> V_76 ) ;
F_37 ( V_19 -> V_27 . V_53 ,
( V_19 -> V_27 . V_15 != V_80 ) ) ;
F_102 ( V_19 ) ;
if ( V_19 -> V_15 == V_165 ) {
F_120 ( V_19 -> V_76 ) ;
F_121 ( V_19 -> V_76 ) ;
}
V_164:
F_34 ( V_19 , V_163 ) ;
return 0 ;
}
static void
F_122 ( struct V_153 * V_76 )
{
#ifdef F_18
struct V_18 * V_19 ;
F_9 ( 4 , V_62 , L_69 ) ;
V_19 = (struct V_18 * ) V_76 -> V_166 ;
if ( ! F_33 ( V_19 , V_163 ) )
F_123 ( & V_19 -> V_167 ) ;
#endif
}
static long
F_124 ( struct V_168 * V_169 , struct V_170 * V_170 )
{
if ( ! F_125 ( V_170 ) )
return 0 ;
switch ( F_126 ( V_170 ) ) {
case - V_116 :
F_127 ( & V_169 -> V_76 ,
L_70 ) ;
F_9 ( 2 , V_62 , L_71 ) ;
F_39 ( 2 , V_62 , L_72 , - V_116 ) ;
break;
case - V_171 :
F_127 ( & V_169 -> V_76 ,
L_73 ) ;
F_9 ( 2 , V_62 , L_71 ) ;
F_39 ( 2 , V_62 , L_72 , - V_171 ) ;
break;
default:
F_127 ( & V_169 -> V_76 ,
L_74 ,
F_126 ( V_170 ) ) ;
F_9 ( 2 , V_62 , L_71 ) ;
F_9 ( 2 , V_62 , L_75 ) ;
}
return F_126 ( V_170 ) ;
}
static int
F_128 ( struct V_168 * V_169 , struct V_170 * V_170 )
{
int V_172 , V_173 ;
char * V_174 ;
V_174 = ( char * ) V_170 -> V_175 ;
V_173 = V_170 -> V_176 . V_93 . V_173 ;
V_172 = V_170 -> V_176 . V_93 . V_172 ;
if ( V_173 & ( V_177 | V_178 |
V_179 | V_180 |
V_181 | V_182 ) ) {
F_9 ( 2 , V_62 , L_76 ) ;
return 1 ;
}
if ( V_172 & V_183 ) {
if ( V_174 [ V_184 ] &
V_185 ) {
F_9 ( 2 , V_62 , L_77 ) ;
return 1 ;
}
if ( V_174 [ V_186 ] &
V_187 ) {
F_9 ( 2 , V_62 , L_78 ) ;
return 0 ;
}
if ( ( ! V_174 [ V_186 ] ) &&
( ! V_174 [ V_184 ] ) &&
( ! V_174 [ V_188 ] ) &&
( ! V_174 [ V_189 ] ) ) {
F_9 ( 2 , V_62 , L_79 ) ;
return 0 ;
}
F_9 ( 2 , V_62 , L_80 ) ;
return 1 ;
}
return 0 ;
}
static void
F_129 ( struct V_18 * V_19 )
{
F_9 ( 2 , V_62 , L_81 ) ;
if ( ! F_33 ( V_19 , V_190 ) )
F_123 ( & V_19 -> V_167 ) ;
}
static void
F_130 ( struct V_168 * V_169 , unsigned long V_191 , struct V_170 * V_170 )
{
struct V_18 * V_19 ;
struct V_5 * V_6 ;
int V_20 , V_86 ;
int V_173 , V_172 ;
if ( F_124 ( V_169 , V_170 ) )
return;
V_19 = F_131 ( V_169 ) ;
if ( V_19 -> V_26 . V_77 == V_169 )
V_6 = & V_19 -> V_26 ;
else
V_6 = & V_19 -> V_27 ;
V_173 = V_170 -> V_176 . V_93 . V_173 ;
V_172 = V_170 -> V_176 . V_93 . V_172 ;
F_39 ( 5 , V_62 , L_82 , F_50 ( & V_169 -> V_76 ) ) ;
F_39 ( 5 , V_62 , L_83 , V_170 -> V_176 . V_93 . V_173 ,
V_170 -> V_176 . V_93 . V_172 ) ;
F_39 ( 5 , V_62 , L_83 , V_170 -> V_176 . V_93 . V_192 ,
V_170 -> V_176 . V_93 . V_193 ) ;
V_20 = F_128 ( V_169 , V_170 ) ;
if ( V_20 || ( V_172 & V_194 ) ) {
F_127 ( & V_169 -> V_76 ,
L_84
L_85 ,
V_172 , V_173 ) ;
if ( V_20 ) {
V_6 -> V_15 = V_195 ;
}
}
if ( V_6 -> V_15 == V_195 ) {
F_129 ( V_19 ) ;
F_29 ( & V_19 -> V_53 ) ;
return;
}
if ( ( V_6 -> V_15 != V_48 ) &&
( V_170 -> V_176 . V_93 . V_192 & V_196 ) &&
( V_170 -> V_176 . V_93 . V_197 != 0 ) ) {
V_86 = (struct V_30 * ) F_132 ( ( V_81 ) V_170 -> V_176 . V_93 . V_197 )
- V_6 -> V_29 ;
if ( ( V_170 -> V_176 . V_93 . V_193 & V_198 ) ||
( V_170 -> V_176 . V_93 . V_173 & V_199 ) )
V_86 = ( V_86 - 1 ) & ( V_9 - 1 ) ;
while ( V_6 -> V_49 != V_86 ) {
F_67 ( V_6 ,
V_6 -> V_10 + V_6 -> V_49 ) ;
V_6 -> V_49 =
( V_6 -> V_49 + 1 ) & ( V_9 - 1 ) ;
}
}
if ( ( V_170 -> V_176 . V_93 . V_172 & V_200 ) ||
( V_170 -> V_176 . V_93 . V_172 & V_201 ) ||
( V_170 -> V_176 . V_93 . V_172 & V_183 ) )
V_6 -> V_15 = V_83 ;
else if ( V_170 -> V_176 . V_93 . V_193 & V_198 )
V_6 -> V_15 = V_89 ;
if ( V_170 -> V_176 . V_93 . V_192 & V_202 ) {
if ( V_170 -> V_176 . V_93 . V_203 != 0 ) {
F_57 ( V_6 -> V_77 , ( V_81 ) V_6 ) ;
return;
}
V_6 -> V_15 = V_84 ;
}
if ( V_170 -> V_176 . V_93 . V_192 & V_204 )
V_6 -> V_15 = V_82 ;
F_133 ( & V_6 -> V_17 ) ;
}
static void
V_52 ( unsigned long V_11 )
{
unsigned long V_34 ;
struct V_5 * V_6 ;
struct V_85 * V_10 ;
int V_50 ;
V_6 = (struct V_5 * ) V_11 ;
F_39 ( 5 , V_62 , L_86 , F_50 ( & V_6 -> V_77 -> V_76 ) ) ;
V_10 = V_6 -> V_10 ;
V_50 = V_6 -> V_50 ;
while ( V_10 [ V_50 ] . V_15 == V_91 ) {
if ( V_10 [ V_50 ] . V_43 != NULL )
V_10 [ V_50 ] . V_43 ( V_6 , V_10 + V_50 ) ;
V_50 = ( V_50 + 1 ) & ( V_9 - 1 ) ;
}
V_6 -> V_50 = V_50 ;
if ( V_6 -> V_15 == V_83 )
F_49 ( V_6 ) ;
F_27 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
if ( V_6 -> V_15 == V_89 &&
V_6 -> V_10 [ V_6 -> V_49 ] . V_15 == V_45 )
F_62 ( V_6 ) ;
F_28 ( F_51 ( V_6 -> V_77 ) , V_34 ) ;
F_29 ( & V_6 -> V_53 ) ;
}
static void
F_134 ( struct V_18 * V_19 )
{
F_9 ( 5 , V_62 , L_87 ) ;
* ( V_94 * ) ( V_19 -> V_65 -> V_11 + V_19 -> V_65 -> V_33 ) = 0 ;
V_19 -> V_65 -> V_33 += 2 ;
F_65 ( & V_19 -> V_27 , V_19 -> V_65 ) ;
V_19 -> V_65 = NULL ;
V_19 -> V_66 ++ ;
}
static void
F_135 ( struct V_5 * V_6 , struct V_85 * V_88 )
{
struct V_18 * V_19 ;
F_9 ( 5 , V_62 , L_88 ) ;
F_68 ( V_6 , V_88 ) ;
V_19 = F_136 ( V_6 , struct V_18 , V_27 ) ;
if ( F_137 ( V_19 -> V_76 ) && F_138 ( V_19 -> V_76 ) )
F_121 ( V_19 -> V_76 ) ;
F_79 ( & V_19 -> V_67 ) ;
V_19 -> V_66 -- ;
if ( V_19 -> V_66 <= 0 && V_19 -> V_65 != NULL )
F_134 ( V_19 ) ;
F_82 ( & V_19 -> V_67 ) ;
}
static int
F_139 ( struct V_18 * V_19 , struct V_205 * V_206 ,
struct V_153 * V_76 )
{
struct V_40 * V_207 ;
int V_20 = V_208 ;
F_9 ( 5 , V_62 , L_89 ) ;
if ( V_206 == NULL ) {
V_19 -> V_209 . V_210 ++ ;
V_19 -> V_209 . V_211 ++ ;
return V_208 ;
}
if ( V_19 -> V_15 != V_165 ) {
F_140 ( V_206 ) ;
V_19 -> V_209 . V_210 ++ ;
V_19 -> V_209 . V_211 ++ ;
V_19 -> V_209 . V_212 ++ ;
return V_208 ;
}
if ( V_206 -> V_213 == F_141 ( V_214 ) ) {
F_140 ( V_206 ) ;
return V_208 ;
}
F_142 ( V_19 -> V_76 ) ;
F_79 ( & V_19 -> V_67 ) ;
if ( V_19 -> V_65 != NULL &&
V_19 -> V_65 -> V_33 + sizeof( struct V_40 ) +
V_206 -> V_215 + sizeof( V_216 ) > V_12 )
F_134 ( V_19 ) ;
if ( V_19 -> V_65 == NULL ) {
V_19 -> V_65 = F_61 ( & V_19 -> V_27 ) ;
if ( V_19 -> V_65 == NULL ) {
V_19 -> V_209 . V_210 ++ ;
V_20 = V_217 ;
goto V_164;
}
V_19 -> V_65 -> V_43 = F_135 ;
V_19 -> V_65 -> V_33 = 0 ;
}
V_207 = (struct V_40 * )
( V_19 -> V_65 -> V_11 + V_19 -> V_65 -> V_33 ) ;
V_19 -> V_65 -> V_33 += V_206 -> V_215 + sizeof( struct V_40 ) ;
V_207 -> V_41 = V_19 -> V_65 -> V_33 ;
V_207 -> type = V_19 -> V_21 ;
V_207 -> V_96 = V_19 -> V_130 ;
F_143 ( V_206 , V_207 + 1 , V_206 -> V_215 ) ;
F_82 ( & V_19 -> V_67 ) ;
V_19 -> V_209 . V_218 += V_206 -> V_215 ;
V_19 -> V_209 . V_219 ++ ;
F_140 ( V_206 ) ;
F_121 ( V_19 -> V_76 ) ;
F_79 ( & V_19 -> V_67 ) ;
if ( V_19 -> V_66 <= 0 && V_19 -> V_65 != NULL )
F_134 ( V_19 ) ;
V_164:
F_82 ( & V_19 -> V_67 ) ;
return V_20 ;
}
static int
F_144 ( struct V_205 * V_206 , struct V_153 * V_76 )
{
struct V_18 * V_19 ;
int V_20 ;
F_9 ( 5 , V_62 , L_90 ) ;
V_19 = (struct V_18 * ) V_76 -> V_166 ;
V_20 = F_139 ( V_19 , V_206 , V_76 ) ;
return V_20 ;
}
static int
F_145 ( struct V_18 * V_19 )
{
int V_20 ;
F_9 ( 2 , V_62 , L_91 ) ;
#ifdef F_146
V_19 -> V_21 = V_220 ;
V_20 = F_98 ( V_19 , V_123 ) ;
if ( V_20 == 0 )
return 0 ;
#endif
#ifdef F_147
V_19 -> V_21 = V_221 ;
V_20 = F_98 ( V_19 , V_123 ) ;
if ( V_20 == 0 )
return 0 ;
#endif
return - V_116 ;
}
static int
F_148 ( struct V_18 * V_19 )
{
int V_20 , V_222 ;
F_9 ( 2 , V_62 , L_92 ) ;
V_20 = 0 ;
if ( V_19 -> V_130 != V_223 ) {
if ( V_19 -> V_21 == V_22 )
V_20 = F_145 ( V_19 ) ;
else
V_20 = F_98 ( V_19 , V_123 ) ;
} else {
for ( V_222 = 0 ; V_222 <= 16 ; V_222 ++ ) {
V_19 -> V_130 = V_222 ;
if ( V_19 -> V_21 != V_22 )
V_20 = F_98 ( V_19 ,
V_123 ) ;
else
V_20 = F_145 ( V_19 ) ;
if ( V_20 == 0 )
break;
}
}
if ( V_20 == 0 )
return F_95 ( V_19 ) ;
return V_20 ;
}
static int
F_149 ( struct V_18 * V_19 )
{
int V_20 = 0 ;
F_9 ( 2 , V_8 , L_93 ) ;
if ( V_19 -> V_76 )
F_142 ( V_19 -> V_76 ) ;
V_20 = F_59 ( V_19 ) ;
if ( V_20 == 0 ) {
V_20 = F_58 ( V_19 ) ;
if ( V_20 == 0 ) {
V_20 = F_92 ( V_19 , V_123 ) ;
if ( V_20 == 0 )
V_20 = F_148 ( V_19 ) ;
}
}
if ( V_20 == 0 ) {
V_19 -> V_15 = V_165 ;
} else {
V_19 -> V_15 = V_64 ;
V_19 -> V_27 . V_15 = V_48 ;
V_19 -> V_26 . V_15 = V_48 ;
}
return V_20 ;
}
static int
F_150 ( struct V_18 * V_19 )
{
int V_20 ;
F_9 ( 3 , V_8 , L_94 ) ;
if ( V_19 -> V_26 . V_15 != V_83 &&
V_19 -> V_27 . V_15 != V_83 &&
V_19 -> V_26 . V_15 != V_195 &&
V_19 -> V_27 . V_15 != V_195 &&
V_19 -> V_15 == V_165 ) {
F_42 ( V_19 ) ;
V_20 = F_96 ( V_19 , V_123 ) ;
V_20 = F_93 ( V_19 ) ;
}
V_20 = F_59 ( V_19 ) ;
V_19 -> V_15 = V_64 ;
return V_20 ;
}
static void
F_151 ( struct V_224 * V_225 )
{
struct V_18 * V_19 = F_136 ( V_225 , struct V_18 , V_167 ) ;
F_9 ( 5 , V_62 , L_95 ) ;
if ( F_38 ( V_19 , V_190 ) )
F_152 ( V_226 , V_19 , L_96 ) ;
#ifdef F_18
if ( F_38 ( V_19 , V_163 ) )
F_152 ( F_113 , V_19 , L_97 ) ;
#endif
}
static void
F_153 ( struct V_18 * V_19 , struct V_92 * V_93 )
{
F_9 ( 5 , V_62 , L_98 ) ;
if ( V_93 -> V_117 == V_227 ) {
switch( V_93 -> V_31 ) {
case V_119 :
case V_132 :
F_129 ( V_19 ) ;
break;
case V_131 :
F_154 ( L_99 ,
V_19 -> V_76 -> V_228 ) ;
if ( V_19 -> V_76 )
F_118 ( V_19 -> V_76 ) ;
break;
default:
F_9 ( 5 , V_62 , L_100 ) ;
break;
}
} else
F_78 ( V_19 , V_93 ) ;
}
static void
F_155 ( struct V_18 * V_19 , char * V_229 , unsigned int V_230 )
{
struct V_205 * V_206 ;
F_9 ( 5 , V_62 , L_101 ) ;
if ( V_19 -> V_76 == NULL ||
V_19 -> V_15 != V_165 )
return;
V_206 = F_156 ( V_230 ) ;
if ( V_206 == NULL ) {
F_53 ( & V_19 -> V_76 -> V_76 ,
L_102 ,
V_19 -> V_76 -> V_228 ) ;
V_19 -> V_209 . V_231 ++ ;
return;
}
memcpy ( F_157 ( V_206 , V_230 ) , V_229 , V_230 ) ;
V_206 -> V_213 = V_19 -> V_232 ( V_206 , V_19 -> V_76 ) ;
V_19 -> V_209 . V_233 += V_230 ;
V_19 -> V_209 . V_234 ++ ;
if ( V_206 -> V_213 == F_141 ( V_235 ) )
* ( ( V_39 * ) V_206 -> V_236 ) = ++ V_19 -> V_23 ;
F_158 ( V_206 ) ;
}
static void
V_44 ( struct V_5 * V_6 , struct V_85 * V_88 )
{
struct V_18 * V_19 ;
struct V_40 * V_237 ;
V_94 V_41 ;
F_9 ( 5 , V_62 , L_103 ) ;
V_237 = (struct V_40 * ) V_88 -> V_11 ;
if ( V_237 -> V_41 == V_42 ) {
F_9 ( 4 , V_62 , L_104 ) ;
return;
}
V_19 = F_136 ( V_6 , struct V_18 , V_26 ) ;
V_41 = 0 ;
while ( V_237 -> V_41 != 0 ) {
if ( V_237 -> V_41 <= 0 ||
V_237 -> V_41 > V_12 ||
V_237 -> V_41 < V_41 ) {
V_19 -> V_209 . V_238 ++ ;
V_19 -> V_209 . V_239 ++ ;
return;
}
if ( V_237 -> type == V_95 )
F_153 ( V_19 , (struct V_92 * ) V_237 ) ;
else if ( V_237 -> type == V_220 ||
V_237 -> type == V_240 ||
V_237 -> type == V_221 )
F_155 ( V_19 , ( char * ) ( V_237 + 1 ) ,
V_237 -> V_41 - V_41 -
sizeof( struct V_40 ) ) ;
else
;
V_41 = V_237 -> V_41 ;
V_237 -> V_41 = V_42 ;
V_237 = (struct V_40 * ) ( V_88 -> V_11 + V_41 ) ;
}
F_65 ( & V_19 -> V_26 , V_88 ) ;
}
static struct V_241 *
F_159 ( struct V_153 * V_76 )
{
struct V_18 * V_19 ;
F_9 ( 4 , V_62 , L_105 ) ;
V_19 = (struct V_18 * ) V_76 -> V_166 ;
return & V_19 -> V_209 ;
}
static int
F_160 ( struct V_153 * V_76 )
{
struct V_18 * V_19 ;
int V_20 ;
F_9 ( 2 , V_62 , L_106 ) ;
V_19 = (struct V_18 * ) V_76 -> V_166 ;
F_118 ( V_76 ) ;
F_119 ( V_76 ) ;
V_76 -> V_34 &= ~ V_242 ;
F_37 ( V_19 -> V_27 . V_53 ,
( V_19 -> V_27 . V_15 != V_80 ) ) ;
V_20 = F_150 ( V_19 ) ;
if ( V_20 )
F_53 ( & V_19 -> V_76 -> V_76 ,
L_107 ) ;
return V_20 ;
}
static int
F_161 ( struct V_153 * V_76 )
{
struct V_18 * V_19 ;
int V_20 ;
F_9 ( 2 , V_62 , L_108 ) ;
V_19 = (struct V_18 * ) V_76 -> V_166 ;
V_20 = F_149 ( V_19 ) ;
if ( V_20 ) {
F_5 ( L_109 ) ;
} else {
V_76 -> V_34 |= V_242 ;
F_120 ( V_76 ) ;
F_121 ( V_76 ) ;
V_19 -> V_15 = V_165 ;
}
return V_20 ;
}
static T_3
F_162 ( struct V_243 * V_76 , struct V_244 * V_245 , char * V_158 )
{
struct V_18 * V_19 ;
V_19 = F_163 ( V_76 ) ;
if ( ! V_19 )
return 0 ;
return sprintf ( V_158 , L_110 , V_19 -> V_130 ) ;
}
static T_3
F_164 ( struct V_243 * V_76 , struct V_244 * V_245 , const char * V_158 , T_4 V_33 )
{
struct V_18 * V_19 ;
int V_20 ;
T_5 V_246 ;
V_19 = F_163 ( V_76 ) ;
if ( ! V_19 )
return 0 ;
V_20 = F_165 ( V_158 , 0 , & V_246 ) ;
if ( V_20 )
return - V_247 ;
V_19 -> V_130 = V_246 ;
return V_33 ;
}
static T_3
F_166 ( struct V_243 * V_76 , struct V_244 * V_245 , char * V_158 )
{
struct V_248 * V_249 ;
V_249 = F_167 ( V_76 ) ;
if ( ! V_249 )
return - V_250 ;
return sprintf ( V_158 , L_111 , V_251 [ V_249 -> V_169 [ 0 ] -> V_252 . V_253 ] ) ;
}
static T_3
F_168 ( struct V_243 * V_76 , struct V_244 * V_245 , char * V_158 )
{
struct V_18 * V_19 ;
V_19 = F_163 ( V_76 ) ;
return V_19 ? sprintf ( V_158 , L_112 , V_19 -> V_24 ) : 0 ;
}
static T_3
F_169 ( struct V_243 * V_76 , struct V_244 * V_245 , const char * V_158 , T_4 V_33 )
{
struct V_18 * V_19 ;
unsigned int V_246 ;
int V_20 ;
V_19 = F_163 ( V_76 ) ;
if ( ! V_19 )
return 0 ;
V_20 = F_170 ( V_158 , 0 , & V_246 ) ;
if ( V_20 )
return - V_247 ;
V_19 -> V_24 = V_246 ;
return V_33 ;
}
static T_3
F_171 ( struct V_243 * V_76 , struct V_244 * V_245 ,
const char * V_158 , T_4 V_33 )
{
struct V_18 * V_19 = F_163 ( V_76 ) ;
char * V_149 ;
int V_222 ;
if ( ! V_19 )
return - V_247 ;
if ( V_19 -> V_15 != V_165 )
return - V_61 ;
V_222 = F_172 ( V_158 , & V_149 , 16 ) ;
if ( V_222 == 1 )
F_129 ( V_19 ) ;
return V_33 ;
}
static int
F_173 ( struct V_248 * V_254 )
{
struct V_18 * V_19 ;
if ( ! F_174 ( & V_254 -> V_76 ) )
return - V_250 ;
F_9 ( 2 , V_8 , L_113 ) ;
V_19 = F_17 () ;
if ( ! V_19 ) {
F_39 ( 2 , V_8 , L_72 , - V_3 ) ;
F_175 ( & V_254 -> V_76 ) ;
return - V_3 ;
}
F_176 ( & V_254 -> V_76 , V_19 ) ;
V_254 -> V_169 [ 0 ] -> V_255 = F_130 ;
V_254 -> V_169 [ 1 ] -> V_255 = F_130 ;
V_19 -> V_256 = V_254 ;
F_177 ( & V_19 -> V_167 , F_151 ) ;
V_19 -> V_60 = 0 ;
V_19 -> V_57 = 0 ;
V_19 -> V_58 = 0 ;
V_254 -> V_76 . type = & V_257 ;
return 0 ;
}
static int
F_178 ( struct V_248 * V_254 )
{
struct V_18 * V_19 ;
F_9 ( 2 , V_8 , L_114 ) ;
V_19 = F_163 ( & V_254 -> V_76 ) ;
if ( V_19 -> V_76 -> V_258 != V_259 )
return 0 ;
F_179 ( V_19 -> V_76 , & V_254 -> V_76 ) ;
return F_180 ( V_19 -> V_76 ) ;
}
static int
F_181 ( struct V_248 * V_254 )
{
struct V_18 * V_19 ;
struct V_153 * V_76 = NULL ;
enum V_260 V_261 ;
int V_20 ;
V_19 = F_163 ( & V_254 -> V_76 ) ;
if ( ! V_19 )
return - V_250 ;
F_9 ( 2 , V_8 , L_115 ) ;
F_16 ( 3 , V_8 , & V_19 , sizeof( void * ) ) ;
V_19 -> V_26 . V_77 = V_254 -> V_169 [ 0 ] ;
V_19 -> V_27 . V_77 = V_254 -> V_169 [ 1 ] ;
V_261 = V_19 -> V_15 ;
V_20 = F_182 ( V_19 -> V_26 . V_77 ) ;
if ( V_20 )
goto V_262;
V_20 = F_182 ( V_19 -> V_27 . V_77 ) ;
if ( V_20 )
goto V_263;
F_9 ( 3 , V_8 , L_116 ) ;
F_40 ( V_19 ) ;
V_20 = F_149 ( V_19 ) ;
if ( V_20 ) {
F_9 ( 2 , V_8 , L_117 ) ;
F_53 ( & V_19 -> V_76 -> V_76 ,
L_118
L_119 , V_20 , V_20 ) ;
F_150 ( V_19 ) ;
goto V_164;
}
if ( V_19 -> V_76 ) {
F_9 ( 2 , V_8 , L_120 ) ;
F_16 ( 3 , V_8 , & V_19 , sizeof( void * ) ) ;
goto V_264;
}
switch ( V_19 -> V_21 ) {
#ifdef F_146
case V_220 :
V_19 -> V_232 = V_265 ;
V_76 = F_183 ( 0 ) ;
break;
#endif
#ifdef F_147
case V_221 :
V_19 -> V_232 = V_266 ;
V_76 = F_184 ( 0 ) ;
break;
#endif
default:
F_9 ( 3 , V_8 , L_121 ) ;
F_5 ( L_122 ) ;
goto V_164;
}
if ( ! V_76 )
goto V_164;
V_19 -> V_76 = V_76 ;
V_19 -> V_76 -> V_166 = V_19 ;
V_19 -> V_76 -> V_267 = & V_268 ;
memcpy ( V_19 -> V_76 -> V_269 , V_19 -> V_124 , V_127 ) ;
#ifdef F_18
if ( ! F_101 ( V_19 ) )
V_19 -> V_76 -> V_267 = & V_270 ;
#endif
V_264:
F_26 ( V_19 , 0xffffffff ) ;
if ( V_261 == V_271 ) {
F_122 ( V_19 -> V_76 ) ;
V_19 -> V_76 -> V_34 |= V_242 ;
F_120 ( V_19 -> V_76 ) ;
F_121 ( V_19 -> V_76 ) ;
V_19 -> V_15 = V_165 ;
} else {
F_150 ( V_19 ) ;
}
if ( F_178 ( V_254 ) != 0 )
goto V_164;
F_103 ( L_123 , V_19 -> V_76 -> V_228 ,
( V_19 -> V_143 & V_272 ) ?
L_124 : L_125 ) ;
F_103 ( L_126 , V_19 -> V_76 -> V_228 ,
( V_19 -> V_143 & V_147 ) ?
L_124 : L_125 ) ;
return 0 ;
V_164:
F_185 ( V_19 -> V_27 . V_77 ) ;
V_263:
F_185 ( V_19 -> V_26 . V_77 ) ;
V_262:
return - V_250 ;
}
static int
F_186 ( struct V_248 * V_254 , int V_273 )
{
struct V_18 * V_19 ;
enum V_260 V_261 ;
int V_274 = 0 , V_275 = 0 , V_276 = 0 ;
F_9 ( 3 , V_8 , L_127 ) ;
V_19 = F_163 ( & V_254 -> V_76 ) ;
if ( ! V_19 )
return - V_250 ;
if ( V_273 == 0 ) {
F_26 ( V_19 , 0 ) ;
if ( F_31 ( V_19 , V_163 ) )
return - V_277 ;
}
F_16 ( 3 , V_8 , & V_19 , sizeof( void * ) ) ;
V_261 = V_19 -> V_15 ;
V_274 = F_160 ( V_19 -> V_76 ) ;
V_275 = F_185 ( V_19 -> V_26 . V_77 ) ;
V_276 = F_185 ( V_19 -> V_27 . V_77 ) ;
if ( ! V_274 )
V_274 = ( V_275 ) ? V_275 : V_276 ;
if ( V_274 )
F_39 ( 3 , V_8 , L_128 , V_274 ) ;
if ( V_261 == V_165 ) {
V_19 -> V_15 = V_271 ;
}
return 0 ;
}
static int
F_187 ( struct V_248 * V_254 )
{
return F_186 ( V_254 , 0 ) ;
}
static int
V_226 ( void * V_278 )
{
struct V_18 * V_19 ;
struct V_248 * V_256 ;
int V_20 ;
V_19 = (struct V_18 * ) V_278 ;
F_9 ( 4 , V_62 , L_129 ) ;
if ( ! F_36 ( V_19 , V_190 ) )
return 0 ;
F_9 ( 4 , V_62 , L_130 ) ;
V_256 = V_19 -> V_256 ;
F_127 ( & V_256 -> V_76 ,
L_131 ) ;
V_20 = F_186 ( V_256 , 1 ) ;
V_20 = F_181 ( V_256 ) ;
if ( ! V_20 )
F_103 ( L_132 ,
V_19 -> V_76 -> V_228 ) ;
else
F_103 ( L_133 ,
V_19 -> V_76 -> V_228 ) ;
F_34 ( V_19 , V_190 ) ;
return 0 ;
}
static void
F_188 ( struct V_248 * V_254 )
{
struct V_18 * V_19 ;
V_19 = F_163 ( & V_254 -> V_76 ) ;
if ( ! V_19 )
return;
F_9 ( 3 , V_8 , L_134 ) ;
F_16 ( 3 , V_8 , & V_19 , sizeof( void * ) ) ;
if ( V_254 -> V_15 == V_279 ) {
F_187 ( V_254 ) ;
}
if ( V_19 -> V_76 )
F_189 ( V_19 -> V_76 ) ;
F_47 ( V_19 ) ;
F_15 ( V_19 ) ;
F_176 ( & V_254 -> V_76 , NULL ) ;
F_175 ( & V_254 -> V_76 ) ;
}
static int F_190 ( struct V_18 * V_19 )
{
if ( V_19 -> V_76 )
F_191 ( V_19 -> V_76 ) ;
F_26 ( V_19 , 0 ) ;
F_31 ( V_19 , 0xffffffff ) ;
if ( V_19 -> V_15 != V_64 )
F_186 ( V_19 -> V_256 , 1 ) ;
return 0 ;
}
static int F_192 ( struct V_18 * V_19 )
{
int V_20 = 0 ;
if ( V_19 -> V_15 == V_271 )
V_20 = F_181 ( V_19 -> V_256 ) ;
if ( V_19 -> V_76 )
F_193 ( V_19 -> V_76 ) ;
if ( V_20 ) {
F_127 ( & V_19 -> V_256 -> V_76 , L_135
L_136 ) ;
}
return V_20 ;
}
static int F_194 ( struct V_248 * V_256 )
{
return 0 ;
}
static void F_195 ( struct V_248 * V_256 )
{
return;
}
static int F_196 ( struct V_248 * V_256 )
{
struct V_18 * V_19 = F_163 ( & V_256 -> V_76 ) ;
return F_190 ( V_19 ) ;
}
static int F_197 ( struct V_248 * V_256 )
{
struct V_18 * V_19 = F_163 ( & V_256 -> V_76 ) ;
return F_192 ( V_19 ) ;
}
static int F_198 ( struct V_248 * V_256 )
{
struct V_18 * V_19 = F_163 ( & V_256 -> V_76 ) ;
return F_192 ( V_19 ) ;
}
static T_3 F_199 ( struct V_280 * V_281 ,
const char * V_158 , T_4 V_33 )
{
int V_282 ;
V_282 = F_200 ( V_283 , & V_284 , 2 , V_158 ) ;
return V_282 ? V_282 : V_33 ;
}
static int
T_6 F_201 ( void )
{
int V_20 ;
F_103 ( L_137 , V_136 ) ;
V_20 = F_3 () ;
F_9 ( 0 , V_8 , L_138 ) ;
if ( V_20 )
goto V_262;
V_283 = F_202 ( L_139 ) ;
V_20 = F_203 ( V_283 ) ;
if ( V_20 )
goto V_285;
V_20 = F_204 ( & V_286 ) ;
if ( V_20 )
goto V_287;
V_284 . V_288 . V_289 = V_290 ;
V_20 = F_205 ( & V_284 ) ;
if ( V_20 )
goto V_291;
return 0 ;
V_291:
F_206 ( & V_286 ) ;
V_287:
F_207 ( V_283 ) ;
V_285:
F_1 () ;
V_262:
F_5 ( L_140 ) ;
return V_20 ;
}
static void
T_7 F_208 ( void )
{
F_103 ( L_141 ) ;
F_9 ( 0 , V_62 , L_142 ) ;
F_209 ( & V_284 ) ;
F_206 ( & V_286 ) ;
F_207 ( V_283 ) ;
F_1 () ;
}
