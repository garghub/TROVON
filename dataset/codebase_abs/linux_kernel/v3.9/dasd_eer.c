static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < V_2 -> V_4 )
return V_2 -> V_4 - V_2 -> V_3 - 1 ;
return V_2 -> V_5 - V_2 -> V_3 + V_2 -> V_4 - 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return V_2 -> V_3 - V_2 -> V_4 ;
return V_2 -> V_5 - V_2 -> V_4 + V_2 -> V_3 ;
}
static void F_3 ( struct V_1 * V_2 ,
char * V_6 , int V_7 )
{
unsigned long V_8 , V_9 ;
unsigned long V_10 , V_11 ;
char * V_12 ;
V_12 = V_6 ;
V_10 = V_7 ;
while ( V_10 > 0 ) {
V_8 = V_2 -> V_3 / V_13 ;
V_9 = V_2 -> V_3 % V_13 ;
V_11 = F_4 ( V_10 , V_13 - V_9 ) ;
memcpy ( V_2 -> V_14 [ V_8 ] + V_9 , V_12 , V_11 ) ;
V_12 += V_11 ;
V_10 -= V_11 ;
V_2 -> V_3 += V_11 ;
if ( V_2 -> V_3 == V_2 -> V_5 )
V_2 -> V_3 = 0 ;
F_5 ( V_2 -> V_3 > V_2 -> V_5 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , char * V_6 , int V_7 )
{
unsigned long V_15 , V_16 ;
unsigned long V_10 , V_11 , V_17 ;
char * V_12 ;
V_17 = F_4 ( V_7 , F_2 ( V_2 ) ) ;
V_12 = V_6 ;
V_10 = V_17 ;
while ( V_10 > 0 ) {
V_15 = V_2 -> V_4 / V_13 ;
V_16 = V_2 -> V_4 % V_13 ;
V_11 = F_4 ( V_10 , V_13 - V_16 ) ;
memcpy ( V_12 , V_2 -> V_14 [ V_15 ] + V_16 , V_11 ) ;
V_12 += V_11 ;
V_10 -= V_11 ;
V_2 -> V_4 += V_11 ;
if ( V_2 -> V_4 == V_2 -> V_5 )
V_2 -> V_4 = 0 ;
F_5 ( V_2 -> V_4 > V_2 -> V_5 ) ;
}
return V_17 ;
}
static int F_7 ( struct V_1 * V_2 , int V_7 )
{
int V_18 ;
if ( V_7 + sizeof( V_7 ) > V_2 -> V_5 )
return - V_19 ;
while ( F_1 ( V_2 ) < V_7 + sizeof( V_7 ) ) {
if ( V_2 -> V_20 > 0 ) {
V_2 -> V_4 += V_2 -> V_20 ;
if ( V_2 -> V_4 >= V_2 -> V_5 )
V_2 -> V_4 -= V_2 -> V_5 ;
V_2 -> V_20 = - 1 ;
}
F_6 ( V_2 , ( char * ) & V_18 ,
sizeof( V_18 ) ) ;
V_2 -> V_4 += V_18 ;
if ( V_2 -> V_4 >= V_2 -> V_5 )
V_2 -> V_4 -= V_2 -> V_5 ;
}
F_3 ( V_2 , ( char * ) & V_7 , sizeof( V_7 ) ) ;
return 0 ;
}
static void F_8 ( char * * V_21 , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_9 ( ( unsigned long ) V_21 [ V_23 ] ) ;
}
static int F_10 ( char * * V_21 , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_21 [ V_23 ] = ( char * ) F_11 ( V_24 ) ;
if ( ! V_21 [ V_23 ] ) {
F_8 ( V_21 , V_23 ) ;
return - V_19 ;
}
}
return 0 ;
}
static void F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
int V_29 )
{
struct V_27 * V_30 ;
int V_31 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
unsigned long V_36 ;
struct V_1 * V_2 ;
char * V_37 ;
V_31 = 0 ;
for ( V_30 = V_28 ; V_30 ; V_30 = V_30 -> V_38 )
if ( F_13 ( & V_30 -> V_39 ) )
V_31 += 32 ;
V_35 . V_40 = sizeof( V_35 ) + V_31 + 4 ;
V_35 . V_29 = V_29 ;
F_14 ( & V_33 ) ;
V_35 . V_41 = V_33 . V_41 ;
V_35 . V_42 = V_33 . V_42 ;
strncpy ( V_35 . V_43 , F_15 ( & V_26 -> V_44 -> V_45 ) ,
V_46 ) ;
F_16 ( & V_47 , V_36 ) ;
F_17 (eerb, &bufferlist, list) {
F_7 ( V_2 , V_35 . V_40 ) ;
F_3 ( V_2 , ( char * ) & V_35 , sizeof( V_35 ) ) ;
for ( V_30 = V_28 ; V_30 ; V_30 = V_30 -> V_38 ) {
V_37 = F_13 ( & V_30 -> V_39 ) ;
if ( V_37 )
F_3 ( V_2 , V_37 , 32 ) ;
}
F_3 ( V_2 , L_1 , 4 ) ;
}
F_18 ( & V_47 , V_36 ) ;
F_19 ( & V_48 ) ;
}
static void F_20 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
int V_29 )
{
int V_31 ;
int V_49 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
unsigned long V_36 ;
struct V_1 * V_2 ;
V_49 = ( V_28 -> V_50 == V_51 ) ? 0 : - V_52 ;
if ( V_49 )
V_31 = 0 ;
else
V_31 = V_53 ;
V_35 . V_40 = sizeof( V_35 ) + V_31 + 4 ;
V_35 . V_29 = V_54 ;
F_14 ( & V_33 ) ;
V_35 . V_41 = V_33 . V_41 ;
V_35 . V_42 = V_33 . V_42 ;
strncpy ( V_35 . V_43 , F_15 ( & V_26 -> V_44 -> V_45 ) ,
V_46 ) ;
F_16 ( & V_47 , V_36 ) ;
F_17 (eerb, &bufferlist, list) {
F_7 ( V_2 , V_35 . V_40 ) ;
F_3 ( V_2 , ( char * ) & V_35 , sizeof( V_35 ) ) ;
if ( ! V_49 )
F_3 ( V_2 , V_28 -> V_6 , V_53 ) ;
F_3 ( V_2 , L_1 , 4 ) ;
}
F_18 ( & V_47 , V_36 ) ;
F_19 ( & V_48 ) ;
}
void F_21 ( struct V_25 * V_26 , struct V_27 * V_28 ,
unsigned int V_55 )
{
if ( ! V_26 -> V_56 )
return;
switch ( V_55 ) {
case V_57 :
case V_58 :
F_12 ( V_26 , V_28 , V_55 ) ;
break;
case V_59 :
F_12 ( V_26 , NULL , V_55 ) ;
break;
case V_54 :
F_20 ( V_26 , V_28 , V_55 ) ;
break;
default:
F_12 ( V_26 , NULL , V_55 ) ;
break;
}
}
void F_22 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = V_26 -> V_56 ;
if ( ! V_28 )
return;
if ( F_23 ( V_60 , & V_26 -> V_36 ) ) {
F_24 ( V_61 , & V_26 -> V_36 ) ;
return;
}
F_25 ( V_61 , & V_26 -> V_36 ) ;
V_28 -> V_50 = V_62 ;
F_26 ( & V_28 -> V_63 , & V_26 -> V_64 ) ;
F_27 ( V_26 ) ;
}
static void F_28 ( struct V_27 * V_28 , void * V_6 )
{
struct V_25 * V_26 = V_28 -> V_65 ;
unsigned long V_36 ;
F_21 ( V_26 , V_28 , V_54 ) ;
F_16 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
if ( V_26 -> V_56 == V_28 ) {
F_25 ( V_60 , & V_26 -> V_36 ) ;
if ( F_30 ( V_61 , & V_26 -> V_36 ) )
F_22 ( V_26 ) ;
V_28 = NULL ;
}
F_18 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
if ( V_28 )
F_31 ( V_28 , V_26 ) ;
}
int F_32 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
unsigned long V_36 ;
struct V_66 * V_67 ;
if ( V_26 -> V_56 )
return 0 ;
if ( ! V_26 -> V_68 || strcmp ( V_26 -> V_68 -> V_69 , L_2 ) )
return - V_70 ;
V_28 = F_33 ( V_71 , 1 ,
V_53 , V_26 ) ;
if ( F_34 ( V_28 ) )
return - V_19 ;
V_28 -> V_65 = V_26 ;
V_28 -> V_72 = 255 ;
V_28 -> V_73 = 10 * V_74 ;
F_25 ( V_75 , & V_28 -> V_36 ) ;
F_24 ( V_76 , & V_28 -> V_36 ) ;
V_67 = V_28 -> V_77 ;
V_67 -> V_78 = V_79 ;
V_67 -> V_7 = V_53 ;
V_67 -> V_36 = 0 ;
V_67 -> V_80 = ( V_81 ) ( V_82 ) V_28 -> V_6 ;
V_28 -> V_83 = F_35 () ;
V_28 -> V_50 = V_84 ;
V_28 -> V_85 = F_28 ;
F_16 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
if ( ! V_26 -> V_56 ) {
V_26 -> V_56 = V_28 ;
V_28 = NULL ;
}
F_18 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
if ( V_28 )
F_31 ( V_28 , V_26 ) ;
return 0 ;
}
void F_36 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
unsigned long V_36 ;
int V_86 ;
if ( ! V_26 -> V_56 )
return;
F_16 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
V_28 = V_26 -> V_56 ;
V_26 -> V_56 = NULL ;
F_25 ( V_61 , & V_26 -> V_36 ) ;
V_86 = F_37 ( V_60 , & V_26 -> V_36 ) ;
F_18 ( F_29 ( V_26 -> V_44 ) , V_36 ) ;
if ( V_28 && ! V_86 )
F_31 ( V_28 , V_26 ) ;
}
static int F_38 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 ;
unsigned long V_36 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_91 = V_92 ;
if ( V_2 -> V_91 < 1 ||
V_2 -> V_91 > V_93 / V_13 ) {
F_40 ( V_2 ) ;
F_41 ( V_94 , L_3
L_4
L_5 , ( int ) ( V_93 / V_13 ) ) ;
return - V_95 ;
}
V_2 -> V_5 = V_2 -> V_91 * V_13 ;
V_2 -> V_14 = F_42 ( V_2 -> V_91 * sizeof( char * ) ,
V_24 ) ;
if ( ! V_2 -> V_14 ) {
F_40 ( V_2 ) ;
return - V_19 ;
}
if ( F_10 ( V_2 -> V_14 ,
V_2 -> V_91 ) ) {
F_40 ( V_2 -> V_14 ) ;
F_40 ( V_2 ) ;
return - V_19 ;
}
V_90 -> V_96 = V_2 ;
F_16 ( & V_47 , V_36 ) ;
F_26 ( & V_2 -> V_97 , & V_98 ) ;
F_18 ( & V_47 , V_36 ) ;
return F_43 ( V_88 , V_90 ) ;
}
static int F_44 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 ;
unsigned long V_36 ;
V_2 = (struct V_1 * ) V_90 -> V_96 ;
F_16 ( & V_47 , V_36 ) ;
F_45 ( & V_2 -> V_97 ) ;
F_18 ( & V_47 , V_36 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_91 ) ;
F_40 ( V_2 -> V_14 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_89 * V_90 , char T_2 * V_21 ,
T_3 V_7 , T_4 * V_99 )
{
int V_100 , V_101 ;
int V_18 , V_102 ;
unsigned long V_36 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_90 -> V_96 ;
if ( F_47 ( & V_103 ) )
return - V_104 ;
F_16 ( & V_47 , V_36 ) ;
if ( V_2 -> V_20 < 0 ) {
V_2 -> V_20 = 0 ;
F_18 ( & V_47 , V_36 ) ;
F_48 ( & V_103 ) ;
return - V_52 ;
} else if ( V_2 -> V_20 > 0 ) {
V_102 = F_4 ( V_2 -> V_20 , ( int ) V_7 ) ;
V_2 -> V_20 -= V_102 ;
} else {
V_100 = 0 ;
while ( ! V_100 ) {
V_100 = F_6 ( V_2 , ( char * ) & V_18 ,
sizeof( V_18 ) ) ;
if ( ! V_100 ) {
F_18 ( & V_47 , V_36 ) ;
F_48 ( & V_103 ) ;
if ( V_90 -> V_105 & V_106 )
return - V_107 ;
V_101 = F_49 (
V_48 ,
V_2 -> V_3 != V_2 -> V_4 ) ;
if ( V_101 )
return V_101 ;
if ( F_47 ( & V_103 ) )
return - V_104 ;
F_16 ( & V_47 , V_36 ) ;
}
}
F_50 ( V_100 != sizeof( V_18 ) ) ;
V_102 = F_4 ( V_18 , ( int ) V_7 ) ;
V_2 -> V_20 = V_18 - V_102 ;
}
V_100 = F_6 ( V_2 , V_108 , V_102 ) ;
F_50 ( V_100 != V_102 ) ;
F_18 ( & V_47 , V_36 ) ;
if ( F_51 ( V_21 , V_108 , V_102 ) ) {
F_48 ( & V_103 ) ;
return - V_109 ;
}
F_48 ( & V_103 ) ;
return V_102 ;
}
static unsigned int F_52 ( struct V_89 * V_90 , T_5 * V_110 )
{
unsigned int V_111 ;
unsigned long V_36 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_90 -> V_96 ;
F_53 ( V_90 , & V_48 , V_110 ) ;
F_16 ( & V_47 , V_36 ) ;
if ( V_2 -> V_3 != V_2 -> V_4 )
V_111 = V_112 | V_113 ;
else
V_111 = 0 ;
F_18 ( & V_47 , V_36 ) ;
return V_111 ;
}
int T_6 F_54 ( void )
{
int V_101 ;
V_114 = F_39 ( sizeof( * V_114 ) , V_24 ) ;
if ( ! V_114 )
return - V_19 ;
V_114 -> V_115 = V_116 ;
V_114 -> V_69 = L_6 ;
V_114 -> V_117 = & V_118 ;
V_101 = F_55 ( V_114 ) ;
if ( V_101 ) {
F_40 ( V_114 ) ;
V_114 = NULL ;
F_41 ( V_119 , L_7 , L_8
L_9 ) ;
return V_101 ;
}
return 0 ;
}
void F_56 ( void )
{
if ( V_114 ) {
F_57 ( V_114 ) ;
F_40 ( V_114 ) ;
V_114 = NULL ;
}
}
