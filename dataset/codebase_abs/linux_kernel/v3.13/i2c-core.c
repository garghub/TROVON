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
if ( ! F_28 ( & V_4 -> V_7 ) )
F_29 ( & V_4 -> V_7 ,
V_4 -> V_43 & V_44 ) ;
F_10 ( V_7 , L_9 ) ;
F_30 ( & V_4 -> V_7 , true ) ;
V_40 = V_11 -> V_41 ( V_4 , F_1 ( V_11 -> V_12 , V_4 ) ) ;
if ( V_40 ) {
F_31 ( V_4 , NULL ) ;
F_32 ( & V_4 -> V_7 , true ) ;
}
return V_40 ;
}
static int F_33 ( struct V_6 * V_7 )
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
if ( V_40 == 0 )
F_31 ( V_4 , NULL ) ;
F_32 ( & V_4 -> V_7 , true ) ;
return V_40 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> V_45 )
V_11 -> V_45 ( V_4 ) ;
}
static int F_35 ( struct V_6 * V_7 , T_1 V_46 )
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
static int F_36 ( struct V_6 * V_7 )
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
static int F_37 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_38 ( V_7 ) ;
else
return F_35 ( V_7 , V_51 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_40 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_42 ( V_7 ) ;
else
return F_35 ( V_7 , V_52 ) ;
}
static int F_43 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_44 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static int F_45 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_46 ( V_7 ) ;
else
return F_35 ( V_7 , V_53 ) ;
}
static int F_47 ( struct V_6 * V_7 )
{
const struct V_49 * V_50 = V_7 -> V_11 ? V_7 -> V_11 -> V_50 : NULL ;
if ( V_50 )
return F_48 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_50 ( F_8 ( V_7 ) ) ;
}
static T_2
F_51 ( struct V_6 * V_7 , struct V_54 * V_55 , char * V_56 )
{
return sprintf ( V_56 , L_11 , V_7 -> type == & V_57 ?
F_8 ( V_7 ) -> V_5 : F_52 ( V_7 ) -> V_5 ) ;
}
static T_2
F_53 ( struct V_6 * V_7 , struct V_54 * V_55 , char * V_56 )
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
static int F_54 ( const struct V_3 * V_4 )
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
static int F_55 ( unsigned short V_59 )
{
if ( V_59 < 0x08 || V_59 > 0x77 )
return - V_60 ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 , void * V_61 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
int V_59 = * ( int * ) V_61 ;
if ( V_4 && V_4 -> V_59 == V_59 )
return - V_34 ;
return 0 ;
}
static int F_57 ( struct V_17 * V_62 , int V_59 )
{
struct V_17 * V_63 = F_58 ( V_62 ) ;
int V_64 ;
V_64 = F_59 ( & V_62 -> V_7 , & V_59 ,
F_56 ) ;
if ( ! V_64 && V_63 )
V_64 = F_57 ( V_63 , V_59 ) ;
return V_64 ;
}
static int F_60 ( struct V_6 * V_7 , void * V_61 )
{
int V_64 ;
if ( V_7 -> type == & V_65 )
V_64 = F_59 ( V_7 , V_61 ,
F_60 ) ;
else
V_64 = F_56 ( V_7 , V_61 ) ;
return V_64 ;
}
static int F_61 ( struct V_17 * V_62 , int V_59 )
{
struct V_17 * V_63 = F_58 ( V_62 ) ;
int V_64 = 0 ;
if ( V_63 )
V_64 = F_57 ( V_63 , V_59 ) ;
if ( ! V_64 )
V_64 = F_59 ( & V_62 -> V_7 , & V_59 ,
F_60 ) ;
return V_64 ;
}
void F_62 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_58 ( V_62 ) ;
if ( V_63 )
F_62 ( V_63 ) ;
else
F_63 ( & V_62 -> V_66 ) ;
}
static int F_64 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_58 ( V_62 ) ;
if ( V_63 )
return F_64 ( V_63 ) ;
else
return F_65 ( & V_62 -> V_66 ) ;
}
void F_66 ( struct V_17 * V_62 )
{
struct V_17 * V_63 = F_58 ( V_62 ) ;
if ( V_63 )
F_66 ( V_63 ) ;
else
F_67 ( & V_62 -> V_66 ) ;
}
static void F_68 ( struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_67 * V_68 = F_69 ( & V_4 -> V_7 ) ;
if ( V_68 ) {
F_70 ( & V_4 -> V_7 , L_13 , F_71 ( V_68 ) ) ;
return;
}
F_70 ( & V_4 -> V_7 , L_14 , F_72 ( V_18 ) ,
V_4 -> V_59 | ( ( V_4 -> V_43 & V_58 )
? 0xa000 : 0 ) ) ;
}
struct V_3 *
F_73 ( struct V_17 * V_18 , struct V_69 const * V_70 )
{
struct V_3 * V_4 ;
int V_40 ;
V_4 = F_74 ( sizeof *V_4 , V_71 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_62 = V_18 ;
V_4 -> V_7 . V_72 = V_70 -> V_72 ;
if ( V_70 -> V_73 )
V_4 -> V_7 . V_73 = * V_70 -> V_73 ;
V_4 -> V_43 = V_70 -> V_43 ;
V_4 -> V_59 = V_70 -> V_59 ;
V_4 -> V_74 = V_70 -> V_74 ;
F_75 ( V_4 -> V_5 , V_70 -> type , sizeof( V_4 -> V_5 ) ) ;
V_40 = F_54 ( V_4 ) ;
if ( V_40 ) {
F_22 ( & V_18 -> V_7 , L_15 ,
V_4 -> V_43 & V_58 ? 10 : 7 , V_4 -> V_59 ) ;
goto V_75;
}
V_40 = F_61 ( V_18 , V_4 -> V_59 ) ;
if ( V_40 )
goto V_76;
V_4 -> V_7 . V_63 = & V_4 -> V_62 -> V_7 ;
V_4 -> V_7 . V_77 = & V_78 ;
V_4 -> V_7 . type = & V_57 ;
V_4 -> V_7 . V_79 = V_70 -> V_79 ;
F_76 ( & V_4 -> V_7 , V_70 -> V_80 . V_81 ) ;
F_68 ( V_18 , V_4 ) ;
V_40 = F_77 ( & V_4 -> V_7 ) ;
if ( V_40 )
goto V_76;
F_10 ( & V_18 -> V_7 , L_16 ,
V_4 -> V_5 , F_78 ( & V_4 -> V_7 ) ) ;
return V_4 ;
V_76:
F_22 ( & V_18 -> V_7 , L_17
L_18 , V_4 -> V_5 , V_4 -> V_59 , V_40 ) ;
V_75:
F_50 ( V_4 ) ;
return NULL ;
}
void F_79 ( struct V_3 * V_4 )
{
F_80 ( & V_4 -> V_7 ) ;
}
static int F_81 ( struct V_3 * V_4 ,
const struct V_1 * V_2 )
{
return 0 ;
}
static int F_82 ( struct V_3 * V_4 )
{
return 0 ;
}
struct V_3 * F_83 ( struct V_17 * V_62 , T_3 V_82 )
{
struct V_69 V_70 = {
F_84 ( L_19 , V_82 ) ,
} ;
return F_73 ( V_62 , & V_70 ) ;
}
static void F_85 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_52 ( V_7 ) ;
F_86 ( & V_18 -> V_83 ) ;
}
static inline unsigned int F_87 ( struct V_17 * V_62 )
{
unsigned int V_84 = 0 ;
while ( ( V_62 = F_58 ( V_62 ) ) )
V_84 ++ ;
return V_84 ;
}
static T_2
F_88 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_4 V_85 )
{
struct V_17 * V_18 = F_52 ( V_7 ) ;
struct V_69 V_70 ;
struct V_3 * V_4 ;
char * V_86 , V_87 ;
int V_88 ;
memset ( & V_70 , 0 , sizeof( struct V_69 ) ) ;
V_86 = strchr ( V_56 , ' ' ) ;
if ( ! V_86 ) {
F_22 ( V_7 , L_20 , L_21 ) ;
return - V_60 ;
}
if ( V_86 - V_56 > V_89 - 1 ) {
F_22 ( V_7 , L_22 , L_21 ) ;
return - V_60 ;
}
memcpy ( V_70 . type , V_56 , V_86 - V_56 ) ;
V_88 = sscanf ( ++ V_86 , L_23 , & V_70 . V_59 , & V_87 ) ;
if ( V_88 < 1 ) {
F_22 ( V_7 , L_24 , L_21 ) ;
return - V_60 ;
}
if ( V_88 > 1 && V_87 != '\n' ) {
F_22 ( V_7 , L_25 , L_21 ) ;
return - V_60 ;
}
V_4 = F_73 ( V_18 , & V_70 ) ;
if ( ! V_4 )
return - V_60 ;
F_89 ( & V_18 -> V_90 ) ;
F_90 ( & V_4 -> V_91 , & V_18 -> V_92 ) ;
F_91 ( & V_18 -> V_90 ) ;
F_92 ( V_7 , L_26 , L_21 ,
V_70 . type , V_70 . V_59 ) ;
return V_85 ;
}
static T_2
F_93 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_4 V_85 )
{
struct V_17 * V_18 = F_52 ( V_7 ) ;
struct V_3 * V_4 , * V_93 ;
unsigned short V_59 ;
char V_87 ;
int V_88 ;
V_88 = sscanf ( V_56 , L_23 , & V_59 , & V_87 ) ;
if ( V_88 < 1 ) {
F_22 ( V_7 , L_24 , L_27 ) ;
return - V_60 ;
}
if ( V_88 > 1 && V_87 != '\n' ) {
F_22 ( V_7 , L_25 , L_27 ) ;
return - V_60 ;
}
V_88 = - V_94 ;
F_94 ( & V_18 -> V_90 ,
F_87 ( V_18 ) ) ;
F_95 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_59 == V_59 ) {
F_92 ( V_7 , L_28 ,
L_27 , V_4 -> V_5 , V_4 -> V_59 ) ;
F_96 ( & V_4 -> V_91 ) ;
F_79 ( V_4 ) ;
V_88 = V_85 ;
break;
}
}
F_91 ( & V_18 -> V_90 ) ;
if ( V_88 < 0 )
F_22 ( V_7 , L_29 ,
L_27 ) ;
return V_88 ;
}
struct V_17 * F_97 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_65 )
? F_52 ( V_7 )
: NULL ;
}
static void F_98 ( struct V_17 * V_62 )
{
struct V_95 * V_96 ;
F_99 ( & V_97 ) ;
F_100 (devinfo, &__i2c_board_list, list) {
if ( V_96 -> V_98 == V_62 -> V_99
&& ! F_73 ( V_62 ,
& V_96 -> V_100 ) )
F_22 ( & V_62 -> V_7 ,
L_30 ,
V_96 -> V_100 . V_59 ) ;
}
F_101 ( & V_97 ) ;
}
static void F_102 ( struct V_17 * V_18 )
{
void * V_64 ;
struct V_101 * V_102 ;
if ( ! V_18 -> V_7 . V_79 )
return;
F_10 ( & V_18 -> V_7 , L_31 ) ;
F_103 (adap->dev.of_node, node) {
struct V_69 V_70 = {} ;
struct V_103 V_104 = {} ;
const T_5 * V_59 ;
int V_105 ;
F_10 ( & V_18 -> V_7 , L_32 , V_102 -> V_106 ) ;
if ( F_104 ( V_102 , V_70 . type , sizeof( V_70 . type ) ) < 0 ) {
F_22 ( & V_18 -> V_7 , L_33 ,
V_102 -> V_106 ) ;
continue;
}
V_59 = F_105 ( V_102 , L_34 , & V_105 ) ;
if ( ! V_59 || ( V_105 < sizeof( int ) ) ) {
F_22 ( & V_18 -> V_7 , L_35 ,
V_102 -> V_106 ) ;
continue;
}
V_70 . V_59 = F_106 ( V_59 ) ;
if ( V_70 . V_59 > ( 1 << 10 ) - 1 ) {
F_22 ( & V_18 -> V_7 , L_36 ,
V_70 . V_59 , V_102 -> V_106 ) ;
continue;
}
V_70 . V_74 = F_107 ( V_102 , 0 ) ;
V_70 . V_79 = F_108 ( V_102 ) ;
V_70 . V_73 = & V_104 ;
if ( F_105 ( V_102 , L_37 , NULL ) )
V_70 . V_43 |= V_44 ;
F_109 ( L_38 , V_15 , V_70 . type ) ;
V_64 = F_73 ( V_18 , & V_70 ) ;
if ( V_64 == NULL ) {
F_22 ( & V_18 -> V_7 , L_39 ,
V_102 -> V_106 ) ;
F_110 ( V_102 ) ;
F_111 ( V_70 . V_74 ) ;
continue;
}
}
}
static int F_112 ( struct V_6 * V_7 , void * V_107 )
{
return V_7 -> V_79 == V_107 ;
}
struct V_3 * F_113 ( struct V_101 * V_102 )
{
struct V_6 * V_7 ;
V_7 = F_114 ( & V_78 , NULL , V_102 ,
F_112 ) ;
if ( ! V_7 )
return NULL ;
return F_3 ( V_7 ) ;
}
struct V_17 * F_115 ( struct V_101 * V_102 )
{
struct V_6 * V_7 ;
V_7 = F_114 ( & V_78 , NULL , V_102 ,
F_112 ) ;
if ( ! V_7 )
return NULL ;
return F_97 ( V_7 ) ;
}
static void F_102 ( struct V_17 * V_18 ) { }
static int F_116 ( struct V_108 * V_109 , void * V_107 )
{
struct V_69 * V_70 = V_107 ;
if ( V_109 -> type == V_110 ) {
struct V_111 * V_112 ;
V_112 = & V_109 -> V_107 . V_113 ;
if ( V_112 -> type == V_114 ) {
V_70 -> V_59 = V_112 -> V_115 ;
if ( V_112 -> V_116 == V_117 )
V_70 -> V_43 |= V_58 ;
}
} else if ( V_70 -> V_74 < 0 ) {
struct V_118 V_119 ;
if ( F_117 ( V_109 , 0 , & V_119 ) )
V_70 -> V_74 = V_119 . V_120 ;
}
return 1 ;
}
static T_6 F_118 ( T_7 V_121 , T_8 V_122 ,
void * V_107 , void * * V_123 )
{
struct V_17 * V_62 = V_107 ;
struct V_124 V_125 ;
struct V_69 V_70 ;
struct V_67 * V_68 ;
int V_25 ;
if ( F_119 ( V_121 , & V_68 ) )
return V_126 ;
if ( F_120 ( V_68 ) || ! V_68 -> V_40 . V_127 )
return V_126 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_80 . V_81 = V_68 ;
V_70 . V_74 = - 1 ;
F_121 ( & V_125 ) ;
V_25 = F_122 ( V_68 , & V_125 ,
F_116 , & V_70 ) ;
F_123 ( & V_125 ) ;
if ( V_25 < 0 || ! V_70 . V_59 )
return V_126 ;
V_68 -> V_128 . V_43 . V_129 = true ;
F_75 ( V_70 . type , F_78 ( & V_68 -> V_7 ) , sizeof( V_70 . type ) ) ;
if ( ! F_73 ( V_62 , & V_70 ) ) {
V_68 -> V_128 . V_43 . V_129 = false ;
F_22 ( & V_62 -> V_7 ,
L_40 ,
F_78 ( & V_68 -> V_7 ) ) ;
}
return V_126 ;
}
static void F_124 ( struct V_17 * V_18 )
{
T_7 V_121 ;
T_6 V_40 ;
if ( ! V_18 -> V_7 . V_63 )
return;
V_121 = F_125 ( V_18 -> V_7 . V_63 ) ;
if ( ! V_121 )
return;
V_40 = F_126 ( V_130 , V_121 , 1 ,
F_118 , NULL ,
V_18 , NULL ) ;
if ( F_127 ( V_40 ) )
F_18 ( & V_18 -> V_7 , L_41 ) ;
}
static inline void F_124 ( struct V_17 * V_18 ) {}
static int F_128 ( struct V_10 * V_11 ,
struct V_17 * V_18 )
{
F_129 ( V_18 , V_11 ) ;
if ( V_11 -> V_131 ) {
F_18 ( & V_18 -> V_7 , L_42 ,
V_11 -> V_11 . V_5 ) ;
F_18 ( & V_18 -> V_7 , L_43
L_44 ) ;
V_11 -> V_131 ( V_18 ) ;
}
return 0 ;
}
static int F_130 ( struct V_8 * V_132 , void * V_107 )
{
return F_128 ( F_6 ( V_132 ) , V_107 ) ;
}
static int F_131 ( struct V_17 * V_18 )
{
int V_88 = 0 ;
if ( F_132 ( F_133 ( ! V_78 . V_133 ) ) ) {
V_88 = - V_134 ;
goto V_135;
}
if ( F_132 ( V_18 -> V_5 [ 0 ] == '\0' ) ) {
F_134 ( L_45
L_46 ) ;
return - V_60 ;
}
if ( F_132 ( ! V_18 -> V_136 ) ) {
F_134 ( L_47
L_48 , V_18 -> V_5 ) ;
return - V_60 ;
}
F_135 ( & V_18 -> V_66 ) ;
F_136 ( & V_18 -> V_90 ) ;
F_121 ( & V_18 -> V_92 ) ;
if ( V_18 -> V_137 == 0 )
V_18 -> V_137 = V_138 ;
F_70 ( & V_18 -> V_7 , L_49 , V_18 -> V_99 ) ;
V_18 -> V_7 . V_77 = & V_78 ;
V_18 -> V_7 . type = & V_65 ;
V_88 = F_77 ( & V_18 -> V_7 ) ;
if ( V_88 )
goto V_135;
F_10 ( & V_18 -> V_7 , L_50 , V_18 -> V_5 ) ;
#ifdef F_137
V_88 = F_138 ( V_139 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
if ( V_88 )
F_18 ( & V_18 -> V_7 ,
L_51 ) ;
#endif
if ( V_18 -> V_19 ) {
struct V_23 * V_24 = V_18 -> V_19 ;
if ( ! V_24 -> V_39 ) {
F_22 ( & V_18 -> V_7 , L_52 ) ;
V_18 -> V_19 = NULL ;
goto V_140;
}
if ( V_24 -> V_39 == F_25 ) {
if ( ! F_139 ( V_24 -> V_20 ) ) {
F_22 ( & V_18 -> V_7 , L_53 ) ;
V_18 -> V_19 = NULL ;
goto V_140;
}
if ( F_139 ( V_24 -> V_22 ) )
V_24 -> V_28 = F_15 ;
else
V_24 -> V_28 = NULL ;
V_24 -> V_33 = F_11 ;
V_24 -> V_35 = F_13 ;
} else if ( ! V_24 -> V_35 || ! V_24 -> V_33 ) {
F_22 ( & V_18 -> V_7 , L_54 ) ;
V_18 -> V_19 = NULL ;
}
}
V_140:
F_102 ( V_18 ) ;
F_124 ( V_18 ) ;
if ( V_18 -> V_99 < V_141 )
F_98 ( V_18 ) ;
F_89 ( & V_142 ) ;
F_140 ( & V_78 , NULL , V_18 , F_130 ) ;
F_91 ( & V_142 ) ;
return 0 ;
V_135:
F_89 ( & V_142 ) ;
F_141 ( & V_143 , V_18 -> V_99 ) ;
F_91 ( & V_142 ) ;
return V_88 ;
}
static int F_142 ( struct V_17 * V_18 )
{
int V_2 ;
F_89 ( & V_142 ) ;
V_2 = F_143 ( & V_143 , V_18 , V_18 -> V_99 , V_18 -> V_99 + 1 ,
V_71 ) ;
F_91 ( & V_142 ) ;
if ( V_2 < 0 )
return V_2 == - V_144 ? - V_34 : V_2 ;
return F_131 ( V_18 ) ;
}
int F_144 ( struct V_17 * V_62 )
{
struct V_6 * V_7 = & V_62 -> V_7 ;
int V_2 ;
if ( V_7 -> V_79 ) {
V_2 = F_145 ( V_7 -> V_79 , L_55 ) ;
if ( V_2 >= 0 ) {
V_62 -> V_99 = V_2 ;
return F_142 ( V_62 ) ;
}
}
F_89 ( & V_142 ) ;
V_2 = F_143 ( & V_143 , V_62 ,
V_141 , 0 , V_71 ) ;
F_91 ( & V_142 ) ;
if ( V_2 < 0 )
return V_2 ;
V_62 -> V_99 = V_2 ;
return F_131 ( V_62 ) ;
}
int F_146 ( struct V_17 * V_18 )
{
if ( V_18 -> V_99 == - 1 )
return F_144 ( V_18 ) ;
return F_142 ( V_18 ) ;
}
static void F_147 ( struct V_10 * V_11 ,
struct V_17 * V_62 )
{
struct V_3 * V_4 , * V_145 ;
F_95 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_62 == V_62 ) {
F_10 ( & V_62 -> V_7 , L_56 ,
V_4 -> V_5 , V_4 -> V_59 ) ;
F_96 ( & V_4 -> V_91 ) ;
F_79 ( V_4 ) ;
}
}
}
static int F_148 ( struct V_6 * V_7 , void * V_146 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_19 ) )
F_79 ( V_4 ) ;
return 0 ;
}
static int F_149 ( struct V_6 * V_7 , void * V_146 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_79 ( V_4 ) ;
return 0 ;
}
static int F_150 ( struct V_8 * V_132 , void * V_107 )
{
F_147 ( F_6 ( V_132 ) , V_107 ) ;
return 0 ;
}
void F_151 ( struct V_17 * V_18 )
{
struct V_17 * V_147 ;
struct V_3 * V_4 , * V_93 ;
F_89 ( & V_142 ) ;
V_147 = F_152 ( & V_143 , V_18 -> V_99 ) ;
F_91 ( & V_142 ) ;
if ( V_147 != V_18 ) {
F_153 ( L_57
L_58 , V_18 -> V_5 ) ;
return;
}
F_89 ( & V_142 ) ;
F_140 ( & V_78 , NULL , V_18 ,
F_150 ) ;
F_91 ( & V_142 ) ;
F_94 ( & V_18 -> V_90 ,
F_87 ( V_18 ) ) ;
F_95 (client, next, &adap->userspace_clients,
detected) {
F_10 ( & V_18 -> V_7 , L_56 , V_4 -> V_5 ,
V_4 -> V_59 ) ;
F_96 ( & V_4 -> V_91 ) ;
F_79 ( V_4 ) ;
}
F_91 ( & V_18 -> V_90 ) ;
F_59 ( & V_18 -> V_7 , NULL , F_148 ) ;
F_59 ( & V_18 -> V_7 , NULL , F_149 ) ;
#ifdef F_137
F_154 ( V_139 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
#endif
F_10 ( & V_18 -> V_7 , L_59 , V_18 -> V_5 ) ;
F_155 ( & V_18 -> V_83 ) ;
F_80 ( & V_18 -> V_7 ) ;
F_156 ( & V_18 -> V_83 ) ;
F_89 ( & V_142 ) ;
F_141 ( & V_143 , V_18 -> V_99 ) ;
F_91 ( & V_142 ) ;
memset ( & V_18 -> V_7 , 0 , sizeof( V_18 -> V_7 ) ) ;
}
int F_157 ( void * V_107 , int (* F_158)( struct V_6 * , void * ) )
{
int V_88 ;
F_89 ( & V_142 ) ;
V_88 = F_159 ( & V_78 , NULL , V_107 , F_158 ) ;
F_91 ( & V_142 ) ;
return V_88 ;
}
static int F_160 ( struct V_6 * V_7 , void * V_107 )
{
if ( V_7 -> type != & V_65 )
return 0 ;
return F_128 ( V_107 , F_52 ( V_7 ) ) ;
}
int F_161 ( struct V_148 * V_149 , struct V_10 * V_11 )
{
int V_88 ;
if ( F_132 ( F_133 ( ! V_78 . V_133 ) ) )
return - V_134 ;
V_11 -> V_11 . V_149 = V_149 ;
V_11 -> V_11 . V_77 = & V_78 ;
V_88 = F_162 ( & V_11 -> V_11 ) ;
if ( V_88 )
return V_88 ;
if ( V_11 -> V_47 )
F_163 ( L_60 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_48 )
F_163 ( L_61 ,
V_11 -> V_11 . V_5 ) ;
F_153 ( L_62 , V_11 -> V_11 . V_5 ) ;
F_121 ( & V_11 -> V_150 ) ;
F_157 ( V_11 , F_160 ) ;
return 0 ;
}
static int F_164 ( struct V_6 * V_7 , void * V_107 )
{
if ( V_7 -> type == & V_65 )
F_147 ( V_107 , F_52 ( V_7 ) ) ;
return 0 ;
}
void F_165 ( struct V_10 * V_11 )
{
F_157 ( V_11 , F_164 ) ;
F_166 ( & V_11 -> V_11 ) ;
F_153 ( L_63 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_167 ( struct V_3 * V_4 )
{
if ( V_4 && F_168 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_169 ( struct V_3 * V_4 )
{
if ( V_4 )
F_170 ( & V_4 -> V_7 ) ;
}
static int F_171 ( struct V_6 * V_7 , void * V_151 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_152 * V_153 = V_151 ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_4 -> V_7 . V_11 )
return 0 ;
V_11 = F_6 ( V_4 -> V_7 . V_11 ) ;
if ( V_11 -> V_154 )
V_11 -> V_154 ( V_4 , V_153 -> V_155 , V_153 -> V_153 ) ;
return 0 ;
}
void F_172 ( struct V_17 * V_18 , unsigned int V_155 , void * V_153 )
{
struct V_152 V_156 ;
V_156 . V_155 = V_155 ;
V_156 . V_153 = V_153 ;
F_59 ( & V_18 -> V_7 , & V_156 , F_171 ) ;
}
static int T_9 F_173 ( void )
{
int V_157 ;
V_157 = F_174 ( & V_78 ) ;
if ( V_157 )
return V_157 ;
#ifdef F_137
V_139 = F_175 ( L_64 ) ;
if ( ! V_139 ) {
V_157 = - V_16 ;
goto V_158;
}
#endif
V_157 = F_176 ( & V_159 ) ;
if ( V_157 )
goto V_160;
return 0 ;
V_160:
#ifdef F_137
F_177 ( V_139 ) ;
V_158:
#endif
F_178 ( & V_78 ) ;
return V_157 ;
}
static void T_10 F_179 ( void )
{
F_165 ( & V_159 ) ;
#ifdef F_137
F_177 ( V_139 ) ;
#endif
F_178 ( & V_78 ) ;
}
int F_180 ( struct V_17 * V_18 , struct V_161 * V_162 , int V_163 )
{
unsigned long V_164 ;
int V_25 , V_165 ;
V_164 = V_166 ;
for ( V_25 = 0 , V_165 = 0 ; V_165 <= V_18 -> V_167 ; V_165 ++ ) {
V_25 = V_18 -> V_136 -> V_168 ( V_18 , V_162 , V_163 ) ;
if ( V_25 != - V_134 )
break;
if ( F_181 ( V_166 , V_164 + V_18 -> V_137 ) )
break;
}
return V_25 ;
}
int F_182 ( struct V_17 * V_18 , struct V_161 * V_162 , int V_163 )
{
int V_25 ;
if ( V_18 -> V_136 -> V_168 ) {
#ifdef F_183
for ( V_25 = 0 ; V_25 < V_163 ; V_25 ++ ) {
F_10 ( & V_18 -> V_7 , L_65
L_66 , V_25 , ( V_162 [ V_25 ] . V_43 & V_169 )
? 'R' : 'W' , V_162 [ V_25 ] . V_59 , V_162 [ V_25 ] . V_105 ,
( V_162 [ V_25 ] . V_43 & V_170 ) ? L_67 : L_68 ) ;
}
#endif
if ( F_184 () || F_185 () ) {
V_25 = F_64 ( V_18 ) ;
if ( ! V_25 )
return - V_134 ;
} else {
F_62 ( V_18 ) ;
}
V_25 = F_180 ( V_18 , V_162 , V_163 ) ;
F_66 ( V_18 ) ;
return V_25 ;
} else {
F_10 ( & V_18 -> V_7 , L_69 ) ;
return - V_38 ;
}
}
int F_186 ( const struct V_3 * V_4 , const char * V_56 , int V_85 )
{
int V_25 ;
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_161 V_171 ;
V_171 . V_59 = V_4 -> V_59 ;
V_171 . V_43 = V_4 -> V_43 & V_172 ;
V_171 . V_105 = V_85 ;
V_171 . V_56 = ( char * ) V_56 ;
V_25 = F_182 ( V_18 , & V_171 , 1 ) ;
return ( V_25 == 1 ) ? V_85 : V_25 ;
}
int F_187 ( const struct V_3 * V_4 , char * V_56 , int V_85 )
{
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_161 V_171 ;
int V_25 ;
V_171 . V_59 = V_4 -> V_59 ;
V_171 . V_43 = V_4 -> V_43 & V_172 ;
V_171 . V_43 |= V_169 ;
V_171 . V_105 = V_85 ;
V_171 . V_56 = V_56 ;
V_25 = F_182 ( V_18 , & V_171 , 1 ) ;
return ( V_25 == 1 ) ? V_85 : V_25 ;
}
static int F_188 ( struct V_17 * V_18 , unsigned short V_59 )
{
int V_173 ;
union V_174 V_146 ;
#ifdef F_189
if ( V_59 == 0x73 && ( V_18 -> V_175 & V_176 )
&& F_190 ( V_18 , V_177 ) )
V_173 = F_191 ( V_18 , V_59 , 0 , V_178 , 0 ,
V_179 , & V_146 ) ;
else
#endif
if ( ! ( ( V_59 & ~ 0x07 ) == 0x30 || ( V_59 & ~ 0x0f ) == 0x50 )
&& F_190 ( V_18 , V_180 ) )
V_173 = F_191 ( V_18 , V_59 , 0 , V_181 , 0 ,
V_182 , NULL ) ;
else if ( F_190 ( V_18 , V_183 ) )
V_173 = F_191 ( V_18 , V_59 , 0 , V_178 , 0 ,
V_184 , & V_146 ) ;
else {
F_18 ( & V_18 -> V_7 , L_70 ,
V_59 ) ;
V_173 = - V_38 ;
}
return V_173 >= 0 ;
}
static int F_192 ( struct V_3 * V_185 ,
struct V_10 * V_11 )
{
struct V_69 V_70 ;
struct V_17 * V_62 = V_185 -> V_62 ;
int V_59 = V_185 -> V_59 ;
int V_173 ;
V_173 = F_55 ( V_59 ) ;
if ( V_173 ) {
F_18 ( & V_62 -> V_7 , L_71 ,
V_59 ) ;
return V_173 ;
}
if ( F_61 ( V_62 , V_59 ) )
return 0 ;
if ( ! F_188 ( V_62 , V_59 ) )
return 0 ;
memset ( & V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 . V_59 = V_59 ;
V_173 = V_11 -> V_186 ( V_185 , & V_70 ) ;
if ( V_173 ) {
return V_173 == - V_42 ? 0 : V_173 ;
}
if ( V_70 . type [ 0 ] == '\0' ) {
F_22 ( & V_62 -> V_7 , L_72
L_73 , V_11 -> V_11 . V_5 ,
V_59 ) ;
} else {
struct V_3 * V_4 ;
F_10 ( & V_62 -> V_7 , L_74 ,
V_70 . type , V_70 . V_59 ) ;
V_4 = F_73 ( V_62 , & V_70 ) ;
if ( V_4 )
F_90 ( & V_4 -> V_91 , & V_11 -> V_150 ) ;
else
F_22 ( & V_62 -> V_7 , L_75 ,
V_70 . type , V_70 . V_59 ) ;
}
return 0 ;
}
static int F_129 ( struct V_17 * V_62 , struct V_10 * V_11 )
{
const unsigned short * V_187 ;
struct V_3 * V_185 ;
int V_30 , V_173 = 0 ;
int V_188 = F_72 ( V_62 ) ;
V_187 = V_11 -> V_187 ;
if ( ! V_11 -> V_186 || ! V_187 )
return 0 ;
if ( ! ( V_62 -> V_175 & V_11 -> V_175 ) )
return 0 ;
V_185 = F_74 ( sizeof( struct V_3 ) , V_71 ) ;
if ( ! V_185 )
return - V_16 ;
V_185 -> V_62 = V_62 ;
for ( V_30 = 0 ; V_187 [ V_30 ] != V_189 ; V_30 += 1 ) {
F_10 ( & V_62 -> V_7 , L_76
L_77 , V_188 , V_187 [ V_30 ] ) ;
V_185 -> V_59 = V_187 [ V_30 ] ;
V_173 = F_192 ( V_185 , V_11 ) ;
if ( F_132 ( V_173 ) )
break;
}
F_50 ( V_185 ) ;
return V_173 ;
}
int F_193 ( struct V_17 * V_18 , unsigned short V_59 )
{
return F_191 ( V_18 , V_59 , 0 , V_178 , 0 ,
V_182 , NULL ) >= 0 ;
}
struct V_3 *
F_194 ( struct V_17 * V_18 ,
struct V_69 * V_70 ,
unsigned short const * V_190 ,
int (* V_41)( struct V_17 * , unsigned short V_59 ) )
{
int V_30 ;
if ( ! V_41 )
V_41 = F_188 ;
for ( V_30 = 0 ; V_190 [ V_30 ] != V_189 ; V_30 ++ ) {
if ( F_55 ( V_190 [ V_30 ] ) < 0 ) {
F_18 ( & V_18 -> V_7 , L_78
L_79 , V_190 [ V_30 ] ) ;
continue;
}
if ( F_61 ( V_18 , V_190 [ V_30 ] ) ) {
F_10 ( & V_18 -> V_7 , L_80
L_81 , V_190 [ V_30 ] ) ;
continue;
}
if ( V_41 ( V_18 , V_190 [ V_30 ] ) )
break;
}
if ( V_190 [ V_30 ] == V_189 ) {
F_10 ( & V_18 -> V_7 , L_82 ) ;
return NULL ;
}
V_70 -> V_59 = V_190 [ V_30 ] ;
return F_73 ( V_18 , V_70 ) ;
}
struct V_17 * F_195 ( int V_99 )
{
struct V_17 * V_62 ;
F_89 ( & V_142 ) ;
V_62 = F_152 ( & V_143 , V_99 ) ;
if ( V_62 && ! F_196 ( V_62 -> V_149 ) )
V_62 = NULL ;
F_91 ( & V_142 ) ;
return V_62 ;
}
void F_197 ( struct V_17 * V_18 )
{
if ( V_18 )
F_198 ( V_18 -> V_149 ) ;
}
static T_11 F_199 ( T_3 V_107 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( V_107 & 0x8000 )
V_107 = V_107 ^ V_191 ;
V_107 = V_107 << 1 ;
}
return ( T_11 ) ( V_107 >> 8 ) ;
}
static T_11 F_200 ( T_11 V_192 , T_11 * V_133 , T_4 V_85 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_85 ; V_30 ++ )
V_192 = F_199 ( ( V_192 ^ V_133 [ V_30 ] ) << 8 ) ;
return V_192 ;
}
static T_11 F_201 ( T_11 V_193 , struct V_161 * V_171 )
{
T_11 V_59 = ( V_171 -> V_59 << 1 ) | ! ! ( V_171 -> V_43 & V_169 ) ;
V_193 = F_200 ( V_193 , & V_59 , 1 ) ;
return F_200 ( V_193 , V_171 -> V_56 , V_171 -> V_105 ) ;
}
static inline void F_202 ( struct V_161 * V_171 )
{
V_171 -> V_56 [ V_171 -> V_105 ] = F_201 ( 0 , V_171 ) ;
V_171 -> V_105 ++ ;
}
static int F_203 ( T_11 V_194 , struct V_161 * V_171 )
{
T_11 V_195 = V_171 -> V_56 [ -- V_171 -> V_105 ] ;
V_194 = F_201 ( V_194 , V_171 ) ;
if ( V_195 != V_194 ) {
F_153 ( L_83 ,
V_195 , V_194 ) ;
return - V_196 ;
}
return 0 ;
}
T_12 F_204 ( const struct V_3 * V_4 )
{
union V_174 V_107 ;
int V_40 ;
V_40 = F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , 0 ,
V_184 , & V_107 ) ;
return ( V_40 < 0 ) ? V_40 : V_107 . V_197 ;
}
T_12 F_205 ( const struct V_3 * V_4 , T_11 V_198 )
{
return F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_181 , V_198 , V_184 , NULL ) ;
}
T_12 F_206 ( const struct V_3 * V_4 , T_11 V_154 )
{
union V_174 V_107 ;
int V_40 ;
V_40 = F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_154 ,
V_179 , & V_107 ) ;
return ( V_40 < 0 ) ? V_40 : V_107 . V_197 ;
}
T_12 F_207 ( const struct V_3 * V_4 , T_11 V_154 ,
T_11 V_198 )
{
union V_174 V_107 ;
V_107 . V_197 = V_198 ;
return F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_181 , V_154 ,
V_179 , & V_107 ) ;
}
T_12 F_208 ( const struct V_3 * V_4 , T_11 V_154 )
{
union V_174 V_107 ;
int V_40 ;
V_40 = F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_154 ,
V_199 , & V_107 ) ;
return ( V_40 < 0 ) ? V_40 : V_107 . V_200 ;
}
T_12 F_209 ( const struct V_3 * V_4 , T_11 V_154 ,
T_3 V_198 )
{
union V_174 V_107 ;
V_107 . V_200 = V_198 ;
return F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_181 , V_154 ,
V_199 , & V_107 ) ;
}
T_12 F_210 ( const struct V_3 * V_4 , T_11 V_154 ,
T_11 * V_201 )
{
union V_174 V_107 ;
int V_40 ;
V_40 = F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_154 ,
V_202 , & V_107 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_201 , & V_107 . V_203 [ 1 ] , V_107 . V_203 [ 0 ] ) ;
return V_107 . V_203 [ 0 ] ;
}
T_12 F_211 ( const struct V_3 * V_4 , T_11 V_154 ,
T_11 V_204 , const T_11 * V_201 )
{
union V_174 V_107 ;
if ( V_204 > V_205 )
V_204 = V_205 ;
V_107 . V_203 [ 0 ] = V_204 ;
memcpy ( & V_107 . V_203 [ 1 ] , V_201 , V_204 ) ;
return F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_181 , V_154 ,
V_202 , & V_107 ) ;
}
T_12 F_212 ( const struct V_3 * V_4 , T_11 V_154 ,
T_11 V_204 , T_11 * V_201 )
{
union V_174 V_107 ;
int V_40 ;
if ( V_204 > V_205 )
V_204 = V_205 ;
V_107 . V_203 [ 0 ] = V_204 ;
V_40 = F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_178 , V_154 ,
V_206 , & V_107 ) ;
if ( V_40 < 0 )
return V_40 ;
memcpy ( V_201 , & V_107 . V_203 [ 1 ] , V_107 . V_203 [ 0 ] ) ;
return V_107 . V_203 [ 0 ] ;
}
T_12 F_213 ( const struct V_3 * V_4 , T_11 V_154 ,
T_11 V_204 , const T_11 * V_201 )
{
union V_174 V_107 ;
if ( V_204 > V_205 )
V_204 = V_205 ;
V_107 . V_203 [ 0 ] = V_204 ;
memcpy ( V_107 . V_203 + 1 , V_201 , V_204 ) ;
return F_191 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_181 , V_154 ,
V_206 , & V_107 ) ;
}
static T_12 F_214 ( struct V_17 * V_62 , T_3 V_59 ,
unsigned short V_43 ,
char V_207 , T_11 V_154 , int V_208 ,
union V_174 * V_107 )
{
unsigned char V_209 [ V_205 + 3 ] ;
unsigned char V_210 [ V_205 + 2 ] ;
int V_163 = V_207 == V_178 ? 2 : 1 ;
int V_30 ;
T_11 V_211 = 0 ;
int V_40 ;
struct V_161 V_171 [ 2 ] = {
{
. V_59 = V_59 ,
. V_43 = V_43 ,
. V_105 = 1 ,
. V_56 = V_209 ,
} , {
. V_59 = V_59 ,
. V_43 = V_43 | V_169 ,
. V_105 = 0 ,
. V_56 = V_210 ,
} ,
} ;
V_209 [ 0 ] = V_154 ;
switch ( V_208 ) {
case V_182 :
V_171 [ 0 ] . V_105 = 0 ;
V_171 [ 0 ] . V_43 = V_43 | ( V_207 == V_178 ?
V_169 : 0 ) ;
V_163 = 1 ;
break;
case V_184 :
if ( V_207 == V_178 ) {
V_171 [ 0 ] . V_43 = V_169 | V_43 ;
V_163 = 1 ;
}
break;
case V_179 :
if ( V_207 == V_178 )
V_171 [ 1 ] . V_105 = 1 ;
else {
V_171 [ 0 ] . V_105 = 2 ;
V_209 [ 1 ] = V_107 -> V_197 ;
}
break;
case V_199 :
if ( V_207 == V_178 )
V_171 [ 1 ] . V_105 = 2 ;
else {
V_171 [ 0 ] . V_105 = 3 ;
V_209 [ 1 ] = V_107 -> V_200 & 0xff ;
V_209 [ 2 ] = V_107 -> V_200 >> 8 ;
}
break;
case V_212 :
V_163 = 2 ;
V_207 = V_178 ;
V_171 [ 0 ] . V_105 = 3 ;
V_171 [ 1 ] . V_105 = 2 ;
V_209 [ 1 ] = V_107 -> V_200 & 0xff ;
V_209 [ 2 ] = V_107 -> V_200 >> 8 ;
break;
case V_202 :
if ( V_207 == V_178 ) {
V_171 [ 1 ] . V_43 |= V_170 ;
V_171 [ 1 ] . V_105 = 1 ;
} else {
V_171 [ 0 ] . V_105 = V_107 -> V_203 [ 0 ] + 2 ;
if ( V_171 [ 0 ] . V_105 > V_205 + 2 ) {
F_22 ( & V_62 -> V_7 ,
L_84 ,
V_107 -> V_203 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 < V_171 [ 0 ] . V_105 ; V_30 ++ )
V_209 [ V_30 ] = V_107 -> V_203 [ V_30 - 1 ] ;
}
break;
case V_213 :
V_163 = 2 ;
V_207 = V_178 ;
if ( V_107 -> V_203 [ 0 ] > V_205 ) {
F_22 ( & V_62 -> V_7 ,
L_84 ,
V_107 -> V_203 [ 0 ] ) ;
return - V_60 ;
}
V_171 [ 0 ] . V_105 = V_107 -> V_203 [ 0 ] + 2 ;
for ( V_30 = 1 ; V_30 < V_171 [ 0 ] . V_105 ; V_30 ++ )
V_209 [ V_30 ] = V_107 -> V_203 [ V_30 - 1 ] ;
V_171 [ 1 ] . V_43 |= V_170 ;
V_171 [ 1 ] . V_105 = 1 ;
break;
case V_206 :
if ( V_207 == V_178 ) {
V_171 [ 1 ] . V_105 = V_107 -> V_203 [ 0 ] ;
} else {
V_171 [ 0 ] . V_105 = V_107 -> V_203 [ 0 ] + 1 ;
if ( V_171 [ 0 ] . V_105 > V_205 + 1 ) {
F_22 ( & V_62 -> V_7 ,
L_84 ,
V_107 -> V_203 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 <= V_107 -> V_203 [ 0 ] ; V_30 ++ )
V_209 [ V_30 ] = V_107 -> V_203 [ V_30 ] ;
}
break;
default:
F_22 ( & V_62 -> V_7 , L_85 , V_208 ) ;
return - V_38 ;
}
V_30 = ( ( V_43 & V_214 ) && V_208 != V_182
&& V_208 != V_206 ) ;
if ( V_30 ) {
if ( ! ( V_171 [ 0 ] . V_43 & V_169 ) ) {
if ( V_163 == 1 )
F_202 ( & V_171 [ 0 ] ) ;
else
V_211 = F_201 ( 0 , & V_171 [ 0 ] ) ;
}
if ( V_171 [ V_163 - 1 ] . V_43 & V_169 )
V_171 [ V_163 - 1 ] . V_105 ++ ;
}
V_40 = F_182 ( V_62 , V_171 , V_163 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_30 && ( V_171 [ V_163 - 1 ] . V_43 & V_169 ) ) {
V_40 = F_203 ( V_211 , & V_171 [ V_163 - 1 ] ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_207 == V_178 )
switch ( V_208 ) {
case V_184 :
V_107 -> V_197 = V_209 [ 0 ] ;
break;
case V_179 :
V_107 -> V_197 = V_210 [ 0 ] ;
break;
case V_199 :
case V_212 :
V_107 -> V_200 = V_210 [ 0 ] | ( V_210 [ 1 ] << 8 ) ;
break;
case V_206 :
for ( V_30 = 0 ; V_30 < V_107 -> V_203 [ 0 ] ; V_30 ++ )
V_107 -> V_203 [ V_30 + 1 ] = V_210 [ V_30 ] ;
break;
case V_202 :
case V_213 :
for ( V_30 = 0 ; V_30 < V_210 [ 0 ] + 1 ; V_30 ++ )
V_107 -> V_203 [ V_30 ] = V_210 [ V_30 ] ;
break;
}
return 0 ;
}
T_12 F_191 ( struct V_17 * V_62 , T_3 V_59 , unsigned short V_43 ,
char V_207 , T_11 V_154 , int V_215 ,
union V_174 * V_107 )
{
unsigned long V_164 ;
int V_165 ;
T_12 V_88 ;
V_43 &= V_172 | V_214 | V_216 ;
if ( V_62 -> V_136 -> V_217 ) {
F_62 ( V_62 ) ;
V_164 = V_166 ;
for ( V_88 = 0 , V_165 = 0 ; V_165 <= V_62 -> V_167 ; V_165 ++ ) {
V_88 = V_62 -> V_136 -> V_217 ( V_62 , V_59 , V_43 ,
V_207 , V_154 ,
V_215 , V_107 ) ;
if ( V_88 != - V_134 )
break;
if ( F_181 ( V_166 ,
V_164 + V_62 -> V_137 ) )
break;
}
F_66 ( V_62 ) ;
if ( V_88 != - V_38 || ! V_62 -> V_136 -> V_168 )
return V_88 ;
}
return F_214 ( V_62 , V_59 , V_43 , V_207 ,
V_154 , V_215 , V_107 ) ;
}
