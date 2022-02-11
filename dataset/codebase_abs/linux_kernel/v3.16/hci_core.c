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
static int F_55 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 > V_2 -> V_79 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_80 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_56 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_80 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_57 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 < V_2 -> V_80 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_79 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_58 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_79 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_8 V_81 ;
T_5 V_82 ;
F_19 ( V_2 ) ;
F_60 ( V_2 , & V_81 , & V_82 ) ;
F_20 ( V_28 , L_9 , & V_81 , V_82 ,
16 , V_2 -> V_83 , & V_2 -> V_84 ) ;
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
F_20 ( V_28 , L_10 , & V_2 -> V_85 ) ;
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
F_20 ( V_28 , L_10 , & V_2 -> V_86 ) ;
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
V_9 [ 0 ] = F_4 ( V_87 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
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
return - V_73 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_87 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_87 , & V_2 -> V_11 ) ;
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
F_34 (p, n, &hdev->identity_resolving_keys) {
struct V_88 * V_83 = F_35 ( V_31 , struct V_88 , V_64 ) ;
F_20 ( V_28 , L_9 ,
& V_83 -> V_40 , V_83 -> V_82 ,
16 , V_83 -> V_45 , & V_83 -> V_84 ) ;
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
F_34 (p, n, &hdev->long_term_keys) {
struct V_89 * V_90 = F_35 ( V_31 , struct V_89 , V_64 ) ;
F_20 ( V_28 , L_11 ,
& V_90 -> V_40 , V_90 -> V_41 , V_90 -> V_91 ,
V_90 -> type , V_90 -> V_92 , F_31 ( V_90 -> V_93 ) ,
F_73 ( V_90 -> rand ) , 16 , V_90 -> V_45 ) ;
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
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 > V_2 -> V_94 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_95 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_76 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_95 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 < V_2 -> V_95 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_94 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_78 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_94 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_79 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x01 || V_45 > 0x07 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_96 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_80 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_96 ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_1 F_81 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_97 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_82 ( struct V_4 * V_98 , const char T_2 * V_99 ,
T_3 V_6 , T_4 * V_100 )
{
struct V_1 * V_2 = V_98 -> V_8 ;
bool V_15 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
if ( F_8 ( V_9 , V_99 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) < 0 )
return - V_21 ;
if ( V_15 == F_4 ( V_97 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_97 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_83 ( struct V_27 * V_101 , void * V_29 )
{
struct V_1 * V_2 = V_101 -> V_30 ;
struct V_102 * V_31 ;
F_19 ( V_2 ) ;
F_26 (p, &hdev->le_conn_params, list) {
F_20 ( V_101 , L_12 , & V_31 -> V_81 , V_31 -> V_82 ,
V_31 -> V_103 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_83 , V_36 -> V_37 ) ;
}
static T_1 F_85 ( struct V_4 * V_4 , const char T_2 * V_26 ,
T_3 V_6 , T_4 * V_104 )
{
struct V_27 * V_101 = V_4 -> V_8 ;
struct V_1 * V_2 = V_101 -> V_30 ;
T_5 V_103 = 0 ;
T_8 V_81 ;
T_5 V_82 ;
char * V_9 ;
int V_16 = 0 ;
int V_61 ;
if ( * V_104 != 0 )
return - V_21 ;
if ( V_6 < 3 )
return - V_21 ;
V_9 = F_86 ( V_26 , V_6 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
if ( memcmp ( V_9 , L_13 , 3 ) == 0 ) {
V_61 = sscanf ( & V_9 [ 4 ] , L_14 ,
& V_81 . V_39 [ 5 ] , & V_81 . V_39 [ 4 ] , & V_81 . V_39 [ 3 ] , & V_81 . V_39 [ 2 ] ,
& V_81 . V_39 [ 1 ] , & V_81 . V_39 [ 0 ] , & V_82 ,
& V_103 ) ;
if ( V_61 < 7 ) {
V_16 = - V_21 ;
goto V_105;
}
F_19 ( V_2 ) ;
V_16 = F_87 ( V_2 , & V_81 , V_82 , V_103 ,
V_2 -> V_95 ,
V_2 -> V_94 ) ;
F_22 ( V_2 ) ;
if ( V_16 )
goto V_105;
} else if ( memcmp ( V_9 , L_15 , 3 ) == 0 ) {
V_61 = sscanf ( & V_9 [ 4 ] , L_16 ,
& V_81 . V_39 [ 5 ] , & V_81 . V_39 [ 4 ] , & V_81 . V_39 [ 3 ] , & V_81 . V_39 [ 2 ] ,
& V_81 . V_39 [ 1 ] , & V_81 . V_39 [ 0 ] , & V_82 ) ;
if ( V_61 < 7 ) {
V_16 = - V_21 ;
goto V_105;
}
F_19 ( V_2 ) ;
F_88 ( V_2 , & V_81 , V_82 ) ;
F_22 ( V_2 ) ;
} else if ( memcmp ( V_9 , L_17 , 3 ) == 0 ) {
F_19 ( V_2 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
F_22 ( V_2 ) ;
} else {
V_16 = - V_21 ;
}
V_105:
F_92 ( V_9 ) ;
if ( V_16 )
return V_16 ;
else
return V_6 ;
}
static void F_93 ( struct V_1 * V_2 , T_5 V_106 )
{
F_94 ( L_18 , V_2 -> V_107 , V_106 ) ;
if ( V_2 -> V_108 == V_109 ) {
V_2 -> V_110 = V_106 ;
V_2 -> V_108 = V_111 ;
F_95 ( & V_2 -> V_112 ) ;
}
}
static void F_96 ( struct V_1 * V_2 , int V_16 )
{
F_94 ( L_19 , V_2 -> V_107 , V_16 ) ;
if ( V_2 -> V_108 == V_109 ) {
V_2 -> V_110 = V_16 ;
V_2 -> V_108 = V_113 ;
F_95 ( & V_2 -> V_112 ) ;
}
}
static struct V_12 * F_97 ( struct V_1 * V_2 , T_9 V_114 ,
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
return F_98 ( - V_120 ) ;
if ( V_13 -> V_121 < sizeof( * V_118 ) ) {
F_99 ( L_20 ) ;
goto V_122;
}
V_118 = ( void * ) V_13 -> V_26 ;
F_100 ( V_13 , V_123 ) ;
if ( V_3 ) {
if ( V_118 -> V_124 != V_3 )
goto V_122;
return V_13 ;
}
if ( V_118 -> V_124 != V_125 ) {
F_94 ( L_21 , V_118 -> V_124 ) ;
goto V_122;
}
if ( V_13 -> V_121 < sizeof( * V_116 ) ) {
F_99 ( L_22 ) ;
goto V_122;
}
V_116 = ( void * ) V_13 -> V_26 ;
F_100 ( V_13 , sizeof( * V_116 ) ) ;
if ( V_114 == F_31 ( V_116 -> V_114 ) )
return V_13 ;
F_94 ( L_23 , V_114 ,
F_31 ( V_116 -> V_114 ) ) ;
V_122:
F_16 ( V_13 ) ;
return F_98 ( - V_120 ) ;
}
struct V_12 * F_101 ( struct V_1 * V_2 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_5 V_3 , T_10 V_128 )
{
F_102 ( V_129 , V_130 ) ;
struct V_131 V_132 ;
int V_16 = 0 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_103 ( & V_132 , V_2 ) ;
F_104 ( & V_132 , V_114 , V_126 , V_127 , V_3 ) ;
V_2 -> V_108 = V_109 ;
V_16 = F_105 ( & V_132 , F_93 ) ;
if ( V_16 < 0 )
return F_98 ( V_16 ) ;
F_106 ( & V_2 -> V_112 , & V_129 ) ;
F_107 ( V_133 ) ;
F_108 ( V_128 ) ;
F_109 ( & V_2 -> V_112 , & V_129 ) ;
if ( F_110 ( V_130 ) )
return F_98 ( - V_134 ) ;
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
F_94 ( L_25 , V_2 -> V_107 , V_16 ) ;
if ( V_16 < 0 )
return F_98 ( V_16 ) ;
return F_97 ( V_2 , V_114 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_10 V_128 )
{
return F_101 ( V_2 , V_114 , V_126 , V_127 , 0 , V_128 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
void (* F_112)( struct V_131 * V_132 ,
unsigned long V_136 ) ,
unsigned long V_136 , T_11 V_128 )
{
struct V_131 V_132 ;
F_102 ( V_129 , V_130 ) ;
int V_16 = 0 ;
F_94 ( L_26 , V_2 -> V_107 ) ;
F_103 ( & V_132 , V_2 ) ;
V_2 -> V_108 = V_109 ;
F_112 ( & V_132 , V_136 ) ;
V_16 = F_105 ( & V_132 , F_93 ) ;
if ( V_16 < 0 ) {
V_2 -> V_108 = 0 ;
if ( V_16 == - V_120 )
return 0 ;
return V_16 ;
}
F_106 ( & V_2 -> V_112 , & V_129 ) ;
F_107 ( V_133 ) ;
F_108 ( V_128 ) ;
F_109 ( & V_2 -> V_112 , & V_129 ) ;
if ( F_110 ( V_130 ) )
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
F_94 ( L_25 , V_2 -> V_107 , V_16 ) ;
return V_16 ;
}
static int F_113 ( struct V_1 * V_2 ,
void (* V_132)( struct V_131 * V_132 ,
unsigned long V_136 ) ,
unsigned long V_136 , T_11 V_128 )
{
int V_137 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_137 = F_111 ( V_2 , V_132 , V_136 , V_128 ) ;
F_12 ( V_2 ) ;
return V_137 ;
}
static void F_114 ( struct V_131 * V_132 , unsigned long V_136 )
{
F_94 ( L_27 , V_132 -> V_2 -> V_107 , V_136 ) ;
F_115 ( V_138 , & V_132 -> V_2 -> V_18 ) ;
F_116 ( V_132 , V_25 , 0 , NULL ) ;
}
static void F_117 ( struct V_131 * V_132 )
{
V_132 -> V_2 -> V_139 = V_140 ;
F_116 ( V_132 , V_141 , 0 , NULL ) ;
F_116 ( V_132 , V_142 , 0 , NULL ) ;
F_116 ( V_132 , V_143 , 0 , NULL ) ;
}
static void F_118 ( struct V_131 * V_132 )
{
V_132 -> V_2 -> V_139 = V_144 ;
F_116 ( V_132 , V_142 , 0 , NULL ) ;
F_116 ( V_132 , V_145 , 0 , NULL ) ;
F_116 ( V_132 , V_141 , 0 , NULL ) ;
F_116 ( V_132 , V_146 , 0 , NULL ) ;
F_116 ( V_132 , V_147 , 0 , NULL ) ;
F_116 ( V_132 , V_148 , 0 , NULL ) ;
F_116 ( V_132 , V_149 , 0 , NULL ) ;
}
static void F_119 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
F_94 ( L_27 , V_2 -> V_107 , V_136 ) ;
if ( ! F_4 ( V_150 , & V_2 -> V_151 ) )
F_114 ( V_132 , 0 ) ;
switch ( V_2 -> V_152 ) {
case V_153 :
F_117 ( V_132 ) ;
break;
case V_154 :
F_118 ( V_132 ) ;
break;
default:
F_99 ( L_28 , V_2 -> V_152 ) ;
break;
}
}
static void F_120 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_12 V_127 ;
T_7 V_155 ;
F_116 ( V_132 , V_156 , 0 , NULL ) ;
F_116 ( V_132 , V_157 , 0 , NULL ) ;
F_116 ( V_132 , V_158 , 0 , NULL ) ;
F_116 ( V_132 , V_159 , 0 , NULL ) ;
F_116 ( V_132 , V_160 , 0 , NULL ) ;
F_116 ( V_132 , V_161 , 0 , NULL ) ;
V_155 = V_162 ;
F_116 ( V_132 , V_163 , 1 , & V_155 ) ;
V_127 = F_121 ( 0x7d00 ) ;
F_116 ( V_132 , V_164 , 2 , & V_127 ) ;
if ( V_2 -> V_165 != 31 && V_2 -> V_166 > V_167 ) {
F_116 ( V_132 , V_168 , 0 , NULL ) ;
F_116 ( V_132 , V_169 , 0 , NULL ) ;
}
}
static void F_122 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
F_116 ( V_132 , V_170 , 0 , NULL ) ;
F_116 ( V_132 , V_171 , 0 , NULL ) ;
F_116 ( V_132 , V_172 , 0 , NULL ) ;
F_116 ( V_132 , V_173 , 0 , NULL ) ;
F_116 ( V_132 , V_174 , 0 , NULL ) ;
F_116 ( V_132 , V_175 , 0 , NULL ) ;
if ( ! F_123 ( V_2 ) )
F_115 ( V_176 , & V_2 -> V_11 ) ;
}
static T_5 F_124 ( struct V_1 * V_2 )
{
if ( F_125 ( V_2 ) )
return 0x02 ;
if ( F_126 ( V_2 ) )
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
static void F_127 ( struct V_131 * V_132 )
{
T_5 V_69 ;
V_69 = F_124 ( V_132 -> V_2 ) ;
F_116 ( V_132 , V_179 , 1 , & V_69 ) ;
}
static void F_128 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_180 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_166 < V_181 )
return;
if ( F_123 ( V_2 ) ) {
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
if ( F_126 ( V_2 ) )
V_180 [ 4 ] |= 0x02 ;
if ( F_129 ( V_2 ) )
V_180 [ 5 ] |= 0x20 ;
if ( F_130 ( V_2 ) )
V_180 [ 5 ] |= 0x80 ;
if ( F_125 ( V_2 ) )
V_180 [ 5 ] |= 0x40 ;
if ( F_131 ( V_2 ) )
V_180 [ 7 ] |= 0x01 ;
if ( F_132 ( V_2 ) )
V_180 [ 6 ] |= 0x80 ;
if ( F_133 ( V_2 ) ) {
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
F_116 ( V_132 , V_182 , sizeof( V_180 ) , V_180 ) ;
if ( F_21 ( V_2 ) ) {
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_180 [ 0 ] = 0x1f ;
F_116 ( V_132 , V_183 ,
sizeof( V_180 ) , V_180 ) ;
}
}
static void F_134 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( F_123 ( V_2 ) )
F_120 ( V_132 ) ;
else
F_135 ( V_184 , & V_2 -> V_11 ) ;
if ( F_21 ( V_2 ) )
F_122 ( V_132 ) ;
F_128 ( V_132 ) ;
if ( V_2 -> V_165 != 31 && V_2 -> V_166 > V_167 )
F_116 ( V_132 , V_145 , 0 , NULL ) ;
if ( F_133 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_185 , & V_2 -> V_11 ) ) {
T_5 V_69 = 0x01 ;
F_116 ( V_132 , V_186 ,
sizeof( V_69 ) , & V_69 ) ;
} else {
struct V_187 V_188 ;
memset ( V_2 -> V_189 , 0 , sizeof( V_2 -> V_189 ) ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
F_116 ( V_132 , V_190 , sizeof( V_188 ) , & V_188 ) ;
}
}
if ( F_126 ( V_2 ) )
F_127 ( V_132 ) ;
if ( F_136 ( V_2 ) )
F_116 ( V_132 , V_191 , 0 , NULL ) ;
if ( F_137 ( V_2 ) ) {
struct V_192 V_188 ;
V_188 . V_193 = 0x01 ;
F_116 ( V_132 , V_194 ,
sizeof( V_188 ) , & V_188 ) ;
}
if ( F_4 ( V_195 , & V_2 -> V_11 ) ) {
T_5 V_15 = 1 ;
F_116 ( V_132 , V_196 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_138 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_197 V_188 ;
T_9 V_198 = 0 ;
if ( F_139 ( V_2 ) )
V_198 |= V_199 ;
if ( F_140 ( V_2 ) )
V_198 |= V_200 ;
if ( F_141 ( V_2 ) )
V_198 |= V_201 ;
if ( F_142 ( V_2 ) )
V_198 |= V_202 ;
V_188 . V_203 = F_121 ( V_198 ) ;
F_116 ( V_132 , V_204 , sizeof( V_188 ) , & V_188 ) ;
}
static void F_143 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_205 V_188 ;
if ( ! F_123 ( V_2 ) )
return;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
if ( F_4 ( V_176 , & V_2 -> V_11 ) ) {
V_188 . V_206 = 0x01 ;
V_188 . V_207 = F_144 ( V_2 ) ;
}
if ( V_188 . V_206 != F_145 ( V_2 ) )
F_116 ( V_132 , V_208 , sizeof( V_188 ) ,
& V_188 ) ;
}
static void F_146 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_180 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_147 ( V_2 ) ) {
V_180 [ 1 ] |= 0x40 ;
V_180 [ 1 ] |= 0x80 ;
V_180 [ 2 ] |= 0x10 ;
V_180 [ 2 ] |= 0x20 ;
}
if ( F_148 ( V_2 ) ) {
V_180 [ 2 ] |= 0x01 ;
V_180 [ 2 ] |= 0x02 ;
V_180 [ 2 ] |= 0x04 ;
V_180 [ 2 ] |= 0x08 ;
}
if ( F_149 ( V_2 ) )
V_180 [ 2 ] |= 0x80 ;
F_116 ( V_132 , V_209 , sizeof( V_180 ) , V_180 ) ;
}
static void F_150 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_31 ;
if ( V_2 -> V_210 [ 6 ] & 0x80 &&
! F_4 ( V_211 , & V_2 -> V_151 ) ) {
struct V_212 V_188 ;
F_151 ( & V_188 . V_40 , V_213 ) ;
V_188 . V_214 = 0x01 ;
F_116 ( V_132 , V_215 ,
sizeof( V_188 ) , & V_188 ) ;
}
if ( V_2 -> V_210 [ 5 ] & 0x10 )
F_138 ( V_132 ) ;
if ( F_21 ( V_2 ) )
F_143 ( V_132 ) ;
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_192 V_188 ;
V_188 . V_193 = V_31 ;
F_116 ( V_132 , V_194 ,
sizeof( V_188 ) , & V_188 ) ;
}
}
static void F_152 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( V_2 -> V_210 [ 22 ] & 0x04 )
F_146 ( V_132 ) ;
if ( F_153 ( V_2 ) )
F_116 ( V_132 , V_216 , 0 , NULL ) ;
if ( ( F_154 ( V_2 ) ||
F_4 ( V_72 , & V_2 -> V_11 ) ) &&
F_4 ( V_217 , & V_2 -> V_11 ) ) {
T_5 V_218 = 0x01 ;
F_116 ( V_132 , V_219 ,
sizeof( V_218 ) , & V_218 ) ;
}
}
static int F_155 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_111 ( V_2 , F_119 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_221 , & V_2 -> V_11 ) ) {
F_156 ( L_29 , 0644 , V_2 -> V_222 , V_2 ,
& V_223 ) ;
}
if ( V_2 -> V_152 != V_153 )
return 0 ;
V_16 = F_111 ( V_2 , F_134 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_111 ( V_2 , F_150 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_111 ( V_2 , F_152 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) )
return 0 ;
F_156 ( L_30 , 0444 , V_2 -> V_222 , V_2 ,
& V_224 ) ;
F_157 ( L_31 , 0444 , V_2 -> V_222 ,
& V_2 -> V_165 ) ;
F_158 ( L_32 , 0444 , V_2 -> V_222 , & V_2 -> V_166 ) ;
F_157 ( L_33 , 0444 , V_2 -> V_222 , & V_2 -> V_177 ) ;
F_156 ( L_34 , 0444 , V_2 -> V_222 , V_2 ,
& V_225 ) ;
F_156 ( L_35 , 0444 , V_2 -> V_222 , V_2 , & V_226 ) ;
F_156 ( L_36 , 0644 , V_2 -> V_222 , V_2 ,
& V_227 ) ;
F_156 ( L_37 , 0644 , V_2 -> V_222 , V_2 ,
& V_228 ) ;
if ( F_123 ( V_2 ) ) {
F_156 ( L_38 , 0444 , V_2 -> V_222 ,
V_2 , & V_229 ) ;
F_156 ( L_39 , 0400 , V_2 -> V_222 ,
V_2 , & V_230 ) ;
F_156 ( L_40 , 0444 , V_2 -> V_222 ,
V_2 , & V_231 ) ;
F_156 ( L_41 , 0444 , V_2 -> V_222 ,
V_2 , & V_232 ) ;
}
if ( F_133 ( V_2 ) ) {
F_156 ( L_42 , 0644 , V_2 -> V_222 ,
V_2 , & V_233 ) ;
F_156 ( L_43 , 0644 , V_2 -> V_222 ,
V_2 , & V_234 ) ;
F_156 ( L_44 , 0644 , V_2 -> V_222 ,
V_2 , & V_235 ) ;
F_156 ( L_45 , 0444 , V_2 -> V_222 ,
V_2 , & V_236 ) ;
}
if ( F_141 ( V_2 ) ) {
F_156 ( L_46 , 0644 , V_2 -> V_222 ,
V_2 , & V_237 ) ;
F_156 ( L_47 , 0644 , V_2 -> V_222 ,
V_2 , & V_238 ) ;
F_156 ( L_48 , 0644 , V_2 -> V_222 ,
V_2 , & V_239 ) ;
}
if ( F_21 ( V_2 ) ) {
F_156 ( L_49 , 0400 , V_2 -> V_222 ,
V_2 , & V_240 ) ;
F_156 ( L_50 , 0644 , V_2 -> V_222 ,
V_2 , & V_241 ) ;
F_156 ( L_51 , 0444 , V_2 -> V_222 ,
V_2 , & V_242 ) ;
F_156 ( L_52 , 0444 , V_2 -> V_222 ,
V_2 , & V_243 ) ;
if ( F_159 ( & V_2 -> V_40 , V_213 ) )
F_156 ( L_53 , 0644 ,
V_2 -> V_222 , V_2 ,
& V_244 ) ;
F_158 ( L_54 , 0444 , V_2 -> V_222 ,
& V_2 -> V_245 ) ;
F_156 ( L_55 , 0444 , V_2 -> V_222 , V_2 ,
& V_246 ) ;
F_156 ( L_56 , 0400 ,
V_2 -> V_222 , V_2 ,
& V_247 ) ;
F_156 ( L_57 , 0400 , V_2 -> V_222 ,
V_2 , & V_248 ) ;
F_156 ( L_58 , 0644 , V_2 -> V_222 ,
V_2 , & V_249 ) ;
F_156 ( L_59 , 0644 , V_2 -> V_222 ,
V_2 , & V_250 ) ;
F_156 ( L_60 , 0644 , V_2 -> V_222 ,
V_2 , & V_251 ) ;
F_156 ( L_61 , 0644 , V_2 -> V_222 , V_2 ,
& V_252 ) ;
F_156 ( L_62 , 0644 , V_2 -> V_222 , V_2 ,
& V_253 ) ;
F_157 ( L_63 , 0644 ,
V_2 -> V_222 ,
& V_2 -> V_254 ) ;
}
return 0 ;
}
static void F_160 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_255 = V_136 ;
F_94 ( L_64 , V_132 -> V_2 -> V_107 , V_255 ) ;
F_116 ( V_132 , V_256 , 1 , & V_255 ) ;
}
static void F_161 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_257 = V_136 ;
F_94 ( L_64 , V_132 -> V_2 -> V_107 , V_257 ) ;
F_116 ( V_132 , V_196 , 1 , & V_257 ) ;
}
static void F_162 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_7 V_258 = V_136 ;
F_94 ( L_64 , V_132 -> V_2 -> V_107 , V_258 ) ;
F_116 ( V_132 , V_259 , 1 , & V_258 ) ;
}
static void F_163 ( struct V_131 * V_132 , unsigned long V_136 )
{
T_12 V_203 = F_121 ( V_136 ) ;
F_94 ( L_64 , V_132 -> V_2 -> V_107 , V_203 ) ;
F_116 ( V_132 , V_204 , 2 , & V_203 ) ;
}
struct V_1 * F_164 ( int V_260 )
{
struct V_1 * V_2 = NULL , * V_261 ;
F_94 ( L_65 , V_260 ) ;
if ( V_260 < 0 )
return NULL ;
F_165 ( & V_262 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_261 -> V_263 == V_260 ) {
V_2 = F_166 ( V_261 ) ;
break;
}
}
F_167 ( & V_262 ) ;
return V_2 ;
}
bool F_168 ( struct V_1 * V_2 )
{
struct V_46 * V_264 = & V_2 -> V_48 ;
switch ( V_264 -> V_265 ) {
case V_266 :
case V_267 :
return true ;
default:
return false ;
}
}
void F_169 ( struct V_1 * V_2 , int V_265 )
{
F_94 ( L_66 , V_2 -> V_107 , V_2 -> V_48 . V_265 , V_265 ) ;
if ( V_2 -> V_48 . V_265 == V_265 )
return;
switch ( V_265 ) {
case V_268 :
F_91 ( V_2 ) ;
if ( V_2 -> V_48 . V_265 != V_269 )
F_170 ( V_2 , 0 ) ;
break;
case V_269 :
break;
case V_266 :
F_170 ( V_2 , 1 ) ;
break;
case V_267 :
break;
case V_270 :
break;
}
V_2 -> V_48 . V_265 = V_265 ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_61 ;
F_172 (p, n, &cache->all, all) {
F_173 ( & V_31 -> V_271 ) ;
F_92 ( V_31 ) ;
}
F_174 ( & V_47 -> V_272 ) ;
F_174 ( & V_47 -> V_273 ) ;
}
struct V_49 * F_175 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_94 ( L_67 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_159 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_176 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_94 ( L_67 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_159 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_177 ( struct V_1 * V_2 ,
T_8 * V_40 ,
int V_265 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_94 ( L_68 , V_47 , V_40 , V_265 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_159 ( V_40 , V_213 ) && V_50 -> V_274 == V_265 )
return V_50 ;
if ( ! F_159 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_178 ( struct V_1 * V_2 ,
struct V_49 * V_275 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_60 * V_276 = & V_47 -> V_273 ;
struct V_49 * V_31 ;
F_173 ( & V_275 -> V_64 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_274 != V_277 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_275 -> V_26 . V_57 ) )
break;
V_276 = & V_31 -> V_64 ;
}
F_179 ( & V_275 -> V_64 , V_276 ) ;
}
bool F_180 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_278 , bool * V_279 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_275 ;
F_94 ( L_67 , V_47 , & V_26 -> V_40 ) ;
F_181 ( V_2 , & V_26 -> V_40 ) ;
* V_279 = V_26 -> V_58 ;
V_275 = F_175 ( V_2 , & V_26 -> V_40 ) ;
if ( V_275 ) {
if ( V_275 -> V_26 . V_58 )
* V_279 = true ;
if ( V_275 -> V_274 == V_280 &&
V_26 -> V_57 != V_275 -> V_26 . V_57 ) {
V_275 -> V_26 . V_57 = V_26 -> V_57 ;
F_178 ( V_2 , V_275 ) ;
}
goto V_281;
}
V_275 = F_182 ( sizeof( struct V_49 ) , V_282 ) ;
if ( ! V_275 )
return false ;
F_179 ( & V_275 -> V_271 , & V_47 -> V_271 ) ;
if ( V_278 ) {
V_275 -> V_274 = V_283 ;
} else {
V_275 -> V_274 = V_284 ;
F_179 ( & V_275 -> V_64 , & V_47 -> V_272 ) ;
}
V_281:
if ( V_278 && V_275 -> V_274 != V_283 &&
V_275 -> V_274 != V_277 ) {
V_275 -> V_274 = V_283 ;
F_173 ( & V_275 -> V_64 ) ;
}
memcpy ( & V_275 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_275 -> V_59 = V_285 ;
V_47 -> V_59 = V_285 ;
if ( V_275 -> V_274 == V_284 )
return false ;
return true ;
}
static int F_183 ( struct V_1 * V_2 , int V_286 , T_7 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_287 * V_288 = (struct V_287 * ) V_9 ;
struct V_49 * V_50 ;
int V_289 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_289 >= V_286 )
break;
F_151 ( & V_288 -> V_40 , & V_26 -> V_40 ) ;
V_288 -> V_52 = V_26 -> V_52 ;
V_288 -> V_53 = V_26 -> V_53 ;
V_288 -> V_54 = V_26 -> V_54 ;
memcpy ( V_288 -> V_55 , V_26 -> V_55 , 3 ) ;
V_288 -> V_56 = V_26 -> V_56 ;
V_288 ++ ;
V_289 ++ ;
}
F_94 ( L_69 , V_47 , V_289 ) ;
return V_289 ;
}
static void F_184 ( struct V_131 * V_132 , unsigned long V_136 )
{
struct V_290 * V_291 = (struct V_290 * ) V_136 ;
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_292 V_188 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( F_4 ( V_293 , & V_2 -> V_18 ) )
return;
memcpy ( & V_188 . V_294 , & V_291 -> V_294 , 3 ) ;
V_188 . V_295 = V_291 -> V_295 ;
V_188 . V_296 = V_291 -> V_296 ;
F_116 ( V_132 , V_297 , sizeof( V_188 ) , & V_188 ) ;
}
static int F_185 ( void * V_298 )
{
F_186 () ;
return F_110 ( V_130 ) ;
}
int F_187 ( void T_2 * V_299 )
{
T_7 T_2 * V_29 = V_299 ;
struct V_290 V_291 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_300 = 0 , V_301 ;
long V_302 ;
T_7 * V_9 ;
if ( F_8 ( & V_291 , V_29 , sizeof( V_291 ) ) )
return - V_20 ;
V_2 = F_164 ( V_291 . V_303 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_4 ( V_305 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( V_2 -> V_152 != V_153 ) {
V_16 = - V_306 ;
goto V_105;
}
if ( ! F_4 ( V_184 , & V_2 -> V_11 ) ) {
V_16 = - V_306 ;
goto V_105;
}
F_19 ( V_2 ) ;
if ( F_188 ( V_2 ) > V_307 ||
F_189 ( V_2 ) || V_291 . V_18 & V_308 ) {
F_171 ( V_2 ) ;
V_300 = 1 ;
}
F_22 ( V_2 ) ;
V_302 = V_291 . V_295 * F_190 ( 2000 ) ;
if ( V_300 ) {
V_16 = F_113 ( V_2 , F_184 , ( unsigned long ) & V_291 ,
V_302 ) ;
if ( V_16 < 0 )
goto V_105;
if ( F_191 ( & V_2 -> V_18 , V_293 , F_185 ,
V_133 ) )
return - V_134 ;
}
V_301 = ( V_291 . V_296 == 0 ) ? 255 : V_291 . V_296 ;
V_9 = F_192 ( sizeof( struct V_287 ) * V_301 , V_309 ) ;
if ( ! V_9 ) {
V_16 = - V_310 ;
goto V_105;
}
F_19 ( V_2 ) ;
V_291 . V_296 = F_183 ( V_2 , V_301 , V_9 ) ;
F_22 ( V_2 ) ;
F_94 ( L_70 , V_291 . V_296 ) ;
if ( ! F_193 ( V_29 , & V_291 , sizeof( V_291 ) ) ) {
V_29 += sizeof( V_291 ) ;
if ( F_193 ( V_29 , V_9 , sizeof( struct V_287 ) *
V_291 . V_296 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_92 ( V_9 ) ;
V_105:
F_194 ( V_2 ) ;
return V_16 ;
}
static int F_195 ( struct V_1 * V_2 )
{
int V_137 = 0 ;
F_94 ( L_71 , V_2 -> V_107 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_311 , & V_2 -> V_11 ) ) {
V_137 = - V_304 ;
goto V_105;
}
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) ) {
if ( F_4 ( V_312 , & V_2 -> V_11 ) ) {
V_137 = - V_313 ;
goto V_105;
}
if ( ! F_4 ( V_305 , & V_2 -> V_11 ) &&
V_2 -> V_152 == V_153 &&
! F_159 ( & V_2 -> V_40 , V_213 ) &&
! F_159 ( & V_2 -> V_86 , V_213 ) ) {
V_137 = - V_314 ;
goto V_105;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_137 = - V_22 ;
goto V_105;
}
if ( V_2 -> V_315 ( V_2 ) ) {
V_137 = - V_316 ;
goto V_105;
}
F_196 ( & V_2 -> V_317 , 1 ) ;
F_115 ( V_318 , & V_2 -> V_18 ) ;
if ( V_2 -> V_319 && F_4 ( V_221 , & V_2 -> V_11 ) )
V_137 = V_2 -> V_319 ( V_2 ) ;
if ( ! V_137 ) {
if ( F_4 ( V_320 , & V_2 -> V_151 ) )
F_115 ( V_321 , & V_2 -> V_18 ) ;
if ( ! F_4 ( V_321 , & V_2 -> V_18 ) &&
! F_4 ( V_305 , & V_2 -> V_11 ) )
V_137 = F_155 ( V_2 ) ;
}
F_135 ( V_318 , & V_2 -> V_18 ) ;
if ( ! V_137 ) {
F_166 ( V_2 ) ;
F_115 ( V_322 , & V_2 -> V_11 ) ;
F_115 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_323 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) &&
! F_4 ( V_305 , & V_2 -> V_11 ) &&
V_2 -> V_152 == V_153 ) {
F_19 ( V_2 ) ;
F_197 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_198 ( & V_2 -> V_324 ) ;
F_198 ( & V_2 -> V_325 ) ;
F_198 ( & V_2 -> V_326 ) ;
F_199 ( & V_2 -> V_327 ) ;
F_199 ( & V_2 -> V_328 ) ;
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_2 ) ;
if ( V_2 -> V_330 ) {
F_16 ( V_2 -> V_330 ) ;
V_2 -> V_330 = NULL ;
}
V_2 -> V_331 ( V_2 ) ;
V_2 -> V_18 = 0 ;
}
V_105:
F_12 ( V_2 ) ;
return V_137 ;
}
int F_200 ( T_13 V_332 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_164 ( V_332 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_201 ( V_333 , & V_2 -> V_11 ) )
F_202 ( & V_2 -> V_334 ) ;
F_203 ( V_2 -> V_335 ) ;
V_16 = F_195 ( V_2 ) ;
F_194 ( V_2 ) ;
return V_16 ;
}
static int F_204 ( struct V_1 * V_2 )
{
F_94 ( L_71 , V_2 -> V_107 , V_2 ) ;
F_202 ( & V_2 -> V_334 ) ;
F_96 ( V_2 , V_304 ) ;
F_10 ( V_2 ) ;
if ( ! F_201 ( V_17 , & V_2 -> V_18 ) ) {
F_205 ( & V_2 -> V_336 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_198 ( & V_2 -> V_324 ) ;
F_198 ( & V_2 -> V_326 ) ;
if ( V_2 -> V_337 > 0 ) {
F_202 ( & V_2 -> V_338 ) ;
V_2 -> V_337 = 0 ;
F_135 ( V_339 , & V_2 -> V_11 ) ;
F_135 ( V_340 , & V_2 -> V_11 ) ;
}
if ( F_201 ( V_341 , & V_2 -> V_11 ) )
F_202 ( & V_2 -> V_342 ) ;
F_206 ( & V_2 -> V_343 ) ;
if ( F_4 ( V_344 , & V_2 -> V_11 ) )
F_206 ( & V_2 -> V_345 ) ;
F_19 ( V_2 ) ;
F_171 ( V_2 ) ;
F_207 ( V_2 ) ;
F_90 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_346 ) ;
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_2 ) ;
F_199 ( & V_2 -> V_327 ) ;
F_196 ( & V_2 -> V_317 , 1 ) ;
if ( ! F_4 ( V_321 , & V_2 -> V_18 ) &&
! F_4 ( V_333 , & V_2 -> V_11 ) &&
F_4 ( V_150 , & V_2 -> V_151 ) ) {
F_115 ( V_318 , & V_2 -> V_18 ) ;
F_111 ( V_2 , F_114 , 0 , V_24 ) ;
F_135 ( V_318 , & V_2 -> V_18 ) ;
}
F_198 ( & V_2 -> V_325 ) ;
F_199 ( & V_2 -> V_328 ) ;
F_199 ( & V_2 -> V_327 ) ;
F_199 ( & V_2 -> V_347 ) ;
if ( V_2 -> V_330 ) {
F_205 ( & V_2 -> V_336 ) ;
F_16 ( V_2 -> V_330 ) ;
V_2 -> V_330 = NULL ;
}
F_16 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
V_2 -> V_331 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_11 &= ~ V_348 ;
if ( ! F_201 ( V_333 , & V_2 -> V_11 ) ) {
if ( V_2 -> V_152 == V_153 ) {
F_19 ( V_2 ) ;
F_197 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
}
}
V_2 -> V_349 = V_350 ;
memset ( V_2 -> V_189 , 0 , sizeof( V_2 -> V_189 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_151 ( & V_2 -> V_85 , V_213 ) ;
F_12 ( V_2 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
int F_208 ( T_13 V_332 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_164 ( V_332 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_4 ( V_305 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( F_201 ( V_333 , & V_2 -> V_11 ) )
F_202 ( & V_2 -> V_334 ) ;
V_16 = F_204 ( V_2 ) ;
V_105:
F_194 ( V_2 ) ;
return V_16 ;
}
int F_209 ( T_13 V_332 )
{
struct V_1 * V_2 ;
int V_137 = 0 ;
V_2 = F_164 ( V_332 ) ;
if ( ! V_2 )
return - V_304 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_137 = - V_19 ;
goto V_105;
}
if ( F_4 ( V_305 , & V_2 -> V_11 ) ) {
V_137 = - V_73 ;
goto V_105;
}
F_199 ( & V_2 -> V_328 ) ;
F_199 ( & V_2 -> V_327 ) ;
F_19 ( V_2 ) ;
F_171 ( V_2 ) ;
F_207 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_329 )
V_2 -> V_329 ( V_2 ) ;
F_196 ( & V_2 -> V_317 , 1 ) ;
V_2 -> V_351 = 0 ; V_2 -> V_352 = 0 ; V_2 -> V_353 = 0 ;
if ( ! F_4 ( V_321 , & V_2 -> V_18 ) )
V_137 = F_111 ( V_2 , F_114 , 0 , V_220 ) ;
V_105:
F_12 ( V_2 ) ;
F_194 ( V_2 ) ;
return V_137 ;
}
int F_210 ( T_13 V_332 )
{
struct V_1 * V_2 ;
int V_137 = 0 ;
V_2 = F_164 ( V_332 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_4 ( V_305 , & V_2 -> V_11 ) ) {
V_137 = - V_73 ;
goto V_105;
}
memset ( & V_2 -> V_354 , 0 , sizeof( struct V_355 ) ) ;
V_105:
F_194 ( V_2 ) ;
return V_137 ;
}
int F_211 ( unsigned int V_356 , void T_2 * V_299 )
{
struct V_1 * V_2 ;
struct V_357 V_358 ;
int V_16 = 0 ;
if ( F_8 ( & V_358 , V_299 , sizeof( V_358 ) ) )
return - V_20 ;
V_2 = F_164 ( V_358 . V_303 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_4 ( V_305 , & V_2 -> V_11 ) ) {
V_16 = - V_73 ;
goto V_105;
}
if ( V_2 -> V_152 != V_153 ) {
V_16 = - V_306 ;
goto V_105;
}
if ( ! F_4 ( V_184 , & V_2 -> V_11 ) ) {
V_16 = - V_306 ;
goto V_105;
}
switch ( V_356 ) {
case V_359 :
V_16 = F_113 ( V_2 , F_161 , V_358 . V_360 ,
V_220 ) ;
break;
case V_361 :
if ( ! F_212 ( V_2 ) ) {
V_16 = - V_306 ;
break;
}
if ( ! F_4 ( V_362 , & V_2 -> V_18 ) ) {
V_16 = F_113 ( V_2 , F_161 , V_358 . V_360 ,
V_220 ) ;
if ( V_16 )
break;
}
V_16 = F_113 ( V_2 , F_162 , V_358 . V_360 ,
V_220 ) ;
break;
case V_363 :
V_16 = F_113 ( V_2 , F_160 , V_358 . V_360 ,
V_220 ) ;
break;
case V_364 :
V_16 = F_113 ( V_2 , F_163 , V_358 . V_360 ,
V_220 ) ;
break;
case V_365 :
V_2 -> V_366 = ( ( T_13 ) V_358 . V_360 ) &
( V_367 | V_368 ) ;
break;
case V_369 :
V_2 -> V_370 = ( T_13 ) V_358 . V_360 ;
break;
case V_371 :
V_2 -> V_372 = * ( ( T_13 * ) & V_358 . V_360 + 1 ) ;
V_2 -> V_373 = * ( ( T_13 * ) & V_358 . V_360 + 0 ) ;
break;
case V_374 :
V_2 -> V_375 = * ( ( T_13 * ) & V_358 . V_360 + 1 ) ;
V_2 -> V_376 = * ( ( T_13 * ) & V_358 . V_360 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_105:
F_194 ( V_2 ) ;
return V_16 ;
}
int F_213 ( void T_2 * V_299 )
{
struct V_1 * V_2 ;
struct V_377 * V_378 ;
struct V_357 * V_358 ;
int V_61 = 0 , V_379 , V_16 ;
T_13 V_380 ;
if ( F_214 ( V_380 , ( T_13 T_2 * ) V_299 ) )
return - V_20 ;
if ( ! V_380 || V_380 > ( V_381 * 2 ) / sizeof( * V_358 ) )
return - V_21 ;
V_379 = sizeof( * V_378 ) + V_380 * sizeof( * V_358 ) ;
V_378 = F_182 ( V_379 , V_309 ) ;
if ( ! V_378 )
return - V_310 ;
V_358 = V_378 -> V_382 ;
F_165 ( & V_262 ) ;
F_26 (hdev, &hci_dev_list, list) {
if ( F_201 ( V_333 , & V_2 -> V_11 ) )
F_202 ( & V_2 -> V_334 ) ;
if ( ! F_4 ( V_344 , & V_2 -> V_11 ) )
F_115 ( V_383 , & V_2 -> V_11 ) ;
( V_358 + V_61 ) -> V_303 = V_2 -> V_263 ;
( V_358 + V_61 ) -> V_360 = V_2 -> V_18 ;
if ( ++ V_61 >= V_380 )
break;
}
F_167 ( & V_262 ) ;
V_378 -> V_380 = V_61 ;
V_379 = sizeof( * V_378 ) + V_61 * sizeof( * V_358 ) ;
V_16 = F_193 ( V_299 , V_378 , V_379 ) ;
F_92 ( V_378 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_215 ( void T_2 * V_299 )
{
struct V_1 * V_2 ;
struct V_384 V_385 ;
int V_16 = 0 ;
if ( F_8 ( & V_385 , V_299 , sizeof( V_385 ) ) )
return - V_20 ;
V_2 = F_164 ( V_385 . V_303 ) ;
if ( ! V_2 )
return - V_304 ;
if ( F_201 ( V_333 , & V_2 -> V_11 ) )
F_206 ( & V_2 -> V_334 ) ;
if ( ! F_4 ( V_344 , & V_2 -> V_11 ) )
F_115 ( V_383 , & V_2 -> V_11 ) ;
strcpy ( V_385 . V_107 , V_2 -> V_107 ) ;
V_385 . V_40 = V_2 -> V_40 ;
V_385 . type = ( V_2 -> V_386 & 0x0f ) | ( ( V_2 -> V_152 & 0x03 ) << 4 ) ;
V_385 . V_18 = V_2 -> V_18 ;
V_385 . V_370 = V_2 -> V_370 ;
if ( F_123 ( V_2 ) ) {
V_385 . V_372 = V_2 -> V_372 ;
V_385 . V_373 = V_2 -> V_373 ;
V_385 . V_375 = V_2 -> V_375 ;
V_385 . V_376 = V_2 -> V_376 ;
} else {
V_385 . V_372 = V_2 -> V_387 ;
V_385 . V_373 = V_2 -> V_388 ;
V_385 . V_375 = 0 ;
V_385 . V_376 = 0 ;
}
V_385 . V_198 = V_2 -> V_198 ;
V_385 . V_366 = V_2 -> V_366 ;
memcpy ( & V_385 . V_354 , & V_2 -> V_354 , sizeof( V_385 . V_354 ) ) ;
memcpy ( & V_385 . V_34 , & V_2 -> V_34 , sizeof( V_385 . V_34 ) ) ;
if ( F_193 ( V_299 , & V_385 , sizeof( V_385 ) ) )
V_16 = - V_20 ;
F_194 ( V_2 ) ;
return V_16 ;
}
static int F_216 ( void * V_26 , bool V_389 )
{
struct V_1 * V_2 = V_26 ;
F_94 ( L_72 , V_2 , V_2 -> V_107 , V_389 ) ;
if ( F_4 ( V_305 , & V_2 -> V_11 ) )
return - V_73 ;
if ( V_389 ) {
F_115 ( V_312 , & V_2 -> V_11 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_11 ) )
F_204 ( V_2 ) ;
} else {
F_135 ( V_312 , & V_2 -> V_11 ) ;
}
return 0 ;
}
static void F_217 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 , V_392 ) ;
int V_16 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
V_16 = F_195 ( V_2 ) ;
if ( V_16 < 0 ) {
F_219 ( V_2 , V_16 ) ;
return;
}
if ( F_4 ( V_312 , & V_2 -> V_11 ) ||
( V_2 -> V_152 == V_153 &&
! F_159 ( & V_2 -> V_40 , V_213 ) &&
! F_159 ( & V_2 -> V_86 , V_213 ) ) ) {
F_135 ( V_333 , & V_2 -> V_11 ) ;
F_204 ( V_2 ) ;
} else if ( F_4 ( V_333 , & V_2 -> V_11 ) ) {
F_220 ( V_2 -> V_335 , & V_2 -> V_334 ,
V_393 ) ;
}
if ( F_201 ( V_221 , & V_2 -> V_11 ) )
F_221 ( V_2 ) ;
}
static void F_222 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 ,
V_334 . V_391 ) ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_204 ( V_2 ) ;
}
static void F_223 ( struct V_390 * V_391 )
{
struct V_1 * V_2 ;
V_2 = F_218 ( V_391 , struct V_1 , V_338 . V_391 ) ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_224 ( V_2 ) ;
}
void F_225 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_394 ;
F_172 (uuid, tmp, &hdev->uuids, list) {
F_173 ( & V_43 -> V_64 ) ;
F_92 ( V_43 ) ;
}
}
void F_226 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 ;
V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_173 ( V_31 ) ;
F_92 ( V_63 ) ;
}
}
void F_227 ( struct V_1 * V_2 )
{
struct V_89 * V_395 , * V_394 ;
F_172 (k, tmp, &hdev->long_term_keys, list) {
F_173 ( & V_395 -> V_64 ) ;
F_92 ( V_395 ) ;
}
}
void F_228 ( struct V_1 * V_2 )
{
struct V_88 * V_395 , * V_394 ;
F_172 (k, tmp, &hdev->identity_resolving_keys, list) {
F_173 ( & V_395 -> V_64 ) ;
F_92 ( V_395 ) ;
}
}
struct V_62 * F_229 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_62 * V_395 ;
F_26 (k, &hdev->link_keys, list)
if ( F_159 ( V_40 , & V_395 -> V_40 ) == 0 )
return V_395 ;
return NULL ;
}
static bool F_230 ( struct V_1 * V_2 , struct V_396 * V_397 ,
T_5 V_398 , T_5 V_399 )
{
if ( V_398 < 0x03 )
return true ;
if ( V_398 == V_400 )
return false ;
if ( V_398 == V_401 && V_399 == 0xff )
return false ;
if ( ! V_397 )
return true ;
if ( V_397 -> V_402 > 0x01 && V_397 -> V_403 > 0x01 )
return true ;
if ( V_397 -> V_402 == 0x02 || V_397 -> V_402 == 0x03 )
return true ;
if ( V_397 -> V_403 == 0x02 || V_397 -> V_403 == 0x03 )
return true ;
return false ;
}
static bool F_231 ( T_5 type )
{
if ( type == V_404 || type == V_405 )
return true ;
return false ;
}
struct V_89 * F_232 ( struct V_1 * V_2 , T_12 V_93 , T_14 rand ,
bool V_406 )
{
struct V_89 * V_395 ;
F_26 (k, &hdev->long_term_keys, list) {
if ( V_395 -> V_93 != V_93 || V_395 -> rand != rand )
continue;
if ( F_231 ( V_395 -> type ) != V_406 )
continue;
return V_395 ;
}
return NULL ;
}
struct V_89 * F_233 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_82 , bool V_406 )
{
struct V_89 * V_395 ;
F_26 (k, &hdev->long_term_keys, list)
if ( V_82 == V_395 -> V_41 &&
F_159 ( V_40 , & V_395 -> V_40 ) == 0 &&
F_231 ( V_395 -> type ) == V_406 )
return V_395 ;
return NULL ;
}
struct V_88 * F_234 ( struct V_1 * V_2 , T_8 * V_84 )
{
struct V_88 * V_83 ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_159 ( & V_83 -> V_84 , V_84 ) )
return V_83 ;
}
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( F_235 ( V_2 -> V_407 , V_83 -> V_45 , V_84 ) ) {
F_151 ( & V_83 -> V_84 , V_84 ) ;
return V_83 ;
}
}
return NULL ;
}
struct V_88 * F_236 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_82 )
{
struct V_88 * V_83 ;
if ( V_82 == V_408 && ( V_40 -> V_39 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_26 (irk, &hdev->identity_resolving_keys, list) {
if ( V_82 == V_83 -> V_82 &&
F_159 ( V_40 , & V_83 -> V_40 ) == 0 )
return V_83 ;
}
return NULL ;
}
int F_237 ( struct V_1 * V_2 , struct V_396 * V_397 , int V_409 ,
T_8 * V_40 , T_5 * V_45 , T_5 type , T_5 V_66 )
{
struct V_62 * V_63 , * V_410 ;
T_5 V_399 ;
bool V_411 ;
V_410 = F_229 ( V_2 , V_40 ) ;
if ( V_410 ) {
V_399 = V_410 -> type ;
V_63 = V_410 ;
} else {
V_399 = V_397 ? V_397 -> V_398 : 0xff ;
V_63 = F_182 ( sizeof( * V_63 ) , V_309 ) ;
if ( ! V_63 )
return - V_310 ;
F_179 ( & V_63 -> V_64 , & V_2 -> V_412 ) ;
}
F_94 ( L_73 , V_2 -> V_107 , V_40 , type ) ;
if ( type == V_401 &&
( ! V_397 || V_397 -> V_403 == 0xff ) && V_399 == 0xff ) {
type = V_413 ;
if ( V_397 )
V_397 -> V_398 = type ;
}
F_151 ( & V_63 -> V_40 , V_40 ) ;
memcpy ( V_63 -> V_45 , V_45 , V_65 ) ;
V_63 -> V_66 = V_66 ;
if ( type == V_401 )
V_63 -> type = V_399 ;
else
V_63 -> type = type ;
if ( ! V_409 )
return 0 ;
V_411 = F_230 ( V_2 , V_397 , type , V_399 ) ;
F_238 ( V_2 , V_63 , V_411 ) ;
if ( V_397 )
V_397 -> V_414 = ! V_411 ;
return 0 ;
}
struct V_89 * F_239 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_82 , T_5 type , T_5 V_91 ,
T_5 V_415 [ 16 ] , T_5 V_92 , T_12 V_93 , T_14 rand )
{
struct V_89 * V_63 , * V_410 ;
bool V_406 = F_231 ( type ) ;
V_410 = F_233 ( V_2 , V_40 , V_82 , V_406 ) ;
if ( V_410 )
V_63 = V_410 ;
else {
V_63 = F_182 ( sizeof( * V_63 ) , V_309 ) ;
if ( ! V_63 )
return NULL ;
F_179 ( & V_63 -> V_64 , & V_2 -> V_416 ) ;
}
F_151 ( & V_63 -> V_40 , V_40 ) ;
V_63 -> V_41 = V_82 ;
memcpy ( V_63 -> V_45 , V_415 , sizeof( V_63 -> V_45 ) ) ;
V_63 -> V_91 = V_91 ;
V_63 -> V_93 = V_93 ;
V_63 -> rand = rand ;
V_63 -> V_92 = V_92 ;
V_63 -> type = type ;
return V_63 ;
}
struct V_88 * F_240 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 V_82 , T_5 V_45 [ 16 ] , T_8 * V_84 )
{
struct V_88 * V_83 ;
V_83 = F_236 ( V_2 , V_40 , V_82 ) ;
if ( ! V_83 ) {
V_83 = F_182 ( sizeof( * V_83 ) , V_309 ) ;
if ( ! V_83 )
return NULL ;
F_151 ( & V_83 -> V_40 , V_40 ) ;
V_83 -> V_82 = V_82 ;
F_179 ( & V_83 -> V_64 , & V_2 -> V_417 ) ;
}
memcpy ( V_83 -> V_45 , V_45 , 16 ) ;
F_151 ( & V_83 -> V_84 , V_84 ) ;
return V_83 ;
}
int F_241 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_62 * V_63 ;
V_63 = F_229 ( V_2 , V_40 ) ;
if ( ! V_63 )
return - V_418 ;
F_94 ( L_74 , V_2 -> V_107 , V_40 ) ;
F_173 ( & V_63 -> V_64 ) ;
F_92 ( V_63 ) ;
return 0 ;
}
int F_242 ( struct V_1 * V_2 , T_8 * V_40 , T_5 V_41 )
{
struct V_89 * V_395 , * V_394 ;
int V_419 = 0 ;
F_172 (k, tmp, &hdev->long_term_keys, list) {
if ( F_159 ( V_40 , & V_395 -> V_40 ) || V_395 -> V_41 != V_41 )
continue;
F_94 ( L_74 , V_2 -> V_107 , V_40 ) ;
F_173 ( & V_395 -> V_64 ) ;
F_92 ( V_395 ) ;
V_419 ++ ;
}
return V_419 ? 0 : - V_418 ;
}
void F_243 ( struct V_1 * V_2 , T_8 * V_40 , T_5 V_82 )
{
struct V_88 * V_395 , * V_394 ;
F_172 (k, tmp, &hdev->identity_resolving_keys, list) {
if ( F_159 ( V_40 , & V_395 -> V_40 ) || V_395 -> V_82 != V_82 )
continue;
F_94 ( L_74 , V_2 -> V_107 , V_40 ) ;
F_173 ( & V_395 -> V_64 ) ;
F_92 ( V_395 ) ;
}
}
static void F_244 ( unsigned long V_299 )
{
struct V_1 * V_2 = ( void * ) V_299 ;
if ( V_2 -> V_330 ) {
struct V_420 * V_421 = ( void * ) V_2 -> V_330 -> V_26 ;
T_9 V_114 = F_31 ( V_421 -> V_114 ) ;
F_99 ( L_75 , V_2 -> V_107 , V_114 ) ;
} else {
F_99 ( L_76 , V_2 -> V_107 ) ;
}
F_196 ( & V_2 -> V_317 , 1 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_325 ) ;
}
struct V_423 * F_246 ( struct V_1 * V_2 ,
T_8 * V_40 )
{
struct V_423 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list)
if ( F_159 ( V_40 , & V_26 -> V_40 ) == 0 )
return V_26 ;
return NULL ;
}
int F_181 ( struct V_1 * V_2 , T_8 * V_40 )
{
struct V_423 * V_26 ;
V_26 = F_246 ( V_2 , V_40 ) ;
if ( ! V_26 )
return - V_418 ;
F_94 ( L_74 , V_2 -> V_107 , V_40 ) ;
F_173 ( & V_26 -> V_64 ) ;
F_92 ( V_26 ) ;
return 0 ;
}
void F_247 ( struct V_1 * V_2 )
{
struct V_423 * V_26 , * V_61 ;
F_172 (data, n, &hdev->remote_oob_data, list) {
F_173 ( & V_26 -> V_64 ) ;
F_92 ( V_26 ) ;
}
}
int F_248 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_424 , T_5 * V_425 )
{
struct V_423 * V_26 ;
V_26 = F_246 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_192 ( sizeof( * V_26 ) , V_309 ) ;
if ( ! V_26 )
return - V_310 ;
F_151 ( & V_26 -> V_40 , V_40 ) ;
F_179 ( & V_26 -> V_64 , & V_2 -> V_426 ) ;
}
memcpy ( V_26 -> V_427 , V_424 , sizeof( V_26 -> V_427 ) ) ;
memcpy ( V_26 -> V_428 , V_425 , sizeof( V_26 -> V_428 ) ) ;
memset ( V_26 -> V_429 , 0 , sizeof( V_26 -> V_429 ) ) ;
memset ( V_26 -> V_430 , 0 , sizeof( V_26 -> V_430 ) ) ;
F_94 ( L_77 , V_2 -> V_107 , V_40 ) ;
return 0 ;
}
int F_249 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_427 , T_5 * V_428 ,
T_5 * V_429 , T_5 * V_430 )
{
struct V_423 * V_26 ;
V_26 = F_246 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_192 ( sizeof( * V_26 ) , V_309 ) ;
if ( ! V_26 )
return - V_310 ;
F_151 ( & V_26 -> V_40 , V_40 ) ;
F_179 ( & V_26 -> V_64 , & V_2 -> V_426 ) ;
}
memcpy ( V_26 -> V_427 , V_427 , sizeof( V_26 -> V_427 ) ) ;
memcpy ( V_26 -> V_428 , V_428 , sizeof( V_26 -> V_428 ) ) ;
memcpy ( V_26 -> V_429 , V_429 , sizeof( V_26 -> V_429 ) ) ;
memcpy ( V_26 -> V_430 , V_430 , sizeof( V_26 -> V_430 ) ) ;
F_94 ( L_77 , V_2 -> V_107 , V_40 ) ;
return 0 ;
}
struct V_38 * F_250 ( struct V_1 * V_2 ,
T_8 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->blacklist, list) {
if ( ! F_159 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
static void F_251 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->blacklist) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_173 ( V_31 ) ;
F_92 ( V_39 ) ;
}
}
int F_252 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_431 ;
if ( ! F_159 ( V_40 , V_213 ) )
return - V_432 ;
if ( F_250 ( V_2 , V_40 , type ) )
return - V_433 ;
V_431 = F_182 ( sizeof( struct V_38 ) , V_309 ) ;
if ( ! V_431 )
return - V_310 ;
F_151 ( & V_431 -> V_40 , V_40 ) ;
V_431 -> V_41 = type ;
F_179 ( & V_431 -> V_64 , & V_2 -> V_434 ) ;
return F_253 ( V_2 , V_40 , type ) ;
}
int F_254 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_431 ;
if ( ! F_159 ( V_40 , V_213 ) ) {
F_251 ( V_2 ) ;
return 0 ;
}
V_431 = F_250 ( V_2 , V_40 , type ) ;
if ( ! V_431 )
return - V_418 ;
F_173 ( & V_431 -> V_64 ) ;
F_92 ( V_431 ) ;
return F_255 ( V_2 , V_40 , type ) ;
}
struct V_38 * F_256 ( struct V_1 * V_2 ,
T_8 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->le_white_list, list) {
if ( ! F_159 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
void F_257 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->le_white_list) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_173 ( V_31 ) ;
F_92 ( V_39 ) ;
}
}
int F_258 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_431 ;
if ( ! F_159 ( V_40 , V_213 ) )
return - V_432 ;
V_431 = F_182 ( sizeof( struct V_38 ) , V_309 ) ;
if ( ! V_431 )
return - V_310 ;
F_151 ( & V_431 -> V_40 , V_40 ) ;
V_431 -> V_41 = type ;
F_179 ( & V_431 -> V_64 , & V_2 -> V_435 ) ;
return 0 ;
}
int F_259 ( struct V_1 * V_2 , T_8 * V_40 , T_5 type )
{
struct V_38 * V_431 ;
if ( ! F_159 ( V_40 , V_213 ) )
return - V_432 ;
V_431 = F_256 ( V_2 , V_40 , type ) ;
if ( ! V_431 )
return - V_418 ;
F_173 ( & V_431 -> V_64 ) ;
F_92 ( V_431 ) ;
return 0 ;
}
struct V_102 * F_260 ( struct V_1 * V_2 ,
T_8 * V_81 , T_5 V_82 )
{
struct V_102 * V_436 ;
F_26 (params, &hdev->le_conn_params, list) {
if ( F_159 ( & V_436 -> V_81 , V_81 ) == 0 &&
V_436 -> V_82 == V_82 ) {
return V_436 ;
}
}
return NULL ;
}
static bool F_261 ( struct V_1 * V_2 , T_8 * V_81 , T_5 type )
{
struct V_396 * V_397 ;
V_397 = F_262 ( V_2 , V_437 , V_81 ) ;
if ( ! V_397 )
return false ;
if ( V_397 -> V_438 != type )
return false ;
if ( V_397 -> V_265 != V_439 )
return false ;
return true ;
}
static bool F_263 ( T_8 * V_81 , T_5 V_82 )
{
if ( V_82 == V_440 )
return true ;
if ( ( V_81 -> V_39 [ 5 ] & 0xc0 ) == 0xc0 )
return true ;
return false ;
}
int F_87 ( struct V_1 * V_2 , T_8 * V_81 , T_5 V_82 ,
T_5 V_103 , T_9 V_441 ,
T_9 V_442 )
{
struct V_102 * V_436 ;
if ( ! F_263 ( V_81 , V_82 ) )
return - V_21 ;
V_436 = F_260 ( V_2 , V_81 , V_82 ) ;
if ( V_436 )
goto V_281;
V_436 = F_182 ( sizeof( * V_436 ) , V_309 ) ;
if ( ! V_436 ) {
F_99 ( L_78 ) ;
return - V_310 ;
}
F_151 ( & V_436 -> V_81 , V_81 ) ;
V_436 -> V_82 = V_82 ;
F_179 ( & V_436 -> V_64 , & V_2 -> V_443 ) ;
V_281:
V_436 -> V_441 = V_441 ;
V_436 -> V_442 = V_442 ;
V_436 -> V_103 = V_103 ;
switch ( V_103 ) {
case V_444 :
case V_445 :
F_264 ( V_2 , V_81 , V_82 ) ;
break;
case V_446 :
if ( ! F_261 ( V_2 , V_81 , V_82 ) )
F_265 ( V_2 , V_81 , V_82 ) ;
break;
}
F_94 ( L_79
L_80 , V_81 , V_82 , V_103 ,
V_441 , V_442 ) ;
return 0 ;
}
void F_88 ( struct V_1 * V_2 , T_8 * V_81 , T_5 V_82 )
{
struct V_102 * V_436 ;
V_436 = F_260 ( V_2 , V_81 , V_82 ) ;
if ( ! V_436 )
return;
F_264 ( V_2 , V_81 , V_82 ) ;
F_173 ( & V_436 -> V_64 ) ;
F_92 ( V_436 ) ;
F_94 ( L_81 , V_81 , V_82 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_102 * V_436 , * V_394 ;
F_172 (params, tmp, &hdev->le_conn_params, list) {
F_173 ( & V_436 -> V_64 ) ;
F_92 ( V_436 ) ;
}
F_94 ( L_82 ) ;
}
struct V_38 * F_266 ( struct V_1 * V_2 ,
T_8 * V_81 , T_5 V_82 )
{
struct V_38 * V_431 ;
F_26 (entry, &hdev->pend_le_conns, list) {
if ( F_159 ( & V_431 -> V_40 , V_81 ) == 0 &&
V_431 -> V_41 == V_82 )
return V_431 ;
}
return NULL ;
}
void F_265 ( struct V_1 * V_2 , T_8 * V_81 , T_5 V_82 )
{
struct V_38 * V_431 ;
V_431 = F_266 ( V_2 , V_81 , V_82 ) ;
if ( V_431 )
goto V_105;
V_431 = F_182 ( sizeof( * V_431 ) , V_309 ) ;
if ( ! V_431 ) {
F_99 ( L_78 ) ;
return;
}
F_151 ( & V_431 -> V_40 , V_81 ) ;
V_431 -> V_41 = V_82 ;
F_179 ( & V_431 -> V_64 , & V_2 -> V_447 ) ;
F_94 ( L_81 , V_81 , V_82 ) ;
V_105:
F_91 ( V_2 ) ;
}
void F_264 ( struct V_1 * V_2 , T_8 * V_81 , T_5 V_82 )
{
struct V_38 * V_431 ;
V_431 = F_266 ( V_2 , V_81 , V_82 ) ;
if ( ! V_431 )
goto V_105;
F_173 ( & V_431 -> V_64 ) ;
F_92 ( V_431 ) ;
F_94 ( L_81 , V_81 , V_82 ) ;
V_105:
F_91 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_38 * V_431 , * V_394 ;
F_172 (entry, tmp, &hdev->pend_le_conns, list) {
F_173 ( & V_431 -> V_64 ) ;
F_92 ( V_431 ) ;
}
F_94 ( L_83 ) ;
}
static void F_267 ( struct V_1 * V_2 , T_5 V_448 )
{
if ( V_448 ) {
F_99 ( L_84 , V_448 ) ;
F_19 ( V_2 ) ;
F_169 ( V_2 , V_268 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_268 ( struct V_1 * V_2 , T_5 V_448 )
{
T_5 V_294 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_131 V_132 ;
struct V_292 V_188 ;
int V_16 ;
if ( V_448 ) {
F_99 ( L_85 , V_448 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_449 :
F_19 ( V_2 ) ;
F_169 ( V_2 , V_268 ) ;
F_22 ( V_2 ) ;
break;
case V_450 :
F_103 ( & V_132 , V_2 ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
memcpy ( & V_188 . V_294 , V_294 , sizeof( V_188 . V_294 ) ) ;
V_188 . V_295 = V_451 ;
F_116 ( & V_132 , V_297 , sizeof( V_188 ) , & V_188 ) ;
F_19 ( V_2 ) ;
F_171 ( V_2 ) ;
V_16 = F_105 ( & V_132 , F_267 ) ;
if ( V_16 ) {
F_99 ( L_86 , V_16 ) ;
F_169 ( V_2 , V_268 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_269 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 ,
V_343 . V_391 ) ;
struct V_131 V_132 ;
int V_16 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_103 ( & V_132 , V_2 ) ;
F_270 ( & V_132 ) ;
V_16 = F_105 ( & V_132 , F_268 ) ;
if ( V_16 )
F_99 ( L_87 , V_16 ) ;
}
static void F_271 ( struct V_131 * V_132 , T_8 * V_84 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
if ( F_4 ( V_452 , & V_2 -> V_11 ) ||
F_272 ( V_2 , V_437 , V_453 ) ) {
F_94 ( L_88 ) ;
return;
}
F_116 ( V_132 , V_454 , 6 , V_84 ) ;
}
int F_273 ( struct V_131 * V_132 , bool V_455 ,
T_5 * V_456 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
int V_16 ;
if ( F_4 ( V_457 , & V_2 -> V_11 ) ) {
int V_458 ;
* V_456 = V_408 ;
if ( ! F_201 ( V_322 , & V_2 -> V_11 ) &&
! F_159 ( & V_2 -> V_85 , & V_2 -> V_84 ) )
return 0 ;
V_16 = F_274 ( V_2 -> V_407 , V_2 -> V_83 , & V_2 -> V_84 ) ;
if ( V_16 < 0 ) {
F_99 ( L_89 , V_2 -> V_107 ) ;
return V_16 ;
}
F_271 ( V_132 , & V_2 -> V_84 ) ;
V_458 = F_190 ( V_2 -> V_76 * 1000 ) ;
F_220 ( V_2 -> V_422 , & V_2 -> V_345 , V_458 ) ;
return 0 ;
}
if ( V_455 ) {
T_8 V_459 ;
F_275 ( & V_459 , 6 ) ;
V_459 . V_39 [ 5 ] &= 0x3f ;
* V_456 = V_408 ;
F_271 ( V_132 , & V_459 ) ;
return 0 ;
}
if ( F_4 ( V_87 , & V_2 -> V_11 ) ||
! F_159 ( & V_2 -> V_40 , V_213 ) ) {
* V_456 = V_408 ;
if ( F_159 ( & V_2 -> V_86 , & V_2 -> V_85 ) )
F_116 ( V_132 , V_454 , 6 ,
& V_2 -> V_86 ) ;
return 0 ;
}
* V_456 = V_440 ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , T_8 * V_40 ,
T_5 * V_41 )
{
if ( F_4 ( V_87 , & V_2 -> V_11 ) ||
! F_159 ( & V_2 -> V_40 , V_213 ) ) {
F_151 ( V_40 , & V_2 -> V_86 ) ;
* V_41 = V_408 ;
} else {
F_151 ( V_40 , & V_2 -> V_40 ) ;
* V_41 = V_440 ;
}
}
struct V_1 * F_276 ( void )
{
struct V_1 * V_2 ;
V_2 = F_182 ( sizeof( struct V_1 ) , V_309 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_370 = ( V_460 | V_461 | V_462 ) ;
V_2 -> V_463 = ( V_464 ) ;
V_2 -> V_366 = ( V_368 ) ;
V_2 -> V_465 = 0x01 ;
V_2 -> V_466 = 0x03 ;
V_2 -> V_467 = V_468 ;
V_2 -> V_469 = V_468 ;
V_2 -> V_77 = 800 ;
V_2 -> V_78 = 80 ;
V_2 -> V_96 = 0x07 ;
V_2 -> V_470 = 0x0060 ;
V_2 -> V_471 = 0x0030 ;
V_2 -> V_95 = 0x0028 ;
V_2 -> V_94 = 0x0038 ;
V_2 -> V_76 = V_472 ;
V_2 -> V_254 = V_473 ;
V_2 -> V_80 = V_474 ;
V_2 -> V_79 = V_475 ;
F_277 ( & V_2 -> V_476 ) ;
F_277 ( & V_2 -> V_477 ) ;
F_174 ( & V_2 -> V_478 ) ;
F_174 ( & V_2 -> V_434 ) ;
F_174 ( & V_2 -> V_479 ) ;
F_174 ( & V_2 -> V_412 ) ;
F_174 ( & V_2 -> V_416 ) ;
F_174 ( & V_2 -> V_417 ) ;
F_174 ( & V_2 -> V_426 ) ;
F_174 ( & V_2 -> V_435 ) ;
F_174 ( & V_2 -> V_443 ) ;
F_174 ( & V_2 -> V_447 ) ;
F_174 ( & V_2 -> V_480 . V_64 ) ;
F_278 ( & V_2 -> V_326 , V_481 ) ;
F_278 ( & V_2 -> V_325 , V_482 ) ;
F_278 ( & V_2 -> V_324 , V_483 ) ;
F_278 ( & V_2 -> V_392 , F_217 ) ;
F_279 ( & V_2 -> V_334 , F_222 ) ;
F_279 ( & V_2 -> V_338 , F_223 ) ;
F_279 ( & V_2 -> V_343 , F_269 ) ;
F_280 ( & V_2 -> V_328 ) ;
F_280 ( & V_2 -> V_327 ) ;
F_280 ( & V_2 -> V_347 ) ;
F_281 ( & V_2 -> V_112 ) ;
F_282 ( & V_2 -> V_336 , F_244 , ( unsigned long ) V_2 ) ;
F_283 ( V_2 ) ;
F_284 ( V_2 ) ;
return V_2 ;
}
void F_285 ( struct V_1 * V_2 )
{
F_286 ( & V_2 -> V_332 ) ;
}
int F_287 ( struct V_1 * V_2 )
{
int V_263 , error ;
if ( ! V_2 -> V_315 || ! V_2 -> V_331 )
return - V_21 ;
switch ( V_2 -> V_152 ) {
case V_153 :
V_263 = F_288 ( & V_484 , 0 , 0 , V_309 ) ;
break;
case V_154 :
V_263 = F_288 ( & V_484 , 1 , 0 , V_309 ) ;
break;
default:
return - V_21 ;
}
if ( V_263 < 0 )
return V_263 ;
sprintf ( V_2 -> V_107 , L_90 , V_263 ) ;
V_2 -> V_263 = V_263 ;
F_94 ( L_91 , V_2 , V_2 -> V_107 , V_2 -> V_386 ) ;
V_2 -> V_422 = F_289 ( L_24 , V_485 | V_486 |
V_487 , 1 , V_2 -> V_107 ) ;
if ( ! V_2 -> V_422 ) {
error = - V_310 ;
goto V_16;
}
V_2 -> V_335 = F_289 ( L_24 , V_485 | V_486 |
V_487 , 1 , V_2 -> V_107 ) ;
if ( ! V_2 -> V_335 ) {
F_290 ( V_2 -> V_422 ) ;
error = - V_310 ;
goto V_16;
}
if ( ! F_291 ( V_488 ) )
V_2 -> V_222 = F_292 ( V_2 -> V_107 , V_488 ) ;
F_293 ( & V_2 -> V_332 , L_24 , V_2 -> V_107 ) ;
V_2 -> V_407 = F_294 ( L_92 , 0 ,
V_489 ) ;
if ( F_13 ( V_2 -> V_407 ) ) {
F_99 ( L_93 ) ;
error = F_14 ( V_2 -> V_407 ) ;
V_2 -> V_407 = NULL ;
goto V_490;
}
error = F_295 ( & V_2 -> V_332 ) ;
if ( error < 0 )
goto V_491;
V_2 -> V_492 = F_296 ( V_2 -> V_107 , & V_2 -> V_332 ,
V_493 , & V_494 ,
V_2 ) ;
if ( V_2 -> V_492 ) {
if ( F_297 ( V_2 -> V_492 ) < 0 ) {
F_298 ( V_2 -> V_492 ) ;
V_2 -> V_492 = NULL ;
}
}
if ( V_2 -> V_492 && F_299 ( V_2 -> V_492 ) )
F_115 ( V_312 , & V_2 -> V_11 ) ;
F_115 ( V_221 , & V_2 -> V_11 ) ;
F_115 ( V_333 , & V_2 -> V_11 ) ;
if ( V_2 -> V_152 == V_153 ) {
F_115 ( V_184 , & V_2 -> V_11 ) ;
}
F_300 ( & V_262 ) ;
F_179 ( & V_2 -> V_64 , & V_495 ) ;
F_301 ( & V_262 ) ;
F_1 ( V_2 , V_496 ) ;
F_166 ( V_2 ) ;
F_245 ( V_2 -> V_335 , & V_2 -> V_392 ) ;
return V_263 ;
V_491:
F_302 ( V_2 -> V_407 ) ;
V_490:
F_290 ( V_2 -> V_422 ) ;
F_290 ( V_2 -> V_335 ) ;
V_16:
F_303 ( & V_484 , V_2 -> V_263 ) ;
return error ;
}
void F_304 ( struct V_1 * V_2 )
{
int V_44 , V_263 ;
F_94 ( L_91 , V_2 , V_2 -> V_107 , V_2 -> V_386 ) ;
F_115 ( V_311 , & V_2 -> V_11 ) ;
V_263 = V_2 -> V_263 ;
F_300 ( & V_262 ) ;
F_173 ( & V_2 -> V_64 ) ;
F_301 ( & V_262 ) ;
F_204 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_497 ; V_44 ++ )
F_16 ( V_2 -> V_498 [ V_44 ] ) ;
F_305 ( & V_2 -> V_392 ) ;
if ( ! F_4 ( V_318 , & V_2 -> V_18 ) &&
! F_4 ( V_221 , & V_2 -> V_11 ) ) {
F_19 ( V_2 ) ;
F_306 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_307 ( ! F_308 ( & V_2 -> V_478 ) ) ;
F_1 ( V_2 , V_499 ) ;
if ( V_2 -> V_492 ) {
F_309 ( V_2 -> V_492 ) ;
F_298 ( V_2 -> V_492 ) ;
}
if ( V_2 -> V_407 )
F_302 ( V_2 -> V_407 ) ;
F_310 ( & V_2 -> V_332 ) ;
F_311 ( V_2 -> V_222 ) ;
F_290 ( V_2 -> V_422 ) ;
F_290 ( V_2 -> V_335 ) ;
F_19 ( V_2 ) ;
F_251 ( V_2 ) ;
F_225 ( V_2 ) ;
F_226 ( V_2 ) ;
F_227 ( V_2 ) ;
F_228 ( V_2 ) ;
F_247 ( V_2 ) ;
F_257 ( V_2 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
F_22 ( V_2 ) ;
F_194 ( V_2 ) ;
F_303 ( & V_484 , V_263 ) ;
}
int F_312 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_500 ) ;
return 0 ;
}
int F_313 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_501 ) ;
return 0 ;
}
int F_314 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_318 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_502 ;
}
F_315 ( V_13 ) -> V_503 = 1 ;
F_316 ( V_13 ) ;
F_317 ( & V_2 -> V_328 , V_13 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_326 ) ;
return 0 ;
}
static int F_318 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_7 V_260 )
{
int V_121 = 0 ;
int V_504 = 0 ;
int V_505 = V_6 ;
struct V_12 * V_13 ;
struct V_506 * V_507 ;
if ( ( type < V_508 || type > V_509 ) ||
V_260 >= V_497 )
return - V_510 ;
V_13 = V_2 -> V_498 [ V_260 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_508 :
V_121 = V_511 ;
V_504 = V_512 ;
break;
case V_509 :
V_121 = V_513 ;
V_504 = V_123 ;
break;
case V_514 :
V_121 = V_515 ;
V_504 = V_516 ;
break;
}
V_13 = F_319 ( V_121 , V_282 ) ;
if ( ! V_13 )
return - V_310 ;
V_507 = ( void * ) V_13 -> V_517 ;
V_507 -> V_518 = V_504 ;
V_507 -> V_370 = type ;
V_2 -> V_498 [ V_260 ] = V_13 ;
}
while ( V_6 ) {
V_507 = ( void * ) V_13 -> V_517 ;
V_121 = F_320 ( V_519 , V_507 -> V_518 , V_6 ) ;
memcpy ( F_321 ( V_13 , V_121 ) , V_26 , V_121 ) ;
V_6 -= V_121 ;
V_26 += V_121 ;
V_507 -> V_518 -= V_121 ;
V_505 = V_6 ;
switch ( type ) {
case V_509 :
if ( V_13 -> V_121 == V_123 ) {
struct V_117 * V_520 = V_117 ( V_13 ) ;
V_507 -> V_518 = V_520 -> V_126 ;
if ( F_322 ( V_13 ) < V_507 -> V_518 ) {
F_16 ( V_13 ) ;
V_2 -> V_498 [ V_260 ] = NULL ;
return - V_310 ;
}
}
break;
case V_508 :
if ( V_13 -> V_121 == V_512 ) {
struct V_521 * V_520 = V_521 ( V_13 ) ;
V_507 -> V_518 = F_31 ( V_520 -> V_522 ) ;
if ( F_322 ( V_13 ) < V_507 -> V_518 ) {
F_16 ( V_13 ) ;
V_2 -> V_498 [ V_260 ] = NULL ;
return - V_310 ;
}
}
break;
case V_514 :
if ( V_13 -> V_121 == V_516 ) {
struct V_523 * V_520 = V_523 ( V_13 ) ;
V_507 -> V_518 = V_520 -> V_522 ;
if ( F_322 ( V_13 ) < V_507 -> V_518 ) {
F_16 ( V_13 ) ;
V_2 -> V_498 [ V_260 ] = NULL ;
return - V_310 ;
}
}
break;
}
if ( V_507 -> V_518 == 0 ) {
F_315 ( V_13 ) -> V_370 = type ;
F_314 ( V_2 , V_13 ) ;
V_2 -> V_498 [ V_260 ] = NULL ;
return V_505 ;
}
}
return V_505 ;
}
int F_323 ( struct V_1 * V_2 , int type , void * V_26 , int V_6 )
{
int V_524 = 0 ;
if ( type < V_508 || type > V_509 )
return - V_510 ;
while ( V_6 ) {
V_524 = F_318 ( V_2 , type , V_26 , V_6 , type - 1 ) ;
if ( V_524 < 0 )
return V_524 ;
V_26 += ( V_6 - V_524 ) ;
V_6 = V_524 ;
}
return V_524 ;
}
int F_324 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_524 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_498 [ V_525 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_526 ;
V_526 = V_26 ;
type = V_526 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_315 ( V_13 ) -> V_370 ;
V_524 = F_318 ( V_2 , type , V_26 , V_6 ,
V_525 ) ;
if ( V_524 < 0 )
return V_524 ;
V_26 += ( V_6 - V_524 ) ;
V_6 = V_524 ;
}
return V_524 ;
}
int F_325 ( struct V_527 * V_517 )
{
F_94 ( L_94 , V_517 , V_517 -> V_107 ) ;
F_300 ( & V_528 ) ;
F_179 ( & V_517 -> V_64 , & V_529 ) ;
F_301 ( & V_528 ) ;
return 0 ;
}
int F_326 ( struct V_527 * V_517 )
{
F_94 ( L_94 , V_517 , V_517 -> V_107 ) ;
F_300 ( & V_528 ) ;
F_173 ( & V_517 -> V_64 ) ;
F_301 ( & V_528 ) ;
return 0 ;
}
static void F_327 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_94 ( L_95 , V_2 -> V_107 , F_315 ( V_13 ) -> V_370 , V_13 -> V_121 ) ;
F_316 ( V_13 ) ;
F_328 ( V_2 , V_13 ) ;
if ( F_329 ( & V_2 -> V_530 ) ) {
F_330 ( V_2 , V_13 ) ;
}
F_331 ( V_13 ) ;
if ( V_2 -> V_531 ( V_2 , V_13 ) < 0 )
F_99 ( L_96 , V_2 -> V_107 ) ;
}
void F_103 ( struct V_131 * V_132 , struct V_1 * V_2 )
{
F_280 ( & V_132 -> V_327 ) ;
V_132 -> V_2 = V_2 ;
V_132 -> V_16 = 0 ;
}
int F_105 ( struct V_131 * V_132 , T_15 V_532 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_94 ( L_97 , F_332 ( & V_132 -> V_327 ) ) ;
if ( V_132 -> V_16 ) {
F_199 ( & V_132 -> V_327 ) ;
return V_132 -> V_16 ;
}
if ( F_333 ( & V_132 -> V_327 ) )
return - V_120 ;
V_13 = F_334 ( & V_132 -> V_327 ) ;
F_315 ( V_13 ) -> V_132 . V_532 = V_532 ;
F_335 ( & V_2 -> V_327 . V_476 , V_18 ) ;
F_336 ( & V_132 -> V_327 , & V_2 -> V_327 ) ;
F_337 ( & V_2 -> V_327 . V_476 , V_18 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_325 ) ;
return 0 ;
}
static struct V_12 * F_338 ( struct V_1 * V_2 , T_9 V_114 ,
T_10 V_126 , const void * V_127 )
{
int V_121 = V_533 + V_126 ;
struct V_420 * V_118 ;
struct V_12 * V_13 ;
V_13 = F_319 ( V_121 , V_282 ) ;
if ( ! V_13 )
return NULL ;
V_118 = (struct V_420 * ) F_321 ( V_13 , V_533 ) ;
V_118 -> V_114 = F_121 ( V_114 ) ;
V_118 -> V_126 = V_126 ;
if ( V_126 )
memcpy ( F_321 ( V_13 , V_126 ) , V_127 , V_126 ) ;
F_94 ( L_98 , V_13 -> V_121 ) ;
F_315 ( V_13 ) -> V_370 = V_534 ;
return V_13 ;
}
int F_339 ( struct V_1 * V_2 , T_13 V_114 , T_11 V_126 ,
const void * V_127 )
{
struct V_12 * V_13 ;
F_94 ( L_99 , V_2 -> V_107 , V_114 , V_126 ) ;
V_13 = F_338 ( V_2 , V_114 , V_126 , V_127 ) ;
if ( ! V_13 ) {
F_99 ( L_100 , V_2 -> V_107 ) ;
return - V_310 ;
}
F_315 ( V_13 ) -> V_132 . V_535 = true ;
F_317 ( & V_2 -> V_327 , V_13 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_325 ) ;
return 0 ;
}
void F_104 ( struct V_131 * V_132 , T_9 V_114 , T_10 V_126 ,
const void * V_127 , T_5 V_3 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_12 * V_13 ;
F_94 ( L_99 , V_2 -> V_107 , V_114 , V_126 ) ;
if ( V_132 -> V_16 )
return;
V_13 = F_338 ( V_2 , V_114 , V_126 , V_127 ) ;
if ( ! V_13 ) {
F_99 ( L_101 ,
V_2 -> V_107 , V_114 ) ;
V_132 -> V_16 = - V_310 ;
return;
}
if ( F_333 ( & V_132 -> V_327 ) )
F_315 ( V_13 ) -> V_132 . V_535 = true ;
F_315 ( V_13 ) -> V_132 . V_3 = V_3 ;
F_317 ( & V_132 -> V_327 , V_13 ) ;
}
void F_116 ( struct V_131 * V_132 , T_9 V_114 , T_10 V_126 ,
const void * V_127 )
{
F_104 ( V_132 , V_114 , V_126 , V_127 , 0 ) ;
}
void * F_340 ( struct V_1 * V_2 , T_13 V_114 )
{
struct V_420 * V_118 ;
if ( ! V_2 -> V_330 )
return NULL ;
V_118 = ( void * ) V_2 -> V_330 -> V_26 ;
if ( V_118 -> V_114 != F_121 ( V_114 ) )
return NULL ;
F_94 ( L_102 , V_2 -> V_107 , V_114 ) ;
return V_2 -> V_330 -> V_26 + V_533 ;
}
static void F_341 ( struct V_12 * V_13 , T_13 V_536 , T_13 V_18 )
{
struct V_521 * V_118 ;
int V_121 = V_13 -> V_121 ;
F_342 ( V_13 , V_512 ) ;
F_343 ( V_13 ) ;
V_118 = (struct V_521 * ) F_344 ( V_13 ) ;
V_118 -> V_536 = F_121 ( F_345 ( V_536 , V_18 ) ) ;
V_118 -> V_522 = F_121 ( V_121 ) ;
}
static void F_346 ( struct V_537 * V_538 , struct V_539 * V_540 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_396 * V_397 = V_538 -> V_397 ;
struct V_1 * V_2 = V_397 -> V_2 ;
struct V_12 * V_64 ;
V_13 -> V_121 = F_347 ( V_13 ) ;
V_13 -> V_541 = 0 ;
F_315 ( V_13 ) -> V_370 = V_508 ;
switch ( V_2 -> V_152 ) {
case V_153 :
F_341 ( V_13 , V_397 -> V_536 , V_18 ) ;
break;
case V_154 :
F_341 ( V_13 , V_538 -> V_536 , V_18 ) ;
break;
default:
F_99 ( L_103 , V_2 -> V_107 , V_2 -> V_152 ) ;
return;
}
V_64 = F_348 ( V_13 ) -> V_542 ;
if ( ! V_64 ) {
F_94 ( L_104 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_317 ( V_540 , V_13 ) ;
} else {
F_94 ( L_105 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_348 ( V_13 ) -> V_542 = NULL ;
F_349 ( & V_540 -> V_476 ) ;
F_350 ( V_540 , V_13 ) ;
V_18 &= ~ V_543 ;
V_18 |= V_544 ;
do {
V_13 = V_64 ; V_64 = V_64 -> V_545 ;
F_315 ( V_13 ) -> V_370 = V_508 ;
F_341 ( V_13 , V_397 -> V_536 , V_18 ) ;
F_94 ( L_105 , V_2 -> V_107 , V_13 , V_13 -> V_121 ) ;
F_350 ( V_540 , V_13 ) ;
} while ( V_64 );
F_351 ( & V_540 -> V_476 ) ;
}
}
void F_352 ( struct V_537 * V_538 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_538 -> V_397 -> V_2 ;
F_94 ( L_106 , V_2 -> V_107 , V_538 , V_18 ) ;
F_346 ( V_538 , & V_538 -> V_546 , V_13 , V_18 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_324 ) ;
}
void F_353 ( struct V_396 * V_397 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_397 -> V_2 ;
struct V_523 V_118 ;
F_94 ( L_107 , V_2 -> V_107 , V_13 -> V_121 ) ;
V_118 . V_536 = F_121 ( V_397 -> V_536 ) ;
V_118 . V_522 = V_13 -> V_121 ;
F_342 ( V_13 , V_516 ) ;
F_343 ( V_13 ) ;
memcpy ( F_344 ( V_13 ) , & V_118 , V_516 ) ;
F_315 ( V_13 ) -> V_370 = V_514 ;
F_317 ( & V_397 -> V_546 , V_13 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_324 ) ;
}
static struct V_396 * F_354 ( struct V_1 * V_2 , T_7 type ,
int * V_547 )
{
struct V_548 * V_520 = & V_2 -> V_480 ;
struct V_396 * V_397 = NULL , * V_549 ;
unsigned int V_286 = 0 , F_7 = ~ 0 ;
F_355 () ;
F_356 (c, &h->list, list) {
if ( V_549 -> type != type || F_333 ( & V_549 -> V_546 ) )
continue;
if ( V_549 -> V_265 != V_439 && V_549 -> V_265 != V_550 )
continue;
V_286 ++ ;
if ( V_549 -> V_421 < F_7 ) {
F_7 = V_549 -> V_421 ;
V_397 = V_549 ;
}
if ( F_357 ( V_2 , type ) == V_286 )
break;
}
F_358 () ;
if ( V_397 ) {
int V_551 , V_552 ;
switch ( V_397 -> type ) {
case V_553 :
V_551 = V_2 -> V_351 ;
break;
case V_554 :
case V_555 :
V_551 = V_2 -> V_352 ;
break;
case V_437 :
V_551 = V_2 -> V_387 ? V_2 -> V_353 : V_2 -> V_351 ;
break;
default:
V_551 = 0 ;
F_99 ( L_108 ) ;
}
V_552 = V_551 / V_286 ;
* V_547 = V_552 ? V_552 : 1 ;
} else
* V_547 = 0 ;
F_94 ( L_109 , V_397 , * V_547 ) ;
return V_397 ;
}
static void F_359 ( struct V_1 * V_2 , T_7 type )
{
struct V_548 * V_520 = & V_2 -> V_480 ;
struct V_396 * V_549 ;
F_99 ( L_110 , V_2 -> V_107 ) ;
F_355 () ;
F_356 (c, &h->list, list) {
if ( V_549 -> type == type && V_549 -> V_421 ) {
F_99 ( L_111 ,
V_2 -> V_107 , & V_549 -> V_556 ) ;
F_360 ( V_549 , V_557 ) ;
}
}
F_358 () ;
}
static struct V_537 * F_361 ( struct V_1 * V_2 , T_7 type ,
int * V_547 )
{
struct V_548 * V_520 = & V_2 -> V_480 ;
struct V_537 * V_538 = NULL ;
unsigned int V_286 = 0 , F_7 = ~ 0 , V_558 = 0 ;
struct V_396 * V_397 ;
int V_551 , V_552 , V_559 = 0 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_355 () ;
F_356 (conn, &h->list, list) {
struct V_537 * V_394 ;
if ( V_397 -> type != type )
continue;
if ( V_397 -> V_265 != V_439 && V_397 -> V_265 != V_550 )
continue;
V_559 ++ ;
F_356 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_333 ( & V_394 -> V_546 ) )
continue;
V_13 = F_362 ( & V_394 -> V_546 ) ;
if ( V_13 -> V_560 < V_558 )
continue;
if ( V_13 -> V_560 > V_558 ) {
V_286 = 0 ;
F_7 = ~ 0 ;
V_558 = V_13 -> V_560 ;
}
V_286 ++ ;
if ( V_397 -> V_421 < F_7 ) {
F_7 = V_397 -> V_421 ;
V_538 = V_394 ;
}
}
if ( F_357 ( V_2 , type ) == V_559 )
break;
}
F_358 () ;
if ( ! V_538 )
return NULL ;
switch ( V_538 -> V_397 -> type ) {
case V_553 :
V_551 = V_2 -> V_351 ;
break;
case V_561 :
V_551 = V_2 -> V_562 ;
break;
case V_554 :
case V_555 :
V_551 = V_2 -> V_352 ;
break;
case V_437 :
V_551 = V_2 -> V_387 ? V_2 -> V_353 : V_2 -> V_351 ;
break;
default:
V_551 = 0 ;
F_99 ( L_108 ) ;
}
V_552 = V_551 / V_286 ;
* V_547 = V_552 ? V_552 : 1 ;
F_94 ( L_112 , V_538 , * V_547 ) ;
return V_538 ;
}
static void F_363 ( struct V_1 * V_2 , T_7 type )
{
struct V_548 * V_520 = & V_2 -> V_480 ;
struct V_396 * V_397 ;
int V_286 = 0 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
F_355 () ;
F_356 (conn, &h->list, list) {
struct V_537 * V_538 ;
if ( V_397 -> type != type )
continue;
if ( V_397 -> V_265 != V_439 && V_397 -> V_265 != V_550 )
continue;
V_286 ++ ;
F_356 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_538 -> V_421 ) {
V_538 -> V_421 = 0 ;
continue;
}
if ( F_333 ( & V_538 -> V_546 ) )
continue;
V_13 = F_362 ( & V_538 -> V_546 ) ;
if ( V_13 -> V_560 >= V_563 - 1 )
continue;
V_13 -> V_560 = V_563 - 1 ;
F_94 ( L_113 , V_538 , V_13 ,
V_13 -> V_560 ) ;
}
if ( F_357 ( V_2 , type ) == V_286 )
break;
}
F_358 () ;
}
static inline int F_364 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_365 ( V_13 -> V_121 - V_512 , V_2 -> V_564 ) ;
}
static void F_366 ( struct V_1 * V_2 , unsigned int V_551 )
{
if ( ! F_4 ( V_321 , & V_2 -> V_18 ) ) {
if ( ! V_551 && F_367 ( V_285 , V_2 -> V_565 +
V_566 ) )
F_359 ( V_2 , V_553 ) ;
}
}
static void F_368 ( struct V_1 * V_2 )
{
unsigned int V_551 = V_2 -> V_351 ;
struct V_537 * V_538 ;
struct V_12 * V_13 ;
int V_547 ;
F_366 ( V_2 , V_551 ) ;
while ( V_2 -> V_351 &&
( V_538 = F_361 ( V_2 , V_553 , & V_547 ) ) ) {
T_10 V_560 = ( F_362 ( & V_538 -> V_546 ) ) -> V_560 ;
while ( V_547 -- && ( V_13 = F_362 ( & V_538 -> V_546 ) ) ) {
F_94 ( L_114 , V_538 , V_13 ,
V_13 -> V_121 , V_13 -> V_560 ) ;
if ( V_13 -> V_560 < V_560 )
break;
V_13 = F_369 ( & V_538 -> V_546 ) ;
F_370 ( V_538 -> V_397 ,
F_315 ( V_13 ) -> V_567 ) ;
F_327 ( V_2 , V_13 ) ;
V_2 -> V_565 = V_285 ;
V_2 -> V_351 -- ;
V_538 -> V_421 ++ ;
V_538 -> V_397 -> V_421 ++ ;
}
}
if ( V_551 != V_2 -> V_351 )
F_363 ( V_2 , V_553 ) ;
}
static void F_371 ( struct V_1 * V_2 )
{
unsigned int V_551 = V_2 -> V_562 ;
struct V_537 * V_538 ;
struct V_12 * V_13 ;
int V_547 ;
T_5 type ;
F_366 ( V_2 , V_551 ) ;
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( V_2 -> V_152 == V_154 )
type = V_561 ;
else
type = V_553 ;
while ( V_2 -> V_562 > 0 &&
( V_538 = F_361 ( V_2 , type , & V_547 ) ) ) {
T_10 V_560 = ( F_362 ( & V_538 -> V_546 ) ) -> V_560 ;
while ( V_547 > 0 && ( V_13 = F_362 ( & V_538 -> V_546 ) ) ) {
int V_568 ;
F_94 ( L_114 , V_538 , V_13 ,
V_13 -> V_121 , V_13 -> V_560 ) ;
if ( V_13 -> V_560 < V_560 )
break;
V_13 = F_369 ( & V_538 -> V_546 ) ;
V_568 = F_364 ( V_2 , V_13 ) ;
if ( V_568 > V_2 -> V_562 )
return;
F_370 ( V_538 -> V_397 ,
F_315 ( V_13 ) -> V_567 ) ;
F_327 ( V_2 , V_13 ) ;
V_2 -> V_565 = V_285 ;
V_2 -> V_562 -= V_568 ;
V_547 -= V_568 ;
V_538 -> V_421 += V_568 ;
V_538 -> V_397 -> V_421 += V_568 ;
}
}
if ( V_551 != V_2 -> V_562 )
F_363 ( V_2 , type ) ;
}
static void F_372 ( struct V_1 * V_2 )
{
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_357 ( V_2 , V_553 ) && V_2 -> V_152 == V_153 )
return;
if ( ! F_357 ( V_2 , V_561 ) && V_2 -> V_152 == V_154 )
return;
switch ( V_2 -> V_139 ) {
case V_140 :
F_368 ( V_2 ) ;
break;
case V_144 :
F_371 ( V_2 ) ;
break;
}
}
static void F_373 ( struct V_1 * V_2 )
{
struct V_396 * V_397 ;
struct V_12 * V_13 ;
int V_547 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_357 ( V_2 , V_554 ) )
return;
while ( V_2 -> V_352 && ( V_397 = F_354 ( V_2 , V_554 , & V_547 ) ) ) {
while ( V_547 -- && ( V_13 = F_369 ( & V_397 -> V_546 ) ) ) {
F_94 ( L_115 , V_13 , V_13 -> V_121 ) ;
F_327 ( V_2 , V_13 ) ;
V_397 -> V_421 ++ ;
if ( V_397 -> V_421 == ~ 0 )
V_397 -> V_421 = 0 ;
}
}
}
static void F_374 ( struct V_1 * V_2 )
{
struct V_396 * V_397 ;
struct V_12 * V_13 ;
int V_547 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_357 ( V_2 , V_555 ) )
return;
while ( V_2 -> V_352 && ( V_397 = F_354 ( V_2 , V_555 ,
& V_547 ) ) ) {
while ( V_547 -- && ( V_13 = F_369 ( & V_397 -> V_546 ) ) ) {
F_94 ( L_115 , V_13 , V_13 -> V_121 ) ;
F_327 ( V_2 , V_13 ) ;
V_397 -> V_421 ++ ;
if ( V_397 -> V_421 == ~ 0 )
V_397 -> V_421 = 0 ;
}
}
}
static void F_375 ( struct V_1 * V_2 )
{
struct V_537 * V_538 ;
struct V_12 * V_13 ;
int V_547 , V_551 , V_394 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
if ( ! F_357 ( V_2 , V_437 ) )
return;
if ( ! F_4 ( V_321 , & V_2 -> V_18 ) ) {
if ( ! V_2 -> V_353 && V_2 -> V_388 &&
F_367 ( V_285 , V_2 -> V_569 + V_570 * 45 ) )
F_359 ( V_2 , V_437 ) ;
}
V_551 = V_2 -> V_388 ? V_2 -> V_353 : V_2 -> V_351 ;
V_394 = V_551 ;
while ( V_551 && ( V_538 = F_361 ( V_2 , V_437 , & V_547 ) ) ) {
T_10 V_560 = ( F_362 ( & V_538 -> V_546 ) ) -> V_560 ;
while ( V_547 -- && ( V_13 = F_362 ( & V_538 -> V_546 ) ) ) {
F_94 ( L_114 , V_538 , V_13 ,
V_13 -> V_121 , V_13 -> V_560 ) ;
if ( V_13 -> V_560 < V_560 )
break;
V_13 = F_369 ( & V_538 -> V_546 ) ;
F_327 ( V_2 , V_13 ) ;
V_2 -> V_569 = V_285 ;
V_551 -- ;
V_538 -> V_421 ++ ;
V_538 -> V_397 -> V_421 ++ ;
}
}
if ( V_2 -> V_388 )
V_2 -> V_353 = V_551 ;
else
V_2 -> V_351 = V_551 ;
if ( V_551 != V_394 )
F_363 ( V_2 , V_437 ) ;
}
static void V_483 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 , V_324 ) ;
struct V_12 * V_13 ;
F_94 ( L_116 , V_2 -> V_107 , V_2 -> V_351 ,
V_2 -> V_352 , V_2 -> V_353 ) ;
if ( ! F_4 ( V_305 , & V_2 -> V_11 ) ) {
F_372 ( V_2 ) ;
F_373 ( V_2 ) ;
F_374 ( V_2 ) ;
F_375 ( V_2 ) ;
}
while ( ( V_13 = F_369 ( & V_2 -> V_347 ) ) )
F_327 ( V_2 , V_13 ) ;
}
static void F_376 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_521 * V_118 = ( void * ) V_13 -> V_26 ;
struct V_396 * V_397 ;
T_13 V_536 , V_18 ;
F_100 ( V_13 , V_512 ) ;
V_536 = F_31 ( V_118 -> V_536 ) ;
V_18 = F_377 ( V_536 ) ;
V_536 = F_378 ( V_536 ) ;
F_94 ( L_117 , V_2 -> V_107 , V_13 -> V_121 ,
V_536 , V_18 ) ;
V_2 -> V_354 . V_571 ++ ;
F_19 ( V_2 ) ;
V_397 = F_379 ( V_2 , V_536 ) ;
F_22 ( V_2 ) ;
if ( V_397 ) {
F_370 ( V_397 , V_572 ) ;
F_380 ( V_397 , V_13 , V_18 ) ;
return;
} else {
F_99 ( L_118 ,
V_2 -> V_107 , V_536 ) ;
}
F_16 ( V_13 ) ;
}
static void F_381 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_523 * V_118 = ( void * ) V_13 -> V_26 ;
struct V_396 * V_397 ;
T_13 V_536 ;
F_100 ( V_13 , V_516 ) ;
V_536 = F_31 ( V_118 -> V_536 ) ;
F_94 ( L_119 , V_2 -> V_107 , V_13 -> V_121 , V_536 ) ;
V_2 -> V_354 . V_573 ++ ;
F_19 ( V_2 ) ;
V_397 = F_379 ( V_2 , V_536 ) ;
F_22 ( V_2 ) ;
if ( V_397 ) {
F_382 ( V_397 , V_13 ) ;
return;
} else {
F_99 ( L_120 ,
V_2 -> V_107 , V_536 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_383 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_362 ( & V_2 -> V_327 ) ;
if ( ! V_13 )
return true ;
return F_315 ( V_13 ) -> V_132 . V_535 ;
}
static void F_384 ( struct V_1 * V_2 )
{
struct V_420 * V_421 ;
struct V_12 * V_13 ;
T_9 V_114 ;
if ( ! V_2 -> V_330 )
return;
V_421 = ( void * ) V_2 -> V_330 -> V_26 ;
V_114 = F_31 ( V_421 -> V_114 ) ;
if ( V_114 == V_25 )
return;
V_13 = F_385 ( V_2 -> V_330 , V_309 ) ;
if ( ! V_13 )
return;
F_386 ( & V_2 -> V_327 , V_13 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_325 ) ;
}
void F_387 ( struct V_1 * V_2 , T_9 V_114 , T_5 V_448 )
{
T_15 V_574 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_94 ( L_121 , V_114 , V_448 ) ;
if ( ! F_340 ( V_2 , V_114 ) ) {
if ( F_4 ( V_318 , & V_2 -> V_18 ) && V_114 == V_25 )
F_384 ( V_2 ) ;
return;
}
if ( ! V_448 && ! F_383 ( V_2 ) )
return;
if ( V_2 -> V_330 ) {
V_574 = F_315 ( V_2 -> V_330 ) -> V_132 . V_532 ;
if ( V_574 ) {
F_315 ( V_2 -> V_330 ) -> V_132 . V_532 = NULL ;
goto V_575;
}
}
F_335 ( & V_2 -> V_327 . V_476 , V_18 ) ;
while ( ( V_13 = F_388 ( & V_2 -> V_327 ) ) ) {
if ( F_315 ( V_13 ) -> V_132 . V_535 ) {
F_389 ( & V_2 -> V_327 , V_13 ) ;
break;
}
V_574 = F_315 ( V_13 ) -> V_132 . V_532 ;
F_16 ( V_13 ) ;
}
F_337 ( & V_2 -> V_327 . V_476 , V_18 ) ;
V_575:
if ( V_574 )
V_574 ( V_2 , V_448 ) ;
}
static void V_481 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 , V_326 ) ;
struct V_12 * V_13 ;
F_94 ( L_24 , V_2 -> V_107 ) ;
while ( ( V_13 = F_369 ( & V_2 -> V_328 ) ) ) {
F_328 ( V_2 , V_13 ) ;
if ( F_329 ( & V_2 -> V_530 ) ) {
F_330 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_321 , & V_2 -> V_18 ) ||
F_4 ( V_305 , & V_2 -> V_11 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_318 , & V_2 -> V_18 ) ) {
switch ( F_315 ( V_13 ) -> V_370 ) {
case V_508 :
case V_514 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_315 ( V_13 ) -> V_370 ) {
case V_509 :
F_94 ( L_122 , V_2 -> V_107 ) ;
F_390 ( V_2 , V_13 ) ;
break;
case V_508 :
F_94 ( L_123 , V_2 -> V_107 ) ;
F_376 ( V_2 , V_13 ) ;
break;
case V_514 :
F_94 ( L_124 , V_2 -> V_107 ) ;
F_381 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_482 ( struct V_390 * V_391 )
{
struct V_1 * V_2 = F_218 ( V_391 , struct V_1 , V_325 ) ;
struct V_12 * V_13 ;
F_94 ( L_125 , V_2 -> V_107 ,
F_329 ( & V_2 -> V_317 ) , F_332 ( & V_2 -> V_327 ) ) ;
if ( F_329 ( & V_2 -> V_317 ) ) {
V_13 = F_369 ( & V_2 -> V_327 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_330 ) ;
V_2 -> V_330 = F_385 ( V_13 , V_309 ) ;
if ( V_2 -> V_330 ) {
F_391 ( & V_2 -> V_317 ) ;
F_327 ( V_2 , V_13 ) ;
if ( F_4 ( V_138 , & V_2 -> V_18 ) )
F_392 ( & V_2 -> V_336 ) ;
else
F_393 ( & V_2 -> V_336 ,
V_285 + V_24 ) ;
} else {
F_386 ( & V_2 -> V_327 , V_13 ) ;
F_245 ( V_2 -> V_422 , & V_2 -> V_325 ) ;
}
}
}
void F_270 ( struct V_131 * V_132 )
{
struct V_576 V_188 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_15 = V_577 ;
F_116 ( V_132 , V_578 , sizeof( V_188 ) , & V_188 ) ;
}
void F_394 ( struct V_131 * V_132 )
{
struct V_579 V_580 ;
struct V_576 V_581 ;
struct V_1 * V_2 = V_132 -> V_2 ;
T_5 V_456 ;
if ( F_273 ( V_132 , true , & V_456 ) )
return;
memset ( & V_580 , 0 , sizeof( V_580 ) ) ;
V_580 . type = V_582 ;
V_580 . V_583 = F_121 ( V_2 -> V_470 ) ;
V_580 . V_584 = F_121 ( V_2 -> V_471 ) ;
V_580 . V_585 = V_456 ;
F_116 ( V_132 , V_586 , sizeof( V_580 ) ,
& V_580 ) ;
memset ( & V_581 , 0 , sizeof( V_581 ) ) ;
V_581 . V_15 = V_587 ;
V_581 . V_588 = V_589 ;
F_116 ( V_132 , V_578 , sizeof( V_581 ) ,
& V_581 ) ;
}
static void F_395 ( struct V_1 * V_2 , T_5 V_448 )
{
if ( V_448 )
F_94 ( L_126
L_127 , V_448 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_131 V_132 ;
struct V_396 * V_397 ;
int V_16 ;
F_103 ( & V_132 , V_2 ) ;
if ( F_308 ( & V_2 -> V_447 ) ) {
if ( ! F_4 ( V_590 , & V_2 -> V_11 ) )
return;
F_270 ( & V_132 ) ;
F_94 ( L_128 , V_2 -> V_107 ) ;
} else {
V_397 = F_272 ( V_2 , V_437 , V_453 ) ;
if ( V_397 )
return;
if ( F_4 ( V_590 , & V_2 -> V_11 ) )
F_270 ( & V_132 ) ;
F_394 ( & V_132 ) ;
F_94 ( L_129 , V_2 -> V_107 ) ;
}
V_16 = F_105 ( & V_132 , F_395 ) ;
if ( V_16 )
F_99 ( L_130 , V_16 ) ;
}
