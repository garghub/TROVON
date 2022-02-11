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
struct V_13 * V_14 = NULL ;
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_18 && V_2 -> V_16 ) {
V_14 = F_5 ( V_2 -> V_16 , struct V_13 , V_17 ) ;
V_2 -> V_16 = V_14 -> V_17 . V_12 ;
V_2 -> V_18 -- ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_14 -> V_19 != V_20 ) {
F_10 ( L_1 ,
V_14 -> V_19 ) ;
}
} else {
F_9 ( & V_2 -> V_7 ) ;
V_14 = F_11 ( sizeof( struct V_13 ) , V_21 ) ;
}
if ( V_14 ) {
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
V_14 -> V_24 = NULL ;
V_14 -> V_25 = 0 ;
V_14 -> V_26 = NULL ;
V_14 -> V_19 = V_27 ;
F_2 ( & V_14 -> V_17 ) ;
F_2 ( & V_14 -> V_15 ) ;
}
return V_14 ;
}
void F_12 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
if ( V_14 ) {
if ( V_14 -> V_19 == V_27 ) {
V_2 -> V_18 ++ ;
V_14 -> V_17 . V_12 = V_2 -> V_16 ;
V_2 -> V_16 = & V_14 -> V_17 ;
V_14 -> V_19 = V_20 ;
} else {
F_10 ( L_2
L_3 ,
V_14 , V_14 -> V_19 ) ;
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
int F_14 ( struct V_1 * V_2 , T_1 V_28 , int V_29 )
{
struct V_30 * V_31 ;
F_10 ( L_4 , V_28 ) ;
V_31 = F_15 ( sizeof( struct V_30 ) , V_21 | V_32 ) ;
if ( V_31 == NULL )
return - V_33 ;
F_16 ( & V_31 -> V_34 , 1 ) ;
V_31 -> V_28 = V_28 ;
V_31 -> V_29 = V_29 ;
F_2 ( & V_31 -> V_35 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_17 ( & V_31 -> V_17 , & V_2 -> V_3 ) ;
F_9 ( & V_2 -> V_7 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_8 * V_9 ;
struct V_30 * V_31 = NULL ;
F_10 ( L_5 , V_28 ) ;
F_8 ( & V_2 -> V_7 ) ;
V_9 = V_2 -> V_3 . V_12 ;
while ( V_9 != & V_2 -> V_3 ) {
V_31 = F_5 ( V_9 , struct V_30 , V_17 ) ;
if ( V_31 -> V_28 == V_28 ) {
F_19 ( V_9 ) ;
break;
}
V_31 = NULL ;
}
if ( ! V_31 ) {
F_9 ( & V_2 -> V_7 ) ;
return - 1 ;
}
V_9 = V_31 -> V_35 . V_12 ;
while ( V_9 != & V_31 -> V_35 ) {
struct V_13 * V_14 =
F_5 ( V_9 , struct V_13 , V_17 ) ;
V_9 = V_9 -> V_12 ;
F_20 ( & V_14 -> V_17 ) ;
F_20 ( & V_14 -> V_15 ) ;
V_31 -> V_36 -= V_14 -> V_37 ;
F_21 ( V_38 , L_6 ,
V_31 -> V_36 ,
V_14 -> V_37 , F_22 ( & V_31 -> V_34 ) ) ;
F_23 ( V_31 ) ;
F_12 ( V_2 , V_14 ) ;
}
F_9 ( & V_2 -> V_7 ) ;
F_23 ( V_31 ) ;
return 0 ;
}
void F_24 ( struct V_30 * V_31 )
{
F_25 ( & V_31 -> V_34 ) ;
}
void F_23 ( struct V_30 * V_31 )
{
if ( F_26 ( & V_31 -> V_34 ) ) {
F_10 ( L_7 ) ;
F_6 ( V_31 ) ;
}
}
int F_27 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_28 ,
struct V_13 * V_14 )
{
struct V_30 * V_31 = NULL ;
struct V_8 * V_9 ;
if ( V_28 ) {
F_28 (e, &buf->stream_list) {
V_31 = F_5 ( V_9 , struct V_30 , V_17 ) ;
if ( V_31 -> V_28 == V_28 )
break;
}
if ( V_9 == & V_2 -> V_3 ) {
return - 1 ;
}
}
if ( V_31 ) {
struct V_40 * V_41 = (struct V_40 * )
& V_14 -> V_42 [ sizeof( struct V_43 ) ] ;
if ( ( V_41 -> V_23 == V_44 ) && ( V_41 -> type
== V_45 ) &&
( V_41 -> V_46 == V_47 ) ) {
T_1 V_48 = V_41 -> V_49 ;
V_41 -> V_49 = V_31 -> V_49 ;
V_31 -> V_49 += V_48 ;
}
F_24 ( V_31 ) ;
V_14 -> V_26 = V_31 ;
V_31 -> V_36 += V_14 -> V_37 ;
F_17 ( & V_14 -> V_17 , & V_31 -> V_35 ) ;
F_21 ( V_38 , L_8 ,
V_31 -> V_36 , V_14 -> V_37 ) ;
while ( ( V_31 -> V_36 > V_31 -> V_29 ) &&
! F_29 ( & V_31 -> V_35 ) ) {
struct V_13 * V_50 =
F_30 ( & V_31 -> V_35 ,
struct V_13 , V_17 ) ;
F_20 ( & V_50 -> V_17 ) ;
F_20 ( & V_50 -> V_15 ) ;
V_31 -> V_36 -= V_50 -> V_37 ;
F_12 ( V_2 , V_50 ) ;
F_23 ( V_31 ) ;
}
}
F_17 ( & V_14 -> V_15 , V_39 ?
& V_2 -> V_5 : & V_2 -> V_4 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_39 , unsigned * V_51 ,
unsigned V_52 , struct V_8 * V_11 )
{
int V_53 = 0 ;
struct V_8 * V_9 ;
struct V_8 * V_54 ;
struct V_13 * V_14 ;
F_8 ( & V_2 -> V_7 ) ;
if ( V_39 )
V_54 = & V_2 -> V_5 ;
else
V_54 = & V_2 -> V_4 ;
V_9 = V_54 -> V_12 ;
while ( V_9 != V_54 ) {
struct V_55 * V_56 ;
V_14 = F_5 ( V_9 , struct V_13 , V_15 ) ;
V_9 = V_9 -> V_12 ;
if ( ( * V_51 + V_14 -> V_37 ) <= V_52 ) {
V_56 = (struct V_55 * )
& V_14 -> V_42 [ sizeof( struct V_43 ) ] ;
V_56 -> V_57 = V_2 -> V_58 [ V_14 -> V_23 ] ++ ;
if ( V_2 -> V_58 [ V_14 -> V_23 ] == 0 )
V_2 -> V_58 [ V_14 -> V_23 ] = 1 ;
* V_51 += V_14 -> V_37 ;
F_19 ( & V_14 -> V_17 ) ;
F_19 ( & V_14 -> V_15 ) ;
if ( V_14 -> V_26 ) {
V_14 -> V_26 -> V_36 -= V_14 -> V_37 ;
F_21 ( V_38 ,
L_9 ,
V_14 -> V_26 -> V_36 , V_14 -> V_37 ) ;
F_23 ( V_14 -> V_26 ) ;
V_14 -> V_26 = NULL ;
}
F_2 ( & V_14 -> V_15 ) ;
F_17 ( & V_14 -> V_17 , V_11 ) ;
V_53 ++ ;
} else {
break;
}
}
F_9 ( & V_2 -> V_7 ) ;
return V_53 ;
}
int F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_12 != & V_2 -> V_4 ;
}
void F_33 ( struct V_1 * V_2 )
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
