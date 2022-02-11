static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
T_1 V_6 [ V_7 ] ;
int V_8 ;
V_8 = F_2 ( V_2 , V_3 , V_6 ) ;
if ( F_3 ( V_8 < 0 ) )
goto abort;
if ( F_3 ( V_8 == 0xff || V_8 != V_5 ) ) {
V_8 = - V_9 ;
goto abort;
}
memcpy ( V_4 , V_6 , V_5 ) ;
V_8 = 0 ;
abort:
return V_8 ;
}
static struct V_10 * F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
struct V_10 * V_4 = F_6 ( V_2 ) ;
struct V_10 * V_13 = V_4 ;
F_7 ( & V_4 -> V_14 ) ;
if ( F_8 ( V_15 , V_4 -> V_16 + V_17 ) || ! V_4 -> V_18 ) {
int V_8 ;
V_8 = F_1 ( V_2 , V_19 ,
V_4 -> V_20 ,
sizeof( V_4 -> V_20 ) ) ;
if ( F_3 ( V_8 < 0 ) ) {
V_13 = F_9 ( V_8 ) ;
goto abort;
}
if ( V_4 -> V_21 ) {
V_8 = F_1 ( V_2 , V_22 ,
V_4 -> V_23 ,
V_4 -> V_21 ) ;
if ( F_3 ( V_8 < 0 ) ) {
V_13 = F_9 ( V_8 ) ;
goto abort;
}
}
if ( V_4 -> V_24 ) {
V_8 = F_1 ( V_2 , V_25 ,
V_4 -> V_26 ,
sizeof( V_4 -> V_26 ) ) ;
if ( F_3 ( V_8 < 0 ) ) {
V_13 = F_9 ( V_8 ) ;
goto abort;
}
}
F_10 ( V_2 , V_27 ) ;
V_4 -> V_16 = V_15 ;
V_4 -> V_18 = 1 ;
}
abort:
F_11 ( & V_4 -> V_14 ) ;
return V_13 ;
}
static long F_12 ( T_1 * V_4 , int V_28 , int V_29 )
{
long V_30 ;
switch ( V_29 ) {
case V_31 :
V_30 = ( V_4 [ V_29 ] + ( V_4 [ V_29 + 1 ] << 8 ) ) * 5 / 2 ;
break;
case V_32 :
V_30 = V_4 [ V_29 ] * 200 ;
break;
case V_33 :
V_30 = V_4 [ V_29 ] * 1000 ;
break;
case V_34 :
V_30 = 97 * 1000 ;
break;
case V_35 :
V_30 = 107 * 1000 ;
break;
default:
F_13 ( 1 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static long F_14 ( T_1 * V_4 , int V_28 , int V_29 )
{
long V_30 ;
switch ( V_29 ) {
case V_36 :
if ( V_28 == V_37 )
V_30 = ( V_4 [ V_29 ] + ( V_4 [ V_29 + 1 ] << 8 ) - 75 ) * 1000 ;
else
V_30 = ( V_4 [ V_29 ] - 75 ) * 1000 ;
break;
case V_38 :
if ( V_28 == V_37 )
V_29 ++ ;
V_30 = ( V_4 [ V_29 ] + ( V_4 [ V_29 + 1 ] << 8 ) ) * 1000000L ;
break;
default:
F_13 ( 1 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static long F_15 ( T_1 * V_4 , int V_28 , int V_29 )
{
long V_30 ;
switch ( V_29 ) {
case V_39 :
case V_40 :
case V_41 :
V_30 = V_4 [ V_29 ] * 100 ;
break;
default:
F_13 ( 1 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static T_2 F_16 ( struct V_11 * V_12 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_45 * V_46 = F_17 ( V_43 ) ;
struct V_10 * V_4 = F_4 ( V_12 ) ;
T_1 V_47 ;
if ( F_18 ( V_4 ) )
return F_19 ( V_4 ) ;
V_47 = V_4 -> V_20 [ V_46 -> V_48 ] & V_46 -> V_29 ;
return snprintf ( V_44 , V_49 , L_1 , ! ! V_47 ) ;
}
static T_2 F_20 ( struct V_11 * V_12 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_50 * V_46 = F_21 ( V_43 ) ;
struct V_10 * V_4 = F_4 ( V_12 ) ;
long V_51 ;
if ( F_18 ( V_4 ) )
return F_19 ( V_4 ) ;
V_51 = F_12 ( V_4 -> V_20 , sizeof( V_4 -> V_20 ) ,
V_46 -> V_29 ) ;
return snprintf ( V_44 , V_49 , L_2 , V_51 ) ;
}
static T_2 F_22 ( struct V_11 * V_12 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_50 * V_46 = F_21 ( V_43 ) ;
struct V_10 * V_4 = F_4 ( V_12 ) ;
long V_51 ;
if ( F_18 ( V_4 ) )
return F_19 ( V_4 ) ;
V_51 = F_14 ( V_4 -> V_23 , sizeof( V_4 -> V_23 ) ,
V_46 -> V_29 ) ;
return snprintf ( V_44 , V_49 , L_2 , V_51 ) ;
}
static T_2 F_23 ( struct V_11 * V_12 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_50 * V_46 = F_21 ( V_43 ) ;
struct V_10 * V_4 = F_4 ( V_12 ) ;
long V_51 ;
if ( F_18 ( V_4 ) )
return F_19 ( V_4 ) ;
V_51 = F_15 ( V_4 -> V_26 , sizeof( V_4 -> V_26 ) ,
V_46 -> V_29 ) ;
return snprintf ( V_44 , V_49 , L_2 , V_51 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_10 * V_4 ;
int V_13 ;
if ( ! F_25 ( V_55 , V_56
| V_57 ) )
return - V_58 ;
V_4 = F_26 ( & V_2 -> V_12 , sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return - V_60 ;
F_27 ( V_2 , V_4 ) ;
F_28 ( & V_4 -> V_14 ) ;
V_13 = F_1 ( V_2 , V_61 ,
V_4 -> V_62 , sizeof( V_4 -> V_62 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_2 , V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
F_29 ( & V_2 -> V_12 , L_3 ,
V_4 -> V_62 [ 0 ] , V_4 -> V_62 [ 1 ] ,
V_4 -> V_62 [ 2 ] ) ;
V_13 = F_30 ( & V_2 -> V_12 . V_63 , & V_64 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_1 ( V_2 , V_22 ,
V_4 -> V_23 ,
sizeof( V_4 -> V_23 ) - 1 ) ;
if ( ! V_13 && ( V_4 -> V_23 [ 0 ] || V_4 -> V_23 [ 1 ] ||
V_4 -> V_23 [ 2 ] ) )
V_4 -> V_21 = sizeof( V_4 -> V_23 ) - 1 ;
else if ( V_13 < 0 ) {
V_13 = F_1 ( V_2 , V_22 ,
V_4 -> V_23 ,
sizeof( V_4 -> V_23 ) ) ;
if ( ! V_13 && ( V_4 -> V_23 [ 0 ] || V_4 -> V_23 [ 1 ] ||
V_4 -> V_23 [ 2 ] || V_4 -> V_23 [ 3 ] ) )
V_4 -> V_21 = sizeof( V_4 -> V_23 ) ;
}
V_13 = 0 ;
if ( V_4 -> V_21 ) {
V_13 = F_30 ( & V_2 -> V_12 . V_63 , & V_65 ) ;
if ( V_13 )
goto V_66;
}
V_13 = F_1 ( V_2 , V_25 ,
V_4 -> V_26 ,
sizeof( V_4 -> V_26 ) ) ;
if ( ! V_13 && ( V_4 -> V_26 [ 0 ] || V_4 -> V_26 [ 1 ] ||
V_4 -> V_26 [ 2 ] || V_4 -> V_26 [ 3 ] ) ) {
V_4 -> V_24 = true ;
V_13 = F_30 ( & V_2 -> V_12 . V_63 , & V_67 ) ;
if ( V_13 )
goto V_66;
}
V_4 -> V_68 = F_31 ( & V_2 -> V_12 ) ;
if ( F_18 ( V_4 -> V_68 ) ) {
V_13 = F_19 ( V_4 -> V_68 ) ;
goto V_66;
}
return 0 ;
V_66:
F_32 ( & V_2 -> V_12 . V_63 , & V_65 ) ;
F_32 ( & V_2 -> V_12 . V_63 , & V_67 ) ;
F_32 ( & V_2 -> V_12 . V_63 , & V_64 ) ;
return V_13 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_4 = F_6 ( V_2 ) ;
F_34 ( V_4 -> V_68 ) ;
F_32 ( & V_2 -> V_12 . V_63 , & V_65 ) ;
F_32 ( & V_2 -> V_12 . V_63 , & V_67 ) ;
F_32 ( & V_2 -> V_12 . V_63 , & V_64 ) ;
return 0 ;
}
