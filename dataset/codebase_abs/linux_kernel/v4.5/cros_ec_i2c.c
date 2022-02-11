static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_6 -> V_9 ;
int V_10 = - V_11 ;
int V_12 ;
int V_13 ;
T_1 * V_14 = NULL ;
T_1 * V_15 = NULL ;
T_1 V_16 ;
struct V_17 V_17 [ 2 ] ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 = sizeof( struct V_20 ) ;
int V_25 = sizeof( struct V_22 ) ;
V_17 [ 0 ] . V_26 = V_5 -> V_26 ;
V_17 [ 0 ] . V_27 = 0 ;
V_17 [ 1 ] . V_26 = V_5 -> V_26 ;
V_17 [ 1 ] . V_27 = V_28 ;
V_13 = V_8 -> V_29 + V_25 ;
F_5 ( V_13 > V_6 -> V_30 ) ;
V_15 = V_6 -> V_31 ;
V_17 [ 1 ] . V_32 = V_13 ;
V_17 [ 1 ] . V_33 = ( char * ) V_15 ;
V_13 = V_8 -> V_34 + V_24 ;
F_5 ( V_13 > V_6 -> V_35 ) ;
V_14 = V_6 -> V_36 ;
V_17 [ 0 ] . V_32 = V_13 ;
V_17 [ 0 ] . V_33 = ( char * ) V_14 ;
V_21 = (struct V_20 * ) V_14 ;
V_21 -> V_37 = V_38 ;
V_6 -> V_36 ++ ;
V_10 = F_6 ( V_6 , V_8 ) ;
V_6 -> V_36 -- ;
V_10 = F_7 ( V_5 -> V_39 , V_17 , 2 ) ;
if ( V_10 < 0 ) {
F_8 ( V_6 -> V_3 , L_1 , V_10 ) ;
goto V_40;
} else if ( V_10 != 2 ) {
F_9 ( V_6 -> V_3 , L_2 , V_10 ) ;
V_10 = - V_41 ;
goto V_40;
}
V_23 = (struct V_22 * ) V_15 ;
V_8 -> V_42 = V_23 -> V_42 ;
V_19 = & V_23 -> V_19 ;
switch ( V_8 -> V_42 ) {
case V_43 :
break;
case V_44 :
V_10 = - V_45 ;
F_8 ( V_6 -> V_3 , L_3 ,
V_8 -> V_46 ) ;
goto V_40;
default:
F_8 ( V_6 -> V_3 , L_4 ,
V_8 -> V_46 , V_8 -> V_42 ) ;
if ( V_23 -> V_42 == V_47 &&
V_23 -> V_48 == 0 ) {
V_10 = - V_49 ;
goto V_40;
}
}
if ( V_23 -> V_48 < sizeof( struct V_18 ) ) {
F_9 ( V_6 -> V_3 ,
L_5 ,
V_23 -> V_48 ) ;
V_10 = - V_50 ;
goto V_40;
}
if ( V_8 -> V_29 < V_19 -> V_51 ) {
F_9 ( V_6 -> V_3 ,
L_6 ,
V_8 -> V_29 ,
V_19 -> V_51 ) ;
V_10 = - V_52 ;
goto V_40;
}
V_16 = 0 ;
for ( V_12 = 0 ; V_12 < sizeof( struct V_18 ) ; V_12 ++ )
V_16 += ( ( T_1 * ) V_19 ) [ V_12 ] ;
memcpy ( V_8 -> V_53 ,
V_15 + V_25 ,
V_19 -> V_51 ) ;
for ( V_12 = 0 ; V_12 < V_19 -> V_51 ; V_12 ++ )
V_16 += V_8 -> V_53 [ V_12 ] ;
if ( V_16 ) {
F_9 ( V_6 -> V_3 , L_7 ) ;
V_10 = - V_50 ;
goto V_40;
}
V_10 = V_19 -> V_51 ;
V_40:
if ( V_8 -> V_46 == V_54 )
F_10 ( V_55 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_6 -> V_9 ;
int V_10 = - V_11 ;
int V_12 ;
int V_32 ;
int V_13 ;
T_1 * V_14 = NULL ;
T_1 * V_15 = NULL ;
T_1 V_16 ;
struct V_17 V_17 [ 2 ] ;
V_17 [ 0 ] . V_26 = V_5 -> V_26 ;
V_17 [ 0 ] . V_27 = 0 ;
V_17 [ 1 ] . V_26 = V_5 -> V_26 ;
V_17 [ 1 ] . V_27 = V_28 ;
V_13 = V_8 -> V_29 + 3 ;
V_15 = F_12 ( V_13 , V_56 ) ;
if ( ! V_15 )
goto V_40;
V_17 [ 1 ] . V_32 = V_13 ;
V_17 [ 1 ] . V_33 = ( char * ) V_15 ;
V_13 = V_8 -> V_34 + 4 ;
V_14 = F_12 ( V_13 , V_56 ) ;
if ( ! V_14 )
goto V_40;
V_17 [ 0 ] . V_32 = V_13 ;
V_17 [ 0 ] . V_33 = ( char * ) V_14 ;
V_14 [ 0 ] = V_57 + V_8 -> V_58 ;
V_14 [ 1 ] = V_8 -> V_46 ;
V_14 [ 2 ] = V_8 -> V_34 ;
V_16 = V_14 [ 0 ] + V_14 [ 1 ] + V_14 [ 2 ] ;
for ( V_12 = 0 ; V_12 < V_8 -> V_34 ; V_12 ++ ) {
V_14 [ 3 + V_12 ] = V_8 -> V_53 [ V_12 ] ;
V_16 += V_14 [ 3 + V_12 ] ;
}
V_14 [ 3 + V_8 -> V_34 ] = V_16 ;
V_10 = F_7 ( V_5 -> V_39 , V_17 , 2 ) ;
if ( V_10 < 0 ) {
F_9 ( V_6 -> V_3 , L_1 , V_10 ) ;
goto V_40;
} else if ( V_10 != 2 ) {
F_9 ( V_6 -> V_3 , L_2 , V_10 ) ;
V_10 = - V_41 ;
goto V_40;
}
V_8 -> V_42 = V_17 [ 1 ] . V_33 [ 0 ] ;
V_10 = F_13 ( V_6 , V_8 ) ;
if ( V_10 )
goto V_40;
V_32 = V_15 [ 1 ] ;
if ( V_32 > V_8 -> V_29 ) {
F_9 ( V_6 -> V_3 , L_8 ,
V_32 , V_8 -> V_29 ) ;
V_10 = - V_59 ;
goto V_40;
}
V_16 = V_15 [ 0 ] + V_15 [ 1 ] ;
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
V_8 -> V_53 [ V_12 ] = V_15 [ 2 + V_12 ] ;
V_16 += V_15 [ 2 + V_12 ] ;
}
F_8 ( V_6 -> V_3 , L_9 ,
V_17 [ 1 ] . V_32 , V_15 , V_16 ) ;
if ( V_16 != V_15 [ 2 + V_32 ] ) {
F_9 ( V_6 -> V_3 , L_7 ) ;
V_10 = - V_50 ;
goto V_40;
}
V_10 = V_32 ;
V_40:
F_14 ( V_15 ) ;
F_14 ( V_14 ) ;
if ( V_8 -> V_46 == V_54 )
F_10 ( V_55 ) ;
return V_10 ;
}
static int F_15 ( struct V_4 * V_5 ,
const struct V_60 * V_61 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_1 * V_6 = NULL ;
int V_62 ;
V_6 = F_16 ( V_3 , sizeof( * V_6 ) , V_56 ) ;
if ( ! V_6 )
return - V_11 ;
F_17 ( V_5 , V_6 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_9 = V_5 ;
V_6 -> V_63 = V_5 -> V_63 ;
V_6 -> V_64 = F_11 ;
V_6 -> V_65 = F_4 ;
V_6 -> V_66 = V_5 -> V_39 -> V_67 ;
V_6 -> V_30 = sizeof( struct V_22 ) +
sizeof( struct V_68 ) ;
V_6 -> V_35 = sizeof( struct V_20 ) ;
V_62 = F_18 ( V_6 ) ;
if ( V_62 ) {
F_9 ( V_3 , L_10 ) ;
return V_62 ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_22 ( V_6 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_24 ( V_6 ) ;
}
