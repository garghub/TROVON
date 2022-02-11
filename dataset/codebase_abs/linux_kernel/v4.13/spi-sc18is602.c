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
if ( V_14 && V_14 -> V_3 + V_17 > V_24 )
return - V_42 ;
return 0 ;
}
static int F_9 ( struct V_43 * V_44 ,
struct V_11 * V_45 )
{
struct V_1 * V_2 = F_10 ( V_44 ) ;
struct V_41 * V_19 = V_45 -> V_19 ;
struct V_13 * V_14 ;
int V_46 = 0 ;
V_2 -> V_17 = 0 ;
F_11 (t, &m->transfers, transfer_list) {
bool V_15 ;
V_46 = F_8 ( V_19 , V_14 , V_2 -> V_17 ) ;
if ( V_46 < 0 )
break;
V_46 = F_6 ( V_2 , V_14 -> V_47 , V_19 -> V_28 ) ;
if ( V_46 < 0 )
break;
V_15 = V_14 -> V_48 || F_12 ( & V_14 -> V_49 ,
& V_45 -> V_50 ) ;
if ( V_14 -> V_3 ) {
V_46 = F_4 ( V_2 , V_45 , V_14 , V_15 ) ;
if ( V_46 < 0 )
break;
V_45 -> V_51 += V_46 ;
}
V_46 = 0 ;
if ( V_14 -> V_52 )
F_13 ( V_14 -> V_52 ) ;
}
V_45 -> V_46 = V_46 ;
F_14 ( V_44 ) ;
return V_46 ;
}
static int F_15 ( struct V_41 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 -> V_44 ) ;
if ( V_2 -> V_53 == V_1 && V_19 -> V_20 == 2 )
return - V_54 ;
return 0 ;
}
static int F_16 ( struct V_55 * V_9 ,
const struct V_56 * V_53 )
{
struct V_57 * V_58 = & V_9 -> V_58 ;
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = F_17 ( V_58 ) ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int error ;
if ( ! F_18 ( V_9 -> V_64 , V_65 |
V_66 ) )
return - V_42 ;
V_44 = F_19 ( V_58 , sizeof( struct V_1 ) ) ;
if ( ! V_44 )
return - V_67 ;
V_2 = F_10 ( V_44 ) ;
F_20 ( V_9 , V_2 ) ;
V_2 -> V_68 = F_21 ( V_58 , L_1 , V_69 ) ;
if ( F_22 ( V_2 -> V_68 ) )
return F_23 ( V_2 -> V_68 ) ;
F_24 ( V_2 -> V_68 , 0 ) ;
V_2 -> V_44 = V_44 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_29 = 0xff ;
if ( V_9 -> V_58 . V_61 )
V_2 -> V_53 = (enum V_70 ) F_25 ( & V_9 -> V_58 ) ;
else
V_2 -> V_53 = V_53 -> V_71 ;
switch ( V_2 -> V_53 ) {
case V_1 :
case V_72 :
V_44 -> V_73 = 4 ;
V_2 -> V_36 = V_74 ;
break;
case V_75 :
V_44 -> V_73 = 2 ;
if ( V_63 ) {
V_2 -> V_36 = V_63 -> V_76 ;
} else {
const T_3 * V_77 ;
int V_3 ;
V_77 = F_26 ( V_60 , L_2 , & V_3 ) ;
if ( V_77 && V_3 >= sizeof( T_3 ) )
V_2 -> V_36 = F_27 ( V_77 ) ;
}
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_74 ;
break;
}
V_44 -> V_78 = V_60 ? - 1 : V_9 -> V_64 -> V_79 ;
V_44 -> V_80 = V_30 | V_32 | V_34 ;
V_44 -> V_81 = F_28 ( 8 ) ;
V_44 -> V_82 = F_15 ;
V_44 -> V_83 = F_9 ;
V_44 -> V_58 . V_61 = V_60 ;
V_44 -> V_84 = V_2 -> V_36 / 128 ;
V_44 -> V_85 = V_2 -> V_36 / 4 ;
error = F_29 ( V_58 , V_44 ) ;
if ( error )
goto V_86;
return 0 ;
V_86:
F_30 ( V_44 ) ;
return error ;
}
