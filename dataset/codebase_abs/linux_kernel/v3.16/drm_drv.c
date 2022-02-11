static int T_1 F_1 ( void )
{
int V_1 = - V_2 ;
F_2 () ;
F_3 () ;
F_4 ( & V_3 ) ;
if ( F_5 ( V_4 , L_1 , & V_5 ) )
goto V_6;
V_7 = F_6 ( V_8 , L_1 ) ;
if ( F_7 ( V_7 ) ) {
F_8 ( V_9 L_2 ) ;
V_1 = F_9 ( V_7 ) ;
goto V_10;
}
V_11 = F_10 ( L_3 , NULL ) ;
if ( ! V_11 ) {
F_11 ( L_4 ) ;
V_1 = - 1 ;
goto V_12;
}
F_12 ( L_5 ,
V_13 , V_14 , V_15 , V_16 , V_17 ) ;
return 0 ;
V_12:
F_13 () ;
V_10:
F_14 ( V_4 , L_1 ) ;
F_15 ( & V_3 ) ;
V_6:
return V_1 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_11 ) ;
F_13 () ;
F_14 ( V_4 , L_1 ) ;
F_18 () ;
F_15 ( & V_3 ) ;
}
static int F_19 ( char * V_18 , T_3 * V_19 , const char * V_20 )
{
int V_21 ;
V_21 = strlen ( V_20 ) ;
if ( V_21 > * V_19 )
V_21 = * V_19 ;
* V_19 = strlen ( V_20 ) ;
if ( V_21 && V_18 )
if ( F_20 ( V_18 , V_20 , V_21 ) )
return - V_22 ;
return 0 ;
}
static int F_21 ( struct V_23 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct F_21 * V_28 = V_25 ;
int V_29 ;
V_28 -> V_30 = V_24 -> V_31 -> V_32 ;
V_28 -> V_33 = V_24 -> V_31 -> V_34 ;
V_28 -> V_35 = V_24 -> V_31 -> V_36 ;
V_29 = F_19 ( V_28 -> V_37 , & V_28 -> V_38 ,
V_24 -> V_31 -> V_37 ) ;
if ( ! V_29 )
V_29 = F_19 ( V_28 -> V_39 , & V_28 -> V_40 ,
V_24 -> V_31 -> V_39 ) ;
if ( ! V_29 )
V_29 = F_19 ( V_28 -> V_41 , & V_28 -> V_42 ,
V_24 -> V_31 -> V_41 ) ;
return V_29 ;
}
static int F_22 ( T_4 V_43 , struct V_26 * V_27 )
{
if ( F_23 ( ( V_43 & V_44 ) && ! F_24 ( V_45 ) ) )
return - V_46 ;
if ( F_23 ( ( V_43 & V_47 ) && ! F_25 ( V_27 ) &&
! V_27 -> V_48 ) )
return - V_46 ;
if ( F_23 ( ( V_43 & V_49 ) && ! V_27 -> V_50 &&
! F_26 ( V_27 ) ) )
return - V_46 ;
if ( F_23 ( ! ( V_43 & V_51 ) &&
F_26 ( V_27 ) ) )
return - V_46 ;
if ( F_23 ( ! ( V_43 & V_52 ) &&
F_25 ( V_27 ) ) )
return - V_46 ;
return 0 ;
}
long F_27 ( struct V_53 * V_54 ,
unsigned int V_55 , unsigned long V_56 )
{
struct V_26 * V_27 = V_54 -> V_57 ;
struct V_23 * V_24 ;
const struct V_58 * V_59 = NULL ;
T_5 * V_60 ;
unsigned int V_61 = F_28 ( V_55 ) ;
int V_62 = - V_63 ;
char V_64 [ 128 ] ;
char * V_65 = NULL ;
unsigned int V_66 , V_67 ;
V_24 = V_27 -> V_34 -> V_24 ;
if ( F_29 ( V_24 ) )
return - V_68 ;
if ( ( V_61 >= V_69 ) &&
( ( V_61 < V_70 ) || ( V_61 >= V_71 ) ) )
goto V_72;
if ( ( V_61 >= V_70 ) && ( V_61 < V_71 ) &&
( V_61 < V_70 + V_24 -> V_31 -> V_73 ) ) {
T_4 V_74 ;
V_59 = & V_24 -> V_31 -> V_75 [ V_61 - V_70 ] ;
V_74 = F_30 ( V_59 -> V_76 ) ;
V_66 = V_67 = F_30 ( V_55 ) ;
if ( V_74 > V_67 )
V_67 = V_74 ;
V_55 = V_59 -> V_76 ;
}
else if ( ( V_61 >= V_71 ) || ( V_61 < V_70 ) ) {
T_4 V_74 ;
V_59 = & V_77 [ V_61 ] ;
V_74 = F_30 ( V_59 -> V_55 ) ;
V_66 = V_67 = F_30 ( V_55 ) ;
if ( V_74 > V_67 )
V_67 = V_74 ;
V_55 = V_59 -> V_55 ;
} else
goto V_72;
F_31 ( L_6 ,
F_32 ( V_78 ) ,
( long ) F_33 ( V_27 -> V_34 -> V_79 -> V_80 ) ,
V_27 -> V_48 , V_59 -> V_37 ) ;
V_60 = V_59 -> V_60 ;
if ( F_23 ( ! V_60 ) ) {
F_31 ( L_7 ) ;
V_62 = - V_63 ;
goto V_72;
}
V_62 = F_22 ( V_59 -> V_43 , V_27 ) ;
if ( F_23 ( V_62 ) )
goto V_72;
if ( V_55 & ( V_81 | V_82 ) ) {
if ( V_67 <= sizeof( V_64 ) ) {
V_65 = V_64 ;
} else {
V_65 = F_34 ( V_67 , V_83 ) ;
if ( ! V_65 ) {
V_62 = - V_2 ;
goto V_72;
}
}
if ( V_67 > V_66 )
memset ( V_65 + V_66 , 0 , V_67 - V_66 ) ;
}
if ( V_55 & V_81 ) {
if ( F_35 ( V_65 , ( void V_84 * ) V_56 ,
V_66 ) != 0 ) {
V_62 = - V_22 ;
goto V_72;
}
} else if ( V_55 & V_82 ) {
memset ( V_65 , 0 , V_66 ) ;
}
if ( V_59 -> V_43 & V_85 )
V_62 = V_60 ( V_24 , V_65 , V_27 ) ;
else {
F_36 ( & V_86 ) ;
V_62 = V_60 ( V_24 , V_65 , V_27 ) ;
F_37 ( & V_86 ) ;
}
if ( V_55 & V_82 ) {
if ( F_20 ( ( void V_84 * ) V_56 , V_65 ,
V_66 ) != 0 )
V_62 = - V_22 ;
}
V_72:
if ( ! V_59 )
F_31 ( L_8 ,
F_32 ( V_78 ) ,
( long ) F_33 ( V_27 -> V_34 -> V_79 -> V_80 ) ,
V_27 -> V_48 , V_55 , V_61 ) ;
if ( V_65 != V_64 )
F_38 ( V_65 ) ;
if ( V_62 )
F_31 ( L_9 , V_62 ) ;
return V_62 ;
}
bool F_39 ( unsigned int V_61 , unsigned int * V_43 )
{
if ( ( V_61 >= V_71 && V_61 < V_69 ) ||
( V_61 < V_70 ) ) {
* V_43 = V_77 [ V_61 ] . V_43 ;
return true ;
}
return false ;
}
