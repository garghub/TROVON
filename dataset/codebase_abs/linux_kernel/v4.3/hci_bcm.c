static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
if ( V_3 > 3000000 ) {
struct V_10 clock ;
clock . type = V_11 ;
F_2 ( L_1 , V_5 -> V_12 , clock . type ) ;
V_7 = F_3 ( V_5 , 0xfc45 , 1 , & clock , V_13 ) ;
if ( F_4 ( V_7 ) ) {
int V_14 = F_5 ( V_7 ) ;
F_6 ( L_2 ,
V_5 -> V_12 , V_14 ) ;
return V_14 ;
}
F_7 ( V_7 ) ;
}
F_2 ( L_3 , V_5 -> V_12 , V_3 ) ;
V_9 . V_15 = F_8 ( 0 ) ;
V_9 . V_16 = F_9 ( V_3 ) ;
V_7 = F_3 ( V_5 , 0xfc18 , sizeof( V_9 ) , & V_9 ,
V_13 ) ;
if ( F_4 ( V_7 ) ) {
int V_14 = F_5 ( V_7 ) ;
F_6 ( L_4 ,
V_5 -> V_12 , V_14 ) ;
return V_14 ;
}
F_7 ( V_7 ) ;
return 0 ;
}
static bool F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_11 (p, &bcm_device_list) {
struct V_17 * V_21 = F_12 ( V_20 , struct V_17 , V_22 ) ;
if ( V_18 == V_21 )
return true ;
}
return false ;
}
static int F_13 ( struct V_17 * V_21 , bool V_23 )
{
if ( V_23 && ! F_4 ( V_21 -> V_24 ) && ! V_21 -> V_25 )
F_14 ( V_21 -> V_24 ) ;
F_15 ( V_21 -> V_26 , V_23 ) ;
F_15 ( V_21 -> V_27 , V_23 ) ;
if ( ! V_23 && ! F_4 ( V_21 -> V_24 ) && V_21 -> V_25 )
F_16 ( V_21 -> V_24 ) ;
V_21 -> V_25 = V_23 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_19 * V_20 ;
F_2 ( L_5 , V_2 ) ;
V_29 = F_18 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
F_19 ( & V_29 -> V_32 ) ;
V_2 -> V_33 = V_29 ;
F_20 ( & V_34 ) ;
F_11 (p, &bcm_device_list) {
struct V_17 * V_21 = F_12 ( V_20 , struct V_17 , V_22 ) ;
if ( V_2 -> V_35 -> V_21 -> V_36 == V_21 -> V_37 -> V_21 . V_36 ) {
V_29 -> V_21 = V_21 ;
V_2 -> V_38 = V_21 -> V_38 ;
#ifdef F_21
V_21 -> V_2 = V_2 ;
#endif
break;
}
}
if ( V_29 -> V_21 )
F_13 ( V_29 -> V_21 , true ) ;
F_22 ( & V_34 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_33 ;
F_2 ( L_5 , V_2 ) ;
F_20 ( & V_34 ) ;
if ( F_10 ( V_29 -> V_21 ) ) {
F_13 ( V_29 -> V_21 , false ) ;
#ifdef F_21
V_29 -> V_21 -> V_2 = NULL ;
#endif
}
F_22 ( & V_34 ) ;
F_24 ( & V_29 -> V_32 ) ;
F_7 ( V_29 -> V_39 ) ;
F_25 ( V_29 ) ;
V_2 -> V_33 = NULL ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_33 ;
F_2 ( L_5 , V_2 ) ;
F_24 ( & V_29 -> V_32 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
char V_40 [ 64 ] ;
const struct V_41 * V_42 ;
unsigned int V_3 ;
int V_14 ;
F_2 ( L_5 , V_2 ) ;
V_2 -> V_5 -> V_43 = V_44 ;
V_14 = F_28 ( V_2 -> V_5 , V_40 , sizeof( V_40 ) ) ;
if ( V_14 )
return V_14 ;
V_14 = F_29 ( & V_42 , V_40 , & V_2 -> V_5 -> V_21 ) ;
if ( V_14 < 0 ) {
F_30 ( L_6 , V_2 -> V_5 -> V_12 , V_40 ) ;
return 0 ;
}
V_14 = F_31 ( V_2 -> V_5 , V_42 ) ;
if ( V_14 ) {
F_30 ( L_7 , V_2 -> V_5 -> V_12 , V_14 ) ;
goto V_45;
}
if ( V_2 -> V_38 )
V_3 = V_2 -> V_38 ;
else if ( V_2 -> V_46 -> V_38 )
V_3 = V_2 -> V_46 -> V_38 ;
else
V_3 = 0 ;
if ( V_3 )
F_32 ( V_2 , V_3 ) ;
if ( V_2 -> V_47 )
V_3 = V_2 -> V_47 ;
else if ( V_2 -> V_46 -> V_47 )
V_3 = V_2 -> V_46 -> V_47 ;
else
V_3 = 0 ;
if ( V_3 ) {
V_14 = F_1 ( V_2 , V_3 ) ;
if ( ! V_14 )
F_32 ( V_2 , V_3 ) ;
}
V_45:
F_33 ( V_42 ) ;
V_14 = F_34 ( V_2 -> V_5 ) ;
return V_14 ;
}
static int F_35 ( struct V_1 * V_2 , const void * V_48 , int V_49 )
{
struct V_28 * V_29 = V_2 -> V_33 ;
if ( ! F_36 ( V_50 , & V_2 -> V_51 ) )
return - V_52 ;
V_29 -> V_39 = F_37 ( V_2 -> V_5 , V_29 -> V_39 , V_48 , V_49 ,
V_53 , F_38 ( V_53 ) ) ;
if ( F_4 ( V_29 -> V_39 ) ) {
int V_14 = F_5 ( V_29 -> V_39 ) ;
F_6 ( L_8 , V_2 -> V_5 -> V_12 , V_14 ) ;
V_29 -> V_39 = NULL ;
return V_14 ;
}
return V_49 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_28 * V_29 = V_2 -> V_33 ;
F_2 ( L_9 , V_2 , V_7 ) ;
memcpy ( F_40 ( V_7 , 1 ) , & F_41 ( V_7 ) -> V_54 , 1 ) ;
F_42 ( & V_29 -> V_32 , V_7 ) ;
return 0 ;
}
static struct V_6 * F_43 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_33 ;
return F_44 ( & V_29 -> V_32 ) ;
}
static int F_45 ( struct V_18 * V_21 )
{
struct V_17 * V_55 = F_46 ( F_47 ( V_21 ) ) ;
F_2 ( L_10 , V_55 , V_55 -> V_56 ) ;
F_20 ( & V_34 ) ;
if ( ! V_55 -> V_2 )
goto V_57;
if ( ! V_55 -> V_56 ) {
F_48 ( V_55 -> V_2 , true ) ;
V_55 -> V_56 = true ;
}
if ( V_55 -> V_27 ) {
F_15 ( V_55 -> V_27 , false ) ;
F_2 ( L_11 ) ;
F_49 ( 15 ) ;
}
V_57:
F_22 ( & V_34 ) ;
return 0 ;
}
static int F_50 ( struct V_18 * V_21 )
{
struct V_17 * V_55 = F_46 ( F_47 ( V_21 ) ) ;
F_2 ( L_12 , V_55 , V_55 -> V_56 ) ;
F_20 ( & V_34 ) ;
if ( ! V_55 -> V_2 )
goto V_57;
if ( V_55 -> V_27 ) {
F_15 ( V_55 -> V_27 , true ) ;
F_2 ( L_13 ) ;
F_49 ( 15 ) ;
}
if ( V_55 -> V_56 ) {
V_55 -> V_56 = false ;
F_48 ( V_55 -> V_2 , false ) ;
}
V_57:
F_22 ( & V_34 ) ;
return 0 ;
}
static int F_51 ( struct V_58 * V_59 , void * V_48 )
{
struct V_17 * V_21 = V_48 ;
if ( V_59 -> type == V_60 ) {
struct V_61 * V_62 ;
V_62 = & V_59 -> V_48 . V_63 ;
if ( V_62 -> type == V_64 )
V_21 -> V_38 = V_62 -> V_65 ;
}
return 1 ;
}
static int F_52 ( struct V_17 * V_21 )
{
struct V_66 * V_37 = V_21 -> V_37 ;
const struct V_67 * V_68 ;
struct V_69 * V_70 ;
F_53 ( V_71 ) ;
int V_72 ;
V_68 = F_54 ( V_37 -> V_21 . V_73 -> V_74 , & V_37 -> V_21 ) ;
if ( ! V_68 )
return - V_75 ;
V_21 -> V_12 = F_55 ( & V_37 -> V_21 ) ;
V_72 = F_56 ( F_57 ( & V_37 -> V_21 ) ,
V_76 ) ;
if ( V_72 )
return V_72 ;
V_21 -> V_24 = F_58 ( & V_37 -> V_21 , NULL ) ;
V_21 -> V_27 = F_59 ( & V_37 -> V_21 ,
L_14 ,
V_77 ) ;
if ( F_4 ( V_21 -> V_27 ) )
return F_5 ( V_21 -> V_27 ) ;
V_21 -> V_26 = F_59 ( & V_37 -> V_21 , L_15 ,
V_77 ) ;
if ( F_4 ( V_21 -> V_26 ) )
return F_5 ( V_21 -> V_26 ) ;
if ( ( ! V_21 -> V_27 && ! V_21 -> V_26 ) || ! V_21 -> V_12 ) {
F_60 ( & V_37 -> V_21 , L_16 ) ;
return - V_78 ;
}
V_70 = F_57 ( & V_21 -> V_37 -> V_21 ) ;
if ( ! V_70 )
return 0 ;
F_61 ( V_70 , & V_71 , F_51 , V_21 ) ;
return 0 ;
}
static int F_52 ( struct V_17 * V_21 )
{
return - V_78 ;
}
static int F_62 ( struct V_66 * V_37 )
{
struct V_17 * V_21 ;
struct V_67 * V_79 = V_37 -> V_21 . V_80 ;
int V_72 ;
V_21 = F_63 ( & V_37 -> V_21 , sizeof( * V_21 ) , V_30 ) ;
if ( ! V_21 )
return - V_31 ;
V_21 -> V_37 = V_37 ;
if ( F_64 ( & V_37 -> V_21 ) ) {
V_72 = F_52 ( V_21 ) ;
if ( V_72 )
return V_72 ;
} else if ( V_79 ) {
V_21 -> V_12 = V_79 -> V_68 ;
} else {
return - V_75 ;
}
F_65 ( V_37 , V_21 ) ;
F_66 ( & V_37 -> V_21 , L_17 , V_21 -> V_12 ) ;
F_20 ( & V_34 ) ;
F_67 ( & V_21 -> V_22 , & V_81 ) ;
F_22 ( & V_34 ) ;
F_13 ( V_21 , false ) ;
return 0 ;
}
static int F_68 ( struct V_66 * V_37 )
{
struct V_17 * V_21 = F_46 ( V_37 ) ;
F_20 ( & V_34 ) ;
F_69 ( & V_21 -> V_22 ) ;
F_22 ( & V_34 ) ;
F_70 ( F_57 ( & V_37 -> V_21 ) ) ;
F_66 ( & V_37 -> V_21 , L_18 , V_21 -> V_12 ) ;
return 0 ;
}
int T_1 F_71 ( void )
{
F_72 ( & V_82 ) ;
return F_73 ( & V_83 ) ;
}
int T_2 F_74 ( void )
{
F_75 ( & V_82 ) ;
return F_76 ( & V_83 ) ;
}
