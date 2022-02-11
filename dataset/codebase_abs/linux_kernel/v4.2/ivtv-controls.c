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
struct V_22 V_23 = {
. V_24 = V_25 ,
} ;
V_23 . V_23 . V_26 = V_2 -> V_26 / ( V_20 ? 2 : 1 ) ;
V_23 . V_23 . V_27 = V_2 -> V_27 ;
V_23 . V_23 . V_28 = V_29 ;
F_8 ( V_5 -> V_30 , V_31 , V_32 , NULL , & V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_33 )
{
static const T_1 V_34 [ 3 ] = { 44100 , 48000 , 32000 } ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_33 < F_10 ( V_34 ) )
F_11 ( V_5 , V_35 , V_36 , V_34 [ V_33 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_5 -> V_37 = V_19 ;
return 0 ;
}
int F_13 ( struct V_4 * V_5 , T_2 * V_38 , T_2 * V_39 )
{
T_1 V_40 [ V_41 ] ;
if ( F_14 ( V_42 , & V_5 -> V_43 ) ) {
* V_38 = ( T_2 ) ( ( V_44 ) V_5 -> V_45 [ 2 ] << 32 ) |
( V_44 ) V_5 -> V_45 [ 1 ] ;
* V_39 = V_5 -> V_45 [ 0 ] ;
return 0 ;
}
* V_38 = 0 ;
* V_39 = 0 ;
if ( F_15 ( & V_5 -> V_46 ) ) {
if ( F_16 ( V_5 , V_47 , 5 , V_40 ) ) {
F_17 ( L_1 ) ;
return - V_48 ;
}
memcpy ( V_5 -> V_45 , V_40 , sizeof( V_5 -> V_45 ) ) ;
F_18 ( V_42 , & V_5 -> V_43 ) ;
* V_38 = ( T_2 ) ( ( V_44 ) V_40 [ 2 ] << 32 ) | ( V_44 ) V_40 [ 1 ] ;
* V_39 = V_40 [ 0 ] ;
}
return 0 ;
}
static int F_19 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = F_2 ( V_50 -> V_51 , struct V_4 , V_2 . V_52 ) ;
switch ( V_50 -> V_53 ) {
case V_54 :
return F_13 ( V_5 , V_5 -> V_55 -> V_56 . V_57 ,
V_5 -> V_58 -> V_56 . V_57 ) ;
}
return 0 ;
}
static int F_20 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = F_2 ( V_50 -> V_51 , struct V_4 , V_2 . V_52 ) ;
switch ( V_50 -> V_53 ) {
case V_59 :
V_5 -> V_60 = V_5 -> V_61 -> V_19 - 1 ;
V_5 -> V_62 = V_5 -> V_63 -> V_19 - 1 ;
F_21 ( V_5 , V_64 , 2 , V_5 -> V_62 , V_5 -> V_60 ) ;
break;
}
return 0 ;
}
