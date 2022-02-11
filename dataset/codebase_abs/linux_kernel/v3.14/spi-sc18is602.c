static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
int V_6 = 1000000 * V_3 / V_2 -> V_7 + 1 ;
T_1 V_8 [ 1 ] ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
V_5 = F_2 ( V_2 -> V_9 , V_8 , 1 ) ;
if ( V_5 >= 0 )
return 0 ;
F_3 ( V_6 , V_6 * 2 ) ;
}
return - V_10 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_13 * V_14 , bool V_15 )
{
unsigned int V_3 = V_14 -> V_3 ;
int V_16 ;
if ( V_2 -> V_17 == 0 ) {
V_2 -> V_18 [ 0 ] = 1 << V_12 -> V_19 -> V_20 ;
V_2 -> V_17 = 1 ;
V_2 -> V_21 = 0 ;
}
if ( V_14 -> V_22 ) {
memcpy ( & V_2 -> V_18 [ V_2 -> V_17 ] , V_14 -> V_22 , V_3 ) ;
V_2 -> V_17 += V_3 ;
if ( V_14 -> V_23 )
V_15 = true ;
else
V_2 -> V_21 = V_2 -> V_17 - 1 ;
} else if ( V_14 -> V_23 ) {
V_2 -> V_21 = V_2 -> V_17 - 1 ;
memset ( & V_2 -> V_18 [ V_2 -> V_17 ] , 0 , V_3 ) ;
V_2 -> V_17 += V_3 ;
V_15 = true ;
}
if ( V_15 && V_2 -> V_17 > 1 ) {
V_16 = F_1 ( V_2 , V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_5 ( V_2 -> V_9 , V_2 -> V_18 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_16 != V_2 -> V_17 )
return - V_25 ;
if ( V_14 -> V_23 ) {
int V_26 = V_2 -> V_21 + V_3 ;
V_16 = F_1 ( V_2 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_2 ( V_2 -> V_9 , V_2 -> V_18 , V_26 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_16 != V_26 )
return - V_25 ;
memcpy ( V_14 -> V_23 , & V_2 -> V_18 [ V_2 -> V_21 ] , V_3 ) ;
}
V_2 -> V_17 = 0 ;
}
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_27 , T_1 V_28 )
{
T_1 V_29 = 0 ;
int V_16 ;
if ( V_28 & V_30 )
V_29 |= V_31 ;
if ( V_28 & V_32 )
V_29 |= V_33 ;
if ( V_28 & V_34 )
V_29 |= V_35 ;
if ( V_27 >= V_2 -> V_36 / 4 ) {
V_29 |= V_37 ;
V_2 -> V_7 = V_2 -> V_36 / 4 ;
} else if ( V_27 >= V_2 -> V_36 / 16 ) {
V_29 |= V_38 ;
V_2 -> V_7 = V_2 -> V_36 / 16 ;
} else if ( V_27 >= V_2 -> V_36 / 64 ) {
V_29 |= V_39 ;
V_2 -> V_7 = V_2 -> V_36 / 64 ;
} else {
V_29 |= V_40 ;
V_2 -> V_7 = V_2 -> V_36 / 128 ;
}
if ( V_29 == V_2 -> V_29 )
return 0 ;
V_16 = F_7 ( V_2 -> V_9 , 0xf0 , V_29 ) ;
if ( V_16 < 0 )
return V_16 ;
V_2 -> V_29 = V_29 ;
return 0 ;
}
static int F_8 ( struct V_41 * V_19 ,
struct V_13 * V_14 , int V_17 )
{
T_3 V_27 ;
if ( V_14 && V_14 -> V_3 + V_17 > V_24 )
return - V_42 ;
V_27 = V_19 -> V_43 ;
if ( V_14 && V_14 -> V_44 )
V_27 = V_14 -> V_44 ;
if ( V_27 == 0 )
return - V_42 ;
return 0 ;
}
static int F_9 ( struct V_45 * V_46 ,
struct V_11 * V_47 )
{
struct V_1 * V_2 = F_10 ( V_46 ) ;
struct V_41 * V_19 = V_47 -> V_19 ;
struct V_13 * V_14 ;
int V_48 = 0 ;
if ( V_2 -> V_49 == V_1 && V_19 -> V_20 == 2 ) {
V_48 = - V_50 ;
goto error;
}
V_2 -> V_17 = 0 ;
F_11 (t, &m->transfers, transfer_list) {
T_2 V_27 = V_14 -> V_44 ? : V_19 -> V_43 ;
bool V_15 ;
V_48 = F_8 ( V_19 , V_14 , V_2 -> V_17 ) ;
if ( V_48 < 0 )
break;
V_48 = F_6 ( V_2 , V_27 , V_19 -> V_28 ) ;
if ( V_48 < 0 )
break;
V_15 = V_14 -> V_51 || F_12 ( & V_14 -> V_52 ,
& V_47 -> V_53 ) ;
if ( V_14 -> V_3 ) {
V_48 = F_4 ( V_2 , V_47 , V_14 , V_15 ) ;
if ( V_48 < 0 )
break;
V_47 -> V_54 += V_48 ;
}
V_48 = 0 ;
if ( V_14 -> V_55 )
F_13 ( V_14 -> V_55 ) ;
}
error:
V_47 -> V_48 = V_48 ;
F_14 ( V_46 ) ;
return V_48 ;
}
static int F_15 ( struct V_41 * V_19 )
{
if ( V_19 -> V_28 & ~ ( V_30 | V_32 | V_34 ) )
return - V_42 ;
return F_8 ( V_19 , NULL , 0 ) ;
}
static int F_16 ( struct V_56 * V_9 ,
const struct V_57 * V_49 )
{
struct V_58 * V_59 = & V_9 -> V_59 ;
struct V_60 * V_61 = V_59 -> V_62 ;
struct V_63 * V_64 = F_17 ( V_59 ) ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int error ;
if ( ! F_18 ( V_9 -> V_65 , V_66 |
V_67 ) )
return - V_42 ;
V_46 = F_19 ( V_59 , sizeof( struct V_1 ) ) ;
if ( ! V_46 )
return - V_68 ;
V_2 = F_10 ( V_46 ) ;
F_20 ( V_9 , V_2 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_29 = 0xff ;
V_2 -> V_49 = V_49 -> V_69 ;
switch ( V_2 -> V_49 ) {
case V_1 :
case V_70 :
V_46 -> V_71 = 4 ;
V_2 -> V_36 = V_72 ;
break;
case V_73 :
V_46 -> V_71 = 2 ;
if ( V_64 ) {
V_2 -> V_36 = V_64 -> V_74 ;
} else {
const T_4 * V_75 ;
int V_3 ;
V_75 = F_21 ( V_61 , L_1 , & V_3 ) ;
if ( V_75 && V_3 >= sizeof( T_4 ) )
V_2 -> V_36 = F_22 ( V_75 ) ;
}
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_72 ;
break;
}
V_46 -> V_76 = V_9 -> V_65 -> V_77 ;
V_46 -> V_78 = V_30 | V_32 | V_34 ;
V_46 -> V_79 = F_23 ( 8 ) ;
V_46 -> V_80 = F_15 ;
V_46 -> V_81 = F_9 ;
V_46 -> V_59 . V_62 = V_61 ;
error = F_24 ( V_59 , V_46 ) ;
if ( error )
goto V_82;
return 0 ;
V_82:
F_25 ( V_46 ) ;
return error ;
}
