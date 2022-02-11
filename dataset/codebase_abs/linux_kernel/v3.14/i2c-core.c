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
int V_15 ;
V_15 = F_9 ( V_7 , V_14 ) ;
if ( V_15 != - V_16 )
return V_15 ;
if ( F_10 ( V_14 , L_1 ,
V_17 , V_4 -> V_5 ) )
return - V_18 ;
F_11 ( V_7 , L_2 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
return F_13 ( V_20 -> V_21 -> V_22 ) ;
}
static void F_14 ( struct V_19 * V_20 , int V_23 )
{
F_15 ( V_20 -> V_21 -> V_22 , V_23 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
return F_13 ( V_20 -> V_21 -> V_24 ) ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_21 ;
struct V_6 * V_7 = & V_20 -> V_7 ;
int V_27 = 0 ;
V_27 = F_18 ( V_26 -> V_22 , V_28 |
V_29 , L_3 ) ;
if ( V_27 ) {
F_19 ( V_7 , L_4 , V_26 -> V_22 ) ;
return V_27 ;
}
if ( V_26 -> V_30 ) {
if ( F_18 ( V_26 -> V_24 , V_31 , L_5 ) ) {
F_19 ( V_7 , L_6 ,
V_26 -> V_24 ) ;
V_26 -> V_30 = NULL ;
}
}
return V_27 ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_21 ;
if ( V_26 -> V_30 )
F_21 ( V_26 -> V_24 ) ;
F_21 ( V_26 -> V_22 ) ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_21 ;
int V_32 = 0 , V_23 = 1 , V_27 = 0 ;
if ( V_26 -> V_33 )
V_26 -> V_33 ( V_26 ) ;
while ( V_32 ++ < V_34 * 2 ) {
if ( V_23 ) {
if ( V_26 -> V_30 && V_26 -> V_30 ( V_20 ) )
break;
if ( ! V_26 -> V_35 ( V_20 ) ) {
F_23 ( & V_20 -> V_7 ,
L_7 ) ;
V_27 = - V_36 ;
break;
}
}
V_23 = ! V_23 ;
V_26 -> V_37 ( V_20 , V_23 ) ;
F_24 ( V_38 ) ;
}
if ( V_26 -> V_39 )
V_26 -> V_39 ( V_26 ) ;
return V_27 ;
}
int F_25 ( struct V_19 * V_20 )
{
V_20 -> V_21 -> V_37 ( V_20 , 1 ) ;
return F_22 ( V_20 ) ;
}
int F_26 ( struct V_19 * V_20 )
{
int V_27 ;
V_27 = F_17 ( V_20 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_22 ( V_20 ) ;
F_20 ( V_20 ) ;
return V_27 ;
}
int F_27 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_21 )
return - V_40 ;
F_11 ( & V_20 -> V_7 , L_8 ) ;
return V_20 -> V_21 -> V_41 ( V_20 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_42 ;
if ( ! V_4 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_43 || ! V_11 -> V_12 )
return - V_16 ;
if ( ! F_29 ( & V_4 -> V_7 ) )
F_30 ( & V_4 -> V_7 ,
V_4 -> V_44 & V_45 ) ;
F_11 ( V_7 , L_9 ) ;
F_31 ( & V_4 -> V_7 , true ) ;
V_42 = V_11 -> V_43 ( V_4 , F_1 ( V_11 -> V_12 , V_4 ) ) ;
if ( V_42 )
F_32 ( & V_4 -> V_7 , true ) ;
return V_42 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_42 = 0 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> remove ) {
F_11 ( V_7 , L_10 ) ;
V_42 = V_11 -> remove ( V_4 ) ;
}
F_32 ( & V_4 -> V_7 , true ) ;
return V_42 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> V_46 )
V_11 -> V_46 ( V_4 ) ;
}
static int F_35 ( struct V_6 * V_7 , T_1 V_47 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_48 )
return 0 ;
return V_11 -> V_48 ( V_4 , V_47 ) ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_49 )
return 0 ;
return V_11 -> V_49 ( V_4 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_38 ( V_7 ) ;
else
return F_35 ( V_7 , V_52 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_40 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_42 ( V_7 ) ;
else
return F_35 ( V_7 , V_53 ) ;
}
static int F_43 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_44 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static int F_45 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_46 ( V_7 ) ;
else
return F_35 ( V_7 , V_54 ) ;
}
static int F_47 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = V_7 -> V_11 ? V_7 -> V_11 -> V_51 : NULL ;
if ( V_51 )
return F_48 ( V_7 ) ;
else
return F_36 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_50 ( F_8 ( V_7 ) ) ;
}
static T_2
F_51 ( struct V_6 * V_7 , struct V_55 * V_56 , char * V_57 )
{
return sprintf ( V_57 , L_11 , V_7 -> type == & V_58 ?
F_8 ( V_7 ) -> V_5 : F_52 ( V_7 ) -> V_5 ) ;
}
static T_2
F_53 ( struct V_6 * V_7 , struct V_55 * V_56 , char * V_57 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
int V_59 ;
V_59 = F_54 ( V_7 , V_57 , V_60 - 1 ) ;
if ( V_59 != - V_16 )
return V_59 ;
return sprintf ( V_57 , L_12 , V_17 , V_4 -> V_5 ) ;
}
struct V_3 * F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_58 )
? F_8 ( V_7 )
: NULL ;
}
static int F_55 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_44 & V_61 ) {
if ( V_4 -> V_62 > 0x3ff )
return - V_63 ;
} else {
if ( V_4 -> V_62 == 0x00 || V_4 -> V_62 > 0x7f )
return - V_63 ;
}
return 0 ;
}
static int F_56 ( unsigned short V_62 )
{
if ( V_62 < 0x08 || V_62 > 0x77 )
return - V_63 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 , void * V_64 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
int V_62 = * ( int * ) V_64 ;
if ( V_4 && V_4 -> V_62 == V_62 )
return - V_36 ;
return 0 ;
}
static int F_58 ( struct V_19 * V_65 , int V_62 )
{
struct V_19 * V_66 = F_59 ( V_65 ) ;
int V_67 ;
V_67 = F_60 ( & V_65 -> V_7 , & V_62 ,
F_57 ) ;
if ( ! V_67 && V_66 )
V_67 = F_58 ( V_66 , V_62 ) ;
return V_67 ;
}
static int F_61 ( struct V_6 * V_7 , void * V_64 )
{
int V_67 ;
if ( V_7 -> type == & V_68 )
V_67 = F_60 ( V_7 , V_64 ,
F_61 ) ;
else
V_67 = F_57 ( V_7 , V_64 ) ;
return V_67 ;
}
static int F_62 ( struct V_19 * V_65 , int V_62 )
{
struct V_19 * V_66 = F_59 ( V_65 ) ;
int V_67 = 0 ;
if ( V_66 )
V_67 = F_58 ( V_66 , V_62 ) ;
if ( ! V_67 )
V_67 = F_60 ( & V_65 -> V_7 , & V_62 ,
F_61 ) ;
return V_67 ;
}
void F_63 ( struct V_19 * V_65 )
{
struct V_19 * V_66 = F_59 ( V_65 ) ;
if ( V_66 )
F_63 ( V_66 ) ;
else
F_64 ( & V_65 -> V_69 ) ;
}
static int F_65 ( struct V_19 * V_65 )
{
struct V_19 * V_66 = F_59 ( V_65 ) ;
if ( V_66 )
return F_65 ( V_66 ) ;
else
return F_66 ( & V_65 -> V_69 ) ;
}
void F_67 ( struct V_19 * V_65 )
{
struct V_19 * V_66 = F_59 ( V_65 ) ;
if ( V_66 )
F_67 ( V_66 ) ;
else
F_68 ( & V_65 -> V_69 ) ;
}
static void F_69 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_70 * V_71 = F_70 ( & V_4 -> V_7 ) ;
if ( V_71 ) {
F_71 ( & V_4 -> V_7 , L_13 , F_72 ( V_71 ) ) ;
return;
}
F_71 ( & V_4 -> V_7 , L_14 , F_73 ( V_20 ) ,
V_4 -> V_62 | ( ( V_4 -> V_44 & V_61 )
? 0xa000 : 0 ) ) ;
}
struct V_3 *
F_74 ( struct V_19 * V_20 , struct V_72 const * V_73 )
{
struct V_3 * V_4 ;
int V_42 ;
V_4 = F_75 ( sizeof *V_4 , V_74 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_65 = V_20 ;
V_4 -> V_7 . V_75 = V_73 -> V_75 ;
if ( V_73 -> V_76 )
V_4 -> V_7 . V_76 = * V_73 -> V_76 ;
V_4 -> V_44 = V_73 -> V_44 ;
V_4 -> V_62 = V_73 -> V_62 ;
V_4 -> V_77 = V_73 -> V_77 ;
F_76 ( V_4 -> V_5 , V_73 -> type , sizeof( V_4 -> V_5 ) ) ;
V_42 = F_55 ( V_4 ) ;
if ( V_42 ) {
F_23 ( & V_20 -> V_7 , L_15 ,
V_4 -> V_44 & V_61 ? 10 : 7 , V_4 -> V_62 ) ;
goto V_78;
}
V_42 = F_62 ( V_20 , V_4 -> V_62 ) ;
if ( V_42 )
goto V_79;
V_4 -> V_7 . V_66 = & V_4 -> V_65 -> V_7 ;
V_4 -> V_7 . V_80 = & V_81 ;
V_4 -> V_7 . type = & V_58 ;
V_4 -> V_7 . V_82 = V_73 -> V_82 ;
F_77 ( & V_4 -> V_7 , V_73 -> V_83 . V_84 ) ;
F_69 ( V_20 , V_4 ) ;
V_42 = F_78 ( & V_4 -> V_7 ) ;
if ( V_42 )
goto V_79;
F_11 ( & V_20 -> V_7 , L_16 ,
V_4 -> V_5 , F_79 ( & V_4 -> V_7 ) ) ;
return V_4 ;
V_79:
F_23 ( & V_20 -> V_7 , L_17
L_18 , V_4 -> V_5 , V_4 -> V_62 , V_42 ) ;
V_78:
F_50 ( V_4 ) ;
return NULL ;
}
void F_80 ( struct V_3 * V_4 )
{
F_81 ( & V_4 -> V_7 ) ;
}
static int F_82 ( struct V_3 * V_4 ,
const struct V_1 * V_2 )
{
return 0 ;
}
static int F_83 ( struct V_3 * V_4 )
{
return 0 ;
}
struct V_3 * F_84 ( struct V_19 * V_65 , T_3 V_85 )
{
struct V_72 V_73 = {
F_85 ( L_19 , V_85 ) ,
} ;
return F_74 ( V_65 , & V_73 ) ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = F_52 ( V_7 ) ;
F_87 ( & V_20 -> V_86 ) ;
}
static inline unsigned int F_88 ( struct V_19 * V_65 )
{
unsigned int V_87 = 0 ;
while ( ( V_65 = F_59 ( V_65 ) ) )
V_87 ++ ;
return V_87 ;
}
static T_2
F_89 ( struct V_6 * V_7 , struct V_55 * V_56 ,
const char * V_57 , T_4 V_88 )
{
struct V_19 * V_20 = F_52 ( V_7 ) ;
struct V_72 V_73 ;
struct V_3 * V_4 ;
char * V_89 , V_90 ;
int V_91 ;
memset ( & V_73 , 0 , sizeof( struct V_72 ) ) ;
V_89 = strchr ( V_57 , ' ' ) ;
if ( ! V_89 ) {
F_23 ( V_7 , L_20 , L_21 ) ;
return - V_63 ;
}
if ( V_89 - V_57 > V_92 - 1 ) {
F_23 ( V_7 , L_22 , L_21 ) ;
return - V_63 ;
}
memcpy ( V_73 . type , V_57 , V_89 - V_57 ) ;
V_91 = sscanf ( ++ V_89 , L_23 , & V_73 . V_62 , & V_90 ) ;
if ( V_91 < 1 ) {
F_23 ( V_7 , L_24 , L_21 ) ;
return - V_63 ;
}
if ( V_91 > 1 && V_90 != '\n' ) {
F_23 ( V_7 , L_25 , L_21 ) ;
return - V_63 ;
}
V_4 = F_74 ( V_20 , & V_73 ) ;
if ( ! V_4 )
return - V_63 ;
F_90 ( & V_20 -> V_93 ) ;
F_91 ( & V_4 -> V_94 , & V_20 -> V_95 ) ;
F_92 ( & V_20 -> V_93 ) ;
F_93 ( V_7 , L_26 , L_21 ,
V_73 . type , V_73 . V_62 ) ;
return V_88 ;
}
static T_2
F_94 ( struct V_6 * V_7 , struct V_55 * V_56 ,
const char * V_57 , T_4 V_88 )
{
struct V_19 * V_20 = F_52 ( V_7 ) ;
struct V_3 * V_4 , * V_96 ;
unsigned short V_62 ;
char V_90 ;
int V_91 ;
V_91 = sscanf ( V_57 , L_23 , & V_62 , & V_90 ) ;
if ( V_91 < 1 ) {
F_23 ( V_7 , L_24 , L_27 ) ;
return - V_63 ;
}
if ( V_91 > 1 && V_90 != '\n' ) {
F_23 ( V_7 , L_25 , L_27 ) ;
return - V_63 ;
}
V_91 = - V_97 ;
F_95 ( & V_20 -> V_93 ,
F_88 ( V_20 ) ) ;
F_96 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_62 == V_62 ) {
F_93 ( V_7 , L_28 ,
L_27 , V_4 -> V_5 , V_4 -> V_62 ) ;
F_97 ( & V_4 -> V_94 ) ;
F_80 ( V_4 ) ;
V_91 = V_88 ;
break;
}
}
F_92 ( & V_20 -> V_93 ) ;
if ( V_91 < 0 )
F_23 ( V_7 , L_29 ,
L_27 ) ;
return V_91 ;
}
struct V_19 * F_98 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_68 )
? F_52 ( V_7 )
: NULL ;
}
static void F_99 ( struct V_19 * V_65 )
{
struct V_98 * V_99 ;
F_100 ( & V_100 ) ;
F_101 (devinfo, &__i2c_board_list, list) {
if ( V_99 -> V_101 == V_65 -> V_102
&& ! F_74 ( V_65 ,
& V_99 -> V_103 ) )
F_23 ( & V_65 -> V_7 ,
L_30 ,
V_99 -> V_103 . V_62 ) ;
}
F_102 ( & V_100 ) ;
}
static void F_103 ( struct V_19 * V_20 )
{
void * V_67 ;
struct V_104 * V_105 ;
if ( ! V_20 -> V_7 . V_82 )
return;
F_11 ( & V_20 -> V_7 , L_31 ) ;
F_104 (adap->dev.of_node, node) {
struct V_72 V_73 = {} ;
struct V_106 V_107 = {} ;
const T_5 * V_62 ;
int V_59 ;
F_11 ( & V_20 -> V_7 , L_32 , V_105 -> V_108 ) ;
if ( F_105 ( V_105 , V_73 . type , sizeof( V_73 . type ) ) < 0 ) {
F_23 ( & V_20 -> V_7 , L_33 ,
V_105 -> V_108 ) ;
continue;
}
V_62 = F_106 ( V_105 , L_34 , & V_59 ) ;
if ( ! V_62 || ( V_59 < sizeof( int ) ) ) {
F_23 ( & V_20 -> V_7 , L_35 ,
V_105 -> V_108 ) ;
continue;
}
V_73 . V_62 = F_107 ( V_62 ) ;
if ( V_73 . V_62 > ( 1 << 10 ) - 1 ) {
F_23 ( & V_20 -> V_7 , L_36 ,
V_73 . V_62 , V_105 -> V_108 ) ;
continue;
}
V_73 . V_77 = F_108 ( V_105 , 0 ) ;
V_73 . V_82 = F_109 ( V_105 ) ;
V_73 . V_76 = & V_107 ;
if ( F_106 ( V_105 , L_37 , NULL ) )
V_73 . V_44 |= V_45 ;
F_110 ( L_38 , V_17 , V_73 . type ) ;
V_67 = F_74 ( V_20 , & V_73 ) ;
if ( V_67 == NULL ) {
F_23 ( & V_20 -> V_7 , L_39 ,
V_105 -> V_108 ) ;
F_111 ( V_105 ) ;
F_112 ( V_73 . V_77 ) ;
continue;
}
}
}
static int F_113 ( struct V_6 * V_7 , void * V_109 )
{
return V_7 -> V_82 == V_109 ;
}
struct V_3 * F_114 ( struct V_104 * V_105 )
{
struct V_6 * V_7 ;
V_7 = F_115 ( & V_81 , NULL , V_105 ,
F_113 ) ;
if ( ! V_7 )
return NULL ;
return F_3 ( V_7 ) ;
}
struct V_19 * F_116 ( struct V_104 * V_105 )
{
struct V_6 * V_7 ;
V_7 = F_115 ( & V_81 , NULL , V_105 ,
F_113 ) ;
if ( ! V_7 )
return NULL ;
return F_98 ( V_7 ) ;
}
static void F_103 ( struct V_19 * V_20 ) { }
static int F_117 ( struct V_110 * V_111 , void * V_109 )
{
struct V_72 * V_73 = V_109 ;
if ( V_111 -> type == V_112 ) {
struct V_113 * V_114 ;
V_114 = & V_111 -> V_109 . V_115 ;
if ( V_114 -> type == V_116 ) {
V_73 -> V_62 = V_114 -> V_117 ;
if ( V_114 -> V_118 == V_119 )
V_73 -> V_44 |= V_61 ;
}
} else if ( V_73 -> V_77 < 0 ) {
struct V_120 V_121 ;
if ( F_118 ( V_111 , 0 , & V_121 ) )
V_73 -> V_77 = V_121 . V_122 ;
}
return 1 ;
}
static T_6 F_119 ( T_7 V_123 , T_8 V_124 ,
void * V_109 , void * * V_125 )
{
struct V_19 * V_65 = V_109 ;
struct V_126 V_127 ;
struct V_72 V_73 ;
struct V_70 * V_71 ;
int V_27 ;
if ( F_120 ( V_123 , & V_71 ) )
return V_128 ;
if ( F_121 ( V_71 ) || ! V_71 -> V_42 . V_129 )
return V_128 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_83 . V_84 = V_71 ;
V_73 . V_77 = - 1 ;
F_122 ( & V_127 ) ;
V_27 = F_123 ( V_71 , & V_127 ,
F_117 , & V_73 ) ;
F_124 ( & V_127 ) ;
if ( V_27 < 0 || ! V_73 . V_62 )
return V_128 ;
V_71 -> V_130 . V_44 . V_131 = true ;
F_76 ( V_73 . type , F_79 ( & V_71 -> V_7 ) , sizeof( V_73 . type ) ) ;
if ( ! F_74 ( V_65 , & V_73 ) ) {
V_71 -> V_130 . V_44 . V_131 = false ;
F_23 ( & V_65 -> V_7 ,
L_40 ,
F_79 ( & V_71 -> V_7 ) ) ;
}
return V_128 ;
}
static void F_125 ( struct V_19 * V_20 )
{
T_7 V_123 ;
T_6 V_42 ;
if ( ! V_20 -> V_7 . V_66 )
return;
V_123 = F_126 ( V_20 -> V_7 . V_66 ) ;
if ( ! V_123 )
return;
V_42 = F_127 ( V_132 , V_123 , 1 ,
F_119 , NULL ,
V_20 , NULL ) ;
if ( F_128 ( V_42 ) )
F_19 ( & V_20 -> V_7 , L_41 ) ;
}
static inline void F_125 ( struct V_19 * V_20 ) {}
static int F_129 ( struct V_10 * V_11 ,
struct V_19 * V_20 )
{
F_130 ( V_20 , V_11 ) ;
if ( V_11 -> V_133 ) {
F_19 ( & V_20 -> V_7 , L_42 ,
V_11 -> V_11 . V_5 ) ;
F_19 ( & V_20 -> V_7 , L_43
L_44 ) ;
V_11 -> V_133 ( V_20 ) ;
}
return 0 ;
}
static int F_131 ( struct V_8 * V_134 , void * V_109 )
{
return F_129 ( F_6 ( V_134 ) , V_109 ) ;
}
static int F_132 ( struct V_19 * V_20 )
{
int V_91 = 0 ;
if ( F_133 ( F_134 ( ! V_81 . V_135 ) ) ) {
V_91 = - V_136 ;
goto V_137;
}
if ( F_133 ( V_20 -> V_5 [ 0 ] == '\0' ) ) {
F_135 ( L_45
L_46 ) ;
return - V_63 ;
}
if ( F_133 ( ! V_20 -> V_138 ) ) {
F_135 ( L_47
L_48 , V_20 -> V_5 ) ;
return - V_63 ;
}
F_136 ( & V_20 -> V_69 ) ;
F_137 ( & V_20 -> V_93 ) ;
F_122 ( & V_20 -> V_95 ) ;
if ( V_20 -> V_139 == 0 )
V_20 -> V_139 = V_140 ;
F_71 ( & V_20 -> V_7 , L_49 , V_20 -> V_102 ) ;
V_20 -> V_7 . V_80 = & V_81 ;
V_20 -> V_7 . type = & V_68 ;
V_91 = F_78 ( & V_20 -> V_7 ) ;
if ( V_91 )
goto V_137;
F_11 ( & V_20 -> V_7 , L_50 , V_20 -> V_5 ) ;
#ifdef F_138
V_91 = F_139 ( V_141 , & V_20 -> V_7 ,
V_20 -> V_7 . V_66 ) ;
if ( V_91 )
F_19 ( & V_20 -> V_7 ,
L_51 ) ;
#endif
if ( V_20 -> V_21 ) {
struct V_25 * V_26 = V_20 -> V_21 ;
if ( ! V_26 -> V_41 ) {
F_23 ( & V_20 -> V_7 , L_52 ) ;
V_20 -> V_21 = NULL ;
goto V_142;
}
if ( V_26 -> V_41 == F_26 ) {
if ( ! F_140 ( V_26 -> V_22 ) ) {
F_23 ( & V_20 -> V_7 , L_53 ) ;
V_20 -> V_21 = NULL ;
goto V_142;
}
if ( F_140 ( V_26 -> V_24 ) )
V_26 -> V_30 = F_16 ;
else
V_26 -> V_30 = NULL ;
V_26 -> V_35 = F_12 ;
V_26 -> V_37 = F_14 ;
} else if ( ! V_26 -> V_37 || ! V_26 -> V_35 ) {
F_23 ( & V_20 -> V_7 , L_54 ) ;
V_20 -> V_21 = NULL ;
}
}
V_142:
F_103 ( V_20 ) ;
F_125 ( V_20 ) ;
if ( V_20 -> V_102 < V_143 )
F_99 ( V_20 ) ;
F_90 ( & V_144 ) ;
F_141 ( & V_81 , NULL , V_20 , F_131 ) ;
F_92 ( & V_144 ) ;
return 0 ;
V_137:
F_90 ( & V_144 ) ;
F_142 ( & V_145 , V_20 -> V_102 ) ;
F_92 ( & V_144 ) ;
return V_91 ;
}
static int F_143 ( struct V_19 * V_20 )
{
int V_2 ;
F_90 ( & V_144 ) ;
V_2 = F_144 ( & V_145 , V_20 , V_20 -> V_102 , V_20 -> V_102 + 1 ,
V_74 ) ;
F_92 ( & V_144 ) ;
if ( V_2 < 0 )
return V_2 == - V_146 ? - V_36 : V_2 ;
return F_132 ( V_20 ) ;
}
int F_145 ( struct V_19 * V_65 )
{
struct V_6 * V_7 = & V_65 -> V_7 ;
int V_2 ;
if ( V_7 -> V_82 ) {
V_2 = F_146 ( V_7 -> V_82 , L_55 ) ;
if ( V_2 >= 0 ) {
V_65 -> V_102 = V_2 ;
return F_143 ( V_65 ) ;
}
}
F_90 ( & V_144 ) ;
V_2 = F_144 ( & V_145 , V_65 ,
V_143 , 0 , V_74 ) ;
F_92 ( & V_144 ) ;
if ( V_2 < 0 )
return V_2 ;
V_65 -> V_102 = V_2 ;
return F_132 ( V_65 ) ;
}
int F_147 ( struct V_19 * V_20 )
{
if ( V_20 -> V_102 == - 1 )
return F_145 ( V_20 ) ;
return F_143 ( V_20 ) ;
}
static void F_148 ( struct V_10 * V_11 ,
struct V_19 * V_65 )
{
struct V_3 * V_4 , * V_147 ;
F_96 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_65 == V_65 ) {
F_11 ( & V_65 -> V_7 , L_56 ,
V_4 -> V_5 , V_4 -> V_62 ) ;
F_97 ( & V_4 -> V_94 ) ;
F_80 ( V_4 ) ;
}
}
}
static int F_149 ( struct V_6 * V_7 , void * V_148 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_19 ) )
F_80 ( V_4 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * V_7 , void * V_148 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_80 ( V_4 ) ;
return 0 ;
}
static int F_151 ( struct V_8 * V_134 , void * V_109 )
{
F_148 ( F_6 ( V_134 ) , V_109 ) ;
return 0 ;
}
void F_152 ( struct V_19 * V_20 )
{
struct V_19 * V_149 ;
struct V_3 * V_4 , * V_96 ;
F_90 ( & V_144 ) ;
V_149 = F_153 ( & V_145 , V_20 -> V_102 ) ;
F_92 ( & V_144 ) ;
if ( V_149 != V_20 ) {
F_154 ( L_57
L_58 , V_20 -> V_5 ) ;
return;
}
F_90 ( & V_144 ) ;
F_141 ( & V_81 , NULL , V_20 ,
F_151 ) ;
F_92 ( & V_144 ) ;
F_95 ( & V_20 -> V_93 ,
F_88 ( V_20 ) ) ;
F_96 (client, next, &adap->userspace_clients,
detected) {
F_11 ( & V_20 -> V_7 , L_56 , V_4 -> V_5 ,
V_4 -> V_62 ) ;
F_97 ( & V_4 -> V_94 ) ;
F_80 ( V_4 ) ;
}
F_92 ( & V_20 -> V_93 ) ;
F_60 ( & V_20 -> V_7 , NULL , F_149 ) ;
F_60 ( & V_20 -> V_7 , NULL , F_150 ) ;
#ifdef F_138
F_155 ( V_141 , & V_20 -> V_7 ,
V_20 -> V_7 . V_66 ) ;
#endif
F_11 ( & V_20 -> V_7 , L_59 , V_20 -> V_5 ) ;
F_156 ( & V_20 -> V_86 ) ;
F_81 ( & V_20 -> V_7 ) ;
F_157 ( & V_20 -> V_86 ) ;
F_90 ( & V_144 ) ;
F_142 ( & V_145 , V_20 -> V_102 ) ;
F_92 ( & V_144 ) ;
memset ( & V_20 -> V_7 , 0 , sizeof( V_20 -> V_7 ) ) ;
}
int F_158 ( void * V_109 , int (* F_159)( struct V_6 * , void * ) )
{
int V_91 ;
F_90 ( & V_144 ) ;
V_91 = F_160 ( & V_81 , NULL , V_109 , F_159 ) ;
F_92 ( & V_144 ) ;
return V_91 ;
}
static int F_161 ( struct V_6 * V_7 , void * V_109 )
{
if ( V_7 -> type != & V_68 )
return 0 ;
return F_129 ( V_109 , F_52 ( V_7 ) ) ;
}
int F_162 ( struct V_150 * V_151 , struct V_10 * V_11 )
{
int V_91 ;
if ( F_133 ( F_134 ( ! V_81 . V_135 ) ) )
return - V_136 ;
V_11 -> V_11 . V_151 = V_151 ;
V_11 -> V_11 . V_80 = & V_81 ;
V_91 = F_163 ( & V_11 -> V_11 ) ;
if ( V_91 )
return V_91 ;
if ( V_11 -> V_48 )
F_164 ( L_60 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_49 )
F_164 ( L_61 ,
V_11 -> V_11 . V_5 ) ;
F_154 ( L_62 , V_11 -> V_11 . V_5 ) ;
F_122 ( & V_11 -> V_152 ) ;
F_158 ( V_11 , F_161 ) ;
return 0 ;
}
static int F_165 ( struct V_6 * V_7 , void * V_109 )
{
if ( V_7 -> type == & V_68 )
F_148 ( V_109 , F_52 ( V_7 ) ) ;
return 0 ;
}
void F_166 ( struct V_10 * V_11 )
{
F_158 ( V_11 , F_165 ) ;
F_167 ( & V_11 -> V_11 ) ;
F_154 ( L_63 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_168 ( struct V_3 * V_4 )
{
if ( V_4 && F_169 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_170 ( struct V_3 * V_4 )
{
if ( V_4 )
F_171 ( & V_4 -> V_7 ) ;
}
static int F_172 ( struct V_6 * V_7 , void * V_153 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_154 * V_155 = V_153 ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_4 -> V_7 . V_11 )
return 0 ;
V_11 = F_6 ( V_4 -> V_7 . V_11 ) ;
if ( V_11 -> V_156 )
V_11 -> V_156 ( V_4 , V_155 -> V_157 , V_155 -> V_155 ) ;
return 0 ;
}
void F_173 ( struct V_19 * V_20 , unsigned int V_157 , void * V_155 )
{
struct V_154 V_158 ;
V_158 . V_157 = V_157 ;
V_158 . V_155 = V_155 ;
F_60 ( & V_20 -> V_7 , & V_158 , F_172 ) ;
}
static int T_9 F_174 ( void )
{
int V_159 ;
V_159 = F_175 ( & V_81 ) ;
if ( V_159 )
return V_159 ;
#ifdef F_138
V_141 = F_176 ( L_64 ) ;
if ( ! V_141 ) {
V_159 = - V_18 ;
goto V_160;
}
#endif
V_159 = F_177 ( & V_161 ) ;
if ( V_159 )
goto V_162;
return 0 ;
V_162:
#ifdef F_138
F_178 ( V_141 ) ;
V_160:
#endif
F_179 ( & V_81 ) ;
return V_159 ;
}
static void T_10 F_180 ( void )
{
F_166 ( & V_161 ) ;
#ifdef F_138
F_178 ( V_141 ) ;
#endif
F_179 ( & V_81 ) ;
}
int F_181 ( struct V_19 * V_20 , struct V_163 * V_164 , int V_165 )
{
unsigned long V_166 ;
int V_27 , V_167 ;
V_166 = V_168 ;
for ( V_27 = 0 , V_167 = 0 ; V_167 <= V_20 -> V_169 ; V_167 ++ ) {
V_27 = V_20 -> V_138 -> V_170 ( V_20 , V_164 , V_165 ) ;
if ( V_27 != - V_136 )
break;
if ( F_182 ( V_168 , V_166 + V_20 -> V_139 ) )
break;
}
return V_27 ;
}
int F_183 ( struct V_19 * V_20 , struct V_163 * V_164 , int V_165 )
{
int V_27 ;
if ( V_20 -> V_138 -> V_170 ) {
#ifdef F_184
for ( V_27 = 0 ; V_27 < V_165 ; V_27 ++ ) {
F_11 ( & V_20 -> V_7 , L_65
L_66 , V_27 , ( V_164 [ V_27 ] . V_44 & V_171 )
? 'R' : 'W' , V_164 [ V_27 ] . V_62 , V_164 [ V_27 ] . V_59 ,
( V_164 [ V_27 ] . V_44 & V_172 ) ? L_67 : L_68 ) ;
}
#endif
if ( F_185 () || F_186 () ) {
V_27 = F_65 ( V_20 ) ;
if ( ! V_27 )
return - V_136 ;
} else {
F_63 ( V_20 ) ;
}
V_27 = F_181 ( V_20 , V_164 , V_165 ) ;
F_67 ( V_20 ) ;
return V_27 ;
} else {
F_11 ( & V_20 -> V_7 , L_69 ) ;
return - V_40 ;
}
}
int F_187 ( const struct V_3 * V_4 , const char * V_57 , int V_88 )
{
int V_27 ;
struct V_19 * V_20 = V_4 -> V_65 ;
struct V_163 V_173 ;
V_173 . V_62 = V_4 -> V_62 ;
V_173 . V_44 = V_4 -> V_44 & V_174 ;
V_173 . V_59 = V_88 ;
V_173 . V_57 = ( char * ) V_57 ;
V_27 = F_183 ( V_20 , & V_173 , 1 ) ;
return ( V_27 == 1 ) ? V_88 : V_27 ;
}
int F_188 ( const struct V_3 * V_4 , char * V_57 , int V_88 )
{
struct V_19 * V_20 = V_4 -> V_65 ;
struct V_163 V_173 ;
int V_27 ;
V_173 . V_62 = V_4 -> V_62 ;
V_173 . V_44 = V_4 -> V_44 & V_174 ;
V_173 . V_44 |= V_171 ;
V_173 . V_59 = V_88 ;
V_173 . V_57 = V_57 ;
V_27 = F_183 ( V_20 , & V_173 , 1 ) ;
return ( V_27 == 1 ) ? V_88 : V_27 ;
}
static int F_189 ( struct V_19 * V_20 , unsigned short V_62 )
{
int V_175 ;
union V_176 V_148 ;
#ifdef F_190
if ( V_62 == 0x73 && ( V_20 -> V_177 & V_178 )
&& F_191 ( V_20 , V_179 ) )
V_175 = F_192 ( V_20 , V_62 , 0 , V_180 , 0 ,
V_181 , & V_148 ) ;
else
#endif
if ( ! ( ( V_62 & ~ 0x07 ) == 0x30 || ( V_62 & ~ 0x0f ) == 0x50 )
&& F_191 ( V_20 , V_182 ) )
V_175 = F_192 ( V_20 , V_62 , 0 , V_183 , 0 ,
V_184 , NULL ) ;
else if ( F_191 ( V_20 , V_185 ) )
V_175 = F_192 ( V_20 , V_62 , 0 , V_180 , 0 ,
V_186 , & V_148 ) ;
else {
F_19 ( & V_20 -> V_7 , L_70 ,
V_62 ) ;
V_175 = - V_40 ;
}
return V_175 >= 0 ;
}
static int F_193 ( struct V_3 * V_187 ,
struct V_10 * V_11 )
{
struct V_72 V_73 ;
struct V_19 * V_65 = V_187 -> V_65 ;
int V_62 = V_187 -> V_62 ;
int V_175 ;
V_175 = F_56 ( V_62 ) ;
if ( V_175 ) {
F_19 ( & V_65 -> V_7 , L_71 ,
V_62 ) ;
return V_175 ;
}
if ( F_62 ( V_65 , V_62 ) )
return 0 ;
if ( ! F_189 ( V_65 , V_62 ) )
return 0 ;
memset ( & V_73 , 0 , sizeof( struct V_72 ) ) ;
V_73 . V_62 = V_62 ;
V_175 = V_11 -> V_188 ( V_187 , & V_73 ) ;
if ( V_175 ) {
return V_175 == - V_16 ? 0 : V_175 ;
}
if ( V_73 . type [ 0 ] == '\0' ) {
F_23 ( & V_65 -> V_7 , L_72
L_73 , V_11 -> V_11 . V_5 ,
V_62 ) ;
} else {
struct V_3 * V_4 ;
F_11 ( & V_65 -> V_7 , L_74 ,
V_73 . type , V_73 . V_62 ) ;
V_4 = F_74 ( V_65 , & V_73 ) ;
if ( V_4 )
F_91 ( & V_4 -> V_94 , & V_11 -> V_152 ) ;
else
F_23 ( & V_65 -> V_7 , L_75 ,
V_73 . type , V_73 . V_62 ) ;
}
return 0 ;
}
static int F_130 ( struct V_19 * V_65 , struct V_10 * V_11 )
{
const unsigned short * V_189 ;
struct V_3 * V_187 ;
int V_32 , V_175 = 0 ;
int V_190 = F_73 ( V_65 ) ;
V_189 = V_11 -> V_189 ;
if ( ! V_11 -> V_188 || ! V_189 )
return 0 ;
if ( ! ( V_65 -> V_177 & V_11 -> V_177 ) )
return 0 ;
V_187 = F_75 ( sizeof( struct V_3 ) , V_74 ) ;
if ( ! V_187 )
return - V_18 ;
V_187 -> V_65 = V_65 ;
for ( V_32 = 0 ; V_189 [ V_32 ] != V_191 ; V_32 += 1 ) {
F_11 ( & V_65 -> V_7 , L_76
L_77 , V_190 , V_189 [ V_32 ] ) ;
V_187 -> V_62 = V_189 [ V_32 ] ;
V_175 = F_193 ( V_187 , V_11 ) ;
if ( F_133 ( V_175 ) )
break;
}
F_50 ( V_187 ) ;
return V_175 ;
}
int F_194 ( struct V_19 * V_20 , unsigned short V_62 )
{
return F_192 ( V_20 , V_62 , 0 , V_180 , 0 ,
V_184 , NULL ) >= 0 ;
}
struct V_3 *
F_195 ( struct V_19 * V_20 ,
struct V_72 * V_73 ,
unsigned short const * V_192 ,
int (* V_43)( struct V_19 * , unsigned short V_62 ) )
{
int V_32 ;
if ( ! V_43 )
V_43 = F_189 ;
for ( V_32 = 0 ; V_192 [ V_32 ] != V_191 ; V_32 ++ ) {
if ( F_56 ( V_192 [ V_32 ] ) < 0 ) {
F_19 ( & V_20 -> V_7 , L_78
L_79 , V_192 [ V_32 ] ) ;
continue;
}
if ( F_62 ( V_20 , V_192 [ V_32 ] ) ) {
F_11 ( & V_20 -> V_7 , L_80
L_81 , V_192 [ V_32 ] ) ;
continue;
}
if ( V_43 ( V_20 , V_192 [ V_32 ] ) )
break;
}
if ( V_192 [ V_32 ] == V_191 ) {
F_11 ( & V_20 -> V_7 , L_82 ) ;
return NULL ;
}
V_73 -> V_62 = V_192 [ V_32 ] ;
return F_74 ( V_20 , V_73 ) ;
}
struct V_19 * F_196 ( int V_102 )
{
struct V_19 * V_65 ;
F_90 ( & V_144 ) ;
V_65 = F_153 ( & V_145 , V_102 ) ;
if ( V_65 && ! F_197 ( V_65 -> V_151 ) )
V_65 = NULL ;
F_92 ( & V_144 ) ;
return V_65 ;
}
void F_198 ( struct V_19 * V_20 )
{
if ( V_20 )
F_199 ( V_20 -> V_151 ) ;
}
static T_11 F_200 ( T_3 V_109 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
if ( V_109 & 0x8000 )
V_109 = V_109 ^ V_193 ;
V_109 = V_109 << 1 ;
}
return ( T_11 ) ( V_109 >> 8 ) ;
}
static T_11 F_201 ( T_11 V_194 , T_11 * V_135 , T_4 V_88 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ )
V_194 = F_200 ( ( V_194 ^ V_135 [ V_32 ] ) << 8 ) ;
return V_194 ;
}
static T_11 F_202 ( T_11 V_195 , struct V_163 * V_173 )
{
T_11 V_62 = ( V_173 -> V_62 << 1 ) | ! ! ( V_173 -> V_44 & V_171 ) ;
V_195 = F_201 ( V_195 , & V_62 , 1 ) ;
return F_201 ( V_195 , V_173 -> V_57 , V_173 -> V_59 ) ;
}
static inline void F_203 ( struct V_163 * V_173 )
{
V_173 -> V_57 [ V_173 -> V_59 ] = F_202 ( 0 , V_173 ) ;
V_173 -> V_59 ++ ;
}
static int F_204 ( T_11 V_196 , struct V_163 * V_173 )
{
T_11 V_197 = V_173 -> V_57 [ -- V_173 -> V_59 ] ;
V_196 = F_202 ( V_196 , V_173 ) ;
if ( V_197 != V_196 ) {
F_154 ( L_83 ,
V_197 , V_196 ) ;
return - V_198 ;
}
return 0 ;
}
T_12 F_205 ( const struct V_3 * V_4 )
{
union V_176 V_109 ;
int V_42 ;
V_42 = F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_180 , 0 ,
V_186 , & V_109 ) ;
return ( V_42 < 0 ) ? V_42 : V_109 . V_199 ;
}
T_12 F_206 ( const struct V_3 * V_4 , T_11 V_200 )
{
return F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_183 , V_200 , V_186 , NULL ) ;
}
T_12 F_207 ( const struct V_3 * V_4 , T_11 V_156 )
{
union V_176 V_109 ;
int V_42 ;
V_42 = F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_180 , V_156 ,
V_181 , & V_109 ) ;
return ( V_42 < 0 ) ? V_42 : V_109 . V_199 ;
}
T_12 F_208 ( const struct V_3 * V_4 , T_11 V_156 ,
T_11 V_200 )
{
union V_176 V_109 ;
V_109 . V_199 = V_200 ;
return F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_183 , V_156 ,
V_181 , & V_109 ) ;
}
T_12 F_209 ( const struct V_3 * V_4 , T_11 V_156 )
{
union V_176 V_109 ;
int V_42 ;
V_42 = F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_180 , V_156 ,
V_201 , & V_109 ) ;
return ( V_42 < 0 ) ? V_42 : V_109 . V_202 ;
}
T_12 F_210 ( const struct V_3 * V_4 , T_11 V_156 ,
T_3 V_200 )
{
union V_176 V_109 ;
V_109 . V_202 = V_200 ;
return F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_183 , V_156 ,
V_201 , & V_109 ) ;
}
T_12 F_211 ( const struct V_3 * V_4 , T_11 V_156 ,
T_11 * V_203 )
{
union V_176 V_109 ;
int V_42 ;
V_42 = F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_180 , V_156 ,
V_204 , & V_109 ) ;
if ( V_42 )
return V_42 ;
memcpy ( V_203 , & V_109 . V_205 [ 1 ] , V_109 . V_205 [ 0 ] ) ;
return V_109 . V_205 [ 0 ] ;
}
T_12 F_212 ( const struct V_3 * V_4 , T_11 V_156 ,
T_11 V_206 , const T_11 * V_203 )
{
union V_176 V_109 ;
if ( V_206 > V_207 )
V_206 = V_207 ;
V_109 . V_205 [ 0 ] = V_206 ;
memcpy ( & V_109 . V_205 [ 1 ] , V_203 , V_206 ) ;
return F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_183 , V_156 ,
V_204 , & V_109 ) ;
}
T_12 F_213 ( const struct V_3 * V_4 , T_11 V_156 ,
T_11 V_206 , T_11 * V_203 )
{
union V_176 V_109 ;
int V_42 ;
if ( V_206 > V_207 )
V_206 = V_207 ;
V_109 . V_205 [ 0 ] = V_206 ;
V_42 = F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_180 , V_156 ,
V_208 , & V_109 ) ;
if ( V_42 < 0 )
return V_42 ;
memcpy ( V_203 , & V_109 . V_205 [ 1 ] , V_109 . V_205 [ 0 ] ) ;
return V_109 . V_205 [ 0 ] ;
}
T_12 F_214 ( const struct V_3 * V_4 , T_11 V_156 ,
T_11 V_206 , const T_11 * V_203 )
{
union V_176 V_109 ;
if ( V_206 > V_207 )
V_206 = V_207 ;
V_109 . V_205 [ 0 ] = V_206 ;
memcpy ( V_109 . V_205 + 1 , V_203 , V_206 ) ;
return F_192 ( V_4 -> V_65 , V_4 -> V_62 , V_4 -> V_44 ,
V_183 , V_156 ,
V_208 , & V_109 ) ;
}
static T_12 F_215 ( struct V_19 * V_65 , T_3 V_62 ,
unsigned short V_44 ,
char V_209 , T_11 V_156 , int V_210 ,
union V_176 * V_109 )
{
unsigned char V_211 [ V_207 + 3 ] ;
unsigned char V_212 [ V_207 + 2 ] ;
int V_165 = V_209 == V_180 ? 2 : 1 ;
int V_32 ;
T_11 V_213 = 0 ;
int V_42 ;
struct V_163 V_173 [ 2 ] = {
{
. V_62 = V_62 ,
. V_44 = V_44 ,
. V_59 = 1 ,
. V_57 = V_211 ,
} , {
. V_62 = V_62 ,
. V_44 = V_44 | V_171 ,
. V_59 = 0 ,
. V_57 = V_212 ,
} ,
} ;
V_211 [ 0 ] = V_156 ;
switch ( V_210 ) {
case V_184 :
V_173 [ 0 ] . V_59 = 0 ;
V_173 [ 0 ] . V_44 = V_44 | ( V_209 == V_180 ?
V_171 : 0 ) ;
V_165 = 1 ;
break;
case V_186 :
if ( V_209 == V_180 ) {
V_173 [ 0 ] . V_44 = V_171 | V_44 ;
V_165 = 1 ;
}
break;
case V_181 :
if ( V_209 == V_180 )
V_173 [ 1 ] . V_59 = 1 ;
else {
V_173 [ 0 ] . V_59 = 2 ;
V_211 [ 1 ] = V_109 -> V_199 ;
}
break;
case V_201 :
if ( V_209 == V_180 )
V_173 [ 1 ] . V_59 = 2 ;
else {
V_173 [ 0 ] . V_59 = 3 ;
V_211 [ 1 ] = V_109 -> V_202 & 0xff ;
V_211 [ 2 ] = V_109 -> V_202 >> 8 ;
}
break;
case V_214 :
V_165 = 2 ;
V_209 = V_180 ;
V_173 [ 0 ] . V_59 = 3 ;
V_173 [ 1 ] . V_59 = 2 ;
V_211 [ 1 ] = V_109 -> V_202 & 0xff ;
V_211 [ 2 ] = V_109 -> V_202 >> 8 ;
break;
case V_204 :
if ( V_209 == V_180 ) {
V_173 [ 1 ] . V_44 |= V_172 ;
V_173 [ 1 ] . V_59 = 1 ;
} else {
V_173 [ 0 ] . V_59 = V_109 -> V_205 [ 0 ] + 2 ;
if ( V_173 [ 0 ] . V_59 > V_207 + 2 ) {
F_23 ( & V_65 -> V_7 ,
L_84 ,
V_109 -> V_205 [ 0 ] ) ;
return - V_63 ;
}
for ( V_32 = 1 ; V_32 < V_173 [ 0 ] . V_59 ; V_32 ++ )
V_211 [ V_32 ] = V_109 -> V_205 [ V_32 - 1 ] ;
}
break;
case V_215 :
V_165 = 2 ;
V_209 = V_180 ;
if ( V_109 -> V_205 [ 0 ] > V_207 ) {
F_23 ( & V_65 -> V_7 ,
L_84 ,
V_109 -> V_205 [ 0 ] ) ;
return - V_63 ;
}
V_173 [ 0 ] . V_59 = V_109 -> V_205 [ 0 ] + 2 ;
for ( V_32 = 1 ; V_32 < V_173 [ 0 ] . V_59 ; V_32 ++ )
V_211 [ V_32 ] = V_109 -> V_205 [ V_32 - 1 ] ;
V_173 [ 1 ] . V_44 |= V_172 ;
V_173 [ 1 ] . V_59 = 1 ;
break;
case V_208 :
if ( V_209 == V_180 ) {
V_173 [ 1 ] . V_59 = V_109 -> V_205 [ 0 ] ;
} else {
V_173 [ 0 ] . V_59 = V_109 -> V_205 [ 0 ] + 1 ;
if ( V_173 [ 0 ] . V_59 > V_207 + 1 ) {
F_23 ( & V_65 -> V_7 ,
L_84 ,
V_109 -> V_205 [ 0 ] ) ;
return - V_63 ;
}
for ( V_32 = 1 ; V_32 <= V_109 -> V_205 [ 0 ] ; V_32 ++ )
V_211 [ V_32 ] = V_109 -> V_205 [ V_32 ] ;
}
break;
default:
F_23 ( & V_65 -> V_7 , L_85 , V_210 ) ;
return - V_40 ;
}
V_32 = ( ( V_44 & V_216 ) && V_210 != V_184
&& V_210 != V_208 ) ;
if ( V_32 ) {
if ( ! ( V_173 [ 0 ] . V_44 & V_171 ) ) {
if ( V_165 == 1 )
F_203 ( & V_173 [ 0 ] ) ;
else
V_213 = F_202 ( 0 , & V_173 [ 0 ] ) ;
}
if ( V_173 [ V_165 - 1 ] . V_44 & V_171 )
V_173 [ V_165 - 1 ] . V_59 ++ ;
}
V_42 = F_183 ( V_65 , V_173 , V_165 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_32 && ( V_173 [ V_165 - 1 ] . V_44 & V_171 ) ) {
V_42 = F_204 ( V_213 , & V_173 [ V_165 - 1 ] ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_209 == V_180 )
switch ( V_210 ) {
case V_186 :
V_109 -> V_199 = V_211 [ 0 ] ;
break;
case V_181 :
V_109 -> V_199 = V_212 [ 0 ] ;
break;
case V_201 :
case V_214 :
V_109 -> V_202 = V_212 [ 0 ] | ( V_212 [ 1 ] << 8 ) ;
break;
case V_208 :
for ( V_32 = 0 ; V_32 < V_109 -> V_205 [ 0 ] ; V_32 ++ )
V_109 -> V_205 [ V_32 + 1 ] = V_212 [ V_32 ] ;
break;
case V_204 :
case V_215 :
for ( V_32 = 0 ; V_32 < V_212 [ 0 ] + 1 ; V_32 ++ )
V_109 -> V_205 [ V_32 ] = V_212 [ V_32 ] ;
break;
}
return 0 ;
}
T_12 F_192 ( struct V_19 * V_65 , T_3 V_62 , unsigned short V_44 ,
char V_209 , T_11 V_156 , int V_217 ,
union V_176 * V_109 )
{
unsigned long V_166 ;
int V_167 ;
T_12 V_91 ;
V_44 &= V_174 | V_216 | V_218 ;
if ( V_65 -> V_138 -> V_219 ) {
F_63 ( V_65 ) ;
V_166 = V_168 ;
for ( V_91 = 0 , V_167 = 0 ; V_167 <= V_65 -> V_169 ; V_167 ++ ) {
V_91 = V_65 -> V_138 -> V_219 ( V_65 , V_62 , V_44 ,
V_209 , V_156 ,
V_217 , V_109 ) ;
if ( V_91 != - V_136 )
break;
if ( F_182 ( V_168 ,
V_166 + V_65 -> V_139 ) )
break;
}
F_67 ( V_65 ) ;
if ( V_91 != - V_40 || ! V_65 -> V_138 -> V_170 )
return V_91 ;
}
return F_215 ( V_65 , V_62 , V_44 , V_209 ,
V_156 , V_217 , V_109 ) ;
}
