static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 -> V_2 , L_1 , V_3 ) ;
memcpy ( V_2 -> V_5 , V_6 , V_7 ) ;
memcpy ( V_2 -> V_5 + V_7 , & V_3 , sizeof( T_1 ) ) ;
}
int F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_8 , V_2 ) ;
V_2 -> V_8 . V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
F_5 ( V_2 , & V_2 -> V_8 ,
& V_13 , V_14 ) ;
F_2 ( & V_2 -> V_4 -> V_2 , L_2 ) ;
if ( V_15 != V_2 -> V_8 . V_9 ) {
F_6 ( & V_2 -> V_4 -> V_2 , L_3 ) ;
return - V_16 ;
}
if ( F_7 ( V_2 , & V_2 -> V_8 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_4 ) ;
V_2 -> V_8 . V_9 = V_10 ;
V_2 -> V_8 . V_17 = 0 ;
return - V_18 ;
}
V_2 -> V_8 . V_19 = V_20 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) & V_2 -> V_23 [ 0 ] ;
V_22 -> V_24 = V_2 -> V_8 . V_17 ;
V_22 -> V_25 = V_2 -> V_8 . V_26 ;
V_22 -> V_27 = 1 ;
V_22 -> V_28 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_22 -> V_29 = V_30 ;
else if ( ! memcmp ( V_2 -> V_5 , V_31 , V_7 ) )
V_22 -> V_29 = V_7 ;
else
return - V_32 ;
return F_10 ( V_2 , V_22 , V_2 -> V_5 , V_22 -> V_29 ) ;
}
int F_11 ( struct V_1 * V_2 , bool V_33 )
{
int V_34 ;
T_1 V_11 = V_2 -> V_11 ;
F_12 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_8 . V_9 != V_36 || ! V_2 -> V_11 )
return 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_37 = 0 ;
memcpy ( V_2 -> V_5 , V_31 , V_7 ) ;
V_2 -> V_38 = true ;
V_34 = F_13 ( V_2 , & V_2 -> V_8 ) ;
if ( V_34 < 0 )
goto V_39;
if ( V_34 && V_2 -> V_40 ) {
V_34 = 0 ;
V_2 -> V_40 = false ;
if ( ! F_9 ( V_2 ) ) {
V_34 = F_14 ( V_2 , & V_2 -> V_8 ) ;
if ( V_34 )
goto V_39;
} else {
F_8 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
}
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
V_2 -> V_42 = false ;
F_15 ( & V_2 -> V_43 ) ;
V_34 = F_16 ( V_2 -> V_44 ,
V_2 -> V_42 , 10 * V_45 ) ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_42 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_6 , V_34 ) ;
V_34 = 0 ;
} else {
if ( ! V_34 )
V_34 = - V_46 ;
F_18 ( & V_2 -> V_4 -> V_2 ,
L_7 , V_34 ) ;
}
if ( V_33 )
V_2 -> V_11 = V_11 ;
V_39:
return V_34 ;
}
static int F_19 ( struct V_47 * V_48 )
{
int V_49 = - V_50 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_51 != V_52 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_8 ,
V_2 -> V_51 ) ;
goto V_53;
}
if ( V_2 -> V_8 . V_9 != V_36 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_9 ) ;
goto V_53;
}
F_1 ( V_2 , V_2 -> V_11 ) ;
V_49 = 0 ;
V_53:
F_15 ( & V_2 -> V_43 ) ;
return V_49 ;
}
static int F_21 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
F_11 ( V_2 , false ) ;
F_15 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_8 . V_9 != V_36 ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_10 ) ;
V_34 = - V_50 ;
goto V_54;
}
if ( V_2 -> V_40 &&
F_13 ( V_2 , & V_2 -> V_8 ) > 0 ) {
V_2 -> V_40 = false ;
F_2 ( & V_2 -> V_4 -> V_2 , L_11 ) ;
if ( F_9 ( V_2 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_34 = - V_18 ;
goto V_54;
}
if ( F_14 ( V_2 , & V_2 -> V_8 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_13 ) ;
V_34 = - V_18 ;
goto V_54;
}
} else {
V_2 -> V_41 = true ;
}
V_54:
F_15 ( & V_2 -> V_43 ) ;
return V_34 ;
}
static int F_23 ( struct V_47 * V_48 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
if ( V_3 < V_55 || V_3 > V_56 )
return - V_32 ;
F_17 ( & V_2 -> V_43 ) ;
V_2 -> V_11 = V_3 ;
V_48 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_11 ) ;
F_15 ( & V_2 -> V_43 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 -> V_2 , L_14 , V_2 -> V_11 ) ;
V_2 -> V_37 = ! ! V_2 -> V_11 ;
if ( F_25 ( & V_57 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_15 ) ;
V_2 -> V_58 = false ;
} else {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_16 ) ;
V_2 -> V_58 = true ;
}
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 )
F_27 ( & V_57 ) ;
V_2 -> V_58 = false ;
}
