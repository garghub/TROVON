int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( L_1 ) ;
if ( V_2 -> V_6 -> V_7 )
V_2 -> V_6 -> V_7 ( V_2 ) ;
F_2 ( L_2 ) ;
if ( V_2 -> V_8 && ! F_3 ( V_2 , V_9 ) )
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( F_6 ( V_2 ) && V_2 -> V_11 &&
! F_3 ( V_2 , V_9 ) ) {
struct V_12 * V_13 , * V_14 ;
F_7 (entry, tempe, &dev->agp->memory, head) {
if ( V_13 -> V_15 )
F_8 ( V_13 -> V_16 ) ;
F_9 ( V_13 -> V_16 , V_13 -> V_17 ) ;
F_10 ( V_13 ) ;
}
F_11 ( & V_2 -> V_11 -> V_16 ) ;
if ( V_2 -> V_11 -> V_18 )
F_12 ( V_2 ) ;
V_2 -> V_11 -> V_18 = 0 ;
V_2 -> V_11 -> V_19 = 0 ;
}
if ( F_3 ( V_2 , V_20 ) && V_2 -> V_21 &&
! F_3 ( V_2 , V_9 ) ) {
F_13 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
F_7 (vma, vma_temp, &dev->vmalist, head) {
F_14 ( & V_4 -> V_22 ) ;
F_10 ( V_4 ) ;
}
if ( F_3 ( V_2 , V_23 ) &&
! F_3 ( V_2 , V_9 ) )
F_15 ( V_2 ) ;
V_2 -> V_24 = NULL ;
F_16 ( & V_2 -> V_10 ) ;
F_2 ( L_3 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_25 = - V_26 ;
F_18 () ;
F_19 ( & V_27 ) ;
if ( F_20 ( V_28 , L_4 , & V_29 ) )
goto V_30;
V_31 = F_21 ( V_32 , L_4 ) ;
if ( F_22 ( V_31 ) ) {
F_23 ( V_33 L_5 ) ;
V_25 = F_24 ( V_31 ) ;
goto V_34;
}
V_35 = F_25 ( L_6 , NULL ) ;
if ( ! V_35 ) {
F_26 ( L_7 ) ;
V_25 = - 1 ;
goto V_36;
}
V_37 = F_27 ( L_6 , NULL ) ;
if ( ! V_37 ) {
F_26 ( L_8 ) ;
V_25 = - 1 ;
goto V_36;
}
F_28 ( L_9 ,
V_38 , V_39 , V_40 , V_41 , V_42 ) ;
return 0 ;
V_36:
F_29 () ;
V_34:
F_30 ( V_28 , L_4 ) ;
F_31 ( & V_27 ) ;
V_30:
return V_25 ;
}
static void T_2 F_32 ( void )
{
F_33 ( L_6 , NULL ) ;
F_34 ( V_37 ) ;
F_29 () ;
F_30 ( V_28 , L_4 ) ;
F_35 ( & V_27 ) ;
F_31 ( & V_27 ) ;
}
static int F_36 ( char * V_43 , T_3 * V_44 , const char * V_45 )
{
int V_46 ;
V_46 = strlen ( V_45 ) ;
if ( V_46 > * V_44 )
V_46 = * V_44 ;
* V_44 = strlen ( V_45 ) ;
if ( V_46 && V_43 )
if ( F_37 ( V_43 , V_45 , V_46 ) )
return - V_47 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_48 ,
struct V_49 * V_50 )
{
struct F_38 * V_51 = V_48 ;
int V_52 ;
V_51 -> V_53 = V_2 -> V_6 -> V_54 ;
V_51 -> V_55 = V_2 -> V_6 -> V_56 ;
V_51 -> V_57 = V_2 -> V_6 -> V_58 ;
V_52 = F_36 ( V_51 -> V_59 , & V_51 -> V_60 ,
V_2 -> V_6 -> V_59 ) ;
if ( ! V_52 )
V_52 = F_36 ( V_51 -> V_61 , & V_51 -> V_62 ,
V_2 -> V_6 -> V_61 ) ;
if ( ! V_52 )
V_52 = F_36 ( V_51 -> V_63 , & V_51 -> V_64 ,
V_2 -> V_6 -> V_63 ) ;
return V_52 ;
}
long F_39 ( struct V_65 * V_66 ,
unsigned int V_67 , unsigned long V_68 )
{
struct V_49 * V_50 = V_66 -> V_69 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
T_4 * V_72 ;
unsigned int V_73 = F_40 ( V_67 ) ;
int V_74 = - V_75 ;
char V_76 [ 128 ] ;
char * V_77 = NULL ;
unsigned int V_78 , V_79 ;
V_2 = V_50 -> V_56 -> V_2 ;
if ( F_41 ( V_2 ) )
return - V_80 ;
F_42 ( & V_2 -> V_81 ) ;
F_42 ( & V_2 -> V_82 [ V_83 ] ) ;
++ V_50 -> V_81 ;
F_2 ( L_10 ,
F_43 ( V_84 ) , V_67 , V_73 ,
( long ) F_44 ( V_50 -> V_56 -> V_85 ) ,
V_50 -> V_86 ) ;
if ( ( V_73 >= V_87 ) &&
( ( V_73 < V_88 ) || ( V_73 >= V_89 ) ) )
goto V_90;
if ( ( V_73 >= V_88 ) && ( V_73 < V_89 ) &&
( V_73 < V_88 + V_2 -> V_6 -> V_91 ) ) {
T_5 V_92 ;
V_71 = & V_2 -> V_6 -> V_93 [ V_73 - V_88 ] ;
V_92 = F_45 ( V_71 -> V_94 ) ;
V_78 = V_79 = F_45 ( V_67 ) ;
if ( V_92 > V_79 )
V_79 = V_92 ;
}
else if ( ( V_73 >= V_89 ) || ( V_73 < V_88 ) ) {
V_71 = & V_95 [ V_73 ] ;
V_67 = V_71 -> V_67 ;
V_78 = V_79 = F_45 ( V_67 ) ;
} else
goto V_90;
V_72 = V_71 -> V_72 ;
if ( ( V_73 == F_40 ( V_96 ) ) && V_2 -> V_6 -> V_97 )
V_72 = V_2 -> V_6 -> V_97 ;
if ( ! V_72 ) {
F_2 ( L_11 ) ;
V_74 = - V_75 ;
} else if ( ( ( V_71 -> V_98 & V_99 ) && ! F_46 ( V_100 ) ) ||
( ( V_71 -> V_98 & V_101 ) && ! V_50 -> V_86 ) ||
( ( V_71 -> V_98 & V_102 ) && ! V_50 -> V_103 ) ||
( ! ( V_71 -> V_98 & V_104 ) && ( V_50 -> V_56 -> type == V_105 ) ) ) {
V_74 = - V_106 ;
} else {
if ( V_67 & ( V_107 | V_108 ) ) {
if ( V_79 <= sizeof( V_76 ) ) {
V_77 = V_76 ;
} else {
V_77 = F_47 ( V_79 , V_109 ) ;
if ( ! V_77 ) {
V_74 = - V_26 ;
goto V_90;
}
}
if ( V_79 > V_78 )
memset ( V_77 + V_78 , 0 , V_79 - V_78 ) ;
}
if ( V_67 & V_107 ) {
if ( F_48 ( V_77 , ( void V_110 * ) V_68 ,
V_78 ) != 0 ) {
V_74 = - V_47 ;
goto V_90;
}
} else
memset ( V_77 , 0 , V_78 ) ;
if ( V_71 -> V_98 & V_111 )
V_74 = V_72 ( V_2 , V_77 , V_50 ) ;
else {
F_5 ( & V_112 ) ;
V_74 = V_72 ( V_2 , V_77 , V_50 ) ;
F_16 ( & V_112 ) ;
}
if ( V_67 & V_108 ) {
if ( F_37 ( ( void V_110 * ) V_68 , V_77 ,
V_78 ) != 0 )
V_74 = - V_47 ;
}
}
V_90:
if ( V_77 != V_76 )
F_10 ( V_77 ) ;
F_49 ( & V_2 -> V_81 ) ;
if ( V_74 )
F_2 ( L_12 , V_74 ) ;
return V_74 ;
}
struct V_113 * F_50 ( struct V_1 * V_2 )
{
struct V_114 * V_13 ;
F_51 (entry, &dev->maplist, head) {
if ( V_13 -> V_115 && V_13 -> V_115 -> type == V_116 &&
( V_13 -> V_115 -> V_98 & V_117 ) ) {
return V_13 -> V_115 ;
}
}
return NULL ;
}
