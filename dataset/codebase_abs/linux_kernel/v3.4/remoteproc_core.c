static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 )
{
F_2 ( V_4 , L_1 , V_5 , V_6 ) ;
return - V_7 ;
}
static int F_3 ( struct V_8 * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_8 -> V_4 ;
int V_9 ;
if ( ! F_4 ( V_4 -> V_10 ) ) {
F_5 ( V_4 , L_2 ) ;
return 0 ;
}
V_2 = F_6 ( V_4 -> V_10 ) ;
if ( ! V_2 ) {
F_2 ( V_4 , L_3 ) ;
return - V_11 ;
}
F_7 ( V_2 , F_1 ) ;
V_9 = F_8 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_4 , V_9 ) ;
goto V_12;
}
V_8 -> V_2 = V_2 ;
return 0 ;
V_12:
F_9 ( V_2 ) ;
return V_9 ;
}
static void F_10 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = V_8 -> V_4 ;
if ( ! V_2 )
return;
F_11 ( V_2 , V_4 ) ;
F_9 ( V_2 ) ;
return;
}
static void * F_12 ( struct V_8 * V_8 , T_1 V_13 , int V_14 )
{
struct V_15 * V_16 ;
void * V_17 = NULL ;
F_13 (carveout, &rproc->carveouts, node) {
int V_18 = V_13 - V_16 -> V_13 ;
if ( V_18 < 0 )
continue;
if ( V_18 + V_14 > V_16 -> V_14 )
continue;
V_17 = V_16 -> V_19 + V_18 ;
break;
}
return V_17 ;
}
static int
F_14 ( struct V_8 * V_8 , const T_2 * V_20 , T_3 V_14 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 , V_9 = 0 ;
V_22 = (struct V_21 * ) V_20 ;
V_24 = (struct V_23 * ) ( V_20 + V_22 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_22 -> V_27 ; V_25 ++ , V_24 ++ ) {
T_4 V_13 = V_24 -> V_28 ;
T_4 V_29 = V_24 -> V_30 ;
T_4 V_31 = V_24 -> V_32 ;
T_4 V_18 = V_24 -> V_33 ;
void * V_17 ;
if ( V_24 -> V_34 != V_35 )
continue;
F_5 ( V_4 , L_5 ,
V_24 -> V_34 , V_13 , V_29 , V_31 ) ;
if ( V_31 > V_29 ) {
F_2 ( V_4 , L_6 ,
V_31 , V_29 ) ;
V_9 = - V_36 ;
break;
}
if ( V_18 + V_31 > V_14 ) {
F_2 ( V_4 , L_7 ,
V_18 + V_31 , V_14 ) ;
V_9 = - V_36 ;
break;
}
V_17 = F_12 ( V_8 , V_13 , V_29 ) ;
if ( ! V_17 ) {
F_2 ( V_4 , L_8 , V_13 , V_29 ) ;
V_9 = - V_36 ;
break;
}
if ( V_24 -> V_32 )
memcpy ( V_17 , V_20 + V_24 -> V_33 , V_31 ) ;
if ( V_29 > V_31 )
memset ( V_17 + V_31 , 0 , V_29 - V_31 ) ;
}
return V_9 ;
}
static int
F_15 ( struct V_37 * V_38 , struct V_39 * V_40 , int V_25 )
{
struct V_8 * V_8 = V_38 -> V_8 ;
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_41 * V_42 = & V_40 -> V_42 [ V_25 ] ;
T_5 V_43 ;
void * V_19 ;
int V_9 , V_44 , V_45 ;
F_5 ( V_4 , L_9 ,
V_25 , V_42 -> V_13 , V_42 -> V_46 , V_42 -> V_47 ) ;
if ( V_42 -> V_48 ) {
F_2 ( V_4 , L_10 ) ;
return - V_36 ;
}
if ( ! V_42 -> V_46 || ! V_42 -> V_47 ) {
F_2 ( V_4 , L_11 ,
V_42 -> V_46 , V_42 -> V_47 ) ;
return - V_36 ;
}
V_44 = F_16 ( F_17 ( V_42 -> V_46 , V_42 -> V_47 ) ) ;
if ( ! F_18 ( & V_8 -> V_49 , V_50 ) ) {
F_2 ( V_4 , L_12 ) ;
return - V_11 ;
}
V_19 = F_19 ( V_4 , V_44 , & V_43 , V_50 ) ;
if ( ! V_19 ) {
F_2 ( V_4 , L_13 ) ;
return - V_36 ;
}
V_9 = F_20 ( & V_8 -> V_49 , & V_38 -> V_42 [ V_25 ] , & V_45 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_14 , V_9 ) ;
F_21 ( V_4 , V_44 , V_19 , V_43 ) ;
return V_9 ;
}
V_42 -> V_13 = V_43 ;
V_42 -> V_45 = V_45 ;
F_5 ( V_4 , L_15 , V_25 , V_19 ,
V_43 , V_44 , V_45 ) ;
V_38 -> V_42 [ V_25 ] . V_14 = V_42 -> V_46 ;
V_38 -> V_42 [ V_25 ] . V_47 = V_42 -> V_47 ;
V_38 -> V_42 [ V_25 ] . V_19 = V_19 ;
V_38 -> V_42 [ V_25 ] . V_43 = V_43 ;
V_38 -> V_42 [ V_25 ] . V_45 = V_45 ;
V_38 -> V_42 [ V_25 ] . V_38 = V_38 ;
return 0 ;
}
static void F_22 ( struct V_37 * V_38 , int V_25 )
{
struct V_8 * V_8 = V_38 -> V_8 ;
for ( V_25 -- ; V_25 >= 0 ; V_25 -- ) {
struct V_51 * V_52 = & V_38 -> V_42 [ V_25 ] ;
int V_44 = F_16 ( F_17 ( V_52 -> V_14 , V_52 -> V_47 ) ) ;
F_21 ( V_8 -> V_4 , V_44 , V_52 -> V_19 , V_52 -> V_43 ) ;
F_23 ( & V_8 -> V_49 , V_52 -> V_45 ) ;
}
}
static int F_24 ( struct V_8 * V_8 , struct V_39 * V_40 ,
int V_53 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_37 * V_38 ;
int V_25 , V_9 ;
if ( sizeof( * V_40 ) + V_40 -> V_54 * sizeof( struct V_41 )
+ V_40 -> V_55 > V_53 ) {
F_2 ( V_8 -> V_4 , L_16 ) ;
return - V_36 ;
}
if ( V_40 -> V_48 [ 0 ] || V_40 -> V_48 [ 1 ] ) {
F_2 ( V_4 , L_17 ) ;
return - V_36 ;
}
F_5 ( V_4 , L_18 ,
V_40 -> V_56 , V_40 -> V_57 , V_40 -> V_55 , V_40 -> V_54 ) ;
if ( V_40 -> V_54 > F_25 ( V_38 -> V_42 ) ) {
F_2 ( V_4 , L_19 , V_40 -> V_54 ) ;
return - V_36 ;
}
V_38 = F_26 ( sizeof( struct V_37 ) , V_50 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_8 = V_8 ;
for ( V_25 = 0 ; V_25 < V_40 -> V_54 ; V_25 ++ ) {
V_9 = F_15 ( V_38 , V_40 , V_25 ) ;
if ( V_9 )
goto V_58;
}
V_38 -> V_57 = V_40 -> V_57 ;
F_27 ( & V_38 -> V_59 , & V_8 -> V_60 ) ;
V_9 = F_28 ( V_38 , V_40 -> V_56 ) ;
if ( V_9 )
goto V_58;
return 0 ;
V_58:
F_22 ( V_38 , V_25 ) ;
F_29 ( V_38 ) ;
return V_9 ;
}
static int F_30 ( struct V_8 * V_8 , struct V_61 * V_40 ,
int V_53 )
{
struct V_15 * V_62 ;
struct V_3 * V_4 = V_8 -> V_4 ;
void * V_17 ;
char V_63 [ 15 ] ;
if ( sizeof( * V_40 ) > V_53 ) {
F_2 ( V_8 -> V_4 , L_20 ) ;
return - V_36 ;
}
if ( V_40 -> V_48 ) {
F_2 ( V_4 , L_21 ) ;
return - V_36 ;
}
V_17 = F_12 ( V_8 , V_40 -> V_13 , V_40 -> V_14 ) ;
if ( ! V_17 ) {
F_2 ( V_4 , L_22 ) ;
return - V_36 ;
}
V_62 = F_26 ( sizeof( * V_62 ) , V_50 ) ;
if ( ! V_62 ) {
F_2 ( V_4 , L_23 ) ;
return - V_11 ;
}
V_62 -> V_14 = V_40 -> V_14 ;
V_62 -> V_19 = V_17 ;
snprintf ( V_63 , sizeof( V_63 ) , L_24 , V_8 -> V_64 ) ;
V_62 -> V_65 = F_31 ( V_63 , V_8 , V_62 ) ;
if ( ! V_62 -> V_65 ) {
V_62 -> V_19 = NULL ;
F_29 ( V_62 ) ;
return - V_36 ;
}
F_27 ( & V_62 -> V_59 , & V_8 -> V_66 ) ;
V_8 -> V_64 ++ ;
F_5 ( V_4 , L_25 , V_63 , V_17 ,
V_40 -> V_13 , V_40 -> V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_8 * V_8 , struct V_67 * V_40 ,
int V_53 )
{
struct V_15 * V_68 ;
int V_9 ;
if ( ! V_8 -> V_2 )
return - V_36 ;
if ( sizeof( * V_40 ) > V_53 ) {
F_2 ( V_8 -> V_4 , L_26 ) ;
return - V_36 ;
}
if ( V_40 -> V_48 ) {
F_2 ( V_8 -> V_4 , L_27 ) ;
return - V_36 ;
}
V_68 = F_26 ( sizeof( * V_68 ) , V_50 ) ;
if ( ! V_68 ) {
F_2 ( V_8 -> V_4 , L_28 ) ;
return - V_11 ;
}
V_9 = F_33 ( V_8 -> V_2 , V_40 -> V_13 , V_40 -> V_69 , V_40 -> V_14 , V_40 -> V_6 ) ;
if ( V_9 ) {
F_2 ( V_8 -> V_4 , L_29 , V_9 ) ;
goto V_70;
}
V_68 -> V_13 = V_40 -> V_13 ;
V_68 -> V_14 = V_40 -> V_14 ;
F_27 ( & V_68 -> V_59 , & V_8 -> V_71 ) ;
F_5 ( V_8 -> V_4 , L_30 ,
V_40 -> V_69 , V_40 -> V_13 , V_40 -> V_14 ) ;
return 0 ;
V_70:
F_29 ( V_68 ) ;
return V_9 ;
}
static int F_34 ( struct V_8 * V_8 ,
struct V_72 * V_40 , int V_53 )
{
struct V_15 * V_16 , * V_68 ;
struct V_3 * V_4 = V_8 -> V_4 ;
T_5 V_43 ;
void * V_19 ;
int V_9 ;
if ( sizeof( * V_40 ) > V_53 ) {
F_2 ( V_8 -> V_4 , L_31 ) ;
return - V_36 ;
}
if ( V_40 -> V_48 ) {
F_2 ( V_4 , L_32 ) ;
return - V_36 ;
}
F_5 ( V_4 , L_33 ,
V_40 -> V_13 , V_40 -> V_69 , V_40 -> V_14 , V_40 -> V_6 ) ;
V_68 = F_26 ( sizeof( * V_68 ) , V_50 ) ;
if ( ! V_68 ) {
F_2 ( V_4 , L_28 ) ;
return - V_11 ;
}
V_16 = F_26 ( sizeof( * V_16 ) , V_50 ) ;
if ( ! V_16 ) {
F_2 ( V_4 , L_34 ) ;
V_9 = - V_11 ;
goto V_73;
}
V_19 = F_19 ( V_4 , V_40 -> V_14 , & V_43 , V_50 ) ;
if ( ! V_19 ) {
F_2 ( V_4 , L_35 , V_40 -> V_14 ) ;
V_9 = - V_11 ;
goto V_74;
}
F_5 ( V_4 , L_36 , V_19 , V_43 , V_40 -> V_14 ) ;
if ( V_8 -> V_2 ) {
V_9 = F_33 ( V_8 -> V_2 , V_40 -> V_13 , V_43 , V_40 -> V_14 ,
V_40 -> V_6 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_37 , V_9 ) ;
goto V_75;
}
V_68 -> V_13 = V_40 -> V_13 ;
V_68 -> V_14 = V_40 -> V_14 ;
F_27 ( & V_68 -> V_59 , & V_8 -> V_71 ) ;
F_5 ( V_4 , L_38 , V_40 -> V_13 , V_43 ) ;
V_40 -> V_69 = V_43 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_14 = V_40 -> V_14 ;
V_16 -> V_43 = V_43 ;
V_16 -> V_13 = V_40 -> V_13 ;
F_27 ( & V_16 -> V_59 , & V_8 -> V_76 ) ;
return 0 ;
V_75:
F_21 ( V_4 , V_40 -> V_14 , V_19 , V_43 ) ;
V_74:
F_29 ( V_16 ) ;
V_73:
F_29 ( V_68 ) ;
return V_9 ;
}
static int
F_35 ( struct V_8 * V_8 , struct V_77 * V_78 , int V_14 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
T_6 V_79 ;
int V_9 = 0 , V_25 ;
for ( V_25 = 0 ; V_25 < V_78 -> V_46 ; V_25 ++ ) {
int V_18 = V_78 -> V_18 [ V_25 ] ;
struct V_80 * V_81 = ( void * ) V_78 + V_18 ;
int V_53 = V_14 - V_18 - sizeof( * V_81 ) ;
void * V_40 = ( void * ) V_81 + sizeof( * V_81 ) ;
if ( V_53 < 0 ) {
F_2 ( V_4 , L_39 ) ;
return - V_36 ;
}
F_5 ( V_4 , L_40 , V_81 -> type ) ;
if ( V_81 -> type >= V_82 ) {
F_36 ( V_4 , L_41 , V_81 -> type ) ;
continue;
}
V_79 = V_83 [ V_81 -> type ] ;
if ( ! V_79 )
continue;
V_9 = V_79 ( V_8 , V_40 , V_53 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int
F_37 ( struct V_8 * V_8 , struct V_77 * V_78 , int V_14 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
int V_9 = 0 , V_25 ;
for ( V_25 = 0 ; V_25 < V_78 -> V_46 ; V_25 ++ ) {
int V_18 = V_78 -> V_18 [ V_25 ] ;
struct V_80 * V_81 = ( void * ) V_78 + V_18 ;
int V_53 = V_14 - V_18 - sizeof( * V_81 ) ;
struct V_39 * V_84 ;
if ( V_53 < 0 ) {
F_2 ( V_4 , L_39 ) ;
return - V_36 ;
}
F_5 ( V_4 , L_42 , V_85 , V_81 -> type ) ;
if ( V_81 -> type != V_86 )
continue;
V_84 = (struct V_39 * ) V_81 -> V_87 ;
V_9 = F_24 ( V_8 , V_84 , V_53 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static struct V_77 *
F_38 ( struct V_8 * V_8 , const T_2 * V_20 , T_3 V_14 ,
int * V_88 )
{
struct V_21 * V_22 ;
struct V_89 * V_90 ;
const char * V_91 ;
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_77 * V_78 = NULL ;
int V_25 ;
V_22 = (struct V_21 * ) V_20 ;
V_90 = (struct V_89 * ) ( V_20 + V_22 -> V_92 ) ;
V_91 = V_20 + V_90 [ V_22 -> V_93 ] . V_94 ;
for ( V_25 = 0 ; V_25 < V_22 -> V_95 ; V_25 ++ , V_90 ++ ) {
int V_44 = V_90 -> V_96 ;
int V_18 = V_90 -> V_94 ;
if ( strcmp ( V_91 + V_90 -> V_97 , L_43 ) )
continue;
V_78 = (struct V_77 * ) ( V_20 + V_18 ) ;
if ( V_18 + V_44 > V_14 ) {
F_2 ( V_4 , L_44 ) ;
return NULL ;
}
if ( sizeof( struct V_77 ) > V_44 ) {
F_2 ( V_4 , L_45 ) ;
return NULL ;
}
if ( V_78 -> V_98 != 1 ) {
F_2 ( V_4 , L_46 , V_78 -> V_98 ) ;
return NULL ;
}
if ( V_78 -> V_48 [ 0 ] || V_78 -> V_48 [ 1 ] ) {
F_2 ( V_4 , L_47 ) ;
return NULL ;
}
if ( V_78 -> V_46 * sizeof( V_78 -> V_18 [ 0 ] ) +
sizeof( struct V_77 ) > V_44 ) {
F_2 ( V_4 , L_48 ) ;
return NULL ;
}
* V_88 = V_90 -> V_96 ;
break;
}
return V_78 ;
}
static void F_39 ( struct V_8 * V_8 )
{
struct V_15 * V_99 , * V_100 ;
struct V_3 * V_4 = V_8 -> V_4 ;
F_40 (entry, tmp, &rproc->traces, node) {
F_41 ( V_99 -> V_65 ) ;
V_8 -> V_64 -- ;
F_42 ( & V_99 -> V_59 ) ;
F_29 ( V_99 ) ;
}
F_40 (entry, tmp, &rproc->carveouts, node) {
F_21 ( V_4 , V_99 -> V_14 , V_99 -> V_19 , V_99 -> V_43 ) ;
F_42 ( & V_99 -> V_59 ) ;
F_29 ( V_99 ) ;
}
F_40 (entry, tmp, &rproc->mappings, node) {
T_3 V_101 ;
V_101 = F_43 ( V_8 -> V_2 , V_99 -> V_13 , V_99 -> V_14 ) ;
if ( V_101 != V_99 -> V_14 ) {
F_2 ( V_4 , L_49 , V_99 -> V_14 ,
V_101 ) ;
}
F_42 ( & V_99 -> V_59 ) ;
F_29 ( V_99 ) ;
}
}
static int F_44 ( struct V_8 * V_8 , const struct V_102 * V_103 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
const char * V_63 = V_8 -> V_102 ;
struct V_21 * V_22 ;
struct V_77 * V_78 ;
int V_9 , V_88 ;
V_9 = F_45 ( V_8 , V_103 ) ;
if ( V_9 )
return V_9 ;
V_22 = (struct V_21 * ) V_103 -> V_87 ;
F_46 ( V_4 , L_50 , V_63 , V_103 -> V_44 ) ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_51 , V_9 ) ;
return V_9 ;
}
V_8 -> V_104 = V_22 -> V_105 ;
V_78 = F_38 ( V_8 , V_103 -> V_87 , V_103 -> V_44 , & V_88 ) ;
if ( ! V_78 )
goto V_106;
V_9 = F_35 ( V_8 , V_78 , V_88 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_52 , V_9 ) ;
goto V_106;
}
V_9 = F_14 ( V_8 , V_103 -> V_87 , V_103 -> V_44 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_53 , V_9 ) ;
goto V_106;
}
V_9 = V_8 -> V_107 -> V_108 ( V_8 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_54 , V_8 -> V_63 , V_9 ) ;
goto V_106;
}
V_8 -> V_109 = V_110 ;
F_46 ( V_4 , L_55 , V_8 -> V_63 ) ;
return 0 ;
V_106:
F_39 ( V_8 ) ;
F_10 ( V_8 ) ;
return V_9 ;
}
static void F_47 ( const struct V_102 * V_103 , void * V_111 )
{
struct V_8 * V_8 = V_111 ;
struct V_77 * V_78 ;
int V_9 , V_88 ;
if ( F_45 ( V_8 , V_103 ) < 0 )
goto V_70;
V_78 = F_38 ( V_8 , V_103 -> V_87 , V_103 -> V_44 , & V_88 ) ;
if ( ! V_78 )
goto V_70;
V_9 = F_37 ( V_8 , V_78 , V_88 ) ;
if ( V_9 )
goto V_70;
V_70:
if ( V_103 )
F_48 ( V_103 ) ;
F_49 ( & V_8 -> V_112 ) ;
}
int F_50 ( struct V_8 * V_8 )
{
const struct V_102 * V_113 ;
struct V_3 * V_4 ;
int V_9 ;
if ( ! V_8 ) {
F_51 ( L_56 ) ;
return - V_36 ;
}
V_4 = V_8 -> V_4 ;
V_9 = F_52 ( & V_8 -> V_114 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_57 , V_8 -> V_63 , V_9 ) ;
return V_9 ;
}
if ( ! V_8 -> V_102 ) {
F_2 ( V_4 , L_58 , V_85 ) ;
V_9 = - V_36 ;
goto V_115;
}
if ( ! F_53 ( V_4 -> V_116 -> V_117 ) ) {
F_2 ( V_4 , L_59 , V_85 ) ;
V_9 = - V_36 ;
goto V_115;
}
if ( F_54 ( & V_8 -> V_118 ) > 1 ) {
V_9 = 0 ;
goto V_115;
}
F_46 ( V_4 , L_60 , V_8 -> V_63 ) ;
V_9 = F_55 ( & V_113 , V_8 -> V_102 , V_4 ) ;
if ( V_9 < 0 ) {
F_2 ( V_4 , L_61 , V_9 ) ;
goto V_119;
}
V_9 = F_44 ( V_8 , V_113 ) ;
F_48 ( V_113 ) ;
V_119:
if ( V_9 ) {
F_56 ( V_4 -> V_116 -> V_117 ) ;
F_57 ( & V_8 -> V_118 ) ;
}
V_115:
F_58 ( & V_8 -> V_114 ) ;
return V_9 ;
}
void F_59 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
int V_9 ;
V_9 = F_52 ( & V_8 -> V_114 ) ;
if ( V_9 ) {
F_2 ( V_4 , L_57 , V_8 -> V_63 , V_9 ) ;
return;
}
if ( ! F_60 ( & V_8 -> V_118 ) )
goto V_70;
V_9 = V_8 -> V_107 -> V_120 ( V_8 ) ;
if ( V_9 ) {
F_61 ( & V_8 -> V_118 ) ;
F_2 ( V_4 , L_62 , V_9 ) ;
goto V_70;
}
F_39 ( V_8 ) ;
F_10 ( V_8 ) ;
V_8 -> V_109 = V_121 ;
F_46 ( V_4 , L_63 , V_8 -> V_63 ) ;
V_70:
F_58 ( & V_8 -> V_114 ) ;
if ( ! V_9 )
F_56 ( V_4 -> V_116 -> V_117 ) ;
}
void F_62 ( struct V_122 * V_122 )
{
struct V_8 * V_8 = F_63 ( V_122 , struct V_8 , V_123 ) ;
struct V_37 * V_38 , * V_124 ;
F_46 ( V_8 -> V_4 , L_64 , V_8 -> V_63 ) ;
F_64 ( V_8 ) ;
F_40 (rvdev, rvtmp, &rproc->rvdevs, node) {
F_22 ( V_38 , V_125 ) ;
F_42 ( & V_38 -> V_59 ) ;
}
F_65 ( V_8 ) ;
}
static void F_66 ( struct V_126 * V_127 )
{
struct V_8 * V_8 = F_63 ( V_127 , struct V_8 , V_59 ) ;
F_67 ( & V_8 -> V_123 ) ;
}
static void F_68 ( struct V_126 * V_127 )
{
struct V_8 * V_8 = F_63 ( V_127 , struct V_8 , V_59 ) ;
F_69 ( & V_8 -> V_123 , F_62 ) ;
}
static struct V_8 * F_70 ( struct V_128 * V_25 )
{
struct V_126 * V_127 ;
V_127 = F_71 ( V_25 ) ;
if ( ! V_127 )
return NULL ;
return F_63 ( V_127 , struct V_8 , V_59 ) ;
}
struct V_8 * F_72 ( const char * V_63 )
{
struct V_8 * V_8 ;
struct V_128 V_25 ;
int V_9 ;
F_73 ( & V_129 , & V_25 ) ;
while ( ( V_8 = F_70 ( & V_25 ) ) != NULL )
if ( ! strcmp ( V_8 -> V_63 , V_63 ) ) {
F_67 ( & V_8 -> V_123 ) ;
break;
}
F_74 ( & V_25 ) ;
if ( ! V_8 ) {
F_51 ( L_65 , V_63 ) ;
return NULL ;
}
V_9 = F_50 ( V_8 ) ;
if ( V_9 < 0 ) {
F_69 ( & V_8 -> V_123 , F_62 ) ;
return NULL ;
}
return V_8 ;
}
void F_75 ( struct V_8 * V_8 )
{
F_59 ( V_8 ) ;
F_69 ( & V_8 -> V_123 , F_62 ) ;
}
int F_76 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_4 ;
int V_9 = 0 ;
F_77 ( & V_8 -> V_59 , & V_129 ) ;
F_46 ( V_8 -> V_4 , L_66 , V_8 -> V_63 ) ;
F_46 ( V_4 , L_67 ) ;
F_46 ( V_4 , L_68 ) ;
F_78 ( V_8 ) ;
F_79 ( & V_8 -> V_112 ) ;
V_9 = F_80 ( V_130 , V_131 ,
V_8 -> V_102 , V_4 , V_50 ,
V_8 , F_47 ) ;
if ( V_9 < 0 ) {
F_2 ( V_4 , L_69 , V_9 ) ;
F_49 ( & V_8 -> V_112 ) ;
F_81 ( & V_8 -> V_59 ) ;
}
return V_9 ;
}
struct V_8 * F_82 ( struct V_3 * V_4 , const char * V_63 ,
const struct V_132 * V_107 ,
const char * V_102 , int V_14 )
{
struct V_8 * V_8 ;
if ( ! V_4 || ! V_63 || ! V_107 )
return NULL ;
V_8 = F_26 ( sizeof( struct V_8 ) + V_14 , V_50 ) ;
if ( ! V_8 ) {
F_2 ( V_4 , L_70 , V_85 ) ;
return NULL ;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_63 = V_63 ;
V_8 -> V_107 = V_107 ;
V_8 -> V_102 = V_102 ;
V_8 -> V_65 = & V_8 [ 1 ] ;
F_83 ( & V_8 -> V_118 , 0 ) ;
F_84 ( & V_8 -> V_123 ) ;
F_85 ( & V_8 -> V_114 ) ;
F_86 ( & V_8 -> V_49 ) ;
F_87 ( & V_8 -> V_76 ) ;
F_87 ( & V_8 -> V_71 ) ;
F_87 ( & V_8 -> V_66 ) ;
F_87 ( & V_8 -> V_60 ) ;
V_8 -> V_109 = V_121 ;
return V_8 ;
}
void F_65 ( struct V_8 * V_8 )
{
F_88 ( & V_8 -> V_49 ) ;
F_89 ( & V_8 -> V_49 ) ;
F_29 ( V_8 ) ;
}
int F_90 ( struct V_8 * V_8 )
{
struct V_37 * V_38 ;
if ( ! V_8 )
return - V_36 ;
F_91 ( & V_8 -> V_112 ) ;
F_13 (rvdev, &rproc->rvdevs, node)
F_92 ( V_38 ) ;
F_93 ( & V_8 -> V_59 ) ;
F_69 ( & V_8 -> V_123 , F_62 ) ;
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
