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
struct V_3 * V_4 ;
struct V_14 * V_15 = NULL ;
int V_16 , V_17 ;
for ( V_17 = 0 ; ; V_17 ++ ) {
struct V_14 * V_18 = F_13 ( V_10 -> V_19 ,
V_20 , V_17 ) ;
if ( ! V_18 )
break;
if ( F_14 ( V_18 ) > V_21 )
V_15 = V_18 ;
else
return - V_22 ;
}
if ( ! V_15 )
return - V_23 ;
if ( ! F_15 ( V_10 -> V_10 , V_15 -> V_24 ,
F_14 ( V_15 ) , L_1 ) )
return - V_25 ;
V_4 = F_16 ( V_10 -> V_10 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
F_17 ( L_2 ) ;
return - V_27 ;
}
F_18 ( V_10 -> V_19 , V_10 ) ;
V_10 -> V_11 = V_4 ;
F_19 ( & V_4 -> V_5 , F_1 ) ;
F_20 ( V_4 -> V_8 ) ;
F_21 ( V_10 ) ;
V_10 -> V_28 . V_29 = 320 ;
V_10 -> V_28 . V_30 = 200 ;
V_10 -> V_28 . V_31 = 1920 ;
V_10 -> V_28 . V_32 = 2048 ;
V_10 -> V_28 . V_33 = 24 ;
V_10 -> V_28 . V_34 = & V_35 ;
F_22 ( & V_4 -> V_36 , V_15 -> V_24 , F_14 ( V_15 ) ) ;
V_16 = F_23 ( V_10 -> V_10 , V_10 ) ;
if ( V_16 )
goto V_37;
V_16 = F_24 ( V_10 , V_10 -> V_28 . V_38 ) ;
if ( V_16 )
goto V_39;
V_10 -> V_40 = true ;
V_10 -> V_41 = 1 ;
V_16 = F_25 ( V_10 ) ;
if ( V_16 )
goto V_39;
F_26 ( V_10 ) ;
return 0 ;
V_39:
F_27 ( V_10 -> V_10 , V_10 ) ;
V_37:
F_28 ( V_10 ) ;
F_29 ( & V_4 -> V_36 ) ;
F_30 ( & V_4 -> V_5 ) ;
return V_16 ;
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_32 ( V_10 ) ;
F_33 ( V_10 ) ;
F_27 ( V_10 -> V_10 , V_10 ) ;
F_28 ( V_10 ) ;
F_29 ( & V_4 -> V_36 ) ;
F_30 ( & V_4 -> V_5 ) ;
V_10 -> V_11 = NULL ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 , unsigned int V_42 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_35 ( V_4 -> V_43 [ V_42 ] , V_44 ) ;
return 0 ;
}
static void F_36 ( struct V_9 * V_10 , unsigned int V_42 )
{
struct V_3 * V_4 = V_10 -> V_11 ;
F_37 ( V_4 -> V_43 [ V_42 ] , V_44 ) ;
}
static void F_38 ( struct V_9 * V_10 )
{
F_39 ( V_10 ) ;
}
static int F_40 ( struct V_45 * V_10 )
{
return F_41 ( & V_46 , F_42 ( V_10 ) ) ;
}
static void F_43 ( struct V_45 * V_10 )
{
F_44 ( F_45 ( V_10 ) ) ;
}
static int F_46 ( struct V_45 * V_10 , void * V_47 )
{
return V_10 -> V_48 == V_47 ;
}
static int F_47 ( struct V_45 * V_10 , void * V_47 )
{
const char * V_49 = V_47 ;
return ! strcmp ( F_48 ( V_10 ) , V_49 ) ;
}
static void F_49 ( struct V_45 * V_10 ,
struct V_50 * * V_51 , struct V_52 * V_53 )
{
struct V_52 * V_54 , * V_55 ;
F_50 (port, ep) {
V_55 = F_51 ( V_54 ) ;
if ( ! V_55 || ! F_52 ( V_55 ) ) {
F_53 ( V_55 ) ;
continue;
} else if ( ! F_52 ( V_55 -> V_56 ) ) {
F_54 ( V_10 , L_3 ,
V_55 -> V_57 ) ;
F_53 ( V_55 ) ;
continue;
}
F_55 ( V_10 , V_51 , F_46 , V_55 ) ;
F_53 ( V_55 ) ;
}
}
static int F_56 ( struct V_58 * V_59 )
{
struct V_50 * V_51 = NULL ;
struct V_45 * V_10 = & V_59 -> V_10 ;
int V_16 ;
V_16 = F_57 ( V_10 , F_47 , & V_60 ) ;
if ( V_16 != - V_22 )
return V_16 ;
if ( V_10 -> V_61 ) {
char * * V_62 = V_10 -> V_61 ;
struct V_52 * V_53 ;
struct V_45 * V_63 ;
int V_64 ;
for ( V_64 = 0 ; V_62 [ V_64 ] ; V_64 ++ )
F_55 ( V_10 , & V_51 , F_47 ,
V_62 [ V_64 ] ) ;
if ( V_64 == 0 ) {
F_58 ( V_10 , L_4 ) ;
return - V_65 ;
}
for ( V_64 = 0 ; V_62 [ V_64 ] ; V_64 ++ ) {
V_63 = F_59 ( & V_66 , NULL ,
V_62 [ V_64 ] ) ;
if ( V_63 && V_63 -> V_48 ) {
F_50 (d->of_node, port)
F_49 ( V_10 , & V_51 , V_53 ) ;
}
F_60 ( V_63 ) ;
}
}
return F_61 ( & V_59 -> V_10 , & V_60 ,
V_51 ) ;
}
static int F_62 ( struct V_58 * V_59 )
{
F_63 ( & V_59 -> V_10 , & V_60 ) ;
return 0 ;
}
static int T_1 F_64 ( void )
{
int V_16 ;
V_46 . V_67 = F_65 ( V_68 ) ;
V_16 = F_66 ( & V_69 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_66 ( & V_70 ) ;
if ( V_16 )
F_67 ( & V_69 ) ;
return V_16 ;
}
static void T_2 F_68 ( void )
{
F_67 ( & V_70 ) ;
F_67 ( & V_69 ) ;
}
