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
static int F_46 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_5 ) ;
}
static int F_47 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_6 ) ;
}
static int F_48 ( struct V_10 * V_3 )
{
return F_42 ( V_3 , L_7 ) ;
}
static int F_49 ( struct V_10 * V_3 )
{
struct V_37 * V_38 ;
struct V_1 * V_13 = (struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
struct V_2 * V_39 ;
struct V_1 * V_40 ;
V_38 = F_50 ( L_8 , 0 , 0 ) ;
if ( F_51 ( V_38 ) )
return F_52 ( V_38 ) ;
V_39 = F_53 ( V_38 ) ;
V_40 = F_1 ( V_39 ) ;
memcpy ( V_40 , V_13 , sizeof( * V_13 ) ) ;
V_13 -> V_38 = V_38 ;
V_3 -> V_41 . V_42 = sizeof( struct V_43 )
+ F_54 ( & V_38 -> V_44 ) ;
return 0 ;
}
static void F_55 ( struct V_10 * V_3 )
{
struct V_1 * V_13 =
(struct V_1 * )
F_2 ( ( V_4 * ) F_3 ( V_3 ) , V_5 ) ;
if ( ! F_51 ( V_13 -> V_38 ) )
F_56 ( V_13 -> V_38 ) ;
return;
}
static void
F_57 ( struct V_45 * V_46 , int V_16 )
{
struct V_47 * V_48 = V_46 -> V_49 ;
if ( V_16 == - V_50 )
return;
V_48 -> V_16 = V_16 ;
F_58 ( & V_48 -> V_51 ) ;
}
static int
F_59 ( V_4 * V_52 , const V_4 * V_53 , unsigned int V_12 )
{
struct V_54 * V_55 ;
struct V_56 * V_46 ;
int V_57 = - V_21 ;
struct V_58 * V_59 ;
V_55 = F_60 ( L_9 , 0 , 0 ) ;
if ( F_51 ( V_55 ) )
return F_52 ( V_55 ) ;
F_61 ( V_55 , ~ 0 ) ;
V_57 = F_62 ( V_55 , V_53 , V_12 ) ;
if ( V_57 )
goto V_60;
V_57 = - V_61 ;
V_46 = F_63 ( V_55 , V_62 ) ;
if ( ! V_46 )
goto V_60;
V_59 = F_64 ( sizeof( * V_59 ) , V_62 ) ;
if ( ! V_59 )
goto V_63;
memset ( V_59 -> V_34 , 0 , sizeof( V_59 -> V_34 ) ) ;
memset ( V_52 , 0 , V_64 ) ;
F_65 ( & V_59 -> V_48 . V_51 ) ;
F_66 ( & V_59 -> V_65 , V_52 , V_64 ) ;
F_67 ( V_46 , V_55 ) ;
F_68 ( V_46 , V_30 |
V_66 ,
F_57 ,
& V_59 -> V_48 ) ;
F_69 ( V_46 , & V_59 -> V_65 ,
& V_59 -> V_65 , V_64 , V_59 -> V_34 ) ;
V_57 = F_70 ( V_46 ) ;
if ( V_57 == - V_50 || V_57 == - V_67 ) {
V_57 = F_71
( & V_59 -> V_48 . V_51 ) ;
if ( ! V_57 )
V_57 = V_59 -> V_48 . V_16 ;
}
F_72 ( V_59 ) ;
V_63:
F_73 ( V_46 ) ;
V_60:
F_74 ( V_55 ) ;
return V_57 ;
}
static int F_75 ( struct V_2 * V_68 , const V_4 * V_53 ,
unsigned int V_12 )
{
int V_57 = 0 ;
struct V_10 * V_3 = F_4 ( V_68 ) ;
struct V_1 * V_13 = F_1 ( V_68 ) ;
struct V_2 * V_39 = F_53 ( V_13 -> V_38 ) ;
struct V_1 * V_40 =
F_1 ( V_39 ) ;
V_4 * V_69 , * V_70 = NULL ;
if ( V_12 < 4 ) {
F_76 ( V_3 , V_20 ) ;
return - V_21 ;
}
V_12 -= 4 ;
if ( V_12 != V_17 ) {
F_76 ( V_3 , V_20 ) ;
return - V_21 ;
}
memcpy ( V_13 -> V_71 , V_53 + V_12 , sizeof( V_13 -> V_71 ) ) ;
if ( ( unsigned long ) ( & ( V_13 -> V_72 . V_73 [ 0 ] ) ) % V_5 )
return - V_21 ;
if ( ( unsigned long ) V_53 % V_5 ) {
V_70 = F_64 ( V_12 + V_5 , V_62 ) ;
if ( ! V_70 )
return - V_61 ;
V_69 = F_2 ( V_70 , V_5 ) ;
memcpy ( V_69 , V_53 , V_12 ) ;
V_53 = V_69 ;
}
if ( ! F_9 () )
V_57 = F_10 ( & ( V_13 -> V_72 ) ,
V_53 , V_12 ) ;
else {
F_11 () ;
V_57 = F_12 ( & ( V_13 -> V_72 ) , V_53 , V_12 ) ;
F_13 () ;
}
if ( ( unsigned long ) ( & ( V_13 -> V_52 [ 0 ] ) ) % V_5 ) {
V_57 = - V_21 ;
goto exit;
}
V_57 = F_59 ( V_13 -> V_52 , V_53 , V_12 ) ;
memcpy ( V_40 , V_13 , sizeof( * V_13 ) ) ;
exit:
F_72 ( V_70 ) ;
return V_57 ;
}
static int F_77 ( struct V_2 * V_68 ,
unsigned int V_74 )
{
struct V_1 * V_13 = F_1 ( V_68 ) ;
struct V_2 * V_39 = F_53 ( V_13 -> V_38 ) ;
switch ( V_74 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_21 ;
}
F_78 ( V_68 ) -> V_74 = V_74 ;
F_78 ( V_39 ) -> V_74 = V_74 ;
return 0 ;
}
static int F_79 ( struct V_43 * V_46 )
{
int V_57 ;
struct V_2 * V_3 = F_80 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_43 * V_75 =
(struct V_43 * ) F_81 ( V_46 ) ;
memcpy ( V_75 , V_46 , sizeof( * V_46 ) ) ;
F_82 ( V_75 , & V_13 -> V_38 -> V_44 ) ;
return F_83 ( V_75 ) ;
} else {
struct V_2 * V_39 = F_53 ( V_13 -> V_38 ) ;
F_11 () ;
V_57 = V_39 -> V_44 . V_41 . V_76 ( V_46 ) ;
F_13 () ;
return V_57 ;
}
}
static int F_84 ( struct V_43 * V_46 )
{
int V_57 ;
struct V_2 * V_3 = F_80 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_9 () ) {
struct V_43 * V_75 =
(struct V_43 * ) F_81 ( V_46 ) ;
memcpy ( V_75 , V_46 , sizeof( * V_46 ) ) ;
F_82 ( V_75 , & V_13 -> V_38 -> V_44 ) ;
return F_85 ( V_75 ) ;
} else {
struct V_2 * V_39 = F_53 ( V_13 -> V_38 ) ;
F_11 () ;
V_57 = V_39 -> V_44 . V_41 . V_77 ( V_46 ) ;
F_13 () ;
return V_57 ;
}
}
static int F_86 ( struct V_43 * V_46 )
{
V_4 V_78 = 0 ;
V_4 * V_23 , * V_22 , * V_79 ;
T_2 V_80 = F_87 ( 1 ) ;
struct V_2 * V_3 = F_80 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_72 ) ;
unsigned long V_81 = F_88 ( V_3 ) ;
V_4 V_82 [ 16 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_82 , V_5 ) ;
struct V_83 V_84 ;
struct V_83 V_85 ;
struct V_83 V_86 ;
unsigned int V_87 ;
if ( F_89 ( V_46 -> V_88 != 8 && V_46 -> V_88 != 12 ) )
return - V_21 ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ )
* ( V_34 + V_87 ) = V_13 -> V_71 [ V_87 ] ;
for ( V_87 = 0 ; V_87 < 8 ; V_87 ++ )
* ( V_34 + 4 + V_87 ) = V_46 -> V_34 [ V_87 ] ;
* ( ( T_2 * ) ( V_34 + 12 ) ) = V_80 ;
if ( ( F_90 ( V_46 -> V_23 ) ) && ( F_90 ( V_46 -> V_79 ) ) ) {
V_78 = 1 ;
F_91 ( & V_84 , V_46 -> V_23 ) ;
F_91 ( & V_85 , V_46 -> V_79 ) ;
V_23 = F_92 ( & V_84 ) ;
V_79 = F_92 ( & V_85 ) ;
V_22 = V_23 ;
if ( F_89 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_91 ( & V_86 , V_46 -> V_22 ) ;
V_22 = F_92 ( & V_86 ) ;
}
} else {
V_23 = F_64 ( V_46 -> V_89 + V_81 + V_46 -> V_88 ,
V_90 ) ;
if ( F_89 ( ! V_23 ) )
return - V_61 ;
V_79 = ( V_23 + V_46 -> V_89 + V_81 ) ;
F_93 ( V_23 , V_46 -> V_23 , 0 , V_46 -> V_89 , 0 ) ;
F_93 ( V_79 , V_46 -> V_79 , 0 ,
V_46 -> V_88 , 0 ) ;
V_22 = V_23 ;
}
F_94 ( F_5 , V_22 , V_23 , ( unsigned long ) V_46 -> V_89 , V_34 ,
V_13 -> V_52 , V_79 , ( unsigned long ) V_46 -> V_88 , V_22
+ ( ( unsigned long ) V_46 -> V_89 ) , V_81 ) ;
if ( V_78 ) {
if ( F_89 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_95 ( V_22 ) ;
F_96 ( & V_86 , 0 , 0 ) ;
}
F_95 ( V_23 ) ;
F_95 ( V_79 ) ;
F_96 ( & V_84 , 0 , 0 ) ;
F_96 ( & V_85 , 0 , 0 ) ;
} else {
F_93 ( V_22 , V_46 -> V_22 , 0 ,
V_46 -> V_89 + V_81 , 1 ) ;
F_72 ( V_23 ) ;
}
return 0 ;
}
static int F_97 ( struct V_43 * V_46 )
{
V_4 V_78 = 0 ;
V_4 * V_23 , * V_22 , * V_79 ;
unsigned long V_91 = 0 ;
T_2 V_80 = F_87 ( 1 ) ;
int V_92 = 0 ;
struct V_2 * V_3 = F_80 ( V_46 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
void * F_5 = & ( V_13 -> V_72 ) ;
unsigned long V_81 = F_88 ( V_3 ) ;
V_4 V_93 [ 32 + V_5 ] ;
V_4 * V_34 = ( V_4 * ) F_2 ( ( V_4 * ) V_93 , V_5 ) ;
V_4 * V_94 = V_34 + 16 ;
struct V_83 V_84 ;
struct V_83 V_85 ;
struct V_83 V_86 ;
unsigned int V_87 ;
if ( F_89 ( ( V_46 -> V_89 < V_81 ) ||
( V_46 -> V_88 != 8 && V_46 -> V_88 != 12 ) ) )
return - V_21 ;
V_91 = ( unsigned long ) ( V_46 -> V_89 - V_81 ) ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ )
* ( V_34 + V_87 ) = V_13 -> V_71 [ V_87 ] ;
for ( V_87 = 0 ; V_87 < 8 ; V_87 ++ )
* ( V_34 + 4 + V_87 ) = V_46 -> V_34 [ V_87 ] ;
* ( ( T_2 * ) ( V_34 + 12 ) ) = V_80 ;
if ( ( F_90 ( V_46 -> V_23 ) ) && ( F_90 ( V_46 -> V_79 ) ) ) {
V_78 = 1 ;
F_91 ( & V_84 , V_46 -> V_23 ) ;
F_91 ( & V_85 , V_46 -> V_79 ) ;
V_23 = F_92 ( & V_84 ) ;
V_79 = F_92 ( & V_85 ) ;
V_22 = V_23 ;
if ( F_89 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_91 ( & V_86 , V_46 -> V_22 ) ;
V_22 = F_92 ( & V_86 ) ;
}
} else {
V_23 = F_64 ( V_46 -> V_89 + V_46 -> V_88 , V_90 ) ;
if ( ! V_23 )
return - V_61 ;
V_79 = ( V_23 + V_46 -> V_89 + V_81 ) ;
F_93 ( V_23 , V_46 -> V_23 , 0 , V_46 -> V_89 , 0 ) ;
F_93 ( V_79 , V_46 -> V_79 , 0 ,
V_46 -> V_88 , 0 ) ;
V_22 = V_23 ;
}
F_98 ( F_5 , V_22 , V_23 , V_91 , V_34 ,
V_13 -> V_52 , V_79 , ( unsigned long ) V_46 -> V_88 ,
V_94 , V_81 ) ;
V_92 = memcmp ( V_23 + V_91 , V_94 , V_81 ) ?
- V_95 : 0 ;
if ( V_78 ) {
if ( F_89 ( V_46 -> V_23 != V_46 -> V_22 ) ) {
F_95 ( V_22 ) ;
F_96 ( & V_86 , 0 , 0 ) ;
}
F_95 ( V_23 ) ;
F_95 ( V_79 ) ;
F_96 ( & V_84 , 0 , 0 ) ;
F_96 ( & V_85 , 0 , 0 ) ;
} else {
F_93 ( V_22 , V_46 -> V_22 , 0 , V_46 -> V_89 , 1 ) ;
F_72 ( V_23 ) ;
}
return V_92 ;
}
static int T_3 F_99 ( void )
{
int V_16 , V_87 ;
if ( ! F_100 ( V_96 ) )
return - V_97 ;
V_16 = F_101 () ;
if ( V_16 )
return V_16 ;
for ( V_87 = 0 ; V_87 < F_102 ( V_98 ) ; V_87 ++ )
F_103 ( & V_98 [ V_87 ] . V_99 ) ;
return F_104 ( V_98 , F_102 ( V_98 ) ) ;
}
static void T_4 F_105 ( void )
{
F_106 ( V_98 , F_102 ( V_98 ) ) ;
F_107 () ;
}
