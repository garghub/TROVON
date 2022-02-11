static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 )
return 0 ;
V_3 = F_2 ( V_2 -> V_5 -> V_6 , V_7 ,
V_8 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_1 ,
V_9 , V_7 ) ;
return V_3 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_10 = 0 ;
if ( V_2 -> V_4 )
return 0 ;
V_3 = F_5 ( V_2 -> V_5 -> V_6 , V_11 ,
& V_10 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_1 ,
V_9 , V_11 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_5 -> V_6 , V_11 ,
( V_10 | V_12 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_2 ,
V_9 , V_11 ) ;
return V_3 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_13 = 0 ;
int V_3 ;
if ( V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_14 -> V_15 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_3 ) ;
return V_3 ;
}
}
V_3 = F_5 ( V_2 -> V_5 -> V_6 , V_16 ,
& V_13 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_1 ,
V_9 , V_16 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_5 -> V_6 , V_16 ,
( V_13 | V_17 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_2 ,
V_9 , V_11 ) ;
return V_3 ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
enum V_20 V_21 ,
union V_22 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_19 ,
struct V_1 , V_24 ) ;
if ( V_21 == V_25 ) {
V_23 -> V_26 = V_2 -> V_27 ;
V_2 -> V_28 = V_2 -> V_27 ;
return 0 ;
}
return - V_29 ;
}
static T_2 F_9 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
int V_3 ;
T_1 V_32 = 0 ;
T_1 V_33 = 0 ;
V_3 = F_5 ( V_2 -> V_5 -> V_6 , V_34 ,
& V_32 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_4 ,
V_9 , V_34 ) ;
return V_35 ;
}
F_10 ( 75 ) ;
V_3 = F_5 ( V_2 -> V_5 -> V_6 , V_36 ,
& V_33 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_4 ,
V_9 , V_36 ) ;
return V_35 ;
}
if ( V_33 & V_17 ) {
V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 )
return V_35 ;
V_2 -> V_27 = 1 ;
} else {
V_2 -> V_27 = 0 ;
}
if ( ! V_2 -> V_4 ) {
V_3 = F_2 ( V_2 -> V_5 -> V_6 ,
V_36 , 0x00 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_5 ,
V_9 , V_36 ) ;
}
}
if ( V_2 -> V_28 != V_2 -> V_27 )
F_11 ( & V_2 -> V_24 ) ;
return V_35 ;
}
static struct V_37 *
F_12 ( struct V_38 * V_39 )
{
struct V_37 * V_14 ;
struct V_40 * V_41 = V_39 -> V_5 . V_42 ;
unsigned int V_43 ;
V_14 = F_13 ( & V_39 -> V_5 , sizeof( * V_14 ) , V_44 ) ;
if ( ! V_14 ) {
F_3 ( & V_39 -> V_5 , L_6 ) ;
return NULL ;
}
V_43 = F_14 ( V_41 , L_7 ) ;
V_14 -> V_15 = V_43 ;
V_14 -> V_45 = - 1 ;
return V_14 ;
}
static int F_15 ( void * V_46 )
{
F_16 () ;
while ( ! F_17 () ) {
F_18 ( V_47 ) ;
F_19 () ;
F_9 ( - 1 , V_46 ) ;
}
return 0 ;
}
static int F_20 ( struct V_38 * V_39 )
{
struct V_1 * V_48 ;
struct V_37 * V_14 ;
T_1 V_32 = 0 ;
int V_3 ;
int V_30 ;
V_14 = F_21 ( V_39 -> V_5 . V_6 ) ;
if ( F_22 ( V_49 ) && ! V_14 && V_39 -> V_5 . V_42 )
V_14 = F_12 ( V_39 ) ;
if ( ! V_14 ) {
F_3 ( & V_39 -> V_5 , L_8 ,
V_9 ) ;
return - V_50 ;
}
V_48 = F_13 ( & V_39 -> V_5 , sizeof( * V_48 ) , V_44 ) ;
if ( ! V_48 ) {
F_3 ( & V_39 -> V_5 , L_9 ) ;
return - V_51 ;
}
F_23 ( V_39 , V_48 ) ;
V_48 -> V_5 = & V_39 -> V_5 ;
V_48 -> V_14 = V_14 ;
V_48 -> V_24 . V_52 = L_10 ;
V_48 -> V_24 . type = V_53 ;
V_48 -> V_24 . V_54 = F_7 ;
V_48 -> V_24 . V_55 = V_56 ;
V_48 -> V_24 . V_57 = F_24 ( V_56 ) ;
V_48 -> V_24 . V_58 = V_14 -> V_58 ;
V_48 -> V_24 . V_59 = V_14 -> V_59 ;
V_48 -> V_24 . V_42 = V_39 -> V_5 . V_42 ;
V_3 = F_25 ( & V_39 -> V_5 , & V_48 -> V_24 ) ;
if ( V_3 ) {
F_3 ( & V_39 -> V_5 , L_11 ) ;
return V_3 ;
}
V_30 = F_26 ( V_39 , 0 ) ;
if ( V_30 < 0 )
V_30 = - V_60 ;
V_48 -> V_30 = V_30 ;
V_3 = F_6 ( V_48 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_39 -> V_5 , L_12 , V_3 ) ;
goto V_61;
}
V_3 = F_5 ( V_48 -> V_5 -> V_6 , V_34 ,
& V_32 ) ;
if ( V_3 < 0 ) {
F_3 ( V_48 -> V_5 , L_13 , V_9 ,
V_34 ) ;
goto V_61;
}
if ( V_32 != 0 ) {
V_3 = F_4 ( V_48 ) ;
if ( V_3 < 0 ) {
F_3 ( V_48 -> V_5 , L_14 ) ;
goto V_61;
}
V_48 -> V_27 = 1 ;
F_11 ( & V_48 -> V_24 ) ;
}
if ( V_30 != - V_60 ) {
V_3 = F_27 ( & V_39 -> V_5 , V_30 , NULL ,
F_9 , 0 , L_15 , V_48 ) ;
if ( V_3 ) {
F_3 ( V_48 -> V_5 ,
L_16 , V_30 ,
V_3 ) ;
goto V_61;
}
} else {
V_48 -> V_62 = F_28 ( F_15 ,
V_48 , L_17 ) ;
V_48 -> V_4 = true ;
if ( F_29 ( V_48 -> V_62 ) ) {
V_3 = F_30 ( V_48 -> V_62 ) ;
F_3 ( V_48 -> V_5 ,
L_18 , V_3 ) ;
goto V_61;
}
}
return 0 ;
V_61:
F_31 ( & V_48 -> V_24 ) ;
return V_3 ;
}
static int F_32 ( struct V_38 * V_39 )
{
struct V_1 * V_48 = F_33 ( V_39 ) ;
if ( V_48 -> V_30 == - V_60 )
F_34 ( V_48 -> V_62 ) ;
F_31 ( & V_48 -> V_24 ) ;
return 0 ;
}
