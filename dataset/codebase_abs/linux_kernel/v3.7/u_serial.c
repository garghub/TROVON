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
if ( V_29 && V_20 -> V_20 . V_44 )
F_26 ( V_20 -> V_20 . V_44 ) ;
return V_28 ;
}
static unsigned F_27 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_45 ;
struct V_14 * V_46 = V_20 -> V_27 -> V_46 ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_28 ;
struct V_47 * V_44 ;
V_44 = V_20 -> V_20 . V_44 ;
if ( ! V_44 )
break;
if ( V_20 -> V_48 >= V_31 )
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
V_20 -> V_48 ++ ;
if ( ! V_20 -> V_27 )
break;
}
return V_20 -> V_48 ;
}
static void F_28 ( unsigned long V_49 )
{
struct V_19 * V_20 = ( void * ) V_49 ;
struct V_47 * V_44 ;
struct V_23 * V_50 = & V_20 -> V_51 ;
bool V_52 = false ;
bool V_53 = false ;
F_29 ( & V_20 -> V_40 ) ;
V_44 = V_20 -> V_20 . V_44 ;
while ( ! F_16 ( V_50 ) ) {
struct V_13 * V_17 ;
V_17 = F_30 ( V_50 , struct V_13 , V_33 ) ;
if ( ! V_44 )
goto V_54;
if ( F_31 ( V_55 , & V_44 -> V_56 ) )
break;
switch ( V_17 -> V_28 ) {
case - V_57 :
V_52 = true ;
F_20 ( V_37 L_4 , V_20 -> V_38 ) ;
break;
default:
F_32 ( V_37 L_5 ,
V_20 -> V_38 , V_17 -> V_28 ) ;
case 0 :
break;
}
if ( V_17 -> V_58 ) {
char * V_21 = V_17 -> V_10 ;
unsigned V_3 = V_17 -> V_58 ;
unsigned V_59 ;
int V_11 ;
V_59 = V_20 -> V_60 ;
if ( V_59 ) {
V_21 += V_59 ;
V_3 -= V_59 ;
}
V_11 = F_33 ( V_44 , V_21 , V_3 ) ;
if ( V_11 )
V_53 = true ;
if ( V_11 != V_3 ) {
V_20 -> V_60 += V_11 ;
F_20 ( V_37 L_6 ,
V_20 -> V_38 ,
V_11 , V_17 -> V_58 ) ;
break;
}
V_20 -> V_60 = 0 ;
}
V_54:
F_34 ( & V_17 -> V_33 , & V_20 -> V_45 ) ;
V_20 -> V_48 -- ;
}
if ( V_44 && V_53 )
F_35 ( V_44 ) ;
if ( ! F_16 ( V_50 ) && V_44 ) {
if ( ! F_31 ( V_55 , & V_44 -> V_56 ) ) {
if ( V_53 )
F_36 ( & V_20 -> V_61 ) ;
else
F_32 ( V_37 L_7 ,
V_20 -> V_38 ) ;
}
}
if ( ! V_52 && V_20 -> V_27 )
F_27 ( V_20 ) ;
F_37 ( & V_20 -> V_40 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_62 ;
F_23 ( & V_20 -> V_40 ) ;
F_39 ( & V_17 -> V_33 , & V_20 -> V_51 ) ;
F_36 ( & V_20 -> V_61 ) ;
F_21 ( & V_20 -> V_40 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_62 ;
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
case - V_57 :
F_20 ( L_9 , V_42 , V_15 -> V_43 ) ;
break;
}
F_21 ( & V_20 -> V_40 ) ;
}
static void F_41 ( struct V_14 * V_15 , struct V_23 * V_63 ,
int * V_64 )
{
struct V_13 * V_17 ;
while ( ! F_16 ( V_63 ) ) {
V_17 = F_17 ( V_63 -> V_32 , struct V_13 , V_33 ) ;
F_19 ( & V_17 -> V_33 ) ;
F_13 ( V_15 , V_17 ) ;
if ( V_64 )
( * V_64 ) -- ;
}
}
static int F_42 ( struct V_14 * V_15 , struct V_23 * V_63 ,
void (* F_43)( struct V_14 * , struct V_13 * ) ,
int * V_64 )
{
int V_65 ;
struct V_13 * V_17 ;
int V_59 = V_64 ? V_31 - * V_64 : V_31 ;
for ( V_65 = 0 ; V_65 < V_59 ; V_65 ++ ) {
V_17 = F_10 ( V_15 , V_15 -> V_34 , V_41 ) ;
if ( ! V_17 )
return F_16 ( V_63 ) ? - V_6 : 0 ;
V_17 -> V_66 = F_43 ;
F_39 ( & V_17 -> V_33 , V_63 ) ;
if ( V_64 )
( * V_64 ) ++ ;
}
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_23 * V_63 = & V_20 -> V_45 ;
struct V_14 * V_15 = V_20 -> V_27 -> V_46 ;
int V_28 ;
unsigned V_67 ;
V_28 = F_42 ( V_15 , V_63 , F_38 ,
& V_20 -> V_68 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_42 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
F_40 , & V_20 -> V_69 ) ;
if ( V_28 ) {
F_41 ( V_15 , V_63 , & V_20 -> V_68 ) ;
return V_28 ;
}
V_20 -> V_60 = 0 ;
V_67 = F_27 ( V_20 ) ;
if ( V_67 ) {
F_26 ( V_20 -> V_20 . V_44 ) ;
} else {
F_41 ( V_15 , V_63 , & V_20 -> V_68 ) ;
F_41 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
& V_20 -> V_69 ) ;
V_28 = - V_70 ;
}
return V_28 ;
}
static int F_45 ( struct V_47 * V_44 , struct V_71 * V_71 )
{
int V_38 = V_44 -> V_72 ;
struct V_19 * V_20 ;
int V_28 ;
do {
F_46 ( & V_73 [ V_38 ] . V_74 ) ;
V_20 = V_73 [ V_38 ] . V_20 ;
if ( ! V_20 )
V_28 = - V_75 ;
else {
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 ) {
V_28 = 0 ;
V_20 -> V_20 . V_11 ++ ;
} else if ( V_20 -> V_76 ) {
V_28 = - V_77 ;
} else {
V_28 = - V_78 ;
V_20 -> V_76 = true ;
}
F_37 ( & V_20 -> V_40 ) ;
}
F_47 ( & V_73 [ V_38 ] . V_74 ) ;
switch ( V_28 ) {
default:
return V_28 ;
case - V_78 :
break;
case - V_77 :
F_48 ( 1 ) ;
break;
}
} while ( V_28 != - V_78 );
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_22 . V_4 == NULL ) {
F_37 ( & V_20 -> V_40 ) ;
V_28 = F_1 ( & V_20 -> V_22 , V_79 ) ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_28 ) {
F_24 ( L_10 ,
V_20 -> V_38 , V_44 , V_71 ) ;
V_20 -> V_76 = false ;
goto V_80;
}
}
V_44 -> V_62 = V_20 ;
V_20 -> V_20 . V_44 = V_44 ;
V_20 -> V_20 . V_11 = 1 ;
V_20 -> V_76 = false ;
if ( V_20 -> V_27 ) {
struct V_81 * V_82 = V_20 -> V_27 ;
F_24 ( L_11 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 ) ;
}
F_24 ( L_12 , V_20 -> V_38 , V_44 , V_71 ) ;
V_28 = 0 ;
V_80:
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int F_49 ( struct V_19 * V_84 )
{
int V_85 ;
F_29 ( & V_84 -> V_40 ) ;
V_85 = ( V_84 -> V_27 == NULL ) || ! F_6 ( & V_84 -> V_22 ) ;
F_37 ( & V_84 -> V_40 ) ;
return V_85 ;
}
static void F_50 ( struct V_47 * V_44 , struct V_71 * V_71 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
struct V_81 * V_82 ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 != 1 ) {
if ( V_20 -> V_20 . V_11 == 0 )
F_51 ( 1 ) ;
else
-- V_20 -> V_20 . V_11 ;
goto exit;
}
F_24 ( L_13 , V_20 -> V_38 , V_44 , V_71 ) ;
V_20 -> V_76 = true ;
V_20 -> V_20 . V_11 = 0 ;
V_82 = V_20 -> V_27 ;
if ( V_82 && V_82 -> V_52 )
V_82 -> V_52 ( V_82 ) ;
if ( F_6 ( & V_20 -> V_22 ) > 0 && V_82 ) {
F_37 ( & V_20 -> V_40 ) ;
F_52 ( V_20 -> V_35 ,
F_49 ( V_20 ) ,
V_86 * V_87 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_82 = V_20 -> V_27 ;
}
if ( V_82 == NULL )
F_3 ( & V_20 -> V_22 ) ;
else
F_5 ( & V_20 -> V_22 ) ;
V_44 -> V_62 = NULL ;
V_20 -> V_20 . V_44 = NULL ;
V_20 -> V_76 = false ;
F_24 ( L_14 ,
V_20 -> V_38 , V_44 , V_71 ) ;
F_18 ( & V_20 -> V_20 . V_88 ) ;
exit:
F_37 ( & V_20 -> V_40 ) ;
}
static int F_53 ( struct V_47 * V_44 , const unsigned char * V_10 , int V_11 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
int V_28 ;
F_20 ( L_15 ,
V_20 -> V_38 , V_44 , V_11 ) ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
if ( V_11 )
V_11 = F_8 ( & V_20 -> V_22 , V_10 , V_11 ) ;
if ( V_20 -> V_27 )
V_28 = F_15 ( V_20 ) ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
return V_11 ;
}
static int F_56 ( struct V_47 * V_44 , unsigned char V_89 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
int V_28 ;
F_20 ( L_16 ,
V_20 -> V_38 , V_44 , V_89 , F_57 ( 0 ) ) ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
V_28 = F_8 ( & V_20 -> V_22 , & V_89 , 1 ) ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
return V_28 ;
}
static void F_58 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
F_20 ( L_17 , V_20 -> V_38 , V_44 ) ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
if ( V_20 -> V_27 )
F_15 ( V_20 ) ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
}
static int F_59 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
int V_90 = 0 ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
if ( V_20 -> V_27 )
V_90 = F_7 ( & V_20 -> V_22 ) ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
F_20 ( L_18 ,
V_20 -> V_38 , V_44 , V_90 ) ;
return V_90 ;
}
static int F_60 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
int V_91 = 0 ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
V_91 = F_6 ( & V_20 -> V_22 ) ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
F_20 ( L_19 ,
V_20 -> V_38 , V_44 , V_91 ) ;
return V_91 ;
}
static void F_61 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
unsigned long V_56 ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
if ( V_20 -> V_27 ) {
F_36 ( & V_20 -> V_61 ) ;
F_20 ( V_37 L_20 , V_20 -> V_38 ) ;
}
F_55 ( & V_20 -> V_40 , V_56 ) ;
}
static int F_62 ( struct V_47 * V_44 , int V_92 )
{
struct V_19 * V_20 = V_44 -> V_62 ;
int V_28 = 0 ;
struct V_81 * V_82 ;
F_20 ( L_21 ,
V_20 -> V_38 , V_92 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_82 = V_20 -> V_27 ;
if ( V_82 && V_82 -> V_93 )
V_28 = V_82 -> V_93 ( V_82 , V_92 ) ;
F_37 ( & V_20 -> V_40 ) ;
return V_28 ;
}
static int
F_63 ( unsigned V_38 , struct V_94 * V_95 )
{
struct V_19 * V_20 ;
V_20 = F_64 ( sizeof( struct V_19 ) , V_5 ) ;
if ( V_20 == NULL )
return - V_6 ;
F_65 ( & V_20 -> V_20 ) ;
F_66 ( & V_20 -> V_40 ) ;
F_67 ( & V_20 -> V_35 ) ;
F_68 ( & V_20 -> V_61 , F_28 , ( unsigned long ) V_20 ) ;
F_69 ( & V_20 -> V_45 ) ;
F_69 ( & V_20 -> V_51 ) ;
F_69 ( & V_20 -> V_25 ) ;
V_20 -> V_38 = V_38 ;
V_20 -> V_96 = * V_95 ;
V_73 [ V_38 ] . V_20 = V_20 ;
return 0 ;
}
int F_70 ( struct V_97 * V_98 , unsigned V_11 )
{
unsigned V_65 ;
struct V_94 V_95 ;
int V_28 ;
if ( V_11 == 0 || V_11 > V_99 )
return - V_100 ;
V_101 = F_71 ( V_11 ) ;
if ( ! V_101 )
return - V_6 ;
V_101 -> V_102 = L_22 ;
V_101 -> V_43 = V_37 ;
V_101 -> type = V_103 ;
V_101 -> V_104 = V_105 ;
V_101 -> V_56 = V_106 | V_107 ;
V_101 -> V_108 = V_109 ;
V_101 -> V_108 . V_110 =
V_111 | V_112 | V_113 | V_114 | V_115 ;
V_101 -> V_108 . V_116 = 9600 ;
V_101 -> V_108 . V_117 = 9600 ;
V_95 . V_118 = F_72 ( 9600 ) ;
V_95 . V_119 = 8 ;
V_95 . V_120 = V_121 ;
V_95 . V_122 = V_123 ;
F_73 ( V_101 , & V_124 ) ;
for ( V_65 = 0 ; V_65 < V_11 ; V_65 ++ ) {
F_74 ( & V_73 [ V_65 ] . V_74 ) ;
V_28 = F_63 ( V_65 , & V_95 ) ;
if ( V_28 ) {
V_11 = V_65 ;
goto V_125;
}
}
V_126 = V_11 ;
V_28 = F_75 ( V_101 ) ;
if ( V_28 ) {
F_76 ( L_23 ,
V_42 , V_28 ) ;
goto V_125;
}
for ( V_65 = 0 ; V_65 < V_11 ; V_65 ++ ) {
struct V_127 * V_128 ;
V_128 = F_77 ( & V_73 [ V_65 ] . V_20 -> V_20 ,
V_101 , V_65 , & V_98 -> V_129 ) ;
if ( F_78 ( V_128 ) )
F_32 ( L_24 ,
V_42 , V_65 , F_79 ( V_128 ) ) ;
}
F_24 ( L_25 , V_42 ,
V_11 , ( V_11 == 1 ) ? L_26 : L_27 ) ;
return V_28 ;
V_125:
while ( V_11 -- )
F_4 ( V_73 [ V_11 ] . V_20 ) ;
F_80 ( V_101 ) ;
V_101 = NULL ;
return V_28 ;
}
static int F_81 ( struct V_19 * V_20 )
{
int V_85 ;
F_29 ( & V_20 -> V_40 ) ;
V_85 = ( V_20 -> V_20 . V_11 == 0 ) && ! V_20 -> V_76 ;
F_37 ( & V_20 -> V_40 ) ;
return V_85 ;
}
void F_82 ( void )
{
unsigned V_65 ;
struct V_19 * V_20 ;
if ( ! V_101 )
return;
for ( V_65 = 0 ; V_65 < V_126 ; V_65 ++ )
F_83 ( V_101 , V_65 ) ;
for ( V_65 = 0 ; V_65 < V_126 ; V_65 ++ ) {
F_46 ( & V_73 [ V_65 ] . V_74 ) ;
V_20 = V_73 [ V_65 ] . V_20 ;
V_73 [ V_65 ] . V_20 = NULL ;
F_47 ( & V_73 [ V_65 ] . V_74 ) ;
F_84 ( & V_20 -> V_61 ) ;
F_85 ( V_20 -> V_20 . V_88 , F_81 ( V_20 ) ) ;
F_51 ( V_20 -> V_27 != NULL ) ;
F_4 ( V_20 ) ;
}
V_126 = 0 ;
F_86 ( V_101 ) ;
F_80 ( V_101 ) ;
V_101 = NULL ;
F_24 ( L_28 , V_42 ) ;
}
int F_87 ( struct V_81 * V_82 , V_39 V_38 )
{
struct V_19 * V_20 ;
unsigned long V_56 ;
int V_28 ;
if ( ! V_101 || V_38 >= V_126 )
return - V_130 ;
V_20 = V_73 [ V_38 ] . V_20 ;
V_28 = F_88 ( V_82 -> V_26 ) ;
if ( V_28 < 0 )
return V_28 ;
V_82 -> V_26 -> V_62 = V_20 ;
V_28 = F_88 ( V_82 -> V_46 ) ;
if ( V_28 < 0 )
goto V_131;
V_82 -> V_46 -> V_62 = V_20 ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
V_82 -> V_132 = V_20 ;
V_20 -> V_27 = V_82 ;
V_82 -> V_96 = V_20 -> V_96 ;
if ( V_20 -> V_20 . V_11 ) {
F_24 ( L_29 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_82 -> V_83 )
V_82 -> V_83 ( V_82 ) ;
} else {
if ( V_82 -> V_52 )
V_82 -> V_52 ( V_82 ) ;
}
F_55 ( & V_20 -> V_40 , V_56 ) ;
return V_28 ;
V_131:
F_89 ( V_82 -> V_26 ) ;
V_82 -> V_26 -> V_62 = NULL ;
return V_28 ;
}
void F_90 ( struct V_81 * V_82 )
{
struct V_19 * V_20 = V_82 -> V_132 ;
unsigned long V_56 ;
if ( ! V_20 )
return;
F_54 ( & V_20 -> V_40 , V_56 ) ;
V_20 -> V_96 = V_82 -> V_96 ;
V_20 -> V_27 = NULL ;
V_82 -> V_132 = NULL ;
if ( V_20 -> V_20 . V_11 > 0 || V_20 -> V_76 ) {
F_18 ( & V_20 -> V_35 ) ;
if ( V_20 -> V_20 . V_44 )
F_91 ( V_20 -> V_20 . V_44 ) ;
}
F_55 ( & V_20 -> V_40 , V_56 ) ;
F_89 ( V_82 -> V_46 ) ;
V_82 -> V_46 -> V_62 = NULL ;
F_89 ( V_82 -> V_26 ) ;
V_82 -> V_26 -> V_62 = NULL ;
F_54 ( & V_20 -> V_40 , V_56 ) ;
if ( V_20 -> V_20 . V_11 == 0 && ! V_20 -> V_76 )
F_3 ( & V_20 -> V_22 ) ;
F_41 ( V_82 -> V_46 , & V_20 -> V_45 , NULL ) ;
F_41 ( V_82 -> V_46 , & V_20 -> V_51 , NULL ) ;
F_41 ( V_82 -> V_26 , & V_20 -> V_25 , NULL ) ;
V_20 -> V_68 = V_20 -> V_48 =
V_20 -> V_69 = V_20 -> V_30 = 0 ;
F_55 ( & V_20 -> V_40 , V_56 ) ;
}
