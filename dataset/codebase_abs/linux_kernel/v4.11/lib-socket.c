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
if ( V_13 ) {
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
F_14 ( sizeof( V_22 . V_27 ) < V_25 ) ;
if ( strlen ( V_17 ) > sizeof( V_22 . V_27 ) - 1 )
return - V_28 ;
strncpy ( V_22 . V_27 , V_17 , sizeof( V_22 . V_27 ) ) ;
V_13 = F_4 ( V_29 , ( unsigned long ) & V_22 ) ;
if ( V_13 ) {
F_6 ( L_3 , V_17 ) ;
return V_13 ;
}
if ( ! ( V_22 . V_30 & V_31 ) ) {
F_15 ( V_32 , L_4 , V_17 ) ;
* V_18 = 0 ;
* V_19 = * V_20 = 0 ;
return 0 ;
}
* V_18 = 1 ;
if ( strlen ( V_17 ) > sizeof( V_22 . V_27 ) - 1 )
return - V_28 ;
strncpy ( V_22 . V_27 , V_17 , sizeof( V_22 . V_27 ) ) ;
V_22 . V_33 . V_34 = V_35 ;
V_13 = F_4 ( V_36 , ( unsigned long ) & V_22 ) ;
if ( V_13 ) {
F_6 ( L_5 , V_17 ) ;
return V_13 ;
}
V_24 = ( (struct V_37 * ) & V_22 . V_33 ) -> V_38 . V_39 ;
* V_19 = F_16 ( V_24 ) ;
if ( strlen ( V_17 ) > sizeof( V_22 . V_27 ) - 1 )
return - V_28 ;
strncpy ( V_22 . V_27 , V_17 , sizeof( V_22 . V_27 ) ) ;
V_22 . V_33 . V_34 = V_35 ;
V_13 = F_4 ( V_40 , ( unsigned long ) & V_22 ) ;
if ( V_13 ) {
F_6 ( L_6 , V_17 ) ;
return V_13 ;
}
V_24 = ( (struct V_37 * ) & V_22 . V_41 ) -> V_38 . V_39 ;
* V_20 = F_16 ( V_24 ) ;
return 0 ;
}
int
F_17 ( char * * * V_42 )
{
char * * V_43 ;
int V_44 ;
int V_45 ;
int V_46 ;
struct V_21 * V_22 ;
struct V_47 V_48 ;
int V_13 ;
int V_23 ;
int V_49 ;
V_45 = 16 ;
V_44 = 0 ;
for (; ; ) {
if ( V_45 * sizeof( * V_22 ) > V_50 ) {
V_44 = 1 ;
V_45 = V_50 / sizeof( * V_22 ) ;
F_18 ( L_7 ,
V_45 ) ;
}
F_19 ( V_22 , V_45 * sizeof( * V_22 ) ) ;
if ( ! V_22 ) {
F_6 ( L_8 ,
V_45 ) ;
V_13 = - V_51 ;
goto V_52;
}
V_48 . V_53 = ( char * ) V_22 ;
V_48 . V_54 = V_45 * sizeof( * V_22 ) ;
V_13 = F_4 ( V_55 , ( unsigned long ) & V_48 ) ;
if ( V_13 < 0 ) {
F_6 ( L_9 , V_13 ) ;
goto V_56;
}
F_20 ( ! V_13 ) ;
V_46 = V_48 . V_54 / sizeof( * V_22 ) ;
F_20 ( V_46 <= V_45 ) ;
if ( V_46 < V_45 || V_44 )
break;
F_21 ( V_22 , V_45 * sizeof( * V_22 ) ) ;
V_45 *= 2 ;
}
if ( ! V_46 )
goto V_56;
F_19 ( V_43 , V_46 * sizeof( * V_43 ) ) ;
if ( ! V_43 ) {
V_13 = - V_51 ;
goto V_56;
}
for ( V_49 = 0 ; V_49 < V_46 ; V_49 ++ ) {
V_23 = F_13 ( V_22 [ V_49 ] . V_27 , V_25 ) ;
if ( V_23 == V_25 ) {
F_6 ( L_10 ,
V_23 , V_22 [ V_49 ] . V_27 , V_25 ) ;
V_13 = - V_57 ;
goto V_58;
}
F_19 ( V_43 [ V_49 ] , V_25 ) ;
if ( ! V_43 [ V_49 ] ) {
V_13 = - V_51 ;
goto V_58;
}
memcpy ( V_43 [ V_49 ] , V_22 [ V_49 ] . V_27 , V_23 ) ;
V_43 [ V_49 ] [ V_23 ] = 0 ;
}
* V_42 = V_43 ;
V_13 = V_46 ;
V_58:
if ( V_13 < 0 )
F_22 ( V_43 , V_46 ) ;
V_56:
F_21 ( V_22 , V_45 * sizeof( * V_22 ) ) ;
V_52:
return V_13 ;
}
void
F_22 ( char * * V_43 , int V_59 )
{
int V_49 ;
F_20 ( V_59 > 0 ) ;
for ( V_49 = 0 ; V_49 < V_59 && V_43 [ V_49 ] ; V_49 ++ )
F_21 ( V_43 [ V_49 ] , V_25 ) ;
F_21 ( V_43 , V_59 * sizeof( * V_43 ) ) ;
}
int
F_23 ( struct V_11 * V_12 , void * V_60 , int V_23 , int V_61 )
{
int V_13 ;
long V_62 = V_61 * F_24 ( V_63 ) ;
unsigned long V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 = { . V_69 = V_60 , . V_70 = V_23 } ;
struct V_71 V_72 = { NULL ,} ;
F_20 ( V_23 > 0 ) ;
F_25 ( & V_72 . V_73 , V_74 | V_75 , & V_68 , 1 , V_23 ) ;
for (; ; ) {
V_72 . V_76 = ! V_61 ? V_77 : 0 ;
if ( V_61 ) {
F_26 ( V_62 , & V_66 ) ;
V_13 = F_27 ( V_12 , V_78 , V_79 ,
( char * ) & V_66 , sizeof( V_66 ) ) ;
if ( V_13 ) {
F_6 ( L_11 ,
( long ) V_66 . V_80 , ( int ) V_66 . V_81 , V_13 ) ;
return V_13 ;
}
}
V_64 = V_82 ;
V_13 = F_28 ( V_12 , & V_72 , & V_68 , 1 , V_23 ) ;
V_62 -= V_82 - V_64 ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_13 ) {
F_6 ( L_12 ) ;
return - V_83 ;
}
if ( ! F_29 ( & V_72 ) )
break;
if ( V_62 <= 0 )
return - V_84 ;
}
return 0 ;
}
int
F_30 ( struct V_11 * V_12 , void * V_60 , int V_23 , int V_61 )
{
int V_13 ;
long V_62 = V_61 * F_24 ( V_63 ) ;
unsigned long V_64 ;
struct V_65 V_66 ;
F_20 ( V_23 > 0 ) ;
F_20 ( V_62 > 0 ) ;
for (; ; ) {
struct V_67 V_68 = {
. V_69 = V_60 ,
. V_70 = V_23
} ;
struct V_71 V_72 = {
. V_76 = 0
} ;
F_26 ( V_62 , & V_66 ) ;
V_13 = F_27 ( V_12 , V_78 , V_85 ,
( char * ) & V_66 , sizeof( V_66 ) ) ;
if ( V_13 ) {
F_6 ( L_13 ,
( long ) V_66 . V_80 , ( int ) V_66 . V_81 , V_13 ) ;
return V_13 ;
}
V_64 = V_82 ;
V_13 = F_31 ( V_12 , & V_72 , & V_68 , 1 , V_23 , 0 ) ;
V_62 -= V_82 - V_64 ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_13 )
return - V_86 ;
V_60 = ( ( char * ) V_60 ) + V_13 ;
V_23 -= V_13 ;
if ( ! V_23 )
return 0 ;
if ( V_62 <= 0 )
return - V_87 ;
}
}
static int
F_32 ( struct V_11 * * V_88 , int * V_89 , T_2 V_90 ,
int V_91 )
{
struct V_37 V_92 ;
struct V_11 * V_12 ;
int V_13 ;
int V_93 ;
* V_89 = 1 ;
V_13 = F_5 ( V_14 , V_15 , 0 , & V_12 ) ;
* V_88 = V_12 ;
if ( V_13 ) {
F_6 ( L_1 , V_13 ) ;
return V_13 ;
}
V_93 = 1 ;
V_13 = F_27 ( V_12 , V_78 , V_94 ,
( char * ) & V_93 , sizeof( V_93 ) ) ;
if ( V_13 ) {
F_6 ( L_14 , V_13 ) ;
goto V_95;
}
if ( V_90 || V_91 ) {
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_96 = V_35 ;
V_92 . V_97 = F_33 ( V_91 ) ;
if ( ! V_90 )
V_92 . V_38 . V_39 = F_34 ( V_98 ) ;
else
V_92 . V_38 . V_39 = F_34 ( V_90 ) ;
V_13 = F_35 ( V_12 , (struct V_99 * ) & V_92 ,
sizeof( V_92 ) ) ;
if ( V_13 == - V_100 ) {
F_15 ( V_32 , L_15 , V_91 ) ;
* V_89 = 0 ;
goto V_95;
}
if ( V_13 ) {
F_6 ( L_16 ,
V_91 , V_13 ) ;
goto V_95;
}
}
return 0 ;
V_95:
F_9 ( V_12 ) ;
return V_13 ;
}
int
F_36 ( struct V_11 * V_12 , int V_101 , int V_102 )
{
int V_93 ;
int V_13 ;
if ( V_101 ) {
V_93 = V_101 ;
V_13 = F_27 ( V_12 , V_78 , V_103 ,
( char * ) & V_93 , sizeof( V_93 ) ) ;
if ( V_13 ) {
F_6 ( L_17 ,
V_93 , V_13 ) ;
return V_13 ;
}
}
if ( V_102 ) {
V_93 = V_102 ;
V_13 = F_27 ( V_12 , V_78 , V_104 ,
( char * ) & V_93 , sizeof( V_93 ) ) ;
if ( V_13 ) {
F_6 ( L_18 ,
V_93 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
int
F_37 ( struct V_11 * V_12 , bool V_105 , T_2 * V_19 , int * V_106 )
{
struct V_37 sin ;
int V_107 = sizeof( sin ) ;
int V_13 ;
if ( V_105 )
V_13 = F_38 ( V_12 , (struct V_99 * ) & sin , & V_107 ) ;
else
V_13 = F_39 ( V_12 , (struct V_99 * ) & sin , & V_107 ) ;
if ( V_13 ) {
F_6 ( L_19 ,
V_13 , V_105 ? L_20 : L_21 ) ;
return V_13 ;
}
if ( V_19 )
* V_19 = F_16 ( sin . V_38 . V_39 ) ;
if ( V_106 )
* V_106 = F_40 ( sin . V_97 ) ;
return 0 ;
}
int
F_41 ( struct V_11 * V_12 , int * V_101 , int * V_102 )
{
if ( V_101 )
* V_101 = V_12 -> V_108 -> V_109 ;
if ( V_102 )
* V_102 = V_12 -> V_108 -> V_110 ;
return 0 ;
}
int
F_42 ( struct V_11 * * V_88 , T_2 V_90 , int V_91 ,
int V_111 )
{
int V_89 ;
int V_13 ;
V_13 = F_32 ( V_88 , & V_89 , V_90 , V_91 ) ;
if ( V_13 ) {
if ( ! V_89 )
F_6 ( L_22 ,
V_91 ) ;
return V_13 ;
}
V_13 = F_43 ( * V_88 , V_111 ) ;
if ( ! V_13 )
return 0 ;
F_6 ( L_23 , V_111 , V_13 ) ;
F_9 ( * V_88 ) ;
return V_13 ;
}
int
F_44 ( struct V_11 * * V_112 , struct V_11 * V_12 )
{
T_3 V_113 ;
struct V_11 * V_114 ;
int V_13 ;
V_13 = F_45 ( V_115 , V_12 -> type , V_116 , & V_114 ) ;
if ( V_13 ) {
F_6 ( L_24 ) ;
return V_13 ;
}
V_114 -> V_117 = V_12 -> V_117 ;
V_13 = V_12 -> V_117 -> V_118 ( V_12 , V_114 , V_119 , false ) ;
if ( V_13 == - V_84 ) {
F_46 ( & V_113 , V_120 ) ;
F_47 ( F_48 ( V_12 -> V_108 ) , & V_113 ) ;
F_49 ( V_121 ) ;
F_50 () ;
F_51 ( F_48 ( V_12 -> V_108 ) , & V_113 ) ;
V_13 = V_12 -> V_117 -> V_118 ( V_12 , V_114 , V_119 , false ) ;
}
if ( V_13 )
goto V_95;
* V_112 = V_114 ;
return 0 ;
V_95:
F_9 ( V_114 ) ;
return V_13 ;
}
int
F_52 ( struct V_11 * * V_88 , int * V_89 , T_2 V_90 ,
int V_91 , T_2 V_122 , int V_123 )
{
struct V_37 V_124 ;
int V_13 ;
V_13 = F_32 ( V_88 , V_89 , V_90 , V_91 ) ;
if ( V_13 )
return V_13 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_96 = V_35 ;
V_124 . V_97 = F_33 ( V_123 ) ;
V_124 . V_38 . V_39 = F_34 ( V_122 ) ;
V_13 = F_53 ( * V_88 , (struct V_99 * ) & V_124 ,
sizeof( V_124 ) , 0 ) ;
if ( ! V_13 )
return 0 ;
* V_89 = ! ( V_13 == - V_125 ) ;
F_54 ( * V_89 ? V_126 : V_32 ,
L_25 , V_13 ,
& V_90 , V_91 , & V_122 , V_123 ) ;
F_9 ( * V_88 ) ;
return V_13 ;
}
