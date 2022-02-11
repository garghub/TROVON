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
if ( ! F_7 ( V_23 -> V_2 , NULL , V_1 -> V_27 , V_7 , V_8 ) ) {
return FALSE ;
}
}
return TRUE ;
}
static T_1
F_8 ( T_8 * V_23 , T_4 V_28 , struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
T_2 * V_1 ;
if ( - 1 == F_9 ( V_23 -> V_29 , V_28 , V_30 , V_7 ) ) {
return FALSE ;
}
V_1 = ( T_2 * ) V_23 -> V_25 ;
if ( ! F_1 ( V_1 , V_23 -> V_29 , V_28 , V_5 , V_6 ,
V_7 , V_8 ) ) {
if ( * V_7 == 0 )
* V_7 = V_31 ;
return FALSE ;
}
return TRUE ;
}
static T_7
F_10 ( T_9 * V_32 )
{
T_7 V_33 ;
T_7 V_34 ;
V_33 = F_11 ( V_32 ) ;
V_33 >>= 7 ;
V_34 = F_12 ( & V_32 [ 4 ] ) ;
V_34 &= 0x01ff ;
return ( V_33 * 300 + V_34 ) ;
}
static T_1
F_13 ( T_8 * V_23 , T_9 V_27 ,
int * V_7 , T_6 * * V_8 , T_10 * V_35 , T_7 * V_36 , T_11 * V_37 )
{
T_9 V_32 [ V_10 + V_38 ] ;
T_1 V_39 ;
T_9 V_40 ;
T_12 V_41 = 0 ;
V_39 = FALSE ;
while ( FALSE == V_39 && V_41 ++ < V_42 * V_42 ) {
( * V_35 ) ++ ;
if ( ! F_3 (
V_23 -> V_2 , V_32 , V_10 + V_27 , V_7 , V_8 ) ) {
return FALSE ;
}
if ( V_43 != V_32 [ 0 ] ) {
continue;
}
V_40 = 3 & ( V_32 [ 3 ] >> 4 ) ;
if ( V_40 < 2 ) {
continue;
}
if ( V_32 [ 4 ] < 7 ) {
continue;
}
if ( 0x10 != ( 0x10 & V_32 [ 5 ] ) ) {
continue;
}
* V_36 = F_10 ( & V_32 [ 6 ] ) ;
* V_37 = 0x01ff & F_12 ( & V_32 [ 1 ] ) ;
V_39 = TRUE ;
}
return V_39 ;
}
static T_13
F_14 ( T_8 * V_23 , T_10 V_44 , T_9 V_27 ,
T_7 * V_19 , int * V_7 , T_6 * * V_8 )
{
T_10 V_45 , V_46 ;
T_7 V_47 , V_48 ;
T_11 V_49 , V_50 ;
T_10 V_35 ;
T_7 V_51 , V_52 ;
V_35 = V_44 ;
if ( ! F_13 ( V_23 , V_27 , V_7 , V_8 , & V_35 , & V_47 , & V_49 ) ) {
if ( * V_7 == V_31 )
return V_53 ;
if ( * V_7 != 0 )
return V_54 ;
* V_19 = V_55 ;
return V_56 ;
}
V_45 = V_35 ;
V_46 = V_45 ;
while ( V_45 == V_46 ) {
if ( ! F_13 ( V_23 , V_27 , V_7 , V_8 , & V_35 , & V_48 , & V_50 ) ) {
if ( * V_7 == V_31 )
return V_53 ;
if ( * V_7 != 0 )
return V_54 ;
* V_19 = V_55 ;
return V_56 ;
}
if ( V_49 == V_50 ) {
V_46 = V_35 ;
}
}
if ( V_48 <= V_47 ) {
return V_53 ;
}
V_51 = V_48 - V_47 ;
V_52 = ( T_7 ) V_10 * ( V_46 - V_45 ) * 8 ;
* V_19 = ( ( V_57 * V_52 ) / V_51 ) ;
if ( * V_19 == 0 ) {
return V_54 ;
}
return V_56 ;
}
T_13
F_15 ( T_8 * V_23 , int * V_7 , T_6 * * V_8 )
{
T_9 V_32 [ V_10 + V_38 ] ;
T_9 V_27 = 0 ;
T_12 V_58 = 0 ;
T_12 V_59 ;
T_10 V_44 = 0 ;
T_2 * V_1 ;
T_13 V_60 ;
T_7 V_19 ;
if ( ! F_7 ( V_23 -> V_2 , V_32 , V_10 , V_7 , V_8 ) ) {
if ( * V_7 != V_31 )
return V_54 ;
return V_53 ;
}
for ( V_59 = 0 ; V_59 < V_10 ; V_59 ++ ) {
if ( V_43 == V_32 [ V_59 ] ) {
V_44 = V_59 ;
goto V_39;
}
}
return V_53 ;
V_39:
if ( - 1 == F_9 ( V_23 -> V_2 , V_44 , V_30 , V_7 ) ) {
return V_54 ;
}
do {
if ( ! F_7 ( V_23 -> V_2 , V_32 , V_10 + V_27 , V_7 , V_8 ) ) {
if ( * V_7 != V_31 )
return V_54 ;
if( V_58 < 2 ) return V_53 ;
break;
}
if ( V_32 [ 0 ] == V_43 ) {
V_58 ++ ;
}
else {
if ( V_27 > 0 )
return V_53 ;
for ( V_59 = 0 ; V_59 < V_38 ; V_59 ++ ) {
if ( V_32 [ V_59 ] == V_43 ) {
V_27 = V_59 ;
if ( - 1 == F_9 ( V_23 -> V_2 , V_44 , V_30 , V_7 ) ) {
return V_54 ;
}
V_58 = 0 ;
break;
}
}
if ( V_59 == V_38 )
return V_53 ;
}
} while ( V_58 < V_42 );
if ( - 1 == F_9 ( V_23 -> V_2 , V_44 , V_30 , V_7 ) ) {
return V_54 ;
}
V_60 = F_14 ( V_23 , V_44 , V_27 ,
& V_19 , V_7 , V_8 ) ;
if ( V_60 != V_56 ) {
return V_60 ;
}
if ( - 1 == F_9 ( V_23 -> V_2 , V_44 , V_30 , V_7 ) ) {
return V_54 ;
}
V_23 -> V_61 = V_62 ;
V_23 -> V_63 = V_64 ;
V_23 -> V_65 = V_66 ;
V_23 -> V_67 = F_5 ;
V_23 -> V_68 = F_8 ;
V_23 -> V_69 = 0 ;
V_1 = ( T_2 * ) F_16 ( sizeof( T_2 ) ) ;
V_23 -> V_25 = V_1 ;
V_1 -> V_15 = V_44 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_19 = V_19 ;
return V_56 ;
}
