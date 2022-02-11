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
V_19 , V_20 ) ;
F_4 ( & V_2 -> V_26 , L_1 , V_2 -> type ,
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
F_4 ( & V_2 -> V_26 , L_4 , V_2 -> type ,
V_5 , V_21 ? L_2 : L_3 ) ;
}
return V_21 ;
}
static int F_7 ( struct V_10 * V_11 ,
unsigned long * V_27 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
* V_27 = V_13 -> V_28 ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
int V_29 , enum V_30 * V_31 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
* V_31 = V_13 -> V_31 ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 ,
enum V_32 * V_33 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
F_10 ( & V_13 -> V_34 ) ;
* V_33 = V_13 -> V_33 ;
F_11 ( & V_13 -> V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
enum V_32 V_33 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
F_10 ( & V_13 -> V_34 ) ;
V_13 -> V_33 = V_33 ;
if ( V_33 == V_35 )
F_13 ( & V_13 -> V_36 ) ;
F_11 ( & V_13 -> V_34 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 ,
int V_29 , enum V_37 * type )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_29 >= V_16 -> V_24 )
return - V_6 ;
* type = V_16 -> V_25 [ V_29 ] . type ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
int V_29 , unsigned long * V_27 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_29 >= V_16 -> V_24 )
return - V_6 ;
* V_27 = V_16 -> V_25 [ V_29 ] . V_27 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
unsigned long * V_27 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int V_5 ;
for ( V_5 = V_16 -> V_24 - 1 ; V_5 > 0 ; V_5 -- ) {
if ( V_16 -> V_25 [ V_5 ] . type == V_38 ) {
* V_27 = V_16 -> V_25 [ V_5 ] . V_27 ;
return 0 ;
}
}
return - V_6 ;
}
static void F_17 ( struct V_12 * V_13 ,
unsigned int V_39 , enum V_30 V_31 ,
unsigned long V_40 , unsigned long V_41 )
{
F_18 () ;
V_13 -> V_42 = V_39 ;
V_13 -> V_28 = ( V_40 + V_41 ) / 2 ;
V_13 -> V_31 = V_31 ;
F_19 ( ( V_43 ) ( V_40 / 1000 ) , ( V_43 ) ( V_41 / 1000 ) ) ;
F_20 ( V_44 ) ;
}
static T_1 F_21 ( int V_45 , void * V_46 )
{
struct V_12 * V_13 = V_46 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned int V_39 = V_13 -> V_42 ;
unsigned long V_40 , V_41 ;
if ( F_22 ( V_39 == 0 ) )
return V_47 ;
if ( V_39 == 1 ) {
V_41 = V_16 -> V_25 [ 0 ] . V_27 ;
V_40 = V_48 ;
} else {
V_41 = V_16 -> V_25 [ V_39 - 1 ] . V_27 ;
V_40 = V_16 -> V_25 [ V_39 - 2 ] . V_27 ;
}
V_39 -= 1 ;
F_17 ( V_13 , V_39 , V_49 ,
V_40 , V_41 ) ;
F_23 ( & V_13 -> V_50 -> V_26 ,
L_5 , V_41 , V_40 ) ;
F_13 ( & V_13 -> V_36 ) ;
return V_47 ;
}
static T_1 F_24 ( int V_45 , void * V_46 )
{
struct V_12 * V_13 = V_46 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned int V_39 = V_13 -> V_42 ;
unsigned long V_40 , V_41 ;
if ( V_39 < V_16 -> V_24 - 1 ) {
V_41 = V_16 -> V_25 [ V_39 + 1 ] . V_27 ;
V_40 = V_16 -> V_25 [ V_39 ] . V_27 ;
V_39 += 1 ;
F_17 ( V_13 , V_39 , V_51 ,
V_40 , V_41 ) ;
F_23 ( & V_13 -> V_50 -> V_26 ,
L_5 , V_41 , V_40 ) ;
} else if ( V_39 == V_16 -> V_24 - 1 )
V_13 -> V_28 = V_16 -> V_25 [ V_39 ] . V_27 + 1 ;
F_13 ( & V_13 -> V_36 ) ;
return V_47 ;
}
static void F_25 ( struct V_52 * V_53 )
{
enum V_32 V_54 ;
struct V_12 * V_13 ;
V_13 = F_26 ( V_53 , struct V_12 , V_36 ) ;
F_10 ( & V_13 -> V_34 ) ;
V_54 = V_13 -> V_33 ;
F_11 ( & V_13 -> V_34 ) ;
if ( V_54 == V_55 )
return;
F_27 ( V_13 -> V_50 ) ;
F_23 ( & V_13 -> V_50 -> V_26 , L_6 ) ;
}
static struct V_15 *
F_28 ( struct V_56 * V_57 )
{
struct V_15 * V_16 ;
struct V_58 * V_59 = V_57 -> V_60 . V_61 ;
char V_62 [ 32 ] ;
const char * V_63 ;
T_2 V_64 ;
int V_5 , V_65 ;
V_16 = F_29 ( & V_57 -> V_60 , sizeof( * V_16 ) , V_66 ) ;
if ( ! V_16 )
return NULL ;
if ( F_30 ( V_59 , L_7 , & V_64 ) )
goto V_67;
if ( V_64 > V_68 )
goto V_67;
V_16 -> V_24 = V_64 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_24 ; V_5 ++ ) {
sprintf ( V_62 , L_8 , V_5 ) ;
if ( F_30 ( V_59 , V_62 , & V_64 ) )
goto V_67;
V_16 -> V_25 [ V_5 ] . V_27 = V_64 ;
sprintf ( V_62 , L_9 , V_5 ) ;
if ( F_31 ( V_59 , V_62 , & V_63 ) )
goto V_67;
if ( ! strcmp ( V_63 , L_10 ) )
V_16 -> V_25 [ V_5 ] . type = V_69 ;
else if ( ! strcmp ( V_63 , L_11 ) )
V_16 -> V_25 [ V_5 ] . type = V_70 ;
else if ( ! strcmp ( V_63 , L_12 ) )
V_16 -> V_25 [ V_5 ] . type = V_71 ;
else if ( ! strcmp ( V_63 , L_13 ) )
V_16 -> V_25 [ V_5 ] . type = V_38 ;
else
goto V_67;
sprintf ( V_62 , L_14 , V_5 ) ;
if ( F_30 ( V_59 , V_62 , & V_64 ) )
goto V_67;
if ( V_64 > V_7 )
goto V_67;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
sprintf ( V_62 , L_15 , V_5 , V_65 ) ;
if ( F_31 ( V_59 , V_62 , & V_63 ) )
goto V_67;
if ( strlen ( V_63 ) >= V_72 )
goto V_67;
strcpy ( V_16 -> V_25 [ V_5 ] . V_8 [ V_65 ] , V_63 ) ;
}
}
return V_16 ;
V_67:
F_32 ( & V_57 -> V_60 , L_16 ) ;
return NULL ;
}
static inline struct V_15 *
F_28 ( struct V_56 * V_57 )
{
return NULL ;
}
static int F_33 ( struct V_56 * V_57 )
{
struct V_12 * V_13 = NULL ;
struct V_15 * V_16 = NULL ;
struct V_58 * V_59 = V_57 -> V_60 . V_61 ;
int V_73 , V_74 , V_21 = 0 ;
unsigned long V_75 , V_76 ;
if ( V_59 )
V_16 = F_28 ( V_57 ) ;
else
V_16 = F_34 ( & V_57 -> V_60 ) ;
if ( ! V_16 )
return - V_6 ;
V_13 = F_29 ( & V_57 -> V_60 , sizeof( * V_13 ) , V_66 ) ;
if ( ! V_13 )
return - V_77 ;
F_35 ( & V_13 -> V_34 ) ;
F_10 ( & V_13 -> V_34 ) ;
V_13 -> V_33 = V_55 ;
V_13 -> V_17 = V_16 ;
F_36 ( & V_13 -> V_36 , F_25 ) ;
V_73 = F_37 ( V_57 , L_17 ) ;
if ( V_73 < 0 ) {
F_32 ( & V_57 -> V_60 , L_18 ) ;
return V_73 ;
}
V_21 = F_38 ( & V_57 -> V_60 , V_73 , NULL ,
F_21 , V_78 | V_79 ,
L_19 , V_13 ) ;
if ( V_21 < 0 ) {
F_32 ( & V_57 -> V_60 , L_20 ) ;
return V_21 ;
}
V_74 = F_37 ( V_57 , L_21 ) ;
if ( V_74 < 0 ) {
F_32 ( & V_57 -> V_60 , L_22 ) ;
return V_74 ;
}
V_21 = F_38 ( & V_57 -> V_60 , V_74 , NULL ,
F_24 , V_78 | V_79 ,
L_23 , V_13 ) ;
if ( V_21 < 0 ) {
F_32 ( & V_57 -> V_60 , L_24 ) ;
return V_21 ;
}
V_13 -> V_50 = F_39 ( L_25 ,
V_16 -> V_24 , 0 , V_13 , & V_80 , NULL , 0 , 0 ) ;
if ( F_40 ( V_13 -> V_50 ) ) {
F_32 ( & V_57 -> V_60 , L_26 ) ;
return F_41 ( V_13 -> V_50 ) ;
}
F_4 ( & V_57 -> V_60 , L_27 ) ;
V_75 = V_48 ;
V_76 = V_16 -> V_25 [ 0 ] . V_27 ;
F_17 ( V_13 , 0 , V_81 ,
V_75 , V_76 ) ;
F_42 ( V_57 , V_13 ) ;
V_13 -> V_33 = V_35 ;
F_11 ( & V_13 -> V_34 ) ;
return 0 ;
}
static int F_43 ( struct V_56 * V_57 )
{
struct V_12 * V_13 = F_44 ( V_57 ) ;
F_45 ( V_13 -> V_50 ) ;
F_46 ( & V_13 -> V_36 ) ;
F_47 ( & V_13 -> V_34 ) ;
return 0 ;
}
static int F_48 ( struct V_56 * V_57 ,
T_3 V_82 )
{
struct V_12 * V_13 = F_44 ( V_57 ) ;
F_49 ( & V_13 -> V_36 ) ;
F_18 () ;
return 0 ;
}
static int F_50 ( struct V_56 * V_57 )
{
struct V_12 * V_13 = F_44 ( V_57 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_75 , V_76 ;
V_75 = V_48 ;
V_76 = V_16 -> V_25 [ 0 ] . V_27 ;
F_17 ( V_13 , 0 , V_81 ,
V_75 , V_76 ) ;
return 0 ;
}
