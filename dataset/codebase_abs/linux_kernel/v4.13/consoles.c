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
T_1 V_17 = 0 ;
if ( V_15 -> V_18 ) {
const struct V_19 * V_20 ;
int V_21 ;
V_20 = V_15 -> V_18 ( V_15 , & V_21 ) ;
if ( V_20 ) {
V_17 = F_3 ( V_20 -> V_22 , V_20 -> V_23 ) ;
V_17 += V_21 ;
}
}
for ( V_16 = 0 ; V_16 < F_2 ( V_6 ) ; V_16 ++ )
V_13 [ V_16 ] = ( V_15 -> V_13 & V_6 [ V_16 ] . V_4 ) ?
V_6 [ V_16 ] . V_5 : ' ' ;
V_13 [ V_16 ] = 0 ;
F_4 ( V_2 , 21 - 1 ) ;
F_5 ( V_2 , L_1 , V_15 -> V_5 , V_15 -> V_21 ) ;
F_6 ( V_2 , ' ' ) ;
F_5 ( V_2 , L_2 , V_15 -> V_24 ? 'R' : '-' ,
V_15 -> V_25 ? 'W' : '-' , V_15 -> V_26 ? 'U' : '-' ,
V_13 ) ;
if ( V_17 )
F_5 ( V_2 , L_3 , F_7 ( V_17 ) , F_8 ( V_17 ) ) ;
F_5 ( V_2 , L_4 ) ;
return 0 ;
}
static void * F_9 ( struct V_1 * V_2 , T_2 * V_27 )
{
struct V_14 * V_15 ;
T_2 V_28 = 0 ;
F_10 () ;
F_11 (con)
if ( V_28 ++ == * V_27 )
break;
return V_15 ;
}
static void * F_12 ( struct V_1 * V_2 , void * V_3 , T_2 * V_27 )
{
struct V_14 * V_15 = V_3 ;
++ * V_27 ;
return V_15 -> V_29 ;
}
static void F_13 ( struct V_1 * V_2 , void * V_3 )
{
F_14 () ;
}
static int F_15 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_16 ( V_31 , & V_32 ) ;
}
static int T_3 F_17 ( void )
{
F_18 ( L_5 , 0 , NULL , & V_33 ) ;
return 0 ;
}
