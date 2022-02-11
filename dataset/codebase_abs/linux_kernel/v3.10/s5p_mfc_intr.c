int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 ,
( V_2 -> V_6 && ( V_2 -> V_7 == V_3
|| V_2 -> V_7 == V_8 ) ) ,
F_3 ( V_9 ) ) ;
if ( V_4 == 0 ) {
F_4 ( L_1 ,
V_2 -> V_7 , V_3 ) ;
return 1 ;
} else if ( V_4 == - V_10 ) {
F_4 ( L_2 ) ;
return 1 ;
}
F_5 ( 1 , L_3 ,
V_2 -> V_7 , V_3 ) ;
if ( V_2 -> V_7 == V_8 )
return 1 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_11 = 0 ;
}
int F_7 ( struct V_12 * V_13 ,
int V_3 , int V_14 )
{
int V_4 ;
if ( V_14 ) {
V_4 = F_2 ( V_13 -> V_5 ,
( V_13 -> V_6 && ( V_13 -> V_7 == V_3
|| V_13 -> V_7 == V_8 ) ) ,
F_3 ( V_9 ) ) ;
} else {
V_4 = F_8 ( V_13 -> V_5 ,
( V_13 -> V_6 && ( V_13 -> V_7 == V_3
|| V_13 -> V_7 == V_8 ) ) ,
F_3 ( V_9 ) ) ;
}
if ( V_4 == 0 ) {
F_4 ( L_4 ,
V_13 -> V_7 , V_3 ) ;
return 1 ;
} else if ( V_4 == - V_10 ) {
F_4 ( L_2 ) ;
return 1 ;
}
F_5 ( 1 , L_5 ,
V_13 -> V_7 , V_3 ) ;
if ( V_13 -> V_7 == V_8 )
return 1 ;
return 0 ;
}
void F_9 ( struct V_12 * V_13 )
{
V_13 -> V_6 = 0 ;
V_13 -> V_7 = 0 ;
V_13 -> V_11 = 0 ;
}
