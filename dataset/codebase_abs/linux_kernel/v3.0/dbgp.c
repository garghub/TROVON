static int F_1 ( char * V_1 , unsigned V_2 )
{
char V_3 ;
if ( ! V_2 )
return 0 ;
V_3 = V_1 [ V_2 - 1 ] ;
if ( V_3 != 0 )
V_1 [ V_2 - 1 ] = 0 ;
F_2 ( V_4 L_1 , V_1 , V_3 ) ;
return 0 ;
}
static void F_3 ( struct V_5 * V_6 )
{
if ( V_6 && V_6 -> V_7 == V_8 . V_9 ) {
F_4 ( V_6 ) ;
V_6 -> V_7 = NULL ;
}
}
static void F_5 ( void )
{
F_3 ( V_8 . V_10 ) ;
F_3 ( V_8 . V_11 ) ;
}
static void F_6 ( struct V_5 * V_6 , struct V_12 * V_13 )
{
int V_14 ;
int V_15 = 0 ;
int V_16 = V_13 -> V_16 ;
if ( V_6 == V_8 . V_10 ) {
V_14 = 1 ;
goto V_17;
}
if ( V_16 != 0 ) {
V_14 = 2 ;
goto V_18;
}
F_1 ( V_13 -> V_1 , V_13 -> V_19 ) ;
V_13 -> V_20 = V_21 ;
V_15 = F_7 ( V_6 , V_13 , V_22 ) ;
if ( V_15 < 0 ) {
V_14 = 3 ;
goto V_18;
}
return;
V_18:
F_8 ( V_13 -> V_1 ) ;
F_9 ( V_8 . V_11 , V_13 ) ;
F_5 () ;
V_17:
F_10 ( & V_8 . V_9 -> V_23 ,
L_2 , V_14 , V_15 , V_16 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
int V_15 , V_14 ;
struct V_12 * V_13 ;
V_13 = F_12 ( V_6 , V_24 ) ;
if ( ! V_13 ) {
V_15 = - V_25 ;
V_14 = 1 ;
goto V_26;
}
V_13 -> V_1 = F_13 ( V_21 , V_24 ) ;
if ( ! V_13 -> V_1 ) {
V_15 = - V_25 ;
V_14 = 2 ;
goto V_27;
}
V_13 -> V_28 = F_6 ;
V_13 -> V_20 = V_21 ;
V_15 = F_7 ( V_6 , V_13 , V_22 ) ;
if ( V_15 < 0 ) {
V_14 = 3 ;
goto V_29;
}
return 0 ;
V_29:
F_8 ( V_13 -> V_1 ) ;
V_27:
F_9 ( V_8 . V_11 , V_13 ) ;
V_26:
F_10 ( & V_8 . V_9 -> V_23 ,
L_3 , V_14 , V_15 ) ;
return V_15 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_30 * V_31 )
{
int V_15 = F_15 ( V_6 , V_31 ) ;
V_6 -> V_7 = V_8 . V_9 ;
return V_15 ;
}
static int F_16 ( void )
{
int V_15 , V_14 ;
V_15 = F_14 ( V_8 . V_10 , & V_32 ) ;
if ( V_15 < 0 ) {
V_14 = 1 ;
goto V_26;
}
V_15 = F_14 ( V_8 . V_11 , & V_33 ) ;
if ( V_15 < 0 ) {
V_14 = 2 ;
goto V_27;
}
V_15 = F_11 ( V_8 . V_11 ) ;
if ( V_15 < 0 ) {
V_14 = 3 ;
goto V_29;
}
return 0 ;
V_29:
F_3 ( V_8 . V_11 ) ;
V_27:
F_3 ( V_8 . V_10 ) ;
V_26:
F_10 ( & V_8 . V_9 -> V_23 , L_4 , V_14 , V_15 ) ;
return V_15 ;
}
static void F_17 ( struct V_34 * V_9 )
{
#ifdef F_18
F_5 () ;
#else
F_19 ( V_8 . V_35 ) ;
#endif
}
static void F_20 ( struct V_34 * V_9 )
{
#ifdef F_21
F_8 ( V_8 . V_35 ) ;
#endif
if ( V_8 . V_13 ) {
F_8 ( V_8 . V_13 -> V_1 ) ;
F_9 ( V_9 -> V_36 , V_8 . V_13 ) ;
}
V_9 -> V_36 -> V_7 = NULL ;
}
static int T_1 F_22 ( struct V_34 * V_9 )
{
int V_14 ;
F_23 ( V_9 ) ;
V_8 . V_10 = F_24 ( V_9 , & V_32 ) ;
if ( ! V_8 . V_10 ) {
V_14 = 1 ;
goto V_26;
}
V_8 . V_10 -> V_7 = V_9 ;
V_32 . V_37 =
F_25 ( V_38 ) ;
V_8 . V_11 = F_24 ( V_9 , & V_33 ) ;
if ( ! V_8 . V_11 ) {
V_8 . V_10 -> V_7 = NULL ;
V_14 = 2 ;
goto V_27;
}
V_8 . V_11 -> V_7 = V_9 ;
V_33 . V_37 =
F_25 ( V_38 ) ;
V_39 . V_40 = V_32 . V_41 ;
V_39 . V_42 = V_33 . V_41 ;
#ifdef F_21
V_8 . V_35 -> V_43 = V_8 . V_10 ;
V_8 . V_35 -> V_44 = V_8 . V_11 ;
V_8 . V_35 -> V_45 = & V_32 ;
V_8 . V_35 -> V_46 = & V_33 ;
if ( F_26 ( V_9 , 1 ) < 0 ) {
V_14 = 3 ;
goto V_29;
}
return 0 ;
V_29:
V_8 . V_11 -> V_7 = NULL ;
#else
return 0 ;
#endif
V_27:
V_8 . V_10 -> V_7 = NULL ;
V_26:
F_10 ( & V_8 . V_9 -> V_23 , L_5 , V_14 ) ;
return - V_47 ;
}
static int T_1 F_27 ( struct V_34 * V_9 )
{
int V_15 , V_14 ;
V_8 . V_9 = V_9 ;
V_8 . V_13 = F_12 ( V_9 -> V_36 , V_24 ) ;
if ( ! V_8 . V_13 ) {
V_15 = - V_25 ;
V_14 = 1 ;
goto V_17;
}
V_8 . V_13 -> V_1 = F_13 ( V_48 , V_24 ) ;
if ( ! V_8 . V_13 -> V_1 ) {
V_15 = - V_25 ;
V_14 = 2 ;
goto V_17;
}
V_8 . V_13 -> V_20 = V_48 ;
V_9 -> V_36 -> V_7 = V_9 ;
V_49 . V_50 = V_9 -> V_36 -> V_51 ;
#ifdef F_21
V_8 . V_35 = F_28 ( sizeof( struct V_52 ) , V_24 ) ;
if ( ! V_8 . V_35 ) {
V_14 = 3 ;
V_15 = - V_25 ;
goto V_17;
}
#endif
V_15 = F_22 ( V_9 ) ;
if ( V_15 < 0 ) {
V_14 = 4 ;
goto V_17;
}
F_10 ( & V_8 . V_9 -> V_23 , L_6 ) ;
return 0 ;
V_17:
F_10 ( & V_9 -> V_23 , L_7 , V_14 , V_15 ) ;
F_20 ( V_9 ) ;
return V_15 ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_12 * V_13 )
{
F_10 ( & V_8 . V_9 -> V_23 , L_8 ,
V_13 -> V_16 , V_13 -> V_19 , V_13 -> V_20 ) ;
}
static int F_30 ( struct V_34 * V_9 ,
const struct V_53 * V_54 )
{
struct V_12 * V_13 = V_8 . V_13 ;
T_2 V_55 = V_54 -> V_56 ;
T_3 V_57 = F_31 ( V_54 -> V_58 ) ;
T_3 V_20 = F_31 ( V_54 -> V_59 ) ;
int V_15 = - V_60 ;
void * V_61 = NULL ;
T_3 V_2 = 0 ;
V_9 -> V_36 -> V_7 = V_9 ;
if ( V_55 == V_62 ) {
switch ( V_57 >> 8 ) {
case V_63 :
F_10 ( & V_8 . V_9 -> V_23 , L_9 ) ;
V_2 = sizeof V_49 ;
V_61 = & V_49 ;
break;
case V_64 :
F_10 ( & V_8 . V_9 -> V_23 , L_10 ) ;
V_2 = sizeof V_39 ;
V_61 = & V_39 ;
break;
default:
goto V_17;
}
V_15 = 0 ;
} else if ( V_55 == V_65 &&
V_57 == V_66 ) {
F_10 ( & V_8 . V_9 -> V_23 , L_11 ) ;
#ifdef F_18
V_15 = F_16 () ;
#else
V_15 = F_32 ( V_8 . V_35 , 0 ) ;
#endif
if ( V_15 < 0 )
goto V_17;
} else
goto V_17;
V_13 -> V_20 = F_33 ( V_20 , V_2 ) ;
V_13 -> V_67 = V_2 < V_13 -> V_20 ;
if ( V_61 && V_13 -> V_20 )
memcpy ( V_13 -> V_1 , V_61 , V_13 -> V_20 ) ;
V_13 -> V_28 = F_29 ;
return F_7 ( V_9 -> V_36 , V_13 , V_22 ) ;
V_17:
F_10 ( & V_8 . V_9 -> V_23 ,
L_12 , V_55 , V_57 ) ;
return V_15 ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_68 , F_27 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_68 ) ;
#ifdef F_21
F_38 () ;
#endif
}
