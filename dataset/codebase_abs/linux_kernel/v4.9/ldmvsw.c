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
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_13 ( V_2 , V_10 -> V_11 ) ;
}
static struct V_19 * F_14 ( struct V_20 * V_21 ,
T_4 V_22 ,
T_4 * V_23 )
{
struct V_19 * V_11 ;
struct V_19 * V_24 ;
const T_4 * V_25 = NULL ;
const T_4 * V_26 = NULL ;
T_4 V_27 ;
F_15 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
T_4 V_28 = F_16 ( V_21 , V_27 ) ;
const char * V_29 ;
V_29 = F_17 ( V_21 , V_28 , L_1 , NULL ) ;
if ( ! V_29 || strcmp ( V_29 , L_2 ) )
continue;
V_25 = F_17 ( V_21 , V_28 ,
V_30 , NULL ) ;
V_26 = F_17 ( V_21 , V_28 ,
V_31 , NULL ) ;
break;
}
if ( ! V_25 || ! V_26 )
return F_18 ( - V_32 ) ;
V_11 = NULL ;
F_19 ( & V_33 ) ;
F_20 (iter, &vnet_list, list) {
if ( V_24 -> V_25 == * V_25 ) {
V_11 = V_24 ;
break;
}
}
if ( ! V_11 ) {
V_11 = F_21 ( sizeof( * V_11 ) , V_34 ) ;
if ( F_22 ( ! V_11 ) ) {
F_23 ( & V_33 ) ;
return F_18 ( - V_35 ) ;
}
F_24 ( & V_11 -> V_36 ) ;
F_25 ( & V_11 -> V_37 ) ;
F_25 ( & V_11 -> V_38 ) ;
V_11 -> V_25 = * V_25 ;
F_26 ( & V_11 -> V_38 , & V_39 ) ;
}
F_23 ( & V_33 ) ;
* V_23 = ( T_4 ) * V_26 ;
return V_11 ;
}
static struct V_1 * F_27 ( T_5 V_40 [] ,
struct V_41 * V_42 ,
T_4 V_23 ,
T_4 V_43 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_44 ;
V_2 = F_28 ( sizeof( * V_10 ) , V_45 , 1 ) ;
if ( ! V_2 )
return F_18 ( - V_35 ) ;
V_2 -> V_46 = V_47 + 8 ;
V_2 -> V_48 = 8 ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ ) {
V_2 -> V_50 [ V_44 ] = V_40 [ V_44 ] ;
V_2 -> V_51 [ V_44 ] = V_2 -> V_50 [ V_44 ] ;
}
sprintf ( V_2 -> V_29 , L_3 , ( int ) V_23 , ( int ) V_43 ) ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_59 | V_60 | V_61 |
V_62 | V_63 ;
V_2 -> V_64 = V_2 -> V_58 ;
F_29 ( V_2 , & V_42 -> V_2 ) ;
return V_2 ;
}
static void F_30 ( void )
{
F_31 ( V_65 L_4 , V_7 ) ;
}
static int F_32 ( struct V_41 * V_42 , const struct V_66 * V_67 )
{
struct V_20 * V_21 ;
struct V_9 * V_10 ;
unsigned long V_68 ;
struct V_19 * V_11 ;
struct V_1 * V_2 ;
const T_4 * V_69 ;
int V_70 , V_44 , V_71 ;
const T_4 * V_43 ;
T_4 V_23 ;
F_30 () ;
V_21 = F_33 () ;
V_69 = F_17 ( V_21 , V_42 -> V_72 , V_73 , & V_70 ) ;
V_71 = - V_32 ;
if ( ! V_69 ) {
F_34 ( L_5 , V_73 ) ;
F_35 ( V_21 ) ;
return V_71 ;
}
V_43 = F_17 ( V_21 , V_42 -> V_72 , V_74 , NULL ) ;
V_71 = - V_32 ;
if ( ! V_43 ) {
F_34 ( L_5 , V_74 ) ;
F_35 ( V_21 ) ;
return V_71 ;
}
V_11 = F_14 ( V_21 , V_42 -> V_72 , & V_23 ) ;
if ( F_22 ( F_36 ( V_11 ) ) ) {
V_71 = F_37 ( V_11 ) ;
F_34 ( L_6 ) ;
F_35 ( V_21 ) ;
return V_71 ;
}
F_35 ( V_21 ) ;
V_2 = F_27 ( V_75 , V_42 , V_23 , * V_43 ) ;
if ( F_36 ( V_2 ) ) {
V_71 = F_37 ( V_2 ) ;
F_34 ( L_7 ) ;
return V_71 ;
}
V_10 = F_4 ( V_2 ) ;
F_25 ( & V_10 -> V_38 ) ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ )
V_10 -> V_76 [ V_44 ] = ( * V_69 >> ( 5 - V_44 ) * 8 ) & 0xff ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_77 = 1 ;
V_10 -> V_78 = true ;
V_10 -> V_79 = 0 ;
V_10 -> V_80 = 1 ;
V_71 = F_38 ( & V_10 -> V_81 , V_42 , V_82 ,
V_83 , F_39 ( V_83 ) ,
& V_84 , V_2 -> V_29 ) ;
if ( V_71 )
goto V_85;
V_71 = F_40 ( & V_10 -> V_81 , & V_86 , V_10 ) ;
if ( V_71 )
goto V_85;
F_41 ( & V_42 -> V_2 , V_10 ) ;
F_42 ( V_2 , & V_10 -> V_87 , V_88 ,
V_89 ) ;
F_43 ( & V_11 -> V_36 , V_68 ) ;
F_44 ( & V_10 -> V_38 , & V_11 -> V_37 ) ;
F_45 ( & V_11 -> V_36 , V_68 ) ;
F_46 ( & V_10 -> V_90 , V_91 ,
( unsigned long ) V_10 ) ;
V_71 = F_47 ( V_2 ) ;
if ( V_71 ) {
F_34 ( L_8 ) ;
goto V_92;
}
F_43 ( & V_11 -> V_36 , V_68 ) ;
F_48 ( V_10 ) ;
F_45 ( & V_11 -> V_36 , V_68 ) ;
F_49 ( & V_10 -> V_87 ) ;
F_50 ( & V_10 -> V_81 ) ;
F_51 ( V_2 , L_9 , V_2 -> V_50 ) ;
F_52 ( L_10 , V_2 -> V_29 ,
V_10 -> V_76 , L_11 ) ;
return 0 ;
V_92:
F_53 ( & V_10 -> V_90 ) ;
F_54 ( & V_10 -> V_38 ) ;
F_55 () ;
F_56 ( & V_10 -> V_87 ) ;
F_41 ( & V_42 -> V_2 , NULL ) ;
F_57 ( & V_10 -> V_81 ) ;
V_85:
F_58 ( V_2 ) ;
return V_71 ;
}
static int F_59 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_60 ( & V_42 -> V_2 ) ;
unsigned long V_68 ;
if ( V_10 ) {
F_53 ( & V_10 -> V_81 . V_93 ) ;
F_61 ( & V_10 -> V_87 ) ;
F_54 ( & V_10 -> V_38 ) ;
F_55 () ;
F_53 ( & V_10 -> V_90 ) ;
F_43 ( & V_10 -> V_11 -> V_36 , V_68 ) ;
F_62 ( V_10 ) ;
F_45 ( & V_10 -> V_11 -> V_36 , V_68 ) ;
F_56 ( & V_10 -> V_87 ) ;
F_63 ( V_10 ) ;
F_57 ( & V_10 -> V_81 ) ;
F_41 ( & V_42 -> V_2 , NULL ) ;
F_64 ( V_10 -> V_2 ) ;
F_58 ( V_10 -> V_2 ) ;
}
return 0 ;
}
static void F_65 ( void )
{
struct V_19 * V_11 ;
F_19 ( & V_33 ) ;
while ( ! F_66 ( & V_39 ) ) {
V_11 = F_67 ( & V_39 , struct V_19 , V_38 ) ;
F_68 ( & V_11 -> V_38 ) ;
if ( ! F_66 ( & V_11 -> V_37 ) )
F_34 ( L_12 ) ;
F_69 ( V_11 ) ;
}
F_23 ( & V_33 ) ;
}
static int T_6 F_70 ( void )
{
return F_71 ( & V_94 ) ;
}
static void T_7 F_72 ( void )
{
F_73 ( & V_94 ) ;
F_65 () ;
}
