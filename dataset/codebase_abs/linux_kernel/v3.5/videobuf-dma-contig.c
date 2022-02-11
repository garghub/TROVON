static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
V_4 -> V_5 = V_5 ;
if ( V_4 -> V_7 ) {
V_4 -> V_8 = F_2 ( V_4 -> V_5 , V_6 | V_9 ) ;
if ( V_4 -> V_8 ) {
int V_10 ;
V_4 -> V_11 = F_3 ( V_2 , V_4 -> V_8 ,
V_4 -> V_5 ,
V_12 ) ;
V_10 = F_4 ( V_2 , V_4 -> V_11 ) ;
if ( V_10 ) {
F_5 ( V_2 , L_1 ) ;
F_6 ( V_4 -> V_8 , V_4 -> V_5 ) ;
V_4 -> V_8 = 0 ;
return V_10 ;
}
}
} else
V_4 -> V_8 = F_7 ( V_2 , V_4 -> V_5 ,
& V_4 -> V_11 , V_6 ) ;
if ( ! V_4 -> V_8 ) {
F_5 ( V_2 , L_2 , V_4 -> V_5 ) ;
return - V_13 ;
}
F_8 ( V_2 , L_3 , V_4 -> V_8 , V_4 -> V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_7 ) {
if ( ! V_4 -> V_8 )
return;
F_10 ( V_2 , V_4 -> V_11 , V_4 -> V_5 ,
V_12 ) ;
F_6 ( V_4 -> V_8 , V_4 -> V_5 ) ;
} else
F_11 ( V_2 , V_4 -> V_5 , V_4 -> V_8 , V_4 -> V_11 ) ;
V_4 -> V_8 = NULL ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_8 ( V_17 -> V_19 -> V_2 , L_4 ,
V_17 , V_17 -> V_20 , V_15 -> V_21 , V_15 -> V_22 ) ;
V_17 -> V_20 ++ ;
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_23 * V_19 = V_17 -> V_19 ;
int V_24 ;
F_8 ( V_19 -> V_2 , L_5 ,
V_17 , V_17 -> V_20 , V_15 -> V_21 , V_15 -> V_22 ) ;
V_17 -> V_20 -- ;
if ( 0 == V_17 -> V_20 ) {
struct V_3 * V_4 ;
F_8 ( V_19 -> V_2 , L_6 , V_17 , V_19 ) ;
F_14 ( V_19 ) ;
if ( V_19 -> V_25 )
F_15 ( V_19 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
if ( NULL == V_19 -> V_27 [ V_24 ] )
continue;
if ( V_19 -> V_27 [ V_24 ] -> V_17 != V_17 )
continue;
V_4 = V_19 -> V_27 [ V_24 ] -> V_28 ;
if ( V_4 ) {
F_16 ( V_4 -> V_29 , V_30 ) ;
F_8 ( V_19 -> V_2 , L_7 ,
V_24 , V_4 -> V_8 ) ;
F_9 ( V_19 -> V_2 , V_4 ) ;
V_4 -> V_8 = NULL ;
}
V_19 -> V_27 [ V_24 ] -> V_17 = NULL ;
V_19 -> V_27 [ V_24 ] -> V_31 = 0 ;
}
F_17 ( V_17 ) ;
F_18 ( V_19 ) ;
}
}
static void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_11 = 0 ;
V_4 -> V_5 = 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_36 -> V_35 ;
struct V_14 * V_15 ;
unsigned long V_37 , V_38 ;
unsigned long V_39 , V_40 ;
unsigned int V_41 ;
int V_42 ;
V_41 = V_33 -> V_31 & ~ V_43 ;
V_4 -> V_5 = F_21 ( V_33 -> V_5 + V_41 ) ;
V_42 = - V_44 ;
F_22 ( & V_35 -> V_45 ) ;
V_15 = F_23 ( V_35 , V_33 -> V_31 ) ;
if ( ! V_15 )
goto V_46;
if ( ( V_33 -> V_31 + V_4 -> V_5 ) > V_15 -> V_22 )
goto V_46;
V_39 = 0 ;
V_37 = 0 ;
V_40 = V_33 -> V_31 ;
while ( V_39 < ( V_4 -> V_5 >> V_47 ) ) {
V_42 = F_24 ( V_15 , V_40 , & V_38 ) ;
if ( V_42 )
break;
if ( V_39 == 0 )
V_4 -> V_11 = ( V_38 << V_47 ) + V_41 ;
else if ( V_38 != ( V_37 + 1 ) )
V_42 = - V_48 ;
if ( V_42 )
break;
V_37 = V_38 ;
V_40 += V_49 ;
V_39 ++ ;
}
V_46:
F_25 ( & V_36 -> V_35 -> V_45 ) ;
return V_42 ;
}
static struct V_32 * F_26 ( T_1 V_5 , bool V_7 )
{
struct V_3 * V_4 ;
struct V_32 * V_33 ;
V_33 = F_27 ( V_5 + sizeof( * V_4 ) , V_50 ) ;
if ( V_33 ) {
V_33 -> V_28 = ( ( char * ) V_33 ) + V_5 ;
V_4 = V_33 -> V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_7 = V_7 ;
}
return V_33 ;
}
static struct V_32 * F_28 ( T_1 V_5 )
{
return F_26 ( V_5 , false ) ;
}
static struct V_32 * F_29 ( T_1 V_5 )
{
return F_26 ( V_5 , true ) ;
}
static void * F_30 ( struct V_32 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_28 ;
F_31 ( ! V_4 ) ;
F_16 ( V_4 -> V_29 , V_30 ) ;
return V_4 -> V_8 ;
}
static int F_32 ( struct V_23 * V_19 ,
struct V_32 * V_33 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = V_33 -> V_28 ;
F_31 ( ! V_4 ) ;
F_16 ( V_4 -> V_29 , V_30 ) ;
switch ( V_33 -> V_54 ) {
case V_55 :
F_8 ( V_19 -> V_2 , L_8 , V_56 ) ;
if ( ! V_4 -> V_8 ) {
F_5 ( V_19 -> V_2 , L_9 ) ;
return - V_44 ;
}
break;
case V_57 :
F_8 ( V_19 -> V_2 , L_10 , V_56 ) ;
if ( V_33 -> V_31 )
return F_20 ( V_4 , V_33 ) ;
if ( F_1 ( V_19 -> V_2 , V_4 , F_21 ( V_33 -> V_5 ) ,
V_50 ) )
return - V_13 ;
break;
case V_58 :
default:
F_8 ( V_19 -> V_2 , L_11 , V_56 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_33 ( struct V_23 * V_19 ,
struct V_32 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_28 ;
F_31 ( ! V_4 ) ;
F_16 ( V_4 -> V_29 , V_30 ) ;
F_34 ( V_19 -> V_2 , V_4 -> V_11 , V_4 -> V_5 ,
V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_19 ,
struct V_32 * V_51 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 ;
int V_59 ;
unsigned long V_5 ;
unsigned long V_60 , V_61 = V_15 -> V_21 ;
struct V_62 * V_62 ;
F_8 ( V_19 -> V_2 , L_12 , V_56 ) ;
V_17 = F_27 ( sizeof( struct V_16 ) , V_50 ) ;
if ( ! V_17 )
return - V_13 ;
V_51 -> V_17 = V_17 ;
V_17 -> V_19 = V_19 ;
V_51 -> V_31 = V_15 -> V_21 ;
V_4 = V_51 -> V_28 ;
F_31 ( ! V_4 ) ;
F_16 ( V_4 -> V_29 , V_30 ) ;
if ( F_1 ( V_19 -> V_2 , V_4 , F_21 ( V_51 -> V_63 ) ,
V_50 | V_64 ) )
goto error;
V_5 = V_15 -> V_22 - V_15 -> V_21 ;
V_5 = ( V_5 < V_4 -> V_5 ) ? V_5 : V_4 -> V_5 ;
if ( ! V_4 -> V_7 )
V_15 -> V_65 = F_36 ( V_15 -> V_65 ) ;
V_60 = ( unsigned long ) V_4 -> V_8 ;
while ( V_5 > 0 ) {
V_62 = F_37 ( ( void * ) V_60 ) ;
if ( NULL == V_62 ) {
F_5 ( V_19 -> V_2 , L_13 ) ;
F_9 ( V_19 -> V_2 , V_4 ) ;
goto error;
}
V_59 = F_38 ( V_15 , V_61 , V_62 ) ;
if ( V_59 ) {
F_5 ( V_19 -> V_2 , L_14 ,
V_59 ) ;
F_9 ( V_19 -> V_2 , V_4 ) ;
goto error;
}
V_61 += V_49 ;
V_60 += V_49 ;
if ( V_5 > V_49 )
V_5 -= V_49 ;
else
V_5 = 0 ;
}
V_15 -> V_66 = & V_67 ;
V_15 -> V_68 |= V_69 ;
V_15 -> V_18 = V_17 ;
F_8 ( V_19 -> V_2 , L_15 ,
V_17 , V_19 , V_15 -> V_21 , V_15 -> V_22 ,
( long int ) V_51 -> V_63 , V_15 -> V_70 , V_51 -> V_24 ) ;
F_12 ( V_15 ) ;
return 0 ;
error:
F_17 ( V_17 ) ;
return - V_13 ;
}
void F_39 ( struct V_23 * V_19 ,
const struct V_71 * V_72 ,
struct V_1 * V_2 ,
T_2 * V_73 ,
enum V_74 type ,
enum V_75 V_76 ,
unsigned int V_77 ,
void * V_28 ,
struct V_78 * V_79 )
{
F_40 ( V_19 , V_72 , V_2 , V_73 , type , V_76 , V_77 ,
V_28 , & V_80 , V_79 ) ;
}
void F_41 ( struct V_23 * V_19 ,
const struct V_71 * V_72 ,
struct V_1 * V_2 ,
T_2 * V_73 ,
enum V_74 type ,
enum V_75 V_76 ,
unsigned int V_77 ,
void * V_28 , struct V_78 * V_79 )
{
F_40 ( V_19 , V_72 , V_2 , V_73 , type , V_76 , V_77 ,
V_28 , & V_81 , V_79 ) ;
}
T_3 F_42 ( struct V_32 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_28 ;
F_31 ( ! V_4 ) ;
F_16 ( V_4 -> V_29 , V_30 ) ;
return V_4 -> V_11 ;
}
void F_43 ( struct V_23 * V_19 ,
struct V_32 * V_51 )
{
struct V_3 * V_4 = V_51 -> V_28 ;
if ( V_51 -> V_54 != V_57 )
return;
if ( ! V_4 )
return;
F_16 ( V_4 -> V_29 , V_30 ) ;
if ( V_51 -> V_31 ) {
F_19 ( V_4 ) ;
return;
}
if ( V_4 -> V_8 ) {
F_9 ( V_19 -> V_2 , V_4 ) ;
V_4 -> V_8 = NULL ;
}
}
