static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned int V_5 ,
int V_6 )
{
F_2 ( & V_2 -> V_7 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
static struct V_1 * F_3 ( T_1 V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_1 * V_2 ;
F_4 (err, &einjected, list) {
if ( V_3 == V_2 -> V_3 &&
V_4 == V_2 -> V_4 &&
V_5 == V_2 -> V_5 )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_5 ( struct V_8 * V_9 )
{
int V_3 = F_6 ( V_9 -> V_4 ) ;
if ( V_3 < 0 )
return NULL ;
return F_3 ( ( T_1 ) V_3 , V_9 -> V_4 -> V_10 , V_9 -> V_5 ) ;
}
static struct V_11 * F_7 ( struct V_12 * V_4 )
{
struct V_13 * V_14 ;
F_4 (bus_ops, &pci_bus_ops_list, list) {
if ( V_14 -> V_4 == V_4 )
return V_14 -> V_15 ;
}
return NULL ;
}
static struct V_13 * F_8 ( void )
{
unsigned long V_16 ;
struct V_13 * V_14 = NULL ;
F_9 ( & V_17 , V_16 ) ;
if ( F_10 ( & V_18 ) )
V_14 = NULL ;
else {
struct V_19 * V_20 = V_18 . V_21 ;
F_11 ( V_20 ) ;
V_14 = F_12 ( V_20 , struct V_13 , V_7 ) ;
}
F_13 ( & V_17 , V_16 ) ;
return V_14 ;
}
static T_2 * F_14 ( struct V_1 * V_2 , int V_22 ,
int * V_23 )
{
int V_24 = 0 ;
T_2 * V_25 = NULL ;
if ( V_2 -> V_6 == - 1 )
return NULL ;
switch ( V_22 - V_2 -> V_6 ) {
case V_26 :
V_25 = & V_2 -> V_27 ;
V_24 = 1 ;
break;
case V_28 :
V_25 = & V_2 -> V_29 ;
V_24 = 1 ;
break;
case V_30 :
V_25 = & V_2 -> V_31 ;
break;
case V_30 + 4 :
V_25 = & V_2 -> V_32 ;
break;
case V_30 + 8 :
V_25 = & V_2 -> V_33 ;
break;
case V_30 + 12 :
V_25 = & V_2 -> V_34 ;
break;
case V_35 :
V_25 = & V_2 -> V_36 ;
V_24 = 1 ;
break;
case V_37 :
V_25 = & V_2 -> V_38 ;
break;
}
if ( V_23 )
* V_23 = V_24 ;
return V_25 ;
}
static int F_15 ( struct V_12 * V_4 , unsigned int V_5 , int V_22 ,
int V_39 , T_2 * V_40 )
{
T_2 * V_41 ;
struct V_1 * V_2 ;
unsigned long V_16 ;
struct V_11 * V_15 ;
int V_3 ;
F_9 ( & V_17 , V_16 ) ;
if ( V_39 != sizeof( T_2 ) )
goto V_42;
V_3 = F_6 ( V_4 ) ;
if ( V_3 < 0 )
goto V_42;
V_2 = F_3 ( ( T_1 ) V_3 , V_4 -> V_10 , V_5 ) ;
if ( ! V_2 )
goto V_42;
V_41 = F_14 ( V_2 , V_22 , NULL ) ;
if ( V_41 ) {
* V_40 = * V_41 ;
F_13 ( & V_17 , V_16 ) ;
return 0 ;
}
V_42:
V_15 = F_7 ( V_4 ) ;
F_13 ( & V_17 , V_16 ) ;
return V_15 -> V_43 ( V_4 , V_5 , V_22 , V_39 , V_40 ) ;
}
static int F_16 ( struct V_12 * V_4 , unsigned int V_5 , int V_22 ,
int V_39 , T_2 V_40 )
{
T_2 * V_41 ;
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_24 ;
struct V_11 * V_15 ;
int V_3 ;
F_9 ( & V_17 , V_16 ) ;
if ( V_39 != sizeof( T_2 ) )
goto V_42;
V_3 = F_6 ( V_4 ) ;
if ( V_3 < 0 )
goto V_42;
V_2 = F_3 ( ( T_1 ) V_3 , V_4 -> V_10 , V_5 ) ;
if ( ! V_2 )
goto V_42;
V_41 = F_14 ( V_2 , V_22 , & V_24 ) ;
if ( V_41 ) {
if ( V_24 )
* V_41 ^= V_40 ;
else
* V_41 = V_40 ;
F_13 ( & V_17 , V_16 ) ;
return 0 ;
}
V_42:
V_15 = F_7 ( V_4 ) ;
F_13 ( & V_17 , V_16 ) ;
return V_15 -> V_44 ( V_4 , V_5 , V_22 , V_39 , V_40 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
struct V_12 * V_4 ,
struct V_11 * V_15 )
{
F_2 ( & V_14 -> V_7 ) ;
V_14 -> V_4 = V_4 ;
V_14 -> V_15 = V_15 ;
}
static int F_18 ( struct V_12 * V_4 )
{
struct V_11 * V_15 ;
struct V_13 * V_14 ;
unsigned long V_16 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
V_15 = F_20 ( V_4 , & V_47 ) ;
F_9 ( & V_17 , V_16 ) ;
if ( V_15 == & V_47 )
goto V_42;
F_17 ( V_14 , V_4 , V_15 ) ;
F_21 ( & V_14 -> V_7 , & V_18 ) ;
V_14 = NULL ;
V_42:
F_13 ( & V_17 , V_16 ) ;
F_22 ( V_14 ) ;
return 0 ;
}
static struct V_8 * F_23 ( struct V_8 * V_9 )
{
while ( 1 ) {
if ( ! F_24 ( V_9 ) )
break;
if ( F_25 ( V_9 ) == V_48 )
return V_9 ;
if ( ! V_9 -> V_4 -> V_49 )
break;
V_9 = V_9 -> V_4 -> V_49 ;
}
return NULL ;
}
static int F_26 ( struct V_50 * V_50 , void * V_51 )
{
struct V_52 * * V_53 = V_51 ;
struct V_52 * V_54 ;
if ( V_50 -> V_4 == & V_55 ) {
V_54 = F_27 ( V_50 ) ;
if ( V_54 -> V_56 & V_57 ) {
* V_53 = V_54 ;
return 1 ;
}
}
return 0 ;
}
static int F_28 ( struct V_8 * V_9 , struct V_52 * * V_53 )
{
return F_29 ( & V_9 -> V_9 , V_53 , F_26 ) ;
}
static int F_30 ( struct V_58 * V_59 )
{
struct V_1 * V_2 , * V_60 ;
struct V_1 * V_61 = NULL , * V_62 = NULL ;
struct V_8 * V_9 , * V_63 ;
struct V_52 * V_64 ;
unsigned long V_16 ;
unsigned int V_5 = F_31 ( V_59 -> V_9 , V_59 -> V_65 ) ;
int V_6 , V_66 ;
T_2 V_67 , V_68 , V_69 , V_70 = 0 , V_71 = 0 ;
int V_72 = 0 ;
V_9 = F_32 ( ( int ) V_59 -> V_3 , V_59 -> V_4 , V_5 ) ;
if ( ! V_9 )
return - V_73 ;
V_63 = F_23 ( V_9 ) ;
if ( ! V_63 ) {
V_72 = - V_73 ;
goto V_74;
}
V_6 = F_33 ( V_9 , V_75 ) ;
if ( ! V_6 ) {
V_72 = - V_76 ;
goto V_74;
}
F_34 ( V_9 , V_6 + V_77 , & V_67 ) ;
F_34 ( V_9 , V_6 + V_78 , & V_68 ) ;
F_34 ( V_9 , V_6 + V_79 ,
& V_69 ) ;
V_66 = F_33 ( V_63 , V_75 ) ;
if ( ! V_66 ) {
V_72 = - V_76 ;
goto V_74;
}
V_61 = F_35 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_61 ) {
V_72 = - V_46 ;
goto V_74;
}
V_62 = F_35 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_62 ) {
V_72 = - V_46 ;
goto V_74;
}
if ( V_80 ) {
V_70 = V_68 ;
V_68 &= ! ( V_59 -> V_29 ) ;
F_36 ( V_9 , V_6 + V_78 ,
V_68 ) ;
V_71 = V_69 ;
V_69 &= ! ( V_59 -> V_27 ) ;
F_36 ( V_9 , V_6 + V_79 ,
V_69 ) ;
}
F_9 ( & V_17 , V_16 ) ;
V_2 = F_5 ( V_9 ) ;
if ( ! V_2 ) {
V_2 = V_61 ;
V_61 = NULL ;
F_1 ( V_2 , V_59 -> V_3 , V_59 -> V_4 , V_5 ,
V_6 ) ;
F_21 ( & V_2 -> V_7 , & V_81 ) ;
}
V_2 -> V_27 |= V_59 -> V_27 ;
V_2 -> V_29 |= V_59 -> V_29 ;
V_2 -> V_31 = V_59 -> V_31 ;
V_2 -> V_32 = V_59 -> V_32 ;
V_2 -> V_33 = V_59 -> V_33 ;
V_2 -> V_34 = V_59 -> V_34 ;
if ( ! V_80 && V_59 -> V_29 &&
! ( V_59 -> V_29 & ~ V_68 ) ) {
V_72 = - V_82 ;
F_37 ( V_83 L_1 ) ;
F_13 ( & V_17 , V_16 ) ;
goto V_74;
}
if ( ! V_80 && V_59 -> V_27 &&
! ( V_59 -> V_27 & ~ V_69 ) ) {
V_72 = - V_82 ;
F_37 ( V_83 L_2 ) ;
F_13 ( & V_17 , V_16 ) ;
goto V_74;
}
V_60 = F_5 ( V_63 ) ;
if ( ! V_60 ) {
V_60 = V_62 ;
V_62 = NULL ;
F_1 ( V_60 , F_6 ( V_63 -> V_4 ) ,
V_63 -> V_4 -> V_10 , V_63 -> V_5 ,
V_66 ) ;
F_21 ( & V_60 -> V_7 , & V_81 ) ;
}
if ( V_59 -> V_29 ) {
if ( V_60 -> V_36 & V_84 )
V_60 -> V_36 |= V_85 ;
else
V_60 -> V_36 |= V_84 ;
V_60 -> V_38 &= 0xffff0000 ;
V_60 -> V_38 |= ( V_59 -> V_4 << 8 ) | V_5 ;
}
if ( V_59 -> V_27 ) {
if ( V_60 -> V_36 & V_86 )
V_60 -> V_36 |= V_87 ;
if ( V_67 & V_59 -> V_27 ) {
V_60 -> V_36 |= V_88 ;
if ( ! ( V_60 -> V_36 & V_86 ) )
V_60 -> V_36 |= V_89 ;
} else
V_60 -> V_36 |= V_90 ;
V_60 -> V_36 |= V_86 ;
V_60 -> V_38 &= 0x0000ffff ;
V_60 -> V_38 |= ( ( V_59 -> V_4 << 8 ) | V_5 ) << 16 ;
}
F_13 ( & V_17 , V_16 ) ;
if ( V_80 ) {
F_36 ( V_9 , V_6 + V_78 ,
V_70 ) ;
F_36 ( V_9 , V_6 + V_79 ,
V_71 ) ;
}
V_72 = F_18 ( V_9 -> V_4 ) ;
if ( V_72 )
goto V_74;
V_72 = F_18 ( V_63 -> V_4 ) ;
if ( V_72 )
goto V_74;
if ( F_28 ( V_63 , & V_64 ) ) {
if ( ! F_38 ( V_64 ) ) {
F_37 ( V_83 L_3 ) ;
V_72 = - V_82 ;
goto V_74;
}
F_39 ( - 1 , V_64 ) ;
} else
V_72 = - V_82 ;
V_74:
F_22 ( V_61 ) ;
F_22 ( V_62 ) ;
F_40 ( V_9 ) ;
return V_72 ;
}
static T_3 F_41 ( struct V_91 * V_92 , const char T_4 * V_93 ,
T_5 V_94 , T_6 * V_95 )
{
struct V_58 V_59 ;
int V_72 ;
if ( ! F_42 ( V_96 ) )
return - V_76 ;
if ( V_94 < V_97 (struct V_58, V_3 ) ||
V_94 > sizeof( V_59 ) )
return - V_82 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
if ( F_43 ( & V_59 , V_93 , V_94 ) )
return - V_98 ;
V_72 = F_30 ( & V_59 ) ;
return V_72 ? V_72 : V_94 ;
}
static int T_7 F_44 ( void )
{
return F_45 ( & V_99 ) ;
}
static void T_8 F_46 ( void )
{
struct V_1 * V_2 , * V_100 ;
unsigned long V_16 ;
struct V_13 * V_14 ;
F_47 ( & V_99 ) ;
while ( ( V_14 = F_8 () ) ) {
F_20 ( V_14 -> V_4 , V_14 -> V_15 ) ;
F_22 ( V_14 ) ;
}
F_9 ( & V_17 , V_16 ) ;
F_48 (err, err_next, &einjected, list) {
F_11 ( & V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
}
F_13 ( & V_17 , V_16 ) ;
}
