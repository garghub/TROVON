void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 ) ;
V_2 -> V_4 . V_5 = false ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_10 ) ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_2 ( V_3 , L_2 , V_12 ) ;
return 0 ;
}
V_2 -> V_4 . V_5 = true ;
V_7 . V_9 = F_4 ( V_13 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , NULL , NULL ) ;
if ( V_11 ) {
F_6 ( L_3 , V_11 ) ;
return V_11 ;
}
F_2 ( V_3 , L_4 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_6 V_7 ;
union V_16 V_17 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_18 ) ;
T_1 V_19 = sizeof( V_17 . V_18 ) ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_5 ) ;
return - V_20 ;
}
V_7 . V_9 = F_4 ( V_21 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , & V_17 , & V_19 ) ;
if ( V_11 ) {
F_6 ( L_6 ) ;
return V_11 ;
}
if ( V_19 < sizeof( V_17 . V_18 ) ) {
F_6 ( L_7 ,
V_19 ) ;
return - V_22 ;
}
V_15 -> V_23 = F_8 ( V_17 . V_18 . V_23 ) ;
V_15 -> type = F_8 ( V_17 . V_18 . type ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 V_24 , void * V_25 , T_1 V_26 )
{
struct V_6 V_7 ;
union V_16 V_17 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_27 ) ;
T_1 V_28 ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_8 ) ;
return - V_20 ;
}
F_2 ( V_3 ,
L_9 ,
V_12 , V_2 , V_24 , V_26 ) ;
while ( V_26 ) {
V_28 = F_10 ( T_1 , V_26 , V_29 ) ;
V_7 . V_9 = F_4 ( V_30 ) ;
V_7 . V_27 . V_31 = F_4 ( V_24 ) ;
V_7 . V_27 . V_32 = F_4 ( V_28 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 ,
& V_17 , & V_28 ) ;
if ( V_11 ) {
F_6 ( L_10 ,
V_11 ) ;
return V_11 ;
}
memcpy ( V_25 , V_17 . V_27 . V_33 , V_28 ) ;
V_24 += V_28 ;
V_25 += V_28 ;
V_26 -= V_28 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_24 , const void * V_25 , T_1 V_26 )
{
struct V_6 V_7 ;
T_1 V_34 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_35 ) ;
T_1 V_36 ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_8 ) ;
return - V_20 ;
}
F_2 ( V_3 ,
L_9 ,
V_12 , V_2 , V_24 , V_26 ) ;
while ( V_26 ) {
V_36 = F_12 ( V_26 , V_29 - V_34 ) ;
memcpy ( V_7 . V_35 . V_33 , V_25 , V_36 ) ;
V_36 = F_13 ( V_36 , 4 ) ;
V_7 . V_9 = F_4 ( V_37 ) ;
V_7 . V_35 . V_31 = F_4 ( V_24 ) ;
V_7 . V_35 . V_32 = F_4 ( V_36 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_34 + V_36 ,
NULL , NULL ) ;
if ( V_11 ) {
F_6 ( L_11 ,
V_11 ) ;
return V_11 ;
}
V_36 = F_12 ( V_36 , V_26 ) ;
V_24 += V_36 ;
V_25 += V_36 ;
V_26 -= V_36 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_24 , T_1 * V_38 )
{
struct V_6 V_7 ;
union V_16 V_17 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_39 ) ;
T_1 V_19 = sizeof( V_17 . V_39 ) ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_8 ) ;
return - V_20 ;
}
F_2 ( V_3 ,
L_12 ,
V_12 , V_2 , V_24 , * V_38 ) ;
V_7 . V_9 = F_4 ( V_40 ) ;
V_7 . V_39 . V_31 = F_4 ( V_24 ) ;
V_7 . V_39 . V_38 = F_4 ( * V_38 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , & V_17 , & V_19 ) ;
if ( V_11 ) {
F_6 ( L_13 ) ;
return V_11 ;
}
if ( V_19 < sizeof( V_17 . V_39 ) ) {
F_6 ( L_14 ,
V_19 ) ;
return V_11 ;
}
* V_38 = F_8 ( V_17 . V_39 . V_41 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , const void * V_25 , T_1 V_26 )
{
struct V_6 V_7 ;
T_1 V_34 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_42 ) ;
T_1 V_36 ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_8 ) ;
return - V_20 ;
}
while ( V_26 ) {
V_36 = F_12 ( V_26 , V_29 - V_34 ) ;
F_16 ( V_36 & 3 ) ;
V_7 . V_9 = F_4 ( V_43 ) ;
V_7 . V_42 . V_32 = F_4 ( V_36 ) ;
memcpy ( V_7 . V_42 . V_33 , V_25 , V_36 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_34 + V_36 ,
NULL , NULL ) ;
if ( V_11 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
V_25 += V_36 ;
V_26 -= V_36 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_6 V_7 ;
T_1 V_8 = sizeof( V_7 . V_9 ) + sizeof( V_7 . V_44 ) ;
int V_11 ;
if ( V_2 -> V_4 . V_5 ) {
F_6 ( L_8 ) ;
return - V_20 ;
}
V_7 . V_9 = F_4 ( V_45 ) ;
V_7 . V_44 . V_31 = F_4 ( V_24 ) ;
V_11 = F_5 ( V_2 , & V_7 , V_8 , NULL , NULL ) ;
if ( V_11 ) {
F_6 ( L_16 ) ;
return V_11 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
T_1 V_24 , const void * V_25 , T_1 V_26 )
{
T_2 V_46 [ 4 ] = {} ;
T_1 V_47 = F_19 ( V_26 , 4 ) ;
T_1 V_48 = V_26 - V_47 ;
int V_11 ;
V_11 = F_17 ( V_2 , V_24 ) ;
if ( V_11 )
return V_11 ;
if ( V_48 > 0 )
memcpy ( V_46 , V_25 + V_47 , V_48 ) ;
V_11 = F_15 ( V_2 , V_25 , V_47 ) ;
if ( V_11 )
return V_11 ;
if ( V_48 > 0 )
V_11 = F_15 ( V_2 , V_46 , 4 ) ;
if ( V_11 != 0 )
return V_11 ;
V_11 = F_17 ( V_2 , 0x00 ) ;
return V_11 ;
}
