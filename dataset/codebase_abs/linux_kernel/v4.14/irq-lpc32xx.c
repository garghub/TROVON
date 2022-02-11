static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_5 , V_8 = F_7 ( V_7 -> V_9 ) ;
V_5 = F_1 ( V_2 , V_10 ) & ~ V_8 ;
F_3 ( V_2 , V_10 , V_5 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_5 , V_8 = F_7 ( V_7 -> V_9 ) ;
V_5 = F_1 ( V_2 , V_10 ) | V_8 ;
F_3 ( V_2 , V_10 , V_5 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_8 = F_7 ( V_7 -> V_9 ) ;
F_3 ( V_2 , V_11 , V_8 ) ;
}
static int F_10 ( struct V_6 * V_7 , unsigned int type )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_5 , V_8 = F_7 ( V_7 -> V_9 ) ;
bool V_12 , V_13 ;
switch ( type ) {
case V_14 :
V_13 = true ;
V_12 = true ;
break;
case V_15 :
V_13 = true ;
V_12 = false ;
break;
case V_16 :
V_13 = false ;
V_12 = true ;
break;
case V_17 :
V_13 = false ;
V_12 = false ;
break;
default:
F_11 ( L_1 , type ) ;
return - V_18 ;
}
F_12 ( V_7 , type ) ;
V_5 = F_1 ( V_2 , V_19 ) ;
if ( V_12 )
V_5 |= V_8 ;
else
V_5 &= ~ V_8 ;
F_3 ( V_2 , V_19 , V_5 ) ;
V_5 = F_1 ( V_2 , V_20 ) ;
if ( V_13 ) {
V_5 |= V_8 ;
F_13 ( V_7 , V_21 ) ;
} else {
V_5 &= ~ V_8 ;
F_13 ( V_7 , V_22 ) ;
}
F_3 ( V_2 , V_20 , V_5 ) ;
return 0 ;
}
static void T_2 F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_25 ;
T_1 V_9 = F_1 ( V_2 , V_26 ) , V_27 ;
while ( V_9 ) {
V_27 = F_15 ( V_9 ) ;
V_9 &= ~ F_7 ( V_27 ) ;
F_16 ( V_25 -> V_28 , V_27 , V_24 ) ;
}
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_18 ( V_30 ) ;
struct V_31 * V_32 = F_19 ( V_30 ) ;
T_1 V_9 = F_1 ( V_2 , V_26 ) , V_27 ;
F_20 ( V_32 , V_30 ) ;
while ( V_9 ) {
V_27 = F_15 ( V_9 ) ;
V_9 &= ~ F_7 ( V_27 ) ;
F_21 ( F_22 ( V_2 -> V_28 , V_27 ) ) ;
}
F_23 ( V_32 , V_30 ) ;
}
static int F_24 ( struct V_33 * V_34 , unsigned int V_35 ,
T_3 V_36 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
F_25 ( V_35 , V_2 ) ;
F_26 ( V_35 , & V_2 -> V_32 , V_22 ) ;
F_27 ( V_35 , V_38 ) ;
F_28 ( V_35 ) ;
return 0 ;
}
static void F_29 ( struct V_33 * V_34 , unsigned int V_35 )
{
F_26 ( V_35 , NULL , NULL ) ;
}
static int T_4 F_30 ( struct V_39 * V_40 ,
struct V_39 * V_41 )
{
struct V_1 * V_42 ;
bool V_43 = F_31 ( V_40 , L_2 ) ;
const T_5 * V_3 = F_32 ( V_40 , L_3 , NULL ) ;
T_1 V_44 , V_45 , V_46 = V_3 ? F_33 ( * V_3 ) : 0 ;
V_42 = F_34 ( sizeof( * V_42 ) , V_47 ) ;
if ( ! V_42 )
return - V_48 ;
V_42 -> V_4 = F_35 ( V_40 , 0 ) ;
if ( ! V_42 -> V_4 ) {
F_36 ( L_4 , V_40 ) ;
F_37 ( V_42 ) ;
return - V_18 ;
}
V_42 -> V_32 . V_49 = F_9 ;
V_42 -> V_32 . V_50 = F_5 ;
V_42 -> V_32 . V_51 = F_8 ;
V_42 -> V_32 . V_52 = F_10 ;
if ( V_43 )
V_42 -> V_32 . V_53 = F_38 ( V_47 , L_5 , V_46 ) ;
else
V_42 -> V_32 . V_53 = F_38 ( V_47 , L_6 , V_46 ) ;
V_42 -> V_28 = F_39 ( V_40 , V_54 ,
& V_55 , V_42 ) ;
if ( ! V_42 -> V_28 ) {
F_36 ( L_7 ) ;
F_40 ( V_42 -> V_4 ) ;
F_37 ( V_42 -> V_32 . V_53 ) ;
F_37 ( V_42 ) ;
return - V_56 ;
}
if ( V_43 ) {
V_25 = V_42 ;
F_41 ( F_14 ) ;
} else {
for ( V_45 = 0 ; V_45 < F_42 ( V_40 ) ; V_45 ++ ) {
V_44 = F_43 ( V_40 , V_45 ) ;
if ( V_44 )
F_44 ( V_44 ,
F_17 , V_42 ) ;
}
}
F_3 ( V_42 , V_10 , 0x00 ) ;
F_3 ( V_42 , V_19 , 0x00 ) ;
F_3 ( V_42 , V_20 , 0x00 ) ;
return 0 ;
}
