int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_7 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
int V_9 = F_4 ( V_6 ) ;
F_5 ( L_1 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_4 ) ) {
F_5 ( L_2 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return - V_12 ;
}
V_4 = (struct V_3 * ) V_6 -> V_13 ;
if ( ! F_7 ( & V_4 -> V_14 , V_15 ) ) {
F_5 ( L_3 ,
V_2 -> V_10 , & V_4 -> V_14 ) ;
F_8 ( V_16 , & V_2 -> V_17 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , const T_1 * V_14 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 , 0xfc31 , 6 , V_14 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_4 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , T_2 V_18 )
{
struct V_5 * V_6 ;
T_2 type = 0x00 ;
F_5 ( L_5 , V_2 -> V_10 , V_18 ) ;
V_6 = F_2 ( V_2 , V_19 , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_6 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return;
}
F_6 ( V_6 ) ;
V_6 = F_2 ( V_2 , 0xfc22 , 1 , & type , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_7 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return;
}
if ( V_6 -> V_11 != 13 ) {
F_5 ( L_8 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return;
}
F_5 ( L_9 , V_2 -> V_10 , ( char * ) ( V_6 -> V_13 + 1 ) ) ;
F_6 ( V_6 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
const char * V_22 ;
switch ( V_21 -> V_23 ) {
case 0x06 :
V_22 = L_10 ;
break;
case 0x23 :
V_22 = L_11 ;
break;
default:
return;
}
F_12 ( L_12 , V_2 -> V_10 ,
V_22 , V_21 -> V_24 >> 4 , V_21 -> V_24 & 0x0f ,
V_21 -> V_25 , V_21 -> V_26 , 2000 + V_21 -> V_27 ) ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_28 , T_3 V_29 ,
const void * V_30 )
{
while ( V_29 > 0 ) {
struct V_5 * V_6 ;
T_2 V_31 [ 253 ] , V_32 = ( V_29 > 252 ) ? 252 : V_29 ;
V_31 [ 0 ] = V_28 ;
memcpy ( V_31 + 1 , V_30 , V_32 ) ;
V_6 = F_2 ( V_2 , 0xfc09 , V_32 + 1 ,
V_31 , V_8 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_6 ( V_6 ) ;
V_29 -= V_32 ;
V_30 += V_32 ;
}
return 0 ;
}
