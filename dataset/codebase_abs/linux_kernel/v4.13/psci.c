static unsigned long F_1 ( unsigned long V_1 )
{
if ( V_1 <= 3 )
return V_2 & F_2 ( V_1 ) ;
return 0 ;
}
static unsigned long F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
F_5 ( V_5 , V_4 ) ;
return V_6 ;
}
static void F_6 ( struct V_3 * V_4 )
{
V_4 -> V_7 . V_8 = true ;
F_7 ( V_9 , V_4 ) ;
F_8 ( V_4 ) ;
}
static unsigned long F_9 ( struct V_3 * V_10 )
{
struct V_11 * V_11 = V_10 -> V_11 ;
struct V_3 * V_4 = NULL ;
struct V_12 * V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
T_1 V_16 ;
V_14 = F_10 ( V_10 , 1 ) & V_2 ;
if ( F_11 ( V_10 ) )
V_14 &= ~ ( ( V_17 ) 0 ) ;
V_4 = F_12 ( V_11 , V_14 ) ;
if ( ! V_4 )
return V_18 ;
if ( ! V_4 -> V_7 . V_8 ) {
if ( F_13 ( V_10 ) != V_19 )
return V_20 ;
else
return V_18 ;
}
V_16 = F_10 ( V_10 , 2 ) ;
V_15 = F_10 ( V_10 , 3 ) ;
F_14 ( V_4 ) ;
if ( F_11 ( V_4 ) && ( V_16 & 1 ) ) {
V_16 &= ~ ( ( T_1 ) 1 ) ;
F_15 ( V_4 ) ;
}
if ( F_16 ( V_10 ) )
F_17 ( V_4 ) ;
* F_18 ( V_4 ) = V_16 ;
F_19 ( V_4 , 0 , V_15 ) ;
V_4 -> V_7 . V_8 = false ;
F_20 () ;
V_13 = F_21 ( V_4 ) ;
F_22 ( V_13 ) ;
return V_6 ;
}
static unsigned long F_23 ( struct V_3 * V_4 )
{
int V_21 , V_22 = 0 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
struct V_11 * V_11 = V_4 -> V_11 ;
struct V_3 * V_27 ;
V_24 = F_10 ( V_4 , 1 ) ;
V_26 = F_10 ( V_4 , 2 ) ;
V_25 = F_1 ( V_26 ) ;
if ( ! V_25 )
return V_18 ;
V_24 &= V_25 ;
F_24 (i, tmp, kvm) {
V_23 = F_25 ( V_27 ) ;
if ( ( V_23 & V_25 ) == V_24 ) {
V_22 ++ ;
if ( ! V_27 -> V_7 . V_8 )
return V_28 ;
}
}
if ( ! V_22 )
return V_18 ;
return V_29 ;
}
static void F_26 ( struct V_3 * V_4 , V_17 type )
{
int V_21 ;
struct V_3 * V_27 ;
F_24 (i, tmp, vcpu->kvm)
V_27 -> V_7 . V_8 = true ;
F_27 ( V_4 -> V_11 , V_9 ) ;
memset ( & V_4 -> V_30 -> V_31 , 0 , sizeof( V_4 -> V_30 -> V_31 ) ) ;
V_4 -> V_30 -> V_31 . type = type ;
V_4 -> V_30 -> V_32 = V_33 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_26 ( V_4 , V_34 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_26 ( V_4 , V_35 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
if ( F_30 ( V_36 , V_4 -> V_7 . V_37 ) )
return V_38 ;
return V_19 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
unsigned long V_39 = F_10 ( V_4 , 0 ) & ~ ( ( V_17 ) 0 ) ;
unsigned long V_40 ;
int V_41 = 1 ;
switch ( V_39 ) {
case V_42 :
V_40 = 2 ;
break;
case V_43 :
case V_44 :
V_40 = F_3 ( V_4 ) ;
break;
case V_45 :
F_6 ( V_4 ) ;
V_40 = V_6 ;
break;
case V_46 :
case V_47 :
F_32 ( & V_11 -> V_48 ) ;
V_40 = F_9 ( V_4 ) ;
F_33 ( & V_11 -> V_48 ) ;
break;
case V_49 :
case V_50 :
V_40 = F_23 ( V_4 ) ;
break;
case V_51 :
V_40 = V_52 ;
break;
case V_53 :
F_28 ( V_4 ) ;
V_40 = V_54 ;
V_41 = 0 ;
break;
case V_55 :
F_29 ( V_4 ) ;
V_40 = V_54 ;
V_41 = 0 ;
break;
default:
V_40 = V_56 ;
break;
}
F_19 ( V_4 , 0 , V_40 ) ;
return V_41 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_11 * V_11 = V_4 -> V_11 ;
unsigned long V_39 = F_10 ( V_4 , 0 ) & ~ ( ( V_17 ) 0 ) ;
unsigned long V_40 ;
switch ( V_39 ) {
case V_57 :
F_6 ( V_4 ) ;
V_40 = V_6 ;
break;
case V_58 :
F_32 ( & V_11 -> V_48 ) ;
V_40 = F_9 ( V_4 ) ;
F_33 ( & V_11 -> V_48 ) ;
break;
default:
V_40 = V_56 ;
break;
}
F_19 ( V_4 , 0 , V_40 ) ;
return 1 ;
}
int F_35 ( struct V_3 * V_4 )
{
switch ( F_13 ( V_4 ) ) {
case V_38 :
return F_31 ( V_4 ) ;
case V_19 :
return F_34 ( V_4 ) ;
default:
return - V_59 ;
} ;
}
