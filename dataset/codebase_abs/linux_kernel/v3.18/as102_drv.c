static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return;
if ( V_4 -> V_5 -> V_6 != NULL )
V_4 -> V_5 -> V_6 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return;
if ( F_3 ( V_4 ) < 0 )
F_4 ( & V_2 -> V_4 . V_9 -> V_2 ,
L_1 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 = - V_11 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return V_10 ;
if ( V_4 -> V_5 -> V_12 != NULL )
V_10 = V_4 -> V_5 -> V_12 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return - V_11 ;
V_10 = F_7 ( V_4 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_13 , T_1 V_14 , int V_15 ) {
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_10 = - V_11 ;
if ( F_2 ( & V_2 -> V_4 . V_8 ) ) {
F_4 ( & V_2 -> V_4 . V_9 -> V_2 ,
L_2 ) ;
return - V_16 ;
}
switch ( V_15 ) {
case 0 :
V_10 = F_9 ( V_4 , ( V_17 ) V_14 ) ;
F_4 ( & V_2 -> V_4 . V_9 -> V_2 ,
L_3 ,
V_13 , V_14 , V_10 ) ;
break;
case 1 :
{
struct V_18 V_19 ;
V_19 . type = V_20 ;
V_19 . V_21 = 0xFF ;
V_19 . V_14 = V_14 ;
V_10 = F_10 ( V_4 , & V_19 ) ;
F_4 ( & V_2 -> V_4 . V_9 -> V_2 ,
L_4 ,
V_13 , V_19 . V_21 , V_19 . V_14 , V_10 ) ;
break;
}
}
F_5 ( & V_2 -> V_4 . V_8 ) ;
return V_10 ;
}
static int F_11 ( struct V_22 * V_23 )
{
int V_10 = 0 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( V_30 )
F_8 ( V_26 , V_23 -> V_13 ,
V_23 -> V_14 , 1 ) ;
if ( V_26 -> V_31 ++ == 0 )
V_10 = F_6 ( V_26 ) ;
F_5 ( & V_26 -> V_28 ) ;
return V_10 ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( -- V_26 -> V_31 == 0 )
F_1 ( V_26 ) ;
if ( V_30 )
F_8 ( V_26 , V_23 -> V_13 ,
V_23 -> V_14 , 0 ) ;
F_5 ( & V_26 -> V_28 ) ;
return 0 ;
}
static int F_13 ( void * V_27 , struct V_32 * V_33 )
{
struct V_3 * V_4 = V_27 ;
int V_10 ;
if ( F_2 ( & V_4 -> V_8 ) )
return - V_16 ;
V_10 = F_14 ( V_4 , V_33 ) ;
if ( V_10 != 0 )
F_4 ( & V_4 -> V_9 -> V_2 ,
L_5 , V_10 ) ;
F_5 ( & V_4 -> V_8 ) ;
return V_10 ;
}
static int F_15 ( void * V_27 , struct V_34 * V_35 )
{
struct V_3 * V_4 = V_27 ;
int V_10 ;
if ( F_2 ( & V_4 -> V_8 ) )
return - V_16 ;
V_10 = F_16 ( V_4 , V_35 ) ;
F_5 ( & V_4 -> V_8 ) ;
return V_10 ;
}
static int F_17 ( void * V_27 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_27 ;
int V_10 ;
if ( F_2 ( & V_4 -> V_8 ) )
return - V_16 ;
V_10 = F_18 ( V_4 , V_37 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_4 -> V_9 -> V_2 ,
L_6 ,
V_10 ) ;
}
F_5 ( & V_4 -> V_8 ) ;
return V_10 ;
}
static int F_19 ( void * V_27 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_27 ;
int V_10 ;
if ( F_2 ( & V_4 -> V_8 ) )
return - V_16 ;
V_10 = F_20 ( V_4 , V_39 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_4 -> V_9 -> V_2 ,
L_7 ) ;
} else {
F_4 ( & V_4 -> V_9 -> V_2 ,
L_8 ,
V_39 -> V_40 ,
V_39 -> V_41 ,
V_39 -> V_42 ,
V_39 -> V_43 ) ;
}
F_5 ( & V_4 -> V_8 ) ;
return V_10 ;
}
static int F_21 ( void * V_27 , int V_44 , T_2 V_45 )
{
struct V_3 * V_4 = V_27 ;
int V_10 ;
if ( F_2 ( & V_4 -> V_8 ) )
return - V_16 ;
if ( V_44 ) {
if ( V_46 )
F_22 ( V_4 ,
V_47 , V_45 ) ;
V_10 = F_23 ( V_4 ) ;
} else {
V_10 = F_24 ( V_4 ) ;
}
F_5 ( & V_4 -> V_8 ) ;
return V_10 ;
}
int F_25 ( struct V_1 * V_26 )
{
struct V_48 * V_2 = & V_26 -> V_4 . V_9 -> V_2 ;
int V_10 ;
V_10 = F_26 ( & V_26 -> V_49 ,
V_26 -> V_50 , V_51 ,
V_2 , V_52 ) ;
if ( V_10 < 0 ) {
F_27 ( V_2 , L_9 ,
V_53 , V_10 ) ;
return V_10 ;
}
V_26 -> V_54 . V_27 = V_26 ;
V_26 -> V_54 . V_55 = V_30 ? 16 : 256 ;
V_26 -> V_54 . V_56 = 256 ;
V_26 -> V_54 . V_57 = F_11 ;
V_26 -> V_54 . V_58 = F_12 ;
V_26 -> V_54 . V_59 . V_60 = V_61 |
V_62 ;
V_26 -> V_63 . V_55 = V_26 -> V_54 . V_55 ;
V_26 -> V_63 . V_25 = & V_26 -> V_54 . V_59 ;
V_26 -> V_63 . V_60 = 0 ;
V_10 = F_28 ( & V_26 -> V_54 ) ;
if ( V_10 < 0 ) {
F_27 ( V_2 , L_10 , V_53 , V_10 ) ;
goto V_64;
}
V_10 = F_29 ( & V_26 -> V_63 , & V_26 -> V_49 ) ;
if ( V_10 < 0 ) {
F_27 ( V_2 , L_11 ,
V_53 , V_10 ) ;
goto V_65;
}
V_26 -> V_66 = F_30 ( V_67 , V_26 -> V_50 ,
& V_68 ,
& V_26 -> V_4 ,
V_26 -> V_45 ) ;
if ( ! V_26 -> V_66 ) {
F_27 ( V_2 , L_12 ,
V_53 , V_10 ) ;
goto V_69;
}
V_10 = F_31 ( & V_26 -> V_49 , V_26 -> V_66 ) ;
if ( V_10 < 0 ) {
F_27 ( V_2 , L_13 ,
V_53 , V_10 ) ;
goto V_69;
}
F_32 ( & V_26 -> V_4 . V_8 ) ;
F_32 ( & V_26 -> V_28 ) ;
if ( V_70 )
F_33 ( F_34 ( & V_26 -> V_4 ) ,
L_14 ) ;
F_35 ( L_15 , V_26 -> V_50 ) ;
return 0 ;
V_69:
F_36 ( & V_26 -> V_63 ) ;
V_65:
F_37 ( & V_26 -> V_54 ) ;
V_64:
F_38 ( & V_26 -> V_49 ) ;
return V_10 ;
}
void F_39 ( struct V_1 * V_26 )
{
F_40 ( V_26 -> V_66 ) ;
F_41 ( V_26 -> V_66 ) ;
F_36 ( & V_26 -> V_63 ) ;
F_37 ( & V_26 -> V_54 ) ;
F_38 ( & V_26 -> V_49 ) ;
F_35 ( L_16 , V_26 -> V_50 ) ;
}
