static int F_1 ( T_1 * V_1 ,
const void * V_2 , const int V_3 ,
const void * V_4 , const int V_5 )
{
int V_6 ;
F_2 ( L_1 ) ;
V_6 = memcmp ( V_2 , V_4 , F_3 ( V_3 , V_5 ) ) ;
if ( ! V_6 && ( V_3 != V_5 ) ) {
if ( V_3 < V_5 )
V_6 = - 1 ;
else
V_6 = 1 ;
}
F_2 ( L_2 , V_6 ) ;
return V_6 ;
}
static int F_4 ( T_1 * V_1 ,
const void * V_2 , const int V_3 ,
const void * V_4 , const int V_5 )
{
int V_6 ;
T_2 V_7 , V_8 ;
F_2 ( L_1 ) ;
F_5 ( V_3 != V_5 ) ;
F_5 ( V_3 != 4 ) ;
V_7 = F_6 ( V_2 ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_7 < V_8 )
V_6 = - 1 ;
else {
if ( V_7 == V_8 )
V_6 = 0 ;
else
V_6 = 1 ;
}
F_2 ( L_2 , V_6 ) ;
return V_6 ;
}
int F_7 ( T_1 * V_1 , T_3 V_9 ,
const void * V_2 , const int V_3 ,
const void * V_4 , const int V_5 ) {
int V_10 ;
F_2 ( L_1 ) ;
F_5 ( V_9 != V_11 && V_9 != V_12 ) ;
V_10 = F_8 ( V_9 ) ;
F_5 ( V_10 < 0 ) ;
if ( V_10 <= 0x02 )
return V_13 [ V_10 ] ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) ;
F_5 ( V_10 < 0x10 ) ;
V_10 -= 0x10 ;
if ( F_9 ( V_10 <= 3 ) )
return V_14 [ V_10 ] ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) ;
F_10 () ;
return 0 ;
}
