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
if ( ! F_20 ( & V_10 -> V_35 , V_36 ) ) {
F_4 ( V_6 , L_6 ) ;
return - V_16 ;
}
V_24 = F_21 ( V_6 -> V_13 , V_32 , & V_31 , V_36 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_7 ) ;
return - V_37 ;
}
V_14 = F_22 ( & V_10 -> V_35 , V_29 , & V_33 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_8 , V_14 ) ;
F_23 ( V_6 -> V_13 , V_32 , V_24 , V_31 ) ;
return V_14 ;
}
V_10 -> V_38 = F_24 ( V_10 -> V_38 , V_33 ) ;
F_8 ( V_6 , L_9 , V_27 , V_24 ,
( unsigned long long ) V_31 , V_32 , V_33 ) ;
V_29 -> V_24 = V_24 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_33 ;
return 0 ;
}
static int
F_25 ( struct V_25 * V_26 , struct V_39 * V_40 , int V_27 )
{
struct V_10 * V_10 = V_26 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_41 * V_30 = & V_40 -> V_30 [ V_27 ] ;
struct V_28 * V_29 = & V_26 -> V_30 [ V_27 ] ;
F_8 ( V_6 , L_10 ,
V_27 , V_30 -> V_18 , V_30 -> V_42 , V_30 -> V_34 ) ;
if ( V_30 -> V_43 ) {
F_4 ( V_6 , L_11 ) ;
return - V_37 ;
}
if ( ! V_30 -> V_42 || ! V_30 -> V_34 ) {
F_4 ( V_6 , L_12 ,
V_30 -> V_42 , V_30 -> V_34 ) ;
return - V_37 ;
}
V_29 -> V_19 = V_30 -> V_42 ;
V_29 -> V_34 = V_30 -> V_34 ;
V_29 -> V_26 = V_26 ;
return 0 ;
}
static int F_26 ( int V_44 , void * V_45 , void * V_46 )
{
int * V_47 = V_46 ;
* V_47 = F_24 ( * V_47 , V_44 ) ;
return 0 ;
}
void F_27 ( struct V_28 * V_29 )
{
int V_32 = F_18 ( F_19 ( V_29 -> V_19 , V_29 -> V_34 ) ) ;
struct V_10 * V_10 = V_29 -> V_26 -> V_10 ;
int V_47 = 0 ;
F_23 ( V_10 -> V_6 . V_13 , V_32 , V_29 -> V_24 , V_29 -> V_31 ) ;
F_28 ( & V_10 -> V_35 , V_29 -> V_33 ) ;
F_29 ( & V_10 -> V_35 , F_26 , & V_47 ) ;
V_10 -> V_38 = V_47 ;
}
static int F_30 ( struct V_10 * V_10 , struct V_39 * V_40 ,
int V_48 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_25 * V_26 ;
int V_27 , V_14 ;
if ( sizeof( * V_40 ) + V_40 -> V_49 * sizeof( struct V_41 )
+ V_40 -> V_50 > V_48 ) {
F_4 ( V_6 , L_13 ) ;
return - V_37 ;
}
if ( V_40 -> V_43 [ 0 ] || V_40 -> V_43 [ 1 ] ) {
F_4 ( V_6 , L_14 ) ;
return - V_37 ;
}
F_8 ( V_6 , L_15 ,
V_40 -> V_44 , V_40 -> V_51 , V_40 -> V_50 , V_40 -> V_49 ) ;
if ( V_40 -> V_49 > F_2 ( V_26 -> V_30 ) ) {
F_4 ( V_6 , L_16 , V_40 -> V_49 ) ;
return - V_37 ;
}
V_26 = F_31 ( sizeof( struct V_25 ) , V_36 ) ;
if ( ! V_26 )
return - V_16 ;
V_26 -> V_10 = V_10 ;
for ( V_27 = 0 ; V_27 < V_40 -> V_49 ; V_27 ++ ) {
V_14 = F_25 ( V_26 , V_40 , V_27 ) ;
if ( V_14 )
goto V_52;
}
V_26 -> V_51 = V_40 -> V_51 ;
F_32 ( & V_26 -> V_53 , & V_10 -> V_54 ) ;
V_14 = F_33 ( V_26 , V_40 -> V_44 ) ;
if ( V_14 )
goto V_52;
return 0 ;
V_52:
F_34 ( V_26 ) ;
return V_14 ;
}
static int F_35 ( struct V_10 * V_10 , struct V_55 * V_40 ,
int V_48 )
{
struct V_20 * V_56 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_22 ;
char V_57 [ 15 ] ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_17 ) ;
return - V_37 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_18 ) ;
return - V_37 ;
}
V_22 = F_15 ( V_10 , V_40 -> V_18 , V_40 -> V_19 ) ;
if ( ! V_22 ) {
F_4 ( V_6 , L_19 ) ;
return - V_37 ;
}
V_56 = F_31 ( sizeof( * V_56 ) , V_36 ) ;
if ( ! V_56 ) {
F_4 ( V_6 , L_20 ) ;
return - V_16 ;
}
V_56 -> V_19 = V_40 -> V_19 ;
V_56 -> V_24 = V_22 ;
snprintf ( V_57 , sizeof( V_57 ) , L_21 , V_10 -> V_58 ) ;
V_56 -> V_59 = F_36 ( V_57 , V_10 , V_56 ) ;
if ( ! V_56 -> V_59 ) {
V_56 -> V_24 = NULL ;
F_34 ( V_56 ) ;
return - V_37 ;
}
F_32 ( & V_56 -> V_53 , & V_10 -> V_60 ) ;
V_10 -> V_58 ++ ;
F_8 ( V_6 , L_22 , V_57 , V_22 ,
V_40 -> V_18 , V_40 -> V_19 ) ;
return 0 ;
}
static int F_37 ( struct V_10 * V_10 , struct V_61 * V_40 ,
int V_48 )
{
struct V_20 * V_62 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_37 ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_23 ) ;
return - V_37 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_24 ) ;
return - V_37 ;
}
V_62 = F_31 ( sizeof( * V_62 ) , V_36 ) ;
if ( ! V_62 ) {
F_4 ( V_6 , L_25 ) ;
return - V_16 ;
}
V_14 = F_38 ( V_10 -> V_4 , V_40 -> V_18 , V_40 -> V_63 , V_40 -> V_19 , V_40 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_26 , V_14 ) ;
goto V_64;
}
V_62 -> V_18 = V_40 -> V_18 ;
V_62 -> V_19 = V_40 -> V_19 ;
F_32 ( & V_62 -> V_53 , & V_10 -> V_65 ) ;
F_8 ( V_6 , L_27 ,
V_40 -> V_63 , V_40 -> V_18 , V_40 -> V_19 ) ;
return 0 ;
V_64:
F_34 ( V_62 ) ;
return V_14 ;
}
static int F_39 ( struct V_10 * V_10 ,
struct V_66 * V_40 , int V_48 )
{
struct V_20 * V_21 , * V_62 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_31 ;
void * V_24 ;
int V_14 ;
if ( sizeof( * V_40 ) > V_48 ) {
F_4 ( V_6 , L_28 ) ;
return - V_37 ;
}
if ( V_40 -> V_43 ) {
F_4 ( V_6 , L_29 ) ;
return - V_37 ;
}
F_8 ( V_6 , L_30 ,
V_40 -> V_18 , V_40 -> V_63 , V_40 -> V_19 , V_40 -> V_8 ) ;
V_21 = F_31 ( sizeof( * V_21 ) , V_36 ) ;
if ( ! V_21 ) {
F_4 ( V_6 , L_31 ) ;
return - V_16 ;
}
V_24 = F_21 ( V_6 -> V_13 , V_40 -> V_19 , & V_31 , V_36 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_32 , V_40 -> V_19 ) ;
V_14 = - V_16 ;
goto V_67;
}
F_8 ( V_6 , L_33 , V_24 ,
( unsigned long long ) V_31 , V_40 -> V_19 ) ;
if ( V_10 -> V_4 ) {
V_62 = F_31 ( sizeof( * V_62 ) , V_36 ) ;
if ( ! V_62 ) {
F_4 ( V_6 , L_25 ) ;
V_14 = - V_16 ;
goto V_68;
}
V_14 = F_38 ( V_10 -> V_4 , V_40 -> V_18 , V_31 , V_40 -> V_19 ,
V_40 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_34 , V_14 ) ;
goto V_69;
}
V_62 -> V_18 = V_40 -> V_18 ;
V_62 -> V_19 = V_40 -> V_19 ;
F_32 ( & V_62 -> V_53 , & V_10 -> V_65 ) ;
F_8 ( V_6 , L_35 ,
V_40 -> V_18 , ( unsigned long long ) V_31 ) ;
}
V_40 -> V_63 = V_31 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_19 = V_40 -> V_19 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_18 = V_40 -> V_18 ;
F_32 ( & V_21 -> V_53 , & V_10 -> V_70 ) ;
return 0 ;
V_69:
F_34 ( V_62 ) ;
V_68:
F_23 ( V_6 -> V_13 , V_40 -> V_19 , V_24 , V_31 ) ;
V_67:
F_34 ( V_21 ) ;
return V_14 ;
}
static int
F_40 ( struct V_10 * V_10 , struct V_71 * V_72 , int V_19 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_73 ;
int V_14 = 0 , V_27 ;
for ( V_27 = 0 ; V_27 < V_72 -> V_42 ; V_27 ++ ) {
int V_23 = V_72 -> V_23 [ V_27 ] ;
struct V_74 * V_75 = ( void * ) V_72 + V_23 ;
int V_48 = V_19 - V_23 - sizeof( * V_75 ) ;
void * V_40 = ( void * ) V_75 + sizeof( * V_75 ) ;
if ( V_48 < 0 ) {
F_4 ( V_6 , L_36 ) ;
return - V_37 ;
}
F_8 ( V_6 , L_37 , V_75 -> type ) ;
if ( V_75 -> type >= V_76 ) {
F_41 ( V_6 , L_38 , V_75 -> type ) ;
continue;
}
V_73 = V_77 [ V_75 -> type ] ;
if ( ! V_73 )
continue;
V_14 = V_73 ( V_10 , V_40 , V_48 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static int
F_42 ( struct V_10 * V_10 , struct V_71 * V_72 , int V_19 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 = 0 , V_27 ;
for ( V_27 = 0 ; V_27 < V_72 -> V_42 ; V_27 ++ ) {
int V_23 = V_72 -> V_23 [ V_27 ] ;
struct V_74 * V_75 = ( void * ) V_72 + V_23 ;
int V_48 = V_19 - V_23 - sizeof( * V_75 ) ;
struct V_39 * V_78 ;
if ( V_48 < 0 ) {
F_4 ( V_6 , L_36 ) ;
return - V_37 ;
}
F_8 ( V_6 , L_39 , V_79 , V_75 -> type ) ;
if ( V_75 -> type != V_80 )
continue;
V_78 = (struct V_39 * ) V_75 -> V_46 ;
V_14 = F_30 ( V_10 , V_78 , V_48 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static void F_43 ( struct V_10 * V_10 )
{
struct V_20 * V_81 , * V_82 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_44 (entry, tmp, &rproc->traces, node) {
F_45 ( V_81 -> V_59 ) ;
V_10 -> V_58 -- ;
F_46 ( & V_81 -> V_53 ) ;
F_34 ( V_81 ) ;
}
F_44 (entry, tmp, &rproc->carveouts, node) {
F_23 ( V_6 -> V_13 , V_81 -> V_19 , V_81 -> V_24 , V_81 -> V_31 ) ;
F_46 ( & V_81 -> V_53 ) ;
F_34 ( V_81 ) ;
}
F_44 (entry, tmp, &rproc->mappings, node) {
T_4 V_83 ;
V_83 = F_47 ( V_10 -> V_4 , V_81 -> V_18 , V_81 -> V_19 ) ;
if ( V_83 != V_81 -> V_19 ) {
F_4 ( V_6 , L_40 , V_81 -> V_19 ,
V_83 ) ;
}
F_46 ( & V_81 -> V_53 ) ;
F_34 ( V_81 ) ;
}
}
static int F_48 ( struct V_10 * V_10 , const struct V_84 * V_85 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_57 = V_10 -> V_84 ;
struct V_71 * V_72 ;
int V_14 , V_86 ;
V_14 = F_49 ( V_10 , V_85 ) ;
if ( V_14 )
return V_14 ;
F_50 ( V_6 , L_41 , V_57 , V_85 -> V_32 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_42 , V_14 ) ;
return V_14 ;
}
V_10 -> V_87 = F_51 ( V_10 , V_85 ) ;
V_72 = F_52 ( V_10 , V_85 , & V_86 ) ;
if ( ! V_72 ) {
V_14 = - V_37 ;
goto V_88;
}
V_14 = F_40 ( V_10 , V_72 , V_86 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_43 , V_14 ) ;
goto V_88;
}
V_14 = F_53 ( V_10 , V_85 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_44 , V_14 ) ;
goto V_88;
}
V_14 = V_10 -> V_89 -> V_90 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_45 , V_10 -> V_57 , V_14 ) ;
goto V_88;
}
V_10 -> V_91 = V_92 ;
F_50 ( V_6 , L_46 , V_10 -> V_57 ) ;
return 0 ;
V_88:
F_43 ( V_10 ) ;
F_13 ( V_10 ) ;
return V_14 ;
}
static void F_54 ( const struct V_84 * V_85 , void * V_93 )
{
struct V_10 * V_10 = V_93 ;
struct V_71 * V_72 ;
int V_14 , V_86 ;
if ( F_49 ( V_10 , V_85 ) < 0 )
goto V_64;
V_72 = F_52 ( V_10 , V_85 , & V_86 ) ;
if ( ! V_72 )
goto V_64;
V_14 = F_42 ( V_10 , V_72 , V_86 ) ;
if ( V_14 )
goto V_64;
V_64:
F_55 ( V_85 ) ;
F_56 ( & V_10 -> V_94 ) ;
}
static int F_57 ( struct V_10 * V_10 )
{
int V_14 ;
F_58 ( & V_10 -> V_94 ) ;
V_14 = F_59 ( V_95 , V_96 ,
V_10 -> V_84 , & V_10 -> V_6 , V_36 ,
V_10 , F_54 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_10 -> V_6 , L_47 , V_14 ) ;
F_56 ( & V_10 -> V_94 ) ;
}
return V_14 ;
}
int F_60 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_97 ;
F_4 ( & V_10 -> V_6 , L_48 , V_10 -> V_57 ) ;
F_58 ( & V_10 -> V_98 ) ;
F_44 (rvdev, rvtmp, &rproc->rvdevs, node)
F_61 ( V_26 ) ;
F_62 ( & V_10 -> V_98 ) ;
return F_57 ( V_10 ) ;
}
static void F_63 ( struct V_99 * V_100 )
{
struct V_10 * V_10 = F_64 ( V_100 , struct V_10 , V_101 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_8 ( V_6 , L_49 , V_79 ) ;
F_65 ( & V_10 -> V_102 ) ;
if ( V_10 -> V_91 == V_103 || V_10 -> V_91 == V_104 ) {
F_66 ( & V_10 -> V_102 ) ;
return;
}
V_10 -> V_91 = V_103 ;
F_4 ( V_6 , L_50 , ++ V_10 -> V_105 ,
V_10 -> V_57 ) ;
F_66 ( & V_10 -> V_102 ) ;
if ( ! V_10 -> V_106 )
F_60 ( V_10 ) ;
}
int F_67 ( struct V_10 * V_10 )
{
const struct V_84 * V_107 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_68 ( L_51 ) ;
return - V_37 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_69 ( & V_10 -> V_102 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_52 , V_10 -> V_57 , V_14 ) ;
return V_14 ;
}
if ( ! V_10 -> V_84 ) {
F_4 ( V_6 , L_53 , V_79 ) ;
V_14 = - V_37 ;
goto V_108;
}
if ( ! F_70 ( V_6 -> V_13 -> V_109 -> V_110 ) ) {
F_4 ( V_6 , L_54 , V_79 ) ;
V_14 = - V_37 ;
goto V_108;
}
if ( F_71 ( & V_10 -> V_111 ) > 1 ) {
V_14 = 0 ;
goto V_108;
}
F_50 ( V_6 , L_55 , V_10 -> V_57 ) ;
V_14 = F_72 ( & V_107 , V_10 -> V_84 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_56 , V_14 ) ;
goto V_112;
}
V_14 = F_48 ( V_10 , V_107 ) ;
F_55 ( V_107 ) ;
V_112:
if ( V_14 ) {
F_73 ( V_6 -> V_13 -> V_109 -> V_110 ) ;
F_74 ( & V_10 -> V_111 ) ;
}
V_108:
F_66 ( & V_10 -> V_102 ) ;
return V_14 ;
}
void F_75 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_69 ( & V_10 -> V_102 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_52 , V_10 -> V_57 , V_14 ) ;
return;
}
if ( ! F_76 ( & V_10 -> V_111 ) )
goto V_64;
V_14 = V_10 -> V_89 -> V_113 ( V_10 ) ;
if ( V_14 ) {
F_77 ( & V_10 -> V_111 ) ;
F_4 ( V_6 , L_57 , V_14 ) ;
goto V_64;
}
F_43 ( V_10 ) ;
F_13 ( V_10 ) ;
if ( V_10 -> V_91 == V_103 )
F_56 ( & V_10 -> V_98 ) ;
V_10 -> V_91 = V_104 ;
F_50 ( V_6 , L_58 , V_10 -> V_57 ) ;
V_64:
F_66 ( & V_10 -> V_102 ) ;
if ( ! V_14 )
F_73 ( V_6 -> V_13 -> V_109 -> V_110 ) ;
}
int F_78 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_79 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_50 ( V_6 , L_59 , V_10 -> V_57 ) ;
F_50 ( V_6 , L_60 ) ;
F_50 ( V_6 , L_61 ) ;
F_80 ( V_10 ) ;
return F_57 ( V_10 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_64 ( V_6 , struct V_10 , V_6 ) ;
F_50 ( & V_10 -> V_6 , L_62 , V_10 -> V_57 ) ;
F_82 ( V_10 ) ;
F_83 ( & V_10 -> V_35 ) ;
F_84 ( & V_10 -> V_35 ) ;
if ( V_10 -> V_114 >= 0 )
F_85 ( & V_115 , V_10 -> V_114 ) ;
F_34 ( V_10 ) ;
}
struct V_10 * F_86 ( struct V_5 * V_6 , const char * V_57 ,
const struct V_116 * V_89 ,
const char * V_84 , int V_19 )
{
struct V_10 * V_10 ;
if ( ! V_6 || ! V_57 || ! V_89 )
return NULL ;
V_10 = F_31 ( sizeof( struct V_10 ) + V_19 , V_36 ) ;
if ( ! V_10 ) {
F_4 ( V_6 , L_63 , V_79 ) ;
return NULL ;
}
V_10 -> V_57 = V_57 ;
V_10 -> V_89 = V_89 ;
V_10 -> V_84 = V_84 ;
V_10 -> V_59 = & V_10 [ 1 ] ;
F_87 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_117 ;
V_10 -> V_114 = F_88 ( & V_115 , 0 , 0 , V_36 ) ;
if ( V_10 -> V_114 < 0 ) {
F_4 ( V_6 , L_64 , V_10 -> V_114 ) ;
F_89 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_90 ( & V_10 -> V_6 , L_65 , V_10 -> V_114 ) ;
F_91 ( & V_10 -> V_111 , 0 ) ;
V_10 -> V_118 = & V_119 ;
F_92 ( & V_10 -> V_102 ) ;
F_93 ( & V_10 -> V_35 ) ;
F_94 ( & V_10 -> V_70 ) ;
F_94 ( & V_10 -> V_65 ) ;
F_94 ( & V_10 -> V_60 ) ;
F_94 ( & V_10 -> V_54 ) ;
F_95 ( & V_10 -> V_101 , F_63 ) ;
F_58 ( & V_10 -> V_98 ) ;
V_10 -> V_91 = V_104 ;
return V_10 ;
}
void F_96 ( struct V_10 * V_10 )
{
F_89 ( & V_10 -> V_6 ) ;
}
int F_97 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_82 ;
if ( ! V_10 )
return - V_37 ;
F_62 ( & V_10 -> V_94 ) ;
F_44 (rvdev, tmp, &rproc->rvdevs, node)
F_61 ( V_26 ) ;
F_98 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_68 ( L_66 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_67 ,
V_10 -> V_57 , F_1 ( type ) ) ;
F_99 ( & V_10 -> V_101 ) ;
}
static int T_5 F_100 ( void )
{
F_101 () ;
return 0 ;
}
static void T_6 F_102 ( void )
{
F_103 () ;
}
