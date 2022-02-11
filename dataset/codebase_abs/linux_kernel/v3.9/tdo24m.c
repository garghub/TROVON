static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
const T_1 * V_7 = V_3 ;
T_1 V_8 ;
int V_9 , V_10 = 0 ;
for (; * V_7 != V_11 ; V_7 ++ ) {
if ( ! V_2 -> V_12 && * V_7 == F_2 ( 0x21 ) )
continue;
V_9 = ( * V_7 >> 30 ) & 0x3 ;
V_8 = * V_7 << ( 7 - V_9 ) ;
switch ( V_9 ) {
case 0 :
V_2 -> V_13 [ 0 ] = ( V_8 >> 8 ) & 0xff ;
V_2 -> V_13 [ 1 ] = V_8 & 0xff ;
break;
case 1 :
V_2 -> V_13 [ 0 ] = ( V_8 >> 16 ) & 0xff ;
V_2 -> V_13 [ 1 ] = ( V_8 >> 8 ) & 0xff ;
V_2 -> V_13 [ 2 ] = V_8 & 0xff ;
break;
case 2 :
V_2 -> V_13 [ 0 ] = ( V_8 >> 24 ) & 0xff ;
V_2 -> V_13 [ 1 ] = ( V_8 >> 16 ) & 0xff ;
V_2 -> V_13 [ 2 ] = ( V_8 >> 8 ) & 0xff ;
V_2 -> V_13 [ 3 ] = V_8 & 0xff ;
break;
default:
continue;
}
V_5 -> V_14 = V_9 + 2 ;
V_10 = F_3 ( V_2 -> V_15 , & V_2 -> V_16 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 , int V_17 )
{
switch ( V_17 ) {
case V_18 :
F_1 ( V_2 , V_19 ) ;
F_1 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_21 ) ;
break;
case V_22 :
F_1 ( V_2 , V_23 ) ;
F_1 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_24 ) ;
break;
default:
return - V_25 ;
}
V_2 -> V_17 = V_17 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_17 )
{
switch ( V_17 ) {
case V_18 :
F_1 ( V_2 , V_26 ) ;
F_1 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_27 ) ;
break;
case V_22 :
F_1 ( V_2 , V_28 ) ;
F_1 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_24 ) ;
break;
default:
return - V_25 ;
}
V_2 -> V_17 = V_17 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_1 ( V_2 , V_29 ) ;
if ( V_10 )
goto V_30;
V_10 = F_1 ( V_2 , V_31 ) ;
if ( V_10 )
goto V_30;
V_10 = V_2 -> V_32 ( V_2 , V_2 -> V_17 ) ;
V_30:
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_33 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_34 )
{
int V_35 = 0 ;
if ( F_9 ( V_34 ) && ! F_9 ( V_2 -> V_34 ) )
V_35 = F_6 ( V_2 ) ;
else if ( ! F_9 ( V_34 ) && F_9 ( V_2 -> V_34 ) )
V_35 = F_7 ( V_2 ) ;
if ( ! V_35 )
V_2 -> V_34 = V_34 ;
return V_35 ;
}
static int F_10 ( struct V_36 * V_37 , int V_34 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
return F_8 ( V_2 , V_34 ) ;
}
static int F_12 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
return V_2 -> V_34 ;
}
static int F_13 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
int V_17 = V_22 ;
if ( V_39 -> V_40 == 640 || V_39 -> V_40 == 480 )
V_17 = V_18 ;
if ( V_2 -> V_17 == V_17 )
return 0 ;
return V_2 -> V_32 ( V_2 , V_17 ) ;
}
static int F_14 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_39 ;
struct V_4 * V_5 ;
struct V_44 * V_45 ;
enum V_46 V_47 ;
int V_10 ;
V_45 = V_42 -> V_48 . V_49 ;
if ( V_45 )
V_47 = V_45 -> V_47 ;
else
V_47 = V_50 ;
V_42 -> V_51 = 8 ;
V_42 -> V_17 = V_52 ;
V_10 = F_15 ( V_42 ) ;
if ( V_10 )
return V_10 ;
V_2 = F_16 ( & V_42 -> V_48 , sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_15 = V_42 ;
V_2 -> V_34 = V_55 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_13 = F_16 ( & V_42 -> V_48 , V_56 , V_53 ) ;
if ( V_2 -> V_13 == NULL )
return - V_54 ;
V_39 = & V_2 -> V_16 ;
V_5 = & V_2 -> V_6 ;
F_17 ( V_39 ) ;
V_5 -> V_57 = 1 ;
V_5 -> V_58 = & V_2 -> V_13 [ 0 ] ;
F_18 ( V_5 , V_39 ) ;
switch ( V_47 ) {
case V_50 :
V_2 -> V_12 = 1 ;
V_2 -> V_32 = F_4 ;
break;
case V_59 :
V_2 -> V_32 = F_5 ;
V_2 -> V_12 = 0 ;
break;
default:
F_19 ( & V_42 -> V_48 , L_1 ) ;
return - V_25 ;
}
V_2 -> V_60 = F_20 ( L_2 , & V_42 -> V_48 ,
V_2 , & V_61 ) ;
if ( F_21 ( V_2 -> V_60 ) )
return F_22 ( V_2 -> V_60 ) ;
F_23 ( V_42 , V_2 ) ;
V_10 = F_8 ( V_2 , V_62 ) ;
if ( V_10 )
goto V_63;
return 0 ;
V_63:
F_24 ( V_2 -> V_60 ) ;
return V_10 ;
}
static int F_25 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
F_8 ( V_2 , V_55 ) ;
F_24 ( V_2 -> V_60 ) ;
return 0 ;
}
static int F_27 ( struct V_41 * V_42 , T_2 V_64 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
return F_8 ( V_2 , V_55 ) ;
}
static int F_28 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
return F_8 ( V_2 , V_62 ) ;
}
static void F_29 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
F_8 ( V_2 , V_55 ) ;
}
