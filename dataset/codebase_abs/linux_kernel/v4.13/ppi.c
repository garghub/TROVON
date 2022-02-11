static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
const struct V_5 * V_6 = V_4 -> V_6 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned short V_11 ;
V_11 = F_2 ( & V_9 -> V_11 ) ;
if ( V_11 & 0x3000 )
V_4 -> V_12 = true ;
F_3 ( & V_9 -> V_11 , 0xff00 ) ;
break;
}
case V_13 :
{
struct V_14 * V_9 = V_6 -> V_10 ;
unsigned short V_11 ;
V_11 = F_2 ( & V_9 -> V_11 ) ;
if ( V_11 & 0x2 )
V_4 -> V_12 = true ;
F_3 ( & V_9 -> V_11 , 0xffff ) ;
break;
}
case V_15 :
{
struct V_16 * V_9 = V_6 -> V_10 ;
unsigned long V_17 ;
V_17 = F_4 ( & V_9 -> V_17 ) ;
if ( V_17 & 0x2 )
V_4 -> V_12 = true ;
F_5 ( & V_9 -> V_17 , 0xc0ff ) ;
break;
}
default:
break;
}
return V_18 ;
}
static int F_6 ( struct V_3 * V_4 , T_2 V_19 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_20 ;
V_20 = F_7 ( V_6 -> V_21 , L_1 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
return V_20 ;
}
F_9 ( V_6 -> V_21 , V_19 , V_4 ) ;
if ( V_4 -> V_22 ) {
V_20 = F_10 ( V_6 -> V_23 , F_1 , 0 , L_3 , V_4 ) ;
if ( V_20 ) {
F_8 ( L_4 ) ;
F_11 ( V_6 -> V_21 ) ;
}
}
return V_20 ;
}
static void F_12 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_22 )
F_13 ( V_6 -> V_23 , V_4 ) ;
F_11 ( V_6 -> V_21 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
F_15 ( V_6 -> V_21 ) ;
V_4 -> V_24 |= V_25 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_3 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
break;
}
case V_13 :
{
struct V_14 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
break;
}
case V_15 :
{
struct V_16 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_27 , V_4 -> V_24 ) ;
break;
}
default:
return - V_28 ;
}
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
V_4 -> V_24 &= ~ V_25 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_3 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
break;
}
case V_13 :
{
struct V_14 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
break;
}
case V_15 :
{
struct V_16 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_27 , V_4 -> V_24 ) ;
break;
}
default:
return - V_28 ;
}
F_18 ( V_6 -> V_21 ) ;
F_19 ( V_6 -> V_21 ) ;
F_16 () ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , struct V_29 * V_30 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_31 = 0 ;
int V_32 , V_33 ;
int V_34 , V_35 , V_36 ;
#ifdef F_21
static const char * const V_37 [] = { L_5 , L_6 , L_7 } ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
if ( V_30 -> V_42 > 24 || V_30 -> V_42 <= 0 )
return - V_28 ;
V_39 = F_22 ( V_4 -> V_43 ) ;
if ( F_23 ( V_39 ) )
return F_24 ( V_39 ) ;
V_41 = F_25 ( V_39 ,
V_37 [ ( V_30 -> V_42 + 7 ) / 8 - 1 ] ) ;
if ( F_26 ( V_39 , V_41 ) )
return - V_28 ;
#endif
V_33 = V_30 -> V_44 * V_30 -> V_45 / 8 ;
V_34 = V_30 -> V_44 * V_30 -> V_45 / V_30 -> V_42 ;
V_35 = V_30 -> V_35 * V_30 -> V_45 / V_30 -> V_42 ;
V_36 = V_30 -> line * V_30 -> V_45 / V_30 -> V_42 ;
if ( V_30 -> V_46 == 0xFFFFFFFF )
V_4 -> V_22 = false ;
else
V_4 -> V_22 = true ;
V_32 = ( V_47 | V_48 | V_49 | V_50 ) ;
V_4 -> V_24 = V_30 -> V_24 & ~ V_25 ;
if ( ! ( V_4 -> V_24 & V_51 ) )
V_32 |= V_52 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_30 -> V_24 & V_53 )
V_31 = 1 ;
F_3 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
F_3 ( & V_9 -> V_54 , V_36 - 1 ) ;
F_3 ( & V_9 -> V_55 , V_30 -> V_55 ) ;
break;
}
case V_13 :
{
struct V_14 * V_9 = V_6 -> V_10 ;
if ( ( V_30 -> V_24 & V_56 )
|| ( V_30 -> V_24 & 0x38000 ) > V_57 )
V_31 = 1 ;
F_5 ( & V_9 -> V_26 , V_4 -> V_24 ) ;
F_3 ( & V_9 -> line , V_36 ) ;
F_3 ( & V_9 -> V_55 , V_30 -> V_55 ) ;
F_3 ( & V_9 -> V_35 , V_35 ) ;
F_3 ( & V_9 -> V_58 , V_30 -> V_58 ) ;
F_3 ( & V_9 -> V_34 , V_34 ) ;
F_3 ( & V_9 -> V_59 , V_30 -> V_60 ) ;
break;
}
case V_15 :
{
struct V_16 * V_9 = V_6 -> V_10 ;
if ( ( V_30 -> V_24 & V_56 )
|| ( V_30 -> V_24 & 0x70000 ) > V_57 )
V_31 = 1 ;
F_5 ( & V_9 -> V_27 , V_4 -> V_24 ) ;
F_5 ( & V_9 -> line , V_36 ) ;
F_5 ( & V_9 -> V_55 , V_30 -> V_55 ) ;
F_5 ( & V_9 -> V_61 , V_35 ) ;
F_5 ( & V_9 -> V_62 , V_30 -> V_58 ) ;
F_5 ( & V_9 -> V_63 , V_34 ) ;
F_5 ( & V_9 -> V_64 , V_30 -> V_60 ) ;
if ( V_30 -> V_46 )
F_5 ( & V_9 -> V_65 , V_30 -> V_46 & 0xFF ) ;
if ( V_4 -> V_24 & V_51 ) {
T_3 V_66 , V_67 , V_68 ;
V_66 = V_30 -> V_69
* V_30 -> V_45 / V_30 -> V_42 ;
V_67 = V_30 -> V_70 * V_36 ;
V_68 = V_36 * V_30 -> V_55 ;
F_5 ( & V_9 -> V_71 , V_66 ) ;
F_5 ( & V_9 -> V_72 , V_36 ) ;
F_5 ( & V_9 -> V_73 , V_67 ) ;
F_5 ( & V_9 -> V_74 , V_68 ) ;
}
break;
}
default:
return - V_28 ;
}
if ( V_31 ) {
V_32 |= V_75 | V_76 ;
F_27 ( V_6 -> V_21 , V_33 >> 2 ) ;
F_28 ( V_6 -> V_21 , 4 ) ;
F_29 ( V_6 -> V_21 , 4 ) ;
} else {
V_32 |= V_77 | V_78 ;
F_27 ( V_6 -> V_21 , V_33 >> 1 ) ;
F_28 ( V_6 -> V_21 , 2 ) ;
F_29 ( V_6 -> V_21 , 2 ) ;
}
F_30 ( V_6 -> V_21 , V_30 -> V_60 ) ;
F_31 ( V_6 -> V_21 , V_32 ) ;
F_16 () ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 , unsigned long V_79 )
{
F_33 ( V_4 -> V_6 -> V_21 , V_79 ) ;
}
struct V_3 * F_34 ( struct V_80 * V_81 ,
const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_6 || ! V_6 -> V_82 )
return NULL ;
#ifndef F_21
if ( F_35 ( V_6 -> V_82 , V_83 ) ) {
F_36 ( & V_81 -> V_43 , L_8 ) ;
return NULL ;
}
#endif
V_4 = F_37 ( sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 ) {
F_38 ( V_6 -> V_82 ) ;
F_36 ( & V_81 -> V_43 , L_9 ) ;
return NULL ;
}
V_4 -> V_85 = & V_86 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_43 = & V_81 -> V_43 ;
F_39 ( L_10 ) ;
return V_4 ;
}
void F_40 ( struct V_3 * V_4 )
{
F_38 ( V_4 -> V_6 -> V_82 ) ;
F_41 ( V_4 ) ;
}
