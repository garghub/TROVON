static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
T_1 V_5 = 0 ;
F_2 ( V_6 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ ) {
if ( F_3 ( V_8 ) != 0 )
break;
F_4 ( 1 ) ;
}
V_5 = F_3 ( V_8 ) ;
if ( V_5 != 1 ) {
if ( V_5 == 0xFF ) {
F_5 ( L_1 ) ;
return - V_9 ;
} else if ( V_5 == 0xFE ) {
F_5 ( L_2 ) ;
return - V_9 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , bool V_10 )
{
if ( V_10 )
return F_1 ( V_2 , V_11 ) ;
else
return F_1 ( V_2 , V_12 ) ;
}
int F_7 ( struct V_1 * V_2 , bool V_10 )
{
if ( V_10 )
F_8 ( V_13 , 1 ) ;
else
F_8 ( V_13 , 0 ) ;
return F_1 ( V_2 , V_14 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_15 )
{
F_8 ( V_13 , V_15 ) ;
return F_1 ( V_2 , V_16 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_15 )
{
F_8 ( V_13 , V_15 ) ;
return F_1 ( V_2 , V_17 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_18 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_19 ) ;
}
int F_13 ( struct V_1 * V_2 ,
bool V_10 )
{
if ( V_10 )
return F_1 ( V_2 , V_20 ) ;
else
return F_1 ( V_2 , V_21 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_22 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_4 ;
F_2 ( V_23 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_7 ; V_4 ++ ) {
if ( ( F_3 ( V_23 ) & 0xffff ) == 1 )
break;
F_4 ( 1 ) ;
}
}
void F_16 ( struct V_1 * V_2 )
{
F_2 ( V_23 , 0 ) ;
}
