static unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned V_4 ;
unsigned V_5 ;
switch ( V_3 >> 28 ) {
case V_6 :
V_4 = V_3 & 0x3f ;
if ( V_4 ) {
F_2 ( V_2 , L_1 ,
V_3 >> 6 & 0x3ff ,
V_3 >> 16 & 0xfff , V_4 ) ;
return F_3 ( V_4 ) ;
} else {
F_2 ( V_2 , L_2 ,
V_3 >> 6 & 0x3ff ) ;
return 0 ;
}
case V_7 :
F_2 ( V_2 , L_3 ,
V_3 >> 16 & 0xfff ) ;
return V_3 & 0xffff ;
case V_8 :
F_2 ( V_2 , L_4 ,
V_3 >> 16 & 0xfff ) ;
return V_3 & 0xffff ;
case V_9 :
V_4 = V_3 & 0xffff ;
F_2 ( V_2 , L_5 ,
V_3 >> 16 & 0xfff , V_4 ) ;
return F_4 ( V_4 ) ;
case V_10 :
F_2 ( V_2 , L_6 ,
V_3 >> 16 & 0xfff , V_3 & 0xffff ) ;
return 0 ;
case V_11 :
F_2 ( V_2 , L_7 , V_3 << 4 ) ;
return 0 ;
case V_12 :
F_2 ( V_2 , L_8 ,
V_3 >> 16 & 0xfff , V_3 >> 15 & 0x1 ,
V_3 >> 14 & 0x1 , V_3 & 0x3fff ) ;
return 1 ;
case V_13 :
V_5 = V_3 >> 24 & 0xf ;
if ( V_5 == V_14 )
F_2 ( V_2 , L_9 ,
V_3 & 0xff ) ;
else if ( V_5 == V_15 )
F_2 ( V_2 , L_10 ,
V_3 & 0xff ) ;
else
F_2 ( V_2 , L_11 , V_3 ) ;
return 0 ;
default:
return 0 ;
}
}
static void F_5 ( struct V_1 * V_2 , T_2 V_16 ,
unsigned int V_17 , struct V_18 * V_19 ,
T_2 V_20 , T_1 * V_21 )
{
T_1 V_22 = V_16 - V_20 ;
unsigned int V_23 = 0 , V_24 ;
if ( V_22 > V_25 ) {
F_2 ( V_2 , L_12 ) ;
return;
}
for ( V_24 = 0 ; V_24 < V_17 ; V_24 ++ ) {
T_1 V_26 = V_16 + V_24 * 4 ;
T_1 V_3 = * ( V_21 + V_22 / 4 + V_24 ) ;
if ( ! V_23 ) {
F_2 ( V_2 , L_13 , V_26 , V_3 ) ;
V_23 = F_1 ( V_2 , V_3 ) ;
} else {
F_2 ( V_2 , L_14 , V_3 ,
V_23 > 0 ? L_15 : L_16 ) ;
V_23 -- ;
}
}
}
static void F_6 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_27 * V_28 ;
F_7 (job, &cdma->sync_queue, list) {
int V_24 ;
F_2 ( V_2 , L_17 ,
V_28 , V_28 -> V_29 , V_28 -> V_30 ,
V_28 -> V_31 , V_28 -> V_32 ,
V_28 -> V_33 , V_28 -> V_34 ) ;
for ( V_24 = 0 ; V_24 < V_28 -> V_35 ; V_24 ++ ) {
struct V_36 * V_37 = & V_28 -> V_38 [ V_24 ] ;
T_1 * V_39 ;
if ( V_28 -> V_40 )
V_39 = ( T_1 * ) V_28 -> V_40 ;
else
V_39 = F_8 ( V_37 -> V_41 ) ;
if ( ! V_39 ) {
F_2 ( V_2 , L_18 ) ;
continue;
}
F_2 ( V_2 , L_19 ,
& V_37 -> V_42 , V_37 -> V_22 , V_37 -> V_17 ) ;
F_5 ( V_2 , V_37 -> V_42 + V_37 -> V_22 , V_37 -> V_17 , V_19 ,
V_37 -> V_42 , V_39 ) ;
if ( ! V_28 -> V_40 )
F_9 ( V_37 -> V_41 , V_39 ) ;
}
}
}
static void F_10 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_46 -> V_19 ;
T_1 V_47 , V_48 , V_49 ;
T_1 V_50 , V_51 ;
T_1 V_3 , V_42 , V_52 ;
V_47 = F_11 ( V_46 , V_53 ) ;
V_48 = F_11 ( V_46 , V_54 ) ;
V_49 = F_11 ( V_46 , V_55 ) ;
V_51 = F_12 ( V_44 , F_13 ( V_46 -> V_56 ) ) ;
V_50 = F_12 ( V_44 , F_14 ( V_46 -> V_56 ) ) ;
F_2 ( V_2 , L_20 , V_46 -> V_56 , F_15 ( V_46 -> V_57 ) ) ;
if ( F_16 ( V_49 ) ||
! V_46 -> V_19 . V_58 . V_39 ) {
F_2 ( V_2 , L_21 ) ;
return;
}
if ( F_17 ( V_50 ) == V_59 &&
F_18 ( V_50 ) ==
V_60 )
F_2 ( V_2 , L_22 ,
V_51 >> 24 , V_51 & 0xffffff ) ;
else if ( F_17 ( V_50 ) ==
V_59 &&
F_18 ( V_50 ) ==
V_61 ) {
V_42 = ( V_51 >> 16 ) & 0xff ;
V_52 =
F_12 ( V_44 , F_19 ( V_42 ) ) ;
V_3 = V_51 & 0xffff ;
F_2 ( V_2 , L_23 ,
V_51 >> 24 , V_52 + V_3 , V_42 ,
V_52 , V_3 ) ;
} else
F_2 ( V_2 , L_24 ,
F_17 ( V_50 ) ,
F_18 ( V_50 ) ,
V_51 ) ;
F_2 ( V_2 , L_25 ,
V_47 , V_48 , V_49 ) ;
F_2 ( V_2 , L_26 , V_51 , V_50 ) ;
F_6 ( V_2 , V_19 ) ;
F_2 ( V_2 , L_27 ) ;
}
static void F_20 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
struct V_1 * V_2 )
{
T_1 V_3 , V_62 , V_63 , V_64 , V_65 ;
unsigned int V_23 = 0 ;
F_2 ( V_2 , L_28 , V_46 -> V_56 ) ;
V_3 = F_11 ( V_46 , V_66 ) ;
F_2 ( V_2 , L_29 , V_3 ) ;
if ( F_21 ( V_3 ) ) {
F_2 ( V_2 , L_30 ) ;
return;
}
F_22 ( V_44 , 0x0 , V_67 ) ;
F_22 ( V_44 , F_23 ( 1 ) |
F_24 ( V_46 -> V_56 ) ,
V_67 ) ;
V_3 = F_12 ( V_44 , V_68 ) ;
V_62 = F_25 ( V_3 ) ;
V_63 = F_26 ( V_3 ) ;
V_3 = F_12 ( V_44 , F_27 ( V_46 -> V_56 ) ) ;
V_64 = F_28 ( V_3 ) ;
V_65 = F_29 ( V_3 ) ;
do {
F_22 ( V_44 , 0x0 , V_67 ) ;
F_22 ( V_44 , F_23 ( 1 ) |
F_24 ( V_46 -> V_56 ) |
F_30 ( V_62 ) ,
V_67 ) ;
V_3 = F_12 ( V_44 , V_69 ) ;
if ( ! V_23 ) {
F_2 ( V_2 , L_31 , V_3 ) ;
V_23 = F_1 ( V_2 , V_3 ) ;
} else {
F_2 ( V_2 , L_14 , V_3 ,
V_23 > 0 ? L_15 : L_16 ) ;
V_23 -- ;
}
if ( V_62 == V_65 )
V_62 = V_64 ;
else
V_62 ++ ;
} while ( V_62 != V_63 );
if ( V_23 )
F_2 ( V_2 , L_32 ) ;
F_2 ( V_2 , L_27 ) ;
F_22 ( V_44 , 0x0 , V_67 ) ;
}
static void F_31 ( struct V_43 * V_44 , struct V_1 * V_2 )
{
int V_24 ;
F_2 ( V_2 , L_33 ) ;
for ( V_24 = 0 ; V_24 < F_32 ( V_44 ) ; V_24 ++ ) {
T_1 V_70 =
F_12 ( V_44 , F_33 ( V_24 ) ) ;
if ( F_34 ( V_70 ) )
F_2 ( V_2 , L_34 ,
V_24 , F_35 ( V_70 ) ) ;
else if ( F_36 ( V_70 ) )
F_2 ( V_2 , L_35 , V_24 ) ;
else
F_2 ( V_2 , L_36 , V_24 ) ;
}
F_2 ( V_2 , L_27 ) ;
}
