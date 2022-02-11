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
return F_3 ( V_3 , V_9 -> V_4 -> V_10 , V_9 -> V_5 ) ;
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
struct V_13 * V_14 ;
F_9 ( & V_17 , V_16 ) ;
V_14 = F_10 ( & V_18 ,
struct V_13 , V_7 ) ;
if ( V_14 )
F_11 ( & V_14 -> V_7 ) ;
F_12 ( & V_17 , V_16 ) ;
return V_14 ;
}
static T_1 * F_13 ( struct V_1 * V_2 , int V_19 ,
int * V_20 )
{
int V_21 = 0 ;
T_1 * V_22 = NULL ;
if ( V_2 -> V_6 == - 1 )
return NULL ;
switch ( V_19 - V_2 -> V_6 ) {
case V_23 :
V_22 = & V_2 -> V_24 ;
V_21 = 1 ;
break;
case V_25 :
V_22 = & V_2 -> V_26 ;
V_21 = 1 ;
break;
case V_27 :
V_22 = & V_2 -> V_28 ;
break;
case V_27 + 4 :
V_22 = & V_2 -> V_29 ;
break;
case V_27 + 8 :
V_22 = & V_2 -> V_30 ;
break;
case V_27 + 12 :
V_22 = & V_2 -> V_31 ;
break;
case V_32 :
V_22 = & V_2 -> V_33 ;
V_21 = 1 ;
break;
case V_34 :
V_22 = & V_2 -> V_35 ;
break;
}
if ( V_20 )
* V_20 = V_21 ;
return V_22 ;
}
static int F_14 ( struct V_12 * V_4 , unsigned int V_5 ,
int V_19 , int V_36 , T_1 * V_37 )
{
T_1 * V_38 ;
struct V_1 * V_2 ;
unsigned long V_16 ;
struct V_11 * V_15 ;
struct V_11 * V_39 ;
int V_3 ;
int V_40 ;
F_9 ( & V_17 , V_16 ) ;
if ( V_36 != sizeof( T_1 ) )
goto V_41;
V_3 = F_6 ( V_4 ) ;
if ( V_3 < 0 )
goto V_41;
V_2 = F_3 ( V_3 , V_4 -> V_10 , V_5 ) ;
if ( ! V_2 )
goto V_41;
V_38 = F_13 ( V_2 , V_19 , NULL ) ;
if ( V_38 ) {
* V_37 = * V_38 ;
F_12 ( & V_17 , V_16 ) ;
return 0 ;
}
V_41:
V_15 = F_7 ( V_4 ) ;
V_39 = V_4 -> V_15 ;
V_4 -> V_15 = V_15 ;
V_40 = V_15 -> V_42 ( V_4 , V_5 , V_19 , V_36 , V_37 ) ;
V_4 -> V_15 = V_39 ;
F_12 ( & V_17 , V_16 ) ;
return V_40 ;
}
static int F_15 ( struct V_12 * V_4 , unsigned int V_5 ,
int V_19 , int V_36 , T_1 V_37 )
{
T_1 * V_38 ;
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_21 ;
struct V_11 * V_15 ;
struct V_11 * V_39 ;
int V_3 ;
int V_40 ;
F_9 ( & V_17 , V_16 ) ;
if ( V_36 != sizeof( T_1 ) )
goto V_41;
V_3 = F_6 ( V_4 ) ;
if ( V_3 < 0 )
goto V_41;
V_2 = F_3 ( V_3 , V_4 -> V_10 , V_5 ) ;
if ( ! V_2 )
goto V_41;
V_38 = F_13 ( V_2 , V_19 , & V_21 ) ;
if ( V_38 ) {
if ( V_21 )
* V_38 ^= V_37 ;
else
* V_38 = V_37 ;
F_12 ( & V_17 , V_16 ) ;
return 0 ;
}
V_41:
V_15 = F_7 ( V_4 ) ;
V_39 = V_4 -> V_15 ;
V_4 -> V_15 = V_15 ;
V_40 = V_15 -> V_43 ( V_4 , V_5 , V_19 , V_36 , V_37 ) ;
V_4 -> V_15 = V_39 ;
F_12 ( & V_17 , V_16 ) ;
return V_40 ;
}
static void F_16 ( struct V_13 * V_14 ,
struct V_12 * V_4 ,
struct V_11 * V_15 )
{
F_2 ( & V_14 -> V_7 ) ;
V_14 -> V_4 = V_4 ;
V_14 -> V_15 = V_15 ;
}
static int F_17 ( struct V_12 * V_4 )
{
struct V_11 * V_15 ;
struct V_13 * V_14 ;
unsigned long V_16 ;
V_14 = F_18 ( sizeof( * V_14 ) , V_44 ) ;
if ( ! V_14 )
return - V_45 ;
V_15 = F_19 ( V_4 , & V_46 ) ;
F_9 ( & V_17 , V_16 ) ;
if ( V_15 == & V_46 )
goto V_41;
F_16 ( V_14 , V_4 , V_15 ) ;
F_20 ( & V_14 -> V_7 , & V_18 ) ;
V_14 = NULL ;
V_41:
F_12 ( & V_17 , V_16 ) ;
F_21 ( V_14 ) ;
return 0 ;
}
static struct V_8 * F_22 ( struct V_8 * V_9 )
{
while ( 1 ) {
if ( ! F_23 ( V_9 ) )
break;
if ( F_24 ( V_9 ) == V_47 )
return V_9 ;
if ( ! V_9 -> V_4 -> V_48 )
break;
V_9 = V_9 -> V_4 -> V_48 ;
}
return NULL ;
}
static int F_25 ( struct V_49 * V_49 , void * V_50 )
{
struct V_51 * * V_52 = V_50 ;
struct V_51 * V_53 ;
if ( V_49 -> V_4 == & V_54 ) {
V_53 = F_26 ( V_49 ) ;
if ( V_53 -> V_55 & V_56 ) {
* V_52 = V_53 ;
return 1 ;
}
}
return 0 ;
}
static int F_27 ( struct V_8 * V_9 , struct V_51 * * V_52 )
{
return F_28 ( & V_9 -> V_9 , V_52 , F_25 ) ;
}
static int F_29 ( struct V_57 * V_58 )
{
struct V_1 * V_2 , * V_59 ;
struct V_1 * V_60 = NULL , * V_61 = NULL ;
struct V_8 * V_9 , * V_62 ;
struct V_51 * V_63 ;
unsigned long V_16 ;
unsigned int V_5 = F_30 ( V_58 -> V_9 , V_58 -> V_64 ) ;
int V_6 , V_65 ;
T_1 V_66 , V_67 , V_68 , V_69 = 0 , V_70 = 0 ;
int V_71 = 0 ;
V_9 = F_31 ( V_58 -> V_3 , V_58 -> V_4 , V_5 ) ;
if ( ! V_9 )
return - V_72 ;
V_62 = F_22 ( V_9 ) ;
if ( ! V_62 ) {
F_32 ( & V_9 -> V_9 , L_1 ) ;
V_71 = - V_72 ;
goto V_73;
}
V_6 = F_33 ( V_9 , V_74 ) ;
if ( ! V_6 ) {
F_32 ( & V_9 -> V_9 , L_2 ) ;
V_71 = - V_75 ;
goto V_73;
}
F_34 ( V_9 , V_6 + V_76 , & V_66 ) ;
F_34 ( V_9 , V_6 + V_77 , & V_67 ) ;
F_34 ( V_9 , V_6 + V_78 ,
& V_68 ) ;
V_65 = F_33 ( V_62 , V_74 ) ;
if ( ! V_65 ) {
F_32 ( & V_62 -> V_9 ,
L_3 ) ;
V_71 = - V_75 ;
goto V_73;
}
V_60 = F_35 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_60 ) {
V_71 = - V_45 ;
goto V_73;
}
V_61 = F_35 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_61 ) {
V_71 = - V_45 ;
goto V_73;
}
if ( V_79 ) {
V_69 = V_67 ;
V_67 &= ! ( V_58 -> V_26 ) ;
F_36 ( V_9 , V_6 + V_77 ,
V_67 ) ;
V_70 = V_68 ;
V_68 &= ! ( V_58 -> V_24 ) ;
F_36 ( V_9 , V_6 + V_78 ,
V_68 ) ;
}
F_9 ( & V_17 , V_16 ) ;
V_2 = F_5 ( V_9 ) ;
if ( ! V_2 ) {
V_2 = V_60 ;
V_60 = NULL ;
F_1 ( V_2 , V_58 -> V_3 , V_58 -> V_4 , V_5 ,
V_6 ) ;
F_20 ( & V_2 -> V_7 , & V_80 ) ;
}
V_2 -> V_24 |= V_58 -> V_24 ;
V_2 -> V_26 |= V_58 -> V_26 ;
V_2 -> V_28 = V_58 -> V_28 ;
V_2 -> V_29 = V_58 -> V_29 ;
V_2 -> V_30 = V_58 -> V_30 ;
V_2 -> V_31 = V_58 -> V_31 ;
if ( ! V_79 && V_58 -> V_26 &&
! ( V_58 -> V_26 & ~ V_67 ) ) {
V_71 = - V_81 ;
F_37 ( & V_9 -> V_9 ,
L_4 ) ;
F_12 ( & V_17 , V_16 ) ;
goto V_73;
}
if ( ! V_79 && V_58 -> V_24 &&
! ( V_58 -> V_24 & ~ V_68 ) ) {
V_71 = - V_81 ;
F_37 ( & V_9 -> V_9 ,
L_5 ) ;
F_12 ( & V_17 , V_16 ) ;
goto V_73;
}
V_59 = F_5 ( V_62 ) ;
if ( ! V_59 ) {
V_59 = V_61 ;
V_61 = NULL ;
F_1 ( V_59 , F_6 ( V_62 -> V_4 ) ,
V_62 -> V_4 -> V_10 , V_62 -> V_5 ,
V_65 ) ;
F_20 ( & V_59 -> V_7 , & V_80 ) ;
}
if ( V_58 -> V_26 ) {
if ( V_59 -> V_33 & V_82 )
V_59 -> V_33 |= V_83 ;
else
V_59 -> V_33 |= V_82 ;
V_59 -> V_35 &= 0xffff0000 ;
V_59 -> V_35 |= ( V_58 -> V_4 << 8 ) | V_5 ;
}
if ( V_58 -> V_24 ) {
if ( V_59 -> V_33 & V_84 )
V_59 -> V_33 |= V_85 ;
if ( V_66 & V_58 -> V_24 ) {
V_59 -> V_33 |= V_86 ;
if ( ! ( V_59 -> V_33 & V_84 ) )
V_59 -> V_33 |= V_87 ;
} else
V_59 -> V_33 |= V_88 ;
V_59 -> V_33 |= V_84 ;
V_59 -> V_35 &= 0x0000ffff ;
V_59 -> V_35 |= ( ( V_58 -> V_4 << 8 ) | V_5 ) << 16 ;
}
F_12 ( & V_17 , V_16 ) ;
if ( V_79 ) {
F_36 ( V_9 , V_6 + V_77 ,
V_69 ) ;
F_36 ( V_9 , V_6 + V_78 ,
V_70 ) ;
}
V_71 = F_17 ( V_9 -> V_4 ) ;
if ( V_71 )
goto V_73;
V_71 = F_17 ( V_62 -> V_4 ) ;
if ( V_71 )
goto V_73;
if ( F_27 ( V_62 , & V_63 ) ) {
if ( ! F_38 ( V_63 ) ) {
F_37 ( & V_63 -> V_49 ,
L_6 ) ;
V_71 = - V_75 ;
goto V_73;
}
F_39 ( & V_63 -> V_49 ,
L_7 ,
V_58 -> V_26 , V_58 -> V_24 , F_40 ( V_9 ) ) ;
F_41 ( - 1 , V_63 ) ;
} else {
F_32 ( & V_62 -> V_9 , L_8 ) ;
V_71 = - V_72 ;
}
V_73:
F_21 ( V_60 ) ;
F_21 ( V_61 ) ;
F_42 ( V_9 ) ;
return V_71 ;
}
static T_2 F_43 ( struct V_89 * V_90 , const char T_3 * V_91 ,
T_4 V_92 , T_5 * V_93 )
{
struct V_57 V_58 ;
int V_71 ;
if ( ! F_44 ( V_94 ) )
return - V_95 ;
if ( V_92 < V_96 (struct V_57, V_3 ) ||
V_92 > sizeof( V_58 ) )
return - V_81 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
if ( F_45 ( & V_58 , V_91 , V_92 ) )
return - V_97 ;
V_71 = F_29 ( & V_58 ) ;
return V_71 ? V_71 : V_92 ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_98 ) ;
}
static void T_7 F_48 ( void )
{
struct V_1 * V_2 , * V_99 ;
unsigned long V_16 ;
struct V_13 * V_14 ;
F_49 ( & V_98 ) ;
while ( ( V_14 = F_8 () ) ) {
F_19 ( V_14 -> V_4 , V_14 -> V_15 ) ;
F_21 ( V_14 ) ;
}
F_9 ( & V_17 , V_16 ) ;
F_50 (err, err_next, &einjected, list) {
F_11 ( & V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
}
F_12 ( & V_17 , V_16 ) ;
}
