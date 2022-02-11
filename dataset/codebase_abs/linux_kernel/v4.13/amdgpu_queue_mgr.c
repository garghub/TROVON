static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
if ( ! V_2 )
return - V_4 ;
if ( V_3 > V_5 )
return - V_4 ;
V_2 -> V_3 = V_3 ;
F_2 ( & V_2 -> V_6 ) ;
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 ,
int V_9 )
{
return V_2 -> V_7 [ V_9 ] ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_9 , struct V_8 * V_10 )
{
if ( F_5 ( V_2 -> V_7 [ V_9 ] ) ) {
F_6 ( L_1 ) ;
return - V_4 ;
}
V_2 -> V_7 [ V_9 ] = V_10 ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
int V_9 ,
struct V_8 * * V_13 )
{
switch ( V_2 -> V_3 ) {
case V_14 :
* V_13 = & V_12 -> V_15 . V_16 [ V_9 ] ;
break;
case V_17 :
* V_13 = & V_12 -> V_15 . V_18 [ V_9 ] ;
break;
case V_19 :
* V_13 = & V_12 -> V_20 . V_21 [ V_9 ] . V_9 ;
break;
case V_22 :
* V_13 = & V_12 -> V_23 . V_9 ;
break;
case V_24 :
* V_13 = & V_12 -> V_25 . V_9 [ V_9 ] ;
break;
case V_26 :
* V_13 = & V_12 -> V_23 . V_27 [ V_9 ] ;
break;
case V_28 :
* V_13 = & V_12 -> V_29 . V_30 ;
break;
case V_31 :
* V_13 = & V_12 -> V_29 . V_27 [ V_9 ] ;
break;
default:
* V_13 = NULL ;
F_6 ( L_2 , V_2 -> V_3 ) ;
return - V_4 ;
}
return F_4 ( V_2 , V_9 , * V_13 ) ;
}
static enum V_32 F_8 ( int V_3 )
{
switch ( V_3 ) {
case V_14 :
return V_33 ;
case V_17 :
return V_34 ;
case V_19 :
return V_35 ;
case V_22 :
return V_36 ;
case V_24 :
return V_37 ;
default:
F_6 ( L_3 , V_3 ) ;
return - 1 ;
}
}
static int F_9 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
int V_38 ,
struct V_8 * * V_13 )
{
int V_39 , V_40 , V_41 ;
int V_42 = F_8 ( V_2 -> V_3 ) ;
int V_43 [ V_44 ] ;
struct V_8 * V_9 ;
memset ( V_43 , 0xff , sizeof( V_43 ) ) ;
for ( V_40 = 0 , V_41 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_9 = V_2 -> V_7 [ V_40 ] ;
if ( V_9 )
V_43 [ V_41 ++ ] = V_9 -> V_45 ;
}
V_39 = F_10 ( V_12 , V_42 , V_43 ,
V_41 , V_13 ) ;
if ( V_39 )
return V_39 ;
return F_4 ( V_2 , V_38 , * V_13 ) ;
}
int F_11 ( struct V_11 * V_12 ,
struct V_46 * V_47 )
{
int V_40 , V_39 ;
if ( ! V_12 || ! V_47 )
return - V_4 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
for ( V_40 = 0 ; V_40 < V_5 ; ++ V_40 ) {
V_39 = F_1 ( & V_47 -> V_2 [ V_40 ] , V_40 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
int F_12 ( struct V_11 * V_12 ,
struct V_46 * V_47 )
{
return 0 ;
}
int F_13 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
int V_3 , int V_21 , int V_9 ,
struct V_8 * * V_13 )
{
int V_39 , V_48 ;
struct V_1 * V_2 = & V_47 -> V_2 [ V_3 ] ;
if ( ! V_12 || ! V_47 || ! V_13 )
return - V_4 ;
if ( V_3 >= V_5 )
return - V_4 ;
if ( V_9 >= V_44 )
return - V_4 ;
if ( V_21 != 0 ) {
F_6 ( L_4 , V_21 ) ;
return - V_4 ;
}
switch ( V_3 ) {
case V_14 :
V_48 = V_12 -> V_15 . V_49 ;
break;
case V_17 :
V_48 = V_12 -> V_15 . V_50 ;
break;
case V_19 :
V_48 = V_12 -> V_20 . V_51 ;
break;
case V_22 :
V_48 = 1 ;
break;
case V_24 :
V_48 = V_12 -> V_25 . V_52 ;
break;
case V_26 :
V_48 = V_12 -> V_23 . V_53 ;
break;
case V_28 :
V_48 = 1 ;
break;
case V_31 :
V_48 = V_12 -> V_29 . V_53 ;
break;
default:
F_6 ( L_5 , V_3 ) ;
return - V_4 ;
}
if ( V_9 >= V_48 ) {
F_6 ( L_6 ,
V_9 , V_48 , V_3 ) ;
return - V_4 ;
}
F_14 ( & V_2 -> V_6 ) ;
* V_13 = F_3 ( V_2 , V_9 ) ;
if ( * V_13 ) {
V_39 = 0 ;
goto V_54;
}
switch ( V_2 -> V_3 ) {
case V_14 :
case V_22 :
case V_24 :
case V_26 :
case V_28 :
case V_31 :
V_39 = F_7 ( V_12 , V_2 , V_9 , V_13 ) ;
break;
case V_19 :
case V_17 :
V_39 = F_9 ( V_12 , V_2 , V_9 , V_13 ) ;
break;
default:
* V_13 = NULL ;
V_39 = - V_4 ;
F_6 ( L_2 , V_2 -> V_3 ) ;
}
V_54:
F_15 ( & V_2 -> V_6 ) ;
return V_39 ;
}
