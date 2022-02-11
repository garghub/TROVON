void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_8 . V_9 = F_3 ( V_10 ) ;
#ifdef F_4
if ( V_11 ) {
V_4 -> V_12 . V_9 =
F_3 ( V_13 ) ;
V_4 -> V_12 . V_14 = V_15 ;
}
#endif
V_4 -> V_16 . V_9 = F_3 ( V_17 ) ;
V_4 -> V_16 . V_18 = 1 ;
V_4 -> V_16 . V_19 = 1 ;
V_4 -> V_16 . V_20 = 3 ;
V_4 -> V_21 . V_9 =
F_3 ( V_22 ) ;
V_2 -> V_4 . V_23 = V_24 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_2 -> V_4 . V_23 = V_24 ;
}
static void F_6 ( void * V_25 , T_1 * V_26 ,
struct V_27 * V_28 )
{
bool * V_29 = V_25 ;
if ( F_7 ( V_28 ) != V_30 )
* V_29 = false ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_4 . V_8 ;
bool V_29 ;
F_9 ( & V_2 -> V_33 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_34 ;
F_10 ( V_2 -> V_35 ,
V_36 ,
F_6 , & V_29 ) ;
if ( ! V_29 ) {
F_11 ( V_2 , L_1 ) ;
return - V_34 ;
}
V_2 -> V_4 . V_23 = V_24 ;
return F_12 ( V_2 , F_13 ( V_37 ,
V_38 , 0 ) ,
0 , sizeof( * V_32 ) , V_32 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_40 V_32 = {
. V_9 = F_3 ( V_41 ) ,
. V_42 = V_39 ,
} ;
F_9 ( & V_2 -> V_33 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_34 ;
if ( V_39 != V_2 -> V_4 . V_23 ) {
F_15 ( V_2 , L_2 ,
V_39 , V_2 -> V_4 . V_23 ) ;
return - V_34 ;
}
V_2 -> V_4 . V_23 = V_24 ;
return F_12 ( V_2 , F_13 ( V_37 ,
V_38 , 0 ) ,
0 , sizeof( V_32 ) , & V_32 ) ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_43 * V_32 = & V_2 -> V_4 . V_12 ;
struct V_44 * V_45 = F_17 ( V_28 ) ;
F_9 ( & V_2 -> V_33 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_34 ;
if ( V_28 -> V_46 || V_28 -> type != V_47 ) {
F_15 ( V_2 , L_3 ) ;
return - V_48 ;
}
V_32 -> V_14 = V_45 -> V_49 . V_14 ;
return F_12 ( V_2 , F_13 ( V_37 ,
V_38 , 0 ) ,
0 , sizeof( * V_32 ) , V_32 ) ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_50 V_32 = {
. V_39 = F_13 ( V_37 , V_38 , 0 ) ,
. V_51 = { sizeof( V_2 -> V_4 . V_16 ) , } ,
. V_52 = { V_53 , } ,
} ;
F_9 ( & V_2 -> V_33 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_34 ;
if ( F_7 ( V_28 ) != V_30 ) {
F_15 ( V_2 , L_4 ) ;
return - V_48 ;
}
if ( V_2 -> V_4 . V_23 !=
V_24 ) {
F_15 ( V_2 , L_5 ,
V_2 -> V_4 . V_23 ) ;
return - V_48 ;
}
V_2 -> V_4 . V_23 = V_2 -> V_4 . V_16 . V_42 ;
V_32 . V_54 [ 0 ] = & V_2 -> V_4 . V_16 ;
return F_19 ( V_2 , & V_32 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_9 ( & V_2 -> V_33 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_34 ;
if ( F_7 ( V_28 ) != V_30 ) {
F_15 ( V_2 , L_6 ) ;
return - V_48 ;
}
return F_12 ( V_2 , F_13 ( V_37 ,
V_38 , 0 ) ,
0 , sizeof( V_2 -> V_4 . V_21 ) ,
& V_2 -> V_4 . V_21 ) ;
}
static int F_21 ( struct V_1 * V_2 , void * V_54 )
{
struct V_55 * V_56 = ( void * ) V_54 ;
if ( V_56 -> V_42 != V_2 -> V_4 . V_23 ) {
F_15 ( V_2 , L_7 ,
V_56 -> V_42 , V_2 -> V_4 . V_23 ) ;
return - V_48 ;
}
memcpy ( & V_2 -> V_4 . V_57 , V_56 ,
sizeof( struct V_55 ) ) ;
V_2 -> V_4 . V_23 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_54 )
{
struct V_58 * V_56 = (struct V_58 * ) V_54 ;
F_11 ( V_2 , L_8 , V_56 -> V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_54 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_54 ;
F_11 ( V_2 , L_9 ,
V_61 -> V_62 , V_61 -> V_63 , V_61 -> V_64 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = F_25 ( V_66 ) ;
struct V_69 * V_56 = ( void * ) V_68 -> V_54 ;
F_9 ( & V_2 -> V_33 ) ;
switch ( F_26 ( V_56 -> V_9 ) ) {
case V_70 :
F_21 ( V_2 , V_56 -> V_54 ) ;
break;
case V_71 :
F_22 ( V_2 , V_56 -> V_54 ) ;
break;
case V_72 :
F_23 ( V_2 , V_56 -> V_54 ) ;
break;
default:
F_15 ( V_2 , L_10 ,
V_56 -> V_9 ) ;
break;
}
}
