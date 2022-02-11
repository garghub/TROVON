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
const struct V_9 * V_9 )
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
F_12 ( V_9 ) ;
V_2 = F_13 ( sizeof( * V_2 ) , V_22 ) ;
if ( F_14 ( ! V_2 ) ) {
V_2 = F_9 ( - V_23 ) ;
goto V_24;
}
F_15 ( & V_2 -> V_5 , F_3 ) ;
V_2 -> V_5 . V_25 = V_26 ;
V_2 -> V_3 = V_16 ;
F_7 ( V_2 , V_18 -> V_21 ) ;
V_2 -> V_27 = V_15 ;
V_19 = F_16 ( & V_2 -> V_5 , V_28 , V_9 , NULL , true ) ;
if ( V_19 < 0 ) {
F_1 ( V_2 ) ;
V_2 = F_9 ( V_19 ) ;
}
V_24:
F_17 ( V_18 ) ;
F_18 ( & V_3 ) ;
return V_2 ;
}
static void F_19 ( struct V_1 * V_2 , char * V_29 )
{
struct V_30 * V_31 ;
struct V_14 * V_27 = V_2 -> V_27 ;
if ( ! V_32 )
return;
V_31 = F_20 ( NULL , V_33 , V_34 ) ;
if ( F_14 ( ! V_31 ) )
return;
F_21 ( V_31 , L_1 ,
F_22 ( & V_35 , F_23 ( V_36 ) ) ,
F_24 ( V_36 ) , V_29 ) ;
F_21 ( V_31 , L_2 ) ;
F_25 ( V_31 , V_2 -> V_3 ) ;
F_26 ( V_31 , V_27 -> V_37 ) ;
F_21 ( V_31 , L_3 , V_27 -> V_38 ) ;
F_27 ( V_31 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_5 , V_28 ) ;
F_30 ( & V_2 -> V_5 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_5 = V_15 -> V_39 ;
F_28 ( V_5 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_27 = V_2 -> V_27 ;
struct V_40 * V_41 = F_4 ( V_27 , struct V_40 , V_27 ) ;
F_19 ( V_2 , L_4 ) ;
F_33 ( V_41 ) ;
}
static int F_34 ( struct V_42 * V_43 ,
struct V_9 * V_44 ,
struct V_4 * V_45 ,
struct V_4 * V_46 ,
T_2 V_25 , const void * V_47 , int V_48 ,
const unsigned char * V_49 , T_2 V_50 )
{
struct V_1 * V_2 ;
const struct V_9 * V_9 = NULL ;
V_2 = F_4 ( V_45 , struct V_1 , V_5 ) ;
F_35 ( V_43 != V_28 ) ;
switch ( V_48 ) {
case ( V_51 ) :
V_9 = ( ( const struct V_3 * ) V_47 ) -> V_18 -> V_21 ;
break;
case ( V_52 ) :
V_9 = ( const struct V_9 * ) V_47 ;
break;
default:
F_36 () ;
return 0 ;
} ;
if ( V_25 & ( V_53 | V_54 | V_55 | V_56 ) ) {
if ( F_37 ( V_49 , V_2 -> V_3 , V_57 ) )
return 0 ;
F_7 ( V_2 , V_9 ) ;
} else if ( V_25 & ( V_58 | V_59 | V_60 ) )
F_32 ( V_2 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
V_28 = F_39 ( & V_61 ) ;
if ( F_11 ( V_28 ) ) {
V_28 = NULL ;
F_40 ( L_5 ) ;
}
return 0 ;
}
