static void T_1 F_1 ( int V_1 )
{
T_2 * V_2 ;
void * V_3 ;
if ( ! ( V_4 & V_5 ) )
return;
for ( V_3 = V_6 . V_7 ; V_3 < V_6 . V_8 ; V_3 += V_6 . V_9 ) {
V_2 = V_3 ;
if ( V_2 -> type == V_10 ||
V_2 -> type == V_11 )
F_2 ( V_2 , V_1 ) ;
}
}
void T_1 F_3 ( void )
{
unsigned long V_12 ;
int V_13 ;
int V_14 ;
if ( ! F_4 ( V_15 ) )
return;
F_1 ( 1 ) ;
F_5 ( V_16 ) ;
V_14 = F_6 ( ( V_17 << V_18 ) , V_19 ) ;
V_20 = F_7 ( V_14 * sizeof( V_21 ) , V_22 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_20 [ V_13 ] = * F_8 ( V_13 * V_19 ) ;
V_12 = ( unsigned long ) F_9 ( V_13 * V_19 ) ;
F_10 ( F_8 ( V_13 * V_19 ) , * F_8 ( V_12 ) ) ;
}
F_11 () ;
}
void T_1 F_12 ( void )
{
int V_13 ;
int V_14 = F_6 ( ( V_17 << V_18 ) , V_19 ) ;
if ( ! F_4 ( V_15 ) )
return;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_10 ( F_8 ( V_13 * V_19 ) , V_20 [ V_13 ] ) ;
F_13 ( V_20 ) ;
F_11 () ;
F_14 ( V_16 ) ;
F_1 ( 0 ) ;
}
void F_15 ( void )
{
unsigned V_23 ;
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
if ( F_4 ( V_15 ) )
return;
V_23 = F_16 ( V_26 - 1 ) - F_16 ( V_27 ) ;
memcpy ( V_13 + F_16 ( V_27 ) ,
V_28 . V_13 + F_16 ( V_27 ) ,
sizeof( V_21 ) * V_23 ) ;
}
int T_1 F_17 ( unsigned long V_29 , unsigned V_30 )
{
unsigned long V_31 ;
struct V_32 * V_32 ;
unsigned V_33 ;
V_21 * V_13 ;
if ( F_4 ( V_15 ) )
return 0 ;
V_34 . V_35 = ( V_21 * ) ( unsigned long ) V_24 -> V_25 ;
V_13 = F_9 ( V_34 . V_35 ) ;
if ( F_18 ( V_13 , V_29 , V_29 , V_30 , V_5 ) ) {
F_19 ( L_1 , V_29 ) ;
return 1 ;
}
V_34 . V_36 = true ;
if ( ! F_20 ( V_37 ) )
return 0 ;
V_32 = F_21 ( V_22 | V_38 ) ;
if ( ! V_32 )
F_22 ( L_2 ) ;
V_34 . V_39 = F_23 ( F_24 ( V_32 ) ) ;
V_34 . V_39 += V_40 ;
V_33 = ( V_41 - V_42 ) >> V_18 ;
V_31 = F_25 ( V_42 ) ;
if ( F_18 ( V_13 , V_31 >> V_18 , V_31 , V_33 , 0 ) ) {
F_19 ( L_3 ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_26 ( unsigned long V_29 , unsigned V_30 )
{
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
F_27 ( V_13 , V_29 , V_30 ) ;
}
static void T_1 F_28 ( T_2 * V_2 , T_3 V_43 )
{
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
unsigned long V_44 = 0 ;
if ( ! ( V_2 -> V_45 & V_46 ) )
V_44 |= V_47 ;
if ( F_18 ( V_13 , V_2 -> V_48 , V_43 , V_2 -> V_30 , V_44 ) )
F_29 ( L_4 ,
V_2 -> V_48 , V_43 ) ;
}
void T_1 F_30 ( T_2 * V_2 )
{
unsigned long V_49 = V_2 -> V_30 << V_18 ;
T_3 V_50 = V_2 -> V_48 ;
if ( F_4 ( V_15 ) )
return F_31 ( V_2 ) ;
F_28 ( V_2 , V_2 -> V_48 ) ;
if ( ! F_32 () && F_20 ( V_37 ) ) {
V_2 -> V_51 = V_2 -> V_48 ;
return;
}
V_52 -= V_49 ;
if ( ! ( V_50 & ( V_53 - 1 ) ) ) {
V_52 &= V_54 ;
} else {
T_3 V_55 = V_50 & ( V_53 - 1 ) ;
T_3 V_56 = V_52 ;
V_52 = ( V_52 & V_54 ) + V_55 ;
if ( V_52 > V_56 )
V_52 -= V_53 ;
}
if ( V_52 < V_57 ) {
F_29 ( V_58 L_5 ) ;
return;
}
F_28 ( V_2 , V_52 ) ;
V_2 -> V_51 = V_52 ;
}
void T_1 F_33 ( T_2 * V_2 )
{
F_28 ( V_2 , V_2 -> V_51 ) ;
}
void T_4 * T_1 F_34 ( unsigned long V_48 , unsigned long V_49 ,
T_5 type , T_3 V_45 )
{
unsigned long V_59 ;
if ( type == V_60 )
return F_35 ( V_48 , V_49 ) ;
V_59 = F_36 ( V_48 , V_48 + V_49 ) ;
if ( ( V_59 << V_18 ) < V_48 + V_49 ) {
unsigned long V_61 = V_59 << V_18 ;
F_34 ( V_61 , V_49 - ( V_61 - V_48 ) , type , V_45 ) ;
}
if ( ! ( V_45 & V_46 ) )
F_37 ( ( T_3 ) ( unsigned long ) F_9 ( V_48 ) , V_49 ) ;
return ( void T_4 * ) F_9 ( V_48 ) ;
}
void T_1 F_38 ( T_3 V_48 , T_5 V_62 )
{
V_63 = V_48 + sizeof( struct V_64 ) ;
}
void T_1 F_39 ( void )
{
if ( ! F_4 ( V_15 ) )
return;
if ( V_4 & V_5 )
F_40 () ;
}
void T_1 F_41 ( void )
{
#ifdef F_42
V_21 * V_13 = ( V_21 * ) F_9 ( V_24 -> V_25 ) ;
F_43 ( NULL , V_13 ) ;
#endif
}
T_6 F_44 (
void * V_65 ,
unsigned long V_66 ,
unsigned long V_67 ,
T_5 V_68 ,
T_2 * V_69 )
{
T_6 V_70 ;
unsigned long V_71 ;
T_5 V_72 ;
F_15 () ;
F_5 ( V_71 ) ;
V_34 . V_73 = F_45 () ;
F_46 ( ( unsigned long ) V_34 . V_35 ) ;
F_11 () ;
V_72 = ( T_5 ) ( unsigned long ) V_65 ;
V_70 = F_47 ( V_72 , V_66 , V_67 ,
V_68 , V_69 ) ;
F_46 ( V_34 . V_73 ) ;
F_11 () ;
F_14 ( V_71 ) ;
return V_70 ;
}
static T_6 F_48 ( T_7 * V_74 , T_8 * V_75 )
{
T_6 V_70 ;
T_5 V_76 , V_77 ;
F_49 ( & V_78 ) ;
V_76 = F_23 ( V_74 ) ;
V_77 = F_23 ( V_75 ) ;
V_70 = F_50 ( V_79 , V_76 , V_77 ) ;
F_51 ( & V_78 ) ;
return V_70 ;
}
static T_6 F_52 ( T_7 * V_74 )
{
T_6 V_70 ;
T_5 V_76 ;
F_49 ( & V_78 ) ;
V_76 = F_23 ( V_74 ) ;
V_70 = F_50 ( V_80 , V_76 ) ;
F_51 ( & V_78 ) ;
return V_70 ;
}
static T_6
F_53 ( T_9 * V_81 , T_9 * V_82 ,
T_7 * V_74 )
{
T_6 V_70 ;
T_5 V_83 , V_84 , V_76 ;
F_49 ( & V_78 ) ;
V_83 = F_23 ( V_81 ) ;
V_84 = F_23 ( V_82 ) ;
V_76 = F_23 ( V_74 ) ;
V_70 = F_50 ( V_85 , V_83 ,
V_84 , V_76 ) ;
F_51 ( & V_78 ) ;
return V_70 ;
}
static T_6
F_54 ( T_9 V_81 , T_7 * V_74 )
{
T_6 V_70 ;
T_5 V_76 ;
F_49 ( & V_78 ) ;
V_76 = F_23 ( V_74 ) ;
V_70 = F_50 ( V_86 , V_81 , V_76 ) ;
F_51 ( & V_78 ) ;
return V_70 ;
}
static T_6
F_55 ( T_10 * V_87 , T_11 * V_88 ,
T_5 * V_89 , unsigned long * V_90 , void * V_91 )
{
T_6 V_70 ;
T_5 V_92 , V_93 , V_94 ;
T_5 V_95 , V_96 ;
V_95 = F_23 ( V_90 ) ;
V_93 = F_23 ( V_88 ) ;
V_92 = F_23 ( V_87 ) ;
V_94 = F_23 ( V_89 ) ;
V_96 = F_23 ( V_91 ) ;
V_70 = F_50 ( V_97 , V_92 , V_93 ,
V_94 , V_95 , V_96 ) ;
return V_70 ;
}
static T_6
F_56 ( T_10 * V_87 , T_11 * V_88 ,
T_5 V_89 , unsigned long V_90 , void * V_91 )
{
T_5 V_92 , V_93 , V_96 ;
T_6 V_70 ;
V_92 = F_23 ( V_87 ) ;
V_93 = F_23 ( V_88 ) ;
V_96 = F_23 ( V_91 ) ;
V_70 = F_50 ( V_98 , V_92 , V_93 ,
V_89 , V_90 , V_96 ) ;
return V_70 ;
}
static T_6
F_57 ( unsigned long * V_99 ,
T_10 * V_87 ,
T_11 * V_88 )
{
T_6 V_70 ;
T_5 V_100 , V_92 , V_93 ;
V_100 = F_23 ( V_99 ) ;
V_93 = F_23 ( V_88 ) ;
V_92 = F_23 ( V_87 ) ;
V_70 = F_50 ( V_101 , V_100 ,
V_92 , V_93 ) ;
return V_70 ;
}
static T_6
F_58 ( T_5 * V_102 )
{
T_6 V_70 ;
T_5 V_103 ;
V_103 = F_23 ( V_102 ) ;
V_70 = F_50 ( V_104 , V_103 ) ;
return V_70 ;
}
static void
F_59 ( int V_105 , T_6 V_70 ,
unsigned long V_90 , T_10 * V_91 )
{
T_5 V_96 ;
V_96 = F_23 ( V_91 ) ;
F_50 ( V_106 , V_105 , V_70 , V_90 , V_96 ) ;
}
static T_6
F_60 ( T_12 * * V_107 ,
unsigned long V_102 , unsigned long V_108 )
{
return V_109 ;
}
static T_6
F_61 ( T_5 V_89 , T_3 * V_110 ,
T_3 * V_111 ,
T_3 * V_112 )
{
T_6 V_70 ;
T_5 V_113 , V_114 , V_115 ;
if ( V_116 . V_117 < V_118 )
return V_109 ;
V_113 = F_23 ( V_110 ) ;
V_114 = F_23 ( V_111 ) ;
V_115 = F_23 ( V_112 ) ;
V_70 = F_50 ( V_119 , V_89 , V_113 ,
V_114 , V_115 ) ;
return V_70 ;
}
static T_6
F_62 ( T_12 * * V_107 ,
unsigned long V_102 , T_3 * V_120 ,
int * V_105 )
{
return V_109 ;
}
void F_63 ( void )
{
V_116 . V_79 = F_48 ;
V_116 . V_80 = F_52 ;
V_116 . V_85 = F_53 ;
V_116 . V_86 = F_54 ;
V_116 . V_97 = F_55 ;
V_116 . V_101 = F_57 ;
V_116 . V_98 = F_56 ;
V_116 . V_104 = F_58 ;
V_116 . V_106 = F_59 ;
V_116 . V_119 = F_61 ;
V_116 . V_121 = F_60 ;
V_116 . V_122 = F_62 ;
}
