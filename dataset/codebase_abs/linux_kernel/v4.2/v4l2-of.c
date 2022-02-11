static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
struct V_8 * V_9 ;
bool V_10 = false ;
unsigned int V_11 = 0 ;
T_1 V_12 ;
V_9 = F_2 ( V_2 , L_1 , NULL ) ;
if ( V_9 ) {
const T_2 * V_13 = NULL ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_6 -> V_15 ) ; V_14 ++ ) {
V_13 = F_4 ( V_9 , V_13 , & V_12 ) ;
if ( ! V_13 )
break;
V_6 -> V_15 [ V_14 ] = V_12 ;
}
V_6 -> V_16 = V_14 ;
}
V_9 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_9 ) {
const T_2 * V_17 = NULL ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_6 -> V_18 ) ; V_14 ++ ) {
V_17 = F_4 ( V_9 , V_17 , & V_12 ) ;
if ( ! V_17 )
break;
V_6 -> V_18 [ V_14 ] = V_12 ;
}
if ( V_14 < 1 + V_6 -> V_16 ) {
F_5 ( L_3 ,
V_2 -> V_19 , 1 + V_6 -> V_16 , V_14 ) ;
return - V_20 ;
}
}
if ( ! F_6 ( V_2 , L_4 , & V_12 ) ) {
V_6 -> V_21 = V_12 ;
V_10 = true ;
}
if ( F_7 ( V_2 , L_5 , & V_12 ) )
V_11 |= V_22 ;
else if ( V_10 || V_6 -> V_16 > 0 )
V_11 |= V_23 ;
V_6 -> V_11 = V_11 ;
V_4 -> V_24 = V_25 ;
return 0 ;
}
static void F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_6 = & V_4 -> V_6 . V_27 ;
unsigned int V_11 = 0 ;
T_1 V_12 ;
if ( ! F_6 ( V_2 , L_6 , & V_12 ) )
V_11 |= V_12 ? V_28 :
V_29 ;
if ( ! F_6 ( V_2 , L_7 , & V_12 ) )
V_11 |= V_12 ? V_30 :
V_31 ;
if ( ! F_6 ( V_2 , L_8 , & V_12 ) )
V_11 |= V_12 ? V_32 :
V_33 ;
if ( V_11 )
V_4 -> V_24 = V_34 ;
else
V_4 -> V_24 = V_35 ;
if ( ! F_6 ( V_2 , L_9 , & V_12 ) )
V_11 |= V_12 ? V_36 :
V_37 ;
if ( ! F_6 ( V_2 , L_10 , & V_12 ) )
V_11 |= V_12 ? V_38 :
V_39 ;
if ( F_7 ( V_2 , L_11 , & V_12 ) )
V_11 |= V_40 ;
else
V_11 |= V_41 ;
if ( ! F_6 ( V_2 , L_12 , & V_12 ) )
V_6 -> V_42 = V_12 ;
if ( ! F_6 ( V_2 , L_13 , & V_12 ) )
V_6 -> V_43 = V_12 ;
if ( ! F_6 ( V_2 , L_14 , & V_12 ) )
V_11 |= V_12 ? V_44 :
V_45 ;
V_6 -> V_11 = V_11 ;
}
int F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_46 ;
F_10 ( V_2 , & V_4 -> V_47 ) ;
memset ( & V_4 -> V_24 , 0 , sizeof( * V_4 ) -
F_11 ( F_12 ( * V_4 ) , V_24 ) ) ;
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 )
return V_46 ;
if ( V_4 -> V_6 . V_7 . V_11 == 0 )
F_8 ( V_2 , V_4 ) ;
return 0 ;
}
void F_13 ( struct V_3 * V_4 )
{
if ( F_14 ( V_4 ) )
return;
F_15 ( V_4 -> V_48 ) ;
F_15 ( V_4 ) ;
}
struct V_3 * F_16 (
const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_49 ;
int V_46 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return F_18 ( - V_51 ) ;
V_46 = F_9 ( V_2 , V_4 ) ;
if ( V_46 < 0 )
goto V_52;
if ( F_7 ( V_2 , L_15 , & V_49 ) ) {
V_4 -> V_48 = F_19 ( V_49 , V_50 ) ;
if ( ! V_4 -> V_48 ) {
V_46 = - V_51 ;
goto V_52;
}
V_4 -> V_53 =
V_49 / sizeof( * V_4 -> V_48 ) ;
V_46 = F_20 (
V_2 , L_15 , V_4 -> V_48 ,
V_4 -> V_53 ) ;
if ( V_46 < 0 )
goto V_52;
}
return V_4 ;
V_52:
F_13 ( V_4 ) ;
return F_18 ( V_46 ) ;
}
int F_21 ( const struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_1 * V_56 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_56 = F_22 ( V_2 ) ;
F_6 ( V_56 , L_16 , & V_55 -> V_57 ) ;
V_56 = F_23 ( V_56 ) ;
if ( F_24 ( V_56 -> V_58 , L_17 ) == 0 )
V_56 = F_23 ( V_56 ) ;
V_55 -> V_59 = V_56 ;
V_56 = F_25 ( V_2 , L_18 , 0 ) ;
if ( ! V_56 ) {
F_26 ( V_55 -> V_59 ) ;
return - V_60 ;
}
V_56 = F_22 ( V_56 ) ;
F_6 ( V_56 , L_16 , & V_55 -> V_61 ) ;
V_56 = F_23 ( V_56 ) ;
if ( F_24 ( V_56 -> V_58 , L_17 ) == 0 )
V_56 = F_23 ( V_56 ) ;
V_55 -> V_62 = V_56 ;
return 0 ;
}
void F_27 ( struct V_54 * V_55 )
{
F_26 ( V_55 -> V_59 ) ;
F_26 ( V_55 -> V_62 ) ;
}
