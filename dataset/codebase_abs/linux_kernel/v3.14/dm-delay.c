static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 -> V_4 , & V_3 -> V_5 ) ;
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
struct V_9 * V_9 = F_13 ( V_14 ,
sizeof( struct V_13 ) ) ;
F_14 ( & V_14 -> V_21 ) ;
F_15 ( & F_8 , V_9 ) ;
if ( ( F_16 ( V_9 ) == V_22 ) )
V_14 -> V_23 -> V_24 -- ;
else
V_14 -> V_23 -> V_25 -- ;
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
static void V_5 ( struct V_26 * V_27 )
{
struct V_2 * V_3 ;
V_3 = F_19 ( V_27 , struct V_2 , V_5 ) ;
F_8 ( F_10 ( V_3 , 0 ) ) ;
}
static int F_20 ( struct V_28 * V_29 , unsigned int V_30 , char * * V_31 )
{
struct V_2 * V_3 ;
unsigned long long V_32 ;
char V_33 ;
if ( V_30 != 3 && V_30 != 6 ) {
V_29 -> error = L_1 ;
return - V_34 ;
}
V_3 = F_21 ( sizeof( * V_3 ) , V_35 ) ;
if ( ! V_3 ) {
V_29 -> error = L_2 ;
return - V_36 ;
}
V_3 -> V_25 = V_3 -> V_24 = 0 ;
if ( sscanf ( V_31 [ 1 ] , L_3 , & V_32 , & V_33 ) != 1 ) {
V_29 -> error = L_4 ;
goto V_37;
}
V_3 -> V_38 = V_32 ;
if ( sscanf ( V_31 [ 2 ] , L_5 , & V_3 -> V_39 , & V_33 ) != 1 ) {
V_29 -> error = L_6 ;
goto V_37;
}
if ( F_22 ( V_29 , V_31 [ 0 ] , F_23 ( V_29 -> V_40 ) ,
& V_3 -> V_41 ) ) {
V_29 -> error = L_7 ;
goto V_37;
}
V_3 -> V_42 = NULL ;
if ( V_30 == 3 )
goto V_43;
if ( sscanf ( V_31 [ 4 ] , L_3 , & V_32 , & V_33 ) != 1 ) {
V_29 -> error = L_8 ;
goto V_44;
}
V_3 -> V_45 = V_32 ;
if ( sscanf ( V_31 [ 5 ] , L_5 , & V_3 -> V_46 , & V_33 ) != 1 ) {
V_29 -> error = L_9 ;
goto V_44;
}
if ( F_22 ( V_29 , V_31 [ 3 ] , F_23 ( V_29 -> V_40 ) ,
& V_3 -> V_42 ) ) {
V_29 -> error = L_10 ;
goto V_44;
}
V_43:
V_3 -> V_4 = F_24 ( L_11 , V_47 , 0 ) ;
if ( ! V_3 -> V_4 ) {
F_25 ( L_12 ) ;
goto V_48;
}
F_26 ( & V_3 -> V_8 , F_1 , ( unsigned long ) V_3 ) ;
F_27 ( & V_3 -> V_5 , V_5 ) ;
F_28 ( & V_3 -> V_49 ) ;
F_29 ( & V_3 -> V_7 ) ;
F_30 ( & V_3 -> V_50 , 1 ) ;
V_29 -> V_51 = 1 ;
V_29 -> V_52 = 1 ;
V_29 -> V_53 = sizeof( struct V_13 ) ;
V_29 -> V_54 = V_3 ;
return 0 ;
V_48:
if ( V_3 -> V_42 )
F_31 ( V_29 , V_3 -> V_42 ) ;
V_44:
F_31 ( V_29 , V_3 -> V_41 ) ;
V_37:
F_32 ( V_3 ) ;
return - V_34 ;
}
static void F_33 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
F_34 ( V_3 -> V_4 ) ;
F_31 ( V_29 , V_3 -> V_41 ) ;
if ( V_3 -> V_42 )
F_31 ( V_29 , V_3 -> V_42 ) ;
F_32 ( V_3 ) ;
}
static int F_35 ( struct V_2 * V_3 , int V_55 , struct V_9 * V_9 )
{
struct V_13 * V_14 ;
unsigned long V_6 = 0 ;
if ( ! V_55 || ! F_36 ( & V_3 -> V_50 ) )
return 1 ;
V_14 = F_37 ( V_9 , sizeof( struct V_13 ) ) ;
V_14 -> V_23 = V_3 ;
V_14 -> V_6 = V_6 = V_20 + ( V_55 * V_56 / 1000 ) ;
F_4 ( & V_19 ) ;
if ( F_16 ( V_9 ) == V_22 )
V_3 -> V_24 ++ ;
else
V_3 -> V_25 ++ ;
F_38 ( & V_14 -> V_21 , & V_3 -> V_49 ) ;
F_7 ( & V_19 ) ;
F_3 ( V_3 , V_6 ) ;
return 0 ;
}
static void F_39 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
F_30 ( & V_3 -> V_50 , 0 ) ;
F_40 ( & V_3 -> V_8 ) ;
F_8 ( F_10 ( V_3 , 1 ) ) ;
}
static void F_41 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
F_30 ( & V_3 -> V_50 , 1 ) ;
}
static int F_42 ( struct V_28 * V_29 , struct V_9 * V_9 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
if ( ( F_16 ( V_9 ) == V_22 ) && ( V_3 -> V_42 ) ) {
V_9 -> V_57 = V_3 -> V_42 -> V_58 ;
if ( F_43 ( V_9 ) )
V_9 -> V_59 . V_60 = V_3 -> V_45 +
F_44 ( V_29 , V_9 -> V_59 . V_60 ) ;
return F_35 ( V_3 , V_3 -> V_46 , V_9 ) ;
}
V_9 -> V_57 = V_3 -> V_41 -> V_58 ;
V_9 -> V_59 . V_60 = V_3 -> V_38 +
F_44 ( V_29 , V_9 -> V_59 . V_60 ) ;
return F_35 ( V_3 , V_3 -> V_39 , V_9 ) ;
}
static void F_45 ( struct V_28 * V_29 , T_1 type ,
unsigned V_61 , char * V_62 , unsigned V_63 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
int V_64 = 0 ;
switch ( type ) {
case V_65 :
F_46 ( L_13 , V_3 -> V_25 , V_3 -> V_24 ) ;
break;
case V_66 :
F_46 ( L_14 , V_3 -> V_41 -> V_67 ,
( unsigned long long ) V_3 -> V_38 ,
V_3 -> V_39 ) ;
if ( V_3 -> V_42 )
F_46 ( L_15 , V_3 -> V_42 -> V_67 ,
( unsigned long long ) V_3 -> V_45 ,
V_3 -> V_46 ) ;
break;
}
}
static int F_47 ( struct V_28 * V_29 ,
T_2 V_68 , void * V_1 )
{
struct V_2 * V_3 = V_29 -> V_54 ;
int V_69 = 0 ;
V_69 = V_68 ( V_29 , V_3 -> V_41 , V_3 -> V_38 , V_29 -> V_70 , V_1 ) ;
if ( V_69 )
goto V_43;
if ( V_3 -> V_42 )
V_69 = V_68 ( V_29 , V_3 -> V_42 , V_3 -> V_45 , V_29 -> V_70 , V_1 ) ;
V_43:
return V_69 ;
}
static int T_3 F_48 ( void )
{
int V_71 ;
V_71 = F_49 ( & V_72 ) ;
if ( V_71 < 0 ) {
F_25 ( L_16 , V_71 ) ;
goto V_73;
}
return 0 ;
V_73:
return V_71 ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_72 ) ;
}
