static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_4 , & V_3 -> V_5 ) ;
}
static void F_3 ( struct V_2 * V_3 , unsigned long V_6 )
{
F_4 ( & V_3 -> V_7 ) ;
if ( ! F_5 ( & V_3 -> V_8 ) || V_6 < V_3 -> V_8 . V_6 )
F_6 ( & V_3 -> V_8 , V_6 ) ;
F_7 ( & V_3 -> V_7 ) ;
}
static void F_8 ( struct V_9 * V_9 )
{
struct V_9 * V_10 ;
while ( V_9 ) {
V_10 = V_9 -> V_11 ;
V_9 -> V_11 = NULL ;
F_9 ( V_9 ) ;
V_9 = V_10 ;
}
}
static struct V_9 * F_10 ( struct V_2 * V_3 , int V_12 )
{
struct V_13 * V_14 , * V_15 ;
unsigned long V_16 = 0 ;
int V_17 = 0 ;
struct V_18 F_8 = { } ;
F_4 ( & V_19 ) ;
F_11 (delayed, next, &dc->delayed_bios, list) {
if ( V_12 || F_12 ( V_20 , V_14 -> V_6 ) ) {
F_13 ( & V_14 -> V_21 ) ;
F_14 ( & F_8 , V_14 -> V_9 ) ;
if ( ( F_15 ( V_14 -> V_9 ) == V_22 ) )
V_14 -> V_23 -> V_24 -- ;
else
V_14 -> V_23 -> V_25 -- ;
F_16 ( V_14 , V_3 -> V_26 ) ;
continue;
}
if ( ! V_17 ) {
V_17 = 1 ;
V_16 = V_14 -> V_6 ;
} else
V_16 = F_17 ( V_16 , V_14 -> V_6 ) ;
}
F_7 ( & V_19 ) ;
if ( V_17 )
F_3 ( V_3 , V_16 ) ;
return F_18 ( & F_8 ) ;
}
static void V_5 ( struct V_27 * V_28 )
{
struct V_2 * V_3 ;
V_3 = F_19 ( V_28 , struct V_2 , V_5 ) ;
F_8 ( F_10 ( V_3 , 0 ) ) ;
}
static int F_20 ( struct V_29 * V_30 , unsigned int V_31 , char * * V_32 )
{
struct V_2 * V_3 ;
unsigned long long V_33 ;
if ( V_31 != 3 && V_31 != 6 ) {
V_30 -> error = L_1 ;
return - V_34 ;
}
V_3 = F_21 ( sizeof( * V_3 ) , V_35 ) ;
if ( ! V_3 ) {
V_30 -> error = L_2 ;
return - V_36 ;
}
V_3 -> V_25 = V_3 -> V_24 = 0 ;
if ( sscanf ( V_32 [ 1 ] , L_3 , & V_33 ) != 1 ) {
V_30 -> error = L_4 ;
goto V_37;
}
V_3 -> V_38 = V_33 ;
if ( sscanf ( V_32 [ 2 ] , L_5 , & V_3 -> V_39 ) != 1 ) {
V_30 -> error = L_6 ;
goto V_37;
}
if ( F_22 ( V_30 , V_32 [ 0 ] , F_23 ( V_30 -> V_40 ) ,
& V_3 -> V_41 ) ) {
V_30 -> error = L_7 ;
goto V_37;
}
V_3 -> V_42 = NULL ;
if ( V_31 == 3 )
goto V_43;
if ( sscanf ( V_32 [ 4 ] , L_3 , & V_33 ) != 1 ) {
V_30 -> error = L_8 ;
goto V_44;
}
V_3 -> V_45 = V_33 ;
if ( sscanf ( V_32 [ 5 ] , L_5 , & V_3 -> V_46 ) != 1 ) {
V_30 -> error = L_9 ;
goto V_44;
}
if ( F_22 ( V_30 , V_32 [ 3 ] , F_23 ( V_30 -> V_40 ) ,
& V_3 -> V_42 ) ) {
V_30 -> error = L_10 ;
goto V_44;
}
V_43:
V_3 -> V_26 = F_24 ( 128 , V_47 ) ;
if ( ! V_3 -> V_26 ) {
F_25 ( L_11 ) ;
goto V_48;
}
F_26 ( & V_3 -> V_8 , F_1 , ( unsigned long ) V_3 ) ;
F_27 ( & V_3 -> V_5 , V_5 ) ;
F_28 ( & V_3 -> V_49 ) ;
F_29 ( & V_3 -> V_7 ) ;
F_30 ( & V_3 -> V_50 , 1 ) ;
V_30 -> V_51 = 1 ;
V_30 -> V_52 = 1 ;
V_30 -> V_53 = V_3 ;
return 0 ;
V_48:
if ( V_3 -> V_42 )
F_31 ( V_30 , V_3 -> V_42 ) ;
V_44:
F_31 ( V_30 , V_3 -> V_41 ) ;
V_37:
F_32 ( V_3 ) ;
return - V_34 ;
}
static void F_33 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
F_34 ( V_4 ) ;
F_31 ( V_30 , V_3 -> V_41 ) ;
if ( V_3 -> V_42 )
F_31 ( V_30 , V_3 -> V_42 ) ;
F_35 ( V_3 -> V_26 ) ;
F_32 ( V_3 ) ;
}
static int F_36 ( struct V_2 * V_3 , int V_54 , struct V_9 * V_9 )
{
struct V_13 * V_14 ;
unsigned long V_6 = 0 ;
if ( ! V_54 || ! F_37 ( & V_3 -> V_50 ) )
return 1 ;
V_14 = F_38 ( V_3 -> V_26 , V_55 ) ;
V_14 -> V_23 = V_3 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_6 = V_6 = V_20 + ( V_54 * V_56 / 1000 ) ;
F_4 ( & V_19 ) ;
if ( F_15 ( V_9 ) == V_22 )
V_3 -> V_24 ++ ;
else
V_3 -> V_25 ++ ;
F_39 ( & V_14 -> V_21 , & V_3 -> V_49 ) ;
F_7 ( & V_19 ) ;
F_3 ( V_3 , V_6 ) ;
return 0 ;
}
static void F_40 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
F_30 ( & V_3 -> V_50 , 0 ) ;
F_41 ( & V_3 -> V_8 ) ;
F_8 ( F_10 ( V_3 , 1 ) ) ;
}
static void F_42 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
F_30 ( & V_3 -> V_50 , 1 ) ;
}
static int F_43 ( struct V_29 * V_30 , struct V_9 * V_9 ,
union V_57 * V_58 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
if ( ( F_15 ( V_9 ) == V_22 ) && ( V_3 -> V_42 ) ) {
V_9 -> V_59 = V_3 -> V_42 -> V_60 ;
if ( F_44 ( V_9 ) )
V_9 -> V_61 = V_3 -> V_45 +
F_45 ( V_30 , V_9 -> V_61 ) ;
return F_36 ( V_3 , V_3 -> V_46 , V_9 ) ;
}
V_9 -> V_59 = V_3 -> V_41 -> V_60 ;
V_9 -> V_61 = V_3 -> V_38 + F_45 ( V_30 , V_9 -> V_61 ) ;
return F_36 ( V_3 , V_3 -> V_39 , V_9 ) ;
}
static int F_46 ( struct V_29 * V_30 , T_1 type ,
char * V_62 , unsigned V_63 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
int V_64 = 0 ;
switch ( type ) {
case V_65 :
F_47 ( L_12 , V_3 -> V_25 , V_3 -> V_24 ) ;
break;
case V_66 :
F_47 ( L_13 , V_3 -> V_41 -> V_67 ,
( unsigned long long ) V_3 -> V_38 ,
V_3 -> V_39 ) ;
if ( V_3 -> V_42 )
F_47 ( L_14 , V_3 -> V_42 -> V_67 ,
( unsigned long long ) V_3 -> V_45 ,
V_3 -> V_46 ) ;
break;
}
return 0 ;
}
static int F_48 ( struct V_29 * V_30 ,
T_2 V_68 , void * V_1 )
{
struct V_2 * V_3 = V_30 -> V_53 ;
int V_69 = 0 ;
V_69 = V_68 ( V_30 , V_3 -> V_41 , V_3 -> V_38 , V_30 -> V_70 , V_1 ) ;
if ( V_69 )
goto V_43;
if ( V_3 -> V_42 )
V_69 = V_68 ( V_30 , V_3 -> V_42 , V_3 -> V_45 , V_30 -> V_70 , V_1 ) ;
V_43:
return V_69 ;
}
static int T_3 F_49 ( void )
{
int V_71 = - V_36 ;
V_4 = F_50 ( L_15 , V_72 , 0 ) ;
if ( ! V_4 ) {
F_25 ( L_16 ) ;
goto V_73;
}
V_47 = F_51 ( V_13 , 0 ) ;
if ( ! V_47 ) {
F_25 ( L_17 ) ;
goto V_74;
}
V_71 = F_52 ( & V_75 ) ;
if ( V_71 < 0 ) {
F_25 ( L_18 , V_71 ) ;
goto V_76;
}
return 0 ;
V_76:
F_53 ( V_47 ) ;
V_74:
F_54 ( V_4 ) ;
V_73:
return V_71 ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_75 ) ;
F_53 ( V_47 ) ;
F_54 ( V_4 ) ;
}
