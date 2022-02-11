static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
void * V_5 ,
unsigned int V_6 ,
void * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_10 = F_2 ( sizeof( * V_10 ) + F_3 ( V_6 , V_8 ) , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_8 = V_8 ;
if ( V_6 )
memcpy ( V_10 -> V_14 , V_5 , V_6 ) ;
V_11 = F_4 ( V_2 -> V_15 , V_10 ) ;
if ( V_11 >= 0 && V_8 )
memcpy ( V_7 , V_10 -> V_14 , V_8 ) ;
F_5 ( V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
struct V_18 V_19 ;
int V_11 ;
V_17 . V_20 = V_2 -> V_21 ;
V_11 = F_1 ( V_2 , V_22 , 0 ,
& V_17 , sizeof( V_17 ) , & V_19 , sizeof( V_19 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return V_19 . type ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_23 V_17 ;
struct V_24 V_19 ;
int V_11 ;
V_17 . V_20 = V_2 -> V_21 ;
V_11 = F_1 ( V_2 , V_25 , 0 ,
& V_17 , sizeof( V_17 ) ,
& V_19 , sizeof( V_19 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return V_19 . V_26 ;
}
static int F_8 ( struct V_1 * V_2 ,
bool * V_27 )
{
struct V_28 V_29 ;
struct V_30 V_19 ;
int V_11 ;
V_29 . V_20 = V_2 -> V_21 ;
V_29 . V_31 = V_32 ;
V_29 . V_33 = V_34 ;
V_11 = F_1 ( V_2 , V_35 , 1 ,
& V_29 , sizeof( V_29 ) ,
& V_19 , sizeof( V_19 ) ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! ( V_19 . V_36 & V_37 ) )
return - V_38 ;
* V_27 = V_19 . V_27 ;
return V_19 . V_31 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_39 V_19 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_40 ,
0 , NULL , 0 , & V_19 , sizeof( V_19 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return V_19 . V_41 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_42 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
int V_31 , V_45 ;
bool V_27 = false ;
bool V_46 = false ;
bool V_33 = false ;
bool V_47 = false ;
V_45 = F_6 ( V_2 ) ;
if ( V_45 < 0 ) {
F_11 ( V_44 , L_1 ,
V_45 ) ;
return V_45 ;
}
V_31 = F_8 ( V_2 , & V_27 ) ;
if ( V_31 < 0 ) {
if ( V_31 != - V_38 ) {
F_11 ( V_44 , L_2 , V_31 ) ;
return V_31 ;
}
} else {
int V_48 ;
V_48 = F_7 ( V_2 ) ;
if ( V_48 < 0 )
V_48 = V_49 ;
V_46 = V_48 & V_50 ;
V_33 = V_48 & V_49 ;
V_47 = V_48 & V_51 ;
}
if ( V_42 || V_2 -> V_46 != V_46 || V_2 -> V_33 != V_33 ||
V_2 -> V_45 != V_45 ) {
V_2 -> V_46 = V_46 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_45 = V_45 ;
F_12 ( V_2 -> V_52 , V_53 , V_46 ) ;
F_13 ( V_2 -> V_52 , V_53 ,
V_54 ,
(union V_55 ) ( int ) V_27 ) ;
F_13 ( V_2 -> V_52 , V_53 ,
V_56 ,
(union V_55 ) ( int ) V_33 ) ;
F_13 ( V_2 -> V_52 , V_53 ,
V_57 ,
(union V_55 ) ( int ) V_47 ) ;
F_14 ( V_2 -> V_52 , V_53 ) ;
} else if ( V_47 ) {
F_13 ( V_2 -> V_52 , V_53 ,
V_57 ,
(union V_55 ) ( int ) V_47 ) ;
F_14 ( V_2 -> V_52 , V_53 ) ;
}
return 0 ;
}
static int F_15 ( struct V_58 * V_59 ,
unsigned long V_60 ,
void * V_61 )
{
struct V_1 * V_2 ;
struct V_62 * V_15 ;
T_1 V_63 ;
V_2 = F_16 ( V_59 , struct V_1 , V_64 ) ;
V_15 = V_2 -> V_15 ;
V_63 = F_17 ( V_15 ) ;
if ( V_63 & ( F_18 ( V_65 ) |
F_18 ( V_66 ) ) ) {
F_10 ( V_2 , false ) ;
return V_67 ;
}
return V_68 ;
}
static int F_19 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_62 * V_15 = F_20 ( V_70 -> V_44 . V_71 ) ;
struct V_43 * V_44 = & V_70 -> V_44 ;
struct V_72 * V_73 = V_44 -> V_74 ;
int V_75 , V_11 ;
V_2 = F_21 ( V_44 , sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_13 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_15 = V_15 ;
if ( V_73 ) {
T_1 V_20 ;
V_11 = F_22 ( V_73 , L_3 , & V_20 ) ;
if ( V_11 < 0 ) {
F_11 ( V_44 , L_4 ) ;
return V_11 ;
}
V_2 -> V_21 = V_20 ;
} else {
V_2 -> V_21 = V_70 -> V_76 ;
}
V_75 = F_9 ( V_2 ) ;
if ( V_75 < 0 ) {
F_11 ( V_44 , L_5 ,
V_75 ) ;
return V_75 ;
}
if ( V_2 -> V_21 >= V_75 ) {
F_11 ( V_44 , L_6 , V_75 ) ;
return - V_77 ;
}
V_2 -> V_52 = F_23 ( V_44 , V_78 ) ;
if ( F_24 ( V_2 -> V_52 ) ) {
F_11 ( V_44 , L_7 ) ;
return - V_13 ;
}
V_11 = F_25 ( V_44 , V_2 -> V_52 ) ;
if ( V_11 < 0 ) {
F_11 ( V_44 , L_8 ) ;
return V_11 ;
}
F_26 ( V_2 -> V_52 , V_53 ,
V_54 ) ;
F_26 ( V_2 -> V_52 , V_53 ,
V_56 ) ;
F_26 ( V_2 -> V_52 , V_53 ,
V_57 ) ;
F_27 ( V_70 , V_2 ) ;
V_2 -> V_64 . V_79 = F_15 ;
V_11 = F_28 ( & V_2 -> V_15 -> V_80 ,
& V_2 -> V_64 ) ;
if ( V_11 < 0 ) {
F_11 ( V_44 , L_9 ) ;
return V_11 ;
}
V_11 = F_10 ( V_2 , true ) ;
if ( V_11 < 0 ) {
F_11 ( V_44 , L_10 ) ;
goto V_81;
}
return 0 ;
V_81:
F_29 ( & V_2 -> V_15 -> V_80 ,
& V_2 -> V_64 ) ;
return V_11 ;
}
static int F_30 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_31 ( V_70 ) ;
F_29 ( & V_2 -> V_15 -> V_80 ,
& V_2 -> V_64 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_44 )
{
return 0 ;
}
static int F_33 ( struct V_43 * V_44 )
{
int V_11 ;
struct V_1 * V_2 = F_20 ( V_44 ) ;
V_11 = F_10 ( V_2 , true ) ;
if ( V_11 < 0 )
F_11 ( V_44 , L_11 ) ;
return 0 ;
}
