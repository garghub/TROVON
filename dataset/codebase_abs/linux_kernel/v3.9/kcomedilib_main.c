struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
unsigned int V_4 ;
if ( strncmp ( V_2 , L_1 , 11 ) != 0 )
return NULL ;
V_4 = F_2 ( V_2 + 11 , NULL , 0 ) ;
if ( V_4 >= V_5 )
return NULL ;
V_3 = F_3 ( V_4 ) ;
if ( ! V_3 || ! V_3 -> V_6 )
return NULL ;
if ( ! F_4 ( V_3 -> V_7 -> V_8 ) )
return NULL ;
return V_3 ;
}
int F_5 ( struct V_1 * V_9 )
{
struct V_1 * V_3 = (struct V_1 * ) V_9 ;
F_6 ( V_3 -> V_7 -> V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_3 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 ;
int V_15 = 0 ;
if ( V_11 -> V_16 >= V_3 -> V_17 ) {
V_15 = - V_18 ;
goto error;
}
V_14 = & V_3 -> V_19 [ V_11 -> V_16 ] ;
if ( V_14 -> type == V_20 ) {
F_8 ( V_3 -> V_21 ,
L_2 , V_11 -> V_16 ) ;
V_15 = - V_22 ;
goto error;
}
V_15 = F_9 ( V_14 , 1 , & V_11 -> V_23 ) ;
if ( V_15 < 0 ) {
F_8 ( V_3 -> V_21 , L_3 ) ;
V_15 = - V_18 ;
goto error;
}
if ( V_14 -> V_24 ) {
V_15 = - V_25 ;
goto error;
}
V_14 -> V_24 = V_3 ;
switch ( V_11 -> V_11 ) {
case V_26 :
V_15 = V_14 -> V_27 ( V_3 , V_14 , V_11 , V_12 ) ;
break;
case V_28 :
V_15 = V_14 -> V_29 ( V_3 , V_14 , V_11 , V_12 ) ;
break;
default:
V_15 = - V_18 ;
break;
}
V_14 -> V_24 = NULL ;
error:
return V_15 ;
}
int F_10 ( struct V_1 * V_3 , unsigned int V_16 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_10 V_11 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_11 = V_28 ;
V_11 . V_32 = 1 ;
V_11 . V_16 = V_16 ;
V_11 . V_23 = F_11 ( V_30 , 0 , 0 ) ;
return F_7 ( V_3 , & V_11 , & V_31 ) ;
}
int F_12 ( struct V_1 * V_3 , unsigned int V_16 ,
unsigned int V_33 , unsigned int * V_34 )
{
struct V_10 V_11 ;
unsigned int V_12 [ 2 ] ;
int V_15 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_11 = V_26 ;
V_11 . V_32 = 2 ;
V_11 . V_16 = V_16 ;
V_12 [ 0 ] = V_33 ;
V_12 [ 1 ] = * V_34 ;
V_15 = F_7 ( V_3 , & V_11 , V_12 ) ;
* V_34 = V_12 [ 1 ] ;
return V_15 ;
}
int F_13 ( struct V_1 * V_3 , int type ,
unsigned int V_35 )
{
struct V_13 * V_14 ;
if ( V_35 > V_3 -> V_17 )
return - V_36 ;
for (; V_35 < V_3 -> V_17 ; V_35 ++ ) {
V_14 = & V_3 -> V_19 [ V_35 ] ;
if ( V_14 -> type == type )
return V_35 ;
}
return - 1 ;
}
int F_14 ( struct V_1 * V_3 , unsigned int V_37 )
{
struct V_13 * V_14 = & V_3 -> V_19 [ V_37 ] ;
return V_14 -> V_38 ;
}
