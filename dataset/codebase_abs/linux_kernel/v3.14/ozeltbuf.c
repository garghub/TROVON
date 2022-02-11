int F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = 32 ;
F_3 ( & V_2 -> V_7 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
struct V_8 * V_11 ;
if ( V_10 )
V_11 = & V_2 -> V_4 ;
else
V_11 = & V_2 -> V_5 ;
V_9 = V_11 -> V_12 ;
while ( V_9 != V_11 ) {
struct V_13 * V_14 =
F_5 ( V_9 , struct V_13 , V_15 ) ;
V_9 = V_9 -> V_12 ;
F_6 ( V_14 ) ;
}
}
while ( V_2 -> V_16 ) {
struct V_13 * V_14 =
F_5 ( V_2 -> V_16 , struct V_13 , V_17 ) ;
V_2 -> V_16 = V_2 -> V_16 -> V_12 ;
F_6 ( V_14 ) ;
}
V_2 -> V_18 = 0 ;
}
struct V_13 * F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_18 && V_2 -> V_16 ) {
V_14 = F_5 ( V_2 -> V_16 , struct V_13 , V_17 ) ;
V_2 -> V_16 = V_14 -> V_17 . V_12 ;
V_2 -> V_18 -- ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_14 -> V_19 != V_20 ) {
F_10 ( V_21 , L_1 ,
V_22 , V_14 -> V_19 ) ;
}
} else {
F_9 ( & V_2 -> V_7 ) ;
V_14 = F_11 ( sizeof( struct V_13 ) , V_23 ) ;
}
if ( V_14 ) {
V_14 -> V_24 = 0 ;
V_14 -> V_25 = 0 ;
V_14 -> V_26 = NULL ;
V_14 -> V_27 = 0 ;
V_14 -> V_28 = NULL ;
V_14 -> V_19 = V_29 ;
F_2 ( & V_14 -> V_17 ) ;
F_2 ( & V_14 -> V_15 ) ;
}
return V_14 ;
}
void F_12 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
if ( V_14 ) {
if ( V_14 -> V_19 == V_29 ) {
V_2 -> V_18 ++ ;
V_14 -> V_17 . V_12 = V_2 -> V_16 ;
V_2 -> V_16 = & V_14 -> V_17 ;
V_14 -> V_19 = V_20 ;
} else {
F_10 ( V_21 , L_2 ,
V_22 , V_14 , V_14 -> V_19 ) ;
}
}
}
void F_13 ( struct V_1 * V_2 , struct V_8 * V_11 )
{
struct V_8 * V_9 ;
V_9 = V_11 -> V_12 ;
F_8 ( & V_2 -> V_7 ) ;
while ( V_9 != V_11 ) {
struct V_13 * V_14 ;
V_14 = F_5 ( V_9 , struct V_13 , V_17 ) ;
V_9 = V_9 -> V_12 ;
F_12 ( V_2 , V_14 ) ;
}
F_9 ( & V_2 -> V_7 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_30 , int V_31 )
{
struct V_32 * V_33 ;
F_10 ( V_21 , L_3 , V_22 , V_30 ) ;
V_33 = F_15 ( sizeof( struct V_32 ) , V_23 ) ;
if ( V_33 == NULL )
return - V_34 ;
F_16 ( & V_33 -> V_35 , 1 ) ;
V_33 -> V_30 = V_30 ;
V_33 -> V_31 = V_31 ;
F_2 ( & V_33 -> V_36 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_17 ( & V_33 -> V_17 , & V_2 -> V_3 ) ;
F_9 ( & V_2 -> V_7 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_8 * V_9 ;
struct V_32 * V_33 = NULL ;
F_10 ( V_21 , L_3 , V_22 , V_30 ) ;
F_8 ( & V_2 -> V_7 ) ;
V_9 = V_2 -> V_3 . V_12 ;
while ( V_9 != & V_2 -> V_3 ) {
V_33 = F_5 ( V_9 , struct V_32 , V_17 ) ;
if ( V_33 -> V_30 == V_30 ) {
F_19 ( V_9 ) ;
break;
}
V_33 = NULL ;
}
if ( ! V_33 ) {
F_9 ( & V_2 -> V_7 ) ;
return - 1 ;
}
V_9 = V_33 -> V_36 . V_12 ;
while ( V_9 != & V_33 -> V_36 ) {
struct V_13 * V_14 =
F_5 ( V_9 , struct V_13 , V_17 ) ;
V_9 = V_9 -> V_12 ;
F_20 ( & V_14 -> V_17 ) ;
F_20 ( & V_14 -> V_15 ) ;
V_33 -> V_37 -= V_14 -> V_38 ;
F_10 ( V_39 , L_4 ,
V_33 -> V_37 , V_14 -> V_38 , F_21 ( & V_33 -> V_35 ) ) ;
F_22 ( V_33 ) ;
F_12 ( V_2 , V_14 ) ;
}
F_9 ( & V_2 -> V_7 ) ;
F_22 ( V_33 ) ;
return 0 ;
}
void F_23 ( struct V_32 * V_33 )
{
F_24 ( & V_33 -> V_35 ) ;
}
void F_22 ( struct V_32 * V_33 )
{
if ( F_25 ( & V_33 -> V_35 ) ) {
F_10 ( V_21 , L_5 ) ;
F_6 ( V_33 ) ;
}
}
int F_26 ( struct V_1 * V_2 , T_1 V_40 , T_1 V_30 ,
struct V_13 * V_14 )
{
struct V_32 * V_33 = NULL ;
struct V_8 * V_9 ;
if ( V_30 ) {
F_27 (e, &buf->stream_list) {
V_33 = F_5 ( V_9 , struct V_32 , V_17 ) ;
if ( V_33 -> V_30 == V_30 )
break;
}
if ( V_9 == & V_2 -> V_3 ) {
return - 1 ;
}
}
if ( V_33 ) {
struct V_41 * V_42 = (struct V_41 * )
& V_14 -> V_43 [ sizeof( struct V_44 ) ] ;
if ( ( V_42 -> V_25 == V_45 ) && ( V_42 -> type
== V_46 ) &&
( V_42 -> V_47 == V_48 ) ) {
T_1 V_49 = V_42 -> V_50 ;
V_42 -> V_50 = V_33 -> V_50 ;
V_33 -> V_50 += V_49 ;
}
F_23 ( V_33 ) ;
V_14 -> V_28 = V_33 ;
V_33 -> V_37 += V_14 -> V_38 ;
F_17 ( & V_14 -> V_17 , & V_33 -> V_36 ) ;
F_10 ( V_39 , L_6 , V_33 -> V_37 , V_14 -> V_38 ) ;
while ( ( V_33 -> V_37 > V_33 -> V_31 ) &&
! F_28 ( & V_33 -> V_36 ) ) {
struct V_13 * V_51 =
F_29 ( & V_33 -> V_36 ,
struct V_13 , V_17 ) ;
F_20 ( & V_51 -> V_17 ) ;
F_20 ( & V_51 -> V_15 ) ;
V_33 -> V_37 -= V_51 -> V_38 ;
F_12 ( V_2 , V_51 ) ;
F_22 ( V_33 ) ;
}
}
F_17 ( & V_14 -> V_15 , V_40 ?
& V_2 -> V_5 : & V_2 -> V_4 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_40 , unsigned * V_52 ,
unsigned V_53 , struct V_8 * V_11 )
{
int V_54 = 0 ;
struct V_8 * V_9 ;
struct V_8 * V_55 ;
struct V_13 * V_14 ;
F_8 ( & V_2 -> V_7 ) ;
if ( V_40 )
V_55 = & V_2 -> V_5 ;
else
V_55 = & V_2 -> V_4 ;
V_9 = V_55 -> V_12 ;
while ( V_9 != V_55 ) {
struct V_56 * V_57 ;
V_14 = F_5 ( V_9 , struct V_13 , V_15 ) ;
V_9 = V_9 -> V_12 ;
if ( ( * V_52 + V_14 -> V_38 ) <= V_53 ) {
V_57 = (struct V_56 * )
& V_14 -> V_43 [ sizeof( struct V_44 ) ] ;
V_57 -> V_58 = V_2 -> V_59 [ V_14 -> V_25 ] ++ ;
if ( V_2 -> V_59 [ V_14 -> V_25 ] == 0 )
V_2 -> V_59 [ V_14 -> V_25 ] = 1 ;
* V_52 += V_14 -> V_38 ;
F_19 ( & V_14 -> V_17 ) ;
F_19 ( & V_14 -> V_15 ) ;
if ( V_14 -> V_28 ) {
V_14 -> V_28 -> V_37 -= V_14 -> V_38 ;
F_10 ( V_39 , L_7 ,
V_14 -> V_28 -> V_37 , V_14 -> V_38 ) ;
F_22 ( V_14 -> V_28 ) ;
V_14 -> V_28 = NULL ;
}
F_2 ( & V_14 -> V_15 ) ;
F_17 ( & V_14 -> V_17 , V_11 ) ;
V_54 ++ ;
} else {
break;
}
}
F_9 ( & V_2 -> V_7 ) ;
return V_54 ;
}
int F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_12 != & V_2 -> V_4 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_8 * free = NULL ;
struct V_8 * V_9 ;
F_8 ( & V_2 -> V_7 ) ;
while ( V_2 -> V_18 > V_2 -> V_6 ) {
V_9 = V_2 -> V_16 ;
V_2 -> V_16 = V_9 -> V_12 ;
V_9 -> V_12 = free ;
free = V_9 ;
V_2 -> V_18 -- ;
}
F_9 ( & V_2 -> V_7 ) ;
while ( free ) {
struct V_13 * V_14 =
F_5 ( free , struct V_13 , V_17 ) ;
free = free -> V_12 ;
F_6 ( V_14 ) ;
}
}
