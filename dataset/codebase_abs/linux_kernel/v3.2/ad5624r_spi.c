static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
T_3 V_7 ;
T_1 V_8 [ 3 ] ;
V_7 = ( 0 << 22 ) | ( V_3 << 19 ) | ( V_4 << 16 ) | ( V_5 << ( 16 - V_6 ) ) ;
V_8 [ 0 ] = V_7 >> 16 ;
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
return F_2 ( V_2 , V_8 , 3 ) ;
}
static T_4 F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_5 V_6 )
{
long V_14 ;
int V_15 ;
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_21 = F_6 ( V_12 ) ;
V_15 = F_7 ( V_13 , 10 , & V_14 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_1 ( V_19 -> V_22 , V_23 ,
V_21 -> V_24 , V_14 ,
V_19 -> V_25 -> V_26 ) ;
return V_15 ? V_15 : V_6 ;
}
static T_4 F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
char V_27 [] [ 15 ] = { L_1 , L_2 , L_3 , L_4 } ;
return sprintf ( V_13 , L_5 , V_27 [ V_19 -> V_28 ] ) ;
}
static T_4 F_9 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_5 V_6 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
int V_15 ;
if ( F_10 ( V_13 , L_2 ) )
V_19 -> V_28 = V_29 ;
else if ( F_10 ( V_13 , L_3 ) )
V_19 -> V_28 = V_30 ;
else if ( F_10 ( V_13 , L_4 ) )
V_19 -> V_28 = V_31 ;
else
V_15 = - V_32 ;
return V_15 ? V_15 : V_6 ;
}
static T_4 F_11 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_21 = F_6 ( V_12 ) ;
return sprintf ( V_13 , L_6 ,
! ! ( V_19 -> V_33 & ( 1 << V_21 -> V_24 ) ) ) ;
}
static T_4 F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_5 V_6 )
{
long V_14 ;
int V_15 ;
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_21 = F_6 ( V_12 ) ;
V_15 = F_7 ( V_13 , 10 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( V_14 == 1 )
V_19 -> V_33 |= ( 1 << V_21 -> V_24 ) ;
else if ( ! V_14 )
V_19 -> V_33 &= ~ ( 1 << V_21 -> V_24 ) ;
else
V_15 = - V_32 ;
V_15 = F_1 ( V_19 -> V_22 , V_34 , 0 ,
( V_19 -> V_28 << 4 ) |
V_19 -> V_33 , 16 ) ;
return V_15 ? V_15 : V_6 ;
}
static T_4 F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
unsigned int V_35 = ( V_19 -> V_36 * 1000 ) >> V_19 -> V_25 -> V_26 ;
return sprintf ( V_13 , L_7 , V_35 / 1000 , V_35 % 1000 ) ;
}
static int T_6 F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 ;
int V_15 , V_37 = 0 ;
V_17 = F_15 ( sizeof( * V_19 ) ) ;
if ( V_17 == NULL ) {
V_15 = - V_38 ;
goto V_39;
}
V_19 = F_5 ( V_17 ) ;
V_19 -> V_40 = F_16 ( & V_2 -> V_10 , L_8 ) ;
if ( ! F_17 ( V_19 -> V_40 ) ) {
V_15 = F_18 ( V_19 -> V_40 ) ;
if ( V_15 )
goto V_41;
V_37 = F_19 ( V_19 -> V_40 ) ;
}
F_20 ( V_2 , V_17 ) ;
V_19 -> V_25 =
& V_42 [ F_21 ( V_2 ) -> V_43 ] ;
if ( V_37 )
V_19 -> V_36 = V_37 / 1000 ;
else
V_19 -> V_36 = V_19 -> V_25 -> V_44 ;
V_19 -> V_22 = V_2 ;
V_17 -> V_10 . V_45 = & V_2 -> V_10 ;
V_17 -> V_46 = F_21 ( V_2 ) -> V_46 ;
V_17 -> V_47 = & V_48 ;
V_17 -> V_49 = V_50 ;
V_15 = F_1 ( V_2 , V_51 , 0 ,
! ! V_37 , 16 ) ;
if ( V_15 )
goto V_52;
V_15 = F_22 ( V_17 ) ;
if ( V_15 )
goto V_52;
return 0 ;
V_52:
if ( ! F_17 ( V_19 -> V_40 ) )
F_23 ( V_19 -> V_40 ) ;
V_41:
if ( ! F_17 ( V_19 -> V_40 ) )
F_24 ( V_19 -> V_40 ) ;
F_25 ( V_17 ) ;
V_39:
return V_15 ;
}
static int T_7 F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_27 ( V_2 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
F_28 ( V_17 ) ;
if ( ! F_17 ( V_19 -> V_40 ) ) {
F_23 ( V_19 -> V_40 ) ;
F_24 ( V_19 -> V_40 ) ;
}
F_25 ( V_17 ) ;
return 0 ;
}
static T_8 int F_29 ( void )
{
return F_30 ( & V_53 ) ;
}
static T_9 void F_31 ( void )
{
F_32 ( & V_53 ) ;
}
