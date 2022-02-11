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
V_26 = F_26 ( V_2 , & V_4 ) ;
if ( V_4 )
F_12 ( V_2 ) ;
V_27:
F_11 ( V_6 , V_16 ) ;
if ( V_4 ) {
V_2 -> F_8 ( V_6 , V_2 ) ;
F_27 ( V_7 ) ;
}
return V_26 ;
}
void F_27 ( struct V_11 * V_7 )
{
F_25 ( V_7 , V_28 ) ;
}
static void F_28 ( struct V_11 * V_7 , int V_34 )
{
if ( F_29 ( V_7 ) )
F_30 ( V_7 , V_34 ) ;
else
F_31 ( V_7 , V_34 ) ;
}
static void F_32 ( struct V_11 * V_7 , int V_34 )
{
F_31 ( V_7 , V_34 ) ;
}
static void F_33 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_34 ( V_6 , V_23 -> V_35 , V_36 , V_36 ) ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
int V_37 = 1024 ;
do {
if ( F_36 ( V_6 , V_23 -> V_35 ) & V_38 )
return 0 ;
F_37 ( 10 ) ;
} while ( V_37 -- );
return - V_39 ;
}
static void F_22 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
if ( ! F_29 ( V_7 ) )
F_35 ( V_6 , V_23 ) ;
F_38 ( V_6 , V_23 -> V_35 , V_40 ) ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
return F_36 ( V_6 , V_23 -> V_35 ) & V_41 ;
}
static void F_24 ( struct V_11 * V_7 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_40 ( V_7 , NULL ) ;
F_38 ( V_6 , V_23 -> V_42 , 0 ) ;
}
static int F_41 ( struct V_11 * V_7 ,
struct V_22 * V_23 ,
int V_43 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_37 = 1024 ;
T_1 V_44 = ( ( 1 << 5 ) | 0xF ) ;
T_1 V_45 = F_42 ( V_7 ) ;
if ( F_43 ( V_7 ) ||
F_44 ( V_23 ) )
return - V_39 ;
if ( F_29 ( V_7 ) ) {
V_45 |= ( 1 == V_43 ) << 5 ;
if ( F_45 ( V_6 ) )
F_46 ( V_7 , V_43 ) ;
}
if ( F_47 ( V_6 , V_46 ) && ! F_48 ( V_6 , V_23 ) )
F_38 ( V_6 , V_23 -> V_42 , V_45 ) ;
else
F_38 ( V_6 , V_23 -> V_42 , V_45 | V_47 ) ;
while ( V_37 -- ) {
if ( V_45 == ( V_44 & F_36 ( V_6 , V_23 -> V_42 ) ) ) {
F_40 ( V_7 , V_23 ) ;
return 0 ;
}
F_37 ( 10 ) ;
}
F_6 ( V_9 , L_5 ) ;
return - V_48 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
F_19 ( V_7 ) ;
V_26 = F_41 ( V_7 , V_23 , 1 ) ;
if ( V_26 < 0 ) {
F_6 ( V_9 , L_6 , V_49 ) ;
return V_26 ;
}
F_51 ( V_7 ) ;
F_22 ( V_7 , V_23 ) ;
F_33 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
F_28 ( V_7 , 1 ) ;
F_52 ( V_7 ) ;
return V_26 ;
}
static int F_53 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
F_19 ( V_7 ) ;
V_26 = F_41 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 ) {
F_6 ( V_9 , L_7 , V_49 ) ;
return V_26 ;
}
F_51 ( V_7 ) ;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
F_32 ( V_7 , 1 ) ;
F_52 ( V_7 ) ;
return V_26 ;
}
static int F_54 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_17 == & V_50 )
F_28 ( V_7 , 0 ) ;
else
F_32 ( V_7 , 0 ) ;
V_2 -> V_21 = V_2 -> V_20 ;
* V_4 = 1 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
F_51 ( V_7 ) ;
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
if ( F_43 ( V_7 ) )
return 0 ;
F_19 ( V_7 ) ;
F_51 ( V_7 ) ;
F_41 ( V_7 , V_23 , 0 ) ;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
V_2 -> V_17 = & V_52 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_57 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
void T_2 * V_53 = V_6 -> V_45 + V_23 -> V_54 ;
T_3 * V_12 ;
int V_55 = F_58 ( V_7 ) ;
int V_56 ;
int V_57 , V_26 , V_13 ;
int V_58 ;
F_59 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
F_60 ( V_7 , V_2 -> V_20 ) ;
V_26 = F_41 ( V_7 , V_23 , 1 ) ;
if ( V_26 < 0 )
return 0 ;
V_26 = F_61 ( V_7 ) ;
if ( V_26 < 0 ) {
V_26 = 0 ;
goto V_59;
}
V_26 = F_35 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_59;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_62 ( V_13 , V_55 ) ;
V_56 = V_13 ;
V_58 = V_56 < V_55 ;
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_63 ( V_53 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_56 - V_13 ;
}
for ( V_57 = 0 ; V_57 < V_13 ; V_57 ++ )
F_64 ( V_12 [ V_57 ] , V_53 + ( 0x03 - ( V_57 & 0x03 ) ) ) ;
V_2 -> V_21 += V_56 ;
if ( V_2 -> V_21 < V_2 -> V_20 )
* V_4 = 0 ;
else if ( V_58 )
* V_4 = 1 ;
else
* V_4 = ! V_2 -> V_14 ;
if ( V_58 )
F_33 ( V_7 , V_23 ) ;
F_28 ( V_7 , ! * V_4 ) ;
F_65 ( V_7 , ! * V_4 ) ;
F_52 ( V_7 ) ;
F_66 ( V_9 , L_8 ,
F_42 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
F_24 ( V_7 , V_23 ) ;
return 0 ;
V_59:
F_24 ( V_7 , V_23 ) ;
F_28 ( V_7 , 1 ) ;
F_65 ( V_7 , 1 ) ;
return V_26 ;
}
static int F_67 ( struct V_1 * V_2 , int * V_4 )
{
if ( F_68 ( V_2 -> V_7 ) )
return 0 ;
return F_57 ( V_2 , V_4 ) ;
}
static int F_69 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
if ( F_43 ( V_7 ) )
return 0 ;
if ( F_68 ( V_7 ) )
return 0 ;
F_59 ( V_7 , V_2 -> V_15 ) ;
V_2 -> V_15 = - 1 ;
F_60 ( V_7 , V_2 -> V_20 ) ;
F_52 ( V_7 ) ;
F_65 ( V_7 , 1 ) ;
F_32 ( V_7 , 1 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
void T_2 * V_53 = V_6 -> V_45 + V_23 -> V_54 ;
T_3 * V_12 ;
T_4 V_60 = 0 ;
int V_55 = F_58 ( V_7 ) ;
int V_61 , V_13 ;
int V_57 , V_26 ;
int V_56 = 0 ;
V_26 = F_41 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
return 0 ;
V_26 = F_35 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_62;
V_61 = F_39 ( V_6 , V_23 ) ;
V_12 = V_2 -> V_12 + V_2 -> V_21 ;
V_13 = V_2 -> V_20 - V_2 -> V_21 ;
V_13 = F_62 ( V_13 , V_61 ) ;
V_56 = V_13 ;
V_2 -> V_21 += V_56 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_56 < V_55 ) ) {
* V_4 = 1 ;
F_32 ( V_7 , 0 ) ;
F_65 ( V_7 , 0 ) ;
F_19 ( V_7 ) ;
}
if ( 0 == V_61 ) {
V_2 -> V_14 = 1 ;
F_22 ( V_7 , V_23 ) ;
goto V_63;
}
if ( V_13 >= 4 && ! ( ( unsigned long ) V_12 & 0x03 ) ) {
F_71 ( V_53 , V_12 , V_13 / 4 ) ;
V_13 %= 4 ;
V_12 += V_56 - V_13 ;
}
for ( V_57 = 0 ; V_57 < V_13 ; V_57 ++ ) {
if ( ! ( V_57 & 0x03 ) )
V_60 = F_72 ( V_53 ) ;
V_12 [ V_57 ] = ( V_60 >> ( ( V_57 & 0x03 ) * 8 ) ) & 0xff ;
}
V_63:
F_66 ( V_9 , L_9 ,
F_42 ( V_7 ) ,
V_2 -> V_20 , V_2 -> V_21 , * V_4 , V_2 -> V_14 ) ;
V_62:
F_24 ( V_7 , V_23 ) ;
return V_26 ;
}
static int F_73 ( struct V_1 * V_2 , int * V_4 )
{
F_74 ( V_2 -> V_7 ) ;
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
static struct V_22 * F_75 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_57 ;
F_76 (priv, fifo, i) {
if ( F_20 ( V_23 , V_2 ) &&
! F_44 ( V_23 ) )
return V_23 ;
}
return NULL ;
}
static void F_77 ( struct V_11 * V_7 ,
struct V_22 * V_23 ,
T_1 V_68 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
F_34 ( V_6 , V_23 -> V_42 , V_69 , V_68 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_70 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_71 * V_72 = F_79 ( V_6 ) ;
return V_72 -> V_73 ( V_2 , V_70 ) ;
}
static void F_80 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_81 ( V_75 , struct V_1 , V_75 ) ;
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_22 * V_23 = F_18 ( V_7 ) ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_76 * V_77 ;
struct V_24 * V_25 = F_20 ( V_23 , V_2 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
enum V_78 V_79 ;
V_79 = F_82 ( V_7 ) ? V_80 : V_81 ;
V_77 = F_83 ( V_25 , V_2 -> V_82 + V_2 -> V_21 ,
V_2 -> V_83 , V_79 ,
V_84 | V_85 ) ;
if ( ! V_77 )
return;
V_77 -> V_86 = V_87 ;
V_77 -> V_88 = V_7 ;
if ( F_84 ( V_77 ) < 0 ) {
F_6 ( V_9 , L_10 ) ;
return;
}
F_66 ( V_9 , L_11 ,
V_23 -> V_89 , F_42 ( V_7 ) , V_2 -> V_20 , V_2 -> V_14 ) ;
F_65 ( V_7 , 1 ) ;
F_60 ( V_7 , V_2 -> V_83 ) ;
F_52 ( V_7 ) ;
F_85 ( V_7 , V_23 ) ;
F_86 ( V_25 ) ;
}
static int F_87 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 ;
int V_13 = V_2 -> V_20 - V_2 -> V_21 ;
int V_26 ;
if ( F_43 ( V_7 ) )
return 0 ;
if ( ( V_13 < F_47 ( V_6 , V_90 ) ) ||
F_29 ( V_7 ) )
goto F_67;
if ( V_13 & 0x7 )
goto F_67;
if ( ( V_91 ) ( V_2 -> V_12 + V_2 -> V_21 ) & 0x7 )
goto F_67;
if ( F_68 ( V_7 ) )
return 0 ;
V_23 = F_75 ( V_6 , V_2 ) ;
if ( ! V_23 )
goto F_67;
if ( F_88 ( V_2 ) < 0 )
goto F_67;
V_26 = F_41 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
goto V_92;
V_2 -> V_83 = V_13 ;
F_89 ( & V_2 -> V_75 , F_80 ) ;
F_90 ( & V_2 -> V_75 ) ;
return 0 ;
V_92:
F_23 ( V_2 ) ;
F_67:
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_29 ( V_2 , V_4 ) ;
}
static int F_91 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
int V_58 = V_2 -> V_83 % F_58 ( V_7 ) ;
V_2 -> V_21 += V_2 -> V_83 ;
if ( V_2 -> V_21 < V_2 -> V_20 )
* V_4 = 0 ;
else if ( V_58 )
* V_4 = 1 ;
else
* V_4 = ! V_2 -> V_14 ;
F_65 ( V_7 , ! * V_4 ) ;
F_92 ( V_7 , V_7 -> V_23 ) ;
F_23 ( V_2 ) ;
F_24 ( V_7 , V_7 -> V_23 ) ;
if ( ! * V_4 ) {
V_2 -> V_17 = & V_51 ;
return V_2 -> V_17 -> V_31 ( V_2 , V_4 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 ;
int V_13 , V_26 ;
if ( F_43 ( V_7 ) )
return 0 ;
if ( F_29 ( V_7 ) )
goto V_93;
V_23 = F_75 ( V_6 , V_2 ) ;
if ( ! V_23 )
goto V_93;
if ( ( V_91 ) ( V_2 -> V_12 + V_2 -> V_21 ) & 0x7 )
goto V_93;
V_26 = F_41 ( V_7 , V_23 , 0 ) ;
if ( V_26 < 0 )
goto V_93;
V_13 = F_39 ( V_6 , V_23 ) ;
V_13 = F_62 ( V_2 -> V_20 - V_2 -> V_21 , V_13 ) ;
if ( V_13 & 0x7 )
goto V_94;
if ( V_13 < F_47 ( V_6 , V_90 ) )
goto V_94;
V_26 = F_35 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_94;
if ( F_88 ( V_2 ) < 0 )
goto V_94;
F_32 ( V_7 , 0 ) ;
V_2 -> V_83 = V_13 ;
F_89 ( & V_2 -> V_75 , F_80 ) ;
F_90 ( & V_2 -> V_75 ) ;
return 0 ;
V_94:
F_24 ( V_7 , V_23 ) ;
V_93:
V_2 -> V_17 = & V_52 ;
return V_2 -> V_17 -> V_31 ( V_2 , V_4 ) ;
}
static int F_94 ( struct V_1 * V_2 , int * V_4 )
{
struct V_11 * V_7 = V_2 -> V_7 ;
int V_55 = F_58 ( V_7 ) ;
F_92 ( V_7 , V_7 -> V_23 ) ;
F_23 ( V_2 ) ;
F_24 ( V_7 , V_7 -> V_23 ) ;
V_2 -> V_21 += V_2 -> V_83 ;
if ( ( V_2 -> V_21 == V_2 -> V_20 ) ||
( V_2 -> V_83 < V_55 ) ) {
* V_4 = 1 ;
F_65 ( V_7 , 0 ) ;
} else {
F_65 ( V_7 , 0 ) ;
F_69 ( V_2 , V_4 ) ;
}
return 0 ;
}
static bool F_95 ( struct V_24 * V_25 , void * V_95 )
{
struct V_96 * V_97 = V_95 ;
if ( 0 == V_97 -> V_98 . V_99 )
return false ;
V_25 -> V_100 = V_97 ;
return true ;
}
static void F_96 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
if ( V_23 -> V_65 )
F_97 ( V_23 -> V_65 ) ;
if ( V_23 -> V_67 )
F_97 ( V_23 -> V_67 ) ;
V_23 -> V_65 = NULL ;
V_23 -> V_67 = NULL ;
}
static void F_98 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
T_5 V_44 ;
F_99 ( V_44 ) ;
F_100 ( V_101 , V_44 ) ;
V_23 -> V_65 = F_101 ( V_44 , F_95 ,
& V_23 -> V_102 ) ;
F_99 ( V_44 ) ;
F_100 ( V_101 , V_44 ) ;
V_23 -> V_67 = F_101 ( V_44 , F_95 ,
& V_23 -> V_103 ) ;
if ( V_23 -> V_65 || V_23 -> V_67 )
F_66 ( V_9 , L_12 ,
V_23 -> V_89 ,
V_23 -> V_65 ? L_13 : L_14 ,
V_23 -> V_67 ? L_15 : L_14 ) ;
}
static int F_102 ( struct V_5 * V_6 ,
struct V_104 * V_105 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_57 , V_26 ;
if ( ! V_105 -> V_106 ) {
F_6 ( V_9 , L_16 , V_49 ) ;
return - V_48 ;
}
F_66 ( V_9 , L_17 , V_105 -> V_106 ) ;
F_103 (pipe, priv, i) {
if ( ! ( V_105 -> V_106 & ( 1 << V_57 ) ) )
continue;
V_26 = F_25 ( V_7 , V_30 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_18 , V_57 , V_26 ) ;
}
return 0 ;
}
static int F_104 ( struct V_5 * V_6 ,
struct V_104 * V_105 )
{
struct V_11 * V_7 ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_57 , V_26 ;
if ( ! V_105 -> V_107 ) {
F_6 ( V_9 , L_16 , V_49 ) ;
return - V_48 ;
}
F_66 ( V_9 , L_19 , V_105 -> V_107 ) ;
F_103 (pipe, priv, i) {
if ( ! ( V_105 -> V_107 & ( 1 << V_57 ) ) )
continue;
V_26 = F_25 ( V_7 , V_30 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_20 , V_57 , V_26 ) ;
}
return 0 ;
}
static void V_87 ( void * V_108 )
{
struct V_11 * V_7 = V_108 ;
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_8 * V_9 = F_5 ( V_6 ) ;
int V_26 ;
V_26 = F_25 ( V_7 , V_32 ) ;
if ( V_26 < 0 )
F_6 ( V_9 , L_21 ,
F_42 ( V_7 ) , V_26 ) ;
}
void F_105 ( struct V_11 * V_7 )
{
struct V_5 * V_6 = F_4 ( V_7 ) ;
struct V_22 * V_23 = F_50 ( V_6 ) ;
if ( F_41 ( V_7 , V_23 , 1 ) < 0 )
return;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
if ( F_41 ( V_7 , V_23 , 0 ) < 0 )
return;
F_22 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_23 ) ;
}
void F_106 ( struct V_5 * V_6 )
{
struct V_109 * V_110 = F_107 ( V_6 ) ;
struct V_22 * V_111 = F_50 ( V_6 ) ;
struct V_22 * V_112 ;
int V_57 ;
V_110 -> V_113 = F_102 ;
V_110 -> V_114 = F_104 ;
V_110 -> V_115 = 0 ;
V_110 -> V_116 = 0 ;
V_111 -> V_7 = NULL ;
F_76 (priv, dfifo, i)
V_112 -> V_7 = NULL ;
}
void F_108 ( struct V_5 * V_6 )
{
struct V_109 * V_110 = F_107 ( V_6 ) ;
V_110 -> V_113 = NULL ;
V_110 -> V_114 = NULL ;
V_110 -> V_115 = 0 ;
V_110 -> V_116 = 0 ;
}
int F_109 ( struct V_5 * V_6 )
{
struct V_22 * V_23 ;
V_23 = F_50 ( V_6 ) ;
V_23 -> V_89 = L_22 ;
V_23 -> V_54 = V_117 ;
V_23 -> V_42 = V_118 ;
V_23 -> V_35 = V_119 ;
F_110 ( V_6 , V_23 , 0 ) ;
F_110 ( V_6 , V_23 , 1 ) ;
F_111 ( V_6 , V_23 , 2 ) ;
F_111 ( V_6 , V_23 , 3 ) ;
return 0 ;
}
void F_112 ( struct V_5 * V_6 )
{
struct V_22 * V_23 ;
int V_57 ;
F_76 (priv, fifo, i)
F_96 ( V_6 , V_23 ) ;
}
