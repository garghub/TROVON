void T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
__asm__ (
"sub %[ret], pc, #4 \n\t"
"str pc, %[addr] \n\t"
"ldr %[scr], %[addr] \n\t"
"sub %[ret], %[scr], %[ret] \n\t"
: [ret] "=r" (ret), [scr] "=r" (scratch), [addr] "+m" (addr));
V_4 = V_3 ;
}
void T_1 F_2 ( void )
{
int V_5 = F_3 () ;
F_4 ( V_5 == V_6 ) ;
V_7 = V_5 >= V_8 ;
}
void T_1 F_5 ( void )
{
int V_5 = F_3 () ;
F_4 ( V_5 == V_6 ) ;
V_9 = V_5 >= V_10 ;
}
void T_1 F_6 ( void )
{
F_1 () ;
F_2 () ;
F_5 () ;
}
static unsigned long T_2 F_7 ( unsigned long V_11 )
{
return V_11 & V_12 ;
}
static unsigned long T_2 F_8 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_12 ;
}
static unsigned long T_2 F_9 ( unsigned long V_11 )
{
return V_11 & V_13 ;
}
static unsigned long T_2 F_10 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_13 ;
}
static unsigned long T_2 F_11 ( unsigned long V_11 )
{
return V_11 & V_14 ;
}
static unsigned long T_2 F_12 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_14 ;
}
static unsigned long T_2 F_13 ( unsigned long V_11 )
{
return V_11 & V_15 ;
}
static unsigned long T_2 F_14 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_15 ;
}
static unsigned long T_2 F_15 ( unsigned long V_11 )
{
V_11 &= ~ ( V_11 >> 1 ) ;
return V_11 & V_13 ;
}
static unsigned long T_2 F_16 ( unsigned long V_11 )
{
V_11 &= ~ ( V_11 >> 1 ) ;
return ( ~ V_11 ) & V_13 ;
}
static unsigned long T_2 F_17 ( unsigned long V_11 )
{
V_11 ^= ( V_11 << 3 ) ;
return ( ~ V_11 ) & V_14 ;
}
static unsigned long T_2 F_18 ( unsigned long V_11 )
{
V_11 ^= ( V_11 << 3 ) ;
return V_11 & V_14 ;
}
static unsigned long T_2 F_19 ( unsigned long V_11 )
{
unsigned long V_16 = V_11 ^ ( V_11 << 3 ) ;
V_16 |= ( V_11 << 1 ) ;
return ( ~ V_16 ) & V_14 ;
}
static unsigned long T_2 F_20 ( unsigned long V_11 )
{
unsigned long V_16 = V_11 ^ ( V_11 << 3 ) ;
V_16 |= ( V_11 << 1 ) ;
return V_16 & V_14 ;
}
static unsigned long T_2 F_21 ( unsigned long V_11 )
{
return true ;
}
void T_2 F_22 ( T_3 V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
}
void T_2 F_23 ( T_3 V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
V_19 -> V_22 () ;
}
static T_3 T_2
F_24 ( T_3 V_23 , struct V_18 * V_19 ,
bool V_24 )
{
#ifdef F_25
if ( V_24 ) {
T_4 * V_25 = ( T_4 * ) V_19 -> V_23 ;
V_25 [ 1 ] = F_26 ( 0x4770 ) ;
V_25 [ 2 ] = F_26 ( 0x4770 ) ;
return V_23 ;
}
V_19 -> V_23 [ 1 ] = F_27 ( 0xe12fff1e ) ;
#else
V_19 -> V_23 [ 1 ] = F_27 ( 0xe1a0f00e ) ;
#endif
if ( V_23 < 0xe0000000 )
V_23 = ( V_23 | 0xe0000000 ) & ~ 0x10000000 ;
return V_23 ;
}
static void T_2
F_28 ( T_3 V_23 , struct V_18 * V_19 ,
bool V_24 )
{
#ifdef F_25
if ( V_24 ) {
T_4 * V_26 = ( T_4 * ) V_19 -> V_23 ;
if ( F_29 ( V_23 ) )
* V_26 ++ = F_26 ( V_23 >> 16 ) ;
* V_26 ++ = F_26 ( V_23 ) ;
return;
}
#endif
V_19 -> V_23 [ 0 ] = F_27 ( V_23 ) ;
}
static bool T_2 F_30 ( T_3 * V_27 , T_5 V_21 , bool V_28 )
{
T_3 V_23 = * V_27 ;
T_3 V_29 = 0xf ;
for (; V_21 != 0 ; V_21 >>= 4 , V_29 <<= 4 ) {
T_3 V_30 = V_31 ;
switch ( V_21 & 0xf ) {
case V_32 :
continue;
case V_33 :
break;
case V_34 :
V_30 = V_35 ;
break;
case V_36 :
if ( ( V_23 ^ 0xdddddddd ) & V_29 )
goto V_37;
break;
case V_38 :
if ( ( V_23 ^ 0xffffffff ) & V_29 )
goto V_37;
break;
case V_39 :
if ( ( ( V_23 ^ 0xdddddddd ) & V_29 ) == 0 )
goto V_37;
break;
case V_40 :
case V_41 :
if ( ( ( V_23 ^ 0xdddddddd ) & 0xdddddddd & V_29 ) == 0 )
goto V_37;
break;
case V_42 :
if ( ! F_31 ( V_23 ) )
break;
case V_43 :
case V_44 :
if ( ( ( V_23 ^ 0xffffffff ) & V_29 ) == 0 )
goto V_37;
break;
}
V_23 &= ~ V_29 ;
V_23 |= V_30 & V_29 ;
}
if ( V_28 )
* V_27 = V_23 ;
return true ;
V_37:
return false ;
}
int T_2
F_32 ( T_3 V_23 , struct V_18 * V_19 ,
const union V_45 * V_46 , bool V_24 ,
bool V_47 , const union V_48 * V_49 )
{
const struct V_50 * V_51 = (struct V_50 * ) V_46 ;
const struct V_50 * V_52 ;
bool V_53 = false ;
if ( V_47 )
V_23 = F_24 ( V_23 , V_19 , V_24 ) ;
for (; ; V_51 = V_52 ) {
enum V_54 type = V_51 -> V_55 . V_56 & V_57 ;
T_5 V_21 = V_51 -> V_55 . V_56 >> V_58 ;
if ( type == V_59 )
return V_60 ;
V_52 = (struct V_50 * )
( ( V_61 ) V_51 + V_62 [ type ] ) ;
if ( ! V_53 && ( V_23 & V_51 -> V_29 . V_56 ) != V_51 -> V_63 . V_56 )
continue;
if ( ! F_30 ( & V_23 , V_21 , V_47 ) )
return V_60 ;
switch ( type ) {
case V_64 : {
struct V_65 * V_66 = (struct V_65 * ) V_51 ;
V_52 = (struct V_50 * ) V_66 -> V_46 . V_46 ;
break;
}
case V_67 : {
struct V_68 * V_66 = (struct V_68 * ) V_51 ;
return V_49 [ V_66 -> V_69 . V_70 ] . V_69 ( V_23 , V_19 , V_51 ) ;
}
case V_71 : {
struct V_72 * V_66 = (struct V_72 * ) V_51 ;
V_19 -> V_73 = V_49 [ V_66 -> V_74 . V_70 ] . V_74 ;
return V_75 ;
}
case V_76 : {
struct V_77 * V_66 = (struct V_77 * ) V_51 ;
if ( ! V_47 )
return V_49 [ V_66 -> V_74 . V_70 ] . V_69 ( V_23 ,
V_19 , V_51 ) ;
V_19 -> V_73 = V_49 [ V_66 -> V_74 . V_70 ] . V_74 ;
F_28 ( V_23 , V_19 , V_24 ) ;
return V_78 ;
}
case V_79 :
V_53 = true ;
break;
case V_80 :
default:
return V_60 ;
}
}
}
