static int F_1 ( const char * V_1 , unsigned long * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , 0 , V_2 ) ;
if ( V_3 )
return - V_4 ;
if ( * V_2 > V_5 )
return - V_4 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned long V_2 )
{
if ( ( V_7 -> V_8 == V_9 ) ||
( V_7 -> V_8 == V_10 ) ||
( V_7 -> V_8 == V_11 ) )
return - V_12 ;
if ( V_2 > V_5 )
return - V_4 ;
F_4 ( V_7 ) = V_2 ;
return 0 ;
}
static T_1 F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_1 )
{
struct V_6 * V_7 = F_6 ( V_14 ) ;
const char * V_17 ;
V_17 = F_7 ( V_7 -> V_8 ) ;
if ( ! V_17 )
return - V_4 ;
return snprintf ( V_1 , V_18 , L_1 , V_17 ) ;
}
static T_1 F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_1 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
const char * V_17 ;
if ( V_20 -> V_21 -> V_22 )
V_20 -> V_21 -> V_22 ( V_20 ) ;
V_17 = F_10 ( V_20 -> V_23 ) ;
if ( ! V_17 )
return - V_4 ;
return snprintf ( V_1 , V_24 ,
L_1 , V_17 ) ;
}
static T_1
F_11 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_1 , T_2 V_25 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_6 * V_7 ;
unsigned long V_2 ;
int V_26 ;
V_26 = F_1 ( V_1 , & V_2 ) ;
if ( V_26 )
return V_26 ;
F_12 ( V_20 ) = V_2 ;
F_13 ( & V_20 -> V_27 ) ;
F_14 (fcf, &ctlr->fcfs, peers)
F_3 ( V_7 , V_2 ) ;
F_15 ( & V_20 -> V_27 ) ;
return V_25 ;
}
static T_1
F_16 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_1 , T_2 V_25 )
{
struct V_6 * V_7 = F_6 ( V_14 ) ;
unsigned long V_2 ;
int V_26 ;
V_26 = F_1 ( V_1 , & V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_3 ( V_7 , V_2 ) ;
if ( V_26 )
return V_26 ;
return V_25 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_28 * V_29 )
{
if ( V_14 -> V_30 == & V_31 )
return 1 ;
return 0 ;
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
F_19 ( V_20 ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_6 ( V_14 ) ;
F_19 ( V_7 ) ;
}
void F_21 ( struct V_19 * V_20 )
{
if ( ! F_22 ( V_20 ) ) {
F_23 ( V_32
L_2
L_3 , V_20 -> V_33 ) ;
F_24 () ;
return;
}
F_25 ( F_22 ( V_20 ) ) ;
}
int F_26 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
if ( F_27 ( ! F_22 ( V_20 ) ) ) {
F_23 ( V_32
L_4
L_3 , V_20 -> V_33 ) ;
F_24 () ;
return - V_4 ;
}
return F_28 ( F_22 ( V_20 ) , V_35 ) ;
}
void F_29 ( struct V_19 * V_20 )
{
if ( ! F_30 ( V_20 ) ) {
F_23 ( V_32
L_2
L_3 , V_20 -> V_33 ) ;
F_24 () ;
return;
}
F_25 ( F_30 ( V_20 ) ) ;
}
int F_31 ( struct V_19 * V_20 ,
struct V_36 * V_35 ,
unsigned long V_37 )
{
if ( F_27 ( ! F_30 ( V_20 ) ) ) {
F_23 ( V_32
L_4
L_3 , V_20 -> V_33 ) ;
F_24 () ;
return - V_4 ;
}
return F_32 ( F_30 ( V_20 ) , V_35 , V_37 ) ;
}
static int F_33 ( struct V_6 * V_38 ,
struct V_6 * V_39 )
{
if ( V_38 -> V_40 == V_39 -> V_40 &&
V_38 -> V_41 == V_39 -> V_41 &&
V_38 -> V_42 == V_39 -> V_42 &&
F_34 ( V_38 -> V_43 , V_39 -> V_43 ) == 0 )
return 1 ;
return 0 ;
}
struct V_19 * F_35 ( struct V_13 * V_44 ,
struct V_45 * V_21 ,
int V_46 )
{
struct V_19 * V_20 ;
int error = 0 ;
V_20 = F_36 ( sizeof( struct V_19 ) + V_46 ,
V_47 ) ;
if ( ! V_20 )
goto V_48;
V_20 -> V_33 = F_37 ( & V_49 ) - 1 ;
V_20 -> V_21 = V_21 ;
F_38 ( & V_20 -> V_50 ) ;
F_39 ( & V_20 -> V_27 ) ;
V_20 -> V_14 . V_44 = V_44 ;
V_20 -> V_14 . V_30 = & V_31 ;
V_20 -> V_14 . type = & V_51 ;
V_20 -> V_52 = F_4 ;
snprintf ( V_20 -> V_53 , sizeof( V_20 -> V_53 ) ,
L_5 , V_20 -> V_33 ) ;
V_20 -> V_54 = F_40 (
V_20 -> V_53 ) ;
if ( ! V_20 -> V_54 )
goto V_55;
snprintf ( V_20 -> V_56 ,
sizeof( V_20 -> V_56 ) ,
L_6 , V_20 -> V_33 ) ;
V_20 -> V_57 = F_40 (
V_20 -> V_56 ) ;
if ( ! V_20 -> V_57 )
goto V_58;
F_41 ( & V_20 -> V_14 , L_7 , V_20 -> V_33 ) ;
error = F_42 ( & V_20 -> V_14 ) ;
if ( error )
goto V_59;
return V_20 ;
V_59:
F_43 ( V_20 -> V_57 ) ;
V_20 -> V_57 = NULL ;
V_58:
F_43 ( V_20 -> V_54 ) ;
V_20 -> V_54 = NULL ;
V_55:
F_19 ( V_20 ) ;
V_48:
return NULL ;
}
void F_44 ( struct V_19 * V_20 )
{
struct V_6 * V_7 , * V_60 ;
F_13 ( & V_20 -> V_27 ) ;
F_45 (fcf, next,
&ctlr->fcfs, peers) {
F_46 ( & V_7 -> V_61 ) ;
V_7 -> V_8 = V_11 ;
F_26 ( V_20 , & V_7 -> V_62 ) ;
}
F_15 ( & V_20 -> V_27 ) ;
F_21 ( V_20 ) ;
F_43 ( V_20 -> V_57 ) ;
V_20 -> V_57 = NULL ;
F_43 ( V_20 -> V_54 ) ;
V_20 -> V_54 = NULL ;
F_47 ( & V_20 -> V_14 ) ;
}
static void F_48 ( struct V_34 * V_35 )
{
struct V_6 * V_7 =
F_49 ( V_35 , struct V_6 , V_62 ) ;
struct V_19 * V_20 = F_50 ( V_7 ) ;
if ( ! F_51 ( & V_7 -> V_63 ) )
F_29 ( V_20 ) ;
F_47 ( & V_7 -> V_14 ) ;
}
static void F_52 ( struct V_34 * V_35 )
{
struct V_6 * V_7 =
F_49 ( V_35 , struct V_6 , V_63 . V_35 ) ;
struct V_19 * V_20 = F_50 ( V_7 ) ;
F_13 ( & V_20 -> V_27 ) ;
if ( V_7 -> V_8 != V_10 )
goto V_48;
F_53 ( V_32 , & V_7 -> V_14 ,
L_8 ) ;
F_46 ( & V_7 -> V_61 ) ;
V_7 -> V_8 = V_11 ;
F_26 ( V_20 , & V_7 -> V_62 ) ;
V_48:
F_15 ( & V_20 -> V_27 ) ;
}
void F_54 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = F_50 ( V_7 ) ;
int V_64 = V_7 -> V_65 ;
if ( V_7 -> V_8 != V_66 )
return;
V_7 -> V_8 = V_10 ;
V_7 -> V_67 = NULL ;
F_31 ( V_20 , & V_7 -> V_63 ,
V_64 * V_68 ) ;
}
struct V_6 * F_55 ( struct V_19 * V_20 ,
struct V_6 * V_69 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_14 (fcf, &ctlr->fcfs, peers) {
if ( F_33 ( V_69 , V_7 ) ) {
if ( V_7 -> V_8 == V_66 )
return V_7 ;
V_7 -> V_8 = V_66 ;
if ( ! F_51 ( & V_7 -> V_63 ) )
F_29 ( V_20 ) ;
return V_7 ;
}
}
V_7 = F_36 ( sizeof( struct V_6 ) , V_70 ) ;
if ( F_27 ( ! V_7 ) )
goto V_48;
F_56 ( & V_7 -> V_62 , F_48 ) ;
F_57 ( & V_7 -> V_63 , F_52 ) ;
V_7 -> V_14 . V_44 = & V_20 -> V_14 ;
V_7 -> V_14 . V_30 = & V_31 ;
V_7 -> V_14 . type = & V_71 ;
V_7 -> V_33 = F_37 ( & V_72 ) - 1 ;
V_7 -> V_8 = V_9 ;
V_7 -> V_65 = V_20 -> V_52 ;
F_41 ( & V_7 -> V_14 , L_9 , V_7 -> V_33 ) ;
V_7 -> V_41 = V_69 -> V_41 ;
V_7 -> V_40 = V_69 -> V_40 ;
V_7 -> V_42 = V_69 -> V_42 ;
V_7 -> V_73 = V_69 -> V_73 ;
memcpy ( V_7 -> V_43 , V_69 -> V_43 , V_74 ) ;
V_7 -> V_75 = V_69 -> V_75 ;
V_7 -> V_76 = V_69 -> V_76 ;
V_7 -> V_77 = V_69 -> V_77 ;
error = F_42 ( & V_7 -> V_14 ) ;
if ( error )
goto V_55;
V_7 -> V_8 = V_66 ;
F_58 ( & V_7 -> V_61 , & V_20 -> V_50 ) ;
return V_7 ;
V_55:
F_19 ( V_7 ) ;
V_48:
return NULL ;
}
int T_3 F_59 ( void )
{
int error ;
F_60 ( & V_49 , 0 ) ;
F_60 ( & V_72 , 0 ) ;
error = F_61 ( & V_31 ) ;
if ( error )
return error ;
return 0 ;
}
void T_4 F_62 ( void )
{
F_63 ( & V_31 ) ;
}
