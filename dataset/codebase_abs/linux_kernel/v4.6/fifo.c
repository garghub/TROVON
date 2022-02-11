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
struct V_22 * V_23 = F_18 ( V_7 ) ;
unsigned long V_16 ;
F_9 ( V_6 , V_16 ) ;
F_19 ( V_7 ) ;
if ( ! V_2 )
V_2 = F_14 ( V_7 ) ;
if ( V_2 ) {
struct V_24 * V_25 = NULL ;
if ( V_23 )
V_25 = F_20 ( V_23 , V_2 ) ;
if ( V_25 ) {
F_21 ( V_25 ) ;
F_22 ( V_7 , V_23 ) ;
F_23 ( V_2 ) ;
}
F_12 ( V_2 ) ;
}
if ( V_23 )
F_24 ( V_7 , V_23 ) ;
F_11 ( V_6 , V_16 ) ;
return V_2 ;
}
static int F_25 ( struct V_11 * V_7 , int type )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int (* F_26)( struct V_1 * V_2 , int * V_4 );
unsigned long V_16 ;
int V_26 = 0 ;
int V_4 = 0 ;
F_9 ( V_6 , V_16 ) ;
V_2 = F_14 ( V_7 ) ;
if ( ! V_2 )
goto V_27;
switch ( type ) {
case V_28 :
F_26 = V_2 -> V_17 -> V_29 ;
break;
case V_30 :
F_26 = V_2 -> V_17 -> V_31 ;
break;
case V_32 :
F_26 = V_2 -> V_17 -> V_33 ;
break;
default:
F_6 ( V_9 , L_4 ) ;
goto V_27;
}
if ( F_27 ( F_26 ) )
V_26 = F_26 ( V_2 , & V_4 ) ;
if ( V_4 )
F_12 ( V_2 ) ;
V_27:
F_11 ( V_6 , V_16 ) ;
if ( V_4 ) {
V_2 -> F_8 ( V_6 , V_2 ) ;
F_28 ( V_7 ) ;
}
return V_26 ;
}
void F_28 ( struct V_11 * V_7 )
{
F_25 ( V_7 , V_28 ) ;
}
static void F_29 ( struct V_11 * V_7 , int V_34 )
{
if ( F_30 ( V_7 ) )
F_31 ( V_7 , V_34 ) ;
else
F_32 ( V_7 , V_34 ) ;
}
static void F_33 ( struct V_11 * V_7 , int V_34 )
{
F_32 ( V_7 , V_34 ) ;
}
static void F_34 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_35 ( V_6 , V_23 -> V_35 , V_36 , V_36 ) ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
int V_37 = 1024 ;
do {
if ( F_37 ( V_6 , V_23 -> V_35 ) & V_38 )
return 0 ;
F_38 ( 10 ) ;
} while ( V_37 -- );
return - V_39 ;
}
static void F_22 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
if ( ! F_30 ( V_7 ) )
F_36 ( V_6 , V_23 ) ;
F_39 ( V_6 , V_23 -> V_35 , V_40 ) ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
return F_37 ( V_6 , V_23 -> V_35 ) & V_41 ;
}
static void F_24 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_41 ( V_7 , NULL ) ;
F_39 ( V_6 , V_23 -> V_42 , 0 ) ;
}
static int F_42 ( struct V_11 * V_7 ,
struct V_22 * V_23 ,
int V_43 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_37 = 1024 ;
T_1 V_44 = ( ( 1 << 5 ) | 0xF ) ;
T_1 V_45 = F_43 ( V_7 ) ;
if ( F_44 ( V_7 ) ||
F_45 ( V_23 ) )
return - V_39 ;
if ( F_30 ( V_7 ) ) {
V_45 |= ( 1 == V_43 ) << 5 ;
if ( F_46 ( V_6 ) )
F_47 ( V_7 , V_43 ) ;
}
if ( F_48 ( V_6 , V_46 ) && ! F_49 ( V_6 , V_23 ) )
F_39 ( V_6 , V_23 -> V_42 , V_45 ) ;
else
F_39 ( V_6 , V_23 -> V_42 , V_45 | V_47 ) ;
while ( V_37 -- ) {
if ( V_45 == ( V_44 & F_37 ( V_6 , V_23 -> V_42 ) ) ) {
F_41 ( V_7 , V_23 ) ;
return 0 ;
}
F_38 ( 10 ) ;
}
F_6 ( V_9 , L_5 ) ;
return - V_48 ;
}
static int F_50 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
F_19 ( V_7 ) ;
V_26 = F_42 ( V_7 , V_23 , 1 ) ;
if ( V_26 < 0 ) {
F_6 ( V_9 , L_6 , V_49 ) ;
return V_26 ;
}
F_52 ( V_7 ) ;
F_22 ( V_7 , V_23 ) ;
F_34 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
F_29 ( V_7 , 1 ) ;
F_53 ( V_7 ) ;
return V_26 ;
}
static int F_54 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
F_19 ( V_7 ) ;
V_26 = F_42 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 ) {
F_6 ( V_9 , L_7 , V_49 ) ;
return V_26 ;
}
F_52 ( V_7 ) ;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
F_33 ( V_7 , 1 ) ;
F_53 ( V_7 ) ;
return V_26 ;
}
static int F_55 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_17 == & V_50 )
F_29 ( V_7 , 0 ) ;
else
F_33 ( V_7 , 0 ) ;
V_2 -> V_21 = V_2 -> V_20 ;
* V_4 = 1 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
F_52 ( V_7 ) ;
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
if ( F_44 ( V_7 ) )
return 0 ;
F_19 ( V_7 ) ;
F_52 ( V_7 ) ;
F_42 ( V_7 , V_23 , 0 ) ;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
V_2 -> V_17 = & V_52 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_58 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
void T_2 * V_53 = V_6 -> V_45 + V_23 -> V_54 ;
T_3 * V_12 ;
int V_55 = F_59 ( V_7 ) ;
int V_56 ;
int V_57 , V_26 , V_13 ;
int V_58 ;
F_60 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
F_61 ( V_7 , V_2 -> V_20 ) ;
V_26 = F_42 ( V_7 , V_23 , 1 ) ;
if ( V_26 < 0 )
return 0 ;
V_26 = F_62 ( V_7 ) ;
if ( V_26 < 0 ) {
V_26 = 0 ;
goto V_59;
}
V_26 = F_36 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_59;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_63 ( V_13 , V_55 ) ;
V_56 = V_13 ;
V_58 = V_56 < V_55 ;
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_64 ( V_53 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_56 - V_13 ;
}
for ( V_57 = 0 ; V_57 < V_13 ; V_57 ++ )
F_65 ( V_12 [ V_57 ] , V_53 + ( 0x03 - ( V_57 & 0x03 ) ) ) ;
V_2 -> V_21 += V_56 ;
if ( V_2 -> V_21 < V_2 -> V_20 )
* V_4 = 0 ;
else if ( V_58 )
* V_4 = 1 ;
else
* V_4 = ! V_2 -> V_14 ;
if ( V_58 )
F_34 ( V_7 , V_23 ) ;
F_29 ( V_7 , ! * V_4 ) ;
F_66 ( V_7 , ! * V_4 ) ;
F_53 ( V_7 ) ;
F_67 ( V_9 , L_8 ,
F_43 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
F_24 ( V_7 , V_23 ) ;
return 0 ;
V_59:
F_24 ( V_7 , V_23 ) ;
F_29 ( V_7 , 1 ) ;
F_66 ( V_7 , 1 ) ;
return V_26 ;
}
static int F_68 ( struct V_1 * V_2 , int * V_4 )
{
if ( F_69 ( V_2 -> V_7 ) )
return 0 ;
return F_58 ( V_2 , V_4 ) ;
}
static int F_70 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
if ( F_44 ( V_7 ) )
return 0 ;
if ( F_69 ( V_7 ) )
return 0 ;
F_60 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
if ( F_30 ( V_7 ) )
F_22 ( V_7 , V_23 ) ;
F_61 ( V_7 , V_2 -> V_20 ) ;
F_53 ( V_7 ) ;
F_66 ( V_7 , 1 ) ;
F_33 ( V_7 , 1 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
void T_2 * V_53 = V_6 -> V_45 + V_23 -> V_54 ;
T_3 * V_12 ;
T_4 V_60 = 0 ;
int V_55 = F_59 ( V_7 ) ;
int V_61 , V_13 ;
int V_57 , V_26 ;
int V_56 = 0 ;
V_26 = F_42 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
return 0 ;
V_26 = F_36 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_62;
V_61 = F_40 ( V_6 , V_23 ) ;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_63 ( V_13 , V_61 ) ;
V_56 = V_13 ;
V_2 -> V_21 += V_56 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_56 < V_55 ) ) {
* V_4 = 1 ;
F_33 ( V_7 , 0 ) ;
F_66 ( V_7 , 0 ) ;
if ( ! F_46 ( V_6 ) && ! F_30 ( V_7 ) )
F_19 ( V_7 ) ;
}
if ( 0 == V_61 ) {
V_2 -> V_14 = 1 ;
F_22 ( V_7 , V_23 ) ;
goto V_63;
}
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_72 ( V_53 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_56 - V_13 ;
}
for ( V_57 = 0 ; V_57 < V_13 ; V_57 ++ ) {
if ( ! ( V_57 & 0x03 ) )
V_60 = F_73 ( V_53 ) ;
V_12 [ V_57 ] = ( V_60 >> ( ( V_57 & 0x03 ) * 8 ) ) & 0xff ;
}
V_63:
F_67 ( V_9 , L_9 ,
F_43 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
V_62:
F_24 ( V_7 , V_23 ) ;
return V_26 ;
}
static int F_74 ( struct V_1 * V_2 , int * V_4 )
{
F_75 ( V_2 -> V_7 ) ;
* V_4 = 1 ;
return 0 ;
}
static struct V_24 * F_20 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
if ( & V_64 == V_2 -> V_17 )
return V_23 -> V_65 ;
if ( & V_66 == V_2 -> V_17 )
return V_23 -> V_67 ;
return NULL ;
}
static struct V_22 * F_76 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_57 ;
F_77 (priv, fifo, i) {
if ( F_20 ( V_23 , V_2 ) &&
! F_45 ( V_23 ) )
return V_23 ;
}
return NULL ;
}
static void F_78 ( struct V_11 * V_7 ,
struct V_22 * V_23 ,
T_1 V_68 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_35 ( V_6 , V_23 -> V_42 , V_69 , V_68 ) ;
}
static int F_79 ( struct V_1 * V_2 , int V_70 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_71 * V_72 = F_80 ( V_6 ) ;
return V_72 -> V_73 ( V_2 , V_70 ) ;
}
static void F_81 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_82 ( V_75 , struct V_1 , V_75 ) ;
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_22 * V_23 = F_18 ( V_7 ) ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_76 * V_77 ;
struct V_24 * V_25 = F_20 ( V_23 , V_2 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
enum V_78 V_79 ;
V_79 = F_83 ( V_7 ) ? V_80 : V_81 ;
V_77 = F_84 ( V_25 , V_2 -> V_82 + V_2 -> V_21 ,
V_2 -> V_83 , V_79 ,
V_84 | V_85 ) ;
if ( ! V_77 )
return;
V_77 -> V_86 = V_87 ;
V_77 -> V_88 = V_7 ;
V_2 -> V_89 = F_85 ( V_77 ) ;
if ( V_2 -> V_89 < 0 ) {
F_6 ( V_9 , L_10 ) ;
return;
}
F_67 ( V_9 , L_11 ,
V_23 -> V_90 , F_43 ( V_7 ) , V_2 -> V_20 , V_2 -> V_14 ) ;
F_66 ( V_7 , 1 ) ;
F_86 ( V_7 , V_23 ) ;
F_61 ( V_7 , V_2 -> V_83 ) ;
F_87 ( V_25 ) ;
F_53 ( V_7 ) ;
}
static int F_88 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 ;
int V_13 = V_2 -> V_20 - V_2 -> V_21 ;
int V_26 ;
T_5 V_91 ;
if ( F_44 ( V_7 ) )
return 0 ;
if ( ( V_13 < F_48 ( V_6 , V_92 ) ) ||
F_30 ( V_7 ) )
goto F_68;
if ( ! F_48 ( V_6 , V_93 ) && V_13 & 0x7 )
goto F_68;
V_91 = F_48 ( V_6 , V_93 ) ?
V_94 - 1 : 0x7 ;
if ( ( T_5 ) ( V_2 -> V_12 + V_2 -> V_21 ) & V_91 )
goto F_68;
if ( F_69 ( V_7 ) )
return 0 ;
V_23 = F_76 ( V_6 , V_2 ) ;
if ( ! V_23 )
goto F_68;
if ( F_89 ( V_2 ) < 0 )
goto F_68;
V_26 = F_42 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
goto V_95;
V_2 -> V_83 = V_13 ;
F_29 ( V_7 , 0 ) ;
F_90 ( & V_2 -> V_75 , F_81 ) ;
F_91 ( & V_2 -> V_75 ) ;
return 0 ;
V_95:
F_23 ( V_2 ) ;
F_68:
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_92 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
int V_58 = V_2 -> V_83 % F_59 ( V_7 ) ;
V_2 -> V_21 += V_2 -> V_83 ;
if ( V_2 -> V_21 < V_2 -> V_20 )
* V_4 = 0 ;
else if ( V_58 )
* V_4 = 1 ;
else
* V_4 = ! V_2 -> V_14 ;
F_66 ( V_7 , ! * V_4 ) ;
F_93 ( V_7 , V_7 -> V_23 ) ;
F_23 ( V_2 ) ;
F_24 ( V_7 , V_7 -> V_23 ) ;
if ( ! * V_4 ) {
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_31 ( V_2 , V_4 ) ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
int * V_4 )
{
return F_70 ( V_2 , V_4 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 ;
int V_26 ;
if ( F_44 ( V_7 ) )
return 0 ;
if ( ( V_2 -> V_20 < F_48 ( V_6 , V_92 ) ) ||
F_30 ( V_7 ) )
goto V_96;
V_23 = F_76 ( V_6 , V_2 ) ;
if ( ! V_23 )
goto V_96;
if ( ( T_5 ) V_2 -> V_12 & ( V_94 - 1 ) )
goto V_96;
F_96 ( V_7 , 1 ) ;
V_26 = F_42 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
goto V_96;
if ( F_89 ( V_2 ) < 0 )
goto V_97;
F_33 ( V_7 , 0 ) ;
V_2 -> V_83 = V_2 -> V_20 ;
F_90 ( & V_2 -> V_75 , F_81 ) ;
F_91 ( & V_2 -> V_75 ) ;
return 0 ;
V_97:
F_24 ( V_7 , V_23 ) ;
V_96:
V_2 -> V_17 = & V_52 ;
F_96 ( V_7 , 0 ) ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_97 ( struct V_1 * V_2 , int * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( F_48 ( V_6 , V_93 ) )
return F_95 ( V_2 , V_4 ) ;
else
return F_94 ( V_2 , V_4 ) ;
}
static int F_98 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 ;
int V_13 , V_26 ;
if ( F_44 ( V_7 ) )
return 0 ;
if ( F_30 ( V_7 ) )
goto V_96;
V_23 = F_76 ( V_6 , V_2 ) ;
if ( ! V_23 )
goto V_96;
if ( ( T_5 ) ( V_2 -> V_12 + V_2 -> V_21 ) & 0x7 )
goto V_96;
V_26 = F_42 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
goto V_96;
V_13 = F_40 ( V_6 , V_23 ) ;
V_13 = F_63 ( V_2 -> V_20 - V_2 -> V_21 , V_13 ) ;
if ( V_13 & 0x7 )
goto V_97;
if ( V_13 < F_48 ( V_6 , V_92 ) )
goto V_97;
V_26 = F_36 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_97;
if ( F_89 ( V_2 ) < 0 )
goto V_97;
F_33 ( V_7 , 0 ) ;
V_2 -> V_83 = V_13 ;
F_90 ( & V_2 -> V_75 , F_81 ) ;
F_91 ( & V_2 -> V_75 ) ;
return 0 ;
V_97:
F_24 ( V_7 , V_23 ) ;
V_96:
V_2 -> V_17 = & V_52 ;
return V_2 -> V_17 -> V_31 ( V_2 , V_4 ) ;
}
static int F_99 ( struct V_1 * V_2 , int * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
F_100 ( F_48 ( V_6 , V_93 ) ) ;
return F_98 ( V_2 , V_4 ) ;
}
static int F_101 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
int V_55 = F_59 ( V_7 ) ;
F_93 ( V_7 , V_7 -> V_23 ) ;
F_23 ( V_2 ) ;
F_24 ( V_7 , V_7 -> V_23 ) ;
V_2 -> V_21 += V_2 -> V_83 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_2 -> V_83 < V_55 ) ) {
* V_4 = 1 ;
F_66 ( V_7 , 0 ) ;
} else {
F_66 ( V_7 , 0 ) ;
F_70 ( V_2 , V_4 ) ;
}
return 0 ;
}
static T_6 F_102 ( struct V_1 * V_2 ,
struct V_24 * V_25 , int V_98 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_99 V_100 ;
T_6 V_101 ;
int V_55 = F_59 ( V_7 ) ;
F_103 ( V_25 , V_2 -> V_89 , & V_100 ) ;
V_101 = V_2 -> V_20 - V_100 . V_102 ;
if ( V_98 ) {
V_101 -= V_94 ;
V_101 &= ~ ( V_55 - 1 ) ;
V_101 += V_98 ;
}
return V_101 ;
}
static int F_104 ( struct V_1 * V_2 ,
int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_18 ( V_7 ) ;
struct V_24 * V_25 = F_20 ( V_23 , V_2 ) ;
int V_61 ;
F_105 ( V_6 , V_103 , F_43 ( V_7 ) ) ;
V_61 = F_40 ( V_6 , V_23 ) ;
F_22 ( V_7 , V_23 ) ;
V_2 -> V_21 = F_102 ( V_2 , V_25 , V_61 ) ;
F_93 ( V_7 , V_23 ) ;
F_23 ( V_2 ) ;
F_24 ( V_7 , V_7 -> V_23 ) ;
* V_4 = 1 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , int * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 -> V_7 ) ;
if ( F_48 ( V_6 , V_93 ) )
return F_104 ( V_2 , V_4 ) ;
else
return F_101 ( V_2 , V_4 ) ;
}
static bool F_107 ( struct V_24 * V_25 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
if ( 0 == V_106 -> V_107 . V_108 )
return false ;
V_25 -> V_109 = V_106 ;
return true ;
}
static void F_108 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
if ( V_23 -> V_65 )
F_109 ( V_23 -> V_65 ) ;
if ( V_23 -> V_67 )
F_109 ( V_23 -> V_67 ) ;
V_23 -> V_65 = NULL ;
V_23 -> V_67 = NULL ;
}
static void F_110 ( struct V_22 * V_23 )
{
T_7 V_44 ;
F_111 ( V_44 ) ;
F_112 ( V_110 , V_44 ) ;
V_23 -> V_65 = F_113 ( V_44 , F_107 ,
& V_23 -> V_111 ) ;
F_111 ( V_44 ) ;
F_112 ( V_110 , V_44 ) ;
V_23 -> V_67 = F_113 ( V_44 , F_107 ,
& V_23 -> V_112 ) ;
}
static void F_114 ( struct V_8 * V_9 , struct V_22 * V_23 ,
int V_113 )
{
char V_90 [ 16 ] ;
snprintf ( V_90 , sizeof( V_90 ) , L_12 , V_113 ) ;
if ( V_113 & 1 ) {
V_23 -> V_65 = F_115 ( V_9 , V_90 ) ;
if ( F_116 ( V_23 -> V_65 ) )
V_23 -> V_65 = NULL ;
} else {
V_23 -> V_67 = F_115 ( V_9 , V_90 ) ;
if ( F_116 ( V_23 -> V_67 ) )
V_23 -> V_67 = NULL ;
}
}
static void F_117 ( struct V_5 * V_6 , struct V_22 * V_23 ,
int V_113 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_9 -> V_114 )
F_114 ( V_9 , V_23 , V_113 ) ;
else
F_110 ( V_23 ) ;
if ( V_23 -> V_65 || V_23 -> V_67 )
F_67 ( V_9 , L_13 ,
V_23 -> V_90 ,
V_23 -> V_65 ? L_14 : L_15 ,
V_23 -> V_67 ? L_16 : L_15 ) ;
}
static int F_118 ( struct V_5 * V_6 ,
struct V_115 * V_116 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_57 , V_26 ;
if ( ! V_116 -> V_117 ) {
F_6 ( V_9 , L_17 , V_49 ) ;
return - V_48 ;
}
F_67 ( V_9 , L_18 , V_116 -> V_117 ) ;
F_119 (pipe, priv, i) {
if ( ! ( V_116 -> V_117 & ( 1 << V_57 ) ) )
continue;
V_26 = F_25 ( V_7 , V_30 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_19 , V_57 , V_26 ) ;
}
return 0 ;
}
static int F_120 ( struct V_5 * V_6 ,
struct V_115 * V_116 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_57 , V_26 ;
if ( ! V_116 -> V_118 ) {
F_6 ( V_9 , L_17 , V_49 ) ;
return - V_48 ;
}
F_67 ( V_9 , L_20 , V_116 -> V_118 ) ;
F_119 (pipe, priv, i) {
if ( ! ( V_116 -> V_118 & ( 1 << V_57 ) ) )
continue;
V_26 = F_25 ( V_7 , V_30 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_21 , V_57 , V_26 ) ;
}
return 0 ;
}
static void V_87 ( void * V_119 )
{
struct V_11 * V_7 = V_119 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
V_26 = F_25 ( V_7 , V_32 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_22 ,
F_43 ( V_7 ) , V_26 ) ;
}
void F_121 ( struct V_11 * V_7 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_51 ( V_6 ) ;
if ( F_42 ( V_7 , V_23 , 1 ) < 0 )
return;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
if ( F_42 ( V_7 , V_23 , 0 ) < 0 )
return;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
}
void F_122 ( struct V_5 * V_6 )
{
struct V_120 * V_121 = F_123 ( V_6 ) ;
struct V_22 * V_122 = F_51 ( V_6 ) ;
struct V_22 * V_123 ;
int V_57 ;
V_121 -> V_124 = F_118 ;
V_121 -> V_125 = F_120 ;
V_121 -> V_126 = 0 ;
V_121 -> V_127 = 0 ;
V_122 -> V_7 = NULL ;
F_77 (priv, dfifo, i)
V_123 -> V_7 = NULL ;
}
void F_124 ( struct V_5 * V_6 )
{
struct V_120 * V_121 = F_123 ( V_6 ) ;
V_121 -> V_124 = NULL ;
V_121 -> V_125 = NULL ;
V_121 -> V_126 = 0 ;
V_121 -> V_127 = 0 ;
}
int F_125 ( struct V_5 * V_6 )
{
struct V_22 * V_23 ;
V_23 = F_51 ( V_6 ) ;
V_23 -> V_90 = L_23 ;
V_23 -> V_54 = V_128 ;
V_23 -> V_42 = V_129 ;
V_23 -> V_35 = V_130 ;
F_126 ( V_6 , V_23 , 0 ) ;
F_126 ( V_6 , V_23 , 1 ) ;
F_127 ( V_6 , V_23 , 2 ) ;
F_127 ( V_6 , V_23 , 3 ) ;
return 0 ;
}
void F_128 ( struct V_5 * V_6 )
{
struct V_22 * V_23 ;
int V_57 ;
F_77 (priv, fifo, i)
F_108 ( V_6 , V_23 ) ;
}
