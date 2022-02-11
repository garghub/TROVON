static struct V_1 * F_1 ( void )
{
if ( ! V_2 ) {
struct V_1 * V_1 = F_2 ( V_3 | V_4 ) ;
if ( V_1 )
V_2 = V_1 ;
}
return V_2 ;
}
static T_1
F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
char T_2 * V_11 ,
T_3 V_12 ,
T_4 * V_13 )
{
struct V_14 * V_14 = V_6 -> V_15 ;
T_5 V_16 , V_17 ;
unsigned long V_18 ;
T_4 V_19 , V_20 ;
T_3 V_21 = 0 , error = 0 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
V_20 = * V_13 ;
V_16 = V_20 >> V_24 ;
V_18 = V_20 & ~ V_25 ;
V_19 = F_5 ( V_14 ) ;
if ( ! V_19 )
goto V_26;
V_17 = ( V_19 - 1 ) >> V_24 ;
do {
unsigned long V_27 , V_28 ;
void * V_29 ;
unsigned long V_30 ;
int V_31 = 0 ;
V_27 = V_32 ;
if ( V_16 >= V_17 ) {
if ( V_16 > V_17 )
goto V_26;
V_27 = ( ( V_19 - 1 ) & ~ V_25 ) + 1 ;
if ( V_27 <= V_18 ) {
goto V_26;
}
}
V_27 = V_27 - V_18 ;
if ( V_27 > V_12 - V_21 )
V_27 = V_12 - V_21 ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( error ) ) {
if ( error == - V_33 ) {
V_31 = 1 ;
} else
goto V_26;
}
if ( F_7 ( V_6 ) )
;
if ( ! V_31 )
V_28 = F_8 ( V_11 + V_21 , V_29 + V_18 , V_27 ) ;
else
V_28 = F_9 ( V_11 + V_21 , V_27 ) ;
if ( V_28 ) {
error = - V_34 ;
goto V_26;
}
V_21 += ( V_27 - V_28 ) ;
V_18 += ( V_27 - V_28 ) ;
V_16 += V_18 >> V_24 ;
V_18 &= ~ V_25 ;
} while ( V_21 < V_12 );
V_26:
* V_13 = V_20 + V_21 ;
if ( V_10 )
F_10 ( V_10 ) ;
return ( V_21 ? V_21 : error ) ;
}
T_1
F_11 ( struct V_9 * V_10 , char T_2 * V_11 , T_3 V_12 , T_4 * V_13 )
{
if ( ! F_12 ( V_35 , V_11 , V_12 ) )
return - V_34 ;
return F_3 ( V_10 -> V_36 , & V_10 -> V_37 , V_10 ,
V_11 , V_12 , V_13 ) ;
}
static void F_13 ( struct V_5 * V_6 , unsigned long V_38 )
{
struct V_39 * V_40 ;
struct V_1 * V_1 ;
unsigned V_41 ;
int V_42 = 0 ;
V_41 = F_14 ( & V_43 ) ;
V_1 = V_2 ;
if ( ! V_1 )
return;
V_44:
F_15 ( V_6 ) ;
F_16 (vma, &mapping->i_mmap, pgoff, pgoff) {
T_6 * V_45 , V_46 ;
T_7 * V_47 ;
struct V_48 * V_49 = V_40 -> V_50 ;
unsigned long V_51 = V_40 -> V_52 +
( ( V_38 - V_40 -> V_53 ) << V_54 ) ;
F_4 ( V_51 < V_40 -> V_52 || V_51 >= V_40 -> V_55 ) ;
V_45 = F_17 ( V_1 , V_49 , V_51 , & V_47 , 1 ) ;
if ( V_45 ) {
F_18 ( V_40 , V_51 , F_19 ( * V_45 ) ) ;
V_46 = F_20 ( V_40 , V_51 , V_45 ) ;
F_21 ( V_1 ) ;
F_22 ( V_49 , V_56 ) ;
F_4 ( F_23 ( V_46 ) ) ;
F_24 ( V_45 , V_47 ) ;
F_25 ( V_49 , V_51 ) ;
F_26 ( V_1 ) ;
}
}
F_27 ( V_6 ) ;
if ( V_42 ) {
F_28 ( & V_57 ) ;
} else if ( F_29 ( & V_43 , V_41 ) ) {
F_30 ( & V_57 ) ;
V_42 = 1 ;
goto V_44;
}
}
static int F_31 ( struct V_39 * V_40 , struct V_58 * V_59 )
{
struct V_9 * V_9 = V_40 -> V_60 ;
struct V_5 * V_6 = V_9 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_5 V_61 ;
void * V_29 ;
unsigned long V_30 ;
struct V_1 * V_1 ;
int error ;
V_62:
V_61 = ( F_5 ( V_14 ) + V_32 - 1 ) >> V_24 ;
if ( V_59 -> V_38 >= V_61 )
return V_63 ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_59 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_32 ( ! error ) )
goto V_64;
if ( error != - V_33 )
return V_65 ;
if ( ( V_40 -> V_66 & ( V_67 | V_68 ) ) &&
( V_40 -> V_66 & ( V_69 | V_70 ) ) &&
( ! ( V_6 -> V_15 -> V_71 -> V_72 & V_73 ) ) ) {
int V_74 ;
F_30 ( & V_57 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_59 -> V_38 , 1 ,
& V_29 , & V_30 ) ;
F_28 ( & V_57 ) ;
if ( error )
return V_63 ;
F_13 ( V_6 , V_59 -> V_38 ) ;
V_64:
V_74 = F_33 ( V_40 , ( unsigned long ) V_59 -> V_75 ,
V_30 ) ;
if ( V_74 == - V_76 )
return V_65 ;
if ( V_74 != - V_77 )
F_4 ( V_74 ) ;
return V_78 ;
} else {
int V_74 , V_79 = V_65 ;
F_30 ( & V_57 ) ;
F_34 ( & V_43 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_59 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( ! error ) ) {
F_35 ( & V_43 ) ;
F_28 ( & V_57 ) ;
goto V_62;
}
if ( error != - V_33 )
goto V_26;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_26;
V_74 = F_36 ( V_40 , ( unsigned long ) V_59 -> V_75 ,
V_1 ) ;
if ( V_74 == - V_76 )
goto V_26;
V_79 = V_78 ;
V_26:
F_35 ( & V_43 ) ;
F_28 ( & V_57 ) ;
return V_79 ;
}
}
int F_37 ( struct V_9 * V_9 , struct V_39 * V_40 )
{
F_4 ( ! V_9 -> V_36 -> V_22 -> V_23 ) ;
F_10 ( V_9 ) ;
V_40 -> V_80 = & V_81 ;
V_40 -> V_66 |= V_82 ;
return 0 ;
}
static T_1
F_38 ( struct V_9 * V_10 , const char T_2 * V_11 ,
T_3 V_41 , T_4 V_20 , T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
const struct V_83 * V_22 = V_6 -> V_22 ;
struct V_14 * V_14 = V_6 -> V_15 ;
long V_84 = 0 ;
T_3 V_85 ;
T_1 V_86 = 0 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
do {
unsigned long V_16 ;
unsigned long V_18 ;
T_3 V_21 ;
void * V_29 ;
unsigned long V_30 ;
V_18 = ( V_20 & ( V_32 - 1 ) ) ;
V_16 = V_20 >> V_24 ;
V_85 = V_32 - V_18 ;
if ( V_85 > V_41 )
V_85 = V_41 ;
V_84 = V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( V_84 == - V_33 ) {
F_30 ( & V_57 ) ;
V_84 = V_22 -> V_23 ( V_6 , V_16 , 1 ,
& V_29 , & V_30 ) ;
F_28 ( & V_57 ) ;
if ( ! V_84 )
F_13 ( V_6 , V_16 ) ;
}
if ( V_84 )
break;
V_21 = V_85 -
F_39 ( V_29 + V_18 , V_11 , V_85 ) ;
if ( F_32 ( V_21 > 0 ) ) {
V_84 = V_21 ;
if ( V_84 >= 0 ) {
V_86 += V_84 ;
V_41 -= V_84 ;
V_20 += V_84 ;
V_11 += V_84 ;
}
}
if ( F_6 ( V_21 != V_85 ) )
if ( V_84 >= 0 )
V_84 = - V_34 ;
if ( V_84 < 0 )
break;
} while ( V_41 );
* V_13 = V_20 ;
if ( V_20 > V_14 -> V_87 ) {
F_40 ( V_14 , V_20 ) ;
F_41 ( V_14 ) ;
}
return V_86 ? V_86 : V_84 ;
}
T_1
F_42 ( struct V_9 * V_10 , const char T_2 * V_11 , T_3 V_12 ,
T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_3 V_41 ;
T_4 V_20 ;
T_1 V_79 ;
F_30 ( & V_14 -> V_88 ) ;
if ( ! F_12 ( V_89 , V_11 , V_12 ) ) {
V_79 = - V_34 ;
goto V_90;
}
V_20 = * V_13 ;
V_41 = V_12 ;
V_91 -> V_92 = V_6 -> V_92 ;
V_79 = F_43 ( V_10 , & V_20 , & V_41 , F_44 ( V_14 -> V_93 ) ) ;
if ( V_79 )
goto V_94;
if ( V_41 == 0 )
goto V_94;
V_79 = F_45 ( V_10 ) ;
if ( V_79 )
goto V_94;
V_79 = F_46 ( V_10 ) ;
if ( V_79 )
goto V_94;
V_79 = F_38 ( V_10 , V_11 , V_41 , V_20 , V_13 ) ;
V_94:
V_91 -> V_92 = NULL ;
V_90:
F_28 ( & V_14 -> V_88 ) ;
return V_79 ;
}
int
F_47 ( struct V_5 * V_6 , T_4 V_95 )
{
T_5 V_16 = V_95 >> V_24 ;
unsigned V_18 = V_95 & ( V_32 - 1 ) ;
unsigned V_96 ;
unsigned V_97 ;
void * V_29 ;
unsigned long V_30 ;
int V_74 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
V_96 = 1 << V_6 -> V_15 -> V_98 ;
V_97 = V_18 & ( V_96 - 1 ) ;
if ( ! V_97 )
return 0 ;
V_97 = V_96 - V_97 ;
V_74 = V_6 -> V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( V_74 ) ) {
if ( V_74 == - V_33 )
return 0 ;
else
return V_74 ;
}
memset ( V_29 + V_18 , 0 , V_97 ) ;
return 0 ;
}
