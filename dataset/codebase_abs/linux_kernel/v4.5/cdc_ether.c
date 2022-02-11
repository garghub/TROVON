static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_4 &&
V_2 -> V_5 == 2 &&
V_2 -> V_6 == 0xff ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_7 &&
V_2 -> V_5 == 1 &&
V_2 -> V_6 == 1 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_8 &&
V_2 -> V_5 == 1 &&
V_2 -> V_6 == 3 ) ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 * V_18 = V_10 -> V_18 ;
T_1 V_19 = V_20
| V_21 ;
if ( V_18 -> V_22 & V_23 )
V_19 |= V_24 ;
if ( ! F_5 ( V_18 ) || ( V_18 -> V_22 & V_25 ) )
V_19 |= V_26 ;
F_6 ( V_10 -> V_27 ,
F_7 ( V_10 -> V_27 , 0 ) ,
V_28 ,
V_29 | V_30 ,
V_19 ,
V_15 -> V_31 -> V_2 . V_32 ,
NULL ,
0 ,
V_33
) ;
}
int F_8 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
T_2 * V_34 = V_15 -> V_31 -> V_35 ;
int V_36 = V_15 -> V_31 -> V_37 ;
struct V_1 * V_38 ;
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
int V_39 ;
int V_40 ;
bool V_41 = false ;
struct V_42 * V_43 = F_9 ( V_15 ) ;
struct V_44 V_45 ;
if ( sizeof( V_10 -> V_13 ) < sizeof( * V_12 ) )
return - V_46 ;
if ( V_36 == 0 && V_10 -> V_27 -> V_47 -> V_37 ) {
V_34 = V_10 -> V_27 -> V_47 -> V_35 ;
V_36 = V_10 -> V_27 -> V_47 -> V_37 ;
F_10 ( & V_15 -> V_10 , L_1 ) ;
}
if ( V_36 == 0 ) {
struct V_48 * V_49 ;
V_49 = V_15 -> V_31 -> V_50 ;
if ( V_49 ) {
V_34 = V_49 -> V_35 ;
V_36 = V_49 -> V_37 ;
}
if ( V_36 )
F_10 ( & V_15 -> V_10 ,
L_2 ) ;
}
V_40 = ( F_1 ( & V_15 -> V_31 -> V_2 ) ||
F_2 ( & V_15 -> V_31 -> V_2 ) ||
F_3 ( & V_15 -> V_31 -> V_2 ) ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_16 = V_15 ;
F_11 ( & V_45 , V_15 , V_34 , V_36 ) ;
V_12 -> V_51 = V_45 . V_52 ;
V_12 -> V_45 = V_45 . V_53 ;
V_12 -> V_54 = V_45 . V_55 ;
if ( ! V_12 -> V_51 ) {
if ( V_40 )
goto V_56;
else
goto V_57;
}
V_12 -> V_16 = F_12 ( V_10 -> V_27 ,
V_12 -> V_51 -> V_58 ) ;
V_12 -> V_13 = F_12 ( V_10 -> V_27 ,
V_12 -> V_51 -> V_59 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 ) {
F_10 ( & V_15 -> V_10 ,
L_3 ,
V_12 -> V_51 -> V_58 ,
V_12 -> V_16 ,
V_12 -> V_51 -> V_59 ,
V_12 -> V_13 ) ;
if ( V_40 ) {
V_41 = true ;
goto V_56;
}
goto V_57;
}
if ( V_12 -> V_16 != V_15 ) {
F_10 ( & V_15 -> V_10 , L_4 ) ;
if ( V_12 -> V_13 == V_15 ) {
V_12 -> V_13 = V_12 -> V_16 ;
V_12 -> V_16 = V_15 ;
} else
goto V_57;
}
if ( V_12 -> V_16 == V_12 -> V_13 )
goto V_56;
V_38 = & V_12 -> V_13 -> V_31 -> V_2 ;
if ( V_38 -> V_3 != V_60 ) {
F_10 ( & V_15 -> V_10 , L_5 ,
V_38 -> V_3 ) ;
goto V_57;
}
V_56:
if ( V_40 &&
V_45 . V_61 &&
V_45 . V_61 -> V_62 ) {
F_10 ( & V_15 -> V_10 ,
L_6 ,
V_45 . V_61 -> V_62 ) ;
goto V_57;
}
if ( V_45 . V_55 ) {
V_10 -> V_63 = F_13 ( V_12 -> V_54 -> V_64 ) ;
}
if ( V_45 . V_65 &&
memcmp ( V_45 . V_65 -> V_66 , V_67 , 16 ) ) {
F_10 ( & V_15 -> V_10 , L_7 ) ;
goto V_57;
}
if ( V_45 . V_68 &&
V_45 . V_68 -> V_69 <
( sizeof( struct V_68 ) + 1 ) ) {
F_10 ( & V_15 -> V_10 , L_8 ) ;
goto V_57;
}
if ( V_40 && ( ! V_12 -> V_51 || V_41 ) ) {
V_12 -> V_16 = F_12 ( V_10 -> V_27 , 0 ) ;
V_12 -> V_13 = F_12 ( V_10 -> V_27 , 1 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 || V_12 -> V_16 != V_15 ) {
F_10 ( & V_15 -> V_10 ,
L_9 ,
V_12 -> V_16 ,
V_12 -> V_13 ) ;
goto V_57;
}
} else if ( ! V_12 -> V_45 || ( ! V_40 && ! V_12 -> V_54 ) ) {
F_10 ( & V_15 -> V_10 , L_10 ,
V_12 -> V_45 ? L_11 : L_12 ,
V_12 -> V_51 ? L_11 : L_13 ,
V_12 -> V_54 ? L_11 : L_14 ) ;
goto V_57;
}
if ( V_12 -> V_13 != V_12 -> V_16 ) {
V_39 = F_14 ( V_43 , V_12 -> V_13 , V_10 ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_39 = F_15 ( V_10 , V_12 -> V_13 ) ;
if ( V_39 < 0 ) {
F_16 ( V_12 -> V_13 , NULL ) ;
if ( V_12 -> V_13 != V_12 -> V_16 )
F_17 ( V_43 , V_12 -> V_13 ) ;
return V_39 ;
}
if ( V_12 -> V_13 != V_12 -> V_16 )
V_10 -> V_39 = NULL ;
if ( V_12 -> V_16 -> V_31 -> V_2 . V_70 == 1 ) {
struct V_71 * V_2 ;
V_10 -> V_39 = & V_12 -> V_16 -> V_31 -> V_50 [ 0 ] ;
V_2 = & V_10 -> V_39 -> V_2 ;
if ( ! F_18 ( V_2 ) ||
( F_13 ( V_2 -> V_72 )
< sizeof( struct V_73 ) ) ||
! V_2 -> V_74 ) {
F_10 ( & V_15 -> V_10 , L_15 ) ;
V_10 -> V_39 = NULL ;
}
}
if ( V_40 && ! V_10 -> V_39 ) {
F_10 ( & V_15 -> V_10 , L_16 ) ;
F_16 ( V_12 -> V_13 , NULL ) ;
F_17 ( V_43 , V_12 -> V_13 ) ;
return - V_75 ;
}
F_4 ( V_10 ) ;
return 0 ;
V_57:
F_19 ( & V_10 -> V_27 -> V_10 , L_17 ) ;
return - V_75 ;
}
void F_20 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
struct V_42 * V_43 = F_9 ( V_15 ) ;
if ( V_12 -> V_13 == V_12 -> V_16 )
return;
if ( V_15 == V_12 -> V_16 && V_12 -> V_13 ) {
F_16 ( V_12 -> V_13 , NULL ) ;
F_17 ( V_43 , V_12 -> V_13 ) ;
V_12 -> V_13 = NULL ;
}
else if ( V_15 == V_12 -> V_13 && V_12 -> V_16 ) {
F_16 ( V_12 -> V_16 , NULL ) ;
F_17 ( V_43 , V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
}
}
static void F_21 ( struct V_9 * V_10 , T_3 * V_76 )
{
F_22 ( V_10 , V_77 , V_10 -> V_18 ,
L_18 ,
F_23 ( V_76 [ 0 ] ) / 1000 ,
F_23 ( V_76 [ 1 ] ) / 1000 ) ;
}
void F_24 ( struct V_9 * V_10 , struct V_78 * V_78 )
{
struct V_73 * V_79 ;
if ( V_78 -> V_80 < sizeof( * V_79 ) )
return;
if ( F_25 ( V_81 , & V_10 -> V_22 ) ) {
F_21 ( V_10 , ( T_3 * ) V_78 -> V_82 ) ;
return;
}
V_79 = V_78 -> V_82 ;
switch ( V_79 -> V_83 ) {
case V_84 :
F_26 ( V_10 , V_77 , V_10 -> V_18 , L_19 ,
V_79 -> V_85 ? L_20 : L_21 ) ;
F_27 ( V_10 , ! ! V_79 -> V_85 , 0 ) ;
break;
case V_86 :
F_26 ( V_10 , V_77 , V_10 -> V_18 , L_22 ,
V_78 -> V_80 ) ;
if ( V_78 -> V_80 != ( sizeof( * V_79 ) + 8 ) )
F_28 ( V_81 , & V_10 -> V_22 ) ;
else
F_21 ( V_10 , ( T_3 * ) & V_79 [ 1 ] ) ;
break;
default:
F_29 ( V_10 -> V_18 , L_23 ,
V_79 -> V_83 ) ;
break;
}
}
int F_30 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_39 ;
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
F_31 ( ( sizeof( ( (struct V_9 * ) 0 ) -> V_13 )
< sizeof( struct V_11 ) ) ) ;
V_39 = F_8 ( V_10 , V_15 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_32 ( V_10 , V_12 -> V_54 -> V_87 ) ;
if ( V_39 < 0 ) {
F_16 ( V_12 -> V_13 , NULL ) ;
F_17 ( F_9 ( V_15 ) , V_12 -> V_13 ) ;
return V_39 ;
}
return 0 ;
}
