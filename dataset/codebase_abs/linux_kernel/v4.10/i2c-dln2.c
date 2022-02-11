static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
struct {
T_2 V_5 ;
} V_6 ;
V_6 . V_5 = V_2 -> V_5 ;
if ( V_3 )
V_4 = V_7 ;
else
V_4 = V_8 ;
return F_2 ( V_2 -> V_9 , V_4 , & V_6 , sizeof( V_6 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_10 ,
T_2 * V_11 , T_1 V_12 )
{
int V_13 ;
struct {
T_2 V_5 ;
T_2 V_10 ;
T_2 V_14 ;
T_3 V_15 ;
T_4 V_16 ;
T_2 V_17 [ V_18 ] ;
} V_19 * V_6 = V_2 -> V_17 ;
unsigned V_20 ;
F_4 ( sizeof( * V_6 ) > V_21 ) ;
V_6 -> V_5 = V_2 -> V_5 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_14 = 0 ;
V_6 -> V_15 = 0 ;
V_6 -> V_16 = F_5 ( V_12 ) ;
memcpy ( V_6 -> V_17 , V_11 , V_12 ) ;
V_20 = sizeof( * V_6 ) + V_12 - V_18 ;
V_13 = F_2 ( V_2 -> V_9 , V_22 , V_6 , V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 , T_2 * V_11 ,
T_1 V_12 )
{
int V_13 ;
struct {
T_2 V_5 ;
T_2 V_10 ;
T_2 V_14 ;
T_3 V_15 ;
T_4 V_16 ;
} V_19 V_6 ;
struct {
T_4 V_16 ;
T_2 V_17 [ V_18 ] ;
} V_19 * V_23 = V_2 -> V_17 ;
unsigned V_24 = sizeof( * V_23 ) ;
F_4 ( sizeof( * V_23 ) > V_21 ) ;
V_6 . V_5 = V_2 -> V_5 ;
V_6 . V_10 = V_10 ;
V_6 . V_14 = 0 ;
V_6 . V_15 = 0 ;
V_6 . V_16 = F_5 ( V_12 ) ;
V_13 = F_7 ( V_2 -> V_9 , V_25 , & V_6 , sizeof( V_6 ) ,
V_23 , & V_24 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_24 < sizeof( V_23 -> V_16 ) + V_12 )
return - V_26 ;
if ( F_8 ( V_23 -> V_16 ) != V_12 )
return - V_26 ;
memcpy ( V_11 , V_23 -> V_17 , V_12 ) ;
return V_12 ;
}
static int F_9 ( struct V_27 * V_28 ,
struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = F_10 ( V_28 ) ;
struct V_29 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
int V_13 ;
V_32 = & V_30 [ V_33 ] ;
if ( V_32 -> V_34 & V_35 ) {
V_13 = F_6 ( V_2 , V_32 -> V_10 , V_32 -> V_17 ,
V_32 -> V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
V_32 -> V_20 = V_13 ;
} else {
V_13 = F_3 ( V_2 , V_32 -> V_10 , V_32 -> V_17 ,
V_32 -> V_20 ) ;
if ( V_13 != V_32 -> V_20 )
return - V_26 ;
}
}
return V_31 ;
}
static T_5 F_11 ( struct V_27 * V_36 )
{
return V_37 | V_38 | V_39 |
V_40 | V_41 |
V_42 ;
}
static int F_12 ( struct V_43 * V_9 )
{
int V_13 ;
struct V_1 * V_2 ;
struct V_44 * V_45 = & V_9 -> V_45 ;
struct V_46 * V_47 = F_13 ( & V_9 -> V_45 ) ;
V_2 = F_14 ( V_45 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_17 = F_15 ( V_45 , V_21 , V_48 ) ;
if ( ! V_2 -> V_17 )
return - V_49 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_5 = V_47 -> V_5 ;
V_2 -> V_28 . V_50 = V_51 ;
V_2 -> V_28 . V_52 = V_53 ;
V_2 -> V_28 . V_54 = & V_55 ;
V_2 -> V_28 . V_56 = & V_57 ;
V_2 -> V_28 . V_45 . V_58 = V_45 ;
F_16 ( & V_2 -> V_28 . V_45 , F_17 ( & V_9 -> V_45 ) ) ;
V_2 -> V_28 . V_45 . V_59 = V_45 -> V_59 ;
F_18 ( & V_2 -> V_28 , V_2 ) ;
snprintf ( V_2 -> V_28 . V_60 , sizeof( V_2 -> V_28 . V_60 ) , L_1 ,
L_2 , F_19 ( V_9 -> V_45 . V_58 ) , V_2 -> V_5 ) ;
F_20 ( V_9 , V_2 ) ;
V_13 = F_1 ( V_2 , true ) ;
if ( V_13 < 0 ) {
F_21 ( V_45 , L_3 , V_13 ) ;
return V_13 ;
}
V_13 = F_22 ( & V_2 -> V_28 ) ;
if ( V_13 < 0 )
goto V_61;
return 0 ;
V_61:
F_1 ( V_2 , false ) ;
return V_13 ;
}
static int F_23 ( struct V_43 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
F_25 ( & V_2 -> V_28 ) ;
F_1 ( V_2 , false ) ;
return 0 ;
}
