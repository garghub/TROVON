static struct V_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 ;
F_2 (gluebi, &gluebi_devices, list)
if ( V_4 -> V_2 == V_2 && V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
int V_7 = V_8 ;
if ( V_6 -> V_9 & V_10 )
V_7 = V_11 ;
V_4 = F_4 ( V_6 , struct V_1 , V_6 ) ;
F_5 ( & V_12 ) ;
if ( V_4 -> V_13 > 0 ) {
V_4 -> V_13 += 1 ;
F_6 ( & V_12 ) ;
return 0 ;
}
V_4 -> V_14 = F_7 ( V_4 -> V_2 , V_4 -> V_3 ,
V_7 ) ;
if ( F_8 ( V_4 -> V_14 ) ) {
F_6 ( & V_12 ) ;
return F_9 ( V_4 -> V_14 ) ;
}
V_4 -> V_13 += 1 ;
F_6 ( & V_12 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
V_4 = F_4 ( V_6 , struct V_1 , V_6 ) ;
F_5 ( & V_12 ) ;
V_4 -> V_13 -= 1 ;
if ( V_4 -> V_13 == 0 )
F_11 ( V_4 -> V_14 ) ;
F_6 ( & V_12 ) ;
}
static int F_12 ( struct V_5 * V_6 , T_1 V_15 , T_2 V_16 ,
T_2 * V_17 , unsigned char * V_18 )
{
int V_19 = 0 , V_20 , V_21 , V_22 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_6 , struct V_1 , V_6 ) ;
V_20 = F_13 ( V_15 , V_6 -> V_23 , & V_21 ) ;
V_22 = V_16 ;
while ( V_22 ) {
T_2 V_24 = V_6 -> V_23 - V_21 ;
if ( V_24 > V_22 )
V_24 = V_22 ;
V_19 = F_14 ( V_4 -> V_14 , V_20 , V_18 , V_21 , V_24 ) ;
if ( V_19 )
break;
V_20 += 1 ;
V_21 = 0 ;
V_22 -= V_24 ;
V_18 += V_24 ;
}
* V_17 = V_16 - V_22 ;
return V_19 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 V_25 , T_2 V_16 ,
T_2 * V_17 , const T_3 * V_18 )
{
int V_19 = 0 , V_20 , V_21 , V_22 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_6 , struct V_1 , V_6 ) ;
V_20 = F_13 ( V_25 , V_6 -> V_23 , & V_21 ) ;
if ( V_16 % V_6 -> V_26 || V_21 % V_6 -> V_26 )
return - V_27 ;
V_22 = V_16 ;
while ( V_22 ) {
T_2 V_28 = V_6 -> V_23 - V_21 ;
if ( V_28 > V_22 )
V_28 = V_22 ;
V_19 = F_16 ( V_4 -> V_14 , V_20 , V_18 , V_21 , V_28 ) ;
if ( V_19 )
break;
V_20 += 1 ;
V_21 = 0 ;
V_22 -= V_28 ;
V_18 += V_28 ;
}
* V_17 = V_16 - V_22 ;
return V_19 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_29 * V_30 )
{
int V_19 , V_31 , V_20 , V_32 ;
struct V_1 * V_4 ;
if ( F_18 ( V_30 -> V_33 , V_6 ) || F_18 ( V_30 -> V_16 , V_6 ) )
return - V_27 ;
V_20 = F_19 ( V_30 -> V_33 , V_6 ) ;
V_32 = F_19 ( V_30 -> V_16 , V_6 ) ;
V_4 = F_4 ( V_6 , struct V_1 , V_6 ) ;
for ( V_31 = 0 ; V_31 < V_32 - 1 ; V_31 ++ ) {
V_19 = F_20 ( V_4 -> V_14 , V_20 + V_31 ) ;
if ( V_19 )
goto V_34;
}
V_19 = F_21 ( V_4 -> V_14 , V_20 + V_31 ) ;
if ( V_19 )
goto V_34;
V_30 -> V_35 = V_36 ;
F_22 ( V_30 ) ;
return 0 ;
V_34:
V_30 -> V_35 = V_37 ;
V_30 -> V_38 = ( long long ) V_20 * V_6 -> V_23 ;
return V_19 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_4 , * V_43 ;
struct V_5 * V_6 ;
V_4 = F_24 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_46 = F_25 ( V_42 -> V_46 , V_42 -> V_47 + 1 , V_44 ) ;
if ( ! V_6 -> V_46 ) {
F_26 ( V_4 ) ;
return - V_45 ;
}
V_4 -> V_3 = V_42 -> V_3 ;
V_4 -> V_2 = V_42 -> V_2 ;
V_6 -> type = V_48 ;
if ( ! V_40 -> V_49 )
V_6 -> V_9 = V_10 ;
V_6 -> V_50 = V_51 ;
V_6 -> V_26 = V_40 -> V_52 ;
V_6 -> V_23 = V_42 -> V_53 ;
V_6 -> V_54 = F_12 ;
V_6 -> V_55 = F_15 ;
V_6 -> V_56 = F_17 ;
V_6 -> V_57 = F_3 ;
V_6 -> V_58 = F_10 ;
if ( V_42 -> V_59 == V_60 )
V_6 -> V_61 = ( unsigned long long ) V_42 -> V_53 * V_42 -> V_61 ;
else
V_6 -> V_61 = V_42 -> V_62 ;
F_5 ( & V_12 ) ;
V_43 = F_1 ( V_42 -> V_2 , V_42 -> V_3 ) ;
if ( V_43 )
F_27 ( L_1 ,
V_43 -> V_6 . V_63 , V_42 -> V_2 , V_42 -> V_3 ) ;
F_6 ( & V_12 ) ;
if ( F_28 ( V_6 , NULL , 0 ) ) {
F_27 ( L_2 ) ;
F_26 ( V_6 -> V_46 ) ;
F_26 ( V_4 ) ;
return - V_64 ;
}
F_5 ( & V_12 ) ;
F_29 ( & V_4 -> V_65 , & V_66 ) ;
F_6 ( & V_12 ) ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 )
{
int V_19 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_4 ;
F_5 ( & V_12 ) ;
V_4 = F_1 ( V_42 -> V_2 , V_42 -> V_3 ) ;
if ( ! V_4 ) {
F_27 ( L_3 ,
V_42 -> V_2 , V_42 -> V_3 ) ;
V_19 = - V_67 ;
} else if ( V_4 -> V_13 )
V_19 = - V_68 ;
else
F_31 ( & V_4 -> V_65 ) ;
F_6 ( & V_12 ) ;
if ( V_19 )
return V_19 ;
V_6 = & V_4 -> V_6 ;
V_19 = F_32 ( V_6 ) ;
if ( V_19 ) {
F_27 ( L_4 ,
V_6 -> V_63 , V_4 -> V_2 , V_4 -> V_3 , V_19 ) ;
F_5 ( & V_12 ) ;
F_29 ( & V_4 -> V_65 , & V_66 ) ;
F_6 ( & V_12 ) ;
return V_19 ;
}
F_26 ( V_6 -> V_46 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 )
{
struct V_1 * V_4 ;
F_5 ( & V_12 ) ;
V_4 = F_1 ( V_42 -> V_2 , V_42 -> V_3 ) ;
if ( ! V_4 ) {
F_6 ( & V_12 ) ;
F_27 ( L_5 ,
V_42 -> V_2 , V_42 -> V_3 ) ;
return - V_67 ;
}
if ( V_42 -> V_59 == V_69 )
V_4 -> V_6 . V_61 = V_42 -> V_62 ;
F_6 ( & V_12 ) ;
return 0 ;
}
static int F_34 ( struct V_41 * V_42 )
{
struct V_1 * V_4 ;
F_5 ( & V_12 ) ;
V_4 = F_1 ( V_42 -> V_2 , V_42 -> V_3 ) ;
if ( ! V_4 ) {
F_6 ( & V_12 ) ;
F_27 ( L_5 ,
V_42 -> V_2 , V_42 -> V_3 ) ;
return - V_67 ;
}
V_4 -> V_6 . V_61 = V_42 -> V_62 ;
F_6 ( & V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_70 * V_71 , unsigned long V_72 ,
void * V_73 )
{
struct V_74 * V_75 = V_73 ;
switch ( V_72 ) {
case V_76 :
F_23 ( & V_75 -> V_40 , & V_75 -> V_42 ) ;
break;
case V_77 :
F_30 ( & V_75 -> V_42 ) ;
break;
case V_78 :
F_34 ( & V_75 -> V_42 ) ;
break;
case V_79 :
F_33 ( & V_75 -> V_42 ) ;
break;
default:
break;
}
return V_80 ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_81 , 0 ) ;
}
static void T_5 F_38 ( void )
{
struct V_1 * V_4 , * V_43 ;
F_39 (gluebi, g, &gluebi_devices, list) {
int V_19 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_19 = F_32 ( V_6 ) ;
if ( V_19 )
F_27 ( L_6 ,
V_19 , V_6 -> V_63 , V_4 -> V_2 ,
V_4 -> V_3 ) ;
F_26 ( V_6 -> V_46 ) ;
F_26 ( V_4 ) ;
}
F_40 ( & V_81 ) ;
}
