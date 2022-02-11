static inline struct V_1 * F_1 ( const struct V_2 * V_3 ,
unsigned int V_4 )
{
return (struct V_1 * )
( V_3 -> V_5 [ V_4 / V_6 ] . V_7 + V_4 % V_6 ) ;
}
static unsigned int F_2 ( const struct V_2 * V_8 ,
unsigned int V_9 , const unsigned char * V_10 , unsigned int V_11 )
{
unsigned int V_12 ;
unsigned char * V_13 ;
unsigned int V_14 ;
while ( V_11 ) {
V_12 = V_11 ;
V_14 = V_6 - ( V_9 & ( V_6 - 1 ) ) ;
if ( V_14 < V_12 )
V_12 = V_14 ;
V_13 = V_8 -> V_5 [ V_9 / V_6 ] . V_7 + V_9 % V_6 ;
memcpy ( V_13 , V_10 , V_12 ) ;
if ( ( V_9 += V_12 ) >= V_8 -> V_15 ) V_9 = 0 ;
V_10 += V_12 ;
V_11 -= V_12 ;
}
return V_9 ;
}
static int F_3 ( const struct V_2 * V_8 , unsigned int V_9 ,
char T_1 * V_16 , int V_11 )
{
unsigned int V_12 ;
unsigned char * V_13 ;
unsigned int V_14 ;
while ( V_11 ) {
V_12 = V_11 ;
V_14 = V_6 - ( V_9 & ( V_6 - 1 ) ) ;
if ( V_14 < V_12 )
V_12 = V_14 ;
V_13 = V_8 -> V_5 [ V_9 / V_6 ] . V_7 + V_9 % V_6 ;
if ( F_4 ( V_16 , V_13 , V_12 ) )
return - V_17 ;
if ( ( V_9 += V_12 ) >= V_8 -> V_15 ) V_9 = 0 ;
V_16 += V_12 ;
V_11 -= V_12 ;
}
return 0 ;
}
static unsigned int F_5 ( struct V_2 * V_3 ,
unsigned int V_18 )
{
unsigned int V_4 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( V_3 -> V_20 + V_18 > V_3 -> V_15 )
return ~ 0 ;
V_4 = V_3 -> V_21 ;
V_3 -> V_20 += V_18 ;
if ( ( V_3 -> V_21 += V_18 ) >= V_3 -> V_15 )
V_3 -> V_21 -= V_3 -> V_15 ;
return V_4 ;
}
static unsigned int F_6 ( struct V_2 * V_3 ,
unsigned int V_18 )
{
unsigned int V_4 ;
unsigned int V_22 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( V_3 -> V_20 + V_18 > V_3 -> V_15 )
return ~ 0 ;
if ( V_3 -> V_21 + V_18 > V_3 -> V_15 ) {
V_22 = V_3 -> V_15 - V_3 -> V_21 ;
if ( V_3 -> V_20 + V_18 + V_22 > V_3 -> V_15 )
return ~ 0 ;
F_7 ( V_3 , V_3 -> V_21 , V_22 ) ;
V_4 = 0 ;
V_3 -> V_21 = V_18 ;
V_3 -> V_20 += V_18 + V_22 ;
} else if ( V_3 -> V_21 + V_18 == V_3 -> V_15 ) {
V_4 = V_3 -> V_21 ;
V_3 -> V_21 = 0 ;
V_3 -> V_20 += V_18 ;
} else {
V_4 = V_3 -> V_21 ;
V_3 -> V_21 += V_18 ;
V_3 -> V_20 += V_18 ;
}
return V_4 ;
}
static void F_8 ( struct V_2 * V_3 , unsigned int V_18 )
{
V_3 -> V_20 -= V_18 ;
if ( V_3 -> V_21 < V_18 )
V_3 -> V_21 += V_3 -> V_15 ;
V_3 -> V_21 -= V_18 ;
}
static void F_9 ( struct V_2 * V_3 , unsigned int V_18 )
{
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
V_3 -> V_20 -= V_18 ;
if ( ( V_3 -> V_23 += V_18 ) >= V_3 -> V_15 )
V_3 -> V_23 -= V_3 -> V_15 ;
}
static void F_7 ( const struct V_2 * V_3 ,
unsigned int V_4 , unsigned int V_18 )
{
struct V_1 * V_24 ;
V_24 = F_1 ( V_3 , V_4 ) ;
memset ( V_24 , 0 , V_25 ) ;
V_24 -> type = '@' ;
V_24 -> V_26 = V_18 - V_25 ;
}
static inline char F_10 ( unsigned char * V_27 ,
const struct V_28 * V_28 , char V_29 )
{
if ( V_28 -> V_30 == NULL )
return 'Z' ;
memcpy ( V_27 , V_28 -> V_30 , V_31 ) ;
return 0 ;
}
static unsigned int F_11 ( const struct V_2 * V_3 ,
unsigned int V_4 , struct V_28 * V_28 , unsigned int V_11 ,
char * V_32 )
{
int V_33 ;
struct V_34 * V_35 ;
unsigned int V_36 ;
* V_32 = 0 ;
if ( V_28 -> V_37 == 0 ) {
if ( V_28 -> V_38 == NULL ) {
* V_32 = 'Z' ;
return V_11 ;
}
F_2 ( V_3 , V_4 , V_28 -> V_38 , V_11 ) ;
V_11 = 0 ;
} else {
if ( V_28 -> V_39 & V_40 ) {
* V_32 = 'D' ;
return V_11 ;
}
F_12 (urb->sg, sg, urb->num_sgs, i) {
if ( V_11 == 0 || F_13 ( F_14 ( V_35 ) ) )
break;
V_36 = F_15 (unsigned int, sg->length, length) ;
V_4 = F_2 ( V_3 , V_4 , F_16 ( V_35 ) ,
V_36 ) ;
V_11 -= V_36 ;
}
if ( V_33 == 0 )
* V_32 = 'D' ;
}
return V_11 ;
}
static unsigned int F_17 ( const struct V_2 * V_3 ,
struct V_28 * V_28 , unsigned int V_41 )
{
struct V_42 * V_43 ;
unsigned int V_11 ;
V_11 = 0 ;
V_43 = V_28 -> V_44 ;
while ( V_41 -- != 0 ) {
if ( V_43 -> V_45 != 0 ) {
if ( V_43 -> V_4 + V_43 -> V_45 > V_11 )
V_11 = V_43 -> V_4 + V_43 -> V_45 ;
}
V_43 ++ ;
}
return V_11 ;
}
static void F_18 ( const struct V_2 * V_3 ,
unsigned int V_4 , struct V_28 * V_28 , char V_29 , unsigned int V_41 )
{
struct V_46 * V_47 ;
struct V_42 * V_43 ;
V_43 = V_28 -> V_44 ;
while ( V_41 -- != 0 ) {
V_47 = (struct V_46 * )
( V_3 -> V_5 [ V_4 / V_6 ] . V_7 + V_4 % V_6 ) ;
V_47 -> V_48 = V_43 -> V_49 ;
V_47 -> V_50 = V_43 -> V_4 ;
V_47 -> V_51 = ( V_29 == 'S' ) ? V_43 -> V_11 : V_43 -> V_45 ;
V_47 -> V_52 = 0 ;
if ( ( V_4 += sizeof( struct V_46 ) ) >= V_3 -> V_15 )
V_4 = 0 ;
V_43 ++ ;
}
}
static void F_19 ( struct V_2 * V_3 , struct V_28 * V_28 ,
char V_29 , int V_49 )
{
const struct V_53 * V_54 = & V_28 -> V_24 -> V_55 ;
struct V_56 V_57 ;
unsigned long V_58 ;
unsigned int V_59 ;
unsigned int V_4 ;
unsigned int V_11 ;
unsigned int V_60 ;
unsigned int V_41 , V_61 ;
unsigned char V_62 ;
struct V_1 * V_24 ;
char V_63 = 0 ;
F_20 ( & V_57 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_59 = ( V_29 == 'S' ) ?
V_28 -> V_65 : V_28 -> V_45 ;
V_11 = V_59 ;
if ( F_22 ( V_54 ) ) {
if ( V_28 -> V_66 < 0 ) {
V_41 = 0 ;
} else if ( V_28 -> V_66 >= V_67 ) {
V_41 = V_67 ;
} else {
V_41 = V_28 -> V_66 ;
}
if ( V_29 == 'C' && F_23 ( V_28 ) )
V_11 = F_17 ( V_3 , V_28 , V_41 ) ;
} else {
V_41 = 0 ;
}
V_61 = V_41 * sizeof( struct V_46 ) ;
if ( V_11 >= V_28 -> V_65 )
V_11 = V_28 -> V_65 ;
if ( V_11 >= V_3 -> V_15 / 5 )
V_11 = V_3 -> V_15 / 5 ;
if ( F_23 ( V_28 ) ) {
if ( V_29 == 'S' ) {
V_11 = 0 ;
V_63 = '<' ;
}
V_62 = V_68 ;
} else {
if ( V_29 == 'C' ) {
V_11 = 0 ;
V_63 = '>' ;
}
V_62 = 0 ;
}
if ( V_3 -> V_69 ) {
V_4 = F_6 ( V_3 ,
V_11 + V_25 + V_61 ) ;
} else {
V_4 = F_5 ( V_3 , V_11 + V_25 + V_61 ) ;
}
if ( V_4 == ~ 0 ) {
V_3 -> V_70 ++ ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
return;
}
V_24 = F_1 ( V_3 , V_4 ) ;
if ( ( V_4 += V_25 ) >= V_3 -> V_15 ) V_4 = 0 ;
memset ( V_24 , 0 , V_25 ) ;
V_24 -> type = V_29 ;
V_24 -> V_71 = V_72 [ F_25 ( V_54 ) ] ;
V_24 -> V_73 = V_62 | F_26 ( V_54 ) ;
V_24 -> V_74 = V_28 -> V_75 -> V_74 ;
V_24 -> V_76 = V_28 -> V_75 -> V_77 -> V_76 ;
V_24 -> V_78 = ( unsigned long ) V_28 ;
V_24 -> V_79 = V_57 . V_80 ;
V_24 -> V_81 = V_57 . V_82 ;
V_24 -> V_49 = V_49 ;
V_24 -> V_83 = V_59 ;
V_24 -> V_26 = V_11 + V_61 ;
V_24 -> V_84 = V_28 -> V_39 ;
if ( F_27 ( V_54 ) ) {
V_24 -> V_85 = V_28 -> V_85 ;
} else if ( F_22 ( V_54 ) ) {
V_24 -> V_85 = V_28 -> V_85 ;
V_24 -> V_86 = V_28 -> V_86 ;
V_24 -> V_87 . V_88 . V_89 = V_28 -> V_89 ;
V_24 -> V_87 . V_88 . V_90 = V_28 -> V_66 ;
}
if ( F_28 ( V_54 ) && V_29 == 'S' ) {
V_24 -> V_91 = F_10 ( V_24 -> V_87 . V_92 , V_28 , V_29 ) ;
} else {
V_24 -> V_91 = '-' ;
}
if ( V_41 != 0 ) {
V_24 -> V_41 = V_41 ;
F_18 ( V_3 , V_4 , V_28 , V_29 , V_41 ) ;
if ( ( V_4 += V_61 ) >= V_3 -> V_15 )
V_4 -= V_3 -> V_15 ;
}
if ( V_11 != 0 ) {
V_11 = F_11 ( V_3 , V_4 , V_28 , V_11 ,
& V_24 -> V_93 ) ;
if ( V_11 > 0 ) {
V_60 = ( V_24 -> V_26 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
V_24 -> V_26 -= V_11 ;
V_60 -= ( V_24 -> V_26 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
F_8 ( V_3 , V_60 ) ;
}
} else {
V_24 -> V_93 = V_63 ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_29 ( & V_3 -> V_94 ) ;
}
static void F_30 ( void * V_95 , struct V_28 * V_28 )
{
struct V_2 * V_3 = V_95 ;
F_19 ( V_3 , V_28 , 'S' , - V_96 ) ;
}
static void F_31 ( void * V_95 , struct V_28 * V_28 , int V_49 )
{
struct V_2 * V_3 = V_95 ;
F_19 ( V_3 , V_28 , 'C' , V_49 ) ;
}
static void F_32 ( void * V_95 , struct V_28 * V_28 , int error )
{
struct V_2 * V_3 = V_95 ;
struct V_56 V_57 ;
unsigned long V_58 ;
unsigned int V_4 ;
struct V_1 * V_24 ;
F_20 ( & V_57 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_4 = F_5 ( V_3 , V_25 ) ;
if ( V_4 == ~ 0 ) {
F_24 ( & V_3 -> V_64 , V_58 ) ;
return;
}
V_24 = F_1 ( V_3 , V_4 ) ;
memset ( V_24 , 0 , V_25 ) ;
V_24 -> type = 'E' ;
V_24 -> V_71 = V_72 [ F_25 ( & V_28 -> V_24 -> V_55 ) ] ;
V_24 -> V_73 = F_23 ( V_28 ) ? V_68 : 0 ;
V_24 -> V_73 |= F_26 ( & V_28 -> V_24 -> V_55 ) ;
V_24 -> V_74 = V_28 -> V_75 -> V_74 ;
V_24 -> V_76 = V_28 -> V_75 -> V_77 -> V_76 ;
V_24 -> V_78 = ( unsigned long ) V_28 ;
V_24 -> V_79 = V_57 . V_80 ;
V_24 -> V_81 = V_57 . V_82 ;
V_24 -> V_49 = error ;
V_24 -> V_91 = '-' ;
V_24 -> V_93 = 'E' ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_29 ( & V_3 -> V_94 ) ;
}
static int F_33 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
struct V_99 * V_100 ;
struct V_2 * V_3 ;
T_2 V_18 ;
int V_101 ;
F_34 ( & V_102 ) ;
if ( ( V_100 = F_35 ( F_36 ( V_97 ) ) ) == NULL ) {
F_37 ( & V_102 ) ;
return - V_103 ;
}
if ( V_100 != & V_104 && V_100 -> V_105 == NULL ) {
F_38 (KERN_ERR TAG L_1 ) ;
F_37 ( & V_102 ) ;
return - V_103 ;
}
V_3 = F_39 ( sizeof( struct V_2 ) , V_106 ) ;
if ( V_3 == NULL ) {
V_101 = - V_107 ;
goto V_108;
}
F_40 ( & V_3 -> V_64 ) ;
F_41 ( & V_3 -> V_94 ) ;
F_42 ( & V_3 -> V_109 ) ;
V_3 -> V_15 = V_110 ;
V_18 = sizeof( struct V_111 ) * ( V_3 -> V_15 / V_6 ) ;
if ( ( V_3 -> V_5 = F_39 ( V_18 , V_106 ) ) == NULL ) {
V_101 = - V_107 ;
goto V_112;
}
if ( ( V_101 = F_43 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ) < 0 )
goto V_113;
V_3 -> V_114 . V_115 = V_100 ;
V_3 -> V_114 . V_116 = V_3 ;
V_3 -> V_114 . V_117 = F_30 ;
V_3 -> V_114 . V_118 = F_32 ;
V_3 -> V_114 . V_119 = F_31 ;
F_44 ( V_100 , & V_3 -> V_114 ) ;
V_98 -> V_120 = V_3 ;
F_37 ( & V_102 ) ;
return 0 ;
V_113:
F_45 ( V_3 -> V_5 ) ;
V_112:
F_45 ( V_3 ) ;
V_108:
F_37 ( & V_102 ) ;
return V_101 ;
}
static int F_46 ( struct V_98 * V_98 , struct V_2 * V_3 ,
struct V_1 T_1 * V_121 , unsigned int V_122 ,
void T_1 * V_95 , unsigned int V_123 )
{
unsigned long V_58 ;
struct V_1 * V_24 ;
T_2 V_12 ;
unsigned int V_4 ;
int V_101 ;
F_34 ( & V_3 -> V_109 ) ;
if ( ( V_101 = F_47 ( V_98 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_109 ) ;
return V_101 ;
}
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
if ( F_4 ( V_121 , V_24 , V_122 ) ) {
F_37 ( & V_3 -> V_109 ) ;
return - V_124 ;
}
V_12 = F_48 ( V_24 -> V_26 , V_123 ) ;
if ( ( V_4 = V_3 -> V_23 + V_25 ) >= V_3 -> V_15 ) V_4 = 0 ;
if ( F_3 ( V_3 , V_4 , V_95 , V_12 ) ) {
F_37 ( & V_3 -> V_109 ) ;
return - V_124 ;
}
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_125 = 0 ;
F_37 ( & V_3 -> V_109 ) ;
return 0 ;
}
static int F_49 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
struct V_2 * V_3 = V_98 -> V_120 ;
struct V_99 * V_100 = V_3 -> V_114 . V_115 ;
F_34 ( & V_102 ) ;
if ( V_100 -> V_126 <= 0 ) {
F_38 (KERN_ERR TAG L_2 ) ;
F_37 ( & V_102 ) ;
return 0 ;
}
F_50 ( V_100 , & V_3 -> V_114 ) ;
F_51 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ;
F_45 ( V_3 -> V_5 ) ;
F_45 ( V_3 ) ;
F_37 ( & V_102 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_98 * V_98 , char T_1 * V_13 ,
T_2 V_123 , T_4 * V_127 )
{
struct V_2 * V_3 = V_98 -> V_120 ;
unsigned int V_122 = V_128 ;
unsigned long V_58 ;
struct V_1 * V_24 ;
unsigned int V_4 ;
T_2 V_12 ;
char * V_7 ;
T_3 V_129 = 0 ;
int V_101 ;
F_34 ( & V_3 -> V_109 ) ;
if ( ( V_101 = F_47 ( V_98 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_109 ) ;
return V_101 ;
}
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
if ( V_3 -> V_125 < V_122 ) {
V_12 = F_48 ( V_123 , ( T_2 ) ( V_122 - V_3 -> V_125 ) ) ;
V_7 = ( ( char * ) V_24 ) + V_3 -> V_125 ;
if ( V_12 && F_4 ( V_13 , V_7 , V_12 ) ) {
F_37 ( & V_3 -> V_109 ) ;
return - V_124 ;
}
V_123 -= V_12 ;
V_13 += V_12 ;
V_3 -> V_125 += V_12 ;
V_129 += V_12 ;
}
if ( V_3 -> V_125 >= V_122 ) {
V_12 = V_24 -> V_26 ;
V_12 -= V_3 -> V_125 - V_122 ;
if ( V_12 > V_123 )
V_12 = V_123 ;
V_4 = V_3 -> V_23 + V_25 ;
V_4 += V_3 -> V_125 - V_122 ;
if ( V_4 >= V_3 -> V_15 )
V_4 -= V_3 -> V_15 ;
if ( F_3 ( V_3 , V_4 , V_13 , V_12 ) ) {
F_37 ( & V_3 -> V_109 ) ;
return - V_124 ;
}
V_123 -= V_12 ;
V_13 += V_12 ;
V_3 -> V_125 += V_12 ;
V_129 += V_12 ;
}
if ( V_3 -> V_125 >= V_122 + V_24 -> V_26 ) {
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_125 = 0 ;
}
F_37 ( & V_3 -> V_109 ) ;
return V_129 ;
}
static int F_53 ( struct V_2 * V_3 , unsigned V_130 )
{
unsigned long V_58 ;
struct V_1 * V_24 ;
int V_33 ;
F_34 ( & V_3 -> V_109 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
for ( V_33 = 0 ; V_33 < V_130 ; ++ V_33 ) {
if ( F_54 ( V_3 ) )
break;
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_125 = 0 ;
F_37 ( & V_3 -> V_109 ) ;
return V_33 ;
}
static int F_55 ( struct V_98 * V_98 , struct V_2 * V_3 ,
T_5 T_1 * V_131 , unsigned int V_132 )
{
unsigned int V_133 ;
unsigned int V_134 , V_135 ;
unsigned int V_18 ;
unsigned int V_130 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
int V_101 ;
F_34 ( & V_3 -> V_109 ) ;
if ( ( V_101 = F_47 ( V_98 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_109 ) ;
return V_101 ;
}
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_135 = V_3 -> V_20 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_133 = V_3 -> V_23 ;
V_130 = 0 ;
V_134 = 0 ;
while ( V_134 < V_135 ) {
if ( V_130 >= V_132 )
break;
V_24 = F_1 ( V_3 , V_133 ) ;
if ( F_56 ( V_133 , & V_131 [ V_130 ] ) ) {
F_37 ( & V_3 -> V_109 ) ;
return - V_124 ;
}
V_130 ++ ;
V_18 = V_24 -> V_26 + V_25 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( ( V_133 += V_18 ) >= V_3 -> V_15 )
V_133 -= V_3 -> V_15 ;
V_134 += V_18 ;
}
F_37 ( & V_3 -> V_109 ) ;
return V_130 ;
}
static int F_57 ( struct V_2 * V_3 )
{
unsigned int V_133 ;
unsigned int V_134 , V_135 ;
unsigned int V_18 ;
unsigned int V_130 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
F_34 ( & V_3 -> V_109 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_135 = V_3 -> V_20 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_133 = V_3 -> V_23 ;
V_130 = 0 ;
V_134 = 0 ;
while ( V_134 < V_135 ) {
V_24 = F_1 ( V_3 , V_133 ) ;
V_130 ++ ;
V_18 = V_24 -> V_26 + V_25 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( ( V_133 += V_18 ) >= V_3 -> V_15 )
V_133 -= V_3 -> V_15 ;
V_134 += V_18 ;
}
F_37 ( & V_3 -> V_109 ) ;
return V_130 ;
}
static long F_58 ( struct V_98 * V_98 , unsigned int V_136 , unsigned long V_137 )
{
struct V_2 * V_3 = V_98 -> V_120 ;
int V_138 = 0 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
switch ( V_136 ) {
case V_139 :
F_21 ( & V_3 -> V_64 , V_58 ) ;
if ( ! F_54 ( V_3 ) ) {
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
V_138 = V_24 -> V_26 ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
break;
case V_140 :
V_138 = V_3 -> V_15 ;
break;
case V_141 :
{
int V_18 ;
struct V_111 * V_131 ;
if ( V_137 < V_142 || V_137 > V_143 )
return - V_17 ;
V_18 = F_59 ( V_137 ) ;
if ( ( V_131 = F_39 ( sizeof( struct V_111 ) * ( V_18 / V_6 ) ,
V_106 ) ) == NULL ) {
V_138 = - V_107 ;
break;
}
V_138 = F_43 ( V_131 , V_18 / V_6 ) ;
if ( V_138 < 0 ) {
F_45 ( V_131 ) ;
break;
}
F_34 ( & V_3 -> V_109 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_51 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ;
F_45 ( V_3 -> V_5 ) ;
V_3 -> V_5 = V_131 ;
V_3 -> V_15 = V_18 ;
V_3 -> V_125 = V_3 -> V_21 = V_3 -> V_23 = V_3 -> V_20 = 0 ;
V_3 -> V_70 = 0 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_37 ( & V_3 -> V_109 ) ;
}
break;
case V_144 :
V_138 = F_53 ( V_3 , V_137 ) ;
break;
case V_145 :
case V_146 :
{
struct V_147 V_148 ;
if ( F_60 ( & V_148 , ( void T_1 * ) V_137 ,
sizeof( struct V_147 ) ) )
return - V_124 ;
if ( V_148 . V_149 > 0x10000000 )
return - V_17 ;
V_138 = F_46 ( V_98 , V_3 , V_148 . V_121 ,
( V_136 == V_145 ) ? V_128 : V_150 ,
V_148 . V_95 , ( unsigned int ) V_148 . V_149 ) ;
}
break;
case V_151 :
{
struct V_152 V_153 ;
struct V_152 T_1 * V_154 ;
V_154 = (struct V_152 T_1 * ) V_137 ;
if ( F_60 ( & V_153 , V_154 , sizeof( V_153 ) ) )
return - V_124 ;
if ( V_153 . V_155 ) {
V_138 = F_53 ( V_3 , V_153 . V_155 ) ;
if ( V_138 < 0 )
return V_138 ;
if ( F_56 ( V_138 , & V_154 -> V_155 ) )
return - V_124 ;
}
V_138 = F_55 ( V_98 , V_3 , V_153 . V_156 , V_153 . V_157 ) ;
if ( V_138 < 0 )
return V_138 ;
if ( F_56 ( V_138 , & V_154 -> V_157 ) )
return - V_124 ;
V_138 = 0 ;
}
break;
case V_158 : {
struct V_159 T_1 * V_160 ;
unsigned int V_130 ;
unsigned int V_161 ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_161 = V_3 -> V_70 ;
V_3 -> V_70 = 0 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_130 = F_57 ( V_3 ) ;
V_160 = (struct V_159 T_1 * ) V_137 ;
if ( F_56 ( V_161 , & V_160 -> V_162 ) )
return - V_124 ;
if ( F_56 ( V_130 , & V_160 -> V_163 ) )
return - V_124 ;
}
break;
default:
return - V_164 ;
}
return V_138 ;
}
static long F_61 ( struct V_98 * V_98 ,
unsigned int V_136 , unsigned long V_137 )
{
struct V_2 * V_3 = V_98 -> V_120 ;
int V_138 ;
switch ( V_136 ) {
case V_165 :
case V_166 :
{
struct V_167 V_148 ;
if ( F_60 ( & V_148 , ( void T_1 * ) V_137 ,
sizeof( struct V_167 ) ) )
return - V_124 ;
V_138 = F_46 ( V_98 , V_3 , F_62 ( V_148 . V_168 ) ,
( V_136 == V_165 ) ? V_128 : V_150 ,
F_62 ( V_148 . V_169 ) , V_148 . V_170 ) ;
if ( V_138 < 0 )
return V_138 ;
}
return 0 ;
case V_171 :
{
struct V_172 V_153 ;
struct V_172 T_1 * V_154 ;
V_154 = (struct V_172 T_1 * ) F_62 ( V_137 ) ;
if ( F_60 ( & V_153 , V_154 , sizeof( V_153 ) ) )
return - V_124 ;
if ( V_153 . V_173 ) {
V_138 = F_53 ( V_3 , V_153 . V_173 ) ;
if ( V_138 < 0 )
return V_138 ;
if ( F_56 ( V_138 , & V_154 -> V_173 ) )
return - V_124 ;
}
V_138 = F_55 ( V_98 , V_3 , F_62 ( V_153 . V_174 ) ,
V_153 . V_175 ) ;
if ( V_138 < 0 )
return V_138 ;
if ( F_56 ( V_138 , & V_154 -> V_175 ) )
return - V_124 ;
}
return 0 ;
case V_158 :
return F_58 ( V_98 , V_136 , ( unsigned long ) F_62 ( V_137 ) ) ;
case V_139 :
case V_140 :
case V_141 :
case V_144 :
return F_58 ( V_98 , V_136 , V_137 ) ;
default:
;
}
return - V_164 ;
}
static unsigned int
F_63 ( struct V_98 * V_98 , struct V_176 * V_177 )
{
struct V_2 * V_3 = V_98 -> V_120 ;
unsigned int V_178 = 0 ;
unsigned long V_58 ;
if ( V_98 -> V_179 & V_180 )
F_64 ( V_98 , & V_3 -> V_94 , V_177 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
if ( ! F_54 ( V_3 ) )
V_178 |= V_181 | V_182 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
return V_178 ;
}
static void F_65 ( struct V_183 * V_184 )
{
struct V_2 * V_3 = V_184 -> V_185 ;
V_3 -> V_69 ++ ;
}
static void F_66 ( struct V_183 * V_184 )
{
struct V_2 * V_3 = V_184 -> V_185 ;
V_3 -> V_69 -- ;
}
static int F_67 ( struct V_183 * V_184 , struct V_186 * V_187 )
{
struct V_2 * V_3 = V_184 -> V_185 ;
unsigned long V_4 , V_188 ;
struct V_189 * V_190 ;
V_4 = V_187 -> V_191 << V_192 ;
if ( V_4 >= V_3 -> V_15 )
return V_193 ;
V_188 = V_4 / V_6 ;
V_190 = V_3 -> V_5 [ V_188 ] . V_194 ;
F_68 ( V_190 ) ;
V_187 -> V_189 = V_190 ;
return 0 ;
}
static int F_69 ( struct V_98 * V_195 , struct V_183 * V_184 )
{
V_184 -> V_196 = & V_197 ;
V_184 -> V_198 |= V_199 ;
V_184 -> V_185 = V_195 -> V_120 ;
F_65 ( V_184 ) ;
return 0 ;
}
static int F_47 ( struct V_98 * V_98 , struct V_2 * V_3 )
{
F_70 ( V_200 , V_201 ) ;
unsigned long V_58 ;
F_71 ( & V_3 -> V_94 , & V_200 ) ;
F_72 ( V_202 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
while ( F_54 ( V_3 ) ) {
F_24 ( & V_3 -> V_64 , V_58 ) ;
if ( V_98 -> V_203 & V_204 ) {
F_72 ( V_205 ) ;
F_73 ( & V_3 -> V_94 , & V_200 ) ;
return - V_206 ;
}
F_74 () ;
if ( F_75 ( V_201 ) ) {
F_73 ( & V_3 -> V_94 , & V_200 ) ;
return - V_207 ;
}
F_72 ( V_202 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_72 ( V_205 ) ;
F_73 ( & V_3 -> V_94 , & V_200 ) ;
return 0 ;
}
static int F_43 ( struct V_111 * V_208 , int V_209 )
{
int V_210 ;
unsigned long V_211 ;
for ( V_210 = 0 ; V_210 < V_209 ; V_210 ++ ) {
V_211 = F_76 ( V_106 ) ;
if ( V_211 == 0 ) {
while ( V_210 -- != 0 )
F_77 ( ( unsigned long ) V_208 [ V_210 ] . V_7 ) ;
return - V_107 ;
}
V_208 [ V_210 ] . V_7 = ( unsigned char * ) V_211 ;
V_208 [ V_210 ] . V_194 = F_78 ( ( void * ) V_211 ) ;
}
return 0 ;
}
static void F_51 ( struct V_111 * V_208 , int V_209 )
{
int V_210 ;
for ( V_210 = 0 ; V_210 < V_209 ; V_210 ++ )
F_77 ( ( unsigned long ) V_208 [ V_210 ] . V_7 ) ;
}
int F_79 ( struct V_99 * V_100 , const struct V_212 * V_213 )
{
struct V_214 * V_75 ;
unsigned V_215 = V_213 ? V_213 -> V_76 : 0 ;
if ( V_215 >= V_216 )
return 0 ;
V_75 = F_80 ( V_217 , V_213 ? V_213 -> V_218 : NULL ,
F_81 ( F_82 ( V_219 ) , V_215 ) , NULL ,
L_3 , V_215 ) ;
if ( F_83 ( V_75 ) )
return 0 ;
V_100 -> V_220 = V_75 ;
return 1 ;
}
void F_84 ( struct V_99 * V_100 )
{
F_85 ( V_217 , V_100 -> V_220 -> V_221 ) ;
}
int T_6 F_86 ( void )
{
int V_101 ;
V_217 = F_87 ( V_222 , L_4 ) ;
if ( F_83 ( V_217 ) ) {
V_101 = F_88 ( V_217 ) ;
goto V_223;
}
V_101 = F_89 ( & V_219 , 0 , V_216 , L_4 ) ;
if ( V_101 < 0 )
goto V_224;
F_90 ( & V_225 , & V_226 ) ;
V_225 . V_227 = V_222 ;
V_101 = F_91 ( & V_225 , V_219 , V_216 ) ;
if ( V_101 < 0 )
goto V_228;
return 0 ;
V_228:
F_92 ( V_219 , V_216 ) ;
V_224:
F_93 ( V_217 ) ;
V_223:
return V_101 ;
}
void F_94 ( void )
{
F_95 ( & V_225 ) ;
F_92 ( V_219 , V_216 ) ;
F_93 ( V_217 ) ;
}
