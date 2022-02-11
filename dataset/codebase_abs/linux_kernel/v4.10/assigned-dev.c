static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_1 * V_5 ;
F_2 (match, head, list) {
if ( V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static int F_3 ( struct V_1
* V_6 , int V_7 )
{
int V_8 , V_9 ;
struct V_10 * V_11 ;
V_11 = V_6 -> V_11 ;
V_9 = - 1 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_12 ; V_8 ++ )
if ( V_7 == V_11 [ V_8 ] . V_13 ) {
V_9 = V_8 ;
break;
}
if ( V_9 < 0 )
F_4 ( V_14 L_1 ) ;
return V_9 ;
}
static T_1 F_5 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
int V_16 ;
F_6 ( & V_6 -> V_17 ) ;
if ( F_7 ( V_6 -> V_18 ) ) {
V_6 -> V_19 = true ;
V_16 = V_20 ;
} else
V_16 = V_21 ;
F_8 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static void
F_9 ( struct V_1 * V_6 ,
int V_13 )
{
if ( F_10 ( V_6 -> V_22 &
V_23 ) ) {
F_6 ( & V_6 -> V_24 ) ;
if ( ! ( V_6 -> V_25 & V_26 ) )
F_11 ( V_6 -> V_27 ,
V_6 -> V_28 , V_13 , 1 ,
false ) ;
F_8 ( & V_6 -> V_24 ) ;
} else
F_11 ( V_6 -> V_27 , V_6 -> V_28 ,
V_13 , 1 , false ) ;
}
static T_1 F_12 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
if ( ! ( V_6 -> V_25 & V_29 ) ) {
F_13 ( & V_6 -> V_17 ) ;
F_14 ( V_7 ) ;
V_6 -> V_19 = true ;
F_15 ( & V_6 -> V_17 ) ;
}
F_9 ( V_6 ,
V_6 -> V_30 ) ;
return V_31 ;
}
static int F_16 ( struct V_27 * V_27 , int V_28 , T_2 V_7 ,
int V_32 )
{
struct V_33 V_34 [ V_35 ] ;
struct V_33 * V_36 ;
int V_16 = - V_37 ;
int V_38 ;
F_17 ( V_7 , V_32 , V_28 ) ;
V_38 = F_18 ( & V_27 -> V_39 ) ;
if ( F_19 ( V_27 , V_34 , V_7 ) > 0 ) {
V_36 = & V_34 [ 0 ] ;
V_16 = F_20 ( V_36 , V_27 , V_28 ,
V_7 , V_32 ) ;
}
F_21 ( & V_27 -> V_39 , V_38 ) ;
return V_16 ;
}
static T_1 F_22 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
int V_16 = F_16 ( V_6 -> V_27 ,
V_6 -> V_28 ,
V_6 -> V_30 , 1 ) ;
return F_10 ( V_16 == - V_40 ) ? V_20 : V_31 ;
}
static T_1 F_23 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
F_9 ( V_6 ,
V_6 -> V_30 ) ;
return V_31 ;
}
static T_1 F_24 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
int V_9 = F_3 ( V_6 , V_7 ) ;
T_2 V_13 ;
int V_16 = 0 ;
if ( V_9 >= 0 ) {
V_13 = V_6 -> V_41 [ V_9 ] . V_13 ;
V_16 = F_16 ( V_6 -> V_27 ,
V_6 -> V_28 ,
V_13 , 1 ) ;
}
return F_10 ( V_16 == - V_40 ) ? V_20 : V_31 ;
}
static T_1 F_25 ( int V_7 , void * V_15 )
{
struct V_1 * V_6 = V_15 ;
int V_9 = F_3 ( V_6 , V_7 ) ;
T_2 V_13 ;
if ( V_9 >= 0 ) {
V_13 = V_6 -> V_41 [ V_9 ] . V_13 ;
F_9 ( V_6 , V_13 ) ;
}
return V_31 ;
}
static void F_26 ( struct V_42 * V_43 )
{
struct V_1 * V_18 =
F_27 ( V_43 , struct V_1 ,
V_44 ) ;
F_11 ( V_18 -> V_27 , V_18 -> V_28 , V_18 -> V_30 , 0 , false ) ;
F_6 ( & V_18 -> V_24 ) ;
if ( ! ( V_18 -> V_25 & V_26 ) ) {
bool V_45 = false ;
F_13 ( & V_18 -> V_17 ) ;
if ( V_18 -> V_19 ) {
if ( ! ( V_18 -> V_25 & V_29 ) )
F_28 ( V_18 -> V_46 ) ;
else if ( ! F_29 ( V_18 -> V_18 ) )
V_45 = true ;
V_18 -> V_19 = V_45 ;
}
F_15 ( & V_18 -> V_17 ) ;
if ( V_45 )
F_11 ( V_18 -> V_27 , V_18 -> V_28 ,
V_18 -> V_30 , 1 , false ) ;
}
F_8 ( & V_18 -> V_24 ) ;
}
static void F_30 ( struct V_27 * V_27 ,
struct V_1 * V_6 )
{
if ( V_6 -> V_44 . V_47 != - 1 )
F_31 ( V_27 ,
& V_6 -> V_44 ) ;
F_11 ( V_6 -> V_27 , V_6 -> V_28 ,
V_6 -> V_30 , 0 , false ) ;
if ( V_6 -> V_28 != - 1 )
F_32 ( V_27 , V_6 -> V_28 ) ;
V_6 -> V_28 = - 1 ;
V_6 -> V_22 &= ~ ( V_48 ) ;
}
static void F_33 ( struct V_27 * V_27 ,
struct V_1 * V_6 )
{
if ( V_6 -> V_22 & V_49 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_12 ; V_8 ++ )
F_34 ( V_6 -> V_11 [ V_8 ] . V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_12 ; V_8 ++ )
F_35 ( V_6 -> V_11 [ V_8 ] . V_13 ,
V_6 ) ;
V_6 -> V_12 = 0 ;
F_36 ( V_6 -> V_11 ) ;
F_36 ( V_6 -> V_41 ) ;
F_37 ( V_6 -> V_18 ) ;
} else {
if ( ( V_6 -> V_22 &
V_50 ) &&
( V_6 -> V_25 & V_29 ) ) {
F_13 ( & V_6 -> V_17 ) ;
F_38 ( V_6 -> V_18 , false ) ;
F_15 ( & V_6 -> V_17 ) ;
F_39 ( V_6 -> V_46 ) ;
} else
F_34 ( V_6 -> V_46 ) ;
F_35 ( V_6 -> V_46 , V_6 ) ;
if ( V_6 -> V_22 & V_51 )
F_40 ( V_6 -> V_18 ) ;
}
V_6 -> V_22 &= ~ ( V_52 ) ;
}
static int F_41 ( struct V_27 * V_27 ,
struct V_1 * V_6 ,
unsigned long V_22 )
{
unsigned long V_53 , V_54 ;
if ( ! F_42 ( V_27 ) )
return - V_37 ;
if ( ! V_6 -> V_22 )
return - V_55 ;
V_54 = V_22 & V_52 ;
V_53 = V_22 & V_48 ;
if ( V_54 )
F_33 ( V_27 , V_6 ) ;
if ( V_53 )
F_30 ( V_27 , V_6 ) ;
return 0 ;
}
static void F_43 ( struct V_27 * V_27 ,
struct V_1 * V_6 )
{
F_41 ( V_27 , V_6 , V_6 -> V_22 ) ;
}
static void F_44 ( struct V_27 * V_27 ,
struct V_1
* V_6 )
{
F_43 ( V_27 , V_6 ) ;
F_45 ( V_6 -> V_18 ) ;
if ( F_46 ( V_6 -> V_18 ,
& V_6 -> V_56 ) )
F_4 ( V_57 L_2 ,
V_58 , F_47 ( & V_6 -> V_18 -> V_18 ) ) ;
else
F_48 ( V_6 -> V_18 ) ;
F_49 ( V_6 -> V_18 ) ;
F_50 ( V_6 -> V_18 ) ;
F_51 ( V_6 -> V_18 ) ;
F_52 ( V_6 -> V_18 ) ;
F_53 ( & V_6 -> V_59 ) ;
F_36 ( V_6 ) ;
}
void F_54 ( struct V_27 * V_27 )
{
struct V_1 * V_6 , * V_60 ;
F_55 (assigned_dev, tmp,
&kvm->arch.assigned_dev_head, list) {
F_44 ( V_27 , V_6 ) ;
}
}
static int F_56 ( struct V_27 * V_27 ,
struct V_1 * V_18 )
{
T_3 V_61 ;
unsigned long V_25 ;
V_18 -> V_46 = V_18 -> V_18 -> V_7 ;
if ( V_18 -> V_25 & V_29 ) {
V_61 = F_5 ;
V_25 = V_62 ;
} else {
V_61 = NULL ;
V_25 = V_63 ;
}
if ( F_57 ( V_18 -> V_46 , V_61 ,
F_12 , V_25 ,
V_18 -> V_64 , V_18 ) )
return - V_65 ;
if ( V_18 -> V_25 & V_29 ) {
F_13 ( & V_18 -> V_17 ) ;
F_38 ( V_18 -> V_18 , true ) ;
F_15 ( & V_18 -> V_17 ) ;
}
return 0 ;
}
static int F_58 ( struct V_27 * V_27 ,
struct V_1 * V_18 )
{
int V_66 ;
if ( ! V_18 -> V_18 -> V_67 ) {
V_66 = F_59 ( V_18 -> V_18 ) ;
if ( V_66 )
return V_66 ;
}
V_18 -> V_46 = V_18 -> V_18 -> V_7 ;
if ( F_57 ( V_18 -> V_46 , F_22 ,
F_23 , 0 ,
V_18 -> V_64 , V_18 ) ) {
F_40 ( V_18 -> V_18 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_60 ( struct V_27 * V_27 ,
struct V_1 * V_18 )
{
int V_8 , V_66 = - V_37 ;
if ( V_18 -> V_12 == 0 )
return V_66 ;
V_66 = F_61 ( V_18 -> V_18 ,
V_18 -> V_11 , V_18 -> V_12 ) ;
if ( V_66 )
return V_66 ;
for ( V_8 = 0 ; V_8 < V_18 -> V_12 ; V_8 ++ ) {
V_66 = F_57 ( V_18 -> V_11 [ V_8 ] . V_13 ,
F_24 ,
F_25 ,
0 , V_18 -> V_64 , V_18 ) ;
if ( V_66 )
goto V_68;
}
return 0 ;
V_68:
for ( V_8 -= 1 ; V_8 >= 0 ; V_8 -- )
F_35 ( V_18 -> V_11 [ V_8 ] . V_13 , V_18 ) ;
F_37 ( V_18 -> V_18 ) ;
return V_66 ;
}
static int F_62 ( struct V_27 * V_27 ,
struct V_1 * V_18 ,
struct V_69 * V_7 )
{
V_18 -> V_30 = V_7 -> V_30 ;
V_18 -> V_44 . V_47 = V_7 -> V_30 ;
return 0 ;
}
static int F_63 ( struct V_27 * V_27 ,
struct V_1 * V_18 ,
struct V_69 * V_7 )
{
V_18 -> V_30 = V_7 -> V_30 ;
V_18 -> V_44 . V_47 = - 1 ;
return 0 ;
}
static int F_64 ( struct V_27 * V_27 ,
struct V_1 * V_18 ,
struct V_69 * V_7 )
{
V_18 -> V_30 = V_7 -> V_30 ;
V_18 -> V_44 . V_47 = - 1 ;
return 0 ;
}
static int F_65 ( struct V_27 * V_27 ,
struct V_1 * V_18 ,
T_4 V_54 )
{
int V_66 = - V_70 ;
if ( V_18 -> V_22 & V_52 )
return V_66 ;
snprintf ( V_18 -> V_64 , sizeof( V_18 -> V_64 ) , L_3 ,
F_66 ( V_18 -> V_18 ) ) ;
switch ( V_54 ) {
case V_50 :
V_66 = F_56 ( V_27 , V_18 ) ;
break;
case V_51 :
V_66 = F_58 ( V_27 , V_18 ) ;
break;
case V_49 :
V_66 = F_60 ( V_27 , V_18 ) ;
break;
default:
V_66 = - V_37 ;
}
V_18 -> V_19 = false ;
if ( ! V_66 )
V_18 -> V_22 |= V_54 ;
return V_66 ;
}
static int F_67 ( struct V_27 * V_27 ,
struct V_1 * V_18 ,
struct V_69 * V_7 ,
unsigned long V_53 )
{
int V_71 ;
int V_66 = - V_70 ;
if ( V_18 -> V_22 & V_48 )
return V_66 ;
V_71 = F_68 ( V_27 ) ;
if ( V_71 < 0 )
return V_71 ;
V_18 -> V_28 = V_71 ;
switch ( V_53 ) {
case V_23 :
V_66 = F_62 ( V_27 , V_18 , V_7 ) ;
break;
case V_72 :
V_66 = F_63 ( V_27 , V_18 , V_7 ) ;
break;
case V_73 :
V_66 = F_64 ( V_27 , V_18 , V_7 ) ;
break;
default:
V_66 = - V_37 ;
}
if ( ! V_66 ) {
V_18 -> V_22 |= V_53 ;
if ( V_18 -> V_44 . V_47 != - 1 )
F_69 ( V_27 , & V_18 -> V_44 ) ;
} else {
F_32 ( V_27 , V_18 -> V_28 ) ;
V_18 -> V_28 = - 1 ;
}
return V_66 ;
}
static int F_70 ( struct V_27 * V_27 ,
struct V_69 * V_74 )
{
int V_66 = - V_37 ;
struct V_1 * V_5 ;
unsigned long V_54 , V_53 ;
if ( ! F_42 ( V_27 ) )
return V_66 ;
F_71 ( & V_27 -> V_75 ) ;
V_66 = - V_76 ;
V_5 = F_1 ( & V_27 -> V_77 . V_78 ,
V_74 -> V_4 ) ;
if ( ! V_5 )
goto V_79;
V_54 = ( V_74 -> V_25 & V_52 ) ;
V_53 = ( V_74 -> V_25 & V_48 ) ;
V_66 = - V_37 ;
if ( F_72 ( V_54 ) > 1 )
goto V_79;
if ( F_72 ( V_53 ) > 1 )
goto V_79;
if ( V_54 == 0 && V_53 == 0 )
goto V_79;
V_66 = 0 ;
if ( V_54 )
V_66 = F_65 ( V_27 , V_5 , V_54 ) ;
if ( V_66 )
goto V_79;
if ( V_53 )
V_66 = F_67 ( V_27 , V_5 , V_74 , V_53 ) ;
V_79:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_74 ( struct V_27 * V_27 ,
struct V_69
* V_74 )
{
int V_66 = - V_76 ;
struct V_1 * V_5 ;
unsigned long V_80 ;
F_71 ( & V_27 -> V_75 ) ;
V_5 = F_1 ( & V_27 -> V_77 . V_78 ,
V_74 -> V_4 ) ;
if ( ! V_5 )
goto V_79;
V_80 = V_74 -> V_25 & ( V_52 |
V_48 ) ;
V_66 = F_41 ( V_27 , V_5 , V_80 ) ;
V_79:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_75 ( struct V_81 * V_18 )
{
#ifdef F_76
int V_8 ;
bool V_82 = false ;
for ( V_8 = V_83 ; V_8 <= V_84 ; V_8 ++ ) {
char * V_85 , * V_86 ;
struct V_87 V_87 ;
struct V_88 * V_88 ;
int V_66 ;
if ( ! F_77 ( V_18 , V_8 ) )
continue;
V_85 = F_78 ( & V_18 -> V_18 . V_89 , V_90 ) ;
if ( ! V_85 )
return - V_91 ;
V_86 = F_79 ( V_90 , L_4 , V_85 , V_8 ) ;
F_36 ( V_85 ) ;
if ( ! V_86 )
return - V_91 ;
V_66 = F_80 ( V_86 , V_92 , & V_87 ) ;
F_36 ( V_86 ) ;
if ( V_66 )
return V_66 ;
V_88 = F_81 ( V_87 . V_93 ) ;
V_66 = F_82 ( V_88 , V_94 | V_95 | V_96 ) ;
F_83 ( & V_87 ) ;
if ( V_66 )
return V_66 ;
V_82 = true ;
}
if ( ! V_82 )
return - V_97 ;
return 0 ;
#else
return - V_37 ;
#endif
}
static int F_84 ( struct V_27 * V_27 ,
struct V_98 * V_6 )
{
int V_66 = 0 , V_38 ;
struct V_1 * V_5 ;
struct V_81 * V_18 ;
if ( ! ( V_6 -> V_25 & V_99 ) )
return - V_37 ;
F_71 ( & V_27 -> V_75 ) ;
V_38 = F_18 ( & V_27 -> V_100 ) ;
V_5 = F_1 ( & V_27 -> V_77 . V_78 ,
V_6 -> V_4 ) ;
if ( V_5 ) {
V_66 = - V_70 ;
goto V_79;
}
V_5 = F_85 ( sizeof( struct V_1 ) , V_90 ) ;
if ( V_5 == NULL ) {
F_4 ( V_57 L_5 ,
V_58 ) ;
V_66 = - V_91 ;
goto V_79;
}
V_18 = F_86 ( V_6 -> V_101 ,
V_6 -> V_102 ,
V_6 -> V_103 ) ;
if ( ! V_18 ) {
F_4 ( V_57 L_6 , V_58 ) ;
V_66 = - V_37 ;
goto V_104;
}
if ( V_18 -> V_105 != V_106 ) {
V_66 = - V_97 ;
goto V_107;
}
V_66 = F_75 ( V_18 ) ;
if ( V_66 )
goto V_107;
if ( F_87 ( V_18 ) ) {
F_4 ( V_57 L_7 , V_58 ) ;
V_66 = - V_108 ;
goto V_107;
}
V_66 = F_88 ( V_18 , L_8 ) ;
if ( V_66 ) {
F_4 ( V_57 L_9 ,
V_58 ) ;
goto V_109;
}
F_45 ( V_18 ) ;
F_89 ( V_18 ) ;
V_5 -> V_56 = F_90 ( V_18 ) ;
if ( ! V_5 -> V_56 )
F_4 ( V_110 L_10 ,
V_58 , F_47 ( & V_18 -> V_18 ) ) ;
if ( ! F_91 ( V_18 ) )
V_6 -> V_25 &= ~ V_29 ;
V_5 -> V_4 = V_6 -> V_4 ;
V_5 -> V_111 = V_6 -> V_101 ;
V_5 -> V_112 = V_6 -> V_102 ;
V_5 -> V_113 = V_6 -> V_103 ;
V_5 -> V_25 = V_6 -> V_25 ;
V_5 -> V_18 = V_18 ;
F_92 ( & V_5 -> V_17 ) ;
F_92 ( & V_5 -> V_24 ) ;
V_5 -> V_28 = - 1 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_44 . V_114 = F_26 ;
F_93 ( & V_5 -> V_59 , & V_27 -> V_77 . V_78 ) ;
if ( ! V_27 -> V_77 . V_115 ) {
V_66 = F_94 ( V_27 ) ;
if ( V_66 )
goto V_116;
}
V_66 = F_95 ( V_27 , V_5 -> V_18 ) ;
if ( V_66 )
goto V_116;
V_79:
F_21 ( & V_27 -> V_100 , V_38 ) ;
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
V_116:
if ( F_46 ( V_18 , & V_5 -> V_56 ) )
F_4 ( V_57 L_2 ,
V_58 , F_47 ( & V_18 -> V_18 ) ) ;
F_53 ( & V_5 -> V_59 ) ;
F_50 ( V_18 ) ;
V_109:
F_51 ( V_18 ) ;
V_107:
F_52 ( V_18 ) ;
V_104:
F_36 ( V_5 ) ;
F_21 ( & V_27 -> V_100 , V_38 ) ;
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_96 ( struct V_27 * V_27 ,
struct V_98 * V_6 )
{
int V_66 = 0 ;
struct V_1 * V_5 ;
F_71 ( & V_27 -> V_75 ) ;
V_5 = F_1 ( & V_27 -> V_77 . V_78 ,
V_6 -> V_4 ) ;
if ( ! V_5 ) {
F_4 ( V_57 L_11
L_12 , V_58 ) ;
V_66 = - V_37 ;
goto V_79;
}
F_97 ( V_27 , V_5 -> V_18 ) ;
F_44 ( V_27 , V_5 ) ;
V_79:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_98 ( struct V_27 * V_27 ,
struct V_117 * V_118 )
{
int V_66 = 0 ;
struct V_1 * V_119 ;
F_71 ( & V_27 -> V_75 ) ;
V_119 = F_1 ( & V_27 -> V_77 . V_78 ,
V_118 -> V_4 ) ;
if ( ! V_119 ) {
V_66 = - V_37 ;
goto V_120;
}
if ( V_119 -> V_12 == 0 ) {
V_119 -> V_12 = V_118 -> V_118 ;
if ( V_119 -> V_12 == 0 ||
V_119 -> V_12 > V_121 ) {
V_66 = - V_37 ;
goto V_120;
}
V_119 -> V_11 = F_85 ( sizeof( struct V_10 ) *
V_118 -> V_118 ,
V_90 ) ;
if ( ! V_119 -> V_11 ) {
V_66 = - V_91 ;
goto V_120;
}
V_119 -> V_41 =
F_85 ( sizeof( struct V_10 ) * V_118 -> V_118 ,
V_90 ) ;
if ( ! V_119 -> V_41 ) {
F_36 ( V_119 -> V_11 ) ;
V_66 = - V_91 ;
goto V_120;
}
} else
V_66 = - V_37 ;
V_120:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_99 ( struct V_27 * V_27 ,
struct V_122 * V_123 )
{
int V_66 = 0 , V_8 ;
struct V_1 * V_119 ;
F_71 ( & V_27 -> V_75 ) ;
V_119 = F_1 ( & V_27 -> V_77 . V_78 ,
V_123 -> V_4 ) ;
if ( ! V_119 ) {
V_66 = - V_37 ;
goto V_124;
}
for ( V_8 = 0 ; V_8 < V_119 -> V_12 ; V_8 ++ )
if ( V_119 -> V_41 [ V_8 ] . V_13 == 0 ||
V_119 -> V_41 [ V_8 ] . V_123 == V_123 -> V_123 ) {
V_119 -> V_41 [ V_8 ] . V_123 = V_123 -> V_123 ;
V_119 -> V_41 [ V_8 ] . V_13 = V_123 -> V_47 ;
V_119 -> V_11 [ V_8 ] . V_123 = V_123 -> V_123 ;
break;
}
if ( V_8 == V_119 -> V_12 ) {
V_66 = - V_125 ;
goto V_124;
}
V_124:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
static int F_100 ( struct V_27 * V_27 ,
struct V_98 * V_6 )
{
int V_66 = 0 ;
struct V_1 * V_5 ;
F_71 ( & V_27 -> V_75 ) ;
V_5 = F_1 ( & V_27 -> V_77 . V_78 ,
V_6 -> V_4 ) ;
if ( ! V_5 ) {
V_66 = - V_76 ;
goto V_79;
}
F_6 ( & V_5 -> V_24 ) ;
V_5 -> V_25 &= ~ V_26 ;
V_5 -> V_25 |= V_6 -> V_25 & V_26 ;
if ( V_5 -> V_22 & V_23 ) {
if ( V_6 -> V_25 & V_26 ) {
F_11 ( V_5 -> V_27 , V_5 -> V_28 ,
V_5 -> V_30 , 0 , false ) ;
} else if ( ! ( V_6 -> V_25 & V_29 ) ) {
F_13 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_19 ) {
F_28 ( V_5 -> V_46 ) ;
V_5 -> V_19 = false ;
}
F_15 ( & V_5 -> V_17 ) ;
}
}
F_8 ( & V_5 -> V_24 ) ;
V_79:
F_73 ( & V_27 -> V_75 ) ;
return V_66 ;
}
long F_101 ( struct V_27 * V_27 , unsigned V_126 ,
unsigned long V_127 )
{
void T_5 * V_128 = ( void T_5 * ) V_127 ;
int V_66 ;
switch ( V_126 ) {
case V_129 : {
struct V_98 V_6 ;
V_66 = - V_130 ;
if ( F_102 ( & V_6 , V_128 , sizeof V_6 ) )
goto V_79;
V_66 = F_84 ( V_27 , & V_6 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_131 : {
V_66 = - V_132 ;
break;
}
case V_133 : {
struct V_69 V_74 ;
V_66 = - V_130 ;
if ( F_102 ( & V_74 , V_128 , sizeof V_74 ) )
goto V_79;
V_66 = F_70 ( V_27 , & V_74 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_134 : {
struct V_69 V_74 ;
V_66 = - V_130 ;
if ( F_102 ( & V_74 , V_128 , sizeof V_74 ) )
goto V_79;
V_66 = F_74 ( V_27 , & V_74 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_135 : {
struct V_98 V_6 ;
V_66 = - V_130 ;
if ( F_102 ( & V_6 , V_128 , sizeof V_6 ) )
goto V_79;
V_66 = F_96 ( V_27 , & V_6 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_136 : {
struct V_117 V_118 ;
V_66 = - V_130 ;
if ( F_102 ( & V_118 , V_128 , sizeof V_118 ) )
goto V_79;
V_66 = F_98 ( V_27 , & V_118 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_137 : {
struct V_122 V_123 ;
V_66 = - V_130 ;
if ( F_102 ( & V_123 , V_128 , sizeof V_123 ) )
goto V_79;
V_66 = F_99 ( V_27 , & V_123 ) ;
if ( V_66 )
goto V_79;
break;
}
case V_138 : {
struct V_98 V_6 ;
V_66 = - V_130 ;
if ( F_102 ( & V_6 , V_128 , sizeof V_6 ) )
goto V_79;
V_66 = F_100 ( V_27 , & V_6 ) ;
break;
}
default:
V_66 = - V_139 ;
break;
}
V_79:
return V_66 ;
}
