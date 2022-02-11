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
int V_29 , int V_30 , struct V_3 * * V_14 )
{
struct V_3 * V_4 ;
T_1 V_31 = 0 ;
int V_8 = - V_21 ;
V_4 = F_17 ( V_1 , V_1 -> V_22 , V_28 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_32;
V_8 = - V_24 ;
if ( F_18 ( V_4 ) )
goto V_33;
if ( V_30 & V_34 ) {
if ( ! F_28 ( V_4 ) ) {
V_8 = - V_35 ;
goto V_25;
}
} else
F_29 ( V_4 ) ;
if ( F_18 ( V_4 ) ) {
F_30 ( V_4 ) ;
goto V_33;
}
V_8 = F_31 ( F_3 ( V_1 ) -> V_10 , V_28 , & V_31 ) ;
if ( F_5 ( V_8 ) ) {
F_30 ( V_4 ) ;
goto V_25;
}
F_32 ( V_4 , V_1 -> V_17 , ( V_36 ) V_31 ) ;
V_4 -> V_37 = V_38 ;
F_21 ( V_4 ) ;
F_33 ( V_29 , V_30 , V_4 ) ;
V_8 = 0 ;
F_34 ( V_1 , V_1 -> V_13 , V_28 , V_29 ) ;
V_33:
F_21 ( V_4 ) ;
* V_14 = V_4 ;
V_25:
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 -> V_11 ) ;
F_24 ( V_4 ) ;
V_32:
return V_8 ;
}
static int F_35 ( struct V_1 * V_1 , unsigned long V_2 ,
int V_39 , struct V_3 * * V_14 )
{
struct V_3 * V_40 , * V_4 ;
unsigned long V_28 ;
int V_41 , V_42 = V_43 ;
int V_20 ;
V_20 = F_27 ( V_1 , V_2 , V_44 , 0 , & V_40 ) ;
if ( V_20 == - V_24 )
goto V_33;
if ( F_5 ( V_20 ) )
goto V_32;
if ( V_39 ) {
V_28 = V_2 + 1 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ , V_28 ++ ) {
V_20 = F_27 ( V_1 , V_28 , V_44 ,
V_34 , & V_4 ) ;
if ( F_20 ( ! V_20 || V_20 == - V_24 ) )
F_24 ( V_4 ) ;
else if ( V_20 != - V_35 )
break;
if ( ! F_36 ( V_40 ) )
goto V_45;
}
}
F_19 ( V_40 ) ;
V_45:
V_20 = - V_46 ;
if ( ! F_18 ( V_40 ) ) {
F_37 ( V_1 -> V_17 , V_47 ,
L_1 ,
V_1 -> V_13 , V_2 ) ;
goto V_25;
}
V_33:
* V_14 = V_40 ;
return 0 ;
V_25:
F_24 ( V_40 ) ;
V_32:
return V_20 ;
}
int F_38 ( struct V_1 * V_1 , unsigned long V_28 , int V_48 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) ,
struct V_3 * * V_14 )
{
int V_8 ;
V_49:
V_8 = F_35 ( V_1 , V_28 , ! V_48 , V_14 ) ;
if ( ! V_48 || V_8 != - V_50 )
return V_8 ;
V_8 = F_15 ( V_1 , V_28 , V_14 , F_2 ) ;
if ( F_5 ( V_8 == - V_24 ) ) {
goto V_49;
}
return V_8 ;
}
int F_39 ( struct V_1 * V_1 , unsigned long V_51 ,
unsigned long V_52 , unsigned long * V_28 ,
struct V_3 * * V_14 )
{
T_1 V_53 ;
int V_8 ;
if ( F_5 ( V_51 > V_52 ) )
return - V_50 ;
V_8 = F_35 ( V_1 , V_51 , true , V_14 ) ;
if ( ! V_8 ) {
* V_28 = V_51 ;
goto V_33;
}
if ( F_5 ( V_8 != - V_50 || V_51 == V_54 ) )
goto V_33;
V_8 = F_40 ( F_3 ( V_1 ) -> V_10 , V_51 + 1 , & V_53 ) ;
if ( ! V_8 ) {
if ( V_53 <= V_52 ) {
V_8 = F_35 ( V_1 , V_53 , true , V_14 ) ;
if ( ! V_8 )
* V_28 = V_53 ;
} else {
V_8 = - V_50 ;
}
}
V_33:
return V_8 ;
}
int F_41 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
int V_20 ;
V_20 = F_42 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_20 || V_20 == - V_50 ) {
F_13 ( V_1 ) ;
F_43 ( V_1 , V_2 ) ;
}
return V_20 ;
}
int F_43 ( struct V_1 * V_1 , unsigned long V_2 )
{
T_2 V_55 = ( T_2 ) V_2 >>
( V_56 - V_1 -> V_12 ) ;
struct V_57 * V_57 ;
unsigned long V_58 ;
int V_8 = 0 ;
int V_59 ;
V_57 = F_44 ( V_1 -> V_22 , V_55 ) ;
if ( ! V_57 )
return - V_50 ;
F_45 ( V_57 ) ;
V_58 = ( unsigned long ) V_55 <<
( V_56 - V_1 -> V_12 ) ;
if ( F_46 ( V_57 ) ) {
struct V_3 * V_4 ;
V_4 = F_47 ( V_57 , V_2 - V_58 ) ;
F_48 ( V_4 ) ;
}
V_59 = F_49 ( V_57 ) ;
F_22 ( V_57 ) ;
F_23 ( V_57 ) ;
if ( V_59 ||
F_50 ( V_1 -> V_22 , V_55 , V_55 ) != 0 )
V_8 = - V_35 ;
return V_8 ;
}
int F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
if ( F_52 ( V_6 -> V_10 ) ) {
F_53 ( V_60 , & V_6 -> V_61 ) ;
return 1 ;
}
return F_54 ( V_60 , & V_6 -> V_61 ) ;
}
static int
F_55 ( struct V_57 * V_57 , struct V_62 * V_63 )
{
struct V_1 * V_1 = V_57 -> V_64 -> V_65 ;
struct V_15 * V_16 ;
int V_20 = 0 ;
if ( V_1 && ( V_1 -> V_17 -> V_66 & V_67 ) ) {
F_56 ( V_57 , false ) ;
F_22 ( V_57 ) ;
return - V_68 ;
}
F_57 ( V_63 , V_57 ) ;
F_22 ( V_57 ) ;
if ( ! V_1 )
return 0 ;
V_16 = V_1 -> V_17 ;
if ( V_63 -> V_69 == V_70 )
V_20 = F_58 ( V_16 ) ;
else if ( V_63 -> V_71 )
F_59 ( V_16 , V_1 -> V_13 ) ;
return V_20 ;
}
int F_60 ( struct V_1 * V_1 , T_3 V_72 , T_4 V_73 )
{
struct V_74 * V_75 ;
V_75 = F_61 ( F_62 ( sizeof( * V_75 ) , V_73 ) , V_76 ) ;
if ( ! V_75 )
return - V_21 ;
F_63 ( & V_75 -> V_77 ) ;
V_1 -> V_78 = V_75 ;
V_1 -> V_79 = V_80 ;
F_64 ( V_1 -> V_22 , V_72 ) ;
V_1 -> V_81 = & V_82 ;
V_1 -> V_83 = & V_84 ;
V_1 -> V_22 -> V_85 = & V_86 ;
return 0 ;
}
void F_65 ( struct V_1 * V_1 )
{
struct V_74 * V_87 = F_66 ( V_1 ) ;
if ( V_87 -> V_88 )
F_67 ( V_1 ) ;
}
void F_68 ( struct V_1 * V_1 )
{
struct V_74 * V_87 = F_66 ( V_1 ) ;
F_69 ( V_87 -> V_89 ) ;
F_69 ( V_87 ) ;
}
void F_70 ( struct V_1 * V_1 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_74 * V_75 = F_66 ( V_1 ) ;
V_75 -> V_92 = V_90 ;
V_75 -> V_93 = ( 1 << V_1 -> V_12 ) / V_90 ;
V_75 -> V_94 = F_71 ( V_91 , V_90 ) ;
}
int F_72 ( struct V_1 * V_1 ,
struct V_95 * V_96 )
{
struct V_74 * V_75 = F_66 ( V_1 ) ;
F_73 ( & V_96 -> V_97 ) ;
F_74 ( & V_96 -> V_98 ) ;
F_75 ( & V_96 -> V_98 , V_1 ) ;
F_74 ( & V_96 -> V_99 ) ;
F_75 ( & V_96 -> V_99 , V_1 ) ;
V_75 -> V_100 = V_96 ;
return 0 ;
}
int F_76 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_66 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
int V_8 ;
V_8 = F_77 ( & V_96 -> V_98 , V_1 -> V_22 ) ;
if ( V_8 )
goto V_33;
V_8 = F_77 ( & V_96 -> V_99 ,
& V_6 -> V_101 ) ;
if ( V_8 )
goto V_33;
F_78 ( V_6 -> V_10 , & V_96 -> V_102 ) ;
V_33:
return V_8 ;
}
int F_79 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_95 * V_96 = F_66 ( V_1 ) -> V_100 ;
struct V_3 * V_103 ;
struct V_57 * V_57 ;
int V_104 = V_1 -> V_12 ;
V_57 = F_80 ( & V_96 -> V_98 , V_4 -> V_11 -> V_55 ) ;
if ( ! V_57 )
return - V_21 ;
if ( ! F_46 ( V_57 ) )
F_81 ( V_57 , 1 << V_104 , 0 ) ;
V_103 = F_47 ( V_57 , F_8 ( V_4 ) >> V_104 ) ;
if ( ! F_18 ( V_103 ) )
F_82 ( V_103 , V_4 ) ;
if ( F_83 ( & V_103 -> V_105 ) ) {
F_84 ( & V_103 -> V_105 ,
& V_96 -> V_97 ) ;
F_85 ( V_4 ) ;
} else {
F_24 ( V_103 ) ;
}
F_22 ( V_57 ) ;
F_23 ( V_57 ) ;
return 0 ;
}
struct V_3 *
F_86 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_95 * V_96 = F_66 ( V_1 ) -> V_100 ;
struct V_3 * V_103 = NULL ;
struct V_57 * V_57 ;
int V_106 ;
V_57 = F_44 ( & V_96 -> V_98 , V_4 -> V_11 -> V_55 ) ;
if ( V_57 ) {
if ( F_46 ( V_57 ) ) {
V_106 = F_8 ( V_4 ) >> V_1 -> V_12 ;
V_103 = F_47 ( V_57 , V_106 ) ;
}
F_22 ( V_57 ) ;
F_23 ( V_57 ) ;
}
return V_103 ;
}
static void F_87 ( struct V_95 * V_96 )
{
struct V_107 * V_108 = & V_96 -> V_97 ;
struct V_3 * V_4 ;
while ( ! F_83 ( V_108 ) ) {
V_4 = F_88 ( V_108 , struct V_3 ,
V_105 ) ;
F_89 ( & V_4 -> V_105 ) ;
F_24 ( V_4 ) ;
}
}
void F_90 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_66 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
F_91 ( & V_75 -> V_77 ) ;
if ( V_75 -> V_88 )
F_92 ( V_1 ) ;
F_93 ( V_1 -> V_22 , true ) ;
F_94 ( V_1 -> V_22 , & V_96 -> V_98 ) ;
F_93 ( & V_6 -> V_101 , true ) ;
F_94 ( & V_6 -> V_101 , & V_96 -> V_99 ) ;
F_95 ( V_6 -> V_10 , & V_96 -> V_102 ) ;
F_96 ( & V_75 -> V_77 ) ;
}
void F_97 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_66 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
F_91 ( & V_75 -> V_77 ) ;
F_87 ( V_96 ) ;
F_98 ( & V_96 -> V_98 , 0 ) ;
F_98 ( & V_96 -> V_99 , 0 ) ;
F_96 ( & V_75 -> V_77 ) ;
}
