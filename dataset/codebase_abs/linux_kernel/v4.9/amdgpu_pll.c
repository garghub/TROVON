static void F_1 ( unsigned * V_1 , unsigned * V_2 ,
unsigned V_3 , unsigned V_4 )
{
unsigned V_5 ;
V_5 = F_2 ( * V_1 , * V_2 ) ;
* V_1 /= V_5 ;
* V_2 /= V_5 ;
if ( * V_1 < V_3 ) {
V_5 = F_3 ( V_3 , * V_1 ) ;
* V_1 *= V_5 ;
* V_2 *= V_5 ;
}
if ( * V_2 < V_4 ) {
V_5 = F_3 ( V_4 , * V_2 ) ;
* V_1 *= V_5 ;
* V_2 *= V_5 ;
}
}
static void F_4 ( unsigned V_1 , unsigned V_2 , unsigned V_6 ,
unsigned V_7 , unsigned V_8 ,
unsigned * V_9 , unsigned * V_10 )
{
V_8 = F_5 ( 128 / V_6 , V_8 ) ;
* V_10 = F_5 ( F_6 ( F_7 ( V_2 , V_6 ) , 1u ) , V_8 ) ;
* V_9 = F_7 ( V_1 * * V_10 * V_6 , V_2 ) ;
if ( * V_9 > V_7 ) {
* V_10 = F_7 ( * V_10 * V_7 , * V_9 ) ;
* V_9 = V_7 ;
}
}
void F_8 ( struct V_11 * V_12 ,
T_1 V_13 ,
T_1 * V_14 ,
T_1 * V_15 ,
T_1 * V_16 ,
T_1 * V_17 ,
T_1 * V_18 )
{
unsigned V_19 = V_12 -> V_20 & V_21 ?
V_13 : V_13 / 10 ;
unsigned V_22 , V_7 , V_9 ;
unsigned V_23 , V_24 , V_6 ;
unsigned V_25 , V_8 , V_10 ;
unsigned V_26 , V_27 ;
unsigned V_1 , V_2 ;
V_22 = V_12 -> V_28 ;
V_7 = V_12 -> V_29 ;
if ( V_12 -> V_20 & V_21 ) {
V_22 *= 10 ;
V_7 *= 10 ;
}
if ( V_12 -> V_20 & V_30 )
V_25 = V_12 -> V_31 ;
else
V_25 = V_12 -> V_32 ;
if ( V_12 -> V_20 & V_21 &&
V_12 -> V_20 & V_30 )
V_8 = V_12 -> V_31 ;
else
V_8 = V_12 -> V_33 ;
if ( V_12 -> V_20 & V_34 ) {
V_23 = V_12 -> V_6 ;
V_24 = V_12 -> V_6 ;
} else {
unsigned V_35 , V_36 ;
if ( V_12 -> V_20 & V_37 ) {
V_35 = V_12 -> V_38 ;
V_36 = V_12 -> V_39 ;
} else {
V_35 = V_12 -> V_40 ;
V_36 = V_12 -> V_41 ;
}
if ( V_12 -> V_20 & V_21 ) {
V_35 *= 10 ;
V_36 *= 10 ;
}
V_23 = V_35 / V_19 ;
if ( ( V_19 * V_23 ) < V_35 )
++ V_23 ;
if ( V_23 < V_12 -> V_42 )
V_23 = V_12 -> V_42 ;
V_24 = V_36 / V_19 ;
if ( ( V_19 * V_24 ) > V_36 )
-- V_24 ;
if ( V_24 > V_12 -> V_43 )
V_24 = V_12 -> V_43 ;
}
V_1 = V_19 ;
V_2 = V_12 -> V_44 ;
F_1 ( & V_1 , & V_2 , V_22 , V_23 ) ;
if ( V_12 -> V_20 & V_45 )
V_26 = V_23 ;
else
V_26 = V_24 ;
V_27 = ~ 0 ;
for ( V_6 = V_23 ; V_6 <= V_24 ; ++ V_6 ) {
unsigned V_46 ;
F_4 ( V_1 , V_2 , V_6 , V_7 ,
V_8 , & V_9 , & V_10 ) ;
V_46 = abs ( V_19 - ( V_12 -> V_44 * V_9 ) /
( V_10 * V_6 ) ) ;
if ( V_46 < V_27 || ( V_46 == V_27 &&
! ( V_12 -> V_20 & V_45 ) ) ) {
V_26 = V_6 ;
V_27 = V_46 ;
}
}
V_6 = V_26 ;
F_4 ( V_1 , V_2 , V_6 , V_7 , V_8 ,
& V_9 , & V_10 ) ;
F_1 ( & V_9 , & V_10 , V_22 , V_25 ) ;
if ( V_12 -> V_20 & V_21 && ( V_9 % 10 ) ) {
V_22 = F_6 ( V_22 , ( 9 - ( V_9 % 10 ) ) * 20 + 60 ) ;
if ( V_9 < V_22 ) {
unsigned V_5 = F_3 ( V_22 , V_9 ) ;
V_9 *= V_5 ;
V_10 *= V_5 ;
}
}
if ( V_12 -> V_20 & V_21 ) {
* V_15 = V_9 / 10 ;
* V_16 = V_9 % 10 ;
} else {
* V_15 = V_9 ;
* V_16 = 0 ;
}
* V_14 = ( ( V_12 -> V_44 * * V_15 * 10 ) +
( V_12 -> V_44 * * V_16 ) ) /
( V_10 * V_6 * 10 ) ;
* V_17 = V_10 ;
* V_18 = V_6 ;
F_9 ( L_1 ,
V_13 , * V_14 * 10 , * V_15 , * V_16 ,
V_10 , V_6 ) ;
}
T_1 F_10 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
struct V_47 * V_51 ;
struct V_52 * V_53 ;
T_1 V_54 = 0 ;
F_11 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_48 == V_51 )
continue;
V_53 = F_12 ( V_51 ) ;
if ( V_53 -> V_55 != V_56 )
V_54 |= ( 1 << V_53 -> V_55 ) ;
}
return V_54 ;
}
int F_13 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
struct V_47 * V_51 ;
struct V_52 * V_53 ;
F_11 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_48 == V_51 )
continue;
V_53 = F_12 ( V_51 ) ;
if ( V_53 -> V_57 &&
F_14 ( F_15 ( V_53 -> V_57 ) ) ) {
if ( V_53 -> V_55 != V_56 )
return V_53 -> V_55 ;
}
}
return V_56 ;
}
int F_16 ( struct V_47 * V_48 )
{
struct V_52 * V_52 = F_12 ( V_48 ) ;
struct V_49 * V_50 = V_48 -> V_50 ;
struct V_47 * V_51 ;
struct V_52 * V_53 ;
T_1 V_58 , V_59 ;
V_58 = V_52 -> V_58 ;
if ( V_58 == 0 )
return V_56 ;
F_11 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_48 == V_51 )
continue;
V_53 = F_12 ( V_51 ) ;
if ( V_53 -> V_57 &&
! F_14 ( F_15 ( V_53 -> V_57 ) ) ) {
if ( V_53 -> V_60 == V_52 -> V_60 ) {
if ( V_53 -> V_55 != V_56 )
return V_53 -> V_55 ;
}
V_59 = V_53 -> V_58 ;
if ( ( V_48 -> V_61 . clock == V_51 -> V_61 . clock ) &&
( V_58 == V_59 ) &&
( V_52 -> V_62 == V_53 -> V_62 ) &&
( V_53 -> V_55 != V_56 ) )
return V_53 -> V_55 ;
}
}
return V_56 ;
}
