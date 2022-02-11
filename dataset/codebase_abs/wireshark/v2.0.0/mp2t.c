static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 ,
struct V_4 * V_5 , T_5 * V_6 , int * V_7 ,
T_6 * * V_8 )
{
T_7 V_9 ;
F_2 ( V_6 , V_10 ) ;
if ( ! F_3 ( V_2 , F_4 ( V_6 ) , V_10 , V_7 , V_8 ) )
return FALSE ;
V_5 -> V_11 = V_12 ;
V_5 -> V_13 = V_14 ;
V_9 = ( ( T_7 ) ( V_3 - V_1 -> V_15 ) * 8 ) ;
V_5 -> V_16 . V_17 = ( V_18 ) ( V_9 / V_1 -> V_19 ) ;
V_5 -> V_16 . V_20 = ( int ) ( ( V_9 % V_1 -> V_19 ) * 1000000000 / V_1 -> V_19 ) ;
V_5 -> V_21 = V_10 ;
V_5 -> V_22 = V_10 ;
return TRUE ;
}
static T_1
F_5 ( T_8 * V_23 , int * V_7 , T_6 * * V_8 , T_4 * V_24 )
{
T_2 * V_1 ;
V_1 = ( T_2 * ) V_23 -> V_25 ;
* V_24 = F_6 ( V_23 -> V_2 ) ;
if ( ! F_1 ( V_1 , V_23 -> V_2 , * V_24 , & V_23 -> V_5 ,
V_23 -> V_26 , V_7 , V_8 ) ) {
return FALSE ;
}
if ( V_1 -> V_27 != 0 ) {
if ( - 1 == F_7 ( V_23 -> V_2 , V_1 -> V_27 , V_28 , V_7 ) ) {
return FALSE ;
}
}
return TRUE ;
}
static T_1
F_8 ( T_8 * V_23 , T_4 V_29 , struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
T_2 * V_1 ;
if ( - 1 == F_7 ( V_23 -> V_30 , V_29 , V_31 , V_7 ) ) {
return FALSE ;
}
V_1 = ( T_2 * ) V_23 -> V_25 ;
if ( ! F_1 ( V_1 , V_23 -> V_30 , V_29 , V_5 , V_6 ,
V_7 , V_8 ) ) {
if ( * V_7 == 0 )
* V_7 = V_32 ;
return FALSE ;
}
return TRUE ;
}
static T_7
F_9 ( T_9 * V_33 )
{
T_7 V_34 ;
T_7 V_35 ;
V_34 = F_10 ( V_33 ) ;
V_34 >>= 7 ;
V_35 = F_11 ( & V_33 [ 4 ] ) ;
V_35 &= 0x01ff ;
return ( V_34 * 300 + V_35 ) ;
}
static T_1
F_12 ( T_8 * V_23 , int * V_7 , T_6 * * V_8 , T_10 * V_36 , T_7 * V_37 , T_11 * V_38 )
{
T_9 V_33 [ V_10 ] ;
T_1 V_39 ;
T_9 V_40 ;
V_39 = FALSE ;
while ( FALSE == V_39 ) {
( * V_36 ) ++ ;
if ( ! F_3 ( V_23 -> V_2 , V_33 , V_10 , V_7 , V_8 ) ) {
return FALSE ;
}
if ( V_41 != V_33 [ 0 ] ) {
continue;
}
V_40 = 3 & ( V_33 [ 3 ] >> 4 ) ;
if ( V_40 < 2 ) {
continue;
}
if ( V_33 [ 4 ] < 7 ) {
continue;
}
if ( 0x10 != ( 0x10 & V_33 [ 5 ] ) ) {
continue;
}
* V_37 = F_9 ( & V_33 [ 6 ] ) ;
* V_38 = 0x01ff & F_11 ( & V_33 [ 1 ] ) ;
V_39 = TRUE ;
}
return TRUE ;
}
static T_12
F_13 ( T_8 * V_23 , T_7 * V_19 , int * V_7 , T_6 * * V_8 )
{
T_10 V_42 , V_43 ;
T_7 V_44 , V_45 ;
T_11 V_46 , V_47 ;
T_10 V_36 ;
T_7 V_48 , V_49 ;
V_36 = 0 ;
if ( ! F_12 ( V_23 , V_7 , V_8 , & V_36 , & V_44 , & V_46 ) ) {
if ( * V_7 == V_32 )
return V_50 ;
if ( * V_7 != 0 )
return V_51 ;
* V_19 = V_52 ;
return V_53 ;
}
V_42 = V_36 ;
V_43 = V_42 ;
while ( V_42 == V_43 ) {
if ( ! F_12 ( V_23 , V_7 , V_8 , & V_36 , & V_45 , & V_47 ) ) {
if ( * V_7 == V_32 )
return V_50 ;
if ( * V_7 != 0 )
return V_51 ;
* V_19 = V_52 ;
return V_53 ;
}
if ( V_46 == V_47 ) {
V_43 = V_36 ;
}
}
if ( V_45 <= V_44 ) {
return V_50 ;
}
V_48 = V_45 - V_44 ;
V_49 = V_10 * ( V_43 - V_42 ) * 8 ;
* V_19 = ( ( V_54 * V_49 ) / V_48 ) ;
return V_53 ;
}
T_12
F_14 ( T_8 * V_23 , int * V_7 , T_6 * * V_8 )
{
T_9 V_33 [ V_10 + V_55 ] ;
T_9 V_27 = 0 ;
T_13 V_56 = 0 ;
int V_57 ;
int V_58 ;
T_2 * V_1 ;
T_12 V_59 ;
T_7 V_19 ;
if ( ! F_15 ( V_23 -> V_2 , V_33 , V_10 , V_7 , V_8 ) ) {
if ( * V_7 != V_32 )
return V_51 ;
return V_50 ;
}
V_58 = - 1 ;
for ( V_57 = 0 ; V_57 < V_10 ; V_57 ++ ) {
if ( V_41 == V_33 [ V_57 ] ) {
V_58 = V_57 ;
break;
}
}
if ( - 1 == V_58 ) {
return V_50 ;
}
if ( - 1 == F_7 ( V_23 -> V_2 , V_58 , V_31 , V_7 ) ) {
return V_51 ;
}
do {
if ( ! F_15 ( V_23 -> V_2 , V_33 , V_10 + V_27 , V_7 , V_8 ) ) {
if ( * V_7 != V_32 )
return V_51 ;
if( V_56 < 2 ) return V_50 ;
break;
}
if ( V_33 [ 0 ] == V_41 ) {
V_56 ++ ;
}
else {
if ( V_27 > 0 )
return V_50 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ ) {
if ( V_33 [ V_57 ] == V_41 ) {
V_27 = V_57 ;
if ( - 1 == F_7 ( V_23 -> V_2 , V_58 , V_31 , V_7 ) ) {
return V_51 ;
}
V_56 = 0 ;
break;
}
}
if ( V_57 == V_55 )
return V_50 ;
}
} while ( V_56 < V_60 );
if ( - 1 == F_7 ( V_23 -> V_2 , V_58 , V_31 , V_7 ) ) {
return V_51 ;
}
V_59 = F_13 ( V_23 , & V_19 , V_7 , V_8 ) ;
if ( V_59 != V_53 ) {
return V_59 ;
}
if ( - 1 == F_7 ( V_23 -> V_2 , V_58 , V_31 , V_7 ) ) {
return V_51 ;
}
V_23 -> V_61 = V_62 ;
V_23 -> V_63 = V_64 ;
V_23 -> V_65 = V_66 ;
V_23 -> V_67 = F_5 ;
V_23 -> V_68 = F_8 ;
V_23 -> V_69 = 0 ;
V_1 = ( T_2 * ) F_16 ( sizeof( T_2 ) ) ;
V_23 -> V_25 = V_1 ;
V_1 -> V_15 = V_58 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_19 = V_19 ;
return V_53 ;
}
