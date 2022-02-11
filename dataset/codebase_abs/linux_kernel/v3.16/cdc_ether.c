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
int F_4 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
T_1 * V_13 = V_12 -> V_14 -> V_15 ;
int V_16 = V_12 -> V_14 -> V_17 ;
struct V_1 * V_18 ;
struct V_19 * V_20 = ( void * ) & V_10 -> V_21 ;
int V_22 ;
int V_23 ;
bool V_24 = false ;
struct V_25 * V_26 = F_5 ( V_12 ) ;
struct V_27 * V_2 = NULL ;
struct V_28 * V_29 = NULL ;
if ( sizeof( V_10 -> V_21 ) < sizeof( * V_20 ) )
return - V_30 ;
if ( V_16 == 0 && V_10 -> V_31 -> V_32 -> V_17 ) {
V_13 = V_10 -> V_31 -> V_32 -> V_15 ;
V_16 = V_10 -> V_31 -> V_32 -> V_17 ;
F_6 ( & V_12 -> V_10 , L_1 ) ;
}
if ( V_16 == 0 ) {
struct V_33 * V_34 ;
V_34 = V_12 -> V_14 -> V_35 ;
if ( V_34 ) {
V_13 = V_34 -> V_15 ;
V_16 = V_34 -> V_17 ;
}
if ( V_16 )
F_6 ( & V_12 -> V_10 ,
L_2 ) ;
}
V_23 = ( F_1 ( & V_12 -> V_14 -> V_2 ) ||
F_2 ( & V_12 -> V_14 -> V_2 ) ||
F_3 ( & V_12 -> V_14 -> V_2 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_36 = V_12 ;
while ( V_16 > 3 ) {
if ( V_13 [ 1 ] != V_37 )
goto V_38;
switch ( V_13 [ 2 ] ) {
case V_39 :
if ( V_20 -> V_40 ) {
F_6 ( & V_12 -> V_10 , L_3 ) ;
goto V_41;
}
V_20 -> V_40 = ( void * ) V_13 ;
if ( V_20 -> V_40 -> V_42 != sizeof( * V_20 -> V_40 ) ) {
F_6 ( & V_12 -> V_10 , L_4 ,
V_20 -> V_40 -> V_42 ) ;
goto V_41;
}
break;
case V_43 :
if ( V_23 ) {
struct V_44 * V_45 ;
V_45 = ( void * ) V_13 ;
if ( V_45 -> V_46 ) {
F_6 ( & V_12 -> V_10 ,
L_5
L_6 ,
V_45 -> V_46 ) ;
goto V_41;
}
}
break;
case V_47 :
if ( V_20 -> V_48 ) {
F_6 ( & V_12 -> V_10 , L_7 ) ;
goto V_41;
}
V_20 -> V_48 = ( void * ) V_13 ;
if ( V_20 -> V_48 -> V_42 != sizeof( * V_20 -> V_48 ) ) {
F_6 ( & V_12 -> V_10 , L_8 ,
V_20 -> V_48 -> V_42 ) ;
goto V_41;
}
V_20 -> V_36 = F_7 ( V_10 -> V_31 ,
V_20 -> V_48 -> V_49 ) ;
V_20 -> V_21 = F_7 ( V_10 -> V_31 ,
V_20 -> V_48 -> V_50 ) ;
if ( ! V_20 -> V_36 || ! V_20 -> V_21 ) {
F_6 ( & V_12 -> V_10 ,
L_9 ,
V_20 -> V_48 -> V_49 ,
V_20 -> V_36 ,
V_20 -> V_48 -> V_50 ,
V_20 -> V_21 ) ;
if ( V_23 ) {
V_24 = true ;
goto V_38;
}
goto V_41;
}
if ( V_20 -> V_36 != V_12 ) {
F_6 ( & V_12 -> V_10 , L_10 ) ;
if ( V_20 -> V_21 == V_12 ) {
V_20 -> V_21 = V_20 -> V_36 ;
V_20 -> V_36 = V_12 ;
} else
goto V_41;
}
if ( V_20 -> V_36 == V_20 -> V_21 )
goto V_38;
V_18 = & V_20 -> V_21 -> V_14 -> V_2 ;
if ( V_18 -> V_3 != V_51 ) {
F_6 ( & V_12 -> V_10 , L_11 ,
V_18 -> V_3 ) ;
goto V_41;
}
break;
case V_52 :
if ( V_20 -> V_53 ) {
F_6 ( & V_12 -> V_10 , L_12 ) ;
goto V_41;
}
V_20 -> V_53 = ( void * ) V_13 ;
if ( V_20 -> V_53 -> V_42 != sizeof( * V_20 -> V_53 ) ) {
F_6 ( & V_12 -> V_10 , L_13 ,
V_20 -> V_53 -> V_42 ) ;
goto V_41;
}
V_10 -> V_54 = F_8 (
V_20 -> V_53 -> V_55 ) ;
break;
case V_56 :
if ( V_2 ) {
F_6 ( & V_12 -> V_10 , L_14 ) ;
goto V_41;
}
V_2 = ( void * ) V_13 ;
if ( V_2 -> V_42 != sizeof( * V_2 ) )
goto V_41;
if ( memcmp ( & V_2 -> V_57 , V_58 , 16 ) )
goto V_41;
break;
case V_59 :
if ( V_29 ) {
F_6 ( & V_12 -> V_10 , L_15 ) ;
goto V_41;
}
V_29 = ( void * ) V_13 ;
if ( V_29 -> V_60 == 0 ) {
if ( V_29 -> V_42 < ( sizeof( * V_29 ) + 1 ) )
goto V_41;
} else
goto V_41;
break;
}
V_38:
V_16 -= V_13 [ 0 ] ;
V_13 += V_13 [ 0 ] ;
}
if ( V_23 && ( ! V_20 -> V_48 || V_24 ) ) {
V_20 -> V_36 = F_7 ( V_10 -> V_31 , 0 ) ;
V_20 -> V_21 = F_7 ( V_10 -> V_31 , 1 ) ;
if ( ! V_20 -> V_36 || ! V_20 -> V_21 || V_20 -> V_36 != V_12 ) {
F_6 ( & V_12 -> V_10 ,
L_16 ,
V_20 -> V_36 ,
V_20 -> V_21 ) ;
goto V_41;
}
} else if ( ! V_20 -> V_40 || ! V_20 -> V_48 || ( ! V_23 && ! V_20 -> V_53 ) ) {
F_6 ( & V_12 -> V_10 , L_17 ,
V_20 -> V_40 ? L_18 : L_19 ,
V_20 -> V_48 ? L_18 : L_20 ,
V_20 -> V_53 ? L_18 : L_21 ) ;
goto V_41;
}
if ( V_20 -> V_21 != V_20 -> V_36 ) {
V_22 = F_9 ( V_26 , V_20 -> V_21 , V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_10 ( V_10 , V_20 -> V_21 ) ;
if ( V_22 < 0 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
if ( V_20 -> V_21 != V_20 -> V_36 )
F_12 ( V_26 , V_20 -> V_21 ) ;
return V_22 ;
}
if ( V_20 -> V_21 != V_20 -> V_36 )
V_10 -> V_22 = NULL ;
if ( V_20 -> V_36 -> V_14 -> V_2 . V_61 == 1 ) {
struct V_62 * V_2 ;
V_10 -> V_22 = & V_20 -> V_36 -> V_14 -> V_35 [ 0 ] ;
V_2 = & V_10 -> V_22 -> V_2 ;
if ( ! F_13 ( V_2 ) ||
( F_8 ( V_2 -> V_63 )
< sizeof( struct V_64 ) ) ||
! V_2 -> V_65 ) {
F_6 ( & V_12 -> V_10 , L_22 ) ;
V_10 -> V_22 = NULL ;
}
}
if ( V_23 && ! V_10 -> V_22 ) {
F_6 ( & V_12 -> V_10 , L_23 ) ;
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( V_26 , V_20 -> V_21 ) ;
return - V_66 ;
}
F_14 ( V_10 -> V_31 ,
F_15 ( V_10 -> V_31 , 0 ) ,
V_67 ,
V_68 | V_69 ,
V_70 | V_71 | V_72 ,
V_12 -> V_14 -> V_2 . V_73 ,
NULL ,
0 ,
V_74
) ;
return 0 ;
V_41:
F_16 ( & V_10 -> V_31 -> V_10 , L_24 ) ;
return - V_66 ;
}
void F_17 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_19 * V_20 = ( void * ) & V_10 -> V_21 ;
struct V_25 * V_26 = F_5 ( V_12 ) ;
if ( V_20 -> V_21 == V_20 -> V_36 )
return;
if ( V_12 == V_20 -> V_36 && V_20 -> V_21 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( V_26 , V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
else if ( V_12 == V_20 -> V_21 && V_20 -> V_36 ) {
F_11 ( V_20 -> V_36 , NULL ) ;
F_12 ( V_26 , V_20 -> V_36 ) ;
V_20 -> V_36 = NULL ;
}
}
static void F_18 ( struct V_9 * V_10 , T_2 * V_75 )
{
F_19 ( V_10 , V_76 , V_10 -> V_77 ,
L_25 ,
F_20 ( V_75 [ 0 ] ) / 1000 ,
F_20 ( V_75 [ 1 ] ) / 1000 ) ;
}
void F_21 ( struct V_9 * V_10 , struct V_78 * V_78 )
{
struct V_64 * V_79 ;
if ( V_78 -> V_80 < sizeof( * V_79 ) )
return;
if ( F_22 ( V_81 , & V_10 -> V_82 ) ) {
F_18 ( V_10 , ( T_2 * ) V_78 -> V_83 ) ;
return;
}
V_79 = V_78 -> V_83 ;
switch ( V_79 -> V_84 ) {
case V_85 :
F_23 ( V_10 , V_76 , V_10 -> V_77 , L_26 ,
V_79 -> V_86 ? L_27 : L_28 ) ;
F_24 ( V_10 , ! ! V_79 -> V_86 , 0 ) ;
break;
case V_87 :
F_23 ( V_10 , V_76 , V_10 -> V_77 , L_29 ,
V_78 -> V_80 ) ;
if ( V_78 -> V_80 != ( sizeof( * V_79 ) + 8 ) )
F_25 ( V_81 , & V_10 -> V_82 ) ;
else
F_18 ( V_10 , ( T_2 * ) & V_79 [ 1 ] ) ;
break;
default:
F_26 ( V_10 -> V_77 , L_30 ,
V_79 -> V_84 ) ;
break;
}
}
int F_27 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_22 ;
struct V_19 * V_20 = ( void * ) & V_10 -> V_21 ;
F_28 ( ( sizeof( ( (struct V_9 * ) 0 ) -> V_21 )
< sizeof( struct V_19 ) ) ) ;
V_22 = F_4 ( V_10 , V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_29 ( V_10 , V_20 -> V_53 -> V_88 ) ;
if ( V_22 < 0 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( F_5 ( V_12 ) , V_20 -> V_21 ) ;
return V_22 ;
}
return 0 ;
}
