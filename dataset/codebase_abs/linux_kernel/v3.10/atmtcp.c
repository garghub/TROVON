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
int V_50 ;
if ( V_44 != V_51 ) return - V_52 ;
if ( F_27 ( & V_47 , V_45 , sizeof( V_47 ) ) ) return - V_53 ;
if ( V_47 . V_54 == V_55 ) V_47 . V_54 = V_56 ;
if ( V_47 . V_57 == V_55 ) V_47 . V_57 = V_58 ;
if ( V_47 . V_54 > V_56 || V_47 . V_54 < 0 ||
V_47 . V_57 > V_58 || V_47 . V_57 < 0 ) return - V_38 ;
F_28 ( & V_59 ) ;
for( V_50 = 0 ; V_50 < V_60 ; ++ V_50 ) {
struct V_61 * V_62 = & V_63 [ V_50 ] ;
F_29 (s, head) {
V_2 = F_30 ( V_49 ) ;
if ( V_2 -> V_13 != V_13 )
continue;
if ( ( V_2 -> V_26 >> V_47 . V_54 ) ||
( V_2 -> V_29 >> V_47 . V_57 ) ) {
F_31 ( & V_59 ) ;
return - V_64 ;
}
}
}
F_31 ( & V_59 ) ;
V_13 -> V_65 = V_47 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_66 * V_67 ;
struct V_1 * V_8 = NULL ;
struct V_9 * V_68 ;
struct V_69 * V_18 ;
int V_70 ;
if ( V_2 -> V_30 . V_71 . V_72 == V_73 ) {
if ( V_2 -> V_74 ) V_2 -> V_74 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
return - V_38 ;
}
V_67 = F_3 ( V_2 -> V_13 ) ;
if ( V_67 ) V_8 = V_67 -> V_2 ;
if ( ! V_67 || ! V_8 ) {
if ( V_2 -> V_74 ) V_2 -> V_74 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
if ( V_67 ) return 0 ;
F_33 ( & V_2 -> V_75 -> V_76 ) ;
return - V_77 ;
}
V_70 = V_10 -> V_78 + sizeof( struct V_69 ) ;
V_68 = F_34 ( V_8 , V_70 , V_79 ) ;
if ( ! V_68 ) {
if ( V_2 -> V_74 ) V_2 -> V_74 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
F_33 ( & V_2 -> V_75 -> V_76 ) ;
return - V_80 ;
}
V_18 = ( void * ) F_8 ( V_68 , sizeof( struct V_69 ) ) ;
V_18 -> V_26 = F_22 ( V_2 -> V_26 ) ;
V_18 -> V_29 = F_22 ( V_2 -> V_29 ) ;
V_18 -> V_19 = F_35 ( V_10 -> V_78 ) ;
F_36 ( V_10 , F_8 ( V_68 , V_10 -> V_78 ) , V_10 -> V_78 ) ;
if ( V_2 -> V_74 ) V_2 -> V_74 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
V_8 -> V_23 ( V_8 , V_68 ) ;
F_33 ( & V_2 -> V_75 -> V_81 ) ;
F_33 ( & V_8 -> V_75 -> V_82 ) ;
return 0 ;
}
static int F_37 ( struct V_39 * V_13 , T_2 * V_83 , char * V_84 )
{
struct V_66 * V_67 = F_3 ( V_13 ) ;
if ( * V_83 ) return 0 ;
if ( ! V_67 -> V_85 ) return sprintf ( V_84 , L_2 ) ;
return sprintf ( V_84 , L_3 ,
V_67 -> V_2 ? L_4 : L_5 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_86 ;
struct V_66 * V_67 ;
V_86 = (struct V_39 * ) V_2 -> V_67 ;
V_67 = F_3 ( V_86 ) ;
V_67 -> V_2 = NULL ;
if ( V_67 -> V_85 ) return;
V_86 -> V_67 = NULL ;
F_39 ( V_67 ) ;
F_40 ( V_86 ) ;
V_2 -> V_67 = NULL ;
F_41 ( V_87 ) ;
}
static struct V_1 * F_42 ( struct V_39 * V_13 , short V_26 , int V_29 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
V_62 = & V_63 [ V_29 & ( V_60 - 1 ) ] ;
F_29 (s, head) {
V_2 = F_30 ( V_49 ) ;
if ( V_2 -> V_13 == V_13 &&
V_2 -> V_29 == V_29 && V_2 -> V_26 == V_26 &&
V_2 -> V_30 . V_88 . V_72 != V_73 ) {
return V_2 ;
}
}
return NULL ;
}
static int F_43 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_13 ;
struct V_69 * V_18 ;
struct V_1 * V_8 ;
struct V_9 * V_68 ;
int V_32 = 0 ;
if ( ! V_10 -> V_78 ) return 0 ;
V_13 = V_2 -> V_67 ;
V_18 = (struct V_69 * ) V_10 -> V_89 ;
if ( V_18 -> V_19 == V_20 ) {
V_32 = F_16 (
(struct V_3 * ) V_10 -> V_89 ) ;
goto V_90;
}
F_28 ( & V_59 ) ;
V_8 = F_42 ( V_13 , F_44 ( V_18 -> V_26 ) , F_44 ( V_18 -> V_29 ) ) ;
F_31 ( & V_59 ) ;
if ( ! V_8 ) {
F_33 ( & V_2 -> V_75 -> V_76 ) ;
goto V_90;
}
F_45 ( V_10 , sizeof( struct V_69 ) ) ;
V_68 = F_34 ( V_8 , V_10 -> V_78 , V_15 ) ;
if ( ! V_68 ) {
V_32 = - V_80 ;
goto V_90;
}
F_46 ( V_68 ) ;
F_36 ( V_10 , F_8 ( V_68 , V_10 -> V_78 ) , V_10 -> V_78 ) ;
V_8 -> V_23 ( V_8 , V_68 ) ;
F_33 ( & V_2 -> V_75 -> V_81 ) ;
F_33 ( & V_8 -> V_75 -> V_82 ) ;
V_90:
if ( V_2 -> V_74 ) V_2 -> V_74 ( V_2 , V_10 ) ;
else F_6 ( V_10 ) ;
return V_32 ;
}
static int F_47 ( int V_91 , int V_85 , struct V_39 * * V_32 )
{
struct V_66 * V_67 ;
struct V_39 * V_13 ;
V_67 = F_48 ( sizeof( * V_67 ) , V_15 ) ;
if ( ! V_67 )
return - V_16 ;
V_13 = F_49 ( V_92 , NULL , & V_93 , V_91 , NULL ) ;
if ( ! V_13 ) {
F_39 ( V_67 ) ;
return V_91 == - 1 ? - V_16 : - V_64 ;
}
V_13 -> V_65 . V_54 = V_56 ;
V_13 -> V_65 . V_57 = V_58 ;
V_13 -> V_67 = V_67 ;
F_3 ( V_13 ) -> V_2 = NULL ;
F_3 ( V_13 ) -> V_85 = V_85 ;
if ( V_32 ) * V_32 = V_13 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_91 )
{
struct V_39 * V_13 ;
V_13 = NULL ;
if ( V_91 != - 1 ) V_13 = F_51 ( V_91 ) ;
if ( V_13 ) {
if ( V_13 -> V_94 != & V_93 ) {
F_52 ( V_13 ) ;
return - V_95 ;
}
if ( F_3 ( V_13 ) -> V_2 ) {
F_52 ( V_13 ) ;
return - V_64 ;
}
}
else {
int error ;
error = F_47 ( V_91 , 0 , & V_13 ) ;
if ( error ) return error ;
}
F_3 ( V_13 ) -> V_2 = V_2 ;
V_2 -> V_13 = & V_96 ;
F_53 ( F_12 ( V_2 ) ) ;
F_23 ( V_97 , & V_2 -> V_22 ) ;
F_23 ( V_34 , & V_2 -> V_22 ) ;
V_2 -> V_67 = V_13 ;
( void ) F_54 ( V_2 ) ;
V_2 -> V_75 = & V_96 . V_75 . V_98 ;
return V_13 -> V_99 ;
}
static int F_55 ( int V_91 )
{
return F_47 ( V_91 , 1 , NULL ) ;
}
static int F_56 ( int V_91 )
{
struct V_39 * V_13 ;
struct V_66 * V_67 ;
V_13 = F_51 ( V_91 ) ;
if ( ! V_13 ) return - V_100 ;
if ( V_13 -> V_94 != & V_93 ) {
F_52 ( V_13 ) ;
return - V_95 ;
}
V_67 = F_3 ( V_13 ) ;
if ( ! V_67 -> V_85 ) return 0 ;
V_67 -> V_85 = 0 ;
if ( F_3 ( V_13 ) -> V_2 ) return 0 ;
F_39 ( V_67 ) ;
F_52 ( V_13 ) ;
F_40 ( V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_101 * V_48 , unsigned int V_44 , unsigned long V_45 )
{
int V_102 = 0 ;
struct V_1 * V_2 = F_58 ( V_48 ) ;
if ( V_44 != V_103 && V_44 != V_104 && V_44 != V_105 )
return - V_52 ;
if ( ! F_59 ( V_106 ) )
return - V_107 ;
switch ( V_44 ) {
case V_103 :
V_102 = F_50 ( V_2 , ( int ) V_45 ) ;
if ( V_102 >= 0 ) {
V_48 -> V_108 = V_109 ;
F_60 ( V_87 ) ;
}
break;
case V_104 :
V_102 = F_55 ( ( int ) V_45 ) ;
break;
case V_105 :
V_102 = F_56 ( ( int ) V_45 ) ;
break;
}
return V_102 ;
}
static T_3 int F_61 ( void )
{
F_62 ( & V_110 ) ;
return 0 ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_110 ) ;
}
