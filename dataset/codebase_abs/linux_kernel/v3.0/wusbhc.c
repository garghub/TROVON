static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
return F_4 ( V_5 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_6 ( V_8 , V_9 , L_1 , V_1 -> V_10 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 = - V_13 ;
unsigned V_10 ;
V_12 = sscanf ( V_8 , L_2 , & V_10 ) ;
if ( V_12 != 1 ) {
V_12 = - V_14 ;
goto V_15;
}
V_1 -> V_10 = V_10 ;
F_8 ( & V_1 -> V_16 ) ;
F_9 ( V_17 ) ;
F_10 ( V_17 , & V_1 -> V_16 ,
( V_10 * V_18 ) / 1000 / 2 ) ;
V_15:
return V_12 < 0 ? V_12 : V_11 ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_19 * V_20 ;
T_1 V_12 = 0 ;
if ( V_1 -> V_21 != NULL )
V_20 = & V_1 -> V_21 -> V_22 ;
else
V_20 = & V_23 ;
V_12 += F_12 ( V_8 , V_9 , V_20 ) ;
V_12 += sprintf ( V_8 + V_12 , L_3 ) ;
return V_12 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 V_20 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 ,
L_4
L_4
L_4
L_5 ,
& V_20 . V_24 [ 0 ] , & V_20 . V_24 [ 1 ] ,
& V_20 . V_24 [ 2 ] , & V_20 . V_24 [ 3 ] ,
& V_20 . V_24 [ 4 ] , & V_20 . V_24 [ 5 ] ,
& V_20 . V_24 [ 6 ] , & V_20 . V_24 [ 7 ] ,
& V_20 . V_24 [ 8 ] , & V_20 . V_24 [ 9 ] ,
& V_20 . V_24 [ 10 ] , & V_20 . V_24 [ 11 ] ,
& V_20 . V_24 [ 12 ] , & V_20 . V_24 [ 13 ] ,
& V_20 . V_24 [ 14 ] , & V_20 . V_24 [ 15 ] ) ;
if ( V_12 != 16 ) {
F_14 ( V_3 , L_6
L_7 , ( int ) V_12 ) ;
return - V_14 ;
}
V_12 = F_15 ( V_1 , & V_20 ) ;
return V_12 < 0 ? V_12 : V_11 ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_7 , V_1 -> V_25 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_25 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 , L_8 , & V_25 ) ;
if ( V_12 != 1 )
return - V_14 ;
if ( V_25 >= V_26 )
return - V_14 ;
V_1 -> V_25 = V_25 ;
return V_11 ;
}
int F_18 ( struct V_1 * V_1 )
{
int V_12 = 0 ;
V_1 -> V_10 = V_27 ;
V_1 -> V_25 = V_26 - 1 ;
F_19 ( & V_1 -> V_28 ) ;
V_12 = F_20 ( V_1 ) ;
if ( V_12 < 0 )
goto V_29;
V_12 = F_21 ( V_1 ) ;
if ( V_12 < 0 )
goto V_30;
V_12 = F_22 ( V_1 ) ;
if ( V_12 < 0 )
goto V_31;
V_12 = F_23 ( V_1 ) ;
if ( V_12 < 0 )
goto V_32;
return 0 ;
V_32:
F_24 ( V_1 ) ;
V_31:
F_25 ( V_1 ) ;
V_30:
F_26 ( V_1 ) ;
V_29:
return V_12 ;
}
static inline struct V_33 * F_27 ( struct V_1 * V_1 )
{
return & V_1 -> V_5 . V_34 . V_35 -> V_36 ;
}
int F_28 ( struct V_1 * V_1 )
{
int V_12 = 0 ;
struct V_2 * V_3 = V_1 -> V_5 . V_34 . V_35 ;
V_12 = F_29 ( F_27 ( V_1 ) , & V_37 ) ;
if ( V_12 < 0 ) {
F_14 ( V_3 , L_9 , V_12 ) ;
goto V_38;
}
V_12 = F_30 ( V_1 ) ;
if ( V_12 < 0 )
goto V_39;
return 0 ;
V_39:
F_31 ( F_27 ( V_1 ) , & V_37 ) ;
V_38:
return V_12 ;
}
void F_32 ( struct V_1 * V_1 )
{
F_33 ( V_1 ) ;
F_31 ( F_27 ( V_1 ) , & V_37 ) ;
}
void F_34 ( struct V_1 * V_1 )
{
F_35 ( V_1 ) ;
F_24 ( V_1 ) ;
F_25 ( V_1 ) ;
F_26 ( V_1 ) ;
}
T_4 F_36 ( void )
{
T_4 V_40 ;
F_37 ( & V_41 ) ;
V_40 = F_38 ( V_42 , V_43 ) ;
if ( V_40 >= V_43 ) {
V_40 = 0 ;
goto V_15;
}
F_39 ( V_40 , V_42 ) ;
V_40 = ( T_4 ) 0xff - V_40 ;
V_15:
F_40 ( & V_41 ) ;
return V_40 ;
}
void F_41 ( T_4 V_40 )
{
V_40 = 0xff - V_40 ;
F_42 ( V_40 >= V_43 ) ;
F_37 ( & V_41 ) ;
F_43 ( ! F_44 ( V_40 , V_42 ) ) ;
F_45 ( V_40 , V_42 ) ;
F_40 ( & V_41 ) ;
}
void F_46 ( struct V_1 * V_1 , struct V_44 * V_44 , int V_45 )
{
struct V_46 * V_46 = F_47 ( V_1 , V_44 -> V_3 ) ;
if ( V_45 == 0 && V_46 ) {
V_46 -> V_47 = V_48 ;
if ( ! F_48 ( & V_46 -> V_49 ) )
F_49 ( V_17 , & V_46 -> V_50 ) ;
else
F_50 ( V_46 ) ;
}
F_51 ( & V_1 -> V_5 , V_44 , V_45 ) ;
}
void F_52 ( struct V_1 * V_1 )
{
F_53 ( V_1 -> V_51 ) ;
}
static int T_5 F_54 ( void )
{
int V_12 ;
V_12 = F_55 () ;
if ( V_12 < 0 )
goto V_52;
V_17 = F_56 ( L_10 ) ;
if ( V_17 == NULL ) {
V_12 = - V_53 ;
F_57 ( V_54 L_11 ) ;
goto V_55;
}
F_58 ( & V_56 ) ;
F_59 ( V_42 , V_43 ) ;
F_39 ( 0 , V_42 ) ;
return 0 ;
V_55:
F_60 () ;
V_52:
return V_12 ;
}
static void T_6 F_61 ( void )
{
F_45 ( 0 , V_42 ) ;
if ( ! F_62 ( V_42 , V_43 ) ) {
char V_8 [ 256 ] ;
F_63 ( V_8 , sizeof( V_8 ) , V_42 ,
V_43 ) ;
F_57 ( V_54 L_12
L_13 , V_8 ) ;
F_43 ( 1 ) ;
}
F_64 ( & V_56 ) ;
F_65 ( V_17 ) ;
F_60 () ;
}
