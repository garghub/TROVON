void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , L_1 ) ;
V_2 -> V_4 . V_5 = false ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_10 ) ;
int V_11 ;
F_2 ( V_2 , V_3 , L_2 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_2 ( V_2 , V_3 , L_3 ) ;
return 0 ;
}
V_2 -> V_4 . V_5 = true ;
V_7 . V_9 = F_4 ( V_12 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , NULL , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 , L_4 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 V_7 ;
union V_15 V_16 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_17 ) ;
T_1 V_18 = sizeof( V_16 . V_17 ) ;
int V_11 ;
F_2 ( V_2 , V_3 , L_5 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_6 ) ;
return - V_19 ;
}
V_7 . V_9 = F_4 ( V_20 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , & V_16 , & V_18 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_7 ) ;
return V_11 ;
}
if ( V_18 < sizeof( V_16 . V_17 ) ) {
F_6 ( V_2 , L_8 ,
V_18 ) ;
return - V_21 ;
}
V_14 -> V_22 = F_8 ( V_16 . V_17 . V_22 ) ;
V_14 -> type = F_8 ( V_16 . V_17 . type ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 V_23 , void * V_24 , T_1 V_25 )
{
struct V_6 V_7 ;
union V_15 V_16 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_26 ) ;
T_1 V_27 ;
int V_11 ;
F_2 ( V_2 , V_3 , L_9 ,
V_23 , V_25 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_10 ) ;
return - V_19 ;
}
while ( V_25 ) {
V_27 = F_10 ( T_1 , V_25 , V_28 ) ;
V_7 . V_9 = F_4 ( V_29 ) ;
V_7 . V_26 . V_30 = F_4 ( V_23 ) ;
V_7 . V_26 . V_31 = F_4 ( V_27 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 ,
& V_16 , & V_27 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_11 ,
V_11 ) ;
return V_11 ;
}
memcpy ( V_24 , V_16 . V_26 . V_32 , V_27 ) ;
V_23 += V_27 ;
V_24 += V_27 ;
V_25 -= V_27 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_23 , const void * V_24 , T_1 V_25 )
{
struct V_6 V_7 ;
T_1 V_33 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_34 ) ;
T_1 V_35 ;
int V_11 ;
F_2 ( V_2 , V_3 , L_12 ,
V_23 , V_25 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_10 ) ;
return - V_19 ;
}
while ( V_25 ) {
V_35 = F_12 ( V_25 , V_28 - V_33 ) ;
memcpy ( V_7 . V_34 . V_32 , V_24 , V_35 ) ;
V_35 = F_13 ( V_35 , 4 ) ;
V_7 . V_9 = F_4 ( V_36 ) ;
V_7 . V_34 . V_30 = F_4 ( V_23 ) ;
V_7 . V_34 . V_31 = F_4 ( V_35 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_33 + V_35 ,
NULL , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 , L_13 ,
V_11 ) ;
return V_11 ;
}
V_35 = F_12 ( V_35 , V_25 ) ;
V_23 += V_35 ;
V_24 += V_35 ;
V_25 -= V_35 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_37 , T_1 * V_38 )
{
struct V_6 V_7 ;
union V_15 V_16 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_39 ) ;
T_1 V_18 = sizeof( V_16 . V_39 ) ;
int V_11 ;
F_2 ( V_2 , V_3 , L_14 ,
V_23 , V_37 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_7 . V_9 = F_4 ( V_40 ) ;
V_7 . V_39 . V_30 = F_4 ( V_23 ) ;
V_7 . V_39 . V_37 = F_4 ( V_37 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , & V_16 , & V_18 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_15 ) ;
return V_11 ;
}
if ( V_18 < sizeof( V_16 . V_39 ) ) {
F_6 ( V_2 , L_16 ,
V_18 ) ;
return - V_21 ;
}
* V_38 = F_8 ( V_16 . V_39 . V_38 ) ;
F_2 ( V_2 , V_3 , L_17 , * V_38 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , const void * V_24 , T_1 V_25 )
{
struct V_6 V_7 ;
T_1 V_33 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_41 ) ;
T_1 V_35 ;
int V_11 ;
F_2 ( V_2 , V_3 , L_18 ,
V_24 , V_25 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_10 ) ;
return - V_19 ;
}
while ( V_25 ) {
V_35 = F_12 ( V_25 , V_28 - V_33 ) ;
F_16 ( V_35 & 3 ) ;
V_7 . V_9 = F_4 ( V_42 ) ;
V_7 . V_41 . V_31 = F_4 ( V_35 ) ;
memcpy ( V_7 . V_41 . V_32 , V_24 , V_35 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_33 + V_35 ,
NULL , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 , L_19 ) ;
return V_11 ;
}
V_24 += V_35 ;
V_25 -= V_35 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_6 V_7 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_43 ) ;
int V_11 ;
F_2 ( V_2 , V_3 , L_20 ,
V_23 ) ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( V_2 , L_10 ) ;
return - V_19 ;
}
V_7 . V_9 = F_4 ( V_44 ) ;
V_7 . V_43 . V_30 = F_4 ( V_23 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , NULL , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 , L_21 ) ;
return V_11 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
T_1 V_23 , const void * V_24 , T_1 V_25 )
{
T_2 V_45 [ 4 ] = {} ;
T_1 V_46 = F_19 ( V_25 , 4 ) ;
T_1 V_47 = V_25 - V_46 ;
int V_11 ;
F_2 ( V_2 , V_3 ,
L_22 ,
V_23 , V_24 , V_25 ) ;
V_11 = F_17 ( V_2 , V_23 ) ;
if ( V_11 )
return V_11 ;
if ( V_47 > 0 )
memcpy ( V_45 , V_24 + V_46 , V_47 ) ;
V_11 = F_15 ( V_2 , V_24 , V_46 ) ;
if ( V_11 )
return V_11 ;
if ( V_47 > 0 )
V_11 = F_15 ( V_2 , V_45 , 4 ) ;
if ( V_11 != 0 )
return V_11 ;
V_11 = F_17 ( V_2 , 0x00 ) ;
return V_11 ;
}
