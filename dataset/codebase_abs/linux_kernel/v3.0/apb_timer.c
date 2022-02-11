static inline unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned long V_3 , unsigned long V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline unsigned long F_5 ( int V_4 , unsigned long V_1 )
{
return F_2 ( V_2 + V_1 + V_4 * V_5 ) ;
}
static inline void F_6 ( int V_4 , unsigned long V_3 , unsigned long V_1 )
{
F_4 ( V_3 , V_2 + V_1 + V_4 * V_5 ) ;
}
static inline void F_7 ( void )
{
struct V_6 * V_7 ;
if ( V_2 ) {
F_8 ( L_1 ) ;
return;
}
V_7 = F_9 ( V_8 ) ;
if ( V_7 == NULL ) {
F_10 ( V_9 L_2 ,
V_8 ) ;
return;
}
V_10 = ( unsigned long ) V_7 -> V_11 ;
if ( ! V_10 ) {
F_10 ( V_12 L_3 ) ;
V_10 = V_13 ;
}
V_2 = F_11 ( V_10 , V_14 ) ;
if ( V_2 ) {
F_8 ( L_4 ,\
( void * ) V_10 , ( void * ) V_2 ) ;
} else {
F_8 ( L_5 ,\
( void * ) V_10 ) ;
goto V_15;
}
V_16 = V_7 -> V_17 / V_18 ;
F_12 ( V_7 ) ;
V_7 = F_9 ( V_19 ) ;
if ( V_7 == NULL )
goto V_15;
V_20 = ( unsigned int ) ( V_7 -> V_11 & 0xff )
/ V_5 ;
F_8 ( L_6 , V_20 ) ;
return;
V_15:
F_13 ( L_7 ) ;
}
static inline void F_14 ( void )
{
F_15 ( V_2 ) ;
V_2 = NULL ;
}
static inline int F_16 ( void )
{
return V_2 ? 1 : 0 ;
}
static void F_17 ( int V_4 )
{
unsigned long V_21 = F_5 ( V_4 , V_22 ) ;
V_21 &= ~ V_23 ;
F_6 ( V_4 , V_21 , V_22 ) ;
F_6 ( V_4 , ~ 0 , V_24 ) ;
V_21 &= ~ V_25 ;
V_21 |= ( V_23 | V_26 ) ;
F_6 ( V_4 , V_21 , V_22 ) ;
F_18 ( & V_27 ) ;
}
static T_1 F_19 ( int V_28 , void * V_29 )
{
struct V_30 * V_31 = (struct V_30 * ) V_29 ;
struct V_32 * V_33 = & V_31 -> V_34 ;
if ( ! V_33 -> V_35 ) {
F_10 ( V_36 L_8 ,
V_31 -> V_37 ) ;
return V_38 ;
}
V_33 -> V_35 ( V_33 ) ;
return V_39 ;
}
static void F_20 ( struct V_40 * V_41 )
{
F_17 ( V_20 ) ;
}
static void F_21 ( int V_4 )
{
unsigned long V_21 = F_5 ( V_4 , V_22 ) ;
F_5 ( V_4 , V_42 ) ;
V_21 &= ~ V_26 ;
F_6 ( V_4 , V_21 , V_22 ) ;
}
static void F_22 ( int V_4 )
{
unsigned long V_21 = F_5 ( V_4 , V_22 ) ;
V_21 |= V_26 ;
F_6 ( V_4 , V_21 , V_22 ) ;
}
static int T_2 F_23 ( void )
{
struct V_6 * V_7 ;
struct V_30 * V_43 = & F_24 ( V_44 ) ;
V_7 = F_9 ( V_8 ) ;
if ( V_7 == NULL ) {
F_10 ( V_9 L_2 ,
V_8 ) ;
return - V_45 ;
}
V_46 . V_47 = F_25 ( ( unsigned long ) V_7 -> V_17
, V_48 , V_49 ) ;
V_46 . V_50 = F_26 ( 0x7FFFFFFF ,
& V_46 ) ;
V_46 . V_51 = F_26 (
V_52 * V_16 ,
& V_46 ) ;
V_46 . V_53 = F_27 ( F_28 () ) ;
V_43 -> V_37 = F_28 () ;
memcpy ( & V_43 -> V_34 , & V_46 , sizeof( struct V_32 ) ) ;
if ( V_54 == V_55 ) {
V_43 -> V_34 . V_56 = V_57 - 100 ;
V_58 = & V_43 -> V_34 ;
F_10 ( V_59 L_9 ,
V_58 -> V_60 ) ;
}
if ( F_29 ( V_46 . V_28 , F_19 ,
V_61 | V_62 | V_63 ,
V_46 . V_60 , V_43 ) ) {
F_10 ( V_9 L_10 ,
V_46 . V_28 ) ;
}
F_30 ( & V_43 -> V_34 ) ;
F_21 ( V_8 ) ;
F_12 ( V_7 ) ;
return 0 ;
}
static void F_31 ( struct V_30 * V_43 )
{
if ( V_43 -> V_28 == 0 )
return;
F_32 ( V_43 -> V_28 , 0 , V_64 ) ;
F_33 ( V_43 -> V_28 , F_27 ( V_43 -> V_65 ) ) ;
F_34 ( V_43 -> V_28 , V_66 , 0 , L_11 ) ;
if ( V_67 == V_68 ) {
if ( F_29 ( V_43 -> V_28 , F_19 ,
V_61 | V_62 |
V_63 ,
V_43 -> V_60 , V_43 ) ) {
F_10 ( V_9 L_10 ,
V_43 -> V_37 ) ;
}
} else
F_35 ( V_43 -> V_28 ) ;
}
void F_36 ( void )
{
struct V_30 * V_43 ;
struct V_32 * V_33 ;
int V_65 ;
V_65 = F_28 () ;
if ( ! V_65 )
return;
F_10 ( V_36 L_12 , V_65 ) ;
V_43 = & F_37 ( V_44 , V_65 ) ;
V_33 = & V_43 -> V_34 ;
memcpy ( V_33 , & V_46 , sizeof( * V_33 ) ) ;
V_33 -> V_53 = F_27 ( V_65 ) ;
V_33 -> V_60 = V_43 -> V_60 ;
V_33 -> V_69 = V_70 ;
F_10 ( V_36 L_13 ,
V_65 , V_33 -> V_60 , * ( V_71 * ) V_33 -> V_53 ) ;
F_31 ( V_43 ) ;
F_30 ( V_33 ) ;
F_21 ( V_65 ) ;
return;
}
static int F_38 ( struct V_72 * V_4 ,
unsigned long V_73 , void * V_74 )
{
unsigned long V_65 = ( unsigned long ) V_74 ;
struct V_30 * V_43 = & F_37 ( V_44 , V_65 ) ;
switch ( V_73 & 0xf ) {
case V_75 :
F_39 ( V_43 -> V_28 ) ;
F_22 ( V_65 ) ;
if ( V_67 == V_76 ) {
F_8 ( L_14 , V_65 ) ;
} else if ( V_43 ) {
F_8 ( L_15 , V_65 ) ;
F_40 ( V_43 -> V_28 , V_43 ) ;
}
break;
default:
F_8 ( L_16 , V_73 ) ;
}
return V_77 ;
}
static T_2 int F_41 ( void )
{
if ( V_54 == V_55 ||
! V_78 )
return 0 ;
F_42 ( F_38 , - 20 ) ;
return 0 ;
}
void F_36 ( void ) {}
static void F_43 ( enum V_79 V_69 ,
struct V_32 * V_34 )
{
unsigned long V_21 ;
T_3 V_80 ;
int V_81 ;
struct V_30 * V_43 = F_44 ( V_34 ) ;
F_45 ( ! V_2 ) ;
V_81 = V_43 -> V_37 ;
F_8 ( L_17 ,
V_82 , F_46 ( * V_34 -> V_53 ) , V_81 , V_69 ) ;
switch ( V_69 ) {
case V_83 :
V_80 = ( ( T_3 ) ( V_48 / V_84 ) ) * V_46 . V_47 ;
V_80 >>= V_46 . V_85 ;
V_21 = F_5 ( V_81 , V_22 ) ;
V_21 |= V_25 ;
F_6 ( V_81 , V_21 , V_22 ) ;
V_21 &= ~ V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
F_47 ( 1 ) ;
F_8 ( L_18 , ( int ) V_80 , V_84 ) ;
F_6 ( V_81 , V_80 , V_24 ) ;
V_21 |= V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
break;
case V_86 :
V_21 = F_5 ( V_81 , V_22 ) ;
V_21 &= ~ V_23 ;
V_21 &= ~ V_25 ;
F_6 ( V_81 , V_21 , V_22 ) ;
F_6 ( V_81 , V_21 , V_22 ) ;
F_6 ( V_81 , ~ 0 , V_24 ) ;
V_21 &= ~ V_26 ;
V_21 |= V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
break;
case V_70 :
case V_87 :
F_22 ( V_81 ) ;
V_21 = F_5 ( V_81 , V_22 ) ;
V_21 &= ~ V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
break;
case V_88 :
F_21 ( V_81 ) ;
break;
}
}
static int F_48 ( unsigned long V_80 ,
struct V_32 * V_34 )
{
unsigned long V_21 ;
int V_81 ;
struct V_30 * V_43 = F_44 ( V_34 ) ;
V_81 = V_43 -> V_37 ;
V_21 = F_5 ( V_81 , V_22 ) ;
V_21 &= ~ V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
F_6 ( V_81 , V_80 , V_24 ) ;
V_21 |= V_23 ;
F_6 ( V_81 , V_21 , V_22 ) ;
return 0 ;
}
static T_4 F_18 ( struct V_40 * V_41 )
{
unsigned long V_89 ;
V_89 = F_5 ( V_20 , V_90 ) ;
return ( T_4 ) ~ V_89 ;
}
static int F_49 ( void )
{
T_5 V_91 , V_92 ;
T_4 V_93 ;
F_17 ( V_20 ) ;
V_93 = F_18 ( & V_27 ) ;
F_50 ( V_91 ) ;
do {
F_51 () ;
F_50 ( V_92 ) ;
} while ( ( V_92 - V_91 ) < 200000UL );
if ( V_93 == F_18 ( & V_27 ) )
F_13 ( L_19 ) ;
F_52 ( & V_27 , ( V_71 ) V_16 * 1000 ) ;
return 0 ;
}
void T_2 F_53 ( void )
{
#ifdef F_54
int V_94 ;
struct V_6 * V_95 ;
unsigned int V_96 ;
struct V_30 * V_43 ;
#endif
if ( V_78 )
return;
F_7 () ;
if ( V_2 ) {
F_8 ( L_20 ,\
F_1 ( V_97 ) ) ;
} else
goto V_98;
if ( V_16 < V_99 || V_16 > V_100 ) {
F_8 ( L_21 , V_16 ) ;
goto V_98;
}
if ( F_49 () ) {
F_8 ( L_22 ) ;
goto V_98;
}
if ( ! F_23 () )
V_78 = 1 ;
else {
F_8 ( L_23 ) ;
goto V_98;
}
#ifdef F_54
if ( V_54 == V_55 ) {
F_10 ( V_36 L_24 ) ;
return;
}
F_8 ( L_25 , V_82 , F_55 () ) ;
if ( F_56 () <= V_101 ) {
V_96 = 1 ;
V_102 = F_56 () ;
} else {
V_96 = 0 ;
V_102 = 1 ;
V_43 = & F_37 ( V_44 , 0 ) ;
V_43 -> V_103 &= ~ V_104 ;
}
F_8 ( L_26 , V_82 , V_102 ) ;
V_105 = F_57 ( sizeof( struct V_30 ) * V_102 ,
V_106 ) ;
if ( ! V_105 ) {
F_10 ( V_9 L_27 ) ;
return;
}
for ( V_94 = 0 ; V_94 < V_102 ; V_94 ++ ) {
V_43 = & F_37 ( V_44 , V_94 ) ;
V_43 -> V_37 = V_94 ;
V_43 -> V_65 = V_94 ;
V_95 = F_9 ( V_94 ) ;
if ( V_95 ) {
V_43 -> V_107 = V_95 -> V_17 ;
V_43 -> V_28 = V_95 -> V_28 ;
} else
F_10 ( V_9 L_28 , V_94 ) ;
V_43 -> V_108 = 0 ;
sprintf ( V_43 -> V_60 , L_29 , V_94 ) ;
}
#endif
return;
V_98:
F_14 () ;
V_78 = 0 ;
F_13 ( L_30 ) ;
}
static inline void F_58 ( int V_4 )
{
if ( F_16 () ) {
unsigned long V_21 = F_5 ( V_4 , V_22 ) ;
V_21 &= ~ V_23 ;
F_6 ( V_4 , V_21 , V_22 ) ;
}
}
unsigned long F_59 ()
{
int V_94 , V_109 ;
T_5 V_110 , V_111 ;
T_4 V_93 , V_112 ;
unsigned long V_113 = 0 ;
V_71 V_114 , V_85 ;
F_7 () ;
F_17 ( V_20 ) ;
V_110 = F_18 ( & V_27 ) ;
V_94 = 10000 ;
while ( -- V_94 ) {
if ( V_110 != F_18 ( & V_27 ) )
break;
}
if ( ! V_94 )
goto V_115;
V_114 = ( V_16 * 1000 ) << 4 ;
F_17 ( V_20 ) ;
V_110 = F_18 ( & V_27 ) ;
V_110 += V_114 ;
V_93 = F_60 () ;
do {
V_111 = F_18 ( & V_27 ) ;
} while ( V_111 < V_110 );
V_112 = F_60 () ;
V_85 = 5 ;
if ( F_61 ( V_114 >> V_85 == 0 ) ) {
F_10 ( V_36
L_31 ) ;
return 0 ;
}
V_109 = ( int ) F_62 ( ( V_112 - V_93 ) , V_114 >> V_85 ) ;
V_113 = ( V_109 * V_16 * 1000 ) >> V_85 ;
F_10 ( V_36 L_32 , V_113 ) ;
return V_113 ;
V_115:
return 0 ;
}
