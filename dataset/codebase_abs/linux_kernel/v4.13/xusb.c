static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * args )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_1 = NULL ;
unsigned int V_7 ;
if ( args -> V_8 != 0 )
return F_3 ( - V_9 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_10 -> V_11 ; V_7 ++ ) {
if ( ! V_6 -> V_12 [ V_7 ] )
continue;
if ( V_6 -> V_12 [ V_7 ] -> V_3 . V_13 == args -> V_14 ) {
V_1 = V_6 -> V_12 [ V_7 ] ;
break;
}
}
if ( V_1 == NULL )
V_1 = F_3 ( - V_15 ) ;
return V_1 ;
}
static struct V_16 *
F_4 ( struct V_17 * V_18 , const char * V_19 )
{
struct V_16 * V_14 = F_5 ( V_18 -> V_3 -> V_13 ) ;
V_14 = F_6 ( V_14 , L_1 ) ;
if ( V_14 )
V_14 = F_6 ( V_14 , V_19 ) ;
return V_14 ;
}
static struct V_16 *
F_7 ( struct V_5 * V_6 , unsigned int V_20 )
{
struct V_16 * V_14 = F_5 ( V_6 -> V_3 . V_13 ) ;
V_14 = F_6 ( V_14 , L_2 ) ;
if ( ! V_14 )
return NULL ;
return F_6 ( V_14 , V_6 -> V_10 -> V_12 [ V_20 ] . V_19 ) ;
}
static int
F_8 ( struct V_21 * V_22 ,
const char * V_23 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_10 -> V_24 ; V_7 ++ )
if ( strcmp ( V_23 , V_22 -> V_10 -> V_25 [ V_7 ] ) == 0 )
return V_7 ;
return - V_9 ;
}
int F_9 ( struct V_21 * V_22 ,
struct V_16 * V_14 )
{
struct V_2 * V_3 = & V_22 -> V_6 -> V_3 ;
const char * V_23 ;
int V_26 ;
V_26 = F_10 ( V_14 , L_3 , & V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_8 ( V_22 , V_23 ) ;
if ( V_26 < 0 ) {
F_11 ( V_3 , L_4 ,
V_23 , V_14 -> V_19 ) ;
return V_26 ;
}
V_22 -> V_23 = V_26 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 ) {
struct V_21 * V_22 = F_13 ( V_1 ) ;
V_22 -> V_6 -> V_27 -> remove ( V_22 ) ;
F_14 ( V_1 ) ;
}
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_16 ( V_3 ) ;
V_6 -> V_10 -> V_27 -> remove ( V_6 ) ;
}
int F_17 ( struct V_5 * V_6 ,
struct V_17 * V_18 ,
struct V_16 * V_14 )
{
int V_26 ;
F_18 ( & V_6 -> V_3 ) ;
F_19 ( & V_6 -> V_28 ) ;
V_6 -> V_3 . V_29 = V_18 -> V_3 ;
V_6 -> V_3 . type = & V_30 ;
V_6 -> V_3 . V_13 = V_14 ;
V_6 -> V_18 = V_18 ;
V_26 = F_20 ( & V_6 -> V_3 , L_5 , V_6 -> V_10 -> V_19 ) ;
if ( V_26 < 0 )
goto V_31;
V_26 = F_21 ( & V_6 -> V_3 ) ;
if ( V_26 < 0 )
goto V_31;
return 0 ;
V_31:
F_22 ( & V_6 -> V_3 ) ;
return V_26 ;
}
int F_23 ( struct V_5 * V_6 ,
const struct V_32 * V_27 )
{
struct V_16 * V_33 ;
struct V_1 * V_22 ;
unsigned int V_7 ;
int V_26 ;
V_33 = F_6 ( V_6 -> V_3 . V_13 , L_2 ) ;
if ( ! V_33 )
return - V_15 ;
V_6 -> V_12 = F_24 ( & V_6 -> V_3 , V_6 -> V_10 -> V_11 , sizeof( V_22 ) ,
V_34 ) ;
if ( ! V_6 -> V_12 ) {
F_25 ( V_33 ) ;
return - V_35 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_16 * V_14 = F_7 ( V_6 , V_7 ) ;
struct V_21 * V_22 ;
if ( ! V_14 || ! F_26 ( V_14 ) ) {
F_25 ( V_14 ) ;
continue;
}
V_6 -> V_12 [ V_7 ] = F_27 ( & V_6 -> V_3 , V_14 , V_27 ) ;
if ( F_28 ( V_6 -> V_12 [ V_7 ] ) ) {
V_26 = F_29 ( V_6 -> V_12 [ V_7 ] ) ;
F_25 ( V_14 ) ;
goto remove;
}
V_22 = V_6 -> V_27 -> V_36 ( V_6 , V_14 , V_7 ) ;
if ( F_28 ( V_22 ) ) {
F_14 ( V_6 -> V_12 [ V_7 ] ) ;
V_26 = F_29 ( V_22 ) ;
goto remove;
}
F_30 ( & V_22 -> V_28 , & V_6 -> V_18 -> V_12 ) ;
F_31 ( V_6 -> V_12 [ V_7 ] , V_22 ) ;
}
V_6 -> V_37 = F_32 ( & V_6 -> V_3 , V_33 ,
F_1 ) ;
if ( F_28 ( V_6 -> V_37 ) ) {
V_26 = F_29 ( V_6 -> V_37 ) ;
goto remove;
}
return 0 ;
remove:
while ( V_7 -- )
F_12 ( V_6 -> V_12 [ V_7 ] ) ;
F_25 ( V_33 ) ;
return V_26 ;
}
void F_33 ( struct V_5 * V_6 )
{
unsigned int V_7 = V_6 -> V_10 -> V_11 ;
F_34 ( V_6 -> V_37 ) ;
while ( V_7 -- )
F_12 ( V_6 -> V_12 [ V_7 ] ) ;
F_22 ( & V_6 -> V_3 ) ;
}
static struct V_5 *
F_35 ( struct V_17 * V_18 ,
const struct V_38 * V_10 )
{
struct V_5 * V_6 ;
struct V_16 * V_14 ;
int V_26 ;
V_14 = F_4 ( V_18 , V_10 -> V_19 ) ;
if ( ! V_14 || ! F_26 ( V_14 ) )
return NULL ;
V_6 = V_10 -> V_27 -> V_36 ( V_18 , V_10 , V_14 ) ;
if ( F_28 ( V_6 ) ) {
V_26 = F_29 ( V_6 ) ;
F_11 ( V_18 -> V_3 , L_6 ,
V_10 -> V_19 , V_26 ) ;
return F_3 ( V_26 ) ;
}
if ( strcmp ( V_10 -> V_19 , L_7 ) == 0 )
V_18 -> V_39 = V_6 ;
if ( strcmp ( V_10 -> V_19 , L_8 ) == 0 )
V_18 -> V_40 = V_6 ;
if ( strcmp ( V_10 -> V_19 , L_9 ) == 0 )
V_18 -> V_41 = V_6 ;
if ( strcmp ( V_10 -> V_19 , L_10 ) == 0 )
V_18 -> V_42 = V_6 ;
if ( strcmp ( V_10 -> V_19 , L_11 ) == 0 )
V_18 -> V_43 = V_6 ;
return V_6 ;
}
static void F_36 ( struct V_17 * V_18 )
{
struct V_5 * V_6 , * V_44 ;
F_37 (pad, tmp, &padctl->pads, list) {
F_38 ( & V_6 -> V_28 ) ;
F_33 ( V_6 ) ;
}
}
static void F_39 ( struct V_17 * V_18 )
{
F_40 ( & V_18 -> V_45 ) ;
F_36 ( V_18 ) ;
F_41 ( & V_18 -> V_45 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_17 * V_18 = V_22 -> V_6 -> V_18 ;
const struct V_46 * V_10 = V_22 -> V_10 ;
T_1 V_47 ;
V_47 = F_43 ( V_18 , V_10 -> V_48 ) ;
V_47 &= ~ ( V_10 -> V_49 << V_10 -> V_50 ) ;
V_47 |= V_22 -> V_23 << V_10 -> V_50 ;
F_44 ( V_18 , V_47 , V_10 -> V_48 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_21 * V_22 ;
if ( V_6 -> V_12 [ V_7 ] ) {
V_22 = F_13 ( V_6 -> V_12 [ V_7 ] ) ;
F_42 ( V_22 ) ;
}
}
}
static int F_46 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
F_40 ( & V_18 -> V_45 ) ;
for ( V_7 = 0 ; V_7 < V_18 -> V_10 -> V_51 ; V_7 ++ ) {
const struct V_38 * V_10 = V_18 -> V_10 -> V_52 [ V_7 ] ;
int V_26 ;
V_6 = F_35 ( V_18 , V_10 ) ;
if ( F_28 ( V_6 ) ) {
V_26 = F_29 ( V_6 ) ;
F_11 ( V_18 -> V_3 , L_6 ,
V_10 -> V_19 , V_26 ) ;
F_36 ( V_18 ) ;
F_41 ( & V_18 -> V_45 ) ;
return V_26 ;
}
if ( ! V_6 )
continue;
F_30 ( & V_6 -> V_28 , & V_18 -> V_52 ) ;
}
F_47 (pad, &padctl->pads, list)
F_45 ( V_6 ) ;
F_41 ( & V_18 -> V_45 ) ;
return 0 ;
}
static bool F_48 ( struct V_21 * V_22 ,
const char * V_23 )
{
const char * V_53 = V_22 -> V_10 -> V_25 [ V_22 -> V_23 ] ;
return strcmp ( V_23 , V_53 ) == 0 ;
}
struct V_21 * F_49 ( struct V_17 * V_18 ,
const char * type ,
unsigned int V_20 )
{
struct V_21 * V_22 , * V_54 = F_3 ( - V_15 ) ;
char * V_19 ;
V_19 = F_50 ( V_34 , L_12 , type , V_20 ) ;
if ( ! V_19 )
return F_3 ( - V_35 ) ;
F_47 (lane, &padctl->lanes, list) {
if ( strcmp ( V_22 -> V_10 -> V_19 , V_19 ) == 0 ) {
V_54 = V_22 ;
break;
}
}
F_51 ( V_19 ) ;
return V_54 ;
}
struct V_21 *
F_52 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
const char * V_23 )
{
struct V_21 * V_22 , * V_59 = F_3 ( - V_15 ) ;
for ( V_58 = V_58 ; V_58 -> type ; V_58 ++ ) {
if ( V_56 -> V_20 != V_58 -> V_56 )
continue;
V_22 = F_49 ( V_56 -> V_18 , V_58 -> type ,
V_58 -> V_20 ) ;
if ( F_28 ( V_22 ) )
continue;
if ( ! F_48 ( V_22 , V_23 ) )
continue;
if ( ! F_28 ( V_59 ) )
F_11 ( & V_56 -> V_3 , L_13 ,
V_58 -> type , V_58 -> V_20 , V_59 -> V_10 -> V_19 ) ;
else
V_59 = V_22 ;
}
return V_59 ;
}
static struct V_16 *
F_53 ( struct V_17 * V_18 , const char * type ,
unsigned int V_20 )
{
struct V_16 * V_14 = F_5 ( V_18 -> V_3 -> V_13 ) ;
V_14 = F_6 ( V_14 , L_14 ) ;
if ( V_14 ) {
char * V_19 ;
V_19 = F_50 ( V_34 , L_12 , type , V_20 ) ;
V_14 = F_6 ( V_14 , V_19 ) ;
F_51 ( V_19 ) ;
}
return V_14 ;
}
struct V_55 *
F_54 ( struct V_17 * V_18 , const char * type ,
unsigned int V_20 )
{
struct V_55 * V_56 ;
struct V_16 * V_14 ;
V_14 = F_53 ( V_18 , type , V_20 ) ;
if ( ! V_14 )
return NULL ;
F_47 (port, &padctl->ports, list) {
if ( V_14 == V_56 -> V_3 . V_13 ) {
F_25 ( V_14 ) ;
return V_56 ;
}
}
F_25 ( V_14 ) ;
return NULL ;
}
struct V_60 *
F_55 ( struct V_17 * V_18 , unsigned int V_20 )
{
struct V_55 * V_56 ;
V_56 = F_54 ( V_18 , L_9 , V_20 ) ;
if ( V_56 )
return F_56 ( V_56 ) ;
return NULL ;
}
struct V_61 *
F_57 ( struct V_17 * V_18 , unsigned int V_20 )
{
struct V_55 * V_56 ;
V_56 = F_54 ( V_18 , L_15 , V_20 ) ;
if ( V_56 )
return F_58 ( V_56 ) ;
return NULL ;
}
static void F_59 ( struct V_2 * V_3 )
{
}
static int F_60 ( struct V_55 * V_56 ,
struct V_17 * V_18 ,
struct V_16 * V_14 ,
const char * V_19 ,
unsigned int V_20 )
{
int V_26 ;
F_19 ( & V_56 -> V_28 ) ;
V_56 -> V_18 = V_18 ;
V_56 -> V_20 = V_20 ;
F_18 ( & V_56 -> V_3 ) ;
V_56 -> V_3 . type = & V_62 ;
V_56 -> V_3 . V_13 = F_5 ( V_14 ) ;
V_56 -> V_3 . V_29 = V_18 -> V_3 ;
V_26 = F_20 ( & V_56 -> V_3 , L_12 , V_19 , V_20 ) ;
if ( V_26 < 0 )
goto V_31;
V_26 = F_21 ( & V_56 -> V_3 ) ;
if ( V_26 < 0 )
goto V_31;
return 0 ;
V_31:
F_22 ( & V_56 -> V_3 ) ;
return V_26 ;
}
static void F_61 ( struct V_55 * V_56 )
{
F_22 ( & V_56 -> V_3 ) ;
}
static int F_62 ( struct V_60 * V_41 )
{
struct V_55 * V_56 = & V_41 -> V_63 ;
struct V_16 * V_14 = V_56 -> V_3 . V_13 ;
V_41 -> V_64 = F_63 ( V_14 , L_16 ) ;
V_41 -> V_65 = F_64 ( & V_56 -> V_3 , L_17 ) ;
return F_65 ( V_41 -> V_65 ) ;
}
static int F_66 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
struct V_60 * V_41 ;
struct V_16 * V_14 ;
int V_26 = 0 ;
V_14 = F_53 ( V_18 , L_9 , V_20 ) ;
if ( ! V_14 || ! F_26 ( V_14 ) )
goto V_66;
V_41 = F_67 ( V_18 -> V_3 , sizeof( * V_41 ) , V_34 ) ;
if ( ! V_41 ) {
V_26 = - V_35 ;
goto V_66;
}
V_26 = F_60 ( & V_41 -> V_63 , V_18 , V_14 , L_9 , V_20 ) ;
if ( V_26 < 0 )
goto V_66;
V_41 -> V_63 . V_27 = V_18 -> V_10 -> V_67 . V_41 . V_27 ;
V_41 -> V_63 . V_22 = V_41 -> V_63 . V_27 -> V_58 ( & V_41 -> V_63 ) ;
if ( F_28 ( V_41 -> V_63 . V_22 ) ) {
V_26 = F_29 ( V_41 -> V_63 . V_22 ) ;
goto V_66;
}
V_26 = F_62 ( V_41 ) ;
if ( V_26 < 0 ) {
F_61 ( & V_41 -> V_63 ) ;
goto V_66;
}
F_30 ( & V_41 -> V_63 . V_28 , & V_18 -> V_67 ) ;
V_66:
F_25 ( V_14 ) ;
return V_26 ;
}
static int F_68 ( struct V_68 * V_42 )
{
struct V_55 * V_56 = & V_42 -> V_63 ;
struct V_16 * V_14 = V_56 -> V_3 . V_13 ;
V_42 -> V_64 = F_63 ( V_14 , L_16 ) ;
return 0 ;
}
static int F_69 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
struct V_68 * V_42 ;
struct V_16 * V_14 ;
int V_26 = 0 ;
V_14 = F_53 ( V_18 , L_10 , V_20 ) ;
if ( ! V_14 || ! F_26 ( V_14 ) )
goto V_66;
V_42 = F_67 ( V_18 -> V_3 , sizeof( * V_42 ) , V_34 ) ;
if ( ! V_42 ) {
V_26 = - V_35 ;
goto V_66;
}
V_26 = F_60 ( & V_42 -> V_63 , V_18 , V_14 , L_10 , V_20 ) ;
if ( V_26 < 0 )
goto V_66;
V_42 -> V_63 . V_27 = V_18 -> V_10 -> V_67 . V_42 . V_27 ;
V_42 -> V_63 . V_22 = V_42 -> V_63 . V_27 -> V_58 ( & V_42 -> V_63 ) ;
if ( F_28 ( V_42 -> V_63 . V_22 ) ) {
V_26 = F_29 ( V_42 -> V_63 . V_22 ) ;
goto V_66;
}
V_26 = F_68 ( V_42 ) ;
if ( V_26 < 0 ) {
F_61 ( & V_42 -> V_63 ) ;
goto V_66;
}
F_30 ( & V_42 -> V_63 . V_28 , & V_18 -> V_67 ) ;
V_66:
F_25 ( V_14 ) ;
return V_26 ;
}
static int F_70 ( struct V_69 * V_43 )
{
return 0 ;
}
static int F_71 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
struct V_69 * V_43 ;
struct V_16 * V_14 ;
int V_26 = 0 ;
V_14 = F_53 ( V_18 , L_11 , V_20 ) ;
if ( ! V_14 || ! F_26 ( V_14 ) )
goto V_66;
V_43 = F_67 ( V_18 -> V_3 , sizeof( * V_43 ) , V_34 ) ;
if ( ! V_43 ) {
V_26 = - V_35 ;
goto V_66;
}
V_26 = F_60 ( & V_43 -> V_63 , V_18 , V_14 , L_11 , V_20 ) ;
if ( V_26 < 0 )
goto V_66;
V_43 -> V_63 . V_27 = V_18 -> V_10 -> V_67 . V_43 . V_27 ;
V_43 -> V_63 . V_22 = V_43 -> V_63 . V_27 -> V_58 ( & V_43 -> V_63 ) ;
if ( F_28 ( V_43 -> V_63 . V_22 ) ) {
V_26 = F_29 ( V_43 -> V_63 . V_22 ) ;
goto V_66;
}
V_26 = F_70 ( V_43 ) ;
if ( V_26 < 0 ) {
F_61 ( & V_43 -> V_63 ) ;
goto V_66;
}
F_30 ( & V_43 -> V_63 . V_28 , & V_18 -> V_67 ) ;
V_66:
F_25 ( V_14 ) ;
return V_26 ;
}
static int F_72 ( struct V_61 * V_70 )
{
struct V_55 * V_56 = & V_70 -> V_63 ;
struct V_16 * V_14 = V_56 -> V_3 . V_13 ;
T_1 V_47 ;
int V_26 ;
V_26 = F_73 ( V_14 , L_18 , & V_47 ) ;
if ( V_26 < 0 ) {
F_11 ( & V_56 -> V_3 , L_19 , V_26 ) ;
return V_26 ;
}
V_70 -> V_56 = V_47 ;
V_70 -> V_64 = F_63 ( V_14 , L_16 ) ;
V_70 -> V_65 = F_64 ( & V_56 -> V_3 , L_17 ) ;
return F_65 ( V_70 -> V_65 ) ;
}
static int F_74 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
struct V_61 * V_70 ;
struct V_16 * V_14 ;
int V_26 = 0 ;
V_14 = F_53 ( V_18 , L_15 , V_20 ) ;
if ( ! V_14 || ! F_26 ( V_14 ) )
goto V_66;
V_70 = F_67 ( V_18 -> V_3 , sizeof( * V_70 ) , V_34 ) ;
if ( ! V_70 ) {
V_26 = - V_35 ;
goto V_66;
}
V_26 = F_60 ( & V_70 -> V_63 , V_18 , V_14 , L_15 , V_20 ) ;
if ( V_26 < 0 )
goto V_66;
V_70 -> V_63 . V_27 = V_18 -> V_10 -> V_67 . V_70 . V_27 ;
V_70 -> V_63 . V_22 = V_70 -> V_63 . V_27 -> V_58 ( & V_70 -> V_63 ) ;
if ( F_28 ( V_70 -> V_63 . V_22 ) ) {
V_26 = F_29 ( V_70 -> V_63 . V_22 ) ;
goto V_66;
}
V_26 = F_72 ( V_70 ) ;
if ( V_26 < 0 ) {
F_61 ( & V_70 -> V_63 ) ;
goto V_66;
}
F_30 ( & V_70 -> V_63 . V_28 , & V_18 -> V_67 ) ;
V_66:
F_25 ( V_14 ) ;
return V_26 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_55 * V_56 , * V_44 ;
F_37 (port, tmp, &padctl->ports, list) {
F_38 ( & V_56 -> V_28 ) ;
F_61 ( V_56 ) ;
}
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_55 * V_56 ;
unsigned int V_7 ;
int V_26 = 0 ;
F_40 ( & V_18 -> V_45 ) ;
for ( V_7 = 0 ; V_7 < V_18 -> V_10 -> V_67 . V_41 . V_71 ; V_7 ++ ) {
V_26 = F_66 ( V_18 , V_7 ) ;
if ( V_26 < 0 )
goto V_72;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_10 -> V_67 . V_42 . V_71 ; V_7 ++ ) {
V_26 = F_69 ( V_18 , V_7 ) ;
if ( V_26 < 0 )
goto V_72;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_10 -> V_67 . V_43 . V_71 ; V_7 ++ ) {
V_26 = F_71 ( V_18 , V_7 ) ;
if ( V_26 < 0 )
goto V_72;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_10 -> V_67 . V_70 . V_71 ; V_7 ++ ) {
V_26 = F_74 ( V_18 , V_7 ) ;
if ( V_26 < 0 )
goto V_72;
}
F_47 (port, &padctl->ports, list) {
V_26 = V_56 -> V_27 -> V_73 ( V_56 ) ;
if ( V_26 < 0 )
F_11 ( V_18 -> V_3 , L_20 ,
F_77 ( & V_56 -> V_3 ) , V_26 ) ;
}
goto V_74;
V_72:
F_75 ( V_18 ) ;
V_74:
F_41 ( & V_18 -> V_45 ) ;
return V_26 ;
}
static void F_78 ( struct V_17 * V_18 )
{
F_40 ( & V_18 -> V_45 ) ;
F_75 ( V_18 ) ;
F_41 ( & V_18 -> V_45 ) ;
}
static int F_79 ( struct V_75 * V_76 )
{
struct V_16 * V_14 = F_5 ( V_76 -> V_3 . V_13 ) ;
const struct V_77 * V_10 ;
struct V_17 * V_18 ;
const struct V_78 * V_59 ;
struct V_79 * V_80 ;
int V_26 ;
V_14 = F_6 ( V_14 , L_1 ) ;
if ( ! V_14 ) {
F_80 ( & V_76 -> V_3 , L_21 ) ;
return F_81 ( V_76 ) ;
}
F_25 ( V_14 ) ;
V_59 = F_82 ( V_81 , V_76 -> V_3 . V_13 ) ;
V_10 = V_59 -> V_82 ;
V_18 = V_10 -> V_27 -> V_36 ( & V_76 -> V_3 , V_10 ) ;
if ( F_28 ( V_18 ) )
return F_29 ( V_18 ) ;
F_83 ( V_76 , V_18 ) ;
F_19 ( & V_18 -> V_67 ) ;
F_19 ( & V_18 -> V_12 ) ;
F_19 ( & V_18 -> V_52 ) ;
F_84 ( & V_18 -> V_45 ) ;
V_80 = F_85 ( V_76 , V_83 , 0 ) ;
V_18 -> V_84 = F_86 ( & V_76 -> V_3 , V_80 ) ;
if ( F_28 ( V_18 -> V_84 ) ) {
V_26 = F_29 ( V_18 -> V_84 ) ;
goto remove;
}
V_18 -> V_85 = F_87 ( & V_76 -> V_3 , NULL ) ;
if ( F_28 ( V_18 -> V_85 ) ) {
V_26 = F_29 ( V_18 -> V_85 ) ;
goto remove;
}
V_26 = F_88 ( V_18 -> V_85 ) ;
if ( V_26 < 0 )
goto remove;
V_26 = F_46 ( V_18 ) ;
if ( V_26 < 0 ) {
F_11 ( & V_76 -> V_3 , L_22 , V_26 ) ;
goto V_86;
}
V_26 = F_76 ( V_18 ) ;
if ( V_26 ) {
F_11 ( & V_76 -> V_3 , L_23 , V_26 ) ;
goto V_87;
}
return 0 ;
V_87:
F_39 ( V_18 ) ;
V_86:
F_89 ( V_18 -> V_85 ) ;
remove:
V_10 -> V_27 -> remove ( V_18 ) ;
return V_26 ;
}
static int F_90 ( struct V_75 * V_76 )
{
struct V_17 * V_18 = F_91 ( V_76 ) ;
int V_26 ;
F_78 ( V_18 ) ;
F_39 ( V_18 ) ;
V_26 = F_89 ( V_18 -> V_85 ) ;
if ( V_26 < 0 )
F_11 ( & V_76 -> V_3 , L_24 , V_26 ) ;
V_18 -> V_10 -> V_27 -> remove ( V_18 ) ;
return V_26 ;
}
struct V_17 * F_92 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_75 * V_76 ;
struct V_16 * V_14 ;
V_14 = F_93 ( V_3 -> V_13 , L_25 , 0 ) ;
if ( ! V_14 )
return F_3 ( - V_9 ) ;
V_76 = F_94 ( V_14 ) ;
if ( ! V_76 ) {
F_25 ( V_14 ) ;
return F_3 ( - V_15 ) ;
}
F_25 ( V_14 ) ;
V_18 = F_91 ( V_76 ) ;
if ( ! V_18 ) {
F_95 ( & V_76 -> V_3 ) ;
return F_3 ( - V_88 ) ;
}
return V_18 ;
}
void F_96 ( struct V_17 * V_18 )
{
if ( V_18 )
F_95 ( V_18 -> V_3 ) ;
}
int F_97 ( struct V_17 * V_18 ,
unsigned int V_56 )
{
if ( V_18 -> V_10 -> V_27 -> V_89 )
return V_18 -> V_10 -> V_27 -> V_89 ( V_18 , V_56 ) ;
return - V_90 ;
}
int F_98 ( struct V_17 * V_18 ,
unsigned int V_56 , bool V_91 )
{
if ( V_18 -> V_10 -> V_27 -> V_92 )
return V_18 -> V_10 -> V_27 -> V_92 ( V_18 , V_56 , V_91 ) ;
return - V_90 ;
}
int F_99 ( struct V_17 * V_18 ,
unsigned int V_56 , bool V_73 )
{
if ( V_18 -> V_10 -> V_27 -> V_93 )
return V_18 -> V_10 -> V_27 -> V_93 ( V_18 , V_56 ,
V_73 ) ;
return - V_90 ;
}
