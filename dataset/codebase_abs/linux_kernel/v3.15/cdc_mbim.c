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
static bool F_21 ( T_2 V_33 )
{
switch ( V_33 ) {
case F_22 ( V_34 ) :
case F_22 ( V_35 ) :
return true ;
}
return false ;
}
static struct V_36 * F_23 ( struct V_1 * V_2 , struct V_36 * V_37 , T_3 V_28 )
{
struct V_36 * V_38 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
T_4 V_39 = F_24 ( V_40 ) ;
T_5 V_41 = 0 ;
bool V_42 ;
T_1 * V_43 ;
if ( ! V_15 )
goto error;
if ( V_37 ) {
if ( V_37 -> V_44 <= V_45 )
goto error;
F_25 ( V_37 ) ;
if ( F_26 ( V_37 , & V_41 ) < 0 && V_37 -> V_44 > V_46 &&
F_27 ( V_37 , & V_41 ) == 0 ) {
V_42 = F_21 ( F_28 ( V_37 ) -> V_47 ) ;
F_29 ( V_37 , V_46 ) ;
} else {
V_42 = F_21 ( F_30 ( V_37 ) -> V_48 ) ;
F_29 ( V_37 , V_45 ) ;
}
switch ( V_41 & 0x0f00 ) {
case 0x0000 :
if ( ! V_42 )
goto error;
V_43 = ( T_1 * ) & V_39 ;
V_43 [ 3 ] = V_41 ;
break;
case 0x0100 :
V_39 = F_24 ( V_49 ) ;
V_43 = ( T_1 * ) & V_39 ;
V_43 [ 3 ] = V_41 ;
break;
default:
F_31 ( V_2 , V_50 , V_2 -> V_27 ,
L_2 , V_41 ) ;
goto error;
}
}
F_32 ( & V_15 -> V_51 ) ;
V_38 = F_33 ( V_2 , V_37 , V_39 ) ;
F_34 ( & V_15 -> V_51 ) ;
return V_38 ;
error:
if ( V_37 )
F_35 ( V_37 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 , T_1 * V_52 , T_5 V_41 )
{
struct V_53 * V_54 = ( void * ) V_52 ;
struct V_55 * V_56 = ( void * ) ( V_54 + 1 ) ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
bool V_61 ;
if ( ! F_37 ( & V_54 -> V_62 ) ||
! ( F_38 ( & V_54 -> V_63 ) & V_64 ) )
return;
F_39 () ;
if ( V_41 ) {
V_58 = F_40 ( V_2 -> V_27 , F_22 ( V_65 ) ,
V_41 ) ;
if ( ! V_58 ) {
F_41 () ;
return;
}
} else {
V_58 = V_2 -> V_27 ;
}
F_42 ( V_58 ) ;
F_41 () ;
V_60 = F_43 ( V_58 ) ;
if ( ! V_60 )
goto V_66;
V_61 = ! ! V_60 -> V_67 . V_68 ;
F_44 ( V_60 ) ;
V_69 -> V_70 ( V_58 , NULL , & V_54 -> V_63 , & V_56 -> V_71 ,
V_61 ,
true ,
false ,
true ) ;
V_66:
F_45 ( V_58 ) ;
}
static bool F_46 ( T_1 * V_52 , T_6 V_44 )
{
struct V_53 * V_54 = ( void * ) V_52 ;
struct V_55 * V_56 = ( void * ) ( V_54 + 1 ) ;
return ( V_44 >= sizeof( struct V_53 ) + sizeof( struct V_55 ) &&
V_54 -> V_72 == V_73 &&
V_56 -> V_74 . V_75 == 0 &&
V_56 -> V_74 . V_76 == V_77 ) ;
}
static struct V_36 * F_47 ( struct V_1 * V_2 , T_1 * V_52 , T_6 V_44 , T_5 V_41 )
{
T_2 V_33 = F_22 ( V_78 ) ;
struct V_36 * V_37 = NULL ;
if ( V_41 < 256 ) {
if ( V_44 < sizeof( struct V_79 ) )
goto V_22;
switch ( * V_52 & 0xf0 ) {
case 0x40 :
V_33 = F_22 ( V_34 ) ;
break;
case 0x60 :
if ( F_46 ( V_52 , V_44 ) )
F_36 ( V_2 , V_52 , V_41 ) ;
V_33 = F_22 ( V_35 ) ;
break;
default:
goto V_22;
}
}
V_37 = F_48 ( V_2 -> V_27 , V_44 + V_45 ) ;
if ( ! V_37 )
goto V_22;
F_49 ( V_37 , V_45 ) ;
F_25 ( V_37 ) ;
F_30 ( V_37 ) -> V_48 = V_33 ;
memset ( F_30 ( V_37 ) -> V_80 , 0 , V_81 ) ;
memcpy ( F_30 ( V_37 ) -> V_82 , V_2 -> V_27 -> V_83 , V_81 ) ;
memcpy ( F_49 ( V_37 , V_44 ) , V_52 , V_44 ) ;
if ( V_41 )
F_50 ( V_37 , F_22 ( V_65 ) , V_41 ) ;
V_22:
return V_37 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_36 * V_84 )
{
struct V_36 * V_37 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
int V_44 ;
int V_85 ;
int V_86 ;
int V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_92 ;
int V_93 = 50 ;
T_1 * V_43 ;
T_5 V_41 ;
V_92 = F_52 ( V_15 , V_84 ) ;
if ( V_92 < 0 )
goto error;
V_94:
V_85 = F_53 ( V_84 , V_92 ) ;
if ( V_85 < 0 )
goto error;
V_89 = (struct V_88 * ) ( V_84 -> V_6 + V_92 ) ;
switch ( V_89 -> V_95 & F_24 ( 0x00ffffff ) ) {
case F_24 ( V_40 ) :
V_43 = ( T_1 * ) & V_89 -> V_95 ;
V_41 = V_43 [ 3 ] ;
break;
case F_24 ( V_49 ) :
V_43 = ( T_1 * ) & V_89 -> V_95 ;
V_41 = V_43 [ 3 ] + 256 ;
break;
default:
F_54 ( V_2 , V_96 , V_2 -> V_27 ,
L_3 ,
F_55 ( V_89 -> V_95 ) ) ;
goto V_97;
}
V_91 = V_89 -> V_91 ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ , V_91 ++ ) {
V_87 = F_16 ( V_91 -> V_98 ) ;
V_44 = F_16 ( V_91 -> V_99 ) ;
if ( ( V_87 == 0 ) || ( V_44 == 0 ) ) {
if ( ! V_86 )
goto V_97;
break;
}
if ( ( ( V_87 + V_44 ) > V_84 -> V_44 ) || ( V_44 > V_15 -> V_100 ) ) {
F_54 ( V_2 , V_96 , V_2 -> V_27 ,
L_4 ,
V_86 , V_87 , V_44 , V_84 ) ;
if ( ! V_86 )
goto V_97;
break;
} else {
V_37 = F_47 ( V_2 , V_84 -> V_6 + V_87 , V_44 , V_41 ) ;
if ( ! V_37 )
goto error;
F_56 ( V_2 , V_37 ) ;
}
}
V_97:
V_92 = F_16 ( V_89 -> V_101 ) ;
if ( V_92 && V_93 -- )
goto V_94;
return 1 ;
error:
return 0 ;
}
static int F_57 ( struct V_12 * V_8 , T_7 V_102 )
{
int V_19 = - V_18 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
if ( ! V_15 )
goto error;
V_19 = F_58 ( V_8 , V_102 ) ;
if ( V_19 < 0 )
goto error;
if ( V_8 == V_15 -> V_24 && V_5 -> V_17 && V_5 -> V_17 -> V_103 )
V_19 = V_5 -> V_17 -> V_103 ( V_8 , V_102 ) ;
if ( V_19 < 0 )
F_59 ( V_8 ) ;
error:
return V_19 ;
}
static int F_60 ( struct V_12 * V_8 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_15 ;
bool V_104 = ( V_8 == V_15 -> V_24 && V_5 -> V_17 && V_5 -> V_17 -> V_105 ) ;
if ( V_104 )
V_19 = V_5 -> V_17 -> V_105 ( V_8 ) ;
if ( V_19 < 0 )
goto V_22;
V_19 = F_59 ( V_8 ) ;
if ( V_19 < 0 && V_104 )
V_5 -> V_17 -> V_103 ( V_8 , V_106 ) ;
V_22:
return V_19 ;
}
