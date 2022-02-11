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
V_8 -> V_30 , V_15 , 1 ) ;
F_9 ( & V_8 -> V_26 ) ;
} else
F_12 ( V_8 -> V_29 , V_8 -> V_30 ,
V_15 , 1 ) ;
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
F_10 ( V_8 ,
V_8 -> V_32 ) ;
return V_33 ;
}
static T_1 F_18 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_34 [ V_11 ] . V_15 ;
F_10 ( V_8 , V_15 ) ;
}
return V_33 ;
}
static void F_19 ( struct V_35 * V_36 )
{
struct V_1 * V_20 =
F_20 ( V_36 , struct V_1 ,
V_37 ) ;
F_12 ( V_20 -> V_29 , V_20 -> V_30 , V_20 -> V_32 , 0 ) ;
F_7 ( & V_20 -> V_26 ) ;
if ( ! ( V_20 -> V_27 & V_28 ) ) {
bool V_38 = false ;
F_14 ( & V_20 -> V_19 ) ;
if ( V_20 -> V_21 ) {
if ( ! ( V_20 -> V_27 & V_31 ) )
F_21 ( V_20 -> V_39 ) ;
else if ( ! F_22 ( V_20 -> V_20 ) )
V_38 = true ;
V_20 -> V_21 = V_38 ;
}
F_16 ( & V_20 -> V_19 ) ;
if ( V_38 )
F_12 ( V_20 -> V_29 , V_20 -> V_30 ,
V_20 -> V_32 , 1 ) ;
}
F_9 ( & V_20 -> V_26 ) ;
}
static void F_23 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_37 . V_40 != - 1 )
F_24 ( V_29 ,
& V_8 -> V_37 ) ;
F_12 ( V_8 -> V_29 , V_8 -> V_30 ,
V_8 -> V_32 , 0 ) ;
if ( V_8 -> V_30 != - 1 )
F_25 ( V_29 , V_8 -> V_30 ) ;
V_8 -> V_30 = - 1 ;
V_8 -> V_24 &= ~ ( V_41 ) ;
}
static void F_26 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_24 & V_42 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_27 ( V_8 -> V_13 [ V_10 ] . V_15 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_28 ( V_8 -> V_13 [ V_10 ] . V_15 ,
V_8 ) ;
V_8 -> V_14 = 0 ;
F_29 ( V_8 -> V_13 ) ;
F_29 ( V_8 -> V_34 ) ;
F_30 ( V_8 -> V_20 ) ;
} else {
if ( ( V_8 -> V_24 &
V_43 ) &&
( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_8 -> V_19 ) ;
F_31 ( V_8 -> V_20 , false ) ;
F_16 ( & V_8 -> V_19 ) ;
F_32 ( V_8 -> V_39 ) ;
} else
F_27 ( V_8 -> V_39 ) ;
F_28 ( V_8 -> V_39 , V_8 ) ;
if ( V_8 -> V_24 & V_44 )
F_33 ( V_8 -> V_20 ) ;
}
V_8 -> V_24 &= ~ ( V_45 ) ;
}
static int F_34 ( struct V_29 * V_29 ,
struct V_1 * V_8 ,
unsigned long V_24 )
{
unsigned long V_46 , V_47 ;
if ( ! F_35 ( V_29 ) )
return - V_48 ;
if ( ! V_8 -> V_24 )
return - V_49 ;
V_47 = V_24 & V_45 ;
V_46 = V_24 & V_41 ;
if ( V_47 )
F_26 ( V_29 , V_8 ) ;
if ( V_46 )
F_23 ( V_29 , V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
F_34 ( V_29 , V_8 , V_8 -> V_24 ) ;
}
static void F_37 ( struct V_29 * V_29 ,
struct V_1
* V_8 )
{
F_36 ( V_29 , V_8 ) ;
F_38 ( V_8 -> V_20 ) ;
if ( F_39 ( V_8 -> V_20 ,
& V_8 -> V_50 ) )
F_5 ( V_51 L_2 ,
V_52 , F_40 ( & V_8 -> V_20 -> V_20 ) ) ;
else
F_41 ( V_8 -> V_20 ) ;
V_8 -> V_20 -> V_53 &= ~ V_54 ;
F_42 ( V_8 -> V_20 ) ;
F_43 ( V_8 -> V_20 ) ;
F_44 ( V_8 -> V_20 ) ;
F_45 ( & V_8 -> V_7 ) ;
F_29 ( V_8 ) ;
}
void F_46 ( struct V_29 * V_29 )
{
struct V_2 * V_5 , * V_55 ;
struct V_1 * V_8 ;
F_47 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_37 ( V_29 , V_8 ) ;
}
}
static int F_48 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
T_3 V_56 ;
unsigned long V_27 ;
V_20 -> V_39 = V_20 -> V_20 -> V_9 ;
if ( V_20 -> V_27 & V_31 ) {
V_56 = F_6 ;
V_27 = V_57 ;
} else {
V_56 = NULL ;
V_27 = V_58 ;
}
if ( F_49 ( V_20 -> V_39 , V_56 ,
F_13 , V_27 ,
V_20 -> V_59 , V_20 ) )
return - V_60 ;
if ( V_20 -> V_27 & V_31 ) {
F_14 ( & V_20 -> V_19 ) ;
F_31 ( V_20 -> V_20 , true ) ;
F_16 ( & V_20 -> V_19 ) ;
}
return 0 ;
}
static int F_50 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_61 ;
if ( ! V_20 -> V_20 -> V_62 ) {
V_61 = F_51 ( V_20 -> V_20 ) ;
if ( V_61 )
return V_61 ;
}
V_20 -> V_39 = V_20 -> V_20 -> V_9 ;
if ( F_49 ( V_20 -> V_39 , NULL ,
F_17 , 0 ,
V_20 -> V_59 , V_20 ) ) {
F_33 ( V_20 -> V_20 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_52 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_10 , V_61 = - V_48 ;
if ( V_20 -> V_14 == 0 )
return V_61 ;
V_61 = F_53 ( V_20 -> V_20 , V_20 -> V_13 , V_20 -> V_14 ) ;
if ( V_61 )
return V_61 ;
for ( V_10 = 0 ; V_10 < V_20 -> V_14 ; V_10 ++ ) {
V_61 = F_49 ( V_20 -> V_13 [ V_10 ] . V_15 ,
NULL , F_18 ,
0 , V_20 -> V_59 , V_20 ) ;
if ( V_61 )
goto V_63;
}
return 0 ;
V_63:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_28 ( V_20 -> V_13 [ V_10 ] . V_15 , V_20 ) ;
F_30 ( V_20 -> V_20 ) ;
return V_61 ;
}
static int F_54 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_64 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_37 . V_40 = V_9 -> V_32 ;
return 0 ;
}
static int F_55 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_64 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_37 . V_40 = - 1 ;
return 0 ;
}
static int F_56 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_64 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_37 . V_40 = - 1 ;
return 0 ;
}
static int F_57 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
T_4 V_47 )
{
int V_61 = - V_65 ;
if ( V_20 -> V_24 & V_45 )
return V_61 ;
snprintf ( V_20 -> V_59 , sizeof( V_20 -> V_59 ) , L_3 ,
F_58 ( V_20 -> V_20 ) ) ;
switch ( V_47 ) {
case V_43 :
V_61 = F_48 ( V_29 , V_20 ) ;
break;
#ifdef F_59
case V_44 :
V_61 = F_50 ( V_29 , V_20 ) ;
break;
#endif
#ifdef F_60
case V_42 :
V_61 = F_52 ( V_29 , V_20 ) ;
break;
#endif
default:
V_61 = - V_48 ;
}
V_20 -> V_21 = false ;
if ( ! V_61 )
V_20 -> V_24 |= V_47 ;
return V_61 ;
}
static int F_61 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_64 * V_9 ,
unsigned long V_46 )
{
int V_66 ;
int V_61 = - V_65 ;
if ( V_20 -> V_24 & V_41 )
return V_61 ;
V_66 = F_62 ( V_29 ) ;
if ( V_66 < 0 )
return V_66 ;
V_20 -> V_30 = V_66 ;
switch ( V_46 ) {
case V_25 :
V_61 = F_54 ( V_29 , V_20 , V_9 ) ;
break;
#ifdef F_59
case V_67 :
V_61 = F_55 ( V_29 , V_20 , V_9 ) ;
break;
#endif
#ifdef F_60
case V_68 :
V_61 = F_56 ( V_29 , V_20 , V_9 ) ;
break;
#endif
default:
V_61 = - V_48 ;
}
if ( ! V_61 ) {
V_20 -> V_24 |= V_46 ;
if ( V_20 -> V_37 . V_40 != - 1 )
F_63 ( V_29 , & V_20 -> V_37 ) ;
} else
F_25 ( V_29 , V_20 -> V_30 ) ;
return V_61 ;
}
static int F_64 ( struct V_29 * V_29 ,
struct V_64 * V_69 )
{
int V_61 = - V_48 ;
struct V_1 * V_6 ;
unsigned long V_47 , V_46 ;
if ( ! F_35 ( V_29 ) )
return V_61 ;
F_65 ( & V_29 -> V_70 ) ;
V_61 = - V_71 ;
V_6 = F_1 ( & V_29 -> V_72 . V_73 ,
V_69 -> V_4 ) ;
if ( ! V_6 )
goto V_74;
V_47 = ( V_69 -> V_27 & V_45 ) ;
V_46 = ( V_69 -> V_27 & V_41 ) ;
V_61 = - V_48 ;
if ( F_66 ( V_47 ) > 1 )
goto V_74;
if ( F_66 ( V_46 ) > 1 )
goto V_74;
if ( V_47 == 0 && V_46 == 0 )
goto V_74;
V_61 = 0 ;
if ( V_47 )
V_61 = F_57 ( V_29 , V_6 , V_47 ) ;
if ( V_61 )
goto V_74;
if ( V_46 )
V_61 = F_61 ( V_29 , V_6 , V_69 , V_46 ) ;
V_74:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_68 ( struct V_29 * V_29 ,
struct V_64
* V_69 )
{
int V_61 = - V_71 ;
struct V_1 * V_6 ;
unsigned long V_75 ;
F_65 ( & V_29 -> V_70 ) ;
V_6 = F_1 ( & V_29 -> V_72 . V_73 ,
V_69 -> V_4 ) ;
if ( ! V_6 )
goto V_74;
V_75 = V_69 -> V_27 & ( V_45 |
V_41 ) ;
V_61 = F_34 ( V_29 , V_6 , V_75 ) ;
V_74:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_69 ( struct V_76 * V_20 )
{
#ifdef F_70
int V_10 ;
bool V_77 = false ;
for ( V_10 = V_78 ; V_10 <= V_79 ; V_10 ++ ) {
char * V_80 , * V_81 ;
struct V_82 V_82 ;
struct V_83 * V_83 ;
int V_61 ;
if ( ! F_71 ( V_20 , V_10 ) )
continue;
V_80 = F_72 ( & V_20 -> V_20 . V_84 , V_85 ) ;
if ( ! V_80 )
return - V_86 ;
V_81 = F_73 ( V_85 , L_4 , V_80 , V_10 ) ;
F_29 ( V_80 ) ;
if ( ! V_81 )
return - V_86 ;
V_61 = F_74 ( V_81 , V_87 , & V_82 ) ;
F_29 ( V_81 ) ;
if ( V_61 )
return V_61 ;
V_83 = V_82 . V_88 -> V_89 ;
V_61 = F_75 ( V_83 , V_90 | V_91 | V_92 ) ;
F_76 ( & V_82 ) ;
if ( V_61 )
return V_61 ;
V_77 = true ;
}
if ( ! V_77 )
return - V_93 ;
return 0 ;
#else
return - V_48 ;
#endif
}
static int F_77 ( struct V_29 * V_29 ,
struct V_94 * V_8 )
{
int V_61 = 0 , V_95 ;
struct V_1 * V_6 ;
struct V_76 * V_20 ;
T_5 V_96 ;
if ( ! ( V_8 -> V_27 & V_97 ) )
return - V_48 ;
F_65 ( & V_29 -> V_70 ) ;
V_95 = F_78 ( & V_29 -> V_98 ) ;
V_6 = F_1 ( & V_29 -> V_72 . V_73 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_61 = - V_65 ;
goto V_74;
}
V_6 = F_79 ( sizeof( struct V_1 ) , V_85 ) ;
if ( V_6 == NULL ) {
F_5 ( V_51 L_5 ,
V_52 ) ;
V_61 = - V_86 ;
goto V_74;
}
V_20 = F_80 ( V_8 -> V_99 ,
V_8 -> V_100 ,
V_8 -> V_101 ) ;
if ( ! V_20 ) {
F_5 ( V_51 L_6 , V_52 ) ;
V_61 = - V_48 ;
goto V_102;
}
F_81 ( V_20 , V_103 , & V_96 ) ;
if ( ( V_96 & V_103 ) != V_104 ) {
V_61 = - V_93 ;
goto V_105;
}
V_61 = F_69 ( V_20 ) ;
if ( V_61 )
goto V_105;
if ( F_82 ( V_20 ) ) {
F_5 ( V_51 L_7 , V_52 ) ;
V_61 = - V_106 ;
goto V_105;
}
V_61 = F_83 ( V_20 , L_8 ) ;
if ( V_61 ) {
F_5 ( V_51 L_9 ,
V_52 ) ;
goto V_107;
}
F_38 ( V_20 ) ;
F_84 ( V_20 ) ;
V_6 -> V_50 = F_85 ( V_20 ) ;
if ( ! V_6 -> V_50 )
F_5 ( V_108 L_10 ,
V_52 , F_40 ( & V_20 -> V_20 ) ) ;
if ( ! F_86 ( V_20 ) )
V_8 -> V_27 &= ~ V_31 ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_109 = V_8 -> V_99 ;
V_6 -> V_110 = V_8 -> V_100 ;
V_6 -> V_111 = V_8 -> V_101 ;
V_6 -> V_27 = V_8 -> V_27 ;
V_6 -> V_20 = V_20 ;
F_87 ( & V_6 -> V_19 ) ;
F_87 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = - 1 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_37 . V_112 = F_19 ;
F_88 ( & V_6 -> V_7 , & V_29 -> V_72 . V_73 ) ;
if ( ! V_29 -> V_72 . V_113 ) {
V_61 = F_89 ( V_29 ) ;
if ( V_61 )
goto V_114;
}
V_61 = F_90 ( V_29 , V_6 ) ;
if ( V_61 )
goto V_114;
V_74:
F_91 ( & V_29 -> V_98 , V_95 ) ;
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
V_114:
if ( F_39 ( V_20 , & V_6 -> V_50 ) )
F_5 ( V_51 L_2 ,
V_52 , F_40 ( & V_20 -> V_20 ) ) ;
F_45 ( & V_6 -> V_7 ) ;
F_42 ( V_20 ) ;
V_107:
F_43 ( V_20 ) ;
V_105:
F_44 ( V_20 ) ;
V_102:
F_29 ( V_6 ) ;
F_91 ( & V_29 -> V_98 , V_95 ) ;
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_92 ( struct V_29 * V_29 ,
struct V_94 * V_8 )
{
int V_61 = 0 ;
struct V_1 * V_6 ;
F_65 ( & V_29 -> V_70 ) ;
V_6 = F_1 ( & V_29 -> V_72 . V_73 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_51 L_11
L_12 , V_52 ) ;
V_61 = - V_48 ;
goto V_74;
}
F_93 ( V_29 , V_6 ) ;
F_37 ( V_29 , V_6 ) ;
V_74:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_94 ( struct V_29 * V_29 ,
struct V_115 * V_116 )
{
int V_61 = 0 ;
struct V_1 * V_117 ;
F_65 ( & V_29 -> V_70 ) ;
V_117 = F_1 ( & V_29 -> V_72 . V_73 ,
V_116 -> V_4 ) ;
if ( ! V_117 ) {
V_61 = - V_48 ;
goto V_118;
}
if ( V_117 -> V_14 == 0 ) {
V_117 -> V_14 = V_116 -> V_116 ;
if ( V_117 -> V_14 == 0 ||
V_117 -> V_14 > V_119 ) {
V_61 = - V_48 ;
goto V_118;
}
V_117 -> V_13 = F_79 ( sizeof( struct V_12 ) *
V_116 -> V_116 ,
V_85 ) ;
if ( ! V_117 -> V_13 ) {
V_61 = - V_86 ;
goto V_118;
}
V_117 -> V_34 =
F_79 ( sizeof( struct V_12 ) * V_116 -> V_116 ,
V_85 ) ;
if ( ! V_117 -> V_34 ) {
F_29 ( V_117 -> V_13 ) ;
V_61 = - V_86 ;
goto V_118;
}
} else
V_61 = - V_48 ;
V_118:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_95 ( struct V_29 * V_29 ,
struct V_120 * V_121 )
{
int V_61 = 0 , V_10 ;
struct V_1 * V_117 ;
F_65 ( & V_29 -> V_70 ) ;
V_117 = F_1 ( & V_29 -> V_72 . V_73 ,
V_121 -> V_4 ) ;
if ( ! V_117 ) {
V_61 = - V_48 ;
goto V_122;
}
for ( V_10 = 0 ; V_10 < V_117 -> V_14 ; V_10 ++ )
if ( V_117 -> V_34 [ V_10 ] . V_15 == 0 ||
V_117 -> V_34 [ V_10 ] . V_121 == V_121 -> V_121 ) {
V_117 -> V_34 [ V_10 ] . V_121 = V_121 -> V_121 ;
V_117 -> V_34 [ V_10 ] . V_15 = V_121 -> V_40 ;
V_117 -> V_13 [ V_10 ] . V_121 = V_121 -> V_121 ;
break;
}
if ( V_10 == V_117 -> V_14 ) {
V_61 = - V_123 ;
goto V_122;
}
V_122:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
static int F_96 ( struct V_29 * V_29 ,
struct V_94 * V_8 )
{
int V_61 = 0 ;
struct V_1 * V_6 ;
F_65 ( & V_29 -> V_70 ) ;
V_6 = F_1 ( & V_29 -> V_72 . V_73 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
V_61 = - V_71 ;
goto V_74;
}
F_7 ( & V_6 -> V_26 ) ;
V_6 -> V_27 &= ~ V_28 ;
V_6 -> V_27 |= V_8 -> V_27 & V_28 ;
if ( V_6 -> V_24 & V_25 ) {
if ( V_8 -> V_27 & V_28 ) {
F_12 ( V_6 -> V_29 , V_6 -> V_30 ,
V_6 -> V_32 , 0 ) ;
} else if ( ! ( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_6 -> V_19 ) ;
if ( V_6 -> V_21 ) {
F_21 ( V_6 -> V_39 ) ;
V_6 -> V_21 = false ;
}
F_16 ( & V_6 -> V_19 ) ;
}
}
F_9 ( & V_6 -> V_26 ) ;
V_74:
F_67 ( & V_29 -> V_70 ) ;
return V_61 ;
}
long F_97 ( struct V_29 * V_29 , unsigned V_124 ,
unsigned long V_125 )
{
void T_6 * V_126 = ( void T_6 * ) V_125 ;
int V_61 ;
switch ( V_124 ) {
case V_127 : {
struct V_94 V_8 ;
V_61 = - V_128 ;
if ( F_98 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_74;
V_61 = F_77 ( V_29 , & V_8 ) ;
if ( V_61 )
goto V_74;
break;
}
case V_129 : {
V_61 = - V_130 ;
break;
}
case V_131 : {
struct V_64 V_69 ;
V_61 = - V_128 ;
if ( F_98 ( & V_69 , V_126 , sizeof V_69 ) )
goto V_74;
V_61 = F_64 ( V_29 , & V_69 ) ;
if ( V_61 )
goto V_74;
break;
}
case V_132 : {
struct V_64 V_69 ;
V_61 = - V_128 ;
if ( F_98 ( & V_69 , V_126 , sizeof V_69 ) )
goto V_74;
V_61 = F_68 ( V_29 , & V_69 ) ;
if ( V_61 )
goto V_74;
break;
}
case V_133 : {
struct V_94 V_8 ;
V_61 = - V_128 ;
if ( F_98 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_74;
V_61 = F_92 ( V_29 , & V_8 ) ;
if ( V_61 )
goto V_74;
break;
}
#ifdef F_99
case V_134 : {
struct V_135 V_136 ;
struct V_135 T_6 * V_137 ;
struct V_138 * V_139 ;
V_61 = - V_128 ;
if ( F_98 ( & V_136 , V_126 , sizeof( V_136 ) ) )
goto V_74;
V_61 = - V_48 ;
if ( V_136 . V_140 >= V_141 )
goto V_74;
if ( V_136 . V_27 )
goto V_74;
V_61 = - V_86 ;
V_139 = F_100 ( V_136 . V_140 * sizeof( * V_139 ) ) ;
if ( ! V_139 )
goto V_74;
V_61 = - V_128 ;
V_137 = V_126 ;
if ( F_98 ( V_139 , V_137 -> V_139 ,
V_136 . V_140 * sizeof( * V_139 ) ) )
goto V_142;
V_61 = F_101 ( V_29 , V_139 , V_136 . V_140 ,
V_136 . V_27 ) ;
V_142:
F_102 ( V_139 ) ;
break;
}
#endif
#ifdef F_60
case V_143 : {
struct V_115 V_116 ;
V_61 = - V_128 ;
if ( F_98 ( & V_116 , V_126 , sizeof V_116 ) )
goto V_74;
V_61 = F_94 ( V_29 , & V_116 ) ;
if ( V_61 )
goto V_74;
break;
}
case V_144 : {
struct V_120 V_121 ;
V_61 = - V_128 ;
if ( F_98 ( & V_121 , V_126 , sizeof V_121 ) )
goto V_74;
V_61 = F_95 ( V_29 , & V_121 ) ;
if ( V_61 )
goto V_74;
break;
}
#endif
case V_145 : {
struct V_94 V_8 ;
V_61 = - V_128 ;
if ( F_98 ( & V_8 , V_126 , sizeof V_8 ) )
goto V_74;
V_61 = F_96 ( V_29 , & V_8 ) ;
break;
}
default:
V_61 = - V_146 ;
break;
}
V_74:
return V_61 ;
}
