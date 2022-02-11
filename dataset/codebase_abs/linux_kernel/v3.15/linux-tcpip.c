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
. V_70 = ( V_58 == 0 ) ? V_71 : 0
} ;
if ( V_58 != 0 ) {
V_63 = (struct V_62 ) {
. V_72 = V_59 / V_60 ,
. V_73 = ( ( V_59 % V_60 ) * 1000000 ) / V_60
} ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_74 , V_75 ,
( char * ) & V_63 , sizeof( V_63 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_11
L_12 ,
( long ) V_63 . V_72 , ( int ) V_63 . V_73 , V_6 ) ;
return V_6 ;
}
}
V_61 = V_76 ;
V_6 = F_24 ( V_5 , & V_69 , & V_65 , 1 , V_21 ) ;
V_59 -= V_76 - V_61 ;
if ( V_6 == V_21 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == 0 ) {
F_4 ( L_13 ) ;
return ( - V_77 ) ;
}
if ( V_59 <= 0 )
return - V_78 ;
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
. V_70 = 0
} ;
V_63 = (struct V_62 ) {
. V_72 = V_59 / V_60 ,
. V_73 = ( ( V_59 % V_60 ) * 1000000 ) / V_60
} ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_74 , V_79 ,
( char * ) & V_63 , sizeof( V_63 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_14 ,
( long ) V_63 . V_72 , ( int ) V_63 . V_73 , V_6 ) ;
return V_6 ;
}
V_61 = V_76 ;
V_6 = F_26 ( V_5 , & V_69 , & V_65 , 1 , V_21 , 0 ) ;
V_59 -= V_76 - V_61 ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == 0 )
return - V_80 ;
V_57 = ( ( char * ) V_57 ) + V_6 ;
V_21 -= V_6 ;
if ( V_21 == 0 )
return 0 ;
if ( V_59 <= 0 )
return - V_81 ;
}
}
static int
F_27 ( struct V_4 * * V_82 , int * V_83 ,
T_2 V_84 , int V_85 )
{
struct V_34 V_86 ;
struct V_4 * V_5 ;
int V_6 ;
int V_87 ;
T_1 V_3 = F_2 () ;
* V_83 = 1 ;
V_6 = F_3 ( V_9 , V_10 , 0 , & V_5 ) ;
* V_82 = V_5 ;
if ( V_6 != 0 ) {
F_4 ( L_1 , V_6 ) ;
return ( V_6 ) ;
}
F_9 ( V_12 ) ;
V_87 = 1 ;
V_6 = F_23 ( V_5 , V_74 , V_88 ,
( char * ) & V_87 , sizeof ( V_87 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_15 , V_6 ) ;
goto V_89;
}
if ( V_84 != 0 || V_85 != 0 ) {
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_90 = V_32 ;
V_86 . V_91 = F_28 ( V_85 ) ;
V_86 . V_35 . V_36 = ( V_84 == 0 ) ?
V_92 : F_29 ( V_84 ) ;
V_6 = V_5 -> V_93 -> V_94 ( V_5 , (struct V_95 * ) & V_86 ,
sizeof( V_86 ) ) ;
if ( V_6 == - V_96 ) {
F_14 ( V_29 , L_16 , V_85 ) ;
* V_83 = 0 ;
goto V_89;
}
if ( V_6 != 0 ) {
F_4 ( L_17 ,
V_85 , V_6 ) ;
goto V_89;
}
}
return 0 ;
V_89:
F_7 ( V_5 ) ;
return V_6 ;
}
int
F_30 ( struct V_4 * V_5 , int V_97 , int V_98 )
{
T_1 V_3 = F_2 () ;
int V_87 ;
int V_6 ;
if ( V_97 != 0 ) {
V_87 = V_97 ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_74 , V_99 ,
( char * ) & V_87 , sizeof ( V_87 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_18 ,
V_87 , V_6 ) ;
return ( V_6 ) ;
}
}
if ( V_98 != 0 ) {
V_87 = V_98 ;
F_9 ( V_12 ) ;
V_6 = F_23 ( V_5 , V_74 , V_100 ,
( char * ) & V_87 , sizeof ( V_87 ) ) ;
F_9 ( V_3 ) ;
if ( V_6 != 0 ) {
F_4 ( L_19 ,
V_87 , V_6 ) ;
return ( V_6 ) ;
}
}
return 0 ;
}
int
F_31 ( struct V_4 * V_5 , int V_101 , T_2 * V_17 , int * V_102 )
{
struct V_34 sin ;
int V_103 = sizeof ( sin ) ;
int V_6 ;
V_6 = V_5 -> V_93 -> V_104 ( V_5 , (struct V_95 * ) & sin , & V_103 ,
V_101 ? 2 : 0 ) ;
if ( V_6 != 0 ) {
F_4 ( L_20 ,
V_6 , V_101 ? L_21 : L_22 ) ;
return V_6 ;
}
if ( V_17 != NULL )
* V_17 = F_15 ( sin . V_35 . V_36 ) ;
if ( V_102 != NULL )
* V_102 = F_32 ( sin . V_91 ) ;
return 0 ;
}
int
F_33 ( struct V_4 * V_5 , int * V_97 , int * V_98 )
{
if ( V_97 != NULL ) {
* V_97 = V_5 -> V_105 -> V_106 ;
}
if ( V_98 != NULL ) {
* V_98 = V_5 -> V_105 -> V_107 ;
}
return 0 ;
}
int
F_34 ( struct V_4 * * V_82 ,
T_2 V_84 , int V_85 , int V_108 )
{
int V_83 ;
int V_6 ;
V_6 = F_27 ( V_82 , & V_83 , V_84 , V_85 ) ;
if ( V_6 != 0 ) {
if ( ! V_83 )
F_4 ( L_23 ,
V_85 ) ;
return V_6 ;
}
V_6 = ( * V_82 ) -> V_93 -> V_109 ( * V_82 , V_108 ) ;
if ( V_6 == 0 )
return 0 ;
F_4 ( L_24 , V_108 , V_6 ) ;
F_7 ( * V_82 ) ;
return V_6 ;
}
int
F_35 ( struct V_4 * * V_110 , struct V_4 * V_5 )
{
T_3 V_111 ;
struct V_4 * V_112 ;
int V_6 ;
F_36 ( & V_111 , V_113 ) ;
V_6 = F_37 ( V_114 , V_5 -> type , V_115 , & V_112 ) ;
if ( V_6 ) {
F_4 ( L_25 ) ;
return V_6 ;
}
V_112 -> V_93 = V_5 -> V_93 ;
F_38 ( V_116 ) ;
F_39 ( F_40 ( V_5 -> V_105 ) , & V_111 ) ;
V_6 = V_5 -> V_93 -> V_117 ( V_5 , V_112 , V_118 ) ;
if ( V_6 == - V_78 ) {
F_41 () ;
V_6 = V_5 -> V_93 -> V_117 ( V_5 , V_112 , V_118 ) ;
}
F_42 ( F_40 ( V_5 -> V_105 ) , & V_111 ) ;
F_38 ( V_119 ) ;
if ( V_6 != 0 )
goto V_89;
* V_110 = V_112 ;
return 0 ;
V_89:
F_7 ( V_112 ) ;
return V_6 ;
}
void
F_43 ( struct V_4 * V_5 )
{
F_44 ( F_40 ( V_5 -> V_105 ) ) ;
}
int
F_45 ( struct V_4 * * V_82 , int * V_83 ,
T_2 V_84 , int V_85 ,
T_2 V_120 , int V_121 )
{
struct V_34 V_122 ;
int V_6 ;
V_6 = F_27 ( V_82 , V_83 , V_84 , V_85 ) ;
if ( V_6 != 0 )
return V_6 ;
memset ( & V_122 , 0 , sizeof ( V_122 ) ) ;
V_122 . V_90 = V_32 ;
V_122 . V_91 = F_28 ( V_121 ) ;
V_122 . V_35 . V_36 = F_29 ( V_120 ) ;
V_6 = ( * V_82 ) -> V_93 -> V_123 ( * V_82 ,
(struct V_95 * ) & V_122 , sizeof( V_122 ) ,
0 ) ;
if ( V_6 == 0 )
return 0 ;
* V_83 = ! ( V_6 == - V_124 ) ;
F_46 ( * V_83 ? V_125 : V_29 ,
L_26 , V_6 ,
& V_84 , V_85 , & V_120 , V_121 ) ;
F_7 ( * V_82 ) ;
return V_6 ;
}
void
F_47 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
}
