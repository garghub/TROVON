inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 (
V_2 -> V_4 -> V_5 -> V_6 . V_7 ) ;
return V_3 == V_8 ;
}
static int F_3 ( T_2 V_9 , struct V_1 * V_2 )
{
int V_10 ;
int V_11 ;
T_2 * V_12 = NULL ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_12 = F_4 ( sizeof( V_9 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
* V_12 = V_9 ;
V_10 = F_5 ( V_2 -> V_4 -> V_5 ,
F_6 ( V_2 -> V_4 -> V_5 , V_2 -> V_15 ) ,
V_12 , sizeof( V_9 ) ,
& V_11 , V_16 ) ;
F_7 ( V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_11 != sizeof( V_9 ) )
return - V_17 ;
return 0 ;
}
static void F_8 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
struct V_22 * V_23 ;
unsigned char * V_24 = V_18 -> V_25 ;
int V_26 = 0 ;
int V_27 = 0 ;
unsigned long V_28 = 0 ;
F_10 ( & V_2 -> V_5 , L_1 , V_29 ) ;
switch ( V_18 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_10 ( & V_2 -> V_5 ,
L_2 ,
V_29 , V_18 -> V_30 ) ;
return;
default:
F_10 ( & V_2 -> V_5 ,
L_3 ,
V_29 , V_18 -> V_30 ) ;
goto exit;
}
V_23 = F_11 ( & V_2 -> V_2 ) ;
if ( ! V_23 ) {
F_12 ( & V_2 -> V_5 , L_4 ,
V_29 ) ;
return;
}
if ( V_23 && V_18 -> V_34 ) {
F_13 ( V_23 , V_24 , V_18 -> V_34 ) ;
F_14 ( V_23 ) ;
}
F_15 ( V_23 ) ;
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_26 = V_21 -> V_26 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
if ( ! V_26 ) {
F_18 ( V_2 -> V_36 , V_2 -> V_4 -> V_5 ,
F_19 ( V_2 -> V_4 -> V_5 , V_2 -> V_37 ) ,
V_2 -> V_36 -> V_25 ,
V_2 -> V_36 -> V_38 ,
F_8 , V_2 , 1 ) ;
V_27 = F_20 ( V_2 -> V_36 , V_39 ) ;
if ( V_27 )
F_12 ( & V_2 -> V_5 ,
L_5 ,
V_29 , V_27 ) ;
}
return;
exit:
V_27 = F_20 ( V_18 , V_39 ) ;
if ( V_27 )
F_12 ( & V_2 -> V_5 ,
L_5 ,
V_29 , V_27 ) ;
}
static void F_21 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_22 ( & V_2 -> V_5 , L_6 ,
V_29 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 , L_1 , V_29 ) ;
if ( V_2 -> V_4 -> V_5 ) {
if ( V_2 -> V_36 ) {
F_24 ( V_2 -> V_36 ) ;
F_25 ( V_2 -> V_36 ) ;
}
F_3 ( V_40 , V_2 ) ;
}
}
static int F_26 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_41 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_28 = 0 ;
int V_27 = 0 ;
F_10 ( & V_2 -> V_5 , L_1 , V_29 ) ;
if ( ! V_2 -> V_36 ) {
F_12 ( & V_2 -> V_5 , L_7 ,
V_29 ) ;
return - V_42 ;
}
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_21 -> V_43 = 0 ;
V_21 -> V_26 = 0 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
F_27 ( V_4 -> V_5 , V_2 -> V_36 -> V_44 ) ;
F_18 ( V_2 -> V_36 , V_4 -> V_5 ,
F_19 ( V_4 -> V_5 , V_2 -> V_37 ) ,
V_2 -> V_36 -> V_25 ,
V_2 -> V_36 -> V_38 ,
F_8 , V_2 , 1 ) ;
V_27 = F_20 ( V_2 -> V_36 , V_13 ) ;
if ( V_27 ) {
F_12 ( & V_2 -> V_5 ,
L_5 ,
V_29 , V_27 ) ;
goto exit;
}
V_27 = F_3 ( V_45 , V_2 ) ;
if ( V_27 ) {
F_12 ( & V_2 -> V_5 ,
L_8 ,
V_29 , V_2 -> V_46 , V_27 ) ;
goto exit;
}
F_10 ( & V_2 -> V_5 , L_9 , V_29 ) ;
exit:
return V_27 ;
}
static int F_28 ( struct V_41 * V_4 , unsigned int V_43 )
{
int V_47 = 0 ;
unsigned char V_48 = V_49 ;
F_10 ( & V_4 -> V_5 -> V_5 , L_10 ,
V_29 , V_43 ) ;
if ( V_43 & V_50 )
V_48 |= V_51 ;
if ( V_43 & V_52 )
V_48 |= V_53 ;
V_47 = F_29 ( V_4 -> V_5 , F_30 ( V_4 -> V_5 , 0 ) ,
V_54 , V_55 ,
V_43 , 0 , NULL , 0 , V_56 ) ;
if ( V_47 < 0 )
F_12 ( & V_4 -> V_5 -> V_5 ,
L_11 ,
V_29 , V_48 , V_47 ) ;
return V_47 ;
}
static void F_31 ( struct V_41 * V_4 )
{
int V_57 = 0 ;
F_10 ( & V_4 -> V_5 -> V_5 , L_1 , V_29 ) ;
for ( V_57 = 0 ; V_57 < V_4 -> V_58 ; ++ V_57 ) {
F_23 ( V_4 -> V_2 [ V_57 ] ) ;
F_7 ( F_9 ( V_4 -> V_2 [ V_57 ] ) ) ;
F_32 ( V_4 -> V_2 [ V_57 ] , NULL ) ;
F_10 ( & V_4 -> V_5 -> V_5 , L_12 ,
V_29 , V_4 -> V_2 [ V_57 ] -> V_46 ) ;
}
}
static int F_33 ( struct V_41 * V_4 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_57 = 0 ;
F_10 ( & V_4 -> V_5 -> V_5 , L_1 , V_29 ) ;
for ( V_57 = 0 ; V_57 < V_4 -> V_58 ; ++ V_57 ) {
V_2 = V_4 -> V_2 [ V_57 ] ;
V_21 = F_4 ( sizeof( struct V_20 ) , V_13 ) ;
if ( ! V_21 )
return - V_14 ;
F_34 ( & V_21 -> V_35 ) ;
F_32 ( V_2 , V_21 ) ;
F_10 ( & V_4 -> V_5 -> V_5 , L_13 ,
V_29 , V_2 -> V_46 ) ;
}
return 0 ;
}
static void F_35 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_59 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_28 = 0 ;
F_10 ( V_23 -> V_5 , L_1 , V_29 ) ;
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_21 -> V_26 = 1 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
}
static int F_36 ( struct V_22 * V_23 )
{
unsigned long V_43 = 0 ;
struct V_1 * V_2 = V_23 -> V_59 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_28 = 0 ;
F_10 ( V_23 -> V_5 , L_1 , V_29 ) ;
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_43 = V_21 -> V_43 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
return V_43 ;
}
static int F_37 ( struct V_22 * V_23 ,
unsigned int V_60 , unsigned int V_61 )
{
struct V_1 * V_2 = V_23 -> V_59 ;
struct V_41 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_28 = 0 ;
unsigned long V_43 = 0 ;
F_10 ( V_23 -> V_5 , L_14 , V_29 , V_60 , V_61 ) ;
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_43 = V_21 -> V_43 ;
if ( V_60 & V_52 )
V_43 |= V_52 ;
if ( V_60 & V_50 )
V_43 |= V_50 ;
if ( V_61 & V_52 )
V_43 &= ~ V_52 ;
if ( V_61 & V_50 )
V_43 &= ~ V_50 ;
V_21 -> V_43 = V_43 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
return F_28 ( V_4 , V_43 ) ;
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_59 ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
unsigned long V_28 = 0 ;
int V_27 = 0 ;
F_10 ( V_23 -> V_5 , L_1 , V_29 ) ;
F_16 ( & V_21 -> V_35 , V_28 ) ;
V_21 -> V_26 = 0 ;
F_17 ( & V_21 -> V_35 , V_28 ) ;
V_2 -> V_36 -> V_5 = V_2 -> V_4 -> V_5 ;
V_27 = F_20 ( V_2 -> V_36 , V_39 ) ;
if ( V_27 )
F_12 ( V_23 -> V_5 ,
L_15 ,
V_27 ) ;
}
