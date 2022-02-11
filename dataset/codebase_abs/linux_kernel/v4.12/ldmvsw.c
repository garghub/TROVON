static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return V_10 -> V_11 -> V_12 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_10 -> V_11 -> V_12 = V_13 ;
}
static struct V_9 * F_6 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return V_10 ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_14 * V_15 ,
void * V_16 , T_3 V_17 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( ! V_10 )
return 0 ;
return V_10 -> V_18 ;
}
static int F_8 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
return F_9 ( V_15 , V_2 , F_6 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_11 ( V_2 , V_10 -> V_11 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_19 * V_20 = & V_10 -> V_20 ;
F_13 ( V_20 , V_21 ) ;
F_14 ( V_10 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_17 ( V_2 , V_10 -> V_11 ) ;
}
static struct V_22 * F_18 ( struct V_23 * V_24 ,
T_4 V_25 ,
T_4 * V_26 )
{
struct V_22 * V_11 ;
struct V_22 * V_27 ;
const T_4 * V_28 = NULL ;
const T_4 * V_29 = NULL ;
T_4 V_30 ;
F_19 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
T_4 V_31 = F_20 ( V_24 , V_30 ) ;
const char * V_32 ;
V_32 = F_21 ( V_24 , V_31 , L_1 , NULL ) ;
if ( ! V_32 || strcmp ( V_32 , L_2 ) )
continue;
V_28 = F_21 ( V_24 , V_31 ,
V_33 , NULL ) ;
V_29 = F_21 ( V_24 , V_31 ,
V_34 , NULL ) ;
break;
}
if ( ! V_28 || ! V_29 )
return F_22 ( - V_35 ) ;
V_11 = NULL ;
F_23 ( & V_36 ) ;
F_24 (iter, &vnet_list, list) {
if ( V_27 -> V_28 == * V_28 ) {
V_11 = V_27 ;
break;
}
}
if ( ! V_11 ) {
V_11 = F_25 ( sizeof( * V_11 ) , V_37 ) ;
if ( F_26 ( ! V_11 ) ) {
F_27 ( & V_36 ) ;
return F_22 ( - V_38 ) ;
}
F_28 ( & V_11 -> V_39 ) ;
F_29 ( & V_11 -> V_40 ) ;
F_29 ( & V_11 -> V_41 ) ;
V_11 -> V_28 = * V_28 ;
F_30 ( & V_11 -> V_41 , & V_42 ) ;
}
F_27 ( & V_36 ) ;
* V_26 = ( T_4 ) * V_29 ;
return V_11 ;
}
static struct V_1 * F_31 ( T_5 V_43 [] ,
struct V_44 * V_45 ,
T_4 V_26 ,
T_4 V_46 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_47 ;
V_2 = F_32 ( sizeof( * V_10 ) , V_48 , 1 ) ;
if ( ! V_2 )
return F_22 ( - V_38 ) ;
V_2 -> V_49 = V_50 + 8 ;
V_2 -> V_51 = 8 ;
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ ) {
V_2 -> V_53 [ V_47 ] = V_43 [ V_47 ] ;
V_2 -> V_54 [ V_47 ] = V_2 -> V_53 [ V_47 ] ;
}
sprintf ( V_2 -> V_32 , L_3 , ( int ) V_26 , ( int ) V_46 ) ;
V_2 -> V_55 = & V_56 ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = V_62 | V_63 ;
V_2 -> V_64 = V_2 -> V_61 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = V_68 ;
F_33 ( V_2 , & V_45 -> V_2 ) ;
return V_2 ;
}
static int F_34 ( struct V_44 * V_45 , const struct V_69 * V_70 )
{
struct V_23 * V_24 ;
struct V_9 * V_10 ;
unsigned long V_71 ;
struct V_22 * V_11 ;
struct V_1 * V_2 ;
const T_4 * V_72 ;
int V_73 , V_47 , V_74 ;
const T_4 * V_46 ;
T_4 V_26 ;
V_24 = F_35 () ;
V_72 = F_21 ( V_24 , V_45 -> V_75 , V_76 , & V_73 ) ;
V_74 = - V_35 ;
if ( ! V_72 ) {
F_36 ( L_4 , V_76 ) ;
F_37 ( V_24 ) ;
return V_74 ;
}
V_46 = F_21 ( V_24 , V_45 -> V_75 , V_77 , NULL ) ;
V_74 = - V_35 ;
if ( ! V_46 ) {
F_36 ( L_4 , V_77 ) ;
F_37 ( V_24 ) ;
return V_74 ;
}
V_11 = F_18 ( V_24 , V_45 -> V_75 , & V_26 ) ;
if ( F_26 ( F_38 ( V_11 ) ) ) {
V_74 = F_39 ( V_11 ) ;
F_36 ( L_5 ) ;
F_37 ( V_24 ) ;
return V_74 ;
}
F_37 ( V_24 ) ;
V_2 = F_31 ( V_78 , V_45 , V_26 , * V_46 ) ;
if ( F_38 ( V_2 ) ) {
V_74 = F_39 ( V_2 ) ;
F_36 ( L_6 ) ;
return V_74 ;
}
V_10 = F_4 ( V_2 ) ;
F_29 ( & V_10 -> V_41 ) ;
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ )
V_10 -> V_79 [ V_47 ] = ( * V_72 >> ( 5 - V_47 ) * 8 ) & 0xff ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_80 = 1 ;
V_10 -> V_81 = false ;
V_10 -> V_82 = 0 ;
V_10 -> V_83 = 1 ;
V_74 = F_40 ( & V_10 -> V_20 , V_45 , V_84 ,
V_85 , F_41 ( V_85 ) ,
& V_86 , V_2 -> V_32 ) ;
if ( V_74 )
goto V_87;
V_74 = F_42 ( & V_10 -> V_20 , & V_88 , V_10 ) ;
if ( V_74 )
goto V_87;
F_43 ( & V_45 -> V_2 , V_10 ) ;
F_44 ( V_2 , & V_10 -> V_89 , V_90 ,
V_91 ) ;
F_45 ( & V_11 -> V_39 , V_71 ) ;
F_46 ( & V_10 -> V_41 , & V_11 -> V_40 ) ;
F_47 ( & V_11 -> V_39 , V_71 ) ;
F_48 ( & V_10 -> V_92 , V_93 ,
( unsigned long ) V_10 ) ;
V_74 = F_49 ( V_2 ) ;
if ( V_74 ) {
F_36 ( L_7 ) ;
goto V_94;
}
F_45 ( & V_11 -> V_39 , V_71 ) ;
F_50 ( V_10 ) ;
F_47 ( & V_11 -> V_39 , V_71 ) ;
F_51 ( & V_10 -> V_89 ) ;
F_15 ( & V_10 -> V_20 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 , L_8 , V_2 -> V_53 ) ;
F_54 ( L_9 , V_2 -> V_32 ,
V_10 -> V_79 , L_10 ) ;
return 0 ;
V_94:
F_55 ( & V_10 -> V_92 ) ;
F_56 ( & V_10 -> V_41 ) ;
F_57 () ;
F_58 ( & V_10 -> V_89 ) ;
F_43 ( & V_45 -> V_2 , NULL ) ;
F_59 ( & V_10 -> V_20 ) ;
V_87:
F_60 ( V_2 ) ;
return V_74 ;
}
static int F_61 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = F_62 ( & V_45 -> V_2 ) ;
unsigned long V_71 ;
if ( V_10 ) {
F_55 ( & V_10 -> V_20 . V_95 ) ;
F_55 ( & V_10 -> V_92 ) ;
F_63 ( & V_10 -> V_89 ) ;
F_64 ( V_10 -> V_2 ) ;
F_56 ( & V_10 -> V_41 ) ;
F_57 () ;
F_45 ( & V_10 -> V_11 -> V_39 , V_71 ) ;
F_65 ( V_10 ) ;
F_47 ( & V_10 -> V_11 -> V_39 , V_71 ) ;
F_58 ( & V_10 -> V_89 ) ;
F_66 ( V_10 ) ;
F_59 ( & V_10 -> V_20 ) ;
F_43 ( & V_45 -> V_2 , NULL ) ;
F_60 ( V_10 -> V_2 ) ;
}
return 0 ;
}
static void F_67 ( void )
{
struct V_22 * V_11 ;
F_23 ( & V_36 ) ;
while ( ! F_68 ( & V_42 ) ) {
V_11 = F_69 ( & V_42 , struct V_22 , V_41 ) ;
F_70 ( & V_11 -> V_41 ) ;
if ( ! F_68 ( & V_11 -> V_40 ) )
F_36 ( L_11 ) ;
F_71 ( V_11 ) ;
}
F_27 ( & V_36 ) ;
}
static int T_6 F_72 ( void )
{
F_54 ( L_12 , V_7 ) ;
return F_73 ( & V_96 ) ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_96 ) ;
F_67 () ;
}
