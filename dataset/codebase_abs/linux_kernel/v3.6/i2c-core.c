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
V_4 -> V_36 | ( ( V_4 -> V_20 & V_35 )
? 0xa000 : 0 ) ) ;
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
static inline unsigned int F_65 ( struct V_40 * V_41 )
{
unsigned int V_60 = 0 ;
while ( ( V_41 = F_39 ( V_41 ) ) )
V_60 ++ ;
return V_60 ;
}
static T_2
F_66 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_61 )
{
struct V_40 * V_46 = F_33 ( V_7 ) ;
struct V_47 V_48 ;
struct V_3 * V_4 ;
char * V_62 , V_63 ;
int V_64 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_62 = strchr ( V_33 , ' ' ) ;
if ( ! V_62 ) {
F_52 ( V_7 , L_13 , L_14 ) ;
return - V_37 ;
}
if ( V_62 - V_33 > V_65 - 1 ) {
F_52 ( V_7 , L_15 , L_14 ) ;
return - V_37 ;
}
memcpy ( V_48 . type , V_33 , V_62 - V_33 ) ;
V_64 = sscanf ( ++ V_62 , L_16 , & V_48 . V_36 , & V_63 ) ;
if ( V_64 < 1 ) {
F_52 ( V_7 , L_17 , L_14 ) ;
return - V_37 ;
}
if ( V_64 > 1 && V_63 != '\n' ) {
F_52 ( V_7 , L_18 , L_14 ) ;
return - V_37 ;
}
V_4 = F_49 ( V_46 , & V_48 ) ;
if ( ! V_4 )
return - V_37 ;
F_67 ( & V_46 -> V_66 ) ;
F_68 ( & V_4 -> V_67 , & V_46 -> V_68 ) ;
F_69 ( & V_46 -> V_66 ) ;
F_70 ( V_7 , L_19 , L_14 ,
V_48 . type , V_48 . V_36 ) ;
return V_61 ;
}
static T_2
F_71 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_61 )
{
struct V_40 * V_46 = F_33 ( V_7 ) ;
struct V_3 * V_4 , * V_69 ;
unsigned short V_36 ;
char V_63 ;
int V_64 ;
V_64 = sscanf ( V_33 , L_16 , & V_36 , & V_63 ) ;
if ( V_64 < 1 ) {
F_52 ( V_7 , L_17 , L_20 ) ;
return - V_37 ;
}
if ( V_64 > 1 && V_63 != '\n' ) {
F_52 ( V_7 , L_18 , L_20 ) ;
return - V_37 ;
}
V_64 = - V_70 ;
F_72 ( & V_46 -> V_66 ,
F_65 ( V_46 ) ) ;
F_73 (client, next, &adap->userspace_clients,
detected) {
if ( V_4 -> V_36 == V_36 ) {
F_70 ( V_7 , L_21 ,
L_20 , V_4 -> V_5 , V_4 -> V_36 ) ;
F_74 ( & V_4 -> V_67 ) ;
F_57 ( V_4 ) ;
V_64 = V_61 ;
break;
}
}
F_69 ( & V_46 -> V_66 ) ;
if ( V_64 < 0 )
F_52 ( V_7 , L_22 ,
L_20 ) ;
return V_64 ;
}
struct V_40 * F_75 ( struct V_6 * V_7 )
{
return ( V_7 -> type == & V_44 )
? F_33 ( V_7 )
: NULL ;
}
static void F_76 ( struct V_40 * V_41 )
{
struct V_71 * V_72 ;
F_77 ( & V_73 ) ;
F_78 (devinfo, &__i2c_board_list, list) {
if ( V_72 -> V_74 == V_41 -> V_75
&& ! F_49 ( V_41 ,
& V_72 -> V_76 ) )
F_52 ( & V_41 -> V_7 ,
L_23 ,
V_72 -> V_76 . V_36 ) ;
}
F_79 ( & V_73 ) ;
}
static int F_80 ( struct V_10 * V_11 ,
struct V_40 * V_46 )
{
F_81 ( V_46 , V_11 ) ;
if ( V_11 -> V_77 ) {
F_82 ( & V_46 -> V_7 , L_24 ,
V_11 -> V_11 . V_5 ) ;
F_82 ( & V_46 -> V_7 , L_25
L_26 ) ;
V_11 -> V_77 ( V_46 ) ;
}
return 0 ;
}
static int F_83 ( struct V_8 * V_78 , void * V_79 )
{
return F_80 ( F_5 ( V_78 ) , V_79 ) ;
}
static int F_84 ( struct V_40 * V_46 )
{
int V_64 = 0 ;
if ( F_85 ( F_86 ( ! V_56 . V_80 ) ) ) {
V_64 = - V_81 ;
goto V_82;
}
if ( F_85 ( V_46 -> V_5 [ 0 ] == '\0' ) ) {
F_87 ( L_27
L_28 ) ;
return - V_37 ;
}
if ( F_85 ( ! V_46 -> V_83 ) ) {
F_87 ( L_29
L_30 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_88 ( & V_46 -> V_45 ) ;
F_89 ( & V_46 -> V_66 ) ;
F_90 ( & V_46 -> V_68 ) ;
if ( V_46 -> V_84 == 0 )
V_46 -> V_84 = V_85 ;
F_53 ( & V_46 -> V_7 , L_31 , V_46 -> V_75 ) ;
V_46 -> V_7 . V_55 = & V_56 ;
V_46 -> V_7 . type = & V_44 ;
V_64 = F_55 ( & V_46 -> V_7 ) ;
if ( V_64 )
goto V_82;
F_9 ( & V_46 -> V_7 , L_32 , V_46 -> V_5 ) ;
#ifdef F_91
V_64 = F_92 ( V_86 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
if ( V_64 )
F_82 ( & V_46 -> V_7 ,
L_33 ) ;
#endif
if ( V_46 -> V_75 < V_87 )
F_76 ( V_46 ) ;
F_67 ( & V_88 ) ;
F_93 ( & V_56 , NULL , V_46 , F_83 ) ;
F_69 ( & V_88 ) ;
return 0 ;
V_82:
F_67 ( & V_88 ) ;
F_94 ( & V_89 , V_46 -> V_75 ) ;
F_69 ( & V_88 ) ;
return V_64 ;
}
int F_95 ( struct V_40 * V_41 )
{
int V_2 , V_64 = 0 ;
V_90:
if ( F_96 ( & V_89 , V_49 ) == 0 )
return - V_16 ;
F_67 ( & V_88 ) ;
V_64 = F_97 ( & V_89 , V_41 ,
V_87 , & V_2 ) ;
F_69 ( & V_88 ) ;
if ( V_64 < 0 ) {
if ( V_64 == - V_81 )
goto V_90;
return V_64 ;
}
V_41 -> V_75 = V_2 ;
return F_84 ( V_41 ) ;
}
int F_98 ( struct V_40 * V_46 )
{
int V_2 ;
int V_17 ;
if ( V_46 -> V_75 == - 1 )
return F_95 ( V_46 ) ;
if ( V_46 -> V_75 & ~ V_91 )
return - V_37 ;
V_90:
if ( F_96 ( & V_89 , V_49 ) == 0 )
return - V_16 ;
F_67 ( & V_88 ) ;
V_17 = F_97 ( & V_89 , V_46 , V_46 -> V_75 , & V_2 ) ;
if ( V_17 == 0 && V_2 != V_46 -> V_75 ) {
V_17 = - V_39 ;
F_94 ( & V_89 , V_2 ) ;
}
F_69 ( & V_88 ) ;
if ( V_17 == - V_81 )
goto V_90;
if ( V_17 == 0 )
V_17 = F_84 ( V_46 ) ;
return V_17 ;
}
static int F_99 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 , * V_92 ;
int V_64 ;
F_73 (client, _n, &driver->clients, detected) {
if ( V_4 -> V_41 == V_41 ) {
F_9 ( & V_41 -> V_7 , L_34 ,
V_4 -> V_5 , V_4 -> V_36 ) ;
F_74 ( & V_4 -> V_67 ) ;
F_57 ( V_4 ) ;
}
}
if ( ! V_11 -> V_93 )
return 0 ;
F_82 ( & V_41 -> V_7 , L_35 ,
V_11 -> V_11 . V_5 ) ;
V_64 = V_11 -> V_93 ( V_41 ) ;
if ( V_64 )
F_52 ( & V_41 -> V_7 , L_36
L_37 , V_64 , V_11 -> V_11 . V_5 ) ;
return V_64 ;
}
static int F_100 ( struct V_6 * V_7 , void * V_94 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 && strcmp ( V_4 -> V_5 , L_12 ) )
F_57 ( V_4 ) ;
return 0 ;
}
static int F_101 ( struct V_6 * V_7 , void * V_94 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
if ( V_4 )
F_57 ( V_4 ) ;
return 0 ;
}
static int F_102 ( struct V_8 * V_78 , void * V_79 )
{
return F_99 ( F_5 ( V_78 ) , V_79 ) ;
}
int F_103 ( struct V_40 * V_46 )
{
int V_64 = 0 ;
struct V_40 * V_95 ;
struct V_3 * V_4 , * V_69 ;
F_67 ( & V_88 ) ;
V_95 = F_104 ( & V_89 , V_46 -> V_75 ) ;
F_69 ( & V_88 ) ;
if ( V_95 != V_46 ) {
F_105 ( L_38
L_39 , V_46 -> V_5 ) ;
return - V_37 ;
}
F_67 ( & V_88 ) ;
V_64 = F_93 ( & V_56 , NULL , V_46 ,
F_102 ) ;
F_69 ( & V_88 ) ;
if ( V_64 )
return V_64 ;
F_72 ( & V_46 -> V_66 ,
F_65 ( V_46 ) ) ;
F_73 (client, next, &adap->userspace_clients,
detected) {
F_9 ( & V_46 -> V_7 , L_34 , V_4 -> V_5 ,
V_4 -> V_36 ) ;
F_74 ( & V_4 -> V_67 ) ;
F_57 ( V_4 ) ;
}
F_69 ( & V_46 -> V_66 ) ;
V_64 = F_40 ( & V_46 -> V_7 , NULL , F_100 ) ;
V_64 = F_40 ( & V_46 -> V_7 , NULL , F_101 ) ;
#ifdef F_91
F_106 ( V_86 , & V_46 -> V_7 ,
V_46 -> V_7 . V_42 ) ;
#endif
F_9 ( & V_46 -> V_7 , L_40 , V_46 -> V_5 ) ;
F_107 ( & V_46 -> V_59 ) ;
F_58 ( & V_46 -> V_7 ) ;
F_108 ( & V_46 -> V_59 ) ;
F_67 ( & V_88 ) ;
F_94 ( & V_89 , V_46 -> V_75 ) ;
F_69 ( & V_88 ) ;
memset ( & V_46 -> V_7 , 0 , sizeof( V_46 -> V_7 ) ) ;
return 0 ;
}
int F_109 ( void * V_79 , int (* F_110)( struct V_6 * , void * ) )
{
int V_64 ;
F_67 ( & V_88 ) ;
V_64 = F_111 ( & V_56 , NULL , V_79 , F_110 ) ;
F_69 ( & V_88 ) ;
return V_64 ;
}
static int F_112 ( struct V_6 * V_7 , void * V_79 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_80 ( V_79 , F_33 ( V_7 ) ) ;
}
int F_113 ( struct V_96 * V_97 , struct V_10 * V_11 )
{
int V_64 ;
if ( F_85 ( F_86 ( ! V_56 . V_80 ) ) )
return - V_81 ;
V_11 -> V_11 . V_97 = V_97 ;
V_11 -> V_11 . V_55 = & V_56 ;
V_64 = F_114 ( & V_11 -> V_11 ) ;
if ( V_64 )
return V_64 ;
if ( V_11 -> V_24 )
F_115 ( L_41 ,
V_11 -> V_11 . V_5 ) ;
if ( V_11 -> V_25 )
F_115 ( L_42 ,
V_11 -> V_11 . V_5 ) ;
F_105 ( L_43 , V_11 -> V_11 . V_5 ) ;
F_90 ( & V_11 -> V_98 ) ;
F_109 ( V_11 , F_112 ) ;
return 0 ;
}
static int F_116 ( struct V_6 * V_7 , void * V_79 )
{
if ( V_7 -> type != & V_44 )
return 0 ;
return F_99 ( V_79 , F_33 ( V_7 ) ) ;
}
void F_117 ( struct V_10 * V_11 )
{
F_109 ( V_11 , F_116 ) ;
F_118 ( & V_11 -> V_11 ) ;
F_105 ( L_44 , V_11 -> V_11 . V_5 ) ;
}
struct V_3 * F_119 ( struct V_3 * V_4 )
{
if ( V_4 && F_120 ( & V_4 -> V_7 ) )
return V_4 ;
return NULL ;
}
void F_121 ( struct V_3 * V_4 )
{
if ( V_4 )
F_122 ( & V_4 -> V_7 ) ;
}
static int F_123 ( struct V_6 * V_7 , void * V_99 )
{
struct V_3 * V_4 = F_3 ( V_7 ) ;
struct V_100 * V_101 = V_99 ;
if ( V_4 && V_4 -> V_11 && V_4 -> V_11 -> V_102 )
V_4 -> V_11 -> V_102 ( V_4 , V_101 -> V_103 , V_101 -> V_101 ) ;
return 0 ;
}
void F_124 ( struct V_40 * V_46 , unsigned int V_103 , void * V_101 )
{
struct V_100 V_104 ;
V_104 . V_103 = V_103 ;
V_104 . V_101 = V_101 ;
F_40 ( & V_46 -> V_7 , & V_104 , F_123 ) ;
}
static int T_5 F_125 ( void )
{
int V_105 ;
V_105 = F_126 ( & V_56 ) ;
if ( V_105 )
return V_105 ;
#ifdef F_91
V_86 = F_127 ( L_45 ) ;
if ( ! V_86 ) {
V_105 = - V_16 ;
goto V_106;
}
#endif
V_105 = F_128 ( & V_107 ) ;
if ( V_105 )
goto V_108;
return 0 ;
V_108:
#ifdef F_91
F_129 ( V_86 ) ;
V_106:
#endif
F_130 ( & V_56 ) ;
return V_105 ;
}
static void T_6 F_131 ( void )
{
F_117 ( & V_107 ) ;
#ifdef F_91
F_129 ( V_86 ) ;
#endif
F_130 ( & V_56 ) ;
}
int F_132 ( struct V_40 * V_46 , struct V_109 * V_110 , int V_111 )
{
unsigned long V_112 ;
int V_113 , V_114 ;
V_112 = V_115 ;
for ( V_113 = 0 , V_114 = 0 ; V_114 <= V_46 -> V_116 ; V_114 ++ ) {
V_113 = V_46 -> V_83 -> V_117 ( V_46 , V_110 , V_111 ) ;
if ( V_113 != - V_81 )
break;
if ( F_133 ( V_115 , V_112 + V_46 -> V_84 ) )
break;
}
return V_113 ;
}
int F_134 ( struct V_40 * V_46 , struct V_109 * V_110 , int V_111 )
{
int V_113 ;
if ( V_46 -> V_83 -> V_117 ) {
#ifdef F_135
for ( V_113 = 0 ; V_113 < V_111 ; V_113 ++ ) {
F_9 ( & V_46 -> V_7 , L_46
L_47 , V_113 , ( V_110 [ V_113 ] . V_20 & V_118 )
? 'R' : 'W' , V_110 [ V_113 ] . V_36 , V_110 [ V_113 ] . V_119 ,
( V_110 [ V_113 ] . V_20 & V_120 ) ? L_48 : L_49 ) ;
}
#endif
if ( F_136 () || F_137 () ) {
V_113 = F_45 ( V_46 ) ;
if ( ! V_113 )
return - V_81 ;
} else {
F_43 ( V_46 ) ;
}
V_113 = F_132 ( V_46 , V_110 , V_111 ) ;
F_47 ( V_46 ) ;
return V_113 ;
} else {
F_9 ( & V_46 -> V_7 , L_50 ) ;
return - V_121 ;
}
}
int F_138 ( const struct V_3 * V_4 , const char * V_33 , int V_61 )
{
int V_113 ;
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_109 V_122 ;
V_122 . V_36 = V_4 -> V_36 ;
V_122 . V_20 = V_4 -> V_20 & V_123 ;
V_122 . V_119 = V_61 ;
V_122 . V_33 = ( char * ) V_33 ;
V_113 = F_134 ( V_46 , & V_122 , 1 ) ;
return ( V_113 == 1 ) ? V_61 : V_113 ;
}
int F_139 ( const struct V_3 * V_4 , char * V_33 , int V_61 )
{
struct V_40 * V_46 = V_4 -> V_41 ;
struct V_109 V_122 ;
int V_113 ;
V_122 . V_36 = V_4 -> V_36 ;
V_122 . V_20 = V_4 -> V_20 & V_123 ;
V_122 . V_20 |= V_118 ;
V_122 . V_119 = V_61 ;
V_122 . V_33 = V_33 ;
V_113 = F_134 ( V_46 , & V_122 , 1 ) ;
return ( V_113 == 1 ) ? V_61 : V_113 ;
}
static int F_140 ( struct V_40 * V_46 , unsigned short V_36 )
{
int V_124 ;
union V_125 V_94 ;
#ifdef F_141
if ( V_36 == 0x73 && ( V_46 -> V_126 & V_127 )
&& F_142 ( V_46 , V_128 ) )
V_124 = F_143 ( V_46 , V_36 , 0 , V_129 , 0 ,
V_130 , & V_94 ) ;
else
#endif
if ( ! ( ( V_36 & ~ 0x07 ) == 0x30 || ( V_36 & ~ 0x0f ) == 0x50 )
&& F_142 ( V_46 , V_131 ) )
V_124 = F_143 ( V_46 , V_36 , 0 , V_132 , 0 ,
V_133 , NULL ) ;
else if ( F_142 ( V_46 , V_134 ) )
V_124 = F_143 ( V_46 , V_36 , 0 , V_129 , 0 ,
V_135 , & V_94 ) ;
else {
F_82 ( & V_46 -> V_7 , L_51 ) ;
V_124 = - V_121 ;
}
return V_124 >= 0 ;
}
static int F_144 ( struct V_3 * V_136 ,
struct V_10 * V_11 )
{
struct V_47 V_48 ;
struct V_40 * V_41 = V_136 -> V_41 ;
int V_36 = V_136 -> V_36 ;
int V_124 ;
V_124 = F_36 ( V_36 ) ;
if ( V_124 ) {
F_82 ( & V_41 -> V_7 , L_52 ,
V_36 ) ;
return V_124 ;
}
if ( F_42 ( V_41 , V_36 ) )
return 0 ;
if ( ! F_140 ( V_41 , V_36 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_36 = V_36 ;
V_124 = V_11 -> V_137 ( V_136 , & V_48 ) ;
if ( V_124 ) {
return V_124 == - V_19 ? 0 : V_124 ;
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
F_68 ( & V_4 -> V_67 , & V_11 -> V_98 ) ;
else
F_52 ( & V_41 -> V_7 , L_56 ,
V_48 . type , V_48 . V_36 ) ;
}
return 0 ;
}
static int F_81 ( struct V_40 * V_41 , struct V_10 * V_11 )
{
const unsigned short * V_138 ;
struct V_3 * V_136 ;
int V_139 , V_124 = 0 ;
int V_140 = F_54 ( V_41 ) ;
V_138 = V_11 -> V_138 ;
if ( ! V_11 -> V_137 || ! V_138 )
return 0 ;
if ( ! ( V_41 -> V_126 & V_11 -> V_126 ) )
return 0 ;
V_136 = F_50 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_136 )
return - V_16 ;
V_136 -> V_41 = V_41 ;
for ( V_139 = 0 ; V_138 [ V_139 ] != V_141 ; V_139 += 1 ) {
F_9 ( & V_41 -> V_7 , L_57
L_58 , V_140 , V_138 [ V_139 ] ) ;
V_136 -> V_36 = V_138 [ V_139 ] ;
V_124 = F_144 ( V_136 , V_11 ) ;
if ( F_85 ( V_124 ) )
break;
}
F_31 ( V_136 ) ;
return V_124 ;
}
int F_145 ( struct V_40 * V_46 , unsigned short V_36 )
{
return F_143 ( V_46 , V_36 , 0 , V_129 , 0 ,
V_133 , NULL ) >= 0 ;
}
struct V_3 *
F_146 ( struct V_40 * V_46 ,
struct V_47 * V_48 ,
unsigned short const * V_142 ,
int (* V_18)( struct V_40 * , unsigned short V_36 ) )
{
int V_139 ;
if ( ! V_18 )
V_18 = F_140 ;
for ( V_139 = 0 ; V_142 [ V_139 ] != V_141 ; V_139 ++ ) {
if ( F_36 ( V_142 [ V_139 ] ) < 0 ) {
F_82 ( & V_46 -> V_7 , L_59
L_60 , V_142 [ V_139 ] ) ;
continue;
}
if ( F_42 ( V_46 , V_142 [ V_139 ] ) ) {
F_9 ( & V_46 -> V_7 , L_61
L_62 , V_142 [ V_139 ] ) ;
continue;
}
if ( V_18 ( V_46 , V_142 [ V_139 ] ) )
break;
}
if ( V_142 [ V_139 ] == V_141 ) {
F_9 ( & V_46 -> V_7 , L_63 ) ;
return NULL ;
}
V_48 -> V_36 = V_142 [ V_139 ] ;
return F_49 ( V_46 , V_48 ) ;
}
struct V_40 * F_147 ( int V_75 )
{
struct V_40 * V_41 ;
F_67 ( & V_88 ) ;
V_41 = F_104 ( & V_89 , V_75 ) ;
if ( V_41 && ! F_148 ( V_41 -> V_97 ) )
V_41 = NULL ;
F_69 ( & V_88 ) ;
return V_41 ;
}
void F_149 ( struct V_40 * V_46 )
{
F_150 ( V_46 -> V_97 ) ;
}
static T_7 F_151 ( T_3 V_79 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < 8 ; V_139 ++ ) {
if ( V_79 & 0x8000 )
V_79 = V_79 ^ V_143 ;
V_79 = V_79 << 1 ;
}
return ( T_7 ) ( V_79 >> 8 ) ;
}
static T_7 F_152 ( T_7 V_144 , T_7 * V_80 , T_4 V_61 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_61 ; V_139 ++ )
V_144 = F_151 ( ( V_144 ^ V_80 [ V_139 ] ) << 8 ) ;
return V_144 ;
}
static T_7 F_153 ( T_7 V_145 , struct V_109 * V_122 )
{
T_7 V_36 = ( V_122 -> V_36 << 1 ) | ! ! ( V_122 -> V_20 & V_118 ) ;
V_145 = F_152 ( V_145 , & V_36 , 1 ) ;
return F_152 ( V_145 , V_122 -> V_33 , V_122 -> V_119 ) ;
}
static inline void F_154 ( struct V_109 * V_122 )
{
V_122 -> V_33 [ V_122 -> V_119 ] = F_153 ( 0 , V_122 ) ;
V_122 -> V_119 ++ ;
}
static int F_155 ( T_7 V_146 , struct V_109 * V_122 )
{
T_7 V_147 = V_122 -> V_33 [ -- V_122 -> V_119 ] ;
V_146 = F_153 ( V_146 , V_122 ) ;
if ( V_147 != V_146 ) {
F_105 ( L_64 ,
V_147 , V_146 ) ;
return - V_148 ;
}
return 0 ;
}
T_8 F_156 ( const struct V_3 * V_4 )
{
union V_125 V_79 ;
int V_17 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_129 , 0 ,
V_135 , & V_79 ) ;
return ( V_17 < 0 ) ? V_17 : V_79 . V_149 ;
}
T_8 F_157 ( const struct V_3 * V_4 , T_7 V_150 )
{
return F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_150 , V_135 , NULL ) ;
}
T_8 F_158 ( const struct V_3 * V_4 , T_7 V_102 )
{
union V_125 V_79 ;
int V_17 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_129 , V_102 ,
V_130 , & V_79 ) ;
return ( V_17 < 0 ) ? V_17 : V_79 . V_149 ;
}
T_8 F_159 ( const struct V_3 * V_4 , T_7 V_102 ,
T_7 V_150 )
{
union V_125 V_79 ;
V_79 . V_149 = V_150 ;
return F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_102 ,
V_130 , & V_79 ) ;
}
T_8 F_160 ( const struct V_3 * V_4 , T_7 V_102 )
{
union V_125 V_79 ;
int V_17 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_129 , V_102 ,
V_151 , & V_79 ) ;
return ( V_17 < 0 ) ? V_17 : V_79 . V_152 ;
}
T_8 F_161 ( const struct V_3 * V_4 , T_7 V_102 ,
T_3 V_150 )
{
union V_125 V_79 ;
V_79 . V_152 = V_150 ;
return F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_102 ,
V_151 , & V_79 ) ;
}
T_8 F_162 ( const struct V_3 * V_4 , T_7 V_102 ,
T_3 V_150 )
{
union V_125 V_79 ;
int V_17 ;
V_79 . V_152 = V_150 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_102 ,
V_153 , & V_79 ) ;
return ( V_17 < 0 ) ? V_17 : V_79 . V_152 ;
}
T_8 F_163 ( const struct V_3 * V_4 , T_7 V_102 ,
T_7 * V_154 )
{
union V_125 V_79 ;
int V_17 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_129 , V_102 ,
V_155 , & V_79 ) ;
if ( V_17 )
return V_17 ;
memcpy ( V_154 , & V_79 . V_156 [ 1 ] , V_79 . V_156 [ 0 ] ) ;
return V_79 . V_156 [ 0 ] ;
}
T_8 F_164 ( const struct V_3 * V_4 , T_7 V_102 ,
T_7 V_157 , const T_7 * V_154 )
{
union V_125 V_79 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_79 . V_156 [ 0 ] = V_157 ;
memcpy ( & V_79 . V_156 [ 1 ] , V_154 , V_157 ) ;
return F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_102 ,
V_155 , & V_79 ) ;
}
T_8 F_165 ( const struct V_3 * V_4 , T_7 V_102 ,
T_7 V_157 , T_7 * V_154 )
{
union V_125 V_79 ;
int V_17 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_79 . V_156 [ 0 ] = V_157 ;
V_17 = F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_129 , V_102 ,
V_159 , & V_79 ) ;
if ( V_17 < 0 )
return V_17 ;
memcpy ( V_154 , & V_79 . V_156 [ 1 ] , V_79 . V_156 [ 0 ] ) ;
return V_79 . V_156 [ 0 ] ;
}
T_8 F_166 ( const struct V_3 * V_4 , T_7 V_102 ,
T_7 V_157 , const T_7 * V_154 )
{
union V_125 V_79 ;
if ( V_157 > V_158 )
V_157 = V_158 ;
V_79 . V_156 [ 0 ] = V_157 ;
memcpy ( V_79 . V_156 + 1 , V_154 , V_157 ) ;
return F_143 ( V_4 -> V_41 , V_4 -> V_36 , V_4 -> V_20 ,
V_132 , V_102 ,
V_159 , & V_79 ) ;
}
static T_8 F_167 ( struct V_40 * V_41 , T_3 V_36 ,
unsigned short V_20 ,
char V_160 , T_7 V_102 , int V_161 ,
union V_125 * V_79 )
{
unsigned char V_162 [ V_158 + 3 ] ;
unsigned char V_163 [ V_158 + 2 ] ;
int V_111 = V_160 == V_129 ? 2 : 1 ;
struct V_109 V_122 [ 2 ] = { { V_36 , V_20 , 1 , V_162 } ,
{ V_36 , V_20 | V_118 , 0 , V_163 }
} ;
int V_139 ;
T_7 V_164 = 0 ;
int V_17 ;
V_162 [ 0 ] = V_102 ;
switch ( V_161 ) {
case V_133 :
V_122 [ 0 ] . V_119 = 0 ;
V_122 [ 0 ] . V_20 = V_20 | ( V_160 == V_129 ?
V_118 : 0 ) ;
V_111 = 1 ;
break;
case V_135 :
if ( V_160 == V_129 ) {
V_122 [ 0 ] . V_20 = V_118 | V_20 ;
V_111 = 1 ;
}
break;
case V_130 :
if ( V_160 == V_129 )
V_122 [ 1 ] . V_119 = 1 ;
else {
V_122 [ 0 ] . V_119 = 2 ;
V_162 [ 1 ] = V_79 -> V_149 ;
}
break;
case V_151 :
if ( V_160 == V_129 )
V_122 [ 1 ] . V_119 = 2 ;
else {
V_122 [ 0 ] . V_119 = 3 ;
V_162 [ 1 ] = V_79 -> V_152 & 0xff ;
V_162 [ 2 ] = V_79 -> V_152 >> 8 ;
}
break;
case V_153 :
V_111 = 2 ;
V_160 = V_129 ;
V_122 [ 0 ] . V_119 = 3 ;
V_122 [ 1 ] . V_119 = 2 ;
V_162 [ 1 ] = V_79 -> V_152 & 0xff ;
V_162 [ 2 ] = V_79 -> V_152 >> 8 ;
break;
case V_155 :
if ( V_160 == V_129 ) {
V_122 [ 1 ] . V_20 |= V_120 ;
V_122 [ 1 ] . V_119 = 1 ;
} else {
V_122 [ 0 ] . V_119 = V_79 -> V_156 [ 0 ] + 2 ;
if ( V_122 [ 0 ] . V_119 > V_158 + 2 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_79 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
for ( V_139 = 1 ; V_139 < V_122 [ 0 ] . V_119 ; V_139 ++ )
V_162 [ V_139 ] = V_79 -> V_156 [ V_139 - 1 ] ;
}
break;
case V_165 :
V_111 = 2 ;
V_160 = V_129 ;
if ( V_79 -> V_156 [ 0 ] > V_158 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_79 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
V_122 [ 0 ] . V_119 = V_79 -> V_156 [ 0 ] + 2 ;
for ( V_139 = 1 ; V_139 < V_122 [ 0 ] . V_119 ; V_139 ++ )
V_162 [ V_139 ] = V_79 -> V_156 [ V_139 - 1 ] ;
V_122 [ 1 ] . V_20 |= V_120 ;
V_122 [ 1 ] . V_119 = 1 ;
break;
case V_159 :
if ( V_160 == V_129 ) {
V_122 [ 1 ] . V_119 = V_79 -> V_156 [ 0 ] ;
} else {
V_122 [ 0 ] . V_119 = V_79 -> V_156 [ 0 ] + 1 ;
if ( V_122 [ 0 ] . V_119 > V_158 + 1 ) {
F_52 ( & V_41 -> V_7 ,
L_65 ,
V_79 -> V_156 [ 0 ] ) ;
return - V_37 ;
}
for ( V_139 = 1 ; V_139 <= V_79 -> V_156 [ 0 ] ; V_139 ++ )
V_162 [ V_139 ] = V_79 -> V_156 [ V_139 ] ;
}
break;
default:
F_52 ( & V_41 -> V_7 , L_66 , V_161 ) ;
return - V_121 ;
}
V_139 = ( ( V_20 & V_166 ) && V_161 != V_133
&& V_161 != V_159 ) ;
if ( V_139 ) {
if ( ! ( V_122 [ 0 ] . V_20 & V_118 ) ) {
if ( V_111 == 1 )
F_154 ( & V_122 [ 0 ] ) ;
else
V_164 = F_153 ( 0 , & V_122 [ 0 ] ) ;
}
if ( V_122 [ V_111 - 1 ] . V_20 & V_118 )
V_122 [ V_111 - 1 ] . V_119 ++ ;
}
V_17 = F_134 ( V_41 , V_122 , V_111 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_139 && ( V_122 [ V_111 - 1 ] . V_20 & V_118 ) ) {
V_17 = F_155 ( V_164 , & V_122 [ V_111 - 1 ] ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_160 == V_129 )
switch ( V_161 ) {
case V_135 :
V_79 -> V_149 = V_162 [ 0 ] ;
break;
case V_130 :
V_79 -> V_149 = V_163 [ 0 ] ;
break;
case V_151 :
case V_153 :
V_79 -> V_152 = V_163 [ 0 ] | ( V_163 [ 1 ] << 8 ) ;
break;
case V_159 :
for ( V_139 = 0 ; V_139 < V_79 -> V_156 [ 0 ] ; V_139 ++ )
V_79 -> V_156 [ V_139 + 1 ] = V_163 [ V_139 ] ;
break;
case V_155 :
case V_165 :
for ( V_139 = 0 ; V_139 < V_163 [ 0 ] + 1 ; V_139 ++ )
V_79 -> V_156 [ V_139 ] = V_163 [ V_139 ] ;
break;
}
return 0 ;
}
T_8 F_143 ( struct V_40 * V_41 , T_3 V_36 , unsigned short V_20 ,
char V_160 , T_7 V_102 , int V_167 ,
union V_125 * V_79 )
{
unsigned long V_112 ;
int V_114 ;
T_8 V_64 ;
V_20 &= V_123 | V_166 | V_168 ;
if ( V_41 -> V_83 -> V_169 ) {
F_43 ( V_41 ) ;
V_112 = V_115 ;
for ( V_64 = 0 , V_114 = 0 ; V_114 <= V_41 -> V_116 ; V_114 ++ ) {
V_64 = V_41 -> V_83 -> V_169 ( V_41 , V_36 , V_20 ,
V_160 , V_102 ,
V_167 , V_79 ) ;
if ( V_64 != - V_81 )
break;
if ( F_133 ( V_115 ,
V_112 + V_41 -> V_84 ) )
break;
}
F_47 ( V_41 ) ;
if ( V_64 != - V_121 || ! V_41 -> V_83 -> V_117 )
return V_64 ;
}
return F_167 ( V_41 , V_36 , V_20 , V_160 ,
V_102 , V_167 , V_79 ) ;
}
