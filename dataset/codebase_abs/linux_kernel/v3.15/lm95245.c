static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_1 * 1000 + V_2 * 1000 / 256 ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
if ( V_1 & 0x80 )
return ( V_1 - 0x100 ) * 1000 ;
return F_1 ( V_1 , V_2 ) ;
}
static struct V_3 * F_3 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_5 ( & V_6 -> V_9 ) ;
if ( F_6 ( V_10 , V_6 -> V_11
+ F_7 ( V_6 -> V_12 ) ) || ! V_6 -> V_13 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < F_8 ( V_15 ) ; V_14 ++ )
V_6 -> V_16 [ V_14 ]
= F_9 ( V_8 ,
V_15 [ V_14 ] ) ;
V_6 -> V_11 = V_10 ;
V_6 -> V_13 = 1 ;
}
F_10 ( & V_6 -> V_9 ) ;
return V_6 ;
}
static unsigned long F_11 ( struct V_7 * V_8 )
{
int V_17 ;
unsigned long V_12 ;
V_17 = F_9 ( V_8 , V_18 ) ;
switch ( V_17 ) {
case V_19 :
V_12 = 63 ;
break;
case V_20 :
V_12 = 364 ;
break;
case V_21 :
V_12 = 1000 ;
break;
case V_22 :
default:
V_12 = 2500 ;
break;
}
return V_12 ;
}
static unsigned long F_12 ( struct V_7 * V_8 ,
unsigned long V_12 )
{
int V_17 ;
if ( V_12 <= 63 ) {
V_12 = 63 ;
V_17 = V_19 ;
} else if ( V_12 <= 364 ) {
V_12 = 364 ;
V_17 = V_20 ;
} else if ( V_12 <= 1000 ) {
V_12 = 1000 ;
V_17 = V_21 ;
} else {
V_12 = 2500 ;
V_17 = V_22 ;
}
F_13 ( V_8 , V_18 , V_17 ) ;
return V_12 ;
}
static T_2 F_14 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
int V_26 ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
if ( V_27 == 0 || V_6 -> V_16 [ V_27 ] & 0x80 )
V_26 = F_2 ( V_6 -> V_16 [ V_27 ] ,
V_6 -> V_16 [ V_27 + 1 ] ) ;
else
V_26 = F_1 ( V_6 -> V_16 [ V_27 + 2 ] ,
V_6 -> V_16 [ V_27 + 3 ] ) ;
return snprintf ( V_25 , V_28 - 1 , L_1 , V_26 ) ;
}
static T_2 F_16 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
return snprintf ( V_25 , V_28 - 1 , L_1 ,
V_6 -> V_16 [ V_27 ] * 1000 ) ;
}
static T_2 F_17 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_30 ;
if ( F_18 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
V_30 /= 1000 ;
V_30 = F_19 ( V_30 , 0 , ( V_27 == 6 ? 127 : 255 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
V_6 -> V_13 = 0 ;
F_13 ( V_8 , V_15 [ V_27 ] , V_30 ) ;
F_10 ( & V_6 -> V_9 ) ;
return V_29 ;
}
static T_2 F_20 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
int V_32 = V_6 -> V_16 [ V_27 ] - V_6 -> V_16 [ 8 ] ;
return snprintf ( V_25 , V_28 - 1 , L_1 , V_32 * 1000 ) ;
}
static T_2 F_21 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_30 ;
int V_32 , V_33 ;
if ( F_18 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
F_5 ( & V_6 -> V_9 ) ;
V_33 = F_9 ( V_8 , V_15 [ V_27 ] ) ;
V_32 = V_33 - V_30 / 1000 ;
V_32 = F_19 ( V_32 , 0 , 31 ) ;
V_6 -> V_16 [ 8 ] = V_32 ;
F_13 ( V_8 , V_34 ,
V_32 ) ;
F_10 ( & V_6 -> V_9 ) ;
return V_29 ;
}
static T_2 F_22 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
return snprintf ( V_25 , V_28 - 1 ,
V_6 -> V_35 & V_36 ? L_2 : L_3 ) ;
}
static T_2 F_23 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_30 ;
if ( F_18 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
if ( V_30 != 1 && V_30 != 2 )
return - V_31 ;
F_5 ( & V_6 -> V_9 ) ;
if ( V_30 == 1 )
V_6 -> V_35 |= V_36 ;
else
V_6 -> V_35 &= ~ V_36 ;
V_6 -> V_13 = 0 ;
F_13 ( V_8 , V_37 ,
V_6 -> V_35 ) ;
F_10 ( & V_6 -> V_9 ) ;
return V_29 ;
}
static T_2 F_24 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
int V_27 = F_15 ( V_24 ) -> V_27 ;
return snprintf ( V_25 , V_28 - 1 , L_1 ,
! ! ( V_6 -> V_16 [ 9 ] & V_27 ) ) ;
}
static T_2 F_25 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_6 = F_3 ( V_5 ) ;
return snprintf ( V_25 , V_28 - 1 , L_4 , V_6 -> V_12 ) ;
}
static T_2 F_26 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_30 ;
if ( F_18 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
F_5 ( & V_6 -> V_9 ) ;
V_6 -> V_12 = F_12 ( V_8 , V_30 ) ;
F_10 ( & V_6 -> V_9 ) ;
return V_29 ;
}
static int F_27 ( struct V_7 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = V_38 -> V_42 ;
if ( ! F_28 ( V_42 , V_43 ) )
return - V_44 ;
if ( F_9 ( V_38 , V_45 )
!= V_46
|| F_9 ( V_38 , V_47 )
!= V_48 )
return - V_44 ;
F_29 ( V_40 -> type , V_49 , V_50 ) ;
return 0 ;
}
static void F_30 ( struct V_7 * V_8 ,
struct V_3 * V_6 )
{
V_6 -> V_12 = F_11 ( V_8 ) ;
V_6 -> V_51 = F_9 ( V_8 ,
V_52 ) ;
V_6 -> V_35 = F_9 ( V_8 ,
V_37 ) ;
if ( V_6 -> V_51 & V_53 ) {
V_6 -> V_51 &= ~ V_53 ;
F_13 ( V_8 , V_52 ,
V_6 -> V_51 ) ;
}
}
static int F_31 ( struct V_7 * V_8 ,
const struct V_54 * V_55 )
{
struct V_4 * V_5 = & V_8 -> V_5 ;
struct V_3 * V_6 ;
struct V_4 * V_56 ;
V_6 = F_32 ( V_5 , sizeof( struct V_3 ) , V_57 ) ;
if ( ! V_6 )
return - V_58 ;
V_6 -> V_8 = V_8 ;
F_33 ( & V_6 -> V_9 ) ;
F_30 ( V_8 , V_6 ) ;
V_56 = F_34 ( V_5 , V_8 -> V_59 ,
V_6 ,
V_60 ) ;
return F_35 ( V_56 ) ;
}
