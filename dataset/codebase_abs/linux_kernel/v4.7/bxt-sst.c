static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
const void * V_4 , T_1 V_5 )
{
int V_6 , V_7 , V_8 ;
T_1 V_9 ;
V_6 = V_2 -> V_10 . V_11 ( V_2 -> V_12 , 0x40 , V_5 , & V_2 -> V_13 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 -> V_12 , L_1 ,
V_6 ) ;
return V_6 ;
}
V_2 -> V_10 . V_6 = V_6 ;
memcpy ( V_2 -> V_13 . V_14 , V_4 , V_5 ) ;
F_5 ( V_2 , V_15 , V_16 |
V_17 | ( V_6 - 1 ) ) ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_2 , V_7 ) ;
V_7 = - V_18 ;
goto V_19;
}
for ( V_8 = V_20 ; V_8 > 0 ; -- V_8 ) {
V_9 = F_2 ( V_2 , V_21 ) ;
if ( V_9 & V_22 ) {
F_7 ( V_2 ,
V_21 ,
V_22 ,
V_22 ) ;
break;
}
F_8 ( 1 ) ;
}
if ( ! V_8 ) {
F_9 ( V_2 -> V_12 , L_3 , V_9 ) ;
F_10 ( V_2 , V_21 ,
V_22 ,
V_22 ) ;
}
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
for ( V_8 = V_20 ; V_8 > 0 ; -- V_8 ) {
if ( V_23 ==
( F_2 ( V_2 , V_24 ) &
V_25 ) ) {
F_9 ( V_2 -> V_12 , L_4 ) ;
break;
}
F_8 ( 1 ) ;
}
if ( ! V_8 ) {
F_4 ( V_2 -> V_12 , L_5 , V_9 ) ;
V_7 = - V_18 ;
goto V_19;
}
return V_7 ;
V_19:
V_2 -> V_10 . V_26 ( V_2 -> V_12 , & V_2 -> V_13 , V_6 ) ;
F_13 ( V_2 ) ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_7 ;
V_2 -> V_10 . V_27 ( V_2 -> V_12 , true , V_2 -> V_10 . V_6 ) ;
V_7 = F_15 ( V_2 , V_24 , V_25 ,
V_28 , V_29 , L_6 ) ;
V_2 -> V_10 . V_27 ( V_2 -> V_12 , false , V_2 -> V_10 . V_6 ) ;
V_2 -> V_10 . V_26 ( V_2 -> V_12 , & V_2 -> V_13 , V_2 -> V_10 . V_6 ) ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 )
{
const struct V_30 * V_31 = NULL ;
struct V_32 * V_33 = V_2 -> V_34 ;
int V_7 ;
V_7 = F_17 ( & V_31 , V_2 -> V_35 , V_2 -> V_12 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_7 , V_7 ) ;
goto V_36;
}
V_7 = F_3 ( V_2 , V_31 -> V_37 , V_31 -> V_38 ) ;
if ( V_7 < 0 ) {
V_7 = F_3 ( V_2 , V_31 -> V_37 , V_31 -> V_38 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_8 , V_7 ) ;
goto V_36;
}
}
V_7 = F_14 ( V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_9 , V_7 ) ;
F_9 ( V_2 -> V_12 , L_10 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_24 ) ) ;
F_13 ( V_2 ) ;
} else {
F_18 ( V_2 -> V_12 , L_11 ) ;
V_7 = F_19 ( V_33 -> V_39 , V_33 -> V_40 ,
F_20 ( V_41 ) ) ;
if ( V_7 == 0 ) {
F_4 ( V_2 -> V_12 , L_12 ) ;
F_13 ( V_2 ) ;
V_7 = - V_18 ;
} else {
F_21 ( V_2 , V_42 ) ;
V_7 = 0 ;
}
}
V_36:
F_22 ( V_31 ) ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 ;
int V_7 ;
V_33 -> V_40 = false ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_13 , V_7 ) ;
return V_7 ;
}
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_7 = F_19 ( V_33 -> V_39 , V_33 -> V_40 ,
F_20 ( V_41 ) ) ;
if ( V_7 == 0 ) {
F_4 ( V_2 -> V_12 , L_14 ) ;
F_4 ( V_2 -> V_12 , L_10 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_24 ) ) ;
return - V_18 ;
}
F_21 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_43 V_44 ;
struct V_32 * V_33 = V_2 -> V_34 ;
int V_7 = 0 ;
if ( ! F_25 ( V_2 ) )
return V_7 ;
V_44 . V_45 = V_46 ;
V_44 . V_47 = V_48 ;
V_7 = F_26 ( & V_33 -> V_49 , V_50 ,
V_51 , & V_44 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_15 , V_7 ) ;
return V_7 ;
}
V_7 = F_13 ( V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_16 , V_7 ) ;
V_7 = - V_18 ;
}
F_21 ( V_2 , V_52 ) ;
return 0 ;
}
int F_27 ( struct V_53 * V_12 , void T_2 * V_54 , int V_55 ,
const char * V_35 , struct V_56 V_10 ,
struct V_32 * * V_57 )
{
struct V_32 * V_33 ;
struct V_1 * V_58 ;
int V_7 ;
V_33 = F_28 ( V_12 , sizeof( * V_33 ) , V_59 ) ;
if ( V_33 == NULL )
return - V_60 ;
V_33 -> V_12 = V_12 ;
V_61 . V_34 = V_33 ;
V_33 -> V_57 = F_29 ( V_12 , & V_61 , V_55 ) ;
if ( ! V_33 -> V_57 ) {
F_4 ( V_33 -> V_12 , L_17 ) ;
return - V_62 ;
}
V_58 = V_33 -> V_57 ;
V_58 -> V_35 = V_35 ;
V_58 -> V_10 = V_10 ;
V_58 -> V_63 = V_64 ;
V_58 -> V_65 . V_66 = V_54 ;
V_58 -> V_65 . V_67 = V_54 ;
F_30 ( V_58 , ( V_68 + V_69 ) ,
V_70 , V_71 , V_72 ) ;
F_31 ( & V_58 -> V_73 ) ;
V_7 = F_32 ( V_12 , V_33 ) ;
if ( V_7 )
return V_7 ;
V_33 -> V_40 = false ;
F_33 ( & V_33 -> V_39 ) ;
V_7 = V_58 -> V_63 . V_74 ( V_58 ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_18 , V_7 ) ;
return V_7 ;
}
if ( V_57 )
* V_57 = V_33 ;
return 0 ;
}
void F_34 ( struct V_53 * V_12 , struct V_32 * V_2 )
{
F_35 ( & V_2 -> V_49 ) ;
V_2 -> V_57 -> V_75 . V_76 . V_77 ( V_2 -> V_57 ) ;
if ( V_2 -> V_57 -> V_65 . V_66 )
F_36 ( V_2 -> V_57 -> V_65 . V_66 ) ;
V_2 -> V_57 -> V_76 -> free ( V_2 -> V_57 ) ;
}
