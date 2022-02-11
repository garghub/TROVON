static int
F_1 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 )
{
enum V_5 type = (enum V_5 ) ( V_2 -> V_6 -> type & 0xff ) ;
F_2 ( V_3 , & V_7 , NULL , 0 , 0 , V_2 -> V_6 -> type ) ;
switch ( type ) {
default:
break;
}
return V_4 ;
}
static int
F_3 ( T_1 * T_2 , T_3 * V_2 , T_4 * V_3 , int V_4 )
{
enum V_8 type = (enum V_8 ) ( V_2 -> V_6 -> type & 0xff ) ;
F_2 ( V_3 , & V_9 , NULL , 0 , 0 , V_2 -> V_6 -> type ) ;
switch ( type ) {
case V_10 :
F_4 ( V_11 , T_2 , V_2 -> V_12 , V_3 ) ;
break;
default:
break;
}
return V_4 ;
}
static int
F_5 ( T_1 * T_2 , T_5 * V_12 , T_4 * V_3 , void * V_13 )
{
struct V_14 * V_6 = NULL ;
T_3 V_2 ;
int V_4 ;
if ( V_13 ) {
if ( ( (struct V_14 * ) V_13 ) -> V_15 == V_16 )
V_6 = (struct V_14 * ) V_13 ;
}
F_6 ( V_6 ) ;
F_7 ( V_12 -> V_17 , V_18 , L_1 ) ;
F_8 ( V_12 -> V_17 , V_19 ) ;
if ( V_3 ) {
F_9 ( V_3 , L_2 ) ;
F_2 ( V_3 , & V_20 , NULL , 0 , 0 , V_6 -> type ) ;
}
V_2 . V_21 = V_6 -> V_21 ;
V_2 . V_12 = V_12 ;
V_2 . V_6 = V_6 ;
V_4 = 0 ;
switch ( V_6 -> type >> 8 ) {
case V_22 :
V_4 = F_1 ( T_2 , & V_2 , V_3 , V_4 ) ;
break;
case V_23 :
V_4 = F_3 ( T_2 , & V_2 , V_3 , V_4 ) ;
break;
}
return V_4 ;
}
void
F_10 ( void )
{
#ifndef F_11
static T_6 * V_24 [] = {
& V_20 ,
& V_7 ,
& V_9 ,
} ;
#endif
static T_7 * V_25 [] = {
& V_26 ,
} ;
int V_27 ;
V_27 = F_12 ( L_3 , L_4 , L_5 ) ;
V_28 = F_13 ( V_27 ) ;
F_14 ( V_27 , V_24 , F_15 ( V_24 ) ) ;
F_16 ( V_25 , F_15 ( V_25 ) ) ;
V_29 = F_17 ( F_5 , V_27 ) ;
}
void
F_18 ( void )
{
F_19 ( L_6 , V_30 , V_29 ) ;
V_11 = F_20 ( L_7 , V_28 -> V_31 ) ;
}
