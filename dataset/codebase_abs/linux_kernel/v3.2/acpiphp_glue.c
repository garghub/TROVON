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
V_37 = V_35 -> V_19 ;
if ( V_37 && F_9 ( V_37 ) ) {
V_28 = F_10 ( V_37 ) ;
if ( V_28 ) {
struct V_38 * V_39 = F_11 ( V_28 ) ;
if ( V_39 && ( V_39 -> V_40 &
V_41 ) )
return V_7 ;
}
}
F_12 ( V_1 , L_1 , NULL , & V_30 ) ;
V_32 = ( V_30 >> 16 ) & 0xffff ;
V_33 = V_30 & 0xffff ;
V_27 = F_13 ( sizeof( struct V_12 ) , V_42 ) ;
if ( ! V_27 )
return V_43 ;
F_14 ( & V_27 -> V_44 ) ;
V_27 -> V_1 = V_1 ;
V_27 -> V_33 = V_33 ;
if ( F_15 ( F_16 ( V_1 , L_2 , & V_28 ) ) )
V_27 -> V_45 = V_46 ;
if ( F_15 ( F_16 ( V_1 , L_3 , & V_28 ) ) )
V_27 -> V_45 |= V_47 ;
if ( F_15 ( F_16 ( V_1 , L_4 , & V_28 ) ) )
V_27 -> V_45 |= V_48 ;
if ( F_15 ( F_16 ( V_1 , L_5 , & V_28 ) ) )
V_27 -> V_45 |= V_49 ;
if ( F_15 ( F_16 ( V_1 , L_6 , & V_28 ) ) )
V_27 -> V_45 |= V_50 ;
V_29 = F_12 ( V_1 , L_7 , NULL , & V_31 ) ;
if ( F_17 ( V_29 ) ) {
V_31 = V_17 -> V_51 + 1 ;
}
for ( V_16 = V_17 -> V_52 ; V_16 ; V_16 = V_16 -> V_53 )
if ( V_16 -> V_32 == V_32 ) {
if ( V_16 -> V_31 != V_31 )
F_18 ( L_8 ) ;
break;
}
if ( ! V_16 ) {
V_16 = F_13 ( sizeof( struct V_26 ) , V_42 ) ;
if ( ! V_16 ) {
F_19 ( V_27 ) ;
return V_43 ;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_32 = V_32 ;
V_16 -> V_31 = V_31 ;
F_14 ( & V_16 -> V_54 ) ;
F_20 ( & V_16 -> V_55 ) ;
V_16 -> V_53 = V_17 -> V_52 ;
V_17 -> V_52 = V_16 ;
V_17 -> V_51 ++ ;
F_21 ( L_9 ,
V_16 -> V_31 , F_22 ( V_35 ) , V_35 -> V_56 , V_32 ) ;
V_34 = F_23 ( V_16 ) ;
if ( V_34 ) {
if ( V_34 == - V_57 )
F_18 ( L_10
L_11 , V_16 -> V_31 ) ;
else
F_18 ( L_12
L_13 , V_34 ) ;
goto V_58;
}
}
V_27 -> V_16 = V_16 ;
F_24 ( & V_27 -> V_44 , & V_16 -> V_54 ) ;
V_37 = F_25 ( V_35 , F_26 ( V_32 , V_33 ) ) ;
if ( V_37 ) {
V_16 -> V_45 |= ( V_59 | V_60 ) ;
F_27 ( V_37 ) ;
}
if ( F_2 ( V_1 ) ) {
V_27 -> V_45 &= ~ V_46 ;
if ( F_28 ( V_1 ,
& V_61 , V_27 ) )
F_21 ( L_14 ) ;
V_27 -> V_9 . V_62 = F_3 ;
if ( F_29 ( & V_27 -> V_9 ) )
F_21 ( L_15 ) ;
}
if ( ! ( V_27 -> V_45 & V_50 ) ) {
V_29 = F_30 ( V_1 ,
V_63 ,
V_64 ,
V_27 ) ;
if ( F_17 ( V_29 ) )
F_31 ( L_16 ) ;
} else
V_29 = V_7 ;
return V_29 ;
V_58:
V_17 -> V_51 -- ;
V_17 -> V_52 = V_16 -> V_53 ;
F_19 ( V_16 ) ;
F_19 ( V_27 ) ;
return V_7 ;
}
static int F_32 ( T_2 V_1 )
{
int V_65 = F_33 ( V_1 ) ;
if ( ! V_65 ) {
F_34 ( V_66 , V_1 , ( T_3 ) 1 ,
F_1 , NULL , ( void * ) & V_65 , NULL ) ;
}
return V_65 ;
}
static void F_35 ( struct V_25 * V_17 )
{
T_1 V_29 ;
F_36 ( & V_17 -> V_67 , & V_68 ) ;
V_29 = F_34 ( V_66 , V_17 -> V_1 , ( T_3 ) 1 ,
F_7 , NULL , V_17 , NULL ) ;
if ( F_17 ( V_29 ) ) {
F_37 ( & V_17 -> V_67 ) ;
return;
}
if ( V_17 -> type != V_69 ) {
if ( ( V_17 -> V_45 & V_70 ) && V_17 -> V_13 ) {
V_29 = F_38 ( V_17 -> V_13 -> V_1 ,
V_63 ,
V_64 ) ;
if ( F_17 ( V_29 ) )
F_31 ( L_17 ) ;
}
V_29 = F_30 ( V_17 -> V_1 ,
V_63 ,
V_71 ,
V_17 ) ;
if ( F_17 ( V_29 ) ) {
F_31 ( L_16 ) ;
}
}
}
static struct V_12 * F_39 ( T_2 V_1 )
{
struct V_25 * V_17 ;
struct V_26 * V_16 ;
struct V_12 * V_13 ;
F_40 (bridge, &bridge_list, list) {
for ( V_16 = V_17 -> V_52 ; V_16 ; V_16 = V_16 -> V_53 ) {
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_1 == V_1 )
return V_13 ;
}
}
}
return NULL ;
}
static inline void F_41 ( struct V_25 * V_17 )
{
T_2 V_72 ;
if ( F_15 ( F_16 ( V_17 -> V_1 ,
L_3 , & V_72 ) ) )
V_17 -> V_45 |= V_73 ;
if ( F_15 ( F_16 ( V_17 -> V_1 ,
L_2 , & V_72 ) ) )
V_17 -> V_45 |= V_70 ;
if ( F_15 ( F_16 ( V_17 -> V_1 ,
L_4 , & V_72 ) ) )
V_17 -> V_45 |= V_74 ;
if ( F_15 ( F_16 ( V_17 -> V_1 ,
L_5 , & V_72 ) ) )
V_17 -> V_45 |= V_75 ;
if ( V_17 -> V_45 & V_70 ) {
struct V_12 * V_13 ;
F_21 ( L_18 ) ;
V_13 = F_39 ( V_17 -> V_1 ) ;
if ( ! V_13 )
return;
V_17 -> V_13 = V_13 ;
V_13 -> V_17 = V_17 ;
}
}
static void F_42 ( T_2 * V_1 )
{
struct V_25 * V_17 ;
struct V_38 * V_39 = F_11 ( V_1 ) ;
V_17 = F_13 ( sizeof( struct V_25 ) , V_42 ) ;
if ( V_17 == NULL )
return;
V_17 -> type = V_69 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_14 = V_39 -> V_15 ;
F_43 ( & V_17 -> V_76 ) ;
F_35 ( V_17 ) ;
}
static void F_44 ( T_2 * V_1 )
{
struct V_25 * V_17 ;
V_17 = F_13 ( sizeof( struct V_25 ) , V_42 ) ;
if ( V_17 == NULL ) {
F_31 ( L_19 ) ;
return;
}
V_17 -> type = V_77 ;
V_17 -> V_1 = V_1 ;
F_41 ( V_17 ) ;
V_17 -> V_36 = F_45 ( V_1 ) ;
V_17 -> V_14 = V_17 -> V_36 -> V_24 ;
if ( ! V_17 -> V_14 ) {
F_31 ( L_20 ) ;
goto F_31;
}
F_46 ( & V_17 -> V_14 -> V_78 ) ;
F_43 ( & V_17 -> V_76 ) ;
F_35 ( V_17 ) ;
return;
F_31:
F_27 ( V_17 -> V_36 ) ;
F_19 ( V_17 ) ;
return;
}
static T_1
F_47 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
T_1 V_29 ;
struct V_36 * V_78 ;
V_78 = F_45 ( V_1 ) ;
if ( ! V_78 || ! V_78 -> V_24 )
goto V_79;
if ( ( F_32 ( V_1 ) > 0 ) ) {
F_21 ( L_21 , F_48 ( V_78 ) ) ;
F_44 ( V_1 ) ;
}
V_29 = F_34 ( V_66 , V_1 , ( T_3 ) 1 ,
F_47 , NULL , NULL , NULL ) ;
if ( F_17 ( V_29 ) )
F_18 ( L_22 , V_29 ) ;
V_79:
F_27 ( V_78 ) ;
return V_7 ;
}
static int F_49 ( T_2 V_1 )
{
T_1 V_29 ;
unsigned long long V_28 ;
T_2 V_72 ;
V_29 = F_16 ( V_1 , L_3 , & V_72 ) ;
if ( F_15 ( V_29 ) ) {
V_29 = F_12 ( V_1 , L_3 , NULL , & V_28 ) ;
if ( F_17 ( V_29 ) ) {
F_21 ( L_23 , V_80 ) ;
return 0 ;
}
if ( ( V_28 & V_81 ) == 0 )
return 0 ;
}
if ( F_32 ( V_1 ) > 0 ) {
F_21 ( L_24 ) ;
F_42 ( V_1 ) ;
}
V_29 = F_34 ( V_66 , V_1 , ( T_3 ) 1 ,
F_47 , NULL , NULL , NULL ) ;
if ( F_17 ( V_29 ) )
F_18 ( L_22 , V_29 ) ;
return 0 ;
}
static struct V_25 * F_50 ( T_2 V_1 )
{
struct V_25 * V_17 ;
F_40 (bridge, &bridge_list, list)
if ( V_17 -> V_1 == V_1 )
return V_17 ;
return NULL ;
}
static void F_51 ( struct V_25 * V_17 )
{
struct V_26 * V_16 , * V_53 ;
struct V_12 * V_13 , * V_28 ;
T_1 V_29 ;
T_2 V_1 = V_17 -> V_1 ;
V_29 = F_38 ( V_1 , V_63 ,
V_71 ) ;
if ( F_17 ( V_29 ) )
F_31 ( L_17 ) ;
if ( ( V_17 -> type != V_69 ) &&
( ( V_17 -> V_45 & V_70 ) && V_17 -> V_13 ) ) {
V_29 = F_30 ( V_17 -> V_13 -> V_1 ,
V_63 ,
V_64 ,
V_17 -> V_13 ) ;
if ( F_17 ( V_29 ) )
F_31 ( L_25 ) ;
}
V_16 = V_17 -> V_52 ;
while ( V_16 ) {
V_53 = V_16 -> V_53 ;
F_52 (func, tmp, &slot->funcs, sibling) {
if ( F_2 ( V_13 -> V_1 ) ) {
F_53 ( V_13 -> V_1 ) ;
F_54 ( & V_13 -> V_9 ) ;
}
if ( ! ( V_13 -> V_45 & V_50 ) ) {
V_29 = F_38 ( V_13 -> V_1 ,
V_63 ,
V_64 ) ;
if ( F_17 ( V_29 ) )
F_31 ( L_17 ) ;
}
F_37 ( & V_13 -> V_44 ) ;
F_19 ( V_13 ) ;
}
F_55 ( V_16 ) ;
F_37 ( & V_16 -> V_54 ) ;
F_19 ( V_16 ) ;
V_16 = V_53 ;
}
if ( V_17 -> V_36 )
F_56 ( & V_17 -> V_14 -> V_78 ) ;
F_27 ( V_17 -> V_36 ) ;
F_37 ( & V_17 -> V_67 ) ;
F_19 ( V_17 ) ;
}
static T_1
F_57 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_25 * V_17 ;
F_34 ( V_66 , V_1 , ( T_3 ) 1 ,
F_57 , NULL , NULL , NULL ) ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
F_51 ( V_17 ) ;
return V_7 ;
}
static void F_58 ( T_2 V_1 )
{
struct V_25 * V_17 ;
F_34 ( V_66 , V_1 ,
( T_3 ) 1 , F_57 , NULL , NULL , NULL ) ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
F_51 ( V_17 ) ;
else
F_38 ( V_1 , V_63 ,
V_71 ) ;
}
static int F_59 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
if ( V_16 -> V_45 & V_60 )
goto V_58;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_45 & V_48 ) {
F_21 ( L_26 , V_80 ) ;
V_29 = F_60 ( V_13 -> V_1 , L_4 , NULL , NULL ) ;
if ( F_17 ( V_29 ) ) {
F_18 ( L_27 , V_80 ) ;
V_34 = - 1 ;
goto V_58;
} else
break;
}
}
V_16 -> V_45 |= V_60 ;
V_58:
return V_34 ;
}
static int F_61 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
if ( ( V_16 -> V_45 & V_60 ) == 0 )
goto V_58;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_45 & V_49 ) {
V_29 = F_60 ( V_13 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_17 ( V_29 ) ) {
F_18 ( L_28 , V_80 ) ;
V_34 = - 1 ;
goto V_58;
} else
break;
}
}
V_16 -> V_45 &= ( ~ V_60 ) ;
V_58:
return V_34 ;
}
static unsigned char F_62 ( struct V_14 * V_15 )
{
struct V_82 * V_28 ;
unsigned char V_83 , V_84 ;
V_83 = V_15 -> V_22 ;
F_63 (tmp, &bus->children) {
V_84 = F_64 ( F_65 ( V_28 ) ) ;
if ( V_84 > V_83 )
V_83 = V_84 ;
}
return V_83 ;
}
static int F_66 ( struct V_12 * V_13 )
{
T_2 V_85 ;
struct V_86 * V_32 , * V_87 ;
int V_88 ;
F_67 ( V_13 -> V_1 , & V_85 ) ;
if ( F_68 ( V_85 , & V_87 ) ) {
F_21 ( L_29 ) ;
V_87 = NULL ;
}
if ( ! F_68 ( V_13 -> V_1 , & V_32 ) ) {
F_21 ( L_30 ) ;
V_88 = F_69 ( V_32 , 1 ) ;
F_21 ( L_31 , V_88 ) ;
}
V_88 = F_70 ( & V_32 , V_87 , V_13 -> V_1 ,
V_89 ) ;
if ( V_88 ) {
F_21 ( L_32 ,
- V_88 ) ;
goto V_90;
}
V_88 = F_71 ( V_32 ) ;
V_90:
return V_88 ;
}
static int F_72 ( T_2 V_1 )
{
struct V_86 * V_32 ;
int V_34 ;
V_34 = F_68 ( V_1 , & V_32 ) ;
if ( V_34 ) {
F_21 ( L_33 ) ;
return V_34 ;
}
V_34 = F_69 ( V_32 , 1 ) ;
if ( V_34 )
F_31 ( L_34 ) ;
return V_34 ;
}
static void F_73 ( struct V_26 * V_16 )
{
struct V_12 * V_13 ;
union V_91 V_92 [ 2 ] ;
struct V_93 V_94 ;
F_40 (func, &slot->funcs, sibling) {
V_94 . V_5 = 2 ;
V_94 . V_95 = V_92 ;
V_92 [ 0 ] . type = V_96 ;
V_92 [ 0 ] . integer . V_97 = V_98 ;
V_92 [ 1 ] . type = V_96 ;
V_92 [ 1 ] . integer . V_97 = 1 ;
F_60 ( V_13 -> V_1 , L_35 , & V_94 , NULL ) ;
}
}
static int T_4 F_74 ( struct V_26 * V_16 )
{
struct V_36 * V_78 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_12 * V_13 ;
int V_34 = 0 ;
int V_99 , V_83 , V_100 ;
T_1 V_29 ;
if ( V_16 -> V_45 & V_59 )
goto V_58;
V_78 = F_25 ( V_15 , F_26 ( V_16 -> V_32 , 0 ) ) ;
if ( V_78 ) {
F_31 ( L_36 ) ;
F_27 ( V_78 ) ;
V_34 = - 1 ;
goto V_58;
}
V_99 = F_75 ( V_15 , F_26 ( V_16 -> V_32 , 0 ) ) ;
if ( V_99 == 0 ) {
F_31 ( L_37 ) ;
V_34 = - 1 ;
goto V_58;
}
V_83 = F_62 ( V_15 ) ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ ) {
F_40 (dev, &bus->devices, bus_list) {
if ( F_76 ( V_78 -> V_101 ) != V_16 -> V_32 )
continue;
if ( V_78 -> V_102 == V_103 ||
V_78 -> V_102 == V_104 ) {
V_83 = F_77 ( V_15 , V_78 , V_83 , V_100 ) ;
if ( V_100 && V_78 -> V_24 )
F_78 ( V_78 -> V_24 ) ;
}
}
}
F_40 (func, &slot->funcs, sibling)
F_66 ( V_13 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
F_73 ( V_16 ) ;
F_82 ( V_15 ) ;
F_40 (dev, &bus->devices, bus_list) {
if ( ! V_78 -> V_105 )
V_78 -> V_106 = V_107 ;
}
F_83 ( V_15 ) ;
F_40 (func, &slot->funcs, sibling) {
V_78 = F_25 ( V_15 , F_26 ( V_16 -> V_32 ,
V_13 -> V_33 ) ) ;
if ( ! V_78 )
continue;
if ( V_78 -> V_102 != V_103 &&
V_78 -> V_102 != V_104 ) {
F_27 ( V_78 ) ;
continue;
}
V_29 = F_47 ( V_13 -> V_1 , ( T_3 ) 1 , V_15 , NULL ) ;
if ( F_17 ( V_29 ) )
F_18 ( L_22 ,
V_29 ) ;
F_27 ( V_78 ) ;
}
V_16 -> V_45 |= V_59 ;
V_58:
return V_34 ;
}
static void F_84 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
F_40 (dev, &bus->devices, bus_list) {
if ( V_78 -> V_24 ) {
F_84 ( V_78 -> V_24 ) ;
F_85 ( V_78 ) ;
}
}
}
static int F_86 ( struct V_26 * V_16 )
{
struct V_12 * V_13 ;
struct V_36 * V_37 ;
if ( ! ( V_16 -> V_45 & V_59 ) )
goto V_58;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_17 ) {
F_57 ( V_13 -> V_17 -> V_1 ,
( T_3 ) 1 , NULL , NULL ) ;
V_13 -> V_17 = NULL ;
}
V_37 = F_25 ( V_16 -> V_17 -> V_14 ,
F_26 ( V_16 -> V_32 , V_13 -> V_33 ) ) ;
if ( V_37 ) {
F_87 ( V_37 ) ;
if ( V_37 -> V_24 ) {
F_84 ( V_37 -> V_24 ) ;
F_85 ( V_37 ) ;
}
F_88 ( V_37 ) ;
F_27 ( V_37 ) ;
}
}
F_40 (func, &slot->funcs, sibling) {
F_72 ( V_13 -> V_1 ) ;
}
V_16 -> V_45 &= ( ~ V_59 ) ;
V_58:
return 0 ;
}
static unsigned int F_89 ( struct V_26 * V_16 )
{
T_1 V_29 ;
unsigned long long V_108 = 0 ;
T_3 V_109 ;
struct V_12 * V_13 ;
F_40 (func, &slot->funcs, sibling) {
if ( V_13 -> V_45 & V_47 ) {
V_29 = F_12 ( V_13 -> V_1 , L_3 , NULL , & V_108 ) ;
if ( F_15 ( V_29 ) && V_108 )
break;
} else {
F_90 ( V_16 -> V_17 -> V_14 ,
F_26 ( V_16 -> V_32 ,
V_13 -> V_33 ) ,
V_110 , & V_109 ) ;
if ( V_109 != 0xffffffff ) {
V_108 = V_111 ;
break;
}
}
}
return ( unsigned int ) V_108 ;
}
int F_91 ( struct V_26 * V_16 )
{
T_1 V_29 ;
struct V_12 * V_13 ;
struct V_93 V_94 ;
union V_91 V_112 ;
F_40 (func, &slot->funcs, sibling) {
if ( ( V_13 -> V_45 & V_46 ) ) {
V_94 . V_5 = 1 ;
V_94 . V_95 = & V_112 ;
V_112 . type = V_96 ;
V_112 . integer . V_97 = 1 ;
V_29 = F_60 ( V_13 -> V_1 , L_2 , & V_94 , NULL ) ;
if ( F_17 ( V_29 ) ) {
F_18 ( L_38 , V_80 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_92 ( struct V_25 * V_17 )
{
struct V_26 * V_16 ;
int V_34 = 0 ;
int V_113 , V_114 ;
V_113 = V_114 = 0 ;
for ( V_16 = V_17 -> V_52 ; V_16 ; V_16 = V_16 -> V_53 ) {
unsigned int V_29 = F_89 ( V_16 ) ;
if ( V_16 -> V_45 & V_59 ) {
if ( V_29 == V_111 )
continue;
V_34 = F_93 ( V_16 ) ;
if ( V_34 ) {
F_31 ( L_39 ) ;
goto V_58;
} else {
F_91 ( V_16 ) ;
}
V_114 ++ ;
} else {
if ( V_29 != V_111 )
continue;
V_34 = F_94 ( V_16 ) ;
if ( V_34 ) {
F_31 ( L_40 ) ;
goto V_58;
}
V_113 ++ ;
}
}
F_21 ( L_41 , V_80 , V_113 , V_114 ) ;
V_58:
return V_34 ;
}
static void F_81 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
F_40 (dev, &bus->devices, bus_list)
F_95 ( V_78 ) ;
}
static void F_80 ( struct V_14 * V_15 )
{
struct V_36 * V_78 ;
int V_115 ;
unsigned long V_116 = V_117 | V_118 ;
F_40 (dev, &bus->devices, bus_list) {
for ( V_115 = 0 ; V_115 < V_119 ; V_115 ++ ) {
struct V_120 * V_121 = & V_78 -> V_120 [ V_115 ] ;
if ( ( V_121 -> V_45 & V_116 ) && ! V_121 -> V_122 &&
V_121 -> V_123 ) {
F_88 ( V_78 ) ;
break;
}
}
}
}
static int F_96 ( T_2 V_1 )
{
struct V_14 * V_15 ;
if ( F_97 ( V_1 ) ) {
struct V_38 * V_39 = F_11 ( V_1 ) ;
V_15 = V_39 -> V_15 ;
} else {
struct V_36 * V_37 = F_45 ( V_1 ) ;
V_15 = V_37 -> V_24 ;
F_27 ( V_37 ) ;
}
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
F_82 ( V_15 ) ;
return 0 ;
}
static void F_98 ( T_2 V_1 , T_3 type )
{
struct V_86 * V_32 , * V_87 ;
T_2 V_85 ;
if ( ( type != V_124 ) &&
( type != V_125 ) ) {
F_31 ( L_42 , type ) ;
return;
}
F_67 ( V_1 , & V_85 ) ;
if ( F_68 ( V_85 , & V_87 ) ) {
F_21 ( L_29 ) ;
V_87 = NULL ;
}
if ( F_70 ( & V_32 , V_87 , V_1 , V_89 ) ) {
F_31 ( L_43 ) ;
return;
}
if ( ! F_96 ( V_1 ) &&
! F_71 ( V_32 ) )
F_49 ( V_1 ) ;
else
F_31 ( L_44 ) ;
}
static T_1
F_99 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
struct V_25 * V_17 ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
( * V_5 ) ++ ;
return V_7 ;
}
static T_1
F_100 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_25 * V_17 ;
char V_126 [ 64 ] ;
struct V_127 V_128 = { . V_129 = sizeof( V_126 ) ,
. V_95 = V_126 } ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 ) {
F_101 ( V_1 , V_130 , & V_128 ) ;
F_21 ( L_45 ,
V_80 , V_126 ) ;
F_92 ( V_17 ) ;
}
return V_7 ;
}
static void F_102 ( T_2 V_1 , T_3 type ,
void * V_3 ,
void (* V_13)( struct V_131 * V_132 ) )
{
struct V_133 * V_134 ;
int V_135 ;
V_134 = F_103 ( sizeof( * V_134 ) , V_42 ) ;
if ( ! V_134 )
return;
V_134 -> V_1 = V_1 ;
V_134 -> type = type ;
V_134 -> V_3 = V_3 ;
F_104 ( & V_134 -> V_132 , V_13 ) ;
V_135 = F_105 ( V_136 , & V_134 -> V_132 ) ;
if ( ! V_135 )
F_19 ( V_134 ) ;
}
static void F_106 ( struct V_131 * V_132 )
{
struct V_25 * V_17 ;
char V_126 [ 64 ] ;
struct V_127 V_128 = { . V_129 = sizeof( V_126 ) ,
. V_95 = V_126 } ;
struct V_86 * V_32 ;
int V_137 = 0 ;
struct V_133 * V_134 ;
T_2 V_1 ;
T_3 type ;
V_134 = F_4 ( V_132 , struct V_133 , V_132 ) ;
V_1 = V_134 -> V_1 ;
type = V_134 -> type ;
if ( F_68 ( V_1 , & V_32 ) ) {
F_98 ( V_1 , type ) ;
goto V_79;
}
V_17 = F_50 ( V_1 ) ;
if ( type == V_124 ) {
F_34 ( V_66 , V_1 , V_138 ,
F_99 , NULL , & V_137 , NULL ) ;
}
if ( ! V_17 && ! V_137 ) {
F_31 ( L_46 ) ;
goto V_79;
}
F_101 ( V_1 , V_130 , & V_128 ) ;
switch ( type ) {
case V_124 :
F_21 ( L_47 , V_80 , V_126 ) ;
if ( V_17 ) {
F_21 ( L_45 ,
V_80 , V_126 ) ;
F_92 ( V_17 ) ;
}
if ( V_137 )
F_34 ( V_66 , V_1 ,
V_138 , F_100 , NULL , NULL , NULL ) ;
break;
case V_125 :
F_21 ( L_48 , V_80 , V_126 ) ;
F_92 ( V_17 ) ;
break;
case V_139 :
F_21 ( L_49 , V_80 , V_126 ) ;
break;
case V_140 :
F_21 ( L_50 , V_80 , V_126 ) ;
if ( ( V_17 -> type != V_69 ) &&
( V_17 -> V_45 & V_70 ) ) {
struct V_26 * V_16 ;
V_16 = V_17 -> V_13 -> V_16 ;
if ( ! F_93 ( V_16 ) )
F_91 ( V_16 ) ;
}
break;
case V_141 :
F_107 ( V_142 L_51
L_52 , V_126 ) ;
break;
case V_143 :
F_107 ( V_142 L_51
L_53 , V_126 ) ;
break;
case V_144 :
F_107 ( V_142 L_54 ,
V_126 ) ;
break;
default:
F_18 ( L_55 , type , V_126 ) ;
break;
}
V_79:
F_19 ( V_134 ) ;
}
static void V_71 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_102 ( V_1 , type , V_3 ,
F_106 ) ;
}
static void F_108 ( struct V_131 * V_132 )
{
struct V_12 * V_13 ;
char V_126 [ 64 ] ;
struct V_127 V_128 = { . V_129 = sizeof( V_126 ) ,
. V_95 = V_126 } ;
struct V_133 * V_134 ;
T_2 V_1 ;
T_3 type ;
void * V_3 ;
V_134 = F_4 ( V_132 , struct V_133 , V_132 ) ;
V_1 = V_134 -> V_1 ;
type = V_134 -> type ;
V_3 = V_134 -> V_3 ;
F_101 ( V_1 , V_130 , & V_128 ) ;
V_13 = (struct V_12 * ) V_3 ;
switch ( type ) {
case V_124 :
F_21 ( L_47 , V_80 , V_126 ) ;
F_94 ( V_13 -> V_16 ) ;
break;
case V_125 :
F_21 ( L_48 , V_80 , V_126 ) ;
F_92 ( V_13 -> V_16 -> V_17 ) ;
break;
case V_139 :
F_21 ( L_49 , V_80 , V_126 ) ;
break;
case V_140 :
F_21 ( L_50 , V_80 , V_126 ) ;
if ( ! ( F_93 ( V_13 -> V_16 ) ) )
F_91 ( V_13 -> V_16 ) ;
break;
default:
F_18 ( L_55 , type , V_126 ) ;
break;
}
F_19 ( V_134 ) ;
}
static void V_64 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_102 ( V_1 , type , V_3 ,
F_108 ) ;
}
static T_1
F_109 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( ! F_97 ( V_1 ) )
return V_7 ;
( * V_5 ) ++ ;
F_30 ( V_1 , V_63 ,
V_71 , NULL ) ;
return V_7 ;
}
int T_5 F_110 ( void )
{
int V_99 = 0 ;
F_34 ( V_66 , V_145 ,
V_138 , F_109 , NULL , & V_99 , NULL ) ;
if ( V_99 <= 0 )
return - 1 ;
else
F_111 ( & V_146 ) ;
return 0 ;
}
void F_112 ( void )
{
F_113 ( & V_146 ) ;
}
int T_5 F_114 ( void )
{
struct V_25 * V_17 ;
int V_147 = 0 ;
F_40 (bridge, &bridge_list, list) {
F_21 ( L_56 ,
F_22 ( V_17 -> V_14 ) ,
V_17 -> V_14 -> V_56 , V_17 -> V_51 ,
V_17 -> V_51 == 1 ? L_57 : L_58 ) ;
V_147 += V_17 -> V_51 ;
}
F_21 ( L_59 , V_147 ) ;
return V_147 ;
}
int F_94 ( struct V_26 * V_16 )
{
int V_34 ;
F_115 ( & V_16 -> V_55 ) ;
V_34 = F_59 ( V_16 ) ;
if ( V_34 )
goto V_58;
if ( F_89 ( V_16 ) == V_111 ) {
V_34 = F_74 ( V_16 ) ;
if ( V_34 )
F_61 ( V_16 ) ;
} else {
F_21 ( L_60 , V_80 ) ;
F_61 ( V_16 ) ;
}
V_58:
F_116 ( & V_16 -> V_55 ) ;
return V_34 ;
}
int F_93 ( struct V_26 * V_16 )
{
int V_34 = 0 ;
F_115 ( & V_16 -> V_55 ) ;
V_34 = F_86 ( V_16 ) ;
if ( V_34 )
goto V_58;
V_34 = F_61 ( V_16 ) ;
if ( V_34 )
goto V_58;
V_58:
F_116 ( & V_16 -> V_55 ) ;
return V_34 ;
}
T_6 F_117 ( struct V_26 * V_16 )
{
return ( V_16 -> V_45 & V_60 ) ;
}
T_6 F_118 ( struct V_26 * V_16 )
{
unsigned int V_108 ;
V_108 = F_89 ( V_16 ) ;
return ( V_108 & V_148 ) ? 0 : 1 ;
}
T_6 F_119 ( struct V_26 * V_16 )
{
unsigned int V_108 ;
V_108 = F_89 ( V_16 ) ;
return ( V_108 == 0 ) ? 0 : 1 ;
}
