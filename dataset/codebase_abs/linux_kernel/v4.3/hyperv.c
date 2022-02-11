static bool F_1 ( T_1 V_1 )
{
bool V_2 = false ;
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 ... V_9 :
V_2 = true ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_10 * V_11 ,
T_1 V_12 , T_2 * V_13 )
{
struct V_14 * V_15 = & V_11 -> V_16 -> V_17 . V_18 ;
if ( F_3 ( V_12 >= F_4 ( V_15 -> V_19 ) ) )
return - V_20 ;
* V_13 = V_15 -> V_19 [ V_12 ] ;
return 0 ;
}
static int F_5 ( struct V_10 * V_11 , T_2 * V_13 )
{
struct V_14 * V_15 = & V_11 -> V_16 -> V_17 . V_18 ;
* V_13 = V_15 -> V_21 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 , T_2 V_22 , bool V_23 )
{
struct V_14 * V_15 = & V_11 -> V_16 -> V_17 . V_18 ;
if ( V_23 )
V_15 -> V_21 = V_22 & V_24 ;
if ( ! V_23 && ( V_22 & V_24 ) ) {
F_7 ( V_11 , L_1 ,
V_15 -> V_19 [ 0 ] ,
V_15 -> V_19 [ 1 ] ,
V_15 -> V_19 [ 2 ] ,
V_15 -> V_19 [ 3 ] ,
V_15 -> V_19 [ 4 ] ) ;
F_8 ( V_25 , V_11 ) ;
}
return 0 ;
}
static int F_9 ( struct V_10 * V_11 ,
T_1 V_12 , T_2 V_22 )
{
struct V_14 * V_15 = & V_11 -> V_16 -> V_17 . V_18 ;
if ( F_3 ( V_12 >= F_4 ( V_15 -> V_19 ) ) )
return - V_20 ;
V_15 -> V_19 [ V_12 ] = V_22 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_1 , T_2 V_22 ,
bool V_23 )
{
struct V_16 * V_16 = V_11 -> V_16 ;
struct V_14 * V_15 = & V_16 -> V_17 . V_18 ;
switch ( V_1 ) {
case V_3 :
V_15 -> V_26 = V_22 ;
if ( ! V_15 -> V_26 )
V_15 -> V_27 &= ~ V_28 ;
break;
case V_4 : {
T_2 V_29 ;
unsigned long V_30 ;
T_3 V_31 [ 4 ] ;
if ( ! V_15 -> V_26 )
break;
if ( ! ( V_22 & V_28 ) ) {
V_15 -> V_27 = V_22 ;
break;
}
V_29 = V_22 >> V_32 ;
V_30 = F_11 ( V_16 , V_29 ) ;
if ( F_12 ( V_30 ) )
return 1 ;
V_33 -> V_34 ( V_11 , V_31 ) ;
( ( unsigned char * ) V_31 ) [ 3 ] = 0xc3 ;
if ( F_13 ( ( void V_35 * ) V_30 , V_31 , 4 ) )
return 1 ;
V_15 -> V_27 = V_22 ;
F_14 ( V_16 , V_29 ) ;
break;
}
case V_5 : {
T_2 V_29 ;
T_4 V_36 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_15 -> V_37 = V_22 ;
if ( ! ( V_22 & V_38 ) )
break;
V_29 = V_22 >> V_39 ;
if ( F_15 (
V_16 ,
V_29 << V_39 ,
& V_36 , sizeof( V_36 ) ) )
return 1 ;
F_14 ( V_16 , V_29 ) ;
break;
}
case V_8 ... V_9 :
return F_9 ( V_11 ,
V_1 - V_8 ,
V_22 ) ;
case V_7 :
return F_6 ( V_11 , V_22 , V_23 ) ;
default:
F_16 ( V_11 , L_2 ,
V_1 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_17 ( struct V_10 * V_11 , T_1 V_1 , T_2 V_22 )
{
struct V_40 * V_15 = & V_11 -> V_17 . V_18 ;
switch ( V_1 ) {
case V_41 : {
T_2 V_29 ;
unsigned long V_30 ;
if ( ! ( V_22 & V_42 ) ) {
V_15 -> V_43 = V_22 ;
if ( F_18 ( V_11 , 0 ) )
return 1 ;
break;
}
V_29 = V_22 >> V_44 ;
V_30 = F_19 ( V_11 , V_29 ) ;
if ( F_12 ( V_30 ) )
return 1 ;
if ( F_20 ( ( void V_35 * ) V_30 , V_45 ) )
return 1 ;
V_15 -> V_43 = V_22 ;
F_21 ( V_11 , V_29 ) ;
if ( F_18 ( V_11 ,
F_22 ( V_29 ) | V_46 ) )
return 1 ;
break;
}
case V_47 :
return F_23 ( V_11 , V_48 , V_22 ) ;
case V_49 :
return F_23 ( V_11 , V_50 , V_22 ) ;
case V_51 :
return F_23 ( V_11 , V_52 , V_22 ) ;
default:
F_16 ( V_11 , L_2 ,
V_1 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 , T_1 V_1 , T_2 * V_13 )
{
T_2 V_22 = 0 ;
struct V_16 * V_16 = V_11 -> V_16 ;
struct V_14 * V_15 = & V_16 -> V_17 . V_18 ;
switch ( V_1 ) {
case V_3 :
V_22 = V_15 -> V_26 ;
break;
case V_4 :
V_22 = V_15 -> V_27 ;
break;
case V_6 : {
V_22 =
F_25 ( F_26 () + V_16 -> V_17 . V_53 , 100 ) ;
break;
}
case V_5 :
V_22 = V_15 -> V_37 ;
break;
case V_8 ... V_9 :
return F_2 ( V_11 ,
V_1 - V_8 ,
V_13 ) ;
case V_7 :
return F_5 ( V_11 , V_13 ) ;
default:
F_16 ( V_11 , L_3 , V_1 ) ;
return 1 ;
}
* V_13 = V_22 ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 , T_1 V_1 , T_2 * V_13 )
{
T_2 V_22 = 0 ;
struct V_40 * V_15 = & V_11 -> V_17 . V_18 ;
switch ( V_1 ) {
case V_54 : {
int V_2 ;
struct V_10 * V_55 ;
F_28 (r, v, vcpu->kvm) {
if ( V_55 == V_11 ) {
V_22 = V_2 ;
break;
}
}
break;
}
case V_47 :
return F_29 ( V_11 , V_48 , V_13 ) ;
case V_49 :
return F_29 ( V_11 , V_50 , V_13 ) ;
case V_51 :
return F_29 ( V_11 , V_52 , V_13 ) ;
case V_41 :
V_22 = V_15 -> V_43 ;
break;
default:
F_16 ( V_11 , L_3 , V_1 ) ;
return 1 ;
}
* V_13 = V_22 ;
return 0 ;
}
int F_30 ( struct V_10 * V_11 , T_1 V_1 , T_2 V_22 , bool V_23 )
{
if ( F_1 ( V_1 ) ) {
int V_2 ;
F_31 ( & V_11 -> V_16 -> V_56 ) ;
V_2 = F_10 ( V_11 , V_1 , V_22 , V_23 ) ;
F_32 ( & V_11 -> V_16 -> V_56 ) ;
return V_2 ;
} else
return F_17 ( V_11 , V_1 , V_22 ) ;
}
int F_33 ( struct V_10 * V_11 , T_1 V_1 , T_2 * V_13 )
{
if ( F_1 ( V_1 ) ) {
int V_2 ;
F_31 ( & V_11 -> V_16 -> V_56 ) ;
V_2 = F_24 ( V_11 , V_1 , V_13 ) ;
F_32 ( & V_11 -> V_16 -> V_56 ) ;
return V_2 ;
} else
return F_27 ( V_11 , V_1 , V_13 ) ;
}
bool F_34 ( struct V_16 * V_16 )
{
return V_16 -> V_17 . V_18 . V_27 & V_28 ;
}
int F_35 ( struct V_10 * V_11 )
{
T_2 V_57 , V_58 , V_59 , V_60 ;
T_5 V_61 , V_62 , V_63 , V_64 = V_65 , V_66 = 0 ;
bool V_67 , V_68 ;
if ( V_33 -> V_69 ( V_11 ) != 0 || ! F_36 ( V_11 ) ) {
F_37 ( V_11 , V_70 ) ;
return 0 ;
}
V_68 = F_38 ( V_11 ) ;
if ( ! V_68 ) {
V_57 = ( ( T_2 ) F_39 ( V_11 , V_71 ) << 32 ) |
( F_39 ( V_11 , V_72 ) & 0xffffffff ) ;
V_58 = ( ( T_2 ) F_39 ( V_11 , V_73 ) << 32 ) |
( F_39 ( V_11 , V_74 ) & 0xffffffff ) ;
V_59 = ( ( T_2 ) F_39 ( V_11 , V_75 ) << 32 ) |
( F_39 ( V_11 , V_76 ) & 0xffffffff ) ;
}
#ifdef F_40
else {
V_57 = F_39 ( V_11 , V_74 ) ;
V_58 = F_39 ( V_11 , V_71 ) ;
V_59 = F_39 ( V_11 , V_77 ) ;
}
#endif
V_61 = V_57 & 0xffff ;
V_67 = ( V_57 >> 16 ) & 0x1 ;
V_63 = ( V_57 >> 32 ) & 0xfff ;
V_62 = ( V_57 >> 48 ) & 0xfff ;
F_41 ( V_61 , V_67 , V_63 , V_62 , V_58 , V_59 ) ;
switch ( V_61 ) {
case V_78 :
F_42 ( V_11 ) ;
break;
default:
V_64 = V_79 ;
break;
}
V_60 = V_64 | ( ( ( T_2 ) V_66 & 0xfff ) << 32 ) ;
if ( V_68 ) {
F_43 ( V_11 , V_72 , V_60 ) ;
} else {
F_43 ( V_11 , V_71 , V_60 >> 32 ) ;
F_43 ( V_11 , V_72 , V_60 & 0xffffffff ) ;
}
return 1 ;
}
