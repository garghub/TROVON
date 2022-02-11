int F_1 ( void )
{
int V_1 = 0 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
if ( V_4 == 0 && ! ( F_3 ( V_5 ) || F_3 ( V_6 ) ) ) {
V_1 = F_4 ( V_5 , V_6 ) ;
if ( V_1 )
F_5 ( L_1 ) ;
}
if ( ! V_1 )
V_4 ++ ;
F_6 ( & V_3 , V_2 ) ;
return V_1 ;
}
int F_7 ( void )
{
int V_1 = 0 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_8 ( ! V_4 ) ;
V_4 -- ;
if ( V_4 == 0 && ! ( F_3 ( V_5 ) || F_3 ( V_7 ) ) ) {
V_1 = F_4 ( V_5 , V_7 ) ;
if ( V_1 )
F_5 ( L_2 ) ;
}
F_6 ( & V_3 , V_2 ) ;
return V_1 ;
}
static struct V_8 * F_9 ( struct V_9 * V_10 ,
int V_11 ,
T_1 V_12 , int V_13 ,
struct V_14 * V_15 )
{
struct V_8 * V_16 ;
struct V_17 V_18 [] = {
F_10 ( V_12 , V_19 ) ,
F_11 ( V_13 ) ,
} ;
F_12 ( L_3 ,
V_11 , V_13 ) ;
V_16 = F_13 ( V_10 , L_4 , V_11 ,
V_18 , F_14 ( V_18 ) ,
V_15 , sizeof( * V_15 ) ) ;
if ( ! V_16 ) {
F_5 ( L_5 ,
V_11 ) ;
return NULL ;
}
return V_16 ;
}
int F_15 ( struct V_9 * V_10 )
{
struct V_8 * V_20 ;
F_12 ( L_6 , V_21 ) ;
F_16 ( & V_22 ) ;
F_12 ( L_7 ) ;
F_9 ( V_10 , 0 , V_23 , V_24 ,
& V_25 ) ;
V_20 = F_9 ( V_10 , 1 , V_26 , V_27 ,
& V_28 ) ;
F_9 ( V_10 , 2 , V_29 , V_30 ,
& V_31 ) ;
F_9 ( V_10 , 3 , V_32 , V_27 ,
& V_33 ) ;
if ( V_20 ) {
V_5 = F_17 ( & V_20 -> V_34 ) ;
if ( F_3 ( V_5 ) )
F_18 ( & V_20 -> V_34 , L_8 ) ;
else {
V_6 = F_19 ( V_5 ,
V_35 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( & V_20 -> V_34 ,
L_9 ) ;
}
V_7 = F_19 ( V_5 ,
V_36 ) ;
if ( F_3 ( V_7 ) )
F_18 ( & V_20 -> V_34 ,
L_10 ) ;
}
}
F_12 ( L_11 , V_21 ) ;
F_16 ( & V_37 ) ;
return 0 ;
}
