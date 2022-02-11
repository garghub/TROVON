struct V_1 * F_1 ( const char * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
unsigned int V_6 ;
if ( strncmp ( V_2 , L_1 , 11 ) != 0 )
return NULL ;
V_6 = F_2 ( V_2 + 11 , NULL , 0 ) ;
if ( V_6 >= V_7 )
return NULL ;
V_4 = F_3 ( V_6 ) ;
if ( V_4 == NULL )
return NULL ;
V_5 = V_4 -> V_8 ;
if ( V_5 == NULL || ! V_5 -> V_9 )
return NULL ;
if ( ! F_4 ( V_5 -> V_10 -> V_11 ) )
return NULL ;
return V_5 ;
}
int F_5 ( struct V_1 * V_12 )
{
struct V_1 * V_5 = (struct V_1 * ) V_12 ;
F_6 ( V_5 -> V_10 -> V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_5 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_17 = 0 ;
if ( V_14 -> V_18 >= V_5 -> V_19 ) {
V_17 = - V_20 ;
goto error;
}
V_16 = V_5 -> V_21 + V_14 -> V_18 ;
if ( V_16 -> type == V_22 ) {
F_8 ( V_23 L_2 , V_14 -> V_18 ) ;
V_17 = - V_24 ;
goto error;
}
V_17 = F_9 ( V_16 , 1 , & V_14 -> V_25 ) ;
if ( V_17 < 0 ) {
F_8 ( V_23 L_3 ) ;
V_17 = - V_20 ;
goto error;
}
if ( V_16 -> V_26 ) {
V_17 = - V_27 ;
goto error;
}
V_16 -> V_26 = V_5 ;
switch ( V_14 -> V_14 ) {
case V_28 :
V_17 = V_16 -> V_29 ( V_5 , V_16 , V_14 , V_14 -> V_30 ) ;
break;
case V_31 :
V_17 = V_16 -> V_32 ( V_5 , V_16 , V_14 , V_14 -> V_30 ) ;
break;
default:
V_17 = - V_20 ;
break;
}
V_16 -> V_26 = NULL ;
error:
return V_17 ;
}
int F_10 ( struct V_1 * V_5 , unsigned int V_18 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_13 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_14 = V_31 ;
V_14 . V_35 = 1 ;
V_14 . V_30 = & V_34 ;
V_14 . V_18 = V_18 ;
V_14 . V_25 = F_11 ( V_33 , 0 , 0 ) ;
return F_7 ( V_5 , & V_14 ) ;
}
int F_12 ( struct V_1 * V_5 , unsigned int V_18 ,
unsigned int V_36 , unsigned int * V_37 )
{
struct V_13 V_14 ;
unsigned int V_30 [ 2 ] ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_14 = V_28 ;
V_14 . V_35 = 2 ;
V_14 . V_30 = V_30 ;
V_14 . V_18 = V_18 ;
V_30 [ 0 ] = V_36 ;
V_30 [ 1 ] = * V_37 ;
V_17 = F_7 ( V_5 , & V_14 ) ;
* V_37 = V_30 [ 1 ] ;
return V_17 ;
}
int F_13 ( struct V_1 * V_5 , int type ,
unsigned int V_38 )
{
if ( V_38 > V_5 -> V_19 )
return - V_39 ;
for (; V_38 < V_5 -> V_19 ; V_38 ++ ) {
if ( V_5 -> V_21 [ V_38 ] . type == type )
return V_38 ;
}
return - 1 ;
}
int F_14 ( struct V_1 * V_5 , unsigned int V_40 )
{
struct V_15 * V_16 = V_5 -> V_21 + V_40 ;
return V_16 -> V_41 ;
}
