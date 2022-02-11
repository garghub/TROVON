static
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_4 ) {
F_3 ( & V_4 -> V_6 , & V_7 ) ;
F_3 ( & V_4 -> V_8 , & V_9 ) ;
F_3 ( & V_4 -> V_10 , & V_11 ) ;
F_3 ( & V_4 -> V_12 , & V_13 ) ;
F_4 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_15 ) ;
F_5 ( & V_4 -> V_16 ) ;
F_6 ( & V_4 -> V_17 ) ;
F_6 ( & V_4 -> V_18 ) ;
F_6 ( & V_4 -> V_19 ) ;
F_7 ( & V_4 -> V_20 ) ;
F_8 ( & V_4 -> V_21 ) ;
F_9 ( & V_4 -> V_22 , 1 ) ;
V_4 -> V_23 = F_10 ( & V_24 ) ;
memcpy ( & V_4 -> V_3 , V_3 , sizeof( * V_3 ) ) ;
}
F_11 ( L_1 , V_4 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_4 )
{
struct V_25 * V_25 ;
int V_26 , V_27 ;
F_13 ( L_2 , V_4 , V_4 -> V_3 . V_28 ) ;
V_26 = F_14 ( V_29 , V_4 -> V_3 . V_28 , V_30 ,
& V_4 -> V_31 ) ;
if ( V_26 < 0 ) {
F_11 ( L_3 , V_26 ) ;
return V_26 ;
}
if ( V_4 -> V_3 . V_32 > sizeof( V_33 ) ) {
F_15 ( L_4 ) ;
V_26 = F_16 ( V_4 -> V_31 ,
(struct V_34 * ) & V_4 -> V_3 . V_35 ,
V_4 -> V_3 . V_32 ) ;
if ( V_26 < 0 ) {
F_15 ( L_5 ) ;
goto error;
}
}
V_27 = 1 ;
V_26 = F_17 ( V_4 -> V_31 , V_36 , V_37 ,
( char * ) & V_27 , sizeof( V_27 ) ) ;
if ( V_26 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
V_27 = V_38 ;
V_26 = F_17 ( V_4 -> V_31 , V_36 , V_39 ,
( char * ) & V_27 , sizeof( V_27 ) ) ;
if ( V_26 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
F_18 ( & V_40 ) ;
F_19 ( & V_4 -> V_15 , & V_41 ) ;
F_20 ( & V_40 ) ;
V_25 = V_4 -> V_31 -> V_42 ;
V_25 -> V_43 = V_4 ;
V_25 -> V_44 = V_45 ;
V_25 -> V_46 = V_47 ;
F_11 ( L_7 ) ;
return 0 ;
error:
F_21 ( V_4 -> V_31 , V_48 ) ;
V_4 -> V_31 -> V_42 -> V_43 = NULL ;
F_22 ( V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
F_11 ( L_8 , V_26 ) ;
return V_26 ;
}
struct V_1 * F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_26 ;
F_13 ( L_9 ,
V_3 -> V_28 ,
V_3 -> V_35 . V_49 ,
& V_3 -> V_35 . sin . V_50 ,
F_24 ( V_3 -> V_35 . sin . V_51 ) ) ;
F_25 ( & V_52 ) ;
F_26 ( & V_40 ) ;
F_27 (local, &rxrpc_locals, link) {
F_15 ( L_10 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_35 . V_49 ,
& V_4 -> V_3 . V_35 . sin . V_50 ,
F_24 ( V_4 -> V_3 . V_35 . sin . V_51 ) ) ;
if ( V_4 -> V_3 . V_28 != V_3 -> V_28 ||
V_4 -> V_3 . V_35 . V_49 != V_3 -> V_35 . V_49 )
continue;
switch ( V_3 -> V_35 . V_49 ) {
case V_53 :
if ( V_4 -> V_3 . V_35 . sin . V_51 !=
V_3 -> V_35 . sin . V_51 )
continue;
if ( memcmp ( & V_4 -> V_3 . V_35 . sin . V_50 ,
& V_3 -> V_35 . sin . V_50 ,
sizeof( struct V_54 ) ) != 0 )
continue;
goto V_55;
default:
F_28 () ;
}
}
F_29 ( & V_40 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_30 ( & V_52 ) ;
return F_31 ( - V_56 ) ;
}
V_26 = F_12 ( V_4 ) ;
if ( V_26 < 0 ) {
F_30 ( & V_52 ) ;
F_32 ( V_4 ) ;
F_11 ( L_8 , V_26 ) ;
return F_31 ( V_26 ) ;
}
F_30 ( & V_52 ) ;
F_33 ( L_11 ,
V_4 -> V_23 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_35 . V_49 ,
& V_4 -> V_3 . V_35 . sin . V_50 ,
F_24 ( V_4 -> V_3 . V_35 . sin . V_51 ) ) ;
F_11 ( L_12 , V_4 ) ;
return V_4 ;
V_55:
F_34 ( V_4 ) ;
F_29 ( & V_40 ) ;
F_30 ( & V_52 ) ;
F_33 ( L_13 ,
V_4 -> V_23 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_35 . V_49 ,
& V_4 -> V_3 . V_35 . sin . V_50 ,
F_24 ( V_4 -> V_3 . V_35 . sin . V_51 ) ) ;
F_11 ( L_14 , V_4 ) ;
return V_4 ;
}
void F_35 ( struct V_1 * V_4 )
{
F_13 ( L_15 , V_4 , F_36 ( & V_4 -> V_22 ) ) ;
F_37 ( F_36 ( & V_4 -> V_22 ) , > , 0 ) ;
F_18 ( & V_40 ) ;
if ( F_38 ( F_39 ( & V_4 -> V_22 ) ) ) {
F_15 ( L_16 ) ;
F_40 ( & V_4 -> V_6 ) ;
}
F_20 ( & V_40 ) ;
F_11 ( L_17 ) ;
}
static void V_7 ( struct V_57 * V_58 )
{
struct V_1 * V_4 =
F_41 ( V_58 , struct V_1 , V_6 ) ;
F_13 ( L_2 , V_4 , F_36 ( & V_4 -> V_22 ) ) ;
F_25 ( & V_52 ) ;
F_18 ( & V_40 ) ;
if ( F_36 ( & V_4 -> V_22 ) > 0 ) {
F_20 ( & V_40 ) ;
F_42 ( & V_52 ) ;
F_11 ( L_18 ) ;
return;
}
F_43 ( & V_4 -> V_15 ) ;
V_4 -> V_31 -> V_42 -> V_43 = NULL ;
F_20 ( & V_40 ) ;
F_44 ( & V_52 ) ;
ASSERT ( F_45 ( & V_4 -> V_14 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_8 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_10 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_12 ) ) ;
F_47 ( & V_4 -> V_17 ) ;
F_47 ( & V_4 -> V_18 ) ;
F_47 ( & V_4 -> V_19 ) ;
F_21 ( V_4 -> V_31 , V_48 ) ;
F_22 ( V_4 -> V_31 ) ;
F_42 ( & V_52 ) ;
F_33 ( L_19 , V_4 -> V_23 ) ;
F_32 ( V_4 ) ;
if ( F_45 ( & V_41 ) )
F_48 ( & V_59 ) ;
F_11 ( L_17 ) ;
}
void T_1 F_49 ( void )
{
F_50 ( V_60 , V_61 ) ;
F_13 ( L_17 ) ;
if ( ! F_45 ( & V_41 ) ) {
F_51 ( V_62 ) ;
F_52 ( & V_59 , & V_60 ) ;
while ( ! F_45 ( & V_41 ) ) {
F_53 () ;
F_51 ( V_62 ) ;
}
F_54 ( & V_59 , & V_60 ) ;
F_51 ( V_63 ) ;
}
F_11 ( L_17 ) ;
}
static void F_55 ( struct V_1 * V_4 ,
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 sin ;
struct V_69 V_70 ;
struct V_71 V_72 [ 2 ] ;
T_2 V_73 ;
int V_26 ;
F_13 ( L_17 ) ;
sin . V_74 = V_53 ;
sin . V_51 = F_56 ( V_67 ) -> V_75 ;
sin . V_50 . V_76 = F_57 ( V_67 ) -> V_77 ;
V_70 . V_78 = & sin ;
V_70 . V_79 = sizeof( sin ) ;
V_70 . V_80 = NULL ;
V_70 . V_81 = 0 ;
V_70 . V_82 = 0 ;
V_65 -> V_83 = 0 ;
V_65 -> V_84 = 0 ;
V_65 -> type = V_85 ;
V_65 -> V_86 = V_87 | ( ~ V_65 -> V_86 & V_88 ) ;
V_65 -> V_89 = 0 ;
V_65 -> V_90 = 0 ;
V_72 [ 0 ] . V_91 = V_65 ;
V_72 [ 0 ] . V_92 = sizeof( * V_65 ) ;
V_72 [ 1 ] . V_91 = ( char * ) V_93 ;
V_72 [ 1 ] . V_92 = sizeof( V_93 ) ;
V_73 = V_72 [ 0 ] . V_92 + V_72 [ 1 ] . V_92 ;
F_58 ( L_20 ) ;
V_26 = F_59 ( V_4 -> V_31 , & V_70 , V_72 , 2 , V_73 ) ;
if ( V_26 < 0 )
F_15 ( L_21 , V_26 ) ;
F_11 ( L_17 ) ;
}
static void V_13 ( struct V_57 * V_58 )
{
struct V_1 * V_4 = F_41 ( V_58 , struct V_1 , V_12 ) ;
struct V_66 * V_67 ;
char V_94 ;
F_13 ( L_17 ) ;
F_60 ( & V_4 -> V_22 ) ;
while ( ( V_67 = F_61 ( & V_4 -> V_19 ) ) ) {
struct V_95 * V_96 = F_62 ( V_67 ) ;
F_63 ( L_22 , V_4 -> V_23 , V_96 -> V_65 . type ) ;
switch ( V_96 -> V_65 . type ) {
case V_85 :
if ( F_64 ( V_67 , 0 , & V_94 , 1 ) < 0 )
return;
F_58 ( L_23 , V_94 ) ;
if ( V_94 == 0 )
F_55 ( V_4 , & V_96 -> V_65 , V_67 ) ;
break;
default:
break;
}
F_35 ( V_4 ) ;
F_65 ( V_67 ) ;
}
F_35 ( V_4 ) ;
F_11 ( L_17 ) ;
}
