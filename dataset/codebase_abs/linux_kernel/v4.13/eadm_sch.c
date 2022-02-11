static void F_1 ( int V_1 , void * V_2 , int V_3 )
{
if ( ! F_2 ( V_4 , V_1 ) )
return;
while ( V_3 > 0 ) {
F_3 ( V_4 , V_1 , V_2 , V_3 ) ;
V_3 -= V_4 -> V_5 ;
V_2 += V_4 -> V_5 ;
}
}
static void F_4 ( union V_6 * V_6 )
{
memset ( V_6 , 0 , sizeof( union V_6 ) ) ;
V_6 -> V_7 . V_8 = 1 ;
V_6 -> V_7 . V_9 = 1 ;
V_6 -> V_7 . V_10 = 1 ;
V_6 -> V_7 . V_11 = 1 ;
}
static int F_5 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
union V_6 * V_6 = & F_6 ( V_13 ) -> V_6 ;
int V_15 ;
F_4 ( V_6 ) ;
V_6 -> V_7 . V_14 = ( V_16 ) F_7 ( V_14 ) ;
V_6 -> V_7 . V_17 = ( V_16 ) ( V_18 ) V_13 ;
V_6 -> V_7 . V_19 = V_20 >> 4 ;
F_8 ( 6 , L_1 ) ;
F_1 ( 6 , & V_13 -> V_21 , sizeof( V_13 -> V_21 ) ) ;
V_15 = F_9 ( V_13 -> V_21 , V_6 ) ;
switch ( V_15 ) {
case 0 :
V_13 -> V_22 . V_23 . V_7 . V_24 |= V_25 ;
break;
case 1 :
case 2 :
return - V_26 ;
case 3 :
return - V_27 ;
}
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
int V_15 ;
V_15 = F_11 ( V_13 -> V_21 ) ;
if ( V_15 )
return - V_27 ;
V_13 -> V_22 . V_23 . V_7 . V_24 |= V_28 ;
return 0 ;
}
static void F_12 ( unsigned long V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 ;
F_13 ( V_13 -> V_29 ) ;
F_8 ( 1 , L_2 ) ;
F_1 ( 1 , & V_13 -> V_21 , sizeof( V_13 -> V_21 ) ) ;
if ( F_10 ( V_13 ) )
F_8 ( 0 , L_3 ) ;
F_14 ( V_13 -> V_29 ) ;
}
static void F_15 ( struct V_12 * V_13 , int V_30 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
if ( V_30 == 0 ) {
F_16 ( & V_32 -> V_33 ) ;
return;
}
if ( F_17 ( & V_32 -> V_33 ) ) {
if ( F_18 ( & V_32 -> V_33 , V_34 + V_30 ) )
return;
}
V_32 -> V_33 . V_35 = F_12 ;
V_32 -> V_33 . V_2 = ( unsigned long ) V_13 ;
V_32 -> V_33 . V_30 = V_34 + V_30 ;
F_19 ( & V_32 -> V_33 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
struct V_36 * V_23 = & V_13 -> V_22 . V_23 . V_7 ;
struct V_37 * V_37 = F_21 ( & V_38 ) ;
T_1 error = V_39 ;
F_8 ( 6 , L_4 ) ;
F_1 ( 6 , V_37 , sizeof( * V_37 ) ) ;
F_22 ( V_40 ) ;
if ( ( V_23 -> V_41 & ( V_42 | V_43 ) )
&& V_23 -> V_44 == 1 && V_37 -> V_45 . V_7 . V_46 . V_47 )
error = V_48 ;
if ( V_23 -> V_49 & V_50 )
error = V_51 ;
F_15 ( V_13 , 0 ) ;
if ( V_32 -> V_52 != V_53 ) {
F_8 ( 1 , L_5 ) ;
F_1 ( 1 , V_37 , sizeof( * V_37 ) ) ;
V_32 -> V_52 = V_54 ;
F_23 ( V_13 , V_55 ) ;
return;
}
F_24 ( (struct V_14 * ) ( unsigned long ) V_23 -> V_14 , error ) ;
V_32 -> V_52 = V_56 ;
if ( V_32 -> V_57 )
F_25 ( V_32 -> V_57 ) ;
}
static struct V_12 * F_26 ( void )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_58 ;
F_27 ( & V_59 , V_58 ) ;
F_28 (private, &eadm_list, head) {
V_13 = V_32 -> V_13 ;
F_29 ( V_13 -> V_29 ) ;
if ( V_32 -> V_52 == V_56 ) {
V_32 -> V_52 = V_53 ;
F_30 ( & V_32 -> V_60 , & V_61 ) ;
F_31 ( V_13 -> V_29 ) ;
F_32 ( & V_59 , V_58 ) ;
return V_13 ;
}
F_31 ( V_13 -> V_29 ) ;
}
F_32 ( & V_59 , V_58 ) ;
return NULL ;
}
int F_33 ( struct V_14 * V_14 )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_58 ;
int V_62 ;
V_13 = F_26 () ;
if ( ! V_13 )
return - V_26 ;
F_27 ( V_13 -> V_29 , V_58 ) ;
F_15 ( V_13 , V_63 ) ;
V_62 = F_5 ( V_13 , V_14 ) ;
if ( ! V_62 )
goto V_64;
F_15 ( V_13 , 0 ) ;
V_32 = F_6 ( V_13 ) ;
V_32 -> V_52 = V_54 ;
F_23 ( V_13 , V_55 ) ;
V_64:
F_32 ( V_13 -> V_29 , V_58 ) ;
return V_62 ;
}
static int F_34 ( struct V_12 * V_13 )
{
struct V_31 * V_32 ;
int V_62 ;
V_32 = F_35 ( sizeof( * V_32 ) , V_65 | V_66 ) ;
if ( ! V_32 )
return - V_67 ;
F_36 ( & V_32 -> V_60 ) ;
F_37 ( & V_32 -> V_33 ) ;
F_13 ( V_13 -> V_29 ) ;
F_38 ( V_13 , V_32 ) ;
V_32 -> V_52 = V_56 ;
V_32 -> V_13 = V_13 ;
V_13 -> V_68 = V_69 ;
V_62 = F_39 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
if ( V_62 ) {
F_38 ( V_13 , NULL ) ;
F_14 ( V_13 -> V_29 ) ;
F_40 ( V_32 ) ;
goto V_70;
}
F_14 ( V_13 -> V_29 ) ;
F_13 ( & V_59 ) ;
F_41 ( & V_32 -> V_60 , & V_61 ) ;
F_14 ( & V_59 ) ;
if ( F_42 ( & V_13 -> V_71 ) ) {
F_43 ( & V_13 -> V_71 , 0 ) ;
F_44 ( & V_13 -> V_71 . V_72 , V_73 ) ;
}
V_70:
return V_62 ;
}
static void F_45 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
F_46 ( V_57 ) ;
int V_62 ;
F_13 ( V_13 -> V_29 ) ;
if ( V_32 -> V_52 != V_53 )
goto V_74;
if ( F_10 ( V_13 ) )
goto V_74;
V_32 -> V_57 = & V_57 ;
F_14 ( V_13 -> V_29 ) ;
F_47 ( & V_57 ) ;
F_13 ( V_13 -> V_29 ) ;
V_32 -> V_57 = NULL ;
V_74:
F_15 ( V_13 , 0 ) ;
do {
V_62 = F_48 ( V_13 ) ;
} while ( V_62 == - V_26 );
F_14 ( V_13 -> V_29 ) ;
}
static int F_49 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
F_13 ( & V_59 ) ;
F_50 ( & V_32 -> V_60 ) ;
F_14 ( & V_59 ) ;
F_45 ( V_13 ) ;
F_13 ( V_13 -> V_29 ) ;
F_38 ( V_13 , NULL ) ;
F_14 ( V_13 -> V_29 ) ;
F_40 ( V_32 ) ;
return 0 ;
}
static void F_51 ( struct V_12 * V_13 )
{
F_45 ( V_13 ) ;
}
static int F_52 ( struct V_12 * V_13 )
{
return F_48 ( V_13 ) ;
}
static int F_53 ( struct V_12 * V_13 )
{
return F_39 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
}
static int F_54 ( struct V_12 * V_13 , int V_75 )
{
struct V_31 * V_32 ;
unsigned long V_58 ;
F_27 ( V_13 -> V_29 , V_58 ) ;
if ( ! F_55 ( & V_13 -> V_71 ) )
goto V_64;
if ( F_56 ( & V_13 -> V_76 ) )
goto V_64;
if ( F_57 ( V_13 ) ) {
F_23 ( V_13 , V_77 ) ;
goto V_64;
}
V_32 = F_6 ( V_13 ) ;
if ( V_32 -> V_52 == V_54 )
V_32 -> V_52 = V_56 ;
V_64:
F_32 ( V_13 -> V_29 , V_58 ) ;
return 0 ;
}
static int T_2 F_58 ( void )
{
int V_62 ;
if ( ! V_78 . V_7 )
return - V_79 ;
V_4 = F_59 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
return - V_67 ;
F_60 ( V_4 , & V_80 ) ;
F_61 ( V_4 , 2 ) ;
F_62 ( V_69 ) ;
V_62 = F_63 ( & V_81 ) ;
if ( V_62 )
goto V_82;
return V_62 ;
V_82:
F_64 ( V_69 ) ;
F_65 ( V_4 ) ;
return V_62 ;
}
static void T_3 F_66 ( void )
{
F_67 ( & V_81 ) ;
F_64 ( V_69 ) ;
F_65 ( V_4 ) ;
}
