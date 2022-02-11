static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 , V_2 -> V_3 + V_5 ) ;
F_3 ( V_2 -> V_6 , V_2 -> V_3 + V_7 ) ;
F_3 ( V_2 -> V_8 , V_2 -> V_3 + V_9 ) ;
F_3 ( 0x01 |
0x04 ,
V_2 -> V_3 + V_10 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( 0x10 ,
V_2 -> V_3 + V_11 ) ;
F_3 ( V_2 -> V_12 , V_2 -> V_3 + V_13 ) ;
F_3 ( V_2 -> V_14 , V_2 -> V_3 + V_15 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
F_2 ( V_2 -> V_3 ) ;
F_3 ( 0xFFF , V_2 -> V_3 + V_16 ) ;
F_3 ( ( V_2 -> V_17 << 16 |
0x02 |
0x01 ) ,
V_2 -> V_3 + V_18 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 , T_1 V_23 )
{
T_1 V_24 ;
struct V_1 * V_2 = F_8 ( V_20 -> V_25 . V_26 ) ;
if ( V_23 != V_27 )
return - V_28 ;
V_24 = F_9 ( & V_2 -> V_23 , V_29 , V_23 ) ;
if ( V_24 )
return - V_30 ;
F_10 ( V_2 -> V_25 ) ;
F_11 ( & V_2 -> V_31 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_2 -> V_31 ) ;
F_13 ( V_2 -> V_25 , L_1 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_10 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_9 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_7 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_15 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_11 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_2 ( V_2 -> V_3 ) ;
V_24 = F_17 ( V_2 -> V_3 + V_18 ) ;
V_24 &= ~ 0x1 ;
F_3 ( V_24 , V_2 -> V_3 + V_18 ) ;
F_4 ( V_2 -> V_3 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_8 )
F_14 ( V_2 ) ;
}
static void F_18 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_25 . V_26 ) ;
if ( F_19 ( & V_2 -> V_23 ) == V_27 ) {
F_11 ( & V_2 -> V_31 ) ;
F_16 ( V_2 ) ;
F_12 ( & V_2 -> V_31 ) ;
F_20 ( V_2 , V_18 , V_32 , 0 ) ;
F_21 ( V_2 -> V_25 ) ;
F_22 ( & V_2 -> V_23 , V_29 ) ;
F_13 ( V_2 -> V_25 , L_2 ) ;
}
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_25 . V_26 ) ;
return V_2 -> V_17 ;
}
static inline bool F_24 ( const void * V_33 , T_2 V_34 )
{
return ( ( unsigned long ) V_33 & ( V_34 - 1 ) ) ;
}
static void F_25 ( void * V_33 , const void * V_35 , T_1 V_36 , T_2 V_34 )
{
T_2 V_37 [ 8 ] ;
if ( F_24 ( V_35 , V_34 ) ) {
memcpy ( V_37 , V_35 , V_36 ) ;
V_35 = V_37 ;
}
switch ( V_36 ) {
#ifdef F_26
case 8 :
F_27 ( * ( V_38 * ) V_35 , V_33 ) ;
break;
#endif
case 4 :
F_3 ( * ( T_1 * ) V_35 , V_33 ) ;
break;
case 2 :
F_28 ( * ( V_39 * ) V_35 , V_33 ) ;
break;
case 1 :
F_29 ( * ( T_2 * ) V_35 , V_33 ) ;
break;
default:
break;
}
}
static int F_30 ( struct V_40 * V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! V_2 || ! V_2 -> V_20 )
return - V_28 ;
return F_32 ( V_2 -> V_20 ) ;
}
static void F_33 ( struct V_40 * V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! V_2 || ! V_2 -> V_20 )
return;
F_34 ( V_2 -> V_20 ) ;
}
static T_3
F_35 ( struct V_40 * V_40 , unsigned int V_41 ,
unsigned int V_42 , unsigned int V_44 )
{
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
T_3 V_33 ;
V_33 = V_2 -> V_45 . V_46 + V_42 * V_47 ;
if ( F_36 ( V_33 ) ||
F_36 ( V_44 * V_47 ) )
return 0 ;
return V_33 ;
}
static long F_37 ( struct V_40 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 ,
unsigned int V_44 ,
unsigned long V_48 )
{
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! ( V_2 && F_19 ( & V_2 -> V_23 ) ) )
return - V_28 ;
if ( V_42 >= V_2 -> V_49 )
return - V_28 ;
switch ( V_48 ) {
case V_50 :
F_38 ( V_42 , V_2 -> V_45 . V_51 ) ;
break;
case V_52 :
F_39 ( V_42 , V_2 -> V_45 . V_51 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static T_4 T_5 F_40 ( struct V_40 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 ,
unsigned int V_53 ,
unsigned int V_54 ,
unsigned int V_36 ,
const unsigned char * V_55 )
{
unsigned long V_56 ;
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! ( V_2 && F_19 ( & V_2 -> V_23 ) ) )
return - V_57 ;
if ( V_42 >= V_2 -> V_49 )
return - V_28 ;
V_56 = ( unsigned long ) F_41 ( V_2 , V_42 ) ;
V_54 = ( V_54 == V_58 ) ? V_59 : 0 ;
V_54 |= F_42 ( V_42 , V_2 -> V_45 . V_51 ) ?
V_60 : 0 ;
if ( V_36 > V_2 -> V_34 )
V_36 = V_2 -> V_34 ;
else
V_36 = F_43 ( V_36 ) ;
switch ( V_53 ) {
case V_61 :
V_56 |= F_44 ( V_62 , V_54 ) ;
F_25 ( ( void * ) V_56 , V_55 , 1 , V_2 -> V_34 ) ;
V_36 = 1 ;
break;
case V_63 :
V_56 |= F_44 ( V_64 , V_54 ) ;
F_25 ( ( void * ) V_56 , V_55 , V_36 ,
V_2 -> V_34 ) ;
break;
default:
return - V_65 ;
}
return V_36 ;
}
static T_4 F_45 ( struct V_66 * V_25 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 = V_2 -> V_8 ;
return F_46 ( V_69 , V_70 , L_3 , V_24 ) ;
}
static T_4 F_47 ( struct V_66 * V_25 ,
struct V_67 * V_68 ,
const char * V_69 , T_6 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_71 = 0 ;
V_71 = F_48 ( V_69 , 16 , & V_24 ) ;
if ( V_71 )
return - V_28 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_6 = V_24 ;
return V_36 ;
}
static T_4 F_49 ( struct V_66 * V_25 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 = V_2 -> V_4 ;
return F_46 ( V_69 , V_70 , L_3 , V_24 ) ;
}
static T_4 F_50 ( struct V_66 * V_25 ,
struct V_67 * V_68 ,
const char * V_69 , T_6 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_71 = 0 ;
V_71 = F_48 ( V_69 , 16 , & V_24 ) ;
if ( V_71 )
return - V_28 ;
V_2 -> V_4 = V_24 ;
return V_36 ;
}
static T_4 F_51 ( struct V_66 * V_25 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
if ( ! F_19 ( & V_2 -> V_23 ) ) {
V_24 = V_2 -> V_12 ;
} else {
F_11 ( & V_2 -> V_31 ) ;
V_24 = F_17 ( V_2 -> V_3 + V_13 ) ;
F_12 ( & V_2 -> V_31 ) ;
}
return F_46 ( V_69 , V_70 , L_3 , V_24 ) ;
}
static T_4 F_52 ( struct V_66 * V_25 ,
struct V_67 * V_68 ,
const char * V_69 , T_6 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 , V_14 ;
int V_71 = 0 ;
V_71 = F_48 ( V_69 , 16 , & V_24 ) ;
if ( V_71 )
return V_71 ;
F_11 ( & V_2 -> V_31 ) ;
V_2 -> V_12 = V_24 ;
if ( F_19 ( & V_2 -> V_23 ) ) {
F_2 ( V_2 -> V_3 ) ;
V_14 = F_17 ( V_2 -> V_3 + V_15 ) ;
F_3 ( 0x0 , V_2 -> V_3 + V_15 ) ;
F_3 ( V_2 -> V_12 , V_2 -> V_3 + V_13 ) ;
F_3 ( V_14 , V_2 -> V_3 + V_15 ) ;
F_4 ( V_2 -> V_3 ) ;
}
F_12 ( & V_2 -> V_31 ) ;
return V_36 ;
}
static T_4 F_53 ( struct V_66 * V_25 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
if ( ! F_19 ( & V_2 -> V_23 ) ) {
V_24 = V_2 -> V_14 ;
} else {
F_11 ( & V_2 -> V_31 ) ;
V_24 = F_17 ( V_2 -> V_3 + V_15 ) ;
F_12 ( & V_2 -> V_31 ) ;
}
return F_46 ( V_69 , V_70 , L_3 , V_24 ) ;
}
static T_4 F_54 ( struct V_66 * V_25 ,
struct V_67 * V_68 ,
const char * V_69 , T_6 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_71 = 0 ;
V_71 = F_48 ( V_69 , 16 , & V_24 ) ;
if ( V_71 )
return V_71 ;
F_11 ( & V_2 -> V_31 ) ;
V_2 -> V_14 = V_24 ;
if ( F_19 ( & V_2 -> V_23 ) ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_14 , V_2 -> V_3 + V_15 ) ;
F_4 ( V_2 -> V_3 ) ;
}
F_12 ( & V_2 -> V_31 ) ;
return V_36 ;
}
static T_4 F_55 ( struct V_66 * V_25 ,
struct V_67 * V_68 , char * V_69 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
V_24 = V_2 -> V_17 ;
return sprintf ( V_69 , L_3 , V_24 ) ;
}
static T_4 F_56 ( struct V_66 * V_25 ,
struct V_67 * V_68 ,
const char * V_69 , T_6 V_36 )
{
int V_71 ;
unsigned long V_24 ;
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
V_71 = F_48 ( V_69 , 16 , & V_24 ) ;
if ( V_71 )
return V_71 ;
V_2 -> V_17 = V_24 & 0x7f ;
return V_36 ;
}
static int F_57 ( struct V_72 * V_73 ,
char * V_74 , struct V_75 * V_76 )
{
const char * V_77 = NULL ;
int V_78 = 0 , V_79 = 0 ;
while ( ! F_58 ( V_73 , L_4 , V_78 , & V_77 ) ) {
if ( strcmp ( V_74 , V_77 ) ) {
V_78 ++ ;
continue;
}
V_79 = 1 ;
break;
}
if ( ! V_79 )
return - V_28 ;
return F_59 ( V_73 , V_78 , V_76 ) ;
}
static T_1 F_60 ( struct V_1 * V_2 )
{
T_1 V_80 ;
if ( ! F_61 ( F_26 ) )
return 4 ;
V_80 = F_17 ( V_2 -> V_3 + V_81 ) ;
return F_62 ( V_80 , 12 , 15 ) ? 8 : 4 ;
}
static T_1 F_63 ( struct V_1 * V_2 )
{
T_1 V_49 ;
V_49 = F_17 ( V_2 -> V_3 + V_82 ) ;
V_49 &= 0x1ffff ;
if ( ! V_49 )
V_49 = V_83 ;
return V_49 ;
}
static void F_64 ( struct V_1 * V_2 )
{
V_2 -> V_12 = 0x0 ;
V_2 -> V_14 = ~ 0x0 ;
V_2 -> V_17 = 0x1 ;
F_65 ( V_2 -> V_45 . V_51 , 0 , V_2 -> V_49 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_43 . V_77 = F_67 ( V_2 -> V_25 ) ;
V_2 -> V_43 . V_84 = 1 ;
V_2 -> V_43 . V_85 = 1 ;
V_2 -> V_43 . V_86 = true ;
V_2 -> V_43 . V_87 = V_2 -> V_49 ;
V_2 -> V_43 . V_88 = V_47 ;
V_2 -> V_43 . V_53 = F_40 ;
V_2 -> V_43 . V_89 = F_35 ;
V_2 -> V_43 . V_90 = F_30 ;
V_2 -> V_43 . V_91 = F_33 ;
V_2 -> V_43 . V_92 = F_37 ;
}
static int F_68 ( struct V_93 * V_94 , const struct V_95 * V_96 )
{
int V_71 ;
void T_7 * V_3 ;
unsigned long * V_51 ;
struct V_66 * V_25 = & V_94 -> V_25 ;
struct V_97 * V_98 = NULL ;
struct V_1 * V_2 ;
struct V_75 * V_76 = & V_94 -> V_76 ;
struct V_75 V_99 ;
T_6 V_100 , V_101 ;
struct V_102 V_103 = { 0 } ;
struct V_72 * V_73 = V_94 -> V_25 . V_104 ;
if ( V_73 ) {
V_98 = F_69 ( V_25 , V_73 ) ;
if ( F_70 ( V_98 ) )
return F_71 ( V_98 ) ;
V_94 -> V_25 . V_105 = V_98 ;
}
V_2 = F_72 ( V_25 , sizeof( * V_2 ) , V_106 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_25 = & V_94 -> V_25 ;
V_2 -> V_108 = F_73 ( & V_94 -> V_25 , L_5 ) ;
if ( ! F_70 ( V_2 -> V_108 ) ) {
V_71 = F_74 ( V_2 -> V_108 ) ;
if ( V_71 )
return V_71 ;
}
F_75 ( V_25 , V_2 ) ;
V_3 = F_76 ( V_25 , V_76 ) ;
if ( F_70 ( V_3 ) )
return F_71 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_71 = F_57 ( V_73 , L_6 , & V_99 ) ;
if ( V_71 )
return V_71 ;
V_2 -> V_45 . V_46 = V_99 . V_109 ;
V_3 = F_76 ( V_25 , & V_99 ) ;
if ( F_70 ( V_3 ) )
return F_71 ( V_3 ) ;
V_2 -> V_45 . V_3 = V_3 ;
V_2 -> V_34 = F_60 ( V_2 ) ;
if ( V_110 ) {
V_2 -> V_49 = V_110 ;
V_100 = F_77 ( ( V_111 ) ( V_110 *
V_47 ) , F_78 ( V_76 ) ) ;
} else {
V_2 -> V_49 = F_63 ( V_2 ) ;
V_100 = F_77 ( ( V_111 ) ( V_2 -> V_49 *
V_47 ) , F_78 ( V_76 ) ) ;
}
V_101 = F_79 ( V_2 -> V_49 ) * sizeof( long ) ;
V_51 = F_72 ( V_25 , V_101 , V_106 ) ;
if ( ! V_51 )
return - V_107 ;
V_2 -> V_45 . V_51 = V_51 ;
F_80 ( & V_2 -> V_31 ) ;
F_64 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( F_81 ( V_25 , & V_2 -> V_43 , V_112 ) ) {
F_13 ( V_25 ,
L_7 ) ;
return - V_113 ;
}
V_103 . type = V_114 ;
V_103 . V_115 . V_116 = V_117 ;
V_103 . V_118 = & V_119 ;
V_103 . V_98 = V_98 ;
V_103 . V_25 = V_25 ;
V_103 . V_120 = V_121 ;
V_2 -> V_20 = F_82 ( & V_103 ) ;
if ( F_70 ( V_2 -> V_20 ) ) {
V_71 = F_71 ( V_2 -> V_20 ) ;
goto V_122;
}
F_21 ( & V_94 -> V_25 ) ;
F_13 ( V_25 , L_8 , ( char * ) V_96 -> V_35 ) ;
return 0 ;
V_122:
F_83 ( & V_2 -> V_43 ) ;
return V_71 ;
}
static int F_84 ( struct V_66 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
if ( V_2 && ! F_70 ( V_2 -> V_108 ) )
F_85 ( V_2 -> V_108 ) ;
return 0 ;
}
static int F_86 ( struct V_66 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
if ( V_2 && ! F_70 ( V_2 -> V_108 ) )
F_74 ( V_2 -> V_108 ) ;
return 0 ;
}
