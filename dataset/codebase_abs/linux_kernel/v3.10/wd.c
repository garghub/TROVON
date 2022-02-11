static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 -> V_2 , L_1 , V_3 ) ;
memcpy ( V_2 -> V_5 , V_6 , V_7 ) ;
memcpy ( V_2 -> V_5 + V_7 , & V_3 , sizeof( T_1 ) ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
int V_12 ;
F_4 ( V_9 , V_2 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_11 = F_5 ( V_2 , & V_17 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_4 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_9 -> V_19 = V_2 -> V_20 [ V_11 ] . V_21 ;
V_12 = F_7 ( V_9 , V_22 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_2 -> V_4 -> V_2 , L_3 ) ;
return - V_18 ;
}
V_9 -> V_23 = V_24 ;
if ( F_8 ( V_2 , V_9 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_4 ) ;
V_9 -> V_23 = V_25 ;
V_9 -> V_26 = 0 ;
return - V_27 ;
}
V_9 -> V_28 = V_29 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_30 V_31 ;
V_31 . V_32 = V_2 -> V_10 . V_26 ;
V_31 . V_33 = V_2 -> V_10 . V_19 ;
V_31 . V_34 = 1 ;
V_31 . V_35 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_31 . V_36 = V_37 ;
else if ( ! memcmp ( V_2 -> V_5 , V_38 , V_7 ) )
V_31 . V_36 = V_39 ;
else
return - V_40 ;
return F_11 ( V_2 , & V_31 , V_2 -> V_5 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_10 . V_23 != V_41 ||
V_2 -> V_15 != V_42 )
return 0 ;
memcpy ( V_2 -> V_5 , V_38 , V_39 ) ;
V_2 -> V_15 = V_43 ;
V_12 = F_13 ( & V_2 -> V_10 ) ;
if ( V_12 < 0 )
goto V_44;
if ( V_12 && V_2 -> V_45 ) {
V_12 = 0 ;
V_2 -> V_45 = false ;
if ( ! F_10 ( V_2 ) ) {
V_12 = F_14 ( & V_2 -> V_10 ) ;
if ( V_12 )
goto V_44;
} else {
F_9 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
}
V_2 -> V_46 = false ;
} else {
V_2 -> V_46 = true ;
}
F_15 ( & V_2 -> V_47 ) ;
V_12 = F_16 ( V_2 -> V_48 ,
V_2 -> V_15 == V_16 ,
F_17 ( V_49 ) ) ;
F_18 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_6 , V_12 ) ;
V_12 = 0 ;
} else {
if ( ! V_12 )
V_12 = - V_50 ;
F_19 ( & V_2 -> V_4 -> V_2 ,
L_7 , V_12 ) ;
}
V_44:
return V_12 ;
}
static int F_20 ( struct V_51 * V_52 )
{
int V_53 = - V_54 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_52 ) ;
if ( ! V_2 )
return - V_54 ;
F_18 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_55 != V_56 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_8 ,
F_22 ( V_2 -> V_55 ) ) ;
goto V_57;
}
if ( V_2 -> V_10 . V_23 != V_41 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_9 ) ;
goto V_57;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_53 = 0 ;
V_57:
F_15 ( & V_2 -> V_47 ) ;
return V_53 ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_52 ) ;
if ( ! V_2 )
return - V_54 ;
F_18 ( & V_2 -> V_47 ) ;
F_12 ( V_2 ) ;
F_15 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_52 ) ;
if ( ! V_2 )
return - V_54 ;
F_18 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_10 . V_23 != V_41 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_10 ) ;
V_12 = - V_54 ;
goto V_58;
}
V_2 -> V_15 = V_42 ;
if ( V_2 -> V_45 && F_13 ( & V_2 -> V_10 ) > 0 ) {
V_2 -> V_45 = false ;
F_2 ( & V_2 -> V_4 -> V_2 , L_11 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_12 = - V_27 ;
goto V_58;
}
if ( F_14 ( & V_2 -> V_10 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 ,
L_13 ) ;
V_12 = - V_27 ;
goto V_58;
}
} else {
V_2 -> V_46 = true ;
}
V_58:
F_15 ( & V_2 -> V_47 ) ;
return V_12 ;
}
static int F_25 ( struct V_51 * V_52 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_52 ) ;
if ( ! V_2 )
return - V_54 ;
if ( V_3 < V_59 || V_3 > V_60 )
return - V_40 ;
F_18 ( & V_2 -> V_47 ) ;
V_2 -> V_13 = V_3 ;
V_52 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_15 ( & V_2 -> V_47 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( & V_61 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 ,
L_14 ) ;
return;
}
F_2 ( & V_2 -> V_4 -> V_2 ,
L_15 ) ;
F_28 ( & V_61 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( F_21 ( & V_61 ) == NULL )
return;
F_28 ( & V_61 , NULL ) ;
F_30 ( & V_61 ) ;
}
