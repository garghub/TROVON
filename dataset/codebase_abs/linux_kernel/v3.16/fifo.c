void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , int * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
F_6 ( V_9 , L_1 ) ;
return - V_10 ;
}
void F_7 ( struct V_11 * V_7 , struct V_1 * V_2 ,
void (* F_8)( struct V_5 * V_6 ,
struct V_1 * V_2 ) ,
void * V_12 , int V_13 , int V_14 , int V_15 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
unsigned long V_16 ;
if ( ! F_8 ) {
F_6 ( V_9 , L_2 ) ;
return;
}
F_9 ( V_6 , V_16 ) ;
if ( ! V_7 -> V_17 ) {
F_6 ( V_9 , L_3 ) ;
V_7 -> V_17 = & V_18 ;
}
F_10 ( & V_2 -> V_3 , & V_7 -> V_19 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_17 = V_7 -> V_17 ;
V_2 -> V_20 = V_13 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_21 = 0 ;
V_2 -> F_8 = F_8 ;
V_2 -> V_15 = V_15 ;
F_11 ( V_6 , V_16 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_3 ) ;
}
static struct V_1 * F_14 ( struct V_11 * V_7 )
{
if ( F_15 ( & V_7 -> V_19 ) )
return NULL ;
return F_16 ( & V_7 -> V_19 , struct V_1 , V_3 ) ;
}
struct V_1 * F_17 ( struct V_11 * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
unsigned long V_16 ;
F_9 ( V_6 , V_16 ) ;
if ( ! V_2 )
V_2 = F_14 ( V_7 ) ;
if ( V_2 )
F_12 ( V_2 ) ;
F_11 ( V_6 , V_16 ) ;
return V_2 ;
}
static int F_18 ( struct V_11 * V_7 , int type )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int (* F_19)( struct V_1 * V_2 , int * V_4 );
unsigned long V_16 ;
int V_22 = 0 ;
int V_4 = 0 ;
F_9 ( V_6 , V_16 ) ;
V_2 = F_14 ( V_7 ) ;
if ( ! V_2 )
goto V_23;
switch ( type ) {
case V_24 :
F_19 = V_2 -> V_17 -> V_25 ;
break;
case V_26 :
F_19 = V_2 -> V_17 -> V_27 ;
break;
case V_28 :
F_19 = V_2 -> V_17 -> V_29 ;
break;
default:
F_6 ( V_9 , L_4 ) ;
goto V_23;
}
V_22 = F_19 ( V_2 , & V_4 ) ;
if ( V_4 )
F_12 ( V_2 ) ;
V_23:
F_11 ( V_6 , V_16 ) ;
if ( V_4 ) {
V_2 -> F_8 ( V_6 , V_2 ) ;
F_20 ( V_7 ) ;
}
return V_22 ;
}
void F_20 ( struct V_11 * V_7 )
{
F_18 ( V_7 , V_24 ) ;
}
static void F_21 ( struct V_11 * V_7 , int V_30 )
{
if ( F_22 ( V_7 ) )
F_23 ( V_7 , V_30 ) ;
else
F_24 ( V_7 , V_30 ) ;
}
static void F_25 ( struct V_11 * V_7 , int V_30 )
{
F_24 ( V_7 , V_30 ) ;
}
static void F_26 ( struct V_11 * V_7 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_27 ( V_6 , V_32 -> V_33 , V_34 , V_34 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
int V_35 = 1024 ;
do {
if ( F_29 ( V_6 , V_32 -> V_33 ) & V_36 )
return 0 ;
F_30 ( 10 ) ;
} while ( V_35 -- );
return - V_37 ;
}
static void F_31 ( struct V_11 * V_7 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
if ( ! F_22 ( V_7 ) )
F_28 ( V_6 , V_32 ) ;
F_32 ( V_6 , V_32 -> V_33 , V_38 ) ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
return F_29 ( V_6 , V_32 -> V_33 ) & V_39 ;
}
static void F_34 ( struct V_11 * V_7 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_35 ( V_7 , NULL ) ;
F_32 ( V_6 , V_32 -> V_40 , 0 ) ;
}
static int F_36 ( struct V_11 * V_7 ,
struct V_31 * V_32 ,
int V_41 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_35 = 1024 ;
T_1 V_42 = ( ( 1 << 5 ) | 0xF ) ;
T_1 V_43 = F_37 ( V_7 ) ;
if ( F_38 ( V_7 ) ||
F_39 ( V_32 ) )
return - V_37 ;
if ( F_22 ( V_7 ) ) {
V_43 |= ( 1 == V_41 ) << 5 ;
if ( F_40 ( V_6 ) )
F_41 ( V_7 , V_41 ) ;
}
if ( F_42 ( V_6 , V_44 ) && ! F_43 ( V_6 , V_32 ) )
F_32 ( V_6 , V_32 -> V_40 , V_43 ) ;
else
F_32 ( V_6 , V_32 -> V_40 , V_43 | V_45 ) ;
while ( V_35 -- ) {
if ( V_43 == ( V_42 & F_29 ( V_6 , V_32 -> V_40 ) ) ) {
F_35 ( V_7 , V_32 ) ;
return 0 ;
}
F_30 ( 10 ) ;
}
F_6 ( V_9 , L_5 ) ;
return - V_46 ;
}
static int F_44 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_31 * V_32 = F_45 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_22 ;
F_46 ( V_7 ) ;
V_22 = F_36 ( V_7 , V_32 , 1 ) ;
if ( V_22 < 0 ) {
F_6 ( V_9 , L_6 , V_47 ) ;
return V_22 ;
}
F_47 ( V_7 ) ;
F_31 ( V_7 , V_32 ) ;
F_26 ( V_7 , V_32 ) ;
F_34 ( V_7 , V_32 ) ;
F_21 ( V_7 , 1 ) ;
F_48 ( V_7 ) ;
return V_22 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_31 * V_32 = F_45 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_22 ;
F_46 ( V_7 ) ;
V_22 = F_36 ( V_7 , V_32 , 0 ) ;
if ( V_22 < 0 ) {
F_6 ( V_9 , L_7 , V_47 ) ;
return V_22 ;
}
F_47 ( V_7 ) ;
F_31 ( V_7 , V_32 ) ;
F_34 ( V_7 , V_32 ) ;
F_25 ( V_7 , 1 ) ;
F_48 ( V_7 ) ;
return V_22 ;
}
static int F_50 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_17 == & V_48 )
F_21 ( V_7 , 0 ) ;
else
F_25 ( V_7 , 0 ) ;
V_2 -> V_21 = V_2 -> V_20 ;
* V_4 = 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
F_47 ( V_7 ) ;
V_2 -> V_17 = & V_49 ;
return V_2 -> V_17 -> V_25 ( V_2 , V_4 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_31 * V_32 = F_45 ( V_6 ) ;
if ( F_38 ( V_7 ) )
return 0 ;
F_46 ( V_7 ) ;
F_47 ( V_7 ) ;
F_36 ( V_7 , V_32 , 0 ) ;
F_31 ( V_7 , V_32 ) ;
F_34 ( V_7 , V_32 ) ;
V_2 -> V_17 = & V_50 ;
return V_2 -> V_17 -> V_25 ( V_2 , V_4 ) ;
}
static int F_53 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_31 * V_32 = F_45 ( V_6 ) ;
void T_2 * V_51 = V_6 -> V_43 + V_32 -> V_52 ;
T_3 * V_12 ;
int V_53 = F_54 ( V_7 ) ;
int V_54 ;
int V_55 , V_22 , V_13 ;
int V_56 ;
F_55 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
F_56 ( V_7 , V_2 -> V_20 ) ;
V_22 = F_36 ( V_7 , V_32 , 1 ) ;
if ( V_22 < 0 )
return 0 ;
V_22 = F_57 ( V_7 ) ;
if ( V_22 < 0 ) {
V_22 = 0 ;
goto V_57;
}
V_22 = F_28 ( V_6 , V_32 ) ;
if ( V_22 < 0 )
goto V_57;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_58 ( V_13 , V_53 ) ;
V_54 = V_13 ;
V_56 = V_54 < V_53 ;
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_59 ( V_51 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_54 - V_13 ;
}
for ( V_55 = 0 ; V_55 < V_13 ; V_55 ++ )
F_60 ( V_12 [ V_55 ] , V_51 + ( 0x03 - ( V_55 & 0x03 ) ) ) ;
V_2 -> V_21 += V_54 ;
if ( V_2 -> V_21 < V_2 -> V_20 )
* V_4 = 0 ;
else if ( V_56 )
* V_4 = 1 ;
else
* V_4 = ! V_2 -> V_14 ;
if ( V_56 )
F_26 ( V_7 , V_32 ) ;
F_21 ( V_7 , ! * V_4 ) ;
F_48 ( V_7 ) ;
F_61 ( V_9 , L_8 ,
F_37 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
if ( * V_4 ) {
if ( F_22 ( V_7 ) )
F_62 ( V_7 ) ;
}
F_34 ( V_7 , V_32 ) ;
return 0 ;
V_57:
F_34 ( V_7 , V_32 ) ;
F_21 ( V_7 , 1 ) ;
return V_22 ;
}
static int F_63 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 ) )
return 0 ;
F_55 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
F_56 ( V_7 , V_2 -> V_20 ) ;
F_48 ( V_7 ) ;
F_25 ( V_7 , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_31 * V_32 = F_45 ( V_6 ) ;
void T_2 * V_51 = V_6 -> V_43 + V_32 -> V_52 ;
T_3 * V_12 ;
T_4 V_58 = 0 ;
int V_53 = F_54 ( V_7 ) ;
int V_59 , V_13 ;
int V_55 , V_22 ;
int V_54 = 0 ;
V_22 = F_36 ( V_7 , V_32 , 0 ) ;
if ( V_22 < 0 )
return 0 ;
V_22 = F_28 ( V_6 , V_32 ) ;
if ( V_22 < 0 )
goto V_60;
V_59 = F_33 ( V_6 , V_32 ) ;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_58 ( V_13 , V_59 ) ;
V_54 = V_13 ;
V_2 -> V_21 += V_54 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_54 < V_53 ) ) {
* V_4 = 1 ;
F_25 ( V_7 , 0 ) ;
F_46 ( V_7 ) ;
}
if ( 0 == V_59 ) {
V_2 -> V_14 = 1 ;
F_31 ( V_7 , V_32 ) ;
goto V_61;
}
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_65 ( V_51 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_54 - V_13 ;
}
for ( V_55 = 0 ; V_55 < V_13 ; V_55 ++ ) {
if ( ! ( V_55 & 0x03 ) )
V_58 = F_66 ( V_51 ) ;
V_12 [ V_55 ] = ( V_58 >> ( ( V_55 & 0x03 ) * 8 ) ) & 0xff ;
}
V_61:
F_61 ( V_9 , L_9 ,
F_37 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
if ( * V_4 ) {
if ( F_22 ( V_7 ) )
F_62 ( V_7 ) ;
}
V_60:
F_34 ( V_7 , V_32 ) ;
return V_22 ;
}
static int F_67 ( struct V_1 * V_2 , int * V_4 )
{
F_62 ( V_2 -> V_7 ) ;
* V_4 = 1 ;
return 0 ;
}
static struct V_62 * F_68 ( struct V_31 * V_32 ,
struct V_1 * V_2 )
{
if ( & V_63 == V_2 -> V_17 )
return V_32 -> V_64 ;
if ( & V_65 == V_2 -> V_17 )
return V_32 -> V_66 ;
return NULL ;
}
static struct V_31 * F_69 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_31 * V_32 ;
V_32 = F_70 ( V_6 ) ;
if ( F_68 ( V_32 , V_2 ) &&
! F_39 ( V_32 ) )
return V_32 ;
V_32 = F_71 ( V_6 ) ;
if ( F_68 ( V_32 , V_2 ) &&
! F_39 ( V_32 ) )
return V_32 ;
return NULL ;
}
static void F_72 ( struct V_11 * V_7 ,
struct V_31 * V_32 ,
T_1 V_67 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_27 ( V_6 , V_32 -> V_40 , V_68 , V_67 ) ;
}
static int F_73 ( struct V_1 * V_2 , int V_69 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_70 * V_71 = F_74 ( V_6 ) ;
return V_71 -> V_72 ( V_2 , V_69 ) ;
}
static void F_75 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_76 ( V_74 , struct V_1 , V_74 ) ;
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_31 * V_32 = F_77 ( V_7 ) ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_75 * V_76 ;
struct V_62 * V_77 = F_68 ( V_32 , V_2 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
enum V_78 V_79 ;
V_79 = F_78 ( V_7 ) ? V_80 : V_81 ;
V_76 = F_79 ( V_77 , V_2 -> V_82 + V_2 -> V_21 ,
V_2 -> V_83 , V_79 ,
V_84 | V_85 ) ;
if ( ! V_76 )
return;
V_76 -> V_86 = V_87 ;
V_76 -> V_88 = V_7 ;
if ( F_80 ( V_76 ) < 0 ) {
F_6 ( V_9 , L_10 ) ;
return;
}
F_61 ( V_9 , L_11 ,
V_32 -> V_89 , F_37 ( V_7 ) , V_2 -> V_20 , V_2 -> V_14 ) ;
F_56 ( V_7 , V_2 -> V_83 ) ;
F_48 ( V_7 ) ;
F_81 ( V_7 , V_32 ) ;
F_82 ( V_77 ) ;
}
static int F_83 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_31 * V_32 ;
int V_13 = V_2 -> V_20 - V_2 -> V_21 ;
int V_22 ;
if ( F_38 ( V_7 ) )
return 0 ;
if ( ( V_13 < F_42 ( V_6 , V_90 ) ) ||
F_22 ( V_7 ) )
goto V_91;
if ( V_13 & 0x7 )
goto V_91;
if ( ( V_92 ) ( V_2 -> V_12 + V_2 -> V_21 ) & 0x7 )
goto V_91;
V_32 = F_69 ( V_6 , V_2 ) ;
if ( ! V_32 )
goto V_91;
if ( F_84 ( V_2 ) < 0 )
goto V_91;
V_22 = F_36 ( V_7 , V_32 , 0 ) ;
if ( V_22 < 0 )
goto V_93;
V_2 -> V_83 = V_13 ;
F_85 ( & V_2 -> V_74 , F_75 ) ;
F_86 ( & V_2 -> V_74 ) ;
return 0 ;
V_93:
F_87 ( V_2 ) ;
V_91:
V_2 -> V_17 = & V_49 ;
return V_2 -> V_17 -> V_25 ( V_2 , V_4 ) ;
}
static int F_88 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
V_2 -> V_21 = V_2 -> V_83 ;
* V_4 = ! V_2 -> V_14 ;
F_89 ( V_7 , V_7 -> V_32 ) ;
F_87 ( V_2 ) ;
F_34 ( V_7 , V_7 -> V_32 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_31 * V_32 ;
int V_13 , V_22 ;
if ( F_38 ( V_7 ) )
return 0 ;
if ( F_22 ( V_7 ) )
goto V_94;
V_32 = F_69 ( V_6 , V_2 ) ;
if ( ! V_32 )
goto V_94;
if ( ( V_92 ) ( V_2 -> V_12 + V_2 -> V_21 ) & 0x7 )
goto V_94;
V_22 = F_36 ( V_7 , V_32 , 0 ) ;
if ( V_22 < 0 )
goto V_94;
V_13 = F_33 ( V_6 , V_32 ) ;
V_13 = F_58 ( V_2 -> V_20 - V_2 -> V_21 , V_13 ) ;
if ( V_13 & 0x7 )
goto V_95;
if ( V_13 < F_42 ( V_6 , V_90 ) )
goto V_95;
V_22 = F_28 ( V_6 , V_32 ) ;
if ( V_22 < 0 )
goto V_95;
if ( F_84 ( V_2 ) < 0 )
goto V_95;
F_25 ( V_7 , 0 ) ;
V_2 -> V_83 = V_13 ;
F_85 ( & V_2 -> V_74 , F_75 ) ;
F_86 ( & V_2 -> V_74 ) ;
return 0 ;
V_95:
F_34 ( V_7 , V_32 ) ;
V_94:
V_2 -> V_17 = & V_50 ;
return V_2 -> V_17 -> V_27 ( V_2 , V_4 ) ;
}
static int F_91 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
int V_53 = F_54 ( V_7 ) ;
F_89 ( V_7 , V_7 -> V_32 ) ;
F_87 ( V_2 ) ;
F_34 ( V_7 , V_7 -> V_32 ) ;
V_2 -> V_21 += V_2 -> V_83 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_2 -> V_83 < V_53 ) ) {
* V_4 = 1 ;
} else {
F_63 ( V_2 , V_4 ) ;
}
return 0 ;
}
static bool F_92 ( struct V_62 * V_77 , void * V_96 )
{
struct V_97 * V_98 = V_96 ;
if ( 0 == V_98 -> V_99 . V_100 )
return false ;
V_77 -> V_101 = V_98 ;
return true ;
}
static void F_93 ( struct V_5 * V_6 , struct V_31 * V_32 )
{
if ( V_32 -> V_64 )
F_94 ( V_32 -> V_64 ) ;
if ( V_32 -> V_66 )
F_94 ( V_32 -> V_66 ) ;
V_32 -> V_64 = NULL ;
V_32 -> V_66 = NULL ;
}
static void F_95 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
T_5 V_42 ;
F_96 ( V_42 ) ;
F_97 ( V_102 , V_42 ) ;
V_32 -> V_64 = F_98 ( V_42 , F_92 ,
& V_32 -> V_103 ) ;
F_96 ( V_42 ) ;
F_97 ( V_102 , V_42 ) ;
V_32 -> V_66 = F_98 ( V_42 , F_92 ,
& V_32 -> V_104 ) ;
if ( V_32 -> V_64 || V_32 -> V_66 )
F_61 ( V_9 , L_12 ,
V_32 -> V_89 ,
V_32 -> V_64 ? L_13 : L_14 ,
V_32 -> V_66 ? L_15 : L_14 ) ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_105 * V_106 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_55 , V_22 ;
if ( ! V_106 -> V_107 ) {
F_6 ( V_9 , L_16 , V_47 ) ;
return - V_46 ;
}
F_61 ( V_9 , L_17 , V_106 -> V_107 ) ;
F_100 (pipe, priv, i) {
if ( ! ( V_106 -> V_107 & ( 1 << V_55 ) ) )
continue;
V_22 = F_18 ( V_7 , V_26 ) ;
if ( V_22 < 0 )
F_6 ( V_9 , L_18 , V_55 , V_22 ) ;
}
return 0 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_105 * V_106 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_55 , V_22 ;
if ( ! V_106 -> V_108 ) {
F_6 ( V_9 , L_16 , V_47 ) ;
return - V_46 ;
}
F_61 ( V_9 , L_19 , V_106 -> V_108 ) ;
F_100 (pipe, priv, i) {
if ( ! ( V_106 -> V_108 & ( 1 << V_55 ) ) )
continue;
V_22 = F_18 ( V_7 , V_26 ) ;
if ( V_22 < 0 )
F_6 ( V_9 , L_20 , V_55 , V_22 ) ;
}
return 0 ;
}
static void V_87 ( void * V_109 )
{
struct V_11 * V_7 = V_109 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_22 ;
V_22 = F_18 ( V_7 , V_28 ) ;
if ( V_22 < 0 )
F_6 ( V_9 , L_21 ,
F_37 ( V_7 ) , V_22 ) ;
}
void F_102 ( struct V_5 * V_6 )
{
struct V_110 * V_111 = F_103 ( V_6 ) ;
struct V_31 * V_112 = F_45 ( V_6 ) ;
struct V_31 * V_113 = F_70 ( V_6 ) ;
struct V_31 * V_114 = F_71 ( V_6 ) ;
V_111 -> V_115 = F_99 ;
V_111 -> V_116 = F_101 ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = 0 ;
V_112 -> V_7 = NULL ;
V_113 -> V_7 = NULL ;
V_114 -> V_7 = NULL ;
}
void F_104 ( struct V_5 * V_6 )
{
struct V_110 * V_111 = F_103 ( V_6 ) ;
V_111 -> V_115 = NULL ;
V_111 -> V_116 = NULL ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = 0 ;
}
int F_105 ( struct V_5 * V_6 )
{
struct V_31 * V_32 ;
V_32 = F_45 ( V_6 ) ;
V_32 -> V_89 = L_22 ;
V_32 -> V_52 = V_119 ;
V_32 -> V_40 = V_120 ;
V_32 -> V_33 = V_121 ;
V_32 = F_70 ( V_6 ) ;
V_32 -> V_89 = L_23 ;
V_32 -> V_52 = V_122 ;
V_32 -> V_40 = V_123 ;
V_32 -> V_33 = V_124 ;
V_32 -> V_103 . V_99 . V_100 = F_42 ( V_6 , V_125 ) ;
V_32 -> V_104 . V_99 . V_100 = F_42 ( V_6 , V_126 ) ;
F_95 ( V_6 , V_32 ) ;
V_32 = F_71 ( V_6 ) ;
V_32 -> V_89 = L_24 ;
V_32 -> V_52 = V_127 ;
V_32 -> V_40 = V_128 ;
V_32 -> V_33 = V_129 ;
V_32 -> V_103 . V_99 . V_100 = F_42 ( V_6 , V_130 ) ;
V_32 -> V_104 . V_99 . V_100 = F_42 ( V_6 , V_131 ) ;
F_95 ( V_6 , V_32 ) ;
return 0 ;
}
void F_106 ( struct V_5 * V_6 )
{
F_93 ( V_6 , F_70 ( V_6 ) ) ;
F_93 ( V_6 , F_71 ( V_6 ) ) ;
}
