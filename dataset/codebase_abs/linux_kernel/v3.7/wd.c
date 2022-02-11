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
V_2 -> V_13 = V_14 ;
F_5 ( V_2 , & V_2 -> V_8 ,
& V_15 , V_16 ) ;
F_2 ( & V_2 -> V_4 -> V_2 , L_2 ) ;
if ( V_17 != V_2 -> V_8 . V_9 ) {
F_6 ( & V_2 -> V_4 -> V_2 , L_3 ) ;
return - V_18 ;
}
if ( F_7 ( V_2 , & V_2 -> V_8 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_4 ) ;
V_2 -> V_8 . V_9 = V_10 ;
V_2 -> V_8 . V_19 = 0 ;
return - V_20 ;
}
V_2 -> V_8 . V_21 = V_22 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
V_24 = (struct V_23 * ) & V_2 -> V_25 [ 0 ] ;
V_24 -> V_26 = V_2 -> V_8 . V_19 ;
V_24 -> V_27 = V_2 -> V_8 . V_28 ;
V_24 -> V_29 = 1 ;
V_24 -> V_30 = 0 ;
if ( ! memcmp ( V_2 -> V_5 , V_6 , V_7 ) )
V_24 -> V_31 = V_32 ;
else if ( ! memcmp ( V_2 -> V_5 , V_33 , V_7 ) )
V_24 -> V_31 = V_34 ;
else
return - V_35 ;
return F_10 ( V_2 , V_24 , V_2 -> V_5 , V_24 -> V_31 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_36 ;
if ( V_2 -> V_8 . V_9 != V_37 ||
V_2 -> V_13 != V_38 )
return 0 ;
memcpy ( V_2 -> V_5 , V_33 , V_34 ) ;
V_2 -> V_13 = V_39 ;
V_36 = F_12 ( V_2 , & V_2 -> V_8 ) ;
if ( V_36 < 0 )
goto V_40;
if ( V_36 && V_2 -> V_41 ) {
V_36 = 0 ;
V_2 -> V_41 = false ;
if ( ! F_9 ( V_2 ) ) {
V_36 = F_13 ( V_2 , & V_2 -> V_8 ) ;
if ( V_36 )
goto V_40;
} else {
F_8 ( & V_2 -> V_4 -> V_2 , L_5 ) ;
}
V_2 -> V_42 = false ;
} else {
V_2 -> V_42 = true ;
}
F_14 ( & V_2 -> V_43 ) ;
V_36 = F_15 ( V_2 -> V_44 ,
V_2 -> V_13 == V_14 ,
F_16 ( V_45 ) ) ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_13 == V_14 ) {
F_2 ( & V_2 -> V_4 -> V_2 , L_6 , V_36 ) ;
V_36 = 0 ;
} else {
if ( ! V_36 )
V_36 = - V_46 ;
F_18 ( & V_2 -> V_4 -> V_2 ,
L_7 , V_36 ) ;
}
V_40:
return V_36 ;
}
static int F_19 ( struct V_47 * V_48 )
{
int V_49 = - V_50 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_48 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_51 != V_52 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_8 ,
F_21 ( V_2 -> V_51 ) ) ;
goto V_53;
}
if ( V_2 -> V_8 . V_9 != V_37 ) {
F_2 ( & V_2 -> V_4 -> V_2 ,
L_9 ) ;
goto V_53;
}
F_1 ( V_2 , V_2 -> V_11 ) ;
V_49 = 0 ;
V_53:
F_14 ( & V_2 -> V_43 ) ;
return V_49 ;
}
static int F_22 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_48 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
F_11 ( V_2 ) ;
F_14 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_23 ( struct V_47 * V_48 )
{
int V_36 = 0 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_48 ) ;
if ( ! V_2 )
return - V_50 ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_8 . V_9 != V_37 ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_10 ) ;
V_36 = - V_50 ;
goto V_54;
}
V_2 -> V_13 = V_38 ;
if ( V_2 -> V_41 &&
F_12 ( V_2 , & V_2 -> V_8 ) > 0 ) {
V_2 -> V_41 = false ;
F_2 ( & V_2 -> V_4 -> V_2 , L_11 ) ;
if ( F_9 ( V_2 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 , L_12 ) ;
V_36 = - V_20 ;
goto V_54;
}
if ( F_13 ( V_2 , & V_2 -> V_8 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_13 ) ;
V_36 = - V_20 ;
goto V_54;
}
} else {
V_2 -> V_42 = true ;
}
V_54:
F_14 ( & V_2 -> V_43 ) ;
return V_36 ;
}
static int F_24 ( struct V_47 * V_48 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_48 ) ;
if ( ! V_2 )
return - V_50 ;
if ( V_3 < V_55 || V_3 > V_56 )
return - V_35 ;
F_17 ( & V_2 -> V_43 ) ;
V_2 -> V_11 = V_3 ;
V_48 -> V_3 = V_3 ;
F_1 ( V_2 , V_2 -> V_11 ) ;
F_14 ( & V_2 -> V_43 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_26 ( & V_57 ) ) {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_14 ) ;
V_2 -> V_58 = false ;
return;
}
F_2 ( & V_2 -> V_4 -> V_2 ,
L_15 ) ;
V_2 -> V_58 = true ;
F_27 ( & V_57 , V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 )
return;
F_27 ( & V_57 , NULL ) ;
F_29 ( & V_57 ) ;
V_2 -> V_58 = false ;
}
