static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_2 , L_1 , V_3 ) ;
memcpy ( V_2 -> V_4 , V_5 , V_6 ) ;
memcpy ( V_2 -> V_4 + V_6 , & V_3 , sizeof( T_1 ) ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
int V_12 ;
F_4 ( V_10 , V_2 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_12 = F_5 ( V_10 , V_17 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_2 , L_2 ) ;
return V_12 ;
}
V_12 = F_7 ( V_10 , V_8 , NULL ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_2 , L_3 , V_12 ) ;
F_9 ( V_10 ) ;
return V_12 ;
}
V_12 = F_10 ( V_2 ) ;
if ( V_12 ) {
F_11 ( V_10 ) ;
F_9 ( V_10 ) ;
}
return V_12 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
struct V_18 V_19 ;
int V_12 ;
V_19 . V_20 = V_10 -> V_21 ;
V_19 . V_22 = F_13 ( V_10 ) ;
V_19 . V_23 = 1 ;
V_19 . V_24 = 0 ;
V_19 . V_25 = 0 ;
if ( ! memcmp ( V_2 -> V_4 , V_5 , V_6 ) )
V_19 . V_26 = V_27 ;
else if ( ! memcmp ( V_2 -> V_4 , V_28 , V_6 ) )
V_19 . V_26 = V_29 ;
else {
F_8 ( V_2 -> V_2 , L_4 ) ;
return - V_30 ;
}
V_12 = F_14 ( V_2 , & V_19 , V_2 -> V_4 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_2 , L_5 ) ;
return V_12 ;
}
V_12 = F_15 ( V_10 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_2 , L_6 ) ;
return V_12 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
int V_12 ;
if ( ! F_17 ( V_10 ) ||
V_2 -> V_15 != V_31 )
return 0 ;
memcpy ( V_2 -> V_4 , V_28 , V_29 ) ;
V_2 -> V_15 = V_32 ;
V_12 = F_18 ( V_10 ) ;
if ( V_12 < 0 )
goto V_33;
if ( V_12 && F_19 ( V_2 ) ) {
V_12 = F_12 ( V_2 ) ;
if ( V_12 )
goto V_33;
V_2 -> V_34 = false ;
} else {
V_2 -> V_34 = true ;
}
F_20 ( & V_2 -> V_35 ) ;
V_12 = F_21 ( V_2 -> V_36 ,
V_2 -> V_15 == V_16 ,
F_22 ( V_37 ) ) ;
F_23 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_15 != V_16 ) {
V_12 = - V_38 ;
F_24 ( V_2 -> V_2 , L_7 , V_12 ) ;
goto V_33;
}
F_2 ( V_2 -> V_2 , L_8 ,
V_37 - F_25 ( V_12 ) ) ;
return 0 ;
V_33:
return V_12 ;
}
static int F_26 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_33 = - V_41 ;
V_2 = F_27 ( V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_10 = & V_2 -> V_11 ;
F_23 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_42 != V_43 ) {
F_2 ( V_2 -> V_2 , L_9 ,
F_28 ( V_2 -> V_42 ) ) ;
goto V_44;
}
if ( ! F_17 ( V_10 ) ) {
F_29 ( V_2 , V_10 , L_10 ) ;
goto V_44;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_33 = 0 ;
V_44:
F_20 ( & V_2 -> V_35 ) ;
return V_33 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_40 ) ;
if ( ! V_2 )
return - V_41 ;
F_23 ( & V_2 -> V_35 ) ;
F_16 ( V_2 ) ;
F_20 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_12 ;
V_2 = F_27 ( V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_10 = & V_2 -> V_11 ;
F_23 ( & V_2 -> V_35 ) ;
if ( ! F_17 ( V_10 ) ) {
F_32 ( V_2 , V_10 , L_11 ) ;
V_12 = - V_41 ;
goto V_45;
}
V_2 -> V_15 = V_31 ;
V_12 = F_18 ( V_10 ) ;
if ( V_12 < 0 )
goto V_45;
if ( V_12 && F_19 ( V_2 ) ) {
F_2 ( V_2 -> V_2 , L_12 ) ;
V_12 = F_12 ( V_2 ) ;
if ( V_12 )
goto V_45;
V_2 -> V_34 = false ;
} else {
V_2 -> V_34 = true ;
}
V_45:
F_20 ( & V_2 -> V_35 ) ;
return V_12 ;
}
static int F_33 ( struct V_39 * V_40 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_40 ) ;
if ( ! V_2 )
return - V_41 ;
if ( V_3 < V_46 || V_3 > V_47 )
return - V_30 ;
F_23 ( & V_2 -> V_35 ) ;
V_2 -> V_13 = V_3 ;
V_40 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_20 ( & V_2 -> V_35 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_12 ;
F_20 ( & V_2 -> V_35 ) ;
V_12 = F_34 ( & V_48 ) ;
F_23 ( & V_2 -> V_35 ) ;
if ( V_12 ) {
F_8 ( V_2 -> V_2 , L_13 ,
V_12 ) ;
return V_12 ;
}
F_2 ( V_2 -> V_2 , L_14 ) ;
F_35 ( & V_48 , V_2 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( F_27 ( & V_48 ) == NULL )
return;
F_35 ( & V_48 , NULL ) ;
F_37 ( & V_48 ) ;
}
