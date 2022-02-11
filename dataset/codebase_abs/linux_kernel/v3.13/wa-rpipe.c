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
1000 ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_1 ,
V_5 , ( int ) V_6 ) ;
goto error;
}
if ( V_6 < sizeof( * V_4 ) ) {
F_4 ( V_8 , L_2
L_3 ,
V_5 , V_6 , sizeof( * V_4 ) ) ;
V_6 = - V_16 ;
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
V_17 ,
V_18 | V_13 | V_14 ,
V_15 << 8 , V_5 , V_4 , sizeof( * V_4 ) ,
V_19 / 10 ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_4 ,
V_5 , ( int ) V_6 ) ;
goto error;
}
if ( V_6 < sizeof( * V_4 ) ) {
F_4 ( V_8 , L_5
L_6 ,
V_5 , V_6 , sizeof( * V_4 ) ) ;
V_6 = - V_16 ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static void F_7 ( struct V_20 * V_21 )
{
F_8 ( & V_21 -> V_22 ) ;
F_9 ( & V_21 -> V_23 ) ;
F_10 ( & V_21 -> V_24 ) ;
F_10 ( & V_21 -> V_25 ) ;
}
static unsigned F_11 ( struct V_1 * V_2 , unsigned V_26 )
{
unsigned long V_27 ;
F_12 ( & V_2 -> V_28 , V_27 ) ;
V_26 = F_13 ( V_2 -> V_29 , V_2 -> V_30 , V_26 ) ;
if ( V_26 < V_2 -> V_30 )
F_14 ( V_26 , V_2 -> V_29 ) ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
return V_26 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned V_26 )
{
unsigned long V_27 ;
F_12 ( & V_2 -> V_28 , V_27 ) ;
F_17 ( V_26 , V_2 -> V_29 ) ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
}
void F_18 ( struct V_31 * V_32 )
{
struct V_20 * V_21 = F_19 ( V_32 , struct V_20 , V_22 ) ;
T_3 V_5 = F_20 ( V_21 -> V_4 . V_33 ) ;
if ( V_21 -> V_34 )
V_21 -> V_34 -> V_35 = NULL ;
F_16 ( V_21 -> V_2 , V_5 ) ;
F_21 ( V_21 -> V_2 ) ;
F_22 ( V_21 ) ;
}
static int F_23 ( struct V_20 * * V_36 , struct V_1 * V_2 , T_3 V_37 ,
T_4 V_38 )
{
int V_6 ;
unsigned V_26 ;
struct V_20 * V_21 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_21 = F_24 ( sizeof( * V_21 ) , V_38 ) ;
if ( V_21 == NULL )
return - V_39 ;
F_7 ( V_21 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 ; V_26 ++ ) {
V_26 = F_11 ( V_2 , V_26 ) ;
if ( V_26 >= V_2 -> V_30 )
break;
V_6 = F_1 ( V_2 , & V_21 -> V_4 , V_26 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_7 ,
V_26 , V_6 ) ;
else if ( ( V_21 -> V_4 . V_40 & V_37 ) != 0 )
goto V_41;
F_16 ( V_2 , V_26 ) ;
}
* V_36 = NULL ;
F_22 ( V_21 ) ;
return - V_42 ;
V_41:
F_14 ( V_26 , V_2 -> V_29 ) ;
V_21 -> V_2 = F_25 ( V_2 ) ;
* V_36 = V_21 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned V_5 )
{
int V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_6 = F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_43 ,
V_18 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , 1000 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_8 ,
V_5 , V_6 ) ;
return V_6 ;
}
static struct V_44 * F_27 (
struct V_7 * V_8 , struct V_45 * V_34 )
{
void * V_46 ;
T_5 V_47 ;
struct V_48 * V_49 ;
struct V_44 * V_50 ;
if ( V_34 -> V_51 . V_52 == 0 ) {
V_50 = & V_53 ;
goto V_54;
}
V_46 = V_34 -> V_55 ;
V_47 = V_34 -> V_56 ;
V_50 = NULL ;
while ( V_47 > 0 ) {
if ( V_47 < sizeof( * V_49 ) ) {
F_4 ( V_8 , L_9
L_10 ,
V_34 -> V_51 . V_52 ,
V_46 - ( void * ) V_34 -> V_55 , V_47 ) ;
break;
}
V_49 = V_46 ;
if ( V_49 -> V_57 == V_58 ) {
V_50 = V_46 ;
break;
}
if ( V_49 -> V_59 > V_47 ) {
F_4 ( V_8 , L_11
L_12
L_13 ,
V_34 -> V_51 . V_52 ,
V_46 - ( void * ) V_34 -> V_55 , V_49 -> V_57 ,
V_49 -> V_59 , V_47 ) ;
break;
}
V_46 += V_49 -> V_59 ;
V_47 -= V_49 -> V_57 ;
}
V_54:
return V_50 ;
}
static int F_28 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_45 * V_34 , struct V_60 * V_60 , T_4 V_38 )
{
int V_6 = - V_61 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_62 * V_10 = V_60 -> V_8 ;
struct V_44 * V_50 ;
T_6 V_63 , V_64 ;
T_3 V_65 ;
V_50 = F_27 ( V_8 , V_34 ) ;
if ( V_50 == NULL ) {
F_4 ( V_8 , L_14 ,
V_34 -> V_51 . V_52 ) ;
goto error;
}
V_65 = V_10 -> V_66 && ! V_10 -> V_67 ? 0x80 : 0 ;
F_26 ( V_2 , F_20 ( V_21 -> V_4 . V_33 ) ) ;
F_29 ( & V_21 -> V_68 , F_20 ( V_21 -> V_4 . V_69 ) ) ;
V_21 -> V_4 . V_70 = F_30 ( 16 ) ;
if ( F_31 ( & V_34 -> V_51 ) )
V_21 -> V_4 . V_71 = V_50 -> V_72 ;
else
V_21 -> V_4 . V_71 = V_34 -> V_51 . V_71 ;
V_21 -> V_4 . V_73 = F_32 ( F_33 (unsigned int,
epcd->bMaxBurst, 16U ) , 1U ) ;
V_21 -> V_4 . V_74 =
F_34 ( V_60 -> V_8 -> V_75 ) ;
V_21 -> V_4 . V_76 = F_35 ( V_60 -> V_77 ) == 0 ?
V_78 : V_79 ;
F_36 ( V_8 , L_15 ,
V_60 -> V_8 -> V_80 , V_60 -> V_8 -> V_80 | V_65 ,
F_20 ( V_21 -> V_4 . V_33 ) ,
F_35 ( V_60 -> V_77 ) , V_21 -> V_4 . V_76 ) ;
V_21 -> V_4 . V_81 = 0 ;
V_21 -> V_4 . V_52 = V_34 -> V_51 . V_52 ;
V_21 -> V_4 . V_82 = 0 ;
V_63 = 0xFFFFFFFF >> ( 32 - V_21 -> V_4 . V_73 ) ;
V_21 -> V_4 . V_83 = F_37 ( V_63 ) ;
V_64 = F_32 ( F_33 (unsigned int,
epcd->bMaxSequence, 32U ) , 2U ) ;
V_21 -> V_4 . V_84 = V_64 - 1 ;
V_21 -> V_4 . V_85 = V_34 -> V_51 . V_85 ;
if ( F_31 ( & V_34 -> V_51 ) )
V_21 -> V_4 . V_86 = V_50 -> V_86 ;
else
V_21 -> V_4 . V_86 = 0 ;
V_21 -> V_4 . V_87 = ( V_34 -> V_51 . V_88 &
V_89 ) ;
V_21 -> V_4 . V_90 = ( V_2 -> V_66 -> V_91 & 0xF ) ;
V_21 -> V_4 . V_92 = 0 ;
V_6 = F_5 ( V_2 , & V_21 -> V_4 ,
F_20 ( V_21 -> V_4 . V_33 ) ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_16 , V_6 ) ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static int F_38 ( const struct V_20 * V_21 , const struct V_1 * V_2 ,
const struct V_45 * V_34 ,
const struct V_60 * V_60 , T_4 V_38 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
T_3 V_75 = F_34 ( V_60 -> V_8 -> V_75 ) ;
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
F_39 ( V_74 , V_75 , L_17 ) ;
F_39 ( V_76 , F_35 ( V_60 -> V_77 ) == 0 ?
V_78 : V_79 ,
L_17 ) ;
F_39 ( V_52 , V_34 -> V_51 . V_52 , L_17 ) ;
F_39 ( V_85 , V_34 -> V_51 . V_85 , L_17 ) ;
F_39 ( V_87 , V_34 -> V_51 . V_88 & 0x03 , L_17 ) ;
#undef F_39
return V_6 ;
}
int F_40 ( struct V_1 * V_2 , struct V_45 * V_34 ,
struct V_60 * V_60 , T_4 V_38 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_20 * V_21 ;
T_3 V_93 ;
F_41 ( & V_2 -> V_94 ) ;
V_21 = V_34 -> V_35 ;
if ( V_21 != NULL ) {
if ( V_95 == 1 ) {
V_6 = F_38 ( V_21 , V_2 , V_34 , V_60 , V_38 ) ;
if ( V_6 < 0 )
goto error;
}
F_42 ( V_21 ) ;
F_36 ( V_8 , L_18 ,
V_34 -> V_51 . V_52 ,
F_20 ( V_21 -> V_4 . V_33 ) ) ;
} else {
V_6 = - V_96 ;
V_93 = V_34 -> V_51 . V_88 & 0x03 ;
V_6 = F_23 ( & V_21 , V_2 , 1 << V_93 , V_38 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_21 , V_2 , V_34 , V_60 , V_38 ) ;
if ( V_6 < 0 ) {
F_43 ( V_21 ) ;
goto error;
}
V_34 -> V_35 = V_21 ;
V_21 -> V_34 = V_34 ;
F_42 ( V_21 ) ;
F_36 ( V_8 , L_19 ,
V_34 -> V_51 . V_52 ,
F_20 ( V_21 -> V_4 . V_33 ) ) ;
}
error:
F_44 ( & V_2 -> V_94 ) ;
return V_6 ;
}
int F_45 ( struct V_1 * V_2 )
{
V_2 -> V_30 = F_20 ( V_2 -> V_97 -> V_98 ) ;
V_2 -> V_29 = F_24 ( F_46 ( V_2 -> V_30 ) *sizeof( unsigned long ) ,
V_99 ) ;
if ( V_2 -> V_29 == NULL )
return - V_39 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
if ( ! F_48 ( V_2 -> V_29 , V_2 -> V_30 ) ) {
char V_100 [ 256 ] ;
F_49 ( 1 ) ;
F_50 ( V_100 , sizeof( V_100 ) , V_2 -> V_29 , V_2 -> V_30 ) ;
F_4 ( V_8 , L_20 , V_100 ) ;
}
F_22 ( V_2 -> V_29 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_45 * V_34 )
{
struct V_20 * V_21 ;
F_41 ( & V_2 -> V_94 ) ;
V_21 = V_34 -> V_35 ;
if ( V_21 != NULL ) {
T_1 V_5 = F_20 ( V_21 -> V_4 . V_33 ) ;
F_2 (
V_2 -> V_10 , F_3 ( V_2 -> V_10 , 0 ) ,
V_101 ,
V_18 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , 1000 ) ;
F_43 ( V_21 ) ;
}
F_44 ( & V_2 -> V_94 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_45 * V_34 )
{
struct V_20 * V_21 ;
F_41 ( & V_2 -> V_94 ) ;
V_21 = V_34 -> V_35 ;
if ( V_21 != NULL ) {
T_1 V_5 = F_20 ( V_21 -> V_4 . V_33 ) ;
F_2 (
V_2 -> V_10 , F_3 ( V_2 -> V_10 , 0 ) ,
V_102 ,
V_18 | V_13 | V_14 ,
V_103 , V_5 , NULL , 0 , 1000 ) ;
}
F_44 ( & V_2 -> V_94 ) ;
}
