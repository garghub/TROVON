static T_1 F_1 ( void )
{
return V_1 ;
}
static T_1 F_2 ( char * V_2 , T_2 V_3 , T_3 * V_4 )
{
T_4 V_5 ;
int V_6 ;
if ( * V_4 >= V_1 )
return 0 ;
V_6 = * V_4 ;
if ( ( V_6 + V_3 ) > V_1 )
V_3 = V_1 - V_6 ;
V_5 = F_3 ( F_4 ( V_2 ) , V_3 , V_6 ) ;
if ( V_5 != V_7 )
return - V_8 ;
* V_4 += V_3 ;
return V_3 ;
}
static T_1 F_5 ( char * V_2 , T_2 V_3 , T_3 * V_4 )
{
T_4 V_5 = V_9 ;
int V_6 ;
if ( * V_4 >= V_1 )
return 0 ;
V_6 = * V_4 ;
if ( ( V_6 + V_3 ) > V_1 )
V_3 = V_1 - V_6 ;
while ( V_5 == V_9 || V_5 == V_10 ) {
V_5 = F_6 ( F_4 ( V_2 ) , V_3 , V_6 ) ;
if ( V_5 == V_10 )
F_7 ( NULL ) ;
}
* V_4 += V_3 ;
return V_3 ;
}
static int T_5 F_8 ( void )
{
F_9 () ;
F_10 ( 0 ) ;
return 0 ;
}
void T_5 F_11 ( void )
{
struct V_11 * V_12 ;
const T_6 * V_13 ;
V_12 = F_12 ( NULL , NULL , L_1 ) ;
if ( V_12 == NULL )
return;
V_13 = F_13 ( V_12 , L_2 , NULL ) ;
if ( ! V_13 ) {
F_14 ( V_12 ) ;
return;
}
V_1 = F_15 ( V_13 ) ;
F_16 ( L_3 , V_1 ) ;
F_14 ( V_12 ) ;
V_14 . V_15 = F_2 ;
V_14 . V_16 = F_5 ;
V_14 . V_1 = F_1 ;
}
