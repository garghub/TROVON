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
struct V_31 * V_32 ;
T_2 V_33 ;
void * V_24 ;
int V_14 , V_34 , V_35 ;
V_34 = F_18 ( F_19 ( V_29 -> V_19 , V_29 -> V_36 ) ) ;
V_24 = F_20 ( V_6 -> V_13 , V_34 , & V_33 , V_37 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_6 ) ;
return - V_38 ;
}
V_14 = F_21 ( & V_10 -> V_39 , V_29 , 0 , 0 , V_37 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_7 , V_14 ) ;
F_22 ( V_6 -> V_13 , V_34 , V_24 , V_33 ) ;
return V_14 ;
}
V_35 = V_14 ;
F_8 ( V_6 , L_8 , V_27 , V_24 ,
( unsigned long long ) V_33 , V_34 , V_35 ) ;
V_29 -> V_24 = V_24 ;
V_29 -> V_33 = V_33 ;
V_29 -> V_35 = V_35 ;
V_32 = ( void * ) V_10 -> V_40 + V_26 -> V_41 ;
V_32 -> V_30 [ V_27 ] . V_18 = V_33 ;
V_32 -> V_30 [ V_27 ] . V_35 = V_35 ;
return 0 ;
}
static int
F_23 ( struct V_25 * V_26 , struct V_31 * V_32 , int V_27 )
{
struct V_10 * V_10 = V_26 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_42 * V_30 = & V_32 -> V_30 [ V_27 ] ;
struct V_28 * V_29 = & V_26 -> V_30 [ V_27 ] ;
F_8 ( V_6 , L_9 ,
V_27 , V_30 -> V_18 , V_30 -> V_43 , V_30 -> V_36 ) ;
if ( V_30 -> V_44 ) {
F_4 ( V_6 , L_10 ) ;
return - V_38 ;
}
if ( ! V_30 -> V_43 || ! V_30 -> V_36 ) {
F_4 ( V_6 , L_11 ,
V_30 -> V_43 , V_30 -> V_36 ) ;
return - V_38 ;
}
V_29 -> V_19 = V_30 -> V_43 ;
V_29 -> V_36 = V_30 -> V_36 ;
V_29 -> V_26 = V_26 ;
return 0 ;
}
void F_24 ( struct V_28 * V_29 )
{
int V_34 = F_18 ( F_19 ( V_29 -> V_19 , V_29 -> V_36 ) ) ;
struct V_10 * V_10 = V_29 -> V_26 -> V_10 ;
int V_45 = V_29 -> V_26 -> V_30 - V_29 ;
struct V_31 * V_32 ;
F_22 ( V_10 -> V_6 . V_13 , V_34 , V_29 -> V_24 , V_29 -> V_33 ) ;
F_25 ( & V_10 -> V_39 , V_29 -> V_35 ) ;
V_32 = ( void * ) V_10 -> V_40 + V_29 -> V_26 -> V_41 ;
V_32 -> V_30 [ V_45 ] . V_18 = 0 ;
V_32 -> V_30 [ V_45 ] . V_35 = - 1 ;
}
static int F_26 ( struct V_10 * V_10 , struct V_31 * V_32 ,
int V_23 , int V_46 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_25 * V_26 ;
int V_27 , V_14 ;
if ( sizeof( * V_32 ) + V_32 -> V_47 * sizeof( struct V_42 )
+ V_32 -> V_48 > V_46 ) {
F_4 ( V_6 , L_12 ) ;
return - V_38 ;
}
if ( V_32 -> V_44 [ 0 ] || V_32 -> V_44 [ 1 ] ) {
F_4 ( V_6 , L_13 ) ;
return - V_38 ;
}
F_8 ( V_6 , L_14 ,
V_32 -> V_49 , V_32 -> V_50 , V_32 -> V_48 , V_32 -> V_47 ) ;
if ( V_32 -> V_47 > F_2 ( V_26 -> V_30 ) ) {
F_4 ( V_6 , L_15 , V_32 -> V_47 ) ;
return - V_38 ;
}
V_26 = F_27 ( sizeof( struct V_25 ) , V_37 ) ;
if ( ! V_26 )
return - V_16 ;
V_26 -> V_10 = V_10 ;
for ( V_27 = 0 ; V_27 < V_32 -> V_47 ; V_27 ++ ) {
V_14 = F_23 ( V_26 , V_32 , V_27 ) ;
if ( V_14 )
goto V_51;
}
V_26 -> V_41 = V_23 ;
F_28 ( & V_26 -> V_52 , & V_10 -> V_53 ) ;
V_14 = F_29 ( V_26 , V_32 -> V_49 ) ;
if ( V_14 )
goto V_54;
return 0 ;
V_54:
F_30 ( & V_26 -> V_52 ) ;
V_51:
F_31 ( V_26 ) ;
return V_14 ;
}
static int F_32 ( struct V_10 * V_10 , struct V_55 * V_32 ,
int V_23 , int V_46 )
{
struct V_20 * V_56 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_22 ;
char V_57 [ 15 ] ;
if ( sizeof( * V_32 ) > V_46 ) {
F_4 ( V_6 , L_16 ) ;
return - V_38 ;
}
if ( V_32 -> V_44 ) {
F_4 ( V_6 , L_17 ) ;
return - V_38 ;
}
V_22 = F_15 ( V_10 , V_32 -> V_18 , V_32 -> V_19 ) ;
if ( ! V_22 ) {
F_4 ( V_6 , L_18 ) ;
return - V_38 ;
}
V_56 = F_27 ( sizeof( * V_56 ) , V_37 ) ;
if ( ! V_56 ) {
F_4 ( V_6 , L_19 ) ;
return - V_16 ;
}
V_56 -> V_19 = V_32 -> V_19 ;
V_56 -> V_24 = V_22 ;
snprintf ( V_57 , sizeof( V_57 ) , L_20 , V_10 -> V_58 ) ;
V_56 -> V_59 = F_33 ( V_57 , V_10 , V_56 ) ;
if ( ! V_56 -> V_59 ) {
V_56 -> V_24 = NULL ;
F_31 ( V_56 ) ;
return - V_38 ;
}
F_28 ( & V_56 -> V_52 , & V_10 -> V_60 ) ;
V_10 -> V_58 ++ ;
F_8 ( V_6 , L_21 , V_57 , V_22 ,
V_32 -> V_18 , V_32 -> V_19 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_10 , struct V_61 * V_32 ,
int V_23 , int V_46 )
{
struct V_20 * V_62 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_38 ;
if ( sizeof( * V_32 ) > V_46 ) {
F_4 ( V_6 , L_22 ) ;
return - V_38 ;
}
if ( V_32 -> V_44 ) {
F_4 ( V_6 , L_23 ) ;
return - V_38 ;
}
V_62 = F_27 ( sizeof( * V_62 ) , V_37 ) ;
if ( ! V_62 ) {
F_4 ( V_6 , L_24 ) ;
return - V_16 ;
}
V_14 = F_35 ( V_10 -> V_4 , V_32 -> V_18 , V_32 -> V_63 , V_32 -> V_19 , V_32 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_25 , V_14 ) ;
goto V_64;
}
V_62 -> V_18 = V_32 -> V_18 ;
V_62 -> V_19 = V_32 -> V_19 ;
F_28 ( & V_62 -> V_52 , & V_10 -> V_65 ) ;
F_8 ( V_6 , L_26 ,
V_32 -> V_63 , V_32 -> V_18 , V_32 -> V_19 ) ;
return 0 ;
V_64:
F_31 ( V_62 ) ;
return V_14 ;
}
static int F_36 ( struct V_10 * V_10 ,
struct V_66 * V_32 ,
int V_23 , int V_46 )
{
struct V_20 * V_21 , * V_62 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_33 ;
void * V_24 ;
int V_14 ;
if ( sizeof( * V_32 ) > V_46 ) {
F_4 ( V_6 , L_27 ) ;
return - V_38 ;
}
if ( V_32 -> V_44 ) {
F_4 ( V_6 , L_28 ) ;
return - V_38 ;
}
F_8 ( V_6 , L_29 ,
V_32 -> V_18 , V_32 -> V_63 , V_32 -> V_19 , V_32 -> V_8 ) ;
V_21 = F_27 ( sizeof( * V_21 ) , V_37 ) ;
if ( ! V_21 ) {
F_4 ( V_6 , L_30 ) ;
return - V_16 ;
}
V_24 = F_20 ( V_6 -> V_13 , V_32 -> V_19 , & V_33 , V_37 ) ;
if ( ! V_24 ) {
F_4 ( V_6 -> V_13 , L_31 , V_32 -> V_19 ) ;
V_14 = - V_16 ;
goto V_67;
}
F_8 ( V_6 , L_32 , V_24 ,
( unsigned long long ) V_33 , V_32 -> V_19 ) ;
if ( V_10 -> V_4 ) {
V_62 = F_27 ( sizeof( * V_62 ) , V_37 ) ;
if ( ! V_62 ) {
F_4 ( V_6 , L_24 ) ;
V_14 = - V_16 ;
goto V_68;
}
V_14 = F_35 ( V_10 -> V_4 , V_32 -> V_18 , V_33 , V_32 -> V_19 ,
V_32 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_33 , V_14 ) ;
goto V_69;
}
V_62 -> V_18 = V_32 -> V_18 ;
V_62 -> V_19 = V_32 -> V_19 ;
F_28 ( & V_62 -> V_52 , & V_10 -> V_65 ) ;
F_8 ( V_6 , L_34 ,
V_32 -> V_18 , ( unsigned long long ) V_33 ) ;
}
V_32 -> V_63 = V_33 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_19 = V_32 -> V_19 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_18 = V_32 -> V_18 ;
F_28 ( & V_21 -> V_52 , & V_10 -> V_70 ) ;
return 0 ;
V_69:
F_31 ( V_62 ) ;
V_68:
F_22 ( V_6 -> V_13 , V_32 -> V_19 , V_24 , V_33 ) ;
V_67:
F_31 ( V_21 ) ;
return V_14 ;
}
static int F_37 ( struct V_10 * V_10 , struct V_31 * V_32 ,
int V_23 , int V_46 )
{
V_10 -> V_71 += V_32 -> V_47 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_10 , int V_19 ,
T_3 V_72 [ V_73 ] )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_74 ;
int V_14 = 0 , V_27 ;
for ( V_27 = 0 ; V_27 < V_10 -> V_40 -> V_43 ; V_27 ++ ) {
int V_23 = V_10 -> V_40 -> V_23 [ V_27 ] ;
struct V_75 * V_76 = ( void * ) V_10 -> V_40 + V_23 ;
int V_46 = V_19 - V_23 - sizeof( * V_76 ) ;
void * V_32 = ( void * ) V_76 + sizeof( * V_76 ) ;
if ( V_46 < 0 ) {
F_4 ( V_6 , L_35 ) ;
return - V_38 ;
}
F_8 ( V_6 , L_36 , V_76 -> type ) ;
if ( V_76 -> type >= V_73 ) {
F_39 ( V_6 , L_37 , V_76 -> type ) ;
continue;
}
V_74 = V_72 [ V_76 -> type ] ;
if ( ! V_74 )
continue;
V_14 = V_74 ( V_10 , V_32 , V_23 + sizeof( * V_76 ) , V_46 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static void F_40 ( struct V_10 * V_10 )
{
struct V_20 * V_77 , * V_78 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_41 (entry, tmp, &rproc->traces, node) {
F_42 ( V_77 -> V_59 ) ;
V_10 -> V_58 -- ;
F_30 ( & V_77 -> V_52 ) ;
F_31 ( V_77 ) ;
}
F_41 (entry, tmp, &rproc->carveouts, node) {
F_22 ( V_6 -> V_13 , V_77 -> V_19 , V_77 -> V_24 , V_77 -> V_33 ) ;
F_30 ( & V_77 -> V_52 ) ;
F_31 ( V_77 ) ;
}
F_41 (entry, tmp, &rproc->mappings, node) {
T_4 V_79 ;
V_79 = F_43 ( V_10 -> V_4 , V_77 -> V_18 , V_77 -> V_19 ) ;
if ( V_79 != V_77 -> V_19 ) {
F_4 ( V_6 , L_38 , V_77 -> V_19 ,
V_79 ) ;
}
F_30 ( & V_77 -> V_52 ) ;
F_31 ( V_77 ) ;
}
}
static int F_44 ( struct V_10 * V_10 , const struct V_80 * V_81 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_57 = V_10 -> V_80 ;
struct V_82 * V_83 , * V_84 ;
int V_14 , V_85 ;
if ( ! V_10 -> V_40 )
return - V_16 ;
V_14 = F_45 ( V_10 , V_81 ) ;
if ( V_14 )
return V_14 ;
F_46 ( V_6 , L_39 , V_57 , V_81 -> V_34 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_40 , V_14 ) ;
return V_14 ;
}
V_10 -> V_86 = F_47 ( V_10 , V_81 ) ;
V_83 = F_48 ( V_10 , V_81 , & V_85 ) ;
if ( ! V_83 ) {
V_14 = - V_38 ;
goto V_87;
}
if ( V_10 -> V_88 != F_49 ( 0 , V_83 , V_85 ) ) {
F_4 ( V_6 , L_41 ) ;
V_14 = - V_38 ;
goto V_87;
}
V_14 = F_38 ( V_10 , V_85 , V_89 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_42 , V_14 ) ;
goto V_87;
}
V_14 = F_50 ( V_10 , V_81 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_43 , V_14 ) ;
goto V_87;
}
V_84 = F_51 ( V_10 , V_81 ) ;
if ( ! V_84 )
goto V_87;
memcpy ( V_84 , V_10 -> V_90 , V_85 ) ;
V_14 = V_10 -> V_91 -> V_92 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_44 , V_10 -> V_57 , V_14 ) ;
goto V_87;
}
V_10 -> V_40 = V_84 ;
V_10 -> V_93 = V_94 ;
F_46 ( V_6 , L_45 , V_10 -> V_57 ) ;
return 0 ;
V_87:
F_40 ( V_10 ) ;
F_13 ( V_10 ) ;
return V_14 ;
}
static void F_52 ( const struct V_80 * V_81 , void * V_95 )
{
struct V_10 * V_10 = V_95 ;
struct V_82 * V_83 ;
int V_14 , V_85 ;
if ( F_45 ( V_10 , V_81 ) < 0 )
goto V_64;
V_83 = F_48 ( V_10 , V_81 , & V_85 ) ;
if ( ! V_83 )
goto V_64;
V_10 -> V_88 = F_49 ( 0 , V_83 , V_85 ) ;
V_10 -> V_90 = F_53 ( V_85 , V_37 ) ;
if ( ! V_10 -> V_90 )
goto V_64;
memcpy ( V_10 -> V_90 , V_83 , V_85 ) ;
V_10 -> V_40 = V_10 -> V_90 ;
V_10 -> V_71 = - 1 ;
V_14 = F_38 ( V_10 , V_85 , V_96 ) ;
if ( V_14 )
goto V_64;
V_14 = F_38 ( V_10 , V_85 , V_97 ) ;
V_64:
F_54 ( V_81 ) ;
F_55 ( & V_10 -> V_98 ) ;
}
static int F_56 ( struct V_10 * V_10 )
{
int V_14 ;
F_57 ( & V_10 -> V_98 ) ;
V_14 = F_58 ( V_99 , V_100 ,
V_10 -> V_80 , & V_10 -> V_6 , V_37 ,
V_10 , F_52 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_10 -> V_6 , L_46 , V_14 ) ;
F_55 ( & V_10 -> V_98 ) ;
}
return V_14 ;
}
int F_59 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_101 ;
F_4 ( & V_10 -> V_6 , L_47 , V_10 -> V_57 ) ;
F_57 ( & V_10 -> V_102 ) ;
F_41 (rvdev, rvtmp, &rproc->rvdevs, node)
F_60 ( V_26 ) ;
F_61 ( & V_10 -> V_102 ) ;
F_31 ( V_10 -> V_90 ) ;
return F_56 ( V_10 ) ;
}
static void F_62 ( struct V_103 * V_104 )
{
struct V_10 * V_10 = F_63 ( V_104 , struct V_10 , V_105 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_8 ( V_6 , L_48 , V_106 ) ;
F_64 ( & V_10 -> V_107 ) ;
if ( V_10 -> V_93 == V_108 || V_10 -> V_93 == V_109 ) {
F_65 ( & V_10 -> V_107 ) ;
return;
}
V_10 -> V_93 = V_108 ;
F_4 ( V_6 , L_49 , ++ V_10 -> V_110 ,
V_10 -> V_57 ) ;
F_65 ( & V_10 -> V_107 ) ;
if ( ! V_10 -> V_111 )
F_59 ( V_10 ) ;
}
int F_66 ( struct V_10 * V_10 )
{
const struct V_80 * V_112 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_67 ( L_50 ) ;
return - V_38 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_68 ( & V_10 -> V_107 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_57 , V_14 ) ;
return V_14 ;
}
if ( ! V_10 -> V_80 ) {
F_4 ( V_6 , L_52 , V_106 ) ;
V_14 = - V_38 ;
goto V_113;
}
if ( ! F_69 ( V_6 -> V_13 -> V_114 -> V_115 ) ) {
F_4 ( V_6 , L_53 , V_106 ) ;
V_14 = - V_38 ;
goto V_113;
}
if ( F_70 ( & V_10 -> V_116 ) > 1 ) {
V_14 = 0 ;
goto V_113;
}
F_46 ( V_6 , L_54 , V_10 -> V_57 ) ;
V_14 = F_71 ( & V_112 , V_10 -> V_80 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_55 , V_14 ) ;
goto V_117;
}
V_14 = F_44 ( V_10 , V_112 ) ;
F_54 ( V_112 ) ;
V_117:
if ( V_14 ) {
F_72 ( V_6 -> V_13 -> V_114 -> V_115 ) ;
F_73 ( & V_10 -> V_116 ) ;
}
V_113:
F_65 ( & V_10 -> V_107 ) ;
return V_14 ;
}
void F_74 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_68 ( & V_10 -> V_107 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_57 , V_14 ) ;
return;
}
if ( ! F_75 ( & V_10 -> V_116 ) )
goto V_64;
V_14 = V_10 -> V_91 -> V_118 ( V_10 ) ;
if ( V_14 ) {
F_76 ( & V_10 -> V_116 ) ;
F_4 ( V_6 , L_56 , V_14 ) ;
goto V_64;
}
F_40 ( V_10 ) ;
F_13 ( V_10 ) ;
V_10 -> V_40 = V_10 -> V_90 ;
if ( V_10 -> V_93 == V_108 )
F_55 ( & V_10 -> V_102 ) ;
V_10 -> V_93 = V_109 ;
F_46 ( V_6 , L_57 , V_10 -> V_57 ) ;
V_64:
F_65 ( & V_10 -> V_107 ) ;
if ( ! V_14 )
F_72 ( V_6 -> V_13 -> V_114 -> V_115 ) ;
}
int F_77 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_78 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_46 ( V_6 , L_58 , V_10 -> V_57 ) ;
F_46 ( V_6 , L_59 ) ;
F_46 ( V_6 , L_60 ) ;
F_79 ( V_10 ) ;
return F_56 ( V_10 ) ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_63 ( V_6 , struct V_10 , V_6 ) ;
F_46 ( & V_10 -> V_6 , L_61 , V_10 -> V_57 ) ;
F_81 ( V_10 ) ;
F_82 ( & V_10 -> V_39 ) ;
if ( V_10 -> V_119 >= 0 )
F_83 ( & V_120 , V_10 -> V_119 ) ;
F_31 ( V_10 ) ;
}
struct V_10 * F_84 ( struct V_5 * V_6 , const char * V_57 ,
const struct V_121 * V_91 ,
const char * V_80 , int V_19 )
{
struct V_10 * V_10 ;
char * V_122 , * V_123 = L_62 ;
int V_124 = 0 ;
if ( ! V_6 || ! V_57 || ! V_91 )
return NULL ;
if ( ! V_80 )
V_124 = strlen ( V_57 ) + strlen ( V_123 ) - 2 + 1 ;
V_10 = F_27 ( sizeof( struct V_10 ) + V_19 + V_124 , V_37 ) ;
if ( ! V_10 ) {
F_4 ( V_6 , L_63 , V_106 ) ;
return NULL ;
}
if ( ! V_80 ) {
V_122 = ( char * ) V_10 + sizeof( struct V_10 ) + V_19 ;
snprintf ( V_122 , V_124 , V_123 , V_57 ) ;
} else {
V_122 = ( char * ) V_80 ;
}
V_10 -> V_80 = V_122 ;
V_10 -> V_57 = V_57 ;
V_10 -> V_91 = V_91 ;
V_10 -> V_59 = & V_10 [ 1 ] ;
F_85 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_125 ;
V_10 -> V_119 = F_86 ( & V_120 , 0 , 0 , V_37 ) ;
if ( V_10 -> V_119 < 0 ) {
F_4 ( V_6 , L_64 , V_10 -> V_119 ) ;
F_87 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_88 ( & V_10 -> V_6 , L_65 , V_10 -> V_119 ) ;
F_89 ( & V_10 -> V_116 , 0 ) ;
V_10 -> V_126 = & V_127 ;
F_90 ( & V_10 -> V_107 ) ;
F_91 ( & V_10 -> V_39 ) ;
F_92 ( & V_10 -> V_70 ) ;
F_92 ( & V_10 -> V_65 ) ;
F_92 ( & V_10 -> V_60 ) ;
F_92 ( & V_10 -> V_53 ) ;
F_93 ( & V_10 -> V_105 , F_62 ) ;
F_57 ( & V_10 -> V_102 ) ;
V_10 -> V_93 = V_109 ;
return V_10 ;
}
void F_94 ( struct V_10 * V_10 )
{
F_87 ( & V_10 -> V_6 ) ;
}
int F_95 ( struct V_10 * V_10 )
{
struct V_25 * V_26 , * V_78 ;
if ( ! V_10 )
return - V_38 ;
F_61 ( & V_10 -> V_98 ) ;
F_41 (rvdev, tmp, &rproc->rvdevs, node)
F_60 ( V_26 ) ;
F_31 ( V_10 -> V_90 ) ;
F_96 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_67 ( L_66 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_67 ,
V_10 -> V_57 , F_1 ( type ) ) ;
F_97 ( & V_10 -> V_105 ) ;
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
