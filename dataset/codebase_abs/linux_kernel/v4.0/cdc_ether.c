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
struct V_44 * V_2 = NULL ;
struct V_45 * V_46 = NULL ;
if ( sizeof( V_10 -> V_13 ) < sizeof( * V_12 ) )
return - V_47 ;
if ( V_36 == 0 && V_10 -> V_27 -> V_48 -> V_37 ) {
V_34 = V_10 -> V_27 -> V_48 -> V_35 ;
V_36 = V_10 -> V_27 -> V_48 -> V_37 ;
F_10 ( & V_15 -> V_10 , L_1 ) ;
}
if ( V_36 == 0 ) {
struct V_49 * V_50 ;
V_50 = V_15 -> V_31 -> V_51 ;
if ( V_50 ) {
V_34 = V_50 -> V_35 ;
V_36 = V_50 -> V_37 ;
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
while ( V_36 > 3 ) {
if ( V_34 [ 1 ] != V_52 )
goto V_53;
switch ( V_34 [ 2 ] ) {
case V_54 :
if ( V_12 -> V_55 ) {
F_10 ( & V_15 -> V_10 , L_3 ) ;
goto V_56;
}
V_12 -> V_55 = ( void * ) V_34 ;
if ( V_12 -> V_55 -> V_57 != sizeof( * V_12 -> V_55 ) ) {
F_10 ( & V_15 -> V_10 , L_4 ,
V_12 -> V_55 -> V_57 ) ;
goto V_56;
}
break;
case V_58 :
if ( V_40 ) {
struct V_59 * V_60 ;
V_60 = ( void * ) V_34 ;
if ( V_60 -> V_61 ) {
F_10 ( & V_15 -> V_10 ,
L_5
L_6 ,
V_60 -> V_61 ) ;
goto V_56;
}
}
break;
case V_62 :
if ( V_12 -> V_63 ) {
F_10 ( & V_15 -> V_10 , L_7 ) ;
goto V_56;
}
V_12 -> V_63 = ( void * ) V_34 ;
if ( V_12 -> V_63 -> V_57 != sizeof( * V_12 -> V_63 ) ) {
F_10 ( & V_15 -> V_10 , L_8 ,
V_12 -> V_63 -> V_57 ) ;
goto V_56;
}
V_12 -> V_16 = F_11 ( V_10 -> V_27 ,
V_12 -> V_63 -> V_64 ) ;
V_12 -> V_13 = F_11 ( V_10 -> V_27 ,
V_12 -> V_63 -> V_65 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 ) {
F_10 ( & V_15 -> V_10 ,
L_9 ,
V_12 -> V_63 -> V_64 ,
V_12 -> V_16 ,
V_12 -> V_63 -> V_65 ,
V_12 -> V_13 ) ;
if ( V_40 ) {
V_41 = true ;
goto V_53;
}
goto V_56;
}
if ( V_12 -> V_16 != V_15 ) {
F_10 ( & V_15 -> V_10 , L_10 ) ;
if ( V_12 -> V_13 == V_15 ) {
V_12 -> V_13 = V_12 -> V_16 ;
V_12 -> V_16 = V_15 ;
} else
goto V_56;
}
if ( V_12 -> V_16 == V_12 -> V_13 )
goto V_53;
V_38 = & V_12 -> V_13 -> V_31 -> V_2 ;
if ( V_38 -> V_3 != V_66 ) {
F_10 ( & V_15 -> V_10 , L_11 ,
V_38 -> V_3 ) ;
goto V_56;
}
break;
case V_67 :
if ( V_12 -> V_68 ) {
F_10 ( & V_15 -> V_10 , L_12 ) ;
goto V_56;
}
V_12 -> V_68 = ( void * ) V_34 ;
if ( V_12 -> V_68 -> V_57 != sizeof( * V_12 -> V_68 ) ) {
F_10 ( & V_15 -> V_10 , L_13 ,
V_12 -> V_68 -> V_57 ) ;
goto V_56;
}
V_10 -> V_69 = F_12 (
V_12 -> V_68 -> V_70 ) ;
break;
case V_71 :
if ( V_2 ) {
F_10 ( & V_15 -> V_10 , L_14 ) ;
goto V_56;
}
V_2 = ( void * ) V_34 ;
if ( V_2 -> V_57 != sizeof( * V_2 ) )
goto V_56;
if ( memcmp ( & V_2 -> V_72 , V_73 , 16 ) )
goto V_56;
break;
case V_74 :
if ( V_46 ) {
F_10 ( & V_15 -> V_10 , L_15 ) ;
goto V_56;
}
V_46 = ( void * ) V_34 ;
if ( V_46 -> V_75 == 0 ) {
if ( V_46 -> V_57 < ( sizeof( * V_46 ) + 1 ) )
goto V_56;
} else
goto V_56;
break;
}
V_53:
V_36 -= V_34 [ 0 ] ;
V_34 += V_34 [ 0 ] ;
}
if ( V_40 && ( ! V_12 -> V_63 || V_41 ) ) {
V_12 -> V_16 = F_11 ( V_10 -> V_27 , 0 ) ;
V_12 -> V_13 = F_11 ( V_10 -> V_27 , 1 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_13 || V_12 -> V_16 != V_15 ) {
F_10 ( & V_15 -> V_10 ,
L_16 ,
V_12 -> V_16 ,
V_12 -> V_13 ) ;
goto V_56;
}
} else if ( ! V_12 -> V_55 || ! V_12 -> V_63 || ( ! V_40 && ! V_12 -> V_68 ) ) {
F_10 ( & V_15 -> V_10 , L_17 ,
V_12 -> V_55 ? L_18 : L_19 ,
V_12 -> V_63 ? L_18 : L_20 ,
V_12 -> V_68 ? L_18 : L_21 ) ;
goto V_56;
}
if ( V_12 -> V_13 != V_12 -> V_16 ) {
V_39 = F_13 ( V_43 , V_12 -> V_13 , V_10 ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_39 = F_14 ( V_10 , V_12 -> V_13 ) ;
if ( V_39 < 0 ) {
F_15 ( V_12 -> V_13 , NULL ) ;
if ( V_12 -> V_13 != V_12 -> V_16 )
F_16 ( V_43 , V_12 -> V_13 ) ;
return V_39 ;
}
if ( V_12 -> V_13 != V_12 -> V_16 )
V_10 -> V_39 = NULL ;
if ( V_12 -> V_16 -> V_31 -> V_2 . V_76 == 1 ) {
struct V_77 * V_2 ;
V_10 -> V_39 = & V_12 -> V_16 -> V_31 -> V_51 [ 0 ] ;
V_2 = & V_10 -> V_39 -> V_2 ;
if ( ! F_17 ( V_2 ) ||
( F_12 ( V_2 -> V_78 )
< sizeof( struct V_79 ) ) ||
! V_2 -> V_80 ) {
F_10 ( & V_15 -> V_10 , L_22 ) ;
V_10 -> V_39 = NULL ;
}
}
if ( V_40 && ! V_10 -> V_39 ) {
F_10 ( & V_15 -> V_10 , L_23 ) ;
F_15 ( V_12 -> V_13 , NULL ) ;
F_16 ( V_43 , V_12 -> V_13 ) ;
return - V_81 ;
}
F_4 ( V_10 ) ;
return 0 ;
V_56:
F_18 ( & V_10 -> V_27 -> V_10 , L_24 ) ;
return - V_81 ;
}
void F_19 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
struct V_42 * V_43 = F_9 ( V_15 ) ;
if ( V_12 -> V_13 == V_12 -> V_16 )
return;
if ( V_15 == V_12 -> V_16 && V_12 -> V_13 ) {
F_15 ( V_12 -> V_13 , NULL ) ;
F_16 ( V_43 , V_12 -> V_13 ) ;
V_12 -> V_13 = NULL ;
}
else if ( V_15 == V_12 -> V_13 && V_12 -> V_16 ) {
F_15 ( V_12 -> V_16 , NULL ) ;
F_16 ( V_43 , V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
}
}
static void F_20 ( struct V_9 * V_10 , T_3 * V_82 )
{
F_21 ( V_10 , V_83 , V_10 -> V_18 ,
L_25 ,
F_22 ( V_82 [ 0 ] ) / 1000 ,
F_22 ( V_82 [ 1 ] ) / 1000 ) ;
}
void F_23 ( struct V_9 * V_10 , struct V_84 * V_84 )
{
struct V_79 * V_85 ;
if ( V_84 -> V_86 < sizeof( * V_85 ) )
return;
if ( F_24 ( V_87 , & V_10 -> V_22 ) ) {
F_20 ( V_10 , ( T_3 * ) V_84 -> V_88 ) ;
return;
}
V_85 = V_84 -> V_88 ;
switch ( V_85 -> V_89 ) {
case V_90 :
F_25 ( V_10 , V_83 , V_10 -> V_18 , L_26 ,
V_85 -> V_91 ? L_27 : L_28 ) ;
F_26 ( V_10 , ! ! V_85 -> V_91 , 0 ) ;
break;
case V_92 :
F_25 ( V_10 , V_83 , V_10 -> V_18 , L_29 ,
V_84 -> V_86 ) ;
if ( V_84 -> V_86 != ( sizeof( * V_85 ) + 8 ) )
F_27 ( V_87 , & V_10 -> V_22 ) ;
else
F_20 ( V_10 , ( T_3 * ) & V_85 [ 1 ] ) ;
break;
default:
F_28 ( V_10 -> V_18 , L_30 ,
V_85 -> V_89 ) ;
break;
}
}
int F_29 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_39 ;
struct V_11 * V_12 = ( void * ) & V_10 -> V_13 ;
F_30 ( ( sizeof( ( (struct V_9 * ) 0 ) -> V_13 )
< sizeof( struct V_11 ) ) ) ;
V_39 = F_8 ( V_10 , V_15 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_31 ( V_10 , V_12 -> V_68 -> V_93 ) ;
if ( V_39 < 0 ) {
F_15 ( V_12 -> V_13 , NULL ) ;
F_16 ( F_9 ( V_15 ) , V_12 -> V_13 ) ;
return V_39 ;
}
return 0 ;
}
