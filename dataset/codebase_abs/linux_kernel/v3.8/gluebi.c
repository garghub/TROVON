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
int V_21 = 0 , V_22 , V_23 , V_24 ;
struct V_1 * V_4 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
V_22 = F_15 ( V_27 , V_6 -> V_25 , & V_23 ) ;
if ( V_18 % V_6 -> V_28 || V_23 % V_6 -> V_28 )
return - V_29 ;
V_24 = V_18 ;
while ( V_24 ) {
T_2 V_30 = V_6 -> V_25 - V_23 ;
if ( V_30 > V_24 )
V_30 = V_24 ;
V_21 = F_18 ( V_4 -> V_16 , V_22 , V_20 , V_23 , V_30 ) ;
if ( V_21 )
break;
V_22 += 1 ;
V_23 = 0 ;
V_24 -= V_30 ;
V_20 += V_30 ;
}
* V_19 = V_18 - V_24 ;
return V_21 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_31 * V_32 )
{
int V_21 , V_33 , V_22 , V_34 ;
struct V_1 * V_4 ;
if ( F_20 ( V_32 -> V_35 , V_6 ) || F_20 ( V_32 -> V_18 , V_6 ) )
return - V_29 ;
V_22 = F_21 ( V_32 -> V_35 , V_6 ) ;
V_34 = F_21 ( V_32 -> V_18 , V_6 ) ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
for ( V_33 = 0 ; V_33 < V_34 - 1 ; V_33 ++ ) {
V_21 = F_22 ( V_4 -> V_16 , V_22 + V_33 ) ;
if ( V_21 )
goto V_36;
}
V_21 = F_23 ( V_4 -> V_16 , V_22 + V_33 ) ;
if ( V_21 )
goto V_36;
V_32 -> V_37 = V_38 ;
F_24 ( V_32 ) ;
return 0 ;
V_36:
V_32 -> V_37 = V_39 ;
V_32 -> V_40 = ( long long ) V_22 * V_6 -> V_25 ;
return V_21 ;
}
static int F_25 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_4 , * V_45 ;
struct V_5 * V_6 ;
V_4 = F_26 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_48 = F_27 ( V_44 -> V_48 , V_44 -> V_49 + 1 , V_46 ) ;
if ( ! V_6 -> V_48 ) {
F_28 ( V_4 ) ;
return - V_47 ;
}
V_4 -> V_3 = V_44 -> V_3 ;
V_4 -> V_2 = V_44 -> V_2 ;
V_6 -> type = V_50 ;
if ( ! V_42 -> V_51 )
V_6 -> V_11 = V_12 ;
V_6 -> V_52 = V_9 ;
V_6 -> V_28 = V_42 -> V_53 ;
V_6 -> V_25 = V_44 -> V_54 ;
V_6 -> V_55 = F_14 ;
V_6 -> V_56 = F_17 ;
V_6 -> V_57 = F_19 ;
V_6 -> V_58 = F_3 ;
V_6 -> V_59 = F_12 ;
if ( V_44 -> V_60 == V_61 )
V_6 -> V_62 = ( unsigned long long ) V_44 -> V_54 * V_44 -> V_62 ;
else
V_6 -> V_62 = V_44 -> V_63 ;
F_6 ( & V_14 ) ;
V_45 = F_1 ( V_44 -> V_2 , V_44 -> V_3 ) ;
if ( V_45 )
F_29 ( L_1 ,
V_45 -> V_6 . V_64 , V_44 -> V_2 , V_44 -> V_3 ) ;
F_7 ( & V_14 ) ;
if ( F_30 ( V_6 , NULL , 0 ) ) {
F_29 ( L_2 ) ;
F_28 ( V_6 -> V_48 ) ;
F_28 ( V_4 ) ;
return - V_65 ;
}
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_66 , & V_67 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_44 )
{
int V_21 = 0 ;
struct V_5 * V_6 ;
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_44 -> V_2 , V_44 -> V_3 ) ;
if ( ! V_4 ) {
F_29 ( L_3 ,
V_44 -> V_2 , V_44 -> V_3 ) ;
V_21 = - V_68 ;
} else if ( V_4 -> V_15 )
V_21 = - V_69 ;
else
F_33 ( & V_4 -> V_66 ) ;
F_7 ( & V_14 ) ;
if ( V_21 )
return V_21 ;
V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 ) {
F_29 ( L_4 ,
V_6 -> V_64 , V_4 -> V_2 , V_4 -> V_3 , V_21 ) ;
F_6 ( & V_14 ) ;
F_31 ( & V_4 -> V_66 , & V_67 ) ;
F_7 ( & V_14 ) ;
return V_21 ;
}
F_28 ( V_6 -> V_48 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_43 * V_44 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_44 -> V_2 , V_44 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_5 ,
V_44 -> V_2 , V_44 -> V_3 ) ;
return - V_68 ;
}
if ( V_44 -> V_60 == V_70 )
V_4 -> V_6 . V_62 = V_44 -> V_63 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_1 * V_4 ;
F_6 ( & V_14 ) ;
V_4 = F_1 ( V_44 -> V_2 , V_44 -> V_3 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 ) ;
F_29 ( L_5 ,
V_44 -> V_2 , V_44 -> V_3 ) ;
return - V_68 ;
}
V_4 -> V_6 . V_62 = V_44 -> V_63 ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_37 ( struct V_71 * V_72 , unsigned long V_73 ,
void * V_74 )
{
struct V_75 * V_76 = V_74 ;
switch ( V_73 ) {
case V_77 :
F_25 ( & V_76 -> V_42 , & V_76 -> V_44 ) ;
break;
case V_78 :
F_32 ( & V_76 -> V_44 ) ;
break;
case V_79 :
F_36 ( & V_76 -> V_44 ) ;
break;
case V_80 :
F_35 ( & V_76 -> V_44 ) ;
break;
default:
break;
}
return V_81 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_82 , 0 ) ;
}
static void T_5 F_40 ( void )
{
struct V_1 * V_4 , * V_45 ;
F_41 (gluebi, g, &gluebi_devices, list) {
int V_21 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 )
F_29 ( L_6 ,
V_21 , V_6 -> V_64 , V_4 -> V_2 ,
V_4 -> V_3 ) ;
F_28 ( V_6 -> V_48 ) ;
F_28 ( V_4 ) ;
}
F_42 ( & V_82 ) ;
}
