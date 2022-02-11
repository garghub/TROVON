static T_1 F_1 ( const void * V_1 ,
void * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_1 ;
unsigned V_6 ;
F_2 ( L_1 , V_5 -> V_7 , V_5 -> V_8 ) ;
V_6 = strlen ( V_5 -> V_7 ) ;
if ( V_6 > V_3 )
return 0 ;
memcpy ( V_2 , V_5 -> V_7 , V_6 ) ;
return V_6 ;
}
static T_1 F_3 ( const void * V_1 ,
void * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_1 ;
unsigned V_9 ;
F_2 ( L_1 , V_5 -> V_7 , V_5 -> V_8 ) ;
V_9 = sizeof( V_10 ) ;
if ( V_9 > V_3 )
return 0 ;
memcpy ( V_2 , & V_5 -> V_8 , V_9 ) ;
return V_9 ;
}
static enum V_11 F_4 (
void * V_1 ,
const void * V_12 ,
T_1 V_13 )
{
struct V_4 * V_5 = V_1 ;
V_10 V_8 ;
F_2 ( L_2 , V_5 -> V_7 , V_13 ) ;
if ( V_13 != sizeof( V_8 ) ) {
F_5 ( L_3 , V_13 , sizeof( V_8 ) ) ;
return V_14 ;
}
memcpy ( & V_8 , V_12 , sizeof( V_8 ) ) ;
if ( V_8 != V_5 -> V_8 ) {
F_5 ( L_4 , V_8 , V_5 -> V_8 ) ;
return V_14 ;
}
F_5 ( L_5 ) ;
return V_15 ;
}
