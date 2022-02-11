T_1 F_1 ( int V_1 , void * V_2 , T_2 V_3 )
{
T_2 V_4 = 0 ;
T_1 V_5 ;
while ( V_4 < V_3 ) {
V_5 = F_2 ( V_1 , V_2 + V_4 , V_3 - V_4 ) ;
if ( ! V_5 )
break;
if ( V_5 < 0 ) {
if ( V_6 == V_7 || V_6 == V_8 )
continue;
perror ( L_1 ) ;
return - 1 ;
}
V_4 += V_5 ;
}
return V_4 ;
}
T_1 F_3 ( int V_1 , const void * V_2 , T_2 V_3 )
{
T_2 V_4 = 0 ;
T_1 V_5 ;
while ( V_4 < V_3 ) {
V_5 = F_4 ( V_1 , V_2 + V_4 , V_3 - V_4 ) ;
if ( V_5 < 0 ) {
if ( V_6 == V_7 || V_6 == V_8 )
continue;
perror ( L_2 ) ;
return - 1 ;
}
V_4 += V_5 ;
}
return V_4 ;
}
T_1 F_5 ( int V_1 , T_2 V_9 )
{
T_2 V_10 = V_9 ;
while ( V_10 -- ) {
const char V_11 = 0 ;
if ( F_3 ( V_1 , & V_11 , 1 ) < 0 )
return - 1 ;
}
return V_9 ;
}
int main ( void )
{
F_6 ( V_12 ) ;
char V_13 [ V_14 ] ;
T_2 V_15 , V_16 ;
T_1 V_17 ;
V_17 = F_1 ( 0 , V_13 , sizeof( V_13 ) ) ;
if ( V_17 <= 0 )
return - 1 ;
V_15 = F_7 ( sizeof( V_12 ) ) ;
V_12 . V_18 = F_8 ( V_19 + V_15 ) ;
V_16 = F_7 ( V_17 ) ;
V_12 . V_20 = F_9 ( V_15 + V_16 ) ;
if ( F_3 ( 1 , & V_12 , sizeof( V_12 ) ) < 0 )
return - 1 ;
if ( F_5 ( 1 , V_15 - sizeof( V_12 ) ) < 0 )
return - 1 ;
if ( F_3 ( 1 , V_13 , V_17 ) < 0 )
return 1 ;
while ( 1 ) {
V_17 = F_1 ( 0 , V_13 , sizeof( V_13 ) ) ;
if ( V_17 < 0 )
return 1 ;
if ( V_17 == 0 )
break;
if ( F_3 ( 1 , V_13 , V_17 ) < 0 )
return 1 ;
}
return 0 ;
}
