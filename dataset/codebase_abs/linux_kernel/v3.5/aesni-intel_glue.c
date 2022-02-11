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
static int F_41 ( struct V_37 * V_3 , const V_4 * V_38 ,
unsigned int V_12 )
{
struct V_39 * V_13 = F_42 ( V_3 ) ;
struct V_37 * V_40 = & V_13 -> V_41 -> V_42 ;
int V_16 ;
F_43 ( V_40 , V_43 ) ;
F_44 ( V_40 , F_45 ( V_3 )
& V_43 ) ;
V_16 = F_46 ( V_40 , V_38 , V_12 ) ;
F_44 ( V_3 , F_45 ( V_40 )
& V_44 ) ;
return V_16 ;
}
static int F_47 ( struct V_45 * V_46 )
{
struct V_37 * V_3 = F_48 ( V_46 ) ;
struct V_39 * V_13 = F_42 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_45 * V_47 =
F_49 ( V_46 ) ;
memcpy ( V_47 , V_46 , sizeof( * V_46 ) ) ;
F_50 ( V_47 , & V_13 -> V_41 -> V_42 ) ;
return F_51 ( V_47 ) ;
} else {
struct V_24 V_25 ;
V_25 . V_3 = F_52 ( V_13 -> V_41 ) ;
V_25 . V_48 = V_46 -> V_48 ;
V_25 . V_14 = 0 ;
return F_53 ( V_25 . V_3 ) -> F_54 (
& V_25 , V_46 -> V_22 , V_46 -> V_23 , V_46 -> V_27 ) ;
}
}
static int F_55 ( struct V_45 * V_46 )
{
struct V_37 * V_3 = F_48 ( V_46 ) ;
struct V_39 * V_13 = F_42 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_45 * V_47 =
F_49 ( V_46 ) ;
memcpy ( V_47 , V_46 , sizeof( * V_46 ) ) ;
F_50 ( V_47 , & V_13 -> V_41 -> V_42 ) ;
return F_56 ( V_47 ) ;
} else {
struct V_24 V_25 ;
V_25 . V_3 = F_52 ( V_13 -> V_41 ) ;
V_25 . V_48 = V_46 -> V_48 ;
V_25 . V_14 = 0 ;
return F_53 ( V_25 . V_3 ) -> F_57 (
& V_25 , V_46 -> V_22 , V_46 -> V_23 , V_46 -> V_27 ) ;
}
}
static void F_58 ( struct V_10 * V_3 )
{
struct V_39 * V_13 = F_3 ( V_3 ) ;
F_59 ( V_13 -> V_41 ) ;
}
static int F_60 ( struct V_10 * V_3 , const char * V_49 )
{
struct V_39 * V_13 = F_3 ( V_3 ) ;
struct V_50 * V_41 ;
V_41 = F_61 ( V_49 , 0 , 0 ) ;
if ( F_62 ( V_41 ) )
return F_63 ( V_41 ) ;
V_13 -> V_41 = V_41 ;
V_3 -> V_51 . V_52 = sizeof( struct V_45 ) +
F_64 ( & V_41 -> V_42 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_1 ) ;
}
static int F_66 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_2 ) ;
}
static int F_67 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_3 ) ;
}
static int F_68 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_4 ) ;
}
static int F_69 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_5 ) ;
}
static int F_70 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_6 ) ;
}
static int F_71 ( struct V_10 * V_3 )
{
return F_60 ( V_3 , L_7 ) ;
}
static int F_72 ( struct V_10 * V_3 )
{
struct V_53 * V_41 ;
struct V_1 * V_13 = (struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
struct V_2 * V_54 ;
struct V_1 * V_55 ;
V_41 = F_73 ( L_8 , 0 , 0 ) ;
if ( F_62 ( V_41 ) )
return F_63 ( V_41 ) ;
V_54 = F_74 ( V_41 ) ;
V_55 = F_1 ( V_54 ) ;
memcpy ( V_55 , V_13 , sizeof( * V_13 ) ) ;
V_13 -> V_41 = V_41 ;
V_3 -> V_56 . V_52 = sizeof( struct V_57 )
+ F_75 ( & V_41 -> V_42 ) ;
return 0 ;
}
static void F_76 ( struct V_10 * V_3 )
{
struct V_1 * V_13 =
(struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
if ( ! F_62 ( V_13 -> V_41 ) )
F_77 ( V_13 -> V_41 ) ;
return;
}
static void
F_78 ( struct V_58 * V_46 , int V_16 )
{
struct V_59 * V_60 = V_46 -> V_61 ;
if ( V_16 == - V_62 )
return;
V_60 -> V_16 = V_16 ;
F_79 ( & V_60 -> V_63 ) ;
}
static int
F_80 ( V_4 * V_64 , const V_4 * V_38 , unsigned int V_12 )
{
struct V_37 * V_65 ;
struct V_45 * V_46 ;
int V_66 = - V_21 ;
struct V_67 * V_68 ;
V_65 = F_81 ( L_9 , 0 , 0 ) ;
if ( F_62 ( V_65 ) )
return F_63 ( V_65 ) ;
F_43 ( V_65 , ~ 0 ) ;
V_66 = F_46 ( V_65 , V_38 , V_12 ) ;
if ( V_66 )
goto V_69;
V_66 = - V_70 ;
V_46 = F_82 ( V_65 , V_71 ) ;
if ( ! V_46 )
goto V_69;
V_68 = F_83 ( sizeof( * V_68 ) , V_71 ) ;
if ( ! V_68 )
goto V_72;
memset ( V_68 -> V_34 , 0 , sizeof( V_68 -> V_34 ) ) ;
memset ( V_64 , 0 , V_73 ) ;
F_84 ( & V_68 -> V_60 . V_63 ) ;
F_85 ( & V_68 -> V_74 , V_64 , V_73 ) ;
F_50 ( V_46 , V_65 ) ;
F_86 ( V_46 , V_30 |
V_75 ,
F_78 ,
& V_68 -> V_60 ) ;
F_87 ( V_46 , & V_68 -> V_74 ,
& V_68 -> V_74 , V_73 , V_68 -> V_34 ) ;
V_66 = F_51 ( V_46 ) ;
if ( V_66 == - V_62 || V_66 == - V_76 ) {
V_66 = F_88
( & V_68 -> V_60 . V_63 ) ;
if ( ! V_66 )
V_66 = V_68 -> V_60 . V_16 ;
}
F_89 ( V_68 ) ;
V_72:
F_90 ( V_46 ) ;
V_69:
F_91 ( V_65 ) ;
return V_66 ;
}
static int F_92 ( struct V_2 * V_77 , const V_4 * V_38 ,
unsigned int V_12 )
{
int V_66 = 0 ;
struct V_10 * V_3 = F_4 ( V_77 ) ;
struct V_1 * V_13 = F_1 ( V_77 ) ;
struct V_2 * V_54 = F_74 ( V_13 -> V_41 ) ;
struct V_1 * V_55 =
F_1 ( V_54 ) ;
V_4 * V_78 = NULL ;
if ( V_12 < 4 ) {
F_93 ( V_3 , V_20 ) ;
return - V_21 ;
}
V_12 -= 4 ;
if ( V_12 != V_17 ) {
F_93 ( V_3 , V_20 ) ;
return - V_21 ;
}
memcpy ( V_13 -> V_79 , V_38 + V_12 , sizeof( V_13 -> V_79 ) ) ;
if ( ( unsigned long ) ( & ( V_13 -> V_80 . V_81 [ 0 ] ) ) % V_5 )
return - V_21 ;
if ( ( unsigned long ) V_38 % V_5 ) {
V_78 = F_83 ( V_12 + V_5 , V_71 ) ;
if ( ! V_78 )
return - V_70 ;
V_78 = F_2 ( V_78 , V_5 ) ;
memcpy ( V_78 , V_38 , V_12 ) ;
V_38 = V_78 ;
}
if ( ! F_9 () )
V_66 = F_10 ( & ( V_13 -> V_80 ) ,
V_38 , V_12 ) ;
else {
F_11 () ;
V_66 = F_12 ( & ( V_13 -> V_80 ) , V_38 , V_12 ) ;
F_13 () ;
}
if ( ( unsigned long ) ( & ( V_13 -> V_64 [ 0 ] ) ) % V_5 ) {
V_66 = - V_21 ;
goto exit;
}
V_66 = F_80 ( V_13 -> V_64 , V_38 , V_12 ) ;
memcpy ( V_55 , V_13 , sizeof( * V_13 ) ) ;
exit:
F_89 ( V_78 ) ;
return V_66 ;
}
static int F_94 ( struct V_2 * V_77 ,
unsigned int V_82 )
{
struct V_1 * V_13 = F_1 ( V_77 ) ;
struct V_2 * V_54 = F_74 ( V_13 -> V_41 ) ;
switch ( V_82 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_21 ;
}
F_95 ( V_77 ) -> V_82 = V_82 ;
F_95 ( V_54 ) -> V_82 = V_82 ;
return 0 ;
}
static int F_96 ( struct V_57 * V_46 )
{
int V_66 ;
struct V_2 * V_3 = F_97 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_57 * V_47 =
(struct V_57 * ) F_98 ( V_46 ) ;
memcpy ( V_47 , V_46 , sizeof( * V_46 ) ) ;
F_99 ( V_47 , & V_13 -> V_41 -> V_42 ) ;
return F_100 ( V_47 ) ;
} else {
struct V_2 * V_54 = F_74 ( V_13 -> V_41 ) ;
F_11 () ;
V_66 = V_54 -> V_42 . V_56 . F_54 ( V_46 ) ;
F_13 () ;
return V_66 ;
}
}
static int F_101 ( struct V_57 * V_46 )
{
int V_66 ;
struct V_2 * V_3 = F_97 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_57 * V_47 =
(struct V_57 * ) F_98 ( V_46 ) ;
memcpy ( V_47 , V_46 , sizeof( * V_46 ) ) ;
F_99 ( V_47 , & V_13 -> V_41 -> V_42 ) ;
return F_102 ( V_47 ) ;
} else {
struct V_2 * V_54 = F_74 ( V_13 -> V_41 ) ;
F_11 () ;
V_66 = V_54 -> V_42 . V_56 . F_57 ( V_46 ) ;
F_13 () ;
return V_66 ;
}
}
static int F_103 ( struct V_57 * V_46 )
{
V_4 V_83 = 0 ;
V_4 * V_23 , * V_22 , * V_84 ;
T_2 V_85 = F_104 ( 1 ) ;
struct V_2 * V_3 = F_97 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_80 ) ;
unsigned long V_86 = F_105 ( V_3 ) ;
V_4 V_87 [ 16 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_87 , V_5 ) ;
struct V_88 V_89 ;
struct V_88 V_90 ;
struct V_88 V_91 ;
unsigned int V_92 ;
if ( F_106 ( V_46 -> V_93 != 8 && V_46 -> V_93 != 12 ) )
return - V_21 ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ )
* ( V_34 + V_92 ) = V_13 -> V_79 [ V_92 ] ;
for ( V_92 = 0 ; V_92 < 8 ; V_92 ++ )
* ( V_34 + 4 + V_92 ) = V_46 -> V_34 [ V_92 ] ;
* ( ( T_2 * ) ( V_34 + 12 ) ) = V_85 ;
if ( ( F_107 ( V_46 -> V_23 ) ) && ( F_107 ( V_46 -> V_84 ) ) ) {
V_83 = 1 ;
F_108 ( & V_89 , V_46 -> V_23 ) ;
F_108 ( & V_90 , V_46 -> V_84 ) ;
V_23 = F_109 ( & V_89 ) ;
V_84 = F_109 ( & V_90 ) ;
V_22 = V_23 ;
if ( F_106 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_108 ( & V_91 , V_46 -> V_22 ) ;
V_22 = F_109 ( & V_91 ) ;
}
} else {
V_23 = F_83 ( V_46 -> V_94 + V_86 + V_46 -> V_93 ,
V_95 ) ;
if ( F_106 ( ! V_23 ) )
return - V_70 ;
V_84 = ( V_23 + V_46 -> V_94 + V_86 ) ;
F_110 ( V_23 , V_46 -> V_23 , 0 , V_46 -> V_94 , 0 ) ;
F_110 ( V_84 , V_46 -> V_84 , 0 ,
V_46 -> V_93 , 0 ) ;
V_22 = V_23 ;
}
F_111 ( F_5 , V_22 , V_23 , ( unsigned long ) V_46 -> V_94 , V_34 ,
V_13 -> V_64 , V_84 , ( unsigned long ) V_46 -> V_93 , V_22
+ ( ( unsigned long ) V_46 -> V_94 ) , V_86 ) ;
if ( V_83 ) {
if ( F_106 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_112 ( V_22 ) ;
F_113 ( & V_91 , 0 , 0 ) ;
}
F_112 ( V_23 ) ;
F_112 ( V_84 ) ;
F_113 ( & V_89 , 0 , 0 ) ;
F_113 ( & V_90 , 0 , 0 ) ;
} else {
F_110 ( V_22 , V_46 -> V_22 , 0 ,
V_46 -> V_94 + V_86 , 1 ) ;
F_89 ( V_23 ) ;
}
return 0 ;
}
static int F_114 ( struct V_57 * V_46 )
{
V_4 V_83 = 0 ;
V_4 * V_23 , * V_22 , * V_84 ;
unsigned long V_96 = 0 ;
T_2 V_85 = F_104 ( 1 ) ;
int V_97 = 0 ;
struct V_2 * V_3 = F_97 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_80 ) ;
unsigned long V_86 = F_105 ( V_3 ) ;
V_4 V_98 [ 32 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_98 , V_5 ) ;
V_4 * V_99 = V_34 + 16 ;
struct V_88 V_89 ;
struct V_88 V_90 ;
struct V_88 V_91 ;
unsigned int V_92 ;
if ( F_106 ( ( V_46 -> V_94 < V_86 ) ||
( V_46 -> V_93 != 8 && V_46 -> V_93 != 12 ) ) )
return - V_21 ;
V_96 = ( unsigned long ) ( V_46 -> V_94 - V_86 ) ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ )
* ( V_34 + V_92 ) = V_13 -> V_79 [ V_92 ] ;
for ( V_92 = 0 ; V_92 < 8 ; V_92 ++ )
* ( V_34 + 4 + V_92 ) = V_46 -> V_34 [ V_92 ] ;
* ( ( T_2 * ) ( V_34 + 12 ) ) = V_85 ;
if ( ( F_107 ( V_46 -> V_23 ) ) && ( F_107 ( V_46 -> V_84 ) ) ) {
V_83 = 1 ;
F_108 ( & V_89 , V_46 -> V_23 ) ;
F_108 ( & V_90 , V_46 -> V_84 ) ;
V_23 = F_109 ( & V_89 ) ;
V_84 = F_109 ( & V_90 ) ;
V_22 = V_23 ;
if ( F_106 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_108 ( & V_91 , V_46 -> V_22 ) ;
V_22 = F_109 ( & V_91 ) ;
}
} else {
V_23 = F_83 ( V_46 -> V_94 + V_46 -> V_93 , V_95 ) ;
if ( ! V_23 )
return - V_70 ;
V_84 = ( V_23 + V_46 -> V_94 + V_86 ) ;
F_110 ( V_23 , V_46 -> V_23 , 0 , V_46 -> V_94 , 0 ) ;
F_110 ( V_84 , V_46 -> V_84 , 0 ,
V_46 -> V_93 , 0 ) ;
V_22 = V_23 ;
}
F_115 ( F_5 , V_22 , V_23 , V_96 , V_34 ,
V_13 -> V_64 , V_84 , ( unsigned long ) V_46 -> V_93 ,
V_99 , V_86 ) ;
V_97 = memcmp ( V_23 + V_96 , V_99 , V_86 ) ?
- V_100 : 0 ;
if ( V_83 ) {
if ( F_106 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_112 ( V_22 ) ;
F_113 ( & V_91 , 0 , 0 ) ;
}
F_112 ( V_23 ) ;
F_112 ( V_84 ) ;
F_113 ( & V_89 , 0 , 0 ) ;
F_113 ( & V_90 , 0 , 0 ) ;
} else {
F_110 ( V_22 , V_46 -> V_22 , 0 , V_46 -> V_94 , 1 ) ;
F_89 ( V_23 ) ;
}
return V_97 ;
}
static int T_3 F_116 ( void )
{
int V_16 , V_92 ;
if ( ! F_117 ( V_101 ) )
return - V_102 ;
V_16 = F_118 () ;
if ( V_16 )
return V_16 ;
for ( V_92 = 0 ; V_92 < F_119 ( V_103 ) ; V_92 ++ )
F_120 ( & V_103 [ V_92 ] . V_104 ) ;
return F_121 ( V_103 , F_119 ( V_103 ) ) ;
}
static void T_4 F_122 ( void )
{
F_123 ( V_103 , F_119 ( V_103 ) ) ;
F_124 () ;
}
