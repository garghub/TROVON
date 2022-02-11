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
return ( T_1 * ) & V_4 -> V_7 ;
}
static T_1 * F_3 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
struct V_11 * V_12 =
(struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
return ( T_1 * ) & V_12 -> V_14 ;
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
return ( T_1 * ) & V_12 -> V_15 [ V_10 ] . V_18 . V_19 ;
}
static T_1 * F_5 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_8 , V_9 ;
int V_10 ;
struct V_11 * V_12 =
(struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
return ( T_1 * ) & V_12 -> V_14 ;
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
int F_6 ( struct V_20 * * V_21 ,
struct V_22 * V_23 )
{
struct V_20 * V_24 = NULL ;
T_1 * V_1 ;
T_1 * V_2 ;
T_1 V_25 ;
V_24 = (struct V_20 * ) V_23 -> V_26 . V_27 [ 0 ] . V_28 ;
if ( V_23 -> V_26 . V_29 <= V_30 ) {
F_2 ( L_4 ,
V_23 -> V_26 . V_29 ) ;
return - V_31 ;
}
V_24 -> V_32 = F_4 ( V_24 -> V_32 ) ;
V_24 -> V_33 = F_4 ( V_24 -> V_33 ) ;
V_24 -> V_34 = F_4 ( V_24 -> V_34 ) ;
V_24 -> V_35 = F_4 ( V_24 -> V_35 ) ;
if ( V_24 -> V_33 != V_36 )
return - V_37 ;
if ( V_24 -> V_35 == V_38 ) {
int V_39 ;
V_24 -> V_40 . V_41 . V_42 =
F_4 ( V_24 -> V_40 . V_41 . V_42 ) ;
V_24 -> V_40 . V_41 . V_43 =
F_4 ( V_24 -> V_40 . V_41 . V_43 ) ;
V_1 = & V_24 -> V_40 . V_41 . V_44 [ 4 ] ;
V_23 -> V_26 . V_27 [ 0 ] . V_28 = V_1 ;
V_39 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_24 ) ;
V_23 -> V_26 . V_27 [ 0 ] . V_45 -= V_39 ;
if ( V_39 > V_23 -> V_26 . V_29 )
return - V_31 ;
return V_39 ;
}
V_1 = & V_24 -> V_40 . V_46 [ 0 ] ;
V_2 = ( T_1 * ) ( ( unsigned long ) V_24 + V_23 -> V_26 . V_29 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_31 ;
V_1 = F_3 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_31 ;
V_1 = F_5 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_31 ;
V_23 -> V_26 . V_27 [ 0 ] . V_28 = V_1 ;
V_25 = ( unsigned long ) V_1 - ( unsigned long ) V_24 ;
V_23 -> V_26 . V_27 [ 0 ] . V_45 -= V_25 ;
* V_21 = V_24 ;
return V_25 ;
}
int F_7 ( struct V_22 * V_23 )
{
struct V_20 * V_24 = NULL ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
T_1 * V_1 ;
T_1 V_39 ;
F_2 ( L_5 ,
V_23 ) ;
V_24 = (struct V_20 * ) V_23 -> V_26 . V_27 [ 0 ] . V_28 ;
if ( V_24 -> V_35 == V_38 ) {
V_1 = & V_24 -> V_40 . V_41 . V_44 [ 4 ] ;
V_23 -> V_26 . V_27 [ 0 ] . V_28 = V_1 ;
V_39 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_24 ) ;
V_23 -> V_26 . V_27 [ 0 ] . V_45 -= V_39 ;
return V_39 ;
}
V_1 = & V_24 -> V_40 . V_46 [ 0 ] ;
for ( V_4 = (struct V_3 * ) V_1 ;
V_4 -> V_5 != V_6 ; V_4 ++ ) ;
V_1 = ( T_1 * ) & V_4 -> V_7 ;
V_12 = (struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
V_1 = ( T_1 * ) & V_12 -> V_14 ;
else
V_1 = ( T_1 * ) & V_12 -> V_15 [ V_12 -> V_14 ] . V_18 . V_19 ;
V_12 = (struct V_11 * ) V_1 ;
if ( V_12 -> V_13 == V_6 )
V_1 = ( T_1 * ) & V_12 -> V_14 ;
else
V_1 = ( T_1 * ) & V_12 -> V_15 [ V_12 -> V_14 ] ;
V_23 -> V_26 . V_27 [ 0 ] . V_28 = V_1 ;
V_39 = ( unsigned long ) V_1 - ( unsigned long ) V_24 ;
V_23 -> V_26 . V_27 [ 0 ] . V_45 -= V_39 ;
return V_39 ;
}
int F_8 ( struct V_47 * V_48 ,
struct V_20 * V_24 ,
enum V_49 V_50 , T_1 * V_1 )
{
T_1 * V_51 = V_1 ;
* V_1 ++ = F_9 ( V_24 -> V_32 ) ;
* V_1 ++ = F_9 ( V_24 -> V_33 ) ;
* V_1 ++ = F_9 ( V_48 -> V_52 ) ;
* V_1 ++ = F_9 ( V_53 ) ;
* V_1 ++ = F_9 ( V_50 ) ;
if ( V_50 == V_54 ) {
* V_1 ++ = F_9 ( V_36 ) ;
* V_1 ++ = F_9 ( V_36 ) ;
}
return ( int ) ( ( unsigned long ) V_1 - ( unsigned long ) V_51 ) ;
}
int F_10 ( struct V_20 * V_24 )
{
struct V_11 * V_55 ;
V_55 = (struct V_11 * )
& V_24 -> V_40 . V_46 [ 1 ] ;
if ( V_55 -> V_13 )
V_55 = (struct V_11 * )
& V_55 -> V_15 [ F_4 ( V_55 -> V_14 ) ] .
V_18 . V_19 ;
else
V_55 = (struct V_11 * )
& V_55 -> V_14 ;
if ( V_55 -> V_13 )
V_55 = (struct V_11 * )
& V_55 -> V_15 [ F_4 ( V_55 -> V_14 ) ] ;
else
V_55 = (struct V_11 * )
& V_55 -> V_14 ;
return ( unsigned long ) V_55 - ( unsigned long ) V_24 ;
}
void F_11 ( struct V_20 * V_24 , int V_56 )
{
struct V_11 * V_12 ;
V_24 -> V_40 . V_46 [ 0 ] = V_6 ;
V_12 = (struct V_11 * )
& V_24 -> V_40 . V_46 [ 1 ] ;
V_12 -> V_13 = V_57 ;
V_12 -> V_14 = F_9 ( V_56 ) ;
V_12 -> V_15 [ V_56 ] . V_18 . V_58 = V_6 ;
V_12 -> V_15 [ V_56 ] . V_18 . V_19 = V_6 ;
}
void F_12 ( struct V_11 * V_12 ,
int V_56 )
{
V_12 -> V_13 = V_57 ;
V_12 -> V_14 = F_9 ( V_56 ) ;
}
void F_13 ( struct V_11 * V_12 ,
int V_59 ,
T_2 V_58 ,
T_3 V_60 ,
T_1 V_61 )
{
struct V_62 * V_63 = & V_12 -> V_15 [ V_59 ] . V_18 ;
V_63 -> V_58 = V_58 ;
V_63 -> V_60 = V_60 ;
V_63 -> V_19 = F_9 ( V_61 ) ;
}
void F_14 ( struct V_47 * V_48 ,
struct V_20 * V_64 ,
struct V_20 * V_65 ,
enum V_66 V_67 )
{
V_65 -> V_32 = F_9 ( V_64 -> V_32 ) ;
V_65 -> V_33 = F_9 ( V_64 -> V_33 ) ;
V_65 -> V_34 = F_9 ( V_48 -> V_52 ) ;
V_65 -> V_35 = F_9 ( V_67 ) ;
V_65 -> V_40 . V_46 [ 0 ] = V_6 ;
V_65 -> V_40 . V_46 [ 1 ] = V_6 ;
V_65 -> V_40 . V_46 [ 2 ] = V_6 ;
}
