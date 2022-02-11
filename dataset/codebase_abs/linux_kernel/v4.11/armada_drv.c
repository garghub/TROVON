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
static int F_12 ( struct V_9 * V_10 , unsigned int V_14 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_13 ( V_4 -> V_15 [ V_14 ] , V_16 ) ;
return 0 ;
}
static void F_14 ( struct V_9 * V_10 , unsigned int V_14 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_15 ( V_4 -> V_15 [ V_14 ] , V_16 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
F_17 ( V_10 ) ;
}
static int F_18 ( struct V_17 * V_10 )
{
struct V_3 * V_4 ;
struct V_18 * V_19 = NULL ;
int V_20 , V_21 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
struct V_18 * V_22 = F_19 ( F_20 ( V_10 ) ,
V_23 , V_21 ) ;
if ( ! V_22 )
break;
if ( F_21 ( V_22 ) > V_24 )
V_19 = V_22 ;
else
return - V_25 ;
}
if ( ! V_19 )
return - V_26 ;
if ( ! F_22 ( V_10 , V_19 -> V_27 , F_21 ( V_19 ) ,
L_1 ) )
return - V_28 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
F_24 ( F_25 ( struct V_3 , V_31 ) != 0 ) ;
V_20 = F_26 ( & V_4 -> V_31 , & V_32 , V_10 ) ;
if ( V_20 ) {
F_27 ( V_10 , L_2 V_33 L_3 ,
V_34 , V_20 ) ;
F_28 ( V_4 ) ;
return V_20 ;
}
V_4 -> V_31 . V_35 = F_20 ( V_10 ) ;
V_4 -> V_31 . V_11 = V_4 ;
F_29 ( V_4 -> V_31 . V_35 , & V_4 -> V_31 ) ;
F_30 ( & V_4 -> V_5 , F_1 ) ;
F_31 ( V_4 -> V_8 ) ;
F_32 ( & V_4 -> V_31 ) ;
V_4 -> V_31 . V_36 . V_37 = 320 ;
V_4 -> V_31 . V_36 . V_38 = 200 ;
V_4 -> V_31 . V_36 . V_39 = 1920 ;
V_4 -> V_31 . V_36 . V_40 = 2048 ;
V_4 -> V_31 . V_36 . V_41 = 24 ;
V_4 -> V_31 . V_36 . V_42 = & V_43 ;
F_33 ( & V_4 -> V_44 , V_19 -> V_27 , F_21 ( V_19 ) ) ;
F_34 ( & V_4 -> V_45 ) ;
V_20 = F_35 ( V_10 , & V_4 -> V_31 ) ;
if ( V_20 )
goto V_46;
V_20 = F_36 ( & V_4 -> V_31 , V_4 -> V_31 . V_36 . V_47 ) ;
if ( V_20 )
goto V_48;
V_4 -> V_31 . V_49 = true ;
V_20 = F_37 ( & V_4 -> V_31 ) ;
if ( V_20 )
goto V_48;
F_38 ( & V_4 -> V_31 ) ;
V_20 = F_39 ( & V_4 -> V_31 , 0 ) ;
if ( V_20 )
goto V_50;
#ifdef F_40
F_41 ( V_4 -> V_31 . V_51 ) ;
#endif
return 0 ;
V_50:
F_42 ( & V_4 -> V_31 ) ;
F_43 ( & V_4 -> V_31 ) ;
V_48:
F_44 ( V_10 , & V_4 -> V_31 ) ;
V_46:
F_45 ( & V_4 -> V_31 ) ;
F_46 ( & V_4 -> V_44 ) ;
F_47 ( & V_4 -> V_5 ) ;
F_48 ( & V_4 -> V_31 ) ;
return V_20 ;
}
static void F_49 ( struct V_17 * V_10 )
{
struct V_9 * V_31 = F_50 ( V_10 ) ;
struct V_3 * V_4 = V_31 -> V_11 ;
F_42 ( & V_4 -> V_31 ) ;
F_43 ( & V_4 -> V_31 ) ;
#ifdef F_40
F_51 ( V_4 -> V_31 . V_51 ) ;
#endif
F_52 ( & V_4 -> V_31 ) ;
F_44 ( V_10 , & V_4 -> V_31 ) ;
F_45 ( & V_4 -> V_31 ) ;
F_46 ( & V_4 -> V_44 ) ;
F_47 ( & V_4 -> V_5 ) ;
F_48 ( & V_4 -> V_31 ) ;
}
static int F_53 ( struct V_17 * V_10 , void * V_52 )
{
return V_10 -> V_53 == V_52 ;
}
static int F_54 ( struct V_17 * V_10 , void * V_52 )
{
const char * V_54 = V_52 ;
return ! strcmp ( F_55 ( V_10 ) , V_54 ) ;
}
static void F_56 ( struct V_17 * V_10 ,
struct V_55 * * V_56 , struct V_57 * V_58 )
{
struct V_57 * V_59 , * V_60 ;
F_57 (port, ep) {
V_60 = F_58 ( V_59 ) ;
if ( ! V_60 || ! F_59 ( V_60 ) ) {
F_60 ( V_60 ) ;
continue;
} else if ( ! F_59 ( V_60 -> V_61 ) ) {
F_61 ( V_10 , L_4 ,
V_60 -> V_62 ) ;
F_60 ( V_60 ) ;
continue;
}
F_62 ( V_10 , V_56 , F_53 , V_60 ) ;
F_60 ( V_60 ) ;
}
}
static int F_63 ( struct V_63 * V_64 )
{
struct V_55 * V_56 = NULL ;
struct V_17 * V_10 = & V_64 -> V_10 ;
int V_20 ;
V_20 = F_64 ( V_10 , F_54 , & V_65 ) ;
if ( V_20 != - V_25 )
return V_20 ;
if ( V_10 -> V_66 ) {
char * * V_67 = V_10 -> V_66 ;
struct V_57 * V_58 ;
struct V_17 * V_68 ;
int V_69 ;
for ( V_69 = 0 ; V_67 [ V_69 ] ; V_69 ++ )
F_65 ( V_10 , & V_56 , F_54 ,
V_67 [ V_69 ] ) ;
if ( V_69 == 0 ) {
F_27 ( V_10 , L_5 ) ;
return - V_70 ;
}
for ( V_69 = 0 ; V_67 [ V_69 ] ; V_69 ++ ) {
V_68 = F_66 ( & V_71 , NULL ,
V_67 [ V_69 ] ) ;
if ( V_68 && V_68 -> V_53 ) {
F_57 (d->of_node, port)
F_56 ( V_10 , & V_56 , V_58 ) ;
}
F_67 ( V_68 ) ;
}
}
return F_68 ( & V_64 -> V_10 , & V_65 ,
V_56 ) ;
}
static int F_69 ( struct V_63 * V_64 )
{
F_70 ( & V_64 -> V_10 , & V_65 ) ;
return 0 ;
}
static int T_1 F_71 ( void )
{
int V_20 ;
V_32 . V_72 = F_72 ( V_73 ) ;
V_20 = F_73 ( & V_74 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_73 ( & V_75 ) ;
if ( V_20 )
F_74 ( & V_74 ) ;
return V_20 ;
}
static void T_2 F_75 ( void )
{
F_74 ( & V_75 ) ;
F_74 ( & V_74 ) ;
}
