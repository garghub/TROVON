static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 V_8 ;
struct V_7 V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_1 = NULL ;
int V_16 ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( NULL , V_3 , & V_8 , V_5 , 0 , 0 ) ;
if ( V_16 < 0 )
return F_3 ( V_16 ) ;
if ( V_16 > 0 ) {
F_4 ( V_5 ) ;
return F_3 ( - V_19 ) ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_6 ( V_15 , V_13 , & V_11 ) ;
F_7 ( & V_9 , & V_11 ) ;
F_4 ( V_5 ) ;
V_1 = F_8 ( V_3 -> V_22 -> V_23 , & V_9 , V_3 , NULL ) ;
if ( ! V_1 )
return F_3 ( - V_19 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
if ( F_10 ( V_1 ) ) {
F_11 ( V_1 ) ;
return F_3 ( - V_19 ) ;
}
V_1 -> V_24 -> V_25 &= ~ V_26 ;
return V_1 ;
}
struct V_1 * F_12 ( struct V_2 * V_3 ,
struct V_27
* V_28 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_13 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_1 )
V_1 = F_14 ( V_28 -> V_1 ) ;
F_15 ( & V_28 -> V_29 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 ,
V_28 -> V_8 . V_17 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_28 -> V_29 ) ;
if ( F_16 ( V_1 ) -> V_25 & V_30 ) {
F_17 ( V_31 L_1 ) ;
F_16 ( V_1 ) -> V_25 &= ~ V_30 ;
V_28 -> V_32 = V_33 ;
}
if ( ! F_18 ( V_3 -> V_22 ) ) {
V_28 -> V_1 = F_14 ( V_1 ) ;
V_28 -> V_34 = 1 ;
}
F_15 ( & V_28 -> V_29 ) ;
return V_1 ;
}
int F_19 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 , T_1 V_37 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
int V_16 ;
V_16 = F_20 ( V_36 , V_3 , V_5 , V_37 ) ;
if ( V_16 )
return V_16 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_39 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_38 ) ;
F_21 ( V_15 , & V_11 , V_5 -> V_21 [ 0 ] ) ;
F_22 ( V_15 , 0 , ( unsigned long ) V_39 ,
sizeof( * V_39 ) ) ;
F_23 ( V_15 , V_39 , V_36 -> V_40 ) ;
F_24 ( V_15 , V_39 , 0 ) ;
F_25 ( V_15 , V_39 , 0 ) ;
F_26 ( V_15 , V_39 , 0 ) ;
F_27 ( V_15 , V_39 , 0 ) ;
F_28 ( V_15 , V_39 , V_41 | 0600 ) ;
F_29 ( V_15 , V_39 , V_42 |
V_43 ) ;
F_30 ( V_15 , V_39 , 1 ) ;
F_31 ( V_15 , V_39 , V_36 -> V_40 ) ;
F_32 ( V_15 , V_39 , V_6 ) ;
F_33 ( V_15 ) ;
F_4 ( V_5 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_34 ( V_36 , V_3 , V_5 , & V_8 ,
sizeof( struct V_12 ) ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 ) ;
return V_16 ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_22 ( V_15 , 0 , ( unsigned long ) V_13 , sizeof( * V_13 ) ) ;
F_35 ( V_15 , V_13 , & V_11 ) ;
F_33 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_37 ;
V_16 = F_37 ( V_3 , & V_37 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_19 ( V_3 , V_36 , V_5 , V_37 ,
V_28 -> V_8 . V_17 ) ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_44 * V_45 ;
T_2 V_46 ;
int V_16 = 0 ;
V_45 = V_36 -> V_47 ;
V_36 -> V_47 = V_3 -> V_48 ;
V_16 = F_39 ( V_36 , V_3 ,
V_3 -> V_48 ,
0 , 5 ) ;
if ( V_16 )
return V_16 ;
V_46 = F_40 ( V_1 ) ;
F_41 ( V_1 , 0 ) ;
F_42 ( V_1 , V_46 , 0 ) ;
V_16 = F_43 ( V_36 , V_3 , V_1 ,
0 , V_49 ) ;
V_36 -> V_47 = V_45 ;
if ( V_16 ) {
F_44 ( 1 ) ;
return V_16 ;
}
V_16 = F_45 ( V_36 , V_3 , V_1 ) ;
return V_16 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_50 * V_51 ;
unsigned long V_52 ;
V_51 = F_47 ( sizeof( * V_51 ) , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
F_48 ( V_51 , V_1 -> V_24 ) ;
V_52 = ( F_40 ( V_1 ) - 1 ) >> V_55 ;
F_49 ( V_1 -> V_24 , V_51 , NULL , 0 , V_52 ) ;
F_50 ( V_51 ) ;
return 0 ;
}
int F_51 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_56 * V_57 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_58 * V_58 ;
struct V_7 V_8 ;
struct V_59 V_60 ;
T_1 V_61 ;
T_1 V_62 ;
T_1 V_63 ;
T_3 V_64 = 0 ;
int V_16 = 0 ;
F_52 ( & V_60 ) ;
if ( ! F_40 ( V_1 ) )
goto V_65;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( NULL , V_3 , & V_8 , V_5 , 0 , 0 ) ;
if ( V_16 < 0 )
goto V_65;
else if ( V_16 > 0 ) {
F_4 ( V_5 ) ;
V_16 = 0 ;
goto V_65;
}
V_16 = - 1 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
V_61 = F_53 ( V_15 , V_13 ) ;
V_62 = F_54 ( V_15 , V_13 ) ;
V_63 = F_55 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_16 ( V_1 ) -> V_63 != V_63 ) {
F_17 ( V_66 L_2
L_3 ,
( unsigned long long ) F_16 ( V_1 ) -> V_63 ,
( unsigned long long ) V_63 ) ;
goto V_65;
}
if ( ! V_61 )
goto V_65;
V_16 = F_46 ( V_1 ) ;
if ( V_16 )
goto V_65;
while ( 1 ) {
struct V_67 * V_68 ;
struct V_69 * V_70 ;
void * V_71 ;
unsigned long V_6 = 0 ;
int V_72 = 0 ;
if ( ! V_61 && ! V_62 )
break;
V_58 = F_56 ( V_1 -> V_24 , V_64 , V_53 ) ;
if ( ! V_58 )
goto V_73;
if ( ! F_57 ( V_58 ) ) {
F_58 ( NULL , V_58 ) ;
F_59 ( V_58 ) ;
if ( ! F_57 ( V_58 ) ) {
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
F_17 ( V_66 L_4
L_5 ) ;
goto V_73;
}
}
V_71 = F_62 ( V_58 ) ;
if ( V_64 == 0 ) {
T_1 * V_74 ;
V_71 += sizeof( T_1 ) ;
V_6 += sizeof( T_1 ) ;
V_74 = V_71 ;
if ( * V_74 != F_16 ( V_1 ) -> V_63 ) {
F_17 ( V_66 L_6
L_7 ,
( unsigned long long ) * V_74 ,
( unsigned long long )
F_16 ( V_1 ) -> V_63 ) ;
F_63 ( V_58 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
V_71 += sizeof( T_1 ) ;
V_6 += sizeof( T_1 ) ;
}
V_68 = V_71 ;
while ( 1 ) {
if ( ! V_61 )
break;
V_72 = 1 ;
V_70 = F_64 ( V_75 ,
V_53 ) ;
if ( ! V_70 ) {
F_63 ( V_58 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
V_70 -> V_6 = F_65 ( V_68 -> V_6 ) ;
V_70 -> V_76 = F_65 ( V_68 -> V_76 ) ;
if ( ! V_70 -> V_76 ) {
F_63 ( V_58 ) ;
F_66 ( V_75 , V_70 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
if ( V_68 -> type == V_77 ) {
F_13 ( & V_57 -> V_78 ) ;
V_16 = F_67 ( V_57 , V_70 ) ;
F_15 ( & V_57 -> V_78 ) ;
if ( V_16 ) {
F_17 ( V_66 L_8
L_9 ) ;
F_63 ( V_58 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
} else {
V_70 -> V_79 = F_47 ( V_80 , V_53 ) ;
if ( ! V_70 -> V_79 ) {
F_63 ( V_58 ) ;
F_66 (
V_75 , V_70 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
F_13 ( & V_57 -> V_78 ) ;
V_16 = F_67 ( V_57 , V_70 ) ;
V_57 -> V_81 ++ ;
V_57 -> V_82 -> V_83 ( V_57 ) ;
F_15 ( & V_57 -> V_78 ) ;
if ( V_16 ) {
F_17 ( V_66 L_8
L_9 ) ;
F_63 ( V_58 ) ;
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
goto V_73;
}
F_68 ( & V_70 -> V_84 , & V_60 ) ;
}
V_61 -- ;
V_6 += sizeof( struct V_67 ) ;
if ( V_6 + sizeof( struct V_67 ) >=
V_80 )
break;
V_68 ++ ;
}
if ( V_72 ) {
F_63 ( V_58 ) ;
goto V_85;
}
V_70 = F_69 ( V_60 . V_85 , struct V_69 , V_84 ) ;
F_70 ( & V_70 -> V_84 ) ;
memcpy ( V_70 -> V_79 , V_71 , V_80 ) ;
F_63 ( V_58 ) ;
V_62 -- ;
V_85:
F_60 ( V_58 ) ;
F_61 ( V_58 ) ;
V_64 ++ ;
}
V_16 = 1 ;
V_65:
return V_16 ;
V_73:
F_71 ( V_57 ) ;
goto V_65;
}
int F_72 ( struct V_86 * V_22 ,
struct V_27 * V_28 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_2 * V_3 = V_22 -> V_88 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 ;
bool V_89 ;
T_1 V_90 = F_73 ( & V_28 -> V_91 ) ;
if ( F_18 ( V_22 ) )
return 0 ;
F_13 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_32 != V_92 ) {
F_15 ( & V_28 -> V_29 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_29 ) ;
V_5 = F_74 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_75 ( V_5 ) ;
return 0 ;
}
V_16 = F_51 ( V_22 -> V_88 , V_1 , V_57 ,
V_5 , V_28 -> V_8 . V_17 ) ;
F_75 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_65;
F_13 ( & V_57 -> V_78 ) ;
V_89 = ( V_57 -> V_93 == ( V_28 -> V_8 . V_6 - V_90 -
V_28 -> V_94 ) ) ;
F_15 ( & V_57 -> V_78 ) ;
if ( ! V_89 ) {
F_71 ( V_57 ) ;
F_17 ( V_66 L_10
L_11 , V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_65:
if ( V_16 < 0 ) {
F_13 ( & V_28 -> V_29 ) ;
V_28 -> V_32 = V_33 ;
F_15 ( & V_28 -> V_29 ) ;
V_16 = 0 ;
F_17 ( V_66 L_12
L_13 , V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
int F_76 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_56 * V_57 ,
struct V_27 * V_28 ,
struct V_35 * V_36 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_95 * V_96 ;
struct V_59 * V_97 , * V_98 ;
struct V_58 * * V_99 ;
struct V_58 * V_58 ;
struct V_100 * V_101 = NULL ;
struct V_102 * V_103 = NULL ;
struct V_104 * V_105 = NULL ;
struct V_59 V_106 ;
struct V_7 V_8 ;
T_1 V_107 , V_108 , V_109 ;
T_1 V_76 = 0 ;
T_4 V_110 = ~ ( T_4 ) 0 ;
int V_64 = 0 , V_111 = 0 ;
int V_112 = 0 ;
int V_60 = 0 ;
int V_16 = - 1 ;
bool V_113 = false ;
bool V_114 = false ;
F_52 ( & V_106 ) ;
V_96 = F_77 ( & V_57 -> V_115 ) ;
if ( ! V_96 )
return 0 ;
if ( ! F_40 ( V_1 ) )
return - 1 ;
V_111 = ( F_40 ( V_1 ) + V_80 - 1 ) >>
V_55 ;
F_78 ( V_1 -> V_24 ) ;
F_79 ( V_1 , V_1 -> V_116 &
~ ( V_3 -> V_117 - 1 ) , ( T_1 ) - 1 ) ;
V_99 = F_47 ( sizeof( struct V_58 * ) * V_111 , V_53 ) ;
if ( ! V_99 )
return - 1 ;
if ( V_28 && ! F_80 ( & V_28 -> V_118 ) )
V_103 = F_69 ( V_28 -> V_118 . V_85 ,
struct V_102 ,
V_119 ) ;
V_105 = V_3 -> V_22 -> V_120 ;
while ( V_64 < V_111 ) {
V_58 = F_56 ( V_1 -> V_24 , V_64 , V_53 ) ;
if ( ! V_58 ) {
int V_121 ;
for ( V_121 = 0 ; V_121 < V_111 ; V_121 ++ ) {
F_60 ( V_99 [ V_121 ] ) ;
F_61 ( V_99 [ V_121 ] ) ;
}
goto V_65;
}
V_99 [ V_64 ] = V_58 ;
V_64 ++ ;
}
V_64 = 0 ;
F_81 ( & F_16 ( V_1 ) -> V_122 , 0 , F_40 ( V_1 ) - 1 ,
0 , & V_101 , V_53 ) ;
if ( V_28 )
V_107 = V_28 -> V_8 . V_17 ;
do {
struct V_67 * V_68 ;
void * V_71 , * V_123 ;
unsigned long V_6 = 0 ;
V_113 = false ;
if ( V_64 >= V_111 ) {
V_114 = true ;
break;
}
V_58 = V_99 [ V_64 ] ;
V_123 = V_71 = F_62 ( V_58 ) ;
if ( V_64 == 0 ) {
T_1 * V_74 ;
V_71 += sizeof( T_1 ) ;
V_6 += sizeof( T_1 ) ;
V_74 = V_71 ;
* V_74 = V_36 -> V_40 ;
V_71 += sizeof( T_1 ) ;
V_6 += sizeof( T_1 ) ;
}
V_68 = V_71 ;
memset ( V_71 , 0 , V_80 - V_6 ) ;
while ( V_96 && ! V_113 ) {
struct V_69 * V_70 ;
V_70 = F_82 ( V_96 , struct V_69 , V_124 ) ;
V_112 ++ ;
V_68 -> V_6 = F_83 ( V_70 -> V_6 ) ;
V_68 -> V_76 = F_83 ( V_70 -> V_76 ) ;
if ( V_70 -> V_79 ) {
V_68 -> type = V_125 ;
F_68 ( & V_70 -> V_84 , & V_106 ) ;
V_60 ++ ;
} else {
V_68 -> type = V_77 ;
}
V_96 = F_84 ( V_96 ) ;
if ( ! V_96 && V_103 ) {
V_96 = F_77 ( & V_103 -> V_3 ) ;
V_103 = NULL ;
}
V_6 += sizeof( struct V_67 ) ;
if ( V_6 + sizeof( struct V_67 ) >=
V_80 )
V_113 = true ;
V_68 ++ ;
}
while ( V_28 && ! V_113 &&
( V_107 < V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 ) ) {
V_16 = F_85 ( V_105 , V_107 , & V_107 , & V_108 ,
V_126 ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_107 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
break;
V_109 = V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 - V_107 ;
V_109 = F_86 ( V_109 , V_108 + 1 - V_107 ) ;
V_112 ++ ;
V_68 -> V_6 = F_83 ( V_107 ) ;
V_68 -> V_76 = F_83 ( V_109 ) ;
V_68 -> type = V_77 ;
V_107 = V_108 + 1 ;
V_6 += sizeof( struct V_67 ) ;
if ( V_6 + sizeof( struct V_67 ) >=
V_80 )
V_113 = true ;
V_68 ++ ;
}
if ( V_64 == 0 ) {
T_4 * V_127 ;
V_110 = F_87 ( V_3 , V_123 + sizeof( T_1 ) , V_110 ,
V_80 - sizeof( T_1 ) ) ;
F_88 ( V_110 , ( char * ) & V_110 ) ;
V_110 ++ ;
V_127 = V_123 ;
* V_127 = V_110 ;
}
F_63 ( V_58 ) ;
V_76 += V_80 ;
V_64 ++ ;
} while ( V_96 || V_113 );
F_89 (pos, n, &bitmap_list) {
void * V_71 ;
struct V_69 * V_68 =
F_69 ( V_97 , struct V_69 , V_84 ) ;
if ( V_64 >= V_111 ) {
V_114 = true ;
break;
}
V_58 = V_99 [ V_64 ] ;
V_71 = F_62 ( V_58 ) ;
memcpy ( V_71 , V_68 -> V_79 , V_80 ) ;
F_63 ( V_58 ) ;
V_76 += V_80 ;
F_70 ( & V_68 -> V_84 ) ;
V_64 ++ ;
}
if ( V_114 ) {
F_90 ( V_99 , V_111 ) ;
F_91 ( & F_16 ( V_1 ) -> V_122 , 0 ,
F_40 ( V_1 ) - 1 , & V_101 ,
V_53 ) ;
V_16 = 0 ;
goto V_65;
}
while ( V_64 < V_111 ) {
void * V_71 ;
V_58 = V_99 [ V_64 ] ;
V_71 = F_62 ( V_58 ) ;
memset ( V_71 , 0 , V_80 ) ;
F_63 ( V_58 ) ;
V_76 += V_80 ;
V_64 ++ ;
}
V_16 = F_92 ( V_3 , V_1 , V_99 , V_111 , 0 ,
V_76 , & V_101 ) ;
F_90 ( V_99 , V_111 ) ;
F_91 ( & F_16 ( V_1 ) -> V_122 , 0 ,
F_40 ( V_1 ) - 1 , & V_101 , V_53 ) ;
if ( V_16 ) {
V_16 = 0 ;
goto V_65;
}
F_16 ( V_1 ) -> V_63 = V_36 -> V_40 ;
F_78 ( V_1 -> V_24 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_36 , V_3 , & V_8 , V_5 , 1 , 1 ) ;
if ( V_16 < 0 ) {
V_16 = - 1 ;
F_93 ( & F_16 ( V_1 ) -> V_122 , 0 , V_76 - 1 ,
V_126 | V_128 |
V_129 , 0 , 0 , NULL , V_53 ) ;
goto V_65;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_130 ;
F_94 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_95 ( V_15 , & V_130 , V_5 -> V_21 [ 0 ] ) ;
if ( V_130 . V_17 != V_18 ||
V_130 . V_6 != V_6 ) {
V_16 = - 1 ;
F_93 ( & F_16 ( V_1 ) -> V_122 , 0 , V_76 - 1 ,
V_126 | V_128 |
V_129 , 0 , 0 , NULL ,
V_53 ) ;
F_4 ( V_5 ) ;
goto V_65;
}
}
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_96 ( V_15 , V_13 , V_112 ) ;
F_97 ( V_15 , V_13 , V_60 ) ;
F_98 ( V_15 , V_13 , V_36 -> V_40 ) ;
F_33 ( V_15 ) ;
F_4 ( V_5 ) ;
V_16 = 1 ;
V_65:
F_50 ( V_99 ) ;
if ( V_16 != 1 ) {
F_99 ( V_1 -> V_24 , 0 , V_64 ) ;
F_16 ( V_1 ) -> V_63 = 0 ;
}
F_45 ( V_36 , V_3 , V_1 ) ;
return V_16 ;
}
int F_100 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_88 ;
F_13 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_32 < V_131 ) {
F_15 ( & V_28 -> V_29 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_29 ) ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_76 ( V_3 , V_1 , V_57 , V_28 , V_36 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 < 0 ) {
F_13 ( & V_28 -> V_29 ) ;
V_28 -> V_32 = V_132 ;
F_15 ( & V_28 -> V_29 ) ;
V_16 = 0 ;
F_17 ( V_66 L_14
L_13 , V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_101 ( T_1 V_133 , T_4 V_134 ,
T_1 V_6 )
{
F_94 ( V_6 < V_133 ) ;
V_6 -= V_133 ;
return ( unsigned long ) ( F_102 ( V_6 , V_134 ) ) ;
}
static inline unsigned long F_103 ( T_1 V_76 , T_4 V_134 )
{
return ( unsigned long ) ( F_102 ( V_76 , V_134 ) ) ;
}
static inline T_1 F_104 ( struct V_56 * V_57 ,
T_1 V_6 )
{
T_1 V_133 ;
T_1 V_135 ;
V_135 = V_136 * V_57 -> V_134 ;
V_133 = V_6 - V_57 -> V_107 ;
V_133 = F_105 ( V_133 , V_135 ) ;
V_133 *= V_135 ;
V_133 += V_57 -> V_107 ;
return V_133 ;
}
static int F_106 ( struct V_137 * V_3 , T_1 V_6 ,
struct V_95 * V_96 , int V_79 )
{
struct V_95 * * V_138 = & V_3 -> V_95 ;
struct V_95 * V_139 = NULL ;
struct V_69 * V_140 ;
while ( * V_138 ) {
V_139 = * V_138 ;
V_140 = F_82 ( V_139 , struct V_69 , V_124 ) ;
if ( V_6 < V_140 -> V_6 ) {
V_138 = & ( * V_138 ) -> V_141 ;
} else if ( V_6 > V_140 -> V_6 ) {
V_138 = & ( * V_138 ) -> V_142 ;
} else {
if ( V_79 ) {
if ( V_140 -> V_79 ) {
F_107 ( 1 ) ;
return - V_143 ;
}
V_138 = & ( * V_138 ) -> V_142 ;
} else {
if ( ! V_140 -> V_79 ) {
F_107 ( 1 ) ;
return - V_143 ;
}
V_138 = & ( * V_138 ) -> V_141 ;
}
}
}
F_108 ( V_96 , V_139 , V_138 ) ;
F_109 ( V_96 , V_3 ) ;
return 0 ;
}
static struct V_69 *
F_110 ( struct V_56 * V_57 ,
T_1 V_6 , int V_144 , int V_145 )
{
struct V_95 * V_98 = V_57 -> V_115 . V_95 ;
struct V_69 * V_68 , * V_146 = NULL ;
while ( 1 ) {
if ( ! V_98 ) {
V_68 = NULL ;
break;
}
V_68 = F_82 ( V_98 , struct V_69 , V_124 ) ;
V_146 = V_68 ;
if ( V_6 < V_68 -> V_6 )
V_98 = V_98 -> V_141 ;
else if ( V_6 > V_68 -> V_6 )
V_98 = V_98 -> V_142 ;
else
break;
}
if ( V_144 ) {
if ( ! V_68 )
return NULL ;
if ( V_68 -> V_79 )
return V_68 ;
V_98 = F_84 ( V_98 ) ;
if ( ! V_98 )
return NULL ;
V_68 = F_82 ( V_98 , struct V_69 , V_124 ) ;
if ( V_68 -> V_6 != V_6 )
return NULL ;
F_44 ( ! V_68 -> V_79 ) ;
return V_68 ;
} else if ( V_68 ) {
if ( V_68 -> V_79 ) {
V_98 = & V_68 -> V_124 ;
while ( 1 ) {
V_98 = F_111 ( V_98 ) ;
if ( ! V_98 )
break;
V_146 = F_82 ( V_98 , struct V_69 ,
V_124 ) ;
if ( ! V_146 -> V_79 ) {
if ( V_146 -> V_6 + V_146 -> V_76 > V_6 )
V_68 = V_146 ;
break;
}
}
}
return V_68 ;
}
if ( ! V_146 )
return NULL ;
V_68 = V_146 ;
if ( V_68 -> V_6 > V_6 ) {
V_98 = F_111 ( & V_68 -> V_124 ) ;
if ( V_98 ) {
V_68 = F_82 ( V_98 , struct V_69 ,
V_124 ) ;
F_94 ( V_68 -> V_6 > V_6 ) ;
} else {
if ( V_145 )
return V_68 ;
else
return NULL ;
}
}
if ( V_68 -> V_79 ) {
V_98 = & V_68 -> V_124 ;
while ( 1 ) {
V_98 = F_111 ( V_98 ) ;
if ( ! V_98 )
break;
V_146 = F_82 ( V_98 , struct V_69 ,
V_124 ) ;
if ( ! V_146 -> V_79 ) {
if ( V_146 -> V_6 + V_146 -> V_76 > V_6 )
return V_146 ;
break;
}
}
if ( V_68 -> V_6 + V_136 * V_57 -> V_134 > V_6 )
return V_68 ;
} else if ( V_68 -> V_6 + V_68 -> V_76 > V_6 )
return V_68 ;
if ( ! V_145 )
return NULL ;
while ( 1 ) {
if ( V_68 -> V_79 ) {
if ( V_68 -> V_6 + V_136 *
V_57 -> V_134 > V_6 )
break;
} else {
if ( V_68 -> V_6 + V_68 -> V_76 > V_6 )
break;
}
V_98 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_98 )
return NULL ;
V_68 = F_82 ( V_98 , struct V_69 , V_124 ) ;
}
return V_68 ;
}
static inline void
F_112 ( struct V_56 * V_57 ,
struct V_69 * V_140 )
{
F_113 ( & V_140 -> V_124 , & V_57 -> V_115 ) ;
V_57 -> V_147 -- ;
}
static void F_114 ( struct V_56 * V_57 ,
struct V_69 * V_140 )
{
F_112 ( V_57 , V_140 ) ;
V_57 -> V_93 -= V_140 -> V_76 ;
}
static int F_67 ( struct V_56 * V_57 ,
struct V_69 * V_140 )
{
int V_16 = 0 ;
F_94 ( ! V_140 -> V_79 && ! V_140 -> V_76 ) ;
V_16 = F_106 ( & V_57 -> V_115 , V_140 -> V_6 ,
& V_140 -> V_124 , ( V_140 -> V_79 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_57 -> V_93 += V_140 -> V_76 ;
V_57 -> V_147 ++ ;
return V_16 ;
}
static void F_115 ( struct V_56 * V_57 )
{
struct V_27 * V_28 = V_57 -> V_148 ;
T_1 V_149 ;
T_1 V_150 ;
T_1 V_151 ;
T_1 V_152 = V_28 -> V_8 . V_6 ;
T_1 V_153 = V_136 * V_28 -> V_117 ;
int V_154 = F_105 ( V_152 + V_153 - 1 , V_153 ) ;
F_94 ( V_57 -> V_81 > V_154 ) ;
if ( V_152 < 1024 * 1024 * 1024 )
V_149 = V_155 ;
else
V_149 = V_155 *
F_105 ( V_152 , 1024 * 1024 * 1024 ) ;
V_150 = ( V_57 -> V_81 + 1 ) * V_80 ;
if ( V_150 >= V_149 ) {
V_57 -> V_156 = 0 ;
return;
}
V_151 = V_149 - V_150 ;
V_151 = F_116 ( T_1 , V_151 , F_105 ( V_149 , 2 ) ) ;
V_57 -> V_156 =
F_105 ( V_151 , ( sizeof( struct V_69 ) ) ) ;
}
static inline void F_117 ( struct V_56 * V_57 ,
struct V_69 * V_140 ,
T_1 V_6 , T_1 V_76 )
{
unsigned long V_107 , V_157 ;
V_107 = F_101 ( V_140 -> V_6 , V_57 -> V_134 , V_6 ) ;
V_157 = F_103 ( V_76 , V_57 -> V_134 ) ;
F_94 ( V_107 + V_157 > V_136 ) ;
F_118 ( V_140 -> V_79 , V_107 , V_157 ) ;
V_140 -> V_76 -= V_76 ;
}
static void F_119 ( struct V_56 * V_57 ,
struct V_69 * V_140 , T_1 V_6 ,
T_1 V_76 )
{
F_117 ( V_57 , V_140 , V_6 , V_76 ) ;
V_57 -> V_93 -= V_76 ;
}
static void F_120 ( struct V_56 * V_57 ,
struct V_69 * V_140 , T_1 V_6 ,
T_1 V_76 )
{
unsigned long V_107 , V_157 ;
V_107 = F_101 ( V_140 -> V_6 , V_57 -> V_134 , V_6 ) ;
V_157 = F_103 ( V_76 , V_57 -> V_134 ) ;
F_94 ( V_107 + V_157 > V_136 ) ;
F_121 ( V_140 -> V_79 , V_107 , V_157 ) ;
V_140 -> V_76 += V_76 ;
V_57 -> V_93 += V_76 ;
}
static int F_122 ( struct V_56 * V_57 ,
struct V_69 * V_158 , T_1 * V_6 ,
T_1 * V_76 )
{
unsigned long V_159 = 0 ;
unsigned long V_160 , V_121 ;
unsigned long V_161 ;
V_121 = F_101 ( V_158 -> V_6 , V_57 -> V_134 ,
F_123 ( T_1 , * V_6 , V_158 -> V_6 ) ) ;
V_160 = F_103 ( * V_76 , V_57 -> V_134 ) ;
for ( V_121 = F_124 ( V_158 -> V_79 , V_136 , V_121 ) ;
V_121 < V_136 ;
V_121 = F_124 ( V_158 -> V_79 , V_136 , V_121 + 1 ) ) {
V_161 = F_125 ( V_158 -> V_79 ,
V_136 , V_121 ) ;
if ( ( V_161 - V_121 ) >= V_160 ) {
V_159 = V_161 - V_121 ;
break;
}
V_121 = V_161 ;
}
if ( V_159 ) {
* V_6 = ( T_1 ) ( V_121 * V_57 -> V_134 ) + V_158 -> V_6 ;
* V_76 = ( T_1 ) ( V_159 ) * V_57 -> V_134 ;
return 0 ;
}
return - 1 ;
}
static struct V_69 *
F_126 ( struct V_56 * V_57 , T_1 * V_6 , T_1 * V_76 )
{
struct V_69 * V_68 ;
struct V_95 * V_96 ;
int V_16 ;
if ( ! V_57 -> V_115 . V_95 )
return NULL ;
V_68 = F_110 ( V_57 , F_104 ( V_57 , * V_6 ) , 0 , 1 ) ;
if ( ! V_68 )
return NULL ;
for ( V_96 = & V_68 -> V_124 ; V_96 ; V_96 = F_84 ( V_96 ) ) {
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
if ( V_68 -> V_76 < * V_76 )
continue;
if ( V_68 -> V_79 ) {
V_16 = F_122 ( V_57 , V_68 , V_6 , V_76 ) ;
if ( ! V_16 )
return V_68 ;
continue;
}
* V_6 = V_68 -> V_6 ;
* V_76 = V_68 -> V_76 ;
return V_68 ;
}
return NULL ;
}
static void F_127 ( struct V_56 * V_57 ,
struct V_69 * V_140 , T_1 V_6 )
{
V_140 -> V_6 = F_104 ( V_57 , V_6 ) ;
V_140 -> V_76 = 0 ;
F_67 ( V_57 , V_140 ) ;
V_57 -> V_81 ++ ;
V_57 -> V_82 -> V_83 ( V_57 ) ;
}
static void F_128 ( struct V_56 * V_57 ,
struct V_69 * V_158 )
{
F_114 ( V_57 , V_158 ) ;
F_50 ( V_158 -> V_79 ) ;
F_66 ( V_75 , V_158 ) ;
V_57 -> V_81 -- ;
V_57 -> V_82 -> V_83 ( V_57 ) ;
}
static T_5 int F_129 ( struct V_56 * V_57 ,
struct V_69 * V_158 ,
T_1 * V_6 , T_1 * V_76 )
{
T_1 V_108 ;
T_1 V_162 , V_163 ;
int V_16 ;
V_164:
V_108 = V_158 -> V_6 + ( T_1 ) ( V_136 * V_57 -> V_134 ) - 1 ;
V_162 = * V_6 ;
V_163 = * V_76 ;
V_163 = F_86 ( V_163 , V_108 - V_162 + 1 ) ;
V_16 = F_122 ( V_57 , V_158 , & V_162 , & V_163 ) ;
F_94 ( V_16 < 0 || V_162 != * V_6 ) ;
if ( * V_6 > V_158 -> V_6 && * V_6 + * V_76 > V_108 ) {
F_119 ( V_57 , V_158 , * V_6 , V_108 - * V_6 + 1 ) ;
* V_76 -= V_108 - * V_6 + 1 ;
* V_6 = V_108 + 1 ;
} else if ( * V_6 >= V_158 -> V_6 && * V_6 + * V_76 <= V_108 ) {
F_119 ( V_57 , V_158 , * V_6 , * V_76 ) ;
* V_76 = 0 ;
}
if ( * V_76 ) {
struct V_95 * V_85 = F_84 ( & V_158 -> V_124 ) ;
if ( ! V_158 -> V_76 )
F_128 ( V_57 , V_158 ) ;
if ( ! V_85 )
return - V_165 ;
V_158 = F_82 ( V_85 , struct V_69 ,
V_124 ) ;
if ( ! V_158 -> V_79 )
return - V_166 ;
V_162 = * V_6 ;
V_163 = * V_76 ;
V_16 = F_122 ( V_57 , V_158 , & V_162 ,
& V_163 ) ;
if ( V_16 < 0 || V_162 != * V_6 )
return - V_166 ;
goto V_164;
} else if ( ! V_158 -> V_76 )
F_128 ( V_57 , V_158 ) ;
return 0 ;
}
static T_1 F_130 ( struct V_56 * V_57 ,
struct V_69 * V_140 , T_1 V_6 ,
T_1 V_76 )
{
T_1 V_167 = 0 ;
T_1 V_108 ;
V_108 = V_140 -> V_6 + ( T_1 ) ( V_136 * V_57 -> V_134 ) ;
V_167 = F_86 ( V_108 - V_6 , V_76 ) ;
F_120 ( V_57 , V_140 , V_6 , V_167 ) ;
return V_167 ;
}
static bool F_131 ( struct V_56 * V_57 ,
struct V_69 * V_140 )
{
struct V_27 * V_28 = V_57 -> V_148 ;
if ( V_57 -> V_147 < V_57 -> V_156 ) {
if ( V_140 -> V_76 <= V_28 -> V_117 * 4 ) {
if ( V_57 -> V_147 * 2 <= V_57 -> V_156 )
return false ;
} else {
return false ;
}
}
if ( V_136 * V_28 -> V_117 >
V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_132 ( struct V_56 * V_57 ,
struct V_69 * V_140 )
{
struct V_69 * V_158 ;
struct V_27 * V_28 = NULL ;
int V_168 = 0 ;
T_1 V_76 , V_6 , V_169 ;
int V_16 ;
V_76 = V_140 -> V_76 ;
V_6 = V_140 -> V_6 ;
if ( ! V_57 -> V_82 -> F_131 ( V_57 , V_140 ) )
return 0 ;
if ( V_57 -> V_82 == & V_170 )
V_28 = V_57 -> V_148 ;
V_164:
if ( V_28 && ! F_80 ( & V_28 -> V_118 ) ) {
struct V_102 * V_103 ;
struct V_95 * V_96 ;
struct V_69 * V_68 ;
V_103 = F_69 ( V_28 -> V_118 . V_85 ,
struct V_102 ,
V_119 ) ;
F_13 ( & V_103 -> V_29 ) ;
V_96 = F_77 ( & V_103 -> V_3 ) ;
if ( ! V_96 ) {
F_15 ( & V_103 -> V_29 ) ;
goto V_171;
}
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
if ( ! V_68 -> V_79 ) {
F_15 ( & V_103 -> V_29 ) ;
goto V_171;
}
if ( V_68 -> V_6 == F_104 ( V_57 , V_6 ) ) {
V_169 = F_130 ( V_57 , V_68 ,
V_6 , V_76 ) ;
V_76 -= V_169 ;
V_6 += V_169 ;
}
F_15 ( & V_103 -> V_29 ) ;
if ( ! V_76 ) {
V_16 = 1 ;
goto V_65;
}
}
V_171:
V_158 = F_110 ( V_57 , F_104 ( V_57 , V_6 ) ,
1 , 0 ) ;
if ( ! V_158 ) {
F_94 ( V_168 ) ;
goto V_172;
}
V_169 = F_130 ( V_57 , V_158 , V_6 , V_76 ) ;
V_76 -= V_169 ;
V_6 += V_169 ;
V_168 = 0 ;
if ( ! V_76 ) {
V_16 = 1 ;
goto V_65;
} else
goto V_164;
V_172:
if ( V_140 && V_140 -> V_79 ) {
F_127 ( V_57 , V_140 , V_6 ) ;
V_168 = 1 ;
V_140 = NULL ;
goto V_164;
} else {
F_15 ( & V_57 -> V_78 ) ;
if ( ! V_140 ) {
V_140 = F_64 ( V_75 ,
V_53 ) ;
if ( ! V_140 ) {
F_13 ( & V_57 -> V_78 ) ;
V_16 = - V_54 ;
goto V_65;
}
}
V_140 -> V_79 = F_47 ( V_80 , V_53 ) ;
F_13 ( & V_57 -> V_78 ) ;
if ( ! V_140 -> V_79 ) {
V_16 = - V_54 ;
goto V_65;
}
goto V_164;
}
V_65:
if ( V_140 ) {
if ( V_140 -> V_79 )
F_50 ( V_140 -> V_79 ) ;
F_66 ( V_75 , V_140 ) ;
}
return V_16 ;
}
static bool F_133 ( struct V_56 * V_57 ,
struct V_69 * V_140 , bool V_173 )
{
struct V_69 * V_174 ;
struct V_69 * V_175 ;
bool V_176 = false ;
T_1 V_6 = V_140 -> V_6 ;
T_1 V_76 = V_140 -> V_76 ;
V_175 = F_110 ( V_57 , V_6 + V_76 , 0 , 0 ) ;
if ( V_175 && F_111 ( & V_175 -> V_124 ) )
V_174 = F_82 ( F_111 ( & V_175 -> V_124 ) ,
struct V_69 , V_124 ) ;
else
V_174 = F_110 ( V_57 , V_6 - 1 , 0 , 0 ) ;
if ( V_175 && ! V_175 -> V_79 ) {
if ( V_173 )
F_114 ( V_57 , V_175 ) ;
else
F_112 ( V_57 , V_175 ) ;
V_140 -> V_76 += V_175 -> V_76 ;
F_66 ( V_75 , V_175 ) ;
V_176 = true ;
}
if ( V_174 && ! V_174 -> V_79 &&
V_174 -> V_6 + V_174 -> V_76 == V_6 ) {
if ( V_173 )
F_114 ( V_57 , V_174 ) ;
else
F_112 ( V_57 , V_174 ) ;
V_140 -> V_6 = V_174 -> V_6 ;
V_140 -> V_76 += V_174 -> V_76 ;
F_66 ( V_75 , V_174 ) ;
V_176 = true ;
}
return V_176 ;
}
int F_134 ( struct V_56 * V_57 ,
T_1 V_6 , T_1 V_76 )
{
struct V_69 * V_140 ;
int V_16 = 0 ;
V_140 = F_64 ( V_75 , V_53 ) ;
if ( ! V_140 )
return - V_54 ;
V_140 -> V_6 = V_6 ;
V_140 -> V_76 = V_76 ;
F_13 ( & V_57 -> V_78 ) ;
if ( F_133 ( V_57 , V_140 , true ) )
goto V_177;
V_16 = F_132 ( V_57 , V_140 ) ;
if ( V_16 < 0 ) {
goto V_65;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_65;
}
V_177:
V_16 = F_67 ( V_57 , V_140 ) ;
if ( V_16 )
F_66 ( V_75 , V_140 ) ;
V_65:
F_15 ( & V_57 -> V_78 ) ;
if ( V_16 ) {
F_17 ( V_178 L_15 , V_16 ) ;
F_94 ( V_16 == - V_143 ) ;
}
return V_16 ;
}
int F_135 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_76 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_140 ;
struct V_69 * V_179 = NULL ;
int V_16 = 0 ;
F_13 ( & V_57 -> V_78 ) ;
V_164:
V_140 = F_110 ( V_57 , V_6 , 0 , 0 ) ;
if ( ! V_140 ) {
V_140 = F_110 ( V_57 , F_104 ( V_57 , V_6 ) ,
1 , 0 ) ;
if ( ! V_140 ) {
F_44 ( 1 ) ;
goto V_180;
}
}
if ( V_140 -> V_76 < V_76 && F_84 ( & V_140 -> V_124 ) ) {
T_1 V_108 ;
V_179 = F_82 ( F_84 ( & V_140 -> V_124 ) ,
struct V_69 ,
V_124 ) ;
if ( V_179 -> V_79 )
V_108 = V_179 -> V_6 +
V_136 * V_57 -> V_134 - 1 ;
else
V_108 = V_179 -> V_6 + V_179 -> V_76 ;
if ( V_179 -> V_76 < V_76 ||
V_179 -> V_6 > V_6 || V_6 > V_108 ) {
F_17 ( V_178 L_16
L_17 ,
( unsigned long long ) V_140 -> V_6 ,
( unsigned long long ) V_140 -> V_76 ,
( unsigned long long ) V_76 ) ;
F_44 ( 1 ) ;
V_16 = - V_165 ;
goto V_180;
}
V_140 = V_179 ;
}
if ( V_140 -> V_76 == V_76 ) {
F_114 ( V_57 , V_140 ) ;
if ( V_140 -> V_79 ) {
F_50 ( V_140 -> V_79 ) ;
V_57 -> V_81 -- ;
}
F_66 ( V_75 , V_140 ) ;
goto V_180;
}
if ( ! V_140 -> V_79 && V_140 -> V_6 == V_6 ) {
F_114 ( V_57 , V_140 ) ;
V_140 -> V_6 += V_76 ;
V_140 -> V_76 -= V_76 ;
F_67 ( V_57 , V_140 ) ;
goto V_180;
}
if ( ! V_140 -> V_79 && V_140 -> V_6 <= V_6 &&
V_140 -> V_6 + V_140 -> V_76 >= V_6 + V_76 ) {
T_1 V_181 = V_140 -> V_6 ;
F_114 ( V_57 , V_140 ) ;
if ( V_6 + V_76 < V_140 -> V_6 + V_140 -> V_76 ) {
T_1 V_182 = V_140 -> V_6 + V_140 -> V_76 ;
V_140 -> V_6 = V_6 + V_76 ;
V_140 -> V_76 = V_182 - V_140 -> V_6 ;
V_16 = F_67 ( V_57 , V_140 ) ;
F_44 ( V_16 ) ;
if ( V_16 )
goto V_180;
} else {
F_66 ( V_75 , V_140 ) ;
}
F_15 ( & V_57 -> V_78 ) ;
V_16 = F_136 ( V_28 , V_181 ,
V_6 - V_181 ) ;
F_44 ( V_16 ) ;
goto V_65;
}
V_16 = F_129 ( V_57 , V_140 , & V_6 , & V_76 ) ;
if ( V_16 == - V_166 )
goto V_164;
F_94 ( V_16 ) ;
V_180:
F_15 ( & V_57 -> V_78 ) ;
V_65:
return V_16 ;
}
void F_137 ( struct V_27 * V_28 ,
T_1 V_76 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_140 ;
struct V_95 * V_98 ;
int V_157 = 0 ;
for ( V_98 = F_77 ( & V_57 -> V_115 ) ; V_98 ; V_98 = F_84 ( V_98 ) ) {
V_140 = F_82 ( V_98 , struct V_69 , V_124 ) ;
if ( V_140 -> V_76 >= V_76 )
V_157 ++ ;
F_17 ( V_178 L_18 ,
( unsigned long long ) V_140 -> V_6 ,
( unsigned long long ) V_140 -> V_76 ,
( V_140 -> V_79 ) ? L_19 : L_20 ) ;
}
F_17 ( V_31 L_21 ,
F_80 ( & V_28 -> V_118 ) ? L_20 : L_19 ) ;
F_17 ( V_31 L_22
L_23 , V_157 ) ;
}
void F_138 ( struct V_27 * V_28 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
F_139 ( & V_57 -> V_78 ) ;
V_57 -> V_134 = V_28 -> V_117 ;
V_57 -> V_107 = V_28 -> V_8 . V_17 ;
V_57 -> V_148 = V_28 ;
V_57 -> V_82 = & V_170 ;
V_57 -> V_156 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_69 ) ;
}
static int
F_140 (
struct V_27 * V_28 ,
struct V_102 * V_103 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_68 ;
struct V_95 * V_96 ;
F_13 ( & V_103 -> V_29 ) ;
if ( V_103 -> V_28 != V_28 )
goto V_65;
V_103 -> V_28 = NULL ;
V_103 -> V_183 = 0 ;
F_70 ( & V_103 -> V_119 ) ;
V_96 = F_77 ( & V_103 -> V_3 ) ;
while ( V_96 ) {
bool V_79 ;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
V_96 = F_84 ( & V_68 -> V_124 ) ;
F_113 ( & V_68 -> V_124 , & V_103 -> V_3 ) ;
V_79 = ( V_68 -> V_79 != NULL ) ;
if ( ! V_79 )
F_133 ( V_57 , V_68 , false ) ;
F_106 ( & V_57 -> V_115 ,
V_68 -> V_6 , & V_68 -> V_124 , V_79 ) ;
}
V_103 -> V_3 = V_184 ;
V_65:
F_15 ( & V_103 -> V_29 ) ;
F_141 ( V_28 ) ;
return 0 ;
}
void F_142 ( struct V_56 * V_57 )
{
struct V_69 * V_140 ;
struct V_95 * V_96 ;
while ( ( V_96 = F_143 ( & V_57 -> V_115 ) ) != NULL ) {
V_140 = F_82 ( V_96 , struct V_69 , V_124 ) ;
if ( ! V_140 -> V_79 ) {
F_114 ( V_57 , V_140 ) ;
F_66 ( V_75 , V_140 ) ;
} else {
F_128 ( V_57 , V_140 ) ;
}
if ( F_144 () ) {
F_15 ( & V_57 -> V_78 ) ;
F_145 () ;
F_13 ( & V_57 -> V_78 ) ;
}
}
}
void F_71 ( struct V_56 * V_57 )
{
F_13 ( & V_57 -> V_78 ) ;
F_142 ( V_57 ) ;
F_15 ( & V_57 -> V_78 ) ;
}
void F_146 ( struct V_27 * V_28 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_102 * V_103 ;
struct V_59 * V_185 ;
F_13 ( & V_57 -> V_78 ) ;
while ( ( V_185 = V_28 -> V_118 . V_85 ) !=
& V_28 -> V_118 ) {
V_103 = F_69 ( V_185 , struct V_102 ,
V_119 ) ;
F_44 ( V_103 -> V_28 != V_28 ) ;
F_140 ( V_28 , V_103 ) ;
if ( F_144 () ) {
F_15 ( & V_57 -> V_78 ) ;
F_145 () ;
F_13 ( & V_57 -> V_78 ) ;
}
}
F_142 ( V_57 ) ;
F_15 ( & V_57 -> V_78 ) ;
}
T_1 F_147 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_76 , T_1 V_186 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_68 = NULL ;
T_1 V_187 = V_76 + V_186 ;
T_1 V_16 = 0 ;
F_13 ( & V_57 -> V_78 ) ;
V_68 = F_126 ( V_57 , & V_6 , & V_187 ) ;
if ( ! V_68 )
goto V_65;
V_16 = V_6 ;
if ( V_68 -> V_79 ) {
F_119 ( V_57 , V_68 , V_6 , V_76 ) ;
if ( ! V_68 -> V_76 )
F_128 ( V_57 , V_68 ) ;
} else {
F_114 ( V_57 , V_68 ) ;
V_68 -> V_6 += V_76 ;
V_68 -> V_76 -= V_76 ;
if ( ! V_68 -> V_76 )
F_66 ( V_75 , V_68 ) ;
else
F_67 ( V_57 , V_68 ) ;
}
V_65:
F_15 ( & V_57 -> V_78 ) ;
return V_16 ;
}
int F_148 (
struct V_27 * V_28 ,
struct V_102 * V_103 )
{
struct V_56 * V_57 ;
int V_16 ;
F_13 ( & V_103 -> V_29 ) ;
if ( ! V_28 ) {
V_28 = V_103 -> V_28 ;
if ( ! V_28 ) {
F_15 ( & V_103 -> V_29 ) ;
return 0 ;
}
} else if ( V_103 -> V_28 != V_28 ) {
F_15 ( & V_103 -> V_29 ) ;
return 0 ;
}
F_149 ( & V_28 -> V_157 ) ;
F_15 ( & V_103 -> V_29 ) ;
V_57 = V_28 -> V_87 ;
F_13 ( & V_57 -> V_78 ) ;
V_16 = F_140 ( V_28 , V_103 ) ;
F_15 ( & V_57 -> V_78 ) ;
F_141 ( V_28 ) ;
return V_16 ;
}
static T_1 F_150 ( struct V_27 * V_28 ,
struct V_102 * V_103 ,
struct V_69 * V_68 ,
T_1 V_76 , T_1 V_188 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
int V_189 ;
T_1 V_162 = V_103 -> V_183 ;
T_1 V_163 = V_76 ;
T_1 V_16 = 0 ;
V_162 = V_188 ;
V_163 = V_76 ;
V_189 = F_122 ( V_57 , V_68 , & V_162 , & V_163 ) ;
if ( V_189 )
return 0 ;
V_16 = V_162 ;
F_117 ( V_57 , V_68 , V_16 , V_76 ) ;
return V_16 ;
}
T_1 F_151 ( struct V_27 * V_28 ,
struct V_102 * V_103 , T_1 V_76 ,
T_1 V_188 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_68 = NULL ;
struct V_95 * V_96 ;
T_1 V_16 = 0 ;
F_13 ( & V_103 -> V_29 ) ;
if ( V_76 > V_103 -> V_190 )
goto V_65;
if ( V_103 -> V_28 != V_28 )
goto V_65;
V_96 = F_77 ( & V_103 -> V_3 ) ;
if ( ! V_96 )
goto V_65;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
while( 1 ) {
if ( V_68 -> V_76 < V_76 ||
( ! V_68 -> V_79 && V_68 -> V_6 < V_188 ) ) {
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_96 )
break;
V_68 = F_82 ( V_96 , struct V_69 ,
V_124 ) ;
continue;
}
if ( V_68 -> V_79 ) {
V_16 = F_150 ( V_28 ,
V_103 , V_68 , V_76 ,
V_188 ) ;
if ( V_16 == 0 ) {
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_96 )
break;
V_68 = F_82 ( V_96 , struct V_69 ,
V_124 ) ;
continue;
}
} else {
V_16 = V_68 -> V_6 ;
V_68 -> V_6 += V_76 ;
V_68 -> V_76 -= V_76 ;
}
if ( V_68 -> V_76 == 0 )
F_113 ( & V_68 -> V_124 , & V_103 -> V_3 ) ;
break;
}
V_65:
F_15 ( & V_103 -> V_29 ) ;
if ( ! V_16 )
return 0 ;
F_13 ( & V_57 -> V_78 ) ;
V_57 -> V_93 -= V_76 ;
if ( V_68 -> V_76 == 0 ) {
V_57 -> V_147 -- ;
if ( V_68 -> V_79 ) {
F_50 ( V_68 -> V_79 ) ;
V_57 -> V_81 -- ;
V_57 -> V_82 -> V_83 ( V_57 ) ;
}
F_66 ( V_75 , V_68 ) ;
}
F_15 ( & V_57 -> V_78 ) ;
return V_16 ;
}
static int F_152 ( struct V_27 * V_28 ,
struct V_69 * V_68 ,
struct V_102 * V_103 ,
T_1 V_6 , T_1 V_76 , T_1 V_191 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
unsigned long V_161 ;
unsigned long V_121 ;
unsigned long V_192 ;
unsigned long V_193 ;
unsigned long V_159 ;
unsigned long V_107 = 0 ;
unsigned long V_194 = 0 ;
int V_16 ;
bool V_195 = false ;
V_121 = F_101 ( V_68 -> V_6 , V_28 -> V_117 ,
F_123 ( T_1 , V_6 , V_68 -> V_6 ) ) ;
V_192 = F_103 ( V_76 , V_28 -> V_117 ) ;
V_193 = F_103 ( V_191 , V_28 -> V_117 ) ;
V_164:
V_159 = 0 ;
for ( V_121 = F_124 ( V_68 -> V_79 , V_136 , V_121 ) ;
V_121 < V_136 ;
V_121 = F_124 ( V_68 -> V_79 , V_136 , V_121 + 1 ) ) {
V_161 = F_125 ( V_68 -> V_79 ,
V_136 , V_121 ) ;
if ( V_161 - V_121 >= V_192 ) {
V_159 = V_161 - V_121 ;
break;
}
V_121 = V_161 ;
}
if ( ! V_159 )
return - V_196 ;
if ( ! V_195 ) {
V_107 = V_121 ;
V_195 = true ;
}
V_194 += V_159 ;
if ( V_103 -> V_190 < V_159 * V_28 -> V_117 )
V_103 -> V_190 = V_159 * V_28 -> V_117 ;
if ( V_194 < V_193 ) {
V_121 = F_124 ( V_68 -> V_79 , V_136 , V_161 ) ;
if ( V_121 - V_107 > V_193 * 2 ) {
V_194 = 0 ;
V_103 -> V_190 = 0 ;
V_195 = false ;
}
goto V_164;
}
V_103 -> V_183 = V_107 * V_28 -> V_117 +
V_68 -> V_6 ;
F_113 ( & V_68 -> V_124 , & V_57 -> V_115 ) ;
V_16 = F_106 ( & V_103 -> V_3 , V_68 -> V_6 ,
& V_68 -> V_124 , 1 ) ;
F_94 ( V_16 ) ;
return 0 ;
}
static T_5 int
F_153 ( struct V_27 * V_28 ,
struct V_102 * V_103 ,
struct V_59 * V_60 , T_1 V_6 , T_1 V_76 ,
T_1 V_191 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_197 = NULL ;
struct V_69 * V_68 = NULL ;
struct V_69 * V_146 = NULL ;
struct V_69 * V_198 ;
struct V_95 * V_96 ;
T_1 V_183 ;
T_1 V_199 ;
T_1 V_200 ;
T_1 V_201 = 128 * 1024 ;
V_68 = F_110 ( V_57 , V_6 , 0 , 1 ) ;
if ( ! V_68 )
return - V_196 ;
while ( V_68 -> V_79 ) {
if ( F_80 ( & V_68 -> V_84 ) )
F_68 ( & V_68 -> V_84 , V_60 ) ;
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_96 )
return - V_196 ;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
}
V_183 = V_68 -> V_6 ;
V_199 = V_68 -> V_76 ;
V_200 = V_68 -> V_76 ;
V_197 = V_68 ;
V_198 = V_68 ;
V_146 = V_68 ;
while ( V_199 <= V_191 ) {
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_96 )
return - V_196 ;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
if ( V_68 -> V_79 ) {
if ( F_80 ( & V_68 -> V_84 ) )
F_68 ( & V_68 -> V_84 , V_60 ) ;
continue;
}
if ( V_68 -> V_6 - ( V_146 -> V_6 + V_146 -> V_76 ) > V_201 ||
V_68 -> V_6 - V_183 > ( V_191 * 2 ) ) {
V_197 = V_68 ;
V_183 = V_68 -> V_6 ;
V_199 = V_68 -> V_76 ;
V_198 = V_68 ;
V_200 = V_68 -> V_76 ;
} else {
V_198 = V_68 ;
V_199 += V_68 -> V_76 ;
if ( V_68 -> V_76 > V_200 )
V_200 = V_68 -> V_76 ;
}
V_146 = V_68 ;
}
V_103 -> V_183 = V_197 -> V_6 ;
V_96 = & V_197 -> V_124 ;
do {
int V_16 ;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( V_68 -> V_79 )
continue;
F_113 ( & V_68 -> V_124 , & V_57 -> V_115 ) ;
V_16 = F_106 ( & V_103 -> V_3 , V_68 -> V_6 ,
& V_68 -> V_124 , 0 ) ;
F_94 ( V_16 ) ;
} while ( V_96 && V_68 != V_198 );
V_103 -> V_190 = V_200 ;
return 0 ;
}
static T_5 int
F_154 ( struct V_27 * V_28 ,
struct V_102 * V_103 ,
struct V_59 * V_60 , T_1 V_6 , T_1 V_76 ,
T_1 V_191 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_68 ;
struct V_95 * V_96 ;
int V_16 = - V_196 ;
if ( V_57 -> V_81 == 0 )
return - V_196 ;
F_155 (entry, bitmaps, list) {
if ( V_68 -> V_76 < V_191 )
continue;
V_16 = F_152 ( V_28 , V_68 , V_103 , V_6 ,
V_76 , V_191 ) ;
if ( ! V_16 )
return 0 ;
}
if ( ! F_80 ( V_60 ) ) {
V_68 = F_69 ( V_60 -> V_146 , struct V_69 ,
V_84 ) ;
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_96 )
return - V_196 ;
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
goto V_202;
}
V_68 = F_110 ( V_57 , F_104 ( V_57 , V_6 ) , 0 , 1 ) ;
if ( ! V_68 )
return - V_196 ;
V_202:
V_96 = & V_68 -> V_124 ;
do {
V_68 = F_82 ( V_96 , struct V_69 , V_124 ) ;
V_96 = F_84 ( & V_68 -> V_124 ) ;
if ( ! V_68 -> V_79 )
continue;
if ( V_68 -> V_76 < V_191 )
continue;
V_16 = F_152 ( V_28 , V_68 , V_103 , V_6 ,
V_76 , V_191 ) ;
} while ( V_16 && V_96 );
return V_16 ;
}
int F_156 ( struct V_35 * V_36 ,
struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_102 * V_103 ,
T_1 V_6 , T_1 V_76 , T_1 V_186 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_59 V_60 ;
struct V_69 * V_68 , * V_127 ;
T_1 V_191 ;
int V_16 ;
if ( F_157 ( V_3 , V_203 ) ) {
V_191 = V_76 + V_186 ;
} else if ( V_28 -> V_25 & V_204 ) {
if ( V_36 -> V_205 -> V_206 . V_207 )
V_191 = F_158 ( V_76 , ( V_76 + V_186 ) >> 1 ) ;
else
V_191 = F_158 ( V_76 , ( V_76 + V_186 ) >> 4 ) ;
} else
V_191 = F_158 ( V_76 , ( V_76 + V_186 ) >> 2 ) ;
F_13 ( & V_57 -> V_78 ) ;
if ( V_57 -> V_93 < V_191 ) {
F_15 ( & V_57 -> V_78 ) ;
return - V_196 ;
}
F_13 ( & V_103 -> V_29 ) ;
if ( V_103 -> V_28 ) {
V_16 = 0 ;
goto V_65;
}
F_52 ( & V_60 ) ;
V_16 = F_153 ( V_28 , V_103 , & V_60 , V_6 ,
V_76 , V_191 ) ;
if ( V_16 )
V_16 = F_154 ( V_28 , V_103 , & V_60 ,
V_6 , V_76 , V_191 ) ;
F_159 (entry, tmp, &bitmaps, list)
F_70 ( & V_68 -> V_84 ) ;
if ( ! V_16 ) {
F_149 ( & V_28 -> V_157 ) ;
F_68 ( & V_103 -> V_119 ,
& V_28 -> V_118 ) ;
V_103 -> V_28 = V_28 ;
}
V_65:
F_15 ( & V_103 -> V_29 ) ;
F_15 ( & V_57 -> V_78 ) ;
return V_16 ;
}
void F_160 ( struct V_102 * V_103 )
{
F_139 ( & V_103 -> V_29 ) ;
F_139 ( & V_103 -> V_208 ) ;
V_103 -> V_3 = V_184 ;
V_103 -> V_190 = 0 ;
F_52 ( & V_103 -> V_119 ) ;
V_103 -> V_28 = NULL ;
}
int F_161 ( struct V_27 * V_28 ,
T_1 * V_209 , T_1 V_107 , T_1 V_108 , T_1 V_210 )
{
struct V_56 * V_57 = V_28 -> V_87 ;
struct V_69 * V_68 = NULL ;
struct V_86 * V_22 = V_28 -> V_22 ;
T_1 V_76 = 0 ;
T_1 V_211 ;
int V_16 = 0 ;
* V_209 = 0 ;
while ( V_107 < V_108 ) {
F_13 ( & V_57 -> V_78 ) ;
if ( V_57 -> V_93 < V_210 ) {
F_15 ( & V_57 -> V_78 ) ;
break;
}
V_68 = F_110 ( V_57 , V_107 , 0 , 1 ) ;
if ( ! V_68 )
V_68 = F_110 ( V_57 ,
F_104 ( V_57 , V_107 ) ,
1 , 1 ) ;
if ( ! V_68 || V_68 -> V_6 >= V_108 ) {
F_15 ( & V_57 -> V_78 ) ;
break;
}
if ( V_68 -> V_79 ) {
V_16 = F_122 ( V_57 , V_68 , & V_107 , & V_76 ) ;
if ( ! V_16 ) {
if ( V_107 >= V_108 ) {
F_15 ( & V_57 -> V_78 ) ;
break;
}
V_76 = F_86 ( V_76 , V_108 - V_107 ) ;
F_119 ( V_57 , V_68 , V_107 , V_76 ) ;
if ( V_68 -> V_76 == 0 )
F_128 ( V_57 , V_68 ) ;
} else {
V_107 = V_68 -> V_6 + V_136 *
V_28 -> V_117 ;
F_15 ( & V_57 -> V_78 ) ;
V_16 = 0 ;
continue;
}
} else {
V_107 = V_68 -> V_6 ;
V_76 = F_86 ( V_68 -> V_76 , V_108 - V_107 ) ;
F_114 ( V_57 , V_68 ) ;
F_66 ( V_75 , V_68 ) ;
}
F_15 ( & V_57 -> V_78 ) ;
if ( V_76 >= V_210 ) {
int V_212 ;
V_212 = F_162 ( V_28 ,
V_76 , 1 , 1 ) ;
V_16 = F_163 ( V_22 -> V_213 ,
V_107 ,
V_76 ,
& V_211 ) ;
F_136 ( V_28 , V_107 , V_76 ) ;
if ( ! V_212 )
F_162 ( V_28 ,
V_76 , 0 , 1 ) ;
if ( V_16 )
break;
* V_209 += V_211 ;
}
V_107 += V_76 ;
V_76 = 0 ;
if ( F_164 ( V_214 ) ) {
V_16 = - V_215 ;
break;
}
F_145 () ;
}
return V_16 ;
}
T_1 F_165 ( struct V_2 * V_216 )
{
struct V_56 * V_57 = V_216 -> V_217 ;
struct V_69 * V_68 = NULL ;
T_1 V_37 = 0 ;
F_13 ( & V_57 -> V_78 ) ;
if ( F_166 ( & V_57 -> V_115 ) )
goto V_65;
V_68 = F_82 ( F_77 ( & V_57 -> V_115 ) ,
struct V_69 , V_124 ) ;
if ( ! V_68 -> V_79 ) {
V_37 = V_68 -> V_6 ;
F_114 ( V_57 , V_68 ) ;
V_68 -> V_6 ++ ;
V_68 -> V_76 -- ;
if ( ! V_68 -> V_76 )
F_66 ( V_75 , V_68 ) ;
else
F_67 ( V_57 , V_68 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_157 = 1 ;
int V_16 ;
V_16 = F_122 ( V_57 , V_68 , & V_6 , & V_157 ) ;
F_94 ( V_16 ) ;
V_37 = V_6 ;
F_119 ( V_57 , V_68 , V_6 , 1 ) ;
if ( V_68 -> V_76 == 0 )
F_128 ( V_57 , V_68 ) ;
}
V_65:
F_15 ( & V_57 -> V_78 ) ;
return V_37 ;
}
struct V_1 * F_167 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_13 ( & V_3 -> V_218 ) ;
if ( V_3 -> V_219 )
V_1 = F_14 ( V_3 -> V_219 ) ;
F_15 ( & V_3 -> V_218 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_3 -> V_218 ) ;
if ( ! F_18 ( V_3 -> V_22 ) )
V_3 -> V_219 = F_14 ( V_1 ) ;
F_15 ( & V_3 -> V_218 ) ;
return V_1 ;
}
int F_168 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
return F_19 ( V_3 , V_36 , V_5 ,
V_220 , 0 ) ;
}
int F_169 ( struct V_86 * V_22 , struct V_2 * V_3 )
{
struct V_56 * V_57 = V_3 -> V_217 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_221 = F_170 ( & V_3 -> V_222 ) ;
if ( ! F_157 ( V_3 , V_223 ) )
return 0 ;
if ( F_18 ( V_22 ) )
return 0 ;
V_5 = F_74 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_167 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_65;
if ( V_221 != F_16 ( V_1 ) -> V_63 )
goto V_224;
V_16 = F_51 ( V_3 , V_1 , V_57 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_17 ( V_66 L_24
L_25 , V_3 -> V_225 . V_17 ) ;
V_224:
F_11 ( V_1 ) ;
V_65:
F_75 ( V_5 ) ;
return V_16 ;
}
int F_171 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
struct V_56 * V_57 = V_3 -> V_217 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_157 ( V_3 , V_223 ) )
return 0 ;
V_1 = F_167 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_76 ( V_3 , V_1 , V_57 , NULL , V_36 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_17 ( V_66 L_26
L_27 , V_3 -> V_225 . V_17 ) ;
F_11 ( V_1 ) ;
return V_16 ;
}
