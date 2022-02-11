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
V_7 -> V_36 ,
( V_45 = V_43 ( V_34 = F_12 ( V_7 ) , V_4 ) ) ,
1 * V_46
) ;
if ( ( V_38 = F_11 ( V_34 ) ) < 0 ) {
* V_42 = V_34 ;
return V_38 ;
} else if ( ! V_44 ) {
* V_42 = V_34 ;
return - V_47 ;
}
} while( ! V_45 );
* V_42 = V_34 ;
return 0 ;
}
static int
F_17 ( unsigned V_48 , unsigned V_49 )
{
return ( V_48 & V_49 ) == 0 ;
}
static int
F_18 ( unsigned V_48 , unsigned V_49 )
{
return ( V_48 & V_49 ) != 0 ;
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
V_7 , V_50 , V_42 , F_17 ) ;
}
static int
F_22 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 ;
if ( V_2 -> V_3 == V_51 ) {
return - V_52 ;
}
F_3 ( F_1 ( V_2 ) , V_7 -> V_9 + V_53 ) ;
V_13 &= ~ ( V_31 | V_54 ) ;
V_13 |= V_29 | V_30 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
V_38 = F_19 ( V_7 , & V_42 ) ;
return V_38 ;
}
static int
F_23 ( struct V_6 * V_7 , char V_55 ,
int V_56 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 = 0 ;
F_3 ( V_55 , V_7 -> V_9 + V_53 ) ;
V_13 &= ~ V_29 ;
if ( V_56 ) {
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
F_24 ( struct V_6 * V_7 , char * V_55 ,
int V_56 )
{
unsigned long V_13 = F_8 ( V_7 -> V_9 + V_10 ) ;
int V_42 ;
int V_38 = 0 ;
V_13 &= ~ V_29 ;
if ( V_56 ) {
V_13 |= V_31 | V_54 ;
} else {
V_13 &= ~ ( V_31 | V_54 ) ;
}
V_13 |= V_30 ;
F_3 ( V_13 , V_7 -> V_9 + V_10 ) ;
V_38 = F_20 ( V_7 , & V_42 ) ;
* V_55 = F_8 ( V_7 -> V_9 + V_53 ) ;
return V_38 ;
}
static int
F_25 ( struct V_57 * V_58 , const char * V_59 , int V_60 )
{
struct V_6 * V_7 = V_58 -> V_61 ;
int V_62 ;
int V_38 = 0 ;
for ( V_62 = 0 ; V_38 == 0 && V_62 != V_60 ; ++ V_62 )
V_38 = F_23 ( V_7 , V_59 [ V_62 ] , V_62 == V_60 - 1 ) ;
return V_38 ;
}
static int
F_26 ( struct V_57 * V_58 , char * V_59 , int V_60 )
{
struct V_6 * V_7 = V_58 -> V_61 ;
int V_62 ;
int V_38 = 0 ;
for ( V_62 = 0 ; V_38 == 0 && V_62 != V_60 ; ++ V_62 )
V_38 = F_24 ( V_7 , & V_59 [ V_62 ] , V_62 == V_60 - 1 ) ;
return V_38 ;
}
static int
F_27 ( struct V_57 * V_58 , struct V_1 * V_63 )
{
struct V_6 * V_7 = V_58 -> V_61 ;
int V_38 ;
V_38 = F_22 ( V_7 , V_63 ) ;
if ( V_38 < 0 ) {
return V_38 ;
}
if ( ( V_63 -> V_4 & V_5 ) ) {
return F_26 ( V_58 , V_63 -> V_59 , V_63 -> V_64 ) ;
} else {
return F_25 ( V_58 , V_63 -> V_59 , V_63 -> V_64 ) ;
}
}
static int
F_28 ( struct V_57 * V_58 , struct V_1 * V_65 ,
int V_66 )
{
struct V_6 * V_7 = V_58 -> V_61 ;
int V_67 = 0 ;
int V_68 = 0 ;
int V_42 ;
F_21 ( V_7 , & V_42 ) ;
F_2 ( V_7 ) ;
F_4 ( V_7 ) ;
for ( V_67 = 0 ; V_68 == 0 && V_67 != V_66 ; V_67 ++ ) {
V_68 = F_27 ( V_58 , & V_65 [ V_67 ] ) ;
}
F_7 ( V_7 ) ;
if( V_68 )
return V_68 ;
return V_67 ;
}
static T_1
F_29 ( struct V_57 * V_69 )
{
return V_70 | V_71 ;
}
static int
F_30 ( struct V_72 * V_73 )
{
struct V_57 * V_74 = F_31 ( V_73 ) ;
struct V_6 * V_75 =
(struct V_6 * ) V_74 -> V_61 ;
struct V_76 * V_77 = F_32 ( V_73 , V_78 , 0 ) ;
unsigned long V_13 = F_8 ( V_75 -> V_9 + V_10 ) ;
V_13 &= ~ ( V_25 | V_26 |
V_27 | V_28 ) ;
F_3 ( V_13 , V_75 -> V_9 + V_10 ) ;
F_33 ( V_75 -> V_9 ) ;
F_34 ( V_77 -> V_79 , V_80 ) ;
F_35 ( V_75 ) ;
F_35 ( V_74 ) ;
return 0 ;
}
static int
F_36 ( struct V_72 * V_73 )
{
struct V_76 * V_77 ;
int V_68 , V_81 ;
struct V_57 * V_82 ;
struct V_6 * V_75 ;
V_82 = F_37 ( sizeof( struct V_57 ) , V_83 ) ;
if ( ! V_82 ) {
V_68 = - V_84 ;
goto V_85;
}
V_75 = F_37 ( sizeof( struct V_6 ) , V_83 ) ;
if ( ! V_75 ) {
V_68 = - V_84 ;
goto V_86;
}
V_77 = F_32 ( V_73 , V_78 , 0 ) ;
if ( ! V_77 ) {
V_68 = - V_87 ;
goto V_88;
}
if ( ! F_38 ( V_77 -> V_79 , V_80 , V_73 -> V_89 ) ) {
V_68 = - V_52 ;
goto V_88;
}
V_75 -> V_19 = V_90 ++ ;
V_75 -> V_9 = F_39 ( V_77 -> V_79 , V_80 ) ;
if ( ! V_75 -> V_9 ) {
V_68 = - V_84 ;
goto V_91;
}
V_81 = F_40 ( V_73 , 0 ) ;
if ( V_81 < 0 ) {
V_68 = - V_92 ;
goto V_93;
}
V_68 = F_41 ( V_81 , F_9 , 0 ,
V_73 -> V_89 , V_75 ) ;
if ( V_68 ) {
V_68 = - V_94 ;
goto V_93;
}
memcpy ( V_82 -> V_89 , V_73 -> V_89 , strlen ( V_73 -> V_89 ) ) ;
V_82 -> V_95 = V_96 ;
V_82 -> V_97 = V_98 | V_99 ;
V_82 -> V_100 . V_101 = & V_73 -> V_100 ;
V_82 -> V_102 = V_73 -> V_19 ;
V_82 -> V_103 = V_46 ;
V_82 -> V_104 = & V_105 ;
F_42 ( & V_75 -> V_36 ) ;
F_43 ( & V_75 -> V_41 ) ;
F_2 ( V_75 ) ;
F_4 ( V_75 ) ;
F_44 ( V_73 , V_82 ) ;
V_82 -> V_61 = V_75 ;
F_45 ( V_82 ) ;
return 0 ;
V_93:
F_33 ( V_75 -> V_9 ) ;
V_91:
F_34 ( V_77 -> V_79 , V_80 ) ;
V_88:
F_35 ( V_75 ) ;
V_86:
F_35 ( V_82 ) ;
V_85:
return V_68 ;
}
