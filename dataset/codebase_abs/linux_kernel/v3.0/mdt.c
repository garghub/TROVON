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
V_7 = F_7 ( V_4 -> V_11 , V_12 ) ;
memset ( V_7 + F_8 ( V_4 ) , 0 , 1 << V_1 -> V_13 ) ;
if ( F_2 )
F_2 ( V_1 , V_4 , V_7 ) ;
F_9 ( V_4 -> V_11 ) ;
F_10 ( V_7 , V_12 ) ;
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_2 ,
struct V_3 * * V_14 ,
void (* F_2)( struct V_1 * ,
struct V_3 * ,
void * ) )
{
struct V_15 * V_16 = V_1 -> V_17 ;
struct V_18 V_19 ;
struct V_3 * V_4 ;
int V_20 ;
F_15 ( V_16 , & V_19 , 0 ) ;
V_20 = - V_21 ;
V_4 = F_16 ( V_1 , V_1 -> V_22 , V_2 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_23;
V_20 = - V_24 ;
if ( F_17 ( V_4 ) )
goto V_25;
F_18 ( V_4 ) ;
if ( F_17 ( V_4 ) )
goto V_25;
V_4 -> V_26 = V_16 -> V_27 ;
V_20 = F_1 ( V_1 , V_2 , V_4 , F_2 ) ;
if ( F_19 ( ! V_20 ) ) {
F_20 ( V_4 ) ;
* V_14 = V_4 ;
}
V_25:
F_21 ( V_4 -> V_11 ) ;
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 ) ;
V_23:
if ( F_19 ( ! V_20 ) )
V_20 = F_24 ( V_16 ) ;
else
F_25 ( V_16 ) ;
return V_20 ;
}
static int
F_26 ( struct V_1 * V_1 , unsigned long V_28 ,
int V_29 , struct V_3 * * V_14 )
{
struct V_3 * V_4 ;
T_1 V_30 = 0 ;
int V_8 = - V_21 ;
V_4 = F_16 ( V_1 , V_1 -> V_22 , V_28 , 0 ) ;
if ( F_5 ( ! V_4 ) )
goto V_31;
V_8 = - V_24 ;
if ( F_17 ( V_4 ) )
goto V_32;
if ( V_29 == V_33 ) {
if ( ! F_27 ( V_4 ) ) {
V_8 = - V_34 ;
goto V_25;
}
} else
F_28 ( V_4 ) ;
if ( F_17 ( V_4 ) ) {
F_29 ( V_4 ) ;
goto V_32;
}
V_8 = F_30 ( F_3 ( V_1 ) -> V_10 , V_28 , & V_30 ) ;
if ( F_5 ( V_8 ) ) {
F_29 ( V_4 ) ;
goto V_25;
}
F_31 ( V_4 , V_1 -> V_17 , ( V_35 ) V_30 ) ;
V_4 -> V_36 = V_37 ;
F_20 ( V_4 ) ;
F_32 ( V_29 , V_4 ) ;
V_8 = 0 ;
V_32:
F_20 ( V_4 ) ;
* V_14 = V_4 ;
V_25:
F_21 ( V_4 -> V_11 ) ;
F_22 ( V_4 -> V_11 ) ;
F_23 ( V_4 ) ;
V_31:
return V_8 ;
}
static int F_33 ( struct V_1 * V_1 , unsigned long V_2 ,
int V_38 , struct V_3 * * V_14 )
{
struct V_3 * V_39 , * V_4 ;
unsigned long V_28 ;
int V_40 , V_41 = V_42 ;
int V_20 ;
V_20 = F_26 ( V_1 , V_2 , V_43 , & V_39 ) ;
if ( V_20 == - V_24 )
goto V_32;
if ( F_5 ( V_20 ) )
goto V_31;
if ( V_38 ) {
V_28 = V_2 + 1 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ , V_28 ++ ) {
V_20 = F_26 ( V_1 , V_28 , V_33 , & V_4 ) ;
if ( F_19 ( ! V_20 || V_20 == - V_24 ) )
F_23 ( V_4 ) ;
else if ( V_20 != - V_34 )
break;
if ( ! F_34 ( V_39 ) )
goto V_44;
}
}
F_18 ( V_39 ) ;
V_44:
V_20 = - V_45 ;
if ( ! F_17 ( V_39 ) )
goto V_25;
V_32:
* V_14 = V_39 ;
return 0 ;
V_25:
F_23 ( V_39 ) ;
V_31:
return V_20 ;
}
int F_35 ( struct V_1 * V_1 , unsigned long V_28 , int V_46 ,
void (* F_2)( struct V_1 * ,
struct V_3 * , void * ) ,
struct V_3 * * V_14 )
{
int V_8 ;
V_47:
V_8 = F_33 ( V_1 , V_28 , ! V_46 , V_14 ) ;
if ( ! V_46 || V_8 != - V_48 )
return V_8 ;
V_8 = F_14 ( V_1 , V_28 , V_14 , F_2 ) ;
if ( F_5 ( V_8 == - V_24 ) ) {
goto V_47;
}
return V_8 ;
}
int F_36 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
int V_20 ;
V_20 = F_37 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_20 || V_20 == - V_48 ) {
F_13 ( V_1 ) ;
F_38 ( V_1 , V_2 ) ;
}
return V_20 ;
}
int F_38 ( struct V_1 * V_1 , unsigned long V_2 )
{
T_2 V_49 = ( T_2 ) V_2 >>
( V_50 - V_1 -> V_13 ) ;
struct V_51 * V_51 ;
unsigned long V_52 ;
int V_8 = 0 ;
int V_53 ;
V_51 = F_39 ( V_1 -> V_22 , V_49 ) ;
if ( ! V_51 )
return - V_48 ;
F_40 ( V_51 ) ;
V_52 = ( unsigned long ) V_49 <<
( V_50 - V_1 -> V_13 ) ;
if ( F_41 ( V_51 ) ) {
struct V_3 * V_4 ;
V_4 = F_42 ( V_51 , V_2 - V_52 ) ;
F_43 ( V_4 ) ;
}
V_53 = F_44 ( V_51 ) ;
F_21 ( V_51 ) ;
F_22 ( V_51 ) ;
if ( V_53 ||
F_45 ( V_1 -> V_22 , V_49 , V_49 ) != 0 )
V_8 = - V_34 ;
return V_8 ;
}
int F_46 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
int V_20 ;
V_20 = F_33 ( V_1 , V_2 , 0 , & V_4 ) ;
if ( F_5 ( V_20 ) )
return V_20 ;
F_12 ( V_4 ) ;
F_13 ( V_1 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_3 ( V_1 ) ;
if ( F_48 ( V_6 -> V_10 ) ) {
F_49 ( V_54 , & V_6 -> V_55 ) ;
return 1 ;
}
return F_50 ( V_54 , & V_6 -> V_55 ) ;
}
static int
F_51 ( struct V_51 * V_51 , struct V_56 * V_57 )
{
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_20 = 0 ;
F_52 ( V_57 , V_51 ) ;
F_21 ( V_51 ) ;
V_1 = V_51 -> V_58 -> V_59 ;
if ( ! V_1 )
return 0 ;
V_16 = V_1 -> V_17 ;
if ( V_57 -> V_60 == V_61 )
V_20 = F_53 ( V_16 ) ;
else if ( V_57 -> V_62 )
F_54 ( V_16 , V_1 -> V_63 ) ;
return V_20 ;
}
int F_55 ( struct V_1 * V_1 , T_3 V_64 , T_4 V_65 )
{
struct V_66 * V_67 ;
V_67 = F_56 ( F_57 ( sizeof( * V_67 ) , V_65 ) , V_68 ) ;
if ( ! V_67 )
return - V_21 ;
F_58 ( & V_67 -> V_69 ) ;
V_1 -> V_70 = V_67 ;
V_1 -> V_71 = V_72 ;
F_59 ( V_1 -> V_22 , V_64 ) ;
V_1 -> V_22 -> V_73 = V_1 -> V_17 -> V_74 ;
V_1 -> V_75 = & V_76 ;
V_1 -> V_77 = & V_78 ;
V_1 -> V_22 -> V_79 = & V_80 ;
return 0 ;
}
void F_60 ( struct V_1 * V_1 , unsigned V_81 ,
unsigned V_82 )
{
struct V_66 * V_67 = F_61 ( V_1 ) ;
V_67 -> V_83 = V_81 ;
V_67 -> V_84 = ( 1 << V_1 -> V_13 ) / V_81 ;
V_67 -> V_85 = F_62 ( V_82 , V_81 ) ;
}
int F_63 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
struct V_66 * V_67 = F_61 ( V_1 ) ;
struct V_73 * V_88 = V_1 -> V_17 -> V_74 ;
F_64 ( & V_87 -> V_89 ) ;
F_65 ( & V_87 -> V_90 ) ;
F_66 ( & V_87 -> V_90 , V_1 , V_88 ) ;
F_65 ( & V_87 -> V_91 ) ;
F_66 ( & V_87 -> V_91 , V_1 , V_88 ) ;
V_67 -> V_92 = V_87 ;
return 0 ;
}
int F_67 ( struct V_1 * V_1 )
{
struct V_66 * V_67 = F_61 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_86 * V_87 = V_67 -> V_92 ;
int V_8 ;
V_8 = F_68 ( & V_87 -> V_90 , V_1 -> V_22 ) ;
if ( V_8 )
goto V_32;
V_8 = F_68 ( & V_87 -> V_91 ,
& V_6 -> V_93 ) ;
if ( V_8 )
goto V_32;
F_69 ( V_6 -> V_10 , & V_87 -> V_94 ) ;
V_32:
return V_8 ;
}
int F_70 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_86 * V_87 = F_61 ( V_1 ) -> V_92 ;
struct V_3 * V_95 ;
struct V_51 * V_51 ;
int V_96 = V_1 -> V_13 ;
V_51 = F_71 ( & V_87 -> V_90 , V_4 -> V_11 -> V_49 ) ;
if ( ! V_51 )
return - V_21 ;
if ( ! F_41 ( V_51 ) )
F_72 ( V_51 , 1 << V_96 , 0 ) ;
V_95 = F_42 ( V_51 , F_8 ( V_4 ) >> V_96 ) ;
if ( ! F_17 ( V_95 ) )
F_73 ( V_95 , V_4 ) ;
if ( F_74 ( & V_95 -> V_97 ) ) {
F_75 ( & V_95 -> V_97 ,
& V_87 -> V_89 ) ;
F_76 ( V_4 ) ;
} else {
F_23 ( V_95 ) ;
}
F_21 ( V_51 ) ;
F_22 ( V_51 ) ;
return 0 ;
}
struct V_3 *
F_77 ( struct V_1 * V_1 , struct V_3 * V_4 )
{
struct V_86 * V_87 = F_61 ( V_1 ) -> V_92 ;
struct V_3 * V_95 = NULL ;
struct V_51 * V_51 ;
int V_98 ;
V_51 = F_39 ( & V_87 -> V_90 , V_4 -> V_11 -> V_49 ) ;
if ( V_51 ) {
if ( F_41 ( V_51 ) ) {
V_98 = F_8 ( V_4 ) >> V_1 -> V_13 ;
V_95 = F_42 ( V_51 , V_98 ) ;
}
F_21 ( V_51 ) ;
F_22 ( V_51 ) ;
}
return V_95 ;
}
static void F_78 ( struct V_86 * V_87 )
{
struct V_99 * V_100 = & V_87 -> V_89 ;
struct V_3 * V_4 ;
while ( ! F_74 ( V_100 ) ) {
V_4 = F_79 ( V_100 , struct V_3 ,
V_97 ) ;
F_80 ( & V_4 -> V_97 ) ;
F_23 ( V_4 ) ;
}
}
void F_81 ( struct V_1 * V_1 )
{
struct V_66 * V_67 = F_61 ( V_1 ) ;
struct V_5 * V_6 = F_3 ( V_1 ) ;
struct V_86 * V_87 = V_67 -> V_92 ;
F_82 ( & V_67 -> V_69 ) ;
if ( V_67 -> V_101 )
F_83 ( V_1 ) ;
F_84 ( V_1 -> V_22 ) ;
F_85 ( V_1 -> V_22 , & V_87 -> V_90 ) ;
F_84 ( & V_6 -> V_93 ) ;
F_85 ( & V_6 -> V_93 , & V_87 -> V_91 ) ;
F_86 ( V_6 -> V_10 , & V_87 -> V_94 ) ;
F_87 ( & V_67 -> V_69 ) ;
}
void F_88 ( struct V_1 * V_1 )
{
struct V_66 * V_67 = F_61 ( V_1 ) ;
struct V_86 * V_87 = V_67 -> V_92 ;
F_82 ( & V_67 -> V_69 ) ;
F_78 ( V_87 ) ;
F_89 ( & V_87 -> V_90 , 0 ) ;
F_89 ( & V_87 -> V_91 , 0 ) ;
F_87 ( & V_67 -> V_69 ) ;
}
