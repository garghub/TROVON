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
static int F_9 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 -> V_16 . V_30 -> V_31 , * V_32 ;
int V_33 ;
if ( ! V_29 )
return - V_34 ;
V_32 = F_10 ( V_29 , L_4 ) ;
if ( ! V_32 ) {
F_11 ( & V_25 -> V_16 , L_5 ) ;
return - V_34 ;
}
F_12 ( V_32 , L_6 , & V_33 ) ;
V_27 -> V_33 = V_33 ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 -> V_16 . V_30 ) ;
struct V_26 * V_27 = V_25 -> V_16 . V_35 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_36 V_17 ;
struct V_37 * V_38 ;
unsigned char V_8 ;
int V_9 = 0 ;
V_5 = F_15 ( & V_25 -> V_16 , sizeof( struct V_4 ) ,
V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_38 = F_16 ( V_25 , V_41 , 0 ) ;
if ( ! V_38 ) {
F_11 ( & V_25 -> V_16 , L_7 ) ;
return - V_42 ;
}
V_5 -> V_15 = V_38 -> V_43 ;
V_38 = F_16 ( V_25 , V_41 , 1 ) ;
if ( ! V_38 ) {
F_11 ( & V_25 -> V_16 , L_8 ) ;
return - V_42 ;
}
V_5 -> V_12 = V_38 -> V_43 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_14 = 0 ;
memset ( & V_17 , 0 , sizeof( struct V_36 ) ) ;
V_17 . type = V_44 ;
V_17 . V_45 = V_10 ;
V_2 = F_17 ( L_9 , & V_25 -> V_16 , V_5 ,
& V_46 , & V_17 ) ;
if ( F_18 ( V_2 ) ) {
F_11 ( & V_25 -> V_16 , L_10 ) ;
return F_19 ( V_2 ) ;
}
V_2 -> V_17 . V_3 = V_10 ;
F_20 ( V_25 , V_2 ) ;
V_8 = 0 ;
if ( V_25 -> V_16 . V_30 -> V_31 && ! V_27 ) {
V_27 = F_15 ( & V_25 -> V_16 ,
sizeof( struct V_26 ) ,
V_39 ) ;
F_9 ( V_25 , V_27 ) ;
}
if ( V_27 ) {
if ( V_27 -> V_47 )
V_8 |= ( 1 << 7 ) ;
if ( V_27 -> V_48 )
V_8 |= ( F_21 ( V_27 -> V_48 ) << 4 ) ;
if ( V_27 -> V_33 )
V_8 |= ( 1 << 1 ) ;
}
V_9 = F_4 ( V_7 -> V_11 , V_5 -> V_15 , 0xfe , V_8 ) ;
if ( V_9 < 0 )
goto V_49;
F_22 ( V_2 ) ;
return 0 ;
V_49:
F_23 ( V_2 ) ;
return V_9 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_25 ( V_25 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
