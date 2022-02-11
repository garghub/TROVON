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
memset ( V_7 + F_8 ( V_4 ) , 0 , F_9 ( V_1 ) ) ;
if ( F_2 )
F_2 ( V_1 , V_4 , V_7 ) ;
F_10 ( V_4 -> V_11 ) ;
F_11 ( V_7 ) ;
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 , V_1 -> V_12 , V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , unsigned long V_2 ,
struct V_3 * * V_13 ,
void (* F_2)( struct V_1 * ,
struct V_3 * ,
void * ) )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
int V_19 ;
F_17 ( V_15 , & V_18 , 0 ) ;
V_19 = - V_20 ;
V_4 = F_18 ( V_1 , V_1 -> V_21 , V_2 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_22;
V_19 = - V_23 ;
if ( F_19 ( V_4 ) )
goto V_24;
F_20 ( V_4 ) ;
if ( F_19 ( V_4 ) )
goto V_24;
V_4 -> V_25 = V_15 -> V_26 ;
V_19 = F_1 ( V_1 , V_2 , V_4 , F_2 ) ;
if ( F_21 ( ! V_19 ) ) {
F_22 ( V_4 ) ;
* V_13 = V_4 ;
}
V_24:
F_23 ( V_4 -> V_11 ) ;
F_24 ( V_4 -> V_11 ) ;
F_25 ( V_4 ) ;
V_22:
if ( F_21 ( ! V_19 ) )
V_19 = F_26 ( V_15 ) ;
else
F_27 ( V_15 ) ;
return V_19 ;
}
static int
F_28 ( struct V_1 * V_1 , unsigned long V_27 ,
int V_28 , int V_29 , struct V_3 * * V_13 )
{
struct V_3 * V_4 ;
T_1 V_30 = 0 ;
int V_8 = - V_20 ;
V_4 = F_18 ( V_1 , V_1 -> V_21 , V_27 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_31;
V_8 = - V_23 ;
if ( F_19 ( V_4 ) )
goto V_32;
if ( V_29 & V_33 ) {
if ( ! F_29 ( V_4 ) ) {
V_8 = - V_34 ;
goto V_24;
}
} else
F_30 ( V_4 ) ;
if ( F_19 ( V_4 ) ) {
F_31 ( V_4 ) ;
goto V_32;
}
V_8 = F_32 ( F_3 ( V_1 ) -> V_10 , V_27 , & V_30 ) ;
if ( F_5 ( V_8 ) ) {
F_31 ( V_4 ) ;
goto V_24;
}
F_33 ( V_4 , V_1 -> V_16 , ( V_35 ) V_30 ) ;
V_4 -> V_36 = V_37 ;
F_22 ( V_4 ) ;
F_34 ( V_28 , V_29 , V_4 ) ;
V_8 = 0 ;
F_35 ( V_1 , V_1 -> V_12 , V_27 , V_28 ) ;
V_32:
F_22 ( V_4 ) ;
* V_13 = V_4 ;
V_24:
F_23 ( V_4 -> V_11 ) ;
F_24 ( V_4 -> V_11 ) ;
F_25 ( V_4 ) ;
V_31:
return V_8 ;
}
static int F_36 ( struct V_1 * V_1 , unsigned long V_2 ,
int V_38 , struct V_3 * * V_13 )
{
struct V_3 * V_39 , * V_4 ;
unsigned long V_27 ;
int V_40 , V_41 = V_42 ;
int V_19 ;
V_19 = F_28 ( V_1 , V_2 , V_43 , 0 , & V_39 ) ;
if ( V_19 == - V_23 )
goto V_32;
if ( F_5 ( V_19 ) )
goto V_31;
if ( V_38 ) {
V_27 = V_2 + 1 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ , V_27 ++ ) {
V_19 = F_28 ( V_1 , V_27 , V_43 ,
V_33 , & V_4 ) ;
if ( F_21 ( ! V_19 || V_19 == - V_23 ) )
F_25 ( V_4 ) ;
else if ( V_19 != - V_34 )
break;
if ( ! F_37 ( V_39 ) )
goto V_44;
}
}
F_20 ( V_39 ) ;
V_44:
V_19 = - V_45 ;
if ( ! F_19 ( V_39 ) ) {
F_38 ( V_1 -> V_16 , V_46 ,
L_1 ,
V_1 -> V_12 , V_2 ) ;
goto V_24;
}
V_32:
* V_13 = V_39 ;
return 0 ;
V_24:
F_25 ( V_39 ) ;
V_31:
return V_19 ;
}
int F_39 ( struct V_1 * V_1 , unsigned long V_27 , int V_47 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) ,
struct V_3 * * V_13 )
{
int V_8 ;
V_48:
V_8 = F_36 ( V_1 , V_27 , ! V_47 , V_13 ) ;
if ( ! V_47 || V_8 != - V_49 )
return V_8 ;
V_8 = F_16 ( V_1 , V_27 , V_13 , F_2 ) ;
if ( F_5 ( V_8 == - V_23 ) ) {
goto V_48;
}
return V_8 ;
}
int F_40 ( struct V_1 * V_1 , unsigned long V_50 ,
unsigned long V_51 , unsigned long * V_27 ,
struct V_3 * * V_13 )
{
T_1 V_52 ;
int V_8 ;
if ( F_5 ( V_50 > V_51 ) )
return - V_49 ;
V_8 = F_36 ( V_1 , V_50 , true , V_13 ) ;
if ( ! V_8 ) {
* V_27 = V_50 ;
goto V_32;
}
if ( F_5 ( V_8 != - V_49 || V_50 == V_53 ) )
goto V_32;
V_8 = F_41 ( F_3 ( V_1 ) -> V_10 , V_50 + 1 , & V_52 ) ;
if ( ! V_8 ) {
if ( V_52 <= V_51 ) {
V_8 = F_36 ( V_1 , V_52 , true , V_13 ) ;
if ( ! V_8 )
* V_27 = V_52 ;
} else {
V_8 = - V_49 ;
}
}
V_32:
return V_8 ;
}
int F_42 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
int V_19 ;
V_19 = F_43 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_19 || V_19 == - V_49 ) {
F_14 ( V_1 ) ;
F_44 ( V_1 , V_2 ) ;
}
return V_19 ;
}
int F_44 ( struct V_1 * V_1 , unsigned long V_2 )
{
T_2 V_54 = ( T_2 ) V_2 >>
( V_55 - V_1 -> V_56 ) ;
struct V_57 * V_57 ;
unsigned long V_58 ;
int V_8 = 0 ;
int V_59 ;
V_57 = F_45 ( V_1 -> V_21 , V_54 ) ;
if ( ! V_57 )
return - V_49 ;
F_46 ( V_57 ) ;
V_58 = ( unsigned long ) V_54 <<
( V_55 - V_1 -> V_56 ) ;
if ( F_47 ( V_57 ) ) {
struct V_3 * V_4 ;
V_4 = F_48 ( V_57 , V_2 - V_58 ) ;
F_49 ( V_4 ) ;
}
V_59 = F_50 ( V_57 ) ;
F_23 ( V_57 ) ;
F_24 ( V_57 ) ;
if ( V_59 ||
F_51 ( V_1 -> V_21 , V_54 , V_54 ) != 0 )
V_8 = - V_34 ;
return V_8 ;
}
int F_52 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
if ( F_53 ( V_6 -> V_10 ) ) {
F_54 ( V_60 , & V_6 -> V_61 ) ;
return 1 ;
}
return F_55 ( V_60 , & V_6 -> V_61 ) ;
}
static int
F_56 ( struct V_57 * V_57 , struct V_62 * V_63 )
{
struct V_1 * V_1 = V_57 -> V_64 -> V_65 ;
struct V_14 * V_15 ;
int V_19 = 0 ;
if ( V_1 && ( V_1 -> V_16 -> V_66 & V_67 ) ) {
F_57 ( V_57 , false ) ;
F_23 ( V_57 ) ;
return - V_68 ;
}
F_58 ( V_63 , V_57 ) ;
F_23 ( V_57 ) ;
if ( ! V_1 )
return 0 ;
V_15 = V_1 -> V_16 ;
if ( V_63 -> V_69 == V_70 )
V_19 = F_59 ( V_15 ) ;
else if ( V_63 -> V_71 )
F_60 ( V_15 , V_1 -> V_12 ) ;
return V_19 ;
}
int F_61 ( struct V_1 * V_1 , T_3 V_72 , T_4 V_73 )
{
struct V_74 * V_75 ;
V_75 = F_62 ( F_63 ( sizeof( * V_75 ) , V_73 ) , V_76 ) ;
if ( ! V_75 )
return - V_20 ;
F_64 ( & V_75 -> V_77 ) ;
V_1 -> V_78 = V_75 ;
V_1 -> V_79 = V_80 ;
F_65 ( V_1 -> V_21 , V_72 ) ;
V_1 -> V_81 = & V_82 ;
V_1 -> V_83 = & V_84 ;
V_1 -> V_21 -> V_85 = & V_86 ;
return 0 ;
}
void F_66 ( struct V_1 * V_1 )
{
struct V_74 * V_87 = F_67 ( V_1 ) ;
if ( V_87 -> V_88 )
F_68 ( V_1 ) ;
}
void F_69 ( struct V_1 * V_1 )
{
struct V_74 * V_87 = F_67 ( V_1 ) ;
F_70 ( V_87 -> V_89 ) ;
F_70 ( V_87 ) ;
}
void F_71 ( struct V_1 * V_1 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_74 * V_75 = F_67 ( V_1 ) ;
V_75 -> V_92 = V_90 ;
V_75 -> V_93 = F_9 ( V_1 ) / V_90 ;
V_75 -> V_94 = F_72 ( V_91 , V_90 ) ;
}
int F_73 ( struct V_1 * V_1 ,
struct V_95 * V_96 )
{
struct V_74 * V_75 = F_67 ( V_1 ) ;
F_74 ( & V_96 -> V_97 ) ;
F_75 ( & V_96 -> V_98 ) ;
F_76 ( & V_96 -> V_98 , V_1 ) ;
F_75 ( & V_96 -> V_99 ) ;
F_76 ( & V_96 -> V_99 , V_1 ) ;
V_75 -> V_100 = V_96 ;
return 0 ;
}
int F_77 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_67 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
int V_8 ;
V_8 = F_78 ( & V_96 -> V_98 , V_1 -> V_21 ) ;
if ( V_8 )
goto V_32;
V_8 = F_78 ( & V_96 -> V_99 ,
& V_6 -> V_101 ) ;
if ( V_8 )
goto V_32;
F_79 ( V_6 -> V_10 , & V_96 -> V_102 ) ;
V_32:
return V_8 ;
}
int F_80 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_95 * V_96 = F_67 ( V_1 ) -> V_100 ;
struct V_3 * V_103 ;
struct V_57 * V_57 ;
int V_104 = V_1 -> V_56 ;
V_57 = F_81 ( & V_96 -> V_98 , V_4 -> V_11 -> V_54 ) ;
if ( ! V_57 )
return - V_20 ;
if ( ! F_47 ( V_57 ) )
F_82 ( V_57 , 1 << V_104 , 0 ) ;
V_103 = F_48 ( V_57 , F_8 ( V_4 ) >> V_104 ) ;
if ( ! F_19 ( V_103 ) )
F_83 ( V_103 , V_4 ) ;
if ( F_84 ( & V_103 -> V_105 ) ) {
F_85 ( & V_103 -> V_105 ,
& V_96 -> V_97 ) ;
F_86 ( V_4 ) ;
} else {
F_25 ( V_103 ) ;
}
F_23 ( V_57 ) ;
F_24 ( V_57 ) ;
return 0 ;
}
struct V_3 *
F_87 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_95 * V_96 = F_67 ( V_1 ) -> V_100 ;
struct V_3 * V_103 = NULL ;
struct V_57 * V_57 ;
int V_106 ;
V_57 = F_45 ( & V_96 -> V_98 , V_4 -> V_11 -> V_54 ) ;
if ( V_57 ) {
if ( F_47 ( V_57 ) ) {
V_106 = F_8 ( V_4 ) >> V_1 -> V_56 ;
V_103 = F_48 ( V_57 , V_106 ) ;
}
F_23 ( V_57 ) ;
F_24 ( V_57 ) ;
}
return V_103 ;
}
static void F_88 ( struct V_95 * V_96 )
{
struct V_107 * V_108 = & V_96 -> V_97 ;
struct V_3 * V_4 ;
while ( ! F_84 ( V_108 ) ) {
V_4 = F_89 ( V_108 , struct V_3 ,
V_105 ) ;
F_90 ( & V_4 -> V_105 ) ;
F_25 ( V_4 ) ;
}
}
void F_91 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_67 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
F_92 ( & V_75 -> V_77 ) ;
if ( V_75 -> V_88 )
F_93 ( V_1 ) ;
F_94 ( V_1 -> V_21 , true ) ;
F_95 ( V_1 -> V_21 , & V_96 -> V_98 ) ;
F_94 ( & V_6 -> V_101 , true ) ;
F_95 ( & V_6 -> V_101 , & V_96 -> V_99 ) ;
F_96 ( V_6 -> V_10 , & V_96 -> V_102 ) ;
F_97 ( & V_75 -> V_77 ) ;
}
void F_98 ( struct V_1 * V_1 )
{
struct V_74 * V_75 = F_67 ( V_1 ) ;
struct V_95 * V_96 = V_75 -> V_100 ;
F_92 ( & V_75 -> V_77 ) ;
F_88 ( V_96 ) ;
F_99 ( & V_96 -> V_98 , 0 ) ;
F_99 ( & V_96 -> V_99 , 0 ) ;
F_97 ( & V_75 -> V_77 ) ;
}
