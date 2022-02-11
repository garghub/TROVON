static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_2 , L_1 , V_3 ) ;
memcpy ( V_2 -> V_4 , V_5 , V_6 ) ;
memcpy ( V_2 -> V_4 + V_6 , & V_3 , sizeof( T_1 ) ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
F_4 ( V_8 , V_2 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_11 = F_5 ( V_2 , & V_17 ) ;
if ( ! V_11 ) {
F_6 ( V_2 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_8 -> V_19 = V_11 -> V_20 ;
V_8 -> V_21 = V_11 -> V_22 . V_23 ;
F_7 ( V_11 ) ;
V_12 = F_8 ( V_8 , V_24 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_2 , L_3 ) ;
return V_12 ;
}
V_12 = F_9 ( V_8 , NULL ) ;
if ( V_12 ) {
F_10 ( V_2 -> V_2 , L_4 , V_12 ) ;
F_11 ( V_8 ) ;
return V_12 ;
}
V_12 = F_12 ( V_2 ) ;
if ( V_12 ) {
F_13 ( V_8 ) ;
F_11 ( V_8 ) ;
}
return V_12 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_25 V_26 ;
int V_12 ;
V_26 . V_27 = V_8 -> V_28 ;
V_26 . V_29 = V_8 -> V_19 ;
V_26 . V_30 = 1 ;
V_26 . V_31 = 0 ;
V_26 . V_32 = 0 ;
if ( ! memcmp ( V_2 -> V_4 , V_5 , V_6 ) )
V_26 . V_33 = V_34 ;
else if ( ! memcmp ( V_2 -> V_4 , V_35 , V_6 ) )
V_26 . V_33 = V_36 ;
else {
F_10 ( V_2 -> V_2 , L_5 ) ;
return - V_37 ;
}
V_12 = F_15 ( V_2 , & V_26 , V_2 -> V_4 ) ;
if ( V_12 ) {
F_10 ( V_2 -> V_2 , L_6 ) ;
return V_12 ;
}
V_12 = F_16 ( V_8 ) ;
if ( V_12 ) {
F_10 ( V_2 -> V_2 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_12 ;
if ( ! F_18 ( V_8 ) ||
V_2 -> V_15 != V_38 )
return 0 ;
memcpy ( V_2 -> V_4 , V_35 , V_36 ) ;
V_2 -> V_15 = V_39 ;
V_12 = F_19 ( V_8 ) ;
if ( V_12 < 0 )
goto V_40;
if ( V_12 && F_20 ( V_2 ) ) {
V_12 = F_14 ( V_2 ) ;
if ( V_12 )
goto V_40;
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
F_21 ( & V_2 -> V_42 ) ;
V_12 = F_22 ( V_2 -> V_43 ,
V_2 -> V_15 == V_16 ,
F_23 ( V_44 ) ) ;
F_24 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_15 != V_16 ) {
V_12 = - V_45 ;
F_25 ( V_2 -> V_2 , L_8 , V_12 ) ;
goto V_40;
}
F_2 ( V_2 -> V_2 , L_9 ,
V_44 - F_26 ( V_12 ) ) ;
return 0 ;
V_40:
return V_12 ;
}
static int F_27 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_40 = - V_48 ;
V_2 = F_28 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_8 = & V_2 -> V_9 ;
F_24 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_2 ( V_2 -> V_2 , L_10 ,
F_29 ( V_2 -> V_49 ) ) ;
goto V_51;
}
if ( ! F_18 ( V_8 ) ) {
F_30 ( V_2 , V_8 , L_11 ) ;
goto V_51;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_40 = 0 ;
V_51:
F_21 ( & V_2 -> V_42 ) ;
return V_40 ;
}
static int F_31 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_24 ( & V_2 -> V_42 ) ;
F_17 ( V_2 ) ;
F_21 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_32 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_12 ;
V_2 = F_28 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_8 = & V_2 -> V_9 ;
F_24 ( & V_2 -> V_42 ) ;
if ( ! F_18 ( V_8 ) ) {
F_33 ( V_2 , V_8 , L_12 ) ;
V_12 = - V_48 ;
goto V_52;
}
V_2 -> V_15 = V_38 ;
V_12 = F_19 ( V_8 ) ;
if ( V_12 < 0 )
goto V_52;
if ( V_12 && F_20 ( V_2 ) ) {
F_2 ( V_2 -> V_2 , L_13 ) ;
V_12 = F_14 ( V_2 ) ;
if ( V_12 )
goto V_52;
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
V_52:
F_21 ( & V_2 -> V_42 ) ;
return V_12 ;
}
static int F_34 ( struct V_46 * V_47 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
if ( V_3 < V_53 || V_3 > V_54 )
return - V_37 ;
F_24 ( & V_2 -> V_42 ) ;
V_2 -> V_13 = V_3 ;
V_47 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_21 ( & V_2 -> V_42 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_12 ;
F_21 ( & V_2 -> V_42 ) ;
V_12 = F_35 ( & V_55 ) ;
F_24 ( & V_2 -> V_42 ) ;
if ( V_12 ) {
F_10 ( V_2 -> V_2 , L_14 ,
V_12 ) ;
return V_12 ;
}
F_2 ( V_2 -> V_2 , L_15 ) ;
F_36 ( & V_55 , V_2 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( F_28 ( & V_55 ) == NULL )
return;
F_36 ( & V_55 , NULL ) ;
F_38 ( & V_55 ) ;
}
