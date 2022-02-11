static inline int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return ! V_2 -> V_3 ;
#else
return 0 ;
#endif
}
static unsigned long F_3 ( int V_4 )
{
unsigned long V_5 ;
switch ( V_4 ) {
case 0 :
V_5 = F_4 ( V_6 ) ;
break;
case 1 :
V_5 = F_4 ( V_7 ) ;
break;
case 2 :
V_5 = F_4 ( V_8 ) ;
break;
case 3 :
V_5 = F_4 ( V_9 ) ;
break;
case 4 :
V_5 = F_4 ( V_10 ) ;
break;
case 5 :
V_5 = F_4 ( V_11 ) ;
break;
default:
F_5 ( V_12 L_1 , V_4 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static void F_6 ( int V_4 , unsigned long V_5 )
{
switch ( V_4 ) {
case 0 :
F_7 ( V_6 , V_5 ) ;
break;
case 1 :
F_7 ( V_7 , V_5 ) ;
break;
case 2 :
F_7 ( V_8 , V_5 ) ;
break;
case 3 :
F_7 ( V_9 , V_5 ) ;
break;
case 4 :
F_7 ( V_10 , V_5 ) ;
break;
case 5 :
F_7 ( V_11 , V_5 ) ;
break;
default:
F_5 ( V_12 L_2 , V_4 ) ;
}
F_8 () ;
}
static void F_9 ( int V_4 , unsigned long V_5 )
{
switch ( V_4 ) {
case 0 :
F_7 ( V_13 , V_5 ) ;
break;
case 1 :
F_7 ( V_14 , V_5 ) ;
break;
case 2 :
F_7 ( V_15 , V_5 ) ;
break;
case 3 :
F_7 ( V_16 , V_5 ) ;
break;
case 4 :
F_7 ( V_17 , V_5 ) ;
break;
case 5 :
F_7 ( V_18 , V_5 ) ;
break;
default:
F_5 ( V_12 L_3 , V_4 ) ;
}
F_8 () ;
}
static void F_10 ( int V_4 , unsigned long V_5 )
{
switch ( V_4 ) {
case 0 :
F_7 ( V_19 , V_5 ) ;
break;
case 1 :
F_7 ( V_20 , V_5 ) ;
break;
case 2 :
F_7 ( V_21 , V_5 ) ;
break;
case 3 :
F_7 ( V_22 , V_5 ) ;
break;
case 4 :
F_7 ( V_23 , V_5 ) ;
break;
case 5 :
F_7 ( V_24 , V_5 ) ;
break;
default:
F_5 ( V_12 L_4 , V_4 ) ;
}
F_8 () ;
}
static void F_11 ( struct V_25 * V_26 )
{
T_1 V_5 , V_27 , V_28 ;
if ( V_26 -> V_29 . V_30 & V_31 )
return;
do {
V_28 = F_12 ( & V_26 -> V_29 . V_32 ) ;
F_13 () ;
V_5 = F_3 ( V_26 -> V_29 . V_4 ) ;
} while ( F_14 ( & V_26 -> V_29 . V_32 , V_28 , V_5 ) != V_28 );
V_27 = ( V_5 - V_28 ) & 0xfffffffful ;
F_15 ( V_27 , & V_26 -> V_33 ) ;
F_16 ( V_27 , & V_26 -> V_29 . V_34 ) ;
}
static void F_17 ( struct V_35 * V_35 )
{
struct V_36 * V_37 ;
unsigned long V_38 ;
F_18 ( V_38 ) ;
V_37 = & F_19 ( V_36 ) ;
if ( ! V_37 -> V_39 ) {
V_37 -> V_39 = 1 ;
if ( ! V_37 -> V_40 ) {
F_20 () ;
V_37 -> V_40 = 1 ;
}
if ( F_21 ( & V_41 ) ) {
F_7 ( V_42 , V_43 ) ;
F_8 () ;
}
}
F_22 ( V_38 ) ;
}
static void F_23 ( struct V_35 * V_35 )
{
struct V_36 * V_37 ;
unsigned long V_38 ;
F_18 ( V_38 ) ;
V_37 = & F_19 ( V_36 ) ;
if ( ! V_37 -> V_39 )
goto V_44;
V_37 -> V_39 = 0 ;
F_24 ( V_37 -> V_45 != 0 ) ;
if ( V_37 -> V_45 > 0 ) {
F_7 ( V_42 , V_46 | V_47 ) ;
F_8 () ;
}
V_44:
F_22 ( V_38 ) ;
}
static int F_25 ( struct V_25 * V_48 , int V_49 ,
struct V_25 * V_50 [] )
{
int V_51 = 0 ;
struct V_25 * V_26 ;
if ( ! F_26 ( V_48 ) ) {
if ( V_51 >= V_49 )
return - 1 ;
V_50 [ V_51 ] = V_48 ;
V_51 ++ ;
}
F_27 (event, &group->sibling_list, group_entry) {
if ( ! F_26 ( V_26 ) &&
V_26 -> V_30 != V_52 ) {
if ( V_51 >= V_49 )
return - 1 ;
V_50 [ V_51 ] = V_26 ;
V_51 ++ ;
}
}
return V_51 ;
}
static int F_28 ( struct V_25 * V_26 , int V_38 )
{
struct V_36 * V_37 ;
int V_53 = - V_54 ;
int V_55 = V_56 -> V_57 ;
T_2 V_5 ;
int V_58 ;
F_29 ( V_26 -> V_35 ) ;
V_37 = & F_30 ( V_36 ) ;
if ( V_26 -> V_29 . V_59 & V_60 )
V_55 = V_56 -> V_61 ;
for ( V_58 = V_55 - 1 ; V_58 >= 0 ; V_58 -- ) {
if ( V_37 -> V_26 [ V_58 ] )
continue;
break;
}
if ( V_58 < 0 )
goto V_44;
V_26 -> V_29 . V_4 = V_58 ;
V_37 -> V_26 [ V_58 ] = V_26 ;
++ V_37 -> V_45 ;
V_5 = 0 ;
if ( V_26 -> V_29 . V_62 ) {
T_1 V_63 = F_12 ( & V_26 -> V_29 . V_34 ) ;
if ( V_63 < 0x80000000L )
V_5 = 0x80000000L - V_63 ;
}
F_31 ( & V_26 -> V_29 . V_32 , V_5 ) ;
if ( ! ( V_38 & V_64 ) ) {
V_26 -> V_29 . V_30 = V_31 | V_65 ;
V_5 = 0 ;
}
F_6 ( V_58 , V_5 ) ;
F_32 ( V_26 ) ;
F_10 ( V_58 , V_26 -> V_29 . V_59 >> 32 ) ;
F_9 ( V_58 , V_26 -> V_29 . V_66 ) ;
V_53 = 0 ;
V_44:
F_33 ( V_36 ) ;
F_34 ( V_26 -> V_35 ) ;
return V_53 ;
}
static void F_35 ( struct V_25 * V_26 , int V_38 )
{
struct V_36 * V_37 ;
int V_58 = V_26 -> V_29 . V_4 ;
F_29 ( V_26 -> V_35 ) ;
if ( V_58 < 0 )
goto V_44;
F_11 ( V_26 ) ;
V_37 = & F_30 ( V_36 ) ;
F_36 ( V_26 != V_37 -> V_26 [ V_26 -> V_29 . V_4 ] ) ;
F_9 ( V_58 , 0 ) ;
F_10 ( V_58 , 0 ) ;
F_6 ( V_58 , 0 ) ;
V_37 -> V_26 [ V_58 ] = NULL ;
V_26 -> V_29 . V_4 = - 1 ;
V_37 -> V_45 -- ;
V_44:
F_34 ( V_26 -> V_35 ) ;
F_33 ( V_36 ) ;
}
static void F_37 ( struct V_25 * V_26 , int V_67 )
{
unsigned long V_38 ;
T_1 V_63 ;
if ( V_26 -> V_29 . V_4 < 0 || ! V_26 -> V_29 . V_62 )
return;
if ( ! ( V_26 -> V_29 . V_30 & V_31 ) )
return;
if ( V_67 & V_68 )
F_38 ( ! ( V_26 -> V_29 . V_30 & V_65 ) ) ;
F_18 ( V_38 ) ;
F_29 ( V_26 -> V_35 ) ;
V_26 -> V_29 . V_30 = 0 ;
V_63 = F_12 ( & V_26 -> V_29 . V_34 ) ;
F_6 ( V_26 -> V_29 . V_4 , V_63 ) ;
F_32 ( V_26 ) ;
F_34 ( V_26 -> V_35 ) ;
F_22 ( V_38 ) ;
}
static void F_39 ( struct V_25 * V_26 , int V_67 )
{
unsigned long V_38 ;
if ( V_26 -> V_29 . V_4 < 0 || ! V_26 -> V_29 . V_62 )
return;
if ( V_26 -> V_29 . V_30 & V_31 )
return;
F_18 ( V_38 ) ;
F_29 ( V_26 -> V_35 ) ;
F_11 ( V_26 ) ;
V_26 -> V_29 . V_30 |= V_31 | V_65 ;
F_6 ( V_26 -> V_29 . V_4 , 0 ) ;
F_32 ( V_26 ) ;
F_34 ( V_26 -> V_35 ) ;
F_22 ( V_38 ) ;
}
static void F_40 ( struct V_25 * V_26 )
{
if ( ! F_41 ( & V_41 , - 1 , 1 ) ) {
F_42 ( & V_69 ) ;
if ( F_43 ( & V_41 ) == 0 )
F_44 () ;
F_45 ( & V_69 ) ;
}
}
static int F_46 ( T_2 V_59 , T_2 * V_70 )
{
unsigned long type , V_71 , V_72 ;
int V_73 ;
if ( ! V_56 -> V_74 )
return - V_75 ;
type = V_59 & 0xff ;
V_71 = ( V_59 >> 8 ) & 0xff ;
V_72 = ( V_59 >> 16 ) & 0xff ;
if ( type >= V_76 ||
V_71 >= V_77 ||
V_72 >= V_78 )
return - V_75 ;
V_73 = ( * V_56 -> V_74 ) [ type ] [ V_71 ] [ V_72 ] ;
if ( V_73 == 0 )
return - V_79 ;
if ( V_73 == - 1 )
return - V_75 ;
* V_70 = V_73 ;
return 0 ;
}
static int F_47 ( struct V_25 * V_26 )
{
T_2 V_73 ;
struct V_25 * V_80 [ V_81 ] ;
int V_51 ;
int V_82 ;
int V_83 ;
int V_58 ;
if ( V_56 -> V_57 > V_81 ) {
F_48 ( 1 , L_5 ,
V_56 -> V_57 , V_81 ) ;
V_56 -> V_57 = V_81 ;
}
switch ( V_26 -> V_84 . type ) {
case V_85 :
V_73 = V_26 -> V_84 . V_59 ;
if ( V_73 >= V_56 -> V_86 || V_56 -> V_87 [ V_73 ] == 0 )
return - V_79 ;
V_73 = V_56 -> V_87 [ V_73 ] ;
break;
case V_88 :
V_82 = F_46 ( V_26 -> V_84 . V_59 , & V_73 ) ;
if ( V_82 )
return V_82 ;
break;
case V_89 :
V_73 = V_26 -> V_84 . V_59 ;
break;
default:
return - V_90 ;
}
V_26 -> V_29 . V_59 = V_56 -> V_91 ( V_73 ) ;
if ( ! ( V_26 -> V_29 . V_59 & V_92 ) )
return - V_75 ;
V_51 = 0 ;
if ( V_26 -> V_93 != V_26 ) {
V_51 = F_25 ( V_26 -> V_93 ,
V_56 -> V_57 - 1 , V_80 ) ;
if ( V_51 < 0 )
return - V_75 ;
}
if ( V_26 -> V_29 . V_59 & V_60 ) {
V_83 = 0 ;
for ( V_58 = 0 ; V_58 < V_51 ; V_58 ++ ) {
if ( V_80 [ V_58 ] -> V_29 . V_59 & V_60 )
V_83 ++ ;
}
if ( V_83 >= V_56 -> V_61 )
return - V_75 ;
}
V_26 -> V_29 . V_4 = - 1 ;
V_26 -> V_29 . V_66 = V_94 | V_95 |
( V_96 ) ( ( V_73 << 16 ) & V_97 ) ;
if ( V_26 -> V_84 . V_98 )
V_26 -> V_29 . V_66 |= V_99 ;
if ( V_26 -> V_84 . V_100 )
V_26 -> V_29 . V_66 |= V_101 ;
if ( V_26 -> V_84 . V_102 )
return - V_103 ;
V_26 -> V_29 . V_104 = V_26 -> V_29 . V_62 ;
F_31 ( & V_26 -> V_29 . V_34 , V_26 -> V_29 . V_104 ) ;
V_82 = 0 ;
if ( ! F_49 ( & V_41 ) ) {
F_42 ( & V_69 ) ;
if ( F_21 ( & V_41 ) == 0 &&
F_50 ( V_105 ) )
V_82 = - V_106 ;
else
F_51 ( & V_41 ) ;
F_45 ( & V_69 ) ;
F_7 ( V_42 , V_43 ) ;
F_8 () ;
}
V_26 -> V_107 = F_40 ;
return V_82 ;
}
static void F_52 ( struct V_25 * V_26 , unsigned long V_5 ,
struct V_1 * V_2 )
{
T_2 V_108 = V_26 -> V_29 . V_62 ;
T_1 V_28 , V_27 , V_63 ;
int V_109 = 0 ;
if ( V_26 -> V_29 . V_30 & V_31 ) {
F_6 ( V_26 -> V_29 . V_4 , 0 ) ;
return;
}
V_28 = F_12 ( & V_26 -> V_29 . V_32 ) ;
V_27 = ( V_5 - V_28 ) & 0xfffffffful ;
F_15 ( V_27 , & V_26 -> V_33 ) ;
V_5 = 0 ;
V_63 = F_12 ( & V_26 -> V_29 . V_34 ) - V_27 ;
if ( V_108 ) {
if ( V_63 <= 0 ) {
V_63 += V_108 ;
if ( V_63 <= 0 )
V_63 = V_108 ;
V_109 = 1 ;
V_26 -> V_29 . V_104 = V_26 -> V_29 . V_62 ;
}
if ( V_63 < 0x80000000LL )
V_5 = 0x80000000LL - V_63 ;
}
F_6 ( V_26 -> V_29 . V_4 , V_5 ) ;
F_31 ( & V_26 -> V_29 . V_32 , V_5 ) ;
F_31 ( & V_26 -> V_29 . V_34 , V_63 ) ;
F_32 ( V_26 ) ;
if ( V_109 ) {
struct V_110 V_111 ;
F_53 ( & V_111 , 0 , V_26 -> V_29 . V_104 ) ;
if ( F_54 ( V_26 , & V_111 , V_2 ) )
F_39 ( V_26 , 0 ) ;
}
}
static void V_105 ( struct V_1 * V_2 )
{
int V_58 ;
struct V_36 * V_37 = & F_19 ( V_36 ) ;
struct V_25 * V_26 ;
unsigned long V_5 ;
int V_112 = 0 ;
int V_113 ;
V_113 = F_1 ( V_2 ) ;
if ( V_113 )
F_55 () ;
else
F_56 () ;
for ( V_58 = 0 ; V_58 < V_56 -> V_57 ; ++ V_58 ) {
V_26 = V_37 -> V_26 [ V_58 ] ;
V_5 = F_3 ( V_58 ) ;
if ( ( int ) V_5 < 0 ) {
if ( V_26 ) {
V_112 = 1 ;
F_52 ( V_26 , V_5 , V_2 ) ;
} else {
F_6 ( V_58 , 0 ) ;
}
}
}
F_57 ( F_58 () | V_114 ) ;
F_7 ( V_42 , V_46 | V_47 ) ;
F_8 () ;
if ( V_113 )
F_59 () ;
else
F_60 () ;
}
void F_61 ( int V_115 )
{
struct V_36 * V_37 = & F_62 ( V_36 , V_115 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
}
int F_63 ( struct V_116 * V_35 )
{
if ( V_56 )
return - V_106 ;
V_56 = V_35 ;
F_64 ( L_6 ,
V_35 -> V_117 ) ;
F_65 ( & V_116 , L_7 , V_89 ) ;
return 0 ;
}
