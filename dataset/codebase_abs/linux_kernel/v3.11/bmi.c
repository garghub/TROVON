int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
T_1 V_5 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_7 ) ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_2 ( V_11 , L_1 , V_12 ) ;
return 0 ;
}
V_2 -> V_9 . V_10 = true ;
V_4 . V_6 = F_3 ( V_13 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_5 , NULL , NULL ) ;
if ( V_8 ) {
F_5 ( L_2 , V_8 ) ;
return V_8 ;
}
F_2 ( V_11 , L_3 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 V_4 ;
union V_16 V_17 ;
T_1 V_5 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_18 ) ;
T_1 V_19 = sizeof( V_17 . V_18 ) ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_4 ) ;
return - V_20 ;
}
V_4 . V_6 = F_3 ( V_21 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_5 , & V_17 , & V_19 ) ;
if ( V_8 ) {
F_5 ( L_5 ) ;
return V_8 ;
}
if ( V_19 < sizeof( V_17 . V_18 ) ) {
F_5 ( L_6 ,
V_19 ) ;
return - V_22 ;
}
V_15 -> V_23 = F_7 ( V_17 . V_18 . V_23 ) ;
V_15 -> type = F_7 ( V_17 . V_18 . type ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
T_1 V_24 , void * V_25 , T_1 V_26 )
{
struct V_3 V_4 ;
union V_16 V_17 ;
T_1 V_5 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_27 ) ;
T_1 V_28 ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_7 ) ;
return - V_20 ;
}
F_2 ( V_11 ,
L_8 ,
V_12 , V_2 , V_24 , V_26 ) ;
while ( V_26 ) {
V_28 = F_9 ( T_1 , V_26 , V_29 ) ;
V_4 . V_6 = F_3 ( V_30 ) ;
V_4 . V_27 . V_31 = F_3 ( V_24 ) ;
V_4 . V_27 . V_32 = F_3 ( V_28 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_5 ,
& V_17 , & V_28 ) ;
if ( V_8 ) {
F_5 ( L_9 ) ;
return V_8 ;
}
memcpy ( V_25 , V_17 . V_27 . V_33 , V_28 ) ;
V_24 += V_28 ;
V_25 += V_28 ;
V_26 -= V_28 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
T_1 V_24 , const void * V_25 , T_1 V_26 )
{
struct V_3 V_4 ;
T_1 V_34 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_35 ) ;
T_1 V_36 ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_7 ) ;
return - V_20 ;
}
F_2 ( V_11 ,
L_8 ,
V_12 , V_2 , V_24 , V_26 ) ;
while ( V_26 ) {
V_36 = F_11 ( V_26 , V_29 - V_34 ) ;
memcpy ( V_4 . V_35 . V_33 , V_25 , V_36 ) ;
V_36 = F_12 ( V_36 , 4 ) ;
V_4 . V_6 = F_3 ( V_37 ) ;
V_4 . V_35 . V_31 = F_3 ( V_24 ) ;
V_4 . V_35 . V_32 = F_3 ( V_36 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_34 + V_36 ,
NULL , NULL ) ;
if ( V_8 ) {
F_5 ( L_10 ) ;
return V_8 ;
}
V_36 = F_11 ( V_36 , V_26 ) ;
V_24 += V_36 ;
V_25 += V_36 ;
V_26 -= V_36 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_24 , T_1 * V_38 )
{
struct V_3 V_4 ;
union V_16 V_17 ;
T_1 V_5 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_39 ) ;
T_1 V_19 = sizeof( V_17 . V_39 ) ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_7 ) ;
return - V_20 ;
}
F_2 ( V_11 ,
L_11 ,
V_12 , V_2 , V_24 , * V_38 ) ;
V_4 . V_6 = F_3 ( V_40 ) ;
V_4 . V_39 . V_31 = F_3 ( V_24 ) ;
V_4 . V_39 . V_38 = F_3 ( * V_38 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_5 , & V_17 , & V_19 ) ;
if ( V_8 ) {
F_5 ( L_9 ) ;
return V_8 ;
}
if ( V_19 < sizeof( V_17 . V_39 ) ) {
F_5 ( L_12 ,
V_19 ) ;
return V_8 ;
}
* V_38 = F_7 ( V_17 . V_39 . V_41 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , const void * V_25 , T_1 V_26 )
{
struct V_3 V_4 ;
T_1 V_34 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_42 ) ;
T_1 V_36 ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_7 ) ;
return - V_20 ;
}
while ( V_26 ) {
V_36 = F_11 ( V_26 , V_29 - V_34 ) ;
F_15 ( V_36 & 3 ) ;
V_4 . V_6 = F_3 ( V_43 ) ;
V_4 . V_42 . V_32 = F_3 ( V_36 ) ;
memcpy ( V_4 . V_42 . V_33 , V_25 , V_36 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_34 + V_36 ,
NULL , NULL ) ;
if ( V_8 ) {
F_5 ( L_10 ) ;
return V_8 ;
}
V_25 += V_36 ;
V_26 -= V_36 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 V_4 ;
T_1 V_5 = sizeof( V_4 . V_6 ) + sizeof( V_4 . V_44 ) ;
int V_8 ;
if ( V_2 -> V_9 . V_10 ) {
F_5 ( L_7 ) ;
return - V_20 ;
}
V_4 . V_6 = F_3 ( V_45 ) ;
V_4 . V_44 . V_31 = F_3 ( V_24 ) ;
V_8 = F_4 ( V_2 , & V_4 , V_5 , NULL , NULL ) ;
if ( V_8 ) {
F_5 ( L_13 ) ;
return V_8 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
T_1 V_24 , const void * V_25 , T_1 V_26 )
{
T_2 V_46 [ 4 ] = {} ;
T_1 V_47 = F_18 ( V_26 , 4 ) ;
T_1 V_48 = V_26 - V_47 ;
int V_8 ;
V_8 = F_16 ( V_2 , V_24 ) ;
if ( V_8 )
return V_8 ;
if ( V_48 > 0 )
memcpy ( V_46 , V_25 + V_47 , V_48 ) ;
V_8 = F_14 ( V_2 , V_25 , V_47 ) ;
if ( V_8 )
return V_8 ;
if ( V_48 > 0 )
V_8 = F_14 ( V_2 , V_46 , 4 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_16 ( V_2 , 0x00 ) ;
return V_8 ;
}
