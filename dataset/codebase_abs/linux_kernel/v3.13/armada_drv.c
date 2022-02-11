static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
while ( F_3 ( & V_4 -> V_8 , & V_7 ) )
F_4 ( V_7 ) ;
}
void F_5 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
const struct V_6 * V_12 = V_7 ;
F_6 ( ! F_7 ( & V_4 -> V_8 , & V_12 ) ) ;
F_8 ( & V_4 -> V_5 ) ;
}
void F_9 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
unsigned long V_13 ;
F_10 ( & V_10 -> V_14 , V_13 ) ;
F_5 ( V_10 , V_7 ) ;
F_11 ( & V_10 -> V_14 , V_13 ) ;
}
static int F_12 ( struct V_9 * V_10 , unsigned long V_13 )
{
const struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_17 * V_18 [ F_13 ( V_4 -> V_19 ) ] ;
struct V_17 * V_20 = NULL ;
int V_21 , V_22 , V_23 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
for ( V_22 = V_23 = 0 ; ; V_22 ++ ) {
struct V_17 * V_24 = F_14 ( V_10 -> V_25 ,
V_26 , V_22 ) ;
if ( ! V_24 )
break;
if ( F_15 ( V_24 ) > V_27 )
V_20 = V_24 ;
else if ( V_23 < F_13 ( V_4 -> V_19 ) )
V_18 [ V_23 ++ ] = V_24 ;
else
return - V_28 ;
}
if ( ! V_18 [ 0 ] || ! V_20 )
return - V_29 ;
if ( ! F_16 ( V_10 -> V_10 , V_20 -> V_30 ,
F_15 ( V_20 ) , L_1 ) )
return - V_31 ;
V_4 = F_17 ( V_10 -> V_10 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 ) {
F_18 ( L_2 ) ;
return - V_33 ;
}
V_10 -> V_11 = V_4 ;
V_16 = F_19 ( V_10 -> V_25 ) ;
if ( ! V_16 )
return - V_29 ;
V_4 -> V_34 = (struct V_35 * ) V_16 -> V_36 ;
V_21 = V_4 -> V_34 -> V_37 ( V_4 , V_10 -> V_10 ) ;
if ( V_21 )
return V_21 ;
F_20 ( & V_4 -> V_5 , F_1 ) ;
F_21 ( V_4 -> V_8 ) ;
F_22 ( V_10 ) ;
V_10 -> V_38 . V_39 = 320 ;
V_10 -> V_38 . V_40 = 200 ;
V_10 -> V_38 . V_41 = 1920 ;
V_10 -> V_38 . V_42 = 2048 ;
V_10 -> V_38 . V_43 = 24 ;
V_10 -> V_38 . V_44 = & V_45 ;
F_23 ( & V_4 -> V_46 , V_20 -> V_30 , F_15 ( V_20 ) ) ;
for ( V_22 = 0 ; V_22 < F_13 ( V_4 -> V_19 ) ; V_22 ++ ) {
if ( ! V_18 [ V_22 ] )
break;
V_21 = F_24 ( V_10 , V_22 , V_18 [ V_22 ] ) ;
if ( V_21 )
goto V_47;
}
#ifdef F_25
V_21 = F_26 ( V_10 , & V_48 ) ;
if ( V_21 )
goto V_47;
#endif
V_21 = F_27 ( V_10 , V_22 ) ;
if ( V_21 )
goto V_47;
V_21 = F_28 ( V_10 ) ;
if ( V_21 )
goto V_47;
V_10 -> V_49 = 1 ;
V_21 = F_29 ( V_10 ) ;
if ( V_21 )
goto V_50;
F_30 ( V_10 ) ;
return 0 ;
V_50:
F_31 ( V_10 ) ;
V_47:
F_32 ( V_10 ) ;
F_33 ( & V_4 -> V_46 ) ;
F_34 ( & V_4 -> V_5 ) ;
return V_21 ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
F_31 ( V_10 ) ;
F_32 ( V_10 ) ;
F_33 ( & V_4 -> V_46 ) ;
F_34 ( & V_4 -> V_5 ) ;
V_10 -> V_11 = NULL ;
return 0 ;
}
void F_38 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
unsigned long V_13 ;
F_10 ( & V_19 -> V_54 , V_13 ) ;
if ( F_39 ( & V_53 -> V_55 ) ) {
F_40 ( & V_53 -> V_55 , & V_19 -> V_56 ) ;
F_41 ( V_19 -> V_57 . V_10 , V_19 -> V_58 ) ;
}
F_11 ( & V_19 -> V_54 , V_13 ) ;
}
void F_42 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
if ( ! F_39 ( & V_53 -> V_55 ) ) {
F_43 ( & V_53 -> V_55 ) ;
F_44 ( V_19 -> V_57 . V_10 , V_19 -> V_58 ) ;
}
}
void F_45 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
unsigned long V_13 ;
F_10 ( & V_19 -> V_54 , V_13 ) ;
F_42 ( V_19 , V_53 ) ;
F_11 ( & V_19 -> V_54 , V_13 ) ;
}
static int F_46 ( struct V_9 * V_10 , int V_57 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_47 ( V_4 -> V_19 [ V_57 ] , V_59 ) ;
return 0 ;
}
static void F_48 ( struct V_9 * V_10 , int V_57 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_49 ( V_4 -> V_19 [ V_57 ] , V_59 ) ;
}
static T_1 F_50 ( int V_60 , void * V_61 )
{
struct V_9 * V_10 = V_61 ;
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_51 * V_19 = V_4 -> V_19 [ 0 ] ;
T_2 V_62 , V_63 = F_51 ( V_19 -> V_64 + V_65 ) ;
T_1 V_66 = V_67 ;
F_52 ( 0 , V_19 -> V_64 + V_65 ) ;
V_62 = V_63 & V_19 -> V_68 ;
if ( V_62 & ( V_69 | V_70 | V_71 ) ) {
F_53 ( V_19 , V_63 ) ;
V_66 = V_72 ;
}
return V_66 ;
}
static int F_54 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_51 * V_19 = V_4 -> V_19 [ 0 ] ;
F_55 ( & V_10 -> V_73 ) ;
F_52 ( V_19 -> V_68 , V_19 -> V_64 + V_74 ) ;
F_56 ( 0 , V_19 -> V_64 + V_65 ) ;
F_57 ( & V_10 -> V_73 ) ;
return 0 ;
}
static void F_58 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_51 * V_19 = V_4 -> V_19 [ 0 ] ;
F_56 ( 0 , V_19 -> V_64 + V_74 ) ;
}
static void F_59 ( struct V_9 * V_10 )
{
F_60 ( V_10 ) ;
}
static int F_61 ( struct V_75 * V_76 )
{
return F_62 ( & V_77 , V_76 ) ;
}
static int F_63 ( struct V_75 * V_76 )
{
F_64 ( & V_77 , V_76 ) ;
return 0 ;
}
static int T_3 F_65 ( void )
{
V_77 . V_78 = F_66 ( V_79 ) ;
return F_67 ( & V_80 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_80 ) ;
}
