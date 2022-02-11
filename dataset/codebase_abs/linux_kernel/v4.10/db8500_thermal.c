static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( ! strlen ( V_2 -> type ) )
return - V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( ! strcmp ( V_4 -> V_8 [ V_5 ] , V_2 -> type ) )
return 0 ;
}
return - V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_18 , V_19 , V_20 ;
int V_5 , V_21 = - V_6 ;
V_2 -> V_22 -> V_23 ( V_2 , & V_18 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_24 ; V_5 ++ ) {
if ( F_1 ( V_2 , & V_16 -> V_25 [ V_5 ] ) )
continue;
V_19 = V_20 = V_5 > V_18 ? V_18 : V_5 ;
V_21 = F_3 ( V_11 , V_5 , V_2 ,
V_19 , V_20 , V_26 ) ;
F_4 ( & V_2 -> V_27 , L_1 , V_2 -> type ,
V_5 , V_21 , V_21 ? L_2 : L_3 ) ;
}
return V_21 ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int V_5 , V_21 = - V_6 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_24 ; V_5 ++ ) {
if ( F_1 ( V_2 , & V_16 -> V_25 [ V_5 ] ) )
continue;
V_21 = F_6 ( V_11 , V_5 , V_2 ) ;
F_4 ( & V_2 -> V_27 , L_4 , V_2 -> type ,
V_5 , V_21 ? L_2 : L_3 ) ;
}
return V_21 ;
}
static int F_7 ( struct V_10 * V_11 , int * V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
* V_28 = V_13 -> V_29 ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
int V_30 , enum V_31 * V_32 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
* V_32 = V_13 -> V_32 ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 ,
enum V_33 * V_34 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
F_10 ( & V_13 -> V_35 ) ;
* V_34 = V_13 -> V_34 ;
F_11 ( & V_13 -> V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
enum V_33 V_34 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
F_10 ( & V_13 -> V_35 ) ;
V_13 -> V_34 = V_34 ;
if ( V_34 == V_36 )
F_13 ( & V_13 -> V_37 ) ;
F_11 ( & V_13 -> V_35 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 ,
int V_30 , enum V_38 * type )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_30 >= V_16 -> V_24 )
return - V_6 ;
* type = V_16 -> V_25 [ V_30 ] . type ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
int V_30 , int * V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_30 >= V_16 -> V_24 )
return - V_6 ;
* V_28 = V_16 -> V_25 [ V_30 ] . V_28 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
int * V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int V_5 ;
for ( V_5 = V_16 -> V_24 - 1 ; V_5 > 0 ; V_5 -- ) {
if ( V_16 -> V_25 [ V_5 ] . type == V_39 ) {
* V_28 = V_16 -> V_25 [ V_5 ] . V_28 ;
return 0 ;
}
}
return - V_6 ;
}
static void F_17 ( struct V_12 * V_13 ,
unsigned int V_40 , enum V_31 V_32 ,
unsigned long V_41 , unsigned long V_42 )
{
F_18 () ;
V_13 -> V_43 = V_40 ;
V_13 -> V_29 = ( V_41 + V_42 ) / 2 ;
V_13 -> V_32 = V_32 ;
F_19 ( ( V_44 ) ( V_41 / 1000 ) , ( V_44 ) ( V_42 / 1000 ) ) ;
F_20 ( V_45 ) ;
}
static T_1 F_21 ( int V_46 , void * V_47 )
{
struct V_12 * V_13 = V_47 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned int V_40 = V_13 -> V_43 ;
unsigned long V_41 , V_42 ;
if ( F_22 ( V_40 == 0 ) )
return V_48 ;
if ( V_40 == 1 ) {
V_42 = V_16 -> V_25 [ 0 ] . V_28 ;
V_41 = V_49 ;
} else {
V_42 = V_16 -> V_25 [ V_40 - 1 ] . V_28 ;
V_41 = V_16 -> V_25 [ V_40 - 2 ] . V_28 ;
}
V_40 -= 1 ;
F_17 ( V_13 , V_40 , V_50 ,
V_41 , V_42 ) ;
F_23 ( & V_13 -> V_51 -> V_27 ,
L_5 , V_42 , V_41 ) ;
F_13 ( & V_13 -> V_37 ) ;
return V_48 ;
}
static T_1 F_24 ( int V_46 , void * V_47 )
{
struct V_12 * V_13 = V_47 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned int V_40 = V_13 -> V_43 ;
unsigned long V_41 , V_42 ;
if ( V_40 < V_16 -> V_24 - 1 ) {
V_42 = V_16 -> V_25 [ V_40 + 1 ] . V_28 ;
V_41 = V_16 -> V_25 [ V_40 ] . V_28 ;
V_40 += 1 ;
F_17 ( V_13 , V_40 , V_52 ,
V_41 , V_42 ) ;
F_23 ( & V_13 -> V_51 -> V_27 ,
L_5 , V_42 , V_41 ) ;
} else if ( V_40 == V_16 -> V_24 - 1 )
V_13 -> V_29 = V_16 -> V_25 [ V_40 ] . V_28 + 1 ;
F_13 ( & V_13 -> V_37 ) ;
return V_48 ;
}
static void F_25 ( struct V_53 * V_54 )
{
enum V_33 V_55 ;
struct V_12 * V_13 ;
V_13 = F_26 ( V_54 , struct V_12 , V_37 ) ;
F_10 ( & V_13 -> V_35 ) ;
V_55 = V_13 -> V_34 ;
F_11 ( & V_13 -> V_35 ) ;
if ( V_55 == V_56 )
return;
F_27 ( V_13 -> V_51 , V_57 ) ;
F_23 ( & V_13 -> V_51 -> V_27 , L_6 ) ;
}
static struct V_15 *
F_28 ( struct V_58 * V_59 )
{
struct V_15 * V_16 ;
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
char V_64 [ 32 ] ;
const char * V_65 ;
T_2 V_66 ;
int V_5 , V_67 ;
V_16 = F_29 ( & V_59 -> V_62 , sizeof( * V_16 ) , V_68 ) ;
if ( ! V_16 )
return NULL ;
if ( F_30 ( V_61 , L_7 , & V_66 ) )
goto V_69;
if ( V_66 > V_70 )
goto V_69;
V_16 -> V_24 = V_66 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_24 ; V_5 ++ ) {
sprintf ( V_64 , L_8 , V_5 ) ;
if ( F_30 ( V_61 , V_64 , & V_66 ) )
goto V_69;
V_16 -> V_25 [ V_5 ] . V_28 = V_66 ;
sprintf ( V_64 , L_9 , V_5 ) ;
if ( F_31 ( V_61 , V_64 , & V_65 ) )
goto V_69;
if ( ! strcmp ( V_65 , L_10 ) )
V_16 -> V_25 [ V_5 ] . type = V_71 ;
else if ( ! strcmp ( V_65 , L_11 ) )
V_16 -> V_25 [ V_5 ] . type = V_72 ;
else if ( ! strcmp ( V_65 , L_12 ) )
V_16 -> V_25 [ V_5 ] . type = V_73 ;
else if ( ! strcmp ( V_65 , L_13 ) )
V_16 -> V_25 [ V_5 ] . type = V_39 ;
else
goto V_69;
sprintf ( V_64 , L_14 , V_5 ) ;
if ( F_30 ( V_61 , V_64 , & V_66 ) )
goto V_69;
if ( V_66 > V_7 )
goto V_69;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
sprintf ( V_64 , L_15 , V_5 , V_67 ) ;
if ( F_31 ( V_61 , V_64 , & V_65 ) )
goto V_69;
if ( strlen ( V_65 ) >= V_74 )
goto V_69;
strcpy ( V_16 -> V_25 [ V_5 ] . V_8 [ V_67 ] , V_65 ) ;
}
}
return V_16 ;
V_69:
F_32 ( & V_59 -> V_62 , L_16 ) ;
return NULL ;
}
static inline struct V_15 *
F_28 ( struct V_58 * V_59 )
{
return NULL ;
}
static int F_33 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = NULL ;
struct V_15 * V_16 = NULL ;
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
int V_75 , V_76 , V_21 = 0 ;
unsigned long V_77 , V_78 ;
if ( V_61 )
V_16 = F_28 ( V_59 ) ;
else
V_16 = F_34 ( & V_59 -> V_62 ) ;
if ( ! V_16 )
return - V_6 ;
V_13 = F_29 ( & V_59 -> V_62 , sizeof( * V_13 ) , V_68 ) ;
if ( ! V_13 )
return - V_79 ;
F_35 ( & V_13 -> V_35 ) ;
F_10 ( & V_13 -> V_35 ) ;
V_13 -> V_34 = V_56 ;
V_13 -> V_17 = V_16 ;
F_36 ( & V_13 -> V_37 , F_25 ) ;
V_75 = F_37 ( V_59 , L_17 ) ;
if ( V_75 < 0 ) {
F_32 ( & V_59 -> V_62 , L_18 ) ;
V_21 = V_75 ;
goto V_80;
}
V_21 = F_38 ( & V_59 -> V_62 , V_75 , NULL ,
F_21 , V_81 | V_82 ,
L_19 , V_13 ) ;
if ( V_21 < 0 ) {
F_32 ( & V_59 -> V_62 , L_20 ) ;
goto V_80;
}
V_76 = F_37 ( V_59 , L_21 ) ;
if ( V_76 < 0 ) {
F_32 ( & V_59 -> V_62 , L_22 ) ;
V_21 = V_76 ;
goto V_80;
}
V_21 = F_38 ( & V_59 -> V_62 , V_76 , NULL ,
F_24 , V_81 | V_82 ,
L_23 , V_13 ) ;
if ( V_21 < 0 ) {
F_32 ( & V_59 -> V_62 , L_24 ) ;
goto V_80;
}
V_13 -> V_51 = F_39 ( L_25 ,
V_16 -> V_24 , 0 , V_13 , & V_83 , NULL , 0 , 0 ) ;
if ( F_40 ( V_13 -> V_51 ) ) {
F_32 ( & V_59 -> V_62 , L_26 ) ;
V_21 = F_41 ( V_13 -> V_51 ) ;
goto V_80;
}
F_4 ( & V_59 -> V_62 , L_27 ) ;
V_77 = V_49 ;
V_78 = V_16 -> V_25 [ 0 ] . V_28 ;
F_17 ( V_13 , 0 , V_84 ,
V_77 , V_78 ) ;
F_42 ( V_59 , V_13 ) ;
V_13 -> V_34 = V_36 ;
V_80:
F_11 ( & V_13 -> V_35 ) ;
return V_21 ;
}
static int F_43 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = F_44 ( V_59 ) ;
F_45 ( V_13 -> V_51 ) ;
F_46 ( & V_13 -> V_37 ) ;
F_47 ( & V_13 -> V_35 ) ;
return 0 ;
}
static int F_48 ( struct V_58 * V_59 ,
T_3 V_85 )
{
struct V_12 * V_13 = F_44 ( V_59 ) ;
F_49 ( & V_13 -> V_37 ) ;
F_18 () ;
return 0 ;
}
static int F_50 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = F_44 ( V_59 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_77 , V_78 ;
V_77 = V_49 ;
V_78 = V_16 -> V_25 [ 0 ] . V_28 ;
F_17 ( V_13 , 0 , V_84 ,
V_77 , V_78 ) ;
return 0 ;
}
