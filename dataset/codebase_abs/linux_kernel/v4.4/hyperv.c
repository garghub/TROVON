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
case V_10 :
V_2 = true ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_11 * V_12 ,
T_1 V_13 , T_2 * V_14 )
{
struct V_15 * V_16 = & V_12 -> V_17 -> V_18 . V_19 ;
if ( F_3 ( V_13 >= F_4 ( V_16 -> V_20 ) ) )
return - V_21 ;
* V_14 = V_16 -> V_20 [ V_13 ] ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 , T_2 * V_14 )
{
struct V_15 * V_16 = & V_12 -> V_17 -> V_18 . V_19 ;
* V_14 = V_16 -> V_22 ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 , T_2 V_23 , bool V_24 )
{
struct V_15 * V_16 = & V_12 -> V_17 -> V_18 . V_19 ;
if ( V_24 )
V_16 -> V_22 = V_23 & V_25 ;
if ( ! V_24 && ( V_23 & V_25 ) ) {
F_7 ( V_12 , L_1 ,
V_16 -> V_20 [ 0 ] ,
V_16 -> V_20 [ 1 ] ,
V_16 -> V_20 [ 2 ] ,
V_16 -> V_20 [ 3 ] ,
V_16 -> V_20 [ 4 ] ) ;
F_8 ( V_26 , V_12 ) ;
}
return 0 ;
}
static int F_9 ( struct V_11 * V_12 ,
T_1 V_13 , T_2 V_23 )
{
struct V_15 * V_16 = & V_12 -> V_17 -> V_18 . V_19 ;
if ( F_3 ( V_13 >= F_4 ( V_16 -> V_20 ) ) )
return - V_21 ;
V_16 -> V_20 [ V_13 ] = V_23 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , T_1 V_1 , T_2 V_23 ,
bool V_24 )
{
struct V_17 * V_17 = V_12 -> V_17 ;
struct V_15 * V_16 = & V_17 -> V_18 . V_19 ;
switch ( V_1 ) {
case V_3 :
V_16 -> V_27 = V_23 ;
if ( ! V_16 -> V_27 )
V_16 -> V_28 &= ~ V_29 ;
break;
case V_4 : {
T_2 V_30 ;
unsigned long V_31 ;
T_3 V_32 [ 4 ] ;
if ( ! V_16 -> V_27 )
break;
if ( ! ( V_23 & V_29 ) ) {
V_16 -> V_28 = V_23 ;
break;
}
V_30 = V_23 >> V_33 ;
V_31 = F_11 ( V_17 , V_30 ) ;
if ( F_12 ( V_31 ) )
return 1 ;
V_34 -> V_35 ( V_12 , V_32 ) ;
( ( unsigned char * ) V_32 ) [ 3 ] = 0xc3 ;
if ( F_13 ( ( void V_36 * ) V_31 , V_32 , 4 ) )
return 1 ;
V_16 -> V_28 = V_23 ;
F_14 ( V_17 , V_30 ) ;
break;
}
case V_5 : {
T_2 V_30 ;
T_4 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_16 -> V_38 = V_23 ;
if ( ! ( V_23 & V_39 ) )
break;
V_30 = V_23 >> V_40 ;
if ( F_15 (
V_17 ,
V_30 << V_40 ,
& V_37 , sizeof( V_37 ) ) )
return 1 ;
F_14 ( V_17 , V_30 ) ;
break;
}
case V_8 ... V_9 :
return F_9 ( V_12 ,
V_1 - V_8 ,
V_23 ) ;
case V_7 :
return F_6 ( V_12 , V_23 , V_24 ) ;
case V_10 :
if ( V_23 == 1 ) {
F_7 ( V_12 , L_2 ) ;
F_8 ( V_41 , V_12 ) ;
}
break;
default:
F_16 ( V_12 , L_3 ,
V_1 , V_23 ) ;
return 1 ;
}
return 0 ;
}
static T_2 F_17 ( void )
{
T_5 V_42 , V_43 ;
F_18 ( V_44 , & V_42 , & V_43 ) ;
return F_19 ( F_20 ( V_42 + V_43 ) , 100 ) ;
}
static int F_21 ( struct V_11 * V_12 , T_1 V_1 , T_2 V_23 , bool V_24 )
{
struct V_45 * V_16 = & V_12 -> V_18 . V_19 ;
switch ( V_1 ) {
case V_46 : {
T_2 V_30 ;
unsigned long V_31 ;
if ( ! ( V_23 & V_47 ) ) {
V_16 -> V_48 = V_23 ;
if ( F_22 ( V_12 , 0 ) )
return 1 ;
break;
}
V_30 = V_23 >> V_49 ;
V_31 = F_23 ( V_12 , V_30 ) ;
if ( F_12 ( V_31 ) )
return 1 ;
if ( F_24 ( ( void V_36 * ) V_31 , V_50 ) )
return 1 ;
V_16 -> V_48 = V_23 ;
F_25 ( V_12 , V_30 ) ;
if ( F_22 ( V_12 ,
F_26 ( V_30 ) | V_51 ) )
return 1 ;
break;
}
case V_52 :
return F_27 ( V_12 , V_53 , V_23 ) ;
case V_54 :
return F_27 ( V_12 , V_55 , V_23 ) ;
case V_56 :
return F_27 ( V_12 , V_57 , V_23 ) ;
case V_58 :
if ( ! V_24 )
return 1 ;
V_16 -> V_59 = V_23 - F_17 () ;
break;
default:
F_16 ( V_12 , L_3 ,
V_1 , V_23 ) ;
return 1 ;
}
return 0 ;
}
static int F_28 ( struct V_11 * V_12 , T_1 V_1 , T_2 * V_14 )
{
T_2 V_23 = 0 ;
struct V_17 * V_17 = V_12 -> V_17 ;
struct V_15 * V_16 = & V_17 -> V_18 . V_19 ;
switch ( V_1 ) {
case V_3 :
V_23 = V_16 -> V_27 ;
break;
case V_4 :
V_23 = V_16 -> V_28 ;
break;
case V_6 : {
V_23 =
F_19 ( F_29 () + V_17 -> V_18 . V_60 , 100 ) ;
break;
}
case V_5 :
V_23 = V_16 -> V_38 ;
break;
case V_8 ... V_9 :
return F_2 ( V_12 ,
V_1 - V_8 ,
V_14 ) ;
case V_7 :
return F_5 ( V_12 , V_14 ) ;
case V_10 :
V_23 = 0 ;
break;
default:
F_16 ( V_12 , L_4 , V_1 ) ;
return 1 ;
}
* V_14 = V_23 ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , T_1 V_1 , T_2 * V_14 )
{
T_2 V_23 = 0 ;
struct V_45 * V_16 = & V_12 -> V_18 . V_19 ;
switch ( V_1 ) {
case V_61 : {
int V_2 ;
struct V_11 * V_62 ;
F_31 (r, v, vcpu->kvm) {
if ( V_62 == V_12 ) {
V_23 = V_2 ;
break;
}
}
break;
}
case V_52 :
return F_32 ( V_12 , V_53 , V_14 ) ;
case V_54 :
return F_32 ( V_12 , V_55 , V_14 ) ;
case V_56 :
return F_32 ( V_12 , V_57 , V_14 ) ;
case V_46 :
V_23 = V_16 -> V_48 ;
break;
case V_58 :
V_23 = F_17 () + V_16 -> V_59 ;
break;
default:
F_16 ( V_12 , L_4 , V_1 ) ;
return 1 ;
}
* V_14 = V_23 ;
return 0 ;
}
int F_33 ( struct V_11 * V_12 , T_1 V_1 , T_2 V_23 , bool V_24 )
{
if ( F_1 ( V_1 ) ) {
int V_2 ;
F_34 ( & V_12 -> V_17 -> V_63 ) ;
V_2 = F_10 ( V_12 , V_1 , V_23 , V_24 ) ;
F_35 ( & V_12 -> V_17 -> V_63 ) ;
return V_2 ;
} else
return F_21 ( V_12 , V_1 , V_23 , V_24 ) ;
}
int F_36 ( struct V_11 * V_12 , T_1 V_1 , T_2 * V_14 )
{
if ( F_1 ( V_1 ) ) {
int V_2 ;
F_34 ( & V_12 -> V_17 -> V_63 ) ;
V_2 = F_28 ( V_12 , V_1 , V_14 ) ;
F_35 ( & V_12 -> V_17 -> V_63 ) ;
return V_2 ;
} else
return F_30 ( V_12 , V_1 , V_14 ) ;
}
bool F_37 ( struct V_17 * V_17 )
{
return V_17 -> V_18 . V_19 . V_28 & V_29 ;
}
int F_38 ( struct V_11 * V_12 )
{
T_2 V_64 , V_65 , V_66 , V_67 ;
T_6 V_68 , V_69 , V_70 , V_71 = V_72 , V_73 = 0 ;
bool V_74 , V_75 ;
if ( V_34 -> V_76 ( V_12 ) != 0 || ! F_39 ( V_12 ) ) {
F_40 ( V_12 , V_77 ) ;
return 0 ;
}
V_75 = F_41 ( V_12 ) ;
if ( ! V_75 ) {
V_64 = ( ( T_2 ) F_42 ( V_12 , V_78 ) << 32 ) |
( F_42 ( V_12 , V_79 ) & 0xffffffff ) ;
V_65 = ( ( T_2 ) F_42 ( V_12 , V_80 ) << 32 ) |
( F_42 ( V_12 , V_81 ) & 0xffffffff ) ;
V_66 = ( ( T_2 ) F_42 ( V_12 , V_82 ) << 32 ) |
( F_42 ( V_12 , V_83 ) & 0xffffffff ) ;
}
#ifdef F_43
else {
V_64 = F_42 ( V_12 , V_81 ) ;
V_65 = F_42 ( V_12 , V_78 ) ;
V_66 = F_42 ( V_12 , V_84 ) ;
}
#endif
V_68 = V_64 & 0xffff ;
V_74 = ( V_64 >> 16 ) & 0x1 ;
V_70 = ( V_64 >> 32 ) & 0xfff ;
V_69 = ( V_64 >> 48 ) & 0xfff ;
F_44 ( V_68 , V_74 , V_70 , V_69 , V_65 , V_66 ) ;
switch ( V_68 ) {
case V_85 :
F_45 ( V_12 ) ;
break;
default:
V_71 = V_86 ;
break;
}
V_67 = V_71 | ( ( ( T_2 ) V_73 & 0xfff ) << 32 ) ;
if ( V_75 ) {
F_46 ( V_12 , V_79 , V_67 ) ;
} else {
F_46 ( V_12 , V_78 , V_67 >> 32 ) ;
F_46 ( V_12 , V_79 , V_67 & 0xffffffff ) ;
}
return 1 ;
}
