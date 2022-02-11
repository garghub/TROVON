static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 , V_4 ) )
return;
F_3 ( & V_2 -> V_5 , 0 ) ;
F_3 ( & V_2 -> V_6 , 0 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_2 -> V_7 ) ; V_3 ++ )
F_3 ( & V_2 -> V_7 [ V_3 ] , 0 ) ;
V_2 -> V_8 . V_9 = NULL ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_15 ;
F_6 ( L_1 ) ;
if ( V_2 -> V_16 -> V_17 )
V_2 -> V_16 -> V_17 ( V_2 ) ;
F_6 ( L_2 ) ;
if ( V_2 -> V_18 && ! F_2 ( V_2 , V_4 ) )
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 (vma, vma_temp, &dev->vmalist, head) {
F_12 ( & V_14 -> V_20 ) ;
F_13 ( V_14 ) ;
}
F_14 ( V_2 ) ;
V_2 -> V_21 = NULL ;
F_15 ( & V_2 -> V_19 ) ;
F_1 ( V_2 ) ;
F_6 ( L_3 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_22 = - V_23 ;
F_17 () ;
F_18 () ;
F_19 ( & V_24 ) ;
if ( F_20 ( V_25 , L_4 , & V_26 ) )
goto V_27;
V_28 = F_21 ( V_29 , L_4 ) ;
if ( F_22 ( V_28 ) ) {
F_23 ( V_30 L_5 ) ;
V_22 = F_24 ( V_28 ) ;
goto V_31;
}
V_32 = F_25 ( L_6 , NULL ) ;
if ( ! V_32 ) {
F_26 ( L_7 ) ;
V_22 = - 1 ;
goto V_33;
}
F_27 ( L_8 ,
V_34 , V_35 , V_36 , V_37 , V_38 ) ;
return 0 ;
V_33:
F_28 () ;
V_31:
F_29 ( V_25 , L_4 ) ;
F_30 ( & V_24 ) ;
V_27:
return V_22 ;
}
static void T_2 F_31 ( void )
{
F_32 ( V_32 ) ;
F_28 () ;
F_29 ( V_25 , L_4 ) ;
F_33 () ;
F_30 ( & V_24 ) ;
}
static int F_34 ( char * V_39 , T_3 * V_40 , const char * V_41 )
{
int V_42 ;
V_42 = strlen ( V_41 ) ;
if ( V_42 > * V_40 )
V_42 = * V_40 ;
* V_40 = strlen ( V_41 ) ;
if ( V_42 && V_39 )
if ( F_35 ( V_39 , V_41 , V_42 ) )
return - V_43 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_44 ,
struct V_45 * V_46 )
{
struct F_36 * V_47 = V_44 ;
int V_48 ;
V_47 -> V_49 = V_2 -> V_16 -> V_50 ;
V_47 -> V_51 = V_2 -> V_16 -> V_52 ;
V_47 -> V_53 = V_2 -> V_16 -> V_54 ;
V_48 = F_34 ( V_47 -> V_55 , & V_47 -> V_56 ,
V_2 -> V_16 -> V_55 ) ;
if ( ! V_48 )
V_48 = F_34 ( V_47 -> V_57 , & V_47 -> V_58 ,
V_2 -> V_16 -> V_57 ) ;
if ( ! V_48 )
V_48 = F_34 ( V_47 -> V_59 , & V_47 -> V_60 ,
V_2 -> V_16 -> V_59 ) ;
return V_48 ;
}
long F_37 ( struct V_61 * V_62 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_45 * V_46 = V_62 -> V_65 ;
struct V_1 * V_2 ;
const struct V_66 * V_67 = NULL ;
T_4 * V_68 ;
unsigned int V_69 = F_38 ( V_63 ) ;
int V_70 = - V_71 ;
char V_72 [ 128 ] ;
char * V_73 = NULL ;
unsigned int V_74 , V_75 ;
V_2 = V_46 -> V_52 -> V_2 ;
if ( F_39 ( V_2 ) )
return - V_76 ;
F_40 ( & V_2 -> V_5 ) ;
F_40 ( & V_2 -> V_7 [ V_77 ] ) ;
++ V_46 -> V_5 ;
if ( ( V_69 >= V_78 ) &&
( ( V_69 < V_79 ) || ( V_69 >= V_80 ) ) )
goto V_81;
if ( ( V_69 >= V_79 ) && ( V_69 < V_80 ) &&
( V_69 < V_79 + V_2 -> V_16 -> V_82 ) ) {
T_5 V_83 ;
V_67 = & V_2 -> V_16 -> V_84 [ V_69 - V_79 ] ;
V_83 = F_41 ( V_67 -> V_85 ) ;
V_74 = V_75 = F_41 ( V_63 ) ;
if ( V_83 > V_75 )
V_75 = V_83 ;
V_63 = V_67 -> V_85 ;
}
else if ( ( V_69 >= V_80 ) || ( V_69 < V_79 ) ) {
T_5 V_83 ;
V_67 = & V_86 [ V_69 ] ;
V_83 = F_41 ( V_67 -> V_63 ) ;
V_74 = V_75 = F_41 ( V_63 ) ;
if ( V_83 > V_75 )
V_75 = V_83 ;
V_63 = V_67 -> V_63 ;
} else
goto V_81;
F_6 ( L_9 ,
F_42 ( V_87 ) ,
( long ) F_43 ( V_46 -> V_52 -> V_88 ) ,
V_46 -> V_89 , V_67 -> V_55 ) ;
V_68 = V_67 -> V_68 ;
if ( ! V_68 ) {
F_6 ( L_10 ) ;
V_70 = - V_71 ;
} else if ( ( ( V_67 -> V_90 & V_91 ) && ! F_44 ( V_92 ) ) ||
( ( V_67 -> V_90 & V_93 ) && ! F_45 ( V_46 ) && ! V_46 -> V_89 ) ||
( ( V_67 -> V_90 & V_94 ) && ! V_46 -> V_95 ) ||
( ! ( V_67 -> V_90 & V_96 ) && ( V_46 -> V_52 -> type == V_97 ) ) ||
( ! ( V_67 -> V_90 & V_98 ) && F_45 ( V_46 ) ) ) {
V_70 = - V_99 ;
} else {
if ( V_63 & ( V_100 | V_101 ) ) {
if ( V_75 <= sizeof( V_72 ) ) {
V_73 = V_72 ;
} else {
V_73 = F_46 ( V_75 , V_102 ) ;
if ( ! V_73 ) {
V_70 = - V_23 ;
goto V_81;
}
}
if ( V_75 > V_74 )
memset ( V_73 + V_74 , 0 , V_75 - V_74 ) ;
}
if ( V_63 & V_100 ) {
if ( F_47 ( V_73 , ( void V_103 * ) V_64 ,
V_74 ) != 0 ) {
V_70 = - V_43 ;
goto V_81;
}
} else
memset ( V_73 , 0 , V_74 ) ;
if ( V_67 -> V_90 & V_104 )
V_70 = V_68 ( V_2 , V_73 , V_46 ) ;
else {
F_8 ( & V_105 ) ;
V_70 = V_68 ( V_2 , V_73 , V_46 ) ;
F_15 ( & V_105 ) ;
}
if ( V_63 & V_101 ) {
if ( F_35 ( ( void V_103 * ) V_64 , V_73 ,
V_74 ) != 0 )
V_70 = - V_43 ;
}
}
V_81:
if ( ! V_67 )
F_6 ( L_11 ,
F_42 ( V_87 ) ,
( long ) F_43 ( V_46 -> V_52 -> V_88 ) ,
V_46 -> V_89 , V_63 , V_69 ) ;
if ( V_73 != V_72 )
F_13 ( V_73 ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( V_70 )
F_6 ( L_12 , V_70 ) ;
return V_70 ;
}
