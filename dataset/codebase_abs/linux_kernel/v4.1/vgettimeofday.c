static T_1 T_2 F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
V_4:
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 & 1 ) {
F_3 () ;
goto V_4;
}
return V_3 ;
}
static T_1 T_2 F_4 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
V_3 = F_1 ( V_2 ) ;
F_5 () ;
return V_3 ;
}
static T_1 int F_6 ( const struct V_1 * V_2 , T_2 V_6 )
{
F_5 () ;
return V_2 -> V_5 != V_6 ;
}
static T_1 long F_7 ( T_3 V_7 ,
struct V_8 * V_9 )
{
register struct V_8 * T_4 V_10 ( L_1 ) = V_9 ;
register T_3 T_5 V_10 ( L_2 ) = V_7 ;
register long T_6 V_10 ( L_2 ) ;
register long T_7 V_10 ( L_3 ) = V_11 ;
asm volatile(
" swi #0\n"
: "=r" (ret)
: "r" (clkid), "r" (ts), "r" (nr)
: "memory");
return T_6 ;
}
static T_1 int F_8 ( struct V_8 * T_4 ,
struct V_1 * V_2 )
{
T_2 V_3 ;
do {
V_3 = F_4 ( V_2 ) ;
T_4 -> V_12 = V_2 -> V_13 ;
T_4 -> V_14 = V_2 -> V_15 ;
} while ( F_6 ( V_2 , V_3 ) );
return 0 ;
}
static T_1 int F_9 ( struct V_8 * T_4 ,
struct V_1 * V_2 )
{
struct V_8 V_16 ;
T_2 V_3 ;
do {
V_3 = F_4 ( V_2 ) ;
T_4 -> V_12 = V_2 -> V_13 ;
T_4 -> V_14 = V_2 -> V_15 ;
V_16 . V_12 = V_2 -> V_17 ;
V_16 . V_14 = V_2 -> V_18 ;
} while ( F_6 ( V_2 , V_3 ) );
T_4 -> V_12 += V_16 . V_12 ;
F_10 ( T_4 , V_16 . V_14 ) ;
return 0 ;
}
static T_1 T_8 F_11 ( struct V_1 * V_2 )
{
T_8 V_19 ;
T_8 V_20 ;
T_8 V_21 ;
V_20 = F_12 () ;
V_19 = ( V_20 - V_2 -> V_22 ) & V_2 -> V_23 ;
V_21 = ( V_19 * V_2 -> V_24 ) + V_2 -> V_25 ;
V_21 >>= V_2 -> V_26 ;
return V_21 ;
}
static T_1 int F_13 ( struct V_8 * T_4 , struct V_1 * V_2 )
{
T_8 V_27 ;
T_2 V_3 ;
do {
V_3 = F_4 ( V_2 ) ;
if ( ! V_2 -> V_28 )
return - 1 ;
T_4 -> V_12 = V_2 -> V_29 ;
V_27 = F_11 ( V_2 ) ;
} while ( F_6 ( V_2 , V_3 ) );
T_4 -> V_14 = 0 ;
F_10 ( T_4 , V_27 ) ;
return 0 ;
}
static T_1 int F_14 ( struct V_8 * T_4 , struct V_1 * V_2 )
{
struct V_8 V_16 ;
T_8 V_27 ;
T_2 V_3 ;
do {
V_3 = F_4 ( V_2 ) ;
if ( ! V_2 -> V_28 )
return - 1 ;
T_4 -> V_12 = V_2 -> V_29 ;
V_27 = F_11 ( V_2 ) ;
V_16 . V_12 = V_2 -> V_17 ;
V_16 . V_14 = V_2 -> V_18 ;
} while ( F_6 ( V_2 , V_3 ) );
T_4 -> V_12 += V_16 . V_12 ;
T_4 -> V_14 = 0 ;
F_10 ( T_4 , V_27 + V_16 . V_14 ) ;
return 0 ;
}
static T_1 int F_13 ( struct V_8 * T_4 , struct V_1 * V_2 )
{
return - 1 ;
}
static T_1 int F_14 ( struct V_8 * T_4 , struct V_1 * V_2 )
{
return - 1 ;
}
T_1 int F_15 ( T_3 T_5 , struct V_8 * T_4 )
{
struct V_1 * V_2 ;
int T_6 = - 1 ;
V_2 = F_16 () ;
switch ( T_5 ) {
case V_30 :
T_6 = F_8 ( T_4 , V_2 ) ;
break;
case V_31 :
T_6 = F_9 ( T_4 , V_2 ) ;
break;
case V_32 :
T_6 = F_13 ( T_4 , V_2 ) ;
break;
case V_33 :
T_6 = F_14 ( T_4 , V_2 ) ;
break;
default:
break;
}
if ( T_6 )
T_6 = F_7 ( T_5 , T_4 ) ;
return T_6 ;
}
static T_1 long F_17 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
register struct V_36 * T_9 V_10 ( L_1 ) = V_37 ;
register struct V_34 * T_10 V_10 ( L_2 ) = V_35 ;
register long T_6 V_10 ( L_2 ) ;
register long T_7 V_10 ( L_3 ) = V_38 ;
asm volatile(
" swi #0\n"
: "=r" (ret)
: "r" (tv), "r" (tz), "r" (nr)
: "memory");
return T_6 ;
}
T_1 int F_18 ( struct V_34 * T_10 , struct V_36 * T_9 )
{
struct V_8 T_4 ;
struct V_1 * V_2 ;
int T_6 ;
V_2 = F_16 () ;
T_6 = F_13 ( & T_4 , V_2 ) ;
if ( T_6 )
return F_17 ( T_10 , T_9 ) ;
if ( T_10 ) {
T_10 -> V_12 = T_4 . V_12 ;
T_10 -> V_39 = T_4 . V_14 / 1000 ;
}
if ( T_9 ) {
T_9 -> V_40 = V_2 -> V_40 ;
T_9 -> V_41 = V_2 -> V_41 ;
}
return T_6 ;
}
void F_19 ( void )
{
}
void F_20 ( void )
{
}
void F_21 ( void )
{
}
