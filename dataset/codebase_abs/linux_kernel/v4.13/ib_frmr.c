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
int V_47 , V_48 = 0 ;
while ( F_19 ( & V_7 -> V_49 -> V_50 ) <= 0 ) {
F_16 ( & V_7 -> V_49 -> V_50 ) ;
F_20 () ;
}
V_47 = F_21 ( V_9 -> V_18 , V_7 -> V_51 , V_7 -> V_37 ,
& V_48 , V_52 ) ;
if ( F_22 ( V_47 != V_7 -> V_37 ) )
return V_47 < 0 ? V_47 : - V_53 ;
F_23 ( V_9 -> V_18 , V_7 -> V_54 ++ ) ;
V_9 -> V_31 = V_55 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_56 . V_57 = ( unsigned long ) ( void * ) V_7 ;
V_46 . V_56 . V_58 = V_59 ;
V_46 . V_56 . V_60 = 0 ;
V_46 . V_18 = V_9 -> V_18 ;
V_46 . V_61 = V_9 -> V_18 -> V_62 ;
V_46 . V_63 = V_64 |
V_65 |
V_66 ;
V_46 . V_56 . V_67 = V_68 ;
V_44 = & V_46 . V_56 ;
V_47 = F_24 ( V_7 -> V_49 -> V_69 -> V_70 , & V_46 . V_56 , & V_44 ) ;
F_25 ( V_44 != & V_46 . V_56 ) ;
if ( F_22 ( V_47 ) ) {
V_9 -> V_31 = V_71 ;
F_16 ( & V_7 -> V_49 -> V_50 ) ;
if ( F_26 () )
F_7 ( L_2 ,
V_23 , V_47 ) ;
}
return V_47 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
struct V_72 * V_51 , unsigned int V_37 )
{
struct V_73 * V_74 = V_3 -> V_74 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
int V_75 ;
T_1 V_76 ;
int V_47 = 0 ;
F_28 ( V_7 ) ;
V_7 -> V_51 = V_51 ;
V_7 -> V_37 = V_37 ;
V_7 -> V_77 = 0 ;
V_9 -> V_78 = 0 ;
F_25 ( V_7 -> V_77 ) ;
V_7 -> V_77 = F_29 ( V_74 , V_7 -> V_51 , V_7 -> V_37 ,
V_79 ) ;
if ( F_22 ( ! V_7 -> V_77 ) ) {
F_7 ( L_3 , V_23 ) ;
return - V_80 ;
}
V_9 -> V_78 = 0 ;
V_9 -> V_81 = 0 ;
V_76 = 0 ;
V_47 = - V_53 ;
for ( V_75 = 0 ; V_75 < V_7 -> V_77 ; ++ V_75 ) {
unsigned int V_82 = F_30 ( V_74 , & V_7 -> V_51 [ V_75 ] ) ;
T_2 V_83 = F_31 ( V_74 , & V_7 -> V_51 [ V_75 ] ) ;
V_9 -> V_78 += V_82 ;
if ( V_83 & ~ V_84 ) {
if ( V_75 > 0 )
goto V_85;
else
++ V_9 -> V_81 ;
}
if ( ( V_83 + V_82 ) & ~ V_84 ) {
if ( V_75 < V_7 -> V_77 - 1 )
goto V_85;
else
++ V_9 -> V_81 ;
}
V_76 += V_82 ;
}
V_9 -> V_81 += V_76 >> V_86 ;
if ( V_9 -> V_81 > V_7 -> V_6 -> V_21 . V_22 ) {
V_47 = - V_87 ;
goto V_85;
}
V_47 = F_18 ( V_7 ) ;
if ( V_47 )
goto V_85;
if ( V_7 -> V_6 -> V_24 == V_25 )
F_8 ( V_88 ) ;
else
F_8 ( V_89 ) ;
return V_47 ;
V_85:
F_32 ( V_3 -> V_74 , V_7 -> V_51 , V_7 -> V_37 ,
V_79 ) ;
V_7 -> V_77 = 0 ;
return V_47 ;
}
static int F_33 ( struct V_1 * V_7 )
{
struct V_43 * V_90 , * V_44 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
struct V_91 * V_69 = V_7 -> V_49 -> V_69 ;
int V_47 = - V_53 ;
if ( ! V_69 || ! V_69 -> V_70 || ! V_9 -> V_18 )
goto V_92;
if ( V_9 -> V_31 != V_55 )
goto V_92;
while ( F_19 ( & V_7 -> V_49 -> V_93 ) <= 0 ) {
F_16 ( & V_7 -> V_49 -> V_93 ) ;
F_20 () ;
}
V_9 -> V_94 = true ;
V_90 = & V_9 -> V_95 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_57 = ( unsigned long ) ( void * ) V_7 ;
V_90 -> V_58 = V_96 ;
V_90 -> V_97 . V_98 = V_9 -> V_18 -> V_62 ;
V_90 -> V_67 = V_68 ;
V_44 = V_90 ;
V_47 = F_24 ( V_69 -> V_70 , V_90 , & V_44 ) ;
F_25 ( V_44 != V_90 ) ;
if ( F_22 ( V_47 ) ) {
V_9 -> V_31 = V_71 ;
V_9 -> V_94 = false ;
F_16 ( & V_7 -> V_49 -> V_93 ) ;
F_34 ( L_2 , V_23 , V_47 ) ;
goto V_92;
}
V_92:
return V_47 ;
}
void F_35 ( struct V_99 * V_49 , struct V_100 * V_101 )
{
struct V_1 * V_7 = ( void * ) ( unsigned long ) V_101 -> V_57 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
if ( V_101 -> V_102 != V_103 ) {
V_9 -> V_31 = V_71 ;
if ( F_36 ( V_49 -> V_104 ) )
F_37 ( V_49 -> V_104 ,
L_4 ,
& V_49 -> V_104 -> V_105 ,
& V_49 -> V_104 -> V_106 ,
V_101 -> V_102 ,
F_38 ( V_101 -> V_102 ) ,
V_101 -> V_107 ) ;
}
if ( V_9 -> V_94 ) {
V_9 -> V_31 = V_32 ;
V_9 -> V_94 = false ;
F_16 ( & V_49 -> V_50 ) ;
} else {
F_16 ( & V_49 -> V_93 ) ;
}
}
void F_39 ( struct V_108 * V_109 , unsigned int * V_110 ,
unsigned long * V_111 , unsigned int V_112 )
{
struct V_1 * V_7 , * V_113 ;
struct V_8 * V_9 ;
int V_47 = 0 ;
unsigned int V_114 = * V_110 ;
F_40 (ibmr, list, unmap_list) {
if ( V_7 -> V_77 )
V_47 |= F_33 ( V_7 ) ;
}
if ( V_47 )
F_7 ( L_5 , V_23 , V_47 ) ;
F_41 (ibmr, next, list, unmap_list) {
* V_111 += V_7 -> V_37 ;
V_9 = & V_7 -> V_17 . V_9 ;
F_42 ( V_7 ) ;
if ( V_114 < V_112 || V_9 -> V_31 == V_71 ) {
if ( V_9 -> V_31 == V_55 )
continue;
if ( V_7 -> V_6 -> V_24 == V_25 )
F_8 ( V_115 ) ;
else
F_8 ( V_116 ) ;
F_43 ( & V_7 -> V_117 ) ;
if ( V_9 -> V_18 )
F_44 ( V_9 -> V_18 ) ;
F_10 ( V_7 ) ;
V_114 ++ ;
}
}
* V_110 = V_114 ;
}
struct V_1 * F_45 ( struct V_2 * V_3 ,
struct V_99 * V_49 ,
struct V_72 * V_51 ,
unsigned long V_118 , T_1 * V_61 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_47 ;
do {
if ( V_7 )
F_13 ( V_7 , true ) ;
V_7 = F_1 ( V_3 , V_118 ) ;
if ( F_6 ( V_7 ) )
return V_7 ;
V_9 = & V_7 -> V_17 . V_9 ;
} while ( V_9 -> V_31 != V_32 );
V_7 -> V_49 = V_49 ;
V_7 -> V_119 = V_3 ;
V_47 = F_27 ( V_3 , V_7 -> V_6 , V_7 , V_51 , V_118 ) ;
if ( V_47 == 0 ) {
* V_61 = V_9 -> V_18 -> V_62 ;
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
if ( V_9 -> V_31 == V_71 )
F_14 ( & V_7 -> V_34 , & V_6 -> V_35 ) ;
else
F_14 ( & V_7 -> V_34 , & V_6 -> V_36 ) ;
}
