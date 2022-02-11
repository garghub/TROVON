static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 = ( V_5 & V_7 ) >> 20 ;
if ( V_3 < 0 ) {
F_2 ( V_8 L_1
L_2 , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_11 , V_2 -> V_12 , V_5 , V_4 ) ;
return 0 ;
}
if ( V_3 != V_6 ) {
F_2 ( V_8 L_3
L_2 ,
V_2 -> V_9 , V_3 , V_2 -> V_10 , V_2 -> V_11 , V_2 -> V_12 , V_5 , V_4 ) ;
return 0 ;
}
return 1 ;
}
static void F_3 ( void * V_13 )
{
struct V_14 * V_15 = V_13 ;
T_1 V_5 , V_4 ;
F_4 ( V_15 -> V_2 -> V_12 , V_4 , V_5 ) ;
if ( V_15 -> V_2 -> V_16 < ( V_5 & V_17 ) )
V_15 -> V_18 = 1 ;
if ( V_15 -> V_18 ) {
V_5 =
( V_5 & ~ ( V_19 | V_20 ) ) |
( V_17 - V_15 -> V_2 -> V_16 ) ;
} else if ( V_15 -> V_21 ) {
int V_22 = ( V_5 & V_17 ) +
( V_15 -> V_21 - V_15 -> V_2 -> V_16 ) ;
V_5 = ( V_5 & ~ V_19 ) |
( V_22 & V_17 ) ;
}
if ( V_15 -> V_23 ) {
if ( F_1 ( V_15 -> V_2 , V_15 -> V_24 , V_4 , V_5 ) ) {
V_5 &= ~ V_7 ;
V_5 |= V_15 -> V_24 << 20 ;
}
}
V_15 -> V_2 -> V_25 ?
( V_5 = ( V_5 & ~ V_26 ) | V_27 ) :
( V_5 &= ~ V_26 ) ;
V_5 |= V_28 ;
F_5 ( V_15 -> V_2 -> V_12 , V_4 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_29 )
{
struct V_14 V_15 = {
. V_2 = V_2 ,
. V_23 = 1 ,
. V_24 = V_29 ,
} ;
V_2 -> V_16 = V_17 ;
F_3 ( & V_15 ) ;
}
static int F_7 ( int V_30 , int V_31 )
{
if ( V_30 < 0 && ! F_8 ( V_31 , V_32 ,
V_33 , 0 ) )
return V_31 ;
return V_30 ;
}
void F_9 ( struct V_34 * V_35 )
{
struct V_1 V_2 ;
unsigned int V_9 = F_10 () ;
T_1 V_36 = 0 , V_37 = 0 , V_12 = 0 ;
unsigned int V_10 , V_11 ;
int V_29 = - 1 ;
for ( V_10 = 0 ; V_10 < V_38 ; ++ V_10 ) {
for ( V_11 = 0 ; V_11 < V_39 ; ++ V_11 ) {
if ( V_11 == 0 )
V_12 = V_40 + V_10 * 4 ;
else if ( V_11 == 1 ) {
V_12 = ( V_36 & V_41 ) >> 21 ;
if ( ! V_12 )
break;
V_12 += V_42 ;
} else
++ V_12 ;
if ( F_11 ( V_12 , & V_36 , & V_37 ) )
break;
if ( ! ( V_37 & V_43 ) )
continue;
if ( ! ( V_37 & V_44 ) ||
( V_37 & V_45 ) )
continue;
if ( ! V_11 )
F_12 ( V_46 , V_9 ) |= ( 1 << V_10 ) ;
#ifdef F_13
if ( V_47 [ V_10 ] && V_35 -> V_48 )
break;
#endif
V_29 = F_7 ( V_29 ,
( V_37 & V_7 ) >> 20 ) ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_10 = V_10 ;
V_2 . V_11 = V_11 ;
V_2 . V_12 = V_12 ;
F_6 ( & V_2 , V_29 ) ;
V_49 = V_50 ;
}
}
}
static void V_50 ( void )
{
T_1 V_36 = 0 , V_37 = 0 , V_12 = 0 ;
unsigned int V_10 , V_11 ;
struct V_51 V_52 ;
F_14 ( & V_52 ) ;
for ( V_10 = 0 ; V_10 < V_38 ; ++ V_10 ) {
if ( ! ( F_12 ( V_46 , V_52 . V_9 ) & ( 1 << V_10 ) ) )
continue;
for ( V_11 = 0 ; V_11 < V_39 ; ++ V_11 ) {
if ( V_11 == 0 ) {
V_12 = V_40 + V_10 * 4 ;
} else if ( V_11 == 1 ) {
V_12 = ( V_36 & V_41 ) >> 21 ;
if ( ! V_12 )
break;
V_12 += V_42 ;
} else {
++ V_12 ;
}
if ( F_11 ( V_12 , & V_36 , & V_37 ) )
break;
if ( ! ( V_37 & V_43 ) ) {
if ( V_11 )
continue;
else
break;
}
if ( ! ( V_37 & V_44 ) ||
( V_37 & V_45 ) )
continue;
F_15 ( V_53 ,
& F_16 ( V_54 ) ) ;
if ( V_37 & V_20 ) {
F_17 ( V_12 , V_52 . V_55 ) ;
F_17 ( V_56 + V_10 * 4 ,
V_52 . V_57 ) ;
V_52 . V_10 = V_58
+ V_10 * V_39
+ V_11 ;
F_18 ( & V_52 ) ;
return;
}
}
}
}
static T_2
F_19 ( struct V_1 * V_2 , const char * V_59 , T_3 V_60 )
{
struct V_14 V_15 ;
unsigned long V_31 ;
if ( F_20 ( V_59 , 0 , & V_31 ) < 0 )
return - V_61 ;
V_2 -> V_25 = ! ! V_31 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_2 = V_2 ;
F_21 ( V_2 -> V_9 , F_3 , & V_15 , 1 ) ;
return V_60 ;
}
static T_2
F_22 ( struct V_1 * V_2 , const char * V_59 , T_3 V_60 )
{
struct V_14 V_15 ;
unsigned long V_31 ;
if ( F_20 ( V_59 , 0 , & V_31 ) < 0 )
return - V_61 ;
if ( V_31 > V_17 )
V_31 = V_17 ;
if ( V_31 < 1 )
V_31 = 1 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_21 = V_2 -> V_16 ;
V_2 -> V_16 = V_31 ;
V_15 . V_2 = V_2 ;
F_21 ( V_2 -> V_9 , F_3 , & V_15 , 1 ) ;
return V_60 ;
}
static void F_23 ( void * V_62 )
{
struct V_63 * V_64 = V_62 ;
struct V_1 * V_2 = V_64 -> V_65 ;
T_1 V_36 , V_37 ;
F_4 ( V_2 -> V_12 , V_36 , V_37 ) ;
V_64 -> V_66 = ( V_37 & 0xFFF ) - ( V_17 - V_2 -> V_16 ) ;
}
static T_2 F_24 ( struct V_1 * V_2 , char * V_59 )
{
struct V_63 V_64 = { . V_65 = V_2 , } ;
F_21 ( V_2 -> V_9 , F_23 , & V_64 , 1 ) ;
return sprintf ( V_59 , L_4 , V_64 . V_66 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 ,
const char * V_59 , T_3 V_67 )
{
struct V_14 V_15 = { . V_2 = V_2 , . V_18 = 1 , . V_21 = 0 } ;
F_21 ( V_2 -> V_9 , F_3 , & V_15 , 1 ) ;
return 1 ;
}
static T_2 F_26 ( struct V_68 * V_69 , struct V_70 * V_71 , char * V_59 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_72 * V_73 = F_28 ( V_71 ) ;
T_2 V_74 ;
V_74 = V_73 -> F_26 ? V_73 -> F_26 ( V_2 , V_59 ) : - V_75 ;
return V_74 ;
}
static T_2 F_29 ( struct V_68 * V_69 , struct V_70 * V_71 ,
const char * V_59 , T_3 V_67 )
{
struct V_1 * V_2 = F_27 ( V_69 ) ;
struct V_72 * V_73 = F_28 ( V_71 ) ;
T_2 V_74 ;
V_74 = V_73 -> F_29 ? V_73 -> F_29 ( V_2 , V_59 , V_67 ) : - V_75 ;
return V_74 ;
}
static T_4 int F_30 ( unsigned int V_9 ,
unsigned int V_10 ,
unsigned int V_11 ,
T_1 V_12 )
{
struct V_1 * V_2 = NULL ;
T_1 V_36 , V_37 ;
int V_76 ;
if ( ( V_10 >= V_38 ) || ( V_11 >= V_39 ) )
return 0 ;
if ( F_31 ( V_9 , V_12 , & V_36 , & V_37 ) )
return 0 ;
if ( ! ( V_37 & V_43 ) ) {
if ( V_11 )
goto V_77;
else
return 0 ;
}
if ( ! ( V_37 & V_44 ) ||
( V_37 & V_45 ) )
goto V_77;
V_2 = F_32 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_25 = 0 ;
V_2 -> V_16 = V_17 ;
F_33 ( & V_2 -> V_80 ) ;
if ( F_12 ( V_81 , V_9 ) [ V_10 ] -> V_82 ) {
F_34 ( & V_2 -> V_80 ,
& F_12 ( V_81 , V_9 ) [ V_10 ] -> V_82 -> V_80 ) ;
} else {
F_12 ( V_81 , V_9 ) [ V_10 ] -> V_82 = V_2 ;
}
V_76 = F_35 ( & V_2 -> V_69 , & V_83 ,
F_12 ( V_81 , V_9 ) [ V_10 ] -> V_69 ,
L_5 , V_11 ) ;
if ( V_76 )
goto V_84;
V_77:
if ( ! V_11 ) {
V_12 = ( V_36 & V_41 ) >> 21 ;
if ( ! V_12 )
return 0 ;
V_12 += V_42 ;
} else {
++ V_12 ;
}
V_76 = F_30 ( V_9 , V_10 , ++ V_11 , V_12 ) ;
if ( V_76 )
goto V_84;
if ( V_2 )
F_36 ( & V_2 -> V_69 , V_85 ) ;
return V_76 ;
V_84:
if ( V_2 ) {
F_37 ( & V_2 -> V_69 ) ;
F_38 ( & V_2 -> V_80 ) ;
F_39 ( V_2 ) ;
}
return V_76 ;
}
static T_4 long
F_40 ( int V_9 , unsigned int V_10 )
{
return F_30 ( V_9 , V_10 , 0 ,
V_40 + V_10 * 4 ) ;
}
static T_4 int F_41 ( unsigned int V_9 , unsigned int V_10 )
{
int V_86 , V_76 = 0 ;
struct V_87 * V_2 = NULL ;
char V_88 [ 32 ] ;
sprintf ( V_88 , L_6 , V_10 ) ;
#ifdef F_13
if ( F_42 ( V_9 ) . V_48 && V_47 [ V_10 ] ) {
V_86 = F_43 ( F_44 ( V_9 ) ) ;
if ( F_42 ( V_86 ) . V_48 )
goto V_89;
if ( F_12 ( V_81 , V_9 ) [ V_10 ] )
goto V_89;
V_2 = F_12 ( V_81 , V_86 ) [ V_10 ] ;
if ( ! V_2 )
goto V_89;
V_76 = F_45 ( & F_12 ( V_90 , V_9 ) . V_69 ,
V_2 -> V_69 , V_88 ) ;
if ( V_76 )
goto V_89;
F_46 ( V_2 -> V_91 , F_44 ( V_9 ) ) ;
F_12 ( V_81 , V_9 ) [ V_10 ] = V_2 ;
goto V_89;
}
#endif
V_2 = F_32 ( sizeof( struct V_87 ) , V_78 ) ;
if ( ! V_2 ) {
V_76 = - V_79 ;
goto V_89;
}
if ( ! F_47 ( & V_2 -> V_91 , V_78 ) ) {
F_39 ( V_2 ) ;
V_76 = - V_79 ;
goto V_89;
}
V_2 -> V_69 = F_48 ( V_88 , & F_12 ( V_90 , V_9 ) . V_69 ) ;
if ( ! V_2 -> V_69 )
goto V_84;
#ifndef F_13
F_49 ( V_2 -> V_91 ) ;
#else
F_50 ( V_9 , V_2 -> V_91 ) ;
#endif
F_12 ( V_81 , V_9 ) [ V_10 ] = V_2 ;
V_76 = F_40 ( V_9 , V_10 ) ;
if ( V_76 )
goto V_84;
F_51 (i, b->cpus) {
if ( V_86 == V_9 )
continue;
V_76 = F_45 ( & F_12 ( V_90 , V_86 ) . V_69 ,
V_2 -> V_69 , V_88 ) ;
if ( V_76 )
goto V_89;
F_12 ( V_81 , V_86 ) [ V_10 ] = V_2 ;
}
goto V_89;
V_84:
F_12 ( V_81 , V_9 ) [ V_10 ] = NULL ;
F_52 ( V_2 -> V_91 ) ;
F_39 ( V_2 ) ;
V_89:
return V_76 ;
}
static T_4 int F_53 ( unsigned int V_9 )
{
unsigned int V_10 ;
int V_76 = 0 ;
for ( V_10 = 0 ; V_10 < V_38 ; ++ V_10 ) {
if ( ! ( F_12 ( V_46 , V_9 ) & ( 1 << V_10 ) ) )
continue;
V_76 = F_41 ( V_9 , V_10 ) ;
if ( V_76 )
return V_76 ;
}
return V_76 ;
}
static void F_54 ( unsigned int V_9 ,
unsigned int V_10 )
{
struct V_1 * V_92 = NULL ;
struct V_1 * V_93 = NULL ;
struct V_87 * V_94 = F_12 ( V_81 , V_9 ) [ V_10 ] ;
if ( ! V_94 )
return;
F_55 (pos, tmp, &head->blocks->miscj, miscj) {
F_37 ( & V_92 -> V_69 ) ;
F_38 ( & V_92 -> V_80 ) ;
F_39 ( V_92 ) ;
}
F_39 ( F_12 ( V_81 , V_9 ) [ V_10 ] -> V_82 ) ;
F_12 ( V_81 , V_9 ) [ V_10 ] -> V_82 = NULL ;
}
static void F_56 ( unsigned int V_9 , int V_10 )
{
struct V_87 * V_2 ;
char V_88 [ 32 ] ;
int V_86 = 0 ;
V_2 = F_12 ( V_81 , V_9 ) [ V_10 ] ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_82 )
goto V_95;
sprintf ( V_88 , L_6 , V_10 ) ;
#ifdef F_13
if ( V_47 [ V_10 ] && V_2 -> V_82 -> V_9 != V_9 ) {
F_57 ( & F_12 ( V_90 , V_9 ) . V_69 , V_88 ) ;
F_12 ( V_81 , V_9 ) [ V_10 ] = NULL ;
return;
}
#endif
F_51 (i, b->cpus) {
if ( V_86 == V_9 )
continue;
F_57 ( & F_12 ( V_90 , V_86 ) . V_69 , V_88 ) ;
F_12 ( V_81 , V_86 ) [ V_10 ] = NULL ;
}
F_54 ( V_9 , V_10 ) ;
V_95:
F_58 ( V_2 -> V_69 ) ;
F_37 ( V_2 -> V_69 ) ;
F_52 ( V_2 -> V_91 ) ;
F_39 ( V_2 ) ;
F_12 ( V_81 , V_9 ) [ V_10 ] = NULL ;
}
static void F_59 ( unsigned int V_9 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_38 ; ++ V_10 ) {
if ( ! ( F_12 ( V_46 , V_9 ) & ( 1 << V_10 ) ) )
continue;
F_56 ( V_9 , V_10 ) ;
}
}
static void T_4
F_60 ( unsigned long V_96 , unsigned int V_9 )
{
switch ( V_96 ) {
case V_97 :
case V_98 :
F_53 ( V_9 ) ;
break;
case V_99 :
case V_100 :
F_59 ( V_9 ) ;
break;
default:
break;
}
}
static T_5 int F_61 ( void )
{
unsigned V_101 = 0 ;
F_62 (lcpu) {
int V_76 = F_53 ( V_101 ) ;
if ( V_76 )
return V_76 ;
}
V_102 = F_60 ;
return 0 ;
}
