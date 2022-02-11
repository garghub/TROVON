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
F_14 ( sizeof( V_22 . V_27 ) >= V_25 ) ;
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
F_20 ( V_23 > 0 ) ;
for (; ; ) {
struct V_67 V_68 = {
. V_69 = V_60 ,
. V_70 = V_23
} ;
struct V_71 V_72 = {
. V_73 = ! V_61 ? V_74 : 0
} ;
if ( V_61 ) {
F_25 ( V_62 , & V_66 ) ;
V_13 = F_26 ( V_12 , V_75 , V_76 ,
( char * ) & V_66 , sizeof( V_66 ) ) ;
if ( V_13 ) {
F_6 ( L_11 ,
( long ) V_66 . V_77 , ( int ) V_66 . V_78 , V_13 ) ;
return V_13 ;
}
}
V_64 = V_79 ;
V_13 = F_27 ( V_12 , & V_72 , & V_68 , 1 , V_23 ) ;
V_62 -= V_79 - V_64 ;
if ( V_13 == V_23 )
return 0 ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_13 ) {
F_6 ( L_12 ) ;
return - V_80 ;
}
if ( V_62 <= 0 )
return - V_81 ;
V_60 = ( ( char * ) V_60 ) + V_13 ;
V_23 -= V_13 ;
}
return 0 ;
}
int
F_28 ( struct V_11 * V_12 , void * V_60 , int V_23 , int V_61 )
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
. V_73 = 0
} ;
F_25 ( V_62 , & V_66 ) ;
V_13 = F_26 ( V_12 , V_75 , V_82 ,
( char * ) & V_66 , sizeof( V_66 ) ) ;
if ( V_13 ) {
F_6 ( L_13 ,
( long ) V_66 . V_77 , ( int ) V_66 . V_78 , V_13 ) ;
return V_13 ;
}
V_64 = V_79 ;
V_13 = F_29 ( V_12 , & V_72 , & V_68 , 1 , V_23 , 0 ) ;
V_62 -= V_79 - V_64 ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_13 )
return - V_83 ;
V_60 = ( ( char * ) V_60 ) + V_13 ;
V_23 -= V_13 ;
if ( ! V_23 )
return 0 ;
if ( V_62 <= 0 )
return - V_84 ;
}
}
static int
F_30 ( struct V_11 * * V_85 , int * V_86 , T_2 V_87 ,
int V_88 )
{
struct V_37 V_89 ;
struct V_11 * V_12 ;
int V_13 ;
int V_90 ;
* V_86 = 1 ;
V_13 = F_5 ( V_14 , V_15 , 0 , & V_12 ) ;
* V_85 = V_12 ;
if ( V_13 ) {
F_6 ( L_1 , V_13 ) ;
return V_13 ;
}
V_90 = 1 ;
V_13 = F_26 ( V_12 , V_75 , V_91 ,
( char * ) & V_90 , sizeof( V_90 ) ) ;
if ( V_13 ) {
F_6 ( L_14 , V_13 ) ;
goto V_92;
}
if ( V_87 || V_88 ) {
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_93 = V_35 ;
V_89 . V_94 = F_31 ( V_88 ) ;
V_89 . V_38 . V_39 = ! V_87 ?
V_95 : F_32 ( V_87 ) ;
V_13 = F_33 ( V_12 , (struct V_96 * ) & V_89 ,
sizeof( V_89 ) ) ;
if ( V_13 == - V_97 ) {
F_15 ( V_32 , L_15 , V_88 ) ;
* V_86 = 0 ;
goto V_92;
}
if ( V_13 ) {
F_6 ( L_16 ,
V_88 , V_13 ) ;
goto V_92;
}
}
return 0 ;
V_92:
F_9 ( V_12 ) ;
return V_13 ;
}
int
F_34 ( struct V_11 * V_12 , int V_98 , int V_99 )
{
int V_90 ;
int V_13 ;
if ( V_98 ) {
V_90 = V_98 ;
V_13 = F_26 ( V_12 , V_75 , V_100 ,
( char * ) & V_90 , sizeof( V_90 ) ) ;
if ( V_13 ) {
F_6 ( L_17 ,
V_90 , V_13 ) ;
return V_13 ;
}
}
if ( V_99 ) {
V_90 = V_99 ;
V_13 = F_26 ( V_12 , V_75 , V_101 ,
( char * ) & V_90 , sizeof( V_90 ) ) ;
if ( V_13 ) {
F_6 ( L_18 ,
V_90 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
int
F_35 ( struct V_11 * V_12 , bool V_102 , T_2 * V_19 , int * V_103 )
{
struct V_37 sin ;
int V_104 = sizeof( sin ) ;
int V_13 ;
if ( V_102 )
V_13 = F_36 ( V_12 , (struct V_96 * ) & sin , & V_104 ) ;
else
V_13 = F_37 ( V_12 , (struct V_96 * ) & sin , & V_104 ) ;
if ( V_13 ) {
F_6 ( L_19 ,
V_13 , V_102 ? L_20 : L_21 ) ;
return V_13 ;
}
if ( V_19 )
* V_19 = F_16 ( sin . V_38 . V_39 ) ;
if ( V_103 )
* V_103 = F_38 ( sin . V_94 ) ;
return 0 ;
}
int
F_39 ( struct V_11 * V_12 , int * V_98 , int * V_99 )
{
if ( V_98 )
* V_98 = V_12 -> V_105 -> V_106 ;
if ( V_99 )
* V_99 = V_12 -> V_105 -> V_107 ;
return 0 ;
}
int
F_40 ( struct V_11 * * V_85 , T_2 V_87 , int V_88 ,
int V_108 )
{
int V_86 ;
int V_13 ;
V_13 = F_30 ( V_85 , & V_86 , V_87 , V_88 ) ;
if ( V_13 ) {
if ( ! V_86 )
F_6 ( L_22 ,
V_88 ) ;
return V_13 ;
}
V_13 = F_41 ( * V_85 , V_108 ) ;
if ( ! V_13 )
return 0 ;
F_6 ( L_23 , V_108 , V_13 ) ;
F_9 ( * V_85 ) ;
return V_13 ;
}
int
F_42 ( struct V_11 * * V_109 , struct V_11 * V_12 )
{
T_3 V_110 ;
struct V_11 * V_111 ;
int V_13 ;
V_13 = F_43 ( V_112 , V_12 -> type , V_113 , & V_111 ) ;
if ( V_13 ) {
F_6 ( L_24 ) ;
return V_13 ;
}
V_111 -> V_114 = V_12 -> V_114 ;
V_13 = V_12 -> V_114 -> V_115 ( V_12 , V_111 , V_116 ) ;
if ( V_13 == - V_81 ) {
F_44 ( & V_110 , V_117 ) ;
F_45 ( F_46 ( V_12 -> V_105 ) , & V_110 ) ;
F_47 ( V_118 ) ;
F_48 () ;
F_49 ( F_46 ( V_12 -> V_105 ) , & V_110 ) ;
V_13 = V_12 -> V_114 -> V_115 ( V_12 , V_111 , V_116 ) ;
}
if ( V_13 )
goto V_92;
* V_109 = V_111 ;
return 0 ;
V_92:
F_9 ( V_111 ) ;
return V_13 ;
}
int
F_50 ( struct V_11 * * V_85 , int * V_86 , T_2 V_87 ,
int V_88 , T_2 V_119 , int V_120 )
{
struct V_37 V_121 ;
int V_13 ;
V_13 = F_30 ( V_85 , V_86 , V_87 , V_88 ) ;
if ( V_13 )
return V_13 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_93 = V_35 ;
V_121 . V_94 = F_31 ( V_120 ) ;
V_121 . V_38 . V_39 = F_32 ( V_119 ) ;
V_13 = F_51 ( * V_85 , (struct V_96 * ) & V_121 ,
sizeof( V_121 ) , 0 ) ;
if ( ! V_13 )
return 0 ;
* V_86 = ! ( V_13 == - V_122 ) ;
F_52 ( * V_86 ? V_123 : V_32 ,
L_25 , V_13 ,
& V_87 , V_88 , & V_119 , V_120 ) ;
F_9 ( * V_85 ) ;
return V_13 ;
}
