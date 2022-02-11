static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_2 -> V_5 )
return;
V_4 = F_2 ( V_2 -> V_6 ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_7 , L_1 ) ;
if ( V_2 -> V_8 )
F_4 ( V_2 -> V_8 , 1 ) ;
F_5 ( V_2 -> V_9 ) ;
V_2 -> V_5 = true ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_7 ( V_2 -> V_9 , 0 , V_2 -> V_10 ) ;
F_8 ( V_2 -> V_9 ) ;
if ( V_2 -> V_8 )
F_4 ( V_2 -> V_8 , 0 ) ;
F_9 ( V_2 -> V_6 ) ;
V_2 -> V_5 = false ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_11 = V_2 -> V_12 ;
int V_13 ;
if ( V_2 -> V_14 )
V_13 = V_2 -> V_14 [ V_3 ] ;
else
V_13 = V_3 ;
return ( V_13 * ( V_2 -> V_10 - V_11 ) / V_2 -> V_15 ) + V_11 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_12 ( V_17 ) ;
int V_3 = V_17 -> V_18 . V_3 ;
int V_13 ;
if ( V_17 -> V_18 . V_19 != V_20 ||
V_17 -> V_18 . V_21 != V_20 ||
V_17 -> V_18 . V_22 & V_23 )
V_3 = 0 ;
if ( V_2 -> V_24 )
V_3 = V_2 -> V_24 ( V_2 -> V_7 , V_3 ) ;
if ( V_3 > 0 ) {
V_13 = F_10 ( V_2 , V_3 ) ;
F_7 ( V_2 -> V_9 , V_13 , V_2 -> V_10 ) ;
F_1 ( V_2 , V_3 ) ;
} else
F_6 ( V_2 ) ;
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 -> V_7 , V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_17 ) ;
return ! V_2 -> V_28 || V_2 -> V_28 ( V_2 -> V_7 , V_27 ) ;
}
static int F_14 ( struct V_29 * V_7 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_7 -> V_34 ;
struct V_35 * V_36 ;
int V_37 ;
T_1 V_38 ;
int V_39 ;
if ( ! V_33 )
return - V_40 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_36 = F_15 ( V_33 , L_2 , & V_37 ) ;
if ( ! V_36 )
return - V_41 ;
V_31 -> V_42 = V_37 / sizeof( T_1 ) ;
if ( V_31 -> V_42 > 0 ) {
T_2 V_43 = sizeof( * V_31 -> V_14 ) * V_31 -> V_42 ;
V_31 -> V_14 = F_16 ( V_7 , V_43 , V_44 ) ;
if ( ! V_31 -> V_14 )
return - V_45 ;
V_39 = F_17 ( V_33 , L_2 ,
V_31 -> V_14 ,
V_31 -> V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_18 ( V_33 , L_3 ,
& V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
V_31 -> V_46 = V_38 ;
V_31 -> V_42 -- ;
}
V_31 -> V_8 = - V_41 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_7 ,
struct V_30 * V_31 )
{
return - V_40 ;
}
static int F_19 ( struct V_47 * V_48 )
{
struct V_30 * V_31 = F_20 ( & V_48 -> V_7 ) ;
struct V_30 V_49 ;
struct V_50 V_18 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_39 ;
if ( ! V_31 ) {
V_39 = F_14 ( & V_48 -> V_7 , & V_49 ) ;
if ( V_39 < 0 ) {
F_3 ( & V_48 -> V_7 , L_4 ) ;
return V_39 ;
}
V_31 = & V_49 ;
}
if ( V_31 -> V_51 ) {
V_39 = V_31 -> V_51 ( & V_48 -> V_7 ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_2 = F_16 ( & V_48 -> V_7 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 ) {
V_39 = - V_45 ;
goto V_52;
}
if ( V_31 -> V_14 ) {
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 <= V_31 -> V_42 ; V_53 ++ )
if ( V_31 -> V_14 [ V_53 ] > V_2 -> V_15 )
V_2 -> V_15 = V_31 -> V_14 [ V_53 ] ;
V_2 -> V_14 = V_31 -> V_14 ;
} else
V_2 -> V_15 = V_31 -> V_42 ;
V_2 -> V_24 = V_31 -> V_24 ;
V_2 -> V_25 = V_31 -> V_25 ;
V_2 -> V_28 = V_31 -> V_28 ;
V_2 -> exit = V_31 -> exit ;
V_2 -> V_7 = & V_48 -> V_7 ;
V_2 -> V_5 = false ;
V_2 -> V_8 = F_21 ( & V_48 -> V_7 , L_5 ) ;
if ( F_22 ( V_2 -> V_8 ) ) {
V_39 = F_23 ( V_2 -> V_8 ) ;
goto V_52;
}
if ( ! V_2 -> V_8 && F_24 ( V_31 -> V_8 ) ) {
V_39 = F_25 ( & V_48 -> V_7 , V_31 -> V_8 ,
V_54 , L_5 ) ;
if ( V_39 < 0 ) {
F_3 ( & V_48 -> V_7 , L_6 ,
V_31 -> V_8 , V_39 ) ;
goto V_52;
}
V_2 -> V_8 = F_26 ( V_31 -> V_8 ) ;
}
if ( V_2 -> V_8 )
F_27 ( V_2 -> V_8 , 1 ) ;
V_2 -> V_6 = F_28 ( & V_48 -> V_7 , L_7 ) ;
if ( F_22 ( V_2 -> V_6 ) ) {
V_39 = F_23 ( V_2 -> V_6 ) ;
goto V_52;
}
V_2 -> V_9 = F_29 ( & V_48 -> V_7 , NULL ) ;
if ( F_22 ( V_2 -> V_9 ) ) {
F_3 ( & V_48 -> V_7 , L_8 ) ;
V_2 -> V_55 = true ;
V_2 -> V_9 = F_30 ( V_31 -> V_56 , L_9 ) ;
if ( F_22 ( V_2 -> V_9 ) ) {
F_3 ( & V_48 -> V_7 , L_10 ) ;
V_39 = F_23 ( V_2 -> V_9 ) ;
goto V_52;
}
}
F_31 ( & V_48 -> V_7 , L_11 ) ;
V_2 -> V_10 = F_32 ( V_2 -> V_9 ) ;
if ( ! V_2 -> V_10 && ( V_31 -> V_57 > 0 ) ) {
V_2 -> V_10 = V_31 -> V_57 ;
F_33 ( V_2 -> V_9 , V_31 -> V_57 ) ;
}
V_2 -> V_12 = V_31 -> V_12 * ( V_2 -> V_10 / V_2 -> V_15 ) ;
memset ( & V_18 , 0 , sizeof( struct V_50 ) ) ;
V_18 . type = V_58 ;
V_18 . V_42 = V_31 -> V_42 ;
V_17 = F_34 ( F_35 ( & V_48 -> V_7 ) , & V_48 -> V_7 , V_2 ,
& V_59 , & V_18 ) ;
if ( F_22 ( V_17 ) ) {
F_3 ( & V_48 -> V_7 , L_12 ) ;
V_39 = F_23 ( V_17 ) ;
goto V_52;
}
if ( V_31 -> V_46 > V_31 -> V_42 ) {
F_36 ( & V_48 -> V_7 ,
L_13 ,
V_31 -> V_46 , V_31 -> V_42 ) ;
V_31 -> V_46 = V_31 -> V_42 ;
}
V_17 -> V_18 . V_3 = V_31 -> V_46 ;
F_37 ( V_17 ) ;
F_38 ( V_48 , V_17 ) ;
return 0 ;
V_52:
if ( V_31 -> exit )
V_31 -> exit ( & V_48 -> V_7 ) ;
return V_39 ;
}
static int F_39 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = F_40 ( V_48 ) ;
struct V_1 * V_2 = F_12 ( V_17 ) ;
F_41 ( V_17 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> exit )
V_2 -> exit ( & V_48 -> V_7 ) ;
if ( V_2 -> V_55 )
F_42 ( V_2 -> V_9 ) ;
return 0 ;
}
static void F_43 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = F_40 ( V_48 ) ;
struct V_1 * V_2 = F_12 ( V_17 ) ;
F_6 ( V_2 ) ;
}
static int F_44 ( struct V_29 * V_7 )
{
struct V_16 * V_17 = F_45 ( V_7 ) ;
struct V_1 * V_2 = F_12 ( V_17 ) ;
if ( V_2 -> V_24 )
V_2 -> V_24 ( V_2 -> V_7 , 0 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 -> V_7 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_29 * V_7 )
{
struct V_16 * V_17 = F_45 ( V_7 ) ;
F_37 ( V_17 ) ;
return 0 ;
}
