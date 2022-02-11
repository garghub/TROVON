static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , int * V_4 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_8 , 2 , ( V_9 * ) V_4 ) ;
* V_4 &= 0xffff ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static void F_8 ( const char * V_10 )
{
struct V_11 * V_12 = V_13 ;
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned int V_4 ;
unsigned int V_14 = 0 ;
V_4 = F_4 ( V_2 , V_15 ) ;
if ( ! strncmp ( V_10 , L_2 , 6 ) ) {
V_14 = V_16 ;
V_4 &= ~ V_17 ;
} else if ( ! strncmp ( V_10 , L_3 , 4 ) ) {
V_14 = V_18 ;
V_4 &= ~ V_17 ;
} else if ( ! strncmp ( V_10 , L_4 , 5 ) ) {
V_14 = V_19 ;
V_4 &= ~ V_17 ;
} else if ( ! strncmp ( V_10 , L_5 , 5 ) ) {
V_14 = V_20 ;
V_4 &= ~ V_17 ;
} else if ( ! strncmp ( V_10 , L_6 , 4 ) ) {
V_14 = V_21 ;
V_4 |= V_17 ;
} else {
F_9 ( V_22 L_7 ) ;
return;
}
V_12 -> V_23 = V_14 ;
F_1 ( V_2 , V_24 , V_14 ) ;
F_1 ( V_2 , V_15 , V_4 ) ;
}
static T_1 F_10 ( char * V_10 )
{
struct V_11 * V_12 = V_13 ;
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned int V_4 ;
V_4 = F_4 ( V_2 , V_24 ) ;
if ( V_4 == V_16 )
return sprintf ( V_10 , L_8 ) ;
else if ( V_4 == V_18 )
return sprintf ( V_10 , L_9 ) ;
else if ( V_4 == V_19 )
return sprintf ( V_10 , L_10 ) ;
else if ( V_4 == V_20 )
return sprintf ( V_10 , L_11 ) ;
else if ( V_4 == V_21 )
return sprintf ( V_10 , L_12 ) ;
else
return sprintf ( V_10 , L_13 , V_4 ) ;
}
static T_1 F_11 ( struct V_25 * V_6 ,
struct V_26 * V_27 ,
char * V_10 )
{
struct V_11 * V_12 = F_12 ( V_6 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_28 , V_29 ;
V_28 = F_4 ( V_2 , V_30 ) ;
V_29 = F_4 ( V_2 , V_31 ) ;
if ( ! V_28 && ! V_29 )
return sprintf ( V_10 , L_14 ) ;
if ( V_28 & V_32 || V_29 & V_33 )
return sprintf ( V_10 , L_15 ) ;
if ( V_28 & V_34 || V_29 & V_35 )
return sprintf ( V_10 , L_9 ) ;
if ( V_28 & V_36 )
return sprintf ( V_10 , L_16 ) ;
if ( V_29 & V_37 )
return sprintf ( V_10 , L_17 ) ;
return sprintf ( V_10 , L_18 ) ;
}
static T_1 F_13 ( struct V_25 * V_6 ,
struct V_26 * V_27 , char * V_10 )
{
return F_10 ( V_10 ) ;
}
static T_1 F_14 ( struct V_25 * V_6 ,
struct V_26 * V_27 ,
const char * V_10 , T_2 V_38 )
{
F_8 ( V_10 ) ;
return V_38 ;
}
static void F_15 ( struct V_11 * V_12 , int V_39 )
{
int V_40 , V_41 , V_42 ;
struct V_43 * V_44 = V_12 -> V_44 ;
struct V_1 * V_2 = V_12 -> V_2 ;
V_40 = F_4 ( V_2 , V_30 ) ;
V_41 = F_4 ( V_2 , V_31 ) ;
V_42 = F_4 ( V_2 , V_15 ) ;
F_16 ( & V_2 -> V_6 , L_19 ,
V_39 , V_40 , V_41 ) ;
if ( ! V_39 )
goto V_45;
if ( V_39 & V_46 ) {
if ( V_40 & V_32 || V_41 & V_33 ) {
if ( V_44 -> V_47 )
V_44 -> V_47 ( V_48 ) ;
if ( V_12 -> V_23 ) {
F_1 ( V_2 ,
V_24 , V_12 -> V_23 ) ;
}
}
if ( V_40 & V_34 || V_41 & V_35 ) {
if ( V_44 -> V_49 )
V_44 -> V_49 ( V_48 ) ;
if ( ! ( V_42 & V_17 ) ) {
F_1 ( V_2 ,
V_24 , V_18 ) ;
}
}
if ( V_40 & V_36 ) {
if ( V_44 -> V_50 )
V_44 -> V_50 ( V_48 ) ;
}
if ( V_41 & V_37 ) {
if ( V_44 -> V_51 )
V_44 -> V_51 ( V_48 ) ;
}
} else if ( V_39 & V_52 ) {
if ( V_12 -> V_28 & V_32 ||
V_12 -> V_29 & V_33 ) {
if ( V_44 -> V_47 )
V_44 -> V_47 ( V_53 ) ;
}
if ( V_12 -> V_28 & V_34 ||
V_12 -> V_29 & V_35 ) {
if ( V_44 -> V_49 )
V_44 -> V_49 ( V_53 ) ;
}
if ( V_12 -> V_28 & V_36 ) {
if ( V_44 -> V_50 )
V_44 -> V_50 ( V_53 ) ;
}
if ( V_12 -> V_29 & V_37 ) {
if ( V_44 -> V_51 )
V_44 -> V_51 ( V_53 ) ;
}
}
V_12 -> V_28 = V_40 ;
V_12 -> V_29 = V_41 ;
V_45:
V_42 &= ~ V_54 ;
F_1 ( V_2 , V_15 , V_42 ) ;
}
static T_3 F_17 ( int V_55 , void * V_56 )
{
struct V_11 * V_12 = V_56 ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_39 ;
F_6 ( V_2 , & V_39 ) ;
F_15 ( V_12 , V_39 ) ;
return V_57 ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_43 * V_44 = V_12 -> V_44 ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_5 ;
int V_39 ;
unsigned int V_42 = V_58 ;
F_6 ( V_2 , & V_39 ) ;
F_1 ( V_2 , V_59 , 0xfc ) ;
F_1 ( V_2 , V_60 , 0x1f ) ;
V_12 -> V_23 = F_4 ( V_2 , V_24 ) ;
if ( V_12 -> V_23 )
V_42 &= ~ V_17 ;
F_1 ( V_2 , V_15 , V_42 ) ;
if ( V_44 && V_44 -> V_61 )
V_44 -> V_61 () ;
if ( V_2 -> V_55 ) {
V_5 = F_19 ( V_2 -> V_55 , NULL ,
F_17 ,
V_62 | V_63 ,
L_20 , V_12 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_21 ) ;
return V_5 ;
}
if ( V_44 )
F_20 ( & V_2 -> V_6 , V_44 -> V_64 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_65 * V_66 )
{
struct V_67 * V_68 = F_22 ( V_2 -> V_6 . V_69 ) ;
struct V_11 * V_12 ;
int V_5 = 0 ;
if ( ! F_23 ( V_68 , V_70 ) )
return - V_71 ;
V_12 = F_24 ( sizeof( struct V_11 ) , V_72 ) ;
if ( ! V_12 ) {
F_3 ( & V_2 -> V_6 , L_22 ) ;
return - V_73 ;
}
V_12 -> V_2 = V_2 ;
V_12 -> V_44 = V_2 -> V_6 . V_74 ;
V_13 = V_12 ;
F_25 ( V_2 , V_12 ) ;
V_5 = F_18 ( V_12 ) ;
if ( V_5 )
goto V_75;
V_5 = F_26 ( & V_2 -> V_6 . V_76 , & V_77 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 ,
L_23 ) ;
goto V_78;
}
F_1 ( V_2 , V_79 , 0x6 ) ;
if ( V_13 -> V_44 -> V_80 )
V_13 -> V_44 -> V_80 () ;
F_15 ( V_12 , V_46 ) ;
F_27 ( & V_2 -> V_6 ) ;
return 0 ;
V_78:
if ( V_2 -> V_55 )
F_28 ( V_2 -> V_55 , V_12 ) ;
V_75:
F_29 ( V_12 ) ;
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_31 ( V_2 ) ;
if ( V_2 -> V_55 )
F_28 ( V_2 -> V_55 , V_12 ) ;
F_32 ( & V_2 -> V_6 . V_76 , & V_77 ) ;
F_20 ( & V_2 -> V_6 , 0 ) ;
F_29 ( V_12 ) ;
return 0 ;
}
static int F_33 ( struct V_25 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
struct V_11 * V_12 = F_31 ( V_2 ) ;
struct V_43 * V_44 = V_12 -> V_44 ;
if ( F_35 ( & V_2 -> V_6 ) && V_2 -> V_55 )
F_36 ( V_2 -> V_55 ) ;
if ( V_44 -> V_81 )
V_44 -> V_81 ( 0 ) ;
return 0 ;
}
static int F_37 ( struct V_25 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
struct V_11 * V_12 = F_31 ( V_2 ) ;
int V_28 , V_29 ;
if ( F_35 ( & V_2 -> V_6 ) && V_2 -> V_55 )
F_38 ( V_2 -> V_55 ) ;
F_4 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_82 ) ;
V_28 = F_4 ( V_2 , V_30 ) ;
V_29 = F_4 ( V_2 , V_31 ) ;
F_15 ( V_12 , ( V_28 || V_29 ) ? V_46 : V_52 ) ;
return 0 ;
}
