static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
void * V_17 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_18 = V_4 -> V_19 ;
V_8 . V_20 = V_4 -> V_21 ;
V_8 . V_22 [ 0 ] = F_2 ( V_8 . V_18 , V_4 -> V_23 ) ;
V_8 . V_24 = F_3 ( V_4 -> V_23 ,
V_4 -> V_25 ) ;
V_15 = V_8 . V_22 [ 0 ] * V_8 . V_20 ;
V_12 = F_4 ( V_6 , V_15 ) ;
if ( ! V_12 ) {
F_5 ( L_1 ) ;
return - V_26 ;
}
V_16 = F_6 ( V_6 , V_12 ) ;
if ( V_16 ) {
F_7 ( & V_12 -> V_12 ) ;
return V_16 ;
}
V_17 = F_8 ( V_6 , V_12 ) ;
if ( ! V_17 ) {
F_7 ( & V_12 -> V_12 ) ;
return - V_26 ;
}
V_10 = F_9 ( V_6 , & V_8 , V_12 ) ;
F_7 ( & V_12 -> V_12 ) ;
if ( F_10 ( V_10 ) )
return F_11 ( V_10 ) ;
V_14 = F_12 ( V_2 ) ;
if ( F_10 ( V_14 ) ) {
V_16 = F_11 ( V_14 ) ;
goto V_27;
}
F_13 ( V_14 -> V_28 . V_29 , L_2 , sizeof( V_14 -> V_28 . V_29 ) ) ;
V_14 -> V_30 = V_2 ;
V_14 -> V_31 = & V_32 ;
V_14 -> V_28 . V_33 = V_12 -> V_34 ;
V_14 -> V_28 . V_35 = V_12 -> V_12 . V_15 ;
V_14 -> V_36 = V_12 -> V_12 . V_15 ;
V_14 -> V_37 = V_17 ;
V_2 -> V_38 = & V_10 -> V_38 ;
F_14 ( V_14 , V_10 -> V_38 . V_22 [ 0 ] ,
V_10 -> V_38 . V_39 -> V_40 ) ;
F_15 ( V_14 , V_2 , V_4 -> V_41 , V_4 -> V_42 ) ;
F_16 ( L_3 ,
V_10 -> V_38 . V_18 , V_10 -> V_38 . V_20 , V_10 -> V_38 . V_39 -> V_43 [ 0 ] * 8 ,
( unsigned long long ) V_12 -> V_34 ) ;
return 0 ;
V_27:
V_10 -> V_38 . V_44 -> V_45 ( & V_10 -> V_38 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_16 = 0 ;
if ( ! V_2 -> V_38 ) {
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 == 0 )
V_16 = 1 ;
}
return V_16 ;
}
int F_18 ( struct V_5 * V_6 )
{
struct V_46 * V_47 = V_6 -> V_48 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_19 ( V_6 -> V_6 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_26 ;
V_47 -> V_50 = V_2 ;
F_20 ( V_6 , V_2 , & V_51 ) ;
V_16 = F_21 ( V_6 , V_2 , 1 ) ;
if ( V_16 ) {
F_5 ( L_4 ) ;
goto V_52;
}
V_16 = F_22 ( V_2 ) ;
if ( V_16 ) {
F_5 ( L_5 ) ;
goto V_53;
}
V_16 = F_23 ( V_2 , 32 ) ;
if ( V_16 ) {
F_5 ( L_6 ) ;
goto V_53;
}
return 0 ;
V_53:
F_24 ( V_2 ) ;
V_52:
V_47 -> V_50 = NULL ;
return V_16 ;
}
void F_25 ( struct V_5 * V_6 )
{
struct V_46 * V_47 = V_6 -> V_48 ;
if ( V_47 -> V_50 )
F_26 ( V_47 -> V_50 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
struct V_46 * V_47 = V_6 -> V_48 ;
struct V_1 * V_2 = V_47 -> V_50 ;
if ( V_2 ) {
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_38 )
V_2 -> V_38 -> V_44 -> V_45 ( V_2 -> V_38 ) ;
V_47 -> V_50 = NULL ;
}
}
