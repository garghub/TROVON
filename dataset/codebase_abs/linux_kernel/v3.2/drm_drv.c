int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
int V_6 ;
F_2 ( L_1 ) ;
if ( V_2 -> V_7 -> V_8 )
V_2 -> V_7 -> V_8 ( V_2 ) ;
F_2 ( L_2 ) ;
if ( V_2 -> V_9 && ! F_3 ( V_2 , V_10 ) )
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_11 ) ;
if ( F_6 ( V_2 ) && V_2 -> V_12 &&
! F_3 ( V_2 , V_10 ) ) {
struct V_13 * V_14 , * V_15 ;
F_7 (entry, tempe, &dev->agp->memory, head) {
if ( V_14 -> V_16 )
F_8 ( V_14 -> V_17 ) ;
F_9 ( V_14 -> V_17 , V_14 -> V_18 ) ;
F_10 ( V_14 ) ;
}
F_11 ( & V_2 -> V_12 -> V_17 ) ;
if ( V_2 -> V_12 -> V_19 )
F_12 ( V_2 ) ;
V_2 -> V_12 -> V_19 = 0 ;
V_2 -> V_12 -> V_20 = 0 ;
}
if ( F_3 ( V_2 , V_21 ) && V_2 -> V_22 &&
! F_3 ( V_2 , V_10 ) ) {
F_13 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
F_7 (vma, vma_temp, &dev->vmalist, head) {
F_14 ( & V_4 -> V_23 ) ;
F_10 ( V_4 ) ;
}
if ( F_3 ( V_2 , V_24 ) && V_2 -> V_25 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_26 ; V_6 ++ ) {
F_10 ( V_2 -> V_25 [ V_6 ] ) ;
V_2 -> V_25 [ V_6 ] = NULL ;
}
F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
V_2 -> V_26 = 0 ;
if ( F_3 ( V_2 , V_27 ) &&
! F_3 ( V_2 , V_10 ) )
F_15 ( V_2 ) ;
V_2 -> V_28 = NULL ;
F_16 ( & V_2 -> V_11 ) ;
F_2 ( L_3 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_29 = - V_30 ;
F_18 () ;
F_19 ( & V_31 ) ;
if ( F_20 ( V_32 , L_4 , & V_33 ) )
goto V_34;
V_35 = F_21 ( V_36 , L_4 ) ;
if ( F_22 ( V_35 ) ) {
F_23 ( V_37 L_5 ) ;
V_29 = F_24 ( V_35 ) ;
goto V_38;
}
V_39 = F_25 ( L_6 , NULL ) ;
if ( ! V_39 ) {
F_26 ( L_7 ) ;
V_29 = - 1 ;
goto V_40;
}
V_41 = F_27 ( L_6 , NULL ) ;
if ( ! V_41 ) {
F_26 ( L_8 ) ;
V_29 = - 1 ;
goto V_40;
}
F_28 ( L_9 ,
V_42 , V_43 , V_44 , V_45 , V_46 ) ;
return 0 ;
V_40:
F_29 () ;
V_38:
F_30 ( V_32 , L_4 ) ;
F_31 ( & V_31 ) ;
V_34:
return V_29 ;
}
static void T_2 F_32 ( void )
{
F_33 ( L_6 , NULL ) ;
F_34 ( V_41 ) ;
F_29 () ;
F_30 ( V_32 , L_4 ) ;
F_35 ( & V_31 ) ;
F_31 ( & V_31 ) ;
}
static int F_36 ( char * V_47 , T_3 * V_48 , const char * V_49 )
{
int V_50 ;
V_50 = strlen ( V_49 ) ;
if ( V_50 > * V_48 )
V_50 = * V_48 ;
* V_48 = strlen ( V_49 ) ;
if ( V_50 && V_47 )
if ( F_37 ( V_47 , V_49 , V_50 ) )
return - V_51 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_52 ,
struct V_53 * V_54 )
{
struct F_38 * V_55 = V_52 ;
int V_56 ;
V_55 -> V_57 = V_2 -> V_7 -> V_58 ;
V_55 -> V_59 = V_2 -> V_7 -> V_60 ;
V_55 -> V_61 = V_2 -> V_7 -> V_62 ;
V_56 = F_36 ( V_55 -> V_63 , & V_55 -> V_64 ,
V_2 -> V_7 -> V_63 ) ;
if ( ! V_56 )
V_56 = F_36 ( V_55 -> V_65 , & V_55 -> V_66 ,
V_2 -> V_7 -> V_65 ) ;
if ( ! V_56 )
V_56 = F_36 ( V_55 -> V_67 , & V_55 -> V_68 ,
V_2 -> V_7 -> V_67 ) ;
return V_56 ;
}
long F_39 ( struct V_69 * V_70 ,
unsigned int V_71 , unsigned long V_72 )
{
struct V_53 * V_54 = V_70 -> V_73 ;
struct V_1 * V_2 ;
struct V_74 * V_75 ;
T_4 * V_76 ;
unsigned int V_77 = F_40 ( V_71 ) ;
int V_78 = - V_79 ;
char V_80 [ 128 ] ;
char * V_81 = NULL ;
unsigned int V_82 , V_83 ;
V_2 = V_54 -> V_60 -> V_2 ;
F_41 ( & V_2 -> V_84 ) ;
F_41 ( & V_2 -> V_85 [ V_86 ] ) ;
++ V_54 -> V_84 ;
F_2 ( L_10 ,
F_42 ( V_87 ) , V_71 , V_77 ,
( long ) F_43 ( V_54 -> V_60 -> V_88 ) ,
V_54 -> V_89 ) ;
if ( ( V_77 >= V_90 ) &&
( ( V_77 < V_91 ) || ( V_77 >= V_92 ) ) )
goto V_93;
if ( ( V_77 >= V_91 ) && ( V_77 < V_92 ) &&
( V_77 < V_91 + V_2 -> V_7 -> V_94 ) ) {
T_5 V_95 ;
V_75 = & V_2 -> V_7 -> V_96 [ V_77 - V_91 ] ;
V_95 = F_44 ( V_75 -> V_97 ) ;
V_82 = V_83 = F_44 ( V_71 ) ;
if ( V_95 > V_83 )
V_83 = V_95 ;
}
else if ( ( V_77 >= V_92 ) || ( V_77 < V_91 ) ) {
V_75 = & V_98 [ V_77 ] ;
V_71 = V_75 -> V_71 ;
V_82 = V_83 = F_44 ( V_71 ) ;
} else
goto V_93;
V_76 = V_75 -> V_76 ;
if ( ( V_77 == F_40 ( V_99 ) ) && V_2 -> V_7 -> V_100 )
V_76 = V_2 -> V_7 -> V_100 ;
if ( ! V_76 ) {
F_2 ( L_11 ) ;
V_78 = - V_79 ;
} else if ( ( ( V_75 -> V_101 & V_102 ) && ! F_45 ( V_103 ) ) ||
( ( V_75 -> V_101 & V_104 ) && ! V_54 -> V_89 ) ||
( ( V_75 -> V_101 & V_105 ) && ! V_54 -> V_106 ) ||
( ! ( V_75 -> V_101 & V_107 ) && ( V_54 -> V_60 -> type == V_108 ) ) ) {
V_78 = - V_109 ;
} else {
if ( V_71 & ( V_110 | V_111 ) ) {
if ( V_83 <= sizeof( V_80 ) ) {
V_81 = V_80 ;
} else {
V_81 = F_46 ( V_83 , V_112 ) ;
if ( ! V_81 ) {
V_78 = - V_30 ;
goto V_93;
}
}
if ( V_83 > V_82 )
memset ( V_81 + V_82 , 0 , V_83 - V_82 ) ;
}
if ( V_71 & V_110 ) {
if ( F_47 ( V_81 , ( void V_113 * ) V_72 ,
V_82 ) != 0 ) {
V_78 = - V_51 ;
goto V_93;
}
} else
memset ( V_81 , 0 , V_82 ) ;
if ( V_75 -> V_101 & V_114 )
V_78 = V_76 ( V_2 , V_81 , V_54 ) ;
else {
F_5 ( & V_115 ) ;
V_78 = V_76 ( V_2 , V_81 , V_54 ) ;
F_16 ( & V_115 ) ;
}
if ( V_71 & V_111 ) {
if ( F_37 ( ( void V_113 * ) V_72 , V_81 ,
V_82 ) != 0 )
V_78 = - V_51 ;
}
}
V_93:
if ( V_81 != V_80 )
F_10 ( V_81 ) ;
F_48 ( & V_2 -> V_84 ) ;
if ( V_78 )
F_2 ( L_12 , V_78 ) ;
return V_78 ;
}
struct V_116 * F_49 ( struct V_1 * V_2 )
{
struct V_117 * V_14 ;
F_50 (entry, &dev->maplist, head) {
if ( V_14 -> V_118 && V_14 -> V_118 -> type == V_119 &&
( V_14 -> V_118 -> V_101 & V_120 ) ) {
return V_14 -> V_118 ;
}
}
return NULL ;
}
