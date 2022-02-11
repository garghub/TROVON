void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , V_4 , L_1 ) ;
V_2 -> V_5 . V_6 = false ;
if ( V_2 -> V_7 . V_8 -> V_9 ) {
V_3 = V_2 -> V_7 . V_8 -> V_9 ( V_2 ) ;
F_2 ( V_2 , V_4 , L_2 , V_3 ) ;
}
}
int F_3 ( struct V_1 * V_2 )
{
struct V_10 V_11 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_14 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_3 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_2 ( V_2 , V_4 , L_4 ) ;
return 0 ;
}
V_2 -> V_5 . V_6 = true ;
V_11 . V_13 = F_4 ( V_15 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_5 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_20 ) ;
T_1 V_21 = sizeof( V_19 . V_20 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_6 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_7 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_23 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_19 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_8 ) ;
return V_3 ;
}
if ( V_21 < sizeof( V_19 . V_20 ) ) {
F_6 ( V_2 , L_9 ,
V_21 ) ;
return - V_24 ;
}
V_17 -> V_25 = F_8 ( V_19 . V_20 . V_25 ) ;
V_17 -> type = F_8 ( V_19 . V_20 . type ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 V_26 , void * V_27 , T_1 V_28 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_29 ) ;
T_1 V_30 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_10 ,
V_26 , V_28 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_11 ) ;
return - V_22 ;
}
while ( V_28 ) {
V_30 = F_10 ( T_1 , V_28 , V_31 ) ;
V_11 . V_13 = F_4 ( V_32 ) ;
V_11 . V_29 . V_33 = F_4 ( V_26 ) ;
V_11 . V_29 . V_34 = F_4 ( V_30 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 ,
& V_19 , & V_30 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_12 ,
V_3 ) ;
return V_3 ;
}
memcpy ( V_27 , V_19 . V_29 . V_35 , V_30 ) ;
V_26 += V_30 ;
V_27 += V_30 ;
V_28 -= V_30 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_36 )
{
struct V_10 V_11 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_37 ) ;
int V_3 ;
F_2 ( V_2 , V_4 ,
L_13 ,
V_26 , V_36 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_38 ) ;
V_11 . V_37 . V_33 = F_4 ( V_26 ) ;
V_11 . V_37 . V_39 = F_4 ( V_36 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_15 ,
V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_26 , T_1 * V_36 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_40 ) ;
T_1 V_21 = sizeof( V_19 . V_40 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_16 ,
V_26 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_17 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_41 ) ;
V_11 . V_40 . V_33 = F_4 ( V_26 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_19 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_18 ,
V_3 ) ;
return V_3 ;
}
* V_36 = F_8 ( V_19 . V_40 . V_39 ) ;
F_2 ( V_2 , V_4 , L_19 ,
* V_36 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_26 , const void * V_27 , T_1 V_28 )
{
struct V_10 V_11 ;
T_1 V_42 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_43 ) ;
T_1 V_44 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_20 ,
V_26 , V_28 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_11 ) ;
return - V_22 ;
}
while ( V_28 ) {
V_44 = F_14 ( V_28 , V_31 - V_42 ) ;
memcpy ( V_11 . V_43 . V_35 , V_27 , V_44 ) ;
V_44 = F_15 ( V_44 , 4 ) ;
V_11 . V_13 = F_4 ( V_45 ) ;
V_11 . V_43 . V_33 = F_4 ( V_26 ) ;
V_11 . V_43 . V_34 = F_4 ( V_44 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_42 + V_44 ,
NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_21 ,
V_3 ) ;
return V_3 ;
}
V_44 = F_14 ( V_44 , V_28 ) ;
V_26 += V_44 ;
V_27 += V_44 ;
V_28 -= V_44 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_46 , T_1 * V_47 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_48 ) ;
T_1 V_21 = sizeof( V_19 . V_48 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_22 ,
V_26 , V_46 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_11 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_49 ) ;
V_11 . V_48 . V_33 = F_4 ( V_26 ) ;
V_11 . V_48 . V_46 = F_4 ( V_46 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_19 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_23 ) ;
return V_3 ;
}
if ( V_21 < sizeof( V_19 . V_48 ) ) {
F_6 ( V_2 , L_24 ,
V_21 ) ;
return - V_24 ;
}
* V_47 = F_8 ( V_19 . V_48 . V_47 ) ;
F_2 ( V_2 , V_4 , L_25 , * V_47 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , const void * V_27 , T_1 V_28 )
{
struct V_10 V_11 ;
T_1 V_42 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_50 ) ;
T_1 V_44 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_26 ,
V_27 , V_28 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_11 ) ;
return - V_22 ;
}
while ( V_28 ) {
V_44 = F_14 ( V_28 , V_31 - V_42 ) ;
F_18 ( V_44 & 3 ) ;
V_11 . V_13 = F_4 ( V_51 ) ;
V_11 . V_50 . V_34 = F_4 ( V_44 ) ;
memcpy ( V_11 . V_50 . V_35 , V_27 , V_44 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_42 + V_44 ,
NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_27 ) ;
return V_3 ;
}
V_27 += V_44 ;
V_28 -= V_44 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_10 V_11 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_52 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_28 ,
V_26 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_11 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_53 ) ;
V_11 . V_52 . V_33 = F_4 ( V_26 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_29 ) ;
return V_3 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
T_1 V_26 , const void * V_27 , T_1 V_28 )
{
T_2 V_54 [ 4 ] = {} ;
T_1 V_55 = F_21 ( V_28 , 4 ) ;
T_1 V_56 = V_28 - V_55 ;
int V_3 ;
F_2 ( V_2 , V_4 ,
L_30 ,
V_26 , V_27 , V_28 ) ;
V_3 = F_19 ( V_2 , V_26 ) ;
if ( V_3 )
return V_3 ;
if ( V_56 > 0 )
memcpy ( V_54 , V_27 + V_55 , V_56 ) ;
V_3 = F_17 ( V_2 , V_27 , V_55 ) ;
if ( V_3 )
return V_3 ;
if ( V_56 > 0 )
V_3 = F_17 ( V_2 , V_54 , 4 ) ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_19 ( V_2 , 0x00 ) ;
return V_3 ;
}
