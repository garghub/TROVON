static inline int F_1 ( void )
{
if ( ! F_2 ( V_1 , 2 , V_2 ) )
return - V_3 ;
F_3 ( 0x87 , V_1 ) ;
F_3 ( 0x01 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
return 0 ;
}
static inline void F_4 ( void )
{
F_3 ( 0x02 , V_1 ) ;
F_3 ( 0x02 , V_4 ) ;
F_5 ( V_1 , 2 ) ;
}
static inline void F_6 ( int V_5 )
{
F_3 ( V_6 , V_1 ) ;
F_3 ( V_5 , V_4 ) ;
}
static inline int F_7 ( int V_7 )
{
F_3 ( V_7 , V_1 ) ;
return F_8 ( V_4 ) ;
}
static inline void F_9 ( int V_8 , int V_7 )
{
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static inline int F_10 ( int V_7 )
{
int V_8 ;
F_3 ( V_7 ++ , V_1 ) ;
V_8 = F_8 ( V_4 ) << 8 ;
F_3 ( V_7 , V_1 ) ;
V_8 |= F_8 ( V_4 ) ;
return V_8 ;
}
static inline void F_11 ( int V_8 , int V_7 )
{
F_3 ( V_7 ++ , V_1 ) ;
F_3 ( V_8 >> 8 , V_4 ) ;
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static void F_12 ( void )
{
unsigned char V_9 = V_10 ;
int V_11 = V_12 ;
if ( V_13 )
V_9 = 0 ;
if ( V_11 <= V_14 )
V_9 |= V_15 ;
else
V_11 /= 60 ;
if ( V_16 != V_17 )
V_9 |= V_18 ;
F_9 ( V_9 , V_19 ) ;
F_9 ( V_11 , V_20 ) ;
if ( V_14 > 255 )
F_9 ( V_11 >> 8 , V_21 ) ;
}
static int F_13 ( int V_22 )
{
V_22 += 59 ;
V_22 -= V_22 % 60 ;
return V_22 ;
}
static void F_14 ( void )
{
if ( F_15 ( V_23 , & V_24 ) )
F_8 ( V_25 ) ;
else if ( F_15 ( V_26 , & V_24 ) )
F_3 ( 0x55 , F_16 ( V_25 ) ) ;
else {
if ( F_1 () )
return;
F_6 ( V_27 ) ;
F_12 () ;
F_4 () ;
}
F_17 ( V_28 , & V_24 ) ;
}
static int F_18 ( void )
{
int V_29 = F_1 () ;
if ( V_29 )
return V_29 ;
F_6 ( V_27 ) ;
if ( F_15 ( V_23 , & V_24 ) )
F_9 ( V_30 , V_31 ) ;
else if ( F_15 ( V_26 , & V_24 ) )
F_9 ( V_32 , V_31 ) ;
F_12 () ;
F_4 () ;
return 0 ;
}
static int F_19 ( void )
{
int V_29 = F_1 () ;
if ( V_29 )
return V_29 ;
F_6 ( V_27 ) ;
F_9 ( 0x00 , V_31 ) ;
F_9 ( V_15 , V_19 ) ;
F_9 ( 0x00 , V_20 ) ;
if ( V_14 > 255 )
F_9 ( 0x00 , V_21 ) ;
F_4 () ;
return 0 ;
}
static int F_20 ( int V_22 )
{
if ( V_22 < 1 || V_22 > V_14 * 60 )
return - V_33 ;
if ( V_22 > V_14 )
V_12 = F_13 ( V_22 ) ;
else
V_12 = V_22 ;
if ( F_15 ( V_34 , & V_24 ) ) {
int V_29 = F_1 () ;
if ( V_29 )
return V_29 ;
F_6 ( V_27 ) ;
F_12 () ;
F_4 () ;
}
return 0 ;
}
static int F_21 ( int * V_35 )
{
* V_35 = 0 ;
if ( V_13 ) {
int V_29 = F_1 () ;
if ( V_29 )
return V_29 ;
F_6 ( V_27 ) ;
if ( F_7 ( V_31 ) & V_36 ) {
F_9 ( 0x00 , V_31 ) ;
F_22 ( V_34 , & V_24 ) ;
* V_35 |= V_37 ;
}
F_4 () ;
}
if ( F_23 ( V_28 , & V_24 ) )
* V_35 |= V_38 ;
if ( F_15 ( V_39 , & V_24 ) )
* V_35 |= V_40 ;
return 0 ;
}
static int F_24 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
if ( V_43 && F_25 ( V_44 , & V_24 ) )
return - V_3 ;
if ( ! F_25 ( V_34 , & V_24 ) ) {
int V_29 ;
if ( V_45 && ! F_25 ( V_46 , & V_24 ) )
F_26 ( V_47 ) ;
V_29 = F_18 () ;
if ( V_29 ) {
F_22 ( V_46 , & V_24 ) ;
F_22 ( V_34 , & V_24 ) ;
F_22 ( V_44 , & V_24 ) ;
return V_29 ;
}
}
return F_27 ( V_41 , V_42 ) ;
}
static int F_28 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
if ( F_15 ( V_34 , & V_24 ) ) {
if ( F_23 ( V_39 , & V_24 ) ) {
int V_29 = F_19 () ;
if ( V_29 ) {
F_17 ( V_39 , & V_24 ) ;
F_14 () ;
return V_29 ;
}
F_22 ( V_34 , & V_24 ) ;
} else {
F_14 () ;
F_29 ( L_1 ) ;
}
}
F_22 ( V_44 , & V_24 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_42 * V_42 , const char T_2 * V_48 ,
T_3 V_49 , T_4 * V_50 )
{
if ( V_49 ) {
F_22 ( V_39 , & V_24 ) ;
F_14 () ;
}
if ( ! V_45 ) {
T_3 V_51 ;
for ( V_51 = 0 ; V_51 != V_49 ; V_51 ++ ) {
char V_52 ;
if ( F_31 ( V_52 , V_48 + V_51 ) )
return - V_53 ;
if ( V_52 == V_54 )
F_17 ( V_39 , & V_24 ) ;
}
}
return V_49 ;
}
static long F_32 ( struct V_42 * V_42 , unsigned int V_55 , unsigned long V_56 )
{
int V_57 = 0 , V_35 , V_58 , V_59 ;
union {
struct V_60 T_2 * V_61 ;
int T_2 * V_62 ;
} V_63 ;
V_63 . V_62 = ( int T_2 * ) V_56 ;
switch ( V_55 ) {
case V_64 :
return F_33 ( V_63 . V_61 ,
& V_61 , sizeof( V_61 ) ) ? - V_53 : 0 ;
case V_65 :
V_57 = F_21 ( & V_35 ) ;
if ( V_57 )
return V_57 ;
return F_34 ( V_35 , V_63 . V_62 ) ;
case V_66 :
return F_34 ( 0 , V_63 . V_62 ) ;
case V_67 :
F_14 () ;
return 0 ;
case V_68 :
if ( F_31 ( V_58 , V_63 . V_62 ) )
return - V_53 ;
switch ( V_58 ) {
case V_69 :
if ( F_15 ( V_34 , & V_24 ) ) {
V_57 = F_19 () ;
if ( V_57 )
return V_57 ;
}
F_22 ( V_34 , & V_24 ) ;
return 0 ;
case V_70 :
if ( ! F_25 ( V_34 , & V_24 ) ) {
V_57 = F_18 () ;
if ( V_57 ) {
F_22 ( V_34 , & V_24 ) ;
return V_57 ;
}
}
return 0 ;
default:
return - V_53 ;
}
case V_71 :
if ( F_31 ( V_59 , V_63 . V_62 ) )
return - V_53 ;
V_57 = F_20 ( V_59 ) ;
case V_72 :
if ( F_34 ( V_12 , V_63 . V_62 ) )
return - V_53 ;
return V_57 ;
default:
return - V_73 ;
}
}
static int F_35 ( struct V_74 * V_75 , unsigned long V_76 ,
void * V_77 )
{
if ( V_76 == V_78 || V_76 == V_79 )
F_19 () ;
return V_80 ;
}
static int T_5 F_36 ( void )
{
int V_57 = 0 ;
int V_81 = ! V_82 ;
T_6 V_83 ;
int V_84 = 0 ;
V_24 = 0 ;
V_57 = F_1 () ;
if ( V_57 )
return V_57 ;
V_16 = F_10 ( V_85 ) ;
V_83 = F_7 ( V_86 ) & 0x0f ;
F_4 () ;
switch ( V_16 ) {
case V_87 :
V_14 = 255 ;
break;
case V_88 :
V_14 = ( V_83 < 8 ) ? 255 : 65535 ;
break;
case V_89 :
case V_90 :
V_14 = 65535 ;
break;
case V_91 :
case V_92 :
case V_17 :
case V_93 :
V_14 = 65535 ;
V_81 = 0 ;
break;
case V_94 :
F_37 ( L_2 ,
V_16 , V_83 ) ;
return - V_95 ;
case V_96 :
F_37 ( L_3 ) ;
return - V_95 ;
default:
F_37 ( L_4 ,
V_16 , V_83 ) ;
return - V_95 ;
}
V_57 = F_1 () ;
if ( V_57 )
return V_57 ;
F_6 ( V_27 ) ;
F_9 ( V_15 , V_19 ) ;
F_9 ( 0x00 , V_31 ) ;
if ( V_81 ) {
F_6 ( V_97 ) ;
V_25 = F_10 ( V_98 ) ;
if ( ! V_25 ) {
V_25 = V_99 ;
F_11 ( V_25 , V_98 ) ;
}
V_100 = F_7 ( V_101 ) ;
F_9 ( 0x01 , V_101 ) ;
if ( F_38 ( V_25 , 1 , V_2 ) )
F_17 ( V_23 , & V_24 ) ;
else
V_84 = 1 ;
}
if ( ! V_102 && ! F_15 ( V_23 , & V_24 ) ) {
if ( ! F_38 ( V_103 , 8 , V_2 ) ) {
if ( V_84 )
F_37 ( L_5 ,
V_25 , V_103 ) ;
else
F_37 ( L_6 ,
V_103 ) ;
V_57 = - V_104 ;
goto V_105;
}
V_25 = V_103 ;
F_6 ( V_106 ) ;
F_11 ( V_25 , V_98 ) ;
F_9 ( 0x00 , V_107 ) ;
V_108 = F_7 ( V_101 ) ;
F_9 ( 0x01 , V_101 ) ;
if ( V_84 ) {
F_6 ( V_97 ) ;
F_9 ( V_100 , V_101 ) ;
}
F_17 ( V_26 , & V_24 ) ;
}
if ( V_12 < 1 || V_12 > V_14 * 60 ) {
V_12 = V_109 ;
F_39 ( L_7 ,
V_109 ) ;
}
if ( V_12 > V_14 )
V_12 = F_13 ( V_12 ) ;
V_57 = F_40 ( & V_110 ) ;
if ( V_57 ) {
F_37 ( L_8 , V_57 ) ;
goto V_111;
}
V_57 = F_41 ( & V_112 ) ;
if ( V_57 ) {
F_37 ( L_9 ,
V_112 . V_113 , V_57 ) ;
goto V_114;
}
if ( F_15 ( V_26 , & V_24 ) ) {
F_3 ( 0x00 , F_42 ( V_25 ) ) ;
F_3 ( 0xc0 , F_43 ( V_25 ) ) ;
F_3 ( 0x5c , F_44 ( V_25 ) ) ;
F_3 ( 0x10 , F_45 ( V_25 ) ) ;
F_3 ( 0x00 , F_46 ( V_25 ) ) ;
F_3 ( 0x01 , F_47 ( V_25 ) ) ;
F_3 ( 0x09 , F_45 ( V_25 ) ) ;
}
F_48 ( L_10 ,
V_16 , V_83 , V_12 ,
V_45 , V_13 , V_43 , V_82 , V_102 ) ;
F_4 () ;
return 0 ;
V_114:
F_49 ( & V_110 ) ;
V_111:
if ( F_15 ( V_23 , & V_24 ) )
F_5 ( V_25 , 1 ) ;
else if ( F_15 ( V_26 , & V_24 ) ) {
F_5 ( V_25 , 8 ) ;
F_6 ( V_106 ) ;
F_9 ( V_108 , V_101 ) ;
}
V_105:
if ( V_81 ) {
F_6 ( V_97 ) ;
F_9 ( V_100 , V_101 ) ;
}
F_4 () ;
return V_57 ;
}
static void T_7 F_50 ( void )
{
if ( F_1 () == 0 ) {
F_6 ( V_27 ) ;
F_9 ( 0x00 , V_31 ) ;
F_9 ( 0x00 , V_19 ) ;
F_9 ( 0x00 , V_20 ) ;
if ( V_14 > 255 )
F_9 ( 0x00 , V_21 ) ;
if ( F_15 ( V_23 , & V_24 ) ) {
F_6 ( V_97 ) ;
F_9 ( V_100 , V_101 ) ;
} else if ( F_15 ( V_26 , & V_24 ) ) {
F_6 ( V_106 ) ;
F_9 ( V_108 , V_101 ) ;
}
F_4 () ;
}
F_51 ( & V_112 ) ;
F_49 ( & V_110 ) ;
if ( F_15 ( V_23 , & V_24 ) )
F_5 ( V_25 , 1 ) ;
else if ( F_15 ( V_26 , & V_24 ) )
F_5 ( V_25 , 8 ) ;
}
