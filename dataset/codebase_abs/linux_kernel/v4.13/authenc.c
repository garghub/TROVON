static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != - V_4 )
F_2 ( V_2 , V_3 ) ;
}
int F_3 ( struct V_5 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_7 ;
struct V_11 * V_12 ;
if ( ! F_4 ( V_10 , V_8 ) )
return - V_13 ;
if ( V_10 -> V_14 != V_15 )
return - V_13 ;
if ( F_5 ( V_10 ) < sizeof( * V_12 ) )
return - V_13 ;
V_12 = F_6 ( V_10 ) ;
V_6 -> V_16 = F_7 ( V_12 -> V_16 ) ;
V_7 += F_8 ( V_10 -> V_17 ) ;
V_8 -= F_8 ( V_10 -> V_17 ) ;
if ( V_8 < V_6 -> V_16 )
return - V_13 ;
V_6 -> V_18 = V_8 - V_6 -> V_16 ;
V_6 -> V_19 = V_7 ;
V_6 -> V_20 = V_7 + V_6 -> V_18 ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_5 V_6 ;
int V_3 = - V_13 ;
if ( F_3 ( & V_6 , V_7 , V_8 ) != 0 )
goto V_29;
F_11 ( V_26 , V_30 ) ;
F_12 ( V_26 , F_13 ( V_22 ) &
V_30 ) ;
V_3 = F_14 ( V_26 , V_6 . V_19 , V_6 . V_18 ) ;
F_15 ( V_22 , F_16 ( V_26 ) &
V_31 ) ;
if ( V_3 )
goto V_32;
F_17 ( V_28 , V_30 ) ;
F_18 ( V_28 , F_13 ( V_22 ) &
V_30 ) ;
V_3 = F_19 ( V_28 , V_6 . V_20 , V_6 . V_16 ) ;
F_15 ( V_22 , F_20 ( V_28 ) &
V_31 ) ;
V_32:
return V_3 ;
V_29:
F_15 ( V_22 , V_33 ) ;
goto V_32;
}
static void F_21 ( struct V_34 * V_35 , int V_3 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_22 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_41 * V_42 = F_25 ( V_2 ) ;
struct V_43 * V_44 = ( void * ) ( V_42 -> V_45 + V_40 -> V_46 ) ;
if ( V_3 )
goto V_32;
F_26 ( V_44 -> V_47 , V_2 -> V_48 ,
V_2 -> V_49 + V_2 -> V_50 ,
F_27 ( V_22 ) , 1 ) ;
V_32:
F_2 ( V_2 , V_3 ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_22 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = F_25 ( V_2 ) ;
struct V_43 * V_44 = ( void * ) ( V_42 -> V_45 + V_40 -> V_46 ) ;
T_1 * V_52 = V_42 -> V_45 ;
int V_3 ;
V_52 = ( T_1 * ) F_29 ( ( unsigned long ) V_52 + F_30 ( V_26 ) ,
F_30 ( V_26 ) + 1 ) ;
F_31 ( V_44 , V_26 ) ;
F_32 ( V_44 , V_2 -> V_48 , V_52 ,
V_2 -> V_49 + V_2 -> V_50 ) ;
F_33 ( V_44 , V_51 ,
F_21 , V_2 ) ;
V_3 = F_34 ( V_44 ) ;
if ( V_3 )
return V_3 ;
F_26 ( V_52 , V_2 -> V_48 , V_2 -> V_49 + V_2 -> V_50 ,
F_27 ( V_22 ) , 1 ) ;
return 0 ;
}
static void F_35 ( struct V_34 * V_2 ,
int V_3 )
{
struct V_1 * V_35 = V_2 -> V_36 ;
if ( V_3 )
goto V_32;
V_3 = F_28 ( V_35 , 0 ) ;
V_32:
F_1 ( V_35 , V_3 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
F_37 ( V_53 , V_24 -> null ) ;
F_38 ( V_53 , V_24 -> null ) ;
F_39 ( V_53 , F_40 ( V_2 ) ,
NULL , NULL ) ;
F_41 ( V_53 , V_2 -> V_54 , V_2 -> V_48 , V_2 -> V_49 ,
NULL ) ;
return F_42 ( V_53 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_22 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_41 * V_42 = F_25 ( V_2 ) ;
struct V_27 * V_28 = V_24 -> V_28 ;
unsigned int V_50 = V_2 -> V_50 ;
struct V_55 * V_53 = ( void * ) ( V_42 -> V_45 +
V_40 -> V_46 ) ;
struct V_56 * V_54 , * V_48 ;
int V_3 ;
V_54 = F_44 ( V_42 -> V_54 , V_2 -> V_54 , V_2 -> V_49 ) ;
V_48 = V_54 ;
if ( V_2 -> V_54 != V_2 -> V_48 ) {
V_3 = F_36 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_48 = F_44 ( V_42 -> V_48 , V_2 -> V_48 , V_2 -> V_49 ) ;
}
F_38 ( V_53 , V_28 ) ;
F_39 ( V_53 , F_40 ( V_2 ) ,
F_35 , V_2 ) ;
F_41 ( V_53 , V_54 , V_48 , V_50 , V_2 -> V_57 ) ;
V_3 = F_42 ( V_53 ) ;
if ( V_3 )
return V_3 ;
return F_28 ( V_2 , F_40 ( V_2 ) ) ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned int V_51 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_22 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_41 * V_42 = F_25 ( V_2 ) ;
struct V_43 * V_44 = ( void * ) ( V_42 -> V_45 + V_40 -> V_46 ) ;
struct V_55 * V_53 = ( void * ) ( V_42 -> V_45 +
V_40 -> V_46 ) ;
unsigned int V_58 = F_27 ( V_22 ) ;
T_1 * V_59 = V_44 -> V_47 + V_58 ;
struct V_56 * V_54 , * V_48 ;
F_26 ( V_59 , V_2 -> V_54 , V_44 -> V_60 , V_58 , 0 ) ;
if ( F_46 ( V_59 , V_44 -> V_47 , V_58 ) )
return - V_61 ;
V_54 = F_44 ( V_42 -> V_54 , V_2 -> V_54 , V_2 -> V_49 ) ;
V_48 = V_54 ;
if ( V_2 -> V_54 != V_2 -> V_48 )
V_48 = F_44 ( V_42 -> V_48 , V_2 -> V_48 , V_2 -> V_49 ) ;
F_38 ( V_53 , V_24 -> V_28 ) ;
F_39 ( V_53 , F_40 ( V_2 ) ,
V_2 -> V_62 . V_63 , V_2 -> V_62 . V_36 ) ;
F_41 ( V_53 , V_54 , V_48 ,
V_2 -> V_50 - V_58 , V_2 -> V_57 ) ;
return F_47 ( V_53 ) ;
}
static void F_48 ( struct V_34 * V_35 ,
int V_3 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
if ( V_3 )
goto V_32;
V_3 = F_45 ( V_2 , 0 ) ;
V_32:
F_1 ( V_2 , V_3 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
unsigned int V_58 = F_27 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_22 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_41 * V_42 = F_25 ( V_2 ) ;
struct V_43 * V_44 = ( void * ) ( V_42 -> V_45 + V_40 -> V_46 ) ;
T_1 * V_52 = V_42 -> V_45 ;
int V_3 ;
V_52 = ( T_1 * ) F_29 ( ( unsigned long ) V_52 + F_30 ( V_26 ) ,
F_30 ( V_26 ) + 1 ) ;
F_31 ( V_44 , V_26 ) ;
F_32 ( V_44 , V_2 -> V_54 , V_52 ,
V_2 -> V_49 + V_2 -> V_50 - V_58 ) ;
F_33 ( V_44 , F_40 ( V_2 ) ,
F_48 , V_2 ) ;
V_3 = F_34 ( V_44 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_2 , F_40 ( V_2 ) ) ;
}
static int F_50 ( struct V_21 * V_64 )
{
struct V_37 * V_38 = F_23 ( V_64 ) ;
struct V_39 * V_40 = F_24 ( V_38 ) ;
struct V_23 * V_24 = F_10 ( V_64 ) ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_27 * null ;
int V_3 ;
V_26 = F_51 ( & V_40 -> V_26 ) ;
if ( F_52 ( V_26 ) )
return F_53 ( V_26 ) ;
V_28 = F_54 ( & V_40 -> V_28 ) ;
V_3 = F_53 ( V_28 ) ;
if ( F_52 ( V_28 ) )
goto V_65;
null = F_55 () ;
V_3 = F_53 ( null ) ;
if ( F_52 ( null ) )
goto V_66;
V_24 -> V_26 = V_26 ;
V_24 -> V_28 = V_28 ;
V_24 -> null = null ;
F_56 (
V_64 ,
sizeof( struct V_41 ) +
V_40 -> V_46 +
F_57 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_request) +
crypto_skcipher_reqsize(enc)) ) ;
return 0 ;
V_66:
F_58 ( V_28 ) ;
V_65:
F_59 ( V_26 ) ;
return V_3 ;
}
static void F_60 ( struct V_21 * V_64 )
{
struct V_23 * V_24 = F_10 ( V_64 ) ;
F_59 ( V_24 -> V_26 ) ;
F_58 ( V_24 -> V_28 ) ;
F_61 () ;
}
static void F_62 ( struct V_37 * V_38 )
{
struct V_39 * V_24 = F_24 ( V_38 ) ;
F_63 ( & V_24 -> V_28 ) ;
F_64 ( & V_24 -> V_26 ) ;
F_65 ( V_38 ) ;
}
static int F_66 ( struct V_67 * V_68 ,
struct V_9 * * V_69 )
{
struct V_70 * V_71 ;
struct V_37 * V_38 ;
struct V_72 * V_26 ;
struct V_73 * V_74 ;
struct V_75 * V_28 ;
struct V_39 * V_24 ;
const char * V_76 ;
int V_3 ;
V_71 = F_67 ( V_69 ) ;
if ( F_52 ( V_71 ) )
return F_53 ( V_71 ) ;
if ( ( V_71 -> type ^ V_77 ) & V_71 -> V_78 )
return - V_13 ;
V_26 = F_68 ( V_69 [ 1 ] , V_79 ,
V_80 |
F_69 ( V_71 -> type , V_71 -> V_78 ) ) ;
if ( F_52 ( V_26 ) )
return F_53 ( V_26 ) ;
V_74 = & V_26 -> V_62 ;
V_76 = F_70 ( V_69 [ 2 ] ) ;
V_3 = F_53 ( V_76 ) ;
if ( F_52 ( V_76 ) )
goto V_81;
V_38 = F_71 ( sizeof( * V_38 ) + sizeof( * V_24 ) , V_82 ) ;
V_3 = - V_83 ;
if ( ! V_38 )
goto V_81;
V_24 = F_24 ( V_38 ) ;
V_3 = F_72 ( & V_24 -> V_26 , V_26 ,
F_73 ( V_38 ) ) ;
if ( V_3 )
goto V_84;
F_74 ( & V_24 -> V_28 , F_73 ( V_38 ) ) ;
V_3 = F_75 ( & V_24 -> V_28 , V_76 , 0 ,
F_69 ( V_71 -> type ,
V_71 -> V_78 ) ) ;
if ( V_3 )
goto V_85;
V_28 = F_76 ( & V_24 -> V_28 ) ;
V_24 -> V_46 = F_29 ( 2 * V_26 -> V_86 + V_74 -> V_87 ,
V_74 -> V_87 + 1 ) ;
V_3 = - V_88 ;
if ( snprintf ( V_38 -> V_89 . V_62 . V_90 , V_91 ,
L_1 , V_74 -> V_90 ,
V_28 -> V_62 . V_90 ) >=
V_91 )
goto V_92;
if ( snprintf ( V_38 -> V_89 . V_62 . V_93 , V_91 ,
L_1 , V_74 -> V_93 ,
V_28 -> V_62 . V_93 ) >= V_91 )
goto V_92;
V_38 -> V_89 . V_62 . V_94 = ( V_74 -> V_94 |
V_28 -> V_62 . V_94 ) & V_95 ;
V_38 -> V_89 . V_62 . V_96 = V_28 -> V_62 . V_96 * 10 +
V_74 -> V_96 ;
V_38 -> V_89 . V_62 . V_97 = V_28 -> V_62 . V_97 ;
V_38 -> V_89 . V_62 . V_87 = V_74 -> V_87 |
V_28 -> V_62 . V_87 ;
V_38 -> V_89 . V_62 . V_98 = sizeof( struct V_23 ) ;
V_38 -> V_89 . V_99 = F_77 ( V_28 ) ;
V_38 -> V_89 . V_100 = F_78 ( V_28 ) ;
V_38 -> V_89 . V_101 = V_26 -> V_86 ;
V_38 -> V_89 . V_102 = F_50 ;
V_38 -> V_89 . exit = F_60 ;
V_38 -> V_89 . V_103 = F_9 ;
V_38 -> V_89 . V_104 = F_43 ;
V_38 -> V_89 . V_105 = F_49 ;
V_38 -> free = F_62 ;
V_3 = F_79 ( V_68 , V_38 ) ;
if ( V_3 )
goto V_92;
V_32:
F_80 ( V_74 ) ;
return V_3 ;
V_92:
F_63 ( & V_24 -> V_28 ) ;
V_85:
F_64 ( & V_24 -> V_26 ) ;
V_84:
F_65 ( V_38 ) ;
V_81:
goto V_32;
}
static int T_2 F_81 ( void )
{
return F_82 ( & V_106 ) ;
}
static void T_3 F_83 ( void )
{
F_84 ( & V_106 ) ;
}
