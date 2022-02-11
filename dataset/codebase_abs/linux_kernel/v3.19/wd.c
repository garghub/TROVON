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
V_12 = F_7 ( V_8 , V_24 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_2 , L_3 ) ;
return V_12 ;
}
V_12 = F_8 ( V_8 , NULL ) ;
if ( V_12 ) {
F_9 ( V_2 -> V_2 , L_4 , V_12 ) ;
F_10 ( V_8 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_12 ( V_8 ) ;
F_10 ( V_8 ) ;
}
return V_12 ;
}
int F_13 ( struct V_1 * V_2 )
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
F_9 ( V_2 -> V_2 , L_5 ) ;
return - V_37 ;
}
V_12 = F_14 ( V_2 , & V_26 , V_2 -> V_4 ) ;
if ( V_12 ) {
F_9 ( V_2 -> V_2 , L_6 ) ;
return V_12 ;
}
V_12 = F_15 ( V_8 ) ;
if ( V_12 ) {
F_9 ( V_2 -> V_2 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_9 . V_38 != V_39 ||
V_2 -> V_15 != V_40 )
return 0 ;
memcpy ( V_2 -> V_4 , V_35 , V_36 ) ;
V_2 -> V_15 = V_41 ;
V_12 = F_17 ( & V_2 -> V_9 ) ;
if ( V_12 < 0 )
goto V_42;
if ( V_12 && F_18 ( V_2 ) ) {
V_12 = F_13 ( V_2 ) ;
if ( V_12 )
goto V_42;
V_2 -> V_43 = false ;
} else {
V_2 -> V_43 = true ;
}
F_19 ( & V_2 -> V_44 ) ;
V_12 = F_20 ( V_2 -> V_45 ,
V_2 -> V_15 == V_16 ,
F_21 ( V_46 ) ) ;
F_22 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_15 != V_16 ) {
V_12 = - V_47 ;
F_23 ( V_2 -> V_2 , L_8 , V_12 ) ;
goto V_42;
}
F_2 ( V_2 -> V_2 , L_9 ,
V_46 - F_24 ( V_12 ) ) ;
return 0 ;
V_42:
return V_12 ;
}
static int F_25 ( struct V_48 * V_49 )
{
int V_42 = - V_50 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_49 ) ;
if ( ! V_2 )
return - V_50 ;
F_22 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_51 != V_52 ) {
F_2 ( V_2 -> V_2 , L_10 ,
F_27 ( V_2 -> V_51 ) ) ;
goto V_53;
}
if ( V_2 -> V_9 . V_38 != V_39 ) {
F_2 ( V_2 -> V_2 , L_11 ) ;
goto V_53;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_42 = 0 ;
V_53:
F_19 ( & V_2 -> V_44 ) ;
return V_42 ;
}
static int F_28 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_49 ) ;
if ( ! V_2 )
return - V_50 ;
F_22 ( & V_2 -> V_44 ) ;
F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_12 ;
V_2 = F_26 ( V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_8 = & V_2 -> V_9 ;
F_22 ( & V_2 -> V_44 ) ;
if ( V_8 -> V_38 != V_39 ) {
F_9 ( V_2 -> V_2 , L_12 ) ;
V_12 = - V_50 ;
goto V_54;
}
V_2 -> V_15 = V_40 ;
V_12 = F_17 ( V_8 ) ;
if ( V_12 < 0 )
goto V_54;
if ( V_12 && F_18 ( V_2 ) ) {
F_2 ( V_2 -> V_2 , L_13 ) ;
V_12 = F_13 ( V_2 ) ;
if ( V_12 )
goto V_54;
V_2 -> V_43 = false ;
} else {
V_2 -> V_43 = true ;
}
V_54:
F_19 ( & V_2 -> V_44 ) ;
return V_12 ;
}
static int F_30 ( struct V_48 * V_49 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_49 ) ;
if ( ! V_2 )
return - V_50 ;
if ( V_3 < V_55 || V_3 > V_56 )
return - V_37 ;
F_22 ( & V_2 -> V_44 ) ;
V_2 -> V_13 = V_3 ;
V_49 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_19 ( & V_2 -> V_44 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_12 ;
F_19 ( & V_2 -> V_44 ) ;
V_12 = F_31 ( & V_57 ) ;
F_22 ( & V_2 -> V_44 ) ;
if ( V_12 ) {
F_9 ( V_2 -> V_2 , L_14 ,
V_12 ) ;
return V_12 ;
}
F_2 ( V_2 -> V_2 , L_15 ) ;
F_32 ( & V_57 , V_2 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( F_26 ( & V_57 ) == NULL )
return;
F_32 ( & V_57 , NULL ) ;
F_34 ( & V_57 ) ;
}
