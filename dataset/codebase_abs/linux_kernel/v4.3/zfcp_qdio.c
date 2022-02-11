static void F_1 ( struct V_1 * V_2 , char * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_7 -> V_8 , L_1 ) ;
if ( V_4 & V_9 ) {
F_3 ( V_6 ) ;
F_4 ( V_6 , 0 , V_3 ) ;
return;
}
F_5 ( V_6 ,
V_10 |
V_11 , V_3 ) ;
}
static void F_6 ( struct V_12 * V_13 [] , int V_14 , int V_15 )
{
int V_16 , V_17 ;
for ( V_16 = V_14 ; V_16 < V_14 + V_15 ; V_16 ++ ) {
V_17 = V_16 % V_18 ;
memset ( V_13 [ V_17 ] , 0 , sizeof( struct V_12 ) ) ;
}
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned long long V_19 , V_20 ;
int V_21 ;
V_19 = F_8 () ;
V_20 = ( V_19 - V_2 -> V_22 ) >> 12 ;
V_21 = V_18 - F_9 ( & V_2 -> V_23 ) ;
V_2 -> V_24 += V_21 * V_20 ;
V_2 -> V_22 = V_19 ;
}
static void F_10 ( struct V_7 * V_25 , unsigned int V_4 ,
int V_26 , int V_27 , int V_28 ,
unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
if ( F_11 ( V_4 ) ) {
F_1 ( V_2 , L_2 , V_4 ) ;
return;
}
F_6 ( V_2 -> V_30 , V_27 , V_28 ) ;
F_12 ( & V_2 -> V_31 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_14 ( V_28 , & V_2 -> V_23 ) ;
F_15 ( & V_2 -> V_32 ) ;
}
static void F_16 ( struct V_7 * V_25 , unsigned int V_4 ,
int V_26 , int V_27 , int V_28 ,
unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_33 , V_17 ;
if ( F_11 ( V_4 ) ) {
if ( F_17 ( V_6 ) ) {
void * V_34 [ V_35 + 1 ] ;
struct V_36 * V_37 ;
T_1 V_38 ;
T_2 V_39 ;
memset ( V_34 , 0 ,
V_35 * sizeof( void * ) ) ;
V_37 = V_2 -> V_40 [ V_27 ] -> V_41 ;
V_38 = ( T_1 ) V_37 -> V_42 ;
V_39 = F_18 ( V_37 -> V_39 + 1 ,
V_35 + 1 ) ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
V_17 = ( V_27 + V_33 ) %
V_18 ;
V_34 [ V_33 ] = V_2 -> V_40 [ V_17 ] ;
}
F_19 ( V_6 , V_38 , V_39 , V_34 ) ;
}
F_1 ( V_2 , L_3 , V_4 ) ;
return;
}
for ( V_33 = 0 ; V_33 < V_28 ; V_33 ++ ) {
V_17 = ( V_27 + V_33 ) % V_18 ;
F_20 ( V_2 , V_17 ) ;
}
if ( F_21 ( V_25 , V_43 , 0 , V_27 , V_28 ) )
F_5 ( V_2 -> V_6 , 0 , L_4 ) ;
}
static struct V_36 *
F_22 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_36 * V_37 ;
V_37 = F_23 ( V_2 , V_45 ) ;
V_37 -> V_46 |= V_47 ;
if ( V_45 -> V_48 == V_45 -> V_49 )
return NULL ;
V_37 = F_24 ( V_2 , V_45 ) ;
V_37 -> V_50 |= V_51 ;
V_45 -> V_48 ++ ;
V_45 -> V_48 %= V_18 ;
V_45 -> V_52 ++ ;
F_25 ( V_45 -> V_52 > V_35 ) ;
V_45 -> V_53 = 0 ;
V_37 = F_23 ( V_2 , V_45 ) ;
V_37 -> V_50 |= V_45 -> V_54 ;
return V_37 ;
}
static struct V_36 *
F_26 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
if ( V_45 -> V_53 == V_2 -> V_55 - 1 )
return F_22 ( V_2 , V_45 ) ;
V_45 -> V_53 ++ ;
return F_23 ( V_2 , V_45 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_56 * V_57 )
{
struct V_36 * V_37 ;
V_37 = F_24 ( V_2 , V_45 ) ;
V_37 -> V_50 |= V_45 -> V_54 ;
for (; V_57 ; V_57 = F_28 ( V_57 ) ) {
V_37 = F_26 ( V_2 , V_45 ) ;
if ( ! V_37 ) {
F_29 ( & V_2 -> V_58 ) ;
F_6 ( V_2 -> V_30 , V_45 -> V_59 ,
V_45 -> V_52 ) ;
return - V_60 ;
}
V_37 -> V_42 = F_30 ( V_57 ) ;
V_37 -> V_61 = V_57 -> V_61 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
if ( F_9 ( & V_2 -> V_23 ) ||
! ( F_9 ( & V_2 -> V_6 -> V_62 ) & V_63 ) )
return 1 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
long V_64 ;
V_64 = F_33 ( V_2 -> V_32 ,
F_31 ( V_2 ) , V_2 -> V_65 , 5 * V_66 ) ;
if ( ! ( F_9 ( & V_2 -> V_6 -> V_62 ) & V_63 ) )
return - V_67 ;
if ( V_64 > 0 )
return 0 ;
if ( ! V_64 ) {
F_29 ( & V_2 -> V_58 ) ;
F_5 ( V_2 -> V_6 , 0 , L_5 ) ;
}
return - V_67 ;
}
int F_34 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_68 ;
T_2 V_52 = V_45 -> V_52 ;
F_35 ( & V_2 -> V_31 ) ;
F_7 ( V_2 ) ;
F_36 ( & V_2 -> V_31 ) ;
V_68 = F_21 ( V_2 -> V_6 -> V_7 , V_69 , 0 ,
V_45 -> V_59 , V_52 ) ;
if ( F_11 ( V_68 ) ) {
F_6 ( V_2 -> V_30 , V_45 -> V_59 ,
V_52 ) ;
return V_68 ;
}
F_37 ( V_52 , & V_2 -> V_23 ) ;
V_2 -> V_70 += V_52 ;
V_2 -> V_70 %= V_18 ;
return 0 ;
}
static void F_38 ( struct V_71 * V_3 ,
struct V_1 * V_2 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_25 = V_2 -> V_6 -> V_7 ;
V_3 -> V_72 = V_73 ;
memcpy ( V_3 -> V_74 , F_39 ( & V_3 -> V_25 -> V_8 ) , 8 ) ;
F_40 ( V_3 -> V_74 , 8 ) ;
V_3 -> V_75 = V_76 ;
if ( V_77 )
V_3 -> V_78 |= V_79 ;
V_3 -> V_80 = 1 ;
V_3 -> V_81 = 1 ;
V_3 -> V_82 = F_16 ;
V_3 -> V_83 = F_10 ;
V_3 -> V_84 = ( unsigned long ) V_2 ;
V_3 -> V_85 = ( void * * ) ( V_2 -> V_40 ) ;
V_3 -> V_86 = ( void * * ) ( V_2 -> V_30 ) ;
V_3 -> V_87 =
V_18 - V_35 * 2 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_71 V_88 ;
int V_64 ;
V_64 = F_42 ( V_2 -> V_30 , V_18 ) ;
if ( V_64 )
return - V_89 ;
V_64 = F_42 ( V_2 -> V_40 , V_18 ) ;
if ( V_64 )
goto V_90;
F_38 ( & V_88 , V_2 ) ;
F_43 ( & V_2 -> V_32 ) ;
V_64 = F_44 ( & V_88 ) ;
if ( V_64 )
goto V_91;
return 0 ;
V_91:
F_45 ( V_2 -> V_40 , V_18 ) ;
V_90:
F_45 ( V_2 -> V_30 , V_18 ) ;
return V_64 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_27 , V_28 ;
if ( ! ( F_9 ( & V_6 -> V_62 ) & V_63 ) )
return;
F_12 ( & V_2 -> V_65 ) ;
F_47 ( V_63 , & V_6 -> V_62 ) ;
F_13 ( & V_2 -> V_65 ) ;
F_15 ( & V_2 -> V_32 ) ;
F_48 ( V_6 -> V_7 , V_92 ) ;
V_28 = F_9 ( & V_2 -> V_23 ) ;
if ( V_28 < V_18 ) {
V_27 = ( V_2 -> V_70 + V_28 ) % V_18 ;
V_28 = V_18 - V_28 ;
F_6 ( V_2 -> V_30 , V_27 , V_28 ) ;
}
V_2 -> V_70 = 0 ;
F_49 ( & V_2 -> V_23 , 0 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_71 V_88 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_25 = V_6 -> V_7 ;
struct V_93 V_94 ;
int V_95 ;
if ( F_9 ( & V_6 -> V_62 ) & V_63 )
return - V_67 ;
F_47 ( V_96 ,
& V_2 -> V_6 -> V_62 ) ;
F_38 ( & V_88 , V_2 ) ;
if ( F_51 ( & V_88 ) )
goto V_97;
if ( F_52 ( V_88 . V_25 , & V_94 ) )
goto V_98;
if ( V_94 . V_99 & V_100 )
F_53 ( V_101 ,
& V_2 -> V_6 -> V_62 ) ;
if ( V_94 . V_99 & V_102 ) {
F_53 ( V_103 , & V_6 -> V_62 ) ;
V_2 -> V_55 = V_104 ;
} else {
F_47 ( V_103 , & V_6 -> V_62 ) ;
V_2 -> V_55 = V_104 - 1 ;
}
V_2 -> V_105 =
V_35 * V_2 -> V_55
- 2 ;
if ( F_54 ( V_25 ) )
goto V_98;
for ( V_95 = 0 ; V_95 < V_18 ; V_95 ++ ) {
V_37 = & ( V_2 -> V_40 [ V_95 ] -> V_41 [ 0 ] ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_46 = V_47 ;
V_37 -> V_50 = 0 ;
V_37 -> V_42 = NULL ;
}
if ( F_21 ( V_25 , V_43 , 0 , 0 , V_18 ) )
goto V_98;
V_2 -> V_70 = 0 ;
F_49 ( & V_2 -> V_23 , V_18 ) ;
F_53 ( V_63 , & V_2 -> V_6 -> V_62 ) ;
if ( V_6 -> V_106 ) {
V_6 -> V_106 -> V_107 = V_2 -> V_105 ;
V_6 -> V_106 -> V_108 = V_2 -> V_105 * 8 ;
}
return 0 ;
V_98:
F_48 ( V_25 , V_92 ) ;
V_97:
F_55 ( & V_25 -> V_8 ,
L_6 ) ;
return - V_67 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_6 -> V_7 )
F_57 ( V_2 -> V_6 -> V_7 ) ;
F_45 ( V_2 -> V_30 , V_18 ) ;
F_45 ( V_2 -> V_40 , V_18 ) ;
F_58 ( V_2 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_2 )
return - V_89 ;
V_2 -> V_6 = V_6 ;
if ( F_41 ( V_2 ) ) {
F_58 ( V_2 ) ;
return - V_89 ;
}
F_61 ( & V_2 -> V_65 ) ;
F_61 ( & V_2 -> V_31 ) ;
V_6 -> V_2 = V_2 ;
return 0 ;
}
void F_3 ( struct V_5 * V_6 )
{
int V_110 ;
if ( F_9 ( & V_6 -> V_62 ) & V_96 )
return;
V_110 = F_62 ( V_6 -> V_7 ) ;
if ( ! V_110 )
F_53 ( V_96 ,
& V_6 -> V_62 ) ;
}
