static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
const struct V_11 * V_12 = NULL ;
struct V_11 V_13 ;
int V_14 = 0 , V_15 , V_16 , V_17 ;
for ( V_15 = 1 ; V_15 < V_5 -> V_18 ; V_15 ++ ) {
V_14 = F_4 ( & V_12 , V_5 -> V_19 [ V_15 ] . V_20 , V_2 -> V_21 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_1 ,
V_5 -> V_19 [ V_15 ] . V_20 , V_14 ) ;
return V_14 ;
}
if ( V_9 -> V_22 ) {
V_14 = F_6 ( V_2 , V_12 ,
V_23 , V_15 ) ;
if ( V_14 < 0 )
goto V_24;
}
V_13 . V_25 = V_12 -> V_25 ;
V_13 . V_26 = V_12 -> V_26 ;
F_7 ( & V_13 ) ;
V_17 = V_2 -> V_27 . V_28 ( V_2 -> V_21 , 0x40 ,
V_13 . V_26 , & V_7 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_21 , L_2 ,
V_17 ) ;
V_14 = V_17 ;
goto V_24;
}
V_16 = V_17 - 1 ;
memcpy ( V_7 . V_29 , V_13 . V_25 , V_13 . V_26 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , true , V_17 ) ;
V_14 = F_8 ( & V_9 -> V_31 , V_16 , V_15 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_21 , L_3 ,
V_5 -> V_19 [ V_15 ] . V_20 , V_14 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , false , V_17 ) ;
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_7 , V_17 ) ;
F_9 ( V_12 ) ;
V_12 = NULL ;
}
return V_14 ;
V_24:
F_9 ( V_12 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
const void * V_33 , T_1 V_34 )
{
int V_17 , V_14 , V_15 ;
T_1 V_35 ;
V_17 = V_2 -> V_27 . V_28 ( V_2 -> V_21 , 0x40 , V_34 , & V_2 -> V_7 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_21 , L_4 ,
V_17 ) ;
return V_17 ;
}
V_2 -> V_27 . V_17 = V_17 ;
memcpy ( V_2 -> V_7 . V_29 , V_33 , V_34 ) ;
V_14 = F_11 ( V_2 , V_36 |
F_12 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_5 ) ;
goto V_37;
}
F_13 ( V_2 , V_38 , V_39 |
( V_40 | ( ( V_17 - 1 ) << 9 ) ) ) ;
V_14 = F_14 ( V_2 , V_36 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_6 , V_14 ) ;
V_14 = - V_41 ;
goto V_37;
}
for ( V_15 = V_42 ; V_15 > 0 ; -- V_15 ) {
V_35 = F_2 ( V_2 , V_43 ) ;
if ( V_35 & V_44 ) {
F_15 ( V_2 ,
V_43 ,
V_44 ,
V_44 ) ;
break;
}
F_16 ( 1 ) ;
}
if ( ! V_15 ) {
F_17 ( V_2 -> V_21 , L_7 , V_35 ) ;
F_18 ( V_2 , V_43 ,
V_44 ,
V_44 ) ;
}
V_14 = F_19 ( V_2 , F_12 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_8 ) ;
goto V_37;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
for ( V_15 = V_42 ; V_15 > 0 ; -- V_15 ) {
if ( V_45 ==
( F_2 ( V_2 , V_46 ) &
V_47 ) ) {
F_17 ( V_2 -> V_21 , L_9 ) ;
break;
}
F_16 ( 1 ) ;
}
if ( ! V_15 ) {
F_5 ( V_2 -> V_21 , L_10 , V_35 ) ;
V_14 = - V_41 ;
goto V_37;
}
return V_14 ;
V_37:
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_2 -> V_7 , V_17 ) ;
F_19 ( V_2 , F_12 ( 1 ) ) ;
F_22 ( V_2 , V_36 ) ;
return V_14 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_14 ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , true , V_2 -> V_27 . V_17 ) ;
V_14 = F_24 ( V_2 , V_46 , V_47 ,
V_48 , V_49 , L_11 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , false , V_2 -> V_27 . V_17 ) ;
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_2 -> V_7 , V_2 -> V_27 . V_17 ) ;
return V_14 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_11 V_13 ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
V_14 = F_4 ( & V_2 -> V_12 , V_2 -> V_50 , V_2 -> V_21 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_12 , V_14 ) ;
goto V_51;
}
if ( V_2 -> V_12 == NULL )
goto V_51;
if ( V_9 -> V_22 ) {
V_14 = F_6 ( V_2 , V_2 -> V_12 , V_23 , 0 ) ;
if ( V_14 < 0 )
goto V_51;
}
V_13 . V_25 = V_2 -> V_12 -> V_25 ;
V_13 . V_26 = V_2 -> V_12 -> V_26 ;
F_7 ( & V_13 ) ;
V_14 = F_10 ( V_2 , V_13 . V_25 , V_13 . V_26 ) ;
if ( V_14 < 0 ) {
V_14 = F_10 ( V_2 , V_13 . V_25 , V_13 . V_26 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_5 ( V_2 -> V_21 , L_14 , V_14 ) ;
goto V_51;
}
}
V_14 = F_23 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_15 , V_14 ) ;
F_17 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_22 ( V_2 , V_36 ) ;
} else {
F_26 ( V_2 -> V_21 , L_16 ) ;
V_14 = F_27 ( V_9 -> V_52 , V_9 -> V_53 ,
F_28 ( V_54 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_21 , L_17 ) ;
F_22 ( V_2 , V_36 ) ;
V_14 = - V_41 ;
} else {
V_14 = 0 ;
V_9 -> V_55 = true ;
}
}
V_51:
F_9 ( V_2 -> V_12 ) ;
return V_14 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_56 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
struct V_57 V_58 ;
unsigned int V_59 = F_12 ( V_56 ) ;
struct V_4 * V_5 = & V_9 -> V_60 ;
if ( V_9 -> V_55 == false ) {
V_9 -> V_53 = false ;
V_14 = F_25 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_18 , V_14 ) ;
return V_14 ;
}
if ( V_5 -> V_18 > 1 ) {
V_14 = F_3 ( V_2 , V_5 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_19 , V_14 ) ;
return V_14 ;
}
}
return V_14 ;
}
if ( V_56 == V_61 )
V_14 = F_11 ( V_2 , V_59 |
F_12 ( 1 ) ) ;
else
V_14 = F_11 ( V_2 , V_59 ) ;
if ( V_14 < 0 )
goto V_62;
if ( V_56 == V_61 ) {
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_9 -> V_53 = false ;
}
V_14 = F_14 ( V_2 , V_59 ) ;
if ( V_14 < 0 )
goto V_62;
if ( V_56 == V_61 ) {
V_14 = F_27 ( V_9 -> V_52 ,
V_9 -> V_53 ,
F_28 ( V_54 ) ) ;
F_19 ( V_2 , F_12 ( 1 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_21 , L_20 , V_63 ) ;
F_5 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_5 ( V_2 -> V_21 , L_21 ) ;
V_14 = - V_41 ;
goto V_62;
}
}
if ( V_56 != V_61 ) {
V_58 . V_59 = V_59 ;
V_58 . V_64 = V_59 ;
V_14 = F_30 ( & V_9 -> V_31 , V_65 ,
V_66 , & V_58 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_22 ,
V_56 , V_14 ) ;
goto V_62;
}
}
V_9 -> V_67 . V_68 [ V_56 ] = V_69 ;
return 0 ;
V_62:
if ( V_56 == V_61 )
V_59 |= F_12 ( 1 ) ;
F_22 ( V_2 , V_59 ) ;
return V_14 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int V_56 )
{
int V_14 ;
struct V_57 V_58 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_59 = F_12 ( V_56 ) ;
V_58 . V_59 = V_59 ;
V_58 . V_64 = V_70 ;
F_26 ( V_2 -> V_21 , L_23 ,
V_58 . V_59 , V_58 . V_64 ) ;
V_14 = F_30 ( & V_9 -> V_31 , V_65 ,
V_66 , & V_58 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_21 ,
L_24 ,
V_56 ) ;
V_14 = F_22 ( V_2 , V_59 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_25 , V_14 ) ;
return V_14 ;
}
V_9 -> V_67 . V_68 [ V_56 ] = V_71 ;
return 0 ;
}
int F_32 ( struct V_72 * V_21 , void T_2 * V_73 , int V_74 ,
const char * V_50 , struct V_75 V_27 ,
struct V_8 * * V_76 )
{
struct V_8 * V_9 ;
struct V_1 * V_77 ;
int V_14 ;
V_9 = F_33 ( V_21 , sizeof( * V_9 ) , V_78 ) ;
if ( V_9 == NULL )
return - V_79 ;
V_9 -> V_21 = V_21 ;
V_80 . V_10 = V_9 ;
F_34 ( & V_9 -> V_81 ) ;
V_9 -> V_76 = F_35 ( V_21 , & V_80 , V_74 ) ;
if ( ! V_9 -> V_76 ) {
F_5 ( V_9 -> V_21 , L_26 ) ;
return - V_82 ;
}
V_77 = V_9 -> V_76 ;
V_77 -> V_50 = V_50 ;
V_77 -> V_27 = V_27 ;
V_77 -> V_83 = V_84 ;
V_77 -> V_85 . V_86 = V_73 ;
V_77 -> V_85 . V_87 = V_73 ;
F_36 ( V_77 , ( V_88 + V_89 ) ,
V_90 , V_91 , V_92 ) ;
F_34 ( & V_77 -> V_93 ) ;
V_14 = F_37 ( V_21 , V_9 ) ;
if ( V_14 )
return V_14 ;
V_9 -> V_67 . V_94 = 2 ;
V_9 -> V_53 = false ;
F_38 ( & V_9 -> V_52 ) ;
V_9 -> V_22 = true ;
if ( V_76 )
* V_76 = V_9 ;
return 0 ;
}
int F_39 ( struct V_72 * V_21 , struct V_8 * V_2 )
{
int V_14 ;
struct V_1 * V_77 = V_2 -> V_76 ;
V_14 = V_77 -> V_83 . V_95 ( V_77 ) ;
if ( V_14 < 0 ) {
F_5 ( V_21 , L_27 , V_14 ) ;
return V_14 ;
}
F_40 ( V_77 ) ;
if ( V_2 -> V_60 . V_18 > 1 ) {
V_14 = V_77 -> V_83 . V_96 ( V_77 , & V_2 -> V_60 ) ;
if ( V_14 < 0 ) {
F_5 ( V_21 , L_28 , V_14 ) ;
return V_14 ;
}
}
V_2 -> V_22 = false ;
return 0 ;
}
void F_41 ( struct V_72 * V_21 , struct V_8 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( & V_2 -> V_31 ) ;
V_2 -> V_76 -> V_97 . V_98 . V_99 ( V_2 -> V_76 ) ;
if ( V_2 -> V_76 -> V_85 . V_86 )
F_44 ( V_2 -> V_76 -> V_85 . V_86 ) ;
V_2 -> V_76 -> V_98 -> free ( V_2 -> V_76 ) ;
}
