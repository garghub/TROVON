bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 100 ;
while ( -- V_4 ) {
V_3 = F_2 ( V_2 -> V_5 +
V_6 ) ;
if ( V_3 & 0x01 )
break;
F_3 ( 500 , 1000 ) ;
}
if ( V_4 == 0 ) {
F_4 ( L_1 , V_7 ) ;
return false ;
} else {
return true ;
}
}
void F_5 ( struct V_1 * V_2 , int V_8 )
{
F_6 ( L_2 , V_8 ) ;
if ( V_8 ) {
F_7 ( V_2 -> V_5 + V_9 ,
V_10 | V_11 ) ;
F_8 () ;
F_3 ( 500 , 1000 ) ;
F_7 ( V_2 -> V_5 + V_9 , 0x000 ) ;
F_7 ( V_2 -> V_5 + V_12 , 0x3f ) ;
F_7 ( V_2 -> V_5 + V_13 , 0x1 ) ;
} else {
F_7 ( V_2 -> V_5 + V_12 , 0xc0 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_5 + V_14 , 0x3 ) ;
F_7 ( V_2 -> V_5 + V_15 , 0x64 ) ;
F_7 ( V_2 -> V_5 + V_16 , 0x6c ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
F_7 ( V_2 -> V_5 + V_14 , V_17 ) ;
F_7 ( V_2 -> V_5 + V_15 , V_18 ) ;
}
void F_11 ( struct V_1 * V_2 , bool V_19 , T_1 V_20 )
{
T_1 V_21 ;
T_1 V_22 ;
if ( V_19 )
V_22 = 0 ;
else
V_22 = 0x7 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
F_7 ( V_2 -> V_5 + F_12 ( V_21 ) , V_22 ) ;
V_22 = 0x7 ;
for ( V_21 = V_20 ; V_21 < V_23 ; V_21 ++ )
F_7 ( V_2 -> V_5 + F_12 ( V_21 ) , V_22 ) ;
}
void * F_13 ( struct V_24 * V_25 , void T_2 * V_26 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_14 ( V_25 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = V_26 ;
return V_2 ;
}
