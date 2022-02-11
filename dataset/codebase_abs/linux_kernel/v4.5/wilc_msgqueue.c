int F_1 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
F_3 ( & V_1 -> V_3 , 0 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = false ;
return 0 ;
}
int F_4 ( T_1 * V_1 )
{
V_1 -> V_6 = true ;
while ( V_1 -> V_5 > 0 ) {
F_5 ( & V_1 -> V_3 ) ;
V_1 -> V_5 -- ;
}
while ( V_1 -> V_4 ) {
T_2 * V_7 = V_1 -> V_4 -> V_8 ;
F_6 ( V_1 -> V_4 ) ;
V_1 -> V_4 = V_7 ;
}
return 0 ;
}
int F_7 ( T_1 * V_1 ,
const void * V_9 , T_3 V_10 )
{
unsigned long V_11 ;
T_2 * V_12 = NULL ;
if ( ( ! V_1 ) || ( V_10 == 0 ) || ( ! V_9 ) ) {
F_8 ( L_1 ) ;
return - V_13 ;
}
if ( V_1 -> V_6 ) {
F_8 ( L_2 ) ;
return - V_13 ;
}
V_12 = F_9 ( sizeof( T_2 ) , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_12 -> V_16 = V_10 ;
V_12 -> V_8 = NULL ;
V_12 -> V_17 = F_10 ( V_9 , V_10 ,
V_14 ) ;
if ( ! V_12 -> V_17 ) {
F_6 ( V_12 ) ;
return - V_15 ;
}
F_11 ( & V_1 -> V_2 , V_11 ) ;
if ( ! V_1 -> V_4 ) {
V_1 -> V_4 = V_12 ;
} else {
T_2 * V_18 = V_1 -> V_4 ;
while ( V_18 -> V_8 )
V_18 = V_18 -> V_8 ;
V_18 -> V_8 = V_12 ;
}
F_12 ( & V_1 -> V_2 , V_11 ) ;
F_5 ( & V_1 -> V_3 ) ;
return 0 ;
}
int F_13 ( T_1 * V_1 ,
void * V_19 , T_3 V_20 ,
T_3 * V_21 )
{
T_2 * V_12 ;
unsigned long V_11 ;
if ( ( ! V_1 ) || ( V_20 == 0 )
|| ( ! V_19 ) || ( ! V_21 ) ) {
F_8 ( L_3 ) ;
return - V_22 ;
}
if ( V_1 -> V_6 ) {
F_8 ( L_2 ) ;
return - V_13 ;
}
F_11 ( & V_1 -> V_2 , V_11 ) ;
V_1 -> V_5 ++ ;
F_12 ( & V_1 -> V_2 , V_11 ) ;
F_14 ( & V_1 -> V_3 ) ;
if ( V_1 -> V_6 ) {
F_8 ( L_2 ) ;
return - V_13 ;
}
F_11 ( & V_1 -> V_2 , V_11 ) ;
V_12 = V_1 -> V_4 ;
if ( ! V_12 ) {
F_12 ( & V_1 -> V_2 , V_11 ) ;
F_8 ( L_4 ) ;
return - V_13 ;
}
if ( V_20 < V_12 -> V_16 ) {
F_12 ( & V_1 -> V_2 , V_11 ) ;
F_5 ( & V_1 -> V_3 ) ;
F_8 ( L_5 ) ;
return - V_23 ;
}
V_1 -> V_5 -- ;
memcpy ( V_19 , V_12 -> V_17 , V_12 -> V_16 ) ;
* V_21 = V_12 -> V_16 ;
V_1 -> V_4 = V_12 -> V_8 ;
F_6 ( V_12 -> V_17 ) ;
F_6 ( V_12 ) ;
F_12 ( & V_1 -> V_2 , V_11 ) ;
return 0 ;
}
