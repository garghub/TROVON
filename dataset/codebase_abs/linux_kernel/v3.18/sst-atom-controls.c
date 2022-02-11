static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 ,
T_2 V_7 , void * V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> type = V_12 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
if ( V_7 > V_13 - sizeof( * V_10 ) ) {
F_2 ( & V_2 -> V_14 -> V_15 , L_1 , V_7 ) ;
return - V_16 ;
}
V_10 -> V_7 = V_7 ;
memcpy ( V_10 -> V_17 , V_8 , V_7 ) ;
F_3 ( L_2 , V_18 ,
V_10 , V_7 + sizeof( * V_10 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
void * V_8 , T_2 V_7 )
{
int V_19 = 0 ;
V_19 = F_1 ( V_2 , V_3 ,
V_4 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_20 -> V_21 -> V_22 ( V_20 -> V_15 , V_2 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
void * V_8 , T_2 V_7 )
{
int V_19 ;
F_6 ( & V_2 -> V_23 ) ;
V_19 = F_4 ( V_2 , V_3 , V_4 ,
V_5 , V_6 , V_8 , V_7 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_7 , V_19 = 0 ;
struct V_26 * V_27 ;
V_7 = sizeof( V_27 -> V_28 ) + sizeof( V_27 -> V_29 ) + V_25 -> V_30 ;
V_27 = F_9 ( V_7 , V_31 ) ;
if ( V_27 == NULL )
return - V_32 ;
F_10 ( 2 , V_27 -> V_28 , V_25 -> V_6 , V_25 -> V_33 ) ;
V_27 -> V_29 = V_25 -> V_34 ;
memcpy ( V_27 -> V_35 , V_25 -> V_35 , V_25 -> V_30 ) ;
V_19 = F_4 ( V_2 , V_36 ,
V_37 , V_25 -> V_5 , 0 , V_27 , V_7 ) ;
F_11 ( V_27 ) ;
return V_19 ;
}
static int F_12 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_24 * V_25 = ( void * ) V_39 -> V_42 ;
V_41 -> type = V_43 ;
V_41 -> V_44 = V_25 -> V_30 ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 ,
struct V_45 * V_46 )
{
struct V_24 * V_25 = ( void * ) V_39 -> V_42 ;
struct V_47 * V_48 = F_14 ( V_39 ) ;
switch ( V_25 -> type ) {
case V_49 :
memcpy ( V_46 -> V_50 . V_17 . V_51 , V_25 -> V_35 , V_25 -> V_30 ) ;
break;
default:
F_2 ( V_48 -> V_15 , L_3 ,
V_25 -> type ) ;
return - V_16 ;
}
return 0 ;
}
static int F_15 ( struct V_38 * V_39 ,
struct V_45 * V_46 )
{
int V_19 = 0 ;
struct V_47 * V_52 = F_16 ( V_39 ) ;
struct V_1 * V_2 = F_17 ( V_52 ) ;
struct V_24 * V_25 = ( void * ) V_39 -> V_42 ;
F_18 ( V_52 -> V_15 , L_4 , V_39 -> V_53 . V_54 ) ;
F_6 ( & V_2 -> V_23 ) ;
switch ( V_25 -> type ) {
case V_49 :
memcpy ( V_25 -> V_35 , V_46 -> V_50 . V_17 . V_51 , V_25 -> V_30 ) ;
break;
default:
F_7 ( & V_2 -> V_23 ) ;
F_2 ( V_52 -> V_15 , L_3 ,
V_25 -> type ) ;
return - V_16 ;
}
if ( V_25 -> V_55 && V_25 -> V_55 -> V_56 )
V_19 = F_8 ( V_2 , V_25 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_19 ( struct V_57 * V_15 )
{
int V_58 = 0 ;
struct V_24 * V_25 ;
for ( V_58 = 0 ; V_58 < F_20 ( V_59 ) ; V_58 ++ ) {
V_25 = (struct V_24 * ) V_59 [ V_58 ] . V_42 ;
V_25 -> V_35 = F_21 ( V_15 , V_25 -> V_30 , V_31 ) ;
if ( V_25 -> V_35 == NULL )
return - V_32 ;
}
return 0 ;
}
int F_22 ( struct V_60 * V_61 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_23 ( V_61 ) ;
V_2 -> V_11 = F_21 ( V_61 -> V_15 ,
V_13 , V_31 ) ;
if ( ! V_2 -> V_11 )
return - V_32 ;
V_19 = F_19 ( V_61 -> V_15 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_24 ( V_61 , V_59 ,
F_20 ( V_59 ) ) ;
return V_19 ;
}
