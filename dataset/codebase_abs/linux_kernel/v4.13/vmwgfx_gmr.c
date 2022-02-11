static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 ,
int V_6 )
{
T_1 V_7 ;
T_2 V_8 ;
T_3 * V_9 ;
T_3 * V_10 ;
T_3 V_11 = sizeof( V_7 ) + sizeof( * V_9 ) ;
T_3 V_12 = V_5 / V_13 + ( ( V_5 % V_13 ) > 0 ) ;
T_3 V_14 = V_15 * V_5 + ( sizeof( V_8 ) + sizeof( * V_9 ) ) * V_12 ;
T_3 V_16 = 0 ;
T_3 V_17 = V_11 + V_14 ;
T_3 V_18 ;
V_10 = V_9 = F_2 ( V_2 , V_17 ) ;
if ( F_3 ( V_9 == NULL ) )
return - V_19 ;
V_7 . V_20 = V_6 ;
V_7 . V_21 = V_5 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
V_9 += sizeof( V_7 ) / sizeof( * V_9 ) ;
V_8 . V_20 = V_6 ;
V_8 . V_23 = ( V_15 > sizeof( * V_9 ) ) ?
V_24 : V_25 ;
while ( V_5 > 0 ) {
unsigned long V_26 = F_4 ( V_5 , ( unsigned long ) V_13 ) ;
V_8 . V_27 = V_16 ;
V_8 . V_21 = V_26 ;
* V_9 ++ = V_28 ;
memcpy ( V_9 , & V_8 , sizeof( V_8 ) ) ;
V_9 += sizeof( V_8 ) / sizeof( * V_9 ) ;
for ( V_18 = 0 ; V_18 < V_26 ; ++ V_18 ) {
if ( V_15 <= 4 )
* V_9 = F_5 ( V_4 ) >> V_29 ;
else
* ( ( V_30 * ) V_9 ) = F_5 ( V_4 ) >>
V_29 ;
V_9 += V_15 / sizeof( * V_9 ) ;
F_6 ( V_4 ) ;
}
V_5 -= V_26 ;
V_16 += V_26 ;
}
F_7 ( V_9 != V_10 + V_17 / sizeof( * V_9 ) ) ;
F_8 ( V_2 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_6 )
{
T_1 V_7 ;
T_3 V_11 = sizeof( V_7 ) + 4 ;
T_3 * V_9 ;
V_9 = F_2 ( V_2 , V_11 ) ;
if ( F_3 ( V_9 == NULL ) ) {
F_10 ( L_1 ) ;
return;
}
V_7 . V_20 = V_6 ;
V_7 . V_21 = 0 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
F_8 ( V_2 , V_11 ) ;
}
int F_11 ( struct V_1 * V_2 ,
const struct V_31 * V_32 ,
unsigned long V_5 ,
int V_6 )
{
struct V_3 V_33 ;
F_12 ( & V_33 , V_32 , 0 ) ;
if ( F_3 ( ! F_6 ( & V_33 ) ) )
return 0 ;
if ( F_3 ( ! ( V_2 -> V_34 & V_35 ) ) )
return - V_36 ;
return F_1 ( V_2 , & V_33 , V_5 , V_6 ) ;
}
void F_13 ( struct V_1 * V_2 , int V_6 )
{
if ( F_14 ( V_2 -> V_34 & V_35 ) )
F_9 ( V_2 , V_6 ) ;
}
