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
if ( ! V_36 ) {
V_30 = - V_41 ;
break;
}
V_22 += V_36 ;
V_10 += V_36 ;
}
if ( V_34 )
F_8 () ;
return ( V_22 == V_28 ) ? V_30 : V_22 - V_28 ;
}
T_4 F_24 ( struct V_42 * V_43 , struct V_1 * V_1 ,
struct V_26 * V_27 , T_3 V_22 , T_5 V_29 ,
T_7 V_44 , int V_45 )
{
struct V_15 V_16 ;
T_4 V_30 = - V_46 ;
T_3 V_23 = V_22 + F_25 ( V_27 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( ( V_45 & V_47 ) && F_16 ( V_27 ) == V_48 ) {
struct V_49 * V_50 = V_1 -> V_51 ;
F_26 ( & V_1 -> V_52 ) ;
V_30 = F_27 ( V_50 , V_22 , V_23 - 1 ) ;
if ( V_30 ) {
F_28 ( & V_1 -> V_52 ) ;
goto V_53;
}
}
if ( ! ( V_45 & V_54 ) )
F_29 ( V_1 ) ;
V_30 = F_15 ( V_1 , V_27 , V_22 , V_23 , V_29 , & V_16 ) ;
if ( ( V_45 & V_47 ) && F_16 ( V_27 ) == V_48 )
F_28 ( & V_1 -> V_52 ) ;
if ( ( V_30 > 0 ) && V_44 )
V_44 ( V_43 , V_22 , V_30 , V_16 . V_55 ) ;
if ( ! ( V_45 & V_54 ) )
F_30 ( V_1 ) ;
V_53:
return V_30 ;
}
static int F_31 ( struct V_49 * V_50 , struct V_37 * V_37 ,
struct V_56 * V_57 )
{
unsigned long V_3 ;
struct V_1 * V_1 = V_50 -> V_58 ;
if ( ! V_37 )
V_37 = F_32 ( V_50 , V_57 -> V_59 ,
V_60 | V_61 ) ;
if ( ! V_37 )
return V_62 ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_57 -> V_59 >= V_3 ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
return V_63 ;
}
V_57 -> V_37 = V_37 ;
return V_64 ;
}
static int F_35 ( struct V_37 * V_65 , struct V_15 * V_16 ,
unsigned V_17 , unsigned long V_66 )
{
void T_2 * V_67 ;
void * V_68 ;
if ( F_9 ( V_16 , & V_67 , V_17 ) < 0 )
return - V_69 ;
V_68 = F_36 ( V_65 ) ;
F_37 ( V_68 , ( void V_40 * ) V_67 , V_66 , V_65 ) ;
F_38 ( V_68 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , struct V_15 * V_16 ,
struct V_70 * V_71 , struct V_56 * V_57 )
{
struct V_49 * V_50 = V_1 -> V_51 ;
T_1 V_8 = V_16 -> V_18 << ( V_1 -> V_9 - 9 ) ;
unsigned long V_66 = ( unsigned long ) V_57 -> V_72 ;
void T_2 * V_10 ;
unsigned long V_11 ;
T_8 V_3 ;
int error ;
F_40 ( V_50 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( F_41 ( V_57 -> V_59 >= V_3 ) ) {
error = - V_69 ;
goto V_53;
}
error = F_3 ( V_16 -> V_19 , V_8 , & V_10 , & V_11 , V_16 -> V_20 ) ;
if ( error < 0 )
goto V_53;
if ( error < V_14 ) {
error = - V_69 ;
goto V_53;
}
if ( F_13 ( V_16 ) || F_20 ( V_16 ) ) {
F_6 ( V_10 , V_14 ) ;
F_8 () ;
}
error = F_42 ( V_71 , V_66 , V_11 ) ;
V_53:
F_43 ( V_50 ) ;
return error ;
}
int F_44 ( struct V_70 * V_71 , struct V_56 * V_57 ,
T_5 V_29 , T_9 V_73 )
{
struct V_74 * V_74 = V_71 -> V_75 ;
struct V_49 * V_50 = V_74 -> V_76 ;
struct V_1 * V_1 = V_50 -> V_58 ;
struct V_37 * V_37 ;
struct V_15 V_16 ;
unsigned long V_66 = ( unsigned long ) V_57 -> V_72 ;
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 ;
T_8 V_3 ;
int error ;
int V_77 = 0 ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_57 -> V_59 >= V_3 )
return V_63 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_57 -> V_59 << ( V_38 - V_17 ) ;
V_16 . V_20 = V_14 ;
V_78:
V_37 = F_45 ( V_50 , V_57 -> V_59 ) ;
if ( V_37 ) {
if ( ! F_46 ( V_37 , V_71 -> V_79 , V_57 -> V_45 ) ) {
F_34 ( V_37 ) ;
return V_80 ;
}
if ( F_41 ( V_37 -> V_50 != V_50 ) ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
goto V_78;
}
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( F_41 ( V_57 -> V_59 >= V_3 ) ) {
error = - V_69 ;
goto F_33;
}
}
error = V_29 ( V_1 , V_2 , & V_16 , 0 ) ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_69 ;
if ( error )
goto F_33;
if ( ! F_12 ( & V_16 ) && ! F_13 ( & V_16 ) && ! V_57 -> V_81 ) {
if ( V_57 -> V_45 & V_82 ) {
error = V_29 ( V_1 , V_2 , & V_16 , 1 ) ;
F_47 ( V_83 ) ;
F_48 ( V_71 -> V_79 , V_83 ) ;
V_77 = V_84 ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_69 ;
if ( error )
goto F_33;
} else {
return F_31 ( V_50 , V_37 , V_57 ) ;
}
}
if ( V_57 -> V_81 ) {
struct V_37 * V_85 = V_57 -> V_81 ;
if ( F_11 ( & V_16 ) )
error = F_35 ( V_85 , & V_16 , V_17 , V_66 ) ;
else
F_49 ( V_85 , V_66 ) ;
if ( error )
goto F_33;
V_57 -> V_37 = V_37 ;
if ( ! V_37 ) {
F_40 ( V_50 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >>
V_38 ;
if ( V_57 -> V_59 >= V_3 ) {
F_43 ( V_50 ) ;
error = - V_69 ;
goto V_53;
}
}
return V_64 ;
}
if ( ! V_37 && V_77 )
V_37 = F_50 ( V_50 , V_57 -> V_59 ) ;
if ( V_37 ) {
F_51 ( V_50 , V_57 -> V_59 << V_38 ,
V_86 , 0 ) ;
F_52 ( V_37 ) ;
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
}
error = F_39 ( V_1 , & V_16 , V_71 , V_57 ) ;
if ( F_13 ( & V_16 ) ) {
if ( V_73 )
V_73 ( & V_16 , ! error ) ;
else
F_53 ( ! ( V_57 -> V_45 & V_82 ) ) ;
}
V_53:
if ( error == - V_87 )
return V_62 | V_77 ;
if ( ( error < 0 ) && ( error != - V_88 ) )
return V_63 | V_77 ;
return V_89 | V_77 ;
F_33:
if ( V_37 ) {
F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
}
goto V_53;
}
int F_54 ( struct V_70 * V_71 , struct V_56 * V_57 ,
T_5 V_29 , T_9 V_73 )
{
int V_90 ;
struct V_91 * V_92 = F_55 ( V_71 -> V_75 ) -> V_6 ;
if ( V_57 -> V_45 & V_82 ) {
F_56 ( V_92 ) ;
F_57 ( V_71 -> V_75 ) ;
}
V_90 = F_44 ( V_71 , V_57 , V_29 , V_73 ) ;
if ( V_57 -> V_45 & V_82 )
F_58 ( V_92 ) ;
return V_90 ;
}
int F_59 ( struct V_70 * V_71 , unsigned long V_93 ,
T_10 * V_94 , unsigned int V_45 , T_5 V_29 ,
T_9 V_73 )
{
struct V_74 * V_74 = V_71 -> V_75 ;
struct V_49 * V_50 = V_74 -> V_76 ;
struct V_1 * V_1 = V_50 -> V_58 ;
struct V_15 V_16 ;
unsigned V_17 = V_1 -> V_9 ;
unsigned long V_95 = V_93 & V_96 ;
bool V_97 = V_45 & V_82 ;
long V_98 ;
void T_2 * V_99 ;
T_8 V_3 , V_59 ;
T_1 V_2 , V_8 ;
unsigned long V_11 ;
int V_90 = 0 ;
if ( ! F_60 ( V_100 ) )
return V_101 ;
if ( V_97 && ! ( V_71 -> V_102 & V_103 ) )
return V_101 ;
if ( V_95 < V_71 -> V_104 )
return V_101 ;
if ( ( V_95 + V_105 ) > V_71 -> V_106 )
return V_101 ;
V_59 = F_61 ( V_71 , V_95 ) ;
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_59 >= V_3 )
return V_63 ;
if ( ( V_59 | V_107 ) >= V_3 )
return V_101 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_59 << ( V_38 - V_17 ) ;
V_16 . V_20 = V_105 ;
V_98 = V_29 ( V_1 , V_2 , & V_16 , V_97 ) ;
if ( V_98 )
return V_63 ;
F_40 ( V_50 ) ;
if ( ! F_14 ( & V_16 ) || V_16 . V_20 < V_105 )
goto V_108;
if ( F_20 ( & V_16 ) ) {
F_43 ( V_50 ) ;
F_51 ( V_50 , V_59 << V_38 , V_105 , 0 ) ;
F_40 ( V_50 ) ;
}
V_3 = ( F_18 ( V_1 ) + V_14 - 1 ) >> V_38 ;
if ( V_59 >= V_3 ) {
V_90 = V_63 ;
goto V_53;
}
if ( ( V_59 | V_107 ) >= V_3 )
goto V_108;
if ( ! V_97 && ! F_12 ( & V_16 ) && F_62 ( & V_16 ) ) {
T_11 * V_109 ;
T_10 V_110 ;
struct V_37 * V_111 = F_63 () ;
if ( F_41 ( ! V_111 ) )
goto V_108;
V_109 = F_64 ( V_71 -> V_79 , V_94 ) ;
if ( ! F_65 ( * V_94 ) ) {
F_66 ( V_109 ) ;
goto V_108;
}
V_110 = F_67 ( V_111 , V_71 -> V_112 ) ;
V_110 = F_68 ( V_110 ) ;
F_69 ( V_71 -> V_79 , V_95 , V_94 , V_110 ) ;
V_90 = V_89 ;
F_66 ( V_109 ) ;
} else {
V_8 = V_16 . V_18 << ( V_17 - 9 ) ;
V_98 = F_3 ( V_16 . V_19 , V_8 , & V_99 , & V_11 ,
V_16 . V_20 ) ;
if ( V_98 < 0 ) {
V_90 = V_63 ;
goto V_53;
}
if ( ( V_98 < V_105 ) || ( V_11 & V_107 ) )
goto V_108;
if ( F_70 ( V_11 ) )
goto V_108;
if ( F_13 ( & V_16 ) || F_20 ( & V_16 ) ) {
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
F_6 ( V_99 + V_113 * V_14 , V_14 ) ;
F_8 () ;
F_47 ( V_83 ) ;
F_48 ( V_71 -> V_79 , V_83 ) ;
V_90 |= V_84 ;
}
V_90 |= F_71 ( V_71 , V_93 , V_94 , V_11 , V_97 ) ;
}
V_53:
F_43 ( V_50 ) ;
if ( F_13 ( & V_16 ) )
V_73 ( & V_16 , ! ( V_90 & V_115 ) ) ;
return V_90 ;
V_108:
F_47 ( V_116 ) ;
V_90 = V_101 ;
goto V_53;
}
int F_72 ( struct V_70 * V_71 , unsigned long V_93 ,
T_10 * V_94 , unsigned int V_45 , T_5 V_29 ,
T_9 V_73 )
{
int V_90 ;
struct V_91 * V_92 = F_55 ( V_71 -> V_75 ) -> V_6 ;
if ( V_45 & V_82 ) {
F_56 ( V_92 ) ;
F_57 ( V_71 -> V_75 ) ;
}
V_90 = F_59 ( V_71 , V_93 , V_94 , V_45 , V_29 ,
V_73 ) ;
if ( V_45 & V_82 )
F_58 ( V_92 ) ;
return V_90 ;
}
int F_73 ( struct V_70 * V_71 , struct V_56 * V_57 )
{
struct V_91 * V_92 = F_55 ( V_71 -> V_75 ) -> V_6 ;
F_56 ( V_92 ) ;
F_57 ( V_71 -> V_75 ) ;
F_58 ( V_92 ) ;
return V_89 ;
}
int F_74 ( struct V_1 * V_1 , T_3 V_117 , unsigned V_98 ,
T_5 V_29 )
{
struct V_15 V_16 ;
T_8 V_118 = V_117 >> V_119 ;
unsigned V_120 = V_117 & ( V_86 - 1 ) ;
int V_121 ;
if ( ! V_98 )
return 0 ;
F_4 ( ( V_120 + V_98 ) > V_86 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_20 = V_86 ;
V_121 = V_29 ( V_1 , V_118 , & V_16 , 0 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_11 ( & V_16 ) ) {
void T_2 * V_10 ;
V_121 = F_9 ( & V_16 , & V_10 , V_1 -> V_9 ) ;
if ( V_121 < 0 )
return V_121 ;
F_6 ( V_10 + V_120 , V_98 ) ;
F_8 () ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_1 , T_3 V_117 , T_5 V_29 )
{
unsigned V_98 = F_76 ( V_117 ) - V_117 ;
return F_74 ( V_1 , V_117 , V_98 , V_29 ) ;
}
