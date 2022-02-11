static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 = 3 ;
int V_5 = F_2 ( V_2 -> V_6 , V_7 ,
( V_3 ? ( V_2 -> V_8 << V_9 ) : V_10 ) |
V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 += V_3 ? V_12 [ V_2 -> V_8 ] : 2 ;
F_3 ( V_4 ) ;
return F_4 ( V_2 -> V_6 , V_13 ) ;
}
static int F_5 ( struct V_1 * V_2 , int * V_14 , int * V_15 )
{
int V_5 ;
T_1 V_16 ;
T_2 V_17 ;
T_3 V_18 , V_19 , V_20 ;
F_6 ( & V_2 -> V_21 ) ;
V_5 = F_1 ( V_2 , false ) ;
if ( V_5 < 0 )
goto V_22;
V_16 = V_5 ;
V_5 = F_1 ( V_2 , true ) ;
if ( V_5 < 0 )
goto V_22;
V_17 = V_5 ;
V_18 = F_7 ( 3 ) + ( T_3 ) F_7 ( 4 ) * V_16 / 0x20000 +
F_8 ( 5 ) * V_16 / 0x8000 * V_16 / 0x80000 +
F_8 ( 9 ) * V_16 / 0x8000 * V_16 / 0x8000 * V_16 / 0x10000 ;
V_19 = F_8 ( 6 ) * 0x4000 + F_8 ( 7 ) * V_16 / 8 +
F_8 ( 8 ) * V_16 / 0x8000 * V_16 / 16 +
F_8 ( 9 ) * V_16 / 0x8000 * V_16 / 0x10000 * V_16 ;
V_20 = ( V_18 * V_17 + V_19 ) / 0x4000 ;
V_20 += ( ( V_20 - 75000 ) * ( V_20 - 75000 ) / 0x10000 - 9537 ) *
F_8 ( 10 ) / 0x10000 ;
* V_14 = V_20 / 1000 ;
* V_15 = ( V_20 % 1000 ) * 1000 ;
V_22:
F_9 ( & V_2 -> V_21 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , int * V_14 )
{
int V_5 ;
T_1 V_16 ;
F_6 ( & V_2 -> V_21 ) ;
V_5 = F_1 ( V_2 , false ) ;
if ( V_5 < 0 )
goto V_22;
V_16 = V_5 ;
* V_14 = ( ( T_3 ) F_7 ( 1 ) * V_16 / 0x100 +
( T_3 ) F_7 ( 2 ) * 0x40 ) * 1000 / 0x10000 ;
V_22:
F_9 ( & V_2 -> V_21 ) ;
return V_5 ;
}
static int F_11 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_14 , int * V_15 , long V_27 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
int V_5 ;
switch ( V_27 ) {
case V_28 :
switch ( V_26 -> type ) {
case V_29 :
V_5 = F_5 ( V_2 , V_14 , V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_30 ;
case V_31 :
V_5 = F_10 ( V_2 , V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_32 ;
default:
return - V_33 ;
}
case V_34 :
* V_14 = 0 ;
* V_15 = V_12 [ V_2 -> V_8 ] * 1000 ;
return V_30 ;
default:
return - V_33 ;
}
}
static int F_13 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_14 , int V_15 , long V_27 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
int V_35 ;
switch ( V_27 ) {
case V_34 :
if ( V_14 != 0 )
return - V_33 ;
for ( V_35 = 0 ; V_35 < F_14 ( V_12 ) ; V_35 ++ )
if ( V_15 == V_12 [ V_35 ] * 1000 ) {
F_6 ( & V_2 -> V_21 ) ;
V_2 -> V_8 = V_35 ;
F_9 ( & V_2 -> V_21 ) ;
return 0 ;
}
return - V_33 ;
default:
return - V_33 ;
}
}
static int F_15 ( struct V_36 * V_6 ,
const struct V_37 * V_38 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_5 ;
if ( ! F_16 ( V_6 -> V_39 , V_40 |
V_41 ) )
return - V_42 ;
V_5 = F_17 ( V_6 , V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 & V_44 ) != V_45 )
return - V_42 ;
V_24 = F_18 ( & V_6 -> V_46 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_47 ;
V_2 = F_12 ( V_24 ) ;
V_2 -> V_6 = V_6 ;
F_19 ( & V_2 -> V_21 ) ;
F_20 ( V_6 , V_24 ) ;
V_24 -> V_48 = & V_49 ;
V_24 -> V_50 = V_38 -> V_50 ;
V_24 -> V_46 . V_51 = & V_6 -> V_46 ;
V_24 -> V_52 = V_53 ;
V_24 -> V_54 = V_55 ;
V_24 -> V_56 = F_14 ( V_55 ) ;
V_2 -> V_8 = V_57 ;
V_5 = F_21 ( V_2 -> V_6 , V_58 ,
sizeof( V_2 -> V_59 ) , ( V_60 * ) V_2 -> V_59 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_22 ( & V_6 -> V_46 , V_24 ) ;
}
