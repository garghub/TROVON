static T_1 F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
T_1 V_4 ;
if ( ( V_2 -> V_5 != V_6 . V_5 ) ||
strcmp ( V_6 . V_7 , V_2 -> V_7 ) )
return - 1 ;
if ( V_2 -> V_8 >= V_6 . V_9 )
return 0 ;
if ( ( V_6 . V_8 < 0 ) ||
F_2 ( V_10 , V_6 . V_11 ) )
return - 1 ;
V_4 = V_6 . V_9 - V_2 -> V_8 ;
if ( V_4 > V_2 -> V_4 )
V_4 = V_2 -> V_4 ;
V_3 = V_2 -> V_8 - V_6 . V_8 ;
if ( ( V_3 >= 0 ) &&
( ( V_3 + V_4 ) <= V_6 . V_4 ) ) {
memcpy ( V_2 -> V_12 ,
V_6 . V_13 + V_3 ,
V_4 ) ;
F_3 ( L_1 ,
V_6 . V_7 , V_4 ,
V_6 . V_9 ) ;
return V_4 ;
}
return - 1 ;
}
static T_1 F_4 ( const struct V_1 * V_2 ,
T_3 V_14 )
{
T_1 V_4 ;
if ( ( V_2 -> V_4 > 0 ) && ( V_6 . V_4 >= V_2 -> V_4 ) ) {
struct V_1 V_15 = * V_2 ;
V_15 . V_12 = V_6 . V_13 ;
V_15 . V_4 = V_6 . V_4 ;
V_4 = V_14 ( & V_15 , & V_6 . V_9 ) ;
if ( V_4 > 0 ) {
F_3 ( L_2 ,
V_4 , V_2 -> V_7 ) ;
if ( V_4 > V_2 -> V_4 )
V_4 = V_2 -> V_4 ;
V_6 . V_8 = V_2 -> V_8 ;
V_6 . V_11 = V_10 +
V_16 * V_17 ;
memcpy ( V_2 -> V_12 , V_6 . V_13 , V_4 ) ;
}
} else {
V_4 = V_14 ( V_2 , & V_6 . V_9 ) ;
V_6 . V_8 = - 1 ;
}
if ( V_4 > 0 ) {
F_5 ( V_6 . V_7 , V_2 -> V_7 ,
V_18 ) ;
V_6 . V_5 = V_2 -> V_5 ;
F_3 ( L_3 ,
V_2 -> V_5 , V_6 . V_9 , V_2 -> V_7 ) ;
}
return V_4 ;
}
T_1 F_6 ( const struct V_1 * V_2 ,
T_3 V_14 )
{
T_1 V_4 ;
if ( ( V_2 -> V_5 == V_19 ) ||
( V_2 -> V_5 == V_20 ) ||
( V_2 -> V_5 == V_21 ) ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 >= 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_14 ) ;
if ( V_4 >= 0 )
return V_4 ;
} else {
V_4 = V_14 ( V_2 , NULL ) ;
}
V_6 . V_5 = V_22 ;
V_6 . V_9 = V_23 ;
V_6 . V_8 = - 1 ;
return V_4 ;
}
int F_7 ( T_4 V_24 )
{
if ( V_24 > 0 ) {
V_25 = F_8 ( V_24 ) ;
V_6 . V_13 =
( void * ) F_9 ( V_26 | V_27 ,
V_25 ) ;
if ( ! V_6 . V_13 ) {
F_10 ( L_4 ,
V_24 ) ;
return - V_28 ;
}
F_3 ( L_5 ,
V_24 ) ;
}
V_6 . V_4 = V_24 ;
return 0 ;
}
void F_11 ( void )
{
if ( V_6 . V_13 ) {
F_12 ( ( unsigned long ) V_6 . V_13 ,
V_25 ) ;
V_6 . V_13 = NULL ;
}
V_6 . V_5 = V_22 ;
V_6 . V_9 = V_23 ;
V_6 . V_8 = - 1 ;
V_6 . V_4 = 0 ;
}
