int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 ) ;
F_2 ( & V_2 -> V_9 ) ;
V_2 -> V_10 = F_3 ( V_4 -> V_11 ,
sizeof( struct V_12 * ) ,
V_13 ) ;
if ( ! V_2 -> V_10 )
return - V_14 ;
if ( ! F_4 ( V_4 -> V_15 , V_16 ) ) {
V_2 -> V_17 = 0 ;
V_2 -> V_18 = F_3 ( V_4 -> V_11 ,
sizeof( * V_2 -> V_18 ) ,
V_13 ) ;
if ( ! V_2 -> V_18 ) {
F_5 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
return - V_14 ;
}
V_7 = F_6 ( V_2 , V_2 -> V_19 , & V_20 ,
V_6 -> V_21 -> V_22 ,
& V_2 -> V_23 ) ;
if ( V_7 ) {
F_7 ( V_6 ,
L_1 ,
V_7 ) ;
V_7 = 0 ;
}
}
F_8 ( & V_2 -> V_8 ) ;
if ( V_4 -> V_24 && V_2 -> V_23 ) {
T_1 V_25 ;
V_2 -> V_26 = V_4 -> V_11 / V_4 -> V_24 ;
V_25 = V_4 -> V_11 % V_4 -> V_24 ;
if ( V_25 && V_2 -> V_27 < V_25 )
V_2 -> V_26 ++ ;
} else {
V_2 -> V_26 = V_4 -> V_11 ;
}
F_9 ( & V_2 -> V_8 ) ;
return V_7 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_23 ) {
F_11 ( V_2 -> V_23 ) ;
} else {
if ( ! F_12 ( V_4 -> V_28 ) )
F_13 ( V_4 , & V_4 -> V_28 , V_2 ) ;
if ( ! F_12 ( V_4 -> V_29 ) )
F_13 ( V_4 , & V_4 -> V_29 , V_2 ) ;
}
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
F_5 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int V_34 ,
unsigned int V_35 ,
bool V_36 )
{
struct V_37 * * V_38 ;
struct V_5 * V_6 = V_2 -> V_4 -> V_6 ;
if ( V_36 ) {
F_15 ( V_6 -> V_39 , V_33 -> V_40 ,
V_33 -> V_41 . V_42 , V_43 ) ;
V_38 = & V_33 -> V_38 [ V_34 ] ;
} else {
V_38 = & V_31 -> V_38 [ V_34 ] ;
}
F_16 ( V_2 -> V_19 , V_38 , V_35 , V_36 ) ;
V_2 -> V_44 -= V_35 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
int V_45 ;
unsigned int V_35 ;
unsigned long V_46 = V_31 -> V_46 ;
struct V_37 * * V_38 = NULL ;
struct V_5 * V_6 = V_2 -> V_4 -> V_6 ;
V_35 = F_18 ( V_46 , V_31 -> V_47 ) ;
if ( ! V_35 )
return - V_48 ;
if ( V_35 > V_2 -> V_4 -> V_11 ) {
F_19 ( V_6 , L_2 ) ;
return - V_48 ;
}
if ( ! F_20 ( V_49 , ( void V_50 * ) V_46 ,
V_35 * V_51 ) ) {
F_19 ( V_6 , L_3 ,
( void * ) V_46 , V_35 ) ;
return - V_52 ;
}
V_38 = F_3 ( V_35 , sizeof( * V_38 ) , V_13 ) ;
if ( ! V_38 )
return - V_14 ;
if ( ! F_21 ( V_6 , V_2 -> V_19 , V_2 -> V_44 , V_35 ) ) {
F_5 ( V_38 ) ;
return - V_14 ;
}
V_45 = F_22 ( V_2 -> V_19 , V_46 , V_35 , true , V_38 ) ;
if ( V_45 <= 0 ) {
F_5 ( V_38 ) ;
return V_45 ;
}
V_31 -> V_38 = V_38 ;
V_31 -> V_35 = V_35 ;
V_2 -> V_44 += V_45 ;
return V_45 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
int V_7 = 0 , V_55 = 0 , V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_56 , V_57 = 0 , V_58 ,
V_59 = 0 , V_36 , V_60 = 0 ;
T_2 * V_61 = NULL ;
struct V_30 * V_31 ;
V_31 = F_24 ( sizeof( * V_31 ) , V_13 ) ;
if ( ! V_31 )
return - V_14 ;
V_31 -> V_46 = V_54 -> V_46 ;
V_31 -> V_47 = V_54 -> V_47 ;
V_31 -> V_62 = F_3 ( V_4 -> V_11 , sizeof( * V_31 -> V_62 ) ,
V_13 ) ;
if ( ! V_31 -> V_62 ) {
F_5 ( V_31 ) ;
return - V_14 ;
}
V_45 = F_17 ( V_2 , V_31 ) ;
if ( V_45 <= 0 ) {
F_5 ( V_31 -> V_62 ) ;
F_5 ( V_31 ) ;
return V_45 ;
}
V_31 -> V_63 = F_25 ( V_31 , V_45 ) ;
F_8 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_64 + V_31 -> V_63 > V_2 -> V_26 )
V_58 = V_2 -> V_26 - V_2 -> V_64 ;
else
V_58 = V_31 -> V_63 ;
F_9 ( & V_2 -> V_8 ) ;
if ( ! V_58 )
goto V_65;
V_56 = V_58 / V_6 -> V_66 . V_67 ;
V_61 = F_3 ( V_58 , sizeof( * V_61 ) , V_13 ) ;
if ( ! V_61 ) {
V_7 = - V_14 ;
goto V_68;
}
V_59 = 0 ;
F_26 ( & V_4 -> V_69 ) ;
while ( V_56 && V_4 -> V_70 . V_71 ) {
struct V_72 * V_73 =
F_27 ( & V_4 -> V_70 ) ;
V_7 = F_28 ( V_2 , V_31 , V_73 ,
V_57 , V_6 -> V_66 . V_67 ,
V_61 , & V_59 , & V_36 ) ;
if ( V_7 <= 0 ) {
F_29 ( V_73 , & V_4 -> V_70 ) ;
F_30 ( V_74 ,
L_4 , V_7 ) ;
goto V_75;
}
F_29 ( V_73 , & V_4 -> V_28 ) ;
V_56 -- ;
V_57 += V_7 ;
V_60 += V_36 ;
}
while ( V_57 < V_58 ) {
struct V_72 * V_73 , * V_76 ;
if ( ! V_4 -> V_29 . V_71 || V_55 ) {
if ( ! V_4 -> V_70 . V_71 )
goto V_75;
V_73 = F_27 ( & V_4 -> V_70 ) ;
F_29 ( V_73 , & V_4 -> V_29 ) ;
V_55 = 0 ;
}
F_31 (grp, ptr, &uctxt->tid_used_list.list,
list) {
unsigned V_77 = F_32 ( unsigned , V_58 - V_57 ,
V_73 -> V_78 - V_73 -> V_79 ) ;
V_7 = F_28 ( V_2 , V_31 , V_73 ,
V_57 , V_77 , V_61 ,
& V_59 , & V_36 ) ;
if ( V_7 < 0 ) {
F_30 ( V_74 ,
L_5 ,
V_7 ) ;
V_7 = - V_52 ;
goto V_75;
} else if ( V_7 > 0 ) {
if ( V_73 -> V_79 == V_73 -> V_78 )
F_33 ( V_73 ,
& V_4 -> V_29 ,
& V_4 -> V_28 ) ;
V_57 += V_7 ;
V_60 += V_36 ;
V_55 = 0 ;
if ( V_57 >= V_58 )
break;
} else if ( F_34 ( V_7 == 0 ) ) {
V_55 = 1 ;
}
}
}
V_75:
F_35 ( & V_4 -> V_69 ) ;
V_68:
F_30 ( V_74 , L_6 , V_59 ,
V_60 , V_7 ) ;
if ( V_59 ) {
F_8 ( & V_2 -> V_8 ) ;
V_2 -> V_64 += V_59 ;
F_9 ( & V_2 -> V_8 ) ;
V_54 -> V_80 = V_59 ;
V_54 -> V_47 = V_60 * V_51 ;
if ( F_36 ( ( void V_50 * ) ( unsigned long ) V_54 -> V_61 ,
V_61 , sizeof( V_61 [ 0 ] ) * V_59 ) ) {
V_54 -> V_61 = ( unsigned long ) & V_61 ;
F_37 ( V_2 , V_54 ) ;
V_54 -> V_61 = 0 ;
V_7 = - V_52 ;
goto V_65;
}
}
if ( V_60 != V_45 )
F_14 ( V_2 , V_31 , NULL , V_60 ,
( V_45 - V_60 ) , false ) ;
V_65:
F_5 ( V_31 -> V_62 ) ;
F_5 ( V_61 ) ;
F_5 ( V_31 -> V_38 ) ;
F_5 ( V_31 ) ;
return V_7 > 0 ? 0 : V_7 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
int V_7 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 * V_81 ;
unsigned V_59 ;
if ( F_38 ( V_54 -> V_80 > V_2 -> V_64 ) )
return - V_48 ;
V_81 = F_39 ( ( void V_50 * ) ( unsigned long ) V_54 -> V_61 ,
sizeof( V_81 [ 0 ] ) * V_54 -> V_80 ) ;
if ( F_40 ( V_81 ) )
return F_41 ( V_81 ) ;
F_26 ( & V_4 -> V_69 ) ;
for ( V_59 = 0 ; V_59 < V_54 -> V_80 ; V_59 ++ ) {
V_7 = F_42 ( V_2 , V_81 [ V_59 ] , NULL ) ;
if ( V_7 ) {
F_30 ( V_74 , L_7 ,
V_7 ) ;
break;
}
}
F_8 ( & V_2 -> V_8 ) ;
V_2 -> V_64 -= V_59 ;
F_9 ( & V_2 -> V_8 ) ;
V_54 -> V_80 = V_59 ;
F_35 ( & V_4 -> V_69 ) ;
F_5 ( V_81 ) ;
return V_7 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long * V_82 = V_4 -> V_6 -> V_83 +
( ( ( V_4 -> V_84 - V_4 -> V_6 -> V_85 ) *
V_86 ) + V_2 -> V_27 ) ;
T_2 * V_87 ;
int V_7 = 0 ;
if ( ! V_2 -> V_18 )
return - V_48 ;
V_87 = F_3 ( V_4 -> V_11 , sizeof( * V_87 ) , V_13 ) ;
if ( ! V_87 )
return - V_52 ;
F_8 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_17 ) {
memcpy ( V_87 , V_2 -> V_18 , sizeof( * V_87 ) *
V_2 -> V_17 ) ;
memset ( V_2 -> V_18 , 0 , sizeof( * V_2 -> V_18 ) *
V_2 -> V_17 ) ;
V_54 -> V_80 = V_2 -> V_17 ;
V_2 -> V_17 = 0 ;
F_44 ( V_88 , V_82 ) ;
} else {
V_54 -> V_80 = 0 ;
}
F_9 ( & V_2 -> V_9 ) ;
if ( V_54 -> V_80 ) {
if ( F_36 ( ( void V_50 * ) V_54 -> V_61 ,
V_87 , sizeof( * V_87 ) * V_54 -> V_80 ) )
V_7 = - V_52 ;
}
F_5 ( V_87 ) ;
return V_7 ;
}
static T_2 F_25 ( struct V_30 * V_31 , unsigned int V_35 )
{
unsigned V_89 , V_57 , V_90 = 0 , V_91 ;
unsigned long V_92 , V_93 ;
struct V_37 * * V_38 = V_31 -> V_38 ;
struct V_94 * V_95 = V_31 -> V_62 ;
if ( ! V_35 )
return 0 ;
V_92 = F_45 ( V_38 [ 0 ] ) ;
for ( V_57 = 0 , V_89 = 1 , V_91 = 1 ; V_91 <= V_35 ; V_91 ++ ) {
V_93 = V_91 < V_35 ? F_45 ( V_38 [ V_91 ] ) : 0 ;
if ( V_93 != ++ V_92 ) {
while ( V_89 ) {
int V_96 = V_89 ;
T_2 V_97 = V_89 * V_51 ;
if ( V_97 > V_98 )
V_96 =
V_98 >>
V_99 ;
else if ( ! F_46 ( V_97 ) )
V_96 =
F_47 ( V_97 ) >>
V_99 ;
V_95 [ V_90 ] . V_34 = V_57 ;
V_95 [ V_90 ] . V_71 = V_96 ;
V_89 -= V_96 ;
V_57 += V_96 ;
V_90 ++ ;
}
V_57 = V_91 ;
V_89 = 1 ;
V_92 = V_93 ;
} else {
V_89 ++ ;
}
}
return V_90 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_30 * V_100 ,
struct V_72 * V_73 ,
unsigned int V_101 , T_1 V_71 ,
T_2 * V_61 , unsigned int * V_59 ,
unsigned int * V_102 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_34 ;
T_2 V_81 = 0 , V_103 , V_104 = 0 ;
int V_36 = 0 ;
if ( V_71 > V_73 -> V_78 )
return - V_48 ;
for ( V_34 = 0 ; V_34 < V_73 -> V_78 ; V_34 ++ ) {
if ( ! ( V_73 -> V_105 & ( 1 << V_34 ) ) ) {
V_104 = V_34 ;
break;
}
F_48 ( V_6 , V_73 -> V_106 + V_34 ) ;
}
V_34 = 0 ;
while ( V_34 < V_71 ) {
T_1 V_35 , V_57 , V_107 = V_101 + V_34 ;
int V_7 = 0 ;
if ( V_104 >= V_73 -> V_78 ) {
break;
} else if ( V_73 -> V_105 & ( 1 << V_104 ) ) {
F_48 ( V_6 , V_73 -> V_106 + V_104 ) ;
V_104 ++ ;
continue;
}
V_103 = V_73 -> V_106 + V_104 ;
V_35 = V_100 -> V_62 [ V_107 ] . V_71 ;
V_57 = V_100 -> V_62 [ V_107 ] . V_34 ;
V_7 = F_49 ( V_2 , V_100 ,
V_103 , V_73 , V_57 ,
V_35 ) ;
if ( V_7 )
return V_7 ;
V_36 += V_35 ;
V_81 = F_50 ( V_103 - V_4 -> V_108 ) |
F_51 ( V_109 , V_35 ) ;
V_61 [ ( * V_59 ) ++ ] = V_81 ;
V_73 -> V_79 ++ ;
V_73 -> V_105 |= 1 << V_104 ++ ;
V_34 ++ ;
}
for (; V_104 < V_73 -> V_78 ; V_104 ++ )
F_48 ( V_6 , V_73 -> V_106 + V_104 ) ;
* V_102 = V_36 ;
return V_34 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_30 * V_100 ,
T_2 V_103 , struct V_72 * V_73 ,
T_1 V_57 , unsigned int V_35 )
{
int V_7 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_3 V_110 ;
struct V_37 * * V_38 = V_100 -> V_38 + V_57 ;
V_33 = F_24 ( sizeof( * V_33 ) + ( sizeof( struct V_37 * ) * V_35 ) ,
V_13 ) ;
if ( ! V_33 )
return - V_14 ;
V_110 = F_52 ( V_6 -> V_39 ,
F_53 ( F_54 ( V_38 [ 0 ] ) ) ,
V_35 * V_51 , V_43 ) ;
if ( F_55 ( & V_6 -> V_39 -> V_111 , V_110 ) ) {
F_19 ( V_6 , L_8 ,
V_110 ) ;
F_5 ( V_33 ) ;
return - V_52 ;
}
V_33 -> V_41 . V_112 = V_100 -> V_46 + ( V_57 * V_51 ) ;
V_33 -> V_41 . V_42 = V_35 * V_51 ;
V_33 -> V_110 = F_54 ( V_38 [ 0 ] ) ;
V_33 -> V_35 = V_35 ;
V_33 -> V_103 = V_103 ;
V_33 -> V_40 = V_110 ;
V_33 -> V_73 = V_73 ;
V_33 -> V_113 = false ;
memcpy ( V_33 -> V_38 , V_38 , sizeof( struct V_37 * ) * V_35 ) ;
if ( ! V_2 -> V_23 )
V_7 = F_56 ( V_2 , & V_33 -> V_41 ) ;
else
V_7 = F_57 ( V_2 -> V_23 , & V_33 -> V_41 ) ;
if ( V_7 ) {
F_30 ( V_74 , L_9 ,
V_33 -> V_103 , V_33 -> V_41 . V_112 , V_33 -> V_110 , V_7 ) ;
F_15 ( V_6 -> V_39 , V_110 , V_35 * V_51 ,
V_43 ) ;
F_5 ( V_33 ) ;
return - V_52 ;
}
F_58 ( V_6 , V_103 , V_114 , V_110 , F_59 ( V_35 ) + 1 ) ;
F_60 ( V_4 -> V_84 , V_2 -> V_27 , V_103 , V_35 ,
V_33 -> V_41 . V_112 , V_33 -> V_110 , V_110 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_2 V_81 ,
struct V_72 * * V_73 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_32 * V_33 ;
T_4 V_115 = F_61 ( V_81 , V_116 ) ;
T_2 V_59 = F_61 ( V_81 , V_117 ) << 1 , V_103 ;
if ( V_59 >= V_4 -> V_11 ) {
F_19 ( V_6 , L_10 ,
V_59 , V_4 -> V_84 ) ;
return - V_48 ;
}
if ( V_115 == 0x3 )
return - V_48 ;
V_103 = V_59 + ( V_115 - 1 ) ;
V_33 = V_2 -> V_10 [ V_103 ] ;
if ( ! V_33 || V_33 -> V_103 != ( V_4 -> V_108 + V_103 ) )
return - V_118 ;
if ( V_73 )
* V_73 = V_33 -> V_73 ;
if ( ! V_2 -> V_23 )
F_62 ( V_2 , V_33 ) ;
else
F_63 ( V_2 -> V_23 , & V_33 -> V_41 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_65 ( V_4 -> V_84 , V_2 -> V_27 , V_33 -> V_103 ,
V_33 -> V_35 , V_33 -> V_41 . V_112 , V_33 -> V_110 ,
V_33 -> V_40 ) ;
F_58 ( V_6 , V_33 -> V_103 , V_119 , 0 , 0 ) ;
F_14 ( V_2 , NULL , V_33 , 0 , V_33 -> V_35 , true ) ;
V_33 -> V_73 -> V_79 -- ;
V_33 -> V_73 -> V_105 &= ~ ( 1 << ( V_33 -> V_103 - V_33 -> V_73 -> V_106 ) ) ;
if ( V_33 -> V_73 -> V_79 == V_33 -> V_73 -> V_78 - 1 )
F_33 ( V_33 -> V_73 , & V_4 -> V_28 ,
& V_4 -> V_29 ) ;
else if ( ! V_33 -> V_73 -> V_79 )
F_33 ( V_33 -> V_73 , & V_4 -> V_29 ,
& V_4 -> V_70 ) ;
F_5 ( V_33 ) ;
}
static void F_13 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
struct V_1 * V_2 )
{
struct V_72 * V_73 , * V_76 ;
int V_91 ;
F_31 (grp, ptr, &set->list, list) {
F_66 ( & V_73 -> V_95 ) ;
for ( V_91 = 0 ; V_91 < V_73 -> V_78 ; V_91 ++ ) {
if ( V_73 -> V_105 & ( 1 << V_91 ) ) {
T_1 V_103 = V_73 -> V_106 + V_91 ;
struct V_32 * V_33 ;
V_33 = V_2 -> V_10 [ V_103 -
V_4 -> V_108 ] ;
if ( ! V_33 || V_33 -> V_103 != V_103 )
continue;
F_62 ( V_2 , V_33 ) ;
}
}
}
}
static int F_67 ( void * V_122 , struct V_123 * V_124 )
{
struct V_1 * V_125 = V_122 ;
struct V_3 * V_4 = V_125 -> V_4 ;
struct V_32 * V_33 =
F_68 ( V_124 , struct V_32 , V_41 ) ;
if ( V_33 -> V_113 )
return 0 ;
F_69 ( V_4 -> V_84 , V_125 -> V_27 , V_33 -> V_41 . V_112 ,
V_33 -> V_103 , V_33 -> V_35 , V_33 -> V_40 ) ;
V_33 -> V_113 = true ;
F_8 ( & V_125 -> V_9 ) ;
if ( V_125 -> V_17 < V_4 -> V_11 ) {
V_125 -> V_18 [ V_125 -> V_17 ] =
F_50 ( V_33 -> V_103 - V_4 -> V_108 ) ;
V_125 -> V_18 [ V_125 -> V_17 ] |=
F_51 ( V_109 , V_33 -> V_35 ) ;
if ( ! V_125 -> V_17 ) {
unsigned long * V_82 ;
V_82 = V_4 -> V_6 -> V_83 +
( ( ( V_4 -> V_84 - V_4 -> V_6 -> V_85 ) *
V_86 ) + V_125 -> V_27 ) ;
F_70 ( V_88 , V_82 ) ;
}
V_125 -> V_17 ++ ;
}
F_9 ( & V_125 -> V_9 ) ;
return 0 ;
}
static int F_56 ( void * V_122 , struct V_123 * V_33 )
{
struct V_1 * V_125 = V_122 ;
struct V_32 * V_126 =
F_68 ( V_33 , struct V_32 , V_41 ) ;
T_2 V_106 = V_125 -> V_4 -> V_108 ;
V_125 -> V_10 [ V_126 -> V_103 - V_106 ] = V_126 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_125 ,
struct V_32 * V_126 )
{
T_2 V_106 = V_125 -> V_4 -> V_108 ;
V_125 -> V_10 [ V_126 -> V_103 - V_106 ] = NULL ;
F_64 ( V_125 , V_126 ) ;
}
static void F_71 ( void * V_122 , struct V_123 * V_33 )
{
struct V_1 * V_125 = V_122 ;
struct V_32 * V_126 =
F_68 ( V_33 , struct V_32 , V_41 ) ;
F_62 ( V_125 , V_126 ) ;
}
