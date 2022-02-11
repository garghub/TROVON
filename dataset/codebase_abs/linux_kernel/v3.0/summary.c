int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( T_1 , V_2 -> V_4 , V_5 ) ;
V_2 -> V_6 = F_3 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_2 -> V_6 ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
V_2 -> V_6 -> V_10 = F_5 ( V_3 , V_8 ) ;
if ( ! V_2 -> V_6 -> V_10 ) {
F_4 ( L_2 ) ;
F_6 ( V_2 -> V_6 ) ;
return - V_9 ;
}
F_7 ( L_3 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_7 ( L_4 ) ;
F_9 ( V_2 -> V_6 ) ;
F_6 ( V_2 -> V_6 -> V_10 ) ;
V_2 -> V_6 -> V_10 = NULL ;
F_6 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_10 ( struct V_7 * V_11 , union V_12 * V_13 )
{
if ( ! V_11 -> V_14 )
V_11 -> V_14 = (union V_12 * ) V_13 ;
if ( V_11 -> V_15 )
V_11 -> V_15 -> V_16 . V_17 = (union V_12 * ) V_13 ;
V_11 -> V_15 = (union V_12 * ) V_13 ;
switch ( F_11 ( V_13 -> V_16 . V_18 ) ) {
case V_19 :
V_11 -> V_3 += V_20 ;
V_11 -> V_21 ++ ;
F_7 ( L_5 ,
F_12 ( V_13 -> V_22 . V_23 ) ) ;
break;
case V_24 :
V_11 -> V_3 += F_13 ( V_13 -> V_25 . V_26 ) ;
V_11 -> V_21 ++ ;
F_7 ( L_6 ,
F_12 ( V_13 -> V_25 . V_27 ) ) ;
break;
#ifdef F_14
case V_28 :
V_11 -> V_3 += V_29 ;
V_11 -> V_21 ++ ;
F_7 ( L_7 ,
F_12 ( V_13 -> V_30 . V_31 ) , F_12 ( V_13 -> V_30 . V_32 ) ) ;
break;
case V_33 :
V_11 -> V_3 += V_34 ;
V_11 -> V_21 ++ ;
F_7 ( L_8 ) ;
break;
#endif
default:
F_4 ( L_9 ,
F_11 ( V_13 -> V_16 . V_18 ) ) ;
return 1 ;
}
return 0 ;
}
int F_15 ( struct V_7 * V_11 , T_1 V_35 )
{
F_7 ( L_10 , V_35 ) ;
V_11 -> V_36 += V_35 ;
return 0 ;
}
int F_16 ( struct V_7 * V_11 , struct V_37 * V_38 ,
T_1 V_39 )
{
struct V_40 * V_41 = F_5 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_41 )
return - V_9 ;
V_41 -> V_18 = V_38 -> V_18 ;
V_41 -> V_23 = V_38 -> V_27 ;
V_41 -> V_32 = V_38 -> V_32 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_43 = V_38 -> V_43 ;
V_41 -> V_17 = NULL ;
return F_10 ( V_11 , (union V_12 * ) V_41 ) ;
}
int F_18 ( struct V_7 * V_11 , struct V_44 * V_45 ,
T_1 V_39 )
{
struct V_46 * V_41 =
F_5 ( sizeof( struct V_46 ) + V_45 -> V_26 , V_8 ) ;
if ( ! V_41 )
return - V_9 ;
V_41 -> V_18 = V_45 -> V_18 ;
V_41 -> V_43 = V_45 -> V_43 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_47 = V_45 -> V_47 ;
V_41 -> V_32 = V_45 -> V_32 ;
V_41 -> V_27 = V_45 -> V_27 ;
V_41 -> V_26 = V_45 -> V_26 ;
V_41 -> type = V_45 -> type ;
V_41 -> V_17 = NULL ;
memcpy ( V_41 -> V_48 , V_45 -> V_48 , V_45 -> V_26 ) ;
return F_10 ( V_11 , (union V_12 * ) V_41 ) ;
}
int F_19 ( struct V_7 * V_11 , struct V_49 * V_50 , T_1 V_39 )
{
struct V_51 * V_41 ;
V_41 = F_5 ( sizeof( struct V_51 ) , V_8 ) ;
if ( ! V_41 )
return - V_9 ;
V_41 -> V_18 = V_50 -> V_18 ;
V_41 -> V_31 = V_50 -> V_31 ;
V_41 -> V_32 = V_50 -> V_32 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_43 = V_50 -> V_43 ;
V_41 -> V_17 = NULL ;
return F_10 ( V_11 , (union V_12 * ) V_41 ) ;
}
int F_20 ( struct V_7 * V_11 , struct V_52 * V_53 , T_1 V_39 )
{
struct V_54 * V_41 ;
V_41 = F_5 ( sizeof( struct V_54 ) , V_8 ) ;
if ( ! V_41 )
return - V_9 ;
V_41 -> V_18 = V_53 -> V_18 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_17 = NULL ;
return F_10 ( V_11 , (union V_12 * ) V_41 ) ;
}
static void F_21 ( struct V_7 * V_11 )
{
union V_12 * V_41 ;
if ( ! V_11 -> V_14 ) {
F_7 ( L_11 ) ;
}
while ( V_11 -> V_14 ) {
V_41 = V_11 -> V_14 ;
V_11 -> V_14 = V_11 -> V_14 -> V_16 . V_17 ;
F_6 ( V_41 ) ;
}
V_11 -> V_15 = NULL ;
V_11 -> V_36 = 0 ;
V_11 -> V_21 = 0 ;
}
void F_22 ( struct V_7 * V_11 )
{
F_7 ( L_4 ) ;
F_21 ( V_11 ) ;
V_11 -> V_3 = 0 ;
}
void F_9 ( struct V_7 * V_11 )
{
F_7 ( L_4 ) ;
F_21 ( V_11 ) ;
V_11 -> V_3 = V_55 ;
}
int F_23 ( struct V_7 * V_11 )
{
return ( V_11 -> V_3 == V_55 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_7 * V_11 )
{
F_7 ( L_12 ,
V_2 -> V_6 -> V_3 , V_2 -> V_6 -> V_21 ,
V_11 -> V_3 , V_11 -> V_21 ) ;
V_2 -> V_6 -> V_3 = V_11 -> V_3 ;
V_2 -> V_6 -> V_21 = V_11 -> V_21 ;
V_2 -> V_6 -> V_36 = V_11 -> V_36 ;
V_2 -> V_6 -> V_14 = V_11 -> V_14 ;
V_2 -> V_6 -> V_15 = V_11 -> V_15 ;
V_11 -> V_14 = V_11 -> V_15 = NULL ;
}
int F_25 ( struct V_1 * V_2 , const struct V_56 * V_57 ,
unsigned long V_58 , T_1 V_39 )
{
union V_59 * V_60 ;
struct V_61 * V_62 ;
if ( V_2 -> V_6 -> V_3 == V_55 ) {
F_7 ( L_13 ) ;
return 0 ;
}
V_60 = V_57 [ 0 ] . V_63 ;
V_62 = & V_2 -> V_64 [ V_39 / V_2 -> V_4 ] ;
V_39 -= V_62 -> V_42 ;
switch ( F_11 ( V_60 -> V_16 . V_18 ) ) {
case V_19 : {
struct V_40 * V_41 =
F_5 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_41 )
goto V_65;
V_41 -> V_18 = V_60 -> V_22 . V_18 ;
V_41 -> V_23 = V_60 -> V_22 . V_27 ;
V_41 -> V_32 = V_60 -> V_22 . V_32 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_43 = V_60 -> V_22 . V_43 ;
V_41 -> V_17 = NULL ;
return F_10 ( V_2 -> V_6 , (union V_12 * ) V_41 ) ;
}
case V_24 : {
struct V_46 * V_41 =
F_5 ( sizeof( struct V_46 ) + V_60 -> V_25 . V_26 , V_8 ) ;
if ( ! V_41 )
goto V_65;
V_41 -> V_18 = V_60 -> V_25 . V_18 ;
V_41 -> V_43 = V_60 -> V_25 . V_43 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_47 = V_60 -> V_25 . V_47 ;
V_41 -> V_32 = V_60 -> V_25 . V_32 ;
V_41 -> V_27 = V_60 -> V_25 . V_27 ;
V_41 -> V_26 = V_60 -> V_25 . V_26 ;
V_41 -> type = V_60 -> V_25 . type ;
V_41 -> V_17 = NULL ;
switch ( V_58 ) {
case 1 :
memcpy ( V_41 -> V_48 , V_60 -> V_25 . V_48 , V_60 -> V_25 . V_26 ) ;
break;
case 2 :
memcpy ( V_41 -> V_48 , V_57 [ 1 ] . V_63 , V_60 -> V_25 . V_26 ) ;
break;
default:
F_26 () ;
break;
}
return F_10 ( V_2 -> V_6 , (union V_12 * ) V_41 ) ;
}
#ifdef F_14
case V_28 : {
struct V_51 * V_41 ;
V_41 = F_5 ( sizeof( struct V_51 ) , V_8 ) ;
if ( ! V_41 )
goto V_65;
V_41 -> V_18 = V_60 -> V_30 . V_18 ;
V_41 -> V_31 = V_60 -> V_30 . V_31 ;
V_41 -> V_32 = V_60 -> V_30 . V_32 ;
V_41 -> V_43 = V_60 -> V_30 . V_43 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_17 = NULL ;
return F_10 ( V_2 -> V_6 , (union V_12 * ) V_41 ) ;
}
case V_33 : {
struct V_54 * V_41 ;
V_41 = F_5 ( sizeof( struct V_54 ) , V_8 ) ;
if ( ! V_41 )
goto V_65;
V_41 -> V_18 = V_60 -> V_66 . V_18 ;
V_41 -> V_42 = F_17 ( V_39 ) ;
V_41 -> V_17 = NULL ;
return F_10 ( V_2 -> V_6 , (union V_12 * ) V_41 ) ;
}
#endif
case V_67 :
F_7 ( L_14 ) ;
V_2 -> V_6 -> V_36 += F_12 ( V_60 -> V_16 . V_43 ) ;
break;
case V_68 :
F_7 ( L_15 ) ;
break;
case V_69 :
F_7 ( L_16 ) ;
break;
default:
F_26 () ;
break;
}
return 0 ;
V_65:
F_4 ( L_17 ) ;
return - V_9 ;
}
static struct V_70 * F_27 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
T_1 V_39 , T_1 V_71 ,
struct V_72 * V_73 )
{
if ( ( V_39 & ~ 3 ) > V_2 -> V_4 - V_62 -> V_74 ) {
F_28 ( V_2 , V_62 , ( V_39 & ~ 3 ) - ( V_2 -> V_4 - V_62 -> V_74 ) ) ;
}
return F_29 ( V_2 , V_62 , V_62 -> V_42 + V_39 , V_71 , V_73 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_75 * V_6 , T_1 * V_76 )
{
struct V_72 * V_73 ;
struct V_77 * V_78 ;
void * V_79 ;
int V_22 , V_27 ;
int V_80 ;
V_79 = V_6 -> V_81 ;
for ( V_22 = 0 ; V_22 < F_12 ( V_6 -> V_21 ) ; V_22 ++ ) {
F_7 ( L_18 , V_22 ) ;
F_31 () ;
V_80 = F_32 ( V_2 , V_62 , 2 ) ;
if ( V_80 )
return V_80 ;
switch ( F_11 ( ( (struct V_82 * ) V_79 ) -> V_18 ) ) {
case V_19 : {
struct V_83 * V_84 ;
V_84 = V_79 ;
V_27 = F_12 ( V_84 -> V_23 ) ;
F_7 ( L_19 ,
V_62 -> V_42 + F_12 ( V_84 -> V_42 ) ,
V_62 -> V_42 + F_12 ( V_84 -> V_42 ) + F_12 ( V_84 -> V_43 ) ) ;
V_73 = F_33 ( V_2 , V_27 ) ;
if ( ! V_73 ) {
F_34 ( L_20 ) ;
return - V_9 ;
}
F_27 ( V_2 , V_62 , F_12 ( V_84 -> V_42 ) | V_85 ,
F_35 ( F_12 ( V_84 -> V_43 ) ) , V_73 ) ;
* V_76 += F_12 ( V_84 -> V_32 ) ;
V_79 += V_20 ;
break;
}
case V_24 : {
struct V_86 * V_87 ;
int V_88 ;
V_87 = V_79 ;
F_7 ( L_21 ,
V_62 -> V_42 + F_12 ( V_87 -> V_42 ) ,
V_62 -> V_42 + F_12 ( V_87 -> V_42 ) + F_12 ( V_87 -> V_43 ) ) ;
V_88 = F_36 ( V_87 -> V_48 , V_87 -> V_26 ) ;
if ( ! V_88 ) {
F_37 ( V_89 L_22 ,
V_62 -> V_42 + F_12 ( V_87 -> V_42 ) ) ;
return - V_90 ;
}
if ( V_88 < V_87 -> V_26 ) {
F_37 ( V_89 L_23 ,
V_62 -> V_42 + F_12 ( V_87 -> V_42 ) , V_88 ) ;
}
V_78 = F_38 ( V_88 + 1 ) ;
if ( ! V_78 )
return - V_9 ;
memcpy ( & V_78 -> V_48 , V_87 -> V_48 , V_88 ) ;
V_78 -> V_48 [ V_88 ] = 0 ;
V_73 = F_33 ( V_2 , F_12 ( V_87 -> V_47 ) ) ;
if ( ! V_73 ) {
F_39 ( V_78 ) ;
return - V_9 ;
}
V_78 -> V_91 = F_27 ( V_2 , V_62 , F_12 ( V_87 -> V_42 ) | V_85 ,
F_35 ( F_12 ( V_87 -> V_43 ) ) , V_73 ) ;
V_78 -> V_17 = NULL ;
V_78 -> V_32 = F_12 ( V_87 -> V_32 ) ;
V_78 -> V_27 = F_12 ( V_87 -> V_27 ) ;
V_78 -> V_92 = F_40 ( V_78 -> V_48 , V_88 ) ;
V_78 -> type = V_87 -> type ;
F_41 ( V_2 , V_78 , & V_73 -> V_93 ) ;
* V_76 += F_12 ( V_87 -> V_32 ) ;
V_79 += F_13 ( V_87 -> V_26 ) ;
break;
}
#ifdef F_14
case V_28 : {
struct V_94 * V_95 ;
struct V_96 * V_97 ;
V_97 = (struct V_96 * ) V_79 ;
F_7 ( L_24 ,
V_62 -> V_42 + F_12 ( V_97 -> V_42 ) ,
V_62 -> V_42 + F_12 ( V_97 -> V_42 ) + F_12 ( V_97 -> V_43 ) ,
F_12 ( V_97 -> V_31 ) , F_12 ( V_97 -> V_32 ) ) ;
V_95 = F_42 ( V_2 , F_12 ( V_97 -> V_31 ) ,
F_12 ( V_97 -> V_32 ) ) ;
if ( F_43 ( V_95 ) )
return F_44 ( V_95 ) ;
if ( V_95 -> V_32 > F_12 ( V_97 -> V_32 ) ) {
struct V_70 * V_91
= F_27 ( V_2 , V_62 , F_12 ( V_97 -> V_42 ) | V_85 ,
F_35 ( F_12 ( V_97 -> V_43 ) ) , NULL ) ;
V_91 -> V_98 = V_95 -> V_60 -> V_98 ;
V_95 -> V_60 -> V_98 = V_91 ;
} else {
V_95 -> V_32 = F_12 ( V_97 -> V_32 ) ;
F_27 ( V_2 , V_62 , F_12 ( V_97 -> V_42 ) | V_85 ,
F_35 ( F_12 ( V_97 -> V_43 ) ) , ( void * ) V_95 ) ;
}
* V_76 += F_12 ( V_97 -> V_31 ) ;
V_79 += V_29 ;
break;
}
case V_33 : {
struct V_99 * V_100 ;
struct V_101 * V_102 ;
V_102 = (struct V_101 * ) V_79 ;
F_7 ( L_25 ,
V_62 -> V_42 + F_12 ( V_102 -> V_42 ) ,
V_62 -> V_42 + F_12 ( V_102 -> V_42 ) +
( T_1 ) F_35 ( sizeof( struct V_52 ) ) ) ;
V_100 = F_45 () ;
if ( ! V_100 ) {
F_34 ( L_26 ) ;
return - V_9 ;
}
V_100 -> V_17 = V_2 -> V_103 ;
V_2 -> V_103 = V_100 ;
F_27 ( V_2 , V_62 , F_12 ( V_102 -> V_42 ) | V_85 ,
F_35 ( sizeof( struct V_52 ) ) , ( void * ) V_100 ) ;
* V_76 += V_100 -> V_60 -> V_104 ;
V_79 += V_34 ;
break;
}
#endif
default : {
T_2 V_18 = F_11 ( ( (struct V_82 * ) V_79 ) -> V_18 ) ;
F_4 ( L_27 , V_18 ) ;
if ( ( V_18 & V_105 ) == V_106 )
return - V_90 ;
V_2 -> V_107 -= V_62 -> V_107 ;
V_2 -> V_74 += V_2 -> V_4 - V_62 -> V_74 ;
V_2 -> V_108 -= V_62 -> V_108 ;
V_2 -> V_109 -= V_62 -> V_109 ;
V_62 -> V_107 = V_62 -> V_108 = V_62 -> V_109 = 0 ;
V_62 -> V_74 = V_2 -> V_4 ;
F_46 ( V_2 , V_62 ) ;
return - V_110 ;
}
}
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , struct V_61 * V_62 ,
struct V_75 * V_6 , T_1 V_111 ,
T_1 * V_76 )
{
struct V_112 V_113 ;
int V_114 , V_39 ;
T_1 V_115 ;
V_39 = V_2 -> V_4 - V_111 ;
F_7 ( L_28 ,
V_62 -> V_42 , V_62 -> V_42 + V_39 , V_111 ) ;
V_113 . V_116 = F_48 ( V_117 ) ;
V_113 . V_18 = F_48 ( V_69 ) ;
V_113 . V_43 = V_6 -> V_43 ;
V_115 = F_49 ( 0 , & V_113 , sizeof( V_113 ) - 4 ) ;
if ( F_12 ( V_6 -> V_118 ) != V_115 ) {
F_7 ( L_29
L_30 ) ;
goto V_119;
}
if ( F_12 ( V_6 -> V_43 ) != V_111 ) {
F_7 ( L_31 ) ;
goto V_119;
}
V_115 = F_49 ( 0 , V_6 , sizeof( struct V_75 ) - 8 ) ;
if ( F_12 ( V_6 -> V_120 ) != V_115 ) {
F_7 ( L_32 ) ;
goto V_119;
}
V_115 = F_49 ( 0 , V_6 -> V_81 , V_111 - sizeof( struct V_75 ) ) ;
if ( F_12 ( V_6 -> V_121 ) != V_115 ) {
F_7 ( L_33 ) ;
goto V_119;
}
if ( F_12 ( V_6 -> V_122 ) ) {
F_7 ( L_34 ) ;
V_114 = F_32 ( V_2 , V_62 , 1 ) ;
if ( V_114 )
return V_114 ;
if ( F_12 ( V_6 -> V_122 ) != V_2 -> V_123 ) {
F_7 ( L_35 ,
F_12 ( V_6 -> V_122 ) , V_2 -> V_123 ) ;
if ( ( V_114 = F_28 ( V_2 , V_62 , F_35 ( F_12 ( V_6 -> V_122 ) ) ) ) )
return V_114 ;
} else if ( V_62 -> V_124 ) {
F_7 ( L_36
L_37 , V_62 -> V_42 ) ;
if ( ( V_114 = F_28 ( V_2 , V_62 , F_35 ( F_12 ( V_6 -> V_122 ) ) ) ) )
return V_114 ;
} else {
F_29 ( V_2 , V_62 , V_62 -> V_42 | V_125 ,
F_12 ( V_6 -> V_122 ) , NULL ) ;
}
}
V_114 = F_30 ( V_2 , V_62 , V_6 , V_76 ) ;
if ( V_114 == - V_110 )
return 0 ;
if ( V_114 )
return V_114 ;
V_114 = F_32 ( V_2 , V_62 , 2 ) ;
if ( V_114 )
return V_114 ;
F_27 ( V_2 , V_62 , V_39 | V_125 , V_111 , NULL ) ;
if ( F_50 ( V_62 -> V_74 ) ) {
F_4 ( L_38 ,
V_62 -> V_74 , V_62 -> V_42 ) ;
V_62 -> V_107 += V_62 -> V_74 ;
V_2 -> V_107 += V_62 -> V_74 ;
V_2 -> V_74 -= V_62 -> V_74 ;
V_62 -> V_74 = 0 ;
}
return F_51 ( V_2 , V_62 ) ;
V_119:
F_4 ( L_39 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_61 * V_62 ,
T_1 V_126 , T_1 V_127 , int V_128 )
{
struct V_75 V_129 ;
union V_12 * V_41 ;
struct V_130 * V_131 ;
struct V_56 V_132 [ 2 ] ;
T_1 V_133 ;
void * V_134 ;
int V_114 ;
T_3 V_135 ;
if ( V_128 + V_127 > V_5 ) {
F_9 ( V_2 -> V_6 ) ;
F_4 ( L_40 ,
V_127 , V_128 , V_62 -> V_42 ) ;
return 0 ;
}
if ( V_128 < 0 ) {
F_9 ( V_2 -> V_6 ) ;
F_4 ( L_41 ,
V_128 ) ;
return 0 ;
}
memset ( V_2 -> V_6 -> V_10 , 0xff , V_127 ) ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_116 = F_48 ( V_117 ) ;
V_129 . V_18 = F_48 ( V_69 ) ;
V_129 . V_43 = F_17 ( V_126 ) ;
V_129 . V_118 = F_17 ( F_49 ( 0 , & V_129 , sizeof( struct V_112 ) - 4 ) ) ;
V_129 . V_136 = F_17 ( V_2 -> V_6 -> V_36 ) ;
V_129 . V_122 = F_17 ( V_2 -> V_123 ) ;
V_129 . V_21 = F_17 ( V_2 -> V_6 -> V_21 ) ;
V_134 = V_2 -> V_6 -> V_10 ;
while ( V_2 -> V_6 -> V_21 ) {
V_41 = V_2 -> V_6 -> V_14 ;
switch ( F_11 ( V_41 -> V_16 . V_18 ) ) {
case V_19 : {
struct V_83 * V_137 = V_134 ;
V_137 -> V_18 = V_41 -> V_22 . V_18 ;
V_137 -> V_23 = V_41 -> V_22 . V_23 ;
V_137 -> V_32 = V_41 -> V_22 . V_32 ;
V_137 -> V_42 = V_41 -> V_22 . V_42 ;
V_137 -> V_43 = V_41 -> V_22 . V_43 ;
V_134 += V_20 ;
break;
}
case V_24 : {
struct V_86 * V_138 = V_134 ;
V_138 -> V_18 = V_41 -> V_25 . V_18 ;
V_138 -> V_43 = V_41 -> V_25 . V_43 ;
V_138 -> V_42 = V_41 -> V_25 . V_42 ;
V_138 -> V_47 = V_41 -> V_25 . V_47 ;
V_138 -> V_32 = V_41 -> V_25 . V_32 ;
V_138 -> V_27 = V_41 -> V_25 . V_27 ;
V_138 -> V_26 = V_41 -> V_25 . V_26 ;
V_138 -> type = V_41 -> V_25 . type ;
memcpy ( V_138 -> V_48 , V_41 -> V_25 . V_48 ,
V_41 -> V_25 . V_26 ) ;
V_134 += F_13 ( V_41 -> V_25 . V_26 ) ;
break;
}
#ifdef F_14
case V_28 : {
struct V_96 * V_139 = V_134 ;
V_41 = V_2 -> V_6 -> V_14 ;
V_139 -> V_18 = V_41 -> V_30 . V_18 ;
V_139 -> V_31 = V_41 -> V_30 . V_31 ;
V_139 -> V_32 = V_41 -> V_30 . V_32 ;
V_139 -> V_42 = V_41 -> V_30 . V_42 ;
V_139 -> V_43 = V_41 -> V_30 . V_43 ;
V_134 += V_29 ;
break;
}
case V_33 : {
struct V_101 * V_140 = V_134 ;
V_41 = V_2 -> V_6 -> V_14 ;
V_140 -> V_18 = V_41 -> V_66 . V_18 ;
V_140 -> V_42 = V_41 -> V_66 . V_42 ;
V_134 += V_34 ;
break;
}
#endif
default : {
if ( ( F_11 ( V_41 -> V_16 . V_18 ) & V_105 )
== V_141 ) {
F_7 ( L_42 ,
F_11 ( V_41 -> V_16 . V_18 ) ) ;
F_9 ( V_2 -> V_6 ) ;
} else {
F_26 () ;
}
}
}
V_2 -> V_6 -> V_14 = V_41 -> V_16 . V_17 ;
F_6 ( V_41 ) ;
V_2 -> V_6 -> V_21 -- ;
}
F_22 ( V_2 -> V_6 ) ;
V_134 += V_128 ;
V_131 = V_134 ;
V_131 -> V_42 = F_17 ( V_2 -> V_4 - V_62 -> V_74 ) ;
V_131 -> V_116 = F_17 ( V_142 ) ;
V_129 . V_121 = F_17 ( F_49 ( 0 , V_2 -> V_6 -> V_10 , V_127 ) ) ;
V_129 . V_120 = F_17 ( F_49 ( 0 , & V_129 , sizeof( V_129 ) - 8 ) ) ;
V_132 [ 0 ] . V_63 = & V_129 ;
V_132 [ 0 ] . V_143 = sizeof( V_129 ) ;
V_132 [ 1 ] . V_63 = V_2 -> V_6 -> V_10 ;
V_132 [ 1 ] . V_143 = V_127 ;
V_133 = V_62 -> V_42 + V_2 -> V_4 - V_62 -> V_74 ;
F_7 ( L_43 ,
V_133 ) ;
V_114 = F_53 ( V_2 , V_132 , 2 , V_133 , & V_135 , 0 ) ;
if ( V_114 || ( V_135 != V_126 ) ) {
F_4 ( L_44 ,
V_126 , V_133 , V_114 , V_135 ) ;
if ( V_135 ) {
F_54 ( & V_2 -> V_144 ) ;
F_29 ( V_2 , V_62 , V_133 | V_145 , V_126 , NULL ) ;
F_55 ( & V_2 -> V_144 ) ;
}
V_2 -> V_6 -> V_3 = V_55 ;
return 0 ;
}
F_54 ( & V_2 -> V_144 ) ;
F_29 ( V_2 , V_62 , V_133 | V_125 , V_126 , NULL ) ;
F_55 ( & V_2 -> V_144 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_127 , V_126 , V_128 ;
struct V_61 * V_62 ;
int V_114 = 0 ;
F_7 ( L_4 ) ;
F_55 ( & V_2 -> V_144 ) ;
V_62 = V_2 -> V_146 ;
F_32 ( V_2 , V_62 , 1 ) ;
if ( ! V_2 -> V_6 -> V_21 || ! V_2 -> V_6 -> V_14 ) {
F_4 ( L_45 ) ;
F_26 () ;
}
V_127 = V_2 -> V_6 -> V_3 + sizeof( struct V_130 ) ;
V_126 = sizeof( struct V_75 ) + V_127 ;
V_128 = V_62 -> V_74 - V_126 ;
V_126 += V_128 ;
V_127 += V_128 ;
V_114 = F_52 ( V_2 , V_62 , V_126 , V_127 , V_128 ) ;
F_54 ( & V_2 -> V_144 ) ;
return V_114 ;
}
