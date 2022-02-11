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
else
F_3 ( 0x55 , F_16 ( V_25 ) ) ;
F_17 ( V_26 , & V_24 ) ;
}
static int F_18 ( void )
{
int V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
F_6 ( V_28 ) ;
if ( F_15 ( V_23 , & V_24 ) )
F_9 ( V_29 , V_30 ) ;
else
F_9 ( V_31 , V_30 ) ;
F_12 () ;
F_4 () ;
return 0 ;
}
static int F_19 ( void )
{
int V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
F_6 ( V_28 ) ;
F_9 ( 0x00 , V_30 ) ;
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
return - V_32 ;
if ( V_22 > V_14 )
V_12 = F_13 ( V_22 ) ;
else
V_12 = V_22 ;
if ( F_15 ( V_33 , & V_24 ) ) {
int V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
F_6 ( V_28 ) ;
F_12 () ;
F_4 () ;
}
return 0 ;
}
static int F_21 ( int * V_34 )
{
* V_34 = 0 ;
if ( V_13 ) {
int V_27 = F_1 () ;
if ( V_27 )
return V_27 ;
F_6 ( V_28 ) ;
if ( F_7 ( V_30 ) & V_35 ) {
F_9 ( 0x00 , V_30 ) ;
F_22 ( V_33 , & V_24 ) ;
* V_34 |= V_36 ;
}
F_4 () ;
}
if ( F_23 ( V_26 , & V_24 ) )
* V_34 |= V_37 ;
if ( F_15 ( V_38 , & V_24 ) )
* V_34 |= V_39 ;
return 0 ;
}
static int F_24 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
if ( V_42 && F_25 ( V_43 , & V_24 ) )
return - V_3 ;
if ( ! F_25 ( V_33 , & V_24 ) ) {
int V_27 ;
if ( V_44 && ! F_25 ( V_45 , & V_24 ) )
F_26 ( V_46 ) ;
V_27 = F_18 () ;
if ( V_27 ) {
F_22 ( V_45 , & V_24 ) ;
F_22 ( V_33 , & V_24 ) ;
F_22 ( V_43 , & V_24 ) ;
return V_27 ;
}
}
return F_27 ( V_40 , V_41 ) ;
}
static int F_28 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
if ( F_15 ( V_33 , & V_24 ) ) {
if ( F_23 ( V_38 , & V_24 ) ) {
int V_27 = F_19 () ;
if ( V_27 ) {
F_17 ( V_38 , & V_24 ) ;
F_14 () ;
return V_27 ;
}
F_22 ( V_33 , & V_24 ) ;
} else {
F_14 () ;
F_29 ( L_1 ) ;
}
}
F_22 ( V_43 , & V_24 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_41 * V_41 , const char T_2 * V_47 ,
T_3 V_48 , T_4 * V_49 )
{
if ( V_48 ) {
F_22 ( V_38 , & V_24 ) ;
F_14 () ;
}
if ( ! V_44 ) {
T_3 V_50 ;
for ( V_50 = 0 ; V_50 != V_48 ; V_50 ++ ) {
char V_51 ;
if ( F_31 ( V_51 , V_47 + V_50 ) )
return - V_52 ;
if ( V_51 == V_53 )
F_17 ( V_38 , & V_24 ) ;
}
}
return V_48 ;
}
static long F_32 ( struct V_41 * V_41 , unsigned int V_54 , unsigned long V_55 )
{
int V_56 = 0 , V_34 , V_57 , V_58 ;
union {
struct V_59 T_2 * V_60 ;
int T_2 * V_61 ;
} V_62 ;
V_62 . V_61 = ( int T_2 * ) V_55 ;
switch ( V_54 ) {
case V_63 :
return F_33 ( V_62 . V_60 ,
& V_60 , sizeof( V_60 ) ) ? - V_52 : 0 ;
case V_64 :
V_56 = F_21 ( & V_34 ) ;
if ( V_56 )
return V_56 ;
return F_34 ( V_34 , V_62 . V_61 ) ;
case V_65 :
return F_34 ( 0 , V_62 . V_61 ) ;
case V_66 :
F_14 () ;
return 0 ;
case V_67 :
if ( F_31 ( V_57 , V_62 . V_61 ) )
return - V_52 ;
switch ( V_57 ) {
case V_68 :
if ( F_15 ( V_33 , & V_24 ) ) {
V_56 = F_19 () ;
if ( V_56 )
return V_56 ;
}
F_22 ( V_33 , & V_24 ) ;
return 0 ;
case V_69 :
if ( ! F_25 ( V_33 , & V_24 ) ) {
V_56 = F_18 () ;
if ( V_56 ) {
F_22 ( V_33 , & V_24 ) ;
return V_56 ;
}
}
return 0 ;
default:
return - V_52 ;
}
case V_70 :
if ( F_31 ( V_58 , V_62 . V_61 ) )
return - V_52 ;
V_56 = F_20 ( V_58 ) ;
case V_71 :
if ( F_34 ( V_12 , V_62 . V_61 ) )
return - V_52 ;
return V_56 ;
default:
return - V_72 ;
}
}
static int F_35 ( struct V_73 * V_74 , unsigned long V_75 ,
void * V_76 )
{
if ( V_75 == V_77 || V_75 == V_78 )
F_19 () ;
return V_79 ;
}
static int T_5 F_36 ( void )
{
int V_56 = 0 ;
int V_80 = ! V_81 ;
T_6 V_82 ;
int V_83 = 0 ;
V_24 = 0 ;
V_56 = F_1 () ;
if ( V_56 )
return V_56 ;
V_16 = F_10 ( V_84 ) ;
V_82 = F_7 ( V_85 ) & 0x0f ;
F_4 () ;
switch ( V_16 ) {
case V_86 :
V_14 = 255 ;
break;
case V_87 :
V_14 = ( V_82 < 8 ) ? 255 : 65535 ;
break;
case V_88 :
case V_89 :
V_14 = 65535 ;
break;
case V_90 :
case V_91 :
case V_17 :
V_14 = 65535 ;
V_80 = 0 ;
break;
case V_92 :
F_37 ( L_2 ,
V_16 , V_82 ) ;
return - V_93 ;
case V_94 :
F_37 ( L_3 ) ;
return - V_93 ;
default:
F_37 ( L_4 ,
V_16 , V_82 ) ;
return - V_93 ;
}
V_56 = F_1 () ;
if ( V_56 )
return V_56 ;
F_6 ( V_28 ) ;
F_9 ( V_15 , V_19 ) ;
F_9 ( 0x00 , V_30 ) ;
if ( V_80 ) {
F_6 ( V_95 ) ;
V_25 = F_10 ( V_96 ) ;
if ( ! V_25 ) {
V_25 = V_97 ;
F_11 ( V_25 , V_96 ) ;
}
V_98 = F_7 ( V_99 ) ;
F_9 ( 0x01 , V_99 ) ;
if ( F_38 ( V_25 , 1 , V_2 ) )
F_17 ( V_23 , & V_24 ) ;
else
V_83 = 1 ;
}
if ( ! F_15 ( V_23 , & V_24 ) ) {
if ( ! F_38 ( V_100 , 8 , V_2 ) ) {
if ( V_83 )
F_37 ( L_5 ,
V_25 , V_100 ) ;
else
F_37 ( L_6 ,
V_100 ) ;
V_56 = - V_101 ;
goto V_102;
}
V_25 = V_100 ;
F_6 ( V_103 ) ;
F_11 ( V_25 , V_96 ) ;
F_9 ( 0x00 , V_104 ) ;
V_105 = F_7 ( V_99 ) ;
F_9 ( 0x01 , V_99 ) ;
if ( V_83 ) {
F_6 ( V_95 ) ;
F_9 ( V_98 , V_99 ) ;
}
}
if ( V_12 < 1 || V_12 > V_14 * 60 ) {
V_12 = V_106 ;
F_39 ( L_7 ,
V_106 ) ;
}
if ( V_12 > V_14 )
V_12 = F_13 ( V_12 ) ;
V_56 = F_40 ( & V_107 ) ;
if ( V_56 ) {
F_37 ( L_8 , V_56 ) ;
goto V_108;
}
V_56 = F_41 ( & V_109 ) ;
if ( V_56 ) {
F_37 ( L_9 ,
V_109 . V_110 , V_56 ) ;
goto V_111;
}
if ( ! F_15 ( V_23 , & V_24 ) ) {
F_3 ( 0x00 , F_42 ( V_25 ) ) ;
F_3 ( 0xc0 , F_43 ( V_25 ) ) ;
F_3 ( 0x5c , F_44 ( V_25 ) ) ;
F_3 ( 0x10 , F_45 ( V_25 ) ) ;
F_3 ( 0x00 , F_46 ( V_25 ) ) ;
F_3 ( 0x01 , F_47 ( V_25 ) ) ;
F_3 ( 0x09 , F_45 ( V_25 ) ) ;
}
F_48 ( L_10 ,
V_16 , V_82 , V_12 ,
V_44 , V_13 , V_42 , V_81 ) ;
F_4 () ;
return 0 ;
V_111:
F_49 ( & V_107 ) ;
V_108:
F_5 ( V_25 , F_15 ( V_23 , & V_24 ) ? 1 : 8 ) ;
if ( ! F_15 ( V_23 , & V_24 ) ) {
F_6 ( V_103 ) ;
F_9 ( V_105 , V_99 ) ;
}
V_102:
if ( V_80 ) {
F_6 ( V_95 ) ;
F_9 ( V_98 , V_99 ) ;
}
F_4 () ;
return V_56 ;
}
static void T_7 F_50 ( void )
{
if ( F_1 () == 0 ) {
F_6 ( V_28 ) ;
F_9 ( 0x00 , V_30 ) ;
F_9 ( 0x00 , V_19 ) ;
F_9 ( 0x00 , V_20 ) ;
if ( V_14 > 255 )
F_9 ( 0x00 , V_21 ) ;
if ( F_15 ( V_23 , & V_24 ) ) {
F_6 ( V_95 ) ;
F_9 ( V_98 , V_99 ) ;
} else {
F_6 ( V_103 ) ;
F_9 ( V_105 , V_99 ) ;
}
F_4 () ;
}
F_51 ( & V_109 ) ;
F_49 ( & V_107 ) ;
F_5 ( V_25 , F_15 ( V_23 , & V_24 ) ? 1 : 8 ) ;
}
