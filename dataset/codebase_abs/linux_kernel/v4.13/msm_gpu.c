static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
V_2 -> V_4 = F_2 ( V_2 -> V_3 ) ;
F_3 ( L_1 , V_2 -> V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_5 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_5 )
{
if ( V_2 -> V_4 ) {
F_3 ( L_2 , V_5 ) ;
F_7 ( V_2 -> V_4 , V_5 ) ;
}
}
static void F_1 ( struct V_1 * V_2 ) {}
static void F_4 ( struct V_1 * V_2 ) {}
static void F_6 ( struct V_1 * V_2 , int V_5 ) {}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_2 -> V_9 ) {
V_8 = F_9 ( V_2 -> V_9 ) ;
if ( V_8 ) {
F_10 ( V_7 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
}
if ( V_2 -> V_10 ) {
V_8 = F_9 ( V_2 -> V_10 ) ;
if ( V_8 ) {
F_10 ( V_7 -> V_7 , L_4 , V_8 ) ;
return V_8 ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 )
F_12 ( V_2 -> V_10 ) ;
if ( V_2 -> V_9 )
F_12 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_12 && V_2 -> V_13 )
F_14 ( V_2 -> V_12 , V_2 -> V_13 ) ;
if ( V_2 -> V_14 )
F_14 ( V_2 -> V_14 , 19200000 ) ;
for ( V_11 = V_2 -> V_15 - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_16 [ V_11 ] )
F_15 ( V_2 -> V_16 [ V_11 ] ) ;
for ( V_11 = V_2 -> V_15 - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_16 [ V_11 ] )
F_16 ( V_2 -> V_16 [ V_11 ] ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = V_2 -> V_15 - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_16 [ V_11 ] )
F_18 ( V_2 -> V_16 [ V_11 ] ) ;
for ( V_11 = V_2 -> V_15 - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_16 [ V_11 ] )
F_19 ( V_2 -> V_16 [ V_11 ] ) ;
if ( V_2 -> V_12 )
F_14 ( V_2 -> V_12 , 27000000 ) ;
if ( V_2 -> V_14 )
F_14 ( V_2 -> V_14 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_21 ( V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_6 ( V_2 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_23 ( V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_6 ( V_2 , 0 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_8 ;
F_3 ( L_5 , V_2 -> V_19 ) ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_20 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_20 = true ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_8 ;
F_3 ( L_5 , V_2 -> V_19 ) ;
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_8 ;
F_27 ( ! F_28 ( & V_2 -> V_7 -> V_21 ) ) ;
if ( ! V_2 -> V_20 )
return 0 ;
F_29 ( V_2 -> V_22 ) ;
V_8 = V_2 -> V_23 -> V_24 ( V_2 ) ;
if ( ! V_8 )
V_2 -> V_20 = false ;
F_30 ( V_2 -> V_22 ) ;
return V_8 ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_32 ( V_26 , struct V_1 , V_27 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 ;
T_1 V_30 = V_2 -> V_23 -> V_31 ( V_2 ) ;
F_33 ( V_2 -> V_32 , V_30 + 1 ) ;
F_34 ( & V_7 -> V_21 ) ;
F_10 ( V_7 -> V_7 , L_6 , V_2 -> V_19 ) ;
F_35 (submit, &gpu->submit_list, node) {
if ( V_29 -> V_30 -> V_33 == ( V_30 + 1 ) ) {
struct V_34 * V_35 ;
F_36 () ;
V_35 = F_37 ( V_29 -> V_36 , V_37 ) ;
if ( V_35 ) {
F_10 ( V_7 -> V_7 , L_7 ,
V_2 -> V_19 , V_35 -> V_38 ) ;
}
F_38 () ;
break;
}
}
if ( F_39 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_41 ( & V_2 -> V_39 -> V_7 ) ;
V_2 -> V_23 -> V_40 ( V_2 ) ;
F_42 ( & V_2 -> V_39 -> V_7 ) ;
F_35 (submit, &gpu->submit_list, node) {
V_2 -> V_23 -> V_29 ( V_2 , V_29 , NULL ) ;
}
}
F_43 ( & V_7 -> V_21 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_3 ( L_5 , V_2 -> V_19 ) ;
F_46 ( & V_2 -> V_41 ,
F_47 ( V_42 + V_43 ) ) ;
}
static void F_48 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_45 * V_46 = V_7 -> V_47 ;
T_1 V_30 = V_2 -> V_23 -> V_31 ( V_2 ) ;
if ( V_30 != V_2 -> V_48 ) {
V_2 -> V_48 = V_30 ;
} else if ( V_30 < V_2 -> V_32 -> V_31 ) {
V_2 -> V_48 = V_30 ;
F_10 ( V_7 -> V_7 , L_8 ,
V_2 -> V_19 ) ;
F_10 ( V_7 -> V_7 , L_9 ,
V_2 -> V_19 , V_30 ) ;
F_10 ( V_7 -> V_7 , L_10 ,
V_2 -> V_19 , V_2 -> V_32 -> V_31 ) ;
F_49 ( V_46 -> V_49 , & V_2 -> V_27 ) ;
}
if ( V_2 -> V_32 -> V_31 > V_2 -> V_48 )
F_45 ( V_2 ) ;
F_49 ( V_46 -> V_49 , & V_2 -> V_50 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_51 , T_1 * V_52 )
{
T_1 V_53 [ F_51 ( V_2 -> V_54 ) ] ;
int V_11 , V_55 = F_52 ( V_51 , V_2 -> V_56 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
V_53 [ V_11 ] = F_53 ( V_2 , V_2 -> V_57 [ V_11 ] . V_58 ) ;
for ( V_11 = 0 ; V_11 < V_55 ; V_11 ++ )
V_52 [ V_11 ] = V_53 [ V_11 ] - V_2 -> V_54 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
V_2 -> V_54 [ V_11 ] = V_53 [ V_11 ] ;
return V_55 ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_2 time ;
T_1 V_59 ;
unsigned long V_60 ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
if ( ! V_2 -> V_62 )
goto V_63;
time = F_56 () ;
V_59 = F_57 ( F_58 ( time , V_2 -> V_64 . time ) ) ;
V_2 -> V_65 += V_59 ;
if ( V_2 -> V_64 . V_66 )
V_2 -> V_67 += V_59 ;
V_2 -> V_64 . V_66 = F_39 ( V_2 ) ;
V_2 -> V_64 . time = time ;
V_63:
F_59 ( & V_2 -> V_61 , V_60 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
unsigned long V_60 ;
F_41 ( & V_2 -> V_39 -> V_7 ) ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
V_2 -> V_64 . V_66 = F_39 ( V_2 ) ;
V_2 -> V_64 . time = F_56 () ;
V_2 -> V_67 = V_2 -> V_65 = 0 ;
V_2 -> V_62 = true ;
F_50 ( V_2 , 0 , NULL ) ;
F_59 ( & V_2 -> V_61 , V_60 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_62 = false ;
F_42 ( & V_2 -> V_39 -> V_7 ) ;
}
int F_62 ( struct V_1 * V_2 , T_1 * V_67 ,
T_1 * V_65 , T_1 V_51 , T_1 * V_52 )
{
unsigned long V_60 ;
int V_8 ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
if ( ! V_2 -> V_62 ) {
V_8 = - V_68 ;
goto V_63;
}
* V_67 = V_2 -> V_67 ;
* V_65 = V_2 -> V_65 ;
V_2 -> V_67 = V_2 -> V_65 = 0 ;
V_8 = F_50 ( V_2 , V_51 , V_52 ) ;
V_63:
F_59 ( & V_2 -> V_61 , V_60 ) ;
return V_8 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_29 -> V_69 ; V_11 ++ ) {
struct V_70 * V_71 = V_29 -> V_72 [ V_11 ] . V_73 ;
F_64 ( & V_71 -> V_74 ) ;
F_65 ( & V_71 -> V_74 , V_2 -> V_75 ) ;
F_66 ( & V_71 -> V_74 ) ;
}
F_67 ( & V_2 -> V_39 -> V_7 ) ;
F_68 ( & V_2 -> V_39 -> V_7 ) ;
F_69 ( V_29 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_27 ( ! F_28 ( & V_7 -> V_21 ) ) ;
while ( ! F_70 ( & V_2 -> V_76 ) ) {
struct V_28 * V_29 ;
V_29 = F_71 ( & V_2 -> V_76 ,
struct V_28 , V_77 ) ;
if ( F_72 ( V_29 -> V_30 ) ) {
F_63 ( V_2 , V_29 ) ;
} else {
break;
}
}
}
static void F_73 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_32 ( V_26 , struct V_1 , V_50 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_30 = V_2 -> V_23 -> V_31 ( V_2 ) ;
F_33 ( V_2 -> V_32 , V_30 ) ;
F_34 ( & V_7 -> V_21 ) ;
F_40 ( V_2 ) ;
F_43 ( & V_7 -> V_21 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_7 -> V_47 ;
F_49 ( V_46 -> V_49 , & V_2 -> V_50 ) ;
F_54 ( V_2 ) ;
}
void F_74 ( struct V_1 * V_2 , struct V_28 * V_29 ,
struct V_78 * V_79 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_45 * V_46 = V_7 -> V_47 ;
int V_11 ;
F_27 ( ! F_28 ( & V_7 -> V_21 ) ) ;
F_41 ( & V_2 -> V_39 -> V_7 ) ;
F_26 ( V_2 ) ;
F_75 ( & V_29 -> V_77 , & V_2 -> V_76 ) ;
F_76 ( V_29 ) ;
F_54 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_29 -> V_69 ; V_11 ++ ) {
struct V_70 * V_71 = V_29 -> V_72 [ V_11 ] . V_73 ;
T_3 V_80 ;
F_27 ( F_77 ( V_71 ) && ( V_71 -> V_2 != V_2 ) ) ;
F_78 ( & V_71 -> V_74 ) ;
F_79 ( & V_71 -> V_74 ,
V_29 -> V_2 -> V_75 , & V_80 ) ;
if ( V_29 -> V_72 [ V_11 ] . V_60 & V_81 )
F_80 ( & V_71 -> V_74 , V_2 , true , V_29 -> V_30 ) ;
else if ( V_29 -> V_72 [ V_11 ] . V_60 & V_82 )
F_80 ( & V_71 -> V_74 , V_2 , false , V_29 -> V_30 ) ;
}
V_2 -> V_23 -> V_29 ( V_2 , V_29 , V_79 ) ;
V_46 -> V_83 = V_79 ;
F_45 ( V_2 ) ;
}
static T_4 F_81 ( int V_22 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
return V_2 -> V_23 -> V_22 ( V_2 ) ;
}
static struct V_84 * F_82 ( struct V_85 * V_7 , const char * V_19 )
{
struct V_84 * V_84 = F_83 ( V_7 , V_19 ) ;
return F_84 ( V_84 ) ? NULL : V_84 ;
}
static int F_85 ( struct V_86 * V_39 , struct V_1 * V_2 )
{
struct V_85 * V_7 = & V_39 -> V_7 ;
struct V_87 * V_88 ;
const char * V_19 ;
int V_11 = 0 ;
V_2 -> V_15 = F_86 ( V_7 -> V_89 , L_11 ) ;
if ( V_2 -> V_15 < 1 ) {
V_2 -> V_15 = 0 ;
return 0 ;
}
V_2 -> V_16 = F_87 ( V_7 , sizeof( struct V_84 * ) , V_2 -> V_15 ,
V_90 ) ;
if ( ! V_2 -> V_16 )
return - V_91 ;
F_88 (dev->of_node, L_11 , prop, name) {
V_2 -> V_16 [ V_11 ] = F_82 ( V_7 , V_19 ) ;
if ( ! strcmp ( V_19 , L_12 ) || ! strcmp ( V_19 , L_13 ) )
V_2 -> V_12 = V_2 -> V_16 [ V_11 ] ;
else if ( ! strcmp ( V_19 , L_14 ) || ! strcmp ( V_19 , L_15 ) )
V_2 -> V_14 = V_2 -> V_16 [ V_11 ] ;
++ V_11 ;
}
return 0 ;
}
int F_89 ( struct V_6 * V_92 , struct V_86 * V_39 ,
struct V_1 * V_2 , const struct V_93 * V_23 ,
const char * V_19 , struct V_94 * V_95 )
{
struct V_96 * V_97 ;
int V_8 ;
if ( F_27 ( V_2 -> V_56 > F_51 ( V_2 -> V_54 ) ) )
V_2 -> V_56 = F_51 ( V_2 -> V_54 ) ;
V_2 -> V_7 = V_92 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_32 = F_90 ( V_92 , V_19 ) ;
if ( F_84 ( V_2 -> V_32 ) ) {
V_8 = F_91 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
goto V_98;
}
F_92 ( & V_2 -> V_99 ) ;
F_93 ( & V_2 -> V_50 , F_73 ) ;
F_93 ( & V_2 -> V_27 , F_31 ) ;
F_92 ( & V_2 -> V_76 ) ;
F_94 ( & V_2 -> V_41 , F_48 ,
( unsigned long ) V_2 ) ;
F_95 ( & V_2 -> V_61 ) ;
V_2 -> V_100 = F_96 ( V_39 , V_95 -> V_101 , V_19 ) ;
if ( F_84 ( V_2 -> V_100 ) ) {
V_8 = F_91 ( V_2 -> V_100 ) ;
goto V_98;
}
V_2 -> V_22 = F_97 ( V_39 , V_95 -> V_102 ) ;
if ( V_2 -> V_22 < 0 ) {
V_8 = V_2 -> V_22 ;
F_10 ( V_92 -> V_7 , L_16 , V_8 ) ;
goto V_98;
}
V_8 = F_98 ( & V_39 -> V_7 , V_2 -> V_22 , F_81 ,
V_103 , V_2 -> V_19 , V_2 ) ;
if ( V_8 ) {
F_10 ( V_92 -> V_7 , L_17 , V_2 -> V_22 , V_8 ) ;
goto V_98;
}
V_8 = F_85 ( V_39 , V_2 ) ;
if ( V_8 )
goto V_98;
V_2 -> V_17 = F_99 ( V_39 , L_18 ) ;
F_3 ( L_19 , V_2 -> V_17 ) ;
if ( F_84 ( V_2 -> V_17 ) )
V_2 -> V_17 = NULL ;
V_2 -> V_9 = F_100 ( & V_39 -> V_7 , L_20 ) ;
F_3 ( L_21 , V_2 -> V_9 ) ;
if ( F_84 ( V_2 -> V_9 ) )
V_2 -> V_9 = NULL ;
V_2 -> V_10 = F_100 ( & V_39 -> V_7 , L_22 ) ;
F_3 ( L_23 , V_2 -> V_10 ) ;
if ( F_84 ( V_2 -> V_10 ) )
V_2 -> V_10 = NULL ;
V_97 = F_101 ( & V_104 ) ;
if ( V_97 ) {
V_97 -> V_105 . V_106 = V_95 -> va_start ;
V_97 -> V_105 . V_107 = V_95 -> va_end ;
F_102 ( V_92 -> V_7 , L_24 , V_19 ) ;
V_2 -> V_75 = F_103 ( & V_39 -> V_7 ,
V_97 , L_25 ) ;
if ( F_84 ( V_2 -> V_75 ) ) {
V_8 = F_91 ( V_2 -> V_75 ) ;
F_10 ( V_92 -> V_7 , L_26 , V_8 ) ;
V_2 -> V_75 = NULL ;
F_104 ( V_97 ) ;
goto V_98;
}
} else {
F_102 ( V_92 -> V_7 , L_27 , V_19 ) ;
}
V_2 -> V_108 = F_105 ( V_2 , V_95 -> V_109 ) ;
if ( F_84 ( V_2 -> V_108 ) ) {
V_8 = F_91 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
F_10 ( V_92 -> V_7 , L_28 , V_8 ) ;
goto V_98;
}
V_2 -> V_39 = V_39 ;
F_106 ( V_39 , V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_98:
return V_8 ;
}
void F_107 ( struct V_1 * V_2 )
{
F_3 ( L_5 , V_2 -> V_19 ) ;
F_27 ( ! F_70 ( & V_2 -> V_99 ) ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_108 ) {
if ( V_2 -> V_110 )
F_65 ( V_2 -> V_108 -> V_111 , V_2 -> V_75 ) ;
F_108 ( V_2 -> V_108 ) ;
}
if ( V_2 -> V_32 )
F_109 ( V_2 -> V_32 ) ;
}
