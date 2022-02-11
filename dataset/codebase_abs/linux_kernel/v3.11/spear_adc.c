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
T_1 V_29 ;
T_1 V_5 ;
switch ( V_28 ) {
case V_30 :
F_16 ( & V_24 -> V_31 ) ;
V_5 = F_17 ( V_26 -> V_32 ) |
F_18 ( V_2 -> V_33 ) |
V_34 | V_35 ;
if ( V_2 -> V_36 == 0 )
V_5 |= V_37 ;
F_1 ( V_2 , V_5 ) ;
F_19 ( & V_2 -> V_38 ) ;
* V_3 = V_2 -> V_39 ;
F_20 ( & V_24 -> V_31 ) ;
return V_40 ;
case V_41 :
V_29 = ( V_2 -> V_36 * 1000 ) >> V_42 ;
* V_3 = V_29 / 1000 ;
* V_27 = ( V_29 % 1000 ) * 1000 ;
return V_43 ;
}
return - V_44 ;
}
static T_2 F_21 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
V_2 -> V_39 = F_8 ( V_2 ) ;
F_22 ( & V_2 -> V_38 ) ;
return V_47 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_48 ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0 , & V_2 -> V_4 -> V_10 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
F_7 ( V_2 , V_48 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_3 ( V_2 , V_2 -> V_49 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_23 * V_24 = F_25 ( V_51 ) ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
return sprintf ( V_54 , L_2 , V_2 -> V_11 ) ;
}
static T_3 F_26 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 ,
T_4 V_55 )
{
struct V_23 * V_24 = F_25 ( V_51 ) ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
T_1 V_6 , V_7 , V_8 ;
T_1 V_9 = F_4 ( V_2 -> V_10 ) ;
unsigned long V_56 ;
int V_57 ;
V_57 = F_27 ( V_54 , 10 , & V_56 ) ;
if ( V_57 )
return V_57 ;
F_16 ( & V_24 -> V_31 ) ;
if ( ( V_56 < V_58 ) || ( V_56 > V_59 ) ) {
V_57 = - V_44 ;
goto V_60;
}
V_8 = ( V_9 + V_56 - 1 ) / V_56 ;
V_7 = V_8 / 2 ;
V_6 = V_8 - V_7 ;
V_2 -> V_11 = V_9 / V_8 ;
F_3 ( V_2 , V_56 ) ;
V_60:
F_20 ( & V_24 -> V_31 ) ;
return V_57 ? V_57 : V_55 ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_63 * V_14 = V_62 -> V_51 . V_64 ;
struct V_50 * V_51 = & V_62 -> V_51 ;
struct V_1 * V_2 ;
struct V_23 * V_65 = NULL ;
int V_57 = - V_66 ;
int V_45 ;
V_65 = F_29 ( sizeof( struct V_1 ) ) ;
if ( ! V_65 ) {
F_30 ( V_51 , L_3 ) ;
V_57 = - V_67 ;
goto V_68;
}
V_2 = F_15 ( V_65 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = F_31 ( V_14 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_30 ( V_51 , L_4 ) ;
V_57 = - V_67 ;
goto V_69;
}
V_2 -> V_18 =
(struct V_70 * ) V_2 -> V_4 ;
V_2 -> V_10 = F_32 ( V_51 , NULL ) ;
if ( F_33 ( V_2 -> V_10 ) ) {
F_30 ( V_51 , L_5 ) ;
goto V_71;
}
V_57 = F_34 ( V_2 -> V_10 ) ;
if ( V_57 ) {
F_30 ( V_51 , L_6 ) ;
goto V_72;
}
V_45 = F_35 ( V_62 , 0 ) ;
if ( ( V_45 < 0 ) || ( V_45 >= V_73 ) ) {
F_30 ( V_51 , L_7 ) ;
V_57 = - V_44 ;
goto V_74;
}
V_57 = F_36 ( V_51 , V_45 , F_21 , 0 , V_75 , V_2 ) ;
if ( V_57 < 0 ) {
F_30 ( V_51 , L_8 ) ;
goto V_74;
}
if ( F_37 ( V_14 , L_9 ,
& V_2 -> V_49 ) ) {
F_30 ( V_51 , L_10 ) ;
V_57 = - V_44 ;
goto V_74;
}
F_37 ( V_14 , L_11 , & V_2 -> V_33 ) ;
F_37 ( V_14 , L_12 , & V_2 -> V_36 ) ;
F_23 ( V_2 ) ;
F_38 ( V_62 , V_65 ) ;
F_39 ( & V_2 -> V_38 ) ;
V_65 -> V_76 = V_75 ;
V_65 -> V_51 . V_77 = V_51 ;
V_65 -> V_2 = & V_78 ;
V_65 -> V_79 = V_80 ;
V_65 -> V_81 = V_82 ;
V_65 -> V_83 = F_40 ( V_82 ) ;
V_57 = F_41 ( V_65 ) ;
if ( V_57 )
goto V_74;
F_42 ( V_51 , L_13 , V_45 ) ;
return 0 ;
V_74:
F_43 ( V_2 -> V_10 ) ;
V_72:
F_44 ( V_2 -> V_10 ) ;
V_71:
F_45 ( V_2 -> V_4 ) ;
V_69:
F_46 ( V_65 ) ;
V_68:
return V_57 ;
}
static int F_47 ( struct V_61 * V_62 )
{
struct V_23 * V_65 = F_48 ( V_62 ) ;
struct V_1 * V_2 = F_15 ( V_65 ) ;
F_49 ( V_65 ) ;
F_43 ( V_2 -> V_10 ) ;
F_44 ( V_2 -> V_10 ) ;
F_45 ( V_2 -> V_4 ) ;
F_46 ( V_65 ) ;
return 0 ;
}
