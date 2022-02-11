static int
F_1 ( struct V_1 * V_2 , int V_3 , unsigned long V_4 )
{
T_1 V_5 = F_2 () ;
int V_6 ;
F_3 ( V_7 ) ;
V_6 = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 ) ;
F_3 ( V_5 ) ;
return V_6 ;
}
static int
F_4 ( int V_3 , unsigned long V_4 )
{
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_5 ( V_14 , V_15 , 0 , & V_12 ) ;
if ( V_13 != 0 ) {
F_6 ( L_1 , V_13 ) ;
return V_13 ;
}
V_10 = F_7 ( V_12 , 0 , NULL ) ;
if ( F_8 ( V_10 ) ) {
F_9 ( V_12 ) ;
V_13 = F_10 ( V_10 ) ;
goto V_16;
}
V_13 = F_1 ( V_10 , V_3 , V_4 ) ;
F_11 ( V_10 ) ;
V_16:
return V_13 ;
}
int
F_12 ( char * V_17 , int * V_18 , T_2 * V_19 , T_2 * V_20 )
{
struct V_21 V_22 ;
int V_23 ;
int V_13 ;
T_2 V_24 ;
V_23 = F_13 ( V_17 , V_25 ) ;
if ( V_23 == V_25 ) {
F_6 ( L_2 , V_17 ) ;
return - V_26 ;
}
F_14 ( sizeof( V_22 . V_27 ) >= V_25 ) ;
strcpy ( V_22 . V_27 , V_17 ) ;
V_13 = F_4 ( V_28 , ( unsigned long ) & V_22 ) ;
if ( V_13 != 0 ) {
F_6 ( L_3 , V_17 ) ;
return V_13 ;
}
if ( ( V_22 . V_29 & V_30 ) == 0 ) {
F_15 ( V_31 , L_4 , V_17 ) ;
* V_18 = 0 ;
* V_19 = * V_20 = 0 ;
return 0 ;
}
* V_18 = 1 ;
strcpy ( V_22 . V_27 , V_17 ) ;
V_22 . V_32 . V_33 = V_34 ;
V_13 = F_4 ( V_35 , ( unsigned long ) & V_22 ) ;
if ( V_13 != 0 ) {
F_6 ( L_5 , V_17 ) ;
return V_13 ;
}
V_24 = ( (struct V_36 * ) & V_22 . V_32 ) -> V_37 . V_38 ;
* V_19 = F_16 ( V_24 ) ;
strcpy ( V_22 . V_27 , V_17 ) ;
V_22 . V_32 . V_33 = V_34 ;
V_13 = F_4 ( V_39 , ( unsigned long ) & V_22 ) ;
if ( V_13 != 0 ) {
F_6 ( L_6 , V_17 ) ;
return V_13 ;
}
V_24 = ( (struct V_36 * ) & V_22 . V_40 ) -> V_37 . V_38 ;
* V_20 = F_16 ( V_24 ) ;
return 0 ;
}
int
F_17 ( char * * * V_41 )
{
char * * V_42 ;
int V_43 ;
int V_44 ;
int V_45 ;
struct V_21 * V_22 ;
struct V_46 V_47 ;
int V_13 ;
int V_23 ;
int V_48 ;
V_44 = 16 ;
V_43 = 0 ;
for (; ; ) {
if ( V_44 * sizeof( * V_22 ) > V_49 ) {
V_43 = 1 ;
V_44 = V_49 / sizeof( * V_22 ) ;
F_18 ( L_7 ,
V_44 ) ;
}
F_19 ( V_22 , V_44 * sizeof( * V_22 ) ) ;
if ( V_22 == NULL ) {
F_6 ( L_8 ,
V_44 ) ;
V_13 = - V_50 ;
goto V_51;
}
V_47 . V_52 = ( char * ) V_22 ;
V_47 . V_53 = V_44 * sizeof( * V_22 ) ;
V_13 = F_4 ( V_54 , ( unsigned long ) & V_47 ) ;
if ( V_13 < 0 ) {
F_6 ( L_9 , V_13 ) ;
goto V_55;
}
F_20 ( V_13 == 0 ) ;
V_45 = V_47 . V_53 / sizeof( * V_22 ) ;
F_20 ( V_45 <= V_44 ) ;
if ( V_45 < V_44 || V_43 )
break;
F_21 ( V_22 , V_44 * sizeof( * V_22 ) ) ;
V_44 *= 2 ;
}
if ( V_45 == 0 )
goto V_55;
F_19 ( V_42 , V_45 * sizeof( * V_42 ) ) ;
if ( V_42 == NULL ) {
V_13 = - V_50 ;
goto V_55;
}
for ( V_48 = 0 ; V_48 < V_45 ; V_48 ++ ) {
V_23 = F_13 ( V_22 [ V_48 ] . V_27 , V_25 ) ;
if ( V_23 == V_25 ) {
F_6 ( L_10 ,
V_23 , V_22 [ V_48 ] . V_27 , V_25 ) ;
V_13 = - V_56 ;
goto V_57;
}
F_19 ( V_42 [ V_48 ] , V_25 ) ;
if ( V_42 [ V_48 ] == NULL ) {
V_13 = - V_50 ;
goto V_57;
}
memcpy ( V_42 [ V_48 ] , V_22 [ V_48 ] . V_27 , V_23 ) ;
V_42 [ V_48 ] [ V_23 ] = 0 ;
}
* V_41 = V_42 ;
V_13 = V_45 ;
V_57:
if ( V_13 < 0 )
F_22 ( V_42 , V_45 ) ;
V_55:
F_21 ( V_22 , V_44 * sizeof( * V_22 ) ) ;
V_51:
return V_13 ;
}
void
F_22 ( char * * V_42 , int V_58 )
{
int V_48 ;
F_20 ( V_58 > 0 ) ;
for ( V_48 = 0 ; V_48 < V_58 && V_42 [ V_48 ] != NULL ; V_48 ++ )
F_21 ( V_42 [ V_48 ] , V_25 ) ;
F_21 ( V_42 , V_58 * sizeof( * V_42 ) ) ;
}
int
F_23 ( struct V_11 * V_12 , void * V_59 , int V_23 , int V_60 )
{
int V_13 ;
long V_61 = V_60 * V_62 ;
unsigned long V_63 ;
struct V_64 V_65 ;
F_20 ( V_23 > 0 ) ;
for (; ; ) {
struct V_66 V_67 = {
. V_68 = V_59 ,
. V_69 = V_23
} ;
struct V_70 V_71 = {
. V_72 = ( V_60 == 0 ) ? V_73 : 0
} ;
if ( V_60 != 0 ) {
V_65 = (struct V_64 ) {
. V_74 = V_61 / V_62 ,
. V_75 = ( ( V_61 % V_62 ) * 1000000 ) / V_62
} ;
V_13 = F_24 ( V_12 , V_76 , V_77 ,
( char * ) & V_65 , sizeof( V_65 ) ) ;
if ( V_13 != 0 ) {
F_6 ( L_11 ,
( long ) V_65 . V_74 , ( int ) V_65 . V_75 , V_13 ) ;
return V_13 ;
}
}
V_63 = V_78 ;
V_13 = F_25 ( V_12 , & V_71 , & V_67 , 1 , V_23 ) ;
V_61 -= V_78 - V_63 ;
if ( V_13 == V_23 )
return 0 ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 ) {
F_6 ( L_12 ) ;
return - V_79 ;
}
if ( V_61 <= 0 )
return - V_80 ;
V_59 = ( ( char * ) V_59 ) + V_13 ;
V_23 -= V_13 ;
}
return 0 ;
}
int
F_26 ( struct V_11 * V_12 , void * V_59 , int V_23 , int V_60 )
{
int V_13 ;
long V_61 = V_60 * V_62 ;
unsigned long V_63 ;
struct V_64 V_65 ;
F_20 ( V_23 > 0 ) ;
F_20 ( V_61 > 0 ) ;
for (; ; ) {
struct V_66 V_67 = {
. V_68 = V_59 ,
. V_69 = V_23
} ;
struct V_70 V_71 = {
. V_72 = 0
} ;
V_65 = (struct V_64 ) {
. V_74 = V_61 / V_62 ,
. V_75 = ( ( V_61 % V_62 ) * 1000000 ) / V_62
} ;
V_13 = F_24 ( V_12 , V_76 , V_81 ,
( char * ) & V_65 , sizeof( V_65 ) ) ;
if ( V_13 != 0 ) {
F_6 ( L_13 ,
( long ) V_65 . V_74 , ( int ) V_65 . V_75 , V_13 ) ;
return V_13 ;
}
V_63 = V_78 ;
V_13 = F_27 ( V_12 , & V_71 , & V_67 , 1 , V_23 , 0 ) ;
V_61 -= V_78 - V_63 ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
return - V_82 ;
V_59 = ( ( char * ) V_59 ) + V_13 ;
V_23 -= V_13 ;
if ( V_23 == 0 )
return 0 ;
if ( V_61 <= 0 )
return - V_83 ;
}
}
static int
F_28 ( struct V_11 * * V_84 , int * V_85 , T_2 V_86 ,
int V_87 )
{
struct V_36 V_88 ;
struct V_11 * V_12 ;
int V_13 ;
int V_89 ;
* V_85 = 1 ;
V_13 = F_5 ( V_14 , V_15 , 0 , & V_12 ) ;
* V_84 = V_12 ;
if ( V_13 != 0 ) {
F_6 ( L_1 , V_13 ) ;
return V_13 ;
}
V_89 = 1 ;
V_13 = F_24 ( V_12 , V_76 , V_90 ,
( char * ) & V_89 , sizeof( V_89 ) ) ;
if ( V_13 != 0 ) {
F_6 ( L_14 , V_13 ) ;
goto V_91;
}
if ( V_86 != 0 || V_87 != 0 ) {
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_92 = V_34 ;
V_88 . V_93 = F_29 ( V_87 ) ;
V_88 . V_37 . V_38 = ( V_86 == 0 ) ?
V_94 : F_30 ( V_86 ) ;
V_13 = F_31 ( V_12 , (struct V_95 * ) & V_88 ,
sizeof( V_88 ) ) ;
if ( V_13 == - V_96 ) {
F_15 ( V_31 , L_15 , V_87 ) ;
* V_85 = 0 ;
goto V_91;
}
if ( V_13 != 0 ) {
F_6 ( L_16 ,
V_87 , V_13 ) ;
goto V_91;
}
}
return 0 ;
V_91:
F_9 ( V_12 ) ;
return V_13 ;
}
int
F_32 ( struct V_11 * V_12 , int V_97 , int V_98 )
{
int V_89 ;
int V_13 ;
if ( V_97 != 0 ) {
V_89 = V_97 ;
V_13 = F_24 ( V_12 , V_76 , V_99 ,
( char * ) & V_89 , sizeof( V_89 ) ) ;
if ( V_13 != 0 ) {
F_6 ( L_17 ,
V_89 , V_13 ) ;
return V_13 ;
}
}
if ( V_98 != 0 ) {
V_89 = V_98 ;
V_13 = F_24 ( V_12 , V_76 , V_100 ,
( char * ) & V_89 , sizeof( V_89 ) ) ;
if ( V_13 != 0 ) {
F_6 ( L_18 ,
V_89 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
int
F_33 ( struct V_11 * V_12 , bool V_101 , T_2 * V_19 , int * V_102 )
{
struct V_36 sin ;
int V_103 = sizeof( sin ) ;
int V_13 ;
if ( V_101 )
V_13 = F_34 ( V_12 , (struct V_95 * ) & sin , & V_103 ) ;
else
V_13 = F_35 ( V_12 , (struct V_95 * ) & sin , & V_103 ) ;
if ( V_13 != 0 ) {
F_6 ( L_19 ,
V_13 , V_101 ? L_20 : L_21 ) ;
return V_13 ;
}
if ( V_19 != NULL )
* V_19 = F_16 ( sin . V_37 . V_38 ) ;
if ( V_102 != NULL )
* V_102 = F_36 ( sin . V_93 ) ;
return 0 ;
}
int
F_37 ( struct V_11 * V_12 , int * V_97 , int * V_98 )
{
if ( V_97 != NULL )
* V_97 = V_12 -> V_104 -> V_105 ;
if ( V_98 != NULL )
* V_98 = V_12 -> V_104 -> V_106 ;
return 0 ;
}
int
F_38 ( struct V_11 * * V_84 , T_2 V_86 , int V_87 ,
int V_107 )
{
int V_85 ;
int V_13 ;
V_13 = F_28 ( V_84 , & V_85 , V_86 , V_87 ) ;
if ( V_13 != 0 ) {
if ( ! V_85 )
F_6 ( L_22 ,
V_87 ) ;
return V_13 ;
}
V_13 = F_39 ( * V_84 , V_107 ) ;
if ( V_13 == 0 )
return 0 ;
F_6 ( L_23 , V_107 , V_13 ) ;
F_9 ( * V_84 ) ;
return V_13 ;
}
int
F_40 ( struct V_11 * * V_108 , struct V_11 * V_12 )
{
T_3 V_109 ;
struct V_11 * V_110 ;
int V_13 ;
F_41 ( & V_109 , V_111 ) ;
V_13 = F_42 ( V_112 , V_12 -> type , V_113 , & V_110 ) ;
if ( V_13 ) {
F_6 ( L_24 ) ;
return V_13 ;
}
V_110 -> V_114 = V_12 -> V_114 ;
V_13 = V_12 -> V_114 -> V_115 ( V_12 , V_110 , V_116 ) ;
if ( V_13 == - V_80 ) {
F_43 ( V_117 ) ;
F_44 ( F_45 ( V_12 -> V_104 ) , & V_109 ) ;
F_46 () ;
F_47 ( F_45 ( V_12 -> V_104 ) , & V_109 ) ;
F_43 ( V_118 ) ;
V_13 = V_12 -> V_114 -> V_115 ( V_12 , V_110 , V_116 ) ;
}
if ( V_13 != 0 )
goto V_91;
* V_108 = V_110 ;
return 0 ;
V_91:
F_9 ( V_110 ) ;
return V_13 ;
}
int
F_48 ( struct V_11 * * V_84 , int * V_85 , T_2 V_86 ,
int V_87 , T_2 V_119 , int V_120 )
{
struct V_36 V_121 ;
int V_13 ;
V_13 = F_28 ( V_84 , V_85 , V_86 , V_87 ) ;
if ( V_13 != 0 )
return V_13 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_92 = V_34 ;
V_121 . V_93 = F_29 ( V_120 ) ;
V_121 . V_37 . V_38 = F_30 ( V_119 ) ;
V_13 = F_49 ( * V_84 , (struct V_95 * ) & V_121 ,
sizeof( V_121 ) , 0 ) ;
if ( V_13 == 0 )
return 0 ;
* V_85 = ! ( V_13 == - V_122 ) ;
F_50 ( * V_85 ? V_123 : V_31 ,
L_25 , V_13 ,
& V_86 , V_87 , & V_119 , V_120 ) ;
F_9 ( * V_84 ) ;
return V_13 ;
}
