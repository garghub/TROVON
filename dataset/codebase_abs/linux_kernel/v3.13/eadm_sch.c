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
struct V_37 * V_37 = (struct V_37 * ) & V_38 . V_37 ;
int error = 0 ;
F_8 ( 6 , L_4 ) ;
F_1 ( 6 , V_37 , sizeof( * V_37 ) ) ;
F_21 ( V_39 ) ;
if ( ( V_23 -> V_40 & ( V_41 | V_42 ) )
&& V_23 -> V_43 == 1 && V_37 -> V_44 . V_7 . V_45 . V_46 )
error = - V_47 ;
if ( V_23 -> V_48 & V_49 )
error = - V_50 ;
F_15 ( V_13 , 0 ) ;
if ( V_32 -> V_51 != V_52 ) {
F_8 ( 1 , L_5 ) ;
F_1 ( 1 , V_37 , sizeof( * V_37 ) ) ;
V_32 -> V_51 = V_53 ;
F_22 ( V_13 , V_54 ) ;
return;
}
F_23 ( (struct V_14 * ) ( unsigned long ) V_23 -> V_14 , error ) ;
V_32 -> V_51 = V_55 ;
if ( V_32 -> V_56 )
F_24 ( V_32 -> V_56 ) ;
}
static struct V_12 * F_25 ( void )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_57 ;
F_26 ( & V_58 , V_57 ) ;
F_27 (private, &eadm_list, head) {
V_13 = V_32 -> V_13 ;
F_28 ( V_13 -> V_29 ) ;
if ( V_32 -> V_51 == V_55 ) {
V_32 -> V_51 = V_52 ;
F_29 ( & V_32 -> V_59 , & V_60 ) ;
F_30 ( V_13 -> V_29 ) ;
F_31 ( & V_58 , V_57 ) ;
return V_13 ;
}
F_30 ( V_13 -> V_29 ) ;
}
F_31 ( & V_58 , V_57 ) ;
return NULL ;
}
int F_32 ( struct V_14 * V_14 )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_57 ;
int V_61 ;
V_13 = F_25 () ;
if ( ! V_13 )
return - V_26 ;
F_26 ( V_13 -> V_29 , V_57 ) ;
F_15 ( V_13 , V_62 ) ;
V_61 = F_5 ( V_13 , V_14 ) ;
if ( ! V_61 )
goto V_63;
F_15 ( V_13 , 0 ) ;
V_32 = F_6 ( V_13 ) ;
V_32 -> V_51 = V_53 ;
F_22 ( V_13 , V_54 ) ;
V_63:
F_31 ( V_13 -> V_29 , V_57 ) ;
return V_61 ;
}
static int F_33 ( struct V_12 * V_13 )
{
struct V_31 * V_32 ;
int V_61 ;
V_32 = F_34 ( sizeof( * V_32 ) , V_64 | V_65 ) ;
if ( ! V_32 )
return - V_66 ;
F_35 ( & V_32 -> V_59 ) ;
F_36 ( & V_32 -> V_33 ) ;
F_13 ( V_13 -> V_29 ) ;
F_37 ( V_13 , V_32 ) ;
V_32 -> V_51 = V_55 ;
V_32 -> V_13 = V_13 ;
V_13 -> V_67 = V_68 ;
V_61 = F_38 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
if ( V_61 ) {
F_37 ( V_13 , NULL ) ;
F_14 ( V_13 -> V_29 ) ;
F_39 ( V_32 ) ;
goto V_69;
}
F_14 ( V_13 -> V_29 ) ;
F_13 ( & V_58 ) ;
F_40 ( & V_32 -> V_59 , & V_60 ) ;
F_14 ( & V_58 ) ;
if ( F_41 ( & V_13 -> V_70 ) ) {
F_42 ( & V_13 -> V_70 , 0 ) ;
F_43 ( & V_13 -> V_70 . V_71 , V_72 ) ;
}
V_69:
return V_61 ;
}
static void F_44 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
F_45 ( V_56 ) ;
int V_61 ;
F_13 ( V_13 -> V_29 ) ;
if ( V_32 -> V_51 != V_52 )
goto V_73;
if ( F_10 ( V_13 ) )
goto V_73;
V_32 -> V_56 = & V_56 ;
F_14 ( V_13 -> V_29 ) ;
F_46 ( & V_56 ) ;
F_13 ( V_13 -> V_29 ) ;
V_32 -> V_56 = NULL ;
V_73:
F_15 ( V_13 , 0 ) ;
do {
V_61 = F_47 ( V_13 ) ;
} while ( V_61 == - V_26 );
F_14 ( V_13 -> V_29 ) ;
}
static int F_48 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_6 ( V_13 ) ;
F_13 ( & V_58 ) ;
F_49 ( & V_32 -> V_59 ) ;
F_14 ( & V_58 ) ;
F_44 ( V_13 ) ;
F_13 ( V_13 -> V_29 ) ;
F_37 ( V_13 , NULL ) ;
F_14 ( V_13 -> V_29 ) ;
F_39 ( V_32 ) ;
return 0 ;
}
static void F_50 ( struct V_12 * V_13 )
{
F_44 ( V_13 ) ;
}
static int F_51 ( struct V_12 * V_13 )
{
return F_47 ( V_13 ) ;
}
static int F_52 ( struct V_12 * V_13 )
{
return F_38 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
}
static int F_53 ( struct V_12 * V_13 , int V_74 )
{
struct V_31 * V_32 ;
unsigned long V_57 ;
int V_61 = 0 ;
F_26 ( V_13 -> V_29 , V_57 ) ;
if ( ! F_54 ( & V_13 -> V_70 ) )
goto V_63;
if ( F_55 ( & V_13 -> V_75 ) )
goto V_63;
if ( F_56 ( V_13 ) ) {
F_22 ( V_13 , V_76 ) ;
goto V_63;
}
V_32 = F_6 ( V_13 ) ;
if ( V_32 -> V_51 == V_53 )
V_32 -> V_51 = V_55 ;
V_63:
F_31 ( V_13 -> V_29 , V_57 ) ;
return V_61 ;
}
static int T_1 F_57 ( void )
{
int V_61 ;
if ( ! V_77 . V_7 )
return - V_78 ;
V_4 = F_58 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
return - V_66 ;
F_59 ( V_4 , & V_79 ) ;
F_60 ( V_4 , 2 ) ;
F_61 ( V_68 ) ;
V_61 = F_62 ( & V_80 ) ;
if ( V_61 )
goto V_81;
return V_61 ;
V_81:
F_63 ( V_68 ) ;
F_64 ( V_4 ) ;
return V_61 ;
}
static void T_2 F_65 ( void )
{
F_66 ( & V_80 ) ;
F_63 ( V_68 ) ;
F_64 ( V_4 ) ;
}
