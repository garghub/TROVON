static T_1 * F_1 ( T_1 * * V_1 ,
T_1 * V_2 , bool * V_3 , T_2 * V_4 )
{
T_1 * V_5 = NULL ;
T_1 * V_6 = NULL ;
T_2 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
if ( ( V_1 == NULL ) || ( * V_4 == 0 ) ||
( * V_3 ) ) {
* V_3 = TRUE ;
return NULL ;
}
V_5 = * V_1 ;
V_6 = * V_1 ;
if ( ! V_5 || ! V_6 ) {
* V_3 = TRUE ;
return NULL ;
}
* V_3 = false ;
switch ( * V_2 ) {
case V_11 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_1 ) ;
V_7 += sizeof( struct V_15 ) ;
break;
case V_16 :
{
struct V_17 * V_18 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_2 ) ;
V_18 =
(struct V_17 * ) V_6 ;
V_7 += sizeof( struct V_17 ) ;
V_7 += V_18 -> V_19 *
V_20 ;
}
break;
case V_21 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_3 ) ;
V_7 += sizeof( struct V_22 ) ;
break;
case V_23 :
{
struct V_24 * V_25 =
(struct V_24 * ) V_6 ;
int V_26 = V_25 -> V_27 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_4 ) ;
V_7 += sizeof( struct V_24 ) ;
V_7 += V_26 *
V_28 ;
}
break;
case V_29 :
{
struct V_30 * V_31 =
(struct V_30 * ) V_6 ;
int V_32 = V_31 -> V_33 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_5 ) ;
V_7 += V_32 * 4 ;
}
break;
case V_34 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_6 ) ;
* V_3 = TRUE ;
break;
case V_35 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_7 ) ;
* V_3 = TRUE ;
break;
case V_36 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_8 ) ;
* V_3 = TRUE ;
break;
case V_37 :
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_9 ) ;
* V_3 = TRUE ;
break;
default:
* V_3 = TRUE ;
break;
}
if ( * V_3 == false ) {
if ( * V_4 <= V_7 ) {
* V_3 = TRUE ;
} else {
* V_2 = * V_6 ;
V_6 += V_7 ;
( * V_4 ) -= V_7 ;
}
}
* V_1 = V_6 ;
return V_5 ;
}
static T_1 F_4 ( T_1 * V_38 , T_2 * V_39 ,
T_2 * V_40 , T_2 V_41 , T_1 V_42 )
{
T_1 * V_43 = V_38 ;
bool V_44 = false ;
T_1 V_45 = 0 ;
T_1 * V_2 = NULL ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
if ( ! V_38 || ( V_41 == 0 ) )
return 0 ;
* V_39 = * V_40 = 0 ;
V_45 = V_42 ;
while ( ! V_44 ) {
V_2 = F_1 ( & V_43 ,
& V_45 ,
& V_44 ,
& V_41 ) ;
if ( V_44 ) {
if ( ( V_45 == V_36 ) ||
( V_45 == V_37 ) ) {
* V_39 = * ( ( V_46 ) ( V_2 ) ) ;
* V_40 = * ( ( V_46 ) ( V_2 + 2 ) ) ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_10 ,
F_5 ( * V_39 ) ,
F_5 ( * V_40 ) ) ;
}
break;
}
}
return V_45 ;
}
T_2 F_6 ( struct V_8 * V_9 , T_3 V_47 ,
struct V_48 * V_49 )
{
T_2 V_50 = 0 ;
T_2 V_51 = 0 ;
T_1 V_52 = 0 ;
struct V_53 * V_54 = NULL ;
bool V_55 = false ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_11 ) ;
V_54 = V_47 ;
F_7 ( V_54 ) ;
V_52 = F_4 ( ( T_1 * ) ( V_47 +
sizeof( struct V_53 ) ) ,
& V_51 ,
& V_50 ,
V_54 -> V_41 ,
V_54 -> V_42 ) ;
do {
if ( V_49 -> V_56 == 0 ) {
break;
}
if ( ! V_49 -> V_57 ) {
break;
}
V_55 = F_8 ( V_49 ,
V_54 ) ;
if ( ! V_55 )
break;
V_55 = F_9 ( V_49 ,
V_54 ) ;
if ( ! V_55 )
break;
V_55 = F_10 ( V_49 ,
V_52 ) ;
if ( ! V_55 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_12 ) ;
if ( ( V_52 == V_36 ) ||
( V_52 == V_37 ) ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_13 ,
F_5 ( V_51 ) ) ;
V_55 = F_11 ( V_49 ,
F_5 ( V_51 ) ) ;
if ( ! V_55 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_14 ) ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_15 ,
F_5 ( V_50 ) ) ;
V_55 = F_12 ( V_49 ,
F_5 ( V_50 ) ) ;
if ( ! V_55 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_16 ) ;
}
} while ( 0 );
if ( V_55 == TRUE ) {
INT V_58 = 0 ;
V_58 = F_13 ( V_9 ,
V_49 -> V_59 ) ;
if ( ( V_58 >= V_60 ) ||
( V_9 -> V_61 [ V_58 ] . V_62 == false ) )
V_55 = false ;
}
return V_55 ;
}
static bool F_8 ( struct V_48 * V_49 ,
struct V_53 * V_54 )
{
T_4 V_63 = 0 ;
T_4 V_64 = 0 ;
T_4 V_65 = 4 ;
T_5 V_66 [ 4 ] ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
union V_67 * V_68 = & V_49 -> V_69 ;
T_4 V_70 =
( T_4 ) V_49 -> V_71 ;
if ( V_70 == 0 )
return TRUE ;
for ( V_64 = 0 ;
V_64 < V_65 ;
V_64 ++ )
V_66 [ V_64 ] =
F_14 ( V_54 -> V_72 [ V_64 ] ) ;
for ( V_63 = 0 ;
V_63 < V_70 ;
V_63 += V_65 ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_17 ) ;
F_15 ( V_66 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_18 ) ;
F_15 ( & V_68 -> V_73 [ V_63 ] ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_19 ) ;
F_15 ( & V_68 -> V_74 [ V_63 ] ) ;
for ( V_64 = 0 ;
V_64 < V_65 ;
V_64 ++ ) {
if ( ( V_68 -> V_73 [ V_63 + V_64 ] &
V_66 [ V_64 ] ) !=
V_68 -> V_74 [ V_63 + V_64 ] ) {
break;
}
if ( V_64 == V_65 - 1 ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_20 ) ;
return TRUE ;
}
}
}
return false ;
}
static bool F_9 ( struct V_48 * V_49 ,
struct V_53 * V_54 )
{
T_4 V_63 = 0 ;
T_4 V_64 = 0 ;
T_4 V_65 = 4 ;
T_5 V_75 [ 4 ] ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
union V_67 * V_76 = & V_49 -> V_77 ;
T_4 V_78 =
( T_4 ) V_49 -> V_79 ;
if ( V_78 == 0 )
return TRUE ;
for ( V_64 = 0 ;
V_64 < V_65 ;
V_64 ++ )
V_75 [ V_64 ] =
F_14 ( V_54 -> V_80 [ V_64 ] ) ;
for ( V_63 = 0 ;
V_63 < V_78 ;
V_63 += V_65 ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_21 ) ;
F_15 ( V_75 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_22 ) ;
F_15 ( & V_76 -> V_73 [ V_63 ] ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_23 ) ;
F_15 ( & V_76 -> V_74 [ V_63 ] ) ;
for ( V_64 = 0 ;
V_64 < V_65 ;
V_64 ++ ) {
if ( ( V_76 -> V_73 [ V_63 + V_64 ] &
V_75 [ V_64 ] ) !=
V_76 -> V_74 [ V_63 + V_64 ] ) {
break;
}
if ( V_64 == V_65 - 1 ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_24 ) ;
return TRUE ;
}
}
}
return false ;
}
VOID F_15 ( T_5 * V_81 )
{
T_4 V_65 = 4 ;
T_4 V_64 = 0 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
for ( V_64 = 0 ;
V_64 < V_65 ;
V_64 ++ ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_25 , V_81 [ V_64 ] ) ;
}
}
static VOID F_7 ( struct V_53 * V_54 )
{
T_1 V_82 ;
T_1 V_83 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_26 ) ;
V_82 = V_54 -> V_84 & 0xf0 ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_27 , V_82 ) ;
V_83 = V_54 -> V_84 & 0x0f ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_28 , V_83 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_29 ,
F_5 ( V_54 -> V_41 ) ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_30 , V_54 -> V_42 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_31 , V_54 -> V_85 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_32 ) ;
F_15 ( V_54 -> V_72 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_33 ) ;
F_15 ( V_54 -> V_80 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_34 ) ;
}
