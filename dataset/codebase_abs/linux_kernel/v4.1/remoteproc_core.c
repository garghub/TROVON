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
return;
}
void * F_14 ( struct V_10 * V_10 , T_1 V_19 , int V_20 )
{
struct V_21 * V_22 ;
void * V_23 = NULL ;
F_15 (carveout, &rproc->carveouts, node) {
int V_24 = V_19 - V_22 -> V_19 ;
if ( V_24 < 0 )
continue;
if ( V_24 + V_20 > V_22 -> V_20 )
continue;
V_23 = V_22 -> V_25 + V_24 ;
break;
}
return V_23 ;
}
int F_16 ( struct V_26 * V_27 , int V_28 )
{
struct V_10 * V_10 = V_27 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_29 * V_30 = & V_27 -> V_31 [ V_28 ] ;
struct V_32 * V_33 ;
T_2 V_34 ;
void * V_25 ;
int V_14 , V_35 , V_36 ;
V_35 = F_17 ( F_18 ( V_30 -> V_20 , V_30 -> V_37 ) ) ;
V_25 = F_19 ( V_6 -> V_13 , V_35 , & V_34 , V_38 ) ;
if ( ! V_25 ) {
F_4 ( V_6 -> V_13 , L_6 ) ;
return - V_39 ;
}
V_14 = F_20 ( & V_10 -> V_40 , V_30 , 0 , 0 , V_38 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_7 , V_14 ) ;
F_21 ( V_6 -> V_13 , V_35 , V_25 , V_34 ) ;
return V_14 ;
}
V_36 = V_14 ;
F_7 ( V_6 , L_8 , V_28 , V_25 ,
( unsigned long long ) V_34 , V_35 , V_36 ) ;
V_30 -> V_25 = V_25 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_36 = V_36 ;
V_33 = ( void * ) V_10 -> V_41 + V_27 -> V_42 ;
V_33 -> V_31 [ V_28 ] . V_19 = V_34 ;
V_33 -> V_31 [ V_28 ] . V_36 = V_36 ;
return 0 ;
}
static int
F_22 ( struct V_26 * V_27 , struct V_32 * V_33 , int V_28 )
{
struct V_10 * V_10 = V_27 -> V_10 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_43 * V_31 = & V_33 -> V_31 [ V_28 ] ;
struct V_29 * V_30 = & V_27 -> V_31 [ V_28 ] ;
F_7 ( V_6 , L_9 ,
V_28 , V_31 -> V_19 , V_31 -> V_44 , V_31 -> V_37 ) ;
if ( V_31 -> V_45 ) {
F_4 ( V_6 , L_10 ) ;
return - V_39 ;
}
if ( ! V_31 -> V_44 || ! V_31 -> V_37 ) {
F_4 ( V_6 , L_11 ,
V_31 -> V_44 , V_31 -> V_37 ) ;
return - V_39 ;
}
V_30 -> V_20 = V_31 -> V_44 ;
V_30 -> V_37 = V_31 -> V_37 ;
V_30 -> V_27 = V_27 ;
return 0 ;
}
void F_23 ( struct V_29 * V_30 )
{
int V_35 = F_17 ( F_18 ( V_30 -> V_20 , V_30 -> V_37 ) ) ;
struct V_10 * V_10 = V_30 -> V_27 -> V_10 ;
int V_46 = V_30 -> V_27 -> V_31 - V_30 ;
struct V_32 * V_33 ;
F_21 ( V_10 -> V_6 . V_13 , V_35 , V_30 -> V_25 , V_30 -> V_34 ) ;
F_24 ( & V_10 -> V_40 , V_30 -> V_36 ) ;
V_33 = ( void * ) V_10 -> V_41 + V_30 -> V_27 -> V_42 ;
V_33 -> V_31 [ V_46 ] . V_19 = 0 ;
V_33 -> V_31 [ V_46 ] . V_36 = - 1 ;
}
static int F_25 ( struct V_10 * V_10 , struct V_32 * V_33 ,
int V_24 , int V_47 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_26 * V_27 ;
int V_28 , V_14 ;
if ( sizeof( * V_33 ) + V_33 -> V_48 * sizeof( struct V_43 )
+ V_33 -> V_49 > V_47 ) {
F_4 ( V_6 , L_12 ) ;
return - V_39 ;
}
if ( V_33 -> V_45 [ 0 ] || V_33 -> V_45 [ 1 ] ) {
F_4 ( V_6 , L_13 ) ;
return - V_39 ;
}
F_7 ( V_6 , L_14 ,
V_33 -> V_50 , V_33 -> V_51 , V_33 -> V_49 , V_33 -> V_48 ) ;
if ( V_33 -> V_48 > F_2 ( V_27 -> V_31 ) ) {
F_4 ( V_6 , L_15 , V_33 -> V_48 ) ;
return - V_39 ;
}
V_27 = F_26 ( sizeof( struct V_26 ) , V_38 ) ;
if ( ! V_27 )
return - V_17 ;
V_27 -> V_10 = V_10 ;
for ( V_28 = 0 ; V_28 < V_33 -> V_48 ; V_28 ++ ) {
V_14 = F_22 ( V_27 , V_33 , V_28 ) ;
if ( V_14 )
goto V_52;
}
V_27 -> V_42 = V_24 ;
F_27 ( & V_27 -> V_53 , & V_10 -> V_54 ) ;
V_14 = F_28 ( V_27 , V_33 -> V_50 ) ;
if ( V_14 )
goto V_55;
return 0 ;
V_55:
F_29 ( & V_27 -> V_53 ) ;
V_52:
F_30 ( V_27 ) ;
return V_14 ;
}
static int F_31 ( struct V_10 * V_10 , struct V_56 * V_33 ,
int V_24 , int V_47 )
{
struct V_21 * V_57 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
void * V_23 ;
char V_58 [ 15 ] ;
if ( sizeof( * V_33 ) > V_47 ) {
F_4 ( V_6 , L_16 ) ;
return - V_39 ;
}
if ( V_33 -> V_45 ) {
F_4 ( V_6 , L_17 ) ;
return - V_39 ;
}
V_23 = F_14 ( V_10 , V_33 -> V_19 , V_33 -> V_20 ) ;
if ( ! V_23 ) {
F_4 ( V_6 , L_18 ) ;
return - V_39 ;
}
V_57 = F_26 ( sizeof( * V_57 ) , V_38 ) ;
if ( ! V_57 ) {
F_4 ( V_6 , L_19 ) ;
return - V_17 ;
}
V_57 -> V_20 = V_33 -> V_20 ;
V_57 -> V_25 = V_23 ;
snprintf ( V_58 , sizeof( V_58 ) , L_20 , V_10 -> V_59 ) ;
V_57 -> V_60 = F_32 ( V_58 , V_10 , V_57 ) ;
if ( ! V_57 -> V_60 ) {
V_57 -> V_25 = NULL ;
F_30 ( V_57 ) ;
return - V_39 ;
}
F_27 ( & V_57 -> V_53 , & V_10 -> V_61 ) ;
V_10 -> V_59 ++ ;
F_7 ( V_6 , L_21 , V_58 , V_23 ,
V_33 -> V_19 , V_33 -> V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_10 , struct V_62 * V_33 ,
int V_24 , int V_47 )
{
struct V_21 * V_63 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
if ( ! V_10 -> V_4 )
return - V_39 ;
if ( sizeof( * V_33 ) > V_47 ) {
F_4 ( V_6 , L_22 ) ;
return - V_39 ;
}
if ( V_33 -> V_45 ) {
F_4 ( V_6 , L_23 ) ;
return - V_39 ;
}
V_63 = F_26 ( sizeof( * V_63 ) , V_38 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_24 ) ;
return - V_17 ;
}
V_14 = F_34 ( V_10 -> V_4 , V_33 -> V_19 , V_33 -> V_64 , V_33 -> V_20 , V_33 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_25 , V_14 ) ;
goto V_65;
}
V_63 -> V_19 = V_33 -> V_19 ;
V_63 -> V_20 = V_33 -> V_20 ;
F_27 ( & V_63 -> V_53 , & V_10 -> V_66 ) ;
F_7 ( V_6 , L_26 ,
V_33 -> V_64 , V_33 -> V_19 , V_33 -> V_20 ) ;
return 0 ;
V_65:
F_30 ( V_63 ) ;
return V_14 ;
}
static int F_35 ( struct V_10 * V_10 ,
struct V_67 * V_33 ,
int V_24 , int V_47 )
{
struct V_21 * V_22 , * V_63 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
T_2 V_34 ;
void * V_25 ;
int V_14 ;
if ( sizeof( * V_33 ) > V_47 ) {
F_4 ( V_6 , L_27 ) ;
return - V_39 ;
}
if ( V_33 -> V_45 ) {
F_4 ( V_6 , L_28 ) ;
return - V_39 ;
}
F_7 ( V_6 , L_29 ,
V_33 -> V_19 , V_33 -> V_64 , V_33 -> V_20 , V_33 -> V_8 ) ;
V_22 = F_26 ( sizeof( * V_22 ) , V_38 ) ;
if ( ! V_22 ) {
F_4 ( V_6 , L_30 ) ;
return - V_17 ;
}
V_25 = F_19 ( V_6 -> V_13 , V_33 -> V_20 , & V_34 , V_38 ) ;
if ( ! V_25 ) {
F_4 ( V_6 -> V_13 , L_31 , V_33 -> V_20 ) ;
V_14 = - V_17 ;
goto V_68;
}
F_7 ( V_6 , L_32 , V_25 ,
( unsigned long long ) V_34 , V_33 -> V_20 ) ;
if ( V_10 -> V_4 ) {
V_63 = F_26 ( sizeof( * V_63 ) , V_38 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_24 ) ;
V_14 = - V_17 ;
goto V_69;
}
V_14 = F_34 ( V_10 -> V_4 , V_33 -> V_19 , V_34 , V_33 -> V_20 ,
V_33 -> V_8 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_33 , V_14 ) ;
goto V_70;
}
V_63 -> V_19 = V_33 -> V_19 ;
V_63 -> V_20 = V_33 -> V_20 ;
F_27 ( & V_63 -> V_53 , & V_10 -> V_66 ) ;
F_7 ( V_6 , L_34 ,
V_33 -> V_19 , ( unsigned long long ) V_34 ) ;
}
V_33 -> V_64 = V_34 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_20 = V_33 -> V_20 ;
V_22 -> V_34 = V_34 ;
V_22 -> V_19 = V_33 -> V_19 ;
F_27 ( & V_22 -> V_53 , & V_10 -> V_71 ) ;
return 0 ;
V_70:
F_30 ( V_63 ) ;
V_69:
F_21 ( V_6 -> V_13 , V_33 -> V_20 , V_25 , V_34 ) ;
V_68:
F_30 ( V_22 ) ;
return V_14 ;
}
static int F_36 ( struct V_10 * V_10 , struct V_32 * V_33 ,
int V_24 , int V_47 )
{
V_10 -> V_72 += V_33 -> V_48 ;
return 0 ;
}
static int F_37 ( struct V_10 * V_10 , int V_20 ,
T_3 V_73 [ V_74 ] )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
T_3 V_75 ;
int V_14 = 0 , V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_41 -> V_44 ; V_28 ++ ) {
int V_24 = V_10 -> V_41 -> V_24 [ V_28 ] ;
struct V_76 * V_77 = ( void * ) V_10 -> V_41 + V_24 ;
int V_47 = V_20 - V_24 - sizeof( * V_77 ) ;
void * V_33 = ( void * ) V_77 + sizeof( * V_77 ) ;
if ( V_47 < 0 ) {
F_4 ( V_6 , L_35 ) ;
return - V_39 ;
}
F_7 ( V_6 , L_36 , V_77 -> type ) ;
if ( V_77 -> type >= V_74 ) {
F_38 ( V_6 , L_37 , V_77 -> type ) ;
continue;
}
V_75 = V_73 [ V_77 -> type ] ;
if ( ! V_75 )
continue;
V_14 = V_75 ( V_10 , V_33 , V_24 + sizeof( * V_77 ) , V_47 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static void F_39 ( struct V_10 * V_10 )
{
struct V_21 * V_78 , * V_79 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_40 (entry, tmp, &rproc->traces, node) {
F_41 ( V_78 -> V_60 ) ;
V_10 -> V_59 -- ;
F_29 ( & V_78 -> V_53 ) ;
F_30 ( V_78 ) ;
}
F_40 (entry, tmp, &rproc->mappings, node) {
T_4 V_80 ;
V_80 = F_42 ( V_10 -> V_4 , V_78 -> V_19 , V_78 -> V_20 ) ;
if ( V_80 != V_78 -> V_20 ) {
F_4 ( V_6 , L_38 , V_78 -> V_20 ,
V_80 ) ;
}
F_29 ( & V_78 -> V_53 ) ;
F_30 ( V_78 ) ;
}
F_40 (entry, tmp, &rproc->carveouts, node) {
F_21 ( V_6 -> V_13 , V_78 -> V_20 , V_78 -> V_25 , V_78 -> V_34 ) ;
F_29 ( & V_78 -> V_53 ) ;
F_30 ( V_78 ) ;
}
}
static int F_43 ( struct V_10 * V_10 , const struct V_81 * V_82 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
const char * V_58 = V_10 -> V_81 ;
struct V_83 * V_84 , * V_85 ;
int V_14 , V_86 ;
if ( ! V_10 -> V_41 )
return - V_17 ;
V_14 = F_44 ( V_10 , V_82 ) ;
if ( V_14 )
return V_14 ;
F_45 ( V_6 , L_39 , V_58 , V_82 -> V_35 ) ;
V_14 = F_6 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_40 , V_14 ) ;
return V_14 ;
}
V_10 -> V_87 = F_46 ( V_10 , V_82 ) ;
V_14 = - V_39 ;
V_84 = F_47 ( V_10 , V_82 , & V_86 ) ;
if ( ! V_84 ) {
goto V_88;
}
if ( V_10 -> V_89 != F_48 ( 0 , V_84 , V_86 ) ) {
F_4 ( V_6 , L_41 ) ;
goto V_88;
}
V_14 = F_37 ( V_10 , V_86 , V_90 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_42 , V_14 ) ;
goto V_88;
}
V_14 = F_49 ( V_10 , V_82 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_43 , V_14 ) ;
goto V_88;
}
V_85 = F_50 ( V_10 , V_82 ) ;
if ( ! V_85 ) {
V_14 = - V_39 ;
goto V_88;
}
memcpy ( V_85 , V_10 -> V_91 , V_86 ) ;
V_14 = V_10 -> V_92 -> V_93 ( V_10 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_44 , V_10 -> V_58 , V_14 ) ;
goto V_88;
}
V_10 -> V_41 = V_85 ;
V_10 -> V_94 = V_95 ;
F_45 ( V_6 , L_45 , V_10 -> V_58 ) ;
return 0 ;
V_88:
F_39 ( V_10 ) ;
F_12 ( V_10 ) ;
return V_14 ;
}
static void F_51 ( const struct V_81 * V_82 , void * V_96 )
{
struct V_10 * V_10 = V_96 ;
struct V_83 * V_84 ;
int V_14 , V_86 ;
if ( F_44 ( V_10 , V_82 ) < 0 )
goto V_65;
V_84 = F_47 ( V_10 , V_82 , & V_86 ) ;
if ( ! V_84 )
goto V_65;
V_10 -> V_89 = F_48 ( 0 , V_84 , V_86 ) ;
V_10 -> V_91 = F_52 ( V_84 , V_86 , V_38 ) ;
if ( ! V_10 -> V_91 )
goto V_65;
V_10 -> V_41 = V_10 -> V_91 ;
V_10 -> V_72 = - 1 ;
V_14 = F_37 ( V_10 , V_86 , V_97 ) ;
if ( V_14 )
goto V_65;
V_14 = F_37 ( V_10 , V_86 , V_98 ) ;
V_65:
F_53 ( V_82 ) ;
F_54 ( & V_10 -> V_99 ) ;
}
static int F_55 ( struct V_10 * V_10 )
{
int V_14 ;
F_56 ( & V_10 -> V_99 ) ;
V_14 = F_57 ( V_100 , V_101 ,
V_10 -> V_81 , & V_10 -> V_6 , V_38 ,
V_10 , F_51 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_10 -> V_6 , L_46 , V_14 ) ;
F_54 ( & V_10 -> V_99 ) ;
}
return V_14 ;
}
int F_58 ( struct V_10 * V_10 )
{
struct V_26 * V_27 , * V_102 ;
F_4 ( & V_10 -> V_6 , L_47 , V_10 -> V_58 ) ;
F_56 ( & V_10 -> V_103 ) ;
F_40 (rvdev, rvtmp, &rproc->rvdevs, node)
F_59 ( V_27 ) ;
F_60 ( & V_10 -> V_103 ) ;
F_30 ( V_10 -> V_91 ) ;
return F_55 ( V_10 ) ;
}
static void F_61 ( struct V_104 * V_105 )
{
struct V_10 * V_10 = F_62 ( V_105 , struct V_10 , V_106 ) ;
struct V_5 * V_6 = & V_10 -> V_6 ;
F_7 ( V_6 , L_48 , V_107 ) ;
F_63 ( & V_10 -> V_108 ) ;
if ( V_10 -> V_94 == V_109 || V_10 -> V_94 == V_110 ) {
F_64 ( & V_10 -> V_108 ) ;
return;
}
V_10 -> V_94 = V_109 ;
F_4 ( V_6 , L_49 , ++ V_10 -> V_111 ,
V_10 -> V_58 ) ;
F_64 ( & V_10 -> V_108 ) ;
if ( ! V_10 -> V_112 )
F_58 ( V_10 ) ;
}
int F_65 ( struct V_10 * V_10 )
{
const struct V_81 * V_113 ;
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_10 ) {
F_66 ( L_50 ) ;
return - V_39 ;
}
V_6 = & V_10 -> V_6 ;
V_14 = F_67 ( & V_10 -> V_108 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_58 , V_14 ) ;
return V_14 ;
}
if ( ! V_10 -> V_81 ) {
F_4 ( V_6 , L_52 , V_107 ) ;
V_14 = - V_39 ;
goto V_114;
}
if ( ! F_68 ( V_6 -> V_13 -> V_115 -> V_116 ) ) {
F_4 ( V_6 , L_53 , V_107 ) ;
V_14 = - V_39 ;
goto V_114;
}
if ( F_69 ( & V_10 -> V_117 ) > 1 ) {
V_14 = 0 ;
goto V_114;
}
F_45 ( V_6 , L_54 , V_10 -> V_58 ) ;
V_14 = F_70 ( & V_113 , V_10 -> V_81 , V_6 ) ;
if ( V_14 < 0 ) {
F_4 ( V_6 , L_55 , V_14 ) ;
goto V_118;
}
V_14 = F_43 ( V_10 , V_113 ) ;
F_53 ( V_113 ) ;
V_118:
if ( V_14 ) {
F_71 ( V_6 -> V_13 -> V_115 -> V_116 ) ;
F_72 ( & V_10 -> V_117 ) ;
}
V_114:
F_64 ( & V_10 -> V_108 ) ;
return V_14 ;
}
void F_73 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_67 ( & V_10 -> V_108 ) ;
if ( V_14 ) {
F_4 ( V_6 , L_51 , V_10 -> V_58 , V_14 ) ;
return;
}
if ( ! F_74 ( & V_10 -> V_117 ) )
goto V_65;
V_14 = V_10 -> V_92 -> V_119 ( V_10 ) ;
if ( V_14 ) {
F_75 ( & V_10 -> V_117 ) ;
F_4 ( V_6 , L_56 , V_14 ) ;
goto V_65;
}
F_39 ( V_10 ) ;
F_12 ( V_10 ) ;
V_10 -> V_41 = V_10 -> V_91 ;
if ( V_10 -> V_94 == V_109 )
F_54 ( & V_10 -> V_103 ) ;
V_10 -> V_94 = V_110 ;
F_45 ( V_6 , L_57 , V_10 -> V_58 ) ;
V_65:
F_64 ( & V_10 -> V_108 ) ;
if ( ! V_14 )
F_71 ( V_6 -> V_13 -> V_115 -> V_116 ) ;
}
int F_76 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = & V_10 -> V_6 ;
int V_14 ;
V_14 = F_77 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_45 ( V_6 , L_58 , V_10 -> V_58 ) ;
F_45 ( V_6 , L_59 ) ;
F_45 ( V_6 , L_60 ) ;
F_78 ( V_10 ) ;
return F_55 ( V_10 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_10 * V_10 = F_62 ( V_6 , struct V_10 , V_6 ) ;
F_45 ( & V_10 -> V_6 , L_61 , V_10 -> V_58 ) ;
F_80 ( V_10 ) ;
F_81 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_120 >= 0 )
F_82 ( & V_121 , V_10 -> V_120 ) ;
F_30 ( V_10 ) ;
}
struct V_10 * F_83 ( struct V_5 * V_6 , const char * V_58 ,
const struct V_122 * V_92 ,
const char * V_81 , int V_20 )
{
struct V_10 * V_10 ;
char * V_123 , * V_124 = L_62 ;
int V_125 = 0 ;
if ( ! V_6 || ! V_58 || ! V_92 )
return NULL ;
if ( ! V_81 )
V_125 = strlen ( V_58 ) + strlen ( V_124 ) - 2 + 1 ;
V_10 = F_26 ( sizeof( struct V_10 ) + V_20 + V_125 , V_38 ) ;
if ( ! V_10 ) {
F_4 ( V_6 , L_63 , V_107 ) ;
return NULL ;
}
if ( ! V_81 ) {
V_123 = ( char * ) V_10 + sizeof( struct V_10 ) + V_20 ;
snprintf ( V_123 , V_125 , V_124 , V_58 ) ;
} else {
V_123 = ( char * ) V_81 ;
}
V_10 -> V_81 = V_123 ;
V_10 -> V_58 = V_58 ;
V_10 -> V_92 = V_92 ;
V_10 -> V_60 = & V_10 [ 1 ] ;
F_84 ( & V_10 -> V_6 ) ;
V_10 -> V_6 . V_13 = V_6 ;
V_10 -> V_6 . type = & V_126 ;
V_10 -> V_120 = F_85 ( & V_121 , 0 , 0 , V_38 ) ;
if ( V_10 -> V_120 < 0 ) {
F_4 ( V_6 , L_64 , V_10 -> V_120 ) ;
F_86 ( & V_10 -> V_6 ) ;
return NULL ;
}
F_87 ( & V_10 -> V_6 , L_65 , V_10 -> V_120 ) ;
F_88 ( & V_10 -> V_117 , 0 ) ;
V_10 -> V_127 = & V_128 ;
F_89 ( & V_10 -> V_108 ) ;
F_90 ( & V_10 -> V_40 ) ;
F_91 ( & V_10 -> V_71 ) ;
F_91 ( & V_10 -> V_66 ) ;
F_91 ( & V_10 -> V_61 ) ;
F_91 ( & V_10 -> V_54 ) ;
F_92 ( & V_10 -> V_106 , F_61 ) ;
F_56 ( & V_10 -> V_103 ) ;
V_10 -> V_94 = V_110 ;
return V_10 ;
}
void F_93 ( struct V_10 * V_10 )
{
F_86 ( & V_10 -> V_6 ) ;
}
int F_94 ( struct V_10 * V_10 )
{
struct V_26 * V_27 , * V_79 ;
if ( ! V_10 )
return - V_39 ;
F_60 ( & V_10 -> V_99 ) ;
F_40 (rvdev, tmp, &rproc->rvdevs, node)
F_59 ( V_27 ) ;
F_30 ( V_10 -> V_91 ) ;
F_95 ( & V_10 -> V_6 ) ;
return 0 ;
}
void F_5 ( struct V_10 * V_10 , enum V_1 type )
{
if ( ! V_10 ) {
F_66 ( L_66 ) ;
return;
}
F_4 ( & V_10 -> V_6 , L_67 ,
V_10 -> V_58 , F_1 ( type ) ) ;
F_96 ( & V_10 -> V_106 ) ;
}
static int T_5 F_97 ( void )
{
F_98 () ;
return 0 ;
}
static void T_6 F_99 ( void )
{
F_100 () ;
}
