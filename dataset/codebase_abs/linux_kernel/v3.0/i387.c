void T_1 F_1 ( void )
{
unsigned long V_1 = 0 ;
F_2 () ;
if ( V_2 ) {
memset ( & V_3 , 0 , sizeof( struct V_4 ) ) ;
asm volatile("fxsave %0" : : "m" (fx_scratch));
V_1 = V_3 . V_5 ;
if ( V_1 == 0 )
V_1 = 0x0000ffbf ;
}
V_6 &= V_1 ;
F_3 () ;
}
static void T_1 F_4 ( void )
{
if ( ! V_7 ) {
F_5 ( V_8 ) ;
F_5 ( V_9 ) ;
V_10 = sizeof( struct V_11 ) ;
return;
}
if ( V_2 )
V_10 = sizeof( struct V_4 ) ;
else
V_10 = sizeof( struct V_12 ) ;
}
void T_1 F_6 ( void )
{
unsigned long V_13 ;
unsigned long V_14 = 0 ;
if ( V_2 )
V_14 |= V_15 ;
if ( V_16 )
V_14 |= V_17 ;
if ( V_14 )
F_7 ( V_14 ) ;
V_13 = F_8 () ;
V_13 &= ~ ( V_18 | V_19 ) ;
if ( ! V_7 )
V_13 |= V_19 ;
F_9 ( V_13 ) ;
if ( ! F_10 () )
F_4 () ;
F_1 () ;
F_11 () -> V_20 = 0 ;
F_12 () ;
}
void F_13 ( struct V_21 * V_21 )
{
if ( ! V_7 ) {
F_14 ( & V_21 -> V_22 -> V_23 ) ;
return;
}
if ( V_2 ) {
struct V_4 * V_24 = & V_21 -> V_22 -> V_25 ;
memset ( V_24 , 0 , V_10 ) ;
V_24 -> V_26 = 0x37f ;
if ( V_16 )
V_24 -> V_27 = V_28 ;
} else {
struct V_12 * V_29 = & V_21 -> V_22 -> V_30 ;
memset ( V_29 , 0 , V_10 ) ;
V_29 -> V_26 = 0xffff037fu ;
V_29 -> V_31 = 0xffff0000u ;
V_29 -> V_32 = 0xffffffffu ;
V_29 -> V_33 = 0xffff0000u ;
}
}
int F_15 ( struct V_34 * V_35 )
{
int V_36 ;
if ( F_16 ( V_35 ) ) {
if ( V_7 && V_35 == V_37 )
F_17 ( V_35 ) ;
return 0 ;
}
V_36 = F_18 ( & V_35 -> V_38 . V_21 ) ;
if ( V_36 )
return V_36 ;
F_13 ( & V_35 -> V_38 . V_21 ) ;
F_19 ( V_35 ) ;
return 0 ;
}
int F_20 ( struct V_34 * V_39 , const struct V_40 * V_41 )
{
return F_16 ( V_39 ) ? V_41 -> V_42 : 0 ;
}
int F_21 ( struct V_34 * V_39 , const struct V_40 * V_41 )
{
return ( V_2 && F_16 ( V_39 ) ) ? V_41 -> V_42 : 0 ;
}
int F_22 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
void * V_45 , void T_2 * V_46 )
{
int V_36 ;
if ( ! V_2 )
return - V_47 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
F_23 ( V_39 ) ;
return F_24 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_25 , 0 , - 1 ) ;
}
int F_25 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
const void * V_45 , const void T_2 * V_46 )
{
int V_36 ;
if ( ! V_2 )
return - V_47 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
F_23 ( V_39 ) ;
V_36 = F_26 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_25 , 0 , - 1 ) ;
V_39 -> V_38 . V_21 . V_22 -> V_25 . V_27 &= V_6 ;
if ( V_48 )
V_39 -> V_38 . V_21 . V_22 -> V_49 . V_50 . V_51 |= V_52 ;
return V_36 ;
}
int F_27 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
void * V_45 , void T_2 * V_46 )
{
int V_36 ;
if ( ! V_48 )
return - V_47 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
memcpy ( & V_39 -> V_38 . V_21 . V_22 -> V_25 . V_53 ,
V_54 , sizeof( V_54 ) ) ;
V_36 = F_24 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_49 , 0 , - 1 ) ;
return V_36 ;
}
int F_28 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
const void * V_45 , const void T_2 * V_46 )
{
int V_36 ;
struct V_55 * V_50 ;
if ( ! V_48 )
return - V_47 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_26 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_49 , 0 , - 1 ) ;
V_39 -> V_38 . V_21 . V_22 -> V_25 . V_27 &= V_6 ;
V_50 = & V_39 -> V_38 . V_21 . V_22 -> V_49 . V_50 ;
V_50 -> V_51 &= V_56 ;
V_50 -> V_57 [ 0 ] = V_50 -> V_57 [ 1 ] = 0 ;
return V_36 ;
}
static inline unsigned short F_29 ( unsigned short V_32 )
{
unsigned int V_58 ;
V_58 = ~ V_32 ;
V_58 = ( V_58 | ( V_58 >> 1 ) ) & 0x5555 ;
V_58 = ( V_58 | ( V_58 >> 1 ) ) & 0x3333 ;
V_58 = ( V_58 | ( V_58 >> 2 ) ) & 0x0f0f ;
V_58 = ( V_58 | ( V_58 >> 4 ) ) & 0x00ff ;
return V_58 ;
}
static inline T_3 F_30 ( struct V_4 * V_25 )
{
struct V_59 * V_60 ;
T_3 V_61 = ( V_25 -> V_31 >> 11 ) & 7 ;
T_3 V_32 = ( unsigned long ) V_25 -> V_32 ;
T_3 V_62 ;
T_3 V_36 = 0xffff0000u ;
int V_63 ;
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ , V_32 >>= 1 ) {
if ( V_32 & 0x1 ) {
V_60 = F_31 ( V_25 , ( V_63 - V_61 ) & 7 ) ;
switch ( V_60 -> V_64 & 0x7fff ) {
case 0x7fff :
V_62 = V_65 ;
break;
case 0x0000 :
if ( ! V_60 -> V_66 [ 0 ] &&
! V_60 -> V_66 [ 1 ] &&
! V_60 -> V_66 [ 2 ] &&
! V_60 -> V_66 [ 3 ] )
V_62 = V_67 ;
else
V_62 = V_65 ;
break;
default:
if ( V_60 -> V_66 [ 3 ] & 0x8000 )
V_62 = V_68 ;
else
V_62 = V_65 ;
break;
}
} else {
V_62 = V_69 ;
}
V_36 |= V_62 << ( 2 * V_63 ) ;
}
return V_36 ;
}
static void
F_32 ( struct V_70 * V_71 , struct V_34 * V_35 )
{
struct V_4 * V_25 = & V_35 -> V_38 . V_21 . V_22 -> V_25 ;
struct V_72 * V_73 = (struct V_72 * ) & V_71 -> V_74 [ 0 ] ;
struct V_59 * V_75 = (struct V_59 * ) & V_25 -> V_74 [ 0 ] ;
int V_63 ;
V_71 -> V_26 = V_25 -> V_26 | 0xffff0000u ;
V_71 -> V_31 = V_25 -> V_31 | 0xffff0000u ;
V_71 -> V_32 = F_30 ( V_25 ) ;
#ifdef F_33
V_71 -> V_76 = V_25 -> V_77 ;
V_71 -> V_78 = V_25 -> V_79 ;
V_71 -> V_80 = F_34 ( V_35 ) -> V_81 ;
if ( V_35 == V_37 ) {
F_35 ( V_82 , V_71 -> V_33 ) ;
} else {
V_71 -> V_33 = V_35 -> V_38 . V_82 ;
}
V_71 -> V_33 |= 0xffff0000 ;
#else
V_71 -> V_76 = V_25 -> V_76 ;
V_71 -> V_80 = ( V_83 ) V_25 -> V_80 | ( ( T_3 ) V_25 -> V_84 << 16 ) ;
V_71 -> V_78 = V_25 -> V_78 ;
V_71 -> V_33 = V_25 -> V_33 ;
#endif
for ( V_63 = 0 ; V_63 < 8 ; ++ V_63 )
memcpy ( & V_73 [ V_63 ] , & V_75 [ V_63 ] , sizeof( V_73 [ 0 ] ) ) ;
}
static void F_36 ( struct V_34 * V_35 ,
const struct V_70 * V_71 )
{
struct V_4 * V_25 = & V_35 -> V_38 . V_21 . V_22 -> V_25 ;
struct V_72 * V_75 = (struct V_72 * ) & V_71 -> V_74 [ 0 ] ;
struct V_59 * V_73 = (struct V_59 * ) & V_25 -> V_74 [ 0 ] ;
int V_63 ;
V_25 -> V_26 = V_71 -> V_26 ;
V_25 -> V_31 = V_71 -> V_31 ;
V_25 -> V_32 = F_29 ( V_71 -> V_32 ) ;
V_25 -> V_84 = ( V_83 ) ( ( T_3 ) V_71 -> V_80 >> 16 ) ;
#ifdef F_33
V_25 -> V_77 = V_71 -> V_76 ;
V_25 -> V_79 = V_71 -> V_78 ;
#else
V_25 -> V_76 = V_71 -> V_76 ;
V_25 -> V_80 = ( V_71 -> V_80 & 0xffff ) ;
V_25 -> V_78 = V_71 -> V_78 ;
V_25 -> V_33 = V_71 -> V_33 ;
#endif
for ( V_63 = 0 ; V_63 < 8 ; ++ V_63 )
memcpy ( & V_73 [ V_63 ] , & V_75 [ V_63 ] , sizeof( V_75 [ 0 ] ) ) ;
}
int F_37 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
void * V_45 , void T_2 * V_46 )
{
struct V_70 V_71 ;
int V_36 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_7 )
return F_38 ( V_39 , V_41 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_2 ) {
return F_24 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_30 , 0 ,
- 1 ) ;
}
F_23 ( V_39 ) ;
if ( V_45 && V_43 == 0 && V_44 == sizeof( V_71 ) ) {
F_32 ( V_45 , V_39 ) ;
return 0 ;
}
F_32 ( & V_71 , V_39 ) ;
return F_24 ( & V_43 , & V_44 , & V_45 , & V_46 , & V_71 , 0 , - 1 ) ;
}
int F_39 ( struct V_34 * V_39 , const struct V_40 * V_41 ,
unsigned int V_43 , unsigned int V_44 ,
const void * V_45 , const void T_2 * V_46 )
{
struct V_70 V_71 ;
int V_36 ;
V_36 = F_15 ( V_39 ) ;
if ( V_36 )
return V_36 ;
F_23 ( V_39 ) ;
if ( ! V_7 )
return F_40 ( V_39 , V_41 , V_43 , V_44 , V_45 , V_46 ) ;
if ( ! V_2 ) {
return F_26 ( & V_43 , & V_44 , & V_45 , & V_46 ,
& V_39 -> V_38 . V_21 . V_22 -> V_30 , 0 , - 1 ) ;
}
if ( V_43 > 0 || V_44 < sizeof( V_71 ) )
F_32 ( & V_71 , V_39 ) ;
V_36 = F_26 ( & V_43 , & V_44 , & V_45 , & V_46 , & V_71 , 0 , - 1 ) ;
if ( ! V_36 )
F_36 ( V_39 , & V_71 ) ;
if ( V_48 )
V_39 -> V_38 . V_21 . V_22 -> V_49 . V_50 . V_51 |= V_85 ;
return V_36 ;
}
static inline int F_41 ( struct V_86 T_2 * V_87 )
{
struct V_34 * V_35 = V_37 ;
struct V_12 * V_29 = & V_35 -> V_38 . V_21 . V_22 -> V_30 ;
V_29 -> V_20 = V_29 -> V_31 ;
if ( F_42 ( V_87 , V_29 , sizeof( struct V_12 ) ) )
return - 1 ;
return 1 ;
}
static int F_43 ( struct V_86 T_2 * V_87 )
{
struct V_34 * V_35 = V_37 ;
struct V_4 * V_24 = & V_35 -> V_38 . V_21 . V_22 -> V_25 ;
struct V_70 V_71 ;
int V_88 = 0 ;
F_32 ( & V_71 , V_35 ) ;
if ( F_42 ( V_87 , & V_71 , sizeof( V_71 ) ) )
return - 1 ;
V_88 |= F_44 ( V_24 -> V_31 , & V_87 -> V_20 ) ;
V_88 |= F_44 ( V_89 , & V_87 -> V_90 ) ;
if ( V_88 )
return - 1 ;
if ( F_42 ( & V_87 -> V_91 [ 0 ] , V_24 , V_10 ) )
return - 1 ;
return 1 ;
}
static int F_45 ( void T_2 * V_87 )
{
struct V_34 * V_35 = V_37 ;
struct V_86 T_2 * V_24 = V_87 ;
int V_88 = 0 ;
F_23 ( V_35 ) ;
V_35 -> V_38 . V_21 . V_22 -> V_49 . V_50 . V_51 |= V_52 ;
if ( F_43 ( V_24 ) < 0 )
return - 1 ;
V_88 = F_42 ( & V_24 -> V_53 , & V_92 ,
sizeof( struct V_93 ) ) ;
V_88 |= F_44 ( V_94 ,
( V_95 T_2 * ) ( V_87 + V_96
- V_97 ) ) ;
if ( V_88 )
return - 1 ;
return 1 ;
}
int F_46 ( void T_2 * V_87 )
{
struct V_86 T_2 * V_29 = (struct V_86 T_2 * ) V_87 ;
struct V_34 * V_35 = V_37 ;
if ( ! F_47 () )
return 0 ;
if ( ! F_48 ( V_98 , V_87 , V_96 ) )
return - V_99 ;
F_12 () ;
if ( ! V_7 ) {
return F_38 ( V_37 , NULL ,
0 , sizeof( struct V_70 ) ,
NULL , V_29 ) ? - 1 : 1 ;
}
F_17 ( V_35 ) ;
if ( V_48 )
return F_45 ( V_29 ) ;
if ( V_2 )
return F_43 ( V_29 ) ;
else
return F_41 ( V_29 ) ;
}
static inline int F_49 ( struct V_86 T_2 * V_87 )
{
struct V_34 * V_35 = V_37 ;
return F_50 ( & V_35 -> V_38 . V_21 . V_22 -> V_30 , V_87 ,
sizeof( struct V_12 ) ) ;
}
static int F_51 ( struct V_86 T_2 * V_87 ,
unsigned int V_100 )
{
struct V_34 * V_35 = V_37 ;
struct V_70 V_71 ;
int V_88 ;
V_88 = F_50 ( & V_35 -> V_38 . V_21 . V_22 -> V_25 , & V_87 -> V_91 [ 0 ] ,
V_100 ) ;
V_35 -> V_38 . V_21 . V_22 -> V_25 . V_27 &= V_6 ;
if ( V_88 || F_50 ( & V_71 , V_87 , sizeof( V_71 ) ) )
return 1 ;
F_36 ( V_35 , & V_71 ) ;
return 0 ;
}
static int F_52 ( void T_2 * V_87 )
{
struct V_93 V_101 ;
struct V_86 T_2 * V_102 =
( (struct V_86 T_2 * ) V_87 ) ;
struct V_4 T_2 * V_24 =
(struct V_4 T_2 * ) & V_102 -> V_91 [ 0 ] ;
struct V_55 * V_50 =
& V_37 -> V_38 . V_21 . V_22 -> V_49 . V_50 ;
T_4 V_1 ;
int V_88 ;
if ( F_53 ( V_24 , V_87 , & V_101 ) )
goto V_103;
V_1 = V_101 . V_51 ;
V_88 = F_51 ( V_87 , V_101 . V_10 ) ;
V_50 -> V_51 &= V_56 ;
V_50 -> V_57 [ 0 ] = V_50 -> V_57 [ 1 ] = 0 ;
V_1 = ~ ( V_56 & ~ V_1 ) ;
V_50 -> V_51 &= V_1 ;
return V_88 ;
V_103:
V_50 -> V_51 = V_52 ;
return F_51 ( V_87 , sizeof( struct V_4 ) ) ;
}
int F_54 ( void T_2 * V_87 )
{
int V_88 ;
struct V_34 * V_35 = V_37 ;
struct V_86 T_2 * V_29 = (struct V_86 T_2 * ) V_87 ;
if ( V_7 )
F_55 ( V_35 ) ;
if ( ! V_87 ) {
if ( F_47 () ) {
F_55 ( V_35 ) ;
F_12 () ;
}
return 0 ;
} else
if ( ! F_48 ( V_104 , V_87 , V_96 ) )
return - V_99 ;
if ( ! F_47 () ) {
V_88 = F_15 ( V_35 ) ;
if ( V_88 )
return V_88 ;
}
if ( V_7 ) {
if ( V_48 )
V_88 = F_52 ( V_87 ) ;
else if ( V_2 )
V_88 = F_51 ( V_29 , sizeof( struct
V_4 ) ) ;
else
V_88 = F_49 ( V_29 ) ;
} else {
V_88 = F_40 ( V_37 , NULL ,
0 , sizeof( struct V_70 ) ,
NULL , V_29 ) != 0 ;
}
F_56 () ;
return V_88 ;
}
int F_57 ( struct V_105 * V_106 , struct V_107 * V_21 )
{
struct V_34 * V_35 = V_37 ;
int V_108 ;
V_108 = ! ! F_47 () ;
if ( V_108 )
V_108 = ! F_37 ( V_35 , NULL ,
0 , sizeof( struct V_70 ) ,
V_21 , NULL ) ;
return V_108 ;
}
