static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
int V_5 = - V_6 ;
switch ( V_3 ) {
case 0 :
V_5 = V_4 ? F_2 ( V_2 , V_7 ) :
F_3 ( V_2 , V_7 ) ;
break;
case 1 :
V_5 = V_4 ? F_2 ( V_2 , V_8 ) :
F_3 ( V_2 , V_8 ) ;
break;
case 2 :
V_5 = V_4 ? F_2 ( V_2 , V_9 ) :
F_3 ( V_2 , V_9 ) ;
break;
}
return V_5 ;
}
static int F_4 ( struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
unsigned char V_15 ;
int V_5 ;
if ( V_12 > V_16 )
V_15 = V_16 ;
else
V_15 = V_12 ;
if ( V_12 )
F_1 ( V_2 , V_14 -> V_3 , 1 ) ;
V_5 = F_6 ( V_14 -> V_17 , V_14 -> V_18 , V_15 ) ;
if ( V_5 < 0 )
goto V_19;
if ( ( V_14 -> V_20 == 0 ) && V_12 ) {
if ( V_14 -> V_21 ) {
V_5 = F_7 ( V_14 -> V_17 , V_14 -> V_22 ,
V_23 , V_14 -> V_21 ) ;
if ( V_5 < 0 )
goto V_19;
}
if ( V_14 -> V_24 ) {
V_5 = F_7 ( V_14 -> V_17 , V_25 ,
V_26 , V_14 -> V_24 ) ;
if ( V_5 < 0 )
goto V_19;
}
if ( V_12 == V_16 ) {
V_5 = F_7 ( V_14 -> V_17 , V_14 -> V_27 ,
V_28 , V_28 ) ;
}
} else {
if ( V_12 == V_16 ) {
V_5 = F_7 ( V_14 -> V_17 , V_14 -> V_27 ,
V_28 , V_28 ) ;
} else {
V_5 = F_7 ( V_14 -> V_17 , V_14 -> V_27 ,
V_28 , 0 ) ;
}
}
if ( V_5 < 0 )
goto V_19;
if ( V_12 == 0 )
F_1 ( V_2 , V_14 -> V_3 , 0 ) ;
F_8 ( V_2 -> V_29 , L_1 , V_15 ) ;
V_14 -> V_20 = V_15 ;
return 0 ;
V_19:
F_8 ( V_2 -> V_29 , L_2
L_3 , V_15 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_10 * V_11 )
{
int V_12 = V_11 -> V_30 . V_12 ;
if ( V_11 -> V_30 . V_31 != V_32 )
V_12 = 0 ;
if ( V_11 -> V_30 . V_33 != V_32 )
V_12 = 0 ;
if ( V_11 -> V_30 . V_34 & V_35 )
V_12 = 0 ;
return F_4 ( V_11 , V_12 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_5 ;
V_5 = F_11 ( V_14 -> V_17 , V_14 -> V_18 ) ;
if ( V_5 < 0 )
goto V_19;
V_14 -> V_20 = V_5 ;
F_8 ( V_2 -> V_29 , L_4 , V_14 -> V_20 ) ;
return V_14 -> V_20 ;
V_19:
return - V_6 ;
}
static int F_12 ( struct V_36 * V_37 ,
struct V_13 * V_14 ,
char * V_38 )
{
struct V_39 * V_40 = V_37 -> V_29 . V_41 -> V_42 , * V_43 ;
int V_21 = 0 ;
if ( ! V_40 )
return - V_44 ;
V_40 = F_13 ( V_40 , L_5 ) ;
if ( ! V_40 ) {
F_14 ( & V_37 -> V_29 , L_6 ) ;
return - V_44 ;
}
F_15 (nproot, np) {
if ( ! F_16 ( V_43 -> V_38 , V_38 ) ) {
F_17 ( V_43 , L_7 ,
& V_21 ) ;
V_14 -> V_21 = F_18 ( V_21 ) ;
F_17 ( V_43 , L_8 ,
& V_14 -> V_24 ) ;
break;
}
}
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 -> V_29 . V_41 ) ;
struct V_45 * V_46 = V_37 -> V_29 . V_47 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
struct V_48 * V_49 ;
struct V_50 V_30 ;
char V_38 [ V_51 ] ;
int V_5 = 0 ;
V_14 = F_21 ( & V_37 -> V_29 , sizeof( struct V_13 ) ,
V_52 ) ;
if ( V_14 == NULL )
return - V_53 ;
V_49 = F_22 ( V_37 , V_54 , L_9 ) ;
if ( ! V_49 ) {
F_14 ( & V_37 -> V_29 , L_10 ) ;
V_5 = - V_55 ;
goto V_19;
}
V_14 -> V_18 = V_49 -> V_56 ;
V_49 = F_22 ( V_37 , V_54 , L_11 ) ;
if ( ! V_49 ) {
F_14 ( & V_37 -> V_29 , L_12 ) ;
V_5 = - V_55 ;
goto V_19;
}
V_14 -> V_27 = V_49 -> V_56 ;
V_49 = F_22 ( V_37 , V_54 , L_13 ) ;
if ( ! V_49 ) {
F_14 ( & V_37 -> V_29 , L_14 ) ;
V_5 = - V_55 ;
goto V_19;
}
V_14 -> V_22 = V_49 -> V_56 ;
memset ( V_38 , 0 , V_51 ) ;
sprintf ( V_38 , L_15 , V_37 -> V_57 ) ;
V_14 -> V_3 = V_37 -> V_57 ;
V_14 -> V_2 = V_2 ;
V_14 -> V_17 = ( V_2 -> V_57 == V_58 ) ? V_2 -> V_59 \
: V_2 -> V_60 ;
V_14 -> V_20 = V_16 ;
if ( F_12 ( V_37 , V_14 , V_38 ) ) {
if ( V_46 ) {
V_14 -> V_24 = V_46 -> V_24 ;
V_14 -> V_21 = V_46 -> V_21 ;
}
}
memset ( & V_30 , 0 , sizeof( struct V_50 ) ) ;
V_30 . type = V_61 ;
V_30 . V_62 = V_16 ;
V_11 = F_23 ( V_38 , & V_37 -> V_29 , V_14 ,
& V_63 , & V_30 ) ;
if ( F_24 ( V_11 ) ) {
F_14 ( & V_37 -> V_29 , L_16 ) ;
return F_25 ( V_11 ) ;
}
V_11 -> V_30 . V_12 = V_16 ;
F_26 ( V_37 , V_11 ) ;
V_5 = F_10 ( V_11 ) ;
if ( V_5 < 0 )
goto V_64;
F_27 ( V_11 ) ;
return 0 ;
V_64:
F_28 ( V_11 ) ;
V_19:
F_29 ( & V_37 -> V_29 , V_14 ) ;
return V_5 ;
}
static int F_30 ( struct V_36 * V_37 )
{
struct V_10 * V_11 = F_31 ( V_37 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
