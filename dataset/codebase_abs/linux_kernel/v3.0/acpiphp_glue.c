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
if ( ( ( V_18 >> 8 ) & 0xff ) != V_15 -> V_22 ) {
V_18 = ( V_18 & 0xff000000 )
| ( ( unsigned int ) ( V_15 -> V_23 ) << 0 )
| ( ( unsigned int ) ( V_15 -> V_22 ) << 8 )
| ( ( unsigned int ) ( V_15 -> V_24 ) << 16 ) ;
F_6 ( V_15 -> V_19 , V_21 , V_18 ) ;
}
return V_20 ;
}
static T_1
F_7 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_25 * V_17 = (struct V_25 * ) V_3 ;
struct V_26 * V_16 ;
struct V_12 * V_27 ;
T_2 V_28 ;
T_1 V_29 = V_7 ;
unsigned long long V_30 , V_31 ;
int V_32 , V_33 , V_34 ;
struct V_14 * V_35 = V_17 -> V_14 ;
struct V_36 * V_37 ;
if ( ! F_8 ( V_35 , V_1 ) && ! F_2 ( V_1 ) )
return V_7 ;
F_9 ( V_1 , L_1 , NULL , & V_30 ) ;
V_32 = ( V_30 >> 16 ) & 0xffff ;
V_33 = V_30 & 0xffff ;
V_27 = F_10 ( sizeof( struct V_12 ) , V_38 ) ;
if ( ! V_27 )
return V_39 ;
F_11 ( & V_27 -> V_40 ) ;
V_27 -> V_1 = V_1 ;
V_27 -> V_33 = V_33 ;
if ( F_12 ( F_13 ( V_1 , L_2 , & V_28 ) ) )
V_27 -> V_41 = V_42 ;
if ( F_12 ( F_13 ( V_1 , L_3 , & V_28 ) ) )
V_27 -> V_41 |= V_43 ;
if ( F_12 ( F_13 ( V_1 , L_4 , & V_28 ) ) )
V_27 -> V_41 |= V_44 ;
if ( F_12 ( F_13 ( V_1 , L_5 , & V_28 ) ) )
V_27 -> V_41 |= V_45 ;
if ( F_12 ( F_13 ( V_1 , L_6 , & V_28 ) ) )
V_27 -> V_41 |= V_46 ;
V_29 = F_9 ( V_1 , L_7 , NULL , & V_31 ) ;
if ( F_14 ( V_29 ) ) {
V_31 = V_17 -> V_47 + 1 ;
}
for ( V_16 = V_17 -> V_48 ; V_16 ; V_16 = V_16 -> V_49 )
if ( V_16 -> V_32 == V_32 ) {
if ( V_16 -> V_31 != V_31 )
F_15 ( L_8 ) ;
break;
}
if ( ! V_16 ) {
V_16 = F_10 ( sizeof( struct V_26 ) , V_38 ) ;
if ( ! V_16 ) {
F_16 ( V_27 ) ;
return V_39 ;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_32 = V_32 ;
V_16 -> V_31 = V_31 ;
F_11 ( & V_16 -> V_50 ) ;
F_17 ( & V_16 -> V_51 ) ;
V_16 -> V_49 = V_17 -> V_48 ;
V_17 -> V_48 = V_16 ;
V_17 -> V_47 ++ ;
F_18 ( L_9 ,
V_16 -> V_31 , F_19 ( V_35 ) , V_35 -> V_52 , V_32 ) ;
V_34 = F_20 ( V_16 ) ;
if ( V_34 ) {
if ( V_34 == - V_53 )
F_15 ( L_10
L_11 , V_16 -> V_31 ) ;
else
F_15 ( L_12
L_13 , V_34 ) ;
goto V_54;
}
}
V_27 -> V_16 = V_16 ;
F_21 ( & V_27 -> V_40 , & V_16 -> V_50 ) ;
V_37 = F_22 ( V_35 , F_23 ( V_32 , V_33 ) ) ;
if ( V_37 ) {
V_37 -> V_55 = V_56 ;
V_16 -> V_41 |= ( V_57 | V_58 ) ;
F_24 ( V_37 ) ;
}
if ( F_2 ( V_1 ) ) {
V_27 -> V_41 &= ~ V_42 ;
if ( F_25 ( V_1 ,
& V_59 , V_27 ) )
F_18 ( L_14 ) ;
V_27 -> V_9 . V_60 = F_3 ;
if ( F_26 ( & V_27 -> V_9 ) )
F_18 ( L_15 ) ;
}
if ( ! ( V_27 -> V_41 & V_46 ) ) {
V_29 = F_27 ( V_1 ,
V_61 ,
V_62 ,
V_27 ) ;
if ( F_14 ( V_29 ) )
F_28 ( L_16 ) ;
} else
V_29 = V_7 ;
return V_29 ;
V_54:
V_17 -> V_47 -- ;
V_17 -> V_48 = V_16 -> V_49 ;
F_16 ( V_16 ) ;
F_16 ( V_27 ) ;
return V_7 ;
}
static int F_29 ( T_2 V_1 )
{
int V_63 = F_30 ( V_1 ) ;
if ( ! V_63 ) {
F_31 ( V_64 , V_1 , ( T_3 ) 1 ,
F_1 , NULL , ( void * ) & V_63 , NULL ) ;
}
return V_63 ;
}
static void F_32 ( struct V_25 * V_17 )
{
T_1 V_29 ;
F_33 ( & V_17 -> V_65 , & V_66 ) ;
V_29 = F_31 ( V_64 , V_17 -> V_1 , ( T_3 ) 1 ,
F_7 , NULL , V_17 , NULL ) ;
if ( F_14 ( V_29 ) ) {
F_34 ( & V_17 -> V_65 ) ;
return;
}
if ( V_17 -> type != V_67 ) {
if ( ( V_17 -> V_41 & V_68 ) && V_17 -> V_13 ) {
V_29 = F_35 ( V_17 -> V_13 -> V_1 ,
V_61 ,
V_62 ) ;
if ( F_14 ( V_29 ) )
F_28 ( L_17 ) ;
}
V_29 = F_27 ( V_17 -> V_1 ,
V_61 ,
V_69 ,
V_17 ) ;
if ( F_14 ( V_29 ) ) {
F_28 ( L_16 ) ;
}
}
}
static struct V_12 * F_36 ( T_2 V_1 )
{
struct V_25 * V_17 ;
struct V_26 * V_16 ;
struct V_12 * V_13 ;
F_37 (bridge, &bridge_list, list) {
for ( V_16 = V_17 -> V_48 ; V_16 ; V_16 = V_16 -> V_49 ) {
F_37 (func, &slot->funcs, sibling) {
if ( V_13 -> V_1 == V_1 )
return V_13 ;
}
}
}
return NULL ;
}
static inline void F_38 ( struct V_25 * V_17 )
{
T_2 V_70 ;
if ( F_12 ( F_13 ( V_17 -> V_1 ,
L_3 , & V_70 ) ) )
V_17 -> V_41 |= V_71 ;
if ( F_12 ( F_13 ( V_17 -> V_1 ,
L_2 , & V_70 ) ) )
V_17 -> V_41 |= V_68 ;
if ( F_12 ( F_13 ( V_17 -> V_1 ,
L_4 , & V_70 ) ) )
V_17 -> V_41 |= V_72 ;
if ( F_12 ( F_13 ( V_17 -> V_1 ,
L_5 , & V_70 ) ) )
V_17 -> V_41 |= V_73 ;
if ( V_17 -> V_41 & V_68 ) {
struct V_12 * V_13 ;
F_18 ( L_18 ) ;
V_13 = F_36 ( V_17 -> V_1 ) ;
if ( ! V_13 )
return;
V_17 -> V_13 = V_13 ;
V_13 -> V_17 = V_17 ;
}
}
static void F_39 ( T_2 * V_1 )
{
struct V_25 * V_17 ;
struct V_74 * V_75 = F_40 ( V_1 ) ;
V_17 = F_10 ( sizeof( struct V_25 ) , V_38 ) ;
if ( V_17 == NULL )
return;
V_17 -> type = V_67 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_14 = V_75 -> V_15 ;
F_41 ( & V_17 -> V_76 ) ;
F_32 ( V_17 ) ;
}
static void F_42 ( T_2 * V_1 )
{
struct V_25 * V_17 ;
V_17 = F_10 ( sizeof( struct V_25 ) , V_38 ) ;
if ( V_17 == NULL ) {
F_28 ( L_19 ) ;
return;
}
V_17 -> type = V_77 ;
V_17 -> V_1 = V_1 ;
F_38 ( V_17 ) ;
V_17 -> V_36 = F_43 ( V_1 ) ;
V_17 -> V_14 = V_17 -> V_36 -> V_24 ;
if ( ! V_17 -> V_14 ) {
F_28 ( L_20 ) ;
goto F_28;
}
F_44 ( & V_17 -> V_14 -> V_78 ) ;
F_41 ( & V_17 -> V_76 ) ;
F_32 ( V_17 ) ;
return;
F_28:
F_24 ( V_17 -> V_36 ) ;
F_16 ( V_17 ) ;
return;
}
static T_1
F_45 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
T_1 V_29 ;
struct V_36 * V_78 ;
V_78 = F_43 ( V_1 ) ;
if ( ! V_78 || ! V_78 -> V_24 )
goto V_79;
if ( ( F_29 ( V_1 ) > 0 ) ) {
F_18 ( L_21 , F_46 ( V_78 ) ) ;
F_42 ( V_1 ) ;
}
V_29 = F_31 ( V_64 , V_1 , ( T_3 ) 1 ,
F_45 , NULL , NULL , NULL ) ;
if ( F_14 ( V_29 ) )
F_15 ( L_22 , V_29 ) ;
V_79:
F_24 ( V_78 ) ;
return V_7 ;
}
static int F_47 ( T_2 V_1 )
{
T_1 V_29 ;
unsigned long long V_28 ;
T_2 V_70 ;
V_29 = F_13 ( V_1 , L_3 , & V_70 ) ;
if ( F_12 ( V_29 ) ) {
V_29 = F_9 ( V_1 , L_3 , NULL , & V_28 ) ;
if ( F_14 ( V_29 ) ) {
F_18 ( L_23 , V_80 ) ;
return 0 ;
}
if ( ( V_28 & V_81 ) == 0 )
return 0 ;
}
if ( F_29 ( V_1 ) > 0 ) {
F_18 ( L_24 ) ;
F_39 ( V_1 ) ;
}
V_29 = F_31 ( V_64 , V_1 , ( T_3 ) 1 ,
F_45 , NULL , NULL , NULL ) ;
if ( F_14 ( V_29 ) )
F_15 ( L_22 , V_29 ) ;
return 0 ;
}
static struct V_25 * F_48 ( T_2 V_1 )
{
struct V_25 * V_17 ;
F_37 (bridge, &bridge_list, list)
if ( V_17 -> V_1 == V_1 )
return V_17 ;
return NULL ;
}
static void F_49 ( struct V_25 * V_17 )
{
struct V_26 * V_16 , * V_49 ;
struct V_12 * V_13 , * V_28 ;
T_1 V_29 ;
T_2 V_1 = V_17 -> V_1 ;
V_29 = F_35 ( V_1 , V_61 ,
V_69 ) ;
if ( F_14 ( V_29 ) )
F_28 ( L_17 ) ;
if ( ( V_17 -> type != V_67 ) &&
( ( V_17 -> V_41 & V_68 ) && V_17 -> V_13 ) ) {
V_29 = F_27 ( V_17 -> V_13 -> V_1 ,
V_61 ,
V_62 ,
V_17 -> V_13 ) ;
if ( F_14 ( V_29 ) )
F_28 ( L_25 ) ;
}
V_16 = V_17 -> V_48 ;
while ( V_16 ) {
V_49 = V_16 -> V_49 ;
F_50 (func, tmp, &slot->funcs, sibling) {
if ( F_2 ( V_13 -> V_1 ) ) {
F_51 ( V_13 -> V_1 ) ;
F_52 ( & V_13 -> V_9 ) ;
}
if ( ! ( V_13 -> V_41 & V_46 ) ) {
V_29 = F_35 ( V_13 -> V_1 ,
V_61 ,
V_62 ) ;
if ( F_14 ( V_29 ) )
F_28 ( L_17 ) ;
}
F_34 ( & V_13 -> V_40 ) ;
F_16 ( V_13 ) ;
}
F_53 ( V_16 ) ;
F_34 ( & V_16 -> V_50 ) ;
F_16 ( V_16 ) ;
V_16 = V_49 ;
}
if ( V_17 -> V_36 )
F_54 ( & V_17 -> V_14 -> V_78 ) ;
F_24 ( V_17 -> V_36 ) ;
F_34 ( & V_17 -> V_65 ) ;
F_16 ( V_17 ) ;
}
static T_1
F_55 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_25 * V_17 ;
F_31 ( V_64 , V_1 , ( T_3 ) 1 ,
F_55 , NULL , NULL , NULL ) ;
V_17 = F_48 ( V_1 ) ;
if ( V_17 )
F_49 ( V_17 ) ;
return V_7 ;
}
static void F_56 ( T_2 V_1 )
{
struct V_25 * V_17 ;
F_31 ( V_64 , V_1 ,
( T_3 ) 1 , F_55 , NULL , NULL , NULL ) ;
V_17 = F_48 ( V_1 ) ;
if ( V_17 )
F_49 ( V_17 ) ;
else
F_35 ( V_1 , V_61 ,
V_69 ) ;
}
static int F_57 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
if ( V_16 -> V_41 & V_58 )
goto V_54;
F_37 (func, &slot->funcs, sibling) {
if ( V_13 -> V_41 & V_44 ) {
F_18 ( L_26 , V_80 ) ;
V_29 = F_58 ( V_13 -> V_1 , L_4 , NULL , NULL ) ;
if ( F_14 ( V_29 ) ) {
F_15 ( L_27 , V_80 ) ;
V_34 = - 1 ;
goto V_54;
} else
break;
}
}
V_16 -> V_41 |= V_58 ;
V_54:
return V_34 ;
}
static int F_59 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
if ( ( V_16 -> V_41 & V_58 ) == 0 )
goto V_54;
F_37 (func, &slot->funcs, sibling) {
if ( V_13 -> V_41 & V_45 ) {
V_29 = F_58 ( V_13 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_14 ( V_29 ) ) {
F_15 ( L_28 , V_80 ) ;
V_34 = - 1 ;
goto V_54;
} else
break;
}
}
V_16 -> V_41 &= ( ~ V_58 ) ;
V_54:
return V_34 ;
}
static unsigned char F_60 ( struct V_14 * V_15 )
{
struct V_82 * V_28 ;
unsigned char V_83 , V_84 ;
V_83 = V_15 -> V_22 ;
F_61 (tmp, &bus->children) {
V_84 = F_62 ( F_63 ( V_28 ) ) ;
if ( V_84 > V_83 )
V_83 = V_84 ;
}
return V_83 ;
}
static int F_64 ( struct V_12 * V_13 )
{
T_2 V_85 ;
struct V_86 * V_32 , * V_87 ;
int V_88 ;
F_65 ( V_13 -> V_1 , & V_85 ) ;
if ( F_66 ( V_85 , & V_87 ) ) {
F_18 ( L_29 ) ;
V_87 = NULL ;
}
if ( ! F_66 ( V_13 -> V_1 , & V_32 ) ) {
F_18 ( L_30 ) ;
V_88 = F_67 ( V_32 , 1 ) ;
F_18 ( L_31 , V_88 ) ;
}
V_88 = F_68 ( & V_32 , V_87 , V_13 -> V_1 ,
V_89 ) ;
if ( V_88 ) {
F_18 ( L_32 ,
- V_88 ) ;
goto V_90;
}
V_88 = F_69 ( V_32 ) ;
V_90:
return V_88 ;
}
static int F_70 ( T_2 V_1 )
{
struct V_86 * V_32 ;
int V_34 ;
V_34 = F_66 ( V_1 , & V_32 ) ;
if ( V_34 ) {
F_18 ( L_33 ) ;
return V_34 ;
}
V_34 = F_67 ( V_32 , 1 ) ;
if ( V_34 )
F_28 ( L_34 ) ;
return V_34 ;
}
static void F_71 ( struct V_26 * V_16 )
{
struct V_12 * V_13 ;
union V_91 V_92 [ 2 ] ;
struct V_93 V_94 ;
F_37 (func, &slot->funcs, sibling) {
V_94 . V_5 = 2 ;
V_94 . V_95 = V_92 ;
V_92 [ 0 ] . type = V_96 ;
V_92 [ 0 ] . integer . V_97 = V_98 ;
V_92 [ 1 ] . type = V_96 ;
V_92 [ 1 ] . integer . V_97 = 1 ;
F_58 ( V_13 -> V_1 , L_35 , & V_94 , NULL ) ;
}
}
static int T_4 F_72 ( struct V_26 * V_16 )
{
struct V_36 * V_78 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
int V_99 , V_83 , V_100 ;
T_1 V_29 ;
if ( V_16 -> V_41 & V_57 )
goto V_54;
V_78 = F_22 ( V_15 , F_23 ( V_16 -> V_32 , 0 ) ) ;
if ( V_78 ) {
F_28 ( L_36 ) ;
F_24 ( V_78 ) ;
V_34 = - 1 ;
goto V_54;
}
V_99 = F_73 ( V_15 , F_23 ( V_16 -> V_32 , 0 ) ) ;
if ( V_99 == 0 ) {
F_28 ( L_37 ) ;
V_34 = - 1 ;
goto V_54;
}
V_83 = F_60 ( V_15 ) ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ ) {
F_37 (dev, &bus->devices, bus_list) {
if ( F_74 ( V_78 -> V_101 ) != V_16 -> V_32 )
continue;
if ( V_78 -> V_102 == V_103 ||
V_78 -> V_102 == V_104 ) {
V_83 = F_75 ( V_15 , V_78 , V_83 , V_100 ) ;
if ( V_100 && V_78 -> V_24 )
F_76 ( V_78 -> V_24 ) ;
}
}
}
F_37 (func, &slot->funcs, sibling)
F_64 ( V_13 ) ;
F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_71 ( V_16 ) ;
F_80 ( V_15 ) ;
F_37 (dev, &bus->devices, bus_list) {
if ( ! V_78 -> V_105 )
V_78 -> V_55 = V_56 ;
}
F_81 ( V_15 ) ;
F_37 (func, &slot->funcs, sibling) {
V_78 = F_22 ( V_15 , F_23 ( V_16 -> V_32 ,
V_13 -> V_33 ) ) ;
if ( ! V_78 )
continue;
if ( V_78 -> V_102 != V_103 &&
V_78 -> V_102 != V_104 ) {
F_24 ( V_78 ) ;
continue;
}
V_29 = F_45 ( V_13 -> V_1 , ( T_3 ) 1 , V_15 , NULL ) ;
if ( F_14 ( V_29 ) )
F_15 ( L_22 ,
V_29 ) ;
F_24 ( V_78 ) ;
}
V_16 -> V_41 |= V_57 ;
V_54:
return V_34 ;
}
static void F_82 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
F_37 (dev, &bus->devices, bus_list) {
if ( V_78 -> V_24 ) {
F_82 ( V_78 -> V_24 ) ;
F_83 ( V_78 ) ;
}
}
}
static int F_84 ( struct V_26 * V_16 )
{
struct V_12 * V_13 ;
struct V_36 * V_37 ;
if ( ! ( V_16 -> V_41 & V_57 ) )
goto V_54;
F_37 (func, &slot->funcs, sibling) {
if ( V_13 -> V_17 ) {
F_55 ( V_13 -> V_17 -> V_1 ,
( T_3 ) 1 , NULL , NULL ) ;
V_13 -> V_17 = NULL ;
}
V_37 = F_22 ( V_16 -> V_17 -> V_14 ,
F_23 ( V_16 -> V_32 , V_13 -> V_33 ) ) ;
if ( V_37 ) {
F_85 ( V_37 ) ;
if ( V_37 -> V_24 ) {
F_82 ( V_37 -> V_24 ) ;
F_83 ( V_37 ) ;
}
F_86 ( V_37 ) ;
F_24 ( V_37 ) ;
}
}
F_37 (func, &slot->funcs, sibling) {
F_70 ( V_13 -> V_1 ) ;
}
V_16 -> V_41 &= ( ~ V_57 ) ;
V_54:
return 0 ;
}
static unsigned int F_87 ( struct V_26 * V_16 )
{
T_1 V_29 ;
unsigned long long V_106 = 0 ;
T_3 V_107 ;
struct V_12 * V_13 ;
F_37 (func, &slot->funcs, sibling) {
if ( V_13 -> V_41 & V_43 ) {
V_29 = F_9 ( V_13 -> V_1 , L_3 , NULL , & V_106 ) ;
if ( F_12 ( V_29 ) && V_106 )
break;
} else {
F_88 ( V_16 -> V_17 -> V_14 ,
F_23 ( V_16 -> V_32 ,
V_13 -> V_33 ) ,
V_108 , & V_107 ) ;
if ( V_107 != 0xffffffff ) {
V_106 = V_109 ;
break;
}
}
}
return ( unsigned int ) V_106 ;
}
int F_89 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
struct V_93 V_94 ;
union V_91 V_110 ;
F_37 (func, &slot->funcs, sibling) {
if ( ( V_13 -> V_41 & V_42 ) ) {
V_94 . V_5 = 1 ;
V_94 . V_95 = & V_110 ;
V_110 . type = V_96 ;
V_110 . integer . V_97 = 1 ;
V_29 = F_58 ( V_13 -> V_1 , L_2 , & V_94 , NULL ) ;
if ( F_14 ( V_29 ) ) {
F_15 ( L_38 , V_80 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_90 ( struct V_25 * V_17 )
{
struct V_26 * V_16 ;
int V_34 = 0 ;
int V_111 , V_112 ;
V_111 = V_112 = 0 ;
for ( V_16 = V_17 -> V_48 ; V_16 ; V_16 = V_16 -> V_49 ) {
unsigned int V_29 = F_87 ( V_16 ) ;
if ( V_16 -> V_41 & V_57 ) {
if ( V_29 == V_109 )
continue;
V_34 = F_91 ( V_16 ) ;
if ( V_34 ) {
F_28 ( L_39 ) ;
goto V_54;
} else {
F_89 ( V_16 ) ;
}
V_112 ++ ;
} else {
if ( V_29 != V_109 )
continue;
V_34 = F_92 ( V_16 ) ;
if ( V_34 ) {
F_28 ( L_40 ) ;
goto V_54;
}
V_111 ++ ;
}
}
F_18 ( L_41 , V_80 , V_111 , V_112 ) ;
V_54:
return V_34 ;
}
static void F_79 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
F_37 (dev, &bus->devices, bus_list)
F_93 ( V_78 ) ;
}
static void F_78 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
int V_113 ;
unsigned long V_114 = V_115 | V_116 ;
F_37 (dev, &bus->devices, bus_list) {
for ( V_113 = 0 ; V_113 < V_117 ; V_113 ++ ) {
struct V_118 * V_119 = & V_78 -> V_118 [ V_113 ] ;
if ( ( V_119 -> V_41 & V_114 ) && ! V_119 -> V_120 &&
V_119 -> V_121 ) {
F_86 ( V_78 ) ;
break;
}
}
}
}
static int F_94 ( T_2 V_1 )
{
struct V_14 * V_15 ;
if ( F_95 ( V_1 ) ) {
struct V_74 * V_75 = F_40 ( V_1 ) ;
V_15 = V_75 -> V_15 ;
} else {
struct V_36 * V_37 = F_43 ( V_1 ) ;
V_15 = V_37 -> V_24 ;
F_24 ( V_37 ) ;
}
F_76 ( V_15 ) ;
F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
return 0 ;
}
static void F_96 ( T_2 V_1 , T_3 type )
{
struct V_86 * V_32 , * V_87 ;
T_2 V_85 ;
if ( ( type != V_122 ) &&
( type != V_123 ) ) {
F_28 ( L_42 , type ) ;
return;
}
F_65 ( V_1 , & V_85 ) ;
if ( F_66 ( V_85 , & V_87 ) ) {
F_18 ( L_29 ) ;
V_87 = NULL ;
}
if ( F_68 ( & V_32 , V_87 , V_1 , V_89 ) ) {
F_28 ( L_43 ) ;
return;
}
if ( ! F_94 ( V_1 ) &&
! F_69 ( V_32 ) )
F_47 ( V_1 ) ;
else
F_28 ( L_44 ) ;
}
static T_1
F_97 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
struct V_25 * V_17 ;
V_17 = F_48 ( V_1 ) ;
if ( V_17 )
( * V_5 ) ++ ;
return V_7 ;
}
static T_1
F_98 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_25 * V_17 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_95 = V_124 } ;
V_17 = F_48 ( V_1 ) ;
if ( V_17 ) {
F_99 ( V_1 , V_128 , & V_126 ) ;
F_18 ( L_45 ,
V_80 , V_124 ) ;
F_90 ( V_17 ) ;
}
return V_7 ;
}
static void V_69 ( T_2 V_1 , T_3 type , void * V_3 )
{
struct V_25 * V_17 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_95 = V_124 } ;
struct V_86 * V_32 ;
int V_129 = 0 ;
if ( F_66 ( V_1 , & V_32 ) ) {
F_96 ( V_1 , type ) ;
return;
}
V_17 = F_48 ( V_1 ) ;
if ( type == V_122 ) {
F_31 ( V_64 , V_1 , V_130 ,
F_97 , NULL , & V_129 , NULL ) ;
}
if ( ! V_17 && ! V_129 ) {
F_28 ( L_46 ) ;
return;
}
F_99 ( V_1 , V_128 , & V_126 ) ;
switch ( type ) {
case V_122 :
F_18 ( L_47 , V_80 , V_124 ) ;
if ( V_17 ) {
F_18 ( L_45 ,
V_80 , V_124 ) ;
F_90 ( V_17 ) ;
}
if ( V_129 )
F_31 ( V_64 , V_1 ,
V_130 , F_98 , NULL , NULL , NULL ) ;
break;
case V_123 :
F_18 ( L_48 , V_80 , V_124 ) ;
F_90 ( V_17 ) ;
break;
case V_131 :
F_18 ( L_49 , V_80 , V_124 ) ;
break;
case V_132 :
F_18 ( L_50 , V_80 , V_124 ) ;
if ( ( V_17 -> type != V_67 ) &&
( V_17 -> V_41 & V_68 ) ) {
struct V_26 * V_16 ;
V_16 = V_17 -> V_13 -> V_16 ;
if ( ! F_91 ( V_16 ) )
F_89 ( V_16 ) ;
}
break;
case V_133 :
F_100 ( V_134 L_51
L_52 , V_124 ) ;
break;
case V_135 :
F_100 ( V_134 L_51
L_53 , V_124 ) ;
break;
case V_136 :
F_100 ( V_134 L_54 ,
V_124 ) ;
break;
default:
F_15 ( L_55 , type , V_124 ) ;
break;
}
}
static void V_62 ( T_2 V_1 , T_3 type , void * V_3 )
{
struct V_12 * V_13 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_95 = V_124 } ;
F_99 ( V_1 , V_128 , & V_126 ) ;
V_13 = (struct V_12 * ) V_3 ;
switch ( type ) {
case V_122 :
F_18 ( L_47 , V_80 , V_124 ) ;
F_92 ( V_13 -> V_16 ) ;
break;
case V_123 :
F_18 ( L_48 , V_80 , V_124 ) ;
F_90 ( V_13 -> V_16 -> V_17 ) ;
break;
case V_131 :
F_18 ( L_49 , V_80 , V_124 ) ;
break;
case V_132 :
F_18 ( L_50 , V_80 , V_124 ) ;
if ( ! ( F_91 ( V_13 -> V_16 ) ) )
F_89 ( V_13 -> V_16 ) ;
break;
default:
F_15 ( L_55 , type , V_124 ) ;
break;
}
}
static T_1
F_101 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( F_95 ( V_1 ) ) {
F_27 ( V_1 , V_61 ,
V_69 , NULL ) ;
( * V_5 ) ++ ;
}
return V_7 ;
}
int T_5 F_102 ( void )
{
int V_99 = 0 ;
F_31 ( V_64 , V_137 ,
V_130 , F_101 , NULL , & V_99 , NULL ) ;
if ( V_99 <= 0 )
return - 1 ;
else
F_103 ( & V_138 ) ;
return 0 ;
}
void F_104 ( void )
{
F_105 ( & V_138 ) ;
}
int T_5 F_106 ( void )
{
struct V_25 * V_17 ;
int V_139 = 0 ;
F_37 (bridge, &bridge_list, list) {
F_18 ( L_56 ,
F_19 ( V_17 -> V_14 ) ,
V_17 -> V_14 -> V_52 , V_17 -> V_47 ,
V_17 -> V_47 == 1 ? L_57 : L_58 ) ;
V_139 += V_17 -> V_47 ;
}
F_18 ( L_59 , V_139 ) ;
return V_139 ;
}
int F_92 ( struct V_26 * V_16 )
{
int V_34 ;
F_107 ( & V_16 -> V_51 ) ;
V_34 = F_57 ( V_16 ) ;
if ( V_34 )
goto V_54;
if ( F_87 ( V_16 ) == V_109 ) {
V_34 = F_72 ( V_16 ) ;
if ( V_34 )
F_59 ( V_16 ) ;
} else {
F_18 ( L_60 , V_80 ) ;
F_59 ( V_16 ) ;
}
V_54:
F_108 ( & V_16 -> V_51 ) ;
return V_34 ;
}
int F_91 ( struct V_26 * V_16 )
{
int V_34 = 0 ;
F_107 ( & V_16 -> V_51 ) ;
V_34 = F_84 ( V_16 ) ;
if ( V_34 )
goto V_54;
V_34 = F_59 ( V_16 ) ;
if ( V_34 )
goto V_54;
V_54:
F_108 ( & V_16 -> V_51 ) ;
return V_34 ;
}
T_6 F_109 ( struct V_26 * V_16 )
{
return ( V_16 -> V_41 & V_58 ) ;
}
T_6 F_110 ( struct V_26 * V_16 )
{
unsigned int V_106 ;
V_106 = F_87 ( V_16 ) ;
return ( V_106 & V_140 ) ? 0 : 1 ;
}
T_6 F_111 ( struct V_26 * V_16 )
{
unsigned int V_106 ;
V_106 = F_87 ( V_16 ) ;
return ( V_106 == 0 ) ? 0 : 1 ;
}
