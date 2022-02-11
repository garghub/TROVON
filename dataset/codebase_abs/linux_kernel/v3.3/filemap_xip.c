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
static void
F_13 ( struct V_5 * V_6 ,
unsigned long V_38 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 ;
unsigned long V_45 ;
T_6 * V_46 ;
T_6 V_47 ;
T_7 * V_48 ;
struct V_1 * V_1 ;
unsigned V_49 ;
int V_50 = 0 ;
V_49 = F_14 ( & V_51 ) ;
V_1 = V_2 ;
if ( ! V_1 )
return;
V_52:
F_15 ( & V_6 -> V_53 ) ;
F_16 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
V_42 = V_40 -> V_54 ;
V_45 = V_40 -> V_55 +
( ( V_38 - V_40 -> V_56 ) << V_57 ) ;
F_4 ( V_45 < V_40 -> V_55 || V_45 >= V_40 -> V_58 ) ;
V_46 = F_17 ( V_1 , V_42 , V_45 , & V_48 , 1 ) ;
if ( V_46 ) {
F_18 ( V_40 , V_45 , F_19 ( * V_46 ) ) ;
V_47 = F_20 ( V_40 , V_45 , V_46 ) ;
F_21 ( V_1 ) ;
F_22 ( V_42 , V_59 ) ;
F_4 ( F_23 ( V_47 ) ) ;
F_24 ( V_46 , V_48 ) ;
F_25 ( V_1 ) ;
}
}
F_26 ( & V_6 -> V_53 ) ;
if ( V_50 ) {
F_26 ( & V_60 ) ;
} else if ( F_27 ( & V_51 , V_49 ) ) {
F_15 ( & V_60 ) ;
V_50 = 1 ;
goto V_52;
}
}
static int F_28 ( struct V_39 * V_40 , struct V_61 * V_62 )
{
struct V_9 * V_9 = V_40 -> V_63 ;
struct V_5 * V_6 = V_9 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_5 V_64 ;
void * V_29 ;
unsigned long V_30 ;
struct V_1 * V_1 ;
int error ;
V_65:
V_64 = ( F_5 ( V_14 ) + V_32 - 1 ) >> V_24 ;
if ( V_62 -> V_38 >= V_64 )
return V_66 ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_62 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_29 ( ! error ) )
goto V_67;
if ( error != - V_33 )
return V_68 ;
if ( ( V_40 -> V_69 & ( V_70 | V_71 ) ) &&
( V_40 -> V_69 & ( V_72 | V_73 ) ) &&
( ! ( V_6 -> V_15 -> V_74 -> V_75 & V_76 ) ) ) {
int V_77 ;
F_15 ( & V_60 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_62 -> V_38 , 1 ,
& V_29 , & V_30 ) ;
F_26 ( & V_60 ) ;
if ( error )
return V_66 ;
F_13 ( V_6 , V_62 -> V_38 ) ;
V_67:
V_77 = F_30 ( V_40 , ( unsigned long ) V_62 -> V_78 ,
V_30 ) ;
if ( V_77 == - V_79 )
return V_68 ;
if ( V_77 != - V_80 )
F_4 ( V_77 ) ;
return V_81 ;
} else {
int V_77 , V_82 = V_68 ;
F_15 ( & V_60 ) ;
F_31 ( & V_51 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_62 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( ! error ) ) {
F_32 ( & V_51 ) ;
F_26 ( & V_60 ) ;
goto V_65;
}
if ( error != - V_33 )
goto V_26;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_26;
V_77 = F_33 ( V_40 , ( unsigned long ) V_62 -> V_78 ,
V_1 ) ;
if ( V_77 == - V_79 )
goto V_26;
V_82 = V_81 ;
V_26:
F_32 ( & V_51 ) ;
F_26 ( & V_60 ) ;
return V_82 ;
}
}
int F_34 ( struct V_9 * V_9 , struct V_39 * V_40 )
{
F_4 ( ! V_9 -> V_36 -> V_22 -> V_23 ) ;
F_10 ( V_9 ) ;
V_40 -> V_83 = & V_84 ;
V_40 -> V_69 |= V_85 | V_86 ;
return 0 ;
}
static T_1
F_35 ( struct V_9 * V_10 , const char T_2 * V_11 ,
T_3 V_49 , T_4 V_20 , T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
const struct V_87 * V_22 = V_6 -> V_22 ;
struct V_14 * V_14 = V_6 -> V_15 ;
long V_88 = 0 ;
T_3 V_89 ;
T_1 V_90 = 0 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
do {
unsigned long V_16 ;
unsigned long V_18 ;
T_3 V_21 ;
void * V_29 ;
unsigned long V_30 ;
V_18 = ( V_20 & ( V_32 - 1 ) ) ;
V_16 = V_20 >> V_24 ;
V_89 = V_32 - V_18 ;
if ( V_89 > V_49 )
V_89 = V_49 ;
V_88 = V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( V_88 == - V_33 ) {
F_15 ( & V_60 ) ;
V_88 = V_22 -> V_23 ( V_6 , V_16 , 1 ,
& V_29 , & V_30 ) ;
F_26 ( & V_60 ) ;
if ( ! V_88 )
F_13 ( V_6 , V_16 ) ;
}
if ( V_88 )
break;
V_21 = V_89 -
F_36 ( V_29 + V_18 , V_11 , V_89 ) ;
if ( F_29 ( V_21 > 0 ) ) {
V_88 = V_21 ;
if ( V_88 >= 0 ) {
V_90 += V_88 ;
V_49 -= V_88 ;
V_20 += V_88 ;
V_11 += V_88 ;
}
}
if ( F_6 ( V_21 != V_89 ) )
if ( V_88 >= 0 )
V_88 = - V_34 ;
if ( V_88 < 0 )
break;
} while ( V_49 );
* V_13 = V_20 ;
if ( V_20 > V_14 -> V_91 ) {
F_37 ( V_14 , V_20 ) ;
F_38 ( V_14 ) ;
}
return V_90 ? V_90 : V_88 ;
}
T_1
F_39 ( struct V_9 * V_10 , const char T_2 * V_11 , T_3 V_12 ,
T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_3 V_49 ;
T_4 V_20 ;
T_1 V_82 ;
F_15 ( & V_14 -> V_92 ) ;
if ( ! F_12 ( V_93 , V_11 , V_12 ) ) {
V_82 = - V_34 ;
goto V_94;
}
V_20 = * V_13 ;
V_49 = V_12 ;
F_40 ( V_14 -> V_74 , V_95 ) ;
V_96 -> V_97 = V_6 -> V_97 ;
V_82 = F_41 ( V_10 , & V_20 , & V_49 , F_42 ( V_14 -> V_98 ) ) ;
if ( V_82 )
goto V_99;
if ( V_49 == 0 )
goto V_99;
V_82 = F_43 ( V_10 ) ;
if ( V_82 )
goto V_99;
F_44 ( V_10 ) ;
V_82 = F_35 ( V_10 , V_11 , V_49 , V_20 , V_13 ) ;
V_99:
V_96 -> V_97 = NULL ;
V_94:
F_26 ( & V_14 -> V_92 ) ;
return V_82 ;
}
int
F_45 ( struct V_5 * V_6 , T_4 V_100 )
{
T_5 V_16 = V_100 >> V_24 ;
unsigned V_18 = V_100 & ( V_32 - 1 ) ;
unsigned V_101 ;
unsigned V_102 ;
void * V_29 ;
unsigned long V_30 ;
int V_77 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
V_101 = 1 << V_6 -> V_15 -> V_103 ;
V_102 = V_18 & ( V_101 - 1 ) ;
if ( ! V_102 )
return 0 ;
V_102 = V_101 - V_102 ;
V_77 = V_6 -> V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( V_77 ) ) {
if ( V_77 == - V_33 )
return 0 ;
else
return V_77 ;
}
memset ( V_29 + V_18 , 0 , V_102 ) ;
return 0 ;
}
