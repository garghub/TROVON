static inline bool F_1 ( void )
{
if ( F_2 () )
return F_3 ( V_1 ) ;
return ! F_3 ( V_1 ) &&
( F_4 () & V_2 ) ;
}
static inline bool F_5 ( void )
{
struct V_3 * V_4 = F_6 () ;
return V_4 && F_7 ( V_4 ) ;
}
bool F_8 ( void )
{
return ! F_9 () ||
F_5 () ||
F_1 () ;
}
void F_10 ( void )
{
struct V_5 * V_6 = V_1 ;
if ( F_3 ( V_6 ) ) {
F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
} else if ( ! F_2 () ) {
F_13 ( V_7 , NULL ) ;
F_14 () ;
}
}
void F_15 ( void )
{
if ( F_2 () ) {
if ( F_16 ( F_17 ( V_1 ) ) )
F_18 () ;
} else {
F_19 () ;
}
}
void F_20 ( struct V_5 * V_8 )
{
F_21 () ;
if ( F_3 ( V_8 ) ) {
F_12 ( V_8 ) ;
F_22 ( V_8 ) ;
} else
V_8 -> V_9 . V_10 = 0 ;
F_23 () ;
}
static void F_24 ( void )
{
unsigned long V_11 = 0 ;
if ( V_12 ) {
memset ( & V_13 , 0 , sizeof( struct V_14 ) ) ;
asm volatile("fxsave %0" : "+m" (fx_scratch));
V_11 = V_13 . V_15 ;
if ( V_11 == 0 )
V_11 = 0x0000ffbf ;
}
V_16 &= V_11 ;
}
static void F_25 ( void )
{
if ( ! V_17 ) {
F_26 ( V_18 ) ;
F_26 ( V_19 ) ;
V_20 = sizeof( struct V_21 ) ;
return;
}
if ( V_12 )
V_20 = sizeof( struct V_14 ) ;
else
V_20 = sizeof( struct V_22 ) ;
}
void F_27 ( void )
{
unsigned long V_23 ;
unsigned long V_24 = 0 ;
#ifndef F_28
if ( ! V_17 ) {
F_29 ( L_1 ) ;
F_29 ( L_2 ) ;
for (; ; )
asm volatile("hlt");
}
#endif
if ( V_12 )
V_24 |= V_25 ;
if ( V_26 )
V_24 |= V_27 ;
if ( V_24 )
F_30 ( V_24 ) ;
V_23 = F_4 () ;
V_23 &= ~ ( V_2 | V_28 ) ;
if ( ! V_17 )
V_23 |= V_28 ;
F_31 ( V_23 ) ;
if ( V_20 == 0 )
F_25 () ;
F_24 () ;
F_32 () ;
F_33 () ;
}
void F_34 ( struct V_29 * V_29 )
{
if ( ! V_17 ) {
F_35 ( & V_29 -> V_30 -> V_31 ) ;
return;
}
if ( V_12 ) {
F_36 ( & V_29 -> V_30 -> V_32 ) ;
} else {
struct V_22 * V_33 = & V_29 -> V_30 -> V_34 ;
memset ( V_33 , 0 , V_20 ) ;
V_33 -> V_35 = 0xffff037fu ;
V_33 -> V_36 = 0xffff0000u ;
V_33 -> V_37 = 0xffffffffu ;
V_33 -> V_38 = 0xffff0000u ;
}
}
int F_37 ( struct V_5 * V_8 )
{
int V_39 ;
if ( F_17 ( V_8 ) ) {
if ( V_17 && V_8 == V_1 )
F_20 ( V_8 ) ;
V_8 -> V_9 . V_29 . V_40 = ~ 0 ;
return 0 ;
}
V_39 = F_38 ( & V_8 -> V_9 . V_29 ) ;
if ( V_39 )
return V_39 ;
F_34 ( & V_8 -> V_9 . V_29 ) ;
F_39 ( V_8 ) ;
return 0 ;
}
int F_40 ( struct V_5 * V_41 , const struct V_42 * V_43 )
{
return F_17 ( V_41 ) ? V_43 -> V_44 : 0 ;
}
int F_41 ( struct V_5 * V_41 , const struct V_42 * V_43 )
{
return ( V_12 && F_17 ( V_41 ) ) ? V_43 -> V_44 : 0 ;
}
int F_42 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
int V_39 ;
if ( ! V_12 )
return - V_49 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_43 ( V_41 ) ;
return F_44 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_32 , 0 , - 1 ) ;
}
int F_45 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
int V_39 ;
if ( ! V_12 )
return - V_49 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_43 ( V_41 ) ;
V_39 = F_46 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_32 , 0 , - 1 ) ;
V_41 -> V_9 . V_29 . V_30 -> V_32 . V_50 &= V_16 ;
if ( V_51 )
V_41 -> V_9 . V_29 . V_30 -> V_52 . V_53 . V_54 |= V_55 ;
return V_39 ;
}
int F_47 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
int V_39 ;
if ( ! V_51 )
return - V_49 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
memcpy ( & V_41 -> V_9 . V_29 . V_30 -> V_32 . V_56 ,
V_57 , sizeof( V_57 ) ) ;
V_39 = F_44 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_52 , 0 , - 1 ) ;
return V_39 ;
}
int F_48 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
int V_39 ;
struct V_58 * V_53 ;
if ( ! V_51 )
return - V_49 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_46 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_52 , 0 , - 1 ) ;
V_41 -> V_9 . V_29 . V_30 -> V_32 . V_50 &= V_16 ;
V_53 = & V_41 -> V_9 . V_29 . V_30 -> V_52 . V_53 ;
V_53 -> V_54 &= V_59 ;
memset ( V_53 -> V_60 , 0 , 48 ) ;
return V_39 ;
}
static inline unsigned short F_49 ( unsigned short V_37 )
{
unsigned int V_61 ;
V_61 = ~ V_37 ;
V_61 = ( V_61 | ( V_61 >> 1 ) ) & 0x5555 ;
V_61 = ( V_61 | ( V_61 >> 1 ) ) & 0x3333 ;
V_61 = ( V_61 | ( V_61 >> 2 ) ) & 0x0f0f ;
V_61 = ( V_61 | ( V_61 >> 4 ) ) & 0x00ff ;
return V_61 ;
}
static inline T_2 F_50 ( struct V_14 * V_32 )
{
struct V_62 * V_63 ;
T_2 V_64 = ( V_32 -> V_36 >> 11 ) & 7 ;
T_2 V_37 = ( unsigned long ) V_32 -> V_37 ;
T_2 V_65 ;
T_2 V_39 = 0xffff0000u ;
int V_66 ;
for ( V_66 = 0 ; V_66 < 8 ; V_66 ++ , V_37 >>= 1 ) {
if ( V_37 & 0x1 ) {
V_63 = F_51 ( V_32 , ( V_66 - V_64 ) & 7 ) ;
switch ( V_63 -> V_67 & 0x7fff ) {
case 0x7fff :
V_65 = V_68 ;
break;
case 0x0000 :
if ( ! V_63 -> V_69 [ 0 ] &&
! V_63 -> V_69 [ 1 ] &&
! V_63 -> V_69 [ 2 ] &&
! V_63 -> V_69 [ 3 ] )
V_65 = V_70 ;
else
V_65 = V_68 ;
break;
default:
if ( V_63 -> V_69 [ 3 ] & 0x8000 )
V_65 = V_71 ;
else
V_65 = V_68 ;
break;
}
} else {
V_65 = V_72 ;
}
V_39 |= V_65 << ( 2 * V_66 ) ;
}
return V_39 ;
}
void
F_52 ( struct V_73 * V_74 , struct V_5 * V_8 )
{
struct V_14 * V_32 = & V_8 -> V_9 . V_29 . V_30 -> V_32 ;
struct V_75 * V_76 = (struct V_75 * ) & V_74 -> V_77 [ 0 ] ;
struct V_62 * V_78 = (struct V_62 * ) & V_32 -> V_77 [ 0 ] ;
int V_66 ;
V_74 -> V_35 = V_32 -> V_35 | 0xffff0000u ;
V_74 -> V_36 = V_32 -> V_36 | 0xffff0000u ;
V_74 -> V_37 = F_50 ( V_32 ) ;
#ifdef F_53
V_74 -> V_79 = V_32 -> V_80 ;
V_74 -> V_81 = V_32 -> V_82 ;
V_74 -> V_83 = F_54 ( V_8 ) -> V_84 ;
if ( V_8 == V_1 ) {
F_55 ( V_85 , V_74 -> V_38 ) ;
} else {
V_74 -> V_38 = V_8 -> V_9 . V_85 ;
}
V_74 -> V_38 |= 0xffff0000 ;
#else
V_74 -> V_79 = V_32 -> V_79 ;
V_74 -> V_83 = ( V_86 ) V_32 -> V_83 | ( ( T_2 ) V_32 -> V_87 << 16 ) ;
V_74 -> V_81 = V_32 -> V_81 ;
V_74 -> V_38 = V_32 -> V_38 ;
#endif
for ( V_66 = 0 ; V_66 < 8 ; ++ V_66 )
memcpy ( & V_76 [ V_66 ] , & V_78 [ V_66 ] , sizeof( V_76 [ 0 ] ) ) ;
}
void F_56 ( struct V_5 * V_8 ,
const struct V_73 * V_74 )
{
struct V_14 * V_32 = & V_8 -> V_9 . V_29 . V_30 -> V_32 ;
struct V_75 * V_78 = (struct V_75 * ) & V_74 -> V_77 [ 0 ] ;
struct V_62 * V_76 = (struct V_62 * ) & V_32 -> V_77 [ 0 ] ;
int V_66 ;
V_32 -> V_35 = V_74 -> V_35 ;
V_32 -> V_36 = V_74 -> V_36 ;
V_32 -> V_37 = F_49 ( V_74 -> V_37 ) ;
V_32 -> V_87 = ( V_86 ) ( ( T_2 ) V_74 -> V_83 >> 16 ) ;
#ifdef F_53
V_32 -> V_80 = V_74 -> V_79 ;
V_32 -> V_82 = V_74 -> V_81 ;
#else
V_32 -> V_79 = V_74 -> V_79 ;
V_32 -> V_83 = ( V_74 -> V_83 & 0xffff ) ;
V_32 -> V_81 = V_74 -> V_81 ;
V_32 -> V_38 = V_74 -> V_38 ;
#endif
for ( V_66 = 0 ; V_66 < 8 ; ++ V_66 )
memcpy ( & V_76 [ V_66 ] , & V_78 [ V_66 ] , sizeof( V_78 [ 0 ] ) ) ;
}
int F_57 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
void * V_47 , void T_1 * V_48 )
{
struct V_73 V_74 ;
int V_39 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
if ( ! F_58 ( V_88 ) )
return F_59 ( V_41 , V_43 , V_45 , V_46 , V_47 , V_48 ) ;
if ( ! V_12 )
return F_44 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_34 , 0 ,
- 1 ) ;
F_43 ( V_41 ) ;
if ( V_47 && V_45 == 0 && V_46 == sizeof( V_74 ) ) {
F_52 ( V_47 , V_41 ) ;
return 0 ;
}
F_52 ( & V_74 , V_41 ) ;
return F_44 ( & V_45 , & V_46 , & V_47 , & V_48 , & V_74 , 0 , - 1 ) ;
}
int F_60 ( struct V_5 * V_41 , const struct V_42 * V_43 ,
unsigned int V_45 , unsigned int V_46 ,
const void * V_47 , const void T_1 * V_48 )
{
struct V_73 V_74 ;
int V_39 ;
V_39 = F_37 ( V_41 ) ;
if ( V_39 )
return V_39 ;
F_43 ( V_41 ) ;
if ( ! F_58 ( V_88 ) )
return F_61 ( V_41 , V_43 , V_45 , V_46 , V_47 , V_48 ) ;
if ( ! V_12 )
return F_46 ( & V_45 , & V_46 , & V_47 , & V_48 ,
& V_41 -> V_9 . V_29 . V_30 -> V_34 , 0 ,
- 1 ) ;
if ( V_45 > 0 || V_46 < sizeof( V_74 ) )
F_52 ( & V_74 , V_41 ) ;
V_39 = F_46 ( & V_45 , & V_46 , & V_47 , & V_48 , & V_74 , 0 , - 1 ) ;
if ( ! V_39 )
F_56 ( V_41 , & V_74 ) ;
if ( V_51 )
V_41 -> V_9 . V_29 . V_30 -> V_52 . V_53 . V_54 |= V_89 ;
return V_39 ;
}
int F_62 ( struct V_3 * V_4 , struct V_90 * V_29 )
{
struct V_5 * V_8 = V_1 ;
int V_91 ;
V_91 = ! ! F_63 () ;
if ( V_91 )
V_91 = ! F_57 ( V_8 , NULL ,
0 , sizeof( struct V_73 ) ,
V_29 , NULL ) ;
return V_91 ;
}
static int T_3 F_64 ( char * V_92 )
{
F_26 ( V_88 ) ;
return 1 ;
}
void F_65 ( struct V_93 * V_94 )
{
unsigned long V_23 ;
V_86 V_95 , V_96 ;
V_95 = V_96 = 0xffff ;
V_23 = F_4 () ;
V_23 &= ~ ( V_2 | V_28 ) ;
F_31 ( V_23 ) ;
asm volatile("fninit ; fnstsw %0 ; fnstcw %1"
: "+m" (fsw), "+m" (fcw));
if ( V_95 == 0 && ( V_96 & 0x103f ) == 0x003f )
F_66 ( V_94 , V_88 ) ;
else
F_67 ( V_94 , V_88 ) ;
}
