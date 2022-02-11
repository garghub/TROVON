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
snprintf ( V_18 . type , V_19 , L_1 , L_2 ) ;
V_18 . V_20 = V_6 -> V_21 ;
V_18 . V_22 = V_6 -> V_23 . V_24 ;
V_18 . V_25 = V_6 -> V_23 . V_26 ;
if ( F_6 ( V_17 , V_27 ,
sizeof( struct F_5 ) , & V_18 ) )
goto V_28;
return 0 ;
V_28:
return - V_29 ;
}
static int F_7 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_7 V_30 ;
snprintf ( V_30 . type , V_19 , L_1 , L_3 ) ;
if ( F_6 ( V_17 , V_31 ,
sizeof( struct F_7 ) , & V_30 ) )
goto V_28;
return 0 ;
V_28:
return - V_29 ;
}
static int F_8 ( struct V_1 * V_6 ,
struct V_2 * V_32 , struct V_16 * V_17 )
{
memcpy ( & V_32 -> V_15 , & V_6 -> V_14 , sizeof( V_32 -> V_15 ) ) ;
memcpy ( & V_32 -> V_12 , & V_6 -> V_13 ,
sizeof( V_32 -> V_12 ) ) ;
memcpy ( & V_32 -> V_33 , F_9 ( V_6 -> V_34 ) ,
V_19 ) ;
V_32 -> V_35 = V_6 -> V_9 ;
V_32 -> V_36 = F_10 ( & V_6 -> V_37 ) ;
if ( F_11 ( V_17 , V_38 , V_6 -> V_39 ) )
goto V_28;
if ( V_6 -> V_9 & V_40 ) {
struct V_41 V_42 ;
snprintf ( V_42 . type , V_19 , L_1 , L_4 ) ;
if ( F_6 ( V_17 , V_43 ,
sizeof( struct V_41 ) , & V_42 ) )
goto V_28;
goto V_44;
}
if ( V_6 -> V_45 && V_6 -> V_45 -> V_46 ) {
if ( V_6 -> V_45 -> V_46 ( V_17 , V_6 ) )
goto V_28;
goto V_44;
}
switch ( V_6 -> V_9 & ( V_47 | V_40 ) ) {
case V_48 :
if ( F_5 ( V_17 , V_6 ) )
goto V_28;
break;
case V_49 :
if ( F_7 ( V_17 , V_6 ) )
goto V_28;
break;
}
V_44:
return 0 ;
V_28:
return - V_29 ;
}
static int F_12 ( struct V_1 * V_6 ,
struct V_50 * V_51 )
{
struct V_16 * V_52 = V_51 -> V_52 ;
struct V_16 * V_17 = V_51 -> V_53 ;
struct V_54 * V_55 ;
struct V_2 * V_32 ;
int V_56 = 0 ;
V_55 = F_13 ( V_17 , F_14 ( V_52 ) . V_57 , V_51 -> V_58 ,
V_59 , sizeof( * V_32 ) , V_51 -> V_60 ) ;
if ( ! V_55 ) {
V_56 = - V_29 ;
goto V_44;
}
V_32 = F_15 ( V_55 ) ;
V_56 = F_8 ( V_6 , V_32 , V_17 ) ;
if ( V_56 ) {
F_16 ( V_17 , V_55 ) ;
goto V_44;
}
F_17 ( V_17 , V_55 ) ;
V_44:
return V_56 ;
}
static int F_18 ( struct V_16 * V_52 , struct V_54 * V_61 ,
struct V_62 * * V_63 )
{
struct V_2 * V_3 = F_15 ( V_61 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_50 V_51 ;
int V_56 ;
if ( ! V_3 -> V_12 )
return - V_64 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_65 ;
V_17 = F_19 ( V_66 , V_67 ) ;
if ( ! V_17 )
return - V_68 ;
V_51 . V_52 = V_52 ;
V_51 . V_53 = V_17 ;
V_51 . V_58 = V_61 -> V_58 ;
V_51 . V_60 = 0 ;
V_56 = F_12 ( V_6 , & V_51 ) ;
if ( V_56 )
return V_56 ;
return F_20 ( V_69 , V_17 , F_14 ( V_52 ) . V_57 ) ;
}
static int F_21 ( struct V_16 * V_17 , struct V_70 * V_71 )
{
struct V_1 * V_6 ;
struct V_50 V_51 ;
int V_56 ;
if ( V_71 -> args [ 0 ] )
goto V_44;
V_71 -> args [ 0 ] = 1 ;
V_51 . V_52 = V_71 -> V_17 ;
V_51 . V_53 = V_17 ;
V_51 . V_58 = V_71 -> V_55 -> V_58 ;
V_51 . V_60 = V_72 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_56 = F_12 ( V_6 , & V_51 ) ;
if ( V_56 )
goto V_73;
}
V_44:
return V_17 -> V_74 ;
V_73:
return V_56 ;
}
static int F_22 ( struct V_70 * V_71 )
{
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_54 * V_55 ,
struct V_62 * * V_63 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_55 ) ;
struct V_62 * V_75 = V_63 [ V_38 ] ;
F_24 ( V_76 ) ;
if ( V_75 && ! strlen ( V_3 -> V_12 ) )
return - V_64 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_65 ;
F_25 ( & V_7 ) ;
F_26 ( V_6 , & V_76 , NULL ) ;
if ( V_75 )
V_6 -> V_39 = F_27 ( V_75 ) ;
F_28 ( & V_7 ) ;
F_29 ( & V_76 ) ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 , struct V_54 * V_55 ,
struct V_62 * * V_63 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_55 ) ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_65 ;
if ( ! ( V_6 -> V_9 & V_77 ) )
return - V_64 ;
if ( F_10 ( & V_6 -> V_37 ) != 1 )
return - V_78 ;
return F_31 ( V_6 ) ;
}
static struct V_1 * F_32 ( const char * V_79 , T_1 type ,
T_1 V_80 )
{
int V_56 ;
struct V_1 * V_6 ;
type = F_33 ( type ) ;
V_80 = F_34 ( V_80 ) ;
for (; ; ) {
V_6 = F_35 ( V_79 , type , V_80 ) ;
if ( ! F_36 ( V_6 ) )
return V_6 ;
V_56 = F_37 ( V_6 ) ;
if ( V_56 != - V_81 )
break;
if ( F_38 ( V_82 ) ) {
V_56 = - V_83 ;
break;
}
}
return F_39 ( V_56 ) ;
}
static struct V_1 * F_40 ( const char * V_79 , T_1 type ,
T_1 V_80 )
{
int V_56 ;
struct V_1 * V_6 ;
type &= ~ ( V_47 | V_84 ) ;
type |= V_85 ;
V_80 &= ~ ( V_47 | V_84 ) ;
V_80 |= V_47 ;
for (; ; ) {
V_6 = F_41 ( V_79 , type , V_80 ) ;
if ( ! F_36 ( V_6 ) )
return V_6 ;
V_56 = F_37 ( V_6 ) ;
if ( V_56 != - V_81 )
break;
if ( F_38 ( V_82 ) ) {
V_56 = - V_83 ;
break;
}
}
return F_39 ( V_56 ) ;
}
static int F_42 ( struct V_16 * V_17 , struct V_54 * V_55 ,
struct V_62 * * V_63 )
{
int V_4 = 0 ;
const char * V_79 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_15 ( V_55 ) ;
struct V_62 * V_75 = V_63 [ V_38 ] ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_75 && ! V_4 )
return - V_64 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 )
return - V_86 ;
if ( strlen ( V_3 -> V_12 ) )
V_79 = V_3 -> V_12 ;
else
V_79 = V_3 -> V_15 ;
switch ( V_3 -> V_10 & V_3 -> V_11 & V_47 ) {
case V_85 :
V_6 = F_40 ( V_79 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
V_6 = F_32 ( V_79 , V_3 -> V_10 , V_3 -> V_11 ) ;
break;
default:
V_6 = F_43 ( V_79 , V_3 -> V_10 , V_3 -> V_11 ) ;
}
if ( F_36 ( V_6 ) )
return F_37 ( V_6 ) ;
F_25 ( & V_7 ) ;
if ( V_75 )
V_6 -> V_39 = F_27 ( V_75 ) ;
F_28 ( & V_7 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 , struct V_54 * V_55 )
{
struct V_62 * V_63 [ V_90 + 1 ] ;
struct V_91 * V_92 ;
int type , V_56 ;
type = V_55 -> V_93 ;
if ( type > V_94 )
return - V_64 ;
type -= V_95 ;
V_92 = & V_96 [ type ] ;
if ( ! F_46 ( V_97 ) )
return - V_98 ;
if ( ( type == ( V_59 - V_95 ) &&
( V_55 -> V_60 & V_99 ) ) ) {
struct V_1 * V_6 ;
T_2 V_100 = 0 ;
if ( V_92 -> V_101 == NULL )
return - V_64 ;
F_3 (alg, &crypto_alg_list, cra_list)
V_100 += V_102 ;
{
struct V_103 V_104 = {
. V_101 = V_92 -> V_101 ,
. V_105 = V_92 -> V_105 ,
. V_106 = V_100 ,
} ;
return F_47 ( V_69 , V_17 , V_55 , & V_104 ) ;
}
}
V_56 = F_48 ( V_55 , V_107 [ type ] , V_63 , V_90 ,
V_108 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_92 -> V_109 == NULL )
return - V_64 ;
return V_92 -> V_109 ( V_17 , V_55 , V_63 ) ;
}
static void F_49 ( struct V_16 * V_17 )
{
F_50 ( & V_110 ) ;
F_51 ( V_17 , & F_45 ) ;
F_52 ( & V_110 ) ;
}
static int T_3 F_53 ( void )
{
struct V_111 V_112 = {
. V_113 = F_49 ,
} ;
V_69 = F_54 ( & V_114 , V_115 ,
V_116 , & V_112 ) ;
if ( ! V_69 )
return - V_68 ;
return 0 ;
}
static void T_4 F_55 ( void )
{
F_56 ( V_69 ) ;
}
