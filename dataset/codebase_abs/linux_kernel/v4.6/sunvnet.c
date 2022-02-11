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
F_26 ( V_2 , & V_29 -> V_2 ) ;
V_30 = F_27 ( V_2 ) ;
if ( V_30 ) {
F_28 ( L_1 ) ;
goto V_56;
}
F_29 ( V_2 , L_2 , V_2 -> V_38 ) ;
F_30 ( & V_10 -> V_42 , & V_57 ) ;
return V_10 ;
V_56:
F_31 ( V_2 ) ;
return F_22 ( V_30 ) ;
}
static struct V_9 * F_32 ( const T_4 * V_27 ,
struct V_28 * V_29 )
{
struct V_9 * V_58 , * V_10 ;
F_33 ( & V_59 ) ;
V_10 = NULL ;
F_34 (iter, &vnet_list, list) {
if ( V_58 -> V_27 == * V_27 ) {
V_10 = V_58 ;
break;
}
}
if ( ! V_10 )
V_10 = F_20 ( V_27 , V_29 ) ;
F_35 ( & V_59 ) ;
return V_10 ;
}
static void F_36 ( void )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_33 ( & V_59 ) ;
while ( ! F_37 ( & V_57 ) ) {
V_10 = F_38 ( & V_57 , struct V_9 , V_42 ) ;
F_39 ( & V_10 -> V_42 ) ;
V_2 = V_10 -> V_2 ;
F_40 ( ! F_37 ( & V_10 -> V_40 ) ) ;
F_41 ( V_2 ) ;
F_31 ( V_2 ) ;
}
F_35 ( & V_59 ) ;
}
static struct V_9 * F_42 ( struct V_60 * V_19 ,
T_4 V_61 ,
struct V_28 * V_29 )
{
const T_4 * V_27 = NULL ;
T_4 V_62 ;
F_43 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
T_4 V_63 = F_44 ( V_19 , V_62 ) ;
const char * V_64 ;
V_64 = F_45 ( V_19 , V_63 , L_3 , NULL ) ;
if ( ! V_64 || strcmp ( V_64 , L_4 ) )
continue;
V_27 = F_45 ( V_19 , V_63 ,
V_65 , NULL ) ;
if ( V_27 )
break;
}
if ( ! V_27 )
return F_22 ( - V_66 ) ;
return F_32 ( V_27 , V_29 ) ;
}
static void F_46 ( void )
{
F_47 ( V_67 L_5 , V_7 ) ;
}
static int F_48 ( struct V_28 * V_29 , const struct V_68 * V_69 )
{
struct V_60 * V_19 ;
struct V_13 * V_21 ;
unsigned long V_70 ;
struct V_9 * V_10 ;
const T_4 * V_71 ;
int V_72 , V_31 , V_30 , V_23 ;
F_46 () ;
V_19 = F_49 () ;
V_10 = F_42 ( V_19 , V_29 -> V_73 , V_29 ) ;
if ( F_50 ( V_10 ) ) {
F_28 ( L_6 ) ;
V_30 = F_51 ( V_10 ) ;
goto V_74;
}
V_71 = F_45 ( V_19 , V_29 -> V_73 , V_75 , & V_72 ) ;
V_30 = - V_66 ;
if ( ! V_71 ) {
F_28 ( L_7 , V_75 ) ;
goto V_74;
}
V_21 = F_52 ( sizeof( * V_21 ) , V_76 ) ;
V_30 = - V_33 ;
if ( ! V_21 )
goto V_74;
for ( V_31 = 0 ; V_31 < V_37 ; V_31 ++ )
V_21 -> V_22 [ V_31 ] = ( * V_71 >> ( 5 - V_31 ) * 8 ) & 0xff ;
V_21 -> V_10 = V_10 ;
V_30 = F_53 ( & V_21 -> V_77 , V_29 , V_78 ,
V_79 , F_54 ( V_79 ) ,
& V_80 , V_10 -> V_2 -> V_64 ) ;
if ( V_30 )
goto V_81;
V_30 = F_55 ( & V_21 -> V_77 , & V_82 , V_21 ) ;
if ( V_30 )
goto V_81;
F_56 ( V_21 -> V_10 -> V_2 , & V_21 -> V_83 , V_84 ,
V_85 ) ;
F_57 ( & V_21 -> V_16 ) ;
F_24 ( & V_21 -> V_42 ) ;
V_23 = 0 ;
if ( F_45 ( V_19 , V_29 -> V_73 , L_8 , NULL ) )
V_23 = 1 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_86 = true ;
V_21 -> V_87 = 0 ;
F_58 ( & V_10 -> V_39 , V_70 ) ;
if ( V_23 )
F_59 ( & V_21 -> V_42 , & V_10 -> V_40 ) ;
else
F_60 ( & V_21 -> V_42 , & V_10 -> V_40 ) ;
F_61 ( & V_21 -> V_16 ,
& V_10 -> V_20 [ F_7 ( V_21 -> V_22 ) ] ) ;
F_62 ( V_21 ) ;
F_63 ( & V_10 -> V_39 , V_70 ) ;
F_64 ( & V_29 -> V_2 , V_21 ) ;
F_65 ( L_9 ,
V_10 -> V_2 -> V_64 , V_21 -> V_22 , V_23 ? L_10 : L_11 ) ;
F_66 ( & V_21 -> V_88 , V_89 ,
( unsigned long ) V_21 ) ;
F_67 ( & V_21 -> V_83 ) ;
F_68 ( & V_21 -> V_77 ) ;
F_69 ( V_19 ) ;
return 0 ;
V_81:
F_70 ( V_21 ) ;
V_74:
F_69 ( V_19 ) ;
return V_30 ;
}
static int F_71 ( struct V_28 * V_29 )
{
struct V_13 * V_21 = F_72 ( & V_29 -> V_2 ) ;
if ( V_21 ) {
F_73 ( & V_21 -> V_77 . V_90 ) ;
F_74 ( & V_21 -> V_83 ) ;
F_75 ( & V_21 -> V_42 ) ;
F_76 ( & V_21 -> V_16 ) ;
F_77 () ;
F_73 ( & V_21 -> V_88 ) ;
F_78 ( V_21 ) ;
F_79 ( & V_21 -> V_83 ) ;
F_80 ( V_21 ) ;
F_81 ( & V_21 -> V_77 ) ;
F_64 ( & V_29 -> V_2 , NULL ) ;
F_70 ( V_21 ) ;
}
return 0 ;
}
static int T_5 F_82 ( void )
{
return F_83 ( & V_91 ) ;
}
static void T_6 F_84 ( void )
{
F_85 ( & V_91 ) ;
F_36 () ;
}
