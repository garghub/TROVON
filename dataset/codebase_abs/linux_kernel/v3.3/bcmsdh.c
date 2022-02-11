static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 -> V_6 ) ;
F_3 ( V_7 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 -> V_8 ) ;
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
}
int F_8 ( struct V_3 * V_4 )
{
F_3 ( V_7 , L_2 ) ;
F_6 ( V_4 -> V_2 [ 1 ] ) ;
F_9 ( V_4 -> V_2 [ 1 ] , F_1 ) ;
F_9 ( V_4 -> V_2 [ 2 ] , F_7 ) ;
F_4 ( V_4 -> V_2 [ 1 ] ) ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 )
{
F_3 ( V_7 , L_2 ) ;
F_6 ( V_4 -> V_2 [ 1 ] ) ;
F_11 ( V_4 -> V_2 [ 2 ] ) ;
F_11 ( V_4 -> V_2 [ 1 ] ) ;
F_4 ( V_4 -> V_2 [ 1 ] ) ;
return 0 ;
}
T_1 F_12 ( struct V_3 * V_4 , T_2 V_9 , T_3 V_10 ,
int * V_11 )
{
int V_12 ;
T_4 V_13 = 0 ;
T_1 V_14 = 0 ;
do {
if ( V_13 )
F_13 ( 1000 ) ;
V_12 = F_14 ( V_4 , V_15 , V_9 ,
V_10 , ( T_1 * ) & V_14 ) ;
} while ( V_12 != 0
&& ( V_13 ++ < V_16 ) );
if ( V_11 )
* V_11 = V_12 ;
F_3 ( V_17 , L_3 ,
V_9 , V_10 , V_14 ) ;
return V_14 ;
}
void
F_15 ( struct V_3 * V_4 , T_2 V_9 , T_3 V_10 ,
T_1 V_14 , int * V_11 )
{
int V_12 ;
T_4 V_13 = 0 ;
do {
if ( V_13 )
F_13 ( 1000 ) ;
V_12 = F_14 ( V_4 , V_18 , V_9 ,
V_10 , ( T_1 * ) & V_14 ) ;
} while ( V_12 != 0
&& ( V_13 ++ < V_16 ) );
if ( V_11 )
* V_11 = V_12 ;
F_3 ( V_17 , L_3 ,
V_9 , V_10 , V_14 ) ;
}
int
F_16 ( struct V_3 * V_4 , T_3 V_19 )
{
int V_11 = 0 ;
F_15 ( V_4 , V_20 , V_21 ,
( V_19 >> 8 ) & V_22 , & V_11 ) ;
if ( ! V_11 )
F_15 ( V_4 , V_20 ,
V_23 ,
( V_19 >> 16 ) & V_24 ,
& V_11 ) ;
if ( ! V_11 )
F_15 ( V_4 , V_20 ,
V_25 ,
( V_19 >> 24 ) & V_26 ,
& V_11 ) ;
return V_11 ;
}
T_3 F_17 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_27 )
{
int V_12 ;
T_3 V_28 = 0 ;
T_2 V_29 = V_10 & ~ V_30 ;
F_3 ( V_17 , L_4 , V_10 ) ;
if ( V_29 != V_4 -> V_31 ) {
if ( F_16 ( V_4 , V_29 ) )
return 0xFFFFFFFF ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
if ( V_27 == 4 )
V_10 |= V_32 ;
V_12 = F_18 ( V_4 , V_15 , V_20 ,
V_10 , & V_28 , V_27 ) ;
V_4 -> V_33 = ( V_12 != 0 ) ;
F_3 ( V_17 , L_5 , V_28 ) ;
if ( V_12 == 0 ) {
switch ( V_27 ) {
case sizeof( T_1 ) :
return V_28 & 0xff ;
case sizeof( V_34 ) :
return V_28 & 0xffff ;
case sizeof( T_3 ) :
return V_28 ;
default:
V_4 -> V_33 = true ;
}
}
F_3 ( ERROR , L_6 , V_10 , V_27 ) ;
return 0xFFFFFFFF ;
}
T_3 F_19 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_27 ,
T_3 V_14 )
{
int V_12 ;
T_2 V_29 = V_10 & ~ V_30 ;
int V_11 = 0 ;
F_3 ( V_17 , L_7 ,
V_10 , V_27 * 8 , V_14 ) ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_16 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
if ( V_27 == 4 )
V_10 |= V_32 ;
V_12 =
F_18 ( V_4 , V_18 , V_20 ,
V_10 , & V_14 , V_27 ) ;
V_4 -> V_33 = ( V_12 != 0 ) ;
if ( V_12 == 0 )
return 0 ;
F_3 ( ERROR , L_8 ,
V_14 , V_10 , V_27 ) ;
return 0xFFFFFFFF ;
}
bool F_20 ( struct V_3 * V_4 )
{
return V_4 -> V_33 ;
}
static int F_21 ( struct V_3 * V_4 , T_2 V_35 ,
T_2 V_36 , T_2 V_37 , T_3 * V_10 )
{
T_2 V_29 = * V_10 & ~ V_30 ;
int V_11 = 0 ;
if ( V_36 & V_38 )
return - V_39 ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_16 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
* V_10 &= V_30 ;
if ( V_37 == 4 )
* V_10 |= V_32 ;
return 0 ;
}
int
F_22 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , T_1 * V_40 , T_2 V_41 )
{
struct V_42 * V_43 ;
int V_11 ;
V_43 = F_23 ( V_41 ) ;
if ( ! V_43 ) {
F_3 ( ERROR , L_9 ,
V_41 ) ;
return - V_44 ;
}
V_11 = F_24 ( V_4 , V_10 , V_35 , V_36 , V_43 ) ;
if ( ! V_11 )
memcpy ( V_40 , V_43 -> V_14 , V_41 ) ;
F_25 ( V_43 ) ;
return V_11 ;
}
int
F_24 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , struct V_42 * V_45 )
{
T_2 V_46 ;
T_2 V_37 ;
int V_11 = 0 ;
F_3 ( V_17 , L_10 ,
V_35 , V_10 , V_45 -> V_47 ) ;
V_37 = ( V_36 & V_48 ) ? 4 : 2 ;
V_11 = F_21 ( V_4 , V_35 , V_36 , V_37 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_46 = ( V_36 & V_49 ) ? V_50 : V_51 ;
V_11 = F_26 ( V_4 , V_46 , V_15 ,
V_35 , V_10 , V_45 ) ;
return V_11 ;
}
int F_27 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , struct V_52 * V_53 )
{
T_2 V_46 ;
T_2 V_37 ;
int V_11 = 0 ;
F_3 ( V_17 , L_10 ,
V_35 , V_10 , V_53 -> V_54 ) ;
V_37 = ( V_36 & V_48 ) ? 4 : 2 ;
V_11 = F_21 ( V_4 , V_35 , V_36 , V_37 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_46 = ( V_36 & V_49 ) ? V_50 : V_51 ;
V_11 = F_28 ( V_4 , V_46 , V_15 , V_35 , V_10 ,
V_53 ) ;
return V_11 ;
}
int
F_29 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , T_1 * V_40 , T_2 V_41 )
{
struct V_42 * V_43 ;
int V_11 ;
V_43 = F_23 ( V_41 ) ;
if ( ! V_43 ) {
F_3 ( ERROR , L_9 ,
V_41 ) ;
return - V_44 ;
}
memcpy ( V_43 -> V_14 , V_40 , V_41 ) ;
V_11 = F_30 ( V_4 , V_10 , V_35 , V_36 , V_43 ) ;
F_25 ( V_43 ) ;
return V_11 ;
}
int
F_30 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , struct V_42 * V_45 )
{
T_2 V_46 ;
T_2 V_37 ;
T_2 V_29 = V_10 & ~ V_30 ;
int V_11 = 0 ;
F_3 ( V_17 , L_10 ,
V_35 , V_10 , V_45 -> V_47 ) ;
if ( V_36 & V_38 )
return - V_39 ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_16 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
V_46 = ( V_36 & V_49 ) ? V_50 : V_51 ;
V_37 = ( V_36 & V_48 ) ? 4 : 2 ;
if ( V_37 == 4 )
V_10 |= V_32 ;
return F_26 ( V_4 , V_46 , V_18 , V_35 ,
V_10 , V_45 ) ;
}
int F_31 ( struct V_3 * V_4 , T_2 V_55 , T_3 V_10 ,
T_1 * V_40 , T_2 V_41 )
{
struct V_42 * V_43 ;
bool V_56 = V_55 ? V_18 : V_15 ;
int V_11 ;
V_10 &= V_30 ;
V_10 |= V_32 ;
V_43 = F_23 ( V_41 ) ;
if ( ! V_43 ) {
F_3 ( ERROR , L_9 ,
V_41 ) ;
return - V_44 ;
}
if ( V_56 )
memcpy ( V_43 -> V_14 , V_40 , V_41 ) ;
V_11 = F_26 ( V_4 , V_51 , V_56 ,
V_20 , V_10 , V_43 ) ;
if ( ! V_11 && ! V_56 )
memcpy ( V_40 , V_43 -> V_14 , V_41 ) ;
F_25 ( V_43 ) ;
return V_11 ;
}
int F_32 ( struct V_3 * V_4 , T_2 V_35 )
{
char V_57 = ( char ) V_35 ;
F_3 ( V_7 , L_11 ) ;
F_14 ( V_4 , V_18 , V_58 ,
V_59 , & V_57 ) ;
F_3 ( V_7 , L_12 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 )
{
T_3 V_60 = 0 ;
int V_61 = 0 ;
V_61 = F_34 ( V_4 ) ;
if ( V_61 )
goto V_62;
V_60 = V_63 ;
V_4 -> V_31 = V_63 ;
V_4 -> V_8 = F_35 ( V_60 , V_4 ) ;
if ( ! V_4 -> V_8 ) {
F_3 ( ERROR , L_13 ) ;
V_61 = - V_64 ;
goto V_62;
}
V_62:
if ( V_61 )
F_36 ( V_4 ) ;
return V_61 ;
}
int F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_37 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
F_38 ( V_4 ) ;
V_4 -> V_31 = 0 ;
return 0 ;
}
void F_39 ( struct V_3 * V_4 , bool V_65 )
{
if ( V_65 )
F_40 ( V_4 -> V_8 , V_66 ) ;
else
F_40 ( V_4 -> V_8 , 0 ) ;
}
