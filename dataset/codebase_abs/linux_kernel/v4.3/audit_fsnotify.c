static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_5 , struct V_1 , V_5 ) ;
F_1 ( V_2 ) ;
}
char * F_5 ( struct V_1 * V_5 )
{
return V_5 -> V_3 ;
}
int F_6 ( struct V_1 * V_5 , unsigned long V_6 , T_1 V_7 )
{
if ( V_5 -> V_6 == V_8 )
return 0 ;
return ( V_5 -> V_6 == V_6 ) && ( V_5 -> V_7 == V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_9 * V_9 )
{
V_2 -> V_7 = V_9 ? V_9 -> V_10 -> V_11 : V_12 ;
V_2 -> V_6 = V_9 ? V_9 -> V_13 : V_8 ;
}
struct V_1 * F_8 ( struct V_14 * V_15 , char * V_16 , int V_17 )
{
struct V_1 * V_2 ;
struct V_3 V_3 ;
struct V_18 * V_18 ;
struct V_9 * V_9 ;
int V_19 ;
if ( V_16 [ 0 ] != '/' || V_16 [ V_17 - 1 ] == '/' )
return F_9 ( - V_20 ) ;
V_18 = F_10 ( V_16 , & V_3 ) ;
if ( F_11 ( V_18 ) )
return ( void * ) V_18 ;
V_9 = V_3 . V_18 -> V_21 ;
F_12 ( & V_9 -> V_22 ) ;
V_2 = F_13 ( sizeof( * V_2 ) , V_23 ) ;
if ( F_14 ( ! V_2 ) ) {
V_2 = F_9 ( - V_24 ) ;
goto V_25;
}
F_15 ( & V_2 -> V_5 , F_3 ) ;
V_2 -> V_5 . V_26 = V_27 ;
V_2 -> V_3 = V_16 ;
F_7 ( V_2 , V_18 -> V_21 ) ;
V_2 -> V_28 = V_15 ;
V_19 = F_16 ( & V_2 -> V_5 , V_29 , V_9 , NULL , true ) ;
if ( V_19 < 0 ) {
F_1 ( V_2 ) ;
V_2 = F_9 ( V_19 ) ;
}
V_25:
F_17 ( V_18 ) ;
F_18 ( & V_3 ) ;
return V_2 ;
}
static void F_19 ( struct V_1 * V_2 , char * V_30 )
{
struct V_31 * V_32 ;
struct V_14 * V_28 = V_2 -> V_28 ;
if ( ! V_33 )
return;
V_32 = F_20 ( NULL , V_34 , V_35 ) ;
if ( F_14 ( ! V_32 ) )
return;
F_21 ( V_32 , L_1 ,
F_22 ( & V_36 , F_23 ( V_37 ) ) ,
F_24 ( V_37 ) ) ;
F_25 ( V_32 , V_30 ) ;
F_21 ( V_32 , L_2 ) ;
F_26 ( V_32 , V_2 -> V_3 ) ;
F_27 ( V_32 , V_28 -> V_38 ) ;
F_21 ( V_32 , L_3 , V_28 -> V_39 ) ;
F_28 ( V_32 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_5 , V_29 ) ;
F_31 ( & V_2 -> V_5 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_5 = V_15 -> V_40 ;
F_29 ( V_5 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_28 = V_2 -> V_28 ;
struct V_41 * V_42 = F_4 ( V_28 , struct V_41 , V_28 ) ;
F_19 ( V_2 , L_4 ) ;
F_34 ( V_42 ) ;
}
static int F_35 ( struct V_43 * V_44 ,
struct V_9 * V_45 ,
struct V_4 * V_46 ,
struct V_4 * V_47 ,
T_2 V_26 , void * V_48 , int V_49 ,
const unsigned char * V_50 , T_2 V_51 )
{
struct V_1 * V_2 ;
struct V_9 * V_9 = NULL ;
V_2 = F_4 ( V_46 , struct V_1 , V_5 ) ;
F_36 ( V_44 != V_29 ) ;
switch ( V_49 ) {
case ( V_52 ) :
V_9 = ( (struct V_3 * ) V_48 ) -> V_18 -> V_21 ;
break;
case ( V_53 ) :
V_9 = (struct V_9 * ) V_48 ;
break;
default:
F_37 () ;
return 0 ;
} ;
if ( V_26 & ( V_54 | V_55 | V_56 | V_57 ) ) {
if ( F_38 ( V_50 , V_2 -> V_3 , V_58 ) )
return 0 ;
F_7 ( V_2 , V_9 ) ;
} else if ( V_26 & ( V_59 | V_60 | V_61 ) )
F_33 ( V_2 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
V_29 = F_40 ( & V_62 ) ;
if ( F_11 ( V_29 ) ) {
V_29 = NULL ;
F_41 ( L_5 ) ;
}
return 0 ;
}
