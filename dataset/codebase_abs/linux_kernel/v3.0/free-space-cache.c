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
if ( ! F_16 ( V_3 -> V_22 ) ) {
V_28 -> V_1 = F_14 ( V_1 ) ;
V_28 -> V_30 = 1 ;
}
F_15 ( & V_28 -> V_29 ) ;
return V_1 ;
}
int F_17 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_4 * V_5 , T_1 V_33 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_34 * V_35 ;
struct V_14 * V_15 ;
int V_16 ;
V_16 = F_18 ( V_32 , V_3 , V_5 , V_33 ) ;
if ( V_16 )
return V_16 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_35 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_34 ) ;
F_19 ( V_15 , & V_11 , V_5 -> V_21 [ 0 ] ) ;
F_20 ( V_15 , 0 , ( unsigned long ) V_35 ,
sizeof( * V_35 ) ) ;
F_21 ( V_15 , V_35 , V_32 -> V_36 ) ;
F_22 ( V_15 , V_35 , 0 ) ;
F_23 ( V_15 , V_35 , 0 ) ;
F_24 ( V_15 , V_35 , 0 ) ;
F_25 ( V_15 , V_35 , 0 ) ;
F_26 ( V_15 , V_35 , V_37 | 0600 ) ;
F_27 ( V_15 , V_35 , V_38 |
V_39 | V_40 ) ;
F_28 ( V_15 , V_35 , 1 ) ;
F_29 ( V_15 , V_35 , V_32 -> V_36 ) ;
F_30 ( V_15 , V_35 , V_6 ) ;
F_31 ( V_15 ) ;
F_4 ( V_5 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_32 ( V_32 , V_3 , V_5 , & V_8 ,
sizeof( struct V_12 ) ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 ) ;
return V_16 ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_20 ( V_15 , 0 , ( unsigned long ) V_13 , sizeof( * V_13 ) ) ;
F_33 ( V_15 , V_13 , & V_11 ) ;
F_31 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_33 ;
V_16 = F_35 ( V_3 , & V_33 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_17 ( V_3 , V_32 , V_5 , V_33 ,
V_28 -> V_8 . V_17 ) ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
T_2 V_41 ;
int V_16 = 0 ;
V_32 -> V_42 = V_3 -> V_43 ;
V_16 = F_37 ( V_32 , V_3 ,
V_3 -> V_43 ,
0 , 5 ) ;
if ( V_16 )
return V_16 ;
V_41 = F_38 ( V_1 ) ;
F_39 ( V_1 , 0 ) ;
F_40 ( V_1 , V_41 , 0 ) ;
V_16 = F_41 ( V_32 , V_3 , V_1 ,
0 , V_44 ) ;
if ( V_16 ) {
F_42 ( 1 ) ;
return V_16 ;
}
V_16 = F_43 ( V_32 , V_3 , V_1 ) ;
return V_16 ;
}
static int F_44 ( struct V_1 * V_1 )
{
struct V_45 * V_46 ;
unsigned long V_47 ;
V_46 = F_45 ( sizeof( * V_46 ) , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
F_46 ( V_46 , V_1 -> V_24 ) ;
V_47 = ( F_38 ( V_1 ) - 1 ) >> V_50 ;
F_47 ( V_1 -> V_24 , V_46 , NULL , 0 , V_47 ) ;
F_48 ( V_46 ) ;
return 0 ;
}
int F_49 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_51 * V_52 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_53 * V_53 ;
T_3 * V_54 = NULL , * V_55 ;
char * V_56 = NULL ;
struct V_7 V_8 ;
struct V_57 V_58 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_61 ;
T_3 V_62 = ~ ( T_3 ) 0 ;
T_4 V_63 = 0 ;
unsigned long V_64 ;
int V_65 ;
int V_16 = 0 ;
F_50 ( & V_58 ) ;
if ( ! F_38 ( V_1 ) )
goto V_66;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( NULL , V_3 , & V_8 , V_5 , 0 , 0 ) ;
if ( V_16 < 0 )
goto V_66;
else if ( V_16 > 0 ) {
F_4 ( V_5 ) ;
V_16 = 0 ;
goto V_66;
}
V_16 = - 1 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
V_59 = F_51 ( V_15 , V_13 ) ;
V_60 = F_52 ( V_15 , V_13 ) ;
V_61 = F_53 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_54 ( V_1 ) -> V_61 != V_61 ) {
F_55 ( V_67 L_1
L_2 ,
( unsigned long long ) F_54 ( V_1 ) -> V_61 ,
( unsigned long long ) V_61 ) ;
goto V_66;
}
if ( ! V_59 )
goto V_66;
V_65 = F_38 ( V_1 ) / V_68 ;
V_54 = V_55 = F_45 ( sizeof( T_3 ) * V_65 , V_48 ) ;
if ( ! V_54 )
goto V_66;
V_64 = ( sizeof( T_3 ) * V_65 ) + sizeof( T_1 ) ;
V_56 = F_45 ( V_64 , V_48 ) ;
if ( ! V_56 )
goto V_66;
V_16 = F_44 ( V_1 ) ;
if ( V_16 )
goto V_66;
while ( 1 ) {
struct V_69 * V_70 ;
struct V_71 * V_72 ;
void * V_73 ;
unsigned long V_6 = 0 ;
unsigned long V_74 = 0 ;
int V_75 = 0 ;
if ( ! V_59 && ! V_60 )
break;
if ( V_63 == 0 ) {
V_74 = V_64 ;
V_6 = V_74 ;
}
V_53 = F_56 ( V_1 -> V_24 , V_63 ) ;
if ( ! V_53 )
goto V_76;
if ( ! F_57 ( V_53 ) ) {
F_58 ( NULL , V_53 ) ;
F_59 ( V_53 ) ;
if ( ! F_57 ( V_53 ) ) {
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
F_55 ( V_67 L_3
L_4 ) ;
goto V_76;
}
}
V_73 = F_62 ( V_53 ) ;
if ( V_63 == 0 ) {
T_1 * V_77 ;
memcpy ( V_56 , V_73 , V_64 ) ;
V_77 = V_73 + ( sizeof( T_3 ) * V_65 ) ;
if ( * V_77 != F_54 ( V_1 ) -> V_61 ) {
F_55 ( V_67 L_5
L_6 ,
( unsigned long long ) * V_77 ,
( unsigned long long )
F_54 ( V_1 ) -> V_61 ) ;
F_63 ( V_53 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
V_55 = ( T_3 * ) V_56 ;
}
V_70 = V_73 + V_74 ;
V_62 = ~ ( T_3 ) 0 ;
V_62 = F_64 ( V_3 , V_73 + V_74 , V_62 ,
V_68 - V_74 ) ;
F_65 ( V_62 , ( char * ) & V_62 ) ;
if ( V_62 != * V_55 ) {
F_55 ( V_67 L_7 ,
V_63 ) ;
F_63 ( V_53 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
V_55 ++ ;
while ( 1 ) {
if ( ! V_59 )
break;
V_75 = 1 ;
V_72 = F_66 ( V_78 ,
V_48 ) ;
if ( ! V_72 ) {
F_63 ( V_53 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
V_72 -> V_6 = F_67 ( V_70 -> V_6 ) ;
V_72 -> V_79 = F_67 ( V_70 -> V_79 ) ;
if ( ! V_72 -> V_79 ) {
F_63 ( V_53 ) ;
F_68 ( V_78 , V_72 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
if ( V_70 -> type == V_80 ) {
F_13 ( & V_52 -> V_81 ) ;
V_16 = F_69 ( V_52 , V_72 ) ;
F_15 ( & V_52 -> V_81 ) ;
if ( V_16 ) {
F_55 ( V_67 L_8
L_9 ) ;
F_63 ( V_53 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
} else {
V_72 -> V_82 = F_45 ( V_68 , V_48 ) ;
if ( ! V_72 -> V_82 ) {
F_63 ( V_53 ) ;
F_68 (
V_78 , V_72 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
F_13 ( & V_52 -> V_81 ) ;
V_16 = F_69 ( V_52 , V_72 ) ;
V_52 -> V_83 ++ ;
V_52 -> V_84 -> V_85 ( V_52 ) ;
F_15 ( & V_52 -> V_81 ) ;
if ( V_16 ) {
F_55 ( V_67 L_8
L_9 ) ;
F_63 ( V_53 ) ;
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
goto V_76;
}
F_70 ( & V_72 -> V_86 , & V_58 ) ;
}
V_59 -- ;
V_6 += sizeof( struct V_69 ) ;
if ( V_6 + sizeof( struct V_69 ) >=
V_68 )
break;
V_70 ++ ;
}
if ( V_75 ) {
F_63 ( V_53 ) ;
goto V_87;
}
V_72 = F_71 ( V_58 . V_87 , struct V_71 , V_86 ) ;
F_72 ( & V_72 -> V_86 ) ;
memcpy ( V_72 -> V_82 , V_73 , V_68 ) ;
F_63 ( V_53 ) ;
V_60 -- ;
V_87:
F_60 ( V_53 ) ;
F_61 ( V_53 ) ;
V_63 ++ ;
}
V_16 = 1 ;
V_66:
F_48 ( V_54 ) ;
F_48 ( V_56 ) ;
return V_16 ;
V_76:
F_73 ( V_52 ) ;
goto V_66;
}
int F_74 ( struct V_88 * V_22 ,
struct V_27 * V_28 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_2 * V_3 = V_22 -> V_90 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 ;
bool V_91 ;
T_1 V_92 = F_75 ( & V_28 -> V_93 ) ;
if ( F_16 ( V_22 ) )
return 0 ;
F_13 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_94 != V_95 ) {
F_15 ( & V_28 -> V_29 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_29 ) ;
V_5 = F_76 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_77 ( V_5 ) ;
return 0 ;
}
V_16 = F_49 ( V_22 -> V_90 , V_1 , V_52 ,
V_5 , V_28 -> V_8 . V_17 ) ;
F_77 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_66;
F_13 ( & V_52 -> V_81 ) ;
V_91 = ( V_52 -> V_96 == ( V_28 -> V_8 . V_6 - V_92 -
V_28 -> V_97 ) ) ;
F_15 ( & V_52 -> V_81 ) ;
if ( ! V_91 ) {
F_73 ( V_52 ) ;
F_55 ( V_67 L_10
L_11 , V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_66:
if ( V_16 < 0 ) {
F_13 ( & V_28 -> V_29 ) ;
V_28 -> V_94 = V_98 ;
F_15 ( & V_28 -> V_29 ) ;
V_16 = 0 ;
F_55 ( V_67 L_12
L_13 , V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
int F_78 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_51 * V_52 ,
struct V_27 * V_28 ,
struct V_31 * V_32 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_99 * V_100 ;
struct V_57 * V_101 , * V_102 ;
struct V_53 * * V_103 ;
struct V_53 * V_53 ;
struct V_104 * V_105 = NULL ;
struct V_106 * V_107 = NULL ;
struct V_108 * V_109 = NULL ;
struct V_57 V_110 ;
struct V_7 V_8 ;
T_1 V_111 , V_112 , V_113 ;
T_1 V_79 = 0 ;
T_3 * V_55 , * V_54 ;
unsigned long V_64 ;
int V_63 = 0 , V_114 = 0 ;
int V_115 = 0 ;
int V_58 = 0 ;
int V_16 = - 1 ;
bool V_116 = false ;
bool V_117 = false ;
F_50 ( & V_110 ) ;
V_100 = F_79 ( & V_52 -> V_118 ) ;
if ( ! V_100 )
return 0 ;
if ( ! F_38 ( V_1 ) )
return - 1 ;
V_114 = ( F_38 ( V_1 ) + V_68 - 1 ) >>
V_50 ;
V_64 = ( sizeof( T_3 ) * V_114 ) + sizeof( T_1 ) ;
F_80 ( V_1 -> V_24 ) ;
F_81 ( V_1 , V_1 -> V_119 &
~ ( V_3 -> V_120 - 1 ) , ( T_1 ) - 1 ) ;
if ( V_64 + sizeof( struct V_69 ) >= V_68 ) {
F_55 ( V_121 L_14 ) ;
V_16 = 0 ;
goto V_122;
}
V_55 = V_54 = F_45 ( sizeof( T_3 ) * V_114 , V_48 ) ;
if ( ! V_55 )
return - 1 ;
V_103 = F_45 ( sizeof( struct V_53 * ) * V_114 , V_48 ) ;
if ( ! V_103 ) {
F_48 ( V_55 ) ;
return - 1 ;
}
if ( V_28 && ! F_82 ( & V_28 -> V_123 ) )
V_107 = F_71 ( V_28 -> V_123 . V_87 ,
struct V_106 ,
V_124 ) ;
V_109 = V_3 -> V_22 -> V_125 ;
while ( V_63 < V_114 ) {
V_53 = F_56 ( V_1 -> V_24 , V_63 ) ;
if ( ! V_53 ) {
int V_126 ;
for ( V_126 = 0 ; V_126 < V_114 ; V_126 ++ ) {
F_60 ( V_103 [ V_126 ] ) ;
F_61 ( V_103 [ V_126 ] ) ;
}
goto V_127;
}
V_103 [ V_63 ] = V_53 ;
V_63 ++ ;
}
V_63 = 0 ;
F_83 ( & F_54 ( V_1 ) -> V_128 , 0 , F_38 ( V_1 ) - 1 ,
0 , & V_105 , V_48 ) ;
if ( V_28 )
V_111 = V_28 -> V_8 . V_17 ;
do {
struct V_69 * V_70 ;
void * V_73 ;
unsigned long V_6 = 0 ;
unsigned long V_74 = 0 ;
V_116 = false ;
if ( V_63 == 0 ) {
V_74 = V_64 ;
V_6 = V_74 ;
}
if ( V_63 >= V_114 ) {
V_117 = true ;
break;
}
V_53 = V_103 [ V_63 ] ;
V_73 = F_62 ( V_53 ) ;
V_70 = V_73 + V_74 ;
memset ( V_73 , 0 , V_68 ) ;
while ( V_100 && ! V_116 ) {
struct V_71 * V_72 ;
V_72 = F_84 ( V_100 , struct V_71 , V_129 ) ;
V_115 ++ ;
V_70 -> V_6 = F_85 ( V_72 -> V_6 ) ;
V_70 -> V_79 = F_85 ( V_72 -> V_79 ) ;
if ( V_72 -> V_82 ) {
V_70 -> type = V_130 ;
F_70 ( & V_72 -> V_86 , & V_110 ) ;
V_58 ++ ;
} else {
V_70 -> type = V_80 ;
}
V_100 = F_86 ( V_100 ) ;
if ( ! V_100 && V_107 ) {
V_100 = F_79 ( & V_107 -> V_3 ) ;
V_107 = NULL ;
}
V_6 += sizeof( struct V_69 ) ;
if ( V_6 + sizeof( struct V_69 ) >=
V_68 )
V_116 = true ;
V_70 ++ ;
}
while ( V_28 && ! V_116 &&
( V_111 < V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 ) ) {
V_16 = F_87 ( V_109 , V_111 , & V_111 , & V_112 ,
V_131 ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_111 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
break;
V_113 = V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 - V_111 ;
V_113 = F_88 ( V_113 , V_112 + 1 - V_111 ) ;
V_115 ++ ;
V_70 -> V_6 = F_85 ( V_111 ) ;
V_70 -> V_79 = F_85 ( V_113 ) ;
V_70 -> type = V_80 ;
V_111 = V_112 + 1 ;
V_6 += sizeof( struct V_69 ) ;
if ( V_6 + sizeof( struct V_69 ) >=
V_68 )
V_116 = true ;
V_70 ++ ;
}
* V_55 = ~ ( T_3 ) 0 ;
* V_55 = F_64 ( V_3 , V_73 + V_74 , * V_55 ,
V_68 - V_74 ) ;
F_63 ( V_53 ) ;
F_65 ( * V_55 , ( char * ) V_55 ) ;
V_55 ++ ;
V_79 += V_68 ;
V_63 ++ ;
} while ( V_100 || V_116 );
F_89 (pos, n, &bitmap_list) {
void * V_73 ;
struct V_71 * V_70 =
F_71 ( V_101 , struct V_71 , V_86 ) ;
if ( V_63 >= V_114 ) {
V_117 = true ;
break;
}
V_53 = V_103 [ V_63 ] ;
V_73 = F_62 ( V_53 ) ;
memcpy ( V_73 , V_70 -> V_82 , V_68 ) ;
* V_55 = ~ ( T_3 ) 0 ;
* V_55 = F_64 ( V_3 , V_73 , * V_55 , V_68 ) ;
F_63 ( V_53 ) ;
F_65 ( * V_55 , ( char * ) V_55 ) ;
V_55 ++ ;
V_79 += V_68 ;
F_72 ( & V_70 -> V_86 ) ;
V_63 ++ ;
}
if ( V_117 ) {
F_90 ( V_103 , V_114 ) ;
F_91 ( & F_54 ( V_1 ) -> V_128 , 0 ,
F_38 ( V_1 ) - 1 , & V_105 ,
V_48 ) ;
V_16 = 0 ;
goto V_127;
}
while ( V_63 < V_114 ) {
void * V_73 ;
V_53 = V_103 [ V_63 ] ;
V_73 = F_62 ( V_53 ) ;
memset ( V_73 , 0 , V_68 ) ;
F_63 ( V_53 ) ;
V_79 += V_68 ;
V_63 ++ ;
}
{
void * V_73 ;
T_1 * V_77 ;
V_53 = V_103 [ 0 ] ;
V_73 = F_62 ( V_53 ) ;
memcpy ( V_73 , V_54 , sizeof( T_3 ) * V_114 ) ;
V_77 = V_73 + ( sizeof( T_3 ) * V_114 ) ;
* V_77 = V_32 -> V_36 ;
F_63 ( V_53 ) ;
}
V_16 = F_92 ( V_3 , V_1 , V_103 , V_114 , 0 ,
V_79 , & V_105 ) ;
F_90 ( V_103 , V_114 ) ;
F_91 ( & F_54 ( V_1 ) -> V_128 , 0 ,
F_38 ( V_1 ) - 1 , & V_105 , V_48 ) ;
if ( V_16 ) {
V_16 = 0 ;
goto V_127;
}
F_54 ( V_1 ) -> V_61 = V_32 -> V_36 ;
F_80 ( V_1 -> V_24 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_32 , V_3 , & V_8 , V_5 , 1 , 1 ) ;
if ( V_16 < 0 ) {
V_16 = - 1 ;
F_93 ( & F_54 ( V_1 ) -> V_128 , 0 , V_79 - 1 ,
V_131 | V_132 |
V_133 , 0 , 0 , NULL , V_48 ) ;
goto V_127;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_134 ;
F_94 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_95 ( V_15 , & V_134 , V_5 -> V_21 [ 0 ] ) ;
if ( V_134 . V_17 != V_18 ||
V_134 . V_6 != V_6 ) {
V_16 = - 1 ;
F_93 ( & F_54 ( V_1 ) -> V_128 , 0 , V_79 - 1 ,
V_131 | V_132 |
V_133 , 0 , 0 , NULL ,
V_48 ) ;
F_4 ( V_5 ) ;
goto V_127;
}
}
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_96 ( V_15 , V_13 , V_115 ) ;
F_97 ( V_15 , V_13 , V_58 ) ;
F_98 ( V_15 , V_13 , V_32 -> V_36 ) ;
F_31 ( V_15 ) ;
F_4 ( V_5 ) ;
V_16 = 1 ;
V_127:
F_48 ( V_54 ) ;
F_48 ( V_103 ) ;
V_122:
if ( V_16 != 1 ) {
F_99 ( V_1 -> V_24 , 0 , V_63 ) ;
F_54 ( V_1 ) -> V_61 = 0 ;
}
F_43 ( V_32 , V_3 , V_1 ) ;
return V_16 ;
}
int F_100 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_90 ;
F_13 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_94 < V_135 ) {
F_15 ( & V_28 -> V_29 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_29 ) ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_78 ( V_3 , V_1 , V_52 , V_28 , V_32 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 < 0 ) {
F_13 ( & V_28 -> V_29 ) ;
V_28 -> V_94 = V_136 ;
F_15 ( & V_28 -> V_29 ) ;
V_16 = 0 ;
F_55 ( V_67 L_15
L_13 , V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_101 ( T_1 V_137 , T_3 V_138 ,
T_1 V_6 )
{
F_94 ( V_6 < V_137 ) ;
V_6 -= V_137 ;
return ( unsigned long ) ( F_102 ( V_6 , V_138 ) ) ;
}
static inline unsigned long F_103 ( T_1 V_79 , T_3 V_138 )
{
return ( unsigned long ) ( F_102 ( V_79 , V_138 ) ) ;
}
static inline T_1 F_104 ( struct V_51 * V_52 ,
T_1 V_6 )
{
T_1 V_137 ;
T_1 V_139 ;
V_139 = V_140 * V_52 -> V_138 ;
V_137 = V_6 - V_52 -> V_111 ;
V_137 = F_105 ( V_137 , V_139 ) ;
V_137 *= V_139 ;
V_137 += V_52 -> V_111 ;
return V_137 ;
}
static int F_106 ( struct V_141 * V_3 , T_1 V_6 ,
struct V_99 * V_100 , int V_82 )
{
struct V_99 * * V_142 = & V_3 -> V_99 ;
struct V_99 * V_143 = NULL ;
struct V_71 * V_144 ;
while ( * V_142 ) {
V_143 = * V_142 ;
V_144 = F_84 ( V_143 , struct V_71 , V_129 ) ;
if ( V_6 < V_144 -> V_6 ) {
V_142 = & ( * V_142 ) -> V_145 ;
} else if ( V_6 > V_144 -> V_6 ) {
V_142 = & ( * V_142 ) -> V_146 ;
} else {
if ( V_82 ) {
if ( V_144 -> V_82 ) {
F_107 ( 1 ) ;
return - V_147 ;
}
V_142 = & ( * V_142 ) -> V_146 ;
} else {
if ( ! V_144 -> V_82 ) {
F_107 ( 1 ) ;
return - V_147 ;
}
V_142 = & ( * V_142 ) -> V_145 ;
}
}
}
F_108 ( V_100 , V_143 , V_142 ) ;
F_109 ( V_100 , V_3 ) ;
return 0 ;
}
static struct V_71 *
F_110 ( struct V_51 * V_52 ,
T_1 V_6 , int V_148 , int V_149 )
{
struct V_99 * V_102 = V_52 -> V_118 . V_99 ;
struct V_71 * V_70 , * V_150 = NULL ;
while ( 1 ) {
if ( ! V_102 ) {
V_70 = NULL ;
break;
}
V_70 = F_84 ( V_102 , struct V_71 , V_129 ) ;
V_150 = V_70 ;
if ( V_6 < V_70 -> V_6 )
V_102 = V_102 -> V_145 ;
else if ( V_6 > V_70 -> V_6 )
V_102 = V_102 -> V_146 ;
else
break;
}
if ( V_148 ) {
if ( ! V_70 )
return NULL ;
if ( V_70 -> V_82 )
return V_70 ;
V_102 = F_86 ( V_102 ) ;
if ( ! V_102 )
return NULL ;
V_70 = F_84 ( V_102 , struct V_71 , V_129 ) ;
if ( V_70 -> V_6 != V_6 )
return NULL ;
F_42 ( ! V_70 -> V_82 ) ;
return V_70 ;
} else if ( V_70 ) {
if ( V_70 -> V_82 ) {
V_102 = & V_70 -> V_129 ;
while ( 1 ) {
V_102 = F_111 ( V_102 ) ;
if ( ! V_102 )
break;
V_150 = F_84 ( V_102 , struct V_71 ,
V_129 ) ;
if ( ! V_150 -> V_82 ) {
if ( V_150 -> V_6 + V_150 -> V_79 > V_6 )
V_70 = V_150 ;
break;
}
}
}
return V_70 ;
}
if ( ! V_150 )
return NULL ;
V_70 = V_150 ;
if ( V_70 -> V_6 > V_6 ) {
V_102 = F_111 ( & V_70 -> V_129 ) ;
if ( V_102 ) {
V_70 = F_84 ( V_102 , struct V_71 ,
V_129 ) ;
F_94 ( V_70 -> V_6 > V_6 ) ;
} else {
if ( V_149 )
return V_70 ;
else
return NULL ;
}
}
if ( V_70 -> V_82 ) {
V_102 = & V_70 -> V_129 ;
while ( 1 ) {
V_102 = F_111 ( V_102 ) ;
if ( ! V_102 )
break;
V_150 = F_84 ( V_102 , struct V_71 ,
V_129 ) ;
if ( ! V_150 -> V_82 ) {
if ( V_150 -> V_6 + V_150 -> V_79 > V_6 )
return V_150 ;
break;
}
}
if ( V_70 -> V_6 + V_140 * V_52 -> V_138 > V_6 )
return V_70 ;
} else if ( V_70 -> V_6 + V_70 -> V_79 > V_6 )
return V_70 ;
if ( ! V_149 )
return NULL ;
while ( 1 ) {
if ( V_70 -> V_82 ) {
if ( V_70 -> V_6 + V_140 *
V_52 -> V_138 > V_6 )
break;
} else {
if ( V_70 -> V_6 + V_70 -> V_79 > V_6 )
break;
}
V_102 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_102 )
return NULL ;
V_70 = F_84 ( V_102 , struct V_71 , V_129 ) ;
}
return V_70 ;
}
static inline void
F_112 ( struct V_51 * V_52 ,
struct V_71 * V_144 )
{
F_113 ( & V_144 -> V_129 , & V_52 -> V_118 ) ;
V_52 -> V_151 -- ;
}
static void F_114 ( struct V_51 * V_52 ,
struct V_71 * V_144 )
{
F_112 ( V_52 , V_144 ) ;
V_52 -> V_96 -= V_144 -> V_79 ;
}
static int F_69 ( struct V_51 * V_52 ,
struct V_71 * V_144 )
{
int V_16 = 0 ;
F_94 ( ! V_144 -> V_82 && ! V_144 -> V_79 ) ;
V_16 = F_106 ( & V_52 -> V_118 , V_144 -> V_6 ,
& V_144 -> V_129 , ( V_144 -> V_82 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_52 -> V_96 += V_144 -> V_79 ;
V_52 -> V_151 ++ ;
return V_16 ;
}
static void F_115 ( struct V_51 * V_52 )
{
struct V_27 * V_28 = V_52 -> V_152 ;
T_1 V_153 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_156 = V_28 -> V_8 . V_6 ;
T_1 V_157 = V_140 * V_28 -> V_120 ;
int V_158 = F_105 ( V_156 + V_157 - 1 , V_157 ) ;
F_94 ( V_52 -> V_83 > V_158 ) ;
if ( V_156 < 1024 * 1024 * 1024 )
V_153 = V_159 ;
else
V_153 = V_159 *
F_105 ( V_156 , 1024 * 1024 * 1024 ) ;
V_154 = ( V_52 -> V_83 + 1 ) * V_68 ;
if ( V_154 >= V_153 ) {
V_52 -> V_160 = 0 ;
return;
}
V_155 = V_153 - V_154 ;
V_155 = F_116 ( T_1 , V_155 , F_105 ( V_153 , 2 ) ) ;
V_52 -> V_160 =
F_105 ( V_155 , ( sizeof( struct V_71 ) ) ) ;
}
static void F_117 ( struct V_51 * V_52 ,
struct V_71 * V_144 , T_1 V_6 ,
T_1 V_79 )
{
unsigned long V_111 , V_161 ;
V_111 = F_101 ( V_144 -> V_6 , V_52 -> V_138 , V_6 ) ;
V_161 = F_103 ( V_79 , V_52 -> V_138 ) ;
F_94 ( V_111 + V_161 > V_140 ) ;
F_118 ( V_144 -> V_82 , V_111 , V_161 ) ;
V_144 -> V_79 -= V_79 ;
V_52 -> V_96 -= V_79 ;
}
static void F_119 ( struct V_51 * V_52 ,
struct V_71 * V_144 , T_1 V_6 ,
T_1 V_79 )
{
unsigned long V_111 , V_161 ;
V_111 = F_101 ( V_144 -> V_6 , V_52 -> V_138 , V_6 ) ;
V_161 = F_103 ( V_79 , V_52 -> V_138 ) ;
F_94 ( V_111 + V_161 > V_140 ) ;
F_120 ( V_144 -> V_82 , V_111 , V_161 ) ;
V_144 -> V_79 += V_79 ;
V_52 -> V_96 += V_79 ;
}
static int F_121 ( struct V_51 * V_52 ,
struct V_71 * V_162 , T_1 * V_6 ,
T_1 * V_79 )
{
unsigned long V_163 = 0 ;
unsigned long V_164 , V_126 ;
unsigned long V_165 ;
V_126 = F_101 ( V_162 -> V_6 , V_52 -> V_138 ,
F_122 ( T_1 , * V_6 , V_162 -> V_6 ) ) ;
V_164 = F_103 ( * V_79 , V_52 -> V_138 ) ;
for ( V_126 = F_123 ( V_162 -> V_82 , V_140 , V_126 ) ;
V_126 < V_140 ;
V_126 = F_123 ( V_162 -> V_82 , V_140 , V_126 + 1 ) ) {
V_165 = F_124 ( V_162 -> V_82 ,
V_140 , V_126 ) ;
if ( ( V_165 - V_126 ) >= V_164 ) {
V_163 = V_165 - V_126 ;
break;
}
V_126 = V_165 ;
}
if ( V_163 ) {
* V_6 = ( T_1 ) ( V_126 * V_52 -> V_138 ) + V_162 -> V_6 ;
* V_79 = ( T_1 ) ( V_163 ) * V_52 -> V_138 ;
return 0 ;
}
return - 1 ;
}
static struct V_71 *
F_125 ( struct V_51 * V_52 , T_1 * V_6 , T_1 * V_79 )
{
struct V_71 * V_70 ;
struct V_99 * V_100 ;
int V_16 ;
if ( ! V_52 -> V_118 . V_99 )
return NULL ;
V_70 = F_110 ( V_52 , F_104 ( V_52 , * V_6 ) , 0 , 1 ) ;
if ( ! V_70 )
return NULL ;
for ( V_100 = & V_70 -> V_129 ; V_100 ; V_100 = F_86 ( V_100 ) ) {
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
if ( V_70 -> V_79 < * V_79 )
continue;
if ( V_70 -> V_82 ) {
V_16 = F_121 ( V_52 , V_70 , V_6 , V_79 ) ;
if ( ! V_16 )
return V_70 ;
continue;
}
* V_6 = V_70 -> V_6 ;
* V_79 = V_70 -> V_79 ;
return V_70 ;
}
return NULL ;
}
static void F_126 ( struct V_51 * V_52 ,
struct V_71 * V_144 , T_1 V_6 )
{
V_144 -> V_6 = F_104 ( V_52 , V_6 ) ;
V_144 -> V_79 = 0 ;
F_69 ( V_52 , V_144 ) ;
V_52 -> V_83 ++ ;
V_52 -> V_84 -> V_85 ( V_52 ) ;
}
static void F_127 ( struct V_51 * V_52 ,
struct V_71 * V_162 )
{
F_114 ( V_52 , V_162 ) ;
F_48 ( V_162 -> V_82 ) ;
F_68 ( V_78 , V_162 ) ;
V_52 -> V_83 -- ;
V_52 -> V_84 -> V_85 ( V_52 ) ;
}
static T_5 int F_128 ( struct V_51 * V_52 ,
struct V_71 * V_162 ,
T_1 * V_6 , T_1 * V_79 )
{
T_1 V_112 ;
T_1 V_166 , V_167 ;
int V_16 ;
V_168:
V_112 = V_162 -> V_6 + ( T_1 ) ( V_140 * V_52 -> V_138 ) - 1 ;
V_166 = * V_6 ;
V_167 = * V_79 ;
V_167 = F_88 ( V_167 , V_112 - V_166 + 1 ) ;
V_16 = F_121 ( V_52 , V_162 , & V_166 , & V_167 ) ;
F_94 ( V_16 < 0 || V_166 != * V_6 ) ;
if ( * V_6 > V_162 -> V_6 && * V_6 + * V_79 > V_112 ) {
F_117 ( V_52 , V_162 , * V_6 , V_112 - * V_6 + 1 ) ;
* V_79 -= V_112 - * V_6 + 1 ;
* V_6 = V_112 + 1 ;
} else if ( * V_6 >= V_162 -> V_6 && * V_6 + * V_79 <= V_112 ) {
F_117 ( V_52 , V_162 , * V_6 , * V_79 ) ;
* V_79 = 0 ;
}
if ( * V_79 ) {
struct V_99 * V_87 = F_86 ( & V_162 -> V_129 ) ;
if ( ! V_162 -> V_79 )
F_127 ( V_52 , V_162 ) ;
if ( ! V_87 )
return - V_169 ;
V_162 = F_84 ( V_87 , struct V_71 ,
V_129 ) ;
if ( ! V_162 -> V_82 )
return - V_170 ;
V_166 = * V_6 ;
V_167 = * V_79 ;
V_16 = F_121 ( V_52 , V_162 , & V_166 ,
& V_167 ) ;
if ( V_16 < 0 || V_166 != * V_6 )
return - V_170 ;
goto V_168;
} else if ( ! V_162 -> V_79 )
F_127 ( V_52 , V_162 ) ;
return 0 ;
}
static T_1 F_129 ( struct V_51 * V_52 ,
struct V_71 * V_144 , T_1 V_6 ,
T_1 V_79 )
{
T_1 V_171 = 0 ;
T_1 V_112 ;
V_112 = V_144 -> V_6 + ( T_1 ) ( V_140 * V_52 -> V_138 ) ;
V_171 = F_88 ( V_112 - V_6 , V_79 ) ;
F_119 ( V_52 , V_144 , V_6 , V_171 ) ;
return V_171 ;
}
static bool F_130 ( struct V_51 * V_52 ,
struct V_71 * V_144 )
{
struct V_27 * V_28 = V_52 -> V_152 ;
if ( V_52 -> V_151 < V_52 -> V_160 ) {
if ( V_144 -> V_79 <= V_28 -> V_120 * 4 ) {
if ( V_52 -> V_151 * 2 <= V_52 -> V_160 )
return false ;
} else {
return false ;
}
}
if ( V_140 * V_28 -> V_120 >
V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_131 ( struct V_51 * V_52 ,
struct V_71 * V_144 )
{
struct V_71 * V_162 ;
struct V_27 * V_28 = NULL ;
int V_172 = 0 ;
T_1 V_79 , V_6 , V_173 ;
int V_16 ;
V_79 = V_144 -> V_79 ;
V_6 = V_144 -> V_6 ;
if ( ! V_52 -> V_84 -> F_130 ( V_52 , V_144 ) )
return 0 ;
if ( V_52 -> V_84 == & V_174 )
V_28 = V_52 -> V_152 ;
V_168:
if ( V_28 && ! F_82 ( & V_28 -> V_123 ) ) {
struct V_106 * V_107 ;
struct V_99 * V_100 ;
struct V_71 * V_70 ;
V_107 = F_71 ( V_28 -> V_123 . V_87 ,
struct V_106 ,
V_124 ) ;
F_13 ( & V_107 -> V_29 ) ;
V_100 = F_79 ( & V_107 -> V_3 ) ;
if ( ! V_100 ) {
F_15 ( & V_107 -> V_29 ) ;
goto V_175;
}
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
if ( ! V_70 -> V_82 ) {
F_15 ( & V_107 -> V_29 ) ;
goto V_175;
}
if ( V_70 -> V_6 == F_104 ( V_52 , V_6 ) ) {
V_173 = F_129 ( V_52 , V_70 ,
V_6 , V_79 ) ;
V_79 -= V_173 ;
V_6 += V_173 ;
}
F_15 ( & V_107 -> V_29 ) ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_66;
}
}
V_175:
V_162 = F_110 ( V_52 , F_104 ( V_52 , V_6 ) ,
1 , 0 ) ;
if ( ! V_162 ) {
F_94 ( V_172 ) ;
goto V_176;
}
V_173 = F_129 ( V_52 , V_162 , V_6 , V_79 ) ;
V_79 -= V_173 ;
V_6 += V_173 ;
V_172 = 0 ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_66;
} else
goto V_168;
V_176:
if ( V_144 && V_144 -> V_82 ) {
F_126 ( V_52 , V_144 , V_6 ) ;
V_172 = 1 ;
V_144 = NULL ;
goto V_168;
} else {
F_15 ( & V_52 -> V_81 ) ;
if ( ! V_144 ) {
V_144 = F_66 ( V_78 ,
V_48 ) ;
if ( ! V_144 ) {
F_13 ( & V_52 -> V_81 ) ;
V_16 = - V_49 ;
goto V_66;
}
}
V_144 -> V_82 = F_45 ( V_68 , V_48 ) ;
F_13 ( & V_52 -> V_81 ) ;
if ( ! V_144 -> V_82 ) {
V_16 = - V_49 ;
goto V_66;
}
goto V_168;
}
V_66:
if ( V_144 ) {
if ( V_144 -> V_82 )
F_48 ( V_144 -> V_82 ) ;
F_68 ( V_78 , V_144 ) ;
}
return V_16 ;
}
static bool F_132 ( struct V_51 * V_52 ,
struct V_71 * V_144 , bool V_177 )
{
struct V_71 * V_178 ;
struct V_71 * V_179 ;
bool V_180 = false ;
T_1 V_6 = V_144 -> V_6 ;
T_1 V_79 = V_144 -> V_79 ;
V_179 = F_110 ( V_52 , V_6 + V_79 , 0 , 0 ) ;
if ( V_179 && F_111 ( & V_179 -> V_129 ) )
V_178 = F_84 ( F_111 ( & V_179 -> V_129 ) ,
struct V_71 , V_129 ) ;
else
V_178 = F_110 ( V_52 , V_6 - 1 , 0 , 0 ) ;
if ( V_179 && ! V_179 -> V_82 ) {
if ( V_177 )
F_114 ( V_52 , V_179 ) ;
else
F_112 ( V_52 , V_179 ) ;
V_144 -> V_79 += V_179 -> V_79 ;
F_68 ( V_78 , V_179 ) ;
V_180 = true ;
}
if ( V_178 && ! V_178 -> V_82 &&
V_178 -> V_6 + V_178 -> V_79 == V_6 ) {
if ( V_177 )
F_114 ( V_52 , V_178 ) ;
else
F_112 ( V_52 , V_178 ) ;
V_144 -> V_6 = V_178 -> V_6 ;
V_144 -> V_79 += V_178 -> V_79 ;
F_68 ( V_78 , V_178 ) ;
V_180 = true ;
}
return V_180 ;
}
int F_133 ( struct V_51 * V_52 ,
T_1 V_6 , T_1 V_79 )
{
struct V_71 * V_144 ;
int V_16 = 0 ;
V_144 = F_66 ( V_78 , V_48 ) ;
if ( ! V_144 )
return - V_49 ;
V_144 -> V_6 = V_6 ;
V_144 -> V_79 = V_79 ;
F_13 ( & V_52 -> V_81 ) ;
if ( F_132 ( V_52 , V_144 , true ) )
goto V_181;
V_16 = F_131 ( V_52 , V_144 ) ;
if ( V_16 < 0 ) {
goto V_66;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_66;
}
V_181:
V_16 = F_69 ( V_52 , V_144 ) ;
if ( V_16 )
F_68 ( V_78 , V_144 ) ;
V_66:
F_15 ( & V_52 -> V_81 ) ;
if ( V_16 ) {
F_55 ( V_121 L_16 , V_16 ) ;
F_94 ( V_16 == - V_147 ) ;
}
return V_16 ;
}
int F_134 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_79 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_144 ;
struct V_71 * V_182 = NULL ;
int V_16 = 0 ;
F_13 ( & V_52 -> V_81 ) ;
V_168:
V_144 = F_110 ( V_52 , V_6 , 0 , 0 ) ;
if ( ! V_144 ) {
V_144 = F_110 ( V_52 , F_104 ( V_52 , V_6 ) ,
1 , 0 ) ;
if ( ! V_144 ) {
F_42 ( 1 ) ;
goto V_183;
}
}
if ( V_144 -> V_79 < V_79 && F_86 ( & V_144 -> V_129 ) ) {
T_1 V_112 ;
V_182 = F_84 ( F_86 ( & V_144 -> V_129 ) ,
struct V_71 ,
V_129 ) ;
if ( V_182 -> V_82 )
V_112 = V_182 -> V_6 +
V_140 * V_52 -> V_138 - 1 ;
else
V_112 = V_182 -> V_6 + V_182 -> V_79 ;
if ( V_182 -> V_79 < V_79 ||
V_182 -> V_6 > V_6 || V_6 > V_112 ) {
F_55 ( V_121 L_17
L_18 ,
( unsigned long long ) V_144 -> V_6 ,
( unsigned long long ) V_144 -> V_79 ,
( unsigned long long ) V_79 ) ;
F_42 ( 1 ) ;
V_16 = - V_169 ;
goto V_183;
}
V_144 = V_182 ;
}
if ( V_144 -> V_79 == V_79 ) {
F_114 ( V_52 , V_144 ) ;
if ( V_144 -> V_82 ) {
F_48 ( V_144 -> V_82 ) ;
V_52 -> V_83 -- ;
}
F_68 ( V_78 , V_144 ) ;
goto V_183;
}
if ( ! V_144 -> V_82 && V_144 -> V_6 == V_6 ) {
F_114 ( V_52 , V_144 ) ;
V_144 -> V_6 += V_79 ;
V_144 -> V_79 -= V_79 ;
F_69 ( V_52 , V_144 ) ;
goto V_183;
}
if ( ! V_144 -> V_82 && V_144 -> V_6 <= V_6 &&
V_144 -> V_6 + V_144 -> V_79 >= V_6 + V_79 ) {
T_1 V_184 = V_144 -> V_6 ;
F_114 ( V_52 , V_144 ) ;
if ( V_6 + V_79 < V_144 -> V_6 + V_144 -> V_79 ) {
T_1 V_185 = V_144 -> V_6 + V_144 -> V_79 ;
V_144 -> V_6 = V_6 + V_79 ;
V_144 -> V_79 = V_185 - V_144 -> V_6 ;
V_16 = F_69 ( V_52 , V_144 ) ;
F_42 ( V_16 ) ;
if ( V_16 )
goto V_183;
} else {
F_68 ( V_78 , V_144 ) ;
}
F_15 ( & V_52 -> V_81 ) ;
V_16 = F_135 ( V_28 , V_184 ,
V_6 - V_184 ) ;
F_42 ( V_16 ) ;
goto V_66;
}
V_16 = F_128 ( V_52 , V_144 , & V_6 , & V_79 ) ;
if ( V_16 == - V_170 )
goto V_168;
F_94 ( V_16 ) ;
V_183:
F_15 ( & V_52 -> V_81 ) ;
V_66:
return V_16 ;
}
void F_136 ( struct V_27 * V_28 ,
T_1 V_79 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_144 ;
struct V_99 * V_102 ;
int V_161 = 0 ;
for ( V_102 = F_79 ( & V_52 -> V_118 ) ; V_102 ; V_102 = F_86 ( V_102 ) ) {
V_144 = F_84 ( V_102 , struct V_71 , V_129 ) ;
if ( V_144 -> V_79 >= V_79 )
V_161 ++ ;
F_55 ( V_121 L_19 ,
( unsigned long long ) V_144 -> V_6 ,
( unsigned long long ) V_144 -> V_79 ,
( V_144 -> V_82 ) ? L_20 : L_21 ) ;
}
F_55 ( V_186 L_22 ,
F_82 ( & V_28 -> V_123 ) ? L_21 : L_20 ) ;
F_55 ( V_186 L_23
L_24 , V_161 ) ;
}
void F_137 ( struct V_27 * V_28 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
F_138 ( & V_52 -> V_81 ) ;
V_52 -> V_138 = V_28 -> V_120 ;
V_52 -> V_111 = V_28 -> V_8 . V_17 ;
V_52 -> V_152 = V_28 ;
V_52 -> V_84 = & V_174 ;
V_52 -> V_160 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_71 ) ;
}
static int
F_139 (
struct V_27 * V_28 ,
struct V_106 * V_107 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_70 ;
struct V_99 * V_100 ;
F_13 ( & V_107 -> V_29 ) ;
if ( V_107 -> V_28 != V_28 )
goto V_66;
V_107 -> V_28 = NULL ;
V_107 -> V_187 = 0 ;
F_72 ( & V_107 -> V_124 ) ;
V_100 = F_79 ( & V_107 -> V_3 ) ;
while ( V_100 ) {
bool V_82 ;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
V_100 = F_86 ( & V_70 -> V_129 ) ;
F_113 ( & V_70 -> V_129 , & V_107 -> V_3 ) ;
V_82 = ( V_70 -> V_82 != NULL ) ;
if ( ! V_82 )
F_132 ( V_52 , V_70 , false ) ;
F_106 ( & V_52 -> V_118 ,
V_70 -> V_6 , & V_70 -> V_129 , V_82 ) ;
}
V_107 -> V_3 = V_188 ;
V_66:
F_15 ( & V_107 -> V_29 ) ;
F_140 ( V_28 ) ;
return 0 ;
}
void F_141 ( struct V_51 * V_52 )
{
struct V_71 * V_144 ;
struct V_99 * V_100 ;
while ( ( V_100 = F_142 ( & V_52 -> V_118 ) ) != NULL ) {
V_144 = F_84 ( V_100 , struct V_71 , V_129 ) ;
if ( ! V_144 -> V_82 ) {
F_114 ( V_52 , V_144 ) ;
F_68 ( V_78 , V_144 ) ;
} else {
F_127 ( V_52 , V_144 ) ;
}
if ( F_143 () ) {
F_15 ( & V_52 -> V_81 ) ;
F_144 () ;
F_13 ( & V_52 -> V_81 ) ;
}
}
}
void F_73 ( struct V_51 * V_52 )
{
F_13 ( & V_52 -> V_81 ) ;
F_141 ( V_52 ) ;
F_15 ( & V_52 -> V_81 ) ;
}
void F_145 ( struct V_27 * V_28 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_106 * V_107 ;
struct V_57 * V_189 ;
F_13 ( & V_52 -> V_81 ) ;
while ( ( V_189 = V_28 -> V_123 . V_87 ) !=
& V_28 -> V_123 ) {
V_107 = F_71 ( V_189 , struct V_106 ,
V_124 ) ;
F_42 ( V_107 -> V_28 != V_28 ) ;
F_139 ( V_28 , V_107 ) ;
if ( F_143 () ) {
F_15 ( & V_52 -> V_81 ) ;
F_144 () ;
F_13 ( & V_52 -> V_81 ) ;
}
}
F_141 ( V_52 ) ;
F_15 ( & V_52 -> V_81 ) ;
}
T_1 F_146 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_79 , T_1 V_190 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_70 = NULL ;
T_1 V_191 = V_79 + V_190 ;
T_1 V_16 = 0 ;
F_13 ( & V_52 -> V_81 ) ;
V_70 = F_125 ( V_52 , & V_6 , & V_191 ) ;
if ( ! V_70 )
goto V_66;
V_16 = V_6 ;
if ( V_70 -> V_82 ) {
F_117 ( V_52 , V_70 , V_6 , V_79 ) ;
if ( ! V_70 -> V_79 )
F_127 ( V_52 , V_70 ) ;
} else {
F_114 ( V_52 , V_70 ) ;
V_70 -> V_6 += V_79 ;
V_70 -> V_79 -= V_79 ;
if ( ! V_70 -> V_79 )
F_68 ( V_78 , V_70 ) ;
else
F_69 ( V_52 , V_70 ) ;
}
V_66:
F_15 ( & V_52 -> V_81 ) ;
return V_16 ;
}
int F_147 (
struct V_27 * V_28 ,
struct V_106 * V_107 )
{
struct V_51 * V_52 ;
int V_16 ;
F_13 ( & V_107 -> V_29 ) ;
if ( ! V_28 ) {
V_28 = V_107 -> V_28 ;
if ( ! V_28 ) {
F_15 ( & V_107 -> V_29 ) ;
return 0 ;
}
} else if ( V_107 -> V_28 != V_28 ) {
F_15 ( & V_107 -> V_29 ) ;
return 0 ;
}
F_148 ( & V_28 -> V_161 ) ;
F_15 ( & V_107 -> V_29 ) ;
V_52 = V_28 -> V_89 ;
F_13 ( & V_52 -> V_81 ) ;
V_16 = F_139 ( V_28 , V_107 ) ;
F_15 ( & V_52 -> V_81 ) ;
F_140 ( V_28 ) ;
return V_16 ;
}
static T_1 F_149 ( struct V_27 * V_28 ,
struct V_106 * V_107 ,
struct V_71 * V_70 ,
T_1 V_79 , T_1 V_192 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
int V_193 ;
T_1 V_166 = V_107 -> V_187 ;
T_1 V_167 = V_79 ;
T_1 V_16 = 0 ;
V_166 = V_192 ;
V_167 = V_79 ;
V_193 = F_121 ( V_52 , V_70 , & V_166 , & V_167 ) ;
if ( V_193 )
return 0 ;
V_16 = V_166 ;
F_117 ( V_52 , V_70 , V_16 , V_79 ) ;
return V_16 ;
}
T_1 F_150 ( struct V_27 * V_28 ,
struct V_106 * V_107 , T_1 V_79 ,
T_1 V_192 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_70 = NULL ;
struct V_99 * V_100 ;
T_1 V_16 = 0 ;
F_13 ( & V_107 -> V_29 ) ;
if ( V_79 > V_107 -> V_194 )
goto V_66;
if ( V_107 -> V_28 != V_28 )
goto V_66;
V_100 = F_79 ( & V_107 -> V_3 ) ;
if ( ! V_100 )
goto V_66;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
while( 1 ) {
if ( V_70 -> V_79 < V_79 ||
( ! V_70 -> V_82 && V_70 -> V_6 < V_192 ) ) {
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_100 )
break;
V_70 = F_84 ( V_100 , struct V_71 ,
V_129 ) ;
continue;
}
if ( V_70 -> V_82 ) {
V_16 = F_149 ( V_28 ,
V_107 , V_70 , V_79 ,
V_192 ) ;
if ( V_16 == 0 ) {
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_100 )
break;
V_70 = F_84 ( V_100 , struct V_71 ,
V_129 ) ;
continue;
}
} else {
V_16 = V_70 -> V_6 ;
V_70 -> V_6 += V_79 ;
V_70 -> V_79 -= V_79 ;
}
if ( V_70 -> V_79 == 0 )
F_113 ( & V_70 -> V_129 , & V_107 -> V_3 ) ;
break;
}
V_66:
F_15 ( & V_107 -> V_29 ) ;
if ( ! V_16 )
return 0 ;
F_13 ( & V_52 -> V_81 ) ;
V_52 -> V_96 -= V_79 ;
if ( V_70 -> V_79 == 0 ) {
V_52 -> V_151 -- ;
if ( V_70 -> V_82 ) {
F_48 ( V_70 -> V_82 ) ;
V_52 -> V_83 -- ;
V_52 -> V_84 -> V_85 ( V_52 ) ;
}
F_68 ( V_78 , V_70 ) ;
}
F_15 ( & V_52 -> V_81 ) ;
return V_16 ;
}
static int F_151 ( struct V_27 * V_28 ,
struct V_71 * V_70 ,
struct V_106 * V_107 ,
T_1 V_6 , T_1 V_79 , T_1 V_195 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
unsigned long V_165 ;
unsigned long V_126 ;
unsigned long V_196 ;
unsigned long V_197 ;
unsigned long V_163 ;
unsigned long V_111 = 0 ;
unsigned long V_198 = 0 ;
int V_16 ;
bool V_199 = false ;
V_126 = F_101 ( V_70 -> V_6 , V_28 -> V_120 ,
F_122 ( T_1 , V_6 , V_70 -> V_6 ) ) ;
V_196 = F_103 ( V_79 , V_28 -> V_120 ) ;
V_197 = F_103 ( V_195 , V_28 -> V_120 ) ;
V_168:
V_163 = 0 ;
for ( V_126 = F_123 ( V_70 -> V_82 , V_140 , V_126 ) ;
V_126 < V_140 ;
V_126 = F_123 ( V_70 -> V_82 , V_140 , V_126 + 1 ) ) {
V_165 = F_124 ( V_70 -> V_82 ,
V_140 , V_126 ) ;
if ( V_165 - V_126 >= V_196 ) {
V_163 = V_165 - V_126 ;
break;
}
V_126 = V_165 ;
}
if ( ! V_163 )
return - V_200 ;
if ( ! V_199 ) {
V_111 = V_126 ;
V_199 = true ;
}
V_198 += V_163 ;
if ( V_107 -> V_194 < V_163 * V_28 -> V_120 )
V_107 -> V_194 = V_163 * V_28 -> V_120 ;
if ( V_198 < V_197 ) {
V_126 = F_123 ( V_70 -> V_82 , V_140 , V_165 ) ;
if ( V_126 - V_111 > V_197 * 2 ) {
V_198 = 0 ;
V_107 -> V_194 = 0 ;
V_199 = false ;
}
goto V_168;
}
V_107 -> V_187 = V_111 * V_28 -> V_120 +
V_70 -> V_6 ;
F_113 ( & V_70 -> V_129 , & V_52 -> V_118 ) ;
V_16 = F_106 ( & V_107 -> V_3 , V_70 -> V_6 ,
& V_70 -> V_129 , 1 ) ;
F_94 ( V_16 ) ;
return 0 ;
}
static T_5 int
F_152 ( struct V_27 * V_28 ,
struct V_106 * V_107 ,
struct V_57 * V_58 , T_1 V_6 , T_1 V_79 ,
T_1 V_195 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_201 = NULL ;
struct V_71 * V_70 = NULL ;
struct V_71 * V_150 = NULL ;
struct V_71 * V_202 ;
struct V_99 * V_100 ;
T_1 V_187 ;
T_1 V_203 ;
T_1 V_204 ;
T_1 V_205 = 128 * 1024 ;
V_70 = F_110 ( V_52 , V_6 , 0 , 1 ) ;
if ( ! V_70 )
return - V_200 ;
while ( V_70 -> V_82 ) {
if ( F_82 ( & V_70 -> V_86 ) )
F_70 ( & V_70 -> V_86 , V_58 ) ;
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_100 )
return - V_200 ;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
}
V_187 = V_70 -> V_6 ;
V_203 = V_70 -> V_79 ;
V_204 = V_70 -> V_79 ;
V_201 = V_70 ;
V_202 = V_70 ;
V_150 = V_70 ;
while ( V_203 <= V_195 ) {
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_100 )
return - V_200 ;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
if ( V_70 -> V_82 ) {
if ( F_82 ( & V_70 -> V_86 ) )
F_70 ( & V_70 -> V_86 , V_58 ) ;
continue;
}
if ( V_70 -> V_6 - ( V_150 -> V_6 + V_150 -> V_79 ) > V_205 ||
V_70 -> V_6 - V_187 > ( V_195 * 2 ) ) {
V_201 = V_70 ;
V_187 = V_70 -> V_6 ;
V_203 = V_70 -> V_79 ;
V_202 = V_70 ;
V_204 = V_70 -> V_79 ;
} else {
V_202 = V_70 ;
V_203 += V_70 -> V_79 ;
if ( V_70 -> V_79 > V_204 )
V_204 = V_70 -> V_79 ;
}
V_150 = V_70 ;
}
V_107 -> V_187 = V_201 -> V_6 ;
V_100 = & V_201 -> V_129 ;
do {
int V_16 ;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( V_70 -> V_82 )
continue;
F_113 ( & V_70 -> V_129 , & V_52 -> V_118 ) ;
V_16 = F_106 ( & V_107 -> V_3 , V_70 -> V_6 ,
& V_70 -> V_129 , 0 ) ;
F_94 ( V_16 ) ;
} while ( V_100 && V_70 != V_202 );
V_107 -> V_194 = V_204 ;
return 0 ;
}
static T_5 int
F_153 ( struct V_27 * V_28 ,
struct V_106 * V_107 ,
struct V_57 * V_58 , T_1 V_6 , T_1 V_79 ,
T_1 V_195 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_70 ;
struct V_99 * V_100 ;
int V_16 = - V_200 ;
if ( V_52 -> V_83 == 0 )
return - V_200 ;
F_154 (entry, bitmaps, list) {
if ( V_70 -> V_79 < V_195 )
continue;
V_16 = F_151 ( V_28 , V_70 , V_107 , V_6 ,
V_79 , V_195 ) ;
if ( ! V_16 )
return 0 ;
}
if ( ! F_82 ( V_58 ) ) {
V_70 = F_71 ( V_58 -> V_150 , struct V_71 ,
V_86 ) ;
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_100 )
return - V_200 ;
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
goto V_206;
}
V_70 = F_110 ( V_52 , F_104 ( V_52 , V_6 ) , 0 , 1 ) ;
if ( ! V_70 )
return - V_200 ;
V_206:
V_100 = & V_70 -> V_129 ;
do {
V_70 = F_84 ( V_100 , struct V_71 , V_129 ) ;
V_100 = F_86 ( & V_70 -> V_129 ) ;
if ( ! V_70 -> V_82 )
continue;
if ( V_70 -> V_79 < V_195 )
continue;
V_16 = F_151 ( V_28 , V_70 , V_107 , V_6 ,
V_79 , V_195 ) ;
} while ( V_16 && V_100 );
return V_16 ;
}
int F_155 ( struct V_31 * V_32 ,
struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_106 * V_107 ,
T_1 V_6 , T_1 V_79 , T_1 V_190 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_57 V_58 ;
struct V_71 * V_70 , * V_207 ;
T_1 V_195 ;
int V_16 ;
if ( F_156 ( V_3 , V_208 ) ) {
V_195 = V_79 + V_190 ;
} else if ( V_28 -> V_25 & V_209 ) {
if ( V_32 -> V_210 -> V_211 . V_212 )
V_195 = F_157 ( V_79 , ( V_79 + V_190 ) >> 1 ) ;
else
V_195 = F_157 ( V_79 , ( V_79 + V_190 ) >> 4 ) ;
} else
V_195 = F_157 ( V_79 , ( V_79 + V_190 ) >> 2 ) ;
F_13 ( & V_52 -> V_81 ) ;
if ( V_52 -> V_96 < V_195 ) {
F_15 ( & V_52 -> V_81 ) ;
return - V_200 ;
}
F_13 ( & V_107 -> V_29 ) ;
if ( V_107 -> V_28 ) {
V_16 = 0 ;
goto V_66;
}
F_50 ( & V_58 ) ;
V_16 = F_152 ( V_28 , V_107 , & V_58 , V_6 ,
V_79 , V_195 ) ;
if ( V_16 )
V_16 = F_153 ( V_28 , V_107 , & V_58 ,
V_6 , V_79 , V_195 ) ;
F_158 (entry, tmp, &bitmaps, list)
F_72 ( & V_70 -> V_86 ) ;
if ( ! V_16 ) {
F_148 ( & V_28 -> V_161 ) ;
F_70 ( & V_107 -> V_124 ,
& V_28 -> V_123 ) ;
V_107 -> V_28 = V_28 ;
}
V_66:
F_15 ( & V_107 -> V_29 ) ;
F_15 ( & V_52 -> V_81 ) ;
return V_16 ;
}
void F_159 ( struct V_106 * V_107 )
{
F_138 ( & V_107 -> V_29 ) ;
F_138 ( & V_107 -> V_213 ) ;
V_107 -> V_3 = V_188 ;
V_107 -> V_194 = 0 ;
F_50 ( & V_107 -> V_124 ) ;
V_107 -> V_28 = NULL ;
}
int F_160 ( struct V_27 * V_28 ,
T_1 * V_214 , T_1 V_111 , T_1 V_112 , T_1 V_215 )
{
struct V_51 * V_52 = V_28 -> V_89 ;
struct V_71 * V_70 = NULL ;
struct V_88 * V_22 = V_28 -> V_22 ;
T_1 V_79 = 0 ;
T_1 V_216 ;
int V_16 = 0 ;
* V_214 = 0 ;
while ( V_111 < V_112 ) {
F_13 ( & V_52 -> V_81 ) ;
if ( V_52 -> V_96 < V_215 ) {
F_15 ( & V_52 -> V_81 ) ;
break;
}
V_70 = F_110 ( V_52 , V_111 , 0 , 1 ) ;
if ( ! V_70 )
V_70 = F_110 ( V_52 ,
F_104 ( V_52 , V_111 ) ,
1 , 1 ) ;
if ( ! V_70 || V_70 -> V_6 >= V_112 ) {
F_15 ( & V_52 -> V_81 ) ;
break;
}
if ( V_70 -> V_82 ) {
V_16 = F_121 ( V_52 , V_70 , & V_111 , & V_79 ) ;
if ( ! V_16 ) {
if ( V_111 >= V_112 ) {
F_15 ( & V_52 -> V_81 ) ;
break;
}
V_79 = F_88 ( V_79 , V_112 - V_111 ) ;
F_117 ( V_52 , V_70 , V_111 , V_79 ) ;
if ( V_70 -> V_79 == 0 )
F_127 ( V_52 , V_70 ) ;
} else {
V_111 = V_70 -> V_6 + V_140 *
V_28 -> V_120 ;
F_15 ( & V_52 -> V_81 ) ;
V_16 = 0 ;
continue;
}
} else {
V_111 = V_70 -> V_6 ;
V_79 = F_88 ( V_70 -> V_79 , V_112 - V_111 ) ;
F_114 ( V_52 , V_70 ) ;
F_68 ( V_78 , V_70 ) ;
}
F_15 ( & V_52 -> V_81 ) ;
if ( V_79 >= V_215 ) {
int V_217 ;
V_217 = F_161 ( V_28 ,
V_79 , 1 , 1 ) ;
V_16 = F_162 ( V_22 -> V_218 ,
V_111 ,
V_79 ,
& V_216 ) ;
F_135 ( V_28 , V_111 , V_79 ) ;
if ( ! V_217 )
F_161 ( V_28 ,
V_79 , 0 , 1 ) ;
if ( V_16 )
break;
* V_214 += V_216 ;
}
V_111 += V_79 ;
V_79 = 0 ;
if ( F_163 ( V_219 ) ) {
V_16 = - V_220 ;
break;
}
F_144 () ;
}
return V_16 ;
}
T_1 F_164 ( struct V_2 * V_221 )
{
struct V_51 * V_52 = V_221 -> V_222 ;
struct V_71 * V_70 = NULL ;
T_1 V_33 = 0 ;
F_13 ( & V_52 -> V_81 ) ;
if ( F_165 ( & V_52 -> V_118 ) )
goto V_66;
V_70 = F_84 ( F_79 ( & V_52 -> V_118 ) ,
struct V_71 , V_129 ) ;
if ( ! V_70 -> V_82 ) {
V_33 = V_70 -> V_6 ;
F_114 ( V_52 , V_70 ) ;
V_70 -> V_6 ++ ;
V_70 -> V_79 -- ;
if ( ! V_70 -> V_79 )
F_68 ( V_78 , V_70 ) ;
else
F_69 ( V_52 , V_70 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_161 = 1 ;
int V_16 ;
V_16 = F_121 ( V_52 , V_70 , & V_6 , & V_161 ) ;
F_94 ( V_16 ) ;
V_33 = V_6 ;
F_117 ( V_52 , V_70 , V_6 , 1 ) ;
if ( V_70 -> V_79 == 0 )
F_127 ( V_52 , V_70 ) ;
}
V_66:
F_15 ( & V_52 -> V_81 ) ;
return V_33 ;
}
struct V_1 * F_166 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_13 ( & V_3 -> V_223 ) ;
if ( V_3 -> V_224 )
V_1 = F_14 ( V_3 -> V_224 ) ;
F_15 ( & V_3 -> V_223 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_3 -> V_223 ) ;
if ( ! F_16 ( V_3 -> V_22 ) )
V_3 -> V_224 = F_14 ( V_1 ) ;
F_15 ( & V_3 -> V_223 ) ;
return V_1 ;
}
int F_167 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_4 * V_5 )
{
return F_17 ( V_3 , V_32 , V_5 ,
V_225 , 0 ) ;
}
int F_168 ( struct V_88 * V_22 , struct V_2 * V_3 )
{
struct V_51 * V_52 = V_3 -> V_222 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_226 = F_169 ( & V_3 -> V_227 ) ;
if ( ! F_156 ( V_3 , V_228 ) )
return 0 ;
if ( F_16 ( V_22 ) )
return 0 ;
V_5 = F_76 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_166 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_66;
if ( V_226 != F_54 ( V_1 ) -> V_61 )
goto V_229;
V_16 = F_49 ( V_3 , V_1 , V_52 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_55 ( V_67 L_25
L_26 , V_3 -> V_230 . V_17 ) ;
V_229:
F_11 ( V_1 ) ;
V_66:
F_77 ( V_5 ) ;
return V_16 ;
}
int F_170 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_4 * V_5 )
{
struct V_51 * V_52 = V_3 -> V_222 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_156 ( V_3 , V_228 ) )
return 0 ;
V_1 = F_166 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_78 ( V_3 , V_1 , V_52 , NULL , V_32 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_55 ( V_67 L_27
L_28 , V_3 -> V_230 . V_17 ) ;
F_11 ( V_1 ) ;
return V_16 ;
}
