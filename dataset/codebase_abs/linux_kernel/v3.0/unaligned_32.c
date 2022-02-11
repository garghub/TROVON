static inline enum V_1 F_1 ( unsigned int V_2 )
{
unsigned long V_3 = ( V_2 >> 21 ) & 1 ;
if( ! V_3 )
return V_4 ;
else {
if( ( ( V_2 >> 19 ) & 0x3f ) == 15 )
return V_5 ;
else
return V_6 ;
}
}
static inline int F_2 ( unsigned int V_2 )
{
V_2 = ( V_2 >> 19 ) & 3 ;
if( ! V_2 )
return 4 ;
else if( V_2 == 3 )
return 8 ;
else if( V_2 == 2 )
return 2 ;
else {
F_3 ( L_1 , V_2 ) ;
F_4 ( L_2 , V_7 -> V_8 . V_9 ) ;
return 4 ;
}
}
static inline int F_5 ( unsigned int V_2 )
{
return ( V_2 & 0x400000 ) ;
}
static inline void F_6 ( unsigned int V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
if( V_11 >= 16 || V_10 >= 16 || V_12 >= 16 ) {
__asm__ __volatile__("save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"restore; restore; restore; restore;\n\t"
"restore; restore; restore;\n\t");
}
}
static inline int F_7 ( int V_13 )
{
return V_13 << 19 >> 19 ;
}
static inline unsigned long F_8 ( unsigned int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
if( V_14 < 16 )
return ( ! V_14 ? 0 : V_16 -> V_19 [ V_14 ] ) ;
V_18 = (struct V_17 * ) V_16 -> V_19 [ V_20 ] ;
return V_18 -> V_21 [ V_14 - 16 ] ;
}
static inline unsigned long F_9 ( unsigned int V_14 , struct V_15 * V_16 )
{
struct V_17 T_1 * V_18 ;
unsigned long V_22 ;
if ( V_14 < 16 )
return ( ! V_14 ? 0 : V_16 -> V_19 [ V_14 ] ) ;
V_18 = (struct V_17 T_1 * ) V_16 -> V_19 [ V_20 ] ;
if ( ( unsigned long ) V_18 & 3 )
return - 1 ;
if ( F_10 ( V_22 , & V_18 -> V_21 [ V_14 - 16 ] ) )
return - 1 ;
return V_22 ;
}
static inline unsigned long * F_11 ( unsigned int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
if( V_14 < 16 )
return & V_16 -> V_19 [ V_14 ] ;
V_18 = (struct V_17 * ) V_16 -> V_19 [ V_20 ] ;
return & V_18 -> V_21 [ V_14 - 16 ] ;
}
static unsigned long F_12 ( struct V_15 * V_16 ,
unsigned int V_2 )
{
unsigned int V_10 = ( V_2 >> 14 ) & 0x1f ;
unsigned int V_11 = V_2 & 0x1f ;
unsigned int V_12 = ( V_2 >> 25 ) & 0x1f ;
if( V_2 & 0x2000 ) {
F_6 ( V_10 , 0 , V_12 ) ;
return ( F_8 ( V_10 , V_16 ) + F_7 ( V_2 ) ) ;
} else {
F_6 ( V_10 , V_11 , V_12 ) ;
return ( F_8 ( V_10 , V_16 ) + F_8 ( V_11 , V_16 ) ) ;
}
}
unsigned long F_13 ( struct V_15 * V_16 ,
unsigned int V_2 )
{
unsigned int V_10 = ( V_2 >> 14 ) & 0x1f ;
unsigned int V_11 = V_2 & 0x1f ;
unsigned int V_12 = ( V_2 >> 25 ) & 0x1f ;
if( V_2 & 0x2000 ) {
F_6 ( V_10 , 0 , V_12 ) ;
return ( F_9 ( V_10 , V_16 ) + F_7 ( V_2 ) ) ;
} else {
F_6 ( V_10 , V_11 , V_12 ) ;
return ( F_9 ( V_10 , V_16 ) + F_9 ( V_11 , V_16 ) ) ;
}
}
static void F_14 ( char * V_23 )
{
F_15 ( V_23 ) ;
}
static int F_16 ( int V_24 , int V_25 , unsigned long * V_26 ,
struct V_15 * V_16 )
{
unsigned long V_27 [ 2 ] = { 0 , 0 } ;
unsigned long * V_28 ;
if ( V_24 )
V_28 = F_11 ( V_24 , V_16 ) ;
else {
V_28 = & V_27 [ 0 ] ;
if ( V_25 == 8 )
V_27 [ 1 ] = F_8 ( 1 , V_16 ) ;
}
return F_17 ( V_26 , V_25 , V_28 ) ;
}
static inline void F_18 ( struct V_15 * V_16 )
{
V_16 -> V_29 = V_16 -> V_30 ;
V_16 -> V_30 += 4 ;
}
static inline int F_19 ( unsigned int V_2 )
{
return ( V_2 >> 24 ) & 1 ;
}
static inline int F_20 ( unsigned int V_2 )
{
return ! F_19 ( V_2 ) ;
}
static void F_21 ( struct V_15 * V_16 , unsigned int V_2 )
{
unsigned long V_31 = V_16 -> V_19 [ V_32 ] ;
unsigned long V_33 = F_22 ( V_16 -> V_29 , & V_31 ) ;
if ( ! V_33 ) {
unsigned long V_34 = F_12 ( V_16 , V_2 ) ;
if( V_34 < V_35 ) {
F_3 ( V_36 L_3 ) ;
} else
F_3 ( V_36 L_4 ) ;
F_3 ( V_36 L_5 , V_34 ) ;
F_3 ( V_36 L_6 ,
( V_7 -> V_37 ? V_7 -> V_37 -> V_38 :
V_7 -> V_39 -> V_38 ) ) ;
F_3 ( V_36 L_7 ,
( V_7 -> V_37 ? ( unsigned long ) V_7 -> V_37 -> V_40 :
( unsigned long ) V_7 -> V_39 -> V_40 ) ) ;
F_4 ( L_8 , V_16 ) ;
}
V_16 -> V_29 = V_33 ;
V_16 -> V_30 = V_16 -> V_29 + 4 ;
V_16 -> V_19 [ V_32 ] = V_31 ;
}
T_2 void F_23 ( struct V_15 * V_16 , unsigned int V_2 )
{
enum V_1 V_41 = F_1 ( V_2 ) ;
int V_25 = F_2 ( V_2 ) ;
if( ! F_20 ( V_2 ) || V_41 == V_5 ) {
F_3 ( L_9 ,
V_16 -> V_29 ) ;
F_14 ( L_10 ) ;
} else {
unsigned long V_42 = F_12 ( V_16 , V_2 ) ;
int V_43 ;
F_24 ( V_44 , 1 , 0 , V_16 , V_42 ) ;
switch ( V_41 ) {
case V_4 :
V_43 = F_25 ( F_11 ( ( ( V_2 >> 25 ) & 0x1f ) ,
V_16 ) ,
V_25 , ( unsigned long * ) V_42 ,
F_5 ( V_2 ) ) ;
break;
case V_6 :
V_43 = F_16 ( ( ( V_2 >> 25 ) & 0x1f ) , V_25 ,
( unsigned long * ) V_42 , V_16 ) ;
break;
default:
F_15 ( L_11 ) ;
}
if ( V_43 )
F_21 ( V_16 , V_2 ) ;
else
F_18 ( V_16 ) ;
}
}
static inline int F_26 ( struct V_15 * V_16 , unsigned int V_2 ,
enum V_1 V_41 )
{
unsigned int V_14 ;
int V_45 = ( V_41 == V_4 ) ? V_46 : V_47 ;
int V_25 = ( ( V_2 >> 19 ) & 3 ) == 3 ? 8 : 4 ;
if ( ( V_16 -> V_29 | V_16 -> V_30 ) & 3 )
return 0 ;
#define F_27 ( T_3 ) \
((void __user *)(((unsigned long *)regs->u_regs[UREG_FP])+(regnum)))
V_14 = ( V_2 >> 25 ) & 0x1f ;
if ( V_14 >= 16 ) {
if ( ! F_28 ( V_45 , F_27 ( V_14 - 16 ) , V_25 ) )
return - V_48 ;
}
V_14 = ( V_2 >> 14 ) & 0x1f ;
if ( V_14 >= 16 ) {
if ( ! F_28 ( V_45 , F_27 ( V_14 - 16 ) , V_25 ) )
return - V_48 ;
}
if ( ! ( V_2 & 0x2000 ) ) {
V_14 = ( V_2 & 0x1f ) ;
if ( V_14 >= 16 ) {
if ( ! F_28 ( V_45 , F_27 ( V_14 - 16 ) , V_25 ) )
return - V_48 ;
}
}
#undef F_27
return 0 ;
}
static void F_29 ( struct V_15 * V_16 , unsigned int V_2 )
{
T_4 V_49 ;
V_49 . V_50 = V_51 ;
V_49 . V_52 = 0 ;
V_49 . V_53 = V_54 ;
V_49 . V_55 = ( void T_1 * ) F_13 ( V_16 , V_2 ) ;
V_49 . V_56 = 0 ;
F_30 ( V_51 , & V_49 , V_7 ) ;
}
T_2 void F_31 ( struct V_15 * V_16 , unsigned int V_2 )
{
enum V_1 V_41 ;
if( ! ( V_7 -> V_8 . V_57 & V_58 ) ||
( ( ( V_2 >> 30 ) & 3 ) != 3 ) )
goto V_59;
V_41 = F_1 ( V_2 ) ;
if( ! F_26 ( V_16 , V_2 , V_41 ) ) {
goto V_59;
} else {
int V_43 , V_25 = F_2 ( V_2 ) ;
unsigned long V_42 ;
if( F_19 ( V_2 ) ) {
F_3 ( L_12 ) ;
goto V_59;
}
V_42 = F_12 ( V_16 , V_2 ) ;
F_24 ( V_44 , 1 , 0 , V_16 , V_42 ) ;
switch( V_41 ) {
case V_4 :
V_43 = F_25 ( F_11 ( ( ( V_2 >> 25 ) & 0x1f ) ,
V_16 ) ,
V_25 , ( unsigned long * ) V_42 ,
F_5 ( V_2 ) ) ;
break;
case V_6 :
V_43 = F_16 ( ( ( V_2 >> 25 ) & 0x1f ) , V_25 ,
( unsigned long * ) V_42 , V_16 ) ;
break;
case V_5 :
F_3 ( L_13 ) ;
V_43 = - V_48 ;
break;
default:
F_14 ( L_14 ) ;
goto V_60;
}
if ( V_43 )
goto V_59;
else
F_18 ( V_16 ) ;
goto V_60;
}
V_59:
F_29 ( V_16 , V_2 ) ;
V_60:
;
}
