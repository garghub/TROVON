static int F_1 ( T_1 * * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
* V_1 = F_2 ( * V_1 , & V_3 ) ;
if ( V_3 & 0x1ff ) {
F_3 ( V_4 L_1 , V_5 ) ;
return - 1 ;
}
* V_2 = V_3 >> V_6 ;
return 0 ;
}
int F_4 ( struct V_7 * V_8 )
{
F_5 ( L_2 , V_5 , F_6 ( V_8 -> V_9 ) ,
F_7 ( V_8 -> V_9 ) ) ;
return F_8 ( V_8 , V_10 ) ;
}
T_4 F_9 ( struct V_11 * V_12 , const char T_5 * V_13 ,
T_6 V_14 )
{
struct V_15 * V_16 = F_10 ( V_12 -> V_17 -> V_18 -> V_19 ,
V_20 ) ;
if ( V_14 != sizeof ( struct V_21 ) )
return - V_22 ;
if ( F_11 ( & V_16 -> V_23 , V_13 , V_14 ) != 0 )
return - V_24 ;
F_12 ( & V_16 -> V_25 ) ;
return V_14 ;
}
void F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_14 ( V_27 , struct V_28 , V_27 ) ;
if ( V_27 -> V_29 >= 0 )
return;
F_12 ( V_28 -> V_25 ) ;
}
struct V_30 *
F_15 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_30 * V_35 ;
struct V_7 * V_36 = NULL ;
struct V_28 V_28 ;
struct V_26 * V_27 = & V_28 . V_27 ;
struct V_37 V_38 = {
. type = V_39 ,
. V_40 = V_34 -> V_41 ,
} ;
T_7 * V_42 ;
F_16 ( V_43 , V_44 ) ;
int V_45 , V_46 , V_47 , V_48 ;
struct V_49 * V_49 = V_32 -> V_50 -> V_51 ;
struct V_15 * V_16 = F_10 ( V_49 , V_20 ) ;
struct V_21 * V_52 = & V_16 -> V_23 ;
F_5 ( L_3 , V_5 ) ;
F_5 ( L_4 , V_5 , V_34 -> V_53 . V_54 ,
V_34 -> V_41 ) ;
V_28 . V_25 = & V_16 -> V_25 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_54 = F_17 ( sizeof( V_38 ) + V_34 -> V_41 , V_55 ) ;
if ( ! V_27 -> V_54 ) {
V_35 = F_18 ( - V_56 ) ;
goto V_57;
}
memcpy ( V_27 -> V_54 , & V_38 , sizeof( V_38 ) ) ;
V_42 = ( T_7 * ) V_27 -> V_54 ;
V_46 = V_34 -> V_41 ;
V_45 = sizeof( V_38 ) ;
for ( V_47 = 0 ; V_46 > 0 ; V_47 ++ ) {
memcpy ( & V_42 [ V_45 ] , F_19 ( V_34 -> V_58 [ V_47 ] ) ,
V_46 < V_59 ? V_46 : V_59 ) ;
V_46 -= V_59 ;
V_45 += V_59 ;
}
V_27 -> V_46 = sizeof( V_38 ) + V_34 -> V_41 ;
F_5 ( L_5 , V_5 ) ;
F_20 ( & V_16 -> V_25 , & V_43 ) ;
V_48 = F_21 ( V_16 -> V_60 , V_27 ) ;
if ( V_48 < 0 ) {
F_22 ( & V_16 -> V_25 , & V_43 ) ;
V_35 = F_18 ( V_48 ) ;
goto V_57;
}
F_23 ( V_61 ) ;
F_24 () ;
F_25 ( V_62 ) ;
F_22 ( & V_16 -> V_25 , & V_43 ) ;
if ( V_52 -> V_63 != V_64 ) {
F_5 ( L_6 ,
V_5 , V_52 -> V_63 ) ;
V_35 = F_18 ( - V_22 ) ;
goto V_57;
}
V_36 = F_26 ( F_27 ( V_52 -> V_65 , V_52 -> V_66 ) ,
V_10 , NULL ) ;
if ( F_28 ( V_36 ) ) {
F_5 ( L_7 , V_5 ,
F_29 ( V_36 ) ) ;
V_35 = F_30 ( V_36 ) ;
goto V_57;
}
V_35 = F_17 ( sizeof( * V_35 ) , V_55 ) ;
if ( ! V_35 ) {
V_35 = F_18 ( - V_56 ) ;
goto V_57;
}
V_35 -> V_67 = V_36 ;
memcpy ( & V_35 -> V_68 , & V_34 -> V_53 , sizeof( struct V_69 ) ) ;
V_35 -> V_49 = V_49 ;
F_5 ( L_8 ,
V_5 ,
V_36 -> V_70 -> V_71 ,
V_36 -> V_72 ) ;
V_57:
F_31 ( V_27 -> V_54 ) ;
return V_35 ;
}
static struct V_7 * F_32 ( struct V_73 * V_74 ,
struct V_69 * V_75 )
{
struct V_7 * V_35 = NULL ;
struct V_76 * V_77 ;
struct V_30 * V_34 ;
F_5 ( L_9 , V_5 , V_74 , V_75 ) ;
V_77 = F_33 ( V_74 ) ;
F_34 ( & V_77 -> V_78 ) ;
F_35 (dev, &mid->bm_devlist, bm_node) {
if ( memcmp ( V_75 -> V_54 , V_34 -> V_68 . V_54 ,
V_79 ) == 0 ) {
V_35 = V_34 -> V_67 ;
goto V_57;
}
}
V_57:
F_36 ( & V_77 -> V_78 ) ;
F_5 ( L_10 , V_5 , V_35 ) ;
return V_35 ;
}
static int F_37 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
if ( V_83 -> V_84 == V_85 ) {
if ( V_81 -> V_86 == V_87 ||
V_81 -> V_86 == V_88 )
return - V_89 ;
if ( V_81 -> V_90 != V_83 -> V_91 )
return - V_89 ;
V_83 -> V_91 += V_81 -> V_92 ;
return 0 ;
}
if ( V_81 -> V_86 == V_87 ) {
if ( V_81 -> V_90 != V_83 -> V_91 )
return - V_89 ;
if ( V_83 -> V_93 > V_83 -> V_91 )
return - V_89 ;
V_83 -> V_91 += V_81 -> V_92 ;
V_83 -> V_94 = V_83 -> V_91 ;
return 0 ;
} else if ( V_81 -> V_86 == V_88 ) {
if ( V_81 -> V_90 != V_83 -> V_91 )
return - V_89 ;
V_83 -> V_91 += V_81 -> V_92 ;
return 0 ;
} else if ( V_81 -> V_86 == V_95 ) {
if ( V_81 -> V_90 > V_83 -> V_91 )
return - V_89 ;
if ( V_81 -> V_90 < V_83 -> V_94 )
return - V_89 ;
if ( V_81 -> V_90 < V_83 -> V_93 )
return - V_89 ;
V_83 -> V_94 = V_83 -> V_94 + V_81 -> V_92 ;
V_83 -> V_93 = V_81 -> V_90 + V_81 -> V_92 ;
return 0 ;
} else
return - V_89 ;
}
int
F_38 ( struct V_73 * V_74 ,
struct V_96 * V_97 , T_8 V_98 )
{
struct V_99 * V_100 = F_39 ( V_74 ) ;
int V_47 , V_63 = - V_89 ;
T_9 V_101 ;
struct V_80 * V_81 = NULL , * V_102 ;
struct V_103 V_104 ;
struct V_105 V_106 ;
struct V_107 * V_108 ;
T_1 * V_109 ;
struct V_82 V_83 = {
. V_84 = V_97 -> V_110 . V_111 ,
. V_91 = V_97 -> V_110 . V_45 >> V_6 ,
. V_94 = V_97 -> V_110 . V_45 >> V_6 ,
. V_93 = V_97 -> V_110 . V_45 >> V_6 ,
} ;
F_40 ( V_112 ) ;
F_5 ( L_11 , V_5 ) ;
V_108 = F_41 ( V_98 ) ;
if ( ! V_108 )
return - V_56 ;
F_42 ( & V_104 , & V_106 , V_97 -> V_113 -> V_58 , V_97 -> V_113 -> V_46 ) ;
F_43 ( & V_104 , F_19 ( V_108 ) , V_114 ) ;
V_109 = F_44 ( & V_104 , 4 ) ;
if ( F_45 ( ! V_109 ) )
goto V_115;
V_101 = F_46 ( V_109 ++ ) ;
F_5 ( L_12 , V_5 , V_101 ) ;
V_109 = F_44 ( & V_104 , ( 28 + V_79 ) * V_101 ) ;
if ( F_45 ( ! V_109 ) )
goto V_115;
for ( V_47 = 0 ; V_47 < V_101 ; V_47 ++ ) {
V_81 = F_47 () ;
if ( ! V_81 ) {
V_63 = - V_56 ;
goto V_115;
}
memcpy ( & V_81 -> V_116 , V_109 , V_79 ) ;
V_109 += F_48 ( V_79 ) ;
V_81 -> V_117 = F_32 ( V_74 , & V_81 -> V_116 ) ;
if ( ! V_81 -> V_117 )
goto V_115;
if ( F_1 ( & V_109 , & V_81 -> V_90 ) < 0 )
goto V_115;
if ( F_1 ( & V_109 , & V_81 -> V_92 ) < 0 )
goto V_115;
if ( F_1 ( & V_109 , & V_81 -> V_118 ) < 0 )
goto V_115;
V_81 -> V_86 = F_46 ( V_109 ++ ) ;
if ( V_81 -> V_86 == V_88 )
V_81 -> V_119 = & V_100 -> V_120 ;
if ( F_37 ( V_81 , & V_83 ) ) {
F_5 ( L_13 , V_5 ) ;
goto V_115;
}
F_49 ( & V_81 -> V_121 , & V_112 ) ;
}
if ( V_97 -> V_110 . V_45 + V_97 -> V_110 . V_122 !=
V_83 . V_91 << V_6 ) {
F_5 ( L_14 , V_5 ) ;
V_81 = NULL ;
goto V_115;
}
if ( V_83 . V_91 < V_83 . V_93 ) {
F_5 ( L_15 , V_5 ) ;
V_81 = NULL ;
goto V_115;
}
F_34 ( & V_100 -> V_123 ) ;
F_50 (be, save, &extents, be_node) {
F_51 ( & V_81 -> V_121 ) ;
V_63 = F_52 ( V_100 , V_81 ) ;
if ( V_63 ) {
F_36 ( & V_100 -> V_123 ) ;
V_81 = NULL ;
goto V_115;
}
}
F_36 ( & V_100 -> V_123 ) ;
V_63 = 0 ;
V_57:
F_53 ( V_108 ) ;
F_5 ( L_16 , V_5 , V_63 ) ;
return V_63 ;
V_115:
F_54 ( V_81 ) ;
while ( ! F_55 ( & V_112 ) ) {
V_81 = F_56 ( & V_112 , struct V_80 ,
V_121 ) ;
F_51 ( & V_81 -> V_121 ) ;
F_54 ( V_81 ) ;
}
goto V_57;
}
