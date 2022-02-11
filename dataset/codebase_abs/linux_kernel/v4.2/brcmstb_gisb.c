static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 == - 1 )
return 1 ;
if ( V_2 -> V_6 )
return F_2 ( V_2 -> V_7 + V_4 ) ;
else
return F_3 ( V_2 -> V_7 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_8 , int V_3 )
{
int V_4 = V_2 -> V_5 [ V_3 ] ;
if ( V_4 == - 1 )
return;
if ( V_2 -> V_6 )
F_5 ( V_8 , V_2 -> V_7 + V_3 ) ;
else
F_6 ( V_8 , V_2 -> V_7 + V_3 ) ;
}
static T_2 F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
T_1 V_16 ;
F_10 ( & V_2 -> V_17 ) ;
V_16 = F_1 ( V_2 , V_18 ) ;
F_11 ( & V_2 -> V_17 ) ;
return sprintf ( V_13 , L_1 , V_16 ) ;
}
static T_2 F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_19 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_8 , V_20 ;
V_20 = F_13 ( V_13 , 10 , & V_8 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_8 == 0 || V_8 >= 0xffffffff )
return - V_21 ;
F_10 ( & V_2 -> V_17 ) ;
F_4 ( V_2 , V_8 , V_18 ) ;
F_11 ( & V_2 -> V_17 ) ;
return V_19 ;
}
static const char *
F_14 ( struct V_1 * V_2 ,
T_1 V_22 )
{
T_1 V_23 = V_2 -> V_24 & V_22 ;
if ( F_15 ( V_23 ) != 1 )
return NULL ;
return V_2 -> V_25 [ F_16 ( V_23 ) - 1 ] ;
}
static int F_17 ( struct V_1 * V_2 ,
const char * V_26 )
{
T_1 V_27 ;
unsigned long V_28 ;
T_1 V_29 ;
const char * V_30 ;
char V_31 [ 11 ] ;
V_27 = F_1 ( V_2 , V_32 ) ;
if ( ! ( V_27 & V_33 ) )
return 1 ;
V_28 = F_1 ( V_2 , V_34 ) & 0xffffffff ;
#if ( F_18 ( V_35 ) )
V_28 |= ( V_36 ) F_1 ( V_2 , V_37 ) << 32 ;
#endif
V_29 = F_1 ( V_2 , V_38 ) ;
V_30 = F_14 ( V_2 , V_29 ) ;
if ( ! V_30 ) {
snprintf ( V_31 , sizeof( V_31 ) , L_2 , V_29 ) ;
V_30 = V_31 ;
}
F_19 ( L_3 ,
V_39 , V_26 , V_28 ,
V_27 & V_40 ? 'W' : 'R' ,
V_27 & V_41 ? L_4 : L_5 ,
V_30 ) ;
F_4 ( V_2 , V_42 , V_43 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_44 , unsigned int V_45 ,
struct V_46 * V_47 )
{
int V_20 = 0 ;
struct V_1 * V_2 ;
F_21 (gdev, &brcmstb_gisb_arb_device_list, next)
V_20 |= F_17 ( V_2 , L_6 ) ;
if ( V_45 & ( 1 << 10 ) )
V_47 -> V_48 += 4 ;
return V_20 ;
}
static T_4 F_22 ( int V_49 , void * V_50 )
{
F_17 ( V_50 , L_4 ) ;
return V_51 ;
}
static T_4 F_23 ( int V_49 , void * V_50 )
{
F_17 ( V_50 , L_7 ) ;
return V_51 ;
}
static int T_5 F_24 ( struct V_14 * V_15 )
{
struct V_52 * V_53 = V_15 -> V_10 . V_54 ;
struct V_1 * V_2 ;
const struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_59 , V_60 , V_61 ;
unsigned int V_62 , V_63 = 0 ;
int V_64 , V_65 , V_66 ;
V_58 = F_25 ( V_15 , V_67 , 0 ) ;
V_60 = F_26 ( V_15 , 0 ) ;
V_61 = F_26 ( V_15 , 1 ) ;
V_2 = F_27 ( & V_15 -> V_10 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
F_28 ( & V_2 -> V_17 ) ;
F_29 ( & V_2 -> V_70 ) ;
V_2 -> V_7 = F_30 ( & V_15 -> V_10 , V_58 ) ;
if ( F_31 ( V_2 -> V_7 ) )
return F_32 ( V_2 -> V_7 ) ;
V_56 = F_33 ( V_71 , V_53 ) ;
if ( ! V_56 ) {
F_34 ( L_8 ) ;
return - V_21 ;
}
V_2 -> V_5 = V_56 -> V_72 ;
V_2 -> V_6 = F_35 ( V_53 ) ;
V_59 = F_36 ( & V_15 -> V_10 , V_60 ,
F_22 , 0 , V_15 -> V_73 ,
V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_36 ( & V_15 -> V_10 , V_61 ,
F_23 , 0 , V_15 -> V_73 ,
V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( F_37 ( V_53 , L_9 ,
& V_2 -> V_24 ) )
V_2 -> V_24 = 0xffffffff ;
V_62 = F_38 ( V_53 ,
L_10 ) ;
if ( F_15 ( V_2 -> V_24 ) == V_62 ) {
V_65 = F_16 ( V_2 -> V_24 ) - 1 ;
V_66 = F_39 ( V_2 -> V_24 ) - 1 ;
for ( V_64 = V_65 ; V_64 < V_66 ; V_64 ++ ) {
if ( ! ( V_2 -> V_24 & F_40 ( V_64 ) ) )
continue;
F_41 ( V_53 ,
L_10 , V_63 ,
& V_2 -> V_25 [ V_64 ] ) ;
V_63 ++ ;
}
}
V_59 = F_42 ( & V_15 -> V_10 . V_74 , & V_75 ) ;
if ( V_59 )
return V_59 ;
F_43 ( V_15 , V_2 ) ;
F_44 ( & V_2 -> V_70 , & V_76 ) ;
#ifdef F_45
F_46 ( 22 , F_20 , V_77 , 0 ,
L_11 ) ;
#endif
F_47 ( & V_15 -> V_10 , L_12 ,
V_2 -> V_7 , V_60 , V_61 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
V_2 -> V_78 = F_1 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_4 ( V_2 , V_2 -> V_78 , V_18 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_79 ,
F_24 ) ;
}
