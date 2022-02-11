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
if ( V_39 > V_10 -> V_44 )
V_10 -> V_44 = V_39 ;
F_7 ( V_6 , L_8 ,
V_31 , V_28 , & V_37 , V_38 , V_39 ) ;
V_33 -> V_28 = V_28 ;
V_33 -> V_37 = V_37 ;
V_33 -> V_39 = V_39 ;
V_36 = ( void * ) V_10 -> V_45 + V_30 -> V_46 ;
V_36 -> V_34 [ V_31 ] . V_19 = V_37 ;
V_36 -> V_34 [ V_31 ] . V_39 = V_39 ;
return 0 ;
}
static int
F_22 ( struct V_29 * V_30 , struct V_35 * V_36 , int V_31 )
{
struct V_10 * V_10 = V_30 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_47 * V_34 = & V_36 -> V_34 [ V_31 ] ;
struct V_32 * V_33 = & V_30 -> V_34 [ V_31 ] ;
F_7 ( V_6 , L_9 ,
V_31 , V_34 -> V_19 , V_34 -> V_48 , V_34 -> V_40 ) ;
if ( ! V_34 -> V_48 || ! V_34 -> V_40 ) {
F_4 ( V_6 , L_10 ,
V_34 -> V_48 , V_34 -> V_40 ) ;
return - V_42 ;
}
V_33 -> V_20 = V_34 -> V_48 ;
V_33 -> V_40 = V_34 -> V_40 ;
V_33 -> V_30 = V_30 ;
return 0 ;
}
void F_23 ( struct V_32 * V_33 )
{
int V_38 = F_17 ( F_18 ( V_33 -> V_20 , V_33 -> V_40 ) ) ;
struct V_10 * V_10 = V_33 -> V_30 -> V_10 ;
int V_49 = V_33 -> V_30 -> V_34 - V_33 ;
struct V_35 * V_36 ;
F_21 ( V_10 -> V_6 . V_13 , V_38 , V_33 -> V_28 , V_33 -> V_37 ) ;
F_24 ( & V_10 -> V_43 , V_33 -> V_39 ) ;
V_36 = ( void * ) V_10 -> V_45 + V_33 -> V_30 -> V_46 ;
V_36 -> V_34 [ V_49 ] . V_19 = 0 ;
V_36 -> V_34 [ V_49 ] . V_39 = - 1 ;
}
static int F_25 ( struct V_50 * V_51 )
{
struct V_29 * V_30 = F_26 ( V_51 , struct V_29 , V_51 ) ;
return F_27 ( V_30 , V_30 -> V_52 ) ;
}
static void F_28 ( struct V_50 * V_51 )
{
struct V_29 * V_30 = F_26 ( V_51 , struct V_29 , V_51 ) ;
F_29 ( V_30 ) ;
}
static int F_30 ( struct V_10 * V_10 , struct V_35 * V_36 ,
int V_27 , int V_53 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_29 * V_30 ;
int V_31 , V_14 ;
if ( sizeof( * V_36 ) + V_36 -> V_54 * sizeof( struct V_47 )
+ V_36 -> V_55 > V_53 ) {
F_4 ( V_6 , L_11 ) ;
return - V_42 ;
}
if ( V_36 -> V_56 [ 0 ] || V_36 -> V_56 [ 1 ] ) {
F_4 ( V_6 , L_12 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_13 ,
V_36 -> V_52 , V_36 -> V_57 , V_36 -> V_55 , V_36 -> V_54 ) ;
if ( V_36 -> V_54 > F_2 ( V_30 -> V_34 ) ) {
F_4 ( V_6 , L_14 , V_36 -> V_54 ) ;
return - V_42 ;
}
V_30 = F_31 ( sizeof( * V_30 ) , V_41 ) ;
if ( ! V_30 )
return - V_17 ;
F_32 ( & V_30 -> V_58 ) ;
V_30 -> V_52 = V_36 -> V_52 ;
V_30 -> V_10 = V_10 ;
for ( V_31 = 0 ; V_31 < V_36 -> V_54 ; V_31 ++ ) {
V_14 = F_22 ( V_30 , V_36 , V_31 ) ;
if ( V_14 )
goto V_59;
}
V_30 -> V_46 = V_27 ;
for ( V_31 = 0 ; V_31 < V_36 -> V_54 ; V_31 ++ ) {
V_14 = F_16 ( V_30 , V_31 ) ;
if ( V_14 )
goto V_60;
}
F_33 ( & V_30 -> V_61 , & V_10 -> V_62 ) ;
F_34 ( V_10 , & V_30 -> V_51 ,
F_25 , F_28 ) ;
return 0 ;
V_60:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_23 ( & V_30 -> V_34 [ V_31 ] ) ;
V_59:
F_35 ( V_30 ) ;
return V_14 ;
}
void F_36 ( struct V_63 * V_64 )
{
struct V_29 * V_30 = F_26 ( V_64 , struct V_29 , V_58 ) ;
struct V_32 * V_33 ;
struct V_10 * V_10 = V_30 -> V_10 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < F_2 ( V_30 -> V_34 ) ; V_52 ++ ) {
V_33 = & V_30 -> V_34 [ V_52 ] ;
if ( ! V_33 -> V_28 )
continue;
F_23 ( V_33 ) ;
}
F_37 ( V_10 , & V_30 -> V_51 ) ;
F_38 ( & V_30 -> V_61 ) ;
F_35 ( V_30 ) ;
}
static int F_39 ( struct V_10 * V_10 , struct V_65 * V_36 ,
int V_27 , int V_53 )
{
struct V_21 * V_66 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_23 ;
char V_67 [ 15 ] ;
if ( sizeof( * V_36 ) > V_53 ) {
F_4 ( V_6 , L_15 ) ;
return - V_42 ;
}
if ( V_36 -> V_56 ) {
F_4 ( V_6 , L_16 ) ;
return - V_42 ;
}
V_23 = F_14 ( V_10 , V_36 -> V_19 , V_36 -> V_20 ) ;
if ( ! V_23 ) {
F_4 ( V_6 , L_17 ) ;
return - V_42 ;
}
V_66 = F_31 ( sizeof( * V_66 ) , V_41 ) ;
if ( ! V_66 )
return - V_17 ;
V_66 -> V_20 = V_36 -> V_20 ;
V_66 -> V_28 = V_23 ;
snprintf ( V_67 , sizeof( V_67 ) , L_18 , V_10 -> V_68 ) ;
V_66 -> V_69 = F_40 ( V_67 , V_10 , V_66 ) ;
if ( ! V_66 -> V_69 ) {
V_66 -> V_28 = NULL ;
F_35 ( V_66 ) ;
return - V_42 ;
}
F_33 ( & V_66 -> V_61 , & V_10 -> V_70 ) ;
V_10 -> V_68 ++ ;
F_7 ( V_6 , L_19 ,
V_67 , V_23 , V_36 -> V_19 , V_36 -> V_20 ) ;
return 0 ;
}
static int F_41 ( struct V_10 * V_10 , struct V_71 * V_36 ,
int V_27 , int V_53 )
{
struct V_21 * V_72 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_42 ;
if ( sizeof( * V_36 ) > V_53 ) {
F_4 ( V_6 , L_20 ) ;
return - V_42 ;
}
if ( V_36 -> V_56 ) {
F_4 ( V_6 , L_21 ) ;
return - V_42 ;
}
V_72 = F_31 ( sizeof( * V_72 ) , V_41 ) ;
if ( ! V_72 )
return - V_17 ;
V_14 = F_42 ( V_10 -> V_4 , V_36 -> V_19 , V_36 -> V_73 , V_36 -> V_20 , V_36 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_22 , V_14 ) ;
goto V_26;
}
V_72 -> V_19 = V_36 -> V_19 ;
V_72 -> V_20 = V_36 -> V_20 ;
F_33 ( & V_72 -> V_61 , & V_10 -> V_74 ) ;
F_7 ( V_6 , L_23 ,
V_36 -> V_73 , V_36 -> V_19 , V_36 -> V_20 ) ;
return 0 ;
V_26:
F_35 ( V_72 ) ;
return V_14 ;
}
static int F_43 ( struct V_10 * V_10 ,
struct V_75 * V_36 ,
int V_27 , int V_53 )
{
struct V_21 * V_22 , * V_72 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_37 ;
void * V_28 ;
int V_14 ;
if ( sizeof( * V_36 ) > V_53 ) {
F_4 ( V_6 , L_24 ) ;
return - V_42 ;
}
if ( V_36 -> V_56 ) {
F_4 ( V_6 , L_25 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_26 ,
V_36 -> V_67 , V_36 -> V_19 , V_36 -> V_73 , V_36 -> V_20 , V_36 -> V_8 ) ;
V_22 = F_31 ( sizeof( * V_22 ) , V_41 ) ;
if ( ! V_22 )
return - V_17 ;
V_28 = F_19 ( V_6 -> V_13 , V_36 -> V_20 , & V_37 , V_41 ) ;
if ( ! V_28 ) {
F_4 ( V_6 -> V_13 ,
L_27 , V_36 -> V_20 ) ;
V_14 = - V_17 ;
goto V_76;
}
F_7 ( V_6 , L_28 ,
V_28 , & V_37 , V_36 -> V_20 ) ;
if ( V_10 -> V_4 ) {
V_72 = F_31 ( sizeof( * V_72 ) , V_41 ) ;
if ( ! V_72 ) {
V_14 = - V_17 ;
goto V_77;
}
V_14 = F_42 ( V_10 -> V_4 , V_36 -> V_19 , V_37 , V_36 -> V_20 ,
V_36 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_29 , V_14 ) ;
goto V_78;
}
V_72 -> V_19 = V_36 -> V_19 ;
V_72 -> V_20 = V_36 -> V_20 ;
F_33 ( & V_72 -> V_61 , & V_10 -> V_74 ) ;
F_7 ( V_6 , L_30 ,
V_36 -> V_19 , & V_37 ) ;
}
V_36 -> V_73 = V_37 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_20 = V_36 -> V_20 ;
V_22 -> V_37 = V_37 ;
V_22 -> V_19 = V_36 -> V_19 ;
F_33 ( & V_22 -> V_61 , & V_10 -> V_79 ) ;
return 0 ;
V_78:
F_35 ( V_72 ) ;
V_77:
F_21 ( V_6 -> V_13 , V_36 -> V_20 , V_28 , V_37 ) ;
V_76:
F_35 ( V_22 ) ;
return V_14 ;
}
static int F_44 ( struct V_10 * V_10 , int V_20 ,
T_3 V_80 [ V_81 ] )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_82 ;
int V_14 = 0 , V_31 ;
for ( V_31 = 0 ; V_31 < V_10 -> V_45 -> V_48 ; V_31 ++ ) {
int V_27 = V_10 -> V_45 -> V_27 [ V_31 ] ;
struct V_83 * V_84 = ( void * ) V_10 -> V_45 + V_27 ;
int V_53 = V_20 - V_27 - sizeof( * V_84 ) ;
void * V_36 = ( void * ) V_84 + sizeof( * V_84 ) ;
if ( V_53 < 0 ) {
F_4 ( V_6 , L_31 ) ;
return - V_42 ;
}
F_7 ( V_6 , L_32 , V_84 -> type ) ;
if ( V_84 -> type >= V_81 ) {
F_45 ( V_6 , L_33 , V_84 -> type ) ;
continue;
}
V_82 = V_80 [ V_84 -> type ] ;
if ( ! V_82 )
continue;
V_14 = V_82 ( V_10 , V_36 , V_27 + sizeof( * V_84 ) , V_53 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static int F_46 ( struct V_10 * V_10 )
{
struct V_50 * V_51 ;
int V_14 ;
F_15 (subdev, &rproc->subdevs, node) {
V_14 = V_51 -> V_85 ( V_51 ) ;
if ( V_14 )
goto V_86;
}
return 0 ;
V_86:
F_47 (subdev, &rproc->subdevs, node)
V_51 -> remove ( V_51 ) ;
return V_14 ;
}
static void F_48 ( struct V_10 * V_10 )
{
struct V_50 * V_51 ;
F_15 (subdev, &rproc->subdevs, node)
V_51 -> remove ( V_51 ) ;
}
static void F_49 ( struct V_10 * V_10 )
{
struct V_21 * V_87 , * V_88 ;
struct V_29 * V_30 , * V_89 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_50 (entry, tmp, &rproc->traces, node) {
F_51 ( V_87 -> V_69 ) ;
V_10 -> V_68 -- ;
F_38 ( & V_87 -> V_61 ) ;
F_35 ( V_87 ) ;
}
F_50 (entry, tmp, &rproc->mappings, node) {
T_4 V_90 ;
V_90 = F_52 ( V_10 -> V_4 , V_87 -> V_19 , V_87 -> V_20 ) ;
if ( V_90 != V_87 -> V_20 ) {
F_4 ( V_6 , L_34 , V_87 -> V_20 ,
V_90 ) ;
}
F_38 ( & V_87 -> V_61 ) ;
F_35 ( V_87 ) ;
}
F_50 (entry, tmp, &rproc->carveouts, node) {
F_21 ( V_6 -> V_13 , V_87 -> V_20 , V_87 -> V_28 ,
V_87 -> V_37 ) ;
F_38 ( & V_87 -> V_61 ) ;
F_35 ( V_87 ) ;
}
F_50 (rvdev, rvtmp, &rproc->rvdevs, node)
F_53 ( & V_30 -> V_58 , F_36 ) ;
}
static int F_54 ( struct V_10 * V_10 , const struct V_91 * V_92 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_67 = V_10 -> V_91 ;
struct V_93 * V_94 , * V_95 ;
int V_14 , V_96 ;
V_14 = F_55 ( V_10 , V_92 ) ;
if ( V_14 )
return V_14 ;
F_56 ( V_6 , L_35 , V_67 , V_92 -> V_38 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_36 , V_14 ) ;
return V_14 ;
}
V_10 -> V_97 = F_57 ( V_10 , V_92 ) ;
V_14 = - V_42 ;
V_94 = F_58 ( V_10 , V_92 , & V_96 ) ;
if ( ! V_94 ) {
F_4 ( V_6 , L_37 ) ;
goto V_98;
}
V_10 -> V_99 = F_59 ( V_94 , V_96 , V_41 ) ;
if ( ! V_10 -> V_99 )
goto V_98;
V_10 -> V_45 = V_10 -> V_99 ;
V_10 -> V_44 = - 1 ;
V_14 = F_44 ( V_10 , V_96 , V_100 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_38 , V_14 ) ;
goto V_101;
}
V_14 = F_60 ( V_10 , V_92 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_39 , V_14 ) ;
goto V_101;
}
V_95 = F_61 ( V_10 , V_92 ) ;
if ( V_95 ) {
memcpy ( V_95 , V_10 -> V_99 , V_96 ) ;
V_10 -> V_45 = V_95 ;
}
V_14 = V_10 -> V_24 -> V_102 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_40 , V_10 -> V_67 , V_14 ) ;
goto V_101;
}
V_14 = F_46 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_41 ,
V_10 -> V_67 , V_14 ) ;
goto V_103;
}
V_10 -> V_104 = V_105 ;
F_56 ( V_6 , L_42 , V_10 -> V_67 ) ;
return 0 ;
V_103:
V_10 -> V_24 -> V_106 ( V_10 ) ;
V_101:
F_49 ( V_10 ) ;
V_98:
F_35 ( V_10 -> V_99 ) ;
V_10 -> V_99 = NULL ;
V_10 -> V_45 = NULL ;
F_12 ( V_10 ) ;
return V_14 ;
}
static void F_62 ( const struct V_91 * V_92 , void * V_107 )
{
struct V_10 * V_10 = V_107 ;
F_63 ( V_10 ) ;
F_64 ( V_92 ) ;
}
static int F_65 ( struct V_10 * V_10 )
{
int V_14 ;
V_14 = F_66 ( V_108 , V_109 ,
V_10 -> V_91 , & V_10 -> V_6 , V_41 ,
V_10 , F_62 ) ;
if ( V_14 < 0 )
F_4 ( & V_10 -> V_6 , L_43 , V_14 ) ;
return V_14 ;
}
int F_67 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_6 , L_44 , V_10 -> V_67 ) ;
F_68 ( & V_10 -> V_110 ) ;
F_69 ( V_10 ) ;
F_70 ( & V_10 -> V_110 ) ;
F_63 ( V_10 ) ;
return 0 ;
}
static void F_71 ( struct V_111 * V_112 )
{
struct V_10 * V_10 = F_26 ( V_112 , struct V_10 , V_113 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_7 ( V_6 , L_45 , V_114 ) ;
F_72 ( & V_10 -> V_115 ) ;
if ( V_10 -> V_104 == V_116 || V_10 -> V_104 == V_117 ) {
F_73 ( & V_10 -> V_115 ) ;
return;
}
V_10 -> V_104 = V_116 ;
F_4 ( V_6 , L_46 , ++ V_10 -> V_118 ,
V_10 -> V_67 ) ;
F_73 ( & V_10 -> V_115 ) ;
if ( ! V_10 -> V_119 )
F_67 ( V_10 ) ;
}
static int F_74 ( struct V_10 * V_10 )
{
const struct V_91 * V_120 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_75 ( L_47 ) ;
return - V_42 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_76 ( & V_10 -> V_115 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_48 , V_10 -> V_67 , V_14 ) ;
return V_14 ;
}
if ( V_10 -> V_104 == V_121 ) {
V_14 = - V_122 ;
F_4 ( V_6 , L_49 , V_10 -> V_67 ) ;
goto V_123;
}
if ( F_77 ( & V_10 -> V_124 ) > 1 ) {
V_14 = 0 ;
goto V_123;
}
F_56 ( V_6 , L_50 , V_10 -> V_67 ) ;
V_14 = F_78 ( & V_120 , V_10 -> V_91 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_51 , V_14 ) ;
goto V_125;
}
V_14 = F_54 ( V_10 , V_120 ) ;
F_64 ( V_120 ) ;
V_125:
if ( V_14 )
F_79 ( & V_10 -> V_124 ) ;
V_123:
F_73 ( & V_10 -> V_115 ) ;
return V_14 ;
}
int F_63 ( struct V_10 * V_10 )
{
return F_74 ( V_10 ) ;
}
void F_69 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_76 ( & V_10 -> V_115 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_48 , V_10 -> V_67 , V_14 ) ;
return;
}
if ( ! F_80 ( & V_10 -> V_124 ) )
goto V_26;
F_48 ( V_10 ) ;
V_14 = V_10 -> V_24 -> V_106 ( V_10 ) ;
if ( V_14 ) {
F_81 ( & V_10 -> V_124 ) ;
F_4 ( V_6 , L_52 , V_14 ) ;
goto V_26;
}
F_49 ( V_10 ) ;
F_12 ( V_10 ) ;
F_35 ( V_10 -> V_99 ) ;
V_10 -> V_99 = NULL ;
V_10 -> V_45 = NULL ;
if ( V_10 -> V_104 == V_116 )
F_82 ( & V_10 -> V_110 ) ;
V_10 -> V_104 = V_117 ;
F_56 ( V_6 , L_53 , V_10 -> V_67 ) ;
V_26:
F_73 ( & V_10 -> V_115 ) ;
}
struct V_10 * F_83 ( T_5 T_5 )
{
struct V_10 * V_10 = NULL , * V_126 ;
struct V_127 * V_128 ;
V_128 = F_84 ( T_5 ) ;
if ( ! V_128 )
return NULL ;
F_72 ( & V_129 ) ;
F_15 (r, &rproc_list, node) {
if ( V_126 -> V_6 . V_13 && V_126 -> V_6 . V_13 -> V_130 == V_128 ) {
if ( ! F_85 ( V_126 -> V_6 . V_13 -> V_131 -> V_132 ) ) {
F_4 ( & V_126 -> V_6 , L_54 ) ;
break;
}
V_10 = V_126 ;
F_86 ( & V_10 -> V_6 ) ;
break;
}
}
F_73 ( & V_129 ) ;
F_87 ( V_128 ) ;
return V_10 ;
}
struct V_10 * F_83 ( T_5 T_5 )
{
return NULL ;
}
int F_88 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_89 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_56 ( V_6 , L_55 , V_10 -> V_67 ) ;
F_90 ( V_10 ) ;
if ( V_10 -> V_133 ) {
V_14 = F_65 ( V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
}
F_72 ( & V_129 ) ;
F_91 ( & V_10 -> V_61 , & V_134 ) ;
F_73 ( & V_129 ) ;
return 0 ;
}
static void F_92 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_26 ( V_6 , struct V_10 , V_6 ) ;
F_56 ( & V_10 -> V_6 , L_56 , V_10 -> V_67 ) ;
F_93 ( & V_10 -> V_43 ) ;
if ( V_10 -> V_135 >= 0 )
F_94 ( & V_136 , V_10 -> V_135 ) ;
F_35 ( V_10 -> V_91 ) ;
F_35 ( V_10 ) ;
}
struct V_10 * F_95 ( struct V_5 * V_6 , const char * V_67 ,
const struct V_137 * V_24 ,
const char * V_91 , int V_20 )
{
struct V_10 * V_10 ;
char * V_138 , * V_139 = L_57 ;
int V_140 ;
if ( ! V_6 || ! V_67 || ! V_24 )
return NULL ;
if ( ! V_91 ) {
V_140 = strlen ( V_67 ) + strlen ( V_139 ) - 2 + 1 ;
V_138 = F_96 ( V_140 , V_41 ) ;
if ( ! V_138 )
return NULL ;
snprintf ( V_138 , V_140 , V_139 , V_67 ) ;
} else {
V_138 = F_97 ( V_91 , V_41 ) ;
if ( ! V_138 )
return NULL ;
}
V_10 = F_31 ( sizeof( struct V_10 ) + V_20 , V_41 ) ;
if ( ! V_10 ) {
F_35 ( V_138 ) ;
return NULL ;
}
V_10 -> V_91 = V_138 ;
V_10 -> V_67 = V_67 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_69 = & V_10 [ 1 ] ;
V_10 -> V_133 = true ;
F_98 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_141 ;
V_10 -> V_6 . V_142 = & V_143 ;
V_10 -> V_135 = F_99 ( & V_136 , 0 , 0 , V_41 ) ;
if ( V_10 -> V_135 < 0 ) {
F_4 ( V_6 , L_58 , V_10 -> V_135 ) ;
F_100 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_101 ( & V_10 -> V_6 , L_59 , V_10 -> V_135 ) ;
F_102 ( & V_10 -> V_124 , 0 ) ;
V_10 -> V_144 = & V_145 ;
F_103 ( & V_10 -> V_115 ) ;
F_104 ( & V_10 -> V_43 ) ;
F_105 ( & V_10 -> V_79 ) ;
F_105 ( & V_10 -> V_74 ) ;
F_105 ( & V_10 -> V_70 ) ;
F_105 ( & V_10 -> V_62 ) ;
F_105 ( & V_10 -> V_146 ) ;
F_106 ( & V_10 -> V_113 , F_71 ) ;
F_68 ( & V_10 -> V_110 ) ;
V_10 -> V_104 = V_117 ;
return V_10 ;
}
void F_107 ( struct V_10 * V_10 )
{
F_100 ( & V_10 -> V_6 ) ;
}
void F_108 ( struct V_10 * V_10 )
{
F_109 ( V_10 -> V_6 . V_13 -> V_131 -> V_132 ) ;
F_100 ( & V_10 -> V_6 ) ;
}
int F_110 ( struct V_10 * V_10 )
{
if ( ! V_10 )
return - V_42 ;
if ( V_10 -> V_133 )
F_69 ( V_10 ) ;
F_72 ( & V_10 -> V_115 ) ;
V_10 -> V_104 = V_121 ;
F_73 ( & V_10 -> V_115 ) ;
F_111 ( V_10 ) ;
F_72 ( & V_129 ) ;
F_38 ( & V_10 -> V_61 ) ;
F_73 ( & V_129 ) ;
F_112 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_34 ( struct V_10 * V_10 ,
struct V_50 * V_51 ,
int (* V_85)( struct V_50 * V_51 ) ,
void (* remove)( struct V_50 * V_51 ) )
{
V_51 -> V_85 = V_85 ;
V_51 -> remove = remove ;
F_33 ( & V_51 -> V_61 , & V_10 -> V_146 ) ;
}
void F_37 ( struct V_10 * V_10 , struct V_50 * V_51 )
{
F_38 ( & V_51 -> V_61 ) ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_75 ( L_60 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_61 ,
V_10 -> V_67 , F_1 ( type ) ) ;
F_113 ( & V_10 -> V_113 ) ;
}
static int T_6 F_114 ( void )
{
F_115 () ;
F_116 () ;
return 0 ;
}
static void T_7 F_117 ( void )
{
F_118 ( & V_136 ) ;
F_119 () ;
F_120 () ;
}
