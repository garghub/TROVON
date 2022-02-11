static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
F_2 ( V_3 ,
V_1 -> V_5 ? V_6 | V_7 : 0 ) ;
if ( V_1 != & V_3 -> V_8 )
F_3 ( V_1 ) ;
}
static inline T_1 F_4 ( struct V_2 * V_3 )
{
return ( ( T_1 ) F_5 ( V_3 -> V_9 -> V_10 . V_11 ) + 1 ) <<
V_3 -> V_12 -> V_13 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = & V_3 -> V_8 ;
F_7 ( V_1 , V_3 -> V_14 , V_15 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
int V_16 = V_3 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_1 ;
T_2 V_19 ;
T_3 V_20 ;
int V_21 , V_22 = 0 , V_23 ;
if ( ! V_3 -> V_16 ) {
F_2 ( V_3 , 0 ) ;
return;
}
if ( V_3 -> V_9 -> V_10 . V_24 == V_25 ) {
V_21 = V_26 ;
V_22 = V_27 | V_28 ;
if ( V_3 -> V_9 -> V_10 . V_29 & F_9 ( V_30 ) )
V_22 |= V_31 ;
} else {
V_21 = V_32 ;
}
V_19 = F_10 ( V_3 -> V_9 -> V_10 . V_33 ) ;
V_19 <<= ( V_3 -> V_12 -> V_13 - 9 ) ;
F_6 ( V_3 ) ;
V_1 = & V_3 -> V_8 ;
F_11 ( V_1 , V_3 -> V_12 -> V_34 ) ;
V_1 -> V_35 . V_36 = V_19 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_37 = F_1 ;
F_12 ( V_1 , V_21 , V_22 ) ;
F_13 (req->sg, sg, req->sg_cnt, i) {
while ( F_14 ( V_1 , F_15 ( V_18 ) , V_18 -> V_11 , V_18 -> V_38 )
!= V_18 -> V_11 ) {
struct V_1 * V_39 = V_1 ;
V_1 = F_16 ( V_40 , F_17 ( V_16 , V_41 ) ) ;
F_11 ( V_1 , V_3 -> V_12 -> V_34 ) ;
V_1 -> V_35 . V_36 = V_19 ;
F_12 ( V_1 , V_21 , V_22 ) ;
F_18 ( V_1 , V_39 ) ;
F_19 ( V_39 ) ;
}
V_19 += V_18 -> V_11 >> 9 ;
V_16 -- ;
}
V_20 = F_19 ( V_1 ) ;
F_20 ( F_21 ( V_3 -> V_12 -> V_34 ) , V_20 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
F_6 ( V_3 ) ;
V_1 = & V_3 -> V_8 ;
F_11 ( V_1 , V_3 -> V_12 -> V_34 ) ;
V_1 -> V_4 = V_3 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_42 = V_26 | V_43 ;
F_19 ( V_1 ) ;
}
static T_4 F_23 ( struct V_44 * V_12 ,
struct V_45 * V_46 , struct V_1 * * V_1 )
{
if ( F_24 ( V_12 -> V_34 ,
F_10 ( V_46 -> V_33 ) << ( V_12 -> V_13 - 9 ) ,
F_25 ( V_46 -> V_47 ) << ( V_12 -> V_13 - 9 ) ,
V_40 , 0 , V_1 ) )
return V_6 | V_7 ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_45 V_46 ;
struct V_1 * V_1 = NULL ;
int V_23 ;
T_4 V_48 ;
for ( V_23 = 0 ; V_23 <= F_25 ( V_3 -> V_9 -> V_49 . V_50 ) ; V_23 ++ ) {
V_48 = F_27 ( V_3 , V_23 * sizeof( V_46 ) , & V_46 ,
sizeof( V_46 ) ) ;
if ( V_48 )
break;
V_48 = F_23 ( V_3 -> V_12 , & V_46 , & V_1 ) ;
if ( V_48 )
break;
}
if ( V_1 ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_37 = F_1 ;
if ( V_48 ) {
V_1 -> V_5 = V_51 ;
F_28 ( V_1 ) ;
} else {
F_19 ( V_1 ) ;
}
} else {
F_2 ( V_3 , V_48 ) ;
}
}
static void F_29 ( struct V_2 * V_3 )
{
switch ( F_25 ( V_3 -> V_9 -> V_49 . V_52 ) ) {
case V_53 :
F_26 ( V_3 ) ;
return;
case V_54 :
case V_55 :
default:
F_2 ( V_3 , 0 ) ;
return;
}
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_56 * V_57 = & V_3 -> V_9 -> V_57 ;
struct V_1 * V_1 = NULL ;
T_4 V_48 = V_58 ;
T_2 V_19 ;
T_2 V_59 ;
V_19 = F_10 ( V_57 -> V_33 ) <<
( V_3 -> V_12 -> V_13 - 9 ) ;
V_59 = ( ( ( T_2 ) F_5 ( V_57 -> V_11 ) ) <<
( V_3 -> V_12 -> V_13 - 9 ) ) + 1 ;
if ( F_31 ( V_3 -> V_12 -> V_34 , V_19 , V_59 ,
V_40 , & V_1 , 0 ) )
V_48 = V_6 | V_7 ;
if ( V_1 ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_37 = F_1 ;
F_19 ( V_1 ) ;
} else {
F_2 ( V_3 , V_48 ) ;
}
}
T_4 F_32 ( struct V_2 * V_3 )
{
struct V_60 * V_9 = V_3 -> V_9 ;
T_4 V_61 ;
V_61 = F_33 ( V_3 , V_9 ) ;
if ( F_34 ( V_61 ) ) {
V_3 -> V_12 = NULL ;
return V_61 ;
}
V_3 -> V_12 = F_35 ( V_3 -> V_62 -> V_63 , V_9 -> V_10 . V_64 ) ;
if ( F_34 ( ! V_3 -> V_12 ) )
return V_65 | V_7 ;
switch ( V_9 -> V_66 . V_24 ) {
case V_67 :
case V_25 :
V_3 -> V_68 = F_8 ;
V_3 -> V_69 = F_4 ( V_3 ) ;
return 0 ;
case V_70 :
V_3 -> V_68 = F_22 ;
V_3 -> V_69 = 0 ;
return 0 ;
case V_71 :
V_3 -> V_68 = F_29 ;
V_3 -> V_69 = ( F_25 ( V_9 -> V_49 . V_50 ) + 1 ) *
sizeof( struct V_45 ) ;
return 0 ;
case V_72 :
V_3 -> V_68 = F_30 ;
return 0 ;
default:
F_36 ( L_1 , V_9 -> V_66 . V_24 ,
V_3 -> V_62 -> V_73 ) ;
return V_74 | V_7 ;
}
}
