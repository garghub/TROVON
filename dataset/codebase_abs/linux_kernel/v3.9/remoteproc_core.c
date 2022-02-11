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
if ( ! F_7 ( V_6 -> V_15 ) ) {
F_8 ( V_6 , L_3 ) ;
return 0 ;
}
V_4 = F_9 ( V_6 -> V_15 ) ;
if ( ! V_4 ) {
F_4 ( V_6 , L_4 ) ;
return - V_16 ;
}
F_10 ( V_4 , F_3 , V_10 ) ;
V_14 = F_11 ( V_4 , V_6 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_5 , V_14 ) ;
goto V_17;
}
V_10 -> V_4 = V_4 ;
return 0 ;
V_17:
F_12 ( V_4 ) ;
return V_14 ;
}
static void F_13 ( struct V_10 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_4 ;
struct V_5 * V_6 = V_10 -> V_6 . V_13 ;
if ( ! V_4 )
return;
F_14 ( V_4 , V_6 ) ;
F_12 ( V_4 ) ;
return;
}
void * F_15 ( struct V_10 * V_10 , T_1 V_18 , int V_19 )
{
struct V_20 * V_21 ;
void * V_22 = NULL ;
F_16 (carveout, &rproc->carveouts, node) {
int V_23 = V_18 - V_21 -> V_18 ;
if ( V_23 < 0 )
continue;
if ( V_23 + V_19 > V_21 -> V_19 )
continue;
V_22 = V_21 -> V_24 + V_23 ;
break;
}
return V_22 ;
}
int F_17 ( struct V_25 * V_26 , int V_27 )
{
struct V_10 * V_10 = V_26 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_28 * V_29 = & V_26 -> V_30 [ V_27 ] ;
T_2 V_31 ;
void * V_24 ;
int V_14 , V_32 , V_33 ;
V_32 = F_18 ( F_19 ( V_29 -> V_19 , V_29 -> V_34 ) ) ;
V_24 = F_20 ( V_6 -> V_13 , V_32 , & V_31 , V_35 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_6 ) ;
return - V_36 ;
}
V_14 = F_21 ( & V_10 -> V_37 , V_29 , 0 , 0 , V_35 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_7 , V_14 ) ;
F_22 ( V_6 -> V_13 , V_32 , V_24 , V_31 ) ;
return V_14 ;
}
V_33 = V_14 ;
V_10 -> V_38 = F_23 ( V_10 -> V_38 , V_33 ) ;
F_8 ( V_6 , L_8 , V_27 , V_24 ,
( unsigned long long ) V_31 , V_32 , V_33 ) ;
V_29 -> V_24 = V_24 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_33 ;
return 0 ;
}
static int
F_24 ( struct V_25 * V_26 , struct V_39 * V_40 , int V_27 )
{
struct V_10 * V_10 = V_26 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_41 * V_30 = & V_40 -> V_30 [ V_27 ] ;
struct V_28 * V_29 = & V_26 -> V_30 [ V_27 ] ;
F_8 ( V_6 , L_9 ,
V_27 , V_30 -> V_18 , V_30 -> V_42 , V_30 -> V_34 ) ;
if ( V_30 -> V_43 ) {
F_4 ( V_6 , L_10 ) ;
return - V_36 ;
}
if ( ! V_30 -> V_42 || ! V_30 -> V_34 ) {
F_4 ( V_6 , L_11 ,
V_30 -> V_42 , V_30 -> V_34 ) ;
return - V_36 ;
}
V_29 -> V_19 = V_30 -> V_42 ;
V_29 -> V_34 = V_30 -> V_34 ;
V_29 -> V_26 = V_26 ;
return 0 ;
}
static int F_25 ( int V_44 , void * V_45 , void * V_46 )
{
int * V_47 = V_46 ;
* V_47 = F_23 ( * V_47 , V_44 ) ;
return 0 ;
}
void F_26 ( struct V_28 * V_29 )
{
int V_32 = F_18 ( F_19 ( V_29 -> V_19 , V_29 -> V_34 ) ) ;
struct V_10 * V_10 = V_29 -> V_26 -> V_10 ;
int V_47 = 0 ;
F_22 ( V_10 -> V_6 . V_13 , V_32 , V_29 -> V_24 , V_29 -> V_31 ) ;
F_27 ( & V_10 -> V_37 , V_29 -> V_33 ) ;
F_28 ( & V_10 -> V_37 , F_25 , & V_47 ) ;
V_10 -> V_38 = V_47 ;
}
static int F_29 ( struct V_10 * V_10 , struct V_39 * V_40 ,
int V_48 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_25 * V_26 ;
int V_27 , V_14 ;
if ( sizeof( * V_40 ) + V_40 -> V_49 * sizeof( struct V_41 )
+ V_40 -> V_50 > V_48 ) {
F_4 ( V_6 , L_12 ) ;
return - V_36 ;
}
if ( V_40 -> V_43 [ 0 ] || V_40 -> V_43 [ 1 ] ) {
F_4 ( V_6 , L_13 ) ;
return - V_36 ;
}
F_8 ( V_6 , L_14 ,
V_40 -> V_44 , V_40 -> V_51 , V_40 -> V_50 , V_40 -> V_49 ) ;
if ( V_40 -> V_49 > F_2 ( V_26 -> V_30 ) ) {
F_4 ( V_6 , L_15 , V_40 -> V_49 ) ;
return - V_36 ;
}
V_26 = F_30 ( sizeof( struct V_25 ) , V_35 ) ;
if ( ! V_26 )
return - V_16 ;
V_26 -> V_10 = V_10 ;
for ( V_27 = 0 ; V_27 < V_40 -> V_49 ; V_27 ++ ) {
V_14 = F_24 ( V_26 , V_40 , V_27 ) ;
if ( V_14 )
goto V_52;
}
V_26 -> V_51 = V_40 -> V_51 ;
F_31 ( & V_26 -> V_53 , & V_10 -> V_54 ) ;
V_14 = F_32 ( V_26 , V_40 -> V_44 ) ;
if ( V_14 )
goto V_55;
return 0 ;
V_55:
F_33 ( & V_26 -> V_53 ) ;
V_52:
F_34 ( V_26 ) ;
return V_14 ;
}
static int F_35 ( struct V_10 * V_10 , struct V_56 * V_40 ,
int V_48 )
{
struct V_20 * V_57 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_22 ;
char V_58 [ 15 ] ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_16 ) ;
return - V_36 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_17 ) ;
return - V_36 ;
}
V_22 = F_15 ( V_10 , V_40 -> V_18 , V_40 -> V_19 ) ;
if ( ! V_22 ) {
F_4 ( V_6 , L_18 ) ;
return - V_36 ;
}
V_57 = F_30 ( sizeof( * V_57 ) , V_35 ) ;
if ( ! V_57 ) {
F_4 ( V_6 , L_19 ) ;
return - V_16 ;
}
V_57 -> V_19 = V_40 -> V_19 ;
V_57 -> V_24 = V_22 ;
snprintf ( V_58 , sizeof( V_58 ) , L_20 , V_10 -> V_59 ) ;
V_57 -> V_60 = F_36 ( V_58 , V_10 , V_57 ) ;
if ( ! V_57 -> V_60 ) {
V_57 -> V_24 = NULL ;
F_34 ( V_57 ) ;
return - V_36 ;
}
F_31 ( & V_57 -> V_53 , & V_10 -> V_61 ) ;
V_10 -> V_59 ++ ;
F_8 ( V_6 , L_21 , V_58 , V_22 ,
V_40 -> V_18 , V_40 -> V_19 ) ;
return 0 ;
}
static int F_37 ( struct V_10 * V_10 , struct V_62 * V_40 ,
int V_48 )
{
struct V_20 * V_63 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_36 ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_22 ) ;
return - V_36 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_23 ) ;
return - V_36 ;
}
V_63 = F_30 ( sizeof( * V_63 ) , V_35 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_24 ) ;
return - V_16 ;
}
V_14 = F_38 ( V_10 -> V_4 , V_40 -> V_18 , V_40 -> V_64 , V_40 -> V_19 , V_40 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_25 , V_14 ) ;
goto V_65;
}
V_63 -> V_18 = V_40 -> V_18 ;
V_63 -> V_19 = V_40 -> V_19 ;
F_31 ( & V_63 -> V_53 , & V_10 -> V_66 ) ;
F_8 ( V_6 , L_26 ,
V_40 -> V_64 , V_40 -> V_18 , V_40 -> V_19 ) ;
return 0 ;
V_65:
F_34 ( V_63 ) ;
return V_14 ;
}
static int F_39 ( struct V_10 * V_10 ,
struct V_67 * V_40 , int V_48 )
{
struct V_20 * V_21 , * V_63 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_31 ;
void * V_24 ;
int V_14 ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_27 ) ;
return - V_36 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_28 ) ;
return - V_36 ;
}
F_8 ( V_6 , L_29 ,
V_40 -> V_18 , V_40 -> V_64 , V_40 -> V_19 , V_40 -> V_8 ) ;
V_21 = F_30 ( sizeof( * V_21 ) , V_35 ) ;
if ( ! V_21 ) {
F_4 ( V_6 , L_30 ) ;
return - V_16 ;
}
V_24 = F_20 ( V_6 -> V_13 , V_40 -> V_19 , & V_31 , V_35 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_31 , V_40 -> V_19 ) ;
V_14 = - V_16 ;
goto V_68;
}
F_8 ( V_6 , L_32 , V_24 ,
( unsigned long long ) V_31 , V_40 -> V_19 ) ;
if ( V_10 -> V_4 ) {
V_63 = F_30 ( sizeof( * V_63 ) , V_35 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_24 ) ;
V_14 = - V_16 ;
goto V_69;
}
V_14 = F_38 ( V_10 -> V_4 , V_40 -> V_18 , V_31 , V_40 -> V_19 ,
V_40 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_33 , V_14 ) ;
goto V_70;
}
V_63 -> V_18 = V_40 -> V_18 ;
V_63 -> V_19 = V_40 -> V_19 ;
F_31 ( & V_63 -> V_53 , & V_10 -> V_66 ) ;
F_8 ( V_6 , L_34 ,
V_40 -> V_18 , ( unsigned long long ) V_31 ) ;
}
V_40 -> V_64 = V_31 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_19 = V_40 -> V_19 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_18 = V_40 -> V_18 ;
F_31 ( & V_21 -> V_53 , & V_10 -> V_71 ) ;
return 0 ;
V_70:
F_34 ( V_63 ) ;
V_69:
F_22 ( V_6 -> V_13 , V_40 -> V_19 , V_24 , V_31 ) ;
V_68:
F_34 ( V_21 ) ;
return V_14 ;
}
static int
F_40 ( struct V_10 * V_10 , struct V_72 * V_73 , int V_19 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_74 ;
int V_14 = 0 , V_27 ;
for ( V_27 = 0 ; V_27 < V_73 -> V_42 ; V_27 ++ ) {
int V_23 = V_73 -> V_23 [ V_27 ] ;
struct V_75 * V_76 = ( void * ) V_73 + V_23 ;
int V_48 = V_19 - V_23 - sizeof( * V_76 ) ;
void * V_40 = ( void * ) V_76 + sizeof( * V_76 ) ;
if ( V_48 < 0 ) {
F_4 ( V_6 , L_35 ) ;
return - V_36 ;
}
F_8 ( V_6 , L_36 , V_76 -> type ) ;
if ( V_76 -> type >= V_77 ) {
F_41 ( V_6 , L_37 , V_76 -> type ) ;
continue;
}
V_74 = V_78 [ V_76 -> type ] ;
if ( ! V_74 )
continue;
V_14 = V_74 ( V_10 , V_40 , V_48 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static int
F_42 ( struct V_10 * V_10 , struct V_72 * V_73 , int V_19 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 = 0 , V_27 ;
for ( V_27 = 0 ; V_27 < V_73 -> V_42 ; V_27 ++ ) {
int V_23 = V_73 -> V_23 [ V_27 ] ;
struct V_75 * V_76 = ( void * ) V_73 + V_23 ;
int V_48 = V_19 - V_23 - sizeof( * V_76 ) ;
struct V_39 * V_79 ;
if ( V_48 < 0 ) {
F_4 ( V_6 , L_35 ) ;
return - V_36 ;
}
F_8 ( V_6 , L_38 , V_80 , V_76 -> type ) ;
if ( V_76 -> type != V_81 )
continue;
V_79 = (struct V_39 * ) V_76 -> V_46 ;
V_14 = F_29 ( V_10 , V_79 , V_48 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static void F_43 ( struct V_10 * V_10 )
{
struct V_20 * V_82 , * V_83 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_44 (entry, tmp, &rproc->traces, node) {
F_45 ( V_82 -> V_60 ) ;
V_10 -> V_59 -- ;
F_33 ( & V_82 -> V_53 ) ;
F_34 ( V_82 ) ;
}
F_44 (entry, tmp, &rproc->carveouts, node) {
F_22 ( V_6 -> V_13 , V_82 -> V_19 , V_82 -> V_24 , V_82 -> V_31 ) ;
F_33 ( & V_82 -> V_53 ) ;
F_34 ( V_82 ) ;
}
F_44 (entry, tmp, &rproc->mappings, node) {
T_4 V_84 ;
V_84 = F_46 ( V_10 -> V_4 , V_82 -> V_18 , V_82 -> V_19 ) ;
if ( V_84 != V_82 -> V_19 ) {
F_4 ( V_6 , L_39 , V_82 -> V_19 ,
V_84 ) ;
}
F_33 ( & V_82 -> V_53 ) ;
F_34 ( V_82 ) ;
}
}
static int F_47 ( struct V_10 * V_10 , const struct V_85 * V_86 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_58 = V_10 -> V_85 ;
struct V_72 * V_73 ;
int V_14 , V_87 ;
V_14 = F_48 ( V_10 , V_86 ) ;
if ( V_14 )
return V_14 ;
F_49 ( V_6 , L_40 , V_58 , V_86 -> V_32 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_41 , V_14 ) ;
return V_14 ;
}
V_10 -> V_88 = F_50 ( V_10 , V_86 ) ;
V_73 = F_51 ( V_10 , V_86 , & V_87 ) ;
if ( ! V_73 ) {
V_14 = - V_36 ;
goto V_89;
}
V_14 = F_40 ( V_10 , V_73 , V_87 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_42 , V_14 ) ;
goto V_89;
}
V_14 = F_52 ( V_10 , V_86 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_43 , V_14 ) ;
goto V_89;
}
V_14 = V_10 -> V_90 -> V_91 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_44 , V_10 -> V_58 , V_14 ) ;
goto V_89;
}
V_10 -> V_92 = V_93 ;
F_49 ( V_6 , L_45 , V_10 -> V_58 ) ;
return 0 ;
V_89:
F_43 ( V_10 ) ;
F_13 ( V_10 ) ;
return V_14 ;
}
static void F_53 ( const struct V_85 * V_86 , void * V_94 )
{
struct V_10 * V_10 = V_94 ;
struct V_72 * V_73 ;
int V_14 , V_87 ;
if ( F_48 ( V_10 , V_86 ) < 0 )
goto V_65;
V_73 = F_51 ( V_10 , V_86 , & V_87 ) ;
if ( ! V_73 )
goto V_65;
V_14 = F_42 ( V_10 , V_73 , V_87 ) ;
if ( V_14 )
goto V_65;
V_65:
F_54 ( V_86 ) ;
F_55 ( & V_10 -> V_95 ) ;
}
static int F_56 ( struct V_10 * V_10 )
{
int V_14 ;
F_57 ( & V_10 -> V_95 ) ;
V_14 = F_58 ( V_96 , V_97 ,
V_10 -> V_85 , & V_10 -> V_6 , V_35 ,
V_10 , F_53 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_10 -> V_6 , L_46 , V_14 ) ;
F_55 ( & V_10 -> V_95 ) ;
}
return V_14 ;
}
int F_59 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_98 ;
F_4 ( & V_10 -> V_6 , L_47 , V_10 -> V_58 ) ;
F_57 ( & V_10 -> V_99 ) ;
F_44 (rvdev, rvtmp, &rproc->rvdevs, node)
F_60 ( V_26 ) ;
F_61 ( & V_10 -> V_99 ) ;
return F_56 ( V_10 ) ;
}
static void F_62 ( struct V_100 * V_101 )
{
struct V_10 * V_10 = F_63 ( V_101 , struct V_10 , V_102 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_8 ( V_6 , L_48 , V_80 ) ;
F_64 ( & V_10 -> V_103 ) ;
if ( V_10 -> V_92 == V_104 || V_10 -> V_92 == V_105 ) {
F_65 ( & V_10 -> V_103 ) ;
return;
}
V_10 -> V_92 = V_104 ;
F_4 ( V_6 , L_49 , ++ V_10 -> V_106 ,
V_10 -> V_58 ) ;
F_65 ( & V_10 -> V_103 ) ;
if ( ! V_10 -> V_107 )
F_59 ( V_10 ) ;
}
int F_66 ( struct V_10 * V_10 )
{
const struct V_85 * V_108 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_67 ( L_50 ) ;
return - V_36 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_68 ( & V_10 -> V_103 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_58 , V_14 ) ;
return V_14 ;
}
if ( ! V_10 -> V_85 ) {
F_4 ( V_6 , L_52 , V_80 ) ;
V_14 = - V_36 ;
goto V_109;
}
if ( ! F_69 ( V_6 -> V_13 -> V_110 -> V_111 ) ) {
F_4 ( V_6 , L_53 , V_80 ) ;
V_14 = - V_36 ;
goto V_109;
}
if ( F_70 ( & V_10 -> V_112 ) > 1 ) {
V_14 = 0 ;
goto V_109;
}
F_49 ( V_6 , L_54 , V_10 -> V_58 ) ;
V_14 = F_71 ( & V_108 , V_10 -> V_85 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_55 , V_14 ) ;
goto V_113;
}
V_14 = F_47 ( V_10 , V_108 ) ;
F_54 ( V_108 ) ;
V_113:
if ( V_14 ) {
F_72 ( V_6 -> V_13 -> V_110 -> V_111 ) ;
F_73 ( & V_10 -> V_112 ) ;
}
V_109:
F_65 ( & V_10 -> V_103 ) ;
return V_14 ;
}
void F_74 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_68 ( & V_10 -> V_103 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_58 , V_14 ) ;
return;
}
if ( ! F_75 ( & V_10 -> V_112 ) )
goto V_65;
V_14 = V_10 -> V_90 -> V_114 ( V_10 ) ;
if ( V_14 ) {
F_76 ( & V_10 -> V_112 ) ;
F_4 ( V_6 , L_56 , V_14 ) ;
goto V_65;
}
F_43 ( V_10 ) ;
F_13 ( V_10 ) ;
if ( V_10 -> V_92 == V_104 )
F_55 ( & V_10 -> V_99 ) ;
V_10 -> V_92 = V_105 ;
F_49 ( V_6 , L_57 , V_10 -> V_58 ) ;
V_65:
F_65 ( & V_10 -> V_103 ) ;
if ( ! V_14 )
F_72 ( V_6 -> V_13 -> V_110 -> V_111 ) ;
}
int F_77 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_78 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_49 ( V_6 , L_58 , V_10 -> V_58 ) ;
F_49 ( V_6 , L_59 ) ;
F_49 ( V_6 , L_60 ) ;
F_79 ( V_10 ) ;
return F_56 ( V_10 ) ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_63 ( V_6 , struct V_10 , V_6 ) ;
F_49 ( & V_10 -> V_6 , L_61 , V_10 -> V_58 ) ;
F_81 ( V_10 ) ;
F_82 ( & V_10 -> V_37 ) ;
if ( V_10 -> V_115 >= 0 )
F_83 ( & V_116 , V_10 -> V_115 ) ;
F_34 ( V_10 ) ;
}
struct V_10 * F_84 ( struct V_5 * V_6 , const char * V_58 ,
const struct V_117 * V_90 ,
const char * V_85 , int V_19 )
{
struct V_10 * V_10 ;
if ( ! V_6 || ! V_58 || ! V_90 )
return NULL ;
V_10 = F_30 ( sizeof( struct V_10 ) + V_19 , V_35 ) ;
if ( ! V_10 ) {
F_4 ( V_6 , L_62 , V_80 ) ;
return NULL ;
}
V_10 -> V_58 = V_58 ;
V_10 -> V_90 = V_90 ;
V_10 -> V_85 = V_85 ;
V_10 -> V_60 = & V_10 [ 1 ] ;
F_85 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_118 ;
V_10 -> V_115 = F_86 ( & V_116 , 0 , 0 , V_35 ) ;
if ( V_10 -> V_115 < 0 ) {
F_4 ( V_6 , L_63 , V_10 -> V_115 ) ;
F_87 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_88 ( & V_10 -> V_6 , L_64 , V_10 -> V_115 ) ;
F_89 ( & V_10 -> V_112 , 0 ) ;
V_10 -> V_119 = & V_120 ;
F_90 ( & V_10 -> V_103 ) ;
F_91 ( & V_10 -> V_37 ) ;
F_92 ( & V_10 -> V_71 ) ;
F_92 ( & V_10 -> V_66 ) ;
F_92 ( & V_10 -> V_61 ) ;
F_92 ( & V_10 -> V_54 ) ;
F_93 ( & V_10 -> V_102 , F_62 ) ;
F_57 ( & V_10 -> V_99 ) ;
V_10 -> V_92 = V_105 ;
return V_10 ;
}
void F_94 ( struct V_10 * V_10 )
{
F_87 ( & V_10 -> V_6 ) ;
}
int F_95 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_83 ;
if ( ! V_10 )
return - V_36 ;
F_61 ( & V_10 -> V_95 ) ;
F_44 (rvdev, tmp, &rproc->rvdevs, node)
F_60 ( V_26 ) ;
F_96 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_67 ( L_65 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_66 ,
V_10 -> V_58 , F_1 ( type ) ) ;
F_97 ( & V_10 -> V_102 ) ;
}
static int T_5 F_98 ( void )
{
F_99 () ;
return 0 ;
}
static void T_6 F_100 ( void )
{
F_101 () ;
}
