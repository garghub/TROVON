static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( unsigned long V_4 , T_1 V_5 )
{
int V_6 = V_7 | V_8 | ( V_4 ? V_9 : 0 ) ;
F_4 ( V_6 , V_5 ) ;
F_5 ( 4 ) ;
F_4 ( V_6 | V_10 , V_5 ) ;
F_5 ( 4 ) ;
F_4 ( V_6 , V_5 ) ;
F_5 ( 4 ) ;
}
static void F_6 ( struct V_1 * V_11 , int V_12 )
{
if ( V_12 != 0 ) {
F_7 ( V_11 , 1 , L_1 ) ;
F_4 ( V_7 , V_11 -> V_5 ) ;
} else {
F_7 ( V_11 , 1 , L_2 ) ;
F_4 ( 0 , V_11 -> V_5 ) ;
}
}
static void F_8 ( struct V_1 * V_11 , T_2 V_13 )
{
unsigned long int V_14 ;
int V_15 ;
int V_5 = V_11 -> V_5 ;
int V_6 = F_9 ( V_13 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 1 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
F_3 ( 0 , V_5 ) ;
V_14 = 0x8000 ;
for ( V_15 = 1 ; V_15 <= 16 ; V_15 ++ ) {
F_3 ( V_6 & V_14 , V_5 ) ;
V_14 >>= 1 ;
}
F_7 ( V_11 , 1 , L_3 ,
V_13 / 16000 ,
V_13 % 16000 * 100 / 16000 ) ;
F_6 ( V_11 , 1 ) ;
}
static int F_10 ( T_1 V_5 )
{
F_4 ( V_7 , V_5 ) ;
F_5 ( 4 ) ;
return ! ( F_11 ( V_5 ) & V_16 ) ;
}
static int F_12 ( T_1 V_5 )
{
F_4 ( V_7 + V_10 , V_5 ) ;
F_5 ( 4 ) ;
return ! ( F_11 ( V_5 ) & V_16 ) ;
}
static int F_13 ( struct V_17 * V_17 , void * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
F_15 ( V_20 -> V_21 , L_4 , sizeof( V_20 -> V_21 ) ) ;
F_15 ( V_20 -> V_22 , L_5 , sizeof( V_20 -> V_22 ) ) ;
snprintf ( V_20 -> V_23 , sizeof( V_20 -> V_23 ) , L_6 , F_16 ( V_11 -> V_24 ) ) ;
V_20 -> V_25 = V_26 | V_27 ;
return 0 ;
}
static int F_17 ( struct V_17 * V_17 , void * V_18 ,
struct V_28 * V_20 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
if ( V_20 -> V_29 > 0 )
return - V_30 ;
F_18 ( & V_11 -> V_31 ) ;
F_15 ( V_20 -> V_32 , L_7 , sizeof( V_20 -> V_32 ) ) ;
V_20 -> type = V_33 ;
V_20 -> V_34 = V_35 ;
V_20 -> V_36 = V_37 ;
V_20 -> V_38 = V_39 | V_40 ;
V_20 -> V_41 = V_42 ;
if ( F_10 ( V_11 -> V_5 ) )
V_20 -> V_43 = V_44 ;
else
V_20 -> V_43 = V_45 ;
V_20 -> signal = 0xffff * F_12 ( V_11 -> V_5 ) ;
F_19 ( & V_11 -> V_31 ) ;
return 0 ;
}
static int F_20 ( struct V_17 * V_17 , void * V_18 ,
struct V_28 * V_20 )
{
return V_20 -> V_29 ? - V_30 : 0 ;
}
static int F_21 ( struct V_17 * V_46 , void * V_18 , unsigned int * V_47 )
{
* V_47 = 0 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_46 , void * V_18 , unsigned int V_47 )
{
return V_47 ? - V_30 : 0 ;
}
static int F_23 ( struct V_17 * V_17 , void * V_18 ,
struct V_48 * V_49 )
{
V_49 -> V_29 = 0 ;
F_15 ( V_49 -> V_32 , L_8 , sizeof( V_49 -> V_32 ) ) ;
V_49 -> V_41 = V_50 ;
return 0 ;
}
static int F_24 ( struct V_17 * V_17 , void * V_18 ,
struct V_48 * V_49 )
{
return V_49 -> V_29 ? - V_30 : 0 ;
}
static int F_25 ( struct V_17 * V_17 , void * V_18 ,
struct V_51 * V_52 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
if ( V_52 -> V_53 != 0 || V_52 -> type != V_33 )
return - V_30 ;
if ( V_52 -> V_54 < V_35 || V_52 -> V_54 > V_37 ) {
F_7 ( V_11 , 1 , L_9 ,
V_52 -> V_54 / 16000 ,
V_52 -> V_54 % 16000 * 100 / 16000 ,
V_35 / 16000 , V_37 / 16000 ) ;
return - V_30 ;
}
F_18 ( & V_11 -> V_31 ) ;
V_11 -> V_13 = V_52 -> V_54 ;
F_8 ( V_11 , V_11 -> V_13 ) ;
F_26 ( 125 ) ;
F_19 ( & V_11 -> V_31 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_17 , void * V_18 ,
struct V_51 * V_52 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
if ( V_52 -> V_53 != 0 )
return - V_30 ;
V_52 -> type = V_33 ;
V_52 -> V_54 = V_11 -> V_13 ;
F_7 ( V_11 , 4 , L_10 ,
V_52 -> V_54 / 16000 ,
V_52 -> V_54 % 16000 * 100 / 16000 ) ;
return 0 ;
}
static int F_28 ( struct V_17 * V_17 , void * V_18 ,
struct V_55 * V_56 )
{
switch ( V_56 -> V_57 ) {
case V_58 :
return F_29 ( V_56 , 0 , 1 , 1 , 1 ) ;
}
return - V_30 ;
}
static int F_30 ( struct V_17 * V_17 , void * V_18 ,
struct V_59 * V_60 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
switch ( V_60 -> V_57 ) {
case V_58 :
V_60 -> V_61 = V_11 -> V_62 ;
return 0 ;
}
return - V_30 ;
}
static int F_31 ( struct V_17 * V_17 , void * V_18 ,
struct V_59 * V_60 )
{
struct V_1 * V_11 = F_14 ( V_17 ) ;
switch ( V_60 -> V_57 ) {
case V_58 :
F_18 ( & V_11 -> V_31 ) ;
V_11 -> V_62 = V_60 -> V_61 ;
if ( V_11 -> V_62 )
F_6 ( V_11 , 0 ) ;
else
F_8 ( V_11 , V_11 -> V_13 ) ;
F_19 ( & V_11 -> V_31 ) ;
return 0 ;
}
return - V_30 ;
}
static int T_3 F_32 ( struct V_63 * V_24 , const struct V_64 * V_65 )
{
struct V_1 * V_11 ;
struct V_2 * V_3 ;
int V_66 = - V_67 ;
V_11 = F_33 ( sizeof( * V_11 ) , V_68 ) ;
if ( V_11 == NULL ) {
F_34 ( & V_24 -> V_11 , L_11 ) ;
return - V_67 ;
}
V_3 = & V_11 -> V_3 ;
F_35 ( & V_11 -> V_31 ) ;
V_11 -> V_24 = V_24 ;
V_11 -> V_62 = 1 ;
V_11 -> V_13 = V_35 ;
F_15 ( V_3 -> V_32 , L_12 , sizeof( V_3 -> V_32 ) ) ;
V_66 = F_36 ( & V_24 -> V_11 , V_3 ) ;
if ( V_66 < 0 ) {
F_37 ( V_3 , L_13 ) ;
goto V_69;
}
if ( ! F_38 ( F_39 ( V_24 , 0 ) ,
F_40 ( V_24 , 0 ) , L_14 ) ) {
F_37 ( V_3 , L_15 ) ;
goto V_70;
}
if ( F_41 ( V_24 ) )
goto V_71;
V_11 -> V_5 = F_39 ( V_24 , 0 ) ;
F_15 ( V_11 -> V_72 . V_32 , V_3 -> V_32 , sizeof( V_11 -> V_72 . V_32 ) ) ;
V_11 -> V_72 . V_3 = V_3 ;
V_11 -> V_72 . V_73 = & V_74 ;
V_11 -> V_72 . V_75 = & V_76 ;
V_11 -> V_72 . V_77 = V_78 ;
F_42 ( & V_11 -> V_72 , V_11 ) ;
if ( F_43 ( & V_11 -> V_72 , V_79 , V_80 ) < 0 ) {
F_37 ( V_3 , L_16 ) ;
goto V_71;
}
F_44 ( V_3 , L_17 V_81 L_18 ) ;
F_44 ( V_3 , L_19 ,
V_11 -> V_5 ) ;
return 0 ;
V_71:
F_45 ( F_39 ( V_24 , 0 ) , F_40 ( V_24 , 0 ) ) ;
V_70:
F_46 ( V_3 ) ;
V_69:
F_47 ( V_11 ) ;
return - V_82 ;
}
static void T_4 F_48 ( struct V_63 * V_24 )
{
struct V_2 * V_3 = F_49 ( & V_24 -> V_11 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_50 ( & V_11 -> V_72 ) ;
F_46 ( & V_11 -> V_3 ) ;
F_45 ( F_39 ( V_24 , 0 ) , F_40 ( V_24 , 0 ) ) ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_83 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_83 ) ;
}
