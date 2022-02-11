static inline unsigned char
F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = ( V_2 -> V_3 << 1 ) ;
if ( V_2 -> V_4 & V_5 )
V_3 |= 1 ;
return V_3 ;
}
static void
F_2 ( struct V_6 * V_7 )
{
F_3 ( V_8 , V_7 -> V_9 + V_10 ) ;
F_3 ( V_11 , V_7 -> V_9 + V_12 ) ;
F_3 ( 0 , V_7 -> V_9 + V_10 ) ;
}
static void
F_4 ( struct V_6 * V_7 )
{
T_1 V_13 = V_14 | V_15 | V_16 ;
#if F_5 ( V_17 ) || F_5 ( V_18 )
if ( V_7 -> V_19 == 0 ) {
F_6 ( 7 , 0 ) ;
F_6 ( 6 , 0 ) ;
} else {
F_6 ( 5 , 0 ) ;
F_6 ( 4 , 0 ) ;
}
#endif
V_7 -> V_20 =
V_21 | V_22 |
V_23 | V_24 ;
V_13 |= V_25 | V_26 |
V_27 | V_28 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
}
static void
F_7 ( struct V_6 * V_7 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
V_13 &= ~ ( V_29 | V_30 |
V_31 | V_15 ) ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
}
static T_2
F_9 ( int V_32 , void * V_33 )
{
struct V_6 * V_7 = V_33 ;
T_1 V_34 = F_8 ( V_7 -> V_9 + V_12 ) ;
if ( ( V_34 &= V_7 -> V_20 ) ) {
F_3 ( V_34 , V_7 -> V_9 + V_12 ) ;
V_7 -> V_35 |= V_34 ;
F_10 ( & V_7 -> V_36 ) ;
}
return V_37 ;
}
static int
F_11 ( T_1 V_34 )
{
int V_38 = 0 ;
if ( ( V_34 & V_22 ) ) {
if ( ! V_38 ) V_38 = - V_39 ;
}
if ( ( V_34 & V_21 ) ) {
if ( ! V_38 ) V_38 = - V_40 ;
}
return V_38 ;
}
static inline T_1
F_12 ( struct V_6 * V_7 )
{
unsigned long V_4 ;
T_1 V_34 ;
F_13 ( & V_7 -> V_41 , V_4 ) ;
V_34 = V_7 -> V_35 ;
V_7 -> V_35 = 0 ;
F_14 ( & V_7 -> V_41 , V_4 ) ;
return V_34 ;
}
static int
F_15 ( struct V_6 * V_7 ,
unsigned V_4 , unsigned * V_42 ,
T_3 V_43 )
{
unsigned V_34 = 0 ;
int V_44 ;
int V_45 ;
int V_38 = 0 ;
do {
V_44 = F_16 (
iop3xx_adap->waitq,
(done = compare( sr = iop3xx_i2c_get_srstat(iop3xx_adap) ,flags )),
1 * HZ;
) ;
if ( ( V_38 = F_11 ( V_34 ) ) < 0 ) {
* V_42 = V_34 ;
return V_38 ;
} else if ( ! V_44 ) {
* V_42 = V_34 ;
return - V_46 ;
}
} while( ! V_45 );
* V_42 = V_34 ;
return 0 ;
}
static int
F_17 ( unsigned V_47 , unsigned V_48 )
{
return ( V_47 & V_48 ) == 0 ;
}
static int
F_18 ( unsigned V_47 , unsigned V_48 )
{
return ( V_47 & V_48 ) != 0 ;
}
static int
F_19 ( struct V_6 * V_7 , int * V_42 )
{
return F_15 (
V_7 ,
V_24 | V_21 | V_22 ,
V_42 , F_18 ) ;
}
static int
F_20 ( struct V_6 * V_7 , int * V_42 )
{
return F_15 (
V_7 ,
V_23 | V_21 | V_22 ,
V_42 , F_18 ) ;
}
static int
F_21 ( struct V_6 * V_7 , int * V_42 )
{
return F_15 (
V_7 , V_49 , V_42 , F_17 ) ;
}
static int
F_22 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 ;
if ( V_2 -> V_3 == V_50 ) {
return - V_51 ;
}
F_3 ( F_1 ( V_2 ) , V_7 -> V_9 + V_52 ) ;
V_13 &= ~ ( V_31 | V_53 ) ;
V_13 |= V_29 | V_30 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
V_38 = F_19 ( V_7 , & V_42 ) ;
return V_38 ;
}
static int
F_23 ( struct V_6 * V_7 , char V_54 ,
int V_55 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 = 0 ;
F_3 ( V_54 , V_7 -> V_9 + V_52 ) ;
V_13 &= ~ V_29 ;
if ( V_55 ) {
V_13 |= V_31 ;
} else {
V_13 &= ~ V_31 ;
}
V_13 |= V_30 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
V_38 = F_19 ( V_7 , & V_42 ) ;
return V_38 ;
}
static int
F_24 ( struct V_6 * V_7 , char * V_54 ,
int V_55 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 = 0 ;
V_13 &= ~ V_29 ;
if ( V_55 ) {
V_13 |= V_31 | V_53 ;
} else {
V_13 &= ~ ( V_31 | V_53 ) ;
}
V_13 |= V_30 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
V_38 = F_20 ( V_7 , & V_42 ) ;
* V_54 = F_8 ( V_7 -> V_9 + V_52 ) ;
return V_38 ;
}
static int
F_25 ( struct V_56 * V_57 , const char * V_58 , int V_59 )
{
struct V_6 * V_7 = V_57 -> V_60 ;
int V_61 ;
int V_38 = 0 ;
for ( V_61 = 0 ; V_38 == 0 && V_61 != V_59 ; ++ V_61 )
V_38 = F_23 ( V_7 , V_58 [ V_61 ] , V_61 == V_59 - 1 ) ;
return V_38 ;
}
static int
F_26 ( struct V_56 * V_57 , char * V_58 , int V_59 )
{
struct V_6 * V_7 = V_57 -> V_60 ;
int V_61 ;
int V_38 = 0 ;
for ( V_61 = 0 ; V_38 == 0 && V_61 != V_59 ; ++ V_61 )
V_38 = F_24 ( V_7 , & V_58 [ V_61 ] , V_61 == V_59 - 1 ) ;
return V_38 ;
}
static int
F_27 ( struct V_56 * V_57 , struct V_1 * V_62 )
{
struct V_6 * V_7 = V_57 -> V_60 ;
int V_38 ;
V_38 = F_22 ( V_7 , V_62 ) ;
if ( V_38 < 0 ) {
return V_38 ;
}
if ( ( V_62 -> V_4 & V_5 ) ) {
return F_26 ( V_57 , V_62 -> V_58 , V_62 -> V_63 ) ;
} else {
return F_25 ( V_57 , V_62 -> V_58 , V_62 -> V_63 ) ;
}
}
static int
F_28 ( struct V_56 * V_57 , struct V_1 * V_64 ,
int V_65 )
{
struct V_6 * V_7 = V_57 -> V_60 ;
int V_66 = 0 ;
int V_67 = 0 ;
int V_42 ;
F_21 ( V_7 , & V_42 ) ;
F_2 ( V_7 ) ;
F_4 ( V_7 ) ;
for ( V_66 = 0 ; V_67 == 0 && V_66 != V_65 ; V_66 ++ ) {
V_67 = F_27 ( V_57 , & V_64 [ V_66 ] ) ;
}
F_7 ( V_7 ) ;
if( V_67 )
return V_67 ;
return V_66 ;
}
static T_1
F_29 ( struct V_56 * V_68 )
{
return V_69 | V_70 ;
}
static int
F_30 ( struct V_71 * V_72 )
{
struct V_56 * V_73 = F_31 ( V_72 ) ;
struct V_6 * V_74 =
(struct V_6 * ) V_73 -> V_60 ;
struct V_75 * V_76 = F_32 ( V_72 , V_77 , 0 ) ;
unsigned long V_13 = F_8 ( V_74 -> V_9 + V_10 ) ;
V_13 &= ~ ( V_25 | V_26 |
V_27 | V_28 ) ;
F_3 ( V_13 , V_74 -> V_9 + V_10 ) ;
F_33 ( V_74 -> V_9 ) ;
F_34 ( V_76 -> V_78 , V_79 ) ;
F_35 ( V_74 ) ;
F_35 ( V_73 ) ;
return 0 ;
}
static int
F_36 ( struct V_71 * V_72 )
{
struct V_75 * V_76 ;
int V_67 , V_80 ;
struct V_56 * V_81 ;
struct V_6 * V_74 ;
V_81 = F_37 ( sizeof( struct V_56 ) , V_82 ) ;
if ( ! V_81 ) {
V_67 = - V_83 ;
goto V_84;
}
V_74 = F_37 ( sizeof( struct V_6 ) , V_82 ) ;
if ( ! V_74 ) {
V_67 = - V_83 ;
goto V_85;
}
V_76 = F_32 ( V_72 , V_77 , 0 ) ;
if ( ! V_76 ) {
V_67 = - V_86 ;
goto V_87;
}
if ( ! F_38 ( V_76 -> V_78 , V_79 , V_72 -> V_88 ) ) {
V_67 = - V_51 ;
goto V_87;
}
V_74 -> V_19 = V_89 ++ ;
V_74 -> V_9 = F_39 ( V_76 -> V_78 , V_79 ) ;
if ( ! V_74 -> V_9 ) {
V_67 = - V_83 ;
goto V_90;
}
V_80 = F_40 ( V_72 , 0 ) ;
if ( V_80 < 0 ) {
V_67 = - V_91 ;
goto V_92;
}
V_67 = F_41 ( V_80 , F_9 , 0 ,
V_72 -> V_88 , V_74 ) ;
if ( V_67 ) {
V_67 = - V_93 ;
goto V_92;
}
memcpy ( V_81 -> V_88 , V_72 -> V_88 , strlen ( V_72 -> V_88 ) ) ;
V_81 -> V_94 = V_95 ;
V_81 -> V_96 = V_97 | V_98 ;
V_81 -> V_99 . V_100 = & V_72 -> V_99 ;
V_81 -> V_101 = V_72 -> V_19 ;
V_81 -> V_102 = V_103 ;
V_81 -> V_104 = & V_105 ;
F_42 ( & V_74 -> V_36 ) ;
F_43 ( & V_74 -> V_41 ) ;
F_2 ( V_74 ) ;
F_4 ( V_74 ) ;
F_44 ( V_72 , V_81 ) ;
V_81 -> V_60 = V_74 ;
F_45 ( V_81 ) ;
return 0 ;
V_92:
F_33 ( V_74 -> V_9 ) ;
V_90:
F_34 ( V_76 -> V_78 , V_79 ) ;
V_87:
F_35 ( V_74 ) ;
V_85:
F_35 ( V_81 ) ;
V_84:
return V_67 ;
}
