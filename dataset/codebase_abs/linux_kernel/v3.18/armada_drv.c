static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 || V_2 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_3 ( V_6 , struct V_7 , V_9 ) ;
struct V_10 * V_11 ;
while ( F_4 ( & V_8 -> V_12 , & V_11 ) )
F_5 ( V_11 ) ;
}
void F_6 ( struct V_13 * V_2 ,
struct V_10 * V_11 )
{
struct V_7 * V_8 = V_2 -> V_14 ;
F_7 ( ! F_8 ( & V_8 -> V_12 , V_11 ) ) ;
F_9 ( & V_8 -> V_9 ) ;
}
void F_10 ( struct V_13 * V_2 ,
struct V_10 * V_11 )
{
unsigned long V_15 ;
F_11 ( & V_2 -> V_16 , V_15 ) ;
F_6 ( V_2 , V_11 ) ;
F_12 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_13 ( struct V_13 * V_2 , unsigned long V_15 )
{
const struct V_17 * V_18 ;
const struct V_19 * V_20 ;
struct V_7 * V_8 ;
struct V_21 * V_22 [ F_14 ( V_8 -> V_23 ) ] ;
struct V_21 * V_24 = NULL ;
int V_25 , V_26 , V_27 ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
for ( V_26 = V_27 = 0 ; ; V_26 ++ ) {
struct V_21 * V_28 = F_15 ( V_2 -> V_29 ,
V_30 , V_26 ) ;
if ( ! V_28 )
break;
if ( F_16 ( V_28 ) > V_31 )
V_24 = V_28 ;
else if ( V_27 < F_14 ( V_8 -> V_23 ) )
V_22 [ V_27 ++ ] = V_28 ;
else
return - V_32 ;
}
if ( ! V_24 )
return - V_33 ;
if ( ! F_17 ( V_2 -> V_2 , V_24 -> V_34 ,
F_16 ( V_24 ) , L_1 ) )
return - V_35 ;
V_8 = F_18 ( V_2 -> V_2 , sizeof( * V_8 ) , V_36 ) ;
if ( ! V_8 ) {
F_19 ( L_2 ) ;
return - V_37 ;
}
F_20 ( V_2 -> V_29 , V_2 ) ;
V_2 -> V_14 = V_8 ;
V_18 = F_21 ( V_2 -> V_29 ) ;
if ( ! V_18 )
return - V_33 ;
V_20 = ( const struct V_19 * ) V_18 -> V_38 ;
F_22 ( & V_8 -> V_9 , F_2 ) ;
F_23 ( V_8 -> V_12 ) ;
F_24 ( V_2 ) ;
V_2 -> V_39 . V_40 = 320 ;
V_2 -> V_39 . V_41 = 200 ;
V_2 -> V_39 . V_42 = 1920 ;
V_2 -> V_39 . V_43 = 2048 ;
V_2 -> V_39 . V_44 = 24 ;
V_2 -> V_39 . V_45 = & V_46 ;
F_25 ( & V_8 -> V_47 , V_24 -> V_34 , F_16 ( V_24 ) ) ;
for ( V_26 = 0 ; V_26 < F_14 ( V_8 -> V_23 ) ; V_26 ++ ) {
int V_48 ;
if ( ! V_22 [ V_26 ] )
break;
V_48 = F_26 ( V_2 -> V_29 , V_26 ) ;
if ( V_48 < 0 )
goto V_49;
V_25 = F_27 ( V_2 , V_2 -> V_2 , V_22 [ V_26 ] , V_48 ,
V_20 , NULL ) ;
if ( V_25 )
goto V_49;
}
if ( F_1 ( V_2 -> V_2 ) ) {
V_25 = F_28 ( V_2 -> V_2 , V_2 ) ;
if ( V_25 )
goto V_49;
} else {
#ifdef F_29
V_25 = F_30 ( V_2 , & V_50 ) ;
if ( V_25 )
goto V_49;
#endif
}
V_25 = F_31 ( V_2 , V_2 -> V_39 . V_51 ) ;
if ( V_25 )
goto V_52;
V_2 -> V_53 = true ;
V_2 -> V_54 = 1 ;
V_25 = F_32 ( V_2 ) ;
if ( V_25 )
goto V_52;
F_33 ( V_2 ) ;
return 0 ;
V_52:
if ( F_1 ( V_2 -> V_2 ) )
F_34 ( V_2 -> V_2 , V_2 ) ;
V_49:
F_35 ( V_2 ) ;
F_36 ( & V_8 -> V_47 ) ;
F_37 ( & V_8 -> V_9 ) ;
return V_25 ;
}
static int F_38 ( struct V_13 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( F_1 ( V_2 -> V_2 ) )
F_34 ( V_2 -> V_2 , V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_8 -> V_47 ) ;
F_37 ( & V_8 -> V_9 ) ;
V_2 -> V_14 = NULL ;
return 0 ;
}
void F_41 ( struct V_55 * V_23 ,
struct V_56 * V_57 )
{
unsigned long V_15 ;
F_11 ( & V_23 -> V_58 , V_15 ) ;
if ( F_42 ( & V_57 -> V_59 ) ) {
F_43 ( & V_57 -> V_59 , & V_23 -> V_60 ) ;
F_44 ( V_23 -> V_61 . V_2 , V_23 -> V_62 ) ;
}
F_12 ( & V_23 -> V_58 , V_15 ) ;
}
void F_45 ( struct V_55 * V_23 ,
struct V_56 * V_57 )
{
if ( ! F_42 ( & V_57 -> V_59 ) ) {
F_46 ( & V_57 -> V_59 ) ;
F_47 ( V_23 -> V_61 . V_2 , V_23 -> V_62 ) ;
}
}
void F_48 ( struct V_55 * V_23 ,
struct V_56 * V_57 )
{
unsigned long V_15 ;
F_11 ( & V_23 -> V_58 , V_15 ) ;
F_45 ( V_23 , V_57 ) ;
F_12 ( & V_23 -> V_58 , V_15 ) ;
}
static int F_49 ( struct V_13 * V_2 , int V_61 )
{
struct V_7 * V_8 = V_2 -> V_14 ;
F_50 ( V_8 -> V_23 [ V_61 ] , V_63 ) ;
return 0 ;
}
static void F_51 ( struct V_13 * V_2 , int V_61 )
{
struct V_7 * V_8 = V_2 -> V_14 ;
F_52 ( V_8 -> V_23 [ V_61 ] , V_63 ) ;
}
static void F_53 ( struct V_13 * V_2 )
{
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
return F_56 ( & V_64 , F_57 ( V_2 ) ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_59 ( F_60 ( V_2 ) ) ;
}
static int F_61 ( struct V_1 * V_2 , void * V_65 )
{
return V_2 -> V_3 == V_65 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_65 )
{
const char * V_66 = V_65 ;
return ! strcmp ( F_63 ( V_2 ) , V_66 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_67 * * V_68 , struct V_69 * V_70 )
{
struct V_69 * V_71 , * V_72 ;
F_65 (port, ep) {
V_72 = F_66 ( V_71 ) ;
if ( ! V_72 || ! F_67 ( V_72 ) ) {
F_68 ( V_72 ) ;
continue;
} else if ( ! F_67 ( V_72 -> V_73 ) ) {
F_69 ( V_2 , L_3 ,
V_72 -> V_74 ) ;
F_68 ( V_72 ) ;
continue;
}
F_70 ( V_2 , V_68 , F_61 , V_72 ) ;
F_68 ( V_72 ) ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_67 * * V_68 )
{
struct V_69 * V_70 ;
int V_27 ;
if ( V_2 -> V_3 ) {
struct V_69 * V_75 = V_2 -> V_3 ;
for ( V_27 = 0 ; ; V_27 ++ ) {
V_70 = F_72 ( V_75 , L_4 , V_27 ) ;
if ( ! V_70 )
break;
F_70 ( V_2 , V_68 , F_61 , V_70 ) ;
F_68 ( V_70 ) ;
}
if ( V_27 == 0 ) {
F_73 ( V_2 , L_5 ) ;
return - V_76 ;
}
for ( V_27 = 0 ; ; V_27 ++ ) {
V_70 = F_72 ( V_75 , L_4 , V_27 ) ;
if ( ! V_70 )
break;
F_64 ( V_2 , V_68 , V_70 ) ;
F_68 ( V_70 ) ;
}
} else if ( V_2 -> V_4 ) {
char * * V_77 = V_2 -> V_4 ;
struct V_1 * V_78 ;
for ( V_27 = 0 ; V_77 [ V_27 ] ; V_27 ++ )
F_70 ( V_2 , V_68 , F_62 ,
V_77 [ V_27 ] ) ;
if ( V_27 == 0 ) {
F_73 ( V_2 , L_5 ) ;
return - V_76 ;
}
for ( V_27 = 0 ; V_77 [ V_27 ] ; V_27 ++ ) {
V_78 = F_74 ( & V_79 , NULL ,
V_77 [ V_27 ] ) ;
if ( V_78 && V_78 -> V_3 ) {
F_65 (d->of_node, port)
F_64 ( V_2 , V_68 , V_70 ) ;
}
F_75 ( V_78 ) ;
}
}
return 0 ;
}
static int F_76 ( struct V_80 * V_81 )
{
if ( F_1 ( & V_81 -> V_2 ) ) {
struct V_67 * V_68 = NULL ;
int V_25 ;
V_25 = F_71 ( & V_81 -> V_2 , & V_68 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_77 ( & V_81 -> V_2 ,
& V_82 , V_68 ) ;
} else {
return F_56 ( & V_64 , V_81 ) ;
}
}
static int F_78 ( struct V_80 * V_81 )
{
if ( F_1 ( & V_81 -> V_2 ) )
F_79 ( & V_81 -> V_2 , & V_82 ) ;
else
F_59 ( F_80 ( V_81 ) ) ;
return 0 ;
}
static int T_1 F_81 ( void )
{
int V_25 ;
V_64 . V_83 = F_14 ( V_84 ) ;
V_25 = F_82 ( & V_85 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_82 ( & V_86 ) ;
if ( V_25 )
F_83 ( & V_85 ) ;
return V_25 ;
}
static void T_2 F_84 ( void )
{
F_83 ( & V_86 ) ;
F_83 ( & V_85 ) ;
}
