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
struct V_60 * V_61 ;
F_34 () ;
F_35 (key, &hdev->link_keys, list)
F_20 ( V_28 , L_7 , & V_61 -> V_40 , V_61 -> type ,
V_62 , V_61 -> V_45 , V_61 -> V_63 ) ;
F_36 () ;
return 0 ;
}
static int F_37 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_33 , V_36 -> V_37 ) ;
}
static int F_38 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_8 , V_2 -> V_55 [ 2 ] ,
V_2 -> V_55 [ 1 ] , V_2 -> V_55 [ 0 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_38 , V_36 -> V_37 ) ;
}
static int F_40 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_64 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_41 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
V_2 -> V_65 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_42 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_65 ;
F_22 ( V_2 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_66 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_44 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_67 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_66 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_66 , & V_2 -> V_11 ) ;
return V_6 ;
}
static T_1 F_45 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_68 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_46 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_68 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_68 , & V_2 -> V_11 ) ;
return V_6 ;
}
static T_1 F_47 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_69 , & V_2 -> V_70 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static int F_48 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 != 0 && ( V_45 < 500 || V_45 > 3600000 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_71 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_49 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_71 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_50 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 30 || V_45 > ( 60 * 60 * 24 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_72 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_51 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_72 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_52 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 > V_2 -> V_73 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_74 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_53 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_74 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_54 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 < V_2 -> V_74 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_73 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_55 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_73 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_56 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 > V_2 -> V_75 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_76 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_57 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_76 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_58 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 < V_2 -> V_76 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_75 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_59 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_75 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_7 V_77 ;
T_5 V_78 ;
F_19 ( V_2 ) ;
F_61 ( V_2 , & V_77 , & V_78 ) ;
F_20 ( V_28 , L_9 , & V_77 , V_78 ,
16 , V_2 -> V_79 , & V_2 -> V_80 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_60 , V_36 -> V_37 ) ;
}
static int F_63 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_81 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_63 , V_36 -> V_37 ) ;
}
static int F_65 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_10 , & V_2 -> V_82 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_65 , V_36 -> V_37 ) ;
}
static T_1 F_67 ( struct V_4 * V_4 ,
char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_83 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_68 ( struct V_4 * V_4 ,
const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
if ( F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_67 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_83 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_83 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_69 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->le_white_list, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_69 , V_36 -> V_37 ) ;
}
static int F_71 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_84 * V_79 ;
F_34 () ;
F_35 (irk, &hdev->identity_resolving_keys, list) {
F_20 ( V_28 , L_9 ,
& V_79 -> V_40 , V_79 -> V_78 ,
16 , V_79 -> V_45 , & V_79 -> V_80 ) ;
}
F_36 () ;
return 0 ;
}
static int F_72 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_71 ,
V_36 -> V_37 ) ;
}
static int F_73 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_85 * V_86 ;
F_34 () ;
F_35 (ltk, &hdev->long_term_keys, list)
F_20 ( V_28 , L_11 ,
& V_86 -> V_40 , V_86 -> V_41 , V_86 -> V_87 ,
V_86 -> type , V_86 -> V_88 , F_31 ( V_86 -> V_89 ) ,
F_74 ( V_86 -> rand ) , 16 , V_86 -> V_45 ) ;
F_36 () ;
return 0 ;
}
static int F_75 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_73 , V_36 -> V_37 ) ;
}
static int F_76 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 > V_2 -> V_90 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_91 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_91 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_78 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 < V_2 -> V_91 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_90 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_79 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_90 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_80 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 > 0x01f3 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_92 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_81 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_92 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_82 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x000a || V_45 > 0x0c80 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_93 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_83 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_93 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_84 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x01 || V_45 > 0x07 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_94 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_85 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_94 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0020 || V_45 > 0x4000 || V_45 > V_2 -> V_95 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_96 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_87 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_96 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_88 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0020 || V_45 > 0x4000 || V_45 < V_2 -> V_96 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_95 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_89 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_95 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_97 * V_31 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->whitelist, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_26 (p, &hdev->le_conn_params, list) {
F_20 ( V_28 , L_12 , & V_31 -> V_77 , V_31 -> V_78 ,
V_31 -> V_98 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_90 , V_36 -> V_37 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_5 V_99 )
{
F_93 ( L_13 , V_2 -> V_100 , V_99 ) ;
if ( V_2 -> V_101 == V_102 ) {
V_2 -> V_103 = V_99 ;
V_2 -> V_101 = V_104 ;
F_94 ( & V_2 -> V_105 ) ;
}
}
static void F_95 ( struct V_1 * V_2 , int V_16 )
{
F_93 ( L_14 , V_2 -> V_100 , V_16 ) ;
if ( V_2 -> V_101 == V_102 ) {
V_2 -> V_103 = V_16 ;
V_2 -> V_101 = V_106 ;
F_94 ( & V_2 -> V_105 ) ;
}
}
static struct V_12 * F_96 ( struct V_1 * V_2 , T_8 V_107 ,
T_5 V_3 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_12 * V_13 ;
F_19 ( V_2 ) ;
V_13 = V_2 -> V_112 ;
V_2 -> V_112 = NULL ;
F_22 ( V_2 ) ;
if ( ! V_13 )
return F_97 ( - V_113 ) ;
if ( V_13 -> V_114 < sizeof( * V_111 ) ) {
F_98 ( L_15 ) ;
goto V_115;
}
V_111 = ( void * ) V_13 -> V_26 ;
F_99 ( V_13 , V_116 ) ;
if ( V_3 ) {
if ( V_111 -> V_117 != V_3 )
goto V_115;
return V_13 ;
}
if ( V_111 -> V_117 != V_118 ) {
F_93 ( L_16 , V_111 -> V_117 ) ;
goto V_115;
}
if ( V_13 -> V_114 < sizeof( * V_109 ) ) {
F_98 ( L_17 ) ;
goto V_115;
}
V_109 = ( void * ) V_13 -> V_26 ;
F_99 ( V_13 , sizeof( * V_109 ) ) ;
if ( V_107 == F_31 ( V_109 -> V_107 ) )
return V_13 ;
F_93 ( L_18 , V_107 ,
F_31 ( V_109 -> V_107 ) ) ;
V_115:
F_16 ( V_13 ) ;
return F_97 ( - V_113 ) ;
}
struct V_12 * F_100 ( struct V_1 * V_2 , T_8 V_107 , T_9 V_119 ,
const void * V_120 , T_5 V_3 , T_9 V_121 )
{
F_101 ( V_122 , V_123 ) ;
struct V_124 V_125 ;
int V_16 = 0 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_102 ( & V_125 , V_2 ) ;
F_103 ( & V_125 , V_107 , V_119 , V_120 , V_3 ) ;
V_2 -> V_101 = V_102 ;
F_104 ( & V_2 -> V_105 , & V_122 ) ;
F_105 ( V_126 ) ;
V_16 = F_106 ( & V_125 , F_92 ) ;
if ( V_16 < 0 ) {
F_107 ( & V_2 -> V_105 , & V_122 ) ;
F_105 ( V_127 ) ;
return F_97 ( V_16 ) ;
}
F_108 ( V_121 ) ;
F_107 ( & V_2 -> V_105 , & V_122 ) ;
if ( F_109 ( V_123 ) )
return F_97 ( - V_128 ) ;
switch ( V_2 -> V_101 ) {
case V_104 :
V_16 = - F_15 ( V_2 -> V_103 ) ;
break;
case V_106 :
V_16 = - V_2 -> V_103 ;
break;
default:
V_16 = - V_129 ;
break;
}
V_2 -> V_101 = V_2 -> V_103 = 0 ;
F_93 ( L_20 , V_2 -> V_100 , V_16 ) ;
if ( V_16 < 0 )
return F_97 ( V_16 ) ;
return F_96 ( V_2 , V_107 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_8 V_107 , T_9 V_119 ,
const void * V_120 , T_9 V_121 )
{
return F_100 ( V_2 , V_107 , V_119 , V_120 , 0 , V_121 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
void (* F_111)( struct V_124 * V_125 ,
unsigned long V_130 ) ,
unsigned long V_130 , T_10 V_121 )
{
struct V_124 V_125 ;
F_101 ( V_122 , V_123 ) ;
int V_16 = 0 ;
F_93 ( L_21 , V_2 -> V_100 ) ;
F_102 ( & V_125 , V_2 ) ;
V_2 -> V_101 = V_102 ;
F_111 ( & V_125 , V_130 ) ;
F_104 ( & V_2 -> V_105 , & V_122 ) ;
F_105 ( V_126 ) ;
V_16 = F_106 ( & V_125 , F_92 ) ;
if ( V_16 < 0 ) {
V_2 -> V_101 = 0 ;
F_107 ( & V_2 -> V_105 , & V_122 ) ;
F_105 ( V_127 ) ;
if ( V_16 == - V_113 )
return 0 ;
return V_16 ;
}
F_108 ( V_121 ) ;
F_107 ( & V_2 -> V_105 , & V_122 ) ;
if ( F_109 ( V_123 ) )
return - V_128 ;
switch ( V_2 -> V_101 ) {
case V_104 :
V_16 = - F_15 ( V_2 -> V_103 ) ;
break;
case V_106 :
V_16 = - V_2 -> V_103 ;
break;
default:
V_16 = - V_129 ;
break;
}
V_2 -> V_101 = V_2 -> V_103 = 0 ;
F_93 ( L_20 , V_2 -> V_100 , V_16 ) ;
return V_16 ;
}
static int F_112 ( struct V_1 * V_2 ,
void (* V_125)( struct V_124 * V_125 ,
unsigned long V_130 ) ,
unsigned long V_130 , T_10 V_121 )
{
int V_131 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_131 = F_110 ( V_2 , V_125 , V_130 , V_121 ) ;
F_12 ( V_2 ) ;
return V_131 ;
}
static void F_113 ( struct V_124 * V_125 , unsigned long V_130 )
{
F_93 ( L_22 , V_125 -> V_2 -> V_100 , V_130 ) ;
F_114 ( V_132 , & V_125 -> V_2 -> V_18 ) ;
F_115 ( V_125 , V_25 , 0 , NULL ) ;
}
static void F_116 ( struct V_124 * V_125 )
{
V_125 -> V_2 -> V_133 = V_134 ;
F_115 ( V_125 , V_135 , 0 , NULL ) ;
F_115 ( V_125 , V_136 , 0 , NULL ) ;
F_115 ( V_125 , V_137 , 0 , NULL ) ;
}
static void F_117 ( struct V_124 * V_125 )
{
V_125 -> V_2 -> V_133 = V_138 ;
F_115 ( V_125 , V_136 , 0 , NULL ) ;
F_115 ( V_125 , V_139 , 0 , NULL ) ;
F_115 ( V_125 , V_135 , 0 , NULL ) ;
F_115 ( V_125 , V_140 , 0 , NULL ) ;
F_115 ( V_125 , V_141 , 0 , NULL ) ;
F_115 ( V_125 , V_142 , 0 , NULL ) ;
F_115 ( V_125 , V_143 , 0 , NULL ) ;
}
static void F_118 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
F_93 ( L_22 , V_2 -> V_100 , V_130 ) ;
if ( ! F_4 ( V_144 , & V_2 -> V_145 ) )
F_113 ( V_125 , 0 ) ;
switch ( V_2 -> V_146 ) {
case V_147 :
F_116 ( V_125 ) ;
break;
case V_148 :
F_117 ( V_125 ) ;
break;
default:
F_98 ( L_23 , V_2 -> V_146 ) ;
break;
}
}
static void F_119 ( struct V_124 * V_125 )
{
T_11 V_120 ;
T_12 V_149 ;
F_115 ( V_125 , V_150 , 0 , NULL ) ;
F_115 ( V_125 , V_151 , 0 , NULL ) ;
F_115 ( V_125 , V_152 , 0 , NULL ) ;
F_115 ( V_125 , V_153 , 0 , NULL ) ;
F_115 ( V_125 , V_154 , 0 , NULL ) ;
F_115 ( V_125 , V_155 , 0 , NULL ) ;
V_149 = V_156 ;
F_115 ( V_125 , V_157 , 1 , & V_149 ) ;
V_120 = F_120 ( 0x7d00 ) ;
F_115 ( V_125 , V_158 , 2 , & V_120 ) ;
}
static void F_121 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
F_115 ( V_125 , V_159 , 0 , NULL ) ;
F_115 ( V_125 , V_160 , 0 , NULL ) ;
F_115 ( V_125 , V_161 , 0 , NULL ) ;
F_115 ( V_125 , V_162 , 0 , NULL ) ;
F_115 ( V_125 , V_163 , 0 , NULL ) ;
if ( ! F_122 ( V_2 ) )
F_114 ( V_164 , & V_2 -> V_70 ) ;
}
static T_5 F_123 ( struct V_1 * V_2 )
{
if ( F_124 ( V_2 ) )
return 0x02 ;
if ( F_125 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_165 == 11 && V_2 -> V_166 == 0x00 &&
V_2 -> V_167 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_165 == 15 ) {
if ( V_2 -> V_166 == 0x03 && V_2 -> V_167 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_166 == 0x09 && V_2 -> V_167 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_166 == 0x00 && V_2 -> V_167 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_165 == 31 && V_2 -> V_166 == 0x2005 &&
V_2 -> V_167 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_126 ( struct V_124 * V_125 )
{
T_5 V_168 ;
V_168 = F_123 ( V_125 -> V_2 ) ;
F_115 ( V_125 , V_169 , 1 , & V_168 ) ;
}
static void F_127 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
T_5 V_170 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_171 < V_172 )
return;
if ( F_122 ( V_2 ) ) {
V_170 [ 4 ] |= 0x01 ;
V_170 [ 4 ] |= 0x02 ;
V_170 [ 4 ] |= 0x04 ;
V_170 [ 5 ] |= 0x08 ;
V_170 [ 5 ] |= 0x10 ;
} else {
memset ( V_170 , 0 , sizeof( V_170 ) ) ;
V_170 [ 0 ] |= 0x10 ;
V_170 [ 1 ] |= 0x08 ;
V_170 [ 1 ] |= 0x20 ;
V_170 [ 1 ] |= 0x40 ;
V_170 [ 1 ] |= 0x80 ;
V_170 [ 2 ] |= 0x04 ;
V_170 [ 3 ] |= 0x02 ;
if ( V_2 -> V_35 [ 0 ] & V_173 ) {
V_170 [ 0 ] |= 0x80 ;
V_170 [ 5 ] |= 0x80 ;
}
}
if ( F_125 ( V_2 ) )
V_170 [ 4 ] |= 0x02 ;
if ( F_128 ( V_2 ) )
V_170 [ 5 ] |= 0x20 ;
if ( F_129 ( V_2 ) )
V_170 [ 5 ] |= 0x80 ;
if ( F_124 ( V_2 ) )
V_170 [ 5 ] |= 0x40 ;
if ( F_130 ( V_2 ) )
V_170 [ 7 ] |= 0x01 ;
if ( F_131 ( V_2 ) )
V_170 [ 6 ] |= 0x80 ;
if ( F_132 ( V_2 ) ) {
V_170 [ 6 ] |= 0x01 ;
V_170 [ 6 ] |= 0x02 ;
V_170 [ 6 ] |= 0x04 ;
V_170 [ 6 ] |= 0x08 ;
V_170 [ 6 ] |= 0x10 ;
V_170 [ 6 ] |= 0x20 ;
V_170 [ 7 ] |= 0x04 ;
V_170 [ 7 ] |= 0x08 ;
V_170 [ 7 ] |= 0x10 ;
}
if ( F_21 ( V_2 ) )
V_170 [ 7 ] |= 0x20 ;
F_115 ( V_125 , V_174 , sizeof( V_170 ) , V_170 ) ;
}
static void F_133 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
if ( F_122 ( V_2 ) )
F_119 ( V_125 ) ;
else
F_134 ( V_175 , & V_2 -> V_70 ) ;
if ( F_21 ( V_2 ) )
F_121 ( V_125 ) ;
if ( V_2 -> V_165 != 31 && V_2 -> V_171 > V_176 )
F_115 ( V_125 , V_139 , 0 , NULL ) ;
if ( F_132 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_177 , & V_2 -> V_70 ) ) {
T_5 V_168 = 0x01 ;
F_115 ( V_125 , V_178 ,
sizeof( V_168 ) , & V_168 ) ;
} else {
struct V_179 V_180 ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
F_115 ( V_125 , V_182 , sizeof( V_180 ) , & V_180 ) ;
}
}
if ( F_125 ( V_2 ) )
F_126 ( V_125 ) ;
if ( F_135 ( V_2 ) )
F_115 ( V_125 , V_183 , 0 , NULL ) ;
if ( F_136 ( V_2 ) ) {
struct V_184 V_180 ;
V_180 . V_185 = 0x01 ;
F_115 ( V_125 , V_186 ,
sizeof( V_180 ) , & V_180 ) ;
}
if ( F_4 ( V_187 , & V_2 -> V_70 ) ) {
T_5 V_15 = 1 ;
F_115 ( V_125 , V_188 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_137 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_189 V_180 ;
T_8 V_190 = 0 ;
if ( F_138 ( V_2 ) )
V_190 |= V_191 ;
if ( F_139 ( V_2 ) )
V_190 |= V_192 ;
if ( F_140 ( V_2 ) )
V_190 |= V_193 ;
if ( F_141 ( V_2 ) )
V_190 |= V_194 ;
V_180 . V_195 = F_120 ( V_190 ) ;
F_115 ( V_125 , V_196 , sizeof( V_180 ) , & V_180 ) ;
}
static void F_142 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_197 V_180 ;
if ( ! F_122 ( V_2 ) )
return;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
if ( F_4 ( V_164 , & V_2 -> V_70 ) ) {
V_180 . V_198 = 0x01 ;
V_180 . V_199 = 0x00 ;
}
if ( V_180 . V_198 != F_143 ( V_2 ) )
F_115 ( V_125 , V_200 , sizeof( V_180 ) ,
& V_180 ) ;
}
static void F_144 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
T_5 V_170 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_145 ( V_2 ) ) {
V_170 [ 1 ] |= 0x40 ;
V_170 [ 1 ] |= 0x80 ;
V_170 [ 2 ] |= 0x10 ;
V_170 [ 2 ] |= 0x20 ;
}
if ( F_146 ( V_2 ) ) {
V_170 [ 2 ] |= 0x01 ;
V_170 [ 2 ] |= 0x02 ;
V_170 [ 2 ] |= 0x04 ;
V_170 [ 2 ] |= 0x08 ;
}
if ( F_147 ( V_2 ) || V_2 -> V_35 [ 0 ] & V_201 )
V_170 [ 2 ] |= 0x80 ;
F_115 ( V_125 , V_202 , sizeof( V_170 ) , V_170 ) ;
}
static void F_148 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
T_5 V_31 ;
F_127 ( V_125 ) ;
if ( V_2 -> V_203 [ 6 ] & 0x80 &&
! F_4 ( V_204 , & V_2 -> V_145 ) ) {
struct V_205 V_180 ;
F_149 ( & V_180 . V_40 , V_206 ) ;
V_180 . V_207 = 0x01 ;
F_115 ( V_125 , V_208 ,
sizeof( V_180 ) , & V_180 ) ;
}
if ( V_2 -> V_203 [ 5 ] & 0x10 )
F_137 ( V_125 ) ;
if ( V_2 -> V_203 [ 8 ] & 0x01 )
F_115 ( V_125 , V_209 , 0 , NULL ) ;
if ( V_2 -> V_203 [ 13 ] & 0x01 )
F_115 ( V_125 , V_210 , 0 , NULL ) ;
if ( F_21 ( V_2 ) ) {
T_5 V_170 [ 8 ] ;
memset ( V_170 , 0 , sizeof( V_170 ) ) ;
V_170 [ 0 ] = 0x0f ;
if ( V_2 -> V_35 [ 0 ] & V_173 )
V_170 [ 0 ] |= 0x10 ;
if ( V_2 -> V_35 [ 0 ] & V_211 )
V_170 [ 0 ] |= 0x20 ;
if ( V_2 -> V_35 [ 0 ] & V_212 )
V_170 [ 1 ] |= 0x04 ;
if ( V_2 -> V_203 [ 34 ] & 0x02 )
V_170 [ 0 ] |= 0x80 ;
if ( V_2 -> V_203 [ 34 ] & 0x04 )
V_170 [ 1 ] |= 0x01 ;
F_115 ( V_125 , V_213 , sizeof( V_170 ) ,
V_170 ) ;
if ( V_2 -> V_203 [ 25 ] & 0x40 ) {
F_115 ( V_125 , V_214 , 0 , NULL ) ;
}
F_142 ( V_125 ) ;
}
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_184 V_180 ;
V_180 . V_185 = V_31 ;
F_115 ( V_125 , V_186 ,
sizeof( V_180 ) , & V_180 ) ;
}
}
static void F_150 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
if ( V_2 -> V_203 [ 22 ] & 0x04 )
F_144 ( V_125 ) ;
if ( V_2 -> V_203 [ 29 ] & 0x20 )
F_115 ( V_125 , V_215 , 0 , NULL ) ;
if ( V_2 -> V_203 [ 30 ] & 0x08 )
F_115 ( V_125 , V_216 , 0 , NULL ) ;
if ( F_151 ( V_2 ) )
F_115 ( V_125 , V_217 , 0 , NULL ) ;
if ( F_152 ( V_2 ) ) {
T_5 V_218 = 0x01 ;
F_115 ( V_125 , V_219 ,
sizeof( V_218 ) , & V_218 ) ;
}
}
static int F_153 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_110 ( V_2 , F_118 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_221 , & V_2 -> V_70 ) ) {
F_154 ( L_24 , 0644 , V_2 -> V_222 , V_2 ,
& V_223 ) ;
}
if ( V_2 -> V_146 != V_147 )
return 0 ;
V_16 = F_110 ( V_2 , F_133 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_110 ( V_2 , F_148 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_110 ( V_2 , F_150 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_221 , & V_2 -> V_70 ) )
return 0 ;
F_154 ( L_25 , 0444 , V_2 -> V_222 , V_2 ,
& V_224 ) ;
F_155 ( L_26 , 0444 , V_2 -> V_222 ,
& V_2 -> V_165 ) ;
F_156 ( L_27 , 0444 , V_2 -> V_222 , & V_2 -> V_171 ) ;
F_155 ( L_28 , 0444 , V_2 -> V_222 , & V_2 -> V_166 ) ;
F_154 ( L_29 , 0444 , V_2 -> V_222 , V_2 ,
& V_225 ) ;
F_154 ( L_30 , 0444 , V_2 -> V_222 , V_2 ,
& V_226 ) ;
F_154 ( L_31 , 0444 , V_2 -> V_222 , V_2 , & V_227 ) ;
F_154 ( L_32 , 0644 , V_2 -> V_222 , V_2 ,
& V_228 ) ;
F_154 ( L_33 , 0644 , V_2 -> V_222 , V_2 ,
& V_229 ) ;
if ( F_122 ( V_2 ) ) {
F_154 ( L_34 , 0444 , V_2 -> V_222 ,
V_2 , & V_230 ) ;
F_154 ( L_35 , 0400 , V_2 -> V_222 ,
V_2 , & V_231 ) ;
F_154 ( L_36 , 0444 , V_2 -> V_222 ,
V_2 , & V_232 ) ;
F_154 ( L_37 , 0444 , V_2 -> V_222 ,
V_2 , & V_233 ) ;
}
if ( F_132 ( V_2 ) ) {
F_154 ( L_38 , 0644 , V_2 -> V_222 ,
V_2 , & V_234 ) ;
F_154 ( L_39 , 0644 , V_2 -> V_222 ,
V_2 , & V_235 ) ;
F_154 ( L_40 , 0444 , V_2 -> V_222 ,
V_2 , & V_236 ) ;
if ( F_21 ( V_2 ) )
F_154 ( L_41 , 0644 ,
V_2 -> V_222 , V_2 ,
& V_237 ) ;
}
if ( F_140 ( V_2 ) ) {
F_154 ( L_42 , 0644 , V_2 -> V_222 ,
V_2 , & V_238 ) ;
F_154 ( L_43 , 0644 , V_2 -> V_222 ,
V_2 , & V_239 ) ;
F_154 ( L_44 , 0644 , V_2 -> V_222 ,
V_2 , & V_240 ) ;
}
if ( F_21 ( V_2 ) ) {
F_154 ( L_45 , 0400 , V_2 -> V_222 ,
V_2 , & V_241 ) ;
F_154 ( L_46 , 0644 , V_2 -> V_222 ,
V_2 , & V_242 ) ;
F_154 ( L_47 , 0444 , V_2 -> V_222 ,
V_2 , & V_243 ) ;
F_154 ( L_48 , 0444 , V_2 -> V_222 ,
V_2 , & V_244 ) ;
if ( F_157 ( & V_2 -> V_40 , V_206 ) )
F_154 ( L_49 , 0644 ,
V_2 -> V_222 , V_2 ,
& V_245 ) ;
F_156 ( L_50 , 0444 , V_2 -> V_222 ,
& V_2 -> V_246 ) ;
F_154 ( L_51 , 0444 , V_2 -> V_222 , V_2 ,
& V_247 ) ;
F_154 ( L_52 , 0400 ,
V_2 -> V_222 , V_2 ,
& V_248 ) ;
F_154 ( L_53 , 0400 , V_2 -> V_222 ,
V_2 , & V_249 ) ;
F_154 ( L_54 , 0644 , V_2 -> V_222 ,
V_2 , & V_250 ) ;
F_154 ( L_55 , 0644 , V_2 -> V_222 ,
V_2 , & V_251 ) ;
F_154 ( L_56 , 0644 , V_2 -> V_222 ,
V_2 , & V_252 ) ;
F_154 ( L_57 , 0644 , V_2 -> V_222 ,
V_2 , & V_253 ) ;
F_154 ( L_58 , 0644 , V_2 -> V_222 ,
V_2 , & V_254 ) ;
F_154 ( L_59 , 0644 , V_2 -> V_222 ,
V_2 , & V_255 ) ;
F_154 ( L_60 , 0644 , V_2 -> V_222 ,
V_2 , & V_256 ) ;
F_155 ( L_61 , 0644 ,
V_2 -> V_222 ,
& V_2 -> V_257 ) ;
F_158 ( V_2 ) ;
}
return 0 ;
}
static void F_159 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
F_93 ( L_22 , V_2 -> V_100 , V_130 ) ;
if ( ! F_4 ( V_144 , & V_2 -> V_145 ) )
F_113 ( V_125 , 0 ) ;
F_115 ( V_125 , V_136 , 0 , NULL ) ;
if ( V_2 -> V_258 )
F_115 ( V_125 , V_137 , 0 , NULL ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_16 ;
if ( F_4 ( V_259 , & V_2 -> V_145 ) )
return 0 ;
V_16 = F_110 ( V_2 , F_159 , 0 , V_220 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static void F_161 ( struct V_124 * V_125 , unsigned long V_130 )
{
T_12 V_260 = V_130 ;
F_93 ( L_62 , V_125 -> V_2 -> V_100 , V_260 ) ;
F_115 ( V_125 , V_261 , 1 , & V_260 ) ;
}
static void F_162 ( struct V_124 * V_125 , unsigned long V_130 )
{
T_12 V_262 = V_130 ;
F_93 ( L_62 , V_125 -> V_2 -> V_100 , V_262 ) ;
F_115 ( V_125 , V_188 , 1 , & V_262 ) ;
}
static void F_163 ( struct V_124 * V_125 , unsigned long V_130 )
{
T_12 V_263 = V_130 ;
F_93 ( L_62 , V_125 -> V_2 -> V_100 , V_263 ) ;
F_115 ( V_125 , V_264 , 1 , & V_263 ) ;
}
static void F_164 ( struct V_124 * V_125 , unsigned long V_130 )
{
T_11 V_195 = F_120 ( V_130 ) ;
F_93 ( L_62 , V_125 -> V_2 -> V_100 , V_195 ) ;
F_115 ( V_125 , V_196 , 2 , & V_195 ) ;
}
struct V_1 * F_165 ( int V_265 )
{
struct V_1 * V_2 = NULL , * V_266 ;
F_93 ( L_63 , V_265 ) ;
if ( V_265 < 0 )
return NULL ;
F_166 ( & V_267 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_266 -> V_268 == V_265 ) {
V_2 = F_167 ( V_266 ) ;
break;
}
}
F_168 ( & V_267 ) ;
return V_2 ;
}
bool F_169 ( struct V_1 * V_2 )
{
struct V_46 * V_269 = & V_2 -> V_48 ;
switch ( V_269 -> V_270 ) {
case V_271 :
case V_272 :
return true ;
default:
return false ;
}
}
void F_170 ( struct V_1 * V_2 , int V_270 )
{
int V_273 = V_2 -> V_48 . V_270 ;
F_93 ( L_64 , V_2 -> V_100 , V_2 -> V_48 . V_270 , V_270 ) ;
if ( V_273 == V_270 )
return;
V_2 -> V_48 . V_270 = V_270 ;
switch ( V_270 ) {
case V_274 :
F_171 ( V_2 ) ;
if ( V_273 != V_275 )
F_172 ( V_2 , 0 ) ;
break;
case V_275 :
break;
case V_271 :
F_172 ( V_2 , 1 ) ;
break;
case V_272 :
break;
case V_276 :
break;
}
}
void F_173 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_277 ;
F_174 (p, n, &cache->all, all) {
F_175 ( & V_31 -> V_278 ) ;
F_176 ( V_31 ) ;
}
F_177 ( & V_47 -> V_279 ) ;
F_177 ( & V_47 -> V_280 ) ;
}
struct V_49 * F_178 ( struct V_1 * V_2 ,
T_7 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_93 ( L_65 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_157 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_179 ( struct V_1 * V_2 ,
T_7 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_93 ( L_65 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_157 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_180 ( struct V_1 * V_2 ,
T_7 * V_40 ,
int V_270 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_93 ( L_66 , V_47 , V_40 , V_270 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_157 ( V_40 , V_206 ) && V_50 -> V_281 == V_270 )
return V_50 ;
if ( ! F_157 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_181 ( struct V_1 * V_2 ,
struct V_49 * V_282 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_283 * V_284 = & V_47 -> V_280 ;
struct V_49 * V_31 ;
F_175 ( & V_282 -> V_285 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_281 != V_286 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_282 -> V_26 . V_57 ) )
break;
V_284 = & V_31 -> V_285 ;
}
F_182 ( & V_282 -> V_285 , V_284 ) ;
}
T_9 F_183 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_287 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_282 ;
T_9 V_18 = 0 ;
F_93 ( L_65 , V_47 , & V_26 -> V_40 ) ;
F_184 ( V_2 , & V_26 -> V_40 , V_288 ) ;
if ( ! V_26 -> V_58 )
V_18 |= V_289 ;
V_282 = F_178 ( V_2 , & V_26 -> V_40 ) ;
if ( V_282 ) {
if ( ! V_282 -> V_26 . V_58 )
V_18 |= V_289 ;
if ( V_282 -> V_281 == V_290 &&
V_26 -> V_57 != V_282 -> V_26 . V_57 ) {
V_282 -> V_26 . V_57 = V_26 -> V_57 ;
F_181 ( V_2 , V_282 ) ;
}
goto V_291;
}
V_282 = F_185 ( sizeof( * V_282 ) , V_292 ) ;
if ( ! V_282 ) {
V_18 |= V_293 ;
goto V_294;
}
F_182 ( & V_282 -> V_278 , & V_47 -> V_278 ) ;
if ( V_287 ) {
V_282 -> V_281 = V_295 ;
} else {
V_282 -> V_281 = V_296 ;
F_182 ( & V_282 -> V_285 , & V_47 -> V_279 ) ;
}
V_291:
if ( V_287 && V_282 -> V_281 != V_295 &&
V_282 -> V_281 != V_286 ) {
V_282 -> V_281 = V_295 ;
F_175 ( & V_282 -> V_285 ) ;
}
memcpy ( & V_282 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_282 -> V_59 = V_297 ;
V_47 -> V_59 = V_297 ;
if ( V_282 -> V_281 == V_296 )
V_18 |= V_293 ;
V_294:
return V_18 ;
}
static int F_186 ( struct V_1 * V_2 , int V_298 , T_12 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_299 * V_300 = (struct V_299 * ) V_9 ;
struct V_49 * V_50 ;
int V_301 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_301 >= V_298 )
break;
F_149 ( & V_300 -> V_40 , & V_26 -> V_40 ) ;
V_300 -> V_52 = V_26 -> V_52 ;
V_300 -> V_53 = V_26 -> V_53 ;
V_300 -> V_54 = V_26 -> V_54 ;
memcpy ( V_300 -> V_55 , V_26 -> V_55 , 3 ) ;
V_300 -> V_56 = V_26 -> V_56 ;
V_300 ++ ;
V_301 ++ ;
}
F_93 ( L_67 , V_47 , V_301 ) ;
return V_301 ;
}
static void F_187 ( struct V_124 * V_125 , unsigned long V_130 )
{
struct V_302 * V_303 = (struct V_302 * ) V_130 ;
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_304 V_180 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( F_4 ( V_305 , & V_2 -> V_18 ) )
return;
memcpy ( & V_180 . V_306 , & V_303 -> V_306 , 3 ) ;
V_180 . V_307 = V_303 -> V_307 ;
V_180 . V_308 = V_303 -> V_308 ;
F_115 ( V_125 , V_309 , sizeof( V_180 ) , & V_180 ) ;
}
int F_188 ( void T_2 * V_310 )
{
T_12 T_2 * V_29 = V_310 ;
struct V_302 V_303 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_311 = 0 , V_312 ;
long V_313 ;
T_12 * V_9 ;
if ( F_8 ( & V_303 , V_29 , sizeof( V_303 ) ) )
return - V_20 ;
V_2 = F_165 ( V_303 . V_314 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_16 = - V_67 ;
goto V_294;
}
if ( F_4 ( V_317 , & V_2 -> V_70 ) ) {
V_16 = - V_318 ;
goto V_294;
}
if ( V_2 -> V_146 != V_147 ) {
V_16 = - V_318 ;
goto V_294;
}
if ( ! F_4 ( V_175 , & V_2 -> V_70 ) ) {
V_16 = - V_318 ;
goto V_294;
}
F_19 ( V_2 ) ;
if ( F_189 ( V_2 ) > V_319 ||
F_190 ( V_2 ) || V_303 . V_18 & V_320 ) {
F_173 ( V_2 ) ;
V_311 = 1 ;
}
F_22 ( V_2 ) ;
V_313 = V_303 . V_307 * F_191 ( 2000 ) ;
if ( V_311 ) {
V_16 = F_112 ( V_2 , F_187 , ( unsigned long ) & V_303 ,
V_313 ) ;
if ( V_16 < 0 )
goto V_294;
if ( F_192 ( & V_2 -> V_18 , V_305 ,
V_126 ) )
return - V_128 ;
}
V_312 = ( V_303 . V_308 == 0 ) ? 255 : V_303 . V_308 ;
V_9 = F_193 ( sizeof( struct V_299 ) * V_312 , V_292 ) ;
if ( ! V_9 ) {
V_16 = - V_321 ;
goto V_294;
}
F_19 ( V_2 ) ;
V_303 . V_308 = F_186 ( V_2 , V_312 , V_9 ) ;
F_22 ( V_2 ) ;
F_93 ( L_68 , V_303 . V_308 ) ;
if ( ! F_194 ( V_29 , & V_303 , sizeof( V_303 ) ) ) {
V_29 += sizeof( V_303 ) ;
if ( F_194 ( V_29 , V_9 , sizeof( struct V_299 ) *
V_303 . V_308 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_176 ( V_9 ) ;
V_294:
F_195 ( V_2 ) ;
return V_16 ;
}
static int F_196 ( struct V_1 * V_2 )
{
int V_131 = 0 ;
F_93 ( L_69 , V_2 -> V_100 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_322 , & V_2 -> V_70 ) ) {
V_131 = - V_315 ;
goto V_294;
}
if ( ! F_4 ( V_221 , & V_2 -> V_70 ) &&
! F_4 ( V_323 , & V_2 -> V_70 ) ) {
if ( F_4 ( V_324 , & V_2 -> V_70 ) ) {
V_131 = - V_325 ;
goto V_294;
}
if ( ! F_4 ( V_316 , & V_2 -> V_70 ) &&
V_2 -> V_146 == V_147 &&
! F_157 ( & V_2 -> V_40 , V_206 ) &&
! F_157 ( & V_2 -> V_82 , V_206 ) ) {
V_131 = - V_326 ;
goto V_294;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_131 = - V_22 ;
goto V_294;
}
if ( V_2 -> V_327 ( V_2 ) ) {
V_131 = - V_328 ;
goto V_294;
}
F_197 ( & V_2 -> V_329 , 1 ) ;
F_114 ( V_330 , & V_2 -> V_18 ) ;
if ( F_4 ( V_221 , & V_2 -> V_70 ) ) {
if ( V_2 -> V_331 )
V_131 = V_2 -> V_331 ( V_2 ) ;
if ( F_4 ( V_332 , & V_2 -> V_145 ) ||
F_4 ( V_333 , & V_2 -> V_145 ) )
F_114 ( V_317 , & V_2 -> V_70 ) ;
if ( F_4 ( V_317 , & V_2 -> V_70 ) )
V_131 = F_160 ( V_2 ) ;
}
if ( F_4 ( V_323 , & V_2 -> V_70 ) ) {
if ( F_157 ( & V_2 -> V_334 , V_206 ) &&
V_2 -> V_258 )
V_131 = V_2 -> V_258 ( V_2 , & V_2 -> V_334 ) ;
else
V_131 = - V_326 ;
}
if ( ! V_131 ) {
if ( ! F_4 ( V_317 , & V_2 -> V_70 ) &&
! F_4 ( V_316 , & V_2 -> V_70 ) )
V_131 = F_153 ( V_2 ) ;
}
F_134 ( V_330 , & V_2 -> V_18 ) ;
if ( ! V_131 ) {
F_167 ( V_2 ) ;
F_114 ( V_335 , & V_2 -> V_70 ) ;
F_114 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_336 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_70 ) &&
! F_4 ( V_323 , & V_2 -> V_70 ) &&
! F_4 ( V_317 , & V_2 -> V_70 ) &&
! F_4 ( V_316 , & V_2 -> V_70 ) &&
V_2 -> V_146 == V_147 ) {
F_19 ( V_2 ) ;
F_198 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_199 ( & V_2 -> V_337 ) ;
F_199 ( & V_2 -> V_338 ) ;
F_199 ( & V_2 -> V_339 ) ;
F_200 ( & V_2 -> V_340 ) ;
F_200 ( & V_2 -> V_341 ) ;
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_2 ) ;
if ( V_2 -> V_343 ) {
F_16 ( V_2 -> V_343 ) ;
V_2 -> V_343 = NULL ;
}
V_2 -> V_344 ( V_2 ) ;
V_2 -> V_18 &= F_201 ( V_345 ) ;
}
V_294:
F_12 ( V_2 ) ;
return V_131 ;
}
int F_202 ( T_13 V_346 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_165 ( V_346 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_317 , & V_2 -> V_70 ) &&
! F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_16 = - V_318 ;
goto V_294;
}
if ( F_203 ( V_347 , & V_2 -> V_70 ) )
F_204 ( & V_2 -> V_348 ) ;
F_205 ( V_2 -> V_349 ) ;
if ( ! F_4 ( V_316 , & V_2 -> V_70 ) &&
! F_4 ( V_350 , & V_2 -> V_70 ) )
F_114 ( V_351 , & V_2 -> V_70 ) ;
V_16 = F_196 ( V_2 ) ;
V_294:
F_195 ( V_2 ) ;
return V_16 ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_97 * V_31 ;
F_26 (p, &hdev->le_conn_params, list) {
if ( V_31 -> V_352 ) {
F_207 ( V_31 -> V_352 ) ;
F_208 ( V_31 -> V_352 ) ;
V_31 -> V_352 = NULL ;
}
F_209 ( & V_31 -> V_353 ) ;
}
F_93 ( L_70 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
F_93 ( L_69 , V_2 -> V_100 , V_2 ) ;
F_204 ( & V_2 -> V_348 ) ;
F_95 ( V_2 , V_315 ) ;
F_10 ( V_2 ) ;
if ( ! F_203 ( V_17 , & V_2 -> V_18 ) ) {
F_211 ( & V_2 -> V_354 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_199 ( & V_2 -> V_337 ) ;
F_199 ( & V_2 -> V_339 ) ;
if ( V_2 -> V_355 > 0 ) {
F_204 ( & V_2 -> V_356 ) ;
V_2 -> V_355 = 0 ;
F_134 ( V_357 , & V_2 -> V_70 ) ;
F_134 ( V_358 , & V_2 -> V_70 ) ;
}
if ( F_203 ( V_359 , & V_2 -> V_70 ) )
F_204 ( & V_2 -> V_360 ) ;
F_211 ( & V_2 -> V_361 ) ;
if ( F_4 ( V_350 , & V_2 -> V_70 ) )
F_211 ( & V_2 -> V_362 ) ;
F_212 ( V_2 -> V_363 ) ;
F_19 ( V_2 ) ;
if ( ! F_203 ( V_347 , & V_2 -> V_70 ) ) {
if ( V_2 -> V_146 == V_147 )
F_198 ( V_2 , 0 ) ;
}
F_173 ( V_2 ) ;
F_206 ( V_2 ) ;
F_213 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_364 ) ;
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_2 ) ;
F_200 ( & V_2 -> V_340 ) ;
F_197 ( & V_2 -> V_329 , 1 ) ;
if ( ! F_4 ( V_347 , & V_2 -> V_70 ) &&
! F_4 ( V_317 , & V_2 -> V_70 ) &&
F_4 ( V_144 , & V_2 -> V_145 ) ) {
F_114 ( V_330 , & V_2 -> V_18 ) ;
F_110 ( V_2 , F_113 , 0 , V_24 ) ;
F_134 ( V_330 , & V_2 -> V_18 ) ;
}
F_199 ( & V_2 -> V_338 ) ;
F_200 ( & V_2 -> V_341 ) ;
F_200 ( & V_2 -> V_340 ) ;
F_200 ( & V_2 -> V_365 ) ;
if ( V_2 -> V_343 ) {
F_211 ( & V_2 -> V_354 ) ;
F_16 ( V_2 -> V_343 ) ;
V_2 -> V_343 = NULL ;
}
F_16 ( V_2 -> V_112 ) ;
V_2 -> V_112 = NULL ;
V_2 -> V_344 ( V_2 ) ;
V_2 -> V_18 &= F_201 ( V_345 ) ;
V_2 -> V_70 &= ~ V_366 ;
V_2 -> V_367 = V_368 ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_149 ( & V_2 -> V_81 , V_206 ) ;
F_12 ( V_2 ) ;
F_195 ( V_2 ) ;
return 0 ;
}
int F_214 ( T_13 V_346 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_165 ( V_346 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_16 = - V_67 ;
goto V_294;
}
if ( F_203 ( V_347 , & V_2 -> V_70 ) )
F_204 ( & V_2 -> V_348 ) ;
V_16 = F_210 ( V_2 ) ;
V_294:
F_195 ( V_2 ) ;
return V_16 ;
}
int F_215 ( T_13 V_346 )
{
struct V_1 * V_2 ;
int V_131 = 0 ;
V_2 = F_165 ( V_346 ) ;
if ( ! V_2 )
return - V_315 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_131 = - V_19 ;
goto V_294;
}
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_131 = - V_67 ;
goto V_294;
}
if ( F_4 ( V_317 , & V_2 -> V_70 ) ) {
V_131 = - V_318 ;
goto V_294;
}
F_200 ( & V_2 -> V_341 ) ;
F_200 ( & V_2 -> V_340 ) ;
F_212 ( V_2 -> V_363 ) ;
F_19 ( V_2 ) ;
F_173 ( V_2 ) ;
F_213 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_342 )
V_2 -> V_342 ( V_2 ) ;
F_197 ( & V_2 -> V_329 , 1 ) ;
V_2 -> V_369 = 0 ; V_2 -> V_370 = 0 ; V_2 -> V_371 = 0 ;
V_131 = F_110 ( V_2 , F_113 , 0 , V_220 ) ;
V_294:
F_12 ( V_2 ) ;
F_195 ( V_2 ) ;
return V_131 ;
}
int F_216 ( T_13 V_346 )
{
struct V_1 * V_2 ;
int V_131 = 0 ;
V_2 = F_165 ( V_346 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_131 = - V_67 ;
goto V_294;
}
if ( F_4 ( V_317 , & V_2 -> V_70 ) ) {
V_131 = - V_318 ;
goto V_294;
}
memset ( & V_2 -> V_372 , 0 , sizeof( struct V_373 ) ) ;
V_294:
F_195 ( V_2 ) ;
return V_131 ;
}
static void F_217 ( struct V_1 * V_2 , T_5 V_260 )
{
bool V_374 , V_375 ;
F_93 ( L_71 , V_2 -> V_100 , V_260 ) ;
if ( ( V_260 & V_376 ) )
V_374 = ! F_218 ( V_377 ,
& V_2 -> V_70 ) ;
else
V_374 = F_203 ( V_377 ,
& V_2 -> V_70 ) ;
if ( ( V_260 & V_378 ) ) {
V_375 = ! F_218 ( V_357 ,
& V_2 -> V_70 ) ;
} else {
F_134 ( V_358 , & V_2 -> V_70 ) ;
V_375 = F_203 ( V_357 ,
& V_2 -> V_70 ) ;
}
if ( ! F_4 ( V_350 , & V_2 -> V_70 ) )
return;
if ( V_374 || V_375 ) {
F_114 ( V_175 , & V_2 -> V_70 ) ;
if ( F_4 ( V_164 , & V_2 -> V_70 ) )
F_219 ( V_2 ) ;
F_220 ( V_2 ) ;
}
}
int F_221 ( unsigned int V_379 , void T_2 * V_310 )
{
struct V_1 * V_2 ;
struct V_380 V_381 ;
int V_16 = 0 ;
if ( F_8 ( & V_381 , V_310 , sizeof( V_381 ) ) )
return - V_20 ;
V_2 = F_165 ( V_381 . V_314 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
V_16 = - V_67 ;
goto V_294;
}
if ( F_4 ( V_317 , & V_2 -> V_70 ) ) {
V_16 = - V_318 ;
goto V_294;
}
if ( V_2 -> V_146 != V_147 ) {
V_16 = - V_318 ;
goto V_294;
}
if ( ! F_4 ( V_175 , & V_2 -> V_70 ) ) {
V_16 = - V_318 ;
goto V_294;
}
switch ( V_379 ) {
case V_382 :
V_16 = F_112 ( V_2 , F_162 , V_381 . V_383 ,
V_220 ) ;
break;
case V_384 :
if ( ! F_222 ( V_2 ) ) {
V_16 = - V_318 ;
break;
}
if ( ! F_4 ( V_385 , & V_2 -> V_18 ) ) {
V_16 = F_112 ( V_2 , F_162 , V_381 . V_383 ,
V_220 ) ;
if ( V_16 )
break;
}
V_16 = F_112 ( V_2 , F_163 , V_381 . V_383 ,
V_220 ) ;
break;
case V_386 :
V_16 = F_112 ( V_2 , F_161 , V_381 . V_383 ,
V_220 ) ;
if ( ! V_16 )
F_217 ( V_2 , V_381 . V_383 ) ;
break;
case V_387 :
V_16 = F_112 ( V_2 , F_164 , V_381 . V_383 ,
V_220 ) ;
break;
case V_388 :
V_2 -> V_389 = ( ( T_13 ) V_381 . V_383 ) &
( V_390 | V_391 ) ;
break;
case V_392 :
V_2 -> V_393 = ( T_13 ) V_381 . V_383 ;
break;
case V_394 :
V_2 -> V_395 = * ( ( T_13 * ) & V_381 . V_383 + 1 ) ;
V_2 -> V_396 = * ( ( T_13 * ) & V_381 . V_383 + 0 ) ;
break;
case V_397 :
V_2 -> V_398 = * ( ( T_13 * ) & V_381 . V_383 + 1 ) ;
V_2 -> V_399 = * ( ( T_13 * ) & V_381 . V_383 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_294:
F_195 ( V_2 ) ;
return V_16 ;
}
int F_223 ( void T_2 * V_310 )
{
struct V_1 * V_2 ;
struct V_400 * V_401 ;
struct V_380 * V_381 ;
int V_277 = 0 , V_402 , V_16 ;
T_13 V_403 ;
if ( F_224 ( V_403 , ( T_13 T_2 * ) V_310 ) )
return - V_20 ;
if ( ! V_403 || V_403 > ( V_404 * 2 ) / sizeof( * V_381 ) )
return - V_21 ;
V_402 = sizeof( * V_401 ) + V_403 * sizeof( * V_381 ) ;
V_401 = F_185 ( V_402 , V_292 ) ;
if ( ! V_401 )
return - V_321 ;
V_381 = V_401 -> V_405 ;
F_166 ( & V_267 ) ;
F_26 (hdev, &hci_dev_list, list) {
unsigned long V_18 = V_2 -> V_18 ;
if ( F_4 ( V_347 , & V_2 -> V_70 ) )
V_18 &= ~ F_201 ( V_17 ) ;
( V_381 + V_277 ) -> V_314 = V_2 -> V_268 ;
( V_381 + V_277 ) -> V_383 = V_18 ;
if ( ++ V_277 >= V_403 )
break;
}
F_168 ( & V_267 ) ;
V_401 -> V_403 = V_277 ;
V_402 = sizeof( * V_401 ) + V_277 * sizeof( * V_381 ) ;
V_16 = F_194 ( V_310 , V_401 , V_402 ) ;
F_176 ( V_401 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_225 ( void T_2 * V_310 )
{
struct V_1 * V_2 ;
struct V_406 V_407 ;
unsigned long V_18 ;
int V_16 = 0 ;
if ( F_8 ( & V_407 , V_310 , sizeof( V_407 ) ) )
return - V_20 ;
V_2 = F_165 ( V_407 . V_314 ) ;
if ( ! V_2 )
return - V_315 ;
if ( F_4 ( V_347 , & V_2 -> V_70 ) )
V_18 = V_2 -> V_18 & ~ F_201 ( V_17 ) ;
else
V_18 = V_2 -> V_18 ;
strcpy ( V_407 . V_100 , V_2 -> V_100 ) ;
V_407 . V_40 = V_2 -> V_40 ;
V_407 . type = ( V_2 -> V_408 & 0x0f ) | ( ( V_2 -> V_146 & 0x03 ) << 4 ) ;
V_407 . V_18 = V_18 ;
V_407 . V_393 = V_2 -> V_393 ;
if ( F_122 ( V_2 ) ) {
V_407 . V_395 = V_2 -> V_395 ;
V_407 . V_396 = V_2 -> V_396 ;
V_407 . V_398 = V_2 -> V_398 ;
V_407 . V_399 = V_2 -> V_399 ;
} else {
V_407 . V_395 = V_2 -> V_409 ;
V_407 . V_396 = V_2 -> V_410 ;
V_407 . V_398 = 0 ;
V_407 . V_399 = 0 ;
}
V_407 . V_190 = V_2 -> V_190 ;
V_407 . V_389 = V_2 -> V_389 ;
memcpy ( & V_407 . V_372 , & V_2 -> V_372 , sizeof( V_407 . V_372 ) ) ;
memcpy ( & V_407 . V_34 , & V_2 -> V_34 , sizeof( V_407 . V_34 ) ) ;
if ( F_194 ( V_310 , & V_407 , sizeof( V_407 ) ) )
V_16 = - V_20 ;
F_195 ( V_2 ) ;
return V_16 ;
}
static int F_226 ( void * V_26 , bool V_411 )
{
struct V_1 * V_2 = V_26 ;
F_93 ( L_72 , V_2 , V_2 -> V_100 , V_411 ) ;
if ( F_4 ( V_316 , & V_2 -> V_70 ) )
return - V_67 ;
if ( V_411 ) {
F_114 ( V_324 , & V_2 -> V_70 ) ;
if ( ! F_4 ( V_221 , & V_2 -> V_70 ) &&
! F_4 ( V_323 , & V_2 -> V_70 ) )
F_210 ( V_2 ) ;
} else {
F_134 ( V_324 , & V_2 -> V_70 ) ;
}
return 0 ;
}
static void F_227 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 , V_414 ) ;
int V_16 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
V_16 = F_196 ( V_2 ) ;
if ( V_16 < 0 ) {
F_19 ( V_2 ) ;
F_229 ( V_2 , V_16 ) ;
F_22 ( V_2 ) ;
return;
}
if ( F_4 ( V_324 , & V_2 -> V_70 ) ||
F_4 ( V_317 , & V_2 -> V_70 ) ||
( V_2 -> V_146 == V_147 &&
! F_157 ( & V_2 -> V_40 , V_206 ) &&
! F_157 ( & V_2 -> V_82 , V_206 ) ) ) {
F_134 ( V_347 , & V_2 -> V_70 ) ;
F_210 ( V_2 ) ;
} else if ( F_4 ( V_347 , & V_2 -> V_70 ) ) {
F_230 ( V_2 -> V_349 , & V_2 -> V_348 ,
V_415 ) ;
}
if ( F_203 ( V_221 , & V_2 -> V_70 ) ) {
if ( F_4 ( V_317 , & V_2 -> V_70 ) )
F_114 ( V_345 , & V_2 -> V_18 ) ;
F_231 ( V_2 ) ;
} else if ( F_203 ( V_323 , & V_2 -> V_70 ) ) {
if ( ! F_4 ( V_317 , & V_2 -> V_70 ) )
F_134 ( V_345 , & V_2 -> V_18 ) ;
F_231 ( V_2 ) ;
}
}
static void F_232 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 ,
V_348 . V_413 ) ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_210 ( V_2 ) ;
}
static void F_233 ( struct V_412 * V_413 )
{
struct V_1 * V_2 ;
V_2 = F_228 ( V_413 , struct V_1 , V_356 . V_413 ) ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_234 ( V_2 ) ;
}
void F_235 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_416 ;
F_174 (uuid, tmp, &hdev->uuids, list) {
F_175 ( & V_43 -> V_285 ) ;
F_176 ( V_43 ) ;
}
}
void F_236 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
F_35 (key, &hdev->link_keys, list) {
F_237 ( & V_61 -> V_285 ) ;
F_238 ( V_61 , V_417 ) ;
}
}
void F_239 ( struct V_1 * V_2 )
{
struct V_85 * V_418 ;
F_35 (k, &hdev->long_term_keys, list) {
F_237 ( & V_418 -> V_285 ) ;
F_238 ( V_418 , V_417 ) ;
}
}
void F_240 ( struct V_1 * V_2 )
{
struct V_84 * V_418 ;
F_35 (k, &hdev->identity_resolving_keys, list) {
F_237 ( & V_418 -> V_285 ) ;
F_238 ( V_418 , V_417 ) ;
}
}
struct V_60 * F_241 ( struct V_1 * V_2 , T_7 * V_40 )
{
struct V_60 * V_418 ;
F_34 () ;
F_35 (k, &hdev->link_keys, list) {
if ( F_157 ( V_40 , & V_418 -> V_40 ) == 0 ) {
F_36 () ;
return V_418 ;
}
}
F_36 () ;
return NULL ;
}
static bool F_242 ( struct V_1 * V_2 , struct V_419 * V_352 ,
T_5 V_420 , T_5 V_421 )
{
if ( V_420 < 0x03 )
return true ;
if ( V_420 == V_422 )
return false ;
if ( V_420 == V_423 && V_421 == 0xff )
return false ;
if ( ! V_352 )
return true ;
if ( V_352 -> type == V_424 )
return true ;
if ( V_352 -> V_425 > 0x01 && V_352 -> V_426 > 0x01 )
return true ;
if ( V_352 -> V_425 == 0x02 || V_352 -> V_425 == 0x03 )
return true ;
if ( V_352 -> V_426 == 0x02 || V_352 -> V_426 == 0x03 )
return true ;
return false ;
}
static T_5 F_243 ( T_5 type )
{
if ( type == V_427 )
return V_428 ;
return V_429 ;
}
struct V_85 * F_244 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_78 , T_5 V_430 )
{
struct V_85 * V_418 ;
F_34 () ;
F_35 (k, &hdev->long_term_keys, list) {
if ( V_78 != V_418 -> V_41 || F_157 ( V_40 , & V_418 -> V_40 ) )
continue;
if ( F_245 ( V_418 ) || F_243 ( V_418 -> type ) == V_430 ) {
F_36 () ;
return V_418 ;
}
}
F_36 () ;
return NULL ;
}
struct V_84 * F_246 ( struct V_1 * V_2 , T_7 * V_80 )
{
struct V_84 * V_79 ;
F_34 () ;
F_35 (irk, &hdev->identity_resolving_keys, list) {
if ( ! F_157 ( & V_79 -> V_80 , V_80 ) ) {
F_36 () ;
return V_79 ;
}
}
F_35 (irk, &hdev->identity_resolving_keys, list) {
if ( F_247 ( V_2 , V_79 -> V_45 , V_80 ) ) {
F_149 ( & V_79 -> V_80 , V_80 ) ;
F_36 () ;
return V_79 ;
}
}
F_36 () ;
return NULL ;
}
struct V_84 * F_248 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_78 )
{
struct V_84 * V_79 ;
if ( V_78 == V_431 && ( V_40 -> V_39 [ 5 ] & 0xc0 ) != 0xc0 )
return NULL ;
F_34 () ;
F_35 (irk, &hdev->identity_resolving_keys, list) {
if ( V_78 == V_79 -> V_78 &&
F_157 ( V_40 , & V_79 -> V_40 ) == 0 ) {
F_36 () ;
return V_79 ;
}
}
F_36 () ;
return NULL ;
}
struct V_60 * F_249 ( struct V_1 * V_2 , struct V_419 * V_352 ,
T_7 * V_40 , T_5 * V_45 , T_5 type ,
T_5 V_63 , bool * V_432 )
{
struct V_60 * V_61 , * V_433 ;
T_5 V_421 ;
V_433 = F_241 ( V_2 , V_40 ) ;
if ( V_433 ) {
V_421 = V_433 -> type ;
V_61 = V_433 ;
} else {
V_421 = V_352 ? V_352 -> V_420 : 0xff ;
V_61 = F_185 ( sizeof( * V_61 ) , V_292 ) ;
if ( ! V_61 )
return NULL ;
F_250 ( & V_61 -> V_285 , & V_2 -> V_434 ) ;
}
F_93 ( L_73 , V_2 -> V_100 , V_40 , type ) ;
if ( type == V_423 &&
( ! V_352 || V_352 -> V_426 == 0xff ) && V_421 == 0xff ) {
type = V_435 ;
if ( V_352 )
V_352 -> V_420 = type ;
}
F_149 ( & V_61 -> V_40 , V_40 ) ;
memcpy ( V_61 -> V_45 , V_45 , V_62 ) ;
V_61 -> V_63 = V_63 ;
if ( type == V_423 )
V_61 -> type = V_421 ;
else
V_61 -> type = type ;
if ( V_432 )
* V_432 = F_242 ( V_2 , V_352 , type ,
V_421 ) ;
return V_61 ;
}
struct V_85 * F_251 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_78 , T_5 type , T_5 V_87 ,
T_5 V_436 [ 16 ] , T_5 V_88 , T_11 V_89 , T_14 rand )
{
struct V_85 * V_61 , * V_433 ;
T_5 V_430 = F_243 ( type ) ;
V_433 = F_244 ( V_2 , V_40 , V_78 , V_430 ) ;
if ( V_433 )
V_61 = V_433 ;
else {
V_61 = F_185 ( sizeof( * V_61 ) , V_292 ) ;
if ( ! V_61 )
return NULL ;
F_250 ( & V_61 -> V_285 , & V_2 -> V_437 ) ;
}
F_149 ( & V_61 -> V_40 , V_40 ) ;
V_61 -> V_41 = V_78 ;
memcpy ( V_61 -> V_45 , V_436 , sizeof( V_61 -> V_45 ) ) ;
V_61 -> V_87 = V_87 ;
V_61 -> V_89 = V_89 ;
V_61 -> rand = rand ;
V_61 -> V_88 = V_88 ;
V_61 -> type = type ;
return V_61 ;
}
struct V_84 * F_252 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_78 , T_5 V_45 [ 16 ] , T_7 * V_80 )
{
struct V_84 * V_79 ;
V_79 = F_248 ( V_2 , V_40 , V_78 ) ;
if ( ! V_79 ) {
V_79 = F_185 ( sizeof( * V_79 ) , V_292 ) ;
if ( ! V_79 )
return NULL ;
F_149 ( & V_79 -> V_40 , V_40 ) ;
V_79 -> V_78 = V_78 ;
F_250 ( & V_79 -> V_285 , & V_2 -> V_438 ) ;
}
memcpy ( V_79 -> V_45 , V_45 , 16 ) ;
F_149 ( & V_79 -> V_80 , V_80 ) ;
return V_79 ;
}
int F_253 ( struct V_1 * V_2 , T_7 * V_40 )
{
struct V_60 * V_61 ;
V_61 = F_241 ( V_2 , V_40 ) ;
if ( ! V_61 )
return - V_439 ;
F_93 ( L_74 , V_2 -> V_100 , V_40 ) ;
F_237 ( & V_61 -> V_285 ) ;
F_238 ( V_61 , V_417 ) ;
return 0 ;
}
int F_254 ( struct V_1 * V_2 , T_7 * V_40 , T_5 V_41 )
{
struct V_85 * V_418 ;
int V_440 = 0 ;
F_35 (k, &hdev->long_term_keys, list) {
if ( F_157 ( V_40 , & V_418 -> V_40 ) || V_418 -> V_41 != V_41 )
continue;
F_93 ( L_74 , V_2 -> V_100 , V_40 ) ;
F_237 ( & V_418 -> V_285 ) ;
F_238 ( V_418 , V_417 ) ;
V_440 ++ ;
}
return V_440 ? 0 : - V_439 ;
}
void F_255 ( struct V_1 * V_2 , T_7 * V_40 , T_5 V_78 )
{
struct V_84 * V_418 ;
F_35 (k, &hdev->identity_resolving_keys, list) {
if ( F_157 ( V_40 , & V_418 -> V_40 ) || V_418 -> V_78 != V_78 )
continue;
F_93 ( L_74 , V_2 -> V_100 , V_40 ) ;
F_237 ( & V_418 -> V_285 ) ;
F_238 ( V_418 , V_417 ) ;
}
}
static void F_256 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 ,
V_354 . V_413 ) ;
if ( V_2 -> V_343 ) {
struct V_441 * V_442 = ( void * ) V_2 -> V_343 -> V_26 ;
T_8 V_107 = F_31 ( V_442 -> V_107 ) ;
F_98 ( L_75 , V_2 -> V_100 , V_107 ) ;
} else {
F_98 ( L_76 , V_2 -> V_100 ) ;
}
F_197 ( & V_2 -> V_329 , 1 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_338 ) ;
}
struct V_443 * F_258 ( struct V_1 * V_2 ,
T_7 * V_40 , T_5 V_41 )
{
struct V_443 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list) {
if ( F_157 ( V_40 , & V_26 -> V_40 ) != 0 )
continue;
if ( V_26 -> V_41 != V_41 )
continue;
return V_26 ;
}
return NULL ;
}
int F_184 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_41 )
{
struct V_443 * V_26 ;
V_26 = F_258 ( V_2 , V_40 , V_41 ) ;
if ( ! V_26 )
return - V_439 ;
F_93 ( L_77 , V_2 -> V_100 , V_40 , V_41 ) ;
F_175 ( & V_26 -> V_285 ) ;
F_176 ( V_26 ) ;
return 0 ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_443 * V_26 , * V_277 ;
F_174 (data, n, &hdev->remote_oob_data, list) {
F_175 ( & V_26 -> V_285 ) ;
F_176 ( V_26 ) ;
}
}
int F_260 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 V_41 , T_5 * V_444 , T_5 * V_445 ,
T_5 * V_446 , T_5 * V_447 )
{
struct V_443 * V_26 ;
V_26 = F_258 ( V_2 , V_40 , V_41 ) ;
if ( ! V_26 ) {
V_26 = F_193 ( sizeof( * V_26 ) , V_292 ) ;
if ( ! V_26 )
return - V_321 ;
F_149 ( & V_26 -> V_40 , V_40 ) ;
V_26 -> V_41 = V_41 ;
F_182 ( & V_26 -> V_285 , & V_2 -> V_448 ) ;
}
if ( V_444 && V_445 ) {
memcpy ( V_26 -> V_444 , V_444 , sizeof( V_26 -> V_444 ) ) ;
memcpy ( V_26 -> V_445 , V_445 , sizeof( V_26 -> V_445 ) ) ;
} else {
memset ( V_26 -> V_444 , 0 , sizeof( V_26 -> V_444 ) ) ;
memset ( V_26 -> V_445 , 0 , sizeof( V_26 -> V_445 ) ) ;
}
if ( V_446 && V_447 ) {
memcpy ( V_26 -> V_446 , V_446 , sizeof( V_26 -> V_446 ) ) ;
memcpy ( V_26 -> V_447 , V_447 , sizeof( V_26 -> V_447 ) ) ;
} else {
memset ( V_26 -> V_446 , 0 , sizeof( V_26 -> V_446 ) ) ;
memset ( V_26 -> V_447 , 0 , sizeof( V_26 -> V_447 ) ) ;
}
F_93 ( L_78 , V_2 -> V_100 , V_40 ) ;
return 0 ;
}
struct V_38 * F_261 ( struct V_283 * V_38 ,
T_7 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, bdaddr_list, list) {
if ( ! F_157 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
void F_262 ( struct V_283 * V_38 )
{
struct V_283 * V_31 , * V_277 ;
F_263 (p, n, bdaddr_list) {
struct V_38 * V_39 = F_264 ( V_31 , struct V_38 , V_285 ) ;
F_175 ( V_31 ) ;
F_176 ( V_39 ) ;
}
}
int F_265 ( struct V_283 * V_285 , T_7 * V_40 , T_5 type )
{
struct V_38 * V_449 ;
if ( ! F_157 ( V_40 , V_206 ) )
return - V_450 ;
if ( F_261 ( V_285 , V_40 , type ) )
return - V_451 ;
V_449 = F_185 ( sizeof( * V_449 ) , V_292 ) ;
if ( ! V_449 )
return - V_321 ;
F_149 ( & V_449 -> V_40 , V_40 ) ;
V_449 -> V_41 = type ;
F_182 ( & V_449 -> V_285 , V_285 ) ;
return 0 ;
}
int F_266 ( struct V_283 * V_285 , T_7 * V_40 , T_5 type )
{
struct V_38 * V_449 ;
if ( ! F_157 ( V_40 , V_206 ) ) {
F_262 ( V_285 ) ;
return 0 ;
}
V_449 = F_261 ( V_285 , V_40 , type ) ;
if ( ! V_449 )
return - V_439 ;
F_175 ( & V_449 -> V_285 ) ;
F_176 ( V_449 ) ;
return 0 ;
}
struct V_97 * F_267 ( struct V_1 * V_2 ,
T_7 * V_77 , T_5 V_78 )
{
struct V_97 * V_452 ;
if ( ! F_268 ( V_77 , V_78 ) )
return NULL ;
F_26 (params, &hdev->le_conn_params, list) {
if ( F_157 ( & V_452 -> V_77 , V_77 ) == 0 &&
V_452 -> V_78 == V_78 ) {
return V_452 ;
}
}
return NULL ;
}
static bool F_269 ( struct V_1 * V_2 , T_7 * V_77 , T_5 type )
{
struct V_419 * V_352 ;
V_352 = F_270 ( V_2 , V_424 , V_77 ) ;
if ( ! V_352 )
return false ;
if ( V_352 -> V_453 != type )
return false ;
if ( V_352 -> V_270 != V_454 )
return false ;
return true ;
}
struct V_97 * F_271 ( struct V_283 * V_285 ,
T_7 * V_77 , T_5 V_78 )
{
struct V_97 * V_120 ;
if ( ! F_268 ( V_77 , V_78 ) )
return NULL ;
F_26 (param, list, action) {
if ( F_157 ( & V_120 -> V_77 , V_77 ) == 0 &&
V_120 -> V_78 == V_78 )
return V_120 ;
}
return NULL ;
}
struct V_97 * F_272 ( struct V_1 * V_2 ,
T_7 * V_77 , T_5 V_78 )
{
struct V_97 * V_452 ;
if ( ! F_268 ( V_77 , V_78 ) )
return NULL ;
V_452 = F_267 ( V_2 , V_77 , V_78 ) ;
if ( V_452 )
return V_452 ;
V_452 = F_185 ( sizeof( * V_452 ) , V_292 ) ;
if ( ! V_452 ) {
F_98 ( L_79 ) ;
return NULL ;
}
F_149 ( & V_452 -> V_77 , V_77 ) ;
V_452 -> V_78 = V_78 ;
F_182 ( & V_452 -> V_285 , & V_2 -> V_455 ) ;
F_177 ( & V_452 -> V_353 ) ;
V_452 -> V_456 = V_2 -> V_91 ;
V_452 -> V_457 = V_2 -> V_90 ;
V_452 -> V_458 = V_2 -> V_92 ;
V_452 -> V_459 = V_2 -> V_93 ;
V_452 -> V_98 = V_460 ;
F_93 ( L_80 , V_77 , V_78 ) ;
return V_452 ;
}
int F_273 ( struct V_1 * V_2 , T_7 * V_77 , T_5 V_78 ,
T_5 V_98 )
{
struct V_97 * V_452 ;
V_452 = F_272 ( V_2 , V_77 , V_78 ) ;
if ( ! V_452 )
return - V_328 ;
if ( V_452 -> V_98 == V_98 )
return 0 ;
F_209 ( & V_452 -> V_353 ) ;
switch ( V_98 ) {
case V_460 :
case V_461 :
F_171 ( V_2 ) ;
break;
case V_462 :
F_182 ( & V_452 -> V_353 , & V_2 -> V_463 ) ;
F_171 ( V_2 ) ;
break;
case V_464 :
case V_465 :
if ( ! F_269 ( V_2 , V_77 , V_78 ) ) {
F_182 ( & V_452 -> V_353 , & V_2 -> V_466 ) ;
F_171 ( V_2 ) ;
}
break;
}
V_452 -> V_98 = V_98 ;
F_93 ( L_81 , V_77 , V_78 ,
V_98 ) ;
return 0 ;
}
static void F_274 ( struct V_97 * V_452 )
{
if ( V_452 -> V_352 ) {
F_207 ( V_452 -> V_352 ) ;
F_208 ( V_452 -> V_352 ) ;
}
F_175 ( & V_452 -> V_353 ) ;
F_175 ( & V_452 -> V_285 ) ;
F_176 ( V_452 ) ;
}
void F_275 ( struct V_1 * V_2 , T_7 * V_77 , T_5 V_78 )
{
struct V_97 * V_452 ;
V_452 = F_267 ( V_2 , V_77 , V_78 ) ;
if ( ! V_452 )
return;
F_274 ( V_452 ) ;
F_171 ( V_2 ) ;
F_93 ( L_80 , V_77 , V_78 ) ;
}
void F_276 ( struct V_1 * V_2 )
{
struct V_97 * V_452 , * V_416 ;
F_174 (params, tmp, &hdev->le_conn_params, list) {
if ( V_452 -> V_98 != V_460 )
continue;
F_175 ( & V_452 -> V_285 ) ;
F_176 ( V_452 ) ;
}
F_93 ( L_82 ) ;
}
void F_277 ( struct V_1 * V_2 )
{
struct V_97 * V_452 , * V_416 ;
F_174 (params, tmp, &hdev->le_conn_params, list)
F_274 ( V_452 ) ;
F_171 ( V_2 ) ;
F_93 ( L_83 ) ;
}
static void F_278 ( struct V_1 * V_2 , T_5 V_467 )
{
if ( V_467 ) {
F_98 ( L_84 , V_467 ) ;
F_19 ( V_2 ) ;
F_170 ( V_2 , V_274 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_279 ( struct V_1 * V_2 , T_5 V_467 )
{
T_5 V_306 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_124 V_125 ;
struct V_304 V_180 ;
int V_16 ;
if ( V_467 ) {
F_98 ( L_85 , V_467 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_468 :
F_19 ( V_2 ) ;
F_170 ( V_2 , V_274 ) ;
F_22 ( V_2 ) ;
break;
case V_469 :
F_102 ( & V_125 , V_2 ) ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
memcpy ( & V_180 . V_306 , V_306 , sizeof( V_180 . V_306 ) ) ;
V_180 . V_307 = V_470 ;
F_115 ( & V_125 , V_309 , sizeof( V_180 ) , & V_180 ) ;
F_19 ( V_2 ) ;
F_173 ( V_2 ) ;
V_16 = F_106 ( & V_125 , F_278 ) ;
if ( V_16 ) {
F_98 ( L_86 , V_16 ) ;
F_170 ( V_2 , V_274 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_280 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 ,
V_361 . V_413 ) ;
struct V_124 V_125 ;
int V_16 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_102 ( & V_125 , V_2 ) ;
F_281 ( & V_125 ) ;
V_16 = F_106 ( & V_125 , F_279 ) ;
if ( V_16 )
F_98 ( L_87 , V_16 ) ;
}
static void F_282 ( struct V_124 * V_125 , T_7 * V_80 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
if ( F_4 ( V_471 , & V_2 -> V_70 ) ||
F_283 ( V_2 , V_424 , V_472 ) ) {
F_93 ( L_88 ) ;
F_114 ( V_335 , & V_2 -> V_70 ) ;
return;
}
F_115 ( V_125 , V_473 , 6 , V_80 ) ;
}
int F_284 ( struct V_124 * V_125 , bool V_474 ,
T_5 * V_475 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
int V_16 ;
if ( F_4 ( V_476 , & V_2 -> V_70 ) ) {
int V_477 ;
* V_475 = V_431 ;
if ( ! F_203 ( V_335 , & V_2 -> V_70 ) &&
! F_157 ( & V_2 -> V_81 , & V_2 -> V_80 ) )
return 0 ;
V_16 = F_285 ( V_2 , V_2 -> V_79 , & V_2 -> V_80 ) ;
if ( V_16 < 0 ) {
F_98 ( L_89 , V_2 -> V_100 ) ;
return V_16 ;
}
F_282 ( V_125 , & V_2 -> V_80 ) ;
V_477 = F_191 ( V_2 -> V_72 * 1000 ) ;
F_230 ( V_2 -> V_363 , & V_2 -> V_362 , V_477 ) ;
return 0 ;
}
if ( V_474 ) {
T_7 V_478 ;
while ( true ) {
F_286 ( & V_478 , 6 ) ;
V_478 . V_39 [ 5 ] &= 0x3f ;
if ( F_157 ( & V_2 -> V_40 , & V_478 ) )
break;
}
* V_475 = V_431 ;
F_282 ( V_125 , & V_478 ) ;
return 0 ;
}
if ( F_4 ( V_83 , & V_2 -> V_11 ) ||
! F_157 ( & V_2 -> V_40 , V_206 ) ) {
* V_475 = V_431 ;
if ( F_157 ( & V_2 -> V_82 , & V_2 -> V_81 ) )
F_115 ( V_125 , V_473 , 6 ,
& V_2 -> V_82 ) ;
return 0 ;
}
* V_475 = V_479 ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 , T_7 * V_40 ,
T_5 * V_41 )
{
if ( F_4 ( V_83 , & V_2 -> V_11 ) ||
! F_157 ( & V_2 -> V_40 , V_206 ) ) {
F_149 ( V_40 , & V_2 -> V_82 ) ;
* V_41 = V_431 ;
} else {
F_149 ( V_40 , & V_2 -> V_40 ) ;
* V_41 = V_479 ;
}
}
struct V_1 * F_287 ( void )
{
struct V_1 * V_2 ;
V_2 = F_185 ( sizeof( * V_2 ) , V_292 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_393 = ( V_480 | V_481 | V_482 ) ;
V_2 -> V_483 = ( V_484 ) ;
V_2 -> V_389 = ( V_391 ) ;
V_2 -> V_485 = 0x01 ;
V_2 -> V_486 = 0x03 ;
V_2 -> V_165 = 0xffff ;
V_2 -> V_487 = V_488 ;
V_2 -> V_489 = V_488 ;
V_2 -> V_73 = 800 ;
V_2 -> V_74 = 80 ;
V_2 -> V_94 = 0x07 ;
V_2 -> V_96 = 0x0800 ;
V_2 -> V_95 = 0x0800 ;
V_2 -> V_490 = 0x0060 ;
V_2 -> V_491 = 0x0030 ;
V_2 -> V_91 = 0x0028 ;
V_2 -> V_90 = 0x0038 ;
V_2 -> V_92 = 0x0000 ;
V_2 -> V_93 = 0x002a ;
V_2 -> V_72 = V_492 ;
V_2 -> V_257 = V_493 ;
V_2 -> V_76 = V_494 ;
V_2 -> V_75 = V_495 ;
F_288 ( & V_2 -> V_496 ) ;
F_288 ( & V_2 -> V_497 ) ;
F_177 ( & V_2 -> V_498 ) ;
F_177 ( & V_2 -> V_499 ) ;
F_177 ( & V_2 -> V_500 ) ;
F_177 ( & V_2 -> V_501 ) ;
F_177 ( & V_2 -> V_434 ) ;
F_177 ( & V_2 -> V_437 ) ;
F_177 ( & V_2 -> V_438 ) ;
F_177 ( & V_2 -> V_448 ) ;
F_177 ( & V_2 -> V_502 ) ;
F_177 ( & V_2 -> V_455 ) ;
F_177 ( & V_2 -> V_466 ) ;
F_177 ( & V_2 -> V_463 ) ;
F_177 ( & V_2 -> V_503 . V_285 ) ;
F_289 ( & V_2 -> V_339 , V_504 ) ;
F_289 ( & V_2 -> V_338 , V_505 ) ;
F_289 ( & V_2 -> V_337 , V_506 ) ;
F_289 ( & V_2 -> V_414 , F_227 ) ;
F_290 ( & V_2 -> V_348 , F_232 ) ;
F_290 ( & V_2 -> V_356 , F_233 ) ;
F_290 ( & V_2 -> V_361 , F_280 ) ;
F_291 ( & V_2 -> V_341 ) ;
F_291 ( & V_2 -> V_340 ) ;
F_291 ( & V_2 -> V_365 ) ;
F_292 ( & V_2 -> V_105 ) ;
F_290 ( & V_2 -> V_354 , F_256 ) ;
F_293 ( V_2 ) ;
F_294 ( V_2 ) ;
return V_2 ;
}
void F_295 ( struct V_1 * V_2 )
{
F_296 ( & V_2 -> V_346 ) ;
}
int F_297 ( struct V_1 * V_2 )
{
int V_268 , error ;
if ( ! V_2 -> V_327 || ! V_2 -> V_344 || ! V_2 -> V_507 )
return - V_21 ;
switch ( V_2 -> V_146 ) {
case V_147 :
V_268 = F_298 ( & V_508 , 0 , 0 , V_292 ) ;
break;
case V_148 :
V_268 = F_298 ( & V_508 , 1 , 0 , V_292 ) ;
break;
default:
return - V_21 ;
}
if ( V_268 < 0 )
return V_268 ;
sprintf ( V_2 -> V_100 , L_90 , V_268 ) ;
V_2 -> V_268 = V_268 ;
F_93 ( L_91 , V_2 , V_2 -> V_100 , V_2 -> V_408 ) ;
V_2 -> V_363 = F_299 ( L_19 , V_509 | V_510 |
V_511 , 1 , V_2 -> V_100 ) ;
if ( ! V_2 -> V_363 ) {
error = - V_321 ;
goto V_16;
}
V_2 -> V_349 = F_299 ( L_19 , V_509 | V_510 |
V_511 , 1 , V_2 -> V_100 ) ;
if ( ! V_2 -> V_349 ) {
F_300 ( V_2 -> V_363 ) ;
error = - V_321 ;
goto V_16;
}
if ( ! F_301 ( V_512 ) )
V_2 -> V_222 = F_302 ( V_2 -> V_100 , V_512 ) ;
F_303 ( & V_2 -> V_346 , L_19 , V_2 -> V_100 ) ;
error = F_304 ( & V_2 -> V_346 ) ;
if ( error < 0 )
goto V_513;
V_2 -> V_514 = F_305 ( V_2 -> V_100 , & V_2 -> V_346 ,
V_515 , & V_516 ,
V_2 ) ;
if ( V_2 -> V_514 ) {
if ( F_306 ( V_2 -> V_514 ) < 0 ) {
F_307 ( V_2 -> V_514 ) ;
V_2 -> V_514 = NULL ;
}
}
if ( V_2 -> V_514 && F_308 ( V_2 -> V_514 ) )
F_114 ( V_324 , & V_2 -> V_70 ) ;
F_114 ( V_221 , & V_2 -> V_70 ) ;
F_114 ( V_347 , & V_2 -> V_70 ) ;
if ( V_2 -> V_146 == V_147 ) {
F_114 ( V_175 , & V_2 -> V_70 ) ;
}
F_309 ( & V_267 ) ;
F_182 ( & V_2 -> V_285 , & V_517 ) ;
F_310 ( & V_267 ) ;
if ( F_4 ( V_259 , & V_2 -> V_145 ) )
F_114 ( V_317 , & V_2 -> V_70 ) ;
F_1 ( V_2 , V_518 ) ;
F_167 ( V_2 ) ;
F_257 ( V_2 -> V_349 , & V_2 -> V_414 ) ;
return V_268 ;
V_513:
F_300 ( V_2 -> V_363 ) ;
F_300 ( V_2 -> V_349 ) ;
V_16:
F_311 ( & V_508 , V_2 -> V_268 ) ;
return error ;
}
void F_312 ( struct V_1 * V_2 )
{
int V_44 , V_268 ;
F_93 ( L_91 , V_2 , V_2 -> V_100 , V_2 -> V_408 ) ;
F_114 ( V_322 , & V_2 -> V_70 ) ;
V_268 = V_2 -> V_268 ;
F_309 ( & V_267 ) ;
F_175 ( & V_2 -> V_285 ) ;
F_310 ( & V_267 ) ;
F_210 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_519 ; V_44 ++ )
F_16 ( V_2 -> V_520 [ V_44 ] ) ;
F_313 ( & V_2 -> V_414 ) ;
if ( ! F_4 ( V_330 , & V_2 -> V_18 ) &&
! F_4 ( V_221 , & V_2 -> V_70 ) &&
! F_4 ( V_323 , & V_2 -> V_70 ) ) {
F_19 ( V_2 ) ;
F_314 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_315 ( ! F_316 ( & V_2 -> V_498 ) ) ;
F_1 ( V_2 , V_521 ) ;
if ( V_2 -> V_514 ) {
F_317 ( V_2 -> V_514 ) ;
F_307 ( V_2 -> V_514 ) ;
}
F_318 ( V_2 ) ;
F_319 ( & V_2 -> V_346 ) ;
F_320 ( V_2 -> V_222 ) ;
F_300 ( V_2 -> V_363 ) ;
F_300 ( V_2 -> V_349 ) ;
F_19 ( V_2 ) ;
F_262 ( & V_2 -> V_499 ) ;
F_262 ( & V_2 -> V_500 ) ;
F_235 ( V_2 ) ;
F_236 ( V_2 ) ;
F_239 ( V_2 ) ;
F_240 ( V_2 ) ;
F_259 ( V_2 ) ;
F_262 ( & V_2 -> V_502 ) ;
F_277 ( V_2 ) ;
F_321 ( V_2 ) ;
F_22 ( V_2 ) ;
F_195 ( V_2 ) ;
F_311 ( & V_508 , V_268 ) ;
}
int F_322 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_522 ) ;
return 0 ;
}
int F_323 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_523 ) ;
return 0 ;
}
int F_324 ( struct V_1 * V_2 )
{
const T_5 V_524 [] = { V_525 , 0x01 , 0x00 } ;
struct V_12 * V_13 ;
V_13 = F_325 ( 3 , V_526 ) ;
if ( ! V_13 )
return - V_321 ;
F_326 ( V_13 ) -> V_393 = V_527 ;
memcpy ( F_327 ( V_13 , 3 ) , V_524 , 3 ) ;
return F_328 ( V_2 , V_13 ) ;
}
int F_328 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_330 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_528 ;
}
F_326 ( V_13 ) -> V_529 = 1 ;
F_329 ( V_13 ) ;
F_330 ( & V_2 -> V_341 , V_13 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_339 ) ;
return 0 ;
}
static int F_331 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_12 V_265 )
{
int V_114 = 0 ;
int V_530 = 0 ;
int V_531 = V_6 ;
struct V_12 * V_13 ;
struct V_532 * V_533 ;
if ( ( type < V_534 || type > V_527 ) ||
V_265 >= V_519 )
return - V_535 ;
V_13 = V_2 -> V_520 [ V_265 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_534 :
V_114 = V_536 ;
V_530 = V_537 ;
break;
case V_527 :
V_114 = V_538 ;
V_530 = V_116 ;
break;
case V_539 :
V_114 = V_540 ;
V_530 = V_541 ;
break;
}
V_13 = F_325 ( V_114 , V_526 ) ;
if ( ! V_13 )
return - V_321 ;
V_533 = ( void * ) V_13 -> V_542 ;
V_533 -> V_543 = V_530 ;
V_533 -> V_393 = type ;
V_2 -> V_520 [ V_265 ] = V_13 ;
}
while ( V_6 ) {
V_533 = ( void * ) V_13 -> V_542 ;
V_114 = F_332 ( V_544 , V_533 -> V_543 , V_6 ) ;
memcpy ( F_327 ( V_13 , V_114 ) , V_26 , V_114 ) ;
V_6 -= V_114 ;
V_26 += V_114 ;
V_533 -> V_543 -= V_114 ;
V_531 = V_6 ;
switch ( type ) {
case V_527 :
if ( V_13 -> V_114 == V_116 ) {
struct V_110 * V_545 = V_110 ( V_13 ) ;
V_533 -> V_543 = V_545 -> V_119 ;
if ( F_333 ( V_13 ) < V_533 -> V_543 ) {
F_16 ( V_13 ) ;
V_2 -> V_520 [ V_265 ] = NULL ;
return - V_321 ;
}
}
break;
case V_534 :
if ( V_13 -> V_114 == V_537 ) {
struct V_546 * V_545 = V_546 ( V_13 ) ;
V_533 -> V_543 = F_31 ( V_545 -> V_547 ) ;
if ( F_333 ( V_13 ) < V_533 -> V_543 ) {
F_16 ( V_13 ) ;
V_2 -> V_520 [ V_265 ] = NULL ;
return - V_321 ;
}
}
break;
case V_539 :
if ( V_13 -> V_114 == V_541 ) {
struct V_548 * V_545 = V_548 ( V_13 ) ;
V_533 -> V_543 = V_545 -> V_547 ;
if ( F_333 ( V_13 ) < V_533 -> V_543 ) {
F_16 ( V_13 ) ;
V_2 -> V_520 [ V_265 ] = NULL ;
return - V_321 ;
}
}
break;
}
if ( V_533 -> V_543 == 0 ) {
F_326 ( V_13 ) -> V_393 = type ;
F_328 ( V_2 , V_13 ) ;
V_2 -> V_520 [ V_265 ] = NULL ;
return V_531 ;
}
}
return V_531 ;
}
int F_334 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_549 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_520 [ V_550 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_551 ;
V_551 = V_26 ;
type = V_551 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_326 ( V_13 ) -> V_393 ;
V_549 = F_331 ( V_2 , type , V_26 , V_6 ,
V_550 ) ;
if ( V_549 < 0 )
return V_549 ;
V_26 += ( V_6 - V_549 ) ;
V_6 = V_549 ;
}
return V_549 ;
}
int F_335 ( struct V_552 * V_542 )
{
F_93 ( L_92 , V_542 , V_542 -> V_100 ) ;
F_309 ( & V_553 ) ;
F_182 ( & V_542 -> V_285 , & V_554 ) ;
F_310 ( & V_553 ) ;
return 0 ;
}
int F_336 ( struct V_552 * V_542 )
{
F_93 ( L_92 , V_542 , V_542 -> V_100 ) ;
F_309 ( & V_553 ) ;
F_175 ( & V_542 -> V_285 ) ;
F_310 ( & V_553 ) ;
return 0 ;
}
static void F_337 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_16 ;
F_93 ( L_93 , V_2 -> V_100 , F_326 ( V_13 ) -> V_393 , V_13 -> V_114 ) ;
F_329 ( V_13 ) ;
F_338 ( V_2 , V_13 ) ;
if ( F_339 ( & V_2 -> V_555 ) ) {
F_340 ( V_2 , V_13 ) ;
}
F_341 ( V_13 ) ;
V_16 = V_2 -> V_507 ( V_2 , V_13 ) ;
if ( V_16 < 0 ) {
F_98 ( L_94 , V_2 -> V_100 , V_16 ) ;
F_16 ( V_13 ) ;
}
}
void F_102 ( struct V_124 * V_125 , struct V_1 * V_2 )
{
F_291 ( & V_125 -> V_340 ) ;
V_125 -> V_2 = V_2 ;
V_125 -> V_16 = 0 ;
}
int F_106 ( struct V_124 * V_125 , T_15 V_556 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_93 ( L_95 , F_342 ( & V_125 -> V_340 ) ) ;
if ( V_125 -> V_16 ) {
F_200 ( & V_125 -> V_340 ) ;
return V_125 -> V_16 ;
}
if ( F_343 ( & V_125 -> V_340 ) )
return - V_113 ;
V_13 = F_344 ( & V_125 -> V_340 ) ;
F_326 ( V_13 ) -> V_125 . V_556 = V_556 ;
F_345 ( & V_2 -> V_340 . V_496 , V_18 ) ;
F_346 ( & V_125 -> V_340 , & V_2 -> V_340 ) ;
F_347 ( & V_2 -> V_340 . V_496 , V_18 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_338 ) ;
return 0 ;
}
bool F_348 ( struct V_1 * V_2 )
{
return ( V_2 -> V_101 == V_102 ) ;
}
static struct V_12 * F_349 ( struct V_1 * V_2 , T_8 V_107 ,
T_9 V_119 , const void * V_120 )
{
int V_114 = V_557 + V_119 ;
struct V_441 * V_111 ;
struct V_12 * V_13 ;
V_13 = F_325 ( V_114 , V_526 ) ;
if ( ! V_13 )
return NULL ;
V_111 = (struct V_441 * ) F_327 ( V_13 , V_557 ) ;
V_111 -> V_107 = F_120 ( V_107 ) ;
V_111 -> V_119 = V_119 ;
if ( V_119 )
memcpy ( F_327 ( V_13 , V_119 ) , V_120 , V_119 ) ;
F_93 ( L_96 , V_13 -> V_114 ) ;
F_326 ( V_13 ) -> V_393 = V_558 ;
F_326 ( V_13 ) -> V_107 = V_107 ;
return V_13 ;
}
int F_350 ( struct V_1 * V_2 , T_13 V_107 , T_10 V_119 ,
const void * V_120 )
{
struct V_12 * V_13 ;
F_93 ( L_97 , V_2 -> V_100 , V_107 , V_119 ) ;
V_13 = F_349 ( V_2 , V_107 , V_119 , V_120 ) ;
if ( ! V_13 ) {
F_98 ( L_98 , V_2 -> V_100 ) ;
return - V_321 ;
}
F_326 ( V_13 ) -> V_125 . V_559 = true ;
F_330 ( & V_2 -> V_340 , V_13 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_338 ) ;
return 0 ;
}
void F_103 ( struct V_124 * V_125 , T_8 V_107 , T_9 V_119 ,
const void * V_120 , T_5 V_3 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_12 * V_13 ;
F_93 ( L_97 , V_2 -> V_100 , V_107 , V_119 ) ;
if ( V_125 -> V_16 )
return;
V_13 = F_349 ( V_2 , V_107 , V_119 , V_120 ) ;
if ( ! V_13 ) {
F_98 ( L_99 ,
V_2 -> V_100 , V_107 ) ;
V_125 -> V_16 = - V_321 ;
return;
}
if ( F_343 ( & V_125 -> V_340 ) )
F_326 ( V_13 ) -> V_125 . V_559 = true ;
F_326 ( V_13 ) -> V_125 . V_3 = V_3 ;
F_330 ( & V_125 -> V_340 , V_13 ) ;
}
void F_115 ( struct V_124 * V_125 , T_8 V_107 , T_9 V_119 ,
const void * V_120 )
{
F_103 ( V_125 , V_107 , V_119 , V_120 , 0 ) ;
}
void * F_351 ( struct V_1 * V_2 , T_13 V_107 )
{
struct V_441 * V_111 ;
if ( ! V_2 -> V_343 )
return NULL ;
V_111 = ( void * ) V_2 -> V_343 -> V_26 ;
if ( V_111 -> V_107 != F_120 ( V_107 ) )
return NULL ;
F_93 ( L_100 , V_2 -> V_100 , V_107 ) ;
return V_2 -> V_343 -> V_26 + V_557 ;
}
static void F_352 ( struct V_12 * V_13 , T_13 V_560 , T_13 V_18 )
{
struct V_546 * V_111 ;
int V_114 = V_13 -> V_114 ;
F_353 ( V_13 , V_537 ) ;
F_354 ( V_13 ) ;
V_111 = (struct V_546 * ) F_355 ( V_13 ) ;
V_111 -> V_560 = F_120 ( F_356 ( V_560 , V_18 ) ) ;
V_111 -> V_547 = F_120 ( V_114 ) ;
}
static void F_357 ( struct V_561 * V_562 , struct V_563 * V_564 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_419 * V_352 = V_562 -> V_352 ;
struct V_1 * V_2 = V_352 -> V_2 ;
struct V_12 * V_285 ;
V_13 -> V_114 = F_358 ( V_13 ) ;
V_13 -> V_565 = 0 ;
F_326 ( V_13 ) -> V_393 = V_534 ;
switch ( V_2 -> V_146 ) {
case V_147 :
F_352 ( V_13 , V_352 -> V_560 , V_18 ) ;
break;
case V_148 :
F_352 ( V_13 , V_562 -> V_560 , V_18 ) ;
break;
default:
F_98 ( L_101 , V_2 -> V_100 , V_2 -> V_146 ) ;
return;
}
V_285 = F_359 ( V_13 ) -> V_566 ;
if ( ! V_285 ) {
F_93 ( L_102 , V_2 -> V_100 , V_13 , V_13 -> V_114 ) ;
F_330 ( V_564 , V_13 ) ;
} else {
F_93 ( L_103 , V_2 -> V_100 , V_13 , V_13 -> V_114 ) ;
F_359 ( V_13 ) -> V_566 = NULL ;
F_360 ( & V_564 -> V_496 ) ;
F_361 ( V_564 , V_13 ) ;
V_18 &= ~ V_567 ;
V_18 |= V_568 ;
do {
V_13 = V_285 ; V_285 = V_285 -> V_569 ;
F_326 ( V_13 ) -> V_393 = V_534 ;
F_352 ( V_13 , V_352 -> V_560 , V_18 ) ;
F_93 ( L_103 , V_2 -> V_100 , V_13 , V_13 -> V_114 ) ;
F_361 ( V_564 , V_13 ) ;
} while ( V_285 );
F_362 ( & V_564 -> V_496 ) ;
}
}
void F_363 ( struct V_561 * V_562 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_562 -> V_352 -> V_2 ;
F_93 ( L_104 , V_2 -> V_100 , V_562 , V_18 ) ;
F_357 ( V_562 , & V_562 -> V_570 , V_13 , V_18 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_337 ) ;
}
void F_364 ( struct V_419 * V_352 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_352 -> V_2 ;
struct V_548 V_111 ;
F_93 ( L_105 , V_2 -> V_100 , V_13 -> V_114 ) ;
V_111 . V_560 = F_120 ( V_352 -> V_560 ) ;
V_111 . V_547 = V_13 -> V_114 ;
F_353 ( V_13 , V_541 ) ;
F_354 ( V_13 ) ;
memcpy ( F_355 ( V_13 ) , & V_111 , V_541 ) ;
F_326 ( V_13 ) -> V_393 = V_539 ;
F_330 ( & V_352 -> V_570 , V_13 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_337 ) ;
}
static struct V_419 * F_365 ( struct V_1 * V_2 , T_12 type ,
int * V_571 )
{
struct V_572 * V_545 = & V_2 -> V_503 ;
struct V_419 * V_352 = NULL , * V_573 ;
unsigned int V_298 = 0 , F_7 = ~ 0 ;
F_34 () ;
F_35 (c, &h->list, list) {
if ( V_573 -> type != type || F_343 ( & V_573 -> V_570 ) )
continue;
if ( V_573 -> V_270 != V_454 && V_573 -> V_270 != V_574 )
continue;
V_298 ++ ;
if ( V_573 -> V_442 < F_7 ) {
F_7 = V_573 -> V_442 ;
V_352 = V_573 ;
}
if ( F_366 ( V_2 , type ) == V_298 )
break;
}
F_36 () ;
if ( V_352 ) {
int V_575 , V_576 ;
switch ( V_352 -> type ) {
case V_577 :
V_575 = V_2 -> V_369 ;
break;
case V_578 :
case V_579 :
V_575 = V_2 -> V_370 ;
break;
case V_424 :
V_575 = V_2 -> V_409 ? V_2 -> V_371 : V_2 -> V_369 ;
break;
default:
V_575 = 0 ;
F_98 ( L_106 ) ;
}
V_576 = V_575 / V_298 ;
* V_571 = V_576 ? V_576 : 1 ;
} else
* V_571 = 0 ;
F_93 ( L_107 , V_352 , * V_571 ) ;
return V_352 ;
}
static void F_367 ( struct V_1 * V_2 , T_12 type )
{
struct V_572 * V_545 = & V_2 -> V_503 ;
struct V_419 * V_573 ;
F_98 ( L_108 , V_2 -> V_100 ) ;
F_34 () ;
F_35 (c, &h->list, list) {
if ( V_573 -> type == type && V_573 -> V_442 ) {
F_98 ( L_109 ,
V_2 -> V_100 , & V_573 -> V_580 ) ;
F_368 ( V_573 , V_581 ) ;
}
}
F_36 () ;
}
static struct V_561 * F_369 ( struct V_1 * V_2 , T_12 type ,
int * V_571 )
{
struct V_572 * V_545 = & V_2 -> V_503 ;
struct V_561 * V_562 = NULL ;
unsigned int V_298 = 0 , F_7 = ~ 0 , V_582 = 0 ;
struct V_419 * V_352 ;
int V_575 , V_576 , V_583 = 0 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_34 () ;
F_35 (conn, &h->list, list) {
struct V_561 * V_416 ;
if ( V_352 -> type != type )
continue;
if ( V_352 -> V_270 != V_454 && V_352 -> V_270 != V_574 )
continue;
V_583 ++ ;
F_35 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_343 ( & V_416 -> V_570 ) )
continue;
V_13 = F_370 ( & V_416 -> V_570 ) ;
if ( V_13 -> V_584 < V_582 )
continue;
if ( V_13 -> V_584 > V_582 ) {
V_298 = 0 ;
F_7 = ~ 0 ;
V_582 = V_13 -> V_584 ;
}
V_298 ++ ;
if ( V_352 -> V_442 < F_7 ) {
F_7 = V_352 -> V_442 ;
V_562 = V_416 ;
}
}
if ( F_366 ( V_2 , type ) == V_583 )
break;
}
F_36 () ;
if ( ! V_562 )
return NULL ;
switch ( V_562 -> V_352 -> type ) {
case V_577 :
V_575 = V_2 -> V_369 ;
break;
case V_585 :
V_575 = V_2 -> V_586 ;
break;
case V_578 :
case V_579 :
V_575 = V_2 -> V_370 ;
break;
case V_424 :
V_575 = V_2 -> V_409 ? V_2 -> V_371 : V_2 -> V_369 ;
break;
default:
V_575 = 0 ;
F_98 ( L_106 ) ;
}
V_576 = V_575 / V_298 ;
* V_571 = V_576 ? V_576 : 1 ;
F_93 ( L_110 , V_562 , * V_571 ) ;
return V_562 ;
}
static void F_371 ( struct V_1 * V_2 , T_12 type )
{
struct V_572 * V_545 = & V_2 -> V_503 ;
struct V_419 * V_352 ;
int V_298 = 0 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
F_34 () ;
F_35 (conn, &h->list, list) {
struct V_561 * V_562 ;
if ( V_352 -> type != type )
continue;
if ( V_352 -> V_270 != V_454 && V_352 -> V_270 != V_574 )
continue;
V_298 ++ ;
F_35 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_562 -> V_442 ) {
V_562 -> V_442 = 0 ;
continue;
}
if ( F_343 ( & V_562 -> V_570 ) )
continue;
V_13 = F_370 ( & V_562 -> V_570 ) ;
if ( V_13 -> V_584 >= V_587 - 1 )
continue;
V_13 -> V_584 = V_587 - 1 ;
F_93 ( L_111 , V_562 , V_13 ,
V_13 -> V_584 ) ;
}
if ( F_366 ( V_2 , type ) == V_298 )
break;
}
F_36 () ;
}
static inline int F_372 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_373 ( V_13 -> V_114 - V_537 , V_2 -> V_588 ) ;
}
static void F_374 ( struct V_1 * V_2 , unsigned int V_575 )
{
if ( ! F_4 ( V_317 , & V_2 -> V_70 ) ) {
if ( ! V_575 && F_375 ( V_297 , V_2 -> V_589 +
V_590 ) )
F_367 ( V_2 , V_577 ) ;
}
}
static void F_376 ( struct V_1 * V_2 )
{
unsigned int V_575 = V_2 -> V_369 ;
struct V_561 * V_562 ;
struct V_12 * V_13 ;
int V_571 ;
F_374 ( V_2 , V_575 ) ;
while ( V_2 -> V_369 &&
( V_562 = F_369 ( V_2 , V_577 , & V_571 ) ) ) {
T_9 V_584 = ( F_370 ( & V_562 -> V_570 ) ) -> V_584 ;
while ( V_571 -- && ( V_13 = F_370 ( & V_562 -> V_570 ) ) ) {
F_93 ( L_112 , V_562 , V_13 ,
V_13 -> V_114 , V_13 -> V_584 ) ;
if ( V_13 -> V_584 < V_584 )
break;
V_13 = F_377 ( & V_562 -> V_570 ) ;
F_378 ( V_562 -> V_352 ,
F_326 ( V_13 ) -> V_591 ) ;
F_337 ( V_2 , V_13 ) ;
V_2 -> V_589 = V_297 ;
V_2 -> V_369 -- ;
V_562 -> V_442 ++ ;
V_562 -> V_352 -> V_442 ++ ;
}
}
if ( V_575 != V_2 -> V_369 )
F_371 ( V_2 , V_577 ) ;
}
static void F_379 ( struct V_1 * V_2 )
{
unsigned int V_575 = V_2 -> V_586 ;
struct V_561 * V_562 ;
struct V_12 * V_13 ;
int V_571 ;
T_5 type ;
F_374 ( V_2 , V_575 ) ;
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( V_2 -> V_146 == V_148 )
type = V_585 ;
else
type = V_577 ;
while ( V_2 -> V_586 > 0 &&
( V_562 = F_369 ( V_2 , type , & V_571 ) ) ) {
T_9 V_584 = ( F_370 ( & V_562 -> V_570 ) ) -> V_584 ;
while ( V_571 > 0 && ( V_13 = F_370 ( & V_562 -> V_570 ) ) ) {
int V_592 ;
F_93 ( L_112 , V_562 , V_13 ,
V_13 -> V_114 , V_13 -> V_584 ) ;
if ( V_13 -> V_584 < V_584 )
break;
V_13 = F_377 ( & V_562 -> V_570 ) ;
V_592 = F_372 ( V_2 , V_13 ) ;
if ( V_592 > V_2 -> V_586 )
return;
F_378 ( V_562 -> V_352 ,
F_326 ( V_13 ) -> V_591 ) ;
F_337 ( V_2 , V_13 ) ;
V_2 -> V_589 = V_297 ;
V_2 -> V_586 -= V_592 ;
V_571 -= V_592 ;
V_562 -> V_442 += V_592 ;
V_562 -> V_352 -> V_442 += V_592 ;
}
}
if ( V_575 != V_2 -> V_586 )
F_371 ( V_2 , type ) ;
}
static void F_380 ( struct V_1 * V_2 )
{
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( ! F_366 ( V_2 , V_577 ) && V_2 -> V_146 == V_147 )
return;
if ( ! F_366 ( V_2 , V_585 ) && V_2 -> V_146 == V_148 )
return;
switch ( V_2 -> V_133 ) {
case V_134 :
F_376 ( V_2 ) ;
break;
case V_138 :
F_379 ( V_2 ) ;
break;
}
}
static void F_381 ( struct V_1 * V_2 )
{
struct V_419 * V_352 ;
struct V_12 * V_13 ;
int V_571 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( ! F_366 ( V_2 , V_578 ) )
return;
while ( V_2 -> V_370 && ( V_352 = F_365 ( V_2 , V_578 , & V_571 ) ) ) {
while ( V_571 -- && ( V_13 = F_377 ( & V_352 -> V_570 ) ) ) {
F_93 ( L_113 , V_13 , V_13 -> V_114 ) ;
F_337 ( V_2 , V_13 ) ;
V_352 -> V_442 ++ ;
if ( V_352 -> V_442 == ~ 0 )
V_352 -> V_442 = 0 ;
}
}
}
static void F_382 ( struct V_1 * V_2 )
{
struct V_419 * V_352 ;
struct V_12 * V_13 ;
int V_571 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( ! F_366 ( V_2 , V_579 ) )
return;
while ( V_2 -> V_370 && ( V_352 = F_365 ( V_2 , V_579 ,
& V_571 ) ) ) {
while ( V_571 -- && ( V_13 = F_377 ( & V_352 -> V_570 ) ) ) {
F_93 ( L_113 , V_13 , V_13 -> V_114 ) ;
F_337 ( V_2 , V_13 ) ;
V_352 -> V_442 ++ ;
if ( V_352 -> V_442 == ~ 0 )
V_352 -> V_442 = 0 ;
}
}
}
static void F_383 ( struct V_1 * V_2 )
{
struct V_561 * V_562 ;
struct V_12 * V_13 ;
int V_571 , V_575 , V_416 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
if ( ! F_366 ( V_2 , V_424 ) )
return;
if ( ! F_4 ( V_317 , & V_2 -> V_70 ) ) {
if ( ! V_2 -> V_371 && V_2 -> V_410 &&
F_375 ( V_297 , V_2 -> V_593 + V_594 * 45 ) )
F_367 ( V_2 , V_424 ) ;
}
V_575 = V_2 -> V_410 ? V_2 -> V_371 : V_2 -> V_369 ;
V_416 = V_575 ;
while ( V_575 && ( V_562 = F_369 ( V_2 , V_424 , & V_571 ) ) ) {
T_9 V_584 = ( F_370 ( & V_562 -> V_570 ) ) -> V_584 ;
while ( V_571 -- && ( V_13 = F_370 ( & V_562 -> V_570 ) ) ) {
F_93 ( L_112 , V_562 , V_13 ,
V_13 -> V_114 , V_13 -> V_584 ) ;
if ( V_13 -> V_584 < V_584 )
break;
V_13 = F_377 ( & V_562 -> V_570 ) ;
F_337 ( V_2 , V_13 ) ;
V_2 -> V_593 = V_297 ;
V_575 -- ;
V_562 -> V_442 ++ ;
V_562 -> V_352 -> V_442 ++ ;
}
}
if ( V_2 -> V_410 )
V_2 -> V_371 = V_575 ;
else
V_2 -> V_369 = V_575 ;
if ( V_575 != V_416 )
F_371 ( V_2 , V_424 ) ;
}
static void V_506 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 , V_337 ) ;
struct V_12 * V_13 ;
F_93 ( L_114 , V_2 -> V_100 , V_2 -> V_369 ,
V_2 -> V_370 , V_2 -> V_371 ) ;
if ( ! F_4 ( V_316 , & V_2 -> V_70 ) ) {
F_380 ( V_2 ) ;
F_381 ( V_2 ) ;
F_382 ( V_2 ) ;
F_383 ( V_2 ) ;
}
while ( ( V_13 = F_377 ( & V_2 -> V_365 ) ) )
F_337 ( V_2 , V_13 ) ;
}
static void F_384 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_546 * V_111 = ( void * ) V_13 -> V_26 ;
struct V_419 * V_352 ;
T_13 V_560 , V_18 ;
F_99 ( V_13 , V_537 ) ;
V_560 = F_31 ( V_111 -> V_560 ) ;
V_18 = F_385 ( V_560 ) ;
V_560 = F_386 ( V_560 ) ;
F_93 ( L_115 , V_2 -> V_100 , V_13 -> V_114 ,
V_560 , V_18 ) ;
V_2 -> V_372 . V_595 ++ ;
F_19 ( V_2 ) ;
V_352 = F_387 ( V_2 , V_560 ) ;
F_22 ( V_2 ) ;
if ( V_352 ) {
F_378 ( V_352 , V_596 ) ;
F_388 ( V_352 , V_13 , V_18 ) ;
return;
} else {
F_98 ( L_116 ,
V_2 -> V_100 , V_560 ) ;
}
F_16 ( V_13 ) ;
}
static void F_389 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_548 * V_111 = ( void * ) V_13 -> V_26 ;
struct V_419 * V_352 ;
T_13 V_560 ;
F_99 ( V_13 , V_541 ) ;
V_560 = F_31 ( V_111 -> V_560 ) ;
F_93 ( L_117 , V_2 -> V_100 , V_13 -> V_114 , V_560 ) ;
V_2 -> V_372 . V_597 ++ ;
F_19 ( V_2 ) ;
V_352 = F_387 ( V_2 , V_560 ) ;
F_22 ( V_2 ) ;
if ( V_352 ) {
F_390 ( V_352 , V_13 ) ;
return;
} else {
F_98 ( L_118 ,
V_2 -> V_100 , V_560 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_391 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_370 ( & V_2 -> V_340 ) ;
if ( ! V_13 )
return true ;
return F_326 ( V_13 ) -> V_125 . V_559 ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_441 * V_442 ;
struct V_12 * V_13 ;
T_8 V_107 ;
if ( ! V_2 -> V_343 )
return;
V_442 = ( void * ) V_2 -> V_343 -> V_26 ;
V_107 = F_31 ( V_442 -> V_107 ) ;
if ( V_107 == V_25 )
return;
V_13 = F_393 ( V_2 -> V_343 , V_292 ) ;
if ( ! V_13 )
return;
F_394 ( & V_2 -> V_340 , V_13 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_338 ) ;
}
void F_395 ( struct V_1 * V_2 , T_8 V_107 , T_5 V_467 )
{
T_15 V_598 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_93 ( L_119 , V_107 , V_467 ) ;
if ( ! F_351 ( V_2 , V_107 ) ) {
if ( F_4 ( V_330 , & V_2 -> V_18 ) && V_107 == V_25 )
F_392 ( V_2 ) ;
return;
}
if ( ! V_467 && ! F_391 ( V_2 ) )
return;
if ( V_2 -> V_343 ) {
V_598 = F_326 ( V_2 -> V_343 ) -> V_125 . V_556 ;
if ( V_598 ) {
F_326 ( V_2 -> V_343 ) -> V_125 . V_556 = NULL ;
goto V_599;
}
}
F_345 ( & V_2 -> V_340 . V_496 , V_18 ) ;
while ( ( V_13 = F_396 ( & V_2 -> V_340 ) ) ) {
if ( F_326 ( V_13 ) -> V_125 . V_559 ) {
F_397 ( & V_2 -> V_340 , V_13 ) ;
break;
}
V_598 = F_326 ( V_13 ) -> V_125 . V_556 ;
F_16 ( V_13 ) ;
}
F_347 ( & V_2 -> V_340 . V_496 , V_18 ) ;
V_599:
if ( V_598 )
V_598 ( V_2 , V_467 ) ;
}
static void V_504 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 , V_339 ) ;
struct V_12 * V_13 ;
F_93 ( L_19 , V_2 -> V_100 ) ;
while ( ( V_13 = F_377 ( & V_2 -> V_341 ) ) ) {
F_338 ( V_2 , V_13 ) ;
if ( F_339 ( & V_2 -> V_555 ) ) {
F_340 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_316 , & V_2 -> V_70 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_330 , & V_2 -> V_18 ) ) {
switch ( F_326 ( V_13 ) -> V_393 ) {
case V_534 :
case V_539 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_326 ( V_13 ) -> V_393 ) {
case V_527 :
F_93 ( L_120 , V_2 -> V_100 ) ;
F_398 ( V_2 , V_13 ) ;
break;
case V_534 :
F_93 ( L_121 , V_2 -> V_100 ) ;
F_384 ( V_2 , V_13 ) ;
break;
case V_539 :
F_93 ( L_122 , V_2 -> V_100 ) ;
F_389 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_505 ( struct V_412 * V_413 )
{
struct V_1 * V_2 = F_228 ( V_413 , struct V_1 , V_338 ) ;
struct V_12 * V_13 ;
F_93 ( L_123 , V_2 -> V_100 ,
F_339 ( & V_2 -> V_329 ) , F_342 ( & V_2 -> V_340 ) ) ;
if ( F_339 ( & V_2 -> V_329 ) ) {
V_13 = F_377 ( & V_2 -> V_340 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_343 ) ;
V_2 -> V_343 = F_393 ( V_13 , V_292 ) ;
if ( V_2 -> V_343 ) {
F_399 ( & V_2 -> V_329 ) ;
F_337 ( V_2 , V_13 ) ;
if ( F_4 ( V_132 , & V_2 -> V_18 ) )
F_204 ( & V_2 -> V_354 ) ;
else
F_400 ( & V_2 -> V_354 ,
V_24 ) ;
} else {
F_394 ( & V_2 -> V_340 , V_13 ) ;
F_257 ( V_2 -> V_363 , & V_2 -> V_338 ) ;
}
}
}
void F_281 ( struct V_124 * V_125 )
{
struct V_600 V_180 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_15 = V_601 ;
F_115 ( V_125 , V_602 , sizeof( V_180 ) , & V_180 ) ;
}
static void F_401 ( struct V_124 * V_125 ,
struct V_97 * V_452 )
{
struct V_603 V_180 ;
V_180 . V_41 = V_452 -> V_78 ;
F_149 ( & V_180 . V_40 , & V_452 -> V_77 ) ;
F_115 ( V_125 , V_604 , sizeof( V_180 ) , & V_180 ) ;
}
static T_5 F_402 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_97 * V_452 ;
struct V_38 * V_39 ;
T_16 V_605 = 0 ;
F_26 (b, &hdev->le_white_list, list) {
struct V_606 V_180 ;
if ( F_271 ( & V_2 -> V_466 ,
& V_39 -> V_40 , V_39 -> V_41 ) ||
F_271 ( & V_2 -> V_463 ,
& V_39 -> V_40 , V_39 -> V_41 ) ) {
V_605 ++ ;
continue;
}
V_180 . V_41 = V_39 -> V_41 ;
F_149 ( & V_180 . V_40 , & V_39 -> V_40 ) ;
F_115 ( V_125 , V_607 ,
sizeof( V_180 ) , & V_180 ) ;
}
F_26 (params, &hdev->pend_le_conns, action) {
if ( F_261 ( & V_2 -> V_502 ,
& V_452 -> V_77 , V_452 -> V_78 ) )
continue;
if ( V_605 >= V_2 -> V_246 ) {
return 0x00 ;
}
if ( F_248 ( V_2 , & V_452 -> V_77 ,
V_452 -> V_78 ) ) {
return 0x00 ;
}
V_605 ++ ;
F_401 ( V_125 , V_452 ) ;
}
F_26 (params, &hdev->pend_le_reports, action) {
if ( F_261 ( & V_2 -> V_502 ,
& V_452 -> V_77 , V_452 -> V_78 ) )
continue;
if ( V_605 >= V_2 -> V_246 ) {
return 0x00 ;
}
if ( F_248 ( V_2 , & V_452 -> V_77 ,
V_452 -> V_78 ) ) {
return 0x00 ;
}
V_605 ++ ;
F_401 ( V_125 , V_452 ) ;
}
return 0x01 ;
}
void F_403 ( struct V_124 * V_125 )
{
struct V_608 V_609 ;
struct V_600 V_610 ;
struct V_1 * V_2 = V_125 -> V_2 ;
T_5 V_475 ;
T_5 V_611 ;
if ( F_284 ( V_125 , false , & V_475 ) )
return;
V_611 = F_402 ( V_125 ) ;
if ( F_4 ( V_476 , & V_2 -> V_70 ) &&
( V_2 -> V_35 [ 0 ] & V_212 ) )
V_611 |= 0x02 ;
memset ( & V_609 , 0 , sizeof( V_609 ) ) ;
V_609 . type = V_612 ;
V_609 . V_613 = F_120 ( V_2 -> V_490 ) ;
V_609 . V_614 = F_120 ( V_2 -> V_491 ) ;
V_609 . V_615 = V_475 ;
V_609 . V_611 = V_611 ;
F_115 ( V_125 , V_616 , sizeof( V_609 ) ,
& V_609 ) ;
memset ( & V_610 , 0 , sizeof( V_610 ) ) ;
V_610 . V_15 = V_617 ;
V_610 . V_618 = V_619 ;
F_115 ( V_125 , V_602 , sizeof( V_610 ) ,
& V_610 ) ;
}
static void F_404 ( struct V_1 * V_2 , T_5 V_467 )
{
if ( V_467 )
F_93 ( L_124
L_125 , V_467 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_124 V_125 ;
struct V_419 * V_352 ;
int V_16 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ||
F_4 ( V_330 , & V_2 -> V_18 ) ||
F_4 ( V_221 , & V_2 -> V_70 ) ||
F_4 ( V_323 , & V_2 -> V_70 ) ||
F_4 ( V_347 , & V_2 -> V_70 ) ||
F_4 ( V_322 , & V_2 -> V_70 ) )
return;
if ( ! F_4 ( V_164 , & V_2 -> V_70 ) )
return;
if ( V_2 -> V_48 . V_270 != V_274 )
return;
F_321 ( V_2 ) ;
F_102 ( & V_125 , V_2 ) ;
if ( F_316 ( & V_2 -> V_466 ) &&
F_316 ( & V_2 -> V_463 ) ) {
if ( ! F_4 ( V_620 , & V_2 -> V_70 ) )
return;
F_281 ( & V_125 ) ;
F_93 ( L_126 , V_2 -> V_100 ) ;
} else {
V_352 = F_283 ( V_2 , V_424 , V_472 ) ;
if ( V_352 )
return;
if ( F_4 ( V_620 , & V_2 -> V_70 ) )
F_281 ( & V_125 ) ;
F_403 ( & V_125 ) ;
F_93 ( L_127 , V_2 -> V_100 ) ;
}
V_16 = F_106 ( & V_125 , F_404 ) ;
if ( V_16 )
F_98 ( L_128 , V_16 ) ;
}
static bool F_405 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->whitelist, list) {
struct V_419 * V_352 ;
V_352 = F_270 ( V_2 , V_577 , & V_39 -> V_40 ) ;
if ( ! V_352 )
return true ;
if ( V_352 -> V_270 != V_454 && V_352 -> V_270 != V_574 )
return true ;
}
return false ;
}
void F_406 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
T_5 V_260 ;
if ( ! F_4 ( V_175 , & V_2 -> V_70 ) )
return;
if ( ! F_407 ( V_2 ) )
return;
if ( F_408 ( V_2 ) )
return;
if ( F_4 ( V_377 , & V_2 -> V_70 ) ||
F_405 ( V_2 ) )
V_260 = V_376 ;
else
V_260 = V_621 ;
if ( F_4 ( V_622 , & V_2 -> V_18 ) == ! ! ( V_260 & V_376 ) )
return;
if ( F_4 ( V_357 , & V_2 -> V_70 ) )
V_260 |= V_378 ;
if ( V_125 )
F_115 ( V_125 , V_261 , 1 , & V_260 ) ;
else
F_350 ( V_2 , V_261 , 1 , & V_260 ) ;
}
