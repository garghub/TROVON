static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3
* V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 =
( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static int T_3 F_5 ( void )
{
return F_6 ( & V_5 ) ;
}
static void T_4 F_8 ( void )
{
F_10 ( & V_5 ) ;
}
static int
F_11 ( struct V_10 * V_2 , int V_11 , int V_12 ,
struct V_1 * * V_13 )
{
struct V_1 * V_1 = NULL ;
* V_13 = NULL ;
for ( V_1 = F_12 ( V_14 , V_15 , NULL ) ;
V_1 != NULL ;
V_1 = F_12 ( V_14 ,
V_15 , V_1 ) ) {
if ( V_11 || V_12 ) {
if ( V_11 != V_1 -> V_11 -> V_16
|| V_12 != F_13 ( V_1 -> V_17 ) )
continue;
}
if ( V_18 -> V_19 == V_20 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_23 != V_24 )
continue;
if ( V_1 -> V_25 == V_22 [ V_21 ] . V_26 ) {
V_2 -> V_27 = & V_22 [ V_21 ] ;
break;
}
}
if ( V_21 == F_14 ( V_22 ) )
continue;
} else {
if ( V_1 -> V_25 != V_18 -> V_26 )
continue;
}
* V_13 = V_1 ;
return 0 ;
}
if ( V_11 || V_12 ) {
F_15 ( V_28
L_1 ,
V_2 -> V_29 , V_18 -> V_9 , V_11 , V_12 ) ;
} else {
F_15 ( V_28 L_2 ,
V_2 -> V_29 , V_18 -> V_9 ) ;
}
return - V_30 ;
}
static int F_16 ( struct V_10 * V_2 , struct V_31 * V_32 )
{
struct V_33 * V_34 ;
unsigned long V_35 = 0 ;
unsigned int V_36 = 0 ;
#ifdef F_17
struct V_1 * V_1 = NULL ;
int V_11 = 0 , V_12 = 0 ;
#endif
int V_37 = 0 ;
int V_38 ;
F_15 ( V_39 L_3 , V_2 -> V_29 ,
V_40 ) ;
V_38 = F_18 ( V_2 , sizeof( struct V_41 ) ) ;
if ( V_38 < 0 ) {
F_15 ( V_28 L_4 ,
V_2 -> V_29 ) ;
return V_38 ;
}
switch ( V_18 -> V_23 ) {
case V_42 :
V_35 = V_32 -> V_43 [ 0 ] ;
V_36 = V_32 -> V_43 [ 1 ] ;
V_37 = 0 ;
break;
#ifdef F_17
case V_24 :
V_11 = V_32 -> V_43 [ 0 ] ;
V_12 = V_32 -> V_43 [ 1 ] ;
V_37 = 1 ;
V_38 = F_11 ( V_2 , V_11 , V_12 , & V_1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_44 -> V_1 = V_1 ;
break;
#endif
default:
F_15 ( V_28
L_5 ,
V_2 -> V_29 , V_40 ) ;
return - V_45 ;
break;
}
V_2 -> V_46 = V_18 -> V_9 ;
#ifdef F_17
if ( V_1 ) {
V_38 = F_19 ( V_1 , V_40 ) ;
if ( V_38 < 0 ) {
F_15 ( V_28
L_6 ,
V_2 -> V_29 ) ;
return V_38 ;
}
V_44 -> V_47 = F_20 ( V_1 , 1 ) ;
V_35 = F_20 ( V_1 , 2 ) ;
V_36 = V_1 -> V_36 ;
} else
#endif
{
V_38 = F_21 ( V_2 -> V_29 , V_35 , V_48 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_2 -> V_35 = V_35 ;
V_38 = F_22 ( V_2 , 2 ) ;
if ( V_38 < 0 ) {
F_15 ( V_28 L_4 ,
V_2 -> V_29 ) ;
return V_38 ;
}
V_34 = V_2 -> V_49 + 0 ;
V_38 = F_23 ( V_2 , V_34 , NULL , V_35 ) ;
if ( V_38 < 0 ) {
F_15 ( V_28 L_4 ,
V_2 -> V_29 ) ;
return V_38 ;
}
V_34 = V_2 -> V_49 + 1 ;
V_2 -> V_50 = V_34 ;
V_34 -> type = V_51 ;
F_24 ( V_2 ) ;
if ( V_36 ) {
unsigned long V_52 = V_37 ? V_53 : 0 ;
if ( F_25 ( V_36 , V_54 , V_52 ,
V_40 , V_2 ) >= 0 ) {
V_2 -> V_36 = V_36 ;
V_34 -> type = V_55 ;
V_34 -> V_56 = V_57 | V_58 ;
V_34 -> V_59 = 1 ;
V_34 -> V_60 = 1 ;
V_34 -> V_61 = & V_62 ;
V_34 -> V_63 = V_64 ;
V_34 -> V_65 = V_66 ;
V_34 -> V_67 = V_68 ;
V_34 -> V_69 = V_70 ;
}
}
F_15 ( V_71 L_7 , V_2 -> V_29 , V_2 -> V_46 ) ;
if ( V_18 -> V_23 == V_42 ) {
F_15 ( L_8 , V_35 ) ;
} else {
#ifdef F_17
F_15 ( L_9 , F_26 ( V_1 ) ) ;
#endif
}
if ( V_36 )
F_15 ( L_10 , V_36 , ( V_2 -> V_36 ? L_11 : L_12 ) ) ;
else
F_15 ( L_13 ) ;
F_15 ( L_14 ) ;
return 1 ;
}
static int F_27 ( struct V_10 * V_2 )
{
F_15 ( V_39 L_15 , V_2 -> V_29 ,
V_40 ) ;
if ( V_44 )
F_24 ( V_2 ) ;
if ( V_2 -> V_36 )
F_28 ( V_2 -> V_36 , V_2 ) ;
if ( V_2 -> V_49 )
F_29 ( V_2 , V_2 -> V_49 + 0 ) ;
if ( V_44 ) {
#ifdef F_17
if ( V_44 -> V_1 ) {
if ( V_2 -> V_35 )
F_30 ( V_44 -> V_1 ) ;
F_31 ( V_44 -> V_1 ) ;
} else
#endif
{
if ( V_2 -> V_35 )
F_32 ( V_2 -> V_35 , V_48 ) ;
}
}
if ( V_2 -> V_46 ) {
F_15 ( V_71 L_16 ,
V_2 -> V_29 , V_2 -> V_46 ) ;
}
return 0 ;
}
static int F_21 ( unsigned V_29 , unsigned long V_72 ,
unsigned long V_73 )
{
if ( ! V_72 || ! F_33 ( V_72 , V_73 , V_40 ) ) {
F_15 ( V_28 L_17 ,
V_29 , V_72 , V_73 ) ;
return - V_30 ;
}
return 0 ;
}
static void F_24 ( struct V_10 * V_2 )
{
unsigned long V_52 ;
F_34 ( & V_2 -> V_74 , V_52 ) ;
V_44 -> V_75 = 0 ;
#ifdef F_17
if ( V_44 -> V_47 )
F_35 ( V_76 , V_44 -> V_47 + V_77 ) ;
#endif
F_36 ( & V_2 -> V_74 , V_52 ) ;
}
static void F_37 ( struct V_10 * V_2 )
{
unsigned long V_52 ;
F_34 ( & V_2 -> V_74 , V_52 ) ;
V_44 -> V_75 = 1 ;
#ifdef F_17
if ( V_44 -> V_47 )
F_35 ( V_78 , V_44 -> V_47 + V_77 ) ;
#endif
F_36 ( & V_2 -> V_74 , V_52 ) ;
}
static int F_38 ( struct V_10 * V_2 )
{
int V_7 = 0 ;
unsigned long V_52 ;
F_34 ( & V_2 -> V_74 , V_52 ) ;
if ( V_44 -> V_75 ) {
V_7 = 1 ;
#ifdef F_17
if ( V_44 -> V_47 ) {
if ( ( F_39 ( V_44 -> V_47 + V_77 )
& V_79 )
== V_80 ) {
V_7 = 0 ;
} else {
F_35 ( V_78 ,
V_44 -> V_47 + V_77 ) ;
}
}
#endif
}
F_36 ( & V_2 -> V_74 , V_52 ) ;
return V_7 ;
}
static int V_64 ( struct V_10 * V_2 ,
struct V_33 * V_34 , struct V_81 * V_82 ,
unsigned int * V_83 )
{
V_83 [ 1 ] = 0 ;
return 2 ;
}
static int V_66 ( struct V_10 * V_2 ,
struct V_33 * V_34 ,
struct V_84 * V_85 )
{
int V_86 = 0 ;
int V_87 ;
V_87 = V_85 -> V_88 ;
V_85 -> V_88 &= V_89 ;
if ( ! V_85 -> V_88 || V_87 != V_85 -> V_88 )
V_86 ++ ;
V_87 = V_85 -> V_90 ;
V_85 -> V_90 &= V_91 ;
if ( ! V_85 -> V_90 || V_87 != V_85 -> V_90 )
V_86 ++ ;
V_87 = V_85 -> V_92 ;
V_85 -> V_92 &= V_93 ;
if ( ! V_85 -> V_92 || V_87 != V_85 -> V_92 )
V_86 ++ ;
V_87 = V_85 -> V_94 ;
V_85 -> V_94 &= V_95 ;
if ( ! V_85 -> V_94 || V_87 != V_85 -> V_94 )
V_86 ++ ;
V_87 = V_85 -> V_96 ;
V_85 -> V_96 &= V_97 ;
if ( ! V_85 -> V_96 || V_87 != V_85 -> V_96 )
V_86 ++ ;
if ( V_86 )
return 1 ;
if ( V_86 )
return 2 ;
if ( V_85 -> V_98 != 0 ) {
V_85 -> V_98 = 0 ;
V_86 ++ ;
}
if ( V_85 -> V_99 != 0 ) {
V_85 -> V_99 = 0 ;
V_86 ++ ;
}
if ( V_85 -> V_100 != 0 ) {
V_85 -> V_100 = 0 ;
V_86 ++ ;
}
if ( V_85 -> V_101 != 1 ) {
V_85 -> V_101 = 1 ;
V_86 ++ ;
}
if ( V_85 -> V_102 != 0 ) {
V_85 -> V_102 = 0 ;
V_86 ++ ;
}
if ( V_86 )
return 3 ;
if ( V_86 )
return 4 ;
return 0 ;
}
static int V_68 ( struct V_10 * V_2 , struct V_33 * V_34 )
{
F_37 ( V_2 ) ;
return 0 ;
}
static int V_70 ( struct V_10 * V_2 ,
struct V_33 * V_34 )
{
F_24 ( V_2 ) ;
return 0 ;
}
static T_5 V_54 ( int V_36 , void * V_103 )
{
struct V_10 * V_2 = V_103 ;
struct V_33 * V_34 = V_2 -> V_49 + 1 ;
int V_104 ;
V_104 = F_38 ( V_2 ) ;
if ( V_2 -> V_105 && V_104 ) {
F_40 ( V_34 -> V_106 , 0 ) ;
V_34 -> V_106 -> V_107 |= V_108 | V_109 ;
F_41 ( V_2 , V_34 ) ;
}
return F_42 ( V_104 ) ;
}
