static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
struct {
T_3 V_3 ;
T_3 V_4 ;
} V_5 ;
V_5 . V_3 = F_2 ( V_3 ) ;
V_5 . V_4 = F_2 ( V_4 ) ;
return F_3 ( V_2 , L_1 ,
& V_5 , sizeof( V_5 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 * V_4 )
{
* V_4 = V_3 ;
return F_5 ( V_2 , L_1 , V_4 ) ;
}
static void F_6 ( struct V_6 * V_7 ,
bool V_8 )
{
struct V_1 * V_2 = F_7 ( V_7 -> V_9 -> V_10 , 0 ) ;
if ( V_8 && ! V_7 -> V_11 ) {
F_8 ( V_12 , L_2 ) ;
F_4 ( V_2 , 50 , & V_7 -> V_13 ) ;
F_4 ( V_2 , 51 , & V_7 -> V_14 ) ;
F_4 ( V_2 , 64 , & V_7 -> V_15 ) ;
F_4 ( V_2 , 65 , & V_7 -> V_16 ) ;
F_4 ( V_2 , 71 , & V_7 -> V_17 ) ;
V_7 -> V_11 = true ;
F_8 ( V_12 ,
L_3 ,
V_7 -> V_13 , V_7 -> V_14 , V_7 -> V_15 ,
V_7 -> V_16 , V_7 -> V_17 ) ;
F_1 ( V_2 , 50 , V_18 ) ;
F_1 ( V_2 , 51 , V_19 ) ;
F_1 ( V_2 , 64 , V_20 ) ;
F_1 ( V_2 , 65 , V_21 ) ;
F_1 ( V_2 , 71 , V_22 ) ;
} else if ( V_7 -> V_11 ) {
F_8 ( V_12 , L_4 ) ;
F_1 ( V_2 , 50 , V_7 -> V_13 ) ;
F_1 ( V_2 , 51 , V_7 -> V_14 ) ;
F_1 ( V_2 , 64 , V_7 -> V_15 ) ;
F_1 ( V_2 , 65 , V_7 -> V_16 ) ;
F_1 ( V_2 , 71 , V_7 -> V_17 ) ;
F_8 ( V_12 ,
L_5 ,
V_7 -> V_13 , V_7 -> V_14 , V_7 -> V_15 ,
V_7 -> V_16 , V_7 -> V_17 ) ;
V_7 -> V_11 = false ;
} else {
F_8 ( V_12 , L_6 ) ;
}
}
static bool F_9 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
bool V_24 = false ;
int V_25 = 0 ;
T_2 V_26 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_23 = F_4 ( V_2 , 27 , & V_26 ) ;
if ( V_23 < 0 ) {
F_10 ( L_7 ) ;
break;
}
F_8 ( V_12 , L_8 , V_27 , V_26 ) ;
if ( ( V_26 & 0x6 ) == 2 ) {
V_25 ++ ;
}
if ( V_25 > 2 ) {
F_8 ( V_12 ,
L_9 ,
V_25 , V_27 ) ;
V_24 = true ;
break;
}
}
F_8 ( V_29 , L_10 , V_24 ) ;
return V_24 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_30 -> V_2 ;
if ( ! V_7 -> V_31 ) {
F_4 ( V_2 , 66 , & V_7 -> V_32 ) ;
F_4 ( V_2 , 41 , & V_7 -> V_33 ) ;
F_4 ( V_2 , 68 , & V_7 -> V_34 ) ;
V_7 -> V_31 = true ;
F_8 ( V_12 ,
L_11 ,
V_7 -> V_32 , V_7 -> V_33 ,
V_7 -> V_34 ) ;
}
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
if ( V_7 -> V_31 ) {
V_7 -> V_31 = false ;
V_2 = V_7 -> V_30 -> V_2 ;
F_1 ( V_2 , 66 , V_7 -> V_32 ) ;
F_1 ( V_2 , 41 , V_7 -> V_33 ) ;
F_1 ( V_2 , 68 , V_7 -> V_34 ) ;
F_8 ( V_12 ,
L_12 ,
V_7 -> V_32 , V_7 -> V_33 ,
V_7 -> V_34 ) ;
}
}
static void F_13 ( T_4 V_4 )
{
struct V_6 * V_35 = (struct V_6 * ) V_4 ;
F_8 ( V_29 , L_13 ) ;
V_35 -> V_36 = false ;
F_14 ( & V_35 -> V_37 ) ;
}
static void F_15 ( struct V_38 * V_37 )
{
struct V_6 * V_7 ;
V_7 = F_16 ( V_37 , struct V_6 , V_37 ) ;
if ( V_7 -> V_36 ) {
V_7 -> V_36 = false ;
F_17 ( & V_7 -> V_39 ) ;
}
switch ( V_7 -> V_40 ) {
case V_41 :
F_8 ( V_12 , L_14 ) ;
V_7 -> V_40 = V_42 ;
if ( V_7 -> V_43 < V_44 ) {
F_18 ( & V_7 -> V_39 , V_7 -> V_39 . V_45 ) ;
} else {
V_7 -> V_43 -= V_44 ;
F_18 ( & V_7 -> V_39 ,
V_46 + V_44 ) ;
}
V_7 -> V_36 = true ;
break;
case V_42 :
if ( V_7 -> V_47 ) {
F_8 ( V_12 , L_15 ) ;
goto V_48;
}
F_8 ( V_12 , L_16 ,
F_19 ( V_44 ) ) ;
F_6 ( V_7 , true ) ;
V_7 -> V_40 = V_49 ;
F_18 ( & V_7 -> V_39 , V_46 + V_7 -> V_43 ) ;
V_7 -> V_36 = true ;
break;
case V_49 :
if ( V_7 -> V_47 )
F_8 ( V_12 , L_17 ) ;
else
F_8 ( V_12 , L_18 ,
V_49 ) ;
goto V_48;
default:
F_10 ( L_19 , V_7 -> V_40 ) ;
goto V_48;
}
return;
V_48:
V_7 -> V_40 = V_50 ;
V_7 -> V_36 = false ;
F_6 ( V_7 , false ) ;
F_20 ( & V_7 -> V_30 -> V_51 , V_52 ) ;
F_12 ( V_7 ) ;
V_7 -> V_30 = NULL ;
}
int F_21 ( struct V_53 * V_9 )
{
struct V_6 * V_7 = NULL ;
F_8 ( V_29 , L_13 ) ;
V_7 = F_22 ( sizeof( struct V_6 ) , V_52 ) ;
if ( ! V_7 )
return - V_54 ;
V_7 -> V_40 = V_50 ;
V_7 -> V_36 = false ;
V_7 -> V_43 = V_44 ;
F_23 ( & V_7 -> V_39 , F_13 , ( T_4 ) V_7 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_31 = false ;
V_7 -> V_11 = false ;
F_24 ( & V_7 -> V_37 , F_15 ) ;
V_9 -> V_55 = V_7 ;
return 0 ;
}
void F_25 ( struct V_53 * V_9 )
{
F_8 ( V_29 , L_13 ) ;
if ( ! V_9 -> V_55 )
return;
if ( V_9 -> V_55 -> V_36 ) {
V_9 -> V_55 -> V_36 = false ;
F_17 ( & V_9 -> V_55 -> V_39 ) ;
}
F_26 ( & V_9 -> V_55 -> V_37 ) ;
F_6 ( V_9 -> V_55 , false ) ;
F_12 ( V_9 -> V_55 ) ;
F_27 ( V_9 -> V_55 ) ;
V_9 -> V_55 = NULL ;
}
static void F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_30 -> V_2 ;
F_11 ( V_7 ) ;
F_1 ( V_2 , 66 , V_56 ) ;
F_1 ( V_2 , 41 , V_57 ) ;
F_1 ( V_2 , 68 , V_58 ) ;
V_7 -> V_47 = false ;
V_7 -> V_40 = V_41 ;
F_14 ( & V_7 -> V_37 ) ;
F_8 ( V_29 , L_20 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
V_7 -> V_47 = true ;
if ( V_7 -> V_36 ) {
F_8 ( V_12 , L_21 ) ;
V_7 -> V_36 = false ;
F_17 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_40 != V_50 ) {
F_8 ( V_12 , L_22 ,
V_7 -> V_40 ) ;
F_14 ( & V_7 -> V_37 ) ;
}
} else {
F_12 ( V_7 ) ;
}
}
int F_30 ( struct V_59 * V_30 ,
enum V_60 V_61 , T_5 V_62 )
{
struct V_53 * V_9 = F_31 ( V_30 -> V_51 . V_63 ) ;
struct V_6 * V_7 = V_9 -> V_55 ;
struct V_1 * V_2 = F_7 ( V_9 -> V_10 , 0 ) ;
switch ( V_61 ) {
case V_64 :
F_8 ( V_12 , L_23 ) ;
if ( V_7 -> V_40 != V_50 )
return - V_65 ;
if ( F_9 ( V_2 ) ) {
V_7 -> V_43 = F_32 ( V_62 ) ;
V_7 -> V_30 = V_30 ;
F_28 ( V_7 ) ;
}
break;
case V_66 :
F_8 ( V_12 , L_24 ) ;
if ( V_7 -> V_40 != V_50 &&
V_30 == V_7 -> V_30 ) {
F_29 ( V_7 ) ;
}
break;
default:
F_8 ( V_12 , L_25 ) ;
}
return 0 ;
}
