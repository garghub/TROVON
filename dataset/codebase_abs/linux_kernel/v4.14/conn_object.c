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
if ( F_12 ( V_21 , & V_29 , V_23 ) < 0 )
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
if ( V_56 -> V_61 ) {
V_58 -> V_62 = V_56 -> V_61 ;
V_58 -> V_63 = V_64 ;
} else {
V_58 -> V_65 = V_56 -> V_66 ;
V_58 -> V_63 = V_67 ;
}
F_24 () ;
V_58 -> V_68 = V_58 -> V_69 ;
V_58 -> V_69 = V_58 -> V_70 ;
F_25 ( V_58 -> V_56 , NULL ) ;
}
F_9 ( L_1 ) ;
}
void F_26 ( struct V_55 * V_56 )
{
struct V_1 * V_3 = V_56 -> V_3 ;
V_56 -> V_31 -> V_71 = V_56 -> V_71 ;
F_27 ( & V_3 -> V_45 . V_31 -> V_72 ) ;
F_28 ( & V_56 -> V_73 ) ;
F_29 ( & V_3 -> V_45 . V_31 -> V_72 ) ;
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
struct V_74 * V_75 = V_3 -> V_45 . V_21 -> V_75 ;
ASSERT ( ! F_22 ( V_3 -> V_59 [ 0 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 1 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 2 ] . V_56 ) &&
! F_22 ( V_3 -> V_59 [ 3 ] . V_56 ) ) ;
ASSERT ( F_36 ( & V_3 -> V_4 ) ) ;
F_37 ( & V_75 -> V_76 ) ;
F_38 ( & V_3 -> V_9 ) ;
F_39 ( & V_75 -> V_76 ) ;
F_40 ( & V_3 -> V_11 ) ;
F_41 ( & V_3 -> V_77 , V_78 ) ;
}
bool F_42 ( struct V_1 * V_3 )
{
const void * V_79 = F_43 ( 0 ) ;
int V_80 = F_44 ( & V_3 -> V_41 , 1 , 0 ) ;
if ( V_80 == 0 )
return false ;
if ( F_45 ( & V_3 -> V_7 ) )
F_46 ( V_3 , V_81 , V_80 + 1 , V_79 ) ;
else
F_34 ( V_3 ) ;
return true ;
}
void F_47 ( struct V_1 * V_3 )
{
const void * V_79 = F_43 ( 0 ) ;
if ( V_3 ) {
int V_80 = F_16 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_82 , V_80 , V_79 ) ;
}
}
void F_48 ( struct V_1 * V_3 )
{
const void * V_79 = F_43 ( 0 ) ;
int V_80 = F_8 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_83 , V_80 , V_79 ) ;
}
struct V_1 *
F_49 ( struct V_1 * V_3 )
{
const void * V_79 = F_43 ( 0 ) ;
if ( V_3 ) {
int V_80 = F_44 ( & V_3 -> V_41 , 1 , 0 ) ;
if ( V_80 > 0 )
F_46 ( V_3 , V_83 , V_80 + 1 , V_79 ) ;
else
V_3 = NULL ;
}
return V_3 ;
}
void F_50 ( struct V_1 * V_3 )
{
struct V_74 * V_75 ;
const void * V_79 = F_43 ( 0 ) ;
int V_80 ;
V_80 = F_51 ( & V_3 -> V_41 ) ;
F_46 ( V_3 , V_84 , V_80 , V_79 ) ;
F_52 ( V_80 , >= , 0 ) ;
if ( V_80 == 0 ) {
V_75 = V_3 -> V_45 . V_21 -> V_75 ;
F_53 ( & V_75 -> V_85 , 0 ) ;
}
}
static void V_78 ( struct V_86 * V_77 )
{
struct V_1 * V_3 =
F_54 ( V_77 , struct V_1 , V_77 ) ;
F_2 ( L_9 , V_3 -> V_15 , F_16 ( & V_3 -> V_41 ) ) ;
F_52 ( F_16 ( & V_3 -> V_41 ) , == , 0 ) ;
F_55 ( L_10 , V_3 -> V_15 ) ;
F_40 ( & V_3 -> V_11 ) ;
V_3 -> V_12 -> V_87 ( V_3 ) ;
F_56 ( V_3 -> V_45 . V_88 ) ;
F_56 ( V_3 -> V_89 ) ;
F_57 ( V_3 -> V_45 . V_31 ) ;
F_58 ( V_3 -> V_45 . V_21 ) ;
F_59 ( V_3 ) ;
F_9 ( L_1 ) ;
}
void F_60 ( struct V_90 * V_91 )
{
struct V_1 * V_3 , * V_92 ;
struct V_74 * V_75 =
F_54 ( F_61 ( V_91 ) ,
struct V_74 , V_85 ) ;
unsigned long V_93 , V_94 , V_18 , V_95 ;
F_62 ( V_96 ) ;
F_2 ( L_1 ) ;
V_95 = V_19 ;
V_93 = V_95 - V_97 * V_98 ;
V_94 = V_99 ;
F_37 ( & V_75 -> V_76 ) ;
F_63 (conn, _p, &rxnet->service_conns, link) {
F_52 ( F_16 ( & V_3 -> V_41 ) , > , 0 ) ;
if ( F_64 ( F_16 ( & V_3 -> V_41 ) > 1 ) )
continue;
if ( V_3 -> V_100 == V_101 )
continue;
V_18 = F_65 ( V_3 -> V_18 ) ;
F_18 ( L_11 ,
V_3 -> V_15 , F_16 ( & V_3 -> V_41 ) ,
( long ) V_93 - ( long ) V_18 ) ;
if ( F_66 ( V_18 , V_93 ) ) {
if ( F_67 ( V_18 , V_94 ) )
V_94 = V_18 ;
continue;
}
if ( F_68 ( & V_3 -> V_41 , 1 , 0 ) != 1 )
continue;
if ( F_69 ( V_3 ) )
F_20 () ;
else
F_70 ( V_3 ) ;
F_71 ( & V_3 -> V_10 , & V_96 ) ;
}
F_39 ( & V_75 -> V_76 ) ;
if ( V_94 != V_99 ) {
F_18 ( L_12 , ( long ) V_94 - V_95 ) ;
ASSERT ( F_66 ( V_94 , V_95 ) ) ;
F_53 ( & V_75 -> V_102 ,
V_94 - V_95 ) ;
}
while ( ! F_36 ( & V_96 ) ) {
V_3 = F_72 ( V_96 . V_103 , struct V_1 ,
V_10 ) ;
F_38 ( & V_3 -> V_10 ) ;
F_52 ( F_16 ( & V_3 -> V_41 ) , == , 0 ) ;
F_35 ( V_3 ) ;
}
F_9 ( L_1 ) ;
}
void F_73 ( struct V_74 * V_75 )
{
struct V_1 * V_3 , * V_92 ;
bool V_104 = false ;
F_2 ( L_1 ) ;
F_74 ( V_75 ) ;
V_97 = 0 ;
F_75 ( & V_75 -> V_102 ) ;
F_53 ( & V_75 -> V_102 , 0 ) ;
F_76 ( V_105 ) ;
F_37 ( & V_75 -> V_76 ) ;
F_63 (conn, _p, &rxnet->service_conns, link) {
F_77 ( L_13 ,
V_3 , F_16 ( & V_3 -> V_41 ) ) ;
V_104 = true ;
}
F_39 ( & V_75 -> V_76 ) ;
F_78 ( V_104 ) ;
ASSERT ( F_36 ( & V_75 -> V_106 ) ) ;
F_9 ( L_1 ) ;
}
