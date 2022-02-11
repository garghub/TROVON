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
if ( V_17 != sizeof ( struct V_18 ) )
return - V_19 ;
if ( F_14 ( & V_20 , V_16 , V_17 ) != 0 )
return - V_21 ;
F_15 ( & V_22 ) ;
return V_17 ;
}
void F_16 ( struct V_23 * V_24 )
{
if ( V_24 -> V_25 >= 0 )
return;
F_15 ( & V_22 ) ;
}
struct V_26 *
F_17 ( struct V_27 * V_28 ,
struct V_29 * V_8 )
{
struct V_26 * V_30 ;
struct V_7 * V_9 = NULL ;
struct V_23 V_24 ;
struct V_31 V_32 = {
. type = V_33 ,
. V_34 = V_8 -> V_35 ,
} ;
T_8 * V_36 ;
F_18 ( V_37 , V_38 ) ;
struct V_18 * V_39 = & V_20 ;
int V_40 , V_41 , V_42 , V_43 ;
F_5 ( L_5 , V_5 ) ;
F_5 ( L_6 , V_5 , V_8 -> V_44 . V_45 ,
V_8 -> V_35 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_45 = F_19 ( sizeof( V_32 ) + V_8 -> V_35 , V_46 ) ;
if ( ! V_24 . V_45 ) {
V_30 = F_20 ( - V_47 ) ;
goto V_48;
}
memcpy ( V_24 . V_45 , & V_32 , sizeof( V_32 ) ) ;
V_36 = ( T_8 * ) V_24 . V_45 ;
V_41 = V_8 -> V_35 ;
V_40 = sizeof( V_32 ) ;
for ( V_42 = 0 ; V_41 > 0 ; V_42 ++ ) {
memcpy ( & V_36 [ V_40 ] , F_21 ( V_8 -> V_49 [ V_42 ] ) ,
V_41 < V_50 ? V_41 : V_50 ) ;
V_41 -= V_50 ;
V_40 += V_50 ;
}
V_24 . V_41 = sizeof( V_32 ) + V_8 -> V_35 ;
F_5 ( L_7 , V_5 ) ;
F_22 ( & V_22 , & V_37 ) ;
V_43 = F_23 ( V_51 -> V_52 , & V_24 ) ;
if ( V_43 < 0 ) {
F_24 ( & V_22 , & V_37 ) ;
V_30 = F_20 ( V_43 ) ;
goto V_48;
}
F_25 ( V_53 ) ;
F_26 () ;
F_27 ( V_54 ) ;
F_24 ( & V_22 , & V_37 ) ;
if ( V_39 -> V_55 != V_56 ) {
F_5 ( L_8 ,
V_5 , V_39 -> V_55 ) ;
V_30 = F_20 ( - V_19 ) ;
goto V_48;
}
V_9 = F_4 ( F_28 ( V_39 -> V_57 , V_39 -> V_58 ) ) ;
if ( F_7 ( V_9 ) ) {
V_43 = F_8 ( V_9 ) ;
F_5 ( L_9 , V_5 , V_43 ) ;
V_30 = F_20 ( V_43 ) ;
goto V_48;
}
V_30 = F_19 ( sizeof( * V_30 ) , V_46 ) ;
if ( ! V_30 ) {
V_30 = F_20 ( - V_47 ) ;
goto V_48;
}
V_30 -> V_59 = V_9 ;
memcpy ( & V_30 -> V_60 , & V_8 -> V_44 , sizeof( struct V_61 ) ) ;
F_5 ( L_10 ,
V_5 ,
V_9 -> V_62 -> V_63 ,
V_9 -> V_64 ) ;
V_48:
F_29 ( V_24 . V_45 ) ;
return V_30 ;
}
static struct V_7 * F_30 ( struct V_65 * V_66 ,
struct V_61 * V_67 )
{
struct V_7 * V_30 = NULL ;
struct V_68 * V_69 ;
struct V_26 * V_8 ;
F_5 ( L_11 , V_5 , V_66 , V_67 ) ;
V_69 = F_31 ( V_66 ) ;
F_32 ( & V_69 -> V_70 ) ;
F_33 (dev, &mid->bm_devlist, bm_node) {
if ( memcmp ( V_67 -> V_45 , V_8 -> V_60 . V_45 ,
V_71 ) == 0 ) {
V_30 = V_8 -> V_59 ;
goto V_48;
}
}
V_48:
F_34 ( & V_69 -> V_70 ) ;
F_5 ( L_12 , V_5 , V_30 ) ;
return V_30 ;
}
static int F_35 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_76 == V_77 ) {
if ( V_73 -> V_78 == V_79 ||
V_73 -> V_78 == V_80 )
return - V_81 ;
if ( V_73 -> V_82 != V_75 -> V_83 )
return - V_81 ;
V_75 -> V_83 += V_73 -> V_84 ;
return 0 ;
}
if ( V_73 -> V_78 == V_79 ) {
if ( V_73 -> V_82 != V_75 -> V_83 )
return - V_81 ;
if ( V_75 -> V_85 > V_75 -> V_83 )
return - V_81 ;
V_75 -> V_83 += V_73 -> V_84 ;
V_75 -> V_86 = V_75 -> V_83 ;
return 0 ;
} else if ( V_73 -> V_78 == V_80 ) {
if ( V_73 -> V_82 != V_75 -> V_83 )
return - V_81 ;
V_75 -> V_83 += V_73 -> V_84 ;
return 0 ;
} else if ( V_73 -> V_78 == V_87 ) {
if ( V_73 -> V_82 > V_75 -> V_83 )
return - V_81 ;
if ( V_73 -> V_82 < V_75 -> V_86 )
return - V_81 ;
if ( V_73 -> V_82 < V_75 -> V_85 )
return - V_81 ;
V_75 -> V_86 = V_75 -> V_86 + V_73 -> V_84 ;
V_75 -> V_85 = V_73 -> V_82 + V_73 -> V_84 ;
return 0 ;
} else
return - V_81 ;
}
int
F_36 ( struct V_65 * V_66 ,
struct V_88 * V_89 , T_9 V_90 )
{
struct V_91 * V_92 = F_37 ( V_66 ) ;
int V_42 , V_55 = - V_81 ;
T_10 V_93 ;
struct V_72 * V_73 = NULL , * V_94 ;
struct V_95 V_96 ;
struct V_97 V_98 ;
struct V_99 * V_100 ;
T_1 * V_101 ;
struct V_74 V_75 = {
. V_76 = V_89 -> V_102 . V_103 ,
. V_83 = V_89 -> V_102 . V_40 >> V_6 ,
. V_86 = V_89 -> V_102 . V_40 >> V_6 ,
. V_85 = V_89 -> V_102 . V_40 >> V_6 ,
} ;
F_38 ( V_104 ) ;
F_5 ( L_13 , V_5 ) ;
V_100 = F_39 ( V_90 ) ;
if ( ! V_100 )
return - V_47 ;
F_40 ( & V_96 , & V_98 , V_89 -> V_105 -> V_49 , V_89 -> V_105 -> V_41 ) ;
F_41 ( & V_96 , F_21 ( V_100 ) , V_106 ) ;
V_101 = F_42 ( & V_96 , 4 ) ;
if ( F_43 ( ! V_101 ) )
goto V_107;
V_93 = F_44 ( V_101 ++ ) ;
F_5 ( L_14 , V_5 , V_93 ) ;
V_101 = F_42 ( & V_96 , ( 28 + V_71 ) * V_93 ) ;
if ( F_43 ( ! V_101 ) )
goto V_107;
for ( V_42 = 0 ; V_42 < V_93 ; V_42 ++ ) {
V_73 = F_45 () ;
if ( ! V_73 ) {
V_55 = - V_47 ;
goto V_107;
}
memcpy ( & V_73 -> V_108 , V_101 , V_71 ) ;
V_101 += F_46 ( V_71 ) ;
V_73 -> V_109 = F_30 ( V_66 , & V_73 -> V_108 ) ;
if ( ! V_73 -> V_109 )
goto V_107;
if ( F_1 ( & V_101 , & V_73 -> V_82 ) < 0 )
goto V_107;
if ( F_1 ( & V_101 , & V_73 -> V_84 ) < 0 )
goto V_107;
if ( F_1 ( & V_101 , & V_73 -> V_110 ) < 0 )
goto V_107;
V_73 -> V_78 = F_44 ( V_101 ++ ) ;
if ( V_73 -> V_78 == V_80 )
V_73 -> V_111 = & V_92 -> V_112 ;
if ( F_35 ( V_73 , & V_75 ) ) {
F_5 ( L_15 , V_5 ) ;
goto V_107;
}
F_47 ( & V_73 -> V_113 , & V_104 ) ;
}
if ( V_89 -> V_102 . V_40 + V_89 -> V_102 . V_114 !=
V_75 . V_83 << V_6 ) {
F_5 ( L_16 , V_5 ) ;
V_73 = NULL ;
goto V_107;
}
if ( V_75 . V_83 < V_75 . V_85 ) {
F_5 ( L_17 , V_5 ) ;
V_73 = NULL ;
goto V_107;
}
F_32 ( & V_92 -> V_115 ) ;
F_48 (be, save, &extents, be_node) {
F_49 ( & V_73 -> V_113 ) ;
V_55 = F_50 ( V_92 , V_73 ) ;
if ( V_55 ) {
F_34 ( & V_92 -> V_115 ) ;
V_73 = NULL ;
goto V_107;
}
}
F_34 ( & V_92 -> V_115 ) ;
V_55 = 0 ;
V_48:
F_51 ( V_100 ) ;
F_5 ( L_18 , V_5 , V_55 ) ;
return V_55 ;
V_107:
F_52 ( V_73 ) ;
while ( ! F_53 ( & V_104 ) ) {
V_73 = F_54 ( & V_104 , struct V_72 ,
V_113 ) ;
F_49 ( & V_73 -> V_113 ) ;
F_52 ( V_73 ) ;
}
goto V_48;
}
