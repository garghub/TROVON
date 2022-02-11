static bool F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , const T_1 V_4 )
{
unsigned int V_5 ;
T_2 V_6 ;
if ( F_3 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < 200 ; V_5 ++ ) {
F_4 ( V_2 , V_7 , & V_6 ) ;
if ( ( F_5 ( V_6 , V_8 ) == V_4 ) ||
( F_5 ( V_6 , V_9 ) == V_4 ) ||
( F_5 ( V_6 , V_10 ) == V_4 ) ||
( F_5 ( V_6 , V_11 ) == V_4 ) )
break;
F_6 ( V_12 ) ;
}
if ( V_5 == 200 )
F_7 ( V_2 , L_1 ) ;
F_8 ( V_2 , V_13 , ~ 0 ) ;
F_8 ( V_2 , V_7 , ~ 0 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_6 ;
F_4 ( V_2 , V_17 , & V_6 ) ;
V_15 -> V_18 = ! ! F_5 ( V_6 , V_19 ) ;
V_15 -> V_20 = ! ! F_5 ( V_6 , V_21 ) ;
V_15 -> V_22 =
! ! F_5 ( V_6 , V_23 ) ;
V_15 -> V_24 =
! ! F_5 ( V_6 , V_25 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_6 = 0 ;
F_11 ( & V_6 , V_19 , ! ! V_15 -> V_18 ) ;
F_11 ( & V_6 , V_21 , ! ! V_15 -> V_20 ) ;
F_11 ( & V_6 , V_23 ,
! ! V_15 -> V_22 ) ;
F_11 ( & V_6 , V_25 ,
! ! V_15 -> V_24 ) ;
F_8 ( V_2 , V_17 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_14 V_15 ;
T_2 V_6 ;
F_4 ( V_2 , V_17 , & V_6 ) ;
V_15 . V_16 = V_2 ;
V_15 . V_26 = F_9 ;
V_15 . V_27 = F_10 ;
switch ( F_5 ( V_6 , V_28 ) )
{
case 0 :
V_15 . V_29 = V_30 ;
break;
case 1 :
V_15 . V_29 = V_31 ;
break;
default:
V_15 . V_29 = V_32 ;
break;
}
V_15 . V_18 = 0 ;
V_15 . V_20 = 0 ;
V_15 . V_22 = 0 ;
V_15 . V_24 = 0 ;
F_13 ( & V_15 , V_33 , V_2 -> V_15 ,
V_34 / sizeof( V_35 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_15 ( V_2 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ;
}
static char * F_18 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 , V_36 ) )
return V_37 ;
else
return V_38 ;
}
static int F_20 ( struct V_1 * V_2 ,
const T_1 * V_16 , const T_3 V_39 )
{
T_2 V_6 ;
V_6 = 0 ;
F_11 ( & V_6 , V_40 , 1 ) ;
F_8 ( V_2 , V_41 , V_6 ) ;
F_21 ( V_2 , V_42 ,
V_16 , V_39 ) ;
F_8 ( V_2 , V_41 , 0x00000 ) ;
F_8 ( V_2 , V_41 , 0x00001 ) ;
F_8 ( V_2 , V_43 , 0 ) ;
F_8 ( V_2 , V_44 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_23 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_8 ( V_2 , V_13 , ~ 0 ) ;
F_8 ( V_2 , V_7 , ~ 0 ) ;
F_24 ( V_2 , V_46 , V_47 , 0xff , 0x02 ) ;
F_2 ( V_2 , V_47 ) ;
F_24 ( V_2 , V_48 , V_49 , 0 , 0 ) ;
F_2 ( V_2 , V_49 ) ;
return V_45 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_50 V_51 )
{
if ( V_51 == V_52 ) {
F_24 ( V_2 , V_48 , V_49 ,
0 , 0x02 ) ;
F_2 ( V_2 , V_49 ) ;
} else if ( V_51 == V_53 ) {
F_8 ( V_2 , V_13 ,
0xffffffff ) ;
F_8 ( V_2 , V_7 ,
0xffffffff ) ;
F_24 ( V_2 , V_46 , V_54 ,
0xff , 0x01 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_50 V_51 )
{
int V_45 = 0 ;
switch ( V_51 ) {
case V_55 :
V_45 = F_22 ( V_2 ) ;
break;
case V_56 :
F_25 ( V_2 , V_53 ) ;
break;
case V_57 :
case V_58 :
F_27 ( V_2 , V_51 ) ;
break;
case V_59 :
case V_53 :
case V_60 :
case V_52 :
V_45 = F_25 ( V_2 , V_51 ) ;
break;
default:
V_45 = - V_61 ;
break;
}
if ( F_28 ( V_45 ) )
F_7 ( V_2 , L_2 ,
V_51 , V_45 ) ;
return V_45 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_45 ;
if ( F_14 ( V_2 ) )
V_45 = F_16 ( V_2 ) ;
else
V_45 = F_12 ( V_2 ) ;
return V_45 ;
}
static int F_30 ( struct V_62 * V_62 ,
const struct V_63 * V_64 )
{
return F_31 ( V_62 , & V_65 ) ;
}
