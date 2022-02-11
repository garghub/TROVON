static inline int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 = 0 ;
if ( V_3 & V_5 ) {
if ( V_3 & V_6 ) {
V_4 = F_2 () ;
if ( V_4 ) {
F_3 ( V_7 , L_1 ,
V_8 , V_4 ) ;
goto V_9;
}
}
if ( V_3 & V_10 ) {
if ( F_4 ( V_2 ) ) {
F_5 ( true ) ;
F_6 () ;
} else {
V_4 = - V_11 ;
F_3 ( V_7 , L_2 ,
V_8 , V_4 ) ;
goto V_9;
}
}
if ( V_3 & V_12 )
F_7 ( V_8 , __LINE__ ) ;
} else {
V_4 = - V_13 ;
F_3 ( V_7 , L_3 , V_8 ,
V_4 ) ;
}
V_9:
return V_4 ;
}
static T_1 F_8 ( struct V_14 * V_15 , char * V_16 )
{
V_17 . V_18 = F_9 () ;
return sprintf ( V_16 , L_4 , V_17 . V_18 ) ;
}
static T_1 F_10 ( struct V_14 * V_15 , const char * V_16 ,
T_2 V_19 )
{
if ( F_11 ( V_16 , 10 , & V_17 . V_18 )
|| V_17 . V_18 < 1
|| V_17 . V_18 > 9 ) {
return - V_20 ;
}
F_12 ( V_17 . V_18 ) ;
return V_19 ;
}
static T_1 F_13 ( struct V_14 * V_15 , char * V_16 )
{
V_17 . V_21 = F_14 () ;
return sprintf ( V_16 , L_5 , V_17 . V_21 ) ;
}
static T_1 F_15 ( struct V_14 * V_15 , const char * V_16 ,
T_2 V_19 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_11 ( V_16 , 10 , & V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_16 ( V_17 . V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_17 . V_21 = V_3 ;
return V_19 ;
}
static T_1 F_17 ( struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_6 , V_17 . V_22 ) ;
}
static T_1 F_18 ( struct V_14 * V_15 , const char * V_16 ,
T_2 V_19 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_11 ( V_16 , 10 , & V_3 ) ;
if ( V_4 )
return V_4 ;
V_17 . V_22 = V_3 ;
V_4 = F_1 ( V_17 . V_2 , V_17 . V_22 ) ;
if ( V_4 )
return V_4 ;
return V_19 ;
}
static int F_19 ( struct V_23 * V_15 )
{
int V_24 , V_4 = 0 ;
for ( V_24 = 0 ; V_24 < F_20 ( V_25 ) ; V_24 ++ )
V_4 |= F_21 ( & ( V_15 -> V_26 ) ,
& V_25 [ V_24 ] ) ;
return V_4 ;
}
static void F_22 ( struct V_23 * V_15 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_20 ( V_25 ) ; V_24 ++ )
F_23 ( & ( V_15 -> V_26 ) , & V_25 [ V_24 ] ) ;
}
int F_24 ( struct V_23 * V_15 , struct V_1 * V_2 )
{
int V_4 ;
V_17 . V_2 = V_2 ;
V_17 . V_15 = V_15 ;
V_4 = F_19 ( V_17 . V_15 ) ;
if ( V_4 ) {
F_3 ( V_7 , L_7 , V_4 ) ;
F_22 ( V_15 ) ;
}
return V_4 ;
}
void F_25 ( void )
{
F_22 ( V_17 . V_15 ) ;
}
