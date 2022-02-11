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
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->whitelist, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
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
static int F_31 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_30 , V_36 -> V_37 ) ;
}
static int F_32 ( struct V_27 * V_28 , void * V_31 )
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
F_33 ( V_26 -> V_56 ) ,
V_26 -> V_57 , V_26 -> V_58 , V_50 -> V_59 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_32 , V_36 -> V_37 ) ;
}
static int F_35 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_36 (p, n, &hdev->link_keys) {
struct V_62 * V_63 = F_37 ( V_31 , struct V_62 , V_64 ) ;
F_20 ( V_28 , L_7 , & V_63 -> V_40 , V_63 -> type ,
V_65 , V_63 -> V_45 , V_63 -> V_66 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_35 , V_36 -> V_37 ) ;
}
static int F_39 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_8 , V_2 -> V_55 [ 2 ] ,
V_2 -> V_55 [ 1 ] , V_2 -> V_55 [ 0 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_39 , V_36 -> V_37 ) ;
}
static int F_41 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_67 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_42 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
V_2 -> V_68 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_43 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_68 ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_1 F_44 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_69 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
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
return - V_70 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_69 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_69 , & V_2 -> V_11 ) ;
return V_6 ;
}
static T_1 F_46 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_71 , & V_2 -> V_72 ) ? 'Y' : 'N' ;
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
V_2 -> V_73 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_48 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_73 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_49 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 30 || V_45 > ( 60 * 60 * 24 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_74 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_50 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_74 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_51 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 > V_2 -> V_75 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_76 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_52 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_76 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_53 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 < V_2 -> V_76 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_75 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_54 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_75 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_55 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 > V_2 -> V_77 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_78 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_56 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_78 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_57 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 < V_2 -> V_78 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_77 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_58 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_77 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_7 V_79 ;
T_5 V_80 ;
F_19 ( V_2 ) ;
F_60 ( V_2 , & V_79 , & V_80 ) ;
F_20 ( V_28 , L_9 , & V_79 , V_80 ,
16 , V_2 -> V_81 , & V_2 -> V_82 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_59 , V_36 -> V_37 ) ;
}
static int F_62 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_83 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_62 , V_36 -> V_37 ) ;
}
static int F_64 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_84 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_64 , V_36 -> V_37 ) ;
}
static T_1 F_66 ( struct V_4 * V_4 ,
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
static T_1 F_67 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_70 ;
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
static int F_68 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->le_white_list, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_68 , V_36 -> V_37 ) ;
}
static int F_70 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_36 (p, n, &hdev->identity_resolving_keys) {
struct V_86 * V_81 = F_37 ( V_31 , struct V_86 , V_64 ) ;
F_20 ( V_28 , L_9 ,
& V_81 -> V_40 , V_81 -> V_80 ,
16 , V_81 -> V_45 , & V_81 -> V_82 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_70 ,
V_36 -> V_37 ) ;
}
static int F_72 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_36 (p, n, &hdev->long_term_keys) {
struct V_87 * V_88 = F_37 ( V_31 , struct V_87 , V_64 ) ;
F_20 ( V_28 , L_11 ,
& V_88 -> V_40 , V_88 -> V_41 , V_88 -> V_89 ,
V_88 -> type , V_88 -> V_90 , F_33 ( V_88 -> V_91 ) ,
F_73 ( V_88 -> rand ) , 16 , V_88 -> V_45 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_72 , V_36 -> V_37 ) ;
}
static int F_75 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 > V_2 -> V_92 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_93 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_76 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_93 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 < V_2 -> V_93 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_92 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_78 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_92 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_79 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 > 0x01f3 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_94 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_80 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_94 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_81 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x000a || V_45 > 0x0c80 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_95 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_82 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_95 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_83 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x01 || V_45 > 0x07 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_96 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_84 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_96 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_85 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0020 || V_45 > 0x4000 || V_45 > V_2 -> V_97 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_98 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_98 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_87 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0020 || V_45 > 0x4000 || V_45 < V_2 -> V_98 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_97 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_88 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_97 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_99 * V_31 ;
F_19 ( V_2 ) ;
F_26 (p, &hdev->le_conn_params, list) {
F_20 ( V_28 , L_12 , & V_31 -> V_79 , V_31 -> V_80 ,
V_31 -> V_100 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_89 , V_36 -> V_37 ) ;
}
static void F_91 ( struct V_1 * V_2 , T_5 V_101 )
{
F_92 ( L_13 , V_2 -> V_102 , V_101 ) ;
if ( V_2 -> V_103 == V_104 ) {
V_2 -> V_105 = V_101 ;
V_2 -> V_103 = V_106 ;
F_93 ( & V_2 -> V_107 ) ;
}
}
static void F_94 ( struct V_1 * V_2 , int V_16 )
{
F_92 ( L_14 , V_2 -> V_102 , V_16 ) ;
if ( V_2 -> V_103 == V_104 ) {
V_2 -> V_105 = V_16 ;
V_2 -> V_103 = V_108 ;
F_93 ( & V_2 -> V_107 ) ;
}
}
static struct V_12 * F_95 ( struct V_1 * V_2 , T_8 V_109 ,
T_5 V_3 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_12 * V_13 ;
F_19 ( V_2 ) ;
V_13 = V_2 -> V_114 ;
V_2 -> V_114 = NULL ;
F_22 ( V_2 ) ;
if ( ! V_13 )
return F_96 ( - V_115 ) ;
if ( V_13 -> V_116 < sizeof( * V_113 ) ) {
F_97 ( L_15 ) ;
goto V_117;
}
V_113 = ( void * ) V_13 -> V_26 ;
F_98 ( V_13 , V_118 ) ;
if ( V_3 ) {
if ( V_113 -> V_119 != V_3 )
goto V_117;
return V_13 ;
}
if ( V_113 -> V_119 != V_120 ) {
F_92 ( L_16 , V_113 -> V_119 ) ;
goto V_117;
}
if ( V_13 -> V_116 < sizeof( * V_111 ) ) {
F_97 ( L_17 ) ;
goto V_117;
}
V_111 = ( void * ) V_13 -> V_26 ;
F_98 ( V_13 , sizeof( * V_111 ) ) ;
if ( V_109 == F_33 ( V_111 -> V_109 ) )
return V_13 ;
F_92 ( L_18 , V_109 ,
F_33 ( V_111 -> V_109 ) ) ;
V_117:
F_16 ( V_13 ) ;
return F_96 ( - V_115 ) ;
}
struct V_12 * F_99 ( struct V_1 * V_2 , T_8 V_109 , T_9 V_121 ,
const void * V_122 , T_5 V_3 , T_9 V_123 )
{
F_100 ( V_124 , V_125 ) ;
struct V_126 V_127 ;
int V_16 = 0 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_101 ( & V_127 , V_2 ) ;
F_102 ( & V_127 , V_109 , V_121 , V_122 , V_3 ) ;
V_2 -> V_103 = V_104 ;
V_16 = F_103 ( & V_127 , F_91 ) ;
if ( V_16 < 0 )
return F_96 ( V_16 ) ;
F_104 ( & V_2 -> V_107 , & V_124 ) ;
F_105 ( V_128 ) ;
F_106 ( V_123 ) ;
F_107 ( & V_2 -> V_107 , & V_124 ) ;
if ( F_108 ( V_125 ) )
return F_96 ( - V_129 ) ;
switch ( V_2 -> V_103 ) {
case V_106 :
V_16 = - F_15 ( V_2 -> V_105 ) ;
break;
case V_108 :
V_16 = - V_2 -> V_105 ;
break;
default:
V_16 = - V_130 ;
break;
}
V_2 -> V_103 = V_2 -> V_105 = 0 ;
F_92 ( L_20 , V_2 -> V_102 , V_16 ) ;
if ( V_16 < 0 )
return F_96 ( V_16 ) ;
return F_95 ( V_2 , V_109 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_8 V_109 , T_9 V_121 ,
const void * V_122 , T_9 V_123 )
{
return F_99 ( V_2 , V_109 , V_121 , V_122 , 0 , V_123 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
void (* F_110)( struct V_126 * V_127 ,
unsigned long V_131 ) ,
unsigned long V_131 , T_10 V_123 )
{
struct V_126 V_127 ;
F_100 ( V_124 , V_125 ) ;
int V_16 = 0 ;
F_92 ( L_21 , V_2 -> V_102 ) ;
F_101 ( & V_127 , V_2 ) ;
V_2 -> V_103 = V_104 ;
F_110 ( & V_127 , V_131 ) ;
V_16 = F_103 ( & V_127 , F_91 ) ;
if ( V_16 < 0 ) {
V_2 -> V_103 = 0 ;
if ( V_16 == - V_115 )
return 0 ;
return V_16 ;
}
F_104 ( & V_2 -> V_107 , & V_124 ) ;
F_105 ( V_128 ) ;
F_106 ( V_123 ) ;
F_107 ( & V_2 -> V_107 , & V_124 ) ;
if ( F_108 ( V_125 ) )
return - V_129 ;
switch ( V_2 -> V_103 ) {
case V_106 :
V_16 = - F_15 ( V_2 -> V_105 ) ;
break;
case V_108 :
V_16 = - V_2 -> V_105 ;
break;
default:
V_16 = - V_130 ;
break;
}
V_2 -> V_103 = V_2 -> V_105 = 0 ;
F_92 ( L_20 , V_2 -> V_102 , V_16 ) ;
return V_16 ;
}
static int F_111 ( struct V_1 * V_2 ,
void (* V_127)( struct V_126 * V_127 ,
unsigned long V_131 ) ,
unsigned long V_131 , T_10 V_123 )
{
int V_132 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_132 = F_109 ( V_2 , V_127 , V_131 , V_123 ) ;
F_12 ( V_2 ) ;
return V_132 ;
}
static void F_112 ( struct V_126 * V_127 , unsigned long V_131 )
{
F_92 ( L_22 , V_127 -> V_2 -> V_102 , V_131 ) ;
F_113 ( V_133 , & V_127 -> V_2 -> V_18 ) ;
F_114 ( V_127 , V_25 , 0 , NULL ) ;
}
static void F_115 ( struct V_126 * V_127 )
{
V_127 -> V_2 -> V_134 = V_135 ;
F_114 ( V_127 , V_136 , 0 , NULL ) ;
F_114 ( V_127 , V_137 , 0 , NULL ) ;
F_114 ( V_127 , V_138 , 0 , NULL ) ;
}
static void F_116 ( struct V_126 * V_127 )
{
V_127 -> V_2 -> V_134 = V_139 ;
F_114 ( V_127 , V_137 , 0 , NULL ) ;
F_114 ( V_127 , V_140 , 0 , NULL ) ;
F_114 ( V_127 , V_136 , 0 , NULL ) ;
F_114 ( V_127 , V_141 , 0 , NULL ) ;
F_114 ( V_127 , V_142 , 0 , NULL ) ;
F_114 ( V_127 , V_143 , 0 , NULL ) ;
F_114 ( V_127 , V_144 , 0 , NULL ) ;
}
static void F_117 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
F_92 ( L_22 , V_2 -> V_102 , V_131 ) ;
if ( ! F_4 ( V_145 , & V_2 -> V_146 ) )
F_112 ( V_127 , 0 ) ;
switch ( V_2 -> V_147 ) {
case V_148 :
F_115 ( V_127 ) ;
break;
case V_149 :
F_116 ( V_127 ) ;
break;
default:
F_97 ( L_23 , V_2 -> V_147 ) ;
break;
}
}
static void F_118 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
T_11 V_122 ;
T_12 V_150 ;
F_114 ( V_127 , V_151 , 0 , NULL ) ;
F_114 ( V_127 , V_152 , 0 , NULL ) ;
F_114 ( V_127 , V_153 , 0 , NULL ) ;
F_114 ( V_127 , V_154 , 0 , NULL ) ;
F_114 ( V_127 , V_155 , 0 , NULL ) ;
F_114 ( V_127 , V_156 , 0 , NULL ) ;
V_150 = V_157 ;
F_114 ( V_127 , V_158 , 1 , & V_150 ) ;
V_122 = F_119 ( 0x7d00 ) ;
F_114 ( V_127 , V_159 , 2 , & V_122 ) ;
if ( V_2 -> V_160 != 31 && V_2 -> V_161 > V_162 ) {
F_114 ( V_127 , V_163 , 0 , NULL ) ;
F_114 ( V_127 , V_164 , 0 , NULL ) ;
}
}
static void F_120 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
F_114 ( V_127 , V_165 , 0 , NULL ) ;
F_114 ( V_127 , V_166 , 0 , NULL ) ;
F_114 ( V_127 , V_167 , 0 , NULL ) ;
F_114 ( V_127 , V_168 , 0 , NULL ) ;
F_114 ( V_127 , V_169 , 0 , NULL ) ;
if ( ! F_121 ( V_2 ) )
F_113 ( V_170 , & V_2 -> V_72 ) ;
}
static T_5 F_122 ( struct V_1 * V_2 )
{
if ( F_123 ( V_2 ) )
return 0x02 ;
if ( F_124 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_160 == 11 && V_2 -> V_171 == 0x00 &&
V_2 -> V_172 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_160 == 15 ) {
if ( V_2 -> V_171 == 0x03 && V_2 -> V_172 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_171 == 0x09 && V_2 -> V_172 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_171 == 0x00 && V_2 -> V_172 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_160 == 31 && V_2 -> V_171 == 0x2005 &&
V_2 -> V_172 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_125 ( struct V_126 * V_127 )
{
T_5 V_173 ;
V_173 = F_122 ( V_127 -> V_2 ) ;
F_114 ( V_127 , V_174 , 1 , & V_173 ) ;
}
static void F_126 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
T_5 V_175 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_161 < V_176 )
return;
if ( F_121 ( V_2 ) ) {
V_175 [ 4 ] |= 0x01 ;
V_175 [ 4 ] |= 0x02 ;
V_175 [ 4 ] |= 0x04 ;
V_175 [ 5 ] |= 0x08 ;
V_175 [ 5 ] |= 0x10 ;
} else {
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
V_175 [ 0 ] |= 0x10 ;
V_175 [ 1 ] |= 0x08 ;
V_175 [ 1 ] |= 0x20 ;
V_175 [ 1 ] |= 0x40 ;
V_175 [ 1 ] |= 0x80 ;
V_175 [ 2 ] |= 0x04 ;
V_175 [ 3 ] |= 0x02 ;
if ( V_2 -> V_35 [ 0 ] & V_177 ) {
V_175 [ 0 ] |= 0x80 ;
V_175 [ 5 ] |= 0x80 ;
}
}
if ( F_124 ( V_2 ) )
V_175 [ 4 ] |= 0x02 ;
if ( F_127 ( V_2 ) )
V_175 [ 5 ] |= 0x20 ;
if ( F_128 ( V_2 ) )
V_175 [ 5 ] |= 0x80 ;
if ( F_123 ( V_2 ) )
V_175 [ 5 ] |= 0x40 ;
if ( F_129 ( V_2 ) )
V_175 [ 7 ] |= 0x01 ;
if ( F_130 ( V_2 ) )
V_175 [ 6 ] |= 0x80 ;
if ( F_131 ( V_2 ) ) {
V_175 [ 6 ] |= 0x01 ;
V_175 [ 6 ] |= 0x02 ;
V_175 [ 6 ] |= 0x04 ;
V_175 [ 6 ] |= 0x08 ;
V_175 [ 6 ] |= 0x10 ;
V_175 [ 6 ] |= 0x20 ;
V_175 [ 7 ] |= 0x04 ;
V_175 [ 7 ] |= 0x08 ;
V_175 [ 7 ] |= 0x10 ;
}
if ( F_21 ( V_2 ) )
V_175 [ 7 ] |= 0x20 ;
F_114 ( V_127 , V_178 , sizeof( V_175 ) , V_175 ) ;
}
static void F_132 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
if ( F_121 ( V_2 ) )
F_118 ( V_127 ) ;
else
F_133 ( V_179 , & V_2 -> V_72 ) ;
if ( F_21 ( V_2 ) )
F_120 ( V_127 ) ;
if ( V_2 -> V_160 != 31 && V_2 -> V_161 > V_162 )
F_114 ( V_127 , V_140 , 0 , NULL ) ;
if ( F_131 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_180 , & V_2 -> V_72 ) ) {
T_5 V_173 = 0x01 ;
F_114 ( V_127 , V_181 ,
sizeof( V_173 ) , & V_173 ) ;
} else {
struct V_182 V_183 ;
memset ( V_2 -> V_184 , 0 , sizeof( V_2 -> V_184 ) ) ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
F_114 ( V_127 , V_185 , sizeof( V_183 ) , & V_183 ) ;
}
}
if ( F_124 ( V_2 ) )
F_125 ( V_127 ) ;
if ( F_134 ( V_2 ) )
F_114 ( V_127 , V_186 , 0 , NULL ) ;
if ( F_135 ( V_2 ) ) {
struct V_187 V_183 ;
V_183 . V_188 = 0x01 ;
F_114 ( V_127 , V_189 ,
sizeof( V_183 ) , & V_183 ) ;
}
if ( F_4 ( V_190 , & V_2 -> V_72 ) ) {
T_5 V_15 = 1 ;
F_114 ( V_127 , V_191 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_136 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_192 V_183 ;
T_8 V_193 = 0 ;
if ( F_137 ( V_2 ) )
V_193 |= V_194 ;
if ( F_138 ( V_2 ) )
V_193 |= V_195 ;
if ( F_139 ( V_2 ) )
V_193 |= V_196 ;
if ( F_140 ( V_2 ) )
V_193 |= V_197 ;
V_183 . V_198 = F_119 ( V_193 ) ;
F_114 ( V_127 , V_199 , sizeof( V_183 ) , & V_183 ) ;
}
static void F_141 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_200 V_183 ;
if ( ! F_121 ( V_2 ) )
return;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
if ( F_4 ( V_170 , & V_2 -> V_72 ) ) {
V_183 . V_201 = 0x01 ;
V_183 . V_202 = 0x00 ;
}
if ( V_183 . V_201 != F_142 ( V_2 ) )
F_114 ( V_127 , V_203 , sizeof( V_183 ) ,
& V_183 ) ;
}
static void F_143 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
T_5 V_175 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_144 ( V_2 ) ) {
V_175 [ 1 ] |= 0x40 ;
V_175 [ 1 ] |= 0x80 ;
V_175 [ 2 ] |= 0x10 ;
V_175 [ 2 ] |= 0x20 ;
}
if ( F_145 ( V_2 ) ) {
V_175 [ 2 ] |= 0x01 ;
V_175 [ 2 ] |= 0x02 ;
V_175 [ 2 ] |= 0x04 ;
V_175 [ 2 ] |= 0x08 ;
}
if ( F_146 ( V_2 ) || V_2 -> V_35 [ 0 ] & V_204 )
V_175 [ 2 ] |= 0x80 ;
F_114 ( V_127 , V_205 , sizeof( V_175 ) , V_175 ) ;
}
static void F_147 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
T_5 V_31 ;
F_126 ( V_127 ) ;
if ( V_2 -> V_206 [ 6 ] & 0x80 &&
! F_4 ( V_207 , & V_2 -> V_146 ) ) {
struct V_208 V_183 ;
F_148 ( & V_183 . V_40 , V_209 ) ;
V_183 . V_210 = 0x01 ;
F_114 ( V_127 , V_211 ,
sizeof( V_183 ) , & V_183 ) ;
}
if ( V_2 -> V_206 [ 5 ] & 0x10 )
F_136 ( V_127 ) ;
if ( F_21 ( V_2 ) ) {
T_5 V_175 [ 8 ] ;
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
V_175 [ 0 ] = 0x0f ;
if ( V_2 -> V_35 [ 0 ] & V_177 )
V_175 [ 0 ] |= 0x10 ;
if ( V_2 -> V_35 [ 0 ] & V_212 )
V_175 [ 0 ] |= 0x20 ;
F_114 ( V_127 , V_213 , sizeof( V_175 ) ,
V_175 ) ;
if ( V_2 -> V_206 [ 25 ] & 0x40 ) {
F_114 ( V_127 , V_214 , 0 , NULL ) ;
}
F_141 ( V_127 ) ;
}
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_187 V_183 ;
V_183 . V_188 = V_31 ;
F_114 ( V_127 , V_189 ,
sizeof( V_183 ) , & V_183 ) ;
}
}
static void F_149 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
if ( V_2 -> V_206 [ 22 ] & 0x04 )
F_143 ( V_127 ) ;
if ( V_2 -> V_206 [ 29 ] & 0x20 )
F_114 ( V_127 , V_215 , 0 , NULL ) ;
if ( V_2 -> V_206 [ 30 ] & 0x08 )
F_114 ( V_127 , V_216 , 0 , NULL ) ;
if ( F_150 ( V_2 ) )
F_114 ( V_127 , V_217 , 0 , NULL ) ;
if ( ( F_151 ( V_2 ) ||
F_4 ( V_69 , & V_2 -> V_11 ) ) &&
F_4 ( V_218 , & V_2 -> V_72 ) ) {
T_5 V_219 = 0x01 ;
F_114 ( V_127 , V_220 ,
sizeof( V_219 ) , & V_219 ) ;
}
}
static int F_152 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_109 ( V_2 , F_117 , 0 , V_221 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_222 , & V_2 -> V_72 ) ) {
F_153 ( L_24 , 0644 , V_2 -> V_223 , V_2 ,
& V_224 ) ;
}
if ( V_2 -> V_147 != V_148 )
return 0 ;
V_16 = F_109 ( V_2 , F_132 , 0 , V_221 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_109 ( V_2 , F_147 , 0 , V_221 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_109 ( V_2 , F_149 , 0 , V_221 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_222 , & V_2 -> V_72 ) )
return 0 ;
F_153 ( L_25 , 0444 , V_2 -> V_223 , V_2 ,
& V_225 ) ;
F_154 ( L_26 , 0444 , V_2 -> V_223 ,
& V_2 -> V_160 ) ;
F_155 ( L_27 , 0444 , V_2 -> V_223 , & V_2 -> V_161 ) ;
F_154 ( L_28 , 0444 , V_2 -> V_223 , & V_2 -> V_171 ) ;
F_153 ( L_29 , 0444 , V_2 -> V_223 , V_2 ,
& V_226 ) ;
F_153 ( L_30 , 0444 , V_2 -> V_223 , V_2 ,
& V_227 ) ;
F_153 ( L_31 , 0444 , V_2 -> V_223 , V_2 , & V_228 ) ;
F_153 ( L_32 , 0644 , V_2 -> V_223 , V_2 ,
& V_229 ) ;
F_153 ( L_33 , 0644 , V_2 -> V_223 , V_2 ,
& V_230 ) ;
if ( F_121 ( V_2 ) ) {
F_153 ( L_34 , 0444 , V_2 -> V_223 ,
V_2 , & V_231 ) ;
F_153 ( L_35 , 0400 , V_2 -> V_223 ,
V_2 , & V_232 ) ;
F_153 ( L_36 , 0444 , V_2 -> V_223 ,
V_2 , & V_233 ) ;
F_153 ( L_37 , 0444 , V_2 -> V_223 ,
V_2 , & V_234 ) ;
}
if ( F_131 ( V_2 ) ) {
F_153 ( L_38 , 0644 , V_2 -> V_223 ,
V_2 , & V_235 ) ;
F_153 ( L_39 , 0644 , V_2 -> V_223 ,
V_2 , & V_236 ) ;
F_153 ( L_40 , 0444 , V_2 -> V_223 ,
V_2 , & V_237 ) ;
}
if ( F_139 ( V_2 ) ) {
F_153 ( L_41 , 0644 , V_2 -> V_223 ,
V_2 , & V_238 ) ;
F_153 ( L_42 , 0644 , V_2 -> V_223 ,
V_2 , & V_239 ) ;
F_153 ( L_43 , 0644 , V_2 -> V_223 ,
V_2 , & V_240 ) ;
}
if ( F_21 ( V_2 ) ) {
F_153 ( L_44 , 0400 , V_2 -> V_223 ,
V_2 , & V_241 ) ;
F_153 ( L_45 , 0644 , V_2 -> V_223 ,
V_2 , & V_242 ) ;
F_153 ( L_46 , 0444 , V_2 -> V_223 ,
V_2 , & V_243 ) ;
F_153 ( L_47 , 0444 , V_2 -> V_223 ,
V_2 , & V_244 ) ;
if ( F_156 ( & V_2 -> V_40 , V_209 ) )
F_153 ( L_48 , 0644 ,
V_2 -> V_223 , V_2 ,
& V_245 ) ;
F_155 ( L_49 , 0444 , V_2 -> V_223 ,
& V_2 -> V_246 ) ;
F_153 ( L_50 , 0444 , V_2 -> V_223 , V_2 ,
& V_247 ) ;
F_153 ( L_51 , 0400 ,
V_2 -> V_223 , V_2 ,
& V_248 ) ;
F_153 ( L_52 , 0400 , V_2 -> V_223 ,
V_2 , & V_249 ) ;
F_153 ( L_53 , 0644 , V_2 -> V_223 ,
V_2 , & V_250 ) ;
F_153 ( L_54 , 0644 , V_2 -> V_223 ,
V_2 , & V_251 ) ;
F_153 ( L_55 , 0644 , V_2 -> V_223 ,
V_2 , & V_252 ) ;
F_153 ( L_56 , 0644 , V_2 -> V_223 ,
V_2 , & V_253 ) ;
F_153 ( L_57 , 0644 , V_2 -> V_223 ,
V_2 , & V_254 ) ;
F_153 ( L_58 , 0644 , V_2 -> V_223 ,
V_2 , & V_255 ) ;
F_153 ( L_59 , 0644 , V_2 -> V_223 ,
V_2 , & V_256 ) ;
F_153 ( L_60 , 0444 , V_2 -> V_223 , V_2 ,
& V_257 ) ;
F_154 ( L_61 , 0644 ,
V_2 -> V_223 ,
& V_2 -> V_258 ) ;
F_157 ( V_2 ) ;
}
return 0 ;
}
static void F_158 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
F_92 ( L_22 , V_2 -> V_102 , V_131 ) ;
if ( ! F_4 ( V_145 , & V_2 -> V_146 ) )
F_112 ( V_127 , 0 ) ;
F_114 ( V_127 , V_137 , 0 , NULL ) ;
if ( V_2 -> V_259 )
F_114 ( V_127 , V_138 , 0 , NULL ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_16 ;
if ( F_4 ( V_260 , & V_2 -> V_146 ) )
return 0 ;
V_16 = F_109 ( V_2 , F_158 , 0 , V_221 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_160 ( struct V_126 * V_127 , unsigned long V_131 )
{
T_12 V_261 = V_131 ;
F_92 ( L_62 , V_127 -> V_2 -> V_102 , V_261 ) ;
F_114 ( V_127 , V_262 , 1 , & V_261 ) ;
}
static void F_161 ( struct V_126 * V_127 , unsigned long V_131 )
{
T_12 V_263 = V_131 ;
F_92 ( L_62 , V_127 -> V_2 -> V_102 , V_263 ) ;
F_114 ( V_127 , V_191 , 1 , & V_263 ) ;
}
static void F_162 ( struct V_126 * V_127 , unsigned long V_131 )
{
T_12 V_264 = V_131 ;
F_92 ( L_62 , V_127 -> V_2 -> V_102 , V_264 ) ;
F_114 ( V_127 , V_265 , 1 , & V_264 ) ;
}
static void F_163 ( struct V_126 * V_127 , unsigned long V_131 )
{
T_11 V_198 = F_119 ( V_131 ) ;
F_92 ( L_62 , V_127 -> V_2 -> V_102 , V_198 ) ;
F_114 ( V_127 , V_199 , 2 , & V_198 ) ;
}
struct V_1 * F_164 ( int V_266 )
{
struct V_1 * V_2 = NULL , * V_267 ;
F_92 ( L_63 , V_266 ) ;
if ( V_266 < 0 )
return NULL ;
F_165 ( & V_268 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_267 -> V_269 == V_266 ) {
V_2 = F_166 ( V_267 ) ;
break;
}
}
F_167 ( & V_268 ) ;
return V_2 ;
}
bool F_168 ( struct V_1 * V_2 )
{
struct V_46 * V_270 = & V_2 -> V_48 ;
switch ( V_270 -> V_271 ) {
case V_272 :
case V_273 :
return true ;
default:
return false ;
}
}
void F_169 ( struct V_1 * V_2 , int V_271 )
{
int V_274 = V_2 -> V_48 . V_271 ;
F_92 ( L_64 , V_2 -> V_102 , V_2 -> V_48 . V_271 , V_271 ) ;
if ( V_274 == V_271 )
return;
V_2 -> V_48 . V_271 = V_271 ;
switch ( V_271 ) {
case V_275 :
F_170 ( V_2 ) ;
if ( V_274 != V_276 )
F_171 ( V_2 , 0 ) ;
break;
case V_276 :
break;
case V_272 :
F_171 ( V_2 , 1 ) ;
break;
case V_273 :
break;
case V_277 :
break;
}
}
void F_172 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_61 ;
F_173 (p, n, &cache->all, all) {
F_174 ( & V_31 -> V_278 ) ;
F_175 ( V_31 ) ;
}
F_176 ( & V_47 -> V_279 ) ;
F_176 ( & V_47 -> V_280 ) ;
}
struct V_49 * F_177 ( struct V_1 * V_2 ,
T_7 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_92 ( L_65 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_156 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_178 ( struct V_1 * V_2 ,
T_7 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_92 ( L_65 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_156 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_179 ( struct V_1 * V_2 ,
T_7 * V_40 ,
int V_271 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_92 ( L_66 , V_47 , V_40 , V_271 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_156 ( V_40 , V_209 ) && V_50 -> V_281 == V_271 )
return V_50 ;
if ( ! F_156 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_180 ( struct V_1 * V_2 ,
struct V_49 * V_282 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_60 * V_283 = & V_47 -> V_280 ;
struct V_49 * V_31 ;
F_174 ( & V_282 -> V_64 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_281 != V_284 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_282 -> V_26 . V_57 ) )
break;
V_283 = & V_31 -> V_64 ;
}
F_181 ( & V_282 -> V_64 , V_283 ) ;
}
T_9 F_182 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_285 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_282 ;
T_9 V_18 = 0 ;
F_92 ( L_65 , V_47 , & V_26 -> V_40 ) ;
F_183 ( V_2 , & V_26 -> V_40 ) ;
if ( ! V_26 -> V_58 )
V_18 |= V_286 ;
V_282 = F_177 ( V_2 , & V_26 -> V_40 ) ;
if ( V_282 ) {
if ( ! V_282 -> V_26 . V_58 )
V_18 |= V_286 ;
if ( V_282 -> V_281 == V_287 &&
V_26 -> V_57 != V_282 -> V_26 . V_57 ) {
V_282 -> V_26 . V_57 = V_26 -> V_57 ;
F_180 ( V_2 , V_282 ) ;
}
goto V_288;
}
V_282 = F_184 ( sizeof( * V_282 ) , V_289 ) ;
if ( ! V_282 ) {
V_18 |= V_290 ;
goto V_291;
}
F_181 ( & V_282 -> V_278 , & V_47 -> V_278 ) ;
if ( V_285 ) {
V_282 -> V_281 = V_292 ;
} else {
V_282 -> V_281 = V_293 ;
F_181 ( & V_282 -> V_64 , & V_47 -> V_279 ) ;
}
V_288:
if ( V_285 && V_282 -> V_281 != V_292 &&
V_282 -> V_281 != V_284 ) {
V_282 -> V_281 = V_292 ;
F_174 ( & V_282 -> V_64 ) ;
}
memcpy ( & V_282 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_282 -> V_59 = V_294 ;
V_47 -> V_59 = V_294 ;
if ( V_282 -> V_281 == V_293 )
V_18 |= V_290 ;
V_291:
return V_18 ;
}
static int F_185 ( struct V_1 * V_2 , int V_295 , T_12 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_296 * V_297 = (struct V_296 * ) V_9 ;
struct V_49 * V_50 ;
int V_298 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_298 >= V_295 )
break;
F_148 ( & V_297 -> V_40 , & V_26 -> V_40 ) ;
V_297 -> V_52 = V_26 -> V_52 ;
V_297 -> V_53 = V_26 -> V_53 ;
V_297 -> V_54 = V_26 -> V_54 ;
memcpy ( V_297 -> V_55 , V_26 -> V_55 , 3 ) ;
V_297 -> V_56 = V_26 -> V_56 ;
V_297 ++ ;
V_298 ++ ;
}
F_92 ( L_67 , V_47 , V_298 ) ;
return V_298 ;
}
static void F_186 ( struct V_126 * V_127 , unsigned long V_131 )
{
struct V_299 * V_300 = (struct V_299 * ) V_131 ;
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_301 V_183 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( F_4 ( V_302 , & V_2 -> V_18 ) )
return;
memcpy ( & V_183 . V_303 , & V_300 -> V_303 , 3 ) ;
V_183 . V_304 = V_300 -> V_304 ;
V_183 . V_305 = V_300 -> V_305 ;
F_114 ( V_127 , V_306 , sizeof( V_183 ) , & V_183 ) ;
}
int F_187 ( void T_2 * V_307 )
{
T_12 T_2 * V_29 = V_307 ;
struct V_299 V_300 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_308 = 0 , V_309 ;
long V_310 ;
T_12 * V_9 ;
if ( F_8 ( & V_300 , V_29 , sizeof( V_300 ) ) )
return - V_20 ;
V_2 = F_164 ( V_300 . V_311 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_16 = - V_70 ;
goto V_291;
}
if ( F_4 ( V_314 , & V_2 -> V_72 ) ) {
V_16 = - V_315 ;
goto V_291;
}
if ( V_2 -> V_147 != V_148 ) {
V_16 = - V_315 ;
goto V_291;
}
if ( ! F_4 ( V_179 , & V_2 -> V_72 ) ) {
V_16 = - V_315 ;
goto V_291;
}
F_19 ( V_2 ) ;
if ( F_188 ( V_2 ) > V_316 ||
F_189 ( V_2 ) || V_300 . V_18 & V_317 ) {
F_172 ( V_2 ) ;
V_308 = 1 ;
}
F_22 ( V_2 ) ;
V_310 = V_300 . V_304 * F_190 ( 2000 ) ;
if ( V_308 ) {
V_16 = F_111 ( V_2 , F_186 , ( unsigned long ) & V_300 ,
V_310 ) ;
if ( V_16 < 0 )
goto V_291;
if ( F_191 ( & V_2 -> V_18 , V_302 ,
V_128 ) )
return - V_129 ;
}
V_309 = ( V_300 . V_305 == 0 ) ? 255 : V_300 . V_305 ;
V_9 = F_192 ( sizeof( struct V_296 ) * V_309 , V_289 ) ;
if ( ! V_9 ) {
V_16 = - V_318 ;
goto V_291;
}
F_19 ( V_2 ) ;
V_300 . V_305 = F_185 ( V_2 , V_309 , V_9 ) ;
F_22 ( V_2 ) ;
F_92 ( L_68 , V_300 . V_305 ) ;
if ( ! F_193 ( V_29 , & V_300 , sizeof( V_300 ) ) ) {
V_29 += sizeof( V_300 ) ;
if ( F_193 ( V_29 , V_9 , sizeof( struct V_296 ) *
V_300 . V_305 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_175 ( V_9 ) ;
V_291:
F_194 ( V_2 ) ;
return V_16 ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_132 = 0 ;
F_92 ( L_69 , V_2 -> V_102 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_319 , & V_2 -> V_72 ) ) {
V_132 = - V_312 ;
goto V_291;
}
if ( ! F_4 ( V_222 , & V_2 -> V_72 ) &&
! F_4 ( V_320 , & V_2 -> V_72 ) ) {
if ( F_4 ( V_321 , & V_2 -> V_72 ) ) {
V_132 = - V_322 ;
goto V_291;
}
if ( ! F_4 ( V_313 , & V_2 -> V_72 ) &&
V_2 -> V_147 == V_148 &&
! F_156 ( & V_2 -> V_40 , V_209 ) &&
! F_156 ( & V_2 -> V_84 , V_209 ) ) {
V_132 = - V_323 ;
goto V_291;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_132 = - V_22 ;
goto V_291;
}
if ( V_2 -> V_324 ( V_2 ) ) {
V_132 = - V_325 ;
goto V_291;
}
F_196 ( & V_2 -> V_326 , 1 ) ;
F_113 ( V_327 , & V_2 -> V_18 ) ;
if ( F_4 ( V_222 , & V_2 -> V_72 ) ) {
if ( V_2 -> V_328 )
V_132 = V_2 -> V_328 ( V_2 ) ;
if ( F_4 ( V_329 , & V_2 -> V_146 ) ||
F_4 ( V_330 , & V_2 -> V_146 ) )
F_113 ( V_314 , & V_2 -> V_72 ) ;
if ( F_4 ( V_314 , & V_2 -> V_72 ) )
V_132 = F_159 ( V_2 ) ;
}
if ( F_4 ( V_320 , & V_2 -> V_72 ) ) {
if ( F_156 ( & V_2 -> V_331 , V_209 ) &&
V_2 -> V_259 )
V_132 = V_2 -> V_259 ( V_2 , & V_2 -> V_331 ) ;
else
V_132 = - V_323 ;
}
if ( ! V_132 ) {
if ( ! F_4 ( V_314 , & V_2 -> V_72 ) &&
! F_4 ( V_313 , & V_2 -> V_72 ) )
V_132 = F_152 ( V_2 ) ;
}
F_133 ( V_327 , & V_2 -> V_18 ) ;
if ( ! V_132 ) {
F_166 ( V_2 ) ;
F_113 ( V_332 , & V_2 -> V_72 ) ;
F_113 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_333 ) ;
if ( ! F_4 ( V_222 , & V_2 -> V_72 ) &&
! F_4 ( V_320 , & V_2 -> V_72 ) &&
! F_4 ( V_314 , & V_2 -> V_72 ) &&
! F_4 ( V_313 , & V_2 -> V_72 ) &&
V_2 -> V_147 == V_148 ) {
F_19 ( V_2 ) ;
F_197 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_198 ( & V_2 -> V_334 ) ;
F_198 ( & V_2 -> V_335 ) ;
F_198 ( & V_2 -> V_336 ) ;
F_199 ( & V_2 -> V_337 ) ;
F_199 ( & V_2 -> V_338 ) ;
if ( V_2 -> V_339 )
V_2 -> V_339 ( V_2 ) ;
if ( V_2 -> V_340 ) {
F_16 ( V_2 -> V_340 ) ;
V_2 -> V_340 = NULL ;
}
V_2 -> V_341 ( V_2 ) ;
V_2 -> V_18 &= F_200 ( V_342 ) ;
}
V_291:
F_12 ( V_2 ) ;
return V_132 ;
}
int F_201 ( T_13 V_343 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_164 ( V_343 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_314 , & V_2 -> V_72 ) &&
! F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_16 = - V_315 ;
goto V_291;
}
if ( F_202 ( V_344 , & V_2 -> V_72 ) )
F_203 ( & V_2 -> V_345 ) ;
F_204 ( V_2 -> V_346 ) ;
if ( ! F_4 ( V_313 , & V_2 -> V_72 ) &&
! F_4 ( V_347 , & V_2 -> V_72 ) )
F_113 ( V_348 , & V_2 -> V_72 ) ;
V_16 = F_195 ( V_2 ) ;
V_291:
F_194 ( V_2 ) ;
return V_16 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_99 * V_31 ;
F_26 (p, &hdev->le_conn_params, list) {
if ( V_31 -> V_349 ) {
F_206 ( V_31 -> V_349 ) ;
F_207 ( V_31 -> V_349 ) ;
V_31 -> V_349 = NULL ;
}
F_208 ( & V_31 -> V_350 ) ;
}
F_92 ( L_70 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
F_92 ( L_69 , V_2 -> V_102 , V_2 ) ;
F_203 ( & V_2 -> V_345 ) ;
F_94 ( V_2 , V_312 ) ;
F_10 ( V_2 ) ;
if ( ! F_202 ( V_17 , & V_2 -> V_18 ) ) {
F_210 ( & V_2 -> V_351 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_198 ( & V_2 -> V_334 ) ;
F_198 ( & V_2 -> V_336 ) ;
if ( V_2 -> V_352 > 0 ) {
F_203 ( & V_2 -> V_353 ) ;
V_2 -> V_352 = 0 ;
F_133 ( V_354 , & V_2 -> V_72 ) ;
F_133 ( V_355 , & V_2 -> V_72 ) ;
}
if ( F_202 ( V_356 , & V_2 -> V_72 ) )
F_203 ( & V_2 -> V_357 ) ;
F_210 ( & V_2 -> V_358 ) ;
if ( F_4 ( V_347 , & V_2 -> V_72 ) )
F_210 ( & V_2 -> V_359 ) ;
F_19 ( V_2 ) ;
F_172 ( V_2 ) ;
F_205 ( V_2 ) ;
F_211 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_360 ) ;
if ( V_2 -> V_339 )
V_2 -> V_339 ( V_2 ) ;
F_199 ( & V_2 -> V_337 ) ;
F_196 ( & V_2 -> V_326 , 1 ) ;
if ( ! F_4 ( V_344 , & V_2 -> V_72 ) &&
! F_4 ( V_314 , & V_2 -> V_72 ) &&
F_4 ( V_145 , & V_2 -> V_146 ) ) {
F_113 ( V_327 , & V_2 -> V_18 ) ;
F_109 ( V_2 , F_112 , 0 , V_24 ) ;
F_133 ( V_327 , & V_2 -> V_18 ) ;
}
F_198 ( & V_2 -> V_335 ) ;
F_199 ( & V_2 -> V_338 ) ;
F_199 ( & V_2 -> V_337 ) ;
F_199 ( & V_2 -> V_361 ) ;
if ( V_2 -> V_340 ) {
F_210 ( & V_2 -> V_351 ) ;
F_16 ( V_2 -> V_340 ) ;
V_2 -> V_340 = NULL ;
}
F_16 ( V_2 -> V_114 ) ;
V_2 -> V_114 = NULL ;
V_2 -> V_341 ( V_2 ) ;
V_2 -> V_18 &= F_200 ( V_342 ) ;
V_2 -> V_72 &= ~ V_362 ;
if ( ! F_202 ( V_344 , & V_2 -> V_72 ) ) {
if ( V_2 -> V_147 == V_148 ) {
F_19 ( V_2 ) ;
F_197 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
}
}
V_2 -> V_363 = V_364 ;
memset ( V_2 -> V_184 , 0 , sizeof( V_2 -> V_184 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_148 ( & V_2 -> V_83 , V_209 ) ;
F_12 ( V_2 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
int F_212 ( T_13 V_343 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_164 ( V_343 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_16 = - V_70 ;
goto V_291;
}
if ( F_202 ( V_344 , & V_2 -> V_72 ) )
F_203 ( & V_2 -> V_345 ) ;
V_16 = F_209 ( V_2 ) ;
V_291:
F_194 ( V_2 ) ;
return V_16 ;
}
int F_213 ( T_13 V_343 )
{
struct V_1 * V_2 ;
int V_132 = 0 ;
V_2 = F_164 ( V_343 ) ;
if ( ! V_2 )
return - V_312 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_132 = - V_19 ;
goto V_291;
}
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_132 = - V_70 ;
goto V_291;
}
if ( F_4 ( V_314 , & V_2 -> V_72 ) ) {
V_132 = - V_315 ;
goto V_291;
}
F_199 ( & V_2 -> V_338 ) ;
F_199 ( & V_2 -> V_337 ) ;
F_19 ( V_2 ) ;
F_172 ( V_2 ) ;
F_211 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_339 )
V_2 -> V_339 ( V_2 ) ;
F_196 ( & V_2 -> V_326 , 1 ) ;
V_2 -> V_365 = 0 ; V_2 -> V_366 = 0 ; V_2 -> V_367 = 0 ;
V_132 = F_109 ( V_2 , F_112 , 0 , V_221 ) ;
V_291:
F_12 ( V_2 ) ;
F_194 ( V_2 ) ;
return V_132 ;
}
int F_214 ( T_13 V_343 )
{
struct V_1 * V_2 ;
int V_132 = 0 ;
V_2 = F_164 ( V_343 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_132 = - V_70 ;
goto V_291;
}
if ( F_4 ( V_314 , & V_2 -> V_72 ) ) {
V_132 = - V_315 ;
goto V_291;
}
memset ( & V_2 -> V_368 , 0 , sizeof( struct V_369 ) ) ;
V_291:
F_194 ( V_2 ) ;
return V_132 ;
}
static void F_215 ( struct V_1 * V_2 , T_5 V_261 )
{
bool V_370 , V_371 ;
F_92 ( L_71 , V_2 -> V_102 , V_261 ) ;
if ( ( V_261 & V_372 ) )
V_370 = ! F_216 ( V_373 ,
& V_2 -> V_72 ) ;
else
V_370 = F_202 ( V_373 ,
& V_2 -> V_72 ) ;
if ( ( V_261 & V_374 ) ) {
V_371 = ! F_216 ( V_354 ,
& V_2 -> V_72 ) ;
} else {
F_133 ( V_355 , & V_2 -> V_72 ) ;
V_371 = F_202 ( V_354 ,
& V_2 -> V_72 ) ;
}
if ( ! F_4 ( V_347 , & V_2 -> V_72 ) )
return;
if ( V_370 || V_371 ) {
F_113 ( V_179 , & V_2 -> V_72 ) ;
if ( F_4 ( V_170 , & V_2 -> V_72 ) )
F_217 ( V_2 ) ;
F_218 ( V_2 ) ;
}
}
int F_219 ( unsigned int V_375 , void T_2 * V_307 )
{
struct V_1 * V_2 ;
struct V_376 V_377 ;
int V_16 = 0 ;
if ( F_8 ( & V_377 , V_307 , sizeof( V_377 ) ) )
return - V_20 ;
V_2 = F_164 ( V_377 . V_311 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
V_16 = - V_70 ;
goto V_291;
}
if ( F_4 ( V_314 , & V_2 -> V_72 ) ) {
V_16 = - V_315 ;
goto V_291;
}
if ( V_2 -> V_147 != V_148 ) {
V_16 = - V_315 ;
goto V_291;
}
if ( ! F_4 ( V_179 , & V_2 -> V_72 ) ) {
V_16 = - V_315 ;
goto V_291;
}
switch ( V_375 ) {
case V_378 :
V_16 = F_111 ( V_2 , F_161 , V_377 . V_379 ,
V_221 ) ;
break;
case V_380 :
if ( ! F_220 ( V_2 ) ) {
V_16 = - V_315 ;
break;
}
if ( ! F_4 ( V_381 , & V_2 -> V_18 ) ) {
V_16 = F_111 ( V_2 , F_161 , V_377 . V_379 ,
V_221 ) ;
if ( V_16 )
break;
}
V_16 = F_111 ( V_2 , F_162 , V_377 . V_379 ,
V_221 ) ;
break;
case V_382 :
V_16 = F_111 ( V_2 , F_160 , V_377 . V_379 ,
V_221 ) ;
if ( ! V_16 )
F_215 ( V_2 , V_377 . V_379 ) ;
break;
case V_383 :
V_16 = F_111 ( V_2 , F_163 , V_377 . V_379 ,
V_221 ) ;
break;
case V_384 :
V_2 -> V_385 = ( ( T_13 ) V_377 . V_379 ) &
( V_386 | V_387 ) ;
break;
case V_388 :
V_2 -> V_389 = ( T_13 ) V_377 . V_379 ;
break;
case V_390 :
V_2 -> V_391 = * ( ( T_13 * ) & V_377 . V_379 + 1 ) ;
V_2 -> V_392 = * ( ( T_13 * ) & V_377 . V_379 + 0 ) ;
break;
case V_393 :
V_2 -> V_394 = * ( ( T_13 * ) & V_377 . V_379 + 1 ) ;
V_2 -> V_395 = * ( ( T_13 * ) & V_377 . V_379 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_291:
F_194 ( V_2 ) ;
return V_16 ;
}
int F_221 ( void T_2 * V_307 )
{
struct V_1 * V_2 ;
struct V_396 * V_397 ;
struct V_376 * V_377 ;
int V_61 = 0 , V_398 , V_16 ;
T_13 V_399 ;
if ( F_222 ( V_399 , ( T_13 T_2 * ) V_307 ) )
return - V_20 ;
if ( ! V_399 || V_399 > ( V_400 * 2 ) / sizeof( * V_377 ) )
return - V_21 ;
V_398 = sizeof( * V_397 ) + V_399 * sizeof( * V_377 ) ;
V_397 = F_184 ( V_398 , V_289 ) ;
if ( ! V_397 )
return - V_318 ;
V_377 = V_397 -> V_401 ;
F_165 ( & V_268 ) ;
F_26 (hdev, &hci_dev_list, list) {
unsigned long V_18 = V_2 -> V_18 ;
if ( F_4 ( V_344 , & V_2 -> V_72 ) )
V_18 &= ~ F_200 ( V_17 ) ;
( V_377 + V_61 ) -> V_311 = V_2 -> V_269 ;
( V_377 + V_61 ) -> V_379 = V_18 ;
if ( ++ V_61 >= V_399 )
break;
}
F_167 ( & V_268 ) ;
V_397 -> V_399 = V_61 ;
V_398 = sizeof( * V_397 ) + V_61 * sizeof( * V_377 ) ;
V_16 = F_193 ( V_307 , V_397 , V_398 ) ;
F_175 ( V_397 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_223 ( void T_2 * V_307 )
{
struct V_1 * V_2 ;
struct V_402 V_403 ;
unsigned long V_18 ;
int V_16 = 0 ;
if ( F_8 ( & V_403 , V_307 , sizeof( V_403 ) ) )
return - V_20 ;
V_2 = F_164 ( V_403 . V_311 ) ;
if ( ! V_2 )
return - V_312 ;
if ( F_4 ( V_344 , & V_2 -> V_72 ) )
V_18 = V_2 -> V_18 & ~ F_200 ( V_17 ) ;
else
V_18 = V_2 -> V_18 ;
strcpy ( V_403 . V_102 , V_2 -> V_102 ) ;
V_403 . V_40 = V_2 -> V_40 ;
V_403 . type = ( V_2 -> V_404 & 0x0f ) | ( ( V_2 -> V_147 & 0x03 ) << 4 ) ;
V_403 . V_18 = V_18 ;
V_403 . V_389 = V_2 -> V_389 ;
if ( F_121 ( V_2 ) ) {
V_403 . V_391 = V_2 -> V_391 ;
V_403 . V_392 = V_2 -> V_392 ;
V_403 . V_394 = V_2 -> V_394 ;
V_403 . V_395 = V_2 -> V_395 ;
} else {
V_403 . V_391 = V_2 -> V_405 ;
V_403 . V_392 = V_2 -> V_406 ;
V_403 . V_394 = 0 ;
V_403 . V_395 = 0 ;
}
V_403 . V_193 = V_2 -> V_193 ;
V_403 . V_385 = V_2 -> V_385 ;
memcpy ( & V_403 . V_368 , & V_2 -> V_368 , sizeof( V_403 . V_368 ) ) ;
memcpy ( & V_403 . V_34 , & V_2 -> V_34 , sizeof( V_403 . V_34 ) ) ;
if ( F_193 ( V_307 , & V_403 , sizeof( V_403 ) ) )
V_16 = - V_20 ;
F_194 ( V_2 ) ;
return V_16 ;
}
static int F_224 ( void * V_26 , bool V_407 )
{
struct V_1 * V_2 = V_26 ;
F_92 ( L_72 , V_2 , V_2 -> V_102 , V_407 ) ;
if ( F_4 ( V_313 , & V_2 -> V_72 ) )
return - V_70 ;
if ( V_407 ) {
F_113 ( V_321 , & V_2 -> V_72 ) ;
if ( ! F_4 ( V_222 , & V_2 -> V_72 ) &&
! F_4 ( V_320 , & V_2 -> V_72 ) )
F_209 ( V_2 ) ;
} else {
F_133 ( V_321 , & V_2 -> V_72 ) ;
}
return 0 ;
}
static void F_225 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 , V_410 ) ;
int V_16 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
V_16 = F_195 ( V_2 ) ;
if ( V_16 < 0 ) {
F_227 ( V_2 , V_16 ) ;
return;
}
if ( F_4 ( V_321 , & V_2 -> V_72 ) ||
F_4 ( V_314 , & V_2 -> V_72 ) ||
( V_2 -> V_147 == V_148 &&
! F_156 ( & V_2 -> V_40 , V_209 ) &&
! F_156 ( & V_2 -> V_84 , V_209 ) ) ) {
F_133 ( V_344 , & V_2 -> V_72 ) ;
F_209 ( V_2 ) ;
} else if ( F_4 ( V_344 , & V_2 -> V_72 ) ) {
F_228 ( V_2 -> V_346 , & V_2 -> V_345 ,
V_411 ) ;
}
if ( F_202 ( V_222 , & V_2 -> V_72 ) ) {
if ( F_4 ( V_314 , & V_2 -> V_72 ) )
F_113 ( V_342 , & V_2 -> V_18 ) ;
F_229 ( V_2 ) ;
} else if ( F_202 ( V_320 , & V_2 -> V_72 ) ) {
if ( ! F_4 ( V_314 , & V_2 -> V_72 ) )
F_133 ( V_342 , & V_2 -> V_18 ) ;
F_229 ( V_2 ) ;
}
}
static void F_230 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 ,
V_345 . V_409 ) ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_209 ( V_2 ) ;
}
static void F_231 ( struct V_408 * V_409 )
{
struct V_1 * V_2 ;
V_2 = F_226 ( V_409 , struct V_1 , V_353 . V_409 ) ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_232 ( V_2 ) ;
}
void F_233 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_412 ;
F_173 (uuid, tmp, &hdev->uuids, list) {
F_174 ( & V_43 -> V_64 ) ;
F_175 ( V_43 ) ;
}
}
void F_234 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_36 (p, n, &hdev->link_keys) {
struct V_62 * V_63 ;
V_63 = F_37 ( V_31 , struct V_62 , V_64 ) ;
F_174 ( V_31 ) ;
F_175 ( V_63 ) ;
}
}
void F_235 ( struct V_1 * V_2 )
{
struct V_87 * V_413 , * V_412 ;
F_173 (k, tmp, &hdev->long_term_keys, list) {
F_174 ( & V_413 -> V_64 ) ;
F_175 ( V_413 ) ;
}
}
void F_236 ( struct V_1 * V_2 )
{
struct V_86 * V_413 , * V_412 ;
F_173 (k, tmp, &hdev->identity_resolving_keys, list) {
F_174 ( & V_413 -> V_64 ) ;
F_175 ( V_413 ) ;
}
}
struct V_62 * F_237 ( struct V_1 * V_2 , T_7 * V_40 )
{
struct V_62 * V_413 ;
F_26 (k, &hdev->link_keys, list)
if ( F_156 ( V_40 , & V_413 -> V_40 ) == 0 )
return V_413 ;
return NULL ;
}
static bool F_238 ( struct V_1 * V_2 , struct V_414 * V_349 ,
T_5 V_415 , T_5 V_416 )
{
if ( V_415 < 0x03 )
return true ;
if ( V_415 == V_417 )
return false ;
if ( V_415 == V_418 && V_416 == 0xff )
return false ;
if ( ! V_349 )
return true ;
if ( V_349 -> V_419 > 0x01 && V_349 -> V_420 > 0x01 )
return true ;
if ( V_349 -> V_419 == 0x02 || V_349 -> V_419 == 0x03 )
return true ;
if ( V_349 -> V_420 == 0x02 || V_349 -> V_420 == 0x03 )
return true ;
return false ;
}
static T_5 F_239 ( T_5 type )
{
if ( type == V_421 )
return V_422 ;
return V_423 ;
}
struct V_87 * F_240 ( struct V_1 * V_2 , T_11 V_91 , T_14 rand ,
T_5 V_424 )
{
struct V_87 * V_413 ;
F_26 (k, &hdev->long_term_keys, list) {
if ( V_413 -> V_91 != V_91 || V_413 -> rand != rand )
continue;
if ( F_239 ( V_413 -> type ) != V_424 )
continue;
return V_413 ;
}
return NULL ;
}
struct V_87 * F_241 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_80 , T_5 V_424 )
{
struct V_87 * V_413 ;
F_26 (k, &hdev->long_term_keys, list)
if ( V_80 == V_413 -> V_41 &&
F_156 ( V_40 , & V_413 -> V_40 ) == 0 &&
F_239 ( V_413 -> type ) == V_424 )
return V_413 ;
return NULL ;
}
struct V_86 * F_242 ( struct V_1 * V_2 , T_7 * V_82 )
{
struct V_86 * V_81 ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_156 ( & V_81 -> V_82 , V_82 ) )
return V_81 ;
}
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( F_243 ( V_2 , V_81 -> V_45 , V_82 ) ) {
F_148 ( & V_81 -> V_82 , V_82 ) ;
return V_81 ;
}
}
return NULL ;
}
struct V_86 * F_244 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_80 )
{
struct V_86 * V_81 ;
if ( V_80 == V_425 && ( V_40 -> V_39 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( V_80 == V_81 -> V_80 &&
F_156 ( V_40 , & V_81 -> V_40 ) == 0 )
return V_81 ;
}
return NULL ;
}
struct V_62 * F_245 ( struct V_1 * V_2 , struct V_414 * V_349 ,
T_7 * V_40 , T_5 * V_45 , T_5 type ,
T_5 V_66 , bool * V_426 )
{
struct V_62 * V_63 , * V_427 ;
T_5 V_416 ;
V_427 = F_237 ( V_2 , V_40 ) ;
if ( V_427 ) {
V_416 = V_427 -> type ;
V_63 = V_427 ;
} else {
V_416 = V_349 ? V_349 -> V_415 : 0xff ;
V_63 = F_184 ( sizeof( * V_63 ) , V_289 ) ;
if ( ! V_63 )
return NULL ;
F_181 ( & V_63 -> V_64 , & V_2 -> V_428 ) ;
}
F_92 ( L_73 , V_2 -> V_102 , V_40 , type ) ;
if ( type == V_418 &&
( ! V_349 || V_349 -> V_420 == 0xff ) && V_416 == 0xff ) {
type = V_429 ;
if ( V_349 )
V_349 -> V_415 = type ;
}
F_148 ( & V_63 -> V_40 , V_40 ) ;
memcpy ( V_63 -> V_45 , V_45 , V_65 ) ;
V_63 -> V_66 = V_66 ;
if ( type == V_418 )
V_63 -> type = V_416 ;
else
V_63 -> type = type ;
if ( V_426 )
* V_426 = F_238 ( V_2 , V_349 , type ,
V_416 ) ;
return V_63 ;
}
struct V_87 * F_246 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_80 , T_5 type , T_5 V_89 ,
T_5 V_430 [ 16 ] , T_5 V_90 , T_11 V_91 , T_14 rand )
{
struct V_87 * V_63 , * V_427 ;
T_5 V_424 = F_239 ( type ) ;
V_427 = F_241 ( V_2 , V_40 , V_80 , V_424 ) ;
if ( V_427 )
V_63 = V_427 ;
else {
V_63 = F_184 ( sizeof( * V_63 ) , V_289 ) ;
if ( ! V_63 )
return NULL ;
F_181 ( & V_63 -> V_64 , & V_2 -> V_431 ) ;
}
F_148 ( & V_63 -> V_40 , V_40 ) ;
V_63 -> V_41 = V_80 ;
memcpy ( V_63 -> V_45 , V_430 , sizeof( V_63 -> V_45 ) ) ;
V_63 -> V_89 = V_89 ;
V_63 -> V_91 = V_91 ;
V_63 -> rand = rand ;
V_63 -> V_90 = V_90 ;
V_63 -> type = type ;
return V_63 ;
}
struct V_86 * F_247 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_80 , T_5 V_45 [ 16 ] , T_7 * V_82 )
{
struct V_86 * V_81 ;
V_81 = F_244 ( V_2 , V_40 , V_80 ) ;
if ( ! V_81 ) {
V_81 = F_184 ( sizeof( * V_81 ) , V_289 ) ;
if ( ! V_81 )
return NULL ;
F_148 ( & V_81 -> V_40 , V_40 ) ;
V_81 -> V_80 = V_80 ;
F_181 ( & V_81 -> V_64 , & V_2 -> V_432 ) ;
}
memcpy ( V_81 -> V_45 , V_45 , 16 ) ;
F_148 ( & V_81 -> V_82 , V_82 ) ;
return V_81 ;
}
int F_248 ( struct V_1 * V_2 , T_7 * V_40 )
{
struct V_62 * V_63 ;
V_63 = F_237 ( V_2 , V_40 ) ;
if ( ! V_63 )
return - V_433 ;
F_92 ( L_74 , V_2 -> V_102 , V_40 ) ;
F_174 ( & V_63 -> V_64 ) ;
F_175 ( V_63 ) ;
return 0 ;
}
int F_249 ( struct V_1 * V_2 , T_7 * V_40 , T_5 V_41 )
{
struct V_87 * V_413 , * V_412 ;
int V_434 = 0 ;
F_173 (k, tmp, &hdev->long_term_keys, list) {
if ( F_156 ( V_40 , & V_413 -> V_40 ) || V_413 -> V_41 != V_41 )
continue;
F_92 ( L_74 , V_2 -> V_102 , V_40 ) ;
F_174 ( & V_413 -> V_64 ) ;
F_175 ( V_413 ) ;
V_434 ++ ;
}
return V_434 ? 0 : - V_433 ;
}
void F_250 ( struct V_1 * V_2 , T_7 * V_40 , T_5 V_80 )
{
struct V_86 * V_413 , * V_412 ;
F_173 (k, tmp, &hdev->identity_resolving_keys, list) {
if ( F_156 ( V_40 , & V_413 -> V_40 ) || V_413 -> V_80 != V_80 )
continue;
F_92 ( L_74 , V_2 -> V_102 , V_40 ) ;
F_174 ( & V_413 -> V_64 ) ;
F_175 ( V_413 ) ;
}
}
static void F_251 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 ,
V_351 . V_409 ) ;
if ( V_2 -> V_340 ) {
struct V_435 * V_436 = ( void * ) V_2 -> V_340 -> V_26 ;
T_8 V_109 = F_33 ( V_436 -> V_109 ) ;
F_97 ( L_75 , V_2 -> V_102 , V_109 ) ;
} else {
F_97 ( L_76 , V_2 -> V_102 ) ;
}
F_196 ( & V_2 -> V_326 , 1 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_335 ) ;
}
struct V_438 * F_253 ( struct V_1 * V_2 ,
T_7 * V_40 )
{
struct V_438 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list)
if ( F_156 ( V_40 , & V_26 -> V_40 ) == 0 )
return V_26 ;
return NULL ;
}
int F_183 ( struct V_1 * V_2 , T_7 * V_40 )
{
struct V_438 * V_26 ;
V_26 = F_253 ( V_2 , V_40 ) ;
if ( ! V_26 )
return - V_433 ;
F_92 ( L_74 , V_2 -> V_102 , V_40 ) ;
F_174 ( & V_26 -> V_64 ) ;
F_175 ( V_26 ) ;
return 0 ;
}
void F_254 ( struct V_1 * V_2 )
{
struct V_438 * V_26 , * V_61 ;
F_173 (data, n, &hdev->remote_oob_data, list) {
F_174 ( & V_26 -> V_64 ) ;
F_175 ( V_26 ) ;
}
}
int F_255 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 * V_439 , T_5 * V_440 )
{
struct V_438 * V_26 ;
V_26 = F_253 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_192 ( sizeof( * V_26 ) , V_289 ) ;
if ( ! V_26 )
return - V_318 ;
F_148 ( & V_26 -> V_40 , V_40 ) ;
F_181 ( & V_26 -> V_64 , & V_2 -> V_441 ) ;
}
memcpy ( V_26 -> V_442 , V_439 , sizeof( V_26 -> V_442 ) ) ;
memcpy ( V_26 -> V_443 , V_440 , sizeof( V_26 -> V_443 ) ) ;
memset ( V_26 -> V_444 , 0 , sizeof( V_26 -> V_444 ) ) ;
memset ( V_26 -> V_445 , 0 , sizeof( V_26 -> V_445 ) ) ;
F_92 ( L_77 , V_2 -> V_102 , V_40 ) ;
return 0 ;
}
int F_256 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 * V_442 , T_5 * V_443 ,
T_5 * V_444 , T_5 * V_445 )
{
struct V_438 * V_26 ;
V_26 = F_253 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_192 ( sizeof( * V_26 ) , V_289 ) ;
if ( ! V_26 )
return - V_318 ;
F_148 ( & V_26 -> V_40 , V_40 ) ;
F_181 ( & V_26 -> V_64 , & V_2 -> V_441 ) ;
}
memcpy ( V_26 -> V_442 , V_442 , sizeof( V_26 -> V_442 ) ) ;
memcpy ( V_26 -> V_443 , V_443 , sizeof( V_26 -> V_443 ) ) ;
memcpy ( V_26 -> V_444 , V_444 , sizeof( V_26 -> V_444 ) ) ;
memcpy ( V_26 -> V_445 , V_445 , sizeof( V_26 -> V_445 ) ) ;
F_92 ( L_77 , V_2 -> V_102 , V_40 ) ;
return 0 ;
}
struct V_38 * F_257 ( struct V_60 * V_38 ,
T_7 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, bdaddr_list, list) {
if ( ! F_156 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
void F_258 ( struct V_60 * V_38 )
{
struct V_60 * V_31 , * V_61 ;
F_36 (p, n, bdaddr_list) {
struct V_38 * V_39 = F_37 ( V_31 , struct V_38 , V_64 ) ;
F_174 ( V_31 ) ;
F_175 ( V_39 ) ;
}
}
int F_259 ( struct V_60 * V_64 , T_7 * V_40 , T_5 type )
{
struct V_38 * V_446 ;
if ( ! F_156 ( V_40 , V_209 ) )
return - V_447 ;
if ( F_257 ( V_64 , V_40 , type ) )
return - V_448 ;
V_446 = F_184 ( sizeof( * V_446 ) , V_289 ) ;
if ( ! V_446 )
return - V_318 ;
F_148 ( & V_446 -> V_40 , V_40 ) ;
V_446 -> V_41 = type ;
F_181 ( & V_446 -> V_64 , V_64 ) ;
return 0 ;
}
int F_260 ( struct V_60 * V_64 , T_7 * V_40 , T_5 type )
{
struct V_38 * V_446 ;
if ( ! F_156 ( V_40 , V_209 ) ) {
F_258 ( V_64 ) ;
return 0 ;
}
V_446 = F_257 ( V_64 , V_40 , type ) ;
if ( ! V_446 )
return - V_433 ;
F_174 ( & V_446 -> V_64 ) ;
F_175 ( V_446 ) ;
return 0 ;
}
struct V_99 * F_261 ( struct V_1 * V_2 ,
T_7 * V_79 , T_5 V_80 )
{
struct V_99 * V_449 ;
if ( ! F_262 ( V_79 , V_80 ) )
return NULL ;
F_26 (params, &hdev->le_conn_params, list) {
if ( F_156 ( & V_449 -> V_79 , V_79 ) == 0 &&
V_449 -> V_80 == V_80 ) {
return V_449 ;
}
}
return NULL ;
}
static bool F_263 ( struct V_1 * V_2 , T_7 * V_79 , T_5 type )
{
struct V_414 * V_349 ;
V_349 = F_264 ( V_2 , V_450 , V_79 ) ;
if ( ! V_349 )
return false ;
if ( V_349 -> V_451 != type )
return false ;
if ( V_349 -> V_271 != V_452 )
return false ;
return true ;
}
struct V_99 * F_265 ( struct V_60 * V_64 ,
T_7 * V_79 , T_5 V_80 )
{
struct V_99 * V_122 ;
if ( ! F_262 ( V_79 , V_80 ) )
return NULL ;
F_26 (param, list, action) {
if ( F_156 ( & V_122 -> V_79 , V_79 ) == 0 &&
V_122 -> V_80 == V_80 )
return V_122 ;
}
return NULL ;
}
struct V_99 * F_266 ( struct V_1 * V_2 ,
T_7 * V_79 , T_5 V_80 )
{
struct V_99 * V_449 ;
if ( ! F_262 ( V_79 , V_80 ) )
return NULL ;
V_449 = F_261 ( V_2 , V_79 , V_80 ) ;
if ( V_449 )
return V_449 ;
V_449 = F_184 ( sizeof( * V_449 ) , V_289 ) ;
if ( ! V_449 ) {
F_97 ( L_78 ) ;
return NULL ;
}
F_148 ( & V_449 -> V_79 , V_79 ) ;
V_449 -> V_80 = V_80 ;
F_181 ( & V_449 -> V_64 , & V_2 -> V_453 ) ;
F_176 ( & V_449 -> V_350 ) ;
V_449 -> V_454 = V_2 -> V_93 ;
V_449 -> V_455 = V_2 -> V_92 ;
V_449 -> V_456 = V_2 -> V_94 ;
V_449 -> V_457 = V_2 -> V_95 ;
V_449 -> V_100 = V_458 ;
F_92 ( L_79 , V_79 , V_80 ) ;
return V_449 ;
}
int F_267 ( struct V_1 * V_2 , T_7 * V_79 , T_5 V_80 ,
T_5 V_100 )
{
struct V_99 * V_449 ;
V_449 = F_266 ( V_2 , V_79 , V_80 ) ;
if ( ! V_449 )
return - V_325 ;
if ( V_449 -> V_100 == V_100 )
return 0 ;
F_208 ( & V_449 -> V_350 ) ;
switch ( V_100 ) {
case V_458 :
case V_459 :
F_170 ( V_2 ) ;
break;
case V_460 :
F_181 ( & V_449 -> V_350 , & V_2 -> V_461 ) ;
F_170 ( V_2 ) ;
break;
case V_462 :
case V_463 :
if ( ! F_263 ( V_2 , V_79 , V_80 ) ) {
F_181 ( & V_449 -> V_350 , & V_2 -> V_464 ) ;
F_170 ( V_2 ) ;
}
break;
}
V_449 -> V_100 = V_100 ;
F_92 ( L_80 , V_79 , V_80 ,
V_100 ) ;
return 0 ;
}
static void F_268 ( struct V_99 * V_449 )
{
if ( V_449 -> V_349 ) {
F_206 ( V_449 -> V_349 ) ;
F_207 ( V_449 -> V_349 ) ;
}
F_174 ( & V_449 -> V_350 ) ;
F_174 ( & V_449 -> V_64 ) ;
F_175 ( V_449 ) ;
}
void F_269 ( struct V_1 * V_2 , T_7 * V_79 , T_5 V_80 )
{
struct V_99 * V_449 ;
V_449 = F_261 ( V_2 , V_79 , V_80 ) ;
if ( ! V_449 )
return;
F_268 ( V_449 ) ;
F_170 ( V_2 ) ;
F_92 ( L_79 , V_79 , V_80 ) ;
}
void F_270 ( struct V_1 * V_2 )
{
struct V_99 * V_449 , * V_412 ;
F_173 (params, tmp, &hdev->le_conn_params, list) {
if ( V_449 -> V_100 != V_458 )
continue;
F_174 ( & V_449 -> V_64 ) ;
F_175 ( V_449 ) ;
}
F_92 ( L_81 ) ;
}
void F_271 ( struct V_1 * V_2 )
{
struct V_99 * V_449 , * V_412 ;
F_173 (params, tmp, &hdev->le_conn_params, list)
F_268 ( V_449 ) ;
F_170 ( V_2 ) ;
F_92 ( L_82 ) ;
}
static void F_272 ( struct V_1 * V_2 , T_5 V_465 )
{
if ( V_465 ) {
F_97 ( L_83 , V_465 ) ;
F_19 ( V_2 ) ;
F_169 ( V_2 , V_275 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_273 ( struct V_1 * V_2 , T_5 V_465 )
{
T_5 V_303 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_126 V_127 ;
struct V_301 V_183 ;
int V_16 ;
if ( V_465 ) {
F_97 ( L_84 , V_465 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_466 :
F_19 ( V_2 ) ;
F_169 ( V_2 , V_275 ) ;
F_22 ( V_2 ) ;
break;
case V_467 :
F_101 ( & V_127 , V_2 ) ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
memcpy ( & V_183 . V_303 , V_303 , sizeof( V_183 . V_303 ) ) ;
V_183 . V_304 = V_468 ;
F_114 ( & V_127 , V_306 , sizeof( V_183 ) , & V_183 ) ;
F_19 ( V_2 ) ;
F_172 ( V_2 ) ;
V_16 = F_103 ( & V_127 , F_272 ) ;
if ( V_16 ) {
F_97 ( L_85 , V_16 ) ;
F_169 ( V_2 , V_275 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_274 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 ,
V_358 . V_409 ) ;
struct V_126 V_127 ;
int V_16 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_101 ( & V_127 , V_2 ) ;
F_275 ( & V_127 ) ;
V_16 = F_103 ( & V_127 , F_273 ) ;
if ( V_16 )
F_97 ( L_86 , V_16 ) ;
}
static void F_276 ( struct V_126 * V_127 , T_7 * V_82 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
if ( F_4 ( V_469 , & V_2 -> V_72 ) ||
F_277 ( V_2 , V_450 , V_470 ) ) {
F_92 ( L_87 ) ;
F_113 ( V_332 , & V_2 -> V_72 ) ;
return;
}
F_114 ( V_127 , V_471 , 6 , V_82 ) ;
}
int F_278 ( struct V_126 * V_127 , bool V_472 ,
T_5 * V_473 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
int V_16 ;
if ( F_4 ( V_474 , & V_2 -> V_72 ) ) {
int V_475 ;
* V_473 = V_425 ;
if ( ! F_202 ( V_332 , & V_2 -> V_72 ) &&
! F_156 ( & V_2 -> V_83 , & V_2 -> V_82 ) )
return 0 ;
V_16 = F_279 ( V_2 , V_2 -> V_81 , & V_2 -> V_82 ) ;
if ( V_16 < 0 ) {
F_97 ( L_88 , V_2 -> V_102 ) ;
return V_16 ;
}
F_276 ( V_127 , & V_2 -> V_82 ) ;
V_475 = F_190 ( V_2 -> V_74 * 1000 ) ;
F_228 ( V_2 -> V_437 , & V_2 -> V_359 , V_475 ) ;
return 0 ;
}
if ( V_472 ) {
T_7 V_476 ;
F_280 ( & V_476 , 6 ) ;
V_476 . V_39 [ 5 ] &= 0x3f ;
* V_473 = V_425 ;
F_276 ( V_127 , & V_476 ) ;
return 0 ;
}
if ( F_4 ( V_85 , & V_2 -> V_11 ) ||
! F_156 ( & V_2 -> V_40 , V_209 ) ) {
* V_473 = V_425 ;
if ( F_156 ( & V_2 -> V_84 , & V_2 -> V_83 ) )
F_114 ( V_127 , V_471 , 6 ,
& V_2 -> V_84 ) ;
return 0 ;
}
* V_473 = V_477 ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 * V_41 )
{
if ( F_4 ( V_85 , & V_2 -> V_11 ) ||
! F_156 ( & V_2 -> V_40 , V_209 ) ) {
F_148 ( V_40 , & V_2 -> V_84 ) ;
* V_41 = V_425 ;
} else {
F_148 ( V_40 , & V_2 -> V_40 ) ;
* V_41 = V_477 ;
}
}
struct V_1 * F_281 ( void )
{
struct V_1 * V_2 ;
V_2 = F_184 ( sizeof( * V_2 ) , V_289 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_389 = ( V_478 | V_479 | V_480 ) ;
V_2 -> V_481 = ( V_482 ) ;
V_2 -> V_385 = ( V_387 ) ;
V_2 -> V_483 = 0x01 ;
V_2 -> V_484 = 0x03 ;
V_2 -> V_160 = 0xffff ;
V_2 -> V_485 = V_486 ;
V_2 -> V_487 = V_486 ;
V_2 -> V_75 = 800 ;
V_2 -> V_76 = 80 ;
V_2 -> V_96 = 0x07 ;
V_2 -> V_98 = 0x0800 ;
V_2 -> V_97 = 0x0800 ;
V_2 -> V_488 = 0x0060 ;
V_2 -> V_489 = 0x0030 ;
V_2 -> V_93 = 0x0028 ;
V_2 -> V_92 = 0x0038 ;
V_2 -> V_94 = 0x0000 ;
V_2 -> V_95 = 0x002a ;
V_2 -> V_74 = V_490 ;
V_2 -> V_258 = V_491 ;
V_2 -> V_78 = V_492 ;
V_2 -> V_77 = V_493 ;
F_282 ( & V_2 -> V_494 ) ;
F_282 ( & V_2 -> V_495 ) ;
F_176 ( & V_2 -> V_496 ) ;
F_176 ( & V_2 -> V_497 ) ;
F_176 ( & V_2 -> V_498 ) ;
F_176 ( & V_2 -> V_499 ) ;
F_176 ( & V_2 -> V_428 ) ;
F_176 ( & V_2 -> V_431 ) ;
F_176 ( & V_2 -> V_432 ) ;
F_176 ( & V_2 -> V_441 ) ;
F_176 ( & V_2 -> V_500 ) ;
F_176 ( & V_2 -> V_453 ) ;
F_176 ( & V_2 -> V_464 ) ;
F_176 ( & V_2 -> V_461 ) ;
F_176 ( & V_2 -> V_501 . V_64 ) ;
F_283 ( & V_2 -> V_336 , V_502 ) ;
F_283 ( & V_2 -> V_335 , V_503 ) ;
F_283 ( & V_2 -> V_334 , V_504 ) ;
F_283 ( & V_2 -> V_410 , F_225 ) ;
F_284 ( & V_2 -> V_345 , F_230 ) ;
F_284 ( & V_2 -> V_353 , F_231 ) ;
F_284 ( & V_2 -> V_358 , F_274 ) ;
F_285 ( & V_2 -> V_338 ) ;
F_285 ( & V_2 -> V_337 ) ;
F_285 ( & V_2 -> V_361 ) ;
F_286 ( & V_2 -> V_107 ) ;
F_284 ( & V_2 -> V_351 , F_251 ) ;
F_287 ( V_2 ) ;
F_288 ( V_2 ) ;
return V_2 ;
}
void F_289 ( struct V_1 * V_2 )
{
F_290 ( & V_2 -> V_343 ) ;
}
int F_291 ( struct V_1 * V_2 )
{
int V_269 , error ;
if ( ! V_2 -> V_324 || ! V_2 -> V_341 || ! V_2 -> V_505 )
return - V_21 ;
switch ( V_2 -> V_147 ) {
case V_148 :
V_269 = F_292 ( & V_506 , 0 , 0 , V_289 ) ;
break;
case V_149 :
V_269 = F_292 ( & V_506 , 1 , 0 , V_289 ) ;
break;
default:
return - V_21 ;
}
if ( V_269 < 0 )
return V_269 ;
sprintf ( V_2 -> V_102 , L_89 , V_269 ) ;
V_2 -> V_269 = V_269 ;
F_92 ( L_90 , V_2 , V_2 -> V_102 , V_2 -> V_404 ) ;
V_2 -> V_437 = F_293 ( L_19 , V_507 | V_508 |
V_509 , 1 , V_2 -> V_102 ) ;
if ( ! V_2 -> V_437 ) {
error = - V_318 ;
goto V_16;
}
V_2 -> V_346 = F_293 ( L_19 , V_507 | V_508 |
V_509 , 1 , V_2 -> V_102 ) ;
if ( ! V_2 -> V_346 ) {
F_294 ( V_2 -> V_437 ) ;
error = - V_318 ;
goto V_16;
}
if ( ! F_295 ( V_510 ) )
V_2 -> V_223 = F_296 ( V_2 -> V_102 , V_510 ) ;
F_297 ( & V_2 -> V_343 , L_19 , V_2 -> V_102 ) ;
error = F_298 ( & V_2 -> V_343 ) ;
if ( error < 0 )
goto V_511;
V_2 -> V_512 = F_299 ( V_2 -> V_102 , & V_2 -> V_343 ,
V_513 , & V_514 ,
V_2 ) ;
if ( V_2 -> V_512 ) {
if ( F_300 ( V_2 -> V_512 ) < 0 ) {
F_301 ( V_2 -> V_512 ) ;
V_2 -> V_512 = NULL ;
}
}
if ( V_2 -> V_512 && F_302 ( V_2 -> V_512 ) )
F_113 ( V_321 , & V_2 -> V_72 ) ;
F_113 ( V_222 , & V_2 -> V_72 ) ;
F_113 ( V_344 , & V_2 -> V_72 ) ;
if ( V_2 -> V_147 == V_148 ) {
F_113 ( V_179 , & V_2 -> V_72 ) ;
}
F_303 ( & V_268 ) ;
F_181 ( & V_2 -> V_64 , & V_515 ) ;
F_304 ( & V_268 ) ;
if ( F_4 ( V_260 , & V_2 -> V_146 ) )
F_113 ( V_314 , & V_2 -> V_72 ) ;
F_1 ( V_2 , V_516 ) ;
F_166 ( V_2 ) ;
F_252 ( V_2 -> V_346 , & V_2 -> V_410 ) ;
return V_269 ;
V_511:
F_294 ( V_2 -> V_437 ) ;
F_294 ( V_2 -> V_346 ) ;
V_16:
F_305 ( & V_506 , V_2 -> V_269 ) ;
return error ;
}
void F_306 ( struct V_1 * V_2 )
{
int V_44 , V_269 ;
F_92 ( L_90 , V_2 , V_2 -> V_102 , V_2 -> V_404 ) ;
F_113 ( V_319 , & V_2 -> V_72 ) ;
V_269 = V_2 -> V_269 ;
F_303 ( & V_268 ) ;
F_174 ( & V_2 -> V_64 ) ;
F_304 ( & V_268 ) ;
F_209 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_517 ; V_44 ++ )
F_16 ( V_2 -> V_518 [ V_44 ] ) ;
F_307 ( & V_2 -> V_410 ) ;
if ( ! F_4 ( V_327 , & V_2 -> V_18 ) &&
! F_4 ( V_222 , & V_2 -> V_72 ) &&
! F_4 ( V_320 , & V_2 -> V_72 ) ) {
F_19 ( V_2 ) ;
F_308 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_309 ( ! F_310 ( & V_2 -> V_496 ) ) ;
F_1 ( V_2 , V_519 ) ;
if ( V_2 -> V_512 ) {
F_311 ( V_2 -> V_512 ) ;
F_301 ( V_2 -> V_512 ) ;
}
F_312 ( V_2 ) ;
F_313 ( & V_2 -> V_343 ) ;
F_314 ( V_2 -> V_223 ) ;
F_294 ( V_2 -> V_437 ) ;
F_294 ( V_2 -> V_346 ) ;
F_19 ( V_2 ) ;
F_258 ( & V_2 -> V_497 ) ;
F_258 ( & V_2 -> V_498 ) ;
F_233 ( V_2 ) ;
F_234 ( V_2 ) ;
F_235 ( V_2 ) ;
F_236 ( V_2 ) ;
F_254 ( V_2 ) ;
F_258 ( & V_2 -> V_500 ) ;
F_271 ( V_2 ) ;
F_22 ( V_2 ) ;
F_194 ( V_2 ) ;
F_305 ( & V_506 , V_269 ) ;
}
int F_315 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_520 ) ;
return 0 ;
}
int F_316 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_521 ) ;
return 0 ;
}
int F_317 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_327 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_522 ;
}
F_318 ( V_13 ) -> V_523 = 1 ;
F_319 ( V_13 ) ;
F_320 ( & V_2 -> V_338 , V_13 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_336 ) ;
return 0 ;
}
static int F_321 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_12 V_266 )
{
int V_116 = 0 ;
int V_524 = 0 ;
int V_525 = V_6 ;
struct V_12 * V_13 ;
struct V_526 * V_527 ;
if ( ( type < V_528 || type > V_529 ) ||
V_266 >= V_517 )
return - V_530 ;
V_13 = V_2 -> V_518 [ V_266 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_528 :
V_116 = V_531 ;
V_524 = V_532 ;
break;
case V_529 :
V_116 = V_533 ;
V_524 = V_118 ;
break;
case V_534 :
V_116 = V_535 ;
V_524 = V_536 ;
break;
}
V_13 = F_322 ( V_116 , V_537 ) ;
if ( ! V_13 )
return - V_318 ;
V_527 = ( void * ) V_13 -> V_538 ;
V_527 -> V_539 = V_524 ;
V_527 -> V_389 = type ;
V_2 -> V_518 [ V_266 ] = V_13 ;
}
while ( V_6 ) {
V_527 = ( void * ) V_13 -> V_538 ;
V_116 = F_323 ( V_540 , V_527 -> V_539 , V_6 ) ;
memcpy ( F_324 ( V_13 , V_116 ) , V_26 , V_116 ) ;
V_6 -= V_116 ;
V_26 += V_116 ;
V_527 -> V_539 -= V_116 ;
V_525 = V_6 ;
switch ( type ) {
case V_529 :
if ( V_13 -> V_116 == V_118 ) {
struct V_112 * V_541 = V_112 ( V_13 ) ;
V_527 -> V_539 = V_541 -> V_121 ;
if ( F_325 ( V_13 ) < V_527 -> V_539 ) {
F_16 ( V_13 ) ;
V_2 -> V_518 [ V_266 ] = NULL ;
return - V_318 ;
}
}
break;
case V_528 :
if ( V_13 -> V_116 == V_532 ) {
struct V_542 * V_541 = V_542 ( V_13 ) ;
V_527 -> V_539 = F_33 ( V_541 -> V_543 ) ;
if ( F_325 ( V_13 ) < V_527 -> V_539 ) {
F_16 ( V_13 ) ;
V_2 -> V_518 [ V_266 ] = NULL ;
return - V_318 ;
}
}
break;
case V_534 :
if ( V_13 -> V_116 == V_536 ) {
struct V_544 * V_541 = V_544 ( V_13 ) ;
V_527 -> V_539 = V_541 -> V_543 ;
if ( F_325 ( V_13 ) < V_527 -> V_539 ) {
F_16 ( V_13 ) ;
V_2 -> V_518 [ V_266 ] = NULL ;
return - V_318 ;
}
}
break;
}
if ( V_527 -> V_539 == 0 ) {
F_318 ( V_13 ) -> V_389 = type ;
F_317 ( V_2 , V_13 ) ;
V_2 -> V_518 [ V_266 ] = NULL ;
return V_525 ;
}
}
return V_525 ;
}
int F_326 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_545 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_518 [ V_546 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_547 ;
V_547 = V_26 ;
type = V_547 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_318 ( V_13 ) -> V_389 ;
V_545 = F_321 ( V_2 , type , V_26 , V_6 ,
V_546 ) ;
if ( V_545 < 0 )
return V_545 ;
V_26 += ( V_6 - V_545 ) ;
V_6 = V_545 ;
}
return V_545 ;
}
int F_327 ( struct V_548 * V_538 )
{
F_92 ( L_91 , V_538 , V_538 -> V_102 ) ;
F_303 ( & V_549 ) ;
F_181 ( & V_538 -> V_64 , & V_550 ) ;
F_304 ( & V_549 ) ;
return 0 ;
}
int F_328 ( struct V_548 * V_538 )
{
F_92 ( L_91 , V_538 , V_538 -> V_102 ) ;
F_303 ( & V_549 ) ;
F_174 ( & V_538 -> V_64 ) ;
F_304 ( & V_549 ) ;
return 0 ;
}
static void F_329 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_16 ;
F_92 ( L_92 , V_2 -> V_102 , F_318 ( V_13 ) -> V_389 , V_13 -> V_116 ) ;
F_319 ( V_13 ) ;
F_330 ( V_2 , V_13 ) ;
if ( F_331 ( & V_2 -> V_551 ) ) {
F_332 ( V_2 , V_13 ) ;
}
F_333 ( V_13 ) ;
V_16 = V_2 -> V_505 ( V_2 , V_13 ) ;
if ( V_16 < 0 ) {
F_97 ( L_93 , V_2 -> V_102 , V_16 ) ;
F_16 ( V_13 ) ;
}
}
void F_101 ( struct V_126 * V_127 , struct V_1 * V_2 )
{
F_285 ( & V_127 -> V_337 ) ;
V_127 -> V_2 = V_2 ;
V_127 -> V_16 = 0 ;
}
int F_103 ( struct V_126 * V_127 , T_15 V_552 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_92 ( L_94 , F_334 ( & V_127 -> V_337 ) ) ;
if ( V_127 -> V_16 ) {
F_199 ( & V_127 -> V_337 ) ;
return V_127 -> V_16 ;
}
if ( F_335 ( & V_127 -> V_337 ) )
return - V_115 ;
V_13 = F_336 ( & V_127 -> V_337 ) ;
F_318 ( V_13 ) -> V_127 . V_552 = V_552 ;
F_337 ( & V_2 -> V_337 . V_494 , V_18 ) ;
F_338 ( & V_127 -> V_337 , & V_2 -> V_337 ) ;
F_339 ( & V_2 -> V_337 . V_494 , V_18 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_335 ) ;
return 0 ;
}
bool F_340 ( struct V_1 * V_2 )
{
return ( V_2 -> V_103 == V_104 ) ;
}
static struct V_12 * F_341 ( struct V_1 * V_2 , T_8 V_109 ,
T_9 V_121 , const void * V_122 )
{
int V_116 = V_553 + V_121 ;
struct V_435 * V_113 ;
struct V_12 * V_13 ;
V_13 = F_322 ( V_116 , V_537 ) ;
if ( ! V_13 )
return NULL ;
V_113 = (struct V_435 * ) F_324 ( V_13 , V_553 ) ;
V_113 -> V_109 = F_119 ( V_109 ) ;
V_113 -> V_121 = V_121 ;
if ( V_121 )
memcpy ( F_324 ( V_13 , V_121 ) , V_122 , V_121 ) ;
F_92 ( L_95 , V_13 -> V_116 ) ;
F_318 ( V_13 ) -> V_389 = V_554 ;
F_318 ( V_13 ) -> V_109 = V_109 ;
return V_13 ;
}
int F_342 ( struct V_1 * V_2 , T_13 V_109 , T_10 V_121 ,
const void * V_122 )
{
struct V_12 * V_13 ;
F_92 ( L_96 , V_2 -> V_102 , V_109 , V_121 ) ;
V_13 = F_341 ( V_2 , V_109 , V_121 , V_122 ) ;
if ( ! V_13 ) {
F_97 ( L_97 , V_2 -> V_102 ) ;
return - V_318 ;
}
F_318 ( V_13 ) -> V_127 . V_555 = true ;
F_320 ( & V_2 -> V_337 , V_13 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_335 ) ;
return 0 ;
}
void F_102 ( struct V_126 * V_127 , T_8 V_109 , T_9 V_121 ,
const void * V_122 , T_5 V_3 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_12 * V_13 ;
F_92 ( L_96 , V_2 -> V_102 , V_109 , V_121 ) ;
if ( V_127 -> V_16 )
return;
V_13 = F_341 ( V_2 , V_109 , V_121 , V_122 ) ;
if ( ! V_13 ) {
F_97 ( L_98 ,
V_2 -> V_102 , V_109 ) ;
V_127 -> V_16 = - V_318 ;
return;
}
if ( F_335 ( & V_127 -> V_337 ) )
F_318 ( V_13 ) -> V_127 . V_555 = true ;
F_318 ( V_13 ) -> V_127 . V_3 = V_3 ;
F_320 ( & V_127 -> V_337 , V_13 ) ;
}
void F_114 ( struct V_126 * V_127 , T_8 V_109 , T_9 V_121 ,
const void * V_122 )
{
F_102 ( V_127 , V_109 , V_121 , V_122 , 0 ) ;
}
void * F_343 ( struct V_1 * V_2 , T_13 V_109 )
{
struct V_435 * V_113 ;
if ( ! V_2 -> V_340 )
return NULL ;
V_113 = ( void * ) V_2 -> V_340 -> V_26 ;
if ( V_113 -> V_109 != F_119 ( V_109 ) )
return NULL ;
F_92 ( L_99 , V_2 -> V_102 , V_109 ) ;
return V_2 -> V_340 -> V_26 + V_553 ;
}
static void F_344 ( struct V_12 * V_13 , T_13 V_556 , T_13 V_18 )
{
struct V_542 * V_113 ;
int V_116 = V_13 -> V_116 ;
F_345 ( V_13 , V_532 ) ;
F_346 ( V_13 ) ;
V_113 = (struct V_542 * ) F_347 ( V_13 ) ;
V_113 -> V_556 = F_119 ( F_348 ( V_556 , V_18 ) ) ;
V_113 -> V_543 = F_119 ( V_116 ) ;
}
static void F_349 ( struct V_557 * V_558 , struct V_559 * V_560 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_414 * V_349 = V_558 -> V_349 ;
struct V_1 * V_2 = V_349 -> V_2 ;
struct V_12 * V_64 ;
V_13 -> V_116 = F_350 ( V_13 ) ;
V_13 -> V_561 = 0 ;
F_318 ( V_13 ) -> V_389 = V_528 ;
switch ( V_2 -> V_147 ) {
case V_148 :
F_344 ( V_13 , V_349 -> V_556 , V_18 ) ;
break;
case V_149 :
F_344 ( V_13 , V_558 -> V_556 , V_18 ) ;
break;
default:
F_97 ( L_100 , V_2 -> V_102 , V_2 -> V_147 ) ;
return;
}
V_64 = F_351 ( V_13 ) -> V_562 ;
if ( ! V_64 ) {
F_92 ( L_101 , V_2 -> V_102 , V_13 , V_13 -> V_116 ) ;
F_320 ( V_560 , V_13 ) ;
} else {
F_92 ( L_102 , V_2 -> V_102 , V_13 , V_13 -> V_116 ) ;
F_351 ( V_13 ) -> V_562 = NULL ;
F_352 ( & V_560 -> V_494 ) ;
F_353 ( V_560 , V_13 ) ;
V_18 &= ~ V_563 ;
V_18 |= V_564 ;
do {
V_13 = V_64 ; V_64 = V_64 -> V_565 ;
F_318 ( V_13 ) -> V_389 = V_528 ;
F_344 ( V_13 , V_349 -> V_556 , V_18 ) ;
F_92 ( L_102 , V_2 -> V_102 , V_13 , V_13 -> V_116 ) ;
F_353 ( V_560 , V_13 ) ;
} while ( V_64 );
F_354 ( & V_560 -> V_494 ) ;
}
}
void F_355 ( struct V_557 * V_558 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_558 -> V_349 -> V_2 ;
F_92 ( L_103 , V_2 -> V_102 , V_558 , V_18 ) ;
F_349 ( V_558 , & V_558 -> V_566 , V_13 , V_18 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_334 ) ;
}
void F_356 ( struct V_414 * V_349 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_349 -> V_2 ;
struct V_544 V_113 ;
F_92 ( L_104 , V_2 -> V_102 , V_13 -> V_116 ) ;
V_113 . V_556 = F_119 ( V_349 -> V_556 ) ;
V_113 . V_543 = V_13 -> V_116 ;
F_345 ( V_13 , V_536 ) ;
F_346 ( V_13 ) ;
memcpy ( F_347 ( V_13 ) , & V_113 , V_536 ) ;
F_318 ( V_13 ) -> V_389 = V_534 ;
F_320 ( & V_349 -> V_566 , V_13 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_334 ) ;
}
static struct V_414 * F_357 ( struct V_1 * V_2 , T_12 type ,
int * V_567 )
{
struct V_568 * V_541 = & V_2 -> V_501 ;
struct V_414 * V_349 = NULL , * V_569 ;
unsigned int V_295 = 0 , F_7 = ~ 0 ;
F_358 () ;
F_359 (c, &h->list, list) {
if ( V_569 -> type != type || F_335 ( & V_569 -> V_566 ) )
continue;
if ( V_569 -> V_271 != V_452 && V_569 -> V_271 != V_570 )
continue;
V_295 ++ ;
if ( V_569 -> V_436 < F_7 ) {
F_7 = V_569 -> V_436 ;
V_349 = V_569 ;
}
if ( F_360 ( V_2 , type ) == V_295 )
break;
}
F_361 () ;
if ( V_349 ) {
int V_571 , V_572 ;
switch ( V_349 -> type ) {
case V_573 :
V_571 = V_2 -> V_365 ;
break;
case V_574 :
case V_575 :
V_571 = V_2 -> V_366 ;
break;
case V_450 :
V_571 = V_2 -> V_405 ? V_2 -> V_367 : V_2 -> V_365 ;
break;
default:
V_571 = 0 ;
F_97 ( L_105 ) ;
}
V_572 = V_571 / V_295 ;
* V_567 = V_572 ? V_572 : 1 ;
} else
* V_567 = 0 ;
F_92 ( L_106 , V_349 , * V_567 ) ;
return V_349 ;
}
static void F_362 ( struct V_1 * V_2 , T_12 type )
{
struct V_568 * V_541 = & V_2 -> V_501 ;
struct V_414 * V_569 ;
F_97 ( L_107 , V_2 -> V_102 ) ;
F_358 () ;
F_359 (c, &h->list, list) {
if ( V_569 -> type == type && V_569 -> V_436 ) {
F_97 ( L_108 ,
V_2 -> V_102 , & V_569 -> V_576 ) ;
F_363 ( V_569 , V_577 ) ;
}
}
F_361 () ;
}
static struct V_557 * F_364 ( struct V_1 * V_2 , T_12 type ,
int * V_567 )
{
struct V_568 * V_541 = & V_2 -> V_501 ;
struct V_557 * V_558 = NULL ;
unsigned int V_295 = 0 , F_7 = ~ 0 , V_578 = 0 ;
struct V_414 * V_349 ;
int V_571 , V_572 , V_579 = 0 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_358 () ;
F_359 (conn, &h->list, list) {
struct V_557 * V_412 ;
if ( V_349 -> type != type )
continue;
if ( V_349 -> V_271 != V_452 && V_349 -> V_271 != V_570 )
continue;
V_579 ++ ;
F_359 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_335 ( & V_412 -> V_566 ) )
continue;
V_13 = F_365 ( & V_412 -> V_566 ) ;
if ( V_13 -> V_580 < V_578 )
continue;
if ( V_13 -> V_580 > V_578 ) {
V_295 = 0 ;
F_7 = ~ 0 ;
V_578 = V_13 -> V_580 ;
}
V_295 ++ ;
if ( V_349 -> V_436 < F_7 ) {
F_7 = V_349 -> V_436 ;
V_558 = V_412 ;
}
}
if ( F_360 ( V_2 , type ) == V_579 )
break;
}
F_361 () ;
if ( ! V_558 )
return NULL ;
switch ( V_558 -> V_349 -> type ) {
case V_573 :
V_571 = V_2 -> V_365 ;
break;
case V_581 :
V_571 = V_2 -> V_582 ;
break;
case V_574 :
case V_575 :
V_571 = V_2 -> V_366 ;
break;
case V_450 :
V_571 = V_2 -> V_405 ? V_2 -> V_367 : V_2 -> V_365 ;
break;
default:
V_571 = 0 ;
F_97 ( L_105 ) ;
}
V_572 = V_571 / V_295 ;
* V_567 = V_572 ? V_572 : 1 ;
F_92 ( L_109 , V_558 , * V_567 ) ;
return V_558 ;
}
static void F_366 ( struct V_1 * V_2 , T_12 type )
{
struct V_568 * V_541 = & V_2 -> V_501 ;
struct V_414 * V_349 ;
int V_295 = 0 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
F_358 () ;
F_359 (conn, &h->list, list) {
struct V_557 * V_558 ;
if ( V_349 -> type != type )
continue;
if ( V_349 -> V_271 != V_452 && V_349 -> V_271 != V_570 )
continue;
V_295 ++ ;
F_359 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_558 -> V_436 ) {
V_558 -> V_436 = 0 ;
continue;
}
if ( F_335 ( & V_558 -> V_566 ) )
continue;
V_13 = F_365 ( & V_558 -> V_566 ) ;
if ( V_13 -> V_580 >= V_583 - 1 )
continue;
V_13 -> V_580 = V_583 - 1 ;
F_92 ( L_110 , V_558 , V_13 ,
V_13 -> V_580 ) ;
}
if ( F_360 ( V_2 , type ) == V_295 )
break;
}
F_361 () ;
}
static inline int F_367 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_368 ( V_13 -> V_116 - V_532 , V_2 -> V_584 ) ;
}
static void F_369 ( struct V_1 * V_2 , unsigned int V_571 )
{
if ( ! F_4 ( V_314 , & V_2 -> V_72 ) ) {
if ( ! V_571 && F_370 ( V_294 , V_2 -> V_585 +
V_586 ) )
F_362 ( V_2 , V_573 ) ;
}
}
static void F_371 ( struct V_1 * V_2 )
{
unsigned int V_571 = V_2 -> V_365 ;
struct V_557 * V_558 ;
struct V_12 * V_13 ;
int V_567 ;
F_369 ( V_2 , V_571 ) ;
while ( V_2 -> V_365 &&
( V_558 = F_364 ( V_2 , V_573 , & V_567 ) ) ) {
T_9 V_580 = ( F_365 ( & V_558 -> V_566 ) ) -> V_580 ;
while ( V_567 -- && ( V_13 = F_365 ( & V_558 -> V_566 ) ) ) {
F_92 ( L_111 , V_558 , V_13 ,
V_13 -> V_116 , V_13 -> V_580 ) ;
if ( V_13 -> V_580 < V_580 )
break;
V_13 = F_372 ( & V_558 -> V_566 ) ;
F_373 ( V_558 -> V_349 ,
F_318 ( V_13 ) -> V_587 ) ;
F_329 ( V_2 , V_13 ) ;
V_2 -> V_585 = V_294 ;
V_2 -> V_365 -- ;
V_558 -> V_436 ++ ;
V_558 -> V_349 -> V_436 ++ ;
}
}
if ( V_571 != V_2 -> V_365 )
F_366 ( V_2 , V_573 ) ;
}
static void F_374 ( struct V_1 * V_2 )
{
unsigned int V_571 = V_2 -> V_582 ;
struct V_557 * V_558 ;
struct V_12 * V_13 ;
int V_567 ;
T_5 type ;
F_369 ( V_2 , V_571 ) ;
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( V_2 -> V_147 == V_149 )
type = V_581 ;
else
type = V_573 ;
while ( V_2 -> V_582 > 0 &&
( V_558 = F_364 ( V_2 , type , & V_567 ) ) ) {
T_9 V_580 = ( F_365 ( & V_558 -> V_566 ) ) -> V_580 ;
while ( V_567 > 0 && ( V_13 = F_365 ( & V_558 -> V_566 ) ) ) {
int V_588 ;
F_92 ( L_111 , V_558 , V_13 ,
V_13 -> V_116 , V_13 -> V_580 ) ;
if ( V_13 -> V_580 < V_580 )
break;
V_13 = F_372 ( & V_558 -> V_566 ) ;
V_588 = F_367 ( V_2 , V_13 ) ;
if ( V_588 > V_2 -> V_582 )
return;
F_373 ( V_558 -> V_349 ,
F_318 ( V_13 ) -> V_587 ) ;
F_329 ( V_2 , V_13 ) ;
V_2 -> V_585 = V_294 ;
V_2 -> V_582 -= V_588 ;
V_567 -= V_588 ;
V_558 -> V_436 += V_588 ;
V_558 -> V_349 -> V_436 += V_588 ;
}
}
if ( V_571 != V_2 -> V_582 )
F_366 ( V_2 , type ) ;
}
static void F_375 ( struct V_1 * V_2 )
{
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( ! F_360 ( V_2 , V_573 ) && V_2 -> V_147 == V_148 )
return;
if ( ! F_360 ( V_2 , V_581 ) && V_2 -> V_147 == V_149 )
return;
switch ( V_2 -> V_134 ) {
case V_135 :
F_371 ( V_2 ) ;
break;
case V_139 :
F_374 ( V_2 ) ;
break;
}
}
static void F_376 ( struct V_1 * V_2 )
{
struct V_414 * V_349 ;
struct V_12 * V_13 ;
int V_567 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( ! F_360 ( V_2 , V_574 ) )
return;
while ( V_2 -> V_366 && ( V_349 = F_357 ( V_2 , V_574 , & V_567 ) ) ) {
while ( V_567 -- && ( V_13 = F_372 ( & V_349 -> V_566 ) ) ) {
F_92 ( L_112 , V_13 , V_13 -> V_116 ) ;
F_329 ( V_2 , V_13 ) ;
V_349 -> V_436 ++ ;
if ( V_349 -> V_436 == ~ 0 )
V_349 -> V_436 = 0 ;
}
}
}
static void F_377 ( struct V_1 * V_2 )
{
struct V_414 * V_349 ;
struct V_12 * V_13 ;
int V_567 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( ! F_360 ( V_2 , V_575 ) )
return;
while ( V_2 -> V_366 && ( V_349 = F_357 ( V_2 , V_575 ,
& V_567 ) ) ) {
while ( V_567 -- && ( V_13 = F_372 ( & V_349 -> V_566 ) ) ) {
F_92 ( L_112 , V_13 , V_13 -> V_116 ) ;
F_329 ( V_2 , V_13 ) ;
V_349 -> V_436 ++ ;
if ( V_349 -> V_436 == ~ 0 )
V_349 -> V_436 = 0 ;
}
}
}
static void F_378 ( struct V_1 * V_2 )
{
struct V_557 * V_558 ;
struct V_12 * V_13 ;
int V_567 , V_571 , V_412 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
if ( ! F_360 ( V_2 , V_450 ) )
return;
if ( ! F_4 ( V_314 , & V_2 -> V_72 ) ) {
if ( ! V_2 -> V_367 && V_2 -> V_406 &&
F_370 ( V_294 , V_2 -> V_589 + V_590 * 45 ) )
F_362 ( V_2 , V_450 ) ;
}
V_571 = V_2 -> V_406 ? V_2 -> V_367 : V_2 -> V_365 ;
V_412 = V_571 ;
while ( V_571 && ( V_558 = F_364 ( V_2 , V_450 , & V_567 ) ) ) {
T_9 V_580 = ( F_365 ( & V_558 -> V_566 ) ) -> V_580 ;
while ( V_567 -- && ( V_13 = F_365 ( & V_558 -> V_566 ) ) ) {
F_92 ( L_111 , V_558 , V_13 ,
V_13 -> V_116 , V_13 -> V_580 ) ;
if ( V_13 -> V_580 < V_580 )
break;
V_13 = F_372 ( & V_558 -> V_566 ) ;
F_329 ( V_2 , V_13 ) ;
V_2 -> V_589 = V_294 ;
V_571 -- ;
V_558 -> V_436 ++ ;
V_558 -> V_349 -> V_436 ++ ;
}
}
if ( V_2 -> V_406 )
V_2 -> V_367 = V_571 ;
else
V_2 -> V_365 = V_571 ;
if ( V_571 != V_412 )
F_366 ( V_2 , V_450 ) ;
}
static void V_504 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 , V_334 ) ;
struct V_12 * V_13 ;
F_92 ( L_113 , V_2 -> V_102 , V_2 -> V_365 ,
V_2 -> V_366 , V_2 -> V_367 ) ;
if ( ! F_4 ( V_313 , & V_2 -> V_72 ) ) {
F_375 ( V_2 ) ;
F_376 ( V_2 ) ;
F_377 ( V_2 ) ;
F_378 ( V_2 ) ;
}
while ( ( V_13 = F_372 ( & V_2 -> V_361 ) ) )
F_329 ( V_2 , V_13 ) ;
}
static void F_379 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_542 * V_113 = ( void * ) V_13 -> V_26 ;
struct V_414 * V_349 ;
T_13 V_556 , V_18 ;
F_98 ( V_13 , V_532 ) ;
V_556 = F_33 ( V_113 -> V_556 ) ;
V_18 = F_380 ( V_556 ) ;
V_556 = F_381 ( V_556 ) ;
F_92 ( L_114 , V_2 -> V_102 , V_13 -> V_116 ,
V_556 , V_18 ) ;
V_2 -> V_368 . V_591 ++ ;
F_19 ( V_2 ) ;
V_349 = F_382 ( V_2 , V_556 ) ;
F_22 ( V_2 ) ;
if ( V_349 ) {
F_373 ( V_349 , V_592 ) ;
F_383 ( V_349 , V_13 , V_18 ) ;
return;
} else {
F_97 ( L_115 ,
V_2 -> V_102 , V_556 ) ;
}
F_16 ( V_13 ) ;
}
static void F_384 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_544 * V_113 = ( void * ) V_13 -> V_26 ;
struct V_414 * V_349 ;
T_13 V_556 ;
F_98 ( V_13 , V_536 ) ;
V_556 = F_33 ( V_113 -> V_556 ) ;
F_92 ( L_116 , V_2 -> V_102 , V_13 -> V_116 , V_556 ) ;
V_2 -> V_368 . V_593 ++ ;
F_19 ( V_2 ) ;
V_349 = F_382 ( V_2 , V_556 ) ;
F_22 ( V_2 ) ;
if ( V_349 ) {
F_385 ( V_349 , V_13 ) ;
return;
} else {
F_97 ( L_117 ,
V_2 -> V_102 , V_556 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_386 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_365 ( & V_2 -> V_337 ) ;
if ( ! V_13 )
return true ;
return F_318 ( V_13 ) -> V_127 . V_555 ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_435 * V_436 ;
struct V_12 * V_13 ;
T_8 V_109 ;
if ( ! V_2 -> V_340 )
return;
V_436 = ( void * ) V_2 -> V_340 -> V_26 ;
V_109 = F_33 ( V_436 -> V_109 ) ;
if ( V_109 == V_25 )
return;
V_13 = F_388 ( V_2 -> V_340 , V_289 ) ;
if ( ! V_13 )
return;
F_389 ( & V_2 -> V_337 , V_13 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_335 ) ;
}
void F_390 ( struct V_1 * V_2 , T_8 V_109 , T_5 V_465 )
{
T_15 V_594 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_92 ( L_118 , V_109 , V_465 ) ;
if ( ! F_343 ( V_2 , V_109 ) ) {
if ( F_4 ( V_327 , & V_2 -> V_18 ) && V_109 == V_25 )
F_387 ( V_2 ) ;
return;
}
if ( ! V_465 && ! F_386 ( V_2 ) )
return;
if ( V_2 -> V_340 ) {
V_594 = F_318 ( V_2 -> V_340 ) -> V_127 . V_552 ;
if ( V_594 ) {
F_318 ( V_2 -> V_340 ) -> V_127 . V_552 = NULL ;
goto V_595;
}
}
F_337 ( & V_2 -> V_337 . V_494 , V_18 ) ;
while ( ( V_13 = F_391 ( & V_2 -> V_337 ) ) ) {
if ( F_318 ( V_13 ) -> V_127 . V_555 ) {
F_392 ( & V_2 -> V_337 , V_13 ) ;
break;
}
V_594 = F_318 ( V_13 ) -> V_127 . V_552 ;
F_16 ( V_13 ) ;
}
F_339 ( & V_2 -> V_337 . V_494 , V_18 ) ;
V_595:
if ( V_594 )
V_594 ( V_2 , V_465 ) ;
}
static void V_502 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 , V_336 ) ;
struct V_12 * V_13 ;
F_92 ( L_19 , V_2 -> V_102 ) ;
while ( ( V_13 = F_372 ( & V_2 -> V_338 ) ) ) {
F_330 ( V_2 , V_13 ) ;
if ( F_331 ( & V_2 -> V_551 ) ) {
F_332 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_313 , & V_2 -> V_72 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_327 , & V_2 -> V_18 ) ) {
switch ( F_318 ( V_13 ) -> V_389 ) {
case V_528 :
case V_534 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_318 ( V_13 ) -> V_389 ) {
case V_529 :
F_92 ( L_119 , V_2 -> V_102 ) ;
F_393 ( V_2 , V_13 ) ;
break;
case V_528 :
F_92 ( L_120 , V_2 -> V_102 ) ;
F_379 ( V_2 , V_13 ) ;
break;
case V_534 :
F_92 ( L_121 , V_2 -> V_102 ) ;
F_384 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_503 ( struct V_408 * V_409 )
{
struct V_1 * V_2 = F_226 ( V_409 , struct V_1 , V_335 ) ;
struct V_12 * V_13 ;
F_92 ( L_122 , V_2 -> V_102 ,
F_331 ( & V_2 -> V_326 ) , F_334 ( & V_2 -> V_337 ) ) ;
if ( F_331 ( & V_2 -> V_326 ) ) {
V_13 = F_372 ( & V_2 -> V_337 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_340 ) ;
V_2 -> V_340 = F_388 ( V_13 , V_289 ) ;
if ( V_2 -> V_340 ) {
F_394 ( & V_2 -> V_326 ) ;
F_329 ( V_2 , V_13 ) ;
if ( F_4 ( V_133 , & V_2 -> V_18 ) )
F_203 ( & V_2 -> V_351 ) ;
else
F_395 ( & V_2 -> V_351 ,
V_24 ) ;
} else {
F_389 ( & V_2 -> V_337 , V_13 ) ;
F_252 ( V_2 -> V_437 , & V_2 -> V_335 ) ;
}
}
}
void F_275 ( struct V_126 * V_127 )
{
struct V_596 V_183 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_15 = V_597 ;
F_114 ( V_127 , V_598 , sizeof( V_183 ) , & V_183 ) ;
}
static void F_396 ( struct V_126 * V_127 ,
struct V_99 * V_449 )
{
struct V_599 V_183 ;
V_183 . V_41 = V_449 -> V_80 ;
F_148 ( & V_183 . V_40 , & V_449 -> V_79 ) ;
F_114 ( V_127 , V_600 , sizeof( V_183 ) , & V_183 ) ;
}
static T_5 F_397 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_99 * V_449 ;
struct V_38 * V_39 ;
T_16 V_601 = 0 ;
F_26 (b, &hdev->le_white_list, list) {
struct V_602 V_183 ;
if ( F_265 ( & V_2 -> V_464 ,
& V_39 -> V_40 , V_39 -> V_41 ) ||
F_265 ( & V_2 -> V_461 ,
& V_39 -> V_40 , V_39 -> V_41 ) ) {
V_601 ++ ;
continue;
}
V_183 . V_41 = V_39 -> V_41 ;
F_148 ( & V_183 . V_40 , & V_39 -> V_40 ) ;
F_114 ( V_127 , V_603 ,
sizeof( V_183 ) , & V_183 ) ;
}
F_26 (params, &hdev->pend_le_conns, action) {
if ( F_257 ( & V_2 -> V_500 ,
& V_449 -> V_79 , V_449 -> V_80 ) )
continue;
if ( V_601 >= V_2 -> V_246 ) {
return 0x00 ;
}
if ( F_244 ( V_2 , & V_449 -> V_79 ,
V_449 -> V_80 ) ) {
return 0x00 ;
}
V_601 ++ ;
F_396 ( V_127 , V_449 ) ;
}
F_26 (params, &hdev->pend_le_reports, action) {
if ( F_257 ( & V_2 -> V_500 ,
& V_449 -> V_79 , V_449 -> V_80 ) )
continue;
if ( V_601 >= V_2 -> V_246 ) {
return 0x00 ;
}
if ( F_244 ( V_2 , & V_449 -> V_79 ,
V_449 -> V_80 ) ) {
return 0x00 ;
}
V_601 ++ ;
F_396 ( V_127 , V_449 ) ;
}
return 0x01 ;
}
void F_398 ( struct V_126 * V_127 )
{
struct V_604 V_605 ;
struct V_596 V_606 ;
struct V_1 * V_2 = V_127 -> V_2 ;
T_5 V_473 ;
T_5 V_607 ;
if ( F_278 ( V_127 , false , & V_473 ) )
return;
V_607 = F_397 ( V_127 ) ;
memset ( & V_605 , 0 , sizeof( V_605 ) ) ;
V_605 . type = V_608 ;
V_605 . V_609 = F_119 ( V_2 -> V_488 ) ;
V_605 . V_610 = F_119 ( V_2 -> V_489 ) ;
V_605 . V_611 = V_473 ;
V_605 . V_607 = V_607 ;
F_114 ( V_127 , V_612 , sizeof( V_605 ) ,
& V_605 ) ;
memset ( & V_606 , 0 , sizeof( V_606 ) ) ;
V_606 . V_15 = V_613 ;
V_606 . V_614 = V_615 ;
F_114 ( V_127 , V_598 , sizeof( V_606 ) ,
& V_606 ) ;
}
static void F_399 ( struct V_1 * V_2 , T_5 V_465 )
{
if ( V_465 )
F_92 ( L_123
L_124 , V_465 ) ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_126 V_127 ;
struct V_414 * V_349 ;
int V_16 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ||
F_4 ( V_327 , & V_2 -> V_18 ) ||
F_4 ( V_222 , & V_2 -> V_72 ) ||
F_4 ( V_320 , & V_2 -> V_72 ) ||
F_4 ( V_344 , & V_2 -> V_72 ) ||
F_4 ( V_319 , & V_2 -> V_72 ) )
return;
if ( ! F_4 ( V_170 , & V_2 -> V_72 ) )
return;
if ( V_2 -> V_48 . V_271 != V_275 )
return;
F_101 ( & V_127 , V_2 ) ;
if ( F_310 ( & V_2 -> V_464 ) &&
F_310 ( & V_2 -> V_461 ) ) {
if ( ! F_4 ( V_616 , & V_2 -> V_72 ) )
return;
F_275 ( & V_127 ) ;
F_92 ( L_125 , V_2 -> V_102 ) ;
} else {
V_349 = F_277 ( V_2 , V_450 , V_470 ) ;
if ( V_349 )
return;
if ( F_4 ( V_616 , & V_2 -> V_72 ) )
F_275 ( & V_127 ) ;
F_398 ( & V_127 ) ;
F_92 ( L_126 , V_2 -> V_102 ) ;
}
V_16 = F_103 ( & V_127 , F_399 ) ;
if ( V_16 )
F_97 ( L_127 , V_16 ) ;
}
static bool F_400 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->whitelist, list) {
struct V_414 * V_349 ;
V_349 = F_264 ( V_2 , V_573 , & V_39 -> V_40 ) ;
if ( ! V_349 )
return true ;
if ( V_349 -> V_271 != V_452 && V_349 -> V_271 != V_570 )
return true ;
}
return false ;
}
void F_401 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
T_5 V_261 ;
if ( ! F_4 ( V_179 , & V_2 -> V_72 ) )
return;
if ( ! F_402 ( V_2 ) )
return;
if ( F_403 ( V_2 ) )
return;
if ( F_4 ( V_373 , & V_2 -> V_72 ) ||
F_400 ( V_2 ) )
V_261 = V_372 ;
else
V_261 = V_617 ;
if ( F_4 ( V_618 , & V_2 -> V_18 ) == ! ! ( V_261 & V_372 ) )
return;
if ( F_4 ( V_354 , & V_2 -> V_72 ) )
V_261 |= V_374 ;
if ( V_127 )
F_114 ( V_127 , V_262 , 1 , & V_261 ) ;
else
F_342 ( V_2 , V_262 , 1 , & V_261 ) ;
}
