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
static int F_97 ( struct V_10 * V_11 ,
struct V_17 * V_18 )
{
F_98 ( V_18 , V_11 ) ;
if ( V_11 -> V_99 ) {
F_18 ( & V_18 -> V_7 , L_30 ,
V_11 -> V_11 . V_5 ) ;
F_18 ( & V_18 -> V_7 , L_31
L_32 ) ;
V_11 -> V_99 ( V_18 ) ;
}
return 0 ;
}
static int F_99 ( struct V_8 * V_100 , void * V_101 )
{
return F_97 ( F_6 ( V_100 ) , V_101 ) ;
}
static int F_100 ( struct V_17 * V_18 )
{
int V_86 = 0 ;
if ( F_101 ( F_102 ( ! V_76 . V_102 ) ) ) {
V_86 = - V_103 ;
goto V_104;
}
if ( F_101 ( V_18 -> V_5 [ 0 ] == '\0' ) ) {
F_103 ( L_33
L_34 ) ;
return - V_60 ;
}
if ( F_101 ( ! V_18 -> V_105 ) ) {
F_103 ( L_35
L_36 , V_18 -> V_5 ) ;
return - V_60 ;
}
F_104 ( & V_18 -> V_66 ) ;
F_105 ( & V_18 -> V_88 ) ;
F_106 ( & V_18 -> V_90 ) ;
if ( V_18 -> V_106 == 0 )
V_18 -> V_106 = V_107 ;
F_70 ( & V_18 -> V_7 , L_37 , V_18 -> V_97 ) ;
V_18 -> V_7 . V_75 = & V_76 ;
V_18 -> V_7 . type = & V_65 ;
V_86 = F_72 ( & V_18 -> V_7 ) ;
if ( V_86 )
goto V_104;
F_10 ( & V_18 -> V_7 , L_38 , V_18 -> V_5 ) ;
#ifdef F_107
V_86 = F_108 ( V_108 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
if ( V_86 )
F_18 ( & V_18 -> V_7 ,
L_39 ) ;
#endif
if ( V_18 -> V_19 ) {
struct V_23 * V_24 = V_18 -> V_19 ;
if ( ! V_24 -> V_39 ) {
F_22 ( & V_18 -> V_7 , L_40 ) ;
V_18 -> V_19 = NULL ;
goto V_109;
}
if ( V_24 -> V_39 == F_25 ) {
if ( ! F_109 ( V_24 -> V_20 ) ) {
F_22 ( & V_18 -> V_7 , L_41 ) ;
V_18 -> V_19 = NULL ;
goto V_109;
}
if ( F_109 ( V_24 -> V_22 ) )
V_24 -> V_28 = F_15 ;
else
V_24 -> V_28 = NULL ;
V_24 -> V_33 = F_11 ;
V_24 -> V_35 = F_13 ;
} else if ( ! V_24 -> V_35 || ! V_24 -> V_33 ) {
F_22 ( & V_18 -> V_7 , L_42 ) ;
V_18 -> V_19 = NULL ;
}
}
V_109:
if ( V_18 -> V_97 < V_110 )
F_93 ( V_18 ) ;
F_84 ( & V_111 ) ;
F_110 ( & V_76 , NULL , V_18 , F_99 ) ;
F_86 ( & V_111 ) ;
return 0 ;
V_104:
F_84 ( & V_111 ) ;
F_111 ( & V_112 , V_18 -> V_97 ) ;
F_86 ( & V_111 ) ;
return V_86 ;
}
static int F_112 ( struct V_17 * V_18 )
{
int V_2 ;
F_84 ( & V_111 ) ;
V_2 = F_113 ( & V_112 , V_18 , V_18 -> V_97 , V_18 -> V_97 + 1 ,
V_69 ) ;
F_86 ( & V_111 ) ;
if ( V_2 < 0 )
return V_2 == - V_113 ? - V_34 : V_2 ;
return F_100 ( V_18 ) ;
}
int F_114 ( struct V_17 * V_62 )
{
struct V_6 * V_7 = & V_62 -> V_7 ;
int V_2 ;
if ( V_7 -> V_77 ) {
V_2 = F_115 ( V_7 -> V_77 , L_43 ) ;
if ( V_2 >= 0 ) {
V_62 -> V_97 = V_2 ;
return F_112 ( V_62 ) ;
}
}
F_84 ( & V_111 ) ;
V_2 = F_113 ( & V_112 , V_62 ,
V_110 , 0 , V_69 ) ;
F_86 ( & V_111 ) ;
if ( V_2 < 0 )
return V_2 ;
V_62 -> V_97 = V_2 ;
return F_100 ( V_62 ) ;
}
int F_116 ( struct V_17 * V_18 )
{
if ( V_18 -> V_97 == - 1 )
return F_114 ( V_18 ) ;
return F_112 ( V_18 ) ;
}
static void F_117 ( struct V_10 * V_11 ,
struct V_17 * V_62 )
{
struct V_3 * V_4 , * V_114 ;
F_90 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_62 == V_62 ) {
F_10 ( & V_62 -> V_7 , L_44 ,
V_4 -> V_5 , V_4 -> V_59 ) ;
F_91 ( & V_4 -> V_89 ) ;
F_74 ( V_4 ) ;
}
}
}
static int F_118 ( struct V_6 * V_7 , void * V_115 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_18 ) )
F_74 ( V_4 ) ;
return 0 ;
}
static int F_119 ( struct V_6 * V_7 , void * V_115 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_74 ( V_4 ) ;
return 0 ;
}
static int F_120 ( struct V_8 * V_100 , void * V_101 )
{
F_117 ( F_6 ( V_100 ) , V_101 ) ;
return 0 ;
}
void F_121 ( struct V_17 * V_18 )
{
struct V_17 * V_116 ;
struct V_3 * V_4 , * V_91 ;
F_84 ( & V_111 ) ;
V_116 = F_122 ( & V_112 , V_18 -> V_97 ) ;
F_86 ( & V_111 ) ;
if ( V_116 != V_18 ) {
F_123 ( L_45
L_46 , V_18 -> V_5 ) ;
return;
}
F_84 ( & V_111 ) ;
F_110 ( & V_76 , NULL , V_18 ,
F_120 ) ;
F_86 ( & V_111 ) ;
F_89 ( & V_18 -> V_88 ,
F_82 ( V_18 ) ) ;
F_90 (client, next, &adap->userspace_clients,
detected) {
F_10 ( & V_18 -> V_7 , L_44 , V_4 -> V_5 ,
V_4 -> V_59 ) ;
F_91 ( & V_4 -> V_89 ) ;
F_74 ( V_4 ) ;
}
F_86 ( & V_18 -> V_88 ) ;
F_57 ( & V_18 -> V_7 , NULL , F_118 ) ;
F_57 ( & V_18 -> V_7 , NULL , F_119 ) ;
#ifdef F_107
F_124 ( V_108 , & V_18 -> V_7 ,
V_18 -> V_7 . V_63 ) ;
#endif
F_10 ( & V_18 -> V_7 , L_47 , V_18 -> V_5 ) ;
F_125 ( & V_18 -> V_81 ) ;
F_75 ( & V_18 -> V_7 ) ;
F_126 ( & V_18 -> V_81 ) ;
F_84 ( & V_111 ) ;
F_111 ( & V_112 , V_18 -> V_97 ) ;
F_86 ( & V_111 ) ;
memset ( & V_18 -> V_7 , 0 , sizeof( V_18 -> V_7 ) ) ;
}
int F_127 ( void * V_101 , int (* F_128)( struct V_6 * , void * ) )
{
int V_86 ;
F_84 ( & V_111 ) ;
V_86 = F_129 ( & V_76 , NULL , V_101 , F_128 ) ;
F_86 ( & V_111 ) ;
return V_86 ;
}
static int F_130 ( struct V_6 * V_7 , void * V_101 )
{
if ( V_7 -> type != & V_65 )
return 0 ;
return F_97 ( V_101 , F_50 ( V_7 ) ) ;
}
int F_131 ( struct V_117 * V_118 , struct V_10 * V_11 )
{
int V_86 ;
if ( F_101 ( F_102 ( ! V_76 . V_102 ) ) )
return - V_103 ;
V_11 -> V_11 . V_118 = V_118 ;
V_11 -> V_11 . V_75 = & V_76 ;
V_86 = F_132 ( & V_11 -> V_11 ) ;
if ( V_86 )
return V_86 ;
if ( V_11 -> V_47 )
F_133 ( L_48 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_48 )
F_133 ( L_49 ,
V_11 -> V_11 . V_5 ) ;
F_123 ( L_50 , V_11 -> V_11 . V_5 ) ;
F_106 ( & V_11 -> V_119 ) ;
F_127 ( V_11 , F_130 ) ;
return 0 ;
}
static int F_134 ( struct V_6 * V_7 , void * V_101 )
{
if ( V_7 -> type == & V_65 )
F_117 ( V_101 , F_50 ( V_7 ) ) ;
return 0 ;
}
void F_135 ( struct V_10 * V_11 )
{
F_127 ( V_11 , F_134 ) ;
F_136 ( & V_11 -> V_11 ) ;
F_123 ( L_51 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_137 ( struct V_3 * V_4 )
{
if ( V_4 && F_138 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_139 ( struct V_3 * V_4 )
{
if ( V_4 )
F_140 ( & V_4 -> V_7 ) ;
}
static int F_141 ( struct V_6 * V_7 , void * V_120 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_121 * V_122 = V_120 ;
if ( V_4 && V_4 -> V_11 && V_4 -> V_11 -> V_123 )
V_4 -> V_11 -> V_123 ( V_4 , V_122 -> V_124 , V_122 -> V_122 ) ;
return 0 ;
}
void F_142 ( struct V_17 * V_18 , unsigned int V_124 , void * V_122 )
{
struct V_121 V_125 ;
V_125 . V_124 = V_124 ;
V_125 . V_122 = V_122 ;
F_57 ( & V_18 -> V_7 , & V_125 , F_141 ) ;
}
static int T_5 F_143 ( void )
{
int V_126 ;
V_126 = F_144 ( & V_76 ) ;
if ( V_126 )
return V_126 ;
#ifdef F_107
V_108 = F_145 ( L_52 ) ;
if ( ! V_108 ) {
V_126 = - V_16 ;
goto V_127;
}
#endif
V_126 = F_146 ( & V_128 ) ;
if ( V_126 )
goto V_129;
return 0 ;
V_129:
#ifdef F_107
F_147 ( V_108 ) ;
V_127:
#endif
F_148 ( & V_76 ) ;
return V_126 ;
}
static void T_6 F_149 ( void )
{
F_135 ( & V_128 ) ;
#ifdef F_107
F_147 ( V_108 ) ;
#endif
F_148 ( & V_76 ) ;
}
int F_150 ( struct V_17 * V_18 , struct V_130 * V_131 , int V_132 )
{
unsigned long V_133 ;
int V_25 , V_134 ;
V_133 = V_135 ;
for ( V_25 = 0 , V_134 = 0 ; V_134 <= V_18 -> V_136 ; V_134 ++ ) {
V_25 = V_18 -> V_105 -> V_137 ( V_18 , V_131 , V_132 ) ;
if ( V_25 != - V_103 )
break;
if ( F_151 ( V_135 , V_133 + V_18 -> V_106 ) )
break;
}
return V_25 ;
}
int F_152 ( struct V_17 * V_18 , struct V_130 * V_131 , int V_132 )
{
int V_25 ;
if ( V_18 -> V_105 -> V_137 ) {
#ifdef F_153
for ( V_25 = 0 ; V_25 < V_132 ; V_25 ++ ) {
F_10 ( & V_18 -> V_7 , L_53
L_54 , V_25 , ( V_131 [ V_25 ] . V_43 & V_138 )
? 'R' : 'W' , V_131 [ V_25 ] . V_59 , V_131 [ V_25 ] . V_139 ,
( V_131 [ V_25 ] . V_43 & V_140 ) ? L_55 : L_56 ) ;
}
#endif
if ( F_154 () || F_155 () ) {
V_25 = F_62 ( V_18 ) ;
if ( ! V_25 )
return - V_103 ;
} else {
F_60 ( V_18 ) ;
}
V_25 = F_150 ( V_18 , V_131 , V_132 ) ;
F_64 ( V_18 ) ;
return V_25 ;
} else {
F_10 ( & V_18 -> V_7 , L_57 ) ;
return - V_38 ;
}
}
int F_156 ( const struct V_3 * V_4 , const char * V_56 , int V_83 )
{
int V_25 ;
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_130 V_141 ;
V_141 . V_59 = V_4 -> V_59 ;
V_141 . V_43 = V_4 -> V_43 & V_142 ;
V_141 . V_139 = V_83 ;
V_141 . V_56 = ( char * ) V_56 ;
V_25 = F_152 ( V_18 , & V_141 , 1 ) ;
return ( V_25 == 1 ) ? V_83 : V_25 ;
}
int F_157 ( const struct V_3 * V_4 , char * V_56 , int V_83 )
{
struct V_17 * V_18 = V_4 -> V_62 ;
struct V_130 V_141 ;
int V_25 ;
V_141 . V_59 = V_4 -> V_59 ;
V_141 . V_43 = V_4 -> V_43 & V_142 ;
V_141 . V_43 |= V_138 ;
V_141 . V_139 = V_83 ;
V_141 . V_56 = V_56 ;
V_25 = F_152 ( V_18 , & V_141 , 1 ) ;
return ( V_25 == 1 ) ? V_83 : V_25 ;
}
static int F_158 ( struct V_17 * V_18 , unsigned short V_59 )
{
int V_143 ;
union V_144 V_115 ;
#ifdef F_159
if ( V_59 == 0x73 && ( V_18 -> V_145 & V_146 )
&& F_160 ( V_18 , V_147 ) )
V_143 = F_161 ( V_18 , V_59 , 0 , V_148 , 0 ,
V_149 , & V_115 ) ;
else
#endif
if ( ! ( ( V_59 & ~ 0x07 ) == 0x30 || ( V_59 & ~ 0x0f ) == 0x50 )
&& F_160 ( V_18 , V_150 ) )
V_143 = F_161 ( V_18 , V_59 , 0 , V_151 , 0 ,
V_152 , NULL ) ;
else if ( F_160 ( V_18 , V_153 ) )
V_143 = F_161 ( V_18 , V_59 , 0 , V_148 , 0 ,
V_154 , & V_115 ) ;
else {
F_18 ( & V_18 -> V_7 , L_58 ) ;
V_143 = - V_38 ;
}
return V_143 >= 0 ;
}
static int F_162 ( struct V_3 * V_155 ,
struct V_10 * V_11 )
{
struct V_67 V_68 ;
struct V_17 * V_62 = V_155 -> V_62 ;
int V_59 = V_155 -> V_59 ;
int V_143 ;
V_143 = F_53 ( V_59 ) ;
if ( V_143 ) {
F_18 ( & V_62 -> V_7 , L_59 ,
V_59 ) ;
return V_143 ;
}
if ( F_59 ( V_62 , V_59 ) )
return 0 ;
if ( ! F_158 ( V_62 , V_59 ) )
return 0 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_59 = V_59 ;
V_143 = V_11 -> V_156 ( V_155 , & V_68 ) ;
if ( V_143 ) {
return V_143 == - V_42 ? 0 : V_143 ;
}
if ( V_68 . type [ 0 ] == '\0' ) {
F_22 ( & V_62 -> V_7 , L_60
L_61 , V_11 -> V_11 . V_5 ,
V_59 ) ;
} else {
struct V_3 * V_4 ;
F_10 ( & V_62 -> V_7 , L_62 ,
V_68 . type , V_68 . V_59 ) ;
V_4 = F_66 ( V_62 , & V_68 ) ;
if ( V_4 )
F_85 ( & V_4 -> V_89 , & V_11 -> V_119 ) ;
else
F_22 ( & V_62 -> V_7 , L_63 ,
V_68 . type , V_68 . V_59 ) ;
}
return 0 ;
}
static int F_98 ( struct V_17 * V_62 , struct V_10 * V_11 )
{
const unsigned short * V_157 ;
struct V_3 * V_155 ;
int V_30 , V_143 = 0 ;
int V_158 = F_71 ( V_62 ) ;
V_157 = V_11 -> V_157 ;
if ( ! V_11 -> V_156 || ! V_157 )
return 0 ;
if ( ! ( V_62 -> V_145 & V_11 -> V_145 ) )
return 0 ;
V_155 = F_67 ( sizeof( struct V_3 ) , V_69 ) ;
if ( ! V_155 )
return - V_16 ;
V_155 -> V_62 = V_62 ;
for ( V_30 = 0 ; V_157 [ V_30 ] != V_159 ; V_30 += 1 ) {
F_10 ( & V_62 -> V_7 , L_64
L_65 , V_158 , V_157 [ V_30 ] ) ;
V_155 -> V_59 = V_157 [ V_30 ] ;
V_143 = F_162 ( V_155 , V_11 ) ;
if ( F_101 ( V_143 ) )
break;
}
F_48 ( V_155 ) ;
return V_143 ;
}
int F_163 ( struct V_17 * V_18 , unsigned short V_59 )
{
return F_161 ( V_18 , V_59 , 0 , V_148 , 0 ,
V_152 , NULL ) >= 0 ;
}
struct V_3 *
F_164 ( struct V_17 * V_18 ,
struct V_67 * V_68 ,
unsigned short const * V_160 ,
int (* V_41)( struct V_17 * , unsigned short V_59 ) )
{
int V_30 ;
if ( ! V_41 )
V_41 = F_158 ;
for ( V_30 = 0 ; V_160 [ V_30 ] != V_159 ; V_30 ++ ) {
if ( F_53 ( V_160 [ V_30 ] ) < 0 ) {
F_18 ( & V_18 -> V_7 , L_66
L_67 , V_160 [ V_30 ] ) ;
continue;
}
if ( F_59 ( V_18 , V_160 [ V_30 ] ) ) {
F_10 ( & V_18 -> V_7 , L_68
L_69 , V_160 [ V_30 ] ) ;
continue;
}
if ( V_41 ( V_18 , V_160 [ V_30 ] ) )
break;
}
if ( V_160 [ V_30 ] == V_159 ) {
F_10 ( & V_18 -> V_7 , L_70 ) ;
return NULL ;
}
V_68 -> V_59 = V_160 [ V_30 ] ;
return F_66 ( V_18 , V_68 ) ;
}
struct V_17 * F_165 ( int V_97 )
{
struct V_17 * V_62 ;
F_84 ( & V_111 ) ;
V_62 = F_122 ( & V_112 , V_97 ) ;
if ( V_62 && ! F_166 ( V_62 -> V_118 ) )
V_62 = NULL ;
F_86 ( & V_111 ) ;
return V_62 ;
}
void F_167 ( struct V_17 * V_18 )
{
F_168 ( V_18 -> V_118 ) ;
}
static T_7 F_169 ( T_3 V_101 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( V_101 & 0x8000 )
V_101 = V_101 ^ V_161 ;
V_101 = V_101 << 1 ;
}
return ( T_7 ) ( V_101 >> 8 ) ;
}
static T_7 F_170 ( T_7 V_162 , T_7 * V_102 , T_4 V_83 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_83 ; V_30 ++ )
V_162 = F_169 ( ( V_162 ^ V_102 [ V_30 ] ) << 8 ) ;
return V_162 ;
}
static T_7 F_171 ( T_7 V_163 , struct V_130 * V_141 )
{
T_7 V_59 = ( V_141 -> V_59 << 1 ) | ! ! ( V_141 -> V_43 & V_138 ) ;
V_163 = F_170 ( V_163 , & V_59 , 1 ) ;
return F_170 ( V_163 , V_141 -> V_56 , V_141 -> V_139 ) ;
}
static inline void F_172 ( struct V_130 * V_141 )
{
V_141 -> V_56 [ V_141 -> V_139 ] = F_171 ( 0 , V_141 ) ;
V_141 -> V_139 ++ ;
}
static int F_173 ( T_7 V_164 , struct V_130 * V_141 )
{
T_7 V_165 = V_141 -> V_56 [ -- V_141 -> V_139 ] ;
V_164 = F_171 ( V_164 , V_141 ) ;
if ( V_165 != V_164 ) {
F_123 ( L_71 ,
V_165 , V_164 ) ;
return - V_166 ;
}
return 0 ;
}
T_8 F_174 ( const struct V_3 * V_4 )
{
union V_144 V_101 ;
int V_40 ;
V_40 = F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_148 , 0 ,
V_154 , & V_101 ) ;
return ( V_40 < 0 ) ? V_40 : V_101 . V_167 ;
}
T_8 F_175 ( const struct V_3 * V_4 , T_7 V_168 )
{
return F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_151 , V_168 , V_154 , NULL ) ;
}
T_8 F_176 ( const struct V_3 * V_4 , T_7 V_123 )
{
union V_144 V_101 ;
int V_40 ;
V_40 = F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_148 , V_123 ,
V_149 , & V_101 ) ;
return ( V_40 < 0 ) ? V_40 : V_101 . V_167 ;
}
T_8 F_177 ( const struct V_3 * V_4 , T_7 V_123 ,
T_7 V_168 )
{
union V_144 V_101 ;
V_101 . V_167 = V_168 ;
return F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_151 , V_123 ,
V_149 , & V_101 ) ;
}
T_8 F_178 ( const struct V_3 * V_4 , T_7 V_123 )
{
union V_144 V_101 ;
int V_40 ;
V_40 = F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_148 , V_123 ,
V_169 , & V_101 ) ;
return ( V_40 < 0 ) ? V_40 : V_101 . V_170 ;
}
T_8 F_179 ( const struct V_3 * V_4 , T_7 V_123 ,
T_3 V_168 )
{
union V_144 V_101 ;
V_101 . V_170 = V_168 ;
return F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_151 , V_123 ,
V_169 , & V_101 ) ;
}
T_8 F_180 ( const struct V_3 * V_4 , T_7 V_123 ,
T_7 * V_171 )
{
union V_144 V_101 ;
int V_40 ;
V_40 = F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_148 , V_123 ,
V_172 , & V_101 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_171 , & V_101 . V_173 [ 1 ] , V_101 . V_173 [ 0 ] ) ;
return V_101 . V_173 [ 0 ] ;
}
T_8 F_181 ( const struct V_3 * V_4 , T_7 V_123 ,
T_7 V_174 , const T_7 * V_171 )
{
union V_144 V_101 ;
if ( V_174 > V_175 )
V_174 = V_175 ;
V_101 . V_173 [ 0 ] = V_174 ;
memcpy ( & V_101 . V_173 [ 1 ] , V_171 , V_174 ) ;
return F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_151 , V_123 ,
V_172 , & V_101 ) ;
}
T_8 F_182 ( const struct V_3 * V_4 , T_7 V_123 ,
T_7 V_174 , T_7 * V_171 )
{
union V_144 V_101 ;
int V_40 ;
if ( V_174 > V_175 )
V_174 = V_175 ;
V_101 . V_173 [ 0 ] = V_174 ;
V_40 = F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_148 , V_123 ,
V_176 , & V_101 ) ;
if ( V_40 < 0 )
return V_40 ;
memcpy ( V_171 , & V_101 . V_173 [ 1 ] , V_101 . V_173 [ 0 ] ) ;
return V_101 . V_173 [ 0 ] ;
}
T_8 F_183 ( const struct V_3 * V_4 , T_7 V_123 ,
T_7 V_174 , const T_7 * V_171 )
{
union V_144 V_101 ;
if ( V_174 > V_175 )
V_174 = V_175 ;
V_101 . V_173 [ 0 ] = V_174 ;
memcpy ( V_101 . V_173 + 1 , V_171 , V_174 ) ;
return F_161 ( V_4 -> V_62 , V_4 -> V_59 , V_4 -> V_43 ,
V_151 , V_123 ,
V_176 , & V_101 ) ;
}
static T_8 F_184 ( struct V_17 * V_62 , T_3 V_59 ,
unsigned short V_43 ,
char V_177 , T_7 V_123 , int V_178 ,
union V_144 * V_101 )
{
unsigned char V_179 [ V_175 + 3 ] ;
unsigned char V_180 [ V_175 + 2 ] ;
int V_132 = V_177 == V_148 ? 2 : 1 ;
int V_30 ;
T_7 V_181 = 0 ;
int V_40 ;
struct V_130 V_141 [ 2 ] = {
{
. V_59 = V_59 ,
. V_43 = V_43 ,
. V_139 = 1 ,
. V_56 = V_179 ,
} , {
. V_59 = V_59 ,
. V_43 = V_43 | V_138 ,
. V_139 = 0 ,
. V_56 = V_180 ,
} ,
} ;
V_179 [ 0 ] = V_123 ;
switch ( V_178 ) {
case V_152 :
V_141 [ 0 ] . V_139 = 0 ;
V_141 [ 0 ] . V_43 = V_43 | ( V_177 == V_148 ?
V_138 : 0 ) ;
V_132 = 1 ;
break;
case V_154 :
if ( V_177 == V_148 ) {
V_141 [ 0 ] . V_43 = V_138 | V_43 ;
V_132 = 1 ;
}
break;
case V_149 :
if ( V_177 == V_148 )
V_141 [ 1 ] . V_139 = 1 ;
else {
V_141 [ 0 ] . V_139 = 2 ;
V_179 [ 1 ] = V_101 -> V_167 ;
}
break;
case V_169 :
if ( V_177 == V_148 )
V_141 [ 1 ] . V_139 = 2 ;
else {
V_141 [ 0 ] . V_139 = 3 ;
V_179 [ 1 ] = V_101 -> V_170 & 0xff ;
V_179 [ 2 ] = V_101 -> V_170 >> 8 ;
}
break;
case V_182 :
V_132 = 2 ;
V_177 = V_148 ;
V_141 [ 0 ] . V_139 = 3 ;
V_141 [ 1 ] . V_139 = 2 ;
V_179 [ 1 ] = V_101 -> V_170 & 0xff ;
V_179 [ 2 ] = V_101 -> V_170 >> 8 ;
break;
case V_172 :
if ( V_177 == V_148 ) {
V_141 [ 1 ] . V_43 |= V_140 ;
V_141 [ 1 ] . V_139 = 1 ;
} else {
V_141 [ 0 ] . V_139 = V_101 -> V_173 [ 0 ] + 2 ;
if ( V_141 [ 0 ] . V_139 > V_175 + 2 ) {
F_22 ( & V_62 -> V_7 ,
L_72 ,
V_101 -> V_173 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 < V_141 [ 0 ] . V_139 ; V_30 ++ )
V_179 [ V_30 ] = V_101 -> V_173 [ V_30 - 1 ] ;
}
break;
case V_183 :
V_132 = 2 ;
V_177 = V_148 ;
if ( V_101 -> V_173 [ 0 ] > V_175 ) {
F_22 ( & V_62 -> V_7 ,
L_72 ,
V_101 -> V_173 [ 0 ] ) ;
return - V_60 ;
}
V_141 [ 0 ] . V_139 = V_101 -> V_173 [ 0 ] + 2 ;
for ( V_30 = 1 ; V_30 < V_141 [ 0 ] . V_139 ; V_30 ++ )
V_179 [ V_30 ] = V_101 -> V_173 [ V_30 - 1 ] ;
V_141 [ 1 ] . V_43 |= V_140 ;
V_141 [ 1 ] . V_139 = 1 ;
break;
case V_176 :
if ( V_177 == V_148 ) {
V_141 [ 1 ] . V_139 = V_101 -> V_173 [ 0 ] ;
} else {
V_141 [ 0 ] . V_139 = V_101 -> V_173 [ 0 ] + 1 ;
if ( V_141 [ 0 ] . V_139 > V_175 + 1 ) {
F_22 ( & V_62 -> V_7 ,
L_72 ,
V_101 -> V_173 [ 0 ] ) ;
return - V_60 ;
}
for ( V_30 = 1 ; V_30 <= V_101 -> V_173 [ 0 ] ; V_30 ++ )
V_179 [ V_30 ] = V_101 -> V_173 [ V_30 ] ;
}
break;
default:
F_22 ( & V_62 -> V_7 , L_73 , V_178 ) ;
return - V_38 ;
}
V_30 = ( ( V_43 & V_184 ) && V_178 != V_152
&& V_178 != V_176 ) ;
if ( V_30 ) {
if ( ! ( V_141 [ 0 ] . V_43 & V_138 ) ) {
if ( V_132 == 1 )
F_172 ( & V_141 [ 0 ] ) ;
else
V_181 = F_171 ( 0 , & V_141 [ 0 ] ) ;
}
if ( V_141 [ V_132 - 1 ] . V_43 & V_138 )
V_141 [ V_132 - 1 ] . V_139 ++ ;
}
V_40 = F_152 ( V_62 , V_141 , V_132 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_30 && ( V_141 [ V_132 - 1 ] . V_43 & V_138 ) ) {
V_40 = F_173 ( V_181 , & V_141 [ V_132 - 1 ] ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_177 == V_148 )
switch ( V_178 ) {
case V_154 :
V_101 -> V_167 = V_179 [ 0 ] ;
break;
case V_149 :
V_101 -> V_167 = V_180 [ 0 ] ;
break;
case V_169 :
case V_182 :
V_101 -> V_170 = V_180 [ 0 ] | ( V_180 [ 1 ] << 8 ) ;
break;
case V_176 :
for ( V_30 = 0 ; V_30 < V_101 -> V_173 [ 0 ] ; V_30 ++ )
V_101 -> V_173 [ V_30 + 1 ] = V_180 [ V_30 ] ;
break;
case V_172 :
case V_183 :
for ( V_30 = 0 ; V_30 < V_180 [ 0 ] + 1 ; V_30 ++ )
V_101 -> V_173 [ V_30 ] = V_180 [ V_30 ] ;
break;
}
return 0 ;
}
T_8 F_161 ( struct V_17 * V_62 , T_3 V_59 , unsigned short V_43 ,
char V_177 , T_7 V_123 , int V_185 ,
union V_144 * V_101 )
{
unsigned long V_133 ;
int V_134 ;
T_8 V_86 ;
V_43 &= V_142 | V_184 | V_186 ;
if ( V_62 -> V_105 -> V_187 ) {
F_60 ( V_62 ) ;
V_133 = V_135 ;
for ( V_86 = 0 , V_134 = 0 ; V_134 <= V_62 -> V_136 ; V_134 ++ ) {
V_86 = V_62 -> V_105 -> V_187 ( V_62 , V_59 , V_43 ,
V_177 , V_123 ,
V_185 , V_101 ) ;
if ( V_86 != - V_103 )
break;
if ( F_151 ( V_135 ,
V_133 + V_62 -> V_106 ) )
break;
}
F_64 ( V_62 ) ;
if ( V_86 != - V_38 || ! V_62 -> V_105 -> V_137 )
return V_86 ;
}
return F_184 ( V_62 , V_59 , V_43 , V_177 ,
V_123 , V_185 , V_101 ) ;
}
