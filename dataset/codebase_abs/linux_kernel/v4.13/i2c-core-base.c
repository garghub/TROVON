int F_1 ( void )
{
F_2 ( & V_1 ) ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
const struct V_2 * F_5 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
if ( ! ( V_3 && V_5 ) )
return NULL ;
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
if ( F_8 ( V_10 -> V_13 , V_5 ) )
return 1 ;
if ( F_9 ( V_8 , V_10 ) )
return 1 ;
V_12 = F_10 ( V_10 ) ;
if ( F_5 ( V_12 -> V_14 , V_5 ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_15 * V_16 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
int V_17 ;
V_17 = F_13 ( V_8 , V_16 ) ;
if ( V_17 != - V_18 )
return V_17 ;
return F_14 ( V_16 , L_1 , V_19 , V_5 -> V_6 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
return F_16 ( V_21 -> V_22 -> V_23 ) ;
}
static void F_17 ( struct V_20 * V_21 , int V_24 )
{
F_18 ( V_21 -> V_22 -> V_23 , V_24 ) ;
}
static int F_19 ( struct V_20 * V_21 )
{
return F_16 ( V_21 -> V_22 -> V_25 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
struct V_7 * V_8 = & V_21 -> V_8 ;
int V_28 = 0 ;
V_28 = F_21 ( V_27 -> V_23 , V_29 |
V_30 , L_2 ) ;
if ( V_28 ) {
F_22 ( V_8 , L_3 , V_27 -> V_23 ) ;
return V_28 ;
}
if ( V_27 -> V_31 ) {
if ( F_21 ( V_27 -> V_25 , V_32 , L_4 ) ) {
F_22 ( V_8 , L_5 ,
V_27 -> V_25 ) ;
V_27 -> V_31 = NULL ;
}
}
return V_28 ;
}
static void F_23 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
if ( V_27 -> V_31 )
F_24 ( V_27 -> V_25 ) ;
F_24 ( V_27 -> V_23 ) ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
int V_33 = 0 , V_24 = 1 , V_28 = 0 ;
if ( V_27 -> V_34 )
V_27 -> V_34 ( V_21 ) ;
V_27 -> V_35 ( V_21 , V_24 ) ;
F_26 ( V_36 ) ;
while ( V_33 ++ < V_37 * 2 ) {
if ( V_24 ) {
if ( V_27 -> V_31 && V_27 -> V_31 ( V_21 ) )
break;
if ( ! V_27 -> V_38 ( V_21 ) ) {
F_27 ( & V_21 -> V_8 ,
L_6 ) ;
V_28 = - V_39 ;
break;
}
}
V_24 = ! V_24 ;
V_27 -> V_35 ( V_21 , V_24 ) ;
F_26 ( V_36 ) ;
}
if ( V_27 -> V_40 )
V_27 -> V_40 ( V_21 ) ;
return V_28 ;
}
int F_28 ( struct V_20 * V_21 )
{
return F_25 ( V_21 ) ;
}
int F_29 ( struct V_20 * V_21 )
{
int V_28 ;
V_28 = F_20 ( V_21 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_25 ( V_21 ) ;
F_23 ( V_21 ) ;
return V_28 ;
}
int F_30 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_22 )
return - V_41 ;
F_31 ( & V_21 -> V_8 , L_7 ) ;
return V_21 -> V_22 -> V_42 ( V_21 ) ;
}
static void F_32 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_22 ;
char * V_43 ;
if ( ! V_27 )
return;
if ( ! V_27 -> V_42 ) {
V_43 = L_8 ;
goto V_44;
}
if ( V_27 -> V_42 == F_29 ) {
if ( ! F_33 ( V_27 -> V_23 ) ) {
V_43 = L_9 ;
goto V_44;
}
if ( F_33 ( V_27 -> V_25 ) )
V_27 -> V_31 = F_19 ;
else
V_27 -> V_31 = NULL ;
V_27 -> V_38 = F_15 ;
V_27 -> V_35 = F_17 ;
} else if ( V_27 -> V_42 == F_28 ) {
if ( ! V_27 -> V_35 || ! V_27 -> V_38 ) {
V_43 = L_10 ;
goto V_44;
}
}
return;
V_44:
F_27 ( & V_21 -> V_8 , L_11 , V_43 ) ;
V_21 -> V_22 = NULL ;
}
static int F_34 ( const struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_45 ;
unsigned int V_46 ;
if ( ! V_21 -> V_47 )
return - V_48 ;
if ( V_5 -> V_49 & V_50 )
return - V_51 ;
V_46 = F_35 ( V_21 -> V_47 , V_5 -> V_52 ) ;
if ( ! V_46 )
V_46 = F_36 ( V_21 -> V_47 ,
V_5 -> V_52 ) ;
return V_46 > 0 ? V_46 : - V_48 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
int V_53 ;
if ( ! V_5 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( ! V_5 -> V_46 && ! V_12 -> V_54 ) {
int V_46 = - V_55 ;
if ( V_5 -> V_49 & V_56 ) {
F_31 ( V_8 , L_12 ) ;
V_46 = F_34 ( V_5 ) ;
} else if ( V_8 -> V_57 ) {
V_46 = F_38 ( V_8 -> V_57 , L_13 ) ;
if ( V_46 == - V_51 || V_46 == - V_58 )
V_46 = F_39 ( V_8 -> V_57 , 0 ) ;
} else if ( F_40 ( V_8 ) ) {
V_46 = F_41 ( F_40 ( V_8 ) , 0 ) ;
}
if ( V_46 == - V_59 )
return V_46 ;
if ( V_46 < 0 )
V_46 = 0 ;
V_5 -> V_46 = V_46 ;
}
if ( ! V_12 -> V_14 &&
! F_42 ( V_8 -> V_12 -> V_60 , V_5 ) &&
! F_8 ( V_8 -> V_12 -> V_13 , V_5 ) )
return - V_18 ;
if ( V_5 -> V_49 & V_61 ) {
int V_62 = - V_55 ;
if ( V_8 -> V_57 ) {
V_62 = F_38 ( V_8 -> V_57 , L_14 ) ;
if ( V_62 == - V_59 )
return V_62 ;
}
F_43 ( & V_5 -> V_8 , true ) ;
if ( V_62 > 0 && V_62 != V_5 -> V_46 )
V_53 = F_44 ( V_8 , V_62 ) ;
else if ( V_5 -> V_46 > 0 )
V_53 = F_45 ( V_8 , V_5 -> V_46 ) ;
else
V_53 = 0 ;
if ( V_53 )
F_22 ( & V_5 -> V_8 , L_15 ) ;
}
F_31 ( V_8 , L_16 ) ;
V_53 = F_46 ( V_8 -> V_57 , false ) ;
if ( V_53 < 0 )
goto V_63;
V_53 = F_47 ( & V_5 -> V_8 , true ) ;
if ( V_53 == - V_59 )
goto V_63;
if ( V_12 -> V_64 )
V_53 = V_12 -> V_64 ( V_5 ) ;
else if ( V_12 -> V_65 )
V_53 = V_12 -> V_65 ( V_5 ,
F_5 ( V_12 -> V_14 , V_5 ) ) ;
else
V_53 = - V_51 ;
if ( V_53 )
goto V_66;
return 0 ;
V_66:
F_48 ( & V_5 -> V_8 , true ) ;
V_63:
F_49 ( & V_5 -> V_8 ) ;
F_43 ( & V_5 -> V_8 , false ) ;
return V_53 ;
}
static int F_50 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
int V_53 = 0 ;
if ( ! V_5 || ! V_8 -> V_12 )
return 0 ;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( V_12 -> remove ) {
F_31 ( V_8 , L_17 ) ;
V_53 = V_12 -> remove ( V_5 ) ;
}
F_48 ( & V_5 -> V_8 , true ) ;
F_49 ( & V_5 -> V_8 ) ;
F_43 ( & V_5 -> V_8 , false ) ;
return V_53 ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_8 -> V_12 )
return;
V_12 = F_10 ( V_8 -> V_12 ) ;
if ( V_12 -> V_67 )
V_12 -> V_67 ( V_5 ) ;
}
static void F_52 ( struct V_7 * V_8 )
{
F_53 ( F_12 ( V_8 ) ) ;
}
static T_1
F_54 ( struct V_7 * V_8 , struct V_68 * V_69 , char * V_70 )
{
return sprintf ( V_70 , L_18 , V_8 -> type == & V_71 ?
F_12 ( V_8 ) -> V_6 : F_55 ( V_8 ) -> V_6 ) ;
}
static T_1
F_56 ( struct V_7 * V_8 , struct V_68 * V_69 , char * V_70 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
int V_72 ;
V_72 = F_57 ( V_8 , V_70 , V_73 - 1 ) ;
if ( V_72 != - V_18 )
return V_72 ;
return sprintf ( V_70 , L_19 , V_19 , V_5 -> V_6 ) ;
}
struct V_4 * F_7 ( struct V_7 * V_8 )
{
return ( V_8 -> type == & V_71 )
? F_12 ( V_8 )
: NULL ;
}
static unsigned short F_58 ( struct V_4 * V_5 )
{
unsigned short V_52 = V_5 -> V_52 ;
if ( V_5 -> V_49 & V_50 )
V_52 |= V_74 ;
if ( V_5 -> V_49 & V_75 )
V_52 |= V_76 ;
return V_52 ;
}
int F_59 ( unsigned V_52 , unsigned short V_49 )
{
if ( V_49 & V_50 ) {
if ( V_52 > 0x3ff )
return - V_51 ;
} else {
if ( V_52 == 0x00 || V_52 > 0x7f )
return - V_51 ;
}
return 0 ;
}
int F_60 ( unsigned short V_52 )
{
if ( V_52 < 0x08 || V_52 > 0x77 )
return - V_51 ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , void * V_77 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
int V_52 = * ( int * ) V_77 ;
if ( V_5 && F_58 ( V_5 ) == V_52 )
return - V_39 ;
return 0 ;
}
static int F_62 ( struct V_20 * V_45 , int V_52 )
{
struct V_20 * V_78 = F_63 ( V_45 ) ;
int V_79 ;
V_79 = F_64 ( & V_45 -> V_8 , & V_52 ,
F_61 ) ;
if ( ! V_79 && V_78 )
V_79 = F_62 ( V_78 , V_52 ) ;
return V_79 ;
}
static int F_65 ( struct V_7 * V_8 , void * V_77 )
{
int V_79 ;
if ( V_8 -> type == & V_80 )
V_79 = F_64 ( V_8 , V_77 ,
F_65 ) ;
else
V_79 = F_61 ( V_8 , V_77 ) ;
return V_79 ;
}
static int F_66 ( struct V_20 * V_45 , int V_52 )
{
struct V_20 * V_78 = F_63 ( V_45 ) ;
int V_79 = 0 ;
if ( V_78 )
V_79 = F_62 ( V_78 , V_52 ) ;
if ( ! V_79 )
V_79 = F_64 ( & V_45 -> V_8 , & V_52 ,
F_65 ) ;
return V_79 ;
}
static void F_67 ( struct V_20 * V_45 ,
unsigned int V_49 )
{
F_68 ( & V_45 -> V_81 ) ;
}
static int F_69 ( struct V_20 * V_45 ,
unsigned int V_49 )
{
return F_70 ( & V_45 -> V_81 ) ;
}
static void F_71 ( struct V_20 * V_45 ,
unsigned int V_49 )
{
F_72 ( & V_45 -> V_81 ) ;
}
static void F_73 ( struct V_20 * V_21 ,
struct V_4 * V_5 )
{
struct V_82 * V_83 = F_40 ( & V_5 -> V_8 ) ;
if ( V_83 ) {
F_74 ( & V_5 -> V_8 , L_20 , F_75 ( V_83 ) ) ;
return;
}
F_74 ( & V_5 -> V_8 , L_21 , F_76 ( V_21 ) ,
F_58 ( V_5 ) ) ;
}
static int F_77 ( const struct V_84 * V_85 ,
unsigned int V_86 )
{
struct V_87 * V_88 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
const struct V_84 * V_89 = & V_85 [ V_33 ] ;
if ( F_78 ( V_89 ) != V_90 )
continue;
if ( V_89 -> V_49 & V_91 ) {
V_88 = F_79 ( V_89 -> V_92 ) ;
if ( ! V_88 )
break;
F_80 ( V_88 , V_89 -> V_49 & V_91 ) ;
}
return V_89 -> V_92 ;
}
return 0 ;
}
struct V_4 *
F_81 ( struct V_20 * V_21 , struct V_93 const * V_94 )
{
struct V_4 * V_5 ;
int V_53 ;
V_5 = F_82 ( sizeof *V_5 , V_95 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_45 = V_21 ;
V_5 -> V_8 . V_96 = V_94 -> V_96 ;
if ( V_94 -> V_97 )
V_5 -> V_8 . V_97 = * V_94 -> V_97 ;
V_5 -> V_49 = V_94 -> V_49 ;
V_5 -> V_52 = V_94 -> V_52 ;
V_5 -> V_46 = V_94 -> V_46 ;
if ( ! V_5 -> V_46 )
V_5 -> V_46 = F_77 ( V_94 -> V_85 ,
V_94 -> V_86 ) ;
F_83 ( V_5 -> V_6 , V_94 -> type , sizeof( V_5 -> V_6 ) ) ;
V_53 = F_59 ( V_5 -> V_52 , V_5 -> V_49 ) ;
if ( V_53 ) {
F_27 ( & V_21 -> V_8 , L_22 ,
V_5 -> V_49 & V_50 ? 10 : 7 , V_5 -> V_52 ) ;
goto V_98;
}
V_53 = F_66 ( V_21 , F_58 ( V_5 ) ) ;
if ( V_53 )
goto V_99;
V_5 -> V_8 . V_78 = & V_5 -> V_45 -> V_8 ;
V_5 -> V_8 . V_100 = & V_101 ;
V_5 -> V_8 . type = & V_71 ;
V_5 -> V_8 . V_57 = V_94 -> V_57 ;
V_5 -> V_8 . V_102 = V_94 -> V_102 ;
F_73 ( V_21 , V_5 ) ;
if ( V_94 -> V_103 ) {
V_53 = F_84 ( & V_5 -> V_8 , V_94 -> V_103 ) ;
if ( V_53 ) {
F_27 ( & V_21 -> V_8 ,
L_23 ,
V_5 -> V_6 , V_53 ) ;
goto V_99;
}
}
V_53 = F_85 ( & V_5 -> V_8 ) ;
if ( V_53 )
goto V_104;
F_31 ( & V_21 -> V_8 , L_24 ,
V_5 -> V_6 , F_86 ( & V_5 -> V_8 ) ) ;
return V_5 ;
V_104:
if ( V_94 -> V_103 )
F_87 ( & V_5 -> V_8 ) ;
V_99:
F_27 ( & V_21 -> V_8 ,
L_25 ,
V_5 -> V_6 , V_5 -> V_52 , V_53 ) ;
V_98:
F_53 ( V_5 ) ;
return NULL ;
}
void F_88 ( struct V_4 * V_5 )
{
if ( V_5 -> V_8 . V_57 )
F_89 ( V_5 -> V_8 . V_57 , V_105 ) ;
if ( F_40 ( & V_5 -> V_8 ) )
F_90 ( F_40 ( & V_5 -> V_8 ) ) ;
F_91 ( & V_5 -> V_8 ) ;
}
static int F_92 ( struct V_4 * V_5 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static int F_93 ( struct V_4 * V_5 )
{
return 0 ;
}
struct V_4 * F_94 ( struct V_20 * V_45 , T_2 V_106 )
{
struct V_93 V_94 = {
F_95 ( L_26 , V_106 ) ,
} ;
return F_81 ( V_45 , & V_94 ) ;
}
struct V_4 * F_96 ( struct V_4 * V_5 ,
const char * V_6 ,
T_2 V_107 )
{
struct V_108 * V_109 = V_5 -> V_8 . V_57 ;
T_3 V_52 = V_107 ;
int V_33 ;
if ( V_109 ) {
V_33 = F_97 ( V_109 , L_27 , V_6 ) ;
if ( V_33 >= 0 )
F_98 ( V_109 , L_28 , V_33 , & V_52 ) ;
}
F_31 ( & V_5 -> V_45 -> V_8 , L_29 , V_6 , V_52 ) ;
return F_94 ( V_5 -> V_45 , V_52 ) ;
}
static void F_99 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = F_55 ( V_8 ) ;
F_100 ( & V_21 -> V_110 ) ;
}
unsigned int F_101 ( struct V_20 * V_45 )
{
unsigned int V_111 = 0 ;
while ( ( V_45 = F_63 ( V_45 ) ) )
V_111 ++ ;
F_102 ( V_111 >= V_112 ,
L_30 ) ;
return V_111 ;
}
static T_1
F_103 ( struct V_7 * V_8 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_113 )
{
struct V_20 * V_21 = F_55 ( V_8 ) ;
struct V_93 V_94 ;
struct V_4 * V_5 ;
char * V_114 , V_115 ;
int V_116 ;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
V_114 = strchr ( V_70 , ' ' ) ;
if ( ! V_114 ) {
F_27 ( V_8 , L_31 , L_32 ) ;
return - V_51 ;
}
if ( V_114 - V_70 > V_117 - 1 ) {
F_27 ( V_8 , L_33 , L_32 ) ;
return - V_51 ;
}
memcpy ( V_94 . type , V_70 , V_114 - V_70 ) ;
V_116 = sscanf ( ++ V_114 , L_34 , & V_94 . V_52 , & V_115 ) ;
if ( V_116 < 1 ) {
F_27 ( V_8 , L_35 , L_32 ) ;
return - V_51 ;
}
if ( V_116 > 1 && V_115 != '\n' ) {
F_27 ( V_8 , L_36 , L_32 ) ;
return - V_51 ;
}
if ( ( V_94 . V_52 & V_74 ) == V_74 ) {
V_94 . V_52 &= ~ V_74 ;
V_94 . V_49 |= V_50 ;
}
if ( V_94 . V_52 & V_76 ) {
V_94 . V_52 &= ~ V_76 ;
V_94 . V_49 |= V_75 ;
}
V_5 = F_81 ( V_21 , & V_94 ) ;
if ( ! V_5 )
return - V_51 ;
F_104 ( & V_21 -> V_118 ) ;
F_105 ( & V_5 -> V_119 , & V_21 -> V_120 ) ;
F_106 ( & V_21 -> V_118 ) ;
F_107 ( V_8 , L_37 , L_32 ,
V_94 . type , V_94 . V_52 ) ;
return V_113 ;
}
static T_1
F_108 ( struct V_7 * V_8 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_113 )
{
struct V_20 * V_21 = F_55 ( V_8 ) ;
struct V_4 * V_5 , * V_121 ;
unsigned short V_52 ;
char V_115 ;
int V_116 ;
V_116 = sscanf ( V_70 , L_34 , & V_52 , & V_115 ) ;
if ( V_116 < 1 ) {
F_27 ( V_8 , L_35 , L_38 ) ;
return - V_51 ;
}
if ( V_116 > 1 && V_115 != '\n' ) {
F_27 ( V_8 , L_36 , L_38 ) ;
return - V_51 ;
}
V_116 = - V_55 ;
F_109 ( & V_21 -> V_118 ,
F_101 ( V_21 ) ) ;
F_110 (client, next, &adap->userspace_clients,
detected) {
if ( F_58 ( V_5 ) == V_52 ) {
F_107 ( V_8 , L_39 ,
L_38 , V_5 -> V_6 , V_5 -> V_52 ) ;
F_111 ( & V_5 -> V_119 ) ;
F_88 ( V_5 ) ;
V_116 = V_113 ;
break;
}
}
F_106 ( & V_21 -> V_118 ) ;
if ( V_116 < 0 )
F_27 ( V_8 , L_40 ,
L_38 ) ;
return V_116 ;
}
struct V_20 * F_112 ( struct V_7 * V_8 )
{
return ( V_8 -> type == & V_80 )
? F_55 ( V_8 )
: NULL ;
}
static void F_113 ( struct V_20 * V_45 )
{
struct V_122 * V_123 ;
F_114 ( & V_124 ) ;
F_115 (devinfo, &__i2c_board_list, list) {
if ( V_123 -> V_125 == V_45 -> V_126
&& ! F_81 ( V_45 ,
& V_123 -> V_127 ) )
F_27 ( & V_45 -> V_8 ,
L_41 ,
V_123 -> V_127 . V_52 ) ;
}
F_116 ( & V_124 ) ;
}
static int F_117 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
F_118 ( V_21 , V_12 ) ;
if ( V_12 -> V_128 ) {
F_22 ( & V_21 -> V_8 , L_42 ,
V_12 -> V_12 . V_6 ) ;
F_22 ( & V_21 -> V_8 ,
L_43 ) ;
V_12 -> V_128 ( V_21 ) ;
}
return 0 ;
}
static int F_119 ( struct V_9 * V_129 , void * V_130 )
{
return F_117 ( F_10 ( V_129 ) , V_130 ) ;
}
static void F_120 ( struct V_20 * V_21 )
{
struct V_131 * V_132 = V_21 -> V_47 ;
T_5 V_133 ;
if ( ! V_132 )
return;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ )
F_121 ( F_35 ( V_132 , V_133 ) ) ;
F_122 ( V_132 ) ;
V_21 -> V_47 = NULL ;
}
static int F_123 ( struct V_131 * V_135 ,
unsigned int V_136 ,
T_5 V_137 )
{
F_124 ( V_136 , & V_138 , V_139 ) ;
return 0 ;
}
static int F_125 ( struct V_20 * V_21 )
{
struct V_131 * V_132 ;
if ( ! F_126 ( V_21 , V_140 ) )
return 0 ;
V_132 = F_127 ( V_21 -> V_8 . V_102 ,
V_134 ,
& V_141 , V_21 ) ;
if ( ! V_132 )
return - V_142 ;
V_21 -> V_47 = V_132 ;
return 0 ;
}
int F_128 ( struct V_20 * V_21 , unsigned short V_52 )
{
int V_46 ;
if ( ! V_21 )
return - V_51 ;
V_46 = F_35 ( V_21 -> V_47 , V_52 ) ;
if ( V_46 <= 0 )
return - V_48 ;
F_129 ( V_46 ) ;
return 0 ;
}
static int F_130 ( struct V_20 * V_21 )
{
int V_116 = - V_51 ;
if ( F_131 ( ! V_143 ) ) {
V_116 = - V_144 ;
goto V_145;
}
if ( F_132 ( ! V_21 -> V_6 [ 0 ] , L_44 ) )
goto V_145;
if ( ! V_21 -> V_146 ) {
F_133 ( L_45 , V_21 -> V_6 ) ;
goto V_145;
}
if ( ! V_21 -> V_147 )
V_21 -> V_147 = & V_148 ;
F_134 ( & V_21 -> V_81 ) ;
F_134 ( & V_21 -> V_149 ) ;
F_135 ( & V_21 -> V_118 ) ;
F_136 ( & V_21 -> V_120 ) ;
if ( V_21 -> V_150 == 0 )
V_21 -> V_150 = V_151 ;
V_116 = F_125 ( V_21 ) ;
if ( V_116 ) {
F_133 ( L_46 ,
V_21 -> V_6 , V_116 ) ;
goto V_145;
}
F_74 ( & V_21 -> V_8 , L_47 , V_21 -> V_126 ) ;
V_21 -> V_8 . V_100 = & V_101 ;
V_21 -> V_8 . type = & V_80 ;
V_116 = F_85 ( & V_21 -> V_8 ) ;
if ( V_116 ) {
F_133 ( L_48 , V_21 -> V_6 , V_116 ) ;
goto V_145;
}
F_31 ( & V_21 -> V_8 , L_49 , V_21 -> V_6 ) ;
F_137 ( & V_21 -> V_8 ) ;
F_138 ( & V_21 -> V_8 , true ) ;
F_139 ( & V_21 -> V_8 ) ;
#ifdef F_140
V_116 = F_141 ( V_152 , & V_21 -> V_8 ,
V_21 -> V_8 . V_78 ) ;
if ( V_116 )
F_22 ( & V_21 -> V_8 ,
L_50 ) ;
#endif
F_32 ( V_21 ) ;
F_142 ( V_21 ) ;
F_143 ( V_21 ) ;
F_144 ( V_21 ) ;
if ( V_21 -> V_126 < V_153 )
F_113 ( V_21 ) ;
F_104 ( & V_154 ) ;
F_145 ( & V_101 , NULL , V_21 , F_119 ) ;
F_106 ( & V_154 ) ;
return 0 ;
V_145:
F_104 ( & V_154 ) ;
F_146 ( & V_155 , V_21 -> V_126 ) ;
F_106 ( & V_154 ) ;
return V_116 ;
}
static int F_147 ( struct V_20 * V_21 )
{
int V_3 ;
F_104 ( & V_154 ) ;
V_3 = F_148 ( & V_155 , V_21 , V_21 -> V_126 , V_21 -> V_126 + 1 , V_95 ) ;
F_106 ( & V_154 ) ;
if ( F_132 ( V_3 < 0 , L_51 ) )
return V_3 == - V_156 ? - V_39 : V_3 ;
return F_130 ( V_21 ) ;
}
int F_149 ( struct V_20 * V_45 )
{
struct V_7 * V_8 = & V_45 -> V_8 ;
int V_3 ;
if ( V_8 -> V_57 ) {
V_3 = F_150 ( V_8 -> V_57 , L_52 ) ;
if ( V_3 >= 0 ) {
V_45 -> V_126 = V_3 ;
return F_147 ( V_45 ) ;
}
}
F_104 ( & V_154 ) ;
V_3 = F_148 ( & V_155 , V_45 ,
V_153 , 0 , V_95 ) ;
F_106 ( & V_154 ) ;
if ( F_132 ( V_3 < 0 , L_51 ) )
return V_3 ;
V_45 -> V_126 = V_3 ;
return F_130 ( V_45 ) ;
}
int F_151 ( struct V_20 * V_21 )
{
if ( V_21 -> V_126 == - 1 )
return F_149 ( V_21 ) ;
return F_147 ( V_21 ) ;
}
static void F_152 ( struct V_11 * V_12 ,
struct V_20 * V_45 )
{
struct V_4 * V_5 , * V_157 ;
F_110 (client, _n, &driver->clients, detected) {
if ( V_5 -> V_45 == V_45 ) {
F_31 ( & V_45 -> V_8 , L_53 ,
V_5 -> V_6 , V_5 -> V_52 ) ;
F_111 ( & V_5 -> V_119 ) ;
F_88 ( V_5 ) ;
}
}
}
static int F_153 ( struct V_7 * V_8 , void * V_158 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
if ( V_5 && strcmp ( V_5 -> V_6 , L_26 ) )
F_88 ( V_5 ) ;
return 0 ;
}
static int F_154 ( struct V_7 * V_8 , void * V_158 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
if ( V_5 )
F_88 ( V_5 ) ;
return 0 ;
}
static int F_155 ( struct V_9 * V_129 , void * V_130 )
{
F_152 ( F_10 ( V_129 ) , V_130 ) ;
return 0 ;
}
void F_156 ( struct V_20 * V_21 )
{
struct V_20 * V_159 ;
struct V_4 * V_5 , * V_121 ;
F_104 ( & V_154 ) ;
V_159 = F_157 ( & V_155 , V_21 -> V_126 ) ;
F_106 ( & V_154 ) ;
if ( V_159 != V_21 ) {
F_158 ( L_54 , V_21 -> V_6 ) ;
return;
}
F_159 ( V_21 ) ;
F_104 ( & V_154 ) ;
F_145 ( & V_101 , NULL , V_21 ,
F_155 ) ;
F_106 ( & V_154 ) ;
F_109 ( & V_21 -> V_118 ,
F_101 ( V_21 ) ) ;
F_110 (client, next, &adap->userspace_clients,
detected) {
F_31 ( & V_21 -> V_8 , L_53 , V_5 -> V_6 ,
V_5 -> V_52 ) ;
F_111 ( & V_5 -> V_119 ) ;
F_88 ( V_5 ) ;
}
F_106 ( & V_21 -> V_118 ) ;
F_64 ( & V_21 -> V_8 , NULL , F_153 ) ;
F_64 ( & V_21 -> V_8 , NULL , F_154 ) ;
#ifdef F_140
F_160 ( V_152 , & V_21 -> V_8 ,
V_21 -> V_8 . V_78 ) ;
#endif
F_31 ( & V_21 -> V_8 , L_55 , V_21 -> V_6 ) ;
F_161 ( & V_21 -> V_8 ) ;
F_120 ( V_21 ) ;
F_162 ( & V_21 -> V_110 ) ;
F_91 ( & V_21 -> V_8 ) ;
F_163 ( & V_21 -> V_110 ) ;
F_104 ( & V_154 ) ;
F_146 ( & V_155 , V_21 -> V_126 ) ;
F_106 ( & V_154 ) ;
memset ( & V_21 -> V_8 , 0 , sizeof( V_21 -> V_8 ) ) ;
}
void F_164 ( struct V_7 * V_8 , struct V_160 * V_161 , bool V_162 )
{
int V_28 ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_28 = F_165 ( V_8 , L_56 , & V_161 -> V_163 ) ;
if ( V_28 && V_162 )
V_161 -> V_163 = 100000 ;
V_28 = F_165 ( V_8 , L_57 , & V_161 -> V_164 ) ;
if ( V_28 && V_162 ) {
if ( V_161 -> V_163 <= 100000 )
V_161 -> V_164 = 1000 ;
else if ( V_161 -> V_163 <= 400000 )
V_161 -> V_164 = 300 ;
else
V_161 -> V_164 = 120 ;
}
V_28 = F_165 ( V_8 , L_58 , & V_161 -> V_165 ) ;
if ( V_28 && V_162 ) {
if ( V_161 -> V_163 <= 400000 )
V_161 -> V_165 = 300 ;
else
V_161 -> V_165 = 120 ;
}
F_165 ( V_8 , L_59 , & V_161 -> V_166 ) ;
V_28 = F_165 ( V_8 , L_60 , & V_161 -> V_167 ) ;
if ( V_28 && V_162 )
V_161 -> V_167 = V_161 -> V_165 ;
}
int F_166 ( void * V_130 , int (* F_167)( struct V_7 * , void * ) )
{
int V_116 ;
F_104 ( & V_154 ) ;
V_116 = F_168 ( & V_101 , NULL , V_130 , F_167 ) ;
F_106 ( & V_154 ) ;
return V_116 ;
}
static int F_169 ( struct V_7 * V_8 , void * V_130 )
{
if ( V_8 -> type != & V_80 )
return 0 ;
return F_117 ( V_130 , F_55 ( V_8 ) ) ;
}
int F_170 ( struct V_168 * V_169 , struct V_11 * V_12 )
{
int V_116 ;
if ( F_131 ( ! V_143 ) )
return - V_144 ;
V_12 -> V_12 . V_169 = V_169 ;
V_12 -> V_12 . V_100 = & V_101 ;
F_136 ( & V_12 -> V_170 ) ;
V_116 = F_171 ( & V_12 -> V_12 ) ;
if ( V_116 )
return V_116 ;
F_158 ( L_61 , V_12 -> V_12 . V_6 ) ;
F_166 ( V_12 , F_169 ) ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , void * V_130 )
{
if ( V_8 -> type == & V_80 )
F_152 ( V_130 , F_55 ( V_8 ) ) ;
return 0 ;
}
void F_173 ( struct V_11 * V_12 )
{
F_166 ( V_12 , F_172 ) ;
F_174 ( & V_12 -> V_12 ) ;
F_158 ( L_62 , V_12 -> V_12 . V_6 ) ;
}
struct V_4 * F_175 ( struct V_4 * V_5 )
{
if ( V_5 && F_176 ( & V_5 -> V_8 ) )
return V_5 ;
return NULL ;
}
void F_177 ( struct V_4 * V_5 )
{
if ( V_5 )
F_178 ( & V_5 -> V_8 ) ;
}
static int F_179 ( struct V_7 * V_8 , void * V_171 )
{
struct V_4 * V_5 = F_7 ( V_8 ) ;
struct V_172 * V_173 = V_171 ;
struct V_11 * V_12 ;
if ( ! V_5 || ! V_5 -> V_8 . V_12 )
return 0 ;
V_12 = F_10 ( V_5 -> V_8 . V_12 ) ;
if ( V_12 -> V_174 )
V_12 -> V_174 ( V_5 , V_173 -> V_175 , V_173 -> V_173 ) ;
return 0 ;
}
void F_180 ( struct V_20 * V_21 , unsigned int V_175 , void * V_173 )
{
struct V_172 V_176 ;
V_176 . V_175 = V_175 ;
V_176 . V_173 = V_173 ;
F_64 ( & V_21 -> V_8 , & V_176 , F_179 ) ;
}
static int T_6 F_181 ( void )
{
int V_177 ;
V_177 = F_182 ( L_52 ) ;
F_183 ( & V_124 ) ;
if ( V_177 >= V_153 )
V_153 = V_177 + 1 ;
F_184 ( & V_124 ) ;
V_177 = F_185 ( & V_101 ) ;
if ( V_177 )
return V_177 ;
V_143 = true ;
#ifdef F_140
V_152 = F_186 ( L_63 ) ;
if ( ! V_152 ) {
V_177 = - V_142 ;
goto V_178;
}
#endif
V_177 = F_187 ( & V_179 ) ;
if ( V_177 )
goto V_180;
if ( F_188 ( V_181 ) )
F_131 ( F_189 ( & V_182 ) ) ;
if ( F_188 ( V_183 ) )
F_131 ( F_190 ( & V_184 ) ) ;
return 0 ;
V_180:
#ifdef F_140
F_191 ( V_152 ) ;
V_178:
#endif
V_143 = false ;
F_192 ( & V_101 ) ;
return V_177 ;
}
static void T_7 F_193 ( void )
{
if ( F_188 ( V_183 ) )
F_131 ( F_194 ( & V_184 ) ) ;
if ( F_188 ( V_181 ) )
F_131 ( F_195 ( & V_182 ) ) ;
F_173 ( & V_179 ) ;
#ifdef F_140
F_191 ( V_152 ) ;
#endif
F_192 ( & V_101 ) ;
F_196 () ;
}
static int F_197 ( struct V_20 * V_21 , struct V_185 * V_186 , char * V_187 )
{
F_198 ( & V_21 -> V_8 , L_64 ,
V_187 , V_186 -> V_52 , V_186 -> V_72 ,
V_186 -> V_49 & V_188 ? L_65 : L_66 ) ;
return - V_41 ;
}
static int F_199 ( struct V_20 * V_21 , struct V_185 * V_189 , int V_190 )
{
const struct V_191 * V_192 = V_21 -> V_193 ;
int V_194 = V_192 -> V_195 , V_33 ;
bool V_196 = true ;
if ( V_192 -> V_49 & V_197 ) {
V_194 = 2 ;
if ( V_190 == 2 ) {
if ( V_192 -> V_49 & V_198 && V_189 [ 0 ] . V_49 & V_188 )
return F_197 ( V_21 , & V_189 [ 0 ] , L_67 ) ;
if ( V_192 -> V_49 & V_199 && ! ( V_189 [ 1 ] . V_49 & V_188 ) )
return F_197 ( V_21 , & V_189 [ 1 ] , L_68 ) ;
if ( V_192 -> V_49 & V_200 && V_189 [ 0 ] . V_52 != V_189 [ 1 ] . V_52 )
return F_197 ( V_21 , & V_189 [ 0 ] , L_69 ) ;
if ( F_200 ( V_189 [ 0 ] . V_72 , V_192 -> V_201 ) )
return F_197 ( V_21 , & V_189 [ 0 ] , L_70 ) ;
if ( F_200 ( V_189 [ 1 ] . V_72 , V_192 -> V_202 ) )
return F_197 ( V_21 , & V_189 [ 1 ] , L_70 ) ;
V_196 = false ;
}
}
if ( F_200 ( V_190 , V_194 ) )
return F_197 ( V_21 , & V_189 [ 0 ] , L_71 ) ;
for ( V_33 = 0 ; V_33 < V_190 ; V_33 ++ ) {
T_2 V_72 = V_189 [ V_33 ] . V_72 ;
if ( V_189 [ V_33 ] . V_49 & V_188 ) {
if ( V_196 && F_200 ( V_72 , V_192 -> V_203 ) )
return F_197 ( V_21 , & V_189 [ V_33 ] , L_70 ) ;
} else {
if ( V_196 && F_200 ( V_72 , V_192 -> V_204 ) )
return F_197 ( V_21 , & V_189 [ V_33 ] , L_70 ) ;
}
}
return 0 ;
}
int F_201 ( struct V_20 * V_21 , struct V_185 * V_189 , int V_190 )
{
unsigned long V_205 ;
int V_28 , V_206 ;
if ( V_21 -> V_193 && F_199 ( V_21 , V_189 , V_190 ) )
return - V_41 ;
if ( F_202 ( & V_1 ) ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_190 ; V_33 ++ )
if ( V_189 [ V_33 ] . V_49 & V_188 )
F_203 ( V_21 , & V_189 [ V_33 ] , V_33 ) ;
else
F_204 ( V_21 , & V_189 [ V_33 ] , V_33 ) ;
}
V_205 = V_207 ;
for ( V_28 = 0 , V_206 = 0 ; V_206 <= V_21 -> V_208 ; V_206 ++ ) {
V_28 = V_21 -> V_146 -> V_209 ( V_21 , V_189 , V_190 ) ;
if ( V_28 != - V_144 )
break;
if ( F_205 ( V_207 , V_205 + V_21 -> V_150 ) )
break;
}
if ( F_202 ( & V_1 ) ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_28 ; V_33 ++ )
if ( V_189 [ V_33 ] . V_49 & V_188 )
F_206 ( V_21 , & V_189 [ V_33 ] , V_33 ) ;
F_207 ( V_21 , V_33 , V_28 ) ;
}
return V_28 ;
}
int F_208 ( struct V_20 * V_21 , struct V_185 * V_189 , int V_190 )
{
int V_28 ;
if ( V_21 -> V_146 -> V_209 ) {
#ifdef F_209
for ( V_28 = 0 ; V_28 < V_190 ; V_28 ++ ) {
F_31 ( & V_21 -> V_8 ,
L_72 ,
V_28 , ( V_189 [ V_28 ] . V_49 & V_188 ) ? 'R' : 'W' ,
V_189 [ V_28 ] . V_52 , V_189 [ V_28 ] . V_72 ,
( V_189 [ V_28 ] . V_49 & V_210 ) ? L_73 : L_74 ) ;
}
#endif
if ( F_210 () || F_211 () ) {
V_28 = F_212 ( V_21 , V_211 ) ;
if ( ! V_28 )
return - V_144 ;
} else {
F_213 ( V_21 , V_211 ) ;
}
V_28 = F_201 ( V_21 , V_189 , V_190 ) ;
F_214 ( V_21 , V_211 ) ;
return V_28 ;
} else {
F_31 ( & V_21 -> V_8 , L_75 ) ;
return - V_41 ;
}
}
int F_215 ( const struct V_4 * V_5 , const char * V_70 , int V_113 )
{
int V_28 ;
struct V_20 * V_21 = V_5 -> V_45 ;
struct V_185 V_186 ;
V_186 . V_52 = V_5 -> V_52 ;
V_186 . V_49 = V_5 -> V_49 & V_212 ;
V_186 . V_72 = V_113 ;
V_186 . V_70 = ( char * ) V_70 ;
V_28 = F_208 ( V_21 , & V_186 , 1 ) ;
return ( V_28 == 1 ) ? V_113 : V_28 ;
}
int F_216 ( const struct V_4 * V_5 , char * V_70 , int V_113 )
{
struct V_20 * V_21 = V_5 -> V_45 ;
struct V_185 V_186 ;
int V_28 ;
V_186 . V_52 = V_5 -> V_52 ;
V_186 . V_49 = V_5 -> V_49 & V_212 ;
V_186 . V_49 |= V_188 ;
V_186 . V_72 = V_113 ;
V_186 . V_70 = V_70 ;
V_28 = F_208 ( V_21 , & V_186 , 1 ) ;
return ( V_28 == 1 ) ? V_113 : V_28 ;
}
static int F_217 ( struct V_20 * V_21 , unsigned short V_52 )
{
int V_44 ;
union V_213 V_158 ;
#ifdef F_218
if ( V_52 == 0x73 && ( V_21 -> V_214 & V_215 )
&& F_126 ( V_21 , V_216 ) )
V_44 = F_219 ( V_21 , V_52 , 0 , V_217 , 0 ,
V_218 , & V_158 ) ;
else
#endif
if ( ! ( ( V_52 & ~ 0x07 ) == 0x30 || ( V_52 & ~ 0x0f ) == 0x50 )
&& F_126 ( V_21 , V_219 ) )
V_44 = F_219 ( V_21 , V_52 , 0 , V_220 , 0 ,
V_221 , NULL ) ;
else if ( F_126 ( V_21 , V_222 ) )
V_44 = F_219 ( V_21 , V_52 , 0 , V_217 , 0 ,
V_223 , & V_158 ) ;
else {
F_22 ( & V_21 -> V_8 , L_76 ,
V_52 ) ;
V_44 = - V_41 ;
}
return V_44 >= 0 ;
}
static int F_220 ( struct V_4 * V_224 ,
struct V_11 * V_12 )
{
struct V_93 V_94 ;
struct V_20 * V_45 = V_224 -> V_45 ;
int V_52 = V_224 -> V_52 ;
int V_44 ;
V_44 = F_60 ( V_52 ) ;
if ( V_44 ) {
F_22 ( & V_45 -> V_8 , L_77 ,
V_52 ) ;
return V_44 ;
}
if ( F_66 ( V_45 , V_52 ) )
return 0 ;
if ( ! F_217 ( V_45 , V_52 ) )
return 0 ;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
V_94 . V_52 = V_52 ;
V_44 = V_12 -> V_225 ( V_224 , & V_94 ) ;
if ( V_44 ) {
return V_44 == - V_18 ? 0 : V_44 ;
}
if ( V_94 . type [ 0 ] == '\0' ) {
F_27 ( & V_45 -> V_8 ,
L_78 ,
V_12 -> V_12 . V_6 , V_52 ) ;
} else {
struct V_4 * V_5 ;
if ( V_45 -> V_214 & V_226 )
F_22 ( & V_45 -> V_8 ,
L_79
L_80
L_81 ,
V_94 . V_52 ) ;
F_31 ( & V_45 -> V_8 , L_82 ,
V_94 . type , V_94 . V_52 ) ;
V_5 = F_81 ( V_45 , & V_94 ) ;
if ( V_5 )
F_105 ( & V_5 -> V_119 , & V_12 -> V_170 ) ;
else
F_27 ( & V_45 -> V_8 , L_83 ,
V_94 . type , V_94 . V_52 ) ;
}
return 0 ;
}
static int F_118 ( struct V_20 * V_45 , struct V_11 * V_12 )
{
const unsigned short * V_227 ;
struct V_4 * V_224 ;
int V_33 , V_44 = 0 ;
int V_228 = F_76 ( V_45 ) ;
V_227 = V_12 -> V_227 ;
if ( ! V_12 -> V_225 || ! V_227 )
return 0 ;
if ( V_45 -> V_214 == V_226 ) {
F_31 ( & V_45 -> V_8 ,
L_84
L_85 ,
V_12 -> V_12 . V_6 ) ;
return 0 ;
}
if ( ! ( V_45 -> V_214 & V_12 -> V_214 ) )
return 0 ;
V_224 = F_82 ( sizeof( struct V_4 ) , V_95 ) ;
if ( ! V_224 )
return - V_142 ;
V_224 -> V_45 = V_45 ;
for ( V_33 = 0 ; V_227 [ V_33 ] != V_229 ; V_33 += 1 ) {
F_31 ( & V_45 -> V_8 ,
L_86 ,
V_228 , V_227 [ V_33 ] ) ;
V_224 -> V_52 = V_227 [ V_33 ] ;
V_44 = F_220 ( V_224 , V_12 ) ;
if ( F_221 ( V_44 ) )
break;
}
F_53 ( V_224 ) ;
return V_44 ;
}
int F_222 ( struct V_20 * V_21 , unsigned short V_52 )
{
return F_219 ( V_21 , V_52 , 0 , V_217 , 0 ,
V_221 , NULL ) >= 0 ;
}
struct V_4 *
F_223 ( struct V_20 * V_21 ,
struct V_93 * V_94 ,
unsigned short const * V_230 ,
int (* V_65)( struct V_20 * , unsigned short V_52 ) )
{
int V_33 ;
if ( ! V_65 )
V_65 = F_217 ;
for ( V_33 = 0 ; V_230 [ V_33 ] != V_229 ; V_33 ++ ) {
if ( F_60 ( V_230 [ V_33 ] ) < 0 ) {
F_22 ( & V_21 -> V_8 , L_87 ,
V_230 [ V_33 ] ) ;
continue;
}
if ( F_66 ( V_21 , V_230 [ V_33 ] ) ) {
F_31 ( & V_21 -> V_8 ,
L_88 ,
V_230 [ V_33 ] ) ;
continue;
}
if ( V_65 ( V_21 , V_230 [ V_33 ] ) )
break;
}
if ( V_230 [ V_33 ] == V_229 ) {
F_31 ( & V_21 -> V_8 , L_89 ) ;
return NULL ;
}
V_94 -> V_52 = V_230 [ V_33 ] ;
return F_81 ( V_21 , V_94 ) ;
}
struct V_20 * F_224 ( int V_126 )
{
struct V_20 * V_45 ;
F_104 ( & V_154 ) ;
V_45 = F_157 ( & V_155 , V_126 ) ;
if ( ! V_45 )
goto exit;
if ( F_225 ( V_45 -> V_169 ) )
F_176 ( & V_45 -> V_8 ) ;
else
V_45 = NULL ;
exit:
F_106 ( & V_154 ) ;
return V_45 ;
}
void F_226 ( struct V_20 * V_21 )
{
if ( ! V_21 )
return;
F_178 ( & V_21 -> V_8 ) ;
F_227 ( V_21 -> V_169 ) ;
}
