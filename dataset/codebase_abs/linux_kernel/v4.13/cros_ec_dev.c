static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
static const char * const V_7 [] = {
L_1 , L_2 , L_3 , L_4 ,
} ;
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( sizeof( * V_9 ) + sizeof( * V_6 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = V_15 + V_2 -> V_16 ;
V_9 -> V_17 = sizeof( * V_6 ) ;
V_9 -> V_18 = 0 ;
V_10 = F_3 ( V_2 -> V_19 , V_9 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_9 -> V_20 != V_21 ) {
snprintf ( V_3 , V_4 ,
L_5 ,
V_22 , V_9 -> V_20 ) ;
V_10 = - V_23 ;
goto exit;
}
V_6 = (struct V_5 * ) V_9 -> V_24 ;
if ( V_6 -> V_25 >= F_4 ( V_7 ) )
V_6 -> V_25 = 3 ;
snprintf ( V_3 , V_4 , L_6 , V_22 ,
V_6 -> V_26 , V_6 -> V_27 ,
V_7 [ V_6 -> V_25 ] ) ;
V_10 = 0 ;
exit:
F_5 ( V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , int V_28 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( V_2 -> V_29 [ 0 ] == - 1U && V_2 -> V_29 [ 1 ] == - 1U ) {
V_9 = F_2 ( sizeof( * V_9 ) + sizeof( V_2 -> V_29 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = V_30 + V_2 -> V_16 ;
V_9 -> V_17 = sizeof( V_2 -> V_29 ) ;
V_9 -> V_18 = 0 ;
V_10 = F_3 ( V_2 -> V_19 , V_9 ) ;
if ( V_10 < 0 || V_9 -> V_20 != V_21 ) {
F_7 ( V_2 -> V_31 , L_7 ,
V_10 , V_9 -> V_20 ) ;
memset ( V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
}
memcpy ( V_2 -> V_29 , V_9 -> V_24 , sizeof( V_2 -> V_29 ) ) ;
F_8 ( V_2 -> V_31 , L_8 ,
V_2 -> V_29 [ 0 ] , V_2 -> V_29 [ 1 ] ) ;
F_5 ( V_9 ) ;
}
return V_2 -> V_29 [ V_28 / 32 ] & F_9 ( V_28 ) ;
}
static int F_10 ( struct V_32 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_11 ( V_32 -> V_35 ,
struct V_1 , V_36 ) ;
V_34 -> V_37 = V_2 ;
F_12 ( V_32 , V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_32 * V_32 , struct V_33 * V_34 )
{
return 0 ;
}
static T_1 F_14 ( struct V_33 * V_34 , char T_2 * V_38 ,
T_3 V_39 , T_4 * V_40 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
char V_9 [ sizeof( struct V_5 ) +
sizeof( V_22 ) ] ;
T_3 V_41 ;
int V_10 ;
if ( * V_40 != 0 )
return 0 ;
V_10 = F_1 ( V_2 , V_9 , sizeof( V_9 ) ) ;
if ( V_10 )
return V_10 ;
V_41 = F_15 ( V_39 , strlen ( V_9 ) ) ;
if ( F_16 ( V_38 , V_9 , V_41 ) )
return - V_42 ;
* V_40 = V_41 ;
return V_41 ;
}
static long F_17 ( struct V_1 * V_2 , void T_2 * V_43 )
{
long V_10 ;
struct V_8 V_44 ;
struct V_8 * V_45 ;
if ( F_18 ( & V_44 , V_43 , sizeof( V_44 ) ) )
return - V_42 ;
if ( ( V_44 . V_18 > V_46 ) ||
( V_44 . V_17 > V_46 ) )
return - V_23 ;
V_45 = F_2 ( sizeof( * V_45 ) + F_19 ( V_44 . V_18 , V_44 . V_17 ) ,
V_11 ) ;
if ( ! V_45 )
return - V_12 ;
if ( F_18 ( V_45 , V_43 , sizeof( * V_45 ) + V_44 . V_18 ) ) {
V_10 = - V_42 ;
goto exit;
}
if ( V_44 . V_18 != V_45 -> V_18 ||
V_44 . V_17 != V_45 -> V_17 ) {
V_10 = - V_23 ;
goto exit;
}
V_45 -> V_14 += V_2 -> V_16 ;
V_10 = F_3 ( V_2 -> V_19 , V_45 ) ;
if ( V_10 < 0 )
goto exit;
if ( F_16 ( V_43 , V_45 , sizeof( * V_45 ) + V_45 -> V_17 ) )
V_10 = - V_42 ;
exit:
F_5 ( V_45 ) ;
return V_10 ;
}
static long F_20 ( struct V_1 * V_2 , void T_2 * V_43 )
{
struct V_47 * V_19 = V_2 -> V_19 ;
struct V_48 V_49 = { } ;
long V_50 ;
if ( ! V_19 -> V_51 )
return - V_52 ;
if ( F_18 ( & V_49 , V_43 , sizeof( V_49 ) ) )
return - V_42 ;
V_50 = V_19 -> V_51 ( V_19 , V_49 . V_40 , V_49 . V_53 ,
V_49 . V_38 ) ;
if ( V_50 <= 0 )
return V_50 ;
if ( F_16 ( ( void T_2 * ) V_43 , & V_49 , sizeof( V_49 ) ) )
return - V_42 ;
return 0 ;
}
static long F_21 ( struct V_33 * V_34 , unsigned int V_54 ,
unsigned long V_43 )
{
struct V_1 * V_2 = V_34 -> V_37 ;
if ( F_22 ( V_54 ) != V_55 )
return - V_52 ;
switch ( V_54 ) {
case V_56 :
return F_17 ( V_2 , ( void T_2 * ) V_43 ) ;
case V_57 :
return F_20 ( V_2 , ( void T_2 * ) V_43 ) ;
}
return - V_52 ;
}
static void F_23 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 ,
V_59 ) ;
F_5 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_10 , V_60 , V_61 , V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_67 [ V_68 ] ;
struct V_69 * V_70 ;
struct V_71 * V_6 ;
struct V_8 * V_9 ;
V_9 = F_25 ( sizeof( struct V_8 ) +
F_19 ( sizeof( * V_70 ) , sizeof( * V_6 ) ) , V_11 ) ;
if ( V_9 == NULL )
return;
V_9 -> V_13 = 2 ;
V_9 -> V_14 = V_72 + V_2 -> V_16 ;
V_9 -> V_18 = sizeof( * V_70 ) ;
V_9 -> V_17 = sizeof( * V_6 ) ;
V_70 = (struct V_69 * ) V_9 -> V_24 ;
V_70 -> V_54 = V_73 ;
V_10 = F_3 ( V_2 -> V_19 , V_9 ) ;
if ( V_10 < 0 || V_9 -> V_20 != V_21 ) {
F_7 ( V_2 -> V_31 , L_9 ,
V_10 , V_9 -> V_20 ) ;
goto error;
}
V_6 = (struct V_71 * ) V_9 -> V_24 ;
V_62 = V_6 -> V_74 . V_75 ;
V_64 = F_25 ( sizeof( struct V_63 ) * ( V_62 + 2 ) ,
V_11 ) ;
if ( V_64 == NULL )
goto error;
V_66 = F_25 ( sizeof( struct V_65 ) *
( V_62 + 1 ) , V_11 ) ;
if ( V_66 == NULL )
goto V_76;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
V_61 = 0 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
V_70 -> V_54 = V_77 ;
V_70 -> V_78 . V_62 = V_60 ;
V_10 = F_3 ( V_2 -> V_19 , V_9 ) ;
if ( V_10 < 0 || V_9 -> V_20 != V_21 ) {
F_7 ( V_2 -> V_31 , L_10 ,
V_60 , V_10 , V_9 -> V_20 ) ;
continue;
}
switch ( V_6 -> V_78 . type ) {
case V_79 :
V_64 [ V_61 ] . V_80 = L_11 ;
break;
case V_81 :
V_64 [ V_61 ] . V_80 = L_12 ;
break;
case V_82 :
V_64 [ V_61 ] . V_80 = L_13 ;
break;
case V_83 :
V_64 [ V_61 ] . V_80 = L_14 ;
break;
case V_84 :
V_64 [ V_61 ] . V_80 = L_15 ;
break;
case V_85 :
V_64 [ V_61 ] . V_80 = L_16 ;
break;
case V_86 :
V_64 [ V_61 ] . V_80 = L_17 ;
break;
default:
F_7 ( V_2 -> V_31 , L_18 , V_6 -> V_78 . type ) ;
continue;
}
V_66 [ V_61 ] . V_62 = V_60 ;
V_64 [ V_61 ] . V_61 = V_67 [ V_6 -> V_78 . type ] ;
V_64 [ V_61 ] . V_87 = & V_66 [ V_61 ] ;
V_64 [ V_61 ] . V_88 =
sizeof( struct V_65 ) ;
V_67 [ V_6 -> V_78 . type ] ++ ;
V_61 ++ ;
}
if ( V_67 [ V_79 ] >= 2 ) {
V_66 [ V_61 ] . V_62 = V_62 ;
V_64 [ V_61 ] . V_80 = L_19 ;
V_64 [ V_61 ] . V_61 = 0 ;
V_64 [ V_61 ] . V_87 = & V_66 [ V_61 ] ;
V_64 [ V_61 ] . V_88 =
sizeof( struct V_65 ) ;
V_61 ++ ;
}
if ( F_6 ( V_2 , V_89 ) ) {
V_64 [ V_61 ] . V_80 = L_20 ;
V_61 ++ ;
}
V_10 = F_26 ( V_2 -> V_31 , 0 , V_64 , V_61 ,
NULL , 0 , NULL ) ;
if ( V_10 )
F_27 ( V_2 -> V_31 , L_21 ) ;
F_5 ( V_66 ) ;
V_76:
F_5 ( V_64 ) ;
error:
F_5 ( V_9 ) ;
}
static int F_28 ( struct V_90 * V_91 )
{
int V_92 = - V_12 ;
struct V_58 * V_31 = & V_91 -> V_31 ;
struct V_93 * V_94 = F_29 ( V_31 ) ;
struct V_1 * V_2 = F_25 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return V_92 ;
F_30 ( V_31 , V_2 ) ;
V_2 -> V_19 = F_31 ( V_31 -> V_95 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_16 = V_94 -> V_16 ;
V_2 -> V_29 [ 0 ] = - 1U ;
V_2 -> V_29 [ 1 ] = - 1U ;
F_32 ( & V_2 -> V_59 ) ;
F_33 ( & V_2 -> V_36 , & V_96 ) ;
V_2 -> V_59 . V_97 = F_34 ( V_98 , V_91 -> V_61 ) ;
V_2 -> V_59 . V_99 = & V_100 ;
V_2 -> V_59 . V_95 = V_31 ;
V_2 -> V_59 . V_101 = F_23 ;
V_92 = F_35 ( & V_2 -> V_59 , L_22 , V_94 -> V_102 ) ;
if ( V_92 ) {
F_27 ( V_31 , L_23 , V_92 ) ;
goto V_103;
}
V_92 = F_36 ( & V_2 -> V_36 , & V_2 -> V_59 ) ;
if ( V_92 ) {
F_27 ( V_31 , L_24 , V_92 ) ;
goto V_103;
}
if ( F_37 ( V_2 ) )
F_7 ( V_31 , L_25 ) ;
if ( F_6 ( V_2 , V_104 ) )
F_24 ( V_2 ) ;
F_38 ( V_2 , 1 ) ;
return 0 ;
V_103:
F_39 ( & V_2 -> V_59 ) ;
return V_92 ;
}
static int F_40 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_31 ( & V_91 -> V_31 ) ;
F_38 ( V_2 , 0 ) ;
F_41 ( V_2 ) ;
F_42 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
static T_5 int F_44 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = F_31 ( V_31 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static T_5 int F_46 ( struct V_58 * V_31 )
{
struct V_1 * V_2 = F_31 ( V_31 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int T_6 F_48 ( void )
{
int V_10 ;
T_7 V_31 = 0 ;
V_10 = F_49 ( & V_100 ) ;
if ( V_10 ) {
F_50 ( V_105 L_26 ) ;
return V_10 ;
}
V_10 = F_51 ( & V_31 , 0 , V_106 , V_105 ) ;
if ( V_10 < 0 ) {
F_50 ( V_105 L_27 ) ;
goto V_107;
}
V_98 = F_52 ( V_31 ) ;
V_10 = F_53 ( & V_108 ) ;
if ( V_10 < 0 ) {
F_54 ( V_105 L_28 , V_10 ) ;
goto V_109;
}
return 0 ;
V_109:
F_55 ( F_34 ( V_98 , 0 ) , V_106 ) ;
V_107:
F_56 ( & V_100 ) ;
return V_10 ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_108 ) ;
F_59 ( V_98 , V_105 ) ;
F_56 ( & V_100 ) ;
}
