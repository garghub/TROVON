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
default:
F_5 ( V_10 L_1 , V_4 ) ;
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
default:
F_5 ( V_10 L_2 , V_4 ) ;
}
F_8 () ;
}
static void F_9 ( int V_4 , unsigned long V_5 )
{
switch ( V_4 ) {
case 0 :
F_7 ( V_11 , V_5 ) ;
break;
case 1 :
F_7 ( V_12 , V_5 ) ;
break;
case 2 :
F_7 ( V_13 , V_5 ) ;
break;
case 3 :
F_7 ( V_14 , V_5 ) ;
break;
default:
F_5 ( V_10 L_3 , V_4 ) ;
}
F_8 () ;
}
static void F_10 ( int V_4 , unsigned long V_5 )
{
switch ( V_4 ) {
case 0 :
F_7 ( V_15 , V_5 ) ;
break;
case 1 :
F_7 ( V_16 , V_5 ) ;
break;
case 2 :
F_7 ( V_17 , V_5 ) ;
break;
case 3 :
F_7 ( V_18 , V_5 ) ;
break;
default:
F_5 ( V_10 L_4 , V_4 ) ;
}
F_8 () ;
}
static void F_11 ( struct V_19 * V_20 )
{
T_1 V_5 , V_21 , V_22 ;
if ( V_20 -> V_23 . V_24 & V_25 )
return;
do {
V_22 = F_12 ( & V_20 -> V_23 . V_26 ) ;
F_13 () ;
V_5 = F_3 ( V_20 -> V_23 . V_4 ) ;
} while ( F_14 ( & V_20 -> V_23 . V_26 , V_22 , V_5 ) != V_22 );
V_21 = ( V_5 - V_22 ) & 0xfffffffful ;
F_15 ( V_21 , & V_20 -> V_27 ) ;
F_16 ( V_21 , & V_20 -> V_23 . V_28 ) ;
}
static void F_17 ( struct V_29 * V_29 )
{
struct V_30 * V_31 ;
unsigned long V_32 ;
F_18 ( V_32 ) ;
V_31 = & F_19 ( V_30 ) ;
if ( ! V_31 -> V_33 ) {
V_31 -> V_33 = 1 ;
if ( ! V_31 -> V_34 ) {
F_20 () ;
V_31 -> V_34 = 1 ;
}
if ( F_21 ( & V_35 ) ) {
F_7 ( V_36 , V_37 ) ;
F_8 () ;
}
}
F_22 ( V_32 ) ;
}
static void F_23 ( struct V_29 * V_29 )
{
struct V_30 * V_31 ;
unsigned long V_32 ;
F_18 ( V_32 ) ;
V_31 = & F_19 ( V_30 ) ;
if ( ! V_31 -> V_33 )
goto V_38;
V_31 -> V_33 = 0 ;
F_24 ( V_31 -> V_39 != 0 ) ;
if ( V_31 -> V_39 > 0 ) {
F_7 ( V_36 , V_40 | V_41 ) ;
F_8 () ;
}
V_38:
F_22 ( V_32 ) ;
}
static int F_25 ( struct V_19 * V_42 , int V_43 ,
struct V_19 * V_44 [] )
{
int V_45 = 0 ;
struct V_19 * V_20 ;
if ( ! F_26 ( V_42 ) ) {
if ( V_45 >= V_43 )
return - 1 ;
V_44 [ V_45 ] = V_42 ;
V_45 ++ ;
}
F_27 (event, &group->sibling_list, group_entry) {
if ( ! F_26 ( V_20 ) &&
V_20 -> V_24 != V_46 ) {
if ( V_45 >= V_43 )
return - 1 ;
V_44 [ V_45 ] = V_20 ;
V_45 ++ ;
}
}
return V_45 ;
}
static int F_28 ( struct V_19 * V_20 , int V_32 )
{
struct V_30 * V_31 ;
int V_47 = - V_48 ;
int V_49 = V_50 -> V_51 ;
T_2 V_5 ;
int V_52 ;
F_29 ( V_20 -> V_29 ) ;
V_31 = & F_30 ( V_30 ) ;
if ( V_20 -> V_23 . V_53 & V_54 )
V_49 = V_50 -> V_55 ;
for ( V_52 = V_49 - 1 ; V_52 >= 0 ; V_52 -- ) {
if ( V_31 -> V_20 [ V_52 ] )
continue;
break;
}
if ( V_52 < 0 )
goto V_38;
V_20 -> V_23 . V_4 = V_52 ;
V_31 -> V_20 [ V_52 ] = V_20 ;
++ V_31 -> V_39 ;
V_5 = 0 ;
if ( V_20 -> V_23 . V_56 ) {
T_1 V_57 = F_12 ( & V_20 -> V_23 . V_28 ) ;
if ( V_57 < 0x80000000L )
V_5 = 0x80000000L - V_57 ;
}
F_31 ( & V_20 -> V_23 . V_26 , V_5 ) ;
if ( ! ( V_32 & V_58 ) ) {
V_20 -> V_23 . V_24 = V_25 | V_59 ;
V_5 = 0 ;
}
F_6 ( V_52 , V_5 ) ;
F_32 ( V_20 ) ;
F_10 ( V_52 , V_20 -> V_23 . V_53 >> 32 ) ;
F_9 ( V_52 , V_20 -> V_23 . V_60 ) ;
V_47 = 0 ;
V_38:
F_33 ( V_30 ) ;
F_34 ( V_20 -> V_29 ) ;
return V_47 ;
}
static void F_35 ( struct V_19 * V_20 , int V_32 )
{
struct V_30 * V_31 ;
int V_52 = V_20 -> V_23 . V_4 ;
F_29 ( V_20 -> V_29 ) ;
if ( V_52 < 0 )
goto V_38;
F_11 ( V_20 ) ;
V_31 = & F_30 ( V_30 ) ;
F_36 ( V_20 != V_31 -> V_20 [ V_20 -> V_23 . V_4 ] ) ;
F_9 ( V_52 , 0 ) ;
F_10 ( V_52 , 0 ) ;
F_6 ( V_52 , 0 ) ;
V_31 -> V_20 [ V_52 ] = NULL ;
V_20 -> V_23 . V_4 = - 1 ;
V_31 -> V_39 -- ;
V_38:
F_34 ( V_20 -> V_29 ) ;
F_33 ( V_30 ) ;
}
static void F_37 ( struct V_19 * V_20 , int V_61 )
{
unsigned long V_32 ;
T_1 V_57 ;
if ( V_20 -> V_23 . V_4 < 0 || ! V_20 -> V_23 . V_56 )
return;
if ( ! ( V_20 -> V_23 . V_24 & V_25 ) )
return;
if ( V_61 & V_62 )
F_38 ( ! ( V_20 -> V_23 . V_24 & V_59 ) ) ;
F_18 ( V_32 ) ;
F_29 ( V_20 -> V_29 ) ;
V_20 -> V_23 . V_24 = 0 ;
V_57 = F_12 ( & V_20 -> V_23 . V_28 ) ;
F_6 ( V_20 -> V_23 . V_4 , V_57 ) ;
F_32 ( V_20 ) ;
F_34 ( V_20 -> V_29 ) ;
F_22 ( V_32 ) ;
}
static void F_39 ( struct V_19 * V_20 , int V_61 )
{
unsigned long V_32 ;
if ( V_20 -> V_23 . V_4 < 0 || ! V_20 -> V_23 . V_56 )
return;
if ( V_20 -> V_23 . V_24 & V_25 )
return;
F_18 ( V_32 ) ;
F_29 ( V_20 -> V_29 ) ;
F_11 ( V_20 ) ;
V_20 -> V_23 . V_24 |= V_25 | V_59 ;
F_6 ( V_20 -> V_23 . V_4 , 0 ) ;
F_32 ( V_20 ) ;
F_34 ( V_20 -> V_29 ) ;
F_22 ( V_32 ) ;
}
static void F_40 ( struct V_19 * V_20 )
{
if ( ! F_41 ( & V_35 , - 1 , 1 ) ) {
F_42 ( & V_63 ) ;
if ( F_43 ( & V_35 ) == 0 )
F_44 () ;
F_45 ( & V_63 ) ;
}
}
static int F_46 ( T_2 V_53 , T_2 * V_64 )
{
unsigned long type , V_65 , V_66 ;
int V_67 ;
if ( ! V_50 -> V_68 )
return - V_69 ;
type = V_53 & 0xff ;
V_65 = ( V_53 >> 8 ) & 0xff ;
V_66 = ( V_53 >> 16 ) & 0xff ;
if ( type >= V_70 ||
V_65 >= V_71 ||
V_66 >= V_72 )
return - V_69 ;
V_67 = ( * V_50 -> V_68 ) [ type ] [ V_65 ] [ V_66 ] ;
if ( V_67 == 0 )
return - V_73 ;
if ( V_67 == - 1 )
return - V_69 ;
* V_64 = V_67 ;
return 0 ;
}
static int F_47 ( struct V_19 * V_20 )
{
T_2 V_67 ;
struct V_19 * V_74 [ V_75 ] ;
int V_45 ;
int V_76 ;
int V_77 ;
int V_52 ;
switch ( V_20 -> V_78 . type ) {
case V_79 :
V_67 = V_20 -> V_78 . V_53 ;
if ( V_67 >= V_50 -> V_80 || V_50 -> V_81 [ V_67 ] == 0 )
return - V_73 ;
V_67 = V_50 -> V_81 [ V_67 ] ;
break;
case V_82 :
V_76 = F_46 ( V_20 -> V_78 . V_53 , & V_67 ) ;
if ( V_76 )
return V_76 ;
break;
case V_83 :
V_67 = V_20 -> V_78 . V_53 ;
break;
default:
return - V_84 ;
}
V_20 -> V_23 . V_53 = V_50 -> V_85 ( V_67 ) ;
if ( ! ( V_20 -> V_23 . V_53 & V_86 ) )
return - V_69 ;
V_45 = 0 ;
if ( V_20 -> V_87 != V_20 ) {
V_45 = F_25 ( V_20 -> V_87 ,
V_50 -> V_51 - 1 , V_74 ) ;
if ( V_45 < 0 )
return - V_69 ;
}
if ( V_20 -> V_23 . V_53 & V_54 ) {
V_77 = 0 ;
for ( V_52 = 0 ; V_52 < V_45 ; V_52 ++ ) {
if ( V_74 [ V_52 ] -> V_23 . V_53 & V_54 )
V_77 ++ ;
}
if ( V_77 >= V_50 -> V_55 )
return - V_69 ;
}
V_20 -> V_23 . V_4 = - 1 ;
V_20 -> V_23 . V_60 = V_88 | V_89 |
( V_90 ) ( ( V_67 << 16 ) & V_91 ) ;
if ( V_20 -> V_78 . V_92 )
V_20 -> V_23 . V_60 |= V_93 ;
if ( V_20 -> V_78 . V_94 )
V_20 -> V_23 . V_60 |= V_95 ;
if ( V_20 -> V_78 . V_96 )
return - V_97 ;
V_20 -> V_23 . V_98 = V_20 -> V_23 . V_56 ;
F_31 ( & V_20 -> V_23 . V_28 , V_20 -> V_23 . V_98 ) ;
V_76 = 0 ;
if ( ! F_48 ( & V_35 ) ) {
F_42 ( & V_63 ) ;
if ( F_21 ( & V_35 ) == 0 &&
F_49 ( V_99 ) )
V_76 = - V_100 ;
else
F_50 ( & V_35 ) ;
F_45 ( & V_63 ) ;
F_7 ( V_36 , V_37 ) ;
F_8 () ;
}
V_20 -> V_101 = F_40 ;
return V_76 ;
}
static void F_51 ( struct V_19 * V_20 , unsigned long V_5 ,
struct V_1 * V_2 )
{
T_2 V_102 = V_20 -> V_23 . V_56 ;
T_1 V_22 , V_21 , V_57 ;
int V_103 = 0 ;
if ( V_20 -> V_23 . V_24 & V_25 ) {
F_6 ( V_20 -> V_23 . V_4 , 0 ) ;
return;
}
V_22 = F_12 ( & V_20 -> V_23 . V_26 ) ;
V_21 = ( V_5 - V_22 ) & 0xfffffffful ;
F_15 ( V_21 , & V_20 -> V_27 ) ;
V_5 = 0 ;
V_57 = F_12 ( & V_20 -> V_23 . V_28 ) - V_21 ;
if ( V_102 ) {
if ( V_57 <= 0 ) {
V_57 += V_102 ;
if ( V_57 <= 0 )
V_57 = V_102 ;
V_103 = 1 ;
V_20 -> V_23 . V_98 = V_20 -> V_23 . V_56 ;
}
if ( V_57 < 0x80000000LL )
V_5 = 0x80000000LL - V_57 ;
}
F_6 ( V_20 -> V_23 . V_4 , V_5 ) ;
F_31 ( & V_20 -> V_23 . V_26 , V_5 ) ;
F_31 ( & V_20 -> V_23 . V_28 , V_57 ) ;
F_32 ( V_20 ) ;
if ( V_103 ) {
struct V_104 V_105 ;
F_52 ( & V_105 , 0 ) ;
V_105 . V_102 = V_20 -> V_23 . V_98 ;
if ( F_53 ( V_20 , & V_105 , V_2 ) )
F_39 ( V_20 , 0 ) ;
}
}
static void V_99 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_30 * V_31 = & F_19 ( V_30 ) ;
struct V_19 * V_20 ;
unsigned long V_5 ;
int V_106 = 0 ;
int V_107 ;
V_107 = F_1 ( V_2 ) ;
if ( V_107 )
F_54 () ;
else
F_55 () ;
for ( V_52 = 0 ; V_52 < V_50 -> V_51 ; ++ V_52 ) {
V_20 = V_31 -> V_20 [ V_52 ] ;
V_5 = F_3 ( V_52 ) ;
if ( ( int ) V_5 < 0 ) {
if ( V_20 ) {
V_106 = 1 ;
F_51 ( V_20 , V_5 , V_2 ) ;
} else {
F_6 ( V_52 , 0 ) ;
}
}
}
F_56 ( F_57 () | V_108 ) ;
F_7 ( V_36 , V_40 | V_41 ) ;
F_8 () ;
if ( V_107 )
F_58 () ;
else
F_59 () ;
}
void F_60 ( int V_109 )
{
struct V_30 * V_31 = & F_61 ( V_30 , V_109 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
}
int F_62 ( struct V_110 * V_29 )
{
if ( V_50 )
return - V_100 ;
V_50 = V_29 ;
F_63 ( L_5 ,
V_29 -> V_111 ) ;
F_64 ( & V_110 , L_6 , V_83 ) ;
return 0 ;
}
