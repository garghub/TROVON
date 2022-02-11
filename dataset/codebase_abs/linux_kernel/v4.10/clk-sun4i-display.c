static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_7 ) ;
F_6 ( V_7 & ~ F_7 ( V_5 -> V_9 + V_4 ) , V_5 -> V_7 ) ;
F_8 ( V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_7 ) ;
F_6 ( V_7 | F_7 ( V_5 -> V_9 + V_4 ) , V_5 -> V_7 ) ;
F_8 ( V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ( F_5 ( V_5 -> V_7 ) & F_7 ( V_5 -> V_9 + V_4 ) ) ;
}
static int F_11 ( struct V_2 * V_3 ,
const struct V_10 * V_11 )
{
return 0 ;
}
static void T_2 F_12 ( struct V_12 * V_13 ,
const struct V_14 * V_5 )
{
const char * V_15 [ 4 ] ;
const char * V_16 = V_13 -> V_17 ;
struct V_1 * V_1 ;
struct V_18 * div = NULL ;
struct V_19 * V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
void T_3 * V_7 ;
struct V_25 * V_25 ;
int V_26 ;
F_13 ( V_13 , L_1 , & V_16 ) ;
V_7 = F_14 ( V_13 , 0 , F_15 ( V_13 ) ) ;
if ( F_16 ( V_7 ) ) {
F_17 ( L_2 , V_16 ) ;
return;
}
V_26 = F_18 ( V_13 , V_15 , V_5 -> V_15 ) ;
if ( V_26 != V_5 -> V_15 ) {
F_17 ( L_3 , V_16 ) ;
goto V_27;
}
V_24 = F_19 ( sizeof( * V_24 ) , V_28 ) ;
if ( ! V_24 )
goto V_27;
V_24 -> V_7 = V_7 ;
V_24 -> V_29 = V_5 -> V_30 ;
V_24 -> V_31 = ( 1 << V_5 -> V_32 ) - 1 ;
V_24 -> V_8 = & V_33 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_28 ) ;
if ( ! V_20 )
goto V_34;
V_20 -> V_7 = V_7 ;
V_20 -> V_35 = V_5 -> V_36 ;
V_20 -> V_8 = & V_33 ;
if ( V_5 -> V_37 ) {
div = F_19 ( sizeof( * div ) , V_28 ) ;
if ( ! div )
goto V_38;
div -> V_7 = V_7 ;
div -> V_29 = V_5 -> V_39 ;
div -> V_40 = V_5 -> V_41 ;
div -> V_8 = & V_33 ;
}
V_25 = F_20 ( NULL , V_16 ,
V_15 , V_5 -> V_15 ,
& V_24 -> V_42 , & V_43 ,
V_5 -> V_37 ? & div -> V_42 : NULL ,
V_5 -> V_37 ? & V_44 : NULL ,
& V_20 -> V_42 , & V_45 ,
V_5 -> V_6 ) ;
if ( F_16 ( V_25 ) ) {
F_17 ( L_4 , V_16 ) ;
goto V_46;
}
V_26 = F_21 ( V_13 , V_47 , V_25 ) ;
if ( V_26 ) {
F_17 ( L_5 , V_16 ) ;
goto V_48;
}
if ( ! V_5 -> V_49 )
return;
V_1 = F_19 ( sizeof( * V_1 ) , V_28 ) ;
if ( ! V_1 )
goto V_50;
V_1 -> V_7 = V_7 ;
V_1 -> V_9 = V_5 -> V_51 ;
V_1 -> V_8 = & V_33 ;
V_1 -> V_3 . V_52 = V_5 -> V_49 ;
V_1 -> V_3 . V_53 = & V_54 ;
V_1 -> V_3 . V_55 = V_13 ;
if ( V_5 -> V_49 == 1 ) {
V_1 -> V_3 . V_56 = 0 ;
V_1 -> V_3 . V_57 = & F_11 ;
} else {
V_1 -> V_3 . V_56 = 1 ;
}
if ( F_22 ( & V_1 -> V_3 ) ) {
F_17 ( L_6 ,
V_16 ) ;
goto V_58;
}
return;
V_58:
F_23 ( V_1 ) ;
V_50:
F_24 ( V_13 ) ;
V_48:
F_25 ( V_25 ) ;
V_46:
F_23 ( div ) ;
V_38:
F_23 ( V_20 ) ;
V_34:
F_23 ( V_24 ) ;
V_27:
F_26 ( V_7 ) ;
F_27 ( V_13 , 0 , & V_22 ) ;
F_28 ( V_22 . V_59 , F_29 ( & V_22 ) ) ;
}
static void T_2 F_30 ( struct V_12 * V_13 )
{
F_12 ( V_13 , & V_60 ) ;
}
static void T_2 F_31 ( struct V_12 * V_13 )
{
F_12 ( V_13 , & V_61 ) ;
}
