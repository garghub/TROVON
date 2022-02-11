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
V_2 -> V_25 |= V_26 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 ,
V_7 ) ||
! ( V_2 -> V_25 & V_26 ) )
return;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_2 -> V_4 . V_23 = V_24 ;
V_2 -> V_25 &= ~ V_26 ;
}
static void F_6 ( void * V_27 , T_1 * V_28 ,
struct V_29 * V_30 )
{
bool * V_31 = V_27 ;
if ( F_7 ( V_30 ) != V_32 )
* V_31 = false ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_4 . V_8 ;
bool V_31 ;
F_9 ( & V_2 -> V_35 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_36 ;
F_10 ( V_2 -> V_37 ,
V_38 ,
F_6 , & V_31 ) ;
if ( ! V_31 ) {
F_11 ( V_2 , L_1 ) ;
return - V_36 ;
}
V_2 -> V_4 . V_23 = V_24 ;
return F_12 ( V_2 , F_13 ( V_39 ,
V_40 , 0 ) ,
0 , sizeof( * V_34 ) , V_34 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_42 V_34 = {
. V_9 = F_3 ( V_43 ) ,
. V_44 = V_41 ,
} ;
F_9 ( & V_2 -> V_35 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_36 ;
if ( V_41 != V_2 -> V_4 . V_23 ) {
F_15 ( V_2 , L_2 ,
V_41 , V_2 -> V_4 . V_23 ) ;
return - V_36 ;
}
V_2 -> V_4 . V_23 = V_24 ;
return F_12 ( V_2 , F_13 ( V_39 ,
V_40 , 0 ) ,
0 , sizeof( V_34 ) , & V_34 ) ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_45 * V_34 = & V_2 -> V_4 . V_12 ;
struct V_46 * V_47 = F_17 ( V_30 ) ;
F_9 ( & V_2 -> V_35 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_36 ;
if ( V_30 -> V_48 || V_30 -> type != V_49 ||
! V_47 -> V_50 ) {
F_15 ( V_2 , L_3 ) ;
return - V_51 ;
}
V_34 -> V_14 = V_47 -> V_52 . V_14 ;
memcpy ( V_34 -> V_53 , V_30 -> V_54 , V_55 ) ;
return F_12 ( V_2 , F_13 ( V_39 ,
V_40 , 0 ) ,
0 , sizeof( * V_34 ) , V_34 ) ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_56 V_34 = {
. V_41 = F_13 ( V_39 , V_40 , 0 ) ,
. V_57 = { sizeof( V_2 -> V_4 . V_16 ) , } ,
. V_58 = { V_59 , } ,
} ;
F_9 ( & V_2 -> V_35 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_36 ;
if ( F_7 ( V_30 ) != V_32 ) {
F_15 ( V_2 , L_4 ) ;
return - V_51 ;
}
if ( V_2 -> V_4 . V_23 !=
V_24 ) {
F_15 ( V_2 , L_5 ,
V_2 -> V_4 . V_23 ) ;
return - V_51 ;
}
V_2 -> V_4 . V_23 = V_2 -> V_4 . V_16 . V_44 ;
V_34 . V_60 [ 0 ] = & V_2 -> V_4 . V_16 ;
return F_19 ( V_2 , & V_34 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
F_9 ( & V_2 -> V_35 ) ;
if ( ! F_2 ( & V_2 -> V_5 -> V_6 , V_7 ) )
return - V_36 ;
if ( F_7 ( V_30 ) != V_32 ) {
F_15 ( V_2 , L_6 ) ;
return - V_51 ;
}
return F_12 ( V_2 , F_13 ( V_39 ,
V_40 , 0 ) ,
0 , sizeof( V_2 -> V_4 . V_21 ) ,
& V_2 -> V_4 . V_21 ) ;
}
static int F_21 ( struct V_1 * V_2 , void * V_60 )
{
struct V_61 * V_62 = ( void * ) V_60 ;
if ( V_62 -> V_44 != V_2 -> V_4 . V_23 ) {
F_15 ( V_2 , L_7 ,
V_62 -> V_44 , V_2 -> V_4 . V_23 ) ;
return - V_51 ;
}
memcpy ( & V_2 -> V_4 . V_63 , V_62 ,
sizeof( struct V_61 ) ) ;
V_2 -> V_4 . V_23 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_60 )
{
struct V_64 * V_62 = (struct V_64 * ) V_60 ;
F_11 ( V_2 , L_8 , V_62 -> V_65 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_60 )
{
struct V_66 * V_67 =
(struct V_66 * ) V_60 ;
F_11 ( V_2 , L_9 ,
V_67 -> V_53 , V_67 -> V_68 , V_67 -> V_69 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_72 * V_73 = F_25 ( V_71 ) ;
struct V_74 * V_62 = ( void * ) V_73 -> V_60 ;
F_9 ( & V_2 -> V_35 ) ;
switch ( F_26 ( V_62 -> V_9 ) ) {
case V_75 :
F_21 ( V_2 , V_62 -> V_60 ) ;
break;
case V_76 :
F_22 ( V_2 , V_62 -> V_60 ) ;
break;
case V_77 :
F_23 ( V_2 , V_62 -> V_60 ) ;
break;
default:
F_15 ( V_2 , L_10 ,
V_62 -> V_9 ) ;
break;
}
}
