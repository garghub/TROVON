static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned char V_8 ;
int V_9 ;
if ( V_3 > V_10 )
V_8 = V_10 ;
else
V_8 = V_3 ;
V_9 = F_3 ( V_7 -> V_11 , V_5 -> V_12 , V_8 ) ;
if ( V_9 < 0 )
goto V_13;
if ( ! V_5 -> V_14 && V_3 )
V_9 = F_4 ( V_7 -> V_11 , V_5 -> V_15 , 1 , 1 ) ;
else if ( ! V_3 )
V_9 = F_4 ( V_7 -> V_11 , V_5 -> V_15 , 1 , 0 ) ;
if ( V_9 < 0 )
goto V_13;
F_5 ( V_7 -> V_16 , L_1 , V_8 ) ;
V_5 -> V_14 = V_8 ;
return 0 ;
V_13:
F_5 ( V_7 -> V_16 , L_2 ,
V_8 , V_9 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_17 . V_3 ;
if ( V_2 -> V_17 . V_18 != V_19 )
V_3 = 0 ;
if ( V_2 -> V_17 . V_20 != V_19 )
V_3 = 0 ;
if ( V_2 -> V_17 . V_21 & V_22 )
V_3 = 0 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_9 ;
V_9 = F_8 ( V_7 -> V_11 , V_5 -> V_12 ) ;
if ( V_9 < 0 )
return - V_23 ;
V_5 -> V_14 = V_9 ;
F_5 ( V_7 -> V_16 , L_3 , V_5 -> V_14 ) ;
return V_9 ;
}
static void F_9 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_16 . V_28 -> V_29 , * V_30 ;
struct V_31 * V_32 ;
T_1 V_33 ;
if ( ! V_27 || ! F_10 ( V_34 ) )
return;
V_32 = F_11 ( & V_25 -> V_16 ,
sizeof( struct V_31 ) ,
V_35 ) ;
if ( ! V_32 )
return;
V_30 = F_12 ( V_27 , L_4 ) ;
if ( ! V_30 ) {
F_13 ( & V_25 -> V_16 , L_5 ) ;
return;
}
if ( ! F_14 ( V_30 , L_6 , & V_33 ) )
V_32 -> V_36 = V_33 ;
V_25 -> V_16 . V_37 = V_32 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_16 ( V_25 -> V_16 . V_28 ) ;
struct V_31 * V_32 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_38 V_17 ;
struct V_39 * V_40 ;
unsigned char V_8 ;
int V_9 = 0 ;
V_5 = F_11 ( & V_25 -> V_16 , sizeof( struct V_4 ) ,
V_35 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_40 = F_17 ( V_25 , V_42 , 0 ) ;
if ( ! V_40 ) {
F_13 ( & V_25 -> V_16 , L_7 ) ;
return - V_43 ;
}
V_5 -> V_15 = V_40 -> V_44 ;
V_40 = F_17 ( V_25 , V_42 , 1 ) ;
if ( ! V_40 ) {
F_13 ( & V_25 -> V_16 , L_8 ) ;
return - V_43 ;
}
V_5 -> V_12 = V_40 -> V_44 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_14 = 0 ;
memset ( & V_17 , 0 , sizeof( struct V_38 ) ) ;
V_17 . type = V_45 ;
V_17 . V_46 = V_10 ;
V_2 = F_18 ( L_9 , & V_25 -> V_16 , V_5 ,
& V_47 , & V_17 ) ;
if ( F_19 ( V_2 ) ) {
F_13 ( & V_25 -> V_16 , L_10 ) ;
return F_20 ( V_2 ) ;
}
V_2 -> V_17 . V_3 = V_10 ;
F_21 ( V_25 , V_2 ) ;
V_8 = 0 ;
if ( ! V_25 -> V_16 . V_37 )
F_9 ( V_25 ) ;
V_32 = V_25 -> V_16 . V_37 ;
if ( V_32 ) {
if ( V_32 -> V_48 )
V_8 |= ( 1 << 7 ) ;
if ( V_32 -> V_49 )
V_8 |= ( F_22 ( V_32 -> V_49 ) << 4 ) ;
if ( V_32 -> V_36 )
V_8 |= ( 1 << 1 ) ;
}
V_9 = F_4 ( V_7 -> V_11 , V_5 -> V_15 , 0xfe , V_8 ) ;
if ( V_9 < 0 )
goto V_50;
F_23 ( V_2 ) ;
return 0 ;
V_50:
F_24 ( V_2 ) ;
return V_9 ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_26 ( V_25 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
