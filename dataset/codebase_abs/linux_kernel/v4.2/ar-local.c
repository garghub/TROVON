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
V_26 = F_14 ( & V_29 , V_30 , V_4 -> V_3 . V_28 ,
V_31 , & V_4 -> V_32 ) ;
if ( V_26 < 0 ) {
F_11 ( L_3 , V_26 ) ;
return V_26 ;
}
if ( V_4 -> V_3 . V_33 > sizeof( V_34 ) ) {
F_15 ( L_4 ) ;
V_26 = F_16 ( V_4 -> V_32 ,
(struct V_35 * ) & V_4 -> V_3 . V_36 ,
V_4 -> V_3 . V_33 ) ;
if ( V_26 < 0 ) {
F_15 ( L_5 ) ;
goto error;
}
}
V_27 = 1 ;
V_26 = F_17 ( V_4 -> V_32 , V_37 , V_38 ,
( char * ) & V_27 , sizeof( V_27 ) ) ;
if ( V_26 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
V_27 = V_39 ;
V_26 = F_17 ( V_4 -> V_32 , V_37 , V_40 ,
( char * ) & V_27 , sizeof( V_27 ) ) ;
if ( V_26 < 0 ) {
F_15 ( L_6 ) ;
goto error;
}
F_18 ( & V_41 ) ;
F_19 ( & V_4 -> V_15 , & V_42 ) ;
F_20 ( & V_41 ) ;
V_25 = V_4 -> V_32 -> V_43 ;
V_25 -> V_44 = V_4 ;
V_25 -> V_45 = V_46 ;
V_25 -> V_47 = V_48 ;
F_11 ( L_7 ) ;
return 0 ;
error:
F_21 ( V_4 -> V_32 , V_49 ) ;
V_4 -> V_32 -> V_43 -> V_44 = NULL ;
F_22 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
F_11 ( L_8 , V_26 ) ;
return V_26 ;
}
struct V_1 * F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_26 ;
F_13 ( L_9 ,
V_3 -> V_28 ,
V_3 -> V_36 . V_50 ,
& V_3 -> V_36 . sin . V_51 ,
F_24 ( V_3 -> V_36 . sin . V_52 ) ) ;
F_25 ( & V_53 ) ;
F_26 ( & V_41 ) ;
F_27 (local, &rxrpc_locals, link) {
F_15 ( L_10 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_36 . V_50 ,
& V_4 -> V_3 . V_36 . sin . V_51 ,
F_24 ( V_4 -> V_3 . V_36 . sin . V_52 ) ) ;
if ( V_4 -> V_3 . V_28 != V_3 -> V_28 ||
V_4 -> V_3 . V_36 . V_50 != V_3 -> V_36 . V_50 )
continue;
switch ( V_3 -> V_36 . V_50 ) {
case V_54 :
if ( V_4 -> V_3 . V_36 . sin . V_52 !=
V_3 -> V_36 . sin . V_52 )
continue;
if ( memcmp ( & V_4 -> V_3 . V_36 . sin . V_51 ,
& V_3 -> V_36 . sin . V_51 ,
sizeof( struct V_55 ) ) != 0 )
continue;
goto V_56;
default:
F_28 () ;
}
}
F_29 ( & V_41 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_30 ( & V_53 ) ;
return F_31 ( - V_57 ) ;
}
V_26 = F_12 ( V_4 ) ;
if ( V_26 < 0 ) {
F_30 ( & V_53 ) ;
F_32 ( V_4 ) ;
F_11 ( L_8 , V_26 ) ;
return F_31 ( V_26 ) ;
}
F_30 ( & V_53 ) ;
F_33 ( L_11 ,
V_4 -> V_23 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_36 . V_50 ,
& V_4 -> V_3 . V_36 . sin . V_51 ,
F_24 ( V_4 -> V_3 . V_36 . sin . V_52 ) ) ;
F_11 ( L_12 , V_4 ) ;
return V_4 ;
V_56:
F_34 ( V_4 ) ;
F_29 ( & V_41 ) ;
F_30 ( & V_53 ) ;
F_33 ( L_13 ,
V_4 -> V_23 ,
V_4 -> V_3 . V_28 ,
V_4 -> V_3 . V_36 . V_50 ,
& V_4 -> V_3 . V_36 . sin . V_51 ,
F_24 ( V_4 -> V_3 . V_36 . sin . V_52 ) ) ;
F_11 ( L_14 , V_4 ) ;
return V_4 ;
}
void F_35 ( struct V_1 * V_4 )
{
F_13 ( L_15 , V_4 , F_36 ( & V_4 -> V_22 ) ) ;
F_37 ( F_36 ( & V_4 -> V_22 ) , > , 0 ) ;
F_18 ( & V_41 ) ;
if ( F_38 ( F_39 ( & V_4 -> V_22 ) ) ) {
F_15 ( L_16 ) ;
F_40 ( & V_4 -> V_6 ) ;
}
F_20 ( & V_41 ) ;
F_11 ( L_17 ) ;
}
static void V_7 ( struct V_58 * V_59 )
{
struct V_1 * V_4 =
F_41 ( V_59 , struct V_1 , V_6 ) ;
F_13 ( L_2 , V_4 , F_36 ( & V_4 -> V_22 ) ) ;
F_25 ( & V_53 ) ;
F_18 ( & V_41 ) ;
if ( F_36 ( & V_4 -> V_22 ) > 0 ) {
F_20 ( & V_41 ) ;
F_42 ( & V_53 ) ;
F_11 ( L_18 ) ;
return;
}
F_43 ( & V_4 -> V_15 ) ;
V_4 -> V_32 -> V_43 -> V_44 = NULL ;
F_20 ( & V_41 ) ;
F_44 ( & V_53 ) ;
ASSERT ( F_45 ( & V_4 -> V_14 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_8 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_10 ) ) ;
ASSERT ( ! F_46 ( & V_4 -> V_12 ) ) ;
F_47 ( & V_4 -> V_17 ) ;
F_47 ( & V_4 -> V_18 ) ;
F_47 ( & V_4 -> V_19 ) ;
F_21 ( V_4 -> V_32 , V_49 ) ;
F_22 ( V_4 -> V_32 ) ;
F_42 ( & V_53 ) ;
F_33 ( L_19 , V_4 -> V_23 ) ;
F_32 ( V_4 ) ;
if ( F_45 ( & V_42 ) )
F_48 ( & V_60 ) ;
F_11 ( L_17 ) ;
}
void T_1 F_49 ( void )
{
F_50 ( V_61 , V_62 ) ;
F_13 ( L_17 ) ;
if ( ! F_45 ( & V_42 ) ) {
F_51 ( V_63 ) ;
F_52 ( & V_60 , & V_61 ) ;
while ( ! F_45 ( & V_42 ) ) {
F_53 () ;
F_51 ( V_63 ) ;
}
F_54 ( & V_60 , & V_61 ) ;
F_51 ( V_64 ) ;
}
F_11 ( L_17 ) ;
}
static void F_55 ( struct V_1 * V_4 ,
struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 sin ;
struct V_70 V_71 ;
struct V_72 V_73 [ 2 ] ;
T_2 V_74 ;
int V_26 ;
F_13 ( L_17 ) ;
sin . V_75 = V_54 ;
sin . V_52 = F_56 ( V_68 ) -> V_76 ;
sin . V_51 . V_77 = F_57 ( V_68 ) -> V_78 ;
V_71 . V_79 = & sin ;
V_71 . V_80 = sizeof( sin ) ;
V_71 . V_81 = NULL ;
V_71 . V_82 = 0 ;
V_71 . V_83 = 0 ;
V_66 -> V_84 = 0 ;
V_66 -> V_85 = 0 ;
V_66 -> type = V_86 ;
V_66 -> V_87 = V_88 | ( ~ V_66 -> V_87 & V_89 ) ;
V_66 -> V_90 = 0 ;
V_66 -> V_91 = 0 ;
V_73 [ 0 ] . V_92 = V_66 ;
V_73 [ 0 ] . V_93 = sizeof( * V_66 ) ;
V_73 [ 1 ] . V_92 = ( char * ) V_94 ;
V_73 [ 1 ] . V_93 = sizeof( V_94 ) ;
V_74 = V_73 [ 0 ] . V_93 + V_73 [ 1 ] . V_93 ;
F_58 ( L_20 ) ;
V_26 = F_59 ( V_4 -> V_32 , & V_71 , V_73 , 2 , V_74 ) ;
if ( V_26 < 0 )
F_15 ( L_21 , V_26 ) ;
F_11 ( L_17 ) ;
}
static void V_13 ( struct V_58 * V_59 )
{
struct V_1 * V_4 = F_41 ( V_59 , struct V_1 , V_12 ) ;
struct V_67 * V_68 ;
char V_95 ;
F_13 ( L_17 ) ;
F_60 ( & V_4 -> V_22 ) ;
while ( ( V_68 = F_61 ( & V_4 -> V_19 ) ) ) {
struct V_96 * V_97 = F_62 ( V_68 ) ;
F_63 ( L_22 , V_4 -> V_23 , V_97 -> V_66 . type ) ;
switch ( V_97 -> V_66 . type ) {
case V_86 :
if ( F_64 ( V_68 , 0 , & V_95 , 1 ) < 0 )
return;
F_58 ( L_23 , V_95 ) ;
if ( V_95 == 0 )
F_55 ( V_4 , & V_97 -> V_66 , V_68 ) ;
break;
default:
break;
}
F_35 ( V_4 ) ;
F_65 ( V_68 ) ;
}
F_35 ( V_4 ) ;
F_11 ( L_17 ) ;
}
