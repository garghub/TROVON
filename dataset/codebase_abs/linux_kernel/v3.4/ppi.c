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
F_3 ( & V_9 -> V_11 , 0xff00 ) ;
break;
}
case V_12 :
{
struct V_13 * V_9 = V_6 -> V_10 ;
F_3 ( & V_9 -> V_11 , 0xffff ) ;
break;
}
default:
break;
}
return V_14 ;
}
static int F_4 ( struct V_3 * V_4 , T_2 V_15 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_16 ;
V_16 = F_5 ( V_6 -> V_17 , L_1 ) ;
if ( V_16 ) {
F_6 ( L_2 ) ;
return V_16 ;
}
F_7 ( V_6 -> V_17 , V_15 , V_4 ) ;
if ( V_4 -> V_18 ) {
V_16 = F_8 ( V_6 -> V_19 , F_1 , 0 , L_3 , V_4 ) ;
if ( V_16 ) {
F_6 ( L_4 ) ;
F_9 ( V_6 -> V_17 ) ;
}
}
return V_16 ;
}
static void F_10 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_18 )
F_11 ( V_6 -> V_19 , V_4 ) ;
F_9 ( V_6 -> V_17 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
F_13 ( V_6 -> V_17 ) ;
V_4 -> V_20 |= V_21 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_3 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
break;
}
case V_12 :
{
struct V_13 * V_9 = V_6 -> V_10 ;
F_14 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
break;
}
default:
return - V_23 ;
}
F_15 () ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
V_4 -> V_20 &= ~ V_21 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_3 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
break;
}
case V_12 :
{
struct V_13 * V_9 = V_6 -> V_10 ;
F_14 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
break;
}
default:
return - V_23 ;
}
F_17 ( V_6 -> V_17 ) ;
F_18 ( V_6 -> V_17 ) ;
F_15 () ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 , struct V_24 * V_25 )
{
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_26 = 0 ;
int V_27 , V_28 , V_29 ;
V_28 = V_25 -> V_30 * V_25 -> V_31 / 8 ;
V_29 = V_25 -> V_32 ;
if ( V_25 -> V_33 == 0xFFFFFFFF )
V_4 -> V_18 = false ;
else
V_4 -> V_18 = true ;
V_27 = ( V_34 | V_35 | V_36 | V_37 | V_38 ) ;
V_4 -> V_20 = V_25 -> V_20 & ~ V_21 ;
switch ( V_6 -> type ) {
case V_7 :
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_25 -> V_20 & V_39 )
V_26 = 1 ;
F_3 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
F_3 ( & V_9 -> V_40 , V_28 - 1 ) ;
F_3 ( & V_9 -> V_41 , V_29 ) ;
break;
}
case V_12 :
{
struct V_13 * V_9 = V_6 -> V_10 ;
if ( ( V_25 -> V_20 & V_42 )
|| ( V_25 -> V_20 & 0x38000 ) > V_43 )
V_26 = 1 ;
F_14 ( & V_9 -> V_22 , V_4 -> V_20 ) ;
F_3 ( & V_9 -> line , V_28 + V_25 -> V_44 ) ;
F_3 ( & V_9 -> V_41 , V_29 ) ;
F_3 ( & V_9 -> V_45 , 0 ) ;
F_3 ( & V_9 -> V_46 , 0 ) ;
F_3 ( & V_9 -> V_47 , V_28 ) ;
F_3 ( & V_9 -> V_48 , V_29 ) ;
break;
}
default:
return - V_23 ;
}
if ( V_26 ) {
V_27 |= V_49 ;
F_20 ( V_6 -> V_17 , V_28 >> 2 ) ;
F_21 ( V_6 -> V_17 , 4 ) ;
F_22 ( V_6 -> V_17 , 4 ) ;
} else {
V_27 |= V_50 ;
F_20 ( V_6 -> V_17 , V_28 >> 1 ) ;
F_21 ( V_6 -> V_17 , 2 ) ;
F_22 ( V_6 -> V_17 , 2 ) ;
}
F_23 ( V_6 -> V_17 , V_29 ) ;
F_24 ( V_6 -> V_17 , V_27 ) ;
F_15 () ;
return 0 ;
}
static void F_25 ( struct V_3 * V_4 , unsigned long V_51 )
{
F_26 ( V_4 -> V_6 -> V_17 , V_51 ) ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_6 || ! V_6 -> V_52 )
return NULL ;
if ( F_28 ( V_6 -> V_52 , V_53 ) ) {
F_6 ( L_5 ) ;
return NULL ;
}
V_4 = F_29 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 ) {
F_30 ( V_6 -> V_52 ) ;
F_6 ( L_6 ) ;
return NULL ;
}
V_4 -> V_55 = & V_56 ;
V_4 -> V_6 = V_6 ;
F_31 ( L_7 ) ;
return V_4 ;
}
void F_32 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_6 -> V_52 ) ;
F_33 ( V_4 ) ;
}
