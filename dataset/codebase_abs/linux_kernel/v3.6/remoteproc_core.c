static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( V_4 , L_1 , V_5 , V_6 ) ;
return - V_8 ;
}
static int F_3 ( struct V_9 * V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_9 -> V_4 . V_10 ;
int V_11 ;
if ( ! F_4 ( V_4 -> V_12 ) ) {
F_5 ( V_4 , L_2 ) ;
return 0 ;
}
V_2 = F_6 ( V_4 -> V_12 ) ;
if ( ! V_2 ) {
F_2 ( V_4 , L_3 ) ;
return - V_13 ;
}
F_7 ( V_2 , F_1 , V_9 ) ;
V_11 = F_8 ( V_2 , V_4 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_4 , V_11 ) ;
goto V_14;
}
V_9 -> V_2 = V_2 ;
return 0 ;
V_14:
F_9 ( V_2 ) ;
return V_11 ;
}
static void F_10 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_9 -> V_4 . V_10 ;
if ( ! V_2 )
return;
F_11 ( V_2 , V_4 ) ;
F_9 ( V_2 ) ;
return;
}
void * F_12 ( struct V_9 * V_9 , T_1 V_15 , int V_16 )
{
struct V_17 * V_18 ;
void * V_19 = NULL ;
F_13 (carveout, &rproc->carveouts, node) {
int V_20 = V_15 - V_18 -> V_15 ;
if ( V_20 < 0 )
continue;
if ( V_20 + V_16 > V_18 -> V_16 )
continue;
V_19 = V_18 -> V_21 + V_20 ;
break;
}
return V_19 ;
}
int F_14 ( struct V_22 * V_23 , int V_24 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
struct V_25 * V_26 = & V_23 -> V_27 [ V_24 ] ;
T_2 V_28 ;
void * V_21 ;
int V_11 , V_29 , V_30 ;
V_29 = F_15 ( F_16 ( V_26 -> V_16 , V_26 -> V_31 ) ) ;
if ( ! F_17 ( & V_9 -> V_32 , V_33 ) ) {
F_2 ( V_4 , L_5 ) ;
return - V_13 ;
}
V_21 = F_18 ( V_4 -> V_10 , V_29 , & V_28 , V_33 ) ;
if ( ! V_21 ) {
F_2 ( V_4 -> V_10 , L_6 ) ;
return - V_34 ;
}
V_11 = F_19 ( & V_9 -> V_32 , V_26 , & V_30 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_7 , V_11 ) ;
F_20 ( V_4 -> V_10 , V_29 , V_21 , V_28 ) ;
return V_11 ;
}
F_5 ( V_4 , L_8 , V_24 , V_21 ,
V_28 , V_29 , V_30 ) ;
V_26 -> V_21 = V_21 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_30 = V_30 ;
return 0 ;
}
static int
F_21 ( struct V_22 * V_23 , struct V_35 * V_36 , int V_24 )
{
struct V_9 * V_9 = V_23 -> V_9 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
struct V_37 * V_27 = & V_36 -> V_27 [ V_24 ] ;
struct V_25 * V_26 = & V_23 -> V_27 [ V_24 ] ;
F_5 ( V_4 , L_9 ,
V_24 , V_27 -> V_15 , V_27 -> V_38 , V_27 -> V_31 ) ;
if ( V_27 -> V_39 ) {
F_2 ( V_4 , L_10 ) ;
return - V_34 ;
}
if ( ! V_27 -> V_38 || ! V_27 -> V_31 ) {
F_2 ( V_4 , L_11 ,
V_27 -> V_38 , V_27 -> V_31 ) ;
return - V_34 ;
}
V_26 -> V_16 = V_27 -> V_38 ;
V_26 -> V_31 = V_27 -> V_31 ;
V_26 -> V_23 = V_23 ;
return 0 ;
}
void F_22 ( struct V_25 * V_26 )
{
int V_29 = F_15 ( F_16 ( V_26 -> V_16 , V_26 -> V_31 ) ) ;
struct V_9 * V_9 = V_26 -> V_23 -> V_9 ;
F_20 ( V_9 -> V_4 . V_10 , V_29 , V_26 -> V_21 , V_26 -> V_28 ) ;
F_23 ( & V_9 -> V_32 , V_26 -> V_30 ) ;
}
static int F_24 ( struct V_9 * V_9 , struct V_35 * V_36 ,
int V_40 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
struct V_22 * V_23 ;
int V_24 , V_11 ;
if ( sizeof( * V_36 ) + V_36 -> V_41 * sizeof( struct V_37 )
+ V_36 -> V_42 > V_40 ) {
F_2 ( V_4 , L_12 ) ;
return - V_34 ;
}
if ( V_36 -> V_39 [ 0 ] || V_36 -> V_39 [ 1 ] ) {
F_2 ( V_4 , L_13 ) ;
return - V_34 ;
}
F_5 ( V_4 , L_14 ,
V_36 -> V_43 , V_36 -> V_44 , V_36 -> V_42 , V_36 -> V_41 ) ;
if ( V_36 -> V_41 > F_25 ( V_23 -> V_27 ) ) {
F_2 ( V_4 , L_15 , V_36 -> V_41 ) ;
return - V_34 ;
}
V_23 = F_26 ( sizeof( struct V_22 ) , V_33 ) ;
if ( ! V_23 )
return - V_13 ;
V_23 -> V_9 = V_9 ;
for ( V_24 = 0 ; V_24 < V_36 -> V_41 ; V_24 ++ ) {
V_11 = F_21 ( V_23 , V_36 , V_24 ) ;
if ( V_11 )
goto V_45;
}
V_23 -> V_44 = V_36 -> V_44 ;
F_27 ( & V_23 -> V_46 , & V_9 -> V_47 ) ;
V_11 = F_28 ( V_23 , V_36 -> V_43 ) ;
if ( V_11 )
goto V_45;
return 0 ;
V_45:
F_29 ( V_23 ) ;
return V_11 ;
}
static int F_30 ( struct V_9 * V_9 , struct V_48 * V_36 ,
int V_40 )
{
struct V_17 * V_49 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
void * V_19 ;
char V_50 [ 15 ] ;
if ( sizeof( * V_36 ) > V_40 ) {
F_2 ( V_4 , L_16 ) ;
return - V_34 ;
}
if ( V_36 -> V_39 ) {
F_2 ( V_4 , L_17 ) ;
return - V_34 ;
}
V_19 = F_12 ( V_9 , V_36 -> V_15 , V_36 -> V_16 ) ;
if ( ! V_19 ) {
F_2 ( V_4 , L_18 ) ;
return - V_34 ;
}
V_49 = F_26 ( sizeof( * V_49 ) , V_33 ) ;
if ( ! V_49 ) {
F_2 ( V_4 , L_19 ) ;
return - V_13 ;
}
V_49 -> V_16 = V_36 -> V_16 ;
V_49 -> V_21 = V_19 ;
snprintf ( V_50 , sizeof( V_50 ) , L_20 , V_9 -> V_51 ) ;
V_49 -> V_52 = F_31 ( V_50 , V_9 , V_49 ) ;
if ( ! V_49 -> V_52 ) {
V_49 -> V_21 = NULL ;
F_29 ( V_49 ) ;
return - V_34 ;
}
F_27 ( & V_49 -> V_46 , & V_9 -> V_53 ) ;
V_9 -> V_51 ++ ;
F_5 ( V_4 , L_21 , V_50 , V_19 ,
V_36 -> V_15 , V_36 -> V_16 ) ;
return 0 ;
}
static int F_32 ( struct V_9 * V_9 , struct V_54 * V_36 ,
int V_40 )
{
struct V_17 * V_55 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
int V_11 ;
if ( ! V_9 -> V_2 )
return - V_34 ;
if ( sizeof( * V_36 ) > V_40 ) {
F_2 ( V_4 , L_22 ) ;
return - V_34 ;
}
if ( V_36 -> V_39 ) {
F_2 ( V_4 , L_23 ) ;
return - V_34 ;
}
V_55 = F_26 ( sizeof( * V_55 ) , V_33 ) ;
if ( ! V_55 ) {
F_2 ( V_4 , L_24 ) ;
return - V_13 ;
}
V_11 = F_33 ( V_9 -> V_2 , V_36 -> V_15 , V_36 -> V_56 , V_36 -> V_16 , V_36 -> V_6 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_25 , V_11 ) ;
goto V_57;
}
V_55 -> V_15 = V_36 -> V_15 ;
V_55 -> V_16 = V_36 -> V_16 ;
F_27 ( & V_55 -> V_46 , & V_9 -> V_58 ) ;
F_5 ( V_4 , L_26 ,
V_36 -> V_56 , V_36 -> V_15 , V_36 -> V_16 ) ;
return 0 ;
V_57:
F_29 ( V_55 ) ;
return V_11 ;
}
static int F_34 ( struct V_9 * V_9 ,
struct V_59 * V_36 , int V_40 )
{
struct V_17 * V_18 , * V_55 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
T_2 V_28 ;
void * V_21 ;
int V_11 ;
if ( sizeof( * V_36 ) > V_40 ) {
F_2 ( V_4 , L_27 ) ;
return - V_34 ;
}
if ( V_36 -> V_39 ) {
F_2 ( V_4 , L_28 ) ;
return - V_34 ;
}
F_5 ( V_4 , L_29 ,
V_36 -> V_15 , V_36 -> V_56 , V_36 -> V_16 , V_36 -> V_6 ) ;
V_55 = F_26 ( sizeof( * V_55 ) , V_33 ) ;
if ( ! V_55 ) {
F_2 ( V_4 , L_24 ) ;
return - V_13 ;
}
V_18 = F_26 ( sizeof( * V_18 ) , V_33 ) ;
if ( ! V_18 ) {
F_2 ( V_4 , L_30 ) ;
V_11 = - V_13 ;
goto V_60;
}
V_21 = F_18 ( V_4 -> V_10 , V_36 -> V_16 , & V_28 , V_33 ) ;
if ( ! V_21 ) {
F_2 ( V_4 -> V_10 , L_31 , V_36 -> V_16 ) ;
V_11 = - V_13 ;
goto V_61;
}
F_5 ( V_4 , L_32 , V_21 , V_28 , V_36 -> V_16 ) ;
if ( V_9 -> V_2 ) {
V_11 = F_33 ( V_9 -> V_2 , V_36 -> V_15 , V_28 , V_36 -> V_16 ,
V_36 -> V_6 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_33 , V_11 ) ;
goto V_62;
}
V_55 -> V_15 = V_36 -> V_15 ;
V_55 -> V_16 = V_36 -> V_16 ;
F_27 ( & V_55 -> V_46 , & V_9 -> V_58 ) ;
F_5 ( V_4 , L_34 , V_36 -> V_15 , V_28 ) ;
}
V_36 -> V_56 = V_28 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_16 = V_36 -> V_16 ;
V_18 -> V_28 = V_28 ;
V_18 -> V_15 = V_36 -> V_15 ;
F_27 ( & V_18 -> V_46 , & V_9 -> V_63 ) ;
return 0 ;
V_62:
F_20 ( V_4 -> V_10 , V_36 -> V_16 , V_21 , V_28 ) ;
V_61:
F_29 ( V_18 ) ;
V_60:
F_29 ( V_55 ) ;
return V_11 ;
}
static int
F_35 ( struct V_9 * V_9 , struct V_64 * V_65 , int V_16 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
T_3 V_66 ;
int V_11 = 0 , V_24 ;
for ( V_24 = 0 ; V_24 < V_65 -> V_38 ; V_24 ++ ) {
int V_20 = V_65 -> V_20 [ V_24 ] ;
struct V_67 * V_68 = ( void * ) V_65 + V_20 ;
int V_40 = V_16 - V_20 - sizeof( * V_68 ) ;
void * V_36 = ( void * ) V_68 + sizeof( * V_68 ) ;
if ( V_40 < 0 ) {
F_2 ( V_4 , L_35 ) ;
return - V_34 ;
}
F_5 ( V_4 , L_36 , V_68 -> type ) ;
if ( V_68 -> type >= V_69 ) {
F_36 ( V_4 , L_37 , V_68 -> type ) ;
continue;
}
V_66 = V_70 [ V_68 -> type ] ;
if ( ! V_66 )
continue;
V_11 = V_66 ( V_9 , V_36 , V_40 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int
F_37 ( struct V_9 * V_9 , struct V_64 * V_65 , int V_16 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
int V_11 = 0 , V_24 ;
for ( V_24 = 0 ; V_24 < V_65 -> V_38 ; V_24 ++ ) {
int V_20 = V_65 -> V_20 [ V_24 ] ;
struct V_67 * V_68 = ( void * ) V_65 + V_20 ;
int V_40 = V_16 - V_20 - sizeof( * V_68 ) ;
struct V_35 * V_71 ;
if ( V_40 < 0 ) {
F_2 ( V_4 , L_35 ) ;
return - V_34 ;
}
F_5 ( V_4 , L_38 , V_72 , V_68 -> type ) ;
if ( V_68 -> type != V_73 )
continue;
V_71 = (struct V_35 * ) V_68 -> V_74 ;
V_11 = F_24 ( V_9 , V_71 , V_40 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static void F_38 ( struct V_9 * V_9 )
{
struct V_17 * V_75 , * V_76 ;
struct V_3 * V_4 = & V_9 -> V_4 ;
F_39 (entry, tmp, &rproc->traces, node) {
F_40 ( V_75 -> V_52 ) ;
V_9 -> V_51 -- ;
F_41 ( & V_75 -> V_46 ) ;
F_29 ( V_75 ) ;
}
F_39 (entry, tmp, &rproc->carveouts, node) {
F_20 ( V_4 -> V_10 , V_75 -> V_16 , V_75 -> V_21 , V_75 -> V_28 ) ;
F_41 ( & V_75 -> V_46 ) ;
F_29 ( V_75 ) ;
}
F_39 (entry, tmp, &rproc->mappings, node) {
T_4 V_77 ;
V_77 = F_42 ( V_9 -> V_2 , V_75 -> V_15 , V_75 -> V_16 ) ;
if ( V_77 != V_75 -> V_16 ) {
F_2 ( V_4 , L_39 , V_75 -> V_16 ,
V_77 ) ;
}
F_41 ( & V_75 -> V_46 ) ;
F_29 ( V_75 ) ;
}
}
static int F_43 ( struct V_9 * V_9 , const struct V_78 * V_79 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
const char * V_50 = V_9 -> V_78 ;
struct V_64 * V_65 ;
int V_11 , V_80 ;
V_11 = F_44 ( V_9 , V_79 ) ;
if ( V_11 )
return V_11 ;
F_45 ( V_4 , L_40 , V_50 , V_79 -> V_29 ) ;
V_11 = F_3 ( V_9 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_41 , V_11 ) ;
return V_11 ;
}
V_9 -> V_81 = F_46 ( V_9 , V_79 ) ;
V_65 = F_47 ( V_9 , V_79 , & V_80 ) ;
if ( ! V_65 ) {
V_11 = - V_34 ;
goto V_82;
}
V_11 = F_35 ( V_9 , V_65 , V_80 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_42 , V_11 ) ;
goto V_82;
}
V_11 = F_48 ( V_9 , V_79 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_43 , V_11 ) ;
goto V_82;
}
V_11 = V_9 -> V_83 -> V_84 ( V_9 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_44 , V_9 -> V_50 , V_11 ) ;
goto V_82;
}
V_9 -> V_85 = V_86 ;
F_45 ( V_4 , L_45 , V_9 -> V_50 ) ;
return 0 ;
V_82:
F_38 ( V_9 ) ;
F_10 ( V_9 ) ;
return V_11 ;
}
static void F_49 ( const struct V_78 * V_79 , void * V_87 )
{
struct V_9 * V_9 = V_87 ;
struct V_64 * V_65 ;
int V_11 , V_80 ;
if ( F_44 ( V_9 , V_79 ) < 0 )
goto V_57;
V_65 = F_47 ( V_9 , V_79 , & V_80 ) ;
if ( ! V_65 )
goto V_57;
V_11 = F_37 ( V_9 , V_65 , V_80 ) ;
if ( V_11 )
goto V_57;
V_57:
F_50 ( V_79 ) ;
F_51 ( & V_9 -> V_88 ) ;
}
int F_52 ( struct V_9 * V_9 )
{
const struct V_78 * V_89 ;
struct V_3 * V_4 ;
int V_11 ;
if ( ! V_9 ) {
F_53 ( L_46 ) ;
return - V_34 ;
}
V_4 = & V_9 -> V_4 ;
V_11 = F_54 ( & V_9 -> V_90 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_47 , V_9 -> V_50 , V_11 ) ;
return V_11 ;
}
if ( ! V_9 -> V_78 ) {
F_2 ( V_4 , L_48 , V_72 ) ;
V_11 = - V_34 ;
goto V_91;
}
if ( ! F_55 ( V_4 -> V_10 -> V_92 -> V_93 ) ) {
F_2 ( V_4 , L_49 , V_72 ) ;
V_11 = - V_34 ;
goto V_91;
}
if ( F_56 ( & V_9 -> V_94 ) > 1 ) {
V_11 = 0 ;
goto V_91;
}
F_45 ( V_4 , L_50 , V_9 -> V_50 ) ;
V_11 = F_57 ( & V_89 , V_9 -> V_78 , V_4 ) ;
if ( V_11 < 0 ) {
F_2 ( V_4 , L_51 , V_11 ) ;
goto V_95;
}
V_11 = F_43 ( V_9 , V_89 ) ;
F_50 ( V_89 ) ;
V_95:
if ( V_11 ) {
F_58 ( V_4 -> V_10 -> V_92 -> V_93 ) ;
F_59 ( & V_9 -> V_94 ) ;
}
V_91:
F_60 ( & V_9 -> V_90 ) ;
return V_11 ;
}
void F_61 ( struct V_9 * V_9 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
int V_11 ;
V_11 = F_54 ( & V_9 -> V_90 ) ;
if ( V_11 ) {
F_2 ( V_4 , L_47 , V_9 -> V_50 , V_11 ) ;
return;
}
if ( ! F_62 ( & V_9 -> V_94 ) )
goto V_57;
V_11 = V_9 -> V_83 -> V_96 ( V_9 ) ;
if ( V_11 ) {
F_63 ( & V_9 -> V_94 ) ;
F_2 ( V_4 , L_52 , V_11 ) ;
goto V_57;
}
F_38 ( V_9 ) ;
F_10 ( V_9 ) ;
V_9 -> V_85 = V_97 ;
F_45 ( V_4 , L_53 , V_9 -> V_50 ) ;
V_57:
F_60 ( & V_9 -> V_90 ) ;
if ( ! V_11 )
F_58 ( V_4 -> V_10 -> V_92 -> V_93 ) ;
}
int F_64 ( struct V_9 * V_9 )
{
struct V_3 * V_4 = & V_9 -> V_4 ;
int V_11 = 0 ;
V_11 = F_65 ( V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
F_45 ( V_4 , L_54 , V_9 -> V_50 ) ;
F_45 ( V_4 , L_55 ) ;
F_45 ( V_4 , L_56 ) ;
F_66 ( V_9 ) ;
F_67 ( & V_9 -> V_88 ) ;
V_11 = F_68 ( V_98 , V_99 ,
V_9 -> V_78 , V_4 , V_33 ,
V_9 , F_49 ) ;
if ( V_11 < 0 ) {
F_2 ( V_4 , L_57 , V_11 ) ;
F_51 ( & V_9 -> V_88 ) ;
}
return V_11 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_9 * V_9 = F_70 ( V_4 , struct V_9 , V_4 ) ;
F_45 ( & V_9 -> V_4 , L_58 , V_9 -> V_50 ) ;
F_71 ( V_9 ) ;
F_72 ( & V_9 -> V_32 ) ;
F_73 ( & V_9 -> V_32 ) ;
if ( V_9 -> V_100 >= 0 )
F_74 ( & V_101 , V_9 -> V_100 ) ;
F_29 ( V_9 ) ;
}
struct V_9 * F_75 ( struct V_3 * V_4 , const char * V_50 ,
const struct V_102 * V_83 ,
const char * V_78 , int V_16 )
{
struct V_9 * V_9 ;
if ( ! V_4 || ! V_50 || ! V_83 )
return NULL ;
V_9 = F_26 ( sizeof( struct V_9 ) + V_16 , V_33 ) ;
if ( ! V_9 ) {
F_2 ( V_4 , L_59 , V_72 ) ;
return NULL ;
}
V_9 -> V_50 = V_50 ;
V_9 -> V_83 = V_83 ;
V_9 -> V_78 = V_78 ;
V_9 -> V_52 = & V_9 [ 1 ] ;
F_76 ( & V_9 -> V_4 ) ;
V_9 -> V_4 . V_10 = V_4 ;
V_9 -> V_4 . type = & V_103 ;
V_9 -> V_100 = F_77 ( & V_101 , 0 , 0 , V_33 ) ;
if ( V_9 -> V_100 < 0 ) {
F_2 ( V_4 , L_60 , V_9 -> V_100 ) ;
F_78 ( & V_9 -> V_4 ) ;
return NULL ;
}
F_79 ( & V_9 -> V_4 , L_61 , V_9 -> V_100 ) ;
F_80 ( & V_9 -> V_94 , 0 ) ;
V_9 -> V_104 = & V_105 ;
F_81 ( & V_9 -> V_90 ) ;
F_82 ( & V_9 -> V_32 ) ;
F_83 ( & V_9 -> V_63 ) ;
F_83 ( & V_9 -> V_58 ) ;
F_83 ( & V_9 -> V_53 ) ;
F_83 ( & V_9 -> V_47 ) ;
V_9 -> V_85 = V_97 ;
return V_9 ;
}
void F_84 ( struct V_9 * V_9 )
{
F_78 ( & V_9 -> V_4 ) ;
}
int F_85 ( struct V_9 * V_9 )
{
struct V_22 * V_23 , * V_76 ;
if ( ! V_9 )
return - V_34 ;
F_86 ( & V_9 -> V_88 ) ;
F_39 (rvdev, tmp, &rproc->rvdevs, node)
F_87 ( V_23 ) ;
F_88 ( & V_9 -> V_4 ) ;
return 0 ;
}
static int T_5 F_89 ( void )
{
F_90 () ;
return 0 ;
}
static void T_6 F_91 ( void )
{
F_92 () ;
}
