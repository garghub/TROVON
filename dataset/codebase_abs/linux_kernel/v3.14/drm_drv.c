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
long F_22 ( struct V_43 * V_44 ,
unsigned int V_45 , unsigned long V_46 )
{
struct V_26 * V_27 = V_44 -> V_47 ;
struct V_23 * V_24 ;
const struct V_48 * V_49 = NULL ;
T_4 * V_50 ;
unsigned int V_51 = F_23 ( V_45 ) ;
int V_52 = - V_53 ;
char V_54 [ 128 ] ;
char * V_55 = NULL ;
unsigned int V_56 , V_57 ;
V_24 = V_27 -> V_34 -> V_24 ;
if ( F_24 ( V_24 ) )
return - V_58 ;
if ( ( V_51 >= V_59 ) &&
( ( V_51 < V_60 ) || ( V_51 >= V_61 ) ) )
goto V_62;
if ( ( V_51 >= V_60 ) && ( V_51 < V_61 ) &&
( V_51 < V_60 + V_24 -> V_31 -> V_63 ) ) {
T_5 V_64 ;
V_49 = & V_24 -> V_31 -> V_65 [ V_51 - V_60 ] ;
V_64 = F_25 ( V_49 -> V_66 ) ;
V_56 = V_57 = F_25 ( V_45 ) ;
if ( V_64 > V_57 )
V_57 = V_64 ;
V_45 = V_49 -> V_66 ;
}
else if ( ( V_51 >= V_61 ) || ( V_51 < V_60 ) ) {
T_5 V_64 ;
V_49 = & V_67 [ V_51 ] ;
V_64 = F_25 ( V_49 -> V_45 ) ;
V_56 = V_57 = F_25 ( V_45 ) ;
if ( V_64 > V_57 )
V_57 = V_64 ;
V_45 = V_49 -> V_45 ;
} else
goto V_62;
F_26 ( L_6 ,
F_27 ( V_68 ) ,
( long ) F_28 ( V_27 -> V_34 -> V_69 ) ,
V_27 -> V_70 , V_49 -> V_37 ) ;
V_50 = V_49 -> V_50 ;
if ( ! V_50 ) {
F_26 ( L_7 ) ;
V_52 = - V_53 ;
} else if ( ( ( V_49 -> V_71 & V_72 ) && ! F_29 ( V_73 ) ) ||
( ( V_49 -> V_71 & V_74 ) && ! F_30 ( V_27 ) && ! V_27 -> V_70 ) ||
( ( V_49 -> V_71 & V_75 ) && ! V_27 -> V_76 ) ||
( ! ( V_49 -> V_71 & V_77 ) && ( V_27 -> V_34 -> type == V_78 ) ) ||
( ! ( V_49 -> V_71 & V_79 ) && F_30 ( V_27 ) ) ) {
V_52 = - V_80 ;
} else {
if ( V_45 & ( V_81 | V_82 ) ) {
if ( V_57 <= sizeof( V_54 ) ) {
V_55 = V_54 ;
} else {
V_55 = F_31 ( V_57 , V_83 ) ;
if ( ! V_55 ) {
V_52 = - V_2 ;
goto V_62;
}
}
if ( V_57 > V_56 )
memset ( V_55 + V_56 , 0 , V_57 - V_56 ) ;
}
if ( V_45 & V_81 ) {
if ( F_32 ( V_55 , ( void V_84 * ) V_46 ,
V_56 ) != 0 ) {
V_52 = - V_22 ;
goto V_62;
}
} else
memset ( V_55 , 0 , V_56 ) ;
if ( V_49 -> V_71 & V_85 )
V_52 = V_50 ( V_24 , V_55 , V_27 ) ;
else {
F_33 ( & V_86 ) ;
V_52 = V_50 ( V_24 , V_55 , V_27 ) ;
F_34 ( & V_86 ) ;
}
if ( V_45 & V_82 ) {
if ( F_20 ( ( void V_84 * ) V_46 , V_55 ,
V_56 ) != 0 )
V_52 = - V_22 ;
}
}
V_62:
if ( ! V_49 )
F_26 ( L_8 ,
F_27 ( V_68 ) ,
( long ) F_28 ( V_27 -> V_34 -> V_69 ) ,
V_27 -> V_70 , V_45 , V_51 ) ;
if ( V_55 != V_54 )
F_35 ( V_55 ) ;
if ( V_52 )
F_26 ( L_9 , V_52 ) ;
return V_52 ;
}
