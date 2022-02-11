static unsigned char * F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 = 0x0 ;
unsigned char * V_4 = F_2 ( V_5 , V_6 ) ;
struct V_7 V_8 [] = {
{
. V_9 = V_10 ,
. V_11 = 0 ,
. V_12 = 1 ,
. V_4 = & V_3 ,
} , {
. V_9 = V_10 ,
. V_11 = V_13 ,
. V_12 = V_5 ,
. V_4 = V_4 ,
}
} ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_14 , L_1
L_2 ) ;
return NULL ;
}
if ( F_4 ( V_2 , V_8 , 2 ) == 2 )
return V_4 ;
F_3 ( & V_2 -> V_14 , L_3 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
unsigned char * F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned char * V_17 = NULL ;
int V_18 , V_19 ;
V_16 -> V_20 ( V_16 -> V_21 , 1 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_16 -> V_22 ( V_16 -> V_21 , 1 ) ;
F_7 ( 13 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 1 ) ;
for ( V_19 = 0 ; V_19 < 5 ; V_19 ++ ) {
F_7 ( 10 ) ;
if ( V_16 -> V_23 ( V_16 -> V_21 ) )
break;
}
if ( V_19 == 5 )
continue;
V_16 -> V_22 ( V_16 -> V_21 , 0 ) ;
F_7 ( 15 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 0 ) ;
F_7 ( 15 ) ;
V_16 -> V_22 ( V_16 -> V_21 , 1 ) ;
F_7 ( 15 ) ;
V_17 = F_1 ( V_2 ) ;
V_16 -> V_22 ( V_16 -> V_21 , 0 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 0 ) ;
F_7 ( 15 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 1 ) ;
for ( V_19 = 0 ; V_19 < 10 ; V_19 ++ ) {
F_7 ( 10 ) ;
if ( V_16 -> V_23 ( V_16 -> V_21 ) )
break;
}
V_16 -> V_22 ( V_16 -> V_21 , 1 ) ;
F_7 ( 15 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 0 ) ;
V_16 -> V_22 ( V_16 -> V_21 , 0 ) ;
if ( V_17 )
break;
}
V_16 -> V_22 ( V_16 -> V_21 , 1 ) ;
V_16 -> V_20 ( V_16 -> V_21 , 1 ) ;
V_2 -> V_24 |= V_25 ;
return V_17 ;
}
