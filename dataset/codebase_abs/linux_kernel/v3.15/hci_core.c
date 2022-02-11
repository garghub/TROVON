static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_10 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_6 ( struct V_4 * V_4 , const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_12 * V_13 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
int V_16 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_10 , & V_2 -> V_11 ) )
return - V_22 ;
F_10 ( V_2 ) ;
if ( V_15 )
V_13 = F_11 ( V_2 , V_23 , 0 , NULL ,
V_24 ) ;
else
V_13 = F_11 ( V_2 , V_25 , 0 , NULL ,
V_24 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_16 = - F_15 ( V_13 -> V_26 [ 0 ] ) ;
F_16 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
F_17 ( V_10 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_18 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_5 V_31 ;
F_19 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
F_20 ( V_28 , L_1
L_2 , V_31 ,
V_2 -> V_34 [ V_31 ] [ 0 ] , V_2 -> V_34 [ V_31 ] [ 1 ] ,
V_2 -> V_34 [ V_31 ] [ 2 ] , V_2 -> V_34 [ V_31 ] [ 3 ] ,
V_2 -> V_34 [ V_31 ] [ 4 ] , V_2 -> V_34 [ V_31 ] [ 5 ] ,
V_2 -> V_34 [ V_31 ] [ 6 ] , V_2 -> V_34 [ V_31 ] [ 7 ] ) ;
}
if ( F_21 ( V_2 ) )
F_20 ( V_28 , L_3
L_2 ,
V_2 -> V_35 [ 0 ] , V_2 -> V_35 [ 1 ] ,
V_2 -> V_35 [ 2 ] , V_2 -> V_35 [ 3 ] ,
V_2 -> V_35 [ 4 ] , V_2 -> V_35 [ 5 ] ,
V_2 -> V_35 [ 6 ] , V_2 -> V_35 [ 7 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_18 , V_36 -> V_37 ) ;
}
static int F_25 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->blacklist, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_25 , V_36 -> V_37 ) ;
}
static int F_28 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_42 * V_43 ;
F_19 ( V_2 ) ;
F_26 (uuid, &hdev->uuids, list) {
T_5 V_44 , V_45 [ 16 ] ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_45 [ V_44 ] = V_43 -> V_43 [ 15 - V_44 ] ;
F_20 ( V_28 , L_5 , V_45 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_28 , V_36 -> V_37 ) ;
}
static int F_30 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_19 ( V_2 ) ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
F_20 ( V_28 , L_6 ,
& V_26 -> V_40 ,
V_26 -> V_52 , V_26 -> V_53 ,
V_26 -> V_54 , V_26 -> V_55 [ 2 ] ,
V_26 -> V_55 [ 1 ] , V_26 -> V_55 [ 0 ] ,
F_31 ( V_26 -> V_56 ) ,
V_26 -> V_57 , V_26 -> V_58 , V_50 -> V_59 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_30 , V_36 -> V_37 ) ;
}
static int F_33 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_20 ( V_28 , L_7 , & V_63 -> V_40 , V_63 -> type ,
V_65 , V_63 -> V_45 , V_63 -> V_66 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_33 , V_36 -> V_37 ) ;
}
static int F_37 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_8 , V_2 -> V_55 [ 2 ] ,
V_2 -> V_55 [ 1 ] , V_2 -> V_55 [ 0 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_37 , V_36 -> V_37 ) ;
}
static int F_39 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_67 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_40 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
V_2 -> V_68 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_41 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_68 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_42 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
struct V_12 * V_13 ;
T_7 V_69 ;
int V_16 ;
if ( V_45 != 0 && V_45 != 1 )
return - V_21 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_69 = V_45 ;
V_13 = F_11 ( V_2 , V_70 , sizeof( V_69 ) ,
& V_69 , V_24 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_16 = - F_15 ( V_13 -> V_26 [ 0 ] ) ;
F_16 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
F_19 ( V_2 ) ;
V_2 -> V_71 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_43 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_71 ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_72 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_45 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_73 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_72 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_72 , & V_2 -> V_11 ) ;
return V_6 ;
}
static T_1 F_46 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_74 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static int F_47 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 != 0 && ( V_45 < 500 || V_45 > 3600000 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_75 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_48 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_75 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_49 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 30 || V_45 > ( 60 * 60 * 24 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_76 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_50 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_76 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_51 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 > V_2 -> V_77 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_78 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_52 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_78 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_53 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 < V_2 -> V_78 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_77 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_54 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_77 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_8 V_79 ;
T_5 V_80 ;
F_19 ( V_2 ) ;
F_56 ( V_2 , & V_79 , & V_80 ) ;
F_20 ( V_28 , L_9 , & V_79 , V_80 ,
16 , V_2 -> V_81 , & V_2 -> V_82 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_55 , V_36 -> V_37 ) ;
}
static int F_58 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_83 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_58 , V_36 -> V_37 ) ;
}
static int F_60 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_84 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_60 , V_36 -> V_37 ) ;
}
static T_1 F_62 ( struct V_4 * V_4 ,
char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_85 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_63 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_73 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_85 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_85 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_64 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->le_white_list, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_64 , V_36 -> V_37 ) ;
}
static int F_66 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_34 (p, n, &hdev->identity_resolving_keys) {
struct V_86 * V_81 = F_35 ( V_31 , struct V_86 , V_64 ) ;
F_20 ( V_28 , L_9 ,
& V_81 -> V_40 , V_81 -> V_80 ,
16 , V_81 -> V_45 , & V_81 -> V_82 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_66 ,
V_36 -> V_37 ) ;
}
static int F_68 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_34 (p, n, &hdev->long_term_keys) {
struct V_87 * V_88 = F_35 ( V_31 , struct V_87 , V_64 ) ;
F_20 ( V_28 , L_11 ,
& V_88 -> V_40 , V_88 -> V_41 , V_88 -> V_89 ,
V_88 -> type , V_88 -> V_90 , F_31 ( V_88 -> V_91 ) ,
F_69 ( V_88 -> rand ) , 16 , V_88 -> V_45 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_68 , V_36 -> V_37 ) ;
}
static int F_71 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 > V_2 -> V_92 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_93 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_72 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_93 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_73 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 < V_2 -> V_93 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_92 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_74 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_92 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_75 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x01 || V_45 > 0x07 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_94 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_76 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_94 ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_1 F_77 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_95 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_78 ( struct V_4 * V_96 , const char T_2 * V_97 ,
T_3 V_6 , T_4 * V_98 )
{
struct V_1 * V_2 = V_96 -> V_8 ;
bool V_15 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
if ( F_8 ( V_9 , V_97 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) < 0 )
return - V_21 ;
if ( V_15 == F_4 ( V_95 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_95 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_79 ( struct V_27 * V_99 , void * V_29 )
{
struct V_1 * V_2 = V_99 -> V_30 ;
struct V_100 * V_31 ;
F_19 ( V_2 ) ;
F_26 (p, &hdev->le_conn_params, list) {
F_20 ( V_99 , L_12 , & V_31 -> V_79 , V_31 -> V_80 ,
V_31 -> V_101 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_79 , V_36 -> V_37 ) ;
}
static T_1 F_81 ( struct V_4 * V_4 , const char T_2 * V_26 ,
T_3 V_6 , T_4 * V_102 )
{
struct V_27 * V_99 = V_4 -> V_8 ;
struct V_1 * V_2 = V_99 -> V_30 ;
T_5 V_101 = 0 ;
T_8 V_79 ;
T_5 V_80 ;
char * V_9 ;
int V_16 = 0 ;
int V_61 ;
if ( * V_102 != 0 )
return - V_21 ;
if ( V_6 < 3 )
return - V_21 ;
V_9 = F_82 ( V_6 , V_103 ) ;
if ( ! V_9 )
return - V_104 ;
if ( F_8 ( V_9 , V_26 , V_6 ) ) {
V_16 = - V_20 ;
goto V_105;
}
if ( memcmp ( V_9 , L_13 , 3 ) == 0 ) {
V_61 = sscanf ( & V_9 [ 4 ] , L_14 ,
& V_79 . V_39 [ 5 ] , & V_79 . V_39 [ 4 ] , & V_79 . V_39 [ 3 ] , & V_79 . V_39 [ 2 ] ,
& V_79 . V_39 [ 1 ] , & V_79 . V_39 [ 0 ] , & V_80 ,
& V_101 ) ;
if ( V_61 < 7 ) {
V_16 = - V_21 ;
goto V_105;
}
F_19 ( V_2 ) ;
V_16 = F_83 ( V_2 , & V_79 , V_80 , V_101 ,
V_2 -> V_93 ,
V_2 -> V_92 ) ;
F_22 ( V_2 ) ;
if ( V_16 )
goto V_105;
} else if ( memcmp ( V_9 , L_15 , 3 ) == 0 ) {
V_61 = sscanf ( & V_9 [ 4 ] , L_16 ,
& V_79 . V_39 [ 5 ] , & V_79 . V_39 [ 4 ] , & V_79 . V_39 [ 3 ] , & V_79 . V_39 [ 2 ] ,
& V_79 . V_39 [ 1 ] , & V_79 . V_39 [ 0 ] , & V_80 ) ;
if ( V_61 < 7 ) {
V_16 = - V_21 ;
goto V_105;
}
F_19 ( V_2 ) ;
F_84 ( V_2 , & V_79 , V_80 ) ;
F_22 ( V_2 ) ;
} else if ( memcmp ( V_9 , L_17 , 3 ) == 0 ) {
F_19 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
F_22 ( V_2 ) ;
} else {
V_16 = - V_21 ;
}
V_105:
F_88 ( V_9 ) ;
if ( V_16 )
return V_16 ;
else
return V_6 ;
}
static void F_89 ( struct V_1 * V_2 , T_5 V_106 )
{
F_90 ( L_18 , V_2 -> V_107 , V_106 ) ;
if ( V_2 -> V_108 == V_109 ) {
V_2 -> V_110 = V_106 ;
V_2 -> V_108 = V_111 ;
F_91 ( & V_2 -> V_112 ) ;
}
}
static void F_92 ( struct V_1 * V_2 , int V_16 )
{
F_90 ( L_19 , V_2 -> V_107 , V_16 ) ;
if ( V_2 -> V_108 == V_109 ) {
V_2 -> V_110 = V_16 ;
V_2 -> V_108 = V_113 ;
F_91 ( & V_2 -> V_112 ) ;
}
}
static struct V_12 * F_93 ( struct V_1 * V_2 , T_9 V_114 ,
T_5 V_3 )
{
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_12 * V_13 ;
F_19 ( V_2 ) ;
V_13 = V_2 -> V_119 ;
V_2 -> V_119 = NULL ;
F_22 ( V_2 ) ;
if ( ! V_13 )
return F_94 ( - V_120 ) ;
if ( V_13 -> V_121 < sizeof( * V_118 ) ) {
F_95 ( L_20 ) ;
goto V_122;
}
V_118 = ( void * ) V_13 -> V_26 ;
F_96 ( V_13 , V_123 ) ;
if ( V_3 ) {
if ( V_118 -> V_124 != V_3 )
goto V_122;
return V_13 ;
}
if ( V_118 -> V_124 != V_125 ) {
F_90 ( L_21 , V_118 -> V_124 ) ;
goto V_122;
}
if ( V_13 -> V_121 < sizeof( * V_116 ) ) {
F_95 ( L_22 ) ;
goto V_122;
}
V_116 = ( void * ) V_13 -> V_26 ;
F_96 ( V_13 , sizeof( * V_116 ) ) ;
if ( V_114 == F_31 ( V_116 -> V_114 ) )
return V_13 ;
F_90 ( L_23 , V_114 ,
F_31 ( V_116 -> V_114 ) ) ;
V_122:
F_16 ( V_13 ) ;
return F_94 ( - V_120 ) ;
}
struct V_12 * F_97 ( struct V_1 * V_2 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_5 V_3 , T_10 V_128 )
{
F_98 ( V_129 , V_130 ) ;
struct V_131 V_132 ;
int V_16 = 0 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_99 ( & V_132 , V_2 ) ;
F_100 ( & V_132 , V_114 , V_126 , V_127 , V_3 ) ;
V_2 -> V_108 = V_109 ;
V_16 = F_101 ( & V_132 , F_89 ) ;
if ( V_16 < 0 )
return F_94 ( V_16 ) ;
F_102 ( & V_2 -> V_112 , & V_129 ) ;
F_103 ( V_133 ) ;
F_104 ( V_128 ) ;
F_105 ( & V_2 -> V_112 , & V_129 ) ;
if ( F_106 ( V_130 ) )
return F_94 ( - V_134 ) ;
switch ( V_2 -> V_108 ) {
case V_111 :
V_16 = - F_15 ( V_2 -> V_110 ) ;
break;
case V_113 :
V_16 = - V_2 -> V_110 ;
break;
default:
V_16 = - V_135 ;
break;
}
V_2 -> V_108 = V_2 -> V_110 = 0 ;
F_90 ( L_25 , V_2 -> V_107 , V_16 ) ;
if ( V_16 < 0 )
return F_94 ( V_16 ) ;
return F_93 ( V_2 , V_114 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_10 V_128 )
{
return F_97 ( V_2 , V_114 , V_126 , V_127 , 0 , V_128 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
void (* F_108)( struct V_131 * V_132 ,
unsigned long V_136 ) ,
unsigned long V_136 , T_11 V_128 )
{
struct V_131 V_132 ;
F_98 ( V_129 , V_130 ) ;
int V_16 = 0 ;
F_90 ( L_26 , V_2 -> V_107 ) ;
F_99 ( & V_132 , V_2 ) ;
V_2 -> V_108 = V_109 ;
F_108 ( & V_132 , V_136 ) ;
V_16 = F_101 ( & V_132 , F_89 ) ;
if ( V_16 < 0 ) {
V_2 -> V_108 = 0 ;
if ( V_16 == - V_120 )
return 0 ;
return V_16 ;
}
F_102 ( & V_2 -> V_112 , & V_129 ) ;
F_103 ( V_133 ) ;
F_104 ( V_128 ) ;
F_105 ( & V_2 -> V_112 , & V_129 ) ;
if ( F_106 ( V_130 ) )
return - V_134 ;
switch ( V_2 -> V_108 ) {
case V_111 :
V_16 = - F_15 ( V_2 -> V_110 ) ;
break;
case V_113 :
V_16 = - V_2 -> V_110 ;
break;
default:
V_16 = - V_135 ;
break;
}
V_2 -> V_108 = V_2 -> V_110 = 0 ;
F_90 ( L_25 , V_2 -> V_107 , V_16 ) ;
return V_16 ;
}
static int F_109 ( struct V_1 * V_2 ,
void (* V_132)( struct V_131 * V_132 ,
unsigned long V_136 ) ,
unsigned long V_136 , T_11 V_128 )
{
int V_137 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_137 = F_107 ( V_2 , V_132 , V_136 , V_128 ) ;
F_12 ( V_2 ) ;
return V_137 ;
}
static void F_110 ( struct V_131 * V_132 , unsigned long V_136 )
{
F_90 ( L_27 , V_132 -> V_2 -> V_107 , V_136 ) ;
F_111 ( V_138 , & V_132 -> V_2 -> V_18 ) ;
F_112 ( V_132 , V_25 , 0 , NULL ) ;
}
static void F_113 ( struct V_131 * V_132 )
{
V_132 -> V_2 -> V_139 = V_140 ;
F_112 ( V_132 , V_141 , 0 , NULL ) ;
F_112 ( V_132 , V_142 , 0 , NULL ) ;
F_112 ( V_132 , V_143 , 0 , NULL ) ;
}
static void F_114 ( struct V_131 * V_132 )
{
V_132 -> V_2 -> V_139 = V_144 ;
F_112 ( V_132 , V_142 , 0 , NULL ) ;
F_112 ( V_132 , V_145 , 0 , NULL ) ;
F_112 ( V_132 , V_141 , 0 , NULL ) ;
F_112 ( V_132 , V_146 , 0 , NULL ) ;
F_112 ( V_132 , V_147 , 0 , NULL ) ;
F_112 ( V_132 , V_148 , 0 , NULL ) ;
F_112 ( V_132 , V_149 , 0 , NULL ) ;
}
static void F_115 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
F_90 ( L_27 , V_2 -> V_107 , V_136 ) ;
if ( ! F_4 ( V_150 , & V_2 -> V_151 ) )
F_110 ( V_132 , 0 ) ;
switch ( V_2 -> V_152 ) {
case V_153 :
F_113 ( V_132 ) ;
break;
case V_154 :
F_114 ( V_132 ) ;
break;
default:
F_95 ( L_28 , V_2 -> V_152 ) ;
break;
}
}
static void F_116 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_12 V_127 ;
T_7 V_155 ;
F_112 ( V_132 , V_156 , 0 , NULL ) ;
F_112 ( V_132 , V_157 , 0 , NULL ) ;
F_112 ( V_132 , V_158 , 0 , NULL ) ;
F_112 ( V_132 , V_159 , 0 , NULL ) ;
F_112 ( V_132 , V_160 , 0 , NULL ) ;
F_112 ( V_132 , V_161 , 0 , NULL ) ;
V_155 = V_162 ;
F_112 ( V_132 , V_163 , 1 , & V_155 ) ;
V_127 = F_117 ( 0x7d00 ) ;
F_112 ( V_132 , V_164 , 2 , & V_127 ) ;
if ( V_2 -> V_165 != 31 && V_2 -> V_166 > V_167 ) {
F_112 ( V_132 , V_168 , 0 , NULL ) ;
F_112 ( V_132 , V_169 , 0 , NULL ) ;
}
}
static void F_118 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
F_112 ( V_132 , V_170 , 0 , NULL ) ;
F_112 ( V_132 , V_171 , 0 , NULL ) ;
F_112 ( V_132 , V_172 , 0 , NULL ) ;
F_112 ( V_132 , V_173 , 0 , NULL ) ;
F_112 ( V_132 , V_174 , 0 , NULL ) ;
F_112 ( V_132 , V_175 , 0 , NULL ) ;
if ( ! F_119 ( V_2 ) )
F_111 ( V_176 , & V_2 -> V_11 ) ;
}
static T_5 F_120 ( struct V_1 * V_2 )
{
if ( F_121 ( V_2 ) )
return 0x02 ;
if ( F_122 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_165 == 11 && V_2 -> V_177 == 0x00 &&
V_2 -> V_178 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_165 == 15 ) {
if ( V_2 -> V_177 == 0x03 && V_2 -> V_178 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_177 == 0x09 && V_2 -> V_178 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_177 == 0x00 && V_2 -> V_178 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_165 == 31 && V_2 -> V_177 == 0x2005 &&
V_2 -> V_178 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_123 ( struct V_131 * V_132 )
{
T_5 V_69 ;
V_69 = F_120 ( V_132 -> V_2 ) ;
F_112 ( V_132 , V_179 , 1 , & V_69 ) ;
}
static void F_124 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_180 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_166 < V_181 )
return;
if ( F_119 ( V_2 ) ) {
V_180 [ 4 ] |= 0x01 ;
V_180 [ 4 ] |= 0x02 ;
V_180 [ 4 ] |= 0x04 ;
V_180 [ 5 ] |= 0x08 ;
V_180 [ 5 ] |= 0x10 ;
} else {
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_180 [ 0 ] |= 0x10 ;
V_180 [ 0 ] |= 0x80 ;
V_180 [ 1 ] |= 0x08 ;
V_180 [ 1 ] |= 0x20 ;
V_180 [ 1 ] |= 0x40 ;
V_180 [ 1 ] |= 0x80 ;
V_180 [ 2 ] |= 0x04 ;
V_180 [ 3 ] |= 0x02 ;
V_180 [ 5 ] |= 0x80 ;
}
if ( F_122 ( V_2 ) )
V_180 [ 4 ] |= 0x02 ;
if ( F_125 ( V_2 ) )
V_180 [ 5 ] |= 0x20 ;
if ( F_126 ( V_2 ) )
V_180 [ 5 ] |= 0x80 ;
if ( F_121 ( V_2 ) )
V_180 [ 5 ] |= 0x40 ;
if ( F_127 ( V_2 ) )
V_180 [ 7 ] |= 0x01 ;
if ( F_128 ( V_2 ) )
V_180 [ 6 ] |= 0x80 ;
if ( F_129 ( V_2 ) ) {
V_180 [ 6 ] |= 0x01 ;
V_180 [ 6 ] |= 0x02 ;
V_180 [ 6 ] |= 0x04 ;
V_180 [ 6 ] |= 0x08 ;
V_180 [ 6 ] |= 0x10 ;
V_180 [ 6 ] |= 0x20 ;
V_180 [ 7 ] |= 0x04 ;
V_180 [ 7 ] |= 0x08 ;
V_180 [ 7 ] |= 0x10 ;
}
if ( F_21 ( V_2 ) )
V_180 [ 7 ] |= 0x20 ;
F_112 ( V_132 , V_182 , sizeof( V_180 ) , V_180 ) ;
if ( F_21 ( V_2 ) ) {
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_180 [ 0 ] = 0x1f ;
F_112 ( V_132 , V_183 ,
sizeof( V_180 ) , V_180 ) ;
}
}
static void F_130 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( F_119 ( V_2 ) )
F_116 ( V_132 ) ;
else
F_131 ( V_184 , & V_2 -> V_11 ) ;
if ( F_21 ( V_2 ) )
F_118 ( V_132 ) ;
F_124 ( V_132 ) ;
if ( V_2 -> V_165 != 31 && V_2 -> V_166 > V_167 )
F_112 ( V_132 , V_145 , 0 , NULL ) ;
if ( F_129 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_185 , & V_2 -> V_11 ) ) {
T_5 V_69 = 0x01 ;
F_112 ( V_132 , V_186 ,
sizeof( V_69 ) , & V_69 ) ;
} else {
struct V_187 V_188 ;
memset ( V_2 -> V_189 , 0 , sizeof( V_2 -> V_189 ) ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
F_112 ( V_132 , V_190 , sizeof( V_188 ) , & V_188 ) ;
}
}
if ( F_122 ( V_2 ) )
F_123 ( V_132 ) ;
if ( F_132 ( V_2 ) )
F_112 ( V_132 , V_191 , 0 , NULL ) ;
if ( F_133 ( V_2 ) ) {
struct V_192 V_188 ;
V_188 . V_193 = 0x01 ;
F_112 ( V_132 , V_194 ,
sizeof( V_188 ) , & V_188 ) ;
}
if ( F_4 ( V_195 , & V_2 -> V_11 ) ) {
T_5 V_15 = 1 ;
F_112 ( V_132 , V_196 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_134 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_197 V_188 ;
T_9 V_198 = 0 ;
if ( F_135 ( V_2 ) )
V_198 |= V_199 ;
if ( F_136 ( V_2 ) )
V_198 |= V_200 ;
if ( F_137 ( V_2 ) )
V_198 |= V_201 ;
if ( F_138 ( V_2 ) )
V_198 |= V_202 ;
V_188 . V_203 = F_117 ( V_198 ) ;
F_112 ( V_132 , V_204 , sizeof( V_188 ) , & V_188 ) ;
}
static void F_139 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_205 V_188 ;
if ( ! F_119 ( V_2 ) )
return;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
if ( F_4 ( V_176 , & V_2 -> V_11 ) ) {
V_188 . V_206 = 0x01 ;
V_188 . V_207 = F_140 ( V_2 ) ;
}
if ( V_188 . V_206 != F_141 ( V_2 ) )
F_112 ( V_132 , V_208 , sizeof( V_188 ) ,
& V_188 ) ;
}
static void F_142 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_180 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_143 ( V_2 ) ) {
V_180 [ 1 ] |= 0x40 ;
V_180 [ 1 ] |= 0x80 ;
V_180 [ 2 ] |= 0x10 ;
V_180 [ 2 ] |= 0x20 ;
}
if ( F_144 ( V_2 ) ) {
V_180 [ 2 ] |= 0x01 ;
V_180 [ 2 ] |= 0x02 ;
V_180 [ 2 ] |= 0x04 ;
V_180 [ 2 ] |= 0x08 ;
}
if ( F_145 ( V_2 ) )
V_180 [ 2 ] |= 0x80 ;
F_112 ( V_132 , V_209 , sizeof( V_180 ) , V_180 ) ;
}
static void F_146 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_31 ;
if ( V_2 -> V_210 [ 6 ] & 0x80 &&
! F_4 ( V_211 , & V_2 -> V_151 ) ) {
struct V_212 V_188 ;
F_147 ( & V_188 . V_40 , V_213 ) ;
V_188 . V_214 = 0x01 ;
F_112 ( V_132 , V_215 ,
sizeof( V_188 ) , & V_188 ) ;
}
if ( V_2 -> V_210 [ 5 ] & 0x10 )
F_134 ( V_132 ) ;
if ( F_21 ( V_2 ) )
F_139 ( V_132 ) ;
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_192 V_188 ;
V_188 . V_193 = V_31 ;
F_112 ( V_132 , V_194 ,
sizeof( V_188 ) , & V_188 ) ;
}
}
static void F_148 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( V_2 -> V_210 [ 22 ] & 0x04 )
F_142 ( V_132 ) ;
if ( F_149 ( V_2 ) )
F_112 ( V_132 , V_216 , 0 , NULL ) ;
if ( ( F_150 ( V_2 ) ||
F_4 ( V_72 , & V_2 -> V_11 ) ) &&
F_4 ( V_217 , & V_2 -> V_11 ) ) {
T_5 V_218 = 0x01 ;
F_112 ( V_132 , V_219 ,
sizeof( V_218 ) , & V_218 ) ;
}
}
static int F_151 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_107 ( V_2 , F_115 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_221 , & V_2 -> V_11 ) ) {
F_152 ( L_29 , 0644 , V_2 -> V_222 , V_2 ,
& V_223 ) ;
}
if ( V_2 -> V_152 != V_153 )
return 0 ;
V_16 = F_107 ( V_2 , F_130 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_107 ( V_2 , F_146 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_107 ( V_2 , F_148 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) )
return 0 ;
F_152 ( L_30 , 0444 , V_2 -> V_222 , V_2 ,
& V_224 ) ;
F_153 ( L_31 , 0444 , V_2 -> V_222 ,
& V_2 -> V_165 ) ;
F_154 ( L_32 , 0444 , V_2 -> V_222 , & V_2 -> V_166 ) ;
F_153 ( L_33 , 0444 , V_2 -> V_222 , & V_2 -> V_177 ) ;
F_152 ( L_34 , 0444 , V_2 -> V_222 , V_2 ,
& V_225 ) ;
F_152 ( L_35 , 0444 , V_2 -> V_222 , V_2 , & V_226 ) ;
if ( F_119 ( V_2 ) ) {
F_152 ( L_36 , 0444 , V_2 -> V_222 ,
V_2 , & V_227 ) ;
F_152 ( L_37 , 0400 , V_2 -> V_222 ,
V_2 , & V_228 ) ;
F_152 ( L_38 , 0444 , V_2 -> V_222 ,
V_2 , & V_229 ) ;
F_152 ( L_39 , 0444 , V_2 -> V_222 ,
V_2 , & V_230 ) ;
}
if ( F_129 ( V_2 ) ) {
F_152 ( L_40 , 0644 , V_2 -> V_222 ,
V_2 , & V_231 ) ;
F_152 ( L_41 , 0644 , V_2 -> V_222 ,
V_2 , & V_232 ) ;
F_152 ( L_42 , 0644 , V_2 -> V_222 ,
V_2 , & V_233 ) ;
F_152 ( L_43 , 0444 , V_2 -> V_222 ,
V_2 , & V_234 ) ;
}
if ( F_137 ( V_2 ) ) {
F_152 ( L_44 , 0644 , V_2 -> V_222 ,
V_2 , & V_235 ) ;
F_152 ( L_45 , 0644 , V_2 -> V_222 ,
V_2 , & V_236 ) ;
F_152 ( L_46 , 0644 , V_2 -> V_222 ,
V_2 , & V_237 ) ;
}
if ( F_21 ( V_2 ) ) {
F_152 ( L_47 , 0400 , V_2 -> V_222 ,
V_2 , & V_238 ) ;
F_152 ( L_48 , 0644 , V_2 -> V_222 ,
V_2 , & V_239 ) ;
F_152 ( L_49 , 0444 , V_2 -> V_222 ,
V_2 , & V_240 ) ;
F_152 ( L_50 , 0444 , V_2 -> V_222 ,
V_2 , & V_241 ) ;
if ( F_155 ( & V_2 -> V_40 , V_213 ) )
F_152 ( L_51 , 0644 ,
V_2 -> V_222 , V_2 ,
& V_242 ) ;
F_154 ( L_52 , 0444 , V_2 -> V_222 ,
& V_2 -> V_243 ) ;
F_152 ( L_53 , 0444 , V_2 -> V_222 , V_2 ,
& V_244 ) ;
F_152 ( L_54 , 0400 ,
V_2 -> V_222 , V_2 ,
& V_245 ) ;
F_152 ( L_55 , 0400 , V_2 -> V_222 ,
V_2 , & V_246 ) ;
F_152 ( L_56 , 0644 , V_2 -> V_222 ,
V_2 , & V_247 ) ;
F_152 ( L_57 , 0644 , V_2 -> V_222 ,
V_2 , & V_248 ) ;
F_152 ( L_58 , 0644 , V_2 -> V_222 ,
V_2 , & V_249 ) ;
F_152 ( L_59 , 0644 , V_2 -> V_222 , V_2 ,
& V_250 ) ;
F_152 ( L_60 , 0644 , V_2 -> V_222 , V_2 ,
& V_251 ) ;
}
return 0 ;
}
static void F_156 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_252 = V_136 ;
F_90 ( L_61 , V_132 -> V_2 -> V_107 , V_252 ) ;
F_112 ( V_132 , V_253 , 1 , & V_252 ) ;
}
static void F_157 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_254 = V_136 ;
F_90 ( L_61 , V_132 -> V_2 -> V_107 , V_254 ) ;
F_112 ( V_132 , V_196 , 1 , & V_254 ) ;
}
static void F_158 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_255 = V_136 ;
F_90 ( L_61 , V_132 -> V_2 -> V_107 , V_255 ) ;
F_112 ( V_132 , V_256 , 1 , & V_255 ) ;
}
static void F_159 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_12 V_203 = F_117 ( V_136 ) ;
F_90 ( L_61 , V_132 -> V_2 -> V_107 , V_203 ) ;
F_112 ( V_132 , V_204 , 2 , & V_203 ) ;
}
struct V_1 * F_160 ( int V_257 )
{
struct V_1 * V_2 = NULL , * V_258 ;
F_90 ( L_62 , V_257 ) ;
if ( V_257 < 0 )
return NULL ;
F_161 ( & V_259 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_258 -> V_260 == V_257 ) {
V_2 = F_162 ( V_258 ) ;
break;
}
}
F_163 ( & V_259 ) ;
return V_2 ;
}
bool F_164 ( struct V_1 * V_2 )
{
struct V_46 * V_261 = & V_2 -> V_48 ;
switch ( V_261 -> V_262 ) {
case V_263 :
case V_264 :
return true ;
default:
return false ;
}
}
void F_165 ( struct V_1 * V_2 , int V_262 )
{
F_90 ( L_63 , V_2 -> V_107 , V_2 -> V_48 . V_262 , V_262 ) ;
if ( V_2 -> V_48 . V_262 == V_262 )
return;
switch ( V_262 ) {
case V_265 :
F_87 ( V_2 ) ;
if ( V_2 -> V_48 . V_262 != V_266 )
F_166 ( V_2 , 0 ) ;
break;
case V_266 :
break;
case V_263 :
F_166 ( V_2 , 1 ) ;
break;
case V_264 :
break;
case V_267 :
break;
}
V_2 -> V_48 . V_262 = V_262 ;
}
void F_167 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_61 ;
F_168 (p, n, &cache->all, all) {
F_169 ( & V_31 -> V_268 ) ;
F_88 ( V_31 ) ;
}
F_170 ( & V_47 -> V_269 ) ;
F_170 ( & V_47 -> V_270 ) ;
}
struct V_49 * F_171 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_90 ( L_64 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_155 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_172 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_90 ( L_64 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_155 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_173 ( struct V_1 * V_2 ,
T_8 * V_40 ,
int V_262 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_90 ( L_65 , V_47 , V_40 , V_262 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_155 ( V_40 , V_213 ) && V_50 -> V_271 == V_262 )
return V_50 ;
if ( ! F_155 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_174 ( struct V_1 * V_2 ,
struct V_49 * V_272 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_60 * V_273 = & V_47 -> V_270 ;
struct V_49 * V_31 ;
F_169 ( & V_272 -> V_64 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_271 != V_274 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_272 -> V_26 . V_57 ) )
break;
V_273 = & V_31 -> V_64 ;
}
F_175 ( & V_272 -> V_64 , V_273 ) ;
}
bool F_176 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_275 , bool * V_276 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_272 ;
F_90 ( L_64 , V_47 , & V_26 -> V_40 ) ;
F_177 ( V_2 , & V_26 -> V_40 ) ;
if ( V_276 )
* V_276 = V_26 -> V_58 ;
V_272 = F_171 ( V_2 , & V_26 -> V_40 ) ;
if ( V_272 ) {
if ( V_272 -> V_26 . V_58 && V_276 )
* V_276 = true ;
if ( V_272 -> V_271 == V_277 &&
V_26 -> V_57 != V_272 -> V_26 . V_57 ) {
V_272 -> V_26 . V_57 = V_26 -> V_57 ;
F_174 ( V_2 , V_272 ) ;
}
goto V_278;
}
V_272 = F_82 ( sizeof( struct V_49 ) , V_279 ) ;
if ( ! V_272 )
return false ;
F_175 ( & V_272 -> V_268 , & V_47 -> V_268 ) ;
if ( V_275 ) {
V_272 -> V_271 = V_280 ;
} else {
V_272 -> V_271 = V_281 ;
F_175 ( & V_272 -> V_64 , & V_47 -> V_269 ) ;
}
V_278:
if ( V_275 && V_272 -> V_271 != V_280 &&
V_272 -> V_271 != V_274 ) {
V_272 -> V_271 = V_280 ;
F_169 ( & V_272 -> V_64 ) ;
}
memcpy ( & V_272 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_272 -> V_59 = V_282 ;
V_47 -> V_59 = V_282 ;
if ( V_272 -> V_271 == V_281 )
return false ;
return true ;
}
static int F_178 ( struct V_1 * V_2 , int V_283 , T_7 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_284 * V_285 = (struct V_284 * ) V_9 ;
struct V_49 * V_50 ;
int V_286 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_286 >= V_283 )
break;
F_147 ( & V_285 -> V_40 , & V_26 -> V_40 ) ;
V_285 -> V_52 = V_26 -> V_52 ;
V_285 -> V_53 = V_26 -> V_53 ;
V_285 -> V_54 = V_26 -> V_54 ;
memcpy ( V_285 -> V_55 , V_26 -> V_55 , 3 ) ;
V_285 -> V_56 = V_26 -> V_56 ;
V_285 ++ ;
V_286 ++ ;
}
F_90 ( L_66 , V_47 , V_286 ) ;
return V_286 ;
}
static void F_179 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_287 * V_288 = (struct V_287 * ) V_136 ;
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_289 V_188 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( F_4 ( V_290 , & V_2 -> V_18 ) )
return;
memcpy ( & V_188 . V_291 , & V_288 -> V_291 , 3 ) ;
V_188 . V_292 = V_288 -> V_292 ;
V_188 . V_293 = V_288 -> V_293 ;
F_112 ( V_132 , V_294 , sizeof( V_188 ) , & V_188 ) ;
}
static int F_180 ( void * V_295 )
{
F_181 () ;
return F_106 ( V_130 ) ;
}
int F_182 ( void T_2 * V_296 )
{
T_7 T_2 * V_29 = V_296 ;
struct V_287 V_288 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_297 = 0 , V_298 ;
long V_299 ;
T_7 * V_9 ;
if ( F_8 ( & V_288 , V_29 , sizeof( V_288 ) ) )
return - V_20 ;
V_2 = F_160 ( V_288 . V_300 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_4 ( V_302 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( V_2 -> V_152 != V_153 ) {
V_16 = - V_303 ;
goto V_105;
}
if ( ! F_4 ( V_184 , & V_2 -> V_11 ) ) {
V_16 = - V_303 ;
goto V_105;
}
F_19 ( V_2 ) ;
if ( F_183 ( V_2 ) > V_304 ||
F_184 ( V_2 ) || V_288 . V_18 & V_305 ) {
F_167 ( V_2 ) ;
V_297 = 1 ;
}
F_22 ( V_2 ) ;
V_299 = V_288 . V_292 * F_185 ( 2000 ) ;
if ( V_297 ) {
V_16 = F_109 ( V_2 , F_179 , ( unsigned long ) & V_288 ,
V_299 ) ;
if ( V_16 < 0 )
goto V_105;
if ( F_186 ( & V_2 -> V_18 , V_290 , F_180 ,
V_133 ) )
return - V_134 ;
}
V_298 = ( V_288 . V_293 == 0 ) ? 255 : V_288 . V_293 ;
V_9 = F_187 ( sizeof( struct V_284 ) * V_298 , V_103 ) ;
if ( ! V_9 ) {
V_16 = - V_104 ;
goto V_105;
}
F_19 ( V_2 ) ;
V_288 . V_293 = F_178 ( V_2 , V_298 , V_9 ) ;
F_22 ( V_2 ) ;
F_90 ( L_67 , V_288 . V_293 ) ;
if ( ! F_188 ( V_29 , & V_288 , sizeof( V_288 ) ) ) {
V_29 += sizeof( V_288 ) ;
if ( F_188 ( V_29 , V_9 , sizeof( struct V_284 ) *
V_288 . V_293 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_88 ( V_9 ) ;
V_105:
F_189 ( V_2 ) ;
return V_16 ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_137 = 0 ;
F_90 ( L_68 , V_2 -> V_107 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_306 , & V_2 -> V_11 ) ) {
V_137 = - V_301 ;
goto V_105;
}
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) ) {
if ( F_4 ( V_307 , & V_2 -> V_11 ) ) {
V_137 = - V_308 ;
goto V_105;
}
if ( ! F_4 ( V_302 , & V_2 -> V_11 ) &&
V_2 -> V_152 == V_153 &&
! F_155 ( & V_2 -> V_40 , V_213 ) &&
! F_155 ( & V_2 -> V_84 , V_213 ) ) {
V_137 = - V_309 ;
goto V_105;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_137 = - V_22 ;
goto V_105;
}
if ( V_2 -> V_310 ( V_2 ) ) {
V_137 = - V_311 ;
goto V_105;
}
F_191 ( & V_2 -> V_312 , 1 ) ;
F_111 ( V_313 , & V_2 -> V_18 ) ;
if ( V_2 -> V_314 && F_4 ( V_221 , & V_2 -> V_11 ) )
V_137 = V_2 -> V_314 ( V_2 ) ;
if ( ! V_137 ) {
if ( F_4 ( V_315 , & V_2 -> V_151 ) )
F_111 ( V_316 , & V_2 -> V_18 ) ;
if ( ! F_4 ( V_316 , & V_2 -> V_18 ) &&
! F_4 ( V_302 , & V_2 -> V_11 ) )
V_137 = F_151 ( V_2 ) ;
}
F_131 ( V_313 , & V_2 -> V_18 ) ;
if ( ! V_137 ) {
F_162 ( V_2 ) ;
F_111 ( V_317 , & V_2 -> V_11 ) ;
F_111 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_318 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) &&
! F_4 ( V_302 , & V_2 -> V_11 ) &&
V_2 -> V_152 == V_153 ) {
F_19 ( V_2 ) ;
F_192 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_193 ( & V_2 -> V_319 ) ;
F_193 ( & V_2 -> V_320 ) ;
F_193 ( & V_2 -> V_321 ) ;
F_194 ( & V_2 -> V_322 ) ;
F_194 ( & V_2 -> V_323 ) ;
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_2 ) ;
if ( V_2 -> V_325 ) {
F_16 ( V_2 -> V_325 ) ;
V_2 -> V_325 = NULL ;
}
V_2 -> V_326 ( V_2 ) ;
V_2 -> V_18 = 0 ;
}
V_105:
F_12 ( V_2 ) ;
return V_137 ;
}
int F_195 ( T_13 V_327 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_160 ( V_327 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_196 ( V_328 , & V_2 -> V_11 ) )
F_197 ( & V_2 -> V_329 ) ;
F_198 ( V_2 -> V_330 ) ;
V_16 = F_190 ( V_2 ) ;
F_189 ( V_2 ) ;
return V_16 ;
}
static int F_199 ( struct V_1 * V_2 )
{
F_90 ( L_68 , V_2 -> V_107 , V_2 ) ;
F_197 ( & V_2 -> V_329 ) ;
F_92 ( V_2 , V_301 ) ;
F_10 ( V_2 ) ;
if ( ! F_196 ( V_17 , & V_2 -> V_18 ) ) {
F_200 ( & V_2 -> V_331 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_193 ( & V_2 -> V_319 ) ;
F_193 ( & V_2 -> V_321 ) ;
if ( V_2 -> V_332 > 0 ) {
F_197 ( & V_2 -> V_333 ) ;
V_2 -> V_332 = 0 ;
F_131 ( V_334 , & V_2 -> V_11 ) ;
F_131 ( V_335 , & V_2 -> V_11 ) ;
}
if ( F_196 ( V_336 , & V_2 -> V_11 ) )
F_197 ( & V_2 -> V_337 ) ;
F_201 ( & V_2 -> V_338 ) ;
if ( F_4 ( V_339 , & V_2 -> V_11 ) )
F_201 ( & V_2 -> V_340 ) ;
F_19 ( V_2 ) ;
F_167 ( V_2 ) ;
F_202 ( V_2 ) ;
F_86 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_341 ) ;
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_2 ) ;
F_194 ( & V_2 -> V_322 ) ;
F_191 ( & V_2 -> V_312 , 1 ) ;
if ( ! F_4 ( V_316 , & V_2 -> V_18 ) &&
! F_4 ( V_328 , & V_2 -> V_11 ) &&
F_4 ( V_150 , & V_2 -> V_151 ) ) {
F_111 ( V_313 , & V_2 -> V_18 ) ;
F_107 ( V_2 , F_110 , 0 , V_24 ) ;
F_131 ( V_313 , & V_2 -> V_18 ) ;
}
F_193 ( & V_2 -> V_320 ) ;
F_194 ( & V_2 -> V_323 ) ;
F_194 ( & V_2 -> V_322 ) ;
F_194 ( & V_2 -> V_342 ) ;
if ( V_2 -> V_325 ) {
F_200 ( & V_2 -> V_331 ) ;
F_16 ( V_2 -> V_325 ) ;
V_2 -> V_325 = NULL ;
}
F_16 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
V_2 -> V_326 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_11 &= ~ V_343 ;
if ( ! F_196 ( V_328 , & V_2 -> V_11 ) ) {
if ( V_2 -> V_152 == V_153 ) {
F_19 ( V_2 ) ;
F_192 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
}
}
V_2 -> V_344 = V_345 ;
memset ( V_2 -> V_189 , 0 , sizeof( V_2 -> V_189 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_147 ( & V_2 -> V_83 , V_213 ) ;
F_12 ( V_2 ) ;
F_189 ( V_2 ) ;
return 0 ;
}
int F_203 ( T_13 V_327 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_160 ( V_327 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_4 ( V_302 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( F_196 ( V_328 , & V_2 -> V_11 ) )
F_197 ( & V_2 -> V_329 ) ;
V_16 = F_199 ( V_2 ) ;
V_105:
F_189 ( V_2 ) ;
return V_16 ;
}
int F_204 ( T_13 V_327 )
{
struct V_1 * V_2 ;
int V_137 = 0 ;
V_2 = F_160 ( V_327 ) ;
if ( ! V_2 )
return - V_301 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_137 = - V_19 ;
goto V_105;
}
if ( F_4 ( V_302 , & V_2 -> V_11 ) ) {
V_137 = - V_73 ;
goto V_105;
}
F_194 ( & V_2 -> V_323 ) ;
F_194 ( & V_2 -> V_322 ) ;
F_19 ( V_2 ) ;
F_167 ( V_2 ) ;
F_202 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_324 )
V_2 -> V_324 ( V_2 ) ;
F_191 ( & V_2 -> V_312 , 1 ) ;
V_2 -> V_346 = 0 ; V_2 -> V_347 = 0 ; V_2 -> V_348 = 0 ;
if ( ! F_4 ( V_316 , & V_2 -> V_18 ) )
V_137 = F_107 ( V_2 , F_110 , 0 , V_220 ) ;
V_105:
F_12 ( V_2 ) ;
F_189 ( V_2 ) ;
return V_137 ;
}
int F_205 ( T_13 V_327 )
{
struct V_1 * V_2 ;
int V_137 = 0 ;
V_2 = F_160 ( V_327 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_4 ( V_302 , & V_2 -> V_11 ) ) {
V_137 = - V_73 ;
goto V_105;
}
memset ( & V_2 -> V_349 , 0 , sizeof( struct V_350 ) ) ;
V_105:
F_189 ( V_2 ) ;
return V_137 ;
}
int F_206 ( unsigned int V_351 , void T_2 * V_296 )
{
struct V_1 * V_2 ;
struct V_352 V_353 ;
int V_16 = 0 ;
if ( F_8 ( & V_353 , V_296 , sizeof( V_353 ) ) )
return - V_20 ;
V_2 = F_160 ( V_353 . V_300 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_4 ( V_302 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( V_2 -> V_152 != V_153 ) {
V_16 = - V_303 ;
goto V_105;
}
if ( ! F_4 ( V_184 , & V_2 -> V_11 ) ) {
V_16 = - V_303 ;
goto V_105;
}
switch ( V_351 ) {
case V_354 :
V_16 = F_109 ( V_2 , F_157 , V_353 . V_355 ,
V_220 ) ;
break;
case V_356 :
if ( ! F_207 ( V_2 ) ) {
V_16 = - V_303 ;
break;
}
if ( ! F_4 ( V_357 , & V_2 -> V_18 ) ) {
V_16 = F_109 ( V_2 , F_157 , V_353 . V_355 ,
V_220 ) ;
if ( V_16 )
break;
}
V_16 = F_109 ( V_2 , F_158 , V_353 . V_355 ,
V_220 ) ;
break;
case V_358 :
V_16 = F_109 ( V_2 , F_156 , V_353 . V_355 ,
V_220 ) ;
break;
case V_359 :
V_16 = F_109 ( V_2 , F_159 , V_353 . V_355 ,
V_220 ) ;
break;
case V_360 :
V_2 -> V_361 = ( ( T_13 ) V_353 . V_355 ) &
( V_362 | V_363 ) ;
break;
case V_364 :
V_2 -> V_365 = ( T_13 ) V_353 . V_355 ;
break;
case V_366 :
V_2 -> V_367 = * ( ( T_13 * ) & V_353 . V_355 + 1 ) ;
V_2 -> V_368 = * ( ( T_13 * ) & V_353 . V_355 + 0 ) ;
break;
case V_369 :
V_2 -> V_370 = * ( ( T_13 * ) & V_353 . V_355 + 1 ) ;
V_2 -> V_371 = * ( ( T_13 * ) & V_353 . V_355 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_105:
F_189 ( V_2 ) ;
return V_16 ;
}
int F_208 ( void T_2 * V_296 )
{
struct V_1 * V_2 ;
struct V_372 * V_373 ;
struct V_352 * V_353 ;
int V_61 = 0 , V_374 , V_16 ;
T_13 V_375 ;
if ( F_209 ( V_375 , ( T_13 T_2 * ) V_296 ) )
return - V_20 ;
if ( ! V_375 || V_375 > ( V_376 * 2 ) / sizeof( * V_353 ) )
return - V_21 ;
V_374 = sizeof( * V_373 ) + V_375 * sizeof( * V_353 ) ;
V_373 = F_82 ( V_374 , V_103 ) ;
if ( ! V_373 )
return - V_104 ;
V_353 = V_373 -> V_377 ;
F_161 ( & V_259 ) ;
F_26 (hdev, &hci_dev_list, list) {
if ( F_196 ( V_328 , & V_2 -> V_11 ) )
F_197 ( & V_2 -> V_329 ) ;
if ( ! F_4 ( V_339 , & V_2 -> V_11 ) )
F_111 ( V_378 , & V_2 -> V_11 ) ;
( V_353 + V_61 ) -> V_300 = V_2 -> V_260 ;
( V_353 + V_61 ) -> V_355 = V_2 -> V_18 ;
if ( ++ V_61 >= V_375 )
break;
}
F_163 ( & V_259 ) ;
V_373 -> V_375 = V_61 ;
V_374 = sizeof( * V_373 ) + V_61 * sizeof( * V_353 ) ;
V_16 = F_188 ( V_296 , V_373 , V_374 ) ;
F_88 ( V_373 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_210 ( void T_2 * V_296 )
{
struct V_1 * V_2 ;
struct V_379 V_380 ;
int V_16 = 0 ;
if ( F_8 ( & V_380 , V_296 , sizeof( V_380 ) ) )
return - V_20 ;
V_2 = F_160 ( V_380 . V_300 ) ;
if ( ! V_2 )
return - V_301 ;
if ( F_196 ( V_328 , & V_2 -> V_11 ) )
F_201 ( & V_2 -> V_329 ) ;
if ( ! F_4 ( V_339 , & V_2 -> V_11 ) )
F_111 ( V_378 , & V_2 -> V_11 ) ;
strcpy ( V_380 . V_107 , V_2 -> V_107 ) ;
V_380 . V_40 = V_2 -> V_40 ;
V_380 . type = ( V_2 -> V_381 & 0x0f ) | ( ( V_2 -> V_152 & 0x03 ) << 4 ) ;
V_380 . V_18 = V_2 -> V_18 ;
V_380 . V_365 = V_2 -> V_365 ;
if ( F_119 ( V_2 ) ) {
V_380 . V_367 = V_2 -> V_367 ;
V_380 . V_368 = V_2 -> V_368 ;
V_380 . V_370 = V_2 -> V_370 ;
V_380 . V_371 = V_2 -> V_371 ;
} else {
V_380 . V_367 = V_2 -> V_382 ;
V_380 . V_368 = V_2 -> V_383 ;
V_380 . V_370 = 0 ;
V_380 . V_371 = 0 ;
}
V_380 . V_198 = V_2 -> V_198 ;
V_380 . V_361 = V_2 -> V_361 ;
memcpy ( & V_380 . V_349 , & V_2 -> V_349 , sizeof( V_380 . V_349 ) ) ;
memcpy ( & V_380 . V_34 , & V_2 -> V_34 , sizeof( V_380 . V_34 ) ) ;
if ( F_188 ( V_296 , & V_380 , sizeof( V_380 ) ) )
V_16 = - V_20 ;
F_189 ( V_2 ) ;
return V_16 ;
}
static int F_211 ( void * V_26 , bool V_384 )
{
struct V_1 * V_2 = V_26 ;
F_90 ( L_69 , V_2 , V_2 -> V_107 , V_384 ) ;
if ( F_4 ( V_302 , & V_2 -> V_11 ) )
return - V_73 ;
if ( V_384 ) {
F_111 ( V_307 , & V_2 -> V_11 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) )
F_199 ( V_2 ) ;
} else {
F_131 ( V_307 , & V_2 -> V_11 ) ;
}
return 0 ;
}
static void F_212 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 , V_387 ) ;
int V_16 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
V_16 = F_190 ( V_2 ) ;
if ( V_16 < 0 ) {
F_214 ( V_2 , V_16 ) ;
return;
}
if ( F_4 ( V_307 , & V_2 -> V_11 ) ||
( V_2 -> V_152 == V_153 &&
! F_155 ( & V_2 -> V_40 , V_213 ) &&
! F_155 ( & V_2 -> V_84 , V_213 ) ) ) {
F_131 ( V_328 , & V_2 -> V_11 ) ;
F_199 ( V_2 ) ;
} else if ( F_4 ( V_328 , & V_2 -> V_11 ) ) {
F_215 ( V_2 -> V_330 , & V_2 -> V_329 ,
V_388 ) ;
}
if ( F_196 ( V_221 , & V_2 -> V_11 ) )
F_216 ( V_2 ) ;
}
static void F_217 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 ,
V_329 . V_386 ) ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_199 ( V_2 ) ;
}
static void F_218 ( struct V_385 * V_386 )
{
struct V_1 * V_2 ;
V_2 = F_213 ( V_386 , struct V_1 , V_333 . V_386 ) ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_219 ( V_2 ) ;
}
void F_220 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_389 ;
F_168 (uuid, tmp, &hdev->uuids, list) {
F_169 ( & V_43 -> V_64 ) ;
F_88 ( V_43 ) ;
}
}
void F_221 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 ;
V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_169 ( V_31 ) ;
F_88 ( V_63 ) ;
}
}
void F_222 ( struct V_1 * V_2 )
{
struct V_87 * V_390 , * V_389 ;
F_168 (k, tmp, &hdev->long_term_keys, list) {
F_169 ( & V_390 -> V_64 ) ;
F_88 ( V_390 ) ;
}
}
void F_223 ( struct V_1 * V_2 )
{
struct V_86 * V_390 , * V_389 ;
F_168 (k, tmp, &hdev->identity_resolving_keys, list) {
F_169 ( & V_390 -> V_64 ) ;
F_88 ( V_390 ) ;
}
}
struct V_62 * F_224 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_62 * V_390 ;
F_26 (k, &hdev->link_keys, list)
if ( F_155 ( V_40 , & V_390 -> V_40 ) == 0 )
return V_390 ;
return NULL ;
}
static bool F_225 ( struct V_1 * V_2 , struct V_391 * V_392 ,
T_5 V_393 , T_5 V_394 )
{
if ( V_393 < 0x03 )
return true ;
if ( V_393 == V_395 )
return false ;
if ( V_393 == V_396 && V_394 == 0xff )
return false ;
if ( ! V_392 )
return true ;
if ( V_392 -> V_397 > 0x01 && V_392 -> V_398 > 0x01 )
return true ;
if ( V_392 -> V_397 == 0x02 || V_392 -> V_397 == 0x03 )
return true ;
if ( V_392 -> V_398 == 0x02 || V_392 -> V_398 == 0x03 )
return true ;
return false ;
}
static bool F_226 ( T_5 type )
{
if ( type == V_399 || type == V_400 )
return true ;
return false ;
}
struct V_87 * F_227 ( struct V_1 * V_2 , T_12 V_91 , T_14 rand ,
bool V_401 )
{
struct V_87 * V_390 ;
F_26 (k, &hdev->long_term_keys, list) {
if ( V_390 -> V_91 != V_91 || V_390 -> rand != rand )
continue;
if ( F_226 ( V_390 -> type ) != V_401 )
continue;
return V_390 ;
}
return NULL ;
}
struct V_87 * F_228 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_80 , bool V_401 )
{
struct V_87 * V_390 ;
F_26 (k, &hdev->long_term_keys, list)
if ( V_80 == V_390 -> V_41 &&
F_155 ( V_40 , & V_390 -> V_40 ) == 0 &&
F_226 ( V_390 -> type ) == V_401 )
return V_390 ;
return NULL ;
}
struct V_86 * F_229 ( struct V_1 * V_2 , T_8 * V_82 )
{
struct V_86 * V_81 ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_155 ( & V_81 -> V_82 , V_82 ) )
return V_81 ;
}
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( F_230 ( V_2 -> V_402 , V_81 -> V_45 , V_82 ) ) {
F_147 ( & V_81 -> V_82 , V_82 ) ;
return V_81 ;
}
}
return NULL ;
}
struct V_86 * F_231 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_80 )
{
struct V_86 * V_81 ;
if ( V_80 == V_403 && ( V_40 -> V_39 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( V_80 == V_81 -> V_80 &&
F_155 ( V_40 , & V_81 -> V_40 ) == 0 )
return V_81 ;
}
return NULL ;
}
int F_232 ( struct V_1 * V_2 , struct V_391 * V_392 , int V_404 ,
T_8 * V_40 , T_5 * V_45 , T_5 type , T_5 V_66 )
{
struct V_62 * V_63 , * V_405 ;
T_5 V_394 ;
bool V_406 ;
V_405 = F_224 ( V_2 , V_40 ) ;
if ( V_405 ) {
V_394 = V_405 -> type ;
V_63 = V_405 ;
} else {
V_394 = V_392 ? V_392 -> V_393 : 0xff ;
V_63 = F_82 ( sizeof( * V_63 ) , V_103 ) ;
if ( ! V_63 )
return - V_104 ;
F_175 ( & V_63 -> V_64 , & V_2 -> V_407 ) ;
}
F_90 ( L_70 , V_2 -> V_107 , V_40 , type ) ;
if ( type == V_396 &&
( ! V_392 || V_392 -> V_398 == 0xff ) && V_394 == 0xff ) {
type = V_408 ;
if ( V_392 )
V_392 -> V_393 = type ;
}
F_147 ( & V_63 -> V_40 , V_40 ) ;
memcpy ( V_63 -> V_45 , V_45 , V_65 ) ;
V_63 -> V_66 = V_66 ;
if ( type == V_396 )
V_63 -> type = V_394 ;
else
V_63 -> type = type ;
if ( ! V_404 )
return 0 ;
V_406 = F_225 ( V_2 , V_392 , type , V_394 ) ;
F_233 ( V_2 , V_63 , V_406 ) ;
if ( V_392 )
V_392 -> V_409 = ! V_406 ;
return 0 ;
}
struct V_87 * F_234 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_80 , T_5 type , T_5 V_89 ,
T_5 V_410 [ 16 ] , T_5 V_90 , T_12 V_91 , T_14 rand )
{
struct V_87 * V_63 , * V_405 ;
bool V_401 = F_226 ( type ) ;
V_405 = F_228 ( V_2 , V_40 , V_80 , V_401 ) ;
if ( V_405 )
V_63 = V_405 ;
else {
V_63 = F_82 ( sizeof( * V_63 ) , V_103 ) ;
if ( ! V_63 )
return NULL ;
F_175 ( & V_63 -> V_64 , & V_2 -> V_411 ) ;
}
F_147 ( & V_63 -> V_40 , V_40 ) ;
V_63 -> V_41 = V_80 ;
memcpy ( V_63 -> V_45 , V_410 , sizeof( V_63 -> V_45 ) ) ;
V_63 -> V_89 = V_89 ;
V_63 -> V_91 = V_91 ;
V_63 -> rand = rand ;
V_63 -> V_90 = V_90 ;
V_63 -> type = type ;
return V_63 ;
}
struct V_86 * F_235 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_80 , T_5 V_45 [ 16 ] , T_8 * V_82 )
{
struct V_86 * V_81 ;
V_81 = F_231 ( V_2 , V_40 , V_80 ) ;
if ( ! V_81 ) {
V_81 = F_82 ( sizeof( * V_81 ) , V_103 ) ;
if ( ! V_81 )
return NULL ;
F_147 ( & V_81 -> V_40 , V_40 ) ;
V_81 -> V_80 = V_80 ;
F_175 ( & V_81 -> V_64 , & V_2 -> V_412 ) ;
}
memcpy ( V_81 -> V_45 , V_45 , 16 ) ;
F_147 ( & V_81 -> V_82 , V_82 ) ;
return V_81 ;
}
int F_236 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_62 * V_63 ;
V_63 = F_224 ( V_2 , V_40 ) ;
if ( ! V_63 )
return - V_413 ;
F_90 ( L_71 , V_2 -> V_107 , V_40 ) ;
F_169 ( & V_63 -> V_64 ) ;
F_88 ( V_63 ) ;
return 0 ;
}
int F_237 ( struct V_1 * V_2 , T_8 * V_40 , T_5 V_41 )
{
struct V_87 * V_390 , * V_389 ;
int V_414 = 0 ;
F_168 (k, tmp, &hdev->long_term_keys, list) {
if ( F_155 ( V_40 , & V_390 -> V_40 ) || V_390 -> V_41 != V_41 )
continue;
F_90 ( L_71 , V_2 -> V_107 , V_40 ) ;
F_169 ( & V_390 -> V_64 ) ;
F_88 ( V_390 ) ;
V_414 ++ ;
}
return V_414 ? 0 : - V_413 ;
}
void F_238 ( struct V_1 * V_2 , T_8 * V_40 , T_5 V_80 )
{
struct V_86 * V_390 , * V_389 ;
F_168 (k, tmp, &hdev->identity_resolving_keys, list) {
if ( F_155 ( V_40 , & V_390 -> V_40 ) || V_390 -> V_80 != V_80 )
continue;
F_90 ( L_71 , V_2 -> V_107 , V_40 ) ;
F_169 ( & V_390 -> V_64 ) ;
F_88 ( V_390 ) ;
}
}
static void F_239 ( unsigned long V_296 )
{
struct V_1 * V_2 = ( void * ) V_296 ;
if ( V_2 -> V_325 ) {
struct V_415 * V_416 = ( void * ) V_2 -> V_325 -> V_26 ;
T_9 V_114 = F_31 ( V_416 -> V_114 ) ;
F_95 ( L_72 , V_2 -> V_107 , V_114 ) ;
} else {
F_95 ( L_73 , V_2 -> V_107 ) ;
}
F_191 ( & V_2 -> V_312 , 1 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_320 ) ;
}
struct V_418 * F_241 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_418 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list)
if ( F_155 ( V_40 , & V_26 -> V_40 ) == 0 )
return V_26 ;
return NULL ;
}
int F_177 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_418 * V_26 ;
V_26 = F_241 ( V_2 , V_40 ) ;
if ( ! V_26 )
return - V_413 ;
F_90 ( L_71 , V_2 -> V_107 , V_40 ) ;
F_169 ( & V_26 -> V_64 ) ;
F_88 ( V_26 ) ;
return 0 ;
}
void F_242 ( struct V_1 * V_2 )
{
struct V_418 * V_26 , * V_61 ;
F_168 (data, n, &hdev->remote_oob_data, list) {
F_169 ( & V_26 -> V_64 ) ;
F_88 ( V_26 ) ;
}
}
int F_243 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_419 , T_5 * V_420 )
{
struct V_418 * V_26 ;
V_26 = F_241 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_187 ( sizeof( * V_26 ) , V_103 ) ;
if ( ! V_26 )
return - V_104 ;
F_147 ( & V_26 -> V_40 , V_40 ) ;
F_175 ( & V_26 -> V_64 , & V_2 -> V_421 ) ;
}
memcpy ( V_26 -> V_422 , V_419 , sizeof( V_26 -> V_422 ) ) ;
memcpy ( V_26 -> V_423 , V_420 , sizeof( V_26 -> V_423 ) ) ;
memset ( V_26 -> V_424 , 0 , sizeof( V_26 -> V_424 ) ) ;
memset ( V_26 -> V_425 , 0 , sizeof( V_26 -> V_425 ) ) ;
F_90 ( L_74 , V_2 -> V_107 , V_40 ) ;
return 0 ;
}
int F_244 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_422 , T_5 * V_423 ,
T_5 * V_424 , T_5 * V_425 )
{
struct V_418 * V_26 ;
V_26 = F_241 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_187 ( sizeof( * V_26 ) , V_103 ) ;
if ( ! V_26 )
return - V_104 ;
F_147 ( & V_26 -> V_40 , V_40 ) ;
F_175 ( & V_26 -> V_64 , & V_2 -> V_421 ) ;
}
memcpy ( V_26 -> V_422 , V_422 , sizeof( V_26 -> V_422 ) ) ;
memcpy ( V_26 -> V_423 , V_423 , sizeof( V_26 -> V_423 ) ) ;
memcpy ( V_26 -> V_424 , V_424 , sizeof( V_26 -> V_424 ) ) ;
memcpy ( V_26 -> V_425 , V_425 , sizeof( V_26 -> V_425 ) ) ;
F_90 ( L_74 , V_2 -> V_107 , V_40 ) ;
return 0 ;
}
struct V_38 * F_245 ( struct V_1 * V_2 ,
T_8 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->blacklist, list) {
if ( ! F_155 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->blacklist) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_169 ( V_31 ) ;
F_88 ( V_39 ) ;
}
}
int F_247 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_426 ;
if ( ! F_155 ( V_40 , V_213 ) )
return - V_427 ;
if ( F_245 ( V_2 , V_40 , type ) )
return - V_428 ;
V_426 = F_82 ( sizeof( struct V_38 ) , V_103 ) ;
if ( ! V_426 )
return - V_104 ;
F_147 ( & V_426 -> V_40 , V_40 ) ;
V_426 -> V_41 = type ;
F_175 ( & V_426 -> V_64 , & V_2 -> V_429 ) ;
return F_248 ( V_2 , V_40 , type ) ;
}
int F_249 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_426 ;
if ( ! F_155 ( V_40 , V_213 ) ) {
F_246 ( V_2 ) ;
return 0 ;
}
V_426 = F_245 ( V_2 , V_40 , type ) ;
if ( ! V_426 )
return - V_413 ;
F_169 ( & V_426 -> V_64 ) ;
F_88 ( V_426 ) ;
return F_250 ( V_2 , V_40 , type ) ;
}
struct V_38 * F_251 ( struct V_1 * V_2 ,
T_8 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->le_white_list, list) {
if ( ! F_155 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
void F_252 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->le_white_list) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_169 ( V_31 ) ;
F_88 ( V_39 ) ;
}
}
int F_253 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_426 ;
if ( ! F_155 ( V_40 , V_213 ) )
return - V_427 ;
V_426 = F_82 ( sizeof( struct V_38 ) , V_103 ) ;
if ( ! V_426 )
return - V_104 ;
F_147 ( & V_426 -> V_40 , V_40 ) ;
V_426 -> V_41 = type ;
F_175 ( & V_426 -> V_64 , & V_2 -> V_430 ) ;
return 0 ;
}
int F_254 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_426 ;
if ( ! F_155 ( V_40 , V_213 ) )
return - V_427 ;
V_426 = F_251 ( V_2 , V_40 , type ) ;
if ( ! V_426 )
return - V_413 ;
F_169 ( & V_426 -> V_64 ) ;
F_88 ( V_426 ) ;
return 0 ;
}
struct V_100 * F_255 ( struct V_1 * V_2 ,
T_8 * V_79 , T_5 V_80 )
{
struct V_100 * V_431 ;
F_26 (params, &hdev->le_conn_params, list) {
if ( F_155 ( & V_431 -> V_79 , V_79 ) == 0 &&
V_431 -> V_80 == V_80 ) {
return V_431 ;
}
}
return NULL ;
}
static bool F_256 ( struct V_1 * V_2 , T_8 * V_79 , T_5 type )
{
struct V_391 * V_392 ;
V_392 = F_257 ( V_2 , V_432 , V_79 ) ;
if ( ! V_392 )
return false ;
if ( V_392 -> V_433 != type )
return false ;
if ( V_392 -> V_262 != V_434 )
return false ;
return true ;
}
static bool F_258 ( T_8 * V_79 , T_5 V_80 )
{
if ( V_80 == V_435 )
return true ;
if ( ( V_79 -> V_39 [ 5 ] & 0xc0 ) == 0xc0 )
return true ;
return false ;
}
int F_83 ( struct V_1 * V_2 , T_8 * V_79 , T_5 V_80 ,
T_5 V_101 , T_9 V_436 ,
T_9 V_437 )
{
struct V_100 * V_431 ;
if ( ! F_258 ( V_79 , V_80 ) )
return - V_21 ;
V_431 = F_255 ( V_2 , V_79 , V_80 ) ;
if ( V_431 )
goto V_278;
V_431 = F_82 ( sizeof( * V_431 ) , V_103 ) ;
if ( ! V_431 ) {
F_95 ( L_75 ) ;
return - V_104 ;
}
F_147 ( & V_431 -> V_79 , V_79 ) ;
V_431 -> V_80 = V_80 ;
F_175 ( & V_431 -> V_64 , & V_2 -> V_438 ) ;
V_278:
V_431 -> V_436 = V_436 ;
V_431 -> V_437 = V_437 ;
V_431 -> V_101 = V_101 ;
switch ( V_101 ) {
case V_439 :
case V_440 :
F_259 ( V_2 , V_79 , V_80 ) ;
break;
case V_441 :
if ( ! F_256 ( V_2 , V_79 , V_80 ) )
F_260 ( V_2 , V_79 , V_80 ) ;
break;
}
F_90 ( L_76
L_77 , V_79 , V_80 , V_101 ,
V_436 , V_437 ) ;
return 0 ;
}
void F_84 ( struct V_1 * V_2 , T_8 * V_79 , T_5 V_80 )
{
struct V_100 * V_431 ;
V_431 = F_255 ( V_2 , V_79 , V_80 ) ;
if ( ! V_431 )
return;
F_259 ( V_2 , V_79 , V_80 ) ;
F_169 ( & V_431 -> V_64 ) ;
F_88 ( V_431 ) ;
F_90 ( L_78 , V_79 , V_80 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_100 * V_431 , * V_389 ;
F_168 (params, tmp, &hdev->le_conn_params, list) {
F_169 ( & V_431 -> V_64 ) ;
F_88 ( V_431 ) ;
}
F_90 ( L_79 ) ;
}
struct V_38 * F_261 ( struct V_1 * V_2 ,
T_8 * V_79 , T_5 V_80 )
{
struct V_38 * V_426 ;
F_26 (entry, &hdev->pend_le_conns, list) {
if ( F_155 ( & V_426 -> V_40 , V_79 ) == 0 &&
V_426 -> V_41 == V_80 )
return V_426 ;
}
return NULL ;
}
void F_260 ( struct V_1 * V_2 , T_8 * V_79 , T_5 V_80 )
{
struct V_38 * V_426 ;
V_426 = F_261 ( V_2 , V_79 , V_80 ) ;
if ( V_426 )
goto V_105;
V_426 = F_82 ( sizeof( * V_426 ) , V_103 ) ;
if ( ! V_426 ) {
F_95 ( L_75 ) ;
return;
}
F_147 ( & V_426 -> V_40 , V_79 ) ;
V_426 -> V_41 = V_80 ;
F_175 ( & V_426 -> V_64 , & V_2 -> V_442 ) ;
F_90 ( L_78 , V_79 , V_80 ) ;
V_105:
F_87 ( V_2 ) ;
}
void F_259 ( struct V_1 * V_2 , T_8 * V_79 , T_5 V_80 )
{
struct V_38 * V_426 ;
V_426 = F_261 ( V_2 , V_79 , V_80 ) ;
if ( ! V_426 )
goto V_105;
F_169 ( & V_426 -> V_64 ) ;
F_88 ( V_426 ) ;
F_90 ( L_78 , V_79 , V_80 ) ;
V_105:
F_87 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_38 * V_426 , * V_389 ;
F_168 (entry, tmp, &hdev->pend_le_conns, list) {
F_169 ( & V_426 -> V_64 ) ;
F_88 ( V_426 ) ;
}
F_90 ( L_80 ) ;
}
static void F_262 ( struct V_1 * V_2 , T_5 V_443 )
{
if ( V_443 ) {
F_95 ( L_81 , V_443 ) ;
F_19 ( V_2 ) ;
F_165 ( V_2 , V_265 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_263 ( struct V_1 * V_2 , T_5 V_443 )
{
T_5 V_291 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_131 V_132 ;
struct V_289 V_188 ;
int V_16 ;
if ( V_443 ) {
F_95 ( L_82 , V_443 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_444 :
F_19 ( V_2 ) ;
F_165 ( V_2 , V_265 ) ;
F_22 ( V_2 ) ;
break;
case V_445 :
F_99 ( & V_132 , V_2 ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
memcpy ( & V_188 . V_291 , V_291 , sizeof( V_188 . V_291 ) ) ;
V_188 . V_292 = V_446 ;
F_112 ( & V_132 , V_294 , sizeof( V_188 ) , & V_188 ) ;
F_19 ( V_2 ) ;
F_167 ( V_2 ) ;
V_16 = F_101 ( & V_132 , F_262 ) ;
if ( V_16 ) {
F_95 ( L_83 , V_16 ) ;
F_165 ( V_2 , V_265 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_264 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 ,
V_338 . V_386 ) ;
struct V_131 V_132 ;
int V_16 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_99 ( & V_132 , V_2 ) ;
F_265 ( & V_132 ) ;
V_16 = F_101 ( & V_132 , F_263 ) ;
if ( V_16 )
F_95 ( L_84 , V_16 ) ;
}
static void F_266 ( struct V_131 * V_132 , T_8 * V_82 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( F_4 ( V_447 , & V_2 -> V_11 ) ||
F_267 ( V_2 , V_432 , V_448 ) ) {
F_90 ( L_85 ) ;
return;
}
F_112 ( V_132 , V_449 , 6 , V_82 ) ;
}
int F_268 ( struct V_131 * V_132 , bool V_450 ,
T_5 * V_451 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
int V_16 ;
if ( F_4 ( V_452 , & V_2 -> V_11 ) ) {
int V_453 ;
* V_451 = V_403 ;
if ( ! F_196 ( V_317 , & V_2 -> V_11 ) &&
! F_155 ( & V_2 -> V_83 , & V_2 -> V_82 ) )
return 0 ;
V_16 = F_269 ( V_2 -> V_402 , V_2 -> V_81 , & V_2 -> V_82 ) ;
if ( V_16 < 0 ) {
F_95 ( L_86 , V_2 -> V_107 ) ;
return V_16 ;
}
F_266 ( V_132 , & V_2 -> V_82 ) ;
V_453 = F_185 ( V_2 -> V_76 * 1000 ) ;
F_215 ( V_2 -> V_417 , & V_2 -> V_340 , V_453 ) ;
return 0 ;
}
if ( V_450 ) {
T_8 V_454 ;
F_270 ( & V_454 , 6 ) ;
V_454 . V_39 [ 5 ] &= 0x3f ;
* V_451 = V_403 ;
F_266 ( V_132 , & V_454 ) ;
return 0 ;
}
if ( F_4 ( V_85 , & V_2 -> V_11 ) ||
! F_155 ( & V_2 -> V_40 , V_213 ) ) {
* V_451 = V_403 ;
if ( F_155 ( & V_2 -> V_84 , & V_2 -> V_83 ) )
F_112 ( V_132 , V_449 , 6 ,
& V_2 -> V_84 ) ;
return 0 ;
}
* V_451 = V_435 ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_41 )
{
if ( F_4 ( V_85 , & V_2 -> V_11 ) ||
! F_155 ( & V_2 -> V_40 , V_213 ) ) {
F_147 ( V_40 , & V_2 -> V_84 ) ;
* V_41 = V_403 ;
} else {
F_147 ( V_40 , & V_2 -> V_40 ) ;
* V_41 = V_435 ;
}
}
struct V_1 * F_271 ( void )
{
struct V_1 * V_2 ;
V_2 = F_82 ( sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_365 = ( V_455 | V_456 | V_457 ) ;
V_2 -> V_458 = ( V_459 ) ;
V_2 -> V_361 = ( V_363 ) ;
V_2 -> V_460 = 0x01 ;
V_2 -> V_461 = 0x03 ;
V_2 -> V_462 = V_463 ;
V_2 -> V_464 = V_463 ;
V_2 -> V_77 = 800 ;
V_2 -> V_78 = 80 ;
V_2 -> V_94 = 0x07 ;
V_2 -> V_465 = 0x0060 ;
V_2 -> V_466 = 0x0030 ;
V_2 -> V_93 = 0x0028 ;
V_2 -> V_92 = 0x0038 ;
V_2 -> V_76 = V_467 ;
F_272 ( & V_2 -> V_468 ) ;
F_272 ( & V_2 -> V_469 ) ;
F_170 ( & V_2 -> V_470 ) ;
F_170 ( & V_2 -> V_429 ) ;
F_170 ( & V_2 -> V_471 ) ;
F_170 ( & V_2 -> V_407 ) ;
F_170 ( & V_2 -> V_411 ) ;
F_170 ( & V_2 -> V_412 ) ;
F_170 ( & V_2 -> V_421 ) ;
F_170 ( & V_2 -> V_430 ) ;
F_170 ( & V_2 -> V_438 ) ;
F_170 ( & V_2 -> V_442 ) ;
F_170 ( & V_2 -> V_472 . V_64 ) ;
F_273 ( & V_2 -> V_321 , V_473 ) ;
F_273 ( & V_2 -> V_320 , V_474 ) ;
F_273 ( & V_2 -> V_319 , V_475 ) ;
F_273 ( & V_2 -> V_387 , F_212 ) ;
F_274 ( & V_2 -> V_329 , F_217 ) ;
F_274 ( & V_2 -> V_333 , F_218 ) ;
F_274 ( & V_2 -> V_338 , F_264 ) ;
F_275 ( & V_2 -> V_323 ) ;
F_275 ( & V_2 -> V_322 ) ;
F_275 ( & V_2 -> V_342 ) ;
F_276 ( & V_2 -> V_112 ) ;
F_277 ( & V_2 -> V_331 , F_239 , ( unsigned long ) V_2 ) ;
F_278 ( V_2 ) ;
F_279 ( V_2 ) ;
return V_2 ;
}
void F_280 ( struct V_1 * V_2 )
{
F_281 ( & V_2 -> V_327 ) ;
}
int F_282 ( struct V_1 * V_2 )
{
int V_260 , error ;
if ( ! V_2 -> V_310 || ! V_2 -> V_326 )
return - V_21 ;
switch ( V_2 -> V_152 ) {
case V_153 :
V_260 = F_283 ( & V_476 , 0 , 0 , V_103 ) ;
break;
case V_154 :
V_260 = F_283 ( & V_476 , 1 , 0 , V_103 ) ;
break;
default:
return - V_21 ;
}
if ( V_260 < 0 )
return V_260 ;
sprintf ( V_2 -> V_107 , L_87 , V_260 ) ;
V_2 -> V_260 = V_260 ;
F_90 ( L_88 , V_2 , V_2 -> V_107 , V_2 -> V_381 ) ;
V_2 -> V_417 = F_284 ( L_24 , V_477 | V_478 |
V_479 , 1 , V_2 -> V_107 ) ;
if ( ! V_2 -> V_417 ) {
error = - V_104 ;
goto V_16;
}
V_2 -> V_330 = F_284 ( L_24 , V_477 | V_478 |
V_479 , 1 , V_2 -> V_107 ) ;
if ( ! V_2 -> V_330 ) {
F_285 ( V_2 -> V_417 ) ;
error = - V_104 ;
goto V_16;
}
if ( ! F_286 ( V_480 ) )
V_2 -> V_222 = F_287 ( V_2 -> V_107 , V_480 ) ;
F_288 ( & V_2 -> V_327 , L_24 , V_2 -> V_107 ) ;
V_2 -> V_402 = F_289 ( L_89 , 0 ,
V_481 ) ;
if ( F_13 ( V_2 -> V_402 ) ) {
F_95 ( L_90 ) ;
error = F_14 ( V_2 -> V_402 ) ;
V_2 -> V_402 = NULL ;
goto V_482;
}
error = F_290 ( & V_2 -> V_327 ) ;
if ( error < 0 )
goto V_483;
V_2 -> V_484 = F_291 ( V_2 -> V_107 , & V_2 -> V_327 ,
V_485 , & V_486 ,
V_2 ) ;
if ( V_2 -> V_484 ) {
if ( F_292 ( V_2 -> V_484 ) < 0 ) {
F_293 ( V_2 -> V_484 ) ;
V_2 -> V_484 = NULL ;
}
}
if ( V_2 -> V_484 && F_294 ( V_2 -> V_484 ) )
F_111 ( V_307 , & V_2 -> V_11 ) ;
F_111 ( V_221 , & V_2 -> V_11 ) ;
F_111 ( V_328 , & V_2 -> V_11 ) ;
if ( V_2 -> V_152 == V_153 ) {
F_111 ( V_184 , & V_2 -> V_11 ) ;
}
F_295 ( & V_259 ) ;
F_175 ( & V_2 -> V_64 , & V_487 ) ;
F_296 ( & V_259 ) ;
F_1 ( V_2 , V_488 ) ;
F_162 ( V_2 ) ;
F_240 ( V_2 -> V_330 , & V_2 -> V_387 ) ;
return V_260 ;
V_483:
F_297 ( V_2 -> V_402 ) ;
V_482:
F_285 ( V_2 -> V_417 ) ;
F_285 ( V_2 -> V_330 ) ;
V_16:
F_298 ( & V_476 , V_2 -> V_260 ) ;
return error ;
}
void F_299 ( struct V_1 * V_2 )
{
int V_44 , V_260 ;
F_90 ( L_88 , V_2 , V_2 -> V_107 , V_2 -> V_381 ) ;
F_111 ( V_306 , & V_2 -> V_11 ) ;
V_260 = V_2 -> V_260 ;
F_295 ( & V_259 ) ;
F_169 ( & V_2 -> V_64 ) ;
F_296 ( & V_259 ) ;
F_199 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_489 ; V_44 ++ )
F_16 ( V_2 -> V_490 [ V_44 ] ) ;
F_300 ( & V_2 -> V_387 ) ;
if ( ! F_4 ( V_313 , & V_2 -> V_18 ) &&
! F_4 ( V_221 , & V_2 -> V_11 ) ) {
F_19 ( V_2 ) ;
F_301 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_302 ( ! F_303 ( & V_2 -> V_470 ) ) ;
F_1 ( V_2 , V_491 ) ;
if ( V_2 -> V_484 ) {
F_304 ( V_2 -> V_484 ) ;
F_293 ( V_2 -> V_484 ) ;
}
if ( V_2 -> V_402 )
F_297 ( V_2 -> V_402 ) ;
F_305 ( & V_2 -> V_327 ) ;
F_306 ( V_2 -> V_222 ) ;
F_285 ( V_2 -> V_417 ) ;
F_285 ( V_2 -> V_330 ) ;
F_19 ( V_2 ) ;
F_246 ( V_2 ) ;
F_220 ( V_2 ) ;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
F_223 ( V_2 ) ;
F_242 ( V_2 ) ;
F_252 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_22 ( V_2 ) ;
F_189 ( V_2 ) ;
F_298 ( & V_476 , V_260 ) ;
}
int F_307 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_492 ) ;
return 0 ;
}
int F_308 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_493 ) ;
return 0 ;
}
int F_309 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_313 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_494 ;
}
F_310 ( V_13 ) -> V_495 = 1 ;
F_311 ( V_13 ) ;
F_312 ( & V_2 -> V_323 , V_13 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_321 ) ;
return 0 ;
}
static int F_313 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_7 V_257 )
{
int V_121 = 0 ;
int V_496 = 0 ;
int V_497 = V_6 ;
struct V_12 * V_13 ;
struct V_498 * V_499 ;
if ( ( type < V_500 || type > V_501 ) ||
V_257 >= V_489 )
return - V_502 ;
V_13 = V_2 -> V_490 [ V_257 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_500 :
V_121 = V_503 ;
V_496 = V_504 ;
break;
case V_501 :
V_121 = V_505 ;
V_496 = V_123 ;
break;
case V_506 :
V_121 = V_507 ;
V_496 = V_508 ;
break;
}
V_13 = F_314 ( V_121 , V_279 ) ;
if ( ! V_13 )
return - V_104 ;
V_499 = ( void * ) V_13 -> V_509 ;
V_499 -> V_510 = V_496 ;
V_499 -> V_365 = type ;
V_2 -> V_490 [ V_257 ] = V_13 ;
}
while ( V_6 ) {
V_499 = ( void * ) V_13 -> V_509 ;
V_121 = F_315 ( V_511 , V_499 -> V_510 , V_6 ) ;
memcpy ( F_316 ( V_13 , V_121 ) , V_26 , V_121 ) ;
V_6 -= V_121 ;
V_26 += V_121 ;
V_499 -> V_510 -= V_121 ;
V_497 = V_6 ;
switch ( type ) {
case V_501 :
if ( V_13 -> V_121 == V_123 ) {
struct V_117 * V_512 = V_117 ( V_13 ) ;
V_499 -> V_510 = V_512 -> V_126 ;
if ( F_317 ( V_13 ) < V_499 -> V_510 ) {
F_16 ( V_13 ) ;
V_2 -> V_490 [ V_257 ] = NULL ;
return - V_104 ;
}
}
break;
case V_500 :
if ( V_13 -> V_121 == V_504 ) {
struct V_513 * V_512 = V_513 ( V_13 ) ;
V_499 -> V_510 = F_31 ( V_512 -> V_514 ) ;
if ( F_317 ( V_13 ) < V_499 -> V_510 ) {
F_16 ( V_13 ) ;
V_2 -> V_490 [ V_257 ] = NULL ;
return - V_104 ;
}
}
break;
case V_506 :
if ( V_13 -> V_121 == V_508 ) {
struct V_515 * V_512 = V_515 ( V_13 ) ;
V_499 -> V_510 = V_512 -> V_514 ;
if ( F_317 ( V_13 ) < V_499 -> V_510 ) {
F_16 ( V_13 ) ;
V_2 -> V_490 [ V_257 ] = NULL ;
return - V_104 ;
}
}
break;
}
if ( V_499 -> V_510 == 0 ) {
F_310 ( V_13 ) -> V_365 = type ;
F_309 ( V_2 , V_13 ) ;
V_2 -> V_490 [ V_257 ] = NULL ;
return V_497 ;
}
}
return V_497 ;
}
int F_318 ( struct V_1 * V_2 , int type , void * V_26 , int V_6 )
{
int V_516 = 0 ;
if ( type < V_500 || type > V_501 )
return - V_502 ;
while ( V_6 ) {
V_516 = F_313 ( V_2 , type , V_26 , V_6 , type - 1 ) ;
if ( V_516 < 0 )
return V_516 ;
V_26 += ( V_6 - V_516 ) ;
V_6 = V_516 ;
}
return V_516 ;
}
int F_319 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_516 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_490 [ V_517 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_518 ;
V_518 = V_26 ;
type = V_518 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_310 ( V_13 ) -> V_365 ;
V_516 = F_313 ( V_2 , type , V_26 , V_6 ,
V_517 ) ;
if ( V_516 < 0 )
return V_516 ;
V_26 += ( V_6 - V_516 ) ;
V_6 = V_516 ;
}
return V_516 ;
}
int F_320 ( struct V_519 * V_509 )
{
F_90 ( L_91 , V_509 , V_509 -> V_107 ) ;
F_295 ( & V_520 ) ;
F_175 ( & V_509 -> V_64 , & V_521 ) ;
F_296 ( & V_520 ) ;
return 0 ;
}
int F_321 ( struct V_519 * V_509 )
{
F_90 ( L_91 , V_509 , V_509 -> V_107 ) ;
F_295 ( & V_520 ) ;
F_169 ( & V_509 -> V_64 ) ;
F_296 ( & V_520 ) ;
return 0 ;
}
static void F_322 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_90 ( L_92 , V_2 -> V_107 , F_310 ( V_13 ) -> V_365 , V_13 -> V_121 ) ;
F_311 ( V_13 ) ;
F_323 ( V_2 , V_13 ) ;
if ( F_324 ( & V_2 -> V_522 ) ) {
F_325 ( V_2 , V_13 ) ;
}
F_326 ( V_13 ) ;
if ( V_2 -> V_523 ( V_2 , V_13 ) < 0 )
F_95 ( L_93 , V_2 -> V_107 ) ;
}
void F_99 ( struct V_131 * V_132 , struct V_1 * V_2 )
{
F_275 ( & V_132 -> V_322 ) ;
V_132 -> V_2 = V_2 ;
V_132 -> V_16 = 0 ;
}
int F_101 ( struct V_131 * V_132 , T_15 V_524 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_90 ( L_94 , F_327 ( & V_132 -> V_322 ) ) ;
if ( V_132 -> V_16 ) {
F_194 ( & V_132 -> V_322 ) ;
return V_132 -> V_16 ;
}
if ( F_328 ( & V_132 -> V_322 ) )
return - V_120 ;
V_13 = F_329 ( & V_132 -> V_322 ) ;
F_310 ( V_13 ) -> V_132 . V_524 = V_524 ;
F_330 ( & V_2 -> V_322 . V_468 , V_18 ) ;
F_331 ( & V_132 -> V_322 , & V_2 -> V_322 ) ;
F_332 ( & V_2 -> V_322 . V_468 , V_18 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_320 ) ;
return 0 ;
}
static struct V_12 * F_333 ( struct V_1 * V_2 , T_9 V_114 ,
T_10 V_126 , const void * V_127 )
{
int V_121 = V_525 + V_126 ;
struct V_415 * V_118 ;
struct V_12 * V_13 ;
V_13 = F_314 ( V_121 , V_279 ) ;
if ( ! V_13 )
return NULL ;
V_118 = (struct V_415 * ) F_316 ( V_13 , V_525 ) ;
V_118 -> V_114 = F_117 ( V_114 ) ;
V_118 -> V_126 = V_126 ;
if ( V_126 )
memcpy ( F_316 ( V_13 , V_126 ) , V_127 , V_126 ) ;
F_90 ( L_95 , V_13 -> V_121 ) ;
F_310 ( V_13 ) -> V_365 = V_526 ;
return V_13 ;
}
int F_334 ( struct V_1 * V_2 , T_13 V_114 , T_11 V_126 ,
const void * V_127 )
{
struct V_12 * V_13 ;
F_90 ( L_96 , V_2 -> V_107 , V_114 , V_126 ) ;
V_13 = F_333 ( V_2 , V_114 , V_126 , V_127 ) ;
if ( ! V_13 ) {
F_95 ( L_97 , V_2 -> V_107 ) ;
return - V_104 ;
}
F_310 ( V_13 ) -> V_132 . V_527 = true ;
F_312 ( & V_2 -> V_322 , V_13 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_320 ) ;
return 0 ;
}
void F_100 ( struct V_131 * V_132 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_5 V_3 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_12 * V_13 ;
F_90 ( L_96 , V_2 -> V_107 , V_114 , V_126 ) ;
if ( V_132 -> V_16 )
return;
V_13 = F_333 ( V_2 , V_114 , V_126 , V_127 ) ;
if ( ! V_13 ) {
F_95 ( L_98 ,
V_2 -> V_107 , V_114 ) ;
V_132 -> V_16 = - V_104 ;
return;
}
if ( F_328 ( & V_132 -> V_322 ) )
F_310 ( V_13 ) -> V_132 . V_527 = true ;
F_310 ( V_13 ) -> V_132 . V_3 = V_3 ;
F_312 ( & V_132 -> V_322 , V_13 ) ;
}
void F_112 ( struct V_131 * V_132 , T_9 V_114 , T_10 V_126 ,
const void * V_127 )
{
F_100 ( V_132 , V_114 , V_126 , V_127 , 0 ) ;
}
void * F_335 ( struct V_1 * V_2 , T_13 V_114 )
{
struct V_415 * V_118 ;
if ( ! V_2 -> V_325 )
return NULL ;
V_118 = ( void * ) V_2 -> V_325 -> V_26 ;
if ( V_118 -> V_114 != F_117 ( V_114 ) )
return NULL ;
F_90 ( L_99 , V_2 -> V_107 , V_114 ) ;
return V_2 -> V_325 -> V_26 + V_525 ;
}
static void F_336 ( struct V_12 * V_13 , T_13 V_528 , T_13 V_18 )
{
struct V_513 * V_118 ;
int V_121 = V_13 -> V_121 ;
F_337 ( V_13 , V_504 ) ;
F_338 ( V_13 ) ;
V_118 = (struct V_513 * ) F_339 ( V_13 ) ;
V_118 -> V_528 = F_117 ( F_340 ( V_528 , V_18 ) ) ;
V_118 -> V_514 = F_117 ( V_121 ) ;
}
static void F_341 ( struct V_529 * V_530 , struct V_531 * V_532 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_391 * V_392 = V_530 -> V_392 ;
struct V_1 * V_2 = V_392 -> V_2 ;
struct V_12 * V_64 ;
V_13 -> V_121 = F_342 ( V_13 ) ;
V_13 -> V_533 = 0 ;
F_310 ( V_13 ) -> V_365 = V_500 ;
switch ( V_2 -> V_152 ) {
case V_153 :
F_336 ( V_13 , V_392 -> V_528 , V_18 ) ;
break;
case V_154 :
F_336 ( V_13 , V_530 -> V_528 , V_18 ) ;
break;
default:
F_95 ( L_100 , V_2 -> V_107 , V_2 -> V_152 ) ;
return;
}
V_64 = F_343 ( V_13 ) -> V_534 ;
if ( ! V_64 ) {
F_90 ( L_101 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_312 ( V_532 , V_13 ) ;
} else {
F_90 ( L_102 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_343 ( V_13 ) -> V_534 = NULL ;
F_344 ( & V_532 -> V_468 ) ;
F_345 ( V_532 , V_13 ) ;
V_18 &= ~ V_535 ;
V_18 |= V_536 ;
do {
V_13 = V_64 ; V_64 = V_64 -> V_537 ;
F_310 ( V_13 ) -> V_365 = V_500 ;
F_336 ( V_13 , V_392 -> V_528 , V_18 ) ;
F_90 ( L_102 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_345 ( V_532 , V_13 ) ;
} while ( V_64 );
F_346 ( & V_532 -> V_468 ) ;
}
}
void F_347 ( struct V_529 * V_530 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_530 -> V_392 -> V_2 ;
F_90 ( L_103 , V_2 -> V_107 , V_530 , V_18 ) ;
F_341 ( V_530 , & V_530 -> V_538 , V_13 , V_18 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_319 ) ;
}
void F_348 ( struct V_391 * V_392 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_392 -> V_2 ;
struct V_515 V_118 ;
F_90 ( L_104 , V_2 -> V_107 , V_13 -> V_121 ) ;
V_118 . V_528 = F_117 ( V_392 -> V_528 ) ;
V_118 . V_514 = V_13 -> V_121 ;
F_337 ( V_13 , V_508 ) ;
F_338 ( V_13 ) ;
memcpy ( F_339 ( V_13 ) , & V_118 , V_508 ) ;
F_310 ( V_13 ) -> V_365 = V_506 ;
F_312 ( & V_392 -> V_538 , V_13 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_319 ) ;
}
static struct V_391 * F_349 ( struct V_1 * V_2 , T_7 type ,
int * V_539 )
{
struct V_540 * V_512 = & V_2 -> V_472 ;
struct V_391 * V_392 = NULL , * V_541 ;
unsigned int V_283 = 0 , F_7 = ~ 0 ;
F_350 () ;
F_351 (c, &h->list, list) {
if ( V_541 -> type != type || F_328 ( & V_541 -> V_538 ) )
continue;
if ( V_541 -> V_262 != V_434 && V_541 -> V_262 != V_542 )
continue;
V_283 ++ ;
if ( V_541 -> V_416 < F_7 ) {
F_7 = V_541 -> V_416 ;
V_392 = V_541 ;
}
if ( F_352 ( V_2 , type ) == V_283 )
break;
}
F_353 () ;
if ( V_392 ) {
int V_543 , V_544 ;
switch ( V_392 -> type ) {
case V_545 :
V_543 = V_2 -> V_346 ;
break;
case V_546 :
case V_547 :
V_543 = V_2 -> V_347 ;
break;
case V_432 :
V_543 = V_2 -> V_382 ? V_2 -> V_348 : V_2 -> V_346 ;
break;
default:
V_543 = 0 ;
F_95 ( L_105 ) ;
}
V_544 = V_543 / V_283 ;
* V_539 = V_544 ? V_544 : 1 ;
} else
* V_539 = 0 ;
F_90 ( L_106 , V_392 , * V_539 ) ;
return V_392 ;
}
static void F_354 ( struct V_1 * V_2 , T_7 type )
{
struct V_540 * V_512 = & V_2 -> V_472 ;
struct V_391 * V_541 ;
F_95 ( L_107 , V_2 -> V_107 ) ;
F_350 () ;
F_351 (c, &h->list, list) {
if ( V_541 -> type == type && V_541 -> V_416 ) {
F_95 ( L_108 ,
V_2 -> V_107 , & V_541 -> V_548 ) ;
F_355 ( V_541 , V_549 ) ;
}
}
F_353 () ;
}
static struct V_529 * F_356 ( struct V_1 * V_2 , T_7 type ,
int * V_539 )
{
struct V_540 * V_512 = & V_2 -> V_472 ;
struct V_529 * V_530 = NULL ;
unsigned int V_283 = 0 , F_7 = ~ 0 , V_550 = 0 ;
struct V_391 * V_392 ;
int V_543 , V_544 , V_551 = 0 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_350 () ;
F_351 (conn, &h->list, list) {
struct V_529 * V_389 ;
if ( V_392 -> type != type )
continue;
if ( V_392 -> V_262 != V_434 && V_392 -> V_262 != V_542 )
continue;
V_551 ++ ;
F_351 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_328 ( & V_389 -> V_538 ) )
continue;
V_13 = F_357 ( & V_389 -> V_538 ) ;
if ( V_13 -> V_552 < V_550 )
continue;
if ( V_13 -> V_552 > V_550 ) {
V_283 = 0 ;
F_7 = ~ 0 ;
V_550 = V_13 -> V_552 ;
}
V_283 ++ ;
if ( V_392 -> V_416 < F_7 ) {
F_7 = V_392 -> V_416 ;
V_530 = V_389 ;
}
}
if ( F_352 ( V_2 , type ) == V_551 )
break;
}
F_353 () ;
if ( ! V_530 )
return NULL ;
switch ( V_530 -> V_392 -> type ) {
case V_545 :
V_543 = V_2 -> V_346 ;
break;
case V_553 :
V_543 = V_2 -> V_554 ;
break;
case V_546 :
case V_547 :
V_543 = V_2 -> V_347 ;
break;
case V_432 :
V_543 = V_2 -> V_382 ? V_2 -> V_348 : V_2 -> V_346 ;
break;
default:
V_543 = 0 ;
F_95 ( L_105 ) ;
}
V_544 = V_543 / V_283 ;
* V_539 = V_544 ? V_544 : 1 ;
F_90 ( L_109 , V_530 , * V_539 ) ;
return V_530 ;
}
static void F_358 ( struct V_1 * V_2 , T_7 type )
{
struct V_540 * V_512 = & V_2 -> V_472 ;
struct V_391 * V_392 ;
int V_283 = 0 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
F_350 () ;
F_351 (conn, &h->list, list) {
struct V_529 * V_530 ;
if ( V_392 -> type != type )
continue;
if ( V_392 -> V_262 != V_434 && V_392 -> V_262 != V_542 )
continue;
V_283 ++ ;
F_351 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_530 -> V_416 ) {
V_530 -> V_416 = 0 ;
continue;
}
if ( F_328 ( & V_530 -> V_538 ) )
continue;
V_13 = F_357 ( & V_530 -> V_538 ) ;
if ( V_13 -> V_552 >= V_555 - 1 )
continue;
V_13 -> V_552 = V_555 - 1 ;
F_90 ( L_110 , V_530 , V_13 ,
V_13 -> V_552 ) ;
}
if ( F_352 ( V_2 , type ) == V_283 )
break;
}
F_353 () ;
}
static inline int F_359 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_360 ( V_13 -> V_121 - V_504 , V_2 -> V_556 ) ;
}
static void F_361 ( struct V_1 * V_2 , unsigned int V_543 )
{
if ( ! F_4 ( V_316 , & V_2 -> V_18 ) ) {
if ( ! V_543 && F_362 ( V_282 , V_2 -> V_557 +
V_558 ) )
F_354 ( V_2 , V_545 ) ;
}
}
static void F_363 ( struct V_1 * V_2 )
{
unsigned int V_543 = V_2 -> V_346 ;
struct V_529 * V_530 ;
struct V_12 * V_13 ;
int V_539 ;
F_361 ( V_2 , V_543 ) ;
while ( V_2 -> V_346 &&
( V_530 = F_356 ( V_2 , V_545 , & V_539 ) ) ) {
T_10 V_552 = ( F_357 ( & V_530 -> V_538 ) ) -> V_552 ;
while ( V_539 -- && ( V_13 = F_357 ( & V_530 -> V_538 ) ) ) {
F_90 ( L_111 , V_530 , V_13 ,
V_13 -> V_121 , V_13 -> V_552 ) ;
if ( V_13 -> V_552 < V_552 )
break;
V_13 = F_364 ( & V_530 -> V_538 ) ;
F_365 ( V_530 -> V_392 ,
F_310 ( V_13 ) -> V_559 ) ;
F_322 ( V_2 , V_13 ) ;
V_2 -> V_557 = V_282 ;
V_2 -> V_346 -- ;
V_530 -> V_416 ++ ;
V_530 -> V_392 -> V_416 ++ ;
}
}
if ( V_543 != V_2 -> V_346 )
F_358 ( V_2 , V_545 ) ;
}
static void F_366 ( struct V_1 * V_2 )
{
unsigned int V_543 = V_2 -> V_554 ;
struct V_529 * V_530 ;
struct V_12 * V_13 ;
int V_539 ;
T_5 type ;
F_361 ( V_2 , V_543 ) ;
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( V_2 -> V_152 == V_154 )
type = V_553 ;
else
type = V_545 ;
while ( V_2 -> V_554 > 0 &&
( V_530 = F_356 ( V_2 , type , & V_539 ) ) ) {
T_10 V_552 = ( F_357 ( & V_530 -> V_538 ) ) -> V_552 ;
while ( V_539 > 0 && ( V_13 = F_357 ( & V_530 -> V_538 ) ) ) {
int V_560 ;
F_90 ( L_111 , V_530 , V_13 ,
V_13 -> V_121 , V_13 -> V_552 ) ;
if ( V_13 -> V_552 < V_552 )
break;
V_13 = F_364 ( & V_530 -> V_538 ) ;
V_560 = F_359 ( V_2 , V_13 ) ;
if ( V_560 > V_2 -> V_554 )
return;
F_365 ( V_530 -> V_392 ,
F_310 ( V_13 ) -> V_559 ) ;
F_322 ( V_2 , V_13 ) ;
V_2 -> V_557 = V_282 ;
V_2 -> V_554 -= V_560 ;
V_539 -= V_560 ;
V_530 -> V_416 += V_560 ;
V_530 -> V_392 -> V_416 += V_560 ;
}
}
if ( V_543 != V_2 -> V_554 )
F_358 ( V_2 , type ) ;
}
static void F_367 ( struct V_1 * V_2 )
{
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_352 ( V_2 , V_545 ) && V_2 -> V_152 == V_153 )
return;
if ( ! F_352 ( V_2 , V_553 ) && V_2 -> V_152 == V_154 )
return;
switch ( V_2 -> V_139 ) {
case V_140 :
F_363 ( V_2 ) ;
break;
case V_144 :
F_366 ( V_2 ) ;
break;
}
}
static void F_368 ( struct V_1 * V_2 )
{
struct V_391 * V_392 ;
struct V_12 * V_13 ;
int V_539 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_352 ( V_2 , V_546 ) )
return;
while ( V_2 -> V_347 && ( V_392 = F_349 ( V_2 , V_546 , & V_539 ) ) ) {
while ( V_539 -- && ( V_13 = F_364 ( & V_392 -> V_538 ) ) ) {
F_90 ( L_112 , V_13 , V_13 -> V_121 ) ;
F_322 ( V_2 , V_13 ) ;
V_392 -> V_416 ++ ;
if ( V_392 -> V_416 == ~ 0 )
V_392 -> V_416 = 0 ;
}
}
}
static void F_369 ( struct V_1 * V_2 )
{
struct V_391 * V_392 ;
struct V_12 * V_13 ;
int V_539 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_352 ( V_2 , V_547 ) )
return;
while ( V_2 -> V_347 && ( V_392 = F_349 ( V_2 , V_547 ,
& V_539 ) ) ) {
while ( V_539 -- && ( V_13 = F_364 ( & V_392 -> V_538 ) ) ) {
F_90 ( L_112 , V_13 , V_13 -> V_121 ) ;
F_322 ( V_2 , V_13 ) ;
V_392 -> V_416 ++ ;
if ( V_392 -> V_416 == ~ 0 )
V_392 -> V_416 = 0 ;
}
}
}
static void F_370 ( struct V_1 * V_2 )
{
struct V_529 * V_530 ;
struct V_12 * V_13 ;
int V_539 , V_543 , V_389 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_352 ( V_2 , V_432 ) )
return;
if ( ! F_4 ( V_316 , & V_2 -> V_18 ) ) {
if ( ! V_2 -> V_348 && V_2 -> V_383 &&
F_362 ( V_282 , V_2 -> V_561 + V_562 * 45 ) )
F_354 ( V_2 , V_432 ) ;
}
V_543 = V_2 -> V_383 ? V_2 -> V_348 : V_2 -> V_346 ;
V_389 = V_543 ;
while ( V_543 && ( V_530 = F_356 ( V_2 , V_432 , & V_539 ) ) ) {
T_10 V_552 = ( F_357 ( & V_530 -> V_538 ) ) -> V_552 ;
while ( V_539 -- && ( V_13 = F_357 ( & V_530 -> V_538 ) ) ) {
F_90 ( L_111 , V_530 , V_13 ,
V_13 -> V_121 , V_13 -> V_552 ) ;
if ( V_13 -> V_552 < V_552 )
break;
V_13 = F_364 ( & V_530 -> V_538 ) ;
F_322 ( V_2 , V_13 ) ;
V_2 -> V_561 = V_282 ;
V_543 -- ;
V_530 -> V_416 ++ ;
V_530 -> V_392 -> V_416 ++ ;
}
}
if ( V_2 -> V_383 )
V_2 -> V_348 = V_543 ;
else
V_2 -> V_346 = V_543 ;
if ( V_543 != V_389 )
F_358 ( V_2 , V_432 ) ;
}
static void V_475 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 , V_319 ) ;
struct V_12 * V_13 ;
F_90 ( L_113 , V_2 -> V_107 , V_2 -> V_346 ,
V_2 -> V_347 , V_2 -> V_348 ) ;
if ( ! F_4 ( V_302 , & V_2 -> V_11 ) ) {
F_367 ( V_2 ) ;
F_368 ( V_2 ) ;
F_369 ( V_2 ) ;
F_370 ( V_2 ) ;
}
while ( ( V_13 = F_364 ( & V_2 -> V_342 ) ) )
F_322 ( V_2 , V_13 ) ;
}
static void F_371 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_513 * V_118 = ( void * ) V_13 -> V_26 ;
struct V_391 * V_392 ;
T_13 V_528 , V_18 ;
F_96 ( V_13 , V_504 ) ;
V_528 = F_31 ( V_118 -> V_528 ) ;
V_18 = F_372 ( V_528 ) ;
V_528 = F_373 ( V_528 ) ;
F_90 ( L_114 , V_2 -> V_107 , V_13 -> V_121 ,
V_528 , V_18 ) ;
V_2 -> V_349 . V_563 ++ ;
F_19 ( V_2 ) ;
V_392 = F_374 ( V_2 , V_528 ) ;
F_22 ( V_2 ) ;
if ( V_392 ) {
F_365 ( V_392 , V_564 ) ;
F_375 ( V_392 , V_13 , V_18 ) ;
return;
} else {
F_95 ( L_115 ,
V_2 -> V_107 , V_528 ) ;
}
F_16 ( V_13 ) ;
}
static void F_376 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_515 * V_118 = ( void * ) V_13 -> V_26 ;
struct V_391 * V_392 ;
T_13 V_528 ;
F_96 ( V_13 , V_508 ) ;
V_528 = F_31 ( V_118 -> V_528 ) ;
F_90 ( L_116 , V_2 -> V_107 , V_13 -> V_121 , V_528 ) ;
V_2 -> V_349 . V_565 ++ ;
F_19 ( V_2 ) ;
V_392 = F_374 ( V_2 , V_528 ) ;
F_22 ( V_2 ) ;
if ( V_392 ) {
F_377 ( V_392 , V_13 ) ;
return;
} else {
F_95 ( L_117 ,
V_2 -> V_107 , V_528 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_378 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_357 ( & V_2 -> V_322 ) ;
if ( ! V_13 )
return true ;
return F_310 ( V_13 ) -> V_132 . V_527 ;
}
static void F_379 ( struct V_1 * V_2 )
{
struct V_415 * V_416 ;
struct V_12 * V_13 ;
T_9 V_114 ;
if ( ! V_2 -> V_325 )
return;
V_416 = ( void * ) V_2 -> V_325 -> V_26 ;
V_114 = F_31 ( V_416 -> V_114 ) ;
if ( V_114 == V_25 )
return;
V_13 = F_380 ( V_2 -> V_325 , V_103 ) ;
if ( ! V_13 )
return;
F_381 ( & V_2 -> V_322 , V_13 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_320 ) ;
}
void F_382 ( struct V_1 * V_2 , T_9 V_114 , T_5 V_443 )
{
T_15 V_566 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_90 ( L_118 , V_114 , V_443 ) ;
if ( ! F_335 ( V_2 , V_114 ) ) {
if ( F_4 ( V_313 , & V_2 -> V_18 ) && V_114 == V_25 )
F_379 ( V_2 ) ;
return;
}
if ( ! V_443 && ! F_378 ( V_2 ) )
return;
if ( V_2 -> V_325 ) {
V_566 = F_310 ( V_2 -> V_325 ) -> V_132 . V_524 ;
if ( V_566 ) {
F_310 ( V_2 -> V_325 ) -> V_132 . V_524 = NULL ;
goto V_567;
}
}
F_330 ( & V_2 -> V_322 . V_468 , V_18 ) ;
while ( ( V_13 = F_383 ( & V_2 -> V_322 ) ) ) {
if ( F_310 ( V_13 ) -> V_132 . V_527 ) {
F_384 ( & V_2 -> V_322 , V_13 ) ;
break;
}
V_566 = F_310 ( V_13 ) -> V_132 . V_524 ;
F_16 ( V_13 ) ;
}
F_332 ( & V_2 -> V_322 . V_468 , V_18 ) ;
V_567:
if ( V_566 )
V_566 ( V_2 , V_443 ) ;
}
static void V_473 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 , V_321 ) ;
struct V_12 * V_13 ;
F_90 ( L_24 , V_2 -> V_107 ) ;
while ( ( V_13 = F_364 ( & V_2 -> V_323 ) ) ) {
F_323 ( V_2 , V_13 ) ;
if ( F_324 ( & V_2 -> V_522 ) ) {
F_325 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_316 , & V_2 -> V_18 ) ||
F_4 ( V_302 , & V_2 -> V_11 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_313 , & V_2 -> V_18 ) ) {
switch ( F_310 ( V_13 ) -> V_365 ) {
case V_500 :
case V_506 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_310 ( V_13 ) -> V_365 ) {
case V_501 :
F_90 ( L_119 , V_2 -> V_107 ) ;
F_385 ( V_2 , V_13 ) ;
break;
case V_500 :
F_90 ( L_120 , V_2 -> V_107 ) ;
F_371 ( V_2 , V_13 ) ;
break;
case V_506 :
F_90 ( L_121 , V_2 -> V_107 ) ;
F_376 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_474 ( struct V_385 * V_386 )
{
struct V_1 * V_2 = F_213 ( V_386 , struct V_1 , V_320 ) ;
struct V_12 * V_13 ;
F_90 ( L_122 , V_2 -> V_107 ,
F_324 ( & V_2 -> V_312 ) , F_327 ( & V_2 -> V_322 ) ) ;
if ( F_324 ( & V_2 -> V_312 ) ) {
V_13 = F_364 ( & V_2 -> V_322 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_325 ) ;
V_2 -> V_325 = F_380 ( V_13 , V_103 ) ;
if ( V_2 -> V_325 ) {
F_386 ( & V_2 -> V_312 ) ;
F_322 ( V_2 , V_13 ) ;
if ( F_4 ( V_138 , & V_2 -> V_18 ) )
F_387 ( & V_2 -> V_331 ) ;
else
F_388 ( & V_2 -> V_331 ,
V_282 + V_24 ) ;
} else {
F_381 ( & V_2 -> V_322 , V_13 ) ;
F_240 ( V_2 -> V_417 , & V_2 -> V_320 ) ;
}
}
}
void F_265 ( struct V_131 * V_132 )
{
struct V_568 V_188 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_15 = V_569 ;
F_112 ( V_132 , V_570 , sizeof( V_188 ) , & V_188 ) ;
}
void F_389 ( struct V_131 * V_132 )
{
struct V_571 V_572 ;
struct V_568 V_573 ;
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_451 ;
if ( F_268 ( V_132 , true , & V_451 ) )
return;
memset ( & V_572 , 0 , sizeof( V_572 ) ) ;
V_572 . type = V_574 ;
V_572 . V_575 = F_117 ( V_2 -> V_465 ) ;
V_572 . V_576 = F_117 ( V_2 -> V_466 ) ;
V_572 . V_577 = V_451 ;
F_112 ( V_132 , V_578 , sizeof( V_572 ) ,
& V_572 ) ;
memset ( & V_573 , 0 , sizeof( V_573 ) ) ;
V_573 . V_15 = V_579 ;
V_573 . V_580 = V_581 ;
F_112 ( V_132 , V_570 , sizeof( V_573 ) ,
& V_573 ) ;
}
static void F_390 ( struct V_1 * V_2 , T_5 V_443 )
{
if ( V_443 )
F_90 ( L_123
L_124 , V_443 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_131 V_132 ;
struct V_391 * V_392 ;
int V_16 ;
F_99 ( & V_132 , V_2 ) ;
if ( F_303 ( & V_2 -> V_442 ) ) {
if ( ! F_4 ( V_582 , & V_2 -> V_11 ) )
return;
F_265 ( & V_132 ) ;
F_90 ( L_125 , V_2 -> V_107 ) ;
} else {
V_392 = F_267 ( V_2 , V_432 , V_448 ) ;
if ( V_392 )
return;
if ( F_4 ( V_582 , & V_2 -> V_11 ) )
F_265 ( & V_132 ) ;
F_389 ( & V_132 ) ;
F_90 ( L_126 , V_2 -> V_107 ) ;
}
V_16 = F_101 ( & V_132 , F_390 ) ;
if ( V_16 )
F_95 ( L_127 , V_16 ) ;
}
