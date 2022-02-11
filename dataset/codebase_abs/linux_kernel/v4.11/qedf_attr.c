static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
T_2 V_8 ;
T_3 V_9 [ 3 ] ;
T_3 V_10 [ 6 ] ;
V_8 = F_4 ( V_7 -> V_11 ) ;
V_9 [ 2 ] = ( V_8 & 0x000000FF ) ;
V_9 [ 1 ] = ( V_8 & 0x0000FF00 ) >> 8 ;
V_9 [ 0 ] = ( V_8 & 0x00FF0000 ) >> 16 ;
F_5 ( V_10 , V_9 ) ;
return F_6 ( V_5 , V_12 , L_1 , V_10 ) ;
}
inline bool F_7 ( struct V_13 * V_14 )
{
return ( ! ( V_14 -> V_7 -> V_15 == NULL ) ) ;
}
static struct V_13 * F_8 ( struct V_13 * V_14 )
{
struct V_6 * V_7 ;
struct V_6 * V_16 ;
if ( ! ( F_7 ( V_14 ) ) )
return NULL ;
V_7 = V_14 -> V_7 ;
V_16 = F_2 ( F_9 ( V_7 -> V_15 ) ) ;
return (struct V_13 * ) ( F_10 ( V_16 ) ) ;
}
void F_11 ( struct V_13 * V_14 )
{
struct V_13 * V_17 ;
if ( F_7 ( V_14 ) )
V_17 = F_8 ( V_14 ) ;
else
V_17 = V_14 ;
if ( F_12 ( V_18 , & V_17 -> V_19 ) ) {
F_13 ( & ( V_17 -> V_20 ) , V_21 ,
L_2 ) ;
return;
}
F_14 ( V_17 -> V_22 , V_23 -> V_24 ,
& V_17 -> V_25 , & V_17 -> V_26 ) ;
F_15 ( & ( V_17 -> V_20 ) , L_3 ) ;
F_16 ( V_18 , & V_17 -> V_19 ) ;
F_17 ( V_17 -> V_7 -> V_11 , V_27 ,
NULL ) ;
}
static T_1
F_18 ( struct V_28 * V_29 , struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_5 , T_4 V_34 ,
T_5 V_35 )
{
T_1 V_36 = 0 ;
struct V_6 * V_7 = F_2 ( F_19 ( F_20 ( V_31 ,
struct V_1 , V_31 ) ) ) ;
struct V_13 * V_14 = F_10 ( V_7 ) ;
if ( F_12 ( V_18 , & V_14 -> V_19 ) ) {
V_36 = F_21 ( V_5 , V_35 , & V_34 ,
V_14 -> V_25 , V_14 -> V_26 ) ;
} else {
F_15 ( & ( V_14 -> V_20 ) , L_4 ) ;
}
return V_36 ;
}
static T_1
F_22 ( struct V_28 * V_29 , struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_5 , T_4 V_34 ,
T_5 V_35 )
{
struct V_6 * V_7 = NULL ;
struct V_13 * V_14 = NULL ;
long V_37 ;
int V_36 = 0 ;
char V_38 [ 40 ] ;
if ( V_34 != 0 )
return V_36 ;
V_7 = F_2 ( F_19 ( F_20 ( V_31 ,
struct V_1 , V_31 ) ) ) ;
V_14 = F_10 ( V_7 ) ;
V_5 [ 1 ] = 0 ;
V_36 = F_23 ( V_5 , 10 , & V_37 ) ;
if ( V_36 ) {
F_15 ( & ( V_14 -> V_20 ) , L_5 , V_36 ) ;
return V_36 ;
}
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
switch ( V_37 ) {
case 0 :
memset ( V_14 -> V_25 , 0 , V_14 -> V_26 ) ;
F_24 ( V_18 , & V_14 -> V_19 ) ;
break;
case 1 :
F_11 ( V_14 ) ;
break;
}
return V_35 ;
}
void F_25 ( struct V_13 * V_14 )
{
F_26 ( V_14 -> V_7 -> V_11 , V_39 ) ;
}
void F_27 ( struct V_13 * V_14 )
{
F_28 ( V_14 -> V_7 -> V_11 , V_39 ) ;
}
