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
static inline struct
V_23 * F_17 ( struct V_19 * V_20 )
{
unsigned long V_21 = V_22 ;
if ( V_21 <= F_14 () )
V_21 = 1 ;
return F_15 ( F_16 ( V_20 ) , V_21 ) ;
}
static inline struct V_11 * V_12 ( void * V_24 )
{
unsigned long V_25 = ( unsigned long ) V_24 ;
unsigned long V_21 = V_22 ;
if ( V_21 <= F_14 () )
V_21 = 1 ;
return (struct V_11 * ) F_18 ( V_25 , V_21 ) ;
}
static int F_19 ( struct V_26 * V_20 , void * V_24 ,
const T_1 * V_27 , unsigned int V_28 )
{
struct V_11 * V_1 = V_12 ( V_24 ) ;
T_2 * V_29 = & V_20 -> V_30 ;
int V_31 ;
if ( V_28 != V_15 && V_28 != V_32 &&
V_28 != V_33 ) {
* V_29 |= V_34 ;
return - V_35 ;
}
if ( ! F_20 () )
V_31 = F_21 ( V_1 , V_27 , V_28 ) ;
else {
F_22 () ;
V_31 = F_23 ( V_1 , V_27 , V_28 ) ;
F_24 () ;
}
return V_31 ;
}
static int F_25 ( struct V_26 * V_20 , const T_1 * V_27 ,
unsigned int V_28 )
{
return F_19 ( V_20 , F_26 ( V_20 ) , V_27 , V_28 ) ;
}
static void F_27 ( struct V_26 * V_20 , T_1 * V_36 , const T_1 * V_37 )
{
struct V_11 * V_1 = V_12 ( F_26 ( V_20 ) ) ;
if ( ! F_20 () )
F_28 ( V_1 , V_36 , V_37 ) ;
else {
F_22 () ;
F_29 ( V_1 , V_36 , V_37 ) ;
F_24 () ;
}
}
static void F_30 ( struct V_26 * V_20 , T_1 * V_36 , const T_1 * V_37 )
{
struct V_11 * V_1 = V_12 ( F_26 ( V_20 ) ) ;
if ( ! F_20 () )
F_31 ( V_1 , V_36 , V_37 ) ;
else {
F_22 () ;
F_32 ( V_1 , V_36 , V_37 ) ;
F_24 () ;
}
}
static void F_33 ( struct V_26 * V_20 , T_1 * V_36 , const T_1 * V_37 )
{
struct V_11 * V_1 = V_12 ( F_26 ( V_20 ) ) ;
F_29 ( V_1 , V_36 , V_37 ) ;
}
static void F_34 ( struct V_26 * V_20 , T_1 * V_36 , const T_1 * V_37 )
{
struct V_11 * V_1 = V_12 ( F_26 ( V_20 ) ) ;
F_32 ( V_1 , V_36 , V_37 ) ;
}
static int F_35 ( struct V_38 * V_20 , const T_1 * V_39 ,
unsigned int V_40 )
{
return F_19 ( F_36 ( V_20 ) ,
F_37 ( V_20 ) , V_39 , V_40 ) ;
}
static int F_38 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_11 * V_1 = V_12 ( F_37 ( V_20 ) ) ;
struct V_43 V_44 ;
unsigned int V_45 ;
int V_31 ;
V_31 = F_40 ( & V_44 , V_42 , true ) ;
F_22 () ;
while ( ( V_45 = V_44 . V_45 ) ) {
F_41 ( V_1 , V_44 . V_36 . V_46 . V_25 , V_44 . V_37 . V_46 . V_25 ,
V_45 & V_47 ) ;
V_45 &= V_48 - 1 ;
V_31 = F_42 ( & V_44 , V_45 ) ;
}
F_24 () ;
return V_31 ;
}
static int F_43 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_11 * V_1 = V_12 ( F_37 ( V_20 ) ) ;
struct V_43 V_44 ;
unsigned int V_45 ;
int V_31 ;
V_31 = F_40 ( & V_44 , V_42 , true ) ;
F_22 () ;
while ( ( V_45 = V_44 . V_45 ) ) {
F_44 ( V_1 , V_44 . V_36 . V_46 . V_25 , V_44 . V_37 . V_46 . V_25 ,
V_45 & V_47 ) ;
V_45 &= V_48 - 1 ;
V_31 = F_42 ( & V_44 , V_45 ) ;
}
F_24 () ;
return V_31 ;
}
static int F_45 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_11 * V_1 = V_12 ( F_37 ( V_20 ) ) ;
struct V_43 V_44 ;
unsigned int V_45 ;
int V_31 ;
V_31 = F_40 ( & V_44 , V_42 , true ) ;
F_22 () ;
while ( ( V_45 = V_44 . V_45 ) ) {
F_46 ( V_1 , V_44 . V_36 . V_46 . V_25 , V_44 . V_37 . V_46 . V_25 ,
V_45 & V_47 , V_44 . V_5 ) ;
V_45 &= V_48 - 1 ;
V_31 = F_42 ( & V_44 , V_45 ) ;
}
F_24 () ;
return V_31 ;
}
static int F_47 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_11 * V_1 = V_12 ( F_37 ( V_20 ) ) ;
struct V_43 V_44 ;
unsigned int V_45 ;
int V_31 ;
V_31 = F_40 ( & V_44 , V_42 , true ) ;
F_22 () ;
while ( ( V_45 = V_44 . V_45 ) ) {
F_48 ( V_1 , V_44 . V_36 . V_46 . V_25 , V_44 . V_37 . V_46 . V_25 ,
V_45 & V_47 , V_44 . V_5 ) ;
V_45 &= V_48 - 1 ;
V_31 = F_42 ( & V_44 , V_45 ) ;
}
F_24 () ;
return V_31 ;
}
static void F_49 ( struct V_11 * V_1 ,
struct V_43 * V_44 )
{
T_1 * V_49 = V_44 -> V_5 ;
T_1 V_50 [ V_48 ] ;
T_1 * V_37 = V_44 -> V_37 . V_46 . V_25 ;
T_1 * V_36 = V_44 -> V_36 . V_46 . V_25 ;
unsigned int V_45 = V_44 -> V_45 ;
F_29 ( V_1 , V_50 , V_49 ) ;
F_50 ( V_50 , V_37 , V_45 ) ;
memcpy ( V_36 , V_50 , V_45 ) ;
F_51 ( V_49 , V_48 ) ;
}
static void F_52 ( struct V_11 * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned int V_40 , T_1 * V_5 )
{
if ( V_1 -> V_14 == V_15 )
F_53 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_40 ) ;
else if ( V_1 -> V_14 == V_32 )
F_54 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_40 ) ;
else
F_55 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_40 ) ;
}
static int F_56 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_11 * V_1 = V_12 ( F_37 ( V_20 ) ) ;
struct V_43 V_44 ;
unsigned int V_45 ;
int V_31 ;
V_31 = F_40 ( & V_44 , V_42 , true ) ;
F_22 () ;
while ( ( V_45 = V_44 . V_45 ) >= V_48 ) {
F_57 ( V_1 , V_44 . V_36 . V_46 . V_25 , V_44 . V_37 . V_46 . V_25 ,
V_45 & V_47 , V_44 . V_5 ) ;
V_45 &= V_48 - 1 ;
V_31 = F_42 ( & V_44 , V_45 ) ;
}
if ( V_44 . V_45 ) {
F_49 ( V_1 , & V_44 ) ;
V_31 = F_42 ( & V_44 , 0 ) ;
}
F_24 () ;
return V_31 ;
}
static int F_58 ( struct V_38 * V_20 , const T_1 * V_39 ,
unsigned int V_51 )
{
struct V_52 * V_1 = F_37 ( V_20 ) ;
int V_31 ;
V_31 = F_59 ( V_20 , V_39 , V_51 ) ;
if ( V_31 )
return V_31 ;
V_51 /= 2 ;
V_31 = F_19 ( F_36 ( V_20 ) , V_1 -> V_53 ,
V_39 , V_51 ) ;
if ( V_31 )
return V_31 ;
return F_19 ( F_36 ( V_20 ) , V_1 -> V_54 ,
V_39 + V_51 , V_51 ) ;
}
static void F_60 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_29 ( V_1 , V_2 , V_3 ) ;
}
static void F_61 ( void * V_1 , T_3 * V_36 , const T_3 * V_37 , T_4 * V_5 )
{
F_62 ( V_1 , V_36 , V_37 , V_5 , F_63 ( F_29 ) ) ;
}
static void F_64 ( void * V_1 , T_3 * V_36 , const T_3 * V_37 , T_4 * V_5 )
{
F_62 ( V_1 , V_36 , V_37 , V_5 , F_63 ( F_32 ) ) ;
}
static void F_65 ( void * V_1 , T_3 * V_36 , const T_3 * V_37 , T_4 * V_5 )
{
F_66 ( V_1 , ( T_1 * ) V_36 , ( const T_1 * ) V_37 , true , ( T_1 * ) V_5 ) ;
}
static void F_67 ( void * V_1 , T_3 * V_36 , const T_3 * V_37 , T_4 * V_5 )
{
F_66 ( V_1 , ( T_1 * ) V_36 , ( const T_1 * ) V_37 , false , ( T_1 * ) V_5 ) ;
}
static int F_68 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_52 * V_1 = F_37 ( V_20 ) ;
return F_69 ( & V_55 , V_42 ,
F_70 ( F_60 ) ,
V_12 ( V_1 -> V_54 ) ,
V_12 ( V_1 -> V_53 ) ) ;
}
static int F_71 ( struct V_41 * V_42 )
{
struct V_38 * V_20 = F_39 ( V_42 ) ;
struct V_52 * V_1 = F_37 ( V_20 ) ;
return F_69 ( & V_56 , V_42 ,
F_70 ( F_60 ) ,
V_12 ( V_1 -> V_54 ) ,
V_12 ( V_1 -> V_53 ) ) ;
}
static int F_72 ( struct V_19 * V_57 )
{
struct V_58 * V_59 ;
struct V_58 * * V_1 = F_16 ( V_57 ) ;
V_59 = F_73 ( L_1 ,
V_60 ,
V_60 ) ;
if ( F_74 ( V_59 ) )
return F_75 ( V_59 ) ;
* V_1 = V_59 ;
F_76 ( V_57 , F_77 ( & V_59 -> V_61 ) ) ;
return 0 ;
}
static void F_78 ( struct V_19 * V_57 )
{
struct V_58 * * V_1 = F_16 ( V_57 ) ;
F_79 ( * V_1 ) ;
}
static int
F_80 ( T_1 * V_6 , const T_1 * V_39 , unsigned int V_28 )
{
struct V_62 * V_20 ;
int V_63 ;
V_20 = F_81 ( L_2 , 0 , 0 ) ;
if ( F_74 ( V_20 ) )
return F_75 ( V_20 ) ;
V_63 = F_82 ( V_20 , V_39 , V_28 ) ;
if ( V_63 )
goto V_64;
memset ( V_6 , 0 , V_65 ) ;
F_83 ( V_20 , V_6 , V_6 ) ;
V_64:
F_84 ( V_20 ) ;
return V_63 ;
}
static int F_85 ( struct V_19 * V_57 , const T_1 * V_39 ,
unsigned int V_28 )
{
struct V_18 * V_1 = F_13 ( V_57 ) ;
if ( V_28 < 4 ) {
F_86 ( V_57 , V_34 ) ;
return - V_35 ;
}
V_28 -= 4 ;
memcpy ( V_1 -> V_66 , V_39 + V_28 , sizeof( V_1 -> V_66 ) ) ;
return F_19 ( F_87 ( V_57 ) ,
& V_1 -> V_67 , V_39 , V_28 ) ? :
F_80 ( V_1 -> V_6 , V_39 , V_28 ) ;
}
static int F_88 ( struct V_19 * V_68 , const T_1 * V_39 ,
unsigned int V_28 )
{
struct V_58 * * V_1 = F_16 ( V_68 ) ;
struct V_58 * V_59 = * V_1 ;
return F_89 ( & V_59 -> V_61 , V_39 , V_28 ) ;
}
static int F_90 ( struct V_19 * V_57 ,
unsigned int V_69 )
{
switch ( V_69 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_91 ( struct V_19 * V_68 ,
unsigned int V_69 )
{
struct V_58 * * V_1 = F_16 ( V_68 ) ;
struct V_58 * V_59 = * V_1 ;
return F_92 ( & V_59 -> V_61 , V_69 ) ;
}
static int F_93 ( struct V_19 * V_20 ,
unsigned int V_69 )
{
switch ( V_69 ) {
case 4 :
case 8 :
case 12 :
case 13 :
case 14 :
case 15 :
case 16 :
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_94 ( struct V_70 * V_42 , unsigned int V_71 ,
T_1 * V_6 , T_1 * V_5 , void * V_12 )
{
T_1 V_72 = 0 ;
T_1 * V_37 , * V_36 , * V_73 ;
struct V_19 * V_20 = F_95 ( V_42 ) ;
unsigned long V_10 = F_96 ( V_20 ) ;
struct V_74 V_75 ;
struct V_74 V_76 = {} ;
if ( F_97 ( V_42 -> V_37 ) &&
( ! F_98 ( F_99 ( V_42 -> V_37 ) ) ||
V_42 -> V_37 -> V_77 + V_42 -> V_37 -> V_78 <= V_79 ) &&
F_97 ( V_42 -> V_36 ) &&
( ! F_98 ( F_99 ( V_42 -> V_36 ) ) ||
V_42 -> V_36 -> V_77 + V_42 -> V_36 -> V_78 <= V_79 ) ) {
V_72 = 1 ;
F_100 ( & V_75 , V_42 -> V_37 ) ;
V_73 = F_101 ( & V_75 ) ;
V_37 = V_73 + V_42 -> V_71 ;
V_36 = V_37 ;
if ( F_102 ( V_42 -> V_37 != V_42 -> V_36 ) ) {
F_100 ( & V_76 , V_42 -> V_36 ) ;
V_36 = F_101 ( & V_76 ) + V_42 -> V_71 ;
}
} else {
V_73 = F_103 ( V_42 -> V_80 + V_10 + V_42 -> V_71 ,
V_81 ) ;
if ( F_102 ( ! V_73 ) )
return - V_82 ;
F_104 ( V_73 , V_42 -> V_37 , 0 ,
V_42 -> V_71 + V_42 -> V_80 , 0 ) ;
V_37 = V_73 + V_42 -> V_71 ;
V_36 = V_37 ;
}
F_22 () ;
F_105 ( V_12 , V_36 , V_37 , V_42 -> V_80 , V_5 ,
V_6 , V_73 , V_71 ,
V_36 + V_42 -> V_80 , V_10 ) ;
F_24 () ;
if ( V_72 ) {
if ( F_102 ( V_42 -> V_37 != V_42 -> V_36 ) ) {
F_106 ( V_36 - V_42 -> V_71 ) ;
F_107 ( & V_76 , V_42 -> V_36 -> V_78 ) ;
F_108 ( & V_76 , 1 , 0 ) ;
}
F_106 ( V_73 ) ;
F_107 ( & V_75 , V_42 -> V_37 -> V_78 ) ;
F_108 ( & V_75 , V_42 -> V_37 == V_42 -> V_36 , 0 ) ;
} else {
F_104 ( V_36 , V_42 -> V_36 , V_42 -> V_71 ,
V_42 -> V_80 + V_10 , 1 ) ;
F_109 ( V_73 ) ;
}
return 0 ;
}
static int F_110 ( struct V_70 * V_42 , unsigned int V_71 ,
T_1 * V_6 , T_1 * V_5 , void * V_12 )
{
T_1 V_72 = 0 ;
T_1 * V_37 , * V_36 , * V_73 ;
unsigned long V_83 = 0 ;
struct V_19 * V_20 = F_95 ( V_42 ) ;
unsigned long V_10 = F_96 ( V_20 ) ;
T_1 V_84 [ 16 ] ;
struct V_74 V_75 ;
struct V_74 V_76 = {} ;
int V_85 = 0 ;
V_83 = ( unsigned long ) ( V_42 -> V_80 - V_10 ) ;
if ( F_97 ( V_42 -> V_37 ) &&
( ! F_98 ( F_99 ( V_42 -> V_37 ) ) ||
V_42 -> V_37 -> V_77 + V_42 -> V_37 -> V_78 <= V_79 ) &&
F_97 ( V_42 -> V_36 ) &&
( ! F_98 ( F_99 ( V_42 -> V_36 ) ) ||
V_42 -> V_36 -> V_77 + V_42 -> V_36 -> V_78 <= V_79 ) ) {
V_72 = 1 ;
F_100 ( & V_75 , V_42 -> V_37 ) ;
V_73 = F_101 ( & V_75 ) ;
V_37 = V_73 + V_42 -> V_71 ;
V_36 = V_37 ;
if ( F_102 ( V_42 -> V_37 != V_42 -> V_36 ) ) {
F_100 ( & V_76 , V_42 -> V_36 ) ;
V_36 = F_101 ( & V_76 ) + V_42 -> V_71 ;
}
} else {
V_73 = F_103 ( V_42 -> V_80 + V_42 -> V_71 , V_81 ) ;
if ( ! V_73 )
return - V_82 ;
F_104 ( V_73 , V_42 -> V_37 , 0 ,
V_42 -> V_71 + V_42 -> V_80 , 0 ) ;
V_37 = V_73 + V_42 -> V_71 ;
V_36 = V_37 ;
}
F_22 () ;
F_111 ( V_12 , V_36 , V_37 , V_83 , V_5 ,
V_6 , V_73 , V_71 ,
V_84 , V_10 ) ;
F_24 () ;
V_85 = F_112 ( V_37 + V_83 , V_84 , V_10 ) ?
- V_86 : 0 ;
if ( V_72 ) {
if ( F_102 ( V_42 -> V_37 != V_42 -> V_36 ) ) {
F_106 ( V_36 - V_42 -> V_71 ) ;
F_107 ( & V_76 , V_42 -> V_36 -> V_78 ) ;
F_108 ( & V_76 , 1 , 0 ) ;
}
F_106 ( V_73 ) ;
F_107 ( & V_75 , V_42 -> V_37 -> V_78 ) ;
F_108 ( & V_75 , V_42 -> V_37 == V_42 -> V_36 , 0 ) ;
} else {
F_104 ( V_36 , V_42 -> V_36 , V_42 -> V_71 ,
V_83 , 1 ) ;
F_109 ( V_73 ) ;
}
return V_85 ;
}
static int F_113 ( struct V_70 * V_42 )
{
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_67 ) ;
T_1 V_5 [ 16 ] V_87 ( ( F_114 ( V_22 ) ) ) ;
unsigned int V_88 ;
T_5 V_89 = F_115 ( 1 ) ;
if ( F_102 ( V_42 -> V_71 != 16 && V_42 -> V_71 != 20 ) )
return - V_35 ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ )
* ( V_5 + V_88 ) = V_1 -> V_66 [ V_88 ] ;
for ( V_88 = 0 ; V_88 < 8 ; V_88 ++ )
* ( V_5 + 4 + V_88 ) = V_42 -> V_5 [ V_88 ] ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_89 ;
return F_94 ( V_42 , V_42 -> V_71 - 8 , V_1 -> V_6 , V_5 ,
V_12 ) ;
}
static int F_116 ( struct V_70 * V_42 )
{
T_5 V_89 = F_115 ( 1 ) ;
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_67 ) ;
T_1 V_5 [ 16 ] V_87 ( ( F_114 ( V_22 ) ) ) ;
unsigned int V_88 ;
if ( F_102 ( V_42 -> V_71 != 16 && V_42 -> V_71 != 20 ) )
return - V_35 ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ )
* ( V_5 + V_88 ) = V_1 -> V_66 [ V_88 ] ;
for ( V_88 = 0 ; V_88 < 8 ; V_88 ++ )
* ( V_5 + 4 + V_88 ) = V_42 -> V_5 [ V_88 ] ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_89 ;
return F_110 ( V_42 , V_42 -> V_71 - 8 , V_1 -> V_6 , V_5 ,
V_12 ) ;
}
static int F_117 ( struct V_70 * V_42 )
{
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_58 * * V_1 = F_16 ( V_20 ) ;
struct V_58 * V_59 = * V_1 ;
V_20 = & V_59 -> V_61 ;
if ( F_20 () && ( ! F_118 () ||
! F_119 ( V_59 ) ) )
V_20 = F_120 ( V_59 ) ;
F_121 ( V_42 , V_20 ) ;
return F_122 ( V_42 ) ;
}
static int F_123 ( struct V_70 * V_42 )
{
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_58 * * V_1 = F_16 ( V_20 ) ;
struct V_58 * V_59 = * V_1 ;
V_20 = & V_59 -> V_61 ;
if ( F_20 () && ( ! F_118 () ||
! F_119 ( V_59 ) ) )
V_20 = F_120 ( V_59 ) ;
F_121 ( V_42 , V_20 ) ;
return F_124 ( V_42 ) ;
}
static int F_125 ( struct V_19 * V_57 , const T_1 * V_39 ,
unsigned int V_28 )
{
struct V_23 * V_1 = F_17 ( V_57 ) ;
return F_19 ( F_87 ( V_57 ) ,
& V_1 -> V_67 , V_39 , V_28 ) ? :
F_80 ( V_1 -> V_6 , V_39 , V_28 ) ;
}
static int F_126 ( struct V_70 * V_42 )
{
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_23 * V_1 = F_17 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_67 ) ;
T_1 V_5 [ 16 ] V_87 ( ( F_114 ( V_22 ) ) ) ;
T_5 V_89 = F_115 ( 1 ) ;
memcpy ( V_5 , V_42 -> V_5 , 12 ) ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_89 ;
return F_94 ( V_42 , V_42 -> V_71 , V_1 -> V_6 , V_5 ,
V_12 ) ;
}
static int F_127 ( struct V_70 * V_42 )
{
T_5 V_89 = F_115 ( 1 ) ;
struct V_19 * V_20 = F_95 ( V_42 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_67 ) ;
T_1 V_5 [ 16 ] V_87 ( ( F_114 ( V_22 ) ) ) ;
memcpy ( V_5 , V_42 -> V_5 , 12 ) ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_89 ;
return F_110 ( V_42 , V_42 -> V_71 , V_1 -> V_6 , V_5 ,
V_12 ) ;
}
static void F_128 ( void )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_129 ( V_90 ) &&
V_90 [ V_88 ] ; V_88 ++ )
F_130 ( V_90 [ V_88 ] ) ;
for ( V_88 = 0 ; V_88 < F_129 ( V_91 ) ; V_88 ++ )
if ( V_91 [ V_88 ] . V_92 )
F_130 ( V_91 [ V_88 ] . V_92 ) ;
}
static int T_6 F_131 ( void )
{
struct V_93 * V_92 ;
const char * V_94 ;
const char * V_95 ;
const char * V_96 ;
int V_31 ;
int V_88 ;
if ( ! F_132 ( V_97 ) )
return - V_98 ;
#ifdef F_133
#ifdef F_134
if ( F_135 ( V_99 ) ) {
F_136 ( L_3 ) ;
F_105 = F_8 ;
F_111 = F_11 ;
} else
#endif
#ifdef F_137
if ( F_135 ( V_100 ) ) {
F_136 ( L_4 ) ;
F_105 = F_1 ;
F_111 = F_5 ;
} else
#endif
{
F_136 ( L_5 ) ;
F_105 = F_2 ;
F_111 = F_6 ;
}
F_57 = V_101 ;
#ifdef F_137
if ( F_135 ( V_100 ) ) {
F_57 = F_52 ;
F_136 ( L_6 ) ;
}
#endif
#endif
V_31 = F_138 () ;
if ( V_31 )
return V_31 ;
V_31 = F_139 ( V_102 , F_129 ( V_102 ) ) ;
if ( V_31 )
goto V_103;
V_31 = F_140 ( V_104 ,
F_129 ( V_104 ) ) ;
if ( V_31 )
goto V_105;
V_31 = F_141 ( V_106 ,
F_129 ( V_106 ) ) ;
if ( V_31 )
goto V_107;
for ( V_88 = 0 ; V_88 < F_129 ( V_104 ) ; V_88 ++ ) {
V_95 = V_104 [ V_88 ] . V_61 . V_108 + 2 ;
V_96 = V_104 [ V_88 ] . V_61 . V_109 + 2 ;
V_94 = V_104 [ V_88 ] . V_61 . V_109 ;
V_92 = F_142 ( V_95 , V_96 , V_94 ) ;
V_31 = F_75 ( V_92 ) ;
if ( F_74 ( V_92 ) )
goto V_110;
V_90 [ V_88 ] = V_92 ;
}
for ( V_88 = 0 ; V_88 < F_129 ( V_91 ) ; V_88 ++ ) {
V_95 = V_91 [ V_88 ] . V_95 ;
V_96 = V_91 [ V_88 ] . V_96 ;
V_94 = V_91 [ V_88 ] . V_94 ;
V_92 = F_142 ( V_95 , V_96 , V_94 ) ;
V_31 = F_75 ( V_92 ) ;
if ( F_74 ( V_92 ) )
continue;
V_91 [ V_88 ] . V_92 = V_92 ;
}
return 0 ;
V_110:
F_128 () ;
F_143 ( V_106 , F_129 ( V_106 ) ) ;
V_107:
F_144 ( V_104 ,
F_129 ( V_104 ) ) ;
V_105:
F_145 ( V_102 , F_129 ( V_102 ) ) ;
V_103:
F_146 () ;
return V_31 ;
}
static void T_7 F_147 ( void )
{
F_128 () ;
F_143 ( V_106 , F_129 ( V_106 ) ) ;
F_144 ( V_104 ,
F_129 ( V_104 ) ) ;
F_145 ( V_102 , F_129 ( V_102 ) ) ;
F_146 () ;
}
