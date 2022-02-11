static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_10 = 0 ;
if ( V_4 <= V_11 )
V_6 = V_3 -> V_12 ;
else
V_6 = V_3 -> V_13 ;
V_7 = F_2 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( sizeof( * V_7 ) , V_14 ,
F_4 ( V_3 ) ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
goto V_16;
}
V_9 = & V_7 -> V_17 . V_9 ;
V_9 -> V_18 = F_5 ( V_3 -> V_19 , V_20 ,
V_6 -> V_21 . V_22 ) ;
if ( F_6 ( V_9 -> V_18 ) ) {
F_7 ( L_1 , V_23 ) ;
goto V_16;
}
V_7 -> V_6 = V_6 ;
if ( V_6 -> V_24 == V_25 )
F_8 ( V_26 ) ;
else
F_8 ( V_27 ) ;
if ( F_9 ( & V_6 -> V_28 ) > V_6 -> V_29 )
V_6 -> V_29 = V_6 -> V_30 ;
V_9 -> V_31 = V_32 ;
return V_7 ;
V_16:
F_10 ( V_7 ) ;
F_11 ( & V_6 -> V_28 ) ;
return F_12 ( V_10 ) ;
}
static void F_13 ( struct V_1 * V_7 , bool V_33 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
if ( V_33 )
F_14 ( & V_7 -> V_34 , & V_6 -> V_35 ) ;
else
F_14 ( & V_7 -> V_34 , & V_6 -> V_36 ) ;
F_15 ( V_7 -> V_37 , & V_6 -> V_38 ) ;
F_16 ( & V_6 -> V_39 ) ;
if ( F_9 ( & V_6 -> V_38 ) >= V_6 -> V_40 ||
F_9 ( & V_6 -> V_39 ) >= V_6 -> V_30 / 5 )
F_17 ( V_41 , & V_6 -> V_42 , 10 ) ;
}
static int F_18 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
int V_47 ;
while ( F_19 ( & V_7 -> V_48 -> V_49 ) <= 0 ) {
F_16 ( & V_7 -> V_48 -> V_49 ) ;
F_20 () ;
}
V_47 = F_21 ( V_9 -> V_18 , V_7 -> V_50 , V_7 -> V_37 , V_51 ) ;
if ( F_22 ( V_47 != V_7 -> V_37 ) )
return V_47 < 0 ? V_47 : - V_52 ;
F_23 ( V_9 -> V_18 , V_7 -> V_53 ++ ) ;
V_9 -> V_31 = V_54 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_55 . V_56 = ( unsigned long ) ( void * ) V_7 ;
V_46 . V_55 . V_57 = V_58 ;
V_46 . V_55 . V_59 = 0 ;
V_46 . V_18 = V_9 -> V_18 ;
V_46 . V_60 = V_9 -> V_18 -> V_61 ;
V_46 . V_62 = V_63 |
V_64 |
V_65 ;
V_46 . V_55 . V_66 = V_67 ;
V_44 = & V_46 . V_55 ;
V_47 = F_24 ( V_7 -> V_48 -> V_68 -> V_69 , & V_46 . V_55 , & V_44 ) ;
F_25 ( V_44 != & V_46 . V_55 ) ;
if ( F_22 ( V_47 ) ) {
V_9 -> V_31 = V_70 ;
F_16 ( & V_7 -> V_48 -> V_49 ) ;
if ( F_26 () )
F_7 ( L_2 ,
V_23 , V_47 ) ;
}
return V_47 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
struct V_71 * V_50 , unsigned int V_37 )
{
struct V_72 * V_73 = V_3 -> V_73 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
int V_74 ;
T_1 V_75 ;
int V_47 = 0 ;
F_28 ( V_7 ) ;
V_7 -> V_50 = V_50 ;
V_7 -> V_37 = V_37 ;
V_7 -> V_76 = 0 ;
V_9 -> V_77 = 0 ;
F_25 ( V_7 -> V_76 ) ;
V_7 -> V_76 = F_29 ( V_73 , V_7 -> V_50 , V_7 -> V_37 ,
V_78 ) ;
if ( F_22 ( ! V_7 -> V_76 ) ) {
F_7 ( L_3 , V_23 ) ;
return - V_79 ;
}
V_9 -> V_77 = 0 ;
V_9 -> V_80 = 0 ;
V_75 = 0 ;
V_47 = - V_52 ;
for ( V_74 = 0 ; V_74 < V_7 -> V_76 ; ++ V_74 ) {
unsigned int V_81 = F_30 ( V_73 , & V_7 -> V_50 [ V_74 ] ) ;
T_2 V_82 = F_31 ( V_73 , & V_7 -> V_50 [ V_74 ] ) ;
V_9 -> V_77 += V_81 ;
if ( V_82 & ~ V_83 ) {
if ( V_74 > 0 )
goto V_84;
else
++ V_9 -> V_80 ;
}
if ( ( V_82 + V_81 ) & ~ V_83 ) {
if ( V_74 < V_7 -> V_76 - 1 )
goto V_84;
else
++ V_9 -> V_80 ;
}
V_75 += V_81 ;
}
V_9 -> V_80 += V_75 >> V_85 ;
if ( V_9 -> V_80 > V_7 -> V_6 -> V_21 . V_22 ) {
V_47 = - V_86 ;
goto V_84;
}
V_47 = F_18 ( V_7 ) ;
if ( V_47 )
goto V_84;
if ( V_7 -> V_6 -> V_24 == V_25 )
F_8 ( V_87 ) ;
else
F_8 ( V_88 ) ;
return V_47 ;
V_84:
F_32 ( V_3 -> V_73 , V_7 -> V_50 , V_7 -> V_37 ,
V_78 ) ;
V_7 -> V_76 = 0 ;
return V_47 ;
}
static int F_33 ( struct V_1 * V_7 )
{
struct V_43 * V_89 , * V_44 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
struct V_90 * V_68 = V_7 -> V_48 -> V_68 ;
int V_47 = - V_52 ;
if ( ! V_68 || ! V_68 -> V_69 || ! V_9 -> V_18 )
goto V_91;
if ( V_9 -> V_31 != V_54 )
goto V_91;
while ( F_19 ( & V_7 -> V_48 -> V_49 ) <= 0 ) {
F_16 ( & V_7 -> V_48 -> V_49 ) ;
F_20 () ;
}
V_9 -> V_92 = true ;
V_89 = & V_9 -> V_93 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_56 = ( unsigned long ) ( void * ) V_7 ;
V_89 -> V_57 = V_94 ;
V_89 -> V_95 . V_96 = V_9 -> V_18 -> V_61 ;
V_89 -> V_66 = V_67 ;
V_44 = V_89 ;
V_47 = F_24 ( V_68 -> V_69 , V_89 , & V_44 ) ;
F_25 ( V_44 != V_89 ) ;
if ( F_22 ( V_47 ) ) {
V_9 -> V_31 = V_70 ;
V_9 -> V_92 = false ;
F_16 ( & V_7 -> V_48 -> V_49 ) ;
F_34 ( L_2 , V_23 , V_47 ) ;
goto V_91;
}
V_91:
return V_47 ;
}
void F_35 ( struct V_97 * V_48 , struct V_98 * V_99 )
{
struct V_1 * V_7 = ( void * ) ( unsigned long ) V_99 -> V_56 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
if ( V_99 -> V_100 != V_101 ) {
V_9 -> V_31 = V_70 ;
if ( F_36 ( V_48 -> V_102 ) )
F_37 ( V_48 -> V_102 ,
L_4 ,
& V_48 -> V_102 -> V_103 ,
& V_48 -> V_102 -> V_104 ,
V_99 -> V_100 ,
F_38 ( V_99 -> V_100 ) ,
V_99 -> V_105 ) ;
}
if ( V_9 -> V_92 ) {
V_9 -> V_31 = V_32 ;
V_9 -> V_92 = false ;
}
F_16 ( & V_48 -> V_49 ) ;
}
void F_39 ( struct V_106 * V_107 , unsigned int * V_108 ,
unsigned long * V_109 , unsigned int V_110 )
{
struct V_1 * V_7 , * V_111 ;
struct V_8 * V_9 ;
int V_47 = 0 ;
unsigned int V_112 = * V_108 ;
F_40 (ibmr, list, unmap_list) {
if ( V_7 -> V_76 )
V_47 |= F_33 ( V_7 ) ;
}
if ( V_47 )
F_7 ( L_5 , V_23 , V_47 ) ;
F_41 (ibmr, next, list, unmap_list) {
* V_109 += V_7 -> V_37 ;
V_9 = & V_7 -> V_17 . V_9 ;
F_42 ( V_7 ) ;
if ( V_112 < V_110 || V_9 -> V_31 == V_70 ) {
if ( V_9 -> V_31 == V_54 )
continue;
if ( V_7 -> V_6 -> V_24 == V_25 )
F_8 ( V_113 ) ;
else
F_8 ( V_114 ) ;
F_43 ( & V_7 -> V_115 ) ;
if ( V_9 -> V_18 )
F_44 ( V_9 -> V_18 ) ;
F_10 ( V_7 ) ;
V_112 ++ ;
}
}
* V_108 = V_112 ;
}
struct V_1 * F_45 ( struct V_2 * V_3 ,
struct V_97 * V_48 ,
struct V_71 * V_50 ,
unsigned long V_116 , T_1 * V_60 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_47 ;
do {
if ( V_7 )
F_13 ( V_7 , true ) ;
V_7 = F_1 ( V_3 , V_116 ) ;
if ( F_6 ( V_7 ) )
return V_7 ;
V_9 = & V_7 -> V_17 . V_9 ;
} while ( V_9 -> V_31 != V_32 );
V_7 -> V_48 = V_48 ;
V_7 -> V_117 = V_3 ;
V_47 = F_27 ( V_3 , V_7 -> V_6 , V_7 , V_50 , V_116 ) ;
if ( V_47 == 0 ) {
* V_60 = V_9 -> V_18 -> V_61 ;
} else {
F_13 ( V_7 , false ) ;
V_7 = F_12 ( V_47 ) ;
}
return V_7 ;
}
void F_46 ( struct V_1 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
if ( V_9 -> V_31 == V_70 )
F_14 ( & V_7 -> V_34 , & V_6 -> V_35 ) ;
else
F_14 ( & V_7 -> V_34 , & V_6 -> V_36 ) ;
}
