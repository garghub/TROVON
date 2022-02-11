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
static int F_11 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_17 ;
if ( ! V_4 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_18 || ! V_11 -> V_12 )
return - V_19 ;
V_4 -> V_11 = V_11 ;
if ( ! F_12 ( & V_4 -> V_7 ) )
F_13 ( & V_4 -> V_7 ,
V_4 -> V_20 & V_21 ) ;
F_10 ( V_7 , L_3 ) ;
V_17 = V_11 -> V_18 ( V_4 , F_1 ( V_11 -> V_12 , V_4 ) ) ;
if ( V_17 ) {
V_4 -> V_11 = NULL ;
F_14 ( V_4 , NULL ) ;
}
return V_17 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_17 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> remove ) {
F_10 ( V_7 , L_4 ) ;
V_17 = V_11 -> remove ( V_4 ) ;
} else {
V_7 -> V_11 = NULL ;
V_17 = 0 ;
}
if ( V_17 == 0 ) {
V_4 -> V_11 = NULL ;
F_14 ( V_4 , NULL ) ;
}
return V_17 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( V_11 -> V_22 )
V_11 -> V_22 ( V_4 ) ;
}
static int F_17 ( struct V_6 * V_7 , T_1 V_23 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_24 )
return 0 ;
return V_11 -> V_24 ( V_4 , V_23 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_6 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_25 )
return 0 ;
return V_11 -> V_25 ( V_4 ) ;
}
static int F_19 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_20 ( V_7 ) ;
else
return F_17 ( V_7 , V_28 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_22 ( V_7 ) ;
else
return F_18 ( V_7 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_24 ( V_7 ) ;
else
return F_17 ( V_7 , V_29 ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_26 ( V_7 ) ;
else
return F_18 ( V_7 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_28 ( V_7 ) ;
else
return F_17 ( V_7 , V_30 ) ;
}
static int F_29 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_30 ( V_7 ) ;
else
return F_18 ( V_7 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
F_32 ( F_8 ( V_7 ) ) ;
}
static T_2
F_33 ( struct V_6 * V_7 , struct V_31 * V_32 , char * V_33 )
{
return sprintf ( V_33 , L_5 , V_7 -> type == & V_34 ?
F_8 ( V_7 ) -> V_5 : F_34 ( V_7 ) -> V_5 ) ;
}
static T_2
F_35 ( struct V_6 * V_7 , struct V_31 * V_32 , char * V_33 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_33 , L_6 , V_15 , V_4 -> V_5 ) ;
}
struct V_3 * F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_34 )
? F_8 ( V_7 )
: NULL ;
}
static int F_36 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_20 & V_35 ) {
if ( V_4 -> V_36 > 0x3ff )
return - V_37 ;
} else {
if ( V_4 -> V_36 == 0x00 || V_4 -> V_36 > 0x7f )
return - V_37 ;
}
return 0 ;
}
static int F_37 ( unsigned short V_36 )
{
if ( V_36 < 0x08 || V_36 > 0x77 )
return - V_37 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , void * V_38 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
int V_36 = * ( int * ) V_38 ;
if ( V_4 && V_4 -> V_36 == V_36 )
return - V_39 ;
return 0 ;
}
static int F_39 ( struct V_40 * V_41 , int V_36 )
{
struct V_40 * V_42 = F_40 ( V_41 ) ;
int V_43 ;
V_43 = F_41 ( & V_41 -> V_7 , & V_36 ,
F_38 ) ;
if ( ! V_43 && V_42 )
V_43 = F_39 ( V_42 , V_36 ) ;
return V_43 ;
}
static int F_42 ( struct V_6 * V_7 , void * V_38 )
{
int V_43 ;
if ( V_7 -> type == & V_44 )
V_43 = F_41 ( V_7 , V_38 ,
F_42 ) ;
else
V_43 = F_38 ( V_7 , V_38 ) ;
return V_43 ;
}
static int F_43 ( struct V_40 * V_41 , int V_36 )
{
struct V_40 * V_42 = F_40 ( V_41 ) ;
int V_43 = 0 ;
if ( V_42 )
V_43 = F_39 ( V_42 , V_36 ) ;
if ( ! V_43 )
V_43 = F_41 ( & V_41 -> V_7 , & V_36 ,
F_42 ) ;
return V_43 ;
}
void F_44 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_40 ( V_41 ) ;
if ( V_42 )
F_44 ( V_42 ) ;
else
F_45 ( & V_41 -> V_45 ) ;
}
static int F_46 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_40 ( V_41 ) ;
if ( V_42 )
return F_46 ( V_42 ) ;
else
return F_47 ( & V_41 -> V_45 ) ;
}
void F_48 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_40 ( V_41 ) ;
if ( V_42 )
F_48 ( V_42 ) ;
else
F_49 ( & V_41 -> V_45 ) ;
}
struct V_3 *
F_50 ( struct V_40 * V_46 , struct V_47 const * V_48 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_51 ( sizeof *V_4 , V_49 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_41 = V_46 ;
V_4 -> V_7 . V_50 = V_48 -> V_50 ;
if ( V_48 -> V_51 )
V_4 -> V_7 . V_51 = * V_48 -> V_51 ;
V_4 -> V_20 = V_48 -> V_20 ;
V_4 -> V_36 = V_48 -> V_36 ;
V_4 -> V_52 = V_48 -> V_52 ;
F_52 ( V_4 -> V_5 , V_48 -> type , sizeof( V_4 -> V_5 ) ) ;
V_17 = F_36 ( V_4 ) ;
if ( V_17 ) {
F_53 ( & V_46 -> V_7 , L_7 ,
V_4 -> V_20 & V_35 ? 10 : 7 , V_4 -> V_36 ) ;
goto V_53;
}
V_17 = F_43 ( V_46 , V_4 -> V_36 ) ;
if ( V_17 )
goto V_54;
V_4 -> V_7 . V_42 = & V_4 -> V_41 -> V_7 ;
V_4 -> V_7 . V_55 = & V_56 ;
V_4 -> V_7 . type = & V_34 ;
V_4 -> V_7 . V_57 = V_48 -> V_57 ;
F_54 ( & V_4 -> V_7 , V_48 -> V_58 . V_59 ) ;
F_55 ( & V_4 -> V_7 , L_8 , F_56 ( V_46 ) ,
V_4 -> V_36 | ( ( V_4 -> V_20 & V_35 )
? 0xa000 : 0 ) ) ;
V_17 = F_57 ( & V_4 -> V_7 ) ;
if ( V_17 )
goto V_54;
F_10 ( & V_46 -> V_7 , L_9 ,
V_4 -> V_5 , F_58 ( & V_4 -> V_7 ) ) ;
return V_4 ;
V_54:
F_53 ( & V_46 -> V_7 , L_10
L_11 , V_4 -> V_5 , V_4 -> V_36 , V_17 ) ;
V_53:
F_32 ( V_4 ) ;
return NULL ;
}
void F_59 ( struct V_3 * V_4 )
{
F_60 ( & V_4 -> V_7 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
const struct V_1 * V_2 )
{
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
return 0 ;
}
struct V_3 * F_63 ( struct V_40 * V_41 , T_3 V_60 )
{
struct V_47 V_48 = {
F_64 ( L_12 , V_60 ) ,
} ;
return F_50 ( V_41 , & V_48 ) ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_40 * V_46 = F_34 ( V_7 ) ;
F_66 ( & V_46 -> V_61 ) ;
}
static inline unsigned int F_67 ( struct V_40 * V_41 )
{
unsigned int V_62 = 0 ;
while ( ( V_41 = F_40 ( V_41 ) ) )
V_62 ++ ;
return V_62 ;
}
static T_2
F_68 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_63 )
{
struct V_40 * V_46 = F_34 ( V_7 ) ;
struct V_47 V_48 ;
struct V_3 * V_4 ;
char * V_64 , V_65 ;
int V_66 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_64 = strchr ( V_33 , ' ' ) ;
if ( ! V_64 ) {
F_53 ( V_7 , L_13 , L_14 ) ;
return - V_37 ;
}
if ( V_64 - V_33 > V_67 - 1 ) {
F_53 ( V_7 , L_15 , L_14 ) ;
return - V_37 ;
}
memcpy ( V_48 . type , V_33 , V_64 - V_33 ) ;
V_66 = sscanf ( ++ V_64 , L_16 , & V_48 . V_36 , & V_65 ) ;
if ( V_66 < 1 ) {
F_53 ( V_7 , L_17 , L_14 ) ;
return - V_37 ;
}
if ( V_66 > 1 && V_65 != '\n' ) {
F_53 ( V_7 , L_18 , L_14 ) ;
return - V_37 ;
}
V_4 = F_50 ( V_46 , & V_48 ) ;
if ( ! V_4 )
return - V_37 ;
F_69 ( & V_46 -> V_68 ) ;
F_70 ( & V_4 -> V_69 , & V_46 -> V_70 ) ;
F_71 ( & V_46 -> V_68 ) ;
F_72 ( V_7 , L_19 , L_14 ,
V_48 . type , V_48 . V_36 ) ;
return V_63 ;
}
static T_2
F_73 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_63 )
{
struct V_40 * V_46 = F_34 ( V_7 ) ;
struct V_3 * V_4 , * V_71 ;
unsigned short V_36 ;
char V_65 ;
int V_66 ;
V_66 = sscanf ( V_33 , L_16 , & V_36 , & V_65 ) ;
if ( V_66 < 1 ) {
F_53 ( V_7 , L_17 , L_20 ) ;
return - V_37 ;
}
if ( V_66 > 1 && V_65 != '\n' ) {
F_53 ( V_7 , L_18 , L_20 ) ;
return - V_37 ;
}
V_66 = - V_72 ;
F_74 ( & V_46 -> V_68 ,
F_67 ( V_46 ) ) ;
F_75 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_36 == V_36 ) {
F_72 ( V_7 , L_21 ,
L_20 , V_4 -> V_5 , V_4 -> V_36 ) ;
F_76 ( & V_4 -> V_69 ) ;
F_59 ( V_4 ) ;
V_66 = V_63 ;
break;
}
}
F_71 ( & V_46 -> V_68 ) ;
if ( V_66 < 0 )
F_53 ( V_7 , L_22 ,
L_20 ) ;
return V_66 ;
}
struct V_40 * F_77 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_44 )
? F_34 ( V_7 )
: NULL ;
}
static void F_78 ( struct V_40 * V_41 )
{
struct V_73 * V_74 ;
F_79 ( & V_75 ) ;
F_80 (devinfo, &__i2c_board_list, list) {
if ( V_74 -> V_76 == V_41 -> V_77
&& ! F_50 ( V_41 ,
& V_74 -> V_78 ) )
F_53 ( & V_41 -> V_7 ,
L_23 ,
V_74 -> V_78 . V_36 ) ;
}
F_81 ( & V_75 ) ;
}
static int F_82 ( struct V_10 * V_11 ,
struct V_40 * V_46 )
{
F_83 ( V_46 , V_11 ) ;
if ( V_11 -> V_79 ) {
F_84 ( & V_46 -> V_7 , L_24 ,
V_11 -> V_11 . V_5 ) ;
F_84 ( & V_46 -> V_7 , L_25
L_26 ) ;
V_11 -> V_79 ( V_46 ) ;
}
return 0 ;
}
static int F_85 ( struct V_8 * V_80 , void * V_81 )
{
return F_82 ( F_6 ( V_80 ) , V_81 ) ;
}
static int F_86 ( struct V_40 * V_46 )
{
int V_66 = 0 ;
if ( F_87 ( F_88 ( ! V_56 . V_82 ) ) ) {
V_66 = - V_83 ;
goto V_84;
}
if ( F_87 ( V_46 -> V_5 [ 0 ] == '\0' ) ) {
F_89 ( L_27
L_28 ) ;
return - V_37 ;
}
if ( F_87 ( ! V_46 -> V_85 ) ) {
F_89 ( L_29
L_30 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_90 ( & V_46 -> V_45 ) ;
F_91 ( & V_46 -> V_68 ) ;
F_92 ( & V_46 -> V_70 ) ;
if ( V_46 -> V_86 == 0 )
V_46 -> V_86 = V_87 ;
F_55 ( & V_46 -> V_7 , L_31 , V_46 -> V_77 ) ;
V_46 -> V_7 . V_55 = & V_56 ;
V_46 -> V_7 . type = & V_44 ;
V_66 = F_57 ( & V_46 -> V_7 ) ;
if ( V_66 )
goto V_84;
F_10 ( & V_46 -> V_7 , L_32 , V_46 -> V_5 ) ;
#ifdef F_93
V_66 = F_94 ( V_88 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
if ( V_66 )
F_84 ( & V_46 -> V_7 ,
L_33 ) ;
#endif
if ( V_46 -> V_77 < V_89 )
F_78 ( V_46 ) ;
F_69 ( & V_90 ) ;
F_95 ( & V_56 , NULL , V_46 , F_85 ) ;
F_71 ( & V_90 ) ;
return 0 ;
V_84:
F_69 ( & V_90 ) ;
F_96 ( & V_91 , V_46 -> V_77 ) ;
F_71 ( & V_90 ) ;
return V_66 ;
}
int F_97 ( struct V_40 * V_41 )
{
int V_2 ;
F_69 ( & V_90 ) ;
V_2 = F_98 ( & V_91 , V_41 ,
V_89 , 0 , V_49 ) ;
F_71 ( & V_90 ) ;
if ( V_2 < 0 )
return V_2 ;
V_41 -> V_77 = V_2 ;
return F_86 ( V_41 ) ;
}
int F_99 ( struct V_40 * V_46 )
{
int V_2 ;
if ( V_46 -> V_77 == - 1 )
return F_97 ( V_46 ) ;
F_69 ( & V_90 ) ;
V_2 = F_98 ( & V_91 , V_46 , V_46 -> V_77 , V_46 -> V_77 + 1 ,
V_49 ) ;
F_71 ( & V_90 ) ;
if ( V_2 < 0 )
return V_2 == - V_92 ? - V_39 : V_2 ;
return F_86 ( V_46 ) ;
}
static int F_100 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 , * V_93 ;
int V_66 ;
F_75 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_41 == V_41 ) {
F_10 ( & V_41 -> V_7 , L_34 ,
V_4 -> V_5 , V_4 -> V_36 ) ;
F_76 ( & V_4 -> V_69 ) ;
F_59 ( V_4 ) ;
}
}
if ( ! V_11 -> V_94 )
return 0 ;
F_84 ( & V_41 -> V_7 , L_35 ,
V_11 -> V_11 . V_5 ) ;
V_66 = V_11 -> V_94 ( V_41 ) ;
if ( V_66 )
F_53 ( & V_41 -> V_7 , L_36
L_37 , V_66 , V_11 -> V_11 . V_5 ) ;
return V_66 ;
}
static int F_101 ( struct V_6 * V_7 , void * V_95 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_12 ) )
F_59 ( V_4 ) ;
return 0 ;
}
static int F_102 ( struct V_6 * V_7 , void * V_95 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_59 ( V_4 ) ;
return 0 ;
}
static int F_103 ( struct V_8 * V_80 , void * V_81 )
{
return F_100 ( F_6 ( V_80 ) , V_81 ) ;
}
int F_104 ( struct V_40 * V_46 )
{
int V_66 = 0 ;
struct V_40 * V_96 ;
struct V_3 * V_4 , * V_71 ;
F_69 ( & V_90 ) ;
V_96 = F_105 ( & V_91 , V_46 -> V_77 ) ;
F_71 ( & V_90 ) ;
if ( V_96 != V_46 ) {
F_106 ( L_38
L_39 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_69 ( & V_90 ) ;
V_66 = F_95 ( & V_56 , NULL , V_46 ,
F_103 ) ;
F_71 ( & V_90 ) ;
if ( V_66 )
return V_66 ;
F_74 ( & V_46 -> V_68 ,
F_67 ( V_46 ) ) ;
F_75 (client, next, &adap->userspace_clients,
detected) {
F_10 ( & V_46 -> V_7 , L_34 , V_4 -> V_5 ,
V_4 -> V_36 ) ;
F_76 ( & V_4 -> V_69 ) ;
F_59 ( V_4 ) ;
}
F_71 ( & V_46 -> V_68 ) ;
V_66 = F_41 ( & V_46 -> V_7 , NULL , F_101 ) ;
V_66 = F_41 ( & V_46 -> V_7 , NULL , F_102 ) ;
#ifdef F_93
F_107 ( V_88 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
#endif
F_10 ( & V_46 -> V_7 , L_40 , V_46 -> V_5 ) ;
F_108 ( & V_46 -> V_61 ) ;
F_60 ( & V_46 -> V_7 ) ;
F_109 ( & V_46 -> V_61 ) ;
F_69 ( & V_90 ) ;
F_96 ( & V_91 , V_46 -> V_77 ) ;
F_71 ( & V_90 ) ;
memset ( & V_46 -> V_7 , 0 , sizeof( V_46 -> V_7 ) ) ;
return 0 ;
}
int F_110 ( void * V_81 , int (* F_111)( struct V_6 * , void * ) )
{
int V_66 ;
F_69 ( & V_90 ) ;
V_66 = F_112 ( & V_56 , NULL , V_81 , F_111 ) ;
F_71 ( & V_90 ) ;
return V_66 ;
}
static int F_113 ( struct V_6 * V_7 , void * V_81 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_82 ( V_81 , F_34 ( V_7 ) ) ;
}
int F_114 ( struct V_97 * V_98 , struct V_10 * V_11 )
{
int V_66 ;
if ( F_87 ( F_88 ( ! V_56 . V_82 ) ) )
return - V_83 ;
V_11 -> V_11 . V_98 = V_98 ;
V_11 -> V_11 . V_55 = & V_56 ;
V_66 = F_115 ( & V_11 -> V_11 ) ;
if ( V_66 )
return V_66 ;
if ( V_11 -> V_24 )
F_116 ( L_41 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_25 )
F_116 ( L_42 ,
V_11 -> V_11 . V_5 ) ;
F_106 ( L_43 , V_11 -> V_11 . V_5 ) ;
F_92 ( & V_11 -> V_99 ) ;
F_110 ( V_11 , F_113 ) ;
return 0 ;
}
static int F_117 ( struct V_6 * V_7 , void * V_81 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_100 ( V_81 , F_34 ( V_7 ) ) ;
}
void F_118 ( struct V_10 * V_11 )
{
F_110 ( V_11 , F_117 ) ;
F_119 ( & V_11 -> V_11 ) ;
F_106 ( L_44 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_120 ( struct V_3 * V_4 )
{
if ( V_4 && F_121 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_122 ( struct V_3 * V_4 )
{
if ( V_4 )
F_123 ( & V_4 -> V_7 ) ;
}
static int F_124 ( struct V_6 * V_7 , void * V_100 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_101 * V_102 = V_100 ;
if ( V_4 && V_4 -> V_11 && V_4 -> V_11 -> V_103 )
V_4 -> V_11 -> V_103 ( V_4 , V_102 -> V_104 , V_102 -> V_102 ) ;
return 0 ;
}
void F_125 ( struct V_40 * V_46 , unsigned int V_104 , void * V_102 )
{
struct V_101 V_105 ;
V_105 . V_104 = V_104 ;
V_105 . V_102 = V_102 ;
F_41 ( & V_46 -> V_7 , & V_105 , F_124 ) ;
}
static int T_5 F_126 ( void )
{
int V_106 ;
V_106 = F_127 ( & V_56 ) ;
if ( V_106 )
return V_106 ;
#ifdef F_93
V_88 = F_128 ( L_45 ) ;
if ( ! V_88 ) {
V_106 = - V_16 ;
goto V_107;
}
#endif
V_106 = F_129 ( & V_108 ) ;
if ( V_106 )
goto V_109;
return 0 ;
V_109:
#ifdef F_93
F_130 ( V_88 ) ;
V_107:
#endif
F_131 ( & V_56 ) ;
return V_106 ;
}
static void T_6 F_132 ( void )
{
F_118 ( & V_108 ) ;
#ifdef F_93
F_130 ( V_88 ) ;
#endif
F_131 ( & V_56 ) ;
}
int F_133 ( struct V_40 * V_46 , struct V_110 * V_111 , int V_112 )
{
unsigned long V_113 ;
int V_114 , V_115 ;
V_113 = V_116 ;
for ( V_114 = 0 , V_115 = 0 ; V_115 <= V_46 -> V_117 ; V_115 ++ ) {
V_114 = V_46 -> V_85 -> V_118 ( V_46 , V_111 , V_112 ) ;
if ( V_114 != - V_83 )
break;
if ( F_134 ( V_116 , V_113 + V_46 -> V_86 ) )
break;
}
return V_114 ;
}
int F_135 ( struct V_40 * V_46 , struct V_110 * V_111 , int V_112 )
{
int V_114 ;
if ( V_46 -> V_85 -> V_118 ) {
#ifdef F_136
for ( V_114 = 0 ; V_114 < V_112 ; V_114 ++ ) {
F_10 ( & V_46 -> V_7 , L_46
L_47 , V_114 , ( V_111 [ V_114 ] . V_20 & V_119 )
? 'R' : 'W' , V_111 [ V_114 ] . V_36 , V_111 [ V_114 ] . V_120 ,
( V_111 [ V_114 ] . V_20 & V_121 ) ? L_48 : L_49 ) ;
}
#endif
if ( F_137 () || F_138 () ) {
V_114 = F_46 ( V_46 ) ;
if ( ! V_114 )
return - V_83 ;
} else {
F_44 ( V_46 ) ;
}
V_114 = F_133 ( V_46 , V_111 , V_112 ) ;
F_48 ( V_46 ) ;
return V_114 ;
} else {
F_10 ( & V_46 -> V_7 , L_50 ) ;
return - V_122 ;
}
}
int F_139 ( const struct V_3 * V_4 , const char * V_33 , int V_63 )
{
int V_114 ;
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_110 V_123 ;
V_123 . V_36 = V_4 -> V_36 ;
V_123 . V_20 = V_4 -> V_20 & V_124 ;
V_123 . V_120 = V_63 ;
V_123 . V_33 = ( char * ) V_33 ;
V_114 = F_135 ( V_46 , & V_123 , 1 ) ;
return ( V_114 == 1 ) ? V_63 : V_114 ;
}
int F_140 ( const struct V_3 * V_4 , char * V_33 , int V_63 )
{
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_110 V_123 ;
int V_114 ;
V_123 . V_36 = V_4 -> V_36 ;
V_123 . V_20 = V_4 -> V_20 & V_124 ;
V_123 . V_20 |= V_119 ;
V_123 . V_120 = V_63 ;
V_123 . V_33 = V_33 ;
V_114 = F_135 ( V_46 , & V_123 , 1 ) ;
return ( V_114 == 1 ) ? V_63 : V_114 ;
}
static int F_141 ( struct V_40 * V_46 , unsigned short V_36 )
{
int V_125 ;
union V_126 V_95 ;
#ifdef F_142
if ( V_36 == 0x73 && ( V_46 -> V_127 & V_128 )
&& F_143 ( V_46 , V_129 ) )
V_125 = F_144 ( V_46 , V_36 , 0 , V_130 , 0 ,
V_131 , & V_95 ) ;
else
#endif
if ( ! ( ( V_36 & ~ 0x07 ) == 0x30 || ( V_36 & ~ 0x0f ) == 0x50 )
&& F_143 ( V_46 , V_132 ) )
V_125 = F_144 ( V_46 , V_36 , 0 , V_133 , 0 ,
V_134 , NULL ) ;
else if ( F_143 ( V_46 , V_135 ) )
V_125 = F_144 ( V_46 , V_36 , 0 , V_130 , 0 ,
V_136 , & V_95 ) ;
else {
F_84 ( & V_46 -> V_7 , L_51 ) ;
V_125 = - V_122 ;
}
return V_125 >= 0 ;
}
static int F_145 ( struct V_3 * V_137 ,
struct V_10 * V_11 )
{
struct V_47 V_48 ;
struct V_40 * V_41 = V_137 -> V_41 ;
int V_36 = V_137 -> V_36 ;
int V_125 ;
V_125 = F_37 ( V_36 ) ;
if ( V_125 ) {
F_84 ( & V_41 -> V_7 , L_52 ,
V_36 ) ;
return V_125 ;
}
if ( F_43 ( V_41 , V_36 ) )
return 0 ;
if ( ! F_141 ( V_41 , V_36 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_36 = V_36 ;
V_125 = V_11 -> V_138 ( V_137 , & V_48 ) ;
if ( V_125 ) {
return V_125 == - V_19 ? 0 : V_125 ;
}
if ( V_48 . type [ 0 ] == '\0' ) {
F_53 ( & V_41 -> V_7 , L_53
L_54 , V_11 -> V_11 . V_5 ,
V_36 ) ;
} else {
struct V_3 * V_4 ;
F_10 ( & V_41 -> V_7 , L_55 ,
V_48 . type , V_48 . V_36 ) ;
V_4 = F_50 ( V_41 , & V_48 ) ;
if ( V_4 )
F_70 ( & V_4 -> V_69 , & V_11 -> V_99 ) ;
else
F_53 ( & V_41 -> V_7 , L_56 ,
V_48 . type , V_48 . V_36 ) ;
}
return 0 ;
}
static int F_83 ( struct V_40 * V_41 , struct V_10 * V_11 )
{
const unsigned short * V_139 ;
struct V_3 * V_137 ;
int V_140 , V_125 = 0 ;
int V_141 = F_56 ( V_41 ) ;
V_139 = V_11 -> V_139 ;
if ( ! V_11 -> V_138 || ! V_139 )
return 0 ;
if ( ! ( V_41 -> V_127 & V_11 -> V_127 ) )
return 0 ;
V_137 = F_51 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_137 )
return - V_16 ;
V_137 -> V_41 = V_41 ;
for ( V_140 = 0 ; V_139 [ V_140 ] != V_142 ; V_140 += 1 ) {
F_10 ( & V_41 -> V_7 , L_57
L_58 , V_141 , V_139 [ V_140 ] ) ;
V_137 -> V_36 = V_139 [ V_140 ] ;
V_125 = F_145 ( V_137 , V_11 ) ;
if ( F_87 ( V_125 ) )
break;
}
F_32 ( V_137 ) ;
return V_125 ;
}
int F_146 ( struct V_40 * V_46 , unsigned short V_36 )
{
return F_144 ( V_46 , V_36 , 0 , V_130 , 0 ,
V_134 , NULL ) >= 0 ;
}
struct V_3 *
F_147 ( struct V_40 * V_46 ,
struct V_47 * V_48 ,
unsigned short const * V_143 ,
int (* V_18)( struct V_40 * , unsigned short V_36 ) )
{
int V_140 ;
if ( ! V_18 )
V_18 = F_141 ;
for ( V_140 = 0 ; V_143 [ V_140 ] != V_142 ; V_140 ++ ) {
if ( F_37 ( V_143 [ V_140 ] ) < 0 ) {
F_84 ( & V_46 -> V_7 , L_59
L_60 , V_143 [ V_140 ] ) ;
continue;
}
if ( F_43 ( V_46 , V_143 [ V_140 ] ) ) {
F_10 ( & V_46 -> V_7 , L_61
L_62 , V_143 [ V_140 ] ) ;
continue;
}
if ( V_18 ( V_46 , V_143 [ V_140 ] ) )
break;
}
if ( V_143 [ V_140 ] == V_142 ) {
F_10 ( & V_46 -> V_7 , L_63 ) ;
return NULL ;
}
V_48 -> V_36 = V_143 [ V_140 ] ;
return F_50 ( V_46 , V_48 ) ;
}
struct V_40 * F_148 ( int V_77 )
{
struct V_40 * V_41 ;
F_69 ( & V_90 ) ;
V_41 = F_105 ( & V_91 , V_77 ) ;
if ( V_41 && ! F_149 ( V_41 -> V_98 ) )
V_41 = NULL ;
F_71 ( & V_90 ) ;
return V_41 ;
}
void F_150 ( struct V_40 * V_46 )
{
F_151 ( V_46 -> V_98 ) ;
}
static T_7 F_152 ( T_3 V_81 )
{
int V_140 ;
for ( V_140 = 0 ; V_140 < 8 ; V_140 ++ ) {
if ( V_81 & 0x8000 )
V_81 = V_81 ^ V_144 ;
V_81 = V_81 << 1 ;
}
return ( T_7 ) ( V_81 >> 8 ) ;
}
static T_7 F_153 ( T_7 V_145 , T_7 * V_82 , T_4 V_63 )
{
int V_140 ;
for ( V_140 = 0 ; V_140 < V_63 ; V_140 ++ )
V_145 = F_152 ( ( V_145 ^ V_82 [ V_140 ] ) << 8 ) ;
return V_145 ;
}
static T_7 F_154 ( T_7 V_146 , struct V_110 * V_123 )
{
T_7 V_36 = ( V_123 -> V_36 << 1 ) | ! ! ( V_123 -> V_20 & V_119 ) ;
V_146 = F_153 ( V_146 , & V_36 , 1 ) ;
return F_153 ( V_146 , V_123 -> V_33 , V_123 -> V_120 ) ;
}
static inline void F_155 ( struct V_110 * V_123 )
{
V_123 -> V_33 [ V_123 -> V_120 ] = F_154 ( 0 , V_123 ) ;
V_123 -> V_120 ++ ;
}
static int F_156 ( T_7 V_147 , struct V_110 * V_123 )
{
T_7 V_148 = V_123 -> V_33 [ -- V_123 -> V_120 ] ;
V_147 = F_154 ( V_147 , V_123 ) ;
if ( V_148 != V_147 ) {
F_106 ( L_64 ,
V_148 , V_147 ) ;
return - V_149 ;
}
return 0 ;
}
T_8 F_157 ( const struct V_3 * V_4 )
{
union V_126 V_81 ;
int V_17 ;
V_17 = F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_130 , 0 ,
V_136 , & V_81 ) ;
return ( V_17 < 0 ) ? V_17 : V_81 . V_150 ;
}
T_8 F_158 ( const struct V_3 * V_4 , T_7 V_151 )
{
return F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_133 , V_151 , V_136 , NULL ) ;
}
T_8 F_159 ( const struct V_3 * V_4 , T_7 V_103 )
{
union V_126 V_81 ;
int V_17 ;
V_17 = F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_130 , V_103 ,
V_131 , & V_81 ) ;
return ( V_17 < 0 ) ? V_17 : V_81 . V_150 ;
}
T_8 F_160 ( const struct V_3 * V_4 , T_7 V_103 ,
T_7 V_151 )
{
union V_126 V_81 ;
V_81 . V_150 = V_151 ;
return F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_133 , V_103 ,
V_131 , & V_81 ) ;
}
T_8 F_161 ( const struct V_3 * V_4 , T_7 V_103 )
{
union V_126 V_81 ;
int V_17 ;
V_17 = F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_130 , V_103 ,
V_152 , & V_81 ) ;
return ( V_17 < 0 ) ? V_17 : V_81 . V_153 ;
}
T_8 F_162 ( const struct V_3 * V_4 , T_7 V_103 ,
T_3 V_151 )
{
union V_126 V_81 ;
V_81 . V_153 = V_151 ;
return F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_133 , V_103 ,
V_152 , & V_81 ) ;
}
T_8 F_163 ( const struct V_3 * V_4 , T_7 V_103 ,
T_7 * V_154 )
{
union V_126 V_81 ;
int V_17 ;
V_17 = F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_130 , V_103 ,
V_155 , & V_81 ) ;
if ( V_17 )
return V_17 ;
memcpy ( V_154 , & V_81 . V_156 [ 1 ] , V_81 . V_156 [ 0 ] ) ;
return V_81 . V_156 [ 0 ] ;
}
T_8 F_164 ( const struct V_3 * V_4 , T_7 V_103 ,
T_7 V_157 , const T_7 * V_154 )
{
union V_126 V_81 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_81 . V_156 [ 0 ] = V_157 ;
memcpy ( & V_81 . V_156 [ 1 ] , V_154 , V_157 ) ;
return F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_133 , V_103 ,
V_155 , & V_81 ) ;
}
T_8 F_165 ( const struct V_3 * V_4 , T_7 V_103 ,
T_7 V_157 , T_7 * V_154 )
{
union V_126 V_81 ;
int V_17 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_81 . V_156 [ 0 ] = V_157 ;
V_17 = F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_130 , V_103 ,
V_159 , & V_81 ) ;
if ( V_17 < 0 )
return V_17 ;
memcpy ( V_154 , & V_81 . V_156 [ 1 ] , V_81 . V_156 [ 0 ] ) ;
return V_81 . V_156 [ 0 ] ;
}
T_8 F_166 ( const struct V_3 * V_4 , T_7 V_103 ,
T_7 V_157 , const T_7 * V_154 )
{
union V_126 V_81 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_81 . V_156 [ 0 ] = V_157 ;
memcpy ( V_81 . V_156 + 1 , V_154 , V_157 ) ;
return F_144 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_133 , V_103 ,
V_159 , & V_81 ) ;
}
static T_8 F_167 ( struct V_40 * V_41 , T_3 V_36 ,
unsigned short V_20 ,
char V_160 , T_7 V_103 , int V_161 ,
union V_126 * V_81 )
{
unsigned char V_162 [ V_158 + 3 ] ;
unsigned char V_163 [ V_158 + 2 ] ;
int V_112 = V_160 == V_130 ? 2 : 1 ;
int V_140 ;
T_7 V_164 = 0 ;
int V_17 ;
struct V_110 V_123 [ 2 ] = {
{
. V_36 = V_36 ,
. V_20 = V_20 ,
. V_120 = 1 ,
. V_33 = V_162 ,
} , {
. V_36 = V_36 ,
. V_20 = V_20 | V_119 ,
. V_120 = 0 ,
. V_33 = V_163 ,
} ,
} ;
V_162 [ 0 ] = V_103 ;
switch ( V_161 ) {
case V_134 :
V_123 [ 0 ] . V_120 = 0 ;
V_123 [ 0 ] . V_20 = V_20 | ( V_160 == V_130 ?
V_119 : 0 ) ;
V_112 = 1 ;
break;
case V_136 :
if ( V_160 == V_130 ) {
V_123 [ 0 ] . V_20 = V_119 | V_20 ;
V_112 = 1 ;
}
break;
case V_131 :
if ( V_160 == V_130 )
V_123 [ 1 ] . V_120 = 1 ;
else {
V_123 [ 0 ] . V_120 = 2 ;
V_162 [ 1 ] = V_81 -> V_150 ;
}
break;
case V_152 :
if ( V_160 == V_130 )
V_123 [ 1 ] . V_120 = 2 ;
else {
V_123 [ 0 ] . V_120 = 3 ;
V_162 [ 1 ] = V_81 -> V_153 & 0xff ;
V_162 [ 2 ] = V_81 -> V_153 >> 8 ;
}
break;
case V_165 :
V_112 = 2 ;
V_160 = V_130 ;
V_123 [ 0 ] . V_120 = 3 ;
V_123 [ 1 ] . V_120 = 2 ;
V_162 [ 1 ] = V_81 -> V_153 & 0xff ;
V_162 [ 2 ] = V_81 -> V_153 >> 8 ;
break;
case V_155 :
if ( V_160 == V_130 ) {
V_123 [ 1 ] . V_20 |= V_121 ;
V_123 [ 1 ] . V_120 = 1 ;
} else {
V_123 [ 0 ] . V_120 = V_81 -> V_156 [ 0 ] + 2 ;
if ( V_123 [ 0 ] . V_120 > V_158 + 2 ) {
F_53 ( & V_41 -> V_7 ,
L_65 ,
V_81 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
for ( V_140 = 1 ; V_140 < V_123 [ 0 ] . V_120 ; V_140 ++ )
V_162 [ V_140 ] = V_81 -> V_156 [ V_140 - 1 ] ;
}
break;
case V_166 :
V_112 = 2 ;
V_160 = V_130 ;
if ( V_81 -> V_156 [ 0 ] > V_158 ) {
F_53 ( & V_41 -> V_7 ,
L_65 ,
V_81 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
V_123 [ 0 ] . V_120 = V_81 -> V_156 [ 0 ] + 2 ;
for ( V_140 = 1 ; V_140 < V_123 [ 0 ] . V_120 ; V_140 ++ )
V_162 [ V_140 ] = V_81 -> V_156 [ V_140 - 1 ] ;
V_123 [ 1 ] . V_20 |= V_121 ;
V_123 [ 1 ] . V_120 = 1 ;
break;
case V_159 :
if ( V_160 == V_130 ) {
V_123 [ 1 ] . V_120 = V_81 -> V_156 [ 0 ] ;
} else {
V_123 [ 0 ] . V_120 = V_81 -> V_156 [ 0 ] + 1 ;
if ( V_123 [ 0 ] . V_120 > V_158 + 1 ) {
F_53 ( & V_41 -> V_7 ,
L_65 ,
V_81 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
for ( V_140 = 1 ; V_140 <= V_81 -> V_156 [ 0 ] ; V_140 ++ )
V_162 [ V_140 ] = V_81 -> V_156 [ V_140 ] ;
}
break;
default:
F_53 ( & V_41 -> V_7 , L_66 , V_161 ) ;
return - V_122 ;
}
V_140 = ( ( V_20 & V_167 ) && V_161 != V_134
&& V_161 != V_159 ) ;
if ( V_140 ) {
if ( ! ( V_123 [ 0 ] . V_20 & V_119 ) ) {
if ( V_112 == 1 )
F_155 ( & V_123 [ 0 ] ) ;
else
V_164 = F_154 ( 0 , & V_123 [ 0 ] ) ;
}
if ( V_123 [ V_112 - 1 ] . V_20 & V_119 )
V_123 [ V_112 - 1 ] . V_120 ++ ;
}
V_17 = F_135 ( V_41 , V_123 , V_112 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_140 && ( V_123 [ V_112 - 1 ] . V_20 & V_119 ) ) {
V_17 = F_156 ( V_164 , & V_123 [ V_112 - 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_160 == V_130 )
switch ( V_161 ) {
case V_136 :
V_81 -> V_150 = V_162 [ 0 ] ;
break;
case V_131 :
V_81 -> V_150 = V_163 [ 0 ] ;
break;
case V_152 :
case V_165 :
V_81 -> V_153 = V_163 [ 0 ] | ( V_163 [ 1 ] << 8 ) ;
break;
case V_159 :
for ( V_140 = 0 ; V_140 < V_81 -> V_156 [ 0 ] ; V_140 ++ )
V_81 -> V_156 [ V_140 + 1 ] = V_163 [ V_140 ] ;
break;
case V_155 :
case V_166 :
for ( V_140 = 0 ; V_140 < V_163 [ 0 ] + 1 ; V_140 ++ )
V_81 -> V_156 [ V_140 ] = V_163 [ V_140 ] ;
break;
}
return 0 ;
}
T_8 F_144 ( struct V_40 * V_41 , T_3 V_36 , unsigned short V_20 ,
char V_160 , T_7 V_103 , int V_168 ,
union V_126 * V_81 )
{
unsigned long V_113 ;
int V_115 ;
T_8 V_66 ;
V_20 &= V_124 | V_167 | V_169 ;
if ( V_41 -> V_85 -> V_170 ) {
F_44 ( V_41 ) ;
V_113 = V_116 ;
for ( V_66 = 0 , V_115 = 0 ; V_115 <= V_41 -> V_117 ; V_115 ++ ) {
V_66 = V_41 -> V_85 -> V_170 ( V_41 , V_36 , V_20 ,
V_160 , V_103 ,
V_168 , V_81 ) ;
if ( V_66 != - V_83 )
break;
if ( F_134 ( V_116 ,
V_113 + V_41 -> V_86 ) )
break;
}
F_48 ( V_41 ) ;
if ( V_66 != - V_122 || ! V_41 -> V_85 -> V_118 )
return V_66 ;
}
return F_167 ( V_41 , V_36 , V_20 , V_160 ,
V_103 , V_168 , V_81 ) ;
}
