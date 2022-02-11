static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 -> V_7 , L_1 ,
V_4 , V_4 -> V_8 , V_2 -> V_9 , V_2 -> V_10 ) ;
V_4 -> V_8 ++ ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_6 = V_4 -> V_6 ;
int V_12 ;
F_2 ( V_6 -> V_7 , L_2 ,
V_4 , V_4 -> V_8 , V_2 -> V_9 , V_2 -> V_10 ) ;
V_4 -> V_8 -- ;
if ( 0 == V_4 -> V_8 ) {
struct V_13 * V_14 ;
F_2 ( V_6 -> V_7 , L_3 , V_4 , V_6 ) ;
F_4 ( V_6 ) ;
if ( V_6 -> V_15 )
F_5 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
if ( NULL == V_6 -> V_17 [ V_12 ] )
continue;
if ( V_6 -> V_17 [ V_12 ] -> V_4 != V_4 )
continue;
V_14 = V_6 -> V_17 [ V_12 ] -> V_18 ;
if ( V_14 ) {
F_6 ( V_14 -> V_19 , V_20 ) ;
F_2 ( V_6 -> V_7 , L_4 ,
V_12 , V_14 -> V_21 ) ;
F_7 ( V_6 -> V_7 , V_14 -> V_22 ,
V_14 -> V_21 , V_14 -> V_23 ) ;
V_14 -> V_21 = NULL ;
}
V_6 -> V_17 [ V_12 ] -> V_4 = NULL ;
V_6 -> V_17 [ V_12 ] -> V_24 = 0 ;
}
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
}
static void F_10 ( struct V_13 * V_14 )
{
V_14 -> V_23 = 0 ;
V_14 -> V_22 = 0 ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_29 -> V_28 ;
struct V_1 * V_2 ;
unsigned long V_30 , V_31 ;
unsigned long V_32 , V_33 ;
unsigned int V_34 ;
int V_35 ;
V_34 = V_26 -> V_24 & ~ V_36 ;
V_14 -> V_22 = F_12 ( V_26 -> V_22 + V_34 ) ;
V_35 = - V_37 ;
F_13 ( & V_28 -> V_38 ) ;
V_2 = F_14 ( V_28 , V_26 -> V_24 ) ;
if ( ! V_2 )
goto V_39;
if ( ( V_26 -> V_24 + V_14 -> V_22 ) > V_2 -> V_10 )
goto V_39;
V_32 = 0 ;
V_30 = 0 ;
V_33 = V_26 -> V_24 ;
while ( V_32 < ( V_14 -> V_22 >> V_40 ) ) {
V_35 = F_15 ( V_2 , V_33 , & V_31 ) ;
if ( V_35 )
break;
if ( V_32 == 0 )
V_14 -> V_23 = ( V_31 << V_40 ) + V_34 ;
else if ( V_31 != ( V_30 + 1 ) )
V_35 = - V_41 ;
if ( V_35 )
break;
V_30 = V_31 ;
V_33 += V_42 ;
V_32 ++ ;
}
V_39:
F_16 ( & V_29 -> V_28 -> V_38 ) ;
return V_35 ;
}
static struct V_25 * F_17 ( T_1 V_22 )
{
struct V_13 * V_14 ;
struct V_25 * V_26 ;
V_26 = F_18 ( V_22 + sizeof( * V_14 ) , V_43 ) ;
if ( V_26 ) {
V_14 = V_26 -> V_18 = ( ( char * ) V_26 ) + V_22 ;
V_14 -> V_19 = V_20 ;
}
return V_26 ;
}
static void * F_19 ( struct V_25 * V_44 )
{
struct V_13 * V_14 = V_44 -> V_18 ;
F_20 ( ! V_14 ) ;
F_6 ( V_14 -> V_19 , V_20 ) ;
return V_14 -> V_21 ;
}
static int F_21 ( struct V_11 * V_6 ,
struct V_25 * V_26 ,
struct V_45 * V_46 )
{
struct V_13 * V_14 = V_26 -> V_18 ;
F_20 ( ! V_14 ) ;
F_6 ( V_14 -> V_19 , V_20 ) ;
switch ( V_26 -> V_47 ) {
case V_48 :
F_2 ( V_6 -> V_7 , L_5 , V_49 ) ;
if ( ! V_14 -> V_21 ) {
F_22 ( V_6 -> V_7 , L_6 ) ;
return - V_37 ;
}
break;
case V_50 :
F_2 ( V_6 -> V_7 , L_7 , V_49 ) ;
if ( V_26 -> V_24 )
return F_11 ( V_14 , V_26 ) ;
V_14 -> V_22 = F_12 ( V_26 -> V_22 ) ;
V_14 -> V_21 = F_23 ( V_6 -> V_7 , V_14 -> V_22 ,
& V_14 -> V_23 , V_43 ) ;
if ( ! V_14 -> V_21 ) {
F_22 ( V_6 -> V_7 , L_8 ,
V_14 -> V_22 ) ;
return - V_51 ;
}
F_2 ( V_6 -> V_7 , L_9 ,
V_14 -> V_21 , V_14 -> V_22 ) ;
break;
case V_52 :
default:
F_2 ( V_6 -> V_7 , L_10 ,
V_49 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_24 ( struct V_11 * V_6 ,
struct V_25 * V_44 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_53 ;
unsigned long V_22 ;
F_2 ( V_6 -> V_7 , L_11 , V_49 ) ;
V_4 = F_18 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_4 )
return - V_51 ;
V_44 -> V_4 = V_4 ;
V_4 -> V_6 = V_6 ;
V_44 -> V_24 = V_2 -> V_9 ;
V_14 = V_44 -> V_18 ;
F_20 ( ! V_14 ) ;
F_6 ( V_14 -> V_19 , V_20 ) ;
V_14 -> V_22 = F_12 ( V_44 -> V_54 ) ;
V_14 -> V_21 = F_23 ( V_6 -> V_7 , V_14 -> V_22 ,
& V_14 -> V_23 , V_43 ) ;
if ( ! V_14 -> V_21 ) {
F_22 ( V_6 -> V_7 , L_12 ,
V_14 -> V_22 ) ;
goto error;
}
F_2 ( V_6 -> V_7 , L_13 ,
V_14 -> V_21 , V_14 -> V_22 ) ;
V_22 = V_2 -> V_10 - V_2 -> V_9 ;
V_22 = ( V_22 < V_14 -> V_22 ) ? V_22 : V_14 -> V_22 ;
V_2 -> V_55 = F_25 ( V_2 -> V_55 ) ;
V_53 = F_26 ( V_2 , V_2 -> V_9 ,
V_14 -> V_23 >> V_40 ,
V_22 , V_2 -> V_55 ) ;
if ( V_53 ) {
F_22 ( V_6 -> V_7 , L_14 , V_53 ) ;
F_7 ( V_6 -> V_7 , V_14 -> V_22 ,
V_14 -> V_21 , V_14 -> V_23 ) ;
goto error;
}
V_2 -> V_56 = & V_57 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_5 = V_4 ;
F_2 ( V_6 -> V_7 , L_15 ,
V_4 , V_6 , V_2 -> V_9 , V_2 -> V_10 ,
( long int ) V_44 -> V_54 ,
V_2 -> V_60 , V_44 -> V_12 ) ;
F_1 ( V_2 ) ;
return 0 ;
error:
F_8 ( V_4 ) ;
return - V_51 ;
}
void F_27 ( struct V_11 * V_6 ,
const struct V_61 * V_62 ,
struct V_63 * V_7 ,
T_2 * V_64 ,
enum V_65 type ,
enum V_66 V_67 ,
unsigned int V_68 ,
void * V_18 ,
struct V_69 * V_70 )
{
F_28 ( V_6 , V_62 , V_7 , V_64 , type , V_67 , V_68 ,
V_18 , & V_71 , V_70 ) ;
}
T_3 F_29 ( struct V_25 * V_44 )
{
struct V_13 * V_14 = V_44 -> V_18 ;
F_20 ( ! V_14 ) ;
F_6 ( V_14 -> V_19 , V_20 ) ;
return V_14 -> V_23 ;
}
void F_30 ( struct V_11 * V_6 ,
struct V_25 * V_44 )
{
struct V_13 * V_14 = V_44 -> V_18 ;
if ( V_44 -> V_47 != V_50 )
return;
if ( ! V_14 )
return;
F_6 ( V_14 -> V_19 , V_20 ) ;
if ( V_44 -> V_24 ) {
F_10 ( V_14 ) ;
return;
}
if ( V_14 -> V_21 ) {
F_7 ( V_6 -> V_7 , V_14 -> V_22 , V_14 -> V_21 , V_14 -> V_23 ) ;
V_14 -> V_21 = NULL ;
}
}
