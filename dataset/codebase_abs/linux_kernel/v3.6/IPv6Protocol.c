static T_1 * F_1 ( T_1 * * V_1 ,
T_1 * V_2 , BOOLEAN * V_3 , T_2 * V_4 )
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
* V_3 = FALSE ;
switch ( * V_2 ) {
case V_11 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_1 ) ;
V_7 += sizeof( V_15 ) ;
}
break;
case V_16 :
{
T_3 * V_17 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_2 ) ;
V_17 = ( T_3 * ) V_6 ;
V_7 += sizeof( T_3 ) ;
V_7 += V_17 -> V_18 * V_19 ;
}
break;
case V_20 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_3 ) ;
V_7 += sizeof( V_21 ) ;
}
break;
case V_22 :
{
T_4 * V_23 = ( T_4 * ) V_6 ;
int V_24 = V_23 -> V_25 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_4 ) ;
V_7 += sizeof( T_4 ) ;
V_7 += V_24 * V_26 ;
}
break;
case V_27 :
{
T_5 * V_28 = ( T_5 * ) V_6 ;
int V_29 = V_28 -> V_30 ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_5 ) ;
V_7 += V_29 * 4 ;
}
break;
case V_31 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_6 ) ;
* V_3 = TRUE ;
}
break;
case V_32 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_7 ) ;
* V_3 = TRUE ;
}
break;
case V_33 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_8 ) ;
* V_3 = TRUE ;
}
break;
case V_34 :
{
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_9 ) ;
* V_3 = TRUE ;
}
break;
default:
{
* V_3 = TRUE ;
}
break;
}
if ( * V_3 == FALSE ) {
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
static T_1 F_4 ( T_1 * V_35 , T_2 * V_36 ,
T_2 * V_37 , T_2 V_38 , T_1 V_39 )
{
T_1 * V_40 = V_35 ;
BOOLEAN V_41 = FALSE ;
T_1 V_42 = 0 ;
T_1 * V_2 = NULL ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
if ( ! V_35 || ( V_38 == 0 ) )
return 0 ;
* V_36 = * V_37 = 0 ;
V_42 = V_39 ;
while ( ! V_41 ) {
V_2 = F_1 ( & V_40 ,
& V_42 , & V_41 , & V_38 ) ;
if ( V_41 ) {
if ( ( V_42 == V_33 ) ||
( V_42 == V_34 ) ) {
* V_36 = * ( ( V_43 ) ( V_2 ) ) ;
* V_37 = * ( ( V_43 ) ( V_2 + 2 ) ) ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_10 ,
F_5 ( * V_36 ) ,
F_5 ( * V_37 ) ) ;
}
break;
}
}
return V_42 ;
}
T_2 F_6 ( struct V_8 * V_9 , T_6 V_44 ,
struct V_45 * V_46 )
{
T_2 V_47 = 0 ;
T_2 V_48 = 0 ;
T_1 V_49 = 0 ;
T_7 * V_50 = NULL ;
BOOLEAN V_51 = FALSE ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_11 ) ;
V_50 = ( T_7 * ) V_44 ;
F_7 ( V_50 ) ;
V_49 = F_4 ( ( T_1 * ) ( V_44 + sizeof( T_7 ) ) ,
& V_48 ,
& V_47 ,
V_50 -> V_38 ,
V_50 -> V_39 ) ;
do {
if ( V_46 -> V_52 == 0 ) {
break;
}
if ( ! V_46 -> V_53 ) {
break;
}
V_51 = F_8 ( V_46 ,
V_50 ) ;
if ( ! V_51 )
break;
V_51 = F_9 ( V_46 ,
V_50 ) ;
if ( ! V_51 )
break;
V_51 = F_10 ( V_46 ,
V_49 ) ;
if ( ! V_51 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_12 ) ;
if ( ( V_49 == V_33 ) ||
( V_49 == V_34 ) ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_13 ,
F_5 ( V_48 ) ) ;
V_51 = F_11 ( V_46 ,
F_5 ( V_48 ) ) ;
if ( ! V_51 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_14 ) ;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_15 ,
F_5 ( V_47 ) ) ;
V_51 = F_12 ( V_46 ,
F_5 ( V_47 ) ) ;
if ( ! V_51 )
break;
F_3 ( V_9 , V_12 , V_13 ,
V_14 , L_16 ) ;
}
} while ( 0 );
if ( V_51 == TRUE ) {
INT V_54 = 0 ;
V_54 = F_13 ( V_9 , V_46 -> V_55 ) ;
if ( V_54 >= V_56 ) {
V_51 = FALSE ;
} else {
if ( V_9 -> V_57 [ V_54 ] . V_58 == FALSE )
V_51 = FALSE ;
}
}
return V_51 ;
}
static BOOLEAN F_8 ( struct V_45 * V_46 ,
T_7 * V_50 )
{
T_8 V_59 = 0 ;
T_8 V_60 = 0 ;
T_8 V_61 = 4 ;
T_9 V_62 [ 4 ] ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
T_8 V_63 = ( T_8 ) V_46 -> V_64 ;
if ( V_63 == 0 )
return TRUE ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
V_62 [ V_60 ] = F_14 ( V_50 -> V_65 [ V_60 ] ) ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 += V_61 ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_17 ) ;
F_15 ( V_62 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_18 ) ;
F_15 ( & V_46 -> V_66 . V_67 [ V_59 ] ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_19 ) ;
F_15 ( & V_46 -> V_66 . V_68 [ V_59 ] ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( ( V_46 -> V_66 . V_67 [ V_59 + V_60 ] & V_62 [ V_60 ] )
!= V_46 -> V_66 . V_68 [ V_59 + V_60 ] ) {
break;
}
if ( V_60 == V_61 - 1 ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_20 ) ;
return TRUE ;
}
}
}
return FALSE ;
}
static BOOLEAN F_9 ( struct V_45 * V_46 ,
T_7 * V_50 )
{
T_8 V_59 = 0 ;
T_8 V_60 = 0 ;
T_8 V_61 = 4 ;
T_9 V_69 [ 4 ] ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
T_8 V_70 = ( T_8 ) V_46 -> V_71 ;
if ( V_70 == 0 )
return TRUE ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
V_69 [ V_60 ] = F_14 ( V_50 -> V_72 [ V_60 ] ) ;
for ( V_59 = 0 ; V_59 < V_70 ; V_59 += V_61 ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_21 ) ;
F_15 ( V_69 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_22 ) ;
F_15 ( & V_46 -> V_73 . V_67 [ V_59 ] ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_23 ) ;
F_15 ( & V_46 -> V_73 . V_68 [ V_59 ] ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
if ( ( V_46 -> V_73 . V_67 [ V_59 + V_60 ] & V_69 [ V_60 ] )
!= V_46 -> V_73 . V_68 [ V_59 + V_60 ] ) {
break;
}
if ( V_60 == V_61 - 1 ) {
F_3 ( V_9 , V_12 , V_13 ,
V_14 ,
L_24 ) ;
return TRUE ;
}
}
}
return FALSE ;
}
VOID F_15 ( T_9 * V_74 )
{
T_8 V_61 = 4 ;
T_8 V_60 = 0 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_25 , V_74 [ V_60 ] ) ;
}
}
static VOID F_7 ( T_7 * V_50 )
{
T_1 V_75 ;
T_1 V_76 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_26 ) ;
V_75 = V_50 -> V_77 & 0xf0 ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_27 , V_75 ) ;
V_76 = V_50 -> V_77 & 0x0f ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_28 , V_76 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_29 ,
F_5 ( V_50 -> V_38 ) ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_30 , V_50 -> V_39 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_31 , V_50 -> V_78 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_32 ) ;
F_15 ( V_50 -> V_65 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_33 ) ;
F_15 ( V_50 -> V_72 ) ;
F_3 ( V_9 , V_12 , V_13 , V_14 ,
L_34 ) ;
}
