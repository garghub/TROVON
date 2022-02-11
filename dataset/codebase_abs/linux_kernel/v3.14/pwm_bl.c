static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_2 -> V_5 )
return;
V_4 = F_2 ( V_2 -> V_6 ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_7 , L_1 ) ;
if ( F_4 ( V_2 -> V_8 ) ) {
if ( V_2 -> V_9 & V_10 )
F_5 ( V_2 -> V_8 , 0 ) ;
else
F_5 ( V_2 -> V_8 , 1 ) ;
}
F_6 ( V_2 -> V_11 ) ;
V_2 -> V_5 = true ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_8 ( V_2 -> V_11 , 0 , V_2 -> V_12 ) ;
F_9 ( V_2 -> V_11 ) ;
if ( F_4 ( V_2 -> V_8 ) ) {
if ( V_2 -> V_9 & V_10 )
F_5 ( V_2 -> V_8 , 1 ) ;
else
F_5 ( V_2 -> V_8 , 0 ) ;
}
F_10 ( V_2 -> V_6 ) ;
V_2 -> V_5 = false ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_13 = V_2 -> V_14 ;
int V_15 ;
if ( V_2 -> V_16 )
V_15 = V_2 -> V_16 [ V_3 ] ;
else
V_15 = V_3 ;
return ( V_15 * ( V_2 -> V_12 - V_13 ) / V_2 -> V_17 ) + V_13 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
int V_3 = V_19 -> V_20 . V_3 ;
int V_15 ;
if ( V_19 -> V_20 . V_21 != V_22 ||
V_19 -> V_20 . V_23 != V_22 ||
V_19 -> V_20 . V_24 & V_25 )
V_3 = 0 ;
if ( V_2 -> V_26 )
V_3 = V_2 -> V_26 ( V_2 -> V_7 , V_3 ) ;
if ( V_3 > 0 ) {
V_15 = F_11 ( V_2 , V_3 ) ;
F_8 ( V_2 -> V_11 , V_15 , V_2 -> V_12 ) ;
F_1 ( V_2 , V_3 ) ;
} else
F_7 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 -> V_7 , V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 )
{
return V_19 -> V_20 . V_3 ;
}
static int F_15 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_13 ( V_19 ) ;
return ! V_2 -> V_30 || V_2 -> V_30 ( V_2 -> V_7 , V_29 ) ;
}
static int F_16 ( struct V_31 * V_7 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_7 -> V_36 ;
enum V_37 V_38 ;
struct V_39 * V_40 ;
int V_41 ;
T_1 V_42 ;
int V_43 ;
if ( ! V_35 )
return - V_44 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_40 = F_17 ( V_35 , L_2 , & V_41 ) ;
if ( ! V_40 )
return - V_45 ;
V_33 -> V_46 = V_41 / sizeof( T_1 ) ;
if ( V_33 -> V_46 > 0 ) {
T_2 V_47 = sizeof( * V_33 -> V_16 ) * V_33 -> V_46 ;
V_33 -> V_16 = F_18 ( V_7 , V_47 , V_48 ) ;
if ( ! V_33 -> V_16 )
return - V_49 ;
V_43 = F_19 ( V_35 , L_2 ,
V_33 -> V_16 ,
V_33 -> V_46 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_20 ( V_35 , L_3 ,
& V_42 ) ;
if ( V_43 < 0 )
return V_43 ;
V_33 -> V_50 = V_42 ;
V_33 -> V_46 -- ;
}
V_33 -> V_8 = F_21 ( V_35 , L_4 , 0 ,
& V_38 ) ;
if ( V_33 -> V_8 == - V_51 )
return - V_51 ;
if ( F_4 ( V_33 -> V_8 ) && ( V_38 & V_52 ) )
V_33 -> V_9 |= V_10 ;
return 0 ;
}
static int F_16 ( struct V_31 * V_7 ,
struct V_32 * V_33 )
{
return - V_44 ;
}
static int F_22 ( struct V_53 * V_54 )
{
struct V_32 * V_33 = F_23 ( & V_54 -> V_7 ) ;
struct V_32 V_55 ;
struct V_56 V_20 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_43 ;
if ( ! V_33 ) {
V_43 = F_16 ( & V_54 -> V_7 , & V_55 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_54 -> V_7 , L_5 ) ;
return V_43 ;
}
V_33 = & V_55 ;
}
if ( V_33 -> V_57 ) {
V_43 = V_33 -> V_57 ( & V_54 -> V_7 ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_2 = F_18 ( & V_54 -> V_7 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
V_43 = - V_49 ;
goto V_58;
}
if ( V_33 -> V_16 ) {
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 <= V_33 -> V_46 ; V_59 ++ )
if ( V_33 -> V_16 [ V_59 ] > V_2 -> V_17 )
V_2 -> V_17 = V_33 -> V_16 [ V_59 ] ;
V_2 -> V_16 = V_33 -> V_16 ;
} else
V_2 -> V_17 = V_33 -> V_46 ;
V_2 -> V_8 = V_33 -> V_8 ;
V_2 -> V_9 = V_33 -> V_9 ;
V_2 -> V_26 = V_33 -> V_26 ;
V_2 -> V_27 = V_33 -> V_27 ;
V_2 -> V_30 = V_33 -> V_30 ;
V_2 -> exit = V_33 -> exit ;
V_2 -> V_7 = & V_54 -> V_7 ;
V_2 -> V_5 = false ;
if ( F_4 ( V_2 -> V_8 ) ) {
unsigned long V_38 ;
if ( V_2 -> V_9 & V_10 )
V_38 = V_60 ;
else
V_38 = V_61 ;
V_43 = F_24 ( V_2 -> V_8 , V_38 , L_6 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_54 -> V_7 , L_7 ,
V_2 -> V_8 , V_43 ) ;
goto V_58;
}
}
V_2 -> V_6 = F_25 ( & V_54 -> V_7 , L_8 ) ;
if ( F_26 ( V_2 -> V_6 ) ) {
V_43 = F_27 ( V_2 -> V_6 ) ;
goto V_62;
}
V_2 -> V_11 = F_28 ( & V_54 -> V_7 , NULL ) ;
if ( F_26 ( V_2 -> V_11 ) ) {
F_3 ( & V_54 -> V_7 , L_9 ) ;
V_2 -> V_11 = F_29 ( V_33 -> V_63 , L_10 ) ;
if ( F_26 ( V_2 -> V_11 ) ) {
F_3 ( & V_54 -> V_7 , L_11 ) ;
V_43 = F_27 ( V_2 -> V_11 ) ;
goto V_62;
}
}
F_30 ( & V_54 -> V_7 , L_12 ) ;
if ( V_33 -> V_64 > 0 )
F_31 ( V_2 -> V_11 , V_33 -> V_64 ) ;
V_2 -> V_12 = F_32 ( V_2 -> V_11 ) ;
V_2 -> V_14 = V_33 -> V_14 * ( V_2 -> V_12 / V_2 -> V_17 ) ;
memset ( & V_20 , 0 , sizeof( struct V_56 ) ) ;
V_20 . type = V_65 ;
V_20 . V_46 = V_33 -> V_46 ;
V_19 = F_33 ( F_34 ( & V_54 -> V_7 ) , & V_54 -> V_7 , V_2 ,
& V_66 , & V_20 ) ;
if ( F_26 ( V_19 ) ) {
F_3 ( & V_54 -> V_7 , L_13 ) ;
V_43 = F_27 ( V_19 ) ;
goto V_62;
}
if ( V_33 -> V_50 > V_33 -> V_46 ) {
F_35 ( & V_54 -> V_7 ,
L_14 ,
V_33 -> V_50 , V_33 -> V_46 ) ;
V_33 -> V_50 = V_33 -> V_46 ;
}
V_19 -> V_20 . V_3 = V_33 -> V_50 ;
F_36 ( V_19 ) ;
F_37 ( V_54 , V_19 ) ;
return 0 ;
V_62:
if ( F_4 ( V_2 -> V_8 ) )
F_38 ( V_2 -> V_8 ) ;
V_58:
if ( V_33 -> exit )
V_33 -> exit ( & V_54 -> V_7 ) ;
return V_43 ;
}
static int F_39 ( struct V_53 * V_54 )
{
struct V_18 * V_19 = F_40 ( V_54 ) ;
struct V_1 * V_2 = F_13 ( V_19 ) ;
F_41 ( V_19 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> exit )
V_2 -> exit ( & V_54 -> V_7 ) ;
return 0 ;
}
static int F_42 ( struct V_31 * V_7 )
{
struct V_18 * V_19 = F_43 ( V_7 ) ;
struct V_1 * V_2 = F_13 ( V_19 ) ;
if ( V_2 -> V_26 )
V_2 -> V_26 ( V_2 -> V_7 , 0 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 -> V_7 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_31 * V_7 )
{
struct V_18 * V_19 = F_43 ( V_7 ) ;
F_36 ( V_19 ) ;
return 0 ;
}
