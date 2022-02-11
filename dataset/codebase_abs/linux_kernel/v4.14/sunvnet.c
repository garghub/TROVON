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
static int F_6 ( struct V_1 * V_2 , int V_13 )
{
struct V_9 * V_10 = (struct V_9 * ) F_4 ( V_2 ) ;
switch ( V_13 ) {
case V_14 :
return F_7 ( V_15 )
+ ( V_16 * V_10 -> V_17 ) ;
default:
return - V_18 ;
}
}
static void F_8 ( struct V_1 * V_2 , T_1 V_19 , T_2 * V_20 )
{
struct V_9 * V_10 = (struct V_9 * ) F_4 ( V_2 ) ;
struct V_21 * V_22 ;
char * V_23 = ( char * ) V_20 ;
switch ( V_19 ) {
case V_14 :
memcpy ( V_20 , & V_15 , sizeof( V_15 ) ) ;
V_23 += sizeof( V_15 ) ;
F_9 () ;
F_10 (port, &vp->port_list, list) {
snprintf ( V_23 , V_24 , L_1 ,
V_22 -> V_25 , V_22 -> V_26 ? L_2 : L_3 ,
V_22 -> V_27 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_4 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_5 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_6 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_7 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_8 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
snprintf ( V_23 , V_24 , L_9 ,
V_22 -> V_25 ) ;
V_23 += V_24 ;
}
F_11 () ;
break;
default:
F_12 ( 1 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_28 * V_29 , T_3 * V_30 )
{
struct V_9 * V_10 = (struct V_9 * ) F_4 ( V_2 ) ;
struct V_21 * V_22 ;
int V_31 = 0 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_33 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_34 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_35 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_36 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_37 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_38 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_39 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_40 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_41 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_42 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_43 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_44 ;
V_30 [ V_31 ++ ] = V_2 -> V_32 . V_45 ;
V_30 [ V_31 ++ ] = V_10 -> V_17 ;
F_9 () ;
F_10 (port, &vp->port_list, list) {
V_30 [ V_31 ++ ] = V_22 -> V_25 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_33 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_34 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_35 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_36 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_46 ;
V_30 [ V_31 ++ ] = V_22 -> V_32 . V_47 ;
}
F_11 () ;
}
static struct V_21 * F_14 ( struct V_9 * V_10 , struct V_48 * V_49 )
{
unsigned int V_50 = F_15 ( V_49 -> V_30 ) ;
struct V_51 * V_52 = & V_10 -> V_53 [ V_50 ] ;
struct V_21 * V_22 ;
F_16 (port, hp, hash) {
if ( ! F_17 ( V_22 ) )
continue;
if ( F_18 ( V_22 -> V_27 , V_49 -> V_30 ) )
return V_22 ;
}
F_10 (port, &vp->port_list, list) {
if ( ! V_22 -> V_26 )
continue;
if ( ! F_17 ( V_22 ) )
continue;
return V_22 ;
}
return NULL ;
}
static struct V_21 * F_19 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_14 ( V_10 , V_49 ) ;
}
static T_4 F_20 ( struct V_1 * V_2 , struct V_48 * V_49 ,
void * V_54 , T_5 V_55 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_21 * V_22 = F_14 ( V_10 , V_49 ) ;
if ( ! V_22 )
return 0 ;
return V_22 -> V_25 ;
}
static int F_21 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
return F_22 ( V_49 , V_2 , F_19 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_24 ( V_2 , V_10 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
return F_26 ( V_2 , V_10 ) ;
}
static struct V_9 * F_27 ( const T_3 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_59 , V_31 ;
V_2 = F_28 ( sizeof( * V_10 ) , V_60 , 1 ) ;
if ( ! V_2 )
return F_29 ( - V_61 ) ;
V_2 -> V_62 = V_63 + 8 ;
V_2 -> V_64 = 8 ;
for ( V_31 = 0 ; V_31 < V_65 ; V_31 ++ )
V_2 -> V_66 [ V_31 ] = ( * V_56 >> ( 5 - V_31 ) * 8 ) & 0xff ;
V_10 = F_4 ( V_2 ) ;
F_30 ( & V_10 -> V_67 ) ;
V_10 -> V_2 = V_2 ;
F_31 ( & V_10 -> V_68 ) ;
for ( V_31 = 0 ; V_31 < V_69 ; V_31 ++ )
F_32 ( & V_10 -> V_53 [ V_31 ] ) ;
F_31 ( & V_10 -> V_70 ) ;
V_10 -> V_56 = * V_56 ;
V_2 -> V_71 = & V_72 ;
V_2 -> V_73 = & V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 | V_79 | V_80 |
V_81 | V_82 ;
V_2 -> V_83 = V_2 -> V_77 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_87 ;
F_33 ( V_2 , & V_58 -> V_2 ) ;
V_59 = F_34 ( V_2 ) ;
if ( V_59 ) {
F_35 ( L_10 ) ;
goto V_88;
}
F_36 ( V_2 , L_11 , V_2 -> V_66 ) ;
F_37 ( & V_10 -> V_70 , & V_89 ) ;
return V_10 ;
V_88:
F_38 ( V_2 ) ;
return F_29 ( V_59 ) ;
}
static struct V_9 * F_39 ( const T_3 * V_56 ,
struct V_57 * V_58 )
{
struct V_9 * V_90 , * V_10 ;
F_40 ( & V_91 ) ;
V_10 = NULL ;
F_41 (iter, &vnet_list, list) {
if ( V_90 -> V_56 == * V_56 ) {
V_10 = V_90 ;
break;
}
}
if ( ! V_10 )
V_10 = F_27 ( V_56 , V_58 ) ;
F_42 ( & V_91 ) ;
return V_10 ;
}
static void F_43 ( void )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_40 ( & V_91 ) ;
while ( ! F_44 ( & V_89 ) ) {
V_10 = F_45 ( & V_89 , struct V_9 , V_70 ) ;
F_46 ( & V_10 -> V_70 ) ;
V_2 = V_10 -> V_2 ;
F_47 ( ! F_44 ( & V_10 -> V_68 ) ) ;
F_48 ( V_2 ) ;
F_38 ( V_2 ) ;
}
F_42 ( & V_91 ) ;
}
static struct V_9 * F_49 ( struct V_92 * V_52 ,
T_3 V_93 ,
struct V_57 * V_58 )
{
const T_3 * V_56 = NULL ;
T_3 V_94 ;
F_50 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
T_3 V_95 = F_51 ( V_52 , V_94 ) ;
const char * V_96 ;
V_96 = F_52 ( V_52 , V_95 , L_12 , NULL ) ;
if ( ! V_96 || strcmp ( V_96 , L_13 ) )
continue;
V_56 = F_52 ( V_52 , V_95 ,
V_97 , NULL ) ;
if ( V_56 )
break;
}
if ( ! V_56 )
return F_29 ( - V_98 ) ;
return F_39 ( V_56 , V_58 ) ;
}
static int F_53 ( struct V_57 * V_58 , const struct V_99 * V_100 )
{
struct V_92 * V_52 ;
struct V_21 * V_22 ;
unsigned long V_101 ;
struct V_9 * V_10 ;
const T_3 * V_102 ;
int V_103 , V_31 , V_59 , V_26 ;
V_52 = F_54 () ;
V_10 = F_49 ( V_52 , V_58 -> V_104 , V_58 ) ;
if ( F_55 ( V_10 ) ) {
F_35 ( L_14 ) ;
V_59 = F_56 ( V_10 ) ;
goto V_105;
}
V_102 = F_52 ( V_52 , V_58 -> V_104 , V_106 , & V_103 ) ;
V_59 = - V_98 ;
if ( ! V_102 ) {
F_35 ( L_15 , V_106 ) ;
goto V_105;
}
V_22 = F_57 ( sizeof( * V_22 ) , V_107 ) ;
V_59 = - V_61 ;
if ( ! V_22 )
goto V_105;
for ( V_31 = 0 ; V_31 < V_65 ; V_31 ++ )
V_22 -> V_27 [ V_31 ] = ( * V_102 >> ( 5 - V_31 ) * 8 ) & 0xff ;
V_22 -> V_10 = V_10 ;
V_59 = F_58 ( & V_22 -> V_108 , V_58 , V_109 ,
V_110 , F_7 ( V_110 ) ,
& V_111 , V_10 -> V_2 -> V_96 ) ;
if ( V_59 )
goto V_112;
V_59 = F_59 ( & V_22 -> V_108 , & V_113 , V_22 ) ;
if ( V_59 )
goto V_112;
F_60 ( V_22 -> V_10 -> V_2 , & V_22 -> V_114 , V_115 ,
V_116 ) ;
F_61 ( & V_22 -> V_50 ) ;
F_31 ( & V_22 -> V_70 ) ;
V_26 = 0 ;
if ( F_52 ( V_52 , V_58 -> V_104 , L_16 , NULL ) )
V_26 = 1 ;
V_22 -> V_26 = V_26 ;
V_22 -> V_117 = true ;
V_22 -> V_118 = 0 ;
F_62 ( & V_10 -> V_67 , V_101 ) ;
if ( V_26 )
F_63 ( & V_22 -> V_70 , & V_10 -> V_68 ) ;
else
F_64 ( & V_22 -> V_70 , & V_10 -> V_68 ) ;
F_65 ( & V_22 -> V_50 ,
& V_10 -> V_53 [ F_15 ( V_22 -> V_27 ) ] ) ;
F_66 ( V_22 ) ;
F_67 ( & V_10 -> V_67 , V_101 ) ;
F_68 ( & V_58 -> V_2 , V_22 ) ;
F_69 ( L_17 ,
V_10 -> V_2 -> V_96 , V_22 -> V_27 , V_26 ? L_18 : L_19 ) ;
F_70 ( & V_22 -> V_119 , V_120 ,
( unsigned long ) V_22 ) ;
F_71 ( & V_22 -> V_114 ) ;
F_72 ( & V_22 -> V_108 ) ;
F_73 ( V_52 ) ;
return 0 ;
V_112:
F_74 ( V_22 ) ;
V_105:
F_73 ( V_52 ) ;
return V_59 ;
}
static int F_75 ( struct V_57 * V_58 )
{
struct V_21 * V_22 = F_76 ( & V_58 -> V_2 ) ;
if ( V_22 ) {
F_77 ( & V_22 -> V_108 . V_121 ) ;
F_78 ( & V_22 -> V_114 ) ;
F_79 ( & V_22 -> V_70 ) ;
F_80 ( & V_22 -> V_50 ) ;
F_81 () ;
F_77 ( & V_22 -> V_119 ) ;
F_82 ( V_22 ) ;
F_83 ( & V_22 -> V_114 ) ;
F_84 ( V_22 ) ;
F_85 ( & V_22 -> V_108 ) ;
F_68 ( & V_58 -> V_2 , NULL ) ;
F_74 ( V_22 ) ;
}
return 0 ;
}
static int T_6 F_86 ( void )
{
F_69 ( L_20 , V_7 ) ;
return F_87 ( & V_122 ) ;
}
static void T_7 F_88 ( void )
{
F_89 ( & V_122 ) ;
F_43 () ;
}
