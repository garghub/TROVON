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
V_24 -> V_81 = V_57 . V_82 / V_83 ;
V_24 -> V_49 = V_49 ;
V_24 -> V_84 = V_59 ;
V_24 -> V_26 = V_11 + V_61 ;
V_24 -> V_85 = V_28 -> V_39 ;
if ( F_27 ( V_54 ) ) {
V_24 -> V_86 = V_28 -> V_86 ;
} else if ( F_22 ( V_54 ) ) {
V_24 -> V_86 = V_28 -> V_86 ;
V_24 -> V_87 = V_28 -> V_87 ;
V_24 -> V_88 . V_89 . V_90 = V_28 -> V_90 ;
V_24 -> V_88 . V_89 . V_91 = V_28 -> V_66 ;
}
if ( F_28 ( V_54 ) && V_29 == 'S' ) {
V_24 -> V_92 = F_10 ( V_24 -> V_88 . V_93 , V_28 , V_29 ) ;
} else {
V_24 -> V_92 = '-' ;
}
if ( V_41 != 0 ) {
V_24 -> V_41 = V_41 ;
F_18 ( V_3 , V_4 , V_28 , V_29 , V_41 ) ;
if ( ( V_4 += V_61 ) >= V_3 -> V_15 )
V_4 -= V_3 -> V_15 ;
}
if ( V_11 != 0 ) {
V_11 = F_11 ( V_3 , V_4 , V_28 , V_11 ,
& V_24 -> V_94 ) ;
if ( V_11 > 0 ) {
V_60 = ( V_24 -> V_26 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
V_24 -> V_26 -= V_11 ;
V_60 -= ( V_24 -> V_26 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
F_8 ( V_3 , V_60 ) ;
}
} else {
V_24 -> V_94 = V_63 ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_29 ( & V_3 -> V_95 ) ;
}
static void F_30 ( void * V_96 , struct V_28 * V_28 )
{
struct V_2 * V_3 = V_96 ;
F_19 ( V_3 , V_28 , 'S' , - V_97 ) ;
}
static void F_31 ( void * V_96 , struct V_28 * V_28 , int V_49 )
{
struct V_2 * V_3 = V_96 ;
F_19 ( V_3 , V_28 , 'C' , V_49 ) ;
}
static void F_32 ( void * V_96 , struct V_28 * V_28 , int error )
{
struct V_2 * V_3 = V_96 ;
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
V_24 -> V_81 = V_57 . V_82 / V_83 ;
V_24 -> V_49 = error ;
V_24 -> V_92 = '-' ;
V_24 -> V_94 = 'E' ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_29 ( & V_3 -> V_95 ) ;
}
static int F_33 ( struct V_98 * V_98 , struct V_99 * V_99 )
{
struct V_100 * V_101 ;
struct V_2 * V_3 ;
T_2 V_18 ;
int V_102 ;
F_34 ( & V_103 ) ;
V_101 = F_35 ( F_36 ( V_98 ) ) ;
if ( V_101 == NULL ) {
F_37 ( & V_103 ) ;
return - V_104 ;
}
if ( V_101 != & V_105 && V_101 -> V_106 == NULL ) {
F_38 (KERN_ERR TAG L_1 ) ;
F_37 ( & V_103 ) ;
return - V_104 ;
}
V_3 = F_39 ( sizeof( struct V_2 ) , V_107 ) ;
if ( V_3 == NULL ) {
V_102 = - V_108 ;
goto V_109;
}
F_40 ( & V_3 -> V_64 ) ;
F_41 ( & V_3 -> V_95 ) ;
F_42 ( & V_3 -> V_110 ) ;
V_3 -> V_15 = V_111 ;
V_18 = sizeof( struct V_112 ) * ( V_3 -> V_15 / V_6 ) ;
if ( ( V_3 -> V_5 = F_39 ( V_18 , V_107 ) ) == NULL ) {
V_102 = - V_108 ;
goto V_113;
}
if ( ( V_102 = F_43 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ) < 0 )
goto V_114;
V_3 -> V_115 . V_116 = V_101 ;
V_3 -> V_115 . V_117 = V_3 ;
V_3 -> V_115 . V_118 = F_30 ;
V_3 -> V_115 . V_119 = F_32 ;
V_3 -> V_115 . V_120 = F_31 ;
F_44 ( V_101 , & V_3 -> V_115 ) ;
V_99 -> V_121 = V_3 ;
F_37 ( & V_103 ) ;
return 0 ;
V_114:
F_45 ( V_3 -> V_5 ) ;
V_113:
F_45 ( V_3 ) ;
V_109:
F_37 ( & V_103 ) ;
return V_102 ;
}
static int F_46 ( struct V_99 * V_99 , struct V_2 * V_3 ,
struct V_1 T_1 * V_122 , unsigned int V_123 ,
void T_1 * V_96 , unsigned int V_124 )
{
unsigned long V_58 ;
struct V_1 * V_24 ;
T_2 V_12 ;
unsigned int V_4 ;
int V_102 ;
F_34 ( & V_3 -> V_110 ) ;
if ( ( V_102 = F_47 ( V_99 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_110 ) ;
return V_102 ;
}
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
if ( F_4 ( V_122 , V_24 , V_123 ) ) {
F_37 ( & V_3 -> V_110 ) ;
return - V_125 ;
}
V_12 = F_48 ( V_24 -> V_26 , V_124 ) ;
if ( ( V_4 = V_3 -> V_23 + V_25 ) >= V_3 -> V_15 ) V_4 = 0 ;
if ( F_3 ( V_3 , V_4 , V_96 , V_12 ) ) {
F_37 ( & V_3 -> V_110 ) ;
return - V_125 ;
}
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_126 = 0 ;
F_37 ( & V_3 -> V_110 ) ;
return 0 ;
}
static int F_49 ( struct V_98 * V_98 , struct V_99 * V_99 )
{
struct V_2 * V_3 = V_99 -> V_121 ;
struct V_100 * V_101 = V_3 -> V_115 . V_116 ;
F_34 ( & V_103 ) ;
if ( V_101 -> V_127 <= 0 ) {
F_38 (KERN_ERR TAG L_2 ) ;
F_37 ( & V_103 ) ;
return 0 ;
}
F_50 ( V_101 , & V_3 -> V_115 ) ;
F_51 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ;
F_45 ( V_3 -> V_5 ) ;
F_45 ( V_3 ) ;
F_37 ( & V_103 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_99 * V_99 , char T_1 * V_13 ,
T_2 V_124 , T_4 * V_128 )
{
struct V_2 * V_3 = V_99 -> V_121 ;
unsigned int V_123 = V_129 ;
unsigned long V_58 ;
struct V_1 * V_24 ;
unsigned int V_4 ;
T_2 V_12 ;
char * V_7 ;
T_3 V_130 = 0 ;
int V_102 ;
F_34 ( & V_3 -> V_110 ) ;
if ( ( V_102 = F_47 ( V_99 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_110 ) ;
return V_102 ;
}
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
if ( V_3 -> V_126 < V_123 ) {
V_12 = F_48 ( V_124 , ( T_2 ) ( V_123 - V_3 -> V_126 ) ) ;
V_7 = ( ( char * ) V_24 ) + V_3 -> V_126 ;
if ( V_12 && F_4 ( V_13 , V_7 , V_12 ) ) {
F_37 ( & V_3 -> V_110 ) ;
return - V_125 ;
}
V_124 -= V_12 ;
V_13 += V_12 ;
V_3 -> V_126 += V_12 ;
V_130 += V_12 ;
}
if ( V_3 -> V_126 >= V_123 ) {
V_12 = V_24 -> V_26 ;
V_12 -= V_3 -> V_126 - V_123 ;
if ( V_12 > V_124 )
V_12 = V_124 ;
V_4 = V_3 -> V_23 + V_25 ;
V_4 += V_3 -> V_126 - V_123 ;
if ( V_4 >= V_3 -> V_15 )
V_4 -= V_3 -> V_15 ;
if ( F_3 ( V_3 , V_4 , V_13 , V_12 ) ) {
F_37 ( & V_3 -> V_110 ) ;
return - V_125 ;
}
V_124 -= V_12 ;
V_13 += V_12 ;
V_3 -> V_126 += V_12 ;
V_130 += V_12 ;
}
if ( V_3 -> V_126 >= V_123 + V_24 -> V_26 ) {
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_126 = 0 ;
}
F_37 ( & V_3 -> V_110 ) ;
return V_130 ;
}
static int F_53 ( struct V_2 * V_3 , unsigned V_131 )
{
unsigned long V_58 ;
struct V_1 * V_24 ;
int V_33 ;
F_34 ( & V_3 -> V_110 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
for ( V_33 = 0 ; V_33 < V_131 ; ++ V_33 ) {
if ( F_54 ( V_3 ) )
break;
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
F_9 ( V_3 , V_25 + V_24 -> V_26 ) ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_3 -> V_126 = 0 ;
F_37 ( & V_3 -> V_110 ) ;
return V_33 ;
}
static int F_55 ( struct V_99 * V_99 , struct V_2 * V_3 ,
T_5 T_1 * V_132 , unsigned int V_133 )
{
unsigned int V_134 ;
unsigned int V_135 , V_136 ;
unsigned int V_18 ;
unsigned int V_131 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
int V_102 ;
F_34 ( & V_3 -> V_110 ) ;
if ( ( V_102 = F_47 ( V_99 , V_3 ) ) < 0 ) {
F_37 ( & V_3 -> V_110 ) ;
return V_102 ;
}
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_136 = V_3 -> V_20 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_134 = V_3 -> V_23 ;
V_131 = 0 ;
V_135 = 0 ;
while ( V_135 < V_136 ) {
if ( V_131 >= V_133 )
break;
V_24 = F_1 ( V_3 , V_134 ) ;
if ( F_56 ( V_134 , & V_132 [ V_131 ] ) ) {
F_37 ( & V_3 -> V_110 ) ;
return - V_125 ;
}
V_131 ++ ;
V_18 = V_24 -> V_26 + V_25 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( ( V_134 += V_18 ) >= V_3 -> V_15 )
V_134 -= V_3 -> V_15 ;
V_135 += V_18 ;
}
F_37 ( & V_3 -> V_110 ) ;
return V_131 ;
}
static int F_57 ( struct V_2 * V_3 )
{
unsigned int V_134 ;
unsigned int V_135 , V_136 ;
unsigned int V_18 ;
unsigned int V_131 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
F_34 ( & V_3 -> V_110 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_136 = V_3 -> V_20 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_134 = V_3 -> V_23 ;
V_131 = 0 ;
V_135 = 0 ;
while ( V_135 < V_136 ) {
V_24 = F_1 ( V_3 , V_134 ) ;
V_131 ++ ;
V_18 = V_24 -> V_26 + V_25 ;
V_18 = ( V_18 + V_19 - 1 ) & ~ ( V_19 - 1 ) ;
if ( ( V_134 += V_18 ) >= V_3 -> V_15 )
V_134 -= V_3 -> V_15 ;
V_135 += V_18 ;
}
F_37 ( & V_3 -> V_110 ) ;
return V_131 ;
}
static long F_58 ( struct V_99 * V_99 , unsigned int V_137 , unsigned long V_138 )
{
struct V_2 * V_3 = V_99 -> V_121 ;
int V_139 = 0 ;
struct V_1 * V_24 ;
unsigned long V_58 ;
switch ( V_137 ) {
case V_140 :
F_21 ( & V_3 -> V_64 , V_58 ) ;
if ( ! F_54 ( V_3 ) ) {
V_24 = F_1 ( V_3 , V_3 -> V_23 ) ;
V_139 = V_24 -> V_26 ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
break;
case V_141 :
V_139 = V_3 -> V_15 ;
break;
case V_142 :
{
int V_18 ;
struct V_112 * V_132 ;
if ( V_138 < V_143 || V_138 > V_144 )
return - V_17 ;
V_18 = F_59 ( V_138 ) ;
V_132 = F_39 ( sizeof( struct V_112 ) * ( V_18 / V_6 ) , V_107 ) ;
if ( V_132 == NULL ) {
V_139 = - V_108 ;
break;
}
V_139 = F_43 ( V_132 , V_18 / V_6 ) ;
if ( V_139 < 0 ) {
F_45 ( V_132 ) ;
break;
}
F_34 ( & V_3 -> V_110 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
F_51 ( V_3 -> V_5 , V_3 -> V_15 / V_6 ) ;
F_45 ( V_3 -> V_5 ) ;
V_3 -> V_5 = V_132 ;
V_3 -> V_15 = V_18 ;
V_3 -> V_126 = V_3 -> V_21 = V_3 -> V_23 = V_3 -> V_20 = 0 ;
V_3 -> V_70 = 0 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_37 ( & V_3 -> V_110 ) ;
}
break;
case V_145 :
V_139 = F_53 ( V_3 , V_138 ) ;
break;
case V_146 :
case V_147 :
{
struct V_148 V_149 ;
if ( F_60 ( & V_149 , ( void T_1 * ) V_138 ,
sizeof( struct V_148 ) ) )
return - V_125 ;
if ( V_149 . V_150 > 0x10000000 )
return - V_17 ;
V_139 = F_46 ( V_99 , V_3 , V_149 . V_122 ,
( V_137 == V_146 ) ? V_129 : V_151 ,
V_149 . V_96 , ( unsigned int ) V_149 . V_150 ) ;
}
break;
case V_152 :
{
struct V_153 V_154 ;
struct V_153 T_1 * V_155 ;
V_155 = (struct V_153 T_1 * ) V_138 ;
if ( F_60 ( & V_154 , V_155 , sizeof( V_154 ) ) )
return - V_125 ;
if ( V_154 . V_156 ) {
V_139 = F_53 ( V_3 , V_154 . V_156 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( F_56 ( V_139 , & V_155 -> V_156 ) )
return - V_125 ;
}
V_139 = F_55 ( V_99 , V_3 , V_154 . V_157 , V_154 . V_158 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( F_56 ( V_139 , & V_155 -> V_158 ) )
return - V_125 ;
V_139 = 0 ;
}
break;
case V_159 : {
struct V_160 T_1 * V_161 ;
unsigned int V_131 ;
unsigned int V_162 ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
V_162 = V_3 -> V_70 ;
V_3 -> V_70 = 0 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
V_131 = F_57 ( V_3 ) ;
V_161 = (struct V_160 T_1 * ) V_138 ;
if ( F_56 ( V_162 , & V_161 -> V_163 ) )
return - V_125 ;
if ( F_56 ( V_131 , & V_161 -> V_164 ) )
return - V_125 ;
}
break;
default:
return - V_165 ;
}
return V_139 ;
}
static long F_61 ( struct V_99 * V_99 ,
unsigned int V_137 , unsigned long V_138 )
{
struct V_2 * V_3 = V_99 -> V_121 ;
int V_139 ;
switch ( V_137 ) {
case V_166 :
case V_167 :
{
struct V_168 V_149 ;
if ( F_60 ( & V_149 , ( void T_1 * ) V_138 ,
sizeof( struct V_168 ) ) )
return - V_125 ;
V_139 = F_46 ( V_99 , V_3 , F_62 ( V_149 . V_169 ) ,
( V_137 == V_166 ) ? V_129 : V_151 ,
F_62 ( V_149 . V_170 ) , V_149 . V_171 ) ;
if ( V_139 < 0 )
return V_139 ;
}
return 0 ;
case V_172 :
{
struct V_173 V_154 ;
struct V_173 T_1 * V_155 ;
V_155 = (struct V_173 T_1 * ) F_62 ( V_138 ) ;
if ( F_60 ( & V_154 , V_155 , sizeof( V_154 ) ) )
return - V_125 ;
if ( V_154 . V_174 ) {
V_139 = F_53 ( V_3 , V_154 . V_174 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( F_56 ( V_139 , & V_155 -> V_174 ) )
return - V_125 ;
}
V_139 = F_55 ( V_99 , V_3 , F_62 ( V_154 . V_175 ) ,
V_154 . V_176 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( F_56 ( V_139 , & V_155 -> V_176 ) )
return - V_125 ;
}
return 0 ;
case V_159 :
return F_58 ( V_99 , V_137 , ( unsigned long ) F_62 ( V_138 ) ) ;
case V_140 :
case V_141 :
case V_142 :
case V_145 :
return F_58 ( V_99 , V_137 , V_138 ) ;
default:
;
}
return - V_165 ;
}
static unsigned int
F_63 ( struct V_99 * V_99 , struct V_177 * V_178 )
{
struct V_2 * V_3 = V_99 -> V_121 ;
unsigned int V_179 = 0 ;
unsigned long V_58 ;
if ( V_99 -> V_180 & V_181 )
F_64 ( V_99 , & V_3 -> V_95 , V_178 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
if ( ! F_54 ( V_3 ) )
V_179 |= V_182 | V_183 ;
F_24 ( & V_3 -> V_64 , V_58 ) ;
return V_179 ;
}
static void F_65 ( struct V_184 * V_185 )
{
struct V_2 * V_3 = V_185 -> V_186 ;
V_3 -> V_69 ++ ;
}
static void F_66 ( struct V_184 * V_185 )
{
struct V_2 * V_3 = V_185 -> V_186 ;
V_3 -> V_69 -- ;
}
static int F_67 ( struct V_187 * V_188 )
{
struct V_2 * V_3 = V_188 -> V_185 -> V_186 ;
unsigned long V_4 , V_189 ;
struct V_190 * V_191 ;
V_4 = V_188 -> V_192 << V_193 ;
if ( V_4 >= V_3 -> V_15 )
return V_194 ;
V_189 = V_4 / V_6 ;
V_191 = V_3 -> V_5 [ V_189 ] . V_195 ;
F_68 ( V_191 ) ;
V_188 -> V_190 = V_191 ;
return 0 ;
}
static int F_69 ( struct V_99 * V_196 , struct V_184 * V_185 )
{
V_185 -> V_197 = & V_198 ;
V_185 -> V_199 |= V_200 | V_201 ;
V_185 -> V_186 = V_196 -> V_121 ;
F_65 ( V_185 ) ;
return 0 ;
}
static int F_47 ( struct V_99 * V_99 , struct V_2 * V_3 )
{
F_70 ( V_202 , V_203 ) ;
unsigned long V_58 ;
F_71 ( & V_3 -> V_95 , & V_202 ) ;
F_72 ( V_204 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
while ( F_54 ( V_3 ) ) {
F_24 ( & V_3 -> V_64 , V_58 ) ;
if ( V_99 -> V_205 & V_206 ) {
F_72 ( V_207 ) ;
F_73 ( & V_3 -> V_95 , & V_202 ) ;
return - V_208 ;
}
F_74 () ;
if ( F_75 ( V_203 ) ) {
F_73 ( & V_3 -> V_95 , & V_202 ) ;
return - V_209 ;
}
F_72 ( V_204 ) ;
F_21 ( & V_3 -> V_64 , V_58 ) ;
}
F_24 ( & V_3 -> V_64 , V_58 ) ;
F_72 ( V_207 ) ;
F_73 ( & V_3 -> V_95 , & V_202 ) ;
return 0 ;
}
static int F_43 ( struct V_112 * V_210 , int V_211 )
{
int V_212 ;
unsigned long V_213 ;
for ( V_212 = 0 ; V_212 < V_211 ; V_212 ++ ) {
V_213 = F_76 ( V_107 ) ;
if ( V_213 == 0 ) {
while ( V_212 -- != 0 )
F_77 ( ( unsigned long ) V_210 [ V_212 ] . V_7 ) ;
return - V_108 ;
}
V_210 [ V_212 ] . V_7 = ( unsigned char * ) V_213 ;
V_210 [ V_212 ] . V_195 = F_78 ( ( void * ) V_213 ) ;
}
return 0 ;
}
static void F_51 ( struct V_112 * V_210 , int V_211 )
{
int V_212 ;
for ( V_212 = 0 ; V_212 < V_211 ; V_212 ++ )
F_77 ( ( unsigned long ) V_210 [ V_212 ] . V_7 ) ;
}
int F_79 ( struct V_100 * V_101 , const struct V_214 * V_215 )
{
struct V_216 * V_75 ;
unsigned V_217 = V_215 ? V_215 -> V_76 : 0 ;
if ( V_217 >= V_218 )
return 0 ;
V_75 = F_80 ( V_219 , V_215 ? V_215 -> V_220 : NULL ,
F_81 ( F_82 ( V_221 ) , V_217 ) , NULL ,
L_3 , V_217 ) ;
if ( F_83 ( V_75 ) )
return 0 ;
V_101 -> V_222 = V_75 ;
return 1 ;
}
void F_84 ( struct V_100 * V_101 )
{
F_85 ( V_219 , V_101 -> V_222 -> V_223 ) ;
}
int T_6 F_86 ( void )
{
int V_102 ;
V_219 = F_87 ( V_224 , L_4 ) ;
if ( F_83 ( V_219 ) ) {
V_102 = F_88 ( V_219 ) ;
goto V_225;
}
V_102 = F_89 ( & V_221 , 0 , V_218 , L_4 ) ;
if ( V_102 < 0 )
goto V_226;
F_90 ( & V_227 , & V_228 ) ;
V_227 . V_229 = V_224 ;
V_102 = F_91 ( & V_227 , V_221 , V_218 ) ;
if ( V_102 < 0 )
goto V_230;
return 0 ;
V_230:
F_92 ( V_221 , V_218 ) ;
V_226:
F_93 ( V_219 ) ;
V_225:
return V_102 ;
}
void F_94 ( void )
{
F_95 ( & V_227 ) ;
F_92 ( V_221 , V_218 ) ;
F_93 ( V_219 ) ;
}
