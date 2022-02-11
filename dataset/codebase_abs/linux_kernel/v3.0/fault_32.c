static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( F_2 () && ! F_3 ( V_2 ) ) {
F_4 () ;
if ( F_5 () && F_6 ( V_2 , V_3 ) )
V_4 = 1 ;
F_7 () ;
}
return V_4 ;
}
static inline T_1 * F_8 ( T_2 * V_5 , unsigned long V_6 )
{
unsigned V_7 = F_9 ( V_6 ) ;
T_2 * V_8 ;
T_3 * V_9 , * V_10 ;
T_1 * V_11 , * V_12 ;
V_5 += V_7 ;
V_8 = V_13 . V_5 + V_7 ;
if ( ! F_10 ( * V_8 ) )
return NULL ;
V_9 = F_11 ( V_5 , V_6 ) ;
V_10 = F_11 ( V_8 , V_6 ) ;
if ( ! F_12 ( * V_10 ) )
return NULL ;
if ( ! F_12 ( * V_9 ) )
F_13 ( V_9 , * V_10 ) ;
V_11 = F_14 ( V_9 , V_6 ) ;
V_12 = F_14 ( V_10 , V_6 ) ;
if ( ! F_15 ( * V_12 ) )
return NULL ;
if ( ! F_15 ( * V_11 ) )
F_16 ( V_11 , * V_12 ) ;
else {
F_17 ( F_18 ( * V_11 ) != F_18 ( * V_12 ) ) ;
return NULL ;
}
return V_12 ;
}
static T_4 int F_19 ( unsigned long V_6 )
{
T_2 * V_8 ;
T_1 * V_12 ;
T_5 * V_14 ;
if ( ! ( V_6 >= V_15 && V_6 < V_16 ) )
return - 1 ;
V_8 = F_20 () ;
V_12 = F_8 ( V_8 , V_6 ) ;
if ( ! V_12 )
return - 1 ;
V_14 = F_21 ( V_12 , V_6 ) ;
if ( ! F_22 ( * V_14 ) )
return - 1 ;
return 0 ;
}
static int F_23 ( unsigned long V_6 )
{
return V_6 >= V_17 ;
}
T_6 void T_7 F_24 ( struct V_1 * V_2 ,
unsigned long V_18 ,
unsigned long V_6 )
{
unsigned long V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
int V_27 ;
T_8 V_28 ;
V_21 = V_29 ;
V_23 = V_21 -> V_23 ;
V_26 = V_30 ;
V_19 = F_25 () ;
if ( F_26 ( F_23 ( V_6 ) ) ) {
if ( F_19 ( V_6 ) >= 0 )
return;
if ( F_1 ( V_2 , V_19 ) )
return;
goto V_31;
}
if ( F_26 ( F_1 ( V_2 , V_19 ) ) )
return;
if ( ( V_2 -> V_32 & V_33 ) != V_33 )
F_27 () ;
F_28 ( V_34 , 1 , 0 , V_2 , V_6 ) ;
if ( F_29 () || ! V_23 )
goto V_35;
F_30 ( & V_23 -> V_36 ) ;
V_25 = F_31 ( V_23 , V_6 ) ;
if ( ! V_25 )
goto V_37;
if ( V_25 -> V_38 <= V_6 )
goto V_39;
if ( ! ( V_25 -> V_40 & V_41 ) )
goto V_37;
if ( F_32 ( V_25 , V_6 ) )
goto V_37;
V_39:
V_26 = V_42 ;
if ( V_18 ) {
if ( ! ( V_25 -> V_40 & V_43 ) )
goto V_37;
} else {
if ( ! ( V_25 -> V_40 & ( V_44 | V_45 | V_43 ) ) )
goto V_37;
}
V_27 = F_33 ( V_23 , V_25 , V_6 , V_18 ? V_46 : 0 ) ;
if ( F_26 ( V_27 & V_47 ) ) {
if ( V_27 & V_48 )
goto V_49;
else if ( V_27 & V_50 )
goto V_51;
F_34 () ;
}
if ( V_27 & V_52 ) {
V_21 -> V_53 ++ ;
F_28 ( V_54 , 1 , 0 ,
V_2 , V_6 ) ;
} else {
V_21 -> V_55 ++ ;
F_28 ( V_56 , 1 , 0 ,
V_2 , V_6 ) ;
}
F_35 ( & V_23 -> V_36 ) ;
return;
V_37:
F_35 ( & V_23 -> V_36 ) ;
V_31:
if ( F_3 ( V_2 ) ) {
V_28 . V_57 = V_58 ;
V_28 . V_59 = 0 ;
V_28 . V_26 = V_26 ;
V_28 . V_60 = ( void * ) V_6 ;
F_36 ( V_58 , & V_28 , V_21 ) ;
return;
}
V_35:
if ( F_37 ( V_2 ) )
return;
if ( F_38 ( V_2 , V_6 ) )
return;
F_39 ( 1 ) ;
if ( F_40 () ) {
unsigned long V_61 ;
if ( V_6 < V_62 )
F_41 ( V_63 L_1
L_2 ) ;
else
F_41 ( V_63 L_3
L_4 ) ;
F_41 ( L_5 , V_6 ) ;
F_41 ( V_63 L_6 , V_2 -> V_64 ) ;
V_61 = ( unsigned long ) F_20 () ;
if ( V_61 ) {
V_61 = ( ( F_42 ( V_61 ) * ) V_61 ) [ V_6 >> V_65 ] ;
F_41 ( V_63 L_7 , V_61 ) ;
if ( V_61 & V_66 ) {
V_61 &= V_67 ;
V_6 &= 0x003ff000 ;
V_61 = ( ( F_42 ( V_61 ) * )
F_43 ( V_61 ) ) [ V_6 >>
V_68 ] ;
F_41 ( V_63 L_8 , V_61 ) ;
}
}
}
F_44 ( L_9 , V_2 , V_18 ) ;
F_39 ( 0 ) ;
F_45 ( V_69 ) ;
V_49:
F_35 ( & V_23 -> V_36 ) ;
if ( ! F_3 ( V_2 ) )
goto V_35;
F_46 () ;
return;
V_51:
F_35 ( & V_23 -> V_36 ) ;
V_28 . V_57 = V_70 ;
V_28 . V_59 = 0 ;
V_28 . V_26 = V_71 ;
V_28 . V_60 = ( void * ) V_6 ;
F_36 ( V_70 , & V_28 , V_21 ) ;
if ( ! F_3 ( V_2 ) )
goto V_35;
}
T_6 int T_7
F_47 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long V_6 )
{
T_2 * V_5 ;
T_3 * V_9 ;
T_1 * V_11 ;
T_5 * V_72 ;
T_5 V_73 ;
if ( V_6 >= V_74 && V_6 < V_16 ) {
V_5 = F_48 ( V_6 ) ;
} else {
if ( F_26 ( V_6 >= V_17 || ! V_29 -> V_23 ) )
return 1 ;
V_5 = F_49 ( V_29 -> V_23 , V_6 ) ;
}
V_9 = F_11 ( V_5 , V_6 ) ;
if ( F_50 ( V_9 ) )
return 1 ;
V_11 = F_14 ( V_9 , V_6 ) ;
if ( F_51 ( V_11 ) )
return 1 ;
V_72 = F_21 ( V_11 , V_6 ) ;
V_73 = * V_72 ;
if ( F_26 ( F_52 ( V_73 ) || F_53 ( V_73 ) ) )
return 1 ;
if ( F_26 ( V_18 && ! F_54 ( V_73 ) ) )
return 1 ;
if ( V_18 )
V_73 = F_55 ( V_73 ) ;
V_73 = F_56 ( V_73 ) ;
F_57 ( V_72 , V_73 ) ;
#if F_58 ( V_75 ) && ! F_58 ( V_76 )
if ( V_18 == 2 )
F_59 ( F_60 () , V_6 & V_67 ) ;
#endif
F_61 ( NULL , V_6 , V_72 ) ;
return 0 ;
}
