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
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_36 . V_37 = V_19 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
F_11 ( V_1 , V_21 , V_22 ) ;
F_12 (req->sg, sg, req->sg_cnt, i) {
while ( F_13 ( V_1 , F_14 ( V_18 ) , V_18 -> V_11 , V_18 -> V_39 )
!= V_18 -> V_11 ) {
struct V_1 * V_40 = V_1 ;
V_1 = F_15 ( V_41 , F_16 ( V_16 , V_42 ) ) ;
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_36 . V_37 = V_19 ;
F_11 ( V_1 , V_21 , V_22 ) ;
F_17 ( V_1 , V_40 ) ;
V_20 = F_18 ( V_40 ) ;
}
V_19 += V_18 -> V_11 >> 9 ;
V_16 -- ;
}
V_20 = F_18 ( V_1 ) ;
F_19 ( F_20 ( V_3 -> V_12 -> V_35 ) , V_20 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
F_6 ( V_3 ) ;
V_1 = & V_3 -> V_8 ;
V_1 -> V_34 = V_3 -> V_12 -> V_35 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
V_1 -> V_43 = V_26 | V_44 ;
F_18 ( V_1 ) ;
}
static T_4 F_22 ( struct V_45 * V_12 ,
struct V_46 * V_47 , struct V_1 * * V_1 )
{
if ( F_23 ( V_12 -> V_35 ,
F_10 ( V_47 -> V_33 ) << ( V_12 -> V_13 - 9 ) ,
F_24 ( V_47 -> V_48 ) << ( V_12 -> V_13 - 9 ) ,
V_41 , 0 , V_1 ) )
return V_6 | V_7 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_46 V_47 ;
struct V_1 * V_1 = NULL ;
int V_23 ;
T_4 V_49 ;
for ( V_23 = 0 ; V_23 <= F_24 ( V_3 -> V_9 -> V_50 . V_51 ) ; V_23 ++ ) {
V_49 = F_26 ( V_3 , V_23 * sizeof( V_47 ) , & V_47 ,
sizeof( V_47 ) ) ;
if ( V_49 )
break;
V_49 = F_22 ( V_3 -> V_12 , & V_47 , & V_1 ) ;
if ( V_49 )
break;
}
if ( V_1 ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
if ( V_49 ) {
V_1 -> V_5 = - V_52 ;
F_27 ( V_1 ) ;
} else {
F_18 ( V_1 ) ;
}
} else {
F_2 ( V_3 , V_49 ) ;
}
}
static void F_28 ( struct V_2 * V_3 )
{
switch ( F_24 ( V_3 -> V_9 -> V_50 . V_53 ) ) {
case V_54 :
F_25 ( V_3 ) ;
return;
case V_55 :
case V_56 :
default:
F_2 ( V_3 , 0 ) ;
return;
}
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = & V_3 -> V_9 -> V_58 ;
struct V_1 * V_1 = NULL ;
T_4 V_49 = V_59 ;
T_2 V_19 ;
T_2 V_60 ;
V_19 = F_10 ( V_58 -> V_33 ) <<
( V_3 -> V_12 -> V_13 - 9 ) ;
V_60 = ( ( ( T_2 ) F_5 ( V_58 -> V_11 ) ) <<
( V_3 -> V_12 -> V_13 - 9 ) ) + 1 ;
if ( F_30 ( V_3 -> V_12 -> V_35 , V_19 , V_60 ,
V_41 , & V_1 , true ) )
V_49 = V_6 | V_7 ;
if ( V_1 ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_38 = F_1 ;
F_18 ( V_1 ) ;
} else {
F_2 ( V_3 , V_49 ) ;
}
}
int F_31 ( struct V_2 * V_3 )
{
struct V_61 * V_9 = V_3 -> V_9 ;
if ( F_32 ( ! ( V_3 -> V_62 -> V_63 -> V_64 & V_65 ) ) ) {
F_33 ( L_1 ,
V_9 -> V_66 . V_24 ) ;
V_3 -> V_12 = NULL ;
return V_67 | V_7 ;
}
if ( F_32 ( ! ( V_3 -> V_62 -> V_63 -> V_68 & V_69 ) ) ) {
F_33 ( L_2 ,
V_9 -> V_66 . V_24 ) ;
V_3 -> V_12 = NULL ;
return V_67 | V_7 ;
}
V_3 -> V_12 = F_34 ( V_3 -> V_62 -> V_63 , V_9 -> V_10 . V_70 ) ;
if ( ! V_3 -> V_12 )
return V_71 | V_7 ;
switch ( V_9 -> V_66 . V_24 ) {
case V_72 :
case V_25 :
V_3 -> V_73 = F_8 ;
V_3 -> V_74 = F_4 ( V_3 ) ;
return 0 ;
case V_75 :
V_3 -> V_73 = F_21 ;
V_3 -> V_74 = 0 ;
return 0 ;
case V_76 :
V_3 -> V_73 = F_28 ;
V_3 -> V_74 = ( F_24 ( V_9 -> V_50 . V_51 ) + 1 ) *
sizeof( struct V_46 ) ;
return 0 ;
case V_77 :
V_3 -> V_73 = F_29 ;
return 0 ;
default:
F_33 ( L_3 , V_9 -> V_66 . V_24 ) ;
return V_78 | V_7 ;
}
}
