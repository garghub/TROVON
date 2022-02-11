int
F_1 ( int V_1 , unsigned long V_2 )
{
T_1 V_3 = F_2 () ;
struct V_4 * V_5 ;
int V_6 ;
struct V_7 * V_8 ;
V_6 = F_3 ( V_9 , V_10 , 0 , & V_5 ) ;
if ( V_6 != 0 ) {
F_4 ( L_1 , V_6 ) ;
return V_6 ;
}
V_8 = F_5 ( V_5 , 0 , NULL ) ;
if ( F_6 ( V_8 ) ) {
F_7 ( V_5 ) ;
V_6 = F_8 ( V_8 ) ;
goto V_11;
}
F_9 ( V_12 ) ;
if ( V_8 -> V_13 -> V_14 )
V_6 = V_8 -> V_13 -> V_14 ( V_8 , V_1 , V_2 ) ;
F_9 ( V_3 ) ;
F_10 ( V_8 ) ;
V_11:
return V_6 ;
}
int
F_11 ( char * V_15 , int * V_16 , T_2 * V_17 , T_2 * V_18 )
{
struct V_19 V_20 ;
int V_21 ;
int V_6 ;
T_2 V_22 ;
V_21 = F_12 ( V_15 , V_23 ) ;
if ( V_21 == V_23 ) {
F_4 ( L_2 , V_15 ) ;
return - V_24 ;
}
F_13 ( sizeof( V_20 . V_25 ) >= V_23 ) ;
strcpy ( V_20 . V_25 , V_15 ) ;
V_6 = F_1 ( V_26 , ( unsigned long ) & V_20 ) ;
if ( V_6 != 0 ) {
F_4 ( L_3 , V_15 ) ;
return V_6 ;
}
if ( ( V_20 . V_27 & V_28 ) == 0 ) {
F_14 ( V_29 , L_4 , V_15 ) ;
* V_16 = 0 ;
* V_17 = * V_18 = 0 ;
return 0 ;
}
* V_16 = 1 ;
strcpy ( V_20 . V_25 , V_15 ) ;
V_20 . V_30 . V_31 = V_32 ;
V_6 = F_1 ( V_33 , ( unsigned long ) & V_20 ) ;
if ( V_6 != 0 ) {
F_4 ( L_5 , V_15 ) ;
return V_6 ;
}
V_22 = ( (struct V_34 * ) & V_20 . V_30 ) -> V_35 . V_36 ;
* V_17 = F_15 ( V_22 ) ;
strcpy ( V_20 . V_25 , V_15 ) ;
V_20 . V_30 . V_31 = V_32 ;
V_6 = F_1 ( V_37 , ( unsigned long ) & V_20 ) ;
if ( V_6 != 0 ) {
F_4 ( L_6 , V_15 ) ;
return V_6 ;
}
V_22 = ( (struct V_34 * ) & V_20 . V_38 ) -> V_35 . V_36 ;
* V_18 = F_15 ( V_22 ) ;
return 0 ;
}
int
F_16 ( char * * * V_39 )
{
char * * V_40 ;
int V_41 ;
int V_42 ;
int V_43 ;
struct V_19 * V_20 ;
struct V_44 V_45 ;
int V_6 ;
int V_21 ;
int V_46 ;
V_42 = 16 ;
V_41 = 0 ;
for (; ; ) {
if ( V_42 * sizeof( * V_20 ) > V_47 ) {
V_41 = 1 ;
V_42 = V_47 / sizeof( * V_20 ) ;
F_17 ( L_7 ,
V_42 ) ;
}
F_18 ( V_20 , V_42 * sizeof( * V_20 ) ) ;
if ( V_20 == NULL ) {
F_4 ( L_8 , V_42 ) ;
V_6 = - V_48 ;
goto V_49;
}
V_45 . V_50 = ( char * ) V_20 ;
V_45 . V_51 = V_42 * sizeof( * V_20 ) ;
V_6 = F_1 ( V_52 , ( unsigned long ) & V_45 ) ;
if ( V_6 < 0 ) {
F_4 ( L_9 , V_6 ) ;
goto V_53;
}
F_19 ( V_6 == 0 ) ;
V_43 = V_45 . V_51 / sizeof( * V_20 ) ;
F_19 ( V_43 <= V_42 ) ;
if ( V_43 < V_42 || V_41 )
break;
F_20 ( V_20 , V_42 * sizeof( * V_20 ) ) ;
V_42 *= 2 ;
}
if ( V_43 == 0 )
goto V_53;
F_18 ( V_40 , V_43 * sizeof( * V_40 ) ) ;
if ( V_40 == NULL ) {
V_6 = - V_48 ;
goto V_53;
}
memset ( V_40 , 0 , V_43 * sizeof( * V_40 ) ) ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 ++ ) {
V_21 = F_12 ( V_20 [ V_46 ] . V_25 , V_23 ) ;
if ( V_21 == V_23 ) {
F_4 ( L_10 ,
V_21 , V_20 [ V_46 ] . V_25 , V_23 ) ;
V_6 = - V_54 ;
goto V_55;
}
F_18 ( V_40 [ V_46 ] , V_23 ) ;
if ( V_40 [ V_46 ] == NULL ) {
V_6 = - V_48 ;
goto V_55;
}
memcpy ( V_40 [ V_46 ] , V_20 [ V_46 ] . V_25 , V_21 ) ;
V_40 [ V_46 ] [ V_21 ] = 0 ;
}
* V_39 = V_40 ;
V_6 = V_43 ;
V_55:
if ( V_6 < 0 )
F_21 ( V_40 , V_43 ) ;
V_53:
F_20 ( V_20 , V_42 * sizeof( * V_20 ) ) ;
V_49:
return V_6 ;
}
void
F_21 ( char * * V_40 , int V_56 )
{
int V_46 ;
F_19 ( V_56 > 0 ) ;
for ( V_46 = 0 ; V_46 < V_56 && V_40 [ V_46 ] != NULL ; V_46 ++ )
F_20 ( V_40 [ V_46 ] , V_23 ) ;
F_20 ( V_40 , V_56 * sizeof( * V_40 ) ) ;
}
int
F_22 ( struct V_4 * V_5 , void * V_57 , int V_21 , int V_58 )
{
int V_6 ;
T_1 V_3 = F_2 () ;
long V_59 = V_58 * V_60 ;
unsigned long V_61 ;
struct V_62 V_63 ;
F_19 ( V_21 > 0 ) ;
for (; ; ) {
struct V_64 V_65 = {
. V_66 = V_57 ,
. V_67 = V_21
} ;
struct V_68 V_69 = {
. V_70 = NULL ,
. V_71 = 0 ,
. V_72 = & V_65 ,
. V_73 = 1 ,
. V_74 = NULL ,
. V_75 = 0 ,
. V_76 = ( V_58 == 0 ) ? V_77 : 0
} ;
if ( V_58 != 0 ) {
V_63 = (struct V_62 ) {
. V_78 = V_59 / V_60 ,
. V_79 = ( ( V_59 % V_60 ) * 1000000 ) / V_60
} ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_80 , V_81 ,
( char * ) & V_63 , sizeof( V_63 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_11
L_12 ,
( long ) V_63 . V_78 , ( int ) V_63 . V_79 , V_6 ) ;
return V_6 ;
}
}
F_9 ( V_12 ) ;
V_61 = V_82 ;
V_6 = F_24 ( V_5 , & V_69 , V_65 . V_67 ) ;
V_59 -= V_82 - V_61 ;
F_9 ( V_3 ) ;
if ( V_6 == V_21 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == 0 ) {
F_4 ( L_13 ) ;
return ( - V_83 ) ;
}
if ( V_59 <= 0 )
return - V_84 ;
V_57 = ( ( char * ) V_57 ) + V_6 ;
V_21 -= V_6 ;
}
return ( 0 ) ;
}
int
F_25 ( struct V_4 * V_5 , void * V_57 , int V_21 , int V_58 )
{
int V_6 ;
T_1 V_3 = F_2 () ;
long V_59 = V_58 * V_60 ;
unsigned long V_61 ;
struct V_62 V_63 ;
F_19 ( V_21 > 0 ) ;
F_19 ( V_59 > 0 ) ;
for (; ; ) {
struct V_64 V_65 = {
. V_66 = V_57 ,
. V_67 = V_21
} ;
struct V_68 V_69 = {
. V_70 = NULL ,
. V_71 = 0 ,
. V_72 = & V_65 ,
. V_73 = 1 ,
. V_74 = NULL ,
. V_75 = 0 ,
. V_76 = 0
} ;
V_63 = (struct V_62 ) {
. V_78 = V_59 / V_60 ,
. V_79 = ( ( V_59 % V_60 ) * 1000000 ) / V_60
} ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_80 , V_85 ,
( char * ) & V_63 , sizeof( V_63 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_14 ,
( long ) V_63 . V_78 , ( int ) V_63 . V_79 , V_6 ) ;
return V_6 ;
}
F_9 ( V_12 ) ;
V_61 = V_82 ;
V_6 = F_26 ( V_5 , & V_69 , V_65 . V_67 , 0 ) ;
V_59 -= V_82 - V_61 ;
F_9 ( V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == 0 )
return - V_86 ;
V_57 = ( ( char * ) V_57 ) + V_6 ;
V_21 -= V_6 ;
if ( V_21 == 0 )
return 0 ;
if ( V_59 <= 0 )
return - V_87 ;
}
}
static int
F_27 ( struct V_4 * * V_88 , int * V_89 ,
T_2 V_90 , int V_91 )
{
struct V_34 V_92 ;
struct V_4 * V_5 ;
int V_6 ;
int V_93 ;
T_1 V_3 = F_2 () ;
* V_89 = 1 ;
V_6 = F_3 ( V_9 , V_10 , 0 , & V_5 ) ;
* V_88 = V_5 ;
if ( V_6 != 0 ) {
F_4 ( L_1 , V_6 ) ;
return ( V_6 ) ;
}
F_9 ( V_12 ) ;
V_93 = 1 ;
V_6 = F_23 ( V_5 , V_80 , V_94 ,
( char * ) & V_93 , sizeof ( V_93 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_15 , V_6 ) ;
goto V_95;
}
if ( V_90 != 0 || V_91 != 0 ) {
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_96 = V_32 ;
V_92 . V_97 = F_28 ( V_91 ) ;
V_92 . V_35 . V_36 = ( V_90 == 0 ) ?
V_98 : F_29 ( V_90 ) ;
V_6 = V_5 -> V_99 -> V_100 ( V_5 , (struct V_101 * ) & V_92 ,
sizeof( V_92 ) ) ;
if ( V_6 == - V_102 ) {
F_14 ( V_29 , L_16 , V_91 ) ;
* V_89 = 0 ;
goto V_95;
}
if ( V_6 != 0 ) {
F_4 ( L_17 ,
V_91 , V_6 ) ;
goto V_95;
}
}
return 0 ;
V_95:
F_7 ( V_5 ) ;
return V_6 ;
}
int
F_30 ( struct V_4 * V_5 , int V_103 , int V_104 )
{
T_1 V_3 = F_2 () ;
int V_93 ;
int V_6 ;
if ( V_103 != 0 ) {
V_93 = V_103 ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_80 , V_105 ,
( char * ) & V_93 , sizeof ( V_93 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_18 ,
V_93 , V_6 ) ;
return ( V_6 ) ;
}
}
if ( V_104 != 0 ) {
V_93 = V_104 ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_80 , V_106 ,
( char * ) & V_93 , sizeof ( V_93 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_19 ,
V_93 , V_6 ) ;
return ( V_6 ) ;
}
}
return 0 ;
}
int
F_31 ( struct V_4 * V_5 , int V_107 , T_2 * V_17 , int * V_108 )
{
struct V_34 sin ;
int V_109 = sizeof ( sin ) ;
int V_6 ;
V_6 = V_5 -> V_99 -> V_110 ( V_5 , (struct V_101 * ) & sin , & V_109 ,
V_107 ? 2 : 0 ) ;
if ( V_6 != 0 ) {
F_4 ( L_20 ,
V_6 , V_107 ? L_21 : L_22 ) ;
return V_6 ;
}
if ( V_17 != NULL )
* V_17 = F_15 ( sin . V_35 . V_36 ) ;
if ( V_108 != NULL )
* V_108 = F_32 ( sin . V_97 ) ;
return 0 ;
}
int
F_33 ( struct V_4 * V_5 , int * V_103 , int * V_104 )
{
if ( V_103 != NULL ) {
* V_103 = V_5 -> V_111 -> V_112 ;
}
if ( V_104 != NULL ) {
* V_104 = V_5 -> V_111 -> V_113 ;
}
return 0 ;
}
int
F_34 ( struct V_4 * * V_88 ,
T_2 V_90 , int V_91 , int V_114 )
{
int V_89 ;
int V_6 ;
V_6 = F_27 ( V_88 , & V_89 , V_90 , V_91 ) ;
if ( V_6 != 0 ) {
if ( ! V_89 )
F_4 ( L_23 ,
V_91 ) ;
return V_6 ;
}
V_6 = ( * V_88 ) -> V_99 -> V_115 ( * V_88 , V_114 ) ;
if ( V_6 == 0 )
return 0 ;
F_4 ( L_24 , V_114 , V_6 ) ;
F_7 ( * V_88 ) ;
return V_6 ;
}
int
F_35 ( struct V_4 * * V_116 , struct V_4 * V_5 )
{
T_3 V_117 ;
struct V_4 * V_118 ;
int V_6 ;
F_36 ( & V_117 , V_119 ) ;
V_6 = F_37 ( V_120 , V_5 -> type , V_121 , & V_118 ) ;
if ( V_6 ) {
F_4 ( L_25 ) ;
return V_6 ;
}
V_118 -> V_99 = V_5 -> V_99 ;
F_38 ( V_122 ) ;
F_39 ( F_40 ( V_5 -> V_111 ) , & V_117 ) ;
V_6 = V_5 -> V_99 -> V_123 ( V_5 , V_118 , V_124 ) ;
if ( V_6 == - V_84 ) {
F_41 () ;
V_6 = V_5 -> V_99 -> V_123 ( V_5 , V_118 , V_124 ) ;
}
F_42 ( F_40 ( V_5 -> V_111 ) , & V_117 ) ;
F_38 ( V_125 ) ;
if ( V_6 != 0 )
goto V_95;
* V_116 = V_118 ;
return 0 ;
V_95:
F_7 ( V_118 ) ;
return V_6 ;
}
void
F_43 ( struct V_4 * V_5 )
{
F_44 ( F_40 ( V_5 -> V_111 ) ) ;
}
int
F_45 ( struct V_4 * * V_88 , int * V_89 ,
T_2 V_90 , int V_91 ,
T_2 V_126 , int V_127 )
{
struct V_34 V_128 ;
int V_6 ;
V_6 = F_27 ( V_88 , V_89 , V_90 , V_91 ) ;
if ( V_6 != 0 )
return V_6 ;
memset ( & V_128 , 0 , sizeof ( V_128 ) ) ;
V_128 . V_96 = V_32 ;
V_128 . V_97 = F_28 ( V_127 ) ;
V_128 . V_35 . V_36 = F_29 ( V_126 ) ;
V_6 = ( * V_88 ) -> V_99 -> V_129 ( * V_88 ,
(struct V_101 * ) & V_128 , sizeof( V_128 ) ,
0 ) ;
if ( V_6 == 0 )
return 0 ;
* V_89 = ! ( V_6 == - V_130 ) ;
F_46 ( * V_89 ? V_131 : V_29 ,
L_26 , V_6 ,
F_47 ( V_90 ) , V_91 , F_47 ( V_126 ) , V_127 ) ;
F_7 ( * V_88 ) ;
return V_6 ;
}
void
F_48 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
