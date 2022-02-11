static T_1 * F_1 ( T_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
while ( V_4 -> V_5 != V_6 ) {
if ( ( ( unsigned long ) V_4 + sizeof( struct V_3 ) ) >
( unsigned long ) V_2 ) {
F_2 ( L_1 , V_2 , V_4 ) ;
return NULL ;
}
V_4 ++ ;
}
return & V_4 -> V_7 ;
}
static T_1 * F_3 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
struct V_11 * V_12 =
(struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
return & V_12 -> V_14 ;
if ( ( unsigned long ) V_12 + sizeof( struct V_11 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_12 , V_2 ) ;
return NULL ;
}
V_10 = F_4 ( V_12 -> V_14 ) ;
V_8 = ( unsigned long ) & V_12 -> V_15 [ 0 ] ;
V_9 = ( unsigned long ) V_2 ;
if ( V_10 < 0 ||
V_10 > ( V_16 - V_8 ) / sizeof( struct V_17 ) ||
( V_8 + ( sizeof( struct V_17 ) * V_10 ) ) > V_9 ) {
F_2 ( L_3 ,
V_12 , V_10 , V_2 ) ;
return NULL ;
}
return & V_12 -> V_15 [ V_10 ] . V_18 . V_19 ;
}
static T_1 * F_5 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
struct V_11 * V_12 =
(struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
return & V_12 -> V_14 ;
if ( ( unsigned long ) V_12 + sizeof( struct V_11 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_12 , V_2 ) ;
return NULL ;
}
V_10 = F_4 ( V_12 -> V_14 ) ;
V_8 = ( unsigned long ) & V_12 -> V_15 [ 0 ] ;
V_9 = ( unsigned long ) V_2 ;
if ( V_10 < 0 ||
V_10 > ( V_16 - V_8 ) / sizeof( struct V_17 ) ||
( V_8 + ( sizeof( struct V_17 ) * V_10 ) ) > V_9 ) {
F_2 ( L_3 ,
V_12 , V_10 , V_2 ) ;
return NULL ;
}
return ( T_1 * ) & V_12 -> V_15 [ V_10 ] ;
}
int F_6 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
T_1 * V_1 , * V_2 ;
unsigned int V_24 ;
T_2 V_25 ;
if ( V_21 -> V_24 <= V_26 ) {
F_2 ( L_4 ,
V_21 -> V_24 ) ;
return - V_27 ;
}
V_23 = (struct V_22 * ) V_21 -> V_28 [ 0 ] . V_29 ;
if ( V_23 -> V_30 != V_31 ) {
F_2 ( L_5 , V_32 ,
F_4 ( V_23 -> V_30 ) ) ;
return - V_33 ;
}
switch ( F_4 ( V_23 -> V_34 ) ) {
case V_35 :
case V_36 :
break;
case V_37 :
F_2 ( L_6 ) ;
return 0 ;
case V_38 :
F_2 ( L_7 ) ;
return 0 ;
case V_39 :
V_23 -> V_40 . V_41 . V_42 =
F_4 ( V_23 -> V_40 . V_41 . V_42 ) ;
V_23 -> V_40 . V_41 . V_43 =
F_4 ( V_23 -> V_40 . V_41 . V_43 ) ;
V_1 = & V_23 -> V_40 . V_41 . V_44 [ 4 ] ;
V_21 -> V_28 [ 0 ] . V_29 = V_1 ;
V_24 = ( T_2 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_23 ) ;
V_21 -> V_28 [ 0 ] . V_45 -= V_24 ;
if ( V_24 > V_21 -> V_24 )
return - V_27 ;
return V_24 ;
default:
F_2 ( L_8 ,
F_4 ( V_23 -> V_34 ) ) ;
return - V_27 ;
}
V_1 = & V_23 -> V_40 . V_46 [ 0 ] ;
V_2 = ( T_1 * ) ( ( unsigned long ) V_23 + V_21 -> V_24 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_9 ) ;
return - V_27 ;
}
V_1 = F_3 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_10 ) ;
return - V_27 ;
}
V_1 = F_5 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_11 ) ;
return - V_27 ;
}
V_21 -> V_28 [ 0 ] . V_29 = V_1 ;
V_25 = ( unsigned long ) V_1 - ( unsigned long ) V_23 ;
V_21 -> V_28 [ 0 ] . V_45 -= V_25 ;
return V_25 ;
}
int F_7 ( struct V_47 * V_48 ,
struct V_22 * V_23 ,
enum V_49 V_50 , T_1 * V_1 )
{
T_1 * V_51 = V_1 ;
* V_1 ++ = V_23 -> V_52 ;
* V_1 ++ = V_23 -> V_30 ;
* V_1 ++ = F_8 ( V_48 -> V_53 ) ;
* V_1 ++ = V_54 ;
* V_1 ++ = F_8 ( V_50 ) ;
if ( V_50 == V_55 ) {
* V_1 ++ = V_31 ;
* V_1 ++ = V_31 ;
}
return ( int ) ( ( unsigned long ) V_1 - ( unsigned long ) V_51 ) ;
}
int F_9 ( struct V_22 * V_23 )
{
struct V_11 * V_56 ;
V_56 = (struct V_11 * )
& V_23 -> V_40 . V_46 [ 1 ] ;
if ( V_56 -> V_13 )
V_56 = (struct V_11 * )
& V_56 -> V_15 [ F_4 ( V_56 -> V_14 ) ] .
V_18 . V_19 ;
else
V_56 = (struct V_11 * )
& V_56 -> V_14 ;
if ( V_56 -> V_13 )
V_56 = (struct V_11 * )
& V_56 -> V_15 [ F_4 ( V_56 -> V_14 ) ] ;
else
V_56 = (struct V_11 * )
& V_56 -> V_14 ;
return ( unsigned long ) V_56 - ( unsigned long ) V_23 ;
}
void F_10 ( struct V_22 * V_23 , int V_57 )
{
struct V_11 * V_12 ;
V_23 -> V_40 . V_46 [ 0 ] = V_6 ;
V_12 = (struct V_11 * )
& V_23 -> V_40 . V_46 [ 1 ] ;
V_12 -> V_13 = V_58 ;
V_12 -> V_14 = F_8 ( V_57 ) ;
V_12 -> V_15 [ V_57 ] . V_18 . V_59 = V_6 ;
V_12 -> V_15 [ V_57 ] . V_18 . V_19 = V_6 ;
}
void F_11 ( struct V_11 * V_12 ,
int V_57 )
{
V_12 -> V_13 = V_58 ;
V_12 -> V_14 = F_8 ( V_57 ) ;
}
void F_12 ( struct V_11 * V_12 ,
int V_60 ,
T_1 V_59 ,
T_3 V_61 ,
T_2 V_62 )
{
struct V_63 * V_64 = & V_12 -> V_15 [ V_60 ] . V_18 ;
V_64 -> V_59 = V_59 ;
V_64 -> V_61 = V_61 ;
V_64 -> V_19 = F_8 ( V_62 ) ;
}
void F_13 ( struct V_47 * V_48 ,
struct V_22 * V_65 ,
struct V_22 * V_66 ,
enum V_67 V_68 )
{
V_66 -> V_52 = V_65 -> V_52 ;
V_66 -> V_30 = V_65 -> V_30 ;
V_66 -> V_69 = F_8 ( V_48 -> V_53 ) ;
V_66 -> V_34 = F_8 ( V_68 ) ;
V_66 -> V_40 . V_46 [ 0 ] = V_6 ;
V_66 -> V_40 . V_46 [ 1 ] = V_6 ;
V_66 -> V_40 . V_46 [ 2 ] = V_6 ;
}
