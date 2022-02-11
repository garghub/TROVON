static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
union V_5 * V_5 ;
int V_6 ;
T_1 V_7 ;
unsigned long V_8 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_4 -> V_9 , V_8 ) ;
V_2 -> V_10 = V_11 ;
F_3 ( V_4 -> V_9 , V_8 ) ;
V_5 = F_4 ( & V_2 -> V_12 , ( V_13 ) ( V_14 ) V_4 , V_4 -> V_7 ) ;
V_6 = F_5 ( V_4 -> V_15 , V_5 ) ;
switch ( V_6 ) {
case 0 :
V_4 -> V_16 . V_17 . V_18 . V_19 |= V_20 ;
return 0 ;
case 1 :
case 2 :
return - V_21 ;
case 3 :
{
V_7 = V_5 -> V_18 . V_7 ;
if ( V_7 != 0 )
V_4 -> V_7 &= ~ V_7 ;
else
V_4 -> V_7 = 0 ;
if ( F_6 ( V_4 ) )
return - V_22 ;
return V_4 -> V_7 ? - V_23 : - V_22 ;
}
default:
return V_6 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_4 , V_26 ) ;
V_2 -> V_10 = V_27 ;
}
static void F_9 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
}
static void F_10 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
F_11 ( L_1 , V_2 -> V_10 ) ;
V_2 -> V_28 . V_29 = - V_30 ;
}
static void F_12 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
V_2 -> V_28 . V_29 = - V_21 ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_14 ( V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
union V_5 * V_5 ;
union V_17 * V_17 = & V_2 -> V_17 ;
struct V_31 * V_28 = & V_2 -> V_28 ;
struct V_32 * V_33 = V_2 -> V_33 ;
V_2 -> V_10 = V_34 ;
memcpy ( V_17 , V_28 -> V_35 , sizeof( * V_17 ) ) ;
if ( V_17 -> V_18 . V_36 & V_37 ) {
V_5 = (union V_5 * ) V_28 -> V_38 ;
V_28 -> V_29 = F_16 ( & V_2 -> V_12 , F_17 ( V_33 ) ,
V_5 ) ;
if ( V_28 -> V_29 )
goto V_39;
V_28 -> V_29 = F_18 ( & V_2 -> V_12 ) ;
if ( V_28 -> V_29 ) {
F_19 ( & V_2 -> V_12 ) ;
goto V_39;
}
V_28 -> V_29 = F_1 ( V_2 ) ;
if ( V_28 -> V_29 ) {
F_19 ( & V_2 -> V_12 ) ;
goto V_39;
}
return;
} else if ( V_17 -> V_18 . V_36 & V_40 ) {
V_28 -> V_29 = - V_41 ;
goto V_39;
} else if ( V_17 -> V_18 . V_36 & V_42 ) {
V_28 -> V_29 = - V_41 ;
goto V_39;
}
V_39:
V_2 -> V_10 = V_43 ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
struct V_44 * V_44 = F_21 ( & V_45 ) ;
memcpy ( & V_2 -> V_44 , V_44 , sizeof( * V_44 ) ) ;
F_22 ( V_46 , & V_2 -> V_47 ) ;
if ( V_2 -> V_48 )
F_23 ( V_2 -> V_48 ) ;
}
