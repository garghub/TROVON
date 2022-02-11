T_1 F_1 ( unsigned V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( sizeof *V_2 , V_3 ) ;
if ( ! V_2 )
return V_2 ;
if ( V_1 ) {
V_2 -> V_4 = F_3 ( V_1 ) ;
if ( ! V_2 -> V_4 ) {
F_4 ( V_2 ) ;
return NULL ;
}
} else {
V_2 -> V_4 = NULL ;
}
V_2 -> V_5 = V_1 ;
V_2 -> V_1 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
return V_2 ;
}
T_2 F_3 ( unsigned V_1 )
{
T_3 V_9 = V_1 * sizeof( V_10 ) ;
if ( ! V_9 )
return NULL ;
return F_2 ( V_9 , V_3 ) ;
}
void F_5 ( T_2 V_2 )
{
if ( ! V_2 )
return;
F_4 ( V_2 ) ;
}
void F_6 ( T_1 V_2 , T_2 V_11 , unsigned V_1 )
{
F_5 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_11 ;
V_2 -> V_5 = V_1 ;
}
int F_7 ( T_1 V_2 , unsigned V_1 )
{
void * V_12 ;
if ( V_1 <= V_2 -> V_5 )
return 0 ;
if ( V_2 -> V_4 ) {
V_12 = F_2 ( V_1 * sizeof( V_10 ) , V_3 ) ;
if ( ! V_12 )
return - V_13 ;
memcpy ( V_12 , V_2 -> V_4 , V_2 -> V_5 * sizeof( V_10 ) ) ;
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_12 ;
} else {
V_2 -> V_4 = F_8 ( V_1 * sizeof( V_10 ) , V_3 ) ;
if ( ! V_2 -> V_4 )
return - V_13 ;
}
V_2 -> V_5 = V_1 ;
return 0 ;
}
void F_9 ( T_1 V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_7 & 4 )
F_4 ( V_2 -> V_4 ) ;
else
F_5 ( V_2 -> V_4 ) ;
if ( V_2 -> V_7 & ~ 7 )
F_10 ( L_1 ) ;
F_4 ( V_2 ) ;
}
