static const struct V_1 * F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
while ( V_2 -> V_5 [ 0 ] ) {
if ( strcmp ( V_4 -> V_5 , V_2 -> V_5 ) == 0 )
return V_2 ;
V_2 ++ ;
}
return NULL ;
}
static int F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 )
return 0 ;
if ( F_4 ( V_7 , V_9 ) )
return 1 ;
if ( F_5 ( V_7 , V_9 ) )
return 1 ;
V_11 = F_6 ( V_9 ) ;
if ( V_11 -> V_12 )
return F_1 ( V_11 -> V_12 , V_4 ) != NULL ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_13 * V_14 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
if ( F_9 ( V_14 , L_1 ,
V_15 , V_4 -> V_5 ) )
return - V_16 ;
F_10 ( V_7 , L_2 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
return F_12 ( V_18 -> V_19 -> V_20 ) ;
}
static void F_13 ( struct V_17 * V_18 , int V_21 )
{
F_14 ( V_18 -> V_19 -> V_20 , V_21 ) ;
}
static int F_15 ( struct V_17 * V_18 )
{
return F_12 ( V_18 -> V_19 -> V_22 ) ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_19 ;
struct V_6 * V_7 = & V_18 -> V_7 ;
int V_25 = 0 ;
V_25 = F_17 ( V_24 -> V_20 , V_26 |
V_27 , L_3 ) ;
if ( V_25 ) {
F_18 ( V_7 , L_4 , V_24 -> V_20 ) ;
return V_25 ;
}
if ( V_24 -> V_28 ) {
if ( F_17 ( V_24 -> V_22 , V_29 , L_5 ) ) {
F_18 ( V_7 , L_6 ,
V_24 -> V_22 ) ;
V_24 -> V_28 = NULL ;
}
}
return V_25 ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_19 ;
if ( V_24 -> V_28 )
F_20 ( V_24 -> V_22 ) ;
F_20 ( V_24 -> V_20 ) ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_19 ;
int V_30 = 0 , V_21 = 1 , V_25 = 0 ;
if ( V_24 -> V_31 )
V_24 -> V_31 ( V_24 ) ;
while ( V_30 ++ < V_32 * 2 ) {
if ( V_21 ) {
if ( V_24 -> V_28 && V_24 -> V_28 ( V_18 ) )
break;
if ( ! V_24 -> V_33 ( V_18 ) ) {
F_22 ( & V_18 -> V_7 ,
L_7 ) ;
V_25 = - V_34 ;
break;
}
}
V_21 = ! V_21 ;
V_24 -> V_35 ( V_18 , V_21 ) ;
F_23 ( V_36 ) ;
}
if ( V_24 -> V_37 )
V_24 -> V_37 ( V_24 ) ;
return V_25 ;
}
int F_24 ( struct V_17 * V_18 )
{
V_18 -> V_19 -> V_35 ( V_18 , 1 ) ;
return F_21 ( V_18 ) ;
}
int F_25 ( struct V_17 * V_18 )
{
int V_25 ;
V_25 = F_16 ( V_18 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_21 ( V_18 ) ;
F_19 ( V_18 ) ;
return V_25 ;
}
int F_26 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_19 )
return - V_38 ;
F_10 ( & V_18 -> V_7 , L_8 ) ;
return V_18 -> V_19 -> V_39 ( V_18 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_40 ;
if ( ! V_4 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_41 || ! V_11 -> V_12 )
return - V_42 ;
V_4 -> V_11 = V_11 ;
if ( ! F_28 ( & V_4 -> V_7 ) )
F_29 ( & V_4 -> V_7 ,
V_4 -> V_43 & V_44 ) ;
F_10 ( V_7 , L_9 ) ;
V_40 = V_11 -> V_41 ( V_4 , F_1 ( V_11 -> V_12 , V_4 ) ) ;
if ( V_40 ) {
V_4 -> V_11 = NULL ;
F_30 ( V_4 , NULL ) ;
}
return V_40 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_40 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> remove ) {
F_10 ( V_7 , L_10 ) ;
V_40 = V_11 -> remove ( V_4 ) ;
} else {
V_7 -> V_11 = NULL ;
V_40 = 0 ;
}
if ( V_40 == 0 ) {
V_4 -> V_11 = NULL ;
F_30 ( V_4 , NULL ) ;
}
return V_40 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> V_45 )
V_11 -> V_45 ( V_4 ) ;
}
static int F_33 ( struct V_6 * V_7 , T_1 V_46 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_47 )
return 0 ;
return V_11 -> V_47 ( V_4 , V_46 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_48 )
return 0 ;
return V_11 -> V_48 ( V_4 ) ;
}
static int F_35 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_36 ( V_7 ) ;
else
return F_33 ( V_7 , V_51 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_38 ( V_7 ) ;
else
return F_34 ( V_7 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_40 ( V_7 ) ;
else
return F_33 ( V_7 , V_52 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_42 ( V_7 ) ;
else
return F_34 ( V_7 ) ;
}
static int F_43 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_44 ( V_7 ) ;
else
return F_33 ( V_7 , V_53 ) ;
}
static int F_45 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_46 ( V_7 ) ;
else
return F_34 ( V_7 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
F_48 ( F_8 ( V_7 ) ) ;
}
static T_2
F_49 ( struct V_6 * V_7 , struct V_54 * V_55 , char * V_56 )
{
return sprintf ( V_56 , L_11 , V_7 -> type == & V_57 ?
F_8 ( V_7 ) -> V_5 : F_50 ( V_7 ) -> V_5 ) ;
}
static T_2
F_51 ( struct V_6 * V_7 , struct V_54 * V_55 , char * V_56 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_56 , L_12 , V_15 , V_4 -> V_5 ) ;
}
struct V_3 * F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_57 )
? F_8 ( V_7 )
: NULL ;
}
static int F_52 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_43 & V_58 ) {
if ( V_4 -> V_59 > 0x3ff )
return - V_60 ;
} else {
if ( V_4 -> V_59 == 0x00 || V_4 -> V_59 > 0x7f )
return - V_60 ;
}
return 0 ;
}
static int F_53 ( unsigned short V_59 )
{
if ( V_59 < 0x08 || V_59 > 0x77 )
return - V_60 ;
return 0 ;
}
static int F_54 ( struct V_6 * V_7 , void * V_61 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
int V_59 = * ( int * ) V_61 ;
if ( V_4 && V_4 -> V_59 == V_59 )
return - V_34 ;
return 0 ;
}
static int F_55 ( struct V_17 * V_62 , int V_59 )
{
struct V_17 * V_63 = F_56 ( V_62 ) ;
int V_64 ;
V_64 = F_57 ( & V_62 -> V_7 , & V_59 ,
F_54 ) ;
if ( ! V_64 && V_63 )
V_64 = F_55 ( V_63 , V_59 ) ;
return V_64 ;
}
static int F_58 ( struct V_6 * V_7 , void * V_61 )
{
int V_64 ;
if ( V_7 -> type == & V_65 )
V_64 = F_57 ( V_7 , V_61 ,
F_58 ) ;
else
V_64 = F_54 ( V_7 , V_61 ) ;
return V_64 ;
}
static int F_59 ( struct V_17 * V_62 , int V_59 )
{
struct V_17 * V_63 = F_56 ( V_62 ) ;
int V_64 = 0 ;
if ( V_63 )
V_64 = F_55 ( V_63 , V_59 ) ;
if ( ! V_64 )
V_64 = F_57 ( & V_62 -> V_7 , & V_59 ,
F_58 ) ;
return V_64 ;
}
void F_60 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_56 ( V_62 ) ;
if ( V_63 )
F_60 ( V_63 ) ;
else
F_61 ( & V_62 -> V_66 ) ;
}
static int F_62 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_56 ( V_62 ) ;
if ( V_63 )
return F_62 ( V_63 ) ;
else
return F_63 ( & V_62 -> V_66 ) ;
}
void F_64 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_56 ( V_62 ) ;
if ( V_63 )
F_64 ( V_63 ) ;
else
F_65 ( & V_62 -> V_66 ) ;
}
struct V_3 *
F_66 ( struct V_17 * V_18 , struct V_67 const * V_68 )
{
struct V_3 * V_4 ;
int V_40 ;
V_4 = F_67 ( sizeof *V_4 , V_69 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_62 = V_18 ;
V_4 -> V_7 . V_70 = V_68 -> V_70 ;
if ( V_68 -> V_71 )
V_4 -> V_7 . V_71 = * V_68 -> V_71 ;
V_4 -> V_43 = V_68 -> V_43 ;
V_4 -> V_59 = V_68 -> V_59 ;
V_4 -> V_72 = V_68 -> V_72 ;
F_68 ( V_4 -> V_5 , V_68 -> type , sizeof( V_4 -> V_5 ) ) ;
V_40 = F_52 ( V_4 ) ;
if ( V_40 ) {
F_22 ( & V_18 -> V_7 , L_13 ,
V_4 -> V_43 & V_58 ? 10 : 7 , V_4 -> V_59 ) ;
goto V_73;
}
V_40 = F_59 ( V_18 , V_4 -> V_59 ) ;
if ( V_40 )
goto V_74;
V_4 -> V_7 . V_63 = & V_4 -> V_62 -> V_7 ;
V_4 -> V_7 . V_75 = & V_76 ;
V_4 -> V_7 . type = & V_57 ;
V_4 -> V_7 . V_77 = V_68 -> V_77 ;
F_69 ( & V_4 -> V_7 , V_68 -> V_78 . V_79 ) ;
F_70 ( & V_4 -> V_7 , L_14 , F_71 ( V_18 ) ,
V_4 -> V_59 | ( ( V_4 -> V_43 & V_58 )
? 0xa000 : 0 ) ) ;
V_40 = F_72 ( & V_4 -> V_7 ) ;
if ( V_40 )
goto V_74;
F_10 ( & V_18 -> V_7 , L_15 ,
V_4 -> V_5 , F_73 ( & V_4 -> V_7 ) ) ;
return V_4 ;
V_74:
F_22 ( & V_18 -> V_7 , L_16
L_17 , V_4 -> V_5 , V_4 -> V_59 , V_40 ) ;
V_73:
F_48 ( V_4 ) ;
return NULL ;
}
void F_74 ( struct V_3 * V_4 )
{
F_75 ( & V_4 -> V_7 ) ;
}
static int F_76 ( struct V_3 * V_4 ,
const struct V_1 * V_2 )
{
return 0 ;
}
static int F_77 ( struct V_3 * V_4 )
{
return 0 ;
}
struct V_3 * F_78 ( struct V_17 * V_62 , T_3 V_80 )
{
struct V_67 V_68 = {
F_79 ( L_18 , V_80 ) ,
} ;
return F_66 ( V_62 , & V_68 ) ;
}
static void F_80 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_50 ( V_7 ) ;
F_81 ( & V_18 -> V_81 ) ;
}
static inline unsigned int F_82 ( struct V_17 * V_62 )
{
unsigned int V_82 = 0 ;
while ( ( V_62 = F_56 ( V_62 ) ) )
V_82 ++ ;
return V_82 ;
}
static T_2
F_83 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_4 V_83 )
{
struct V_17 * V_18 = F_50 ( V_7 ) ;
struct V_67 V_68 ;
struct V_3 * V_4 ;
char * V_84 , V_85 ;
int V_86 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_84 = strchr ( V_56 , ' ' ) ;
if ( ! V_84 ) {
F_22 ( V_7 , L_19 , L_20 ) ;
return - V_60 ;
}
if ( V_84 - V_56 > V_87 - 1 ) {
F_22 ( V_7 , L_21 , L_20 ) ;
return - V_60 ;
}
memcpy ( V_68 . type , V_56 , V_84 - V_56 ) ;
V_86 = sscanf ( ++ V_84 , L_22 , & V_68 . V_59 , & V_85 ) ;
if ( V_86 < 1 ) {
F_22 ( V_7 , L_23 , L_20 ) ;
return - V_60 ;
}
if ( V_86 > 1 && V_85 != '\n' ) {
F_22 ( V_7 , L_24 , L_20 ) ;
return - V_60 ;
}
V_4 = F_66 ( V_18 , & V_68 ) ;
if ( ! V_4 )
return - V_60 ;
F_84 ( & V_18 -> V_88 ) ;
F_85 ( & V_4 -> V_89 , & V_18 -> V_90 ) ;
F_86 ( & V_18 -> V_88 ) ;
F_87 ( V_7 , L_25 , L_20 ,
V_68 . type , V_68 . V_59 ) ;
return V_83 ;
}
static T_2
F_88 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_4 V_83 )
{
struct V_17 * V_18 = F_50 ( V_7 ) ;
struct V_3 * V_4 , * V_91 ;
unsigned short V_59 ;
char V_85 ;
int V_86 ;
V_86 = sscanf ( V_56 , L_22 , & V_59 , & V_85 ) ;
if ( V_86 < 1 ) {
F_22 ( V_7 , L_23 , L_26 ) ;
return - V_60 ;
}
if ( V_86 > 1 && V_85 != '\n' ) {
F_22 ( V_7 , L_24 , L_26 ) ;
return - V_60 ;
}
V_86 = - V_92 ;
F_89 ( & V_18 -> V_88 ,
F_82 ( V_18 ) ) ;
F_90 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_59 == V_59 ) {
F_87 ( V_7 , L_27 ,
L_26 , V_4 -> V_5 , V_4 -> V_59 ) ;
F_91 ( & V_4 -> V_89 ) ;
F_74 ( V_4 ) ;
V_86 = V_83 ;
break;
}
}
F_86 ( & V_18 -> V_88 ) ;
if ( V_86 < 0 )
F_22 ( V_7 , L_28 ,
L_26 ) ;
return V_86 ;
}
struct V_17 * F_92 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_65 )
? F_50 ( V_7 )
: NULL ;
}
static void F_93 ( struct V_17 * V_62 )
{
struct V_93 * V_94 ;
F_94 ( & V_95 ) ;
F_95 (devinfo, &__i2c_board_list, list) {
if ( V_94 -> V_96 == V_62 -> V_97
&& ! F_66 ( V_62 ,
& V_94 -> V_98 ) )
F_22 ( & V_62 -> V_7 ,
L_29 ,
V_94 -> V_98 . V_59 ) ;
}
F_96 ( & V_95 ) ;
}
static void F_97 ( struct V_17 * V_18 )
{
void * V_64 ;
struct V_99 * V_100 ;
if ( ! V_18 -> V_7 . V_77 )
return;
F_10 ( & V_18 -> V_7 , L_30 ) ;
F_98 (adap->dev.of_node, node) {
struct V_67 V_68 = {} ;
struct V_101 V_102 = {} ;
const T_5 * V_59 ;
int V_103 ;
F_10 ( & V_18 -> V_7 , L_31 , V_100 -> V_104 ) ;
if ( F_99 ( V_100 , V_68 . type , sizeof( V_68 . type ) ) < 0 ) {
F_22 ( & V_18 -> V_7 , L_32 ,
V_100 -> V_104 ) ;
continue;
}
V_59 = F_100 ( V_100 , L_33 , & V_103 ) ;
if ( ! V_59 || ( V_103 < sizeof( int ) ) ) {
F_22 ( & V_18 -> V_7 , L_34 ,
V_100 -> V_104 ) ;
continue;
}
V_68 . V_59 = F_101 ( V_59 ) ;
if ( V_68 . V_59 > ( 1 << 10 ) - 1 ) {
F_22 ( & V_18 -> V_7 , L_35 ,
V_68 . V_59 , V_100 -> V_104 ) ;
continue;
}
V_68 . V_72 = F_102 ( V_100 , 0 ) ;
V_68 . V_77 = F_103 ( V_100 ) ;
V_68 . V_71 = & V_102 ;
if ( F_100 ( V_100 , L_36 , NULL ) )
V_68 . V_43 |= V_44 ;
F_104 ( L_37 , V_15 , V_68 . type ) ;
V_64 = F_66 ( V_18 , & V_68 ) ;
if ( V_64 == NULL ) {
F_22 ( & V_18 -> V_7 , L_38 ,
V_100 -> V_104 ) ;
F_105 ( V_100 ) ;
F_106 ( V_68 . V_72 ) ;
continue;
}
}
}
static int F_107 ( struct V_6 * V_7 , void * V_105 )
{
return V_7 -> V_77 == V_105 ;
}
struct V_3 * F_108 ( struct V_99 * V_100 )
{
struct V_6 * V_7 ;
V_7 = F_109 ( & V_76 , NULL , V_100 ,
F_107 ) ;
if ( ! V_7 )
return NULL ;
return F_3 ( V_7 ) ;
}
struct V_17 * F_110 ( struct V_99 * V_100 )
{
struct V_6 * V_7 ;
V_7 = F_109 ( & V_76 , NULL , V_100 ,
F_107 ) ;
if ( ! V_7 )
return NULL ;
return F_92 ( V_7 ) ;
}
static void F_97 ( struct V_17 * V_18 ) { }
static int F_111 ( struct V_106 * V_107 , void * V_105 )
{
struct V_67 * V_68 = V_105 ;
if ( V_107 -> type == V_108 ) {
struct V_109 * V_110 ;
V_110 = & V_107 -> V_105 . V_111 ;
if ( V_110 -> type == V_112 ) {
V_68 -> V_59 = V_110 -> V_113 ;
if ( V_110 -> V_114 == V_115 )
V_68 -> V_43 |= V_58 ;
}
} else if ( V_68 -> V_72 < 0 ) {
struct V_116 V_117 ;
if ( F_112 ( V_107 , 0 , & V_117 ) )
V_68 -> V_72 = V_117 . V_118 ;
}
return 1 ;
}
static T_6 F_113 ( T_7 V_79 , T_8 V_119 ,
void * V_105 , void * * V_120 )
{
struct V_17 * V_62 = V_105 ;
struct V_121 V_122 ;
struct V_67 V_68 ;
struct V_123 * V_124 ;
int V_25 ;
if ( F_114 ( V_79 , & V_124 ) )
return V_125 ;
if ( F_115 ( V_124 ) || ! V_124 -> V_40 . V_126 )
return V_125 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_78 . V_79 = V_79 ;
V_68 . V_72 = - 1 ;
F_116 ( & V_122 ) ;
V_25 = F_117 ( V_124 , & V_122 ,
F_111 , & V_68 ) ;
F_118 ( & V_122 ) ;
if ( V_25 < 0 || ! V_68 . V_59 )
return V_125 ;
F_68 ( V_68 . type , F_73 ( & V_124 -> V_7 ) , sizeof( V_68 . type ) ) ;
if ( ! F_66 ( V_62 , & V_68 ) ) {
F_22 ( & V_62 -> V_7 ,
L_39 ,
F_73 ( & V_124 -> V_7 ) ) ;
}
return V_125 ;
}
static void F_119 ( struct V_17 * V_18 )
{
T_7 V_79 ;
T_6 V_40 ;
if ( ! V_18 -> V_7 . V_63 )
return;
V_79 = F_120 ( V_18 -> V_7 . V_63 ) ;
if ( ! V_79 )
return;
V_40 = F_121 ( V_127 , V_79 , 1 ,
F_113 , NULL ,
V_18 , NULL ) ;
if ( F_122 ( V_40 ) )
F_18 ( & V_18 -> V_7 , L_40 ) ;
}
static inline void F_119 ( struct V_17 * V_18 ) {}
static int F_123 ( struct V_10 * V_11 ,
struct V_17 * V_18 )
{
F_124 ( V_18 , V_11 ) ;
if ( V_11 -> V_128 ) {
F_18 ( & V_18 -> V_7 , L_41 ,
V_11 -> V_11 . V_5 ) ;
F_18 ( & V_18 -> V_7 , L_42
L_43 ) ;
V_11 -> V_128 ( V_18 ) ;
}
return 0 ;
}
static int F_125 ( struct V_8 * V_129 , void * V_105 )
{
return F_123 ( F_6 ( V_129 ) , V_105 ) ;
}
static int F_126 ( struct V_17 * V_18 )
{
int V_86 = 0 ;
if ( F_127 ( F_128 ( ! V_76 . V_130 ) ) ) {
V_86 = - V_131 ;
goto V_132;
}
if ( F_127 ( V_18 -> V_5 [ 0 ] == '\0' ) ) {
F_129 ( L_44
L_45 ) ;
return - V_60 ;
}
if ( F_127 ( ! V_18 -> V_133 ) ) {
F_129 ( L_46
L_47 , V_18 -> V_5 ) ;
return - V_60 ;
}
F_130 ( & V_18 -> V_66 ) ;
F_131 ( & V_18 -> V_88 ) ;
F_116 ( & V_18 -> V_90 ) ;
if ( V_18 -> V_134 == 0 )
V_18 -> V_134 = V_135 ;
F_70 ( & V_18 -> V_7 , L_48 , V_18 -> V_97 ) ;
V_18 -> V_7 . V_75 = & V_76 ;
V_18 -> V_7 . type = & V_65 ;
V_86 = F_72 ( & V_18 -> V_7 ) ;
if ( V_86 )
goto V_132;
F_10 ( & V_18 -> V_7 , L_49 , V_18 -> V_5 ) ;
#ifdef F_132
V_86 = F_133 ( V_136 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
if ( V_86 )
F_18 ( & V_18 -> V_7 ,
L_50 ) ;
#endif
if ( V_18 -> V_19 ) {
struct V_23 * V_24 = V_18 -> V_19 ;
if ( ! V_24 -> V_39 ) {
F_22 ( & V_18 -> V_7 , L_51 ) ;
V_18 -> V_19 = NULL ;
goto V_137;
}
if ( V_24 -> V_39 == F_25 ) {
if ( ! F_134 ( V_24 -> V_20 ) ) {
F_22 ( & V_18 -> V_7 , L_52 ) ;
V_18 -> V_19 = NULL ;
goto V_137;
}
if ( F_134 ( V_24 -> V_22 ) )
V_24 -> V_28 = F_15 ;
else
V_24 -> V_28 = NULL ;
V_24 -> V_33 = F_11 ;
V_24 -> V_35 = F_13 ;
} else if ( ! V_24 -> V_35 || ! V_24 -> V_33 ) {
F_22 ( & V_18 -> V_7 , L_53 ) ;
V_18 -> V_19 = NULL ;
}
}
V_137:
F_97 ( V_18 ) ;
F_119 ( V_18 ) ;
if ( V_18 -> V_97 < V_138 )
F_93 ( V_18 ) ;
F_84 ( & V_139 ) ;
F_135 ( & V_76 , NULL , V_18 , F_125 ) ;
F_86 ( & V_139 ) ;
return 0 ;
V_132:
F_84 ( & V_139 ) ;
F_136 ( & V_140 , V_18 -> V_97 ) ;
F_86 ( & V_139 ) ;
return V_86 ;
}
static int F_137 ( struct V_17 * V_18 )
{
int V_2 ;
F_84 ( & V_139 ) ;
V_2 = F_138 ( & V_140 , V_18 , V_18 -> V_97 , V_18 -> V_97 + 1 ,
V_69 ) ;
F_86 ( & V_139 ) ;
if ( V_2 < 0 )
return V_2 == - V_141 ? - V_34 : V_2 ;
return F_126 ( V_18 ) ;
}
int F_139 ( struct V_17 * V_62 )
{
struct V_6 * V_7 = & V_62 -> V_7 ;
int V_2 ;
if ( V_7 -> V_77 ) {
V_2 = F_140 ( V_7 -> V_77 , L_54 ) ;
if ( V_2 >= 0 ) {
V_62 -> V_97 = V_2 ;
return F_137 ( V_62 ) ;
}
}
F_84 ( & V_139 ) ;
V_2 = F_138 ( & V_140 , V_62 ,
V_138 , 0 , V_69 ) ;
F_86 ( & V_139 ) ;
if ( V_2 < 0 )
return V_2 ;
V_62 -> V_97 = V_2 ;
return F_126 ( V_62 ) ;
}
int F_141 ( struct V_17 * V_18 )
{
if ( V_18 -> V_97 == - 1 )
return F_139 ( V_18 ) ;
return F_137 ( V_18 ) ;
}
static void F_142 ( struct V_10 * V_11 ,
struct V_17 * V_62 )
{
struct V_3 * V_4 , * V_142 ;
F_90 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_62 == V_62 ) {
F_10 ( & V_62 -> V_7 , L_55 ,
V_4 -> V_5 , V_4 -> V_59 ) ;
F_91 ( & V_4 -> V_89 ) ;
F_74 ( V_4 ) ;
}
}
}
static int F_143 ( struct V_6 * V_7 , void * V_143 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_18 ) )
F_74 ( V_4 ) ;
return 0 ;
}
static int F_144 ( struct V_6 * V_7 , void * V_143 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_74 ( V_4 ) ;
return 0 ;
}
static int F_145 ( struct V_8 * V_129 , void * V_105 )
{
F_142 ( F_6 ( V_129 ) , V_105 ) ;
return 0 ;
}
void F_146 ( struct V_17 * V_18 )
{
struct V_17 * V_144 ;
struct V_3 * V_4 , * V_91 ;
F_84 ( & V_139 ) ;
V_144 = F_147 ( & V_140 , V_18 -> V_97 ) ;
F_86 ( & V_139 ) ;
if ( V_144 != V_18 ) {
F_148 ( L_56
L_57 , V_18 -> V_5 ) ;
return;
}
F_84 ( & V_139 ) ;
F_135 ( & V_76 , NULL , V_18 ,
F_145 ) ;
F_86 ( & V_139 ) ;
F_89 ( & V_18 -> V_88 ,
F_82 ( V_18 ) ) ;
F_90 (client, next, &adap->userspace_clients,
detected) {
F_10 ( & V_18 -> V_7 , L_55 , V_4 -> V_5 ,
V_4 -> V_59 ) ;
F_91 ( & V_4 -> V_89 ) ;
F_74 ( V_4 ) ;
}
F_86 ( & V_18 -> V_88 ) ;
F_57 ( & V_18 -> V_7 , NULL , F_143 ) ;
F_57 ( & V_18 -> V_7 , NULL , F_144 ) ;
#ifdef F_132
F_149 ( V_136 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
#endif
F_10 ( & V_18 -> V_7 , L_58 , V_18 -> V_5 ) ;
F_150 ( & V_18 -> V_81 ) ;
F_75 ( & V_18 -> V_7 ) ;
F_151 ( & V_18 -> V_81 ) ;
F_84 ( & V_139 ) ;
F_136 ( & V_140 , V_18 -> V_97 ) ;
F_86 ( & V_139 ) ;
memset ( & V_18 -> V_7 , 0 , sizeof( V_18 -> V_7 ) ) ;
}
int F_152 ( void * V_105 , int (* F_153)( struct V_6 * , void * ) )
{
int V_86 ;
F_84 ( & V_139 ) ;
V_86 = F_154 ( & V_76 , NULL , V_105 , F_153 ) ;
F_86 ( & V_139 ) ;
return V_86 ;
}
static int F_155 ( struct V_6 * V_7 , void * V_105 )
{
if ( V_7 -> type != & V_65 )
return 0 ;
return F_123 ( V_105 , F_50 ( V_7 ) ) ;
}
int F_156 ( struct V_145 * V_146 , struct V_10 * V_11 )
{
int V_86 ;
if ( F_127 ( F_128 ( ! V_76 . V_130 ) ) )
return - V_131 ;
V_11 -> V_11 . V_146 = V_146 ;
V_11 -> V_11 . V_75 = & V_76 ;
V_86 = F_157 ( & V_11 -> V_11 ) ;
if ( V_86 )
return V_86 ;
if ( V_11 -> V_47 )
F_158 ( L_59 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_48 )
F_158 ( L_60 ,
V_11 -> V_11 . V_5 ) ;
F_148 ( L_61 , V_11 -> V_11 . V_5 ) ;
F_116 ( & V_11 -> V_147 ) ;
F_152 ( V_11 , F_155 ) ;
return 0 ;
}
static int F_159 ( struct V_6 * V_7 , void * V_105 )
{
if ( V_7 -> type == & V_65 )
F_142 ( V_105 , F_50 ( V_7 ) ) ;
return 0 ;
}
void F_160 ( struct V_10 * V_11 )
{
F_152 ( V_11 , F_159 ) ;
F_161 ( & V_11 -> V_11 ) ;
F_148 ( L_62 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_162 ( struct V_3 * V_4 )
{
if ( V_4 && F_163 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_164 ( struct V_3 * V_4 )
{
if ( V_4 )
F_165 ( & V_4 -> V_7 ) ;
}
static int F_166 ( struct V_6 * V_7 , void * V_148 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_149 * V_150 = V_148 ;
if ( V_4 && V_4 -> V_11 && V_4 -> V_11 -> V_151 )
V_4 -> V_11 -> V_151 ( V_4 , V_150 -> V_152 , V_150 -> V_150 ) ;
return 0 ;
}
void F_167 ( struct V_17 * V_18 , unsigned int V_152 , void * V_150 )
{
struct V_149 V_153 ;
V_153 . V_152 = V_152 ;
V_153 . V_150 = V_150 ;
F_57 ( & V_18 -> V_7 , & V_153 , F_166 ) ;
}
static int T_9 F_168 ( void )
{
int V_154 ;
V_154 = F_169 ( & V_76 ) ;
if ( V_154 )
return V_154 ;
#ifdef F_132
V_136 = F_170 ( L_63 ) ;
if ( ! V_136 ) {
V_154 = - V_16 ;
goto V_155;
}
#endif
V_154 = F_171 ( & V_156 ) ;
if ( V_154 )
goto V_157;
return 0 ;
V_157:
#ifdef F_132
F_172 ( V_136 ) ;
V_155:
#endif
F_173 ( & V_76 ) ;
return V_154 ;
}
static void T_10 F_174 ( void )
{
F_160 ( & V_156 ) ;
#ifdef F_132
F_172 ( V_136 ) ;
#endif
F_173 ( & V_76 ) ;
}
int F_175 ( struct V_17 * V_18 , struct V_158 * V_159 , int V_160 )
{
unsigned long V_161 ;
int V_25 , V_162 ;
V_161 = V_163 ;
for ( V_25 = 0 , V_162 = 0 ; V_162 <= V_18 -> V_164 ; V_162 ++ ) {
V_25 = V_18 -> V_133 -> V_165 ( V_18 , V_159 , V_160 ) ;
if ( V_25 != - V_131 )
break;
if ( F_176 ( V_163 , V_161 + V_18 -> V_134 ) )
break;
}
return V_25 ;
}
int F_177 ( struct V_17 * V_18 , struct V_158 * V_159 , int V_160 )
{
int V_25 ;
if ( V_18 -> V_133 -> V_165 ) {
#ifdef F_178
for ( V_25 = 0 ; V_25 < V_160 ; V_25 ++ ) {
F_10 ( & V_18 -> V_7 , L_64
L_65 , V_25 , ( V_159 [ V_25 ] . V_43 & V_166 )
? 'R' : 'W' , V_159 [ V_25 ] . V_59 , V_159 [ V_25 ] . V_103 ,
( V_159 [ V_25 ] . V_43 & V_167 ) ? L_66 : L_67 ) ;
}
#endif
if ( F_179 () || F_180 () ) {
V_25 = F_62 ( V_18 ) ;
if ( ! V_25 )
return - V_131 ;
} else {
F_60 ( V_18 ) ;
}
V_25 = F_175 ( V_18 , V_159 , V_160 ) ;
F_64 ( V_18 ) ;
return V_25 ;
} else {
F_10 ( & V_18 -> V_7 , L_68 ) ;
return - V_38 ;
}
}
int F_181 ( const struct V_3 * V_4 , const char * V_56 , int V_83 )
{
int V_25 ;
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_158 V_168 ;
V_168 . V_59 = V_4 -> V_59 ;
V_168 . V_43 = V_4 -> V_43 & V_169 ;
V_168 . V_103 = V_83 ;
V_168 . V_56 = ( char * ) V_56 ;
V_25 = F_177 ( V_18 , & V_168 , 1 ) ;
return ( V_25 == 1 ) ? V_83 : V_25 ;
}
int F_182 ( const struct V_3 * V_4 , char * V_56 , int V_83 )
{
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_158 V_168 ;
int V_25 ;
V_168 . V_59 = V_4 -> V_59 ;
V_168 . V_43 = V_4 -> V_43 & V_169 ;
V_168 . V_43 |= V_166 ;
V_168 . V_103 = V_83 ;
V_168 . V_56 = V_56 ;
V_25 = F_177 ( V_18 , & V_168 , 1 ) ;
return ( V_25 == 1 ) ? V_83 : V_25 ;
}
static int F_183 ( struct V_17 * V_18 , unsigned short V_59 )
{
int V_170 ;
union V_171 V_143 ;
#ifdef F_184
if ( V_59 == 0x73 && ( V_18 -> V_172 & V_173 )
&& F_185 ( V_18 , V_174 ) )
V_170 = F_186 ( V_18 , V_59 , 0 , V_175 , 0 ,
V_176 , & V_143 ) ;
else
#endif
if ( ! ( ( V_59 & ~ 0x07 ) == 0x30 || ( V_59 & ~ 0x0f ) == 0x50 )
&& F_185 ( V_18 , V_177 ) )
V_170 = F_186 ( V_18 , V_59 , 0 , V_178 , 0 ,
V_179 , NULL ) ;
else if ( F_185 ( V_18 , V_180 ) )
V_170 = F_186 ( V_18 , V_59 , 0 , V_175 , 0 ,
V_181 , & V_143 ) ;
else {
F_18 ( & V_18 -> V_7 , L_69 ,
V_59 ) ;
V_170 = - V_38 ;
}
return V_170 >= 0 ;
}
static int F_187 ( struct V_3 * V_182 ,
struct V_10 * V_11 )
{
struct V_67 V_68 ;
struct V_17 * V_62 = V_182 -> V_62 ;
int V_59 = V_182 -> V_59 ;
int V_170 ;
V_170 = F_53 ( V_59 ) ;
if ( V_170 ) {
F_18 ( & V_62 -> V_7 , L_70 ,
V_59 ) ;
return V_170 ;
}
if ( F_59 ( V_62 , V_59 ) )
return 0 ;
if ( ! F_183 ( V_62 , V_59 ) )
return 0 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_59 = V_59 ;
V_170 = V_11 -> V_183 ( V_182 , & V_68 ) ;
if ( V_170 ) {
return V_170 == - V_42 ? 0 : V_170 ;
}
if ( V_68 . type [ 0 ] == '\0' ) {
F_22 ( & V_62 -> V_7 , L_71
L_72 , V_11 -> V_11 . V_5 ,
V_59 ) ;
} else {
struct V_3 * V_4 ;
F_10 ( & V_62 -> V_7 , L_73 ,
V_68 . type , V_68 . V_59 ) ;
V_4 = F_66 ( V_62 , & V_68 ) ;
if ( V_4 )
F_85 ( & V_4 -> V_89 , & V_11 -> V_147 ) ;
else
F_22 ( & V_62 -> V_7 , L_74 ,
V_68 . type , V_68 . V_59 ) ;
}
return 0 ;
}
static int F_124 ( struct V_17 * V_62 , struct V_10 * V_11 )
{
const unsigned short * V_184 ;
struct V_3 * V_182 ;
int V_30 , V_170 = 0 ;
int V_185 = F_71 ( V_62 ) ;
V_184 = V_11 -> V_184 ;
if ( ! V_11 -> V_183 || ! V_184 )
return 0 ;
if ( ! ( V_62 -> V_172 & V_11 -> V_172 ) )
return 0 ;
V_182 = F_67 ( sizeof( struct V_3 ) , V_69 ) ;
if ( ! V_182 )
return - V_16 ;
V_182 -> V_62 = V_62 ;
for ( V_30 = 0 ; V_184 [ V_30 ] != V_186 ; V_30 += 1 ) {
F_10 ( & V_62 -> V_7 , L_75
L_76 , V_185 , V_184 [ V_30 ] ) ;
V_182 -> V_59 = V_184 [ V_30 ] ;
V_170 = F_187 ( V_182 , V_11 ) ;
if ( F_127 ( V_170 ) )
break;
}
F_48 ( V_182 ) ;
return V_170 ;
}
int F_188 ( struct V_17 * V_18 , unsigned short V_59 )
{
return F_186 ( V_18 , V_59 , 0 , V_175 , 0 ,
V_179 , NULL ) >= 0 ;
}
struct V_3 *
F_189 ( struct V_17 * V_18 ,
struct V_67 * V_68 ,
unsigned short const * V_187 ,
int (* V_41)( struct V_17 * , unsigned short V_59 ) )
{
int V_30 ;
if ( ! V_41 )
V_41 = F_183 ;
for ( V_30 = 0 ; V_187 [ V_30 ] != V_186 ; V_30 ++ ) {
if ( F_53 ( V_187 [ V_30 ] ) < 0 ) {
F_18 ( & V_18 -> V_7 , L_77
L_78 , V_187 [ V_30 ] ) ;
continue;
}
if ( F_59 ( V_18 , V_187 [ V_30 ] ) ) {
F_10 ( & V_18 -> V_7 , L_79
L_80 , V_187 [ V_30 ] ) ;
continue;
}
if ( V_41 ( V_18 , V_187 [ V_30 ] ) )
break;
}
if ( V_187 [ V_30 ] == V_186 ) {
F_10 ( & V_18 -> V_7 , L_81 ) ;
return NULL ;
}
V_68 -> V_59 = V_187 [ V_30 ] ;
return F_66 ( V_18 , V_68 ) ;
}
struct V_17 * F_190 ( int V_97 )
{
struct V_17 * V_62 ;
F_84 ( & V_139 ) ;
V_62 = F_147 ( & V_140 , V_97 ) ;
if ( V_62 && ! F_191 ( V_62 -> V_146 ) )
V_62 = NULL ;
F_86 ( & V_139 ) ;
return V_62 ;
}
void F_192 ( struct V_17 * V_18 )
{
if ( V_18 )
F_193 ( V_18 -> V_146 ) ;
}
static T_11 F_194 ( T_3 V_105 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( V_105 & 0x8000 )
V_105 = V_105 ^ V_188 ;
V_105 = V_105 << 1 ;
}
return ( T_11 ) ( V_105 >> 8 ) ;
}
static T_11 F_195 ( T_11 V_189 , T_11 * V_130 , T_4 V_83 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_83 ; V_30 ++ )
V_189 = F_194 ( ( V_189 ^ V_130 [ V_30 ] ) << 8 ) ;
return V_189 ;
}
static T_11 F_196 ( T_11 V_190 , struct V_158 * V_168 )
{
T_11 V_59 = ( V_168 -> V_59 << 1 ) | ! ! ( V_168 -> V_43 & V_166 ) ;
V_190 = F_195 ( V_190 , & V_59 , 1 ) ;
return F_195 ( V_190 , V_168 -> V_56 , V_168 -> V_103 ) ;
}
static inline void F_197 ( struct V_158 * V_168 )
{
V_168 -> V_56 [ V_168 -> V_103 ] = F_196 ( 0 , V_168 ) ;
V_168 -> V_103 ++ ;
}
static int F_198 ( T_11 V_191 , struct V_158 * V_168 )
{
T_11 V_192 = V_168 -> V_56 [ -- V_168 -> V_103 ] ;
V_191 = F_196 ( V_191 , V_168 ) ;
if ( V_192 != V_191 ) {
F_148 ( L_82 ,
V_192 , V_191 ) ;
return - V_193 ;
}
return 0 ;
}
T_12 F_199 ( const struct V_3 * V_4 )
{
union V_171 V_105 ;
int V_40 ;
V_40 = F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_175 , 0 ,
V_181 , & V_105 ) ;
return ( V_40 < 0 ) ? V_40 : V_105 . V_194 ;
}
T_12 F_200 ( const struct V_3 * V_4 , T_11 V_195 )
{
return F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_195 , V_181 , NULL ) ;
}
T_12 F_201 ( const struct V_3 * V_4 , T_11 V_151 )
{
union V_171 V_105 ;
int V_40 ;
V_40 = F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_175 , V_151 ,
V_176 , & V_105 ) ;
return ( V_40 < 0 ) ? V_40 : V_105 . V_194 ;
}
T_12 F_202 ( const struct V_3 * V_4 , T_11 V_151 ,
T_11 V_195 )
{
union V_171 V_105 ;
V_105 . V_194 = V_195 ;
return F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_151 ,
V_176 , & V_105 ) ;
}
T_12 F_203 ( const struct V_3 * V_4 , T_11 V_151 )
{
union V_171 V_105 ;
int V_40 ;
V_40 = F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_175 , V_151 ,
V_196 , & V_105 ) ;
return ( V_40 < 0 ) ? V_40 : V_105 . V_197 ;
}
T_12 F_204 ( const struct V_3 * V_4 , T_11 V_151 ,
T_3 V_195 )
{
union V_171 V_105 ;
V_105 . V_197 = V_195 ;
return F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_151 ,
V_196 , & V_105 ) ;
}
T_12 F_205 ( const struct V_3 * V_4 , T_11 V_151 ,
T_11 * V_198 )
{
union V_171 V_105 ;
int V_40 ;
V_40 = F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_175 , V_151 ,
V_199 , & V_105 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_198 , & V_105 . V_200 [ 1 ] , V_105 . V_200 [ 0 ] ) ;
return V_105 . V_200 [ 0 ] ;
}
T_12 F_206 ( const struct V_3 * V_4 , T_11 V_151 ,
T_11 V_201 , const T_11 * V_198 )
{
union V_171 V_105 ;
if ( V_201 > V_202 )
V_201 = V_202 ;
V_105 . V_200 [ 0 ] = V_201 ;
memcpy ( & V_105 . V_200 [ 1 ] , V_198 , V_201 ) ;
return F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_151 ,
V_199 , & V_105 ) ;
}
T_12 F_207 ( const struct V_3 * V_4 , T_11 V_151 ,
T_11 V_201 , T_11 * V_198 )
{
union V_171 V_105 ;
int V_40 ;
if ( V_201 > V_202 )
V_201 = V_202 ;
V_105 . V_200 [ 0 ] = V_201 ;
V_40 = F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_175 , V_151 ,
V_203 , & V_105 ) ;
if ( V_40 < 0 )
return V_40 ;
memcpy ( V_198 , & V_105 . V_200 [ 1 ] , V_105 . V_200 [ 0 ] ) ;
return V_105 . V_200 [ 0 ] ;
}
T_12 F_208 ( const struct V_3 * V_4 , T_11 V_151 ,
T_11 V_201 , const T_11 * V_198 )
{
union V_171 V_105 ;
if ( V_201 > V_202 )
V_201 = V_202 ;
V_105 . V_200 [ 0 ] = V_201 ;
memcpy ( V_105 . V_200 + 1 , V_198 , V_201 ) ;
return F_186 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_151 ,
V_203 , & V_105 ) ;
}
static T_12 F_209 ( struct V_17 * V_62 , T_3 V_59 ,
unsigned short V_43 ,
char V_204 , T_11 V_151 , int V_205 ,
union V_171 * V_105 )
{
unsigned char V_206 [ V_202 + 3 ] ;
unsigned char V_207 [ V_202 + 2 ] ;
int V_160 = V_204 == V_175 ? 2 : 1 ;
int V_30 ;
T_11 V_208 = 0 ;
int V_40 ;
struct V_158 V_168 [ 2 ] = {
{
. V_59 = V_59 ,
. V_43 = V_43 ,
. V_103 = 1 ,
. V_56 = V_206 ,
} , {
. V_59 = V_59 ,
. V_43 = V_43 | V_166 ,
. V_103 = 0 ,
. V_56 = V_207 ,
} ,
} ;
V_206 [ 0 ] = V_151 ;
switch ( V_205 ) {
case V_179 :
V_168 [ 0 ] . V_103 = 0 ;
V_168 [ 0 ] . V_43 = V_43 | ( V_204 == V_175 ?
V_166 : 0 ) ;
V_160 = 1 ;
break;
case V_181 :
if ( V_204 == V_175 ) {
V_168 [ 0 ] . V_43 = V_166 | V_43 ;
V_160 = 1 ;
}
break;
case V_176 :
if ( V_204 == V_175 )
V_168 [ 1 ] . V_103 = 1 ;
else {
V_168 [ 0 ] . V_103 = 2 ;
V_206 [ 1 ] = V_105 -> V_194 ;
}
break;
case V_196 :
if ( V_204 == V_175 )
V_168 [ 1 ] . V_103 = 2 ;
else {
V_168 [ 0 ] . V_103 = 3 ;
V_206 [ 1 ] = V_105 -> V_197 & 0xff ;
V_206 [ 2 ] = V_105 -> V_197 >> 8 ;
}
break;
case V_209 :
V_160 = 2 ;
V_204 = V_175 ;
V_168 [ 0 ] . V_103 = 3 ;
V_168 [ 1 ] . V_103 = 2 ;
V_206 [ 1 ] = V_105 -> V_197 & 0xff ;
V_206 [ 2 ] = V_105 -> V_197 >> 8 ;
break;
case V_199 :
if ( V_204 == V_175 ) {
V_168 [ 1 ] . V_43 |= V_167 ;
V_168 [ 1 ] . V_103 = 1 ;
} else {
V_168 [ 0 ] . V_103 = V_105 -> V_200 [ 0 ] + 2 ;
if ( V_168 [ 0 ] . V_103 > V_202 + 2 ) {
F_22 ( & V_62 -> V_7 ,
L_83 ,
V_105 -> V_200 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 < V_168 [ 0 ] . V_103 ; V_30 ++ )
V_206 [ V_30 ] = V_105 -> V_200 [ V_30 - 1 ] ;
}
break;
case V_210 :
V_160 = 2 ;
V_204 = V_175 ;
if ( V_105 -> V_200 [ 0 ] > V_202 ) {
F_22 ( & V_62 -> V_7 ,
L_83 ,
V_105 -> V_200 [ 0 ] ) ;
return - V_60 ;
}
V_168 [ 0 ] . V_103 = V_105 -> V_200 [ 0 ] + 2 ;
for ( V_30 = 1 ; V_30 < V_168 [ 0 ] . V_103 ; V_30 ++ )
V_206 [ V_30 ] = V_105 -> V_200 [ V_30 - 1 ] ;
V_168 [ 1 ] . V_43 |= V_167 ;
V_168 [ 1 ] . V_103 = 1 ;
break;
case V_203 :
if ( V_204 == V_175 ) {
V_168 [ 1 ] . V_103 = V_105 -> V_200 [ 0 ] ;
} else {
V_168 [ 0 ] . V_103 = V_105 -> V_200 [ 0 ] + 1 ;
if ( V_168 [ 0 ] . V_103 > V_202 + 1 ) {
F_22 ( & V_62 -> V_7 ,
L_83 ,
V_105 -> V_200 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 <= V_105 -> V_200 [ 0 ] ; V_30 ++ )
V_206 [ V_30 ] = V_105 -> V_200 [ V_30 ] ;
}
break;
default:
F_22 ( & V_62 -> V_7 , L_84 , V_205 ) ;
return - V_38 ;
}
V_30 = ( ( V_43 & V_211 ) && V_205 != V_179
&& V_205 != V_203 ) ;
if ( V_30 ) {
if ( ! ( V_168 [ 0 ] . V_43 & V_166 ) ) {
if ( V_160 == 1 )
F_197 ( & V_168 [ 0 ] ) ;
else
V_208 = F_196 ( 0 , & V_168 [ 0 ] ) ;
}
if ( V_168 [ V_160 - 1 ] . V_43 & V_166 )
V_168 [ V_160 - 1 ] . V_103 ++ ;
}
V_40 = F_177 ( V_62 , V_168 , V_160 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_30 && ( V_168 [ V_160 - 1 ] . V_43 & V_166 ) ) {
V_40 = F_198 ( V_208 , & V_168 [ V_160 - 1 ] ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_204 == V_175 )
switch ( V_205 ) {
case V_181 :
V_105 -> V_194 = V_206 [ 0 ] ;
break;
case V_176 :
V_105 -> V_194 = V_207 [ 0 ] ;
break;
case V_196 :
case V_209 :
V_105 -> V_197 = V_207 [ 0 ] | ( V_207 [ 1 ] << 8 ) ;
break;
case V_203 :
for ( V_30 = 0 ; V_30 < V_105 -> V_200 [ 0 ] ; V_30 ++ )
V_105 -> V_200 [ V_30 + 1 ] = V_207 [ V_30 ] ;
break;
case V_199 :
case V_210 :
for ( V_30 = 0 ; V_30 < V_207 [ 0 ] + 1 ; V_30 ++ )
V_105 -> V_200 [ V_30 ] = V_207 [ V_30 ] ;
break;
}
return 0 ;
}
T_12 F_186 ( struct V_17 * V_62 , T_3 V_59 , unsigned short V_43 ,
char V_204 , T_11 V_151 , int V_212 ,
union V_171 * V_105 )
{
unsigned long V_161 ;
int V_162 ;
T_12 V_86 ;
V_43 &= V_169 | V_211 | V_213 ;
if ( V_62 -> V_133 -> V_214 ) {
F_60 ( V_62 ) ;
V_161 = V_163 ;
for ( V_86 = 0 , V_162 = 0 ; V_162 <= V_62 -> V_164 ; V_162 ++ ) {
V_86 = V_62 -> V_133 -> V_214 ( V_62 , V_59 , V_43 ,
V_204 , V_151 ,
V_212 , V_105 ) ;
if ( V_86 != - V_131 )
break;
if ( F_176 ( V_163 ,
V_161 + V_62 -> V_134 ) )
break;
}
F_64 ( V_62 ) ;
if ( V_86 != - V_38 || ! V_62 -> V_133 -> V_165 )
return V_86 ;
}
return F_209 ( V_62 , V_59 , V_43 , V_204 ,
V_151 , V_212 , V_105 ) ;
}
