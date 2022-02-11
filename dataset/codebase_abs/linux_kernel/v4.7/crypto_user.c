static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 , * V_6 = NULL ;
F_2 ( & V_7 ) ;
F_3 (q, &crypto_alg_list, cra_list) {
int V_8 = 0 ;
if ( ( V_5 -> V_9 ^ V_3 -> V_10 ) & V_3 -> V_11 )
continue;
if ( strlen ( V_3 -> V_12 ) )
V_8 = ! strcmp ( V_5 -> V_13 ,
V_3 -> V_12 ) ;
else if ( ! V_4 )
V_8 = ! strcmp ( V_5 -> V_14 , V_3 -> V_15 ) ;
if ( ! V_8 )
continue;
if ( F_4 ( ! F_5 ( V_5 ) ) )
continue;
V_6 = V_5 ;
break;
}
F_6 ( & V_7 ) ;
return V_6 ;
}
static int F_7 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_7 V_18 ;
strncpy ( V_18 . type , L_1 , sizeof( V_18 . type ) ) ;
V_18 . V_19 = V_6 -> V_20 ;
V_18 . V_21 = V_6 -> V_22 . V_23 ;
V_18 . V_24 = V_6 -> V_22 . V_25 ;
if ( F_8 ( V_17 , V_26 ,
sizeof( struct F_7 ) , & V_18 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_9 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_9 V_29 ;
strncpy ( V_29 . type , L_2 , sizeof( V_29 . type ) ) ;
if ( F_8 ( V_17 , V_30 ,
sizeof( struct F_9 ) , & V_29 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_10 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_10 V_31 ;
strncpy ( V_31 . type , L_3 , sizeof( V_31 . type ) ) ;
if ( F_8 ( V_17 , V_32 ,
sizeof( struct F_10 ) , & V_31 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_11 ( struct V_1 * V_6 ,
struct V_2 * V_33 , struct V_16 * V_17 )
{
strncpy ( V_33 -> V_15 , V_6 -> V_14 , sizeof( V_33 -> V_15 ) ) ;
strncpy ( V_33 -> V_12 , V_6 -> V_13 ,
sizeof( V_33 -> V_12 ) ) ;
strncpy ( V_33 -> V_34 , F_12 ( V_6 -> V_35 ) ,
sizeof( V_33 -> V_34 ) ) ;
V_33 -> V_10 = 0 ;
V_33 -> V_11 = 0 ;
V_33 -> V_36 = V_6 -> V_9 ;
V_33 -> V_37 = F_13 ( & V_6 -> V_38 ) ;
if ( F_14 ( V_17 , V_39 , V_6 -> V_40 ) )
goto V_27;
if ( V_6 -> V_9 & V_41 ) {
struct V_42 V_43 ;
strncpy ( V_43 . type , L_4 , sizeof( V_43 . type ) ) ;
if ( F_8 ( V_17 , V_44 ,
sizeof( struct V_42 ) , & V_43 ) )
goto V_27;
goto V_45;
}
if ( V_6 -> V_46 && V_6 -> V_46 -> V_47 ) {
if ( V_6 -> V_46 -> V_47 ( V_17 , V_6 ) )
goto V_27;
goto V_45;
}
switch ( V_6 -> V_9 & ( V_48 | V_41 ) ) {
case V_49 :
if ( F_7 ( V_17 , V_6 ) )
goto V_27;
break;
case V_50 :
if ( F_9 ( V_17 , V_6 ) )
goto V_27;
break;
case V_51 :
if ( F_10 ( V_17 , V_6 ) )
goto V_27;
break;
}
V_45:
return 0 ;
V_27:
return - V_28 ;
}
static int F_15 ( struct V_1 * V_6 ,
struct V_52 * V_53 )
{
struct V_16 * V_54 = V_53 -> V_54 ;
struct V_16 * V_17 = V_53 -> V_55 ;
struct V_56 * V_57 ;
struct V_2 * V_33 ;
int V_58 = 0 ;
V_57 = F_16 ( V_17 , F_17 ( V_54 ) . V_59 , V_53 -> V_60 ,
V_61 , sizeof( * V_33 ) , V_53 -> V_62 ) ;
if ( ! V_57 ) {
V_58 = - V_28 ;
goto V_45;
}
V_33 = F_18 ( V_57 ) ;
V_58 = F_11 ( V_6 , V_33 , V_17 ) ;
if ( V_58 ) {
F_19 ( V_17 , V_57 ) ;
goto V_45;
}
F_20 ( V_17 , V_57 ) ;
V_45:
return V_58 ;
}
static int F_21 ( struct V_16 * V_54 , struct V_56 * V_63 ,
struct V_64 * * V_65 )
{
struct V_2 * V_3 = F_18 ( V_63 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_52 V_53 ;
int V_58 ;
if ( ! F_22 ( V_3 -> V_15 ) || ! F_22 ( V_3 -> V_12 ) )
return - V_66 ;
V_6 = F_1 ( V_3 , 0 ) ;
if ( ! V_6 )
return - V_67 ;
V_58 = - V_68 ;
V_17 = F_23 ( V_69 , V_70 ) ;
if ( ! V_17 )
goto V_71;
V_53 . V_54 = V_54 ;
V_53 . V_55 = V_17 ;
V_53 . V_60 = V_63 -> V_60 ;
V_53 . V_62 = 0 ;
V_58 = F_15 ( V_6 , & V_53 ) ;
V_71:
F_24 ( V_6 ) ;
if ( V_58 )
return V_58 ;
return F_25 ( V_72 , V_17 , F_17 ( V_54 ) . V_59 ) ;
}
static int F_26 ( struct V_16 * V_17 , struct V_73 * V_74 )
{
struct V_1 * V_6 ;
struct V_52 V_53 ;
int V_58 ;
if ( V_74 -> args [ 0 ] )
goto V_45;
V_74 -> args [ 0 ] = 1 ;
V_53 . V_54 = V_74 -> V_17 ;
V_53 . V_55 = V_17 ;
V_53 . V_60 = V_74 -> V_57 -> V_60 ;
V_53 . V_62 = V_75 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_58 = F_15 ( V_6 , & V_53 ) ;
if ( V_58 )
goto V_76;
}
V_45:
return V_17 -> V_77 ;
V_76:
return V_58 ;
}
static int F_27 ( struct V_73 * V_74 )
{
return 0 ;
}
static int F_28 ( struct V_16 * V_17 , struct V_56 * V_57 ,
struct V_64 * * V_65 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_18 ( V_57 ) ;
struct V_64 * V_78 = V_65 [ V_39 ] ;
F_29 ( V_79 ) ;
if ( ! F_30 ( V_17 , V_80 ) )
return - V_81 ;
if ( ! F_22 ( V_3 -> V_15 ) || ! F_22 ( V_3 -> V_12 ) )
return - V_66 ;
if ( V_78 && ! strlen ( V_3 -> V_12 ) )
return - V_66 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_67 ;
F_31 ( & V_7 ) ;
F_32 ( V_6 , & V_79 , NULL ) ;
if ( V_78 )
V_6 -> V_40 = F_33 ( V_78 ) ;
F_34 ( & V_7 ) ;
F_24 ( V_6 ) ;
F_35 ( & V_79 ) ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 , struct V_56 * V_57 ,
struct V_64 * * V_65 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_18 ( V_57 ) ;
int V_58 ;
if ( ! F_30 ( V_17 , V_80 ) )
return - V_81 ;
if ( ! F_22 ( V_3 -> V_15 ) || ! F_22 ( V_3 -> V_12 ) )
return - V_66 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_67 ;
V_58 = - V_66 ;
if ( ! ( V_6 -> V_9 & V_82 ) )
goto V_71;
V_58 = - V_83 ;
if ( F_13 ( & V_6 -> V_38 ) > 2 )
goto V_71;
V_58 = F_37 ( (struct V_84 * ) V_6 ) ;
V_71:
F_24 ( V_6 ) ;
return V_58 ;
}
static struct V_1 * F_38 ( const char * V_85 , T_1 type ,
T_1 V_86 )
{
int V_58 ;
struct V_1 * V_6 ;
type = F_39 ( type ) ;
V_86 = F_40 ( V_86 ) ;
for (; ; ) {
V_6 = F_41 ( V_85 , type , V_86 ) ;
if ( ! F_42 ( V_6 ) )
return V_6 ;
V_58 = F_43 ( V_6 ) ;
if ( V_58 != - V_87 )
break;
if ( F_44 ( V_88 ) ) {
V_58 = - V_89 ;
break;
}
}
return F_45 ( V_58 ) ;
}
static int F_46 ( struct V_16 * V_17 , struct V_56 * V_57 ,
struct V_64 * * V_65 )
{
int V_4 = 0 ;
const char * V_85 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_18 ( V_57 ) ;
struct V_64 * V_78 = V_65 [ V_39 ] ;
if ( ! F_30 ( V_17 , V_80 ) )
return - V_81 ;
if ( ! F_22 ( V_3 -> V_15 ) || ! F_22 ( V_3 -> V_12 ) )
return - V_66 ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_78 && ! V_4 )
return - V_66 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 ) {
F_24 ( V_6 ) ;
return - V_90 ;
}
if ( strlen ( V_3 -> V_12 ) )
V_85 = V_3 -> V_12 ;
else
V_85 = V_3 -> V_15 ;
switch ( V_3 -> V_10 & V_3 -> V_11 & V_48 ) {
case V_91 :
case V_92 :
case V_93 :
V_6 = F_38 ( V_85 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
default:
V_6 = F_47 ( V_85 , V_3 -> V_10 , V_3 -> V_11 ) ;
}
if ( F_42 ( V_6 ) )
return F_43 ( V_6 ) ;
F_31 ( & V_7 ) ;
if ( V_78 )
V_6 -> V_40 = F_33 ( V_78 ) ;
F_34 ( & V_7 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_16 * V_17 , struct V_56 * V_57 ,
struct V_64 * * V_65 )
{
if ( ! F_30 ( V_17 , V_80 ) )
return - V_81 ;
return F_49 () ;
}
static int F_50 ( struct V_16 * V_17 , struct V_56 * V_57 )
{
struct V_64 * V_65 [ V_94 + 1 ] ;
const struct V_95 * V_96 ;
int type , V_58 ;
type = V_57 -> V_97 ;
if ( type > V_98 )
return - V_66 ;
type -= V_99 ;
V_96 = & V_100 [ type ] ;
if ( ( type == ( V_61 - V_99 ) &&
( V_57 -> V_62 & V_101 ) ) ) {
struct V_1 * V_6 ;
T_2 V_102 = 0 ;
if ( V_96 -> V_103 == NULL )
return - V_66 ;
F_2 ( & V_7 ) ;
F_3 (alg, &crypto_alg_list, cra_list)
V_102 += V_104 ;
{
struct V_105 V_106 = {
. V_103 = V_96 -> V_103 ,
. V_107 = V_96 -> V_107 ,
. V_108 = V_102 ,
} ;
V_58 = F_51 ( V_72 , V_17 , V_57 , & V_106 ) ;
}
F_6 ( & V_7 ) ;
return V_58 ;
}
V_58 = F_52 ( V_57 , V_109 [ type ] , V_65 , V_94 ,
V_110 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_96 -> V_111 == NULL )
return - V_66 ;
return V_96 -> V_111 ( V_17 , V_57 , V_65 ) ;
}
static void F_53 ( struct V_16 * V_17 )
{
F_54 ( & V_112 ) ;
F_55 ( V_17 , & F_50 ) ;
F_56 ( & V_112 ) ;
}
static int T_3 F_57 ( void )
{
struct V_113 V_114 = {
. V_115 = F_53 ,
} ;
V_72 = F_58 ( & V_116 , V_117 , & V_114 ) ;
if ( ! V_72 )
return - V_68 ;
return 0 ;
}
static void T_4 F_59 ( void )
{
F_60 ( V_72 ) ;
}
