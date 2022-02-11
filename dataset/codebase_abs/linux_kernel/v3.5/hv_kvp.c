static void
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
char * V_5 ;
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( struct V_3 ) , V_6 ) ;
if ( V_2 ) {
V_4 = (struct V_3 * ) V_2 -> V_7 ;
V_5 = V_4 -> V_8 . F_1 . V_5 ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_13 ;
V_4 -> V_14 . V_15 = V_16 ;
strcpy ( V_5 , V_17 ) ;
V_2 -> V_18 = sizeof( struct V_3 ) ;
F_3 ( V_2 , 0 , V_6 ) ;
F_4 ( V_2 ) ;
}
}
static void
F_5 ( struct V_19 * V_20 )
{
F_6 ( L_1 , L_2 , V_21 ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_24 ;
struct V_25 * V_7 ;
V_24 = (struct V_3 * ) V_2 -> V_7 ;
switch ( V_24 -> V_14 . V_15 ) {
case V_16 :
F_8 ( L_3 ) ;
F_1 () ;
V_26 . V_27 = false ;
F_9 ( V_26 . V_28 ) ;
break;
default:
V_7 = & V_24 -> V_8 . V_29 ;
if ( F_10 ( & V_30 ) )
F_6 ( V_7 -> V_7 . V_31 ,
V_7 -> V_7 . V_32 ,
! strlen ( V_7 -> V_7 . V_31 ) ) ;
}
}
static void
F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
struct V_3 * V_33 ;
T_1 V_15 = V_26 . V_4 -> V_14 . V_15 ;
T_1 V_34 = V_26 . V_4 -> V_14 . V_34 ;
T_2 V_35 ;
T_3 V_36 ;
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( struct V_3 ) , V_6 ) ;
if ( ! V_2 )
return;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_13 ;
V_24 = (struct V_3 * ) V_2 -> V_7 ;
V_24 -> V_14 . V_15 = V_15 ;
V_24 -> V_14 . V_34 = V_34 ;
V_33 = V_26 . V_4 ;
switch ( V_24 -> V_14 . V_15 ) {
case V_37 :
switch ( V_33 -> V_8 . V_38 . V_7 . V_39 ) {
case V_40 :
V_24 -> V_8 . V_38 . V_7 . V_41 =
F_12 (
( V_42 * ) V_33 -> V_8 . V_38 . V_7 . V_32 ,
V_33 -> V_8 . V_38 . V_7 . V_41 ,
V_43 ,
V_24 -> V_8 . V_38 . V_7 . V_32 ,
V_44 - 1 ) + 1 ;
break;
case V_45 :
V_35 = V_33 -> V_8 . V_38 . V_7 . V_46 ;
V_24 -> V_8 . V_38 . V_7 . V_41 =
sprintf ( V_24 -> V_8 . V_38 . V_7 . V_32 ,
L_4 , V_35 ) + 1 ;
break;
case V_47 :
V_36 = V_33 -> V_8 . V_38 . V_7 . V_48 ;
V_24 -> V_8 . V_38 . V_7 . V_41 =
sprintf ( V_24 -> V_8 . V_38 . V_7 . V_32 ,
L_5 , V_36 ) + 1 ;
break;
}
case V_49 :
V_24 -> V_8 . V_38 . V_7 . V_50 =
F_12 (
( V_42 * ) V_33 -> V_8 . V_38 . V_7 . V_31 ,
V_33 -> V_8 . V_38 . V_7 . V_50 ,
V_43 ,
V_24 -> V_8 . V_38 . V_7 . V_31 ,
V_51 - 1 ) + 1 ;
break;
case V_52 :
V_24 -> V_8 . V_53 . V_50 =
F_12 (
( V_42 * ) V_33 -> V_8 . V_53 . V_31 ,
V_33 -> V_8 . V_53 . V_50 ,
V_43 ,
V_24 -> V_8 . V_53 . V_31 ,
V_51 - 1 ) + 1 ;
break;
case V_54 :
V_24 -> V_8 . V_29 . V_55 =
V_33 -> V_8 . V_29 . V_55 ;
break;
}
V_2 -> V_18 = sizeof( struct V_3 ) ;
F_3 ( V_2 , 0 , V_6 ) ;
F_4 ( V_2 ) ;
return;
}
static void
F_6 ( char * V_31 , char * V_32 , int error )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
char * V_58 ;
struct V_59 * V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
T_4 V_63 ;
struct V_64 * V_65 ;
T_5 V_66 ;
if ( ! V_26 . V_27 ) {
F_13 ( L_6 ) ;
return;
}
V_63 = V_26 . V_67 ;
V_65 = V_26 . V_68 ;
V_66 = V_26 . V_69 ;
V_26 . V_27 = false ;
V_60 = (struct V_59 * )
& V_70 [ sizeof( struct V_71 ) ] ;
if ( V_65 -> V_72 == NULL )
return;
if ( error ) {
V_60 -> V_73 = V_74 ;
goto V_75;
}
V_60 -> V_73 = V_76 ;
V_4 = (struct V_3 * )
& V_70 [ sizeof( struct V_71 ) +
sizeof( struct V_59 ) ] ;
switch ( V_26 . V_4 -> V_14 . V_15 ) {
case V_49 :
V_57 = & V_4 -> V_8 . V_77 . V_7 ;
goto V_78;
case V_37 :
case V_52 :
goto V_75;
default:
break;
}
V_57 = & V_4 -> V_8 . V_29 . V_7 ;
V_58 = V_31 ;
V_61 = F_14 ( V_58 , strlen ( V_58 ) , V_79 ,
( V_42 * ) V_57 -> V_31 ,
( V_51 / 2 ) - 2 ) ;
V_57 -> V_50 = 2 * ( V_61 + 1 ) ;
V_78:
V_62 = F_14 ( V_32 , strlen ( V_32 ) , V_79 ,
( V_42 * ) V_57 -> V_32 ,
( V_44 / 2 ) - 2 ) ;
V_57 -> V_41 = 2 * ( V_62 + 1 ) ;
if ( ( V_61 < 0 ) || ( V_62 < 0 ) )
V_60 -> V_73 = V_80 ;
V_57 -> V_39 = V_40 ;
V_75:
V_60 -> V_81 = V_82 | V_83 ;
F_15 ( V_65 , V_70 , V_63 , V_66 ,
V_84 , 0 ) ;
}
void F_9 ( void * V_85 )
{
struct V_64 * V_65 = V_85 ;
T_4 V_86 ;
T_5 V_87 ;
struct V_3 * V_4 ;
struct V_59 * V_60 ;
struct V_88 * V_89 = NULL ;
if ( V_26 . V_27 ) {
V_26 . V_28 = V_85 ;
return;
}
F_16 ( V_65 , V_70 , V_90 , & V_86 , & V_87 ) ;
if ( V_86 > 0 ) {
V_60 = (struct V_59 * ) & V_70 [
sizeof( struct V_71 ) ] ;
if ( V_60 -> V_91 == V_92 ) {
F_17 ( V_60 , V_89 ,
V_70 , V_93 , V_93 ) ;
} else {
V_4 = (struct V_3 * ) & V_70 [
sizeof( struct V_71 ) +
sizeof( struct V_59 ) ] ;
V_26 . V_67 = V_86 ;
V_26 . V_68 = V_65 ;
V_26 . V_69 = V_87 ;
V_26 . V_27 = true ;
V_26 . V_4 = V_4 ;
F_18 ( & V_94 ) ;
F_19 ( & V_30 , 5 * V_95 ) ;
return;
}
V_60 -> V_81 = V_82
| V_83 ;
F_15 ( V_65 , V_70 ,
V_86 , V_87 ,
V_84 , 0 ) ;
}
}
int
F_20 ( struct V_96 * V_97 )
{
int V_98 ;
V_98 = F_21 ( & V_99 , V_100 , F_7 ) ;
if ( V_98 )
return V_98 ;
V_70 = V_97 -> V_70 ;
V_26 . V_27 = true ;
return 0 ;
}
void F_22 ( void )
{
F_23 ( & V_99 ) ;
F_10 ( & V_30 ) ;
F_24 ( & V_94 ) ;
}
