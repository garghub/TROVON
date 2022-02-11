void F_1 ( void * V_1 ,
unsigned int V_2 ,
enum V_3 type )
{
V_4 = V_1 ;
V_5 = V_2 ;
V_6 = type ;
}
static T_1 F_2 ( T_2 V_7 , void * V_1 ,
unsigned int V_2 ,
enum V_3 type ,
bool V_8 )
{
#ifdef F_3
if ( type == V_9 )
return F_4 ( V_7 , V_10 , 0 ,
V_1 , V_8 ) ;
#endif
if ( type == V_11 ) {
if ( V_1 == NULL )
return F_4 ( V_7 , V_12 , 0 ,
0 , V_8 ) ;
else {
if ( V_2 < ( ( F_5 ( V_7 ) ) >> V_13 ) )
F_6 ( V_14 ,
L_1
L_2 ) ;
else if ( V_2 > ( ( F_5 ( V_7 ) )
>> V_13 ) )
F_6 ( V_14 ,
L_3
L_4 ) ;
return F_4 ( V_7 , V_15 , 0 ,
V_1 , V_8 ) ;
}
} else {
F_6 ( V_14 , L_5 ) ;
return 0 ;
}
}
T_1 F_7 ( T_2 V_7 )
{
return F_2 ( V_7 , V_4 ,
V_5 , V_6 , false ) ;
}
T_1 F_8 ( T_2 V_7 , void * V_1 ,
unsigned int V_2 ,
enum V_3 type ,
bool V_8 )
{
return F_2 ( V_7 , V_1 , V_2 ,
type , V_8 ) ;
}
T_1 F_9 ( T_2 V_7 )
{
if ( V_4 == NULL )
return F_4 ( V_7 , V_12 , 0 , 0 ,
V_16 ) ;
else {
if ( V_5 < ( ( F_5 ( V_7 ) ) >> V_13 ) )
F_6 ( V_14 ,
L_1
L_2 ) ;
else if ( V_5 > ( ( F_5 ( V_7 ) ) >> V_13 ) )
F_6 ( V_14 ,
L_3
L_4 ) ;
return F_4 ( V_7 , V_15 , 0 ,
V_4 , V_16 ) ;
}
}
T_1 F_10 ( T_2 V_7 )
{
T_1 V_17 = F_7 ( V_7 ) ;
if ( V_17 )
F_11 ( V_17 , 0 , V_7 ) ;
return V_17 ;
}
T_1 F_12 ( T_2 V_7 )
{
T_1 V_17 = F_9 ( V_7 ) ;
if ( V_17 )
F_11 ( V_17 , 0 , V_7 ) ;
return V_17 ;
}
