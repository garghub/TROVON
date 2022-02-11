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
static void F_12 ( struct V_9 * V_10 )
{
F_13 ( V_10 ) ;
}
static int F_14 ( struct V_14 * V_10 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 = NULL ;
int V_17 , V_18 ;
for ( V_18 = 0 ; ; V_18 ++ ) {
struct V_15 * V_19 = F_15 ( F_16 ( V_10 ) ,
V_20 , V_18 ) ;
if ( ! V_19 )
break;
if ( F_17 ( V_19 ) > V_21 )
V_16 = V_19 ;
else
return - V_22 ;
}
if ( ! V_16 )
return - V_23 ;
if ( ! F_18 ( V_10 , V_16 -> V_24 , F_17 ( V_16 ) ,
L_1 ) )
return - V_25 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
F_20 ( F_21 ( struct V_3 , V_28 ) != 0 ) ;
V_17 = F_22 ( & V_4 -> V_28 , & V_29 , V_10 ) ;
if ( V_17 ) {
F_23 ( V_10 , L_2 V_30 L_3 ,
V_31 , V_17 ) ;
F_24 ( V_4 ) ;
return V_17 ;
}
V_4 -> V_28 . V_11 = V_4 ;
F_25 ( V_10 , & V_4 -> V_28 ) ;
F_26 ( & V_4 -> V_5 , F_1 ) ;
F_27 ( V_4 -> V_8 ) ;
F_28 ( & V_4 -> V_28 ) ;
V_4 -> V_28 . V_32 . V_33 = 320 ;
V_4 -> V_28 . V_32 . V_34 = 200 ;
V_4 -> V_28 . V_32 . V_35 = 1920 ;
V_4 -> V_28 . V_32 . V_36 = 2048 ;
V_4 -> V_28 . V_32 . V_37 = 24 ;
V_4 -> V_28 . V_32 . V_38 = & V_39 ;
F_29 ( & V_4 -> V_40 , V_16 -> V_24 , F_17 ( V_16 ) ) ;
F_30 ( & V_4 -> V_41 ) ;
V_17 = F_31 ( V_10 , & V_4 -> V_28 ) ;
if ( V_17 )
goto V_42;
V_17 = F_32 ( & V_4 -> V_28 , V_4 -> V_28 . V_32 . V_43 ) ;
if ( V_17 )
goto V_44;
V_4 -> V_28 . V_45 = true ;
V_17 = F_33 ( & V_4 -> V_28 ) ;
if ( V_17 )
goto V_44;
F_34 ( & V_4 -> V_28 ) ;
V_17 = F_35 ( & V_4 -> V_28 , 0 ) ;
if ( V_17 )
goto V_46;
#ifdef F_36
F_37 ( V_4 -> V_28 . V_47 ) ;
#endif
return 0 ;
V_46:
F_38 ( & V_4 -> V_28 ) ;
F_39 ( & V_4 -> V_28 ) ;
V_44:
F_40 ( V_10 , & V_4 -> V_28 ) ;
V_42:
F_41 ( & V_4 -> V_28 ) ;
F_42 ( & V_4 -> V_40 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_44 ( & V_4 -> V_28 ) ;
return V_17 ;
}
static void F_45 ( struct V_14 * V_10 )
{
struct V_9 * V_28 = F_46 ( V_10 ) ;
struct V_3 * V_4 = V_28 -> V_11 ;
F_38 ( & V_4 -> V_28 ) ;
F_39 ( & V_4 -> V_28 ) ;
F_47 ( & V_4 -> V_28 ) ;
F_40 ( V_10 , & V_4 -> V_28 ) ;
F_41 ( & V_4 -> V_28 ) ;
F_42 ( & V_4 -> V_40 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_44 ( & V_4 -> V_28 ) ;
}
static int F_48 ( struct V_14 * V_10 , void * V_48 )
{
return V_10 -> V_49 == V_48 ;
}
static int F_49 ( struct V_14 * V_10 , void * V_48 )
{
const char * V_50 = V_48 ;
return ! strcmp ( F_50 ( V_10 ) , V_50 ) ;
}
static void F_51 ( struct V_14 * V_10 ,
struct V_51 * * V_52 , struct V_53 * V_54 )
{
struct V_53 * V_55 , * V_56 ;
F_52 (port, ep) {
V_56 = F_53 ( V_55 ) ;
if ( ! V_56 || ! F_54 ( V_56 ) ) {
F_55 ( V_56 ) ;
continue;
} else if ( ! F_54 ( V_56 -> V_57 ) ) {
F_56 ( V_10 , L_4 ,
V_56 -> V_58 ) ;
F_55 ( V_56 ) ;
continue;
}
F_57 ( V_10 , V_52 , F_48 , V_56 ) ;
F_55 ( V_56 ) ;
}
}
static int F_58 ( struct V_59 * V_60 )
{
struct V_51 * V_52 = NULL ;
struct V_14 * V_10 = & V_60 -> V_10 ;
int V_17 ;
V_17 = F_59 ( V_10 , F_49 , & V_61 ) ;
if ( V_17 != - V_22 )
return V_17 ;
if ( V_10 -> V_62 ) {
char * * V_63 = V_10 -> V_62 ;
struct V_53 * V_54 ;
struct V_14 * V_64 ;
int V_65 ;
for ( V_65 = 0 ; V_63 [ V_65 ] ; V_65 ++ )
F_60 ( V_10 , & V_52 , F_49 ,
V_63 [ V_65 ] ) ;
if ( V_65 == 0 ) {
F_23 ( V_10 , L_5 ) ;
return - V_66 ;
}
for ( V_65 = 0 ; V_63 [ V_65 ] ; V_65 ++ ) {
V_64 = F_61 ( & V_67 , NULL ,
V_63 [ V_65 ] ) ;
if ( V_64 && V_64 -> V_49 ) {
F_52 (d->of_node, port)
F_51 ( V_10 , & V_52 , V_54 ) ;
}
F_62 ( V_64 ) ;
}
}
return F_63 ( & V_60 -> V_10 , & V_61 ,
V_52 ) ;
}
static int F_64 ( struct V_59 * V_60 )
{
F_65 ( & V_60 -> V_10 , & V_61 ) ;
return 0 ;
}
static int T_1 F_66 ( void )
{
int V_17 ;
V_29 . V_68 = F_67 ( V_69 ) ;
V_17 = F_68 ( & V_70 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_68 ( & V_71 ) ;
if ( V_17 )
F_69 ( & V_70 ) ;
return V_17 ;
}
static void T_2 F_70 ( void )
{
F_69 ( & V_71 ) ;
F_69 ( & V_70 ) ;
}
