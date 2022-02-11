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
F_7 ( V_1 ) ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_3 -> V_17 ;
}
static void F_8 ( struct V_2 * V_3 )
{
int V_18 = V_3 -> V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_1 ;
T_2 V_21 ;
T_3 V_22 ;
int V_23 , V_24 = 0 , V_25 ;
if ( ! V_3 -> V_18 ) {
F_2 ( V_3 , 0 ) ;
return;
}
if ( V_3 -> V_9 -> V_10 . V_26 == V_27 ) {
V_23 = V_28 ;
if ( V_3 -> V_9 -> V_10 . V_29 & F_9 ( V_30 ) )
V_24 |= V_31 ;
} else {
V_23 = V_32 ;
}
V_21 = F_10 ( V_3 -> V_9 -> V_10 . V_33 ) ;
V_21 <<= ( V_3 -> V_12 -> V_13 - 9 ) ;
F_6 ( V_3 ) ;
V_1 = & V_3 -> V_8 ;
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_36 . V_37 = V_21 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
F_11 ( V_1 , V_23 , V_24 ) ;
F_12 (req->sg, sg, req->sg_cnt, i) {
while ( F_13 ( V_1 , F_14 ( V_20 ) , V_20 -> V_11 , V_20 -> V_39 )
!= V_20 -> V_11 ) {
struct V_1 * V_40 = V_1 ;
V_1 = F_15 ( V_41 , F_16 ( V_18 , V_42 ) ) ;
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_36 . V_37 = V_21 ;
F_11 ( V_1 , V_23 , V_24 ) ;
F_17 ( V_1 , V_40 ) ;
V_22 = F_18 ( V_40 ) ;
}
V_21 += V_20 -> V_11 >> 9 ;
V_18 -- ;
}
V_22 = F_18 ( V_1 ) ;
F_19 ( F_20 ( V_3 -> V_12 -> V_35 ) , V_22 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
F_6 ( V_3 ) ;
V_1 = & V_3 -> V_8 ;
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
F_11 ( V_1 , V_28 , V_43 ) ;
F_18 ( V_1 ) ;
}
static T_4 F_22 ( struct V_44 * V_12 ,
struct V_45 * V_46 , struct V_1 * * V_1 )
{
if ( F_23 ( V_12 -> V_35 ,
F_10 ( V_46 -> V_33 ) << ( V_12 -> V_13 - 9 ) ,
F_24 ( V_46 -> V_47 ) << ( V_12 -> V_13 - 9 ) ,
V_41 , 0 , V_1 ) )
return V_6 | V_7 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_45 V_46 ;
struct V_1 * V_1 = NULL ;
int V_25 ;
T_4 V_48 ;
for ( V_25 = 0 ; V_25 <= F_24 ( V_3 -> V_9 -> V_49 . V_50 ) ; V_25 ++ ) {
V_48 = F_26 ( V_3 , V_25 * sizeof( V_46 ) , & V_46 ,
sizeof( V_46 ) ) ;
if ( V_48 )
break;
V_48 = F_22 ( V_3 -> V_12 , & V_46 , & V_1 ) ;
if ( V_48 )
break;
}
if ( V_1 ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
if ( V_48 ) {
V_1 -> V_5 = - V_51 ;
F_27 ( V_1 ) ;
} else {
F_18 ( V_1 ) ;
}
} else {
F_2 ( V_3 , V_48 ) ;
}
}
static void F_28 ( struct V_2 * V_3 )
{
switch ( F_24 ( V_3 -> V_9 -> V_49 . V_52 ) ) {
case V_53 :
F_25 ( V_3 ) ;
return;
case V_54 :
case V_55 :
default:
F_2 ( V_3 , 0 ) ;
return;
}
}
int F_29 ( struct V_2 * V_3 )
{
struct V_56 * V_9 = V_3 -> V_9 ;
if ( F_30 ( ! ( V_3 -> V_57 -> V_58 -> V_59 & V_60 ) ) ) {
F_31 ( L_1 ,
V_9 -> V_61 . V_26 ) ;
V_3 -> V_12 = NULL ;
return V_62 | V_7 ;
}
if ( F_30 ( ! ( V_3 -> V_57 -> V_58 -> V_63 & V_64 ) ) ) {
F_31 ( L_2 ,
V_9 -> V_61 . V_26 ) ;
V_3 -> V_12 = NULL ;
return V_62 | V_7 ;
}
V_3 -> V_12 = F_32 ( V_3 -> V_57 -> V_58 , V_9 -> V_10 . V_65 ) ;
if ( ! V_3 -> V_12 )
return V_66 | V_7 ;
switch ( V_9 -> V_61 . V_26 ) {
case V_67 :
case V_27 :
V_3 -> V_68 = F_8 ;
V_3 -> V_69 = F_4 ( V_3 ) ;
return 0 ;
case V_70 :
V_3 -> V_68 = F_21 ;
V_3 -> V_69 = 0 ;
return 0 ;
case V_71 :
V_3 -> V_68 = F_28 ;
V_3 -> V_69 = F_24 ( V_9 -> V_49 . V_50 ) *
sizeof( struct V_45 ) ;
return 0 ;
default:
F_31 ( L_3 , V_9 -> V_61 . V_26 ) ;
return V_72 | V_7 ;
}
}
