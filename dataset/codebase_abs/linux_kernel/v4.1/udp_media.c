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
struct V_28 * V_37 ;
struct V_38 * V_39 ;
V_37 = F_10 ( V_29 , V_40 ) ;
F_11 ( V_37 , F_12 ( V_41 ) ) ;
V_34 = F_13 ( V_21 -> V_42 ) ;
if ( ! V_34 ) {
V_32 = - V_43 ;
goto V_44;
}
if ( V_35 -> V_8 == F_12 ( V_9 ) ) {
struct V_45 V_46 = {
. V_47 = V_35 -> V_10 . V_11 ,
. V_48 = V_36 -> V_10 . V_11 ,
. V_49 = V_37 -> V_50 ,
. V_51 = V_52
} ;
V_39 = F_14 ( V_27 , & V_46 ) ;
if ( F_15 ( V_39 ) ) {
V_32 = F_16 ( V_39 ) ;
goto V_44;
}
V_31 = F_17 ( & V_39 -> V_35 ) ;
V_32 = F_18 ( V_39 , V_34 -> V_53 -> V_54 , V_37 ,
V_36 -> V_10 . V_11 ,
V_35 -> V_10 . V_11 , 0 , V_31 , 0 ,
V_36 -> V_19 , V_35 -> V_19 ,
false , true ) ;
if ( V_32 < 0 ) {
F_19 ( V_39 ) ;
goto V_44;
}
#if F_20 ( V_55 )
} else {
struct V_56 * V_57 ;
struct V_58 V_59 = {
. V_60 = V_34 -> V_61 ,
. V_47 = V_35 -> V_14 ,
. V_48 = V_36 -> V_14 ,
. V_62 = V_52
} ;
V_32 = V_63 -> V_64 ( V_34 -> V_53 -> V_54 , & V_57 , & V_59 ) ;
if ( V_32 )
goto V_44;
V_31 = F_21 ( V_57 ) ;
V_32 = F_22 ( V_57 , V_34 -> V_53 -> V_54 , V_37 ,
V_57 -> V_65 , & V_36 -> V_14 ,
& V_35 -> V_14 , 0 , V_31 , V_36 -> V_19 ,
V_35 -> V_19 , false ) ;
#endif
}
return V_32 ;
V_44:
F_23 ( V_37 ) ;
return V_32 ;
}
static int F_24 ( struct V_66 * V_54 , struct V_28 * V_29 )
{
struct V_33 * V_34 ;
struct V_20 * V_21 ;
V_34 = F_25 ( V_54 ) ;
if ( ! V_34 ) {
F_26 ( L_4 ) ;
F_23 ( V_29 ) ;
return 0 ;
}
F_27 ( V_29 , sizeof( struct V_67 ) ) ;
F_28 () ;
V_21 = F_13 ( V_34 -> V_68 ) ;
if ( V_21 ) {
F_29 ( F_30 ( V_54 ) , V_29 , V_21 ) ;
F_31 () ;
return 0 ;
}
F_31 () ;
F_23 ( V_29 ) ;
return 0 ;
}
static int F_32 ( struct V_33 * V_34 , struct V_3 * V_69 )
{
int V_32 = 0 ;
struct V_70 V_71 ;
struct V_66 * V_54 = V_34 -> V_53 -> V_54 ;
if ( F_2 ( V_69 -> V_8 ) == V_9 ) {
if ( ! F_3 ( V_69 -> V_10 . V_11 ) )
return 0 ;
V_71 . V_72 = V_69 -> V_10 ;
V_71 . V_73 = V_34 -> V_61 ;
V_32 = F_33 ( V_54 , & V_71 ) ;
#if F_20 ( V_55 )
} else {
if ( ! F_34 ( & V_69 -> V_14 ) )
return 0 ;
V_32 = V_63 -> V_74 ( V_54 , V_34 -> V_61 ,
& V_69 -> V_14 ) ;
#endif
}
return V_32 ;
}
static int F_35 ( struct V_75 * V_76 [] , struct V_33 * V_34 ,
struct V_3 * V_77 ,
struct V_3 * V_69 )
{
struct V_75 * V_78 [ V_79 + 1 ] ;
struct V_80 * V_81 , * V_82 ;
if ( ! V_76 [ V_83 ] )
goto V_32;
if ( F_36 ( V_78 , V_79 ,
V_76 [ V_83 ] ,
V_84 ) )
goto V_32;
if ( V_78 [ V_85 ] && V_78 [ V_86 ] ) {
V_81 = F_37 ( V_78 [ V_85 ] ) ;
V_82 = F_37 ( V_78 [ V_86 ] ) ;
} else {
V_32:
F_5 ( L_5 ) ;
return - V_25 ;
}
if ( ( V_81 -> V_87 & V_82 -> V_87 ) == V_88 ) {
struct V_89 * V_90 ;
V_90 = (struct V_89 * ) V_81 ;
V_77 -> V_8 = F_12 ( V_9 ) ;
V_77 -> V_19 = V_90 -> V_91 ;
V_77 -> V_10 . V_11 = V_90 -> V_92 . V_11 ;
V_90 = (struct V_89 * ) V_82 ;
V_69 -> V_8 = F_12 ( V_9 ) ;
V_69 -> V_19 = V_90 -> V_91 ;
V_69 -> V_10 . V_11 = V_90 -> V_92 . V_11 ;
return 0 ;
#if F_20 ( V_55 )
} else if ( ( V_81 -> V_87 & V_82 -> V_87 ) == V_93 ) {
struct V_94 * V_95 ;
V_95 = (struct V_94 * ) V_81 ;
V_77 -> V_8 = F_12 ( V_13 ) ;
V_77 -> V_19 = V_95 -> V_96 ;
V_77 -> V_14 = V_95 -> V_97 ;
V_34 -> V_61 = V_95 -> V_98 ;
V_95 = (struct V_94 * ) V_82 ;
V_69 -> V_8 = F_12 ( V_13 ) ;
V_69 -> V_19 = V_95 -> V_96 ;
V_69 -> V_14 = V_95 -> V_97 ;
return 0 ;
#endif
}
return - V_99 ;
}
static int F_38 ( struct V_27 * V_27 , struct V_20 * V_21 ,
struct V_75 * V_76 [] )
{
int V_32 = - V_25 ;
struct V_33 * V_34 ;
struct V_3 * V_69 ;
struct V_3 V_77 = { 0 } ;
struct V_100 V_101 = { 0 } ;
struct V_102 V_103 = { NULL } ;
V_34 = F_39 ( sizeof( * V_34 ) , V_40 ) ;
if ( ! V_34 )
return - V_104 ;
V_69 = (struct V_3 * ) & V_21 -> V_105 . V_7 ;
memset ( V_69 , 0 , sizeof( struct V_3 ) ) ;
V_32 = F_35 ( V_76 , V_34 , & V_77 , V_69 ) ;
if ( V_32 )
goto V_32;
V_21 -> V_105 . V_5 = V_6 ;
V_21 -> V_105 . V_12 = 1 ;
F_40 ( V_21 -> V_42 , V_34 ) ;
F_40 ( V_34 -> V_68 , V_21 ) ;
F_1 ( & V_21 -> V_2 , & V_77 ) ;
if ( V_77 . V_8 == F_12 ( V_9 ) ) {
struct V_106 * V_65 ;
V_65 = F_41 ( V_27 , V_77 . V_10 . V_11 , false ) ;
if ( ! V_65 ) {
V_32 = - V_43 ;
goto V_32;
}
V_101 . V_107 = V_88 ;
V_101 . V_108 . V_11 = F_42 ( V_109 ) ;
V_101 . V_110 = false ;
V_34 -> V_61 = V_65 -> V_61 ;
V_21 -> V_111 = V_65 -> V_111 - sizeof( struct V_112 )
- sizeof( struct V_67 ) ;
#if F_20 ( V_55 )
} else if ( V_77 . V_8 == F_12 ( V_13 ) ) {
V_101 . V_107 = V_93 ;
V_101 . V_113 = true ;
V_101 . V_114 = true ;
V_101 . V_115 = V_116 ;
V_21 -> V_111 = 1280 ;
#endif
} else {
V_32 = - V_117 ;
goto V_32;
}
V_101 . V_118 = V_77 . V_19 ;
V_32 = F_43 ( V_27 , & V_101 , & V_34 -> V_53 ) ;
if ( V_32 )
goto V_32;
V_103 . V_119 = V_34 ;
V_103 . V_120 = 1 ;
V_103 . V_121 = F_24 ;
V_103 . V_122 = NULL ;
F_44 ( V_27 , V_34 -> V_53 , & V_103 ) ;
if ( F_32 ( V_34 , V_69 ) )
goto V_32;
return 0 ;
V_32:
F_45 ( V_34 ) ;
return V_32 ;
}
static void F_46 ( struct V_123 * V_124 )
{
struct V_33 * V_34 = F_47 ( V_124 , struct V_33 , V_124 ) ;
if ( V_34 -> V_53 )
F_48 ( V_34 -> V_53 ) ;
F_49 () ;
F_45 ( V_34 ) ;
}
static void F_50 ( struct V_20 * V_21 )
{
struct V_33 * V_34 ;
V_34 = F_13 ( V_21 -> V_42 ) ;
if ( ! V_34 ) {
F_5 ( L_6 ) ;
return;
}
if ( V_34 -> V_53 )
F_51 ( V_34 -> V_53 -> V_54 , V_125 ) ;
F_52 ( V_21 -> V_42 , NULL ) ;
F_52 ( V_34 -> V_68 , NULL ) ;
F_53 ( & V_34 -> V_124 , F_46 ) ;
F_54 ( & V_34 -> V_124 ) ;
}
