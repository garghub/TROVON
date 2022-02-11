static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 -> V_6 ) ;
F_3 ( V_7 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 -> V_8 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( struct V_3 * V_4 )
{
F_3 ( V_7 , L_2 ) ;
F_6 ( V_4 -> V_2 [ 1 ] ) ;
F_8 ( V_4 -> V_2 [ 1 ] , F_1 ) ;
F_4 ( V_4 -> V_2 [ 1 ] ) ;
return 0 ;
}
int F_9 ( struct V_3 * V_4 )
{
F_3 ( V_7 , L_2 ) ;
F_6 ( V_4 -> V_2 [ 1 ] ) ;
F_10 ( V_4 -> V_2 [ 1 ] ) ;
F_4 ( V_4 -> V_2 [ 1 ] ) ;
return 0 ;
}
T_1 F_11 ( struct V_3 * V_4 , T_2 V_9 , T_3 V_10 ,
int * V_11 )
{
int V_12 ;
T_4 V_13 = 0 ;
T_1 V_14 = 0 ;
do {
if ( V_13 )
F_12 ( 1000 ) ;
V_12 = F_13 ( V_4 , V_15 , V_9 ,
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
F_14 ( struct V_3 * V_4 , T_2 V_9 , T_3 V_10 ,
T_1 V_14 , int * V_11 )
{
int V_12 ;
T_4 V_13 = 0 ;
do {
if ( V_13 )
F_12 ( 1000 ) ;
V_12 = F_13 ( V_4 , V_18 , V_9 ,
V_10 , ( T_1 * ) & V_14 ) ;
} while ( V_12 != 0
&& ( V_13 ++ < V_16 ) );
if ( V_11 )
* V_11 = V_12 ;
F_3 ( V_17 , L_3 ,
V_9 , V_10 , V_14 ) ;
}
int
F_15 ( struct V_3 * V_4 , T_3 V_19 )
{
int V_11 = 0 ;
F_14 ( V_4 , V_20 , V_21 ,
( V_19 >> 8 ) & V_22 , & V_11 ) ;
if ( ! V_11 )
F_14 ( V_4 , V_20 ,
V_23 ,
( V_19 >> 16 ) & V_24 ,
& V_11 ) ;
if ( ! V_11 )
F_14 ( V_4 , V_20 ,
V_25 ,
( V_19 >> 24 ) & V_26 ,
& V_11 ) ;
return V_11 ;
}
T_3 F_16 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_27 )
{
int V_12 ;
T_3 V_28 = 0 ;
T_2 V_29 = V_10 & ~ V_30 ;
F_3 ( V_17 , L_4 , V_10 ) ;
if ( V_29 != V_4 -> V_31 ) {
if ( F_15 ( V_4 , V_29 ) )
return 0xFFFFFFFF ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
if ( V_27 == 4 )
V_10 |= V_32 ;
V_12 = F_17 ( V_4 , V_15 , V_20 ,
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
T_3 F_18 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_27 ,
T_3 V_14 )
{
int V_12 ;
T_2 V_29 = V_10 & ~ V_30 ;
int V_11 = 0 ;
F_3 ( V_17 , L_7 ,
V_10 , V_27 * 8 , V_14 ) ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_15 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
if ( V_27 == 4 )
V_10 |= V_32 ;
V_12 =
F_17 ( V_4 , V_18 , V_20 ,
V_10 , & V_14 , V_27 ) ;
V_4 -> V_33 = ( V_12 != 0 ) ;
if ( V_12 == 0 )
return 0 ;
F_3 ( ERROR , L_8 ,
V_14 , V_10 , V_27 ) ;
return 0xFFFFFFFF ;
}
bool F_19 ( struct V_3 * V_4 )
{
return V_4 -> V_33 ;
}
int
F_20 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 ,
T_1 * V_37 , T_2 V_38 , struct V_39 * V_40 )
{
int V_12 ;
T_2 V_41 ;
T_2 V_42 ;
T_2 V_29 = V_10 & ~ V_30 ;
int V_11 = 0 ;
F_3 ( V_17 , L_9 , V_35 , V_10 , V_38 ) ;
if ( V_36 & V_43 )
return - V_44 ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_15 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
V_41 = ( V_36 & V_45 ) ? V_46 : V_47 ;
V_42 = ( V_36 & V_48 ) ? 4 : 2 ;
if ( V_42 == 4 )
V_10 |= V_32 ;
V_12 = F_21 ( V_4 , V_41 , V_15 ,
V_35 , V_10 , V_42 , V_38 , V_37 , V_40 ) ;
return V_12 ;
}
int
F_22 ( struct V_3 * V_4 , T_3 V_10 , T_2 V_35 ,
T_2 V_36 , T_1 * V_37 , T_2 V_38 , struct V_39 * V_40 )
{
T_2 V_41 ;
T_2 V_42 ;
T_2 V_29 = V_10 & ~ V_30 ;
int V_11 = 0 ;
F_3 ( V_17 , L_9 , V_35 , V_10 , V_38 ) ;
if ( V_36 & V_43 )
return - V_44 ;
if ( V_29 != V_4 -> V_31 ) {
V_11 = F_15 ( V_4 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_31 = V_29 ;
}
V_10 &= V_30 ;
V_41 = ( V_36 & V_45 ) ? V_46 : V_47 ;
V_42 = ( V_36 & V_48 ) ? 4 : 2 ;
if ( V_42 == 4 )
V_10 |= V_32 ;
return F_21 ( V_4 , V_41 , V_18 , V_35 ,
V_10 , V_42 , V_38 , V_37 , V_40 ) ;
}
int F_23 ( struct V_3 * V_4 , T_2 V_49 , T_3 V_10 ,
T_1 * V_37 , T_2 V_38 )
{
V_10 &= V_30 ;
V_10 |= V_32 ;
return F_21 ( V_4 , V_47 ,
( V_49 ? V_18 : V_15 ) , V_20 ,
V_10 , 4 , V_38 , V_37 , NULL ) ;
}
int F_24 ( struct V_3 * V_4 , T_2 V_35 )
{
char V_50 = ( char ) V_35 ;
F_3 ( V_7 , L_10 ) ;
F_13 ( V_4 , V_18 , V_51 ,
V_52 , & V_50 ) ;
F_3 ( V_7 , L_11 ) ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 )
{
T_3 V_53 = 0 ;
int V_54 = 0 ;
V_54 = F_26 ( V_4 ) ;
if ( V_54 )
goto V_55;
V_53 = V_56 ;
V_4 -> V_31 = V_56 ;
V_4 -> V_8 = F_27 ( 0 , 0 , 0 , 0 , V_53 , V_4 ) ;
if ( ! V_4 -> V_8 ) {
F_3 ( ERROR , L_12 ) ;
V_54 = - V_57 ;
goto V_55;
}
V_55:
if ( V_54 )
F_28 ( V_4 ) ;
return V_54 ;
}
int F_28 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_29 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
F_30 ( V_4 ) ;
V_4 -> V_31 = 0 ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 , bool V_58 )
{
if ( V_58 )
F_32 ( V_4 -> V_8 , V_59 ) ;
else
F_32 ( V_4 -> V_8 , 0 ) ;
}
