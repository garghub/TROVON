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
if ( V_8 ) {
V_6 = V_5 ;
break;
}
}
F_4 ( & V_7 ) ;
return V_6 ;
}
static int F_5 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_5 V_18 ;
strncpy ( V_18 . type , L_1 , sizeof( V_18 . type ) ) ;
V_18 . V_19 = V_6 -> V_20 ;
V_18 . V_21 = V_6 -> V_22 . V_23 ;
V_18 . V_24 = V_6 -> V_22 . V_25 ;
if ( F_6 ( V_17 , V_26 ,
sizeof( struct F_5 ) , & V_18 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_7 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_7 V_29 ;
strncpy ( V_29 . type , L_2 , sizeof( V_29 . type ) ) ;
if ( F_6 ( V_17 , V_30 ,
sizeof( struct F_7 ) , & V_29 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_8 ( struct V_1 * V_6 ,
struct V_2 * V_31 , struct V_16 * V_17 )
{
strncpy ( V_31 -> V_15 , V_6 -> V_14 , sizeof( V_31 -> V_15 ) ) ;
strncpy ( V_31 -> V_12 , V_6 -> V_13 ,
sizeof( V_31 -> V_12 ) ) ;
strncpy ( V_31 -> V_32 , F_9 ( V_6 -> V_33 ) ,
sizeof( V_31 -> V_32 ) ) ;
V_31 -> V_10 = 0 ;
V_31 -> V_11 = 0 ;
V_31 -> V_34 = V_6 -> V_9 ;
V_31 -> V_35 = F_10 ( & V_6 -> V_36 ) ;
if ( F_11 ( V_17 , V_37 , V_6 -> V_38 ) )
goto V_27;
if ( V_6 -> V_9 & V_39 ) {
struct V_40 V_41 ;
strncpy ( V_41 . type , L_3 , sizeof( V_41 . type ) ) ;
if ( F_6 ( V_17 , V_42 ,
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
if ( F_5 ( V_17 , V_6 ) )
goto V_27;
break;
case V_48 :
if ( F_7 ( V_17 , V_6 ) )
goto V_27;
break;
}
V_43:
return 0 ;
V_27:
return - V_28 ;
}
static int F_12 ( struct V_1 * V_6 ,
struct V_49 * V_50 )
{
struct V_16 * V_51 = V_50 -> V_51 ;
struct V_16 * V_17 = V_50 -> V_52 ;
struct V_53 * V_54 ;
struct V_2 * V_31 ;
int V_55 = 0 ;
V_54 = F_13 ( V_17 , F_14 ( V_51 ) . V_56 , V_50 -> V_57 ,
V_58 , sizeof( * V_31 ) , V_50 -> V_59 ) ;
if ( ! V_54 ) {
V_55 = - V_28 ;
goto V_43;
}
V_31 = F_15 ( V_54 ) ;
V_55 = F_8 ( V_6 , V_31 , V_17 ) ;
if ( V_55 ) {
F_16 ( V_17 , V_54 ) ;
goto V_43;
}
F_17 ( V_17 , V_54 ) ;
V_43:
return V_55 ;
}
static int F_18 ( struct V_16 * V_51 , struct V_53 * V_60 ,
struct V_61 * * V_62 )
{
struct V_2 * V_3 = F_15 ( V_60 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_49 V_50 ;
int V_55 ;
if ( ! F_19 ( V_3 -> V_15 ) || ! F_19 ( V_3 -> V_12 ) )
return - V_63 ;
if ( ! V_3 -> V_12 [ 0 ] )
return - V_63 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_64 ;
V_17 = F_20 ( V_65 , V_66 ) ;
if ( ! V_17 )
return - V_67 ;
V_50 . V_51 = V_51 ;
V_50 . V_52 = V_17 ;
V_50 . V_57 = V_60 -> V_57 ;
V_50 . V_59 = 0 ;
V_55 = F_12 ( V_6 , & V_50 ) ;
if ( V_55 )
return V_55 ;
return F_21 ( V_68 , V_17 , F_14 ( V_51 ) . V_56 ) ;
}
static int F_22 ( struct V_16 * V_17 , struct V_69 * V_70 )
{
struct V_1 * V_6 ;
struct V_49 V_50 ;
int V_55 ;
if ( V_70 -> args [ 0 ] )
goto V_43;
V_70 -> args [ 0 ] = 1 ;
V_50 . V_51 = V_70 -> V_17 ;
V_50 . V_52 = V_17 ;
V_50 . V_57 = V_70 -> V_54 -> V_57 ;
V_50 . V_59 = V_71 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_55 = F_12 ( V_6 , & V_50 ) ;
if ( V_55 )
goto V_72;
}
V_43:
return V_17 -> V_73 ;
V_72:
return V_55 ;
}
static int F_23 ( struct V_69 * V_70 )
{
return 0 ;
}
static int F_24 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_61 * V_74 = V_62 [ V_37 ] ;
F_25 ( V_75 ) ;
if ( ! F_19 ( V_3 -> V_15 ) || ! F_19 ( V_3 -> V_12 ) )
return - V_63 ;
if ( V_74 && ! strlen ( V_3 -> V_12 ) )
return - V_63 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_64 ;
F_26 ( & V_7 ) ;
F_27 ( V_6 , & V_75 , NULL ) ;
if ( V_74 )
V_6 -> V_38 = F_28 ( V_74 ) ;
F_29 ( & V_7 ) ;
F_30 ( & V_75 ) ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_54 ) ;
if ( ! F_19 ( V_3 -> V_15 ) || ! F_19 ( V_3 -> V_12 ) )
return - V_63 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_64 ;
if ( ! ( V_6 -> V_9 & V_76 ) )
return - V_63 ;
if ( F_10 ( & V_6 -> V_36 ) != 1 )
return - V_77 ;
return F_32 ( V_6 ) ;
}
static struct V_1 * F_33 ( const char * V_78 , T_1 type ,
T_1 V_79 )
{
int V_55 ;
struct V_1 * V_6 ;
type = F_34 ( type ) ;
V_79 = F_35 ( V_79 ) ;
for (; ; ) {
V_6 = F_36 ( V_78 , type , V_79 ) ;
if ( ! F_37 ( V_6 ) )
return V_6 ;
V_55 = F_38 ( V_6 ) ;
if ( V_55 != - V_80 )
break;
if ( F_39 ( V_81 ) ) {
V_55 = - V_82 ;
break;
}
}
return F_40 ( V_55 ) ;
}
static struct V_1 * F_41 ( const char * V_78 , T_1 type ,
T_1 V_79 )
{
int V_55 ;
struct V_1 * V_6 ;
type &= ~ ( V_46 | V_83 ) ;
type |= V_84 ;
V_79 &= ~ ( V_46 | V_83 ) ;
V_79 |= V_46 ;
for (; ; ) {
V_6 = F_42 ( V_78 , type , V_79 ) ;
if ( ! F_37 ( V_6 ) )
return V_6 ;
V_55 = F_38 ( V_6 ) ;
if ( V_55 != - V_80 )
break;
if ( F_39 ( V_81 ) ) {
V_55 = - V_82 ;
break;
}
}
return F_40 ( V_55 ) ;
}
static int F_43 ( struct V_16 * V_17 , struct V_53 * V_54 ,
struct V_61 * * V_62 )
{
int V_4 = 0 ;
const char * V_78 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_61 * V_74 = V_62 [ V_37 ] ;
if ( ! F_19 ( V_3 -> V_15 ) || ! F_19 ( V_3 -> V_12 ) )
return - V_63 ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_74 && ! V_4 )
return - V_63 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 )
return - V_85 ;
if ( strlen ( V_3 -> V_12 ) )
V_78 = V_3 -> V_12 ;
else
V_78 = V_3 -> V_15 ;
switch ( V_3 -> V_10 & V_3 -> V_11 & V_46 ) {
case V_84 :
V_6 = F_41 ( V_78 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
V_6 = F_33 ( V_78 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
default:
V_6 = F_44 ( V_78 , V_3 -> V_10 , V_3 -> V_11 ) ;
}
if ( F_37 ( V_6 ) )
return F_38 ( V_6 ) ;
F_26 ( & V_7 ) ;
if ( V_74 )
V_6 -> V_38 = F_28 ( V_74 ) ;
F_29 ( & V_7 ) ;
F_45 ( V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_16 * V_17 , struct V_53 * V_54 )
{
struct V_61 * V_62 [ V_89 + 1 ] ;
const struct V_90 * V_91 ;
int type , V_55 ;
type = V_54 -> V_92 ;
if ( type > V_93 )
return - V_63 ;
type -= V_94 ;
V_91 = & V_95 [ type ] ;
if ( ! F_47 ( V_96 ) )
return - V_97 ;
if ( ( type == ( V_58 - V_94 ) &&
( V_54 -> V_59 & V_98 ) ) ) {
struct V_1 * V_6 ;
T_2 V_99 = 0 ;
if ( V_91 -> V_100 == NULL )
return - V_63 ;
F_3 (alg, &crypto_alg_list, cra_list)
V_99 += V_101 ;
{
struct V_102 V_103 = {
. V_100 = V_91 -> V_100 ,
. V_104 = V_91 -> V_104 ,
. V_105 = V_99 ,
} ;
return F_48 ( V_68 , V_17 , V_54 , & V_103 ) ;
}
}
V_55 = F_49 ( V_54 , V_106 [ type ] , V_62 , V_89 ,
V_107 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_91 -> V_108 == NULL )
return - V_63 ;
return V_91 -> V_108 ( V_17 , V_54 , V_62 ) ;
}
static void F_50 ( struct V_16 * V_17 )
{
F_51 ( & V_109 ) ;
F_52 ( V_17 , & F_46 ) ;
F_53 ( & V_109 ) ;
}
static int T_3 F_54 ( void )
{
struct V_110 V_111 = {
. V_112 = F_50 ,
} ;
V_68 = F_55 ( & V_113 , V_114 , & V_111 ) ;
if ( ! V_68 )
return - V_67 ;
return 0 ;
}
static void T_4 F_56 ( void )
{
F_57 ( V_68 ) ;
}
