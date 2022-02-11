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
unsigned long V_43 ;
T_6 * V_44 ;
T_6 V_45 ;
T_7 * V_46 ;
struct V_1 * V_1 ;
unsigned V_47 ;
int V_48 = 0 ;
V_47 = F_14 ( & V_49 ) ;
V_1 = V_2 ;
if ( ! V_1 )
return;
V_50:
F_15 ( & V_6 -> V_51 ) ;
F_16 (vma, &mapping->i_mmap, pgoff, pgoff) {
V_42 = V_40 -> V_52 ;
V_43 = V_40 -> V_53 +
( ( V_38 - V_40 -> V_54 ) << V_55 ) ;
F_4 ( V_43 < V_40 -> V_53 || V_43 >= V_40 -> V_56 ) ;
V_44 = F_17 ( V_1 , V_42 , V_43 , & V_46 , 1 ) ;
if ( V_44 ) {
F_18 ( V_40 , V_43 , F_19 ( * V_44 ) ) ;
V_45 = F_20 ( V_40 , V_43 , V_44 ) ;
F_21 ( V_1 ) ;
F_22 ( V_42 , V_57 ) ;
F_4 ( F_23 ( V_45 ) ) ;
F_24 ( V_44 , V_46 ) ;
F_25 ( V_42 , V_43 ) ;
F_26 ( V_1 ) ;
}
}
F_27 ( & V_6 -> V_51 ) ;
if ( V_48 ) {
F_27 ( & V_58 ) ;
} else if ( F_28 ( & V_49 , V_47 ) ) {
F_15 ( & V_58 ) ;
V_48 = 1 ;
goto V_50;
}
}
static int F_29 ( struct V_39 * V_40 , struct V_59 * V_60 )
{
struct V_9 * V_9 = V_40 -> V_61 ;
struct V_5 * V_6 = V_9 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_5 V_62 ;
void * V_29 ;
unsigned long V_30 ;
struct V_1 * V_1 ;
int error ;
V_63:
V_62 = ( F_5 ( V_14 ) + V_32 - 1 ) >> V_24 ;
if ( V_60 -> V_38 >= V_62 )
return V_64 ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_60 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_30 ( ! error ) )
goto V_65;
if ( error != - V_33 )
return V_66 ;
if ( ( V_40 -> V_67 & ( V_68 | V_69 ) ) &&
( V_40 -> V_67 & ( V_70 | V_71 ) ) &&
( ! ( V_6 -> V_15 -> V_72 -> V_73 & V_74 ) ) ) {
int V_75 ;
F_15 ( & V_58 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_60 -> V_38 , 1 ,
& V_29 , & V_30 ) ;
F_27 ( & V_58 ) ;
if ( error )
return V_64 ;
F_13 ( V_6 , V_60 -> V_38 ) ;
V_65:
V_75 = F_31 ( V_40 , ( unsigned long ) V_60 -> V_76 ,
V_30 ) ;
if ( V_75 == - V_77 )
return V_66 ;
if ( V_75 != - V_78 )
F_4 ( V_75 ) ;
return V_79 ;
} else {
int V_75 , V_80 = V_66 ;
F_15 ( & V_58 ) ;
F_32 ( & V_49 ) ;
error = V_6 -> V_22 -> V_23 ( V_6 , V_60 -> V_38 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( ! error ) ) {
F_33 ( & V_49 ) ;
F_27 ( & V_58 ) ;
goto V_63;
}
if ( error != - V_33 )
goto V_26;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_26;
V_75 = F_34 ( V_40 , ( unsigned long ) V_60 -> V_76 ,
V_1 ) ;
if ( V_75 == - V_77 )
goto V_26;
V_80 = V_79 ;
V_26:
F_33 ( & V_49 ) ;
F_27 ( & V_58 ) ;
return V_80 ;
}
}
int F_35 ( struct V_9 * V_9 , struct V_39 * V_40 )
{
F_4 ( ! V_9 -> V_36 -> V_22 -> V_23 ) ;
F_10 ( V_9 ) ;
V_40 -> V_81 = & V_82 ;
V_40 -> V_67 |= V_83 ;
return 0 ;
}
static T_1
F_36 ( struct V_9 * V_10 , const char T_2 * V_11 ,
T_3 V_47 , T_4 V_20 , T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
const struct V_84 * V_22 = V_6 -> V_22 ;
struct V_14 * V_14 = V_6 -> V_15 ;
long V_85 = 0 ;
T_3 V_86 ;
T_1 V_87 = 0 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
do {
unsigned long V_16 ;
unsigned long V_18 ;
T_3 V_21 ;
void * V_29 ;
unsigned long V_30 ;
V_18 = ( V_20 & ( V_32 - 1 ) ) ;
V_16 = V_20 >> V_24 ;
V_86 = V_32 - V_18 ;
if ( V_86 > V_47 )
V_86 = V_47 ;
V_85 = V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( V_85 == - V_33 ) {
F_15 ( & V_58 ) ;
V_85 = V_22 -> V_23 ( V_6 , V_16 , 1 ,
& V_29 , & V_30 ) ;
F_27 ( & V_58 ) ;
if ( ! V_85 )
F_13 ( V_6 , V_16 ) ;
}
if ( V_85 )
break;
V_21 = V_86 -
F_37 ( V_29 + V_18 , V_11 , V_86 ) ;
if ( F_30 ( V_21 > 0 ) ) {
V_85 = V_21 ;
if ( V_85 >= 0 ) {
V_87 += V_85 ;
V_47 -= V_85 ;
V_20 += V_85 ;
V_11 += V_85 ;
}
}
if ( F_6 ( V_21 != V_86 ) )
if ( V_85 >= 0 )
V_85 = - V_34 ;
if ( V_85 < 0 )
break;
} while ( V_47 );
* V_13 = V_20 ;
if ( V_20 > V_14 -> V_88 ) {
F_38 ( V_14 , V_20 ) ;
F_39 ( V_14 ) ;
}
return V_87 ? V_87 : V_85 ;
}
T_1
F_40 ( struct V_9 * V_10 , const char T_2 * V_11 , T_3 V_12 ,
T_4 * V_13 )
{
struct V_5 * V_6 = V_10 -> V_36 ;
struct V_14 * V_14 = V_6 -> V_15 ;
T_3 V_47 ;
T_4 V_20 ;
T_1 V_80 ;
F_41 ( V_14 -> V_72 ) ;
F_15 ( & V_14 -> V_89 ) ;
if ( ! F_12 ( V_90 , V_11 , V_12 ) ) {
V_80 = - V_34 ;
goto V_91;
}
V_20 = * V_13 ;
V_47 = V_12 ;
V_92 -> V_93 = V_6 -> V_93 ;
V_80 = F_42 ( V_10 , & V_20 , & V_47 , F_43 ( V_14 -> V_94 ) ) ;
if ( V_80 )
goto V_95;
if ( V_47 == 0 )
goto V_95;
V_80 = F_44 ( V_10 ) ;
if ( V_80 )
goto V_95;
V_80 = F_45 ( V_10 ) ;
if ( V_80 )
goto V_95;
V_80 = F_36 ( V_10 , V_11 , V_47 , V_20 , V_13 ) ;
V_95:
V_92 -> V_93 = NULL ;
V_91:
F_27 ( & V_14 -> V_89 ) ;
F_46 ( V_14 -> V_72 ) ;
return V_80 ;
}
int
F_47 ( struct V_5 * V_6 , T_4 V_96 )
{
T_5 V_16 = V_96 >> V_24 ;
unsigned V_18 = V_96 & ( V_32 - 1 ) ;
unsigned V_97 ;
unsigned V_98 ;
void * V_29 ;
unsigned long V_30 ;
int V_75 ;
F_4 ( ! V_6 -> V_22 -> V_23 ) ;
V_97 = 1 << V_6 -> V_15 -> V_99 ;
V_98 = V_18 & ( V_97 - 1 ) ;
if ( ! V_98 )
return 0 ;
V_98 = V_97 - V_98 ;
V_75 = V_6 -> V_22 -> V_23 ( V_6 , V_16 , 0 ,
& V_29 , & V_30 ) ;
if ( F_6 ( V_75 ) ) {
if ( V_75 == - V_33 )
return 0 ;
else
return V_75 ;
}
memset ( V_29 + V_18 , 0 , V_98 ) ;
return 0 ;
}
