static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
struct V_8 * V_9 ;
bool V_10 = false ;
unsigned int V_11 = 0 , V_12 = 0 ;
T_1 V_13 ;
V_9 = F_2 ( V_2 , L_1 , NULL ) ;
if ( V_9 ) {
const T_2 * V_14 = NULL ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < F_3 ( V_6 -> V_16 ) ; V_15 ++ ) {
V_14 = F_4 ( V_9 , V_14 , & V_13 ) ;
if ( ! V_14 )
break;
if ( V_12 & F_5 ( V_13 ) )
F_6 ( L_2 ,
V_2 -> V_17 , V_13 ) ;
V_12 |= F_5 ( V_13 ) ;
V_6 -> V_16 [ V_15 ] = V_13 ;
}
V_6 -> V_18 = V_15 ;
}
V_9 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_9 ) {
const T_2 * V_19 = NULL ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < F_3 ( V_6 -> V_20 ) ; V_15 ++ ) {
V_19 = F_4 ( V_9 , V_19 , & V_13 ) ;
if ( ! V_19 )
break;
V_6 -> V_20 [ V_15 ] = V_13 ;
}
if ( V_15 < 1 + V_6 -> V_18 ) {
F_6 ( L_4 ,
V_2 -> V_17 , 1 + V_6 -> V_18 , V_15 ) ;
return - V_21 ;
}
}
if ( ! F_7 ( V_2 , L_5 , & V_13 ) ) {
if ( V_12 & F_5 ( V_13 ) )
F_6 ( L_6 ,
V_2 -> V_17 , V_13 ) ;
V_12 |= F_5 ( V_13 ) ;
V_6 -> V_22 = V_13 ;
V_10 = true ;
}
if ( F_8 ( V_2 , L_7 , & V_13 ) )
V_11 |= V_23 ;
else if ( V_10 || V_6 -> V_18 > 0 )
V_11 |= V_24 ;
V_6 -> V_11 = V_11 ;
V_4 -> V_25 = V_26 ;
return 0 ;
}
static void F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_6 = & V_4 -> V_6 . V_28 ;
unsigned int V_11 = 0 ;
T_1 V_13 ;
if ( ! F_7 ( V_2 , L_8 , & V_13 ) )
V_11 |= V_13 ? V_29 :
V_30 ;
if ( ! F_7 ( V_2 , L_9 , & V_13 ) )
V_11 |= V_13 ? V_31 :
V_32 ;
if ( ! F_7 ( V_2 , L_10 , & V_13 ) )
V_11 |= V_13 ? V_33 :
V_34 ;
if ( V_11 )
V_4 -> V_25 = V_35 ;
else
V_4 -> V_25 = V_36 ;
if ( ! F_7 ( V_2 , L_11 , & V_13 ) )
V_11 |= V_13 ? V_37 :
V_38 ;
if ( ! F_7 ( V_2 , L_12 , & V_13 ) )
V_11 |= V_13 ? V_39 :
V_40 ;
if ( F_8 ( V_2 , L_13 , & V_13 ) )
V_11 |= V_41 ;
else
V_11 |= V_42 ;
if ( ! F_7 ( V_2 , L_14 , & V_13 ) )
V_6 -> V_43 = V_13 ;
if ( ! F_7 ( V_2 , L_15 , & V_13 ) )
V_6 -> V_44 = V_13 ;
if ( ! F_7 ( V_2 , L_16 , & V_13 ) )
V_11 |= V_13 ? V_45 :
V_46 ;
V_6 -> V_11 = V_11 ;
}
int F_10 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_47 ;
F_11 ( V_2 , & V_4 -> V_48 ) ;
memset ( & V_4 -> V_25 , 0 , sizeof( * V_4 ) -
F_12 ( F_13 ( * V_4 ) , V_25 ) ) ;
V_47 = F_1 ( V_2 , V_4 ) ;
if ( V_47 )
return V_47 ;
if ( V_4 -> V_6 . V_7 . V_11 == 0 )
F_9 ( V_2 , V_4 ) ;
return 0 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( V_4 ) )
return;
F_16 ( V_4 -> V_49 ) ;
F_16 ( V_4 ) ;
}
struct V_3 * F_17 (
const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_50 ;
int V_47 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return F_19 ( - V_52 ) ;
V_47 = F_10 ( V_2 , V_4 ) ;
if ( V_47 < 0 )
goto V_53;
if ( F_8 ( V_2 , L_17 , & V_50 ) ) {
V_4 -> V_49 = F_20 ( V_50 , V_51 ) ;
if ( ! V_4 -> V_49 ) {
V_47 = - V_52 ;
goto V_53;
}
V_4 -> V_54 =
V_50 / sizeof( * V_4 -> V_49 ) ;
V_47 = F_21 (
V_2 , L_17 , V_4 -> V_49 ,
V_4 -> V_54 ) ;
if ( V_47 < 0 )
goto V_53;
}
return V_4 ;
V_53:
F_14 ( V_4 ) ;
return F_19 ( V_47 ) ;
}
int F_22 ( const struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_1 * V_57 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_57 = F_23 ( V_2 ) ;
F_7 ( V_57 , L_18 , & V_56 -> V_58 ) ;
V_57 = F_24 ( V_57 ) ;
if ( F_25 ( V_57 -> V_59 , L_19 ) == 0 )
V_57 = F_24 ( V_57 ) ;
V_56 -> V_60 = V_57 ;
V_57 = F_26 ( V_2 , L_20 , 0 ) ;
if ( ! V_57 ) {
F_27 ( V_56 -> V_60 ) ;
return - V_61 ;
}
V_57 = F_23 ( V_57 ) ;
F_7 ( V_57 , L_18 , & V_56 -> V_62 ) ;
V_57 = F_24 ( V_57 ) ;
if ( F_25 ( V_57 -> V_59 , L_19 ) == 0 )
V_57 = F_24 ( V_57 ) ;
V_56 -> V_63 = V_57 ;
return 0 ;
}
void F_28 ( struct V_55 * V_56 )
{
F_27 ( V_56 -> V_60 ) ;
F_27 ( V_56 -> V_63 ) ;
}
