static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 == - 1 )
return 1 ;
return F_2 ( V_2 -> V_6 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_7 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 == - 1 )
return;
F_4 ( V_7 , V_2 -> V_6 + V_3 ) ;
}
static T_2 F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
T_1 V_15 ;
F_8 ( & V_2 -> V_16 ) ;
V_15 = F_1 ( V_2 , V_17 ) ;
F_9 ( & V_2 -> V_16 ) ;
return sprintf ( V_12 , L_1 , V_15 ) ;
}
static T_2 F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_3 V_18 )
{
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
int V_7 , V_19 ;
V_19 = F_11 ( V_12 , 10 , & V_7 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_7 == 0 || V_7 >= 0xffffffff )
return - V_20 ;
F_8 ( & V_2 -> V_16 ) ;
F_3 ( V_2 , V_7 , V_17 ) ;
F_9 ( & V_2 -> V_16 ) ;
return V_18 ;
}
static const char *
F_12 ( struct V_1 * V_2 ,
T_1 V_21 )
{
T_1 V_22 = V_2 -> V_23 & V_21 ;
if ( F_13 ( V_22 ) != 1 )
return NULL ;
return V_2 -> V_24 [ F_14 ( V_22 ) - 1 ] ;
}
static int F_15 ( struct V_1 * V_2 ,
const char * V_25 )
{
T_1 V_26 ;
unsigned long V_27 ;
T_1 V_28 ;
const char * V_29 ;
char V_30 [ 11 ] ;
V_26 = F_1 ( V_2 , V_31 ) ;
if ( ! ( V_26 & V_32 ) )
return 1 ;
V_27 = F_1 ( V_2 , V_33 ) & 0xffffffff ;
#if ( F_16 ( V_34 ) )
V_27 |= ( V_35 ) F_1 ( V_2 , V_36 ) << 32 ;
#endif
V_28 = F_1 ( V_2 , V_37 ) ;
V_29 = F_12 ( V_2 , V_28 ) ;
if ( ! V_29 ) {
snprintf ( V_30 , sizeof( V_30 ) , L_2 , V_28 ) ;
V_29 = V_30 ;
}
F_17 ( L_3 ,
V_38 , V_25 , V_27 ,
V_26 & V_39 ? 'W' : 'R' ,
V_26 & V_40 ? L_4 : L_5 ,
V_29 ) ;
F_3 ( V_2 , V_41 , V_42 ) ;
return 0 ;
}
static int F_18 ( unsigned long V_43 , unsigned int V_44 ,
struct V_45 * V_46 )
{
int V_19 = 0 ;
struct V_1 * V_2 ;
F_19 (gdev, &brcmstb_gisb_arb_device_list, next)
V_19 |= F_15 ( V_2 , L_6 ) ;
if ( V_44 & ( 1 << 10 ) )
V_46 -> V_47 += 4 ;
return V_19 ;
}
static T_4 F_20 ( int V_48 , void * V_49 )
{
F_15 ( V_49 , L_4 ) ;
return V_50 ;
}
static T_4 F_21 ( int V_48 , void * V_49 )
{
F_15 ( V_49 , L_7 ) ;
return V_50 ;
}
static int T_5 F_22 ( struct V_13 * V_14 )
{
struct V_51 * V_52 = V_14 -> V_9 . V_53 ;
struct V_1 * V_2 ;
const struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_58 , V_59 , V_60 ;
unsigned int V_61 , V_62 = 0 ;
int V_63 , V_64 , V_65 ;
V_57 = F_23 ( V_14 , V_66 , 0 ) ;
V_59 = F_24 ( V_14 , 0 ) ;
V_60 = F_24 ( V_14 , 1 ) ;
V_2 = F_25 ( & V_14 -> V_9 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
F_26 ( & V_2 -> V_16 ) ;
F_27 ( & V_2 -> V_69 ) ;
V_2 -> V_6 = F_28 ( & V_14 -> V_9 , V_57 ) ;
if ( F_29 ( V_2 -> V_6 ) )
return F_30 ( V_2 -> V_6 ) ;
V_55 = F_31 ( V_70 , V_52 ) ;
if ( ! V_55 ) {
F_32 ( L_8 ) ;
return - V_20 ;
}
V_2 -> V_5 = V_55 -> V_71 ;
V_58 = F_33 ( & V_14 -> V_9 , V_59 ,
F_20 , 0 , V_14 -> V_72 ,
V_2 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_33 ( & V_14 -> V_9 , V_60 ,
F_21 , 0 , V_14 -> V_72 ,
V_2 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( F_34 ( V_52 , L_9 ,
& V_2 -> V_23 ) )
V_2 -> V_23 = 0xffffffff ;
V_61 = F_35 ( V_52 ,
L_10 ) ;
if ( F_13 ( V_2 -> V_23 ) == V_61 ) {
V_64 = F_14 ( V_2 -> V_23 ) - 1 ;
V_65 = F_36 ( V_2 -> V_23 ) - 1 ;
for ( V_63 = V_64 ; V_63 < V_65 ; V_63 ++ ) {
if ( ! ( V_2 -> V_23 & F_37 ( V_63 ) ) )
continue;
F_38 ( V_52 ,
L_10 , V_62 ,
& V_2 -> V_24 [ V_63 ] ) ;
V_62 ++ ;
}
}
V_58 = F_39 ( & V_14 -> V_9 . V_73 , & V_74 ) ;
if ( V_58 )
return V_58 ;
F_40 ( V_14 , V_2 ) ;
F_41 ( & V_2 -> V_69 , & V_75 ) ;
#ifdef F_42
F_43 ( 22 , F_18 , V_76 , 0 ,
L_11 ) ;
#endif
F_44 ( & V_14 -> V_9 , L_12 ,
V_2 -> V_6 , V_59 , V_60 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
V_2 -> V_77 = F_1 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
F_3 ( V_2 , V_2 -> V_77 , V_17 ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_78 ,
F_22 ) ;
}
