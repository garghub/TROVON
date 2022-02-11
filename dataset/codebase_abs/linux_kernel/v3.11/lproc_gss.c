void F_1 ( int V_1 )
{
F_2 ( & V_2 . V_3 ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_1 > V_2 . V_5 )
V_2 . V_5 = V_1 ;
F_4 ( & V_2 . V_4 ) ;
}
void F_5 ( int V_6 , int V_7 )
{
F_6 ( V_6 >= 0 && V_6 <= 2 ) ;
if ( V_7 )
F_2 ( & V_2 . V_8 [ V_6 ] ) ;
else
F_2 ( & V_2 . V_9 [ V_6 ] ) ;
}
static int F_7 ( struct V_10 * V_11 , void * V_12 )
{
return F_8 ( V_11 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_9 ,
V_13 ,
V_14 ,
F_9 ( & V_2 . V_3 ) ,
V_2 . V_5 ,
F_9 ( & V_2 . V_8 [ 0 ] ) ,
F_9 ( & V_2 . V_8 [ 1 ] ) ,
F_9 ( & V_2 . V_8 [ 2 ] ) ,
F_9 ( & V_2 . V_9 [ 2 ] ) ) ;
}
static int F_10 ( struct V_15 * V_15 , const char * V_16 ,
T_1 V_17 , T_2 * V_18 )
{
int V_19 ;
V_19 = F_11 ( ( char * ) V_16 , V_17 ) ;
if ( V_19 ) {
F_6 ( V_19 < 0 ) ;
return V_19 ;
}
return V_17 ;
}
static int F_12 ( struct V_10 * V_11 , void * V_12 )
{
return F_8 ( V_11 , L_11 , V_20 ) ;
}
static int F_13 ( struct V_15 * V_15 , const char * V_16 ,
T_1 V_17 , T_2 * V_18 )
{
int V_21 , V_19 ;
V_19 = F_14 ( V_16 , V_17 , & V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_21 < 0 || V_21 > 4 )
return - V_22 ;
V_20 = V_21 ;
return V_17 ;
}
void F_15 ( void )
{
if ( V_23 ) {
F_16 ( & V_23 ) ;
V_23 = NULL ;
}
if ( V_24 ) {
F_16 ( & V_24 ) ;
V_24 = NULL ;
}
}
int F_17 ( void )
{
int V_19 ;
F_18 ( & V_2 . V_4 ) ;
V_24 = F_19 ( L_12 , V_25 ,
V_26 , NULL ) ;
if ( F_20 ( V_24 ) ) {
V_24 = NULL ;
GOTO ( V_27 , V_19 = F_21 ( V_24 ) ) ;
}
V_23 = F_19 ( L_13 , V_24 ,
V_28 , NULL ) ;
if ( F_20 ( V_23 ) ) {
V_23 = NULL ;
GOTO ( V_27 , V_19 = F_21 ( V_24 ) ) ;
}
return 0 ;
V_27:
F_22 ( L_14 , V_19 ) ;
F_15 () ;
return V_19 ;
}
