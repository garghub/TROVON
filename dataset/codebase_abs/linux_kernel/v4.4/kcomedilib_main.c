struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 , * V_4 = NULL ;
unsigned int V_5 ;
if ( strncmp ( V_2 , L_1 , 11 ) != 0 )
return NULL ;
if ( F_2 ( V_2 + 11 , 0 , & V_5 ) )
return NULL ;
if ( V_5 >= V_6 )
return NULL ;
V_3 = F_3 ( V_5 ) ;
if ( ! V_3 )
return NULL ;
F_4 ( & V_3 -> V_7 ) ;
if ( V_3 -> V_8 )
V_4 = V_3 ;
else
V_4 = NULL ;
F_5 ( & V_3 -> V_7 ) ;
if ( ! V_4 )
F_6 ( V_3 ) ;
return V_4 ;
}
int F_7 ( struct V_1 * V_3 )
{
F_6 ( V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_3 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_12 * V_13 ;
int V_14 ;
F_9 ( & V_3 -> V_15 ) ;
if ( ! V_3 -> V_8 ) {
V_14 = - V_16 ;
goto error;
}
if ( V_10 -> V_17 >= V_3 -> V_18 ) {
V_14 = - V_16 ;
goto error;
}
V_13 = & V_3 -> V_19 [ V_10 -> V_17 ] ;
if ( V_13 -> type == V_20 ) {
F_10 ( V_3 -> V_21 ,
L_2 , V_10 -> V_17 ) ;
V_14 = - V_22 ;
goto error;
}
V_14 = F_11 ( V_13 , 1 , & V_10 -> V_23 ) ;
if ( V_14 < 0 ) {
F_10 ( V_3 -> V_21 , L_3 ) ;
V_14 = - V_16 ;
goto error;
}
if ( V_13 -> V_24 ) {
V_14 = - V_25 ;
goto error;
}
V_13 -> V_24 = V_3 ;
switch ( V_10 -> V_10 ) {
case V_26 :
V_14 = V_13 -> V_27 ( V_3 , V_13 , V_10 , V_11 ) ;
break;
case V_28 :
V_14 = V_13 -> V_29 ( V_3 , V_13 , V_10 , V_11 ) ;
break;
default:
V_14 = - V_16 ;
break;
}
V_13 -> V_24 = NULL ;
error:
F_12 ( & V_3 -> V_15 ) ;
return V_14 ;
}
int F_13 ( struct V_1 * V_3 , unsigned int V_17 ,
unsigned int V_30 , unsigned int * V_31 )
{
struct V_9 V_10 ;
unsigned int V_11 [ 2 ] ;
int V_14 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_10 = V_28 ;
V_10 . V_32 = 2 ;
V_10 . V_17 = V_17 ;
V_10 . V_23 = F_14 ( V_30 , 0 , 0 ) ;
V_11 [ 0 ] = V_33 ;
V_11 [ 1 ] = 0 ;
V_14 = F_8 ( V_3 , & V_10 , V_11 ) ;
if ( V_14 >= 0 )
* V_31 = V_11 [ 1 ] ;
return V_14 ;
}
int F_15 ( struct V_1 * V_3 , unsigned int V_17 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_10 = V_28 ;
V_10 . V_32 = 1 ;
V_10 . V_17 = V_17 ;
V_10 . V_23 = F_14 ( V_30 , 0 , 0 ) ;
return F_8 ( V_3 , & V_10 , & V_31 ) ;
}
int F_16 ( struct V_1 * V_3 , unsigned int V_17 ,
unsigned int V_34 , unsigned int * V_35 ,
unsigned int V_36 )
{
struct V_9 V_10 ;
unsigned int V_11 [ 2 ] ;
unsigned int V_37 ;
unsigned int V_38 ;
int V_14 ;
V_36 = F_17 ( V_36 ) ;
V_37 = F_18 ( V_3 , V_17 ) ;
if ( V_36 >= V_37 )
return - V_16 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_10 = V_26 ;
V_10 . V_23 = V_36 ;
V_10 . V_32 = 2 ;
V_10 . V_17 = V_17 ;
V_11 [ 0 ] = V_34 ;
V_11 [ 1 ] = * V_35 ;
if ( V_37 <= 32 ) {
V_38 = V_36 ;
if ( V_38 ) {
V_10 . V_23 = 0 ;
V_11 [ 0 ] <<= V_38 ;
V_11 [ 1 ] <<= V_38 ;
}
} else {
V_38 = 0 ;
}
V_14 = F_8 ( V_3 , & V_10 , V_11 ) ;
* V_35 = V_11 [ 1 ] >> V_38 ;
return V_14 ;
}
int F_19 ( struct V_1 * V_3 , int type ,
unsigned int V_39 )
{
struct V_12 * V_13 ;
int V_14 = - V_40 ;
F_4 ( & V_3 -> V_7 ) ;
if ( V_3 -> V_8 )
for (; V_39 < V_3 -> V_18 ; V_39 ++ ) {
V_13 = & V_3 -> V_19 [ V_39 ] ;
if ( V_13 -> type == type ) {
V_14 = V_39 ;
break;
}
}
F_5 ( & V_3 -> V_7 ) ;
return V_14 ;
}
int F_18 ( struct V_1 * V_3 , unsigned int V_41 )
{
int V_32 ;
F_4 ( & V_3 -> V_7 ) ;
if ( ! V_3 -> V_8 || V_41 >= V_3 -> V_18 )
V_32 = 0 ;
else
V_32 = V_3 -> V_19 [ V_41 ] . V_37 ;
F_5 ( & V_3 -> V_7 ) ;
return V_32 ;
}
