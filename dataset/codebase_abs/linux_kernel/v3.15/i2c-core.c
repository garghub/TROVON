void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static const struct V_2 * F_5 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
while ( V_3 -> V_6 [ 0 ] ) {
if ( strcmp ( V_5 -> V_6 , V_3 -> V_6 ) == 0 )
return V_3 ;
V_3 ++ ;
}
return NULL ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
if ( ! V_5 )
return 0 ;
if ( F_8 ( V_8 , V_10 ) )
return 1 ;
if ( F_9 ( V_8 , V_10 ) )
return 1 ;
V_12 = F_10 ( V_10 ) ;
if ( V_12 -> V_13 )
return F_5 ( V_12 -> V_13 , V_5 ) != NULL ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_14 * V_15 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
int V_16 ;
V_16 = F_13 ( V_8 , V_15 ) ;
if ( V_16 != - V_17 )
return V_16 ;
if ( F_14 ( V_15 , L_1 ,
V_18 , V_5 -> V_6 ) )
return - V_19 ;
F_15 ( V_8 , L_2 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
return F_17 ( V_21 -> V_22 -> V_23 ) ;
}
static void F_18 ( struct V_20 * V_21 , int V_24 )
{
F_19 ( V_21 -> V_22 -> V_23 , V_24 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
return F_17 ( V_21 -> V_22 -> V_25 ) ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
struct V_7 * V_8 = & V_21 -> V_8 ;
int V_28 = 0 ;
V_28 = F_22 ( V_27 -> V_23 , V_29 |
V_30 , L_3 ) ;
if ( V_28 ) {
F_23 ( V_8 , L_4 , V_27 -> V_23 ) ;
return V_28 ;
}
if ( V_27 -> V_31 ) {
if ( F_22 ( V_27 -> V_25 , V_32 , L_5 ) ) {
F_23 ( V_8 , L_6 ,
V_27 -> V_25 ) ;
V_27 -> V_31 = NULL ;
}
}
return V_28 ;
}
static void F_24 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
if ( V_27 -> V_31 )
F_25 ( V_27 -> V_25 ) ;
F_25 ( V_27 -> V_23 ) ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
int V_33 = 0 , V_24 = 1 , V_28 = 0 ;
if ( V_27 -> V_34 )
V_27 -> V_34 ( V_27 ) ;
while ( V_33 ++ < V_35 * 2 ) {
if ( V_24 ) {
if ( V_27 -> V_31 && V_27 -> V_31 ( V_21 ) )
break;
if ( ! V_27 -> V_36 ( V_21 ) ) {
F_27 ( & V_21 -> V_8 ,
L_7 ) ;
V_28 = - V_37 ;
break;
}
}
V_24 = ! V_24 ;
V_27 -> V_38 ( V_21 , V_24 ) ;
F_28 ( V_39 ) ;
}
if ( V_27 -> V_40 )
V_27 -> V_40 ( V_27 ) ;
return V_28 ;
}
int F_29 ( struct V_20 * V_21 )
{
V_21 -> V_22 -> V_38 ( V_21 , 1 ) ;
return F_26 ( V_21 ) ;
}
int F_30 ( struct V_20 * V_21 )
{
int V_28 ;
V_28 = F_21 ( V_21 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_26 ( V_21 ) ;
F_24 ( V_21 ) ;
return V_28 ;
}
int F_31 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_22 )
return - V_41 ;
F_15 ( & V_21 -> V_8 , L_8 ) ;
return V_21 -> V_22 -> V_42 ( V_21 ) ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
int V_43 ;
if ( ! V_5 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( ! V_12 -> V_44 || ! V_12 -> V_13 )
return - V_17 ;
if ( ! F_33 ( & V_5 -> V_8 ) )
F_34 ( & V_5 -> V_8 ,
V_5 -> V_45 & V_46 ) ;
F_15 ( V_8 , L_9 ) ;
F_35 ( & V_5 -> V_8 , true ) ;
V_43 = V_12 -> V_44 ( V_5 , F_5 ( V_12 -> V_13 , V_5 ) ) ;
if ( V_43 )
F_36 ( & V_5 -> V_8 , true ) ;
return V_43 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
int V_43 = 0 ;
if ( ! V_5 || ! V_8 -> V_12 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( V_12 -> remove ) {
F_15 ( V_8 , L_10 ) ;
V_43 = V_12 -> remove ( V_5 ) ;
}
F_36 ( & V_5 -> V_8 , true ) ;
return V_43 ;
}
static void F_38 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_8 -> V_12 )
return;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( V_12 -> V_47 )
V_12 -> V_47 ( V_5 ) ;
}
static int F_39 ( struct V_7 * V_8 , T_1 V_48 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_8 -> V_12 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( ! V_12 -> V_49 )
return 0 ;
return V_12 -> V_49 ( V_5 , V_48 ) ;
}
static int F_40 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_8 -> V_12 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( ! V_12 -> V_50 )
return 0 ;
return V_12 -> V_50 ( V_5 ) ;
}
static int F_41 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_42 ( V_8 ) ;
else
return F_39 ( V_8 , V_53 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_44 ( V_8 ) ;
else
return F_40 ( V_8 ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_46 ( V_8 ) ;
else
return F_39 ( V_8 , V_54 ) ;
}
static int F_47 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_48 ( V_8 ) ;
else
return F_40 ( V_8 ) ;
}
static int F_49 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_50 ( V_8 ) ;
else
return F_39 ( V_8 , V_55 ) ;
}
static int F_51 ( struct V_7 * V_8 )
{
const struct V_51 * V_52 = V_8 -> V_12 ? V_8 -> V_12 -> V_52 : NULL ;
if ( V_52 )
return F_52 ( V_8 ) ;
else
return F_40 ( V_8 ) ;
}
static void F_53 ( struct V_7 * V_8 )
{
F_54 ( F_12 ( V_8 ) ) ;
}
static T_2
F_55 ( struct V_7 * V_8 , struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_11 , V_8 -> type == & V_59 ?
F_12 ( V_8 ) -> V_6 : F_56 ( V_8 ) -> V_6 ) ;
}
static T_2
F_57 ( struct V_7 * V_8 , struct V_56 * V_57 , char * V_58 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
int V_60 ;
V_60 = F_58 ( V_8 , V_58 , V_61 - 1 ) ;
if ( V_60 != - V_17 )
return V_60 ;
return sprintf ( V_58 , L_12 , V_18 , V_5 -> V_6 ) ;
}
struct V_4 * F_7 ( struct V_7 * V_8 )
{
return ( V_8 -> type == & V_59 )
? F_12 ( V_8 )
: NULL ;
}
static int F_59 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_45 & V_62 ) {
if ( V_5 -> V_63 > 0x3ff )
return - V_64 ;
} else {
if ( V_5 -> V_63 == 0x00 || V_5 -> V_63 > 0x7f )
return - V_64 ;
}
return 0 ;
}
static int F_60 ( unsigned short V_63 )
{
if ( V_63 < 0x08 || V_63 > 0x77 )
return - V_64 ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , void * V_65 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
int V_63 = * ( int * ) V_65 ;
if ( V_5 && V_5 -> V_63 == V_63 )
return - V_37 ;
return 0 ;
}
static int F_62 ( struct V_20 * V_66 , int V_63 )
{
struct V_20 * V_67 = F_63 ( V_66 ) ;
int V_68 ;
V_68 = F_64 ( & V_66 -> V_8 , & V_63 ,
F_61 ) ;
if ( ! V_68 && V_67 )
V_68 = F_62 ( V_67 , V_63 ) ;
return V_68 ;
}
static int F_65 ( struct V_7 * V_8 , void * V_65 )
{
int V_68 ;
if ( V_8 -> type == & V_69 )
V_68 = F_64 ( V_8 , V_65 ,
F_65 ) ;
else
V_68 = F_61 ( V_8 , V_65 ) ;
return V_68 ;
}
static int F_66 ( struct V_20 * V_66 , int V_63 )
{
struct V_20 * V_67 = F_63 ( V_66 ) ;
int V_68 = 0 ;
if ( V_67 )
V_68 = F_62 ( V_67 , V_63 ) ;
if ( ! V_68 )
V_68 = F_64 ( & V_66 -> V_8 , & V_63 ,
F_65 ) ;
return V_68 ;
}
void F_67 ( struct V_20 * V_66 )
{
struct V_20 * V_67 = F_63 ( V_66 ) ;
if ( V_67 )
F_67 ( V_67 ) ;
else
F_68 ( & V_66 -> V_70 ) ;
}
static int F_69 ( struct V_20 * V_66 )
{
struct V_20 * V_67 = F_63 ( V_66 ) ;
if ( V_67 )
return F_69 ( V_67 ) ;
else
return F_70 ( & V_66 -> V_70 ) ;
}
void F_71 ( struct V_20 * V_66 )
{
struct V_20 * V_67 = F_63 ( V_66 ) ;
if ( V_67 )
F_71 ( V_67 ) ;
else
F_72 ( & V_66 -> V_70 ) ;
}
static void F_73 ( struct V_20 * V_21 ,
struct V_4 * V_5 )
{
struct V_71 * V_72 = F_74 ( & V_5 -> V_8 ) ;
if ( V_72 ) {
F_75 ( & V_5 -> V_8 , L_13 , F_76 ( V_72 ) ) ;
return;
}
F_75 ( & V_5 -> V_8 , L_14 , F_77 ( V_21 ) ,
V_5 -> V_63 | ( ( V_5 -> V_45 & V_62 )
? 0xa000 : 0 ) ) ;
}
struct V_4 *
F_78 ( struct V_20 * V_21 , struct V_73 const * V_74 )
{
struct V_4 * V_5 ;
int V_43 ;
V_5 = F_79 ( sizeof *V_5 , V_75 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_66 = V_21 ;
V_5 -> V_8 . V_76 = V_74 -> V_76 ;
if ( V_74 -> V_77 )
V_5 -> V_8 . V_77 = * V_74 -> V_77 ;
V_5 -> V_45 = V_74 -> V_45 ;
V_5 -> V_63 = V_74 -> V_63 ;
V_5 -> V_78 = V_74 -> V_78 ;
F_80 ( V_5 -> V_6 , V_74 -> type , sizeof( V_5 -> V_6 ) ) ;
V_43 = F_59 ( V_5 ) ;
if ( V_43 ) {
F_27 ( & V_21 -> V_8 , L_15 ,
V_5 -> V_45 & V_62 ? 10 : 7 , V_5 -> V_63 ) ;
goto V_79;
}
V_43 = F_66 ( V_21 , V_5 -> V_63 ) ;
if ( V_43 )
goto V_80;
V_5 -> V_8 . V_67 = & V_5 -> V_66 -> V_8 ;
V_5 -> V_8 . V_81 = & V_82 ;
V_5 -> V_8 . type = & V_59 ;
V_5 -> V_8 . V_83 = V_74 -> V_83 ;
F_81 ( & V_5 -> V_8 , V_74 -> V_84 . V_85 ) ;
F_73 ( V_21 , V_5 ) ;
V_43 = F_82 ( & V_5 -> V_8 ) ;
if ( V_43 )
goto V_80;
F_15 ( & V_21 -> V_8 , L_16 ,
V_5 -> V_6 , F_83 ( & V_5 -> V_8 ) ) ;
return V_5 ;
V_80:
F_27 ( & V_21 -> V_8 , L_17
L_18 , V_5 -> V_6 , V_5 -> V_63 , V_43 ) ;
V_79:
F_54 ( V_5 ) ;
return NULL ;
}
void F_84 ( struct V_4 * V_5 )
{
F_85 ( & V_5 -> V_8 ) ;
}
static int F_86 ( struct V_4 * V_5 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static int F_87 ( struct V_4 * V_5 )
{
return 0 ;
}
struct V_4 * F_88 ( struct V_20 * V_66 , T_3 V_86 )
{
struct V_73 V_74 = {
F_89 ( L_19 , V_86 ) ,
} ;
return F_78 ( V_66 , & V_74 ) ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = F_56 ( V_8 ) ;
F_91 ( & V_21 -> V_87 ) ;
}
static inline unsigned int F_92 ( struct V_20 * V_66 )
{
unsigned int V_88 = 0 ;
while ( ( V_66 = F_63 ( V_66 ) ) )
V_88 ++ ;
return V_88 ;
}
static T_2
F_93 ( struct V_7 * V_8 , struct V_56 * V_57 ,
const char * V_58 , T_4 V_89 )
{
struct V_20 * V_21 = F_56 ( V_8 ) ;
struct V_73 V_74 ;
struct V_4 * V_5 ;
char * V_90 , V_91 ;
int V_92 ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
V_90 = strchr ( V_58 , ' ' ) ;
if ( ! V_90 ) {
F_27 ( V_8 , L_20 , L_21 ) ;
return - V_64 ;
}
if ( V_90 - V_58 > V_93 - 1 ) {
F_27 ( V_8 , L_22 , L_21 ) ;
return - V_64 ;
}
memcpy ( V_74 . type , V_58 , V_90 - V_58 ) ;
V_92 = sscanf ( ++ V_90 , L_23 , & V_74 . V_63 , & V_91 ) ;
if ( V_92 < 1 ) {
F_27 ( V_8 , L_24 , L_21 ) ;
return - V_64 ;
}
if ( V_92 > 1 && V_91 != '\n' ) {
F_27 ( V_8 , L_25 , L_21 ) ;
return - V_64 ;
}
V_5 = F_78 ( V_21 , & V_74 ) ;
if ( ! V_5 )
return - V_64 ;
F_94 ( & V_21 -> V_94 ) ;
F_95 ( & V_5 -> V_95 , & V_21 -> V_96 ) ;
F_96 ( & V_21 -> V_94 ) ;
F_97 ( V_8 , L_26 , L_21 ,
V_74 . type , V_74 . V_63 ) ;
return V_89 ;
}
static T_2
F_98 ( struct V_7 * V_8 , struct V_56 * V_57 ,
const char * V_58 , T_4 V_89 )
{
struct V_20 * V_21 = F_56 ( V_8 ) ;
struct V_4 * V_5 , * V_97 ;
unsigned short V_63 ;
char V_91 ;
int V_92 ;
V_92 = sscanf ( V_58 , L_23 , & V_63 , & V_91 ) ;
if ( V_92 < 1 ) {
F_27 ( V_8 , L_24 , L_27 ) ;
return - V_64 ;
}
if ( V_92 > 1 && V_91 != '\n' ) {
F_27 ( V_8 , L_25 , L_27 ) ;
return - V_64 ;
}
V_92 = - V_98 ;
F_99 ( & V_21 -> V_94 ,
F_92 ( V_21 ) ) ;
F_100 (client, next, &adap->userspace_clients,
detected) {
if ( V_5 -> V_63 == V_63 ) {
F_97 ( V_8 , L_28 ,
L_27 , V_5 -> V_6 , V_5 -> V_63 ) ;
F_101 ( & V_5 -> V_95 ) ;
F_84 ( V_5 ) ;
V_92 = V_89 ;
break;
}
}
F_96 ( & V_21 -> V_94 ) ;
if ( V_92 < 0 )
F_27 ( V_8 , L_29 ,
L_27 ) ;
return V_92 ;
}
struct V_20 * F_102 ( struct V_7 * V_8 )
{
return ( V_8 -> type == & V_69 )
? F_56 ( V_8 )
: NULL ;
}
static void F_103 ( struct V_20 * V_66 )
{
struct V_99 * V_100 ;
F_104 ( & V_101 ) ;
F_105 (devinfo, &__i2c_board_list, list) {
if ( V_100 -> V_102 == V_66 -> V_103
&& ! F_78 ( V_66 ,
& V_100 -> V_104 ) )
F_27 ( & V_66 -> V_8 ,
L_30 ,
V_100 -> V_104 . V_63 ) ;
}
F_106 ( & V_101 ) ;
}
static void F_107 ( struct V_20 * V_21 )
{
void * V_68 ;
struct V_105 * V_106 ;
if ( ! V_21 -> V_8 . V_83 )
return;
F_15 ( & V_21 -> V_8 , L_31 ) ;
F_108 (adap->dev.of_node, node) {
struct V_73 V_74 = {} ;
struct V_107 V_108 = {} ;
const T_5 * V_63 ;
int V_60 ;
F_15 ( & V_21 -> V_8 , L_32 , V_106 -> V_109 ) ;
if ( F_109 ( V_106 , V_74 . type , sizeof( V_74 . type ) ) < 0 ) {
F_27 ( & V_21 -> V_8 , L_33 ,
V_106 -> V_109 ) ;
continue;
}
V_63 = F_110 ( V_106 , L_34 , & V_60 ) ;
if ( ! V_63 || ( V_60 < sizeof( int ) ) ) {
F_27 ( & V_21 -> V_8 , L_35 ,
V_106 -> V_109 ) ;
continue;
}
V_74 . V_63 = F_111 ( V_63 ) ;
if ( V_74 . V_63 > ( 1 << 10 ) - 1 ) {
F_27 ( & V_21 -> V_8 , L_36 ,
V_74 . V_63 , V_106 -> V_109 ) ;
continue;
}
V_74 . V_78 = F_112 ( V_106 , 0 ) ;
V_74 . V_83 = F_113 ( V_106 ) ;
V_74 . V_77 = & V_108 ;
if ( F_110 ( V_106 , L_37 , NULL ) )
V_74 . V_45 |= V_46 ;
F_114 ( L_38 , V_18 , V_74 . type ) ;
V_68 = F_78 ( V_21 , & V_74 ) ;
if ( V_68 == NULL ) {
F_27 ( & V_21 -> V_8 , L_39 ,
V_106 -> V_109 ) ;
F_115 ( V_106 ) ;
F_116 ( V_74 . V_78 ) ;
continue;
}
}
}
static int F_117 ( struct V_7 * V_8 , void * V_110 )
{
return V_8 -> V_83 == V_110 ;
}
struct V_4 * F_118 ( struct V_105 * V_106 )
{
struct V_7 * V_8 ;
V_8 = F_119 ( & V_82 , NULL , V_106 ,
F_117 ) ;
if ( ! V_8 )
return NULL ;
return F_7 ( V_8 ) ;
}
struct V_20 * F_120 ( struct V_105 * V_106 )
{
struct V_7 * V_8 ;
V_8 = F_119 ( & V_82 , NULL , V_106 ,
F_117 ) ;
if ( ! V_8 )
return NULL ;
return F_102 ( V_8 ) ;
}
static void F_107 ( struct V_20 * V_21 ) { }
static int F_121 ( struct V_111 * V_112 , void * V_110 )
{
struct V_73 * V_74 = V_110 ;
if ( V_112 -> type == V_113 ) {
struct V_114 * V_115 ;
V_115 = & V_112 -> V_110 . V_116 ;
if ( V_115 -> type == V_117 ) {
V_74 -> V_63 = V_115 -> V_118 ;
if ( V_115 -> V_119 == V_120 )
V_74 -> V_45 |= V_62 ;
}
} else if ( V_74 -> V_78 < 0 ) {
struct V_121 V_122 ;
if ( F_122 ( V_112 , 0 , & V_122 ) )
V_74 -> V_78 = V_122 . V_123 ;
}
return 1 ;
}
static T_6 F_123 ( T_7 V_124 , T_8 V_125 ,
void * V_110 , void * * V_126 )
{
struct V_20 * V_66 = V_110 ;
struct V_127 V_128 ;
struct V_73 V_74 ;
struct V_71 * V_72 ;
int V_28 ;
if ( F_124 ( V_124 , & V_72 ) )
return V_129 ;
if ( F_125 ( V_72 ) || ! V_72 -> V_43 . V_130 )
return V_129 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_84 . V_85 = V_72 ;
V_74 . V_78 = - 1 ;
F_126 ( & V_128 ) ;
V_28 = F_127 ( V_72 , & V_128 ,
F_121 , & V_74 ) ;
F_128 ( & V_128 ) ;
if ( V_28 < 0 || ! V_74 . V_63 )
return V_129 ;
V_72 -> V_131 . V_45 . V_132 = true ;
F_80 ( V_74 . type , F_83 ( & V_72 -> V_8 ) , sizeof( V_74 . type ) ) ;
if ( ! F_78 ( V_66 , & V_74 ) ) {
V_72 -> V_131 . V_45 . V_132 = false ;
F_27 ( & V_66 -> V_8 ,
L_40 ,
F_83 ( & V_72 -> V_8 ) ) ;
}
return V_129 ;
}
static void F_129 ( struct V_20 * V_21 )
{
T_7 V_124 ;
T_6 V_43 ;
if ( ! V_21 -> V_8 . V_67 )
return;
V_124 = F_130 ( V_21 -> V_8 . V_67 ) ;
if ( ! V_124 )
return;
V_43 = F_131 ( V_133 , V_124 , 1 ,
F_123 , NULL ,
V_21 , NULL ) ;
if ( F_132 ( V_43 ) )
F_23 ( & V_21 -> V_8 , L_41 ) ;
}
static inline void F_129 ( struct V_20 * V_21 ) {}
static int F_133 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
F_134 ( V_21 , V_12 ) ;
if ( V_12 -> V_134 ) {
F_23 ( & V_21 -> V_8 , L_42 ,
V_12 -> V_12 . V_6 ) ;
F_23 ( & V_21 -> V_8 , L_43
L_44 ) ;
V_12 -> V_134 ( V_21 ) ;
}
return 0 ;
}
static int F_135 ( struct V_9 * V_135 , void * V_110 )
{
return F_133 ( F_10 ( V_135 ) , V_110 ) ;
}
static int F_136 ( struct V_20 * V_21 )
{
int V_92 = 0 ;
if ( F_137 ( F_138 ( ! V_82 . V_136 ) ) ) {
V_92 = - V_137 ;
goto V_138;
}
if ( F_137 ( V_21 -> V_6 [ 0 ] == '\0' ) ) {
F_139 ( L_45
L_46 ) ;
return - V_64 ;
}
if ( F_137 ( ! V_21 -> V_139 ) ) {
F_139 ( L_47
L_48 , V_21 -> V_6 ) ;
return - V_64 ;
}
F_140 ( & V_21 -> V_70 ) ;
F_141 ( & V_21 -> V_94 ) ;
F_126 ( & V_21 -> V_96 ) ;
if ( V_21 -> V_140 == 0 )
V_21 -> V_140 = V_141 ;
F_75 ( & V_21 -> V_8 , L_49 , V_21 -> V_103 ) ;
V_21 -> V_8 . V_81 = & V_82 ;
V_21 -> V_8 . type = & V_69 ;
V_92 = F_82 ( & V_21 -> V_8 ) ;
if ( V_92 )
goto V_138;
F_15 ( & V_21 -> V_8 , L_50 , V_21 -> V_6 ) ;
#ifdef F_142
V_92 = F_143 ( V_142 , & V_21 -> V_8 ,
V_21 -> V_8 . V_67 ) ;
if ( V_92 )
F_23 ( & V_21 -> V_8 ,
L_51 ) ;
#endif
if ( V_21 -> V_22 ) {
struct V_26 * V_27 = V_21 -> V_22 ;
if ( ! V_27 -> V_42 ) {
F_27 ( & V_21 -> V_8 , L_52 ) ;
V_21 -> V_22 = NULL ;
goto V_143;
}
if ( V_27 -> V_42 == F_30 ) {
if ( ! F_144 ( V_27 -> V_23 ) ) {
F_27 ( & V_21 -> V_8 , L_53 ) ;
V_21 -> V_22 = NULL ;
goto V_143;
}
if ( F_144 ( V_27 -> V_25 ) )
V_27 -> V_31 = F_20 ;
else
V_27 -> V_31 = NULL ;
V_27 -> V_36 = F_16 ;
V_27 -> V_38 = F_18 ;
} else if ( ! V_27 -> V_38 || ! V_27 -> V_36 ) {
F_27 ( & V_21 -> V_8 , L_54 ) ;
V_21 -> V_22 = NULL ;
}
}
V_143:
F_107 ( V_21 ) ;
F_129 ( V_21 ) ;
if ( V_21 -> V_103 < V_144 )
F_103 ( V_21 ) ;
F_94 ( & V_145 ) ;
F_145 ( & V_82 , NULL , V_21 , F_135 ) ;
F_96 ( & V_145 ) ;
return 0 ;
V_138:
F_94 ( & V_145 ) ;
F_146 ( & V_146 , V_21 -> V_103 ) ;
F_96 ( & V_145 ) ;
return V_92 ;
}
static int F_147 ( struct V_20 * V_21 )
{
int V_3 ;
F_94 ( & V_145 ) ;
V_3 = F_148 ( & V_146 , V_21 , V_21 -> V_103 , V_21 -> V_103 + 1 ,
V_75 ) ;
F_96 ( & V_145 ) ;
if ( V_3 < 0 )
return V_3 == - V_147 ? - V_37 : V_3 ;
return F_136 ( V_21 ) ;
}
int F_149 ( struct V_20 * V_66 )
{
struct V_7 * V_8 = & V_66 -> V_8 ;
int V_3 ;
if ( V_8 -> V_83 ) {
V_3 = F_150 ( V_8 -> V_83 , L_55 ) ;
if ( V_3 >= 0 ) {
V_66 -> V_103 = V_3 ;
return F_147 ( V_66 ) ;
}
}
F_94 ( & V_145 ) ;
V_3 = F_148 ( & V_146 , V_66 ,
V_144 , 0 , V_75 ) ;
F_96 ( & V_145 ) ;
if ( V_3 < 0 )
return V_3 ;
V_66 -> V_103 = V_3 ;
return F_136 ( V_66 ) ;
}
int F_151 ( struct V_20 * V_21 )
{
if ( V_21 -> V_103 == - 1 )
return F_149 ( V_21 ) ;
return F_147 ( V_21 ) ;
}
static void F_152 ( struct V_11 * V_12 ,
struct V_20 * V_66 )
{
struct V_4 * V_5 , * V_148 ;
F_100 (client, _n, &driver->clients, detected) {
if ( V_5 -> V_66 == V_66 ) {
F_15 ( & V_66 -> V_8 , L_56 ,
V_5 -> V_6 , V_5 -> V_63 ) ;
F_101 ( & V_5 -> V_95 ) ;
F_84 ( V_5 ) ;
}
}
}
static int F_153 ( struct V_7 * V_8 , void * V_149 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
if ( V_5 && strcmp ( V_5 -> V_6 , L_19 ) )
F_84 ( V_5 ) ;
return 0 ;
}
static int F_154 ( struct V_7 * V_8 , void * V_149 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
if ( V_5 )
F_84 ( V_5 ) ;
return 0 ;
}
static int F_155 ( struct V_9 * V_135 , void * V_110 )
{
F_152 ( F_10 ( V_135 ) , V_110 ) ;
return 0 ;
}
void F_156 ( struct V_20 * V_21 )
{
struct V_20 * V_150 ;
struct V_4 * V_5 , * V_97 ;
F_94 ( & V_145 ) ;
V_150 = F_157 ( & V_146 , V_21 -> V_103 ) ;
F_96 ( & V_145 ) ;
if ( V_150 != V_21 ) {
F_158 ( L_57
L_58 , V_21 -> V_6 ) ;
return;
}
F_94 ( & V_145 ) ;
F_145 ( & V_82 , NULL , V_21 ,
F_155 ) ;
F_96 ( & V_145 ) ;
F_99 ( & V_21 -> V_94 ,
F_92 ( V_21 ) ) ;
F_100 (client, next, &adap->userspace_clients,
detected) {
F_15 ( & V_21 -> V_8 , L_56 , V_5 -> V_6 ,
V_5 -> V_63 ) ;
F_101 ( & V_5 -> V_95 ) ;
F_84 ( V_5 ) ;
}
F_96 ( & V_21 -> V_94 ) ;
F_64 ( & V_21 -> V_8 , NULL , F_153 ) ;
F_64 ( & V_21 -> V_8 , NULL , F_154 ) ;
#ifdef F_142
F_159 ( V_142 , & V_21 -> V_8 ,
V_21 -> V_8 . V_67 ) ;
#endif
F_15 ( & V_21 -> V_8 , L_59 , V_21 -> V_6 ) ;
F_160 ( & V_21 -> V_87 ) ;
F_85 ( & V_21 -> V_8 ) ;
F_161 ( & V_21 -> V_87 ) ;
F_94 ( & V_145 ) ;
F_146 ( & V_146 , V_21 -> V_103 ) ;
F_96 ( & V_145 ) ;
memset ( & V_21 -> V_8 , 0 , sizeof( V_21 -> V_8 ) ) ;
}
int F_162 ( void * V_110 , int (* F_163)( struct V_7 * , void * ) )
{
int V_92 ;
F_94 ( & V_145 ) ;
V_92 = F_164 ( & V_82 , NULL , V_110 , F_163 ) ;
F_96 ( & V_145 ) ;
return V_92 ;
}
static int F_165 ( struct V_7 * V_8 , void * V_110 )
{
if ( V_8 -> type != & V_69 )
return 0 ;
return F_133 ( V_110 , F_56 ( V_8 ) ) ;
}
int F_166 ( struct V_151 * V_152 , struct V_11 * V_12 )
{
int V_92 ;
if ( F_137 ( F_138 ( ! V_82 . V_136 ) ) )
return - V_137 ;
V_12 -> V_12 . V_152 = V_152 ;
V_12 -> V_12 . V_81 = & V_82 ;
V_92 = F_167 ( & V_12 -> V_12 ) ;
if ( V_92 )
return V_92 ;
if ( V_12 -> V_49 )
F_168 ( L_60 ,
V_12 -> V_12 . V_6 ) ;
if ( V_12 -> V_50 )
F_168 ( L_61 ,
V_12 -> V_12 . V_6 ) ;
F_158 ( L_62 , V_12 -> V_12 . V_6 ) ;
F_126 ( & V_12 -> V_153 ) ;
F_162 ( V_12 , F_165 ) ;
return 0 ;
}
static int F_169 ( struct V_7 * V_8 , void * V_110 )
{
if ( V_8 -> type == & V_69 )
F_152 ( V_110 , F_56 ( V_8 ) ) ;
return 0 ;
}
void F_170 ( struct V_11 * V_12 )
{
F_162 ( V_12 , F_169 ) ;
F_171 ( & V_12 -> V_12 ) ;
F_158 ( L_63 , V_12 -> V_12 . V_6 ) ;
}
struct V_4 * F_172 ( struct V_4 * V_5 )
{
if ( V_5 && F_173 ( & V_5 -> V_8 ) )
return V_5 ;
return NULL ;
}
void F_174 ( struct V_4 * V_5 )
{
if ( V_5 )
F_175 ( & V_5 -> V_8 ) ;
}
static int F_176 ( struct V_7 * V_8 , void * V_154 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_155 * V_156 = V_154 ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_5 -> V_8 . V_12 )
return 0 ;
V_12 = F_10 ( V_5 -> V_8 . V_12 ) ;
if ( V_12 -> V_157 )
V_12 -> V_157 ( V_5 , V_156 -> V_158 , V_156 -> V_156 ) ;
return 0 ;
}
void F_177 ( struct V_20 * V_21 , unsigned int V_158 , void * V_156 )
{
struct V_155 V_159 ;
V_159 . V_158 = V_158 ;
V_159 . V_156 = V_156 ;
F_64 ( & V_21 -> V_8 , & V_159 , F_176 ) ;
}
static int T_9 F_178 ( void )
{
int V_160 ;
V_160 = F_179 ( & V_82 ) ;
if ( V_160 )
return V_160 ;
#ifdef F_142
V_142 = F_180 ( L_64 ) ;
if ( ! V_142 ) {
V_160 = - V_19 ;
goto V_161;
}
#endif
V_160 = F_181 ( & V_162 ) ;
if ( V_160 )
goto V_163;
return 0 ;
V_163:
#ifdef F_142
F_182 ( V_142 ) ;
V_161:
#endif
F_183 ( & V_82 ) ;
return V_160 ;
}
static void T_10 F_184 ( void )
{
F_170 ( & V_162 ) ;
#ifdef F_142
F_182 ( V_142 ) ;
#endif
F_183 ( & V_82 ) ;
F_185 () ;
}
int F_186 ( struct V_20 * V_21 , struct V_164 * V_165 , int V_166 )
{
unsigned long V_167 ;
int V_28 , V_168 ;
if ( F_187 ( & V_1 ) ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_166 ; V_33 ++ )
if ( V_165 [ V_33 ] . V_45 & V_169 )
F_188 ( V_21 , & V_165 [ V_33 ] , V_33 ) ;
else
F_189 ( V_21 , & V_165 [ V_33 ] , V_33 ) ;
}
V_167 = V_170 ;
for ( V_28 = 0 , V_168 = 0 ; V_168 <= V_21 -> V_171 ; V_168 ++ ) {
V_28 = V_21 -> V_139 -> V_172 ( V_21 , V_165 , V_166 ) ;
if ( V_28 != - V_137 )
break;
if ( F_190 ( V_170 , V_167 + V_21 -> V_140 ) )
break;
}
if ( F_187 ( & V_1 ) ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_28 ; V_33 ++ )
if ( V_165 [ V_33 ] . V_45 & V_169 )
F_191 ( V_21 , & V_165 [ V_33 ] , V_33 ) ;
F_192 ( V_21 , V_33 , V_28 ) ;
}
return V_28 ;
}
int F_193 ( struct V_20 * V_21 , struct V_164 * V_165 , int V_166 )
{
int V_28 ;
if ( V_21 -> V_139 -> V_172 ) {
#ifdef F_194
for ( V_28 = 0 ; V_28 < V_166 ; V_28 ++ ) {
F_15 ( & V_21 -> V_8 , L_65
L_66 , V_28 , ( V_165 [ V_28 ] . V_45 & V_169 )
? 'R' : 'W' , V_165 [ V_28 ] . V_63 , V_165 [ V_28 ] . V_60 ,
( V_165 [ V_28 ] . V_45 & V_173 ) ? L_67 : L_68 ) ;
}
#endif
if ( F_195 () || F_196 () ) {
V_28 = F_69 ( V_21 ) ;
if ( ! V_28 )
return - V_137 ;
} else {
F_67 ( V_21 ) ;
}
V_28 = F_186 ( V_21 , V_165 , V_166 ) ;
F_71 ( V_21 ) ;
return V_28 ;
} else {
F_15 ( & V_21 -> V_8 , L_69 ) ;
return - V_41 ;
}
}
int F_197 ( const struct V_4 * V_5 , const char * V_58 , int V_89 )
{
int V_28 ;
struct V_20 * V_21 = V_5 -> V_66 ;
struct V_164 V_174 ;
V_174 . V_63 = V_5 -> V_63 ;
V_174 . V_45 = V_5 -> V_45 & V_175 ;
V_174 . V_60 = V_89 ;
V_174 . V_58 = ( char * ) V_58 ;
V_28 = F_193 ( V_21 , & V_174 , 1 ) ;
return ( V_28 == 1 ) ? V_89 : V_28 ;
}
int F_198 ( const struct V_4 * V_5 , char * V_58 , int V_89 )
{
struct V_20 * V_21 = V_5 -> V_66 ;
struct V_164 V_174 ;
int V_28 ;
V_174 . V_63 = V_5 -> V_63 ;
V_174 . V_45 = V_5 -> V_45 & V_175 ;
V_174 . V_45 |= V_169 ;
V_174 . V_60 = V_89 ;
V_174 . V_58 = V_58 ;
V_28 = F_193 ( V_21 , & V_174 , 1 ) ;
return ( V_28 == 1 ) ? V_89 : V_28 ;
}
static int F_199 ( struct V_20 * V_21 , unsigned short V_63 )
{
int V_176 ;
union V_177 V_149 ;
#ifdef F_200
if ( V_63 == 0x73 && ( V_21 -> V_178 & V_179 )
&& F_201 ( V_21 , V_180 ) )
V_176 = F_202 ( V_21 , V_63 , 0 , V_181 , 0 ,
V_182 , & V_149 ) ;
else
#endif
if ( ! ( ( V_63 & ~ 0x07 ) == 0x30 || ( V_63 & ~ 0x0f ) == 0x50 )
&& F_201 ( V_21 , V_183 ) )
V_176 = F_202 ( V_21 , V_63 , 0 , V_184 , 0 ,
V_185 , NULL ) ;
else if ( F_201 ( V_21 , V_186 ) )
V_176 = F_202 ( V_21 , V_63 , 0 , V_181 , 0 ,
V_187 , & V_149 ) ;
else {
F_23 ( & V_21 -> V_8 , L_70 ,
V_63 ) ;
V_176 = - V_41 ;
}
return V_176 >= 0 ;
}
static int F_203 ( struct V_4 * V_188 ,
struct V_11 * V_12 )
{
struct V_73 V_74 ;
struct V_20 * V_66 = V_188 -> V_66 ;
int V_63 = V_188 -> V_63 ;
int V_176 ;
V_176 = F_60 ( V_63 ) ;
if ( V_176 ) {
F_23 ( & V_66 -> V_8 , L_71 ,
V_63 ) ;
return V_176 ;
}
if ( F_66 ( V_66 , V_63 ) )
return 0 ;
if ( ! F_199 ( V_66 , V_63 ) )
return 0 ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 . V_63 = V_63 ;
V_176 = V_12 -> V_189 ( V_188 , & V_74 ) ;
if ( V_176 ) {
return V_176 == - V_17 ? 0 : V_176 ;
}
if ( V_74 . type [ 0 ] == '\0' ) {
F_27 ( & V_66 -> V_8 , L_72
L_73 , V_12 -> V_12 . V_6 ,
V_63 ) ;
} else {
struct V_4 * V_5 ;
if ( V_66 -> V_178 & V_190 )
F_23 ( & V_66 -> V_8 ,
L_74
L_75
L_76 ,
V_74 . V_63 ) ;
F_15 ( & V_66 -> V_8 , L_77 ,
V_74 . type , V_74 . V_63 ) ;
V_5 = F_78 ( V_66 , & V_74 ) ;
if ( V_5 )
F_95 ( & V_5 -> V_95 , & V_12 -> V_153 ) ;
else
F_27 ( & V_66 -> V_8 , L_78 ,
V_74 . type , V_74 . V_63 ) ;
}
return 0 ;
}
static int F_134 ( struct V_20 * V_66 , struct V_11 * V_12 )
{
const unsigned short * V_191 ;
struct V_4 * V_188 ;
int V_33 , V_176 = 0 ;
int V_192 = F_77 ( V_66 ) ;
V_191 = V_12 -> V_191 ;
if ( ! V_12 -> V_189 || ! V_191 )
return 0 ;
if ( ! ( V_66 -> V_178 & V_12 -> V_178 ) )
return 0 ;
V_188 = F_79 ( sizeof( struct V_4 ) , V_75 ) ;
if ( ! V_188 )
return - V_19 ;
V_188 -> V_66 = V_66 ;
for ( V_33 = 0 ; V_191 [ V_33 ] != V_193 ; V_33 += 1 ) {
F_15 ( & V_66 -> V_8 , L_79
L_80 , V_192 , V_191 [ V_33 ] ) ;
V_188 -> V_63 = V_191 [ V_33 ] ;
V_176 = F_203 ( V_188 , V_12 ) ;
if ( F_137 ( V_176 ) )
break;
}
F_54 ( V_188 ) ;
return V_176 ;
}
int F_204 ( struct V_20 * V_21 , unsigned short V_63 )
{
return F_202 ( V_21 , V_63 , 0 , V_181 , 0 ,
V_185 , NULL ) >= 0 ;
}
struct V_4 *
F_205 ( struct V_20 * V_21 ,
struct V_73 * V_74 ,
unsigned short const * V_194 ,
int (* V_44)( struct V_20 * , unsigned short V_63 ) )
{
int V_33 ;
if ( ! V_44 )
V_44 = F_199 ;
for ( V_33 = 0 ; V_194 [ V_33 ] != V_193 ; V_33 ++ ) {
if ( F_60 ( V_194 [ V_33 ] ) < 0 ) {
F_23 ( & V_21 -> V_8 , L_81
L_82 , V_194 [ V_33 ] ) ;
continue;
}
if ( F_66 ( V_21 , V_194 [ V_33 ] ) ) {
F_15 ( & V_21 -> V_8 , L_83
L_84 , V_194 [ V_33 ] ) ;
continue;
}
if ( V_44 ( V_21 , V_194 [ V_33 ] ) )
break;
}
if ( V_194 [ V_33 ] == V_193 ) {
F_15 ( & V_21 -> V_8 , L_85 ) ;
return NULL ;
}
V_74 -> V_63 = V_194 [ V_33 ] ;
return F_78 ( V_21 , V_74 ) ;
}
struct V_20 * F_206 ( int V_103 )
{
struct V_20 * V_66 ;
F_94 ( & V_145 ) ;
V_66 = F_157 ( & V_146 , V_103 ) ;
if ( V_66 && ! F_207 ( V_66 -> V_152 ) )
V_66 = NULL ;
F_96 ( & V_145 ) ;
return V_66 ;
}
void F_208 ( struct V_20 * V_21 )
{
if ( V_21 )
F_209 ( V_21 -> V_152 ) ;
}
static T_11 F_210 ( T_3 V_110 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ ) {
if ( V_110 & 0x8000 )
V_110 = V_110 ^ V_195 ;
V_110 = V_110 << 1 ;
}
return ( T_11 ) ( V_110 >> 8 ) ;
}
static T_11 F_211 ( T_11 V_196 , T_11 * V_136 , T_4 V_89 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_89 ; V_33 ++ )
V_196 = F_210 ( ( V_196 ^ V_136 [ V_33 ] ) << 8 ) ;
return V_196 ;
}
static T_11 F_212 ( T_11 V_197 , struct V_164 * V_174 )
{
T_11 V_63 = ( V_174 -> V_63 << 1 ) | ! ! ( V_174 -> V_45 & V_169 ) ;
V_197 = F_211 ( V_197 , & V_63 , 1 ) ;
return F_211 ( V_197 , V_174 -> V_58 , V_174 -> V_60 ) ;
}
static inline void F_213 ( struct V_164 * V_174 )
{
V_174 -> V_58 [ V_174 -> V_60 ] = F_212 ( 0 , V_174 ) ;
V_174 -> V_60 ++ ;
}
static int F_214 ( T_11 V_198 , struct V_164 * V_174 )
{
T_11 V_199 = V_174 -> V_58 [ -- V_174 -> V_60 ] ;
V_198 = F_212 ( V_198 , V_174 ) ;
if ( V_199 != V_198 ) {
F_158 ( L_86 ,
V_199 , V_198 ) ;
return - V_200 ;
}
return 0 ;
}
T_12 F_215 ( const struct V_4 * V_5 )
{
union V_177 V_110 ;
int V_43 ;
V_43 = F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_181 , 0 ,
V_187 , & V_110 ) ;
return ( V_43 < 0 ) ? V_43 : V_110 . V_201 ;
}
T_12 F_216 ( const struct V_4 * V_5 , T_11 V_202 )
{
return F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_184 , V_202 , V_187 , NULL ) ;
}
T_12 F_217 ( const struct V_4 * V_5 , T_11 V_157 )
{
union V_177 V_110 ;
int V_43 ;
V_43 = F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_181 , V_157 ,
V_182 , & V_110 ) ;
return ( V_43 < 0 ) ? V_43 : V_110 . V_201 ;
}
T_12 F_218 ( const struct V_4 * V_5 , T_11 V_157 ,
T_11 V_202 )
{
union V_177 V_110 ;
V_110 . V_201 = V_202 ;
return F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_184 , V_157 ,
V_182 , & V_110 ) ;
}
T_12 F_219 ( const struct V_4 * V_5 , T_11 V_157 )
{
union V_177 V_110 ;
int V_43 ;
V_43 = F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_181 , V_157 ,
V_203 , & V_110 ) ;
return ( V_43 < 0 ) ? V_43 : V_110 . V_204 ;
}
T_12 F_220 ( const struct V_4 * V_5 , T_11 V_157 ,
T_3 V_202 )
{
union V_177 V_110 ;
V_110 . V_204 = V_202 ;
return F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_184 , V_157 ,
V_203 , & V_110 ) ;
}
T_12 F_221 ( const struct V_4 * V_5 , T_11 V_157 ,
T_11 * V_205 )
{
union V_177 V_110 ;
int V_43 ;
V_43 = F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_181 , V_157 ,
V_206 , & V_110 ) ;
if ( V_43 )
return V_43 ;
memcpy ( V_205 , & V_110 . V_207 [ 1 ] , V_110 . V_207 [ 0 ] ) ;
return V_110 . V_207 [ 0 ] ;
}
T_12 F_222 ( const struct V_4 * V_5 , T_11 V_157 ,
T_11 V_208 , const T_11 * V_205 )
{
union V_177 V_110 ;
if ( V_208 > V_209 )
V_208 = V_209 ;
V_110 . V_207 [ 0 ] = V_208 ;
memcpy ( & V_110 . V_207 [ 1 ] , V_205 , V_208 ) ;
return F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_184 , V_157 ,
V_206 , & V_110 ) ;
}
T_12 F_223 ( const struct V_4 * V_5 , T_11 V_157 ,
T_11 V_208 , T_11 * V_205 )
{
union V_177 V_110 ;
int V_43 ;
if ( V_208 > V_209 )
V_208 = V_209 ;
V_110 . V_207 [ 0 ] = V_208 ;
V_43 = F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_181 , V_157 ,
V_210 , & V_110 ) ;
if ( V_43 < 0 )
return V_43 ;
memcpy ( V_205 , & V_110 . V_207 [ 1 ] , V_110 . V_207 [ 0 ] ) ;
return V_110 . V_207 [ 0 ] ;
}
T_12 F_224 ( const struct V_4 * V_5 , T_11 V_157 ,
T_11 V_208 , const T_11 * V_205 )
{
union V_177 V_110 ;
if ( V_208 > V_209 )
V_208 = V_209 ;
V_110 . V_207 [ 0 ] = V_208 ;
memcpy ( V_110 . V_207 + 1 , V_205 , V_208 ) ;
return F_202 ( V_5 -> V_66 , V_5 -> V_63 , V_5 -> V_45 ,
V_184 , V_157 ,
V_210 , & V_110 ) ;
}
static T_12 F_225 ( struct V_20 * V_66 , T_3 V_63 ,
unsigned short V_45 ,
char V_211 , T_11 V_157 , int V_212 ,
union V_177 * V_110 )
{
unsigned char V_213 [ V_209 + 3 ] ;
unsigned char V_214 [ V_209 + 2 ] ;
int V_166 = V_211 == V_181 ? 2 : 1 ;
int V_33 ;
T_11 V_215 = 0 ;
int V_43 ;
struct V_164 V_174 [ 2 ] = {
{
. V_63 = V_63 ,
. V_45 = V_45 ,
. V_60 = 1 ,
. V_58 = V_213 ,
} , {
. V_63 = V_63 ,
. V_45 = V_45 | V_169 ,
. V_60 = 0 ,
. V_58 = V_214 ,
} ,
} ;
V_213 [ 0 ] = V_157 ;
switch ( V_212 ) {
case V_185 :
V_174 [ 0 ] . V_60 = 0 ;
V_174 [ 0 ] . V_45 = V_45 | ( V_211 == V_181 ?
V_169 : 0 ) ;
V_166 = 1 ;
break;
case V_187 :
if ( V_211 == V_181 ) {
V_174 [ 0 ] . V_45 = V_169 | V_45 ;
V_166 = 1 ;
}
break;
case V_182 :
if ( V_211 == V_181 )
V_174 [ 1 ] . V_60 = 1 ;
else {
V_174 [ 0 ] . V_60 = 2 ;
V_213 [ 1 ] = V_110 -> V_201 ;
}
break;
case V_203 :
if ( V_211 == V_181 )
V_174 [ 1 ] . V_60 = 2 ;
else {
V_174 [ 0 ] . V_60 = 3 ;
V_213 [ 1 ] = V_110 -> V_204 & 0xff ;
V_213 [ 2 ] = V_110 -> V_204 >> 8 ;
}
break;
case V_216 :
V_166 = 2 ;
V_211 = V_181 ;
V_174 [ 0 ] . V_60 = 3 ;
V_174 [ 1 ] . V_60 = 2 ;
V_213 [ 1 ] = V_110 -> V_204 & 0xff ;
V_213 [ 2 ] = V_110 -> V_204 >> 8 ;
break;
case V_206 :
if ( V_211 == V_181 ) {
V_174 [ 1 ] . V_45 |= V_173 ;
V_174 [ 1 ] . V_60 = 1 ;
} else {
V_174 [ 0 ] . V_60 = V_110 -> V_207 [ 0 ] + 2 ;
if ( V_174 [ 0 ] . V_60 > V_209 + 2 ) {
F_27 ( & V_66 -> V_8 ,
L_87 ,
V_110 -> V_207 [ 0 ] ) ;
return - V_64 ;
}
for ( V_33 = 1 ; V_33 < V_174 [ 0 ] . V_60 ; V_33 ++ )
V_213 [ V_33 ] = V_110 -> V_207 [ V_33 - 1 ] ;
}
break;
case V_217 :
V_166 = 2 ;
V_211 = V_181 ;
if ( V_110 -> V_207 [ 0 ] > V_209 ) {
F_27 ( & V_66 -> V_8 ,
L_87 ,
V_110 -> V_207 [ 0 ] ) ;
return - V_64 ;
}
V_174 [ 0 ] . V_60 = V_110 -> V_207 [ 0 ] + 2 ;
for ( V_33 = 1 ; V_33 < V_174 [ 0 ] . V_60 ; V_33 ++ )
V_213 [ V_33 ] = V_110 -> V_207 [ V_33 - 1 ] ;
V_174 [ 1 ] . V_45 |= V_173 ;
V_174 [ 1 ] . V_60 = 1 ;
break;
case V_210 :
if ( V_211 == V_181 ) {
V_174 [ 1 ] . V_60 = V_110 -> V_207 [ 0 ] ;
} else {
V_174 [ 0 ] . V_60 = V_110 -> V_207 [ 0 ] + 1 ;
if ( V_174 [ 0 ] . V_60 > V_209 + 1 ) {
F_27 ( & V_66 -> V_8 ,
L_87 ,
V_110 -> V_207 [ 0 ] ) ;
return - V_64 ;
}
for ( V_33 = 1 ; V_33 <= V_110 -> V_207 [ 0 ] ; V_33 ++ )
V_213 [ V_33 ] = V_110 -> V_207 [ V_33 ] ;
}
break;
default:
F_27 ( & V_66 -> V_8 , L_88 , V_212 ) ;
return - V_41 ;
}
V_33 = ( ( V_45 & V_218 ) && V_212 != V_185
&& V_212 != V_210 ) ;
if ( V_33 ) {
if ( ! ( V_174 [ 0 ] . V_45 & V_169 ) ) {
if ( V_166 == 1 )
F_213 ( & V_174 [ 0 ] ) ;
else
V_215 = F_212 ( 0 , & V_174 [ 0 ] ) ;
}
if ( V_174 [ V_166 - 1 ] . V_45 & V_169 )
V_174 [ V_166 - 1 ] . V_60 ++ ;
}
V_43 = F_193 ( V_66 , V_174 , V_166 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_33 && ( V_174 [ V_166 - 1 ] . V_45 & V_169 ) ) {
V_43 = F_214 ( V_215 , & V_174 [ V_166 - 1 ] ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_211 == V_181 )
switch ( V_212 ) {
case V_187 :
V_110 -> V_201 = V_213 [ 0 ] ;
break;
case V_182 :
V_110 -> V_201 = V_214 [ 0 ] ;
break;
case V_203 :
case V_216 :
V_110 -> V_204 = V_214 [ 0 ] | ( V_214 [ 1 ] << 8 ) ;
break;
case V_210 :
for ( V_33 = 0 ; V_33 < V_110 -> V_207 [ 0 ] ; V_33 ++ )
V_110 -> V_207 [ V_33 + 1 ] = V_214 [ V_33 ] ;
break;
case V_206 :
case V_217 :
for ( V_33 = 0 ; V_33 < V_214 [ 0 ] + 1 ; V_33 ++ )
V_110 -> V_207 [ V_33 ] = V_214 [ V_33 ] ;
break;
}
return 0 ;
}
T_12 F_202 ( struct V_20 * V_66 , T_3 V_63 , unsigned short V_45 ,
char V_211 , T_11 V_157 , int V_219 ,
union V_177 * V_110 )
{
unsigned long V_167 ;
int V_168 ;
T_12 V_92 ;
F_226 ( V_66 , V_63 , V_45 , V_211 ,
V_157 , V_219 , V_110 ) ;
F_227 ( V_66 , V_63 , V_45 , V_211 ,
V_157 , V_219 ) ;
V_45 &= V_175 | V_218 | V_220 ;
if ( V_66 -> V_139 -> V_221 ) {
F_67 ( V_66 ) ;
V_167 = V_170 ;
for ( V_92 = 0 , V_168 = 0 ; V_168 <= V_66 -> V_171 ; V_168 ++ ) {
V_92 = V_66 -> V_139 -> V_221 ( V_66 , V_63 , V_45 ,
V_211 , V_157 ,
V_219 , V_110 ) ;
if ( V_92 != - V_137 )
break;
if ( F_190 ( V_170 ,
V_167 + V_66 -> V_140 ) )
break;
}
F_71 ( V_66 ) ;
if ( V_92 != - V_41 || ! V_66 -> V_139 -> V_172 )
goto V_222;
}
V_92 = F_225 ( V_66 , V_63 , V_45 , V_211 ,
V_157 , V_219 , V_110 ) ;
V_222:
F_228 ( V_66 , V_63 , V_45 , V_211 ,
V_157 , V_219 , V_110 ) ;
F_229 ( V_66 , V_63 , V_45 , V_211 ,
V_157 , V_219 , V_92 ) ;
return V_92 ;
}
