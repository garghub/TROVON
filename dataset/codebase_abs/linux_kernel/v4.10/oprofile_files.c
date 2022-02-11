static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
return F_2 ( F_3 ( V_5 ) ,
V_2 , V_3 , V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 , char const T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned long V_6 ;
int V_7 ;
if ( * V_4 )
return - V_8 ;
V_7 = F_5 ( & V_6 , V_2 , V_3 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_7 = F_6 ( V_6 ) ;
if ( V_7 )
return V_7 ;
return V_3 ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
return F_2 ( V_9 , V_2 , V_3 ,
V_4 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 , char const T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
unsigned long V_6 ;
int V_7 ;
if ( * V_4 )
return - V_8 ;
if ( ! V_10 . V_11 )
return - V_8 ;
V_7 = F_5 ( & V_6 , V_2 , V_3 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_7 = F_9 ( & V_9 , V_6 ) ;
if ( V_7 )
return V_7 ;
return V_3 ;
}
static T_1 F_10 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
return F_2 ( sizeof( void * ) , V_2 , V_3 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
return F_12 ( V_10 . V_12 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
return F_2 ( V_13 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 , char const T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
unsigned long V_6 ;
int V_7 ;
if ( * V_4 )
return - V_8 ;
V_7 = F_5 ( & V_6 , V_2 , V_3 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_7 = 0 ;
if ( V_6 )
V_7 = F_15 () ;
else
F_16 () ;
if ( V_7 )
return V_7 ;
return V_3 ;
}
static T_1 F_17 ( struct V_1 * V_1 , char const T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
F_18 () ;
return V_3 ;
}
void F_19 ( struct V_14 * V_15 )
{
V_16 = V_17 ;
V_18 = V_19 ;
V_20 = V_21 ;
V_5 = F_20 ( V_22 ) ;
F_21 ( V_15 , L_1 , & V_23 ) ;
F_22 ( V_15 , L_2 , & V_24 , 0666 ) ;
F_21 ( V_15 , L_3 , & V_25 ) ;
F_23 ( V_15 , L_4 , & V_16 ) ;
F_23 ( V_15 , L_5 , & V_20 ) ;
F_23 ( V_15 , L_6 , & V_18 ) ;
F_21 ( V_15 , L_7 , & V_26 ) ;
F_21 ( V_15 , L_8 , & V_27 ) ;
F_21 ( V_15 , L_9 , & V_28 ) ;
#ifdef F_24
F_21 ( V_15 , L_10 , & V_29 ) ;
#endif
F_25 ( V_15 ) ;
if ( V_10 . V_30 )
V_10 . V_30 ( V_15 ) ;
}
