void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 -> V_2 , L_1 , V_3 ) ;
memcpy ( V_2 -> V_5 , V_6 , V_7 ) ;
memcpy ( V_2 -> V_5 + V_7 ,
& V_3 , sizeof( T_1 ) ) ;
}
bool F_3 ( struct V_1 * V_2 )
{
bool V_8 = false ;
F_4 ( & V_2 -> V_9 , V_2 ) ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_12 = V_13 ;
F_5 ( V_2 , & V_2 -> V_9 ,
& V_14 , V_15 ) ;
F_2 ( & V_2 -> V_4 -> V_2 , L_2 ) ;
if ( V_16 == V_2 -> V_9 . V_10 ) {
if ( ! F_6 ( V_2 , & V_2 -> V_9 ) ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_3 ) ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_17 = 0 ;
V_8 = false ;
goto V_18;
} else {
V_2 -> V_9 . V_19 = V_20 ;
}
} else {
F_2 ( & V_2 -> V_4 -> V_2 , L_4 ) ;
V_8 = false ;
goto V_18;
}
V_18:
return V_8 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) & V_2 -> V_23 [ 0 ] ;
V_22 -> V_24 = V_2 -> V_9 . V_17 ;
V_22 -> V_25 = V_2 -> V_9 . V_26 ;
V_22 -> V_27 = 1 ;
V_22 -> V_28 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_22 -> V_29 = V_30 ;
else if ( ! memcmp ( V_2 -> V_5 , V_31 , V_7 ) )
V_22 -> V_29 = V_7 ;
else
return - V_32 ;
if ( F_8 ( V_2 , V_22 , V_2 -> V_5 , V_22 -> V_29 ) )
return 0 ;
return - V_33 ;
}
int F_9 ( struct V_1 * V_2 , bool V_34 )
{
int V_8 ;
T_1 V_12 = V_2 -> V_12 ;
F_10 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_9 . V_10 != V_36 || ! V_2 -> V_12 )
return 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_37 = 0 ;
memcpy ( V_2 -> V_5 , V_31 , V_7 ) ;
V_2 -> V_38 = true ;
V_8 = F_11 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 < 0 )
goto V_39;
if ( V_8 && V_2 -> V_40 ) {
V_8 = 0 ;
V_2 -> V_40 = false ;
if ( ! F_7 ( V_2 ) ) {
V_8 = F_12 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 )
goto V_39;
} else {
F_2 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
}
V_2 -> V_41 = false ;
} else {
V_2 -> V_41 = true ;
}
V_2 -> V_42 = false ;
F_13 ( & V_2 -> V_43 ) ;
V_8 = F_14 ( V_2 -> V_44 ,
V_2 -> V_42 , 10 * V_45 ) ;
F_15 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_42 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_6 , V_8 ) ;
V_8 = 0 ;
} else {
if ( ! V_8 )
V_8 = - V_46 ;
F_16 ( & V_2 -> V_4 -> V_2 ,
L_7 , V_8 ) ;
}
if ( V_34 )
V_2 -> V_12 = V_12 ;
V_39:
return V_8 ;
}
static int F_17 ( struct V_47 * V_48 )
{
int V_49 = - V_50 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_15 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_51 != V_52 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_8 ,
V_2 -> V_51 ) ;
goto V_53;
}
if ( V_2 -> V_9 . V_10 != V_36 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_9 ) ;
goto V_53;
}
F_1 ( V_2 , V_2 -> V_12 ) ;
V_49 = 0 ;
V_53:
F_13 ( & V_2 -> V_43 ) ;
return V_49 ;
}
static int F_19 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_15 ( & V_2 -> V_43 ) ;
F_9 ( V_2 , false ) ;
F_13 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_20 ( struct V_47 * V_48 )
{
int V_8 = 0 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
F_15 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_9 . V_10 != V_36 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_10 ) ;
V_8 = - V_50 ;
goto V_18;
}
if ( V_2 -> V_40 &&
F_11 ( V_2 , & V_2 -> V_9 ) > 0 ) {
V_2 -> V_40 = false ;
F_2 ( & V_2 -> V_4 -> V_2 , L_11 ) ;
if ( F_7 ( V_2 ) ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_8 = - V_33 ;
goto V_18;
}
if ( F_12 ( V_2 , & V_2 -> V_9 ) ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_13 ) ;
V_8 = - V_33 ;
goto V_18;
}
} else {
V_2 -> V_41 = true ;
}
V_18:
F_13 ( & V_2 -> V_43 ) ;
return V_8 ;
}
static int F_21 ( struct V_47 * V_48 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_1 ) ;
if ( ! V_2 )
return - V_50 ;
if ( V_3 < V_54 || V_3 > V_55 )
return - V_32 ;
F_15 ( & V_2 -> V_43 ) ;
V_2 -> V_12 = V_3 ;
F_1 ( V_2 , V_2 -> V_12 ) ;
F_13 ( & V_2 -> V_43 ) ;
return 0 ;
}
