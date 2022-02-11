static T_1
F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( F_2 ( V_1 ) ) {
( * V_5 ) ++ ;
return V_6 ;
} else {
return V_7 ;
}
}
static int F_3 ( struct V_8 * V_9 , unsigned long V_10 ,
void * V_11 )
{
struct V_12 * V_13 = F_4 ( V_9 , struct V_12 , V_9 ) ;
struct V_14 * V_15 = V_13 -> V_16 -> V_17 -> V_14 ;
T_3 V_18 ;
if ( ! V_15 -> V_19 )
return V_20 ;
F_5 ( V_15 -> V_19 ,
V_21 ,
& V_18 ) ;
if ( ( ( V_18 >> 8 ) & 0xff ) != V_15 -> V_22 . V_23 ) {
V_18 = ( V_18 & 0xff000000 )
| ( ( unsigned int ) ( V_15 -> V_24 ) << 0 )
| ( ( unsigned int ) ( V_15 -> V_22 . V_23 ) << 8 )
| ( ( unsigned int ) ( V_15 -> V_22 . V_25 ) << 16 ) ;
F_6 ( V_15 -> V_19 , V_21 , V_18 ) ;
}
return V_20 ;
}
static T_1
F_7 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_26 * V_17 = (struct V_26 * ) V_3 ;
struct V_27 * V_16 ;
struct V_12 * V_28 ;
T_2 V_29 ;
T_1 V_30 = V_7 ;
unsigned long long V_31 , V_32 ;
int V_33 , V_34 , V_35 ;
struct V_14 * V_36 = V_17 -> V_14 ;
struct V_37 * V_38 ;
if ( ! F_8 ( V_36 , V_1 ) && ! F_2 ( V_1 ) )
return V_7 ;
V_30 = F_9 ( V_1 , L_1 , NULL , & V_31 ) ;
if ( F_10 ( V_30 ) ) {
F_11 ( L_2 , V_30 ) ;
return V_7 ;
}
V_33 = ( V_31 >> 16 ) & 0xffff ;
V_34 = V_31 & 0xffff ;
V_38 = V_36 -> V_19 ;
if ( V_38 && F_12 ( V_38 ) ) {
V_29 = F_13 ( V_38 ) ;
if ( V_29 ) {
struct V_39 * V_40 = F_14 ( V_29 ) ;
if ( V_40 && ( V_40 -> V_41 &
V_42 ) )
return V_7 ;
}
}
V_28 = F_15 ( sizeof( struct V_12 ) , V_43 ) ;
if ( ! V_28 )
return V_44 ;
F_16 ( & V_28 -> V_45 ) ;
V_28 -> V_1 = V_1 ;
V_28 -> V_34 = V_34 ;
if ( F_17 ( F_18 ( V_1 , L_3 , & V_29 ) ) )
V_28 -> V_46 = V_47 ;
if ( F_17 ( F_18 ( V_1 , L_4 , & V_29 ) ) )
V_28 -> V_46 |= V_48 ;
if ( F_17 ( F_18 ( V_1 , L_5 , & V_29 ) ) )
V_28 -> V_46 |= V_49 ;
if ( F_17 ( F_18 ( V_1 , L_6 , & V_29 ) ) )
V_28 -> V_46 |= V_50 ;
if ( F_17 ( F_18 ( V_1 , L_7 , & V_29 ) ) )
V_28 -> V_46 |= V_51 ;
V_30 = F_9 ( V_1 , L_8 , NULL , & V_32 ) ;
if ( F_10 ( V_30 ) ) {
V_32 = V_17 -> V_52 + 1 ;
}
for ( V_16 = V_17 -> V_53 ; V_16 ; V_16 = V_16 -> V_54 )
if ( V_16 -> V_33 == V_33 ) {
if ( V_16 -> V_32 != V_32 )
F_11 ( L_9 ) ;
break;
}
if ( ! V_16 ) {
V_16 = F_15 ( sizeof( struct V_27 ) , V_43 ) ;
if ( ! V_16 ) {
F_19 ( V_28 ) ;
return V_44 ;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_33 = V_33 ;
V_16 -> V_32 = V_32 ;
F_16 ( & V_16 -> V_55 ) ;
F_20 ( & V_16 -> V_56 ) ;
V_16 -> V_54 = V_17 -> V_53 ;
V_17 -> V_53 = V_16 ;
V_17 -> V_52 ++ ;
F_21 ( L_10 ,
V_16 -> V_32 , F_22 ( V_36 ) , V_36 -> V_57 , V_33 ) ;
V_35 = F_23 ( V_16 ) ;
if ( V_35 ) {
if ( V_35 == - V_58 )
F_11 ( L_11
L_12 , V_16 -> V_32 ) ;
else
F_11 ( L_13
L_14 , V_35 ) ;
goto V_59;
}
}
V_28 -> V_16 = V_16 ;
F_24 ( & V_28 -> V_45 , & V_16 -> V_55 ) ;
V_38 = F_25 ( V_36 , F_26 ( V_33 , V_34 ) ) ;
if ( V_38 ) {
V_16 -> V_46 |= ( V_60 | V_61 ) ;
F_27 ( V_38 ) ;
}
if ( F_2 ( V_1 ) ) {
V_28 -> V_46 &= ~ V_47 ;
if ( F_28 ( V_1 ,
& V_62 , V_28 ) )
F_21 ( L_15 ) ;
V_28 -> V_9 . V_63 = F_3 ;
if ( F_29 ( & V_28 -> V_9 ) )
F_21 ( L_16 ) ;
}
if ( ! ( V_28 -> V_46 & V_51 ) ) {
V_30 = F_30 ( V_1 ,
V_64 ,
V_65 ,
V_28 ) ;
if ( F_10 ( V_30 ) )
F_31 ( L_17 ) ;
} else
V_30 = V_7 ;
return V_30 ;
V_59:
V_17 -> V_52 -- ;
V_17 -> V_53 = V_16 -> V_54 ;
F_19 ( V_16 ) ;
F_19 ( V_28 ) ;
return V_7 ;
}
static int F_32 ( T_2 V_1 )
{
int V_66 = F_33 ( V_1 ) ;
if ( ! V_66 ) {
F_34 ( V_67 , V_1 , ( T_3 ) 1 ,
F_1 , NULL , ( void * ) & V_66 , NULL ) ;
}
return V_66 ;
}
static void F_35 ( struct V_26 * V_17 )
{
T_1 V_30 ;
F_36 ( & V_17 -> V_68 , & V_69 ) ;
V_30 = F_34 ( V_67 , V_17 -> V_1 , ( T_3 ) 1 ,
F_7 , NULL , V_17 , NULL ) ;
if ( F_10 ( V_30 ) ) {
F_37 ( & V_17 -> V_68 ) ;
return;
}
if ( V_17 -> type != V_70 ) {
if ( ( V_17 -> V_46 & V_71 ) && V_17 -> V_13 ) {
V_30 = F_38 ( V_17 -> V_13 -> V_1 ,
V_64 ,
V_65 ) ;
if ( F_10 ( V_30 ) )
F_31 ( L_18 ) ;
}
V_30 = F_30 ( V_17 -> V_1 ,
V_64 ,
V_72 ,
V_17 ) ;
if ( F_10 ( V_30 ) ) {
F_31 ( L_17 ) ;
}
}
}
static struct V_12 * F_39 ( T_2 V_1 )
{
struct V_26 * V_17 ;
struct V_27 * V_16 ;
struct V_12 * V_13 ;
F_40 (bridge, &bridge_list, list) {
for ( V_16 = V_17 -> V_53 ; V_16 ; V_16 = V_16 -> V_54 ) {
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_1 == V_1 )
return V_13 ;
}
}
}
return NULL ;
}
static inline void F_41 ( struct V_26 * V_17 )
{
T_2 V_73 ;
if ( F_17 ( F_18 ( V_17 -> V_1 ,
L_4 , & V_73 ) ) )
V_17 -> V_46 |= V_74 ;
if ( F_17 ( F_18 ( V_17 -> V_1 ,
L_3 , & V_73 ) ) )
V_17 -> V_46 |= V_71 ;
if ( F_17 ( F_18 ( V_17 -> V_1 ,
L_5 , & V_73 ) ) )
V_17 -> V_46 |= V_75 ;
if ( F_17 ( F_18 ( V_17 -> V_1 ,
L_6 , & V_73 ) ) )
V_17 -> V_46 |= V_76 ;
if ( V_17 -> V_46 & V_71 ) {
struct V_12 * V_13 ;
F_21 ( L_19 ) ;
V_13 = F_39 ( V_17 -> V_1 ) ;
if ( ! V_13 )
return;
V_17 -> V_13 = V_13 ;
V_13 -> V_17 = V_17 ;
}
}
static void F_42 ( T_2 * V_1 )
{
struct V_26 * V_17 ;
struct V_39 * V_40 = F_14 ( V_1 ) ;
V_17 = F_15 ( sizeof( struct V_26 ) , V_43 ) ;
if ( V_17 == NULL )
return;
V_17 -> type = V_70 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_14 = V_40 -> V_15 ;
F_35 ( V_17 ) ;
}
static void F_43 ( T_2 * V_1 )
{
struct V_26 * V_17 ;
V_17 = F_15 ( sizeof( struct V_26 ) , V_43 ) ;
if ( V_17 == NULL ) {
F_31 ( L_20 ) ;
return;
}
V_17 -> type = V_77 ;
V_17 -> V_1 = V_1 ;
F_41 ( V_17 ) ;
V_17 -> V_37 = F_44 ( V_1 ) ;
V_17 -> V_14 = V_17 -> V_37 -> V_78 ;
if ( ! V_17 -> V_14 ) {
F_31 ( L_21 ) ;
goto F_31;
}
F_45 ( & V_17 -> V_14 -> V_79 ) ;
F_35 ( V_17 ) ;
return;
F_31:
F_27 ( V_17 -> V_37 ) ;
F_19 ( V_17 ) ;
return;
}
static T_1
F_46 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
T_1 V_30 ;
struct V_37 * V_79 ;
V_79 = F_44 ( V_1 ) ;
if ( ! V_79 || ! V_79 -> V_78 )
goto V_80;
if ( ( F_32 ( V_1 ) > 0 ) ) {
F_21 ( L_22 , F_47 ( V_79 ) ) ;
F_43 ( V_1 ) ;
}
V_30 = F_34 ( V_67 , V_1 , ( T_3 ) 1 ,
F_46 , NULL , NULL , NULL ) ;
if ( F_10 ( V_30 ) )
F_11 ( L_23 , V_30 ) ;
V_80:
F_27 ( V_79 ) ;
return V_7 ;
}
static int F_48 ( T_2 V_1 )
{
T_1 V_30 ;
unsigned long long V_29 ;
T_2 V_73 ;
V_30 = F_18 ( V_1 , L_4 , & V_73 ) ;
if ( F_17 ( V_30 ) ) {
V_30 = F_9 ( V_1 , L_4 , NULL , & V_29 ) ;
if ( F_10 ( V_30 ) ) {
F_21 ( L_24 , V_81 ) ;
return 0 ;
}
if ( ( V_29 & V_82 ) == 0 )
return 0 ;
}
if ( F_32 ( V_1 ) > 0 ) {
F_21 ( L_25 ) ;
F_42 ( V_1 ) ;
}
V_30 = F_34 ( V_67 , V_1 , ( T_3 ) 1 ,
F_46 , NULL , NULL , NULL ) ;
if ( F_10 ( V_30 ) )
F_11 ( L_23 , V_30 ) ;
return 0 ;
}
static struct V_26 * F_49 ( T_2 V_1 )
{
struct V_26 * V_17 ;
F_40 (bridge, &bridge_list, list)
if ( V_17 -> V_1 == V_1 )
return V_17 ;
return NULL ;
}
static void F_50 ( struct V_26 * V_17 )
{
struct V_27 * V_16 , * V_54 ;
struct V_12 * V_13 , * V_29 ;
T_1 V_30 ;
T_2 V_1 = V_17 -> V_1 ;
V_30 = F_38 ( V_1 , V_64 ,
V_72 ) ;
if ( F_10 ( V_30 ) )
F_31 ( L_18 ) ;
if ( ( V_17 -> type != V_70 ) &&
( ( V_17 -> V_46 & V_71 ) && V_17 -> V_13 ) ) {
V_30 = F_30 ( V_17 -> V_13 -> V_1 ,
V_64 ,
V_65 ,
V_17 -> V_13 ) ;
if ( F_10 ( V_30 ) )
F_31 ( L_26 ) ;
}
V_16 = V_17 -> V_53 ;
while ( V_16 ) {
V_54 = V_16 -> V_54 ;
F_51 (func, tmp, &slot->funcs, sibling) {
if ( F_2 ( V_13 -> V_1 ) ) {
F_52 ( V_13 -> V_1 ) ;
F_53 ( & V_13 -> V_9 ) ;
}
if ( ! ( V_13 -> V_46 & V_51 ) ) {
V_30 = F_38 ( V_13 -> V_1 ,
V_64 ,
V_65 ) ;
if ( F_10 ( V_30 ) )
F_31 ( L_18 ) ;
}
F_37 ( & V_13 -> V_45 ) ;
F_19 ( V_13 ) ;
}
F_54 ( V_16 ) ;
F_37 ( & V_16 -> V_55 ) ;
F_19 ( V_16 ) ;
V_16 = V_54 ;
}
if ( V_17 -> V_37 )
F_55 ( & V_17 -> V_14 -> V_79 ) ;
F_27 ( V_17 -> V_37 ) ;
F_37 ( & V_17 -> V_68 ) ;
F_19 ( V_17 ) ;
}
static T_1
F_56 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_26 * V_17 ;
F_34 ( V_67 , V_1 , ( T_3 ) 1 ,
F_56 , NULL , NULL , NULL ) ;
V_17 = F_49 ( V_1 ) ;
if ( V_17 )
F_50 ( V_17 ) ;
return V_7 ;
}
static void F_57 ( T_2 V_1 )
{
struct V_26 * V_17 ;
F_34 ( V_67 , V_1 ,
( T_3 ) 1 , F_56 , NULL , NULL , NULL ) ;
V_17 = F_49 ( V_1 ) ;
if ( V_17 )
F_50 ( V_17 ) ;
else
F_38 ( V_1 , V_64 ,
V_72 ) ;
}
static int F_58 ( struct V_27 * V_16 )
{
T_1 V_30 ;
struct V_12 * V_13 ;
int V_35 = 0 ;
if ( V_16 -> V_46 & V_61 )
goto V_59;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_46 & V_49 ) {
F_21 ( L_27 , V_81 ) ;
V_30 = F_59 ( V_13 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_10 ( V_30 ) ) {
F_11 ( L_28 , V_81 ) ;
V_35 = - 1 ;
goto V_59;
} else
break;
}
}
V_16 -> V_46 |= V_61 ;
V_59:
return V_35 ;
}
static int F_60 ( struct V_27 * V_16 )
{
T_1 V_30 ;
struct V_12 * V_13 ;
int V_35 = 0 ;
if ( ( V_16 -> V_46 & V_61 ) == 0 )
goto V_59;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_46 & V_50 ) {
V_30 = F_59 ( V_13 -> V_1 , L_6 , NULL , NULL ) ;
if ( F_10 ( V_30 ) ) {
F_11 ( L_29 , V_81 ) ;
V_35 = - 1 ;
goto V_59;
} else
break;
}
}
V_16 -> V_46 &= ( ~ V_61 ) ;
V_59:
return V_35 ;
}
static unsigned char F_61 ( struct V_14 * V_15 )
{
struct V_83 * V_29 ;
unsigned char V_84 , V_85 ;
V_84 = V_15 -> V_22 . V_23 ;
F_62 (tmp, &bus->children) {
V_85 = F_63 ( F_64 ( V_29 ) ) ;
if ( V_85 > V_84 )
V_84 = V_85 ;
}
return V_84 ;
}
static int F_65 ( struct V_12 * V_13 )
{
T_2 V_86 ;
struct V_87 * V_33 , * V_88 ;
int V_89 ;
F_66 ( V_13 -> V_1 , & V_86 ) ;
if ( F_67 ( V_86 , & V_88 ) ) {
F_21 ( L_30 ) ;
V_88 = NULL ;
}
if ( ! F_67 ( V_13 -> V_1 , & V_33 ) ) {
F_21 ( L_31 ) ;
V_89 = F_68 ( V_33 , 1 ) ;
F_21 ( L_32 , V_89 ) ;
}
V_89 = F_69 ( & V_33 , V_88 , V_13 -> V_1 ,
V_90 ) ;
if ( V_89 ) {
F_21 ( L_33 ,
- V_89 ) ;
goto V_91;
}
V_89 = F_70 ( V_33 ) ;
V_91:
return V_89 ;
}
static int F_71 ( T_2 V_1 )
{
struct V_87 * V_33 ;
int V_35 ;
V_35 = F_67 ( V_1 , & V_33 ) ;
if ( V_35 ) {
F_21 ( L_34 ) ;
return V_35 ;
}
V_35 = F_68 ( V_33 , 1 ) ;
if ( V_35 )
F_31 ( L_35 ) ;
return V_35 ;
}
static void F_72 ( struct V_27 * V_16 )
{
struct V_12 * V_13 ;
union V_92 V_93 [ 2 ] ;
struct V_94 V_95 ;
F_40 (func, &slot->funcs, sibling) {
V_95 . V_5 = 2 ;
V_95 . V_96 = V_93 ;
V_93 [ 0 ] . type = V_97 ;
V_93 [ 0 ] . integer . V_98 = V_99 ;
V_93 [ 1 ] . type = V_97 ;
V_93 [ 1 ] . integer . V_98 = 1 ;
F_59 ( V_13 -> V_1 , L_36 , & V_95 , NULL ) ;
}
}
static int T_4 F_73 ( struct V_27 * V_16 )
{
struct V_37 * V_79 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_12 * V_13 ;
int V_35 = 0 ;
int V_100 , V_84 , V_101 ;
T_1 V_30 ;
if ( V_16 -> V_46 & V_60 )
goto V_59;
V_100 = F_74 ( V_15 , F_26 ( V_16 -> V_33 , 0 ) ) ;
if ( V_100 == 0 ) {
F_21 ( L_37 ) ;
goto V_59;
}
V_84 = F_61 ( V_15 ) ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ ) {
F_40 (dev, &bus->devices, bus_list) {
if ( F_75 ( V_79 -> V_102 ) != V_16 -> V_33 )
continue;
if ( V_79 -> V_103 == V_104 ||
V_79 -> V_103 == V_105 ) {
V_84 = F_76 ( V_15 , V_79 , V_84 , V_101 ) ;
if ( V_101 && V_79 -> V_78 )
F_77 ( V_79 -> V_78 ) ;
}
}
}
F_40 (func, &slot->funcs, sibling)
F_65 ( V_13 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_72 ( V_16 ) ;
F_81 ( V_15 ) ;
F_40 (dev, &bus->devices, bus_list) {
if ( ! V_79 -> V_106 )
V_79 -> V_107 = V_108 ;
}
F_82 ( V_15 ) ;
V_16 -> V_46 |= V_60 ;
F_40 (func, &slot->funcs, sibling) {
V_79 = F_25 ( V_15 , F_26 ( V_16 -> V_33 ,
V_13 -> V_34 ) ) ;
if ( ! V_79 ) {
V_16 -> V_46 &= ( ~ V_60 ) ;
continue;
}
if ( V_79 -> V_103 != V_104 &&
V_79 -> V_103 != V_105 ) {
F_27 ( V_79 ) ;
continue;
}
V_30 = F_46 ( V_13 -> V_1 , ( T_3 ) 1 , V_15 , NULL ) ;
if ( F_10 ( V_30 ) )
F_11 ( L_23 ,
V_30 ) ;
F_27 ( V_79 ) ;
}
V_59:
return V_35 ;
}
static void F_83 ( struct V_14 * V_15 )
{
struct V_37 * V_79 ;
F_40 (dev, &bus->devices, bus_list) {
if ( V_79 -> V_78 ) {
F_83 ( V_79 -> V_78 ) ;
F_84 ( V_79 ) ;
}
}
}
static struct V_37 * F_85 ( struct V_27 * V_16 )
{
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_37 * V_79 ;
struct V_37 * V_109 = NULL ;
F_86 ( & V_110 ) ;
F_40 (dev, &bus->devices, bus_list)
if ( F_75 ( V_79 -> V_102 ) == V_16 -> V_33 ) {
V_109 = F_87 ( V_79 ) ;
break;
}
F_88 ( & V_110 ) ;
return V_109 ;
}
static int F_89 ( struct V_27 * V_16 )
{
struct V_12 * V_13 ;
struct V_37 * V_38 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
V_38 = F_25 ( V_15 , F_26 ( V_16 -> V_33 , 0 ) ) ;
if ( ! V_38 )
goto V_59;
F_27 ( V_38 ) ;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_17 ) {
F_56 ( V_13 -> V_17 -> V_1 ,
( T_3 ) 1 , NULL , NULL ) ;
V_13 -> V_17 = NULL ;
}
}
while ( ( V_38 = F_85 ( V_16 ) ) ) {
F_90 ( V_38 ) ;
if ( V_38 -> V_78 ) {
F_83 ( V_38 -> V_78 ) ;
F_84 ( V_38 ) ;
}
F_91 ( V_38 ) ;
F_27 ( V_38 ) ;
}
F_40 (func, &slot->funcs, sibling) {
F_71 ( V_13 -> V_1 ) ;
}
V_16 -> V_46 &= ( ~ V_60 ) ;
V_59:
return 0 ;
}
static unsigned int F_92 ( struct V_27 * V_16 )
{
T_1 V_30 ;
unsigned long long V_111 = 0 ;
T_3 V_112 ;
struct V_12 * V_13 ;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_46 & V_48 ) {
V_30 = F_9 ( V_13 -> V_1 , L_4 , NULL , & V_111 ) ;
if ( F_17 ( V_30 ) && V_111 )
break;
} else {
F_93 ( V_16 -> V_17 -> V_14 ,
F_26 ( V_16 -> V_33 ,
V_13 -> V_34 ) ,
V_113 , & V_112 ) ;
if ( V_112 != 0xffffffff ) {
V_111 = V_114 ;
break;
}
}
}
return ( unsigned int ) V_111 ;
}
int F_94 ( struct V_27 * V_16 )
{
T_1 V_30 ;
struct V_12 * V_13 ;
struct V_94 V_95 ;
union V_92 V_115 ;
F_40 (func, &slot->funcs, sibling) {
if ( ( V_13 -> V_46 & V_47 ) ) {
V_95 . V_5 = 1 ;
V_95 . V_96 = & V_115 ;
V_115 . type = V_97 ;
V_115 . integer . V_98 = 1 ;
V_30 = F_59 ( V_13 -> V_1 , L_3 , & V_95 , NULL ) ;
if ( F_10 ( V_30 ) ) {
F_11 ( L_38 , V_81 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_95 ( struct V_26 * V_17 )
{
struct V_27 * V_16 ;
int V_35 = 0 ;
int V_116 , V_117 ;
V_116 = V_117 = 0 ;
for ( V_16 = V_17 -> V_53 ; V_16 ; V_16 = V_16 -> V_54 ) {
unsigned int V_30 = F_92 ( V_16 ) ;
if ( V_16 -> V_46 & V_60 ) {
if ( V_30 == V_114 )
continue;
V_35 = F_96 ( V_16 ) ;
if ( V_35 ) {
F_31 ( L_39 ) ;
goto V_59;
} else {
F_94 ( V_16 ) ;
}
V_117 ++ ;
} else {
if ( V_30 != V_114 )
continue;
V_35 = F_97 ( V_16 ) ;
if ( V_35 ) {
F_31 ( L_40 ) ;
goto V_59;
}
V_116 ++ ;
}
}
F_21 ( L_41 , V_81 , V_116 , V_117 ) ;
V_59:
return V_35 ;
}
static void F_80 ( struct V_14 * V_15 )
{
struct V_37 * V_79 ;
F_40 (dev, &bus->devices, bus_list)
F_98 ( V_79 ) ;
}
static void F_79 ( struct V_14 * V_15 )
{
struct V_37 * V_79 ;
int V_118 ;
unsigned long V_119 = V_120 | V_121 ;
F_40 (dev, &bus->devices, bus_list) {
for ( V_118 = 0 ; V_118 < V_122 ; V_118 ++ ) {
struct V_123 * V_124 = & V_79 -> V_123 [ V_118 ] ;
if ( ( V_124 -> V_46 & V_119 ) && ! V_124 -> V_23 &&
V_124 -> V_25 ) {
F_99 ( V_79 ) ;
break;
}
}
}
}
static int F_100 ( T_2 V_1 )
{
struct V_14 * V_15 ;
if ( F_101 ( V_1 ) ) {
struct V_39 * V_40 = F_14 ( V_1 ) ;
V_15 = V_40 -> V_15 ;
} else {
struct V_37 * V_38 = F_44 ( V_1 ) ;
V_15 = V_38 -> V_78 ;
F_27 ( V_38 ) ;
}
F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
return 0 ;
}
static void F_102 ( T_2 V_1 , T_3 type )
{
struct V_87 * V_33 , * V_88 ;
T_2 V_86 ;
if ( ( type != V_125 ) &&
( type != V_126 ) ) {
F_31 ( L_42 , type ) ;
return;
}
F_66 ( V_1 , & V_86 ) ;
if ( F_67 ( V_86 , & V_88 ) ) {
F_21 ( L_30 ) ;
V_88 = NULL ;
}
if ( F_69 ( & V_33 , V_88 , V_1 , V_90 ) ) {
F_31 ( L_43 ) ;
return;
}
if ( ! F_100 ( V_1 ) &&
! F_70 ( V_33 ) )
F_48 ( V_1 ) ;
else
F_31 ( L_44 ) ;
}
static T_1
F_103 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
struct V_26 * V_17 ;
V_17 = F_49 ( V_1 ) ;
if ( V_17 )
( * V_5 ) ++ ;
return V_7 ;
}
static T_1
F_104 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_26 * V_17 ;
char V_127 [ 64 ] ;
struct V_128 V_129 = { . V_130 = sizeof( V_127 ) ,
. V_96 = V_127 } ;
V_17 = F_49 ( V_1 ) ;
if ( V_17 ) {
F_105 ( V_1 , V_131 , & V_129 ) ;
F_21 ( L_45 ,
V_81 , V_127 ) ;
F_95 ( V_17 ) ;
}
return V_7 ;
}
static void F_106 ( T_2 V_1 , T_3 type ,
void * V_3 ,
void (* V_13)( struct V_132 * V_133 ) )
{
struct V_134 * V_135 ;
int V_109 ;
V_135 = F_107 ( sizeof( * V_135 ) , V_43 ) ;
if ( ! V_135 )
return;
V_135 -> V_1 = V_1 ;
V_135 -> type = type ;
V_135 -> V_3 = V_3 ;
F_108 ( & V_135 -> V_133 , V_13 ) ;
V_109 = F_109 ( V_136 , & V_135 -> V_133 ) ;
if ( ! V_109 )
F_19 ( V_135 ) ;
}
static void F_110 ( struct V_132 * V_133 )
{
struct V_26 * V_17 ;
char V_127 [ 64 ] ;
struct V_128 V_129 = { . V_130 = sizeof( V_127 ) ,
. V_96 = V_127 } ;
struct V_87 * V_33 ;
int V_137 = 0 ;
struct V_134 * V_135 ;
T_2 V_1 ;
T_3 type ;
V_135 = F_4 ( V_133 , struct V_134 , V_133 ) ;
V_1 = V_135 -> V_1 ;
type = V_135 -> type ;
if ( F_67 ( V_1 , & V_33 ) ) {
F_102 ( V_1 , type ) ;
goto V_80;
}
V_17 = F_49 ( V_1 ) ;
if ( type == V_125 ) {
F_34 ( V_67 , V_1 , V_138 ,
F_103 , NULL , & V_137 , NULL ) ;
}
if ( ! V_17 && ! V_137 ) {
F_31 ( L_46 ) ;
goto V_80;
}
F_105 ( V_1 , V_131 , & V_129 ) ;
switch ( type ) {
case V_125 :
F_21 ( L_47 , V_81 , V_127 ) ;
if ( V_17 ) {
F_21 ( L_45 ,
V_81 , V_127 ) ;
F_95 ( V_17 ) ;
}
if ( V_137 )
F_34 ( V_67 , V_1 ,
V_138 , F_104 , NULL , NULL , NULL ) ;
break;
case V_126 :
F_21 ( L_48 , V_81 , V_127 ) ;
F_95 ( V_17 ) ;
break;
case V_139 :
F_21 ( L_49 , V_81 , V_127 ) ;
break;
case V_140 :
F_21 ( L_50 , V_81 , V_127 ) ;
if ( ( V_17 -> type != V_70 ) &&
( V_17 -> V_46 & V_71 ) ) {
struct V_27 * V_16 ;
V_16 = V_17 -> V_13 -> V_16 ;
if ( ! F_96 ( V_16 ) )
F_94 ( V_16 ) ;
}
break;
case V_141 :
F_111 ( V_142 L_51
L_52 , V_127 ) ;
break;
case V_143 :
F_111 ( V_142 L_51
L_53 , V_127 ) ;
break;
case V_144 :
F_111 ( V_142 L_54 ,
V_127 ) ;
break;
default:
F_11 ( L_55 , type , V_127 ) ;
break;
}
V_80:
F_19 ( V_135 ) ;
}
static void V_72 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_106 ( V_1 , type , V_3 ,
F_110 ) ;
}
static void F_112 ( struct V_132 * V_133 )
{
struct V_12 * V_13 ;
char V_127 [ 64 ] ;
struct V_128 V_129 = { . V_130 = sizeof( V_127 ) ,
. V_96 = V_127 } ;
struct V_134 * V_135 ;
T_2 V_1 ;
T_3 type ;
void * V_3 ;
V_135 = F_4 ( V_133 , struct V_134 , V_133 ) ;
V_1 = V_135 -> V_1 ;
type = V_135 -> type ;
V_3 = V_135 -> V_3 ;
F_105 ( V_1 , V_131 , & V_129 ) ;
V_13 = (struct V_12 * ) V_3 ;
switch ( type ) {
case V_125 :
F_21 ( L_47 , V_81 , V_127 ) ;
F_97 ( V_13 -> V_16 ) ;
break;
case V_126 :
F_21 ( L_48 , V_81 , V_127 ) ;
F_95 ( V_13 -> V_16 -> V_17 ) ;
break;
case V_139 :
F_21 ( L_49 , V_81 , V_127 ) ;
break;
case V_140 :
F_21 ( L_50 , V_81 , V_127 ) ;
if ( ! ( F_96 ( V_13 -> V_16 ) ) )
F_94 ( V_13 -> V_16 ) ;
break;
default:
F_11 ( L_55 , type , V_127 ) ;
break;
}
F_19 ( V_135 ) ;
}
static void V_65 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_106 ( V_1 , type , V_3 ,
F_112 ) ;
}
static T_1
F_113 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( ! F_101 ( V_1 ) )
return V_7 ;
( * V_5 ) ++ ;
F_30 ( V_1 , V_64 ,
V_72 , NULL ) ;
return V_7 ;
}
int T_5 F_114 ( void )
{
int V_100 = 0 ;
F_34 ( V_67 , V_145 ,
V_138 , F_113 , NULL , & V_100 , NULL ) ;
if ( V_100 <= 0 )
return - 1 ;
else
F_115 ( & V_146 ) ;
return 0 ;
}
void F_116 ( void )
{
F_117 ( & V_146 ) ;
}
int T_5 F_118 ( void )
{
struct V_26 * V_17 ;
int V_147 = 0 ;
F_40 (bridge, &bridge_list, list) {
F_21 ( L_56 ,
F_22 ( V_17 -> V_14 ) ,
V_17 -> V_14 -> V_57 , V_17 -> V_52 ,
V_17 -> V_52 == 1 ? L_57 : L_58 ) ;
V_147 += V_17 -> V_52 ;
}
F_21 ( L_59 , V_147 ) ;
return V_147 ;
}
int F_97 ( struct V_27 * V_16 )
{
int V_35 ;
F_119 ( & V_16 -> V_56 ) ;
V_35 = F_58 ( V_16 ) ;
if ( V_35 )
goto V_59;
if ( F_92 ( V_16 ) == V_114 ) {
V_35 = F_73 ( V_16 ) ;
if ( V_35 )
F_60 ( V_16 ) ;
} else {
F_21 ( L_60 , V_81 ) ;
F_60 ( V_16 ) ;
}
V_59:
F_120 ( & V_16 -> V_56 ) ;
return V_35 ;
}
int F_96 ( struct V_27 * V_16 )
{
int V_35 = 0 ;
F_119 ( & V_16 -> V_56 ) ;
V_35 = F_89 ( V_16 ) ;
if ( V_35 )
goto V_59;
V_35 = F_60 ( V_16 ) ;
if ( V_35 )
goto V_59;
V_59:
F_120 ( & V_16 -> V_56 ) ;
return V_35 ;
}
T_6 F_121 ( struct V_27 * V_16 )
{
return ( V_16 -> V_46 & V_61 ) ;
}
T_6 F_122 ( struct V_27 * V_16 )
{
unsigned int V_111 ;
V_111 = F_92 ( V_16 ) ;
return ( V_111 & V_148 ) ? 0 : 1 ;
}
T_6 F_123 ( struct V_27 * V_16 )
{
unsigned int V_111 ;
V_111 = F_92 ( V_16 ) ;
return ( V_111 == 0 ) ? 0 : 1 ;
}
