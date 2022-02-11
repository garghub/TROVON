static int F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 = ( V_1 << 8 ) | V_2 ;
return V_3 * 1000 / 256 ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
T_3 V_3 = ( V_1 << 8 ) | V_2 ;
return V_3 * 1000 / 256 ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
F_6 ( & V_9 -> V_10 ) ;
if ( F_7 ( V_11 , V_9 -> V_12 + V_9 -> V_13 ) ||
! V_9 -> V_14 ) {
int V_15 ;
F_8 ( & V_8 -> V_6 , L_1 ) ;
for ( V_15 = 0 ; V_15 < F_9 ( V_16 ) ; V_15 ++ )
V_9 -> V_17 [ V_15 ]
= F_10 ( V_8 ,
V_16 [ V_15 ] ) ;
V_9 -> V_12 = V_11 ;
V_9 -> V_14 = 1 ;
}
F_11 ( & V_9 -> V_10 ) ;
return V_9 ;
}
static T_4 F_12 ( struct V_5 * V_6 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_4 * V_9 = F_3 ( V_6 ) ;
int V_21 = F_13 ( V_19 ) -> V_21 ;
return snprintf ( V_20 , V_22 - 1 , L_2 ,
V_21 == 0 || ( V_9 -> V_23 & ( 1 << ( V_21 / 2 ) ) ) ?
F_1 ( V_9 -> V_17 [ V_21 ] , V_9 -> V_17 [ V_21 + 1 ] ) :
F_2 ( V_9 -> V_17 [ V_21 ] ,
V_9 -> V_17 [ V_21 + 1 ] ) ) ;
}
static T_4 F_14 ( struct V_5 * V_6 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
return snprintf ( V_20 , V_22 - 1 ,
V_9 -> V_24 & F_13 ( V_19 ) -> V_21 ? L_3 : L_4 ) ;
}
static T_4 F_15 ( struct V_5 * V_6 , struct V_18 * V_19 ,
const char * V_20 , T_5 V_25 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
unsigned long V_26 ;
int V_27 ;
T_1 V_28 = F_13 ( V_19 ) -> V_21 ;
if ( F_16 ( V_20 , 10 , & V_26 ) < 0 )
return - V_29 ;
if ( V_26 != 1 && V_26 != 2 )
return - V_29 ;
V_27 = V_28 == V_30 ? V_31 : V_32 ;
F_6 ( & V_9 -> V_10 ) ;
V_9 -> V_33 &= ~ ( V_34 << V_27 ) ;
if ( V_26 == 1 ) {
V_9 -> V_24 |= V_28 ;
V_9 -> V_33 |= ( V_35 << V_27 ) ;
} else {
V_9 -> V_24 &= ~ V_28 ;
V_9 -> V_33 |= ( V_36 << V_27 ) ;
}
V_9 -> V_14 = 0 ;
F_17 ( V_8 , V_37 ,
V_9 -> V_24 ) ;
F_17 ( V_8 , V_38 ,
V_9 -> V_33 ) ;
F_11 ( & V_9 -> V_10 ) ;
return V_25 ;
}
static T_4 F_18 ( struct V_5 * V_6 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
return snprintf ( V_20 , V_22 - 1 ,
V_9 -> V_23 & F_13 ( V_19 ) -> V_21 ?
L_5 : L_6 ) ;
}
static T_4 F_19 ( struct V_5 * V_6 , struct V_18 * V_19 ,
const char * V_20 , T_5 V_25 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
long V_26 ;
if ( F_20 ( V_20 , 10 , & V_26 ) < 0 )
return - V_29 ;
if ( V_26 < - 128000 )
return - V_29 ;
F_6 ( & V_9 -> V_10 ) ;
if ( V_26 < 0 )
V_9 -> V_23 |= F_13 ( V_19 ) -> V_21 ;
else
V_9 -> V_23 &= ~ F_13 ( V_19 ) -> V_21 ;
V_9 -> V_14 = 0 ;
F_17 ( V_8 , V_39 , V_9 -> V_23 ) ;
F_11 ( & V_9 -> V_10 ) ;
return V_25 ;
}
static T_4 F_21 ( struct V_5 * V_6 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
return snprintf ( V_20 , V_22 - 1 ,
V_9 -> V_23 & F_13 ( V_19 ) -> V_21 ?
L_7 : L_8 ) ;
}
static T_4 F_22 ( struct V_5 * V_6 , struct V_18 * V_19 ,
const char * V_20 , T_5 V_25 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
long V_26 ;
if ( F_20 ( V_20 , 10 , & V_26 ) < 0 )
return - V_29 ;
if ( V_26 >= 256000 )
return - V_29 ;
F_6 ( & V_9 -> V_10 ) ;
if ( V_26 <= 127000 )
V_9 -> V_23 |= F_13 ( V_19 ) -> V_21 ;
else
V_9 -> V_23 &= ~ F_13 ( V_19 ) -> V_21 ;
V_9 -> V_14 = 0 ;
F_17 ( V_8 , V_39 , V_9 -> V_23 ) ;
F_11 ( & V_9 -> V_10 ) ;
return V_25 ;
}
static T_4 F_23 ( struct V_5 * V_6 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_4 * V_9 = F_3 ( V_6 ) ;
return snprintf ( V_20 , V_22 - 1 , L_9 , 1000 * V_9 -> V_13
/ V_40 ) ;
}
static T_4 F_24 ( struct V_5 * V_6 , struct V_18 * V_19 ,
const char * V_20 , T_5 V_25 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_4 * V_9 = F_5 ( V_8 ) ;
unsigned long V_26 ;
if ( F_16 ( V_20 , 10 , & V_26 ) < 0 )
return - V_29 ;
V_9 -> V_13 = V_26 * V_40 / 1000 ;
return V_25 ;
}
static int F_25 ( struct V_7 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_41 -> V_45 ;
const char * V_46 ;
int V_47 , V_48 ;
if ( ! F_26 ( V_45 , V_49 ) )
return - V_50 ;
V_47 = F_10 ( V_41 , V_51 ) ;
if ( V_47 != V_52 )
return - V_50 ;
V_48 = F_10 ( V_41 , V_53 ) ;
switch ( V_48 ) {
case V_54 :
V_46 = L_10 ;
break;
case V_55 :
V_46 = L_11 ;
break;
default:
return - V_50 ;
}
F_27 ( V_43 -> type , V_46 , V_56 ) ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = F_5 ( V_8 ) ;
V_9 -> V_13 = V_40 ;
V_9 -> V_14 = 0 ;
V_9 -> V_23 = V_57 ;
V_9 -> V_24 = 0 ;
V_9 -> V_33 = ( V_36 << V_31 ) | ( V_36 << V_32 ) ;
F_17 ( V_8 , V_39 , V_9 -> V_23 ) ;
F_17 ( V_8 , V_58 ,
V_59 | V_60 ) ;
F_17 ( V_8 , V_38 ,
V_9 -> V_33 ) ;
F_17 ( V_8 , V_37 ,
V_9 -> V_24 ) ;
}
static int F_29 ( struct V_7 * V_41 ,
const struct V_61 * V_62 )
{
struct V_4 * V_9 ;
int V_63 ;
V_9 = F_30 ( sizeof( struct V_4 ) , V_64 ) ;
if ( ! V_9 ) {
V_63 = - V_65 ;
goto exit;
}
F_31 ( V_41 , V_9 ) ;
F_32 ( & V_9 -> V_10 ) ;
F_28 ( V_41 ) ;
V_63 = F_33 ( & V_41 -> V_6 . V_66 , & V_67 ) ;
if ( V_63 )
goto V_68;
V_9 -> V_69 = F_34 ( & V_41 -> V_6 ) ;
if ( F_35 ( V_9 -> V_69 ) ) {
V_63 = F_36 ( V_9 -> V_69 ) ;
goto V_70;
}
return 0 ;
V_70:
F_37 ( & V_41 -> V_6 . V_66 , & V_67 ) ;
V_68:
F_38 ( V_9 ) ;
exit:
return V_63 ;
}
static int F_39 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = F_5 ( V_8 ) ;
F_40 ( V_9 -> V_69 ) ;
F_37 ( & V_8 -> V_6 . V_66 , & V_67 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_71 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_71 ) ;
}
