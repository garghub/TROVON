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
static int F_50 ( struct V_35 * V_36 ,
struct V_37 * V_33 , struct V_37 * V_34 ,
unsigned int V_38 )
{
struct V_18 * V_1 = F_17 ( F_36 ( V_36 -> V_16 ) ) ;
struct V_39 V_40 ;
int V_27 ;
F_37 ( & V_40 , V_33 , V_34 , V_38 ) ;
V_27 = F_51 ( V_36 , & V_40 , V_44 ) ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
while ( ( V_38 = V_40 . V_38 ) >= V_44 ) {
F_52 ( V_1 , V_40 . V_33 . V_42 . V_20 , V_40 . V_34 . V_42 . V_20 ,
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
static int F_53 ( struct V_22 * V_16 )
{
return F_54 ( V_16 , L_1 ) ;
}
static int F_55 ( struct V_22 * V_16 )
{
return F_54 ( V_16 , L_2 ) ;
}
static int F_56 ( struct V_22 * V_16 )
{
return F_54 ( V_16 , L_3 ) ;
}
static int F_57 ( struct V_22 * V_16 )
{
return F_54 ( V_16 , L_4 ) ;
}
static void F_58 ( void * V_1 , T_1 * V_47 , unsigned int V_38 )
{
F_39 ( V_1 , V_47 , V_47 , V_38 ) ;
}
static void F_59 ( void * V_1 , T_1 * V_47 , unsigned int V_38 )
{
F_42 ( V_1 , V_47 , V_47 , V_38 ) ;
}
static int F_60 ( struct V_22 * V_16 , const T_1 * V_48 ,
unsigned int V_49 )
{
struct V_50 * V_1 = F_15 ( V_16 ) ;
int V_27 ;
V_27 = F_20 ( V_16 , V_1 -> V_51 , V_48 ,
V_49 - V_44 ) ;
if ( V_27 )
return V_27 ;
return F_61 ( & V_1 -> V_52 , V_48 + V_49 - V_44 ) ;
}
static void F_62 ( struct V_22 * V_16 )
{
struct V_50 * V_1 = F_15 ( V_16 ) ;
F_63 ( & V_1 -> V_52 ) ;
}
static int F_64 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_50 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_53 [ 8 ] ;
struct V_54 V_55 = {
. V_56 = V_53 ,
. V_57 = sizeof( V_53 ) ,
. V_58 = & V_1 -> V_52 ,
. V_59 = F_17 ( V_1 -> V_51 ) ,
. V_60 = F_58 ,
} ;
int V_61 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_61 = F_65 ( V_36 , V_33 , V_34 , V_38 , & V_55 ) ;
F_25 () ;
return V_61 ;
}
static int F_66 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_50 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_53 [ 8 ] ;
struct V_54 V_55 = {
. V_56 = V_53 ,
. V_57 = sizeof( V_53 ) ,
. V_58 = & V_1 -> V_52 ,
. V_59 = F_17 ( V_1 -> V_51 ) ,
. V_60 = F_59 ,
} ;
int V_61 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_61 = F_65 ( V_36 , V_33 , V_34 , V_38 , & V_55 ) ;
F_25 () ;
return V_61 ;
}
static int F_67 ( struct V_22 * V_16 , const T_1 * V_48 ,
unsigned int V_49 )
{
struct V_62 * V_1 = F_15 ( V_16 ) ;
T_2 * V_25 = & V_16 -> V_26 ;
int V_27 ;
if ( V_49 % 2 ) {
* V_25 |= V_31 ;
return - V_32 ;
}
V_27 = F_20 ( V_16 , V_1 -> V_63 , V_48 , V_49 / 2 ) ;
if ( V_27 )
return V_27 ;
return F_20 ( V_16 , V_1 -> V_64 , V_48 + V_49 / 2 ,
V_49 / 2 ) ;
}
static void F_68 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_29 ( V_1 , V_2 , V_3 ) ;
}
static void F_69 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_70 ( V_1 , V_33 , V_34 , V_5 , F_71 ( F_29 ) ) ;
}
static void F_72 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_70 ( V_1 , V_33 , V_34 , V_5 , F_71 ( F_32 ) ) ;
}
static void F_73 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_74 ( V_1 , ( T_1 * ) V_33 , ( const T_1 * ) V_34 , true , ( T_1 * ) V_5 ) ;
}
static void F_75 ( void * V_1 , T_4 * V_33 , const T_4 * V_34 , T_5 * V_5 )
{
F_74 ( V_1 , ( T_1 * ) V_33 , ( const T_1 * ) V_34 , false , ( T_1 * ) V_5 ) ;
}
static int F_76 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_62 * V_1 = F_36 ( V_36 -> V_16 ) ;
return F_77 ( & V_65 , V_36 , V_33 , V_34 , V_38 ,
F_78 ( F_68 ) ,
F_17 ( V_1 -> V_64 ) ,
F_17 ( V_1 -> V_63 ) ) ;
}
static int F_79 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_62 * V_1 = F_36 ( V_36 -> V_16 ) ;
return F_77 ( & V_66 , V_36 , V_33 , V_34 , V_38 ,
F_78 ( F_68 ) ,
F_17 ( V_1 -> V_64 ) ,
F_17 ( V_1 -> V_63 ) ) ;
}
static int F_76 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_62 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_53 [ 8 ] ;
struct V_67 V_55 = {
. V_56 = V_53 ,
. V_57 = sizeof( V_53 ) ,
. V_68 = F_17 ( V_1 -> V_64 ) ,
. V_69 = F_68 ,
. V_59 = F_17 ( V_1 -> V_63 ) ,
. V_60 = F_58 ,
} ;
int V_61 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_61 = F_80 ( V_36 , V_33 , V_34 , V_38 , & V_55 ) ;
F_25 () ;
return V_61 ;
}
static int F_79 ( struct V_35 * V_36 , struct V_37 * V_33 ,
struct V_37 * V_34 , unsigned int V_38 )
{
struct V_62 * V_1 = F_36 ( V_36 -> V_16 ) ;
T_3 V_53 [ 8 ] ;
struct V_67 V_55 = {
. V_56 = V_53 ,
. V_57 = sizeof( V_53 ) ,
. V_68 = F_17 ( V_1 -> V_64 ) ,
. V_69 = F_68 ,
. V_59 = F_17 ( V_1 -> V_63 ) ,
. V_60 = F_59 ,
} ;
int V_61 ;
V_36 -> V_25 &= ~ V_41 ;
F_23 () ;
V_61 = F_80 ( V_36 , V_33 , V_34 , V_38 , & V_55 ) ;
F_25 () ;
return V_61 ;
}
static int F_81 ( struct V_22 * V_16 )
{
struct V_70 * V_71 ;
struct V_14 * V_1 = (struct V_14 * )
F_14 ( ( T_1 * ) F_15 ( V_16 ) , V_17 ) ;
struct V_15 * V_72 ;
struct V_14 * V_73 ;
V_71 = F_82 ( L_5 , 0 , 0 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_72 = F_85 ( V_71 ) ;
V_73 = F_13 ( V_72 ) ;
memcpy ( V_73 , V_1 , sizeof( * V_1 ) ) ;
V_1 -> V_71 = V_71 ;
V_16 -> V_74 . V_75 = sizeof( struct V_76 )
+ F_86 ( & V_71 -> V_77 ) ;
return 0 ;
}
static void F_87 ( struct V_22 * V_16 )
{
struct V_14 * V_1 =
(struct V_14 * )
F_14 ( ( T_1 * ) F_15 ( V_16 ) , V_17 ) ;
if ( ! F_83 ( V_1 -> V_71 ) )
F_88 ( V_1 -> V_71 ) ;
return;
}
static void
F_89 ( struct V_78 * V_55 , int V_27 )
{
struct V_79 * V_80 = V_55 -> V_81 ;
if ( V_27 == - V_82 )
return;
V_80 -> V_27 = V_27 ;
F_90 ( & V_80 -> V_83 ) ;
}
static int
F_91 ( T_1 * V_6 , const T_1 * V_48 , unsigned int V_24 )
{
struct V_84 * V_85 ;
struct V_86 * V_55 ;
int V_61 = - V_32 ;
struct V_87 * V_88 ;
V_85 = F_92 ( L_6 , 0 , 0 ) ;
if ( F_83 ( V_85 ) )
return F_84 ( V_85 ) ;
F_93 ( V_85 , ~ 0 ) ;
V_61 = F_94 ( V_85 , V_48 , V_24 ) ;
if ( V_61 )
goto V_89;
V_61 = - V_90 ;
V_55 = F_95 ( V_85 , V_91 ) ;
if ( ! V_55 )
goto V_89;
V_88 = F_96 ( sizeof( * V_88 ) , V_91 ) ;
if ( ! V_88 )
goto V_92;
memset ( V_88 -> V_5 , 0 , sizeof( V_88 -> V_5 ) ) ;
memset ( V_6 , 0 , V_93 ) ;
F_97 ( & V_88 -> V_80 . V_83 ) ;
F_98 ( & V_88 -> V_94 , V_6 , V_93 ) ;
F_99 ( V_55 , V_85 ) ;
F_100 ( V_55 , V_41 |
V_95 ,
F_89 ,
& V_88 -> V_80 ) ;
F_101 ( V_55 , & V_88 -> V_94 ,
& V_88 -> V_94 , V_93 , V_88 -> V_5 ) ;
V_61 = F_102 ( V_55 ) ;
if ( V_61 == - V_82 || V_61 == - V_96 ) {
V_61 = F_103
( & V_88 -> V_80 . V_83 ) ;
if ( ! V_61 )
V_61 = V_88 -> V_80 . V_27 ;
}
F_104 ( V_88 ) ;
V_92:
F_105 ( V_55 ) ;
V_89:
F_106 ( V_85 ) ;
return V_61 ;
}
static int F_107 ( struct V_15 * V_97 , const T_1 * V_48 ,
unsigned int V_24 )
{
int V_61 = 0 ;
struct V_22 * V_16 = F_16 ( V_97 ) ;
struct V_14 * V_1 = F_13 ( V_97 ) ;
struct V_15 * V_72 = F_85 ( V_1 -> V_71 ) ;
struct V_14 * V_73 =
F_13 ( V_72 ) ;
T_1 * V_98 , * V_99 = NULL ;
if ( V_24 < 4 ) {
F_108 ( V_16 , V_31 ) ;
return - V_32 ;
}
V_24 -= 4 ;
if ( V_24 != V_28 ) {
F_108 ( V_16 , V_31 ) ;
return - V_32 ;
}
memcpy ( V_1 -> V_100 , V_48 + V_24 , sizeof( V_1 -> V_100 ) ) ;
if ( ( unsigned long ) ( & ( V_1 -> V_101 . V_102 [ 0 ] ) ) % V_17 )
return - V_32 ;
if ( ( unsigned long ) V_48 % V_17 ) {
V_99 = F_96 ( V_24 + V_17 , V_91 ) ;
if ( ! V_99 )
return - V_90 ;
V_98 = F_14 ( V_99 , V_17 ) ;
memcpy ( V_98 , V_48 , V_24 ) ;
V_48 = V_98 ;
}
if ( ! F_21 () )
V_61 = F_22 ( & ( V_1 -> V_101 ) ,
V_48 , V_24 ) ;
else {
F_23 () ;
V_61 = F_24 ( & ( V_1 -> V_101 ) , V_48 , V_24 ) ;
F_25 () ;
}
if ( ( unsigned long ) ( & ( V_1 -> V_6 [ 0 ] ) ) % V_17 ) {
V_61 = - V_32 ;
goto exit;
}
V_61 = F_91 ( V_1 -> V_6 , V_48 , V_24 ) ;
memcpy ( V_73 , V_1 , sizeof( * V_1 ) ) ;
exit:
F_104 ( V_99 ) ;
return V_61 ;
}
static int F_109 ( struct V_15 * V_97 ,
unsigned int V_103 )
{
struct V_14 * V_1 = F_13 ( V_97 ) ;
struct V_15 * V_72 = F_85 ( V_1 -> V_71 ) ;
switch ( V_103 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_32 ;
}
F_110 ( V_97 ) -> V_103 = V_103 ;
F_110 ( V_72 ) -> V_103 = V_103 ;
return 0 ;
}
static int F_111 ( struct V_76 * V_55 )
{
int V_61 ;
struct V_15 * V_16 = F_112 ( V_55 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
if ( ! F_21 () ) {
struct V_76 * V_104 =
(struct V_76 * ) F_113 ( V_55 ) ;
memcpy ( V_104 , V_55 , sizeof( * V_55 ) ) ;
F_114 ( V_104 , & V_1 -> V_71 -> V_77 ) ;
return F_115 ( V_104 ) ;
} else {
struct V_15 * V_72 = F_85 ( V_1 -> V_71 ) ;
F_23 () ;
V_61 = V_72 -> V_77 . V_74 . V_105 ( V_55 ) ;
F_25 () ;
return V_61 ;
}
}
static int F_116 ( struct V_76 * V_55 )
{
int V_61 ;
struct V_15 * V_16 = F_112 ( V_55 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
if ( ! F_21 () ) {
struct V_76 * V_104 =
(struct V_76 * ) F_113 ( V_55 ) ;
memcpy ( V_104 , V_55 , sizeof( * V_55 ) ) ;
F_114 ( V_104 , & V_1 -> V_71 -> V_77 ) ;
return F_117 ( V_104 ) ;
} else {
struct V_15 * V_72 = F_85 ( V_1 -> V_71 ) ;
F_23 () ;
V_61 = V_72 -> V_77 . V_74 . V_106 ( V_55 ) ;
F_25 () ;
return V_61 ;
}
}
static int F_118 ( struct V_76 * V_55 )
{
T_1 V_107 = 0 ;
T_1 * V_34 , * V_33 , * V_108 ;
T_6 V_109 = F_119 ( 1 ) ;
struct V_15 * V_16 = F_112 ( V_55 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
void * F_17 = & ( V_1 -> V_101 ) ;
unsigned long V_10 = F_120 ( V_16 ) ;
T_1 V_110 [ 16 + V_17 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_110 , V_17 ) ;
struct V_111 V_112 ;
struct V_111 V_113 ;
struct V_111 V_114 ;
unsigned int V_115 ;
if ( F_121 ( V_55 -> V_116 != 8 && V_55 -> V_116 != 12 ) )
return - V_32 ;
for ( V_115 = 0 ; V_115 < 4 ; V_115 ++ )
* ( V_5 + V_115 ) = V_1 -> V_100 [ V_115 ] ;
for ( V_115 = 0 ; V_115 < 8 ; V_115 ++ )
* ( V_5 + 4 + V_115 ) = V_55 -> V_5 [ V_115 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_109 ;
if ( ( F_122 ( V_55 -> V_34 ) ) && ( F_122 ( V_55 -> V_108 ) ) ) {
V_107 = 1 ;
F_123 ( & V_112 , V_55 -> V_34 ) ;
F_123 ( & V_113 , V_55 -> V_108 ) ;
V_34 = F_124 ( & V_112 ) ;
V_108 = F_124 ( & V_113 ) ;
V_33 = V_34 ;
if ( F_121 ( V_55 -> V_34 != V_55 -> V_33 ) ) {
F_123 ( & V_114 , V_55 -> V_33 ) ;
V_33 = F_124 ( & V_114 ) ;
}
} else {
V_34 = F_96 ( V_55 -> V_117 + V_10 + V_55 -> V_116 ,
V_118 ) ;
if ( F_121 ( ! V_34 ) )
return - V_90 ;
V_108 = ( V_34 + V_55 -> V_117 + V_10 ) ;
F_125 ( V_34 , V_55 -> V_34 , 0 , V_55 -> V_117 , 0 ) ;
F_125 ( V_108 , V_55 -> V_108 , 0 ,
V_55 -> V_116 , 0 ) ;
V_33 = V_34 ;
}
F_126 ( F_17 , V_33 , V_34 , ( unsigned long ) V_55 -> V_117 , V_5 ,
V_1 -> V_6 , V_108 , ( unsigned long ) V_55 -> V_116 , V_33
+ ( ( unsigned long ) V_55 -> V_117 ) , V_10 ) ;
if ( V_107 ) {
if ( F_121 ( V_55 -> V_34 != V_55 -> V_33 ) ) {
F_127 ( V_33 ) ;
F_128 ( & V_114 , 0 , 0 ) ;
}
F_127 ( V_34 ) ;
F_127 ( V_108 ) ;
F_128 ( & V_112 , 0 , 0 ) ;
F_128 ( & V_113 , 0 , 0 ) ;
} else {
F_125 ( V_33 , V_55 -> V_33 , 0 ,
V_55 -> V_117 + V_10 , 1 ) ;
F_104 ( V_34 ) ;
}
return 0 ;
}
static int F_129 ( struct V_76 * V_55 )
{
T_1 V_107 = 0 ;
T_1 * V_34 , * V_33 , * V_108 ;
unsigned long V_119 = 0 ;
T_6 V_109 = F_119 ( 1 ) ;
int V_120 = 0 ;
struct V_15 * V_16 = F_112 ( V_55 ) ;
struct V_14 * V_1 = F_13 ( V_16 ) ;
void * F_17 = & ( V_1 -> V_101 ) ;
unsigned long V_10 = F_120 ( V_16 ) ;
T_1 V_121 [ 32 + V_17 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_121 , V_17 ) ;
T_1 * V_122 = V_5 + 16 ;
struct V_111 V_112 ;
struct V_111 V_113 ;
struct V_111 V_114 ;
unsigned int V_115 ;
if ( F_121 ( ( V_55 -> V_117 < V_10 ) ||
( V_55 -> V_116 != 8 && V_55 -> V_116 != 12 ) ) )
return - V_32 ;
V_119 = ( unsigned long ) ( V_55 -> V_117 - V_10 ) ;
for ( V_115 = 0 ; V_115 < 4 ; V_115 ++ )
* ( V_5 + V_115 ) = V_1 -> V_100 [ V_115 ] ;
for ( V_115 = 0 ; V_115 < 8 ; V_115 ++ )
* ( V_5 + 4 + V_115 ) = V_55 -> V_5 [ V_115 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_109 ;
if ( ( F_122 ( V_55 -> V_34 ) ) && ( F_122 ( V_55 -> V_108 ) ) ) {
V_107 = 1 ;
F_123 ( & V_112 , V_55 -> V_34 ) ;
F_123 ( & V_113 , V_55 -> V_108 ) ;
V_34 = F_124 ( & V_112 ) ;
V_108 = F_124 ( & V_113 ) ;
V_33 = V_34 ;
if ( F_121 ( V_55 -> V_34 != V_55 -> V_33 ) ) {
F_123 ( & V_114 , V_55 -> V_33 ) ;
V_33 = F_124 ( & V_114 ) ;
}
} else {
V_34 = F_96 ( V_55 -> V_117 + V_55 -> V_116 , V_118 ) ;
if ( ! V_34 )
return - V_90 ;
V_108 = ( V_34 + V_55 -> V_117 + V_10 ) ;
F_125 ( V_34 , V_55 -> V_34 , 0 , V_55 -> V_117 , 0 ) ;
F_125 ( V_108 , V_55 -> V_108 , 0 ,
V_55 -> V_116 , 0 ) ;
V_33 = V_34 ;
}
F_130 ( F_17 , V_33 , V_34 , V_119 , V_5 ,
V_1 -> V_6 , V_108 , ( unsigned long ) V_55 -> V_116 ,
V_122 , V_10 ) ;
V_120 = F_131 ( V_34 + V_119 , V_122 , V_10 ) ?
- V_123 : 0 ;
if ( V_107 ) {
if ( F_121 ( V_55 -> V_34 != V_55 -> V_33 ) ) {
F_127 ( V_33 ) ;
F_128 ( & V_114 , 0 , 0 ) ;
}
F_127 ( V_34 ) ;
F_127 ( V_108 ) ;
F_128 ( & V_112 , 0 , 0 ) ;
F_128 ( & V_113 , 0 , 0 ) ;
} else {
F_125 ( V_33 , V_55 -> V_33 , 0 , V_55 -> V_117 , 1 ) ;
F_104 ( V_34 ) ;
}
return V_120 ;
}
static int T_7 F_132 ( void )
{
int V_27 ;
if ( ! F_133 ( V_124 ) )
return - V_125 ;
#ifdef F_134
#ifdef F_135
if ( F_136 ( V_126 ) ) {
F_137 ( L_7 ) ;
F_126 = F_8 ;
F_130 = F_11 ;
} else
#endif
#ifdef F_138
if ( F_136 ( V_127 ) ) {
F_137 ( L_8 ) ;
F_126 = F_1 ;
F_130 = F_5 ;
} else
#endif
{
F_137 ( L_9 ) ;
F_126 = F_2 ;
F_130 = F_6 ;
}
#endif
V_27 = F_139 () ;
if ( V_27 )
return V_27 ;
return F_140 ( V_128 , F_141 ( V_128 ) ) ;
}
static void T_8 F_142 ( void )
{
F_143 ( V_128 , F_141 ( V_128 ) ) ;
F_144 () ;
}
