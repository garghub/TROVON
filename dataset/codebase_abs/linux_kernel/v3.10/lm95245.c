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
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
F_6 ( & V_8 -> V_9 ) ;
if ( F_7 ( V_10 , V_8 -> V_11
+ F_8 ( V_8 -> V_12 ) ) || ! V_8 -> V_13 ) {
int V_14 ;
F_9 ( & V_7 -> V_5 , L_1 ) ;
for ( V_14 = 0 ; V_14 < F_10 ( V_15 ) ; V_14 ++ )
V_8 -> V_16 [ V_14 ]
= F_11 ( V_7 ,
V_15 [ V_14 ] ) ;
V_8 -> V_11 = V_10 ;
V_8 -> V_13 = 1 ;
}
F_12 ( & V_8 -> V_9 ) ;
return V_8 ;
}
static unsigned long F_13 ( struct V_6 * V_7 )
{
int V_17 ;
unsigned long V_12 ;
V_17 = F_11 ( V_7 , V_18 ) ;
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
static unsigned long F_14 ( struct V_6 * V_7 ,
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
F_15 ( V_7 , V_18 , V_17 ) ;
return V_12 ;
}
static T_2 F_16 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_8 = F_3 ( V_5 ) ;
int V_26 ;
int V_27 = F_17 ( V_24 ) -> V_27 ;
if ( V_27 == 0 || V_8 -> V_16 [ V_27 ] & 0x80 )
V_26 = F_2 ( V_8 -> V_16 [ V_27 ] ,
V_8 -> V_16 [ V_27 + 1 ] ) ;
else
V_26 = F_1 ( V_8 -> V_16 [ V_27 + 2 ] ,
V_8 -> V_16 [ V_27 + 3 ] ) ;
return snprintf ( V_25 , V_28 - 1 , L_2 , V_26 ) ;
}
static T_2 F_18 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_8 = F_3 ( V_5 ) ;
int V_27 = F_17 ( V_24 ) -> V_27 ;
return snprintf ( V_25 , V_28 - 1 , L_2 ,
V_8 -> V_16 [ V_27 ] * 1000 ) ;
}
static T_2 F_19 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
int V_27 = F_17 ( V_24 ) -> V_27 ;
unsigned long V_30 ;
if ( F_20 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
V_30 /= 1000 ;
V_30 = F_21 ( V_30 , 0 , ( V_27 == 6 ? 127 : 255 ) ) ;
F_6 ( & V_8 -> V_9 ) ;
V_8 -> V_13 = 0 ;
F_15 ( V_7 , V_15 [ V_27 ] , V_30 ) ;
F_12 ( & V_8 -> V_9 ) ;
return V_29 ;
}
static T_2 F_22 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
unsigned long V_30 ;
if ( F_20 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
V_30 /= 1000 ;
V_30 = F_21 ( V_30 , 0 , 31 ) ;
F_6 ( & V_8 -> V_9 ) ;
V_8 -> V_13 = 0 ;
F_15 ( V_7 , V_32 ,
V_30 ) ;
F_12 ( & V_8 -> V_9 ) ;
return V_29 ;
}
static T_2 F_23 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
return snprintf ( V_25 , V_28 - 1 ,
V_8 -> V_33 & V_34 ? L_3 : L_4 ) ;
}
static T_2 F_24 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
unsigned long V_30 ;
if ( F_20 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
if ( V_30 != 1 && V_30 != 2 )
return - V_31 ;
F_6 ( & V_8 -> V_9 ) ;
if ( V_30 == 1 )
V_8 -> V_33 |= V_34 ;
else
V_8 -> V_33 &= ~ V_34 ;
V_8 -> V_13 = 0 ;
F_15 ( V_7 , V_35 ,
V_8 -> V_33 ) ;
F_12 ( & V_8 -> V_9 ) ;
return V_29 ;
}
static T_2 F_25 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_8 = F_3 ( V_5 ) ;
int V_27 = F_17 ( V_24 ) -> V_27 ;
return snprintf ( V_25 , V_28 - 1 , L_2 ,
! ! ( V_8 -> V_16 [ 9 ] & V_27 ) ) ;
}
static T_2 F_26 ( struct V_4 * V_5 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_3 * V_8 = F_3 ( V_5 ) ;
return snprintf ( V_25 , V_28 - 1 , L_5 , V_8 -> V_12 ) ;
}
static T_2 F_27 ( struct V_4 * V_5 , struct V_23 * V_24 ,
const char * V_25 , T_3 V_29 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
unsigned long V_30 ;
if ( F_20 ( V_25 , 10 , & V_30 ) < 0 )
return - V_31 ;
F_6 ( & V_8 -> V_9 ) ;
V_8 -> V_12 = F_14 ( V_7 , V_30 ) ;
F_12 ( & V_8 -> V_9 ) ;
return V_29 ;
}
static int F_28 ( struct V_6 * V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_36 -> V_40 ;
if ( ! F_29 ( V_40 , V_41 ) )
return - V_42 ;
if ( F_11 ( V_36 , V_43 )
!= V_44
|| F_11 ( V_36 , V_45 )
!= V_46 )
return - V_42 ;
F_30 ( V_38 -> type , V_47 , V_48 ) ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_5 ( V_7 ) ;
V_8 -> V_13 = 0 ;
V_8 -> V_12 = F_13 ( V_7 ) ;
V_8 -> V_49 = F_11 ( V_7 ,
V_50 ) ;
V_8 -> V_33 = F_11 ( V_7 ,
V_35 ) ;
if ( V_8 -> V_49 & V_51 ) {
V_8 -> V_49 &= ~ V_51 ;
F_15 ( V_7 , V_50 ,
V_8 -> V_49 ) ;
}
}
static int F_32 ( struct V_6 * V_36 ,
const struct V_52 * V_53 )
{
struct V_3 * V_8 ;
int V_54 ;
V_8 = F_33 ( & V_36 -> V_5 , sizeof( struct V_3 ) ,
V_55 ) ;
if ( ! V_8 )
return - V_56 ;
F_34 ( V_36 , V_8 ) ;
F_35 ( & V_8 -> V_9 ) ;
F_31 ( V_36 ) ;
V_54 = F_36 ( & V_36 -> V_5 . V_57 , & V_58 ) ;
if ( V_54 )
return V_54 ;
V_8 -> V_59 = F_37 ( & V_36 -> V_5 ) ;
if ( F_38 ( V_8 -> V_59 ) ) {
V_54 = F_39 ( V_8 -> V_59 ) ;
goto V_60;
}
return 0 ;
V_60:
F_40 ( & V_36 -> V_5 . V_57 , & V_58 ) ;
return V_54 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_5 ( V_7 ) ;
F_42 ( V_8 -> V_59 ) ;
F_40 ( & V_7 -> V_5 . V_57 , & V_58 ) ;
return 0 ;
}
