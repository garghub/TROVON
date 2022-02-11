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
static int F_10 ( struct V_1 * V_6 ,
struct V_2 * V_31 , struct V_16 * V_17 )
{
strncpy ( V_31 -> V_15 , V_6 -> V_14 , sizeof( V_31 -> V_15 ) ) ;
strncpy ( V_31 -> V_12 , V_6 -> V_13 ,
sizeof( V_31 -> V_12 ) ) ;
strncpy ( V_31 -> V_32 , F_11 ( V_6 -> V_33 ) ,
sizeof( V_31 -> V_32 ) ) ;
V_31 -> V_10 = 0 ;
V_31 -> V_11 = 0 ;
V_31 -> V_34 = V_6 -> V_9 ;
V_31 -> V_35 = F_12 ( & V_6 -> V_36 ) ;
if ( F_13 ( V_17 , V_37 , V_6 -> V_38 ) )
goto V_27;
if ( V_6 -> V_9 & V_39 ) {
struct V_40 V_41 ;
strncpy ( V_41 . type , L_3 , sizeof( V_41 . type ) ) ;
if ( F_8 ( V_17 , V_42 ,
sizeof( struct V_40 ) , & V_41 ) )
goto V_27;
goto V_43;
}
if ( V_6 -> V_44 && V_6 -> V_44 -> V_45 ) {
if ( V_6 -> V_44 -> V_45 ( V_17 , V_6 ) )
goto V_27;
goto V_43;
}
switch ( V_6 -> V_9 & ( V_46 | V_39 ) ) {
case V_47 :
if ( F_7 ( V_17 , V_6 ) )
goto V_27;
break;
case V_48 :
if ( F_9 ( V_17 , V_6 ) )
goto V_27;
break;
}
V_43:
return 0 ;
V_27:
return - V_28 ;
}
static int F_14 ( struct V_1 * V_6 ,
struct V_49 * V_50 )
{
struct V_16 * V_51 = V_50 -> V_51 ;
struct V_16 * V_17 = V_50 -> V_52 ;
struct V_53 * V_54 ;
struct V_2 * V_31 ;
int V_55 = 0 ;
V_54 = F_15 ( V_17 , F_16 ( V_51 ) . V_56 , V_50 -> V_57 ,
V_58 , sizeof( * V_31 ) , V_50 -> V_59 ) ;
if ( ! V_54 ) {
V_55 = - V_28 ;
goto V_43;
}
V_31 = F_17 ( V_54 ) ;
V_55 = F_10 ( V_6 , V_31 , V_17 ) ;
if ( V_55 ) {
F_18 ( V_17 , V_54 ) ;
goto V_43;
}
F_19 ( V_17 , V_54 ) ;
V_43:
return V_55 ;
}
static int F_20 ( struct V_16 * V_51 , struct V_53 * V_60 ,
struct V_61 * * V_62 )
{
struct V_2 * V_3 = F_17 ( V_60 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_49 V_50 ;
int V_55 ;
if ( ! F_21 ( V_3 -> V_15 ) || ! F_21 ( V_3 -> V_12 ) )
return - V_63 ;
V_6 = F_1 ( V_3 , 0 ) ;
if ( ! V_6 )
return - V_64 ;
V_55 = - V_65 ;
V_17 = F_22 ( V_66 , V_67 ) ;
if ( ! V_17 )
goto V_68;
V_50 . V_51 = V_51 ;
V_50 . V_52 = V_17 ;
V_50 . V_57 = V_60 -> V_57 ;
V_50 . V_59 = 0 ;
V_55 = F_14 ( V_6 , & V_50 ) ;
V_68:
F_23 ( V_6 ) ;
if ( V_55 )
return V_55 ;
return F_24 ( V_69 , V_17 , F_16 ( V_51 ) . V_56 ) ;
}
static int F_25 ( struct V_16 * V_17 , struct V_70 * V_71 )
{
struct V_1 * V_6 ;
struct V_49 V_50 ;
int V_55 ;
if ( V_71 -> args [ 0 ] )
goto V_43;
V_71 -> args [ 0 ] = 1 ;
V_50 . V_51 = V_71 -> V_17 ;
V_50 . V_52 = V_17 ;
V_50 . V_57 = V_71 -> V_54 -> V_57 ;
V_50 . V_59 = V_72 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_55 = F_14 ( V_6 , & V_50 ) ;
if ( V_55 )
goto V_73;
}
V_43:
return V_17 -> V_74 ;
V_73:
return V_55 ;
}
static int F_26 ( struct V_70 * V_71 )
{
return 0 ;
}
static int F_27 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_17 ( V_54 ) ;
struct V_61 * V_75 = V_62 [ V_37 ] ;
F_28 ( V_76 ) ;
if ( ! F_29 ( V_17 , V_77 ) )
return - V_78 ;
if ( ! F_21 ( V_3 -> V_15 ) || ! F_21 ( V_3 -> V_12 ) )
return - V_63 ;
if ( V_75 && ! strlen ( V_3 -> V_12 ) )
return - V_63 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_64 ;
F_30 ( & V_7 ) ;
F_31 ( V_6 , & V_76 , NULL ) ;
if ( V_75 )
V_6 -> V_38 = F_32 ( V_75 ) ;
F_33 ( & V_7 ) ;
F_23 ( V_6 ) ;
F_34 ( & V_76 ) ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_17 ( V_54 ) ;
int V_55 ;
if ( ! F_29 ( V_17 , V_77 ) )
return - V_78 ;
if ( ! F_21 ( V_3 -> V_15 ) || ! F_21 ( V_3 -> V_12 ) )
return - V_63 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_64 ;
V_55 = - V_63 ;
if ( ! ( V_6 -> V_9 & V_79 ) )
goto V_68;
V_55 = - V_80 ;
if ( F_12 ( & V_6 -> V_36 ) > 2 )
goto V_68;
V_55 = F_36 ( (struct V_81 * ) V_6 ) ;
V_68:
F_23 ( V_6 ) ;
return V_55 ;
}
static struct V_1 * F_37 ( const char * V_82 , T_1 type ,
T_1 V_83 )
{
int V_55 ;
struct V_1 * V_6 ;
type = F_38 ( type ) ;
V_83 = F_39 ( V_83 ) ;
for (; ; ) {
V_6 = F_40 ( V_82 , type , V_83 ) ;
if ( ! F_41 ( V_6 ) )
return V_6 ;
V_55 = F_42 ( V_6 ) ;
if ( V_55 != - V_84 )
break;
if ( F_43 ( V_85 ) ) {
V_55 = - V_86 ;
break;
}
}
return F_44 ( V_55 ) ;
}
static struct V_1 * F_45 ( const char * V_82 , T_1 type ,
T_1 V_83 )
{
int V_55 ;
struct V_1 * V_6 ;
type &= ~ ( V_46 | V_87 ) ;
type |= V_88 ;
V_83 &= ~ ( V_46 | V_87 ) ;
V_83 |= V_46 ;
for (; ; ) {
V_6 = F_46 ( V_82 , type , V_83 ) ;
if ( ! F_41 ( V_6 ) )
return V_6 ;
V_55 = F_42 ( V_6 ) ;
if ( V_55 != - V_84 )
break;
if ( F_43 ( V_85 ) ) {
V_55 = - V_86 ;
break;
}
}
return F_44 ( V_55 ) ;
}
static int F_47 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
int V_4 = 0 ;
const char * V_82 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_17 ( V_54 ) ;
struct V_61 * V_75 = V_62 [ V_37 ] ;
if ( ! F_29 ( V_17 , V_77 ) )
return - V_78 ;
if ( ! F_21 ( V_3 -> V_15 ) || ! F_21 ( V_3 -> V_12 ) )
return - V_63 ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_75 && ! V_4 )
return - V_63 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 ) {
F_23 ( V_6 ) ;
return - V_89 ;
}
if ( strlen ( V_3 -> V_12 ) )
V_82 = V_3 -> V_12 ;
else
V_82 = V_3 -> V_15 ;
switch ( V_3 -> V_10 & V_3 -> V_11 & V_46 ) {
case V_88 :
V_6 = F_45 ( V_82 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
case V_90 :
case V_91 :
case V_92 :
V_6 = F_37 ( V_82 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
default:
V_6 = F_48 ( V_82 , V_3 -> V_10 , V_3 -> V_11 ) ;
}
if ( F_41 ( V_6 ) )
return F_42 ( V_6 ) ;
F_30 ( & V_7 ) ;
if ( V_75 )
V_6 -> V_38 = F_32 ( V_75 ) ;
F_33 ( & V_7 ) ;
F_23 ( V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_16 * V_17 , struct V_53 * V_54 )
{
struct V_61 * V_62 [ V_93 + 1 ] ;
const struct V_94 * V_95 ;
int type , V_55 ;
type = V_54 -> V_96 ;
if ( type > V_97 )
return - V_63 ;
type -= V_98 ;
V_95 = & V_99 [ type ] ;
if ( ( type == ( V_58 - V_98 ) &&
( V_54 -> V_59 & V_100 ) ) ) {
struct V_1 * V_6 ;
T_2 V_101 = 0 ;
if ( V_95 -> V_102 == NULL )
return - V_63 ;
F_3 (alg, &crypto_alg_list, cra_list)
V_101 += V_103 ;
{
struct V_104 V_105 = {
. V_102 = V_95 -> V_102 ,
. V_106 = V_95 -> V_106 ,
. V_107 = V_101 ,
} ;
return F_50 ( V_69 , V_17 , V_54 , & V_105 ) ;
}
}
V_55 = F_51 ( V_54 , V_108 [ type ] , V_62 , V_93 ,
V_109 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_95 -> V_110 == NULL )
return - V_63 ;
return V_95 -> V_110 ( V_17 , V_54 , V_62 ) ;
}
static void F_52 ( struct V_16 * V_17 )
{
F_53 ( & V_111 ) ;
F_54 ( V_17 , & F_49 ) ;
F_55 ( & V_111 ) ;
}
static int T_3 F_56 ( void )
{
struct V_112 V_113 = {
. V_114 = F_52 ,
} ;
V_69 = F_57 ( & V_115 , V_116 , & V_113 ) ;
if ( ! V_69 )
return - V_65 ;
return 0 ;
}
static void T_4 F_58 ( void )
{
F_59 ( V_69 ) ;
}
