static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 < 0 ) {
if ( V_3 == V_6 )
return 1 ;
else
return 0 ;
}
if ( V_2 -> V_7 )
return F_2 ( V_2 -> V_8 + V_4 ) ;
else
return F_3 ( V_2 -> V_8 + V_4 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
T_2 V_9 ;
V_9 = F_1 ( V_2 , V_10 ) ;
V_9 |= ( T_2 ) F_1 ( V_2 , V_11 ) << 32 ;
return V_9 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 == - 1 )
return;
if ( V_2 -> V_7 )
F_6 ( V_12 , V_2 -> V_8 + V_4 ) ;
else
F_7 ( V_12 , V_2 -> V_8 + V_4 ) ;
}
static T_3 F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
T_1 V_20 ;
F_11 ( & V_2 -> V_21 ) ;
V_20 = F_1 ( V_2 , V_22 ) ;
F_12 ( & V_2 -> V_21 ) ;
return sprintf ( V_17 , L_1 , V_20 ) ;
}
static T_3 F_13 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_4 V_23 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_12 , V_24 ;
V_24 = F_14 ( V_17 , 10 , & V_12 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_12 == 0 || V_12 >= 0xffffffff )
return - V_25 ;
F_11 ( & V_2 -> V_21 ) ;
F_5 ( V_2 , V_12 , V_22 ) ;
F_12 ( & V_2 -> V_21 ) ;
return V_23 ;
}
static const char *
F_15 ( struct V_1 * V_2 ,
T_1 V_26 )
{
T_1 V_27 = V_2 -> V_28 & V_26 ;
if ( F_16 ( V_27 ) != 1 )
return NULL ;
return V_2 -> V_29 [ F_17 ( V_27 ) - 1 ] ;
}
static int F_18 ( struct V_1 * V_2 ,
const char * V_30 )
{
T_1 V_31 ;
T_2 V_32 ;
T_1 V_33 ;
const char * V_34 ;
char V_35 [ 11 ] ;
V_31 = F_1 ( V_2 , V_36 ) ;
if ( ! ( V_31 & V_37 ) )
return 1 ;
V_32 = F_4 ( V_2 ) ;
V_33 = F_1 ( V_2 , V_6 ) ;
V_34 = F_15 ( V_2 , V_33 ) ;
if ( ! V_34 ) {
snprintf ( V_35 , sizeof( V_35 ) , L_2 , V_33 ) ;
V_34 = V_35 ;
}
F_19 ( L_3 ,
V_38 , V_30 , V_32 ,
V_31 & V_39 ? 'W' : 'R' ,
V_31 & V_40 ? L_4 : L_5 ,
V_34 ) ;
F_5 ( V_2 , V_41 , V_42 ) ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 , int V_45 )
{
int V_24 = 0 ;
struct V_1 * V_2 ;
T_1 V_31 ;
F_21 (gdev, &brcmstb_gisb_arb_device_list, next) {
V_31 = F_1 ( V_2 , V_36 ) ;
if ( ! ( V_31 & V_37 ) ) {
V_45 = 1 ;
goto V_46;
}
V_24 |= F_18 ( V_2 , L_6 ) ;
}
V_46:
return V_45 ? V_47 : V_48 ;
}
static T_5 F_22 ( int V_49 , void * V_50 )
{
F_18 ( V_50 , L_4 ) ;
return V_51 ;
}
static T_5 F_23 ( int V_49 , void * V_50 )
{
F_18 ( V_50 , L_7 ) ;
return V_51 ;
}
static int F_24 ( struct V_52 * V_53 , unsigned long V_54 ,
void * V_55 )
{
struct V_1 * V_2 ;
const char * V_30 = L_8 ;
if ( V_53 == & V_56 )
V_30 = L_9 ;
F_21 (gdev, &brcmstb_gisb_arb_device_list, next)
F_18 ( V_2 , V_30 ) ;
return V_57 ;
}
static int T_6 F_25 ( struct V_18 * V_19 )
{
struct V_58 * V_59 = V_19 -> V_14 . V_60 ;
struct V_1 * V_2 ;
const struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_65 , V_66 , V_67 ;
unsigned int V_68 , V_69 = 0 ;
int V_70 , V_71 , V_72 ;
V_64 = F_26 ( V_19 , V_73 , 0 ) ;
V_66 = F_27 ( V_19 , 0 ) ;
V_67 = F_27 ( V_19 , 1 ) ;
V_2 = F_28 ( & V_19 -> V_14 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
F_29 ( & V_2 -> V_21 ) ;
F_30 ( & V_2 -> V_76 ) ;
V_2 -> V_8 = F_31 ( & V_19 -> V_14 , V_64 ) ;
if ( F_32 ( V_2 -> V_8 ) )
return F_33 ( V_2 -> V_8 ) ;
V_62 = F_34 ( V_77 , V_59 ) ;
if ( ! V_62 ) {
F_35 ( L_10 ) ;
return - V_25 ;
}
V_2 -> V_5 = V_62 -> V_78 ;
V_2 -> V_7 = F_36 ( V_59 ) ;
V_65 = F_37 ( & V_19 -> V_14 , V_66 ,
F_22 , 0 , V_19 -> V_79 ,
V_2 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_37 ( & V_19 -> V_14 , V_67 ,
F_23 , 0 , V_19 -> V_79 ,
V_2 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( F_38 ( V_59 , L_11 ,
& V_2 -> V_28 ) )
V_2 -> V_28 = 0xffffffff ;
V_68 = F_39 ( V_59 ,
L_12 ) ;
if ( F_16 ( V_2 -> V_28 ) == V_68 ) {
V_71 = F_17 ( V_2 -> V_28 ) - 1 ;
V_72 = F_40 ( V_2 -> V_28 ) - 1 ;
for ( V_70 = V_71 ; V_70 < V_72 ; V_70 ++ ) {
if ( ! ( V_2 -> V_28 & F_41 ( V_70 ) ) )
continue;
F_42 ( V_59 ,
L_12 , V_69 ,
& V_2 -> V_29 [ V_70 ] ) ;
V_69 ++ ;
}
}
V_65 = F_43 ( & V_19 -> V_14 . V_80 , & V_81 ) ;
if ( V_65 )
return V_65 ;
F_44 ( V_19 , V_2 ) ;
F_45 ( & V_2 -> V_76 , & V_82 ) ;
#ifdef F_46
V_83 = F_20 ;
#endif
if ( F_47 ( & V_82 ) ) {
F_48 ( & V_56 ) ;
F_49 ( & V_84 ,
& V_85 ) ;
}
F_50 ( & V_19 -> V_14 , L_13 ,
V_2 -> V_8 , V_66 , V_67 ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
V_2 -> V_86 = F_1 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_52 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_5 ( V_2 , V_2 -> V_86 , V_22 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
return F_54 ( & V_87 ,
F_25 ) ;
}
