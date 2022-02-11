static void F_1 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_4 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
if ( V_4 < V_11 ) {
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_3 ( V_1 , V_6 ) ;
F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static void F_5 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_12 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
if ( V_12 < V_11 ) {
F_6 ( V_1 , V_2 , V_3 , V_12 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_3 ( V_1 , V_6 ) ;
F_7 ( V_1 , V_2 , V_3 , V_12 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_4 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
if ( V_4 < V_11 ) {
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else if ( V_4 < V_13 ) {
F_3 ( V_1 , V_6 ) ;
F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_9 ( V_1 , V_6 ) ;
F_10 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static void F_11 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_12 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
if ( V_12 < V_11 ) {
F_6 ( V_1 , V_2 , V_3 , V_12 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
} else if ( V_12 < V_13 ) {
F_3 ( V_1 , V_6 ) ;
F_7 ( V_1 , V_2 , V_3 , V_12 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_9 ( V_1 , V_6 ) ;
F_12 ( V_1 , V_2 , V_3 , V_12 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static inline struct
V_14 * F_13 ( struct V_15 * V_16 )
{
return
(struct V_14 * )
F_14 ( ( T_1 * )
F_15 ( F_16 ( V_16 ) ) , V_17 ) ;
}
static inline struct V_18 * F_17 ( void * V_19 )
{
unsigned long V_20 = ( unsigned long ) V_19 ;
unsigned long V_21 = V_17 ;
if ( V_21 <= F_18 () )
V_21 = 1 ;
return (struct V_18 * ) F_19 ( V_20 , V_21 ) ;
}
static int F_20 ( struct V_22 * V_16 , void * V_19 ,
const T_1 * V_23 , unsigned int V_24 )
{
struct V_18 * V_1 = F_17 ( V_19 ) ;
T_2 * V_25 = & V_16 -> V_26 ;
int V_27 ;
if ( V_24 != V_28 && V_24 != V_29 &&
V_24 != V_30 ) {
* V_25 |= V_31 ;
return - V_32 ;
}
if ( ! F_21 () )
V_27 = F_22 ( V_1 , V_23 , V_24 ) ;
else {
F_23 () ;
V_27 = F_24 ( V_1 , V_23 , V_24 ) ;
F_25 () ;
}
return V_27 ;
}
static int F_26 ( struct V_22 * V_16 , const T_1 * V_23 ,
unsigned int V_24 )
{
return F_20 ( V_16 , F_15 ( V_16 ) , V_23 , V_24 ) ;
}
static void F_27 ( struct V_22 * V_16 , T_1 * V_33 , const T_1 * V_34 )
{
struct V_18 * V_1 = F_17 ( F_15 ( V_16 ) ) ;
if ( ! F_21 () )
F_28 ( V_1 , V_33 , V_34 ) ;
else {
F_23 () ;
F_29 ( V_1 , V_33 , V_34 ) ;
F_25 () ;
}
}
static void F_30 ( struct V_22 * V_16 , T_1 * V_33 , const T_1 * V_34 )
{
struct V_18 * V_1 = F_17 ( F_15 ( V_16 ) ) ;
if ( ! F_21 () )
F_31 ( V_1 , V_33 , V_34 ) ;
else {
F_23 () ;
F_32 ( V_1 , V_33 , V_34 ) ;
F_25 () ;
}
}
static void F_33 ( struct V_22 * V_16 , T_1 * V_33 , const T_1 * V_34 )
{
struct V_18 * V_1 = F_17 ( F_15 ( V_16 ) ) ;
F_29 ( V_1 , V_33 , V_34 ) ;
}
static void F_34 ( struct V_22 * V_16 , T_1 * V_33 , const T_1 * V_34 )
{
struct V_18 * V_1 = F_17 ( F_15 ( V_16 ) ) ;
F_32 ( V_1 , V_33 , V_34 ) ;
}
static int F_35 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_38 ( V_36 , & V_40 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) ) {
F_39 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
V_38 & V_43 ) ;
V_38 &= V_44 - 1 ;
V_27 = F_40 ( V_36 , & V_40 , V_38 ) ;
}
F_25 () ;
return V_27 ;
}
static int F_41 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_38 ( V_36 , & V_40 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) ) {
F_42 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
V_38 & V_43 ) ;
V_38 &= V_44 - 1 ;
V_27 = F_40 ( V_36 , & V_40 , V_38 ) ;
}
F_25 () ;
return V_27 ;
}
static int F_43 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_38 ( V_36 , & V_40 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) ) {
F_44 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
V_38 & V_43 , V_40 . V_5 ) ;
V_38 &= V_44 - 1 ;
V_27 = F_40 ( V_36 , & V_40 , V_38 ) ;
}
F_25 () ;
return V_27 ;
}
static int F_45 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_38 ( V_36 , & V_40 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) ) {
F_46 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
V_38 & V_43 , V_40 . V_5 ) ;
V_38 &= V_44 - 1 ;
V_27 = F_40 ( V_36 , & V_40 , V_38 ) ;
}
F_25 () ;
return V_27 ;
}
static void F_47 ( struct V_18 * V_1 ,
struct V_39 * V_40 )
{
T_1 * V_45 = V_40 -> V_5 ;
T_1 V_46 [ V_44 ] ;
T_1 * V_34 = V_40 -> V_34 . V_42 . V_20 ;
T_1 * V_33 = V_40 -> V_33 . V_42 . V_20 ;
unsigned int V_38 = V_40 -> V_38 ;
F_29 ( V_1 , V_46 , V_45 ) ;
F_48 ( V_46 , V_34 , V_38 ) ;
memcpy ( V_33 , V_46 , V_38 ) ;
F_49 ( V_45 , V_44 ) ;
}
static void F_50 ( struct V_18 * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned int V_47 , T_1 * V_5 )
{
if ( V_1 -> V_48 == V_28 )
F_51 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_47 ) ;
else if ( V_1 -> V_48 == V_29 )
F_52 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_47 ) ;
else
F_53 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_47 ) ;
}
static int F_54 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_55 ( V_36 , & V_40 , V_44 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) >= V_44 ) {
F_56 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
V_38 & V_43 , V_40 . V_5 ) ;
V_38 &= V_44 - 1 ;
V_27 = F_40 ( V_36 , & V_40 , V_38 ) ;
}
if ( V_40 . V_38 ) {
F_47 ( V_1 , & V_40 ) ;
V_27 = F_40 ( V_36 , & V_40 , 0 ) ;
}
F_25 () ;
return V_27 ;
}
static int F_57 ( struct V_22 * V_16 )
{
return F_58 ( V_16 , L_1 ) ;
}
static int F_59 ( struct V_22 * V_16 )
{
return F_58 ( V_16 , L_2 ) ;
}
static int F_60 ( struct V_22 * V_16 )
{
return F_58 ( V_16 , L_3 ) ;
}
static int F_61 ( struct V_22 * V_16 )
{
return F_58 ( V_16 , L_4 ) ;
}
static void F_62 ( void * V_1 , T_1 * V_49 , unsigned int V_38 )
{
F_39 ( V_1 , V_49 , V_49 , V_38 ) ;
}
static void F_63 ( void * V_1 , T_1 * V_49 , unsigned int V_38 )
{
F_42 ( V_1 , V_49 , V_49 , V_38 ) ;
}
static int F_64 ( struct V_22 * V_16 , const T_1 * V_50 ,
unsigned int V_51 )
{
struct V_52 * V_1 = F_15 ( V_16 ) ;
int V_27 ;
V_27 = F_20 ( V_16 , V_1 -> V_53 , V_50 ,
V_51 - V_44 ) ;
if ( V_27 )
return V_27 ;
return F_65 ( & V_1 -> V_54 , V_50 + V_51 - V_44 ) ;
}
static void F_66 ( struct V_22 * V_16 )
{
struct V_52 * V_1 = F_15 ( V_16 ) ;
F_67 ( & V_1 -> V_54 ) ;
}
static int F_68 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_52 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_55 [ 8 ] ;
struct V_56 V_57 = {
. V_58 = V_55 ,
. V_59 = sizeof( V_55 ) ,
. V_60 = & V_1 -> V_54 ,
. V_61 = F_17 ( V_1 -> V_53 ) ,
. V_62 = F_62 ,
} ;
int V_63 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_63 = F_69 ( V_36 , V_33 , V_34 , V_38 , & V_57 ) ;
F_25 () ;
return V_63 ;
}
static int F_70 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_52 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_55 [ 8 ] ;
struct V_56 V_57 = {
. V_58 = V_55 ,
. V_59 = sizeof( V_55 ) ,
. V_60 = & V_1 -> V_54 ,
. V_61 = F_17 ( V_1 -> V_53 ) ,
. V_62 = F_63 ,
} ;
int V_63 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_63 = F_69 ( V_36 , V_33 , V_34 , V_38 , & V_57 ) ;
F_25 () ;
return V_63 ;
}
static int F_71 ( struct V_22 * V_16 , const T_1 * V_50 ,
unsigned int V_51 )
{
struct V_64 * V_1 = F_15 ( V_16 ) ;
T_2 * V_25 = & V_16 -> V_26 ;
int V_27 ;
if ( V_51 % 2 ) {
* V_25 |= V_31 ;
return - V_32 ;
}
V_27 = F_20 ( V_16 , V_1 -> V_65 , V_50 , V_51 / 2 ) ;
if ( V_27 )
return V_27 ;
return F_20 ( V_16 , V_1 -> V_66 , V_50 + V_51 / 2 ,
V_51 / 2 ) ;
}
static void F_72 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_29 ( V_1 , V_2 , V_3 ) ;
}
static void F_73 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_74 ( V_1 , V_33 , V_34 , V_5 , F_75 ( F_29 ) ) ;
}
static void F_76 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_74 ( V_1 , V_33 , V_34 , V_5 , F_75 ( F_32 ) ) ;
}
static void F_77 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_78 ( V_1 , ( T_1 * ) V_33 , ( const T_1 * ) V_34 , true , ( T_1 * ) V_5 ) ;
}
static void F_79 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_78 ( V_1 , ( T_1 * ) V_33 , ( const T_1 * ) V_34 , false , ( T_1 * ) V_5 ) ;
}
static int F_80 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_64 * V_1 = F_36 ( V_36 -> V_16 ) ;
return F_81 ( & V_67 , V_36 , V_33 , V_34 , V_38 ,
F_82 ( F_72 ) ,
F_17 ( V_1 -> V_66 ) ,
F_17 ( V_1 -> V_65 ) ) ;
}
static int F_83 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_64 * V_1 = F_36 ( V_36 -> V_16 ) ;
return F_81 ( & V_68 , V_36 , V_33 , V_34 , V_38 ,
F_82 ( F_72 ) ,
F_17 ( V_1 -> V_66 ) ,
F_17 ( V_1 -> V_65 ) ) ;
}
static int F_80 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_64 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_55 [ 8 ] ;
struct V_69 V_57 = {
. V_58 = V_55 ,
. V_59 = sizeof( V_55 ) ,
. V_70 = F_17 ( V_1 -> V_66 ) ,
. V_71 = F_72 ,
. V_61 = F_17 ( V_1 -> V_65 ) ,
. V_62 = F_62 ,
} ;
int V_63 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_63 = F_84 ( V_36 , V_33 , V_34 , V_38 , & V_57 ) ;
F_25 () ;
return V_63 ;
}
static int F_83 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_64 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_55 [ 8 ] ;
struct V_69 V_57 = {
. V_58 = V_55 ,
. V_59 = sizeof( V_55 ) ,
. V_70 = F_17 ( V_1 -> V_66 ) ,
. V_71 = F_72 ,
. V_61 = F_17 ( V_1 -> V_65 ) ,
. V_62 = F_63 ,
} ;
int V_63 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_63 = F_84 ( V_36 , V_33 , V_34 , V_38 , & V_57 ) ;
F_25 () ;
return V_63 ;
}
static int F_85 ( struct V_22 * V_16 )
{
struct V_72 * V_73 ;
struct V_14 * V_1 = (struct V_14 * )
F_14 ( ( T_1 * ) F_15 ( V_16 ) , V_17 ) ;
struct V_15 * V_74 ;
struct V_14 * V_75 ;
V_73 = F_86 ( L_5 , 0 , 0 ) ;
if ( F_87 ( V_73 ) )
return F_88 ( V_73 ) ;
V_74 = F_89 ( V_73 ) ;
V_75 = F_13 ( V_74 ) ;
memcpy ( V_75 , V_1 , sizeof( * V_1 ) ) ;
V_1 -> V_73 = V_73 ;
V_16 -> V_76 . V_77 = sizeof( struct V_78 )
+ F_90 ( & V_73 -> V_79 ) ;
return 0 ;
}
static void F_91 ( struct V_22 * V_16 )
{
struct V_14 * V_1 =
(struct V_14 * )
F_14 ( ( T_1 * ) F_15 ( V_16 ) , V_17 ) ;
if ( ! F_87 ( V_1 -> V_73 ) )
F_92 ( V_1 -> V_73 ) ;
return;
}
static void
F_93 ( struct V_80 * V_57 , int V_27 )
{
struct V_81 * V_82 = V_57 -> V_83 ;
if ( V_27 == - V_84 )
return;
V_82 -> V_27 = V_27 ;
F_94 ( & V_82 -> V_85 ) ;
}
static int
F_95 ( T_1 * V_6 , const T_1 * V_50 , unsigned int V_24 )
{
struct V_86 * V_87 ;
struct V_88 * V_57 ;
int V_63 = - V_32 ;
struct V_89 * V_90 ;
V_87 = F_96 ( L_6 , 0 , 0 ) ;
if ( F_87 ( V_87 ) )
return F_88 ( V_87 ) ;
F_97 ( V_87 , ~ 0 ) ;
V_63 = F_98 ( V_87 , V_50 , V_24 ) ;
if ( V_63 )
goto V_91;
V_63 = - V_92 ;
V_57 = F_99 ( V_87 , V_93 ) ;
if ( ! V_57 )
goto V_91;
V_90 = F_100 ( sizeof( * V_90 ) , V_93 ) ;
if ( ! V_90 )
goto V_94;
memset ( V_90 -> V_5 , 0 , sizeof( V_90 -> V_5 ) ) ;
memset ( V_6 , 0 , V_95 ) ;
F_101 ( & V_90 -> V_82 . V_85 ) ;
F_102 ( & V_90 -> V_96 , V_6 , V_95 ) ;
F_103 ( V_57 , V_87 ) ;
F_104 ( V_57 , V_41 |
V_97 ,
F_93 ,
& V_90 -> V_82 ) ;
F_105 ( V_57 , & V_90 -> V_96 ,
& V_90 -> V_96 , V_95 , V_90 -> V_5 ) ;
V_63 = F_106 ( V_57 ) ;
if ( V_63 == - V_84 || V_63 == - V_98 ) {
V_63 = F_107
( & V_90 -> V_82 . V_85 ) ;
if ( ! V_63 )
V_63 = V_90 -> V_82 . V_27 ;
}
F_108 ( V_90 ) ;
V_94:
F_109 ( V_57 ) ;
V_91:
F_110 ( V_87 ) ;
return V_63 ;
}
static int F_111 ( struct V_15 * V_99 , const T_1 * V_50 ,
unsigned int V_24 )
{
int V_63 = 0 ;
struct V_22 * V_16 = F_16 ( V_99 ) ;
struct V_14 * V_1 = F_13 ( V_99 ) ;
struct V_15 * V_74 = F_89 ( V_1 -> V_73 ) ;
struct V_14 * V_75 =
F_13 ( V_74 ) ;
T_1 * V_100 , * V_101 = NULL ;
if ( V_24 < 4 ) {
F_112 ( V_16 , V_31 ) ;
return - V_32 ;
}
V_24 -= 4 ;
if ( V_24 != V_28 ) {
F_112 ( V_16 , V_31 ) ;
return - V_32 ;
}
memcpy ( V_1 -> V_102 , V_50 + V_24 , sizeof( V_1 -> V_102 ) ) ;
if ( ( unsigned long ) ( & ( V_1 -> V_103 . V_104 [ 0 ] ) ) % V_17 )
return - V_32 ;
if ( ( unsigned long ) V_50 % V_17 ) {
V_101 = F_100 ( V_24 + V_17 , V_93 ) ;
if ( ! V_101 )
return - V_92 ;
V_100 = F_14 ( V_101 , V_17 ) ;
memcpy ( V_100 , V_50 , V_24 ) ;
V_50 = V_100 ;
}
if ( ! F_21 () )
V_63 = F_22 ( & ( V_1 -> V_103 ) ,
V_50 , V_24 ) ;
else {
F_23 () ;
V_63 = F_24 ( & ( V_1 -> V_103 ) , V_50 , V_24 ) ;
F_25 () ;
}
if ( ( unsigned long ) ( & ( V_1 -> V_6 [ 0 ] ) ) % V_17 ) {
V_63 = - V_32 ;
goto exit;
}
V_63 = F_95 ( V_1 -> V_6 , V_50 , V_24 ) ;
memcpy ( V_75 , V_1 , sizeof( * V_1 ) ) ;
exit:
F_108 ( V_101 ) ;
return V_63 ;
}
static int F_113 ( struct V_15 * V_99 ,
unsigned int V_105 )
{
struct V_14 * V_1 = F_13 ( V_99 ) ;
struct V_15 * V_74 = F_89 ( V_1 -> V_73 ) ;
switch ( V_105 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_32 ;
}
F_114 ( V_99 ) -> V_105 = V_105 ;
F_114 ( V_74 ) -> V_105 = V_105 ;
return 0 ;
}
static int F_115 ( struct V_78 * V_57 )
{
int V_63 ;
struct V_15 * V_16 = F_116 ( V_57 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
if ( ! F_21 () ) {
struct V_78 * V_106 =
(struct V_78 * ) F_117 ( V_57 ) ;
memcpy ( V_106 , V_57 , sizeof( * V_57 ) ) ;
F_118 ( V_106 , & V_1 -> V_73 -> V_79 ) ;
return F_119 ( V_106 ) ;
} else {
struct V_15 * V_74 = F_89 ( V_1 -> V_73 ) ;
F_23 () ;
V_63 = V_74 -> V_79 . V_76 . V_107 ( V_57 ) ;
F_25 () ;
return V_63 ;
}
}
static int F_120 ( struct V_78 * V_57 )
{
int V_63 ;
struct V_15 * V_16 = F_116 ( V_57 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
if ( ! F_21 () ) {
struct V_78 * V_106 =
(struct V_78 * ) F_117 ( V_57 ) ;
memcpy ( V_106 , V_57 , sizeof( * V_57 ) ) ;
F_118 ( V_106 , & V_1 -> V_73 -> V_79 ) ;
return F_121 ( V_106 ) ;
} else {
struct V_15 * V_74 = F_89 ( V_1 -> V_73 ) ;
F_23 () ;
V_63 = V_74 -> V_79 . V_76 . V_108 ( V_57 ) ;
F_25 () ;
return V_63 ;
}
}
static int F_122 ( struct V_78 * V_57 )
{
T_1 V_109 = 0 ;
T_1 * V_34 , * V_33 , * V_110 ;
T_6 V_111 = F_123 ( 1 ) ;
struct V_15 * V_16 = F_116 ( V_57 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
void * F_17 = & ( V_1 -> V_103 ) ;
unsigned long V_10 = F_124 ( V_16 ) ;
T_1 V_112 [ 16 + V_17 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_112 , V_17 ) ;
struct V_113 V_114 ;
struct V_113 V_115 ;
struct V_113 V_116 ;
unsigned int V_117 ;
if ( F_125 ( V_57 -> V_118 != 8 && V_57 -> V_118 != 12 ) )
return - V_32 ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ )
* ( V_5 + V_117 ) = V_1 -> V_102 [ V_117 ] ;
for ( V_117 = 0 ; V_117 < 8 ; V_117 ++ )
* ( V_5 + 4 + V_117 ) = V_57 -> V_5 [ V_117 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_111 ;
if ( ( F_126 ( V_57 -> V_34 ) ) && ( F_126 ( V_57 -> V_110 ) ) ) {
V_109 = 1 ;
F_127 ( & V_114 , V_57 -> V_34 ) ;
F_127 ( & V_115 , V_57 -> V_110 ) ;
V_34 = F_128 ( & V_114 ) ;
V_110 = F_128 ( & V_115 ) ;
V_33 = V_34 ;
if ( F_125 ( V_57 -> V_34 != V_57 -> V_33 ) ) {
F_127 ( & V_116 , V_57 -> V_33 ) ;
V_33 = F_128 ( & V_116 ) ;
}
} else {
V_34 = F_100 ( V_57 -> V_119 + V_10 + V_57 -> V_118 ,
V_120 ) ;
if ( F_125 ( ! V_34 ) )
return - V_92 ;
V_110 = ( V_34 + V_57 -> V_119 + V_10 ) ;
F_129 ( V_34 , V_57 -> V_34 , 0 , V_57 -> V_119 , 0 ) ;
F_129 ( V_110 , V_57 -> V_110 , 0 ,
V_57 -> V_118 , 0 ) ;
V_33 = V_34 ;
}
F_130 ( F_17 , V_33 , V_34 , ( unsigned long ) V_57 -> V_119 , V_5 ,
V_1 -> V_6 , V_110 , ( unsigned long ) V_57 -> V_118 , V_33
+ ( ( unsigned long ) V_57 -> V_119 ) , V_10 ) ;
if ( V_109 ) {
if ( F_125 ( V_57 -> V_34 != V_57 -> V_33 ) ) {
F_131 ( V_33 ) ;
F_132 ( & V_116 , 0 , 0 ) ;
}
F_131 ( V_34 ) ;
F_131 ( V_110 ) ;
F_132 ( & V_114 , 0 , 0 ) ;
F_132 ( & V_115 , 0 , 0 ) ;
} else {
F_129 ( V_33 , V_57 -> V_33 , 0 ,
V_57 -> V_119 + V_10 , 1 ) ;
F_108 ( V_34 ) ;
}
return 0 ;
}
static int F_133 ( struct V_78 * V_57 )
{
T_1 V_109 = 0 ;
T_1 * V_34 , * V_33 , * V_110 ;
unsigned long V_121 = 0 ;
T_6 V_111 = F_123 ( 1 ) ;
int V_122 = 0 ;
struct V_15 * V_16 = F_116 ( V_57 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
void * F_17 = & ( V_1 -> V_103 ) ;
unsigned long V_10 = F_124 ( V_16 ) ;
T_1 V_123 [ 32 + V_17 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_123 , V_17 ) ;
T_1 * V_124 = V_5 + 16 ;
struct V_113 V_114 ;
struct V_113 V_115 ;
struct V_113 V_116 ;
unsigned int V_117 ;
if ( F_125 ( ( V_57 -> V_119 < V_10 ) ||
( V_57 -> V_118 != 8 && V_57 -> V_118 != 12 ) ) )
return - V_32 ;
V_121 = ( unsigned long ) ( V_57 -> V_119 - V_10 ) ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ )
* ( V_5 + V_117 ) = V_1 -> V_102 [ V_117 ] ;
for ( V_117 = 0 ; V_117 < 8 ; V_117 ++ )
* ( V_5 + 4 + V_117 ) = V_57 -> V_5 [ V_117 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_111 ;
if ( ( F_126 ( V_57 -> V_34 ) ) && ( F_126 ( V_57 -> V_110 ) ) ) {
V_109 = 1 ;
F_127 ( & V_114 , V_57 -> V_34 ) ;
F_127 ( & V_115 , V_57 -> V_110 ) ;
V_34 = F_128 ( & V_114 ) ;
V_110 = F_128 ( & V_115 ) ;
V_33 = V_34 ;
if ( F_125 ( V_57 -> V_34 != V_57 -> V_33 ) ) {
F_127 ( & V_116 , V_57 -> V_33 ) ;
V_33 = F_128 ( & V_116 ) ;
}
} else {
V_34 = F_100 ( V_57 -> V_119 + V_57 -> V_118 , V_120 ) ;
if ( ! V_34 )
return - V_92 ;
V_110 = ( V_34 + V_57 -> V_119 + V_10 ) ;
F_129 ( V_34 , V_57 -> V_34 , 0 , V_57 -> V_119 , 0 ) ;
F_129 ( V_110 , V_57 -> V_110 , 0 ,
V_57 -> V_118 , 0 ) ;
V_33 = V_34 ;
}
F_134 ( F_17 , V_33 , V_34 , V_121 , V_5 ,
V_1 -> V_6 , V_110 , ( unsigned long ) V_57 -> V_118 ,
V_124 , V_10 ) ;
V_122 = F_135 ( V_34 + V_121 , V_124 , V_10 ) ?
- V_125 : 0 ;
if ( V_109 ) {
if ( F_125 ( V_57 -> V_34 != V_57 -> V_33 ) ) {
F_131 ( V_33 ) ;
F_132 ( & V_116 , 0 , 0 ) ;
}
F_131 ( V_34 ) ;
F_131 ( V_110 ) ;
F_132 ( & V_114 , 0 , 0 ) ;
F_132 ( & V_115 , 0 , 0 ) ;
} else {
F_129 ( V_33 , V_57 -> V_33 , 0 , V_57 -> V_119 , 1 ) ;
F_108 ( V_34 ) ;
}
return V_122 ;
}
static int T_7 F_136 ( void )
{
int V_27 ;
if ( ! F_137 ( V_126 ) )
return - V_127 ;
#ifdef F_138
#ifdef F_139
if ( F_140 ( V_128 ) ) {
F_141 ( L_7 ) ;
F_130 = F_8 ;
F_134 = F_11 ;
} else
#endif
#ifdef F_142
if ( F_140 ( V_129 ) ) {
F_141 ( L_8 ) ;
F_130 = F_1 ;
F_134 = F_5 ;
} else
#endif
{
F_141 ( L_9 ) ;
F_130 = F_2 ;
F_134 = F_6 ;
}
F_56 = V_130 ;
#ifdef F_142
if ( V_131 ) {
F_56 = F_50 ;
F_141 ( L_10 ) ;
}
#endif
#endif
V_27 = F_143 () ;
if ( V_27 )
return V_27 ;
return F_144 ( V_132 , F_145 ( V_132 ) ) ;
}
static void T_8 F_146 ( void )
{
F_147 ( V_132 , F_145 ( V_132 ) ) ;
F_148 () ;
}
