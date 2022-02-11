static int
F_1 ( struct V_1 * V_1 , unsigned long V_2 ,
struct V_3 * V_4 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
void * V_7 ;
int V_8 ;
V_4 -> V_9 = 0 ;
V_8 = F_4 ( V_6 -> V_10 , V_2 , ( unsigned long ) V_4 ) ;
if ( F_5 ( V_8 ) )
return V_8 ;
F_6 ( V_4 ) ;
V_7 = F_7 ( V_4 -> V_11 ) ;
memset ( V_7 + F_8 ( V_4 ) , 0 , 1 << V_1 -> V_12 ) ;
if ( F_2 )
F_2 ( V_1 , V_4 , V_7 ) ;
F_9 ( V_4 -> V_11 ) ;
F_10 ( V_7 ) ;
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 , V_1 -> V_13 , V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned long V_2 ,
struct V_3 * * V_14 ,
void (* F_2)( struct V_1 * ,
struct V_3 * ,
void * ) )
{
struct V_15 * V_16 = V_1 -> V_17 ;
struct V_18 V_19 ;
struct V_3 * V_4 ;
int V_20 ;
F_16 ( V_16 , & V_19 , 0 ) ;
V_20 = - V_21 ;
V_4 = F_17 ( V_1 , V_1 -> V_22 , V_2 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_23;
V_20 = - V_24 ;
if ( F_18 ( V_4 ) )
goto V_25;
F_19 ( V_4 ) ;
if ( F_18 ( V_4 ) )
goto V_25;
V_4 -> V_26 = V_16 -> V_27 ;
V_20 = F_1 ( V_1 , V_2 , V_4 , F_2 ) ;
if ( F_20 ( ! V_20 ) ) {
F_21 ( V_4 ) ;
* V_14 = V_4 ;
}
V_25:
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 -> V_11 ) ;
F_24 ( V_4 ) ;
V_23:
if ( F_20 ( ! V_20 ) )
V_20 = F_25 ( V_16 ) ;
else
F_26 ( V_16 ) ;
return V_20 ;
}
static int
F_27 ( struct V_1 * V_1 , unsigned long V_28 ,
int V_29 , struct V_3 * * V_14 )
{
struct V_3 * V_4 ;
T_1 V_30 = 0 ;
int V_8 = - V_21 ;
V_4 = F_17 ( V_1 , V_1 -> V_22 , V_28 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_31;
V_8 = - V_24 ;
if ( F_18 ( V_4 ) )
goto V_32;
if ( V_29 == V_33 ) {
if ( ! F_28 ( V_4 ) ) {
V_8 = - V_34 ;
goto V_25;
}
} else
F_29 ( V_4 ) ;
if ( F_18 ( V_4 ) ) {
F_30 ( V_4 ) ;
goto V_32;
}
V_8 = F_31 ( F_3 ( V_1 ) -> V_10 , V_28 , & V_30 ) ;
if ( F_5 ( V_8 ) ) {
F_30 ( V_4 ) ;
goto V_25;
}
F_32 ( V_4 , V_1 -> V_17 , ( V_35 ) V_30 ) ;
V_4 -> V_36 = V_37 ;
F_21 ( V_4 ) ;
F_33 ( V_29 , V_4 ) ;
V_8 = 0 ;
F_34 ( V_1 , V_1 -> V_13 , V_28 , V_29 ) ;
V_32:
F_21 ( V_4 ) ;
* V_14 = V_4 ;
V_25:
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 -> V_11 ) ;
F_24 ( V_4 ) ;
V_31:
return V_8 ;
}
static int F_35 ( struct V_1 * V_1 , unsigned long V_2 ,
int V_38 , struct V_3 * * V_14 )
{
struct V_3 * V_39 , * V_4 ;
unsigned long V_28 ;
int V_40 , V_41 = V_42 ;
int V_20 ;
V_20 = F_27 ( V_1 , V_2 , V_43 , & V_39 ) ;
if ( V_20 == - V_24 )
goto V_32;
if ( F_5 ( V_20 ) )
goto V_31;
if ( V_38 ) {
V_28 = V_2 + 1 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ , V_28 ++ ) {
V_20 = F_27 ( V_1 , V_28 , V_33 , & V_4 ) ;
if ( F_20 ( ! V_20 || V_20 == - V_24 ) )
F_24 ( V_4 ) ;
else if ( V_20 != - V_34 )
break;
if ( ! F_36 ( V_39 ) )
goto V_44;
}
}
F_19 ( V_39 ) ;
V_44:
V_20 = - V_45 ;
if ( ! F_18 ( V_39 ) )
goto V_25;
V_32:
* V_14 = V_39 ;
return 0 ;
V_25:
F_24 ( V_39 ) ;
V_31:
return V_20 ;
}
int F_37 ( struct V_1 * V_1 , unsigned long V_28 , int V_46 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) ,
struct V_3 * * V_14 )
{
int V_8 ;
V_47:
V_8 = F_35 ( V_1 , V_28 , ! V_46 , V_14 ) ;
if ( ! V_46 || V_8 != - V_48 )
return V_8 ;
V_8 = F_15 ( V_1 , V_28 , V_14 , F_2 ) ;
if ( F_5 ( V_8 == - V_24 ) ) {
goto V_47;
}
return V_8 ;
}
int F_38 ( struct V_1 * V_1 , unsigned long V_49 ,
unsigned long V_50 , unsigned long * V_28 ,
struct V_3 * * V_14 )
{
T_1 V_51 ;
int V_8 ;
if ( F_5 ( V_49 > V_50 ) )
return - V_48 ;
V_8 = F_35 ( V_1 , V_49 , true , V_14 ) ;
if ( ! V_8 ) {
* V_28 = V_49 ;
goto V_32;
}
if ( F_5 ( V_8 != - V_48 || V_49 == V_52 ) )
goto V_32;
V_8 = F_39 ( F_3 ( V_1 ) -> V_10 , V_49 + 1 , & V_51 ) ;
if ( ! V_8 ) {
if ( V_51 <= V_50 ) {
V_8 = F_35 ( V_1 , V_51 , true , V_14 ) ;
if ( ! V_8 )
* V_28 = V_51 ;
} else {
V_8 = - V_48 ;
}
}
V_32:
return V_8 ;
}
int F_40 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
int V_20 ;
V_20 = F_41 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_20 || V_20 == - V_48 ) {
F_13 ( V_1 ) ;
F_42 ( V_1 , V_2 ) ;
}
return V_20 ;
}
int F_42 ( struct V_1 * V_1 , unsigned long V_2 )
{
T_2 V_53 = ( T_2 ) V_2 >>
( V_54 - V_1 -> V_12 ) ;
struct V_55 * V_55 ;
unsigned long V_56 ;
int V_8 = 0 ;
int V_57 ;
V_55 = F_43 ( V_1 -> V_22 , V_53 ) ;
if ( ! V_55 )
return - V_48 ;
F_44 ( V_55 ) ;
V_56 = ( unsigned long ) V_53 <<
( V_54 - V_1 -> V_12 ) ;
if ( F_45 ( V_55 ) ) {
struct V_3 * V_4 ;
V_4 = F_46 ( V_55 , V_2 - V_56 ) ;
F_47 ( V_4 ) ;
}
V_57 = F_48 ( V_55 ) ;
F_22 ( V_55 ) ;
F_23 ( V_55 ) ;
if ( V_57 ||
F_49 ( V_1 -> V_22 , V_53 , V_53 ) != 0 )
V_8 = - V_34 ;
return V_8 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
if ( F_51 ( V_6 -> V_10 ) ) {
F_52 ( V_58 , & V_6 -> V_59 ) ;
return 1 ;
}
return F_53 ( V_58 , & V_6 -> V_59 ) ;
}
static int
F_54 ( struct V_55 * V_55 , struct V_60 * V_61 )
{
struct V_1 * V_1 = V_55 -> V_62 -> V_63 ;
struct V_15 * V_16 ;
int V_20 = 0 ;
if ( V_1 && ( V_1 -> V_17 -> V_64 & V_65 ) ) {
F_55 ( V_55 , false ) ;
F_22 ( V_55 ) ;
return - V_66 ;
}
F_56 ( V_61 , V_55 ) ;
F_22 ( V_55 ) ;
if ( ! V_1 )
return 0 ;
V_16 = V_1 -> V_17 ;
if ( V_61 -> V_67 == V_68 )
V_20 = F_57 ( V_16 ) ;
else if ( V_61 -> V_69 )
F_58 ( V_16 , V_1 -> V_13 ) ;
return V_20 ;
}
int F_59 ( struct V_1 * V_1 , T_3 V_70 , T_4 V_71 )
{
struct V_72 * V_73 ;
V_73 = F_60 ( F_61 ( sizeof( * V_73 ) , V_71 ) , V_74 ) ;
if ( ! V_73 )
return - V_21 ;
F_62 ( & V_73 -> V_75 ) ;
V_1 -> V_76 = V_73 ;
V_1 -> V_77 = V_78 ;
F_63 ( V_1 -> V_22 , V_70 ) ;
V_1 -> V_79 = & V_80 ;
V_1 -> V_81 = & V_82 ;
V_1 -> V_22 -> V_83 = & V_84 ;
return 0 ;
}
void F_64 ( struct V_1 * V_1 )
{
struct V_72 * V_85 = F_65 ( V_1 ) ;
if ( V_85 -> V_86 )
F_66 ( V_1 ) ;
}
void F_67 ( struct V_1 * V_1 )
{
struct V_72 * V_85 = F_65 ( V_1 ) ;
F_68 ( V_85 -> V_87 ) ;
F_68 ( V_85 ) ;
}
void F_69 ( struct V_1 * V_1 , unsigned int V_88 ,
unsigned int V_89 )
{
struct V_72 * V_73 = F_65 ( V_1 ) ;
V_73 -> V_90 = V_88 ;
V_73 -> V_91 = ( 1 << V_1 -> V_12 ) / V_88 ;
V_73 -> V_92 = F_70 ( V_89 , V_88 ) ;
}
int F_71 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
struct V_72 * V_73 = F_65 ( V_1 ) ;
F_72 ( & V_94 -> V_95 ) ;
F_73 ( & V_94 -> V_96 ) ;
F_74 ( & V_94 -> V_96 , V_1 ) ;
F_73 ( & V_94 -> V_97 ) ;
F_74 ( & V_94 -> V_97 , V_1 ) ;
V_73 -> V_98 = V_94 ;
return 0 ;
}
int F_75 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_65 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_93 * V_94 = V_73 -> V_98 ;
int V_8 ;
V_8 = F_76 ( & V_94 -> V_96 , V_1 -> V_22 ) ;
if ( V_8 )
goto V_32;
V_8 = F_76 ( & V_94 -> V_97 ,
& V_6 -> V_99 ) ;
if ( V_8 )
goto V_32;
F_77 ( V_6 -> V_10 , & V_94 -> V_100 ) ;
V_32:
return V_8 ;
}
int F_78 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_93 * V_94 = F_65 ( V_1 ) -> V_98 ;
struct V_3 * V_101 ;
struct V_55 * V_55 ;
int V_102 = V_1 -> V_12 ;
V_55 = F_79 ( & V_94 -> V_96 , V_4 -> V_11 -> V_53 ) ;
if ( ! V_55 )
return - V_21 ;
if ( ! F_45 ( V_55 ) )
F_80 ( V_55 , 1 << V_102 , 0 ) ;
V_101 = F_46 ( V_55 , F_8 ( V_4 ) >> V_102 ) ;
if ( ! F_18 ( V_101 ) )
F_81 ( V_101 , V_4 ) ;
if ( F_82 ( & V_101 -> V_103 ) ) {
F_83 ( & V_101 -> V_103 ,
& V_94 -> V_95 ) ;
F_84 ( V_4 ) ;
} else {
F_24 ( V_101 ) ;
}
F_22 ( V_55 ) ;
F_23 ( V_55 ) ;
return 0 ;
}
struct V_3 *
F_85 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_93 * V_94 = F_65 ( V_1 ) -> V_98 ;
struct V_3 * V_101 = NULL ;
struct V_55 * V_55 ;
int V_104 ;
V_55 = F_43 ( & V_94 -> V_96 , V_4 -> V_11 -> V_53 ) ;
if ( V_55 ) {
if ( F_45 ( V_55 ) ) {
V_104 = F_8 ( V_4 ) >> V_1 -> V_12 ;
V_101 = F_46 ( V_55 , V_104 ) ;
}
F_22 ( V_55 ) ;
F_23 ( V_55 ) ;
}
return V_101 ;
}
static void F_86 ( struct V_93 * V_94 )
{
struct V_105 * V_106 = & V_94 -> V_95 ;
struct V_3 * V_4 ;
while ( ! F_82 ( V_106 ) ) {
V_4 = F_87 ( V_106 , struct V_3 ,
V_103 ) ;
F_88 ( & V_4 -> V_103 ) ;
F_24 ( V_4 ) ;
}
}
void F_89 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_65 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_93 * V_94 = V_73 -> V_98 ;
F_90 ( & V_73 -> V_75 ) ;
if ( V_73 -> V_86 )
F_91 ( V_1 ) ;
F_92 ( V_1 -> V_22 , true ) ;
F_93 ( V_1 -> V_22 , & V_94 -> V_96 ) ;
F_92 ( & V_6 -> V_99 , true ) ;
F_93 ( & V_6 -> V_99 , & V_94 -> V_97 ) ;
F_94 ( V_6 -> V_10 , & V_94 -> V_100 ) ;
F_95 ( & V_73 -> V_75 ) ;
}
void F_96 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_65 ( V_1 ) ;
struct V_93 * V_94 = V_73 -> V_98 ;
F_90 ( & V_73 -> V_75 ) ;
F_86 ( V_94 ) ;
F_97 ( & V_94 -> V_96 , 0 ) ;
F_97 ( & V_94 -> V_97 , 0 ) ;
F_95 ( & V_73 -> V_75 ) ;
}
