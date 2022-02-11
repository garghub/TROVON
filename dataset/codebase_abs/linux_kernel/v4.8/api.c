struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
int V_9 ;
V_7 = F_2 ( V_3 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_8 = F_5 () ;
if ( F_3 ( V_8 ) ) {
V_9 = F_6 ( V_8 ) ;
goto V_10;
}
V_8 -> V_11 = true ;
V_5 = F_7 ( sizeof( struct V_4 ) , V_12 ) ;
if ( ! V_5 ) {
V_9 = - V_13 ;
goto V_14;
}
F_8 ( V_5 ) ;
V_9 = F_9 ( V_8 , V_7 , false , V_5 ) ;
if ( V_9 )
goto V_15;
return V_8 ;
V_15:
F_10 ( V_5 ) ;
V_14:
F_10 ( V_8 ) ;
V_10:
return F_11 ( V_9 ) ;
}
struct V_1 * F_12 ( struct V_2 * V_3 )
{
return V_3 -> V_3 . V_16 . V_17 ;
}
int F_13 ( struct V_1 * V_8 )
{
if ( V_8 -> V_18 >= V_19 )
return - V_20 ;
F_14 ( V_8 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_8 , int V_21 )
{
T_2 V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 = V_8 -> V_25 . V_22 [ V_23 ] ;
if ( V_21 < V_22 ) {
return V_8 -> V_25 . V_26 [ V_23 ] + V_21 ;
}
V_21 -= V_22 ;
}
return 0 ;
}
int F_16 ( struct V_2 * V_27 , struct V_1 * * V_8 , int * V_28 )
{
if ( * V_8 == NULL || * V_28 == 0 ) {
* V_28 = 1 ;
* V_8 = F_12 ( V_27 ) ;
} else {
( * V_28 ) ++ ;
if ( * V_28 > F_17 ( V_27 ) ) {
* V_8 = F_18 ( * V_8 , V_29 ) ;
* V_28 = 1 ;
}
}
return F_15 ( * V_8 , * V_28 ) ;
}
int F_19 ( struct V_1 * V_8 , void * V_30 )
{
if ( ! V_8 )
return - V_31 ;
V_8 -> V_30 = V_30 ;
return 0 ;
}
void * F_20 ( struct V_1 * V_8 )
{
if ( ! V_8 )
return F_11 ( - V_31 ) ;
return V_8 -> V_30 ;
}
int F_21 ( struct V_1 * V_8 , int V_21 )
{
int V_32 ;
T_1 V_33 ;
if ( V_21 == 0 )
V_21 = V_8 -> V_7 -> V_34 ;
V_32 = F_22 ( V_8 , V_21 ) ;
if ( V_32 )
return V_32 ;
if ( ! F_23 ( V_35 ) ) {
V_33 = F_15 ( V_8 , 0 ) ;
if ( V_33 )
F_24 ( V_8 -> V_7 -> V_36 , V_33 , V_37 -> V_38 , V_8 , L_1 ) ;
}
if ( V_8 -> V_18 == V_19 ) {
if ( V_37 -> V_39 )
V_37 -> V_39 ( V_8 ) ;
else F_25 ( 1 , L_2 ) ;
}
return V_32 ;
}
void F_26 ( struct V_1 * V_8 )
{
T_1 V_33 ;
unsigned int V_40 ;
if ( ! F_23 ( V_35 ) ) {
V_33 = F_15 ( V_8 , 0 ) ;
if ( V_33 ) {
V_40 = F_27 ( NULL , V_33 ) ;
if ( V_40 )
F_28 ( V_40 , V_8 ) ;
}
}
F_29 ( V_8 ) ;
V_37 -> V_41 ( & V_8 -> V_25 , V_8 -> V_7 -> V_36 ) ;
}
int F_30 ( struct V_1 * V_8 , int V_21 ,
T_3 V_42 , void * V_43 , char * V_44 )
{
T_1 V_33 ;
V_33 = F_15 ( V_8 , V_21 ) ;
if ( ! V_33 )
return - V_45 ;
return F_24 ( V_8 -> V_7 -> V_36 , V_33 , V_42 , V_43 , V_44 ) ;
}
void F_31 ( struct V_1 * V_8 , int V_21 , void * V_43 )
{
T_1 V_33 ;
unsigned int V_40 ;
V_33 = F_15 ( V_8 , V_21 ) ;
if ( ! V_33 )
return;
V_40 = F_27 ( NULL , V_33 ) ;
if ( V_40 )
F_28 ( V_40 , V_43 ) ;
}
int F_32 ( struct V_1 * V_8 , T_4 V_46 ,
struct V_47 * V_48 )
{
int V_9 = 0 ;
bool V_49 = true ;
F_33 ( L_3 , V_50 , V_8 -> V_51 ) ;
F_34 ( & V_8 -> V_52 ) ;
if ( V_8 -> V_18 == V_19 )
goto V_53;
if ( V_48 ) {
V_8 -> V_54 = F_35 ( V_48 , V_55 ) ;
V_8 -> V_56 = F_35 ( V_48 -> V_57 , V_55 ) ;
V_49 = false ;
V_8 -> V_58 = false ;
}
F_36 () ;
if ( ( V_9 = V_37 -> V_59 ( V_8 , V_49 , V_46 , 0 ) ) ) {
F_37 ( V_8 -> V_54 ) ;
F_38 () ;
goto V_53;
}
V_8 -> V_18 = V_19 ;
V_53:
F_39 ( & V_8 -> V_52 ) ;
return V_9 ;
}
int F_40 ( struct V_1 * V_8 )
{
return V_8 -> V_60 ;
}
int F_41 ( struct V_1 * V_8 )
{
return F_42 ( V_8 ) ;
}
void F_43 ( struct V_1 * V_8 )
{
V_8 -> V_61 = true ;
}
int F_44 ( struct V_1 * V_8 , bool V_58 )
{
if ( V_8 -> V_18 == V_19 ) {
return - V_20 ;
}
V_8 -> V_58 = V_58 ;
return 0 ;
}
int F_45 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
return F_46 ( V_62 , V_63 ) ;
}
int F_47 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
return F_48 ( V_62 , V_63 ) ;
}
long F_49 ( struct V_63 * V_63 , unsigned int V_64 , unsigned long V_65 )
{
return F_50 ( V_63 , V_64 , V_65 ) ;
}
int F_51 ( struct V_63 * V_63 , struct V_66 * V_67 )
{
return F_52 ( V_63 , V_67 ) ;
}
unsigned int F_53 ( struct V_63 * V_63 , struct V_68 * V_69 )
{
return F_54 ( V_63 , V_69 ) ;
}
T_5 F_55 ( struct V_63 * V_63 , char T_6 * V_70 , T_7 V_71 ,
T_8 * V_72 )
{
return F_56 ( V_63 , V_70 , V_71 , V_72 ) ;
}
struct V_63 * F_57 ( struct V_1 * V_8 , struct V_73 * V_74 ,
int * V_75 )
{
struct V_63 * V_63 ;
int V_9 , V_76 , V_77 ;
V_76 = V_78 | V_79 ;
V_9 = F_58 ( V_76 ) ;
if ( V_9 < 0 )
return F_11 ( V_9 ) ;
V_77 = V_9 ;
if ( V_74 ) {
F_59 ( V_80 ) ;
F_59 ( V_69 ) ;
F_59 ( V_81 ) ;
F_59 ( V_82 ) ;
F_59 ( V_83 ) ;
F_59 ( V_84 ) ;
F_59 ( V_85 ) ;
} else
V_74 = (struct V_73 * ) & V_86 ;
V_63 = F_60 ( L_4 , V_74 , V_8 , V_76 ) ;
if ( F_3 ( V_63 ) )
goto V_87;
V_63 -> V_88 = V_8 -> V_5 ;
* V_75 = V_77 ;
return V_63 ;
V_87:
F_61 ( V_77 ) ;
return NULL ;
}
struct V_1 * F_62 ( struct V_63 * V_63 )
{
return V_63 -> V_89 ;
}
void F_63 ( struct V_1 * V_8 ,
struct V_90 * V_91 )
{
F_64 ( ! V_91 -> V_92 || ! V_91 -> V_93 ) ;
F_65 ( & V_8 -> V_94 , 0 ) ;
V_8 -> V_95 = V_91 ;
}
void F_66 ( struct V_1 * V_8 ,
unsigned int V_96 )
{
F_67 ( V_96 , & V_8 -> V_94 ) ;
F_68 ( & V_8 -> V_97 ) ;
}
int F_69 ( struct V_1 * V_8 ,
struct V_98 * V_99 )
{
int V_9 ;
if ( ! ( V_99 -> V_76 & V_100 ) )
V_99 -> V_101 = V_8 -> V_7 -> V_34 ;
else if ( ( V_99 -> V_101 < V_8 -> V_7 -> V_34 ) ||
( V_99 -> V_101 > V_8 -> V_7 -> V_102 ) ) {
return - V_31 ;
}
V_9 = F_70 ( V_8 , V_99 -> V_101 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_32 ( V_8 , V_99 -> V_103 , V_104 ) ;
if ( V_9 < 0 ) {
F_71 ( V_8 , V_8 ) ;
return V_9 ;
}
return 0 ;
}
void T_9 * F_72 ( struct V_1 * V_8 )
{
if ( V_8 -> V_18 != V_19 )
return NULL ;
F_33 ( L_5 ,
V_50 , V_8 -> V_105 , V_8 -> V_106 ) ;
return F_73 ( V_8 -> V_105 , V_8 -> V_106 ) ;
}
void F_74 ( void T_9 * V_107 )
{
F_75 ( V_107 ) ;
}
int F_76 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
int V_9 ;
V_9 = V_37 -> V_108 ( V_7 ) ;
if ( V_9 )
return V_9 ;
return V_37 -> V_109 ( V_7 ) ;
}
void F_77 ( struct V_6 * V_7 ,
bool V_110 )
{
V_7 -> V_36 -> V_111 = V_110 ;
}
T_5 F_78 ( struct V_2 * V_3 , void * V_70 , T_7 V_71 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
if ( F_3 ( V_7 ) )
return - V_112 ;
return V_37 -> V_113 ( V_7 -> V_36 , V_70 , V_71 ) ;
}
int F_79 ( struct V_2 * V_3 , int V_25 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
if ( F_3 ( V_7 ) )
return - V_112 ;
if ( V_25 > V_7 -> V_36 -> V_114 )
return - V_31 ;
V_7 -> V_36 -> V_114 = V_25 ;
V_7 -> V_102 = V_25 ;
return 0 ;
}
int F_17 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
if ( F_3 ( V_7 ) )
return - V_112 ;
return V_7 -> V_102 ;
}
int F_80 ( struct V_2 * V_27 , int V_115 , int type )
{
struct V_1 * V_8 , * V_116 , * V_117 ;
int V_118 ;
int V_9 ;
V_8 = V_117 = F_12 ( V_27 ) ;
if ( F_64 ( ! V_117 ) )
return - V_112 ;
V_118 = V_115 ;
while ( V_118 > 0 ) {
V_9 = F_21 ( V_8 , F_81 ( V_118 , V_8 -> V_7 -> V_102 ) ) ;
if ( V_9 ) {
F_82 ( L_6 , F_83 ( V_27 ) ) ;
return V_9 ;
}
V_118 -= V_8 -> V_7 -> V_102 ;
if ( V_8 != V_117 && V_117 -> V_18 == V_19 ) {
F_64 ( F_32 ( V_8 ,
F_84 ( V_117 -> V_119 -> V_120 . V_46 ) ,
NULL ) ) ;
}
if ( V_118 > 0 ) {
V_116 = F_1 ( V_27 ) ;
if ( ! V_116 ) {
F_82 ( L_7 , F_83 ( V_27 ) ) ;
return - V_121 ;
}
F_85 ( & V_116 -> V_29 , & V_8 -> V_29 ) ;
V_8 = V_116 ;
}
}
return 0 ;
}
void F_86 ( struct V_2 * V_27 )
{
struct V_1 * V_8 , * V_122 , * V_123 ;
V_8 = F_12 ( V_27 ) ;
if ( F_64 ( ! V_8 ) )
return;
F_26 ( V_8 ) ;
F_87 (pos, tmp, &ctx->extra_irq_contexts, extra_irq_contexts) {
F_41 ( V_122 ) ;
F_26 ( V_122 ) ;
F_88 ( & V_122 -> V_29 ) ;
F_13 ( V_122 ) ;
}
}
