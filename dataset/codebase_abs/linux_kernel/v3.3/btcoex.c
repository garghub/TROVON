void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
const struct V_6 V_7 = {
. V_8 = 0 ,
. V_9 = true ,
. V_10 = true ,
. V_11 = V_12 ,
. V_13 = true ,
. V_14 = true ,
. V_15 = 2 ,
. V_16 = 5 ,
. V_17 = true ,
} ;
T_1 V_18 , V_19 ;
bool V_20 = V_7 . V_14 ;
if ( F_2 ( V_2 ) == V_21 )
return;
if ( F_3 ( V_2 ) )
V_20 = ! V_7 . V_14 ;
V_5 -> V_22 =
( V_5 -> V_22 & V_23 ) |
F_4 ( V_7 . V_8 , V_24 ) |
F_4 ( V_7 . V_9 , V_25 ) |
F_4 ( V_7 . V_10 , V_26 ) |
F_4 ( V_7 . V_11 , V_27 ) |
F_4 ( V_7 . V_13 , V_28 ) |
F_4 ( V_20 , V_29 ) |
F_4 ( V_7 . V_15 , V_30 ) |
F_4 ( V_7 . V_16 , V_31 ) |
F_4 ( V_3 , V_23 ) ;
V_5 -> V_32 =
F_4 ( V_7 . V_17 , V_33 ) |
F_4 ( V_34 , V_35 ) |
V_36 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ ) {
V_19 = ( V_37 << V_18 ) >> 27 ;
V_2 -> V_38 . V_39 [ V_19 ] = V_18 ;
}
}
void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( F_2 ( V_2 ) == V_21 )
return;
F_6 ( V_2 , V_40 ,
( V_41 |
V_42 ) ) ;
F_7 ( V_2 , V_40 ,
V_43 ) ;
F_8 ( V_2 , V_44 ,
V_45 ,
V_5 -> V_46 ) ;
F_9 ( V_2 , V_5 -> V_46 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( F_2 ( V_2 ) == V_21 )
return;
F_7 ( V_2 , V_40 ,
( V_47 |
V_43 ) ) ;
F_8 ( V_2 , V_44 ,
V_45 ,
V_5 -> V_46 ) ;
F_8 ( V_2 , V_44 ,
V_48 ,
V_5 -> V_49 ) ;
F_9 ( V_2 , V_5 -> V_46 ) ;
F_9 ( V_2 , V_5 -> V_49 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( F_2 ( V_2 ) == V_21 )
return;
F_12 ( V_2 , V_5 -> V_50 ,
V_51 ) ;
}
void F_13 ( struct V_1 * V_2 ,
T_1 V_52 ,
T_1 V_53 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( F_2 ( V_2 ) == V_21 )
return;
V_5 -> V_54 = F_4 ( V_52 , V_55 ) |
F_4 ( V_53 , V_56 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_57 = & V_2 -> V_5 ;
T_1 V_58 ;
int V_18 ;
F_15 ( V_2 , V_59 , V_57 -> V_22 ) ;
F_15 ( V_2 , V_60 , V_57 -> V_32 ) ;
if ( F_3 ( V_2 ) ) {
F_15 ( V_2 , V_61 , V_57 -> V_53 [ 0 ] ) ;
F_15 ( V_2 , V_62 , V_57 -> V_53 [ 1 ] ) ;
for ( V_18 = 0 ; V_18 < V_63 ; V_18 ++ )
F_15 ( V_2 , F_16 ( V_18 ) ,
V_57 -> V_52 [ V_18 ] ) ;
} else
F_15 ( V_2 , V_64 , V_57 -> V_54 ) ;
if ( F_17 ( V_2 ) ) {
V_58 = F_18 ( V_2 , 0x50040 ) ;
V_58 &= 0xFFFFFEFF ;
F_15 ( V_2 , 0x50040 , V_58 ) ;
}
F_8 ( V_2 , V_65 , V_66 , 1 ) ;
F_8 ( V_2 , V_67 , V_68 , 0 ) ;
F_12 ( V_2 , V_57 -> V_50 ,
V_69 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_57 = & V_2 -> V_5 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_63 ; V_18 ++ )
F_15 ( V_2 , F_20 ( V_18 ) ,
V_57 -> V_53 [ V_18 ] ) ;
F_8 ( V_2 , V_65 , V_66 , 1 ) ;
V_57 -> V_70 = true ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( F_2 ( V_2 ) ) {
case V_21 :
return;
case V_71 :
F_11 ( V_2 ) ;
break;
case V_72 :
F_14 ( V_2 ) ;
break;
case V_73 :
F_19 ( V_2 ) ;
return;
}
F_22 ( V_2 , V_74 ,
( 0x2 << ( V_5 -> V_46 * 2 ) ) ,
( 0x3 << ( V_5 -> V_46 * 2 ) ) ) ;
V_2 -> V_5 . V_70 = true ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_18 ;
if ( F_2 ( V_2 ) == V_21 )
return;
V_5 -> V_70 = false ;
if ( V_5 -> V_75 == V_73 ) {
F_24 ( V_2 , V_76 ) ;
for ( V_18 = 0 ; V_18 < V_63 ; V_18 ++ )
F_15 ( V_2 , F_20 ( V_18 ) ,
V_5 -> V_53 [ V_18 ] ) ;
}
F_25 ( V_2 , V_5 -> V_50 , 0 ) ;
F_12 ( V_2 , V_5 -> V_50 ,
V_77 ) ;
if ( V_5 -> V_75 == V_72 ) {
F_15 ( V_2 , V_59 , V_28 | V_27 ) ;
F_15 ( V_2 , V_60 , 0 ) ;
if ( F_3 ( V_2 ) ) {
F_15 ( V_2 , V_61 , 0 ) ;
F_15 ( V_2 , V_62 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_63 ; V_18 ++ )
F_15 ( V_2 , F_16 ( V_18 ) , 0 ) ;
} else
F_15 ( V_2 , V_64 , 0 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
struct V_4 * V_57 = & V_2 -> V_5 ;
const T_1 * V_80 = F_27 ( V_2 ) ? V_81 [ V_79 ] :
V_82 [ V_79 ] ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ ) {
V_57 -> V_52 [ V_18 ] = V_84 ;
V_57 -> V_53 [ V_18 ] = V_80 [ V_18 ] ;
}
}
void F_24 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
if ( F_2 ( V_2 ) == V_21 )
return;
if ( F_3 ( V_2 ) ) {
F_26 ( V_2 , V_79 ) ;
return;
}
switch ( V_79 ) {
case V_85 :
F_13 ( V_2 , V_86 ,
V_87 ) ;
break;
case V_88 :
F_13 ( V_2 , V_86 ,
V_89 ) ;
break;
case V_76 :
F_13 ( V_2 , V_86 ,
V_90 ) ;
break;
default:
F_28 ( F_29 ( V_2 ) , V_91 , L_1 ) ;
break;
}
}
