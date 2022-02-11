static int F_1 ( unsigned long V_1 , const char * V_2 )
{
if ( F_2 ( V_1 ) != V_3 ) {
F_3 ( L_1 ,
V_4 , V_2 , F_2 ( V_1 ) , V_3 ) ;
return - V_5 ;
}
if ( F_4 ( V_1 ) != V_6 )
F_5 ( L_2 ,
V_4 , V_2 , F_4 ( V_1 ) , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_7 ( V_10 , L_3 , L_4 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 -> V_13 ) ;
struct V_14 * V_15 = F_10 ( V_8 ) ;
return V_12 -> V_16 ( V_15 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 -> V_13 ) ;
struct V_14 * V_15 = F_10 ( V_8 ) ;
return V_12 -> remove ( V_15 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_14 * V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
F_15 ( V_17 ) ;
}
static T_1 F_16 ( struct V_18 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_2 V_24 , T_3 V_25 )
{
struct V_7 * V_8 ;
struct V_14 * V_17 ;
int V_26 ;
V_8 = F_14 ( V_20 , struct V_7 , V_20 ) ;
V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
V_26 = V_17 -> V_27 ;
if ( V_24 > V_26 )
return - V_28 ;
if ( V_24 == V_26 )
return 0 ;
if ( V_24 + V_25 > V_26 )
V_25 = V_26 - V_24 ;
memcpy ( V_23 , V_17 -> V_29 + V_24 , V_25 ) ;
return V_25 ;
}
static T_1 F_17 ( struct V_18 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_2 V_24 , T_3 V_25 )
{
struct V_7 * V_8 ;
struct V_14 * V_17 ;
V_8 = F_14 ( V_20 , struct V_7 , V_20 ) ;
V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
return V_17 -> V_30 -> V_31 ( V_17 , V_24 , V_23 , V_25 ) ;
}
int F_18 ( struct V_14 * V_17 , T_4 V_32 ,
char * V_2 , int V_33 )
{
if ( V_17 -> V_30 -> V_34 )
return V_17 -> V_30 -> V_34 ( V_17 , V_32 , V_2 , V_33 ) ;
return - V_35 ;
}
void F_19 ( struct V_14 * V_17 )
{
if ( V_17 -> V_30 -> V_36 )
V_17 -> V_30 -> V_36 ( V_17 ) ;
}
void F_20 ( struct V_14 * V_17 )
{
if ( F_21 ( V_17 -> V_30 -> V_37 ) )
V_17 -> V_30 -> V_37 ( V_17 ) ;
}
int F_22 ( struct V_14 * V_17 , struct V_11 * V_38 )
{
if ( V_17 -> V_30 -> V_39 )
return V_17 -> V_30 -> V_39 ( V_17 , V_38 ) ;
return - V_35 ;
}
int F_23 ( struct V_14 * V_17 , struct V_40 * V_41 , int V_42 )
{
if ( V_17 -> V_30 -> V_43 )
return V_17 -> V_30 -> V_43 ( V_17 , V_41 , V_42 ) ;
return - V_35 ;
}
int F_24 ( struct V_14 * V_17 , int V_44 , void * V_45 , int V_46 )
{
if ( V_17 -> V_30 -> V_47 )
return V_17 -> V_30 -> V_47 ( V_17 , V_44 , V_45 , V_46 ) ;
return - V_35 ;
}
int F_25 ( struct V_14 * V_17 , int V_44 , const void * V_45 , int V_46 )
{
if ( V_17 -> V_30 -> V_31 )
return V_17 -> V_30 -> V_31 ( V_17 , V_44 , V_45 , V_46 ) ;
return - V_35 ;
}
int F_26 ( struct V_11 * V_38 )
{
if ( F_1 ( V_38 -> V_1 , V_38 -> V_13 . V_2 ) )
return - V_5 ;
V_38 -> V_13 . V_48 = & V_49 ;
return F_27 ( & V_38 -> V_13 ) ;
}
void F_28 ( struct V_11 * V_38 )
{
F_29 ( & V_38 -> V_13 ) ;
}
int F_30 ( struct V_14 * * V_50 , int V_51 ,
struct V_52 * V_53 )
{
struct V_14 * V_17 , * * V_54 ;
T_5 V_55 ;
int V_56 , V_57 = 0 ;
if ( V_51 < 1 )
return 0 ;
if ( F_1 ( V_50 [ 0 ] -> V_1 , V_50 [ 0 ] -> V_58 ) )
return - V_5 ;
V_54 = F_31 ( V_50 , V_51 * sizeof( * V_50 ) , V_59 ) ;
if ( ! V_54 )
return - V_60 ;
for ( V_56 = 0 ; V_56 < V_51 ; V_56 ++ ) {
V_17 = V_54 [ V_56 ] ;
if ( ! V_17 -> V_61 ) {
F_3 ( L_5 ,
V_4 , V_56 ) ;
V_57 = - V_5 ;
break;
}
if ( V_17 -> V_33 & V_62 ) {
F_32 ( V_17 -> V_61 , L_6 ,
V_17 -> V_63 ) ;
continue;
}
if ( ! V_17 -> V_29 ) {
F_33 ( V_17 -> V_61 , L_7 ,
V_17 -> V_63 ) ;
V_57 = - V_5 ;
}
if ( ! V_17 -> V_64 ) {
F_33 ( V_17 -> V_61 , L_8 ,
V_17 -> V_63 ) ;
V_57 = - V_5 ;
}
if ( ! V_17 -> V_58 || ! V_17 -> V_65 ||
! V_17 -> V_55 ) {
F_33 ( V_17 -> V_61 ,
L_9
L_10 , V_56 ) ;
V_57 = - V_5 ;
}
if ( V_57 )
break;
}
if ( V_57 ) {
F_15 ( V_54 ) ;
return V_57 ;
}
for ( V_56 = 0 ; V_56 < V_51 ; V_56 ++ ) {
V_17 = V_54 [ V_56 ] ;
V_17 -> V_66 = V_51 ;
V_17 -> V_54 = V_54 ;
F_34 ( & V_17 -> V_8 ) ;
V_17 -> V_8 . V_67 = F_13 ;
V_17 -> V_8 . V_68 = V_17 -> V_61 ;
F_35 ( V_17 ) ;
V_17 -> V_8 . V_48 = & V_49 ;
V_55 = V_17 -> V_55 ;
if ( ! V_17 -> V_69 )
F_36 ( & V_17 -> V_8 , L_11 , V_55 ) ;
else
F_36 ( & V_17 -> V_8 , L_12 , V_17 -> V_69 ,
V_55 ) ;
if ( V_53 ) {
V_57 = V_17 -> V_30 -> V_70 ( V_17 , NULL ,
V_53 -> V_71 , V_53 -> V_72 ) ;
if ( V_57 ) {
F_37 ( V_17 -> V_61 ,
L_13 ) ;
goto V_73;
}
}
V_57 = F_38 ( & V_17 -> V_8 ) ;
if ( V_57 < 0 ) {
F_33 ( V_17 -> V_61 , L_14
L_15 , V_17 -> V_63 , V_17 -> V_8 . V_20 . V_2 ) ;
goto V_73;
}
V_57 = F_39 ( & V_17 -> V_8 . V_20 , & V_74 ) ;
if ( V_57 < 0 ) {
F_33 ( & V_17 -> V_8 , L_16 ) ;
goto V_75;
}
F_40 ( V_17 ) ;
F_41 ( V_17 ) ;
}
return 0 ;
V_75:
F_42 ( & V_17 -> V_8 ) ;
V_73:
F_15 ( V_54 ) ;
for ( V_56 -- ; V_56 >= 0 ; V_56 -- ) {
F_43 ( V_50 [ V_56 ] ) ;
F_44 ( & V_50 [ V_56 ] -> V_8 . V_20 , & V_74 ) ;
F_42 ( & V_50 [ V_56 ] -> V_8 ) ;
F_45 ( V_50 [ V_56 ] ) ;
F_46 ( & V_50 [ V_56 ] -> V_8 ) ;
}
return V_57 ;
}
int F_47 ( struct V_14 * * V_50 , int V_51 )
{
return F_30 ( V_50 , V_51 , NULL ) ;
}
int F_48 ( struct V_14 * V_17 , struct V_52 * V_53 )
{
return F_30 ( & V_17 , 1 , V_53 ) ;
}
int F_49 ( struct V_14 * V_17 )
{
return F_47 ( & V_17 , 1 ) ;
}
void F_50 ( struct V_14 * * V_50 , int V_51 )
{
int V_56 ;
if ( V_51 < 1 )
return;
F_15 ( V_50 [ 0 ] -> V_54 ) ;
for ( V_56 = 0 ; V_56 < V_51 ; V_56 ++ ) {
F_43 ( V_50 [ V_56 ] ) ;
F_44 ( & V_50 [ V_56 ] -> V_8 . V_20 , & V_74 ) ;
F_42 ( & V_50 [ V_56 ] -> V_8 ) ;
F_45 ( V_50 [ V_56 ] ) ;
F_46 ( & V_50 [ V_56 ] -> V_8 ) ;
}
}
void F_51 ( struct V_14 * V_17 )
{
F_50 ( & V_17 , 1 ) ;
}
static int F_52 ( void )
{
return F_53 ( & V_49 ) ;
}
static void F_54 ( void )
{
F_55 ( & V_49 ) ;
}
