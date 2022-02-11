static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_5 . V_2 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
int error ;
error = F_3 ( V_4 -> V_8 , V_9 ,
V_10 , & V_7 ) ;
if ( error ) {
F_4 ( V_6 -> V_11 . V_12 ,
L_1 , error ) ;
} else if ( V_7 & F_5 ( 1 ) ) {
F_6 ( V_6 , V_13 , 0 ) ;
F_7 ( V_6 ) ;
} else {
F_8 ( & V_4 -> V_5 ,
F_9 ( V_14 ) ) ;
}
}
static T_1 F_10 ( int V_15 , void * V_3 )
{
struct V_3 * V_4 = V_3 ;
struct V_6 * V_6 = V_4 -> V_6 ;
F_6 ( V_6 , V_13 , 1 ) ;
F_11 ( V_6 -> V_11 . V_12 , 0 ) ;
F_7 ( V_6 ) ;
F_12 ( V_16 , & V_4 -> V_5 ,
F_9 ( V_14 ) ) ;
return V_17 ;
}
static void F_13 ( struct V_18 * V_11 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
T_2 V_23 ;
int V_24 , error ;
T_3 V_25 [] = { 6 , 8 , 10 , 12 } ;
int V_26 [] = { 15 , 100 , 500 , 1000 } ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_27 = F_14 ( V_25 ) - 1 ;
V_22 = V_11 -> V_28 ;
if ( ! V_22 )
return;
error = F_15 ( V_22 , L_2 , & V_23 ) ;
if ( ! error ) {
for ( V_24 = 0 ; V_24 < F_14 ( V_25 ) ; V_24 ++ ) {
if ( V_23 <= V_25 [ V_24 ] ) {
V_20 -> V_27 = V_24 ;
break;
}
}
}
error = F_15 ( V_22 ,
L_3 ,
& V_23 ) ;
if ( ! error ) {
for ( V_24 = 0 ; V_24 < F_14 ( V_26 ) ; V_24 ++ ) {
if ( V_23 <= V_26 [ V_24 ] ) {
V_20 -> V_29 = V_24 ;
break;
}
}
}
F_16 ( V_11 , L_4 ,
V_25 [ V_20 -> V_27 ] ) ;
}
static int F_17 ( struct V_30 * V_31 )
{
struct V_8 * V_8 = F_18 ( V_31 -> V_11 . V_12 ) ;
struct V_18 * V_11 = & V_31 -> V_11 ;
struct V_6 * V_6 ;
struct V_3 * V_4 ;
struct V_19 V_20 ;
int V_23 ;
int error ;
F_13 ( V_11 , & V_20 ) ;
V_4 = F_19 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_6 = F_20 () ;
if ( ! V_6 ) {
F_4 ( V_11 , L_5 ) ;
error = - V_33 ;
goto V_34;
}
V_6 -> V_35 = L_6 ;
V_6 -> V_36 = L_7 ;
V_6 -> V_11 . V_12 = V_11 ;
F_21 ( V_6 , V_37 , V_13 ) ;
V_23 = V_20 . V_27 << F_22 ( V_38 ) ;
V_23 |= V_20 . V_29 << F_22 ( V_39 ) ;
error = F_23 ( V_8 , V_40 ,
V_41 ,
V_38 |
V_39 ,
V_23 ) ;
if ( error ) {
F_4 ( V_11 , L_8 , error ) ;
goto V_42;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_6 = V_6 ;
F_24 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_15 = F_25 ( V_31 , 0 ) ;
error = F_26 ( V_4 -> V_15 , NULL , F_10 ,
V_43 |
V_44 |
V_45 ,
F_27 ( V_11 ) , V_4 ) ;
if ( error ) {
F_4 ( V_11 , L_9 , error ) ;
goto V_42;
}
error = F_28 ( V_6 ) ;
if ( error ) {
F_4 ( V_11 , L_10 , error ) ;
goto V_46;
}
F_29 ( V_31 , V_4 ) ;
F_30 ( V_11 , true ) ;
return 0 ;
V_46:
F_31 ( & V_4 -> V_5 ) ;
F_32 ( V_4 -> V_15 , V_4 ) ;
V_42:
F_33 ( V_6 ) ;
V_34:
F_34 ( V_4 ) ;
return error ;
}
static int F_35 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_36 ( V_31 ) ;
F_32 ( V_4 -> V_15 , V_4 ) ;
F_31 ( & V_4 -> V_5 ) ;
F_37 ( V_4 -> V_6 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_11 )
{
struct V_30 * V_31 = F_39 ( V_11 ) ;
struct V_3 * V_4 = F_36 ( V_31 ) ;
F_31 ( & V_4 -> V_5 ) ;
if ( F_40 ( V_11 ) )
F_41 ( V_4 -> V_15 ) ;
return 0 ;
}
static int F_42 ( struct V_18 * V_11 )
{
struct V_30 * V_31 = F_39 ( V_11 ) ;
struct V_3 * V_4 = F_36 ( V_31 ) ;
if ( F_40 ( V_11 ) )
F_43 ( V_4 -> V_15 ) ;
return 0 ;
}
