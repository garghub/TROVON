static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
struct V_16 V_17 [ 2 ] ;
int V_18 , V_19 ;
T_4 V_20 ;
V_13 = F_2 ( V_4 , struct V_12 , V_4 ) ;
V_11 = F_3 ( V_13 ) ;
V_20 = V_21 << V_11 -> V_22 ;
if ( V_11 -> V_22 == 7 ) {
V_20 |= V_8 & 0x7f ;
V_18 = 10 ;
} else {
V_20 |= V_8 & 0x3f ;
V_18 = 9 ;
}
F_4 ( & V_11 -> V_23 -> V_13 , L_1 ,
V_20 , V_11 -> V_23 -> V_24 ) ;
F_5 ( & V_15 ) ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
V_17 [ 0 ] . V_25 = ( char * ) & V_20 ;
V_17 [ 0 ] . V_26 = 2 ;
V_17 [ 0 ] . V_27 = V_18 ;
F_6 ( & V_17 [ 0 ] , & V_15 ) ;
V_17 [ 1 ] . V_28 = V_7 ;
V_17 [ 1 ] . V_26 = V_9 ;
V_17 [ 1 ] . V_27 = 8 ;
F_6 ( & V_17 [ 1 ] , & V_15 ) ;
F_7 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_30 -> V_31 )
V_11 -> V_30 -> V_31 ( V_11 ) ;
V_19 = F_8 ( V_11 -> V_23 , & V_15 ) ;
F_9 ( 250 ) ;
if ( V_19 ) {
F_10 ( & V_11 -> V_23 -> V_13 , L_2 ,
V_9 , ( int ) V_8 , V_19 ) ;
}
if ( V_11 -> V_30 -> V_32 )
V_11 -> V_30 -> V_32 ( V_11 ) ;
F_11 ( & V_11 -> V_29 ) ;
return V_19 ? : V_9 ;
}
static int F_12 ( struct V_10 * V_11 , int V_33 )
{
struct V_14 V_15 ;
struct V_16 V_17 ;
int V_18 , V_19 ;
T_4 V_20 ;
V_20 = V_34 << V_11 -> V_22 ;
if ( V_11 -> V_22 == 7 ) {
V_20 |= ( V_33 ? V_35 : V_36 ) << 1 ;
V_18 = 10 ;
} else {
V_20 |= ( V_33 ? V_35 : V_36 ) ;
V_18 = 9 ;
}
F_4 ( & V_11 -> V_23 -> V_13 , L_3 , V_20 ) ;
F_5 ( & V_15 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_25 = & V_20 ;
V_17 . V_26 = 2 ;
V_17 . V_27 = V_18 ;
F_6 ( & V_17 , & V_15 ) ;
F_7 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_30 -> V_31 )
V_11 -> V_30 -> V_31 ( V_11 ) ;
V_19 = F_8 ( V_11 -> V_23 , & V_15 ) ;
F_9 ( 250 ) ;
if ( V_19 )
F_10 ( & V_11 -> V_23 -> V_13 , L_4 ,
V_33 ? L_5 : L_6 , V_19 ) ;
if ( V_11 -> V_30 -> V_32 )
V_11 -> V_30 -> V_32 ( V_11 ) ;
F_11 ( & V_11 -> V_29 ) ;
return V_19 ;
}
static T_1
F_13 ( struct V_10 * V_11 ,
const char * V_7 , unsigned V_8 )
{
struct V_14 V_15 ;
struct V_16 V_17 [ 2 ] ;
int V_18 , V_37 , V_19 ;
T_4 V_20 ;
V_20 = V_38 << V_11 -> V_22 ;
if ( V_11 -> V_22 == 7 ) {
V_20 |= V_8 & 0x7f ;
V_18 = 10 ;
V_37 = 1 ;
} else {
V_20 |= V_8 & 0x3f ;
V_18 = 9 ;
V_37 = 2 ;
}
F_4 ( & V_11 -> V_23 -> V_13 , L_7 , V_20 ) ;
F_5 ( & V_15 ) ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
V_17 [ 0 ] . V_25 = ( char * ) & V_20 ;
V_17 [ 0 ] . V_26 = 2 ;
V_17 [ 0 ] . V_27 = V_18 ;
F_6 ( & V_17 [ 0 ] , & V_15 ) ;
V_17 [ 1 ] . V_25 = V_7 ;
V_17 [ 1 ] . V_26 = V_37 ;
V_17 [ 1 ] . V_27 = 8 ;
F_6 ( & V_17 [ 1 ] , & V_15 ) ;
V_19 = F_8 ( V_11 -> V_23 , & V_15 ) ;
F_14 ( 6 ) ;
return V_19 ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_39 , V_19 , V_40 = 1 ;
V_13 = F_2 ( V_4 , struct V_12 , V_4 ) ;
V_11 = F_3 ( V_13 ) ;
if ( V_11 -> V_22 == 6 ) {
V_40 = 2 ;
V_9 &= ~ 1 ;
}
V_19 = F_12 ( V_11 , 1 ) ;
if ( V_19 )
return V_19 ;
F_7 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_30 -> V_31 )
V_11 -> V_30 -> V_31 ( V_11 ) ;
for ( V_39 = 0 ; V_39 < V_9 ; V_39 += V_40 ) {
V_19 = F_13 ( V_11 , & V_7 [ V_39 ] , V_8 + V_39 ) ;
if ( V_19 ) {
F_10 ( & V_11 -> V_23 -> V_13 , L_8 ,
( int ) V_8 + V_39 , V_19 ) ;
break;
}
}
if ( V_11 -> V_30 -> V_32 )
V_11 -> V_30 -> V_32 ( V_11 ) ;
F_11 ( & V_11 -> V_29 ) ;
F_12 ( V_11 , 0 ) ;
return V_19 ? : V_9 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_41 * V_42 = V_11 -> V_30 ;
struct V_14 V_15 ;
struct V_16 V_17 ;
int V_18 , V_19 ;
T_4 V_20 ;
V_20 = V_34 << V_11 -> V_22 ;
if ( V_11 -> V_22 == 7 ) {
V_20 |= V_43 << 1 ;
V_18 = 10 ;
} else {
V_20 |= V_43 ;
V_18 = 9 ;
}
F_5 ( & V_15 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_25 = & V_20 ;
V_17 . V_26 = 2 ;
V_17 . V_27 = V_18 ;
F_6 ( & V_17 , & V_15 ) ;
F_7 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_30 -> V_31 )
V_11 -> V_30 -> V_31 ( V_11 ) ;
V_19 = F_8 ( V_11 -> V_23 , & V_15 ) ;
if ( V_19 )
F_10 ( & V_11 -> V_23 -> V_13 , L_9 , V_19 ) ;
F_14 ( 6 ) ;
if ( V_42 -> V_32 )
V_42 -> V_32 ( V_11 ) ;
F_11 ( & V_11 -> V_29 ) ;
return V_19 ;
}
static T_1 F_17 ( struct V_12 * V_13 ,
struct V_44 * V_45 ,
const char * V_7 , T_3 V_9 )
{
struct V_10 * V_11 = F_3 ( V_13 ) ;
int V_46 = 0 , V_19 ;
sscanf ( V_7 , L_10 , & V_46 ) ;
if ( V_46 ) {
V_19 = F_12 ( V_11 , 1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_16 ( V_11 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_12 ( V_11 , 0 ) ;
if ( V_19 )
return V_19 ;
}
return V_9 ;
}
static int F_18 ( struct V_47 * V_23 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
int V_48 ;
V_42 = V_23 -> V_13 . V_49 ;
if ( ! V_42 ) {
F_10 ( & V_23 -> V_13 , L_11 ) ;
return - V_50 ;
}
V_11 = F_19 ( sizeof( * V_11 ) , V_51 ) ;
if ( ! V_11 )
return - V_52 ;
if ( V_42 -> V_53 & V_54 )
V_11 -> V_22 = 7 ;
else if ( V_42 -> V_53 & V_55 )
V_11 -> V_22 = 6 ;
else {
F_10 ( & V_23 -> V_13 , L_12 ) ;
V_48 = - V_56 ;
goto V_57;
}
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_23 = F_21 ( V_23 ) ;
V_11 -> V_30 = V_42 ;
F_22 ( & V_11 -> V_58 ) ;
V_11 -> V_58 . V_45 . V_59 = L_13 ;
V_11 -> V_58 . V_45 . V_60 = V_61 ;
V_11 -> V_58 . V_62 = F_1 ;
V_11 -> V_58 . V_63 = 128 ;
if ( ! ( V_42 -> V_53 & V_64 ) ) {
V_11 -> V_58 . V_65 = F_15 ;
V_11 -> V_58 . V_45 . V_60 |= V_66 ;
}
V_48 = F_23 ( & V_23 -> V_13 . V_4 , & V_11 -> V_58 ) ;
if ( V_48 )
goto V_57;
F_24 ( & V_23 -> V_13 , L_14 ,
( V_42 -> V_53 & V_54 ) ? 8 : 16 ,
( V_42 -> V_53 & V_64 ) ? L_15 : L_16 ) ;
if ( ! ( V_42 -> V_53 & V_64 ) ) {
if ( F_25 ( & V_23 -> V_13 , & V_67 ) )
F_10 ( & V_23 -> V_13 , L_17 ) ;
}
F_26 ( V_23 , V_11 ) ;
return 0 ;
V_57:
F_27 ( V_11 ) ;
return V_48 ;
}
static int F_28 ( struct V_47 * V_23 )
{
struct V_10 * V_11 = F_29 ( V_23 ) ;
if ( ! ( V_11 -> V_30 -> V_53 & V_64 ) )
F_30 ( & V_23 -> V_13 , & V_67 ) ;
F_31 ( & V_23 -> V_13 . V_4 , & V_11 -> V_58 ) ;
F_27 ( V_11 ) ;
return 0 ;
}
