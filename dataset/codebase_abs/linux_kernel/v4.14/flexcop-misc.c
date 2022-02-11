void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ( V_2 , V_5 ) ;
switch ( V_3 . V_5 . V_6 ) {
case 0x2 :
F_2 ( L_1 ) ;
V_2 -> V_7 = V_8 ;
break;
case 0x3 :
F_2 ( L_2 ) ;
V_2 -> V_7 = V_9 ;
break;
case 0x0 :
F_2 ( L_3 ) ;
V_2 -> V_7 = V_10 ;
break;
default:
F_3 ( L_4 ,
V_3 . V_5 . V_6 ) ;
break;
}
if ( ( V_2 -> V_11 = V_3 . V_5 . V_12 ) )
F_2 ( L_5 ) ;
else
F_2 ( L_6 ) ;
}
void F_4 ( struct V_1 * V_2 ,
const char * V_13 , const char * V_14 )
{
F_5 ( L_7 ,
V_13 , V_15 [ V_2 -> V_16 ] ,
V_17 [ V_2 -> V_18 ] ,
V_19 [ V_2 -> V_7 ] , V_14 ) ;
}
void F_6 ( struct V_1 * V_2 ,
T_2 V_20 , int V_21 )
{
T_1 V_3 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_3 = V_2 -> V_4 ( V_2 , V_20 + 4 * V_22 ) ;
F_7 ( L_8 , V_20 + 4 * V_22 , V_3 . V_23 ) ;
}
F_7 ( L_9 ) ;
}
