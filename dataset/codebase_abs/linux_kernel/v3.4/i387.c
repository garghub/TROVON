static inline bool F_1 ( void )
{
return ! F_2 ( V_1 ) &&
( F_3 () & V_2 ) ;
}
static inline bool F_4 ( void )
{
struct V_3 * V_4 = F_5 () ;
return V_4 && F_6 ( V_4 ) ;
}
bool F_7 ( void )
{
return ! F_8 () ||
F_4 () ||
F_1 () ;
}
void F_9 ( void )
{
struct V_5 * V_6 = V_1 ;
F_10 ( ! F_7 () ) ;
F_11 () ;
if ( F_2 ( V_6 ) ) {
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
} else {
F_14 ( V_7 , NULL ) ;
F_15 () ;
}
}
void F_16 ( void )
{
F_17 () ;
F_18 () ;
}
void F_19 ( struct V_5 * V_8 )
{
F_11 () ;
if ( F_2 ( V_8 ) ) {
F_12 ( V_8 ) ;
F_20 ( V_8 ) ;
} else
V_8 -> V_9 = 0 ;
F_18 () ;
}
static void T_1 F_21 ( void )
{
unsigned long V_10 = 0 ;
F_15 () ;
if ( V_11 ) {
memset ( & V_12 , 0 , sizeof( struct V_13 ) ) ;
asm volatile("fxsave %0" : : "m" (fx_scratch));
V_10 = V_12 . V_14 ;
if ( V_10 == 0 )
V_10 = 0x0000ffbf ;
}
V_15 &= V_10 ;
F_17 () ;
}
static void T_1 F_22 ( void )
{
if ( ! V_16 ) {
F_23 ( V_17 ) ;
F_23 ( V_18 ) ;
V_19 = sizeof( struct V_20 ) ;
return;
}
if ( V_11 )
V_19 = sizeof( struct V_13 ) ;
else
V_19 = sizeof( struct V_21 ) ;
}
void T_1 F_24 ( void )
{
unsigned long V_22 ;
unsigned long V_23 = 0 ;
if ( V_11 )
V_23 |= V_24 ;
if ( V_25 )
V_23 |= V_26 ;
if ( V_23 )
F_25 ( V_23 ) ;
V_22 = F_3 () ;
V_22 &= ~ ( V_2 | V_27 ) ;
if ( ! V_16 )
V_22 |= V_27 ;
F_26 ( V_22 ) ;
if ( ! F_27 () )
F_22 () ;
F_21 () ;
F_28 () -> V_28 = 0 ;
F_29 () ;
}
void F_30 ( struct V_29 * V_29 )
{
if ( ! V_16 ) {
F_31 ( & V_29 -> V_30 -> V_31 ) ;
return;
}
if ( V_11 ) {
struct V_13 * V_32 = & V_29 -> V_30 -> V_33 ;
memset ( V_32 , 0 , V_19 ) ;
V_32 -> V_34 = 0x37f ;
if ( V_25 )
V_32 -> V_35 = V_36 ;
} else {
struct V_21 * V_37 = & V_29 -> V_30 -> V_38 ;
memset ( V_37 , 0 , V_19 ) ;
V_37 -> V_34 = 0xffff037fu ;
V_37 -> V_39 = 0xffff0000u ;
V_37 -> V_40 = 0xffffffffu ;
V_37 -> V_41 = 0xffff0000u ;
}
}
int F_32 ( struct V_5 * V_8 )
{
int V_42 ;
if ( F_33 ( V_8 ) ) {
if ( V_16 && V_8 == V_1 )
F_19 ( V_8 ) ;
V_8 -> V_43 . V_29 . V_44 = ~ 0 ;
return 0 ;
}
V_42 = F_34 ( & V_8 -> V_43 . V_29 ) ;
if ( V_42 )
return V_42 ;
F_30 ( & V_8 -> V_43 . V_29 ) ;
F_35 ( V_8 ) ;
return 0 ;
}
int F_36 ( struct V_5 * V_45 , const struct V_46 * V_47 )
{
return F_33 ( V_45 ) ? V_47 -> V_48 : 0 ;
}
int F_37 ( struct V_5 * V_45 , const struct V_46 * V_47 )
{
return ( V_11 && F_33 ( V_45 ) ) ? V_47 -> V_48 : 0 ;
}
int F_38 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
void * V_51 , void T_2 * V_52 )
{
int V_42 ;
if ( ! V_11 )
return - V_53 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
F_39 ( V_45 ) ;
return F_40 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_33 , 0 , - 1 ) ;
}
int F_41 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
const void * V_51 , const void T_2 * V_52 )
{
int V_42 ;
if ( ! V_11 )
return - V_53 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
F_39 ( V_45 ) ;
V_42 = F_42 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_33 , 0 , - 1 ) ;
V_45 -> V_43 . V_29 . V_30 -> V_33 . V_35 &= V_15 ;
if ( V_54 )
V_45 -> V_43 . V_29 . V_30 -> V_55 . V_56 . V_57 |= V_58 ;
return V_42 ;
}
int F_43 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
void * V_51 , void T_2 * V_52 )
{
int V_42 ;
if ( ! V_54 )
return - V_53 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
memcpy ( & V_45 -> V_43 . V_29 . V_30 -> V_33 . V_59 ,
V_60 , sizeof( V_60 ) ) ;
V_42 = F_40 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_55 , 0 , - 1 ) ;
return V_42 ;
}
int F_44 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
const void * V_51 , const void T_2 * V_52 )
{
int V_42 ;
struct V_61 * V_56 ;
if ( ! V_54 )
return - V_53 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_42 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_55 , 0 , - 1 ) ;
V_45 -> V_43 . V_29 . V_30 -> V_33 . V_35 &= V_15 ;
V_56 = & V_45 -> V_43 . V_29 . V_30 -> V_55 . V_56 ;
V_56 -> V_57 &= V_62 ;
V_56 -> V_63 [ 0 ] = V_56 -> V_63 [ 1 ] = 0 ;
return V_42 ;
}
static inline unsigned short F_45 ( unsigned short V_40 )
{
unsigned int V_64 ;
V_64 = ~ V_40 ;
V_64 = ( V_64 | ( V_64 >> 1 ) ) & 0x5555 ;
V_64 = ( V_64 | ( V_64 >> 1 ) ) & 0x3333 ;
V_64 = ( V_64 | ( V_64 >> 2 ) ) & 0x0f0f ;
V_64 = ( V_64 | ( V_64 >> 4 ) ) & 0x00ff ;
return V_64 ;
}
static inline T_3 F_46 ( struct V_13 * V_33 )
{
struct V_65 * V_66 ;
T_3 V_67 = ( V_33 -> V_39 >> 11 ) & 7 ;
T_3 V_40 = ( unsigned long ) V_33 -> V_40 ;
T_3 V_68 ;
T_3 V_42 = 0xffff0000u ;
int V_69 ;
for ( V_69 = 0 ; V_69 < 8 ; V_69 ++ , V_40 >>= 1 ) {
if ( V_40 & 0x1 ) {
V_66 = F_47 ( V_33 , ( V_69 - V_67 ) & 7 ) ;
switch ( V_66 -> V_70 & 0x7fff ) {
case 0x7fff :
V_68 = V_71 ;
break;
case 0x0000 :
if ( ! V_66 -> V_72 [ 0 ] &&
! V_66 -> V_72 [ 1 ] &&
! V_66 -> V_72 [ 2 ] &&
! V_66 -> V_72 [ 3 ] )
V_68 = V_73 ;
else
V_68 = V_71 ;
break;
default:
if ( V_66 -> V_72 [ 3 ] & 0x8000 )
V_68 = V_74 ;
else
V_68 = V_71 ;
break;
}
} else {
V_68 = V_75 ;
}
V_42 |= V_68 << ( 2 * V_69 ) ;
}
return V_42 ;
}
static void
F_48 ( struct V_76 * V_77 , struct V_5 * V_8 )
{
struct V_13 * V_33 = & V_8 -> V_43 . V_29 . V_30 -> V_33 ;
struct V_78 * V_79 = (struct V_78 * ) & V_77 -> V_80 [ 0 ] ;
struct V_65 * V_81 = (struct V_65 * ) & V_33 -> V_80 [ 0 ] ;
int V_69 ;
V_77 -> V_34 = V_33 -> V_34 | 0xffff0000u ;
V_77 -> V_39 = V_33 -> V_39 | 0xffff0000u ;
V_77 -> V_40 = F_46 ( V_33 ) ;
#ifdef F_49
V_77 -> V_82 = V_33 -> V_83 ;
V_77 -> V_84 = V_33 -> V_85 ;
V_77 -> V_86 = F_50 ( V_8 ) -> V_87 ;
if ( V_8 == V_1 ) {
F_51 ( V_88 , V_77 -> V_41 ) ;
} else {
V_77 -> V_41 = V_8 -> V_43 . V_88 ;
}
V_77 -> V_41 |= 0xffff0000 ;
#else
V_77 -> V_82 = V_33 -> V_82 ;
V_77 -> V_86 = ( V_89 ) V_33 -> V_86 | ( ( T_3 ) V_33 -> V_90 << 16 ) ;
V_77 -> V_84 = V_33 -> V_84 ;
V_77 -> V_41 = V_33 -> V_41 ;
#endif
for ( V_69 = 0 ; V_69 < 8 ; ++ V_69 )
memcpy ( & V_79 [ V_69 ] , & V_81 [ V_69 ] , sizeof( V_79 [ 0 ] ) ) ;
}
static void F_52 ( struct V_5 * V_8 ,
const struct V_76 * V_77 )
{
struct V_13 * V_33 = & V_8 -> V_43 . V_29 . V_30 -> V_33 ;
struct V_78 * V_81 = (struct V_78 * ) & V_77 -> V_80 [ 0 ] ;
struct V_65 * V_79 = (struct V_65 * ) & V_33 -> V_80 [ 0 ] ;
int V_69 ;
V_33 -> V_34 = V_77 -> V_34 ;
V_33 -> V_39 = V_77 -> V_39 ;
V_33 -> V_40 = F_45 ( V_77 -> V_40 ) ;
V_33 -> V_90 = ( V_89 ) ( ( T_3 ) V_77 -> V_86 >> 16 ) ;
#ifdef F_49
V_33 -> V_83 = V_77 -> V_82 ;
V_33 -> V_85 = V_77 -> V_84 ;
#else
V_33 -> V_82 = V_77 -> V_82 ;
V_33 -> V_86 = ( V_77 -> V_86 & 0xffff ) ;
V_33 -> V_84 = V_77 -> V_84 ;
V_33 -> V_41 = V_77 -> V_41 ;
#endif
for ( V_69 = 0 ; V_69 < 8 ; ++ V_69 )
memcpy ( & V_79 [ V_69 ] , & V_81 [ V_69 ] , sizeof( V_81 [ 0 ] ) ) ;
}
int F_53 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
void * V_51 , void T_2 * V_52 )
{
struct V_76 V_77 ;
int V_42 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_16 )
return F_54 ( V_45 , V_47 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_11 ) {
return F_40 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_38 , 0 ,
- 1 ) ;
}
F_39 ( V_45 ) ;
if ( V_51 && V_49 == 0 && V_50 == sizeof( V_77 ) ) {
F_48 ( V_51 , V_45 ) ;
return 0 ;
}
F_48 ( & V_77 , V_45 ) ;
return F_40 ( & V_49 , & V_50 , & V_51 , & V_52 , & V_77 , 0 , - 1 ) ;
}
int F_55 ( struct V_5 * V_45 , const struct V_46 * V_47 ,
unsigned int V_49 , unsigned int V_50 ,
const void * V_51 , const void T_2 * V_52 )
{
struct V_76 V_77 ;
int V_42 ;
V_42 = F_32 ( V_45 ) ;
if ( V_42 )
return V_42 ;
F_39 ( V_45 ) ;
if ( ! V_16 )
return F_56 ( V_45 , V_47 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_11 ) {
return F_42 ( & V_49 , & V_50 , & V_51 , & V_52 ,
& V_45 -> V_43 . V_29 . V_30 -> V_38 , 0 , - 1 ) ;
}
if ( V_49 > 0 || V_50 < sizeof( V_77 ) )
F_48 ( & V_77 , V_45 ) ;
V_42 = F_42 ( & V_49 , & V_50 , & V_51 , & V_52 , & V_77 , 0 , - 1 ) ;
if ( ! V_42 )
F_52 ( V_45 , & V_77 ) ;
if ( V_54 )
V_45 -> V_43 . V_29 . V_30 -> V_55 . V_56 . V_57 |= V_91 ;
return V_42 ;
}
static inline int F_57 ( struct V_92 T_2 * V_93 )
{
struct V_5 * V_8 = V_1 ;
struct V_21 * V_37 = & V_8 -> V_43 . V_29 . V_30 -> V_38 ;
V_37 -> V_28 = V_37 -> V_39 ;
if ( F_58 ( V_93 , V_37 , sizeof( struct V_21 ) ) )
return - 1 ;
return 1 ;
}
static int F_59 ( struct V_92 T_2 * V_93 )
{
struct V_5 * V_8 = V_1 ;
struct V_13 * V_32 = & V_8 -> V_43 . V_29 . V_30 -> V_33 ;
struct V_76 V_77 ;
int V_94 = 0 ;
F_48 ( & V_77 , V_8 ) ;
if ( F_58 ( V_93 , & V_77 , sizeof( V_77 ) ) )
return - 1 ;
V_94 |= F_60 ( V_32 -> V_39 , & V_93 -> V_28 ) ;
V_94 |= F_60 ( V_95 , & V_93 -> V_96 ) ;
if ( V_94 )
return - 1 ;
if ( F_58 ( & V_93 -> V_97 [ 0 ] , V_32 , V_19 ) )
return - 1 ;
return 1 ;
}
static int F_61 ( void T_2 * V_93 )
{
struct V_5 * V_8 = V_1 ;
struct V_92 T_2 * V_32 = V_93 ;
int V_94 = 0 ;
F_39 ( V_8 ) ;
V_8 -> V_43 . V_29 . V_30 -> V_55 . V_56 . V_57 |= V_58 ;
if ( F_59 ( V_32 ) < 0 )
return - 1 ;
V_94 = F_58 ( & V_32 -> V_59 , & V_98 ,
sizeof( struct V_99 ) ) ;
V_94 |= F_60 ( V_100 ,
( V_101 T_2 * ) ( V_93 + V_102
- V_103 ) ) ;
if ( V_94 )
return - 1 ;
return 1 ;
}
int F_62 ( void T_2 * V_93 )
{
struct V_92 T_2 * V_37 = (struct V_92 T_2 * ) V_93 ;
struct V_5 * V_8 = V_1 ;
if ( ! F_63 () )
return 0 ;
if ( ! F_64 ( V_104 , V_93 , V_102 ) )
return - V_105 ;
F_29 () ;
if ( ! V_16 ) {
return F_54 ( V_1 , NULL ,
0 , sizeof( struct V_76 ) ,
NULL , V_37 ) ? - 1 : 1 ;
}
F_19 ( V_8 ) ;
if ( V_54 )
return F_61 ( V_37 ) ;
if ( V_11 )
return F_59 ( V_37 ) ;
else
return F_57 ( V_37 ) ;
}
static inline int F_65 ( struct V_92 T_2 * V_93 )
{
struct V_5 * V_8 = V_1 ;
return F_66 ( & V_8 -> V_43 . V_29 . V_30 -> V_38 , V_93 ,
sizeof( struct V_21 ) ) ;
}
static int F_67 ( struct V_92 T_2 * V_93 ,
unsigned int V_106 )
{
struct V_5 * V_8 = V_1 ;
struct V_76 V_77 ;
int V_94 ;
V_94 = F_66 ( & V_8 -> V_43 . V_29 . V_30 -> V_33 , & V_93 -> V_97 [ 0 ] ,
V_106 ) ;
V_8 -> V_43 . V_29 . V_30 -> V_33 . V_35 &= V_15 ;
if ( V_94 || F_66 ( & V_77 , V_93 , sizeof( V_77 ) ) )
return 1 ;
F_52 ( V_8 , & V_77 ) ;
return 0 ;
}
static int F_68 ( void T_2 * V_93 )
{
struct V_99 V_107 ;
struct V_92 T_2 * V_108 =
( (struct V_92 T_2 * ) V_93 ) ;
struct V_13 T_2 * V_32 =
(struct V_13 T_2 * ) & V_108 -> V_97 [ 0 ] ;
struct V_61 * V_56 =
& V_1 -> V_43 . V_29 . V_30 -> V_55 . V_56 ;
T_4 V_10 ;
int V_94 ;
if ( F_69 ( V_32 , V_93 , & V_107 ) )
goto V_109;
V_10 = V_107 . V_57 ;
V_94 = F_67 ( V_93 , V_107 . V_19 ) ;
V_56 -> V_57 &= V_62 ;
V_56 -> V_63 [ 0 ] = V_56 -> V_63 [ 1 ] = 0 ;
V_10 = ~ ( V_62 & ~ V_10 ) ;
V_56 -> V_57 &= V_10 ;
return V_94 ;
V_109:
V_56 -> V_57 = V_58 ;
return F_67 ( V_93 , sizeof( struct V_13 ) ) ;
}
int F_70 ( void T_2 * V_93 )
{
int V_94 ;
struct V_5 * V_8 = V_1 ;
struct V_92 T_2 * V_37 = (struct V_92 T_2 * ) V_93 ;
if ( V_16 )
F_71 ( V_8 ) ;
if ( ! V_93 ) {
if ( F_63 () ) {
F_71 ( V_8 ) ;
F_29 () ;
}
return 0 ;
} else
if ( ! F_64 ( V_110 , V_93 , V_102 ) )
return - V_105 ;
if ( ! F_63 () ) {
V_94 = F_32 ( V_8 ) ;
if ( V_94 )
return V_94 ;
}
if ( V_16 ) {
if ( V_54 )
V_94 = F_68 ( V_93 ) ;
else if ( V_11 )
V_94 = F_67 ( V_37 , sizeof( struct
V_13 ) ) ;
else
V_94 = F_65 ( V_37 ) ;
} else {
V_94 = F_56 ( V_1 , NULL ,
0 , sizeof( struct V_76 ) ,
NULL , V_37 ) != 0 ;
}
F_72 () ;
return V_94 ;
}
int F_73 ( struct V_3 * V_4 , struct V_111 * V_29 )
{
struct V_5 * V_8 = V_1 ;
int V_112 ;
V_112 = ! ! F_63 () ;
if ( V_112 )
V_112 = ! F_53 ( V_8 , NULL ,
0 , sizeof( struct V_76 ) ,
V_29 , NULL ) ;
return V_112 ;
}
