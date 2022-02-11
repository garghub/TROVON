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
static void F_18 ( struct V_19 * V_20 )
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
F_18 ( V_2 -> V_20 ) ;
}
static long F_34 ( struct V_40 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 ,
unsigned int V_44 ,
unsigned long V_45 )
{
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! ( V_2 && F_19 ( & V_2 -> V_23 ) ) )
return - V_28 ;
if ( V_42 >= V_2 -> V_46 )
return - V_28 ;
switch ( V_45 ) {
case V_47 :
F_35 ( V_42 , V_2 -> V_48 . V_49 ) ;
break;
case V_50 :
F_36 ( V_42 , V_2 -> V_48 . V_49 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static T_3 F_37 ( struct V_40 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 ,
unsigned int V_51 ,
unsigned int V_52 ,
unsigned int V_36 ,
const unsigned char * V_53 )
{
unsigned long V_54 ;
struct V_1 * V_2 = F_31 ( V_40 ,
struct V_1 , V_43 ) ;
if ( ! ( V_2 && F_19 ( & V_2 -> V_23 ) ) )
return 0 ;
if ( V_42 >= V_2 -> V_46 )
return 0 ;
V_54 = ( unsigned long ) F_38 ( V_2 , V_42 ) ;
V_52 = ( V_52 == V_55 ) ? V_56 : 0 ;
V_52 |= F_39 ( V_42 , V_2 -> V_48 . V_49 ) ?
V_57 : 0 ;
if ( V_36 > V_2 -> V_34 )
V_36 = V_2 -> V_34 ;
else
V_36 = F_40 ( V_36 ) ;
switch ( V_51 ) {
case V_58 :
V_54 |= F_41 ( V_59 , V_52 ) ;
F_25 ( ( void * ) V_54 , V_53 , 1 , V_2 -> V_34 ) ;
V_36 = 1 ;
break;
case V_60 :
V_54 |= F_41 ( V_61 , V_52 ) ;
F_25 ( ( void * ) V_54 , V_53 , V_36 ,
V_2 -> V_34 ) ;
break;
default:
return - V_62 ;
}
return V_36 ;
}
static T_3 F_42 ( struct V_63 * V_25 ,
struct V_64 * V_22 , char * V_65 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 = V_2 -> V_8 ;
return F_43 ( V_65 , V_66 , L_3 , V_24 ) ;
}
static T_3 F_44 ( struct V_63 * V_25 ,
struct V_64 * V_22 ,
const char * V_65 , T_4 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_67 = 0 ;
V_67 = F_45 ( V_65 , 16 , & V_24 ) ;
if ( V_67 )
return - V_28 ;
V_2 -> V_8 = V_24 ;
V_2 -> V_6 = V_24 ;
return V_36 ;
}
static T_3 F_46 ( struct V_63 * V_25 ,
struct V_64 * V_22 , char * V_65 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 = V_2 -> V_4 ;
return F_43 ( V_65 , V_66 , L_3 , V_24 ) ;
}
static T_3 F_47 ( struct V_63 * V_25 ,
struct V_64 * V_22 ,
const char * V_65 , T_4 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_67 = 0 ;
V_67 = F_45 ( V_65 , 16 , & V_24 ) ;
if ( V_67 )
return - V_28 ;
V_2 -> V_4 = V_24 ;
return V_36 ;
}
static T_3 F_48 ( struct V_63 * V_25 ,
struct V_64 * V_22 , char * V_65 )
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
return F_43 ( V_65 , V_66 , L_3 , V_24 ) ;
}
static T_3 F_49 ( struct V_63 * V_25 ,
struct V_64 * V_22 ,
const char * V_65 , T_4 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 , V_14 ;
int V_67 = 0 ;
V_67 = F_45 ( V_65 , 16 , & V_24 ) ;
if ( V_67 )
return V_67 ;
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
static T_3 F_50 ( struct V_63 * V_25 ,
struct V_64 * V_22 , char * V_65 )
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
return F_43 ( V_65 , V_66 , L_3 , V_24 ) ;
}
static T_3 F_51 ( struct V_63 * V_25 ,
struct V_64 * V_22 ,
const char * V_65 , T_4 V_36 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
unsigned long V_24 ;
int V_67 = 0 ;
V_67 = F_45 ( V_65 , 16 , & V_24 ) ;
if ( V_67 )
return V_67 ;
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
static T_3 F_52 ( struct V_63 * V_25 ,
struct V_64 * V_22 , char * V_65 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
V_24 = V_2 -> V_17 ;
return sprintf ( V_65 , L_3 , V_24 ) ;
}
static T_3 F_53 ( struct V_63 * V_25 ,
struct V_64 * V_22 ,
const char * V_65 , T_4 V_36 )
{
int V_67 ;
unsigned long V_24 ;
struct V_1 * V_2 = F_8 ( V_25 -> V_26 ) ;
V_67 = F_45 ( V_65 , 16 , & V_24 ) ;
if ( V_67 )
return V_67 ;
V_2 -> V_17 = V_24 & 0x7f ;
return V_36 ;
}
static int F_54 ( struct V_68 * V_69 ,
char * V_70 , struct V_71 * V_72 )
{
const char * V_73 = NULL ;
int V_74 = 0 , V_75 = 0 ;
while ( ! F_55 ( V_69 , L_4 , V_74 , & V_73 ) ) {
if ( strcmp ( V_70 , V_73 ) ) {
V_74 ++ ;
continue;
}
V_75 = 1 ;
break;
}
if ( ! V_75 )
return - V_28 ;
return F_56 ( V_69 , V_74 , V_72 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 )
{
T_1 V_76 ;
if ( ! F_58 ( F_26 ) )
return 4 ;
V_76 = F_17 ( V_2 -> V_3 + V_77 ) ;
return F_59 ( V_76 , 12 , 15 ) ? 8 : 4 ;
}
static T_1 F_60 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_17 ( V_2 -> V_3 + V_78 ) ;
V_46 &= 0x1ffff ;
if ( ! V_46 )
V_46 = V_79 ;
return V_46 ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_12 = 0x0 ;
V_2 -> V_14 = ~ 0x0 ;
V_2 -> V_17 = 0x1 ;
F_62 ( V_2 -> V_48 . V_49 , 0 , V_2 -> V_46 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
V_2 -> V_43 . V_73 = F_64 ( V_2 -> V_25 ) ;
V_2 -> V_43 . V_80 = 1 ;
V_2 -> V_43 . V_81 = 1 ;
V_2 -> V_43 . V_82 = true ;
V_2 -> V_43 . V_83 = V_2 -> V_46 ;
V_2 -> V_43 . V_51 = F_37 ;
V_2 -> V_43 . V_84 = F_30 ;
V_2 -> V_43 . V_85 = F_33 ;
V_2 -> V_43 . V_86 = F_34 ;
}
static int F_65 ( struct V_87 * V_88 , const struct V_89 * V_90 )
{
int V_67 ;
void T_5 * V_3 ;
unsigned long * V_49 ;
struct V_63 * V_25 = & V_88 -> V_25 ;
struct V_91 * V_92 = NULL ;
struct V_1 * V_2 ;
struct V_71 * V_72 = & V_88 -> V_72 ;
struct V_71 V_93 ;
T_4 V_94 , V_95 ;
struct V_96 * V_97 ;
struct V_68 * V_69 = V_88 -> V_25 . V_98 ;
if ( V_69 ) {
V_92 = F_66 ( V_25 , V_69 ) ;
if ( F_67 ( V_92 ) )
return F_68 ( V_92 ) ;
V_88 -> V_25 . V_99 = V_92 ;
}
V_2 = F_69 ( V_25 , sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_25 = & V_88 -> V_25 ;
V_2 -> V_102 = F_70 ( & V_88 -> V_25 , L_5 ) ;
if ( ! F_67 ( V_2 -> V_102 ) ) {
V_67 = F_71 ( V_2 -> V_102 ) ;
if ( V_67 )
return V_67 ;
}
F_72 ( V_25 , V_2 ) ;
V_3 = F_73 ( V_25 , V_72 ) ;
if ( F_67 ( V_3 ) )
return F_68 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_67 = F_54 ( V_69 , L_6 , & V_93 ) ;
if ( V_67 )
return V_67 ;
V_3 = F_73 ( V_25 , & V_93 ) ;
if ( F_67 ( V_3 ) )
return F_68 ( V_3 ) ;
V_2 -> V_48 . V_3 = V_3 ;
V_2 -> V_34 = F_57 ( V_2 ) ;
if ( V_103 ) {
V_2 -> V_46 = V_103 ;
V_94 = F_74 ( ( V_104 ) ( V_103 *
V_105 ) , F_75 ( V_72 ) ) ;
} else {
V_2 -> V_46 = F_60 ( V_2 ) ;
V_94 = F_74 ( ( V_104 ) ( V_2 -> V_46 *
V_105 ) , F_75 ( V_72 ) ) ;
}
V_95 = F_76 ( V_2 -> V_46 ) * sizeof( long ) ;
V_49 = F_69 ( V_25 , V_95 , V_100 ) ;
if ( ! V_49 )
return - V_101 ;
V_2 -> V_48 . V_49 = V_49 ;
F_77 ( & V_2 -> V_31 ) ;
F_61 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( F_78 ( V_25 , & V_2 -> V_43 , V_106 ) ) {
F_13 ( V_25 ,
L_7 ) ;
return - V_107 ;
}
V_97 = F_69 ( V_25 , sizeof( * V_97 ) , V_100 ) ;
if ( ! V_97 ) {
V_67 = - V_101 ;
goto V_108;
}
V_97 -> type = V_109 ;
V_97 -> V_110 . V_111 = V_112 ;
V_97 -> V_113 = & V_114 ;
V_97 -> V_92 = V_92 ;
V_97 -> V_25 = V_25 ;
V_97 -> V_115 = V_116 ;
V_2 -> V_20 = F_79 ( V_97 ) ;
if ( F_67 ( V_2 -> V_20 ) ) {
V_67 = F_68 ( V_2 -> V_20 ) ;
goto V_108;
}
F_21 ( & V_88 -> V_25 ) ;
F_13 ( V_25 , L_8 , ( char * ) V_90 -> V_35 ) ;
return 0 ;
V_108:
F_80 ( & V_2 -> V_43 ) ;
return V_67 ;
}
static int F_81 ( struct V_63 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
if ( V_2 && ! F_67 ( V_2 -> V_102 ) )
F_82 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_83 ( struct V_63 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
if ( V_2 && ! F_67 ( V_2 -> V_102 ) )
F_71 ( V_2 -> V_102 ) ;
return 0 ;
}
