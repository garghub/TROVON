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
static bool F_7 ( struct V_26 * V_27 )
{
T_3 V_28 ;
T_2 V_29 ;
struct V_30 * V_31 ;
if ( F_8 ( V_27 , V_32 , & V_28 ) )
return false ;
if ( ! ( V_28 & V_33 ) )
return false ;
V_29 = F_9 ( V_27 ) ;
if ( ! V_29 )
return false ;
V_31 = F_10 ( V_29 ) ;
if ( ! V_31 )
return false ;
if ( ! ( V_31 -> V_34 & V_35 ) )
return false ;
return true ;
}
static T_1
F_11 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_36 * V_17 = (struct V_36 * ) V_3 ;
struct V_37 * V_16 ;
struct V_12 * V_38 ;
T_2 V_29 ;
T_1 V_39 = V_7 ;
unsigned long long V_40 , V_41 ;
int V_42 , V_43 , V_44 ;
struct V_14 * V_45 = V_17 -> V_14 ;
struct V_26 * V_27 ;
if ( ! F_12 ( V_45 , V_1 ) && ! F_2 ( V_1 ) )
return V_7 ;
V_39 = F_13 ( V_1 , L_1 , NULL , & V_40 ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_2 , V_39 ) ;
return V_7 ;
}
V_42 = ( V_40 >> 16 ) & 0xffff ;
V_43 = V_40 & 0xffff ;
V_27 = V_45 -> V_19 ;
if ( V_27 && F_7 ( V_27 ) )
return V_7 ;
V_38 = F_16 ( sizeof( struct V_12 ) , V_46 ) ;
if ( ! V_38 )
return V_47 ;
F_17 ( & V_38 -> V_48 ) ;
V_38 -> V_1 = V_1 ;
V_38 -> V_43 = V_43 ;
if ( F_18 ( F_19 ( V_1 , L_3 , & V_29 ) ) )
V_38 -> V_49 = V_50 ;
if ( F_18 ( F_19 ( V_1 , L_4 , & V_29 ) ) )
V_38 -> V_49 |= V_51 ;
if ( F_18 ( F_19 ( V_1 , L_5 , & V_29 ) ) )
V_38 -> V_49 |= V_52 ;
if ( F_18 ( F_19 ( V_1 , L_6 , & V_29 ) ) )
V_38 -> V_49 |= V_53 ;
if ( F_18 ( F_19 ( V_1 , L_7 , & V_29 ) ) )
V_38 -> V_49 |= V_54 ;
V_39 = F_13 ( V_1 , L_8 , NULL , & V_41 ) ;
if ( F_14 ( V_39 ) ) {
V_41 = V_17 -> V_55 + 1 ;
}
for ( V_16 = V_17 -> V_56 ; V_16 ; V_16 = V_16 -> V_57 )
if ( V_16 -> V_42 == V_42 ) {
if ( V_16 -> V_41 != V_41 )
F_15 ( L_9 ) ;
break;
}
if ( ! V_16 ) {
V_16 = F_16 ( sizeof( struct V_37 ) , V_46 ) ;
if ( ! V_16 ) {
F_20 ( V_38 ) ;
return V_47 ;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_42 = V_42 ;
V_16 -> V_41 = V_41 ;
F_17 ( & V_16 -> V_58 ) ;
F_21 ( & V_16 -> V_59 ) ;
V_16 -> V_57 = V_17 -> V_56 ;
V_17 -> V_56 = V_16 ;
V_17 -> V_55 ++ ;
F_22 ( L_10 ,
V_16 -> V_41 , F_23 ( V_45 ) , V_45 -> V_60 , V_42 ) ;
V_44 = F_24 ( V_16 ) ;
if ( V_44 ) {
if ( V_44 == - V_61 )
F_15 ( L_11
L_12 , V_16 -> V_41 ) ;
else
F_15 ( L_13
L_14 , V_44 ) ;
goto V_62;
}
}
V_38 -> V_16 = V_16 ;
F_25 ( & V_38 -> V_48 , & V_16 -> V_58 ) ;
V_27 = F_26 ( V_45 , F_27 ( V_42 , V_43 ) ) ;
if ( V_27 ) {
V_16 -> V_49 |= ( V_63 | V_64 ) ;
F_28 ( V_27 ) ;
}
if ( F_2 ( V_1 ) ) {
V_38 -> V_49 &= ~ V_50 ;
if ( F_29 ( V_1 ,
& V_65 , V_38 ) )
F_22 ( L_15 ) ;
V_38 -> V_9 . V_66 = F_3 ;
if ( F_30 ( & V_38 -> V_9 ) )
F_22 ( L_16 ) ;
}
if ( ! ( V_38 -> V_49 & V_54 ) ) {
V_39 = F_31 ( V_1 ,
V_67 ,
V_68 ,
V_38 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_17 ) ;
} else
V_39 = V_7 ;
return V_39 ;
V_62:
V_17 -> V_55 -- ;
V_17 -> V_56 = V_16 -> V_57 ;
F_20 ( V_16 ) ;
F_20 ( V_38 ) ;
return V_7 ;
}
static int F_33 ( T_2 V_1 )
{
int V_69 = F_34 ( V_1 ) ;
if ( ! V_69 ) {
F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_1 , NULL , ( void * ) & V_69 , NULL ) ;
}
return V_69 ;
}
static void F_36 ( struct V_36 * V_17 )
{
T_1 V_39 ;
F_37 ( & V_17 -> V_71 , & V_72 ) ;
V_39 = F_35 ( V_70 , V_17 -> V_1 , ( T_3 ) 1 ,
F_11 , NULL , V_17 , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_38 ( & V_17 -> V_71 ) ;
return;
}
if ( V_17 -> type != V_73 ) {
if ( ( V_17 -> V_49 & V_74 ) && V_17 -> V_13 ) {
V_39 = F_39 ( V_17 -> V_13 -> V_1 ,
V_67 ,
V_68 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
}
V_39 = F_31 ( V_17 -> V_1 ,
V_67 ,
V_75 ,
V_17 ) ;
if ( F_14 ( V_39 ) ) {
F_32 ( L_17 ) ;
}
}
}
static struct V_12 * F_40 ( T_2 V_1 )
{
struct V_36 * V_17 ;
struct V_37 * V_16 ;
struct V_12 * V_13 ;
F_41 (bridge, &bridge_list, list) {
for ( V_16 = V_17 -> V_56 ; V_16 ; V_16 = V_16 -> V_57 ) {
F_41 (func, &slot->funcs, sibling) {
if ( V_13 -> V_1 == V_1 )
return V_13 ;
}
}
}
return NULL ;
}
static inline void F_42 ( struct V_36 * V_17 )
{
T_2 V_76 ;
if ( F_18 ( F_19 ( V_17 -> V_1 ,
L_4 , & V_76 ) ) )
V_17 -> V_49 |= V_77 ;
if ( F_18 ( F_19 ( V_17 -> V_1 ,
L_3 , & V_76 ) ) )
V_17 -> V_49 |= V_74 ;
if ( F_18 ( F_19 ( V_17 -> V_1 ,
L_5 , & V_76 ) ) )
V_17 -> V_49 |= V_78 ;
if ( F_18 ( F_19 ( V_17 -> V_1 ,
L_6 , & V_76 ) ) )
V_17 -> V_49 |= V_79 ;
if ( V_17 -> V_49 & V_74 ) {
struct V_12 * V_13 ;
F_22 ( L_19 ) ;
V_13 = F_40 ( V_17 -> V_1 ) ;
if ( ! V_13 )
return;
V_17 -> V_13 = V_13 ;
V_13 -> V_17 = V_17 ;
}
}
static void F_43 ( struct V_30 * V_31 )
{
struct V_36 * V_17 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
V_17 = F_16 ( sizeof( struct V_36 ) , V_46 ) ;
if ( V_17 == NULL )
return;
V_17 -> type = V_73 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_14 = V_31 -> V_15 ;
F_36 ( V_17 ) ;
}
static void F_44 ( T_2 * V_1 )
{
struct V_36 * V_17 ;
V_17 = F_16 ( sizeof( struct V_36 ) , V_46 ) ;
if ( V_17 == NULL ) {
F_32 ( L_20 ) ;
return;
}
V_17 -> type = V_80 ;
V_17 -> V_1 = V_1 ;
F_42 ( V_17 ) ;
V_17 -> V_26 = F_45 ( V_1 ) ;
V_17 -> V_14 = V_17 -> V_26 -> V_81 ;
if ( ! V_17 -> V_14 ) {
F_32 ( L_21 ) ;
goto F_32;
}
F_46 ( & V_17 -> V_14 -> V_82 ) ;
F_36 ( V_17 ) ;
return;
F_32:
F_28 ( V_17 -> V_26 ) ;
F_20 ( V_17 ) ;
return;
}
static T_1
F_47 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
T_1 V_39 ;
struct V_26 * V_82 ;
V_82 = F_45 ( V_1 ) ;
if ( ! V_82 || ! V_82 -> V_81 )
goto V_83;
if ( ( F_33 ( V_1 ) > 0 ) ) {
F_22 ( L_22 , F_48 ( V_82 ) ) ;
F_44 ( V_1 ) ;
}
V_39 = F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_47 , NULL , NULL , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 , V_39 ) ;
V_83:
F_28 ( V_82 ) ;
return V_7 ;
}
static int F_49 ( struct V_30 * V_31 )
{
T_1 V_39 ;
unsigned long long V_29 ;
T_2 V_76 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
V_39 = F_19 ( V_1 , L_4 , & V_76 ) ;
if ( F_18 ( V_39 ) ) {
V_39 = F_13 ( V_1 , L_4 , NULL , & V_29 ) ;
if ( F_14 ( V_39 ) ) {
F_22 ( L_24 , V_84 ) ;
return 0 ;
}
if ( ( V_29 & V_85 ) == 0 )
return 0 ;
}
if ( F_33 ( V_1 ) > 0 ) {
F_22 ( L_25 ) ;
F_43 ( V_31 ) ;
}
V_39 = F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_47 , NULL , NULL , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 , V_39 ) ;
return 0 ;
}
static struct V_36 * F_50 ( T_2 V_1 )
{
struct V_36 * V_17 ;
F_41 (bridge, &bridge_list, list)
if ( V_17 -> V_1 == V_1 )
return V_17 ;
return NULL ;
}
static void F_51 ( struct V_36 * V_17 )
{
struct V_37 * V_16 , * V_57 ;
struct V_12 * V_13 , * V_29 ;
T_1 V_39 ;
T_2 V_1 = V_17 -> V_1 ;
V_39 = F_39 ( V_1 , V_67 ,
V_75 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
if ( ( V_17 -> type != V_73 ) &&
( ( V_17 -> V_49 & V_74 ) && V_17 -> V_13 ) ) {
V_39 = F_31 ( V_17 -> V_13 -> V_1 ,
V_67 ,
V_68 ,
V_17 -> V_13 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_26 ) ;
}
V_16 = V_17 -> V_56 ;
while ( V_16 ) {
V_57 = V_16 -> V_57 ;
F_52 (func, tmp, &slot->funcs, sibling) {
if ( F_2 ( V_13 -> V_1 ) ) {
F_53 ( V_13 -> V_1 ) ;
F_54 ( & V_13 -> V_9 ) ;
}
if ( ! ( V_13 -> V_49 & V_54 ) ) {
V_39 = F_39 ( V_13 -> V_1 ,
V_67 ,
V_68 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
}
F_38 ( & V_13 -> V_48 ) ;
F_20 ( V_13 ) ;
}
F_55 ( V_16 ) ;
F_38 ( & V_16 -> V_58 ) ;
F_20 ( V_16 ) ;
V_16 = V_57 ;
}
if ( V_17 -> V_26 )
F_56 ( & V_17 -> V_14 -> V_82 ) ;
F_28 ( V_17 -> V_26 ) ;
F_38 ( & V_17 -> V_71 ) ;
F_20 ( V_17 ) ;
}
static T_1
F_57 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_36 * V_17 ;
F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_57 , NULL , NULL , NULL ) ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
F_51 ( V_17 ) ;
return V_7 ;
}
static void F_58 ( struct V_30 * V_31 )
{
struct V_36 * V_17 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
F_35 ( V_70 , V_1 ,
( T_3 ) 1 , F_57 , NULL , NULL , NULL ) ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
F_51 ( V_17 ) ;
else
F_39 ( V_1 , V_67 ,
V_75 ) ;
}
static int F_59 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
if ( V_16 -> V_49 & V_64 )
goto V_62;
F_41 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_52 ) {
F_22 ( L_27 , V_84 ) ;
V_39 = F_60 ( V_13 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_28 , V_84 ) ;
V_44 = - 1 ;
goto V_62;
} else
break;
}
}
V_16 -> V_49 |= V_64 ;
V_62:
return V_44 ;
}
static int F_61 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
if ( ( V_16 -> V_49 & V_64 ) == 0 )
goto V_62;
F_41 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_53 ) {
V_39 = F_60 ( V_13 -> V_1 , L_6 , NULL , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_29 , V_84 ) ;
V_44 = - 1 ;
goto V_62;
} else
break;
}
}
V_16 -> V_49 &= ( ~ V_64 ) ;
V_62:
return V_44 ;
}
static unsigned char F_62 ( struct V_14 * V_15 )
{
struct V_86 * V_29 ;
unsigned char V_87 , V_88 ;
V_87 = V_15 -> V_22 . V_23 ;
F_63 (tmp, &bus->children) {
V_88 = F_64 ( F_65 ( V_29 ) ) ;
if ( V_88 > V_87 )
V_87 = V_88 ;
}
return V_87 ;
}
static int F_66 ( struct V_12 * V_13 )
{
T_2 V_89 ;
struct V_90 * V_42 , * V_91 ;
int V_92 ;
F_67 ( V_13 -> V_1 , & V_89 ) ;
if ( F_68 ( V_89 , & V_91 ) ) {
F_22 ( L_30 ) ;
V_91 = NULL ;
}
if ( ! F_68 ( V_13 -> V_1 , & V_42 ) ) {
F_22 ( L_31 ) ;
V_92 = F_69 ( V_42 , 1 ) ;
F_22 ( L_32 , V_92 ) ;
}
V_92 = F_70 ( & V_42 , V_91 , V_13 -> V_1 ,
V_93 ) ;
if ( V_92 ) {
F_22 ( L_33 ,
- V_92 ) ;
goto V_94;
}
V_92 = F_71 ( V_42 ) ;
V_94:
return V_92 ;
}
static int F_72 ( T_2 V_1 )
{
struct V_90 * V_42 ;
int V_44 ;
V_44 = F_68 ( V_1 , & V_42 ) ;
if ( V_44 ) {
F_22 ( L_34 ) ;
return V_44 ;
}
V_44 = F_69 ( V_42 , 1 ) ;
if ( V_44 )
F_32 ( L_35 ) ;
return V_44 ;
}
static void F_73 ( struct V_37 * V_16 )
{
struct V_12 * V_13 ;
union V_95 V_96 [ 2 ] ;
struct V_97 V_98 ;
F_41 (func, &slot->funcs, sibling) {
V_98 . V_5 = 2 ;
V_98 . V_99 = V_96 ;
V_96 [ 0 ] . type = V_100 ;
V_96 [ 0 ] . integer . V_101 = V_102 ;
V_96 [ 1 ] . type = V_100 ;
V_96 [ 1 ] . integer . V_101 = 1 ;
F_60 ( V_13 -> V_1 , L_36 , & V_98 , NULL ) ;
}
}
static int T_4 F_74 ( struct V_37 * V_16 )
{
struct V_26 * V_82 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
int V_103 , V_87 , V_104 ;
T_1 V_39 ;
if ( V_16 -> V_49 & V_63 )
goto V_62;
V_103 = F_75 ( V_15 , F_27 ( V_16 -> V_42 , 0 ) ) ;
if ( V_103 == 0 ) {
F_22 ( L_37 ) ;
goto V_62;
}
V_87 = F_62 ( V_15 ) ;
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
F_41 (dev, &bus->devices, bus_list) {
if ( F_76 ( V_82 -> V_105 ) != V_16 -> V_42 )
continue;
if ( V_82 -> V_106 == V_107 ||
V_82 -> V_106 == V_108 ) {
V_87 = F_77 ( V_15 , V_82 , V_87 , V_104 ) ;
if ( V_104 && V_82 -> V_81 )
F_78 ( V_82 -> V_81 ) ;
}
}
}
F_41 (func, &slot->funcs, sibling)
F_66 ( V_13 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
F_73 ( V_16 ) ;
F_82 ( V_15 ) ;
F_41 (dev, &bus->devices, bus_list) {
if ( ! V_82 -> V_109 )
V_82 -> V_110 = V_111 ;
}
F_83 ( V_15 ) ;
V_16 -> V_49 |= V_63 ;
F_41 (func, &slot->funcs, sibling) {
V_82 = F_26 ( V_15 , F_27 ( V_16 -> V_42 ,
V_13 -> V_43 ) ) ;
if ( ! V_82 ) {
V_16 -> V_49 &= ( ~ V_63 ) ;
continue;
}
if ( V_82 -> V_106 != V_107 &&
V_82 -> V_106 != V_108 ) {
F_28 ( V_82 ) ;
continue;
}
V_39 = F_47 ( V_13 -> V_1 , ( T_3 ) 1 , V_15 , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 ,
V_39 ) ;
F_28 ( V_82 ) ;
}
V_62:
return V_44 ;
}
static struct V_26 * F_84 ( struct V_37 * V_16 )
{
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_26 * V_82 ;
struct V_26 * V_112 = NULL ;
F_85 ( & V_113 ) ;
F_41 (dev, &bus->devices, bus_list)
if ( F_76 ( V_82 -> V_105 ) == V_16 -> V_42 ) {
V_112 = F_86 ( V_82 ) ;
break;
}
F_87 ( & V_113 ) ;
return V_112 ;
}
static int F_88 ( struct V_37 * V_16 )
{
struct V_12 * V_13 ;
struct V_26 * V_27 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
V_27 = F_26 ( V_15 , F_27 ( V_16 -> V_42 , 0 ) ) ;
if ( ! V_27 )
goto V_62;
F_28 ( V_27 ) ;
F_41 (func, &slot->funcs, sibling) {
if ( V_13 -> V_17 ) {
F_57 ( V_13 -> V_17 -> V_1 ,
( T_3 ) 1 , NULL , NULL ) ;
V_13 -> V_17 = NULL ;
}
}
while ( ( V_27 = F_84 ( V_16 ) ) ) {
F_89 ( V_27 ) ;
F_28 ( V_27 ) ;
}
F_41 (func, &slot->funcs, sibling) {
F_72 ( V_13 -> V_1 ) ;
}
V_16 -> V_49 &= ( ~ V_63 ) ;
V_62:
return 0 ;
}
static unsigned int F_90 ( struct V_37 * V_16 )
{
T_1 V_39 ;
unsigned long long V_114 = 0 ;
T_3 V_115 ;
struct V_12 * V_13 ;
F_41 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_51 ) {
V_39 = F_13 ( V_13 -> V_1 , L_4 , NULL , & V_114 ) ;
if ( F_18 ( V_39 ) && V_114 )
break;
} else {
F_91 ( V_16 -> V_17 -> V_14 ,
F_27 ( V_16 -> V_42 ,
V_13 -> V_43 ) ,
V_116 , & V_115 ) ;
if ( V_115 != 0xffffffff ) {
V_114 = V_117 ;
break;
}
}
}
return ( unsigned int ) V_114 ;
}
int F_92 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
struct V_97 V_98 ;
union V_95 V_118 ;
F_41 (func, &slot->funcs, sibling) {
if ( ( V_13 -> V_49 & V_50 ) ) {
V_98 . V_5 = 1 ;
V_98 . V_99 = & V_118 ;
V_118 . type = V_100 ;
V_118 . integer . V_101 = 1 ;
V_39 = F_60 ( V_13 -> V_1 , L_3 , & V_98 , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_38 , V_84 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_93 ( struct V_36 * V_17 )
{
struct V_37 * V_16 ;
int V_44 = 0 ;
int V_119 , V_120 ;
V_119 = V_120 = 0 ;
for ( V_16 = V_17 -> V_56 ; V_16 ; V_16 = V_16 -> V_57 ) {
unsigned int V_39 = F_90 ( V_16 ) ;
if ( V_16 -> V_49 & V_63 ) {
if ( V_39 == V_117 )
continue;
V_44 = F_94 ( V_16 ) ;
if ( V_44 ) {
F_32 ( L_39 ) ;
goto V_62;
} else {
F_92 ( V_16 ) ;
}
V_120 ++ ;
} else {
if ( V_39 != V_117 )
continue;
V_44 = F_95 ( V_16 ) ;
if ( V_44 ) {
F_32 ( L_40 ) ;
goto V_62;
}
V_119 ++ ;
}
}
F_22 ( L_41 , V_84 , V_119 , V_120 ) ;
V_62:
return V_44 ;
}
static void F_81 ( struct V_14 * V_15 )
{
struct V_26 * V_82 ;
F_41 (dev, &bus->devices, bus_list)
F_96 ( V_82 ) ;
}
static void F_80 ( struct V_14 * V_15 )
{
struct V_26 * V_82 ;
int V_121 ;
unsigned long V_122 = V_123 | V_124 ;
F_41 (dev, &bus->devices, bus_list) {
for ( V_121 = 0 ; V_121 < V_125 ; V_121 ++ ) {
struct V_126 * V_127 = & V_82 -> V_126 [ V_121 ] ;
if ( ( V_127 -> V_49 & V_122 ) && ! V_127 -> V_23 &&
V_127 -> V_25 ) {
F_89 ( V_82 ) ;
break;
}
}
}
}
static int F_97 ( T_2 V_1 )
{
struct V_14 * V_15 ;
if ( F_98 ( V_1 ) ) {
struct V_30 * V_31 = F_10 ( V_1 ) ;
V_15 = V_31 -> V_15 ;
} else {
struct V_26 * V_27 = F_45 ( V_1 ) ;
V_15 = V_27 -> V_81 ;
F_28 ( V_27 ) ;
}
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
F_82 ( V_15 ) ;
return 0 ;
}
static void F_99 ( T_2 V_1 , T_3 type )
{
struct V_90 * V_42 , * V_91 ;
T_2 V_89 ;
if ( ( type != V_128 ) &&
( type != V_129 ) ) {
F_32 ( L_42 , type ) ;
return;
}
F_67 ( V_1 , & V_89 ) ;
if ( F_68 ( V_89 , & V_91 ) ) {
F_22 ( L_30 ) ;
V_91 = NULL ;
}
if ( F_70 ( & V_42 , V_91 , V_1 , V_93 ) ) {
F_32 ( L_43 ) ;
return;
}
if ( ! F_97 ( V_1 ) &&
! F_71 ( V_42 ) )
F_49 ( V_1 ) ;
else
F_32 ( L_44 ) ;
}
static T_1
F_100 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
struct V_36 * V_17 ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 )
( * V_5 ) ++ ;
return V_7 ;
}
static T_1
F_101 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_36 * V_17 ;
char V_130 [ 64 ] ;
struct V_131 V_132 = { . V_133 = sizeof( V_130 ) ,
. V_99 = V_130 } ;
V_17 = F_50 ( V_1 ) ;
if ( V_17 ) {
F_102 ( V_1 , V_134 , & V_132 ) ;
F_22 ( L_45 ,
V_84 , V_130 ) ;
F_93 ( V_17 ) ;
}
return V_7 ;
}
static void F_103 ( T_2 V_1 , T_3 type ,
void * V_3 ,
void (* V_13)( struct V_135 * V_136 ) )
{
struct V_137 * V_138 ;
int V_112 ;
V_138 = F_104 ( sizeof( * V_138 ) , V_46 ) ;
if ( ! V_138 )
return;
V_138 -> V_1 = V_1 ;
V_138 -> type = type ;
V_138 -> V_3 = V_3 ;
F_105 ( & V_138 -> V_136 , V_13 ) ;
V_112 = F_106 ( V_139 , & V_138 -> V_136 ) ;
if ( ! V_112 )
F_20 ( V_138 ) ;
}
static void F_107 ( struct V_135 * V_136 )
{
struct V_36 * V_17 ;
char V_130 [ 64 ] ;
struct V_131 V_132 = { . V_133 = sizeof( V_130 ) ,
. V_99 = V_130 } ;
struct V_90 * V_42 ;
int V_140 = 0 ;
struct V_137 * V_138 ;
T_2 V_1 ;
T_3 type ;
V_138 = F_4 ( V_136 , struct V_137 , V_136 ) ;
V_1 = V_138 -> V_1 ;
type = V_138 -> type ;
if ( F_68 ( V_1 , & V_42 ) ) {
F_99 ( V_1 , type ) ;
goto V_83;
}
V_17 = F_50 ( V_1 ) ;
if ( type == V_128 ) {
F_35 ( V_70 , V_1 , V_141 ,
F_100 , NULL , & V_140 , NULL ) ;
}
if ( ! V_17 && ! V_140 ) {
F_32 ( L_46 ) ;
goto V_83;
}
F_102 ( V_1 , V_134 , & V_132 ) ;
switch ( type ) {
case V_128 :
F_22 ( L_47 , V_84 , V_130 ) ;
if ( V_17 ) {
F_22 ( L_45 ,
V_84 , V_130 ) ;
F_93 ( V_17 ) ;
}
if ( V_140 )
F_35 ( V_70 , V_1 ,
V_141 , F_101 , NULL , NULL , NULL ) ;
break;
case V_129 :
F_22 ( L_48 , V_84 , V_130 ) ;
F_93 ( V_17 ) ;
break;
case V_142 :
F_22 ( L_49 , V_84 , V_130 ) ;
break;
case V_143 :
F_22 ( L_50 , V_84 , V_130 ) ;
if ( ( V_17 -> type != V_73 ) &&
( V_17 -> V_49 & V_74 ) ) {
struct V_37 * V_16 ;
V_16 = V_17 -> V_13 -> V_16 ;
if ( ! F_94 ( V_16 ) )
F_92 ( V_16 ) ;
}
break;
case V_144 :
F_108 ( V_145 L_51
L_52 , V_130 ) ;
break;
case V_146 :
F_108 ( V_145 L_51
L_53 , V_130 ) ;
break;
case V_147 :
F_108 ( V_145 L_54 ,
V_130 ) ;
break;
default:
F_15 ( L_55 , type , V_130 ) ;
break;
}
V_83:
F_20 ( V_138 ) ;
}
static void V_75 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_103 ( V_1 , type , V_3 ,
F_107 ) ;
}
static void F_109 ( struct V_135 * V_136 )
{
struct V_12 * V_13 ;
char V_130 [ 64 ] ;
struct V_131 V_132 = { . V_133 = sizeof( V_130 ) ,
. V_99 = V_130 } ;
struct V_137 * V_138 ;
T_2 V_1 ;
T_3 type ;
void * V_3 ;
V_138 = F_4 ( V_136 , struct V_137 , V_136 ) ;
V_1 = V_138 -> V_1 ;
type = V_138 -> type ;
V_3 = V_138 -> V_3 ;
F_102 ( V_1 , V_134 , & V_132 ) ;
V_13 = (struct V_12 * ) V_3 ;
switch ( type ) {
case V_128 :
F_22 ( L_47 , V_84 , V_130 ) ;
F_95 ( V_13 -> V_16 ) ;
break;
case V_129 :
F_22 ( L_48 , V_84 , V_130 ) ;
F_93 ( V_13 -> V_16 -> V_17 ) ;
break;
case V_142 :
F_22 ( L_49 , V_84 , V_130 ) ;
break;
case V_143 :
F_22 ( L_50 , V_84 , V_130 ) ;
if ( ! ( F_94 ( V_13 -> V_16 ) ) )
F_92 ( V_13 -> V_16 ) ;
break;
default:
F_15 ( L_55 , type , V_130 ) ;
break;
}
F_20 ( V_138 ) ;
}
static void V_68 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_103 ( V_1 , type , V_3 ,
F_109 ) ;
}
static T_1
F_110 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( ! F_98 ( V_1 ) )
return V_7 ;
( * V_5 ) ++ ;
F_31 ( V_1 , V_67 ,
V_75 , NULL ) ;
return V_7 ;
}
int T_5 F_111 ( void )
{
int V_103 = 0 ;
F_35 ( V_70 , V_148 ,
V_141 , F_110 , NULL , & V_103 , NULL ) ;
if ( V_103 <= 0 )
return - 1 ;
else
F_112 ( & V_149 ) ;
return 0 ;
}
void F_113 ( void )
{
F_114 ( & V_149 ) ;
}
int T_5 F_115 ( void )
{
struct V_36 * V_17 ;
int V_150 = 0 ;
F_41 (bridge, &bridge_list, list) {
F_22 ( L_56 ,
F_23 ( V_17 -> V_14 ) ,
V_17 -> V_14 -> V_60 , V_17 -> V_55 ,
V_17 -> V_55 == 1 ? L_57 : L_58 ) ;
V_150 += V_17 -> V_55 ;
}
F_22 ( L_59 , V_150 ) ;
return V_150 ;
}
int F_95 ( struct V_37 * V_16 )
{
int V_44 ;
F_116 ( & V_16 -> V_59 ) ;
V_44 = F_59 ( V_16 ) ;
if ( V_44 )
goto V_62;
if ( F_90 ( V_16 ) == V_117 ) {
V_44 = F_74 ( V_16 ) ;
if ( V_44 )
F_61 ( V_16 ) ;
} else {
F_22 ( L_60 , V_84 ) ;
F_61 ( V_16 ) ;
}
V_62:
F_117 ( & V_16 -> V_59 ) ;
return V_44 ;
}
int F_94 ( struct V_37 * V_16 )
{
int V_44 = 0 ;
F_116 ( & V_16 -> V_59 ) ;
V_44 = F_88 ( V_16 ) ;
if ( V_44 )
goto V_62;
V_44 = F_61 ( V_16 ) ;
if ( V_44 )
goto V_62;
V_62:
F_117 ( & V_16 -> V_59 ) ;
return V_44 ;
}
T_6 F_118 ( struct V_37 * V_16 )
{
return ( V_16 -> V_49 & V_64 ) ;
}
T_6 F_119 ( struct V_37 * V_16 )
{
unsigned int V_114 ;
V_114 = F_90 ( V_16 ) ;
return ( V_114 & V_151 ) ? 0 : 1 ;
}
T_6 F_120 ( struct V_37 * V_16 )
{
unsigned int V_114 ;
V_114 = F_90 ( V_16 ) ;
return ( V_114 == 0 ) ? 0 : 1 ;
}
