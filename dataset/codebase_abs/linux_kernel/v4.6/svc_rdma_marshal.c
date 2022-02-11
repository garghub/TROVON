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
int F_6 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
T_1 * V_1 , * V_2 ;
unsigned int V_24 ;
T_2 V_25 ;
if ( V_23 -> V_26 . V_24 <= V_27 ) {
F_2 ( L_4 ,
V_23 -> V_26 . V_24 ) ;
return - V_28 ;
}
if ( V_21 -> V_29 != V_30 ) {
F_2 ( L_5 , V_31 ,
F_4 ( V_21 -> V_29 ) ) ;
return - V_32 ;
}
switch ( F_4 ( V_21 -> V_33 ) ) {
case V_34 :
case V_35 :
break;
case V_36 :
F_2 ( L_6 ) ;
return 0 ;
case V_37 :
F_2 ( L_7 ) ;
return 0 ;
case V_38 :
V_21 -> V_39 . V_40 . V_41 =
F_4 ( V_21 -> V_39 . V_40 . V_41 ) ;
V_21 -> V_39 . V_40 . V_42 =
F_4 ( V_21 -> V_39 . V_40 . V_42 ) ;
V_1 = & V_21 -> V_39 . V_40 . V_43 [ 4 ] ;
V_23 -> V_26 . V_44 [ 0 ] . V_45 = V_1 ;
V_24 = ( T_2 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_21 ) ;
V_23 -> V_26 . V_44 [ 0 ] . V_46 -= V_24 ;
if ( V_24 > V_23 -> V_26 . V_24 )
return - V_28 ;
return V_24 ;
default:
F_2 ( L_8 ,
F_4 ( V_21 -> V_33 ) ) ;
return - V_28 ;
}
V_1 = & V_21 -> V_39 . V_47 [ 0 ] ;
V_2 = ( T_1 * ) ( ( unsigned long ) V_21 + V_23 -> V_26 . V_24 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_9 ) ;
return - V_28 ;
}
V_1 = F_3 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_10 ) ;
return - V_28 ;
}
V_1 = F_5 ( V_1 , V_2 ) ;
if ( ! V_1 ) {
F_2 ( L_11 ) ;
return - V_28 ;
}
V_23 -> V_26 . V_44 [ 0 ] . V_45 = V_1 ;
V_25 = ( unsigned long ) V_1 - ( unsigned long ) V_21 ;
V_23 -> V_26 . V_44 [ 0 ] . V_46 -= V_25 ;
return V_25 ;
}
int F_7 ( struct V_48 * V_49 ,
struct V_20 * V_21 ,
enum V_50 V_51 , T_1 * V_1 )
{
T_1 * V_52 = V_1 ;
* V_1 ++ = V_21 -> V_53 ;
* V_1 ++ = V_21 -> V_29 ;
* V_1 ++ = F_8 ( V_49 -> V_54 ) ;
* V_1 ++ = V_55 ;
* V_1 ++ = F_8 ( V_51 ) ;
if ( V_51 == V_56 ) {
* V_1 ++ = V_30 ;
* V_1 ++ = V_30 ;
}
return ( int ) ( ( unsigned long ) V_1 - ( unsigned long ) V_52 ) ;
}
int F_9 ( struct V_20 * V_21 )
{
struct V_11 * V_57 ;
V_57 = (struct V_11 * )
& V_21 -> V_39 . V_47 [ 1 ] ;
if ( V_57 -> V_13 )
V_57 = (struct V_11 * )
& V_57 -> V_15 [ F_4 ( V_57 -> V_14 ) ] .
V_18 . V_19 ;
else
V_57 = (struct V_11 * )
& V_57 -> V_14 ;
if ( V_57 -> V_13 )
V_57 = (struct V_11 * )
& V_57 -> V_15 [ F_4 ( V_57 -> V_14 ) ] ;
else
V_57 = (struct V_11 * )
& V_57 -> V_14 ;
return ( unsigned long ) V_57 - ( unsigned long ) V_21 ;
}
void F_10 ( struct V_20 * V_21 , int V_58 )
{
struct V_11 * V_12 ;
V_21 -> V_39 . V_47 [ 0 ] = V_6 ;
V_12 = (struct V_11 * )
& V_21 -> V_39 . V_47 [ 1 ] ;
V_12 -> V_13 = V_59 ;
V_12 -> V_14 = F_8 ( V_58 ) ;
V_12 -> V_15 [ V_58 ] . V_18 . V_60 = V_6 ;
V_12 -> V_15 [ V_58 ] . V_18 . V_19 = V_6 ;
}
void F_11 ( struct V_11 * V_12 ,
int V_58 )
{
V_12 -> V_13 = V_59 ;
V_12 -> V_14 = F_8 ( V_58 ) ;
}
void F_12 ( struct V_11 * V_12 ,
int V_61 ,
T_1 V_60 ,
T_3 V_62 ,
T_2 V_63 )
{
struct V_64 * V_65 = & V_12 -> V_15 [ V_61 ] . V_18 ;
V_65 -> V_60 = V_60 ;
V_65 -> V_62 = V_62 ;
V_65 -> V_19 = F_8 ( V_63 ) ;
}
void F_13 ( struct V_48 * V_49 ,
struct V_20 * V_66 ,
struct V_20 * V_67 ,
enum V_68 V_69 )
{
V_67 -> V_53 = V_66 -> V_53 ;
V_67 -> V_29 = V_66 -> V_29 ;
V_67 -> V_70 = F_8 ( V_49 -> V_54 ) ;
V_67 -> V_33 = F_8 ( V_69 ) ;
V_67 -> V_39 . V_47 [ 0 ] = V_6 ;
V_67 -> V_39 . V_47 [ 1 ] = V_6 ;
V_67 -> V_39 . V_47 [ 2 ] = V_6 ;
}
