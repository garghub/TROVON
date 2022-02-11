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
struct V_16 * V_17 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_20 ) ;
T_1 V_21 , V_26 ;
T_2 V_27 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_10 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_7 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_23 ) ;
V_21 = sizeof( T_1 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_27 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_11 ) ;
return V_3 ;
}
if ( F_8 ( V_27 ) == V_28 ) {
V_21 = sizeof( T_1 ) ;
V_3 = F_5 ( V_2 , NULL , 0 , & V_27 ,
& V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_11 ) ;
return V_3 ;
}
}
V_26 = F_8 ( V_27 ) ;
if ( V_26 != sizeof( V_19 . V_20 ) ) {
F_6 ( V_2 , L_12 ,
V_26 , sizeof( V_19 . V_20 ) ) ;
return - V_29 ;
}
V_21 = sizeof( V_19 . V_20 ) - sizeof( T_1 ) ;
V_3 = F_5 ( V_2 , NULL , 0 ,
& V_19 . V_20 . V_25 ,
& V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_11 ) ;
return V_3 ;
}
V_17 -> V_25 = F_8 ( V_19 . V_20 . V_25 ) ;
V_17 -> type = F_8 ( V_19 . V_20 . type ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
T_1 V_30 , void * V_31 , T_1 V_32 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_33 ) ;
T_1 V_34 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_13 ,
V_30 , V_32 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
while ( V_32 ) {
V_34 = F_11 ( T_1 , V_32 , V_35 ) ;
V_11 . V_13 = F_4 ( V_36 ) ;
V_11 . V_33 . V_37 = F_4 ( V_30 ) ;
V_11 . V_33 . V_38 = F_4 ( V_34 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 ,
& V_19 , & V_34 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_15 ,
V_3 ) ;
return V_3 ;
}
memcpy ( V_31 , V_19 . V_33 . V_39 , V_34 ) ;
V_30 += V_34 ;
V_31 += V_34 ;
V_32 -= V_34 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_30 , T_1 V_40 )
{
struct V_10 V_11 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_41 ) ;
int V_3 ;
F_2 ( V_2 , V_4 ,
L_16 ,
V_30 , V_40 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_17 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_42 ) ;
V_11 . V_41 . V_37 = F_4 ( V_30 ) ;
V_11 . V_41 . V_43 = F_4 ( V_40 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_18 ,
V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_30 , T_1 * V_40 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_44 ) ;
T_1 V_21 = sizeof( V_19 . V_44 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_19 ,
V_30 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_20 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_45 ) ;
V_11 . V_44 . V_37 = F_4 ( V_30 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_19 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_21 ,
V_3 ) ;
return V_3 ;
}
* V_40 = F_8 ( V_19 . V_44 . V_43 ) ;
F_2 ( V_2 , V_4 , L_22 ,
* V_40 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
T_1 V_30 , const void * V_31 , T_1 V_32 )
{
struct V_10 V_11 ;
T_1 V_46 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_47 ) ;
T_1 V_48 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_23 ,
V_30 , V_32 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
while ( V_32 ) {
V_48 = F_15 ( V_32 , V_35 - V_46 ) ;
memcpy ( V_11 . V_47 . V_39 , V_31 , V_48 ) ;
V_48 = F_16 ( V_48 , 4 ) ;
V_11 . V_13 = F_4 ( V_49 ) ;
V_11 . V_47 . V_37 = F_4 ( V_30 ) ;
V_11 . V_47 . V_38 = F_4 ( V_48 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_46 + V_48 ,
NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_24 ,
V_3 ) ;
return V_3 ;
}
V_48 = F_15 ( V_48 , V_32 ) ;
V_30 += V_48 ;
V_31 += V_48 ;
V_32 -= V_48 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_30 , T_1 V_50 , T_1 * V_51 )
{
struct V_10 V_11 ;
union V_18 V_19 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_52 ) ;
T_1 V_21 = sizeof( V_19 . V_52 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_25 ,
V_30 , V_50 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_53 ) ;
V_11 . V_52 . V_37 = F_4 ( V_30 ) ;
V_11 . V_52 . V_50 = F_4 ( V_50 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , & V_19 , & V_21 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_26 ) ;
return V_3 ;
}
if ( V_21 < sizeof( V_19 . V_52 ) ) {
F_6 ( V_2 , L_27 ,
V_21 ) ;
return - V_24 ;
}
* V_51 = F_8 ( V_19 . V_52 . V_51 ) ;
F_2 ( V_2 , V_4 , L_28 , * V_51 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , const void * V_31 , T_1 V_32 )
{
struct V_10 V_11 ;
T_1 V_46 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_54 ) ;
T_1 V_48 ;
int V_3 ;
F_2 ( V_2 , V_4 , L_29 ,
V_31 , V_32 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
while ( V_32 ) {
V_48 = F_15 ( V_32 , V_35 - V_46 ) ;
F_19 ( V_48 & 3 ) ;
V_11 . V_13 = F_4 ( V_55 ) ;
V_11 . V_54 . V_38 = F_4 ( V_48 ) ;
memcpy ( V_11 . V_54 . V_39 , V_31 , V_48 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_46 + V_48 ,
NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_30 ) ;
return V_3 ;
}
V_31 += V_48 ;
V_32 -= V_48 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_10 V_11 ;
T_1 V_12 = sizeof( V_11 . V_13 ) + sizeof( V_11 . V_56 ) ;
int V_3 ;
F_2 ( V_2 , V_4 , L_31 ,
V_30 ) ;
if ( V_2 -> V_5 . V_6 ) {
F_6 ( V_2 , L_14 ) ;
return - V_22 ;
}
V_11 . V_13 = F_4 ( V_57 ) ;
V_11 . V_56 . V_37 = F_4 ( V_30 ) ;
V_3 = F_5 ( V_2 , & V_11 , V_12 , NULL , NULL ) ;
if ( V_3 ) {
F_6 ( V_2 , L_32 ) ;
return V_3 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_30 , const void * V_31 , T_1 V_32 )
{
T_3 V_58 [ 4 ] = {} ;
T_1 V_59 = F_22 ( V_32 , 4 ) ;
T_1 V_60 = V_32 - V_59 ;
int V_3 ;
F_2 ( V_2 , V_4 ,
L_33 ,
V_30 , V_31 , V_32 ) ;
V_3 = F_20 ( V_2 , V_30 ) ;
if ( V_3 )
return V_3 ;
if ( V_60 > 0 )
memcpy ( V_58 , V_31 + V_59 , V_60 ) ;
V_3 = F_18 ( V_2 , V_31 , V_59 ) ;
if ( V_3 )
return V_3 ;
if ( V_60 > 0 )
V_3 = F_18 ( V_2 , V_58 , 4 ) ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_20 ( V_2 , 0x00 ) ;
return V_3 ;
}
