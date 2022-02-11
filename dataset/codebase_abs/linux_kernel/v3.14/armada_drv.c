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
F_6 ( ! F_7 ( & V_4 -> V_8 , V_7 ) ) ;
F_8 ( & V_4 -> V_5 ) ;
}
void F_9 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
unsigned long V_12 ;
F_10 ( & V_10 -> V_13 , V_12 ) ;
F_5 ( V_10 , V_7 ) ;
F_11 ( & V_10 -> V_13 , V_12 ) ;
}
static int F_12 ( struct V_9 * V_10 , unsigned long V_12 )
{
const struct V_14 * V_15 ;
struct V_3 * V_4 ;
struct V_16 * V_17 [ F_13 ( V_4 -> V_18 ) ] ;
struct V_16 * V_19 = NULL ;
int V_20 , V_21 , V_22 ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
for ( V_21 = V_22 = 0 ; ; V_21 ++ ) {
struct V_16 * V_23 = F_14 ( V_10 -> V_24 ,
V_25 , V_21 ) ;
if ( ! V_23 )
break;
if ( F_15 ( V_23 ) > V_26 )
V_19 = V_23 ;
else if ( V_22 < F_13 ( V_4 -> V_18 ) )
V_17 [ V_22 ++ ] = V_23 ;
else
return - V_27 ;
}
if ( ! V_17 [ 0 ] || ! V_19 )
return - V_28 ;
if ( ! F_16 ( V_10 -> V_10 , V_19 -> V_29 ,
F_15 ( V_19 ) , L_1 ) )
return - V_30 ;
V_4 = F_17 ( V_10 -> V_10 , sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 ) {
F_18 ( L_2 ) ;
return - V_32 ;
}
F_19 ( V_10 -> V_24 , V_10 ) ;
V_10 -> V_11 = V_4 ;
V_15 = F_20 ( V_10 -> V_24 ) ;
if ( ! V_15 )
return - V_28 ;
V_4 -> V_33 = (struct V_34 * ) V_15 -> V_35 ;
V_20 = V_4 -> V_33 -> V_36 ( V_4 , V_10 -> V_10 ) ;
if ( V_20 )
return V_20 ;
F_21 ( & V_4 -> V_5 , F_1 ) ;
F_22 ( V_4 -> V_8 ) ;
F_23 ( V_10 ) ;
V_10 -> V_37 . V_38 = 320 ;
V_10 -> V_37 . V_39 = 200 ;
V_10 -> V_37 . V_40 = 1920 ;
V_10 -> V_37 . V_41 = 2048 ;
V_10 -> V_37 . V_42 = 24 ;
V_10 -> V_37 . V_43 = & V_44 ;
F_24 ( & V_4 -> V_45 , V_19 -> V_29 , F_15 ( V_19 ) ) ;
for ( V_21 = 0 ; V_21 < F_13 ( V_4 -> V_18 ) ; V_21 ++ ) {
if ( ! V_17 [ V_21 ] )
break;
V_20 = F_25 ( V_10 , V_21 , V_17 [ V_21 ] ) ;
if ( V_20 )
goto V_46;
}
#ifdef F_26
V_20 = F_27 ( V_10 , & V_47 ) ;
if ( V_20 )
goto V_46;
#endif
V_20 = F_28 ( V_10 , V_21 ) ;
if ( V_20 )
goto V_46;
V_20 = F_29 ( V_10 ) ;
if ( V_20 )
goto V_46;
V_10 -> V_48 = 1 ;
V_20 = F_30 ( V_10 ) ;
if ( V_20 )
goto V_49;
F_31 ( V_10 ) ;
return 0 ;
V_49:
F_32 ( V_10 ) ;
V_46:
F_33 ( V_10 ) ;
F_34 ( & V_4 -> V_45 ) ;
F_35 ( & V_4 -> V_5 ) ;
return V_20 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
F_32 ( V_10 ) ;
F_33 ( V_10 ) ;
F_34 ( & V_4 -> V_45 ) ;
F_35 ( & V_4 -> V_5 ) ;
V_10 -> V_11 = NULL ;
return 0 ;
}
void F_39 ( struct V_50 * V_18 ,
struct V_51 * V_52 )
{
unsigned long V_12 ;
F_10 ( & V_18 -> V_53 , V_12 ) ;
if ( F_40 ( & V_52 -> V_54 ) ) {
F_41 ( & V_52 -> V_54 , & V_18 -> V_55 ) ;
F_42 ( V_18 -> V_56 . V_10 , V_18 -> V_57 ) ;
}
F_11 ( & V_18 -> V_53 , V_12 ) ;
}
void F_43 ( struct V_50 * V_18 ,
struct V_51 * V_52 )
{
if ( ! F_40 ( & V_52 -> V_54 ) ) {
F_44 ( & V_52 -> V_54 ) ;
F_45 ( V_18 -> V_56 . V_10 , V_18 -> V_57 ) ;
}
}
void F_46 ( struct V_50 * V_18 ,
struct V_51 * V_52 )
{
unsigned long V_12 ;
F_10 ( & V_18 -> V_53 , V_12 ) ;
F_43 ( V_18 , V_52 ) ;
F_11 ( & V_18 -> V_53 , V_12 ) ;
}
static int F_47 ( struct V_9 * V_10 , int V_56 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_48 ( V_4 -> V_18 [ V_56 ] , V_58 ) ;
return 0 ;
}
static void F_49 ( struct V_9 * V_10 , int V_56 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_50 ( V_4 -> V_18 [ V_56 ] , V_58 ) ;
}
static T_1 F_51 ( int V_59 , void * V_60 )
{
struct V_9 * V_10 = V_60 ;
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_50 * V_18 = V_4 -> V_18 [ 0 ] ;
T_2 V_61 , V_62 = F_52 ( V_18 -> V_63 + V_64 ) ;
T_1 V_65 = V_66 ;
F_53 ( 0 , V_18 -> V_63 + V_64 ) ;
V_61 = V_62 & V_18 -> V_67 ;
if ( V_61 & ( V_68 | V_69 | V_70 ) ) {
F_54 ( V_18 , V_62 ) ;
V_65 = V_71 ;
}
return V_65 ;
}
static int F_55 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_50 * V_18 = V_4 -> V_18 [ 0 ] ;
F_56 ( & V_10 -> V_72 ) ;
F_53 ( V_18 -> V_67 , V_18 -> V_63 + V_73 ) ;
F_57 ( 0 , V_18 -> V_63 + V_64 ) ;
F_58 ( & V_10 -> V_72 ) ;
return 0 ;
}
static void F_59 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
struct V_50 * V_18 = V_4 -> V_18 [ 0 ] ;
F_57 ( 0 , V_18 -> V_63 + V_73 ) ;
}
static void F_60 ( struct V_9 * V_10 )
{
F_61 ( V_10 ) ;
}
static int F_62 ( struct V_74 * V_75 )
{
return F_63 ( & V_76 , V_75 ) ;
}
static int F_64 ( struct V_74 * V_75 )
{
F_65 ( F_66 ( V_75 ) ) ;
return 0 ;
}
static int T_3 F_67 ( void )
{
V_76 . V_77 = F_68 ( V_78 ) ;
return F_69 ( & V_79 ) ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_79 ) ;
}
