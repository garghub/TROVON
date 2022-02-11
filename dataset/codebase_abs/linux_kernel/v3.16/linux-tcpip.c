int
F_1 ( int V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_2 ( V_6 , V_7 , 0 , & V_4 ) ;
if ( V_5 != 0 ) {
F_3 ( L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_4 ( V_4 , V_1 , V_2 ) ;
F_5 ( V_4 ) ;
return V_5 ;
}
int
F_6 ( char * V_8 , int * V_9 , T_1 * V_10 , T_1 * V_11 )
{
struct V_12 V_13 ;
int V_14 ;
int V_5 ;
T_1 V_15 ;
V_14 = F_7 ( V_8 , V_16 ) ;
if ( V_14 == V_16 ) {
F_3 ( L_2 , V_8 ) ;
return - V_17 ;
}
F_8 ( sizeof( V_13 . V_18 ) >= V_16 ) ;
strcpy ( V_13 . V_18 , V_8 ) ;
V_5 = F_1 ( V_19 , ( unsigned long ) & V_13 ) ;
if ( V_5 != 0 ) {
F_3 ( L_3 , V_8 ) ;
return V_5 ;
}
if ( ( V_13 . V_20 & V_21 ) == 0 ) {
F_9 ( V_22 , L_4 , V_8 ) ;
* V_9 = 0 ;
* V_10 = * V_11 = 0 ;
return 0 ;
}
* V_9 = 1 ;
strcpy ( V_13 . V_18 , V_8 ) ;
V_13 . V_23 . V_24 = V_25 ;
V_5 = F_1 ( V_26 , ( unsigned long ) & V_13 ) ;
if ( V_5 != 0 ) {
F_3 ( L_5 , V_8 ) ;
return V_5 ;
}
V_15 = ( (struct V_27 * ) & V_13 . V_23 ) -> V_28 . V_29 ;
* V_10 = F_10 ( V_15 ) ;
strcpy ( V_13 . V_18 , V_8 ) ;
V_13 . V_23 . V_24 = V_25 ;
V_5 = F_1 ( V_30 , ( unsigned long ) & V_13 ) ;
if ( V_5 != 0 ) {
F_3 ( L_6 , V_8 ) ;
return V_5 ;
}
V_15 = ( (struct V_27 * ) & V_13 . V_31 ) -> V_28 . V_29 ;
* V_11 = F_10 ( V_15 ) ;
return 0 ;
}
int
F_11 ( char * * * V_32 )
{
char * * V_33 ;
int V_34 ;
int V_35 ;
int V_36 ;
struct V_12 * V_13 ;
struct V_37 V_38 ;
int V_5 ;
int V_14 ;
int V_39 ;
V_35 = 16 ;
V_34 = 0 ;
for (; ; ) {
if ( V_35 * sizeof( * V_13 ) > V_40 ) {
V_34 = 1 ;
V_35 = V_40 / sizeof( * V_13 ) ;
F_12 ( L_7 ,
V_35 ) ;
}
F_13 ( V_13 , V_35 * sizeof( * V_13 ) ) ;
if ( V_13 == NULL ) {
F_3 ( L_8 , V_35 ) ;
V_5 = - V_41 ;
goto V_42;
}
V_38 . V_43 = ( char * ) V_13 ;
V_38 . V_44 = V_35 * sizeof( * V_13 ) ;
V_5 = F_1 ( V_45 , ( unsigned long ) & V_38 ) ;
if ( V_5 < 0 ) {
F_3 ( L_9 , V_5 ) ;
goto V_46;
}
F_14 ( V_5 == 0 ) ;
V_36 = V_38 . V_44 / sizeof( * V_13 ) ;
F_14 ( V_36 <= V_35 ) ;
if ( V_36 < V_35 || V_34 )
break;
F_15 ( V_13 , V_35 * sizeof( * V_13 ) ) ;
V_35 *= 2 ;
}
if ( V_36 == 0 )
goto V_46;
F_13 ( V_33 , V_36 * sizeof( * V_33 ) ) ;
if ( V_33 == NULL ) {
V_5 = - V_41 ;
goto V_46;
}
memset ( V_33 , 0 , V_36 * sizeof( * V_33 ) ) ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_14 = F_7 ( V_13 [ V_39 ] . V_18 , V_16 ) ;
if ( V_14 == V_16 ) {
F_3 ( L_10 ,
V_14 , V_13 [ V_39 ] . V_18 , V_16 ) ;
V_5 = - V_47 ;
goto V_48;
}
F_13 ( V_33 [ V_39 ] , V_16 ) ;
if ( V_33 [ V_39 ] == NULL ) {
V_5 = - V_41 ;
goto V_48;
}
memcpy ( V_33 [ V_39 ] , V_13 [ V_39 ] . V_18 , V_14 ) ;
V_33 [ V_39 ] [ V_14 ] = 0 ;
}
* V_32 = V_33 ;
V_5 = V_36 ;
V_48:
if ( V_5 < 0 )
F_16 ( V_33 , V_36 ) ;
V_46:
F_15 ( V_13 , V_35 * sizeof( * V_13 ) ) ;
V_42:
return V_5 ;
}
void
F_16 ( char * * V_33 , int V_49 )
{
int V_39 ;
F_14 ( V_49 > 0 ) ;
for ( V_39 = 0 ; V_39 < V_49 && V_33 [ V_39 ] != NULL ; V_39 ++ )
F_15 ( V_33 [ V_39 ] , V_16 ) ;
F_15 ( V_33 , V_49 * sizeof( * V_33 ) ) ;
}
int
F_17 ( struct V_3 * V_4 , void * V_50 , int V_14 , int V_51 )
{
int V_5 ;
long V_52 = V_51 * V_53 ;
unsigned long V_54 ;
struct V_55 V_56 ;
F_14 ( V_14 > 0 ) ;
for (; ; ) {
struct V_57 V_58 = {
. V_59 = V_50 ,
. V_60 = V_14
} ;
struct V_61 V_62 = {
. V_63 = ( V_51 == 0 ) ? V_64 : 0
} ;
if ( V_51 != 0 ) {
V_56 = (struct V_55 ) {
. V_65 = V_52 / V_53 ,
. V_66 = ( ( V_52 % V_53 ) * 1000000 ) / V_53
} ;
V_5 = F_18 ( V_4 , V_67 , V_68 ,
( char * ) & V_56 , sizeof( V_56 ) ) ;
if ( V_5 != 0 ) {
F_3 ( L_11
L_12 ,
( long ) V_56 . V_65 , ( int ) V_56 . V_66 , V_5 ) ;
return V_5 ;
}
}
V_54 = V_69 ;
V_5 = F_19 ( V_4 , & V_62 , & V_58 , 1 , V_14 ) ;
V_52 -= V_69 - V_54 ;
if ( V_5 == V_14 )
return 0 ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 == 0 ) {
F_3 ( L_13 ) ;
return ( - V_70 ) ;
}
if ( V_52 <= 0 )
return - V_71 ;
V_50 = ( ( char * ) V_50 ) + V_5 ;
V_14 -= V_5 ;
}
return ( 0 ) ;
}
int
F_20 ( struct V_3 * V_4 , void * V_50 , int V_14 , int V_51 )
{
int V_5 ;
long V_52 = V_51 * V_53 ;
unsigned long V_54 ;
struct V_55 V_56 ;
F_14 ( V_14 > 0 ) ;
F_14 ( V_52 > 0 ) ;
for (; ; ) {
struct V_57 V_58 = {
. V_59 = V_50 ,
. V_60 = V_14
} ;
struct V_61 V_62 = {
. V_63 = 0
} ;
V_56 = (struct V_55 ) {
. V_65 = V_52 / V_53 ,
. V_66 = ( ( V_52 % V_53 ) * 1000000 ) / V_53
} ;
V_5 = F_18 ( V_4 , V_67 , V_72 ,
( char * ) & V_56 , sizeof( V_56 ) ) ;
if ( V_5 != 0 ) {
F_3 ( L_14 ,
( long ) V_56 . V_65 , ( int ) V_56 . V_66 , V_5 ) ;
return V_5 ;
}
V_54 = V_69 ;
V_5 = F_21 ( V_4 , & V_62 , & V_58 , 1 , V_14 , 0 ) ;
V_52 -= V_69 - V_54 ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 == 0 )
return - V_73 ;
V_50 = ( ( char * ) V_50 ) + V_5 ;
V_14 -= V_5 ;
if ( V_14 == 0 )
return 0 ;
if ( V_52 <= 0 )
return - V_74 ;
}
}
static int
F_22 ( struct V_3 * * V_75 , int * V_76 ,
T_1 V_77 , int V_78 )
{
struct V_27 V_79 ;
struct V_3 * V_4 ;
int V_5 ;
int V_80 ;
* V_76 = 1 ;
V_5 = F_2 ( V_6 , V_7 , 0 , & V_4 ) ;
* V_75 = V_4 ;
if ( V_5 != 0 ) {
F_3 ( L_1 , V_5 ) ;
return ( V_5 ) ;
}
V_80 = 1 ;
V_5 = F_18 ( V_4 , V_67 , V_81 ,
( char * ) & V_80 , sizeof ( V_80 ) ) ;
if ( V_5 != 0 ) {
F_3 ( L_15 , V_5 ) ;
goto V_82;
}
if ( V_77 != 0 || V_78 != 0 ) {
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_83 = V_25 ;
V_79 . V_84 = F_23 ( V_78 ) ;
V_79 . V_28 . V_29 = ( V_77 == 0 ) ?
V_85 : F_24 ( V_77 ) ;
V_5 = V_4 -> V_86 -> V_87 ( V_4 , (struct V_88 * ) & V_79 ,
sizeof( V_79 ) ) ;
if ( V_5 == - V_89 ) {
F_9 ( V_22 , L_16 , V_78 ) ;
* V_76 = 0 ;
goto V_82;
}
if ( V_5 != 0 ) {
F_3 ( L_17 ,
V_78 , V_5 ) ;
goto V_82;
}
}
return 0 ;
V_82:
F_5 ( V_4 ) ;
return V_5 ;
}
int
F_25 ( struct V_3 * V_4 , int V_90 , int V_91 )
{
int V_80 ;
int V_5 ;
if ( V_90 != 0 ) {
V_80 = V_90 ;
V_5 = F_18 ( V_4 , V_67 , V_92 ,
( char * ) & V_80 , sizeof ( V_80 ) ) ;
if ( V_5 != 0 ) {
F_3 ( L_18 ,
V_80 , V_5 ) ;
return ( V_5 ) ;
}
}
if ( V_91 != 0 ) {
V_80 = V_91 ;
V_5 = F_18 ( V_4 , V_67 , V_93 ,
( char * ) & V_80 , sizeof ( V_80 ) ) ;
if ( V_5 != 0 ) {
F_3 ( L_19 ,
V_80 , V_5 ) ;
return ( V_5 ) ;
}
}
return 0 ;
}
int
F_26 ( struct V_3 * V_4 , int V_94 , T_1 * V_10 , int * V_95 )
{
struct V_27 sin ;
int V_96 = sizeof ( sin ) ;
int V_5 ;
V_5 = V_4 -> V_86 -> V_97 ( V_4 , (struct V_88 * ) & sin , & V_96 ,
V_94 ? 2 : 0 ) ;
if ( V_5 != 0 ) {
F_3 ( L_20 ,
V_5 , V_94 ? L_21 : L_22 ) ;
return V_5 ;
}
if ( V_10 != NULL )
* V_10 = F_10 ( sin . V_28 . V_29 ) ;
if ( V_95 != NULL )
* V_95 = F_27 ( sin . V_84 ) ;
return 0 ;
}
int
F_28 ( struct V_3 * V_4 , int * V_90 , int * V_91 )
{
if ( V_90 != NULL ) {
* V_90 = V_4 -> V_98 -> V_99 ;
}
if ( V_91 != NULL ) {
* V_91 = V_4 -> V_98 -> V_100 ;
}
return 0 ;
}
int
F_29 ( struct V_3 * * V_75 ,
T_1 V_77 , int V_78 , int V_101 )
{
int V_76 ;
int V_5 ;
V_5 = F_22 ( V_75 , & V_76 , V_77 , V_78 ) ;
if ( V_5 != 0 ) {
if ( ! V_76 )
F_3 ( L_23 ,
V_78 ) ;
return V_5 ;
}
V_5 = ( * V_75 ) -> V_86 -> V_102 ( * V_75 , V_101 ) ;
if ( V_5 == 0 )
return 0 ;
F_3 ( L_24 , V_101 , V_5 ) ;
F_5 ( * V_75 ) ;
return V_5 ;
}
int
F_30 ( struct V_3 * * V_103 , struct V_3 * V_4 )
{
T_2 V_104 ;
struct V_3 * V_105 ;
int V_5 ;
F_31 ( & V_104 , V_106 ) ;
V_5 = F_32 ( V_107 , V_4 -> type , V_108 , & V_105 ) ;
if ( V_5 ) {
F_3 ( L_25 ) ;
return V_5 ;
}
V_105 -> V_86 = V_4 -> V_86 ;
F_33 ( V_109 ) ;
F_34 ( F_35 ( V_4 -> V_98 ) , & V_104 ) ;
V_5 = V_4 -> V_86 -> V_110 ( V_4 , V_105 , V_111 ) ;
if ( V_5 == - V_71 ) {
F_36 () ;
V_5 = V_4 -> V_86 -> V_110 ( V_4 , V_105 , V_111 ) ;
}
F_37 ( F_35 ( V_4 -> V_98 ) , & V_104 ) ;
F_33 ( V_112 ) ;
if ( V_5 != 0 )
goto V_82;
* V_103 = V_105 ;
return 0 ;
V_82:
F_5 ( V_105 ) ;
return V_5 ;
}
void
F_38 ( struct V_3 * V_4 )
{
F_39 ( F_35 ( V_4 -> V_98 ) ) ;
}
int
F_40 ( struct V_3 * * V_75 , int * V_76 ,
T_1 V_77 , int V_78 ,
T_1 V_113 , int V_114 )
{
struct V_27 V_115 ;
int V_5 ;
V_5 = F_22 ( V_75 , V_76 , V_77 , V_78 ) ;
if ( V_5 != 0 )
return V_5 ;
memset ( & V_115 , 0 , sizeof ( V_115 ) ) ;
V_115 . V_83 = V_25 ;
V_115 . V_84 = F_23 ( V_114 ) ;
V_115 . V_28 . V_29 = F_24 ( V_113 ) ;
V_5 = ( * V_75 ) -> V_86 -> V_116 ( * V_75 ,
(struct V_88 * ) & V_115 , sizeof( V_115 ) ,
0 ) ;
if ( V_5 == 0 )
return 0 ;
* V_76 = ! ( V_5 == - V_117 ) ;
F_41 ( * V_76 ? V_118 : V_22 ,
L_26 , V_5 ,
& V_77 , V_78 , & V_113 , V_114 ) ;
F_5 ( * V_75 ) ;
return V_5 ;
}
void
F_42 ( struct V_3 * V_4 )
{
F_5 ( V_4 ) ;
}
