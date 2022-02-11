static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , enum V_6 V_7 ,
void (* F_2)( struct V_8 * ,
T_2 , unsigned long , T_3 ,
enum V_6 ) )
{
F_2 ( V_2 -> V_9 -> V_10 , V_4 -> V_11 , 0 , V_12 , V_7 ) ;
F_2 ( V_2 -> V_9 -> V_10 , V_4 -> V_11 + ( V_5 & V_13 ) ,
V_5 & ~ V_13 , V_12 , V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
enum V_6 V_7 )
{
if ( F_4 ( V_2 ) )
return;
F_1 ( V_2 , V_4 , V_5 , V_7 ,
V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
enum V_6 V_7 )
{
if ( F_4 ( V_2 ) )
return;
F_1 ( V_2 , V_4 , V_5 , V_7 ,
V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 V_5 = F_7 ( V_2 ) ?
V_4 -> V_5 + V_16 : V_4 -> V_5 ;
T_4 * V_17 ;
T_4 * V_18 ;
int V_19 = - V_20 ;
F_5 ( V_2 , V_4 , V_5 , V_21 ) ;
for ( V_17 = V_4 -> V_22 , V_18 = V_17 + V_12 ; V_17 < V_18 ; V_17 ++ )
if ( F_8 ( * V_17 != V_23 ) )
V_19 = 0 ;
if ( V_19 ) {
F_9 ( V_2 -> V_9 -> V_10 , L_1
L_2 , V_2 -> V_24 . V_25 ) ;
return V_19 ;
}
for ( V_17 = V_4 -> V_22 + V_5 , V_18 = V_17 + V_12 ;
V_17 < V_18 ; V_17 ++ ) {
if ( F_10 ( * V_17 != V_23 ) ) {
F_9 ( V_2 -> V_9 -> V_10 , L_3
L_4 , V_2 -> V_24 . V_25 ) ;
return - V_20 ;
}
}
F_3 ( V_2 , V_4 , V_5 ,
V_21 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_1 V_5 = F_7 ( V_2 ) ?
V_2 -> V_5 + V_16 : V_2 -> V_5 ;
F_5 ( V_2 , V_4 , V_5 , V_21 ) ;
memset ( V_4 -> V_22 , V_23 , V_12 ) ;
memset ( V_4 -> V_22 + V_5 , V_23 , V_12 ) ;
F_3 ( V_2 , V_4 , V_5 ,
V_26 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_4 ( V_2 ) )
return;
F_13 ( V_2 -> V_9 -> V_10 , V_4 -> V_27 . V_28 ,
V_4 -> V_27 . V_29 , V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_4 ( V_2 ) )
return;
F_15 ( V_2 -> V_9 -> V_10 , V_4 -> V_27 . V_28 ,
V_4 -> V_27 . V_29 , V_21 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_2 -> V_4 [ V_30 ] . V_32 = 1 ;
}
static struct V_3 *
F_17 ( struct V_1 * V_2 , int V_33 )
{
struct V_3 * V_34 = NULL ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_3 * V_35 = & V_2 -> V_4 [ V_30 ] ;
if ( V_35 == V_2 -> V_36 || V_35 == V_2 -> V_37 )
continue;
if ( ! V_33 && V_35 -> V_32 )
continue;
if ( V_35 -> V_32 ) {
V_34 = V_35 ;
break;
}
if ( ! V_34 ||
( V_38 ) V_35 -> V_39 - ( V_38 ) V_34 -> V_39 < 0 )
V_34 = V_35 ;
}
return V_34 ;
}
static inline struct V_3 *
F_18 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , 0 ) ;
}
static inline struct V_3 *
F_19 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , 1 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_37 )
return V_40 ;
F_21 ( & V_2 -> V_37 -> V_41 ) ;
V_2 -> V_37 -> V_5 = V_2 -> V_5 ;
if ( F_6 ( V_2 , V_2 -> V_37 ) ) {
F_9 ( V_2 -> V_9 -> V_10 , L_5 ,
V_2 -> V_24 . V_25 ) ;
return V_40 ;
}
V_2 -> V_37 -> V_42 = V_2 -> V_42 ;
V_2 -> V_37 -> V_39 = V_2 -> V_39 ;
V_2 -> V_37 -> V_32 = 0 ;
V_2 -> V_37 = NULL ;
return V_43 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_37 ) )
F_9 ( V_2 -> V_9 -> V_10 , L_6
L_7 ,
V_2 -> V_24 . V_25 ) ;
else
V_2 -> V_37 = F_19 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_12 ( V_2 , V_2 -> V_36 ) ;
F_24 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
V_2 -> V_36 = NULL ;
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
}
static struct V_3 * F_26 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
int V_48 = 0 ;
unsigned long V_44 ;
struct V_3 * V_4 ;
F_24 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
while ( 1 ) {
V_4 = F_18 ( V_2 ) ;
if ( ! V_4 ) {
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_8 ,
V_2 -> V_24 . V_25 ) ;
return F_27 ( - V_49 ) ;
}
if ( F_6 ( V_2 , V_4 ) ) {
F_9 ( V_2 -> V_9 -> V_10 , L_9
L_10 , V_2 -> V_24 . V_25 ) ;
V_4 -> V_32 = 1 ;
} else {
break;
}
}
V_2 -> V_36 = V_4 ;
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
if ( V_4 -> V_5 > V_47 -> V_5 ) {
F_28 ( V_2 -> V_9 -> V_10 , L_11
L_12 , V_2 -> V_24 . V_25 ) ;
F_23 ( V_2 ) ;
return F_27 ( - V_20 ) ;
}
F_14 ( V_2 , V_4 ) ;
V_48 = F_29 ( V_47 -> V_4 ,
V_4 -> V_22 ,
V_4 -> V_5 ) ;
if ( V_48 ) {
F_30 ( V_2 -> V_9 -> V_10 ,
L_13 ,
V_2 -> V_24 . V_25 , V_48 ) ;
V_4 = F_27 ( - V_50 ) ;
F_23 ( V_2 ) ;
}
return V_4 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_10 = F_4 ( V_2 )
? NULL : V_2 -> V_9 -> V_10 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_3 * V_4 = & V_2 -> V_4 [ V_30 ] ;
if ( ! V_4 -> V_22 )
continue;
F_32 ( & V_4 -> V_27 ) ;
F_33 ( V_10 , V_2 -> V_51 , V_4 -> V_22 ,
V_4 -> V_11 ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_22 = NULL ;
V_4 -> V_32 = 1 ;
}
F_9 ( V_2 -> V_9 -> V_10 , L_14 ,
V_2 -> V_24 . V_25 ) ;
V_2 -> V_51 = 0 ;
V_2 -> V_37 = NULL ;
}
static int F_34 ( struct V_8 * V_10 ,
struct V_3 * V_4 ,
unsigned int V_52 )
{
int V_19 ;
V_4 -> V_22 = F_35 ( V_10 , V_52 , & V_4 -> V_11 ,
V_53 | V_54 ) ;
if ( ! V_4 -> V_22 )
return - V_55 ;
V_19 = F_36 ( V_10 , & V_4 -> V_27 , V_4 -> V_22 , V_4 -> V_11 ,
V_52 ) ;
if ( V_19 < 0 ) {
F_33 ( V_10 , V_52 , V_4 -> V_22 , V_4 -> V_11 ) ;
V_4 -> V_22 = NULL ;
V_4 -> V_11 = 0 ;
return V_19 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_8 * V_10 = F_4 ( V_2 )
? NULL : V_2 -> V_9 -> V_10 ;
unsigned long V_44 ;
unsigned int V_30 ;
F_24 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
F_38 ( V_2 -> V_36 != NULL ) ;
if ( V_2 -> V_51 >= V_52 ) {
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
return 0 ;
}
if ( V_2 -> V_56 != V_57 || V_2 -> V_58 ) {
F_30 ( V_2 -> V_9 -> V_10 ,
L_15 ,
V_2 -> V_24 . V_25 ) ;
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
return - V_49 ;
}
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
F_31 ( V_2 ) ;
V_2 -> V_51 = V_52 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_3 * V_4 = & V_2 -> V_4 [ V_30 ] ;
int V_19 ;
V_19 = F_34 ( V_10 , V_4 , V_52 ) ;
if ( V_19 < 0 ) {
F_39 ( V_2 -> V_9 -> V_10 ,
L_16 ,
V_2 -> V_24 . V_25 , V_30 ) ;
F_31 ( V_2 ) ;
return V_19 ;
}
V_4 -> V_32 = 1 ;
F_9 ( V_2 -> V_9 -> V_10 ,
L_17 ,
V_2 -> V_24 . V_25 , V_30 ,
( unsigned long ) V_4 -> V_11 ,
( unsigned long ) V_4 -> V_22 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_59 )
{
struct V_60 * V_61 = V_2 -> V_24 . V_62 ;
struct V_63 V_64 ;
struct V_65 * V_66 = ( void * ) V_64 . V_67 . V_47 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( ! V_59 ) {
V_66 -> V_39 = V_2 -> V_39 ;
V_66 -> V_42 = V_2 -> V_42 ;
} else {
V_66 -> V_68 = 1 ;
}
V_64 . type = V_2 -> V_69 ;
F_41 ( V_61 , & V_64 ) ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_56 != V_70 ) {
F_9 ( V_2 -> V_9 -> V_10 , L_18 ,
V_2 -> V_24 . V_25 ) ;
return - V_20 ;
}
F_43 ( & V_2 -> V_71 ) ;
V_4 = F_26 ( V_2 , V_47 ) ;
if ( F_44 ( V_4 ) ) {
F_45 ( & V_2 -> V_71 ) ;
return F_46 ( V_4 ) ;
}
V_47 -> V_41 . V_72 = V_4 -> V_41 . V_72 ;
V_47 -> V_41 . V_73 = V_4 -> V_41 . V_74 / V_75 ;
V_47 -> V_42 = V_4 -> V_42 ;
V_47 -> V_39 = V_4 -> V_39 ;
V_47 -> V_5 = V_4 -> V_5 ;
V_4 -> V_32 = 1 ;
F_23 ( V_2 ) ;
F_45 ( & V_2 -> V_71 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , void * V_76 )
{
int V_19 ;
unsigned long V_77 ;
struct V_78 * V_79 = V_76 ;
T_1 V_5 = V_79 -> V_5 ;
if ( ! V_76 ) {
F_9 ( V_2 -> V_9 -> V_10 , L_19 ,
V_2 -> V_24 . V_25 ) ;
return - V_20 ;
}
F_43 ( & V_2 -> V_71 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_20
L_21 , V_2 -> V_24 . V_25 , ( unsigned long ) V_5 ) ;
V_19 = V_2 -> V_80 -> V_81 ( V_2 , V_76 ) ;
if ( V_19 ) {
F_45 ( & V_2 -> V_71 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_22
L_23 , V_2 -> V_24 . V_25 ) ;
return V_19 ;
}
if ( V_5 != V_79 -> V_5 )
F_9 ( V_2 -> V_9 -> V_10 , L_24
L_25 , V_2 -> V_24 . V_25 ,
( unsigned long ) V_79 -> V_5 ) ;
if ( F_48 ( V_2 ) ) {
V_5 = V_79 -> V_5 * 2 + V_12 ;
if ( F_7 ( V_2 ) )
V_5 += V_16 * ( V_82 + 2 ) ;
if ( V_2 -> V_83 ) {
struct V_78 * V_84 =
V_2 -> V_83 ;
V_5 += V_84 -> V_5 *
V_82 ;
}
V_5 = F_49 ( V_5 ) ;
} else {
V_5 = F_49 ( V_79 -> V_5 + V_12 ) ;
}
V_19 = F_37 ( V_2 , V_5 ) ;
if ( V_19 ) {
F_45 ( & V_2 -> V_71 ) ;
return V_19 ;
}
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
V_2 -> V_80 -> V_85 ( V_2 , V_76 ) ;
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
V_79 -> V_42 = V_2 -> V_42 + V_2 -> V_86 ;
V_2 -> V_87 = 1 ;
F_9 ( V_2 -> V_9 -> V_10 , L_26
L_27 , V_2 -> V_24 . V_25 ) ;
F_45 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_88 )
{
int V_19 = V_40 ;
if ( ! F_51 ( & V_2 -> V_68 , - 1 , 0 ) &&
V_88 == V_43 && V_2 -> V_56 == V_70 ) {
V_19 = F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
}
return V_19 ;
}
int F_52 ( struct V_1 * V_2 )
{
return V_2 -> V_80 -> V_89 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
return F_52 ( V_2 ) | V_2 -> V_58 |
( V_2 -> V_56 != V_57 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_4 V_90 )
{
if ( ( V_2 -> V_56 != V_91 &&
V_2 -> V_56 != V_70 ) && V_90 )
return;
V_2 -> V_80 -> V_92 ( V_2 , V_90 ) ;
if ( V_2 -> V_56 == V_93 && ! V_90 )
V_2 -> V_56 = V_57 ;
else if ( V_2 -> V_56 == V_91 && V_90 )
V_2 -> V_56 = V_70 ;
}
void F_55 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_24 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
if ( V_2 -> V_56 != V_57 )
V_2 -> V_80 -> V_92 ( V_2 , 0 ) ;
if ( V_2 -> V_56 == V_70 )
V_2 -> V_56 = V_94 ;
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 == V_94 )
V_2 -> V_56 = V_91 ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned long V_77 ;
if ( V_2 -> V_95 == NULL )
return;
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
if ( V_2 -> V_56 == V_91 && ! V_2 -> V_58 &&
V_2 -> V_51 ) {
V_2 -> V_96 = 1 ;
F_22 ( V_2 ) ;
V_2 -> V_80 -> V_97 ( V_2 , V_2 -> V_95 ) ;
F_11 ( V_2 , V_2 -> V_37 ) ;
if ( ! F_48 ( V_2 ) )
F_58 ( & V_2 -> V_68 , 0 ) ;
F_54 ( V_2 , 1 ) ;
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_28 ,
V_2 -> V_24 . V_25 ) ;
} else {
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
unsigned long V_77 ;
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
F_58 ( & V_2 -> V_68 , 2 ) ;
if ( V_2 -> V_83 )
V_2 -> V_98 = 1 ;
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
}
int F_61 ( struct V_1 * V_2 , T_4 V_92 )
{
unsigned long V_77 ;
F_9 ( V_2 -> V_9 -> V_10 , L_29 ,
V_2 -> V_24 . V_25 , V_92 ? L_30 : L_31 ) ;
F_43 ( & V_2 -> V_71 ) ;
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
if ( ! V_2 -> V_87 && V_92 ) {
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
F_45 ( & V_2 -> V_71 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_32
L_33 ,
V_2 -> V_24 . V_25 ) ;
return - V_20 ;
}
if ( V_92 ) {
if ( V_2 -> V_56 == V_93 )
V_2 -> V_56 = V_70 ;
else if ( V_2 -> V_56 == V_57 )
V_2 -> V_56 = V_91 ;
} else {
if ( V_2 -> V_56 == V_91 ) {
V_2 -> V_56 = V_57 ;
} else if ( V_2 -> V_56 == V_70 ) {
V_2 -> V_56 = V_93 ;
F_16 ( V_2 ) ;
}
}
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
F_45 ( & V_2 -> V_71 ) ;
return 0 ;
}
int F_62 ( struct V_99 * V_24 , int V_92 )
{
struct V_1 * V_2 = F_63 ( V_24 ) ;
if ( V_92 ) {
F_57 ( V_2 ) ;
} else {
unsigned long V_44 ;
F_61 ( V_2 , 0 ) ;
F_24 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
V_2 -> V_80 -> V_92 ( V_2 , 0 ) ;
F_25 ( & V_2 -> V_9 -> V_45 , V_44 ) ;
if ( ! F_52 ( V_2 ) )
F_64 ( V_2 ) ;
F_9 ( V_2 -> V_9 -> V_10 , L_34 ,
V_2 -> V_24 . V_25 ) ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , int V_100 )
{
int V_19 = V_43 ;
int V_58 ;
unsigned long V_77 ;
struct V_101 * V_102 ;
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
if ( V_2 -> V_56 == V_57 ) {
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
return;
}
V_58 = V_2 -> V_58 ;
V_2 -> V_58 = 1 ;
V_2 -> V_80 -> V_92 ( V_2 , 0 ) ;
if ( V_58 && ! V_100 ) {
if ( V_2 -> V_56 == V_70 ) {
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
F_39 ( V_2 -> V_9 -> V_10 ,
L_35
L_36 , V_2 -> V_24 . V_25 ) ;
V_19 = V_40 ;
goto V_103;
} else {
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
return;
}
}
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
if ( ! F_52 ( V_2 ) ) {
if ( ! V_100 && V_2 -> V_80 -> V_104 )
V_19 = V_2 -> V_80 -> V_104 ( V_2 ) ;
if ( V_19 == V_105 )
return;
F_24 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
if ( V_2 -> V_56 == V_93 ) {
V_2 -> V_56 = V_57 ;
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
V_2 -> V_58 = 0 ;
return;
}
V_102 = F_66 ( & V_2 -> V_24 . V_106 ) ;
V_2 -> V_39 = F_67 ( & V_102 -> V_39 ) ;
V_19 = F_50 ( V_2 , V_19 ) ;
if ( F_8 ( ! V_2 -> V_98 ) ) {
V_2 -> V_80 -> V_97 ( V_2 , V_2 -> V_95 ) ;
} else {
V_2 -> V_96 = 1 ;
V_2 -> V_80 -> V_97 ( V_2 , V_2 -> V_83 ) ;
V_2 -> V_98 = 0 ;
V_2 -> V_96 = 1 ;
}
F_11 ( V_2 , V_2 -> V_37 ) ;
F_54 ( V_2 , 1 ) ;
F_25 ( & V_2 -> V_9 -> V_45 , V_77 ) ;
} else {
if ( V_2 -> V_80 -> V_104 )
F_58 ( & V_2 -> V_68 , 1 ) ;
V_19 = V_40 ;
F_9 ( V_2 -> V_9 -> V_10 , L_37
L_38 , V_2 -> V_24 . V_25 ) ;
}
V_103:
V_2 -> V_58 = 0 ;
F_40 ( V_2 , V_19 != V_43 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 , 0 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_65 ( V_2 , 1 ) ;
}
int F_69 ( struct V_99 * V_24 ,
struct V_107 * V_108 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = F_63 ( V_24 ) ;
if ( V_110 -> type != V_2 -> V_69 )
return - V_20 ;
return F_70 ( V_108 , V_110 , V_111 , NULL ) ;
}
int F_71 ( struct V_99 * V_24 ,
struct V_107 * V_108 ,
struct V_109 * V_110 )
{
return F_72 ( V_108 , V_110 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( & V_2 -> V_24 ) ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_112 * V_61 )
{
return F_76 ( V_61 , & V_2 -> V_24 ) ;
}
static int F_77 ( struct V_1 * V_2 , const char * V_25 ,
const struct V_113 * V_114 )
{
struct V_99 * V_24 = & V_2 -> V_24 ;
struct V_115 * V_116 = & V_24 -> V_106 ;
F_78 ( V_24 , V_114 ) ;
snprintf ( V_24 -> V_25 , V_117 , L_39 , V_25 ) ;
V_24 -> V_118 = 1 << 16 ;
V_24 -> V_44 |= V_119 | V_120 ;
F_79 ( V_24 , V_2 ) ;
V_2 -> V_121 . V_44 = V_122 | V_123 ;
V_116 -> V_80 = NULL ;
return F_80 ( V_116 , 1 , & V_2 -> V_121 , 0 ) ;
}
int F_81 ( struct V_1 * V_2 , const char * V_25 ,
const struct V_113 * V_114 )
{
int V_19 ;
V_2 -> V_4 = F_82 ( V_31 , sizeof( * V_2 -> V_4 ) , V_53 ) ;
if ( ! V_2 -> V_4 )
return - V_55 ;
F_16 ( V_2 ) ;
F_83 ( & V_2 -> V_71 ) ;
F_58 ( & V_2 -> V_68 , 0 ) ;
V_19 = F_77 ( V_2 , V_25 , V_114 ) ;
if ( V_19 < 0 ) {
F_84 ( & V_2 -> V_71 ) ;
F_85 ( V_2 -> V_4 ) ;
}
return V_19 ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( & V_2 -> V_24 . V_106 ) ;
F_84 ( & V_2 -> V_71 ) ;
F_31 ( V_2 ) ;
F_85 ( V_2 -> V_4 ) ;
}
