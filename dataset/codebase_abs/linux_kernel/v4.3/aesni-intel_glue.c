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
unsigned long V_21 = V_22 ;
if ( V_21 <= F_14 () )
V_21 = 1 ;
return F_15 ( F_16 ( V_20 ) , V_21 ) ;
}
static inline struct V_11 * V_12 ( void * V_23 )
{
unsigned long V_24 = ( unsigned long ) V_23 ;
unsigned long V_21 = V_22 ;
if ( V_21 <= F_14 () )
V_21 = 1 ;
return (struct V_11 * ) F_17 ( V_24 , V_21 ) ;
}
static int F_18 ( struct V_25 * V_20 , void * V_23 ,
const T_1 * V_26 , unsigned int V_27 )
{
struct V_11 * V_1 = V_12 ( V_23 ) ;
T_2 * V_28 = & V_20 -> V_29 ;
int V_30 ;
if ( V_27 != V_15 && V_27 != V_31 &&
V_27 != V_32 ) {
* V_28 |= V_33 ;
return - V_34 ;
}
if ( ! F_19 () )
V_30 = F_20 ( V_1 , V_26 , V_27 ) ;
else {
F_21 () ;
V_30 = F_22 ( V_1 , V_26 , V_27 ) ;
F_23 () ;
}
return V_30 ;
}
static int F_24 ( struct V_25 * V_20 , const T_1 * V_26 ,
unsigned int V_27 )
{
return F_18 ( V_20 , F_25 ( V_20 ) , V_26 , V_27 ) ;
}
static void F_26 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_25 ( V_20 ) ) ;
if ( ! F_19 () )
F_27 ( V_1 , V_35 , V_36 ) ;
else {
F_21 () ;
F_28 ( V_1 , V_35 , V_36 ) ;
F_23 () ;
}
}
static void F_29 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_25 ( V_20 ) ) ;
if ( ! F_19 () )
F_30 ( V_1 , V_35 , V_36 ) ;
else {
F_21 () ;
F_31 ( V_1 , V_35 , V_36 ) ;
F_23 () ;
}
}
static void F_32 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_25 ( V_20 ) ) ;
F_28 ( V_1 , V_35 , V_36 ) ;
}
static void F_33 ( struct V_25 * V_20 , T_1 * V_35 , const T_1 * V_36 )
{
struct V_11 * V_1 = V_12 ( F_25 ( V_20 ) ) ;
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
F_21 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_38 ( V_1 , V_42 . V_35 . V_44 . V_24 , V_42 . V_36 . V_44 . V_24 ,
V_40 & V_45 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_23 () ;
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
F_21 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_41 ( V_1 , V_42 . V_35 . V_44 . V_24 , V_42 . V_36 . V_44 . V_24 ,
V_40 & V_45 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_23 () ;
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
F_21 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_43 ( V_1 , V_42 . V_35 . V_44 . V_24 , V_42 . V_36 . V_44 . V_24 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_23 () ;
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
F_21 () ;
while ( ( V_40 = V_42 . V_40 ) ) {
F_45 ( V_1 , V_42 . V_35 . V_44 . V_24 , V_42 . V_36 . V_44 . V_24 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
F_23 () ;
return V_30 ;
}
static void F_46 ( struct V_11 * V_1 ,
struct V_41 * V_42 )
{
T_1 * V_47 = V_42 -> V_5 ;
T_1 V_48 [ V_46 ] ;
T_1 * V_36 = V_42 -> V_36 . V_44 . V_24 ;
T_1 * V_35 = V_42 -> V_35 . V_44 . V_24 ;
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
F_21 () ;
while ( ( V_40 = V_42 . V_40 ) >= V_46 ) {
F_55 ( V_1 , V_42 . V_35 . V_44 . V_24 , V_42 . V_36 . V_44 . V_24 ,
V_40 & V_45 , V_42 . V_5 ) ;
V_40 &= V_46 - 1 ;
V_30 = F_39 ( V_38 , & V_42 , V_40 ) ;
}
if ( V_42 . V_40 ) {
F_46 ( V_1 , & V_42 ) ;
V_30 = F_39 ( V_38 , & V_42 , 0 ) ;
}
F_23 () ;
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
struct V_53 * V_1 = F_25 ( V_20 ) ;
int V_30 ;
V_30 = F_18 ( V_20 , V_1 -> V_54 , V_51 ,
V_52 - V_46 ) ;
if ( V_30 )
return V_30 ;
return F_64 ( & V_1 -> V_55 , V_51 + V_52 - V_46 ) ;
}
static void F_65 ( struct V_25 * V_20 )
{
struct V_53 * V_1 = F_25 ( V_20 ) ;
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
F_21 () ;
V_64 = F_68 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
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
F_21 () ;
V_64 = F_68 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
return V_64 ;
}
static int F_70 ( struct V_25 * V_20 , const T_1 * V_51 ,
unsigned int V_52 )
{
struct V_65 * V_1 = F_25 ( V_20 ) ;
T_2 * V_28 = & V_20 -> V_29 ;
int V_30 ;
if ( V_52 % 2 ) {
* V_28 |= V_33 ;
return - V_34 ;
}
V_30 = F_18 ( V_20 , V_1 -> V_66 , V_51 , V_52 / 2 ) ;
if ( V_30 )
return V_30 ;
return F_18 ( V_20 , V_1 -> V_67 , V_51 + V_52 / 2 ,
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
F_21 () ;
V_64 = F_83 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
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
F_21 () ;
V_64 = F_83 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
return V_64 ;
}
static int F_84 ( struct V_19 * V_73 )
{
struct V_74 * V_75 ;
struct V_74 * * V_1 = F_16 ( V_73 ) ;
V_75 = F_85 ( L_5 ,
V_76 ,
V_76 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
* V_1 = V_75 ;
F_88 ( V_73 , F_89 ( & V_75 -> V_77 ) ) ;
return 0 ;
}
static void F_90 ( struct V_19 * V_73 )
{
struct V_74 * * V_1 = F_16 ( V_73 ) ;
F_91 ( * V_1 ) ;
}
static void
F_92 ( struct V_78 * V_58 , int V_30 )
{
struct V_79 * V_80 = V_58 -> V_81 ;
if ( V_30 == - V_82 )
return;
V_80 -> V_30 = V_30 ;
F_93 ( & V_80 -> V_83 ) ;
}
static int
F_94 ( T_1 * V_6 , const T_1 * V_51 , unsigned int V_27 )
{
struct V_84 * V_85 ;
struct V_86 * V_58 ;
int V_64 = - V_34 ;
struct V_87 * V_88 ;
V_85 = F_95 ( L_6 , 0 , 0 ) ;
if ( F_86 ( V_85 ) )
return F_87 ( V_85 ) ;
V_64 = F_96 ( V_85 , V_51 , V_27 ) ;
if ( V_64 )
goto V_89;
V_64 = - V_90 ;
V_58 = F_97 ( V_85 , V_91 ) ;
if ( ! V_58 )
goto V_89;
V_88 = F_98 ( sizeof( * V_88 ) , V_91 ) ;
if ( ! V_88 )
goto V_92;
memset ( V_88 -> V_5 , 0 , sizeof( V_88 -> V_5 ) ) ;
memset ( V_6 , 0 , V_93 ) ;
F_99 ( & V_88 -> V_80 . V_83 ) ;
F_100 ( & V_88 -> V_94 , V_6 , V_93 ) ;
F_101 ( V_58 , V_85 ) ;
F_102 ( V_58 , V_43 |
V_95 ,
F_92 ,
& V_88 -> V_80 ) ;
F_103 ( V_58 , & V_88 -> V_94 ,
& V_88 -> V_94 , V_93 , V_88 -> V_5 ) ;
V_64 = F_104 ( V_58 ) ;
if ( V_64 == - V_82 || V_64 == - V_96 ) {
V_64 = F_105
( & V_88 -> V_80 . V_83 ) ;
if ( ! V_64 )
V_64 = V_88 -> V_80 . V_30 ;
}
F_106 ( V_88 ) ;
V_92:
F_107 ( V_58 ) ;
V_89:
F_108 ( V_85 ) ;
return V_64 ;
}
static int F_109 ( struct V_19 * V_73 , const T_1 * V_51 ,
unsigned int V_27 )
{
struct V_18 * V_1 = F_13 ( V_73 ) ;
if ( V_27 < 4 ) {
F_110 ( V_73 , V_33 ) ;
return - V_34 ;
}
V_27 -= 4 ;
memcpy ( V_1 -> V_97 , V_51 + V_27 , sizeof( V_1 -> V_97 ) ) ;
return F_18 ( F_111 ( V_73 ) ,
& V_1 -> V_98 , V_51 , V_27 ) ? :
F_94 ( V_1 -> V_6 , V_51 , V_27 ) ;
}
static int F_112 ( struct V_19 * V_99 , const T_1 * V_51 ,
unsigned int V_27 )
{
struct V_74 * * V_1 = F_16 ( V_99 ) ;
struct V_74 * V_75 = * V_1 ;
return F_113 ( & V_75 -> V_77 , V_51 , V_27 ) ;
}
static int F_114 ( struct V_19 * V_73 ,
unsigned int V_100 )
{
switch ( V_100 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_115 ( struct V_19 * V_99 ,
unsigned int V_100 )
{
struct V_74 * * V_1 = F_16 ( V_99 ) ;
struct V_74 * V_75 = * V_1 ;
return F_116 ( & V_75 -> V_77 , V_100 ) ;
}
static int F_117 ( struct V_101 * V_58 )
{
T_1 V_102 = 0 ;
T_1 * V_36 , * V_35 , * V_103 ;
T_6 V_104 = F_118 ( 1 ) ;
struct V_19 * V_20 = F_119 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_98 ) ;
unsigned long V_10 = F_120 ( V_20 ) ;
T_1 V_5 [ 16 ] V_105 ( ( F_121 ( V_22 ) ) ) ;
struct V_106 V_107 ;
struct V_106 V_108 ;
unsigned int V_109 ;
if ( F_122 ( V_58 -> V_110 != 16 && V_58 -> V_110 != 20 ) )
return - V_34 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ )
* ( V_5 + V_109 ) = V_1 -> V_97 [ V_109 ] ;
for ( V_109 = 0 ; V_109 < 8 ; V_109 ++ )
* ( V_5 + 4 + V_109 ) = V_58 -> V_5 [ V_109 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_104 ;
if ( F_123 ( V_58 -> V_36 ) &&
V_58 -> V_36 -> V_111 + V_58 -> V_36 -> V_112 <= V_113 &&
F_123 ( V_58 -> V_35 ) &&
V_58 -> V_35 -> V_111 + V_58 -> V_35 -> V_112 <= V_113 ) {
V_102 = 1 ;
F_124 ( & V_107 , V_58 -> V_36 ) ;
V_103 = F_125 ( & V_107 ) ;
V_36 = V_103 + V_58 -> V_110 ;
V_35 = V_36 ;
if ( F_122 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_124 ( & V_108 , V_58 -> V_35 ) ;
V_35 = F_125 ( & V_108 ) + V_58 -> V_110 ;
}
} else {
V_103 = F_98 ( V_58 -> V_114 + V_10 + V_58 -> V_110 ,
V_115 ) ;
if ( F_122 ( ! V_103 ) )
return - V_90 ;
F_126 ( V_103 , V_58 -> V_36 , 0 ,
V_58 -> V_110 + V_58 -> V_114 , 0 ) ;
V_36 = V_103 + V_58 -> V_110 ;
V_35 = V_36 ;
}
F_21 () ;
F_127 ( V_12 , V_35 , V_36 , V_58 -> V_114 , V_5 ,
V_1 -> V_6 , V_103 , V_58 -> V_110 - 8 ,
V_35 + V_58 -> V_114 , V_10 ) ;
F_23 () ;
if ( V_102 ) {
if ( F_122 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_128 ( V_35 - V_58 -> V_110 ) ;
F_129 ( & V_108 , V_58 -> V_35 -> V_112 ) ;
F_130 ( & V_108 , 1 , 0 ) ;
}
F_128 ( V_103 ) ;
F_129 ( & V_107 , V_58 -> V_36 -> V_112 ) ;
F_130 ( & V_107 , V_58 -> V_36 == V_58 -> V_35 , 0 ) ;
} else {
F_126 ( V_35 , V_58 -> V_35 , V_58 -> V_110 ,
V_58 -> V_114 + V_10 , 1 ) ;
F_106 ( V_103 ) ;
}
return 0 ;
}
static int F_131 ( struct V_101 * V_58 )
{
T_1 V_102 = 0 ;
T_1 * V_36 , * V_35 , * V_103 ;
unsigned long V_116 = 0 ;
T_6 V_104 = F_118 ( 1 ) ;
int V_117 = 0 ;
struct V_19 * V_20 = F_119 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_98 ) ;
unsigned long V_10 = F_120 ( V_20 ) ;
T_1 V_5 [ 16 ] V_105 ( ( F_121 ( V_22 ) ) ) ;
T_1 V_118 [ 16 ] ;
struct V_106 V_107 ;
struct V_106 V_108 ;
unsigned int V_109 ;
if ( F_122 ( V_58 -> V_110 != 16 && V_58 -> V_110 != 20 ) )
return - V_34 ;
V_116 = ( unsigned long ) ( V_58 -> V_114 - V_10 ) ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ )
* ( V_5 + V_109 ) = V_1 -> V_97 [ V_109 ] ;
for ( V_109 = 0 ; V_109 < 8 ; V_109 ++ )
* ( V_5 + 4 + V_109 ) = V_58 -> V_5 [ V_109 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_104 ;
if ( F_123 ( V_58 -> V_36 ) &&
V_58 -> V_36 -> V_111 + V_58 -> V_36 -> V_112 <= V_113 &&
F_123 ( V_58 -> V_35 ) &&
V_58 -> V_35 -> V_111 + V_58 -> V_35 -> V_112 <= V_113 ) {
V_102 = 1 ;
F_124 ( & V_107 , V_58 -> V_36 ) ;
V_103 = F_125 ( & V_107 ) ;
V_36 = V_103 + V_58 -> V_110 ;
V_35 = V_36 ;
if ( F_122 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_124 ( & V_108 , V_58 -> V_35 ) ;
V_35 = F_125 ( & V_108 ) + V_58 -> V_110 ;
}
} else {
V_103 = F_98 ( V_58 -> V_114 + V_58 -> V_110 , V_115 ) ;
if ( ! V_103 )
return - V_90 ;
F_126 ( V_103 , V_58 -> V_36 , 0 ,
V_58 -> V_110 + V_58 -> V_114 , 0 ) ;
V_36 = V_103 + V_58 -> V_110 ;
V_35 = V_36 ;
}
F_21 () ;
F_132 ( V_12 , V_35 , V_36 , V_116 , V_5 ,
V_1 -> V_6 , V_103 , V_58 -> V_110 - 8 ,
V_118 , V_10 ) ;
F_23 () ;
V_117 = F_133 ( V_36 + V_116 , V_118 , V_10 ) ?
- V_119 : 0 ;
if ( V_102 ) {
if ( F_122 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_128 ( V_35 - V_58 -> V_110 ) ;
F_129 ( & V_108 , V_58 -> V_35 -> V_112 ) ;
F_130 ( & V_108 , 1 , 0 ) ;
}
F_128 ( V_103 ) ;
F_129 ( & V_107 , V_58 -> V_36 -> V_112 ) ;
F_130 ( & V_107 , V_58 -> V_36 == V_58 -> V_35 , 0 ) ;
} else {
F_126 ( V_35 , V_58 -> V_35 , V_58 -> V_110 ,
V_116 , 1 ) ;
F_106 ( V_103 ) ;
}
return V_117 ;
}
static int F_134 ( struct V_101 * V_58 )
{
struct V_19 * V_20 = F_119 ( V_58 ) ;
struct V_74 * * V_1 = F_16 ( V_20 ) ;
struct V_74 * V_75 = * V_1 ;
F_135 ( V_58 , F_19 () ?
F_136 ( V_75 ) :
& V_75 -> V_77 ) ;
return F_137 ( V_58 ) ;
}
static int F_138 ( struct V_101 * V_58 )
{
struct V_19 * V_20 = F_119 ( V_58 ) ;
struct V_74 * * V_1 = F_16 ( V_20 ) ;
struct V_74 * V_75 = * V_1 ;
F_135 ( V_58 , F_19 () ?
F_136 ( V_75 ) :
& V_75 -> V_77 ) ;
return F_139 ( V_58 ) ;
}
static int T_7 F_140 ( void )
{
int V_30 ;
if ( ! F_141 ( V_120 ) )
return - V_121 ;
#ifdef F_142
#ifdef F_143
if ( F_144 ( V_122 ) ) {
F_145 ( L_7 ) ;
F_127 = F_8 ;
F_132 = F_11 ;
} else
#endif
#ifdef F_146
if ( F_144 ( V_123 ) ) {
F_145 ( L_8 ) ;
F_127 = F_1 ;
F_132 = F_5 ;
} else
#endif
{
F_145 ( L_9 ) ;
F_127 = F_2 ;
F_132 = F_6 ;
}
F_55 = V_124 ;
#ifdef F_146
if ( V_125 ) {
F_55 = F_49 ;
F_145 ( L_10 ) ;
}
#endif
#endif
V_30 = F_147 () ;
if ( V_30 )
return V_30 ;
V_30 = F_148 ( V_126 , F_149 ( V_126 ) ) ;
if ( V_30 )
goto V_127;
V_30 = F_150 ( V_128 ,
F_149 ( V_128 ) ) ;
if ( V_30 )
goto V_129;
return V_30 ;
V_129:
F_151 ( V_126 , F_149 ( V_126 ) ) ;
V_127:
F_152 () ;
return V_30 ;
}
static void T_8 F_153 ( void )
{
F_154 ( V_128 , F_149 ( V_128 ) ) ;
F_151 ( V_126 , F_149 ( V_126 ) ) ;
F_152 () ;
}
