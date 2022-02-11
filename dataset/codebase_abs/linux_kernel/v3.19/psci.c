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
struct V_3 * V_4 = NULL , * V_10 ;
T_1 * V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
T_2 V_15 ;
int V_16 ;
V_12 = * F_7 ( V_8 , 1 ) ;
if ( F_8 ( V_8 ) )
V_12 &= ~ ( ( V_17 ) 0 ) ;
F_9 (i, tmp, kvm) {
V_14 = F_10 ( V_10 ) ;
if ( ( V_14 & V_2 ) == ( V_12 & V_2 ) ) {
V_4 = V_10 ;
break;
}
}
if ( ! V_4 )
return V_18 ;
if ( ! V_4 -> V_6 . V_7 ) {
if ( F_11 ( V_8 ) != V_19 )
return V_20 ;
else
return V_18 ;
}
V_15 = * F_7 ( V_8 , 2 ) ;
V_13 = * F_7 ( V_8 , 3 ) ;
F_12 ( V_4 ) ;
if ( F_8 ( V_4 ) && ( V_15 & 1 ) ) {
V_15 &= ~ ( ( T_2 ) 1 ) ;
F_13 ( V_4 ) ;
}
if ( F_14 ( V_8 ) )
F_15 ( V_4 ) ;
* F_16 ( V_4 ) = V_15 ;
* F_7 ( V_4 , 0 ) = V_13 ;
V_4 -> V_6 . V_7 = false ;
F_17 () ;
V_11 = F_18 ( V_4 ) ;
F_19 ( V_11 ) ;
return V_5 ;
}
static unsigned long F_20 ( struct V_3 * V_4 )
{
int V_16 ;
unsigned long V_14 ;
unsigned long V_21 ;
unsigned long V_22 ;
unsigned long V_23 ;
struct V_9 * V_9 = V_4 -> V_9 ;
struct V_3 * V_10 ;
V_21 = * F_7 ( V_4 , 1 ) ;
V_23 = * F_7 ( V_4 , 2 ) ;
V_22 = F_1 ( V_23 ) ;
if ( ! V_22 )
return V_18 ;
V_21 &= V_22 ;
F_9 (i, tmp, kvm) {
V_14 = F_10 ( V_10 ) ;
if ( ( ( V_14 & V_22 ) == V_21 ) &&
! V_10 -> V_6 . V_7 ) {
return V_24 ;
}
}
return V_25 ;
}
static void F_21 ( struct V_3 * V_4 , V_17 type )
{
int V_16 ;
struct V_3 * V_10 ;
F_9 (i, tmp, vcpu->kvm) {
V_10 -> V_6 . V_7 = true ;
F_22 ( V_10 ) ;
}
memset ( & V_4 -> V_26 -> V_27 , 0 , sizeof( V_4 -> V_26 -> V_27 ) ) ;
V_4 -> V_26 -> V_27 . type = type ;
V_4 -> V_26 -> V_28 = V_29 ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_21 ( V_4 , V_30 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_21 ( V_4 , V_31 ) ;
}
int F_11 ( struct V_3 * V_4 )
{
if ( F_25 ( V_32 , V_4 -> V_6 . V_33 ) )
return V_34 ;
return V_19 ;
}
static int F_26 ( struct V_3 * V_4 )
{
int V_35 = 1 ;
unsigned long V_36 = * F_7 ( V_4 , 0 ) & ~ ( ( V_17 ) 0 ) ;
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
V_37 = F_20 ( V_4 ) ;
break;
case V_46 :
case V_47 :
V_37 = V_48 ;
break;
case V_49 :
V_37 = V_50 ;
break;
case V_51 :
case V_52 :
V_37 = V_48 ;
break;
case V_53 :
F_23 ( V_4 ) ;
V_37 = V_54 ;
V_35 = 0 ;
break;
case V_55 :
F_24 ( V_4 ) ;
V_37 = V_54 ;
V_35 = 0 ;
break;
default:
return - V_56 ;
}
* F_7 ( V_4 , 0 ) = V_37 ;
return V_35 ;
}
static int F_27 ( struct V_3 * V_4 )
{
unsigned long V_36 = * F_7 ( V_4 , 0 ) & ~ ( ( V_17 ) 0 ) ;
unsigned long V_37 ;
switch ( V_36 ) {
case V_57 :
F_5 ( V_4 ) ;
V_37 = V_5 ;
break;
case V_58 :
V_37 = F_6 ( V_4 ) ;
break;
case V_59 :
case V_60 :
V_37 = V_48 ;
break;
default:
return - V_56 ;
}
* F_7 ( V_4 , 0 ) = V_37 ;
return 1 ;
}
int F_28 ( struct V_3 * V_4 )
{
switch ( F_11 ( V_4 ) ) {
case V_34 :
return F_26 ( V_4 ) ;
case V_19 :
return F_27 ( V_4 ) ;
default:
return - V_56 ;
} ;
}
