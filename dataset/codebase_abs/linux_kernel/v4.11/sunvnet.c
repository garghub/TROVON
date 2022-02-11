static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return V_10 -> V_11 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
V_10 -> V_11 = V_12 ;
}
static struct V_13 * F_6 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
unsigned int V_16 = F_7 ( V_15 -> V_17 ) ;
struct V_18 * V_19 = & V_10 -> V_20 [ V_16 ] ;
struct V_13 * V_21 ;
F_8 (port, hp, hash) {
if ( ! F_9 ( V_21 ) )
continue;
if ( F_10 ( V_21 -> V_22 , V_15 -> V_17 ) )
return V_21 ;
}
F_11 (port, &vp->port_list, list) {
if ( ! V_21 -> V_23 )
continue;
if ( ! F_9 ( V_21 ) )
continue;
return V_21 ;
}
return NULL ;
}
static struct V_13 * F_12 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_6 ( V_10 , V_15 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 , struct V_14 * V_15 ,
void * V_24 , T_3 V_25 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_13 * V_21 = F_6 ( V_10 , V_15 ) ;
if ( ! V_21 )
return 0 ;
return V_21 -> V_26 ;
}
static int F_14 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
return F_15 ( V_15 , V_2 , F_12 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_17 ( V_2 , V_10 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_19 ( V_2 , V_10 ) ;
}
static struct V_9 * F_20 ( const T_4 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_30 , V_31 ;
V_2 = F_21 ( sizeof( * V_10 ) , V_32 , 1 ) ;
if ( ! V_2 )
return F_22 ( - V_33 ) ;
V_2 -> V_34 = V_35 + 8 ;
V_2 -> V_36 = 8 ;
for ( V_31 = 0 ; V_31 < V_37 ; V_31 ++ )
V_2 -> V_38 [ V_31 ] = ( * V_27 >> ( 5 - V_31 ) * 8 ) & 0xff ;
V_10 = F_4 ( V_2 ) ;
F_23 ( & V_10 -> V_39 ) ;
V_10 -> V_2 = V_2 ;
F_24 ( & V_10 -> V_40 ) ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ )
F_25 ( & V_10 -> V_20 [ V_31 ] ) ;
F_24 ( & V_10 -> V_42 ) ;
V_10 -> V_27 = * V_27 ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 = & V_46 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = V_50 | V_51 | V_52 |
V_53 | V_54 ;
V_2 -> V_55 = V_2 -> V_49 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_59 ;
F_26 ( V_2 , & V_29 -> V_2 ) ;
V_30 = F_27 ( V_2 ) ;
if ( V_30 ) {
F_28 ( L_1 ) ;
goto V_60;
}
F_29 ( V_2 , L_2 , V_2 -> V_38 ) ;
F_30 ( & V_10 -> V_42 , & V_61 ) ;
return V_10 ;
V_60:
F_31 ( V_2 ) ;
return F_22 ( V_30 ) ;
}
static struct V_9 * F_32 ( const T_4 * V_27 ,
struct V_28 * V_29 )
{
struct V_9 * V_62 , * V_10 ;
F_33 ( & V_63 ) ;
V_10 = NULL ;
F_34 (iter, &vnet_list, list) {
if ( V_62 -> V_27 == * V_27 ) {
V_10 = V_62 ;
break;
}
}
if ( ! V_10 )
V_10 = F_20 ( V_27 , V_29 ) ;
F_35 ( & V_63 ) ;
return V_10 ;
}
static void F_36 ( void )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_33 ( & V_63 ) ;
while ( ! F_37 ( & V_61 ) ) {
V_10 = F_38 ( & V_61 , struct V_9 , V_42 ) ;
F_39 ( & V_10 -> V_42 ) ;
V_2 = V_10 -> V_2 ;
F_40 ( ! F_37 ( & V_10 -> V_40 ) ) ;
F_41 ( V_2 ) ;
F_31 ( V_2 ) ;
}
F_35 ( & V_63 ) ;
}
static struct V_9 * F_42 ( struct V_64 * V_19 ,
T_4 V_65 ,
struct V_28 * V_29 )
{
const T_4 * V_27 = NULL ;
T_4 V_66 ;
F_43 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
T_4 V_67 = F_44 ( V_19 , V_66 ) ;
const char * V_68 ;
V_68 = F_45 ( V_19 , V_67 , L_3 , NULL ) ;
if ( ! V_68 || strcmp ( V_68 , L_4 ) )
continue;
V_27 = F_45 ( V_19 , V_67 ,
V_69 , NULL ) ;
if ( V_27 )
break;
}
if ( ! V_27 )
return F_22 ( - V_70 ) ;
return F_32 ( V_27 , V_29 ) ;
}
static int F_46 ( struct V_28 * V_29 , const struct V_71 * V_72 )
{
struct V_64 * V_19 ;
struct V_13 * V_21 ;
unsigned long V_73 ;
struct V_9 * V_10 ;
const T_4 * V_74 ;
int V_75 , V_31 , V_30 , V_23 ;
V_19 = F_47 () ;
V_10 = F_42 ( V_19 , V_29 -> V_76 , V_29 ) ;
if ( F_48 ( V_10 ) ) {
F_28 ( L_5 ) ;
V_30 = F_49 ( V_10 ) ;
goto V_77;
}
V_74 = F_45 ( V_19 , V_29 -> V_76 , V_78 , & V_75 ) ;
V_30 = - V_70 ;
if ( ! V_74 ) {
F_28 ( L_6 , V_78 ) ;
goto V_77;
}
V_21 = F_50 ( sizeof( * V_21 ) , V_79 ) ;
V_30 = - V_33 ;
if ( ! V_21 )
goto V_77;
for ( V_31 = 0 ; V_31 < V_37 ; V_31 ++ )
V_21 -> V_22 [ V_31 ] = ( * V_74 >> ( 5 - V_31 ) * 8 ) & 0xff ;
V_21 -> V_10 = V_10 ;
V_30 = F_51 ( & V_21 -> V_80 , V_29 , V_81 ,
V_82 , F_52 ( V_82 ) ,
& V_83 , V_10 -> V_2 -> V_68 ) ;
if ( V_30 )
goto V_84;
V_30 = F_53 ( & V_21 -> V_80 , & V_85 , V_21 ) ;
if ( V_30 )
goto V_84;
F_54 ( V_21 -> V_10 -> V_2 , & V_21 -> V_86 , V_87 ,
V_88 ) ;
F_55 ( & V_21 -> V_16 ) ;
F_24 ( & V_21 -> V_42 ) ;
V_23 = 0 ;
if ( F_45 ( V_19 , V_29 -> V_76 , L_7 , NULL ) )
V_23 = 1 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_89 = true ;
V_21 -> V_90 = 0 ;
F_56 ( & V_10 -> V_39 , V_73 ) ;
if ( V_23 )
F_57 ( & V_21 -> V_42 , & V_10 -> V_40 ) ;
else
F_58 ( & V_21 -> V_42 , & V_10 -> V_40 ) ;
F_59 ( & V_21 -> V_16 ,
& V_10 -> V_20 [ F_7 ( V_21 -> V_22 ) ] ) ;
F_60 ( V_21 ) ;
F_61 ( & V_10 -> V_39 , V_73 ) ;
F_62 ( & V_29 -> V_2 , V_21 ) ;
F_63 ( L_8 ,
V_10 -> V_2 -> V_68 , V_21 -> V_22 , V_23 ? L_9 : L_10 ) ;
F_64 ( & V_21 -> V_91 , V_92 ,
( unsigned long ) V_21 ) ;
F_65 ( & V_21 -> V_86 ) ;
F_66 ( & V_21 -> V_80 ) ;
F_67 ( V_19 ) ;
return 0 ;
V_84:
F_68 ( V_21 ) ;
V_77:
F_67 ( V_19 ) ;
return V_30 ;
}
static int F_69 ( struct V_28 * V_29 )
{
struct V_13 * V_21 = F_70 ( & V_29 -> V_2 ) ;
if ( V_21 ) {
F_71 ( & V_21 -> V_80 . V_93 ) ;
F_72 ( & V_21 -> V_86 ) ;
F_73 ( & V_21 -> V_42 ) ;
F_74 ( & V_21 -> V_16 ) ;
F_75 () ;
F_71 ( & V_21 -> V_91 ) ;
F_76 ( V_21 ) ;
F_77 ( & V_21 -> V_86 ) ;
F_78 ( V_21 ) ;
F_79 ( & V_21 -> V_80 ) ;
F_62 ( & V_29 -> V_2 , NULL ) ;
F_68 ( V_21 ) ;
}
return 0 ;
}
static int T_5 F_80 ( void )
{
F_63 ( L_11 , V_7 ) ;
return F_81 ( & V_94 ) ;
}
static void T_6 F_82 ( void )
{
F_83 ( & V_94 ) ;
F_36 () ;
}
