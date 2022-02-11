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
static int F_12 ( struct V_16 * V_17 , struct V_1 * V_6 )
{
struct F_12 V_35 ;
strncpy ( V_35 . type , L_5 , sizeof( V_35 . type ) ) ;
if ( F_8 ( V_17 , V_36 ,
sizeof( struct F_12 ) , & V_35 ) )
goto V_27;
return 0 ;
V_27:
return - V_28 ;
}
static int F_13 ( struct V_1 * V_6 ,
struct V_2 * V_37 , struct V_16 * V_17 )
{
strncpy ( V_37 -> V_15 , V_6 -> V_14 , sizeof( V_37 -> V_15 ) ) ;
strncpy ( V_37 -> V_12 , V_6 -> V_13 ,
sizeof( V_37 -> V_12 ) ) ;
strncpy ( V_37 -> V_38 , F_14 ( V_6 -> V_39 ) ,
sizeof( V_37 -> V_38 ) ) ;
V_37 -> V_10 = 0 ;
V_37 -> V_11 = 0 ;
V_37 -> V_40 = V_6 -> V_9 ;
V_37 -> V_41 = F_15 ( & V_6 -> V_42 ) ;
if ( F_16 ( V_17 , V_43 , V_6 -> V_44 ) )
goto V_27;
if ( V_6 -> V_9 & V_45 ) {
struct V_46 V_47 ;
strncpy ( V_47 . type , L_6 , sizeof( V_47 . type ) ) ;
if ( F_8 ( V_17 , V_48 ,
sizeof( struct V_46 ) , & V_47 ) )
goto V_27;
goto V_49;
}
if ( V_6 -> V_50 && V_6 -> V_50 -> V_51 ) {
if ( V_6 -> V_50 -> V_51 ( V_17 , V_6 ) )
goto V_27;
goto V_49;
}
switch ( V_6 -> V_9 & ( V_52 | V_45 ) ) {
case V_53 :
if ( F_7 ( V_17 , V_6 ) )
goto V_27;
break;
case V_54 :
if ( F_9 ( V_17 , V_6 ) )
goto V_27;
break;
case V_55 :
if ( F_10 ( V_17 , V_6 ) )
goto V_27;
break;
case V_56 :
if ( F_11 ( V_17 , V_6 ) )
goto V_27;
break;
case V_57 :
if ( F_12 ( V_17 , V_6 ) )
goto V_27;
break;
}
V_49:
return 0 ;
V_27:
return - V_28 ;
}
static int F_17 ( struct V_1 * V_6 ,
struct V_58 * V_59 )
{
struct V_16 * V_60 = V_59 -> V_60 ;
struct V_16 * V_17 = V_59 -> V_61 ;
struct V_62 * V_63 ;
struct V_2 * V_37 ;
int V_64 = 0 ;
V_63 = F_18 ( V_17 , F_19 ( V_60 ) . V_65 , V_59 -> V_66 ,
V_67 , sizeof( * V_37 ) , V_59 -> V_68 ) ;
if ( ! V_63 ) {
V_64 = - V_28 ;
goto V_49;
}
V_37 = F_20 ( V_63 ) ;
V_64 = F_13 ( V_6 , V_37 , V_17 ) ;
if ( V_64 ) {
F_21 ( V_17 , V_63 ) ;
goto V_49;
}
F_22 ( V_17 , V_63 ) ;
V_49:
return V_64 ;
}
static int F_23 ( struct V_16 * V_60 , struct V_62 * V_69 ,
struct V_70 * * V_71 )
{
struct V_2 * V_3 = F_20 ( V_69 ) ;
struct V_1 * V_6 ;
struct V_16 * V_17 ;
struct V_58 V_59 ;
int V_64 ;
if ( ! F_24 ( V_3 -> V_15 ) || ! F_24 ( V_3 -> V_12 ) )
return - V_72 ;
V_6 = F_1 ( V_3 , 0 ) ;
if ( ! V_6 )
return - V_73 ;
V_64 = - V_74 ;
V_17 = F_25 ( V_75 , V_76 ) ;
if ( ! V_17 )
goto V_77;
V_59 . V_60 = V_60 ;
V_59 . V_61 = V_17 ;
V_59 . V_66 = V_69 -> V_66 ;
V_59 . V_68 = 0 ;
V_64 = F_17 ( V_6 , & V_59 ) ;
V_77:
F_26 ( V_6 ) ;
if ( V_64 )
return V_64 ;
return F_27 ( V_78 , V_17 , F_19 ( V_60 ) . V_65 ) ;
}
static int F_28 ( struct V_16 * V_17 , struct V_79 * V_80 )
{
struct V_1 * V_6 ;
struct V_58 V_59 ;
int V_64 ;
if ( V_80 -> args [ 0 ] )
goto V_49;
V_80 -> args [ 0 ] = 1 ;
V_59 . V_60 = V_80 -> V_17 ;
V_59 . V_61 = V_17 ;
V_59 . V_66 = V_80 -> V_63 -> V_66 ;
V_59 . V_68 = V_81 ;
F_3 (alg, &crypto_alg_list, cra_list) {
V_64 = F_17 ( V_6 , & V_59 ) ;
if ( V_64 )
goto V_82;
}
V_49:
return V_17 -> V_83 ;
V_82:
return V_64 ;
}
static int F_29 ( struct V_79 * V_80 )
{
return 0 ;
}
static int F_30 ( struct V_16 * V_17 , struct V_62 * V_63 ,
struct V_70 * * V_71 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_20 ( V_63 ) ;
struct V_70 * V_84 = V_71 [ V_43 ] ;
F_31 ( V_85 ) ;
if ( ! F_32 ( V_17 , V_86 ) )
return - V_87 ;
if ( ! F_24 ( V_3 -> V_15 ) || ! F_24 ( V_3 -> V_12 ) )
return - V_72 ;
if ( V_84 && ! strlen ( V_3 -> V_12 ) )
return - V_72 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_73 ;
F_33 ( & V_7 ) ;
F_34 ( V_6 , & V_85 , NULL ) ;
if ( V_84 )
V_6 -> V_44 = F_35 ( V_84 ) ;
F_36 ( & V_7 ) ;
F_26 ( V_6 ) ;
F_37 ( & V_85 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_62 * V_63 ,
struct V_70 * * V_71 )
{
struct V_1 * V_6 ;
struct V_2 * V_3 = F_20 ( V_63 ) ;
int V_64 ;
if ( ! F_32 ( V_17 , V_86 ) )
return - V_87 ;
if ( ! F_24 ( V_3 -> V_15 ) || ! F_24 ( V_3 -> V_12 ) )
return - V_72 ;
V_6 = F_1 ( V_3 , 1 ) ;
if ( ! V_6 )
return - V_73 ;
V_64 = - V_72 ;
if ( ! ( V_6 -> V_9 & V_88 ) )
goto V_77;
V_64 = - V_89 ;
if ( F_15 ( & V_6 -> V_42 ) > 2 )
goto V_77;
V_64 = F_39 ( (struct V_90 * ) V_6 ) ;
V_77:
F_26 ( V_6 ) ;
return V_64 ;
}
static int F_40 ( struct V_16 * V_17 , struct V_62 * V_63 ,
struct V_70 * * V_71 )
{
int V_4 = 0 ;
const char * V_91 ;
struct V_1 * V_6 ;
struct V_2 * V_3 = F_20 ( V_63 ) ;
struct V_70 * V_84 = V_71 [ V_43 ] ;
if ( ! F_32 ( V_17 , V_86 ) )
return - V_87 ;
if ( ! F_24 ( V_3 -> V_15 ) || ! F_24 ( V_3 -> V_12 ) )
return - V_72 ;
if ( strlen ( V_3 -> V_12 ) )
V_4 = 1 ;
if ( V_84 && ! V_4 )
return - V_72 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 ) {
F_26 ( V_6 ) ;
return - V_92 ;
}
if ( strlen ( V_3 -> V_12 ) )
V_91 = V_3 -> V_12 ;
else
V_91 = V_3 -> V_15 ;
V_6 = F_41 ( V_91 , V_3 -> V_10 , V_3 -> V_11 ) ;
if ( F_42 ( V_6 ) )
return F_43 ( V_6 ) ;
F_33 ( & V_7 ) ;
if ( V_84 )
V_6 -> V_44 = F_35 ( V_84 ) ;
F_36 ( & V_7 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int F_44 ( struct V_16 * V_17 , struct V_62 * V_63 ,
struct V_70 * * V_71 )
{
if ( ! F_32 ( V_17 , V_86 ) )
return - V_87 ;
return F_45 () ;
}
static int F_46 ( struct V_16 * V_17 , struct V_62 * V_63 )
{
struct V_70 * V_71 [ V_93 + 1 ] ;
const struct V_94 * V_95 ;
int type , V_64 ;
type = V_63 -> V_96 ;
if ( type > V_97 )
return - V_72 ;
type -= V_98 ;
V_95 = & V_99 [ type ] ;
if ( ( type == ( V_67 - V_98 ) &&
( V_63 -> V_68 & V_100 ) ) ) {
struct V_1 * V_6 ;
T_1 V_101 = 0 ;
if ( V_95 -> V_102 == NULL )
return - V_72 ;
F_2 ( & V_7 ) ;
F_3 (alg, &crypto_alg_list, cra_list)
V_101 += V_103 ;
{
struct V_104 V_105 = {
. V_102 = V_95 -> V_102 ,
. V_106 = V_95 -> V_106 ,
. V_107 = V_101 ,
} ;
V_64 = F_47 ( V_78 , V_17 , V_63 , & V_105 ) ;
}
F_6 ( & V_7 ) ;
return V_64 ;
}
V_64 = F_48 ( V_63 , V_108 [ type ] , V_71 , V_93 ,
V_109 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_95 -> V_110 == NULL )
return - V_72 ;
return V_95 -> V_110 ( V_17 , V_63 , V_71 ) ;
}
static void F_49 ( struct V_16 * V_17 )
{
F_50 ( & V_111 ) ;
F_51 ( V_17 , & F_46 ) ;
F_52 ( & V_111 ) ;
}
static int T_2 F_53 ( void )
{
struct V_112 V_113 = {
. V_114 = F_49 ,
} ;
V_78 = F_54 ( & V_115 , V_116 , & V_113 ) ;
if ( ! V_78 )
return - V_74 ;
return 0 ;
}
static void T_3 F_55 ( void )
{
F_56 ( V_78 ) ;
}
