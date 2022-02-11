static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
F_3 ( & V_8 -> V_11 ) ;
V_8 -> V_12 -- ;
if ( V_8 -> V_12 < 0 ) {
F_4 ( V_10 , L_1 ) ;
V_8 -> V_12 = 0 ;
}
if ( ! V_8 -> V_12 )
V_8 -> V_13 = V_14 ;
F_5 ( & V_8 -> V_11 ) ;
}
static int F_6 ( struct V_3 * V_4 , unsigned int V_15 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_15 &= V_16 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
case V_19 :
V_8 -> V_15 = V_15 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
const struct V_23 * V_24 ;
struct V_9 * V_10 = V_6 -> V_10 ;
unsigned int V_25 = F_8 ( V_22 ) ;
unsigned int V_15 = V_8 -> V_15 ;
unsigned int V_26 ;
int V_27 = V_2 -> V_28 == V_29 ;
int V_30 , V_31 ;
T_1 V_13 , V_32 ;
V_26 = F_9 ( V_22 ) ;
switch ( V_26 ) {
case 32000 :
case 44100 :
case 48000 :
V_32 = V_33 ;
break;
case 88200 :
case 96000 :
V_32 = V_34 ;
break;
case 176400 :
case 192000 :
V_32 = V_35 ;
break;
default:
return - V_20 ;
}
V_13 = V_14 ;
for ( V_30 = 0 ; V_30 < F_10 ( V_36 ) ; V_30 ++ ) {
V_24 = ( V_27 ) ? & V_36 [ V_30 ] . V_37 :
& V_36 [ V_30 ] . V_38 ;
if ( V_24 -> V_15 != V_15 )
continue;
if ( V_15 == V_17 ) {
if ( V_24 -> V_25 != V_25 )
continue;
} else {
if ( V_24 -> V_25 < V_25 )
continue;
}
V_13 = F_11 ( V_30 ) ;
break;
}
V_31 = - V_20 ;
if ( V_13 == V_14 )
goto V_39;
F_3 ( & V_8 -> V_11 ) ;
if ( ( V_8 -> V_13 == V_14 ) ||
( V_8 -> V_13 == V_13 ) ) {
V_8 -> V_13 = V_13 ;
V_8 -> V_12 ++ ;
V_31 = 0 ;
}
F_5 ( & V_8 -> V_11 ) ;
if ( V_31 < 0 )
goto V_39;
F_12 ( V_6 , V_40 , V_41 , V_13 ) ;
F_13 ( V_6 , V_42 , V_32 ) ;
V_39:
if ( V_31 < 0 )
F_14 ( V_10 , L_2 ) ;
return V_31 ;
}
static int F_15 ( struct V_5 * V_6 ,
enum V_43 V_44 )
{
T_1 V_45 = 0 ;
switch ( V_44 ) {
case V_46 :
V_45 |= V_47 ;
case V_48 :
V_45 |= V_49 | V_50 ;
case V_51 :
V_45 |= V_52 ;
case V_53 :
default:
break;
}
F_13 ( V_6 , V_54 , V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_55 * V_55 = F_17 ( V_6 -> V_10 , NULL ) ;
F_18 ( V_55 ) ;
return F_19 ( V_55 ) ;
}
static int F_20 ( struct V_56 * V_57 ,
const struct V_58 * V_59 )
{
struct V_9 * V_10 = & V_57 -> V_10 ;
struct V_60 * V_61 = V_10 -> V_62 ;
const struct V_63 * V_64 ;
struct V_55 * V_55 ;
struct V_7 * V_8 ;
V_64 = NULL ;
if ( V_61 ) {
const struct V_65 * V_66 ;
V_66 = F_21 ( V_67 , V_10 ) ;
if ( V_66 )
V_64 = V_66 -> V_68 ;
} else {
V_64 = ( const struct V_63 * ) V_59 -> V_69 ;
}
if ( ! V_64 )
return - V_20 ;
V_8 = F_22 ( V_10 , sizeof( * V_8 ) , V_70 ) ;
if ( ! V_8 )
return - V_71 ;
V_8 -> V_13 = V_14 ;
V_8 -> V_12 = 0 ;
F_23 ( & V_8 -> V_11 ) ;
F_24 ( V_57 , V_8 ) ;
V_55 = F_25 ( V_57 , V_64 ) ;
if ( F_26 ( V_55 ) )
return F_27 ( V_55 ) ;
return F_28 ( V_10 , & V_72 ,
& V_73 , 1 ) ;
}
static int F_29 ( struct V_56 * V_74 )
{
F_30 ( & V_74 -> V_10 ) ;
return 0 ;
}
