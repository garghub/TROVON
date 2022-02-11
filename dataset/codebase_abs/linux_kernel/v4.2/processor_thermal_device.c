static int F_1 ( void )
{
T_1 V_1 , V_2 ;
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_5 , & V_1 , & V_2 ) ;
if ( V_4 )
return V_4 ;
V_3 = ( V_1 >> 16 ) & 0xff ;
if ( V_3 )
return V_3 ;
return - V_6 ;
}
static int F_3 ( unsigned long * V_7 )
{
int V_8 ;
T_1 V_1 , V_2 ;
int V_4 ;
unsigned long V_9 = 0 ;
* V_7 = 0 ;
F_4 (cpu) {
V_4 = F_5 ( V_8 , V_10 , & V_1 ,
& V_2 ) ;
if ( V_4 )
goto V_11;
else {
if ( V_1 & 0x80000000 ) {
V_9 = ( V_1 >> 16 ) & 0x7f ;
if ( ! * V_7 || V_9 < * V_7 )
* V_7 = V_9 ;
} else {
V_4 = - V_6 ;
goto V_11;
}
}
}
return 0 ;
V_11:
return V_4 ;
}
static int F_6 ( struct V_12 * V_13 ,
unsigned long * V_7 )
{
int V_14 ;
V_14 = F_3 ( V_7 ) ;
if ( ! V_14 )
* V_7 = ( V_15 - * V_7 ) * 1000 ;
return V_14 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * * V_19 )
{
struct V_18 * V_20 ;
struct V_21 * V_22 ;
T_2 V_23 ;
struct V_24 V_25 = { V_26 , NULL } ;
union V_27 * V_28 , * V_29 ;
union V_27 * V_30 ;
unsigned long long V_31 ;
struct V_32 * V_33 = NULL ;
int V_34 ;
int V_14 ;
V_22 = F_8 ( V_17 ) ;
if ( ! V_22 )
return - V_35 ;
V_23 = F_9 ( V_22 -> V_36 , L_1 , NULL , & V_25 ) ;
if ( F_10 ( V_23 ) )
return - V_35 ;
V_30 = V_25 . V_37 ;
if ( ! V_30 || ( V_30 -> type != V_38 ) ) {
F_11 ( V_17 , L_2 ) ;
V_14 = - V_39 ;
goto V_40;
}
if ( ! V_30 -> V_41 . V_42 ) {
F_11 ( V_17 , L_3 ) ;
V_14 = - V_39 ;
goto V_40;
}
V_20 = F_12 ( V_17 , sizeof( * V_20 ) , V_43 ) ;
if ( ! V_20 ) {
V_14 = - V_44 ;
goto V_40;
}
V_20 -> V_17 = V_17 ;
V_20 -> V_22 = V_22 ;
for ( V_34 = 0 ; V_34 < F_13 ( ( int ) V_30 -> V_41 . V_42 - 1 , 2 ) ; ++ V_34 ) {
V_28 = & ( V_30 -> V_41 . V_28 [ V_34 + 1 ] ) ;
if ( V_28 -> type != V_38 ||
V_28 -> V_41 . V_42 != 6 ) {
V_14 = - V_39 ;
goto V_40;
}
V_29 = V_28 -> V_41 . V_28 ;
V_20 -> V_45 [ V_34 ] . V_46 = V_29 [ 0 ] . integer . V_47 ;
V_20 -> V_45 [ V_34 ] . V_48 = V_29 [ 1 ] . integer . V_47 ;
V_20 -> V_45 [ V_34 ] . V_49 = V_29 [ 2 ] . integer . V_47 ;
V_20 -> V_45 [ V_34 ] . V_50 = V_29 [ 3 ] . integer . V_47 ;
V_20 -> V_45 [ V_34 ] . V_51 = V_29 [ 4 ] . integer . V_47 ;
V_20 -> V_45 [ V_34 ] . V_52 = V_29 [ 5 ] . integer . V_47 ;
}
* V_19 = V_20 ;
V_14 = F_14 ( & V_17 -> V_53 ,
& V_54 ) ;
if ( V_14 )
goto V_40;
V_23 = F_15 ( V_22 -> V_36 , L_4 , NULL , & V_31 ) ;
if ( F_10 ( V_23 ) ) {
V_15 = F_1 () ;
if ( V_15 > 0 )
V_33 = & V_55 ;
}
V_20 -> V_56 = F_16 ( V_22 , V_33 ) ;
if ( F_17 ( V_20 -> V_56 ) ) {
F_18 ( & V_20 -> V_17 -> V_53 ,
& V_54 ) ;
V_14 = F_19 ( V_20 -> V_56 ) ;
} else
V_14 = 0 ;
V_40:
F_20 ( V_25 . V_37 ) ;
return V_14 ;
}
static void F_21 ( struct V_18 * V_20 )
{
F_22 ( V_20 -> V_56 ) ;
F_18 ( & V_20 -> V_17 -> V_53 ,
& V_54 ) ;
}
static int F_23 ( struct V_57 * V_58 )
{
struct V_18 * V_20 ;
int V_14 ;
if ( V_59 == V_60 ) {
F_11 ( & V_58 -> V_17 , L_5 ) ;
return - V_35 ;
}
V_14 = F_7 ( & V_58 -> V_17 , & V_20 ) ;
if ( V_14 )
return V_14 ;
F_24 ( V_58 , V_20 ) ;
V_59 = V_61 ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
F_21 ( F_26 ( V_58 ) ) ;
return 0 ;
}
static T_3 F_27 ( int V_62 , void * V_63 )
{
struct V_18 * V_20 ;
struct V_64 * V_58 = V_63 ;
V_20 = F_28 ( V_58 ) ;
F_29 ( V_20 -> V_65 ) ;
return V_66 ;
}
static int F_30 ( struct V_64 * V_58 ,
const struct V_67 * V_68 )
{
struct V_18 * V_20 ;
int V_14 ;
if ( V_59 == V_61 ) {
F_11 ( & V_58 -> V_17 , L_6 ) ;
return - V_35 ;
}
V_14 = F_31 ( V_58 ) ;
if ( V_14 < 0 ) {
F_11 ( & V_58 -> V_17 , L_7 ) ;
return V_14 ;
}
V_14 = F_7 ( & V_58 -> V_17 , & V_20 ) ;
if ( V_14 ) {
F_32 ( V_58 ) ;
return V_14 ;
}
F_33 ( V_58 , V_20 ) ;
V_59 = V_60 ;
if ( V_58 -> V_16 == V_69 ) {
V_20 -> V_65 = F_34 (
V_70 , 2 , 0 ) ;
if ( V_20 -> V_65 && V_58 -> V_62 ) {
V_14 = F_35 ( V_58 ) ;
if ( ! V_14 ) {
V_14 = F_36 ( V_58 -> V_62 , NULL ,
F_27 ,
V_71 , L_8 ,
V_58 ) ;
if ( V_14 ) {
F_37 (
V_20 -> V_65 ) ;
F_38 ( V_58 ) ;
V_20 -> V_65 = NULL ;
}
}
} else
F_11 ( & V_58 -> V_17 , L_9 ) ;
}
return 0 ;
}
static void F_39 ( struct V_64 * V_58 )
{
struct V_18 * V_20 = F_28 ( V_58 ) ;
if ( V_20 -> V_65 ) {
F_37 ( V_20 -> V_65 ) ;
if ( V_58 -> V_62 ) {
F_40 ( V_58 -> V_62 , V_58 ) ;
F_38 ( V_58 ) ;
}
}
F_21 ( V_20 ) ;
F_32 ( V_58 ) ;
}
static int T_4 F_41 ( void )
{
int V_14 ;
V_14 = F_42 ( & V_72 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_43 ( & V_73 ) ;
return V_14 ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_72 ) ;
F_46 ( & V_73 ) ;
}
