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
return true ;
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
} else {
F_4 ( V_8 , NULL ) ;
if ( ! F_7 () )
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
if ( F_7 () ) {
F_24 ( V_9 ) ;
} else {
F_16 ( V_9 ) ;
F_25 ( V_9 ) ;
}
}
F_26 () ;
}
static void F_27 ( void )
{
unsigned long V_10 = 0 ;
if ( V_11 ) {
memset ( & V_12 , 0 , sizeof( struct V_13 ) ) ;
asm volatile("fxsave %0" : "+m" (fx_scratch));
V_10 = V_12 . V_14 ;
if ( V_10 == 0 )
V_10 = 0x0000ffbf ;
}
V_15 &= V_10 ;
}
static void F_28 ( void )
{
if ( ! V_16 ) {
F_29 ( V_17 ) ;
F_29 ( V_18 ) ;
V_19 = sizeof( struct V_20 ) ;
return;
}
if ( V_11 )
V_19 = sizeof( struct V_13 ) ;
else
V_19 = sizeof( struct V_21 ) ;
F_29 ( V_22 ) ;
}
void F_30 ( void )
{
unsigned long V_23 ;
unsigned long V_24 = 0 ;
#ifndef F_31
if ( ! V_16 ) {
F_32 ( L_1 ) ;
F_32 ( L_2 ) ;
for (; ; )
asm volatile("hlt");
}
#endif
if ( V_11 )
V_24 |= V_25 ;
if ( V_26 )
V_24 |= V_27 ;
if ( V_24 )
F_33 ( V_24 ) ;
V_23 = F_9 () ;
V_23 &= ~ ( V_3 | V_28 ) ;
if ( ! V_16 )
V_23 |= V_28 ;
F_34 ( V_23 ) ;
if ( V_19 == 0 )
F_28 () ;
F_27 () ;
F_35 () ;
F_36 () ;
}
void F_37 ( struct V_29 * V_29 )
{
if ( ! V_16 ) {
F_38 ( & V_29 -> V_30 -> V_31 ) ;
return;
}
memset ( V_29 -> V_30 , 0 , V_19 ) ;
if ( V_11 ) {
F_39 ( & V_29 -> V_30 -> V_32 ) ;
} else {
struct V_21 * V_33 = & V_29 -> V_30 -> V_34 ;
V_33 -> V_35 = 0xffff037fu ;
V_33 -> V_36 = 0xffff0000u ;
V_33 -> V_37 = 0xffffffffu ;
V_33 -> V_38 = 0xffff0000u ;
}
}
int F_40 ( struct V_6 * V_9 )
{
int V_39 ;
if ( F_41 ( V_9 ) ) {
if ( V_16 && V_9 == V_2 )
F_22 ( V_9 ) ;
F_42 ( V_9 ) ;
return 0 ;
}
V_39 = F_43 ( & V_9 -> V_40 . V_29 ) ;
if ( V_39 )
return V_39 ;
F_37 ( & V_9 -> V_40 . V_29 ) ;
F_44 ( V_9 ) ;
return 0 ;
}
int F_45 ( struct V_6 * V_41 , const struct V_42 * V_43 )
{
return F_41 ( V_41 ) ? V_43 -> V_44 : 0 ;
}
int F_46 ( struct V_6 * V_41 , const struct V_42 * V_43 )
{
return ( V_11 && F_41 ( V_41 ) ) ? V_43 -> V_44 : 0 ;
}
int F_47 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
int V_39 ;
if ( ! V_11 )
return - V_49 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_48 ( V_41 ) ;
return F_49 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_40 . V_29 . V_30 -> V_32 , 0 , - 1 ) ;
}
int F_50 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
int V_39 ;
if ( ! V_11 )
return - V_49 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_48 ( V_41 ) ;
V_39 = F_51 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_40 . V_29 . V_30 -> V_32 , 0 , - 1 ) ;
V_41 -> V_40 . V_29 . V_30 -> V_32 . V_50 &= V_15 ;
if ( V_51 )
V_41 -> V_40 . V_29 . V_30 -> V_52 . V_53 . V_54 |= V_55 ;
return V_39 ;
}
int F_52 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
struct V_56 * V_52 ;
int V_39 ;
if ( ! V_51 )
return - V_49 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
V_52 = & V_41 -> V_40 . V_29 . V_30 -> V_52 ;
memcpy ( & V_52 -> V_57 . V_58 ,
V_59 , sizeof( V_59 ) ) ;
V_39 = F_49 ( & V_45 , & V_46 , & V_47 , & V_48 , V_52 , 0 , - 1 ) ;
return V_39 ;
}
int F_53 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
struct V_56 * V_52 ;
int V_39 ;
if ( ! V_51 )
return - V_49 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
V_52 = & V_41 -> V_40 . V_29 . V_30 -> V_52 ;
V_39 = F_51 ( & V_45 , & V_46 , & V_47 , & V_48 , V_52 , 0 , - 1 ) ;
V_52 -> V_57 . V_50 &= V_15 ;
V_52 -> V_53 . V_54 &= V_60 ;
memset ( & V_52 -> V_53 . V_61 , 0 , 48 ) ;
return V_39 ;
}
static inline unsigned short F_54 ( unsigned short V_37 )
{
unsigned int V_62 ;
V_62 = ~ V_37 ;
V_62 = ( V_62 | ( V_62 >> 1 ) ) & 0x5555 ;
V_62 = ( V_62 | ( V_62 >> 1 ) ) & 0x3333 ;
V_62 = ( V_62 | ( V_62 >> 2 ) ) & 0x0f0f ;
V_62 = ( V_62 | ( V_62 >> 4 ) ) & 0x00ff ;
return V_62 ;
}
static inline T_2 F_55 ( struct V_13 * V_32 )
{
struct V_63 * V_64 ;
T_2 V_65 = ( V_32 -> V_36 >> 11 ) & 7 ;
T_2 V_37 = ( unsigned long ) V_32 -> V_37 ;
T_2 V_66 ;
T_2 V_39 = 0xffff0000u ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ , V_37 >>= 1 ) {
if ( V_37 & 0x1 ) {
V_64 = F_56 ( V_32 , ( V_67 - V_65 ) & 7 ) ;
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
V_39 |= V_66 << ( 2 * V_67 ) ;
}
return V_39 ;
}
void
F_57 ( struct V_74 * V_75 , struct V_6 * V_9 )
{
struct V_13 * V_32 = & V_9 -> V_40 . V_29 . V_30 -> V_32 ;
struct V_76 * V_77 = (struct V_76 * ) & V_75 -> V_78 [ 0 ] ;
struct V_63 * V_79 = (struct V_63 * ) & V_32 -> V_78 [ 0 ] ;
int V_67 ;
V_75 -> V_35 = V_32 -> V_35 | 0xffff0000u ;
V_75 -> V_36 = V_32 -> V_36 | 0xffff0000u ;
V_75 -> V_37 = F_55 ( V_32 ) ;
#ifdef F_58
V_75 -> V_80 = V_32 -> V_81 ;
V_75 -> V_82 = V_32 -> V_83 ;
V_75 -> V_84 = F_59 ( V_9 ) -> V_85 ;
if ( V_9 == V_2 ) {
F_60 ( V_86 , V_75 -> V_38 ) ;
} else {
V_75 -> V_38 = V_9 -> V_40 . V_86 ;
}
V_75 -> V_38 |= 0xffff0000 ;
#else
V_75 -> V_80 = V_32 -> V_80 ;
V_75 -> V_84 = ( V_87 ) V_32 -> V_84 | ( ( T_2 ) V_32 -> V_88 << 16 ) ;
V_75 -> V_82 = V_32 -> V_82 ;
V_75 -> V_38 = V_32 -> V_38 ;
#endif
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
memcpy ( & V_77 [ V_67 ] , & V_79 [ V_67 ] , sizeof( V_77 [ 0 ] ) ) ;
}
void F_61 ( struct V_6 * V_9 ,
const struct V_74 * V_75 )
{
struct V_13 * V_32 = & V_9 -> V_40 . V_29 . V_30 -> V_32 ;
struct V_76 * V_79 = (struct V_76 * ) & V_75 -> V_78 [ 0 ] ;
struct V_63 * V_77 = (struct V_63 * ) & V_32 -> V_78 [ 0 ] ;
int V_67 ;
V_32 -> V_35 = V_75 -> V_35 ;
V_32 -> V_36 = V_75 -> V_36 ;
V_32 -> V_37 = F_54 ( V_75 -> V_37 ) ;
V_32 -> V_88 = ( V_87 ) ( ( T_2 ) V_75 -> V_84 >> 16 ) ;
#ifdef F_58
V_32 -> V_81 = V_75 -> V_80 ;
V_32 -> V_83 = V_75 -> V_82 ;
#else
V_32 -> V_80 = V_75 -> V_80 ;
V_32 -> V_84 = ( V_75 -> V_84 & 0xffff ) ;
V_32 -> V_82 = V_75 -> V_82 ;
V_32 -> V_38 = V_75 -> V_38 ;
#endif
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
memcpy ( & V_77 [ V_67 ] , & V_79 [ V_67 ] , sizeof( V_79 [ 0 ] ) ) ;
}
int F_62 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
struct V_74 V_75 ;
int V_39 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
if ( ! F_63 ( V_89 ) )
return F_64 ( V_41 , V_43 , V_45 , V_46 , V_47 , V_48 ) ;
if ( ! V_11 )
return F_49 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_40 . V_29 . V_30 -> V_34 , 0 ,
- 1 ) ;
F_48 ( V_41 ) ;
if ( V_47 && V_45 == 0 && V_46 == sizeof( V_75 ) ) {
F_57 ( V_47 , V_41 ) ;
return 0 ;
}
F_57 ( & V_75 , V_41 ) ;
return F_49 ( & V_45 , & V_46 , & V_47 , & V_48 , & V_75 , 0 , - 1 ) ;
}
int F_65 ( struct V_6 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
struct V_74 V_75 ;
int V_39 ;
V_39 = F_40 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_48 ( V_41 ) ;
if ( ! F_63 ( V_89 ) )
return F_66 ( V_41 , V_43 , V_45 , V_46 , V_47 , V_48 ) ;
if ( ! V_11 )
return F_51 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_40 . V_29 . V_30 -> V_34 , 0 ,
- 1 ) ;
if ( V_45 > 0 || V_46 < sizeof( V_75 ) )
F_57 ( & V_75 , V_41 ) ;
V_39 = F_51 ( & V_45 , & V_46 , & V_47 , & V_48 , & V_75 , 0 , - 1 ) ;
if ( ! V_39 )
F_61 ( V_41 , & V_75 ) ;
if ( V_51 )
V_41 -> V_40 . V_29 . V_30 -> V_52 . V_53 . V_54 |= V_90 ;
return V_39 ;
}
int F_67 ( struct V_4 * V_5 , struct V_91 * V_29 )
{
struct V_6 * V_9 = V_2 ;
int V_92 ;
V_92 = ! ! F_68 () ;
if ( V_92 )
V_92 = ! F_62 ( V_9 , NULL ,
0 , sizeof( struct V_74 ) ,
V_29 , NULL ) ;
return V_92 ;
}
static int T_3 F_69 ( char * V_93 )
{
F_29 ( V_89 ) ;
return 1 ;
}
void F_70 ( struct V_94 * V_95 )
{
unsigned long V_23 ;
V_87 V_96 , V_97 ;
V_96 = V_97 = 0xffff ;
V_23 = F_9 () ;
V_23 &= ~ ( V_3 | V_28 ) ;
F_34 ( V_23 ) ;
asm volatile("fninit ; fnstsw %0 ; fnstcw %1"
: "+m" (fsw), "+m" (fcw));
if ( V_96 == 0 && ( V_97 & 0x103f ) == 0x003f )
F_71 ( V_95 , V_89 ) ;
else
F_72 ( V_95 , V_89 ) ;
}
