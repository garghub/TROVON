static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( V_2 . V_3 , V_1 ) ;
}
static int F_3 ( T_2 V_1 , T_2 V_4 )
{
return F_4 ( V_2 . V_3 , V_1 , V_4 ) ;
}
static int F_5 ( enum F_5 V_5 )
{
T_1 V_6 ;
int V_7 = 3 ;
F_3 ( V_8 , V_5 ) ;
F_6 ( 5 ) ;
while ( V_7 -- ) {
V_6 = F_1 ( V_8 ) ;
if ( V_6 == 0 || V_6 & 0x80 )
return 0 ;
F_7 ( V_9 / 20 ) ;
}
return - 1 ;
}
static void F_8 ( enum V_10 V_1 , char V_11 )
{
if ( V_1 & V_12 ) {
T_2 V_13 = F_1 ( V_14 ) ;
if ( V_11 )
V_13 |= 0x80 ;
else
V_13 &= ~ 0x80 ;
F_3 ( V_14 , V_13 ) ;
}
if ( V_1 & V_15 ) {
T_2 V_13 = F_1 ( V_16 ) ;
if ( V_11 )
V_13 |= 0x80 ;
else
V_13 &= ~ 0x80 ;
F_3 ( V_16 , V_13 ) ;
}
if ( V_1 & V_17 ) {
T_2 V_13 = F_1 ( V_18 ) ;
if ( V_11 )
V_13 |= 0x80 ;
else
V_13 &= ~ 0x80 ;
F_3 ( V_18 , V_13 ) ;
}
}
static void F_9 ( enum V_10 V_1 )
{
if ( V_1 & V_12 )
F_3 ( V_19 , 0 ) ;
if ( V_1 & V_15 )
F_3 ( V_20 , 0 ) ;
}
static T_2 F_10 ( void )
{
return F_1 ( V_21 ) ;
}
static void F_11 ( T_3 * V_22 , T_3 * V_23 , T_3 * V_24 )
{
* V_22 = F_1 ( V_25 ) ;
* V_23 = F_1 ( V_26 ) ;
* V_24 = F_1 ( V_27 ) ;
}
static int F_12 ( struct V_3 * V_28 ,
const struct V_29 * V_30 )
{
int V_31 , V_32 ;
int V_6 ;
if ( F_13 ( V_2 . V_33 ) )
return - V_34 ;
V_2 . V_3 = V_28 ;
if ( F_5 ( V_35 ) ) {
F_14 ( V_36 L_1 ) ;
return - V_34 ;
}
if ( F_5 ( V_37 ) ) {
F_14 ( V_36 L_2 ) ;
return - V_34 ;
}
F_3 ( V_38 , 0x02 ) ;
F_3 ( V_39 , 0x85 ) ;
F_3 ( V_40 , 0x01 ) ;
F_5 ( V_41 ) ;
V_31 = F_1 ( V_42 ) ;
V_32 = F_1 ( V_43 ) ;
if ( V_31 != 1 || V_32 != 52 ) {
F_14 ( V_36 L_3 ,
V_31 , V_32 ) ;
return - V_34 ;
}
F_5 ( V_44 ) ;
V_31 = F_1 ( V_42 ) ;
V_32 = F_1 ( V_43 ) ;
if ( V_31 != 0 || V_32 != 1 ) {
F_14 ( V_36 L_4 ,
V_31 , V_32 ) ;
return - V_34 ;
}
F_8 ( V_45 , 0 ) ;
V_6 = F_15 () ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( V_46 , 0x15 ) ;
F_3 ( V_47 , 0x60 ) ;
F_3 ( V_14 , 0x08 ) ;
F_3 ( V_16 , 0x0F ) ;
F_3 ( V_18 , 0x4F ) ;
F_3 ( V_48 , 0x14 ) ;
F_9 ( V_45 ) ;
V_2 . V_33 = 1 ;
F_8 ( V_45 , 1 ) ;
F_14 ( V_36 L_5 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_28 )
{
if ( V_2 . V_33 ) {
F_17 () ;
F_8 ( V_45 , 0 ) ;
F_9 ( V_45 ) ;
F_14 ( V_36 L_6 ) ;
V_2 . V_33 = 0 ;
}
return 0 ;
}
static void F_18 ( void )
{
F_19 ( & V_49 ) ;
}
int T_4 F_20 ( struct V_50 * V_51 )
{
int V_6 ;
V_2 . V_52 = V_51 ;
V_2 . exit = F_18 ;
V_2 . V_53 = F_10 ;
V_2 . V_54 = F_11 ;
V_2 . V_55 = F_9 ;
V_2 . V_56 = V_57 ;
V_6 = F_21 ( & V_49 ) ;
return V_6 ;
}
