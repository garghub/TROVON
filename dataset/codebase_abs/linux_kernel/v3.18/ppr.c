void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_2 ( sizeof( struct V_3 ) != V_5 * sizeof( V_6 ) ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_7 )
{
int V_8 ;
V_6 * V_9 ;
F_4 (ppr, i, rate) {
* V_9 = F_5 ( * V_9 + V_7 , 0 , 127 ) ;
}
}
void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , V_6 V_10 )
{
int V_8 ;
V_6 * V_9 ;
F_4 (ppr, i, rate) {
* V_9 = F_7 ( * V_9 , V_10 ) ;
}
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , V_6 F_7 )
{
int V_8 ;
V_6 * V_9 ;
F_4 (ppr, i, rate) {
* V_9 = V_10 ( * V_9 , F_7 ) ;
}
}
V_6 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_6 V_11 = 0 ;
int V_8 ;
V_6 * V_9 ;
F_4 (ppr, i, rate) {
V_11 = V_10 ( * V_9 , V_11 ) ;
}
return V_11 ;
}
bool F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_12 V_13 )
{
struct V_14 * V_15 = & V_4 -> V_15 ;
struct V_16 * V_17 = V_2 -> V_2 -> V_18 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
V_6 V_21 , V_22 ;
T_1 V_23 ;
T_2 * V_24 ;
V_6 V_25 , V_26 ;
int V_8 ;
switch ( V_13 ) {
case V_27 :
V_21 = F_7 ( V_17 -> V_28 [ 0 ] . V_29 ,
V_17 -> V_28 [ 1 ] . V_29 ) ;
V_23 = V_17 -> V_30 ;
V_24 = V_17 -> V_31 ;
V_25 = ( V_17 -> V_32 >> 0 ) & 0xf ;
V_26 = ( V_17 -> V_33 >> 0 ) & 0xf ;
break;
case V_34 :
V_21 = F_7 ( V_17 -> V_28 [ 0 ] . V_35 ,
V_17 -> V_28 [ 1 ] . V_35 ) ;
V_23 = V_17 -> V_36 ;
V_24 = V_17 -> V_37 ;
V_25 = ( V_17 -> V_32 >> 8 ) & 0xf ;
V_26 = ( V_17 -> V_33 >> 8 ) & 0xf ;
break;
case V_38 :
V_21 = F_7 ( V_17 -> V_28 [ 0 ] . V_39 ,
V_17 -> V_28 [ 1 ] . V_39 ) ;
V_23 = V_17 -> V_40 ;
V_24 = V_17 -> V_41 ;
V_25 = ( V_17 -> V_32 >> 4 ) & 0xf ;
V_26 = ( V_17 -> V_33 >> 4 ) & 0xf ;
break;
case V_42 :
V_21 = F_7 ( V_17 -> V_28 [ 0 ] . V_43 ,
V_17 -> V_28 [ 1 ] . V_43 ) ;
V_23 = V_17 -> V_44 ;
V_24 = V_17 -> V_45 ;
V_25 = ( V_17 -> V_32 >> 12 ) & 0xf ;
V_26 = ( V_17 -> V_33 >> 12 ) & 0xf ;
break;
default:
F_11 ( 1 ) ;
return false ;
}
if ( V_13 == V_27 ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_17 -> V_46 >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_47 [ V_8 ] = V_21 - V_22 ;
}
}
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_22 = ( ( V_23 >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_48 [ V_8 ] = V_21 - V_22 ;
}
V_15 -> V_49 [ 0 ] = V_15 -> V_48 [ 0 ] ;
V_15 -> V_49 [ 1 ] = V_15 -> V_48 [ 2 ] ;
V_15 -> V_49 [ 2 ] = V_15 -> V_48 [ 3 ] ;
V_15 -> V_49 [ 3 ] = V_15 -> V_48 [ 4 ] ;
V_15 -> V_49 [ 4 ] = V_15 -> V_48 [ 5 ] ;
V_15 -> V_49 [ 5 ] = V_15 -> V_48 [ 6 ] ;
V_15 -> V_49 [ 6 ] = V_15 -> V_48 [ 7 ] ;
V_15 -> V_49 [ 7 ] = V_15 -> V_48 [ 7 ] ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 0 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_50 [ V_8 ] = V_21 - V_22 ;
if ( V_20 -> type == V_51 && V_20 -> V_52 >= 3 )
V_15 -> V_50 [ V_8 ] -= V_25 ;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 1 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_50 [ 4 + V_8 ] = V_21 - V_22 ;
if ( V_20 -> type == V_51 && V_20 -> V_52 >= 3 )
V_15 -> V_50 [ 4 + V_8 ] -= V_25 ;
}
V_15 -> V_53 [ 0 ] = V_15 -> V_50 [ 0 ] ;
V_15 -> V_53 [ 1 ] = V_15 -> V_50 [ 0 ] ;
V_15 -> V_53 [ 2 ] = V_15 -> V_50 [ 1 ] ;
V_15 -> V_53 [ 3 ] = V_15 -> V_50 [ 2 ] ;
V_15 -> V_53 [ 4 ] = V_15 -> V_50 [ 3 ] ;
V_15 -> V_53 [ 5 ] = V_15 -> V_50 [ 4 ] ;
V_15 -> V_53 [ 6 ] = V_15 -> V_50 [ 5 ] ;
V_15 -> V_53 [ 7 ] = V_15 -> V_50 [ 6 ] ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 0 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_54 [ V_8 ] = V_21 - V_22 ;
if ( V_20 -> type == V_51 && V_20 -> V_52 >= 3 )
V_15 -> V_54 [ V_8 ] -= V_26 ;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 1 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_54 [ 4 + V_8 ] = V_21 - V_22 ;
if ( V_20 -> type == V_51 && V_20 -> V_52 >= 3 )
V_15 -> V_54 [ 4 + V_8 ] -= V_26 ;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 2 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_55 [ V_8 ] = V_21 - V_22 ;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_22 = ( ( V_24 [ 3 ] >> ( V_8 * 4 ) ) & 0xf ) * 2 ;
V_15 -> V_55 [ 4 + V_8 ] = V_21 - V_22 ;
}
return true ;
}
