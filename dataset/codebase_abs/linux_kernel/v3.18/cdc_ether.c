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
T_1 V_17 =
V_18 | V_19 |
V_20 ;
if ( V_10 -> V_21 -> V_22 & V_23 )
V_17 |= V_24 ;
F_5 ( V_10 -> V_25 ,
F_6 ( V_10 -> V_25 , 0 ) ,
V_26 ,
V_27 | V_28 ,
V_17 ,
V_15 -> V_29 -> V_2 . V_30 ,
NULL ,
0 ,
V_31
) ;
}
int F_7 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
T_2 * V_32 = V_15 -> V_29 -> V_33 ;
int V_34 = V_15 -> V_29 -> V_35 ;
struct V_1 * V_36 ;
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
int V_37 ;
int V_38 ;
bool V_39 = false ;
struct V_40 * V_41 = F_8 ( V_15 ) ;
struct V_42 * V_2 = NULL ;
struct V_43 * V_44 = NULL ;
if ( sizeof( V_10 -> V_13 ) < sizeof( * V_12 ) )
return - V_45 ;
if ( V_34 == 0 && V_10 -> V_25 -> V_46 -> V_35 ) {
V_32 = V_10 -> V_25 -> V_46 -> V_33 ;
V_34 = V_10 -> V_25 -> V_46 -> V_35 ;
F_9 ( & V_15 -> V_10 , L_1 ) ;
}
if ( V_34 == 0 ) {
struct V_47 * V_48 ;
V_48 = V_15 -> V_29 -> V_49 ;
if ( V_48 ) {
V_32 = V_48 -> V_33 ;
V_34 = V_48 -> V_35 ;
}
if ( V_34 )
F_9 ( & V_15 -> V_10 ,
L_2 ) ;
}
V_38 = ( F_1 ( & V_15 -> V_29 -> V_2 ) ||
F_2 ( & V_15 -> V_29 -> V_2 ) ||
F_3 ( & V_15 -> V_29 -> V_2 ) ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_16 = V_15 ;
while ( V_34 > 3 ) {
if ( V_32 [ 1 ] != V_50 )
goto V_51;
switch ( V_32 [ 2 ] ) {
case V_52 :
if ( V_12 -> V_53 ) {
F_9 ( & V_15 -> V_10 , L_3 ) ;
goto V_54;
}
V_12 -> V_53 = ( void * ) V_32 ;
if ( V_12 -> V_53 -> V_55 != sizeof( * V_12 -> V_53 ) ) {
F_9 ( & V_15 -> V_10 , L_4 ,
V_12 -> V_53 -> V_55 ) ;
goto V_54;
}
break;
case V_56 :
if ( V_38 ) {
struct V_57 * V_58 ;
V_58 = ( void * ) V_32 ;
if ( V_58 -> V_59 ) {
F_9 ( & V_15 -> V_10 ,
L_5
L_6 ,
V_58 -> V_59 ) ;
goto V_54;
}
}
break;
case V_60 :
if ( V_12 -> V_61 ) {
F_9 ( & V_15 -> V_10 , L_7 ) ;
goto V_54;
}
V_12 -> V_61 = ( void * ) V_32 ;
if ( V_12 -> V_61 -> V_55 != sizeof( * V_12 -> V_61 ) ) {
F_9 ( & V_15 -> V_10 , L_8 ,
V_12 -> V_61 -> V_55 ) ;
goto V_54;
}
V_12 -> V_16 = F_10 ( V_10 -> V_25 ,
V_12 -> V_61 -> V_62 ) ;
V_12 -> V_13 = F_10 ( V_10 -> V_25 ,
V_12 -> V_61 -> V_63 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 ) {
F_9 ( & V_15 -> V_10 ,
L_9 ,
V_12 -> V_61 -> V_62 ,
V_12 -> V_16 ,
V_12 -> V_61 -> V_63 ,
V_12 -> V_13 ) ;
if ( V_38 ) {
V_39 = true ;
goto V_51;
}
goto V_54;
}
if ( V_12 -> V_16 != V_15 ) {
F_9 ( & V_15 -> V_10 , L_10 ) ;
if ( V_12 -> V_13 == V_15 ) {
V_12 -> V_13 = V_12 -> V_16 ;
V_12 -> V_16 = V_15 ;
} else
goto V_54;
}
if ( V_12 -> V_16 == V_12 -> V_13 )
goto V_51;
V_36 = & V_12 -> V_13 -> V_29 -> V_2 ;
if ( V_36 -> V_3 != V_64 ) {
F_9 ( & V_15 -> V_10 , L_11 ,
V_36 -> V_3 ) ;
goto V_54;
}
break;
case V_65 :
if ( V_12 -> V_66 ) {
F_9 ( & V_15 -> V_10 , L_12 ) ;
goto V_54;
}
V_12 -> V_66 = ( void * ) V_32 ;
if ( V_12 -> V_66 -> V_55 != sizeof( * V_12 -> V_66 ) ) {
F_9 ( & V_15 -> V_10 , L_13 ,
V_12 -> V_66 -> V_55 ) ;
goto V_54;
}
V_10 -> V_67 = F_11 (
V_12 -> V_66 -> V_68 ) ;
break;
case V_69 :
if ( V_2 ) {
F_9 ( & V_15 -> V_10 , L_14 ) ;
goto V_54;
}
V_2 = ( void * ) V_32 ;
if ( V_2 -> V_55 != sizeof( * V_2 ) )
goto V_54;
if ( memcmp ( & V_2 -> V_70 , V_71 , 16 ) )
goto V_54;
break;
case V_72 :
if ( V_44 ) {
F_9 ( & V_15 -> V_10 , L_15 ) ;
goto V_54;
}
V_44 = ( void * ) V_32 ;
if ( V_44 -> V_73 == 0 ) {
if ( V_44 -> V_55 < ( sizeof( * V_44 ) + 1 ) )
goto V_54;
} else
goto V_54;
break;
}
V_51:
V_34 -= V_32 [ 0 ] ;
V_32 += V_32 [ 0 ] ;
}
if ( V_38 && ( ! V_12 -> V_61 || V_39 ) ) {
V_12 -> V_16 = F_10 ( V_10 -> V_25 , 0 ) ;
V_12 -> V_13 = F_10 ( V_10 -> V_25 , 1 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 || V_12 -> V_16 != V_15 ) {
F_9 ( & V_15 -> V_10 ,
L_16 ,
V_12 -> V_16 ,
V_12 -> V_13 ) ;
goto V_54;
}
} else if ( ! V_12 -> V_53 || ! V_12 -> V_61 || ( ! V_38 && ! V_12 -> V_66 ) ) {
F_9 ( & V_15 -> V_10 , L_17 ,
V_12 -> V_53 ? L_18 : L_19 ,
V_12 -> V_61 ? L_18 : L_20 ,
V_12 -> V_66 ? L_18 : L_21 ) ;
goto V_54;
}
if ( V_12 -> V_13 != V_12 -> V_16 ) {
V_37 = F_12 ( V_41 , V_12 -> V_13 , V_10 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_37 = F_13 ( V_10 , V_12 -> V_13 ) ;
if ( V_37 < 0 ) {
F_14 ( V_12 -> V_13 , NULL ) ;
if ( V_12 -> V_13 != V_12 -> V_16 )
F_15 ( V_41 , V_12 -> V_13 ) ;
return V_37 ;
}
if ( V_12 -> V_13 != V_12 -> V_16 )
V_10 -> V_37 = NULL ;
if ( V_12 -> V_16 -> V_29 -> V_2 . V_74 == 1 ) {
struct V_75 * V_2 ;
V_10 -> V_37 = & V_12 -> V_16 -> V_29 -> V_49 [ 0 ] ;
V_2 = & V_10 -> V_37 -> V_2 ;
if ( ! F_16 ( V_2 ) ||
( F_11 ( V_2 -> V_76 )
< sizeof( struct V_77 ) ) ||
! V_2 -> V_78 ) {
F_9 ( & V_15 -> V_10 , L_22 ) ;
V_10 -> V_37 = NULL ;
}
}
if ( V_38 && ! V_10 -> V_37 ) {
F_9 ( & V_15 -> V_10 , L_23 ) ;
F_14 ( V_12 -> V_13 , NULL ) ;
F_15 ( V_41 , V_12 -> V_13 ) ;
return - V_79 ;
}
F_4 ( V_10 ) ;
return 0 ;
V_54:
F_17 ( & V_10 -> V_25 -> V_10 , L_24 ) ;
return - V_79 ;
}
void F_18 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
struct V_40 * V_41 = F_8 ( V_15 ) ;
if ( V_12 -> V_13 == V_12 -> V_16 )
return;
if ( V_15 == V_12 -> V_16 && V_12 -> V_13 ) {
F_14 ( V_12 -> V_13 , NULL ) ;
F_15 ( V_41 , V_12 -> V_13 ) ;
V_12 -> V_13 = NULL ;
}
else if ( V_15 == V_12 -> V_13 && V_12 -> V_16 ) {
F_14 ( V_12 -> V_16 , NULL ) ;
F_15 ( V_41 , V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
}
}
static void F_19 ( struct V_9 * V_10 , T_3 * V_80 )
{
F_20 ( V_10 , V_81 , V_10 -> V_21 ,
L_25 ,
F_21 ( V_80 [ 0 ] ) / 1000 ,
F_21 ( V_80 [ 1 ] ) / 1000 ) ;
}
void F_22 ( struct V_9 * V_10 , struct V_82 * V_82 )
{
struct V_77 * V_83 ;
if ( V_82 -> V_84 < sizeof( * V_83 ) )
return;
if ( F_23 ( V_85 , & V_10 -> V_22 ) ) {
F_19 ( V_10 , ( T_3 * ) V_82 -> V_86 ) ;
return;
}
V_83 = V_82 -> V_86 ;
switch ( V_83 -> V_87 ) {
case V_88 :
F_24 ( V_10 , V_81 , V_10 -> V_21 , L_26 ,
V_83 -> V_89 ? L_27 : L_28 ) ;
F_25 ( V_10 , ! ! V_83 -> V_89 , 0 ) ;
break;
case V_90 :
F_24 ( V_10 , V_81 , V_10 -> V_21 , L_29 ,
V_82 -> V_84 ) ;
if ( V_82 -> V_84 != ( sizeof( * V_83 ) + 8 ) )
F_26 ( V_85 , & V_10 -> V_22 ) ;
else
F_19 ( V_10 , ( T_3 * ) & V_83 [ 1 ] ) ;
break;
default:
F_27 ( V_10 -> V_21 , L_30 ,
V_83 -> V_87 ) ;
break;
}
}
int F_28 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_37 ;
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
F_29 ( ( sizeof( ( (struct V_9 * ) 0 ) -> V_13 )
< sizeof( struct V_11 ) ) ) ;
V_37 = F_7 ( V_10 , V_15 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_30 ( V_10 , V_12 -> V_66 -> V_91 ) ;
if ( V_37 < 0 ) {
F_14 ( V_12 -> V_13 , NULL ) ;
F_15 ( F_8 ( V_15 ) , V_12 -> V_13 ) ;
return V_37 ;
}
return 0 ;
}
