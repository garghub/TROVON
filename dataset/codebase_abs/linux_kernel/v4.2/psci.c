static unsigned long F_1 ( unsigned long V_1 )
{
if ( V_1 <= 3 )
return V_2 & F_2 ( V_1 ) ;
return 0 ;
}
static unsigned long F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
return V_5 ;
}
static void F_5 ( struct V_3 * V_4 )
{
V_4 -> V_6 . V_7 = true ;
}
static unsigned long F_6 ( struct V_3 * V_8 )
{
struct V_9 * V_9 = V_8 -> V_9 ;
struct V_3 * V_4 = NULL ;
T_1 * V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
T_2 V_13 ;
V_11 = * F_7 ( V_8 , 1 ) & V_2 ;
if ( F_8 ( V_8 ) )
V_11 &= ~ ( ( V_14 ) 0 ) ;
V_4 = F_9 ( V_9 , V_11 ) ;
if ( ! V_4 )
return V_15 ;
if ( ! V_4 -> V_6 . V_7 ) {
if ( F_10 ( V_8 ) != V_16 )
return V_17 ;
else
return V_15 ;
}
V_13 = * F_7 ( V_8 , 2 ) ;
V_12 = * F_7 ( V_8 , 3 ) ;
F_11 ( V_4 ) ;
if ( F_8 ( V_4 ) && ( V_13 & 1 ) ) {
V_13 &= ~ ( ( T_2 ) 1 ) ;
F_12 ( V_4 ) ;
}
if ( F_13 ( V_8 ) )
F_14 ( V_4 ) ;
* F_15 ( V_4 ) = V_13 ;
* F_7 ( V_4 , 0 ) = V_12 ;
V_4 -> V_6 . V_7 = false ;
F_16 () ;
V_10 = F_17 ( V_4 ) ;
F_18 ( V_10 ) ;
return V_5 ;
}
static unsigned long F_19 ( struct V_3 * V_4 )
{
int V_18 ;
unsigned long V_19 ;
unsigned long V_20 ;
unsigned long V_21 ;
unsigned long V_22 ;
struct V_9 * V_9 = V_4 -> V_9 ;
struct V_3 * V_23 ;
V_20 = * F_7 ( V_4 , 1 ) ;
V_22 = * F_7 ( V_4 , 2 ) ;
V_21 = F_1 ( V_22 ) ;
if ( ! V_21 )
return V_15 ;
V_20 &= V_21 ;
F_20 (i, tmp, kvm) {
V_19 = F_21 ( V_23 ) ;
if ( ( ( V_19 & V_21 ) == V_20 ) &&
! V_23 -> V_6 . V_7 ) {
return V_24 ;
}
}
return V_25 ;
}
static void F_22 ( struct V_3 * V_4 , V_14 type )
{
int V_18 ;
struct V_3 * V_23 ;
F_20 (i, tmp, vcpu->kvm) {
V_23 -> V_6 . V_7 = true ;
F_23 ( V_23 ) ;
}
memset ( & V_4 -> V_26 -> V_27 , 0 , sizeof( V_4 -> V_26 -> V_27 ) ) ;
V_4 -> V_26 -> V_27 . type = type ;
V_4 -> V_26 -> V_28 = V_29 ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_22 ( V_4 , V_30 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
F_22 ( V_4 , V_31 ) ;
}
int F_10 ( struct V_3 * V_4 )
{
if ( F_26 ( V_32 , V_4 -> V_6 . V_33 ) )
return V_34 ;
return V_16 ;
}
static int F_27 ( struct V_3 * V_4 )
{
int V_35 = 1 ;
unsigned long V_36 = * F_7 ( V_4 , 0 ) & ~ ( ( V_14 ) 0 ) ;
unsigned long V_37 ;
switch ( V_36 ) {
case V_38 :
V_37 = 2 ;
break;
case V_39 :
case V_40 :
V_37 = F_3 ( V_4 ) ;
break;
case V_41 :
F_5 ( V_4 ) ;
V_37 = V_5 ;
break;
case V_42 :
case V_43 :
V_37 = F_6 ( V_4 ) ;
break;
case V_44 :
case V_45 :
V_37 = F_19 ( V_4 ) ;
break;
case V_46 :
V_37 = V_47 ;
break;
case V_48 :
F_24 ( V_4 ) ;
V_37 = V_49 ;
V_35 = 0 ;
break;
case V_50 :
F_25 ( V_4 ) ;
V_37 = V_49 ;
V_35 = 0 ;
break;
default:
V_37 = V_51 ;
break;
}
* F_7 ( V_4 , 0 ) = V_37 ;
return V_35 ;
}
static int F_28 ( struct V_3 * V_4 )
{
unsigned long V_36 = * F_7 ( V_4 , 0 ) & ~ ( ( V_14 ) 0 ) ;
unsigned long V_37 ;
switch ( V_36 ) {
case V_52 :
F_5 ( V_4 ) ;
V_37 = V_5 ;
break;
case V_53 :
V_37 = F_6 ( V_4 ) ;
break;
default:
V_37 = V_51 ;
break;
}
* F_7 ( V_4 , 0 ) = V_37 ;
return 1 ;
}
int F_29 ( struct V_3 * V_4 )
{
switch ( F_10 ( V_4 ) ) {
case V_34 :
return F_27 ( V_4 ) ;
case V_16 :
return F_28 ( V_4 ) ;
default:
return - V_54 ;
} ;
}
