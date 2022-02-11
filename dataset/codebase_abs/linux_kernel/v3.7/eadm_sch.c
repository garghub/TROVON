static void F_1 ( int V_1 , void * V_2 , int V_3 )
{
if ( V_1 > V_4 -> V_1 )
return;
while ( V_3 > 0 ) {
F_2 ( V_4 , V_1 , V_2 , V_3 ) ;
V_3 -= V_4 -> V_5 ;
V_2 += V_4 -> V_5 ;
}
}
static void F_3 ( union V_6 * V_6 )
{
memset ( V_6 , 0 , sizeof( union V_6 ) ) ;
V_6 -> V_7 . V_8 = 1 ;
V_6 -> V_7 . V_9 = 1 ;
V_6 -> V_7 . V_10 = 1 ;
V_6 -> V_7 . V_11 = 1 ;
}
static int F_4 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
union V_6 * V_6 = & F_5 ( V_13 ) -> V_6 ;
int V_15 ;
F_3 ( V_6 ) ;
V_6 -> V_7 . V_14 = ( V_16 ) F_6 ( V_14 ) ;
V_6 -> V_7 . V_17 = ( V_16 ) ( V_18 ) V_13 ;
V_6 -> V_7 . V_19 = V_20 >> 4 ;
F_7 ( 6 , L_1 ) ;
F_1 ( 6 , & V_13 -> V_21 , sizeof( V_13 -> V_21 ) ) ;
V_15 = F_8 ( V_13 -> V_21 , V_6 ) ;
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
static int F_9 ( struct V_12 * V_13 )
{
int V_15 ;
V_15 = F_10 ( V_13 -> V_21 ) ;
if ( V_15 )
return - V_27 ;
V_13 -> V_22 . V_23 . V_7 . V_24 |= V_28 ;
return 0 ;
}
static void F_11 ( unsigned long V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 ;
F_12 ( V_13 -> V_29 ) ;
F_7 ( 1 , L_2 ) ;
F_1 ( 1 , & V_13 -> V_21 , sizeof( V_13 -> V_21 ) ) ;
if ( F_9 ( V_13 ) )
F_7 ( 0 , L_3 ) ;
F_13 ( V_13 -> V_29 ) ;
}
static void F_14 ( struct V_12 * V_13 , int V_30 )
{
struct V_31 * V_32 = F_5 ( V_13 ) ;
if ( V_30 == 0 ) {
F_15 ( & V_32 -> V_33 ) ;
return;
}
if ( F_16 ( & V_32 -> V_33 ) ) {
if ( F_17 ( & V_32 -> V_33 , V_34 + V_30 ) )
return;
}
V_32 -> V_33 . V_35 = F_11 ;
V_32 -> V_33 . V_2 = ( unsigned long ) V_13 ;
V_32 -> V_33 . V_30 = V_34 + V_30 ;
F_18 ( & V_32 -> V_33 ) ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_5 ( V_13 ) ;
struct V_36 * V_23 = & V_13 -> V_22 . V_23 . V_7 ;
struct V_37 * V_37 = (struct V_37 * ) & V_38 . V_37 ;
int error = 0 ;
F_7 ( 6 , L_4 ) ;
F_1 ( 6 , V_37 , sizeof( * V_37 ) ) ;
F_20 ( F_21 () ) . V_39 [ V_40 ] ++ ;
if ( ( V_23 -> V_41 & ( V_42 | V_43 ) )
&& V_23 -> V_44 == 1 && V_37 -> V_45 . V_7 . V_46 . V_47 )
error = - V_48 ;
if ( V_23 -> V_49 & V_50 )
error = - V_51 ;
F_14 ( V_13 , 0 ) ;
if ( V_32 -> V_52 != V_53 ) {
F_7 ( 1 , L_5 ) ;
F_1 ( 1 , V_37 , sizeof( * V_37 ) ) ;
V_32 -> V_52 = V_54 ;
F_22 ( V_13 , V_55 ) ;
return;
}
F_23 ( (struct V_14 * ) ( unsigned long ) V_23 -> V_14 , error ) ;
V_32 -> V_52 = V_56 ;
}
static struct V_12 * F_24 ( void )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_57 ;
F_25 ( & V_58 , V_57 ) ;
F_26 (private, &eadm_list, head) {
V_13 = V_32 -> V_13 ;
F_27 ( V_13 -> V_29 ) ;
if ( V_32 -> V_52 == V_56 ) {
V_32 -> V_52 = V_53 ;
F_28 ( & V_32 -> V_59 , & V_60 ) ;
F_29 ( V_13 -> V_29 ) ;
F_30 ( & V_58 , V_57 ) ;
return V_13 ;
}
F_29 ( V_13 -> V_29 ) ;
}
F_30 ( & V_58 , V_57 ) ;
return NULL ;
}
static int F_31 ( struct V_14 * V_14 )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_57 ;
int V_61 ;
V_13 = F_24 () ;
if ( ! V_13 )
return - V_26 ;
F_25 ( V_13 -> V_29 , V_57 ) ;
F_14 ( V_13 , V_62 ) ;
V_61 = F_4 ( V_13 , V_14 ) ;
if ( ! V_61 )
goto V_63;
F_14 ( V_13 , 0 ) ;
V_32 = F_5 ( V_13 ) ;
V_32 -> V_52 = V_54 ;
F_22 ( V_13 , V_55 ) ;
V_63:
F_30 ( V_13 -> V_29 , V_57 ) ;
return V_61 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_31 * V_32 ;
int V_61 ;
V_32 = F_33 ( sizeof( * V_32 ) , V_64 | V_65 ) ;
if ( ! V_32 )
return - V_66 ;
F_34 ( & V_32 -> V_59 ) ;
F_35 ( & V_32 -> V_33 ) ;
F_12 ( V_13 -> V_29 ) ;
F_36 ( V_13 , V_32 ) ;
V_32 -> V_52 = V_56 ;
V_32 -> V_13 = V_13 ;
V_13 -> V_67 = V_68 ;
V_61 = F_37 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
if ( V_61 ) {
F_36 ( V_13 , NULL ) ;
F_13 ( V_13 -> V_29 ) ;
F_38 ( V_32 ) ;
goto V_69;
}
F_13 ( V_13 -> V_29 ) ;
F_12 ( & V_58 ) ;
F_39 ( & V_32 -> V_59 , & V_60 ) ;
F_13 ( & V_58 ) ;
if ( F_40 ( & V_13 -> V_70 ) ) {
F_41 ( & V_13 -> V_70 , 0 ) ;
F_42 ( & V_13 -> V_70 . V_71 , V_72 ) ;
}
V_69:
return V_61 ;
}
static void F_43 ( struct V_12 * V_13 )
{
int V_61 ;
do {
F_12 ( V_13 -> V_29 ) ;
V_61 = F_44 ( V_13 ) ;
F_13 ( V_13 -> V_29 ) ;
} while ( V_61 == - V_26 );
}
static int F_45 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_5 ( V_13 ) ;
F_12 ( & V_58 ) ;
F_46 ( & V_32 -> V_59 ) ;
F_13 ( & V_58 ) ;
F_43 ( V_13 ) ;
F_12 ( V_13 -> V_29 ) ;
F_36 ( V_13 , NULL ) ;
F_13 ( V_13 -> V_29 ) ;
F_38 ( V_32 ) ;
return 0 ;
}
static void F_47 ( struct V_12 * V_13 )
{
F_43 ( V_13 ) ;
}
static int F_48 ( struct V_12 * V_13 )
{
return F_44 ( V_13 ) ;
}
static int F_49 ( struct V_12 * V_13 )
{
return F_37 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
}
static int F_50 ( struct V_12 * V_13 , int V_73 )
{
struct V_31 * V_32 ;
unsigned long V_57 ;
int V_61 = 0 ;
F_25 ( V_13 -> V_29 , V_57 ) ;
if ( ! F_51 ( & V_13 -> V_70 ) )
goto V_63;
if ( F_52 ( & V_13 -> V_74 ) )
goto V_63;
if ( F_53 ( V_13 ) ) {
F_22 ( V_13 , V_75 ) ;
goto V_63;
}
V_32 = F_5 ( V_13 ) ;
if ( V_32 -> V_52 == V_54 )
V_32 -> V_52 = V_56 ;
V_63:
F_30 ( V_13 -> V_29 , V_57 ) ;
return V_61 ;
}
static int T_1 F_54 ( void )
{
int V_61 ;
if ( ! V_76 . V_7 )
return - V_77 ;
V_4 = F_55 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
return - V_66 ;
F_56 ( V_4 , & V_78 ) ;
F_57 ( V_4 , 2 ) ;
F_58 ( V_68 ) ;
V_61 = F_59 ( & V_79 ) ;
if ( V_61 )
goto V_80;
F_60 ( & V_81 ) ;
return V_61 ;
V_80:
F_61 ( V_68 ) ;
F_62 ( V_4 ) ;
return V_61 ;
}
static void T_2 F_63 ( void )
{
F_64 ( & V_81 ) ;
F_65 ( & V_79 ) ;
F_61 ( V_68 ) ;
F_62 ( V_4 ) ;
}
