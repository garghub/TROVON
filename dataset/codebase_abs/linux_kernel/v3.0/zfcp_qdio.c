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
if ( V_11 & V_16 )
F_5 ( V_13 ) ;
F_6 ( V_13 ,
V_17 |
V_18 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 [] , int V_19 , int V_20 )
{
int V_21 , V_22 ;
for ( V_21 = V_19 ; V_21 < V_19 + V_20 ; V_21 ++ ) {
V_22 = V_21 % V_4 ;
memset ( V_2 [ V_22 ] , 0 , sizeof( struct V_1 ) ) ;
}
}
static inline void F_8 ( struct V_8 * V_9 )
{
unsigned long long V_23 , V_24 ;
int V_25 ;
V_23 = F_9 () ;
V_24 = ( V_23 - V_9 -> V_26 ) >> 12 ;
V_25 = V_4 - F_10 ( & V_9 -> V_27 ) ;
V_9 -> V_28 += V_25 * V_24 ;
V_9 -> V_26 = V_23 ;
}
static void F_11 ( struct V_14 * V_29 , unsigned int V_11 ,
int V_30 , int V_31 , int V_32 ,
unsigned long V_33 )
{
struct V_8 * V_9 = (struct V_8 * ) V_33 ;
if ( F_12 ( V_11 ) ) {
F_3 ( V_9 , L_2 , V_11 ) ;
return;
}
F_7 ( V_9 -> V_34 , V_31 , V_32 ) ;
F_13 ( & V_9 -> V_35 ) ;
F_8 ( V_9 ) ;
F_14 ( & V_9 -> V_35 ) ;
F_15 ( V_32 , & V_9 -> V_27 ) ;
F_16 ( & V_9 -> V_36 ) ;
}
static void F_17 ( struct V_14 * V_29 , unsigned int V_11 ,
int V_30 , int V_31 , int V_32 ,
unsigned long V_33 )
{
struct V_8 * V_9 = (struct V_8 * ) V_33 ;
int V_22 , V_37 ;
if ( F_12 ( V_11 ) ) {
F_3 ( V_9 , L_3 , V_11 ) ;
return;
}
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
V_22 = ( V_31 + V_37 ) % V_4 ;
F_18 ( V_9 , V_22 ) ;
}
if ( F_19 ( V_29 , V_38 , 0 , V_31 , V_32 ) )
F_6 ( V_9 -> V_13 , 0 , L_4 ) ;
}
static struct V_39 *
F_20 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
struct V_39 * V_42 ;
V_42 = F_21 ( V_9 , V_41 ) ;
V_42 -> V_43 |= V_44 ;
if ( V_41 -> V_45 == V_41 -> V_46 )
return NULL ;
V_42 = F_22 ( V_9 , V_41 ) ;
V_42 -> V_47 |= V_48 ;
V_41 -> V_45 ++ ;
V_41 -> V_45 %= V_4 ;
V_41 -> V_49 ++ ;
F_23 ( V_41 -> V_49 > V_50 ) ;
V_41 -> V_51 = 0 ;
V_42 = F_21 ( V_9 , V_41 ) ;
V_42 -> V_47 |= V_41 -> V_52 ;
return V_42 ;
}
static struct V_39 *
F_24 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
if ( V_41 -> V_51 == V_53 )
return F_20 ( V_9 , V_41 ) ;
V_41 -> V_51 ++ ;
return F_21 ( V_9 , V_41 ) ;
}
int F_25 ( struct V_8 * V_9 , struct V_40 * V_41 ,
struct V_54 * V_55 )
{
struct V_39 * V_42 ;
int V_56 = 0 ;
V_42 = F_22 ( V_9 , V_41 ) ;
V_42 -> V_47 |= V_41 -> V_52 ;
for (; V_55 ; V_55 = F_26 ( V_55 ) ) {
V_42 = F_24 ( V_9 , V_41 ) ;
if ( ! V_42 ) {
F_27 ( & V_9 -> V_57 ) ;
F_7 ( V_9 -> V_34 , V_41 -> V_58 ,
V_41 -> V_49 ) ;
return - V_59 ;
}
V_42 -> V_60 = F_28 ( V_55 ) ;
V_42 -> V_61 = V_55 -> V_61 ;
V_56 += V_55 -> V_61 ;
}
return V_56 ;
}
static int F_29 ( struct V_8 * V_9 )
{
F_13 ( & V_9 -> V_62 ) ;
if ( F_10 ( & V_9 -> V_27 ) ||
! ( F_10 ( & V_9 -> V_13 -> V_63 ) & V_64 ) )
return 1 ;
F_14 ( & V_9 -> V_62 ) ;
return 0 ;
}
int F_30 ( struct V_8 * V_9 )
{
long V_65 ;
F_14 ( & V_9 -> V_62 ) ;
V_65 = F_31 ( V_9 -> V_36 ,
F_29 ( V_9 ) , 5 * V_66 ) ;
if ( ! ( F_10 ( & V_9 -> V_13 -> V_63 ) & V_64 ) )
return - V_67 ;
if ( V_65 > 0 )
return 0 ;
if ( ! V_65 ) {
F_27 ( & V_9 -> V_57 ) ;
F_6 ( V_9 -> V_13 , 0 , L_5 ) ;
}
F_13 ( & V_9 -> V_62 ) ;
return - V_67 ;
}
int F_32 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
int V_68 ;
T_1 V_49 = V_41 -> V_49 ;
F_33 ( & V_9 -> V_35 ) ;
F_8 ( V_9 ) ;
F_34 ( & V_9 -> V_35 ) ;
V_68 = F_19 ( V_9 -> V_13 -> V_14 , V_69 , 0 ,
V_41 -> V_58 , V_49 ) ;
if ( F_12 ( V_68 ) ) {
F_7 ( V_9 -> V_34 , V_41 -> V_58 ,
V_49 ) ;
return V_68 ;
}
F_35 ( V_49 , & V_9 -> V_27 ) ;
V_9 -> V_70 += V_49 ;
V_9 -> V_70 %= V_4 ;
return 0 ;
}
static void F_36 ( struct V_71 * V_10 ,
struct V_8 * V_9 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_29 = V_9 -> V_13 -> V_14 ;
V_10 -> V_72 = V_73 ;
memcpy ( V_10 -> V_74 , F_37 ( & V_10 -> V_29 -> V_15 ) , 8 ) ;
F_38 ( V_10 -> V_74 , 8 ) ;
V_10 -> V_75 = V_76 ;
V_10 -> V_77 = 1 ;
V_10 -> V_78 = 1 ;
V_10 -> V_79 = F_17 ;
V_10 -> V_80 = F_11 ;
V_10 -> V_81 = ( unsigned long ) V_9 ;
V_10 -> V_82 = ( void * * ) ( V_9 -> V_83 ) ;
V_10 -> V_84 = ( void * * ) ( V_9 -> V_34 ) ;
V_10 -> V_85 =
V_4 - V_50 * 2 ;
}
static int F_39 ( struct V_8 * V_9 )
{
struct V_71 V_86 ;
if ( F_1 ( V_9 -> V_34 ) ||
F_1 ( V_9 -> V_83 ) )
return - V_7 ;
F_36 ( & V_86 , V_9 ) ;
F_40 ( & V_9 -> V_36 ) ;
return F_41 ( & V_86 ) ;
}
void F_42 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
int V_31 , V_32 ;
if ( ! ( F_10 ( & V_13 -> V_63 ) & V_64 ) )
return;
F_13 ( & V_9 -> V_62 ) ;
F_43 ( V_64 , & V_13 -> V_63 ) ;
F_14 ( & V_9 -> V_62 ) ;
F_16 ( & V_9 -> V_36 ) ;
F_44 ( V_13 -> V_14 , V_87 ) ;
V_32 = F_10 ( & V_9 -> V_27 ) ;
if ( V_32 < V_4 ) {
V_31 = ( V_9 -> V_70 + V_32 ) % V_4 ;
V_32 = V_4 - V_32 ;
F_7 ( V_9 -> V_34 , V_31 , V_32 ) ;
}
V_9 -> V_70 = 0 ;
F_45 ( & V_9 -> V_27 , 0 ) ;
}
int F_46 ( struct V_8 * V_9 )
{
struct V_39 * V_42 ;
struct V_71 V_86 ;
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_14 * V_29 = V_13 -> V_14 ;
struct V_88 V_89 ;
int V_90 ;
if ( F_10 ( & V_13 -> V_63 ) & V_64 )
return - V_67 ;
F_43 ( V_91 ,
& V_9 -> V_13 -> V_63 ) ;
F_36 ( & V_86 , V_9 ) ;
if ( F_47 ( & V_86 ) )
goto V_92;
if ( F_48 ( V_86 . V_29 , & V_89 ) )
goto V_93;
if ( V_89 . V_94 & V_95 )
F_49 ( V_96 ,
& V_9 -> V_13 -> V_63 ) ;
if ( F_50 ( V_29 ) )
goto V_93;
for ( V_90 = 0 ; V_90 < V_4 ; V_90 ++ ) {
V_42 = & ( V_9 -> V_83 [ V_90 ] -> V_97 [ 0 ] ) ;
V_42 -> V_61 = 0 ;
V_42 -> V_43 = V_44 ;
V_42 -> V_47 = 0 ;
V_42 -> V_60 = NULL ;
}
if ( F_19 ( V_29 , V_38 , 0 , 0 , V_4 ) )
goto V_93;
V_9 -> V_70 = 0 ;
F_45 ( & V_9 -> V_27 , V_4 ) ;
F_49 ( V_64 , & V_9 -> V_13 -> V_63 ) ;
return 0 ;
V_93:
F_44 ( V_29 , V_87 ) ;
V_92:
F_51 ( & V_29 -> V_15 ,
L_6 ) ;
return - V_67 ;
}
void F_52 ( struct V_8 * V_9 )
{
int V_98 ;
if ( ! V_9 )
return;
if ( V_9 -> V_13 -> V_14 )
F_53 ( V_9 -> V_13 -> V_14 ) ;
for ( V_98 = 0 ; V_98 < V_4 ; V_98 += V_5 ) {
F_54 ( ( unsigned long ) V_9 -> V_34 [ V_98 ] ) ;
F_54 ( ( unsigned long ) V_9 -> V_83 [ V_98 ] ) ;
}
F_55 ( V_9 ) ;
}
int F_56 ( struct V_12 * V_13 )
{
struct V_8 * V_9 ;
V_9 = F_57 ( sizeof( struct V_8 ) , V_6 ) ;
if ( ! V_9 )
return - V_7 ;
V_9 -> V_13 = V_13 ;
if ( F_39 ( V_9 ) ) {
F_52 ( V_9 ) ;
return - V_7 ;
}
F_58 ( & V_9 -> V_62 ) ;
F_58 ( & V_9 -> V_35 ) ;
V_13 -> V_9 = V_9 ;
return 0 ;
}
void F_5 ( struct V_12 * V_13 )
{
int V_99 ;
if ( F_10 ( & V_13 -> V_63 ) & V_91 )
return;
V_99 = F_59 ( V_13 -> V_14 ) ;
if ( ! V_99 )
F_49 ( V_91 ,
& V_13 -> V_63 ) ;
}
