static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_2 ( & V_7 -> V_7 ) ;
F_4 ( & V_7 -> V_7 , L_1 ) ;
F_5 ( V_9 ) ;
F_6 ( 2 ) ;
F_5 ( V_10 ) ;
if ( V_8 != NULL ) {
V_8 -> V_3 = V_3 ;
V_8 -> V_11 = V_12 ;
if ( V_8 -> V_13 != NULL )
( V_8 -> V_13 ) ( V_8 , 1 ) ;
}
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_2 ( & V_7 -> V_7 ) ;
F_4 ( & V_7 -> V_7 , L_2 ) ;
if ( V_8 != NULL ) {
V_8 -> V_11 = NULL ;
V_8 -> V_3 = NULL ;
if ( V_8 -> V_13 != NULL )
( V_8 -> V_13 ) ( V_8 , 0 ) ;
}
F_8 ( V_10 ) ;
F_8 ( V_9 ) ;
}
static int
F_9 ( struct V_2 * V_3 , char * V_14 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
V_17 = F_10 ( V_3 , V_14 ) ;
if ( V_8 == NULL )
return V_17 ;
V_16 = & V_8 -> V_16 [ 0 ] ;
for ( V_18 = 0 ; V_18 < 2 ; V_16 ++ , V_18 ++ ) {
if ( V_16 -> V_19 == 1 &&
V_16 -> V_20 & V_21 ) {
F_4 ( V_3 -> V_4 . V_5 ,
L_3 , V_18 ) ;
if ( V_17 < 1 )
V_17 = 1 ;
V_14 [ 0 ] |= 1 << ( V_18 + 1 ) ;
}
}
return V_17 ;
}
static void F_11 ( struct V_1 * V_8 ,
int V_16 , int V_22 )
{
if ( V_8 == NULL )
return;
if ( V_8 -> V_23 != NULL ) {
V_8 -> V_16 [ V_16 - 1 ] . V_24 = V_22 ;
( V_8 -> V_23 ) ( V_16 - 1 , V_22 ) ;
}
}
static int F_12 (
struct V_2 * V_3 ,
T_1 V_25 ,
T_1 V_26 ,
T_1 V_27 ,
char * V_14 ,
T_1 V_28 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_29 * V_30 ;
int V_31 = - V_32 ;
T_2 * V_33 = ( T_2 * ) V_14 ;
F_4 ( V_3 -> V_4 . V_5 ,
L_4 ,
V_3 , V_25 , V_26 , V_27 , V_14 , V_28 ) ;
if ( V_8 == NULL ) {
V_31 = F_13 ( V_3 , V_25 , V_26 ,
V_27 , V_14 , V_28 ) ;
goto V_34;
}
switch ( V_25 ) {
case V_35 :
if ( V_26 == V_36 ) {
F_4 ( V_3 -> V_4 . V_5 , L_5 ) ;
F_11 ( V_8 , V_27 , 1 ) ;
goto V_34;
}
break;
case V_37 :
switch ( V_26 ) {
case V_38 :
F_4 ( V_3 -> V_4 . V_5 ,
L_6 ) ;
if ( F_14 ( V_27 ) ) {
V_8 -> V_16 [ V_27 - 1 ] . V_19 = 0 ;
V_8 -> V_16 [ V_27 - 1 ] . V_39 = 0 ;
}
goto V_34;
case V_40 :
F_4 ( V_3 -> V_4 . V_5 ,
L_7 ) ;
if ( F_14 ( V_27 ) )
V_8 -> V_16 [ V_27 - 1 ] . V_39 = 0 ;
goto V_34;
case V_36 :
F_4 ( V_3 -> V_4 . V_5 ,
L_8 ) ;
if ( F_14 ( V_27 ) ) {
F_11 ( V_8 , V_27 , 0 ) ;
return 0 ;
}
}
break;
}
V_31 = F_13 ( V_3 , V_25 , V_26 , V_27 , V_14 , V_28 ) ;
if ( V_31 )
goto V_34;
switch ( V_25 ) {
case V_41 :
V_30 = (struct V_29 * ) V_14 ;
if ( V_8 -> V_23 == NULL )
return V_31 ;
F_4 ( V_3 -> V_4 . V_5 , L_9 ,
V_30 -> V_42 ) ;
V_30 -> V_42 &= ~ F_15 ( V_43 ) ;
V_30 -> V_42 |= F_15 ( 0x0001 ) ;
if ( V_8 -> V_13 ) {
V_30 -> V_42 &= ~ F_15 (
V_44 ) ;
V_30 -> V_42 |= F_15 (
0x0008 |
0x0001 ) ;
}
F_4 ( V_3 -> V_4 . V_5 , L_10 ,
V_30 -> V_42 ) ;
return V_31 ;
case V_45 :
F_4 ( V_3 -> V_4 . V_5 , L_11 , V_27 ) ;
if ( F_14 ( V_27 ) ) {
if ( V_8 -> V_16 [ V_27 - 1 ] . V_19 )
* V_33 |= F_16 ( V_46 ) ;
if ( V_8 -> V_16 [ V_27 - 1 ] . V_39 )
* V_33 |= F_16 ( V_47 ) ;
}
}
V_34:
return V_31 ;
}
static void V_12 ( struct V_1 * V_8 , int V_48 )
{
struct V_15 * V_16 ;
struct V_2 * V_3 ;
unsigned long V_20 ;
int V_18 ;
if ( V_8 == NULL )
return;
V_16 = & V_8 -> V_16 [ 0 ] ;
V_3 = V_8 -> V_3 ;
F_17 ( V_20 ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_16 ++ , V_18 ++ ) {
if ( V_48 & ( 1 << V_18 ) &&
V_16 -> V_20 & V_21 ) {
V_16 -> V_39 = 1 ;
V_16 -> V_19 = 1 ;
F_11 ( V_8 , V_18 + 1 , 0 ) ;
}
}
F_18 ( V_20 ) ;
}
static void
F_19 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
F_20 ( V_3 ) ;
F_7 ( V_7 ) ;
F_21 ( V_3 ) ;
}
static int F_22 ( const struct V_49 * V_50 ,
struct V_6 * V_7 )
{
struct V_2 * V_3 = NULL ;
struct V_1 * V_8 = F_2 ( & V_7 -> V_7 ) ;
int V_51 ;
F_11 ( V_8 , 1 , 1 ) ;
F_11 ( V_8 , 2 , 1 ) ;
V_3 = F_23 ( V_50 , & V_7 -> V_7 , L_12 ) ;
if ( V_3 == NULL )
return - V_52 ;
V_3 -> V_53 = V_7 -> V_54 [ 0 ] . V_55 ;
V_3 -> V_56 = F_24 ( & V_7 -> V_54 [ 0 ] ) ;
V_3 -> V_57 = F_25 ( & V_7 -> V_7 , & V_7 -> V_54 [ 0 ] ) ;
if ( F_26 ( V_3 -> V_57 ) ) {
V_51 = F_27 ( V_3 -> V_57 ) ;
goto V_58;
}
V_10 = F_28 ( & V_7 -> V_7 , L_13 ) ;
if ( F_26 ( V_10 ) ) {
F_29 ( & V_7 -> V_7 , L_14 ) ;
V_51 = F_27 ( V_10 ) ;
goto V_58;
}
V_9 = F_28 ( & V_7 -> V_7 , L_15 ) ;
if ( F_26 ( V_9 ) ) {
F_29 ( & V_7 -> V_7 , L_16 ) ;
V_51 = F_27 ( V_9 ) ;
goto V_58;
}
F_3 ( V_7 , V_3 ) ;
V_51 = F_30 ( V_3 , V_7 -> V_54 [ 1 ] . V_55 , 0 ) ;
if ( V_51 != 0 )
goto V_59;
return 0 ;
V_59:
F_7 ( V_7 ) ;
V_58:
F_21 ( V_3 ) ;
return V_51 ;
}
static int F_31 ( struct V_6 * V_60 )
{
return F_22 ( & V_61 , V_60 ) ;
}
static int F_32 ( struct V_6 * V_60 )
{
struct V_2 * V_3 = F_33 ( V_60 ) ;
F_19 ( V_3 , V_60 ) ;
return 0 ;
}
static int F_34 ( struct V_62 * V_7 )
{
struct V_2 * V_3 = F_35 ( V_7 ) ;
struct V_63 * V_64 = F_36 ( V_3 ) ;
struct V_6 * V_60 = F_37 ( V_7 ) ;
unsigned long V_20 ;
int V_65 = 0 ;
F_38 ( & V_64 -> V_66 , V_20 ) ;
if ( V_64 -> V_67 != V_68 ) {
V_65 = - V_32 ;
goto V_69;
}
F_39 ( V_70 , & V_3 -> V_20 ) ;
F_7 ( V_60 ) ;
V_69:
F_40 ( & V_64 -> V_66 , V_20 ) ;
return V_65 ;
}
static int F_41 ( struct V_62 * V_7 )
{
struct V_2 * V_3 = F_35 ( V_7 ) ;
struct V_6 * V_60 = F_37 ( V_7 ) ;
F_3 ( V_60 , V_3 ) ;
F_42 ( V_3 , false ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
if ( F_44 () )
return - V_71 ;
F_45 ( L_17 V_72 L_18 , V_73 ) ;
F_46 ( & V_61 , NULL ) ;
F_13 = V_61 . V_74 ;
F_10 = V_61 . V_75 ;
V_61 . V_75 = F_9 ;
V_61 . V_74 = F_12 ;
return F_47 ( & V_76 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_76 ) ;
}
