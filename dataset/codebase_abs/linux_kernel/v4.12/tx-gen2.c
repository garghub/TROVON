void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
memset ( V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
memset ( V_4 -> V_7 , 0 , sizeof( V_4 -> V_7 ) ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_4 -> V_8 ) ; V_5 ++ ) {
if ( ! V_4 -> V_8 [ V_5 ] )
continue;
F_4 ( V_2 , V_5 ) ;
}
}
static void F_5 ( struct V_9 * V_8 , T_1 V_10 ,
int V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 . V_15 ;
int V_16 = V_8 -> V_16 ;
T_2 V_17 , V_18 ;
T_1 V_19 = V_10 ;
T_3 V_20 ;
V_19 = F_6 ( V_19 , 4 ) ;
if ( F_7 ( V_19 > 0xFFF || V_16 >= V_21 ) )
return;
V_17 = F_8 ( struct V_22 , V_23 ) +
V_11 * sizeof( struct V_24 ) ;
V_18 = F_6 ( V_17 , 64 ) - 1 ;
V_20 = F_9 ( V_19 | ( V_18 << 12 ) ) ;
V_13 -> V_25 [ V_16 ] = V_20 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
F_11 ( & V_8 -> V_26 ) ;
F_12 ( V_2 , L_1 , V_8 -> V_27 , V_8 -> V_16 ) ;
F_13 ( V_2 , V_28 , V_8 -> V_16 | ( V_8 -> V_27 << 16 ) ) ;
}
static T_2 F_14 ( struct V_1 * V_2 ,
struct V_22 * V_29 )
{
return F_15 ( V_29 -> V_11 ) & 0x1f ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_22 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_32 , V_11 ;
V_11 = F_14 ( V_2 , V_29 ) ;
if ( V_11 >= V_4 -> V_33 ) {
F_17 ( V_2 , L_2 , V_11 ) ;
return;
}
for ( V_32 = 1 ; V_32 < V_11 ; V_32 ++ ) {
if ( V_31 -> V_23 & F_18 ( V_32 ) )
F_19 ( V_2 -> V_34 ,
F_20 ( V_29 -> V_23 [ V_32 ] . V_15 ) ,
F_15 ( V_29 -> V_23 [ V_32 ] . V_35 ) ,
V_36 ) ;
else
F_21 ( V_2 -> V_34 ,
F_20 ( V_29 -> V_23 [ V_32 ] . V_15 ) ,
F_15 ( V_29 -> V_23 [ V_32 ] . V_35 ) ,
V_36 ) ;
}
V_29 -> V_11 = 0 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_9 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_37 = V_8 -> V_38 ;
int V_39 = F_23 ( V_8 , V_37 ) ;
F_11 ( & V_8 -> V_26 ) ;
F_16 ( V_2 , & V_8 -> V_40 [ V_39 ] . V_31 ,
F_24 ( V_4 , V_8 , V_37 ) ) ;
if ( V_8 -> V_40 ) {
struct V_41 * V_42 ;
V_42 = V_8 -> V_40 [ V_39 ] . V_42 ;
if ( V_42 ) {
F_25 ( V_2 -> V_43 , V_42 ) ;
V_8 -> V_40 [ V_39 ] . V_42 = NULL ;
}
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_22 * V_29 , T_4 V_15 ,
T_1 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_39 = F_14 ( V_2 , V_29 ) ;
struct V_24 * V_44 = & V_29 -> V_23 [ V_39 ] ;
if ( F_15 ( V_29 -> V_11 ) >= V_4 -> V_33 ) {
F_17 ( V_2 , L_3 ,
V_4 -> V_33 ) ;
return - V_45 ;
}
F_27 ( V_15 , & V_44 -> V_15 ) ;
V_44 -> V_35 = F_9 ( V_19 ) ;
V_29 -> V_11 = F_9 ( V_39 + 1 ) ;
return V_39 ;
}
static
struct V_22 * F_28 ( struct V_1 * V_2 ,
struct V_9 * V_8 ,
struct V_46 * V_47 ,
struct V_41 * V_42 ,
struct V_30 * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_49 * V_50 = (struct V_49 * ) V_42 -> V_51 ;
struct V_22 * V_29 =
F_24 ( V_4 , V_8 , V_8 -> V_16 ) ;
T_4 V_52 ;
int V_32 , V_19 , V_53 , V_54 , V_55 ;
void * V_56 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_52 = F_29 ( V_8 , V_8 -> V_16 ) ;
memcpy ( & V_8 -> V_57 [ V_8 -> V_16 ] , & V_47 -> V_50 ,
V_58 ) ;
F_26 ( V_2 , V_29 , V_52 , V_58 ) ;
F_30 ( sizeof( struct V_59 ) < V_58 ) ;
V_19 = sizeof( struct V_59 ) + sizeof( struct V_60 ) +
F_31 ( V_50 -> V_61 ) - V_58 ;
V_53 = F_32 ( V_19 , 4 ) ;
V_56 = ( ( T_2 * ) & V_47 -> V_50 ) + V_58 ;
V_52 = F_33 ( V_2 -> V_34 , V_56 , V_53 , V_36 ) ;
if ( F_34 ( F_35 ( V_2 -> V_34 , V_52 ) ) )
goto V_62;
F_26 ( V_2 , V_29 , V_52 , V_53 ) ;
V_55 = F_31 ( V_50 -> V_61 ) ;
V_54 = F_36 ( V_42 ) - V_55 ;
if ( V_54 > 0 ) {
V_52 = F_33 ( V_2 -> V_34 , V_42 -> V_51 + V_55 ,
V_54 , V_36 ) ;
if ( F_34 ( F_35 ( V_2 -> V_34 , V_52 ) ) )
goto V_62;
F_26 ( V_2 , V_29 , V_52 , V_54 ) ;
}
for ( V_32 = 0 ; V_32 < F_37 ( V_42 ) -> V_63 ; V_32 ++ ) {
const T_5 * V_64 = & F_37 ( V_42 ) -> V_65 [ V_32 ] ;
int V_66 ;
if ( ! F_38 ( V_64 ) )
continue;
V_52 = F_39 ( V_2 -> V_34 , V_64 , 0 ,
F_38 ( V_64 ) , V_36 ) ;
if ( F_34 ( F_35 ( V_2 -> V_34 , V_52 ) ) )
goto V_62;
V_66 = F_26 ( V_2 , V_29 , V_52 ,
F_38 ( V_64 ) ) ;
V_48 -> V_23 |= F_18 ( V_66 ) ;
}
F_40 ( V_2 -> V_34 , V_42 , V_29 , sizeof( * V_29 ) , & V_47 -> V_50 ,
V_58 + V_53 ,
V_42 -> V_51 + V_55 , V_54 ) ;
F_41 ( V_2 -> V_34 , V_42 , V_55 ,
V_42 -> V_19 - V_55 ) ;
return V_29 ;
V_62:
F_16 ( V_2 , V_48 , V_29 ) ;
return NULL ;
}
int F_42 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_46 * V_47 , int V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_67 = ( void * ) V_47 -> V_68 ;
struct V_30 * V_48 ;
struct V_9 * V_8 = V_4 -> V_8 [ V_5 ] ;
void * V_29 ;
if ( F_43 ( ! F_44 ( V_5 , V_4 -> V_7 ) ,
L_4 , V_5 ) )
return - V_45 ;
if ( F_45 ( V_42 ) &&
F_37 ( V_42 ) -> V_63 > F_46 ( V_4 ) &&
F_47 ( V_42 ) )
return - V_69 ;
F_48 ( & V_8 -> V_26 ) ;
V_8 -> V_40 [ V_8 -> V_16 ] . V_42 = V_42 ;
V_8 -> V_40 [ V_8 -> V_16 ] . V_70 = V_47 ;
V_47 -> V_50 . V_71 =
F_9 ( ( T_1 ) ( F_49 ( V_5 ) |
F_50 ( V_8 -> V_16 ) ) ) ;
V_48 = & V_8 -> V_40 [ V_8 -> V_16 ] . V_31 ;
V_48 -> V_72 = 0 ;
V_29 = F_28 ( V_2 , V_8 , V_47 , V_42 , V_48 ) ;
if ( ! V_29 ) {
F_51 ( & V_8 -> V_26 ) ;
return - 1 ;
}
F_5 ( V_8 , F_15 ( V_67 -> V_19 ) ,
F_14 ( V_2 , V_29 ) ) ;
if ( V_8 -> V_38 == V_8 -> V_16 ) {
if ( V_8 -> V_73 )
F_52 ( & V_8 -> V_74 , V_75 + V_8 -> V_73 ) ;
F_53 ( V_2 , L_5 , V_8 -> V_27 ) ;
F_54 ( V_2 ) ;
}
V_8 -> V_16 = F_55 ( V_8 -> V_16 ) ;
F_10 ( V_2 , V_8 ) ;
if ( F_56 ( V_8 ) < V_8 -> V_76 )
F_57 ( V_2 , V_8 ) ;
F_51 ( & V_8 -> V_26 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_77 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_8 = V_4 -> V_8 [ V_4 -> V_78 ] ;
struct V_46 * V_79 ;
struct V_30 * V_48 ;
unsigned long V_72 ;
void * V_80 = NULL ;
T_4 V_81 ;
int V_39 , V_32 , V_82 ;
T_1 V_83 , V_84 , V_85 ;
bool V_86 = false ;
T_2 V_87 = F_59 ( V_70 -> V_27 ) ;
const T_2 * V_88 [ V_89 ] ;
T_1 V_90 [ V_89 ] ;
struct V_22 * V_29 =
F_24 ( V_4 , V_8 , V_8 -> V_16 ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_83 = sizeof( struct V_91 ) ;
V_84 = sizeof( struct V_91 ) ;
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
V_88 [ V_32 ] = V_70 -> V_51 [ V_32 ] ;
V_90 [ V_32 ] = V_70 -> V_19 [ V_32 ] ;
if ( ! V_70 -> V_19 [ V_32 ] )
continue;
if ( V_83 < V_58 ) {
int V_92 = V_58 - V_83 ;
if ( V_92 > V_90 [ V_32 ] )
V_92 = V_90 [ V_32 ] ;
V_90 [ V_32 ] -= V_92 ;
V_88 [ V_32 ] += V_92 ;
V_83 += V_92 ;
}
if ( V_70 -> V_93 [ V_32 ] & V_94 ) {
V_86 = true ;
if ( F_7 ( V_70 -> V_93 [ V_32 ] & V_95 ) ) {
V_39 = - V_45 ;
goto V_96;
}
} else if ( V_70 -> V_93 [ V_32 ] & V_95 ) {
V_86 = true ;
if ( F_7 ( V_80 ) ) {
V_39 = - V_45 ;
goto V_96;
}
V_80 = F_60 ( V_88 [ V_32 ] , V_90 [ V_32 ] ,
V_97 ) ;
if ( ! V_80 )
return - V_69 ;
} else {
if ( F_7 ( V_86 ) ) {
V_39 = - V_45 ;
goto V_96;
}
V_83 += V_90 [ V_32 ] ;
}
V_84 += V_70 -> V_19 [ V_32 ] ;
}
if ( F_61 ( V_83 > V_98 ,
L_6 ,
F_62 ( V_2 , V_70 -> V_27 ) , V_70 -> V_27 , V_83 ) ) {
V_39 = - V_45 ;
goto V_96;
}
F_63 ( & V_8 -> V_26 ) ;
if ( F_56 ( V_8 ) < ( ( V_70 -> V_72 & V_99 ) ? 2 : 1 ) ) {
F_64 ( & V_8 -> V_26 ) ;
F_17 ( V_2 , L_7 ) ;
F_65 ( V_2 -> V_43 ) ;
V_39 = - V_100 ;
goto V_96;
}
V_39 = F_23 ( V_8 , V_8 -> V_16 ) ;
V_79 = V_8 -> V_40 [ V_39 ] . V_70 ;
V_48 = & V_8 -> V_40 [ V_39 ] . V_31 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
if ( V_70 -> V_72 & V_101 )
V_48 -> V_102 = V_70 ;
V_79 -> V_103 . V_70 = F_66 ( V_70 -> V_27 ) ;
V_79 -> V_103 . V_87 = V_87 ;
V_79 -> V_103 . V_104 = F_67 ( V_70 -> V_27 ) ;
V_79 -> V_103 . V_105 =
F_9 ( V_84 - sizeof( struct V_91 ) ) ;
V_79 -> V_103 . V_106 = 0 ;
V_79 -> V_103 . V_71 =
F_9 ( F_49 ( V_4 -> V_78 ) |
F_50 ( V_8 -> V_16 ) ) ;
V_82 = sizeof( struct V_91 ) ;
V_83 = sizeof( struct V_91 ) ;
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
int V_92 ;
if ( ! V_70 -> V_19 [ V_32 ] )
continue;
if ( ! ( V_70 -> V_93 [ V_32 ] & ( V_94 |
V_95 ) ) ) {
V_92 = V_70 -> V_19 [ V_32 ] ;
memcpy ( ( T_2 * ) V_79 + V_82 , V_70 -> V_51 [ V_32 ] , V_92 ) ;
V_82 += V_92 ;
V_83 += V_92 ;
continue;
}
V_92 = F_68 ( int , V_98 - V_82 , V_70 -> V_19 [ V_32 ] ) ;
memcpy ( ( T_2 * ) V_79 + V_82 , V_70 -> V_51 [ V_32 ] , V_92 ) ;
V_82 += V_92 ;
if ( V_83 < V_58 ) {
V_92 = V_58 - V_83 ;
if ( V_92 > V_70 -> V_19 [ V_32 ] )
V_92 = V_70 -> V_19 [ V_32 ] ;
V_83 += V_92 ;
}
}
F_69 ( V_2 ,
L_8 ,
F_62 ( V_2 , V_70 -> V_27 ) , V_87 ,
V_79 -> V_50 . V_70 , F_15 ( V_79 -> V_50 . V_71 ) ,
V_84 , V_8 -> V_16 , V_39 , V_4 -> V_78 ) ;
V_85 = F_68 ( int , V_83 , V_58 ) ;
memcpy ( & V_8 -> V_57 [ V_39 ] , & V_79 -> V_50 , V_85 ) ;
F_26 ( V_2 , V_29 , F_29 ( V_8 , V_39 ) ,
V_85 ) ;
if ( V_83 > V_85 ) {
V_81 = F_33 ( V_2 -> V_34 ,
( ( T_2 * ) & V_79 -> V_50 ) + V_85 ,
V_83 - V_85 ,
V_36 ) ;
if ( F_35 ( V_2 -> V_34 , V_81 ) ) {
V_39 = - V_69 ;
F_16 ( V_2 , V_48 , V_29 ) ;
goto V_107;
}
F_26 ( V_2 , V_29 , V_81 ,
V_83 - V_85 ) ;
}
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
const void * V_51 = V_88 [ V_32 ] ;
if ( ! V_90 [ V_32 ] )
continue;
if ( ! ( V_70 -> V_93 [ V_32 ] & ( V_94 |
V_95 ) ) )
continue;
if ( V_70 -> V_93 [ V_32 ] & V_95 )
V_51 = V_80 ;
V_81 = F_33 ( V_2 -> V_34 , ( void * ) V_51 ,
V_90 [ V_32 ] , V_36 ) ;
if ( F_35 ( V_2 -> V_34 , V_81 ) ) {
V_39 = - V_69 ;
F_16 ( V_2 , V_48 , V_29 ) ;
goto V_107;
}
F_26 ( V_2 , V_29 , V_81 , V_90 [ V_32 ] ) ;
}
F_30 ( V_108 > sizeof( V_48 -> V_23 ) * V_109 ) ;
V_48 -> V_72 = V_70 -> V_72 ;
if ( F_70 ( V_8 -> V_40 [ V_39 ] . V_110 ) )
F_71 ( V_8 -> V_40 [ V_39 ] . V_110 ) ;
V_8 -> V_40 [ V_39 ] . V_110 = V_80 ;
F_72 ( V_2 -> V_34 , V_70 , V_84 , & V_79 -> V_103 ) ;
if ( V_8 -> V_38 == V_8 -> V_16 && V_8 -> V_73 )
F_52 ( & V_8 -> V_74 , V_75 + V_8 -> V_73 ) ;
F_73 ( & V_4 -> V_111 , V_72 ) ;
if ( ! ( V_70 -> V_72 & V_112 ) &&
! V_4 -> V_113 ) {
V_4 -> V_113 = true ;
F_53 ( V_2 , L_9 ) ;
F_54 ( V_2 ) ;
}
V_8 -> V_16 = F_55 ( V_8 -> V_16 ) ;
F_10 ( V_2 , V_8 ) ;
F_74 ( & V_4 -> V_111 , V_72 ) ;
V_107:
F_64 ( & V_8 -> V_26 ) ;
V_96:
if ( V_39 < 0 )
F_75 ( V_80 ) ;
return V_39 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_77 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_114 = F_62 ( V_2 , V_70 -> V_27 ) ;
struct V_9 * V_8 = V_4 -> V_8 [ V_4 -> V_78 ] ;
int V_115 ;
int V_116 ;
F_77 ( V_2 , L_10 , V_114 ) ;
if ( F_61 ( F_78 ( V_117 ,
& V_2 -> V_118 ) ,
L_11 , V_114 ) )
return - V_119 ;
F_77 ( V_2 , L_12 , V_114 ) ;
if ( F_79 ( & V_4 -> V_120 -> V_34 ) ) {
V_116 = F_80 ( V_4 -> V_121 ,
F_81 ( & V_4 -> V_120 -> V_34 ) ,
F_82 ( V_122 ) ) ;
if ( ! V_116 ) {
F_17 ( V_2 , L_13 ) ;
return - V_123 ;
}
}
V_115 = F_58 ( V_2 , V_70 ) ;
if ( V_115 < 0 ) {
V_116 = V_115 ;
F_83 ( V_117 , & V_2 -> V_118 ) ;
F_17 ( V_2 , L_14 ,
V_114 , V_116 ) ;
return V_116 ;
}
V_116 = F_80 ( V_4 -> V_124 ,
! F_44 ( V_117 ,
& V_2 -> V_118 ) ,
V_125 ) ;
if ( ! V_116 ) {
F_17 ( V_2 , L_15 ,
V_114 , F_84 ( V_125 ) ) ;
F_17 ( V_2 , L_16 ,
V_8 -> V_38 , V_8 -> V_16 ) ;
F_83 ( V_117 , & V_2 -> V_118 ) ;
F_77 ( V_2 , L_17 ,
V_114 ) ;
V_116 = - V_123 ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
goto V_126;
}
if ( F_44 ( V_127 , & V_2 -> V_118 ) ) {
F_17 ( V_2 , L_18 , V_114 ) ;
F_87 () ;
V_116 = - V_119 ;
goto V_126;
}
if ( ! ( V_70 -> V_72 & V_128 ) &&
F_44 ( V_129 , & V_2 -> V_118 ) ) {
F_88 ( V_2 , L_19 ) ;
V_116 = - V_130 ;
goto V_126;
}
if ( ( V_70 -> V_72 & V_101 ) && ! V_70 -> V_131 ) {
F_17 ( V_2 , L_20 , V_114 ) ;
V_116 = - V_119 ;
goto V_126;
}
return 0 ;
V_126:
if ( V_70 -> V_72 & V_101 ) {
V_8 -> V_40 [ V_115 ] . V_31 . V_72 &= ~ V_101 ;
}
if ( V_70 -> V_131 ) {
F_89 ( V_70 ) ;
V_70 -> V_131 = NULL ;
}
return V_116 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_77 * V_70 )
{
if ( ! ( V_70 -> V_72 & V_128 ) &&
F_44 ( V_129 , & V_2 -> V_118 ) ) {
F_88 ( V_2 , L_21 ,
V_70 -> V_27 ) ;
return - V_130 ;
}
if ( V_70 -> V_72 & V_99 ) {
int V_116 ;
if ( F_7 ( V_70 -> V_72 & V_101 ) )
return - V_45 ;
V_116 = F_58 ( V_2 , V_70 ) ;
if ( V_116 < 0 ) {
F_17 ( V_2 ,
L_14 ,
F_62 ( V_2 , V_70 -> V_27 ) , V_116 ) ;
return V_116 ;
}
return 0 ;
}
return F_76 ( V_2 , V_70 ) ;
}
void F_4 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_8 = V_4 -> V_8 [ V_5 ] ;
F_63 ( & V_8 -> V_26 ) ;
while ( V_8 -> V_16 != V_8 -> V_38 ) {
F_91 ( V_2 , L_22 ,
V_5 , V_8 -> V_38 ) ;
F_22 ( V_2 , V_8 ) ;
V_8 -> V_38 = F_55 ( V_8 -> V_38 ) ;
if ( V_8 -> V_38 == V_8 -> V_16 ) {
unsigned long V_72 ;
F_73 ( & V_4 -> V_111 , V_72 ) ;
if ( V_5 != V_4 -> V_78 ) {
F_53 ( V_2 , L_23 ,
V_8 -> V_27 ) ;
F_92 ( V_2 ) ;
} else if ( V_4 -> V_113 ) {
V_4 -> V_113 = false ;
F_53 ( V_2 ,
L_24 ) ;
F_92 ( V_2 ) ;
}
F_74 ( & V_4 -> V_111 , V_72 ) ;
}
}
F_64 ( & V_8 -> V_26 ) ;
F_93 ( V_2 , V_8 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_9 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_132 * V_34 = V_2 -> V_34 ;
if ( V_8 -> V_133 ) {
F_95 ( V_34 ,
V_4 -> V_134 * V_21 ,
V_8 -> V_133 , V_8 -> V_135 ) ;
F_95 ( V_34 ,
sizeof( * V_8 -> V_57 ) * V_8 -> V_136 ,
V_8 -> V_57 , V_8 -> V_137 ) ;
}
F_75 ( V_8 -> V_40 ) ;
F_96 ( V_2 , & V_8 -> V_14 ) ;
F_75 ( V_8 ) ;
}
static void F_97 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_8 = V_4 -> V_8 [ V_5 ] ;
int V_32 ;
if ( F_7 ( ! V_8 ) )
return;
F_4 ( V_2 , V_5 ) ;
if ( V_5 == V_4 -> V_78 )
for ( V_32 = 0 ; V_32 < V_8 -> V_136 ; V_32 ++ ) {
F_71 ( V_8 -> V_40 [ V_32 ] . V_70 ) ;
F_71 ( V_8 -> V_40 [ V_32 ] . V_110 ) ;
}
F_98 ( & V_8 -> V_74 ) ;
F_94 ( V_2 , V_8 ) ;
V_4 -> V_8 [ V_5 ] = NULL ;
F_83 ( V_5 , V_4 -> V_7 ) ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_138 * V_70 ,
int V_139 ,
unsigned int V_140 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_141 * V_142 ;
struct V_9 * V_8 ;
struct V_77 V_143 = {
. V_27 = V_139 ,
. V_19 = { sizeof( * V_70 ) } ,
. V_51 = { V_70 , } ,
. V_72 = V_101 ,
} ;
int V_116 , V_144 ;
V_8 = F_100 ( sizeof( * V_8 ) , V_145 ) ;
if ( ! V_8 )
return - V_69 ;
V_116 = F_101 ( V_2 , & V_8 -> V_14 ,
sizeof( struct V_12 ) ) ;
if ( V_116 ) {
F_17 ( V_2 , L_25 ) ;
F_75 ( V_8 ) ;
return - V_69 ;
}
V_116 = F_102 ( V_2 , V_8 , V_146 , false ) ;
if ( V_116 ) {
F_17 ( V_2 , L_26 ) ;
goto error;
}
V_116 = F_103 ( V_2 , V_8 , V_146 , false ) ;
if ( V_116 ) {
F_17 ( V_2 , L_27 ) ;
goto error;
}
V_8 -> V_73 = F_82 ( V_140 ) ;
V_70 -> V_147 = F_104 ( V_8 -> V_135 ) ;
V_70 -> V_148 = F_104 ( V_8 -> V_14 . V_149 ) ;
V_70 -> V_150 = F_105 ( F_106 ( V_21 ) ) ;
V_116 = F_107 ( V_2 , & V_143 ) ;
if ( V_116 )
goto error;
if ( F_7 ( F_108 ( V_143 . V_131 ) != sizeof( * V_142 ) ) ) {
V_116 = - V_45 ;
goto V_151;
}
V_142 = ( void * ) V_143 . V_131 -> V_51 ;
V_144 = F_15 ( V_142 -> V_152 ) ;
if ( V_144 > F_3 ( V_4 -> V_8 ) ) {
F_43 ( 1 , L_28 , V_144 ) ;
V_116 = - V_119 ;
goto V_151;
}
if ( F_78 ( V_144 , V_4 -> V_7 ) ) {
F_43 ( 1 , L_29 , V_144 ) ;
V_116 = - V_119 ;
goto V_151;
}
V_8 -> V_27 = V_144 ;
V_4 -> V_8 [ V_144 ] = V_8 ;
V_8 -> V_38 = F_15 ( V_142 -> V_153 ) ;
V_8 -> V_16 = F_15 ( V_142 -> V_153 ) ;
F_109 ( V_2 , V_28 ,
( V_8 -> V_16 ) | ( V_144 << 16 ) ) ;
F_110 ( V_2 , L_30 , V_144 ) ;
F_89 ( & V_143 ) ;
return V_144 ;
V_151:
F_89 ( & V_143 ) ;
error:
F_94 ( V_2 , V_8 ) ;
return V_116 ;
}
void F_111 ( struct V_1 * V_2 , int V_154 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_112 ( V_154 , V_4 -> V_7 ) ) {
F_43 ( F_44 ( V_155 , & V_2 -> V_118 ) ,
L_31 , V_154 ) ;
return;
}
F_4 ( V_2 , V_154 ) ;
F_110 ( V_2 , L_32 , V_154 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_32 ;
memset ( V_4 -> V_7 , 0 , sizeof( V_4 -> V_7 ) ) ;
for ( V_32 = 0 ; V_32 < F_3 ( V_4 -> V_8 ) ; V_32 ++ ) {
if ( ! V_4 -> V_8 [ V_32 ] )
continue;
F_97 ( V_2 , V_32 ) ;
}
}
int F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_78 ;
int V_5 = V_4 -> V_78 , V_116 ;
if ( ! V_4 -> V_8 [ V_5 ] ) {
V_78 = F_100 ( sizeof( * V_78 ) , V_145 ) ;
if ( ! V_78 ) {
F_17 ( V_2 , L_33 ) ;
return - V_69 ;
}
V_4 -> V_8 [ V_5 ] = V_78 ;
V_116 = F_102 ( V_2 , V_78 , V_156 , true ) ;
if ( V_116 ) {
F_17 ( V_2 , L_34 , V_5 ) ;
goto error;
}
} else {
V_78 = V_4 -> V_8 [ V_5 ] ;
}
V_116 = F_103 ( V_2 , V_78 , V_156 , true ) ;
if ( V_116 ) {
F_17 ( V_2 , L_35 , V_5 ) ;
goto error;
}
V_4 -> V_8 [ V_5 ] -> V_27 = V_5 ;
F_115 ( V_5 , V_4 -> V_7 ) ;
return 0 ;
error:
F_113 ( V_2 ) ;
return V_116 ;
}
