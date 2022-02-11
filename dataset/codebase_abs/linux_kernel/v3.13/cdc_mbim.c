static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_1 , V_9 , F_3 ( & V_5 -> V_10 ) , V_3 ) ;
if ( ( V_3 && F_4 ( 1 , & V_5 -> V_10 ) == 1 ) || ( ! V_3 && F_5 ( & V_5 -> V_10 ) ) ) {
V_7 = F_6 ( V_2 -> V_8 ) ;
V_2 -> V_8 -> V_11 = V_3 ;
if ( ! V_7 )
F_7 ( V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_8 , int V_13 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_12 * V_8 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 = F_11 ( - V_18 ) ;
int V_19 = - V_18 ;
T_1 V_20 = F_12 ( V_2 , V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( ! F_13 ( V_8 -> V_21 ) )
goto V_22;
V_19 = F_14 ( V_2 , V_8 , V_20 ) ;
if ( V_19 )
goto V_22;
V_15 = V_5 -> V_15 ;
if ( V_15 -> V_23 && V_2 -> V_13 )
V_17 = F_15 ( V_15 -> V_24 ,
& V_2 -> V_13 -> V_25 ,
F_16 ( V_15 -> V_23 -> V_26 ) ,
F_8 ) ;
if ( F_17 ( V_17 ) ) {
V_19 = F_18 ( V_17 ) ;
F_19 ( V_2 , V_8 ) ;
goto V_22;
}
V_2 -> V_13 = NULL ;
V_5 -> V_17 = V_17 ;
V_2 -> V_27 -> V_28 |= V_29 ;
V_2 -> V_27 -> V_30 |= V_31 ;
V_22:
return V_19 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_12 * V_8 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
if ( V_5 -> V_17 && V_5 -> V_17 -> V_32 )
V_5 -> V_17 -> V_32 ( V_15 -> V_24 ) ;
V_5 -> V_17 = NULL ;
F_19 ( V_2 , V_8 ) ;
}
static struct V_33 * F_21 ( struct V_1 * V_2 , struct V_33 * V_34 , T_2 V_28 )
{
struct V_33 * V_35 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
T_3 V_36 = F_22 ( V_37 ) ;
T_4 V_38 = 0 ;
T_1 * V_39 ;
if ( ! V_15 )
goto error;
if ( V_34 ) {
if ( V_34 -> V_40 <= V_41 )
goto error;
F_23 ( V_34 , & V_38 ) ;
switch ( V_38 & 0x0f00 ) {
case 0x0000 :
F_24 ( V_34 ) ;
switch ( F_25 ( V_34 ) -> V_42 ) {
case F_26 ( V_43 ) :
case F_26 ( V_44 ) :
break;
default:
goto error;
}
V_39 = ( T_1 * ) & V_36 ;
V_39 [ 3 ] = V_38 ;
break;
case 0x0100 :
V_36 = F_22 ( V_45 ) ;
V_39 = ( T_1 * ) & V_36 ;
V_39 [ 3 ] = V_38 ;
break;
default:
F_27 ( V_2 , V_46 , V_2 -> V_27 ,
L_2 , V_38 ) ;
goto error;
}
F_28 ( V_34 , V_41 ) ;
}
F_29 ( & V_15 -> V_47 ) ;
V_35 = F_30 ( V_2 , V_34 , V_36 ) ;
F_31 ( & V_15 -> V_47 ) ;
return V_35 ;
error:
if ( V_34 )
F_32 ( V_34 ) ;
return NULL ;
}
static void F_33 ( struct V_1 * V_2 , T_1 * V_48 , T_4 V_38 )
{
struct V_49 * V_50 = ( void * ) V_48 ;
struct V_51 * V_52 = ( void * ) ( V_50 + 1 ) ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
bool V_57 ;
if ( ! F_34 ( & V_50 -> V_58 ) ||
! ( F_35 ( & V_50 -> V_59 ) & V_60 ) )
return;
if ( V_38 )
V_54 = F_36 ( V_2 -> V_27 , F_26 ( V_61 ) ,
V_38 ) ;
else
V_54 = V_2 -> V_27 ;
if ( ! V_54 )
return;
V_56 = F_37 ( V_54 ) ;
if ( ! V_56 )
return;
V_57 = ! ! V_56 -> V_62 . V_63 ;
F_38 ( V_56 ) ;
V_64 -> V_65 ( V_54 , NULL , & V_50 -> V_59 , & V_52 -> V_66 ,
V_57 ,
true ,
false ,
true ) ;
}
static bool F_39 ( T_1 * V_48 , T_5 V_40 )
{
struct V_49 * V_50 = ( void * ) V_48 ;
struct V_51 * V_52 = ( void * ) ( V_50 + 1 ) ;
return ( V_40 >= sizeof( struct V_49 ) + sizeof( struct V_51 ) &&
V_50 -> V_67 == V_68 &&
V_52 -> V_69 . V_70 == 0 &&
V_52 -> V_69 . V_71 == V_72 ) ;
}
static struct V_33 * F_40 ( struct V_1 * V_2 , T_1 * V_48 , T_5 V_40 , T_4 V_38 )
{
T_6 V_73 = F_26 ( V_74 ) ;
struct V_33 * V_34 = NULL ;
if ( V_38 < 256 ) {
if ( V_40 < sizeof( struct V_75 ) )
goto V_22;
switch ( * V_48 & 0xf0 ) {
case 0x40 :
V_73 = F_26 ( V_43 ) ;
break;
case 0x60 :
if ( F_39 ( V_48 , V_40 ) )
F_33 ( V_2 , V_48 , V_38 ) ;
V_73 = F_26 ( V_44 ) ;
break;
default:
goto V_22;
}
}
V_34 = F_41 ( V_2 -> V_27 , V_40 + V_41 ) ;
if ( ! V_34 )
goto V_22;
F_42 ( V_34 , V_41 ) ;
F_24 ( V_34 ) ;
F_25 ( V_34 ) -> V_42 = V_73 ;
memset ( F_25 ( V_34 ) -> V_76 , 0 , V_77 ) ;
memcpy ( F_25 ( V_34 ) -> V_78 , V_2 -> V_27 -> V_79 , V_77 ) ;
memcpy ( F_42 ( V_34 , V_40 ) , V_48 , V_40 ) ;
if ( V_38 )
F_43 ( V_34 , F_26 ( V_61 ) , V_38 ) ;
V_22:
return V_34 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_33 * V_80 )
{
struct V_33 * V_34 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
int V_40 ;
int V_81 ;
int V_82 ;
int V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_88 ;
int V_89 = 50 ;
T_1 * V_39 ;
T_4 V_38 ;
V_88 = F_45 ( V_15 , V_80 ) ;
if ( V_88 < 0 )
goto error;
V_90:
V_81 = F_46 ( V_80 , V_88 ) ;
if ( V_81 < 0 )
goto error;
V_85 = (struct V_84 * ) ( V_80 -> V_6 + V_88 ) ;
switch ( V_85 -> V_91 & F_22 ( 0x00ffffff ) ) {
case F_22 ( V_37 ) :
V_39 = ( T_1 * ) & V_85 -> V_91 ;
V_38 = V_39 [ 3 ] ;
break;
case F_22 ( V_45 ) :
V_39 = ( T_1 * ) & V_85 -> V_91 ;
V_38 = V_39 [ 3 ] + 256 ;
break;
default:
F_47 ( V_2 , V_92 , V_2 -> V_27 ,
L_3 ,
F_48 ( V_85 -> V_91 ) ) ;
goto V_93;
}
V_87 = V_85 -> V_87 ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ , V_87 ++ ) {
V_83 = F_16 ( V_87 -> V_94 ) ;
V_40 = F_16 ( V_87 -> V_95 ) ;
if ( ( V_83 == 0 ) || ( V_40 == 0 ) ) {
if ( ! V_82 )
goto V_93;
break;
}
if ( ( ( V_83 + V_40 ) > V_80 -> V_40 ) || ( V_40 > V_15 -> V_96 ) ) {
F_47 ( V_2 , V_92 , V_2 -> V_27 ,
L_4 ,
V_82 , V_83 , V_40 , V_80 ) ;
if ( ! V_82 )
goto V_93;
break;
} else {
V_34 = F_40 ( V_2 , V_80 -> V_6 + V_83 , V_40 , V_38 ) ;
if ( ! V_34 )
goto error;
F_49 ( V_2 , V_34 ) ;
}
}
V_93:
V_88 = F_16 ( V_85 -> V_97 ) ;
if ( V_88 && V_89 -- )
goto V_90;
return 1 ;
error:
return 0 ;
}
static int F_50 ( struct V_12 * V_8 , T_7 V_98 )
{
int V_19 = - V_18 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
if ( ! V_15 )
goto error;
V_19 = F_51 ( V_8 , V_98 ) ;
if ( V_19 < 0 )
goto error;
if ( V_8 == V_15 -> V_24 && V_5 -> V_17 && V_5 -> V_17 -> V_99 )
V_19 = V_5 -> V_17 -> V_99 ( V_8 , V_98 ) ;
if ( V_19 < 0 )
F_52 ( V_8 ) ;
error:
return V_19 ;
}
static int F_53 ( struct V_12 * V_8 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
bool V_100 = ( V_8 == V_15 -> V_24 && V_5 -> V_17 && V_5 -> V_17 -> V_101 ) ;
if ( V_100 )
V_19 = V_5 -> V_17 -> V_101 ( V_8 ) ;
if ( V_19 < 0 )
goto V_22;
V_19 = F_52 ( V_8 ) ;
if ( V_19 < 0 && V_100 )
V_5 -> V_17 -> V_99 ( V_8 , V_102 ) ;
V_22:
return V_19 ;
}
