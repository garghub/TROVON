static const char * F_1 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return L_1 ;
return V_2 [ V_1 ] ;
}
static const char * F_1 ( T_1 V_1 )
{
return L_2 ;
}
static T_2
F_3 ( struct V_3 * V_4 , T_1 V_5 , void * V_6 , T_1 V_7 , bool V_8 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
if ( V_10 -> V_11 -> V_12 != V_13 ) {
F_4 ( L_3 ) ;
return - V_14 ;
}
if ( V_6 != NULL )
V_7 = F_5 ( V_15 , V_7 , V_16 ) ;
if ( V_8 )
V_1 = F_6 ( V_10 , V_4 -> V_17 , V_5 , V_6 , V_7 ) ;
else
V_1 = F_7 ( V_10 , V_4 -> V_17 , V_5 , V_6 , V_7 ) ;
if ( V_1 >= 0 )
return 0 ;
F_8 ( V_18 , L_4 ,
F_1 ( ( T_1 ) ( - V_1 ) ) , V_1 ) ;
return V_1 ;
}
T_2
F_9 ( struct V_3 * V_4 , T_1 V_5 , void * V_6 , T_1 V_7 )
{
T_2 V_1 ;
F_10 ( & V_4 -> V_10 -> V_19 ) ;
F_8 ( V_18 , L_5 , V_4 -> V_17 , V_5 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
V_1 = F_3 ( V_4 , V_5 , V_6 , V_7 , true ) ;
F_13 ( & V_4 -> V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_14 ( struct V_3 * V_4 , T_1 V_5 , void * V_6 , T_1 V_7 )
{
T_2 V_1 ;
F_10 ( & V_4 -> V_10 -> V_19 ) ;
V_1 = F_3 ( V_4 , V_5 , V_6 , V_7 , false ) ;
F_8 ( V_18 , L_5 , V_4 -> V_17 , V_5 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
F_13 ( & V_4 -> V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_15 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
T_2 V_1 ;
T_3 V_21 = F_16 ( V_6 ) ;
F_10 ( & V_4 -> V_10 -> V_19 ) ;
F_8 ( V_18 , L_7 , V_4 -> V_17 , V_5 , V_6 ) ;
V_1 = F_3 ( V_4 , V_5 , & V_21 , sizeof( V_21 ) , true ) ;
F_13 ( & V_4 -> V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_17 ( struct V_3 * V_4 , T_1 V_5 , T_1 * V_6 )
{
T_2 V_1 ;
T_3 V_21 = F_16 ( * V_6 ) ;
F_10 ( & V_4 -> V_10 -> V_19 ) ;
V_1 = F_3 ( V_4 , V_5 , & V_21 , sizeof( V_21 ) , false ) ;
F_13 ( & V_4 -> V_10 -> V_19 ) ;
* V_6 = F_18 ( V_21 ) ;
F_8 ( V_18 , L_7 , V_4 -> V_17 , V_5 , * V_6 ) ;
return V_1 ;
}
static T_1
F_19 ( char * V_22 , const char * V_6 , T_1 V_23 ,
char * V_24 , T_1 V_25 )
{
T_1 V_7 ;
V_7 = strlen ( V_22 ) + 1 ;
if ( ( V_7 + V_23 ) > V_25 )
return 0 ;
memcpy ( V_24 , V_22 , V_7 ) ;
if ( V_6 && V_23 )
memcpy ( & V_24 [ V_7 ] , V_6 , V_23 ) ;
return V_7 + V_23 ;
}
T_2
F_20 ( struct V_3 * V_4 , char * V_22 , const void * V_6 ,
T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_25 ;
F_10 ( & V_10 -> V_19 ) ;
F_8 ( V_18 , L_8 , V_4 -> V_17 , V_22 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
V_25 = F_19 ( V_22 , V_6 , V_7 , V_10 -> V_26 ,
sizeof( V_10 -> V_26 ) ) ;
if ( V_25 ) {
V_1 = F_3 ( V_4 , V_27 , V_10 -> V_26 ,
V_25 , true ) ;
} else {
V_1 = - V_28 ;
F_4 ( L_9 ) ;
}
F_13 ( & V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_21 ( struct V_3 * V_4 , char * V_22 , void * V_6 ,
T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_25 ;
F_10 ( & V_10 -> V_19 ) ;
V_25 = F_19 ( V_22 , V_6 , V_7 , V_10 -> V_26 ,
sizeof( V_10 -> V_26 ) ) ;
if ( V_25 ) {
V_1 = F_3 ( V_4 , V_29 , V_10 -> V_26 ,
V_25 , false ) ;
if ( V_1 == 0 )
memcpy ( V_6 , V_10 -> V_26 , V_7 ) ;
} else {
V_1 = - V_28 ;
F_4 ( L_9 ) ;
}
F_8 ( V_18 , L_8 , V_4 -> V_17 , V_22 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
F_13 ( & V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_22 ( struct V_3 * V_4 , char * V_22 , T_1 V_6 )
{
T_3 V_21 = F_16 ( V_6 ) ;
return F_20 ( V_4 , V_22 , & V_21 , sizeof( V_21 ) ) ;
}
T_2
F_23 ( struct V_3 * V_4 , char * V_22 , T_1 * V_6 )
{
T_3 V_21 = F_16 ( * V_6 ) ;
T_2 V_1 ;
V_1 = F_21 ( V_4 , V_22 , & V_21 , sizeof( V_21 ) ) ;
if ( V_1 == 0 )
* V_6 = F_18 ( V_21 ) ;
return V_1 ;
}
static T_1
F_24 ( T_2 V_30 , char * V_22 , char * V_6 , T_1 V_23 ,
char * V_24 , T_1 V_25 )
{
const T_4 * V_31 = L_10 ;
T_4 * V_32 ;
T_1 V_33 ;
T_1 V_34 ;
T_1 V_35 ;
T_3 V_36 ;
if ( V_30 == 0 )
return F_19 ( V_22 , V_6 , V_23 , V_24 , V_25 ) ;
V_33 = strlen ( V_31 ) ;
V_34 = strlen ( V_22 ) + 1 ;
V_35 = V_33 + V_34 + sizeof( V_36 ) + V_23 ;
if ( V_25 < V_35 ) {
F_4 ( L_11 ) ;
return 0 ;
}
V_32 = V_24 ;
memcpy ( V_32 , V_31 , V_33 ) ;
V_32 += V_33 ;
memcpy ( V_32 , V_22 , V_34 ) ;
V_32 += V_34 ;
V_36 = F_16 ( V_30 ) ;
memcpy ( V_32 , & V_36 , sizeof( V_36 ) ) ;
V_32 += sizeof( V_36 ) ;
if ( V_23 )
memcpy ( V_32 , V_6 , V_23 ) ;
return V_35 ;
}
T_2
F_25 ( struct V_3 * V_4 , char * V_22 ,
void * V_6 , T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_25 ;
F_10 ( & V_10 -> V_19 ) ;
F_8 ( V_18 , L_12 , V_4 -> V_17 ,
V_4 -> V_30 , V_22 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
V_25 = F_24 ( V_4 -> V_30 , V_22 , V_6 , V_7 ,
V_10 -> V_26 , sizeof( V_10 -> V_26 ) ) ;
if ( V_25 ) {
V_1 = F_3 ( V_4 , V_27 , V_10 -> V_26 ,
V_25 , true ) ;
} else {
V_1 = - V_28 ;
F_4 ( L_13 ) ;
}
F_13 ( & V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_26 ( struct V_3 * V_4 , char * V_22 ,
void * V_6 , T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_25 ;
F_10 ( & V_10 -> V_19 ) ;
V_25 = F_24 ( V_4 -> V_30 , V_22 , V_6 , V_7 ,
V_10 -> V_26 , sizeof( V_10 -> V_26 ) ) ;
if ( V_25 ) {
V_1 = F_3 ( V_4 , V_29 , V_10 -> V_26 ,
V_25 , false ) ;
if ( V_1 == 0 )
memcpy ( V_6 , V_10 -> V_26 , V_7 ) ;
} else {
V_1 = - V_28 ;
F_4 ( L_13 ) ;
}
F_8 ( V_18 , L_12 , V_4 -> V_17 ,
V_4 -> V_30 , V_22 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_20 ) , L_6 ) ;
F_13 ( & V_10 -> V_19 ) ;
return V_1 ;
}
T_2
F_27 ( struct V_3 * V_4 , char * V_22 , T_1 V_6 )
{
T_3 V_21 = F_16 ( V_6 ) ;
return F_25 ( V_4 , V_22 , & V_21 ,
sizeof( V_21 ) ) ;
}
T_2
F_28 ( struct V_3 * V_4 , char * V_22 , T_1 * V_6 )
{
T_3 V_21 = F_16 ( * V_6 ) ;
T_2 V_1 ;
V_1 = F_26 ( V_4 , V_22 , & V_21 ,
sizeof( V_21 ) ) ;
if ( V_1 == 0 )
* V_6 = F_18 ( V_21 ) ;
return V_1 ;
}
