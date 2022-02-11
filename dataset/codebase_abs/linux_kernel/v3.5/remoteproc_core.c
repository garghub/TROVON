static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( V_4 , L_1 , V_5 , V_6 ) ;
return - V_8 ;
}
static int F_3 ( struct V_9 * V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 ;
if ( ! F_4 ( V_4 -> V_11 ) ) {
F_5 ( V_4 , L_2 ) ;
return 0 ;
}
V_2 = F_6 ( V_4 -> V_11 ) ;
if ( ! V_2 ) {
F_2 ( V_4 , L_3 ) ;
return - V_12 ;
}
F_7 ( V_2 , F_1 , V_9 ) ;
V_10 = F_8 ( V_2 , V_4 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_4 , V_10 ) ;
goto V_13;
}
V_9 -> V_2 = V_2 ;
return 0 ;
V_13:
F_9 ( V_2 ) ;
return V_10 ;
}
static void F_10 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_9 -> V_4 ;
if ( ! V_2 )
return;
F_11 ( V_2 , V_4 ) ;
F_9 ( V_2 ) ;
return;
}
static void * F_12 ( struct V_9 * V_9 , T_1 V_14 , int V_15 )
{
struct V_16 * V_17 ;
void * V_18 = NULL ;
F_13 (carveout, &rproc->carveouts, node) {
int V_19 = V_14 - V_17 -> V_14 ;
if ( V_19 < 0 )
continue;
if ( V_19 + V_15 > V_17 -> V_15 )
continue;
V_18 = V_17 -> V_20 + V_19 ;
break;
}
return V_18 ;
}
static int
F_14 ( struct V_9 * V_9 , const T_2 * V_21 , T_3 V_15 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 , V_10 = 0 ;
V_23 = (struct V_22 * ) V_21 ;
V_25 = (struct V_24 * ) ( V_21 + V_23 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_23 -> V_28 ; V_26 ++ , V_25 ++ ) {
T_4 V_14 = V_25 -> V_29 ;
T_4 V_30 = V_25 -> V_31 ;
T_4 V_32 = V_25 -> V_33 ;
T_4 V_19 = V_25 -> V_34 ;
void * V_18 ;
if ( V_25 -> V_35 != V_36 )
continue;
F_5 ( V_4 , L_5 ,
V_25 -> V_35 , V_14 , V_30 , V_32 ) ;
if ( V_32 > V_30 ) {
F_2 ( V_4 , L_6 ,
V_32 , V_30 ) ;
V_10 = - V_37 ;
break;
}
if ( V_19 + V_32 > V_15 ) {
F_2 ( V_4 , L_7 ,
V_19 + V_32 , V_15 ) ;
V_10 = - V_37 ;
break;
}
V_18 = F_12 ( V_9 , V_14 , V_30 ) ;
if ( ! V_18 ) {
F_2 ( V_4 , L_8 , V_14 , V_30 ) ;
V_10 = - V_37 ;
break;
}
if ( V_25 -> V_33 )
memcpy ( V_18 , V_21 + V_25 -> V_34 , V_32 ) ;
if ( V_30 > V_32 )
memset ( V_18 + V_32 , 0 , V_30 - V_32 ) ;
}
return V_10 ;
}
static int
F_15 ( struct V_38 * V_39 , struct V_40 * V_41 , int V_26 )
{
struct V_9 * V_9 = V_39 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_4 ;
struct V_42 * V_43 = & V_41 -> V_43 [ V_26 ] ;
T_5 V_44 ;
void * V_20 ;
int V_10 , V_45 , V_46 ;
F_5 ( V_4 , L_9 ,
V_26 , V_43 -> V_14 , V_43 -> V_47 , V_43 -> V_48 ) ;
if ( V_43 -> V_49 ) {
F_2 ( V_4 , L_10 ) ;
return - V_37 ;
}
if ( ! V_43 -> V_47 || ! V_43 -> V_48 ) {
F_2 ( V_4 , L_11 ,
V_43 -> V_47 , V_43 -> V_48 ) ;
return - V_37 ;
}
V_45 = F_16 ( F_17 ( V_43 -> V_47 , V_43 -> V_48 ) ) ;
if ( ! F_18 ( & V_9 -> V_50 , V_51 ) ) {
F_2 ( V_4 , L_12 ) ;
return - V_12 ;
}
V_20 = F_19 ( V_4 , V_45 , & V_44 , V_51 ) ;
if ( ! V_20 ) {
F_2 ( V_4 , L_13 ) ;
return - V_37 ;
}
V_10 = F_20 ( & V_9 -> V_50 , & V_39 -> V_43 [ V_26 ] , & V_46 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_14 , V_10 ) ;
F_21 ( V_4 , V_45 , V_20 , V_44 ) ;
return V_10 ;
}
V_43 -> V_14 = V_44 ;
V_43 -> V_46 = V_46 ;
F_5 ( V_4 , L_15 , V_26 , V_20 ,
V_44 , V_45 , V_46 ) ;
V_39 -> V_43 [ V_26 ] . V_15 = V_43 -> V_47 ;
V_39 -> V_43 [ V_26 ] . V_48 = V_43 -> V_48 ;
V_39 -> V_43 [ V_26 ] . V_20 = V_20 ;
V_39 -> V_43 [ V_26 ] . V_44 = V_44 ;
V_39 -> V_43 [ V_26 ] . V_46 = V_46 ;
V_39 -> V_43 [ V_26 ] . V_39 = V_39 ;
return 0 ;
}
static void F_22 ( struct V_38 * V_39 , int V_26 )
{
struct V_9 * V_9 = V_39 -> V_9 ;
for ( V_26 -- ; V_26 >= 0 ; V_26 -- ) {
struct V_52 * V_53 = & V_39 -> V_43 [ V_26 ] ;
int V_45 = F_16 ( F_17 ( V_53 -> V_15 , V_53 -> V_48 ) ) ;
F_21 ( V_9 -> V_4 , V_45 , V_53 -> V_20 , V_53 -> V_44 ) ;
F_23 ( & V_9 -> V_50 , V_53 -> V_46 ) ;
}
}
static int F_24 ( struct V_9 * V_9 , struct V_40 * V_41 ,
int V_54 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
struct V_38 * V_39 ;
int V_26 , V_10 ;
if ( sizeof( * V_41 ) + V_41 -> V_55 * sizeof( struct V_42 )
+ V_41 -> V_56 > V_54 ) {
F_2 ( V_9 -> V_4 , L_16 ) ;
return - V_37 ;
}
if ( V_41 -> V_49 [ 0 ] || V_41 -> V_49 [ 1 ] ) {
F_2 ( V_4 , L_17 ) ;
return - V_37 ;
}
F_5 ( V_4 , L_18 ,
V_41 -> V_57 , V_41 -> V_58 , V_41 -> V_56 , V_41 -> V_55 ) ;
if ( V_41 -> V_55 > F_25 ( V_39 -> V_43 ) ) {
F_2 ( V_4 , L_19 , V_41 -> V_55 ) ;
return - V_37 ;
}
V_39 = F_26 ( sizeof( struct V_38 ) , V_51 ) ;
if ( ! V_39 )
return - V_12 ;
V_39 -> V_9 = V_9 ;
for ( V_26 = 0 ; V_26 < V_41 -> V_55 ; V_26 ++ ) {
V_10 = F_15 ( V_39 , V_41 , V_26 ) ;
if ( V_10 )
goto V_59;
}
V_39 -> V_58 = V_41 -> V_58 ;
F_27 ( & V_39 -> V_60 , & V_9 -> V_61 ) ;
V_10 = F_28 ( V_39 , V_41 -> V_57 ) ;
if ( V_10 )
goto V_59;
return 0 ;
V_59:
F_22 ( V_39 , V_26 ) ;
F_29 ( V_39 ) ;
return V_10 ;
}
static int F_30 ( struct V_9 * V_9 , struct V_62 * V_41 ,
int V_54 )
{
struct V_16 * V_63 ;
struct V_3 * V_4 = V_9 -> V_4 ;
void * V_18 ;
char V_64 [ 15 ] ;
if ( sizeof( * V_41 ) > V_54 ) {
F_2 ( V_9 -> V_4 , L_20 ) ;
return - V_37 ;
}
if ( V_41 -> V_49 ) {
F_2 ( V_4 , L_21 ) ;
return - V_37 ;
}
V_18 = F_12 ( V_9 , V_41 -> V_14 , V_41 -> V_15 ) ;
if ( ! V_18 ) {
F_2 ( V_4 , L_22 ) ;
return - V_37 ;
}
V_63 = F_26 ( sizeof( * V_63 ) , V_51 ) ;
if ( ! V_63 ) {
F_2 ( V_4 , L_23 ) ;
return - V_12 ;
}
V_63 -> V_15 = V_41 -> V_15 ;
V_63 -> V_20 = V_18 ;
snprintf ( V_64 , sizeof( V_64 ) , L_24 , V_9 -> V_65 ) ;
V_63 -> V_66 = F_31 ( V_64 , V_9 , V_63 ) ;
if ( ! V_63 -> V_66 ) {
V_63 -> V_20 = NULL ;
F_29 ( V_63 ) ;
return - V_37 ;
}
F_27 ( & V_63 -> V_60 , & V_9 -> V_67 ) ;
V_9 -> V_65 ++ ;
F_5 ( V_4 , L_25 , V_64 , V_18 ,
V_41 -> V_14 , V_41 -> V_15 ) ;
return 0 ;
}
static int F_32 ( struct V_9 * V_9 , struct V_68 * V_41 ,
int V_54 )
{
struct V_16 * V_69 ;
int V_10 ;
if ( ! V_9 -> V_2 )
return - V_37 ;
if ( sizeof( * V_41 ) > V_54 ) {
F_2 ( V_9 -> V_4 , L_26 ) ;
return - V_37 ;
}
if ( V_41 -> V_49 ) {
F_2 ( V_9 -> V_4 , L_27 ) ;
return - V_37 ;
}
V_69 = F_26 ( sizeof( * V_69 ) , V_51 ) ;
if ( ! V_69 ) {
F_2 ( V_9 -> V_4 , L_28 ) ;
return - V_12 ;
}
V_10 = F_33 ( V_9 -> V_2 , V_41 -> V_14 , V_41 -> V_70 , V_41 -> V_15 , V_41 -> V_6 ) ;
if ( V_10 ) {
F_2 ( V_9 -> V_4 , L_29 , V_10 ) ;
goto V_71;
}
V_69 -> V_14 = V_41 -> V_14 ;
V_69 -> V_15 = V_41 -> V_15 ;
F_27 ( & V_69 -> V_60 , & V_9 -> V_72 ) ;
F_5 ( V_9 -> V_4 , L_30 ,
V_41 -> V_70 , V_41 -> V_14 , V_41 -> V_15 ) ;
return 0 ;
V_71:
F_29 ( V_69 ) ;
return V_10 ;
}
static int F_34 ( struct V_9 * V_9 ,
struct V_73 * V_41 , int V_54 )
{
struct V_16 * V_17 , * V_69 ;
struct V_3 * V_4 = V_9 -> V_4 ;
T_5 V_44 ;
void * V_20 ;
int V_10 ;
if ( sizeof( * V_41 ) > V_54 ) {
F_2 ( V_9 -> V_4 , L_31 ) ;
return - V_37 ;
}
if ( V_41 -> V_49 ) {
F_2 ( V_4 , L_32 ) ;
return - V_37 ;
}
F_5 ( V_4 , L_33 ,
V_41 -> V_14 , V_41 -> V_70 , V_41 -> V_15 , V_41 -> V_6 ) ;
V_69 = F_26 ( sizeof( * V_69 ) , V_51 ) ;
if ( ! V_69 ) {
F_2 ( V_4 , L_28 ) ;
return - V_12 ;
}
V_17 = F_26 ( sizeof( * V_17 ) , V_51 ) ;
if ( ! V_17 ) {
F_2 ( V_4 , L_34 ) ;
V_10 = - V_12 ;
goto V_74;
}
V_20 = F_19 ( V_4 , V_41 -> V_15 , & V_44 , V_51 ) ;
if ( ! V_20 ) {
F_2 ( V_4 , L_35 , V_41 -> V_15 ) ;
V_10 = - V_12 ;
goto V_75;
}
F_5 ( V_4 , L_36 , V_20 , V_44 , V_41 -> V_15 ) ;
if ( V_9 -> V_2 ) {
V_10 = F_33 ( V_9 -> V_2 , V_41 -> V_14 , V_44 , V_41 -> V_15 ,
V_41 -> V_6 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_37 , V_10 ) ;
goto V_76;
}
V_69 -> V_14 = V_41 -> V_14 ;
V_69 -> V_15 = V_41 -> V_15 ;
F_27 ( & V_69 -> V_60 , & V_9 -> V_72 ) ;
F_5 ( V_4 , L_38 , V_41 -> V_14 , V_44 ) ;
V_41 -> V_70 = V_44 ;
}
V_17 -> V_20 = V_20 ;
V_17 -> V_15 = V_41 -> V_15 ;
V_17 -> V_44 = V_44 ;
V_17 -> V_14 = V_41 -> V_14 ;
F_27 ( & V_17 -> V_60 , & V_9 -> V_77 ) ;
return 0 ;
V_76:
F_21 ( V_4 , V_41 -> V_15 , V_20 , V_44 ) ;
V_75:
F_29 ( V_17 ) ;
V_74:
F_29 ( V_69 ) ;
return V_10 ;
}
static int
F_35 ( struct V_9 * V_9 , struct V_78 * V_79 , int V_15 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
T_6 V_80 ;
int V_10 = 0 , V_26 ;
for ( V_26 = 0 ; V_26 < V_79 -> V_47 ; V_26 ++ ) {
int V_19 = V_79 -> V_19 [ V_26 ] ;
struct V_81 * V_82 = ( void * ) V_79 + V_19 ;
int V_54 = V_15 - V_19 - sizeof( * V_82 ) ;
void * V_41 = ( void * ) V_82 + sizeof( * V_82 ) ;
if ( V_54 < 0 ) {
F_2 ( V_4 , L_39 ) ;
return - V_37 ;
}
F_5 ( V_4 , L_40 , V_82 -> type ) ;
if ( V_82 -> type >= V_83 ) {
F_36 ( V_4 , L_41 , V_82 -> type ) ;
continue;
}
V_80 = V_84 [ V_82 -> type ] ;
if ( ! V_80 )
continue;
V_10 = V_80 ( V_9 , V_41 , V_54 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_37 ( struct V_9 * V_9 , struct V_78 * V_79 , int V_15 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 = 0 , V_26 ;
for ( V_26 = 0 ; V_26 < V_79 -> V_47 ; V_26 ++ ) {
int V_19 = V_79 -> V_19 [ V_26 ] ;
struct V_81 * V_82 = ( void * ) V_79 + V_19 ;
int V_54 = V_15 - V_19 - sizeof( * V_82 ) ;
struct V_40 * V_85 ;
if ( V_54 < 0 ) {
F_2 ( V_4 , L_39 ) ;
return - V_37 ;
}
F_5 ( V_4 , L_42 , V_86 , V_82 -> type ) ;
if ( V_82 -> type != V_87 )
continue;
V_85 = (struct V_40 * ) V_82 -> V_88 ;
V_10 = F_24 ( V_9 , V_85 , V_54 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static struct V_78 *
F_38 ( struct V_9 * V_9 , const T_2 * V_21 , T_3 V_15 ,
int * V_89 )
{
struct V_22 * V_23 ;
struct V_90 * V_91 ;
const char * V_92 ;
struct V_3 * V_4 = V_9 -> V_4 ;
struct V_78 * V_79 = NULL ;
int V_26 ;
V_23 = (struct V_22 * ) V_21 ;
V_91 = (struct V_90 * ) ( V_21 + V_23 -> V_93 ) ;
V_92 = V_21 + V_91 [ V_23 -> V_94 ] . V_95 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_96 ; V_26 ++ , V_91 ++ ) {
int V_45 = V_91 -> V_97 ;
int V_19 = V_91 -> V_95 ;
if ( strcmp ( V_92 + V_91 -> V_98 , L_43 ) )
continue;
V_79 = (struct V_78 * ) ( V_21 + V_19 ) ;
if ( V_19 + V_45 > V_15 ) {
F_2 ( V_4 , L_44 ) ;
return NULL ;
}
if ( sizeof( struct V_78 ) > V_45 ) {
F_2 ( V_4 , L_45 ) ;
return NULL ;
}
if ( V_79 -> V_99 != 1 ) {
F_2 ( V_4 , L_46 , V_79 -> V_99 ) ;
return NULL ;
}
if ( V_79 -> V_49 [ 0 ] || V_79 -> V_49 [ 1 ] ) {
F_2 ( V_4 , L_47 ) ;
return NULL ;
}
if ( V_79 -> V_47 * sizeof( V_79 -> V_19 [ 0 ] ) +
sizeof( struct V_78 ) > V_45 ) {
F_2 ( V_4 , L_48 ) ;
return NULL ;
}
* V_89 = V_91 -> V_97 ;
break;
}
return V_79 ;
}
static void F_39 ( struct V_9 * V_9 )
{
struct V_16 * V_100 , * V_101 ;
struct V_3 * V_4 = V_9 -> V_4 ;
F_40 (entry, tmp, &rproc->traces, node) {
F_41 ( V_100 -> V_66 ) ;
V_9 -> V_65 -- ;
F_42 ( & V_100 -> V_60 ) ;
F_29 ( V_100 ) ;
}
F_40 (entry, tmp, &rproc->carveouts, node) {
F_21 ( V_4 , V_100 -> V_15 , V_100 -> V_20 , V_100 -> V_44 ) ;
F_42 ( & V_100 -> V_60 ) ;
F_29 ( V_100 ) ;
}
F_40 (entry, tmp, &rproc->mappings, node) {
T_3 V_102 ;
V_102 = F_43 ( V_9 -> V_2 , V_100 -> V_14 , V_100 -> V_15 ) ;
if ( V_102 != V_100 -> V_15 ) {
F_2 ( V_4 , L_49 , V_100 -> V_15 ,
V_102 ) ;
}
F_42 ( & V_100 -> V_60 ) ;
F_29 ( V_100 ) ;
}
}
static int F_44 ( struct V_9 * V_9 , const struct V_103 * V_104 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
const char * V_64 = V_9 -> V_103 ;
struct V_22 * V_23 ;
struct V_78 * V_79 ;
int V_10 , V_89 ;
V_10 = F_45 ( V_9 , V_104 ) ;
if ( V_10 )
return V_10 ;
V_23 = (struct V_22 * ) V_104 -> V_88 ;
F_46 ( V_4 , L_50 , V_64 , V_104 -> V_45 ) ;
V_10 = F_3 ( V_9 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_51 , V_10 ) ;
return V_10 ;
}
V_9 -> V_105 = V_23 -> V_106 ;
V_79 = F_38 ( V_9 , V_104 -> V_88 , V_104 -> V_45 , & V_89 ) ;
if ( ! V_79 ) {
V_10 = - V_37 ;
goto V_107;
}
V_10 = F_35 ( V_9 , V_79 , V_89 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_52 , V_10 ) ;
goto V_107;
}
V_10 = F_14 ( V_9 , V_104 -> V_88 , V_104 -> V_45 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_53 , V_10 ) ;
goto V_107;
}
V_10 = V_9 -> V_108 -> V_109 ( V_9 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_54 , V_9 -> V_64 , V_10 ) ;
goto V_107;
}
V_9 -> V_110 = V_111 ;
F_46 ( V_4 , L_55 , V_9 -> V_64 ) ;
return 0 ;
V_107:
F_39 ( V_9 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static void F_47 ( const struct V_103 * V_104 , void * V_112 )
{
struct V_9 * V_9 = V_112 ;
struct V_78 * V_79 ;
int V_10 , V_89 ;
if ( F_45 ( V_9 , V_104 ) < 0 )
goto V_71;
V_79 = F_38 ( V_9 , V_104 -> V_88 , V_104 -> V_45 , & V_89 ) ;
if ( ! V_79 )
goto V_71;
V_10 = F_37 ( V_9 , V_79 , V_89 ) ;
if ( V_10 )
goto V_71;
V_71:
F_48 ( V_104 ) ;
F_49 ( & V_9 -> V_113 ) ;
}
int F_50 ( struct V_9 * V_9 )
{
const struct V_103 * V_114 ;
struct V_3 * V_4 ;
int V_10 ;
if ( ! V_9 ) {
F_51 ( L_56 ) ;
return - V_37 ;
}
V_4 = V_9 -> V_4 ;
V_10 = F_52 ( & V_9 -> V_115 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_57 , V_9 -> V_64 , V_10 ) ;
return V_10 ;
}
if ( ! V_9 -> V_103 ) {
F_2 ( V_4 , L_58 , V_86 ) ;
V_10 = - V_37 ;
goto V_116;
}
if ( ! F_53 ( V_4 -> V_117 -> V_118 ) ) {
F_2 ( V_4 , L_59 , V_86 ) ;
V_10 = - V_37 ;
goto V_116;
}
if ( F_54 ( & V_9 -> V_119 ) > 1 ) {
V_10 = 0 ;
goto V_116;
}
F_46 ( V_4 , L_60 , V_9 -> V_64 ) ;
V_10 = F_55 ( & V_114 , V_9 -> V_103 , V_4 ) ;
if ( V_10 < 0 ) {
F_2 ( V_4 , L_61 , V_10 ) ;
goto V_120;
}
V_10 = F_44 ( V_9 , V_114 ) ;
F_48 ( V_114 ) ;
V_120:
if ( V_10 ) {
F_56 ( V_4 -> V_117 -> V_118 ) ;
F_57 ( & V_9 -> V_119 ) ;
}
V_116:
F_58 ( & V_9 -> V_115 ) ;
return V_10 ;
}
void F_59 ( struct V_9 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 ;
V_10 = F_52 ( & V_9 -> V_115 ) ;
if ( V_10 ) {
F_2 ( V_4 , L_57 , V_9 -> V_64 , V_10 ) ;
return;
}
if ( ! F_60 ( & V_9 -> V_119 ) )
goto V_71;
V_10 = V_9 -> V_108 -> V_121 ( V_9 ) ;
if ( V_10 ) {
F_61 ( & V_9 -> V_119 ) ;
F_2 ( V_4 , L_62 , V_10 ) ;
goto V_71;
}
F_39 ( V_9 ) ;
F_10 ( V_9 ) ;
V_9 -> V_110 = V_122 ;
F_46 ( V_4 , L_63 , V_9 -> V_64 ) ;
V_71:
F_58 ( & V_9 -> V_115 ) ;
if ( ! V_10 )
F_56 ( V_4 -> V_117 -> V_118 ) ;
}
void F_62 ( struct V_123 * V_123 )
{
struct V_9 * V_9 = F_63 ( V_123 , struct V_9 , V_124 ) ;
struct V_38 * V_39 , * V_125 ;
F_46 ( V_9 -> V_4 , L_64 , V_9 -> V_64 ) ;
F_64 ( V_9 ) ;
F_40 (rvdev, rvtmp, &rproc->rvdevs, node) {
F_22 ( V_39 , V_126 ) ;
F_42 ( & V_39 -> V_60 ) ;
}
F_65 ( V_9 ) ;
}
static void F_66 ( struct V_127 * V_128 )
{
struct V_9 * V_9 = F_63 ( V_128 , struct V_9 , V_60 ) ;
F_67 ( & V_9 -> V_124 ) ;
}
static void F_68 ( struct V_127 * V_128 )
{
struct V_9 * V_9 = F_63 ( V_128 , struct V_9 , V_60 ) ;
F_69 ( & V_9 -> V_124 , F_62 ) ;
}
static struct V_9 * F_70 ( struct V_129 * V_26 )
{
struct V_127 * V_128 ;
V_128 = F_71 ( V_26 ) ;
if ( ! V_128 )
return NULL ;
return F_63 ( V_128 , struct V_9 , V_60 ) ;
}
struct V_9 * F_72 ( const char * V_64 )
{
struct V_9 * V_9 ;
struct V_129 V_26 ;
int V_10 ;
F_73 ( & V_130 , & V_26 ) ;
while ( ( V_9 = F_70 ( & V_26 ) ) != NULL )
if ( ! strcmp ( V_9 -> V_64 , V_64 ) ) {
F_67 ( & V_9 -> V_124 ) ;
break;
}
F_74 ( & V_26 ) ;
if ( ! V_9 ) {
F_51 ( L_65 , V_64 ) ;
return NULL ;
}
V_10 = F_50 ( V_9 ) ;
if ( V_10 < 0 ) {
F_69 ( & V_9 -> V_124 , F_62 ) ;
return NULL ;
}
return V_9 ;
}
void F_75 ( struct V_9 * V_9 )
{
F_59 ( V_9 ) ;
F_69 ( & V_9 -> V_124 , F_62 ) ;
}
int F_76 ( struct V_9 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 = 0 ;
F_77 ( & V_9 -> V_60 , & V_130 ) ;
F_46 ( V_9 -> V_4 , L_66 , V_9 -> V_64 ) ;
F_46 ( V_4 , L_67 ) ;
F_46 ( V_4 , L_68 ) ;
F_78 ( V_9 ) ;
F_79 ( & V_9 -> V_113 ) ;
V_10 = F_80 ( V_131 , V_132 ,
V_9 -> V_103 , V_4 , V_51 ,
V_9 , F_47 ) ;
if ( V_10 < 0 ) {
F_2 ( V_4 , L_69 , V_10 ) ;
F_49 ( & V_9 -> V_113 ) ;
F_81 ( & V_9 -> V_60 ) ;
}
return V_10 ;
}
struct V_9 * F_82 ( struct V_3 * V_4 , const char * V_64 ,
const struct V_133 * V_108 ,
const char * V_103 , int V_15 )
{
struct V_9 * V_9 ;
if ( ! V_4 || ! V_64 || ! V_108 )
return NULL ;
V_9 = F_26 ( sizeof( struct V_9 ) + V_15 , V_51 ) ;
if ( ! V_9 ) {
F_2 ( V_4 , L_70 , V_86 ) ;
return NULL ;
}
V_9 -> V_4 = V_4 ;
V_9 -> V_64 = V_64 ;
V_9 -> V_108 = V_108 ;
V_9 -> V_103 = V_103 ;
V_9 -> V_66 = & V_9 [ 1 ] ;
F_83 ( & V_9 -> V_119 , 0 ) ;
F_84 ( & V_9 -> V_124 ) ;
F_85 ( & V_9 -> V_115 ) ;
F_86 ( & V_9 -> V_50 ) ;
F_87 ( & V_9 -> V_77 ) ;
F_87 ( & V_9 -> V_72 ) ;
F_87 ( & V_9 -> V_67 ) ;
F_87 ( & V_9 -> V_61 ) ;
V_9 -> V_110 = V_122 ;
return V_9 ;
}
void F_65 ( struct V_9 * V_9 )
{
F_88 ( & V_9 -> V_50 ) ;
F_89 ( & V_9 -> V_50 ) ;
F_29 ( V_9 ) ;
}
int F_90 ( struct V_9 * V_9 )
{
struct V_38 * V_39 ;
if ( ! V_9 )
return - V_37 ;
F_91 ( & V_9 -> V_113 ) ;
F_13 (rvdev, &rproc->rvdevs, node)
F_92 ( V_39 ) ;
F_93 ( & V_9 -> V_60 ) ;
F_69 ( & V_9 -> V_124 , F_62 ) ;
return 0 ;
}
static int T_7 F_94 ( void )
{
F_95 () ;
return 0 ;
}
static void T_8 F_96 ( void )
{
F_97 () ;
}
