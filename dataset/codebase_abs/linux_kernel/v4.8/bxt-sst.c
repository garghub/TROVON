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
if ( V_6 <= 0 ) {
F_4 ( V_2 -> V_12 , L_1 ,
V_6 ) ;
return V_6 ;
}
V_2 -> V_10 . V_6 = V_6 ;
memcpy ( V_2 -> V_13 . V_14 , V_4 , V_5 ) ;
V_7 = F_5 ( V_2 , V_15 |
F_6 ( 1 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_2 ) ;
goto V_16;
}
F_7 ( V_2 , V_17 , V_18 |
( V_19 | ( ( V_6 - 1 ) << 9 ) ) ) ;
V_7 = F_8 ( V_2 , V_15 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_3 , V_7 ) ;
V_7 = - V_20 ;
goto V_16;
}
for ( V_8 = V_21 ; V_8 > 0 ; -- V_8 ) {
V_9 = F_2 ( V_2 , V_22 ) ;
if ( V_9 & V_23 ) {
F_9 ( V_2 ,
V_22 ,
V_23 ,
V_23 ) ;
break;
}
F_10 ( 1 ) ;
}
if ( ! V_8 ) {
F_11 ( V_2 -> V_12 , L_4 , V_9 ) ;
F_12 ( V_2 , V_22 ,
V_23 ,
V_23 ) ;
}
V_7 = F_13 ( V_2 , F_6 ( 1 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_5 ) ;
goto V_16;
}
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
for ( V_8 = V_21 ; V_8 > 0 ; -- V_8 ) {
if ( V_24 ==
( F_2 ( V_2 , V_25 ) &
V_26 ) ) {
F_11 ( V_2 -> V_12 , L_6 ) ;
break;
}
F_10 ( 1 ) ;
}
if ( ! V_8 ) {
F_4 ( V_2 -> V_12 , L_7 , V_9 ) ;
V_7 = - V_20 ;
goto V_16;
}
return V_7 ;
V_16:
V_2 -> V_10 . V_27 ( V_2 -> V_12 , & V_2 -> V_13 , V_6 ) ;
F_13 ( V_2 , F_6 ( 1 ) ) ;
F_16 ( V_2 , V_15 ) ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 ;
V_2 -> V_10 . V_28 ( V_2 -> V_12 , true , V_2 -> V_10 . V_6 ) ;
V_7 = F_18 ( V_2 , V_25 , V_26 ,
V_29 , V_30 , L_8 ) ;
V_2 -> V_10 . V_28 ( V_2 -> V_12 , false , V_2 -> V_10 . V_6 ) ;
V_2 -> V_10 . V_27 ( V_2 -> V_12 , & V_2 -> V_13 , V_2 -> V_10 . V_6 ) ;
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_31 V_32 ;
struct V_33 * V_34 = V_2 -> V_35 ;
int V_7 ;
V_7 = F_20 ( & V_2 -> V_36 , V_2 -> V_37 , V_2 -> V_12 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_9 , V_7 ) ;
goto V_38;
}
if ( V_2 -> V_36 == NULL )
goto V_38;
V_7 = F_21 ( V_2 , V_39 ) ;
if ( V_7 < 0 )
goto V_38;
V_32 . V_40 = V_2 -> V_36 -> V_40 ;
V_32 . V_41 = V_2 -> V_36 -> V_41 ;
F_22 ( & V_32 ) ;
V_7 = F_3 ( V_2 , V_32 . V_40 , V_32 . V_41 ) ;
if ( V_7 < 0 ) {
V_7 = F_3 ( V_2 , V_32 . V_40 , V_32 . V_41 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_10 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_25 ) ) ;
F_4 ( V_2 -> V_12 , L_11 , V_7 ) ;
goto V_38;
}
}
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_12 , V_7 ) ;
F_11 ( V_2 -> V_12 , L_10 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_25 ) ) ;
F_16 ( V_2 , V_15 ) ;
} else {
F_23 ( V_2 -> V_12 , L_13 ) ;
V_7 = F_24 ( V_34 -> V_42 , V_34 -> V_43 ,
F_25 ( V_44 ) ) ;
if ( V_7 == 0 ) {
F_4 ( V_2 -> V_12 , L_14 ) ;
F_16 ( V_2 , V_15 ) ;
V_7 = - V_20 ;
} else {
V_7 = 0 ;
V_34 -> V_45 = true ;
}
}
V_38:
F_26 ( V_2 -> V_36 ) ;
return V_7 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_46 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
int V_7 ;
struct V_47 V_48 ;
unsigned int V_49 = F_6 ( V_46 ) ;
if ( V_34 -> V_45 == false ) {
V_34 -> V_43 = false ;
V_7 = F_19 ( V_2 ) ;
if ( V_7 < 0 )
F_4 ( V_2 -> V_12 , L_15 , V_7 ) ;
return V_7 ;
}
if ( V_46 == V_50 )
V_7 = F_5 ( V_2 , V_49 |
F_6 ( 1 ) ) ;
else
V_7 = F_5 ( V_2 , V_49 ) ;
if ( V_7 < 0 )
goto V_51;
if ( V_46 == V_50 ) {
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_34 -> V_43 = false ;
}
V_7 = F_8 ( V_2 , V_49 ) ;
if ( V_7 < 0 )
goto V_51;
if ( V_46 == V_50 ) {
V_7 = F_24 ( V_34 -> V_42 ,
V_34 -> V_43 ,
F_25 ( V_44 ) ) ;
F_13 ( V_2 , F_6 ( 1 ) ) ;
if ( V_7 == 0 ) {
F_4 ( V_2 -> V_12 , L_16 , V_52 ) ;
F_4 ( V_2 -> V_12 , L_10 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_25 ) ) ;
F_4 ( V_2 -> V_12 , L_17 ) ;
V_7 = - V_20 ;
goto V_51;
}
}
if ( V_46 != V_50 ) {
V_48 . V_49 = V_49 ;
V_48 . V_53 = V_49 ;
V_7 = F_28 ( & V_34 -> V_54 , V_55 ,
V_56 , & V_48 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_18 ,
V_46 , V_7 ) ;
goto V_51;
}
}
V_34 -> V_57 . V_58 [ V_46 ] = V_59 ;
return 0 ;
V_51:
if ( V_46 == V_50 )
V_49 |= F_6 ( 1 ) ;
F_16 ( V_2 , V_49 ) ;
return V_7 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_46 )
{
int V_7 ;
struct V_47 V_48 ;
struct V_33 * V_34 = V_2 -> V_35 ;
unsigned int V_49 = F_6 ( V_46 ) ;
V_48 . V_49 = V_49 ;
V_48 . V_53 = V_60 ;
F_23 ( V_2 -> V_12 , L_19 ,
V_48 . V_49 , V_48 . V_53 ) ;
V_7 = F_28 ( & V_34 -> V_54 , V_55 ,
V_56 , & V_48 ) ;
if ( V_7 < 0 )
F_4 ( V_2 -> V_12 ,
L_20 ,
V_46 ) ;
V_7 = F_16 ( V_2 , V_49 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_12 , L_21 , V_7 ) ;
return V_7 ;
}
V_34 -> V_57 . V_58 [ V_46 ] = V_61 ;
return 0 ;
}
int F_30 ( struct V_62 * V_12 , void T_2 * V_63 , int V_64 ,
const char * V_37 , struct V_65 V_10 ,
struct V_33 * * V_66 )
{
struct V_33 * V_34 ;
struct V_1 * V_67 ;
int V_7 ;
V_34 = F_31 ( V_12 , sizeof( * V_34 ) , V_68 ) ;
if ( V_34 == NULL )
return - V_69 ;
V_34 -> V_12 = V_12 ;
V_70 . V_35 = V_34 ;
F_32 ( & V_34 -> V_71 ) ;
V_34 -> V_66 = F_33 ( V_12 , & V_70 , V_64 ) ;
if ( ! V_34 -> V_66 ) {
F_4 ( V_34 -> V_12 , L_22 ) ;
return - V_72 ;
}
V_67 = V_34 -> V_66 ;
V_67 -> V_37 = V_37 ;
V_67 -> V_10 = V_10 ;
V_67 -> V_73 = V_74 ;
V_67 -> V_75 . V_76 = V_63 ;
V_67 -> V_75 . V_77 = V_63 ;
F_34 ( V_67 , ( V_78 + V_79 ) ,
V_80 , V_81 , V_82 ) ;
F_32 ( & V_67 -> V_83 ) ;
V_7 = F_35 ( V_12 , V_34 ) ;
if ( V_7 )
return V_7 ;
V_34 -> V_57 . V_84 = 2 ;
V_34 -> V_43 = false ;
F_36 ( & V_34 -> V_42 ) ;
V_7 = V_67 -> V_73 . V_85 ( V_67 ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_23 , V_7 ) ;
return V_7 ;
}
F_37 ( V_67 ) ;
if ( V_66 )
* V_66 = V_34 ;
return 0 ;
}
void F_38 ( struct V_62 * V_12 , struct V_33 * V_2 )
{
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_54 ) ;
V_2 -> V_66 -> V_86 . V_87 . V_88 ( V_2 -> V_66 ) ;
if ( V_2 -> V_66 -> V_75 . V_76 )
F_41 ( V_2 -> V_66 -> V_75 . V_76 ) ;
V_2 -> V_66 -> V_87 -> free ( V_2 -> V_66 ) ;
}
