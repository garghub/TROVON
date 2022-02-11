static inline unsigned char
F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 ) ;
return V_3 ;
}
static void
F_3 ( struct V_4 * V_5 )
{
F_4 ( V_6 , V_5 -> V_7 + V_8 ) ;
F_4 ( V_9 , V_5 -> V_7 + V_10 ) ;
F_4 ( 0 , V_5 -> V_7 + V_8 ) ;
}
static void
F_5 ( struct V_4 * V_5 )
{
T_1 V_11 = V_12 | V_13 | V_14 ;
#if F_6 ( V_15 ) || F_6 ( V_16 )
if ( V_5 -> V_17 == 0 ) {
F_7 ( 7 , 0 ) ;
F_7 ( 6 , 0 ) ;
} else {
F_7 ( 5 , 0 ) ;
F_7 ( 4 , 0 ) ;
}
#endif
V_5 -> V_18 =
V_19 | V_20 |
V_21 | V_22 ;
V_11 |= V_23 | V_24 |
V_25 | V_26 ;
F_4 ( V_11 , V_5 -> V_7 + V_8 ) ;
}
static void
F_8 ( struct V_4 * V_5 )
{
unsigned long V_11 = F_9 ( V_5 -> V_7 + V_8 ) ;
V_11 &= ~ ( V_27 | V_28 |
V_29 | V_13 ) ;
F_4 ( V_11 , V_5 -> V_7 + V_8 ) ;
}
static T_2
F_10 ( int V_30 , void * V_31 )
{
struct V_4 * V_5 = V_31 ;
T_1 V_32 = F_9 ( V_5 -> V_7 + V_10 ) ;
if ( ( V_32 &= V_5 -> V_18 ) ) {
F_4 ( V_32 , V_5 -> V_7 + V_10 ) ;
V_5 -> V_33 |= V_32 ;
F_11 ( & V_5 -> V_34 ) ;
}
return V_35 ;
}
static int
F_12 ( T_1 V_32 )
{
int V_36 = 0 ;
if ( ( V_32 & V_20 ) ) {
if ( ! V_36 ) V_36 = - V_37 ;
}
if ( ( V_32 & V_19 ) ) {
if ( ! V_36 ) V_36 = - V_38 ;
}
return V_36 ;
}
static inline T_1
F_13 ( struct V_4 * V_5 )
{
unsigned long V_39 ;
T_1 V_32 ;
F_14 ( & V_5 -> V_40 , V_39 ) ;
V_32 = V_5 -> V_33 ;
V_5 -> V_33 = 0 ;
F_15 ( & V_5 -> V_40 , V_39 ) ;
return V_32 ;
}
static int
F_16 ( struct V_4 * V_5 ,
unsigned V_39 , unsigned * V_41 ,
T_3 V_42 )
{
unsigned V_32 = 0 ;
int V_43 ;
int V_44 ;
int V_36 = 0 ;
do {
V_43 = F_17 (
V_5 -> V_34 ,
( V_44 = V_42 ( V_32 = F_13 ( V_5 ) , V_39 ) ) ,
1 * V_45
) ;
if ( ( V_36 = F_12 ( V_32 ) ) < 0 ) {
* V_41 = V_32 ;
return V_36 ;
} else if ( ! V_43 ) {
* V_41 = V_32 ;
return - V_46 ;
}
} while( ! V_44 );
* V_41 = V_32 ;
return 0 ;
}
static int
F_18 ( unsigned V_47 , unsigned V_48 )
{
return ( V_47 & V_48 ) == 0 ;
}
static int
F_19 ( unsigned V_47 , unsigned V_48 )
{
return ( V_47 & V_48 ) != 0 ;
}
static int
F_20 ( struct V_4 * V_5 , int * V_41 )
{
return F_16 (
V_5 ,
V_22 | V_19 | V_20 ,
V_41 , F_19 ) ;
}
static int
F_21 ( struct V_4 * V_5 , int * V_41 )
{
return F_16 (
V_5 ,
V_21 | V_19 | V_20 ,
V_41 , F_19 ) ;
}
static int
F_22 ( struct V_4 * V_5 , int * V_41 )
{
return F_16 (
V_5 , V_49 , V_41 , F_18 ) ;
}
static int
F_23 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
unsigned long V_11 = F_9 ( V_5 -> V_7 + V_8 ) ;
int V_41 ;
int V_36 ;
if ( V_2 -> V_3 == V_50 ) {
return - V_51 ;
}
F_4 ( F_1 ( V_2 ) , V_5 -> V_7 + V_52 ) ;
V_11 &= ~ ( V_29 | V_53 ) ;
V_11 |= V_27 | V_28 ;
F_4 ( V_11 , V_5 -> V_7 + V_8 ) ;
V_36 = F_20 ( V_5 , & V_41 ) ;
return V_36 ;
}
static int
F_24 ( struct V_4 * V_5 , char V_54 ,
int V_55 )
{
unsigned long V_11 = F_9 ( V_5 -> V_7 + V_8 ) ;
int V_41 ;
int V_36 = 0 ;
F_4 ( V_54 , V_5 -> V_7 + V_52 ) ;
V_11 &= ~ V_27 ;
if ( V_55 ) {
V_11 |= V_29 ;
} else {
V_11 &= ~ V_29 ;
}
V_11 |= V_28 ;
F_4 ( V_11 , V_5 -> V_7 + V_8 ) ;
V_36 = F_20 ( V_5 , & V_41 ) ;
return V_36 ;
}
static int
F_25 ( struct V_4 * V_5 , char * V_54 ,
int V_55 )
{
unsigned long V_11 = F_9 ( V_5 -> V_7 + V_8 ) ;
int V_41 ;
int V_36 = 0 ;
V_11 &= ~ V_27 ;
if ( V_55 ) {
V_11 |= V_29 | V_53 ;
} else {
V_11 &= ~ ( V_29 | V_53 ) ;
}
V_11 |= V_28 ;
F_4 ( V_11 , V_5 -> V_7 + V_8 ) ;
V_36 = F_21 ( V_5 , & V_41 ) ;
* V_54 = F_9 ( V_5 -> V_7 + V_52 ) ;
return V_36 ;
}
static int
F_26 ( struct V_56 * V_57 , const char * V_58 , int V_59 )
{
struct V_4 * V_5 = V_57 -> V_60 ;
int V_61 ;
int V_36 = 0 ;
for ( V_61 = 0 ; V_36 == 0 && V_61 != V_59 ; ++ V_61 )
V_36 = F_24 ( V_5 , V_58 [ V_61 ] , V_61 == V_59 - 1 ) ;
return V_36 ;
}
static int
F_27 ( struct V_56 * V_57 , char * V_58 , int V_59 )
{
struct V_4 * V_5 = V_57 -> V_60 ;
int V_61 ;
int V_36 = 0 ;
for ( V_61 = 0 ; V_36 == 0 && V_61 != V_59 ; ++ V_61 )
V_36 = F_25 ( V_5 , & V_58 [ V_61 ] , V_61 == V_59 - 1 ) ;
return V_36 ;
}
static int
F_28 ( struct V_56 * V_57 , struct V_1 * V_62 )
{
struct V_4 * V_5 = V_57 -> V_60 ;
int V_36 ;
V_36 = F_23 ( V_5 , V_62 ) ;
if ( V_36 < 0 ) {
return V_36 ;
}
if ( ( V_62 -> V_39 & V_63 ) ) {
return F_27 ( V_57 , V_62 -> V_58 , V_62 -> V_64 ) ;
} else {
return F_26 ( V_57 , V_62 -> V_58 , V_62 -> V_64 ) ;
}
}
static int
F_29 ( struct V_56 * V_57 , struct V_1 * V_65 ,
int V_66 )
{
struct V_4 * V_5 = V_57 -> V_60 ;
int V_67 = 0 ;
int V_68 = 0 ;
int V_41 ;
F_22 ( V_5 , & V_41 ) ;
F_3 ( V_5 ) ;
F_5 ( V_5 ) ;
for ( V_67 = 0 ; V_68 == 0 && V_67 != V_66 ; V_67 ++ ) {
V_68 = F_28 ( V_57 , & V_65 [ V_67 ] ) ;
}
F_8 ( V_5 ) ;
if( V_68 )
return V_68 ;
return V_67 ;
}
static T_1
F_30 ( struct V_56 * V_69 )
{
return V_70 | V_71 ;
}
static int
F_31 ( struct V_72 * V_73 )
{
struct V_56 * V_74 = F_32 ( V_73 ) ;
struct V_4 * V_75 =
(struct V_4 * ) V_74 -> V_60 ;
struct V_76 * V_77 = F_33 ( V_73 , V_78 , 0 ) ;
unsigned long V_11 = F_9 ( V_75 -> V_7 + V_8 ) ;
V_11 &= ~ ( V_23 | V_24 |
V_25 | V_26 ) ;
F_4 ( V_11 , V_75 -> V_7 + V_8 ) ;
F_34 ( V_75 -> V_7 ) ;
F_35 ( V_77 -> V_79 , V_80 ) ;
F_36 ( V_75 ) ;
F_36 ( V_74 ) ;
return 0 ;
}
static int
F_37 ( struct V_72 * V_73 )
{
struct V_76 * V_77 ;
int V_68 , V_81 ;
struct V_56 * V_82 ;
struct V_4 * V_75 ;
V_82 = F_38 ( sizeof( struct V_56 ) , V_83 ) ;
if ( ! V_82 ) {
V_68 = - V_84 ;
goto V_85;
}
V_75 = F_38 ( sizeof( struct V_4 ) , V_83 ) ;
if ( ! V_75 ) {
V_68 = - V_84 ;
goto V_86;
}
V_77 = F_33 ( V_73 , V_78 , 0 ) ;
if ( ! V_77 ) {
V_68 = - V_87 ;
goto V_88;
}
if ( ! F_39 ( V_77 -> V_79 , V_80 , V_73 -> V_89 ) ) {
V_68 = - V_51 ;
goto V_88;
}
V_75 -> V_17 = V_90 ++ ;
V_75 -> V_7 = F_40 ( V_77 -> V_79 , V_80 ) ;
if ( ! V_75 -> V_7 ) {
V_68 = - V_84 ;
goto V_91;
}
V_81 = F_41 ( V_73 , 0 ) ;
if ( V_81 < 0 ) {
V_68 = - V_92 ;
goto V_93;
}
V_68 = F_42 ( V_81 , F_10 , 0 ,
V_73 -> V_89 , V_75 ) ;
if ( V_68 ) {
V_68 = - V_94 ;
goto V_93;
}
memcpy ( V_82 -> V_89 , V_73 -> V_89 , strlen ( V_73 -> V_89 ) ) ;
V_82 -> V_95 = V_96 ;
V_82 -> V_97 = V_98 | V_99 ;
V_82 -> V_100 . V_101 = & V_73 -> V_100 ;
V_82 -> V_102 = V_73 -> V_17 ;
V_82 -> V_103 = V_45 ;
V_82 -> V_104 = & V_105 ;
F_43 ( & V_75 -> V_34 ) ;
F_44 ( & V_75 -> V_40 ) ;
F_3 ( V_75 ) ;
F_5 ( V_75 ) ;
F_45 ( V_73 , V_82 ) ;
V_82 -> V_60 = V_75 ;
F_46 ( V_82 ) ;
return 0 ;
V_93:
F_34 ( V_75 -> V_7 ) ;
V_91:
F_35 ( V_77 -> V_79 , V_80 ) ;
V_88:
F_36 ( V_75 ) ;
V_86:
F_36 ( V_82 ) ;
V_85:
return V_68 ;
}
