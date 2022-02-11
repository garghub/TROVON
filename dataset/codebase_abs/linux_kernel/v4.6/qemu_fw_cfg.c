static inline T_1 F_1 ( T_1 V_1 )
{
return V_2 ? F_2 ( V_1 ) : F_3 ( V_1 ) ;
}
static inline void F_4 ( T_1 V_1 ,
void * V_3 , T_2 V_4 , T_3 V_5 )
{
T_4 V_6 = - 1U ;
T_5 V_7 ;
V_7 = F_5 ( V_8 , & V_6 ) ;
if ( F_6 ( V_7 ) && V_7 != V_9 ) {
F_7 ( 1 , L_1 ) ;
memset ( V_3 , 0 , V_5 ) ;
return;
}
F_8 ( & V_10 ) ;
F_9 ( F_1 ( V_1 ) , V_11 ) ;
while ( V_4 -- > 0 )
F_10 ( V_12 ) ;
F_11 ( V_12 , V_3 , V_5 ) ;
F_12 ( & V_10 ) ;
F_13 ( V_6 ) ;
}
static void F_14 ( void )
{
if ( V_2 ) {
F_15 ( V_13 ) ;
F_16 ( V_14 , V_15 ) ;
} else {
F_17 ( V_13 ) ;
F_18 ( V_14 , V_15 ) ;
}
}
static int F_19 ( struct V_16 * V_17 )
{
char V_18 [ V_19 ] ;
struct V_20 * V_21 , * V_22 , * V_23 ;
V_2 = false ;
V_21 = F_20 ( V_17 , V_24 , 0 ) ;
if ( ! V_21 ) {
V_2 = true ;
V_21 = F_20 ( V_17 , V_25 , 0 ) ;
if ( ! V_21 )
return - V_26 ;
}
V_14 = V_21 -> V_27 ;
V_15 = F_21 ( V_21 ) ;
if ( V_2 ) {
if ( ! F_22 ( V_14 ,
V_15 , L_2 ) )
return - V_28 ;
V_13 = F_23 ( V_14 , V_15 ) ;
if ( ! V_13 ) {
F_16 ( V_14 , V_15 ) ;
return - V_29 ;
}
} else {
if ( ! F_24 ( V_14 ,
V_15 , L_3 ) )
return - V_28 ;
V_13 = F_25 ( V_14 , V_15 ) ;
if ( ! V_13 ) {
F_18 ( V_14 , V_15 ) ;
return - V_29 ;
}
}
V_22 = F_26 ( V_17 , V_30 , L_4 ) ;
V_23 = F_26 ( V_17 , V_30 , L_5 ) ;
if ( V_22 && V_23 ) {
V_11 = V_13 + V_22 -> V_27 ;
V_12 = V_13 + V_23 -> V_27 ;
} else {
V_11 = V_13 + V_31 ;
V_12 = V_13 + V_32 ;
}
F_4 ( V_33 , V_18 , 0 , V_19 ) ;
if ( memcmp ( V_18 , L_6 , V_19 ) != 0 ) {
F_14 () ;
return - V_34 ;
}
return 0 ;
}
static T_6 F_27 ( struct V_35 * V_36 , struct V_37 * V_38 , char * V_3 )
{
return sprintf ( V_3 , L_7 , V_39 ) ;
}
static inline struct V_40 * F_28 ( struct V_35 * V_41 )
{
return F_29 ( V_41 , struct V_40 , V_41 ) ;
}
static inline struct V_42 * F_30 ( struct V_37 * V_43 )
{
return F_29 ( V_43 , struct V_42 , V_43 ) ;
}
static inline void F_31 ( struct V_40 * V_44 )
{
F_32 ( & V_45 ) ;
F_33 ( & V_44 -> V_46 , & V_47 ) ;
F_34 ( & V_45 ) ;
}
static inline void F_35 ( struct V_40 * V_44 )
{
F_32 ( & V_45 ) ;
F_36 ( & V_44 -> V_46 ) ;
F_34 ( & V_45 ) ;
}
static void F_37 ( void )
{
struct V_40 * V_44 , * V_48 ;
F_38 (entry, next, &fw_cfg_entry_cache, list) {
F_39 ( & V_44 -> V_41 ) ;
}
}
static T_6 F_40 ( struct V_40 * V_49 , char * V_3 )
{
return sprintf ( V_3 , L_7 , V_49 -> V_50 . V_51 ) ;
}
static T_6 F_41 ( struct V_40 * V_49 , char * V_3 )
{
return sprintf ( V_3 , L_7 , V_49 -> V_50 . V_52 ) ;
}
static T_6 F_42 ( struct V_40 * V_49 , char * V_3 )
{
return sprintf ( V_3 , L_8 , V_49 -> V_50 . V_53 ) ;
}
static T_6 F_43 ( struct V_35 * V_41 , struct V_37 * V_38 ,
char * V_3 )
{
struct V_40 * V_44 = F_28 ( V_41 ) ;
struct V_42 * V_43 = F_30 ( V_38 ) ;
return V_43 -> V_54 ( V_44 , V_3 ) ;
}
static void F_44 ( struct V_35 * V_41 )
{
struct V_40 * V_44 = F_28 ( V_41 ) ;
F_35 ( V_44 ) ;
F_45 ( V_44 ) ;
}
static T_6 F_46 ( struct V_55 * V_56 , struct V_35 * V_41 ,
struct V_57 * V_58 ,
char * V_3 , T_2 V_4 , T_3 V_5 )
{
struct V_40 * V_44 = F_28 ( V_41 ) ;
if ( V_4 > V_44 -> V_50 . V_51 )
return - V_26 ;
if ( V_5 > V_44 -> V_50 . V_51 - V_4 )
V_5 = V_44 -> V_50 . V_51 - V_4 ;
F_4 ( V_44 -> V_50 . V_52 , V_3 , V_4 , V_5 ) ;
return V_5 ;
}
static int F_47 ( struct V_59 * V_60 ,
struct V_35 * V_61 , const char * V_53 )
{
int V_62 ;
struct V_59 * V_63 ;
struct V_35 * V_64 ;
char * V_65 , * V_66 , * V_67 ;
if ( ! V_60 || ! V_61 || ! V_53 || ! * V_53 )
return - V_26 ;
V_65 = V_66 = F_48 ( V_53 , V_68 ) ;
if ( ! V_65 )
return - V_69 ;
while ( ( V_67 = F_49 ( & V_66 , L_9 ) ) && * V_67 ) {
if ( ! V_66 || ! * V_66 ) {
V_62 = F_50 ( & V_60 -> V_41 , V_61 , V_67 ) ;
break;
}
V_64 = F_51 ( V_60 , V_67 ) ;
if ( V_64 ) {
F_39 ( V_64 ) ;
if ( V_64 -> V_70 != V_60 -> V_41 . V_70 ) {
V_62 = - V_26 ;
break;
}
V_60 = F_52 ( V_64 ) ;
} else {
V_63 = F_53 ( sizeof( struct V_59 ) , V_68 ) ;
if ( ! V_63 ) {
V_62 = - V_69 ;
break;
}
V_63 -> V_41 . V_59 = V_60 ;
V_63 -> V_41 . V_70 = V_60 -> V_41 . V_70 ;
V_62 = F_54 ( & V_63 -> V_41 , L_10 , V_67 ) ;
if ( V_62 ) {
F_45 ( V_63 ) ;
break;
}
V_62 = F_55 ( V_63 ) ;
if ( V_62 ) {
F_45 ( V_63 ) ;
break;
}
V_60 = V_63 ;
}
}
F_45 ( V_65 ) ;
return V_62 ;
}
static void F_56 ( struct V_59 * V_59 )
{
struct V_35 * V_36 , * V_48 ;
F_38 (k, next, &kset->list, entry)
if ( V_36 -> V_70 == V_59 -> V_41 . V_70 )
F_56 ( F_52 ( V_36 ) ) ;
F_57 ( V_59 ) ;
}
static int F_58 ( const struct V_71 * V_50 )
{
int V_72 ;
struct V_40 * V_44 ;
V_44 = F_53 ( sizeof( * V_44 ) , V_68 ) ;
if ( ! V_44 )
return - V_69 ;
memcpy ( & V_44 -> V_50 , V_50 , sizeof( struct V_71 ) ) ;
V_72 = F_59 ( & V_44 -> V_41 , & V_73 ,
V_74 , L_11 , V_44 -> V_50 . V_52 ) ;
if ( V_72 )
goto V_75;
V_72 = F_60 ( & V_44 -> V_41 , & V_76 ) ;
if ( V_72 )
goto V_77;
F_47 ( V_78 , & V_44 -> V_41 , V_44 -> V_50 . V_53 ) ;
F_31 ( V_44 ) ;
return 0 ;
V_77:
F_61 ( & V_44 -> V_41 ) ;
V_75:
F_45 ( V_44 ) ;
return V_72 ;
}
static int F_62 ( void )
{
int V_62 = 0 ;
T_4 V_5 , V_79 ;
struct V_71 * V_60 ;
T_3 V_80 ;
F_4 ( V_81 , & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 = F_63 ( V_5 ) ;
V_80 = V_5 * sizeof( struct V_71 ) ;
V_60 = F_64 ( V_80 , V_68 ) ;
if ( ! V_60 )
return - V_69 ;
F_4 ( V_81 , V_60 , sizeof( V_5 ) , V_80 ) ;
for ( V_79 = 0 ; V_79 < V_5 ; V_79 ++ ) {
V_60 [ V_79 ] . V_51 = F_63 ( V_60 [ V_79 ] . V_51 ) ;
V_60 [ V_79 ] . V_52 = F_65 ( V_60 [ V_79 ] . V_52 ) ;
V_62 = F_58 ( & V_60 [ V_79 ] ) ;
if ( V_62 )
break;
}
F_45 ( V_60 ) ;
return V_62 ;
}
static inline void F_66 ( struct V_35 * V_41 )
{
F_61 ( V_41 ) ;
F_39 ( V_41 ) ;
}
static int F_67 ( struct V_16 * V_17 )
{
int V_72 ;
if ( V_74 )
return - V_28 ;
V_72 = - V_69 ;
V_74 = F_68 ( L_12 , V_82 ) ;
if ( ! V_74 )
goto V_83;
V_78 = F_69 ( L_13 , NULL , V_82 ) ;
if ( ! V_78 )
goto V_84;
V_72 = F_19 ( V_17 ) ;
if ( V_72 )
goto V_85;
F_4 ( V_86 , & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 = F_70 ( V_39 ) ;
V_72 = F_71 ( V_82 , & V_87 . V_43 ) ;
if ( V_72 )
goto V_88;
V_72 = F_62 () ;
if ( V_72 )
goto V_89;
F_72 ( L_14 ) ;
return 0 ;
V_89:
F_37 () ;
F_73 ( V_82 , & V_87 . V_43 ) ;
V_88:
F_14 () ;
V_85:
F_56 ( V_78 ) ;
V_84:
F_66 ( V_74 ) ;
V_83:
return V_72 ;
}
static int F_74 ( struct V_16 * V_17 )
{
F_72 ( L_15 ) ;
F_37 () ;
F_56 ( V_78 ) ;
F_66 ( V_74 ) ;
F_14 () ;
return 0 ;
}
static int F_75 ( const char * V_90 , const struct V_91 * V_92 )
{
struct V_20 V_93 [ 3 ] = {} ;
char * V_94 ;
T_7 V_95 ;
T_8 V_51 , V_96 , V_97 ;
int V_98 , V_99 = 0 ;
if ( V_100 ) {
F_76 ( V_100 ) ;
return - V_26 ;
}
V_51 = F_77 ( V_90 , & V_94 ) ;
V_98 = sscanf ( V_94 , V_101 ,
& V_95 , & V_99 ,
& V_96 , & V_97 , & V_99 ) ;
if ( V_94 [ V_99 ] ||
( V_98 != 1 && V_98 != 3 ) )
return - V_26 ;
V_93 [ 0 ] . V_27 = V_95 ;
V_93 [ 0 ] . V_102 = V_95 + V_51 - 1 ;
V_93 [ 0 ] . V_103 = ! strcmp ( V_92 -> V_53 , L_16 ) ? V_25 :
V_24 ;
if ( V_98 > 1 ) {
V_93 [ 1 ] . V_53 = L_4 ;
V_93 [ 1 ] . V_27 = V_96 ;
V_93 [ 1 ] . V_103 = V_30 ;
V_93 [ 2 ] . V_53 = L_5 ;
V_93 [ 2 ] . V_27 = V_97 ;
V_93 [ 2 ] . V_103 = V_30 ;
}
V_100 = F_78 ( L_17 ,
V_104 , V_93 , V_98 ) ;
if ( F_79 ( V_100 ) )
return F_80 ( V_100 ) ;
return 0 ;
}
static int F_81 ( char * V_3 , const struct V_91 * V_92 )
{
if ( ! V_100 ||
( ! strcmp ( V_92 -> V_53 , L_16 ) ^
( V_100 -> V_20 [ 0 ] . V_103 == V_25 ) ) )
return 0 ;
switch ( V_100 -> V_105 ) {
case 1 :
return snprintf ( V_3 , V_106 , V_107 ,
F_21 ( & V_100 -> V_20 [ 0 ] ) ,
V_100 -> V_20 [ 0 ] . V_27 ) ;
case 3 :
return snprintf ( V_3 , V_106 , V_108 ,
F_21 ( & V_100 -> V_20 [ 0 ] ) ,
V_100 -> V_20 [ 0 ] . V_27 ,
V_100 -> V_20 [ 1 ] . V_27 ,
V_100 -> V_20 [ 2 ] . V_27 ) ;
}
F_7 ( 1 , L_18 ,
V_100 -> V_105 ) ;
return 0 ;
}
static int T_9 F_82 ( void )
{
int V_62 ;
V_82 = F_68 ( L_19 , V_109 ) ;
if ( ! V_82 )
return - V_69 ;
V_62 = F_83 ( & V_110 ) ;
if ( V_62 )
F_66 ( V_82 ) ;
return V_62 ;
}
static void T_10 F_84 ( void )
{
F_85 ( & V_110 ) ;
#ifdef F_86
F_76 ( V_100 ) ;
#endif
F_66 ( V_82 ) ;
}
