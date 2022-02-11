static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 = F_2 ( V_3 , V_5 ) ;
if ( V_2 -> V_4 == NULL )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_2 -> V_4 ;
V_2 -> V_9 = V_2 -> V_4 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_2 -> V_8 ;
}
static unsigned F_6 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_8 - V_2 -> V_9 ) % V_2 -> V_7 ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_9 - V_2 -> V_8 - 1 ) % V_2 -> V_7 ;
}
static unsigned
F_8 ( struct V_1 * V_2 , const char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_8 ;
if ( V_11 > V_12 ) {
memcpy ( V_2 -> V_8 , V_10 , V_12 ) ;
memcpy ( V_2 -> V_4 , V_10 + V_12 , V_11 - V_12 ) ;
V_2 -> V_8 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_2 -> V_8 , V_10 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_8 += V_11 ;
else
V_2 -> V_8 = V_2 -> V_4 ;
}
return V_11 ;
}
static unsigned
F_9 ( struct V_1 * V_2 , char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_6 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_9 ;
if ( V_11 > V_12 ) {
memcpy ( V_10 , V_2 -> V_9 , V_12 ) ;
memcpy ( V_10 + V_12 , V_2 -> V_4 , V_11 - V_12 ) ;
V_2 -> V_9 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_10 , V_2 -> V_9 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_9 += V_11 ;
else
V_2 -> V_9 = V_2 -> V_4 ;
}
return V_11 ;
}
struct V_13 *
F_10 ( struct V_14 * V_15 , unsigned V_12 , T_1 V_16 )
{
struct V_13 * V_17 ;
V_17 = F_11 ( V_15 , V_16 ) ;
if ( V_17 != NULL ) {
V_17 -> V_18 = V_12 ;
V_17 -> V_10 = F_2 ( V_12 , V_16 ) ;
if ( V_17 -> V_10 == NULL ) {
F_12 ( V_15 , V_17 ) ;
return NULL ;
}
}
return V_17 ;
}
void F_13 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
F_4 ( V_17 -> V_10 ) ;
F_12 ( V_15 , V_17 ) ;
}
static unsigned
F_14 ( struct V_19 * V_20 , char * V_21 , unsigned V_3 )
{
unsigned V_12 ;
V_12 = F_6 ( & V_20 -> V_22 ) ;
if ( V_12 < V_3 )
V_3 = V_12 ;
if ( V_3 != 0 )
V_3 = F_9 ( & V_20 -> V_22 , V_21 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_25 ;
struct V_14 * V_26 = V_20 -> V_27 -> V_26 ;
int V_28 = 0 ;
bool V_29 = false ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_12 ;
if ( V_20 -> V_30 >= V_31 )
break;
V_17 = F_17 ( V_24 -> V_32 , struct V_13 , V_33 ) ;
V_12 = F_14 ( V_20 , V_17 -> V_10 , V_26 -> V_34 ) ;
if ( V_12 == 0 ) {
F_18 ( & V_20 -> V_35 ) ;
break;
}
V_29 = true ;
V_17 -> V_18 = V_12 ;
F_19 ( & V_17 -> V_33 ) ;
V_17 -> V_36 = ( F_6 ( & V_20 -> V_22 ) == 0 ) ;
F_20 ( V_37 L_1 ,
V_20 -> V_38 , V_12 , * ( ( V_39 * ) V_17 -> V_10 ) ,
* ( ( V_39 * ) V_17 -> V_10 + 1 ) , * ( ( V_39 * ) V_17 -> V_10 + 2 ) ) ;
F_21 ( & V_20 -> V_40 ) ;
V_28 = F_22 ( V_26 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_26 -> V_43 , V_28 ) ;
F_25 ( & V_17 -> V_33 , V_24 ) ;
break;
}
V_20 -> V_30 ++ ;
if ( ! V_20 -> V_27 )
break;
}
if ( V_29 && V_20 -> V_44 )
F_26 ( V_20 -> V_44 ) ;
return V_28 ;
}
static unsigned F_27 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_45 ;
struct V_14 * V_46 = V_20 -> V_27 -> V_46 ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_28 ;
struct V_47 * V_48 ;
V_48 = V_20 -> V_44 ;
if ( ! V_48 )
break;
if ( V_20 -> V_49 >= V_31 )
break;
V_17 = F_17 ( V_24 -> V_32 , struct V_13 , V_33 ) ;
F_19 ( & V_17 -> V_33 ) ;
V_17 -> V_18 = V_46 -> V_34 ;
F_21 ( & V_20 -> V_40 ) ;
V_28 = F_22 ( V_46 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_46 -> V_43 , V_28 ) ;
F_25 ( & V_17 -> V_33 , V_24 ) ;
break;
}
V_20 -> V_49 ++ ;
if ( ! V_20 -> V_27 )
break;
}
return V_20 -> V_49 ;
}
static void F_28 ( unsigned long V_50 )
{
struct V_19 * V_20 = ( void * ) V_50 ;
struct V_47 * V_48 ;
struct V_23 * V_51 = & V_20 -> V_52 ;
bool V_53 = false ;
bool V_54 = false ;
F_29 ( & V_20 -> V_40 ) ;
V_48 = V_20 -> V_44 ;
while ( ! F_16 ( V_51 ) ) {
struct V_13 * V_17 ;
V_17 = F_30 ( V_51 , struct V_13 , V_33 ) ;
if ( ! V_48 )
goto V_55;
if ( F_31 ( V_56 , & V_48 -> V_57 ) )
break;
switch ( V_17 -> V_28 ) {
case - V_58 :
V_53 = true ;
F_20 ( V_37 L_4 , V_20 -> V_38 ) ;
break;
default:
F_32 ( V_37 L_5 ,
V_20 -> V_38 , V_17 -> V_28 ) ;
case 0 :
break;
}
if ( V_17 -> V_59 ) {
char * V_21 = V_17 -> V_10 ;
unsigned V_3 = V_17 -> V_59 ;
unsigned V_60 ;
int V_11 ;
V_60 = V_20 -> V_61 ;
if ( V_60 ) {
V_21 += V_60 ;
V_3 -= V_60 ;
}
V_11 = F_33 ( V_48 , V_21 , V_3 ) ;
if ( V_11 )
V_54 = true ;
if ( V_11 != V_3 ) {
V_20 -> V_61 += V_11 ;
F_20 ( V_37 L_6 ,
V_20 -> V_38 ,
V_11 , V_17 -> V_59 ) ;
break;
}
V_20 -> V_61 = 0 ;
}
V_55:
F_34 ( & V_17 -> V_33 , & V_20 -> V_45 ) ;
V_20 -> V_49 -- ;
}
if ( V_48 && V_54 ) {
F_35 ( V_48 ) ;
}
if ( ! F_16 ( V_51 ) && V_48 ) {
if ( ! F_31 ( V_56 , & V_48 -> V_57 ) ) {
if ( V_54 )
F_36 ( & V_20 -> V_62 ) ;
else
F_32 ( V_37 L_7 ,
V_20 -> V_38 ) ;
}
}
if ( ! V_53 && V_20 -> V_27 )
F_27 ( V_20 ) ;
F_37 ( & V_20 -> V_40 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_63 ;
F_23 ( & V_20 -> V_40 ) ;
F_39 ( & V_17 -> V_33 , & V_20 -> V_52 ) ;
F_36 ( & V_20 -> V_62 ) ;
F_21 ( & V_20 -> V_40 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_63 ;
F_23 ( & V_20 -> V_40 ) ;
F_25 ( & V_17 -> V_33 , & V_20 -> V_25 ) ;
V_20 -> V_30 -- ;
switch ( V_17 -> V_28 ) {
default:
F_32 ( L_8 ,
V_42 , V_15 -> V_43 , V_17 -> V_28 ) ;
case 0 :
F_15 ( V_20 ) ;
break;
case - V_58 :
F_20 ( L_9 , V_42 , V_15 -> V_43 ) ;
break;
}
F_21 ( & V_20 -> V_40 ) ;
}
static void F_41 ( struct V_14 * V_15 , struct V_23 * V_64 ,
int * V_65 )
{
struct V_13 * V_17 ;
while ( ! F_16 ( V_64 ) ) {
V_17 = F_17 ( V_64 -> V_32 , struct V_13 , V_33 ) ;
F_19 ( & V_17 -> V_33 ) ;
F_13 ( V_15 , V_17 ) ;
if ( V_65 )
( * V_65 ) -- ;
}
}
static int F_42 ( struct V_14 * V_15 , struct V_23 * V_64 ,
void (* F_43)( struct V_14 * , struct V_13 * ) ,
int * V_65 )
{
int V_66 ;
struct V_13 * V_17 ;
int V_60 = V_65 ? V_31 - * V_65 : V_31 ;
for ( V_66 = 0 ; V_66 < V_60 ; V_66 ++ ) {
V_17 = F_10 ( V_15 , V_15 -> V_34 , V_41 ) ;
if ( ! V_17 )
return F_16 ( V_64 ) ? - V_6 : 0 ;
V_17 -> V_67 = F_43 ;
F_39 ( & V_17 -> V_33 , V_64 ) ;
if ( V_65 )
( * V_65 ) ++ ;
}
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_23 * V_64 = & V_20 -> V_45 ;
struct V_14 * V_15 = V_20 -> V_27 -> V_46 ;
int V_28 ;
unsigned V_68 ;
V_28 = F_42 ( V_15 , V_64 , F_38 ,
& V_20 -> V_69 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_42 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
F_40 , & V_20 -> V_70 ) ;
if ( V_28 ) {
F_41 ( V_15 , V_64 , & V_20 -> V_69 ) ;
return V_28 ;
}
V_20 -> V_61 = 0 ;
V_68 = F_27 ( V_20 ) ;
if ( V_68 ) {
F_26 ( V_20 -> V_44 ) ;
} else {
F_41 ( V_15 , V_64 , & V_20 -> V_69 ) ;
F_41 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
& V_20 -> V_70 ) ;
V_28 = - V_71 ;
}
return V_28 ;
}
static int F_45 ( struct V_47 * V_48 , struct V_72 * V_72 )
{
int V_38 = V_48 -> V_73 ;
struct V_19 * V_20 ;
int V_28 ;
if ( V_38 < 0 || V_38 >= V_74 )
return - V_75 ;
do {
F_46 ( & V_76 [ V_38 ] . V_77 ) ;
V_20 = V_76 [ V_38 ] . V_20 ;
if ( ! V_20 )
V_28 = - V_78 ;
else {
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_79 ) {
V_28 = 0 ;
V_20 -> V_79 ++ ;
} else if ( V_20 -> V_80 ) {
V_28 = - V_81 ;
} else {
V_28 = - V_82 ;
V_20 -> V_80 = true ;
}
F_37 ( & V_20 -> V_40 ) ;
}
F_47 ( & V_76 [ V_38 ] . V_77 ) ;
switch ( V_28 ) {
default:
return V_28 ;
case - V_82 :
break;
case - V_81 :
F_48 ( 1 ) ;
break;
}
} while ( V_28 != - V_82 );
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_22 . V_4 == NULL ) {
F_37 ( & V_20 -> V_40 ) ;
V_28 = F_1 ( & V_20 -> V_22 , V_83 ) ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_10 ,
V_20 -> V_38 , V_48 , V_72 ) ;
V_20 -> V_80 = false ;
goto V_84;
}
}
V_48 -> V_63 = V_20 ;
V_20 -> V_44 = V_48 ;
V_20 -> V_79 = 1 ;
V_20 -> V_80 = false ;
if ( V_20 -> V_27 ) {
struct V_85 * V_86 = V_20 -> V_27 ;
F_24 ( L_11 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_86 -> V_87 )
V_86 -> V_87 ( V_86 ) ;
}
F_24 ( L_12 , V_20 -> V_38 , V_48 , V_72 ) ;
V_28 = 0 ;
V_84:
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int F_49 ( struct V_19 * V_88 )
{
int V_89 ;
F_29 ( & V_88 -> V_40 ) ;
V_89 = ( V_88 -> V_27 == NULL ) || ! F_6 ( & V_88 -> V_22 ) ;
F_37 ( & V_88 -> V_40 ) ;
return V_89 ;
}
static void F_50 ( struct V_47 * V_48 , struct V_72 * V_72 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
struct V_85 * V_86 ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_79 != 1 ) {
if ( V_20 -> V_79 == 0 )
F_51 ( 1 ) ;
else
-- V_20 -> V_79 ;
goto exit;
}
F_24 ( L_13 , V_20 -> V_38 , V_48 , V_72 ) ;
V_20 -> V_80 = true ;
V_20 -> V_79 = 0 ;
V_86 = V_20 -> V_27 ;
if ( V_86 && V_86 -> V_53 )
V_86 -> V_53 ( V_86 ) ;
if ( F_6 ( & V_20 -> V_22 ) > 0 && V_86 ) {
F_37 ( & V_20 -> V_40 ) ;
F_52 ( V_20 -> V_35 ,
F_49 ( V_20 ) ,
V_90 * V_91 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_86 = V_20 -> V_27 ;
}
if ( V_86 == NULL )
F_3 ( & V_20 -> V_22 ) ;
else
F_5 ( & V_20 -> V_22 ) ;
V_48 -> V_63 = NULL ;
V_20 -> V_44 = NULL ;
V_20 -> V_80 = false ;
F_24 ( L_14 ,
V_20 -> V_38 , V_48 , V_72 ) ;
F_18 ( & V_20 -> V_92 ) ;
exit:
F_37 ( & V_20 -> V_40 ) ;
}
static int F_53 ( struct V_47 * V_48 , const unsigned char * V_10 , int V_11 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
int V_28 ;
F_20 ( L_15 ,
V_20 -> V_38 , V_48 , V_11 ) ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
if ( V_11 )
V_11 = F_8 ( & V_20 -> V_22 , V_10 , V_11 ) ;
if ( V_20 -> V_27 )
V_28 = F_15 ( V_20 ) ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
return V_11 ;
}
static int F_56 ( struct V_47 * V_48 , unsigned char V_93 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
int V_28 ;
F_20 ( L_16 ,
V_20 -> V_38 , V_48 , V_93 , F_57 ( 0 ) ) ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
V_28 = F_8 ( & V_20 -> V_22 , & V_93 , 1 ) ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
return V_28 ;
}
static void F_58 ( struct V_47 * V_48 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
F_20 ( L_17 , V_20 -> V_38 , V_48 ) ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
if ( V_20 -> V_27 )
F_15 ( V_20 ) ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
}
static int F_59 ( struct V_47 * V_48 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
int V_94 = 0 ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
if ( V_20 -> V_27 )
V_94 = F_7 ( & V_20 -> V_22 ) ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
F_20 ( L_18 ,
V_20 -> V_38 , V_48 , V_94 ) ;
return V_94 ;
}
static int F_60 ( struct V_47 * V_48 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
int V_95 = 0 ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
V_95 = F_6 ( & V_20 -> V_22 ) ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
F_20 ( L_19 ,
V_20 -> V_38 , V_48 , V_95 ) ;
return V_95 ;
}
static void F_61 ( struct V_47 * V_48 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
unsigned long V_57 ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
if ( V_20 -> V_27 ) {
F_36 ( & V_20 -> V_62 ) ;
F_20 ( V_37 L_20 , V_20 -> V_38 ) ;
}
F_55 ( & V_20 -> V_40 , V_57 ) ;
}
static int F_62 ( struct V_47 * V_48 , int V_96 )
{
struct V_19 * V_20 = V_48 -> V_63 ;
int V_28 = 0 ;
struct V_85 * V_86 ;
F_20 ( L_21 ,
V_20 -> V_38 , V_96 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_86 = V_20 -> V_27 ;
if ( V_86 && V_86 -> V_97 )
V_28 = V_86 -> V_97 ( V_86 , V_96 ) ;
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int T_2
F_63 ( unsigned V_38 , struct V_98 * V_99 )
{
struct V_19 * V_20 ;
V_20 = F_64 ( sizeof( struct V_19 ) , V_5 ) ;
if ( V_20 == NULL )
return - V_6 ;
F_65 ( & V_20 -> V_40 ) ;
F_66 ( & V_20 -> V_92 ) ;
F_66 ( & V_20 -> V_35 ) ;
F_67 ( & V_20 -> V_62 , F_28 , ( unsigned long ) V_20 ) ;
F_68 ( & V_20 -> V_45 ) ;
F_68 ( & V_20 -> V_52 ) ;
F_68 ( & V_20 -> V_25 ) ;
V_20 -> V_38 = V_38 ;
V_20 -> V_100 = * V_99 ;
V_76 [ V_38 ] . V_20 = V_20 ;
return 0 ;
}
int T_2 F_69 ( struct V_101 * V_102 , unsigned V_11 )
{
unsigned V_66 ;
struct V_98 V_99 ;
int V_28 ;
if ( V_11 == 0 || V_11 > V_103 )
return - V_104 ;
V_105 = F_70 ( V_11 ) ;
if ( ! V_105 )
return - V_6 ;
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = L_22 ;
V_105 -> V_43 = V_37 ;
V_105 -> type = V_109 ;
V_105 -> V_110 = V_111 ;
V_105 -> V_57 = V_112 | V_113 ;
V_105 -> V_114 = V_115 ;
V_105 -> V_114 . V_116 =
V_117 | V_118 | V_119 | V_120 | V_121 ;
V_105 -> V_114 . V_122 = 9600 ;
V_105 -> V_114 . V_123 = 9600 ;
V_99 . V_124 = F_71 ( 9600 ) ;
V_99 . V_125 = 8 ;
V_99 . V_126 = V_127 ;
V_99 . V_128 = V_129 ;
F_72 ( V_105 , & V_130 ) ;
for ( V_66 = 0 ; V_66 < V_11 ; V_66 ++ ) {
F_73 ( & V_76 [ V_66 ] . V_77 ) ;
V_28 = F_63 ( V_66 , & V_99 ) ;
if ( V_28 ) {
V_11 = V_66 ;
goto V_131;
}
}
V_74 = V_11 ;
V_28 = F_74 ( V_105 ) ;
if ( V_28 ) {
F_75 ( L_23 ,
V_42 , V_28 ) ;
goto V_131;
}
for ( V_66 = 0 ; V_66 < V_11 ; V_66 ++ ) {
struct V_132 * V_133 ;
V_133 = F_76 ( V_105 , V_66 , & V_102 -> V_134 ) ;
if ( F_77 ( V_133 ) )
F_32 ( L_24 ,
V_42 , V_66 , F_78 ( V_133 ) ) ;
}
F_24 ( L_25 , V_42 ,
V_11 , ( V_11 == 1 ) ? L_26 : L_27 ) ;
return V_28 ;
V_131:
while ( V_11 -- )
F_4 ( V_76 [ V_11 ] . V_20 ) ;
F_79 ( V_105 ) ;
V_105 = NULL ;
return V_28 ;
}
static int F_80 ( struct V_19 * V_20 )
{
int V_89 ;
F_29 ( & V_20 -> V_40 ) ;
V_89 = ( V_20 -> V_79 == 0 ) && ! V_20 -> V_80 ;
F_37 ( & V_20 -> V_40 ) ;
return V_89 ;
}
void F_81 ( void )
{
unsigned V_66 ;
struct V_19 * V_20 ;
if ( ! V_105 )
return;
for ( V_66 = 0 ; V_66 < V_74 ; V_66 ++ )
F_82 ( V_105 , V_66 ) ;
for ( V_66 = 0 ; V_66 < V_74 ; V_66 ++ ) {
F_46 ( & V_76 [ V_66 ] . V_77 ) ;
V_20 = V_76 [ V_66 ] . V_20 ;
V_76 [ V_66 ] . V_20 = NULL ;
F_47 ( & V_76 [ V_66 ] . V_77 ) ;
F_83 ( & V_20 -> V_62 ) ;
F_84 ( V_20 -> V_92 , F_80 ( V_20 ) ) ;
F_51 ( V_20 -> V_27 != NULL ) ;
F_4 ( V_20 ) ;
}
V_74 = 0 ;
F_85 ( V_105 ) ;
F_79 ( V_105 ) ;
V_105 = NULL ;
F_24 ( L_28 , V_42 ) ;
}
int F_86 ( struct V_85 * V_86 , V_39 V_38 )
{
struct V_19 * V_20 ;
unsigned long V_57 ;
int V_28 ;
if ( ! V_105 || V_38 >= V_74 )
return - V_75 ;
V_20 = V_76 [ V_38 ] . V_20 ;
V_28 = F_87 ( V_86 -> V_26 , V_86 -> V_135 ) ;
if ( V_28 < 0 )
return V_28 ;
V_86 -> V_26 -> V_63 = V_20 ;
V_28 = F_87 ( V_86 -> V_46 , V_86 -> V_136 ) ;
if ( V_28 < 0 )
goto V_137;
V_86 -> V_46 -> V_63 = V_20 ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
V_86 -> V_138 = V_20 ;
V_20 -> V_27 = V_86 ;
V_86 -> V_100 = V_20 -> V_100 ;
if ( V_20 -> V_79 ) {
F_24 ( L_29 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_86 -> V_87 )
V_86 -> V_87 ( V_86 ) ;
} else {
if ( V_86 -> V_53 )
V_86 -> V_53 ( V_86 ) ;
}
F_55 ( & V_20 -> V_40 , V_57 ) ;
return V_28 ;
V_137:
F_88 ( V_86 -> V_26 ) ;
V_86 -> V_26 -> V_63 = NULL ;
return V_28 ;
}
void F_89 ( struct V_85 * V_86 )
{
struct V_19 * V_20 = V_86 -> V_138 ;
unsigned long V_57 ;
if ( ! V_20 )
return;
F_54 ( & V_20 -> V_40 , V_57 ) ;
V_20 -> V_100 = V_86 -> V_100 ;
V_20 -> V_27 = NULL ;
V_86 -> V_138 = NULL ;
if ( V_20 -> V_79 > 0 || V_20 -> V_80 ) {
F_18 ( & V_20 -> V_35 ) ;
if ( V_20 -> V_44 )
F_90 ( V_20 -> V_44 ) ;
}
F_55 ( & V_20 -> V_40 , V_57 ) ;
F_88 ( V_86 -> V_46 ) ;
V_86 -> V_46 -> V_63 = NULL ;
F_88 ( V_86 -> V_26 ) ;
V_86 -> V_26 -> V_63 = NULL ;
F_54 ( & V_20 -> V_40 , V_57 ) ;
if ( V_20 -> V_79 == 0 && ! V_20 -> V_80 )
F_3 ( & V_20 -> V_22 ) ;
F_41 ( V_86 -> V_46 , & V_20 -> V_45 , NULL ) ;
F_41 ( V_86 -> V_46 , & V_20 -> V_52 , NULL ) ;
F_41 ( V_86 -> V_26 , & V_20 -> V_25 , NULL ) ;
V_20 -> V_69 = V_20 -> V_49 =
V_20 -> V_70 = V_20 -> V_30 = 0 ;
F_55 ( & V_20 -> V_40 , V_57 ) ;
}
