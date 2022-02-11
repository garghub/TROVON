static int F_1 ( struct V_1 * V_2 , int type ,
const struct V_3 * V_4 , int V_5 )
{
F_2 ( V_6 , V_7 ) ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_11 ;
int V_12 ;
int error = 0 ;
V_8 = F_3 ( V_2 -> V_13 ) ? F_3 ( V_2 -> V_13 ) -> V_2 : NULL ;
if ( ! V_8 ) return - V_14 ;
V_10 = F_4 ( sizeof( * V_4 ) , V_15 ) ;
if ( ! V_10 ) return - V_16 ;
F_5 () ;
V_8 = F_3 ( V_2 -> V_13 ) ? F_3 ( V_2 -> V_13 ) -> V_2 : NULL ;
if ( ! V_8 ) {
F_6 ( V_10 ) ;
return - V_14 ;
}
F_7 ( V_8 , V_10 -> V_17 ) ;
V_11 = (struct V_3 * ) F_8 ( V_10 , sizeof( * V_11 ) ) ;
* V_11 = * V_4 ;
V_11 -> V_18 . V_19 = V_20 ;
V_11 -> type = type ;
memset ( & V_11 -> V_2 , 0 , sizeof( V_21 ) ) ;
* (struct V_1 * * ) & V_11 -> V_2 = V_2 ;
V_12 = F_9 ( V_5 , & V_2 -> V_22 ) ;
V_8 -> V_23 ( V_8 , V_10 ) ;
F_10 ( F_11 ( F_12 ( V_2 ) ) , & V_6 ) ;
while ( F_9 ( V_5 , & V_2 -> V_22 ) == V_12 ) {
F_5 () ;
V_8 = F_3 ( V_2 -> V_13 ) ? F_3 ( V_2 -> V_13 ) -> V_2 : NULL ;
if ( ! V_8 ) {
error = - V_14 ;
break;
}
F_13 ( V_24 ) ;
F_14 () ;
}
F_13 ( V_25 ) ;
F_15 ( F_11 ( F_12 ( V_2 ) ) , & V_6 ) ;
return error ;
}
static int F_16 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = * (struct V_1 * * ) & V_4 -> V_2 ;
V_2 -> V_26 = V_4 -> V_27 . V_28 . V_26 ;
V_2 -> V_29 = V_4 -> V_27 . V_28 . V_29 ;
V_2 -> V_30 = V_4 -> V_30 ;
F_12 ( V_2 ) -> V_31 = - V_4 -> V_32 ;
switch ( V_4 -> type ) {
case V_33 :
F_17 ( V_34 , & V_2 -> V_22 ) ;
break;
case V_35 :
F_17 ( V_36 , & V_2 -> V_22 ) ;
break;
default:
F_18 ( V_37 L_1 ,
V_4 -> type ) ;
return - V_38 ;
}
F_19 ( F_11 ( F_12 ( V_2 ) ) ) ;
return 0 ;
}
static void F_20 ( struct V_39 * V_13 )
{
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int error ;
short V_26 = V_2 -> V_26 ;
int V_29 = V_2 -> V_29 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_27 . V_40 = V_41 ;
V_4 . V_18 . V_26 = F_22 ( V_26 ) ;
V_4 . V_27 . V_28 . V_26 = V_26 ;
V_4 . V_18 . V_29 = F_22 ( V_29 ) ;
V_4 . V_27 . V_28 . V_29 = V_29 ;
if ( V_26 == V_42 || V_29 == V_43 ) return 0 ;
V_4 . type = V_33 ;
V_4 . V_30 = V_2 -> V_30 ;
F_23 ( V_36 , & V_2 -> V_22 ) ;
F_24 ( V_34 , & V_2 -> V_22 ) ;
error = F_1 ( V_2 , V_33 , & V_4 , V_34 ) ;
if ( error ) return error ;
return - F_12 ( V_2 ) -> V_31 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_27 . V_40 = V_41 ;
V_4 . V_27 . V_28 . V_26 = V_2 -> V_26 ;
V_4 . V_27 . V_28 . V_29 = V_2 -> V_29 ;
F_24 ( V_34 , & V_2 -> V_22 ) ;
( void ) F_1 ( V_2 , V_35 , & V_4 , V_36 ) ;
}
static int F_26 ( struct V_39 * V_13 , unsigned int V_44 , void T_1 * V_45 )
{
struct V_46 V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_52 ;
if ( V_44 != V_53 ) return - V_54 ;
if ( F_27 ( & V_47 , V_45 , sizeof( V_47 ) ) ) return - V_55 ;
if ( V_47 . V_56 == V_57 ) V_47 . V_56 = V_58 ;
if ( V_47 . V_59 == V_57 ) V_47 . V_59 = V_60 ;
if ( V_47 . V_56 > V_58 || V_47 . V_56 < 0 ||
V_47 . V_59 > V_60 || V_47 . V_59 < 0 ) return - V_38 ;
F_28 ( & V_61 ) ;
for( V_52 = 0 ; V_52 < V_62 ; ++ V_52 ) {
struct V_63 * V_64 = & V_65 [ V_52 ] ;
F_29 (s, node, head) {
V_2 = F_30 ( V_51 ) ;
if ( V_2 -> V_13 != V_13 )
continue;
if ( ( V_2 -> V_26 >> V_47 . V_56 ) ||
( V_2 -> V_29 >> V_47 . V_59 ) ) {
F_31 ( & V_61 ) ;
return - V_66 ;
}
}
}
F_31 ( & V_61 ) ;
V_13 -> V_67 = V_47 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_68 * V_69 ;
struct V_1 * V_8 = NULL ;
struct V_9 * V_70 ;
struct V_71 * V_18 ;
int V_72 ;
if ( V_2 -> V_30 . V_73 . V_74 == V_75 ) {
if ( V_2 -> V_76 ) V_2 -> V_76 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
return - V_38 ;
}
V_69 = F_3 ( V_2 -> V_13 ) ;
if ( V_69 ) V_8 = V_69 -> V_2 ;
if ( ! V_69 || ! V_8 ) {
if ( V_2 -> V_76 ) V_2 -> V_76 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
if ( V_69 ) return 0 ;
F_33 ( & V_2 -> V_77 -> V_78 ) ;
return - V_79 ;
}
V_72 = V_10 -> V_80 + sizeof( struct V_71 ) ;
V_70 = F_34 ( V_8 , V_72 , V_81 ) ;
if ( ! V_70 ) {
if ( V_2 -> V_76 ) V_2 -> V_76 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
F_33 ( & V_2 -> V_77 -> V_78 ) ;
return - V_82 ;
}
V_18 = ( void * ) F_8 ( V_70 , sizeof( struct V_71 ) ) ;
V_18 -> V_26 = F_22 ( V_2 -> V_26 ) ;
V_18 -> V_29 = F_22 ( V_2 -> V_29 ) ;
V_18 -> V_19 = F_35 ( V_10 -> V_80 ) ;
F_36 ( V_10 , F_8 ( V_70 , V_10 -> V_80 ) , V_10 -> V_80 ) ;
if ( V_2 -> V_76 ) V_2 -> V_76 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
V_8 -> V_23 ( V_8 , V_70 ) ;
F_33 ( & V_2 -> V_77 -> V_83 ) ;
F_33 ( & V_8 -> V_77 -> V_84 ) ;
return 0 ;
}
static int F_37 ( struct V_39 * V_13 , T_2 * V_85 , char * V_86 )
{
struct V_68 * V_69 = F_3 ( V_13 ) ;
if ( * V_85 ) return 0 ;
if ( ! V_69 -> V_87 ) return sprintf ( V_86 , L_2 ) ;
return sprintf ( V_86 , L_3 ,
V_69 -> V_2 ? L_4 : L_5 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_88 ;
struct V_68 * V_69 ;
V_88 = (struct V_39 * ) V_2 -> V_69 ;
V_69 = F_3 ( V_88 ) ;
V_69 -> V_2 = NULL ;
if ( V_69 -> V_87 ) return;
V_88 -> V_69 = NULL ;
F_39 ( V_69 ) ;
F_40 ( V_88 ) ;
V_2 -> V_69 = NULL ;
F_41 ( V_89 ) ;
}
static struct V_1 * F_42 ( struct V_39 * V_13 , short V_26 , int V_29 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_64 = & V_65 [ V_29 & ( V_62 - 1 ) ] ;
F_29 (s, node, head) {
V_2 = F_30 ( V_51 ) ;
if ( V_2 -> V_13 == V_13 &&
V_2 -> V_29 == V_29 && V_2 -> V_26 == V_26 &&
V_2 -> V_30 . V_90 . V_74 != V_75 ) {
return V_2 ;
}
}
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_13 ;
struct V_71 * V_18 ;
struct V_1 * V_8 ;
struct V_9 * V_70 ;
int V_32 = 0 ;
if ( ! V_10 -> V_80 ) return 0 ;
V_13 = V_2 -> V_69 ;
V_18 = (struct V_71 * ) V_10 -> V_91 ;
if ( V_18 -> V_19 == V_20 ) {
V_32 = F_16 (
(struct V_3 * ) V_10 -> V_91 ) ;
goto V_92;
}
F_28 ( & V_61 ) ;
V_8 = F_42 ( V_13 , F_44 ( V_18 -> V_26 ) , F_44 ( V_18 -> V_29 ) ) ;
F_31 ( & V_61 ) ;
if ( ! V_8 ) {
F_33 ( & V_2 -> V_77 -> V_78 ) ;
goto V_92;
}
F_45 ( V_10 , sizeof( struct V_71 ) ) ;
V_70 = F_34 ( V_8 , V_10 -> V_80 , V_15 ) ;
if ( ! V_70 ) {
V_32 = - V_82 ;
goto V_92;
}
F_46 ( V_70 ) ;
F_36 ( V_10 , F_8 ( V_70 , V_10 -> V_80 ) , V_10 -> V_80 ) ;
V_8 -> V_23 ( V_8 , V_70 ) ;
F_33 ( & V_2 -> V_77 -> V_83 ) ;
F_33 ( & V_8 -> V_77 -> V_84 ) ;
V_92:
if ( V_2 -> V_76 ) V_2 -> V_76 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
return V_32 ;
}
static int F_47 ( int V_93 , int V_87 , struct V_39 * * V_32 )
{
struct V_68 * V_69 ;
struct V_39 * V_13 ;
V_69 = F_48 ( sizeof( * V_69 ) , V_15 ) ;
if ( ! V_69 )
return - V_16 ;
V_13 = F_49 ( V_94 , NULL , & V_95 , V_93 , NULL ) ;
if ( ! V_13 ) {
F_39 ( V_69 ) ;
return V_93 == - 1 ? - V_16 : - V_66 ;
}
V_13 -> V_67 . V_56 = V_58 ;
V_13 -> V_67 . V_59 = V_60 ;
V_13 -> V_69 = V_69 ;
F_3 ( V_13 ) -> V_2 = NULL ;
F_3 ( V_13 ) -> V_87 = V_87 ;
if ( V_32 ) * V_32 = V_13 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_93 )
{
struct V_39 * V_13 ;
V_13 = NULL ;
if ( V_93 != - 1 ) V_13 = F_51 ( V_93 ) ;
if ( V_13 ) {
if ( V_13 -> V_96 != & V_95 ) {
F_52 ( V_13 ) ;
return - V_97 ;
}
if ( F_3 ( V_13 ) -> V_2 ) {
F_52 ( V_13 ) ;
return - V_66 ;
}
}
else {
int error ;
error = F_47 ( V_93 , 0 , & V_13 ) ;
if ( error ) return error ;
}
F_3 ( V_13 ) -> V_2 = V_2 ;
V_2 -> V_13 = & V_98 ;
F_53 ( F_12 ( V_2 ) ) ;
F_23 ( V_99 , & V_2 -> V_22 ) ;
F_23 ( V_34 , & V_2 -> V_22 ) ;
V_2 -> V_69 = V_13 ;
( void ) F_54 ( V_2 ) ;
V_2 -> V_77 = & V_98 . V_77 . V_100 ;
return V_13 -> V_101 ;
}
static int F_55 ( int V_93 )
{
return F_47 ( V_93 , 1 , NULL ) ;
}
static int F_56 ( int V_93 )
{
struct V_39 * V_13 ;
struct V_68 * V_69 ;
V_13 = F_51 ( V_93 ) ;
if ( ! V_13 ) return - V_102 ;
if ( V_13 -> V_96 != & V_95 ) {
F_52 ( V_13 ) ;
return - V_97 ;
}
V_69 = F_3 ( V_13 ) ;
if ( ! V_69 -> V_87 ) return 0 ;
V_69 -> V_87 = 0 ;
if ( F_3 ( V_13 ) -> V_2 ) return 0 ;
F_39 ( V_69 ) ;
F_52 ( V_13 ) ;
F_40 ( V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_103 * V_50 , unsigned int V_44 , unsigned long V_45 )
{
int V_104 = 0 ;
struct V_1 * V_2 = F_58 ( V_50 ) ;
if ( V_44 != V_105 && V_44 != V_106 && V_44 != V_107 )
return - V_54 ;
if ( ! F_59 ( V_108 ) )
return - V_109 ;
switch ( V_44 ) {
case V_105 :
V_104 = F_50 ( V_2 , ( int ) V_45 ) ;
if ( V_104 >= 0 ) {
V_50 -> V_110 = V_111 ;
F_60 ( V_89 ) ;
}
break;
case V_106 :
V_104 = F_55 ( ( int ) V_45 ) ;
break;
case V_107 :
V_104 = F_56 ( ( int ) V_45 ) ;
break;
}
return V_104 ;
}
static T_3 int F_61 ( void )
{
F_62 ( & V_112 ) ;
return 0 ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_112 ) ;
}
