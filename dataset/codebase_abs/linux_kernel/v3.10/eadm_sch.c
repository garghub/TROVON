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
F_20 ( V_39 ) ;
if ( ( V_23 -> V_40 & ( V_41 | V_42 ) )
&& V_23 -> V_43 == 1 && V_37 -> V_44 . V_7 . V_45 . V_46 )
error = - V_47 ;
if ( V_23 -> V_48 & V_49 )
error = - V_50 ;
F_14 ( V_13 , 0 ) ;
if ( V_32 -> V_51 != V_52 ) {
F_7 ( 1 , L_5 ) ;
F_1 ( 1 , V_37 , sizeof( * V_37 ) ) ;
V_32 -> V_51 = V_53 ;
F_21 ( V_13 , V_54 ) ;
return;
}
F_22 ( (struct V_14 * ) ( unsigned long ) V_23 -> V_14 , error ) ;
V_32 -> V_51 = V_55 ;
}
static struct V_12 * F_23 ( void )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_56 ;
F_24 ( & V_57 , V_56 ) ;
F_25 (private, &eadm_list, head) {
V_13 = V_32 -> V_13 ;
F_26 ( V_13 -> V_29 ) ;
if ( V_32 -> V_51 == V_55 ) {
V_32 -> V_51 = V_52 ;
F_27 ( & V_32 -> V_58 , & V_59 ) ;
F_28 ( V_13 -> V_29 ) ;
F_29 ( & V_57 , V_56 ) ;
return V_13 ;
}
F_28 ( V_13 -> V_29 ) ;
}
F_29 ( & V_57 , V_56 ) ;
return NULL ;
}
static int F_30 ( struct V_14 * V_14 )
{
struct V_31 * V_32 ;
struct V_12 * V_13 ;
unsigned long V_56 ;
int V_60 ;
V_13 = F_23 () ;
if ( ! V_13 )
return - V_26 ;
F_24 ( V_13 -> V_29 , V_56 ) ;
F_14 ( V_13 , V_61 ) ;
V_60 = F_4 ( V_13 , V_14 ) ;
if ( ! V_60 )
goto V_62;
F_14 ( V_13 , 0 ) ;
V_32 = F_5 ( V_13 ) ;
V_32 -> V_51 = V_53 ;
F_21 ( V_13 , V_54 ) ;
V_62:
F_29 ( V_13 -> V_29 , V_56 ) ;
return V_60 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_31 * V_32 ;
int V_60 ;
V_32 = F_32 ( sizeof( * V_32 ) , V_63 | V_64 ) ;
if ( ! V_32 )
return - V_65 ;
F_33 ( & V_32 -> V_58 ) ;
F_34 ( & V_32 -> V_33 ) ;
F_12 ( V_13 -> V_29 ) ;
F_35 ( V_13 , V_32 ) ;
V_32 -> V_51 = V_55 ;
V_32 -> V_13 = V_13 ;
V_13 -> V_66 = V_67 ;
V_60 = F_36 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
if ( V_60 ) {
F_35 ( V_13 , NULL ) ;
F_13 ( V_13 -> V_29 ) ;
F_37 ( V_32 ) ;
goto V_68;
}
F_13 ( V_13 -> V_29 ) ;
F_12 ( & V_57 ) ;
F_38 ( & V_32 -> V_58 , & V_59 ) ;
F_13 ( & V_57 ) ;
if ( F_39 ( & V_13 -> V_69 ) ) {
F_40 ( & V_13 -> V_69 , 0 ) ;
F_41 ( & V_13 -> V_69 . V_70 , V_71 ) ;
}
V_68:
return V_60 ;
}
static void F_42 ( struct V_12 * V_13 )
{
int V_60 ;
do {
F_12 ( V_13 -> V_29 ) ;
V_60 = F_43 ( V_13 ) ;
F_13 ( V_13 -> V_29 ) ;
} while ( V_60 == - V_26 );
}
static int F_44 ( struct V_12 * V_13 )
{
struct V_31 * V_32 = F_5 ( V_13 ) ;
F_12 ( & V_57 ) ;
F_45 ( & V_32 -> V_58 ) ;
F_13 ( & V_57 ) ;
F_42 ( V_13 ) ;
F_12 ( V_13 -> V_29 ) ;
F_35 ( V_13 , NULL ) ;
F_13 ( V_13 -> V_29 ) ;
F_37 ( V_32 ) ;
return 0 ;
}
static void F_46 ( struct V_12 * V_13 )
{
F_42 ( V_13 ) ;
}
static int F_47 ( struct V_12 * V_13 )
{
return F_43 ( V_13 ) ;
}
static int F_48 ( struct V_12 * V_13 )
{
return F_36 ( V_13 , ( V_16 ) ( unsigned long ) V_13 ) ;
}
static int F_49 ( struct V_12 * V_13 , int V_72 )
{
struct V_31 * V_32 ;
unsigned long V_56 ;
int V_60 = 0 ;
F_24 ( V_13 -> V_29 , V_56 ) ;
if ( ! F_50 ( & V_13 -> V_69 ) )
goto V_62;
if ( F_51 ( & V_13 -> V_73 ) )
goto V_62;
if ( F_52 ( V_13 ) ) {
F_21 ( V_13 , V_74 ) ;
goto V_62;
}
V_32 = F_5 ( V_13 ) ;
if ( V_32 -> V_51 == V_53 )
V_32 -> V_51 = V_55 ;
V_62:
F_29 ( V_13 -> V_29 , V_56 ) ;
return V_60 ;
}
static int T_1 F_53 ( void )
{
int V_60 ;
if ( ! V_75 . V_7 )
return - V_76 ;
V_4 = F_54 ( L_6 , 16 , 1 , 16 ) ;
if ( ! V_4 )
return - V_65 ;
F_55 ( V_4 , & V_77 ) ;
F_56 ( V_4 , 2 ) ;
F_57 ( V_67 ) ;
V_60 = F_58 ( & V_78 ) ;
if ( V_60 )
goto V_79;
F_59 ( & V_80 ) ;
return V_60 ;
V_79:
F_60 ( V_67 ) ;
F_61 ( V_4 ) ;
return V_60 ;
}
static void T_2 F_62 ( void )
{
F_63 ( & V_80 ) ;
F_64 ( & V_78 ) ;
F_60 ( V_67 ) ;
F_61 ( V_4 ) ;
}
