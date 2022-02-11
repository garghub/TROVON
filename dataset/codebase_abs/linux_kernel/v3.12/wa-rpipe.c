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
}
static unsigned F_11 ( struct V_1 * V_2 , unsigned V_25 )
{
unsigned long V_26 ;
F_12 ( & V_2 -> V_27 , V_26 ) ;
V_25 = F_13 ( V_2 -> V_28 , V_2 -> V_29 , V_25 ) ;
if ( V_25 < V_2 -> V_29 )
F_14 ( V_25 , V_2 -> V_28 ) ;
F_15 ( & V_2 -> V_27 , V_26 ) ;
return V_25 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned V_25 )
{
unsigned long V_26 ;
F_12 ( & V_2 -> V_27 , V_26 ) ;
F_17 ( V_25 , V_2 -> V_28 ) ;
F_15 ( & V_2 -> V_27 , V_26 ) ;
}
void F_18 ( struct V_30 * V_31 )
{
struct V_20 * V_21 = F_19 ( V_31 , struct V_20 , V_22 ) ;
T_3 V_5 = F_20 ( V_21 -> V_4 . V_32 ) ;
if ( V_21 -> V_33 )
V_21 -> V_33 -> V_34 = NULL ;
F_16 ( V_21 -> V_2 , V_5 ) ;
F_21 ( V_21 -> V_2 ) ;
F_22 ( V_21 ) ;
}
static int F_23 ( struct V_20 * * V_35 , struct V_1 * V_2 , T_3 V_36 ,
T_4 V_37 )
{
int V_6 ;
unsigned V_25 ;
struct V_20 * V_21 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_21 = F_24 ( sizeof( * V_21 ) , V_37 ) ;
if ( V_21 == NULL )
return - V_38 ;
F_7 ( V_21 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_29 ; V_25 ++ ) {
V_25 = F_11 ( V_2 , V_25 ) ;
if ( V_25 >= V_2 -> V_29 )
break;
V_6 = F_1 ( V_2 , & V_21 -> V_4 , V_25 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_7 ,
V_25 , V_6 ) ;
else if ( ( V_21 -> V_4 . V_39 & V_36 ) != 0 )
goto V_40;
F_16 ( V_2 , V_25 ) ;
}
* V_35 = NULL ;
F_22 ( V_21 ) ;
return - V_41 ;
V_40:
F_14 ( V_25 , V_2 -> V_28 ) ;
V_21 -> V_2 = F_25 ( V_2 ) ;
* V_35 = V_21 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned V_5 )
{
int V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
V_6 = F_2 (
V_2 -> V_10 , F_6 ( V_2 -> V_10 , 0 ) ,
V_42 ,
V_18 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , 1000 ) ;
if ( V_6 < 0 )
F_4 ( V_8 , L_8 ,
V_5 , V_6 ) ;
return V_6 ;
}
static struct V_43 * F_27 (
struct V_7 * V_8 , struct V_44 * V_33 )
{
void * V_45 ;
T_5 V_46 ;
struct V_47 * V_48 ;
struct V_43 * V_49 ;
if ( V_33 -> V_50 . V_51 == 0 ) {
V_49 = & V_52 ;
goto V_53;
}
V_45 = V_33 -> V_54 ;
V_46 = V_33 -> V_55 ;
V_49 = NULL ;
while ( V_46 > 0 ) {
if ( V_46 < sizeof( * V_48 ) ) {
F_4 ( V_8 , L_9
L_10 ,
V_33 -> V_50 . V_51 ,
V_45 - ( void * ) V_33 -> V_54 , V_46 ) ;
break;
}
V_48 = V_45 ;
if ( V_48 -> V_56 == V_57 ) {
V_49 = V_45 ;
break;
}
if ( V_48 -> V_58 > V_46 ) {
F_4 ( V_8 , L_11
L_12
L_13 ,
V_33 -> V_50 . V_51 ,
V_45 - ( void * ) V_33 -> V_54 , V_48 -> V_56 ,
V_48 -> V_58 , V_46 ) ;
break;
}
V_45 += V_48 -> V_58 ;
V_46 -= V_48 -> V_56 ;
}
V_53:
return V_49 ;
}
static int F_28 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_44 * V_33 , struct V_59 * V_59 , T_4 V_37 )
{
int V_6 = - V_60 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_61 * V_10 = V_59 -> V_8 ;
struct V_43 * V_49 ;
T_6 V_62 , V_63 ;
T_3 V_64 ;
V_49 = F_27 ( V_8 , V_33 ) ;
if ( V_49 == NULL ) {
F_4 ( V_8 , L_14 ,
V_33 -> V_50 . V_51 ) ;
goto error;
}
V_64 = V_10 -> V_65 && ! V_10 -> V_66 ? 0x80 : 0 ;
F_26 ( V_2 , F_20 ( V_21 -> V_4 . V_32 ) ) ;
F_29 ( & V_21 -> V_67 , F_20 ( V_21 -> V_4 . V_68 ) ) ;
V_21 -> V_4 . V_69 = F_30 ( 16 ) ;
V_21 -> V_4 . V_70 = F_30 ( V_33 -> V_50 . V_70 ) ;
V_21 -> V_4 . V_71 = F_31 ( F_32 (unsigned int,
epcd->bMaxBurst, 16U ) , 1U ) ;
V_21 -> V_4 . V_72 =
F_33 ( V_59 -> V_8 -> V_73 ) ;
V_21 -> V_4 . V_74 = F_34 ( V_59 -> V_75 ) == 0 ?
V_76 : V_77 ;
F_35 ( V_8 , L_15 ,
V_59 -> V_8 -> V_78 , V_59 -> V_8 -> V_78 | V_64 ,
F_20 ( V_21 -> V_4 . V_32 ) ,
F_34 ( V_59 -> V_75 ) , V_21 -> V_4 . V_74 ) ;
V_21 -> V_4 . V_79 = 0 ;
V_21 -> V_4 . V_51 = V_33 -> V_50 . V_51 ;
V_21 -> V_4 . V_80 = 0 ;
V_62 = 0xFFFFFFFF >> ( 32 - V_21 -> V_4 . V_71 ) ;
V_21 -> V_4 . V_81 = F_36 ( V_62 ) ;
V_63 = F_31 ( F_32 (unsigned int,
epcd->bMaxSequence, 32U ) , 2U ) ;
V_21 -> V_4 . V_82 = V_63 - 1 ;
V_21 -> V_4 . V_83 = V_33 -> V_50 . V_83 ;
V_21 -> V_4 . V_84 = 0 ;
V_21 -> V_4 . V_85 = ( V_33 -> V_50 . V_86 &
V_87 ) ;
V_21 -> V_4 . V_88 = ( V_2 -> V_65 -> V_89 & 0xF ) ;
V_21 -> V_4 . V_90 = 0 ;
V_6 = F_5 ( V_2 , & V_21 -> V_4 ,
F_20 ( V_21 -> V_4 . V_32 ) ) ;
if ( V_6 < 0 ) {
F_4 ( V_8 , L_16 , V_6 ) ;
goto error;
}
V_6 = 0 ;
error:
return V_6 ;
}
static int F_37 ( const struct V_20 * V_21 , const struct V_1 * V_2 ,
const struct V_44 * V_33 ,
const struct V_59 * V_59 , T_4 V_37 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
T_3 V_73 = F_33 ( V_59 -> V_8 -> V_73 ) ;
#define F_38 ( T_7 , T_8 , T_9 ) \
do { \
if (rpipe->descr.rdf != (val)) { \
dev_err(dev, \
"rpipe aim discrepancy: " #rdf " " text "\n", \
rpipe->descr.rdf, (val)); \
result = -EINVAL; \
WARN_ON(1); \
} \
} while (0)
F_38 ( V_72 , V_73 , L_17 ) ;
F_38 ( V_74 , F_34 ( V_59 -> V_75 ) == 0 ?
V_76 : V_77 ,
L_17 ) ;
F_38 ( V_51 , V_33 -> V_50 . V_51 , L_17 ) ;
F_38 ( V_83 , V_33 -> V_50 . V_83 , L_17 ) ;
F_38 ( V_85 , V_33 -> V_50 . V_86 & 0x03 , L_17 ) ;
#undef F_38
return V_6 ;
}
int F_39 ( struct V_1 * V_2 , struct V_44 * V_33 ,
struct V_59 * V_59 , T_4 V_37 )
{
int V_6 = 0 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_20 * V_21 ;
T_3 V_91 ;
F_40 ( & V_2 -> V_92 ) ;
V_21 = V_33 -> V_34 ;
if ( V_21 != NULL ) {
if ( V_93 == 1 ) {
V_6 = F_37 ( V_21 , V_2 , V_33 , V_59 , V_37 ) ;
if ( V_6 < 0 )
goto error;
}
F_41 ( V_21 ) ;
F_35 ( V_8 , L_18 ,
V_33 -> V_50 . V_51 ,
F_20 ( V_21 -> V_4 . V_32 ) ) ;
} else {
V_6 = - V_94 ;
V_91 = V_33 -> V_50 . V_86 & 0x03 ;
V_6 = F_23 ( & V_21 , V_2 , 1 << V_91 , V_37 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_21 , V_2 , V_33 , V_59 , V_37 ) ;
if ( V_6 < 0 ) {
F_42 ( V_21 ) ;
goto error;
}
V_33 -> V_34 = V_21 ;
V_21 -> V_33 = V_33 ;
F_41 ( V_21 ) ;
F_35 ( V_8 , L_19 ,
V_33 -> V_50 . V_51 ,
F_20 ( V_21 -> V_4 . V_32 ) ) ;
}
error:
F_43 ( & V_2 -> V_92 ) ;
return V_6 ;
}
int F_44 ( struct V_1 * V_2 )
{
V_2 -> V_29 = V_2 -> V_95 -> V_96 ;
V_2 -> V_28 = F_24 ( F_45 ( V_2 -> V_29 ) *sizeof( unsigned long ) ,
V_97 ) ;
if ( V_2 -> V_28 == NULL )
return - V_38 ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
if ( ! F_47 ( V_2 -> V_28 , V_2 -> V_29 ) ) {
char V_98 [ 256 ] ;
F_48 ( 1 ) ;
F_49 ( V_98 , sizeof( V_98 ) , V_2 -> V_28 , V_2 -> V_29 ) ;
F_4 ( V_8 , L_20 , V_98 ) ;
}
F_22 ( V_2 -> V_28 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_44 * V_33 )
{
struct V_20 * V_21 ;
F_40 ( & V_2 -> V_92 ) ;
V_21 = V_33 -> V_34 ;
if ( V_21 != NULL ) {
T_1 V_5 = F_20 ( V_21 -> V_4 . V_32 ) ;
F_2 (
V_2 -> V_10 , F_3 ( V_2 -> V_10 , 0 ) ,
V_99 ,
V_18 | V_13 | V_14 ,
0 , V_5 , NULL , 0 , 1000 ) ;
F_42 ( V_21 ) ;
}
F_43 ( & V_2 -> V_92 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_44 * V_33 )
{
struct V_20 * V_21 ;
F_40 ( & V_2 -> V_92 ) ;
V_21 = V_33 -> V_34 ;
if ( V_21 != NULL ) {
T_1 V_5 = F_20 ( V_21 -> V_4 . V_32 ) ;
F_2 (
V_2 -> V_10 , F_3 ( V_2 -> V_10 , 0 ) ,
V_100 ,
V_18 | V_13 | V_14 ,
V_101 , V_5 , NULL , 0 , 1000 ) ;
}
F_43 ( & V_2 -> V_92 ) ;
}
