void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) ) ;
F_4 ( V_1 , true ) ;
}
void F_5 ( void )
{
F_4 ( V_1 , false ) ;
}
static inline bool F_6 ( void )
{
if ( F_3 ( V_1 ) )
return false ;
if ( F_7 () )
return F_8 ( V_2 ) ;
return ! F_8 ( V_2 ) &&
( F_9 () & V_3 ) ;
}
static inline bool F_10 ( void )
{
struct V_4 * V_5 = F_11 () ;
return V_5 && F_12 ( V_5 ) ;
}
bool F_13 ( void )
{
return ! F_14 () ||
F_10 () ||
F_6 () ;
}
void F_15 ( void )
{
struct V_6 * V_7 = V_2 ;
F_4 ( V_1 , true ) ;
if ( F_8 ( V_7 ) ) {
F_16 ( V_7 ) ;
} else if ( ! F_7 () ) {
F_4 ( V_8 , NULL ) ;
F_17 () ;
}
}
void F_18 ( void )
{
struct V_6 * V_7 = V_2 ;
if ( F_8 ( V_7 ) ) {
if ( F_2 ( F_19 ( V_7 ) ) )
F_20 ( V_7 ) ;
} else if ( ! F_7 () ) {
F_21 () ;
}
F_4 ( V_1 , false ) ;
}
void F_22 ( struct V_6 * V_9 )
{
F_23 () ;
if ( F_8 ( V_9 ) ) {
F_16 ( V_9 ) ;
F_24 ( V_9 ) ;
} else
V_9 -> V_10 . V_11 = 0 ;
F_25 () ;
}
static void F_26 ( void )
{
unsigned long V_12 = 0 ;
if ( V_13 ) {
memset ( & V_14 , 0 , sizeof( struct V_15 ) ) ;
asm volatile("fxsave %0" : "+m" (fx_scratch));
V_12 = V_14 . V_16 ;
if ( V_12 == 0 )
V_12 = 0x0000ffbf ;
}
V_17 &= V_12 ;
}
static void F_27 ( void )
{
if ( ! V_18 ) {
F_28 ( V_19 ) ;
F_28 ( V_20 ) ;
V_21 = sizeof( struct V_22 ) ;
return;
}
if ( V_13 )
V_21 = sizeof( struct V_15 ) ;
else
V_21 = sizeof( struct V_23 ) ;
}
void F_29 ( void )
{
unsigned long V_24 ;
unsigned long V_25 = 0 ;
#ifndef F_30
if ( ! V_18 ) {
F_31 ( L_1 ) ;
F_31 ( L_2 ) ;
for (; ; )
asm volatile("hlt");
}
#endif
if ( V_13 )
V_25 |= V_26 ;
if ( V_27 )
V_25 |= V_28 ;
if ( V_25 )
F_32 ( V_25 ) ;
V_24 = F_9 () ;
V_24 &= ~ ( V_3 | V_29 ) ;
if ( ! V_18 )
V_24 |= V_29 ;
F_33 ( V_24 ) ;
if ( V_21 == 0 )
F_27 () ;
F_26 () ;
F_34 () ;
F_35 () ;
}
void F_36 ( struct V_30 * V_30 )
{
if ( ! V_18 ) {
F_37 ( & V_30 -> V_31 -> V_32 ) ;
return;
}
if ( V_13 ) {
F_38 ( & V_30 -> V_31 -> V_33 ) ;
} else {
struct V_23 * V_34 = & V_30 -> V_31 -> V_35 ;
memset ( V_34 , 0 , V_21 ) ;
V_34 -> V_36 = 0xffff037fu ;
V_34 -> V_37 = 0xffff0000u ;
V_34 -> V_38 = 0xffffffffu ;
V_34 -> V_39 = 0xffff0000u ;
}
}
int F_39 ( struct V_6 * V_9 )
{
int V_40 ;
if ( F_40 ( V_9 ) ) {
if ( V_18 && V_9 == V_2 )
F_22 ( V_9 ) ;
V_9 -> V_10 . V_30 . V_41 = ~ 0 ;
return 0 ;
}
V_40 = F_41 ( & V_9 -> V_10 . V_30 ) ;
if ( V_40 )
return V_40 ;
F_36 ( & V_9 -> V_10 . V_30 ) ;
F_42 ( V_9 ) ;
return 0 ;
}
int F_43 ( struct V_6 * V_42 , const struct V_43 * V_44 )
{
return F_40 ( V_42 ) ? V_44 -> V_45 : 0 ;
}
int F_44 ( struct V_6 * V_42 , const struct V_43 * V_44 )
{
return ( V_13 && F_40 ( V_42 ) ) ? V_44 -> V_45 : 0 ;
}
int F_45 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
void * V_48 , void T_1 * V_49 )
{
int V_40 ;
if ( ! V_13 )
return - V_50 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_42 ) ;
return F_47 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_33 , 0 , - 1 ) ;
}
int F_48 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
const void * V_48 , const void T_1 * V_49 )
{
int V_40 ;
if ( ! V_13 )
return - V_50 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_42 ) ;
V_40 = F_49 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_33 , 0 , - 1 ) ;
V_42 -> V_10 . V_30 . V_31 -> V_33 . V_51 &= V_17 ;
if ( V_52 )
V_42 -> V_10 . V_30 . V_31 -> V_53 . V_54 . V_55 |= V_56 ;
return V_40 ;
}
int F_50 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
void * V_48 , void T_1 * V_49 )
{
int V_40 ;
if ( ! V_52 )
return - V_50 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
memcpy ( & V_42 -> V_10 . V_30 . V_31 -> V_33 . V_57 ,
V_58 , sizeof( V_58 ) ) ;
V_40 = F_47 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_53 , 0 , - 1 ) ;
return V_40 ;
}
int F_51 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
const void * V_48 , const void T_1 * V_49 )
{
int V_40 ;
struct V_59 * V_54 ;
if ( ! V_52 )
return - V_50 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_49 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_53 , 0 , - 1 ) ;
V_42 -> V_10 . V_30 . V_31 -> V_33 . V_51 &= V_17 ;
V_54 = & V_42 -> V_10 . V_30 . V_31 -> V_53 . V_54 ;
V_54 -> V_55 &= V_60 ;
memset ( V_54 -> V_61 , 0 , 48 ) ;
return V_40 ;
}
static inline unsigned short F_52 ( unsigned short V_38 )
{
unsigned int V_62 ;
V_62 = ~ V_38 ;
V_62 = ( V_62 | ( V_62 >> 1 ) ) & 0x5555 ;
V_62 = ( V_62 | ( V_62 >> 1 ) ) & 0x3333 ;
V_62 = ( V_62 | ( V_62 >> 2 ) ) & 0x0f0f ;
V_62 = ( V_62 | ( V_62 >> 4 ) ) & 0x00ff ;
return V_62 ;
}
static inline T_2 F_53 ( struct V_15 * V_33 )
{
struct V_63 * V_64 ;
T_2 V_65 = ( V_33 -> V_37 >> 11 ) & 7 ;
T_2 V_38 = ( unsigned long ) V_33 -> V_38 ;
T_2 V_66 ;
T_2 V_40 = 0xffff0000u ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ , V_38 >>= 1 ) {
if ( V_38 & 0x1 ) {
V_64 = F_54 ( V_33 , ( V_67 - V_65 ) & 7 ) ;
switch ( V_64 -> V_68 & 0x7fff ) {
case 0x7fff :
V_66 = V_69 ;
break;
case 0x0000 :
if ( ! V_64 -> V_70 [ 0 ] &&
! V_64 -> V_70 [ 1 ] &&
! V_64 -> V_70 [ 2 ] &&
! V_64 -> V_70 [ 3 ] )
V_66 = V_71 ;
else
V_66 = V_69 ;
break;
default:
if ( V_64 -> V_70 [ 3 ] & 0x8000 )
V_66 = V_72 ;
else
V_66 = V_69 ;
break;
}
} else {
V_66 = V_73 ;
}
V_40 |= V_66 << ( 2 * V_67 ) ;
}
return V_40 ;
}
void
F_55 ( struct V_74 * V_75 , struct V_6 * V_9 )
{
struct V_15 * V_33 = & V_9 -> V_10 . V_30 . V_31 -> V_33 ;
struct V_76 * V_77 = (struct V_76 * ) & V_75 -> V_78 [ 0 ] ;
struct V_63 * V_79 = (struct V_63 * ) & V_33 -> V_78 [ 0 ] ;
int V_67 ;
V_75 -> V_36 = V_33 -> V_36 | 0xffff0000u ;
V_75 -> V_37 = V_33 -> V_37 | 0xffff0000u ;
V_75 -> V_38 = F_53 ( V_33 ) ;
#ifdef F_56
V_75 -> V_80 = V_33 -> V_81 ;
V_75 -> V_82 = V_33 -> V_83 ;
V_75 -> V_84 = F_57 ( V_9 ) -> V_85 ;
if ( V_9 == V_2 ) {
F_58 ( V_86 , V_75 -> V_39 ) ;
} else {
V_75 -> V_39 = V_9 -> V_10 . V_86 ;
}
V_75 -> V_39 |= 0xffff0000 ;
#else
V_75 -> V_80 = V_33 -> V_80 ;
V_75 -> V_84 = ( V_87 ) V_33 -> V_84 | ( ( T_2 ) V_33 -> V_88 << 16 ) ;
V_75 -> V_82 = V_33 -> V_82 ;
V_75 -> V_39 = V_33 -> V_39 ;
#endif
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
memcpy ( & V_77 [ V_67 ] , & V_79 [ V_67 ] , sizeof( V_77 [ 0 ] ) ) ;
}
void F_59 ( struct V_6 * V_9 ,
const struct V_74 * V_75 )
{
struct V_15 * V_33 = & V_9 -> V_10 . V_30 . V_31 -> V_33 ;
struct V_76 * V_79 = (struct V_76 * ) & V_75 -> V_78 [ 0 ] ;
struct V_63 * V_77 = (struct V_63 * ) & V_33 -> V_78 [ 0 ] ;
int V_67 ;
V_33 -> V_36 = V_75 -> V_36 ;
V_33 -> V_37 = V_75 -> V_37 ;
V_33 -> V_38 = F_52 ( V_75 -> V_38 ) ;
V_33 -> V_88 = ( V_87 ) ( ( T_2 ) V_75 -> V_84 >> 16 ) ;
#ifdef F_56
V_33 -> V_81 = V_75 -> V_80 ;
V_33 -> V_83 = V_75 -> V_82 ;
#else
V_33 -> V_80 = V_75 -> V_80 ;
V_33 -> V_84 = ( V_75 -> V_84 & 0xffff ) ;
V_33 -> V_82 = V_75 -> V_82 ;
V_33 -> V_39 = V_75 -> V_39 ;
#endif
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
memcpy ( & V_77 [ V_67 ] , & V_79 [ V_67 ] , sizeof( V_79 [ 0 ] ) ) ;
}
int F_60 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
void * V_48 , void T_1 * V_49 )
{
struct V_74 V_75 ;
int V_40 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_61 ( V_89 ) )
return F_62 ( V_42 , V_44 , V_46 , V_47 , V_48 , V_49 ) ;
if ( ! V_13 )
return F_47 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_35 , 0 ,
- 1 ) ;
F_46 ( V_42 ) ;
if ( V_48 && V_46 == 0 && V_47 == sizeof( V_75 ) ) {
F_55 ( V_48 , V_42 ) ;
return 0 ;
}
F_55 ( & V_75 , V_42 ) ;
return F_47 ( & V_46 , & V_47 , & V_48 , & V_49 , & V_75 , 0 , - 1 ) ;
}
int F_63 ( struct V_6 * V_42 , const struct V_43 * V_44 ,
unsigned int V_46 , unsigned int V_47 ,
const void * V_48 , const void T_1 * V_49 )
{
struct V_74 V_75 ;
int V_40 ;
V_40 = F_39 ( V_42 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_42 ) ;
if ( ! F_61 ( V_89 ) )
return F_64 ( V_42 , V_44 , V_46 , V_47 , V_48 , V_49 ) ;
if ( ! V_13 )
return F_49 ( & V_46 , & V_47 , & V_48 , & V_49 ,
& V_42 -> V_10 . V_30 . V_31 -> V_35 , 0 ,
- 1 ) ;
if ( V_46 > 0 || V_47 < sizeof( V_75 ) )
F_55 ( & V_75 , V_42 ) ;
V_40 = F_49 ( & V_46 , & V_47 , & V_48 , & V_49 , & V_75 , 0 , - 1 ) ;
if ( ! V_40 )
F_59 ( V_42 , & V_75 ) ;
if ( V_52 )
V_42 -> V_10 . V_30 . V_31 -> V_53 . V_54 . V_55 |= V_90 ;
return V_40 ;
}
int F_65 ( struct V_4 * V_5 , struct V_91 * V_30 )
{
struct V_6 * V_9 = V_2 ;
int V_92 ;
V_92 = ! ! F_66 () ;
if ( V_92 )
V_92 = ! F_60 ( V_9 , NULL ,
0 , sizeof( struct V_74 ) ,
V_30 , NULL ) ;
return V_92 ;
}
static int T_3 F_67 ( char * V_93 )
{
F_28 ( V_89 ) ;
return 1 ;
}
void F_68 ( struct V_94 * V_95 )
{
unsigned long V_24 ;
V_87 V_96 , V_97 ;
V_96 = V_97 = 0xffff ;
V_24 = F_9 () ;
V_24 &= ~ ( V_3 | V_29 ) ;
F_33 ( V_24 ) ;
asm volatile("fninit ; fnstsw %0 ; fnstcw %1"
: "+m" (fsw), "+m" (fcw));
if ( V_96 == 0 && ( V_97 & 0x103f ) == 0x003f )
F_69 ( V_95 , V_89 ) ;
else
F_70 ( V_95 , V_89 ) ;
}
