static inline bool F_1 ( int V_1 )
{
return ( V_1 == 4 ) ;
}
static const char * F_2 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case 0x00000413 :
return L_1 ;
case 0xc0000408 :
return L_2 ;
case 0xc0000409 :
return L_3 ;
default:
F_3 ( 1 , L_4 , V_3 -> V_4 ) ;
return L_5 ;
}
}
static bool F_4 ( unsigned int V_1 , T_1 V_5 )
{
if ( V_1 == 4 )
return true ;
return V_5 & F_5 ( 28 ) ;
}
static int F_6 ( struct V_2 * V_3 , int V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 = ( V_8 & V_10 ) >> 20 ;
if ( V_6 < 0 ) {
F_7 ( V_11 L_6
L_7 , V_3 -> V_12 ,
V_3 -> V_1 , V_3 -> V_13 , V_3 -> V_4 , V_8 , V_7 ) ;
return 0 ;
}
if ( V_6 != V_9 ) {
F_7 ( V_11 L_8
L_7 ,
V_3 -> V_12 , V_6 , V_3 -> V_1 , V_3 -> V_13 , V_3 -> V_4 , V_8 , V_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_8 ( void * V_14 )
{
struct V_15 * V_16 = V_14 ;
T_1 V_8 , V_7 ;
F_9 ( V_16 -> V_3 -> V_4 , V_7 , V_8 ) ;
if ( V_16 -> V_3 -> V_17 < ( V_8 & V_18 ) )
V_16 -> V_19 = 1 ;
if ( V_16 -> V_19 ) {
V_8 =
( V_8 & ~ ( V_20 | V_21 ) ) |
( V_18 - V_16 -> V_3 -> V_17 ) ;
} else if ( V_16 -> V_22 ) {
int V_23 = ( V_8 & V_18 ) +
( V_16 -> V_22 - V_16 -> V_3 -> V_17 ) ;
V_8 = ( V_8 & ~ V_20 ) |
( V_23 & V_18 ) ;
}
V_8 &= ~ V_24 ;
if ( ! V_16 -> V_3 -> V_25 )
goto V_26;
if ( V_16 -> V_27 ) {
if ( F_6 ( V_16 -> V_3 , V_16 -> V_28 , V_7 , V_8 ) ) {
V_8 &= ~ V_10 ;
V_8 |= V_16 -> V_28 << 20 ;
}
}
if ( V_16 -> V_3 -> V_29 )
V_8 |= V_30 ;
V_26:
V_8 |= V_31 ;
F_10 ( V_16 -> V_3 -> V_4 , V_7 , V_8 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_32 )
{
struct V_15 V_16 = {
. V_3 = V_3 ,
. V_27 = 1 ,
. V_28 = V_32 ,
} ;
V_3 -> V_17 = V_18 ;
F_8 ( & V_16 ) ;
}
static int F_12 ( int V_33 , int V_34 )
{
if ( V_33 < 0 && ! F_13 ( V_34 , V_35 ,
V_36 , 0 ) )
return V_34 ;
return V_33 ;
}
void F_14 ( struct V_37 * V_38 )
{
struct V_2 V_3 ;
unsigned int V_12 = F_15 () ;
T_1 V_39 = 0 , V_40 = 0 , V_4 = 0 ;
unsigned int V_1 , V_13 ;
int V_32 = - 1 , V_34 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 ) {
if ( V_13 == 0 )
V_4 = F_16 ( V_1 ) ;
else if ( V_13 == 1 ) {
V_4 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_4 )
break;
V_4 += V_45 ;
} else
++ V_4 ;
if ( F_17 ( V_4 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) )
continue;
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
if ( ! V_13 )
F_18 ( V_49 , V_12 ) |= ( 1 << V_1 ) ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_12 = V_12 ;
V_3 . V_1 = V_1 ;
V_3 . V_13 = V_13 ;
V_3 . V_4 = V_4 ;
V_3 . V_25 = F_4 ( V_1 , V_40 ) ;
if ( ! V_3 . V_25 )
goto V_50;
V_3 . V_29 = 1 ;
V_34 = ( V_40 & V_10 ) >> 20 ;
V_32 = F_12 ( V_32 , V_34 ) ;
if ( ( V_32 == V_34 ) &&
( V_51 != V_52 ) )
V_51 = V_52 ;
V_50:
F_11 ( & V_3 , V_32 ) ;
}
}
}
static void V_52 ( void )
{
T_1 V_39 = 0 , V_40 = 0 , V_4 = 0 ;
int V_12 = F_15 () ;
unsigned int V_1 , V_13 ;
struct V_53 V_54 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_18 ( V_49 , V_12 ) & ( 1 << V_1 ) ) )
continue;
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 ) {
if ( V_13 == 0 ) {
V_4 = F_16 ( V_1 ) ;
} else if ( V_13 == 1 ) {
V_4 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_4 )
break;
V_4 += V_45 ;
} else {
++ V_4 ;
}
if ( F_17 ( V_4 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) ) {
if ( V_13 )
continue;
else
break;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
if ( V_40 & V_21 )
goto log;
}
}
return;
log:
F_19 ( & V_54 ) ;
F_20 ( F_21 ( V_1 ) , V_54 . V_55 ) ;
if ( ! ( V_54 . V_55 & V_56 ) )
return;
V_54 . V_57 = ( ( V_58 ) V_40 << 32 ) | V_39 ;
V_54 . V_1 = V_1 ;
F_22 ( & V_54 ) ;
F_23 ( F_21 ( V_1 ) , 0 ) ;
}
static T_2
F_24 ( struct V_2 * V_3 , const char * V_59 , T_3 V_60 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( ! V_3 -> V_25 )
return - V_61 ;
if ( F_25 ( V_59 , 0 , & V_34 ) < 0 )
return - V_61 ;
V_3 -> V_29 = ! ! V_34 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_3 = V_3 ;
F_26 ( V_3 -> V_12 , F_8 , & V_16 , 1 ) ;
return V_60 ;
}
static T_2
F_27 ( struct V_2 * V_3 , const char * V_59 , T_3 V_60 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( F_25 ( V_59 , 0 , & V_34 ) < 0 )
return - V_61 ;
if ( V_34 > V_18 )
V_34 = V_18 ;
if ( V_34 < 1 )
V_34 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = V_3 -> V_17 ;
V_3 -> V_17 = V_34 ;
V_16 . V_3 = V_3 ;
F_26 ( V_3 -> V_12 , F_8 , & V_16 , 1 ) ;
return V_60 ;
}
static T_2 F_28 ( struct V_2 * V_3 , char * V_59 )
{
T_1 V_7 , V_8 ;
F_29 ( V_3 -> V_12 , V_3 -> V_4 , & V_7 , & V_8 ) ;
return sprintf ( V_59 , L_9 , ( ( V_8 & V_18 ) -
( V_18 - V_3 -> V_17 ) ) ) ;
}
static T_2 F_30 ( struct V_62 * V_63 , struct V_64 * V_65 , char * V_59 )
{
struct V_2 * V_3 = F_31 ( V_63 ) ;
struct V_66 * V_67 = F_32 ( V_65 ) ;
T_2 V_68 ;
V_68 = V_67 -> F_30 ? V_67 -> F_30 ( V_3 , V_59 ) : - V_69 ;
return V_68 ;
}
static T_2 F_33 ( struct V_62 * V_63 , struct V_64 * V_65 ,
const char * V_59 , T_3 V_70 )
{
struct V_2 * V_3 = F_31 ( V_63 ) ;
struct V_66 * V_67 = F_32 ( V_65 ) ;
T_2 V_68 ;
V_68 = V_67 -> F_33 ? V_67 -> F_33 ( V_3 , V_59 , V_70 ) : - V_69 ;
return V_68 ;
}
static int F_34 ( unsigned int V_12 , unsigned int V_1 ,
unsigned int V_13 , T_1 V_4 )
{
struct V_2 * V_3 = NULL ;
T_1 V_39 , V_40 ;
int V_71 ;
if ( ( V_1 >= V_41 . V_42 ) || ( V_13 >= V_43 ) )
return 0 ;
if ( F_35 ( V_12 , V_4 , & V_39 , & V_40 ) )
return 0 ;
if ( ! ( V_40 & V_46 ) ) {
if ( V_13 )
goto V_72;
else
return 0 ;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
goto V_72;
V_3 = F_36 ( sizeof( struct V_2 ) , V_73 ) ;
if ( ! V_3 )
return - V_74 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_29 = 0 ;
V_3 -> V_25 = F_4 ( V_1 , V_40 ) ;
V_3 -> V_17 = V_18 ;
if ( V_3 -> V_25 ) {
V_75 . V_76 [ 2 ] = & V_29 . V_65 ;
V_3 -> V_29 = 1 ;
} else {
V_75 . V_76 [ 2 ] = NULL ;
}
F_37 ( & V_3 -> V_77 ) ;
if ( F_18 ( V_78 , V_12 ) [ V_1 ] -> V_79 ) {
F_38 ( & V_3 -> V_77 ,
& F_18 ( V_78 , V_12 ) [ V_1 ] -> V_79 -> V_77 ) ;
} else {
F_18 ( V_78 , V_12 ) [ V_1 ] -> V_79 = V_3 ;
}
V_71 = F_39 ( & V_3 -> V_63 , & V_75 ,
F_18 ( V_78 , V_12 ) [ V_1 ] -> V_63 ,
( V_1 == 4 ? F_2 ( V_3 ) : V_80 [ V_1 ] ) ) ;
if ( V_71 )
goto V_81;
V_72:
if ( ! V_13 ) {
V_4 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_4 )
return 0 ;
V_4 += V_45 ;
} else {
++ V_4 ;
}
V_71 = F_34 ( V_12 , V_1 , ++ V_13 , V_4 ) ;
if ( V_71 )
goto V_81;
if ( V_3 )
F_40 ( & V_3 -> V_63 , V_82 ) ;
return V_71 ;
V_81:
if ( V_3 ) {
F_41 ( & V_3 -> V_63 ) ;
F_42 ( & V_3 -> V_77 ) ;
F_43 ( V_3 ) ;
}
return V_71 ;
}
static int F_44 ( struct V_83 * V_3 )
{
struct V_84 * V_85 = & V_3 -> V_79 -> V_77 ;
struct V_2 * V_86 = NULL ;
struct V_2 * V_87 = NULL ;
int V_71 = 0 ;
V_71 = F_45 ( & V_3 -> V_79 -> V_63 , V_3 -> V_63 , V_3 -> V_79 -> V_63 . V_88 ) ;
if ( V_71 )
return V_71 ;
F_46 (pos, tmp, head, miscj) {
V_71 = F_45 ( & V_86 -> V_63 , V_3 -> V_63 , V_86 -> V_63 . V_88 ) ;
if ( V_71 ) {
F_47 (pos, tmp, head, miscj)
F_48 ( & V_86 -> V_63 ) ;
return V_71 ;
}
}
return V_71 ;
}
static int F_49 ( unsigned int V_12 , unsigned int V_1 )
{
struct V_89 * V_90 = F_18 ( V_91 , V_12 ) ;
struct V_92 * V_93 = NULL ;
struct V_83 * V_3 = NULL ;
const char * V_88 = V_80 [ V_1 ] ;
int V_71 = 0 ;
if ( F_1 ( V_1 ) ) {
V_93 = F_50 ( F_51 ( V_12 ) ) ;
if ( V_93 && V_93 -> V_94 ) {
V_3 = V_93 -> V_94 ;
V_71 = F_45 ( V_3 -> V_63 , & V_90 -> V_63 , V_88 ) ;
if ( V_71 )
goto V_95;
F_18 ( V_78 , V_12 ) [ V_1 ] = V_3 ;
F_52 ( & V_3 -> V_96 ) ;
V_71 = F_44 ( V_3 ) ;
goto V_95;
}
}
V_3 = F_36 ( sizeof( struct V_83 ) , V_73 ) ;
if ( ! V_3 ) {
V_71 = - V_74 ;
goto V_95;
}
V_3 -> V_63 = F_53 ( V_88 , & V_90 -> V_63 ) ;
if ( ! V_3 -> V_63 ) {
V_71 = - V_61 ;
goto V_81;
}
F_18 ( V_78 , V_12 ) [ V_1 ] = V_3 ;
if ( F_1 ( V_1 ) ) {
F_54 ( & V_3 -> V_96 , 1 ) ;
if ( V_93 ) {
F_55 ( V_93 -> V_94 ) ;
V_93 -> V_94 = V_3 ;
}
}
V_71 = F_34 ( V_12 , V_1 , 0 , F_16 ( V_1 ) ) ;
if ( ! V_71 )
goto V_95;
V_81:
F_43 ( V_3 ) ;
V_95:
return V_71 ;
}
static int F_56 ( unsigned int V_12 )
{
unsigned int V_1 ;
struct V_83 * * V_97 ;
int V_71 = 0 ;
V_97 = F_36 ( sizeof( struct V_83 * ) * V_41 . V_42 ,
V_73 ) ;
if ( ! V_97 )
return - V_74 ;
F_18 ( V_78 , V_12 ) = V_97 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_18 ( V_49 , V_12 ) & ( 1 << V_1 ) ) )
continue;
V_71 = F_49 ( V_12 , V_1 ) ;
if ( V_71 )
return V_71 ;
}
return V_71 ;
}
static void F_57 ( unsigned int V_12 ,
unsigned int V_1 )
{
struct V_2 * V_86 = NULL ;
struct V_2 * V_87 = NULL ;
struct V_83 * V_85 = F_18 ( V_78 , V_12 ) [ V_1 ] ;
if ( ! V_85 )
return;
F_46 (pos, tmp, &head->blocks->miscj, miscj) {
F_41 ( & V_86 -> V_63 ) ;
F_42 ( & V_86 -> V_77 ) ;
F_43 ( V_86 ) ;
}
F_43 ( F_18 ( V_78 , V_12 ) [ V_1 ] -> V_79 ) ;
F_18 ( V_78 , V_12 ) [ V_1 ] -> V_79 = NULL ;
}
static void F_58 ( struct V_83 * V_3 )
{
struct V_2 * V_86 = NULL ;
struct V_2 * V_87 = NULL ;
F_48 ( V_3 -> V_63 ) ;
F_46 (pos, tmp, &b->blocks->miscj, miscj)
F_48 ( & V_86 -> V_63 ) ;
}
static void F_59 ( unsigned int V_12 , int V_1 )
{
struct V_92 * V_93 ;
struct V_83 * V_3 ;
V_3 = F_18 ( V_78 , V_12 ) [ V_1 ] ;
if ( ! V_3 )
return;
if ( ! V_3 -> V_79 )
goto V_98;
if ( F_1 ( V_1 ) ) {
if ( ! F_60 ( & V_3 -> V_96 ) ) {
F_58 ( V_3 ) ;
F_18 ( V_78 , V_12 ) [ V_1 ] = NULL ;
return;
} else {
V_93 = F_50 ( F_51 ( V_12 ) ) ;
V_93 -> V_94 = NULL ;
}
}
F_57 ( V_12 , V_1 ) ;
V_98:
F_48 ( V_3 -> V_63 ) ;
F_41 ( V_3 -> V_63 ) ;
F_43 ( V_3 ) ;
F_18 ( V_78 , V_12 ) [ V_1 ] = NULL ;
}
static void F_61 ( unsigned int V_12 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_18 ( V_49 , V_12 ) & ( 1 << V_1 ) ) )
continue;
F_59 ( V_12 , V_1 ) ;
}
F_43 ( F_18 ( V_78 , V_12 ) ) ;
}
static void
F_62 ( unsigned long V_99 , unsigned int V_12 )
{
switch ( V_99 ) {
case V_100 :
case V_101 :
F_56 ( V_12 ) ;
break;
case V_102 :
case V_103 :
F_61 ( V_12 ) ;
break;
default:
break;
}
}
static T_4 int F_63 ( void )
{
unsigned V_104 = 0 ;
F_64 (lcpu) {
int V_71 = F_56 ( V_104 ) ;
if ( V_71 )
return V_71 ;
}
V_105 = F_62 ;
return 0 ;
}
