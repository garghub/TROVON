int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 . V_7 ; V_4 ++ ) {
if ( V_2 -> V_5 . V_6 . free [ V_4 ] ) {
V_2 -> V_5 . V_6 . free [ V_4 ] = false ;
* V_3 = V_2 -> V_5 . V_6 . V_3 [ V_4 ] ;
return 0 ;
}
}
return - V_8 ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 . V_7 ; V_4 ++ ) {
if ( V_2 -> V_5 . V_6 . V_3 [ V_4 ] == V_3 ) {
V_2 -> V_5 . V_6 . free [ V_4 ] = true ;
return;
}
}
}
void F_3 ( unsigned * V_9 , unsigned V_10 , unsigned V_11 )
{
unsigned V_12 , V_13 , V_14 ;
const char * V_15 ;
memset ( V_9 , 0 , sizeof( * V_9 ) * V_10 * V_11 ) ;
if ( ! V_16 || ! * V_16 )
return;
V_15 = V_16 ;
for (; ; ) {
char * V_17 ;
int V_18 = sscanf ( V_15 , L_1 , & V_12 , & V_13 , & V_14 ) ;
if ( V_18 < 3 ) {
F_4 ( L_2 ) ;
return;
}
if ( V_12 < V_10 && V_13 < V_11 && V_14 < 16 ) {
F_5 ( L_3 , V_12 , V_13 , V_14 ) ;
V_9 [ V_12 * V_11 + V_13 ] |= 1u << V_14 ;
} else {
F_4 ( L_4 ,
V_12 , V_13 , V_14 ) ;
}
V_17 = strchr ( V_15 , ',' ) ;
if ( ! V_17 )
break;
V_15 = V_17 + 1 ;
}
}
