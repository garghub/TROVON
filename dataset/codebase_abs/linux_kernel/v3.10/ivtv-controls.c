static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_3 && V_5 -> V_6 . V_7 [ 0 ] == NULL ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_5 -> V_6 . V_7 [ V_8 ] = F_3 ( 2049 , V_10 ) ;
if ( V_5 -> V_6 . V_7 [ V_8 ] == NULL ) {
while ( -- V_8 >= 0 ) {
F_4 ( V_5 -> V_6 . V_7 [ V_8 ] ) ;
V_5 -> V_6 . V_7 [ V_8 ] = NULL ;
}
return - V_11 ;
}
}
}
V_5 -> V_6 . V_12 = V_3 ;
if ( V_5 -> V_6 . V_12 == 0 ) {
return 0 ;
}
if ( F_5 ( V_5 -> V_6 . V_13 ) == 0 ) {
if ( V_5 -> V_14 )
V_5 -> V_6 . V_13 -> V_15 = V_16 ;
else
V_5 -> V_6 . V_13 -> V_15 = V_17 ;
F_6 ( V_5 -> V_6 . V_13 , V_5 -> V_18 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_20 = V_19 == V_21 ;
struct V_22 V_3 ;
V_3 . V_23 = V_2 -> V_23 / ( V_20 ? 2 : 1 ) ;
V_3 . V_24 = V_2 -> V_24 ;
V_3 . V_25 = V_26 ;
F_8 ( V_5 -> V_27 , V_28 , V_29 , & V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_30 )
{
static const T_1 V_31 [ 3 ] = { 44100 , 48000 , 32000 } ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_30 < F_10 ( V_31 ) )
F_11 ( V_5 , V_32 , V_33 , V_31 [ V_30 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_5 -> V_34 = V_19 ;
return 0 ;
}
int F_13 ( struct V_4 * V_5 , T_2 * V_35 , T_2 * V_36 )
{
T_1 V_37 [ V_38 ] ;
if ( F_14 ( V_39 , & V_5 -> V_40 ) ) {
* V_35 = ( T_2 ) ( ( V_41 ) V_5 -> V_42 [ 2 ] << 32 ) |
( V_41 ) V_5 -> V_42 [ 1 ] ;
* V_36 = V_5 -> V_42 [ 0 ] ;
return 0 ;
}
* V_35 = 0 ;
* V_36 = 0 ;
if ( F_15 ( & V_5 -> V_43 ) ) {
if ( F_16 ( V_5 , V_44 , 5 , V_37 ) ) {
F_17 ( L_1 ) ;
return - V_45 ;
}
memcpy ( V_5 -> V_42 , V_37 , sizeof( V_5 -> V_42 ) ) ;
F_18 ( V_39 , & V_5 -> V_40 ) ;
* V_35 = ( T_2 ) ( ( V_41 ) V_37 [ 2 ] << 32 ) | ( V_41 ) V_37 [ 1 ] ;
* V_36 = V_37 [ 0 ] ;
}
return 0 ;
}
static int F_19 ( struct V_46 * V_47 )
{
struct V_4 * V_5 = F_2 ( V_47 -> V_48 , struct V_4 , V_2 . V_49 ) ;
switch ( V_47 -> V_50 ) {
case V_51 :
return F_13 ( V_5 , & V_5 -> V_52 -> V_53 ,
& V_5 -> V_54 -> V_53 ) ;
}
return 0 ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_4 * V_5 = F_2 ( V_47 -> V_48 , struct V_4 , V_2 . V_49 ) ;
switch ( V_47 -> V_50 ) {
case V_55 :
V_5 -> V_56 = V_5 -> V_57 -> V_19 - 1 ;
V_5 -> V_58 = V_5 -> V_59 -> V_19 - 1 ;
F_21 ( V_5 , V_60 , 2 , V_5 -> V_58 , V_5 -> V_56 ) ;
break;
}
return 0 ;
}
