static inline struct
V_1 * F_1 ( struct V_2 * V_3 )
{
return
(struct V_1 * )
F_2 ( ( V_4 * )
F_3 ( F_4 ( V_3 ) ) , V_5 ) ;
}
static inline struct V_6 * F_5 ( void * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_7 ;
unsigned long V_9 = V_5 ;
if ( V_9 <= F_6 () )
V_9 = 1 ;
return (struct V_6 * ) F_7 ( V_8 , V_9 ) ;
}
static int F_8 ( struct V_10 * V_3 , void * V_7 ,
const V_4 * V_11 , unsigned int V_12 )
{
struct V_6 * V_13 = F_5 ( V_7 ) ;
T_1 * V_14 = & V_3 -> V_15 ;
int V_16 ;
if ( V_12 != V_17 && V_12 != V_18 &&
V_12 != V_19 ) {
* V_14 |= V_20 ;
return - V_21 ;
}
if ( ! F_9 () )
V_16 = F_10 ( V_13 , V_11 , V_12 ) ;
else {
F_11 () ;
V_16 = F_12 ( V_13 , V_11 , V_12 ) ;
F_13 () ;
}
return V_16 ;
}
static int F_14 ( struct V_10 * V_3 , const V_4 * V_11 ,
unsigned int V_12 )
{
return F_8 ( V_3 , F_3 ( V_3 ) , V_11 , V_12 ) ;
}
static void F_15 ( struct V_10 * V_3 , V_4 * V_22 , const V_4 * V_23 )
{
struct V_6 * V_13 = F_5 ( F_3 ( V_3 ) ) ;
if ( ! F_9 () )
F_16 ( V_13 , V_22 , V_23 ) ;
else {
F_11 () ;
F_17 ( V_13 , V_22 , V_23 ) ;
F_13 () ;
}
}
static void F_18 ( struct V_10 * V_3 , V_4 * V_22 , const V_4 * V_23 )
{
struct V_6 * V_13 = F_5 ( F_3 ( V_3 ) ) ;
if ( ! F_9 () )
F_19 ( V_13 , V_22 , V_23 ) ;
else {
F_11 () ;
F_20 ( V_13 , V_22 , V_23 ) ;
F_13 () ;
}
}
static void F_21 ( struct V_10 * V_3 , V_4 * V_22 , const V_4 * V_23 )
{
struct V_6 * V_13 = F_5 ( F_3 ( V_3 ) ) ;
F_17 ( V_13 , V_22 , V_23 ) ;
}
static void F_22 ( struct V_10 * V_3 , V_4 * V_22 , const V_4 * V_23 )
{
struct V_6 * V_13 = F_5 ( F_3 ( V_3 ) ) ;
F_20 ( V_13 , V_22 , V_23 ) ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_26 * V_22 , struct V_26 * V_23 ,
unsigned int V_27 )
{
struct V_6 * V_13 = F_5 ( F_24 ( V_25 -> V_3 ) ) ;
struct V_28 V_29 ;
int V_16 ;
F_25 ( & V_29 , V_22 , V_23 , V_27 ) ;
V_16 = F_26 ( V_25 , & V_29 ) ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
while ( ( V_27 = V_29 . V_27 ) ) {
F_27 ( V_13 , V_29 . V_22 . V_31 . V_8 , V_29 . V_23 . V_31 . V_8 ,
V_27 & V_32 ) ;
V_27 &= V_33 - 1 ;
V_16 = F_28 ( V_25 , & V_29 , V_27 ) ;
}
F_13 () ;
return V_16 ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_26 * V_22 , struct V_26 * V_23 ,
unsigned int V_27 )
{
struct V_6 * V_13 = F_5 ( F_24 ( V_25 -> V_3 ) ) ;
struct V_28 V_29 ;
int V_16 ;
F_25 ( & V_29 , V_22 , V_23 , V_27 ) ;
V_16 = F_26 ( V_25 , & V_29 ) ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
while ( ( V_27 = V_29 . V_27 ) ) {
F_30 ( V_13 , V_29 . V_22 . V_31 . V_8 , V_29 . V_23 . V_31 . V_8 ,
V_27 & V_32 ) ;
V_27 &= V_33 - 1 ;
V_16 = F_28 ( V_25 , & V_29 , V_27 ) ;
}
F_13 () ;
return V_16 ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_26 * V_22 , struct V_26 * V_23 ,
unsigned int V_27 )
{
struct V_6 * V_13 = F_5 ( F_24 ( V_25 -> V_3 ) ) ;
struct V_28 V_29 ;
int V_16 ;
F_25 ( & V_29 , V_22 , V_23 , V_27 ) ;
V_16 = F_26 ( V_25 , & V_29 ) ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
while ( ( V_27 = V_29 . V_27 ) ) {
F_32 ( V_13 , V_29 . V_22 . V_31 . V_8 , V_29 . V_23 . V_31 . V_8 ,
V_27 & V_32 , V_29 . V_34 ) ;
V_27 &= V_33 - 1 ;
V_16 = F_28 ( V_25 , & V_29 , V_27 ) ;
}
F_13 () ;
return V_16 ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_26 * V_22 , struct V_26 * V_23 ,
unsigned int V_27 )
{
struct V_6 * V_13 = F_5 ( F_24 ( V_25 -> V_3 ) ) ;
struct V_28 V_29 ;
int V_16 ;
F_25 ( & V_29 , V_22 , V_23 , V_27 ) ;
V_16 = F_26 ( V_25 , & V_29 ) ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
while ( ( V_27 = V_29 . V_27 ) ) {
F_34 ( V_13 , V_29 . V_22 . V_31 . V_8 , V_29 . V_23 . V_31 . V_8 ,
V_27 & V_32 , V_29 . V_34 ) ;
V_27 &= V_33 - 1 ;
V_16 = F_28 ( V_25 , & V_29 , V_27 ) ;
}
F_13 () ;
return V_16 ;
}
static void F_35 ( struct V_6 * V_13 ,
struct V_28 * V_29 )
{
V_4 * V_35 = V_29 -> V_34 ;
V_4 V_36 [ V_33 ] ;
V_4 * V_23 = V_29 -> V_23 . V_31 . V_8 ;
V_4 * V_22 = V_29 -> V_22 . V_31 . V_8 ;
unsigned int V_27 = V_29 -> V_27 ;
F_17 ( V_13 , V_36 , V_35 ) ;
F_36 ( V_36 , V_23 , V_27 ) ;
memcpy ( V_22 , V_36 , V_27 ) ;
F_37 ( V_35 , V_33 ) ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_26 * V_22 , struct V_26 * V_23 ,
unsigned int V_27 )
{
struct V_6 * V_13 = F_5 ( F_24 ( V_25 -> V_3 ) ) ;
struct V_28 V_29 ;
int V_16 ;
F_25 ( & V_29 , V_22 , V_23 , V_27 ) ;
V_16 = F_39 ( V_25 , & V_29 , V_33 ) ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
while ( ( V_27 = V_29 . V_27 ) >= V_33 ) {
F_40 ( V_13 , V_29 . V_22 . V_31 . V_8 , V_29 . V_23 . V_31 . V_8 ,
V_27 & V_32 , V_29 . V_34 ) ;
V_27 &= V_33 - 1 ;
V_16 = F_28 ( V_25 , & V_29 , V_27 ) ;
}
if ( V_29 . V_27 ) {
F_35 ( V_13 , & V_29 ) ;
V_16 = F_28 ( V_25 , & V_29 , 0 ) ;
}
F_13 () ;
return V_16 ;
}
static int F_41 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_1 ) ;
}
static int F_43 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_2 ) ;
}
static int F_44 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_3 ) ;
}
static int F_45 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_4 ) ;
}
static void F_46 ( void * V_13 , V_4 * V_37 , unsigned int V_27 )
{
F_27 ( V_13 , V_37 , V_37 , V_27 ) ;
}
static void F_47 ( void * V_13 , V_4 * V_37 , unsigned int V_27 )
{
F_30 ( V_13 , V_37 , V_37 , V_27 ) ;
}
static int F_48 ( struct V_10 * V_3 , const V_4 * V_38 ,
unsigned int V_39 )
{
struct V_40 * V_13 = F_3 ( V_3 ) ;
int V_16 ;
V_16 = F_8 ( V_3 , V_13 -> V_41 , V_38 ,
V_39 - V_33 ) ;
if ( V_16 )
return V_16 ;
return F_49 ( & V_13 -> V_42 , V_38 + V_39 - V_33 ) ;
}
static void F_50 ( struct V_10 * V_3 )
{
struct V_40 * V_13 = F_3 ( V_3 ) ;
F_51 ( & V_13 -> V_42 ) ;
}
static int F_52 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_40 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_44 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_48 = & V_13 -> V_42 ,
. V_49 = F_5 ( V_13 -> V_41 ) ,
. V_50 = F_46 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_53 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_54 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_40 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_44 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_48 = & V_13 -> V_42 ,
. V_49 = F_5 ( V_13 -> V_41 ) ,
. V_50 = F_47 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_53 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_55 ( struct V_10 * V_3 , const V_4 * V_38 ,
unsigned int V_39 )
{
struct V_52 * V_13 = F_3 ( V_3 ) ;
T_1 * V_14 = & V_3 -> V_15 ;
int V_16 ;
if ( V_39 % 2 ) {
* V_14 |= V_20 ;
return - V_21 ;
}
V_16 = F_8 ( V_3 , V_13 -> V_53 , V_38 , V_39 / 2 ) ;
if ( V_16 )
return V_16 ;
return F_8 ( V_3 , V_13 -> V_54 , V_38 + V_39 / 2 ,
V_39 / 2 ) ;
}
static void F_56 ( void * V_13 , V_4 * V_55 , const V_4 * V_56 )
{
F_17 ( V_13 , V_55 , V_56 ) ;
}
static void F_57 ( void * V_13 , T_3 * V_22 , const T_3 * V_23 , T_4 * V_34 )
{
F_58 ( V_13 , V_22 , V_23 , V_34 , F_59 ( F_17 ) ) ;
}
static void F_60 ( void * V_13 , T_3 * V_22 , const T_3 * V_23 , T_4 * V_34 )
{
F_58 ( V_13 , V_22 , V_23 , V_34 , F_59 ( F_20 ) ) ;
}
static void F_61 ( void * V_13 , T_3 * V_22 , const T_3 * V_23 , T_4 * V_34 )
{
F_62 ( V_13 , ( V_4 * ) V_22 , ( const V_4 * ) V_23 , true , ( V_4 * ) V_34 ) ;
}
static void F_63 ( void * V_13 , T_3 * V_22 , const T_3 * V_23 , T_4 * V_34 )
{
F_62 ( V_13 , ( V_4 * ) V_22 , ( const V_4 * ) V_23 , false , ( V_4 * ) V_34 ) ;
}
static int F_64 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
return F_65 ( & V_57 , V_25 , V_22 , V_23 , V_27 ,
F_66 ( F_56 ) ,
F_5 ( V_13 -> V_54 ) ,
F_5 ( V_13 -> V_53 ) ) ;
}
static int F_67 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
return F_65 ( & V_58 , V_25 , V_22 , V_23 , V_27 ,
F_66 ( F_56 ) ,
F_5 ( V_13 -> V_54 ) ,
F_5 ( V_13 -> V_53 ) ) ;
}
static int F_64 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_59 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_60 = F_5 ( V_13 -> V_54 ) ,
. V_61 = F_56 ,
. V_49 = F_5 ( V_13 -> V_53 ) ,
. V_50 = F_46 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_68 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_67 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_59 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_60 = F_5 ( V_13 -> V_54 ) ,
. V_61 = F_56 ,
. V_49 = F_5 ( V_13 -> V_53 ) ,
. V_50 = F_47 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_68 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_69 ( struct V_10 * V_3 )
{
struct V_62 * V_63 ;
struct V_1 * V_13 = (struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
struct V_2 * V_64 ;
struct V_1 * V_65 ;
V_63 = F_70 ( L_5 , 0 , 0 ) ;
if ( F_71 ( V_63 ) )
return F_72 ( V_63 ) ;
V_64 = F_73 ( V_63 ) ;
V_65 = F_1 ( V_64 ) ;
memcpy ( V_65 , V_13 , sizeof( * V_13 ) ) ;
V_13 -> V_63 = V_63 ;
V_3 -> V_66 . V_67 = sizeof( struct V_68 )
+ F_74 ( & V_63 -> V_69 ) ;
return 0 ;
}
static void F_75 ( struct V_10 * V_3 )
{
struct V_1 * V_13 =
(struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
if ( ! F_71 ( V_13 -> V_63 ) )
F_76 ( V_13 -> V_63 ) ;
return;
}
static void
F_77 ( struct V_70 * V_45 , int V_16 )
{
struct V_71 * V_72 = V_45 -> V_73 ;
if ( V_16 == - V_74 )
return;
V_72 -> V_16 = V_16 ;
F_78 ( & V_72 -> V_75 ) ;
}
static int
F_79 ( V_4 * V_76 , const V_4 * V_38 , unsigned int V_12 )
{
struct V_77 * V_78 ;
struct V_79 * V_45 ;
int V_51 = - V_21 ;
struct V_80 * V_81 ;
V_78 = F_80 ( L_6 , 0 , 0 ) ;
if ( F_71 ( V_78 ) )
return F_72 ( V_78 ) ;
F_81 ( V_78 , ~ 0 ) ;
V_51 = F_82 ( V_78 , V_38 , V_12 ) ;
if ( V_51 )
goto V_82;
V_51 = - V_83 ;
V_45 = F_83 ( V_78 , V_84 ) ;
if ( ! V_45 )
goto V_82;
V_81 = F_84 ( sizeof( * V_81 ) , V_84 ) ;
if ( ! V_81 )
goto V_85;
memset ( V_81 -> V_34 , 0 , sizeof( V_81 -> V_34 ) ) ;
memset ( V_76 , 0 , V_86 ) ;
F_85 ( & V_81 -> V_72 . V_75 ) ;
F_86 ( & V_81 -> V_87 , V_76 , V_86 ) ;
F_87 ( V_45 , V_78 ) ;
F_88 ( V_45 , V_30 |
V_88 ,
F_77 ,
& V_81 -> V_72 ) ;
F_89 ( V_45 , & V_81 -> V_87 ,
& V_81 -> V_87 , V_86 , V_81 -> V_34 ) ;
V_51 = F_90 ( V_45 ) ;
if ( V_51 == - V_74 || V_51 == - V_89 ) {
V_51 = F_91
( & V_81 -> V_72 . V_75 ) ;
if ( ! V_51 )
V_51 = V_81 -> V_72 . V_16 ;
}
F_92 ( V_81 ) ;
V_85:
F_93 ( V_45 ) ;
V_82:
F_94 ( V_78 ) ;
return V_51 ;
}
static int F_95 ( struct V_2 * V_90 , const V_4 * V_38 ,
unsigned int V_12 )
{
int V_51 = 0 ;
struct V_10 * V_3 = F_4 ( V_90 ) ;
struct V_1 * V_13 = F_1 ( V_90 ) ;
struct V_2 * V_64 = F_73 ( V_13 -> V_63 ) ;
struct V_1 * V_65 =
F_1 ( V_64 ) ;
V_4 * V_91 , * V_92 = NULL ;
if ( V_12 < 4 ) {
F_96 ( V_3 , V_20 ) ;
return - V_21 ;
}
V_12 -= 4 ;
if ( V_12 != V_17 ) {
F_96 ( V_3 , V_20 ) ;
return - V_21 ;
}
memcpy ( V_13 -> V_93 , V_38 + V_12 , sizeof( V_13 -> V_93 ) ) ;
if ( ( unsigned long ) ( & ( V_13 -> V_94 . V_95 [ 0 ] ) ) % V_5 )
return - V_21 ;
if ( ( unsigned long ) V_38 % V_5 ) {
V_92 = F_84 ( V_12 + V_5 , V_84 ) ;
if ( ! V_92 )
return - V_83 ;
V_91 = F_2 ( V_92 , V_5 ) ;
memcpy ( V_91 , V_38 , V_12 ) ;
V_38 = V_91 ;
}
if ( ! F_9 () )
V_51 = F_10 ( & ( V_13 -> V_94 ) ,
V_38 , V_12 ) ;
else {
F_11 () ;
V_51 = F_12 ( & ( V_13 -> V_94 ) , V_38 , V_12 ) ;
F_13 () ;
}
if ( ( unsigned long ) ( & ( V_13 -> V_76 [ 0 ] ) ) % V_5 ) {
V_51 = - V_21 ;
goto exit;
}
V_51 = F_79 ( V_13 -> V_76 , V_38 , V_12 ) ;
memcpy ( V_65 , V_13 , sizeof( * V_13 ) ) ;
exit:
F_92 ( V_92 ) ;
return V_51 ;
}
static int F_97 ( struct V_2 * V_90 ,
unsigned int V_96 )
{
struct V_1 * V_13 = F_1 ( V_90 ) ;
struct V_2 * V_64 = F_73 ( V_13 -> V_63 ) ;
switch ( V_96 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_21 ;
}
F_98 ( V_90 ) -> V_96 = V_96 ;
F_98 ( V_64 ) -> V_96 = V_96 ;
return 0 ;
}
static int F_99 ( struct V_68 * V_45 )
{
int V_51 ;
struct V_2 * V_3 = F_100 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_68 * V_97 =
(struct V_68 * ) F_101 ( V_45 ) ;
memcpy ( V_97 , V_45 , sizeof( * V_45 ) ) ;
F_102 ( V_97 , & V_13 -> V_63 -> V_69 ) ;
return F_103 ( V_97 ) ;
} else {
struct V_2 * V_64 = F_73 ( V_13 -> V_63 ) ;
F_11 () ;
V_51 = V_64 -> V_69 . V_66 . V_98 ( V_45 ) ;
F_13 () ;
return V_51 ;
}
}
static int F_104 ( struct V_68 * V_45 )
{
int V_51 ;
struct V_2 * V_3 = F_100 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_68 * V_97 =
(struct V_68 * ) F_101 ( V_45 ) ;
memcpy ( V_97 , V_45 , sizeof( * V_45 ) ) ;
F_102 ( V_97 , & V_13 -> V_63 -> V_69 ) ;
return F_105 ( V_97 ) ;
} else {
struct V_2 * V_64 = F_73 ( V_13 -> V_63 ) ;
F_11 () ;
V_51 = V_64 -> V_69 . V_66 . V_99 ( V_45 ) ;
F_13 () ;
return V_51 ;
}
}
static int F_106 ( struct V_68 * V_45 )
{
V_4 V_100 = 0 ;
V_4 * V_23 , * V_22 , * V_101 ;
T_5 V_102 = F_107 ( 1 ) ;
struct V_2 * V_3 = F_100 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_94 ) ;
unsigned long V_103 = F_108 ( V_3 ) ;
V_4 V_104 [ 16 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_104 , V_5 ) ;
struct V_105 V_106 ;
struct V_105 V_107 ;
struct V_105 V_108 ;
unsigned int V_109 ;
if ( F_109 ( V_45 -> V_110 != 8 && V_45 -> V_110 != 12 ) )
return - V_21 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ )
* ( V_34 + V_109 ) = V_13 -> V_93 [ V_109 ] ;
for ( V_109 = 0 ; V_109 < 8 ; V_109 ++ )
* ( V_34 + 4 + V_109 ) = V_45 -> V_34 [ V_109 ] ;
* ( ( T_5 * ) ( V_34 + 12 ) ) = V_102 ;
if ( ( F_110 ( V_45 -> V_23 ) ) && ( F_110 ( V_45 -> V_101 ) ) ) {
V_100 = 1 ;
F_111 ( & V_106 , V_45 -> V_23 ) ;
F_111 ( & V_107 , V_45 -> V_101 ) ;
V_23 = F_112 ( & V_106 ) ;
V_101 = F_112 ( & V_107 ) ;
V_22 = V_23 ;
if ( F_109 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_111 ( & V_108 , V_45 -> V_22 ) ;
V_22 = F_112 ( & V_108 ) ;
}
} else {
V_23 = F_84 ( V_45 -> V_111 + V_103 + V_45 -> V_110 ,
V_112 ) ;
if ( F_109 ( ! V_23 ) )
return - V_83 ;
V_101 = ( V_23 + V_45 -> V_111 + V_103 ) ;
F_113 ( V_23 , V_45 -> V_23 , 0 , V_45 -> V_111 , 0 ) ;
F_113 ( V_101 , V_45 -> V_101 , 0 ,
V_45 -> V_110 , 0 ) ;
V_22 = V_23 ;
}
F_114 ( F_5 , V_22 , V_23 , ( unsigned long ) V_45 -> V_111 , V_34 ,
V_13 -> V_76 , V_101 , ( unsigned long ) V_45 -> V_110 , V_22
+ ( ( unsigned long ) V_45 -> V_111 ) , V_103 ) ;
if ( V_100 ) {
if ( F_109 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_115 ( V_22 ) ;
F_116 ( & V_108 , 0 , 0 ) ;
}
F_115 ( V_23 ) ;
F_115 ( V_101 ) ;
F_116 ( & V_106 , 0 , 0 ) ;
F_116 ( & V_107 , 0 , 0 ) ;
} else {
F_113 ( V_22 , V_45 -> V_22 , 0 ,
V_45 -> V_111 + V_103 , 1 ) ;
F_92 ( V_23 ) ;
}
return 0 ;
}
static int F_117 ( struct V_68 * V_45 )
{
V_4 V_100 = 0 ;
V_4 * V_23 , * V_22 , * V_101 ;
unsigned long V_113 = 0 ;
T_5 V_102 = F_107 ( 1 ) ;
int V_114 = 0 ;
struct V_2 * V_3 = F_100 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_94 ) ;
unsigned long V_103 = F_108 ( V_3 ) ;
V_4 V_115 [ 32 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_115 , V_5 ) ;
V_4 * V_116 = V_34 + 16 ;
struct V_105 V_106 ;
struct V_105 V_107 ;
struct V_105 V_108 ;
unsigned int V_109 ;
if ( F_109 ( ( V_45 -> V_111 < V_103 ) ||
( V_45 -> V_110 != 8 && V_45 -> V_110 != 12 ) ) )
return - V_21 ;
V_113 = ( unsigned long ) ( V_45 -> V_111 - V_103 ) ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ )
* ( V_34 + V_109 ) = V_13 -> V_93 [ V_109 ] ;
for ( V_109 = 0 ; V_109 < 8 ; V_109 ++ )
* ( V_34 + 4 + V_109 ) = V_45 -> V_34 [ V_109 ] ;
* ( ( T_5 * ) ( V_34 + 12 ) ) = V_102 ;
if ( ( F_110 ( V_45 -> V_23 ) ) && ( F_110 ( V_45 -> V_101 ) ) ) {
V_100 = 1 ;
F_111 ( & V_106 , V_45 -> V_23 ) ;
F_111 ( & V_107 , V_45 -> V_101 ) ;
V_23 = F_112 ( & V_106 ) ;
V_101 = F_112 ( & V_107 ) ;
V_22 = V_23 ;
if ( F_109 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_111 ( & V_108 , V_45 -> V_22 ) ;
V_22 = F_112 ( & V_108 ) ;
}
} else {
V_23 = F_84 ( V_45 -> V_111 + V_45 -> V_110 , V_112 ) ;
if ( ! V_23 )
return - V_83 ;
V_101 = ( V_23 + V_45 -> V_111 + V_103 ) ;
F_113 ( V_23 , V_45 -> V_23 , 0 , V_45 -> V_111 , 0 ) ;
F_113 ( V_101 , V_45 -> V_101 , 0 ,
V_45 -> V_110 , 0 ) ;
V_22 = V_23 ;
}
F_118 ( F_5 , V_22 , V_23 , V_113 , V_34 ,
V_13 -> V_76 , V_101 , ( unsigned long ) V_45 -> V_110 ,
V_116 , V_103 ) ;
V_114 = memcmp ( V_23 + V_113 , V_116 , V_103 ) ?
- V_117 : 0 ;
if ( V_100 ) {
if ( F_109 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_115 ( V_22 ) ;
F_116 ( & V_108 , 0 , 0 ) ;
}
F_115 ( V_23 ) ;
F_115 ( V_101 ) ;
F_116 ( & V_106 , 0 , 0 ) ;
F_116 ( & V_107 , 0 , 0 ) ;
} else {
F_113 ( V_22 , V_45 -> V_22 , 0 , V_45 -> V_111 , 1 ) ;
F_92 ( V_23 ) ;
}
return V_114 ;
}
static int T_6 F_119 ( void )
{
int V_16 ;
if ( ! F_120 ( V_118 ) )
return - V_119 ;
V_16 = F_121 () ;
if ( V_16 )
return V_16 ;
return F_122 ( V_120 , F_123 ( V_120 ) ) ;
}
static void T_7 F_124 ( void )
{
F_125 ( V_120 , F_123 ( V_120 ) ) ;
F_126 () ;
}
