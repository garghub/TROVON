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
struct V_7 * F_4 ( T_4 V_8 )
{
struct V_7 * V_9 ;
F_5 ( L_2 , V_5 ) ;
V_9 = F_6 ( V_8 , V_10 , NULL ) ;
if ( F_7 ( V_9 ) )
goto V_11;
return V_9 ;
V_11:
F_5 ( L_3 ,
V_5 , F_8 ( V_9 ) ) ;
return NULL ;
}
int F_9 ( struct V_7 * V_12 )
{
F_5 ( L_4 , V_5 , F_10 ( V_12 -> V_13 ) ,
F_11 ( V_12 -> V_13 ) ) ;
return F_12 ( V_12 , V_10 ) ;
}
T_5 F_13 ( struct V_14 * V_15 , const char T_6 * V_16 ,
T_7 V_17 )
{
struct V_18 * V_19 = F_14 ( V_15 -> V_20 -> V_21 -> V_22 ,
V_23 ) ;
if ( V_17 != sizeof ( struct V_24 ) )
return - V_25 ;
if ( F_15 ( & V_19 -> V_26 , V_16 , V_17 ) != 0 )
return - V_27 ;
F_16 ( & V_19 -> V_28 ) ;
return V_17 ;
}
void F_17 ( struct V_29 * V_30 )
{
struct V_31 * V_31 = F_18 ( V_30 , struct V_31 , V_30 ) ;
if ( V_30 -> V_32 >= 0 )
return;
F_16 ( V_31 -> V_28 ) ;
}
struct V_33 *
F_19 ( struct V_34 * V_35 ,
struct V_36 * V_8 )
{
struct V_33 * V_37 ;
struct V_7 * V_9 = NULL ;
struct V_31 V_31 ;
struct V_29 * V_30 = & V_31 . V_30 ;
struct V_38 V_39 = {
. type = V_40 ,
. V_41 = V_8 -> V_42 ,
} ;
T_8 * V_43 ;
F_20 ( V_44 , V_45 ) ;
int V_46 , V_47 , V_48 , V_49 ;
struct V_50 * V_50 = V_35 -> V_51 -> V_52 ;
struct V_18 * V_19 = F_14 ( V_50 , V_23 ) ;
struct V_24 * V_53 = & V_19 -> V_26 ;
F_5 ( L_5 , V_5 ) ;
F_5 ( L_6 , V_5 , V_8 -> V_54 . V_55 ,
V_8 -> V_42 ) ;
V_31 . V_28 = & V_19 -> V_28 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_55 = F_21 ( sizeof( V_39 ) + V_8 -> V_42 , V_56 ) ;
if ( ! V_30 -> V_55 ) {
V_37 = F_22 ( - V_57 ) ;
goto V_58;
}
memcpy ( V_30 -> V_55 , & V_39 , sizeof( V_39 ) ) ;
V_43 = ( T_8 * ) V_30 -> V_55 ;
V_47 = V_8 -> V_42 ;
V_46 = sizeof( V_39 ) ;
for ( V_48 = 0 ; V_47 > 0 ; V_48 ++ ) {
memcpy ( & V_43 [ V_46 ] , F_23 ( V_8 -> V_59 [ V_48 ] ) ,
V_47 < V_60 ? V_47 : V_60 ) ;
V_47 -= V_60 ;
V_46 += V_60 ;
}
V_30 -> V_47 = sizeof( V_39 ) + V_8 -> V_42 ;
F_5 ( L_7 , V_5 ) ;
F_24 ( & V_19 -> V_28 , & V_44 ) ;
V_49 = F_25 ( V_19 -> V_61 , V_30 ) ;
if ( V_49 < 0 ) {
F_26 ( & V_19 -> V_28 , & V_44 ) ;
V_37 = F_22 ( V_49 ) ;
goto V_58;
}
F_27 ( V_62 ) ;
F_28 () ;
F_29 ( V_63 ) ;
F_26 ( & V_19 -> V_28 , & V_44 ) ;
if ( V_53 -> V_64 != V_65 ) {
F_5 ( L_8 ,
V_5 , V_53 -> V_64 ) ;
V_37 = F_22 ( - V_25 ) ;
goto V_58;
}
V_9 = F_4 ( F_30 ( V_53 -> V_66 , V_53 -> V_67 ) ) ;
if ( F_7 ( V_9 ) ) {
V_49 = F_8 ( V_9 ) ;
F_5 ( L_9 , V_5 , V_49 ) ;
V_37 = F_22 ( V_49 ) ;
goto V_58;
}
V_37 = F_21 ( sizeof( * V_37 ) , V_56 ) ;
if ( ! V_37 ) {
V_37 = F_22 ( - V_57 ) ;
goto V_58;
}
V_37 -> V_68 = V_9 ;
memcpy ( & V_37 -> V_69 , & V_8 -> V_54 , sizeof( struct V_70 ) ) ;
V_37 -> V_50 = V_50 ;
F_5 ( L_10 ,
V_5 ,
V_9 -> V_71 -> V_72 ,
V_9 -> V_73 ) ;
V_58:
F_31 ( V_30 -> V_55 ) ;
return V_37 ;
}
static struct V_7 * F_32 ( struct V_74 * V_75 ,
struct V_70 * V_76 )
{
struct V_7 * V_37 = NULL ;
struct V_77 * V_78 ;
struct V_33 * V_8 ;
F_5 ( L_11 , V_5 , V_75 , V_76 ) ;
V_78 = F_33 ( V_75 ) ;
F_34 ( & V_78 -> V_79 ) ;
F_35 (dev, &mid->bm_devlist, bm_node) {
if ( memcmp ( V_76 -> V_55 , V_8 -> V_69 . V_55 ,
V_80 ) == 0 ) {
V_37 = V_8 -> V_68 ;
goto V_58;
}
}
V_58:
F_36 ( & V_78 -> V_79 ) ;
F_5 ( L_12 , V_5 , V_37 ) ;
return V_37 ;
}
static int F_37 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
if ( V_84 -> V_85 == V_86 ) {
if ( V_82 -> V_87 == V_88 ||
V_82 -> V_87 == V_89 )
return - V_90 ;
if ( V_82 -> V_91 != V_84 -> V_92 )
return - V_90 ;
V_84 -> V_92 += V_82 -> V_93 ;
return 0 ;
}
if ( V_82 -> V_87 == V_88 ) {
if ( V_82 -> V_91 != V_84 -> V_92 )
return - V_90 ;
if ( V_84 -> V_94 > V_84 -> V_92 )
return - V_90 ;
V_84 -> V_92 += V_82 -> V_93 ;
V_84 -> V_95 = V_84 -> V_92 ;
return 0 ;
} else if ( V_82 -> V_87 == V_89 ) {
if ( V_82 -> V_91 != V_84 -> V_92 )
return - V_90 ;
V_84 -> V_92 += V_82 -> V_93 ;
return 0 ;
} else if ( V_82 -> V_87 == V_96 ) {
if ( V_82 -> V_91 > V_84 -> V_92 )
return - V_90 ;
if ( V_82 -> V_91 < V_84 -> V_95 )
return - V_90 ;
if ( V_82 -> V_91 < V_84 -> V_94 )
return - V_90 ;
V_84 -> V_95 = V_84 -> V_95 + V_82 -> V_93 ;
V_84 -> V_94 = V_82 -> V_91 + V_82 -> V_93 ;
return 0 ;
} else
return - V_90 ;
}
int
F_38 ( struct V_74 * V_75 ,
struct V_97 * V_98 , T_9 V_99 )
{
struct V_100 * V_101 = F_39 ( V_75 ) ;
int V_48 , V_64 = - V_90 ;
T_10 V_102 ;
struct V_81 * V_82 = NULL , * V_103 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
T_1 * V_110 ;
struct V_83 V_84 = {
. V_85 = V_98 -> V_111 . V_112 ,
. V_92 = V_98 -> V_111 . V_46 >> V_6 ,
. V_95 = V_98 -> V_111 . V_46 >> V_6 ,
. V_94 = V_98 -> V_111 . V_46 >> V_6 ,
} ;
F_40 ( V_113 ) ;
F_5 ( L_13 , V_5 ) ;
V_109 = F_41 ( V_99 ) ;
if ( ! V_109 )
return - V_57 ;
F_42 ( & V_105 , & V_107 , V_98 -> V_114 -> V_59 , V_98 -> V_114 -> V_47 ) ;
F_43 ( & V_105 , F_23 ( V_109 ) , V_115 ) ;
V_110 = F_44 ( & V_105 , 4 ) ;
if ( F_45 ( ! V_110 ) )
goto V_116;
V_102 = F_46 ( V_110 ++ ) ;
F_5 ( L_14 , V_5 , V_102 ) ;
V_110 = F_44 ( & V_105 , ( 28 + V_80 ) * V_102 ) ;
if ( F_45 ( ! V_110 ) )
goto V_116;
for ( V_48 = 0 ; V_48 < V_102 ; V_48 ++ ) {
V_82 = F_47 () ;
if ( ! V_82 ) {
V_64 = - V_57 ;
goto V_116;
}
memcpy ( & V_82 -> V_117 , V_110 , V_80 ) ;
V_110 += F_48 ( V_80 ) ;
V_82 -> V_118 = F_32 ( V_75 , & V_82 -> V_117 ) ;
if ( ! V_82 -> V_118 )
goto V_116;
if ( F_1 ( & V_110 , & V_82 -> V_91 ) < 0 )
goto V_116;
if ( F_1 ( & V_110 , & V_82 -> V_93 ) < 0 )
goto V_116;
if ( F_1 ( & V_110 , & V_82 -> V_119 ) < 0 )
goto V_116;
V_82 -> V_87 = F_46 ( V_110 ++ ) ;
if ( V_82 -> V_87 == V_89 )
V_82 -> V_120 = & V_101 -> V_121 ;
if ( F_37 ( V_82 , & V_84 ) ) {
F_5 ( L_15 , V_5 ) ;
goto V_116;
}
F_49 ( & V_82 -> V_122 , & V_113 ) ;
}
if ( V_98 -> V_111 . V_46 + V_98 -> V_111 . V_123 !=
V_84 . V_92 << V_6 ) {
F_5 ( L_16 , V_5 ) ;
V_82 = NULL ;
goto V_116;
}
if ( V_84 . V_92 < V_84 . V_94 ) {
F_5 ( L_17 , V_5 ) ;
V_82 = NULL ;
goto V_116;
}
F_34 ( & V_101 -> V_124 ) ;
F_50 (be, save, &extents, be_node) {
F_51 ( & V_82 -> V_122 ) ;
V_64 = F_52 ( V_101 , V_82 ) ;
if ( V_64 ) {
F_36 ( & V_101 -> V_124 ) ;
V_82 = NULL ;
goto V_116;
}
}
F_36 ( & V_101 -> V_124 ) ;
V_64 = 0 ;
V_58:
F_53 ( V_109 ) ;
F_5 ( L_18 , V_5 , V_64 ) ;
return V_64 ;
V_116:
F_54 ( V_82 ) ;
while ( ! F_55 ( & V_113 ) ) {
V_82 = F_56 ( & V_113 , struct V_81 ,
V_122 ) ;
F_51 ( & V_82 -> V_122 ) ;
F_54 ( V_82 ) ;
}
goto V_58;
}
