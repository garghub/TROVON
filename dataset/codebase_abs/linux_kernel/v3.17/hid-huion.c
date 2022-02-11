static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
if ( V_6 -> V_3 != NULL ) {
V_3 = V_6 -> V_3 ;
* V_4 = V_6 -> V_4 ;
}
break;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_12 = NULL ;
T_3 V_13 ;
T_4 V_14 [ V_15 ] ;
T_4 V_16 ;
T_1 * V_17 ;
T_4 V_18 ;
V_13 = V_19 * sizeof( * V_12 ) ;
V_12 = F_5 ( V_13 , V_20 ) ;
if ( V_12 == NULL ) {
F_6 ( V_2 , L_1 ) ;
V_9 = - V_21 ;
goto V_22;
}
V_9 = F_7 ( V_11 , F_8 ( V_11 , 0 ) ,
V_23 , V_24 ,
( V_25 << 8 ) + 0x64 ,
0x0409 , V_12 , V_13 ,
V_26 ) ;
if ( V_9 == - V_27 ) {
F_6 ( V_2 , L_2 ) ;
V_9 = - V_28 ;
goto V_22;
} else if ( V_9 < 0 ) {
F_6 ( V_2 , L_3 , V_9 ) ;
V_9 = - V_28 ;
goto V_22;
} else if ( V_9 != V_13 ) {
F_6 ( V_2 , L_4 ) ;
V_9 = - V_28 ;
goto V_22;
}
V_14 [ V_29 ] = F_9 ( V_12 [ V_30 ] ) ;
V_14 [ V_31 ] = F_9 ( V_12 [ V_32 ] ) ;
V_14 [ V_33 ] =
F_9 ( V_12 [ V_34 ] ) ;
V_16 = F_9 ( V_12 [ V_35 ] ) ;
if ( V_16 == 0 ) {
V_14 [ V_36 ] = 0 ;
V_14 [ V_37 ] = 0 ;
} else {
V_14 [ V_36 ] = V_14 [ V_29 ] *
1000 / V_16 ;
V_14 [ V_37 ] = V_14 [ V_31 ] *
1000 / V_16 ;
}
V_6 -> V_3 = F_10 ( & V_2 -> V_38 ,
sizeof( V_39 ) ,
V_20 ) ;
if ( V_6 -> V_3 == NULL ) {
F_6 ( V_2 , L_5 ) ;
V_9 = - V_21 ;
goto V_22;
}
V_6 -> V_4 = sizeof( V_39 ) ;
memcpy ( V_6 -> V_3 , V_39 ,
V_6 -> V_4 ) ;
for ( V_17 = V_6 -> V_3 ;
V_17 <= V_6 -> V_3 + V_6 -> V_4 - 4 ; ) {
if ( V_17 [ 0 ] == 0xFE && V_17 [ 1 ] == 0xED && V_17 [ 2 ] == 0x1D &&
V_17 [ 3 ] < sizeof( V_14 ) ) {
V_18 = V_14 [ V_17 [ 3 ] ] ;
F_11 ( F_12 ( V_18 ) , ( T_4 * ) V_17 ) ;
V_17 += 4 ;
} else {
V_17 ++ ;
}
}
V_9 = 0 ;
V_22:
F_13 ( V_12 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , const struct V_40 * V_41 )
{
int V_9 ;
struct V_42 * V_43 = F_15 ( V_2 -> V_38 . V_44 ) ;
struct V_5 * V_6 ;
V_6 = F_16 ( & V_2 -> V_38 , sizeof( * V_6 ) , V_20 ) ;
if ( V_6 == NULL ) {
F_6 ( V_2 , L_6 ) ;
return - V_21 ;
}
F_17 ( V_2 , V_6 ) ;
switch ( V_41 -> V_7 ) {
case V_8 :
if ( V_43 -> V_45 -> V_46 . V_47 == 0 ) {
V_9 = F_3 ( V_2 ) ;
if ( V_9 ) {
F_6 ( V_2 , L_7 ) ;
return V_9 ;
}
}
break;
}
V_9 = F_18 ( V_2 ) ;
if ( V_9 ) {
F_6 ( V_2 , L_8 ) ;
return V_9 ;
}
V_9 = F_19 ( V_2 , V_48 ) ;
if ( V_9 ) {
F_6 ( V_2 , L_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_49 * V_50 ,
T_5 * V_51 , int V_52 )
{
struct V_42 * V_43 = F_15 ( V_2 -> V_38 . V_44 ) ;
if ( V_43 -> V_45 -> V_46 . V_47 == 0 &&
V_50 -> type == V_53 &&
V_50 -> V_41 == 0x07 && V_52 >= 2 )
V_51 [ 1 ] ^= 0x40 ;
return 0 ;
}
