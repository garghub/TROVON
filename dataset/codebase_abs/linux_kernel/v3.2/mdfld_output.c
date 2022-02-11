int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
switch ( V_5 -> V_7 ) {
case V_8 :
case V_9 :
case V_10 :
return true ;
case V_11 :
case V_12 :
case V_13 :
default:
return false ;
}
}
static int F_3 ( struct V_1 * V_2 , int V_14 , int V_15 )
{
struct V_16 * V_17 ;
struct V_16 * V_18 ;
V_17 = F_4 ( sizeof( struct V_16 ) , V_19 ) ;
if ( V_17 == NULL )
return - V_20 ;
V_18 = F_4 ( sizeof( struct V_16 ) , V_19 ) ;
if ( V_18 == NULL ) {
F_5 ( V_17 ) ;
return - V_20 ;
}
switch ( V_15 ) {
case V_12 :
F_6 ( V_2 , V_17 ) ;
F_7 ( V_2 , V_14 , NULL , V_17 , NULL ) ;
break;
case V_9 :
F_8 ( V_2 , V_18 ) ;
F_7 ( V_2 , V_14 , NULL , NULL , V_18 ) ;
break;
case V_11 :
F_7 ( V_2 , V_14 , NULL , V_17 , NULL ) ;
break;
case V_8 :
F_9 ( V_2 , V_18 ) ;
F_7 ( V_2 , V_14 , NULL , NULL , V_18 ) ;
break;
case V_13 :
F_10 ( V_2 , V_17 ) ;
F_7 ( V_2 , V_14 , NULL , V_17 , NULL ) ;
break;
case V_10 :
F_7 ( V_2 , V_14 , NULL , NULL , V_18 ) ;
break;
case V_21 :
F_6 ( V_2 , V_17 ) ;
F_8 ( V_2 , V_18 ) ;
F_7 ( V_2 , V_14 , NULL , V_17 ,
V_18 ) ;
break;
case V_22 :
break;
case V_23 :
break;
#if 0
case HDMI:
dev_dbg(dev->dev, "Initializing HDMI");
mdfld_hdmi_init(dev, &dev_priv->mode_dev);
break;
#endif
default:
F_11 ( V_2 -> V_2 , L_1 , V_15 ) ;
return - V_20 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int type ;
type = F_1 ( V_2 , 0 ) ;
F_13 ( V_2 -> V_2 , L_2 , type ) ;
F_3 ( V_2 , 0 , type ) ;
if ( V_24 ) {
type = F_1 ( V_2 , 2 ) ;
F_13 ( V_2 -> V_2 , L_3 , type ) ;
F_3 ( V_2 , 2 , type ) ;
}
if ( V_25 )
F_3 ( V_2 , 0 , V_26 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) ) {
if ( V_27 )
F_16 ( V_2 ) ;
else
F_17 ( V_2 ) ;
}
}
