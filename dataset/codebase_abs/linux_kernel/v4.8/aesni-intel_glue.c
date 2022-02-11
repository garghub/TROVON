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
int V_30 ;
V_30 = F_71 ( V_20 , V_51 , V_52 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_18 ( V_20 , V_1 -> V_66 , V_51 , V_52 / 2 ) ;
if ( V_30 )
return V_30 ;
return F_18 ( V_20 , V_1 -> V_67 , V_51 + V_52 / 2 ,
V_52 / 2 ) ;
}
static void F_72 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_28 ( V_1 , V_2 , V_3 ) ;
}
static void F_73 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_74 ( V_1 , V_35 , V_36 , V_5 , F_75 ( F_28 ) ) ;
}
static void F_76 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_74 ( V_1 , V_35 , V_36 , V_5 , F_75 ( F_31 ) ) ;
}
static void F_77 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_78 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , true , ( T_1 * ) V_5 ) ;
}
static void F_79 ( void * V_1 , T_4 * V_35 , const T_4 * V_36 , T_5 * V_5 )
{
F_78 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , false , ( T_1 * ) V_5 ) ;
}
static int F_80 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
return F_81 ( & V_68 , V_38 , V_35 , V_36 , V_40 ,
F_82 ( F_72 ) ,
V_12 ( V_1 -> V_67 ) ,
V_12 ( V_1 -> V_66 ) ) ;
}
static int F_83 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
return F_81 ( & V_69 , V_38 , V_35 , V_36 , V_40 ,
F_82 ( F_72 ) ,
V_12 ( V_1 -> V_67 ) ,
V_12 ( V_1 -> V_66 ) ) ;
}
static int F_80 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_70 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_71 = V_12 ( V_1 -> V_67 ) ,
. V_72 = F_72 ,
. V_62 = V_12 ( V_1 -> V_66 ) ,
. V_63 = F_61 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_21 () ;
V_64 = F_84 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
return V_64 ;
}
static int F_83 ( struct V_37 * V_38 , struct V_39 * V_35 ,
struct V_39 * V_36 , unsigned int V_40 )
{
struct V_65 * V_1 = F_35 ( V_38 -> V_20 ) ;
T_3 V_56 [ 8 ] ;
struct V_70 V_58 = {
. V_59 = V_56 ,
. V_60 = sizeof( V_56 ) ,
. V_71 = V_12 ( V_1 -> V_67 ) ,
. V_72 = F_72 ,
. V_62 = V_12 ( V_1 -> V_66 ) ,
. V_63 = F_62 ,
} ;
int V_64 ;
V_38 -> V_28 &= ~ V_43 ;
F_21 () ;
V_64 = F_84 ( V_38 , V_35 , V_36 , V_40 , & V_58 ) ;
F_23 () ;
return V_64 ;
}
static int F_85 ( struct V_19 * V_73 )
{
struct V_74 * V_75 ;
struct V_74 * * V_1 = F_16 ( V_73 ) ;
V_75 = F_86 ( L_5 ,
V_76 ,
V_76 ) ;
if ( F_87 ( V_75 ) )
return F_88 ( V_75 ) ;
* V_1 = V_75 ;
F_89 ( V_73 , F_90 ( & V_75 -> V_77 ) ) ;
return 0 ;
}
static void F_91 ( struct V_19 * V_73 )
{
struct V_74 * * V_1 = F_16 ( V_73 ) ;
F_92 ( * V_1 ) ;
}
static int
F_93 ( T_1 * V_6 , const T_1 * V_51 , unsigned int V_27 )
{
struct V_78 * V_20 ;
int V_64 ;
V_20 = F_94 ( L_6 , 0 , 0 ) ;
if ( F_87 ( V_20 ) )
return F_88 ( V_20 ) ;
V_64 = F_95 ( V_20 , V_51 , V_27 ) ;
if ( V_64 )
goto V_79;
memset ( V_6 , 0 , V_80 ) ;
F_96 ( V_20 , V_6 , V_6 ) ;
V_79:
F_97 ( V_20 ) ;
return V_64 ;
}
static int F_98 ( struct V_19 * V_73 , const T_1 * V_51 ,
unsigned int V_27 )
{
struct V_18 * V_1 = F_13 ( V_73 ) ;
if ( V_27 < 4 ) {
F_99 ( V_73 , V_33 ) ;
return - V_34 ;
}
V_27 -= 4 ;
memcpy ( V_1 -> V_81 , V_51 + V_27 , sizeof( V_1 -> V_81 ) ) ;
return F_18 ( F_100 ( V_73 ) ,
& V_1 -> V_82 , V_51 , V_27 ) ? :
F_93 ( V_1 -> V_6 , V_51 , V_27 ) ;
}
static int F_101 ( struct V_19 * V_83 , const T_1 * V_51 ,
unsigned int V_27 )
{
struct V_74 * * V_1 = F_16 ( V_83 ) ;
struct V_74 * V_75 = * V_1 ;
return F_102 ( & V_75 -> V_77 , V_51 , V_27 ) ;
}
static int F_103 ( struct V_19 * V_73 ,
unsigned int V_84 )
{
switch ( V_84 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_104 ( struct V_19 * V_83 ,
unsigned int V_84 )
{
struct V_74 * * V_1 = F_16 ( V_83 ) ;
struct V_74 * V_75 = * V_1 ;
return F_105 ( & V_75 -> V_77 , V_84 ) ;
}
static int F_106 ( struct V_85 * V_58 )
{
T_1 V_86 = 0 ;
T_1 * V_36 , * V_35 , * V_87 ;
T_6 V_88 = F_107 ( 1 ) ;
struct V_19 * V_20 = F_108 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_82 ) ;
unsigned long V_10 = F_109 ( V_20 ) ;
T_1 V_5 [ 16 ] V_89 ( ( F_110 ( V_22 ) ) ) ;
struct V_90 V_91 ;
struct V_90 V_92 ;
unsigned int V_93 ;
if ( F_111 ( V_58 -> V_94 != 16 && V_58 -> V_94 != 20 ) )
return - V_34 ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ )
* ( V_5 + V_93 ) = V_1 -> V_81 [ V_93 ] ;
for ( V_93 = 0 ; V_93 < 8 ; V_93 ++ )
* ( V_5 + 4 + V_93 ) = V_58 -> V_5 [ V_93 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_88 ;
if ( F_112 ( V_58 -> V_36 ) &&
V_58 -> V_36 -> V_95 + V_58 -> V_36 -> V_96 <= V_97 &&
F_112 ( V_58 -> V_35 ) &&
V_58 -> V_35 -> V_95 + V_58 -> V_35 -> V_96 <= V_97 ) {
V_86 = 1 ;
F_113 ( & V_91 , V_58 -> V_36 ) ;
V_87 = F_114 ( & V_91 ) ;
V_36 = V_87 + V_58 -> V_94 ;
V_35 = V_36 ;
if ( F_111 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_113 ( & V_92 , V_58 -> V_35 ) ;
V_35 = F_114 ( & V_92 ) + V_58 -> V_94 ;
}
} else {
V_87 = F_115 ( V_58 -> V_98 + V_10 + V_58 -> V_94 ,
V_99 ) ;
if ( F_111 ( ! V_87 ) )
return - V_100 ;
F_116 ( V_87 , V_58 -> V_36 , 0 ,
V_58 -> V_94 + V_58 -> V_98 , 0 ) ;
V_36 = V_87 + V_58 -> V_94 ;
V_35 = V_36 ;
}
F_21 () ;
F_117 ( V_12 , V_35 , V_36 , V_58 -> V_98 , V_5 ,
V_1 -> V_6 , V_87 , V_58 -> V_94 - 8 ,
V_35 + V_58 -> V_98 , V_10 ) ;
F_23 () ;
if ( V_86 ) {
if ( F_111 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_118 ( V_35 - V_58 -> V_94 ) ;
F_119 ( & V_92 , V_58 -> V_35 -> V_96 ) ;
F_120 ( & V_92 , 1 , 0 ) ;
}
F_118 ( V_87 ) ;
F_119 ( & V_91 , V_58 -> V_36 -> V_96 ) ;
F_120 ( & V_91 , V_58 -> V_36 == V_58 -> V_35 , 0 ) ;
} else {
F_116 ( V_35 , V_58 -> V_35 , V_58 -> V_94 ,
V_58 -> V_98 + V_10 , 1 ) ;
F_121 ( V_87 ) ;
}
return 0 ;
}
static int F_122 ( struct V_85 * V_58 )
{
T_1 V_86 = 0 ;
T_1 * V_36 , * V_35 , * V_87 ;
unsigned long V_101 = 0 ;
T_6 V_88 = F_107 ( 1 ) ;
int V_102 = 0 ;
struct V_19 * V_20 = F_108 ( V_58 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_82 ) ;
unsigned long V_10 = F_109 ( V_20 ) ;
T_1 V_5 [ 16 ] V_89 ( ( F_110 ( V_22 ) ) ) ;
T_1 V_103 [ 16 ] ;
struct V_90 V_91 ;
struct V_90 V_92 ;
unsigned int V_93 ;
if ( F_111 ( V_58 -> V_94 != 16 && V_58 -> V_94 != 20 ) )
return - V_34 ;
V_101 = ( unsigned long ) ( V_58 -> V_98 - V_10 ) ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ )
* ( V_5 + V_93 ) = V_1 -> V_81 [ V_93 ] ;
for ( V_93 = 0 ; V_93 < 8 ; V_93 ++ )
* ( V_5 + 4 + V_93 ) = V_58 -> V_5 [ V_93 ] ;
* ( ( T_6 * ) ( V_5 + 12 ) ) = V_88 ;
if ( F_112 ( V_58 -> V_36 ) &&
V_58 -> V_36 -> V_95 + V_58 -> V_36 -> V_96 <= V_97 &&
F_112 ( V_58 -> V_35 ) &&
V_58 -> V_35 -> V_95 + V_58 -> V_35 -> V_96 <= V_97 ) {
V_86 = 1 ;
F_113 ( & V_91 , V_58 -> V_36 ) ;
V_87 = F_114 ( & V_91 ) ;
V_36 = V_87 + V_58 -> V_94 ;
V_35 = V_36 ;
if ( F_111 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_113 ( & V_92 , V_58 -> V_35 ) ;
V_35 = F_114 ( & V_92 ) + V_58 -> V_94 ;
}
} else {
V_87 = F_115 ( V_58 -> V_98 + V_58 -> V_94 , V_99 ) ;
if ( ! V_87 )
return - V_100 ;
F_116 ( V_87 , V_58 -> V_36 , 0 ,
V_58 -> V_94 + V_58 -> V_98 , 0 ) ;
V_36 = V_87 + V_58 -> V_94 ;
V_35 = V_36 ;
}
F_21 () ;
F_123 ( V_12 , V_35 , V_36 , V_101 , V_5 ,
V_1 -> V_6 , V_87 , V_58 -> V_94 - 8 ,
V_103 , V_10 ) ;
F_23 () ;
V_102 = F_124 ( V_36 + V_101 , V_103 , V_10 ) ?
- V_104 : 0 ;
if ( V_86 ) {
if ( F_111 ( V_58 -> V_36 != V_58 -> V_35 ) ) {
F_118 ( V_35 - V_58 -> V_94 ) ;
F_119 ( & V_92 , V_58 -> V_35 -> V_96 ) ;
F_120 ( & V_92 , 1 , 0 ) ;
}
F_118 ( V_87 ) ;
F_119 ( & V_91 , V_58 -> V_36 -> V_96 ) ;
F_120 ( & V_91 , V_58 -> V_36 == V_58 -> V_35 , 0 ) ;
} else {
F_116 ( V_35 , V_58 -> V_35 , V_58 -> V_94 ,
V_101 , 1 ) ;
F_121 ( V_87 ) ;
}
return V_102 ;
}
static int F_125 ( struct V_85 * V_58 )
{
struct V_19 * V_20 = F_108 ( V_58 ) ;
struct V_74 * * V_1 = F_16 ( V_20 ) ;
struct V_74 * V_75 = * V_1 ;
V_20 = & V_75 -> V_77 ;
if ( F_19 () && ( ! F_126 () ||
! F_127 ( V_75 ) ) )
V_20 = F_128 ( V_75 ) ;
F_129 ( V_58 , V_20 ) ;
return F_130 ( V_58 ) ;
}
static int F_131 ( struct V_85 * V_58 )
{
struct V_19 * V_20 = F_108 ( V_58 ) ;
struct V_74 * * V_1 = F_16 ( V_20 ) ;
struct V_74 * V_75 = * V_1 ;
V_20 = & V_75 -> V_77 ;
if ( F_19 () && ( ! F_126 () ||
! F_127 ( V_75 ) ) )
V_20 = F_128 ( V_75 ) ;
F_129 ( V_58 , V_20 ) ;
return F_132 ( V_58 ) ;
}
static int T_7 F_133 ( void )
{
int V_30 ;
if ( ! F_134 ( V_105 ) )
return - V_106 ;
#ifdef F_135
#ifdef F_136
if ( F_137 ( V_107 ) ) {
F_138 ( L_7 ) ;
F_117 = F_8 ;
F_123 = F_11 ;
} else
#endif
#ifdef F_139
if ( F_137 ( V_108 ) ) {
F_138 ( L_8 ) ;
F_117 = F_1 ;
F_123 = F_5 ;
} else
#endif
{
F_138 ( L_9 ) ;
F_117 = F_2 ;
F_123 = F_6 ;
}
F_55 = V_109 ;
#ifdef F_139
if ( F_137 ( V_108 ) ) {
F_55 = F_49 ;
F_138 ( L_10 ) ;
}
#endif
#endif
V_30 = F_140 () ;
if ( V_30 )
return V_30 ;
V_30 = F_141 ( V_110 , F_142 ( V_110 ) ) ;
if ( V_30 )
goto V_111;
V_30 = F_143 ( V_112 ,
F_142 ( V_112 ) ) ;
if ( V_30 )
goto V_113;
return V_30 ;
V_113:
F_144 ( V_110 , F_142 ( V_110 ) ) ;
V_111:
F_145 () ;
return V_30 ;
}
static void T_8 F_146 ( void )
{
F_147 ( V_112 , F_142 ( V_112 ) ) ;
F_144 ( V_110 , F_142 ( V_110 ) ) ;
F_145 () ;
}
