static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
F_2 ( V_5 ) ;
for ( V_7 = 0 ; V_7 < V_8 && V_7 <= V_5 -> V_9 ; V_7 ++ ) {
F_3 ( V_2 , L_1
L_2 , V_7 ,
V_5 -> V_10 [ V_7 ] [ 0 ] , V_5 -> V_10 [ V_7 ] [ 1 ] ,
V_5 -> V_10 [ V_7 ] [ 2 ] , V_5 -> V_10 [ V_7 ] [ 3 ] ,
V_5 -> V_10 [ V_7 ] [ 4 ] , V_5 -> V_10 [ V_7 ] [ 5 ] ,
V_5 -> V_10 [ V_7 ] [ 6 ] , V_5 -> V_10 [ V_7 ] [ 7 ] ) ;
}
if ( F_4 ( V_5 ) )
F_3 ( V_2 , L_3
L_2 ,
V_5 -> V_11 [ 0 ] , V_5 -> V_11 [ 1 ] ,
V_5 -> V_11 [ 2 ] , V_5 -> V_11 [ 3 ] ,
V_5 -> V_11 [ 4 ] , V_5 -> V_11 [ 5 ] ,
V_5 -> V_11 [ 6 ] , V_5 -> V_11 [ 7 ] ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_1 , V_12 -> V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_15 * V_7 ;
struct V_16 * V_17 ;
F_2 ( V_5 ) ;
F_9 (b, &hdev->whitelist, list)
F_3 ( V_2 , L_4 , & V_17 -> V_18 , V_17 -> V_19 ) ;
F_9 (p, &hdev->le_conn_params, list) {
F_3 ( V_2 , L_5 , & V_7 -> V_20 , V_7 -> V_21 ,
V_7 -> V_22 ) ;
}
F_5 ( V_5 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_8 , V_12 -> V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 ;
F_2 ( V_5 ) ;
F_9 (b, &hdev->blacklist, list)
F_3 ( V_2 , L_4 , & V_17 -> V_18 , V_17 -> V_19 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_11 , V_12 -> V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_23 * V_24 ;
F_2 ( V_5 ) ;
F_9 (uuid, &hdev->uuids, list) {
T_1 V_25 , V_26 [ 16 ] ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
V_26 [ V_25 ] = V_24 -> V_24 [ 15 - V_25 ] ;
F_3 ( V_2 , L_6 , V_26 ) ;
}
F_5 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_13 , V_12 -> V_14 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_27 * V_28 ;
F_2 ( V_5 ) ;
F_9 (data, &hdev->remote_oob_data, list) {
F_3 ( V_2 , L_7 ,
& V_28 -> V_18 , V_28 -> V_19 , V_28 -> V_29 ,
16 , V_28 -> V_30 , 16 , V_28 -> V_31 ,
16 , V_28 -> V_32 , 19 , V_28 -> V_33 ) ;
}
F_5 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_15 , V_12 -> V_14 ) ;
}
static int F_17 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 == 0 || V_26 > V_5 -> V_34 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_36 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_18 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_36 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_19 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 == 0 || V_26 < V_5 -> V_36 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_34 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_20 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_34 ;
F_5 ( V_5 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_13 * V_13 , char T_4 * V_37 ,
T_5 V_38 , T_6 * V_39 )
{
struct V_4 * V_5 = V_13 -> V_40 ;
char V_41 [ 3 ] ;
V_41 [ 0 ] = F_22 ( V_42 , & V_5 -> V_43 ) ? 'Y' : 'N' ;
V_41 [ 1 ] = '\n' ;
V_41 [ 2 ] = '\0' ;
return F_23 ( V_37 , V_38 , V_39 , V_41 , 2 ) ;
}
static T_3 F_24 ( struct V_13 * V_13 , char T_4 * V_37 ,
T_5 V_38 , T_6 * V_39 )
{
struct V_4 * V_5 = V_13 -> V_40 ;
char V_41 [ 3 ] ;
V_41 [ 0 ] = F_22 ( V_44 , & V_5 -> V_43 ) ? 'Y' : 'N' ;
V_41 [ 1 ] = '\n' ;
V_41 [ 2 ] = '\0' ;
return F_23 ( V_37 , V_38 , V_39 , V_41 , 2 ) ;
}
void F_25 ( struct V_4 * V_5 )
{
F_26 ( L_8 , 0444 , V_5 -> V_45 , V_5 ,
& V_46 ) ;
F_27 ( L_9 , 0444 , V_5 -> V_45 ,
& V_5 -> V_47 ) ;
F_28 ( L_10 , 0444 , V_5 -> V_45 , & V_5 -> V_48 ) ;
F_27 ( L_11 , 0444 , V_5 -> V_45 , & V_5 -> V_49 ) ;
F_28 ( L_12 , 0444 , V_5 -> V_45 ,
& V_5 -> V_50 ) ;
F_26 ( L_13 , 0444 , V_5 -> V_45 , V_5 ,
& V_51 ) ;
F_26 ( L_14 , 0444 , V_5 -> V_45 , V_5 ,
& V_52 ) ;
F_26 ( L_15 , 0444 , V_5 -> V_45 , V_5 , & V_53 ) ;
F_26 ( L_16 , 0400 , V_5 -> V_45 , V_5 ,
& V_54 ) ;
F_26 ( L_17 , 0644 , V_5 -> V_45 , V_5 ,
& V_55 ) ;
F_26 ( L_18 , 0644 , V_5 -> V_45 , V_5 ,
& V_56 ) ;
if ( F_29 ( V_5 ) || F_4 ( V_5 ) )
F_26 ( L_19 , 0444 , V_5 -> V_45 ,
V_5 , & V_57 ) ;
if ( F_30 ( V_5 ) || F_4 ( V_5 ) )
F_26 ( L_20 , 0444 , V_5 -> V_45 ,
V_5 , & V_58 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_59 * V_60 = & V_5 -> V_61 ;
struct V_62 * V_63 ;
F_2 ( V_5 ) ;
F_9 (e, &cache->all, all) {
struct V_64 * V_28 = & V_63 -> V_28 ;
F_3 ( V_2 , L_21 ,
& V_28 -> V_18 ,
V_28 -> V_65 , V_28 -> V_66 ,
V_28 -> V_67 , V_28 -> V_68 [ 2 ] ,
V_28 -> V_68 [ 1 ] , V_28 -> V_68 [ 0 ] ,
F_32 ( V_28 -> V_69 ) ,
V_28 -> V_70 , V_28 -> V_71 , V_63 -> V_72 ) ;
}
F_5 ( V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_31 , V_12 -> V_14 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_73 * V_74 ;
F_35 () ;
F_36 (key, &hdev->link_keys, list)
F_3 ( V_2 , L_22 , & V_74 -> V_18 , V_74 -> type ,
V_75 , V_74 -> V_26 , V_74 -> V_76 ) ;
F_37 () ;
return 0 ;
}
static int F_38 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_34 , V_12 -> V_14 ) ;
}
static int F_39 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 ) ;
F_3 ( V_2 , L_23 , V_5 -> V_68 [ 2 ] ,
V_5 -> V_68 [ 1 ] , V_5 -> V_68 [ 0 ] ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_40 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_39 , V_12 -> V_14 ) ;
}
static int F_41 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_77 ;
F_5 ( V_5 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_13 * V_13 , char T_4 * V_37 ,
T_5 V_38 , T_6 * V_39 )
{
struct V_4 * V_5 = V_13 -> V_40 ;
char V_41 [ 3 ] ;
V_41 [ 0 ] = V_5 -> V_78 ? 'Y' : 'N' ;
V_41 [ 1 ] = '\n' ;
V_41 [ 2 ] = '\0' ;
return F_23 ( V_37 , V_38 , V_39 , V_41 , 2 ) ;
}
static int F_43 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
V_5 -> V_79 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_44 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_79 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_45 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 != 0 && ( V_26 < 500 || V_26 > 3600000 ) )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_80 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_46 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_80 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_47 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 == 0 || V_26 % 2 || V_26 > V_5 -> V_81 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_82 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_48 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_82 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_49 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 == 0 || V_26 % 2 || V_26 < V_5 -> V_82 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_81 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_50 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_81 ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_51 ( struct V_4 * V_5 )
{
F_26 ( L_24 , 0444 , V_5 -> V_45 , V_5 ,
& V_83 ) ;
F_26 ( L_25 , 0400 , V_5 -> V_45 , V_5 ,
& V_84 ) ;
F_26 ( L_26 , 0444 , V_5 -> V_45 , V_5 ,
& V_85 ) ;
F_26 ( L_27 , 0444 , V_5 -> V_45 , V_5 ,
& V_86 ) ;
if ( F_29 ( V_5 ) ) {
F_26 ( L_28 , 0444 , V_5 -> V_45 ,
V_5 , & V_87 ) ;
F_26 ( L_29 , 0644 , V_5 -> V_45 ,
V_5 , & V_88 ) ;
}
if ( F_52 ( V_5 ) ) {
F_26 ( L_30 , 0644 , V_5 -> V_45 ,
V_5 , & V_89 ) ;
F_26 ( L_31 , 0644 , V_5 -> V_45 ,
V_5 , & V_90 ) ;
F_26 ( L_32 , 0644 , V_5 -> V_45 ,
V_5 , & V_91 ) ;
}
}
static int F_53 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_7 V_20 ;
T_1 V_21 ;
F_2 ( V_5 ) ;
F_54 ( V_5 , & V_20 , & V_21 ) ;
F_3 ( V_2 , L_33 , & V_20 , V_21 ,
16 , V_5 -> V_92 , & V_5 -> V_93 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_55 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_53 , V_12 -> V_14 ) ;
}
static int F_56 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 30 || V_26 > ( 60 * 60 * 24 ) )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_94 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_57 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_94 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 ) ;
F_3 ( V_2 , L_34 , & V_5 -> V_95 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_58 , V_12 -> V_14 ) ;
}
static int F_60 ( struct V_1 * V_2 , void * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 ) ;
F_3 ( V_2 , L_34 , & V_5 -> V_96 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_61 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_60 , V_12 -> V_14 ) ;
}
static T_3 F_62 ( struct V_13 * V_13 ,
char T_4 * V_37 ,
T_5 V_38 , T_6 * V_39 )
{
struct V_4 * V_5 = V_13 -> V_40 ;
char V_41 [ 3 ] ;
V_41 [ 0 ] = F_22 ( V_97 , & V_5 -> V_98 ) ? 'Y' : 'N' ;
V_41 [ 1 ] = '\n' ;
V_41 [ 2 ] = '\0' ;
return F_23 ( V_37 , V_38 , V_39 , V_41 , 2 ) ;
}
static T_3 F_63 ( struct V_13 * V_13 ,
const char T_4 * V_37 ,
T_5 V_38 , T_6 * V_39 )
{
struct V_4 * V_5 = V_13 -> V_40 ;
char V_41 [ 32 ] ;
T_5 V_99 = F_64 ( V_38 , ( sizeof( V_41 ) - 1 ) ) ;
bool V_100 ;
if ( F_22 ( V_101 , & V_5 -> V_102 ) )
return - V_103 ;
if ( F_65 ( V_41 , V_37 , V_99 ) )
return - V_104 ;
V_41 [ V_99 ] = '\0' ;
if ( F_66 ( V_41 , & V_100 ) )
return - V_35 ;
if ( V_100 == F_22 ( V_97 , & V_5 -> V_98 ) )
return - V_105 ;
F_67 ( V_97 , & V_5 -> V_98 ) ;
return V_38 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 ;
F_2 ( V_5 ) ;
F_9 (b, &hdev->le_white_list, list)
F_3 ( V_2 , L_4 , & V_17 -> V_18 , V_17 -> V_19 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_69 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_68 , V_12 -> V_14 ) ;
}
static int F_70 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_106 * V_92 ;
F_35 () ;
F_36 (irk, &hdev->identity_resolving_keys, list) {
F_3 ( V_2 , L_33 ,
& V_92 -> V_18 , V_92 -> V_21 ,
16 , V_92 -> V_26 , & V_92 -> V_93 ) ;
}
F_37 () ;
return 0 ;
}
static int F_71 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_70 ,
V_12 -> V_14 ) ;
}
static int F_72 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_107 * V_108 ;
F_35 () ;
F_36 (ltk, &hdev->long_term_keys, list)
F_3 ( V_2 , L_35 ,
& V_108 -> V_18 , V_108 -> V_19 , V_108 -> V_109 ,
V_108 -> type , V_108 -> V_110 , F_32 ( V_108 -> V_111 ) ,
F_73 ( V_108 -> rand ) , 16 , V_108 -> V_26 ) ;
F_37 () ;
return 0 ;
}
static int F_74 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_7 ( V_13 , F_72 , V_12 -> V_14 ) ;
}
static int F_75 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x0006 || V_26 > 0x0c80 || V_26 > V_5 -> V_112 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_113 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_76 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_113 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_77 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x0006 || V_26 > 0x0c80 || V_26 < V_5 -> V_113 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_112 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_78 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_112 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_79 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 > 0x01f3 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_114 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_80 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_114 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_81 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x000a || V_26 > 0x0c80 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_115 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_82 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_115 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_83 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x01 || V_26 > 0x07 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_116 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_84 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_116 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_85 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x0020 || V_26 > 0x4000 || V_26 > V_5 -> V_117 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_118 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_86 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_118 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_87 ( void * V_28 , T_2 V_26 )
{
struct V_4 * V_5 = V_28 ;
if ( V_26 < 0x0020 || V_26 > 0x4000 || V_26 < V_5 -> V_118 )
return - V_35 ;
F_2 ( V_5 ) ;
V_5 -> V_117 = V_26 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_88 ( void * V_28 , T_2 * V_26 )
{
struct V_4 * V_5 = V_28 ;
F_2 ( V_5 ) ;
* V_26 = V_5 -> V_117 ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_89 ( struct V_4 * V_5 )
{
F_26 ( L_36 , 0400 , V_5 -> V_45 , V_5 ,
& V_119 ) ;
F_26 ( L_37 , 0644 , V_5 -> V_45 , V_5 ,
& V_120 ) ;
F_26 ( L_38 , 0444 , V_5 -> V_45 , V_5 ,
& V_121 ) ;
F_26 ( L_39 , 0444 , V_5 -> V_45 , V_5 ,
& V_122 ) ;
if ( F_90 ( & V_5 -> V_18 , V_123 ) )
F_26 ( L_40 , 0644 ,
V_5 -> V_45 , V_5 ,
& V_124 ) ;
F_28 ( L_41 , 0444 , V_5 -> V_45 ,
& V_5 -> V_125 ) ;
F_26 ( L_42 , 0444 , V_5 -> V_45 , V_5 ,
& V_126 ) ;
F_26 ( L_43 , 0400 , V_5 -> V_45 ,
V_5 , & V_127 ) ;
F_26 ( L_44 , 0400 , V_5 -> V_45 , V_5 ,
& V_128 ) ;
F_26 ( L_45 , 0644 , V_5 -> V_45 , V_5 ,
& V_129 ) ;
F_26 ( L_46 , 0644 , V_5 -> V_45 , V_5 ,
& V_130 ) ;
F_26 ( L_47 , 0644 , V_5 -> V_45 , V_5 ,
& V_131 ) ;
F_26 ( L_48 , 0644 , V_5 -> V_45 , V_5 ,
& V_132 ) ;
F_26 ( L_49 , 0644 , V_5 -> V_45 , V_5 ,
& V_133 ) ;
F_26 ( L_50 , 0644 , V_5 -> V_45 , V_5 ,
& V_134 ) ;
F_26 ( L_51 , 0644 , V_5 -> V_45 , V_5 ,
& V_135 ) ;
F_27 ( L_52 , 0644 , V_5 -> V_45 ,
& V_5 -> V_136 ) ;
}
void F_91 ( struct V_137 * V_138 )
{
struct V_4 * V_5 = V_138 -> V_5 ;
char V_139 [ 6 ] ;
if ( F_92 ( V_5 -> V_45 ) )
return;
snprintf ( V_139 , sizeof( V_139 ) , L_53 , V_138 -> V_140 ) ;
V_138 -> V_45 = F_93 ( V_139 , V_5 -> V_45 ) ;
}
