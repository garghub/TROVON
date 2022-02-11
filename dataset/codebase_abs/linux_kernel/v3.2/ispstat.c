static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , enum V_6 V_7 ,
void (* F_2)( struct V_8 * ,
T_2 , unsigned long , T_3 ,
enum V_6 ) )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_9 ;
struct V_11 * V_12 ;
T_2 V_13 ;
T_1 V_14 ;
V_12 = F_3 ( V_4 -> V_15 ) ;
V_13 = F_4 ( V_9 , F_5 ( V_12 ) ) ;
F_2 ( V_9 , V_13 , 0 , V_16 , V_7 ) ;
V_12 = F_3 ( V_4 -> V_15 + V_5 ) ;
V_13 = F_4 ( V_9 , F_5 ( V_12 ) ) ;
V_14 = ( ( T_1 ) V_4 -> V_15 + V_5 ) & ~ V_17 ;
F_2 ( V_9 , V_13 , V_14 , V_16 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
enum V_6 V_7 )
{
if ( F_7 ( V_2 ) )
return;
F_1 ( V_2 , V_4 , V_5 , V_7 ,
V_18 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
enum V_6 V_7 )
{
if ( F_7 ( V_2 ) )
return;
F_1 ( V_2 , V_4 , V_5 , V_7 ,
V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 V_5 = F_10 ( V_2 ) ?
V_4 -> V_5 + V_20 : V_4 -> V_5 ;
T_4 * V_21 ;
T_4 * V_22 ;
int V_23 = - V_24 ;
F_8 ( V_2 , V_4 , V_5 , V_25 ) ;
for ( V_21 = V_4 -> V_15 , V_22 = V_21 + V_16 ; V_21 < V_22 ; V_21 ++ )
if ( F_11 ( * V_21 != V_26 ) )
V_23 = 0 ;
if ( V_23 ) {
F_12 ( V_2 -> V_10 -> V_9 , L_1
L_2 , V_2 -> V_27 . V_28 ) ;
return V_23 ;
}
for ( V_21 = V_4 -> V_15 + V_5 , V_22 = V_21 + V_16 ;
V_21 < V_22 ; V_21 ++ ) {
if ( F_13 ( * V_21 != V_26 ) ) {
F_12 ( V_2 -> V_10 -> V_9 , L_3
L_4 , V_2 -> V_27 . V_28 ) ;
return - V_24 ;
}
}
F_6 ( V_2 , V_4 , V_5 ,
V_25 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 V_5 = F_10 ( V_2 ) ?
V_2 -> V_5 + V_20 : V_2 -> V_5 ;
F_8 ( V_2 , V_4 , V_5 , V_25 ) ;
memset ( V_4 -> V_15 , V_26 , V_16 ) ;
memset ( V_4 -> V_15 + V_5 , V_26 , V_16 ) ;
F_6 ( V_2 , V_4 , V_5 ,
V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) )
return;
F_16 ( V_2 -> V_10 -> V_9 , V_4 -> V_30 -> V_31 -> V_32 ,
V_4 -> V_30 -> V_31 -> V_33 , V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) )
return;
F_18 ( V_2 -> V_10 -> V_9 , V_4 -> V_30 -> V_31 -> V_32 ,
V_4 -> V_30 -> V_31 -> V_33 , V_25 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
V_2 -> V_4 [ V_34 ] . V_36 = 1 ;
}
static struct V_3 *
F_20 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_38 = NULL ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
struct V_3 * V_39 = & V_2 -> V_4 [ V_34 ] ;
if ( V_39 == V_2 -> V_40 || V_39 == V_2 -> V_41 )
continue;
if ( ! V_37 && V_39 -> V_36 )
continue;
if ( V_39 -> V_36 ) {
V_38 = V_39 ;
break;
}
if ( ! V_38 ||
( V_42 ) V_39 -> V_43 - ( V_42 ) V_38 -> V_43 < 0 )
V_38 = V_39 ;
}
return V_38 ;
}
static inline struct V_3 *
F_21 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , 0 ) ;
}
static inline struct V_3 *
F_22 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , 1 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_41 )
return V_44 ;
F_24 ( & V_2 -> V_41 -> V_45 ) ;
V_2 -> V_41 -> V_5 = V_2 -> V_5 ;
if ( F_9 ( V_2 , V_2 -> V_41 ) ) {
F_12 ( V_2 -> V_10 -> V_9 , L_5 ,
V_2 -> V_27 . V_28 ) ;
return V_44 ;
}
V_2 -> V_41 -> V_46 = V_2 -> V_46 ;
V_2 -> V_41 -> V_43 = V_2 -> V_43 ;
V_2 -> V_41 -> V_36 = 0 ;
V_2 -> V_41 = NULL ;
return V_47 ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 -> V_41 ) )
F_12 ( V_2 -> V_10 -> V_9 , L_6
L_7 ,
V_2 -> V_27 . V_28 ) ;
else
V_2 -> V_41 = F_22 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_48 ;
F_15 ( V_2 , V_2 -> V_40 ) ;
F_27 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
V_2 -> V_40 = NULL ;
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
}
static struct V_3 * F_29 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_52 = 0 ;
unsigned long V_48 ;
struct V_3 * V_4 ;
F_27 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
while ( 1 ) {
V_4 = F_21 ( V_2 ) ;
if ( ! V_4 ) {
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_8 ,
V_2 -> V_27 . V_28 ) ;
return F_30 ( - V_53 ) ;
}
if ( F_9 ( V_2 , V_4 ) ) {
F_12 ( V_2 -> V_10 -> V_9 , L_9
L_10 , V_2 -> V_27 . V_28 ) ;
V_4 -> V_36 = 1 ;
} else {
break;
}
}
V_2 -> V_40 = V_4 ;
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
if ( V_4 -> V_5 > V_51 -> V_5 ) {
F_31 ( V_2 -> V_10 -> V_9 , L_11
L_12 , V_2 -> V_27 . V_28 ) ;
F_26 ( V_2 ) ;
return F_30 ( - V_24 ) ;
}
F_17 ( V_2 , V_4 ) ;
V_52 = F_32 ( V_51 -> V_4 ,
V_4 -> V_15 ,
V_4 -> V_5 ) ;
if ( V_52 ) {
F_33 ( V_2 -> V_10 -> V_9 ,
L_13 ,
V_2 -> V_27 . V_28 , V_52 ) ;
V_4 = F_30 ( - V_54 ) ;
F_26 ( V_2 ) ;
}
return V_4 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_55 * V_10 = V_2 -> V_10 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
struct V_3 * V_4 = & V_2 -> V_4 [ V_34 ] ;
if ( ! F_7 ( V_2 ) ) {
if ( F_35 ( ( void * ) V_4 -> V_56 ) )
continue;
if ( V_4 -> V_30 )
F_36 ( V_10 -> V_9 , V_4 -> V_30 -> V_31 -> V_32 ,
V_4 -> V_30 -> V_31 -> V_33 ,
V_25 ) ;
F_37 ( V_10 -> V_57 , V_10 -> V_58 ,
V_4 -> V_56 ) ;
} else {
if ( ! V_4 -> V_15 )
continue;
F_38 ( V_2 -> V_10 -> V_9 , V_2 -> V_59 ,
V_4 -> V_15 , V_4 -> V_13 ) ;
}
V_4 -> V_56 = 0 ;
V_4 -> V_30 = NULL ;
V_4 -> V_13 = 0 ;
V_4 -> V_15 = NULL ;
V_4 -> V_36 = 1 ;
}
F_12 ( V_2 -> V_10 -> V_9 , L_14 ,
V_2 -> V_27 . V_28 ) ;
V_2 -> V_59 = 0 ;
V_2 -> V_41 = NULL ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_55 * V_10 = V_2 -> V_10 ;
int V_34 ;
V_2 -> V_59 = V_60 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
struct V_3 * V_4 = & V_2 -> V_4 [ V_34 ] ;
struct V_61 * V_30 ;
F_40 ( V_4 -> V_13 ) ;
V_4 -> V_56 = F_41 ( V_10 -> V_57 , V_10 -> V_58 , 0 ,
V_60 , V_62 ) ;
if ( F_42 ( ( void * ) V_4 -> V_56 ) ) {
F_43 ( V_2 -> V_10 -> V_9 ,
L_15
L_16 , V_2 -> V_27 . V_28 , V_34 ) ;
F_34 ( V_2 ) ;
return - V_63 ;
}
V_30 = F_44 ( V_10 -> V_58 , V_4 -> V_56 ) ;
if ( ! V_30 ||
! F_45 ( V_10 -> V_9 , V_30 -> V_31 -> V_32 , V_30 -> V_31 -> V_33 ,
V_25 ) ) {
F_34 ( V_2 ) ;
return - V_63 ;
}
V_4 -> V_30 = V_30 ;
V_4 -> V_15 = F_46 ( V_2 -> V_10 -> V_58 ,
( T_1 ) V_4 -> V_56 ) ;
V_4 -> V_36 = 1 ;
F_12 ( V_2 -> V_10 -> V_9 , L_17
L_18 ,
V_2 -> V_27 . V_28 , V_34 , V_4 -> V_56 ,
( unsigned long ) V_4 -> V_15 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , unsigned int V_60 )
{
int V_34 ;
V_2 -> V_59 = V_60 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
struct V_3 * V_4 = & V_2 -> V_4 [ V_34 ] ;
F_40 ( V_4 -> V_56 ) ;
V_4 -> V_15 = F_48 ( V_2 -> V_10 -> V_9 , V_60 ,
& V_4 -> V_13 , V_64 | V_65 ) ;
if ( ! V_4 -> V_15 || ! V_4 -> V_13 ) {
F_33 ( V_2 -> V_10 -> V_9 ,
L_15
L_19 , V_2 -> V_27 . V_28 , V_34 ) ;
F_34 ( V_2 ) ;
return - V_63 ;
}
V_4 -> V_36 = 1 ;
F_12 ( V_2 -> V_10 -> V_9 , L_17
L_20 ,
V_2 -> V_27 . V_28 , V_34 , ( unsigned long ) V_4 -> V_13 ,
( unsigned long ) V_4 -> V_15 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_60 )
{
unsigned long V_48 ;
F_27 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
F_50 ( V_2 -> V_40 != NULL ) ;
if ( V_2 -> V_59 >= V_60 ) {
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
return 0 ;
}
if ( V_2 -> V_66 != V_67 || V_2 -> V_68 ) {
F_33 ( V_2 -> V_10 -> V_9 ,
L_21 ,
V_2 -> V_27 . V_28 ) ;
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
return - V_53 ;
}
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
F_34 ( V_2 ) ;
if ( F_7 ( V_2 ) )
return F_47 ( V_2 , V_60 ) ;
else
return F_39 ( V_2 , V_60 ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_69 )
{
struct V_70 * V_71 = V_2 -> V_27 . V_72 ;
struct V_73 V_74 ;
struct V_75 * V_76 = ( void * ) V_74 . V_77 . V_51 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
if ( ! V_69 ) {
V_76 -> V_43 = V_2 -> V_43 ;
V_76 -> V_46 = V_2 -> V_46 ;
} else {
V_76 -> V_78 = 1 ;
}
V_74 . type = V_2 -> V_79 ;
F_52 ( V_71 , & V_74 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_66 != V_80 ) {
F_12 ( V_2 -> V_10 -> V_9 , L_22 ,
V_2 -> V_27 . V_28 ) ;
return - V_24 ;
}
F_54 ( & V_2 -> V_81 ) ;
V_4 = F_29 ( V_2 , V_51 ) ;
if ( F_42 ( V_4 ) ) {
F_55 ( & V_2 -> V_81 ) ;
return F_56 ( V_4 ) ;
}
V_51 -> V_45 = V_4 -> V_45 ;
V_51 -> V_46 = V_4 -> V_46 ;
V_51 -> V_43 = V_4 -> V_43 ;
V_51 -> V_5 = V_4 -> V_5 ;
V_4 -> V_36 = 1 ;
F_26 ( V_2 ) ;
F_55 ( & V_2 -> V_81 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , void * V_82 )
{
int V_23 ;
unsigned long V_83 ;
struct V_84 * V_85 = V_82 ;
T_1 V_5 = V_85 -> V_5 ;
if ( ! V_82 ) {
F_12 ( V_2 -> V_10 -> V_9 , L_23 ,
V_2 -> V_27 . V_28 ) ;
return - V_24 ;
}
F_54 ( & V_2 -> V_81 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_24
L_25 , V_2 -> V_27 . V_28 , ( unsigned long ) V_5 ) ;
V_23 = V_2 -> V_86 -> V_87 ( V_2 , V_82 ) ;
if ( V_23 ) {
F_55 ( & V_2 -> V_81 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_26
L_27 , V_2 -> V_27 . V_28 ) ;
return V_23 ;
}
if ( V_5 != V_85 -> V_5 )
F_12 ( V_2 -> V_10 -> V_9 , L_28
L_29 , V_2 -> V_27 . V_28 ,
( unsigned long ) V_85 -> V_5 ) ;
if ( F_58 ( V_2 ) ) {
V_5 = V_85 -> V_5 * 2 + V_16 ;
if ( F_10 ( V_2 ) )
V_5 += V_20 * ( V_88 + 2 ) ;
if ( V_2 -> V_89 ) {
struct V_84 * V_90 =
V_2 -> V_89 ;
V_5 += V_90 -> V_5 *
V_88 ;
}
V_5 = F_59 ( V_5 ) ;
} else {
V_5 = F_59 ( V_85 -> V_5 + V_16 ) ;
}
V_23 = F_49 ( V_2 , V_5 ) ;
if ( V_23 ) {
F_55 ( & V_2 -> V_81 ) ;
return V_23 ;
}
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
V_2 -> V_86 -> V_91 ( V_2 , V_82 ) ;
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
V_85 -> V_46 = V_2 -> V_46 + V_2 -> V_92 ;
V_2 -> V_93 = 1 ;
F_12 ( V_2 -> V_10 -> V_9 , L_30
L_31 , V_2 -> V_27 . V_28 ) ;
F_55 ( & V_2 -> V_81 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_94 )
{
int V_23 = V_44 ;
if ( ! F_61 ( & V_2 -> V_78 , - 1 , 0 ) &&
V_94 == V_47 && V_2 -> V_66 == V_80 ) {
V_23 = F_23 ( V_2 ) ;
F_25 ( V_2 ) ;
}
return V_23 ;
}
int F_62 ( struct V_1 * V_2 )
{
return V_2 -> V_86 -> V_95 ( V_2 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
return F_62 ( V_2 ) | V_2 -> V_68 |
( V_2 -> V_66 != V_67 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_4 V_96 )
{
if ( ( V_2 -> V_66 != V_97 &&
V_2 -> V_66 != V_80 ) && V_96 )
return;
V_2 -> V_86 -> V_98 ( V_2 , V_96 ) ;
if ( V_2 -> V_66 == V_99 && ! V_96 )
V_2 -> V_66 = V_67 ;
else if ( V_2 -> V_66 == V_97 && V_96 )
V_2 -> V_66 = V_80 ;
}
void F_65 ( struct V_1 * V_2 )
{
unsigned long V_48 ;
F_27 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
if ( V_2 -> V_66 != V_67 )
V_2 -> V_86 -> V_98 ( V_2 , 0 ) ;
if ( V_2 -> V_66 == V_80 )
V_2 -> V_66 = V_100 ;
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 == V_100 )
V_2 -> V_66 = V_97 ;
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
if ( V_2 -> V_101 == NULL )
return;
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
if ( V_2 -> V_66 == V_97 && ! V_2 -> V_68 &&
V_2 -> V_59 ) {
V_2 -> V_102 = 1 ;
F_25 ( V_2 ) ;
V_2 -> V_86 -> V_103 ( V_2 , V_2 -> V_101 ) ;
F_14 ( V_2 , V_2 -> V_41 ) ;
if ( ! F_58 ( V_2 ) )
F_68 ( & V_2 -> V_78 , 0 ) ;
F_64 ( V_2 , 1 ) ;
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_32 ,
V_2 -> V_27 . V_28 ) ;
} else {
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
}
}
void F_69 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
F_68 ( & V_2 -> V_78 , 2 ) ;
if ( V_2 -> V_89 )
V_2 -> V_104 = 1 ;
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
}
int F_71 ( struct V_1 * V_2 , T_4 V_98 )
{
unsigned long V_83 ;
F_12 ( V_2 -> V_10 -> V_9 , L_33 ,
V_2 -> V_27 . V_28 , V_98 ? L_34 : L_35 ) ;
F_54 ( & V_2 -> V_81 ) ;
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
if ( ! V_2 -> V_93 && V_98 ) {
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
F_55 ( & V_2 -> V_81 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_36
L_37 ,
V_2 -> V_27 . V_28 ) ;
return - V_24 ;
}
if ( V_98 ) {
if ( V_2 -> V_66 == V_99 )
V_2 -> V_66 = V_80 ;
else if ( V_2 -> V_66 == V_67 )
V_2 -> V_66 = V_97 ;
} else {
if ( V_2 -> V_66 == V_97 ) {
V_2 -> V_66 = V_67 ;
} else if ( V_2 -> V_66 == V_80 ) {
V_2 -> V_66 = V_99 ;
F_19 ( V_2 ) ;
}
}
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
F_55 ( & V_2 -> V_81 ) ;
return 0 ;
}
int F_72 ( struct V_105 * V_27 , int V_98 )
{
struct V_1 * V_2 = F_73 ( V_27 ) ;
if ( V_98 ) {
F_67 ( V_2 ) ;
} else {
unsigned long V_48 ;
F_71 ( V_2 , 0 ) ;
F_27 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
V_2 -> V_86 -> V_98 ( V_2 , 0 ) ;
F_28 ( & V_2 -> V_10 -> V_49 , V_48 ) ;
if ( ! F_62 ( V_2 ) )
F_74 ( V_2 ) ;
F_12 ( V_2 -> V_10 -> V_9 , L_38 ,
V_2 -> V_27 . V_28 ) ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , int V_106 )
{
int V_23 = V_47 ;
int V_68 ;
unsigned long V_83 ;
struct V_107 * V_108 ;
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
if ( V_2 -> V_66 == V_67 ) {
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
return;
}
V_68 = V_2 -> V_68 ;
V_2 -> V_68 = 1 ;
V_2 -> V_86 -> V_98 ( V_2 , 0 ) ;
if ( V_68 && ! V_106 ) {
if ( V_2 -> V_66 == V_80 ) {
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
F_43 ( V_2 -> V_10 -> V_9 ,
L_39
L_40 , V_2 -> V_27 . V_28 ) ;
V_23 = V_44 ;
goto V_109;
} else {
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
return;
}
}
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
if ( ! F_62 ( V_2 ) ) {
if ( ! V_106 && V_2 -> V_86 -> V_110 )
V_23 = V_2 -> V_86 -> V_110 ( V_2 ) ;
if ( V_23 == V_111 )
return;
F_27 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
if ( V_2 -> V_66 == V_99 ) {
V_2 -> V_66 = V_67 ;
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
V_2 -> V_68 = 0 ;
return;
}
V_108 = F_76 ( & V_2 -> V_27 . V_112 ) ;
V_2 -> V_43 = F_77 ( & V_108 -> V_43 ) ;
V_23 = F_60 ( V_2 , V_23 ) ;
if ( F_11 ( ! V_2 -> V_104 ) ) {
V_2 -> V_86 -> V_103 ( V_2 , V_2 -> V_101 ) ;
} else {
V_2 -> V_102 = 1 ;
V_2 -> V_86 -> V_103 ( V_2 , V_2 -> V_89 ) ;
V_2 -> V_104 = 0 ;
V_2 -> V_102 = 1 ;
}
F_14 ( V_2 , V_2 -> V_41 ) ;
F_64 ( V_2 , 1 ) ;
F_28 ( & V_2 -> V_10 -> V_49 , V_83 ) ;
} else {
if ( V_2 -> V_86 -> V_110 )
F_68 ( & V_2 -> V_78 , 1 ) ;
V_23 = V_44 ;
F_12 ( V_2 -> V_10 -> V_9 , L_41
L_42 , V_2 -> V_27 . V_28 ) ;
}
V_109:
V_2 -> V_68 = 0 ;
F_51 ( V_2 , V_23 != V_47 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 , 0 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_75 ( V_2 , 1 ) ;
}
int F_79 ( struct V_105 * V_27 ,
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_73 ( V_27 ) ;
if ( V_116 -> type != V_2 -> V_79 )
return - V_24 ;
return F_80 ( V_114 , V_116 , V_117 ) ;
}
int F_81 ( struct V_105 * V_27 ,
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
return F_82 ( V_114 , V_116 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_27 ) ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_118 * V_71 )
{
return F_86 ( V_71 , & V_2 -> V_27 ) ;
}
static int F_87 ( struct V_1 * V_2 , const char * V_28 ,
const struct V_119 * V_120 )
{
struct V_105 * V_27 = & V_2 -> V_27 ;
struct V_121 * V_122 = & V_27 -> V_112 ;
F_88 ( V_27 , V_120 ) ;
snprintf ( V_27 -> V_28 , V_123 , L_43 , V_28 ) ;
V_27 -> V_124 = 1 << 16 ;
V_27 -> V_48 |= V_125 | V_126 ;
F_89 ( V_27 , V_2 ) ;
V_2 -> V_127 . V_48 = V_128 ;
V_122 -> V_86 = NULL ;
return F_90 ( V_122 , 1 , & V_2 -> V_127 , 0 ) ;
}
int F_91 ( struct V_1 * V_2 , const char * V_28 ,
const struct V_119 * V_120 )
{
int V_23 ;
V_2 -> V_4 = F_92 ( V_35 , sizeof( * V_2 -> V_4 ) , V_64 ) ;
if ( ! V_2 -> V_4 )
return - V_63 ;
F_19 ( V_2 ) ;
F_93 ( & V_2 -> V_81 ) ;
F_68 ( & V_2 -> V_78 , 0 ) ;
V_23 = F_87 ( V_2 , V_28 , V_120 ) ;
if ( V_23 < 0 ) {
F_94 ( & V_2 -> V_81 ) ;
F_95 ( V_2 -> V_4 ) ;
}
return V_23 ;
}
void F_96 ( struct V_1 * V_2 )
{
F_97 ( & V_2 -> V_27 . V_112 ) ;
F_94 ( & V_2 -> V_81 ) ;
F_34 ( V_2 ) ;
F_95 ( V_2 -> V_4 ) ;
}
