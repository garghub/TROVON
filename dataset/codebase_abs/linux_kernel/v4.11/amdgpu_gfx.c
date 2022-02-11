int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 . V_6 . V_7 ) ;
if ( V_4 != 0 && V_4 <= V_2 -> V_5 . V_6 . V_8 ) {
V_4 -- ;
V_2 -> V_5 . V_6 . V_7 &= ~ ( 1u << V_4 ) ;
* V_3 = V_2 -> V_5 . V_6 . V_9 + V_4 ;
return 0 ;
}
return - V_10 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_5 . V_6 . V_7 |= 1u << ( V_3 - V_2 -> V_5 . V_6 . V_9 ) ;
}
void F_4 ( unsigned * V_11 , unsigned V_12 , unsigned V_13 )
{
unsigned V_14 , V_15 , V_16 ;
const char * V_17 ;
memset ( V_11 , 0 , sizeof( * V_11 ) * V_12 * V_13 ) ;
if ( ! V_18 || ! * V_18 )
return;
V_17 = V_18 ;
for (; ; ) {
char * V_19 ;
int V_20 = sscanf ( V_17 , L_1 , & V_14 , & V_15 , & V_16 ) ;
if ( V_20 < 3 ) {
F_5 ( L_2 ) ;
return;
}
if ( V_14 < V_12 && V_15 < V_13 && V_16 < 16 ) {
F_6 ( L_3 , V_14 , V_15 , V_16 ) ;
V_11 [ V_14 * V_13 + V_15 ] |= 1u << V_16 ;
} else {
F_5 ( L_4 ,
V_14 , V_15 , V_16 ) ;
}
V_19 = strchr ( V_17 , ',' ) ;
if ( ! V_19 )
break;
V_17 = V_19 + 1 ;
}
}
