static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_2 * V_5 ;
struct V_1 * V_6 ;
F_2 (ptr, head) {
V_6 = F_3 ( V_5 , struct V_1 , V_7 ) ;
if ( V_6 -> V_4 == V_4 )
return V_6 ;
}
return NULL ;
}
static int F_4 ( struct V_1
* V_8 , int V_9 )
{
int V_10 , V_11 ;
struct V_12 * V_13 ;
V_13 = V_8 -> V_13 ;
V_11 = - 1 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
if ( V_9 == V_13 [ V_10 ] . V_15 ) {
V_11 = V_10 ;
break;
}
if ( V_11 < 0 )
F_5 ( V_16 L_1 ) ;
return V_11 ;
}
static T_1 F_6 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_18 ;
F_7 ( & V_8 -> V_19 ) ;
if ( F_8 ( V_8 -> V_20 ) ) {
V_8 -> V_21 = true ;
V_18 = V_22 ;
} else
V_18 = V_23 ;
F_9 ( & V_8 -> V_19 ) ;
return V_18 ;
}
static void
F_10 ( struct V_1 * V_8 ,
int V_15 )
{
if ( F_11 ( V_8 -> V_24 &
V_25 ) ) {
F_7 ( & V_8 -> V_26 ) ;
if ( ! ( V_8 -> V_27 & V_28 ) )
F_12 ( V_8 -> V_29 ,
V_8 -> V_30 , V_15 , 1 ,
false ) ;
F_9 ( & V_8 -> V_26 ) ;
} else
F_12 ( V_8 -> V_29 , V_8 -> V_30 ,
V_15 , 1 , false ) ;
}
static T_1 F_13 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
if ( ! ( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_8 -> V_19 ) ;
F_15 ( V_9 ) ;
V_8 -> V_21 = true ;
F_16 ( & V_8 -> V_19 ) ;
}
F_10 ( V_8 ,
V_8 -> V_32 ) ;
return V_33 ;
}
static T_1 F_17 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_18 = F_18 ( V_8 -> V_29 ,
V_8 -> V_30 ,
V_8 -> V_32 , 1 ) ;
return F_11 ( V_18 == - V_34 ) ? V_22 : V_33 ;
}
static T_1 F_19 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
F_10 ( V_8 ,
V_8 -> V_32 ) ;
return V_33 ;
}
static T_1 F_20 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
int V_18 = 0 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_35 [ V_11 ] . V_15 ;
V_18 = F_18 ( V_8 -> V_29 ,
V_8 -> V_30 ,
V_15 , 1 ) ;
}
return F_11 ( V_18 == - V_34 ) ? V_22 : V_33 ;
}
static T_1 F_21 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_35 [ V_11 ] . V_15 ;
F_10 ( V_8 , V_15 ) ;
}
return V_33 ;
}
static void F_22 ( struct V_36 * V_37 )
{
struct V_1 * V_20 =
F_23 ( V_37 , struct V_1 ,
V_38 ) ;
F_12 ( V_20 -> V_29 , V_20 -> V_30 , V_20 -> V_32 , 0 , false ) ;
F_7 ( & V_20 -> V_26 ) ;
if ( ! ( V_20 -> V_27 & V_28 ) ) {
bool V_39 = false ;
F_14 ( & V_20 -> V_19 ) ;
if ( V_20 -> V_21 ) {
if ( ! ( V_20 -> V_27 & V_31 ) )
F_24 ( V_20 -> V_40 ) ;
else if ( ! F_25 ( V_20 -> V_20 ) )
V_39 = true ;
V_20 -> V_21 = V_39 ;
}
F_16 ( & V_20 -> V_19 ) ;
if ( V_39 )
F_12 ( V_20 -> V_29 , V_20 -> V_30 ,
V_20 -> V_32 , 1 , false ) ;
}
F_9 ( & V_20 -> V_26 ) ;
}
static void F_26 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_38 . V_41 != - 1 )
F_27 ( V_29 ,
& V_8 -> V_38 ) ;
F_12 ( V_8 -> V_29 , V_8 -> V_30 ,
V_8 -> V_32 , 0 , false ) ;
if ( V_8 -> V_30 != - 1 )
F_28 ( V_29 , V_8 -> V_30 ) ;
V_8 -> V_30 = - 1 ;
V_8 -> V_24 &= ~ ( V_42 ) ;
}
static void F_29 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_24 & V_43 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_30 ( V_8 -> V_13 [ V_10 ] . V_15 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_31 ( V_8 -> V_13 [ V_10 ] . V_15 ,
V_8 ) ;
V_8 -> V_14 = 0 ;
F_32 ( V_8 -> V_13 ) ;
F_32 ( V_8 -> V_35 ) ;
F_33 ( V_8 -> V_20 ) ;
} else {
if ( ( V_8 -> V_24 &
V_44 ) &&
( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_8 -> V_19 ) ;
F_34 ( V_8 -> V_20 , false ) ;
F_16 ( & V_8 -> V_19 ) ;
F_35 ( V_8 -> V_40 ) ;
} else
F_30 ( V_8 -> V_40 ) ;
F_31 ( V_8 -> V_40 , V_8 ) ;
if ( V_8 -> V_24 & V_45 )
F_36 ( V_8 -> V_20 ) ;
}
V_8 -> V_24 &= ~ ( V_46 ) ;
}
static int F_37 ( struct V_29 * V_29 ,
struct V_1 * V_8 ,
unsigned long V_24 )
{
unsigned long V_47 , V_48 ;
if ( ! F_38 ( V_29 ) )
return - V_49 ;
if ( ! V_8 -> V_24 )
return - V_50 ;
V_48 = V_24 & V_46 ;
V_47 = V_24 & V_42 ;
if ( V_48 )
F_29 ( V_29 , V_8 ) ;
if ( V_47 )
F_26 ( V_29 , V_8 ) ;
return 0 ;
}
static void F_39 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
F_37 ( V_29 , V_8 , V_8 -> V_24 ) ;
}
static void F_40 ( struct V_29 * V_29 ,
struct V_1
* V_8 )
{
F_39 ( V_29 , V_8 ) ;
F_41 ( V_8 -> V_20 ) ;
if ( F_42 ( V_8 -> V_20 ,
& V_8 -> V_51 ) )
F_5 ( V_52 L_2 ,
V_53 , F_43 ( & V_8 -> V_20 -> V_20 ) ) ;
else
F_44 ( V_8 -> V_20 ) ;
V_8 -> V_20 -> V_54 &= ~ V_55 ;
F_45 ( V_8 -> V_20 ) ;
F_46 ( V_8 -> V_20 ) ;
F_47 ( V_8 -> V_20 ) ;
F_48 ( & V_8 -> V_7 ) ;
F_32 ( V_8 ) ;
}
void F_49 ( struct V_29 * V_29 )
{
struct V_2 * V_5 , * V_56 ;
struct V_1 * V_8 ;
F_50 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_40 ( V_29 , V_8 ) ;
}
}
static int F_51 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
T_3 V_57 ;
unsigned long V_27 ;
V_20 -> V_40 = V_20 -> V_20 -> V_9 ;
if ( V_20 -> V_27 & V_31 ) {
V_57 = F_6 ;
V_27 = V_58 ;
} else {
V_57 = NULL ;
V_27 = V_59 ;
}
if ( F_52 ( V_20 -> V_40 , V_57 ,
F_13 , V_27 ,
V_20 -> V_60 , V_20 ) )
return - V_61 ;
if ( V_20 -> V_27 & V_31 ) {
F_14 ( & V_20 -> V_19 ) ;
F_34 ( V_20 -> V_20 , true ) ;
F_16 ( & V_20 -> V_19 ) ;
}
return 0 ;
}
static int F_53 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_62 ;
if ( ! V_20 -> V_20 -> V_63 ) {
V_62 = F_54 ( V_20 -> V_20 ) ;
if ( V_62 )
return V_62 ;
}
V_20 -> V_40 = V_20 -> V_20 -> V_9 ;
if ( F_52 ( V_20 -> V_40 , F_17 ,
F_19 , 0 ,
V_20 -> V_60 , V_20 ) ) {
F_36 ( V_20 -> V_20 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_55 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_10 , V_62 = - V_49 ;
if ( V_20 -> V_14 == 0 )
return V_62 ;
V_62 = F_56 ( V_20 -> V_20 , V_20 -> V_13 , V_20 -> V_14 ) ;
if ( V_62 )
return V_62 ;
for ( V_10 = 0 ; V_10 < V_20 -> V_14 ; V_10 ++ ) {
V_62 = F_52 ( V_20 -> V_13 [ V_10 ] . V_15 ,
F_20 ,
F_21 ,
0 , V_20 -> V_60 , V_20 ) ;
if ( V_62 )
goto V_64;
}
return 0 ;
V_64:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_31 ( V_20 -> V_13 [ V_10 ] . V_15 , V_20 ) ;
F_33 ( V_20 -> V_20 ) ;
return V_62 ;
}
static int F_57 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_65 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = V_9 -> V_32 ;
return 0 ;
}
static int F_58 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_65 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = - 1 ;
return 0 ;
}
static int F_59 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_65 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = - 1 ;
return 0 ;
}
static int F_60 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
T_4 V_48 )
{
int V_62 = - V_66 ;
if ( V_20 -> V_24 & V_46 )
return V_62 ;
snprintf ( V_20 -> V_60 , sizeof( V_20 -> V_60 ) , L_3 ,
F_61 ( V_20 -> V_20 ) ) ;
switch ( V_48 ) {
case V_44 :
V_62 = F_51 ( V_29 , V_20 ) ;
break;
#ifdef F_62
case V_45 :
V_62 = F_53 ( V_29 , V_20 ) ;
break;
#endif
#ifdef F_63
case V_43 :
V_62 = F_55 ( V_29 , V_20 ) ;
break;
#endif
default:
V_62 = - V_49 ;
}
V_20 -> V_21 = false ;
if ( ! V_62 )
V_20 -> V_24 |= V_48 ;
return V_62 ;
}
static int F_64 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_65 * V_9 ,
unsigned long V_47 )
{
int V_67 ;
int V_62 = - V_66 ;
if ( V_20 -> V_24 & V_42 )
return V_62 ;
V_67 = F_65 ( V_29 ) ;
if ( V_67 < 0 )
return V_67 ;
V_20 -> V_30 = V_67 ;
switch ( V_47 ) {
case V_25 :
V_62 = F_57 ( V_29 , V_20 , V_9 ) ;
break;
#ifdef F_62
case V_68 :
V_62 = F_58 ( V_29 , V_20 , V_9 ) ;
break;
#endif
#ifdef F_63
case V_69 :
V_62 = F_59 ( V_29 , V_20 , V_9 ) ;
break;
#endif
default:
V_62 = - V_49 ;
}
if ( ! V_62 ) {
V_20 -> V_24 |= V_47 ;
if ( V_20 -> V_38 . V_41 != - 1 )
F_66 ( V_29 , & V_20 -> V_38 ) ;
} else
F_28 ( V_29 , V_20 -> V_30 ) ;
return V_62 ;
}
static int F_67 ( struct V_29 * V_29 ,
struct V_65 * V_70 )
{
int V_62 = - V_49 ;
struct V_1 * V_6 ;
unsigned long V_48 , V_47 ;
if ( ! F_38 ( V_29 ) )
return V_62 ;
F_68 ( & V_29 -> V_71 ) ;
V_62 = - V_72 ;
V_6 = F_1 ( & V_29 -> V_73 . V_74 ,
V_70 -> V_4 ) ;
if ( ! V_6 )
goto V_75;
V_48 = ( V_70 -> V_27 & V_46 ) ;
V_47 = ( V_70 -> V_27 & V_42 ) ;
V_62 = - V_49 ;
if ( F_69 ( V_48 ) > 1 )
goto V_75;
if ( F_69 ( V_47 ) > 1 )
goto V_75;
if ( V_48 == 0 && V_47 == 0 )
goto V_75;
V_62 = 0 ;
if ( V_48 )
V_62 = F_60 ( V_29 , V_6 , V_48 ) ;
if ( V_62 )
goto V_75;
if ( V_47 )
V_62 = F_64 ( V_29 , V_6 , V_70 , V_47 ) ;
V_75:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_71 ( struct V_29 * V_29 ,
struct V_65
* V_70 )
{
int V_62 = - V_72 ;
struct V_1 * V_6 ;
unsigned long V_76 ;
F_68 ( & V_29 -> V_71 ) ;
V_6 = F_1 ( & V_29 -> V_73 . V_74 ,
V_70 -> V_4 ) ;
if ( ! V_6 )
goto V_75;
V_76 = V_70 -> V_27 & ( V_46 |
V_42 ) ;
V_62 = F_37 ( V_29 , V_6 , V_76 ) ;
V_75:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_72 ( struct V_77 * V_20 )
{
#ifdef F_73
int V_10 ;
bool V_78 = false ;
for ( V_10 = V_79 ; V_10 <= V_80 ; V_10 ++ ) {
char * V_81 , * V_82 ;
struct V_83 V_83 ;
struct V_84 * V_84 ;
int V_62 ;
if ( ! F_74 ( V_20 , V_10 ) )
continue;
V_81 = F_75 ( & V_20 -> V_20 . V_85 , V_86 ) ;
if ( ! V_81 )
return - V_87 ;
V_82 = F_76 ( V_86 , L_4 , V_81 , V_10 ) ;
F_32 ( V_81 ) ;
if ( ! V_82 )
return - V_87 ;
V_62 = F_77 ( V_82 , V_88 , & V_83 ) ;
F_32 ( V_82 ) ;
if ( V_62 )
return V_62 ;
V_84 = V_83 . V_89 -> V_90 ;
V_62 = F_78 ( V_84 , V_91 | V_92 | V_93 ) ;
F_79 ( & V_83 ) ;
if ( V_62 )
return V_62 ;
V_78 = true ;
}
if ( ! V_78 )
return - V_94 ;
return 0 ;
#else
return - V_49 ;
#endif
}
static int F_80 ( struct V_29 * V_29 ,
struct V_95 * V_8 )
{
int V_62 = 0 , V_96 ;
struct V_1 * V_6 ;
struct V_77 * V_20 ;
if ( ! ( V_8 -> V_27 & V_97 ) )
return - V_49 ;
F_68 ( & V_29 -> V_71 ) ;
V_96 = F_81 ( & V_29 -> V_98 ) ;
V_6 = F_1 ( & V_29 -> V_73 . V_74 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_62 = - V_66 ;
goto V_75;
}
V_6 = F_82 ( sizeof( struct V_1 ) , V_86 ) ;
if ( V_6 == NULL ) {
F_5 ( V_52 L_5 ,
V_53 ) ;
V_62 = - V_87 ;
goto V_75;
}
V_20 = F_83 ( V_8 -> V_99 ,
V_8 -> V_100 ,
V_8 -> V_101 ) ;
if ( ! V_20 ) {
F_5 ( V_52 L_6 , V_53 ) ;
V_62 = - V_49 ;
goto V_102;
}
if ( V_20 -> V_103 != V_104 ) {
V_62 = - V_94 ;
goto V_105;
}
V_62 = F_72 ( V_20 ) ;
if ( V_62 )
goto V_105;
if ( F_84 ( V_20 ) ) {
F_5 ( V_52 L_7 , V_53 ) ;
V_62 = - V_106 ;
goto V_105;
}
V_62 = F_85 ( V_20 , L_8 ) ;
if ( V_62 ) {
F_5 ( V_52 L_9 ,
V_53 ) ;
goto V_107;
}
F_41 ( V_20 ) ;
F_86 ( V_20 ) ;
V_6 -> V_51 = F_87 ( V_20 ) ;
if ( ! V_6 -> V_51 )
F_5 ( V_108 L_10 ,
V_53 , F_43 ( & V_20 -> V_20 ) ) ;
if ( ! F_88 ( V_20 ) )
V_8 -> V_27 &= ~ V_31 ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_109 = V_8 -> V_99 ;
V_6 -> V_110 = V_8 -> V_100 ;
V_6 -> V_111 = V_8 -> V_101 ;
V_6 -> V_27 = V_8 -> V_27 ;
V_6 -> V_20 = V_20 ;
F_89 ( & V_6 -> V_19 ) ;
F_89 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = - 1 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_38 . V_112 = F_22 ;
F_90 ( & V_6 -> V_7 , & V_29 -> V_73 . V_74 ) ;
if ( ! V_29 -> V_73 . V_113 ) {
V_62 = F_91 ( V_29 ) ;
if ( V_62 )
goto V_114;
}
V_62 = F_92 ( V_29 , V_6 ) ;
if ( V_62 )
goto V_114;
V_75:
F_93 ( & V_29 -> V_98 , V_96 ) ;
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
V_114:
if ( F_42 ( V_20 , & V_6 -> V_51 ) )
F_5 ( V_52 L_2 ,
V_53 , F_43 ( & V_20 -> V_20 ) ) ;
F_48 ( & V_6 -> V_7 ) ;
F_45 ( V_20 ) ;
V_107:
F_46 ( V_20 ) ;
V_105:
F_47 ( V_20 ) ;
V_102:
F_32 ( V_6 ) ;
F_93 ( & V_29 -> V_98 , V_96 ) ;
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_94 ( struct V_29 * V_29 ,
struct V_95 * V_8 )
{
int V_62 = 0 ;
struct V_1 * V_6 ;
F_68 ( & V_29 -> V_71 ) ;
V_6 = F_1 ( & V_29 -> V_73 . V_74 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_52 L_11
L_12 , V_53 ) ;
V_62 = - V_49 ;
goto V_75;
}
F_95 ( V_29 , V_6 ) ;
F_40 ( V_29 , V_6 ) ;
V_75:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_96 ( struct V_29 * V_29 ,
struct V_115 * V_116 )
{
int V_62 = 0 ;
struct V_1 * V_117 ;
F_68 ( & V_29 -> V_71 ) ;
V_117 = F_1 ( & V_29 -> V_73 . V_74 ,
V_116 -> V_4 ) ;
if ( ! V_117 ) {
V_62 = - V_49 ;
goto V_118;
}
if ( V_117 -> V_14 == 0 ) {
V_117 -> V_14 = V_116 -> V_116 ;
if ( V_117 -> V_14 == 0 ||
V_117 -> V_14 > V_119 ) {
V_62 = - V_49 ;
goto V_118;
}
V_117 -> V_13 = F_82 ( sizeof( struct V_12 ) *
V_116 -> V_116 ,
V_86 ) ;
if ( ! V_117 -> V_13 ) {
V_62 = - V_87 ;
goto V_118;
}
V_117 -> V_35 =
F_82 ( sizeof( struct V_12 ) * V_116 -> V_116 ,
V_86 ) ;
if ( ! V_117 -> V_35 ) {
F_32 ( V_117 -> V_13 ) ;
V_62 = - V_87 ;
goto V_118;
}
} else
V_62 = - V_49 ;
V_118:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_97 ( struct V_29 * V_29 ,
struct V_120 * V_121 )
{
int V_62 = 0 , V_10 ;
struct V_1 * V_117 ;
F_68 ( & V_29 -> V_71 ) ;
V_117 = F_1 ( & V_29 -> V_73 . V_74 ,
V_121 -> V_4 ) ;
if ( ! V_117 ) {
V_62 = - V_49 ;
goto V_122;
}
for ( V_10 = 0 ; V_10 < V_117 -> V_14 ; V_10 ++ )
if ( V_117 -> V_35 [ V_10 ] . V_15 == 0 ||
V_117 -> V_35 [ V_10 ] . V_121 == V_121 -> V_121 ) {
V_117 -> V_35 [ V_10 ] . V_121 = V_121 -> V_121 ;
V_117 -> V_35 [ V_10 ] . V_15 = V_121 -> V_41 ;
V_117 -> V_13 [ V_10 ] . V_121 = V_121 -> V_121 ;
break;
}
if ( V_10 == V_117 -> V_14 ) {
V_62 = - V_123 ;
goto V_122;
}
V_122:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
static int F_98 ( struct V_29 * V_29 ,
struct V_95 * V_8 )
{
int V_62 = 0 ;
struct V_1 * V_6 ;
F_68 ( & V_29 -> V_71 ) ;
V_6 = F_1 ( & V_29 -> V_73 . V_74 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
V_62 = - V_72 ;
goto V_75;
}
F_7 ( & V_6 -> V_26 ) ;
V_6 -> V_27 &= ~ V_28 ;
V_6 -> V_27 |= V_8 -> V_27 & V_28 ;
if ( V_6 -> V_24 & V_25 ) {
if ( V_8 -> V_27 & V_28 ) {
F_12 ( V_6 -> V_29 , V_6 -> V_30 ,
V_6 -> V_32 , 0 , false ) ;
} else if ( ! ( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_6 -> V_19 ) ;
if ( V_6 -> V_21 ) {
F_24 ( V_6 -> V_40 ) ;
V_6 -> V_21 = false ;
}
F_16 ( & V_6 -> V_19 ) ;
}
}
F_9 ( & V_6 -> V_26 ) ;
V_75:
F_70 ( & V_29 -> V_71 ) ;
return V_62 ;
}
long F_99 ( struct V_29 * V_29 , unsigned V_124 ,
unsigned long V_125 )
{
void T_5 * V_126 = ( void T_5 * ) V_125 ;
int V_62 ;
switch ( V_124 ) {
case V_127 : {
struct V_95 V_8 ;
V_62 = - V_128 ;
if ( F_100 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_75;
V_62 = F_80 ( V_29 , & V_8 ) ;
if ( V_62 )
goto V_75;
break;
}
case V_129 : {
V_62 = - V_130 ;
break;
}
case V_131 : {
struct V_65 V_70 ;
V_62 = - V_128 ;
if ( F_100 ( & V_70 , V_126 , sizeof V_70 ) )
goto V_75;
V_62 = F_67 ( V_29 , & V_70 ) ;
if ( V_62 )
goto V_75;
break;
}
case V_132 : {
struct V_65 V_70 ;
V_62 = - V_128 ;
if ( F_100 ( & V_70 , V_126 , sizeof V_70 ) )
goto V_75;
V_62 = F_71 ( V_29 , & V_70 ) ;
if ( V_62 )
goto V_75;
break;
}
case V_133 : {
struct V_95 V_8 ;
V_62 = - V_128 ;
if ( F_100 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_75;
V_62 = F_94 ( V_29 , & V_8 ) ;
if ( V_62 )
goto V_75;
break;
}
#ifdef F_63
case V_134 : {
struct V_115 V_116 ;
V_62 = - V_128 ;
if ( F_100 ( & V_116 , V_126 , sizeof V_116 ) )
goto V_75;
V_62 = F_96 ( V_29 , & V_116 ) ;
if ( V_62 )
goto V_75;
break;
}
case V_135 : {
struct V_120 V_121 ;
V_62 = - V_128 ;
if ( F_100 ( & V_121 , V_126 , sizeof V_121 ) )
goto V_75;
V_62 = F_97 ( V_29 , & V_121 ) ;
if ( V_62 )
goto V_75;
break;
}
#endif
case V_136 : {
struct V_95 V_8 ;
V_62 = - V_128 ;
if ( F_100 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_75;
V_62 = F_98 ( V_29 , & V_8 ) ;
break;
}
default:
V_62 = - V_137 ;
break;
}
V_75:
return V_62 ;
}
