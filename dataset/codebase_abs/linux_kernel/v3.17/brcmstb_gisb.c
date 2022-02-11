static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_2 V_10 ;
F_4 ( & V_9 -> V_11 ) ;
V_10 = F_5 ( V_9 -> V_12 + V_13 ) ;
F_6 ( & V_9 -> V_11 ) ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 , V_16 ;
V_16 = F_8 ( V_5 , 10 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 == 0 || V_15 >= 0xffffffff )
return - V_17 ;
F_4 ( & V_9 -> V_11 ) ;
F_9 ( V_15 , V_9 -> V_12 + V_13 ) ;
F_6 ( & V_9 -> V_11 ) ;
return V_14 ;
}
static const char *
F_10 ( struct V_8 * V_9 ,
T_2 V_18 )
{
T_2 V_19 = V_9 -> V_20 & V_18 ;
if ( F_11 ( V_19 ) != 1 )
return NULL ;
return V_9 -> V_21 [ F_12 ( V_19 ) - 1 ] ;
}
static int F_13 ( struct V_8 * V_9 ,
const char * V_22 )
{
T_2 V_23 ;
unsigned long V_24 ;
T_2 V_25 ;
const char * V_26 ;
char V_27 [ 11 ] ;
V_23 = F_5 ( V_9 -> V_12 + V_28 ) ;
if ( ! ( V_23 & V_29 ) )
return 1 ;
V_24 = F_5 ( V_9 -> V_12 + V_30 ) & 0xffffffff ;
#if ( F_14 ( V_31 ) )
V_24 |= ( V_32 ) F_5 ( V_9 -> V_12 + V_33 ) << 32 ;
#endif
V_25 = F_5 ( V_9 -> V_12 + V_34 ) ;
V_26 = F_10 ( V_9 , V_25 ) ;
if ( ! V_26 ) {
snprintf ( V_27 , sizeof( V_27 ) , L_2 , V_25 ) ;
V_26 = V_27 ;
}
F_15 ( L_3 ,
V_35 , V_22 , V_24 ,
V_23 & V_36 ? 'W' : 'R' ,
V_23 & V_37 ? L_4 : L_5 ,
V_26 ) ;
F_9 ( V_38 , V_9 -> V_12 + V_39 ) ;
return 0 ;
}
static int F_16 ( unsigned long V_40 , unsigned int V_41 ,
struct V_42 * V_43 )
{
int V_16 = 0 ;
struct V_8 * V_9 ;
F_17 (gdev, &brcmstb_gisb_arb_device_list, next)
V_16 |= F_13 ( V_9 , L_6 ) ;
if ( V_41 & ( 1 << 10 ) )
V_43 -> V_44 += 4 ;
return V_16 ;
}
void T_4 F_18 ( void )
{
F_19 ( 22 , F_16 , V_45 , 0 ,
L_7 ) ;
}
static T_5 F_20 ( int V_46 , void * V_47 )
{
F_13 ( V_47 , L_4 ) ;
return V_48 ;
}
static T_5 F_21 ( int V_46 , void * V_47 )
{
F_13 ( V_47 , L_8 ) ;
return V_48 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_49 * V_50 = V_7 -> V_2 . V_51 ;
struct V_8 * V_9 ;
struct V_52 * V_53 ;
int V_54 , V_55 , V_56 ;
unsigned int V_57 , V_58 = 0 ;
int V_59 , V_60 , V_61 ;
V_53 = F_23 ( V_7 , V_62 , 0 ) ;
V_55 = F_24 ( V_7 , 0 ) ;
V_56 = F_24 ( V_7 , 1 ) ;
V_9 = F_25 ( & V_7 -> V_2 , sizeof( * V_9 ) , V_63 ) ;
if ( ! V_9 )
return - V_64 ;
F_26 ( & V_9 -> V_11 ) ;
F_27 ( & V_9 -> V_65 ) ;
V_9 -> V_12 = F_28 ( & V_7 -> V_2 , V_53 ) ;
if ( F_29 ( V_9 -> V_12 ) )
return F_30 ( V_9 -> V_12 ) ;
V_54 = F_31 ( & V_7 -> V_2 , V_55 ,
F_20 , 0 , V_7 -> V_66 ,
V_9 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_31 ( & V_7 -> V_2 , V_56 ,
F_21 , 0 , V_7 -> V_66 ,
V_9 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_32 ( V_50 , L_9 ,
& V_9 -> V_20 ) )
V_9 -> V_20 = 0xffffffff ;
V_57 = F_33 ( V_50 ,
L_10 ) ;
if ( F_11 ( V_9 -> V_20 ) == V_57 ) {
V_60 = F_12 ( V_9 -> V_20 ) - 1 ;
V_61 = F_34 ( V_9 -> V_20 ) - 1 ;
for ( V_59 = V_60 ; V_59 < V_61 ; V_59 ++ ) {
if ( ! ( V_9 -> V_20 & F_35 ( V_59 ) ) )
continue;
F_36 ( V_50 ,
L_10 , V_58 ,
& V_9 -> V_21 [ V_59 ] ) ;
V_58 ++ ;
}
}
V_54 = F_37 ( & V_7 -> V_2 . V_67 , & V_68 ) ;
if ( V_54 )
return V_54 ;
F_38 ( V_7 , V_9 ) ;
F_39 ( & V_9 -> V_65 , & V_69 ) ;
F_40 ( & V_7 -> V_2 , L_11 ,
V_9 -> V_12 , V_55 , V_56 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_70 ) ;
}
