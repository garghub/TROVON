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
static int F_34 ( struct V_37 * V_20 , const T_1 * V_38 ,
unsigned int V_39 )
{
return F_18 ( F_35 ( V_20 ) ,
F_36 ( V_20 ) , V_38 , V_39 ) ;
}
static int F_37 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_11 * V_1 = V_12 ( F_36 ( V_20 ) ) ;
struct V_42 V_43 ;
unsigned int V_44 ;
int V_30 ;
V_30 = F_39 ( & V_43 , V_41 , true ) ;
F_21 () ;
while ( ( V_44 = V_43 . V_44 ) ) {
F_40 ( V_1 , V_43 . V_35 . V_45 . V_24 , V_43 . V_36 . V_45 . V_24 ,
V_44 & V_46 ) ;
V_44 &= V_47 - 1 ;
V_30 = F_41 ( & V_43 , V_44 ) ;
}
F_23 () ;
return V_30 ;
}
static int F_42 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_11 * V_1 = V_12 ( F_36 ( V_20 ) ) ;
struct V_42 V_43 ;
unsigned int V_44 ;
int V_30 ;
V_30 = F_39 ( & V_43 , V_41 , true ) ;
F_21 () ;
while ( ( V_44 = V_43 . V_44 ) ) {
F_43 ( V_1 , V_43 . V_35 . V_45 . V_24 , V_43 . V_36 . V_45 . V_24 ,
V_44 & V_46 ) ;
V_44 &= V_47 - 1 ;
V_30 = F_41 ( & V_43 , V_44 ) ;
}
F_23 () ;
return V_30 ;
}
static int F_44 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_11 * V_1 = V_12 ( F_36 ( V_20 ) ) ;
struct V_42 V_43 ;
unsigned int V_44 ;
int V_30 ;
V_30 = F_39 ( & V_43 , V_41 , true ) ;
F_21 () ;
while ( ( V_44 = V_43 . V_44 ) ) {
F_45 ( V_1 , V_43 . V_35 . V_45 . V_24 , V_43 . V_36 . V_45 . V_24 ,
V_44 & V_46 , V_43 . V_5 ) ;
V_44 &= V_47 - 1 ;
V_30 = F_41 ( & V_43 , V_44 ) ;
}
F_23 () ;
return V_30 ;
}
static int F_46 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_11 * V_1 = V_12 ( F_36 ( V_20 ) ) ;
struct V_42 V_43 ;
unsigned int V_44 ;
int V_30 ;
V_30 = F_39 ( & V_43 , V_41 , true ) ;
F_21 () ;
while ( ( V_44 = V_43 . V_44 ) ) {
F_47 ( V_1 , V_43 . V_35 . V_45 . V_24 , V_43 . V_36 . V_45 . V_24 ,
V_44 & V_46 , V_43 . V_5 ) ;
V_44 &= V_47 - 1 ;
V_30 = F_41 ( & V_43 , V_44 ) ;
}
F_23 () ;
return V_30 ;
}
static void F_48 ( struct V_11 * V_1 ,
struct V_42 * V_43 )
{
T_1 * V_48 = V_43 -> V_5 ;
T_1 V_49 [ V_47 ] ;
T_1 * V_36 = V_43 -> V_36 . V_45 . V_24 ;
T_1 * V_35 = V_43 -> V_35 . V_45 . V_24 ;
unsigned int V_44 = V_43 -> V_44 ;
F_28 ( V_1 , V_49 , V_48 ) ;
F_49 ( V_49 , V_36 , V_44 ) ;
memcpy ( V_35 , V_49 , V_44 ) ;
F_50 ( V_48 , V_47 ) ;
}
static void F_51 ( struct V_11 * V_1 , T_1 * V_2 ,
const T_1 * V_3 , unsigned int V_39 , T_1 * V_5 )
{
if ( V_1 -> V_14 == V_15 )
F_52 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_39 ) ;
else if ( V_1 -> V_14 == V_31 )
F_53 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_39 ) ;
else
F_54 ( V_3 , V_5 , ( void * ) V_1 , V_2 , V_39 ) ;
}
static int F_55 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_11 * V_1 = V_12 ( F_36 ( V_20 ) ) ;
struct V_42 V_43 ;
unsigned int V_44 ;
int V_30 ;
V_30 = F_39 ( & V_43 , V_41 , true ) ;
F_21 () ;
while ( ( V_44 = V_43 . V_44 ) >= V_47 ) {
F_56 ( V_1 , V_43 . V_35 . V_45 . V_24 , V_43 . V_36 . V_45 . V_24 ,
V_44 & V_46 , V_43 . V_5 ) ;
V_44 &= V_47 - 1 ;
V_30 = F_41 ( & V_43 , V_44 ) ;
}
if ( V_43 . V_44 ) {
F_48 ( V_1 , & V_43 ) ;
V_30 = F_41 ( & V_43 , 0 ) ;
}
F_23 () ;
return V_30 ;
}
static int F_57 ( struct V_37 * V_20 , const T_1 * V_38 ,
unsigned int V_50 )
{
struct V_51 * V_1 = F_36 ( V_20 ) ;
int V_30 ;
V_30 = F_58 ( V_20 , V_38 , V_50 ) ;
if ( V_30 )
return V_30 ;
V_50 /= 2 ;
V_30 = F_18 ( F_35 ( V_20 ) , V_1 -> V_52 ,
V_38 , V_50 ) ;
if ( V_30 )
return V_30 ;
return F_18 ( F_35 ( V_20 ) , V_1 -> V_53 ,
V_38 + V_50 , V_50 ) ;
}
static void F_59 ( void * V_1 , T_1 * V_2 , const T_1 * V_3 )
{
F_28 ( V_1 , V_2 , V_3 ) ;
}
static void F_60 ( void * V_1 , T_3 * V_35 , const T_3 * V_36 , T_4 * V_5 )
{
F_61 ( V_1 , V_35 , V_36 , V_5 , F_62 ( F_28 ) ) ;
}
static void F_63 ( void * V_1 , T_3 * V_35 , const T_3 * V_36 , T_4 * V_5 )
{
F_61 ( V_1 , V_35 , V_36 , V_5 , F_62 ( F_31 ) ) ;
}
static void F_64 ( void * V_1 , T_3 * V_35 , const T_3 * V_36 , T_4 * V_5 )
{
F_65 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , true , ( T_1 * ) V_5 ) ;
}
static void F_66 ( void * V_1 , T_3 * V_35 , const T_3 * V_36 , T_4 * V_5 )
{
F_65 ( V_1 , ( T_1 * ) V_35 , ( const T_1 * ) V_36 , false , ( T_1 * ) V_5 ) ;
}
static int F_67 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_51 * V_1 = F_36 ( V_20 ) ;
return F_68 ( & V_54 , V_41 ,
F_69 ( F_59 ) ,
V_12 ( V_1 -> V_53 ) ,
V_12 ( V_1 -> V_52 ) ) ;
}
static int F_70 ( struct V_40 * V_41 )
{
struct V_37 * V_20 = F_38 ( V_41 ) ;
struct V_51 * V_1 = F_36 ( V_20 ) ;
return F_68 ( & V_55 , V_41 ,
F_69 ( F_59 ) ,
V_12 ( V_1 -> V_53 ) ,
V_12 ( V_1 -> V_52 ) ) ;
}
static int F_71 ( struct V_19 * V_56 )
{
struct V_57 * V_58 ;
struct V_57 * * V_1 = F_16 ( V_56 ) ;
V_58 = F_72 ( L_1 ,
V_59 ,
V_59 ) ;
if ( F_73 ( V_58 ) )
return F_74 ( V_58 ) ;
* V_1 = V_58 ;
F_75 ( V_56 , F_76 ( & V_58 -> V_60 ) ) ;
return 0 ;
}
static void F_77 ( struct V_19 * V_56 )
{
struct V_57 * * V_1 = F_16 ( V_56 ) ;
F_78 ( * V_1 ) ;
}
static int
F_79 ( T_1 * V_6 , const T_1 * V_38 , unsigned int V_27 )
{
struct V_61 * V_20 ;
int V_62 ;
V_20 = F_80 ( L_2 , 0 , 0 ) ;
if ( F_73 ( V_20 ) )
return F_74 ( V_20 ) ;
V_62 = F_81 ( V_20 , V_38 , V_27 ) ;
if ( V_62 )
goto V_63;
memset ( V_6 , 0 , V_64 ) ;
F_82 ( V_20 , V_6 , V_6 ) ;
V_63:
F_83 ( V_20 ) ;
return V_62 ;
}
static int F_84 ( struct V_19 * V_56 , const T_1 * V_38 ,
unsigned int V_27 )
{
struct V_18 * V_1 = F_13 ( V_56 ) ;
if ( V_27 < 4 ) {
F_85 ( V_56 , V_33 ) ;
return - V_34 ;
}
V_27 -= 4 ;
memcpy ( V_1 -> V_65 , V_38 + V_27 , sizeof( V_1 -> V_65 ) ) ;
return F_18 ( F_86 ( V_56 ) ,
& V_1 -> V_66 , V_38 , V_27 ) ? :
F_79 ( V_1 -> V_6 , V_38 , V_27 ) ;
}
static int F_87 ( struct V_19 * V_67 , const T_1 * V_38 ,
unsigned int V_27 )
{
struct V_57 * * V_1 = F_16 ( V_67 ) ;
struct V_57 * V_58 = * V_1 ;
return F_88 ( & V_58 -> V_60 , V_38 , V_27 ) ;
}
static int F_89 ( struct V_19 * V_56 ,
unsigned int V_68 )
{
switch ( V_68 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_90 ( struct V_19 * V_67 ,
unsigned int V_68 )
{
struct V_57 * * V_1 = F_16 ( V_67 ) ;
struct V_57 * V_58 = * V_1 ;
return F_91 ( & V_58 -> V_60 , V_68 ) ;
}
static int F_92 ( struct V_69 * V_41 )
{
T_1 V_70 = 0 ;
T_1 * V_36 , * V_35 , * V_71 ;
T_5 V_72 = F_93 ( 1 ) ;
struct V_19 * V_20 = F_94 ( V_41 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_66 ) ;
unsigned long V_10 = F_95 ( V_20 ) ;
T_1 V_5 [ 16 ] V_73 ( ( F_96 ( V_22 ) ) ) ;
struct V_74 V_75 ;
struct V_74 V_76 = {} ;
unsigned int V_77 ;
if ( F_97 ( V_41 -> V_78 != 16 && V_41 -> V_78 != 20 ) )
return - V_34 ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
* ( V_5 + V_77 ) = V_1 -> V_65 [ V_77 ] ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
* ( V_5 + 4 + V_77 ) = V_41 -> V_5 [ V_77 ] ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_72 ;
if ( F_98 ( V_41 -> V_36 ) &&
V_41 -> V_36 -> V_79 + V_41 -> V_36 -> V_80 <= V_81 &&
F_98 ( V_41 -> V_35 ) &&
V_41 -> V_35 -> V_79 + V_41 -> V_35 -> V_80 <= V_81 ) {
V_70 = 1 ;
F_99 ( & V_75 , V_41 -> V_36 ) ;
V_71 = F_100 ( & V_75 ) ;
V_36 = V_71 + V_41 -> V_78 ;
V_35 = V_36 ;
if ( F_97 ( V_41 -> V_36 != V_41 -> V_35 ) ) {
F_99 ( & V_76 , V_41 -> V_35 ) ;
V_35 = F_100 ( & V_76 ) + V_41 -> V_78 ;
}
} else {
V_71 = F_101 ( V_41 -> V_82 + V_10 + V_41 -> V_78 ,
V_83 ) ;
if ( F_97 ( ! V_71 ) )
return - V_84 ;
F_102 ( V_71 , V_41 -> V_36 , 0 ,
V_41 -> V_78 + V_41 -> V_82 , 0 ) ;
V_36 = V_71 + V_41 -> V_78 ;
V_35 = V_36 ;
}
F_21 () ;
F_103 ( V_12 , V_35 , V_36 , V_41 -> V_82 , V_5 ,
V_1 -> V_6 , V_71 , V_41 -> V_78 - 8 ,
V_35 + V_41 -> V_82 , V_10 ) ;
F_23 () ;
if ( V_70 ) {
if ( F_97 ( V_41 -> V_36 != V_41 -> V_35 ) ) {
F_104 ( V_35 - V_41 -> V_78 ) ;
F_105 ( & V_76 , V_41 -> V_35 -> V_80 ) ;
F_106 ( & V_76 , 1 , 0 ) ;
}
F_104 ( V_71 ) ;
F_105 ( & V_75 , V_41 -> V_36 -> V_80 ) ;
F_106 ( & V_75 , V_41 -> V_36 == V_41 -> V_35 , 0 ) ;
} else {
F_102 ( V_35 , V_41 -> V_35 , V_41 -> V_78 ,
V_41 -> V_82 + V_10 , 1 ) ;
F_107 ( V_71 ) ;
}
return 0 ;
}
static int F_108 ( struct V_69 * V_41 )
{
T_1 V_70 = 0 ;
T_1 * V_36 , * V_35 , * V_71 ;
unsigned long V_85 = 0 ;
T_5 V_72 = F_93 ( 1 ) ;
int V_86 = 0 ;
struct V_19 * V_20 = F_94 ( V_41 ) ;
struct V_18 * V_1 = F_13 ( V_20 ) ;
void * V_12 = & ( V_1 -> V_66 ) ;
unsigned long V_10 = F_95 ( V_20 ) ;
T_1 V_5 [ 16 ] V_73 ( ( F_96 ( V_22 ) ) ) ;
T_1 V_87 [ 16 ] ;
struct V_74 V_75 ;
struct V_74 V_76 = {} ;
unsigned int V_77 ;
if ( F_97 ( V_41 -> V_78 != 16 && V_41 -> V_78 != 20 ) )
return - V_34 ;
V_85 = ( unsigned long ) ( V_41 -> V_82 - V_10 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ )
* ( V_5 + V_77 ) = V_1 -> V_65 [ V_77 ] ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
* ( V_5 + 4 + V_77 ) = V_41 -> V_5 [ V_77 ] ;
* ( ( T_5 * ) ( V_5 + 12 ) ) = V_72 ;
if ( F_98 ( V_41 -> V_36 ) &&
V_41 -> V_36 -> V_79 + V_41 -> V_36 -> V_80 <= V_81 &&
F_98 ( V_41 -> V_35 ) &&
V_41 -> V_35 -> V_79 + V_41 -> V_35 -> V_80 <= V_81 ) {
V_70 = 1 ;
F_99 ( & V_75 , V_41 -> V_36 ) ;
V_71 = F_100 ( & V_75 ) ;
V_36 = V_71 + V_41 -> V_78 ;
V_35 = V_36 ;
if ( F_97 ( V_41 -> V_36 != V_41 -> V_35 ) ) {
F_99 ( & V_76 , V_41 -> V_35 ) ;
V_35 = F_100 ( & V_76 ) + V_41 -> V_78 ;
}
} else {
V_71 = F_101 ( V_41 -> V_82 + V_41 -> V_78 , V_83 ) ;
if ( ! V_71 )
return - V_84 ;
F_102 ( V_71 , V_41 -> V_36 , 0 ,
V_41 -> V_78 + V_41 -> V_82 , 0 ) ;
V_36 = V_71 + V_41 -> V_78 ;
V_35 = V_36 ;
}
F_21 () ;
F_109 ( V_12 , V_35 , V_36 , V_85 , V_5 ,
V_1 -> V_6 , V_71 , V_41 -> V_78 - 8 ,
V_87 , V_10 ) ;
F_23 () ;
V_86 = F_110 ( V_36 + V_85 , V_87 , V_10 ) ?
- V_88 : 0 ;
if ( V_70 ) {
if ( F_97 ( V_41 -> V_36 != V_41 -> V_35 ) ) {
F_104 ( V_35 - V_41 -> V_78 ) ;
F_105 ( & V_76 , V_41 -> V_35 -> V_80 ) ;
F_106 ( & V_76 , 1 , 0 ) ;
}
F_104 ( V_71 ) ;
F_105 ( & V_75 , V_41 -> V_36 -> V_80 ) ;
F_106 ( & V_75 , V_41 -> V_36 == V_41 -> V_35 , 0 ) ;
} else {
F_102 ( V_35 , V_41 -> V_35 , V_41 -> V_78 ,
V_85 , 1 ) ;
F_107 ( V_71 ) ;
}
return V_86 ;
}
static int F_111 ( struct V_69 * V_41 )
{
struct V_19 * V_20 = F_94 ( V_41 ) ;
struct V_57 * * V_1 = F_16 ( V_20 ) ;
struct V_57 * V_58 = * V_1 ;
V_20 = & V_58 -> V_60 ;
if ( F_19 () && ( ! F_112 () ||
! F_113 ( V_58 ) ) )
V_20 = F_114 ( V_58 ) ;
F_115 ( V_41 , V_20 ) ;
return F_116 ( V_41 ) ;
}
static int F_117 ( struct V_69 * V_41 )
{
struct V_19 * V_20 = F_94 ( V_41 ) ;
struct V_57 * * V_1 = F_16 ( V_20 ) ;
struct V_57 * V_58 = * V_1 ;
V_20 = & V_58 -> V_60 ;
if ( F_19 () && ( ! F_112 () ||
! F_113 ( V_58 ) ) )
V_20 = F_114 ( V_58 ) ;
F_115 ( V_41 , V_20 ) ;
return F_118 ( V_41 ) ;
}
static void F_119 ( void )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < F_120 ( V_89 ) &&
V_89 [ V_77 ] ; V_77 ++ )
F_121 ( V_89 [ V_77 ] ) ;
for ( V_77 = 0 ; V_77 < F_120 ( V_90 ) ; V_77 ++ )
if ( V_90 [ V_77 ] . V_91 )
F_121 ( V_90 [ V_77 ] . V_91 ) ;
}
static int T_6 F_122 ( void )
{
struct V_92 * V_91 ;
const char * V_93 ;
const char * V_94 ;
const char * V_95 ;
int V_30 ;
int V_77 ;
if ( ! F_123 ( V_96 ) )
return - V_97 ;
#ifdef F_124
#ifdef F_125
if ( F_126 ( V_98 ) ) {
F_127 ( L_3 ) ;
F_103 = F_8 ;
F_109 = F_11 ;
} else
#endif
#ifdef F_128
if ( F_126 ( V_99 ) ) {
F_127 ( L_4 ) ;
F_103 = F_1 ;
F_109 = F_5 ;
} else
#endif
{
F_127 ( L_5 ) ;
F_103 = F_2 ;
F_109 = F_6 ;
}
F_56 = V_100 ;
#ifdef F_128
if ( F_126 ( V_99 ) ) {
F_56 = F_51 ;
F_127 ( L_6 ) ;
}
#endif
#endif
V_30 = F_129 () ;
if ( V_30 )
return V_30 ;
V_30 = F_130 ( V_101 , F_120 ( V_101 ) ) ;
if ( V_30 )
goto V_102;
V_30 = F_131 ( V_103 ,
F_120 ( V_103 ) ) ;
if ( V_30 )
goto V_104;
V_30 = F_132 ( V_105 ,
F_120 ( V_105 ) ) ;
if ( V_30 )
goto V_106;
for ( V_77 = 0 ; V_77 < F_120 ( V_103 ) ; V_77 ++ ) {
V_94 = V_103 [ V_77 ] . V_60 . V_107 + 2 ;
V_95 = V_103 [ V_77 ] . V_60 . V_108 + 2 ;
V_93 = V_103 [ V_77 ] . V_60 . V_108 ;
V_91 = F_133 ( V_94 , V_95 , V_93 ) ;
V_30 = F_74 ( V_91 ) ;
if ( F_73 ( V_91 ) )
goto V_109;
V_89 [ V_77 ] = V_91 ;
}
for ( V_77 = 0 ; V_77 < F_120 ( V_90 ) ; V_77 ++ ) {
V_94 = V_90 [ V_77 ] . V_94 ;
V_95 = V_90 [ V_77 ] . V_95 ;
V_93 = V_90 [ V_77 ] . V_93 ;
V_91 = F_133 ( V_94 , V_95 , V_93 ) ;
V_30 = F_74 ( V_91 ) ;
if ( F_73 ( V_91 ) )
continue;
V_90 [ V_77 ] . V_91 = V_91 ;
}
return 0 ;
V_109:
F_119 () ;
F_134 ( V_105 , F_120 ( V_105 ) ) ;
V_106:
F_135 ( V_103 ,
F_120 ( V_103 ) ) ;
V_104:
F_136 ( V_101 , F_120 ( V_101 ) ) ;
V_102:
F_137 () ;
return V_30 ;
}
static void T_7 F_138 ( void )
{
F_119 () ;
F_134 ( V_105 , F_120 ( V_105 ) ) ;
F_135 ( V_103 ,
F_120 ( V_103 ) ) ;
F_136 ( V_101 , F_120 ( V_101 ) ) ;
F_137 () ;
}
