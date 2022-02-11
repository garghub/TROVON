struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 ( L_1 ) ;
V_3 = F_3 ( sizeof( struct V_1 ) , V_2 ) ;
if ( V_3 ) {
F_4 ( & V_3 -> V_4 ) ;
F_5 ( & V_3 -> V_5 ) ;
F_4 ( & V_3 -> V_6 ) ;
F_6 ( & V_3 -> V_7 , & V_8 ) ;
F_4 ( & V_3 -> V_9 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_7 ( & V_3 -> V_11 ) ;
V_3 -> V_12 = & V_13 ;
F_5 ( & V_3 -> V_14 ) ;
V_3 -> V_15 = F_8 ( & V_16 ) ;
V_3 -> V_17 = 4 ;
V_3 -> V_18 = V_19 ;
}
F_9 ( L_2 , V_3 , V_3 ? V_3 -> V_15 : 0 ) ;
return V_3 ;
}
struct V_1 * F_10 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_3 ;
struct V_24 V_25 ;
struct V_26 * V_27 = F_11 ( V_23 ) ;
struct V_28 V_29 ;
struct V_30 * V_31 ;
F_2 ( L_3 , V_27 -> V_32 . V_33 & V_34 ) ;
if ( F_12 ( & V_29 , V_23 ) < 0 )
goto V_35;
V_25 . V_36 = V_27 -> V_32 . V_36 ;
V_25 . V_33 = V_27 -> V_32 . V_33 & V_34 ;
if ( V_29 . V_37 . V_38 != V_21 -> V_29 . V_37 . V_38 ) {
F_13 ( L_4 ,
V_29 . V_37 . V_38 ,
V_21 -> V_29 . V_37 . V_38 ) ;
goto V_35;
}
V_25 . V_36 = V_27 -> V_32 . V_36 ;
V_25 . V_33 = V_27 -> V_32 . V_33 & V_34 ;
if ( V_27 -> V_32 . V_39 & V_40 ) {
V_31 = F_14 ( V_21 , & V_29 ) ;
if ( ! V_31 )
goto V_35;
V_3 = F_15 ( V_31 , V_23 ) ;
if ( ! V_3 || F_16 ( & V_3 -> V_41 ) == 0 )
goto V_35;
F_9 ( L_5 , V_3 ) ;
return V_3 ;
} else {
V_3 = F_17 ( & V_42 ,
V_27 -> V_32 . V_33 >> V_43 ) ;
if ( ! V_3 || F_16 ( & V_3 -> V_41 ) == 0 ) {
F_18 ( L_6 ) ;
goto V_35;
}
if ( V_3 -> V_44 . V_36 != V_25 . V_36 ||
V_3 -> V_45 . V_21 != V_21 )
goto V_35;
V_31 = V_3 -> V_45 . V_31 ;
switch ( V_29 . V_37 . V_38 ) {
case V_46 :
if ( V_31 -> V_29 . V_37 . sin . V_47 !=
V_29 . V_37 . sin . V_47 ||
V_31 -> V_29 . V_37 . sin . V_48 . V_49 !=
V_29 . V_37 . sin . V_48 . V_49 )
goto V_35;
break;
#ifdef F_19
case V_50 :
if ( V_31 -> V_29 . V_37 . V_51 . V_52 !=
V_29 . V_37 . V_51 . V_52 ||
memcmp ( & V_31 -> V_29 . V_37 . V_51 . V_53 ,
& V_29 . V_37 . V_51 . V_53 ,
sizeof( struct V_54 ) ) != 0 )
goto V_35;
break;
#endif
default:
F_20 () ;
}
F_9 ( L_5 , V_3 ) ;
return V_3 ;
}
V_35:
F_9 ( L_7 ) ;
return NULL ;
}
void F_21 ( struct V_1 * V_3 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 =
& V_3 -> V_59 [ V_56 -> V_33 & V_60 ] ;
F_2 ( L_8 , V_3 -> V_15 , V_56 -> V_33 ) ;
if ( F_22 ( V_58 -> V_56 ) == V_56 ) {
F_23 ( V_56 ) ;
V_58 -> V_61 = V_56 -> V_62 ;
if ( V_56 -> V_63 ) {
V_58 -> V_64 = V_56 -> V_63 ;
V_58 -> V_65 = V_66 ;
} else {
V_58 -> V_67 = V_56 -> V_68 ;
V_58 -> V_65 = V_69 ;
}
F_24 () ;
V_58 -> V_70 = V_58 -> V_71 ;
V_58 -> V_71 = V_58 -> V_72 ;
F_25 ( V_58 -> V_56 , NULL ) ;
}
F_9 ( L_1 ) ;
}
void F_26 ( struct V_55 * V_56 )
{
struct V_1 * V_3 = V_56 -> V_3 ;
F_27 ( & V_3 -> V_45 . V_31 -> V_73 ) ;
F_28 ( & V_56 -> V_74 ) ;
F_29 ( & V_3 -> V_45 . V_31 -> V_73 ) ;
if ( F_30 ( V_56 ) )
return F_31 ( V_56 ) ;
F_32 ( & V_3 -> V_5 ) ;
F_21 ( V_3 , V_56 ) ;
F_33 ( & V_3 -> V_5 ) ;
V_56 -> V_3 = NULL ;
V_3 -> V_18 = V_19 ;
F_34 ( V_3 ) ;
}
void F_35 ( struct V_1 * V_3 )
{
ASSERT ( ! F_22 ( V_3 -> V_59 [ 0 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 1 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 2 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 3 ] . V_56 ) ) ;
ASSERT ( F_36 ( & V_3 -> V_4 ) ) ;
F_37 ( & V_75 ) ;
F_38 ( & V_3 -> V_9 ) ;
F_39 ( & V_75 ) ;
F_40 ( & V_3 -> V_11 ) ;
F_41 ( & V_3 -> V_76 , V_77 ) ;
}
bool F_42 ( struct V_1 * V_3 )
{
const void * V_78 = F_43 ( 0 ) ;
int V_79 = F_44 ( & V_3 -> V_41 , 1 , 0 ) ;
if ( V_79 == 0 )
return false ;
if ( F_45 ( & V_3 -> V_7 ) )
F_46 ( V_3 , V_80 , V_79 + 1 , V_78 ) ;
else
F_34 ( V_3 ) ;
return true ;
}
void F_47 ( struct V_1 * V_3 )
{
const void * V_78 = F_43 ( 0 ) ;
if ( V_3 ) {
int V_79 = F_16 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_81 , V_79 , V_78 ) ;
}
}
void F_48 ( struct V_1 * V_3 )
{
const void * V_78 = F_43 ( 0 ) ;
int V_79 = F_8 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_82 , V_79 , V_78 ) ;
}
struct V_1 *
F_49 ( struct V_1 * V_3 )
{
const void * V_78 = F_43 ( 0 ) ;
if ( V_3 ) {
int V_79 = F_44 ( & V_3 -> V_41 , 1 , 0 ) ;
if ( V_79 > 0 )
F_46 ( V_3 , V_82 , V_79 + 1 , V_78 ) ;
else
V_3 = NULL ;
}
return V_3 ;
}
void F_50 ( struct V_1 * V_3 )
{
const void * V_78 = F_43 ( 0 ) ;
int V_79 ;
V_79 = F_51 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_83 , V_79 , V_78 ) ;
F_52 ( V_79 , >= , 0 ) ;
if ( V_79 == 0 )
F_53 ( & V_84 , 0 ) ;
}
static void V_77 ( struct V_85 * V_76 )
{
struct V_1 * V_3 =
F_54 ( V_76 , struct V_1 , V_76 ) ;
F_2 ( L_9 , V_3 -> V_15 , F_16 ( & V_3 -> V_41 ) ) ;
F_52 ( F_16 ( & V_3 -> V_41 ) , == , 0 ) ;
F_55 ( L_10 , V_3 -> V_15 ) ;
F_40 ( & V_3 -> V_11 ) ;
V_3 -> V_12 -> V_86 ( V_3 ) ;
F_56 ( V_3 -> V_45 . V_87 ) ;
F_56 ( V_3 -> V_88 ) ;
F_57 ( V_3 -> V_45 . V_31 ) ;
F_58 ( V_3 -> V_45 . V_21 ) ;
F_59 ( V_3 ) ;
F_9 ( L_1 ) ;
}
static void F_60 ( struct V_89 * V_90 )
{
struct V_1 * V_3 , * V_91 ;
unsigned long V_92 , V_93 , V_18 , V_94 ;
F_61 ( V_95 ) ;
F_2 ( L_1 ) ;
V_94 = V_19 ;
V_92 = V_94 - V_96 * V_97 ;
V_93 = V_98 ;
F_37 ( & V_75 ) ;
F_62 (conn, _p, &rxrpc_connections, link) {
F_52 ( F_16 ( & V_3 -> V_41 ) , > , 0 ) ;
if ( F_63 ( F_16 ( & V_3 -> V_41 ) > 1 ) )
continue;
if ( V_3 -> V_99 == V_100 )
continue;
V_18 = F_64 ( V_3 -> V_18 ) ;
F_18 ( L_11 ,
V_3 -> V_15 , F_16 ( & V_3 -> V_41 ) ,
( long ) V_92 - ( long ) V_18 ) ;
if ( F_65 ( V_18 , V_92 ) ) {
if ( F_66 ( V_18 , V_93 ) )
V_93 = V_18 ;
continue;
}
if ( F_67 ( & V_3 -> V_41 , 1 , 0 ) != 1 )
continue;
if ( F_68 ( V_3 ) )
F_20 () ;
else
F_69 ( V_3 ) ;
F_70 ( & V_3 -> V_10 , & V_95 ) ;
}
F_39 ( & V_75 ) ;
if ( V_93 != V_98 ) {
F_18 ( L_12 , ( long ) V_93 - V_94 ) ;
ASSERT ( F_65 ( V_93 , V_94 ) ) ;
F_53 ( & V_84 ,
V_93 - V_94 ) ;
}
while ( ! F_36 ( & V_95 ) ) {
V_3 = F_71 ( V_95 . V_101 , struct V_1 ,
V_10 ) ;
F_38 ( & V_3 -> V_10 ) ;
F_52 ( F_16 ( & V_3 -> V_41 ) , == , 0 ) ;
F_35 ( V_3 ) ;
}
F_9 ( L_1 ) ;
}
void T_2 F_72 ( void )
{
struct V_1 * V_3 , * V_91 ;
bool V_102 = false ;
F_2 ( L_1 ) ;
F_73 () ;
V_96 = 0 ;
F_74 ( & V_84 ) ;
F_53 ( & V_84 , 0 ) ;
F_75 ( V_103 ) ;
F_37 ( & V_75 ) ;
F_62 (conn, _p, &rxrpc_connections, link) {
F_76 ( L_13 ,
V_3 , F_16 ( & V_3 -> V_41 ) ) ;
V_102 = true ;
}
F_39 ( & V_75 ) ;
F_77 ( V_102 ) ;
ASSERT ( F_36 ( & V_104 ) ) ;
F_78 () ;
F_79 () ;
F_9 ( L_1 ) ;
}
