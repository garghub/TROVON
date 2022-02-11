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
if ( F_10 ( V_29 ) < V_40 )
F_11 ( V_29 , V_40 , 0 , V_41 ) ;
V_37 = F_12 ( V_29 , V_41 ) ;
F_13 ( V_37 , F_14 ( V_42 ) ) ;
V_34 = F_15 ( V_21 -> V_43 ) ;
if ( ! V_34 ) {
V_32 = - V_44 ;
goto V_45;
}
if ( V_35 -> V_8 == F_14 ( V_9 ) ) {
struct V_46 V_47 = {
. V_48 = V_35 -> V_10 . V_11 ,
. V_49 = V_36 -> V_10 . V_11 ,
. V_50 = V_37 -> V_51 ,
. V_52 = V_53
} ;
V_39 = F_16 ( V_27 , & V_47 ) ;
if ( F_17 ( V_39 ) ) {
V_32 = F_18 ( V_39 ) ;
goto V_45;
}
V_31 = F_19 ( & V_39 -> V_35 ) ;
V_32 = F_20 ( V_39 , V_34 -> V_54 -> V_55 , V_37 ,
V_36 -> V_10 . V_11 ,
V_35 -> V_10 . V_11 , 0 , V_31 , 0 ,
V_36 -> V_19 , V_35 -> V_19 ,
false , true ) ;
if ( V_32 < 0 ) {
F_21 ( V_39 ) ;
goto V_45;
}
#if F_22 ( V_56 )
} else {
struct V_57 * V_58 ;
struct V_59 V_60 = {
. V_61 = V_34 -> V_62 ,
. V_48 = V_35 -> V_14 ,
. V_49 = V_36 -> V_14 ,
. V_63 = V_53
} ;
V_32 = V_64 -> V_65 ( V_27 , V_34 -> V_54 -> V_55 , & V_58 ,
& V_60 ) ;
if ( V_32 )
goto V_45;
V_31 = F_23 ( V_58 ) ;
V_32 = F_24 ( V_58 , V_34 -> V_54 -> V_55 , V_37 ,
V_58 -> V_66 , & V_36 -> V_14 ,
& V_35 -> V_14 , 0 , V_31 , V_36 -> V_19 ,
V_35 -> V_19 , false ) ;
#endif
}
return V_32 ;
V_45:
F_25 ( V_37 ) ;
return V_32 ;
}
static int F_26 ( struct V_67 * V_55 , struct V_28 * V_29 )
{
struct V_33 * V_34 ;
struct V_20 * V_21 ;
V_34 = F_27 ( V_55 ) ;
if ( ! V_34 ) {
F_28 ( L_4 ) ;
F_25 ( V_29 ) ;
return 0 ;
}
F_29 ( V_29 , sizeof( struct V_68 ) ) ;
F_30 () ;
V_21 = F_15 ( V_34 -> V_69 ) ;
if ( V_21 ) {
F_31 ( F_32 ( V_55 ) , V_29 , V_21 ) ;
F_33 () ;
return 0 ;
}
F_33 () ;
F_25 ( V_29 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 , struct V_3 * V_70 )
{
int V_32 = 0 ;
struct V_71 V_72 ;
struct V_67 * V_55 = V_34 -> V_54 -> V_55 ;
if ( F_2 ( V_70 -> V_8 ) == V_9 ) {
if ( ! F_3 ( V_70 -> V_10 . V_11 ) )
return 0 ;
V_72 . V_73 = V_70 -> V_10 ;
V_72 . V_74 = V_34 -> V_62 ;
V_32 = F_35 ( V_55 , & V_72 ) ;
#if F_22 ( V_56 )
} else {
if ( ! F_36 ( & V_70 -> V_14 ) )
return 0 ;
V_32 = V_64 -> V_75 ( V_55 , V_34 -> V_62 ,
& V_70 -> V_14 ) ;
#endif
}
return V_32 ;
}
static int F_37 ( struct V_76 * V_77 [] , struct V_33 * V_34 ,
struct V_3 * V_78 ,
struct V_3 * V_70 )
{
struct V_76 * V_79 [ V_80 + 1 ] ;
struct V_81 * V_82 , * V_83 ;
if ( ! V_77 [ V_84 ] )
goto V_32;
if ( F_38 ( V_79 , V_80 ,
V_77 [ V_84 ] ,
V_85 ) )
goto V_32;
if ( V_79 [ V_86 ] && V_79 [ V_87 ] ) {
V_82 = F_39 ( V_79 [ V_86 ] ) ;
V_83 = F_39 ( V_79 [ V_87 ] ) ;
} else {
V_32:
F_5 ( L_5 ) ;
return - V_25 ;
}
if ( ( V_82 -> V_88 & V_83 -> V_88 ) == V_89 ) {
struct V_90 * V_91 ;
V_91 = (struct V_90 * ) V_82 ;
V_78 -> V_8 = F_14 ( V_9 ) ;
V_78 -> V_19 = V_91 -> V_92 ;
V_78 -> V_10 . V_11 = V_91 -> V_93 . V_11 ;
V_91 = (struct V_90 * ) V_83 ;
V_70 -> V_8 = F_14 ( V_9 ) ;
V_70 -> V_19 = V_91 -> V_92 ;
V_70 -> V_10 . V_11 = V_91 -> V_93 . V_11 ;
return 0 ;
#if F_22 ( V_56 )
} else if ( ( V_82 -> V_88 & V_83 -> V_88 ) == V_94 ) {
struct V_95 * V_96 ;
V_96 = (struct V_95 * ) V_82 ;
V_78 -> V_8 = F_14 ( V_13 ) ;
V_78 -> V_19 = V_96 -> V_97 ;
V_78 -> V_14 = V_96 -> V_98 ;
V_34 -> V_62 = V_96 -> V_99 ;
V_96 = (struct V_95 * ) V_83 ;
V_70 -> V_8 = F_14 ( V_13 ) ;
V_70 -> V_19 = V_96 -> V_97 ;
V_70 -> V_14 = V_96 -> V_98 ;
return 0 ;
#endif
}
return - V_100 ;
}
static int F_40 ( struct V_27 * V_27 , struct V_20 * V_21 ,
struct V_76 * V_77 [] )
{
int V_32 = - V_25 ;
struct V_33 * V_34 ;
struct V_3 * V_70 ;
struct V_3 V_78 = { 0 } ;
struct V_101 V_102 = { 0 } ;
struct V_103 V_104 = { NULL } ;
V_34 = F_41 ( sizeof( * V_34 ) , V_41 ) ;
if ( ! V_34 )
return - V_105 ;
V_70 = (struct V_3 * ) & V_21 -> V_106 . V_7 ;
memset ( V_70 , 0 , sizeof( struct V_3 ) ) ;
V_32 = F_37 ( V_77 , V_34 , & V_78 , V_70 ) ;
if ( V_32 )
goto V_32;
V_21 -> V_106 . V_5 = V_6 ;
V_21 -> V_106 . V_12 = 1 ;
F_42 ( V_21 -> V_43 , V_34 ) ;
F_42 ( V_34 -> V_69 , V_21 ) ;
F_1 ( & V_21 -> V_2 , & V_78 ) ;
if ( V_78 . V_8 == F_14 ( V_9 ) ) {
struct V_107 * V_66 ;
V_66 = F_43 ( V_27 , V_78 . V_10 . V_11 , false ) ;
if ( ! V_66 ) {
V_32 = - V_44 ;
goto V_32;
}
V_102 . V_108 = V_89 ;
V_102 . V_109 . V_11 = F_44 ( V_110 ) ;
V_102 . V_111 = false ;
V_34 -> V_62 = V_66 -> V_62 ;
V_21 -> V_112 = V_66 -> V_112 - sizeof( struct V_113 )
- sizeof( struct V_68 ) ;
#if F_22 ( V_56 )
} else if ( V_78 . V_8 == F_14 ( V_13 ) ) {
V_102 . V_108 = V_94 ;
V_102 . V_114 = true ;
V_102 . V_115 = true ;
V_102 . V_116 = V_117 ;
V_21 -> V_112 = 1280 ;
#endif
} else {
V_32 = - V_118 ;
goto V_32;
}
V_102 . V_119 = V_78 . V_19 ;
V_32 = F_45 ( V_27 , & V_102 , & V_34 -> V_54 ) ;
if ( V_32 )
goto V_32;
V_104 . V_120 = V_34 ;
V_104 . V_121 = 1 ;
V_104 . V_122 = F_26 ;
V_104 . V_123 = NULL ;
F_46 ( V_27 , V_34 -> V_54 , & V_104 ) ;
if ( F_34 ( V_34 , V_70 ) )
goto V_32;
return 0 ;
V_32:
F_47 ( V_34 ) ;
return V_32 ;
}
static void F_48 ( struct V_124 * V_125 )
{
struct V_33 * V_34 = F_49 ( V_125 , struct V_33 , V_125 ) ;
if ( V_34 -> V_54 )
F_50 ( V_34 -> V_54 ) ;
F_51 () ;
F_47 ( V_34 ) ;
}
static void F_52 ( struct V_20 * V_21 )
{
struct V_33 * V_34 ;
V_34 = F_15 ( V_21 -> V_43 ) ;
if ( ! V_34 ) {
F_5 ( L_6 ) ;
return;
}
if ( V_34 -> V_54 )
F_53 ( V_34 -> V_54 -> V_55 , V_126 ) ;
F_54 ( V_21 -> V_43 , NULL ) ;
F_54 ( V_34 -> V_69 , NULL ) ;
F_55 ( & V_34 -> V_125 , F_48 ) ;
F_56 ( & V_34 -> V_125 ) ;
}
