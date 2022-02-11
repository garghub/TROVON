static void F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 ( 0 , 1 , V_2 -> V_5 , V_2 -> V_2 , 4 ,
& V_2 -> V_6 . V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_7 )
{
* V_7 = V_2 -> V_6 . V_7 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
V_2 -> V_6 . V_7 = ( V_7 & V_2 -> V_6 . V_8 ) |
( V_2 -> V_6 . V_7 & ~ V_2 -> V_6 . V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_3 . V_4 ( 0 , 1 , F_5 ( 14 , 0 ) , 0x10 , 4 ,
& V_2 -> V_6 . V_7 ) ;
V_2 -> V_6 . V_7 += 0x400 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_7 )
{
F_2 ( V_2 , V_7 ) ;
if ( * V_7 != V_2 -> V_6 . V_8 )
* V_7 |= 0x100 ;
}
void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_7 = 0x01060100 ;
V_2 -> V_6 . V_8 = 0 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_7 )
{
F_2 ( V_2 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_7 )
{
* V_7 = V_2 -> V_6 . V_7 & 0xfff00ff ;
}
static void T_2 F_10 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_11 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_11 )
V_10 [ V_9 ] . V_11 ( & V_10 [ V_9 ] ) ;
}
}
static inline void F_12 ( T_1 * V_7 , int V_2 , int V_12 )
{
T_3 V_8 ;
* V_7 >>= ( ( V_2 & 3 ) * 8 ) ;
V_8 = 0xFFFFFFFF >> ( ( 4 - V_12 ) * 8 ) ;
* V_7 &= V_8 ;
}
int F_13 ( unsigned int V_13 , int V_2 , int V_12 , T_1 * V_7 )
{
T_1 V_14 , V_15 ;
int V_16 = 0 ;
switch ( V_2 ) {
case V_17 :
case V_17 + 1 :
case V_17 + 2 :
case V_17 + 3 :
* V_7 = 0 ;
break;
case V_18 :
if ( V_12 == 4 )
* V_7 = 0x00010100 ;
break;
case V_19 :
* V_7 = 1 ;
break;
case V_20 :
case V_21 :
V_3 . V_4 ( 0 , 0 , V_13 ,
V_17 , 4 , & V_14 ) ;
V_15 = V_14 + ( 512 * V_22 - 1 ) ;
V_15 >>= 16 ;
V_15 &= 0xFFF0 ;
V_14 >>= 16 ;
V_14 &= 0xFFF0 ;
if ( V_2 == V_21 )
* V_7 = V_15 ;
else if ( V_12 == 2 )
* V_7 = V_14 ;
else
* V_7 = ( V_15 << 16 ) | V_14 ;
break;
case V_23 :
* V_7 = 0xFFF0 ;
break;
case V_24 :
* V_7 = 0x0 ;
break;
case V_25 :
* V_7 = 0xF0 ;
break;
case V_26 :
* V_7 = 0 ;
break;
default:
V_16 = 1 ;
}
return V_16 ;
}
static int F_14 ( unsigned int V_13 , int V_2 , int V_12 , T_1 * V_7 )
{
unsigned long V_27 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_11 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_5 == V_13 &&
V_10 [ V_9 ] . V_2 == ( V_2 & ~ 3 ) &&
V_10 [ V_9 ] . V_4 ) {
F_15 ( & V_28 , V_27 ) ;
V_10 [ V_9 ] . V_4 ( & ( V_10 [ V_9 ] ) , V_7 ) ;
F_16 ( & V_28 , V_27 ) ;
F_12 ( V_7 , V_2 , V_12 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_17 ( unsigned int V_29 , unsigned int V_30 ,
unsigned int V_13 , int V_2 , int V_12 , T_1 * V_7 )
{
F_18 ( V_29 ) ;
if ( V_30 == 1 && ! F_14 ( V_13 , V_2 , V_12 , V_7 ) )
return 0 ;
if ( V_30 == 0 && ( F_5 ( 1 , 0 ) == V_13 ) &&
! F_13 ( V_13 , V_2 , V_12 , V_7 ) )
return 0 ;
return V_3 . V_4 ( V_29 , V_30 , V_13 , V_2 , V_12 , V_7 ) ;
}
static int F_19 ( unsigned int V_13 , int V_2 , int V_12 , T_1 V_7 )
{
unsigned long V_27 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_11 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_5 == V_13 &&
V_10 [ V_9 ] . V_2 == ( V_2 & ~ 3 ) &&
V_10 [ V_9 ] . V_31 ) {
F_15 ( & V_28 , V_27 ) ;
V_10 [ V_9 ] . V_31 ( & ( V_10 [ V_9 ] ) , V_7 ) ;
F_16 ( & V_28 , V_27 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_20 ( unsigned int V_29 , unsigned int V_30 ,
unsigned int V_13 , int V_2 , int V_12 , T_1 V_7 )
{
F_18 ( V_29 ) ;
if ( V_30 == 1 && ! F_19 ( V_13 , V_2 , V_12 , V_7 ) )
return 0 ;
if ( V_30 == 0 && F_5 ( 1 , 0 ) == V_13 &&
( ( V_2 & ~ 3 ) == V_17 ) )
return 0 ;
return V_3 . V_31 ( V_29 , V_30 , V_13 , V_2 , V_12 , V_7 ) ;
}
int T_2 F_21 ( void )
{
F_10 () ;
V_32 = & V_33 ;
return 1 ;
}
