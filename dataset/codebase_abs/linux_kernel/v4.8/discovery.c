void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
if ( F_3 ( & V_3 -> V_5 ) ) {
F_4 ( & V_3 -> V_5 , & V_2 -> V_6 ) ;
V_3 -> V_7 = true ;
V_8 ++ ;
}
F_5 ( & V_4 ) ;
}
void F_6 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
if ( ! F_3 ( & V_3 -> V_5 ) ) {
V_3 -> V_7 = false ;
F_7 ( & V_3 -> V_5 ) ;
V_8 ++ ;
}
F_5 ( & V_4 ) ;
}
static void F_8 ( struct V_9 * V_10 ,
struct V_1 * V_3 , char * V_11 , T_1 type , T_2 V_12 )
{
struct V_13 * V_14 = & V_10 -> V_15 [ V_12 ] ;
V_14 -> V_16 = V_3 -> V_17 . V_16 ;
V_14 -> V_18 = V_3 -> V_17 . V_18 ;
V_14 -> V_19 = V_3 -> V_17 . V_19 ;
V_14 -> V_20 = V_3 -> V_17 . V_20 ;
V_14 -> V_21 = F_9 ( V_22 ) ;
V_14 -> V_23 = F_9 ( V_24 ) ;
V_14 -> V_25 = type ;
memcpy ( V_14 -> V_26 , V_3 -> V_17 . V_26 , V_27 ) ;
memcpy ( V_14 -> V_28 , V_3 -> V_17 . V_28 , V_29 ) ;
memcpy ( V_14 -> V_30 . V_31 , V_3 -> V_17 . V_30 . V_31 , V_32 ) ;
memcpy ( V_14 -> V_33 , V_11 , V_34 ) ;
}
static void F_10 ( struct V_35 * V_36 )
{
const int V_37 = sizeof( struct V_13 ) ;
struct V_38 * V_39 = V_36 -> V_40 -> V_39 ;
struct V_9 * V_10 ;
T_3 V_41 = F_11 ( V_36 -> V_42 ) ;
T_3 V_43 = F_12 ( V_41 , sizeof( * V_10 ) ) ;
int V_44 = V_41 - sizeof( * V_10 ) ;
struct V_45 * V_46 ;
struct V_1 * V_47 ;
T_2 V_12 = 0 ;
T_4 V_48 = 0 ;
V_10 = F_13 ( V_43 , V_49 ) ;
if ( ! V_10 ) {
V_48 = V_50 ;
goto V_51;
}
F_14 ( & V_4 ) ;
F_15 (p, &req->port->subsystems, entry) {
if ( ! F_16 ( V_36 , V_46 -> V_52 , V_39 -> V_53 ) )
continue;
if ( V_44 >= V_37 ) {
F_8 ( V_10 , V_36 -> V_3 ,
V_46 -> V_52 -> V_54 ,
V_55 , V_12 ) ;
V_44 -= V_37 ;
}
V_12 ++ ;
}
F_15 (r, &req->port->referrals, entry) {
if ( V_44 >= V_37 ) {
F_8 ( V_10 , V_47 ,
V_56 ,
V_57 , V_12 ) ;
V_44 -= V_37 ;
}
V_12 ++ ;
}
V_10 -> V_58 = F_17 ( V_8 ) ;
V_10 -> V_12 = F_17 ( V_12 ) ;
V_10 -> V_59 = F_9 ( 0 ) ;
F_18 ( & V_4 ) ;
V_48 = F_19 ( V_36 , 0 , V_10 , V_41 ) ;
F_20 ( V_10 ) ;
V_51:
F_21 ( V_36 , V_48 ) ;
}
static void F_22 ( struct V_35 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_40 -> V_39 ;
struct V_60 * V_61 ;
T_4 V_48 = 0 ;
V_61 = F_13 ( sizeof( * V_61 ) , V_49 ) ;
if ( ! V_61 ) {
V_48 = V_50 ;
goto V_51;
}
memset ( V_61 -> V_62 , ' ' , sizeof( V_61 -> V_62 ) ) ;
strncpy ( ( char * ) V_61 -> V_62 , V_63 , sizeof( V_61 -> V_62 ) ) ;
V_61 -> V_64 = 0 ;
V_61 -> V_21 = F_9 ( V_39 -> V_21 ) ;
V_61 -> V_65 = F_23 ( V_39 -> V_52 -> V_65 ) ;
V_61 -> V_66 = ( 1 << 2 ) ;
V_61 -> V_67 = F_9 ( V_68 ) ;
V_61 -> V_69 = F_23 ( 1 << 0 ) ;
if ( V_39 -> V_70 -> V_71 )
V_61 -> V_69 |= F_23 ( 1 << 2 ) ;
if ( V_39 -> V_70 -> V_72 )
V_61 -> V_69 |= F_23 ( 1 << 20 ) ;
strcpy ( V_61 -> V_33 , V_39 -> V_52 -> V_54 ) ;
V_48 = F_19 ( V_36 , 0 , V_61 , sizeof( * V_61 ) ) ;
F_20 ( V_61 ) ;
V_51:
F_21 ( V_36 , V_48 ) ;
}
int F_24 ( struct V_35 * V_36 )
{
struct V_73 * V_42 = V_36 -> V_42 ;
V_36 -> V_74 = NULL ;
if ( F_25 ( ! ( V_36 -> V_40 -> V_39 -> V_75 & V_76 ) ) ) {
F_26 ( L_1 ,
V_42 -> V_31 . V_77 ) ;
return V_78 | V_79 ;
}
switch ( V_42 -> V_31 . V_77 ) {
case V_80 :
V_36 -> V_41 = F_11 ( V_42 ) ;
switch ( V_42 -> V_81 . V_82 ) {
case V_83 :
V_36 -> V_84 = F_10 ;
return 0 ;
default:
F_26 ( L_2 ,
V_42 -> V_81 . V_82 ) ;
return V_78 | V_79 ;
}
case V_85 :
V_36 -> V_41 = 4096 ;
switch ( F_27 ( V_42 -> V_86 . V_87 ) ) {
case 0x01 :
V_36 -> V_84 =
F_22 ;
return 0 ;
default:
F_26 ( L_3 ,
F_27 ( V_42 -> V_86 . V_87 ) ) ;
return V_78 | V_79 ;
}
default:
F_26 ( L_4 ,
V_42 -> V_31 . V_77 ) ;
return V_78 | V_79 ;
}
F_26 ( L_5 , V_42 -> V_31 . V_77 ) ;
return V_78 | V_79 ;
}
int T_5 F_28 ( void )
{
V_88 =
F_29 ( V_56 , V_57 ) ;
if ( ! V_88 )
return - V_89 ;
return 0 ;
}
void F_30 ( void )
{
F_31 ( V_88 ) ;
}
