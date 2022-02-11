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
V_11 = F_5 ( V_9 ) ;
if ( V_11 -> V_12 )
return F_1 ( V_11 -> V_12 , V_4 ) != NULL ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 , struct V_13 * V_14 )
{
struct V_3 * V_4 = F_7 ( V_7 ) ;
if ( F_8 ( V_14 , L_1 ,
V_15 , V_4 -> V_5 ) )
return - V_16 ;
F_9 ( V_7 , L_2 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_17 ;
if ( ! V_4 )
return 0 ;
V_11 = F_5 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_18 || ! V_11 -> V_12 )
return - V_19 ;
V_4 -> V_11 = V_11 ;
if ( ! F_11 ( & V_4 -> V_7 ) )
F_12 ( & V_4 -> V_7 ,
V_4 -> V_20 & V_21 ) ;
F_9 ( V_7 , L_3 ) ;
V_17 = V_11 -> V_18 ( V_4 , F_1 ( V_11 -> V_12 , V_4 ) ) ;
if ( V_17 ) {
V_4 -> V_11 = NULL ;
F_13 ( V_4 , NULL ) ;
}
return V_17 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
int V_17 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_5 ( V_7 -> V_11 ) ;
if ( V_11 -> remove ) {
F_9 ( V_7 , L_4 ) ;
V_17 = V_11 -> remove ( V_4 ) ;
} else {
V_7 -> V_11 = NULL ;
V_17 = 0 ;
}
if ( V_17 == 0 ) {
V_4 -> V_11 = NULL ;
F_13 ( V_4 , NULL ) ;
}
return V_17 ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return;
V_11 = F_5 ( V_7 -> V_11 ) ;
if ( V_11 -> V_22 )
V_11 -> V_22 ( V_4 ) ;
}
static int F_16 ( struct V_6 * V_7 , T_1 V_23 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_5 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_24 )
return 0 ;
return V_11 -> V_24 ( V_4 , V_23 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_4 || ! V_7 -> V_11 )
return 0 ;
V_11 = F_5 ( V_7 -> V_11 ) ;
if ( ! V_11 -> V_25 )
return 0 ;
return V_11 -> V_25 ( V_4 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_19 ( V_7 ) ;
else
return F_16 ( V_7 , V_28 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_21 ( V_7 ) ;
else
return F_17 ( V_7 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_23 ( V_7 ) ;
else
return F_16 ( V_7 , V_29 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_25 ( V_7 ) ;
else
return F_17 ( V_7 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_27 ( V_7 ) ;
else
return F_16 ( V_7 , V_30 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
const struct V_26 * V_27 = V_7 -> V_11 ? V_7 -> V_11 -> V_27 : NULL ;
if ( V_27 )
return F_29 ( V_7 ) ;
else
return F_17 ( V_7 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
F_31 ( F_7 ( V_7 ) ) ;
}
static T_2
F_32 ( struct V_6 * V_7 , struct V_31 * V_32 , char * V_33 )
{
return sprintf ( V_33 , L_5 , V_7 -> type == & V_34 ?
F_7 ( V_7 ) -> V_5 : F_33 ( V_7 ) -> V_5 ) ;
}
static T_2
F_34 ( struct V_6 * V_7 , struct V_31 * V_32 , char * V_33 )
{
struct V_3 * V_4 = F_7 ( V_7 ) ;
return sprintf ( V_33 , L_6 , V_15 , V_4 -> V_5 ) ;
}
struct V_3 * F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_34 )
? F_7 ( V_7 )
: NULL ;
}
static int F_35 ( const struct V_3 * V_4 )
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
static int F_36 ( unsigned short V_36 )
{
if ( V_36 < 0x08 || V_36 > 0x77 )
return - V_37 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , void * V_38 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
int V_36 = * ( int * ) V_38 ;
if ( V_4 && V_4 -> V_36 == V_36 )
return - V_39 ;
return 0 ;
}
static int F_38 ( struct V_40 * V_41 , int V_36 )
{
struct V_40 * V_42 = F_39 ( V_41 ) ;
int V_43 ;
V_43 = F_40 ( & V_41 -> V_7 , & V_36 ,
F_37 ) ;
if ( ! V_43 && V_42 )
V_43 = F_38 ( V_42 , V_36 ) ;
return V_43 ;
}
static int F_41 ( struct V_6 * V_7 , void * V_38 )
{
int V_43 ;
if ( V_7 -> type == & V_44 )
V_43 = F_40 ( V_7 , V_38 ,
F_41 ) ;
else
V_43 = F_37 ( V_7 , V_38 ) ;
return V_43 ;
}
static int F_42 ( struct V_40 * V_41 , int V_36 )
{
struct V_40 * V_42 = F_39 ( V_41 ) ;
int V_43 = 0 ;
if ( V_42 )
V_43 = F_38 ( V_42 , V_36 ) ;
if ( ! V_43 )
V_43 = F_40 ( & V_41 -> V_7 , & V_36 ,
F_41 ) ;
return V_43 ;
}
void F_43 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_39 ( V_41 ) ;
if ( V_42 )
F_43 ( V_42 ) ;
else
F_44 ( & V_41 -> V_45 ) ;
}
static int F_45 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_39 ( V_41 ) ;
if ( V_42 )
return F_45 ( V_42 ) ;
else
return F_46 ( & V_41 -> V_45 ) ;
}
void F_47 ( struct V_40 * V_41 )
{
struct V_40 * V_42 = F_39 ( V_41 ) ;
if ( V_42 )
F_47 ( V_42 ) ;
else
F_48 ( & V_41 -> V_45 ) ;
}
struct V_3 *
F_49 ( struct V_40 * V_46 , struct V_47 const * V_48 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_50 ( sizeof *V_4 , V_49 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_41 = V_46 ;
V_4 -> V_7 . V_50 = V_48 -> V_50 ;
if ( V_48 -> V_51 )
V_4 -> V_7 . V_51 = * V_48 -> V_51 ;
V_4 -> V_20 = V_48 -> V_20 ;
V_4 -> V_36 = V_48 -> V_36 ;
V_4 -> V_52 = V_48 -> V_52 ;
F_51 ( V_4 -> V_5 , V_48 -> type , sizeof( V_4 -> V_5 ) ) ;
V_17 = F_35 ( V_4 ) ;
if ( V_17 ) {
F_52 ( & V_46 -> V_7 , L_7 ,
V_4 -> V_20 & V_35 ? 10 : 7 , V_4 -> V_36 ) ;
goto V_53;
}
V_17 = F_42 ( V_46 , V_4 -> V_36 ) ;
if ( V_17 )
goto V_54;
V_4 -> V_7 . V_42 = & V_4 -> V_41 -> V_7 ;
V_4 -> V_7 . V_55 = & V_56 ;
V_4 -> V_7 . type = & V_34 ;
V_4 -> V_7 . V_57 = V_48 -> V_57 ;
F_53 ( & V_4 -> V_7 , L_8 , F_54 ( V_46 ) ,
V_4 -> V_36 ) ;
V_17 = F_55 ( & V_4 -> V_7 ) ;
if ( V_17 )
goto V_54;
F_9 ( & V_46 -> V_7 , L_9 ,
V_4 -> V_5 , F_56 ( & V_4 -> V_7 ) ) ;
return V_4 ;
V_54:
F_52 ( & V_46 -> V_7 , L_10
L_11 , V_4 -> V_5 , V_4 -> V_36 , V_17 ) ;
V_53:
F_31 ( V_4 ) ;
return NULL ;
}
void F_57 ( struct V_3 * V_4 )
{
F_58 ( & V_4 -> V_7 ) ;
}
static int F_59 ( struct V_3 * V_4 ,
const struct V_1 * V_2 )
{
return 0 ;
}
static int F_60 ( struct V_3 * V_4 )
{
return 0 ;
}
struct V_3 * F_61 ( struct V_40 * V_41 , T_3 V_58 )
{
struct V_47 V_48 = {
F_62 ( L_12 , V_58 ) ,
} ;
return F_49 ( V_41 , & V_48 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_40 * V_46 = F_33 ( V_7 ) ;
F_64 ( & V_46 -> V_59 ) ;
}
static T_2
F_65 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_60 )
{
struct V_40 * V_46 = F_33 ( V_7 ) ;
struct V_47 V_48 ;
struct V_3 * V_4 ;
char * V_61 , V_62 ;
int V_63 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_61 = strchr ( V_33 , ' ' ) ;
if ( ! V_61 ) {
F_52 ( V_7 , L_13 , L_14 ) ;
return - V_37 ;
}
if ( V_61 - V_33 > V_64 - 1 ) {
F_52 ( V_7 , L_15 , L_14 ) ;
return - V_37 ;
}
memcpy ( V_48 . type , V_33 , V_61 - V_33 ) ;
V_63 = sscanf ( ++ V_61 , L_16 , & V_48 . V_36 , & V_62 ) ;
if ( V_63 < 1 ) {
F_52 ( V_7 , L_17 , L_14 ) ;
return - V_37 ;
}
if ( V_63 > 1 && V_62 != '\n' ) {
F_52 ( V_7 , L_18 , L_14 ) ;
return - V_37 ;
}
V_4 = F_49 ( V_46 , & V_48 ) ;
if ( ! V_4 )
return - V_37 ;
F_66 ( & V_46 -> V_65 ) ;
F_67 ( & V_4 -> V_66 , & V_46 -> V_67 ) ;
F_68 ( & V_46 -> V_65 ) ;
F_69 ( V_7 , L_19 , L_14 ,
V_48 . type , V_48 . V_36 ) ;
return V_60 ;
}
static T_2
F_70 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_60 )
{
struct V_40 * V_46 = F_33 ( V_7 ) ;
struct V_3 * V_4 , * V_68 ;
unsigned short V_36 ;
char V_62 ;
int V_63 ;
V_63 = sscanf ( V_33 , L_16 , & V_36 , & V_62 ) ;
if ( V_63 < 1 ) {
F_52 ( V_7 , L_17 , L_20 ) ;
return - V_37 ;
}
if ( V_63 > 1 && V_62 != '\n' ) {
F_52 ( V_7 , L_18 , L_20 ) ;
return - V_37 ;
}
V_63 = - V_69 ;
F_66 ( & V_46 -> V_65 ) ;
F_71 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_36 == V_36 ) {
F_69 ( V_7 , L_21 ,
L_20 , V_4 -> V_5 , V_4 -> V_36 ) ;
F_72 ( & V_4 -> V_66 ) ;
F_57 ( V_4 ) ;
V_63 = V_60 ;
break;
}
}
F_68 ( & V_46 -> V_65 ) ;
if ( V_63 < 0 )
F_52 ( V_7 , L_22 ,
L_20 ) ;
return V_63 ;
}
static void F_73 ( struct V_40 * V_41 )
{
struct V_70 * V_71 ;
F_74 ( & V_72 ) ;
F_75 (devinfo, &__i2c_board_list, list) {
if ( V_71 -> V_73 == V_41 -> V_74
&& ! F_49 ( V_41 ,
& V_71 -> V_75 ) )
F_52 ( & V_41 -> V_7 ,
L_23 ,
V_71 -> V_75 . V_36 ) ;
}
F_76 ( & V_72 ) ;
}
static int F_77 ( struct V_10 * V_11 ,
struct V_40 * V_46 )
{
F_78 ( V_46 , V_11 ) ;
if ( V_11 -> V_76 ) {
F_79 ( & V_46 -> V_7 , L_24 ,
V_11 -> V_11 . V_5 ) ;
F_79 ( & V_46 -> V_7 , L_25
L_26 ) ;
V_11 -> V_76 ( V_46 ) ;
}
return 0 ;
}
static int F_80 ( struct V_8 * V_77 , void * V_78 )
{
return F_77 ( F_5 ( V_77 ) , V_78 ) ;
}
static int F_81 ( struct V_40 * V_46 )
{
int V_63 = 0 ;
if ( F_82 ( F_83 ( ! V_56 . V_79 ) ) ) {
V_63 = - V_80 ;
goto V_81;
}
if ( F_82 ( V_46 -> V_5 [ 0 ] == '\0' ) ) {
F_84 ( L_27
L_28 ) ;
return - V_37 ;
}
if ( F_82 ( ! V_46 -> V_82 ) ) {
F_84 ( L_29
L_30 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_85 ( & V_46 -> V_45 ) ;
F_86 ( & V_46 -> V_65 ) ;
F_87 ( & V_46 -> V_67 ) ;
if ( V_46 -> V_83 == 0 )
V_46 -> V_83 = V_84 ;
F_53 ( & V_46 -> V_7 , L_31 , V_46 -> V_74 ) ;
V_46 -> V_7 . V_55 = & V_56 ;
V_46 -> V_7 . type = & V_44 ;
V_63 = F_55 ( & V_46 -> V_7 ) ;
if ( V_63 )
goto V_81;
F_9 ( & V_46 -> V_7 , L_32 , V_46 -> V_5 ) ;
#ifdef F_88
V_63 = F_89 ( V_85 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
if ( V_63 )
F_79 ( & V_46 -> V_7 ,
L_33 ) ;
#endif
if ( V_46 -> V_74 < V_86 )
F_73 ( V_46 ) ;
F_66 ( & V_87 ) ;
F_90 ( & V_56 , NULL , V_46 , F_80 ) ;
F_68 ( & V_87 ) ;
return 0 ;
V_81:
F_66 ( & V_87 ) ;
F_91 ( & V_88 , V_46 -> V_74 ) ;
F_68 ( & V_87 ) ;
return V_63 ;
}
int F_92 ( struct V_40 * V_41 )
{
int V_2 , V_63 = 0 ;
V_89:
if ( F_93 ( & V_88 , V_49 ) == 0 )
return - V_16 ;
F_66 ( & V_87 ) ;
V_63 = F_94 ( & V_88 , V_41 ,
V_86 , & V_2 ) ;
F_68 ( & V_87 ) ;
if ( V_63 < 0 ) {
if ( V_63 == - V_80 )
goto V_89;
return V_63 ;
}
V_41 -> V_74 = V_2 ;
return F_81 ( V_41 ) ;
}
int F_95 ( struct V_40 * V_46 )
{
int V_2 ;
int V_17 ;
if ( V_46 -> V_74 & ~ V_90 )
return - V_37 ;
V_89:
if ( F_93 ( & V_88 , V_49 ) == 0 )
return - V_16 ;
F_66 ( & V_87 ) ;
V_17 = F_94 ( & V_88 , V_46 , V_46 -> V_74 , & V_2 ) ;
if ( V_17 == 0 && V_2 != V_46 -> V_74 ) {
V_17 = - V_39 ;
F_91 ( & V_88 , V_2 ) ;
}
F_68 ( & V_87 ) ;
if ( V_17 == - V_80 )
goto V_89;
if ( V_17 == 0 )
V_17 = F_81 ( V_46 ) ;
return V_17 ;
}
static int F_96 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 , * V_91 ;
int V_63 ;
F_71 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_41 == V_41 ) {
F_9 ( & V_41 -> V_7 , L_34 ,
V_4 -> V_5 , V_4 -> V_36 ) ;
F_72 ( & V_4 -> V_66 ) ;
F_57 ( V_4 ) ;
}
}
if ( ! V_11 -> V_92 )
return 0 ;
F_79 ( & V_41 -> V_7 , L_35 ,
V_11 -> V_11 . V_5 ) ;
V_63 = V_11 -> V_92 ( V_41 ) ;
if ( V_63 )
F_52 ( & V_41 -> V_7 , L_36
L_37 , V_63 , V_11 -> V_11 . V_5 ) ;
return V_63 ;
}
static int F_97 ( struct V_6 * V_7 , void * V_93 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_12 ) )
F_57 ( V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 , void * V_93 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_57 ( V_4 ) ;
return 0 ;
}
static int F_99 ( struct V_8 * V_77 , void * V_78 )
{
return F_96 ( F_5 ( V_77 ) , V_78 ) ;
}
int F_100 ( struct V_40 * V_46 )
{
int V_63 = 0 ;
struct V_40 * V_94 ;
struct V_3 * V_4 , * V_68 ;
F_66 ( & V_87 ) ;
V_94 = F_101 ( & V_88 , V_46 -> V_74 ) ;
F_68 ( & V_87 ) ;
if ( V_94 != V_46 ) {
F_102 ( L_38
L_39 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_66 ( & V_87 ) ;
V_63 = F_90 ( & V_56 , NULL , V_46 ,
F_99 ) ;
F_68 ( & V_87 ) ;
if ( V_63 )
return V_63 ;
F_66 ( & V_46 -> V_65 ) ;
F_71 (client, next, &adap->userspace_clients,
detected) {
F_9 ( & V_46 -> V_7 , L_34 , V_4 -> V_5 ,
V_4 -> V_36 ) ;
F_72 ( & V_4 -> V_66 ) ;
F_57 ( V_4 ) ;
}
F_68 ( & V_46 -> V_65 ) ;
V_63 = F_40 ( & V_46 -> V_7 , NULL , F_97 ) ;
V_63 = F_40 ( & V_46 -> V_7 , NULL , F_98 ) ;
#ifdef F_88
F_103 ( V_85 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
#endif
F_9 ( & V_46 -> V_7 , L_40 , V_46 -> V_5 ) ;
F_104 ( & V_46 -> V_59 ) ;
F_58 ( & V_46 -> V_7 ) ;
F_105 ( & V_46 -> V_59 ) ;
F_66 ( & V_87 ) ;
F_91 ( & V_88 , V_46 -> V_74 ) ;
F_68 ( & V_87 ) ;
memset ( & V_46 -> V_7 , 0 , sizeof( V_46 -> V_7 ) ) ;
return 0 ;
}
int F_106 ( void * V_78 , int (* F_107)( struct V_6 * , void * ) )
{
int V_63 ;
F_66 ( & V_87 ) ;
V_63 = F_108 ( & V_56 , NULL , V_78 , F_107 ) ;
F_68 ( & V_87 ) ;
return V_63 ;
}
static int F_109 ( struct V_6 * V_7 , void * V_78 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_77 ( V_78 , F_33 ( V_7 ) ) ;
}
int F_110 ( struct V_95 * V_96 , struct V_10 * V_11 )
{
int V_63 ;
if ( F_82 ( F_83 ( ! V_56 . V_79 ) ) )
return - V_80 ;
V_11 -> V_11 . V_96 = V_96 ;
V_11 -> V_11 . V_55 = & V_56 ;
V_63 = F_111 ( & V_11 -> V_11 ) ;
if ( V_63 )
return V_63 ;
if ( V_11 -> V_24 )
F_112 ( L_41 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_25 )
F_112 ( L_42 ,
V_11 -> V_11 . V_5 ) ;
F_102 ( L_43 , V_11 -> V_11 . V_5 ) ;
F_87 ( & V_11 -> V_97 ) ;
F_106 ( V_11 , F_109 ) ;
return 0 ;
}
static int F_113 ( struct V_6 * V_7 , void * V_78 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_96 ( V_78 , F_33 ( V_7 ) ) ;
}
void F_114 ( struct V_10 * V_11 )
{
F_106 ( V_11 , F_113 ) ;
F_115 ( & V_11 -> V_11 ) ;
F_102 ( L_44 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_116 ( struct V_3 * V_4 )
{
if ( V_4 && F_117 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_118 ( struct V_3 * V_4 )
{
if ( V_4 )
F_119 ( & V_4 -> V_7 ) ;
}
static int F_120 ( struct V_6 * V_7 , void * V_98 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_99 * V_100 = V_98 ;
if ( V_4 && V_4 -> V_11 && V_4 -> V_11 -> V_101 )
V_4 -> V_11 -> V_101 ( V_4 , V_100 -> V_102 , V_100 -> V_100 ) ;
return 0 ;
}
void F_121 ( struct V_40 * V_46 , unsigned int V_102 , void * V_100 )
{
struct V_99 V_103 ;
V_103 . V_102 = V_102 ;
V_103 . V_100 = V_100 ;
F_40 ( & V_46 -> V_7 , & V_103 , F_120 ) ;
}
static int T_5 F_122 ( void )
{
int V_104 ;
V_104 = F_123 ( & V_56 ) ;
if ( V_104 )
return V_104 ;
#ifdef F_88
V_85 = F_124 ( L_45 ) ;
if ( ! V_85 ) {
V_104 = - V_16 ;
goto V_105;
}
#endif
V_104 = F_125 ( & V_106 ) ;
if ( V_104 )
goto V_107;
return 0 ;
V_107:
#ifdef F_88
F_126 ( V_85 ) ;
V_105:
#endif
F_127 ( & V_56 ) ;
return V_104 ;
}
static void T_6 F_128 ( void )
{
F_114 ( & V_106 ) ;
#ifdef F_88
F_126 ( V_85 ) ;
#endif
F_127 ( & V_56 ) ;
}
int F_129 ( struct V_40 * V_46 , struct V_108 * V_109 , int V_110 )
{
unsigned long V_111 ;
int V_112 , V_113 ;
if ( V_46 -> V_82 -> V_114 ) {
#ifdef F_130
for ( V_112 = 0 ; V_112 < V_110 ; V_112 ++ ) {
F_9 ( & V_46 -> V_7 , L_46
L_47 , V_112 , ( V_109 [ V_112 ] . V_20 & V_115 )
? 'R' : 'W' , V_109 [ V_112 ] . V_36 , V_109 [ V_112 ] . V_116 ,
( V_109 [ V_112 ] . V_20 & V_117 ) ? L_48 : L_49 ) ;
}
#endif
if ( F_131 () || F_132 () ) {
V_112 = F_45 ( V_46 ) ;
if ( ! V_112 )
return - V_80 ;
} else {
F_43 ( V_46 ) ;
}
V_111 = V_118 ;
for ( V_112 = 0 , V_113 = 0 ; V_113 <= V_46 -> V_119 ; V_113 ++ ) {
V_112 = V_46 -> V_82 -> V_114 ( V_46 , V_109 , V_110 ) ;
if ( V_112 != - V_80 )
break;
if ( F_133 ( V_118 , V_111 + V_46 -> V_83 ) )
break;
}
F_47 ( V_46 ) ;
return V_112 ;
} else {
F_9 ( & V_46 -> V_7 , L_50 ) ;
return - V_120 ;
}
}
int F_134 ( const struct V_3 * V_4 , const char * V_33 , int V_60 )
{
int V_112 ;
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_108 V_121 ;
V_121 . V_36 = V_4 -> V_36 ;
V_121 . V_20 = V_4 -> V_20 & V_122 ;
V_121 . V_116 = V_60 ;
V_121 . V_33 = ( char * ) V_33 ;
V_112 = F_129 ( V_46 , & V_121 , 1 ) ;
return ( V_112 == 1 ) ? V_60 : V_112 ;
}
int F_135 ( const struct V_3 * V_4 , char * V_33 , int V_60 )
{
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_108 V_121 ;
int V_112 ;
V_121 . V_36 = V_4 -> V_36 ;
V_121 . V_20 = V_4 -> V_20 & V_122 ;
V_121 . V_20 |= V_115 ;
V_121 . V_116 = V_60 ;
V_121 . V_33 = V_33 ;
V_112 = F_129 ( V_46 , & V_121 , 1 ) ;
return ( V_112 == 1 ) ? V_60 : V_112 ;
}
static int F_136 ( struct V_40 * V_46 , unsigned short V_36 )
{
int V_123 ;
union V_124 V_93 ;
#ifdef F_137
if ( V_36 == 0x73 && ( V_46 -> V_125 & V_126 )
&& F_138 ( V_46 , V_127 ) )
V_123 = F_139 ( V_46 , V_36 , 0 , V_128 , 0 ,
V_129 , & V_93 ) ;
else
#endif
if ( ! ( ( V_36 & ~ 0x07 ) == 0x30 || ( V_36 & ~ 0x0f ) == 0x50 )
&& F_138 ( V_46 , V_130 ) )
V_123 = F_139 ( V_46 , V_36 , 0 , V_131 , 0 ,
V_132 , NULL ) ;
else if ( F_138 ( V_46 , V_133 ) )
V_123 = F_139 ( V_46 , V_36 , 0 , V_128 , 0 ,
V_134 , & V_93 ) ;
else {
F_79 ( & V_46 -> V_7 , L_51 ) ;
V_123 = - V_120 ;
}
return V_123 >= 0 ;
}
static int F_140 ( struct V_3 * V_135 ,
struct V_10 * V_11 )
{
struct V_47 V_48 ;
struct V_40 * V_41 = V_135 -> V_41 ;
int V_36 = V_135 -> V_36 ;
int V_123 ;
V_123 = F_36 ( V_36 ) ;
if ( V_123 ) {
F_79 ( & V_41 -> V_7 , L_52 ,
V_36 ) ;
return V_123 ;
}
if ( F_42 ( V_41 , V_36 ) )
return 0 ;
if ( ! F_136 ( V_41 , V_36 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_36 = V_36 ;
V_123 = V_11 -> V_136 ( V_135 , & V_48 ) ;
if ( V_123 ) {
return V_123 == - V_19 ? 0 : V_123 ;
}
if ( V_48 . type [ 0 ] == '\0' ) {
F_52 ( & V_41 -> V_7 , L_53
L_54 , V_11 -> V_11 . V_5 ,
V_36 ) ;
} else {
struct V_3 * V_4 ;
F_9 ( & V_41 -> V_7 , L_55 ,
V_48 . type , V_48 . V_36 ) ;
V_4 = F_49 ( V_41 , & V_48 ) ;
if ( V_4 )
F_67 ( & V_4 -> V_66 , & V_11 -> V_97 ) ;
else
F_52 ( & V_41 -> V_7 , L_56 ,
V_48 . type , V_48 . V_36 ) ;
}
return 0 ;
}
static int F_78 ( struct V_40 * V_41 , struct V_10 * V_11 )
{
const unsigned short * V_137 ;
struct V_3 * V_135 ;
int V_138 , V_123 = 0 ;
int V_139 = F_54 ( V_41 ) ;
V_137 = V_11 -> V_137 ;
if ( ! V_11 -> V_136 || ! V_137 )
return 0 ;
if ( ! ( V_41 -> V_125 & V_11 -> V_125 ) )
return 0 ;
V_135 = F_50 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_135 )
return - V_16 ;
V_135 -> V_41 = V_41 ;
for ( V_138 = 0 ; V_137 [ V_138 ] != V_140 ; V_138 += 1 ) {
F_9 ( & V_41 -> V_7 , L_57
L_58 , V_139 , V_137 [ V_138 ] ) ;
V_135 -> V_36 = V_137 [ V_138 ] ;
V_123 = F_140 ( V_135 , V_11 ) ;
if ( F_82 ( V_123 ) )
break;
}
F_31 ( V_135 ) ;
return V_123 ;
}
int F_141 ( struct V_40 * V_46 , unsigned short V_36 )
{
return F_139 ( V_46 , V_36 , 0 , V_128 , 0 ,
V_132 , NULL ) >= 0 ;
}
struct V_3 *
F_142 ( struct V_40 * V_46 ,
struct V_47 * V_48 ,
unsigned short const * V_141 ,
int (* V_18)( struct V_40 * , unsigned short V_36 ) )
{
int V_138 ;
if ( ! V_18 )
V_18 = F_136 ;
for ( V_138 = 0 ; V_141 [ V_138 ] != V_140 ; V_138 ++ ) {
if ( F_36 ( V_141 [ V_138 ] ) < 0 ) {
F_79 ( & V_46 -> V_7 , L_59
L_60 , V_141 [ V_138 ] ) ;
continue;
}
if ( F_42 ( V_46 , V_141 [ V_138 ] ) ) {
F_9 ( & V_46 -> V_7 , L_61
L_62 , V_141 [ V_138 ] ) ;
continue;
}
if ( V_18 ( V_46 , V_141 [ V_138 ] ) )
break;
}
if ( V_141 [ V_138 ] == V_140 ) {
F_9 ( & V_46 -> V_7 , L_63 ) ;
return NULL ;
}
V_48 -> V_36 = V_141 [ V_138 ] ;
return F_49 ( V_46 , V_48 ) ;
}
struct V_40 * F_143 ( int V_74 )
{
struct V_40 * V_41 ;
F_66 ( & V_87 ) ;
V_41 = F_101 ( & V_88 , V_74 ) ;
if ( V_41 && ! F_144 ( V_41 -> V_96 ) )
V_41 = NULL ;
F_68 ( & V_87 ) ;
return V_41 ;
}
void F_145 ( struct V_40 * V_46 )
{
F_146 ( V_46 -> V_96 ) ;
}
static T_7 F_147 ( T_3 V_78 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < 8 ; V_138 ++ ) {
if ( V_78 & 0x8000 )
V_78 = V_78 ^ V_142 ;
V_78 = V_78 << 1 ;
}
return ( T_7 ) ( V_78 >> 8 ) ;
}
static T_7 F_148 ( T_7 V_143 , T_7 * V_79 , T_4 V_60 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_60 ; V_138 ++ )
V_143 = F_147 ( ( V_143 ^ V_79 [ V_138 ] ) << 8 ) ;
return V_143 ;
}
static T_7 F_149 ( T_7 V_144 , struct V_108 * V_121 )
{
T_7 V_36 = ( V_121 -> V_36 << 1 ) | ! ! ( V_121 -> V_20 & V_115 ) ;
V_144 = F_148 ( V_144 , & V_36 , 1 ) ;
return F_148 ( V_144 , V_121 -> V_33 , V_121 -> V_116 ) ;
}
static inline void F_150 ( struct V_108 * V_121 )
{
V_121 -> V_33 [ V_121 -> V_116 ] = F_149 ( 0 , V_121 ) ;
V_121 -> V_116 ++ ;
}
static int F_151 ( T_7 V_145 , struct V_108 * V_121 )
{
T_7 V_146 = V_121 -> V_33 [ -- V_121 -> V_116 ] ;
V_145 = F_149 ( V_145 , V_121 ) ;
if ( V_146 != V_145 ) {
F_102 ( L_64 ,
V_146 , V_145 ) ;
return - V_147 ;
}
return 0 ;
}
T_8 F_152 ( const struct V_3 * V_4 )
{
union V_124 V_78 ;
int V_17 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_128 , 0 ,
V_134 , & V_78 ) ;
return ( V_17 < 0 ) ? V_17 : V_78 . V_148 ;
}
T_8 F_153 ( const struct V_3 * V_4 , T_7 V_149 )
{
return F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_149 , V_134 , NULL ) ;
}
T_8 F_154 ( const struct V_3 * V_4 , T_7 V_101 )
{
union V_124 V_78 ;
int V_17 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_128 , V_101 ,
V_129 , & V_78 ) ;
return ( V_17 < 0 ) ? V_17 : V_78 . V_148 ;
}
T_8 F_155 ( const struct V_3 * V_4 , T_7 V_101 ,
T_7 V_149 )
{
union V_124 V_78 ;
V_78 . V_148 = V_149 ;
return F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_101 ,
V_129 , & V_78 ) ;
}
T_8 F_156 ( const struct V_3 * V_4 , T_7 V_101 )
{
union V_124 V_78 ;
int V_17 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_128 , V_101 ,
V_150 , & V_78 ) ;
return ( V_17 < 0 ) ? V_17 : V_78 . V_151 ;
}
T_8 F_157 ( const struct V_3 * V_4 , T_7 V_101 ,
T_3 V_149 )
{
union V_124 V_78 ;
V_78 . V_151 = V_149 ;
return F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_101 ,
V_150 , & V_78 ) ;
}
T_8 F_158 ( const struct V_3 * V_4 , T_7 V_101 ,
T_3 V_149 )
{
union V_124 V_78 ;
int V_17 ;
V_78 . V_151 = V_149 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_101 ,
V_152 , & V_78 ) ;
return ( V_17 < 0 ) ? V_17 : V_78 . V_151 ;
}
T_8 F_159 ( const struct V_3 * V_4 , T_7 V_101 ,
T_7 * V_153 )
{
union V_124 V_78 ;
int V_17 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_128 , V_101 ,
V_154 , & V_78 ) ;
if ( V_17 )
return V_17 ;
memcpy ( V_153 , & V_78 . V_155 [ 1 ] , V_78 . V_155 [ 0 ] ) ;
return V_78 . V_155 [ 0 ] ;
}
T_8 F_160 ( const struct V_3 * V_4 , T_7 V_101 ,
T_7 V_156 , const T_7 * V_153 )
{
union V_124 V_78 ;
if ( V_156 > V_157 )
V_156 = V_157 ;
V_78 . V_155 [ 0 ] = V_156 ;
memcpy ( & V_78 . V_155 [ 1 ] , V_153 , V_156 ) ;
return F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_101 ,
V_154 , & V_78 ) ;
}
T_8 F_161 ( const struct V_3 * V_4 , T_7 V_101 ,
T_7 V_156 , T_7 * V_153 )
{
union V_124 V_78 ;
int V_17 ;
if ( V_156 > V_157 )
V_156 = V_157 ;
V_78 . V_155 [ 0 ] = V_156 ;
V_17 = F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_128 , V_101 ,
V_158 , & V_78 ) ;
if ( V_17 < 0 )
return V_17 ;
memcpy ( V_153 , & V_78 . V_155 [ 1 ] , V_78 . V_155 [ 0 ] ) ;
return V_78 . V_155 [ 0 ] ;
}
T_8 F_162 ( const struct V_3 * V_4 , T_7 V_101 ,
T_7 V_156 , const T_7 * V_153 )
{
union V_124 V_78 ;
if ( V_156 > V_157 )
V_156 = V_157 ;
V_78 . V_155 [ 0 ] = V_156 ;
memcpy ( V_78 . V_155 + 1 , V_153 , V_156 ) ;
return F_139 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_131 , V_101 ,
V_158 , & V_78 ) ;
}
static T_8 F_163 ( struct V_40 * V_41 , T_3 V_36 ,
unsigned short V_20 ,
char V_159 , T_7 V_101 , int V_160 ,
union V_124 * V_78 )
{
unsigned char V_161 [ V_157 + 3 ] ;
unsigned char V_162 [ V_157 + 2 ] ;
int V_110 = V_159 == V_128 ? 2 : 1 ;
struct V_108 V_121 [ 2 ] = { { V_36 , V_20 , 1 , V_161 } ,
{ V_36 , V_20 | V_115 , 0 , V_162 }
} ;
int V_138 ;
T_7 V_163 = 0 ;
int V_17 ;
V_161 [ 0 ] = V_101 ;
switch ( V_160 ) {
case V_132 :
V_121 [ 0 ] . V_116 = 0 ;
V_121 [ 0 ] . V_20 = V_20 | ( V_159 == V_128 ?
V_115 : 0 ) ;
V_110 = 1 ;
break;
case V_134 :
if ( V_159 == V_128 ) {
V_121 [ 0 ] . V_20 = V_115 | V_20 ;
V_110 = 1 ;
}
break;
case V_129 :
if ( V_159 == V_128 )
V_121 [ 1 ] . V_116 = 1 ;
else {
V_121 [ 0 ] . V_116 = 2 ;
V_161 [ 1 ] = V_78 -> V_148 ;
}
break;
case V_150 :
if ( V_159 == V_128 )
V_121 [ 1 ] . V_116 = 2 ;
else {
V_121 [ 0 ] . V_116 = 3 ;
V_161 [ 1 ] = V_78 -> V_151 & 0xff ;
V_161 [ 2 ] = V_78 -> V_151 >> 8 ;
}
break;
case V_152 :
V_110 = 2 ;
V_159 = V_128 ;
V_121 [ 0 ] . V_116 = 3 ;
V_121 [ 1 ] . V_116 = 2 ;
V_161 [ 1 ] = V_78 -> V_151 & 0xff ;
V_161 [ 2 ] = V_78 -> V_151 >> 8 ;
break;
case V_154 :
if ( V_159 == V_128 ) {
V_121 [ 1 ] . V_20 |= V_117 ;
V_121 [ 1 ] . V_116 = 1 ;
} else {
V_121 [ 0 ] . V_116 = V_78 -> V_155 [ 0 ] + 2 ;
if ( V_121 [ 0 ] . V_116 > V_157 + 2 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_78 -> V_155 [ 0 ] ) ;
return - V_37 ;
}
for ( V_138 = 1 ; V_138 < V_121 [ 0 ] . V_116 ; V_138 ++ )
V_161 [ V_138 ] = V_78 -> V_155 [ V_138 - 1 ] ;
}
break;
case V_164 :
V_110 = 2 ;
V_159 = V_128 ;
if ( V_78 -> V_155 [ 0 ] > V_157 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_78 -> V_155 [ 0 ] ) ;
return - V_37 ;
}
V_121 [ 0 ] . V_116 = V_78 -> V_155 [ 0 ] + 2 ;
for ( V_138 = 1 ; V_138 < V_121 [ 0 ] . V_116 ; V_138 ++ )
V_161 [ V_138 ] = V_78 -> V_155 [ V_138 - 1 ] ;
V_121 [ 1 ] . V_20 |= V_117 ;
V_121 [ 1 ] . V_116 = 1 ;
break;
case V_158 :
if ( V_159 == V_128 ) {
V_121 [ 1 ] . V_116 = V_78 -> V_155 [ 0 ] ;
} else {
V_121 [ 0 ] . V_116 = V_78 -> V_155 [ 0 ] + 1 ;
if ( V_121 [ 0 ] . V_116 > V_157 + 1 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_78 -> V_155 [ 0 ] ) ;
return - V_37 ;
}
for ( V_138 = 1 ; V_138 <= V_78 -> V_155 [ 0 ] ; V_138 ++ )
V_161 [ V_138 ] = V_78 -> V_155 [ V_138 ] ;
}
break;
default:
F_52 ( & V_41 -> V_7 , L_66 , V_160 ) ;
return - V_120 ;
}
V_138 = ( ( V_20 & V_165 ) && V_160 != V_132
&& V_160 != V_158 ) ;
if ( V_138 ) {
if ( ! ( V_121 [ 0 ] . V_20 & V_115 ) ) {
if ( V_110 == 1 )
F_150 ( & V_121 [ 0 ] ) ;
else
V_163 = F_149 ( 0 , & V_121 [ 0 ] ) ;
}
if ( V_121 [ V_110 - 1 ] . V_20 & V_115 )
V_121 [ V_110 - 1 ] . V_116 ++ ;
}
V_17 = F_129 ( V_41 , V_121 , V_110 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_138 && ( V_121 [ V_110 - 1 ] . V_20 & V_115 ) ) {
V_17 = F_151 ( V_163 , & V_121 [ V_110 - 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_159 == V_128 )
switch ( V_160 ) {
case V_134 :
V_78 -> V_148 = V_161 [ 0 ] ;
break;
case V_129 :
V_78 -> V_148 = V_162 [ 0 ] ;
break;
case V_150 :
case V_152 :
V_78 -> V_151 = V_162 [ 0 ] | ( V_162 [ 1 ] << 8 ) ;
break;
case V_158 :
for ( V_138 = 0 ; V_138 < V_78 -> V_155 [ 0 ] ; V_138 ++ )
V_78 -> V_155 [ V_138 + 1 ] = V_162 [ V_138 ] ;
break;
case V_154 :
case V_164 :
for ( V_138 = 0 ; V_138 < V_162 [ 0 ] + 1 ; V_138 ++ )
V_78 -> V_155 [ V_138 ] = V_162 [ V_138 ] ;
break;
}
return 0 ;
}
T_8 F_139 ( struct V_40 * V_41 , T_3 V_36 , unsigned short V_20 ,
char V_159 , T_7 V_101 , int V_166 ,
union V_124 * V_78 )
{
unsigned long V_111 ;
int V_113 ;
T_8 V_63 ;
V_20 &= V_122 | V_165 ;
if ( V_41 -> V_82 -> V_167 ) {
F_43 ( V_41 ) ;
V_111 = V_118 ;
for ( V_63 = 0 , V_113 = 0 ; V_113 <= V_41 -> V_119 ; V_113 ++ ) {
V_63 = V_41 -> V_82 -> V_167 ( V_41 , V_36 , V_20 ,
V_159 , V_101 ,
V_166 , V_78 ) ;
if ( V_63 != - V_80 )
break;
if ( F_133 ( V_118 ,
V_111 + V_41 -> V_83 ) )
break;
}
F_47 ( V_41 ) ;
} else
V_63 = F_163 ( V_41 , V_36 , V_20 , V_159 ,
V_101 , V_166 , V_78 ) ;
return V_63 ;
}
