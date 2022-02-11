static void F_1 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_4 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_1 ;
if ( ( V_4 < V_13 ) || ( V_12 -> V_14 != V_15 ) ) {
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_3 ( V_1 , V_6 ) ;
F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static void F_5 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_16 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_1 ;
if ( ( V_16 < V_13 ) || ( V_12 -> V_14 != V_15 ) ) {
F_6 ( V_1 , V_2 , V_3 , V_16 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_3 ( V_1 , V_6 ) ;
F_7 ( V_1 , V_2 , V_3 , V_16 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned long V_4 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_1 ;
if ( ( V_4 < V_13 ) || ( V_12 -> V_14 != V_15 ) ) {
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else if ( V_4 < V_17 ) {
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
const T_1 * V_3 , unsigned long V_16 , T_1 * V_5 ,
T_1 * V_6 , const T_1 * V_7 , unsigned long V_8 ,
T_1 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_1 ;
if ( ( V_16 < V_13 ) || ( V_12 -> V_14 != V_15 ) ) {
F_6 ( V_1 , V_2 , V_3 , V_16 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
} else if ( V_16 < V_17 ) {
F_3 ( V_1 , V_6 ) ;
F_7 ( V_1 , V_2 , V_3 , V_16 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
} else {
F_9 ( V_1 , V_6 ) ;
F_12 ( V_1 , V_2 , V_3 , V_16 , V_5 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
}
static inline struct
V_18 * F_13 ( struct V_19 * V_20 )
{
return
(struct V_18 * )
F_14 ( ( T_1 * )
F_15 ( F_16 ( V_20 ) ) , V_21 ) ;
}
static inline struct V_11 * V_12 ( void * V_22 )
{
unsigned long V_23 = ( unsigned long ) V_22 ;
unsigned long V_24 = V_21 ;
if ( V_24 <= F_17 () )
V_24 = 1 ;
return (struct V_11 * ) F_18 ( V_23 , V_24 ) ;
}
static int F_19 ( struct V_25 * V_20 , void * V_22 ,
const T_1 * V_26 , unsigned int V_27 )
{
struct V_11 * V_1 = V_12 ( V_22 ) ;
T_2 * V_28 = & V_20 -> V_29 ;
int V_30 ;
if ( V_27 != V_15 && V_27 != V_31 &&
V_27 != V_32 ) {
* V_28 |= V_33 ;
return - V_34 ;
}
if ( ! F_20 () )
V_30 = F_21 ( V_1 , V_26 , V_27 ) ;
else {
F_22 () ;
V_30 = F_23 ( V_1 , V_26 , V_27 ) ;
F_24 () ;
}
return V_30 ;
}
static int F_25 ( struct V_25 * V_20 , const T_1 * V_26 ,
unsigned int V_27 )
{
return F_19 ( V_20 , F_15 ( V_20 ) , V_26 , V_27 ) ;
}
static void F_26 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_15 ( V_20 ) ) ;
if ( ! F_20 () )
F_27 ( V_1 , V_35 , V_36 ) ;
else {
F_22 () ;
F_28 ( V_1 , V_35 , V_36 ) ;
F_24 () ;
}
}
static void F_29 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_15 ( V_20 ) ) ;
if ( ! F_20 () )
F_30 ( V_1 , V_35 , V_36 ) ;
else {
F_22 () ;
F_31 ( V_1 , V_35 , V_36 ) ;
F_24 () ;
}
}
static void F_32 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_15 ( V_20 ) ) ;
F_28 ( V_1 , V_35 , V_36 ) ;
}
static void F_33 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_15 ( V_20 ) ) ;
F_31 ( V_1 , V_35 , V_36 ) ;
}
static int F_34 ( struct V_37 * V_38 ,
struct V_39 * V_35 , struct V_39 * V_36 ,
unsigned int V_40 )
{
struct V_11 * V_1 = V_12 ( F_35 ( V_38 -> V_20 ) ) ;
struct V_41 V_42 ;
int V_30 ;
F_36 ( & V_42 , V_35 , V_36 , V_40 ) ;
V_30 = F_37 ( V_38 , & V_42 ) ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_38 ( V_1 , V_42 . V_35 . V_44 . V_23 , V_42 . V_36 . V_44 . V_23 ,
V_40 & V_45 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_24 () ;
return V_30 ;
}
static int F_40 ( struct V_37 * V_38 ,
struct V_39 * V_35 , struct V_39 * V_36 ,
unsigned int V_40 )
{
struct V_11 * V_1 = V_12 ( F_35 ( V_38 -> V_20 ) ) ;
struct V_41 V_42 ;
int V_30 ;
F_36 ( & V_42 , V_35 , V_36 , V_40 ) ;
V_30 = F_37 ( V_38 , & V_42 ) ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_41 ( V_1 , V_42 . V_35 . V_44 . V_23 , V_42 . V_36 . V_44 . V_23 ,
V_40 & V_45 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_24 () ;
return V_30 ;
}
static int F_42 ( struct V_37 * V_38 ,
struct V_39 * V_35 , struct V_39 * V_36 ,
unsigned int V_40 )
{
struct V_11 * V_1 = V_12 ( F_35 ( V_38 -> V_20 ) ) ;
struct V_41 V_42 ;
int V_30 ;
F_36 ( & V_42 , V_35 , V_36 , V_40 ) ;
V_30 = F_37 ( V_38 , & V_42 ) ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_43 ( V_1 , V_42 . V_35 . V_44 . V_23 , V_42 . V_36 . V_44 . V_23 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_24 () ;
return V_30 ;
}
static int F_44 ( struct V_37 * V_38 ,
struct V_39 * V_35 , struct V_39 * V_36 ,
unsigned int V_40 )
{
struct V_11 * V_1 = V_12 ( F_35 ( V_38 -> V_20 ) ) ;
struct V_41 V_42 ;
int V_30 ;
F_36 ( & V_42 , V_35 , V_36 , V_40 ) ;
V_30 = F_37 ( V_38 , & V_42 ) ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_45 ( V_1 , V_42 . V_35 . V_44 . V_23 , V_42 . V_36 . V_44 . V_23 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_24 () ;
return V_30 ;
}
static void F_46 ( struct V_11 * V_1 ,
struct V_41 * V_42 )
{
T_1 * V_47 = V_42 -> V_5 ;
T_1 V_48 [ V_46 ] ;
T_1 * V_36 = V_42 -> V_36 . V_44 . V_23 ;
T_1 * V_35 = V_42 -> V_35 . V_44 . V_23 ;
unsigned int V_40 = V_42 -> V_40 ;
F_28 ( V_1 , V_48 , V_47 ) ;
F_47 ( V_48 , V_36 , V_40 ) ;
memcpy ( V_35 , V_48 , V_40 ) ;
F_48 ( V_47 , V_46 ) ;
}
static void F_49 ( struct V_11 * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned int V_49 , T_1 * V_5 )
{
if ( V_1 -> V_14 == V_15 )
F_50 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_49 ) ;
else if ( V_1 -> V_14 == V_31 )
F_51 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_49 ) ;
else
F_52 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_49 ) ;
}
static int F_53 ( struct V_37 * V_38 ,
struct V_39 * V_35 , struct V_39 * V_36 ,
unsigned int V_40 )
{
struct V_11 * V_1 = V_12 ( F_35 ( V_38 -> V_20 ) ) ;
struct V_41 V_42 ;
int V_30 ;
F_36 ( & V_42 , V_35 , V_36 , V_40 ) ;
V_30 = F_54 ( V_38 , & V_42 , V_46 ) ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
while ( ( V_40 = V_42 . V_40 ) >= V_46 ) {
F_55 ( V_1 , V_42 . V_35 . V_44 . V_23 , V_42 . V_36 . V_44 . V_23 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
if ( V_42 . V_40 ) {
F_46 ( V_1 , & V_42 ) ;
V_30 = F_39 ( V_38 , & V_42 , 0 ) ;
}
F_24 () ;
return V_30 ;
}
static int F_56 ( struct V_25 * V_20 )
{
return F_57 ( V_20 , L_1 ) ;
}
static int F_58 ( struct V_25 * V_20 )
{
return F_57 ( V_20 , L_2 ) ;
}
static int F_59 ( struct V_25 * V_20 )
{
return F_57 ( V_20 , L_3 ) ;
}
static int F_60 ( struct V_25 * V_20 )
{
return F_57 ( V_20 , L_4 ) ;
}
static void F_61 ( void * V_1 , T_1 * V_50 , unsigned int V_40 )
{
F_38 ( V_1 , V_50 , V_50 , V_40 ) ;
}
static void F_62 ( void * V_1 , T_1 * V_50 , unsigned int V_40 )
{
F_41 ( V_1 , V_50 , V_50 , V_40 ) ;
}
static int F_63 ( struct V_25 * V_20 , const T_1 * V_51 ,
unsigned int V_52 )
{
struct V_53 * V_1 = F_15 ( V_20 ) ;
int V_30 ;
V_30 = F_19 ( V_20 , V_1 -> V_54 , V_51 ,
V_52 - V_46 ) ;
if ( V_30 )
return V_30 ;
return F_64 ( & V_1 -> V_55 , V_51 + V_52 - V_46 ) ;
}
static void F_65 ( struct V_25 * V_20 )
{
struct V_53 * V_1 = F_15 ( V_20 ) ;
F_66 ( & V_1 -> V_55 ) ;
}
static int F_67 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_53 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_57 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_61 = & V_1 -> V_55 ,
. V_62 = V_12 ( V_1 -> V_54 ) ,
. V_63 = F_61 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
V_64 = F_68 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_24 () ;
return V_64 ;
}
static int F_69 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_53 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_57 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_61 = & V_1 -> V_55 ,
. V_62 = V_12 ( V_1 -> V_54 ) ,
. V_63 = F_62 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
V_64 = F_68 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_24 () ;
return V_64 ;
}
static int F_70 ( struct V_25 * V_20 , const T_1 * V_51 ,
unsigned int V_52 )
{
struct V_65 * V_1 = F_15 ( V_20 ) ;
T_2 * V_28 = & V_20 -> V_29 ;
int V_30 ;
if ( V_52 % 2 ) {
* V_28 |= V_33 ;
return - V_34 ;
}
V_30 = F_19 ( V_20 , V_1 -> V_66 , V_51 , V_52 / 2 ) ;
if ( V_30 )
return V_30 ;
return F_19 ( V_20 , V_1 -> V_67 , V_51 + V_52 / 2 ,
V_52 / 2 ) ;
}
static void F_71 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_28 ( V_1 , V_2 , V_3 ) ;
}
static void F_72 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_73 ( V_1 , V_35 , V_36 , V_5 , F_74 ( F_28 ) ) ;
}
static void F_75 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_73 ( V_1 , V_35 , V_36 , V_5 , F_74 ( F_31 ) ) ;
}
static void F_76 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_77 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , true , ( T_1 * ) V_5 ) ;
}
static void F_78 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_77 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , false , ( T_1 * ) V_5 ) ;
}
static int F_79 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
return F_80 ( & V_68 , V_38 , V_35 , V_36 , V_40 ,
F_81 ( F_71 ) ,
V_12 ( V_1 -> V_67 ) ,
V_12 ( V_1 -> V_66 ) ) ;
}
static int F_82 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
return F_80 ( & V_69 , V_38 , V_35 , V_36 , V_40 ,
F_81 ( F_71 ) ,
V_12 ( V_1 -> V_67 ) ,
V_12 ( V_1 -> V_66 ) ) ;
}
static int F_79 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_70 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_71 = V_12 ( V_1 -> V_67 ) ,
. V_72 = F_71 ,
. V_62 = V_12 ( V_1 -> V_66 ) ,
. V_63 = F_61 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
V_64 = F_83 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_24 () ;
return V_64 ;
}
static int F_82 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_70 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_71 = V_12 ( V_1 -> V_67 ) ,
. V_72 = F_71 ,
. V_62 = V_12 ( V_1 -> V_66 ) ,
. V_63 = F_62 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_22 () ;
V_64 = F_83 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_24 () ;
return V_64 ;
}
static int F_84 ( struct V_25 * V_20 )
{
struct V_73 * V_74 ;
struct V_18 * V_1 = (struct V_18 * )
F_14 ( ( T_1 * ) F_15 ( V_20 ) , V_21 ) ;
struct V_19 * V_75 ;
struct V_18 * V_76 ;
V_74 = F_85 ( L_5 , 0 , 0 ) ;
if ( F_86 ( V_74 ) )
return F_87 ( V_74 ) ;
V_75 = F_88 ( V_74 ) ;
V_76 = F_13 ( V_75 ) ;
memcpy ( V_76 , V_1 , sizeof( * V_1 ) ) ;
V_1 -> V_74 = V_74 ;
V_20 -> V_77 . V_78 = sizeof( struct V_79 )
+ F_89 ( & V_74 -> V_80 ) ;
return 0 ;
}
static void F_90 ( struct V_25 * V_20 )
{
struct V_18 * V_1 =
(struct V_18 * )
F_14 ( ( T_1 * ) F_15 ( V_20 ) , V_21 ) ;
if ( ! F_86 ( V_1 -> V_74 ) )
F_91 ( V_1 -> V_74 ) ;
return;
}
static void
F_92 ( struct V_81 * V_58 , int V_30 )
{
struct V_82 * V_83 = V_58 -> V_84 ;
if ( V_30 == - V_85 )
return;
V_83 -> V_30 = V_30 ;
F_93 ( & V_83 -> V_86 ) ;
}
static int
F_94 ( T_1 * V_6 , const T_1 * V_51 , unsigned int V_27 )
{
struct V_87 * V_88 ;
struct V_89 * V_58 ;
int V_64 = - V_34 ;
struct V_90 * V_91 ;
V_88 = F_95 ( L_6 , 0 , 0 ) ;
if ( F_86 ( V_88 ) )
return F_87 ( V_88 ) ;
F_96 ( V_88 , ~ 0 ) ;
V_64 = F_97 ( V_88 , V_51 , V_27 ) ;
if ( V_64 )
goto V_92;
V_64 = - V_93 ;
V_58 = F_98 ( V_88 , V_94 ) ;
if ( ! V_58 )
goto V_92;
V_91 = F_99 ( sizeof( * V_91 ) , V_94 ) ;
if ( ! V_91 )
goto V_95;
memset ( V_91 -> V_5 , 0 , sizeof( V_91 -> V_5 ) ) ;
memset ( V_6 , 0 , V_96 ) ;
F_100 ( & V_91 -> V_83 . V_86 ) ;
F_101 ( & V_91 -> V_97 , V_6 , V_96 ) ;
F_102 ( V_58 , V_88 ) ;
F_103 ( V_58 , V_43 |
V_98 ,
F_92 ,
& V_91 -> V_83 ) ;
F_104 ( V_58 , & V_91 -> V_97 ,
& V_91 -> V_97 , V_96 , V_91 -> V_5 ) ;
V_64 = F_105 ( V_58 ) ;
if ( V_64 == - V_85 || V_64 == - V_99 ) {
V_64 = F_106
( & V_91 -> V_83 . V_86 ) ;
if ( ! V_64 )
V_64 = V_91 -> V_83 . V_30 ;
}
F_107 ( V_91 ) ;
V_95:
F_108 ( V_58 ) ;
V_92:
F_109 ( V_88 ) ;
return V_64 ;
}
static int F_110 ( struct V_19 * V_100 , const T_1 * V_51 ,
unsigned int V_27 )
{
int V_64 = 0 ;
struct V_25 * V_20 = F_16 ( V_100 ) ;
struct V_18 * V_1 = F_13 ( V_100 ) ;
struct V_19 * V_75 = F_88 ( V_1 -> V_74 ) ;
struct V_18 * V_76 =
F_13 ( V_75 ) ;
T_1 * V_101 , * V_102 = NULL ;
if ( V_27 < 4 ) {
F_111 ( V_20 , V_33 ) ;
return - V_34 ;
}
V_27 -= 4 ;
if ( V_27 != V_15 && V_27 != V_31 &&
V_27 != V_32 ) {
F_111 ( V_20 , V_33 ) ;
return - V_34 ;
}
memcpy ( V_1 -> V_103 , V_51 + V_27 , sizeof( V_1 -> V_103 ) ) ;
if ( ( unsigned long ) ( & ( V_1 -> V_104 . V_105 [ 0 ] ) ) % V_21 )
return - V_34 ;
if ( ( unsigned long ) V_51 % V_21 ) {
V_102 = F_99 ( V_27 + V_21 , V_94 ) ;
if ( ! V_102 )
return - V_93 ;
V_101 = F_14 ( V_102 , V_21 ) ;
memcpy ( V_101 , V_51 , V_27 ) ;
V_51 = V_101 ;
}
if ( ! F_20 () )
V_64 = F_21 ( & ( V_1 -> V_104 ) ,
V_51 , V_27 ) ;
else {
F_22 () ;
V_64 = F_23 ( & ( V_1 -> V_104 ) , V_51 , V_27 ) ;
F_24 () ;
}
if ( ( unsigned long ) ( & ( V_1 -> V_6 [ 0 ] ) ) % V_21 ) {
V_64 = - V_34 ;
goto exit;
}
V_64 = F_94 ( V_1 -> V_6 , V_51 , V_27 ) ;
memcpy ( V_76 , V_1 , sizeof( * V_1 ) ) ;
exit:
F_107 ( V_102 ) ;
return V_64 ;
}
static int F_112 ( struct V_19 * V_100 ,
unsigned int V_106 )
{
struct V_18 * V_1 = F_13 ( V_100 ) ;
struct V_19 * V_75 = F_88 ( V_1 -> V_74 ) ;
switch ( V_106 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_34 ;
}
F_113 ( V_100 ) -> V_106 = V_106 ;
F_113 ( V_75 ) -> V_106 = V_106 ;
return 0 ;
}
static int F_114 ( struct V_79 * V_58 )
{
int V_64 ;
struct V_19 * V_20 = F_115 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
if ( ! F_20 () ) {
struct V_79 * V_107 =
(struct V_79 * ) F_116 ( V_58 ) ;
memcpy ( V_107 , V_58 , sizeof( * V_58 ) ) ;
F_117 ( V_107 , & V_1 -> V_74 -> V_80 ) ;
return F_118 ( V_107 ) ;
} else {
struct V_19 * V_75 = F_88 ( V_1 -> V_74 ) ;
F_22 () ;
V_64 = V_75 -> V_80 . V_77 . V_108 ( V_58 ) ;
F_24 () ;
return V_64 ;
}
}
static int F_119 ( struct V_79 * V_58 )
{
int V_64 ;
struct V_19 * V_20 = F_115 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
if ( ! F_20 () ) {
struct V_79 * V_107 =
(struct V_79 * ) F_116 ( V_58 ) ;
memcpy ( V_107 , V_58 , sizeof( * V_58 ) ) ;
F_117 ( V_107 , & V_1 -> V_74 -> V_80 ) ;
return F_120 ( V_107 ) ;
} else {
struct V_19 * V_75 = F_88 ( V_1 -> V_74 ) ;
F_22 () ;
V_64 = V_75 -> V_80 . V_77 . V_109 ( V_58 ) ;
F_24 () ;
return V_64 ;
}
}
static int F_121 ( struct V_79 * V_58 )
{
T_1 V_110 = 0 ;
T_1 * V_36 , * V_35 , * V_111 ;
T_6 V_112 = F_122 ( 1 ) ;
struct V_19 * V_20 = F_115 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
T_2 V_27 = V_1 -> V_104 . V_14 ;
void * V_12 = & ( V_1 -> V_104 ) ;
unsigned long V_10 = F_123 ( V_20 ) ;
T_1 V_113 [ 16 + V_21 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_113 , V_21 ) ;
struct V_114 V_115 ;
struct V_114 V_116 ;
struct V_114 V_117 ;
unsigned int V_118 ;
if ( F_124 ( V_58 -> V_119 != 8 && V_58 -> V_119 != 12 ) )
return - V_34 ;
if ( F_124 ( V_10 != 8 && V_10 != 12 && V_10 != 16 ) )
return - V_34 ;
if ( F_124 ( V_27 != V_15 &&
V_27 != V_31 &&
V_27 != V_32 ) )
return - V_34 ;
for ( V_118 = 0 ; V_118 < 4 ; V_118 ++ )
* ( V_5 + V_118 ) = V_1 -> V_103 [ V_118 ] ;
for ( V_118 = 0 ; V_118 < 8 ; V_118 ++ )
* ( V_5 + 4 + V_118 ) = V_58 -> V_5 [ V_118 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_112 ;
if ( ( F_125 ( V_58 -> V_36 ) ) && ( F_125 ( V_58 -> V_111 ) ) ) {
V_110 = 1 ;
F_126 ( & V_115 , V_58 -> V_36 ) ;
F_126 ( & V_116 , V_58 -> V_111 ) ;
V_36 = F_127 ( & V_115 ) ;
V_111 = F_127 ( & V_116 ) ;
V_35 = V_36 ;
if ( F_124 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_126 ( & V_117 , V_58 -> V_35 ) ;
V_35 = F_127 ( & V_117 ) ;
}
} else {
V_36 = F_99 ( V_58 -> V_120 + V_10 + V_58 -> V_119 ,
V_121 ) ;
if ( F_124 ( ! V_36 ) )
return - V_93 ;
V_111 = ( V_36 + V_58 -> V_120 + V_10 ) ;
F_128 ( V_36 , V_58 -> V_36 , 0 , V_58 -> V_120 , 0 ) ;
F_128 ( V_111 , V_58 -> V_111 , 0 ,
V_58 -> V_119 , 0 ) ;
V_35 = V_36 ;
}
F_129 ( V_12 , V_35 , V_36 , ( unsigned long ) V_58 -> V_120 , V_5 ,
V_1 -> V_6 , V_111 , ( unsigned long ) V_58 -> V_119 , V_35
+ ( ( unsigned long ) V_58 -> V_120 ) , V_10 ) ;
if ( V_110 ) {
if ( F_124 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_130 ( V_35 ) ;
F_131 ( & V_117 , 0 , 0 ) ;
}
F_130 ( V_36 ) ;
F_130 ( V_111 ) ;
F_131 ( & V_115 , 0 , 0 ) ;
F_131 ( & V_116 , 0 , 0 ) ;
} else {
F_128 ( V_35 , V_58 -> V_35 , 0 ,
V_58 -> V_120 + V_10 , 1 ) ;
F_107 ( V_36 ) ;
}
return 0 ;
}
static int F_132 ( struct V_79 * V_58 )
{
T_1 V_110 = 0 ;
T_1 * V_36 , * V_35 , * V_111 ;
unsigned long V_122 = 0 ;
T_6 V_112 = F_122 ( 1 ) ;
int V_123 = 0 ;
struct V_19 * V_20 = F_115 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
T_2 V_27 = V_1 -> V_104 . V_14 ;
void * V_12 = & ( V_1 -> V_104 ) ;
unsigned long V_10 = F_123 ( V_20 ) ;
T_1 V_124 [ 32 + V_21 ] ;
T_1 * V_5 = ( T_1 * ) F_14 ( ( T_1 * ) V_124 , V_21 ) ;
T_1 * V_125 = V_5 + 16 ;
struct V_114 V_115 ;
struct V_114 V_116 ;
struct V_114 V_117 ;
unsigned int V_118 ;
if ( F_124 ( ( V_58 -> V_120 < V_10 ) ||
( V_58 -> V_119 != 8 && V_58 -> V_119 != 12 ) ) )
return - V_34 ;
if ( F_124 ( V_10 != 8 && V_10 != 12 && V_10 != 16 ) )
return - V_34 ;
if ( F_124 ( V_27 != V_15 &&
V_27 != V_31 &&
V_27 != V_32 ) )
return - V_34 ;
V_122 = ( unsigned long ) ( V_58 -> V_120 - V_10 ) ;
for ( V_118 = 0 ; V_118 < 4 ; V_118 ++ )
* ( V_5 + V_118 ) = V_1 -> V_103 [ V_118 ] ;
for ( V_118 = 0 ; V_118 < 8 ; V_118 ++ )
* ( V_5 + 4 + V_118 ) = V_58 -> V_5 [ V_118 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_112 ;
if ( ( F_125 ( V_58 -> V_36 ) ) && ( F_125 ( V_58 -> V_111 ) ) ) {
V_110 = 1 ;
F_126 ( & V_115 , V_58 -> V_36 ) ;
F_126 ( & V_116 , V_58 -> V_111 ) ;
V_36 = F_127 ( & V_115 ) ;
V_111 = F_127 ( & V_116 ) ;
V_35 = V_36 ;
if ( F_124 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_126 ( & V_117 , V_58 -> V_35 ) ;
V_35 = F_127 ( & V_117 ) ;
}
} else {
V_36 = F_99 ( V_58 -> V_120 + V_58 -> V_119 , V_121 ) ;
if ( ! V_36 )
return - V_93 ;
V_111 = ( V_36 + V_58 -> V_120 ) ;
F_128 ( V_36 , V_58 -> V_36 , 0 , V_58 -> V_120 , 0 ) ;
F_128 ( V_111 , V_58 -> V_111 , 0 ,
V_58 -> V_119 , 0 ) ;
V_35 = V_36 ;
}
F_133 ( V_12 , V_35 , V_36 , V_122 , V_5 ,
V_1 -> V_6 , V_111 , ( unsigned long ) V_58 -> V_119 ,
V_125 , V_10 ) ;
V_123 = F_134 ( V_36 + V_122 , V_125 , V_10 ) ?
- V_126 : 0 ;
if ( V_110 ) {
if ( F_124 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_130 ( V_35 ) ;
F_131 ( & V_117 , 0 , 0 ) ;
}
F_130 ( V_36 ) ;
F_130 ( V_111 ) ;
F_131 ( & V_115 , 0 , 0 ) ;
F_131 ( & V_116 , 0 , 0 ) ;
} else {
F_128 ( V_35 , V_58 -> V_35 , 0 , V_122 , 1 ) ;
F_107 ( V_36 ) ;
}
return V_123 ;
}
static int T_7 F_135 ( void )
{
int V_30 ;
if ( ! F_136 ( V_127 ) )
return - V_128 ;
#ifdef F_137
#ifdef F_138
if ( F_139 ( V_129 ) ) {
F_140 ( L_7 ) ;
F_129 = F_8 ;
F_133 = F_11 ;
} else
#endif
#ifdef F_141
if ( F_139 ( V_130 ) ) {
F_140 ( L_8 ) ;
F_129 = F_1 ;
F_133 = F_5 ;
} else
#endif
{
F_140 ( L_9 ) ;
F_129 = F_2 ;
F_133 = F_6 ;
}
F_55 = V_131 ;
#ifdef F_141
if ( V_132 ) {
F_55 = F_49 ;
F_140 ( L_10 ) ;
}
#endif
#endif
V_30 = F_142 () ;
if ( V_30 )
return V_30 ;
return F_143 ( V_133 , F_144 ( V_133 ) ) ;
}
static void T_8 F_145 ( void )
{
F_146 ( V_133 , F_144 ( V_133 ) ) ;
F_147 () ;
}
