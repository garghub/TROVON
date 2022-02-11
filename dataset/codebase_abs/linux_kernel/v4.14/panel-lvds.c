static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_5 ) {
V_4 -> V_5 -> V_6 . V_7 = V_8 ;
V_4 -> V_5 -> V_6 . V_9 |= V_10 ;
F_4 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_11 )
F_6 ( V_4 -> V_11 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_11 )
F_6 ( V_4 -> V_11 , 1 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_5 ) {
V_4 -> V_5 -> V_6 . V_9 &= ~ V_10 ;
V_4 -> V_5 -> V_6 . V_7 = V_12 ;
F_4 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_13 * V_14 = V_4 -> V_3 . V_14 ;
struct V_15 * V_16 ;
V_16 = F_10 ( V_4 -> V_3 . V_17 ) ;
if ( ! V_16 )
return 0 ;
F_11 ( & V_4 -> V_18 , V_16 ) ;
V_16 -> type |= V_19 | V_20 ;
F_12 ( V_14 , V_16 ) ;
V_14 -> V_21 . V_22 = V_4 -> V_23 ;
V_14 -> V_21 . V_24 = V_4 -> V_25 ;
F_13 ( & V_14 -> V_21 ,
& V_4 -> V_26 , 1 ) ;
V_14 -> V_21 . V_27 = V_4 -> V_28
? V_29
: V_30 ;
return 1 ;
}
static int F_14 ( struct V_1 * V_4 )
{
struct V_31 * V_32 = V_4 -> V_33 -> V_34 ;
struct V_35 V_36 ;
const char * V_37 ;
int V_38 ;
V_38 = F_15 ( V_32 , L_1 , & V_36 ) ;
if ( V_38 < 0 )
return V_38 ;
F_16 ( & V_36 , & V_4 -> V_18 ) ;
V_38 = F_17 ( V_32 , L_2 , & V_4 -> V_23 ) ;
if ( V_38 < 0 ) {
F_18 ( V_4 -> V_33 , L_3 ,
V_32 , L_2 ) ;
return - V_39 ;
}
V_38 = F_17 ( V_32 , L_4 , & V_4 -> V_25 ) ;
if ( V_38 < 0 ) {
F_18 ( V_4 -> V_33 , L_3 ,
V_32 , L_4 ) ;
return - V_39 ;
}
F_19 ( V_32 , L_5 , & V_4 -> V_40 ) ;
V_38 = F_19 ( V_32 , L_6 , & V_37 ) ;
if ( V_38 < 0 ) {
F_18 ( V_4 -> V_33 , L_3 ,
V_32 , L_6 ) ;
return - V_39 ;
}
if ( ! strcmp ( V_37 , L_7 ) ) {
V_4 -> V_26 = V_41 ;
} else if ( ! strcmp ( V_37 , L_8 ) ) {
V_4 -> V_26 = V_42 ;
} else if ( ! strcmp ( V_37 , L_9 ) ) {
V_4 -> V_26 = V_43 ;
} else {
F_18 ( V_4 -> V_33 , L_3 ,
V_32 , L_6 ) ;
return - V_44 ;
}
V_4 -> V_28 = F_20 ( V_32 , L_10 ) ;
return 0 ;
}
static int F_21 ( struct V_45 * V_46 )
{
struct V_1 * V_4 ;
struct V_31 * V_32 ;
int V_38 ;
V_4 = F_22 ( & V_46 -> V_33 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_4 -> V_33 = & V_46 -> V_33 ;
V_38 = F_14 ( V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_4 -> V_11 = F_23 ( V_4 -> V_33 , L_11 ,
V_49 ) ;
if ( F_24 ( V_4 -> V_11 ) ) {
V_38 = F_25 ( V_4 -> V_11 ) ;
F_18 ( V_4 -> V_33 , L_12 ,
L_11 , V_38 ) ;
return V_38 ;
}
V_4 -> V_50 = F_23 ( V_4 -> V_33 , L_13 ,
V_51 ) ;
if ( F_24 ( V_4 -> V_50 ) ) {
V_38 = F_25 ( V_4 -> V_50 ) ;
F_18 ( V_4 -> V_33 , L_12 ,
L_13 , V_38 ) ;
return V_38 ;
}
V_32 = F_26 ( V_4 -> V_33 -> V_34 , L_14 , 0 ) ;
if ( V_32 ) {
V_4 -> V_5 = F_27 ( V_32 ) ;
F_28 ( V_32 ) ;
if ( ! V_4 -> V_5 )
return - V_52 ;
}
F_29 ( & V_4 -> V_3 ) ;
V_4 -> V_3 . V_33 = V_4 -> V_33 ;
V_4 -> V_3 . V_53 = & V_54 ;
V_38 = F_30 ( & V_4 -> V_3 ) ;
if ( V_38 < 0 )
goto error;
F_31 ( V_4 -> V_33 , V_4 ) ;
return 0 ;
error:
F_32 ( & V_4 -> V_5 -> V_33 ) ;
return V_38 ;
}
static int F_33 ( struct V_45 * V_46 )
{
struct V_1 * V_4 = F_34 ( & V_46 -> V_33 ) ;
F_35 ( & V_4 -> V_3 ) ;
F_36 ( & V_4 -> V_3 ) ;
F_3 ( & V_4 -> V_3 ) ;
if ( V_4 -> V_5 )
F_32 ( & V_4 -> V_5 -> V_33 ) ;
return 0 ;
}
