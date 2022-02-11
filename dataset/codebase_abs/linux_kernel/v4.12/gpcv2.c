static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
unsigned int V_6 = V_3 ?
V_7 : V_8 ;
const bool V_9 = ! V_3 ;
const bool V_10 = ! F_3 ( V_5 -> V_11 ) ;
unsigned long V_12 ;
int V_13 = 0 ;
F_4 ( V_5 -> V_14 , V_15 ,
V_5 -> V_16 . V_17 , V_5 -> V_16 . V_17 ) ;
if ( V_10 && V_3 ) {
V_13 = F_5 ( V_5 -> V_11 ) ;
if ( V_13 ) {
F_6 ( V_5 -> V_18 , L_1 ) ;
goto V_19;
}
}
if ( V_9 )
F_4 ( V_5 -> V_14 , F_7 ( V_5 -> V_20 ) ,
V_21 , V_21 ) ;
F_4 ( V_5 -> V_14 , V_6 ,
V_5 -> V_16 . V_22 , V_5 -> V_16 . V_22 ) ;
V_12 = V_23 + F_8 ( 1 ) ;
while ( true ) {
T_1 V_24 ;
F_9 ( V_5 -> V_14 , V_6 , & V_24 ) ;
if ( ! ( V_24 & V_5 -> V_16 . V_22 ) )
break;
if ( F_10 ( V_23 , V_12 ) ) {
F_6 ( V_5 -> V_18 , L_2 ) ;
V_13 = - V_25 ;
V_3 = ! V_3 ;
break;
}
F_11 () ;
}
if ( V_9 )
F_4 ( V_5 -> V_14 , F_7 ( V_5 -> V_20 ) ,
V_21 , 0 ) ;
if ( V_10 && ! V_3 ) {
int V_26 ;
V_26 = F_12 ( V_5 -> V_11 ) ;
if ( V_26 )
F_6 ( V_5 -> V_18 ,
L_3 , V_13 ) ;
V_13 = V_13 ? : V_26 ;
}
V_19:
F_4 ( V_5 -> V_14 , V_15 ,
V_5 -> V_16 . V_17 , 0 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = V_28 -> V_18 . V_29 ;
int V_13 ;
V_5 -> V_18 = & V_28 -> V_18 ;
V_13 = F_16 ( & V_5 -> V_2 , NULL , true ) ;
if ( V_13 ) {
F_6 ( V_5 -> V_18 , L_4 ) ;
return V_13 ;
}
V_5 -> V_11 = F_17 ( V_5 -> V_18 , L_5 ) ;
if ( F_3 ( V_5 -> V_11 ) ) {
if ( F_18 ( V_5 -> V_11 ) != - V_30 ) {
F_6 ( V_5 -> V_18 , L_6 ) ;
return F_18 ( V_5 -> V_11 ) ;
}
} else {
F_19 ( V_5 -> V_11 ,
V_5 -> V_31 , V_5 -> V_31 ) ;
}
V_13 = F_20 ( V_5 -> V_18 -> V_32 ,
& V_5 -> V_2 ) ;
if ( V_13 ) {
F_6 ( V_5 -> V_18 , L_7 ) ;
F_21 ( & V_5 -> V_2 ) ;
}
return V_13 ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = V_28 -> V_18 . V_29 ;
F_23 ( V_5 -> V_18 -> V_32 ) ;
F_21 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 )
{
static const struct V_33 V_34 [] = {
F_25 ( V_35 ,
V_36 ) ,
F_25 ( F_7 ( V_37 ) ,
F_26 ( V_37 ) ) ,
F_25 ( F_7 ( V_38 ) ,
F_26 ( V_38 ) ) ,
F_25 ( F_7 ( V_39 ) ,
F_26 ( V_39 ) ) ,
} ;
static const struct V_40 V_41 = {
. V_34 = V_34 ,
. V_42 = F_27 ( V_34 ) ,
} ;
static const struct V_43 V_43 = {
. V_44 = 32 ,
. V_45 = 32 ,
. V_46 = 4 ,
. V_47 = & V_41 ,
. V_48 = & V_41 ,
. V_49 = V_50 ,
} ;
struct V_51 * V_18 = & V_28 -> V_18 ;
struct V_52 * V_53 , * V_54 ;
struct V_14 * V_14 ;
struct V_55 * V_56 ;
void T_2 * V_57 ;
int V_13 ;
V_53 = F_28 ( V_18 -> V_32 , L_8 ) ;
if ( ! V_53 ) {
F_6 ( V_18 , L_9 ) ;
return - V_58 ;
}
V_56 = F_29 ( V_28 , V_59 , 0 ) ;
V_57 = F_30 ( V_18 , V_56 ) ;
if ( F_3 ( V_57 ) )
return F_18 ( V_57 ) ;
V_14 = F_31 ( V_18 , V_57 , & V_43 ) ;
if ( F_3 ( V_14 ) ) {
V_13 = F_18 ( V_14 ) ;
F_6 ( V_18 , L_10 , V_13 ) ;
return V_13 ;
}
F_32 (pgc_np, np) {
struct V_27 * V_60 ;
struct V_4 * V_5 ;
T_1 V_61 ;
V_13 = F_33 ( V_54 , L_11 , & V_61 ) ;
if ( V_13 ) {
F_6 ( V_18 , L_12 ) ;
F_34 ( V_54 ) ;
return V_13 ;
}
if ( V_61 >= F_27 ( V_62 ) ) {
F_35 ( V_18 ,
L_13 ,
V_61 ) ;
continue;
}
V_5 = & V_62 [ V_61 ] ;
V_5 -> V_14 = V_14 ;
V_5 -> V_2 . V_63 = F_13 ;
V_5 -> V_2 . V_64 = F_14 ;
V_60 = F_36 ( L_14 ,
V_61 ) ;
if ( ! V_60 ) {
F_6 ( V_18 , L_15 ) ;
F_34 ( V_54 ) ;
return - V_65 ;
}
V_60 -> V_18 . V_29 = V_5 ;
V_60 -> V_18 . V_66 = V_18 ;
V_60 -> V_18 . V_32 = V_54 ;
V_13 = F_37 ( V_60 ) ;
if ( V_13 ) {
F_38 ( V_60 ) ;
F_34 ( V_54 ) ;
return V_13 ;
}
}
return 0 ;
}
