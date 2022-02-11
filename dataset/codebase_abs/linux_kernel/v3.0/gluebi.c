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
if ( ! F_4 ( V_9 ) )
return - V_10 ;
if ( V_6 -> V_11 & V_12 )
V_7 = V_13 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
F_6 ( & V_14 ) ;
if ( V_4 -> V_15 > 0 ) {
V_4 -> V_15 += 1 ;
F_7 ( & V_14 ) ;
return 0 ;
}
V_4 -> V_16 = F_8 ( V_4 -> V_2 , V_4 -> V_3 ,
V_7 ) ;
if ( F_9 ( V_4 -> V_16 ) ) {
F_7 ( & V_14 ) ;
F_10 ( V_9 ) ;
return F_11 ( V_4 -> V_16 ) ;
}
V_4 -> V_15 += 1 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
F_6 ( & V_14 ) ;
V_4 -> V_15 -= 1 ;
if ( V_4 -> V_15 == 0 )
F_13 ( V_4 -> V_16 ) ;
F_10 ( V_9 ) ;
F_7 ( & V_14 ) ;
}
static int F_14 ( struct V_5 * V_6 , T_1 V_17 , T_2 V_18 ,
T_2 * V_19 , unsigned char * V_20 )
{
int V_21 = 0 , V_22 , V_23 , V_24 ;
struct V_1 * V_4 ;
if ( V_18 < 0 || V_17 < 0 || V_17 + V_18 > V_6 -> V_25 )
return - V_26 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
V_22 = F_15 ( V_17 , V_6 -> V_27 , & V_23 ) ;
V_24 = V_18 ;
while ( V_24 ) {
T_2 V_28 = V_6 -> V_27 - V_23 ;
if ( V_28 > V_24 )
V_28 = V_24 ;
V_21 = F_16 ( V_4 -> V_16 , V_22 , V_20 , V_23 , V_28 ) ;
if ( V_21 )
break;
V_22 += 1 ;
V_23 = 0 ;
V_24 -= V_28 ;
V_20 += V_28 ;
}
* V_19 = V_18 - V_24 ;
return V_21 ;
}
static int F_17 ( struct V_5 * V_6 , T_1 V_29 , T_2 V_18 ,
T_2 * V_19 , const T_3 * V_20 )
{
int V_21 = 0 , V_22 , V_23 , V_30 ;
struct V_1 * V_4 ;
if ( V_18 < 0 || V_29 < 0 || V_18 + V_29 > V_6 -> V_25 )
return - V_26 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
if ( ! ( V_6 -> V_11 & V_12 ) )
return - V_31 ;
V_22 = F_15 ( V_29 , V_6 -> V_27 , & V_23 ) ;
if ( V_18 % V_6 -> V_32 || V_23 % V_6 -> V_32 )
return - V_26 ;
V_30 = V_18 ;
while ( V_30 ) {
T_2 V_33 = V_6 -> V_27 - V_23 ;
if ( V_33 > V_30 )
V_33 = V_30 ;
V_21 = F_18 ( V_4 -> V_16 , V_22 , V_20 , V_23 , V_33 ) ;
if ( V_21 )
break;
V_22 += 1 ;
V_23 = 0 ;
V_30 -= V_33 ;
V_20 += V_33 ;
}
* V_19 = V_18 - V_30 ;
return V_21 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_34 * V_35 )
{
int V_21 , V_36 , V_22 , V_37 ;
struct V_1 * V_4 ;
if ( V_35 -> V_38 < 0 || V_35 -> V_38 > V_6 -> V_25 - V_6 -> V_27 )
return - V_26 ;
if ( V_35 -> V_18 < 0 || V_35 -> V_38 + V_35 -> V_18 > V_6 -> V_25 )
return - V_26 ;
if ( F_20 ( V_35 -> V_38 , V_6 ) || F_20 ( V_35 -> V_18 , V_6 ) )
return - V_26 ;
V_22 = F_21 ( V_35 -> V_38 , V_6 ) ;
V_37 = F_21 ( V_35 -> V_18 , V_6 ) ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
if ( ! ( V_6 -> V_11 & V_12 ) )
return - V_31 ;
for ( V_36 = 0 ; V_36 < V_37 - 1 ; V_36 ++ ) {
V_21 = F_22 ( V_4 -> V_16 , V_22 + V_36 ) ;
if ( V_21 )
goto V_39;
}
V_21 = F_23 ( V_4 -> V_16 , V_22 + V_36 ) ;
if ( V_21 )
goto V_39;
V_35 -> V_40 = V_41 ;
F_24 ( V_35 ) ;
return 0 ;
V_39:
V_35 -> V_40 = V_42 ;
V_35 -> V_43 = ( long long ) V_22 * V_6 -> V_27 ;
return V_21 ;
}
static int F_25 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_4 , * V_48 ;
struct V_5 * V_6 ;
V_4 = F_26 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_51 = F_27 ( V_47 -> V_51 , V_47 -> V_52 + 1 , V_49 ) ;
if ( ! V_6 -> V_51 ) {
F_28 ( V_4 ) ;
return - V_50 ;
}
V_4 -> V_3 = V_47 -> V_3 ;
V_4 -> V_2 = V_47 -> V_2 ;
V_6 -> type = V_53 ;
if ( ! V_45 -> V_54 )
V_6 -> V_11 = V_12 ;
V_6 -> V_55 = V_9 ;
V_6 -> V_32 = V_45 -> V_56 ;
V_6 -> V_27 = V_47 -> V_57 ;
V_6 -> V_58 = F_14 ;
V_6 -> V_59 = F_17 ;
V_6 -> V_60 = F_19 ;
V_6 -> V_61 = F_3 ;
V_6 -> V_62 = F_12 ;
if ( V_47 -> V_63 == V_64 )
V_6 -> V_25 = ( unsigned long long ) V_47 -> V_57 * V_47 -> V_25 ;
else
V_6 -> V_25 = V_47 -> V_65 ;
F_6 ( & V_14 ) ;
V_48 = F_1 ( V_47 -> V_2 , V_47 -> V_3 ) ;
if ( V_48 )
F_29 ( L_1
L_2 , V_48 -> V_6 . V_66 , V_47 -> V_2 ,
V_47 -> V_3 ) ;
F_7 ( & V_14 ) ;
if ( F_30 ( V_6 , NULL , 0 ) ) {
F_29 ( L_3 ) ;
F_28 ( V_6 -> V_51 ) ;
F_28 ( V_4 ) ;
return - V_67 ;
}
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_68 , & V_69 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_46 * V_47 )
{
int V_21 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_47 -> V_2 , V_47 -> V_3 ) ;
if ( ! V_4 ) {
F_29 ( L_4
L_5 , V_47 -> V_2 , V_47 -> V_3 ) ;
V_21 = - V_70 ;
} else if ( V_4 -> V_15 )
V_21 = - V_71 ;
else
F_33 ( & V_4 -> V_68 ) ;
F_7 ( & V_14 ) ;
if ( V_21 )
return V_21 ;
V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 ) {
F_29 ( L_6
L_7 , V_6 -> V_66 , V_4 -> V_2 ,
V_4 -> V_3 , V_21 ) ;
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_68 , & V_69 ) ;
F_7 ( & V_14 ) ;
return V_21 ;
}
F_28 ( V_6 -> V_51 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_46 * V_47 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_47 -> V_2 , V_47 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_8
L_5 , V_47 -> V_2 , V_47 -> V_3 ) ;
return - V_70 ;
}
if ( V_47 -> V_63 == V_72 )
V_4 -> V_6 . V_25 = V_47 -> V_65 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_47 -> V_2 , V_47 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_8
L_5 , V_47 -> V_2 , V_47 -> V_3 ) ;
return - V_70 ;
}
V_4 -> V_6 . V_25 = V_47 -> V_65 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_37 ( struct V_73 * V_74 , unsigned long V_75 ,
void * V_76 )
{
struct V_77 * V_78 = V_76 ;
switch ( V_75 ) {
case V_79 :
F_25 ( & V_78 -> V_45 , & V_78 -> V_47 ) ;
break;
case V_80 :
F_32 ( & V_78 -> V_47 ) ;
break;
case V_81 :
F_36 ( & V_78 -> V_47 ) ;
break;
case V_82 :
F_35 ( & V_78 -> V_47 ) ;
break;
default:
break;
}
return V_83 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_84 , 0 ) ;
}
static void T_5 F_40 ( void )
{
struct V_1 * V_4 , * V_48 ;
F_41 (gluebi, g, &gluebi_devices, list) {
int V_21 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 )
F_29 ( L_9
L_10 , V_21 ,
V_6 -> V_66 , V_4 -> V_2 , V_4 -> V_3 ) ;
F_28 ( V_6 -> V_51 ) ;
F_28 ( V_4 ) ;
}
F_42 ( & V_84 ) ;
}
