static void F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_6 ( V_2 , V_7 , 0 ) ;
V_2 -> V_4 -> V_8 ( V_2 , 0 ) ;
V_2 -> V_4 -> V_6 ( V_2 , V_7 , 1 ) ;
V_2 -> V_4 -> V_8 ( V_2 , 1 ) ;
}
static void F_2 ( struct V_1 * V_2 , unsigned char V_3 )
{
V_2 -> V_4 -> V_6 ( V_2 , V_9 , 1 ) ;
F_1 ( V_2 , V_3 ) ;
V_2 -> V_4 -> V_6 ( V_2 , V_9 , 0 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned char * V_11 = ( unsigned char V_12 * ) V_2 -> V_13 -> V_14 ;
F_2 ( V_2 , V_15 ) ;
for ( V_10 = 0 ; V_10 < ( V_16 * V_17 / 8 ) ; V_10 ++ ) {
F_1 ( V_2 , * ( V_11 ++ ) ) ;
}
F_2 ( V_2 , V_18 ) ;
F_2 ( V_2 , V_19 ) ;
}
static void F_4 ( struct V_20 * V_13 ,
struct V_21 * V_22 )
{
F_3 ( V_13 -> V_2 ) ;
}
static void F_5 ( struct V_20 * V_13 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_6 ( V_13 , V_24 ) ;
F_3 ( V_2 ) ;
}
static void F_7 ( struct V_20 * V_13 ,
const struct V_25 * V_26 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_8 ( V_13 , V_26 ) ;
F_3 ( V_2 ) ;
}
static void F_9 ( struct V_20 * V_13 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_10 ( V_13 , V_28 ) ;
F_3 ( V_2 ) ;
}
static T_1 F_11 ( struct V_20 * V_13 , const char T_2 * V_11 ,
T_3 V_29 , T_4 * V_30 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_31 = * V_30 ;
void * V_32 ;
int V_33 = 0 ;
unsigned long V_34 ;
if ( V_13 -> V_35 != V_36 )
return - V_37 ;
V_34 = V_13 -> V_38 . V_39 ;
if ( V_31 > V_34 )
return - V_40 ;
if ( V_29 > V_34 ) {
V_33 = - V_40 ;
V_29 = V_34 ;
}
if ( V_29 + V_31 > V_34 ) {
if ( ! V_33 )
V_33 = - V_41 ;
V_29 = V_34 - V_31 ;
}
V_32 = ( void V_12 * ) ( V_13 -> V_14 + V_31 ) ;
if ( F_12 ( V_32 , V_11 , V_29 ) )
V_33 = - V_42 ;
if ( ! V_33 )
* V_30 += V_29 ;
F_3 ( V_2 ) ;
return ( V_33 ) ? V_33 : V_29 ;
}
static int T_5 F_13 ( struct V_43 * V_44 )
{
struct V_20 * V_13 ;
struct V_45 * V_4 ;
int V_46 = - V_47 ;
int V_48 ;
unsigned char * V_49 ;
struct V_1 * V_2 ;
V_4 = V_44 -> V_44 . V_50 ;
if ( ! V_4 )
return - V_51 ;
if ( ! F_14 ( V_4 -> V_52 ) )
return - V_53 ;
V_48 = ( V_16 * V_17 ) / 8 ;
V_49 = F_15 ( V_48 ) ;
if ( ! V_49 )
goto V_54;
V_13 = F_16 ( sizeof( struct V_1 ) , & V_44 -> V_44 ) ;
if ( ! V_13 )
goto V_55;
V_13 -> V_14 = ( char V_12 V_56 * ) V_49 ;
V_13 -> V_57 = & V_58 ;
V_13 -> V_59 = V_60 ;
V_13 -> V_38 = V_61 ;
V_13 -> V_38 . V_39 = V_48 ;
V_2 = V_13 -> V_2 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_62 = F_2 ;
V_2 -> V_63 = F_1 ;
V_13 -> V_64 = V_65 | V_66 ;
V_13 -> V_67 = & V_68 ;
F_17 ( V_13 ) ;
V_46 = F_18 ( V_13 ) ;
if ( V_46 < 0 )
goto V_69;
F_19 ( V_44 , V_13 ) ;
F_20 ( V_70
L_1 ,
V_13 -> V_71 , V_48 >> 10 ) ;
V_46 = V_2 -> V_4 -> V_72 ( V_2 ) ;
if ( V_46 < 0 )
goto V_69;
return 0 ;
V_69:
F_21 ( V_13 ) ;
V_55:
F_22 ( V_49 ) ;
V_54:
F_23 ( V_4 -> V_52 ) ;
return V_46 ;
}
static int T_6 F_24 ( struct V_43 * V_44 )
{
struct V_20 * V_13 = F_25 ( V_44 ) ;
if ( V_13 ) {
struct V_1 * V_2 = V_13 -> V_2 ;
F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
F_22 ( ( void V_12 * ) V_13 -> V_14 ) ;
if ( V_2 -> V_4 -> remove )
V_2 -> V_4 -> remove ( V_2 ) ;
F_23 ( V_2 -> V_4 -> V_52 ) ;
F_21 ( V_13 ) ;
}
return 0 ;
}
static int T_7 F_28 ( void )
{
return F_29 ( & V_73 ) ;
}
static void T_8 F_30 ( void )
{
F_31 ( & V_73 ) ;
}
