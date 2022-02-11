static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_1 -> V_8 , struct V_3 , V_9 ) ;
if ( ! V_4 )
return - V_10 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
F_4 ( V_4 -> V_4 , L_1 ,
F_5 ( V_4 -> V_12 ) ) ;
V_7 = - V_10 ;
goto V_14;
}
V_6 = F_6 ( V_4 , V_15 ) ;
if ( F_7 ( V_6 ) ) {
V_7 = F_8 ( V_6 ) ;
goto V_14;
}
V_2 -> V_16 = V_6 ;
F_9 ( & V_4 -> V_11 ) ;
return F_10 ( V_1 , V_2 ) ;
V_14:
F_9 ( & V_4 -> V_11 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_17 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_13 ( V_4 , V_2 ) ;
goto V_19;
}
if ( F_14 ( V_6 ) ) {
V_6 -> V_20 = V_21 ;
F_15 ( V_4 , V_6 , L_2 ) ;
V_17 = F_16 ( V_6 ) ;
}
F_17 ( V_6 , V_2 ) ;
F_15 ( V_4 , V_6 , L_3 ) ;
F_18 ( V_6 ) ;
V_2 -> V_16 = NULL ;
F_19 ( V_6 ) ;
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_20 ( struct V_2 * V_2 , char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
struct V_25 * V_26 = NULL ;
int V_17 ;
int V_7 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
if ( V_23 == 0 ) {
V_17 = 0 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_21 ( V_4 , V_2 , V_22 , V_23 , V_24 ) ;
goto V_19;
}
V_26 = F_22 ( V_6 , V_2 ) ;
if ( V_26 ) {
if ( V_26 -> V_27 > * V_24 )
goto V_28;
if ( V_26 -> V_27 > 0 && V_26 -> V_27 <= * V_24 ) {
V_17 = 0 ;
goto free;
}
if ( V_26 -> V_27 == 0 && * V_24 > 0 )
* V_24 = 0 ;
} else if ( * V_24 > 0 ) {
* V_24 = 0 ;
}
V_7 = F_23 ( V_6 , V_23 , V_2 ) ;
if ( V_7 && V_7 != - V_29 ) {
F_4 ( V_4 -> V_4 ,
L_4 , V_7 ) ;
V_17 = V_7 ;
goto V_19;
}
if ( F_24 ( & V_6 -> V_30 ) && ! F_25 ( & V_6 -> V_31 ) ) {
if ( V_2 -> V_32 & V_33 ) {
V_17 = - V_34 ;
goto V_19;
}
F_9 ( & V_4 -> V_11 ) ;
if ( F_26 ( V_6 -> V_31 ,
( ! F_24 ( & V_6 -> V_30 ) ) ||
( ! F_14 ( V_6 ) ) ) ) {
if ( F_27 ( V_35 ) )
return - V_36 ;
return - V_37 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_14 ( V_6 ) ) {
V_17 = - V_29 ;
goto V_19;
}
}
V_26 = F_22 ( V_6 , V_2 ) ;
if ( ! V_26 ) {
V_17 = 0 ;
goto V_19;
}
V_28:
if ( V_26 -> V_38 ) {
V_17 = V_26 -> V_38 ;
F_4 ( V_4 -> V_4 , L_5 , V_17 ) ;
goto free;
}
F_4 ( V_4 -> V_4 , L_6 ,
V_26 -> V_39 . V_40 , V_26 -> V_27 ) ;
if ( V_23 == 0 || V_22 == NULL || * V_24 > V_26 -> V_27 ) {
V_17 = - V_41 ;
goto free;
}
V_23 = F_28 ( T_3 , V_23 , V_26 -> V_27 - * V_24 ) ;
if ( F_29 ( V_22 , V_26 -> V_39 . V_42 + * V_24 , V_23 ) ) {
F_4 ( V_4 -> V_4 , L_7 ) ;
V_17 = - V_43 ;
goto free;
}
V_17 = V_23 ;
* V_24 += V_23 ;
if ( ( unsigned long ) * V_24 < V_26 -> V_27 )
goto V_19;
free:
F_30 ( V_26 ) ;
V_19:
F_4 ( V_4 -> V_4 , L_8 , V_17 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_31 ( struct V_2 * V_2 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_44 * V_45 = NULL ;
struct V_25 * V_46 = NULL ;
struct V_3 * V_4 ;
unsigned long V_47 = 0 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
V_45 = F_32 ( V_4 , & V_6 -> V_48 , V_6 -> V_49 ) ;
if ( ! V_45 ) {
V_17 = - V_50 ;
goto V_19;
}
if ( V_23 == 0 ) {
V_17 = 0 ;
goto V_19;
}
if ( V_23 > V_45 -> V_51 . V_52 ) {
V_17 = - V_53 ;
goto V_19;
}
if ( ! F_14 ( V_6 ) ) {
F_33 ( V_4 , V_6 , L_9 ) ;
V_17 = - V_10 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_46 = F_34 ( V_4 , V_2 ) ;
if ( V_46 ) {
V_47 = V_46 -> V_54 +
F_35 ( V_55 ) ;
if ( F_36 ( V_56 , V_47 ) ) {
* V_24 = 0 ;
F_30 ( V_46 ) ;
V_46 = NULL ;
}
}
}
* V_24 = 0 ;
V_46 = F_37 ( V_6 , V_23 , V_57 , V_2 ) ;
if ( ! V_46 ) {
V_17 = - V_58 ;
goto V_19;
}
V_17 = F_38 ( V_46 -> V_39 . V_42 , V_22 , V_23 ) ;
if ( V_17 ) {
F_4 ( V_4 -> V_4 , L_10 ) ;
V_17 = - V_43 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_39 ( V_6 , V_46 ) ;
if ( V_17 ) {
F_40 ( V_4 -> V_4 ,
L_11 , V_17 ) ;
goto V_19;
}
F_41 ( V_45 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_23 ;
}
V_17 = F_42 ( V_6 , V_46 , false ) ;
V_19:
F_41 ( V_45 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_17 < 0 )
F_30 ( V_46 ) ;
return V_17 ;
}
static int F_43 ( struct V_2 * V_2 ,
struct V_59 * V_42 )
{
struct V_3 * V_4 ;
struct V_60 * V_61 ;
struct V_44 * V_45 ;
struct V_5 * V_6 ;
int V_17 ;
V_6 = V_2 -> V_16 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 )
return - V_10 ;
if ( V_6 -> V_20 != V_62 &&
V_6 -> V_20 != V_63 )
return - V_29 ;
V_45 = F_44 ( V_4 , & V_42 -> V_64 ) ;
if ( ! V_45 || V_45 -> V_51 . V_65 ) {
F_4 ( V_4 -> V_4 , L_12 ,
& V_42 -> V_64 ) ;
return - V_50 ;
}
V_6 -> V_49 = V_45 -> V_66 ;
V_6 -> V_48 = V_45 -> V_51 . V_67 ;
F_4 ( V_4 -> V_4 , L_13 ,
V_6 -> V_49 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_45 -> V_51 . V_68 ) ;
F_4 ( V_4 -> V_4 , L_15 ,
V_45 -> V_51 . V_52 ) ;
if ( F_45 ( V_42 -> V_64 , V_69 ) == 0 ) {
F_4 ( V_4 -> V_4 , L_16 ) ;
if ( ! F_14 ( & V_4 -> V_18 ) ) {
V_17 = - V_10 ;
goto V_70;
}
F_18 ( V_6 ) ;
F_19 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_71 ++ ;
V_2 -> V_16 = & V_4 -> V_18 ;
V_61 = & V_42 -> V_72 ;
V_61 -> V_52 = V_45 -> V_51 . V_52 ;
V_61 -> V_68 = V_45 -> V_51 . V_68 ;
V_17 = V_4 -> V_18 . V_38 ;
goto V_70;
}
V_61 = & V_42 -> V_72 ;
V_61 -> V_52 = V_45 -> V_51 . V_52 ;
V_61 -> V_68 = V_45 -> V_51 . V_68 ;
F_4 ( V_4 -> V_4 , L_17 ) ;
V_17 = F_46 ( V_6 , V_2 ) ;
V_70:
F_41 ( V_45 ) ;
return V_17 ;
}
static long F_47 ( struct V_2 * V_2 , unsigned int V_73 , unsigned long V_42 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_59 V_74 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( V_4 -> V_4 , L_18 , V_73 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
switch ( V_73 ) {
case V_75 :
F_4 ( V_4 -> V_4 , L_19 ) ;
if ( F_38 ( & V_74 , ( char T_2 * ) V_42 ,
sizeof( struct V_59 ) ) ) {
F_4 ( V_4 -> V_4 , L_10 ) ;
V_17 = - V_43 ;
goto V_19;
}
V_17 = F_43 ( V_2 , & V_74 ) ;
if ( V_17 )
goto V_19;
if ( F_29 ( ( char T_2 * ) V_42 , & V_74 ,
sizeof( struct V_59 ) ) ) {
F_4 ( V_4 -> V_4 , L_7 ) ;
V_17 = - V_43 ;
goto V_19;
}
break;
default:
F_40 ( V_4 -> V_4 , L_20 , V_73 ) ;
V_17 = - V_76 ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static long F_48 ( struct V_2 * V_2 ,
unsigned int V_73 , unsigned long V_42 )
{
return F_47 ( V_2 , V_73 , ( unsigned long ) F_49 ( V_42 ) ) ;
}
static unsigned int F_50 ( struct V_2 * V_2 , T_5 * V_77 )
{
unsigned long V_78 = F_51 ( V_77 ) ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
unsigned int V_79 = 0 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_80 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ||
! F_14 ( V_6 ) ) {
V_79 = V_80 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_79 = F_52 ( V_4 , V_2 , V_77 ) ;
goto V_19;
}
if ( V_78 & ( V_81 | V_82 ) ) {
F_53 ( V_2 , & V_6 -> V_31 , V_77 ) ;
if ( ! F_24 ( & V_6 -> V_30 ) )
V_79 |= V_81 | V_82 ;
else
F_23 ( V_6 , 0 , V_2 ) ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_79 ;
}
static T_1 F_54 ( struct V_83 * V_83 ,
struct V_84 * V_85 , char * V_39 )
{
struct V_3 * V_4 = F_55 ( V_83 ) ;
struct V_86 V_87 ;
int V_7 , V_88 ;
T_1 V_89 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_7 = V_86 ( V_4 , & V_87 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_7 ) {
F_40 ( V_83 , L_21 , V_7 ) ;
return V_7 ;
}
for ( V_88 = 0 ; V_88 < V_87 . V_90 ; V_88 ++ )
V_89 += F_56 ( V_39 + V_89 , V_91 - V_89 , L_22 ,
V_87 . V_38 [ V_88 ] ) ;
return V_89 ;
}
static int F_57 ( struct V_3 * V_4 )
{
int V_92 ;
F_3 ( & V_93 ) ;
V_92 = F_58 ( & V_94 , V_4 , 0 , V_95 , V_96 ) ;
if ( V_92 >= 0 )
V_4 -> V_97 = V_92 ;
else if ( V_92 == - V_98 )
F_40 ( V_4 -> V_4 , L_23 ) ;
F_9 ( & V_93 ) ;
return V_92 ;
}
static void F_59 ( struct V_3 * V_4 )
{
F_3 ( & V_93 ) ;
F_60 ( & V_94 , V_4 -> V_97 ) ;
F_9 ( & V_93 ) ;
}
int F_61 ( struct V_3 * V_4 , struct V_83 * V_99 )
{
struct V_83 * V_100 ;
int V_92 , V_101 ;
V_92 = F_57 ( V_4 ) ;
if ( V_92 < 0 )
return V_92 ;
V_101 = F_62 ( F_63 ( V_102 ) , V_4 -> V_97 ) ;
F_64 ( & V_4 -> V_9 , & V_103 ) ;
V_4 -> V_9 . V_104 = V_103 . V_104 ;
V_92 = F_65 ( & V_4 -> V_9 , V_101 , 1 ) ;
if ( V_92 ) {
F_40 ( V_99 , L_24 ,
F_63 ( V_102 ) , V_4 -> V_97 ) ;
goto V_105;
}
V_100 = F_66 ( V_106 , V_99 , V_101 ,
V_4 , V_107 ,
L_25 , V_4 -> V_97 ) ;
if ( F_7 ( V_100 ) ) {
F_40 ( V_99 , L_26 ,
F_63 ( V_102 ) , V_4 -> V_97 ) ;
V_92 = F_8 ( V_100 ) ;
goto V_108;
}
V_92 = F_67 ( V_4 , F_68 ( V_100 ) ) ;
if ( V_92 ) {
F_40 ( V_100 , L_27 , V_92 ) ;
goto V_109;
}
return 0 ;
V_109:
F_69 ( V_106 , V_101 ) ;
V_108:
F_70 ( & V_4 -> V_9 ) ;
V_105:
F_59 ( V_4 ) ;
return V_92 ;
}
void F_71 ( struct V_3 * V_4 )
{
int V_101 ;
V_101 = V_4 -> V_9 . V_4 ;
F_70 ( & V_4 -> V_9 ) ;
F_72 ( V_4 ) ;
F_69 ( V_106 , V_101 ) ;
F_59 ( V_4 ) ;
}
static int T_6 F_73 ( void )
{
int V_92 ;
V_106 = F_74 ( V_110 , L_28 ) ;
if ( F_7 ( V_106 ) ) {
F_75 ( L_29 ) ;
V_92 = F_8 ( V_106 ) ;
goto V_7;
}
V_92 = F_76 ( & V_102 , 0 , V_95 , L_28 ) ;
if ( V_92 < 0 ) {
F_75 ( L_30 ) ;
goto V_111;
}
V_92 = F_77 () ;
if ( V_92 < 0 ) {
F_75 ( L_31 ) ;
goto V_112;
}
return 0 ;
V_112:
F_78 ( V_102 , V_95 ) ;
V_111:
F_79 ( V_106 ) ;
V_7:
return V_92 ;
}
static void T_7 F_80 ( void )
{
F_78 ( V_102 , V_95 ) ;
F_79 ( V_106 ) ;
F_81 () ;
}
