T_1 F_1 ( struct V_1 * V_2 , const char * V_3 ,
void * V_4 , T_2 V_5 )
{
T_1 V_6 ;
int V_7 , V_8 ;
T_3 V_9 = 0 , V_10 ;
struct V_1 * V_11 ;
V_11 = F_2 ( V_2 , V_3 , & V_10 ) ;
if ( F_3 ( V_11 ) ) {
V_6 = F_4 ( V_11 ) ;
F_5 ( V_12 ,
L_1 , V_6 ) ;
V_11 = NULL ;
goto error;
}
if ( ! V_5 ) {
V_6 = V_10 ;
goto error;
}
if ( V_10 > V_5 ) {
V_6 = - V_13 ;
goto error;
}
V_7 = V_11 -> V_14 -> V_7 ;
while ( V_10 ) {
if ( V_10 > ( V_7 - V_15 ) )
V_8 = V_7 - V_15 ;
else
V_8 = V_10 ;
V_8 = F_6 ( V_11 , ( ( char * ) V_4 ) + V_9 ,
NULL , V_9 , V_8 ) ;
if ( V_8 < 0 ) {
V_6 = V_8 ;
goto error;
}
V_9 += V_8 ;
V_10 -= V_8 ;
}
V_6 = V_9 ;
error:
if ( V_11 )
F_7 ( V_11 ) ;
return V_6 ;
}
T_1 F_8 ( struct V_16 * V_16 , const char * V_3 ,
void * V_4 , T_2 V_5 )
{
struct V_1 * V_2 ;
F_5 ( V_12 , L_2 ,
V_17 , V_3 , V_5 ) ;
V_2 = F_9 ( V_16 ) ;
if ( F_3 ( V_2 ) )
return F_4 ( V_2 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_10 ( struct V_16 * V_16 , const char * V_3 ,
const void * V_18 , T_2 V_19 , int V_20 )
{
T_3 V_9 = 0 ;
int V_6 , V_7 , V_21 ;
struct V_1 * V_2 = NULL ;
F_5 ( V_12 , L_3 ,
V_17 , V_3 , V_19 , V_20 ) ;
V_2 = F_11 ( V_16 ) ;
if ( F_3 ( V_2 ) ) {
V_6 = F_4 ( V_2 ) ;
V_2 = NULL ;
goto error;
}
V_6 = F_12 ( V_2 , V_3 , V_19 , V_20 ) ;
if ( V_6 < 0 ) {
F_5 ( V_12 ,
L_4 , V_6 ) ;
goto error;
}
V_7 = V_2 -> V_14 -> V_7 ;
while ( V_19 ) {
if ( V_19 > ( V_7 - V_15 ) )
V_21 = V_7 - V_15 ;
else
V_21 = V_19 ;
V_21 = F_13 ( V_2 , ( ( char * ) V_18 ) + V_9 ,
NULL , V_9 , V_21 ) ;
if ( V_21 < 0 ) {
V_6 = V_21 ;
goto error;
}
V_9 += V_21 ;
V_19 -= V_21 ;
}
V_6 = V_9 ;
error:
if ( V_2 )
V_6 = F_7 ( V_2 ) ;
return V_6 ;
}
T_1 F_14 ( struct V_16 * V_16 , char * V_4 , T_2 V_5 )
{
return F_8 ( V_16 , NULL , V_4 , V_5 ) ;
}
