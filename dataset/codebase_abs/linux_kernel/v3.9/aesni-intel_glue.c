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
static int F_41 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_1 ) ;
}
static int F_43 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_2 ) ;
}
static int F_44 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_3 ) ;
}
static int F_45 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_4 ) ;
}
static void F_46 ( void * V_13 , V_4 * V_37 , unsigned int V_27 )
{
F_27 ( V_13 , V_37 , V_37 , V_27 ) ;
}
static void F_47 ( void * V_13 , V_4 * V_37 , unsigned int V_27 )
{
F_30 ( V_13 , V_37 , V_37 , V_27 ) ;
}
static int F_48 ( struct V_10 * V_3 , const V_4 * V_38 ,
unsigned int V_39 )
{
struct V_40 * V_13 = F_3 ( V_3 ) ;
int V_16 ;
V_16 = F_8 ( V_3 , V_13 -> V_41 , V_38 ,
V_39 - V_33 ) ;
if ( V_16 )
return V_16 ;
return F_49 ( & V_13 -> V_42 , V_38 + V_39 - V_33 ) ;
}
static void F_50 ( struct V_10 * V_3 )
{
struct V_40 * V_13 = F_3 ( V_3 ) ;
F_51 ( & V_13 -> V_42 ) ;
}
static int F_52 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_40 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_44 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_48 = & V_13 -> V_42 ,
. V_49 = F_5 ( V_13 -> V_41 ) ,
. V_50 = F_46 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_53 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_54 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_40 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_44 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_48 = & V_13 -> V_42 ,
. V_49 = F_5 ( V_13 -> V_41 ) ,
. V_50 = F_47 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_53 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_55 ( struct V_10 * V_3 , const V_4 * V_38 ,
unsigned int V_39 )
{
struct V_52 * V_13 = F_3 ( V_3 ) ;
T_1 * V_14 = & V_3 -> V_15 ;
int V_16 ;
if ( V_39 % 2 ) {
* V_14 |= V_20 ;
return - V_21 ;
}
V_16 = F_8 ( V_3 , V_13 -> V_53 , V_38 , V_39 / 2 ) ;
if ( V_16 )
return V_16 ;
return F_8 ( V_3 , V_13 -> V_54 , V_38 + V_39 / 2 ,
V_39 / 2 ) ;
}
static void F_56 ( void * V_13 , V_4 * V_55 , const V_4 * V_56 )
{
F_17 ( V_13 , V_55 , V_56 ) ;
}
static int F_57 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_57 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_58 = F_5 ( V_13 -> V_54 ) ,
. V_59 = F_56 ,
. V_49 = F_5 ( V_13 -> V_53 ) ,
. V_50 = F_46 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_58 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_59 ( struct V_24 * V_25 , struct V_26 * V_22 ,
struct V_26 * V_23 , unsigned int V_27 )
{
struct V_52 * V_13 = F_24 ( V_25 -> V_3 ) ;
T_2 V_43 [ 8 ] ;
struct V_57 V_45 = {
. V_46 = V_43 ,
. V_47 = sizeof( V_43 ) ,
. V_58 = F_5 ( V_13 -> V_54 ) ,
. V_59 = F_56 ,
. V_49 = F_5 ( V_13 -> V_53 ) ,
. V_50 = F_47 ,
} ;
int V_51 ;
V_25 -> V_14 &= ~ V_30 ;
F_11 () ;
V_51 = F_58 ( V_25 , V_22 , V_23 , V_27 , & V_45 ) ;
F_13 () ;
return V_51 ;
}
static int F_60 ( struct V_10 * V_3 )
{
struct V_60 * V_61 ;
struct V_1 * V_13 = (struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
struct V_2 * V_62 ;
struct V_1 * V_63 ;
V_61 = F_61 ( L_5 , 0 , 0 ) ;
if ( F_62 ( V_61 ) )
return F_63 ( V_61 ) ;
V_62 = F_64 ( V_61 ) ;
V_63 = F_1 ( V_62 ) ;
memcpy ( V_63 , V_13 , sizeof( * V_13 ) ) ;
V_13 -> V_61 = V_61 ;
V_3 -> V_64 . V_65 = sizeof( struct V_66 )
+ F_65 ( & V_61 -> V_67 ) ;
return 0 ;
}
static void F_66 ( struct V_10 * V_3 )
{
struct V_1 * V_13 =
(struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
if ( ! F_62 ( V_13 -> V_61 ) )
F_67 ( V_13 -> V_61 ) ;
return;
}
static void
F_68 ( struct V_68 * V_45 , int V_16 )
{
struct V_69 * V_70 = V_45 -> V_71 ;
if ( V_16 == - V_72 )
return;
V_70 -> V_16 = V_16 ;
F_69 ( & V_70 -> V_73 ) ;
}
static int
F_70 ( V_4 * V_74 , const V_4 * V_38 , unsigned int V_12 )
{
struct V_75 * V_76 ;
struct V_77 * V_45 ;
int V_51 = - V_21 ;
struct V_78 * V_79 ;
V_76 = F_71 ( L_6 , 0 , 0 ) ;
if ( F_62 ( V_76 ) )
return F_63 ( V_76 ) ;
F_72 ( V_76 , ~ 0 ) ;
V_51 = F_73 ( V_76 , V_38 , V_12 ) ;
if ( V_51 )
goto V_80;
V_51 = - V_81 ;
V_45 = F_74 ( V_76 , V_82 ) ;
if ( ! V_45 )
goto V_80;
V_79 = F_75 ( sizeof( * V_79 ) , V_82 ) ;
if ( ! V_79 )
goto V_83;
memset ( V_79 -> V_34 , 0 , sizeof( V_79 -> V_34 ) ) ;
memset ( V_74 , 0 , V_84 ) ;
F_76 ( & V_79 -> V_70 . V_73 ) ;
F_77 ( & V_79 -> V_85 , V_74 , V_84 ) ;
F_78 ( V_45 , V_76 ) ;
F_79 ( V_45 , V_30 |
V_86 ,
F_68 ,
& V_79 -> V_70 ) ;
F_80 ( V_45 , & V_79 -> V_85 ,
& V_79 -> V_85 , V_84 , V_79 -> V_34 ) ;
V_51 = F_81 ( V_45 ) ;
if ( V_51 == - V_72 || V_51 == - V_87 ) {
V_51 = F_82
( & V_79 -> V_70 . V_73 ) ;
if ( ! V_51 )
V_51 = V_79 -> V_70 . V_16 ;
}
F_83 ( V_79 ) ;
V_83:
F_84 ( V_45 ) ;
V_80:
F_85 ( V_76 ) ;
return V_51 ;
}
static int F_86 ( struct V_2 * V_88 , const V_4 * V_38 ,
unsigned int V_12 )
{
int V_51 = 0 ;
struct V_10 * V_3 = F_4 ( V_88 ) ;
struct V_1 * V_13 = F_1 ( V_88 ) ;
struct V_2 * V_62 = F_64 ( V_13 -> V_61 ) ;
struct V_1 * V_63 =
F_1 ( V_62 ) ;
V_4 * V_89 , * V_90 = NULL ;
if ( V_12 < 4 ) {
F_87 ( V_3 , V_20 ) ;
return - V_21 ;
}
V_12 -= 4 ;
if ( V_12 != V_17 ) {
F_87 ( V_3 , V_20 ) ;
return - V_21 ;
}
memcpy ( V_13 -> V_91 , V_38 + V_12 , sizeof( V_13 -> V_91 ) ) ;
if ( ( unsigned long ) ( & ( V_13 -> V_92 . V_93 [ 0 ] ) ) % V_5 )
return - V_21 ;
if ( ( unsigned long ) V_38 % V_5 ) {
V_90 = F_75 ( V_12 + V_5 , V_82 ) ;
if ( ! V_90 )
return - V_81 ;
V_89 = F_2 ( V_90 , V_5 ) ;
memcpy ( V_89 , V_38 , V_12 ) ;
V_38 = V_89 ;
}
if ( ! F_9 () )
V_51 = F_10 ( & ( V_13 -> V_92 ) ,
V_38 , V_12 ) ;
else {
F_11 () ;
V_51 = F_12 ( & ( V_13 -> V_92 ) , V_38 , V_12 ) ;
F_13 () ;
}
if ( ( unsigned long ) ( & ( V_13 -> V_74 [ 0 ] ) ) % V_5 ) {
V_51 = - V_21 ;
goto exit;
}
V_51 = F_70 ( V_13 -> V_74 , V_38 , V_12 ) ;
memcpy ( V_63 , V_13 , sizeof( * V_13 ) ) ;
exit:
F_83 ( V_90 ) ;
return V_51 ;
}
static int F_88 ( struct V_2 * V_88 ,
unsigned int V_94 )
{
struct V_1 * V_13 = F_1 ( V_88 ) ;
struct V_2 * V_62 = F_64 ( V_13 -> V_61 ) ;
switch ( V_94 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_21 ;
}
F_89 ( V_88 ) -> V_94 = V_94 ;
F_89 ( V_62 ) -> V_94 = V_94 ;
return 0 ;
}
static int F_90 ( struct V_66 * V_45 )
{
int V_51 ;
struct V_2 * V_3 = F_91 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_66 * V_95 =
(struct V_66 * ) F_92 ( V_45 ) ;
memcpy ( V_95 , V_45 , sizeof( * V_45 ) ) ;
F_93 ( V_95 , & V_13 -> V_61 -> V_67 ) ;
return F_94 ( V_95 ) ;
} else {
struct V_2 * V_62 = F_64 ( V_13 -> V_61 ) ;
F_11 () ;
V_51 = V_62 -> V_67 . V_64 . V_96 ( V_45 ) ;
F_13 () ;
return V_51 ;
}
}
static int F_95 ( struct V_66 * V_45 )
{
int V_51 ;
struct V_2 * V_3 = F_91 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_66 * V_95 =
(struct V_66 * ) F_92 ( V_45 ) ;
memcpy ( V_95 , V_45 , sizeof( * V_45 ) ) ;
F_93 ( V_95 , & V_13 -> V_61 -> V_67 ) ;
return F_96 ( V_95 ) ;
} else {
struct V_2 * V_62 = F_64 ( V_13 -> V_61 ) ;
F_11 () ;
V_51 = V_62 -> V_67 . V_64 . V_97 ( V_45 ) ;
F_13 () ;
return V_51 ;
}
}
static int F_97 ( struct V_66 * V_45 )
{
V_4 V_98 = 0 ;
V_4 * V_23 , * V_22 , * V_99 ;
T_3 V_100 = F_98 ( 1 ) ;
struct V_2 * V_3 = F_91 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_92 ) ;
unsigned long V_101 = F_99 ( V_3 ) ;
V_4 V_102 [ 16 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_102 , V_5 ) ;
struct V_103 V_104 ;
struct V_103 V_105 ;
struct V_103 V_106 ;
unsigned int V_107 ;
if ( F_100 ( V_45 -> V_108 != 8 && V_45 -> V_108 != 12 ) )
return - V_21 ;
for ( V_107 = 0 ; V_107 < 4 ; V_107 ++ )
* ( V_34 + V_107 ) = V_13 -> V_91 [ V_107 ] ;
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ )
* ( V_34 + 4 + V_107 ) = V_45 -> V_34 [ V_107 ] ;
* ( ( T_3 * ) ( V_34 + 12 ) ) = V_100 ;
if ( ( F_101 ( V_45 -> V_23 ) ) && ( F_101 ( V_45 -> V_99 ) ) ) {
V_98 = 1 ;
F_102 ( & V_104 , V_45 -> V_23 ) ;
F_102 ( & V_105 , V_45 -> V_99 ) ;
V_23 = F_103 ( & V_104 ) ;
V_99 = F_103 ( & V_105 ) ;
V_22 = V_23 ;
if ( F_100 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_102 ( & V_106 , V_45 -> V_22 ) ;
V_22 = F_103 ( & V_106 ) ;
}
} else {
V_23 = F_75 ( V_45 -> V_109 + V_101 + V_45 -> V_108 ,
V_110 ) ;
if ( F_100 ( ! V_23 ) )
return - V_81 ;
V_99 = ( V_23 + V_45 -> V_109 + V_101 ) ;
F_104 ( V_23 , V_45 -> V_23 , 0 , V_45 -> V_109 , 0 ) ;
F_104 ( V_99 , V_45 -> V_99 , 0 ,
V_45 -> V_108 , 0 ) ;
V_22 = V_23 ;
}
F_105 ( F_5 , V_22 , V_23 , ( unsigned long ) V_45 -> V_109 , V_34 ,
V_13 -> V_74 , V_99 , ( unsigned long ) V_45 -> V_108 , V_22
+ ( ( unsigned long ) V_45 -> V_109 ) , V_101 ) ;
if ( V_98 ) {
if ( F_100 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_106 ( V_22 ) ;
F_107 ( & V_106 , 0 , 0 ) ;
}
F_106 ( V_23 ) ;
F_106 ( V_99 ) ;
F_107 ( & V_104 , 0 , 0 ) ;
F_107 ( & V_105 , 0 , 0 ) ;
} else {
F_104 ( V_22 , V_45 -> V_22 , 0 ,
V_45 -> V_109 + V_101 , 1 ) ;
F_83 ( V_23 ) ;
}
return 0 ;
}
static int F_108 ( struct V_66 * V_45 )
{
V_4 V_98 = 0 ;
V_4 * V_23 , * V_22 , * V_99 ;
unsigned long V_111 = 0 ;
T_3 V_100 = F_98 ( 1 ) ;
int V_112 = 0 ;
struct V_2 * V_3 = F_91 ( V_45 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_92 ) ;
unsigned long V_101 = F_99 ( V_3 ) ;
V_4 V_113 [ 32 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_113 , V_5 ) ;
V_4 * V_114 = V_34 + 16 ;
struct V_103 V_104 ;
struct V_103 V_105 ;
struct V_103 V_106 ;
unsigned int V_107 ;
if ( F_100 ( ( V_45 -> V_109 < V_101 ) ||
( V_45 -> V_108 != 8 && V_45 -> V_108 != 12 ) ) )
return - V_21 ;
V_111 = ( unsigned long ) ( V_45 -> V_109 - V_101 ) ;
for ( V_107 = 0 ; V_107 < 4 ; V_107 ++ )
* ( V_34 + V_107 ) = V_13 -> V_91 [ V_107 ] ;
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ )
* ( V_34 + 4 + V_107 ) = V_45 -> V_34 [ V_107 ] ;
* ( ( T_3 * ) ( V_34 + 12 ) ) = V_100 ;
if ( ( F_101 ( V_45 -> V_23 ) ) && ( F_101 ( V_45 -> V_99 ) ) ) {
V_98 = 1 ;
F_102 ( & V_104 , V_45 -> V_23 ) ;
F_102 ( & V_105 , V_45 -> V_99 ) ;
V_23 = F_103 ( & V_104 ) ;
V_99 = F_103 ( & V_105 ) ;
V_22 = V_23 ;
if ( F_100 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_102 ( & V_106 , V_45 -> V_22 ) ;
V_22 = F_103 ( & V_106 ) ;
}
} else {
V_23 = F_75 ( V_45 -> V_109 + V_45 -> V_108 , V_110 ) ;
if ( ! V_23 )
return - V_81 ;
V_99 = ( V_23 + V_45 -> V_109 + V_101 ) ;
F_104 ( V_23 , V_45 -> V_23 , 0 , V_45 -> V_109 , 0 ) ;
F_104 ( V_99 , V_45 -> V_99 , 0 ,
V_45 -> V_108 , 0 ) ;
V_22 = V_23 ;
}
F_109 ( F_5 , V_22 , V_23 , V_111 , V_34 ,
V_13 -> V_74 , V_99 , ( unsigned long ) V_45 -> V_108 ,
V_114 , V_101 ) ;
V_112 = memcmp ( V_23 + V_111 , V_114 , V_101 ) ?
- V_115 : 0 ;
if ( V_98 ) {
if ( F_100 ( V_45 -> V_23 != V_45 -> V_22 ) ) {
F_106 ( V_22 ) ;
F_107 ( & V_106 , 0 , 0 ) ;
}
F_106 ( V_23 ) ;
F_106 ( V_99 ) ;
F_107 ( & V_104 , 0 , 0 ) ;
F_107 ( & V_105 , 0 , 0 ) ;
} else {
F_104 ( V_22 , V_45 -> V_22 , 0 , V_45 -> V_109 , 1 ) ;
F_83 ( V_23 ) ;
}
return V_112 ;
}
static int T_4 F_110 ( void )
{
int V_16 ;
if ( ! F_111 ( V_116 ) )
return - V_117 ;
V_16 = F_112 () ;
if ( V_16 )
return V_16 ;
return F_113 ( V_118 , F_114 ( V_118 ) ) ;
}
static void T_5 F_115 ( void )
{
F_116 ( V_118 , F_114 ( V_118 ) ) ;
F_117 () ;
}
