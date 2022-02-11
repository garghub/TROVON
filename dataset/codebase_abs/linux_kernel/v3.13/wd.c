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
return V_11 ;
}
V_9 -> V_18 = V_2 -> V_19 [ V_11 ] . V_20 ;
V_12 = F_7 ( V_9 , V_21 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_2 -> V_4 -> V_2 , L_3 ) ;
return V_12 ;
}
V_9 -> V_22 = V_23 ;
if ( F_8 ( V_2 , V_9 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_4 ) ;
V_9 -> V_22 = V_24 ;
V_9 -> V_25 = 0 ;
return - V_26 ;
}
V_9 -> V_27 = V_28 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_29 V_30 ;
V_30 . V_31 = V_2 -> V_10 . V_25 ;
V_30 . V_32 = V_2 -> V_10 . V_18 ;
V_30 . V_33 = 1 ;
V_30 . V_34 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_30 . V_35 = V_36 ;
else if ( ! memcmp ( V_2 -> V_5 , V_37 , V_7 ) )
V_30 . V_35 = V_38 ;
else
return - V_39 ;
return F_11 ( V_2 , & V_30 , V_2 -> V_5 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_10 . V_22 != V_40 ||
V_2 -> V_15 != V_41 )
return 0 ;
memcpy ( V_2 -> V_5 , V_37 , V_38 ) ;
V_2 -> V_15 = V_42 ;
V_12 = F_13 ( & V_2 -> V_10 ) ;
if ( V_12 < 0 )
goto V_43;
if ( V_12 && V_2 -> V_44 ) {
V_12 = 0 ;
V_2 -> V_44 = false ;
if ( ! F_10 ( V_2 ) ) {
V_12 = F_14 ( & V_2 -> V_10 ) ;
if ( V_12 )
goto V_43;
} else {
F_9 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
}
V_2 -> V_45 = false ;
} else {
V_2 -> V_45 = true ;
}
F_15 ( & V_2 -> V_46 ) ;
V_12 = F_16 ( V_2 -> V_47 ,
V_2 -> V_15 == V_16 ,
F_17 ( V_48 ) ) ;
F_18 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_6 , V_12 ) ;
V_12 = 0 ;
} else {
if ( ! V_12 )
V_12 = - V_49 ;
F_19 ( & V_2 -> V_4 -> V_2 ,
L_7 , V_12 ) ;
}
V_43:
return V_12 ;
}
static int F_20 ( struct V_50 * V_51 )
{
int V_52 = - V_53 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_51 ) ;
if ( ! V_2 )
return - V_53 ;
F_18 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_54 != V_55 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_8 ,
F_22 ( V_2 -> V_54 ) ) ;
goto V_56;
}
if ( V_2 -> V_10 . V_22 != V_40 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_9 ) ;
goto V_56;
}
F_1 ( V_2 , V_2 -> V_13 ) ;
V_52 = 0 ;
V_56:
F_15 ( & V_2 -> V_46 ) ;
return V_52 ;
}
static int F_23 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_51 ) ;
if ( ! V_2 )
return - V_53 ;
F_18 ( & V_2 -> V_46 ) ;
F_12 ( V_2 ) ;
F_15 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_24 ( struct V_50 * V_51 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
V_2 = F_21 ( V_51 ) ;
if ( ! V_2 )
return - V_53 ;
F_18 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_10 . V_22 != V_40 ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_10 ) ;
V_12 = - V_53 ;
goto V_57;
}
V_2 -> V_15 = V_41 ;
if ( V_2 -> V_44 && F_13 ( & V_2 -> V_10 ) > 0 ) {
V_2 -> V_44 = false ;
F_2 ( & V_2 -> V_4 -> V_2 , L_11 ) ;
if ( F_10 ( V_2 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_12 = - V_26 ;
goto V_57;
}
if ( F_14 ( & V_2 -> V_10 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 ,
L_13 ) ;
V_12 = - V_26 ;
goto V_57;
}
} else {
V_2 -> V_45 = true ;
}
V_57:
F_15 ( & V_2 -> V_46 ) ;
return V_12 ;
}
static int F_25 ( struct V_50 * V_51 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_51 ) ;
if ( ! V_2 )
return - V_53 ;
if ( V_3 < V_58 || V_3 > V_59 )
return - V_39 ;
F_18 ( & V_2 -> V_46 ) ;
V_2 -> V_13 = V_3 ;
V_51 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_13 ) ;
F_15 ( & V_2 -> V_46 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( & V_60 ) ) {
F_9 ( & V_2 -> V_4 -> V_2 ,
L_14 ) ;
return;
}
F_2 ( & V_2 -> V_4 -> V_2 ,
L_15 ) ;
F_28 ( & V_60 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( F_21 ( & V_60 ) == NULL )
return;
F_28 ( & V_60 , NULL ) ;
F_30 ( & V_60 ) ;
}
