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
if ( ! F_39 ( V_17 -> V_14 ) ) {
if ( ( V_17 -> V_49 & V_73 ) && V_17 -> V_13 ) {
V_39 = F_40 ( V_17 -> V_13 -> V_1 ,
V_67 ,
V_68 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
}
V_39 = F_31 ( V_17 -> V_1 ,
V_67 ,
V_74 ,
V_17 ) ;
if ( F_14 ( V_39 ) ) {
F_32 ( L_17 ) ;
}
}
}
static struct V_12 * F_41 ( T_2 V_1 )
{
struct V_36 * V_17 ;
struct V_37 * V_16 ;
struct V_12 * V_13 ;
F_42 (bridge, &bridge_list, list) {
for ( V_16 = V_17 -> V_56 ; V_16 ; V_16 = V_16 -> V_57 ) {
F_42 (func, &slot->funcs, sibling) {
if ( V_13 -> V_1 == V_1 )
return V_13 ;
}
}
}
return NULL ;
}
static inline void F_43 ( struct V_36 * V_17 )
{
T_2 V_75 ;
struct V_12 * V_13 ;
if ( F_18 ( F_19 ( V_17 -> V_1 ,
L_3 , & V_75 ) ) ) {
V_17 -> V_49 |= V_73 ;
F_22 ( L_19 ) ;
V_13 = F_41 ( V_17 -> V_1 ) ;
if ( ! V_13 )
return;
V_17 -> V_13 = V_13 ;
V_13 -> V_17 = V_17 ;
}
}
static void F_44 ( struct V_30 * V_31 )
{
struct V_36 * V_17 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
V_17 = F_16 ( sizeof( struct V_36 ) , V_46 ) ;
if ( V_17 == NULL )
return;
V_17 -> V_1 = V_1 ;
V_17 -> V_14 = V_31 -> V_15 ;
F_36 ( V_17 ) ;
}
static void F_45 ( T_2 * V_1 )
{
struct V_36 * V_17 ;
V_17 = F_16 ( sizeof( struct V_36 ) , V_46 ) ;
if ( V_17 == NULL ) {
F_32 ( L_20 ) ;
return;
}
V_17 -> V_1 = V_1 ;
F_43 ( V_17 ) ;
V_17 -> V_26 = F_46 ( V_1 ) ;
V_17 -> V_14 = V_17 -> V_26 -> V_76 ;
if ( ! V_17 -> V_14 ) {
F_32 ( L_21 ) ;
goto F_32;
}
F_47 ( & V_17 -> V_14 -> V_77 ) ;
F_36 ( V_17 ) ;
return;
F_32:
F_28 ( V_17 -> V_26 ) ;
F_20 ( V_17 ) ;
return;
}
static T_1
F_48 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
T_1 V_39 ;
struct V_26 * V_77 ;
V_77 = F_46 ( V_1 ) ;
if ( ! V_77 || ! V_77 -> V_76 )
goto V_78;
if ( ( F_33 ( V_1 ) > 0 ) ) {
F_22 ( L_22 , F_49 ( V_77 ) ) ;
F_45 ( V_1 ) ;
}
V_39 = F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_48 , NULL , NULL , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 , V_39 ) ;
V_78:
F_28 ( V_77 ) ;
return V_7 ;
}
static int F_50 ( struct V_30 * V_31 )
{
T_1 V_39 ;
unsigned long long V_29 ;
T_2 V_75 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
V_39 = F_19 ( V_1 , L_4 , & V_75 ) ;
if ( F_18 ( V_39 ) ) {
V_39 = F_13 ( V_1 , L_4 , NULL , & V_29 ) ;
if ( F_14 ( V_39 ) ) {
F_22 ( L_24 , V_79 ) ;
return 0 ;
}
if ( ( V_29 & V_80 ) == 0 )
return 0 ;
}
if ( F_33 ( V_1 ) > 0 ) {
F_22 ( L_25 ) ;
F_44 ( V_31 ) ;
}
V_39 = F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_48 , NULL , NULL , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 , V_39 ) ;
return 0 ;
}
static struct V_36 * F_51 ( T_2 V_1 )
{
struct V_36 * V_17 ;
F_42 (bridge, &bridge_list, list)
if ( V_17 -> V_1 == V_1 )
return V_17 ;
return NULL ;
}
static void F_52 ( struct V_36 * V_17 )
{
struct V_37 * V_16 , * V_57 ;
struct V_12 * V_13 , * V_29 ;
T_1 V_39 ;
T_2 V_1 = V_17 -> V_1 ;
if ( ! F_39 ( V_17 -> V_14 ) ) {
V_39 = F_40 ( V_1 ,
V_67 ,
V_74 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
}
if ( ( V_17 -> V_49 & V_73 ) && V_17 -> V_13 ) {
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
F_53 (func, tmp, &slot->funcs, sibling) {
if ( F_2 ( V_13 -> V_1 ) ) {
F_54 ( V_13 -> V_1 ) ;
F_55 ( & V_13 -> V_9 ) ;
}
if ( ! ( V_13 -> V_49 & V_54 ) ) {
V_39 = F_40 ( V_13 -> V_1 ,
V_67 ,
V_68 ) ;
if ( F_14 ( V_39 ) )
F_32 ( L_18 ) ;
}
F_38 ( & V_13 -> V_48 ) ;
F_20 ( V_13 ) ;
}
F_56 ( V_16 ) ;
F_38 ( & V_16 -> V_58 ) ;
F_20 ( V_16 ) ;
V_16 = V_57 ;
}
if ( V_17 -> V_26 )
F_57 ( & V_17 -> V_14 -> V_77 ) ;
F_28 ( V_17 -> V_26 ) ;
F_38 ( & V_17 -> V_71 ) ;
F_20 ( V_17 ) ;
}
static T_1
F_58 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_36 * V_17 ;
F_35 ( V_70 , V_1 , ( T_3 ) 1 ,
F_58 , NULL , NULL , NULL ) ;
V_17 = F_51 ( V_1 ) ;
if ( V_17 )
F_52 ( V_17 ) ;
return V_7 ;
}
static void F_59 ( struct V_30 * V_31 )
{
struct V_36 * V_17 ;
T_2 V_1 = V_31 -> V_42 -> V_1 ;
F_35 ( V_70 , V_1 ,
( T_3 ) 1 , F_58 , NULL , NULL , NULL ) ;
V_17 = F_51 ( V_1 ) ;
if ( V_17 )
F_52 ( V_17 ) ;
}
static int F_60 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
if ( V_16 -> V_49 & V_64 )
goto V_62;
F_42 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_52 ) {
F_22 ( L_27 , V_79 ) ;
V_39 = F_61 ( V_13 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_28 , V_79 ) ;
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
static int F_62 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
if ( ( V_16 -> V_49 & V_64 ) == 0 )
goto V_62;
F_42 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_53 ) {
V_39 = F_61 ( V_13 -> V_1 , L_6 , NULL , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_29 , V_79 ) ;
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
static unsigned char F_63 ( struct V_14 * V_15 )
{
struct V_81 * V_29 ;
unsigned char V_82 , V_83 ;
V_82 = V_15 -> V_22 . V_23 ;
F_64 (tmp, &bus->children) {
V_83 = F_65 ( F_66 ( V_29 ) ) ;
if ( V_83 > V_82 )
V_82 = V_83 ;
}
return V_82 ;
}
static int F_67 ( struct V_12 * V_13 )
{
struct V_84 * V_42 ;
int V_85 ;
if ( ! F_68 ( V_13 -> V_1 , & V_42 ) ) {
F_22 ( L_30 ) ;
F_69 ( V_42 ) ;
}
V_85 = F_70 ( V_13 -> V_1 ) ;
if ( ! V_85 )
V_85 = F_68 ( V_13 -> V_1 , & V_42 ) ;
if ( V_85 )
F_22 ( L_31 , - V_85 ) ;
return V_85 ;
}
static int F_71 ( T_2 V_1 )
{
struct V_84 * V_42 ;
int V_44 ;
V_44 = F_68 ( V_1 , & V_42 ) ;
if ( V_44 ) {
F_22 ( L_32 ) ;
return V_44 ;
}
F_69 ( V_42 ) ;
return 0 ;
}
static void F_72 ( struct V_37 * V_16 )
{
struct V_12 * V_13 ;
union V_86 V_87 [ 2 ] ;
struct V_88 V_89 ;
F_42 (func, &slot->funcs, sibling) {
V_89 . V_5 = 2 ;
V_89 . V_90 = V_87 ;
V_87 [ 0 ] . type = V_91 ;
V_87 [ 0 ] . integer . V_92 = V_93 ;
V_87 [ 1 ] . type = V_91 ;
V_87 [ 1 ] . integer . V_92 = 1 ;
F_61 ( V_13 -> V_1 , L_33 , & V_89 , NULL ) ;
}
}
static void F_73 ( struct V_37 * V_16 , struct V_26 * V_77 )
{
struct V_12 * V_13 ;
if ( ! V_77 -> V_76 )
return;
if ( V_77 -> V_94 )
return;
if ( F_74 ( V_77 -> V_95 ) != V_16 -> V_42 )
return;
F_42 (func, &slot->funcs, sibling) {
if ( F_75 ( V_77 -> V_95 ) == V_13 -> V_43 ) {
if ( ( F_33 ( V_13 -> V_1 ) > 0 ) )
V_77 -> V_94 = 1 ;
break;
}
}
}
static int T_4 F_76 ( struct V_37 * V_16 )
{
struct V_26 * V_77 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_12 * V_13 ;
int V_44 = 0 ;
int V_96 , V_82 , V_97 ;
T_1 V_39 ;
if ( V_16 -> V_49 & V_63 )
goto V_62;
F_42 (func, &slot->funcs, sibling)
F_67 ( V_13 ) ;
V_96 = F_77 ( V_15 , F_27 ( V_16 -> V_42 , 0 ) ) ;
if ( V_96 == 0 ) {
F_22 ( L_34 ) ;
goto V_62;
}
V_82 = F_63 ( V_15 ) ;
for ( V_97 = 0 ; V_97 < 2 ; V_97 ++ ) {
F_42 (dev, &bus->devices, bus_list) {
if ( F_74 ( V_77 -> V_95 ) != V_16 -> V_42 )
continue;
if ( V_77 -> V_98 == V_99 ||
V_77 -> V_98 == V_100 ) {
V_82 = F_78 ( V_15 , V_77 , V_82 , V_97 ) ;
if ( V_97 && V_77 -> V_76 ) {
F_73 ( V_16 , V_77 ) ;
F_79 ( V_77 -> V_76 ) ;
}
}
}
}
F_80 ( V_15 ) ;
F_81 ( V_15 ) ;
F_82 ( V_15 ) ;
F_72 ( V_16 ) ;
F_83 ( V_15 ) ;
F_42 (dev, &bus->devices, bus_list) {
if ( ! V_77 -> V_101 )
V_77 -> V_102 = V_103 ;
}
F_84 ( V_15 ) ;
V_16 -> V_49 |= V_63 ;
F_42 (func, &slot->funcs, sibling) {
V_77 = F_26 ( V_15 , F_27 ( V_16 -> V_42 ,
V_13 -> V_43 ) ) ;
if ( ! V_77 ) {
V_16 -> V_49 &= ( ~ V_63 ) ;
continue;
}
if ( V_77 -> V_98 != V_99 &&
V_77 -> V_98 != V_100 ) {
F_28 ( V_77 ) ;
continue;
}
V_39 = F_48 ( V_13 -> V_1 , ( T_3 ) 1 , V_15 , NULL ) ;
if ( F_14 ( V_39 ) )
F_15 ( L_23 ,
V_39 ) ;
F_28 ( V_77 ) ;
}
V_62:
return V_44 ;
}
static struct V_26 * F_85 ( struct V_37 * V_16 )
{
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
struct V_26 * V_77 ;
struct V_26 * V_104 = NULL ;
F_86 ( & V_105 ) ;
F_42 (dev, &bus->devices, bus_list)
if ( F_74 ( V_77 -> V_95 ) == V_16 -> V_42 ) {
V_104 = F_87 ( V_77 ) ;
break;
}
F_88 ( & V_105 ) ;
return V_104 ;
}
static int F_89 ( struct V_37 * V_16 )
{
struct V_12 * V_13 ;
struct V_26 * V_27 ;
struct V_14 * V_15 = V_16 -> V_17 -> V_14 ;
V_27 = F_26 ( V_15 , F_27 ( V_16 -> V_42 , 0 ) ) ;
if ( ! V_27 )
goto V_62;
F_28 ( V_27 ) ;
F_42 (func, &slot->funcs, sibling) {
if ( V_13 -> V_17 ) {
F_58 ( V_13 -> V_17 -> V_1 ,
( T_3 ) 1 , NULL , NULL ) ;
V_13 -> V_17 = NULL ;
}
}
while ( ( V_27 = F_85 ( V_16 ) ) ) {
F_90 ( V_27 ) ;
F_28 ( V_27 ) ;
}
F_42 (func, &slot->funcs, sibling) {
F_71 ( V_13 -> V_1 ) ;
}
V_16 -> V_49 &= ( ~ V_63 ) ;
V_62:
return 0 ;
}
static unsigned int F_91 ( struct V_37 * V_16 )
{
T_1 V_39 ;
unsigned long long V_106 = 0 ;
T_3 V_107 ;
struct V_12 * V_13 ;
F_42 (func, &slot->funcs, sibling) {
if ( V_13 -> V_49 & V_51 ) {
V_39 = F_13 ( V_13 -> V_1 , L_4 , NULL , & V_106 ) ;
if ( F_18 ( V_39 ) && V_106 )
break;
} else {
F_92 ( V_16 -> V_17 -> V_14 ,
F_27 ( V_16 -> V_42 ,
V_13 -> V_43 ) ,
V_108 , & V_107 ) ;
if ( V_107 != 0xffffffff ) {
V_106 = V_109 ;
break;
}
}
}
return ( unsigned int ) V_106 ;
}
int F_93 ( struct V_37 * V_16 )
{
T_1 V_39 ;
struct V_12 * V_13 ;
struct V_88 V_89 ;
union V_86 V_110 ;
F_42 (func, &slot->funcs, sibling) {
if ( ( V_13 -> V_49 & V_50 ) ) {
V_89 . V_5 = 1 ;
V_89 . V_90 = & V_110 ;
V_110 . type = V_91 ;
V_110 . integer . V_92 = 1 ;
V_39 = F_61 ( V_13 -> V_1 , L_3 , & V_89 , NULL ) ;
if ( F_14 ( V_39 ) ) {
F_15 ( L_35 , V_79 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_94 ( struct V_36 * V_17 )
{
struct V_37 * V_16 ;
int V_44 = 0 ;
int V_111 , V_112 ;
V_111 = V_112 = 0 ;
for ( V_16 = V_17 -> V_56 ; V_16 ; V_16 = V_16 -> V_57 ) {
unsigned int V_39 = F_91 ( V_16 ) ;
if ( V_16 -> V_49 & V_63 ) {
if ( V_39 == V_109 )
continue;
V_44 = F_95 ( V_16 ) ;
if ( V_44 ) {
F_32 ( L_36 ) ;
goto V_62;
} else {
F_93 ( V_16 ) ;
}
V_112 ++ ;
} else {
if ( V_39 != V_109 )
continue;
V_44 = F_96 ( V_16 ) ;
if ( V_44 ) {
F_32 ( L_37 ) ;
goto V_62;
}
V_111 ++ ;
}
}
F_22 ( L_38 , V_79 , V_111 , V_112 ) ;
V_62:
return V_44 ;
}
static void F_82 ( struct V_14 * V_15 )
{
struct V_26 * V_77 ;
F_42 (dev, &bus->devices, bus_list)
F_97 ( V_77 ) ;
}
static void F_81 ( struct V_14 * V_15 )
{
struct V_26 * V_77 ;
int V_113 ;
unsigned long V_114 = V_115 | V_116 ;
F_42 (dev, &bus->devices, bus_list) {
for ( V_113 = 0 ; V_113 < V_117 ; V_113 ++ ) {
struct V_118 * V_119 = & V_77 -> V_118 [ V_113 ] ;
if ( ( V_119 -> V_49 & V_114 ) && ! V_119 -> V_23 &&
V_119 -> V_25 ) {
F_90 ( V_77 ) ;
break;
}
}
}
}
static T_1
F_98 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_36 * V_17 ;
char V_120 [ 64 ] ;
struct V_121 V_122 = { . V_123 = sizeof( V_120 ) ,
. V_90 = V_120 } ;
V_17 = F_51 ( V_1 ) ;
if ( V_17 ) {
F_99 ( V_1 , V_124 , & V_122 ) ;
F_22 ( L_39 ,
V_79 , V_120 ) ;
F_94 ( V_17 ) ;
}
return V_7 ;
}
static void F_100 ( struct V_125 * V_126 )
{
struct V_36 * V_17 ;
char V_120 [ 64 ] ;
struct V_121 V_122 = { . V_123 = sizeof( V_120 ) ,
. V_90 = V_120 } ;
struct V_127 * V_128 ;
T_2 V_1 ;
T_3 type ;
V_128 = F_4 ( V_126 , struct V_127 , V_126 ) ;
V_1 = V_128 -> V_1 ;
type = V_128 -> type ;
V_17 = (struct V_36 * ) V_128 -> V_3 ;
F_101 () ;
F_99 ( V_1 , V_124 , & V_122 ) ;
switch ( type ) {
case V_129 :
F_22 ( L_40 , V_79 , V_120 ) ;
F_22 ( L_39 , V_79 , V_120 ) ;
F_94 ( V_17 ) ;
F_35 ( V_70 , V_1 ,
V_130 , F_98 , NULL , NULL , NULL ) ;
break;
case V_131 :
F_22 ( L_41 , V_79 , V_120 ) ;
F_94 ( V_17 ) ;
break;
case V_132 :
F_22 ( L_42 , V_79 , V_120 ) ;
break;
case V_133 :
F_22 ( L_43 , V_79 , V_120 ) ;
if ( ( V_17 -> V_49 & V_73 ) && V_17 -> V_13 ) {
struct V_37 * V_16 ;
V_16 = V_17 -> V_13 -> V_16 ;
if ( ! F_95 ( V_16 ) )
F_93 ( V_16 ) ;
}
break;
case V_134 :
F_102 ( V_135 L_44
L_45 , V_120 ) ;
break;
case V_136 :
F_102 ( V_135 L_44
L_46 , V_120 ) ;
break;
case V_137 :
F_102 ( V_135 L_47 ,
V_120 ) ;
break;
default:
F_15 ( L_48 , type , V_120 ) ;
break;
}
F_103 () ;
F_20 ( V_128 ) ;
}
static void V_74 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_104 ( V_1 , type , V_3 , F_100 ) ;
}
static void F_105 ( struct V_125 * V_126 )
{
struct V_12 * V_13 ;
char V_120 [ 64 ] ;
struct V_121 V_122 = { . V_123 = sizeof( V_120 ) ,
. V_90 = V_120 } ;
struct V_127 * V_128 ;
T_2 V_1 ;
T_3 type ;
V_128 = F_4 ( V_126 , struct V_127 , V_126 ) ;
V_1 = V_128 -> V_1 ;
type = V_128 -> type ;
V_13 = (struct V_12 * ) V_128 -> V_3 ;
F_101 () ;
F_99 ( V_1 , V_124 , & V_122 ) ;
switch ( type ) {
case V_129 :
F_22 ( L_40 , V_79 , V_120 ) ;
F_96 ( V_13 -> V_16 ) ;
break;
case V_131 :
F_22 ( L_41 , V_79 , V_120 ) ;
F_94 ( V_13 -> V_16 -> V_17 ) ;
break;
case V_132 :
F_22 ( L_42 , V_79 , V_120 ) ;
break;
case V_133 :
F_22 ( L_43 , V_79 , V_120 ) ;
if ( ! ( F_95 ( V_13 -> V_16 ) ) )
F_93 ( V_13 -> V_16 ) ;
break;
default:
F_15 ( L_48 , type , V_120 ) ;
break;
}
F_103 () ;
F_20 ( V_128 ) ;
}
static void V_68 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
F_104 ( V_1 , type , V_3 , F_105 ) ;
}
int T_5 F_106 ( void )
{
F_107 ( & V_138 ) ;
return 0 ;
}
void F_108 ( void )
{
F_109 ( & V_138 ) ;
}
int F_96 ( struct V_37 * V_16 )
{
int V_44 ;
F_110 ( & V_16 -> V_59 ) ;
V_44 = F_60 ( V_16 ) ;
if ( V_44 )
goto V_62;
if ( F_91 ( V_16 ) == V_109 ) {
V_44 = F_76 ( V_16 ) ;
if ( V_44 )
F_62 ( V_16 ) ;
} else {
F_22 ( L_49 , V_79 ) ;
F_62 ( V_16 ) ;
}
V_62:
F_111 ( & V_16 -> V_59 ) ;
return V_44 ;
}
int F_95 ( struct V_37 * V_16 )
{
int V_44 = 0 ;
F_110 ( & V_16 -> V_59 ) ;
V_44 = F_89 ( V_16 ) ;
if ( V_44 )
goto V_62;
V_44 = F_62 ( V_16 ) ;
if ( V_44 )
goto V_62;
V_62:
F_111 ( & V_16 -> V_59 ) ;
return V_44 ;
}
T_6 F_112 ( struct V_37 * V_16 )
{
return ( V_16 -> V_49 & V_64 ) ;
}
T_6 F_113 ( struct V_37 * V_16 )
{
unsigned int V_106 ;
V_106 = F_91 ( V_16 ) ;
return ( V_106 & V_139 ) ? 0 : 1 ;
}
T_6 F_114 ( struct V_37 * V_16 )
{
unsigned int V_106 ;
V_106 = F_91 ( V_16 ) ;
return ( V_106 == 0 ) ? 0 : 1 ;
}
