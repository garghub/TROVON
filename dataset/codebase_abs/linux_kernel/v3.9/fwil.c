static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 , void * V_4 , T_2 V_5 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
if ( V_8 -> V_10 -> V_11 != V_12 ) {
F_2 ( L_1 ) ;
return - V_13 ;
}
if ( V_4 != NULL )
V_5 = F_3 ( V_14 , V_5 , V_15 ) ;
if ( V_6 )
V_9 = F_4 ( V_8 , V_2 -> V_16 , V_3 , V_4 ,
V_5 ) ;
else
V_9 = F_5 ( V_8 , V_2 -> V_16 , V_3 , V_4 ,
V_5 ) ;
if ( V_9 >= 0 )
V_9 = 0 ;
else
F_2 ( L_2 , V_9 ) ;
return V_9 ;
}
T_1
F_6 ( struct V_1 * V_2 , T_2 V_3 , void * V_4 , T_2 V_5 )
{
T_1 V_9 ;
F_7 ( & V_2 -> V_8 -> V_17 ) ;
F_8 ( V_18 , L_3 , V_3 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , true ) ;
F_11 ( & V_2 -> V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_12 ( struct V_1 * V_2 , T_2 V_3 , void * V_4 , T_2 V_5 )
{
T_1 V_9 ;
F_7 ( & V_2 -> V_8 -> V_17 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , false ) ;
F_8 ( V_18 , L_3 , V_3 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
F_11 ( & V_2 -> V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_13 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_9 ;
T_3 V_20 = F_14 ( V_4 ) ;
F_7 ( & V_2 -> V_8 -> V_17 ) ;
F_8 ( V_18 , L_5 , V_3 , V_4 ) ;
V_9 = F_1 ( V_2 , V_3 , & V_20 , sizeof( V_20 ) , true ) ;
F_11 ( & V_2 -> V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_15 ( struct V_1 * V_2 , T_2 V_3 , T_2 * V_4 )
{
T_1 V_9 ;
T_3 V_20 = F_14 ( * V_4 ) ;
F_7 ( & V_2 -> V_8 -> V_17 ) ;
V_9 = F_1 ( V_2 , V_3 , & V_20 , sizeof( V_20 ) , false ) ;
F_11 ( & V_2 -> V_8 -> V_17 ) ;
* V_4 = F_16 ( V_20 ) ;
F_8 ( V_18 , L_5 , V_3 , * V_4 ) ;
return V_9 ;
}
static T_2
F_17 ( char * V_21 , char * V_4 , T_2 V_22 , char * V_23 , T_2 V_24 )
{
T_2 V_5 ;
V_5 = strlen ( V_21 ) + 1 ;
if ( ( V_5 + V_22 ) > V_24 )
return 0 ;
memcpy ( V_23 , V_21 , V_5 ) ;
if ( V_4 && V_22 )
memcpy ( & V_23 [ V_5 ] , V_4 , V_22 ) ;
return V_5 + V_22 ;
}
T_1
F_18 ( struct V_1 * V_2 , char * V_21 , void * V_4 ,
T_2 V_5 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
T_2 V_24 ;
F_7 ( & V_8 -> V_17 ) ;
F_8 ( V_18 , L_6 , V_21 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
V_24 = F_17 ( V_21 , V_4 , V_5 , V_8 -> V_25 ,
sizeof( V_8 -> V_25 ) ) ;
if ( V_24 ) {
V_9 = F_1 ( V_2 , V_26 , V_8 -> V_25 ,
V_24 , true ) ;
} else {
V_9 = - V_27 ;
F_2 ( L_7 ) ;
}
F_11 ( & V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_19 ( struct V_1 * V_2 , char * V_21 , void * V_4 ,
T_2 V_5 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
T_2 V_24 ;
F_7 ( & V_8 -> V_17 ) ;
V_24 = F_17 ( V_21 , V_4 , V_5 , V_8 -> V_25 ,
sizeof( V_8 -> V_25 ) ) ;
if ( V_24 ) {
V_9 = F_1 ( V_2 , V_28 , V_8 -> V_25 ,
V_24 , false ) ;
if ( V_9 == 0 )
memcpy ( V_4 , V_8 -> V_25 , V_5 ) ;
} else {
V_9 = - V_27 ;
F_2 ( L_7 ) ;
}
F_8 ( V_18 , L_6 , V_21 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
F_11 ( & V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_20 ( struct V_1 * V_2 , char * V_21 , T_2 V_4 )
{
T_3 V_20 = F_14 ( V_4 ) ;
return F_18 ( V_2 , V_21 , & V_20 , sizeof( V_20 ) ) ;
}
T_1
F_21 ( struct V_1 * V_2 , char * V_21 , T_2 * V_4 )
{
T_3 V_20 = F_14 ( * V_4 ) ;
T_1 V_9 ;
V_9 = F_19 ( V_2 , V_21 , & V_20 , sizeof( V_20 ) ) ;
if ( V_9 == 0 )
* V_4 = F_16 ( V_20 ) ;
return V_9 ;
}
static T_2
F_22 ( T_1 V_29 , char * V_21 , char * V_4 , T_2 V_22 , char * V_23 ,
T_2 V_24 )
{
const T_4 * V_30 = L_8 ;
T_4 * V_31 ;
T_2 V_32 ;
T_2 V_33 ;
T_2 V_34 ;
T_3 V_35 ;
if ( V_29 == 0 )
return F_17 ( V_21 , V_4 , V_22 , V_23 , V_24 ) ;
V_32 = strlen ( V_30 ) ;
V_33 = strlen ( V_21 ) + 1 ;
V_34 = V_32 + V_33 + sizeof( V_35 ) + V_22 ;
if ( V_24 < V_34 ) {
F_2 ( L_9 ) ;
return 0 ;
}
V_31 = V_23 ;
memcpy ( V_31 , V_30 , V_32 ) ;
V_31 += V_32 ;
memcpy ( V_31 , V_21 , V_33 ) ;
V_31 += V_33 ;
V_35 = F_14 ( V_29 ) ;
memcpy ( V_31 , & V_35 , sizeof( V_35 ) ) ;
V_31 += sizeof( V_35 ) ;
if ( V_22 )
memcpy ( V_31 , V_4 , V_22 ) ;
return V_34 ;
}
T_1
F_23 ( struct V_1 * V_2 , char * V_21 ,
void * V_4 , T_2 V_5 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
T_2 V_24 ;
F_7 ( & V_8 -> V_17 ) ;
F_8 ( V_18 , L_10 , V_2 -> V_29 , V_21 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
V_24 = F_22 ( V_2 -> V_29 , V_21 , V_4 , V_5 ,
V_8 -> V_25 , sizeof( V_8 -> V_25 ) ) ;
if ( V_24 ) {
V_9 = F_1 ( V_2 , V_26 , V_8 -> V_25 ,
V_24 , true ) ;
} else {
V_9 = - V_27 ;
F_2 ( L_11 ) ;
}
F_11 ( & V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_24 ( struct V_1 * V_2 , char * V_21 ,
void * V_4 , T_2 V_5 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
T_2 V_24 ;
F_7 ( & V_8 -> V_17 ) ;
V_24 = F_22 ( V_2 -> V_29 , V_21 , V_4 , V_5 ,
V_8 -> V_25 , sizeof( V_8 -> V_25 ) ) ;
if ( V_24 ) {
V_9 = F_1 ( V_2 , V_28 , V_8 -> V_25 ,
V_24 , false ) ;
if ( V_9 == 0 )
memcpy ( V_4 , V_8 -> V_25 , V_5 ) ;
} else {
V_9 = - V_27 ;
F_2 ( L_11 ) ;
}
F_8 ( V_18 , L_10 , V_2 -> V_29 , V_21 , V_5 ) ;
F_9 ( F_10 () , V_4 ,
F_3 ( V_14 , V_5 , V_19 ) , L_4 ) ;
F_11 ( & V_8 -> V_17 ) ;
return V_9 ;
}
T_1
F_25 ( struct V_1 * V_2 , char * V_21 , T_2 V_4 )
{
T_3 V_20 = F_14 ( V_4 ) ;
return F_23 ( V_2 , V_21 , & V_20 ,
sizeof( V_20 ) ) ;
}
T_1
F_26 ( struct V_1 * V_2 , char * V_21 , T_2 * V_4 )
{
T_3 V_20 = F_14 ( * V_4 ) ;
T_1 V_9 ;
V_9 = F_24 ( V_2 , V_21 , & V_20 ,
sizeof( V_20 ) ) ;
if ( V_9 == 0 )
* V_4 = F_16 ( V_20 ) ;
return V_9 ;
}
