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
struct V_24 * V_25 = F_5 ( V_12 ) ;
struct V_26 * V_2 = NULL ;
struct V_27 * V_28 = NULL ;
if ( sizeof V_10 -> V_21 < sizeof *V_20 )
return - V_29 ;
if ( V_16 == 0 && V_10 -> V_30 -> V_31 -> V_17 ) {
V_13 = V_10 -> V_30 -> V_31 -> V_15 ;
V_16 = V_10 -> V_30 -> V_31 -> V_17 ;
F_6 ( & V_12 -> V_10 , L_1 ) ;
}
if ( V_16 == 0 ) {
struct V_32 * V_33 ;
V_33 = V_12 -> V_14 -> V_34 ;
if ( V_33 ) {
V_13 = V_33 -> V_15 ;
V_16 = V_33 -> V_17 ;
}
if ( V_16 )
F_6 ( & V_12 -> V_10 ,
L_2 ) ;
}
V_23 = ( F_1 ( & V_12 -> V_14 -> V_2 ) ||
F_2 ( & V_12 -> V_14 -> V_2 ) ||
F_3 ( & V_12 -> V_14 -> V_2 ) ) ;
memset ( V_20 , 0 , sizeof *V_20 ) ;
V_20 -> V_35 = V_12 ;
while ( V_16 > 3 ) {
if ( V_13 [ 1 ] != V_36 )
goto V_37;
switch ( V_13 [ 2 ] ) {
case V_38 :
if ( V_20 -> V_39 ) {
F_6 ( & V_12 -> V_10 , L_3 ) ;
goto V_40;
}
V_20 -> V_39 = ( void * ) V_13 ;
if ( V_20 -> V_39 -> V_41 != sizeof * V_20 -> V_39 ) {
F_6 ( & V_12 -> V_10 , L_4 ,
V_20 -> V_39 -> V_41 ) ;
goto V_40;
}
break;
case V_42 :
if ( V_23 ) {
struct V_43 * V_44 ;
V_44 = ( void * ) V_13 ;
if ( V_44 -> V_45 ) {
F_6 ( & V_12 -> V_10 ,
L_5
L_6 ,
V_44 -> V_45 ) ;
goto V_40;
}
}
break;
case V_46 :
if ( V_20 -> V_47 ) {
F_6 ( & V_12 -> V_10 , L_7 ) ;
goto V_40;
}
V_20 -> V_47 = ( void * ) V_13 ;
if ( V_20 -> V_47 -> V_41 != sizeof * V_20 -> V_47 ) {
F_6 ( & V_12 -> V_10 , L_8 ,
V_20 -> V_47 -> V_41 ) ;
goto V_40;
}
V_20 -> V_35 = F_7 ( V_10 -> V_30 ,
V_20 -> V_47 -> V_48 ) ;
V_20 -> V_21 = F_7 ( V_10 -> V_30 ,
V_20 -> V_47 -> V_49 ) ;
if ( ! V_20 -> V_35 || ! V_20 -> V_21 ) {
F_6 ( & V_12 -> V_10 ,
L_9 ,
V_20 -> V_47 -> V_48 ,
V_20 -> V_35 ,
V_20 -> V_47 -> V_49 ,
V_20 -> V_21 ) ;
goto V_40;
}
if ( V_20 -> V_35 != V_12 ) {
F_6 ( & V_12 -> V_10 , L_10 ) ;
if ( V_20 -> V_21 == V_12 ) {
V_20 -> V_21 = V_20 -> V_35 ;
V_20 -> V_35 = V_12 ;
} else
goto V_40;
}
V_18 = & V_20 -> V_21 -> V_14 -> V_2 ;
if ( V_18 -> V_3 != V_50 ) {
F_6 ( & V_12 -> V_10 , L_11 ,
V_18 -> V_3 ) ;
goto V_40;
}
break;
case V_51 :
if ( V_20 -> V_52 ) {
F_6 ( & V_12 -> V_10 , L_12 ) ;
goto V_40;
}
V_20 -> V_52 = ( void * ) V_13 ;
if ( V_20 -> V_52 -> V_41 != sizeof * V_20 -> V_52 ) {
F_6 ( & V_12 -> V_10 , L_13 ,
V_20 -> V_52 -> V_41 ) ;
goto V_40;
}
V_10 -> V_53 = F_8 (
V_20 -> V_52 -> V_54 ) ;
break;
case V_55 :
if ( V_2 ) {
F_6 ( & V_12 -> V_10 , L_14 ) ;
goto V_40;
}
V_2 = ( void * ) V_13 ;
if ( V_2 -> V_41 != sizeof( * V_2 ) )
goto V_40;
if ( memcmp ( & V_2 -> V_56 , V_57 , 16 ) )
goto V_40;
break;
case V_58 :
if ( V_28 ) {
F_6 ( & V_12 -> V_10 , L_15 ) ;
goto V_40;
}
V_28 = ( void * ) V_13 ;
if ( V_28 -> V_59 == 0 ) {
if ( V_28 -> V_41 < ( sizeof( * V_28 ) + 1 ) )
goto V_40;
} else
goto V_40;
break;
}
V_37:
V_16 -= V_13 [ 0 ] ;
V_13 += V_13 [ 0 ] ;
}
if ( V_23 && ! V_20 -> V_47 ) {
V_20 -> V_35 = F_7 ( V_10 -> V_30 , 0 ) ;
V_20 -> V_21 = F_7 ( V_10 -> V_30 , 1 ) ;
if ( ! V_20 -> V_35 || ! V_20 -> V_21 ) {
F_6 ( & V_12 -> V_10 ,
L_16 ,
V_20 -> V_35 ,
V_20 -> V_21 ) ;
goto V_40;
}
} else if ( ! V_20 -> V_39 || ! V_20 -> V_47 || ( ! V_23 && ! V_20 -> V_52 ) ) {
F_6 ( & V_12 -> V_10 , L_17 ,
V_20 -> V_39 ? L_18 : L_19 ,
V_20 -> V_47 ? L_18 : L_20 ,
V_20 -> V_52 ? L_18 : L_21 ) ;
goto V_40;
}
V_22 = F_9 ( V_25 , V_20 -> V_21 , V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_10 ( V_10 , V_20 -> V_21 ) ;
if ( V_22 < 0 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( V_25 , V_20 -> V_21 ) ;
return V_22 ;
}
V_10 -> V_22 = NULL ;
if ( V_20 -> V_35 -> V_14 -> V_2 . V_60 == 1 ) {
struct V_61 * V_2 ;
V_10 -> V_22 = & V_20 -> V_35 -> V_14 -> V_34 [ 0 ] ;
V_2 = & V_10 -> V_22 -> V_2 ;
if ( ! F_13 ( V_2 ) ||
( F_8 ( V_2 -> V_62 )
< sizeof( struct V_63 ) ) ||
! V_2 -> V_64 ) {
F_6 ( & V_12 -> V_10 , L_22 ) ;
V_10 -> V_22 = NULL ;
}
}
if ( V_23 && ! V_10 -> V_22 ) {
F_6 ( & V_12 -> V_10 , L_23 ) ;
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( V_25 , V_20 -> V_21 ) ;
return - V_65 ;
}
return 0 ;
V_40:
F_14 ( & V_10 -> V_30 -> V_10 , L_24 ) ;
return - V_65 ;
}
void F_15 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_19 * V_20 = ( void * ) & V_10 -> V_21 ;
struct V_24 * V_25 = F_5 ( V_12 ) ;
if ( V_12 == V_20 -> V_35 && V_20 -> V_21 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( V_25 , V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
else if ( V_12 == V_20 -> V_21 && V_20 -> V_35 ) {
F_11 ( V_20 -> V_35 , NULL ) ;
F_12 ( V_25 , V_20 -> V_35 ) ;
V_20 -> V_35 = NULL ;
}
}
static void F_16 ( struct V_9 * V_10 , T_2 * V_66 )
{
F_17 ( V_10 , V_67 , V_10 -> V_68 ,
L_25 ,
F_18 ( V_66 [ 0 ] ) / 1000 ,
F_18 ( V_66 [ 1 ] ) / 1000 ) ;
}
void F_19 ( struct V_9 * V_10 , struct V_69 * V_69 )
{
struct V_63 * V_70 ;
if ( V_69 -> V_71 < sizeof *V_70 )
return;
if ( F_20 ( V_72 , & V_10 -> V_73 ) ) {
F_16 ( V_10 , ( T_2 * ) V_69 -> V_74 ) ;
return;
}
V_70 = V_69 -> V_74 ;
switch ( V_70 -> V_75 ) {
case V_76 :
F_21 ( V_10 , V_67 , V_10 -> V_68 , L_26 ,
V_70 -> V_77 ? L_27 : L_28 ) ;
if ( V_70 -> V_77 )
F_22 ( V_10 -> V_68 ) ;
else
F_23 ( V_10 -> V_68 ) ;
break;
case V_78 :
F_21 ( V_10 , V_67 , V_10 -> V_68 , L_29 ,
V_69 -> V_71 ) ;
if ( V_69 -> V_71 != ( sizeof *V_70 + 8 ) )
F_24 ( V_72 , & V_10 -> V_73 ) ;
else
F_16 ( V_10 , ( T_2 * ) & V_70 [ 1 ] ) ;
break;
default:
F_25 ( V_10 -> V_68 , L_30 ,
V_70 -> V_75 ) ;
break;
}
}
int F_26 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_22 ;
struct V_19 * V_20 = ( void * ) & V_10 -> V_21 ;
F_27 ( ( sizeof( ( (struct V_9 * ) 0 ) -> V_21 )
< sizeof( struct V_19 ) ) ) ;
V_22 = F_4 ( V_10 , V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_28 ( V_10 , V_20 -> V_52 -> V_79 ) ;
if ( V_22 < 0 ) {
F_11 ( V_20 -> V_21 , NULL ) ;
F_12 ( F_5 ( V_12 ) , V_20 -> V_21 ) ;
return V_22 ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , int V_80 )
{
V_10 -> V_12 -> V_81 = V_80 ;
return 0 ;
}
