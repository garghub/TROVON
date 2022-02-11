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
T_5 F_13 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char T_6 * V_18 , T_7 V_19 )
{
char * V_20 = ( char * ) V_17 -> V_20 + V_17 -> V_21 ;
T_7 V_22 = F_14 ( V_17 -> V_23 - V_17 -> V_21 , V_19 ) ;
unsigned long V_24 ;
V_24 = F_15 ( V_18 , V_20 , V_22 ) ;
if ( V_24 == V_22 ) {
V_17 -> V_25 = - V_26 ;
return - V_26 ;
}
V_22 -= V_24 ;
V_17 -> V_21 += V_22 ;
V_17 -> V_25 = 0 ;
return V_22 ;
}
T_5 F_16 ( struct V_14 * V_15 , const char T_6 * V_27 ,
T_7 V_22 )
{
if ( V_22 != sizeof ( struct V_28 ) )
return - V_29 ;
if ( F_17 ( & V_30 , V_27 , V_22 ) != 0 )
return - V_26 ;
F_18 ( & V_31 ) ;
return V_22 ;
}
void F_19 ( struct V_16 * V_17 )
{
if ( V_17 -> V_25 >= 0 )
return;
F_18 ( & V_31 ) ;
}
struct V_32 *
F_20 ( struct V_33 * V_34 ,
struct V_35 * V_8 )
{
struct V_32 * V_36 = NULL ;
struct V_7 * V_9 = NULL ;
struct V_16 V_17 ;
struct V_37 V_38 = {
. type = V_39 ,
. V_40 = V_8 -> V_41 ,
} ;
T_8 * V_42 ;
F_21 ( V_43 , V_44 ) ;
struct V_28 * V_45 = & V_30 ;
int V_46 , V_23 , V_47 ;
F_5 ( L_5 , V_5 ) ;
F_5 ( L_6 , V_5 , V_8 -> V_48 . V_20 ,
V_8 -> V_41 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_20 = F_22 ( sizeof( V_38 ) + V_8 -> V_41 , V_49 ) ;
if ( ! V_17 . V_20 ) {
V_36 = F_23 ( - V_50 ) ;
goto V_51;
}
memcpy ( V_17 . V_20 , & V_38 , sizeof( V_38 ) ) ;
V_42 = ( T_8 * ) V_17 . V_20 ;
V_23 = V_8 -> V_41 ;
V_46 = sizeof( V_38 ) ;
for ( V_47 = 0 ; V_23 > 0 ; V_47 ++ ) {
memcpy ( & V_42 [ V_46 ] , F_24 ( V_8 -> V_52 [ V_47 ] ) ,
V_23 < V_53 ? V_23 : V_53 ) ;
V_23 -= V_53 ;
V_46 += V_53 ;
}
V_17 . V_23 = sizeof( V_38 ) + V_8 -> V_41 ;
F_5 ( L_7 , V_5 ) ;
F_25 ( & V_31 , & V_43 ) ;
if ( F_26 ( V_54 -> V_55 , & V_17 ) < 0 ) {
F_27 ( & V_31 , & V_43 ) ;
goto V_51;
}
F_28 ( V_56 ) ;
F_29 () ;
F_30 ( V_57 ) ;
F_27 ( & V_31 , & V_43 ) ;
if ( V_45 -> V_58 != V_59 ) {
F_5 ( L_8 ,
V_5 , V_45 -> V_58 ) ;
V_36 = F_23 ( - V_29 ) ;
goto V_51;
}
V_9 = F_4 ( F_31 ( V_45 -> V_60 , V_45 -> V_61 ) ) ;
if ( F_7 ( V_9 ) ) {
F_5 ( L_3 ,
V_5 , F_8 ( V_9 ) ) ;
goto V_51;
}
V_36 = F_22 ( sizeof( * V_36 ) , V_49 ) ;
if ( ! V_36 ) {
V_36 = F_23 ( - V_50 ) ;
goto V_51;
}
V_36 -> V_62 = V_9 ;
memcpy ( & V_36 -> V_63 , & V_8 -> V_48 , sizeof( struct V_64 ) ) ;
F_5 ( L_9 ,
V_5 ,
V_9 -> V_65 -> V_66 ,
V_9 -> V_67 ) ;
V_51:
F_32 ( V_17 . V_20 ) ;
return V_36 ;
}
static struct V_7 * F_33 ( struct V_68 * V_69 ,
struct V_64 * V_70 )
{
struct V_7 * V_36 = NULL ;
struct V_71 * V_72 ;
struct V_32 * V_8 ;
F_5 ( L_10 , V_5 , V_69 , V_70 ) ;
V_72 = F_34 ( V_69 ) ;
F_35 ( & V_72 -> V_73 ) ;
F_36 (dev, &mid->bm_devlist, bm_node) {
if ( memcmp ( V_70 -> V_20 , V_8 -> V_63 . V_20 ,
V_74 ) == 0 ) {
V_36 = V_8 -> V_62 ;
goto V_51;
}
}
V_51:
F_37 ( & V_72 -> V_73 ) ;
F_5 ( L_11 , V_5 , V_36 ) ;
return V_36 ;
}
static int F_38 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_79 == V_80 ) {
if ( V_76 -> V_81 == V_82 ||
V_76 -> V_81 == V_83 )
return - V_84 ;
if ( V_76 -> V_85 != V_78 -> V_86 )
return - V_84 ;
V_78 -> V_86 += V_76 -> V_87 ;
return 0 ;
}
if ( V_76 -> V_81 == V_82 ) {
if ( V_76 -> V_85 != V_78 -> V_86 )
return - V_84 ;
if ( V_78 -> V_88 > V_78 -> V_86 )
return - V_84 ;
V_78 -> V_86 += V_76 -> V_87 ;
V_78 -> V_89 = V_78 -> V_86 ;
return 0 ;
} else if ( V_76 -> V_81 == V_83 ) {
if ( V_76 -> V_85 != V_78 -> V_86 )
return - V_84 ;
V_78 -> V_86 += V_76 -> V_87 ;
return 0 ;
} else if ( V_76 -> V_81 == V_90 ) {
if ( V_76 -> V_85 > V_78 -> V_86 )
return - V_84 ;
if ( V_76 -> V_85 < V_78 -> V_89 )
return - V_84 ;
if ( V_76 -> V_85 < V_78 -> V_88 )
return - V_84 ;
V_78 -> V_89 = V_78 -> V_89 + V_76 -> V_87 ;
V_78 -> V_88 = V_76 -> V_85 + V_76 -> V_87 ;
return 0 ;
} else
return - V_84 ;
}
int
F_39 ( struct V_68 * V_69 ,
struct V_91 * V_92 , T_9 V_93 )
{
struct V_94 * V_95 = F_40 ( V_69 ) ;
int V_47 , V_58 = - V_84 ;
T_10 V_96 ;
struct V_75 * V_76 = NULL , * V_97 ;
struct V_98 V_99 ;
struct V_100 V_101 ;
struct V_102 * V_103 ;
T_1 * V_104 ;
struct V_77 V_78 = {
. V_79 = V_92 -> V_105 . V_106 ,
. V_86 = V_92 -> V_105 . V_46 >> V_6 ,
. V_89 = V_92 -> V_105 . V_46 >> V_6 ,
. V_88 = V_92 -> V_105 . V_46 >> V_6 ,
} ;
F_41 ( V_107 ) ;
F_5 ( L_12 , V_5 ) ;
V_103 = F_42 ( V_93 ) ;
if ( ! V_103 )
return - V_50 ;
F_43 ( & V_99 , & V_101 , V_92 -> V_108 -> V_52 , V_92 -> V_108 -> V_23 ) ;
F_44 ( & V_99 , F_24 ( V_103 ) , V_109 ) ;
V_104 = F_45 ( & V_99 , 4 ) ;
if ( F_46 ( ! V_104 ) )
goto V_110;
V_96 = F_47 ( V_104 ++ ) ;
F_5 ( L_13 , V_5 , V_96 ) ;
V_104 = F_45 ( & V_99 , ( 28 + V_74 ) * V_96 ) ;
if ( F_46 ( ! V_104 ) )
goto V_110;
for ( V_47 = 0 ; V_47 < V_96 ; V_47 ++ ) {
V_76 = F_48 () ;
if ( ! V_76 ) {
V_58 = - V_50 ;
goto V_110;
}
memcpy ( & V_76 -> V_111 , V_104 , V_74 ) ;
V_104 += F_49 ( V_74 ) ;
V_76 -> V_112 = F_33 ( V_69 , & V_76 -> V_111 ) ;
if ( ! V_76 -> V_112 )
goto V_110;
if ( F_1 ( & V_104 , & V_76 -> V_85 ) < 0 )
goto V_110;
if ( F_1 ( & V_104 , & V_76 -> V_87 ) < 0 )
goto V_110;
if ( F_1 ( & V_104 , & V_76 -> V_113 ) < 0 )
goto V_110;
V_76 -> V_81 = F_47 ( V_104 ++ ) ;
if ( V_76 -> V_81 == V_83 )
V_76 -> V_114 = & V_95 -> V_115 ;
if ( F_38 ( V_76 , & V_78 ) ) {
F_5 ( L_14 , V_5 ) ;
goto V_110;
}
F_50 ( & V_76 -> V_116 , & V_107 ) ;
}
if ( V_92 -> V_105 . V_46 + V_92 -> V_105 . V_117 !=
V_78 . V_86 << V_6 ) {
F_5 ( L_15 , V_5 ) ;
V_76 = NULL ;
goto V_110;
}
if ( V_78 . V_86 < V_78 . V_88 ) {
F_5 ( L_16 , V_5 ) ;
V_76 = NULL ;
goto V_110;
}
F_35 ( & V_95 -> V_118 ) ;
F_51 (be, save, &extents, be_node) {
F_52 ( & V_76 -> V_116 ) ;
V_58 = F_53 ( V_95 , V_76 ) ;
if ( V_58 ) {
F_37 ( & V_95 -> V_118 ) ;
V_76 = NULL ;
goto V_110;
}
}
F_37 ( & V_95 -> V_118 ) ;
V_58 = 0 ;
V_51:
F_54 ( V_103 ) ;
F_5 ( L_17 , V_5 , V_58 ) ;
return V_58 ;
V_110:
F_55 ( V_76 ) ;
while ( ! F_56 ( & V_107 ) ) {
V_76 = F_57 ( & V_107 , struct V_75 ,
V_116 ) ;
F_52 ( & V_76 -> V_116 ) ;
F_55 ( V_76 ) ;
}
goto V_51;
}
