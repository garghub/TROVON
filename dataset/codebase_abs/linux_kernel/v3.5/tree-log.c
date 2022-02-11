static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
int V_6 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 ) {
if ( ! V_4 -> V_9 ) {
V_4 -> V_9 = V_10 -> V_11 ;
V_4 -> V_12 = false ;
} else if ( V_4 -> V_9 != V_10 -> V_11 ) {
V_4 -> V_12 = true ;
}
V_4 -> V_13 ++ ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
V_4 -> V_12 = false ;
V_4 -> V_9 = V_10 -> V_11 ;
F_2 ( & V_4 -> V_15 -> V_16 ) ;
if ( ! V_4 -> V_15 -> V_17 ) {
V_5 = F_5 ( V_2 , V_4 -> V_15 ) ;
if ( V_5 )
V_6 = V_5 ;
}
if ( V_6 == 0 && ! V_4 -> V_8 ) {
V_5 = F_6 ( V_2 , V_4 ) ;
if ( V_5 )
V_6 = V_5 ;
}
F_4 ( & V_4 -> V_15 -> V_16 ) ;
V_4 -> V_13 ++ ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 = - V_18 ;
F_8 () ;
if ( ! V_4 -> V_8 )
return - V_18 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 ) {
V_5 = 0 ;
F_3 ( & V_4 -> V_14 ) ;
}
F_4 ( & V_4 -> V_7 ) ;
return V_5 ;
}
int F_9 ( struct V_3 * V_4 )
{
int V_5 = - V_18 ;
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_5 ;
}
void F_10 ( struct V_3 * V_4 )
{
if ( F_11 ( & V_4 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_4 -> V_19 ) )
F_13 ( & V_4 -> V_19 ) ;
}
}
static int F_14 ( struct V_3 * log ,
struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
if ( V_23 -> V_25 )
F_15 ( V_23 -> V_2 ,
log -> V_15 -> V_26 ,
V_21 -> V_27 , V_21 -> V_28 ) ;
if ( F_16 ( V_21 , V_24 , 0 ) ) {
if ( V_23 -> V_29 )
F_17 ( V_21 ) ;
if ( V_23 -> V_30 )
F_18 ( V_21 ) ;
}
return 0 ;
}
static T_2 int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_5 ;
T_3 V_36 ;
T_1 V_37 = 0 ;
int V_38 = 0 ;
unsigned long V_39 ;
unsigned long V_40 ;
int V_41 = 0 ;
if ( V_4 -> V_42 . V_43 != V_44 )
V_41 = 1 ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_39 = F_21 ( V_21 , V_33 ) ;
V_5 = F_22 ( NULL , V_4 , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 == 0 ) {
char * V_45 ;
char * V_46 ;
T_3 V_47 = F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_47 != V_36 )
goto V_50;
if ( V_36 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
V_46 = F_24 ( V_36 , V_51 ) ;
V_45 = F_24 ( V_36 , V_51 ) ;
if ( ! V_46 || ! V_45 ) {
F_23 ( V_32 ) ;
F_25 ( V_46 ) ;
F_25 ( V_45 ) ;
return - V_52 ;
}
F_26 ( V_21 , V_45 , V_39 , V_36 ) ;
V_40 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
F_26 ( V_32 -> V_48 [ 0 ] , V_46 , V_40 ,
V_36 ) ;
V_5 = memcmp ( V_46 , V_45 , V_36 ) ;
F_25 ( V_46 ) ;
F_25 ( V_45 ) ;
if ( V_5 == 0 ) {
F_23 ( V_32 ) ;
return 0 ;
}
}
V_50:
F_23 ( V_32 ) ;
V_5 = F_27 ( V_2 , V_4 , V_32 ,
V_35 , V_36 ) ;
if ( V_5 == - V_53 ) {
T_3 V_54 ;
V_54 = F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_54 > V_36 )
F_28 ( V_2 , V_4 , V_32 , V_36 , 1 ) ;
else if ( V_54 < V_36 )
F_29 ( V_2 , V_4 , V_32 ,
V_36 - V_54 ) ;
} else if ( V_5 ) {
return V_5 ;
}
V_40 = F_21 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_35 -> type == V_55 && V_5 == - V_53 ) {
struct V_56 * V_57 ;
struct V_56 * V_58 ;
V_57 = (struct V_56 * ) V_39 ;
V_58 = (struct V_56 * ) V_40 ;
if ( F_30 ( V_21 , V_57 ) == 0 )
goto V_59;
if ( V_41 &&
F_31 ( F_32 ( V_21 , V_57 ) ) &&
F_31 ( F_32 ( V_32 -> V_48 [ 0 ] , V_58 ) ) ) {
V_38 = 1 ;
V_37 = F_33 ( V_32 -> V_48 [ 0 ] ,
V_58 ) ;
}
}
F_34 ( V_32 -> V_48 [ 0 ] , V_21 , V_40 ,
V_39 , V_36 ) ;
if ( V_38 ) {
struct V_56 * V_58 ;
V_58 = (struct V_56 * ) V_40 ;
F_35 ( V_32 -> V_48 [ 0 ] , V_58 , V_37 ) ;
}
if ( V_35 -> type == V_55 ) {
struct V_56 * V_58 ;
V_58 = (struct V_56 * ) V_40 ;
if ( F_30 ( V_32 -> V_48 [ 0 ] , V_58 ) == 0 ) {
F_36 ( V_32 -> V_48 [ 0 ] , V_58 ,
V_2 -> V_60 ) ;
}
}
V_59:
F_37 ( V_32 -> V_48 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
T_2 int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_61 ;
T_1 V_62 = V_4 -> V_63 - 1 ;
T_1 V_64 ;
T_1 V_65 ;
T_1 V_27 = V_35 -> V_66 ;
T_1 V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_70 = NULL ;
unsigned long V_71 ;
int V_5 = 0 ;
V_69 = F_39 ( V_21 , V_33 , struct V_68 ) ;
V_61 = F_40 ( V_21 , V_69 ) ;
if ( V_61 == V_72 ||
V_61 == V_73 )
V_64 = V_27 + F_41 ( V_21 , V_69 ) ;
else if ( V_61 == V_74 ) {
V_71 = F_42 ( V_21 , V_69 ) ;
V_64 = ( V_27 + V_71 + V_62 ) & ~ V_62 ;
} else {
V_5 = 0 ;
goto V_75;
}
V_70 = F_43 ( V_4 , V_35 -> V_43 ) ;
if ( ! V_70 ) {
V_5 = - V_76 ;
goto V_75;
}
V_5 = F_44 ( V_2 , V_4 , V_32 , F_45 ( V_70 ) ,
V_27 , 0 ) ;
if ( V_5 == 0 &&
( V_61 == V_72 ||
V_61 == V_73 ) ) {
struct V_68 V_77 ;
struct V_68 V_78 ;
struct V_68 * V_79 ;
struct V_20 * V_80 ;
V_80 = V_32 -> V_48 [ 0 ] ;
V_79 = F_39 ( V_80 , V_32 -> V_49 [ 0 ] ,
struct V_68 ) ;
F_26 ( V_21 , & V_77 , ( unsigned long ) V_69 ,
sizeof( V_77 ) ) ;
F_26 ( V_80 , & V_78 , ( unsigned long ) V_79 ,
sizeof( V_78 ) ) ;
if ( memcmp ( & V_77 , & V_78 , sizeof( V_77 ) ) == 0 ) {
F_23 ( V_32 ) ;
goto V_75;
}
}
F_23 ( V_32 ) ;
V_67 = F_46 ( V_70 ) ;
V_5 = F_47 ( V_2 , V_70 , V_27 , V_64 ,
& V_65 , 1 ) ;
F_48 ( V_5 ) ;
if ( V_61 == V_72 ||
V_61 == V_73 ) {
T_1 V_66 ;
unsigned long V_81 ;
struct V_34 V_82 ;
V_5 = F_27 ( V_2 , V_4 , V_32 , V_35 ,
sizeof( * V_69 ) ) ;
F_48 ( V_5 ) ;
V_81 = F_21 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
F_34 ( V_32 -> V_48 [ 0 ] , V_21 , V_81 ,
( unsigned long ) V_69 , sizeof( * V_69 ) ) ;
V_82 . V_43 = F_49 ( V_21 , V_69 ) ;
V_82 . V_66 = F_50 ( V_21 , V_69 ) ;
V_82 . type = V_83 ;
V_66 = V_35 -> V_66 - F_51 ( V_21 , V_69 ) ;
if ( V_82 . V_43 > 0 ) {
T_1 V_84 ;
T_1 V_85 ;
F_52 ( V_86 ) ;
V_5 = F_53 ( V_4 , V_82 . V_43 ,
V_82 . V_66 ) ;
if ( V_5 == 0 ) {
V_5 = F_54 ( V_2 , V_4 ,
V_82 . V_43 , V_82 . V_66 ,
0 , V_4 -> V_42 . V_43 ,
V_35 -> V_43 , V_66 , 0 ) ;
F_48 ( V_5 ) ;
} else {
V_5 = F_55 ( V_2 ,
V_4 , V_4 -> V_42 . V_43 ,
V_35 -> V_43 , V_66 , & V_82 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
if ( F_56 ( V_21 , V_69 ) ) {
V_84 = V_82 . V_43 ;
V_85 = V_84 + V_82 . V_66 ;
} else {
V_84 = V_82 . V_43 +
F_51 ( V_21 , V_69 ) ;
V_85 = V_84 +
F_41 ( V_21 , V_69 ) ;
}
V_5 = F_57 ( V_4 -> V_8 ,
V_84 , V_85 - 1 ,
& V_86 , 0 ) ;
F_48 ( V_5 ) ;
while ( ! F_58 ( & V_86 ) ) {
struct V_87 * V_88 ;
V_88 = F_59 ( V_86 . V_89 ,
struct V_87 ,
V_90 ) ;
V_5 = F_60 ( V_2 ,
V_4 -> V_15 -> V_91 ,
V_88 ) ;
F_48 ( V_5 ) ;
F_61 ( & V_88 -> V_90 ) ;
F_25 ( V_88 ) ;
}
} else {
F_23 ( V_32 ) ;
}
} else if ( V_61 == V_74 ) {
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_48 ( V_5 ) ;
}
F_62 ( V_70 , V_67 ) ;
F_63 ( V_2 , V_4 , V_70 ) ;
V_75:
if ( V_70 )
F_64 ( V_70 ) ;
return V_5 ;
}
static T_2 int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_70 * V_92 ,
struct V_93 * V_94 )
{
struct V_70 * V_70 ;
char * V_95 ;
int V_96 ;
struct V_20 * V_80 ;
struct V_34 V_97 ;
int V_5 ;
V_80 = V_32 -> V_48 [ 0 ] ;
F_66 ( V_80 , V_94 , & V_97 ) ;
V_96 = F_67 ( V_80 , V_94 ) ;
V_95 = F_24 ( V_96 , V_51 ) ;
if ( ! V_95 )
return - V_52 ;
F_26 ( V_80 , V_95 , ( unsigned long ) ( V_94 + 1 ) , V_96 ) ;
F_23 ( V_32 ) ;
V_70 = F_43 ( V_4 , V_97 . V_43 ) ;
if ( ! V_70 ) {
F_25 ( V_95 ) ;
return - V_76 ;
}
V_5 = F_68 ( V_2 , V_4 , V_32 , V_97 . V_43 ) ;
F_48 ( V_5 ) ;
V_5 = F_69 ( V_2 , V_4 , V_92 , V_70 , V_95 , V_96 ) ;
F_48 ( V_5 ) ;
F_25 ( V_95 ) ;
F_64 ( V_70 ) ;
F_70 ( V_2 , V_4 ) ;
return V_5 ;
}
static T_2 int F_71 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_98 , T_1 V_43 , T_1 V_99 ,
const char * V_95 , int V_96 )
{
struct V_93 * V_94 ;
struct V_34 V_97 ;
int V_100 = 0 ;
V_94 = F_72 ( NULL , V_4 , V_32 , V_98 ,
V_99 , V_95 , V_96 , 0 ) ;
if ( V_94 && ! F_73 ( V_94 ) ) {
F_66 ( V_32 -> V_48 [ 0 ] , V_94 , & V_97 ) ;
if ( V_97 . V_43 != V_43 )
goto V_75;
} else
goto V_75;
F_23 ( V_32 ) ;
V_94 = F_74 ( NULL , V_4 , V_32 , V_98 , V_95 , V_96 , 0 ) ;
if ( V_94 && ! F_73 ( V_94 ) ) {
F_66 ( V_32 -> V_48 [ 0 ] , V_94 , & V_97 ) ;
if ( V_97 . V_43 != V_43 )
goto V_75;
} else
goto V_75;
V_100 = 1 ;
V_75:
F_23 ( V_32 ) ;
return V_100 ;
}
static T_2 int F_75 ( struct V_3 * log ,
struct V_34 * V_35 ,
char * V_95 , int V_101 )
{
struct V_31 * V_32 ;
struct V_102 * V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
int V_107 ;
int V_36 ;
int V_5 ;
int V_100 = 0 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_5 = F_22 ( NULL , log , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 )
goto V_75;
V_36 = F_20 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
V_104 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_103 = (struct V_102 * ) V_104 ;
V_107 = F_77 ( V_32 -> V_48 [ 0 ] , V_103 ) ;
if ( V_107 == V_101 ) {
V_106 = ( unsigned long ) ( V_103 + 1 ) ;
V_5 = F_78 ( V_32 -> V_48 [ 0 ] , V_95 ,
V_106 , V_101 ) ;
if ( V_5 == 0 ) {
V_100 = 1 ;
goto V_75;
}
}
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_107 ;
}
V_75:
F_79 ( V_32 ) ;
return V_100 ;
}
static T_2 int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
struct V_102 * V_103 ;
struct V_93 * V_94 ;
struct V_70 * V_92 ;
struct V_70 * V_70 ;
unsigned long V_108 ;
unsigned long V_109 ;
char * V_95 ;
int V_101 ;
int V_5 ;
int V_110 = 0 ;
V_92 = F_43 ( V_4 , V_35 -> V_66 ) ;
if ( ! V_92 )
return - V_18 ;
V_70 = F_43 ( V_4 , V_35 -> V_43 ) ;
if ( ! V_70 ) {
F_64 ( V_92 ) ;
return - V_76 ;
}
V_108 = F_21 ( V_21 , V_33 ) ;
V_109 = V_108 + F_20 ( V_21 , V_33 ) ;
V_111:
V_103 = (struct V_102 * ) V_108 ;
V_101 = F_77 ( V_21 , V_103 ) ;
V_95 = F_24 ( V_101 , V_51 ) ;
F_48 ( ! V_95 ) ;
F_26 ( V_21 , V_95 , ( unsigned long ) ( V_103 + 1 ) , V_101 ) ;
if ( F_71 ( V_4 , V_32 , F_45 ( V_92 ) , F_45 ( V_70 ) ,
F_81 ( V_21 , V_103 ) ,
V_95 , V_101 ) ) {
goto V_75;
}
if ( V_110 )
goto V_50;
V_5 = F_22 ( NULL , V_4 , V_35 , V_32 , 0 , 0 ) ;
if ( V_5 == 0 ) {
char * V_112 ;
int V_113 ;
struct V_102 * V_114 ;
unsigned long V_104 ;
unsigned long V_105 ;
struct V_20 * V_80 = V_32 -> V_48 [ 0 ] ;
if ( V_35 -> V_43 == V_35 -> V_66 )
goto V_115;
V_104 = F_21 ( V_80 , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_80 , V_32 -> V_49 [ 0 ] ) ;
while ( V_104 < V_105 ) {
V_114 = (struct V_102 * ) V_104 ;
V_113 = F_77 ( V_80 ,
V_114 ) ;
V_112 = F_24 ( V_113 , V_51 ) ;
F_48 ( ! V_112 ) ;
F_26 ( V_80 , V_112 ,
( unsigned long ) ( V_114 + 1 ) ,
V_113 ) ;
if ( ! F_75 ( log , V_35 , V_112 ,
V_113 ) ) {
F_82 ( V_70 ) ;
F_23 ( V_32 ) ;
V_5 = F_69 ( V_2 , V_4 , V_92 ,
V_70 , V_112 ,
V_113 ) ;
F_70 ( V_2 , V_4 ) ;
}
F_25 ( V_112 ) ;
V_104 = ( unsigned long ) ( V_114 + 1 ) + V_113 ;
}
F_48 ( V_5 ) ;
V_110 = 1 ;
}
F_23 ( V_32 ) ;
V_94 = F_72 ( V_2 , V_4 , V_32 , F_45 ( V_92 ) ,
F_81 ( V_21 , V_103 ) ,
V_95 , V_101 , 0 ) ;
if ( V_94 && ! F_73 ( V_94 ) ) {
V_5 = F_65 ( V_2 , V_4 , V_32 , V_92 , V_94 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_94 = F_74 ( V_2 , V_4 , V_32 , F_45 ( V_92 ) ,
V_95 , V_101 , 0 ) ;
if ( V_94 && ! F_73 ( V_94 ) ) {
V_5 = F_65 ( V_2 , V_4 , V_32 , V_92 , V_94 ) ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_50:
V_5 = F_83 ( V_2 , V_92 , V_70 , V_95 , V_101 , 0 ,
F_81 ( V_21 , V_103 ) ) ;
F_48 ( V_5 ) ;
F_63 ( V_2 , V_4 , V_70 ) ;
V_75:
V_108 = ( unsigned long ) ( V_103 + 1 ) + V_101 ;
F_25 ( V_95 ) ;
if ( V_108 < V_109 )
goto V_111;
V_5 = F_19 ( V_2 , V_4 , V_32 , V_21 , V_33 , V_35 ) ;
F_48 ( V_5 ) ;
V_115:
F_23 ( V_32 ) ;
F_64 ( V_92 ) ;
F_64 ( V_70 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_66 )
{
int V_5 ;
V_5 = F_85 ( V_4 , V_66 ) ;
if ( V_5 > 0 )
V_5 = F_86 ( V_2 , V_4 , V_66 ) ;
return V_5 ;
}
static T_2 int F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_70 )
{
struct V_31 * V_32 ;
int V_5 ;
struct V_34 V_35 ;
T_1 V_116 = 0 ;
unsigned long V_104 ;
unsigned long V_105 ;
int V_96 ;
T_1 V_117 = F_45 ( V_70 ) ;
V_35 . V_43 = V_117 ;
V_35 . type = V_118 ;
V_35 . V_66 = ( T_1 ) - 1 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
break;
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_35 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . V_43 != V_117 ||
V_35 . type != V_118 )
break;
V_104 = F_21 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ) ;
V_105 = V_104 + F_20 ( V_32 -> V_48 [ 0 ] ,
V_32 -> V_49 [ 0 ] ) ;
while ( V_104 < V_105 ) {
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) V_104 ;
V_96 = F_77 ( V_32 -> V_48 [ 0 ] ,
V_103 ) ;
V_104 = ( unsigned long ) ( V_103 + 1 ) + V_96 ;
V_116 ++ ;
}
if ( V_35 . V_66 == 0 )
break;
V_35 . V_66 -- ;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_116 != V_70 -> V_119 ) {
F_89 ( V_70 , V_116 ) ;
F_63 ( V_2 , V_4 , V_70 ) ;
}
F_90 ( V_70 ) -> V_120 = ( T_1 ) - 1 ;
if ( V_70 -> V_119 == 0 ) {
if ( F_31 ( V_70 -> V_121 ) ) {
V_5 = F_91 ( V_2 , V_4 , NULL , V_32 ,
V_117 , 1 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_84 ( V_2 , V_4 , V_117 ) ;
F_48 ( V_5 ) ;
}
F_79 ( V_32 ) ;
return 0 ;
}
static T_2 int F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_70 * V_70 ;
V_35 . V_43 = V_122 ;
V_35 . type = V_123 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , V_4 , & V_35 , V_32 , - 1 , 1 ) ;
if ( V_5 < 0 )
break;
if ( V_5 == 1 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . V_43 != V_122 ||
V_35 . type != V_123 )
break;
V_5 = F_93 ( V_2 , V_4 , V_32 ) ;
if ( V_5 )
goto V_75;
F_23 ( V_32 ) ;
V_70 = F_43 ( V_4 , V_35 . V_66 ) ;
if ( ! V_70 )
return - V_76 ;
V_5 = F_87 ( V_2 , V_4 , V_70 ) ;
F_48 ( V_5 ) ;
F_64 ( V_70 ) ;
V_35 . V_66 = ( T_1 ) - 1 ;
}
V_5 = 0 ;
V_75:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_43 )
{
struct V_34 V_35 ;
int V_5 = 0 ;
struct V_70 * V_70 ;
V_70 = F_43 ( V_4 , V_43 ) ;
if ( ! V_70 )
return - V_76 ;
V_35 . V_43 = V_122 ;
F_94 ( & V_35 , V_123 ) ;
V_35 . V_66 = V_43 ;
V_5 = F_27 ( V_2 , V_4 , V_32 , & V_35 , 0 ) ;
F_23 ( V_32 ) ;
if ( V_5 == 0 ) {
F_82 ( V_70 ) ;
F_63 ( V_2 , V_4 , V_70 ) ;
} else if ( V_5 == - V_53 ) {
V_5 = 0 ;
} else {
F_95 () ;
}
F_64 ( V_70 ) ;
return V_5 ;
}
static T_2 int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_98 , T_1 V_99 ,
char * V_95 , int V_96 , T_4 type ,
struct V_34 * V_97 )
{
struct V_70 * V_70 ;
struct V_70 * V_92 ;
int V_5 ;
V_70 = F_43 ( V_4 , V_97 -> V_43 ) ;
if ( ! V_70 )
return - V_18 ;
V_92 = F_43 ( V_4 , V_98 ) ;
if ( ! V_92 ) {
F_64 ( V_70 ) ;
return - V_76 ;
}
V_5 = F_83 ( V_2 , V_92 , V_70 , V_95 , V_96 , 1 , V_99 ) ;
F_64 ( V_70 ) ;
F_64 ( V_92 ) ;
return V_5 ;
}
static T_2 int F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 ,
struct V_93 * V_94 ,
struct V_34 * V_35 )
{
char * V_95 ;
int V_96 ;
struct V_93 * V_124 ;
struct V_34 V_125 ;
struct V_34 V_126 ;
struct V_70 * V_92 ;
T_4 V_127 ;
int V_128 ;
int V_5 ;
V_92 = F_43 ( V_4 , V_35 -> V_43 ) ;
if ( ! V_92 )
return - V_76 ;
V_96 = F_67 ( V_21 , V_94 ) ;
V_95 = F_24 ( V_96 , V_51 ) ;
if ( ! V_95 )
return - V_52 ;
V_127 = F_98 ( V_21 , V_94 ) ;
F_26 ( V_21 , V_95 , ( unsigned long ) ( V_94 + 1 ) ,
V_96 ) ;
F_66 ( V_21 , V_94 , & V_126 ) ;
V_128 = F_99 ( V_2 , V_4 , V_32 , & V_126 , 0 ) ;
if ( V_128 == 0 )
V_128 = 1 ;
else
V_128 = 0 ;
F_23 ( V_32 ) ;
if ( V_35 -> type == V_129 ) {
V_124 = F_74 ( V_2 , V_4 , V_32 , V_35 -> V_43 ,
V_95 , V_96 , 1 ) ;
} else if ( V_35 -> type == V_130 ) {
V_124 = F_72 ( V_2 , V_4 , V_32 ,
V_35 -> V_43 ,
V_35 -> V_66 , V_95 ,
V_96 , 1 ) ;
} else {
F_95 () ;
}
if ( F_100 ( V_124 ) ) {
if ( V_35 -> type != V_130 )
goto V_75;
goto V_50;
}
F_66 ( V_32 -> V_48 [ 0 ] , V_124 , & V_125 ) ;
if ( V_125 . V_43 == V_126 . V_43 &&
V_125 . type == V_126 . type &&
V_125 . V_66 == V_126 . V_66 &&
F_98 ( V_32 -> V_48 [ 0 ] , V_124 ) == V_127 ) {
goto V_75;
}
if ( ! V_128 )
goto V_75;
V_5 = F_65 ( V_2 , V_4 , V_32 , V_92 , V_124 ) ;
F_48 ( V_5 ) ;
if ( V_35 -> type == V_130 )
goto V_50;
V_75:
F_23 ( V_32 ) ;
F_25 ( V_95 ) ;
F_64 ( V_92 ) ;
return 0 ;
V_50:
F_23 ( V_32 ) ;
V_5 = F_96 ( V_2 , V_4 , V_32 , V_35 -> V_43 , V_35 -> V_66 ,
V_95 , V_96 , V_127 , & V_126 ) ;
F_48 ( V_5 && V_5 != - V_18 ) ;
goto V_75;
}
static T_2 int F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_20 * V_21 , int V_33 ,
struct V_34 * V_35 )
{
int V_5 ;
T_3 V_36 = F_20 ( V_21 , V_33 ) ;
struct V_93 * V_94 ;
int V_96 ;
unsigned long V_104 ;
unsigned long V_105 ;
V_104 = F_21 ( V_21 , V_33 ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_94 = (struct V_93 * ) V_104 ;
if ( F_102 ( V_4 , V_21 , V_94 ) )
return - V_76 ;
V_96 = F_67 ( V_21 , V_94 ) ;
V_5 = F_97 ( V_2 , V_4 , V_32 , V_21 , V_94 , V_35 ) ;
F_48 ( V_5 ) ;
V_104 = ( unsigned long ) ( V_94 + 1 ) ;
V_104 += V_96 ;
}
return 0 ;
}
static T_2 int F_103 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
T_1 V_98 , int V_131 ,
T_1 * V_132 , T_1 * V_133 )
{
struct V_34 V_35 ;
T_1 V_134 ;
struct V_135 * V_69 ;
int V_5 ;
int V_136 ;
if ( * V_132 == ( T_1 ) - 1 )
return 1 ;
V_35 . V_43 = V_98 ;
V_35 . type = V_131 ;
V_35 . V_66 = * V_132 ;
V_5 = F_22 ( NULL , V_4 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_75;
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
goto V_75;
V_32 -> V_49 [ 0 ] -- ;
}
if ( V_5 != 0 )
F_88 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . type != V_131 || V_35 . V_43 != V_98 ) {
V_5 = 1 ;
goto V_89;
}
V_69 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_135 ) ;
V_134 = F_104 ( V_32 -> V_48 [ 0 ] , V_69 ) ;
if ( * V_132 >= V_35 . V_66 && * V_132 <= V_134 ) {
V_5 = 0 ;
* V_132 = V_35 . V_66 ;
* V_133 = V_134 ;
goto V_75;
}
V_5 = 1 ;
V_89:
V_136 = F_105 ( V_32 -> V_48 [ 0 ] ) ;
if ( V_32 -> V_49 [ 0 ] >= V_136 ) {
V_5 = F_106 ( V_4 , V_32 ) ;
if ( V_5 )
goto V_75;
} else {
V_32 -> V_49 [ 0 ] ++ ;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_35 , V_32 -> V_49 [ 0 ] ) ;
if ( V_35 . type != V_131 || V_35 . V_43 != V_98 ) {
V_5 = 1 ;
goto V_75;
}
V_69 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_135 ) ;
V_134 = F_104 ( V_32 -> V_48 [ 0 ] , V_69 ) ;
* V_132 = V_35 . V_66 ;
* V_133 = V_134 ;
V_5 = 0 ;
V_75:
F_23 ( V_32 ) ;
return V_5 ;
}
static T_2 int F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
struct V_31 * V_137 ,
struct V_70 * V_92 ,
struct V_34 * V_138 )
{
int V_5 ;
struct V_20 * V_21 ;
int V_33 ;
T_3 V_36 ;
struct V_93 * V_94 ;
struct V_93 * V_139 ;
int V_96 ;
unsigned long V_104 ;
unsigned long V_105 ;
char * V_95 ;
struct V_70 * V_70 ;
struct V_34 V_97 ;
V_111:
V_21 = V_32 -> V_48 [ 0 ] ;
V_33 = V_32 -> V_49 [ 0 ] ;
V_36 = F_20 ( V_21 , V_33 ) ;
V_104 = F_21 ( V_21 , V_33 ) ;
V_105 = V_104 + V_36 ;
while ( V_104 < V_105 ) {
V_94 = (struct V_93 * ) V_104 ;
if ( F_102 ( V_4 , V_21 , V_94 ) ) {
V_5 = - V_76 ;
goto V_75;
}
V_96 = F_67 ( V_21 , V_94 ) ;
V_95 = F_24 ( V_96 , V_51 ) ;
if ( ! V_95 ) {
V_5 = - V_52 ;
goto V_75;
}
F_26 ( V_21 , V_95 , ( unsigned long ) ( V_94 + 1 ) ,
V_96 ) ;
V_139 = NULL ;
if ( log && V_138 -> type == V_129 ) {
V_139 = F_74 ( V_2 , log , V_137 ,
V_138 -> V_43 ,
V_95 , V_96 , 0 ) ;
} else if ( log && V_138 -> type == V_130 ) {
V_139 = F_72 ( V_2 , log ,
V_137 ,
V_138 -> V_43 ,
V_138 -> V_66 ,
V_95 , V_96 , 0 ) ;
}
if ( F_100 ( V_139 ) ) {
F_66 ( V_21 , V_94 , & V_97 ) ;
F_23 ( V_32 ) ;
F_23 ( V_137 ) ;
V_70 = F_43 ( V_4 , V_97 . V_43 ) ;
if ( ! V_70 ) {
F_25 ( V_95 ) ;
return - V_76 ;
}
V_5 = F_68 ( V_2 , V_4 ,
V_32 , V_97 . V_43 ) ;
F_48 ( V_5 ) ;
F_82 ( V_70 ) ;
V_5 = F_69 ( V_2 , V_4 , V_92 , V_70 ,
V_95 , V_96 ) ;
F_48 ( V_5 ) ;
F_70 ( V_2 , V_4 ) ;
F_25 ( V_95 ) ;
F_64 ( V_70 ) ;
V_5 = F_22 ( NULL , V_4 , V_138 , V_32 ,
0 , 0 ) ;
if ( V_5 == 0 )
goto V_111;
V_5 = 0 ;
goto V_75;
}
F_23 ( V_137 ) ;
F_25 ( V_95 ) ;
V_104 = ( unsigned long ) ( V_94 + 1 ) ;
V_104 += V_96 ;
}
V_5 = 0 ;
V_75:
F_23 ( V_32 ) ;
F_23 ( V_137 ) ;
return V_5 ;
}
static T_2 int F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_98 , int V_140 )
{
T_1 V_141 ;
T_1 V_142 ;
int V_131 = V_143 ;
int V_5 = 0 ;
struct V_34 V_138 ;
struct V_34 V_125 ;
struct V_31 * V_137 ;
struct V_70 * V_92 ;
V_138 . V_43 = V_98 ;
V_138 . type = V_129 ;
V_137 = F_76 () ;
if ( ! V_137 )
return - V_52 ;
V_92 = F_43 ( V_4 , V_98 ) ;
if ( ! V_92 ) {
F_79 ( V_137 ) ;
return 0 ;
}
V_111:
V_141 = 0 ;
V_142 = 0 ;
while ( 1 ) {
if ( V_140 )
V_142 = ( T_1 ) - 1 ;
else {
V_5 = F_103 ( log , V_32 , V_98 , V_131 ,
& V_141 , & V_142 ) ;
if ( V_5 != 0 )
break;
}
V_138 . V_66 = V_141 ;
while ( 1 ) {
int V_136 ;
V_5 = F_22 ( NULL , V_4 , & V_138 , V_32 ,
0 , 0 ) ;
if ( V_5 < 0 )
goto V_75;
V_136 = F_105 ( V_32 -> V_48 [ 0 ] ) ;
if ( V_32 -> V_49 [ 0 ] >= V_136 ) {
V_5 = F_106 ( V_4 , V_32 ) ;
if ( V_5 )
break;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_125 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_125 . V_43 != V_98 ||
V_125 . type != V_138 . type )
goto V_144;
if ( V_125 . V_66 > V_142 )
break;
V_5 = F_107 ( V_2 , V_4 , log , V_32 ,
V_137 , V_92 ,
& V_125 ) ;
F_48 ( V_5 ) ;
if ( V_125 . V_66 == ( T_1 ) - 1 )
break;
V_138 . V_66 = V_125 . V_66 + 1 ;
}
F_23 ( V_32 ) ;
if ( V_142 == ( T_1 ) - 1 )
break;
V_141 = V_142 + 1 ;
}
V_144:
V_5 = 0 ;
if ( V_131 == V_143 ) {
V_131 = V_145 ;
V_138 . type = V_130 ;
F_23 ( V_32 ) ;
goto V_111;
}
V_75:
F_23 ( V_32 ) ;
F_79 ( V_137 ) ;
F_64 ( V_92 ) ;
return V_5 ;
}
static int F_108 ( struct V_3 * log , struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
int V_136 ;
struct V_31 * V_32 ;
struct V_3 * V_4 = V_23 -> V_146 ;
struct V_34 V_35 ;
int V_147 ;
int V_148 ;
int V_5 ;
V_5 = F_109 ( V_21 , V_24 ) ;
if ( V_5 )
return V_5 ;
V_147 = F_110 ( V_21 ) ;
if ( V_147 != 0 )
return 0 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_136 = F_105 ( V_21 ) ;
for ( V_148 = 0 ; V_148 < V_136 ; V_148 ++ ) {
F_88 ( V_21 , & V_35 , V_148 ) ;
if ( V_35 . type == V_55 &&
V_23 -> V_149 == V_150 ) {
struct V_56 * V_151 ;
T_3 V_152 ;
V_151 = F_39 ( V_21 , V_148 ,
struct V_56 ) ;
V_152 = F_32 ( V_21 , V_151 ) ;
if ( F_31 ( V_152 ) ) {
V_5 = F_91 ( V_23 -> V_2 ,
V_4 , log , V_32 , V_35 . V_43 , 0 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_148 , & V_35 ) ;
F_48 ( V_5 ) ;
if ( F_111 ( V_152 ) ) {
V_5 = F_84 ( V_23 -> V_2 , V_4 ,
V_35 . V_43 ) ;
F_48 ( V_5 ) ;
}
V_5 = F_68 ( V_23 -> V_2 , V_4 ,
V_32 , V_35 . V_43 ) ;
F_48 ( V_5 ) ;
}
if ( V_23 -> V_149 < V_153 )
continue;
if ( V_35 . type == V_154 ) {
V_5 = F_19 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_148 , & V_35 ) ;
F_48 ( V_5 ) ;
} else if ( V_35 . type == V_118 ) {
V_5 = F_80 ( V_23 -> V_2 , V_4 , log , V_32 ,
V_21 , V_148 , & V_35 ) ;
F_48 ( V_5 && V_5 != - V_18 ) ;
} else if ( V_35 . type == V_155 ) {
V_5 = F_38 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_148 , & V_35 ) ;
F_48 ( V_5 ) ;
} else if ( V_35 . type == V_129 ||
V_35 . type == V_130 ) {
V_5 = F_101 ( V_23 -> V_2 , V_4 , V_32 ,
V_21 , V_148 , & V_35 ) ;
F_48 ( V_5 ) ;
}
}
F_79 ( V_32 ) ;
return 0 ;
}
static T_2 int F_112 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_147 ,
struct V_22 * V_23 )
{
T_1 V_156 ;
T_1 V_157 ;
T_1 V_158 ;
struct V_20 * V_89 ;
struct V_20 * V_159 ;
struct V_20 * V_160 ;
T_3 V_161 ;
int V_5 = 0 ;
F_113 ( * V_147 < 0 ) ;
F_113 ( * V_147 >= V_162 ) ;
while ( * V_147 > 0 ) {
F_113 ( * V_147 < 0 ) ;
F_113 ( * V_147 >= V_162 ) ;
V_159 = V_32 -> V_48 [ * V_147 ] ;
if ( F_110 ( V_159 ) != * V_147 )
F_113 ( 1 ) ;
if ( V_32 -> V_49 [ * V_147 ] >=
F_105 ( V_159 ) )
break;
V_157 = F_114 ( V_159 , V_32 -> V_49 [ * V_147 ] ) ;
V_158 = F_115 ( V_159 , V_32 -> V_49 [ * V_147 ] ) ;
V_161 = F_116 ( V_4 , * V_147 - 1 ) ;
V_160 = V_32 -> V_48 [ * V_147 ] ;
V_156 = F_117 ( V_160 ) ;
V_89 = F_118 ( V_4 , V_157 , V_161 ) ;
if ( ! V_89 )
return - V_52 ;
if ( * V_147 == 1 ) {
V_5 = V_23 -> V_163 ( V_4 , V_89 , V_23 , V_158 ) ;
if ( V_5 )
return V_5 ;
V_32 -> V_49 [ * V_147 ] ++ ;
if ( V_23 -> free ) {
V_5 = F_109 ( V_89 , V_158 ) ;
if ( V_5 ) {
F_119 ( V_89 ) ;
return V_5 ;
}
F_120 ( V_89 ) ;
F_121 ( V_89 ) ;
F_122 ( V_2 , V_4 , V_89 ) ;
F_18 ( V_89 ) ;
F_123 ( V_89 ) ;
F_113 ( V_156 !=
V_44 ) ;
V_5 = F_124 ( V_4 ,
V_157 , V_161 ) ;
F_48 ( V_5 ) ;
}
F_119 ( V_89 ) ;
continue;
}
V_5 = F_109 ( V_89 , V_158 ) ;
if ( V_5 ) {
F_119 ( V_89 ) ;
return V_5 ;
}
F_113 ( * V_147 <= 0 ) ;
if ( V_32 -> V_48 [ * V_147 - 1 ] )
F_119 ( V_32 -> V_48 [ * V_147 - 1 ] ) ;
V_32 -> V_48 [ * V_147 - 1 ] = V_89 ;
* V_147 = F_110 ( V_89 ) ;
V_32 -> V_49 [ * V_147 ] = 0 ;
F_125 () ;
}
F_113 ( * V_147 < 0 ) ;
F_113 ( * V_147 >= V_162 ) ;
V_32 -> V_49 [ * V_147 ] = F_105 ( V_32 -> V_48 [ * V_147 ] ) ;
F_125 () ;
return 0 ;
}
static T_2 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 , int * V_147 ,
struct V_22 * V_23 )
{
T_1 V_156 ;
int V_148 ;
int V_33 ;
int V_5 ;
for ( V_148 = * V_147 ; V_148 < V_162 - 1 && V_32 -> V_48 [ V_148 ] ; V_148 ++ ) {
V_33 = V_32 -> V_49 [ V_148 ] ;
if ( V_33 + 1 < F_105 ( V_32 -> V_48 [ V_148 ] ) ) {
V_32 -> V_49 [ V_148 ] ++ ;
* V_147 = V_148 ;
F_113 ( * V_147 == 0 ) ;
return 0 ;
} else {
struct V_20 * V_160 ;
if ( V_32 -> V_48 [ * V_147 ] == V_4 -> V_164 )
V_160 = V_32 -> V_48 [ * V_147 ] ;
else
V_160 = V_32 -> V_48 [ * V_147 + 1 ] ;
V_156 = F_117 ( V_160 ) ;
V_5 = V_23 -> V_163 ( V_4 , V_32 -> V_48 [ * V_147 ] , V_23 ,
F_127 ( V_32 -> V_48 [ * V_147 ] ) ) ;
if ( V_5 )
return V_5 ;
if ( V_23 -> free ) {
struct V_20 * V_89 ;
V_89 = V_32 -> V_48 [ * V_147 ] ;
F_120 ( V_89 ) ;
F_121 ( V_89 ) ;
F_122 ( V_2 , V_4 , V_89 ) ;
F_18 ( V_89 ) ;
F_123 ( V_89 ) ;
F_113 ( V_156 != V_44 ) ;
V_5 = F_124 ( V_4 ,
V_32 -> V_48 [ * V_147 ] -> V_27 ,
V_32 -> V_48 [ * V_147 ] -> V_28 ) ;
F_48 ( V_5 ) ;
}
F_119 ( V_32 -> V_48 [ * V_147 ] ) ;
V_32 -> V_48 [ * V_147 ] = NULL ;
* V_147 = V_148 + 1 ;
}
}
return 1 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_3 * log , struct V_22 * V_23 )
{
int V_5 = 0 ;
int V_165 ;
int V_147 ;
struct V_31 * V_32 ;
int V_148 ;
int V_166 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_147 = F_110 ( log -> V_164 ) ;
V_166 = V_147 ;
V_32 -> V_48 [ V_147 ] = log -> V_164 ;
F_129 ( log -> V_164 ) ;
V_32 -> V_49 [ V_147 ] = 0 ;
while ( 1 ) {
V_165 = F_112 ( V_2 , log , V_32 , & V_147 , V_23 ) ;
if ( V_165 > 0 )
break;
if ( V_165 < 0 ) {
V_5 = V_165 ;
goto V_75;
}
V_165 = F_126 ( V_2 , log , V_32 , & V_147 , V_23 ) ;
if ( V_165 > 0 )
break;
if ( V_165 < 0 ) {
V_5 = V_165 ;
goto V_75;
}
}
if ( V_32 -> V_48 [ V_166 ] ) {
V_5 = V_23 -> V_163 ( log , V_32 -> V_48 [ V_166 ] , V_23 ,
F_127 ( V_32 -> V_48 [ V_166 ] ) ) ;
if ( V_5 )
goto V_75;
if ( V_23 -> free ) {
struct V_20 * V_89 ;
V_89 = V_32 -> V_48 [ V_166 ] ;
F_120 ( V_89 ) ;
F_121 ( V_89 ) ;
F_122 ( V_2 , log , V_89 ) ;
F_18 ( V_89 ) ;
F_123 ( V_89 ) ;
F_113 ( log -> V_42 . V_43 !=
V_44 ) ;
V_5 = F_124 ( log , V_89 -> V_27 ,
V_89 -> V_28 ) ;
F_48 ( V_5 ) ;
}
}
V_75:
for ( V_148 = 0 ; V_148 <= V_166 ; V_148 ++ ) {
if ( V_32 -> V_48 [ V_148 ] ) {
F_119 ( V_32 -> V_48 [ V_148 ] ) ;
V_32 -> V_48 [ V_148 ] = NULL ;
}
}
F_79 ( V_32 ) ;
return V_5 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
if ( log -> V_167 == 1 ) {
V_5 = F_131 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_42 , & log -> V_168 ) ;
} else {
V_5 = F_132 ( V_2 , log -> V_15 -> V_17 ,
& log -> V_42 , & log -> V_168 ) ;
}
return V_5 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_60 )
{
F_134 ( V_30 ) ;
int V_99 = V_60 % 2 ;
do {
F_135 ( & V_4 -> V_169 [ V_99 ] ,
& V_30 , V_170 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_171 !=
V_2 -> V_60 && V_4 -> V_167 < V_60 + 2 &&
F_136 ( & V_4 -> V_172 [ V_99 ] ) )
F_137 () ;
F_138 ( & V_4 -> V_169 [ V_99 ] , & V_30 ) ;
F_2 ( & V_4 -> V_7 ) ;
} while ( V_4 -> V_15 -> V_171 !=
V_2 -> V_60 && V_4 -> V_167 < V_60 + 2 &&
F_136 ( & V_4 -> V_172 [ V_99 ] ) );
return 0 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_134 ( V_30 ) ;
while ( V_4 -> V_15 -> V_171 !=
V_2 -> V_60 && F_136 ( & V_4 -> V_14 ) ) {
F_135 ( & V_4 -> V_19 ,
& V_30 , V_170 ) ;
F_4 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_15 -> V_171 !=
V_2 -> V_60 && F_136 ( & V_4 -> V_14 ) )
F_137 () ;
F_2 ( & V_4 -> V_7 ) ;
F_138 ( & V_4 -> V_19 , & V_30 ) ;
}
}
int F_140 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_173 ;
int V_174 ;
int V_175 ;
int V_5 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_3 * V_17 = V_4 -> V_15 -> V_17 ;
unsigned long V_167 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
V_173 = V_4 -> V_167 % 2 ;
if ( F_136 ( & V_4 -> V_172 [ V_173 ] ) ) {
F_133 ( V_2 , V_4 , V_4 -> V_167 ) ;
F_4 ( & V_4 -> V_7 ) ;
return 0 ;
}
F_141 ( & V_4 -> V_172 [ V_173 ] , 1 ) ;
if ( F_136 ( & V_4 -> V_172 [ ( V_173 + 1 ) % 2 ] ) )
F_133 ( V_2 , V_4 , V_4 -> V_167 - 1 ) ;
while ( 1 ) {
unsigned long V_176 = V_4 -> V_13 ;
if ( ! F_142 ( V_4 , V_177 ) && V_4 -> V_12 ) {
F_4 ( & V_4 -> V_7 ) ;
F_143 ( 1 ) ;
F_2 ( & V_4 -> V_7 ) ;
}
F_139 ( V_2 , V_4 ) ;
if ( V_176 == V_4 -> V_13 )
break;
}
if ( V_4 -> V_15 -> V_171 == V_2 -> V_60 ) {
V_5 = - V_178 ;
F_4 ( & V_4 -> V_7 ) ;
goto V_75;
}
V_167 = V_4 -> V_167 ;
if ( V_167 % 2 == 0 )
V_175 = V_179 ;
else
V_175 = V_180 ;
V_5 = F_144 ( log , & log -> V_181 , V_175 ) ;
if ( V_5 ) {
F_145 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_4 -> V_7 ) ;
goto V_75;
}
F_146 ( & log -> V_168 , log -> V_164 ) ;
V_4 -> V_13 = 0 ;
V_4 -> V_167 ++ ;
log -> V_167 = V_4 -> V_167 ;
V_4 -> V_9 = 0 ;
F_8 () ;
F_4 ( & V_4 -> V_7 ) ;
F_2 ( & V_17 -> V_7 ) ;
V_17 -> V_13 ++ ;
F_3 ( & V_17 -> V_14 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = F_130 ( V_2 , log ) ;
F_2 ( & V_17 -> V_7 ) ;
if ( F_11 ( & V_17 -> V_14 ) ) {
F_8 () ;
if ( F_12 ( & V_17 -> V_19 ) )
F_13 ( & V_17 -> V_19 ) ;
}
if ( V_5 ) {
if ( V_5 != - V_182 ) {
F_145 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_75;
}
V_4 -> V_15 -> V_171 = V_2 -> V_60 ;
F_147 ( log , & log -> V_181 , V_175 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_178 ;
goto V_75;
}
V_174 = V_17 -> V_167 % 2 ;
if ( F_136 ( & V_17 -> V_172 [ V_174 ] ) ) {
F_147 ( log , & log -> V_181 , V_175 ) ;
F_133 ( V_2 , V_17 ,
V_17 -> V_167 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = 0 ;
goto V_75;
}
F_141 ( & V_17 -> V_172 [ V_174 ] , 1 ) ;
if ( F_136 ( & V_17 -> V_172 [ ( V_174 + 1 ) % 2 ] ) ) {
F_133 ( V_2 , V_17 ,
V_17 -> V_167 - 1 ) ;
}
F_139 ( V_2 , V_17 ) ;
if ( V_4 -> V_15 -> V_171 == V_2 -> V_60 ) {
F_147 ( log , & log -> V_181 , V_175 ) ;
F_4 ( & V_17 -> V_7 ) ;
V_5 = - V_178 ;
goto V_183;
}
V_5 = F_148 ( V_17 ,
& V_17 -> V_181 ,
V_179 | V_180 ) ;
if ( V_5 ) {
F_145 ( V_2 , V_4 , V_5 ) ;
F_4 ( & V_17 -> V_7 ) ;
goto V_183;
}
F_147 ( log , & log -> V_181 , V_175 ) ;
F_149 ( V_4 -> V_15 -> V_184 ,
V_17 -> V_164 -> V_27 ) ;
F_150 ( V_4 -> V_15 -> V_184 ,
F_110 ( V_17 -> V_164 ) ) ;
V_17 -> V_13 = 0 ;
V_17 -> V_167 ++ ;
F_8 () ;
F_4 ( & V_17 -> V_7 ) ;
F_151 ( V_4 ) ;
F_152 ( V_2 , V_4 -> V_15 -> V_185 , 1 ) ;
F_153 ( V_4 ) ;
V_5 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_186 < V_167 )
V_4 -> V_186 = V_167 ;
F_4 ( & V_4 -> V_7 ) ;
V_183:
F_141 ( & V_17 -> V_172 [ V_174 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_17 -> V_169 [ V_174 ] ) )
F_13 ( & V_17 -> V_169 [ V_174 ] ) ;
V_75:
F_141 ( & V_4 -> V_172 [ V_173 ] , 0 ) ;
F_8 () ;
if ( F_12 ( & V_4 -> V_169 [ V_173 ] ) )
F_13 ( & V_4 -> V_169 [ V_173 ] ) ;
return V_5 ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_3 * log )
{
int V_5 ;
T_1 V_27 ;
T_1 V_187 ;
struct V_22 V_23 = {
. free = 1 ,
. V_163 = F_14
} ;
V_5 = F_128 ( V_2 , log , & V_23 ) ;
F_48 ( V_5 ) ;
while ( 1 ) {
V_5 = F_155 ( & log -> V_181 ,
0 , & V_27 , & V_187 , V_179 | V_180 ) ;
if ( V_5 )
break;
F_156 ( & log -> V_181 , V_27 , V_187 ,
V_179 | V_180 , V_51 ) ;
}
F_119 ( log -> V_164 ) ;
F_25 ( log ) ;
}
int F_157 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
F_154 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
return 0 ;
}
int F_158 ( struct V_1 * V_2 ,
struct V_188 * V_15 )
{
if ( V_15 -> V_17 ) {
F_154 ( V_2 , V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
return 0 ;
}
int F_159 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_95 , int V_96 ,
struct V_70 * V_92 , T_1 V_99 )
{
struct V_3 * log ;
struct V_93 * V_94 ;
struct V_31 * V_32 ;
int V_5 ;
int V_6 = 0 ;
int V_189 = 0 ;
T_1 V_190 = F_45 ( V_92 ) ;
if ( F_90 ( V_92 ) -> V_191 < V_2 -> V_60 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
F_2 ( & F_90 ( V_92 ) -> V_7 ) ;
log = V_4 -> V_8 ;
V_32 = F_76 () ;
if ( ! V_32 ) {
V_6 = - V_52 ;
goto V_192;
}
V_94 = F_74 ( V_2 , log , V_32 , V_190 ,
V_95 , V_96 , - 1 ) ;
if ( F_73 ( V_94 ) ) {
V_6 = F_160 ( V_94 ) ;
goto V_193;
}
if ( V_94 ) {
V_5 = F_161 ( V_2 , log , V_32 , V_94 ) ;
V_189 += V_96 ;
F_48 ( V_5 ) ;
}
F_23 ( V_32 ) ;
V_94 = F_72 ( V_2 , log , V_32 , V_190 ,
V_99 , V_95 , V_96 , - 1 ) ;
if ( F_73 ( V_94 ) ) {
V_6 = F_160 ( V_94 ) ;
goto V_193;
}
if ( V_94 ) {
V_5 = F_161 ( V_2 , log , V_32 , V_94 ) ;
V_189 += V_96 ;
F_48 ( V_5 ) ;
}
if ( V_189 ) {
struct V_34 V_35 ;
V_35 . V_43 = V_190 ;
V_35 . V_66 = 0 ;
V_35 . type = V_55 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , 0 , 1 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_193;
}
if ( V_5 == 0 ) {
struct V_56 * V_69 ;
T_1 V_194 ;
V_69 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_56 ) ;
V_194 = F_33 ( V_32 -> V_48 [ 0 ] , V_69 ) ;
if ( V_194 > V_189 )
V_194 -= V_189 ;
else
V_194 = 0 ;
F_35 ( V_32 -> V_48 [ 0 ] , V_69 , V_194 ) ;
F_37 ( V_32 -> V_48 [ 0 ] ) ;
} else
V_5 = 0 ;
F_23 ( V_32 ) ;
}
V_193:
F_79 ( V_32 ) ;
V_192:
F_4 ( & F_90 ( V_92 ) -> V_7 ) ;
if ( V_5 == - V_182 ) {
V_4 -> V_15 -> V_171 = V_2 -> V_60 ;
V_5 = 0 ;
} else if ( V_5 < 0 )
F_145 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_6 ;
}
int F_162 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_95 , int V_96 ,
struct V_70 * V_70 , T_1 V_98 )
{
struct V_3 * log ;
T_1 V_99 ;
int V_5 ;
if ( F_90 ( V_70 ) -> V_191 < V_2 -> V_60 )
return 0 ;
V_5 = F_7 ( V_4 ) ;
if ( V_5 )
return 0 ;
log = V_4 -> V_8 ;
F_2 ( & F_90 ( V_70 ) -> V_7 ) ;
V_5 = F_163 ( V_2 , log , V_95 , V_96 , F_45 ( V_70 ) ,
V_98 , & V_99 ) ;
F_4 ( & F_90 ( V_70 ) -> V_7 ) ;
if ( V_5 == - V_182 ) {
V_4 -> V_15 -> V_171 = V_2 -> V_60 ;
V_5 = 0 ;
} else if ( V_5 < 0 && V_5 != - V_18 )
F_145 ( V_2 , V_4 , V_5 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
static T_2 int F_164 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
int V_131 , T_1 V_98 ,
T_1 V_195 , T_1 V_196 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_135 * V_69 ;
V_35 . V_43 = V_98 ;
V_35 . V_66 = V_195 ;
if ( V_131 == V_129 )
V_35 . type = V_143 ;
else
V_35 . type = V_145 ;
V_5 = F_27 ( V_2 , log , V_32 , & V_35 , sizeof( * V_69 ) ) ;
if ( V_5 )
return V_5 ;
V_69 = F_39 ( V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
struct V_135 ) ;
F_165 ( V_32 -> V_48 [ 0 ] , V_69 , V_196 ) ;
F_37 ( V_32 -> V_48 [ 0 ] ) ;
F_23 ( V_32 ) ;
return 0 ;
}
static T_2 int F_166 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_31 * V_32 ,
struct V_31 * V_197 , int V_131 ,
T_1 V_198 , T_1 * V_199 )
{
struct V_34 V_200 ;
struct V_34 V_201 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_202 ;
int V_6 = 0 ;
int V_5 ;
int V_148 ;
int V_136 ;
T_1 V_195 = V_198 ;
T_1 V_196 = ( T_1 ) - 1 ;
T_1 V_117 = F_45 ( V_70 ) ;
log = V_4 -> V_8 ;
V_201 . V_43 = V_117 ;
V_201 . V_66 = ( T_1 ) - 1 ;
V_201 . type = V_131 ;
V_200 . V_43 = V_117 ;
V_200 . type = V_131 ;
V_200 . V_66 = V_198 ;
V_32 -> V_203 = 1 ;
V_5 = F_167 ( V_4 , & V_200 , & V_201 ,
V_32 , 0 , V_2 -> V_60 ) ;
if ( V_5 != 0 || V_200 . V_43 != V_117 || V_200 . type != V_131 ) {
V_200 . V_43 = V_117 ;
V_200 . type = V_131 ;
V_200 . V_66 = ( T_1 ) - 1 ;
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_200 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_23 ( V_32 ) ;
return V_5 ;
}
V_5 = F_168 ( V_4 , V_32 , V_117 , V_131 ) ;
if ( V_5 == 0 ) {
struct V_34 V_204 ;
F_88 ( V_32 -> V_48 [ 0 ] , & V_204 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_131 == V_204 . type )
V_195 = F_169 ( V_198 , V_204 . V_66 ) + 1 ;
}
goto V_205;
}
V_5 = F_168 ( V_4 , V_32 , V_117 , V_131 ) ;
if ( V_5 == 0 ) {
struct V_34 V_204 ;
F_88 ( V_32 -> V_48 [ 0 ] , & V_204 , V_32 -> V_49 [ 0 ] ) ;
if ( V_131 == V_204 . type ) {
V_195 = V_204 . V_66 ;
V_5 = F_19 ( V_2 , log , V_197 ,
V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
& V_204 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_205;
}
}
}
F_23 ( V_32 ) ;
V_5 = F_22 ( NULL , V_4 , & V_200 , V_32 , 0 , 0 ) ;
if ( V_5 != 0 ) {
F_113 ( 1 ) ;
goto V_205;
}
while ( 1 ) {
struct V_34 V_204 ;
V_202 = V_32 -> V_48 [ 0 ] ;
V_136 = F_105 ( V_202 ) ;
for ( V_148 = V_32 -> V_49 [ 0 ] ; V_148 < V_136 ; V_148 ++ ) {
F_88 ( V_202 , & V_200 , V_148 ) ;
if ( V_200 . V_43 != V_117 || V_200 . type != V_131 )
goto V_205;
V_5 = F_19 ( V_2 , log , V_197 , V_202 , V_148 ,
& V_200 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_205;
}
}
V_32 -> V_49 [ 0 ] = V_136 ;
V_5 = F_106 ( V_4 , V_32 ) ;
if ( V_5 == 1 ) {
V_196 = ( T_1 ) - 1 ;
goto V_205;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_204 , V_32 -> V_49 [ 0 ] ) ;
if ( V_204 . V_43 != V_117 || V_204 . type != V_131 ) {
V_196 = ( T_1 ) - 1 ;
goto V_205;
}
if ( F_127 ( V_32 -> V_48 [ 0 ] ) != V_2 -> V_60 ) {
V_5 = F_19 ( V_2 , log , V_197 ,
V_32 -> V_48 [ 0 ] , V_32 -> V_49 [ 0 ] ,
& V_204 ) ;
if ( V_5 )
V_6 = V_5 ;
else
V_196 = V_204 . V_66 ;
goto V_205;
}
}
V_205:
F_23 ( V_32 ) ;
F_23 ( V_197 ) ;
if ( V_6 == 0 ) {
* V_199 = V_196 ;
V_5 = F_164 ( V_2 , log , V_32 , V_131 ,
V_117 , V_195 , V_196 ) ;
if ( V_5 )
V_6 = V_5 ;
}
return V_6 ;
}
static T_2 int F_170 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_31 * V_32 ,
struct V_31 * V_197 )
{
T_1 V_200 ;
T_1 V_201 ;
int V_5 ;
int V_131 = V_129 ;
V_111:
V_200 = 0 ;
V_201 = 0 ;
while ( 1 ) {
V_5 = F_166 ( V_2 , V_4 , V_70 , V_32 ,
V_197 , V_131 , V_200 ,
& V_201 ) ;
if ( V_5 )
return V_5 ;
if ( V_201 == ( T_1 ) - 1 )
break;
V_200 = V_201 + 1 ;
}
if ( V_131 == V_129 ) {
V_131 = V_130 ;
goto V_111;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_32 ,
T_1 V_43 , int V_206 )
{
int V_5 ;
struct V_34 V_35 ;
struct V_34 V_125 ;
V_35 . V_43 = V_43 ;
V_35 . type = V_206 ;
V_35 . V_66 = ( T_1 ) - 1 ;
while ( 1 ) {
V_5 = F_22 ( V_2 , log , & V_35 , V_32 , - 1 , 1 ) ;
F_48 ( V_5 == 0 ) ;
if ( V_5 < 0 )
break;
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
F_88 ( V_32 -> V_48 [ 0 ] , & V_125 ,
V_32 -> V_49 [ 0 ] ) ;
if ( V_125 . V_43 != V_43 )
break;
V_5 = F_93 ( V_2 , log , V_32 ) ;
if ( V_5 )
break;
F_23 ( V_32 ) ;
}
F_23 ( V_32 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
return V_5 ;
}
static T_2 int F_172 ( struct V_1 * V_2 ,
struct V_3 * log ,
struct V_31 * V_197 ,
struct V_20 * V_202 ,
int V_207 , int V_208 , int V_209 )
{
unsigned long V_210 ;
unsigned long V_211 ;
struct V_68 * V_212 ;
struct V_56 * V_151 ;
int V_5 ;
struct V_34 * V_213 ;
T_3 * V_214 ;
char * V_215 ;
int V_148 ;
struct V_216 V_86 ;
F_173 ( & V_86 ) ;
V_215 = F_24 ( V_208 * sizeof( struct V_34 ) +
V_208 * sizeof( T_3 ) , V_51 ) ;
if ( ! V_215 )
return - V_52 ;
V_214 = ( T_3 * ) V_215 ;
V_213 = (struct V_34 * ) ( V_215 + V_208 * sizeof( T_3 ) ) ;
for ( V_148 = 0 ; V_148 < V_208 ; V_148 ++ ) {
V_214 [ V_148 ] = F_20 ( V_202 , V_148 + V_207 ) ;
F_88 ( V_202 , V_213 + V_148 , V_148 + V_207 ) ;
}
V_5 = F_174 ( V_2 , log , V_197 ,
V_213 , V_214 , V_208 ) ;
if ( V_5 ) {
F_25 ( V_215 ) ;
return V_5 ;
}
for ( V_148 = 0 ; V_148 < V_208 ; V_148 ++ , V_197 -> V_49 [ 0 ] ++ ) {
V_211 = F_21 ( V_197 -> V_48 [ 0 ] ,
V_197 -> V_49 [ 0 ] ) ;
V_210 = F_21 ( V_202 , V_207 + V_148 ) ;
F_34 ( V_197 -> V_48 [ 0 ] , V_202 , V_211 ,
V_210 , V_214 [ V_148 ] ) ;
if ( V_209 == V_217 &&
V_213 [ V_148 ] . type == V_55 ) {
V_151 = F_39 ( V_197 -> V_48 [ 0 ] ,
V_197 -> V_49 [ 0 ] ,
struct V_56 ) ;
F_35 ( V_197 -> V_48 [ 0 ] , V_151 , 0 ) ;
F_36 ( V_197 -> V_48 [ 0 ] ,
V_151 , 0 ) ;
}
if ( F_175 ( V_213 + V_148 ) == V_155 ) {
int V_61 ;
V_212 = F_39 ( V_202 , V_207 + V_148 ,
struct V_68 ) ;
if ( F_176 ( V_202 , V_212 ) < V_2 -> V_60 )
continue;
V_61 = F_40 ( V_202 , V_212 ) ;
if ( V_61 == V_72 ||
V_61 == V_73 ) {
T_1 V_218 , V_219 , V_220 , V_221 ;
V_218 = F_49 ( V_202 ,
V_212 ) ;
if ( V_218 == 0 )
continue;
V_219 = F_50 ( V_202 ,
V_212 ) ;
V_220 = F_51 ( V_202 , V_212 ) ;
V_221 = F_41 ( V_202 ,
V_212 ) ;
if ( F_56 ( V_202 ,
V_212 ) ) {
V_220 = 0 ;
V_221 = V_219 ;
}
V_5 = F_57 (
log -> V_15 -> V_91 ,
V_218 + V_220 , V_218 + V_220 + V_221 - 1 ,
& V_86 , 0 ) ;
F_48 ( V_5 ) ;
}
}
}
F_37 ( V_197 -> V_48 [ 0 ] ) ;
F_23 ( V_197 ) ;
F_25 ( V_215 ) ;
V_5 = 0 ;
while ( ! F_58 ( & V_86 ) ) {
struct V_87 * V_88 = F_59 ( V_86 . V_89 ,
struct V_87 ,
V_90 ) ;
if ( ! V_5 )
V_5 = F_60 ( V_2 , log , V_88 ) ;
F_61 ( & V_88 -> V_90 ) ;
F_25 ( V_88 ) ;
}
return V_5 ;
}
static int F_177 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
int V_209 )
{
struct V_31 * V_32 ;
struct V_31 * V_197 ;
struct V_34 V_200 ;
struct V_34 V_201 ;
struct V_3 * log = V_4 -> V_8 ;
struct V_20 * V_202 = NULL ;
int V_6 = 0 ;
int V_5 ;
int V_136 ;
int V_222 = 0 ;
int V_223 ;
T_1 V_117 = F_45 ( V_70 ) ;
log = V_4 -> V_8 ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_197 = F_76 () ;
if ( ! V_197 ) {
F_79 ( V_32 ) ;
return - V_52 ;
}
V_200 . V_43 = V_117 ;
V_200 . type = V_55 ;
V_200 . V_66 = 0 ;
V_201 . V_43 = V_117 ;
if ( ! F_31 ( V_70 -> V_121 ) )
V_209 = V_224 ;
if ( V_209 == V_217 || F_31 ( V_70 -> V_121 ) )
V_201 . type = V_154 ;
else
V_201 . type = ( T_4 ) - 1 ;
V_201 . V_66 = ( T_1 ) - 1 ;
V_5 = F_178 ( V_2 , V_70 ) ;
if ( V_5 ) {
F_79 ( V_32 ) ;
F_79 ( V_197 ) ;
return V_5 ;
}
F_2 ( & F_90 ( V_70 ) -> V_7 ) ;
if ( F_31 ( V_70 -> V_121 ) ) {
int V_206 = V_145 ;
if ( V_209 == V_217 )
V_206 = V_154 ;
V_5 = F_171 ( V_2 , log , V_32 , V_117 , V_206 ) ;
} else {
V_5 = F_179 ( V_2 , log , V_70 , 0 , 0 ) ;
}
if ( V_5 ) {
V_6 = V_5 ;
goto V_192;
}
V_32 -> V_203 = 1 ;
while ( 1 ) {
V_223 = 0 ;
V_5 = F_167 ( V_4 , & V_200 , & V_201 ,
V_32 , 0 , V_2 -> V_60 ) ;
if ( V_5 != 0 )
break;
V_111:
if ( V_200 . V_43 != V_117 )
break;
if ( V_200 . type > V_201 . type )
break;
V_202 = V_32 -> V_48 [ 0 ] ;
if ( V_223 && V_222 + V_223 == V_32 -> V_49 [ 0 ] ) {
V_223 ++ ;
goto V_225;
} else if ( ! V_223 ) {
V_222 = V_32 -> V_49 [ 0 ] ;
V_223 = 1 ;
goto V_225;
}
V_5 = F_172 ( V_2 , log , V_197 , V_202 , V_222 ,
V_223 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_192;
}
V_223 = 1 ;
V_222 = V_32 -> V_49 [ 0 ] ;
V_225:
V_136 = F_105 ( V_32 -> V_48 [ 0 ] ) ;
V_32 -> V_49 [ 0 ] ++ ;
if ( V_32 -> V_49 [ 0 ] < V_136 ) {
F_88 ( V_32 -> V_48 [ 0 ] , & V_200 ,
V_32 -> V_49 [ 0 ] ) ;
goto V_111;
}
if ( V_223 ) {
V_5 = F_172 ( V_2 , log , V_197 , V_202 ,
V_222 ,
V_223 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_192;
}
V_223 = 0 ;
}
F_23 ( V_32 ) ;
if ( V_200 . V_66 < ( T_1 ) - 1 )
V_200 . V_66 ++ ;
else if ( V_200 . type < ( T_4 ) - 1 )
V_200 . type ++ ;
else if ( V_200 . V_43 < ( T_1 ) - 1 )
V_200 . V_43 ++ ;
else
break;
}
if ( V_223 ) {
V_5 = F_172 ( V_2 , log , V_197 , V_202 ,
V_222 ,
V_223 , V_209 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_192;
}
V_223 = 0 ;
}
F_113 ( V_223 ) ;
if ( V_209 == V_224 && F_31 ( V_70 -> V_121 ) ) {
F_23 ( V_32 ) ;
F_23 ( V_197 ) ;
V_5 = F_170 ( V_2 , V_4 , V_70 , V_32 , V_197 ) ;
if ( V_5 ) {
V_6 = V_5 ;
goto V_192;
}
}
F_90 ( V_70 ) -> V_191 = V_2 -> V_60 ;
V_192:
F_4 ( & F_90 ( V_70 ) -> V_7 ) ;
F_79 ( V_32 ) ;
F_79 ( V_197 ) ;
return V_6 ;
}
static T_2 int F_180 ( struct V_1 * V_2 ,
struct V_70 * V_70 ,
struct V_226 * V_160 ,
struct V_227 * V_228 ,
T_1 V_229 )
{
int V_5 = 0 ;
struct V_3 * V_4 ;
struct V_226 * V_230 = NULL ;
if ( F_111 ( V_70 -> V_121 ) &&
F_90 ( V_70 ) -> V_231 <= V_229 &&
F_90 ( V_70 ) -> V_232 <= V_229 )
goto V_75;
if ( ! F_31 ( V_70 -> V_121 ) ) {
if ( ! V_160 || ! V_160 -> V_233 || V_228 != V_160 -> V_233 -> V_234 )
goto V_75;
V_70 = V_160 -> V_233 ;
}
while ( 1 ) {
F_90 ( V_70 ) -> V_191 = V_2 -> V_60 ;
F_8 () ;
if ( F_90 ( V_70 ) -> V_232 > V_229 ) {
V_4 = F_90 ( V_70 ) -> V_4 ;
V_4 -> V_15 -> V_171 =
V_2 -> V_60 ;
V_5 = 1 ;
break;
}
if ( ! V_160 || ! V_160 -> V_233 || V_228 != V_160 -> V_233 -> V_234 )
break;
if ( F_181 ( V_160 ) )
break;
V_160 = F_182 ( V_160 ) ;
F_183 ( V_230 ) ;
V_230 = V_160 ;
V_70 = V_160 -> V_233 ;
}
F_183 ( V_230 ) ;
V_75:
return V_5 ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_70 ,
struct V_226 * V_160 , int V_235 )
{
int V_209 = V_235 ? V_217 : V_224 ;
struct V_227 * V_228 ;
struct V_226 * V_230 = NULL ;
int V_5 = 0 ;
T_1 V_229 = V_4 -> V_15 -> V_236 ;
V_228 = V_70 -> V_234 ;
if ( F_142 ( V_4 , V_237 ) ) {
V_5 = 1 ;
goto V_238;
}
if ( V_4 -> V_15 -> V_171 >
V_4 -> V_15 -> V_236 ) {
V_5 = 1 ;
goto V_238;
}
if ( V_4 != F_90 ( V_70 ) -> V_4 ||
F_185 ( & V_4 -> V_168 ) == 0 ) {
V_5 = 1 ;
goto V_238;
}
V_5 = F_180 ( V_2 , V_70 , V_160 ,
V_228 , V_229 ) ;
if ( V_5 )
goto V_238;
if ( F_186 ( V_70 , V_2 -> V_60 ) ) {
V_5 = V_239 ;
goto V_238;
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_240;
V_5 = F_177 ( V_2 , V_4 , V_70 , V_209 ) ;
if ( V_5 )
goto V_240;
if ( F_111 ( V_70 -> V_121 ) &&
F_90 ( V_70 ) -> V_231 <= V_229 &&
F_90 ( V_70 ) -> V_232 <= V_229 ) {
V_5 = 0 ;
goto V_240;
}
V_209 = V_217 ;
while ( 1 ) {
if ( ! V_160 || ! V_160 -> V_233 || V_228 != V_160 -> V_233 -> V_234 )
break;
V_70 = V_160 -> V_233 ;
if ( V_4 != F_90 ( V_70 ) -> V_4 )
break;
if ( F_90 ( V_70 ) -> V_231 >
V_4 -> V_15 -> V_236 ) {
V_5 = F_177 ( V_2 , V_4 , V_70 , V_209 ) ;
if ( V_5 )
goto V_240;
}
if ( F_181 ( V_160 ) )
break;
V_160 = F_182 ( V_160 ) ;
F_183 ( V_230 ) ;
V_230 = V_160 ;
}
V_5 = 0 ;
V_240:
F_183 ( V_230 ) ;
if ( V_5 < 0 ) {
F_48 ( V_5 != - V_182 ) ;
V_4 -> V_15 -> V_171 = V_2 -> V_60 ;
V_5 = 1 ;
}
F_10 ( V_4 ) ;
V_238:
return V_5 ;
}
int F_187 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_226 * V_226 )
{
struct V_226 * V_160 = F_182 ( V_226 ) ;
int V_5 ;
V_5 = F_184 ( V_2 , V_4 , V_226 -> V_233 , V_160 , 0 ) ;
F_183 ( V_160 ) ;
return V_5 ;
}
int F_188 ( struct V_3 * V_17 )
{
int V_5 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_34 V_35 ;
struct V_34 V_125 ;
struct V_34 V_241 ;
struct V_3 * log ;
struct V_188 * V_15 = V_17 -> V_15 ;
struct V_22 V_23 = {
. V_163 = F_14 ,
. V_149 = 0 ,
} ;
V_32 = F_76 () ;
if ( ! V_32 )
return - V_52 ;
V_15 -> V_242 = 1 ;
V_2 = F_189 ( V_15 -> V_185 , 0 ) ;
if ( F_73 ( V_2 ) ) {
V_5 = F_160 ( V_2 ) ;
goto error;
}
V_23 . V_2 = V_2 ;
V_23 . V_25 = 1 ;
V_5 = F_128 ( V_2 , V_17 , & V_23 ) ;
if ( V_5 ) {
F_190 ( V_15 , V_5 , L_1
L_2 ) ;
goto error;
}
V_111:
V_35 . V_43 = V_44 ;
V_35 . V_66 = ( T_1 ) - 1 ;
F_94 ( & V_35 , V_243 ) ;
while ( 1 ) {
V_5 = F_22 ( NULL , V_17 , & V_35 , V_32 , 0 , 0 ) ;
if ( V_5 < 0 ) {
F_190 ( V_15 , V_5 ,
L_3 ) ;
goto error;
}
if ( V_5 > 0 ) {
if ( V_32 -> V_49 [ 0 ] == 0 )
break;
V_32 -> V_49 [ 0 ] -- ;
}
F_88 ( V_32 -> V_48 [ 0 ] , & V_125 ,
V_32 -> V_49 [ 0 ] ) ;
F_23 ( V_32 ) ;
if ( V_125 . V_43 != V_44 )
break;
log = F_191 ( V_17 ,
& V_125 ) ;
if ( F_73 ( log ) ) {
V_5 = F_160 ( log ) ;
F_190 ( V_15 , V_5 ,
L_4 ) ;
goto error;
}
V_241 . V_43 = V_125 . V_66 ;
V_241 . type = V_243 ;
V_241 . V_66 = ( T_1 ) - 1 ;
V_23 . V_146 = F_192 ( V_15 , & V_241 ) ;
if ( F_73 ( V_23 . V_146 ) ) {
V_5 = F_160 ( V_23 . V_146 ) ;
F_190 ( V_15 , V_5 , L_5
L_6 ) ;
goto error;
}
V_23 . V_146 -> V_8 = log ;
F_193 ( V_2 , V_23 . V_146 ) ;
V_5 = F_128 ( V_2 , log , & V_23 ) ;
F_48 ( V_5 ) ;
if ( V_23 . V_149 == V_153 ) {
V_5 = F_92 ( V_2 , V_23 . V_146 ,
V_32 ) ;
F_48 ( V_5 ) ;
}
V_35 . V_66 = V_125 . V_66 - 1 ;
V_23 . V_146 -> V_8 = NULL ;
F_119 ( log -> V_164 ) ;
F_119 ( log -> V_244 ) ;
F_25 ( log ) ;
if ( V_125 . V_66 == 0 )
break;
}
F_23 ( V_32 ) ;
if ( V_23 . V_25 ) {
V_23 . V_25 = 0 ;
V_23 . V_163 = F_108 ;
V_23 . V_149 = V_150 ;
goto V_111;
}
if ( V_23 . V_149 < V_153 ) {
V_23 . V_149 ++ ;
goto V_111;
}
F_79 ( V_32 ) ;
F_119 ( V_17 -> V_164 ) ;
V_17 -> V_8 = NULL ;
V_15 -> V_242 = 0 ;
F_194 ( V_2 , V_15 -> V_185 ) ;
F_25 ( V_17 ) ;
return 0 ;
error:
F_79 ( V_32 ) ;
return V_5 ;
}
void F_195 ( struct V_1 * V_2 ,
struct V_70 * V_92 , struct V_70 * V_70 ,
int V_245 )
{
if ( F_111 ( V_70 -> V_121 ) )
F_90 ( V_70 ) -> V_232 = V_2 -> V_60 ;
F_8 () ;
if ( F_90 ( V_92 ) -> V_191 == V_2 -> V_60 )
return;
if ( F_90 ( V_70 ) -> V_191 == V_2 -> V_60 )
return;
if ( V_245 )
goto V_246;
return;
V_246:
F_90 ( V_92 ) -> V_232 = V_2 -> V_60 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_70 * V_247 ,
struct V_226 * V_160 )
{
struct V_3 * V_4 = F_90 ( V_70 ) -> V_4 ;
if ( F_111 ( V_70 -> V_121 ) )
F_90 ( V_70 ) -> V_232 = V_2 -> V_60 ;
if ( F_90 ( V_70 ) -> V_191 <=
V_4 -> V_15 -> V_236 &&
( ! V_247 || F_90 ( V_247 ) -> V_191 <=
V_4 -> V_15 -> V_236 ) )
return 0 ;
return F_184 ( V_2 , V_4 , V_70 , V_160 , 1 ) ;
}
