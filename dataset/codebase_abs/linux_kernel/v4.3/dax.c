int F_1 ( struct V_1 * V_1 , T_1 V_2 , long V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_1 V_8 = V_2 << ( V_1 -> V_9 - 9 ) ;
F_2 () ;
do {
void T_2 * V_10 ;
unsigned long V_11 ;
long V_12 ;
V_12 = F_3 ( V_5 , V_8 , & V_10 , & V_11 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_4 ( V_3 < V_12 ) ;
while ( V_12 > 0 ) {
unsigned V_13 = V_14 - F_5 ( V_10 ) ;
if ( V_13 > V_12 )
V_13 = V_12 ;
F_6 ( V_10 , V_13 ) ;
V_10 += V_13 ;
V_3 -= V_13 ;
V_12 -= V_13 ;
F_4 ( V_13 & 511 ) ;
V_8 += V_13 / 512 ;
F_7 () ;
}
} while ( V_3 );
F_8 () ;
return 0 ;
}
static long F_9 ( struct V_15 * V_16 , void T_2 * * V_10 ,
unsigned V_17 )
{
unsigned long V_11 ;
T_1 V_8 = V_16 -> V_18 << ( V_17 - 9 ) ;
return F_3 ( V_16 -> V_19 , V_8 , V_10 , & V_11 , V_16 -> V_20 ) ;
}
static void F_10 ( void T_2 * V_10 , unsigned V_3 , unsigned V_21 ,
T_3 V_22 , T_3 V_23 )
{
T_3 V_24 = V_23 - V_22 + V_21 ;
if ( V_21 > 0 )
F_6 ( V_10 , V_21 ) ;
if ( V_24 < V_3 )
F_6 ( V_10 + V_24 , V_3 - V_24 ) ;
}
static bool F_11 ( struct V_15 * V_16 )
{
return F_12 ( V_16 ) && ! F_13 ( V_16 ) ;
}
static bool F_14 ( struct V_15 * V_16 )
{
return V_16 -> V_25 != 0 ;
}
static T_4 F_15 ( struct V_1 * V_1 , struct V_26 * V_27 ,
T_3 V_28 , T_3 V_23 , T_5 V_29 ,
struct V_15 * V_16 )
{
T_4 V_30 = 0 ;
T_3 V_22 = V_28 ;
T_3 V_31 = V_28 ;
T_3 V_32 = V_28 ;
void T_2 * V_10 ;
bool V_33 = false ;
bool V_34 = false ;
if ( F_16 ( V_27 ) != V_35 )
V_23 = F_17 ( V_23 , F_18 ( V_1 ) ) ;
while ( V_22 < V_23 ) {
T_6 V_36 ;
if ( V_22 == V_31 ) {
unsigned V_17 = V_1 -> V_9 ;
long V_37 = V_22 >> V_38 ;
T_1 V_2 = V_37 << ( V_38 - V_17 ) ;
unsigned V_21 = V_22 - ( V_2 << V_17 ) ;
long V_3 ;
if ( V_22 == V_32 ) {
V_16 -> V_20 = F_19 ( V_23 - V_22 ) ;
V_16 -> V_25 = 0 ;
V_30 = V_29 ( V_1 , V_2 , V_16 ,
F_16 ( V_27 ) == V_35 ) ;
if ( V_30 )
break;
if ( ! F_14 ( V_16 ) )
V_16 -> V_20 = 1 << V_17 ;
V_32 = V_22 - V_21 + V_16 -> V_20 ;
} else {
unsigned V_39 = V_16 -> V_20 -
( V_32 - ( V_22 - V_21 ) ) ;
V_16 -> V_18 += V_39 >> V_17 ;
V_16 -> V_20 -= V_39 ;
}
V_33 = F_16 ( V_27 ) != V_35 && ! F_11 ( V_16 ) ;
if ( V_33 ) {
V_10 = NULL ;
V_3 = V_16 -> V_20 - V_21 ;
} else {
V_30 = F_9 ( V_16 , & V_10 , V_17 ) ;
if ( V_30 < 0 )
break;
if ( F_13 ( V_16 ) || F_20 ( V_16 ) ) {
F_10 ( V_10 , V_30 , V_21 , V_22 ,
V_23 ) ;
V_34 = true ;
}
V_10 += V_21 ;
V_3 = V_30 - V_21 ;
}
V_31 = F_17 ( V_22 + V_3 , V_23 ) ;
}
if ( F_16 ( V_27 ) == V_35 ) {
V_36 = F_21 ( V_10 , V_31 - V_22 , V_27 ) ;
V_34 = true ;
} else if ( ! V_33 )
V_36 = F_22 ( ( void V_40 * ) V_10 , V_31 - V_22 ,
V_27 ) ;
else
V_36 = F_23 ( V_31 - V_22 , V_27 ) ;
if ( ! V_36 )
break;
V_22 += V_36 ;
V_10 += V_36 ;
}
if ( V_34 )
F_8 () ;
return ( V_22 == V_28 ) ? V_30 : V_22 - V_28 ;
}
T_4 F_24 ( struct V_41 * V_42 , struct V_1 * V_1 ,
struct V_26 * V_27 , T_3 V_22 , T_5 V_29 ,
T_7 V_43 , int V_44 )
{
struct V_15 V_16 ;
T_4 V_30 = - V_45 ;
T_3 V_23 = V_22 + F_25 ( V_27 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( ( V_44 & V_46 ) && F_16 ( V_27 ) == V_47 ) {
struct V_48 * V_49 = V_1 -> V_50 ;
F_26 ( & V_1 -> V_51 ) ;
V_30 = F_27 ( V_49 , V_22 , V_23 - 1 ) ;
if ( V_30 ) {
F_28 ( & V_1 -> V_51 ) ;
goto V_52;
}
}
if ( ! ( V_44 & V_53 ) )
F_29 ( V_1 ) ;
V_30 = F_15 ( V_1 , V_27 , V_22 , V_23 , V_29 , & V_16 ) ;
if ( ( V_44 & V_46 ) && F_16 ( V_27 ) == V_47 )
F_28 ( & V_1 -> V_51 ) ;
if ( ( V_30 > 0 ) && V_43 )
V_43 ( V_42 , V_22 , V_30 , V_16 . V_54 ) ;
if ( ! ( V_44 & V_53 ) )
F_30 ( V_1 ) ;
V_52:
return V_30 ;
}
static int F_31 ( struct V_48 * V_49 , struct V_37 * V_37 ,
struct V_55 * V_56 )
{
unsigned long V_3 ;
struct V_1 * V_1 = V_49 -> V_57 ;
if ( ! V_37 )
V_37 = F_32 ( V_49 , V_56 -> V_58 ,
V_59 | V_60 ) ;
if ( ! V_37 )
return V_61 ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_56 -> V_58 >= V_3 ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
return V_62 ;
}
V_56 -> V_37 = V_37 ;
return V_63 ;
}
static int F_35 ( struct V_37 * V_64 , struct V_15 * V_16 ,
unsigned V_17 , unsigned long V_65 )
{
void T_2 * V_66 ;
void * V_67 ;
if ( F_9 ( V_16 , & V_66 , V_17 ) < 0 )
return - V_68 ;
V_67 = F_36 ( V_64 ) ;
F_37 ( V_67 , ( void V_40 * ) V_66 , V_65 , V_64 ) ;
F_38 ( V_67 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , struct V_15 * V_16 ,
struct V_69 * V_70 , struct V_55 * V_56 )
{
struct V_48 * V_49 = V_1 -> V_50 ;
T_1 V_8 = V_16 -> V_18 << ( V_1 -> V_9 - 9 ) ;
unsigned long V_65 = ( unsigned long ) V_56 -> V_71 ;
void T_2 * V_10 ;
unsigned long V_11 ;
T_8 V_3 ;
int error ;
F_40 ( V_49 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( F_41 ( V_56 -> V_58 >= V_3 ) ) {
error = - V_68 ;
goto V_52;
}
error = F_3 ( V_16 -> V_19 , V_8 , & V_10 , & V_11 , V_16 -> V_20 ) ;
if ( error < 0 )
goto V_52;
if ( error < V_14 ) {
error = - V_68 ;
goto V_52;
}
if ( F_13 ( V_16 ) || F_20 ( V_16 ) ) {
F_6 ( V_10 , V_14 ) ;
F_8 () ;
}
error = F_42 ( V_70 , V_65 , V_11 ) ;
V_52:
F_43 ( V_49 ) ;
return error ;
}
int F_44 ( struct V_69 * V_70 , struct V_55 * V_56 ,
T_5 V_29 , T_9 V_72 )
{
struct V_73 * V_73 = V_70 -> V_74 ;
struct V_48 * V_49 = V_73 -> V_75 ;
struct V_1 * V_1 = V_49 -> V_57 ;
struct V_37 * V_37 ;
struct V_15 V_16 ;
unsigned long V_65 = ( unsigned long ) V_56 -> V_71 ;
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 ;
T_8 V_3 ;
int error ;
int V_76 = 0 ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_56 -> V_58 >= V_3 )
return V_62 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_56 -> V_58 << ( V_38 - V_17 ) ;
V_16 . V_20 = V_14 ;
V_77:
V_37 = F_45 ( V_49 , V_56 -> V_58 ) ;
if ( V_37 ) {
if ( ! F_46 ( V_37 , V_70 -> V_78 , V_56 -> V_44 ) ) {
F_34 ( V_37 ) ;
return V_79 ;
}
if ( F_41 ( V_37 -> V_49 != V_49 ) ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
goto V_77;
}
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( F_41 ( V_56 -> V_58 >= V_3 ) ) {
error = - V_68 ;
goto F_33;
}
}
error = V_29 ( V_1 , V_2 , & V_16 , 0 ) ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_68 ;
if ( error )
goto F_33;
if ( ! F_12 ( & V_16 ) && ! F_13 ( & V_16 ) && ! V_56 -> V_80 ) {
if ( V_56 -> V_44 & V_81 ) {
error = V_29 ( V_1 , V_2 , & V_16 , 1 ) ;
F_47 ( V_82 ) ;
F_48 ( V_70 -> V_78 , V_82 ) ;
V_76 = V_83 ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_68 ;
if ( error )
goto F_33;
} else {
return F_31 ( V_49 , V_37 , V_56 ) ;
}
}
if ( V_56 -> V_80 ) {
struct V_37 * V_84 = V_56 -> V_80 ;
if ( F_11 ( & V_16 ) )
error = F_35 ( V_84 , & V_16 , V_17 , V_65 ) ;
else
F_49 ( V_84 , V_65 ) ;
if ( error )
goto F_33;
V_56 -> V_37 = V_37 ;
if ( ! V_37 ) {
F_40 ( V_49 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >>
V_38 ;
if ( V_56 -> V_58 >= V_3 ) {
F_43 ( V_49 ) ;
error = - V_68 ;
goto V_52;
}
}
return V_63 ;
}
if ( ! V_37 && V_76 )
V_37 = F_50 ( V_49 , V_56 -> V_58 ) ;
if ( V_37 ) {
F_51 ( V_49 , V_56 -> V_58 << V_38 ,
V_85 , 0 ) ;
F_52 ( V_37 ) ;
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
}
error = F_39 ( V_1 , & V_16 , V_70 , V_56 ) ;
if ( F_13 ( & V_16 ) ) {
if ( V_72 )
V_72 ( & V_16 , ! error ) ;
else
F_53 ( ! ( V_56 -> V_44 & V_81 ) ) ;
}
V_52:
if ( error == - V_86 )
return V_61 | V_76 ;
if ( ( error < 0 ) && ( error != - V_87 ) )
return V_62 | V_76 ;
return V_88 | V_76 ;
F_33:
if ( V_37 ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
}
goto V_52;
}
int F_54 ( struct V_69 * V_70 , struct V_55 * V_56 ,
T_5 V_29 , T_9 V_72 )
{
int V_89 ;
struct V_90 * V_91 = F_55 ( V_70 -> V_74 ) -> V_6 ;
if ( V_56 -> V_44 & V_81 ) {
F_56 ( V_91 ) ;
F_57 ( V_70 -> V_74 ) ;
}
V_89 = F_44 ( V_70 , V_56 , V_29 , V_72 ) ;
if ( V_56 -> V_44 & V_81 )
F_58 ( V_91 ) ;
return V_89 ;
}
int F_59 ( struct V_69 * V_70 , unsigned long V_92 ,
T_10 * V_93 , unsigned int V_44 , T_5 V_29 ,
T_9 V_72 )
{
struct V_73 * V_73 = V_70 -> V_74 ;
struct V_48 * V_49 = V_73 -> V_75 ;
struct V_1 * V_1 = V_49 -> V_57 ;
struct V_15 V_16 ;
unsigned V_17 = V_1 -> V_9 ;
unsigned long V_94 = V_92 & V_95 ;
bool V_96 = V_44 & V_81 ;
long V_97 ;
void T_2 * V_98 ;
T_8 V_3 , V_58 ;
T_1 V_2 , V_8 ;
unsigned long V_11 ;
int V_89 = 0 ;
if ( V_96 && ! ( V_70 -> V_99 & V_100 ) )
return V_101 ;
if ( V_94 < V_70 -> V_102 )
return V_101 ;
if ( ( V_94 + V_103 ) > V_70 -> V_104 )
return V_101 ;
V_58 = F_60 ( V_70 , V_94 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_58 >= V_3 )
return V_62 ;
if ( ( V_58 | V_105 ) >= V_3 )
return V_101 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_58 << ( V_38 - V_17 ) ;
V_16 . V_20 = V_103 ;
V_97 = V_29 ( V_1 , V_2 , & V_16 , V_96 ) ;
if ( V_97 )
return V_62 ;
F_40 ( V_49 ) ;
if ( ! F_14 ( & V_16 ) || V_16 . V_20 < V_103 )
goto V_106;
if ( F_20 ( & V_16 ) ) {
F_43 ( V_49 ) ;
F_51 ( V_49 , V_58 << V_38 , V_103 , 0 ) ;
F_40 ( V_49 ) ;
}
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_58 >= V_3 ) {
V_89 = V_62 ;
goto V_52;
}
if ( ( V_58 | V_105 ) >= V_3 )
goto V_106;
if ( ! V_96 && ! F_12 ( & V_16 ) && F_61 ( & V_16 ) ) {
T_11 * V_107 ;
T_10 V_108 ;
struct V_37 * V_109 = F_62 () ;
if ( F_41 ( ! V_109 ) )
goto V_106;
V_107 = F_63 ( V_70 -> V_78 , V_93 ) ;
if ( ! F_64 ( * V_93 ) ) {
F_65 ( V_107 ) ;
goto V_106;
}
V_108 = F_66 ( V_109 , V_70 -> V_110 ) ;
V_108 = F_67 ( V_108 ) ;
F_68 ( V_70 -> V_78 , V_94 , V_93 , V_108 ) ;
V_89 = V_88 ;
F_65 ( V_107 ) ;
} else {
V_8 = V_16 . V_18 << ( V_17 - 9 ) ;
V_97 = F_3 ( V_16 . V_19 , V_8 , & V_98 , & V_11 ,
V_16 . V_20 ) ;
if ( V_97 < 0 ) {
V_89 = V_62 ;
goto V_52;
}
if ( ( V_97 < V_103 ) || ( V_11 & V_105 ) )
goto V_106;
if ( F_13 ( & V_16 ) || F_20 ( & V_16 ) ) {
int V_111 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
F_6 ( V_98 + V_111 * V_14 , V_14 ) ;
F_8 () ;
F_47 ( V_82 ) ;
F_48 ( V_70 -> V_78 , V_82 ) ;
V_89 |= V_83 ;
}
V_89 |= F_69 ( V_70 , V_92 , V_93 , V_11 , V_96 ) ;
}
V_52:
F_43 ( V_49 ) ;
if ( F_13 ( & V_16 ) )
V_72 ( & V_16 , ! ( V_89 & V_113 ) ) ;
return V_89 ;
V_106:
F_47 ( V_114 ) ;
V_89 = V_101 ;
goto V_52;
}
int F_70 ( struct V_69 * V_70 , unsigned long V_92 ,
T_10 * V_93 , unsigned int V_44 , T_5 V_29 ,
T_9 V_72 )
{
int V_89 ;
struct V_90 * V_91 = F_55 ( V_70 -> V_74 ) -> V_6 ;
if ( V_44 & V_81 ) {
F_56 ( V_91 ) ;
F_57 ( V_70 -> V_74 ) ;
}
V_89 = F_59 ( V_70 , V_92 , V_93 , V_44 , V_29 ,
V_72 ) ;
if ( V_44 & V_81 )
F_58 ( V_91 ) ;
return V_89 ;
}
int F_71 ( struct V_69 * V_70 , struct V_55 * V_56 )
{
struct V_90 * V_91 = F_55 ( V_70 -> V_74 ) -> V_6 ;
F_56 ( V_91 ) ;
F_57 ( V_70 -> V_74 ) ;
F_58 ( V_91 ) ;
return V_88 ;
}
int F_72 ( struct V_1 * V_1 , T_3 V_115 , unsigned V_97 ,
T_5 V_29 )
{
struct V_15 V_16 ;
T_8 V_116 = V_115 >> V_117 ;
unsigned V_118 = V_115 & ( V_85 - 1 ) ;
int V_119 ;
if ( ! V_97 )
return 0 ;
F_4 ( ( V_118 + V_97 ) > V_85 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_20 = V_85 ;
V_119 = V_29 ( V_1 , V_116 , & V_16 , 0 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( F_11 ( & V_16 ) ) {
void T_2 * V_10 ;
V_119 = F_9 ( & V_16 , & V_10 , V_1 -> V_9 ) ;
if ( V_119 < 0 )
return V_119 ;
F_6 ( V_10 + V_118 , V_97 ) ;
F_8 () ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_1 , T_3 V_115 , T_5 V_29 )
{
unsigned V_97 = F_74 ( V_115 ) - V_115 ;
return F_72 ( V_1 , V_115 , V_97 , V_29 ) ;
}
