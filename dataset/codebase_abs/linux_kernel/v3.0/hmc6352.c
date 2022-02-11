static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , & V_3 , 1 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_1 , V_3 ) ;
return V_4 ;
}
static int F_4 ( struct V_6 * V_5 , const char * V_7 , T_2 V_8 ,
const char * V_9 )
{
struct V_1 * V_2 = F_5 ( V_5 ) ;
int V_4 ;
unsigned long V_10 ;
if ( F_6 ( V_7 , 10 , & V_10 ) )
return - V_11 ;
if ( V_10 >= strlen ( V_9 ) )
return - V_11 ;
F_7 ( & V_12 ) ;
V_4 = F_1 ( V_2 , V_9 [ V_10 ] ) ;
F_8 ( & V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_8 ;
}
static T_3 F_9 ( struct V_6 * V_5 ,
struct V_13 * V_14 , const char * V_7 , T_2 V_8 )
{
return F_4 ( V_5 , V_7 , V_8 , L_2 ) ;
}
static T_3 F_10 ( struct V_6 * V_5 ,
struct V_13 * V_14 , const char * V_7 , T_2 V_8 )
{
return F_4 ( V_5 , V_7 , V_8 , L_3 ) ;
}
static T_3 F_11 ( struct V_6 * V_5 ,
struct V_13 * V_14 , char * V_7 )
{
struct V_1 * V_15 = F_5 ( V_5 ) ;
unsigned char V_16 [ 2 ] ;
int V_4 ;
F_7 ( & V_12 ) ;
V_4 = F_1 ( V_15 , 'A' ) ;
if ( V_4 != 1 ) {
F_8 ( & V_12 ) ;
return V_4 ;
}
F_12 ( 10 ) ;
V_4 = F_13 ( V_15 , V_16 , 2 ) ;
F_8 ( & V_12 ) ;
if ( V_4 < 0 ) {
F_3 ( V_5 , L_4 ) ;
return V_4 ;
}
V_4 = ( V_16 [ 0 ] << 8 ) | V_16 [ 1 ] ;
return sprintf ( V_7 , L_5 , V_4 / 10 , V_4 % 10 ) ;
}
static int F_14 ( struct V_1 * V_15 ,
const struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_15 ( & V_15 -> V_5 . V_20 , & V_21 ) ;
if ( V_19 ) {
F_16 ( & V_15 -> V_5 , L_6 ) ;
return V_19 ;
}
F_17 ( & V_15 -> V_5 , L_7 ,
V_15 -> V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_15 )
{
F_19 ( & V_15 -> V_5 . V_20 , & V_21 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_23 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_23 ) ;
}
