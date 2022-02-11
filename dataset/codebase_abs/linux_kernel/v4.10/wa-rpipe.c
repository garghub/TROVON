static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_6 = F_2 (
V_2 -> V_10 , F_3 ( V_2 -> V_10 , 0 ) ,
V_11 ,
V_12 | V_13 | V_14 ,
V_15 << 8 , V_5 , V_4 , sizeof( * V_4 ) ,
V_16 ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_1 ,
V_5 , ( int ) V_6 ) ;
goto error;
}
if ( V_6 < sizeof( * V_4 ) ) {
F_4 ( V_8 , L_2
L_3 ,
V_5 , V_6 , sizeof( * V_4 ) ) ;
V_6 = - V_17 ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_6 = F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_18 ,
V_19 | V_13 | V_14 ,
V_15 << 8 , V_5 , V_4 , sizeof( * V_4 ) ,
V_20 ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_4 ,
V_5 , ( int ) V_6 ) ;
goto error;
}
if ( V_6 < sizeof( * V_4 ) ) {
F_4 ( V_8 , L_5
L_6 ,
V_5 , V_6 , sizeof( * V_4 ) ) ;
V_6 = - V_17 ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static void F_7 ( struct V_21 * V_22 )
{
F_8 ( & V_22 -> V_23 ) ;
F_9 ( & V_22 -> V_24 ) ;
F_10 ( & V_22 -> V_25 ) ;
F_10 ( & V_22 -> V_26 ) ;
}
static unsigned F_11 ( struct V_1 * V_2 , unsigned V_27 )
{
unsigned long V_28 ;
F_12 ( & V_2 -> V_29 , V_28 ) ;
V_27 = F_13 ( V_2 -> V_30 , V_2 -> V_31 , V_27 ) ;
if ( V_27 < V_2 -> V_31 )
F_14 ( V_27 , V_2 -> V_30 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
return V_27 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned V_27 )
{
unsigned long V_28 ;
F_12 ( & V_2 -> V_29 , V_28 ) ;
F_17 ( V_27 , V_2 -> V_30 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
}
void F_18 ( struct V_32 * V_33 )
{
struct V_21 * V_22 = F_19 ( V_33 , struct V_21 , V_23 ) ;
T_3 V_5 = F_20 ( V_22 -> V_4 . V_34 ) ;
if ( V_22 -> V_35 )
V_22 -> V_35 -> V_36 = NULL ;
F_16 ( V_22 -> V_2 , V_5 ) ;
F_21 ( V_22 -> V_2 ) ;
F_22 ( V_22 ) ;
}
static int F_23 ( struct V_21 * * V_37 , struct V_1 * V_2 , T_3 V_38 ,
T_4 V_39 )
{
int V_6 ;
unsigned V_27 ;
struct V_21 * V_22 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_22 = F_24 ( sizeof( * V_22 ) , V_39 ) ;
if ( V_22 == NULL )
return - V_40 ;
F_7 ( V_22 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_31 ; V_27 ++ ) {
V_27 = F_11 ( V_2 , V_27 ) ;
if ( V_27 >= V_2 -> V_31 )
break;
V_6 = F_1 ( V_2 , & V_22 -> V_4 , V_27 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_7 ,
V_27 , V_6 ) ;
else if ( ( V_22 -> V_4 . V_41 & V_38 ) != 0 )
goto V_42;
F_16 ( V_2 , V_27 ) ;
}
* V_37 = NULL ;
F_22 ( V_22 ) ;
return - V_43 ;
V_42:
F_14 ( V_27 , V_2 -> V_30 ) ;
V_22 -> V_2 = F_25 ( V_2 ) ;
* V_37 = V_22 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned V_5 )
{
int V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_6 = F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_44 ,
V_19 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , V_20 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_8 ,
V_5 , V_6 ) ;
return V_6 ;
}
static struct V_45 * F_27 (
struct V_7 * V_8 , struct V_46 * V_35 )
{
void * V_47 ;
T_5 V_48 ;
struct V_49 * V_50 ;
struct V_45 * V_51 ;
if ( V_35 -> V_52 . V_53 == 0 ) {
V_51 = & V_54 ;
goto V_55;
}
V_47 = V_35 -> V_56 ;
V_48 = V_35 -> V_57 ;
V_51 = NULL ;
while ( V_48 > 0 ) {
if ( V_48 < sizeof( * V_50 ) ) {
F_4 ( V_8 , L_9
L_10 ,
V_35 -> V_52 . V_53 ,
V_47 - ( void * ) V_35 -> V_56 , V_48 ) ;
break;
}
V_50 = V_47 ;
if ( V_50 -> V_58 == V_59 ) {
V_51 = V_47 ;
break;
}
if ( V_50 -> V_60 > V_48 ) {
F_4 ( V_8 , L_11
L_12
L_13 ,
V_35 -> V_52 . V_53 ,
V_47 - ( void * ) V_35 -> V_56 , V_50 -> V_58 ,
V_50 -> V_60 , V_48 ) ;
break;
}
V_47 += V_50 -> V_60 ;
V_48 -= V_50 -> V_60 ;
}
V_55:
return V_51 ;
}
static int F_28 ( struct V_21 * V_22 , struct V_1 * V_2 ,
struct V_46 * V_35 , struct V_61 * V_61 , T_4 V_39 )
{
int V_6 = - V_62 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_63 * V_10 = V_61 -> V_8 ;
struct V_45 * V_51 ;
T_6 V_64 , V_65 ;
T_3 V_66 ;
V_51 = F_27 ( V_8 , V_35 ) ;
if ( V_51 == NULL ) {
F_4 ( V_8 , L_14 ,
V_35 -> V_52 . V_53 ) ;
goto error;
}
V_66 = V_10 -> V_67 && ! V_10 -> V_68 ? 0x80 : 0 ;
F_26 ( V_2 , F_20 ( V_22 -> V_4 . V_34 ) ) ;
F_29 ( & V_22 -> V_69 ,
F_20 ( V_22 -> V_4 . V_70 ) ) ;
V_22 -> V_4 . V_71 = F_30 ( 16 ) ;
if ( F_31 ( & V_35 -> V_52 ) )
V_22 -> V_4 . V_72 = V_51 -> V_73 ;
else
V_22 -> V_4 . V_72 = V_35 -> V_52 . V_72 ;
V_22 -> V_4 . V_74 = F_32 ( F_33 (unsigned int,
epcd->bMaxBurst, 16U ) , 1U ) ;
V_22 -> V_4 . V_75 =
F_34 ( V_61 -> V_8 -> V_76 ) ;
V_22 -> V_4 . V_77 = F_35 ( V_61 -> V_78 ) == 0 ?
V_79 : V_80 ;
F_36 ( V_8 , L_15 ,
V_61 -> V_8 -> V_81 , V_61 -> V_8 -> V_81 | V_66 ,
F_20 ( V_22 -> V_4 . V_34 ) ,
F_35 ( V_61 -> V_78 ) , V_22 -> V_4 . V_77 ) ;
V_22 -> V_4 . V_82 = 0 ;
V_22 -> V_4 . V_53 = V_35 -> V_52 . V_53 ;
V_22 -> V_4 . V_83 = 0 ;
V_64 = 0xFFFFFFFF >> ( 32 - V_22 -> V_4 . V_74 ) ;
V_22 -> V_4 . V_84 = F_37 ( V_64 ) ;
V_65 = F_32 ( F_33 (unsigned int,
epcd->bMaxSequence, 32U ) , 2U ) ;
V_22 -> V_4 . V_85 = V_65 - 1 ;
V_22 -> V_4 . V_86 = V_35 -> V_52 . V_86 ;
if ( F_31 ( & V_35 -> V_52 ) )
V_22 -> V_4 . V_87 = V_51 -> V_87 ;
else
V_22 -> V_4 . V_87 = 0 ;
V_22 -> V_4 . V_88 = ( V_35 -> V_52 . V_89 &
V_90 ) ;
V_22 -> V_4 . V_91 = ( V_2 -> V_67 -> V_92 & 0xF ) ;
V_22 -> V_4 . V_93 = 0 ;
V_6 = F_5 ( V_2 , & V_22 -> V_4 ,
F_20 ( V_22 -> V_4 . V_34 ) ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_16 , V_6 ) ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static int F_38 ( const struct V_21 * V_22 , const struct V_1 * V_2 ,
const struct V_46 * V_35 ,
const struct V_61 * V_61 , T_4 V_39 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
T_3 V_76 = F_34 ( V_61 -> V_8 -> V_76 ) ;
#define F_39 ( T_7 , T_8 , T_9 ) \
do { \
if (rpipe->descr.rdf != (val)) { \
dev_err(dev, \
"rpipe aim discrepancy: " #rdf " " text "\n", \
rpipe->descr.rdf, (val)); \
result = -EINVAL; \
WARN_ON(1); \
} \
} while (0)
F_39 ( V_75 , V_76 , L_17 ) ;
F_39 ( V_77 , F_35 ( V_61 -> V_78 ) == 0 ?
V_79 : V_80 ,
L_17 ) ;
F_39 ( V_53 , V_35 -> V_52 . V_53 , L_17 ) ;
F_39 ( V_86 , V_35 -> V_52 . V_86 , L_17 ) ;
F_39 ( V_88 , V_35 -> V_52 . V_89 & 0x03 , L_17 ) ;
#undef F_39
return V_6 ;
}
int F_40 ( struct V_1 * V_2 , struct V_46 * V_35 ,
struct V_61 * V_61 , T_4 V_39 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_21 * V_22 ;
T_3 V_94 ;
F_41 ( & V_2 -> V_95 ) ;
V_22 = V_35 -> V_36 ;
if ( V_22 != NULL ) {
if ( V_96 == 1 ) {
V_6 = F_38 ( V_22 , V_2 , V_35 , V_61 , V_39 ) ;
if ( V_6 < 0 )
goto error;
}
F_42 ( V_22 ) ;
F_36 ( V_8 , L_18 ,
V_35 -> V_52 . V_53 ,
F_20 ( V_22 -> V_4 . V_34 ) ) ;
} else {
V_6 = - V_97 ;
V_94 = V_35 -> V_52 . V_89 & 0x03 ;
V_6 = F_23 ( & V_22 , V_2 , 1 << V_94 , V_39 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_22 , V_2 , V_35 , V_61 , V_39 ) ;
if ( V_6 < 0 ) {
F_43 ( V_22 ) ;
goto error;
}
V_35 -> V_36 = V_22 ;
V_22 -> V_35 = V_35 ;
F_42 ( V_22 ) ;
F_36 ( V_8 , L_19 ,
V_35 -> V_52 . V_53 ,
F_20 ( V_22 -> V_4 . V_34 ) ) ;
}
error:
F_44 ( & V_2 -> V_95 ) ;
return V_6 ;
}
int F_45 ( struct V_1 * V_2 )
{
V_2 -> V_31 = F_20 ( V_2 -> V_98 -> V_99 ) ;
V_2 -> V_30 = F_24 ( F_46 ( V_2 -> V_31 ) *sizeof( unsigned long ) ,
V_100 ) ;
if ( V_2 -> V_30 == NULL )
return - V_40 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
if ( ! F_48 ( V_2 -> V_30 , V_2 -> V_31 ) ) {
F_49 ( 1 ) ;
F_4 ( V_8 , L_20 ,
V_2 -> V_31 , V_2 -> V_30 ) ;
}
F_22 ( V_2 -> V_30 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_46 * V_35 )
{
struct V_21 * V_22 ;
F_41 ( & V_2 -> V_95 ) ;
V_22 = V_35 -> V_36 ;
if ( V_22 != NULL ) {
T_1 V_5 = F_20 ( V_22 -> V_4 . V_34 ) ;
F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_101 ,
V_19 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , V_20 ) ;
F_43 ( V_22 ) ;
}
F_44 ( & V_2 -> V_95 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_46 * V_35 )
{
struct V_21 * V_22 ;
F_41 ( & V_2 -> V_95 ) ;
V_22 = V_35 -> V_36 ;
if ( V_22 != NULL ) {
T_1 V_5 = F_20 ( V_22 -> V_4 . V_34 ) ;
F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_102 ,
V_19 | V_13 | V_14 ,
V_103 , V_5 , NULL , 0 , V_20 ) ;
}
F_44 ( & V_2 -> V_95 ) ;
}
