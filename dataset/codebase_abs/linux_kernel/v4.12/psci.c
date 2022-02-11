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
struct V_10 * V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
T_1 V_14 ;
V_12 = F_7 ( V_8 , 1 ) & V_2 ;
if ( F_8 ( V_8 ) )
V_12 &= ~ ( ( V_15 ) 0 ) ;
V_4 = F_9 ( V_9 , V_12 ) ;
if ( ! V_4 )
return V_16 ;
if ( ! V_4 -> V_6 . V_7 ) {
if ( F_10 ( V_8 ) != V_17 )
return V_18 ;
else
return V_16 ;
}
V_14 = F_7 ( V_8 , 2 ) ;
V_13 = F_7 ( V_8 , 3 ) ;
F_11 ( V_4 ) ;
if ( F_8 ( V_4 ) && ( V_14 & 1 ) ) {
V_14 &= ~ ( ( T_1 ) 1 ) ;
F_12 ( V_4 ) ;
}
if ( F_13 ( V_8 ) )
F_14 ( V_4 ) ;
* F_15 ( V_4 ) = V_14 ;
F_16 ( V_4 , 0 , V_13 ) ;
V_4 -> V_6 . V_7 = false ;
F_17 () ;
V_11 = F_18 ( V_4 ) ;
F_19 ( V_11 ) ;
return V_5 ;
}
static unsigned long F_20 ( struct V_3 * V_4 )
{
int V_19 , V_20 = 0 ;
unsigned long V_21 ;
unsigned long V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
struct V_9 * V_9 = V_4 -> V_9 ;
struct V_3 * V_25 ;
V_22 = F_7 ( V_4 , 1 ) ;
V_24 = F_7 ( V_4 , 2 ) ;
V_23 = F_1 ( V_24 ) ;
if ( ! V_23 )
return V_16 ;
V_22 &= V_23 ;
F_21 (i, tmp, kvm) {
V_21 = F_22 ( V_25 ) ;
if ( ( V_21 & V_23 ) == V_22 ) {
V_20 ++ ;
if ( ! V_25 -> V_6 . V_7 )
return V_26 ;
}
}
if ( ! V_20 )
return V_16 ;
return V_27 ;
}
static void F_23 ( struct V_3 * V_4 , V_15 type )
{
int V_19 ;
struct V_3 * V_25 ;
F_21 (i, tmp, vcpu->kvm) {
V_25 -> V_6 . V_7 = true ;
F_24 ( V_25 ) ;
}
memset ( & V_4 -> V_28 -> V_29 , 0 , sizeof( V_4 -> V_28 -> V_29 ) ) ;
V_4 -> V_28 -> V_29 . type = type ;
V_4 -> V_28 -> V_30 = V_31 ;
}
static void F_25 ( struct V_3 * V_4 )
{
F_23 ( V_4 , V_32 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_23 ( V_4 , V_33 ) ;
}
int F_10 ( struct V_3 * V_4 )
{
if ( F_27 ( V_34 , V_4 -> V_6 . V_35 ) )
return V_36 ;
return V_17 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
unsigned long V_37 = F_7 ( V_4 , 0 ) & ~ ( ( V_15 ) 0 ) ;
unsigned long V_38 ;
int V_39 = 1 ;
switch ( V_37 ) {
case V_40 :
V_38 = 2 ;
break;
case V_41 :
case V_42 :
V_38 = F_3 ( V_4 ) ;
break;
case V_43 :
F_5 ( V_4 ) ;
V_38 = V_5 ;
break;
case V_44 :
case V_45 :
F_29 ( & V_9 -> V_46 ) ;
V_38 = F_6 ( V_4 ) ;
F_30 ( & V_9 -> V_46 ) ;
break;
case V_47 :
case V_48 :
V_38 = F_20 ( V_4 ) ;
break;
case V_49 :
V_38 = V_50 ;
break;
case V_51 :
F_25 ( V_4 ) ;
V_38 = V_52 ;
V_39 = 0 ;
break;
case V_53 :
F_26 ( V_4 ) ;
V_38 = V_52 ;
V_39 = 0 ;
break;
default:
V_38 = V_54 ;
break;
}
F_16 ( V_4 , 0 , V_38 ) ;
return V_39 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_9 * V_9 = V_4 -> V_9 ;
unsigned long V_37 = F_7 ( V_4 , 0 ) & ~ ( ( V_15 ) 0 ) ;
unsigned long V_38 ;
switch ( V_37 ) {
case V_55 :
F_5 ( V_4 ) ;
V_38 = V_5 ;
break;
case V_56 :
F_29 ( & V_9 -> V_46 ) ;
V_38 = F_6 ( V_4 ) ;
F_30 ( & V_9 -> V_46 ) ;
break;
default:
V_38 = V_54 ;
break;
}
F_16 ( V_4 , 0 , V_38 ) ;
return 1 ;
}
int F_32 ( struct V_3 * V_4 )
{
switch ( F_10 ( V_4 ) ) {
case V_36 :
return F_28 ( V_4 ) ;
case V_17 :
return F_31 ( V_4 ) ;
default:
return - V_57 ;
} ;
}
