static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
bool V_8 = false ;
unsigned int V_9 = 0 , V_10 = 0 ;
unsigned int V_11 ;
T_1 V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , L_1 , NULL , 0 ) ;
if ( V_13 > 0 ) {
T_1 V_14 [ 1 + V_15 ] ;
V_6 -> V_16 =
F_3 ( int , V_15 , V_13 ) ;
F_2 ( V_2 , L_1 , V_14 ,
V_6 -> V_16 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_16 ; V_11 ++ ) {
if ( V_10 & F_4 ( V_14 [ V_11 ] ) )
F_5 ( L_2 ,
V_14 [ V_11 ] ) ;
V_10 |= F_4 ( V_14 [ V_11 ] ) ;
V_6 -> V_17 [ V_11 ] = V_14 [ V_11 ] ;
}
V_13 = F_2 ( V_2 ,
L_3 , NULL ,
0 ) ;
if ( V_13 > 0 ) {
if ( V_13 != 1 + V_6 -> V_16 ) {
F_5 ( L_4 ,
1 + V_6 -> V_16 , V_13 ) ;
return - V_18 ;
}
F_2 ( V_2 ,
L_3 , V_14 ,
1 + V_6 -> V_16 ) ;
for ( V_11 = 0 ; V_11 < 1 + V_6 -> V_16 ; V_11 ++ )
V_6 -> V_19 [ V_11 ] = V_14 [ V_11 ] ;
}
}
if ( ! F_6 ( V_2 , L_5 , & V_12 ) ) {
if ( V_10 & F_4 ( V_12 ) )
F_5 ( L_6 , V_12 ) ;
V_10 |= F_4 ( V_12 ) ;
V_6 -> V_20 = V_12 ;
V_8 = true ;
}
if ( F_7 ( V_2 , L_7 ) )
V_9 |= V_21 ;
else if ( V_8 || V_6 -> V_16 > 0 )
V_9 |= V_22 ;
V_6 -> V_9 = V_9 ;
V_4 -> V_23 = V_24 ;
return 0 ;
}
static void F_8 (
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_25 * V_6 = & V_4 -> V_6 . V_26 ;
unsigned int V_9 = 0 ;
T_1 V_12 ;
if ( ! F_6 ( V_2 , L_8 , & V_12 ) )
V_9 |= V_12 ? V_27 :
V_28 ;
if ( ! F_6 ( V_2 , L_9 , & V_12 ) )
V_9 |= V_12 ? V_29 :
V_30 ;
if ( ! F_6 ( V_2 , L_10 , & V_12 ) )
V_9 |= V_12 ? V_31 :
V_32 ;
if ( V_9 )
V_4 -> V_23 = V_33 ;
else
V_4 -> V_23 = V_34 ;
if ( ! F_6 ( V_2 , L_11 , & V_12 ) )
V_9 |= V_12 ? V_35 :
V_36 ;
if ( ! F_6 ( V_2 , L_12 , & V_12 ) )
V_9 |= V_12 ? V_37 :
V_38 ;
if ( F_7 ( V_2 , L_13 ) )
V_9 |= V_39 ;
else
V_9 |= V_40 ;
if ( ! F_6 ( V_2 , L_14 , & V_12 ) )
V_6 -> V_41 = V_12 ;
if ( ! F_6 ( V_2 , L_15 , & V_12 ) )
V_6 -> V_42 = V_12 ;
if ( ! F_6 ( V_2 , L_16 , & V_12 ) )
V_9 |= V_12 ? V_43 :
V_44 ;
V_6 -> V_9 = V_9 ;
}
static void
F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_23 )
{
struct V_45 * V_6 = & V_4 -> V_6 . V_46 ;
T_1 V_12 ;
if ( ! F_6 ( V_2 , L_17 , & V_12 ) )
V_6 -> V_47 = V_12 ;
if ( ! F_6 ( V_2 , L_18 , & V_12 ) )
V_6 -> V_48 = V_12 ;
if ( ! F_6 ( V_2 , L_1 , & V_12 ) )
V_6 -> V_49 = V_12 ;
if ( ! F_6 ( V_2 , L_5 , & V_12 ) )
V_6 -> V_20 = V_12 ;
if ( V_23 == V_50 )
V_4 -> V_23 = V_51 ;
else
V_4 -> V_23 = V_52 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_23 = 0 ;
int V_13 ;
F_11 ( V_2 , & V_4 -> V_53 ) ;
memset ( & V_4 -> V_23 , 0 , sizeof( * V_4 ) -
F_12 ( F_13 ( * V_4 ) , V_23 ) ) ;
F_6 ( V_2 , L_19 , & V_23 ) ;
switch ( V_23 ) {
case V_54 :
V_13 = F_1 ( V_2 , V_4 ) ;
if ( V_13 )
return V_13 ;
if ( V_4 -> V_6 . V_7 . V_9 == 0 )
F_8 ( V_2 , V_4 ) ;
return 0 ;
case V_50 :
case V_55 :
F_9 ( V_2 , V_4 , V_23 ) ;
return 0 ;
default:
F_5 ( L_20 , V_23 ) ;
return - V_18 ;
}
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( V_4 ) )
return;
F_16 ( V_4 -> V_56 ) ;
F_16 ( V_4 ) ;
}
struct V_3 * F_17 (
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_13 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return F_19 ( - V_58 ) ;
V_13 = F_10 ( V_2 , V_4 ) ;
if ( V_13 < 0 )
goto V_59;
V_13 = F_20 ( V_2 , L_21 ,
NULL , 0 ) ;
if ( V_13 > 0 ) {
V_4 -> V_56 =
F_21 ( V_13 , sizeof( * V_4 -> V_56 ) ,
V_57 ) ;
if ( ! V_4 -> V_56 ) {
V_13 = - V_58 ;
goto V_59;
}
V_4 -> V_60 = V_13 ;
V_13 = F_20 (
V_2 , L_21 , V_4 -> V_56 ,
V_4 -> V_60 ) ;
if ( V_13 < 0 )
goto V_59;
}
return V_4 ;
V_59:
F_14 ( V_4 ) ;
return F_19 ( V_13 ) ;
}
int F_22 ( struct V_1 * V_61 ,
struct V_62 * V_63 )
{
const char * V_64 = F_23 ( V_61 ) ? L_22 : L_23 ;
struct V_1 * V_2 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_2 = F_24 ( V_61 ) ;
F_6 ( V_2 , V_64 , & V_63 -> V_65 ) ;
V_2 = F_25 ( V_2 ) ;
if ( F_23 ( V_2 ) &&
F_26 ( F_27 ( V_2 ) -> V_66 , L_24 ) == 0 )
V_2 = F_25 ( V_2 ) ;
V_63 -> V_67 = V_2 ;
V_2 = F_28 ( V_61 ) ;
if ( ! V_2 ) {
F_29 ( V_2 ) ;
return - V_68 ;
}
V_2 = F_24 ( V_2 ) ;
F_6 ( V_2 , V_64 , & V_63 -> V_69 ) ;
V_2 = F_25 ( V_2 ) ;
if ( F_23 ( V_2 ) &&
F_26 ( F_27 ( V_2 ) -> V_66 , L_24 ) == 0 )
V_2 = F_25 ( V_2 ) ;
V_63 -> V_70 = V_2 ;
return 0 ;
}
void F_30 ( struct V_62 * V_63 )
{
F_29 ( V_63 -> V_67 ) ;
F_29 ( V_63 -> V_70 ) ;
}
