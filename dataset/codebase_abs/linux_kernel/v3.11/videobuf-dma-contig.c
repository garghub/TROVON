static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 , T_1 V_6 )
{
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = F_2 ( V_2 , V_4 -> V_5 ,
& V_4 -> V_8 , V_6 ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( V_2 , L_1 , V_4 -> V_5 ) ;
return - V_9 ;
}
F_4 ( V_2 , L_2 , V_4 -> V_7 , V_4 -> V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_6 ( V_2 , V_4 -> V_5 , V_4 -> V_7 , V_4 -> V_8 ) ;
V_4 -> V_7 = NULL ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_16 ;
F_4 ( V_16 -> V_2 , L_3 ,
V_13 , V_13 -> V_17 , V_11 -> V_18 , V_11 -> V_19 ) ;
F_8 ( V_16 ) ;
V_13 -> V_17 ++ ;
F_9 ( V_16 ) ;
}
static void F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_16 ;
int V_20 ;
F_4 ( V_16 -> V_2 , L_4 ,
V_13 , V_13 -> V_17 , V_11 -> V_18 , V_11 -> V_19 ) ;
F_8 ( V_16 ) ;
if ( ! -- V_13 -> V_17 ) {
struct V_3 * V_4 ;
F_4 ( V_16 -> V_2 , L_5 , V_13 , V_16 ) ;
if ( V_16 -> V_21 )
F_11 ( V_16 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( NULL == V_16 -> V_23 [ V_20 ] )
continue;
if ( V_16 -> V_23 [ V_20 ] -> V_13 != V_13 )
continue;
V_4 = V_16 -> V_23 [ V_20 ] -> V_24 ;
if ( V_4 ) {
F_12 ( V_4 -> V_25 , V_26 ) ;
F_4 ( V_16 -> V_2 , L_6 ,
V_20 , V_4 -> V_7 ) ;
F_5 ( V_16 -> V_2 , V_4 ) ;
V_4 -> V_7 = NULL ;
}
V_16 -> V_23 [ V_20 ] -> V_13 = NULL ;
V_16 -> V_23 [ V_20 ] -> V_27 = 0 ;
}
F_13 ( V_13 ) ;
}
F_9 ( V_16 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_8 = 0 ;
V_4 -> V_5 = 0 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_32 -> V_31 ;
struct V_10 * V_11 ;
unsigned long V_33 , V_34 ;
unsigned long V_35 , V_36 ;
unsigned int V_37 ;
int V_38 ;
V_37 = V_29 -> V_27 & ~ V_39 ;
V_4 -> V_5 = F_16 ( V_29 -> V_5 + V_37 ) ;
V_38 = - V_40 ;
F_17 ( & V_31 -> V_41 ) ;
V_11 = F_18 ( V_31 , V_29 -> V_27 ) ;
if ( ! V_11 )
goto V_42;
if ( ( V_29 -> V_27 + V_4 -> V_5 ) > V_11 -> V_19 )
goto V_42;
V_35 = 0 ;
V_33 = 0 ;
V_36 = V_29 -> V_27 ;
while ( V_35 < ( V_4 -> V_5 >> V_43 ) ) {
V_38 = F_19 ( V_11 , V_36 , & V_34 ) ;
if ( V_38 )
break;
if ( V_35 == 0 )
V_4 -> V_8 = ( V_34 << V_43 ) + V_37 ;
else if ( V_34 != ( V_33 + 1 ) )
V_38 = - V_44 ;
if ( V_38 )
break;
V_33 = V_34 ;
V_36 += V_45 ;
V_35 ++ ;
}
V_42:
F_20 ( & V_32 -> V_31 -> V_41 ) ;
return V_38 ;
}
static struct V_28 * F_21 ( T_2 V_5 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
V_29 = F_22 ( V_5 + sizeof( * V_4 ) , V_46 ) ;
if ( V_29 ) {
V_29 -> V_24 = ( ( char * ) V_29 ) + V_5 ;
V_4 = V_29 -> V_24 ;
V_4 -> V_25 = V_26 ;
}
return V_29 ;
}
static void * F_23 ( struct V_28 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_24 ;
F_24 ( ! V_4 ) ;
F_12 ( V_4 -> V_25 , V_26 ) ;
return V_4 -> V_7 ;
}
static int F_25 ( struct V_15 * V_16 ,
struct V_28 * V_29 ,
struct V_48 * V_49 )
{
struct V_3 * V_4 = V_29 -> V_24 ;
F_24 ( ! V_4 ) ;
F_12 ( V_4 -> V_25 , V_26 ) ;
switch ( V_29 -> V_50 ) {
case V_51 :
F_4 ( V_16 -> V_2 , L_7 , V_52 ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( V_16 -> V_2 , L_8 ) ;
return - V_40 ;
}
break;
case V_53 :
F_4 ( V_16 -> V_2 , L_9 , V_52 ) ;
if ( V_29 -> V_27 )
return F_15 ( V_4 , V_29 ) ;
if ( F_1 ( V_16 -> V_2 , V_4 , F_16 ( V_29 -> V_5 ) ,
V_46 ) )
return - V_9 ;
break;
case V_54 :
default:
F_4 ( V_16 -> V_2 , L_10 , V_52 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_26 ( struct V_15 * V_16 ,
struct V_28 * V_47 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
int V_55 ;
unsigned long V_5 ;
F_4 ( V_16 -> V_2 , L_11 , V_52 ) ;
V_13 = F_22 ( sizeof( struct V_12 ) , V_46 ) ;
if ( ! V_13 )
return - V_9 ;
V_47 -> V_13 = V_13 ;
V_13 -> V_16 = V_16 ;
V_47 -> V_27 = V_11 -> V_18 ;
V_4 = V_47 -> V_24 ;
F_24 ( ! V_4 ) ;
F_12 ( V_4 -> V_25 , V_26 ) ;
if ( F_1 ( V_16 -> V_2 , V_4 , F_16 ( V_47 -> V_56 ) ,
V_46 | V_57 ) )
goto error;
V_5 = V_11 -> V_19 - V_11 -> V_18 ;
V_11 -> V_58 = F_27 ( V_11 -> V_58 ) ;
V_55 = F_28 ( V_11 , V_11 -> V_18 , V_5 ) ;
if ( V_55 ) {
F_3 ( V_16 -> V_2 , L_12 ,
V_55 ) ;
F_6 ( V_16 -> V_2 , V_4 -> V_5 ,
V_4 -> V_7 , V_4 -> V_8 ) ;
goto error;
}
V_11 -> V_59 = & V_60 ;
V_11 -> V_61 |= V_62 ;
V_11 -> V_14 = V_13 ;
F_4 ( V_16 -> V_2 , L_13 ,
V_13 , V_16 , V_11 -> V_18 , V_11 -> V_19 ,
( long int ) V_47 -> V_56 , V_11 -> V_63 , V_47 -> V_20 ) ;
F_7 ( V_11 ) ;
return 0 ;
error:
F_13 ( V_13 ) ;
return - V_9 ;
}
void F_29 ( struct V_15 * V_16 ,
const struct V_64 * V_65 ,
struct V_1 * V_2 ,
T_3 * V_66 ,
enum V_67 type ,
enum V_68 V_69 ,
unsigned int V_70 ,
void * V_24 ,
struct V_71 * V_72 )
{
F_30 ( V_16 , V_65 , V_2 , V_66 , type , V_69 , V_70 ,
V_24 , & V_73 , V_72 ) ;
}
T_4 F_31 ( struct V_28 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_24 ;
F_24 ( ! V_4 ) ;
F_12 ( V_4 -> V_25 , V_26 ) ;
return V_4 -> V_8 ;
}
void F_32 ( struct V_15 * V_16 ,
struct V_28 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_24 ;
if ( V_47 -> V_50 != V_53 )
return;
if ( ! V_4 )
return;
F_12 ( V_4 -> V_25 , V_26 ) ;
if ( V_47 -> V_27 ) {
F_14 ( V_4 ) ;
return;
}
if ( V_4 -> V_7 ) {
F_5 ( V_16 -> V_2 , V_4 ) ;
V_4 -> V_7 = NULL ;
}
}
