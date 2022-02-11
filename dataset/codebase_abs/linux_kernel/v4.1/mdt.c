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
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_2 ,
struct V_3 * * V_13 ,
void (* F_2)( struct V_1 * ,
struct V_3 * ,
void * ) )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
int V_19 ;
F_15 ( V_15 , & V_18 , 0 ) ;
V_19 = - V_20 ;
V_4 = F_16 ( V_1 , V_1 -> V_21 , V_2 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_22;
V_19 = - V_23 ;
if ( F_17 ( V_4 ) )
goto V_24;
F_18 ( V_4 ) ;
if ( F_17 ( V_4 ) )
goto V_24;
V_4 -> V_25 = V_15 -> V_26 ;
V_19 = F_1 ( V_1 , V_2 , V_4 , F_2 ) ;
if ( F_19 ( ! V_19 ) ) {
F_20 ( V_4 ) ;
* V_13 = V_4 ;
}
V_24:
F_21 ( V_4 -> V_11 ) ;
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 ) ;
V_22:
if ( F_19 ( ! V_19 ) )
V_19 = F_24 ( V_15 ) ;
else
F_25 ( V_15 ) ;
return V_19 ;
}
static int
F_26 ( struct V_1 * V_1 , unsigned long V_27 ,
int V_28 , struct V_3 * * V_13 )
{
struct V_3 * V_4 ;
T_1 V_29 = 0 ;
int V_8 = - V_20 ;
V_4 = F_16 ( V_1 , V_1 -> V_21 , V_27 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_30;
V_8 = - V_23 ;
if ( F_17 ( V_4 ) )
goto V_31;
if ( V_28 == V_32 ) {
if ( ! F_27 ( V_4 ) ) {
V_8 = - V_33 ;
goto V_24;
}
} else
F_28 ( V_4 ) ;
if ( F_17 ( V_4 ) ) {
F_29 ( V_4 ) ;
goto V_31;
}
V_8 = F_30 ( F_3 ( V_1 ) -> V_10 , V_27 , & V_29 ) ;
if ( F_5 ( V_8 ) ) {
F_29 ( V_4 ) ;
goto V_24;
}
F_31 ( V_4 , V_1 -> V_16 , ( V_34 ) V_29 ) ;
V_4 -> V_35 = V_36 ;
F_20 ( V_4 ) ;
F_32 ( V_28 , V_4 ) ;
V_8 = 0 ;
V_31:
F_20 ( V_4 ) ;
* V_13 = V_4 ;
V_24:
F_21 ( V_4 -> V_11 ) ;
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 ) ;
V_30:
return V_8 ;
}
static int F_33 ( struct V_1 * V_1 , unsigned long V_2 ,
int V_37 , struct V_3 * * V_13 )
{
struct V_3 * V_38 , * V_4 ;
unsigned long V_27 ;
int V_39 , V_40 = V_41 ;
int V_19 ;
V_19 = F_26 ( V_1 , V_2 , V_42 , & V_38 ) ;
if ( V_19 == - V_23 )
goto V_31;
if ( F_5 ( V_19 ) )
goto V_30;
if ( V_37 ) {
V_27 = V_2 + 1 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ , V_27 ++ ) {
V_19 = F_26 ( V_1 , V_27 , V_32 , & V_4 ) ;
if ( F_19 ( ! V_19 || V_19 == - V_23 ) )
F_23 ( V_4 ) ;
else if ( V_19 != - V_33 )
break;
if ( ! F_34 ( V_38 ) )
goto V_43;
}
}
F_18 ( V_38 ) ;
V_43:
V_19 = - V_44 ;
if ( ! F_17 ( V_38 ) )
goto V_24;
V_31:
* V_13 = V_38 ;
return 0 ;
V_24:
F_23 ( V_38 ) ;
V_30:
return V_19 ;
}
int F_35 ( struct V_1 * V_1 , unsigned long V_27 , int V_45 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) ,
struct V_3 * * V_13 )
{
int V_8 ;
V_46:
V_8 = F_33 ( V_1 , V_27 , ! V_45 , V_13 ) ;
if ( ! V_45 || V_8 != - V_47 )
return V_8 ;
V_8 = F_14 ( V_1 , V_27 , V_13 , F_2 ) ;
if ( F_5 ( V_8 == - V_23 ) ) {
goto V_46;
}
return V_8 ;
}
int F_36 ( struct V_1 * V_1 , unsigned long V_48 ,
unsigned long V_49 , unsigned long * V_27 ,
struct V_3 * * V_13 )
{
T_1 V_50 ;
int V_8 ;
if ( F_5 ( V_48 > V_49 ) )
return - V_47 ;
V_8 = F_33 ( V_1 , V_48 , true , V_13 ) ;
if ( ! V_8 ) {
* V_27 = V_48 ;
goto V_31;
}
if ( F_5 ( V_8 != - V_47 || V_48 == V_51 ) )
goto V_31;
V_8 = F_37 ( F_3 ( V_1 ) -> V_10 , V_48 + 1 , & V_50 ) ;
if ( ! V_8 ) {
if ( V_50 <= V_49 ) {
V_8 = F_33 ( V_1 , V_50 , true , V_13 ) ;
if ( ! V_8 )
* V_27 = V_50 ;
} else {
V_8 = - V_47 ;
}
}
V_31:
return V_8 ;
}
int F_38 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
int V_19 ;
V_19 = F_39 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_19 || V_19 == - V_47 ) {
F_13 ( V_1 ) ;
F_40 ( V_1 , V_2 ) ;
}
return V_19 ;
}
int F_40 ( struct V_1 * V_1 , unsigned long V_2 )
{
T_2 V_52 = ( T_2 ) V_2 >>
( V_53 - V_1 -> V_12 ) ;
struct V_54 * V_54 ;
unsigned long V_55 ;
int V_8 = 0 ;
int V_56 ;
V_54 = F_41 ( V_1 -> V_21 , V_52 ) ;
if ( ! V_54 )
return - V_47 ;
F_42 ( V_54 ) ;
V_55 = ( unsigned long ) V_52 <<
( V_53 - V_1 -> V_12 ) ;
if ( F_43 ( V_54 ) ) {
struct V_3 * V_4 ;
V_4 = F_44 ( V_54 , V_2 - V_55 ) ;
F_45 ( V_4 ) ;
}
V_56 = F_46 ( V_54 ) ;
F_21 ( V_54 ) ;
F_22 ( V_54 ) ;
if ( V_56 ||
F_47 ( V_1 -> V_21 , V_52 , V_52 ) != 0 )
V_8 = - V_33 ;
return V_8 ;
}
int F_48 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_33 ( V_1 , V_2 , 0 , & V_4 ) ;
if ( F_5 ( V_19 ) )
return V_19 ;
F_12 ( V_4 ) ;
F_13 ( V_1 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
if ( F_50 ( V_6 -> V_10 ) ) {
F_51 ( V_57 , & V_6 -> V_58 ) ;
return 1 ;
}
return F_52 ( V_57 , & V_6 -> V_58 ) ;
}
static int
F_53 ( struct V_54 * V_54 , struct V_59 * V_60 )
{
struct V_1 * V_1 = V_54 -> V_61 -> V_62 ;
struct V_14 * V_15 ;
int V_19 = 0 ;
if ( V_1 && ( V_1 -> V_16 -> V_63 & V_64 ) ) {
F_54 ( V_54 , false ) ;
F_21 ( V_54 ) ;
return - V_65 ;
}
F_55 ( V_60 , V_54 ) ;
F_21 ( V_54 ) ;
if ( ! V_1 )
return 0 ;
V_15 = V_1 -> V_16 ;
if ( V_60 -> V_66 == V_67 )
V_19 = F_56 ( V_15 ) ;
else if ( V_60 -> V_68 )
F_57 ( V_15 , V_1 -> V_69 ) ;
return V_19 ;
}
int F_58 ( struct V_1 * V_1 , T_3 V_70 , T_4 V_71 )
{
struct V_72 * V_73 ;
V_73 = F_59 ( F_60 ( sizeof( * V_73 ) , V_71 ) , V_74 ) ;
if ( ! V_73 )
return - V_20 ;
F_61 ( & V_73 -> V_75 ) ;
V_1 -> V_76 = V_73 ;
V_1 -> V_77 = V_78 ;
F_62 ( V_1 -> V_21 , V_70 ) ;
V_1 -> V_79 = & V_80 ;
V_1 -> V_81 = & V_82 ;
V_1 -> V_21 -> V_83 = & V_84 ;
return 0 ;
}
void F_63 ( struct V_1 * V_1 , unsigned V_85 ,
unsigned V_86 )
{
struct V_72 * V_73 = F_64 ( V_1 ) ;
V_73 -> V_87 = V_85 ;
V_73 -> V_88 = ( 1 << V_1 -> V_12 ) / V_85 ;
V_73 -> V_89 = F_65 ( V_86 , V_85 ) ;
}
int F_66 ( struct V_1 * V_1 ,
struct V_90 * V_91 )
{
struct V_72 * V_73 = F_64 ( V_1 ) ;
F_67 ( & V_91 -> V_92 ) ;
F_68 ( & V_91 -> V_93 ) ;
F_69 ( & V_91 -> V_93 , V_1 ) ;
F_68 ( & V_91 -> V_94 ) ;
F_69 ( & V_91 -> V_94 , V_1 ) ;
V_73 -> V_95 = V_91 ;
return 0 ;
}
int F_70 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_64 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_90 * V_91 = V_73 -> V_95 ;
int V_8 ;
V_8 = F_71 ( & V_91 -> V_93 , V_1 -> V_21 ) ;
if ( V_8 )
goto V_31;
V_8 = F_71 ( & V_91 -> V_94 ,
& V_6 -> V_96 ) ;
if ( V_8 )
goto V_31;
F_72 ( V_6 -> V_10 , & V_91 -> V_97 ) ;
V_31:
return V_8 ;
}
int F_73 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_90 * V_91 = F_64 ( V_1 ) -> V_95 ;
struct V_3 * V_98 ;
struct V_54 * V_54 ;
int V_99 = V_1 -> V_12 ;
V_54 = F_74 ( & V_91 -> V_93 , V_4 -> V_11 -> V_52 ) ;
if ( ! V_54 )
return - V_20 ;
if ( ! F_43 ( V_54 ) )
F_75 ( V_54 , 1 << V_99 , 0 ) ;
V_98 = F_44 ( V_54 , F_8 ( V_4 ) >> V_99 ) ;
if ( ! F_17 ( V_98 ) )
F_76 ( V_98 , V_4 ) ;
if ( F_77 ( & V_98 -> V_100 ) ) {
F_78 ( & V_98 -> V_100 ,
& V_91 -> V_92 ) ;
F_79 ( V_4 ) ;
} else {
F_23 ( V_98 ) ;
}
F_21 ( V_54 ) ;
F_22 ( V_54 ) ;
return 0 ;
}
struct V_3 *
F_80 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_90 * V_91 = F_64 ( V_1 ) -> V_95 ;
struct V_3 * V_98 = NULL ;
struct V_54 * V_54 ;
int V_101 ;
V_54 = F_41 ( & V_91 -> V_93 , V_4 -> V_11 -> V_52 ) ;
if ( V_54 ) {
if ( F_43 ( V_54 ) ) {
V_101 = F_8 ( V_4 ) >> V_1 -> V_12 ;
V_98 = F_44 ( V_54 , V_101 ) ;
}
F_21 ( V_54 ) ;
F_22 ( V_54 ) ;
}
return V_98 ;
}
static void F_81 ( struct V_90 * V_91 )
{
struct V_102 * V_103 = & V_91 -> V_92 ;
struct V_3 * V_4 ;
while ( ! F_77 ( V_103 ) ) {
V_4 = F_82 ( V_103 , struct V_3 ,
V_100 ) ;
F_83 ( & V_4 -> V_100 ) ;
F_23 ( V_4 ) ;
}
}
void F_84 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_64 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_90 * V_91 = V_73 -> V_95 ;
F_85 ( & V_73 -> V_75 ) ;
if ( V_73 -> V_104 )
F_86 ( V_1 ) ;
F_87 ( V_1 -> V_21 , true ) ;
F_88 ( V_1 -> V_21 , & V_91 -> V_93 ) ;
F_87 ( & V_6 -> V_96 , true ) ;
F_88 ( & V_6 -> V_96 , & V_91 -> V_94 ) ;
F_89 ( V_6 -> V_10 , & V_91 -> V_97 ) ;
F_90 ( & V_73 -> V_75 ) ;
}
void F_91 ( struct V_1 * V_1 )
{
struct V_72 * V_73 = F_64 ( V_1 ) ;
struct V_90 * V_91 = V_73 -> V_95 ;
F_85 ( & V_73 -> V_75 ) ;
F_81 ( V_91 ) ;
F_92 ( & V_91 -> V_93 , 0 ) ;
F_92 ( & V_91 -> V_94 , 0 ) ;
F_90 ( & V_73 -> V_75 ) ;
}
