static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_5 , unsigned int * V_6 )
{
if ( V_4 > * V_6 )
return - V_7 ;
memcpy ( V_5 , V_3 , V_4 ) ;
* V_6 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_3 ( struct V_8 * V_9 , const T_1 * V_10 ,
unsigned int V_11 )
{
return 0 ;
}
static int F_4 ( struct V_8 * V_9 , T_1 * V_12 )
{
return 0 ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 )
{
return 0 ;
}
static int F_6 ( struct V_13 * V_2 , const T_1 * V_14 ,
unsigned int V_15 )
{ return 0 ; }
static int F_7 ( struct V_1 * V_2 , const T_1 * V_14 ,
unsigned int V_15 )
{ return 0 ; }
static void F_8 ( struct V_1 * V_2 , T_1 * V_5 , const T_1 * V_3 )
{
memcpy ( V_5 , V_3 , V_16 ) ;
}
static int F_9 ( struct V_17 * V_9 ,
struct V_18 * V_5 ,
struct V_18 * V_3 , unsigned int V_19 )
{
struct V_20 V_21 ;
int V_22 ;
F_10 ( & V_21 , V_5 , V_3 , V_19 ) ;
V_22 = F_11 ( V_9 , & V_21 ) ;
while ( V_21 . V_19 ) {
if ( V_21 . V_3 . V_23 . V_24 != V_21 . V_5 . V_23 . V_24 )
memcpy ( V_21 . V_5 . V_23 . V_24 , V_21 . V_3 . V_23 . V_24 ,
V_21 . V_19 ) ;
V_22 = F_12 ( V_9 , & V_21 , 0 ) ;
}
return V_22 ;
}
static int T_2 F_13 ( void )
{
int V_25 = 0 ;
V_25 = F_14 ( V_26 , F_15 ( V_26 ) ) ;
if ( V_25 < 0 )
goto V_12;
V_25 = F_16 ( & V_27 ) ;
if ( V_25 < 0 )
goto V_28;
return 0 ;
V_28:
F_17 ( V_26 , F_15 ( V_26 ) ) ;
V_12:
return V_25 ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_27 ) ;
F_17 ( V_26 , F_15 ( V_26 ) ) ;
}
