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
F_39 ( V_42 , V_3 -> V_58 ,
V_3 -> V_34 + V_3 -> V_29 ,
F_22 ( V_12 ) , 1 ) ;
F_40 ( V_3 , V_22 ) ;
}
static inline int F_41 ( const V_5 * V_31 )
{
if ( 1 > V_31 [ 0 ] || V_31 [ 0 ] > 7 )
return - V_27 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , V_5 * V_59 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_47 * V_48 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_22 ;
V_22 = F_41 ( V_31 ) ;
if ( V_22 )
return V_22 ;
V_40 -> V_52 = F_43 ( V_3 ) ;
memset ( V_31 + 15 - V_31 [ 0 ] , 0 , V_31 [ 0 ] + 1 ) ;
F_44 ( V_40 -> V_55 , 3 ) ;
F_45 ( V_40 -> V_55 , V_59 , 16 ) ;
V_48 = F_46 ( V_40 -> V_55 + 1 , V_3 -> V_55 , V_3 -> V_34 ) ;
if ( V_48 != V_40 -> V_55 + 1 )
F_47 ( V_40 -> V_55 , 2 , V_48 ) ;
if ( V_3 -> V_55 != V_3 -> V_58 ) {
F_44 ( V_40 -> V_58 , 3 ) ;
F_45 ( V_40 -> V_58 , V_59 , 16 ) ;
V_48 = F_46 ( V_40 -> V_58 + 1 , V_3 -> V_58 , V_3 -> V_34 ) ;
if ( V_48 != V_40 -> V_58 + 1 )
F_47 ( V_40 -> V_58 , 2 , V_48 ) ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_60 * V_61 = & V_40 -> V_61 ;
struct V_47 * V_58 ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_22 ;
V_22 = F_42 ( V_3 , V_42 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_37 ( V_3 , F_31 ( V_40 -> V_55 ) , V_29 ) ;
if ( V_22 )
return V_22 ;
V_58 = V_40 -> V_55 ;
if ( V_3 -> V_55 != V_3 -> V_58 )
V_58 = V_40 -> V_58 ;
F_49 ( V_61 , V_16 -> V_18 ) ;
F_50 ( V_61 , V_40 -> V_52 ,
F_38 , V_3 ) ;
F_51 ( V_61 , V_40 -> V_55 , V_58 , V_29 + 16 , V_31 ) ;
V_22 = F_52 ( V_61 ) ;
if ( V_22 )
return V_22 ;
F_39 ( V_42 , F_31 ( V_58 ) , V_29 ,
F_22 ( V_12 ) , 1 ) ;
return V_22 ;
}
static void F_53 ( struct V_56 * V_57 ,
int V_22 )
{
struct V_2 * V_3 = V_57 -> V_9 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 - V_26 ;
struct V_47 * V_58 ;
V_40 -> V_52 = 0 ;
V_58 = F_31 ( V_3 -> V_55 == V_3 -> V_58 ? V_40 -> V_55 : V_40 -> V_58 ) ;
if ( ! V_22 ) {
V_22 = F_37 ( V_3 , V_58 , V_29 ) ;
if ( ! V_22 && F_54 ( V_40 -> V_62 , V_40 -> V_42 , V_26 ) )
V_22 = - V_63 ;
}
F_40 ( V_3 , V_22 ) ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_60 * V_61 = & V_40 -> V_61 ;
struct V_47 * V_58 ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_64 = V_40 -> V_62 ;
V_5 * V_42 = V_40 -> V_42 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_22 ;
V_29 -= V_26 ;
V_22 = F_42 ( V_3 , V_64 ) ;
if ( V_22 )
return V_22 ;
F_39 ( V_64 , F_31 ( V_40 -> V_55 ) , V_29 ,
V_26 , 0 ) ;
V_58 = V_40 -> V_55 ;
if ( V_3 -> V_55 != V_3 -> V_58 )
V_58 = V_40 -> V_58 ;
F_49 ( V_61 , V_16 -> V_18 ) ;
F_50 ( V_61 , V_40 -> V_52 ,
F_53 , V_3 ) ;
F_51 ( V_61 , V_40 -> V_55 , V_58 , V_29 + 16 , V_31 ) ;
V_22 = F_56 ( V_61 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_37 ( V_3 , F_31 ( V_58 ) , V_29 ) ;
if ( V_22 )
return V_22 ;
if ( F_54 ( V_64 , V_42 , V_26 ) )
return - V_63 ;
return V_22 ;
}
static int F_57 ( struct V_11 * V_20 )
{
struct V_65 * V_66 = F_58 ( V_20 ) ;
struct V_67 * V_68 = F_59 ( V_66 ) ;
struct V_15 * V_16 = F_9 ( V_20 ) ;
struct V_19 * V_21 ;
struct V_17 * V_18 ;
unsigned long V_4 ;
int V_22 ;
V_21 = F_60 ( & V_68 -> V_21 ) ;
if ( F_61 ( V_21 ) )
return F_62 ( V_21 ) ;
V_18 = F_63 ( & V_68 -> V_18 ) ;
V_22 = F_62 ( V_18 ) ;
if ( F_61 ( V_18 ) )
goto V_69;
V_16 -> V_21 = V_21 ;
V_16 -> V_18 = V_18 ;
V_4 = F_2 ( V_20 ) ;
V_4 &= ~ ( F_64 () - 1 ) ;
F_65 (
V_20 ,
V_4 + sizeof( struct V_1 ) +
F_66 ( V_18 ) ) ;
return 0 ;
V_69:
F_67 ( V_21 ) ;
return V_22 ;
}
static void F_68 ( struct V_11 * V_20 )
{
struct V_15 * V_16 = F_9 ( V_20 ) ;
F_67 ( V_16 -> V_21 ) ;
F_69 ( V_16 -> V_18 ) ;
}
static void F_70 ( struct V_65 * V_66 )
{
struct V_67 * V_16 = F_59 ( V_66 ) ;
F_71 ( & V_16 -> V_21 ) ;
F_72 ( & V_16 -> V_18 ) ;
F_73 ( V_66 ) ;
}
static int F_74 ( struct V_70 * V_71 ,
struct V_72 * * V_73 ,
const char * V_74 ,
const char * V_75 ,
const char * V_76 )
{
struct V_77 * V_78 ;
struct V_65 * V_66 ;
struct V_79 * V_18 ;
struct V_80 * V_21 ;
struct V_67 * V_68 ;
int V_22 ;
V_78 = F_75 ( V_73 ) ;
if ( F_61 ( V_78 ) )
return F_62 ( V_78 ) ;
if ( ( V_78 -> type ^ V_81 ) & V_78 -> V_82 )
return - V_27 ;
V_21 = F_76 ( V_76 , V_83 ,
V_84 ) ;
if ( F_61 ( V_21 ) )
return F_62 ( V_21 ) ;
V_22 = - V_27 ;
if ( V_21 -> V_85 != 16 )
goto V_86;
V_66 = F_77 ( sizeof( * V_66 ) + sizeof( * V_68 ) , V_87 ) ;
V_22 = - V_88 ;
if ( ! V_66 )
goto V_86;
V_68 = F_59 ( V_66 ) ;
V_22 = F_78 ( & V_68 -> V_21 , V_21 ,
F_79 ( V_66 ) ,
V_84 ) ;
if ( V_22 )
goto V_89;
F_80 ( & V_68 -> V_18 , F_79 ( V_66 ) ) ;
V_22 = F_81 ( & V_68 -> V_18 , V_75 , 0 ,
F_82 ( V_78 -> type ,
V_78 -> V_82 ) ) ;
if ( V_22 )
goto V_90;
V_18 = F_83 ( & V_68 -> V_18 ) ;
V_22 = - V_27 ;
if ( V_18 -> V_91 . V_85 != 1 )
goto V_92;
if ( F_84 ( V_18 ) != 16 )
goto V_92;
V_22 = - V_93 ;
if ( snprintf ( V_66 -> V_94 . V_91 . V_95 , V_96 ,
L_1 , V_18 -> V_91 . V_95 ,
V_21 -> V_95 ) >= V_96 )
goto V_92;
memcpy ( V_66 -> V_94 . V_91 . V_97 , V_74 , V_96 ) ;
V_66 -> V_94 . V_91 . V_98 = V_18 -> V_91 . V_98 & V_99 ;
V_66 -> V_94 . V_91 . V_100 = ( V_21 -> V_100 +
V_18 -> V_91 . V_100 ) / 2 ;
V_66 -> V_94 . V_91 . V_85 = 1 ;
V_66 -> V_94 . V_91 . V_101 = V_21 -> V_101 |
V_18 -> V_91 . V_101 |
( F_85 ( V_102 ) - 1 ) ;
V_66 -> V_94 . V_103 = 16 ;
V_66 -> V_94 . V_104 = F_86 ( V_18 ) ;
V_66 -> V_94 . V_105 = 16 ;
V_66 -> V_94 . V_91 . V_106 = sizeof( struct V_15 ) ;
V_66 -> V_94 . V_107 = F_57 ;
V_66 -> V_94 . exit = F_68 ;
V_66 -> V_94 . V_108 = F_8 ;
V_66 -> V_94 . V_109 = F_20 ;
V_66 -> V_94 . V_110 = F_48 ;
V_66 -> V_94 . V_111 = F_55 ;
V_66 -> free = F_70 ;
V_22 = F_87 ( V_71 , V_66 ) ;
if ( V_22 )
goto V_92;
V_86:
F_88 ( V_21 ) ;
return V_22 ;
V_92:
F_72 ( & V_68 -> V_18 ) ;
V_90:
F_71 ( & V_68 -> V_21 ) ;
V_89:
F_73 ( V_66 ) ;
goto V_86;
}
static int F_89 ( struct V_70 * V_71 , struct V_72 * * V_73 )
{
const char * V_76 ;
char V_75 [ V_96 ] ;
char V_74 [ V_96 ] ;
V_76 = F_90 ( V_73 [ 1 ] ) ;
if ( F_61 ( V_76 ) )
return F_62 ( V_76 ) ;
if ( snprintf ( V_75 , V_96 , L_2 ,
V_76 ) >= V_96 )
return - V_93 ;
if ( snprintf ( V_74 , V_96 , L_3 , V_76 ) >=
V_96 )
return - V_93 ;
return F_74 ( V_71 , V_73 , V_74 , V_75 ,
V_76 ) ;
}
static int F_91 ( struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
const char * V_75 ;
const char * V_76 ;
char V_74 [ V_96 ] ;
V_75 = F_90 ( V_73 [ 1 ] ) ;
if ( F_61 ( V_75 ) )
return F_62 ( V_75 ) ;
V_76 = F_90 ( V_73 [ 2 ] ) ;
if ( F_61 ( V_76 ) )
return F_62 ( V_76 ) ;
if ( snprintf ( V_74 , V_96 , L_1 ,
V_75 , V_76 ) >= V_96 )
return - V_93 ;
return F_74 ( V_71 , V_73 , V_74 , V_75 ,
V_76 ) ;
}
static int F_92 ( struct V_11 * V_112 , const V_5 * V_13 ,
unsigned int V_14 )
{
struct V_113 * V_16 = F_9 ( V_112 ) ;
struct V_11 * V_114 = V_16 -> V_114 ;
int V_22 ;
if ( V_14 < 3 )
return - V_27 ;
V_14 -= 3 ;
memcpy ( V_16 -> V_115 , V_13 + V_14 , 3 ) ;
F_93 ( V_114 , V_23 ) ;
F_14 ( V_114 , F_12 ( V_112 ) &
V_23 ) ;
V_22 = F_94 ( V_114 , V_13 , V_14 ) ;
F_14 ( V_112 , F_12 ( V_114 ) &
V_24 ) ;
return V_22 ;
}
static int F_95 ( struct V_11 * V_112 ,
unsigned int V_26 )
{
struct V_113 * V_16 = F_9 ( V_112 ) ;
switch ( V_26 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_27 ;
}
return F_96 ( V_16 -> V_114 , V_26 ) ;
}
static struct V_2 * F_97 ( struct V_2 * V_3 )
{
struct V_116 * V_117 = F_5 ( V_3 ) ;
struct V_2 * V_118 = & V_117 -> V_118 ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_113 * V_16 = F_9 ( V_12 ) ;
struct V_11 * V_114 = V_16 -> V_114 ;
struct V_47 * V_48 ;
V_5 * V_31 = F_4 ( ( V_5 * ) ( V_118 + 1 ) + F_98 ( V_114 ) ,
F_2 ( V_114 ) + 1 ) ;
V_31 [ 0 ] = 3 ;
memcpy ( V_31 + 1 , V_16 -> V_115 , 3 ) ;
memcpy ( V_31 + 4 , V_3 -> V_31 , 8 ) ;
F_39 ( V_31 + 16 , V_3 -> V_55 , 0 , V_3 -> V_34 - 8 , 0 ) ;
F_44 ( V_117 -> V_55 , 3 ) ;
F_45 ( V_117 -> V_55 , V_31 + 16 , V_3 -> V_34 - 8 ) ;
V_48 = F_46 ( V_117 -> V_55 + 1 , V_3 -> V_55 , V_3 -> V_34 ) ;
if ( V_48 != V_117 -> V_55 + 1 )
F_47 ( V_117 -> V_55 , 2 , V_48 ) ;
if ( V_3 -> V_55 != V_3 -> V_58 ) {
F_44 ( V_117 -> V_58 , 3 ) ;
F_45 ( V_117 -> V_58 , V_31 + 16 , V_3 -> V_34 - 8 ) ;
V_48 = F_46 ( V_117 -> V_58 + 1 , V_3 -> V_58 , V_3 -> V_34 ) ;
if ( V_48 != V_117 -> V_58 + 1 )
F_47 ( V_117 -> V_58 , 2 , V_48 ) ;
}
F_99 ( V_118 , V_114 ) ;
F_100 ( V_118 , V_3 -> V_91 . V_52 , V_3 -> V_91 . V_119 ,
V_3 -> V_91 . V_9 ) ;
F_101 ( V_118 , V_117 -> V_55 ,
V_3 -> V_55 == V_3 -> V_58 ? V_117 -> V_55 : V_117 -> V_58 ,
V_3 -> V_29 , V_31 ) ;
F_102 ( V_118 , V_3 -> V_34 - 8 ) ;
return V_118 ;
}
static int F_103 ( struct V_2 * V_3 )
{
if ( V_3 -> V_34 != 16 && V_3 -> V_34 != 20 )
return - V_27 ;
V_3 = F_97 ( V_3 ) ;
return F_104 ( V_3 ) ;
}
static int F_105 ( struct V_2 * V_3 )
{
if ( V_3 -> V_34 != 16 && V_3 -> V_34 != 20 )
return - V_27 ;
V_3 = F_97 ( V_3 ) ;
return F_106 ( V_3 ) ;
}
static int F_107 ( struct V_11 * V_20 )
{
struct V_65 * V_66 = F_58 ( V_20 ) ;
struct V_120 * V_121 = F_59 ( V_66 ) ;
struct V_113 * V_16 = F_9 ( V_20 ) ;
struct V_11 * V_12 ;
unsigned long V_4 ;
V_12 = F_108 ( V_121 ) ;
if ( F_61 ( V_12 ) )
return F_62 ( V_12 ) ;
V_16 -> V_114 = V_12 ;
V_4 = F_2 ( V_12 ) ;
V_4 &= ~ ( F_64 () - 1 ) ;
F_65 (
V_20 ,
sizeof( struct V_116 ) +
F_109 ( F_98 ( V_12 ) , F_64 () ) +
V_4 + 32 ) ;
return 0 ;
}
static void F_110 ( struct V_11 * V_20 )
{
struct V_113 * V_16 = F_9 ( V_20 ) ;
F_111 ( V_16 -> V_114 ) ;
}
static void F_112 ( struct V_65 * V_66 )
{
F_113 ( F_59 ( V_66 ) ) ;
F_73 ( V_66 ) ;
}
static int F_114 ( struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
struct V_77 * V_78 ;
struct V_65 * V_66 ;
struct V_120 * V_121 ;
struct V_122 * V_94 ;
const char * V_123 ;
int V_22 ;
V_78 = F_75 ( V_73 ) ;
if ( F_61 ( V_78 ) )
return F_62 ( V_78 ) ;
if ( ( V_78 -> type ^ V_81 ) & V_78 -> V_82 )
return - V_27 ;
V_123 = F_90 ( V_73 [ 1 ] ) ;
if ( F_61 ( V_123 ) )
return F_62 ( V_123 ) ;
V_66 = F_77 ( sizeof( * V_66 ) + sizeof( * V_121 ) , V_87 ) ;
if ( ! V_66 )
return - V_88 ;
V_121 = F_59 ( V_66 ) ;
F_115 ( V_121 , F_79 ( V_66 ) ) ;
V_22 = F_116 ( V_121 , V_123 , 0 ,
F_82 ( V_78 -> type , V_78 -> V_82 ) ) ;
if ( V_22 )
goto V_124;
V_94 = F_117 ( V_121 ) ;
V_22 = - V_27 ;
if ( F_118 ( V_94 ) != 16 )
goto V_125;
if ( V_94 -> V_91 . V_85 != 1 )
goto V_125;
V_22 = - V_93 ;
if ( snprintf ( V_66 -> V_94 . V_91 . V_97 , V_96 ,
L_4 , V_94 -> V_91 . V_97 ) >=
V_96 ||
snprintf ( V_66 -> V_94 . V_91 . V_95 , V_96 ,
L_4 , V_94 -> V_91 . V_95 ) >=
V_96 )
goto V_125;
V_66 -> V_94 . V_91 . V_98 = V_94 -> V_91 . V_98 & V_99 ;
V_66 -> V_94 . V_91 . V_100 = V_94 -> V_91 . V_100 ;
V_66 -> V_94 . V_91 . V_85 = 1 ;
V_66 -> V_94 . V_91 . V_101 = V_94 -> V_91 . V_101 ;
V_66 -> V_94 . V_103 = 8 ;
V_66 -> V_94 . V_104 = F_119 ( V_94 ) ;
V_66 -> V_94 . V_105 = 16 ;
V_66 -> V_94 . V_91 . V_106 = sizeof( struct V_113 ) ;
V_66 -> V_94 . V_107 = F_107 ;
V_66 -> V_94 . exit = F_110 ;
V_66 -> V_94 . V_108 = F_92 ;
V_66 -> V_94 . V_109 = F_95 ;
V_66 -> V_94 . V_110 = F_103 ;
V_66 -> V_94 . V_111 = F_105 ;
V_66 -> free = F_112 ;
V_22 = F_87 ( V_71 , V_66 ) ;
if ( V_22 )
goto V_125;
V_25:
return V_22 ;
V_125:
F_113 ( V_121 ) ;
V_124:
F_73 ( V_66 ) ;
goto V_25;
}
static int T_2 F_120 ( void )
{
int V_22 ;
V_22 = F_121 ( & V_126 ) ;
if ( V_22 )
goto V_25;
V_22 = F_121 ( & V_127 ) ;
if ( V_22 )
goto V_128;
V_22 = F_121 ( & V_129 ) ;
if ( V_22 )
goto V_130;
V_25:
return V_22 ;
V_130:
F_122 ( & V_127 ) ;
V_128:
F_122 ( & V_126 ) ;
goto V_25;
}
static void T_3 F_123 ( void )
{
F_122 ( & V_129 ) ;
F_122 ( & V_127 ) ;
F_122 ( & V_126 ) ;
}
