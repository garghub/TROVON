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
F_45 ( V_8 -> V_20 ) ;
F_46 ( V_8 -> V_20 ) ;
F_47 ( V_8 -> V_20 ) ;
F_48 ( V_8 -> V_20 ) ;
F_49 ( & V_8 -> V_7 ) ;
F_32 ( V_8 ) ;
}
void F_50 ( struct V_29 * V_29 )
{
struct V_2 * V_5 , * V_54 ;
struct V_1 * V_8 ;
F_51 (ptr, ptr2, &kvm->arch.assigned_dev_head) {
V_8 = F_3 ( V_5 ,
struct V_1 ,
V_7 ) ;
F_40 ( V_29 , V_8 ) ;
}
}
static int F_52 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
T_3 V_55 ;
unsigned long V_27 ;
V_20 -> V_40 = V_20 -> V_20 -> V_9 ;
if ( V_20 -> V_27 & V_31 ) {
V_55 = F_6 ;
V_27 = V_56 ;
} else {
V_55 = NULL ;
V_27 = V_57 ;
}
if ( F_53 ( V_20 -> V_40 , V_55 ,
F_13 , V_27 ,
V_20 -> V_58 , V_20 ) )
return - V_59 ;
if ( V_20 -> V_27 & V_31 ) {
F_14 ( & V_20 -> V_19 ) ;
F_34 ( V_20 -> V_20 , true ) ;
F_16 ( & V_20 -> V_19 ) ;
}
return 0 ;
}
static int F_54 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_60 ;
if ( ! V_20 -> V_20 -> V_61 ) {
V_60 = F_55 ( V_20 -> V_20 ) ;
if ( V_60 )
return V_60 ;
}
V_20 -> V_40 = V_20 -> V_20 -> V_9 ;
if ( F_53 ( V_20 -> V_40 , F_17 ,
F_19 , 0 ,
V_20 -> V_58 , V_20 ) ) {
F_36 ( V_20 -> V_20 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_56 ( struct V_29 * V_29 ,
struct V_1 * V_20 )
{
int V_10 , V_60 = - V_49 ;
if ( V_20 -> V_14 == 0 )
return V_60 ;
V_60 = F_57 ( V_20 -> V_20 ,
V_20 -> V_13 , V_20 -> V_14 ) ;
if ( V_60 )
return V_60 ;
for ( V_10 = 0 ; V_10 < V_20 -> V_14 ; V_10 ++ ) {
V_60 = F_53 ( V_20 -> V_13 [ V_10 ] . V_15 ,
F_20 ,
F_21 ,
0 , V_20 -> V_58 , V_20 ) ;
if ( V_60 )
goto V_62;
}
return 0 ;
V_62:
for ( V_10 -= 1 ; V_10 >= 0 ; V_10 -- )
F_31 ( V_20 -> V_13 [ V_10 ] . V_15 , V_20 ) ;
F_33 ( V_20 -> V_20 ) ;
return V_60 ;
}
static int F_58 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_63 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = V_9 -> V_32 ;
return 0 ;
}
static int F_59 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_63 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = - 1 ;
return 0 ;
}
static int F_60 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_63 * V_9 )
{
V_20 -> V_32 = V_9 -> V_32 ;
V_20 -> V_38 . V_41 = - 1 ;
return 0 ;
}
static int F_61 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
T_4 V_48 )
{
int V_60 = - V_64 ;
if ( V_20 -> V_24 & V_46 )
return V_60 ;
snprintf ( V_20 -> V_58 , sizeof( V_20 -> V_58 ) , L_3 ,
F_62 ( V_20 -> V_20 ) ) ;
switch ( V_48 ) {
case V_44 :
V_60 = F_52 ( V_29 , V_20 ) ;
break;
#ifdef F_63
case V_45 :
V_60 = F_54 ( V_29 , V_20 ) ;
break;
#endif
#ifdef F_64
case V_43 :
V_60 = F_56 ( V_29 , V_20 ) ;
break;
#endif
default:
V_60 = - V_49 ;
}
V_20 -> V_21 = false ;
if ( ! V_60 )
V_20 -> V_24 |= V_48 ;
return V_60 ;
}
static int F_65 ( struct V_29 * V_29 ,
struct V_1 * V_20 ,
struct V_63 * V_9 ,
unsigned long V_47 )
{
int V_65 ;
int V_60 = - V_64 ;
if ( V_20 -> V_24 & V_42 )
return V_60 ;
V_65 = F_66 ( V_29 ) ;
if ( V_65 < 0 )
return V_65 ;
V_20 -> V_30 = V_65 ;
switch ( V_47 ) {
case V_25 :
V_60 = F_58 ( V_29 , V_20 , V_9 ) ;
break;
#ifdef F_63
case V_66 :
V_60 = F_59 ( V_29 , V_20 , V_9 ) ;
break;
#endif
#ifdef F_64
case V_67 :
V_60 = F_60 ( V_29 , V_20 , V_9 ) ;
break;
#endif
default:
V_60 = - V_49 ;
}
if ( ! V_60 ) {
V_20 -> V_24 |= V_47 ;
if ( V_20 -> V_38 . V_41 != - 1 )
F_67 ( V_29 , & V_20 -> V_38 ) ;
} else {
F_28 ( V_29 , V_20 -> V_30 ) ;
V_20 -> V_30 = - 1 ;
}
return V_60 ;
}
static int F_68 ( struct V_29 * V_29 ,
struct V_63 * V_68 )
{
int V_60 = - V_49 ;
struct V_1 * V_6 ;
unsigned long V_48 , V_47 ;
if ( ! F_38 ( V_29 ) )
return V_60 ;
F_69 ( & V_29 -> V_69 ) ;
V_60 = - V_70 ;
V_6 = F_1 ( & V_29 -> V_71 . V_72 ,
V_68 -> V_4 ) ;
if ( ! V_6 )
goto V_73;
V_48 = ( V_68 -> V_27 & V_46 ) ;
V_47 = ( V_68 -> V_27 & V_42 ) ;
V_60 = - V_49 ;
if ( F_70 ( V_48 ) > 1 )
goto V_73;
if ( F_70 ( V_47 ) > 1 )
goto V_73;
if ( V_48 == 0 && V_47 == 0 )
goto V_73;
V_60 = 0 ;
if ( V_48 )
V_60 = F_61 ( V_29 , V_6 , V_48 ) ;
if ( V_60 )
goto V_73;
if ( V_47 )
V_60 = F_65 ( V_29 , V_6 , V_68 , V_47 ) ;
V_73:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_72 ( struct V_29 * V_29 ,
struct V_63
* V_68 )
{
int V_60 = - V_70 ;
struct V_1 * V_6 ;
unsigned long V_74 ;
F_69 ( & V_29 -> V_69 ) ;
V_6 = F_1 ( & V_29 -> V_71 . V_72 ,
V_68 -> V_4 ) ;
if ( ! V_6 )
goto V_73;
V_74 = V_68 -> V_27 & ( V_46 |
V_42 ) ;
V_60 = F_37 ( V_29 , V_6 , V_74 ) ;
V_73:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_73 ( struct V_75 * V_20 )
{
#ifdef F_74
int V_10 ;
bool V_76 = false ;
for ( V_10 = V_77 ; V_10 <= V_78 ; V_10 ++ ) {
char * V_79 , * V_80 ;
struct V_81 V_81 ;
struct V_82 * V_82 ;
int V_60 ;
if ( ! F_75 ( V_20 , V_10 ) )
continue;
V_79 = F_76 ( & V_20 -> V_20 . V_83 , V_84 ) ;
if ( ! V_79 )
return - V_85 ;
V_80 = F_77 ( V_84 , L_4 , V_79 , V_10 ) ;
F_32 ( V_79 ) ;
if ( ! V_80 )
return - V_85 ;
V_60 = F_78 ( V_80 , V_86 , & V_81 ) ;
F_32 ( V_80 ) ;
if ( V_60 )
return V_60 ;
V_82 = V_81 . V_87 -> V_88 ;
V_60 = F_79 ( V_82 , V_89 | V_90 | V_91 ) ;
F_80 ( & V_81 ) ;
if ( V_60 )
return V_60 ;
V_76 = true ;
}
if ( ! V_76 )
return - V_92 ;
return 0 ;
#else
return - V_49 ;
#endif
}
static int F_81 ( struct V_29 * V_29 ,
struct V_93 * V_8 )
{
int V_60 = 0 , V_94 ;
struct V_1 * V_6 ;
struct V_75 * V_20 ;
if ( ! ( V_8 -> V_27 & V_95 ) )
return - V_49 ;
F_69 ( & V_29 -> V_69 ) ;
V_94 = F_82 ( & V_29 -> V_96 ) ;
V_6 = F_1 ( & V_29 -> V_71 . V_72 ,
V_8 -> V_4 ) ;
if ( V_6 ) {
V_60 = - V_64 ;
goto V_73;
}
V_6 = F_83 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_6 == NULL ) {
F_5 ( V_52 L_5 ,
V_53 ) ;
V_60 = - V_85 ;
goto V_73;
}
V_20 = F_84 ( V_8 -> V_97 ,
V_8 -> V_98 ,
V_8 -> V_99 ) ;
if ( ! V_20 ) {
F_5 ( V_52 L_6 , V_53 ) ;
V_60 = - V_49 ;
goto V_100;
}
if ( V_20 -> V_101 != V_102 ) {
V_60 = - V_92 ;
goto V_103;
}
V_60 = F_73 ( V_20 ) ;
if ( V_60 )
goto V_103;
if ( F_85 ( V_20 ) ) {
F_5 ( V_52 L_7 , V_53 ) ;
V_60 = - V_104 ;
goto V_103;
}
V_60 = F_86 ( V_20 , L_8 ) ;
if ( V_60 ) {
F_5 ( V_52 L_9 ,
V_53 ) ;
goto V_105;
}
F_41 ( V_20 ) ;
F_87 ( V_20 ) ;
V_6 -> V_51 = F_88 ( V_20 ) ;
if ( ! V_6 -> V_51 )
F_5 ( V_106 L_10 ,
V_53 , F_43 ( & V_20 -> V_20 ) ) ;
if ( ! F_89 ( V_20 ) )
V_8 -> V_27 &= ~ V_31 ;
V_6 -> V_4 = V_8 -> V_4 ;
V_6 -> V_107 = V_8 -> V_97 ;
V_6 -> V_108 = V_8 -> V_98 ;
V_6 -> V_109 = V_8 -> V_99 ;
V_6 -> V_27 = V_8 -> V_27 ;
V_6 -> V_20 = V_20 ;
F_90 ( & V_6 -> V_19 ) ;
F_90 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = - 1 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_38 . V_110 = F_22 ;
F_91 ( & V_6 -> V_7 , & V_29 -> V_71 . V_72 ) ;
if ( ! V_29 -> V_71 . V_111 ) {
V_60 = F_92 ( V_29 ) ;
if ( V_60 )
goto V_112;
}
V_60 = F_93 ( V_29 , V_6 ) ;
if ( V_60 )
goto V_112;
V_73:
F_94 ( & V_29 -> V_96 , V_94 ) ;
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
V_112:
if ( F_42 ( V_20 , & V_6 -> V_51 ) )
F_5 ( V_52 L_2 ,
V_53 , F_43 ( & V_20 -> V_20 ) ) ;
F_49 ( & V_6 -> V_7 ) ;
F_46 ( V_20 ) ;
V_105:
F_47 ( V_20 ) ;
V_103:
F_48 ( V_20 ) ;
V_100:
F_32 ( V_6 ) ;
F_94 ( & V_29 -> V_96 , V_94 ) ;
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_95 ( struct V_29 * V_29 ,
struct V_93 * V_8 )
{
int V_60 = 0 ;
struct V_1 * V_6 ;
F_69 ( & V_29 -> V_69 ) ;
V_6 = F_1 ( & V_29 -> V_71 . V_72 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
F_5 ( V_52 L_11
L_12 , V_53 ) ;
V_60 = - V_49 ;
goto V_73;
}
F_96 ( V_29 , V_6 ) ;
F_40 ( V_29 , V_6 ) ;
V_73:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_97 ( struct V_29 * V_29 ,
struct V_113 * V_114 )
{
int V_60 = 0 ;
struct V_1 * V_115 ;
F_69 ( & V_29 -> V_69 ) ;
V_115 = F_1 ( & V_29 -> V_71 . V_72 ,
V_114 -> V_4 ) ;
if ( ! V_115 ) {
V_60 = - V_49 ;
goto V_116;
}
if ( V_115 -> V_14 == 0 ) {
V_115 -> V_14 = V_114 -> V_114 ;
if ( V_115 -> V_14 == 0 ||
V_115 -> V_14 > V_117 ) {
V_60 = - V_49 ;
goto V_116;
}
V_115 -> V_13 = F_83 ( sizeof( struct V_12 ) *
V_114 -> V_114 ,
V_84 ) ;
if ( ! V_115 -> V_13 ) {
V_60 = - V_85 ;
goto V_116;
}
V_115 -> V_35 =
F_83 ( sizeof( struct V_12 ) * V_114 -> V_114 ,
V_84 ) ;
if ( ! V_115 -> V_35 ) {
F_32 ( V_115 -> V_13 ) ;
V_60 = - V_85 ;
goto V_116;
}
} else
V_60 = - V_49 ;
V_116:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_98 ( struct V_29 * V_29 ,
struct V_118 * V_119 )
{
int V_60 = 0 , V_10 ;
struct V_1 * V_115 ;
F_69 ( & V_29 -> V_69 ) ;
V_115 = F_1 ( & V_29 -> V_71 . V_72 ,
V_119 -> V_4 ) ;
if ( ! V_115 ) {
V_60 = - V_49 ;
goto V_120;
}
for ( V_10 = 0 ; V_10 < V_115 -> V_14 ; V_10 ++ )
if ( V_115 -> V_35 [ V_10 ] . V_15 == 0 ||
V_115 -> V_35 [ V_10 ] . V_119 == V_119 -> V_119 ) {
V_115 -> V_35 [ V_10 ] . V_119 = V_119 -> V_119 ;
V_115 -> V_35 [ V_10 ] . V_15 = V_119 -> V_41 ;
V_115 -> V_13 [ V_10 ] . V_119 = V_119 -> V_119 ;
break;
}
if ( V_10 == V_115 -> V_14 ) {
V_60 = - V_121 ;
goto V_120;
}
V_120:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
static int F_99 ( struct V_29 * V_29 ,
struct V_93 * V_8 )
{
int V_60 = 0 ;
struct V_1 * V_6 ;
F_69 ( & V_29 -> V_69 ) ;
V_6 = F_1 ( & V_29 -> V_71 . V_72 ,
V_8 -> V_4 ) ;
if ( ! V_6 ) {
V_60 = - V_70 ;
goto V_73;
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
V_73:
F_71 ( & V_29 -> V_69 ) ;
return V_60 ;
}
long F_100 ( struct V_29 * V_29 , unsigned V_122 ,
unsigned long V_123 )
{
void T_5 * V_124 = ( void T_5 * ) V_123 ;
int V_60 ;
switch ( V_122 ) {
case V_125 : {
struct V_93 V_8 ;
V_60 = - V_126 ;
if ( F_101 ( & V_8 , V_124 , sizeof V_8 ) )
goto V_73;
V_60 = F_81 ( V_29 , & V_8 ) ;
if ( V_60 )
goto V_73;
break;
}
case V_127 : {
V_60 = - V_128 ;
break;
}
case V_129 : {
struct V_63 V_68 ;
V_60 = - V_126 ;
if ( F_101 ( & V_68 , V_124 , sizeof V_68 ) )
goto V_73;
V_60 = F_68 ( V_29 , & V_68 ) ;
if ( V_60 )
goto V_73;
break;
}
case V_130 : {
struct V_63 V_68 ;
V_60 = - V_126 ;
if ( F_101 ( & V_68 , V_124 , sizeof V_68 ) )
goto V_73;
V_60 = F_72 ( V_29 , & V_68 ) ;
if ( V_60 )
goto V_73;
break;
}
case V_131 : {
struct V_93 V_8 ;
V_60 = - V_126 ;
if ( F_101 ( & V_8 , V_124 , sizeof V_8 ) )
goto V_73;
V_60 = F_95 ( V_29 , & V_8 ) ;
if ( V_60 )
goto V_73;
break;
}
#ifdef F_64
case V_132 : {
struct V_113 V_114 ;
V_60 = - V_126 ;
if ( F_101 ( & V_114 , V_124 , sizeof V_114 ) )
goto V_73;
V_60 = F_97 ( V_29 , & V_114 ) ;
if ( V_60 )
goto V_73;
break;
}
case V_133 : {
struct V_118 V_119 ;
V_60 = - V_126 ;
if ( F_101 ( & V_119 , V_124 , sizeof V_119 ) )
goto V_73;
V_60 = F_98 ( V_29 , & V_119 ) ;
if ( V_60 )
goto V_73;
break;
}
#endif
case V_134 : {
struct V_93 V_8 ;
V_60 = - V_126 ;
if ( F_101 ( & V_8 , V_124 , sizeof V_8 ) )
goto V_73;
V_60 = F_99 ( V_29 , & V_8 ) ;
break;
}
default:
V_60 = - V_135 ;
break;
}
V_73:
return V_60 ;
}
