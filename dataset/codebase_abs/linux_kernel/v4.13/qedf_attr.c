inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 != NULL ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_3 ;
struct V_5 * V_6 ;
if ( ! ( F_1 ( V_2 ) ) )
return NULL ;
V_3 = V_2 -> V_3 ;
V_6 = F_3 ( F_4 ( V_3 -> V_4 ) ) ;
return F_5 ( V_6 ) ;
}
static T_1
F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_5 * V_3 = F_3 ( F_7 ( V_8 ) ) ;
T_2 V_12 ;
T_3 V_13 [ 3 ] ;
T_3 V_14 [ 6 ] ;
V_12 = F_8 ( V_3 -> V_15 ) ;
V_13 [ 2 ] = ( V_12 & 0x000000FF ) ;
V_13 [ 1 ] = ( V_12 & 0x0000FF00 ) >> 8 ;
V_13 [ 0 ] = ( V_12 & 0x00FF0000 ) >> 16 ;
F_9 ( V_14 , V_13 ) ;
return F_10 ( V_11 , V_16 , L_1 , V_14 ) ;
}
static T_1
F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_5 * V_3 = F_3 ( F_7 ( V_8 ) ) ;
struct V_1 * V_2 = F_5 ( V_3 ) ;
int V_17 = - 1 ;
if ( F_1 ( V_2 ) )
V_2 = F_2 ( V_2 ) ;
if ( V_2 -> V_18 . V_19 )
V_17 = V_2 -> V_18 . V_19 -> V_17 ;
return F_10 ( V_11 , V_16 , L_2 , V_17 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_1 * V_20 ;
if ( F_1 ( V_2 ) )
V_20 = F_2 ( V_2 ) ;
else
V_20 = V_2 ;
if ( F_13 ( V_21 , & V_20 -> V_22 ) ) {
F_14 ( & ( V_20 -> V_23 ) , V_24 ,
L_3 ) ;
return;
}
F_15 ( V_20 -> V_25 , V_26 -> V_27 ,
& V_20 -> V_28 , & V_20 -> V_29 ) ;
F_16 ( & ( V_20 -> V_23 ) , L_4 ) ;
F_17 ( V_21 , & V_20 -> V_22 ) ;
F_18 ( V_20 -> V_3 -> V_15 , V_30 ,
NULL ) ;
}
static T_1
F_19 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_11 , T_4 V_37 ,
T_5 V_38 )
{
T_1 V_39 = 0 ;
struct V_5 * V_3 = F_3 ( F_20 ( F_21 ( V_34 ,
struct V_7 , V_34 ) ) ) ;
struct V_1 * V_2 = F_5 ( V_3 ) ;
if ( F_13 ( V_21 , & V_2 -> V_22 ) ) {
V_39 = F_22 ( V_11 , V_38 , & V_37 ,
V_2 -> V_28 , V_2 -> V_29 ) ;
} else {
F_16 ( & ( V_2 -> V_23 ) , L_5 ) ;
}
return V_39 ;
}
static T_1
F_23 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_11 , T_4 V_37 ,
T_5 V_38 )
{
struct V_5 * V_3 = NULL ;
struct V_1 * V_2 = NULL ;
long V_40 ;
int V_39 = 0 ;
char V_41 [ 40 ] ;
if ( V_37 != 0 )
return V_39 ;
V_3 = F_3 ( F_20 ( F_21 ( V_34 ,
struct V_7 , V_34 ) ) ) ;
V_2 = F_5 ( V_3 ) ;
V_11 [ 1 ] = 0 ;
V_39 = F_24 ( V_11 , 10 , & V_40 ) ;
if ( V_39 ) {
F_16 ( & ( V_2 -> V_23 ) , L_6 , V_39 ) ;
return V_39 ;
}
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
switch ( V_40 ) {
case 0 :
memset ( V_2 -> V_28 , 0 , V_2 -> V_29 ) ;
F_25 ( V_21 , & V_2 -> V_22 ) ;
break;
case 1 :
F_12 ( V_2 ) ;
break;
}
return V_38 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_3 -> V_15 , V_42 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_3 -> V_15 , V_42 ) ;
}
