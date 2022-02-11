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
void T_1 * V_45 ,
void T_1 * V_46 ,
int * V_47 , int * V_33 )
{
struct V_48 T_1 * V_4 = V_45 ;
int V_49 , type , V_50 ;
int V_51 ( V_39 ) ;
unsigned int V_52 ;
if ( F_9 ( & V_6 -> V_18 , & V_4 -> V_18 , sizeof( V_6 -> V_18 ) ) )
return - V_10 ;
if ( F_4 ( V_52 , & V_4 -> V_52 ) )
return - V_10 ;
if ( V_52 )
return - V_53 ;
type = F_15 ( V_2 , & V_6 -> V_18 , & V_39 ) ;
if ( type < 0 )
return type ;
if ( type == V_24 ||
type == V_25 ) {
for ( V_49 = 0 ; V_49 < V_39 ; V_49 ++ ) {
T_3 T_1 * V_54 = V_46 ;
int V_55 ;
if ( F_4 ( V_55 , & V_54 [ V_49 ] ) )
return - V_10 ;
V_6 -> V_19 . integer . V_19 [ V_49 ] = V_55 ;
}
} else {
V_50 = F_19 ( type , V_39 ) ;
if ( V_50 < 0 ) {
F_21 ( V_2 -> V_56 , L_1 , type ) ;
return - V_53 ;
}
if ( F_9 ( V_6 -> V_19 . V_57 . V_6 , V_46 , V_50 ) )
return - V_10 ;
}
* V_47 = type ;
* V_33 = V_39 ;
return 0 ;
}
static int F_22 ( void T_1 * V_45 ,
void T_1 * V_46 ,
struct V_44 * V_6 ,
int type , int V_39 )
{
int V_49 , V_50 ;
if ( type == V_24 ||
type == V_25 ) {
for ( V_49 = 0 ; V_49 < V_39 ; V_49 ++ ) {
T_3 T_1 * V_54 = V_46 ;
int V_55 ;
V_55 = V_6 -> V_19 . integer . V_19 [ V_49 ] ;
if ( F_5 ( V_55 , & V_54 [ V_49 ] ) )
return - V_10 ;
}
} else {
V_50 = F_19 ( type , V_39 ) ;
if ( F_13 ( V_46 , V_6 -> V_19 . V_57 . V_6 , V_50 ) )
return - V_10 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
void T_1 * V_45 , void T_1 * V_46 )
{
struct V_44 * V_6 ;
int V_8 , type , V_39 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( V_6 == NULL )
return - V_17 ;
V_8 = F_20 ( V_2 , V_6 , V_45 , V_46 ,
& type , & V_39 ) ;
if ( V_8 < 0 )
goto error;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 , V_22 ) ;
if ( V_8 >= 0 )
V_8 = F_24 ( V_2 , V_6 ) ;
F_12 ( V_2 ) ;
if ( V_8 >= 0 )
V_8 = F_22 ( V_45 , V_46 , V_6 ,
type , V_39 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static int F_25 ( struct V_12 * V_58 ,
void T_1 * V_45 , void T_1 * V_46 )
{
struct V_44 * V_6 ;
struct V_1 * V_2 = V_58 -> V_2 ;
int V_8 , type , V_39 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( V_6 == NULL )
return - V_17 ;
V_8 = F_20 ( V_2 , V_6 , V_45 , V_46 ,
& type , & V_39 ) ;
if ( V_8 < 0 )
goto error;
F_10 ( V_2 ) ;
V_8 = F_11 ( V_2 , V_22 ) ;
if ( V_8 >= 0 )
V_8 = F_26 ( V_2 , V_58 , V_6 ) ;
F_12 ( V_2 ) ;
if ( V_8 >= 0 )
V_8 = F_22 ( V_45 , V_46 , V_6 ,
type , V_39 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_48 T_1 * V_4 )
{
return F_23 ( V_2 , V_4 , & V_4 -> V_19 ) ;
}
static int F_28 ( struct V_12 * V_58 ,
struct V_48 T_1 * V_4 )
{
return F_25 ( V_58 , V_4 , & V_4 -> V_19 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_59 T_1 * V_4 )
{
return F_23 ( V_2 , V_4 , & V_4 -> V_19 ) ;
}
static int F_30 ( struct V_12 * V_58 ,
struct V_59 T_1 * V_4 )
{
return F_25 ( V_58 , V_4 , & V_4 -> V_19 ) ;
}
static int F_31 ( struct V_12 * V_58 ,
struct V_14 T_1 * V_4 ,
int V_60 )
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
V_6 -> V_19 . V_20 . V_61 =
( V_62 ) F_6 ( V_6 -> V_19 . V_20 . V_61 ) ;
break;
default:
break;
}
V_8 = F_32 ( V_58 , V_6 , V_60 ) ;
error:
F_14 ( V_6 ) ;
return V_8 ;
}
static inline long F_33 ( struct V_58 * V_58 , unsigned int V_63 , unsigned long V_64 )
{
struct V_12 * V_13 ;
struct V_65 * V_66 ;
void T_1 * V_67 = F_6 ( V_64 ) ;
int V_8 ;
V_13 = V_58 -> V_68 ;
if ( F_34 ( ! V_13 || ! V_13 -> V_2 ) )
return - V_38 ;
switch ( V_63 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return F_35 ( V_58 , V_63 , ( unsigned long ) V_67 ) ;
case V_80 :
return F_1 ( V_13 -> V_2 , V_67 ) ;
case V_81 :
return F_7 ( V_13 , V_67 ) ;
case V_82 :
return F_27 ( V_13 -> V_2 , V_67 ) ;
case V_83 :
return F_28 ( V_13 , V_67 ) ;
case V_84 :
return F_31 ( V_13 , V_67 , 0 ) ;
case V_85 :
return F_31 ( V_13 , V_67 , 1 ) ;
#ifdef F_36
case V_86 :
return F_29 ( V_13 -> V_2 , V_67 ) ;
case V_87 :
return F_30 ( V_13 , V_67 ) ;
#endif
}
F_16 ( & V_88 ) ;
F_37 (p, &snd_control_compat_ioctls, list) {
if ( V_66 -> V_89 ) {
V_8 = V_66 -> V_89 ( V_13 -> V_2 , V_13 , V_63 , V_64 ) ;
if ( V_8 != - V_90 ) {
F_18 ( & V_88 ) ;
return V_8 ;
}
}
}
F_18 ( & V_88 ) ;
return - V_90 ;
}
