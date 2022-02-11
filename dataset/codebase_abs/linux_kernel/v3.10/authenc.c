static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != - V_4 )
F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_17 * V_18 = ( void * ) V_7 ;
struct V_19 * V_20 ;
int V_3 = - V_21 ;
if ( ! F_5 ( V_18 , V_8 ) )
goto V_22;
if ( V_18 -> V_23 != V_24 )
goto V_22;
if ( F_6 ( V_18 ) < sizeof( * V_20 ) )
goto V_22;
V_20 = F_7 ( V_18 ) ;
V_10 = F_8 ( V_20 -> V_10 ) ;
V_7 += F_9 ( V_18 -> V_25 ) ;
V_8 -= F_9 ( V_18 -> V_25 ) ;
if ( V_8 < V_10 )
goto V_22;
V_9 = V_8 - V_10 ;
F_10 ( V_14 , V_26 ) ;
F_11 ( V_14 , F_12 ( V_6 ) &
V_26 ) ;
V_3 = F_13 ( V_14 , V_7 , V_9 ) ;
F_14 ( V_6 , F_15 ( V_14 ) &
V_27 ) ;
if ( V_3 )
goto V_28;
F_16 ( V_16 , V_26 ) ;
F_17 ( V_16 , F_12 ( V_6 ) &
V_26 ) ;
V_3 = F_18 ( V_16 , V_7 + V_9 , V_10 ) ;
F_14 ( V_6 , F_19 ( V_16 ) &
V_27 ) ;
V_28:
return V_3 ;
V_22:
F_14 ( V_6 , V_29 ) ;
goto V_28;
}
static void F_20 ( struct V_30 * V_31 ,
int V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_39 , V_36 -> V_40 ,
V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
goto V_28;
F_27 ( V_36 -> V_40 , V_34 -> V_39 ,
V_34 -> V_41 ,
F_28 ( V_6 ) , 1 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_29 ( struct V_30 * V_31 , int V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
if ( V_3 )
goto V_28;
F_27 ( V_36 -> V_40 , V_34 -> V_39 ,
V_34 -> V_41 ,
F_28 ( V_6 ) , 1 ) ;
V_28:
F_2 ( V_2 , V_3 ) ;
}
static void F_30 ( struct V_30 * V_31 ,
int V_3 )
{
T_1 * V_44 ;
unsigned int V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
unsigned int V_41 = V_2 -> V_41 ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_39 , V_36 -> V_40 ,
V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
goto V_28;
V_45 = F_28 ( V_6 ) ;
V_41 -= V_45 ;
V_44 = V_36 -> V_40 + V_45 ;
F_27 ( V_44 , V_34 -> V_39 , V_34 -> V_41 ,
V_45 , 0 ) ;
V_3 = memcmp ( V_44 , V_36 -> V_40 , V_45 ) ? - V_48 : 0 ;
if ( V_3 )
goto V_28;
V_47 = F_22 ( V_2 ) ;
F_31 ( V_47 , V_12 -> V_16 ) ;
F_32 ( V_47 , F_25 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_32 ) ;
F_33 ( V_47 , V_2 -> V_50 , V_2 -> V_51 ,
V_41 , V_2 -> V_52 ) ;
V_3 = F_34 ( V_47 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_35 ( struct V_30 * V_31 ,
int V_3 )
{
T_1 * V_44 ;
unsigned int V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
unsigned int V_41 = V_2 -> V_41 ;
if ( V_3 )
goto V_28;
V_45 = F_28 ( V_6 ) ;
V_41 -= V_45 ;
V_44 = V_36 -> V_40 + V_45 ;
F_27 ( V_44 , V_34 -> V_39 , V_34 -> V_41 ,
V_45 , 0 ) ;
V_3 = memcmp ( V_44 , V_36 -> V_40 , V_45 ) ? - V_48 : 0 ;
if ( V_3 )
goto V_28;
V_47 = F_22 ( V_2 ) ;
F_31 ( V_47 , V_12 -> V_16 ) ;
F_32 ( V_47 , F_25 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_32 ) ;
F_33 ( V_47 , V_2 -> V_50 , V_2 -> V_51 ,
V_41 , V_2 -> V_52 ) ;
V_3 = F_34 ( V_47 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static T_1 * F_36 ( struct V_1 * V_2 , unsigned int V_53 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
T_1 * V_54 = V_34 -> V_37 ;
int V_3 ;
V_54 = ( T_1 * ) F_37 ( ( unsigned long ) V_54 + F_38 ( V_14 ) ,
F_38 ( V_14 ) + 1 ) ;
F_39 ( V_36 , V_14 ) ;
V_3 = F_40 ( V_36 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
F_23 ( V_36 , V_2 -> V_55 , V_54 , V_2 -> V_56 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_53 ,
V_34 -> V_57 , V_2 ) ;
V_3 = F_42 ( V_36 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
F_23 ( V_36 , V_34 -> V_39 , V_54 ,
V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_53 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
return V_54 ;
}
static T_1 * F_43 ( struct V_1 * V_2 , unsigned int V_53 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
T_1 * V_54 = V_34 -> V_37 ;
int V_3 ;
V_54 = ( T_1 * ) F_37 ( ( unsigned long ) V_54 + F_38 ( V_14 ) ,
F_38 ( V_14 ) + 1 ) ;
F_39 ( V_36 , V_14 ) ;
F_23 ( V_36 , V_34 -> V_39 , V_54 ,
V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_53 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_44 ( V_36 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
return V_54 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_52 ,
unsigned int V_53 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_58 * V_51 = V_2 -> V_51 ;
struct V_58 * V_55 = V_2 -> V_55 ;
struct V_58 * V_59 = V_34 -> V_59 ;
struct V_58 * V_60 = V_34 -> V_60 ;
unsigned int V_61 = F_46 ( V_6 ) ;
unsigned int V_41 = V_2 -> V_41 ;
T_2 V_62 = F_36 ;
struct V_63 * V_64 ;
T_1 * V_65 ;
T_1 * V_54 ;
V_64 = F_47 ( V_51 ) ;
V_65 = F_48 ( V_64 ) ? NULL : F_49 ( V_64 ) + V_51 -> V_66 ;
if ( V_61 ) {
F_50 ( V_59 , 2 ) ;
F_51 ( V_59 , V_52 , V_61 ) ;
F_52 ( V_59 , V_51 , V_65 == V_52 + V_61 , 2 ) ;
V_51 = V_59 ;
V_41 += V_61 ;
}
if ( V_2 -> V_56 && F_53 ( V_55 ) ) {
V_62 = F_43 ;
F_50 ( V_60 , 2 ) ;
F_54 ( V_60 , F_47 ( V_55 ) , V_55 -> V_67 , V_55 -> V_66 ) ;
F_52 ( V_60 , V_51 , 0 , 2 ) ;
V_51 = V_60 ;
V_41 += V_2 -> V_56 ;
}
V_34 -> V_41 = V_41 ;
V_34 -> V_39 = V_51 ;
V_34 -> V_43 = F_29 ;
V_34 -> V_57 = F_20 ;
V_54 = V_62 ( V_2 , V_53 ) ;
if ( F_55 ( V_54 ) )
return F_56 ( V_54 ) ;
F_27 ( V_54 , V_51 , V_41 ,
F_28 ( V_6 ) , 1 ) ;
return 0 ;
}
static void F_57 ( struct V_30 * V_2 ,
int V_3 )
{
struct V_1 * V_31 = V_2 -> V_32 ;
if ( ! V_3 ) {
struct V_5 * V_6 = F_21 ( V_31 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_46 * V_47 = F_22 ( V_31 ) ;
T_1 * V_52 = ( T_1 * ) ( V_47 + 1 ) +
F_58 ( V_12 -> V_16 ) ;
V_3 = F_45 ( V_31 , V_52 , 0 ) ;
}
F_1 ( V_31 , V_3 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_58 * V_51 = V_2 -> V_51 ;
unsigned int V_41 = V_2 -> V_41 ;
struct V_46 * V_47 = ( void * ) ( V_34 -> V_37
+ V_12 -> V_38 ) ;
T_1 * V_52 = ( T_1 * ) V_47 - F_60 ( V_16 ) ;
int V_3 ;
F_31 ( V_47 , V_16 ) ;
F_32 ( V_47 , F_25 ( V_2 ) ,
F_57 , V_2 ) ;
F_33 ( V_47 , V_2 -> V_50 , V_51 , V_41 , V_2 -> V_52 ) ;
memcpy ( V_52 , V_2 -> V_52 , F_46 ( V_6 ) ) ;
V_3 = F_61 ( V_47 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_2 , V_52 , V_42 ) ;
}
static void F_62 ( struct V_30 * V_2 ,
int V_3 )
{
struct V_1 * V_31 = V_2 -> V_32 ;
if ( ! V_3 ) {
struct V_68 * V_69 = F_22 ( V_31 ) ;
V_3 = F_45 ( V_31 , V_69 -> V_70 , 0 ) ;
}
F_1 ( V_31 , V_3 ) ;
}
static int F_63 ( struct V_71 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_1 * V_31 = & V_2 -> V_31 ;
struct V_68 * V_69 = F_22 ( V_31 ) ;
T_1 * V_52 = V_2 -> V_70 ;
int V_3 ;
F_65 ( V_69 , V_12 -> V_16 ) ;
F_66 ( V_69 , F_25 ( V_31 ) ,
F_62 , V_31 ) ;
F_67 ( V_69 , V_31 -> V_50 , V_31 -> V_51 , V_31 -> V_41 ,
V_31 -> V_52 ) ;
F_68 ( V_69 , V_52 , V_2 -> V_72 ) ;
V_3 = F_69 ( V_69 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_31 , V_52 , V_42 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_2 V_62 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
T_1 * V_73 ;
T_1 * V_44 ;
unsigned int V_45 ;
V_34 -> V_43 = F_35 ;
V_34 -> V_57 = F_30 ;
V_73 = V_62 ( V_2 , V_42 ) ;
if ( F_55 ( V_73 ) )
return F_56 ( V_73 ) ;
V_45 = F_28 ( V_6 ) ;
V_44 = V_73 + V_45 ;
F_27 ( V_44 , V_34 -> V_39 , V_34 -> V_41 ,
V_45 , 0 ) ;
return memcmp ( V_44 , V_73 , V_45 ) ? - V_48 : 0 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 * V_52 ,
unsigned int V_41 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_58 * V_50 = V_2 -> V_50 ;
struct V_58 * V_55 = V_2 -> V_55 ;
struct V_58 * V_59 = V_34 -> V_59 ;
struct V_58 * V_60 = V_34 -> V_60 ;
unsigned int V_61 = F_46 ( V_6 ) ;
T_2 V_62 = F_36 ;
struct V_63 * V_74 ;
T_1 * V_75 ;
V_74 = F_47 ( V_50 ) ;
V_75 = F_48 ( V_74 ) ? NULL : F_49 ( V_74 ) + V_50 -> V_66 ;
if ( V_61 ) {
F_50 ( V_59 , 2 ) ;
F_51 ( V_59 , V_52 , V_61 ) ;
F_52 ( V_59 , V_50 , V_75 == V_52 + V_61 , 2 ) ;
V_50 = V_59 ;
V_41 += V_61 ;
}
if ( V_2 -> V_56 && F_53 ( V_55 ) ) {
V_62 = F_43 ;
F_50 ( V_60 , 2 ) ;
F_54 ( V_60 , F_47 ( V_55 ) , V_55 -> V_67 , V_55 -> V_66 ) ;
F_52 ( V_60 , V_50 , 0 , 2 ) ;
V_50 = V_60 ;
V_41 += V_2 -> V_56 ;
}
V_34 -> V_41 = V_41 ;
V_34 -> V_39 = V_50 ;
return F_70 ( V_2 , V_62 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_46 * V_47 = F_22 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_41 ;
unsigned int V_45 = F_28 ( V_6 ) ;
T_1 * V_52 = V_2 -> V_52 ;
int V_3 ;
if ( V_41 < V_45 )
return - V_21 ;
V_41 -= V_45 ;
V_3 = F_71 ( V_2 , V_52 , V_41 ) ;
if ( V_3 )
return V_3 ;
F_31 ( V_47 , V_12 -> V_16 ) ;
F_32 ( V_47 , F_25 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_32 ) ;
F_33 ( V_47 , V_2 -> V_50 , V_2 -> V_51 , V_41 , V_52 ) ;
return F_34 ( V_47 ) ;
}
static int F_73 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = F_74 ( V_77 ) ;
struct V_80 * V_81 = F_75 ( V_79 ) ;
struct V_11 * V_12 = F_76 ( V_77 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_3 ;
V_14 = F_77 ( & V_81 -> V_14 ) ;
if ( F_55 ( V_14 ) )
return F_56 ( V_14 ) ;
V_16 = F_78 ( & V_81 -> V_16 ) ;
V_3 = F_56 ( V_16 ) ;
if ( F_55 ( V_16 ) )
goto V_82;
V_12 -> V_14 = V_14 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_38 = F_37 ( 2 * F_79 ( V_14 ) +
F_38 ( V_14 ) ,
F_38 ( V_14 ) + 1 ) +
F_60 ( V_16 ) ;
V_77 -> V_83 . V_84 = sizeof( struct V_33 ) +
V_12 -> V_38 +
F_80 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_givcrypt_request) +
crypto_ablkcipher_reqsize(enc)) ;
return 0 ;
V_82:
F_81 ( V_14 ) ;
return V_3 ;
}
static void F_82 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_76 ( V_77 ) ;
F_81 ( V_12 -> V_14 ) ;
F_83 ( V_12 -> V_16 ) ;
}
static struct V_78 * F_84 ( struct V_17 * * V_85 )
{
struct V_86 * V_87 ;
struct V_78 * V_79 ;
struct V_88 * V_14 ;
struct V_89 * V_90 ;
struct V_89 * V_16 ;
struct V_80 * V_12 ;
const char * V_91 ;
int V_3 ;
V_87 = F_85 ( V_85 ) ;
if ( F_55 ( V_87 ) )
return F_86 ( V_87 ) ;
if ( ( V_87 -> type ^ V_92 ) & V_87 -> V_93 )
return F_41 ( - V_21 ) ;
V_14 = F_87 ( V_85 [ 1 ] , V_94 ,
V_95 ) ;
if ( F_55 ( V_14 ) )
return F_86 ( V_14 ) ;
V_90 = & V_14 -> V_49 ;
V_91 = F_88 ( V_85 [ 2 ] ) ;
V_3 = F_56 ( V_91 ) ;
if ( F_55 ( V_91 ) )
goto V_96;
V_79 = F_89 ( sizeof( * V_79 ) + sizeof( * V_12 ) , V_97 ) ;
V_3 = - V_98 ;
if ( ! V_79 )
goto V_96;
V_12 = F_75 ( V_79 ) ;
V_3 = F_90 ( & V_12 -> V_14 , V_14 , V_79 ) ;
if ( V_3 )
goto V_99;
F_91 ( & V_12 -> V_16 , V_79 ) ;
V_3 = F_92 ( & V_12 -> V_16 , V_91 , 0 ,
F_93 ( V_87 -> type ,
V_87 -> V_93 ) ) ;
if ( V_3 )
goto V_100;
V_16 = F_94 ( & V_12 -> V_16 ) ;
V_3 = - V_101 ;
if ( snprintf ( V_79 -> V_102 . V_103 , V_104 ,
L_1 , V_90 -> V_103 , V_16 -> V_103 ) >=
V_104 )
goto V_105;
if ( snprintf ( V_79 -> V_102 . V_106 , V_104 ,
L_1 , V_90 -> V_106 ,
V_16 -> V_106 ) >= V_104 )
goto V_105;
V_79 -> V_102 . V_107 = V_92 ;
V_79 -> V_102 . V_107 |= V_16 -> V_107 & V_108 ;
V_79 -> V_102 . V_109 = V_16 -> V_109 *
10 + V_90 -> V_109 ;
V_79 -> V_102 . V_110 = V_16 -> V_110 ;
V_79 -> V_102 . V_111 = V_90 -> V_111 | V_16 -> V_111 ;
V_79 -> V_102 . V_112 = & V_113 ;
V_79 -> V_102 . V_114 . V_61 = V_16 -> V_115 . V_61 ;
V_79 -> V_102 . V_114 . V_116 = V_14 -> V_117 ;
V_79 -> V_102 . V_118 = sizeof( struct V_11 ) ;
V_79 -> V_102 . V_119 = F_73 ;
V_79 -> V_102 . V_120 = F_82 ;
V_79 -> V_102 . V_114 . V_121 = F_3 ;
V_79 -> V_102 . V_114 . V_122 = F_59 ;
V_79 -> V_102 . V_114 . V_123 = F_72 ;
V_79 -> V_102 . V_114 . V_124 = F_63 ;
V_28:
F_95 ( V_90 ) ;
return V_79 ;
V_105:
F_96 ( & V_12 -> V_16 ) ;
V_100:
F_97 ( & V_12 -> V_14 ) ;
V_99:
F_98 ( V_79 ) ;
V_96:
V_79 = F_41 ( V_3 ) ;
goto V_28;
}
static void F_99 ( struct V_78 * V_79 )
{
struct V_80 * V_12 = F_75 ( V_79 ) ;
F_96 ( & V_12 -> V_16 ) ;
F_97 ( & V_12 -> V_14 ) ;
F_98 ( V_79 ) ;
}
static int T_3 F_100 ( void )
{
return F_101 ( & V_125 ) ;
}
static void T_4 F_102 ( void )
{
F_103 ( & V_125 ) ;
}
