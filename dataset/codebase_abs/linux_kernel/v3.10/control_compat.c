static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
struct V_5 T_1 * V_6 ;
T_2 V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof( * V_6 ) ) ;
if ( F_3 ( V_6 , V_4 , 4 * sizeof( V_9 ) ) )
return - V_10 ;
if ( F_4 ( V_7 , & V_4 -> V_11 ) ||
F_5 ( F_6 ( V_7 ) , & V_6 -> V_11 ) )
return - V_10 ;
V_8 = V_5 ( V_2 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_3 ( V_4 , V_6 , 4 * sizeof( V_9 ) ) )
return - V_10 ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 T_1 * V_4 )
{
struct V_15 * V_6 ;
int V_8 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
V_8 = - V_10 ;
if ( F_9 ( & V_6 -> V_18 , & V_4 -> V_18 , sizeof( V_6 -> V_18 ) ) )
goto error;
if ( F_4 ( V_6 -> V_19 . V_20 . V_21 , & V_4 -> V_19 . V_20 . V_21 ) )
goto error;
F_10 ( V_13 -> V_2 ) ;
V_8 = F_11 ( V_13 -> V_2 , V_22 ) ;
if ( V_8 >= 0 )
V_8 = V_15 ( V_13 , V_6 ) ;
F_12 ( V_13 -> V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = - V_10 ;
if ( F_13 ( & V_4 -> V_18 , & V_6 -> V_18 , sizeof( V_6 -> V_18 ) ) ||
F_13 ( & V_4 -> type , & V_6 -> type , 3 * sizeof( V_9 ) ) )
goto error;
if ( F_5 ( V_6 -> V_23 , & V_4 -> V_23 ) )
goto error;
switch ( V_6 -> type ) {
case V_24 :
case V_25 :
if ( F_5 ( V_6 -> V_19 . integer . V_26 , & V_4 -> V_19 . integer . V_26 ) ||
F_5 ( V_6 -> V_19 . integer . V_27 , & V_4 -> V_19 . integer . V_27 ) ||
F_5 ( V_6 -> V_19 . integer . V_28 , & V_4 -> V_19 . integer . V_28 ) )
goto error;
break;
case V_29 :
if ( F_13 ( & V_4 -> V_19 . V_30 ,
& V_6 -> V_19 . V_30 ,
sizeof( V_6 -> V_19 . V_30 ) ) )
goto error;
break;
case V_31 :
if ( F_13 ( & V_4 -> V_19 . V_20 ,
& V_6 -> V_19 . V_20 ,
sizeof( V_6 -> V_19 . V_20 ) ) )
goto error;
break;
default:
break;
}
V_8 = 0 ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_32 * V_18 ,
int * V_33 )
{
struct V_34 * V_35 ;
struct V_15 * V_36 ;
int V_8 ;
F_16 ( & V_2 -> V_37 ) ;
V_35 = F_17 ( V_2 , V_18 ) ;
if ( ! V_35 ) {
F_18 ( & V_2 -> V_37 ) ;
return - V_38 ;
}
V_36 = F_8 ( sizeof( * V_36 ) , V_16 ) ;
if ( V_36 == NULL ) {
F_18 ( & V_2 -> V_37 ) ;
return - V_17 ;
}
V_36 -> V_18 = * V_18 ;
V_8 = V_35 -> V_36 ( V_35 , V_36 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( V_8 >= 0 ) {
V_8 = V_36 -> type ;
* V_33 = V_36 -> V_39 ;
}
F_14 ( V_36 ) ;
return V_8 ;
}
static int F_19 ( int type , int V_39 )
{
switch ( type ) {
case V_29 :
return sizeof( V_40 ) * V_39 ;
case V_31 :
return sizeof( int ) * V_39 ;
case V_41 :
return 512 ;
case V_42 :
return sizeof( struct V_43 ) ;
default:
return - 1 ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_44 * V_6 ,
struct V_45 T_1 * V_4 ,
int * V_46 , int * V_33 )
{
int V_47 , type , V_48 ;
int V_49 ( V_39 ) ;
unsigned int V_50 ;
if ( F_9 ( & V_6 -> V_18 , & V_4 -> V_18 , sizeof( V_6 -> V_18 ) ) )
return - V_10 ;
if ( F_4 ( V_50 , & V_4 -> V_50 ) )
return - V_10 ;
if ( V_50 )
return - V_51 ;
type = F_15 ( V_2 , & V_6 -> V_18 , & V_39 ) ;
if ( type < 0 )
return type ;
if ( type == V_24 ||
type == V_25 ) {
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ ) {
int V_52 ;
if ( F_4 ( V_52 , & V_4 -> V_19 . integer [ V_47 ] ) )
return - V_10 ;
V_6 -> V_19 . integer . V_19 [ V_47 ] = V_52 ;
}
} else {
V_48 = F_19 ( type , V_39 ) ;
if ( V_48 < 0 ) {
F_21 ( V_53 L_1 , type ) ;
return - V_51 ;
}
if ( F_9 ( V_6 -> V_19 . V_54 . V_6 ,
V_4 -> V_19 . V_6 , V_48 ) )
return - V_10 ;
}
* V_46 = type ;
* V_33 = V_39 ;
return 0 ;
}
static int F_22 ( struct V_45 T_1 * V_4 ,
struct V_44 * V_6 ,
int type , int V_39 )
{
int V_47 , V_48 ;
if ( type == V_24 ||
type == V_25 ) {
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ ) {
int V_52 ;
V_52 = V_6 -> V_19 . integer . V_19 [ V_47 ] ;
if ( F_5 ( V_52 , & V_4 -> V_19 . integer [ V_47 ] ) )
return - V_10 ;
}
} else {
V_48 = F_19 ( type , V_39 ) ;
if ( F_13 ( V_4 -> V_19 . V_6 ,
V_6 -> V_19 . V_54 . V_6 , V_48 ) )
return - V_10 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_45 T_1 * V_4 )
{
struct V_44 * V_6 ;
int V_8 , type , V_39 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( V_6 == NULL )
return - V_17 ;
if ( ( V_8 = F_20 ( V_2 , V_6 , V_4 , & type , & V_39 ) ) < 0 )
goto error;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 , V_22 ) ;
if ( V_8 >= 0 )
V_8 = F_24 ( V_2 , V_6 ) ;
F_12 ( V_2 ) ;
if ( V_8 >= 0 )
V_8 = F_22 ( V_4 , V_6 , type , V_39 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static int F_25 ( struct V_12 * V_55 ,
struct V_45 T_1 * V_4 )
{
struct V_44 * V_6 ;
struct V_1 * V_2 = V_55 -> V_2 ;
int V_8 , type , V_39 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( V_6 == NULL )
return - V_17 ;
if ( ( V_8 = F_20 ( V_2 , V_6 , V_4 , & type , & V_39 ) ) < 0 )
goto error;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 , V_22 ) ;
if ( V_8 >= 0 )
V_8 = F_26 ( V_2 , V_55 , V_6 ) ;
F_12 ( V_2 ) ;
if ( V_8 >= 0 )
V_8 = F_22 ( V_4 , V_6 , type , V_39 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static int F_27 ( struct V_12 * V_55 ,
struct V_14 T_1 * V_4 ,
int V_56 )
{
struct V_15 * V_6 ;
int V_8 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
V_8 = - V_10 ;
\
if ( F_9 ( & V_6 -> V_18 , & V_4 -> V_18 , sizeof( V_6 -> V_18 ) ) ||
F_9 ( & V_6 -> type , & V_4 -> type , 3 * sizeof( V_9 ) ) )
goto error;
if ( F_4 ( V_6 -> V_23 , & V_4 -> V_23 ) ||
F_4 ( V_6 -> type , & V_4 -> type ) )
goto error;
switch ( V_6 -> type ) {
case V_24 :
case V_25 :
if ( F_4 ( V_6 -> V_19 . integer . V_26 , & V_4 -> V_19 . integer . V_26 ) ||
F_4 ( V_6 -> V_19 . integer . V_27 , & V_4 -> V_19 . integer . V_27 ) ||
F_4 ( V_6 -> V_19 . integer . V_28 , & V_4 -> V_19 . integer . V_28 ) )
goto error;
break;
case V_29 :
if ( F_9 ( & V_6 -> V_19 . V_30 ,
& V_4 -> V_19 . V_30 ,
sizeof( V_6 -> V_19 . V_30 ) ) )
goto error;
break;
case V_31 :
if ( F_9 ( & V_6 -> V_19 . V_20 ,
& V_4 -> V_19 . V_20 ,
sizeof( V_6 -> V_19 . V_20 ) ) )
goto error;
V_6 -> V_19 . V_20 . V_57 =
( V_58 ) F_6 ( V_6 -> V_19 . V_20 . V_57 ) ;
break;
default:
break;
}
V_8 = F_28 ( V_55 , V_6 , V_56 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static inline long F_29 ( struct V_55 * V_55 , unsigned int V_59 , unsigned long V_60 )
{
struct V_12 * V_13 ;
struct V_61 * V_62 ;
void T_1 * V_63 = F_6 ( V_60 ) ;
int V_8 ;
V_13 = V_55 -> V_64 ;
if ( F_30 ( ! V_13 || ! V_13 -> V_2 ) )
return - V_38 ;
switch ( V_59 ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
return F_31 ( V_55 , V_59 , ( unsigned long ) V_63 ) ;
case V_76 :
return F_1 ( V_13 -> V_2 , V_63 ) ;
case V_77 :
return F_7 ( V_13 , V_63 ) ;
case V_78 :
return F_23 ( V_13 -> V_2 , V_63 ) ;
case V_79 :
return F_25 ( V_13 , V_63 ) ;
case V_80 :
return F_27 ( V_13 , V_63 , 0 ) ;
case V_81 :
return F_27 ( V_13 , V_63 , 1 ) ;
}
F_16 ( & V_82 ) ;
F_32 (p, &snd_control_compat_ioctls, list) {
if ( V_62 -> V_83 ) {
V_8 = V_62 -> V_83 ( V_13 -> V_2 , V_13 , V_59 , V_60 ) ;
if ( V_8 != - V_84 ) {
F_18 ( & V_82 ) ;
return V_8 ;
}
}
}
F_18 ( & V_82 ) ;
return - V_84 ;
}
