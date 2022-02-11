static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_5 = V_6 ;
memcpy ( V_2 -> V_7 , V_4 , sizeof( struct V_3 ) ) ;
if ( F_2 ( V_4 -> V_8 ) == V_9 ) {
if ( F_3 ( V_4 -> V_10 . V_11 ) )
V_2 -> V_12 = 1 ;
} else if ( F_2 ( V_4 -> V_8 ) == V_13 ) {
if ( F_4 ( & V_4 -> V_14 ) & V_15 )
V_2 -> V_12 = 1 ;
} else {
F_5 ( L_1 ) ;
}
}
static int F_6 ( struct V_1 * V_16 , char * V_17 , int V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) & V_16 -> V_7 ;
if ( F_2 ( V_4 -> V_8 ) == V_9 )
snprintf ( V_17 , V_18 , L_2 , & V_4 -> V_10 , F_2 ( V_4 -> V_19 ) ) ;
else if ( F_2 ( V_4 -> V_8 ) == V_13 )
snprintf ( V_17 , V_18 , L_3 , & V_4 -> V_14 , F_2 ( V_4 -> V_19 ) ) ;
else
F_5 ( L_1 ) ;
return 0 ;
}
static int F_7 ( struct V_20 * V_21 , struct V_1 * V_16 ,
char * V_22 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) ( V_22 + V_23 ) ;
if ( V_22 [ V_24 ] != V_6 )
return - V_25 ;
F_1 ( V_16 , V_4 ) ;
return 0 ;
}
static int F_8 ( char * V_22 , struct V_1 * V_16 )
{
memset ( V_22 , 0 , V_26 ) ;
V_22 [ V_24 ] = V_6 ;
memcpy ( V_22 + V_23 , V_16 -> V_7 ,
sizeof( struct V_3 ) ) ;
return 0 ;
}
static int F_9 ( struct V_27 * V_27 , struct V_28 * V_29 ,
struct V_20 * V_21 ,
struct V_1 * V_30 )
{
int V_31 , V_32 = 0 ;
struct V_33 * V_34 ;
struct V_3 * V_35 = (struct V_3 * ) & V_30 -> V_7 ;
struct V_3 * V_36 = (struct V_3 * ) & V_21 -> V_2 . V_7 ;
struct V_37 * V_38 ;
if ( F_10 ( V_29 ) < V_39 ) {
V_32 = F_11 ( V_29 , V_39 , 0 , V_40 ) ;
if ( V_32 )
goto V_41;
}
F_12 ( V_29 , F_13 ( V_42 ) ) ;
V_34 = F_14 ( V_21 -> V_43 ) ;
if ( ! V_34 ) {
V_32 = - V_44 ;
goto V_41;
}
if ( V_35 -> V_8 == F_13 ( V_9 ) ) {
struct V_45 V_46 = {
. V_47 = V_35 -> V_10 . V_11 ,
. V_48 = V_36 -> V_10 . V_11 ,
. V_49 = V_29 -> V_50 ,
. V_51 = V_52
} ;
V_38 = F_15 ( V_27 , & V_46 ) ;
if ( F_16 ( V_38 ) ) {
V_32 = F_17 ( V_38 ) ;
goto V_41;
}
V_31 = F_18 ( & V_38 -> V_35 ) ;
V_32 = F_19 ( V_38 , V_34 -> V_53 -> V_54 , V_29 ,
V_36 -> V_10 . V_11 ,
V_35 -> V_10 . V_11 , 0 , V_31 , 0 ,
V_36 -> V_19 , V_35 -> V_19 ,
false , true ) ;
if ( V_32 < 0 ) {
F_20 ( V_38 ) ;
goto V_41;
}
#if F_21 ( V_55 )
} else {
struct V_56 * V_57 ;
struct V_58 V_59 = {
. V_60 = V_34 -> V_61 ,
. V_47 = V_35 -> V_14 ,
. V_48 = V_36 -> V_14 ,
. V_62 = V_52
} ;
V_32 = V_63 -> V_64 ( V_27 , V_34 -> V_53 -> V_54 , & V_57 ,
& V_59 ) ;
if ( V_32 )
goto V_41;
V_31 = F_22 ( V_57 ) ;
V_32 = F_23 ( V_57 , V_34 -> V_53 -> V_54 , V_29 ,
V_57 -> V_65 , & V_36 -> V_14 ,
& V_35 -> V_14 , 0 , V_31 , V_36 -> V_19 ,
V_35 -> V_19 , false ) ;
#endif
}
return V_32 ;
V_41:
F_24 ( V_29 ) ;
return V_32 ;
}
static int F_25 ( struct V_66 * V_54 , struct V_28 * V_29 )
{
struct V_33 * V_34 ;
struct V_20 * V_21 ;
int V_67 = F_26 ( F_27 ( V_29 ) ) ;
if ( ( V_67 == V_68 ) || ( V_67 == V_69 ) )
F_28 ( V_29 ) ;
V_34 = F_29 ( V_54 ) ;
if ( ! V_34 ) {
F_30 ( L_4 ) ;
F_24 ( V_29 ) ;
return 0 ;
}
F_31 ( V_29 , sizeof( struct V_70 ) ) ;
F_32 () ;
V_21 = F_14 ( V_34 -> V_71 ) ;
if ( V_21 ) {
F_33 ( F_34 ( V_54 ) , V_29 , V_21 ) ;
F_35 () ;
return 0 ;
}
F_35 () ;
F_24 ( V_29 ) ;
return 0 ;
}
static int F_36 ( struct V_33 * V_34 , struct V_3 * V_72 )
{
int V_32 = 0 ;
struct V_73 V_74 ;
struct V_66 * V_54 = V_34 -> V_53 -> V_54 ;
if ( F_2 ( V_72 -> V_8 ) == V_9 ) {
if ( ! F_3 ( V_72 -> V_10 . V_11 ) )
return 0 ;
V_74 . V_75 = V_72 -> V_10 ;
V_74 . V_76 = V_34 -> V_61 ;
V_32 = F_37 ( V_54 , & V_74 ) ;
#if F_21 ( V_55 )
} else {
if ( ! F_38 ( & V_72 -> V_14 ) )
return 0 ;
V_32 = V_63 -> V_77 ( V_54 , V_34 -> V_61 ,
& V_72 -> V_14 ) ;
#endif
}
return V_32 ;
}
static int F_39 ( struct V_78 * V_79 [] , struct V_33 * V_34 ,
struct V_3 * V_80 ,
struct V_3 * V_72 )
{
struct V_78 * V_81 [ V_82 + 1 ] ;
struct V_83 * V_84 , * V_85 ;
if ( ! V_79 [ V_86 ] )
goto V_32;
if ( F_40 ( V_81 , V_82 ,
V_79 [ V_86 ] ,
V_87 ) )
goto V_32;
if ( V_81 [ V_88 ] && V_81 [ V_89 ] ) {
V_84 = F_41 ( V_81 [ V_88 ] ) ;
V_85 = F_41 ( V_81 [ V_89 ] ) ;
} else {
V_32:
F_5 ( L_5 ) ;
return - V_25 ;
}
if ( ( V_84 -> V_90 & V_85 -> V_90 ) == V_91 ) {
struct V_92 * V_93 ;
V_93 = (struct V_92 * ) V_84 ;
V_80 -> V_8 = F_13 ( V_9 ) ;
V_80 -> V_19 = V_93 -> V_94 ;
V_80 -> V_10 . V_11 = V_93 -> V_95 . V_11 ;
V_93 = (struct V_92 * ) V_85 ;
V_72 -> V_8 = F_13 ( V_9 ) ;
V_72 -> V_19 = V_93 -> V_94 ;
V_72 -> V_10 . V_11 = V_93 -> V_95 . V_11 ;
return 0 ;
#if F_21 ( V_55 )
} else if ( ( V_84 -> V_90 & V_85 -> V_90 ) == V_96 ) {
struct V_97 * V_98 ;
V_98 = (struct V_97 * ) V_84 ;
V_80 -> V_8 = F_13 ( V_13 ) ;
V_80 -> V_19 = V_98 -> V_99 ;
V_80 -> V_14 = V_98 -> V_100 ;
V_34 -> V_61 = V_98 -> V_101 ;
V_98 = (struct V_97 * ) V_85 ;
V_72 -> V_8 = F_13 ( V_13 ) ;
V_72 -> V_19 = V_98 -> V_99 ;
V_72 -> V_14 = V_98 -> V_100 ;
return 0 ;
#endif
}
return - V_102 ;
}
static int F_42 ( struct V_27 * V_27 , struct V_20 * V_21 ,
struct V_78 * V_79 [] )
{
int V_32 = - V_25 ;
struct V_33 * V_34 ;
struct V_3 * V_72 ;
struct V_3 V_80 = { 0 } ;
struct V_103 V_104 = { 0 } ;
struct V_105 V_106 = { NULL } ;
V_34 = F_43 ( sizeof( * V_34 ) , V_40 ) ;
if ( ! V_34 )
return - V_107 ;
V_72 = (struct V_3 * ) & V_21 -> V_108 . V_7 ;
memset ( V_72 , 0 , sizeof( struct V_3 ) ) ;
V_32 = F_39 ( V_79 , V_34 , & V_80 , V_72 ) ;
if ( V_32 )
goto V_32;
V_21 -> V_108 . V_5 = V_6 ;
V_21 -> V_108 . V_12 = 1 ;
F_44 ( V_21 -> V_43 , V_34 ) ;
F_44 ( V_34 -> V_71 , V_21 ) ;
F_1 ( & V_21 -> V_2 , & V_80 ) ;
if ( V_80 . V_8 == F_13 ( V_9 ) ) {
struct V_109 * V_65 ;
V_65 = F_45 ( V_27 , V_80 . V_10 . V_11 , false ) ;
if ( ! V_65 ) {
V_32 = - V_44 ;
goto V_32;
}
V_104 . V_110 = V_91 ;
V_104 . V_111 . V_11 = F_46 ( V_112 ) ;
V_104 . V_113 = false ;
V_34 -> V_61 = V_65 -> V_61 ;
V_21 -> V_114 = V_65 -> V_114 - sizeof( struct V_115 )
- sizeof( struct V_70 ) ;
#if F_21 ( V_55 )
} else if ( V_80 . V_8 == F_13 ( V_13 ) ) {
V_104 . V_110 = V_96 ;
V_104 . V_116 = true ;
V_104 . V_117 = true ;
V_104 . V_118 = V_119 ;
V_21 -> V_114 = 1280 ;
#endif
} else {
V_32 = - V_120 ;
goto V_32;
}
V_104 . V_121 = V_80 . V_19 ;
V_32 = F_47 ( V_27 , & V_104 , & V_34 -> V_53 ) ;
if ( V_32 )
goto V_32;
V_106 . V_122 = V_34 ;
V_106 . V_123 = 1 ;
V_106 . V_124 = F_25 ;
V_106 . V_125 = NULL ;
F_48 ( V_27 , V_34 -> V_53 , & V_106 ) ;
if ( F_36 ( V_34 , V_72 ) )
goto V_32;
return 0 ;
V_32:
F_49 ( V_34 ) ;
return V_32 ;
}
static void F_50 ( struct V_126 * V_127 )
{
struct V_33 * V_34 = F_51 ( V_127 , struct V_33 , V_127 ) ;
if ( V_34 -> V_53 )
F_52 ( V_34 -> V_53 ) ;
F_53 () ;
F_49 ( V_34 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_33 * V_34 ;
V_34 = F_14 ( V_21 -> V_43 ) ;
if ( ! V_34 ) {
F_5 ( L_6 ) ;
return;
}
if ( V_34 -> V_53 )
F_55 ( V_34 -> V_53 -> V_54 , V_128 ) ;
F_56 ( V_34 -> V_71 , NULL ) ;
F_57 ( & V_34 -> V_127 , F_50 ) ;
F_58 ( & V_34 -> V_127 ) ;
}
