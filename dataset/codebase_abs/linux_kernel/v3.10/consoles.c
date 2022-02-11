static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
static const struct {
short V_4 ;
char V_5 ;
} V_6 [] = {
{ V_7 , 'E' } ,
{ V_8 , 'C' } ,
{ V_9 , 'B' } ,
{ V_10 , 'p' } ,
{ V_11 , 'b' } ,
{ V_12 , 'a' } ,
} ;
char V_13 [ F_2 ( V_6 ) + 1 ] ;
struct V_14 * V_15 = V_3 ;
unsigned int V_16 ;
int V_17 ;
T_1 V_18 = 0 ;
if ( V_15 -> V_19 ) {
const struct V_20 * V_21 ;
int V_22 ;
V_21 = V_15 -> V_19 ( V_15 , & V_22 ) ;
if ( V_21 ) {
V_18 = F_3 ( V_21 -> V_23 , V_21 -> V_24 ) ;
V_18 += V_22 ;
}
}
for ( V_16 = 0 ; V_16 < F_2 ( V_6 ) ; V_16 ++ )
V_13 [ V_16 ] = ( V_15 -> V_13 & V_6 [ V_16 ] . V_4 ) ?
V_6 [ V_16 ] . V_5 : ' ' ;
V_13 [ V_16 ] = 0 ;
F_4 ( V_2 , L_1 , V_15 -> V_5 , V_15 -> V_22 , & V_17 ) ;
V_17 = 21 - V_17 ;
if ( V_17 < 1 )
V_17 = 1 ;
F_4 ( V_2 , L_2 , V_17 , ' ' , V_15 -> V_25 ? 'R' : '-' ,
V_15 -> V_26 ? 'W' : '-' , V_15 -> V_27 ? 'U' : '-' ,
V_13 ) ;
if ( V_18 )
F_4 ( V_2 , L_3 , F_5 ( V_18 ) , F_6 ( V_18 ) ) ;
F_4 ( V_2 , L_4 ) ;
return 0 ;
}
static void * F_7 ( struct V_1 * V_2 , T_2 * V_28 )
{
struct V_14 * V_15 ;
T_2 V_29 = 0 ;
F_8 () ;
F_9 (con)
if ( V_29 ++ == * V_28 )
break;
return V_15 ;
}
static void * F_10 ( struct V_1 * V_2 , void * V_3 , T_2 * V_28 )
{
struct V_14 * V_15 = V_3 ;
++ * V_28 ;
return V_15 -> V_30 ;
}
static void F_11 ( struct V_1 * V_2 , void * V_3 )
{
F_12 () ;
}
static int F_13 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_14 ( V_32 , & V_33 ) ;
}
static int T_3 F_15 ( void )
{
F_16 ( L_5 , 0 , NULL , & V_34 ) ;
return 0 ;
}
