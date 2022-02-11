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
return V_12 ;
}
V_12 = F_8 ( V_9 , NULL ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_4 , V_12 ) ;
F_10 ( V_9 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_12 ( V_9 ) ;
F_10 ( V_9 ) ;
}
return V_12 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_23 V_24 ;
int V_12 ;
V_24 . V_25 = V_9 -> V_26 ;
V_24 . V_27 = V_9 -> V_19 ;
V_24 . V_28 = 1 ;
V_24 . V_29 = 0 ;
V_24 . V_30 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_24 . V_31 = V_32 ;
else if ( ! memcmp ( V_2 -> V_5 , V_33 , V_7 ) )
V_24 . V_31 = V_34 ;
else {
F_9 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
return - V_35 ;
}
V_12 = F_14 ( V_2 , & V_24 , V_2 -> V_5 ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_6 ) ;
return V_12 ;
}
V_12 = F_15 ( V_9 ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_10 . V_36 != V_37 ||
V_2 -> V_15 != V_38 )
return 0 ;
memcpy ( V_2 -> V_5 , V_33 , V_34 ) ;
V_2 -> V_15 = V_39 ;
V_12 = F_17 ( & V_2 -> V_10 ) ;
if ( V_12 < 0 )
goto V_40;
if ( V_12 && F_18 ( V_2 ) ) {
V_12 = F_13 ( V_2 ) ;
if ( V_12 )
goto V_40;
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
F_19 ( & V_2 -> V_42 ) ;
V_12 = F_20 ( V_2 -> V_43 ,
V_2 -> V_15 == V_16 ,
F_21 ( V_44 ) ) ;
F_22 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_15 != V_16 ) {
V_12 = - V_45 ;
F_23 ( & V_2 -> V_4 -> V_2 ,
L_8 , V_12 ) ;
goto V_40;
}
F_2 ( & V_2 -> V_4 -> V_2 , L_9 ,
V_44 - F_24 ( V_12 ) ) ;
return 0 ;
V_40:
return V_12 ;
}
static int F_25 ( struct V_46 * V_47 )
{
int V_40 = - V_48 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_22 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_10 ,
F_27 ( V_2 -> V_49 ) ) ;
goto V_51;
}
if ( V_2 -> V_10 . V_36 != V_37 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_11 ) ;
goto V_51;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_40 = 0 ;
V_51:
F_19 ( & V_2 -> V_42 ) ;
return V_40 ;
}
static int F_28 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_22 ( & V_2 -> V_42 ) ;
F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_26 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_22 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_10 . V_36 != V_37 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_12 = - V_48 ;
goto V_52;
}
V_2 -> V_15 = V_38 ;
V_12 = F_17 ( & V_2 -> V_10 ) ;
if ( V_12 < 0 )
goto V_52;
if ( V_12 && F_18 ( V_2 ) ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_13 ) ;
V_12 = F_13 ( V_2 ) ;
if ( V_12 )
goto V_52;
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
V_52:
F_19 ( & V_2 -> V_42 ) ;
return V_12 ;
}
static int F_30 ( struct V_46 * V_47 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_47 ) ;
if ( ! V_2 )
return - V_48 ;
if ( V_3 < V_53 || V_3 > V_54 )
return - V_35 ;
F_22 ( & V_2 -> V_42 ) ;
V_2 -> V_13 = V_3 ;
V_47 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_19 ( & V_2 -> V_42 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_12 ;
F_19 ( & V_2 -> V_42 ) ;
V_12 = F_31 ( & V_55 ) ;
F_22 ( & V_2 -> V_42 ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_14 ,
V_12 ) ;
return V_12 ;
}
F_2 ( & V_2 -> V_4 -> V_2 ,
L_15 ) ;
F_32 ( & V_55 , V_2 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( F_26 ( & V_55 ) == NULL )
return;
F_32 ( & V_55 , NULL ) ;
F_34 ( & V_55 ) ;
}
