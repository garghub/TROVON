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
static int F_17 ( struct V_29 * V_29 , int V_30 , T_2 V_9 ,
int V_34 )
{
struct V_35 V_36 [ V_37 ] ;
struct V_35 * V_38 ;
int V_18 = - V_39 ;
int V_40 ;
F_18 ( V_9 , V_34 , V_30 ) ;
V_40 = F_19 ( & V_29 -> V_41 ) ;
if ( F_20 ( V_29 , V_36 , V_9 ) > 0 ) {
V_38 = & V_36 [ 0 ] ;
V_18 = F_21 ( V_38 , V_29 , V_30 ,
V_9 , V_34 ) ;
}
F_22 ( & V_29 -> V_41 , V_40 ) ;
return V_18 ;
}
static T_1 F_23 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_18 = F_17 ( V_8 -> V_29 ,
V_8 -> V_30 ,
V_8 -> V_32 , 1 ) ;
return F_11 ( V_18 == - V_42 ) ? V_22 : V_33 ;
}
static T_1 F_24 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
F_10 ( V_8 ,
V_8 -> V_32 ) ;
return V_33 ;
}
static T_1 F_25 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
int V_18 = 0 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_43 [ V_11 ] . V_15 ;
V_18 = F_17 ( V_8 -> V_29 ,
V_8 -> V_30 ,
V_15 , 1 ) ;
}
return F_11 ( V_18 == - V_42 ) ? V_22 : V_33 ;
}
static T_1 F_26 ( int V_9 , void * V_17 )
{
struct V_1 * V_8 = V_17 ;
int V_11 = F_4 ( V_8 , V_9 ) ;
T_2 V_15 ;
if ( V_11 >= 0 ) {
V_15 = V_8 -> V_43 [ V_11 ] . V_15 ;
F_10 ( V_8 , V_15 ) ;
}
return V_33 ;
}
static void F_27 ( struct V_44 * V_45 )
{
struct V_1 * V_20 =
F_28 ( V_45 , struct V_1 ,
V_46 ) ;
F_12 ( V_20 -> V_29 , V_20 -> V_30 , V_20 -> V_32 , 0 , false ) ;
F_7 ( & V_20 -> V_26 ) ;
if ( ! ( V_20 -> V_27 & V_28 ) ) {
bool V_47 = false ;
F_14 ( & V_20 -> V_19 ) ;
if ( V_20 -> V_21 ) {
if ( ! ( V_20 -> V_27 & V_31 ) )
F_29 ( V_20 -> V_48 ) ;
else if ( ! F_30 ( V_20 -> V_20 ) )
V_47 = true ;
V_20 -> V_21 = V_47 ;
}
F_16 ( & V_20 -> V_19 ) ;
if ( V_47 )
F_12 ( V_20 -> V_29 , V_20 -> V_30 ,
V_20 -> V_32 , 1 , false ) ;
}
F_9 ( & V_20 -> V_26 ) ;
}
static void F_31 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_46 . V_49 != - 1 )
F_32 ( V_29 ,
& V_8 -> V_46 ) ;
F_12 ( V_8 -> V_29 , V_8 -> V_30 ,
V_8 -> V_32 , 0 , false ) ;
if ( V_8 -> V_30 != - 1 )
F_33 ( V_29 , V_8 -> V_30 ) ;
V_8 -> V_30 = - 1 ;
V_8 -> V_24 &= ~ ( V_50 ) ;
}
static void F_34 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
if ( V_8 -> V_24 & V_51 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_35 ( V_8 -> V_13 [ V_10 ] . V_15 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_14 ; V_10 ++ )
F_36 ( V_8 -> V_13 [ V_10 ] . V_15 ,
V_8 ) ;
V_8 -> V_14 = 0 ;
F_37 ( V_8 -> V_13 ) ;
F_37 ( V_8 -> V_43 ) ;
F_38 ( V_8 -> V_20 ) ;
} else {
if ( ( V_8 -> V_24 &
V_52 ) &&
( V_8 -> V_27 & V_31 ) ) {
F_14 ( & V_8 -> V_19 ) ;
F_39 ( V_8 -> V_20 , false ) ;
F_16 ( & V_8 -> V_19 ) ;
F_40 ( V_8 -> V_48 ) ;
} else
F_35 ( V_8 -> V_48 ) ;
F_36 ( V_8 -> V_48 , V_8 ) ;
if ( V_8 -> V_24 & V_53 )
F_41 ( V_8 -> V_20 ) ;
}
V_8 -> V_24 &= ~ ( V_54 ) ;
}
static int F_42 ( struct V_29 * V_29 ,
struct V_1 * V_8 ,
unsigned long V_24 )
{
unsigned long V_55 , V_56 ;
if ( ! F_43 ( V_29 ) )
return - V_39 ;
if ( ! V_8 -> V_24 )
return - V_57 ;
V_56 = V_24 & V_54 ;
V_55 = V_24 & V_50 ;
if ( V_56 )
F_34 ( V_29 , V_8 ) ;
if ( V_55 )
F_31 ( V_29 , V_8 ) ;
return 0 ;
}
static void F_44 ( struct V_29 * V_29 ,
struct V_1 * V_8 )
{
F_42 ( V_29 , V_8 , V_8 -> V_24 ) ;
}
static void F_45 ( struct V_29 * V_29 ,
struct V_1
* V_8 )
{
F_44 ( V_29 , V_8 ) ;
F_46 ( V_8 -> V_20 ) ;
if ( F_47 ( V_8 -> V_20 ,
& V_8 -> V_58 ) )
F_5 ( V_59 L_2 ,
V_60 , F_48 ( & V_8 -> V_20 -> V_20 ) ) ;
else
F_49 ( V_8 -> V_20 ) ;
F_50 ( V_8 -> V_20 ) ;
F_51 ( V_8 -> V_20 ) ;
F_52 ( V_8 -> V_20 ) ;
F_53 ( V_8 -> V_20 ) ;
F_54 ( & V_8 -> V_7 ) ;
F_37 ( V_8 ) ;
}
void F_55 ( struct V_29 * V_29 )
{
struct V_2 * V_5 , * V_61 ;
struct V_1 * V_8 ;
F_56 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_45 ( V_29 , V_8 ) ;
}
}
static int F_57 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
T_3 V_62 ;
unsigned long V_27 ;
V_20 -> V_48 = V_20 -> V_20 -> V_9 ;
if ( V_20 -> V_27 & V_31 ) {
V_62 = F_6 ;
V_27 = V_63 ;
} else {
V_62 = NULL ;
V_27 = V_64 ;
}
if ( F_58 ( V_20 -> V_48 , V_62 ,
F_13 , V_27 ,
V_20 -> V_65 , V_20 ) )
return - V_66 ;
if ( V_20 -> V_27 & V_31 ) {
F_14 ( & V_20 -> V_19 ) ;
F_39 ( V_20 -> V_20 , true ) ;
F_16 ( & V_20 -> V_19 ) ;
}
return 0 ;
}
static int F_59 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_67 ;
if ( ! V_20 -> V_20 -> V_68 ) {
V_67 = F_60 ( V_20 -> V_20 ) ;
if ( V_67 )
return V_67 ;
}
V_20 -> V_48 = V_20 -> V_20 -> V_9 ;
if ( F_58 ( V_20 -> V_48 , F_23 ,
F_24 , 0 ,
V_20 -> V_65 , V_20 ) ) {
F_41 ( V_20 -> V_20 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_61 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_10 , V_67 = - V_39 ;
if ( V_20 -> V_14 == 0 )
return V_67 ;
V_67 = F_62 ( V_20 -> V_20 ,
V_20 -> V_13 , V_20 -> V_14 ) ;
if ( V_67 )
return V_67 ;
for ( V_10 = 0 ; V_10 < V_20 -> V_14 ; V_10 ++ ) {
V_67 = F_58 ( V_20 -> V_13 [ V_10 ] . V_15 ,
F_25 ,
F_26 ,
0 , V_20 -> V_65 , V_20 ) ;
if ( V_67 )
goto V_69;
}
return 0 ;
V_69:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_36 ( V_20 -> V_13 [ V_10 ] . V_15 , V_20 ) ;
F_38 ( V_20 -> V_20 ) ;
return V_67 ;
}
static int F_63 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_70 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_46 . V_49 = V_9 -> V_32 ;
return 0 ;
}
static int F_64 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_70 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_46 . V_49 = - 1 ;
return 0 ;
}
static int F_65 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_70 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_46 . V_49 = - 1 ;
return 0 ;
}
static int F_66 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
T_4 V_56 )
{
int V_67 = - V_71 ;
if ( V_20 -> V_24 & V_54 )
return V_67 ;
snprintf ( V_20 -> V_65 , sizeof( V_20 -> V_65 ) , L_3 ,
F_67 ( V_20 -> V_20 ) ) ;
switch ( V_56 ) {
case V_52 :
V_67 = F_57 ( V_29 , V_20 ) ;
break;
case V_53 :
V_67 = F_59 ( V_29 , V_20 ) ;
break;
case V_51 :
V_67 = F_61 ( V_29 , V_20 ) ;
break;
default:
V_67 = - V_39 ;
}
V_20 -> V_21 = false ;
if ( ! V_67 )
V_20 -> V_24 |= V_56 ;
return V_67 ;
}
static int F_68 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_70 * V_9 ,
unsigned long V_55 )
{
int V_72 ;
int V_67 = - V_71 ;
if ( V_20 -> V_24 & V_50 )
return V_67 ;
V_72 = F_69 ( V_29 ) ;
if ( V_72 < 0 )
return V_72 ;
V_20 -> V_30 = V_72 ;
switch ( V_55 ) {
case V_25 :
V_67 = F_63 ( V_29 , V_20 , V_9 ) ;
break;
case V_73 :
V_67 = F_64 ( V_29 , V_20 , V_9 ) ;
break;
case V_74 :
V_67 = F_65 ( V_29 , V_20 , V_9 ) ;
break;
default:
V_67 = - V_39 ;
}
if ( ! V_67 ) {
V_20 -> V_24 |= V_55 ;
if ( V_20 -> V_46 . V_49 != - 1 )
F_70 ( V_29 , & V_20 -> V_46 ) ;
} else {
F_33 ( V_29 , V_20 -> V_30 ) ;
V_20 -> V_30 = - 1 ;
}
return V_67 ;
}
static int F_71 ( struct V_29 * V_29 ,
struct V_70 * V_75 )
{
int V_67 = - V_39 ;
struct V_1 * V_6 ;
unsigned long V_56 , V_55 ;
if ( ! F_43 ( V_29 ) )
return V_67 ;
F_72 ( & V_29 -> V_76 ) ;
V_67 = - V_77 ;
V_6 = F_1 ( & V_29 -> V_78 . V_79 ,
V_75 -> V_4 ) ;
if ( ! V_6 )
goto V_80;
V_56 = ( V_75 -> V_27 & V_54 ) ;
V_55 = ( V_75 -> V_27 & V_50 ) ;
V_67 = - V_39 ;
if ( F_73 ( V_56 ) > 1 )
goto V_80;
if ( F_73 ( V_55 ) > 1 )
goto V_80;
if ( V_56 == 0 && V_55 == 0 )
goto V_80;
V_67 = 0 ;
if ( V_56 )
V_67 = F_66 ( V_29 , V_6 , V_56 ) ;
if ( V_67 )
goto V_80;
if ( V_55 )
V_67 = F_68 ( V_29 , V_6 , V_75 , V_55 ) ;
V_80:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_75 ( struct V_29 * V_29 ,
struct V_70
* V_75 )
{
int V_67 = - V_77 ;
struct V_1 * V_6 ;
unsigned long V_81 ;
F_72 ( & V_29 -> V_76 ) ;
V_6 = F_1 ( & V_29 -> V_78 . V_79 ,
V_75 -> V_4 ) ;
if ( ! V_6 )
goto V_80;
V_81 = V_75 -> V_27 & ( V_54 |
V_50 ) ;
V_67 = F_42 ( V_29 , V_6 , V_81 ) ;
V_80:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_76 ( struct V_82 * V_20 )
{
#ifdef F_77
int V_10 ;
bool V_83 = false ;
for ( V_10 = V_84 ; V_10 <= V_85 ; V_10 ++ ) {
char * V_86 , * V_87 ;
struct V_88 V_88 ;
struct V_89 * V_89 ;
int V_67 ;
if ( ! F_78 ( V_20 , V_10 ) )
continue;
V_86 = F_79 ( & V_20 -> V_20 . V_90 , V_91 ) ;
if ( ! V_86 )
return - V_92 ;
V_87 = F_80 ( V_91 , L_4 , V_86 , V_10 ) ;
F_37 ( V_86 ) ;
if ( ! V_87 )
return - V_92 ;
V_67 = F_81 ( V_87 , V_93 , & V_88 ) ;
F_37 ( V_87 ) ;
if ( V_67 )
return V_67 ;
V_89 = F_82 ( V_88 . V_94 ) ;
V_67 = F_83 ( V_89 , V_95 | V_96 | V_97 ) ;
F_84 ( & V_88 ) ;
if ( V_67 )
return V_67 ;
V_83 = true ;
}
if ( ! V_83 )
return - V_98 ;
return 0 ;
#else
return - V_39 ;
#endif
}
static int F_85 ( struct V_29 * V_29 ,
struct V_99 * V_8 )
{
int V_67 = 0 , V_40 ;
struct V_1 * V_6 ;
struct V_82 * V_20 ;
if ( ! ( V_8 -> V_27 & V_100 ) )
return - V_39 ;
F_72 ( & V_29 -> V_76 ) ;
V_40 = F_19 ( & V_29 -> V_101 ) ;
V_6 = F_1 ( & V_29 -> V_78 . V_79 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_67 = - V_71 ;
goto V_80;
}
V_6 = F_86 ( sizeof( struct V_1 ) , V_91 ) ;
if ( V_6 == NULL ) {
F_5 ( V_59 L_5 ,
V_60 ) ;
V_67 = - V_92 ;
goto V_80;
}
V_20 = F_87 ( V_8 -> V_102 ,
V_8 -> V_103 ,
V_8 -> V_104 ) ;
if ( ! V_20 ) {
F_5 ( V_59 L_6 , V_60 ) ;
V_67 = - V_39 ;
goto V_105;
}
if ( V_20 -> V_106 != V_107 ) {
V_67 = - V_98 ;
goto V_108;
}
V_67 = F_76 ( V_20 ) ;
if ( V_67 )
goto V_108;
if ( F_88 ( V_20 ) ) {
F_5 ( V_59 L_7 , V_60 ) ;
V_67 = - V_109 ;
goto V_108;
}
V_67 = F_89 ( V_20 , L_8 ) ;
if ( V_67 ) {
F_5 ( V_59 L_9 ,
V_60 ) ;
goto V_110;
}
F_46 ( V_20 ) ;
F_90 ( V_20 ) ;
V_6 -> V_58 = F_91 ( V_20 ) ;
if ( ! V_6 -> V_58 )
F_5 ( V_111 L_10 ,
V_60 , F_48 ( & V_20 -> V_20 ) ) ;
if ( ! F_92 ( V_20 ) )
V_8 -> V_27 &= ~ V_31 ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_112 = V_8 -> V_102 ;
V_6 -> V_113 = V_8 -> V_103 ;
V_6 -> V_114 = V_8 -> V_104 ;
V_6 -> V_27 = V_8 -> V_27 ;
V_6 -> V_20 = V_20 ;
F_93 ( & V_6 -> V_19 ) ;
F_93 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = - 1 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_46 . V_115 = F_27 ;
F_94 ( & V_6 -> V_7 , & V_29 -> V_78 . V_79 ) ;
if ( ! V_29 -> V_78 . V_116 ) {
V_67 = F_95 ( V_29 ) ;
if ( V_67 )
goto V_117;
}
V_67 = F_96 ( V_29 , V_6 -> V_20 ) ;
if ( V_67 )
goto V_117;
V_80:
F_22 ( & V_29 -> V_101 , V_40 ) ;
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
V_117:
if ( F_47 ( V_20 , & V_6 -> V_58 ) )
F_5 ( V_59 L_2 ,
V_60 , F_48 ( & V_20 -> V_20 ) ) ;
F_54 ( & V_6 -> V_7 ) ;
F_51 ( V_20 ) ;
V_110:
F_52 ( V_20 ) ;
V_108:
F_53 ( V_20 ) ;
V_105:
F_37 ( V_6 ) ;
F_22 ( & V_29 -> V_101 , V_40 ) ;
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_97 ( struct V_29 * V_29 ,
struct V_99 * V_8 )
{
int V_67 = 0 ;
struct V_1 * V_6 ;
F_72 ( & V_29 -> V_76 ) ;
V_6 = F_1 ( & V_29 -> V_78 . V_79 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_59 L_11
L_12 , V_60 ) ;
V_67 = - V_39 ;
goto V_80;
}
F_98 ( V_29 , V_6 -> V_20 ) ;
F_45 ( V_29 , V_6 ) ;
V_80:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_99 ( struct V_29 * V_29 ,
struct V_118 * V_119 )
{
int V_67 = 0 ;
struct V_1 * V_120 ;
F_72 ( & V_29 -> V_76 ) ;
V_120 = F_1 ( & V_29 -> V_78 . V_79 ,
V_119 -> V_4 ) ;
if ( ! V_120 ) {
V_67 = - V_39 ;
goto V_121;
}
if ( V_120 -> V_14 == 0 ) {
V_120 -> V_14 = V_119 -> V_119 ;
if ( V_120 -> V_14 == 0 ||
V_120 -> V_14 > V_122 ) {
V_67 = - V_39 ;
goto V_121;
}
V_120 -> V_13 = F_86 ( sizeof( struct V_12 ) *
V_119 -> V_119 ,
V_91 ) ;
if ( ! V_120 -> V_13 ) {
V_67 = - V_92 ;
goto V_121;
}
V_120 -> V_43 =
F_86 ( sizeof( struct V_12 ) * V_119 -> V_119 ,
V_91 ) ;
if ( ! V_120 -> V_43 ) {
F_37 ( V_120 -> V_13 ) ;
V_67 = - V_92 ;
goto V_121;
}
} else
V_67 = - V_39 ;
V_121:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_100 ( struct V_29 * V_29 ,
struct V_123 * V_124 )
{
int V_67 = 0 , V_10 ;
struct V_1 * V_120 ;
F_72 ( & V_29 -> V_76 ) ;
V_120 = F_1 ( & V_29 -> V_78 . V_79 ,
V_124 -> V_4 ) ;
if ( ! V_120 ) {
V_67 = - V_39 ;
goto V_125;
}
for ( V_10 = 0 ; V_10 < V_120 -> V_14 ; V_10 ++ )
if ( V_120 -> V_43 [ V_10 ] . V_15 == 0 ||
V_120 -> V_43 [ V_10 ] . V_124 == V_124 -> V_124 ) {
V_120 -> V_43 [ V_10 ] . V_124 = V_124 -> V_124 ;
V_120 -> V_43 [ V_10 ] . V_15 = V_124 -> V_49 ;
V_120 -> V_13 [ V_10 ] . V_124 = V_124 -> V_124 ;
break;
}
if ( V_10 == V_120 -> V_14 ) {
V_67 = - V_126 ;
goto V_125;
}
V_125:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
static int F_101 ( struct V_29 * V_29 ,
struct V_99 * V_8 )
{
int V_67 = 0 ;
struct V_1 * V_6 ;
F_72 ( & V_29 -> V_76 ) ;
V_6 = F_1 ( & V_29 -> V_78 . V_79 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
V_67 = - V_77 ;
goto V_80;
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
F_29 ( V_6 -> V_48 ) ;
V_6 -> V_21 = false ;
}
F_16 ( & V_6 -> V_19 ) ;
}
}
F_9 ( & V_6 -> V_26 ) ;
V_80:
F_74 ( & V_29 -> V_76 ) ;
return V_67 ;
}
long F_102 ( struct V_29 * V_29 , unsigned V_127 ,
unsigned long V_128 )
{
void T_5 * V_129 = ( void T_5 * ) V_128 ;
int V_67 ;
switch ( V_127 ) {
case V_130 : {
struct V_99 V_8 ;
V_67 = - V_131 ;
if ( F_103 ( & V_8 , V_129 , sizeof V_8 ) )
goto V_80;
V_67 = F_85 ( V_29 , & V_8 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_132 : {
V_67 = - V_133 ;
break;
}
case V_134 : {
struct V_70 V_75 ;
V_67 = - V_131 ;
if ( F_103 ( & V_75 , V_129 , sizeof V_75 ) )
goto V_80;
V_67 = F_71 ( V_29 , & V_75 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_135 : {
struct V_70 V_75 ;
V_67 = - V_131 ;
if ( F_103 ( & V_75 , V_129 , sizeof V_75 ) )
goto V_80;
V_67 = F_75 ( V_29 , & V_75 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_136 : {
struct V_99 V_8 ;
V_67 = - V_131 ;
if ( F_103 ( & V_8 , V_129 , sizeof V_8 ) )
goto V_80;
V_67 = F_97 ( V_29 , & V_8 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_137 : {
struct V_118 V_119 ;
V_67 = - V_131 ;
if ( F_103 ( & V_119 , V_129 , sizeof V_119 ) )
goto V_80;
V_67 = F_99 ( V_29 , & V_119 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_138 : {
struct V_123 V_124 ;
V_67 = - V_131 ;
if ( F_103 ( & V_124 , V_129 , sizeof V_124 ) )
goto V_80;
V_67 = F_100 ( V_29 , & V_124 ) ;
if ( V_67 )
goto V_80;
break;
}
case V_139 : {
struct V_99 V_8 ;
V_67 = - V_131 ;
if ( F_103 ( & V_8 , V_129 , sizeof V_8 ) )
goto V_80;
V_67 = F_101 ( V_29 , & V_8 ) ;
break;
}
default:
V_67 = - V_140 ;
break;
}
V_80:
return V_67 ;
}
