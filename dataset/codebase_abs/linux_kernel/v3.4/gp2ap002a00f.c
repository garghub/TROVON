static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 -> V_4 -> V_5 ) ;
F_3 ( V_2 -> V_6 , V_7 , ! V_3 ) ;
F_4 ( V_2 -> V_6 ) ;
return 0 ;
}
static T_1 F_5 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
F_1 ( V_2 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_11 , V_12 ,
V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_11 , V_12 ,
0x00 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
int error ;
error = F_6 ( V_2 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_11 -> V_15 ,
L_1 , error ) ;
return error ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
int error ;
error = F_8 ( V_2 ) ;
if ( error < 0 )
F_11 ( & V_2 -> V_11 -> V_15 ,
L_2 , error ) ;
}
static int T_2 F_13 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 -> V_11 , V_16 ,
0x08 ) ;
if ( error < 0 )
return error ;
error = F_7 ( V_2 -> V_11 , V_17 ,
0xc2 ) ;
if ( error < 0 )
return error ;
error = F_7 ( V_2 -> V_11 , V_18 ,
0x04 ) ;
if ( error < 0 )
return error ;
error = F_8 ( V_2 ) ;
return error ;
}
static int T_2 F_14 ( struct V_11 * V_19 ,
const struct V_20 * V_21 )
{
const struct V_22 * V_4 = V_19 -> V_15 . V_23 ;
struct V_1 * V_2 ;
int error ;
if ( ! V_4 )
return - V_24 ;
if ( V_4 -> V_25 ) {
error = V_4 -> V_25 ( V_19 ) ;
if ( error < 0 )
return error ;
}
error = F_15 ( V_4 -> V_5 , V_26 , V_27 ) ;
if ( error )
goto V_28;
V_2 = F_16 ( sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 ) {
error = - V_30 ;
goto V_31;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = V_19 ;
error = F_13 ( V_2 ) ;
if ( error < 0 )
goto V_32;
V_2 -> V_6 = F_17 () ;
if ( ! V_2 -> V_6 ) {
error = - V_30 ;
goto V_32;
}
F_18 ( V_2 -> V_6 , V_2 ) ;
V_2 -> V_6 -> V_33 = F_9 ;
V_2 -> V_6 -> V_34 = F_12 ;
V_2 -> V_6 -> V_35 = V_27 ;
V_2 -> V_6 -> V_21 . V_36 = V_37 ;
V_2 -> V_6 -> V_15 . V_38 = & V_19 -> V_15 ;
F_19 ( V_2 -> V_6 , V_39 , V_7 ) ;
error = F_20 ( V_19 -> V_8 , NULL , F_5 ,
V_40 | V_41 |
V_42 ,
V_27 , V_2 ) ;
if ( error ) {
F_11 ( & V_19 -> V_15 , L_3 ) ;
goto V_43;
}
error = F_21 ( V_2 -> V_6 ) ;
if ( error ) {
F_11 ( & V_19 -> V_15 , L_4 ) ;
goto V_44;
}
F_22 ( & V_19 -> V_15 , V_4 -> V_45 ) ;
F_23 ( V_19 , V_2 ) ;
return 0 ;
V_44:
F_24 ( V_19 -> V_8 , V_2 ) ;
V_43:
F_25 ( V_2 -> V_6 ) ;
V_32:
F_26 ( V_2 ) ;
V_31:
F_27 ( V_4 -> V_5 ) ;
V_28:
if ( V_4 -> V_46 )
V_4 -> V_46 ( V_19 ) ;
return error ;
}
static int T_3 F_28 ( struct V_11 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
const struct V_22 * V_4 = V_2 -> V_4 ;
F_22 ( & V_19 -> V_15 , false ) ;
F_24 ( V_19 -> V_8 , V_2 ) ;
F_30 ( V_2 -> V_6 ) ;
F_26 ( V_2 ) ;
F_27 ( V_4 -> V_5 ) ;
if ( V_4 -> V_46 )
V_4 -> V_46 ( V_19 ) ;
return 0 ;
}
static int F_31 ( struct V_47 * V_15 )
{
struct V_11 * V_19 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_29 ( V_19 ) ;
int V_48 = 0 ;
if ( F_33 ( & V_19 -> V_15 ) ) {
F_34 ( V_19 -> V_8 ) ;
} else {
F_35 ( & V_2 -> V_6 -> V_49 ) ;
if ( V_2 -> V_6 -> V_50 )
V_48 = F_8 ( V_2 ) ;
F_36 ( & V_2 -> V_6 -> V_49 ) ;
}
return V_48 ;
}
static int F_37 ( struct V_47 * V_15 )
{
struct V_11 * V_19 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_29 ( V_19 ) ;
int V_48 = 0 ;
if ( F_33 ( & V_19 -> V_15 ) ) {
F_38 ( V_19 -> V_8 ) ;
} else {
F_35 ( & V_2 -> V_6 -> V_49 ) ;
if ( V_2 -> V_6 -> V_50 )
V_48 = F_6 ( V_2 ) ;
F_36 ( & V_2 -> V_6 -> V_49 ) ;
}
return V_48 ;
}
