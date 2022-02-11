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
return - V_19 ;
}
T_2
F_9 ( struct V_3 * V_4 , T_1 V_5 , void * V_6 , T_1 V_7 )
{
T_2 V_1 ;
F_10 ( & V_4 -> V_10 -> V_20 ) ;
F_8 ( V_18 , L_5 , V_4 -> V_17 , V_5 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
V_1 = F_3 ( V_4 , V_5 , V_6 , V_7 , true ) ;
F_13 ( & V_4 -> V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_14 ( struct V_3 * V_4 , T_1 V_5 , void * V_6 , T_1 V_7 )
{
T_2 V_1 ;
F_10 ( & V_4 -> V_10 -> V_20 ) ;
V_1 = F_3 ( V_4 , V_5 , V_6 , V_7 , false ) ;
F_8 ( V_18 , L_5 , V_4 -> V_17 , V_5 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
F_13 ( & V_4 -> V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_15 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
T_2 V_1 ;
T_3 V_22 = F_16 ( V_6 ) ;
F_10 ( & V_4 -> V_10 -> V_20 ) ;
F_8 ( V_18 , L_7 , V_4 -> V_17 , V_5 , V_6 ) ;
V_1 = F_3 ( V_4 , V_5 , & V_22 , sizeof( V_22 ) , true ) ;
F_13 ( & V_4 -> V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_17 ( struct V_3 * V_4 , T_1 V_5 , T_1 * V_6 )
{
T_2 V_1 ;
T_3 V_22 = F_16 ( * V_6 ) ;
F_10 ( & V_4 -> V_10 -> V_20 ) ;
V_1 = F_3 ( V_4 , V_5 , & V_22 , sizeof( V_22 ) , false ) ;
F_13 ( & V_4 -> V_10 -> V_20 ) ;
* V_6 = F_18 ( V_22 ) ;
F_8 ( V_18 , L_7 , V_4 -> V_17 , V_5 , * V_6 ) ;
return V_1 ;
}
static T_1
F_19 ( char * V_23 , const char * V_6 , T_1 V_24 ,
char * V_25 , T_1 V_26 )
{
T_1 V_7 ;
V_7 = strlen ( V_23 ) + 1 ;
if ( ( V_7 + V_24 ) > V_26 )
return 0 ;
memcpy ( V_25 , V_23 , V_7 ) ;
if ( V_6 && V_24 )
memcpy ( & V_25 [ V_7 ] , V_6 , V_24 ) ;
return V_7 + V_24 ;
}
T_2
F_20 ( struct V_3 * V_4 , char * V_23 , const void * V_6 ,
T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_26 ;
F_10 ( & V_10 -> V_20 ) ;
F_8 ( V_18 , L_8 , V_4 -> V_17 , V_23 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
V_26 = F_19 ( V_23 , V_6 , V_7 , V_10 -> V_27 ,
sizeof( V_10 -> V_27 ) ) ;
if ( V_26 ) {
V_1 = F_3 ( V_4 , V_28 , V_10 -> V_27 ,
V_26 , true ) ;
} else {
V_1 = - V_29 ;
F_4 ( L_9 ) ;
}
F_13 ( & V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_21 ( struct V_3 * V_4 , char * V_23 , void * V_6 ,
T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_26 ;
F_10 ( & V_10 -> V_20 ) ;
V_26 = F_19 ( V_23 , V_6 , V_7 , V_10 -> V_27 ,
sizeof( V_10 -> V_27 ) ) ;
if ( V_26 ) {
V_1 = F_3 ( V_4 , V_30 , V_10 -> V_27 ,
V_26 , false ) ;
if ( V_1 == 0 )
memcpy ( V_6 , V_10 -> V_27 , V_7 ) ;
} else {
V_1 = - V_29 ;
F_4 ( L_9 ) ;
}
F_8 ( V_18 , L_8 , V_4 -> V_17 , V_23 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
F_13 ( & V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_22 ( struct V_3 * V_4 , char * V_23 , T_1 V_6 )
{
T_3 V_22 = F_16 ( V_6 ) ;
return F_20 ( V_4 , V_23 , & V_22 , sizeof( V_22 ) ) ;
}
T_2
F_23 ( struct V_3 * V_4 , char * V_23 , T_1 * V_6 )
{
T_3 V_22 = F_16 ( * V_6 ) ;
T_2 V_1 ;
V_1 = F_21 ( V_4 , V_23 , & V_22 , sizeof( V_22 ) ) ;
if ( V_1 == 0 )
* V_6 = F_18 ( V_22 ) ;
return V_1 ;
}
static T_1
F_24 ( T_2 V_31 , char * V_23 , char * V_6 , T_1 V_24 , char * V_25 ,
T_1 V_26 )
{
const T_4 * V_32 = L_10 ;
T_4 * V_33 ;
T_1 V_34 ;
T_1 V_35 ;
T_1 V_36 ;
T_3 V_37 ;
if ( V_31 == 0 )
return F_19 ( V_23 , V_6 , V_24 , V_25 , V_26 ) ;
V_34 = strlen ( V_32 ) ;
V_35 = strlen ( V_23 ) + 1 ;
V_36 = V_34 + V_35 + sizeof( V_37 ) + V_24 ;
if ( V_26 < V_36 ) {
F_4 ( L_11 ) ;
return 0 ;
}
V_33 = V_25 ;
memcpy ( V_33 , V_32 , V_34 ) ;
V_33 += V_34 ;
memcpy ( V_33 , V_23 , V_35 ) ;
V_33 += V_35 ;
V_37 = F_16 ( V_31 ) ;
memcpy ( V_33 , & V_37 , sizeof( V_37 ) ) ;
V_33 += sizeof( V_37 ) ;
if ( V_24 )
memcpy ( V_33 , V_6 , V_24 ) ;
return V_36 ;
}
T_2
F_25 ( struct V_3 * V_4 , char * V_23 ,
void * V_6 , T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_26 ;
F_10 ( & V_10 -> V_20 ) ;
F_8 ( V_18 , L_12 , V_4 -> V_17 ,
V_4 -> V_31 , V_23 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
V_26 = F_24 ( V_4 -> V_31 , V_23 , V_6 , V_7 ,
V_10 -> V_27 , sizeof( V_10 -> V_27 ) ) ;
if ( V_26 ) {
V_1 = F_3 ( V_4 , V_28 , V_10 -> V_27 ,
V_26 , true ) ;
} else {
V_1 = - V_29 ;
F_4 ( L_13 ) ;
}
F_13 ( & V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_26 ( struct V_3 * V_4 , char * V_23 ,
void * V_6 , T_1 V_7 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_1 ;
T_1 V_26 ;
F_10 ( & V_10 -> V_20 ) ;
V_26 = F_24 ( V_4 -> V_31 , V_23 , V_6 , V_7 ,
V_10 -> V_27 , sizeof( V_10 -> V_27 ) ) ;
if ( V_26 ) {
V_1 = F_3 ( V_4 , V_30 , V_10 -> V_27 ,
V_26 , false ) ;
if ( V_1 == 0 )
memcpy ( V_6 , V_10 -> V_27 , V_7 ) ;
} else {
V_1 = - V_29 ;
F_4 ( L_13 ) ;
}
F_8 ( V_18 , L_12 , V_4 -> V_17 ,
V_4 -> V_31 , V_23 , V_7 ) ;
F_11 ( F_12 () , V_6 ,
F_5 ( V_15 , V_7 , V_21 ) , L_6 ) ;
F_13 ( & V_10 -> V_20 ) ;
return V_1 ;
}
T_2
F_27 ( struct V_3 * V_4 , char * V_23 , T_1 V_6 )
{
T_3 V_22 = F_16 ( V_6 ) ;
return F_25 ( V_4 , V_23 , & V_22 ,
sizeof( V_22 ) ) ;
}
T_2
F_28 ( struct V_3 * V_4 , char * V_23 , T_1 * V_6 )
{
T_3 V_22 = F_16 ( * V_6 ) ;
T_2 V_1 ;
V_1 = F_26 ( V_4 , V_23 , & V_22 ,
sizeof( V_22 ) ) ;
if ( V_1 == 0 )
* V_6 = F_18 ( V_22 ) ;
return V_1 ;
}
