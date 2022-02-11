static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 , V_1 -> V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( V_9 ) ;
F_5 ( V_6 , L_1 , V_9 -> V_11 ,
V_9 -> V_12 , V_9 -> V_13 , V_9 -> V_14 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_3 , V_1 -> V_4 ) ;
}
static int F_8 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
F_4 ( V_9 ) ;
F_9 (b, &hdev->whitelist, list)
F_5 ( V_6 , L_2 , & V_18 -> V_19 , V_18 -> V_20 ) ;
F_9 (p, &hdev->le_conn_params, list) {
F_5 ( V_6 , L_3 , & V_16 -> V_21 , V_16 -> V_22 ,
V_16 -> V_23 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_8 , V_1 -> V_4 ) ;
}
static int F_11 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 ;
F_4 ( V_9 ) ;
F_9 (b, &hdev->blacklist, list)
F_5 ( V_6 , L_2 , & V_18 -> V_19 , V_18 -> V_20 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_11 , V_1 -> V_4 ) ;
}
static int F_13 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_24 * V_25 ;
F_4 ( V_9 ) ;
F_9 (uuid, &hdev->uuids, list) {
T_1 V_26 , V_27 [ 16 ] ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
V_27 [ V_26 ] = V_25 -> V_25 [ 15 - V_26 ] ;
F_5 ( V_6 , L_4 , V_27 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_13 , V_1 -> V_4 ) ;
}
static int F_15 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_28 * V_29 ;
F_4 ( V_9 ) ;
F_9 (data, &hdev->remote_oob_data, list) {
F_5 ( V_6 , L_5 ,
& V_29 -> V_19 , V_29 -> V_20 , V_29 -> V_30 ,
16 , V_29 -> V_31 , 16 , V_29 -> V_32 ,
16 , V_29 -> V_33 , 16 , V_29 -> V_34 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_15 , V_1 -> V_4 ) ;
}
static int F_17 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 == 0 || V_27 > V_9 -> V_35 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_37 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_18 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_37 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_19 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 == 0 || V_27 < V_9 -> V_37 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_35 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_20 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_35 ;
F_6 ( V_9 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_2 * V_2 , char T_4 * V_38 ,
T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_41 ;
char V_42 [ 3 ] ;
V_42 [ 0 ] = F_22 ( V_9 , V_43 ) ? 'Y' : 'N' ;
V_42 [ 1 ] = '\n' ;
V_42 [ 2 ] = '\0' ;
return F_23 ( V_38 , V_39 , V_40 , V_42 , 2 ) ;
}
static T_3 F_24 ( struct V_2 * V_2 , char T_4 * V_38 ,
T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_41 ;
char V_42 [ 3 ] ;
V_42 [ 0 ] = F_22 ( V_9 , V_44 ) ? 'Y' : 'N' ;
V_42 [ 1 ] = '\n' ;
V_42 [ 2 ] = '\0' ;
return F_23 ( V_38 , V_39 , V_40 , V_42 , 2 ) ;
}
void F_25 ( struct V_8 * V_9 )
{
F_26 ( L_6 , 0444 , V_9 -> V_45 , V_9 ,
& V_46 ) ;
F_27 ( L_7 , 0444 , V_9 -> V_45 ,
& V_9 -> V_47 ) ;
F_28 ( L_8 , 0444 , V_9 -> V_45 , & V_9 -> V_48 ) ;
F_27 ( L_9 , 0444 , V_9 -> V_45 , & V_9 -> V_49 ) ;
F_28 ( L_10 , 0444 , V_9 -> V_45 ,
& V_9 -> V_50 ) ;
F_26 ( L_11 , 0444 , V_9 -> V_45 , V_9 ,
& V_51 ) ;
F_26 ( L_12 , 0444 , V_9 -> V_45 , V_9 ,
& V_52 ) ;
F_26 ( L_13 , 0444 , V_9 -> V_45 , V_9 ,
& V_53 ) ;
F_26 ( L_14 , 0444 , V_9 -> V_45 , V_9 , & V_54 ) ;
F_26 ( L_15 , 0400 , V_9 -> V_45 , V_9 ,
& V_55 ) ;
F_26 ( L_16 , 0644 , V_9 -> V_45 , V_9 ,
& V_56 ) ;
F_26 ( L_17 , 0644 , V_9 -> V_45 , V_9 ,
& V_57 ) ;
if ( F_29 ( V_9 ) || F_30 ( V_9 ) )
F_26 ( L_18 , 0444 , V_9 -> V_45 ,
V_9 , & V_58 ) ;
if ( F_31 ( V_9 ) || F_30 ( V_9 ) )
F_26 ( L_19 , 0444 , V_9 -> V_45 ,
V_9 , & V_59 ) ;
if ( V_9 -> V_60 )
F_26 ( L_20 , 0444 , V_9 -> V_45 ,
V_9 , & V_61 ) ;
if ( V_9 -> V_62 )
F_26 ( L_21 , 0444 , V_9 -> V_45 ,
V_9 , & V_63 ) ;
}
static int F_32 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_64 * V_65 = & V_9 -> V_66 ;
struct V_67 * V_68 ;
F_4 ( V_9 ) ;
F_9 (e, &cache->all, all) {
struct V_69 * V_29 = & V_68 -> V_29 ;
F_5 ( V_6 , L_22 ,
& V_29 -> V_19 ,
V_29 -> V_70 , V_29 -> V_71 ,
V_29 -> V_72 , V_29 -> V_73 [ 2 ] ,
V_29 -> V_73 [ 1 ] , V_29 -> V_73 [ 0 ] ,
F_33 ( V_29 -> V_74 ) ,
V_29 -> V_75 , V_29 -> V_76 , V_68 -> V_77 ) ;
}
F_6 ( V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_32 , V_1 -> V_4 ) ;
}
static int F_35 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_78 * V_79 ;
F_36 () ;
F_37 (key, &hdev->link_keys, list)
F_5 ( V_6 , L_23 , & V_79 -> V_19 , V_79 -> type ,
V_80 , V_79 -> V_27 , V_79 -> V_81 ) ;
F_38 () ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_35 , V_1 -> V_4 ) ;
}
static int F_40 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( V_9 ) ;
F_5 ( V_6 , L_24 , V_9 -> V_73 [ 2 ] ,
V_9 -> V_73 [ 1 ] , V_9 -> V_73 [ 0 ] ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_40 , V_1 -> V_4 ) ;
}
static int F_42 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_82 ;
F_6 ( V_9 ) ;
return 0 ;
}
static T_3 F_43 ( struct V_2 * V_2 , char T_4 * V_38 ,
T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_41 ;
char V_42 [ 3 ] ;
V_42 [ 0 ] = V_9 -> V_83 ? 'Y' : 'N' ;
V_42 [ 1 ] = '\n' ;
V_42 [ 2 ] = '\0' ;
return F_23 ( V_38 , V_39 , V_40 , V_42 , 2 ) ;
}
static int F_44 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
V_9 -> V_84 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_45 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_84 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_46 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 != 0 && ( V_27 < 500 || V_27 > 3600000 ) )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_85 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_47 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_85 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_48 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 == 0 || V_27 % 2 || V_27 > V_9 -> V_86 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_87 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_49 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_87 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_50 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 == 0 || V_27 % 2 || V_27 < V_9 -> V_87 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_86 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_51 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_86 ;
F_6 ( V_9 ) ;
return 0 ;
}
void F_52 ( struct V_8 * V_9 )
{
F_26 ( L_25 , 0444 , V_9 -> V_45 , V_9 ,
& V_88 ) ;
F_26 ( L_26 , 0400 , V_9 -> V_45 , V_9 ,
& V_89 ) ;
F_26 ( L_27 , 0444 , V_9 -> V_45 , V_9 ,
& V_90 ) ;
F_26 ( L_28 , 0444 , V_9 -> V_45 , V_9 ,
& V_91 ) ;
if ( F_29 ( V_9 ) ) {
F_26 ( L_29 , 0444 , V_9 -> V_45 ,
V_9 , & V_92 ) ;
F_26 ( L_30 , 0644 , V_9 -> V_45 ,
V_9 , & V_93 ) ;
}
if ( F_53 ( V_9 ) ) {
F_26 ( L_31 , 0644 , V_9 -> V_45 ,
V_9 , & V_94 ) ;
F_26 ( L_32 , 0644 , V_9 -> V_45 ,
V_9 , & V_95 ) ;
F_26 ( L_33 , 0644 , V_9 -> V_45 ,
V_9 , & V_96 ) ;
}
}
static int F_54 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_7 V_21 ;
T_1 V_22 ;
F_4 ( V_9 ) ;
F_55 ( V_9 , & V_21 , & V_22 ) ;
F_5 ( V_6 , L_34 , & V_21 , V_22 ,
16 , V_9 -> V_97 , & V_9 -> V_98 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_54 , V_1 -> V_4 ) ;
}
static int F_57 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 30 || V_27 > ( 60 * 60 * 24 ) )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_99 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_58 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_99 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( V_9 ) ;
F_5 ( V_6 , L_35 , & V_9 -> V_100 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_59 , V_1 -> V_4 ) ;
}
static int F_61 ( struct V_5 * V_6 , void * V_16 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( V_9 ) ;
F_5 ( V_6 , L_35 , & V_9 -> V_101 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_61 , V_1 -> V_4 ) ;
}
static T_3 F_63 ( struct V_2 * V_2 ,
char T_4 * V_38 ,
T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_41 ;
char V_42 [ 3 ] ;
V_42 [ 0 ] = F_22 ( V_9 , V_102 ) ? 'Y' : 'N' ;
V_42 [ 1 ] = '\n' ;
V_42 [ 2 ] = '\0' ;
return F_23 ( V_38 , V_39 , V_40 , V_42 , 2 ) ;
}
static T_3 F_64 ( struct V_2 * V_2 ,
const char T_4 * V_38 ,
T_5 V_39 , T_6 * V_40 )
{
struct V_8 * V_9 = V_2 -> V_41 ;
char V_42 [ 32 ] ;
T_5 V_103 = F_65 ( V_39 , ( sizeof( V_42 ) - 1 ) ) ;
bool V_104 ;
if ( F_66 ( V_105 , & V_9 -> V_106 ) )
return - V_107 ;
if ( F_67 ( V_42 , V_38 , V_103 ) )
return - V_108 ;
V_42 [ V_103 ] = '\0' ;
if ( F_68 ( V_42 , & V_104 ) )
return - V_36 ;
if ( V_104 == F_22 ( V_9 , V_102 ) )
return - V_109 ;
F_69 ( V_9 , V_102 ) ;
return V_39 ;
}
static int F_70 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 ;
F_4 ( V_9 ) ;
F_9 (b, &hdev->le_white_list, list)
F_5 ( V_6 , L_2 , & V_18 -> V_19 , V_18 -> V_20 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_70 , V_1 -> V_4 ) ;
}
static int F_72 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_110 * V_97 ;
F_36 () ;
F_37 (irk, &hdev->identity_resolving_keys, list) {
F_5 ( V_6 , L_34 ,
& V_97 -> V_19 , V_97 -> V_22 ,
16 , V_97 -> V_27 , & V_97 -> V_98 ) ;
}
F_38 () ;
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_72 ,
V_1 -> V_4 ) ;
}
static int F_74 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_111 * V_112 ;
F_36 () ;
F_37 (ltk, &hdev->long_term_keys, list)
F_5 ( V_6 , L_36 ,
& V_112 -> V_19 , V_112 -> V_20 , V_112 -> V_113 ,
V_112 -> type , V_112 -> V_114 , F_33 ( V_112 -> V_115 ) ,
F_75 ( V_112 -> rand ) , 16 , V_112 -> V_27 ) ;
F_38 () ;
return 0 ;
}
static int F_76 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , F_74 , V_1 -> V_4 ) ;
}
static int F_77 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x0006 || V_27 > 0x0c80 || V_27 > V_9 -> V_116 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_117 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_78 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_117 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_79 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x0006 || V_27 > 0x0c80 || V_27 < V_9 -> V_117 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_116 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_80 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_116 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_81 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 > 0x01f3 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_118 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_82 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_118 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_83 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x000a || V_27 > 0x0c80 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_119 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_84 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_119 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_85 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x01 || V_27 > 0x07 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_120 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_86 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_120 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_87 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x0020 || V_27 > 0x4000 || V_27 > V_9 -> V_121 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_122 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_88 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_122 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_89 ( void * V_29 , T_2 V_27 )
{
struct V_8 * V_9 = V_29 ;
if ( V_27 < 0x0020 || V_27 > 0x4000 || V_27 < V_9 -> V_122 )
return - V_36 ;
F_4 ( V_9 ) ;
V_9 -> V_121 = V_27 ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_90 ( void * V_29 , T_2 * V_27 )
{
struct V_8 * V_9 = V_29 ;
F_4 ( V_9 ) ;
* V_27 = V_9 -> V_121 ;
F_6 ( V_9 ) ;
return 0 ;
}
void F_91 ( struct V_8 * V_9 )
{
F_26 ( L_37 , 0400 , V_9 -> V_45 , V_9 ,
& V_123 ) ;
F_26 ( L_38 , 0644 , V_9 -> V_45 , V_9 ,
& V_124 ) ;
F_26 ( L_39 , 0444 , V_9 -> V_45 , V_9 ,
& V_125 ) ;
F_26 ( L_40 , 0444 , V_9 -> V_45 , V_9 ,
& V_126 ) ;
if ( F_92 ( & V_9 -> V_19 , V_127 ) )
F_26 ( L_41 , 0644 ,
V_9 -> V_45 , V_9 ,
& V_128 ) ;
F_28 ( L_42 , 0444 , V_9 -> V_45 ,
& V_9 -> V_129 ) ;
F_26 ( L_43 , 0444 , V_9 -> V_45 , V_9 ,
& V_130 ) ;
F_26 ( L_44 , 0400 , V_9 -> V_45 ,
V_9 , & V_131 ) ;
F_26 ( L_45 , 0400 , V_9 -> V_45 , V_9 ,
& V_132 ) ;
F_26 ( L_46 , 0644 , V_9 -> V_45 , V_9 ,
& V_133 ) ;
F_26 ( L_47 , 0644 , V_9 -> V_45 , V_9 ,
& V_134 ) ;
F_26 ( L_48 , 0644 , V_9 -> V_45 , V_9 ,
& V_135 ) ;
F_26 ( L_49 , 0644 , V_9 -> V_45 , V_9 ,
& V_136 ) ;
F_26 ( L_50 , 0644 , V_9 -> V_45 , V_9 ,
& V_137 ) ;
F_26 ( L_51 , 0644 , V_9 -> V_45 , V_9 ,
& V_138 ) ;
F_26 ( L_52 , 0644 , V_9 -> V_45 , V_9 ,
& V_139 ) ;
F_27 ( L_53 , 0644 , V_9 -> V_45 ,
& V_9 -> V_140 ) ;
F_26 ( L_54 , 0644 ,
V_9 -> V_45 , V_9 ,
& V_141 ) ;
F_26 ( L_55 , 0644 ,
V_9 -> V_45 , V_9 ,
& V_142 ) ;
}
void F_93 ( struct V_143 * V_144 )
{
struct V_8 * V_9 = V_144 -> V_9 ;
char V_145 [ 6 ] ;
if ( F_94 ( V_9 -> V_45 ) )
return;
snprintf ( V_145 , sizeof( V_145 ) , L_56 , V_144 -> V_146 ) ;
V_144 -> V_45 = F_95 ( V_145 , V_9 -> V_45 ) ;
}
