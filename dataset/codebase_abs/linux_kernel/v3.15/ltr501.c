static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 100 ;
int V_5 ;
while ( V_4 -- ) {
V_5 = F_2 ( V_2 -> V_6 ,
V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 & V_3 ) == V_3 )
return 0 ;
F_3 ( 25 ) ;
}
F_4 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_10 [ 2 ] )
{
int V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_6 ( V_2 -> V_6 ,
V_12 , 2 * sizeof( T_2 ) , ( T_1 * ) V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 = F_1 ( V_2 , V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_8 ( V_2 -> V_6 , V_14 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int * V_19 , int * V_20 , long V_21 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
T_2 V_10 [ 2 ] ;
int V_5 , V_22 ;
switch ( V_21 ) {
case V_23 :
if ( F_11 ( V_16 ) )
return - V_24 ;
switch ( V_18 -> type ) {
case V_25 :
F_12 ( & V_2 -> V_26 ) ;
V_5 = F_5 ( V_2 , V_10 ) ;
F_13 ( & V_2 -> V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_19 = F_14 ( V_18 -> V_27 == V_12 ?
V_10 [ 0 ] : V_10 [ 1 ] ) ;
return V_28 ;
case V_29 :
F_12 ( & V_2 -> V_30 ) ;
V_5 = F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_30 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_19 = V_5 & V_31 ;
return V_28 ;
default:
return - V_32 ;
}
case V_33 :
switch ( V_18 -> type ) {
case V_25 :
if ( V_2 -> V_34 & V_35 ) {
* V_19 = 0 ;
* V_20 = 5000 ;
return V_36 ;
} else {
* V_19 = 1 ;
* V_20 = 0 ;
return V_28 ;
}
case V_29 :
V_22 = ( V_2 -> V_37 & V_38 ) >>
V_39 ;
* V_19 = V_40 [ V_22 ] [ 0 ] ;
* V_20 = V_40 [ V_22 ] [ 1 ] ;
return V_36 ;
default:
return - V_32 ;
}
}
return - V_32 ;
}
static int F_15 ( int V_19 , int V_20 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < F_16 ( V_40 ) ; V_22 ++ )
if ( V_19 == V_40 [ V_22 ] [ 0 ] && V_20 == V_40 [ V_22 ] [ 1 ] )
return V_22 ;
return - 1 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int V_19 , int V_20 , long V_21 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
int V_22 ;
if ( F_11 ( V_16 ) )
return - V_24 ;
switch ( V_21 ) {
case V_33 :
switch ( V_18 -> type ) {
case V_25 :
if ( V_19 == 0 && V_20 == 5000 )
V_2 -> V_34 |= V_35 ;
else if ( V_19 == 1 && V_20 == 0 )
V_2 -> V_34 &= ~ V_35 ;
else
return - V_32 ;
return F_18 ( V_2 -> V_6 ,
V_41 , V_2 -> V_34 ) ;
case V_29 :
V_22 = F_15 ( V_19 , V_20 ) ;
if ( V_22 < 0 )
return - V_32 ;
V_2 -> V_37 &= ~ V_38 ;
V_2 -> V_37 |= V_22 << V_39 ;
return F_18 ( V_2 -> V_6 ,
V_42 , V_2 -> V_37 ) ;
default:
return - V_32 ;
}
}
return - V_32 ;
}
static int F_19 ( struct V_43 * V_6 , T_1 V_44 , T_1 V_45 )
{
int V_5 = F_18 ( V_6 , V_41 , V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_18 ( V_6 , V_42 , V_45 ) ;
}
static T_3 F_20 ( int V_46 , void * V_47 )
{
struct V_48 * V_49 = V_47 ;
struct V_15 * V_16 = V_49 -> V_16 ;
struct V_1 * V_2 = F_10 ( V_16 ) ;
T_4 V_10 [ 8 ] ;
T_2 V_50 [ 2 ] ;
T_1 V_21 = 0 ;
int V_51 = 0 ;
int V_5 ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_21 ( 0 , V_16 -> V_52 ) ||
F_21 ( 1 , V_16 -> V_52 ) )
V_21 |= V_11 ;
if ( F_21 ( 2 , V_16 -> V_52 ) )
V_21 |= V_13 ;
V_5 = F_1 ( V_2 , V_21 ) ;
if ( V_5 < 0 )
goto V_53;
if ( V_21 & V_11 ) {
V_5 = F_6 ( V_2 -> V_6 ,
V_12 , sizeof( V_50 ) , ( T_1 * ) V_50 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_21 ( 0 , V_16 -> V_52 ) )
V_10 [ V_51 ++ ] = F_14 ( V_50 [ 1 ] ) ;
if ( F_21 ( 1 , V_16 -> V_52 ) )
V_10 [ V_51 ++ ] = F_14 ( V_50 [ 0 ] ) ;
}
if ( V_21 & V_13 ) {
V_5 = F_8 ( V_2 -> V_6 , V_14 ) ;
if ( V_5 < 0 )
goto V_53;
V_10 [ V_51 ++ ] = V_5 & V_31 ;
}
F_22 ( V_16 , V_10 ,
F_23 () ) ;
V_53:
F_24 ( V_16 -> V_54 ) ;
return V_55 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_34 = V_5 | V_56 ;
V_5 = F_2 ( V_2 -> V_6 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_37 = V_5 | V_56 ;
return F_19 ( V_2 -> V_6 , V_2 -> V_34 ,
V_2 -> V_37 ) ;
}
static int F_26 ( struct V_43 * V_6 ,
const struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_5 ;
V_16 = F_27 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_16 )
return - V_59 ;
V_2 = F_10 ( V_16 ) ;
F_28 ( V_6 , V_16 ) ;
V_2 -> V_6 = V_6 ;
F_29 ( & V_2 -> V_26 ) ;
F_29 ( & V_2 -> V_30 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_60 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 >> 4 ) != 0x8 )
return - V_61 ;
V_16 -> V_8 . V_62 = & V_6 -> V_8 ;
V_16 -> V_63 = & V_64 ;
V_16 -> V_65 = V_66 ;
V_16 -> V_67 = F_16 ( V_66 ) ;
V_16 -> V_68 = V_69 ;
V_16 -> V_70 = V_71 ;
V_5 = F_25 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_30 ( V_16 , NULL ,
F_20 , NULL ) ;
if ( V_5 )
return V_5 ;
V_5 = F_31 ( V_16 ) ;
if ( V_5 )
goto V_72;
return 0 ;
V_72:
F_32 ( V_16 ) ;
return V_5 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_19 ( V_2 -> V_6 ,
V_2 -> V_34 & ~ V_56 ,
V_2 -> V_37 & ~ V_56 ) ;
}
static int F_34 ( struct V_43 * V_6 )
{
struct V_15 * V_16 = F_35 ( V_6 ) ;
F_36 ( V_16 ) ;
F_32 ( V_16 ) ;
F_33 ( F_10 ( V_16 ) ) ;
return 0 ;
}
static int F_37 ( struct V_73 * V_8 )
{
struct V_1 * V_2 = F_10 ( F_35 (
F_38 ( V_8 ) ) ) ;
return F_33 ( V_2 ) ;
}
static int F_39 ( struct V_73 * V_8 )
{
struct V_1 * V_2 = F_10 ( F_35 (
F_38 ( V_8 ) ) ) ;
return F_19 ( V_2 -> V_6 , V_2 -> V_34 ,
V_2 -> V_37 ) ;
}
