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
void F_3 ( struct V_3 * V_4 ,
int * V_8 , int * V_9 )
{
* V_9 = 0 ;
* V_8 = 0 ;
for (; V_4 -> V_5 != 0 ; V_4 ++ ) {
* V_9 = * V_9 + F_4 ( V_4 -> V_10 . V_11 ) ;
* V_8 = * V_8 + 1 ;
}
}
static T_1 * F_5 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_12 , V_13 ;
int V_14 ;
struct V_15 * V_16 =
(struct V_15 * ) V_1 ;
if ( V_16 -> V_17 == V_6 )
return ( T_1 * ) & V_16 -> V_18 ;
if ( ( unsigned long ) V_16 + sizeof( struct V_15 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_16 , V_2 ) ;
return NULL ;
}
V_14 = F_4 ( V_16 -> V_18 ) ;
V_12 = ( unsigned long ) & V_16 -> V_19 [ 0 ] ;
V_13 = ( unsigned long ) V_2 ;
if ( V_14 < 0 ||
V_14 > ( V_20 - V_12 ) / sizeof( struct V_21 ) ||
( V_12 + ( sizeof( struct V_21 ) * V_14 ) ) > V_13 ) {
F_2 ( L_3 ,
V_16 , V_14 , V_2 ) ;
return NULL ;
}
return ( T_1 * ) & V_16 -> V_19 [ V_14 ] . V_22 . V_11 ;
}
static T_1 * F_6 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned long V_12 , V_13 ;
int V_14 ;
struct V_15 * V_16 =
(struct V_15 * ) V_1 ;
if ( V_16 -> V_17 == V_6 )
return ( T_1 * ) & V_16 -> V_18 ;
if ( ( unsigned long ) V_16 + sizeof( struct V_15 ) >
( unsigned long ) V_2 ) {
F_2 ( L_2 , V_16 , V_2 ) ;
return NULL ;
}
V_14 = F_4 ( V_16 -> V_18 ) ;
V_12 = ( unsigned long ) & V_16 -> V_19 [ 0 ] ;
V_13 = ( unsigned long ) V_2 ;
if ( V_14 < 0 ||
V_14 > ( V_20 - V_12 ) / sizeof( struct V_21 ) ||
( V_12 + ( sizeof( struct V_21 ) * V_14 ) ) > V_13 ) {
F_2 ( L_3 ,
V_16 , V_14 , V_2 ) ;
return NULL ;
}
return ( T_1 * ) & V_16 -> V_19 [ V_14 ] ;
}
int F_7 ( struct V_23 * * V_24 ,
struct V_25 * V_26 )
{
struct V_23 * V_27 = NULL ;
T_1 * V_1 ;
T_1 * V_2 ;
T_1 V_28 ;
V_27 = (struct V_23 * ) V_26 -> V_29 . V_30 [ 0 ] . V_31 ;
if ( V_26 -> V_29 . V_32 <= V_33 ) {
F_2 ( L_4 ,
V_26 -> V_29 . V_32 ) ;
return - V_34 ;
}
V_27 -> V_35 = F_4 ( V_27 -> V_35 ) ;
V_27 -> V_36 = F_4 ( V_27 -> V_36 ) ;
V_27 -> V_37 = F_4 ( V_27 -> V_37 ) ;
V_27 -> V_38 = F_4 ( V_27 -> V_38 ) ;
if ( V_27 -> V_36 != V_39 )
return - V_40 ;
if ( V_27 -> V_38 == V_41 ) {
int V_42 ;
V_27 -> V_43 . V_44 . V_45 =
F_4 ( V_27 -> V_43 . V_44 . V_45 ) ;
V_27 -> V_43 . V_44 . V_46 =
F_4 ( V_27 -> V_43 . V_44 . V_46 ) ;
V_1 = & V_27 -> V_43 . V_44 . V_47 [ 4 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_27 ) ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
if ( V_42 > V_26 -> V_29 . V_32 )
return - V_34 ;
return V_42 ;
}
V_1 = & V_27 -> V_43 . V_49 [ 0 ] ;
V_2 = ( T_1 * ) ( ( unsigned long ) V_27 + V_26 -> V_29 . V_32 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 = F_5 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 = F_6 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_34 ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_28 = ( unsigned long ) V_1 - ( unsigned long ) V_27 ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_28 ;
* V_24 = V_27 ;
return V_28 ;
}
int F_8 ( struct V_25 * V_26 )
{
struct V_23 * V_27 = NULL ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_1 * V_1 ;
T_1 V_42 ;
F_2 ( L_5 ,
V_26 ) ;
V_27 = (struct V_23 * ) V_26 -> V_29 . V_30 [ 0 ] . V_31 ;
if ( V_27 -> V_38 == V_41 ) {
V_1 = & V_27 -> V_43 . V_44 . V_47 [ 4 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( T_1 ) ( ( unsigned long ) V_1 - ( unsigned long ) V_27 ) ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
return V_42 ;
}
V_1 = & V_27 -> V_43 . V_49 [ 0 ] ;
for ( V_4 = (struct V_3 * ) V_1 ;
V_4 -> V_5 != V_6 ; V_4 ++ ) ;
V_1 = ( T_1 * ) & V_4 -> V_7 ;
V_16 = (struct V_15 * ) V_1 ;
if ( V_16 -> V_17 == V_6 )
V_1 = ( T_1 * ) & V_16 -> V_18 ;
else
V_1 = ( T_1 * ) & V_16 -> V_19 [ V_16 -> V_18 ] . V_22 . V_11 ;
V_16 = (struct V_15 * ) V_1 ;
if ( V_16 -> V_17 == V_6 )
V_1 = ( T_1 * ) & V_16 -> V_18 ;
else
V_1 = ( T_1 * ) & V_16 -> V_19 [ V_16 -> V_18 ] ;
V_26 -> V_29 . V_30 [ 0 ] . V_31 = V_1 ;
V_42 = ( unsigned long ) V_1 - ( unsigned long ) V_27 ;
V_26 -> V_29 . V_30 [ 0 ] . V_48 -= V_42 ;
return V_42 ;
}
int F_9 ( struct V_50 * V_51 ,
struct V_23 * V_27 ,
enum V_52 V_53 , T_1 * V_1 )
{
T_1 * V_54 = V_1 ;
* V_1 ++ = F_10 ( V_27 -> V_35 ) ;
* V_1 ++ = F_10 ( V_27 -> V_36 ) ;
* V_1 ++ = F_10 ( V_51 -> V_55 ) ;
* V_1 ++ = F_10 ( V_56 ) ;
* V_1 ++ = F_10 ( V_53 ) ;
if ( V_53 == V_57 ) {
* V_1 ++ = F_10 ( V_39 ) ;
* V_1 ++ = F_10 ( V_39 ) ;
}
return ( int ) ( ( unsigned long ) V_1 - ( unsigned long ) V_54 ) ;
}
int F_11 ( struct V_23 * V_27 )
{
struct V_15 * V_58 ;
V_58 = (struct V_15 * )
& V_27 -> V_43 . V_49 [ 1 ] ;
if ( V_58 -> V_17 )
V_58 = (struct V_15 * )
& V_58 -> V_19 [ F_4 ( V_58 -> V_18 ) ] .
V_22 . V_11 ;
else
V_58 = (struct V_15 * )
& V_58 -> V_18 ;
if ( V_58 -> V_17 )
V_58 = (struct V_15 * )
& V_58 -> V_19 [ F_4 ( V_58 -> V_18 ) ] ;
else
V_58 = (struct V_15 * )
& V_58 -> V_18 ;
return ( unsigned long ) V_58 - ( unsigned long ) V_27 ;
}
void F_12 ( struct V_23 * V_27 , int V_59 )
{
struct V_15 * V_16 ;
V_27 -> V_43 . V_49 [ 0 ] = V_6 ;
V_16 = (struct V_15 * )
& V_27 -> V_43 . V_49 [ 1 ] ;
V_16 -> V_17 = V_60 ;
V_16 -> V_18 = F_10 ( V_59 ) ;
V_16 -> V_19 [ V_59 ] . V_22 . V_61 = V_6 ;
V_16 -> V_19 [ V_59 ] . V_22 . V_11 = V_6 ;
}
void F_13 ( struct V_15 * V_16 ,
int V_59 )
{
V_16 -> V_17 = V_60 ;
V_16 -> V_18 = F_10 ( V_59 ) ;
}
void F_14 ( struct V_15 * V_16 ,
int V_62 ,
T_2 V_61 ,
T_3 V_63 ,
T_1 V_64 )
{
struct V_65 * V_66 = & V_16 -> V_19 [ V_62 ] . V_22 ;
V_66 -> V_61 = V_61 ;
V_66 -> V_63 = V_63 ;
V_66 -> V_11 = F_10 ( V_64 ) ;
}
void F_15 ( struct V_50 * V_51 ,
struct V_23 * V_67 ,
struct V_23 * V_68 ,
enum V_69 V_70 )
{
V_68 -> V_35 = F_10 ( V_67 -> V_35 ) ;
V_68 -> V_36 = F_10 ( V_67 -> V_36 ) ;
V_68 -> V_37 = F_10 ( V_51 -> V_55 ) ;
V_68 -> V_38 = F_10 ( V_70 ) ;
V_68 -> V_43 . V_49 [ 0 ] = V_6 ;
V_68 -> V_43 . V_49 [ 1 ] = V_6 ;
V_68 -> V_43 . V_49 [ 2 ] = V_6 ;
}
