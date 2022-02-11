void
F_1 ( void )
{
V_1 = false ;
V_2 = false ;
if ( ! V_3 ) {
V_3 = ( V_4 * ) F_2 ( 4 ) ;
F_3 ( V_3 ) ;
}
if ( ! V_5 ) {
V_5 = ( V_6 * ) F_2 ( V_7 ) ;
F_3 ( V_5 ) ;
}
F_4 ( V_8 ) ;
}
void
F_5 ( void )
{
if ( V_3 ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
if ( V_5 ) {
F_6 ( V_5 ) ;
V_5 = NULL ;
}
}
int
F_7 ( struct V_9 * V_10 )
{
int V_11 ;
V_4 V_12 ;
if ( V_1 ) {
F_8 ( V_13 , ( L_1 ) ) ;
return 0 ;
}
F_8 ( V_13 , ( L_2 , V_10 ) ) ;
V_1 = true ;
V_12 = V_14 ;
V_11 = F_9 ( V_10 , ( V_6 * ) & V_12 , sizeof( V_12 ) ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
if ( V_3 ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
if ( V_5 ) {
F_6 ( V_5 ) ;
V_5 = NULL ;
}
F_8 ( V_13 , ( L_4 ) ) ;
return 0 ;
}
int
F_10 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
int V_11 ;
V_4 V_12 ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_6 , V_10 ) ) ;
V_12 = V_19 ;
V_11 = F_9 ( V_10 , ( V_6 * ) & V_12 , sizeof( V_12 ) ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_11 = F_11 ( V_10 , ( V_6 * ) & V_18 -> V_20 ,
sizeof( V_18 -> V_20 ) , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_7 ) ) ;
return V_16 ;
}
if ( V_18 -> V_20 == V_21 ) {
V_11 = F_11 ( V_10 , ( V_6 * ) & V_18 -> V_22 ,
sizeof( V_18 -> V_22 ) , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_8 ) ) ;
return V_16 ;
}
F_3 ( V_18 -> V_22 == sizeof( * V_18 ) ) ;
V_11 = F_11 ( V_10 ,
( ( V_6 * ) V_18 ) + sizeof( V_18 -> V_22 ) ,
sizeof( * V_18 ) - sizeof( V_18 -> V_22 ) , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_9 ,
V_18 -> V_22 ) ) ;
return V_16 ;
}
}
F_8 ( V_13 , ( L_10 ,
V_18 -> V_20 , V_18 -> V_23 ) ) ;
return 0 ;
}
int
F_12 ( struct V_9 * V_10 ,
V_4 V_24 ,
V_6 * V_25 ,
V_4 V_26 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
V_4 V_28 , V_29 ;
F_3 ( F_13 ( V_30 + sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_26 ) ) ) ;
memset ( V_5 , 0 , V_30 + sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_26 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_11 ,
V_10 , V_24 , V_26 ) ) ;
V_12 = V_31 ;
V_28 = V_26 ;
while ( V_28 )
{
V_29 = ( V_28 < V_30 ) ? V_28 : V_30 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_29 , sizeof( V_29 ) ) ;
V_27 += sizeof( V_26 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_11 = F_11 ( V_10 , V_5 , V_29 , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_12 ) ) ;
return V_16 ;
}
memcpy ( & V_25 [ V_26 - V_28 ] , V_5 , V_29 ) ;
V_28 -= V_29 ; V_24 += V_29 ;
}
F_8 ( V_13 , ( L_13 ) ) ;
return 0 ;
}
int
F_14 ( struct V_9 * V_10 ,
V_4 V_24 ,
V_6 * V_25 ,
V_4 V_26 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
V_4 V_28 , V_32 ;
const V_4 V_33 = sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_26 ) ;
V_6 V_34 [ V_30 ] ;
V_6 * V_35 ;
F_3 ( F_13 ( V_30 + V_33 ) ) ;
memset ( V_5 , 0 , V_30 + V_33 ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_14 ,
V_10 , V_24 , V_26 ) ) ;
V_12 = V_36 ;
V_28 = V_26 ;
while ( V_28 )
{
V_35 = & V_25 [ V_26 - V_28 ] ;
if ( V_28 < ( V_30 - V_33 ) ) {
if ( V_28 & 3 ) {
V_28 = V_28 + ( 4 - ( V_28 & 3 ) ) ;
memcpy ( V_34 , V_35 , V_28 ) ;
V_35 = V_34 ;
}
V_32 = V_28 ;
} else {
V_32 = ( V_30 - V_33 ) ;
}
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_32 , sizeof( V_32 ) ) ;
V_27 += sizeof( V_32 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , V_35 , V_32 ) ;
V_27 += V_32 ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_28 -= V_32 ; V_24 += V_32 ;
}
F_8 ( V_13 , ( L_15 ) ) ;
return 0 ;
}
int
F_15 ( struct V_9 * V_10 ,
V_4 V_24 ,
V_4 * V_37 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_37 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_37 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_16 ,
V_10 , V_24 , * V_37 ) ) ;
V_12 = V_38 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , V_37 , sizeof( * V_37 ) ) ;
V_27 += sizeof( * V_37 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_11 = F_11 ( V_10 , V_5 , sizeof( * V_37 ) , false ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_12 ) ) ;
return V_16 ;
}
memcpy ( V_37 , V_5 , sizeof( * V_37 ) ) ;
F_8 ( V_13 , ( L_17 , * V_37 ) ) ;
return 0 ;
}
int
F_16 ( struct V_9 * V_10 ,
V_4 V_24 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_24 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_24 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_18 ,
V_10 , V_24 ) ) ;
V_12 = V_39 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_19 ) ) ;
return 0 ;
}
int
F_17 ( struct V_9 * V_10 ,
V_4 V_24 ,
V_4 * V_37 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_24 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_24 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_20 ,
V_10 , V_24 ) ) ;
V_12 = V_40 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_11 = F_11 ( V_10 , V_5 , sizeof( * V_37 ) , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_12 ) ) ;
return V_16 ;
}
memcpy ( V_37 , V_5 , sizeof( * V_37 ) ) ;
F_8 ( V_13 , ( L_21 , * V_37 ) ) ;
return 0 ;
}
int
F_18 ( struct V_9 * V_10 ,
V_4 V_24 ,
V_4 V_37 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_37 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_24 ) + sizeof( V_37 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_22 ,
V_10 , V_24 , V_37 ) ) ;
V_12 = V_41 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_37 , sizeof( V_37 ) ) ;
V_27 += sizeof( V_37 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_23 ) ) ;
return 0 ;
}
int
F_19 ( struct V_9 * V_10 ,
V_4 V_42 ,
V_4 V_43 ,
V_4 V_44 ,
V_4 V_45 ,
V_4 * V_46 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_42 ) + sizeof( V_43 ) +
sizeof( V_44 ) + sizeof( V_45 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_42 ) + sizeof( V_43 ) +
sizeof( V_44 ) + sizeof( V_45 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_24 ,
V_10 , V_42 , V_43 , V_44 , V_45 ) ) ;
V_12 = V_47 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_42 , sizeof( V_42 ) ) ;
V_27 += sizeof( V_42 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_43 , sizeof( V_43 ) ) ;
V_27 += sizeof( V_43 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_44 , sizeof( V_44 ) ) ;
V_27 += sizeof( V_44 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_45 , sizeof( V_45 ) ) ;
V_27 += sizeof( V_45 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_11 = F_11 ( V_10 , V_5 , sizeof( * V_46 ) , true ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_12 ) ) ;
return V_16 ;
}
memcpy ( V_46 , V_5 , sizeof( * V_46 ) ) ;
F_8 ( V_13 , ( L_25 , * V_46 ) ) ;
return 0 ;
}
int
F_20 ( struct V_9 * V_10 ,
V_4 V_46 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_46 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_46 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_26 ,
V_10 , V_46 ) ) ;
V_12 = V_48 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_46 , sizeof( V_46 ) ) ;
V_27 += sizeof( V_46 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_27 , V_46 ) ) ;
return 0 ;
}
static int
F_21 ( struct V_9 * V_10 ,
V_4 V_49 ,
V_4 * V_50 ,
V_4 V_45 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
V_4 V_26 ;
F_3 ( F_13 ( V_30 + sizeof( V_12 ) + sizeof( V_49 ) ) ) ;
memset ( V_5 , 0 , V_30 + sizeof( V_12 ) + sizeof( V_49 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_28 ,
V_10 , V_49 ) ) ;
V_12 = V_45 ? V_51 : V_52 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_49 , sizeof( V_49 ) ) ;
V_27 += sizeof( V_49 ) ;
V_26 = V_49 * sizeof( * V_50 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , V_50 , V_26 ) ;
V_27 += V_26 ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_29 ) ) ;
return 0 ;
}
int
F_22 ( struct V_9 * V_10 ,
V_4 V_49 ,
V_4 * V_50 )
{
return F_21 ( V_10 , V_49 , V_50 , 1 ) ;
}
int
F_23 ( struct V_9 * V_10 ,
V_4 V_49 ,
V_4 * V_50 )
{
return F_21 ( V_10 , V_49 , V_50 , 0 ) ;
}
int
F_24 ( struct V_9 * V_10 ,
V_6 * V_25 ,
V_4 V_26 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
V_4 V_28 , V_32 ;
const V_4 V_33 = sizeof( V_12 ) + sizeof( V_26 ) ;
F_3 ( F_13 ( V_30 + V_33 ) ) ;
memset ( V_5 , 0 , V_30 + V_33 ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_30 ,
V_10 , V_26 ) ) ;
V_12 = V_53 ;
V_28 = V_26 ;
while ( V_28 )
{
V_32 = ( V_28 < ( V_30 - V_33 ) ) ?
V_28 : ( V_30 - V_33 ) ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_32 , sizeof( V_32 ) ) ;
V_27 += sizeof( V_32 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_25 [ V_26 - V_28 ] , V_32 ) ;
V_27 += V_32 ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_3 ) ) ;
return V_16 ;
}
V_28 -= V_32 ;
}
F_8 ( V_13 , ( L_31 ) ) ;
return 0 ;
}
int
F_25 ( struct V_9 * V_10 ,
V_4 V_24 )
{
V_4 V_12 ;
int V_11 ;
V_4 V_27 ;
F_3 ( F_13 ( sizeof( V_12 ) + sizeof( V_24 ) ) ) ;
memset ( V_5 , 0 , sizeof( V_12 ) + sizeof( V_24 ) ) ;
if ( V_1 ) {
F_8 ( V_15 , ( L_5 ) ) ;
return V_16 ;
}
F_8 ( V_13 ,
( L_32 ,
V_10 , V_24 ) ) ;
V_12 = V_54 ;
V_27 = 0 ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_12 , sizeof( V_12 ) ) ;
V_27 += sizeof( V_12 ) ;
memcpy ( & ( V_5 [ V_27 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_27 += sizeof( V_24 ) ;
V_11 = F_9 ( V_10 , V_5 , V_27 ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_33 ) ) ;
return V_16 ;
}
F_8 ( V_13 , ( L_34 ) ) ;
return 0 ;
}
int
F_9 ( struct V_9 * V_10 ,
V_6 * V_25 ,
V_4 V_26 )
{
int V_11 ;
V_4 V_55 ;
V_4 V_24 ;
V_4 V_56 [ V_57 ] ;
F_26 ( V_10 , V_58 ,
& V_56 [ 0 ] , sizeof( V_56 ) ) ;
* V_3 = 0 ;
V_55 = V_59 ;
while( V_55 -- && ! ( * V_3 ) ) {
V_24 = V_60 + ( V_57 + V_61 ) * 4 ;
V_11 = F_27 ( V_10 , V_24 , ( V_6 * ) V_3 , 4 ,
V_62 , NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_35 ) ) ;
return V_16 ;
}
( * V_3 ) &= 0xFF ;
}
if ( * V_3 ) {
V_24 = V_56 [ V_61 ] ;
V_11 = F_27 ( V_10 , V_24 , V_25 , V_26 ,
V_63 , NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_36 ) ) ;
return V_16 ;
}
} else {
F_8 ( V_15 , ( L_37 ) ) ;
return V_16 ;
}
return V_11 ;
}
int
F_11 ( struct V_9 * V_10 ,
V_6 * V_25 ,
V_4 V_26 ,
bool V_64 )
{
int V_11 ;
V_4 V_24 ;
V_4 V_56 [ V_57 ] ;
struct V_65 V_66 ;
static T_1 V_67 = NULL ;
if ( ! V_2 ) {
F_26 ( V_10 ,
V_68 ,
& V_67 ,
sizeof( V_67 ) ) ;
V_2 = true ;
}
F_26 ( V_10 , V_58 ,
& V_56 [ 0 ] , sizeof( V_56 ) ) ;
if ( V_26 >= 4 ) {
static V_4 V_69 ;
V_4 V_55 ;
V_69 = 0 ;
V_55 = V_59 ;
while( ( ! V_64 || V_55 -- ) && ! V_69 ) {
if ( V_67 != NULL ) {
V_11 = V_67 ( V_10 ,
& V_66 ,
NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_38 ) ) ;
break;
}
if ( V_66 . V_70 >= sizeof( V_4 ) ) {
V_69 = 1 ;
}
continue;
}
V_11 = F_27 ( V_10 , V_71 , ( V_6 * ) & V_69 ,
sizeof( V_69 ) , V_62 , NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_39 ) ) ;
return V_16 ;
}
V_69 &= ( 1 << V_61 ) ;
}
if ( ! V_69 ) {
F_8 ( V_15 , ( L_40 ) ) ;
return V_16 ;
}
}
#define F_28 0
#if F_28
if ( ( V_26 > 4 ) && ( V_26 < 128 ) ) {
V_4 V_55 ;
* V_3 = 0 ;
V_55 = V_59 ;
while( ( ! V_64 || V_55 -- ) && ! ( * V_3 ) {
V_24 = V_72 + ( V_57 + V_61 ) * 1 ;
V_11 = F_27 ( V_10 , V_24 , ( V_6 * ) V_3 , sizeof( * V_3 ) ,
V_73 , NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_41 ) ) ;
return V_16 ;
}
( * V_3 ) &= 0xFF ;
}
if ( ! ( * V_3 ) ) {
F_8 ( V_15 , ( L_42 ) ) ;
return V_16 ;
}
}
#endif
V_24 = V_56 [ V_61 ] ;
V_11 = F_27 ( V_10 , V_24 , V_25 , V_26 , V_62 , NULL ) ;
if ( V_11 ) {
F_8 ( V_15 , ( L_43 ) ) ;
return V_16 ;
}
return 0 ;
}
int
F_29 ( struct V_9 * V_10 , V_4 V_24 , V_6 * V_25 , V_4 V_26 )
{
int V_11 = V_16 ;
V_4 V_74 = 0 ;
V_4 V_75 = V_26 & ~ 0x3 ;
V_4 V_76 = V_26 & 0x3 ;
V_11 = F_25 ( V_10 , V_24 ) ;
if ( V_11 ) {
return V_16 ;
}
if ( V_76 ) {
memcpy ( & V_74 , & V_25 [ V_75 ] , V_76 ) ;
}
V_11 = F_24 ( V_10 , V_25 , V_75 ) ;
if ( V_11 ) {
return V_16 ;
}
if ( V_76 ) {
V_11 = F_24 ( V_10 , ( V_6 * ) & V_74 , 4 ) ;
}
if ( ! V_11 ) {
V_11 = F_25 ( V_10 , 0x00 ) ;
if ( V_11 ) {
return V_16 ;
}
}
return V_11 ;
}
int
F_30 ( struct V_9 * V_10 , V_6 * V_25 , V_4 V_26 )
{
return F_9 ( V_10 , V_25 , V_26 ) ;
}
int
F_31 ( struct V_9 * V_10 , V_6 * V_25 , V_4 V_26 , bool V_64 )
{
return F_11 ( V_10 , V_25 , V_26 , V_64 ) ;
}
