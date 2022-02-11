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
static void F_21 ( struct V_34 * V_35 ,
int V_3 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
if ( V_3 )
goto V_32;
F_24 ( V_40 , V_38 -> V_43 , V_40 -> V_44 ,
V_38 -> V_45 ) ;
F_25 ( V_40 , F_26 ( V_2 ) &
V_46 ,
V_38 -> V_47 , V_2 ) ;
V_3 = F_27 ( V_40 ) ;
if ( V_3 )
goto V_32;
F_28 ( V_40 -> V_44 , V_38 -> V_43 ,
V_38 -> V_45 ,
F_29 ( V_22 ) , 1 ) ;
V_32:
F_1 ( V_2 , V_3 ) ;
}
static void F_30 ( struct V_34 * V_35 , int V_3 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
if ( V_3 )
goto V_32;
F_28 ( V_40 -> V_44 , V_38 -> V_43 ,
V_38 -> V_45 ,
F_29 ( V_22 ) , 1 ) ;
V_32:
F_2 ( V_2 , V_3 ) ;
}
static void F_31 ( struct V_34 * V_35 ,
int V_3 )
{
T_1 * V_48 ;
unsigned int V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
unsigned int V_45 = V_2 -> V_45 ;
if ( V_3 )
goto V_32;
F_24 ( V_40 , V_38 -> V_43 , V_40 -> V_44 ,
V_38 -> V_45 ) ;
F_25 ( V_40 , F_26 ( V_2 ) &
V_46 ,
V_38 -> V_47 , V_2 ) ;
V_3 = F_27 ( V_40 ) ;
if ( V_3 )
goto V_32;
V_49 = F_29 ( V_22 ) ;
V_45 -= V_49 ;
V_48 = V_40 -> V_44 + V_49 ;
F_28 ( V_48 , V_38 -> V_43 , V_38 -> V_45 ,
V_49 , 0 ) ;
V_3 = F_32 ( V_48 , V_40 -> V_44 , V_49 ) ? - V_52 : 0 ;
if ( V_3 )
goto V_32;
V_51 = F_23 ( V_2 ) ;
F_33 ( V_51 , V_24 -> V_28 ) ;
F_34 ( V_51 , F_26 ( V_2 ) ,
V_2 -> V_53 . V_47 , V_2 -> V_53 . V_36 ) ;
F_35 ( V_51 , V_2 -> V_54 , V_2 -> V_55 ,
V_45 , V_2 -> V_56 ) ;
V_3 = F_36 ( V_51 ) ;
V_32:
F_1 ( V_2 , V_3 ) ;
}
static void F_37 ( struct V_34 * V_35 ,
int V_3 )
{
T_1 * V_48 ;
unsigned int V_49 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
unsigned int V_45 = V_2 -> V_45 ;
if ( V_3 )
goto V_32;
V_49 = F_29 ( V_22 ) ;
V_45 -= V_49 ;
V_48 = V_40 -> V_44 + V_49 ;
F_28 ( V_48 , V_38 -> V_43 , V_38 -> V_45 ,
V_49 , 0 ) ;
V_3 = F_32 ( V_48 , V_40 -> V_44 , V_49 ) ? - V_52 : 0 ;
if ( V_3 )
goto V_32;
V_51 = F_23 ( V_2 ) ;
F_33 ( V_51 , V_24 -> V_28 ) ;
F_34 ( V_51 , F_26 ( V_2 ) ,
V_2 -> V_53 . V_47 , V_2 -> V_53 . V_36 ) ;
F_35 ( V_51 , V_2 -> V_54 , V_2 -> V_55 ,
V_45 , V_2 -> V_56 ) ;
V_3 = F_36 ( V_51 ) ;
V_32:
F_1 ( V_2 , V_3 ) ;
}
static T_1 * F_38 ( struct V_1 * V_2 , unsigned int V_57 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
T_1 * V_58 = V_38 -> V_41 ;
int V_3 ;
V_58 = ( T_1 * ) F_39 ( ( unsigned long ) V_58 + F_40 ( V_26 ) ,
F_40 ( V_26 ) + 1 ) ;
F_41 ( V_40 , V_26 ) ;
V_3 = F_42 ( V_40 ) ;
if ( V_3 )
return F_43 ( V_3 ) ;
F_24 ( V_40 , V_2 -> V_59 , V_58 , V_2 -> V_60 ) ;
F_25 ( V_40 , F_26 ( V_2 ) & V_57 ,
V_38 -> V_61 , V_2 ) ;
V_3 = F_44 ( V_40 ) ;
if ( V_3 )
return F_43 ( V_3 ) ;
F_24 ( V_40 , V_38 -> V_43 , V_58 ,
V_38 -> V_45 ) ;
F_25 ( V_40 , F_26 ( V_2 ) & V_57 ,
V_38 -> V_47 , V_2 ) ;
V_3 = F_27 ( V_40 ) ;
if ( V_3 )
return F_43 ( V_3 ) ;
return V_58 ;
}
static T_1 * F_45 ( struct V_1 * V_2 , unsigned int V_57 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_26 ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_39 * V_40 = ( void * ) ( V_38 -> V_41 + V_24 -> V_42 ) ;
T_1 * V_58 = V_38 -> V_41 ;
int V_3 ;
V_58 = ( T_1 * ) F_39 ( ( unsigned long ) V_58 + F_40 ( V_26 ) ,
F_40 ( V_26 ) + 1 ) ;
F_41 ( V_40 , V_26 ) ;
F_24 ( V_40 , V_38 -> V_43 , V_58 ,
V_38 -> V_45 ) ;
F_25 ( V_40 , F_26 ( V_2 ) & V_57 ,
V_38 -> V_47 , V_2 ) ;
V_3 = F_46 ( V_40 ) ;
if ( V_3 )
return F_43 ( V_3 ) ;
return V_58 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 * V_56 ,
unsigned int V_57 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_62 * V_55 = V_2 -> V_55 ;
struct V_62 * V_59 = V_2 -> V_59 ;
struct V_62 * V_63 = V_38 -> V_63 ;
struct V_62 * V_64 = V_38 -> V_64 ;
unsigned int V_65 = F_48 ( V_22 ) ;
unsigned int V_45 = V_2 -> V_45 ;
T_2 V_66 = F_38 ;
struct V_67 * V_68 ;
T_1 * V_69 ;
T_1 * V_58 ;
V_68 = F_49 ( V_55 ) ;
V_69 = F_50 ( V_68 ) ? NULL : F_51 ( V_68 ) + V_55 -> V_70 ;
if ( V_65 ) {
F_52 ( V_63 , 2 ) ;
F_53 ( V_63 , V_56 , V_65 ) ;
F_54 ( V_63 , V_55 , V_69 == V_56 + V_65 , 2 ) ;
V_55 = V_63 ;
V_45 += V_65 ;
}
if ( V_2 -> V_60 && F_55 ( V_59 ) ) {
V_66 = F_45 ;
F_52 ( V_64 , 2 ) ;
F_56 ( V_64 , F_49 ( V_59 ) , V_59 -> V_71 , V_59 -> V_70 ) ;
F_54 ( V_64 , V_55 , 0 , 2 ) ;
V_55 = V_64 ;
V_45 += V_2 -> V_60 ;
}
V_38 -> V_45 = V_45 ;
V_38 -> V_43 = V_55 ;
V_38 -> V_47 = F_30 ;
V_38 -> V_61 = F_21 ;
V_58 = V_66 ( V_2 , V_57 ) ;
if ( F_57 ( V_58 ) )
return F_58 ( V_58 ) ;
F_28 ( V_58 , V_55 , V_45 ,
F_29 ( V_22 ) , 1 ) ;
return 0 ;
}
static void F_59 ( struct V_34 * V_2 ,
int V_3 )
{
struct V_1 * V_35 = V_2 -> V_36 ;
if ( ! V_3 ) {
struct V_21 * V_22 = F_22 ( V_35 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_35 ) ;
struct V_50 * V_51 = ( void * ) ( V_38 -> V_41
+ V_24 -> V_42 ) ;
T_1 * V_56 = ( T_1 * ) V_51 - F_60 ( V_24 -> V_28 ) ;
V_3 = F_47 ( V_35 , V_56 , 0 ) ;
}
F_1 ( V_35 , V_3 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_27 * V_28 = V_24 -> V_28 ;
struct V_62 * V_55 = V_2 -> V_55 ;
unsigned int V_45 = V_2 -> V_45 ;
struct V_50 * V_51 = ( void * ) ( V_38 -> V_41
+ V_24 -> V_42 ) ;
T_1 * V_56 = ( T_1 * ) V_51 - F_60 ( V_28 ) ;
int V_3 ;
F_33 ( V_51 , V_28 ) ;
F_34 ( V_51 , F_26 ( V_2 ) ,
F_59 , V_2 ) ;
F_35 ( V_51 , V_2 -> V_54 , V_55 , V_45 , V_2 -> V_56 ) ;
memcpy ( V_56 , V_2 -> V_56 , F_48 ( V_22 ) ) ;
V_3 = F_62 ( V_51 ) ;
if ( V_3 )
return V_3 ;
return F_47 ( V_2 , V_56 , V_46 ) ;
}
static void F_63 ( struct V_34 * V_2 ,
int V_3 )
{
struct V_1 * V_35 = V_2 -> V_36 ;
if ( ! V_3 ) {
struct V_72 * V_73 = F_23 ( V_35 ) ;
V_3 = F_47 ( V_35 , V_73 -> V_74 , 0 ) ;
}
F_1 ( V_35 , V_3 ) ;
}
static int F_64 ( struct V_75 * V_2 )
{
struct V_21 * V_22 = F_65 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_1 * V_35 = & V_2 -> V_35 ;
struct V_72 * V_73 = F_23 ( V_35 ) ;
T_1 * V_56 = V_2 -> V_74 ;
int V_3 ;
F_66 ( V_73 , V_24 -> V_28 ) ;
F_67 ( V_73 , F_26 ( V_35 ) ,
F_63 , V_35 ) ;
F_68 ( V_73 , V_35 -> V_54 , V_35 -> V_55 , V_35 -> V_45 ,
V_35 -> V_56 ) ;
F_69 ( V_73 , V_56 , V_2 -> V_76 ) ;
V_3 = F_70 ( V_73 ) ;
if ( V_3 )
return V_3 ;
return F_47 ( V_35 , V_56 , V_46 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
T_2 V_66 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
T_1 * V_77 ;
T_1 * V_48 ;
unsigned int V_49 ;
V_38 -> V_47 = F_37 ;
V_38 -> V_61 = F_31 ;
V_77 = V_66 ( V_2 , V_46 ) ;
if ( F_57 ( V_77 ) )
return F_58 ( V_77 ) ;
V_49 = F_29 ( V_22 ) ;
V_48 = V_77 + V_49 ;
F_28 ( V_48 , V_38 -> V_43 , V_38 -> V_45 ,
V_49 , 0 ) ;
return F_32 ( V_48 , V_77 , V_49 ) ? - V_52 : 0 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 * V_56 ,
unsigned int V_45 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
struct V_62 * V_54 = V_2 -> V_54 ;
struct V_62 * V_59 = V_2 -> V_59 ;
struct V_62 * V_63 = V_38 -> V_63 ;
struct V_62 * V_64 = V_38 -> V_64 ;
unsigned int V_65 = F_48 ( V_22 ) ;
T_2 V_66 = F_38 ;
struct V_67 * V_78 ;
T_1 * V_79 ;
V_78 = F_49 ( V_54 ) ;
V_79 = F_50 ( V_78 ) ? NULL : F_51 ( V_78 ) + V_54 -> V_70 ;
if ( V_65 ) {
F_52 ( V_63 , 2 ) ;
F_53 ( V_63 , V_56 , V_65 ) ;
F_54 ( V_63 , V_54 , V_79 == V_56 + V_65 , 2 ) ;
V_54 = V_63 ;
V_45 += V_65 ;
}
if ( V_2 -> V_60 && F_55 ( V_59 ) ) {
V_66 = F_45 ;
F_52 ( V_64 , 2 ) ;
F_56 ( V_64 , F_49 ( V_59 ) , V_59 -> V_71 , V_59 -> V_70 ) ;
F_54 ( V_64 , V_54 , 0 , 2 ) ;
V_54 = V_64 ;
V_45 += V_2 -> V_60 ;
}
V_38 -> V_45 = V_45 ;
V_38 -> V_43 = V_54 ;
return F_71 ( V_2 , V_66 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_22 ( V_2 ) ;
struct V_23 * V_24 = F_10 ( V_22 ) ;
struct V_50 * V_51 = F_23 ( V_2 ) ;
unsigned int V_45 = V_2 -> V_45 ;
unsigned int V_49 = F_29 ( V_22 ) ;
T_1 * V_56 = V_2 -> V_56 ;
int V_3 ;
if ( V_45 < V_49 )
return - V_13 ;
V_45 -= V_49 ;
V_3 = F_72 ( V_2 , V_56 , V_45 ) ;
if ( V_3 )
return V_3 ;
F_33 ( V_51 , V_24 -> V_28 ) ;
F_34 ( V_51 , F_26 ( V_2 ) ,
V_2 -> V_53 . V_47 , V_2 -> V_53 . V_36 ) ;
F_35 ( V_51 , V_2 -> V_54 , V_2 -> V_55 , V_45 , V_56 ) ;
return F_36 ( V_51 ) ;
}
static int F_74 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_75 ( V_81 ) ;
struct V_84 * V_85 = F_76 ( V_83 ) ;
struct V_23 * V_24 = F_77 ( V_81 ) ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_3 ;
V_26 = F_78 ( & V_85 -> V_26 ) ;
if ( F_57 ( V_26 ) )
return F_58 ( V_26 ) ;
V_28 = F_79 ( & V_85 -> V_28 ) ;
V_3 = F_58 ( V_28 ) ;
if ( F_57 ( V_28 ) )
goto V_86;
V_24 -> V_26 = V_26 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_42 = F_39 ( 2 * F_80 ( V_26 ) +
F_40 ( V_26 ) ,
F_40 ( V_26 ) + 1 ) +
F_60 ( V_28 ) ;
V_81 -> V_87 . V_88 = sizeof( struct V_37 ) +
V_24 -> V_42 +
F_81 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_givcrypt_request) +
crypto_ablkcipher_reqsize(enc)) ;
return 0 ;
V_86:
F_82 ( V_26 ) ;
return V_3 ;
}
static void F_83 ( struct V_80 * V_81 )
{
struct V_23 * V_24 = F_77 ( V_81 ) ;
F_82 ( V_24 -> V_26 ) ;
F_84 ( V_24 -> V_28 ) ;
}
static struct V_82 * F_85 ( struct V_9 * * V_89 )
{
struct V_90 * V_91 ;
struct V_82 * V_83 ;
struct V_92 * V_26 ;
struct V_93 * V_94 ;
struct V_93 * V_28 ;
struct V_84 * V_24 ;
const char * V_95 ;
int V_3 ;
V_91 = F_86 ( V_89 ) ;
if ( F_57 ( V_91 ) )
return F_87 ( V_91 ) ;
if ( ( V_91 -> type ^ V_96 ) & V_91 -> V_97 )
return F_43 ( - V_13 ) ;
V_26 = F_88 ( V_89 [ 1 ] , V_98 ,
V_99 ) ;
if ( F_57 ( V_26 ) )
return F_87 ( V_26 ) ;
V_94 = & V_26 -> V_53 ;
V_95 = F_89 ( V_89 [ 2 ] ) ;
V_3 = F_58 ( V_95 ) ;
if ( F_57 ( V_95 ) )
goto V_100;
V_83 = F_90 ( sizeof( * V_83 ) + sizeof( * V_24 ) , V_101 ) ;
V_3 = - V_102 ;
if ( ! V_83 )
goto V_100;
V_24 = F_76 ( V_83 ) ;
V_3 = F_91 ( & V_24 -> V_26 , V_26 , V_83 ) ;
if ( V_3 )
goto V_103;
F_92 ( & V_24 -> V_28 , V_83 ) ;
V_3 = F_93 ( & V_24 -> V_28 , V_95 , 0 ,
F_94 ( V_91 -> type ,
V_91 -> V_97 ) ) ;
if ( V_3 )
goto V_104;
V_28 = F_95 ( & V_24 -> V_28 ) ;
V_3 = - V_105 ;
if ( snprintf ( V_83 -> V_106 . V_107 , V_108 ,
L_1 , V_94 -> V_107 , V_28 -> V_107 ) >=
V_108 )
goto V_109;
if ( snprintf ( V_83 -> V_106 . V_110 , V_108 ,
L_1 , V_94 -> V_110 ,
V_28 -> V_110 ) >= V_108 )
goto V_109;
V_83 -> V_106 . V_111 = V_96 ;
V_83 -> V_106 . V_111 |= V_28 -> V_111 & V_112 ;
V_83 -> V_106 . V_113 = V_28 -> V_113 *
10 + V_94 -> V_113 ;
V_83 -> V_106 . V_114 = V_28 -> V_114 ;
V_83 -> V_106 . V_115 = V_94 -> V_115 | V_28 -> V_115 ;
V_83 -> V_106 . V_116 = & V_117 ;
V_83 -> V_106 . V_118 . V_65 = V_28 -> V_119 . V_65 ;
V_83 -> V_106 . V_118 . V_120 = V_26 -> V_121 ;
V_83 -> V_106 . V_122 = sizeof( struct V_23 ) ;
V_83 -> V_106 . V_123 = F_74 ;
V_83 -> V_106 . V_124 = F_83 ;
V_83 -> V_106 . V_118 . V_125 = F_9 ;
V_83 -> V_106 . V_118 . V_126 = F_61 ;
V_83 -> V_106 . V_118 . V_127 = F_73 ;
V_83 -> V_106 . V_118 . V_128 = F_64 ;
V_32:
F_96 ( V_94 ) ;
return V_83 ;
V_109:
F_97 ( & V_24 -> V_28 ) ;
V_104:
F_98 ( & V_24 -> V_26 ) ;
V_103:
F_99 ( V_83 ) ;
V_100:
V_83 = F_43 ( V_3 ) ;
goto V_32;
}
static void F_100 ( struct V_82 * V_83 )
{
struct V_84 * V_24 = F_76 ( V_83 ) ;
F_97 ( & V_24 -> V_28 ) ;
F_98 ( & V_24 -> V_26 ) ;
F_99 ( V_83 ) ;
}
static int T_3 F_101 ( void )
{
return F_102 ( & V_129 ) ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_129 ) ;
}
