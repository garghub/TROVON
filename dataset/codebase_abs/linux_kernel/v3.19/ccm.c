static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_3 ) ) ;
return ( void * ) F_4 ( ( V_5 * ) F_5 ( V_3 ) , V_4 + 1 ) ;
}
static int F_6 ( V_5 * V_6 , unsigned int V_7 , int V_8 )
{
T_1 V_9 ;
memset ( V_6 , 0 , V_8 ) ;
V_6 += V_8 ;
if ( V_8 >= 4 )
V_8 = 4 ;
else if ( V_7 > ( 1 << ( 8 * V_8 ) ) )
return - V_10 ;
V_9 = F_7 ( V_7 ) ;
memcpy ( V_6 - V_8 , ( V_5 * ) & V_9 + 4 - V_8 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , const V_5 * V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_16 -> V_21 ;
int V_22 = 0 ;
F_10 ( V_18 , V_23 ) ;
F_11 ( V_18 , F_12 ( V_12 ) &
V_23 ) ;
V_22 = F_13 ( V_18 , V_13 , V_14 ) ;
F_14 ( V_12 , F_15 ( V_18 ) &
V_24 ) ;
if ( V_22 )
goto V_25;
F_16 ( V_20 , V_23 ) ;
F_17 ( V_20 , F_12 ( V_12 ) &
V_23 ) ;
V_22 = F_18 ( V_20 , V_13 , V_14 ) ;
F_14 ( V_12 , F_19 ( V_20 ) &
V_24 ) ;
V_25:
return V_22 ;
}
static int F_20 ( struct V_11 * V_20 ,
unsigned int V_26 )
{
switch ( V_26 ) {
case 4 :
case 6 :
case 8 :
case 10 :
case 12 :
case 14 :
case 16 :
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_21 ( V_5 * V_28 , struct V_2 * V_3 ,
unsigned int V_29 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
unsigned int V_30 = V_3 -> V_31 [ 0 ] ;
unsigned int V_32 = V_30 + 1 ;
unsigned int V_33 ;
V_33 = F_22 ( V_12 ) ;
memcpy ( V_28 , V_3 -> V_31 , 16 ) ;
* V_28 |= ( 8 * ( ( V_33 - 2 ) / 2 ) ) ;
if ( V_3 -> V_34 )
* V_28 |= 64 ;
return F_6 ( V_28 + 16 - V_32 , V_29 , V_32 ) ;
}
static int F_23 ( V_5 * V_35 , unsigned int V_36 )
{
int V_37 = 0 ;
if ( V_36 < 65280 ) {
* ( V_38 * ) V_35 = F_24 ( V_36 ) ;
V_37 = 2 ;
} else {
* ( V_38 * ) V_35 = F_24 ( 0xfffe ) ;
* ( T_1 * ) & V_35 [ 2 ] = F_7 ( V_36 ) ;
V_37 = 6 ;
}
return V_37 ;
}
static void F_25 ( struct V_19 * V_20 , V_5 * V_9 , int V_39 ,
struct V_1 * V_40 )
{
unsigned int V_41 = 16 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_43 = V_40 -> V_43 ;
int V_44 , V_45 ;
V_44 = V_39 ;
V_45 = V_41 - V_40 -> V_46 ;
if ( V_44 >= V_45 ) {
memcpy ( V_43 + V_40 -> V_46 , V_9 , V_45 ) ;
F_26 ( V_42 , V_43 , V_41 ) ;
F_27 ( V_20 , V_42 , V_42 ) ;
V_44 -= V_45 ;
V_9 += V_45 ;
V_40 -> V_46 = 0 ;
}
while ( V_44 >= V_41 ) {
F_26 ( V_42 , V_9 , V_41 ) ;
F_27 ( V_20 , V_42 , V_42 ) ;
V_44 -= V_41 ;
V_9 += V_41 ;
}
if ( V_44 ) {
memcpy ( V_43 + V_40 -> V_46 , V_9 , V_44 ) ;
V_40 -> V_46 += V_44 ;
}
}
static void F_28 ( struct V_19 * V_20 ,
struct V_1 * V_40 ,
struct V_47 * V_48 , unsigned int V_37 )
{
struct V_49 V_50 ;
V_5 * V_51 ;
int V_39 ;
F_29 ( & V_50 , V_48 ) ;
while ( V_37 ) {
V_39 = F_30 ( & V_50 , V_37 ) ;
if ( ! V_39 ) {
F_29 ( & V_50 , F_31 ( V_50 . V_48 ) ) ;
V_39 = F_30 ( & V_50 , V_37 ) ;
}
V_51 = F_32 ( & V_50 ) ;
F_25 ( V_20 , V_51 , V_39 , V_40 ) ;
V_37 -= V_39 ;
F_33 ( V_51 ) ;
F_34 ( & V_50 , V_39 ) ;
F_35 ( & V_50 , 0 , V_37 ) ;
if ( V_37 )
F_36 ( V_40 -> V_52 ) ;
}
if ( V_40 -> V_46 ) {
int V_53 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_43 = V_40 -> V_43 ;
V_53 = 16 - V_40 -> V_46 ;
memset ( V_43 + V_40 -> V_46 , 0 , V_53 ) ;
F_26 ( V_42 , V_43 , 16 ) ;
F_27 ( V_20 , V_42 , V_42 ) ;
V_40 -> V_46 = 0 ;
}
}
static int F_37 ( struct V_2 * V_3 , struct V_47 * V_54 ,
unsigned int V_29 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_19 * V_21 = V_16 -> V_21 ;
unsigned int V_34 = V_3 -> V_34 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_43 = V_40 -> V_43 ;
int V_22 ;
V_22 = F_21 ( V_42 , V_3 , V_29 ) ;
if ( V_22 )
goto V_25;
F_27 ( V_21 , V_42 , V_42 ) ;
if ( V_34 ) {
V_40 -> V_46 = F_23 ( V_43 , V_34 ) ;
F_28 ( V_21 , V_40 , V_3 -> V_55 , V_3 -> V_34 ) ;
} else {
V_40 -> V_46 = 0 ;
}
if ( V_29 )
F_28 ( V_21 , V_40 , V_54 , V_29 ) ;
V_25:
return V_22 ;
}
static void F_38 ( struct V_56 * V_57 , int V_22 )
{
struct V_2 * V_3 = V_57 -> V_9 ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
V_5 * V_42 = V_40 -> V_42 ;
if ( ! V_22 )
F_39 ( V_42 , V_3 -> V_58 , V_3 -> V_29 ,
F_22 ( V_12 ) , 1 ) ;
F_40 ( V_3 , V_22 ) ;
}
static inline int F_41 ( const V_5 * V_31 )
{
if ( 1 > V_31 [ 0 ] || V_31 [ 0 ] > 7 )
return - V_27 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_59 * V_60 = & V_40 -> V_60 ;
struct V_47 * V_58 ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_22 ;
V_22 = F_41 ( V_31 ) ;
if ( V_22 )
return V_22 ;
V_40 -> V_52 = F_43 ( V_3 ) ;
V_22 = F_37 ( V_3 , V_3 -> V_61 , V_29 ) ;
if ( V_22 )
return V_22 ;
memset ( V_31 + 15 - V_31 [ 0 ] , 0 , V_31 [ 0 ] + 1 ) ;
F_44 ( V_40 -> V_61 , 2 ) ;
F_45 ( V_40 -> V_61 , V_42 , 16 ) ;
F_46 ( V_40 -> V_61 , 2 , V_3 -> V_61 ) ;
V_58 = V_40 -> V_61 ;
if ( V_3 -> V_61 != V_3 -> V_58 ) {
F_44 ( V_40 -> V_58 , 2 ) ;
F_45 ( V_40 -> V_58 , V_42 , 16 ) ;
F_46 ( V_40 -> V_58 , 2 , V_3 -> V_58 ) ;
V_58 = V_40 -> V_58 ;
}
F_47 ( V_60 , V_16 -> V_18 ) ;
F_48 ( V_60 , V_40 -> V_52 ,
F_38 , V_3 ) ;
F_49 ( V_60 , V_40 -> V_61 , V_58 , V_29 + 16 , V_31 ) ;
V_22 = F_50 ( V_60 ) ;
if ( V_22 )
return V_22 ;
F_39 ( V_42 , V_3 -> V_58 , V_29 ,
F_22 ( V_12 ) , 1 ) ;
return V_22 ;
}
static void F_51 ( struct V_56 * V_57 ,
int V_22 )
{
struct V_2 * V_3 = V_57 -> V_9 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 - V_26 ;
if ( ! V_22 ) {
V_22 = F_37 ( V_3 , V_3 -> V_58 , V_29 ) ;
if ( ! V_22 && F_52 ( V_40 -> V_62 , V_40 -> V_42 , V_26 ) )
V_22 = - V_63 ;
}
F_40 ( V_3 , V_22 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_59 * V_60 = & V_40 -> V_60 ;
struct V_47 * V_58 ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_64 = V_40 -> V_62 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_22 ;
if ( V_29 < V_26 )
return - V_27 ;
V_29 -= V_26 ;
V_22 = F_41 ( V_31 ) ;
if ( V_22 )
return V_22 ;
V_40 -> V_52 = F_43 ( V_3 ) ;
F_39 ( V_64 , V_3 -> V_61 , V_29 , V_26 , 0 ) ;
memset ( V_31 + 15 - V_31 [ 0 ] , 0 , V_31 [ 0 ] + 1 ) ;
F_44 ( V_40 -> V_61 , 2 ) ;
F_45 ( V_40 -> V_61 , V_64 , 16 ) ;
F_46 ( V_40 -> V_61 , 2 , V_3 -> V_61 ) ;
V_58 = V_40 -> V_61 ;
if ( V_3 -> V_61 != V_3 -> V_58 ) {
F_44 ( V_40 -> V_58 , 2 ) ;
F_45 ( V_40 -> V_58 , V_64 , 16 ) ;
F_46 ( V_40 -> V_58 , 2 , V_3 -> V_58 ) ;
V_58 = V_40 -> V_58 ;
}
F_47 ( V_60 , V_16 -> V_18 ) ;
F_48 ( V_60 , V_40 -> V_52 ,
F_51 , V_3 ) ;
F_49 ( V_60 , V_40 -> V_61 , V_58 , V_29 + 16 , V_31 ) ;
V_22 = F_54 ( V_60 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_37 ( V_3 , V_3 -> V_58 , V_29 ) ;
if ( V_22 )
return V_22 ;
if ( F_52 ( V_64 , V_42 , V_26 ) )
return - V_63 ;
return V_22 ;
}
static int F_55 ( struct V_65 * V_20 )
{
struct V_66 * V_67 = ( void * ) V_20 -> V_68 ;
struct V_69 * V_70 = F_56 ( V_67 ) ;
struct V_15 * V_16 = F_57 ( V_20 ) ;
struct V_19 * V_21 ;
struct V_17 * V_18 ;
unsigned long V_4 ;
int V_22 ;
V_21 = F_58 ( & V_70 -> V_21 ) ;
if ( F_59 ( V_21 ) )
return F_60 ( V_21 ) ;
V_18 = F_61 ( & V_70 -> V_18 ) ;
V_22 = F_60 ( V_18 ) ;
if ( F_59 ( V_18 ) )
goto V_71;
V_16 -> V_21 = V_21 ;
V_16 -> V_18 = V_18 ;
V_4 = F_62 ( V_20 ) ;
V_4 &= ~ ( F_63 () - 1 ) ;
V_20 -> V_72 . V_73 = V_4 +
sizeof( struct V_1 ) +
F_64 ( V_18 ) ;
return 0 ;
V_71:
F_65 ( V_21 ) ;
return V_22 ;
}
static void F_66 ( struct V_65 * V_20 )
{
struct V_15 * V_16 = F_57 ( V_20 ) ;
F_65 ( V_16 -> V_21 ) ;
F_67 ( V_16 -> V_18 ) ;
}
static struct V_66 * F_68 ( struct V_74 * * V_75 ,
const char * V_76 ,
const char * V_77 ,
const char * V_78 )
{
struct V_79 * V_80 ;
struct V_66 * V_67 ;
struct V_81 * V_18 ;
struct V_81 * V_21 ;
struct V_69 * V_70 ;
int V_22 ;
V_80 = F_69 ( V_75 ) ;
if ( F_59 ( V_80 ) )
return F_70 ( V_80 ) ;
if ( ( V_80 -> type ^ V_82 ) & V_80 -> V_83 )
return F_71 ( - V_27 ) ;
V_21 = F_72 ( V_78 , V_84 ,
V_85 ) ;
if ( F_59 ( V_21 ) )
return F_70 ( V_21 ) ;
V_22 = - V_27 ;
if ( V_21 -> V_86 != 16 )
goto V_87;
V_67 = F_73 ( sizeof( * V_67 ) + sizeof( * V_70 ) , V_88 ) ;
V_22 = - V_89 ;
if ( ! V_67 )
goto V_87;
V_70 = F_56 ( V_67 ) ;
V_22 = F_74 ( & V_70 -> V_21 , V_21 , V_67 ,
V_85 ) ;
if ( V_22 )
goto V_90;
F_75 ( & V_70 -> V_18 , V_67 ) ;
V_22 = F_76 ( & V_70 -> V_18 , V_77 , 0 ,
F_77 ( V_80 -> type ,
V_80 -> V_83 ) ) ;
if ( V_22 )
goto V_91;
V_18 = F_78 ( & V_70 -> V_18 ) ;
V_22 = - V_27 ;
if ( V_18 -> V_86 != 1 )
goto V_92;
if ( V_18 -> V_93 . V_94 != 16 )
goto V_92;
V_22 = - V_95 ;
if ( snprintf ( V_67 -> V_96 . V_97 , V_98 ,
L_1 , V_18 -> V_97 ,
V_21 -> V_97 ) >= V_98 )
goto V_92;
memcpy ( V_67 -> V_96 . V_99 , V_76 , V_98 ) ;
V_67 -> V_96 . V_100 = V_82 ;
V_67 -> V_96 . V_100 |= V_18 -> V_100 & V_101 ;
V_67 -> V_96 . V_102 = V_21 -> V_102 + V_18 -> V_102 ;
V_67 -> V_96 . V_86 = 1 ;
V_67 -> V_96 . V_103 = V_21 -> V_103 | V_18 -> V_103 |
( F_79 ( V_104 ) - 1 ) ;
V_67 -> V_96 . V_105 = & V_106 ;
V_67 -> V_96 . V_107 . V_94 = 16 ;
V_67 -> V_96 . V_107 . V_108 = 16 ;
V_67 -> V_96 . V_109 = sizeof( struct V_15 ) ;
V_67 -> V_96 . V_110 = F_55 ;
V_67 -> V_96 . V_111 = F_66 ;
V_67 -> V_96 . V_107 . V_112 = F_8 ;
V_67 -> V_96 . V_107 . V_113 = F_20 ;
V_67 -> V_96 . V_107 . V_114 = F_42 ;
V_67 -> V_96 . V_107 . V_115 = F_53 ;
V_25:
F_80 ( V_21 ) ;
return V_67 ;
V_92:
F_81 ( & V_70 -> V_18 ) ;
V_91:
F_82 ( & V_70 -> V_21 ) ;
V_90:
F_83 ( V_67 ) ;
V_87:
V_67 = F_71 ( V_22 ) ;
goto V_25;
}
static struct V_66 * F_84 ( struct V_74 * * V_75 )
{
const char * V_78 ;
char V_77 [ V_98 ] ;
char V_76 [ V_98 ] ;
V_78 = F_85 ( V_75 [ 1 ] ) ;
if ( F_59 ( V_78 ) )
return F_70 ( V_78 ) ;
if ( snprintf ( V_77 , V_98 , L_2 ,
V_78 ) >= V_98 )
return F_71 ( - V_95 ) ;
if ( snprintf ( V_76 , V_98 , L_3 , V_78 ) >=
V_98 )
return F_71 ( - V_95 ) ;
return F_68 ( V_75 , V_76 , V_77 , V_78 ) ;
}
static void F_86 ( struct V_66 * V_67 )
{
struct V_69 * V_16 = F_56 ( V_67 ) ;
F_82 ( & V_16 -> V_21 ) ;
F_81 ( & V_16 -> V_18 ) ;
F_83 ( V_67 ) ;
}
static struct V_66 * F_87 ( struct V_74 * * V_75 )
{
const char * V_77 ;
const char * V_78 ;
char V_76 [ V_98 ] ;
V_77 = F_85 ( V_75 [ 1 ] ) ;
if ( F_59 ( V_77 ) )
return F_70 ( V_77 ) ;
V_78 = F_85 ( V_75 [ 2 ] ) ;
if ( F_59 ( V_78 ) )
return F_70 ( V_78 ) ;
if ( snprintf ( V_76 , V_98 , L_1 ,
V_77 , V_78 ) >= V_98 )
return F_71 ( - V_95 ) ;
return F_68 ( V_75 , V_76 , V_77 , V_78 ) ;
}
static int F_88 ( struct V_11 * V_116 , const V_5 * V_13 ,
unsigned int V_14 )
{
struct V_117 * V_16 = F_9 ( V_116 ) ;
struct V_11 * V_118 = V_16 -> V_118 ;
int V_22 ;
if ( V_14 < 3 )
return - V_27 ;
V_14 -= 3 ;
memcpy ( V_16 -> V_119 , V_13 + V_14 , 3 ) ;
F_89 ( V_118 , V_23 ) ;
F_14 ( V_118 , F_12 ( V_116 ) &
V_23 ) ;
V_22 = F_90 ( V_118 , V_13 , V_14 ) ;
F_14 ( V_116 , F_12 ( V_118 ) &
V_24 ) ;
return V_22 ;
}
static int F_91 ( struct V_11 * V_116 ,
unsigned int V_26 )
{
struct V_117 * V_16 = F_9 ( V_116 ) ;
switch ( V_26 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_27 ;
}
return F_92 ( V_16 -> V_118 , V_26 ) ;
}
static struct V_2 * F_93 ( struct V_2 * V_3 )
{
struct V_2 * V_120 = F_5 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_117 * V_16 = F_9 ( V_12 ) ;
struct V_11 * V_118 = V_16 -> V_118 ;
V_5 * V_31 = F_4 ( ( V_5 * ) ( V_120 + 1 ) + F_94 ( V_118 ) ,
F_2 ( V_118 ) + 1 ) ;
V_31 [ 0 ] = 3 ;
memcpy ( V_31 + 1 , V_16 -> V_119 , 3 ) ;
memcpy ( V_31 + 4 , V_3 -> V_31 , 8 ) ;
F_95 ( V_120 , V_118 ) ;
F_96 ( V_120 , V_3 -> V_121 . V_52 , V_3 -> V_121 . V_122 ,
V_3 -> V_121 . V_9 ) ;
F_97 ( V_120 , V_3 -> V_61 , V_3 -> V_58 , V_3 -> V_29 , V_31 ) ;
F_98 ( V_120 , V_3 -> V_55 , V_3 -> V_34 ) ;
return V_120 ;
}
static int F_99 ( struct V_2 * V_3 )
{
V_3 = F_93 ( V_3 ) ;
return F_100 ( V_3 ) ;
}
static int F_101 ( struct V_2 * V_3 )
{
V_3 = F_93 ( V_3 ) ;
return F_102 ( V_3 ) ;
}
static int F_103 ( struct V_65 * V_20 )
{
struct V_66 * V_67 = ( void * ) V_20 -> V_68 ;
struct V_123 * V_124 = F_56 ( V_67 ) ;
struct V_117 * V_16 = F_57 ( V_20 ) ;
struct V_11 * V_12 ;
unsigned long V_4 ;
V_12 = F_104 ( V_124 ) ;
if ( F_59 ( V_12 ) )
return F_60 ( V_12 ) ;
V_16 -> V_118 = V_12 ;
V_4 = F_2 ( V_12 ) ;
V_4 &= ~ ( F_63 () - 1 ) ;
V_20 -> V_72 . V_73 = sizeof( struct V_2 ) +
F_105 ( F_94 ( V_12 ) ,
F_63 () ) +
V_4 + 16 ;
return 0 ;
}
static void F_106 ( struct V_65 * V_20 )
{
struct V_117 * V_16 = F_57 ( V_20 ) ;
F_107 ( V_16 -> V_118 ) ;
}
static struct V_66 * F_108 ( struct V_74 * * V_75 )
{
struct V_79 * V_80 ;
struct V_66 * V_67 ;
struct V_123 * V_124 ;
struct V_81 * V_96 ;
const char * V_125 ;
int V_22 ;
V_80 = F_69 ( V_75 ) ;
if ( F_59 ( V_80 ) )
return F_70 ( V_80 ) ;
if ( ( V_80 -> type ^ V_82 ) & V_80 -> V_83 )
return F_71 ( - V_27 ) ;
V_125 = F_85 ( V_75 [ 1 ] ) ;
if ( F_59 ( V_125 ) )
return F_70 ( V_125 ) ;
V_67 = F_73 ( sizeof( * V_67 ) + sizeof( * V_124 ) , V_88 ) ;
if ( ! V_67 )
return F_71 ( - V_89 ) ;
V_124 = F_56 ( V_67 ) ;
F_109 ( V_124 , V_67 ) ;
V_22 = F_110 ( V_124 , V_125 , 0 ,
F_77 ( V_80 -> type , V_80 -> V_83 ) ) ;
if ( V_22 )
goto V_126;
V_96 = F_111 ( V_124 ) ;
V_22 = - V_27 ;
if ( V_96 -> V_107 . V_94 != 16 )
goto V_127;
if ( V_96 -> V_86 != 1 )
goto V_127;
V_22 = - V_95 ;
if ( snprintf ( V_67 -> V_96 . V_99 , V_98 ,
L_4 , V_96 -> V_99 ) >= V_98 ||
snprintf ( V_67 -> V_96 . V_97 , V_98 ,
L_4 , V_96 -> V_97 ) >=
V_98 )
goto V_127;
V_67 -> V_96 . V_100 = V_82 ;
V_67 -> V_96 . V_100 |= V_96 -> V_100 & V_101 ;
V_67 -> V_96 . V_102 = V_96 -> V_102 ;
V_67 -> V_96 . V_86 = 1 ;
V_67 -> V_96 . V_103 = V_96 -> V_103 ;
V_67 -> V_96 . V_105 = & V_128 ;
V_67 -> V_96 . V_107 . V_94 = 8 ;
V_67 -> V_96 . V_107 . V_108 = 16 ;
V_67 -> V_96 . V_109 = sizeof( struct V_117 ) ;
V_67 -> V_96 . V_110 = F_103 ;
V_67 -> V_96 . V_111 = F_106 ;
V_67 -> V_96 . V_107 . V_112 = F_88 ;
V_67 -> V_96 . V_107 . V_113 = F_91 ;
V_67 -> V_96 . V_107 . V_114 = F_99 ;
V_67 -> V_96 . V_107 . V_115 = F_101 ;
V_67 -> V_96 . V_107 . V_129 = L_5 ;
V_25:
return V_67 ;
V_127:
F_112 ( V_124 ) ;
V_126:
F_83 ( V_67 ) ;
V_67 = F_71 ( V_22 ) ;
goto V_25;
}
static void F_113 ( struct V_66 * V_67 )
{
F_82 ( F_56 ( V_67 ) ) ;
F_83 ( V_67 ) ;
}
static int T_2 F_114 ( void )
{
int V_22 ;
V_22 = F_115 ( & V_130 ) ;
if ( V_22 )
goto V_25;
V_22 = F_115 ( & V_131 ) ;
if ( V_22 )
goto V_132;
V_22 = F_115 ( & V_133 ) ;
if ( V_22 )
goto V_134;
V_25:
return V_22 ;
V_134:
F_116 ( & V_131 ) ;
V_132:
F_116 ( & V_130 ) ;
goto V_25;
}
static void T_3 F_117 ( void )
{
F_116 ( & V_133 ) ;
F_116 ( & V_131 ) ;
F_116 ( & V_130 ) ;
}
