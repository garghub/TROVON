static int F_1 ( struct V_1 * * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 += V_5 ) {
V_2 [ V_3 ] = (struct V_1 * ) F_2 ( V_6 ) ;
if ( ! V_2 [ V_3 ] )
return - V_7 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_3 % V_5 )
V_2 [ V_3 ] = V_2 [ V_3 - 1 ] + 1 ;
return 0 ;
}
static void F_3 ( struct V_8 * V_9 , char * V_10 ,
unsigned int V_11 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
F_4 ( & V_13 -> V_14 -> V_15 , L_1 ) ;
if ( V_11 & V_16 ) {
F_5 ( V_13 ) ;
F_6 ( V_13 , 0 , V_10 ) ;
return;
}
F_7 ( V_13 ,
V_17 |
V_18 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 [] , int V_19 , int V_20 )
{
int V_21 , V_22 ;
for ( V_21 = V_19 ; V_21 < V_19 + V_20 ; V_21 ++ ) {
V_22 = V_21 % V_4 ;
memset ( V_2 [ V_22 ] , 0 , sizeof( struct V_1 ) ) ;
}
}
static inline void F_9 ( struct V_8 * V_9 )
{
unsigned long long V_23 , V_24 ;
int V_25 ;
V_23 = F_10 () ;
V_24 = ( V_23 - V_9 -> V_26 ) >> 12 ;
V_25 = V_4 - F_11 ( & V_9 -> V_27 ) ;
V_9 -> V_28 += V_25 * V_24 ;
V_9 -> V_26 = V_23 ;
}
static void F_12 ( struct V_14 * V_29 , unsigned int V_11 ,
int V_30 , int V_31 , int V_32 ,
unsigned long V_33 )
{
struct V_8 * V_9 = (struct V_8 * ) V_33 ;
if ( F_13 ( V_11 ) ) {
F_3 ( V_9 , L_2 , V_11 ) ;
return;
}
F_8 ( V_9 -> V_34 , V_31 , V_32 ) ;
F_14 ( & V_9 -> V_35 ) ;
F_9 ( V_9 ) ;
F_15 ( & V_9 -> V_35 ) ;
F_16 ( V_32 , & V_9 -> V_27 ) ;
F_17 ( & V_9 -> V_36 ) ;
}
static void F_18 ( struct V_14 * V_29 , unsigned int V_11 ,
int V_30 , int V_31 , int V_32 ,
unsigned long V_33 )
{
struct V_8 * V_9 = (struct V_8 * ) V_33 ;
struct V_12 * V_13 = V_9 -> V_13 ;
int V_37 , V_22 ;
if ( F_13 ( V_11 ) ) {
if ( F_19 ( V_13 ) ) {
void * V_38 [ V_39 + 1 ] ;
struct V_40 * V_41 ;
T_1 V_42 ;
T_2 V_43 ;
memset ( V_38 , 0 ,
V_39 * sizeof( void * ) ) ;
V_41 = V_9 -> V_44 [ V_31 ] -> V_45 ;
V_42 = ( T_1 ) V_41 -> V_46 ;
V_43 = F_20 ( V_41 -> V_43 + 1 ,
V_39 + 1 ) ;
for ( V_37 = 0 ; V_37 < V_43 ; V_37 ++ ) {
V_22 = ( V_31 + V_37 ) %
V_4 ;
V_38 [ V_37 ] = V_9 -> V_44 [ V_22 ] ;
}
F_21 ( V_13 , V_42 , V_43 , V_38 ) ;
}
F_3 ( V_9 , L_3 , V_11 ) ;
return;
}
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
V_22 = ( V_31 + V_37 ) % V_4 ;
F_22 ( V_9 , V_22 ) ;
}
if ( F_23 ( V_29 , V_47 , 0 , V_31 , V_32 ) )
F_7 ( V_9 -> V_13 , 0 , L_4 ) ;
}
static struct V_40 *
F_24 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
struct V_40 * V_41 ;
V_41 = F_25 ( V_9 , V_49 ) ;
V_41 -> V_50 |= V_51 ;
if ( V_49 -> V_52 == V_49 -> V_53 )
return NULL ;
V_41 = F_26 ( V_9 , V_49 ) ;
V_41 -> V_54 |= V_55 ;
V_49 -> V_52 ++ ;
V_49 -> V_52 %= V_4 ;
V_49 -> V_56 ++ ;
F_27 ( V_49 -> V_56 > V_39 ) ;
V_49 -> V_57 = 0 ;
V_41 = F_25 ( V_9 , V_49 ) ;
V_41 -> V_54 |= V_49 -> V_58 ;
return V_41 ;
}
static struct V_40 *
F_28 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
if ( V_49 -> V_57 == V_9 -> V_59 - 1 )
return F_24 ( V_9 , V_49 ) ;
V_49 -> V_57 ++ ;
return F_25 ( V_9 , V_49 ) ;
}
int F_29 ( struct V_8 * V_9 , struct V_48 * V_49 ,
struct V_60 * V_61 )
{
struct V_40 * V_41 ;
V_41 = F_26 ( V_9 , V_49 ) ;
V_41 -> V_54 |= V_49 -> V_58 ;
for (; V_61 ; V_61 = F_30 ( V_61 ) ) {
V_41 = F_28 ( V_9 , V_49 ) ;
if ( ! V_41 ) {
F_31 ( & V_9 -> V_62 ) ;
F_8 ( V_9 -> V_34 , V_49 -> V_63 ,
V_49 -> V_56 ) ;
return - V_64 ;
}
V_41 -> V_46 = F_32 ( V_61 ) ;
V_41 -> V_65 = V_61 -> V_65 ;
}
return 0 ;
}
static int F_33 ( struct V_8 * V_9 )
{
if ( F_11 ( & V_9 -> V_27 ) ||
! ( F_11 ( & V_9 -> V_13 -> V_66 ) & V_67 ) )
return 1 ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 )
{
long V_68 ;
V_68 = F_35 ( V_9 -> V_36 ,
F_33 ( V_9 ) , V_9 -> V_69 , 5 * V_70 ) ;
if ( ! ( F_11 ( & V_9 -> V_13 -> V_66 ) & V_67 ) )
return - V_71 ;
if ( V_68 > 0 )
return 0 ;
if ( ! V_68 ) {
F_31 ( & V_9 -> V_62 ) ;
F_7 ( V_9 -> V_13 , 0 , L_5 ) ;
}
return - V_71 ;
}
int F_36 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
int V_72 ;
T_2 V_56 = V_49 -> V_56 ;
F_37 ( & V_9 -> V_35 ) ;
F_9 ( V_9 ) ;
F_38 ( & V_9 -> V_35 ) ;
V_72 = F_23 ( V_9 -> V_13 -> V_14 , V_73 , 0 ,
V_49 -> V_63 , V_56 ) ;
if ( F_13 ( V_72 ) ) {
F_8 ( V_9 -> V_34 , V_49 -> V_63 ,
V_56 ) ;
return V_72 ;
}
F_39 ( V_56 , & V_9 -> V_27 ) ;
V_9 -> V_74 += V_56 ;
V_9 -> V_74 %= V_4 ;
return 0 ;
}
static void F_40 ( struct V_75 * V_10 ,
struct V_8 * V_9 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_29 = V_9 -> V_13 -> V_14 ;
V_10 -> V_76 = V_77 ;
memcpy ( V_10 -> V_78 , F_41 ( & V_10 -> V_29 -> V_15 ) , 8 ) ;
F_42 ( V_10 -> V_78 , 8 ) ;
V_10 -> V_79 = V_80 ;
if ( V_81 )
V_10 -> V_82 |= V_83 ;
V_10 -> V_84 = 1 ;
V_10 -> V_85 = 1 ;
V_10 -> V_86 = F_18 ;
V_10 -> V_87 = F_12 ;
V_10 -> V_88 = ( unsigned long ) V_9 ;
V_10 -> V_89 = ( void * * ) ( V_9 -> V_44 ) ;
V_10 -> V_90 = ( void * * ) ( V_9 -> V_34 ) ;
V_10 -> V_91 =
V_4 - V_39 * 2 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_75 V_92 ;
if ( F_1 ( V_9 -> V_34 ) ||
F_1 ( V_9 -> V_44 ) )
return - V_7 ;
F_40 ( & V_92 , V_9 ) ;
F_44 ( & V_9 -> V_36 ) ;
return F_45 ( & V_92 ) ;
}
void F_46 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
int V_31 , V_32 ;
if ( ! ( F_11 ( & V_13 -> V_66 ) & V_67 ) )
return;
F_14 ( & V_9 -> V_69 ) ;
F_47 ( V_67 , & V_13 -> V_66 ) ;
F_15 ( & V_9 -> V_69 ) ;
F_17 ( & V_9 -> V_36 ) ;
F_48 ( V_13 -> V_14 , V_93 ) ;
V_32 = F_11 ( & V_9 -> V_27 ) ;
if ( V_32 < V_4 ) {
V_31 = ( V_9 -> V_74 + V_32 ) % V_4 ;
V_32 = V_4 - V_32 ;
F_8 ( V_9 -> V_34 , V_31 , V_32 ) ;
}
V_9 -> V_74 = 0 ;
F_49 ( & V_9 -> V_27 , 0 ) ;
}
int F_50 ( struct V_8 * V_9 )
{
struct V_40 * V_41 ;
struct V_75 V_92 ;
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_14 * V_29 = V_13 -> V_14 ;
struct V_94 V_95 ;
int V_96 ;
if ( F_11 ( & V_13 -> V_66 ) & V_67 )
return - V_71 ;
F_47 ( V_97 ,
& V_9 -> V_13 -> V_66 ) ;
F_40 ( & V_92 , V_9 ) ;
if ( F_51 ( & V_92 ) )
goto V_98;
if ( F_52 ( V_92 . V_29 , & V_95 ) )
goto V_99;
if ( V_95 . V_100 & V_101 )
F_53 ( V_102 ,
& V_9 -> V_13 -> V_66 ) ;
if ( V_95 . V_100 & V_103 ) {
F_53 ( V_104 , & V_13 -> V_66 ) ;
V_9 -> V_59 = V_105 ;
} else {
F_47 ( V_104 , & V_13 -> V_66 ) ;
V_9 -> V_59 = V_105 - 1 ;
}
V_9 -> V_106 =
V_39 * V_9 -> V_59
- 2 ;
if ( F_54 ( V_29 ) )
goto V_99;
for ( V_96 = 0 ; V_96 < V_4 ; V_96 ++ ) {
V_41 = & ( V_9 -> V_44 [ V_96 ] -> V_45 [ 0 ] ) ;
V_41 -> V_65 = 0 ;
V_41 -> V_50 = V_51 ;
V_41 -> V_54 = 0 ;
V_41 -> V_46 = NULL ;
}
if ( F_23 ( V_29 , V_47 , 0 , 0 , V_4 ) )
goto V_99;
V_9 -> V_74 = 0 ;
F_49 ( & V_9 -> V_27 , V_4 ) ;
F_53 ( V_67 , & V_9 -> V_13 -> V_66 ) ;
if ( V_13 -> V_107 ) {
V_13 -> V_107 -> V_108 = V_9 -> V_106 ;
V_13 -> V_107 -> V_109 = V_9 -> V_106 * 8 ;
}
return 0 ;
V_99:
F_48 ( V_29 , V_93 ) ;
V_98:
F_55 ( & V_29 -> V_15 ,
L_6 ) ;
return - V_71 ;
}
void F_56 ( struct V_8 * V_9 )
{
int V_110 ;
if ( ! V_9 )
return;
if ( V_9 -> V_13 -> V_14 )
F_57 ( V_9 -> V_13 -> V_14 ) ;
for ( V_110 = 0 ; V_110 < V_4 ; V_110 += V_5 ) {
F_58 ( ( unsigned long ) V_9 -> V_34 [ V_110 ] ) ;
F_58 ( ( unsigned long ) V_9 -> V_44 [ V_110 ] ) ;
}
F_59 ( V_9 ) ;
}
int F_60 ( struct V_12 * V_13 )
{
struct V_8 * V_9 ;
V_9 = F_61 ( sizeof( struct V_8 ) , V_6 ) ;
if ( ! V_9 )
return - V_7 ;
V_9 -> V_13 = V_13 ;
if ( F_43 ( V_9 ) ) {
F_56 ( V_9 ) ;
return - V_7 ;
}
F_62 ( & V_9 -> V_69 ) ;
F_62 ( & V_9 -> V_35 ) ;
V_13 -> V_9 = V_9 ;
return 0 ;
}
void F_5 ( struct V_12 * V_13 )
{
int V_111 ;
if ( F_11 ( & V_13 -> V_66 ) & V_97 )
return;
V_111 = F_63 ( V_13 -> V_14 ) ;
if ( ! V_111 )
F_53 ( V_97 ,
& V_13 -> V_66 ) ;
}
