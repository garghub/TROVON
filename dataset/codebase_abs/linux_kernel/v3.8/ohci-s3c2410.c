static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 -> V_6 ;
}
static void F_2 ( struct V_7 * V_8 , struct V_2 * V_3 )
{
struct V_1 * V_9 = V_8 -> V_8 . V_6 ;
F_3 ( & V_8 -> V_8 , L_1 ) ;
F_4 ( V_10 ) ;
F_5 ( 2 ) ;
F_4 ( V_11 ) ;
if ( V_9 != NULL ) {
V_9 -> V_3 = V_3 ;
V_9 -> V_12 = V_13 ;
if ( V_9 -> V_14 != NULL )
( V_9 -> V_14 ) ( V_9 , 1 ) ;
}
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_9 = V_8 -> V_8 . V_6 ;
F_3 ( & V_8 -> V_8 , L_2 ) ;
if ( V_9 != NULL ) {
V_9 -> V_12 = NULL ;
V_9 -> V_3 = NULL ;
if ( V_9 -> V_14 != NULL )
( V_9 -> V_14 ) ( V_9 , 0 ) ;
}
F_7 ( V_11 ) ;
F_7 ( V_10 ) ;
}
static int
F_8 ( struct V_2 * V_3 , char * V_15 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
int V_18 ;
int V_19 ;
V_18 = F_9 ( V_3 , V_15 ) ;
if ( V_9 == NULL )
return V_18 ;
V_17 = & V_9 -> V_17 [ 0 ] ;
for ( V_19 = 0 ; V_19 < 2 ; V_17 ++ , V_19 ++ ) {
if ( V_17 -> V_20 == 1 &&
V_17 -> V_21 & V_22 ) {
F_3 ( V_3 -> V_4 . V_5 ,
L_3 , V_19 ) ;
if ( V_18 < 1 )
V_18 = 1 ;
V_15 [ 0 ] |= 1 << ( V_19 + 1 ) ;
}
}
return V_18 ;
}
static void F_10 ( struct V_1 * V_9 ,
int V_17 , int V_23 )
{
if ( V_9 == NULL )
return;
if ( V_9 -> V_24 != NULL ) {
V_9 -> V_17 [ V_17 - 1 ] . V_25 = V_23 ;
( V_9 -> V_24 ) ( V_17 - 1 , V_23 ) ;
}
}
static int F_11 (
struct V_2 * V_3 ,
T_1 V_26 ,
T_1 V_27 ,
T_1 V_28 ,
char * V_15 ,
T_1 V_29 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_30 * V_31 ;
int V_32 = - V_33 ;
T_2 * V_34 = ( T_2 * ) V_15 ;
F_3 ( V_3 -> V_4 . V_5 ,
L_4 ,
V_3 , V_26 , V_27 , V_28 , V_15 , V_29 ) ;
if ( V_9 == NULL ) {
V_32 = F_12 ( V_3 , V_26 , V_27 ,
V_28 , V_15 , V_29 ) ;
goto V_35;
}
switch ( V_26 ) {
case V_36 :
if ( V_27 == V_37 ) {
F_3 ( V_3 -> V_4 . V_5 , L_5 ) ;
F_10 ( V_9 , V_28 , 1 ) ;
goto V_35;
}
break;
case V_38 :
switch ( V_27 ) {
case V_39 :
F_3 ( V_3 -> V_4 . V_5 ,
L_6 ) ;
if ( F_13 ( V_28 ) ) {
V_9 -> V_17 [ V_28 - 1 ] . V_20 = 0 ;
V_9 -> V_17 [ V_28 - 1 ] . V_40 = 0 ;
}
goto V_35;
case V_41 :
F_3 ( V_3 -> V_4 . V_5 ,
L_7 ) ;
if ( F_13 ( V_28 ) )
V_9 -> V_17 [ V_28 - 1 ] . V_40 = 0 ;
goto V_35;
case V_37 :
F_3 ( V_3 -> V_4 . V_5 ,
L_8 ) ;
if ( F_13 ( V_28 ) ) {
F_10 ( V_9 , V_28 , 0 ) ;
return 0 ;
}
}
break;
}
V_32 = F_12 ( V_3 , V_26 , V_27 , V_28 , V_15 , V_29 ) ;
if ( V_32 )
goto V_35;
switch ( V_26 ) {
case V_42 :
V_31 = (struct V_30 * ) V_15 ;
if ( V_9 -> V_24 == NULL )
return V_32 ;
F_3 ( V_3 -> V_4 . V_5 , L_9 ,
V_31 -> V_43 ) ;
V_31 -> V_43 &= ~ F_14 ( V_44 ) ;
V_31 -> V_43 |= F_14 ( 0x0001 ) ;
if ( V_9 -> V_14 ) {
V_31 -> V_43 &= ~ F_14 (
V_45 ) ;
V_31 -> V_43 |= F_14 (
0x0008 |
0x0001 ) ;
}
F_3 ( V_3 -> V_4 . V_5 , L_10 ,
V_31 -> V_43 ) ;
return V_32 ;
case V_46 :
F_3 ( V_3 -> V_4 . V_5 , L_11 , V_28 ) ;
if ( F_13 ( V_28 ) ) {
if ( V_9 -> V_17 [ V_28 - 1 ] . V_20 )
* V_34 |= F_15 ( V_47 ) ;
if ( V_9 -> V_17 [ V_28 - 1 ] . V_40 )
* V_34 |= F_15 ( V_48 ) ;
}
}
V_35:
return V_32 ;
}
static void V_13 ( struct V_1 * V_9 , int V_49 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 ;
unsigned long V_21 ;
int V_19 ;
if ( V_9 == NULL )
return;
V_17 = & V_9 -> V_17 [ 0 ] ;
V_3 = V_9 -> V_3 ;
F_16 ( V_21 ) ;
for ( V_19 = 0 ; V_19 < 2 ; V_17 ++ , V_19 ++ ) {
if ( V_49 & ( 1 << V_19 ) &&
V_17 -> V_21 & V_22 ) {
V_17 -> V_40 = 1 ;
V_17 -> V_20 = 1 ;
F_10 ( V_9 , V_19 + 1 , 0 ) ;
}
}
F_17 ( V_21 ) ;
}
static void
F_18 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
F_19 ( V_3 ) ;
F_6 ( V_8 ) ;
F_20 ( V_3 ) ;
}
static int F_21 ( const struct V_50 * V_51 ,
struct V_7 * V_8 )
{
struct V_2 * V_3 = NULL ;
int V_52 ;
F_10 ( V_8 -> V_8 . V_6 , 1 , 1 ) ;
F_10 ( V_8 -> V_8 . V_6 , 2 , 1 ) ;
V_3 = F_22 ( V_51 , & V_8 -> V_8 , L_12 ) ;
if ( V_3 == NULL )
return - V_53 ;
V_3 -> V_54 = V_8 -> V_55 [ 0 ] . V_56 ;
V_3 -> V_57 = F_23 ( & V_8 -> V_55 [ 0 ] ) ;
V_3 -> V_58 = F_24 ( & V_8 -> V_8 , & V_8 -> V_55 [ 0 ] ) ;
if ( ! V_3 -> V_58 ) {
F_25 ( & V_8 -> V_8 , L_13 ) ;
V_52 = - V_53 ;
goto V_59;
}
V_11 = F_26 ( & V_8 -> V_8 , L_14 ) ;
if ( F_27 ( V_11 ) ) {
F_25 ( & V_8 -> V_8 , L_15 ) ;
V_52 = F_28 ( V_11 ) ;
goto V_59;
}
V_10 = F_26 ( & V_8 -> V_8 , L_16 ) ;
if ( F_27 ( V_10 ) ) {
F_25 ( & V_8 -> V_8 , L_17 ) ;
V_52 = F_28 ( V_10 ) ;
goto V_59;
}
F_2 ( V_8 , V_3 ) ;
F_29 ( F_30 ( V_3 ) ) ;
V_52 = F_31 ( V_3 , V_8 -> V_55 [ 1 ] . V_56 , 0 ) ;
if ( V_52 != 0 )
goto V_60;
return 0 ;
V_60:
F_6 ( V_8 ) ;
V_59:
F_20 ( V_3 ) ;
return V_52 ;
}
static int
F_32 ( struct V_2 * V_3 )
{
struct V_61 * V_62 = F_30 ( V_3 ) ;
int V_32 ;
V_32 = F_33 ( V_62 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_34 ( V_62 ) ;
if ( V_32 < 0 ) {
F_25 ( V_3 -> V_4 . V_5 , L_18 ,
V_3 -> V_4 . V_63 ) ;
F_35 ( V_3 ) ;
return V_32 ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_64 )
{
return F_21 ( & V_65 , V_64 ) ;
}
static int F_37 ( struct V_7 * V_64 )
{
struct V_2 * V_3 = F_38 ( V_64 ) ;
F_18 ( V_3 , V_64 ) ;
return 0 ;
}
static int F_39 ( struct V_66 * V_8 )
{
struct V_2 * V_3 = F_40 ( V_8 ) ;
struct V_61 * V_62 = F_30 ( V_3 ) ;
struct V_7 * V_64 = F_41 ( V_8 ) ;
unsigned long V_21 ;
int V_67 = 0 ;
F_42 ( & V_62 -> V_68 , V_21 ) ;
if ( V_62 -> V_69 != V_70 ) {
V_67 = - V_33 ;
goto V_71;
}
F_43 ( V_72 , & V_3 -> V_21 ) ;
F_6 ( V_64 ) ;
V_71:
F_44 ( & V_62 -> V_68 , V_21 ) ;
return V_67 ;
}
static int F_45 ( struct V_66 * V_8 )
{
struct V_2 * V_3 = F_40 ( V_8 ) ;
struct V_7 * V_64 = F_41 ( V_8 ) ;
F_2 ( V_64 , V_3 ) ;
F_46 ( V_3 , false ) ;
return 0 ;
}
