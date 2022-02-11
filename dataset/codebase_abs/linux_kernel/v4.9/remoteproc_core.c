static const char * F_1 ( enum V_1 type )
{
if ( type < F_2 ( V_2 ) )
return V_2 [ type ] ;
return L_1 ;
}
static int F_3 ( struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned long V_7 , int V_8 , void * V_9 )
{
struct V_10 * V_10 = V_9 ;
F_4 ( V_6 , L_2 , V_7 , V_8 ) ;
F_5 ( V_10 , V_11 ) ;
return - V_12 ;
}
static int F_6 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_10 -> V_6 . V_13 ;
int V_14 ;
if ( ! V_10 -> V_15 ) {
F_7 ( V_6 , L_3 ) ;
return 0 ;
}
V_4 = F_8 ( V_6 -> V_16 ) ;
if ( ! V_4 ) {
F_4 ( V_6 , L_4 ) ;
return - V_17 ;
}
F_9 ( V_4 , F_3 , V_10 ) ;
V_14 = F_10 ( V_4 , V_6 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_5 , V_14 ) ;
goto V_18;
}
V_10 -> V_4 = V_4 ;
return 0 ;
V_18:
F_11 ( V_4 ) ;
return V_14 ;
}
static void F_12 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_4 ;
struct V_5 * V_6 = V_10 -> V_6 . V_13 ;
if ( ! V_4 )
return;
F_13 ( V_4 , V_6 ) ;
F_11 ( V_4 ) ;
}
void * F_14 ( struct V_10 * V_10 , T_1 V_19 , int V_20 )
{
struct V_21 * V_22 ;
void * V_23 = NULL ;
if ( V_10 -> V_24 -> V_25 ) {
V_23 = V_10 -> V_24 -> V_25 ( V_10 , V_19 , V_20 ) ;
if ( V_23 )
goto V_26;
}
F_15 (carveout, &rproc->carveouts, node) {
int V_27 = V_19 - V_22 -> V_19 ;
if ( V_27 < 0 )
continue;
if ( V_27 + V_20 > V_22 -> V_20 )
continue;
V_23 = V_22 -> V_28 + V_27 ;
break;
}
V_26:
return V_23 ;
}
int F_16 ( struct V_29 * V_30 , int V_31 )
{
struct V_10 * V_10 = V_30 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_32 * V_33 = & V_30 -> V_34 [ V_31 ] ;
struct V_35 * V_36 ;
T_2 V_37 ;
void * V_28 ;
int V_14 , V_38 , V_39 ;
V_38 = F_17 ( F_18 ( V_33 -> V_20 , V_33 -> V_40 ) ) ;
V_28 = F_19 ( V_6 -> V_13 , V_38 , & V_37 , V_41 ) ;
if ( ! V_28 ) {
F_4 ( V_6 -> V_13 , L_6 ) ;
return - V_42 ;
}
V_14 = F_20 ( & V_10 -> V_43 , V_33 , 0 , 0 , V_41 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_7 , V_14 ) ;
F_21 ( V_6 -> V_13 , V_38 , V_28 , V_37 ) ;
return V_14 ;
}
V_39 = V_14 ;
F_7 ( V_6 , L_8 ,
V_31 , V_28 , & V_37 , V_38 , V_39 ) ;
V_33 -> V_28 = V_28 ;
V_33 -> V_37 = V_37 ;
V_33 -> V_39 = V_39 ;
V_36 = ( void * ) V_10 -> V_44 + V_30 -> V_45 ;
V_36 -> V_34 [ V_31 ] . V_19 = V_37 ;
V_36 -> V_34 [ V_31 ] . V_39 = V_39 ;
return 0 ;
}
static int
F_22 ( struct V_29 * V_30 , struct V_35 * V_36 , int V_31 )
{
struct V_10 * V_10 = V_30 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_46 * V_34 = & V_36 -> V_34 [ V_31 ] ;
struct V_32 * V_33 = & V_30 -> V_34 [ V_31 ] ;
F_7 ( V_6 , L_9 ,
V_31 , V_34 -> V_19 , V_34 -> V_47 , V_34 -> V_40 ) ;
if ( ! V_34 -> V_47 || ! V_34 -> V_40 ) {
F_4 ( V_6 , L_10 ,
V_34 -> V_47 , V_34 -> V_40 ) ;
return - V_42 ;
}
V_33 -> V_20 = V_34 -> V_47 ;
V_33 -> V_40 = V_34 -> V_40 ;
V_33 -> V_30 = V_30 ;
return 0 ;
}
void F_23 ( struct V_32 * V_33 )
{
int V_38 = F_17 ( F_18 ( V_33 -> V_20 , V_33 -> V_40 ) ) ;
struct V_10 * V_10 = V_33 -> V_30 -> V_10 ;
int V_48 = V_33 -> V_30 -> V_34 - V_33 ;
struct V_35 * V_36 ;
F_21 ( V_10 -> V_6 . V_13 , V_38 , V_33 -> V_28 , V_33 -> V_37 ) ;
F_24 ( & V_10 -> V_43 , V_33 -> V_39 ) ;
V_36 = ( void * ) V_10 -> V_44 + V_33 -> V_30 -> V_45 ;
V_36 -> V_34 [ V_48 ] . V_19 = 0 ;
V_36 -> V_34 [ V_48 ] . V_39 = - 1 ;
}
static int F_25 ( struct V_10 * V_10 , struct V_35 * V_36 ,
int V_27 , int V_49 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_29 * V_30 ;
int V_31 , V_14 ;
if ( sizeof( * V_36 ) + V_36 -> V_50 * sizeof( struct V_46 )
+ V_36 -> V_51 > V_49 ) {
F_4 ( V_6 , L_11 ) ;
return - V_42 ;
}
if ( V_36 -> V_52 [ 0 ] || V_36 -> V_52 [ 1 ] ) {
F_4 ( V_6 , L_12 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_13 ,
V_36 -> V_53 , V_36 -> V_54 , V_36 -> V_51 , V_36 -> V_50 ) ;
if ( V_36 -> V_50 > F_2 ( V_30 -> V_34 ) ) {
F_4 ( V_6 , L_14 , V_36 -> V_50 ) ;
return - V_42 ;
}
V_30 = F_26 ( sizeof( * V_30 ) , V_41 ) ;
if ( ! V_30 )
return - V_17 ;
V_30 -> V_10 = V_10 ;
for ( V_31 = 0 ; V_31 < V_36 -> V_50 ; V_31 ++ ) {
V_14 = F_22 ( V_30 , V_36 , V_31 ) ;
if ( V_14 )
goto V_55;
}
V_30 -> V_45 = V_27 ;
F_27 ( & V_30 -> V_56 , & V_10 -> V_57 ) ;
V_14 = F_28 ( V_30 , V_36 -> V_53 ) ;
if ( V_14 )
goto V_58;
return 0 ;
V_58:
F_29 ( & V_30 -> V_56 ) ;
V_55:
F_30 ( V_30 ) ;
return V_14 ;
}
static int F_31 ( struct V_10 * V_10 , struct V_59 * V_36 ,
int V_27 , int V_49 )
{
struct V_21 * V_60 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_23 ;
char V_61 [ 15 ] ;
if ( sizeof( * V_36 ) > V_49 ) {
F_4 ( V_6 , L_15 ) ;
return - V_42 ;
}
if ( V_36 -> V_52 ) {
F_4 ( V_6 , L_16 ) ;
return - V_42 ;
}
V_23 = F_14 ( V_10 , V_36 -> V_19 , V_36 -> V_20 ) ;
if ( ! V_23 ) {
F_4 ( V_6 , L_17 ) ;
return - V_42 ;
}
V_60 = F_26 ( sizeof( * V_60 ) , V_41 ) ;
if ( ! V_60 )
return - V_17 ;
V_60 -> V_20 = V_36 -> V_20 ;
V_60 -> V_28 = V_23 ;
snprintf ( V_61 , sizeof( V_61 ) , L_18 , V_10 -> V_62 ) ;
V_60 -> V_63 = F_32 ( V_61 , V_10 , V_60 ) ;
if ( ! V_60 -> V_63 ) {
V_60 -> V_28 = NULL ;
F_30 ( V_60 ) ;
return - V_42 ;
}
F_27 ( & V_60 -> V_56 , & V_10 -> V_64 ) ;
V_10 -> V_62 ++ ;
F_7 ( V_6 , L_19 ,
V_61 , V_23 , V_36 -> V_19 , V_36 -> V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_10 , struct V_65 * V_36 ,
int V_27 , int V_49 )
{
struct V_21 * V_66 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_42 ;
if ( sizeof( * V_36 ) > V_49 ) {
F_4 ( V_6 , L_20 ) ;
return - V_42 ;
}
if ( V_36 -> V_52 ) {
F_4 ( V_6 , L_21 ) ;
return - V_42 ;
}
V_66 = F_26 ( sizeof( * V_66 ) , V_41 ) ;
if ( ! V_66 )
return - V_17 ;
V_14 = F_34 ( V_10 -> V_4 , V_36 -> V_19 , V_36 -> V_67 , V_36 -> V_20 , V_36 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_22 , V_14 ) ;
goto V_26;
}
V_66 -> V_19 = V_36 -> V_19 ;
V_66 -> V_20 = V_36 -> V_20 ;
F_27 ( & V_66 -> V_56 , & V_10 -> V_68 ) ;
F_7 ( V_6 , L_23 ,
V_36 -> V_67 , V_36 -> V_19 , V_36 -> V_20 ) ;
return 0 ;
V_26:
F_30 ( V_66 ) ;
return V_14 ;
}
static int F_35 ( struct V_10 * V_10 ,
struct V_69 * V_36 ,
int V_27 , int V_49 )
{
struct V_21 * V_22 , * V_66 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_37 ;
void * V_28 ;
int V_14 ;
if ( sizeof( * V_36 ) > V_49 ) {
F_4 ( V_6 , L_24 ) ;
return - V_42 ;
}
if ( V_36 -> V_52 ) {
F_4 ( V_6 , L_25 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_26 ,
V_36 -> V_61 , V_36 -> V_19 , V_36 -> V_67 , V_36 -> V_20 , V_36 -> V_8 ) ;
V_22 = F_26 ( sizeof( * V_22 ) , V_41 ) ;
if ( ! V_22 )
return - V_17 ;
V_28 = F_19 ( V_6 -> V_13 , V_36 -> V_20 , & V_37 , V_41 ) ;
if ( ! V_28 ) {
F_4 ( V_6 -> V_13 ,
L_27 , V_36 -> V_20 ) ;
V_14 = - V_17 ;
goto V_70;
}
F_7 ( V_6 , L_28 ,
V_28 , & V_37 , V_36 -> V_20 ) ;
if ( V_10 -> V_4 ) {
V_66 = F_26 ( sizeof( * V_66 ) , V_41 ) ;
if ( ! V_66 ) {
V_14 = - V_17 ;
goto V_71;
}
V_14 = F_34 ( V_10 -> V_4 , V_36 -> V_19 , V_37 , V_36 -> V_20 ,
V_36 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_29 , V_14 ) ;
goto V_72;
}
V_66 -> V_19 = V_36 -> V_19 ;
V_66 -> V_20 = V_36 -> V_20 ;
F_27 ( & V_66 -> V_56 , & V_10 -> V_68 ) ;
F_7 ( V_6 , L_30 ,
V_36 -> V_19 , & V_37 ) ;
}
V_36 -> V_67 = V_37 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_20 = V_36 -> V_20 ;
V_22 -> V_37 = V_37 ;
V_22 -> V_19 = V_36 -> V_19 ;
F_27 ( & V_22 -> V_56 , & V_10 -> V_73 ) ;
return 0 ;
V_72:
F_30 ( V_66 ) ;
V_71:
F_21 ( V_6 -> V_13 , V_36 -> V_20 , V_28 , V_37 ) ;
V_70:
F_30 ( V_22 ) ;
return V_14 ;
}
static int F_36 ( struct V_10 * V_10 , struct V_35 * V_36 ,
int V_27 , int V_49 )
{
V_10 -> V_74 += V_36 -> V_50 ;
return 0 ;
}
static int F_37 ( struct V_10 * V_10 , int V_20 ,
T_3 V_75 [ V_76 ] )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_77 ;
int V_14 = 0 , V_31 ;
for ( V_31 = 0 ; V_31 < V_10 -> V_44 -> V_47 ; V_31 ++ ) {
int V_27 = V_10 -> V_44 -> V_27 [ V_31 ] ;
struct V_78 * V_79 = ( void * ) V_10 -> V_44 + V_27 ;
int V_49 = V_20 - V_27 - sizeof( * V_79 ) ;
void * V_36 = ( void * ) V_79 + sizeof( * V_79 ) ;
if ( V_49 < 0 ) {
F_4 ( V_6 , L_31 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_32 , V_79 -> type ) ;
if ( V_79 -> type >= V_76 ) {
F_38 ( V_6 , L_33 , V_79 -> type ) ;
continue;
}
V_77 = V_75 [ V_79 -> type ] ;
if ( ! V_77 )
continue;
V_14 = V_77 ( V_10 , V_36 , V_27 + sizeof( * V_79 ) , V_49 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static void F_39 ( struct V_10 * V_10 )
{
struct V_21 * V_80 , * V_81 ;
struct V_29 * V_30 , * V_82 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_40 (entry, tmp, &rproc->traces, node) {
F_41 ( V_80 -> V_63 ) ;
V_10 -> V_62 -- ;
F_29 ( & V_80 -> V_56 ) ;
F_30 ( V_80 ) ;
}
F_40 (entry, tmp, &rproc->mappings, node) {
T_4 V_83 ;
V_83 = F_42 ( V_10 -> V_4 , V_80 -> V_19 , V_80 -> V_20 ) ;
if ( V_83 != V_80 -> V_20 ) {
F_4 ( V_6 , L_34 , V_80 -> V_20 ,
V_83 ) ;
}
F_29 ( & V_80 -> V_56 ) ;
F_30 ( V_80 ) ;
}
F_40 (entry, tmp, &rproc->carveouts, node) {
F_21 ( V_6 -> V_13 , V_80 -> V_20 , V_80 -> V_28 ,
V_80 -> V_37 ) ;
F_29 ( & V_80 -> V_56 ) ;
F_30 ( V_80 ) ;
}
F_40 (rvdev, rvtmp, &rproc->rvdevs, node)
F_43 ( V_30 ) ;
}
static int F_44 ( struct V_10 * V_10 , const struct V_84 * V_85 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_61 = V_10 -> V_84 ;
struct V_86 * V_87 , * V_88 ;
int V_14 , V_89 ;
V_14 = F_45 ( V_10 , V_85 ) ;
if ( V_14 )
return V_14 ;
F_46 ( V_6 , L_35 , V_61 , V_85 -> V_38 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_36 , V_14 ) ;
return V_14 ;
}
V_10 -> V_90 = F_47 ( V_10 , V_85 ) ;
V_14 = - V_42 ;
V_87 = F_48 ( V_10 , V_85 , & V_89 ) ;
if ( ! V_87 ) {
F_4 ( V_6 , L_37 ) ;
goto V_91;
}
V_10 -> V_92 = F_49 ( V_87 , V_89 , V_41 ) ;
if ( ! V_10 -> V_92 )
goto V_91;
V_10 -> V_44 = V_10 -> V_92 ;
V_10 -> V_74 = - 1 ;
V_14 = F_37 ( V_10 , V_89 , V_93 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_38 , V_14 ) ;
goto V_91;
}
V_14 = F_37 ( V_10 , V_89 , V_94 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_39 , V_14 ) ;
goto V_95;
}
V_14 = F_50 ( V_10 , V_85 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_40 , V_14 ) ;
goto V_95;
}
V_88 = F_51 ( V_10 , V_85 ) ;
if ( V_88 ) {
memcpy ( V_88 , V_10 -> V_92 , V_89 ) ;
V_10 -> V_44 = V_88 ;
}
V_14 = V_10 -> V_24 -> V_96 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_41 , V_10 -> V_61 , V_14 ) ;
goto V_95;
}
V_10 -> V_97 = V_98 ;
F_46 ( V_6 , L_42 , V_10 -> V_61 ) ;
return 0 ;
V_95:
F_39 ( V_10 ) ;
V_91:
F_30 ( V_10 -> V_92 ) ;
V_10 -> V_92 = NULL ;
V_10 -> V_44 = NULL ;
F_12 ( V_10 ) ;
return V_14 ;
}
static void F_52 ( const struct V_84 * V_85 , void * V_99 )
{
struct V_10 * V_10 = V_99 ;
if ( V_10 -> V_100 )
F_53 ( V_10 ) ;
F_54 ( V_85 ) ;
F_55 ( & V_10 -> V_101 ) ;
}
static int F_56 ( struct V_10 * V_10 )
{
int V_14 ;
F_57 ( & V_10 -> V_101 ) ;
V_14 = F_58 ( V_102 , V_103 ,
V_10 -> V_84 , & V_10 -> V_6 , V_41 ,
V_10 , F_52 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_10 -> V_6 , L_43 , V_14 ) ;
F_55 ( & V_10 -> V_101 ) ;
}
return V_14 ;
}
int F_59 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_6 , L_44 , V_10 -> V_61 ) ;
F_57 ( & V_10 -> V_104 ) ;
F_60 ( V_10 ) ;
F_61 ( & V_10 -> V_104 ) ;
F_62 ( V_10 ) ;
return 0 ;
}
static void F_63 ( struct V_105 * V_106 )
{
struct V_10 * V_10 = F_64 ( V_106 , struct V_10 , V_107 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_7 ( V_6 , L_45 , V_108 ) ;
F_65 ( & V_10 -> V_109 ) ;
if ( V_10 -> V_97 == V_110 || V_10 -> V_97 == V_111 ) {
F_66 ( & V_10 -> V_109 ) ;
return;
}
V_10 -> V_97 = V_110 ;
F_4 ( V_6 , L_46 , ++ V_10 -> V_112 ,
V_10 -> V_61 ) ;
F_66 ( & V_10 -> V_109 ) ;
if ( ! V_10 -> V_113 )
F_59 ( V_10 ) ;
}
static int F_67 ( struct V_10 * V_10 , bool V_114 )
{
const struct V_84 * V_115 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_68 ( L_47 ) ;
return - V_42 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_69 ( & V_10 -> V_109 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_48 , V_10 -> V_61 , V_14 ) ;
return V_14 ;
}
if ( F_70 ( & V_10 -> V_116 ) > 1 ) {
V_14 = 0 ;
goto V_117;
}
F_46 ( V_6 , L_49 , V_10 -> V_61 ) ;
V_14 = F_71 ( & V_115 , V_10 -> V_84 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_50 , V_14 ) ;
goto V_118;
}
if ( V_114 )
F_61 ( & V_10 -> V_101 ) ;
V_14 = F_44 ( V_10 , V_115 ) ;
F_54 ( V_115 ) ;
V_118:
if ( V_14 )
F_72 ( & V_10 -> V_116 ) ;
V_117:
F_66 ( & V_10 -> V_109 ) ;
return V_14 ;
}
int F_62 ( struct V_10 * V_10 )
{
return F_67 ( V_10 , true ) ;
}
int F_53 ( struct V_10 * V_10 )
{
return F_67 ( V_10 , false ) ;
}
void F_60 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_69 ( & V_10 -> V_109 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_48 , V_10 -> V_61 , V_14 ) ;
return;
}
if ( ! F_73 ( & V_10 -> V_116 ) )
goto V_26;
V_14 = V_10 -> V_24 -> V_119 ( V_10 ) ;
if ( V_14 ) {
F_74 ( & V_10 -> V_116 ) ;
F_4 ( V_6 , L_51 , V_14 ) ;
goto V_26;
}
F_39 ( V_10 ) ;
F_12 ( V_10 ) ;
F_30 ( V_10 -> V_92 ) ;
V_10 -> V_92 = NULL ;
V_10 -> V_44 = NULL ;
if ( V_10 -> V_97 == V_110 )
F_55 ( & V_10 -> V_104 ) ;
V_10 -> V_97 = V_111 ;
F_46 ( V_6 , L_52 , V_10 -> V_61 ) ;
V_26:
F_66 ( & V_10 -> V_109 ) ;
}
struct V_10 * F_75 ( T_5 T_5 )
{
struct V_10 * V_10 = NULL , * V_120 ;
struct V_121 * V_122 ;
V_122 = F_76 ( T_5 ) ;
if ( ! V_122 )
return NULL ;
F_65 ( & V_123 ) ;
F_15 (r, &rproc_list, node) {
if ( V_120 -> V_6 . V_13 && V_120 -> V_6 . V_13 -> V_124 == V_122 ) {
if ( ! F_77 ( V_120 -> V_6 . V_13 -> V_125 -> V_126 ) ) {
F_4 ( & V_120 -> V_6 , L_53 ) ;
break;
}
V_10 = V_120 ;
F_78 ( & V_10 -> V_6 ) ;
break;
}
}
F_66 ( & V_123 ) ;
F_79 ( V_122 ) ;
return V_10 ;
}
struct V_10 * F_75 ( T_5 T_5 )
{
return NULL ;
}
int F_80 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_81 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_46 ( V_6 , L_54 , V_10 -> V_61 ) ;
F_46 ( V_6 , L_55 ) ;
F_46 ( V_6 , L_56 ) ;
F_82 ( V_10 ) ;
V_14 = F_56 ( V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
F_65 ( & V_123 ) ;
F_83 ( & V_10 -> V_56 , & V_127 ) ;
F_66 ( & V_123 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_64 ( V_6 , struct V_10 , V_6 ) ;
F_46 ( & V_10 -> V_6 , L_57 , V_10 -> V_61 ) ;
F_85 ( V_10 ) ;
F_86 ( & V_10 -> V_43 ) ;
if ( V_10 -> V_128 >= 0 )
F_87 ( & V_129 , V_10 -> V_128 ) ;
F_30 ( V_10 ) ;
}
struct V_10 * F_88 ( struct V_5 * V_6 , const char * V_61 ,
const struct V_130 * V_24 ,
const char * V_84 , int V_20 )
{
struct V_10 * V_10 ;
char * V_131 , * V_132 = L_58 ;
int V_133 = 0 ;
if ( ! V_6 || ! V_61 || ! V_24 )
return NULL ;
if ( ! V_84 )
V_133 = strlen ( V_61 ) + strlen ( V_132 ) - 2 + 1 ;
V_10 = F_26 ( sizeof( * V_10 ) + V_20 + V_133 , V_41 ) ;
if ( ! V_10 )
return NULL ;
if ( ! V_84 ) {
V_131 = ( char * ) V_10 + sizeof( struct V_10 ) + V_20 ;
snprintf ( V_131 , V_133 , V_132 , V_61 ) ;
} else {
V_131 = ( char * ) V_84 ;
}
V_10 -> V_84 = V_131 ;
V_10 -> V_61 = V_61 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_63 = & V_10 [ 1 ] ;
V_10 -> V_100 = true ;
F_89 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_134 ;
V_10 -> V_128 = F_90 ( & V_129 , 0 , 0 , V_41 ) ;
if ( V_10 -> V_128 < 0 ) {
F_4 ( V_6 , L_59 , V_10 -> V_128 ) ;
F_91 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_92 ( & V_10 -> V_6 , L_60 , V_10 -> V_128 ) ;
F_93 ( & V_10 -> V_116 , 0 ) ;
V_10 -> V_135 = & V_136 ;
F_94 ( & V_10 -> V_109 ) ;
F_95 ( & V_10 -> V_43 ) ;
F_96 ( & V_10 -> V_73 ) ;
F_96 ( & V_10 -> V_68 ) ;
F_96 ( & V_10 -> V_64 ) ;
F_96 ( & V_10 -> V_57 ) ;
F_97 ( & V_10 -> V_107 , F_63 ) ;
F_57 ( & V_10 -> V_104 ) ;
V_10 -> V_97 = V_111 ;
return V_10 ;
}
void F_98 ( struct V_10 * V_10 )
{
F_91 ( & V_10 -> V_6 ) ;
}
void F_99 ( struct V_10 * V_10 )
{
F_100 ( V_10 -> V_6 . V_13 -> V_125 -> V_126 ) ;
F_91 ( & V_10 -> V_6 ) ;
}
int F_101 ( struct V_10 * V_10 )
{
struct V_29 * V_30 , * V_81 ;
if ( ! V_10 )
return - V_42 ;
F_61 ( & V_10 -> V_101 ) ;
if ( V_10 -> V_100 )
F_60 ( V_10 ) ;
F_40 (rvdev, tmp, &rproc->rvdevs, node)
F_43 ( V_30 ) ;
F_65 ( & V_123 ) ;
F_29 ( & V_10 -> V_56 ) ;
F_66 ( & V_123 ) ;
F_102 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_68 ( L_61 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_62 ,
V_10 -> V_61 , F_1 ( type ) ) ;
F_103 ( & V_10 -> V_107 ) ;
}
static int T_6 F_104 ( void )
{
F_105 () ;
return 0 ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_129 ) ;
F_108 () ;
}
