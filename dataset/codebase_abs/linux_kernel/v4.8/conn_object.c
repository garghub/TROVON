struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 ( L_1 ) ;
V_3 = F_3 ( sizeof( struct V_1 ) , V_2 ) ;
if ( V_3 ) {
F_4 ( & V_3 -> V_4 ) ;
F_5 ( & V_3 -> V_5 ) ;
F_6 ( & V_3 -> V_6 , & V_7 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_8 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = & V_11 ;
F_4 ( & V_3 -> V_12 ) ;
F_9 ( & V_3 -> V_13 , 2 ) ;
V_3 -> V_14 = F_10 ( & V_15 ) ;
F_9 ( & V_3 -> V_16 , V_17 ) ;
V_3 -> V_18 = 4 ;
V_3 -> V_19 = sizeof( struct V_20 ) ;
}
F_11 ( L_2 , V_3 , V_3 ? V_3 -> V_14 : 0 ) ;
return V_3 ;
}
struct V_1 * F_12 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_3 ;
struct V_25 V_26 ;
struct V_27 * V_28 = F_13 ( V_24 ) ;
struct V_29 V_30 ;
struct V_31 * V_32 ;
F_2 ( L_3 , V_28 -> V_33 . V_34 & V_35 ) ;
if ( F_14 ( & V_30 , V_24 ) < 0 )
goto V_36;
V_26 . V_37 = V_28 -> V_33 . V_37 ;
V_26 . V_34 = V_28 -> V_33 . V_34 & V_35 ;
if ( V_30 . V_38 . V_39 != V_22 -> V_30 . V_38 . V_39 ) {
F_15 ( L_4 ,
V_30 . V_38 . V_39 ,
V_22 -> V_30 . V_38 . V_39 ) ;
goto V_36;
}
V_26 . V_37 = V_28 -> V_33 . V_37 ;
V_26 . V_34 = V_28 -> V_33 . V_34 & V_35 ;
if ( V_28 -> V_33 . V_40 & V_41 ) {
V_32 = F_16 ( V_22 , & V_30 ) ;
if ( ! V_32 )
goto V_36;
V_3 = F_17 ( V_32 , V_24 ) ;
if ( ! V_3 || F_18 ( & V_3 -> V_13 ) == 0 )
goto V_36;
F_11 ( L_5 , V_3 ) ;
return V_3 ;
} else {
V_3 = F_19 ( & V_42 ,
V_28 -> V_33 . V_34 >> V_43 ) ;
if ( ! V_3 || F_18 ( & V_3 -> V_13 ) == 0 ) {
F_20 ( L_6 ) ;
goto V_36;
}
if ( V_3 -> V_44 . V_37 != V_26 . V_37 ||
V_3 -> V_45 . V_22 != V_22 )
goto V_36;
V_32 = V_3 -> V_45 . V_32 ;
switch ( V_30 . V_38 . V_39 ) {
case V_46 :
if ( V_32 -> V_30 . V_38 . sin . V_47 !=
V_30 . V_38 . sin . V_47 ||
V_32 -> V_30 . V_38 . sin . V_48 . V_49 !=
V_30 . V_38 . sin . V_48 . V_49 )
goto V_36;
break;
default:
F_21 () ;
}
F_11 ( L_5 , V_3 ) ;
return V_3 ;
}
V_36:
F_11 ( L_7 ) ;
return NULL ;
}
void F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_3 = V_51 -> V_3 ;
struct V_52 * V_53 = & V_3 -> V_54 [ V_51 -> V_55 ] ;
F_2 ( L_8 , V_3 -> V_14 , V_51 -> V_55 ) ;
if ( F_23 ( V_53 -> V_51 ) == V_51 ) {
V_53 -> V_56 = V_51 -> V_57 ;
F_24 () ;
V_53 -> V_58 = V_53 -> V_59 ;
V_53 -> V_59 = V_53 -> V_60 ;
F_25 ( V_53 -> V_51 , NULL ) ;
F_26 ( & V_3 -> V_16 ) ;
F_27 ( & V_3 -> V_5 ) ;
}
F_11 ( L_1 ) ;
}
void F_28 ( struct V_50 * V_51 )
{
struct V_1 * V_3 = V_51 -> V_3 ;
F_29 ( & V_3 -> V_4 ) ;
F_22 ( V_51 ) ;
F_30 ( & V_3 -> V_4 ) ;
V_51 -> V_3 = NULL ;
F_31 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_2 ( L_9 ,
V_3 , F_18 ( & V_3 -> V_13 ) , V_3 -> V_14 ) ;
F_32 ( F_18 ( & V_3 -> V_13 ) , > , 1 ) ;
V_3 -> V_61 = F_33 () ;
if ( F_34 ( & V_3 -> V_13 ) == 1 ) {
F_20 ( L_10 ) ;
F_35 ( & V_62 , 0 ) ;
}
F_11 ( L_1 ) ;
}
static void F_36 ( struct V_63 * V_64 )
{
struct V_1 * V_3 =
F_37 ( V_64 , struct V_1 , V_64 ) ;
F_2 ( L_11 , V_3 -> V_14 , F_18 ( & V_3 -> V_13 ) ) ;
F_32 ( F_18 ( & V_3 -> V_13 ) , == , 0 ) ;
F_38 ( L_12 , V_3 -> V_14 ) ;
F_39 ( & V_3 -> V_9 ) ;
V_3 -> V_10 -> V_65 ( V_3 ) ;
F_40 ( V_3 -> V_45 . V_66 ) ;
F_40 ( V_3 -> V_67 ) ;
F_41 ( V_3 -> V_45 . V_32 ) ;
F_42 ( V_3 -> V_45 . V_22 ) ;
F_43 ( V_3 ) ;
F_11 ( L_1 ) ;
}
static void F_44 ( struct V_68 * V_69 )
{
struct V_1 * V_3 , * V_70 ;
unsigned long V_71 , V_72 , V_61 , V_73 ;
F_45 ( V_74 ) ;
F_2 ( L_1 ) ;
V_73 = F_33 () ;
V_71 = V_73 - V_75 ;
V_72 = V_76 ;
F_46 ( & V_77 ) ;
F_47 (conn, _p, &rxrpc_connections, link) {
F_32 ( F_18 ( & V_3 -> V_13 ) , > , 0 ) ;
if ( F_48 ( F_18 ( & V_3 -> V_13 ) > 1 ) )
continue;
V_61 = F_49 ( V_3 -> V_61 ) ;
if ( F_50 ( V_61 , V_71 ) ) {
if ( F_51 ( V_61 , V_72 ) )
V_72 = V_61 ;
continue;
}
if ( F_52 ( & V_3 -> V_13 , 1 , 0 ) != 1 )
continue;
if ( F_53 ( V_3 ) )
F_54 ( V_3 ) ;
else
F_55 ( V_3 ) ;
F_56 ( & V_3 -> V_8 , & V_74 ) ;
}
F_57 ( & V_77 ) ;
if ( V_72 != V_76 ) {
F_20 ( L_13 , ( long ) V_72 - V_73 ) ;
F_32 ( V_72 , > , V_73 ) ;
F_35 ( & V_62 ,
( V_72 - V_73 ) * V_78 ) ;
}
while ( ! F_58 ( & V_74 ) ) {
V_3 = F_59 ( V_74 . V_79 , struct V_1 ,
V_8 ) ;
F_60 ( & V_3 -> V_8 ) ;
F_32 ( F_18 ( & V_3 -> V_13 ) , == , 0 ) ;
F_61 ( & V_3 -> V_9 ) ;
F_62 ( & V_3 -> V_64 , F_36 ) ;
}
F_11 ( L_1 ) ;
}
void T_2 F_63 ( void )
{
struct V_1 * V_3 , * V_70 ;
bool V_80 = false ;
F_2 ( L_1 ) ;
V_75 = 0 ;
F_64 ( & V_62 ) ;
F_35 ( & V_62 , 0 ) ;
F_65 ( V_81 ) ;
F_46 ( & V_77 ) ;
F_47 (conn, _p, &rxrpc_connections, link) {
F_66 ( L_14 ,
V_3 , F_18 ( & V_3 -> V_13 ) ) ;
V_80 = true ;
}
F_57 ( & V_77 ) ;
F_67 ( V_80 ) ;
F_68 () ;
F_69 () ;
F_11 ( L_1 ) ;
}
