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
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
V_22 = F_15 ( V_17 , V_6 -> V_25 , & V_23 ) ;
V_24 = V_18 ;
while ( V_24 ) {
T_2 V_26 = V_6 -> V_25 - V_23 ;
if ( V_26 > V_24 )
V_26 = V_24 ;
V_21 = F_16 ( V_4 -> V_16 , V_22 , V_20 , V_23 , V_26 ) ;
if ( V_21 )
break;
V_22 += 1 ;
V_23 = 0 ;
V_24 -= V_26 ;
V_20 += V_26 ;
}
* V_19 = V_18 - V_24 ;
return V_21 ;
}
static int F_17 ( struct V_5 * V_6 , T_1 V_27 , T_2 V_18 ,
T_2 * V_19 , const T_3 * V_20 )
{
int V_21 = 0 , V_22 , V_23 , V_28 ;
struct V_1 * V_4 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
V_22 = F_15 ( V_27 , V_6 -> V_25 , & V_23 ) ;
if ( V_18 % V_6 -> V_29 || V_23 % V_6 -> V_29 )
return - V_30 ;
V_28 = V_18 ;
while ( V_28 ) {
T_2 V_31 = V_6 -> V_25 - V_23 ;
if ( V_31 > V_28 )
V_31 = V_28 ;
V_21 = F_18 ( V_4 -> V_16 , V_22 , V_20 , V_23 , V_31 ) ;
if ( V_21 )
break;
V_22 += 1 ;
V_23 = 0 ;
V_28 -= V_31 ;
V_20 += V_31 ;
}
* V_19 = V_18 - V_28 ;
return V_21 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_32 * V_33 )
{
int V_21 , V_34 , V_22 , V_35 ;
struct V_1 * V_4 ;
if ( F_20 ( V_33 -> V_36 , V_6 ) || F_20 ( V_33 -> V_18 , V_6 ) )
return - V_30 ;
V_22 = F_21 ( V_33 -> V_36 , V_6 ) ;
V_35 = F_21 ( V_33 -> V_18 , V_6 ) ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
for ( V_34 = 0 ; V_34 < V_35 - 1 ; V_34 ++ ) {
V_21 = F_22 ( V_4 -> V_16 , V_22 + V_34 ) ;
if ( V_21 )
goto V_37;
}
V_21 = F_23 ( V_4 -> V_16 , V_22 + V_34 ) ;
if ( V_21 )
goto V_37;
V_33 -> V_38 = V_39 ;
F_24 ( V_33 ) ;
return 0 ;
V_37:
V_33 -> V_38 = V_40 ;
V_33 -> V_41 = ( long long ) V_22 * V_6 -> V_25 ;
return V_21 ;
}
static int F_25 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_4 , * V_46 ;
struct V_5 * V_6 ;
V_4 = F_26 ( sizeof( struct V_1 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_49 = F_27 ( V_45 -> V_49 , V_45 -> V_50 + 1 , V_47 ) ;
if ( ! V_6 -> V_49 ) {
F_28 ( V_4 ) ;
return - V_48 ;
}
V_4 -> V_3 = V_45 -> V_3 ;
V_4 -> V_2 = V_45 -> V_2 ;
V_6 -> type = V_51 ;
if ( ! V_43 -> V_52 )
V_6 -> V_11 = V_12 ;
V_6 -> V_53 = V_9 ;
V_6 -> V_29 = V_43 -> V_54 ;
V_6 -> V_25 = V_45 -> V_55 ;
V_6 -> V_56 = F_14 ;
V_6 -> V_57 = F_17 ;
V_6 -> V_58 = F_19 ;
V_6 -> V_59 = F_3 ;
V_6 -> V_60 = F_12 ;
if ( V_45 -> V_61 == V_62 )
V_6 -> V_63 = ( unsigned long long ) V_45 -> V_55 * V_45 -> V_63 ;
else
V_6 -> V_63 = V_45 -> V_64 ;
F_6 ( & V_14 ) ;
V_46 = F_1 ( V_45 -> V_2 , V_45 -> V_3 ) ;
if ( V_46 )
F_29 ( L_1
L_2 , V_46 -> V_6 . V_65 , V_45 -> V_2 ,
V_45 -> V_3 ) ;
F_7 ( & V_14 ) ;
if ( F_30 ( V_6 , NULL , 0 ) ) {
F_29 ( L_3 ) ;
F_28 ( V_6 -> V_49 ) ;
F_28 ( V_4 ) ;
return - V_66 ;
}
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_67 , & V_68 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_45 )
{
int V_21 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_45 -> V_2 , V_45 -> V_3 ) ;
if ( ! V_4 ) {
F_29 ( L_4
L_5 , V_45 -> V_2 , V_45 -> V_3 ) ;
V_21 = - V_69 ;
} else if ( V_4 -> V_15 )
V_21 = - V_70 ;
else
F_33 ( & V_4 -> V_67 ) ;
F_7 ( & V_14 ) ;
if ( V_21 )
return V_21 ;
V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 ) {
F_29 ( L_6
L_7 , V_6 -> V_65 , V_4 -> V_2 ,
V_4 -> V_3 , V_21 ) ;
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_67 , & V_68 ) ;
F_7 ( & V_14 ) ;
return V_21 ;
}
F_28 ( V_6 -> V_49 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_45 -> V_2 , V_45 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_8
L_5 , V_45 -> V_2 , V_45 -> V_3 ) ;
return - V_69 ;
}
if ( V_45 -> V_61 == V_71 )
V_4 -> V_6 . V_63 = V_45 -> V_64 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_36 ( struct V_44 * V_45 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_45 -> V_2 , V_45 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_8
L_5 , V_45 -> V_2 , V_45 -> V_3 ) ;
return - V_69 ;
}
V_4 -> V_6 . V_63 = V_45 -> V_64 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_37 ( struct V_72 * V_73 , unsigned long V_74 ,
void * V_75 )
{
struct V_76 * V_77 = V_75 ;
switch ( V_74 ) {
case V_78 :
F_25 ( & V_77 -> V_43 , & V_77 -> V_45 ) ;
break;
case V_79 :
F_32 ( & V_77 -> V_45 ) ;
break;
case V_80 :
F_36 ( & V_77 -> V_45 ) ;
break;
case V_81 :
F_35 ( & V_77 -> V_45 ) ;
break;
default:
break;
}
return V_82 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_83 , 0 ) ;
}
static void T_5 F_40 ( void )
{
struct V_1 * V_4 , * V_46 ;
F_41 (gluebi, g, &gluebi_devices, list) {
int V_21 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 )
F_29 ( L_9
L_10 , V_21 ,
V_6 -> V_65 , V_4 -> V_2 , V_4 -> V_3 ) ;
F_28 ( V_6 -> V_49 ) ;
F_28 ( V_4 ) ;
}
F_42 ( & V_83 ) ;
}
