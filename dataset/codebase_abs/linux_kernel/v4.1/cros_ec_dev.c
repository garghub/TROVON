static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
static const char * const V_7 [] = {
L_1 , L_2 , L_3 , L_4 ,
} ;
struct V_8 V_9 = {
. V_10 = 0 ,
. V_11 = V_12 ,
. V_13 = { 0 } ,
. V_14 = 0 ,
. V_15 = { 0 } ,
. V_16 = sizeof( * V_6 ) ,
} ;
int V_17 ;
V_17 = F_2 ( V_2 , & V_9 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_9 . V_18 != V_19 ) {
snprintf ( V_3 , V_4 ,
L_5 ,
V_20 , V_9 . V_18 ) ;
return 0 ;
}
V_6 = (struct V_5 * ) V_9 . V_15 ;
if ( V_6 -> V_21 >= F_3 ( V_7 ) )
V_6 -> V_21 = 3 ;
snprintf ( V_3 , V_4 , L_6 , V_20 ,
V_6 -> V_22 , V_6 -> V_23 ,
V_7 [ V_6 -> V_21 ] ) ;
return 0 ;
}
static int F_4 ( struct V_24 * V_24 , struct V_25 * V_26 )
{
V_26 -> V_27 = F_5 ( V_24 -> V_28 ,
struct V_1 , V_29 ) ;
return 0 ;
}
static int F_6 ( struct V_24 * V_24 , struct V_25 * V_26 )
{
return 0 ;
}
static T_1 F_7 ( struct V_25 * V_26 , char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
char V_9 [ sizeof( struct V_5 ) +
sizeof( V_20 ) ] ;
T_3 V_33 ;
int V_17 ;
if ( * V_32 != 0 )
return 0 ;
V_17 = F_1 ( V_2 , V_9 , sizeof( V_9 ) ) ;
if ( V_17 )
return V_17 ;
V_33 = F_8 ( V_31 , strlen ( V_9 ) ) ;
if ( F_9 ( V_30 , V_9 , V_33 ) )
return - V_34 ;
* V_32 = V_33 ;
return V_33 ;
}
static long F_10 ( struct V_1 * V_2 , void T_2 * V_35 )
{
long V_17 ;
struct V_8 V_36 = { } ;
if ( F_11 ( & V_36 , V_35 , sizeof( V_36 ) ) )
return - V_34 ;
V_17 = F_2 ( V_2 , & V_36 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( F_9 ( V_35 , & V_36 , sizeof( V_36 ) ) )
return - V_34 ;
return 0 ;
}
static long F_12 ( struct V_1 * V_2 , void T_2 * V_35 )
{
struct V_37 V_38 = { } ;
long V_39 ;
if ( ! V_2 -> V_40 )
return - V_41 ;
if ( F_11 ( & V_38 , V_35 , sizeof( V_38 ) ) )
return - V_34 ;
V_39 = V_2 -> V_40 ( V_2 , V_38 . V_32 , V_38 . V_42 , V_38 . V_30 ) ;
if ( V_39 <= 0 )
return V_39 ;
if ( F_9 ( ( void T_2 * ) V_35 , & V_38 , sizeof( V_38 ) ) )
return - V_34 ;
return 0 ;
}
static long F_13 ( struct V_25 * V_26 , unsigned int V_43 ,
unsigned long V_35 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
if ( F_14 ( V_43 ) != V_44 )
return - V_41 ;
switch ( V_43 ) {
case V_45 :
return F_10 ( V_2 , ( void T_2 * ) V_35 ) ;
case V_46 :
return F_12 ( V_2 , ( void T_2 * ) V_35 ) ;
}
return - V_41 ;
}
static int F_15 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_16 ( V_48 -> V_49 . V_50 ) ;
int V_51 = - V_41 ;
T_5 V_52 = F_17 ( V_53 , 0 ) ;
F_18 ( & V_2 -> V_29 , & V_54 ) ;
V_51 = F_19 ( & V_2 -> V_29 , V_52 , 1 ) ;
if ( V_51 ) {
F_20 ( & V_48 -> V_49 , L_7 ) ;
return V_51 ;
}
V_2 -> V_55 = F_21 ( V_56 , NULL , V_52 , V_2 ,
V_57 ) ;
if ( F_22 ( V_2 -> V_55 ) ) {
V_51 = F_23 ( V_2 -> V_55 ) ;
F_20 ( & V_48 -> V_49 , L_8 ) ;
F_24 ( & V_2 -> V_29 ) ;
return V_51 ;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_16 ( V_48 -> V_49 . V_50 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_56 , F_17 ( V_53 , 0 ) ) ;
F_24 ( & V_2 -> V_29 ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
int V_17 ;
T_5 V_49 = 0 ;
V_56 = F_32 ( V_58 , L_9 ) ;
if ( F_22 ( V_56 ) ) {
F_33 ( V_57 L_10 ) ;
return F_23 ( V_56 ) ;
}
V_17 = F_34 ( & V_49 , 0 , V_59 , V_57 ) ;
if ( V_17 < 0 ) {
F_33 ( V_57 L_11 ) ;
goto V_60;
}
V_53 = F_35 ( V_49 ) ;
V_17 = F_36 ( & V_61 ) ;
if ( V_17 < 0 ) {
F_37 ( V_57 L_12 , V_17 ) ;
goto V_62;
}
return 0 ;
V_62:
F_38 ( F_17 ( V_53 , 0 ) , V_59 ) ;
V_60:
F_39 ( V_56 ) ;
return V_17 ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_61 ) ;
F_42 ( V_53 , V_57 ) ;
F_39 ( V_56 ) ;
}
