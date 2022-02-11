static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , & V_2 -> V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_6 , V_7 , V_8 ;
T_1 V_9 = F_4 ( V_2 -> V_10 ) ;
V_8 = ( V_9 + V_3 - 1 ) / V_3 ;
V_7 = V_8 / 2 ;
V_6 = V_8 - V_7 ;
V_2 -> V_11 = V_9 / V_8 ;
F_2 ( F_5 ( V_7 ) | F_6 ( V_6 ) ,
& V_2 -> V_4 -> V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_12 ,
T_1 V_3 )
{
F_2 ( V_3 , & V_2 -> V_4 -> V_13 [ V_12 ] ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 -> V_14 , L_1 ) ) {
return F_10 ( & V_2 -> V_4 -> V_15 . V_16 ) &
V_17 ;
} else {
return F_10 ( & V_2 -> V_18 -> V_15 ) &
V_17 ;
}
}
static void F_11 ( struct V_1 * V_2 , T_1 V_19 )
{
if ( F_9 ( V_2 -> V_14 , L_1 ) ) {
F_2 ( F_12 ( V_19 ) ,
& V_2 -> V_4 -> V_20 ) ;
F_2 ( F_13 ( V_19 ) ,
& V_2 -> V_4 -> V_21 ) ;
} else {
F_2 ( V_19 , & V_2 -> V_18 -> V_22 ) ;
}
}
static int F_14 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_3 ,
int * V_27 ,
long V_28 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
T_1 V_5 ;
switch ( V_28 ) {
case V_29 :
F_16 ( & V_24 -> V_30 ) ;
V_5 = F_17 ( V_26 -> V_31 ) |
F_18 ( V_2 -> V_32 ) |
V_33 | V_34 ;
if ( V_2 -> V_35 == 0 )
V_5 |= V_36 ;
F_1 ( V_2 , V_5 ) ;
F_19 ( & V_2 -> V_37 ) ;
* V_3 = V_2 -> V_38 ;
F_20 ( & V_24 -> V_30 ) ;
return V_39 ;
case V_40 :
* V_3 = V_2 -> V_35 ;
* V_27 = V_41 ;
return V_42 ;
}
return - V_43 ;
}
static T_2 F_21 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
V_2 -> V_38 = F_8 ( V_2 ) ;
F_22 ( & V_2 -> V_37 ) ;
return V_46 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_47 ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0 , & V_2 -> V_4 -> V_10 ) ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ )
F_7 ( V_2 , V_47 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_3 ( V_2 , V_2 -> V_48 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_23 * V_24 = F_25 ( V_50 ) ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
return sprintf ( V_53 , L_2 , V_2 -> V_11 ) ;
}
static T_3 F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
const char * V_53 ,
T_4 V_54 )
{
struct V_23 * V_24 = F_25 ( V_50 ) ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
T_1 V_6 , V_7 , V_8 ;
T_1 V_9 = F_4 ( V_2 -> V_10 ) ;
unsigned long V_55 ;
int V_56 ;
V_56 = F_27 ( V_53 , 10 , & V_55 ) ;
if ( V_56 )
return V_56 ;
F_16 ( & V_24 -> V_30 ) ;
if ( ( V_55 < V_57 ) || ( V_55 > V_58 ) ) {
V_56 = - V_43 ;
goto V_59;
}
V_8 = ( V_9 + V_55 - 1 ) / V_55 ;
V_7 = V_8 / 2 ;
V_6 = V_8 - V_7 ;
V_2 -> V_11 = V_9 / V_8 ;
F_3 ( V_2 , V_55 ) ;
V_59:
F_20 ( & V_24 -> V_30 ) ;
return V_56 ? V_56 : V_54 ;
}
static int F_28 ( struct V_60 * V_61 )
{
struct V_62 * V_14 = V_61 -> V_50 . V_63 ;
struct V_49 * V_50 = & V_61 -> V_50 ;
struct V_1 * V_2 ;
struct V_23 * V_64 = NULL ;
int V_56 = - V_65 ;
int V_44 ;
V_64 = F_29 ( V_50 , sizeof( struct V_1 ) ) ;
if ( ! V_64 ) {
F_30 ( V_50 , L_3 ) ;
return - V_66 ;
}
V_2 = F_15 ( V_64 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = F_31 ( V_14 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_30 ( V_50 , L_4 ) ;
return - V_66 ;
}
V_2 -> V_18 =
(struct V_67 V_68 * ) V_2 -> V_4 ;
V_2 -> V_10 = F_32 ( V_50 , NULL ) ;
if ( F_33 ( V_2 -> V_10 ) ) {
F_30 ( V_50 , L_5 ) ;
goto V_69;
}
V_56 = F_34 ( V_2 -> V_10 ) ;
if ( V_56 ) {
F_30 ( V_50 , L_6 ) ;
goto V_70;
}
V_44 = F_35 ( V_61 , 0 ) ;
if ( V_44 <= 0 ) {
F_30 ( V_50 , L_7 ) ;
V_56 = - V_43 ;
goto V_71;
}
V_56 = F_36 ( V_50 , V_44 , F_21 , 0 , V_72 , V_2 ) ;
if ( V_56 < 0 ) {
F_30 ( V_50 , L_8 ) ;
goto V_71;
}
if ( F_37 ( V_14 , L_9 ,
& V_2 -> V_48 ) ) {
F_30 ( V_50 , L_10 ) ;
V_56 = - V_43 ;
goto V_71;
}
F_37 ( V_14 , L_11 , & V_2 -> V_32 ) ;
F_37 ( V_14 , L_12 , & V_2 -> V_35 ) ;
F_23 ( V_2 ) ;
F_38 ( V_61 , V_64 ) ;
F_39 ( & V_2 -> V_37 ) ;
V_64 -> V_73 = V_72 ;
V_64 -> V_50 . V_74 = V_50 ;
V_64 -> V_2 = & V_75 ;
V_64 -> V_76 = V_77 ;
V_64 -> V_78 = V_79 ;
V_64 -> V_80 = F_40 ( V_79 ) ;
V_56 = F_41 ( V_64 ) ;
if ( V_56 )
goto V_71;
F_42 ( V_50 , L_13 , V_44 ) ;
return 0 ;
V_71:
F_43 ( V_2 -> V_10 ) ;
V_70:
F_44 ( V_2 -> V_10 ) ;
V_69:
F_45 ( V_2 -> V_4 ) ;
return V_56 ;
}
static int F_46 ( struct V_60 * V_61 )
{
struct V_23 * V_64 = F_47 ( V_61 ) ;
struct V_1 * V_2 = F_15 ( V_64 ) ;
F_48 ( V_64 ) ;
F_43 ( V_2 -> V_10 ) ;
F_44 ( V_2 -> V_10 ) ;
F_45 ( V_2 -> V_4 ) ;
return 0 ;
}
