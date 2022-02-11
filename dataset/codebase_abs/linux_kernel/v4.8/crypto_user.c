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
static int F_11 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_11 V_33 ;
strncpy ( V_33 . type , L_4 , sizeof( V_33 . type ) ) ;
if ( F_8 ( V_17 , V_34 ,
sizeof( struct F_11 ) , & V_33 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_12 ( struct V_1 * V_6 ,
struct V_2 * V_35 , struct V_16 * V_17 )
{
strncpy ( V_35 -> V_15 , V_6 -> V_14 , sizeof( V_35 -> V_15 ) ) ;
strncpy ( V_35 -> V_12 , V_6 -> V_13 ,
sizeof( V_35 -> V_12 ) ) ;
strncpy ( V_35 -> V_36 , F_13 ( V_6 -> V_37 ) ,
sizeof( V_35 -> V_36 ) ) ;
V_35 -> V_10 = 0 ;
V_35 -> V_11 = 0 ;
V_35 -> V_38 = V_6 -> V_9 ;
V_35 -> V_39 = F_14 ( & V_6 -> V_40 ) ;
if ( F_15 ( V_17 , V_41 , V_6 -> V_42 ) )
goto V_27;
if ( V_6 -> V_9 & V_43 ) {
struct V_44 V_45 ;
strncpy ( V_45 . type , L_5 , sizeof( V_45 . type ) ) ;
if ( F_8 ( V_17 , V_46 ,
sizeof( struct V_44 ) , & V_45 ) )
goto V_27;
goto V_47;
}
if ( V_6 -> V_48 && V_6 -> V_48 -> V_49 ) {
if ( V_6 -> V_48 -> V_49 ( V_17 , V_6 ) )
goto V_27;
goto V_47;
}
switch ( V_6 -> V_9 & ( V_50 | V_43 ) ) {
case V_51 :
if ( F_7 ( V_17 , V_6 ) )
goto V_27;
break;
case V_52 :
if ( F_9 ( V_17 , V_6 ) )
goto V_27;
break;
case V_53 :
if ( F_10 ( V_17 , V_6 ) )
goto V_27;
break;
case V_54 :
if ( F_11 ( V_17 , V_6 ) )
goto V_27;
break;
}
V_47:
return 0 ;
V_27:
return - V_28 ;
}
static int F_16 ( struct V_1 * V_6 ,
struct V_55 * V_56 )
{
struct V_16 * V_57 = V_56 -> V_57 ;
struct V_16 * V_17 = V_56 -> V_58 ;
struct V_59 * V_60 ;
struct V_2 * V_35 ;
int V_61 = 0 ;
V_60 = F_17 ( V_17 , F_18 ( V_57 ) . V_62 , V_56 -> V_63 ,
V_64 , sizeof( * V_35 ) , V_56 -> V_65 ) ;
if ( ! V_60 ) {
V_61 = - V_28 ;
goto V_47;
}
V_35 = F_19 ( V_60 ) ;
V_61 = F_12 ( V_6 , V_35 , V_17 ) ;
if ( V_61 ) {
F_20 ( V_17 , V_60 ) ;
goto V_47;
}
F_21 ( V_17 , V_60 ) ;
V_47:
return V_61 ;
}
static int F_22 ( struct V_16 * V_57 , struct V_59 * V_66 ,
struct V_67 * * V_68 )
{
struct V_2 * V_3 = F_19 ( V_66 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_55 V_56 ;
int V_61 ;
if ( ! F_23 ( V_3 -> V_15 ) || ! F_23 ( V_3 -> V_12 ) )
return - V_69 ;
V_6 = F_1 ( V_3 , 0 ) ;
if ( ! V_6 )
return - V_70 ;
V_61 = - V_71 ;
V_17 = F_24 ( V_72 , V_73 ) ;
if ( ! V_17 )
goto V_74;
V_56 . V_57 = V_57 ;
V_56 . V_58 = V_17 ;
V_56 . V_63 = V_66 -> V_63 ;
V_56 . V_65 = 0 ;
V_61 = F_16 ( V_6 , & V_56 ) ;
V_74:
F_25 ( V_6 ) ;
if ( V_61 )
return V_61 ;
return F_26 ( V_75 , V_17 , F_18 ( V_57 ) . V_62 ) ;
}
static int F_27 ( struct V_16 * V_17 , struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_55 V_56 ;
int V_61 ;
if ( V_77 -> args [ 0 ] )
goto V_47;
V_77 -> args [ 0 ] = 1 ;
V_56 . V_57 = V_77 -> V_17 ;
V_56 . V_58 = V_17 ;
V_56 . V_63 = V_77 -> V_60 -> V_63 ;
V_56 . V_65 = V_78 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_61 = F_16 ( V_6 , & V_56 ) ;
if ( V_61 )
goto V_79;
}
V_47:
return V_17 -> V_80 ;
V_79:
return V_61 ;
}
static int F_28 ( struct V_76 * V_77 )
{
return 0 ;
}
static int F_29 ( struct V_16 * V_17 , struct V_59 * V_60 ,
struct V_67 * * V_68 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_19 ( V_60 ) ;
struct V_67 * V_81 = V_68 [ V_41 ] ;
F_30 ( V_82 ) ;
if ( ! F_31 ( V_17 , V_83 ) )
return - V_84 ;
if ( ! F_23 ( V_3 -> V_15 ) || ! F_23 ( V_3 -> V_12 ) )
return - V_69 ;
if ( V_81 && ! strlen ( V_3 -> V_12 ) )
return - V_69 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_70 ;
F_32 ( & V_7 ) ;
F_33 ( V_6 , & V_82 , NULL ) ;
if ( V_81 )
V_6 -> V_42 = F_34 ( V_81 ) ;
F_35 ( & V_7 ) ;
F_25 ( V_6 ) ;
F_36 ( & V_82 ) ;
return 0 ;
}
static int F_37 ( struct V_16 * V_17 , struct V_59 * V_60 ,
struct V_67 * * V_68 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_19 ( V_60 ) ;
int V_61 ;
if ( ! F_31 ( V_17 , V_83 ) )
return - V_84 ;
if ( ! F_23 ( V_3 -> V_15 ) || ! F_23 ( V_3 -> V_12 ) )
return - V_69 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_70 ;
V_61 = - V_69 ;
if ( ! ( V_6 -> V_9 & V_85 ) )
goto V_74;
V_61 = - V_86 ;
if ( F_14 ( & V_6 -> V_40 ) > 2 )
goto V_74;
V_61 = F_38 ( (struct V_87 * ) V_6 ) ;
V_74:
F_25 ( V_6 ) ;
return V_61 ;
}
static int F_39 ( struct V_16 * V_17 , struct V_59 * V_60 ,
struct V_67 * * V_68 )
{
int V_4 = 0 ;
const char * V_88 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_19 ( V_60 ) ;
struct V_67 * V_81 = V_68 [ V_41 ] ;
if ( ! F_31 ( V_17 , V_83 ) )
return - V_84 ;
if ( ! F_23 ( V_3 -> V_15 ) || ! F_23 ( V_3 -> V_12 ) )
return - V_69 ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_81 && ! V_4 )
return - V_69 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 ) {
F_25 ( V_6 ) ;
return - V_89 ;
}
if ( strlen ( V_3 -> V_12 ) )
V_88 = V_3 -> V_12 ;
else
V_88 = V_3 -> V_15 ;
V_6 = F_40 ( V_88 , V_3 -> V_10 , V_3 -> V_11 ) ;
if ( F_41 ( V_6 ) )
return F_42 ( V_6 ) ;
F_32 ( & V_7 ) ;
if ( V_81 )
V_6 -> V_42 = F_34 ( V_81 ) ;
F_35 ( & V_7 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
static int F_43 ( struct V_16 * V_17 , struct V_59 * V_60 ,
struct V_67 * * V_68 )
{
if ( ! F_31 ( V_17 , V_83 ) )
return - V_84 ;
return F_44 () ;
}
static int F_45 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
struct V_67 * V_68 [ V_90 + 1 ] ;
const struct V_91 * V_92 ;
int type , V_61 ;
type = V_60 -> V_93 ;
if ( type > V_94 )
return - V_69 ;
type -= V_95 ;
V_92 = & V_96 [ type ] ;
if ( ( type == ( V_64 - V_95 ) &&
( V_60 -> V_65 & V_97 ) ) ) {
struct V_1 * V_6 ;
T_1 V_98 = 0 ;
if ( V_92 -> V_99 == NULL )
return - V_69 ;
F_2 ( & V_7 ) ;
F_3 (alg, &crypto_alg_list, cra_list)
V_98 += V_100 ;
{
struct V_101 V_102 = {
. V_99 = V_92 -> V_99 ,
. V_103 = V_92 -> V_103 ,
. V_104 = V_98 ,
} ;
V_61 = F_46 ( V_75 , V_17 , V_60 , & V_102 ) ;
}
F_6 ( & V_7 ) ;
return V_61 ;
}
V_61 = F_47 ( V_60 , V_105 [ type ] , V_68 , V_90 ,
V_106 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_92 -> V_107 == NULL )
return - V_69 ;
return V_92 -> V_107 ( V_17 , V_60 , V_68 ) ;
}
static void F_48 ( struct V_16 * V_17 )
{
F_49 ( & V_108 ) ;
F_50 ( V_17 , & F_45 ) ;
F_51 ( & V_108 ) ;
}
static int T_2 F_52 ( void )
{
struct V_109 V_110 = {
. V_111 = F_48 ,
} ;
V_75 = F_53 ( & V_112 , V_113 , & V_110 ) ;
if ( ! V_75 )
return - V_71 ;
return 0 ;
}
static void T_3 F_54 ( void )
{
F_55 ( V_75 ) ;
}
