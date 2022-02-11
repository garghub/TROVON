static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
T_1 V_4 = F_2 ( V_3 -> V_4 ) * 2 ;
T_2 V_5 , V_6 ;
int V_7 = 0 ;
V_5 = V_8 ;
F_3 ( V_2 , V_5 , 0 ) ;
V_4 = F_4 ( V_4 , 8 ) ;
while ( V_4 ) {
V_6 = V_3 -> V_9 [ V_7 ] ;
V_5 = F_5 ( V_7 ) ;
F_3 ( V_2 , V_5 , V_6 ) ;
V_4 -= 8 ;
V_7 ++ ;
}
V_5 = F_6 ( V_10 ) ;
F_3 ( V_2 , V_5 , ( ~ 0ULL ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 . V_12 ; V_7 ++ ) {
V_5 = F_7 ( V_7 ) ;
F_3 ( V_2 , V_5 , 0x8 ) ;
}
F_8 ( 300 , 400 ) ;
}
static int F_9 ( struct V_1 * V_2 , const char * V_13 )
{
const struct V_14 * V_15 ;
struct V_3 * V_3 ;
int V_16 ;
F_10 ( F_11 ( V_2 ) , L_1 , V_13 ) ;
V_16 = F_12 ( & V_15 , V_13 , F_11 ( V_2 ) ) ;
if ( V_16 < 0 ) {
F_13 ( F_11 ( V_2 ) , L_2 , V_13 ) ;
return V_16 ;
}
V_3 = (struct V_3 * ) V_15 -> V_6 ;
memcpy ( V_2 -> V_11 . V_13 , V_3 -> V_17 , ( V_18 - 2 ) ) ;
V_2 -> V_11 . V_13 [ V_18 - 1 ] = '\0' ;
F_1 ( V_2 , V_3 ) ;
F_14 ( V_15 ) ;
F_15 ( V_19 , & V_2 -> V_20 ) ;
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_1 * V_21 ;
int V_16 = 0 ;
F_18 ( & V_2 -> V_22 ) ;
F_19 ( & V_2 -> V_23 , 1 ) ;
F_20 ( & V_24 ) ;
F_21 (dev, &ndevlist, list) {
if ( V_21 == V_2 ) {
V_16 = - V_25 ;
goto V_26;
}
}
V_2 -> V_27 = V_28 ++ ;
F_22 ( & V_2 -> V_22 , & V_29 ) ;
V_26:
F_23 ( & V_24 ) ;
return V_16 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_20 ( & V_24 ) ;
F_25 ( & V_2 -> V_22 ) ;
V_28 -- ;
F_23 ( & V_24 ) ;
}
struct V_1 * F_26 ( void )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_24 ) ;
F_21 (ndev, &ndevlist, list) {
if ( F_27 ( V_2 ) )
break;
}
F_23 ( & V_24 ) ;
if ( ! V_2 )
return NULL ;
F_28 ( & V_2 -> V_23 ) ;
F_16 () ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_30 ( & V_2 -> V_23 ) ;
F_16 () ;
}
static int F_31 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
V_32 = F_32 ( V_31 ) ;
if ( V_32 ) {
F_13 ( & V_31 -> V_21 , L_3 ) ;
return - V_33 ;
}
V_32 = F_33 ( V_31 ) ;
if ( ! V_32 )
return - V_34 ;
if ( ! F_34 ( V_31 ) )
F_13 ( & V_31 -> V_21 , L_4 ) ;
F_35 ( V_31 , V_35 , V_36 ) ;
F_36 ( 100 ) ;
F_37 ( V_31 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_39 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_40 ( V_2 ) ;
if ( V_37 )
F_41 ( V_2 ) ;
return V_37 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_2 V_38 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ ) {
V_38 += F_45 ( V_2 , F_46 ( V_7 ) ) ;
V_38 += F_45 ( V_2 , F_47 ( V_7 ) ) ;
}
V_38 += F_45 ( V_2 , V_40 ) ;
V_38 += F_45 ( V_2 , V_41 ) ;
V_38 += F_45 ( V_2 , V_42 ) ;
V_38 += F_45 ( V_2 , V_43 ) ;
V_38 += F_45 ( V_2 , V_44 ) ;
V_38 += F_45 ( V_2 , V_45 ) ;
V_38 += F_45 ( V_2 , V_46 ) ;
V_38 += F_45 ( V_2 , V_47 ) ;
V_38 += F_45 ( V_2 , V_48 ) ;
V_38 += F_45 ( V_2 , V_49 ) ;
V_38 += F_45 ( V_2 , F_48 ( 0 ) ) ;
if ( V_38 )
return - V_50 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
union V_51 V_52 ;
T_2 V_5 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ ) {
T_3 V_53 ;
V_5 = F_50 ( V_7 ) ;
V_52 . V_38 = F_45 ( V_2 , V_5 ) ;
if ( V_52 . V_54 . V_55 ) {
V_53 = F_51 ( V_52 . V_54 . V_56 ) ;
V_2 -> V_11 . V_57 += V_58 - V_53 ;
V_53 = F_52 ( V_52 . V_54 . V_59 ) ;
V_2 -> V_11 . V_12 += V_60 - V_53 ;
}
}
}
static int F_53 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_44 ( V_2 ) ;
if ( V_37 ) {
F_13 ( & V_2 -> V_31 -> V_21 , L_5 ) ;
return V_37 ;
}
F_49 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_37 = F_9 ( V_2 , V_61 ) ;
if ( V_37 )
return V_37 ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_62 * V_54 , void * V_63 )
{
struct V_1 * V_2 = V_54 -> V_64 ;
T_2 V_5 ;
V_5 = V_65 ;
F_63 ( V_54 , L_6 ,
F_45 ( V_2 , V_5 ) ) ;
V_5 = V_66 ;
F_63 ( V_54 , L_7 ,
F_45 ( V_2 , V_5 ) ) ;
V_5 = V_67 ;
F_63 ( V_54 , L_8 ,
F_45 ( V_2 , V_5 ) ) ;
V_5 = V_68 ;
F_63 ( V_54 , L_9 ,
F_45 ( V_2 , V_5 ) ) ;
return 0 ;
}
static int F_64 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_65 ( V_70 , F_62 , V_69 -> V_71 ) ;
}
static int F_66 ( struct V_62 * V_54 , void * V_63 )
{
struct V_1 * V_2 = V_54 -> V_64 ;
F_63 ( V_54 , L_10 , V_2 -> V_11 . V_13 ) ;
return 0 ;
}
static int F_67 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_65 ( V_70 , F_66 , V_69 -> V_71 ) ;
}
static int F_68 ( struct V_62 * V_54 , void * V_63 )
{
struct V_1 * V_2 = V_54 -> V_64 ;
F_63 ( V_54 , L_11 , V_2 -> V_27 ) ;
F_63 ( V_54 , L_12 , V_2 -> V_11 . V_72 ) ;
F_63 ( V_54 , L_13 ,
V_2 -> V_11 . V_57 , V_2 -> V_11 . V_12 ) ;
F_63 ( V_54 , L_14 , V_2 -> V_73 ) ;
F_63 ( V_54 , L_15 , V_2 -> V_74 ) ;
F_63 ( V_54 , L_16 , V_2 -> V_75 ) ;
return 0 ;
}
static int F_69 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_65 ( V_70 , F_68 , V_69 -> V_71 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_77 * V_78 , * V_79 ;
V_78 = F_73 ( V_80 , NULL ) ;
if ( ! V_78 )
return - V_33 ;
V_2 -> V_76 = V_78 ;
V_79 = F_74 ( L_17 , 0400 , V_78 , V_2 , & V_81 ) ;
if ( ! V_79 )
goto V_37;
V_79 = F_74 ( L_18 , 0400 , V_78 , V_2 , & V_82 ) ;
if ( ! V_79 )
goto V_37;
V_79 = F_74 ( L_19 , 0400 , V_78 , V_2 , & V_83 ) ;
if ( ! V_79 )
goto V_37;
return 0 ;
V_37:
F_70 ( V_2 ) ;
return - V_84 ;
}
static int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
}
static int F_75 ( struct V_30 * V_31 ,
const struct V_85 * V_86 )
{
struct V_1 * V_2 ;
int V_37 ;
F_76 ( & V_31 -> V_21 , L_20 ,
V_87 , V_88 ) ;
V_37 = F_77 ( V_31 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_31 ( V_31 ) ;
if ( V_37 ) {
F_13 ( & V_31 -> V_21 , L_21 ) ;
F_78 ( V_31 ) ;
return V_37 ;
}
if ( ! F_79 ( & V_31 -> V_21 , F_80 ( 64 ) ) ) {
F_81 ( & V_31 -> V_21 , L_22 ) ;
} else {
V_37 = F_79 ( & V_31 -> V_21 , F_80 ( 32 ) ) ;
if ( V_37 ) {
F_13 ( & V_31 -> V_21 , L_23 ) ;
F_78 ( V_31 ) ;
return V_37 ;
}
}
V_37 = F_82 ( V_31 , V_87 ) ;
if ( V_37 ) {
F_78 ( V_31 ) ;
return V_37 ;
}
F_83 ( V_31 ) ;
V_2 = F_84 ( sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 ) {
V_37 = - V_33 ;
goto V_90;
}
F_85 ( V_31 , V_2 ) ;
V_2 -> V_31 = V_31 ;
F_17 ( V_2 ) ;
V_2 -> V_11 . V_91 = V_31 -> V_92 ;
V_2 -> V_11 . V_93 = V_31 -> V_94 ;
V_2 -> V_11 . V_72 = V_31 -> V_95 ;
V_2 -> V_96 = F_86 ( V_97 ) ;
V_2 -> V_75 = F_87 ( & V_31 -> V_21 ) ;
if ( V_2 -> V_75 == V_98 )
V_2 -> V_75 = 0 ;
V_2 -> V_99 = F_88 ( F_89 ( V_31 , 0 ) ,
F_90 ( V_31 , 0 ) ) ;
if ( ! V_2 -> V_99 ) {
V_37 = - V_50 ;
goto V_100;
}
V_2 -> V_73 = F_91 ( T_1 , V_101 , F_92 () ) ;
V_2 -> V_74 = V_74 ;
V_37 = F_38 ( V_2 ) ;
if ( V_37 )
goto V_100;
V_37 = F_53 ( V_2 ) ;
if ( V_37 )
goto V_102;
V_37 = F_72 ( V_2 ) ;
if ( V_37 )
goto V_102;
F_15 ( V_103 , & V_2 -> V_20 ) ;
F_16 () ;
V_37 = F_93 () ;
if ( V_37 )
goto V_104;
return 0 ;
V_104:
F_70 ( V_2 ) ;
F_94 ( V_103 , & V_2 -> V_20 ) ;
F_16 () ;
V_102:
F_42 ( V_2 ) ;
V_100:
F_24 ( V_2 ) ;
F_95 ( V_2 ) ;
F_85 ( V_31 , NULL ) ;
V_90:
F_96 ( V_31 ) ;
F_78 ( V_31 ) ;
return V_37 ;
}
static void F_97 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_98 ( V_31 ) ;
if ( ! V_2 )
return;
if ( ! F_99 ( & V_2 -> V_23 ) ) {
F_13 ( F_11 ( V_2 ) , L_24 ,
F_100 ( & V_2 -> V_23 ) ) ;
return;
}
F_10 ( F_11 ( V_2 ) , L_25 ,
V_2 -> V_11 . V_91 , V_2 -> V_11 . V_93 ) ;
F_94 ( V_103 , & V_2 -> V_20 ) ;
F_16 () ;
F_24 ( V_2 ) ;
F_101 () ;
F_70 ( V_2 ) ;
F_42 ( V_2 ) ;
F_102 ( V_2 -> V_99 ) ;
F_95 ( V_2 ) ;
F_85 ( V_31 , NULL ) ;
F_96 ( V_31 ) ;
F_78 ( V_31 ) ;
}
static void F_103 ( struct V_30 * V_31 )
{
F_85 ( V_31 , NULL ) ;
F_96 ( V_31 ) ;
F_78 ( V_31 ) ;
}
