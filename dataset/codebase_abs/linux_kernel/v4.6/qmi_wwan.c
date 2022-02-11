static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
if ( V_6 -> V_8 & V_9 ) {
V_2 -> V_10 = NULL ;
V_2 -> type = V_11 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_8 = V_14 | V_15 | V_16 ;
F_3 ( V_2 , L_1 ) ;
} else if ( ! V_2 -> V_10 ) {
F_4 ( V_2 ) ;
F_3 ( V_2 , L_2 ) ;
}
F_5 ( V_2 , V_2 -> V_17 ) ;
}
static T_1 F_6 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_3 * V_4 = F_2 ( F_7 ( V_19 ) ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
return sprintf ( V_22 , L_3 , V_6 -> V_8 & V_9 ? 'Y' : 'N' ) ;
}
static T_1 F_8 ( struct V_18 * V_19 , struct V_20 * V_21 , const char * V_22 , T_2 V_23 )
{
struct V_3 * V_4 = F_2 ( F_7 ( V_19 ) ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
bool V_24 ;
int V_25 ;
if ( F_9 ( V_22 , & V_24 ) )
return - V_26 ;
if ( V_24 == ( V_6 -> V_8 & V_9 ) )
return V_23 ;
if ( ! F_10 () )
return F_11 () ;
if ( F_12 ( V_4 -> V_2 ) ) {
F_13 ( V_4 -> V_2 , L_4 ) ;
V_25 = - V_27 ;
goto V_28;
}
V_25 = F_14 ( V_29 , V_4 -> V_2 ) ;
V_25 = F_15 ( V_25 ) ;
if ( V_25 ) {
F_13 ( V_4 -> V_2 , L_5 ) ;
goto V_28;
}
if ( V_24 )
V_6 -> V_8 |= V_9 ;
else
V_6 -> V_8 &= ~ V_9 ;
F_1 ( V_4 -> V_2 ) ;
F_14 ( V_30 , V_4 -> V_2 ) ;
V_25 = V_23 ;
V_28:
F_16 () ;
return V_25 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
bool V_33 = V_6 -> V_8 & V_9 ;
T_3 V_34 ;
if ( V_32 -> V_23 < V_4 -> V_2 -> V_12 )
return 0 ;
switch ( V_32 -> V_7 [ 0 ] & 0xf0 ) {
case 0x40 :
V_34 = F_18 ( V_35 ) ;
break;
case 0x60 :
V_34 = F_18 ( V_36 ) ;
break;
case 0x00 :
if ( V_33 )
return 0 ;
if ( F_19 ( V_32 -> V_7 ) )
return 1 ;
F_20 ( V_32 ) ;
goto V_37;
default:
if ( V_33 )
return 0 ;
return 1 ;
}
if ( V_33 ) {
V_32 -> V_4 = V_4 -> V_2 ;
V_32 -> V_38 = V_34 ;
return 1 ;
}
if ( F_21 ( V_32 ) < V_39 )
return 0 ;
F_22 ( V_32 , V_39 ) ;
F_20 ( V_32 ) ;
F_23 ( V_32 ) -> V_40 = V_34 ;
F_24 ( F_23 ( V_32 ) -> V_41 ) ;
V_37:
memcpy ( F_23 ( V_32 ) -> V_42 , V_4 -> V_2 -> V_43 , V_44 ) ;
return 1 ;
}
static bool F_25 ( const char * V_7 )
{
return ( V_7 [ 0 ] & 0xd0 ) == 0x40 ;
}
static int F_26 ( struct V_1 * V_4 , void * V_45 )
{
int V_25 ;
struct V_46 * V_47 = V_45 ;
V_25 = F_27 ( V_4 , V_45 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( F_25 ( V_47 -> V_48 ) )
return - V_49 ;
F_28 ( V_4 , V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 , int V_50 )
{
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
int V_51 ;
F_30 ( & V_4 -> V_52 -> V_4 , L_6 , V_53 ,
F_31 ( & V_6 -> V_54 ) , V_50 ) ;
if ( ( V_50 && F_32 ( 1 , & V_6 -> V_54 ) == 1 ) ||
( ! V_50 && F_33 ( & V_6 -> V_54 ) ) ) {
V_51 = F_34 ( V_4 -> V_52 ) ;
V_4 -> V_52 -> V_55 = V_50 ;
if ( ! V_51 )
F_35 ( V_4 -> V_52 ) ;
}
return 0 ;
}
static int F_36 ( struct V_56 * V_52 , int V_50 )
{
struct V_3 * V_4 = F_37 ( V_52 ) ;
if ( ! V_4 )
return 0 ;
return F_29 ( V_4 , V_50 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
int V_51 ;
struct V_57 * V_58 = NULL ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
V_51 = F_39 ( V_4 , V_6 -> V_7 ) ;
if ( V_51 < 0 )
goto V_28;
if ( V_6 -> V_59 != V_6 -> V_7 )
V_4 -> V_60 = & V_6 -> V_59 -> V_61 -> V_62 [ 0 ] ;
if ( ! V_4 -> V_60 ) {
V_51 = - V_26 ;
goto V_28;
}
F_40 ( & V_6 -> V_54 , 0 ) ;
V_58 = F_41 ( V_6 -> V_59 , & V_4 -> V_60 -> V_63 ,
4096 , & F_36 ) ;
if ( F_42 ( V_58 ) ) {
F_43 ( & V_6 -> V_59 -> V_4 , L_7 ) ;
V_51 = F_44 ( V_58 ) ;
goto V_28;
}
V_4 -> V_60 = NULL ;
V_6 -> V_58 = V_58 ;
V_28:
return V_51 ;
}
static int F_45 ( struct V_3 * V_4 , bool V_50 )
{
T_4 V_52 = V_4 -> V_52 -> V_61 -> V_63 . V_64 ;
return F_46 ( V_4 , V_65 ,
V_66 | V_67 | V_68 ,
V_50 ? 0x01 : 0x00 , V_52 , NULL , 0 ) ;
}
static int F_47 ( struct V_3 * V_4 , struct V_56 * V_52 )
{
int V_60 = - 1 ;
T_4 * V_22 = V_52 -> V_61 -> V_69 ;
int V_23 = V_52 -> V_61 -> V_70 ;
struct V_71 * V_63 = & V_52 -> V_61 -> V_63 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_57 * V_76 = F_48 ( V_52 ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
struct V_77 V_78 ;
F_49 ( ( sizeof( ( (struct V_3 * ) 0 ) -> V_7 ) <
sizeof( struct V_5 ) ) ) ;
V_6 -> V_59 = V_52 ;
V_6 -> V_7 = V_52 ;
F_50 ( & V_78 , V_52 , V_22 , V_23 ) ;
V_73 = V_78 . V_72 ;
V_75 = V_78 . V_74 ;
if ( V_73 ) {
V_6 -> V_7 = F_51 ( V_4 -> V_79 ,
V_73 -> V_80 ) ;
if ( V_63 -> V_64 != V_73 -> V_81 ||
! V_6 -> V_7 ) {
F_43 ( & V_52 -> V_4 ,
L_8 ,
V_73 -> V_81 ,
V_73 -> V_80 ) ;
V_73 = NULL ;
V_6 -> V_7 = V_52 ;
}
}
if ( V_75 ) {
V_4 -> V_82 = F_52 ( V_75 -> V_83 ) ;
F_53 ( V_4 , V_75 -> V_84 ) ;
}
if ( V_6 -> V_59 != V_6 -> V_7 ) {
V_60 = F_54 ( V_76 , V_6 -> V_7 , V_4 ) ;
if ( V_60 < 0 )
goto V_28;
}
V_60 = F_38 ( V_4 ) ;
if ( V_60 < 0 && V_6 -> V_59 != V_6 -> V_7 ) {
F_55 ( V_6 -> V_7 , NULL ) ;
F_56 ( V_76 , V_6 -> V_7 ) ;
}
if ( F_52 ( V_4 -> V_79 -> V_85 . V_86 ) >= 0x0201 ) {
F_29 ( V_4 , 1 ) ;
F_45 ( V_4 , true ) ;
}
if ( F_57 ( V_4 -> V_2 -> V_43 , V_87 ) ||
F_57 ( V_4 -> V_2 -> V_43 , V_88 ) )
F_58 ( V_4 -> V_2 ) ;
if ( F_25 ( V_4 -> V_2 -> V_43 ) ) {
V_4 -> V_2 -> V_43 [ 0 ] |= 0x02 ;
V_4 -> V_2 -> V_43 [ 0 ] &= 0xbf ;
}
V_4 -> V_2 -> V_89 = & V_90 ;
V_4 -> V_2 -> V_91 [ 0 ] = & V_92 ;
V_28:
return V_60 ;
}
static void F_59 ( struct V_3 * V_4 , struct V_56 * V_52 )
{
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
struct V_57 * V_76 = F_48 ( V_52 ) ;
struct V_56 * V_93 ;
if ( V_6 -> V_58 && V_6 -> V_58 -> V_94 )
V_6 -> V_58 -> V_94 ( V_6 -> V_59 ) ;
if ( F_52 ( V_4 -> V_79 -> V_85 . V_86 ) >= 0x0201 ) {
F_45 ( V_4 , false ) ;
F_29 ( V_4 , 0 ) ;
}
if ( V_52 == V_6 -> V_59 )
V_93 = V_6 -> V_7 ;
else
V_93 = V_6 -> V_59 ;
if ( V_93 && V_52 != V_93 ) {
F_55 ( V_93 , NULL ) ;
F_56 ( V_76 , V_93 ) ;
}
V_6 -> V_58 = NULL ;
V_6 -> V_7 = NULL ;
V_6 -> V_59 = NULL ;
}
static int F_60 ( struct V_56 * V_52 , T_5 V_95 )
{
struct V_3 * V_4 = F_37 ( V_52 ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
int V_25 ;
V_25 = F_61 ( V_52 , V_95 ) ;
if ( V_25 < 0 )
goto V_28;
if ( V_52 == V_6 -> V_59 && V_6 -> V_58 &&
V_6 -> V_58 -> V_96 )
V_25 = V_6 -> V_58 -> V_96 ( V_52 , V_95 ) ;
if ( V_25 < 0 )
F_62 ( V_52 ) ;
V_28:
return V_25 ;
}
static int F_63 ( struct V_56 * V_52 )
{
struct V_3 * V_4 = F_37 ( V_52 ) ;
struct V_5 * V_6 = ( void * ) & V_4 -> V_7 ;
int V_25 = 0 ;
bool V_97 = ( V_52 == V_6 -> V_59 && V_6 -> V_58 &&
V_6 -> V_58 -> V_98 ) ;
if ( V_97 )
V_25 = V_6 -> V_58 -> V_98 ( V_52 ) ;
if ( V_25 < 0 )
goto V_28;
V_25 = F_62 ( V_52 ) ;
if ( V_25 < 0 && V_97 )
V_6 -> V_58 -> V_96 ( V_52 , V_99 ) ;
V_28:
return V_25 ;
}
static bool F_64 ( struct V_56 * V_52 )
{
struct V_100 * V_4 = F_65 ( V_52 ) ;
if ( V_4 -> V_101 &&
F_52 ( V_4 -> V_85 . V_102 ) == 0x05c6 &&
F_52 ( V_4 -> V_85 . V_103 ) == 0x9215 &&
V_4 -> V_101 -> V_63 . V_104 == 5 )
return true ;
return false ;
}
static int F_66 ( struct V_56 * V_52 ,
const struct V_105 * V_106 )
{
struct V_105 * V_107 = (struct V_105 * ) V_106 ;
struct V_71 * V_63 = & V_52 -> V_61 -> V_63 ;
if ( ! V_107 -> V_108 ) {
F_30 ( & V_52 -> V_4 , L_9 ) ;
V_107 -> V_108 = ( unsigned long ) & V_109 ;
}
if ( F_64 ( V_52 ) && V_63 -> V_64 == 0 ) {
F_30 ( & V_52 -> V_4 , L_10 ) ;
return - V_110 ;
}
return F_67 ( V_52 , V_107 ) ;
}
