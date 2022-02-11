static bool F_1 ( unsigned int V_1 , T_1 V_2 )
{
if ( V_1 == 4 )
return true ;
return V_2 & F_2 ( 28 ) ;
}
static int F_3 ( struct V_3 * V_4 , int V_5 , T_1 V_6 , T_1 V_7 )
{
int V_8 = ( V_7 & V_9 ) >> 20 ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_1
L_2 , V_4 -> V_11 ,
V_4 -> V_1 , V_4 -> V_12 , V_4 -> V_13 , V_7 , V_6 ) ;
return 0 ;
}
if ( V_5 != V_8 ) {
F_4 ( V_10 L_3
L_2 ,
V_4 -> V_11 , V_5 , V_4 -> V_1 , V_4 -> V_12 , V_4 -> V_13 , V_7 , V_6 ) ;
return 0 ;
}
return 1 ;
}
static void F_5 ( void * V_14 )
{
struct V_15 * V_16 = V_14 ;
T_1 V_7 , V_6 ;
F_6 ( V_16 -> V_4 -> V_13 , V_6 , V_7 ) ;
if ( V_16 -> V_4 -> V_17 < ( V_7 & V_18 ) )
V_16 -> V_19 = 1 ;
if ( V_16 -> V_19 ) {
V_7 =
( V_7 & ~ ( V_20 | V_21 ) ) |
( V_18 - V_16 -> V_4 -> V_17 ) ;
} else if ( V_16 -> V_22 ) {
int V_23 = ( V_7 & V_18 ) +
( V_16 -> V_22 - V_16 -> V_4 -> V_17 ) ;
V_7 = ( V_7 & ~ V_20 ) |
( V_23 & V_18 ) ;
}
V_7 &= ~ V_24 ;
if ( ! V_16 -> V_4 -> V_25 )
goto V_26;
if ( V_16 -> V_27 ) {
if ( F_3 ( V_16 -> V_4 , V_16 -> V_28 , V_6 , V_7 ) ) {
V_7 &= ~ V_9 ;
V_7 |= V_16 -> V_28 << 20 ;
}
}
if ( V_16 -> V_4 -> V_29 )
V_7 |= V_30 ;
V_26:
V_7 |= V_31 ;
F_7 ( V_16 -> V_4 -> V_13 , V_6 , V_7 ) ;
}
static void F_8 ( struct V_3 * V_4 , int V_32 )
{
struct V_15 V_16 = {
. V_4 = V_4 ,
. V_27 = 1 ,
. V_28 = V_32 ,
} ;
V_4 -> V_17 = V_18 ;
F_5 ( & V_16 ) ;
}
static int F_9 ( int V_33 , int V_34 )
{
if ( V_33 < 0 && ! F_10 ( V_34 , V_35 ,
V_36 , 0 ) )
return V_34 ;
return V_33 ;
}
void F_11 ( struct V_37 * V_38 )
{
struct V_3 V_4 ;
unsigned int V_11 = F_12 () ;
T_1 V_39 = 0 , V_40 = 0 , V_13 = 0 ;
unsigned int V_1 , V_12 ;
int V_32 = - 1 ;
for ( V_1 = 0 ; V_1 < V_41 ; ++ V_1 ) {
for ( V_12 = 0 ; V_12 < V_42 ; ++ V_12 ) {
if ( V_12 == 0 )
V_13 = V_43 + V_1 * 4 ;
else if ( V_12 == 1 ) {
V_13 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_13 )
break;
V_13 += V_45 ;
} else
++ V_13 ;
if ( F_13 ( V_13 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) )
continue;
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
if ( ! V_12 )
F_14 ( V_49 , V_11 ) |= ( 1 << V_1 ) ;
if ( V_50 [ V_1 ] && V_38 -> V_51 )
break;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_11 = V_11 ;
V_4 . V_1 = V_1 ;
V_4 . V_12 = V_12 ;
V_4 . V_13 = V_13 ;
V_4 . V_25 = F_1 ( V_1 , V_40 ) ;
if ( V_4 . V_25 ) {
int V_34 = ( V_40 & V_9 ) >> 20 ;
V_32 = F_9 ( V_32 , V_34 ) ;
}
F_8 ( & V_4 , V_32 ) ;
V_52 = V_53 ;
}
}
}
static void V_53 ( void )
{
T_1 V_39 = 0 , V_40 = 0 , V_13 = 0 ;
unsigned int V_1 , V_12 ;
struct V_54 V_55 ;
F_15 ( & V_55 ) ;
for ( V_1 = 0 ; V_1 < V_41 ; ++ V_1 ) {
if ( ! ( F_14 ( V_49 , V_55 . V_11 ) & ( 1 << V_1 ) ) )
continue;
for ( V_12 = 0 ; V_12 < V_42 ; ++ V_12 ) {
if ( V_12 == 0 ) {
V_13 = V_43 + V_1 * 4 ;
} else if ( V_12 == 1 ) {
V_13 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_13 )
break;
V_13 += V_45 ;
} else {
++ V_13 ;
}
if ( F_13 ( V_13 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) ) {
if ( V_12 )
continue;
else
break;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
F_16 ( V_56 ,
& F_17 ( V_57 ) ) ;
if ( V_40 & V_21 ) {
F_18 ( V_13 , V_55 . V_58 ) ;
F_18 ( V_59 + V_1 * 4 ,
V_55 . V_60 ) ;
V_55 . V_1 = V_61
+ V_1 * V_42
+ V_12 ;
F_19 ( & V_55 ) ;
return;
}
}
}
}
static T_2
F_20 ( struct V_3 * V_4 , const char * V_62 , T_3 V_63 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( ! V_4 -> V_25 )
return - V_64 ;
if ( F_21 ( V_62 , 0 , & V_34 ) < 0 )
return - V_64 ;
V_4 -> V_29 = ! ! V_34 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_4 = V_4 ;
F_22 ( V_4 -> V_11 , F_5 , & V_16 , 1 ) ;
return V_63 ;
}
static T_2
F_23 ( struct V_3 * V_4 , const char * V_62 , T_3 V_63 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( F_21 ( V_62 , 0 , & V_34 ) < 0 )
return - V_64 ;
if ( V_34 > V_18 )
V_34 = V_18 ;
if ( V_34 < 1 )
V_34 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = V_4 -> V_17 ;
V_4 -> V_17 = V_34 ;
V_16 . V_4 = V_4 ;
F_22 ( V_4 -> V_11 , F_5 , & V_16 , 1 ) ;
return V_63 ;
}
static void F_24 ( void * V_65 )
{
struct V_66 * V_67 = V_65 ;
struct V_3 * V_4 = V_67 -> V_68 ;
T_1 V_39 , V_40 ;
F_6 ( V_4 -> V_13 , V_39 , V_40 ) ;
V_67 -> V_69 = ( V_40 & 0xFFF ) - ( V_18 - V_4 -> V_17 ) ;
}
static T_2 F_25 ( struct V_3 * V_4 , char * V_62 )
{
struct V_66 V_67 = { . V_68 = V_4 , } ;
F_22 ( V_4 -> V_11 , F_24 , & V_67 , 1 ) ;
return sprintf ( V_62 , L_4 , V_67 . V_69 ) ;
}
static T_2 F_26 ( struct V_3 * V_4 ,
const char * V_62 , T_3 V_70 )
{
struct V_15 V_16 = { . V_4 = V_4 , . V_19 = 1 , . V_22 = 0 } ;
F_22 ( V_4 -> V_11 , F_5 , & V_16 , 1 ) ;
return 1 ;
}
static T_2 F_27 ( struct V_71 * V_72 , struct V_73 * V_74 , char * V_62 )
{
struct V_3 * V_4 = F_28 ( V_72 ) ;
struct V_75 * V_76 = F_29 ( V_74 ) ;
T_2 V_77 ;
V_77 = V_76 -> F_27 ? V_76 -> F_27 ( V_4 , V_62 ) : - V_78 ;
return V_77 ;
}
static T_2 F_30 ( struct V_71 * V_72 , struct V_73 * V_74 ,
const char * V_62 , T_3 V_70 )
{
struct V_3 * V_4 = F_28 ( V_72 ) ;
struct V_75 * V_76 = F_29 ( V_74 ) ;
T_2 V_77 ;
V_77 = V_76 -> F_30 ? V_76 -> F_30 ( V_4 , V_62 , V_70 ) : - V_78 ;
return V_77 ;
}
static T_4 int F_31 ( unsigned int V_11 ,
unsigned int V_1 ,
unsigned int V_12 ,
T_1 V_13 )
{
struct V_3 * V_4 = NULL ;
T_1 V_39 , V_40 ;
int V_79 ;
if ( ( V_1 >= V_41 ) || ( V_12 >= V_42 ) )
return 0 ;
if ( F_32 ( V_11 , V_13 , & V_39 , & V_40 ) )
return 0 ;
if ( ! ( V_40 & V_46 ) ) {
if ( V_12 )
goto V_80;
else
return 0 ;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
goto V_80;
V_4 = F_33 ( sizeof( struct V_3 ) , V_81 ) ;
if ( ! V_4 )
return - V_82 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_29 = 0 ;
V_4 -> V_25 = F_1 ( V_1 , V_40 ) ;
V_4 -> V_17 = V_18 ;
if ( V_4 -> V_25 )
V_83 . V_84 [ 2 ] = & V_29 . V_74 ;
else
V_83 . V_84 [ 2 ] = NULL ;
F_34 ( & V_4 -> V_85 ) ;
if ( F_14 ( V_86 , V_11 ) [ V_1 ] -> V_87 ) {
F_35 ( & V_4 -> V_85 ,
& F_14 ( V_86 , V_11 ) [ V_1 ] -> V_87 -> V_85 ) ;
} else {
F_14 ( V_86 , V_11 ) [ V_1 ] -> V_87 = V_4 ;
}
V_79 = F_36 ( & V_4 -> V_72 , & V_83 ,
F_14 ( V_86 , V_11 ) [ V_1 ] -> V_72 ,
L_5 , V_12 ) ;
if ( V_79 )
goto V_88;
V_80:
if ( ! V_12 ) {
V_13 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_13 )
return 0 ;
V_13 += V_45 ;
} else {
++ V_13 ;
}
V_79 = F_31 ( V_11 , V_1 , ++ V_12 , V_13 ) ;
if ( V_79 )
goto V_88;
if ( V_4 )
F_37 ( & V_4 -> V_72 , V_89 ) ;
return V_79 ;
V_88:
if ( V_4 ) {
F_38 ( & V_4 -> V_72 ) ;
F_39 ( & V_4 -> V_85 ) ;
F_40 ( V_4 ) ;
}
return V_79 ;
}
static T_4 long
F_41 ( int V_11 , unsigned int V_1 )
{
return F_31 ( V_11 , V_1 , 0 ,
V_43 + V_1 * 4 ) ;
}
static T_4 int F_42 ( unsigned int V_11 , unsigned int V_1 )
{
int V_90 , V_79 = 0 ;
struct V_91 * V_4 = NULL ;
struct V_92 * V_93 = F_14 ( V_94 , V_11 ) ;
char V_95 [ 32 ] ;
sprintf ( V_95 , L_6 , V_1 ) ;
#ifdef F_43
if ( F_44 ( V_11 ) . V_51 && V_50 [ V_1 ] ) {
V_90 = F_45 ( F_46 ( V_11 ) ) ;
if ( F_44 ( V_90 ) . V_51 )
goto V_96;
if ( F_14 ( V_86 , V_11 ) [ V_1 ] )
goto V_96;
V_4 = F_14 ( V_86 , V_90 ) [ V_1 ] ;
if ( ! V_4 )
goto V_96;
V_79 = F_47 ( & V_93 -> V_72 , V_4 -> V_72 , V_95 ) ;
if ( V_79 )
goto V_96;
F_48 ( V_4 -> V_97 , F_46 ( V_11 ) ) ;
F_14 ( V_86 , V_11 ) [ V_1 ] = V_4 ;
goto V_96;
}
#endif
V_4 = F_33 ( sizeof( struct V_91 ) , V_81 ) ;
if ( ! V_4 ) {
V_79 = - V_82 ;
goto V_96;
}
if ( ! F_49 ( & V_4 -> V_97 , V_81 ) ) {
F_40 ( V_4 ) ;
V_79 = - V_82 ;
goto V_96;
}
V_4 -> V_72 = F_50 ( V_95 , & V_93 -> V_72 ) ;
if ( ! V_4 -> V_72 )
goto V_88;
#ifndef F_43
F_51 ( V_4 -> V_97 ) ;
#else
F_52 ( V_11 , V_4 -> V_97 ) ;
#endif
F_14 ( V_86 , V_11 ) [ V_1 ] = V_4 ;
V_79 = F_41 ( V_11 , V_1 ) ;
if ( V_79 )
goto V_88;
F_53 (i, b->cpus) {
if ( V_90 == V_11 )
continue;
V_93 = F_14 ( V_94 , V_90 ) ;
if ( V_93 )
V_79 = F_47 ( & V_93 -> V_72 , V_4 -> V_72 , V_95 ) ;
if ( V_79 )
goto V_96;
F_14 ( V_86 , V_90 ) [ V_1 ] = V_4 ;
}
goto V_96;
V_88:
F_14 ( V_86 , V_11 ) [ V_1 ] = NULL ;
F_54 ( V_4 -> V_97 ) ;
F_40 ( V_4 ) ;
V_96:
return V_79 ;
}
static T_4 int F_55 ( unsigned int V_11 )
{
unsigned int V_1 ;
int V_79 = 0 ;
for ( V_1 = 0 ; V_1 < V_41 ; ++ V_1 ) {
if ( ! ( F_14 ( V_49 , V_11 ) & ( 1 << V_1 ) ) )
continue;
V_79 = F_42 ( V_11 , V_1 ) ;
if ( V_79 )
return V_79 ;
}
return V_79 ;
}
static void F_56 ( unsigned int V_11 ,
unsigned int V_1 )
{
struct V_3 * V_98 = NULL ;
struct V_3 * V_99 = NULL ;
struct V_91 * V_100 = F_14 ( V_86 , V_11 ) [ V_1 ] ;
if ( ! V_100 )
return;
F_57 (pos, tmp, &head->blocks->miscj, miscj) {
F_38 ( & V_98 -> V_72 ) ;
F_39 ( & V_98 -> V_85 ) ;
F_40 ( V_98 ) ;
}
F_40 ( F_14 ( V_86 , V_11 ) [ V_1 ] -> V_87 ) ;
F_14 ( V_86 , V_11 ) [ V_1 ] -> V_87 = NULL ;
}
static void F_58 ( unsigned int V_11 , int V_1 )
{
struct V_91 * V_4 ;
struct V_92 * V_93 ;
char V_95 [ 32 ] ;
int V_90 = 0 ;
V_4 = F_14 ( V_86 , V_11 ) [ V_1 ] ;
if ( ! V_4 )
return;
if ( ! V_4 -> V_87 )
goto V_101;
sprintf ( V_95 , L_6 , V_1 ) ;
#ifdef F_43
if ( V_50 [ V_1 ] && V_4 -> V_87 -> V_11 != V_11 ) {
V_93 = F_14 ( V_94 , V_11 ) ;
F_59 ( & V_93 -> V_72 , V_95 ) ;
F_14 ( V_86 , V_11 ) [ V_1 ] = NULL ;
return;
}
#endif
F_53 (i, b->cpus) {
if ( V_90 == V_11 )
continue;
V_93 = F_14 ( V_94 , V_90 ) ;
if ( V_93 )
F_59 ( & V_93 -> V_72 , V_95 ) ;
F_14 ( V_86 , V_90 ) [ V_1 ] = NULL ;
}
F_56 ( V_11 , V_1 ) ;
V_101:
F_60 ( V_4 -> V_72 ) ;
F_38 ( V_4 -> V_72 ) ;
F_54 ( V_4 -> V_97 ) ;
F_40 ( V_4 ) ;
F_14 ( V_86 , V_11 ) [ V_1 ] = NULL ;
}
static void F_61 ( unsigned int V_11 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_41 ; ++ V_1 ) {
if ( ! ( F_14 ( V_49 , V_11 ) & ( 1 << V_1 ) ) )
continue;
F_58 ( V_11 , V_1 ) ;
}
}
static void T_4
F_62 ( unsigned long V_102 , unsigned int V_11 )
{
switch ( V_102 ) {
case V_103 :
case V_104 :
F_55 ( V_11 ) ;
break;
case V_105 :
case V_106 :
F_61 ( V_11 ) ;
break;
default:
break;
}
}
static T_5 int F_63 ( void )
{
unsigned V_107 = 0 ;
F_64 (lcpu) {
int V_79 = F_55 ( V_107 ) ;
if ( V_79 )
return V_79 ;
}
V_108 = F_62 ;
return 0 ;
}
