T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 , T_2 type )
{
union V_3 * V_5 ;
union V_3 * V_6 ;
T_2 V_7 = V_8 ;
F_2 ( V_9 ) ;
if ( ! V_2 ) {
F_3 ( ( V_10 , L_1 ) ) ;
F_4 ( V_11 ) ;
}
if ( ! V_4 && ( V_8 != type ) ) {
F_3 ( ( V_10 ,
L_2 ) ) ;
F_4 ( V_11 ) ;
}
if ( F_5 ( V_2 ) != V_12 ) {
F_3 ( ( V_10 , L_3 ,
V_2 , F_6 ( V_2 ) ) ) ;
F_4 ( V_11 ) ;
}
if ( V_2 -> V_4 == V_4 ) {
F_7 ( ( V_13 ,
L_4 ,
V_4 , V_2 ) ) ;
F_4 ( V_14 ) ;
}
if ( ! V_4 ) {
V_5 = NULL ;
V_7 = V_8 ;
}
else if ( ( F_5 ( V_4 ) == V_12 ) &&
( (struct V_1 * ) V_4 ) -> V_4 ) {
V_5 = ( (struct V_1 * ) V_4 ) -> V_4 ;
V_7 = ( (struct V_1 * ) V_4 ) -> type ;
}
else {
V_5 = (union V_3 * ) V_4 ;
V_7 = type ;
}
F_7 ( ( V_13 , L_5 ,
V_5 , V_2 , F_8 ( V_2 ) ) ) ;
if ( V_2 -> V_4 ) {
F_9 ( V_2 ) ;
}
if ( V_5 ) {
F_10 ( V_5 ) ;
V_6 = V_5 ;
while ( V_6 -> V_15 . V_16 ) {
V_6 = V_6 -> V_15 . V_16 ;
}
V_6 -> V_15 . V_16 = V_2 -> V_4 ;
}
V_2 -> type = ( V_17 ) V_7 ;
V_2 -> V_4 = V_5 ;
F_4 ( V_14 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
union V_3 * V_5 ;
F_2 ( V_18 ) ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 || ( V_5 -> V_15 . type == V_19 ) ) {
V_20 ;
}
if ( V_2 -> V_21 & V_22 ) {
if ( V_5 -> V_15 . type == V_23 ) {
F_11 ( V_5 -> V_24 . V_25 ) ;
}
}
V_2 -> V_4 = NULL ;
if ( F_5 ( V_5 ) == V_26 ) {
V_2 -> V_4 = V_5 -> V_15 . V_16 ;
if ( V_2 -> V_4 &&
( V_2 -> V_4 -> V_15 . type != V_19 ) ) {
V_2 -> V_4 = V_2 -> V_4 -> V_15 . V_16 ;
}
}
V_2 -> type = V_8 ;
F_7 ( ( V_27 , L_6 ,
V_2 , F_8 ( V_2 ) , V_5 ) ) ;
F_12 ( V_5 ) ;
V_20 ;
}
union V_3 * F_13 ( struct
V_1
* V_2 )
{
F_14 ( V_28 , V_2 ) ;
if ( ! V_2 ) {
F_15 ( ( V_10 , L_7 ) ) ;
F_16 ( NULL ) ;
}
if ( ! V_2 -> V_4 ||
( ( F_5 ( V_2 -> V_4 ) != V_26 )
&& ( F_5 ( V_2 -> V_4 ) !=
V_12 ) )
|| ( ( V_2 -> V_4 ) -> V_15 . type == V_19 ) ) {
F_16 ( NULL ) ;
}
F_16 ( V_2 -> V_4 ) ;
}
union V_3 * F_17 ( union
V_3
* V_5 )
{
F_14 ( V_29 , V_5 ) ;
if ( ( ! V_5 ) ||
( V_5 -> V_15 . type == V_19 ) ||
( ! V_5 -> V_15 . V_16 ) ||
( ( V_5 -> V_15 . V_16 ) -> V_15 . type ==
V_19 ) ) {
F_16 ( NULL ) ;
}
F_16 ( V_5 -> V_15 . V_16 ) ;
}
T_1
F_18 ( struct V_1 * V_2 ,
T_3 V_30 , void * V_31 )
{
union V_3 * V_32 ;
union V_3 * V_5 ;
union V_3 * V_33 ;
V_32 = NULL ;
V_5 = V_2 -> V_4 ;
while ( V_5 ) {
if ( ( V_5 -> V_15 . type == V_19 ) &&
( V_5 -> V_31 . V_30 == V_30 ) ) {
return ( V_34 ) ;
}
V_32 = V_5 ;
V_5 = V_5 -> V_15 . V_16 ;
}
V_33 = F_19 ( V_19 ) ;
if ( ! V_33 ) {
return ( V_35 ) ;
}
V_33 -> V_31 . V_30 = V_30 ;
V_33 -> V_31 . V_36 = V_31 ;
if ( V_32 ) {
V_32 -> V_15 . V_16 = V_33 ;
} else {
V_2 -> V_4 = V_33 ;
}
return ( V_14 ) ;
}
T_1
F_20 ( struct V_1 * V_2 ,
T_3 V_30 )
{
union V_3 * V_5 ;
union V_3 * V_32 ;
V_32 = NULL ;
V_5 = V_2 -> V_4 ;
while ( V_5 ) {
if ( ( V_5 -> V_15 . type == V_19 ) &&
( V_5 -> V_31 . V_30 == V_30 ) ) {
if ( V_32 ) {
V_32 -> V_15 . V_16 =
V_5 -> V_15 . V_16 ;
} else {
V_2 -> V_4 = V_5 -> V_15 . V_16 ;
}
F_12 ( V_5 ) ;
return ( V_14 ) ;
}
V_32 = V_5 ;
V_5 = V_5 -> V_15 . V_16 ;
}
return ( V_37 ) ;
}
T_1
F_21 ( struct V_1 * V_2 ,
T_3 V_30 , void * * V_31 )
{
union V_3 * V_5 ;
V_5 = V_2 -> V_4 ;
while ( V_5 ) {
if ( ( V_5 -> V_15 . type == V_19 ) &&
( V_5 -> V_31 . V_30 == V_30 ) ) {
* V_31 = V_5 -> V_31 . V_36 ;
return ( V_14 ) ;
}
V_5 = V_5 -> V_15 . V_16 ;
}
return ( V_37 ) ;
}
