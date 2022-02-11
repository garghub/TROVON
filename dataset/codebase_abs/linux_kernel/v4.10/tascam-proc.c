static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
int V_13 ;
V_13 = F_2 ( V_6 -> V_14 , V_15 ,
V_16 + V_17 ,
& V_8 , sizeof( V_8 ) , 0 ) ;
if ( V_13 < 0 )
return;
V_9 = F_3 ( V_8 ) ;
V_13 = F_2 ( V_6 -> V_14 , V_15 ,
V_16 + V_18 ,
& V_8 , sizeof( V_8 ) , 0 ) ;
if ( V_13 < 0 )
return;
V_10 = F_3 ( V_8 ) ;
V_13 = F_2 ( V_6 -> V_14 , V_15 ,
V_16 + V_19 ,
& V_8 , sizeof( V_8 ) , 0 ) ;
if ( V_13 < 0 )
return;
V_11 = F_3 ( V_8 ) ;
V_13 = F_2 ( V_6 -> V_14 , V_15 ,
V_16 + V_20 ,
& V_8 , sizeof( V_8 ) , 0 ) ;
if ( V_13 < 0 )
return;
V_12 = F_3 ( V_8 ) ;
F_4 ( V_4 , L_1 , V_9 & 0xffff , V_9 ) ;
F_4 ( V_4 , L_2 , V_10 & 0xffff , V_10 ) ;
F_4 ( V_4 , L_3 , V_11 & 0xffff , V_11 ) ;
F_4 ( V_4 , L_4 , V_12 >> 16 , V_12 ) ;
}
static void F_5 ( struct V_5 * V_6 , struct V_1 * V_21 ,
const char * V_22 ,
void (* F_6)( struct V_1 * V_23 ,
struct V_3 * V_24 ) )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_6 -> V_25 , V_22 , V_21 ) ;
if ( V_2 == NULL )
return;
F_8 ( V_2 , V_6 , F_6 ) ;
if ( F_9 ( V_2 ) < 0 )
F_10 ( V_2 ) ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_21 ;
V_21 = F_7 ( V_6 -> V_25 , L_5 ,
V_6 -> V_25 -> V_26 ) ;
if ( V_21 == NULL )
return;
V_21 -> V_27 = V_28 | V_29 | V_30 ;
if ( F_9 ( V_21 ) < 0 ) {
F_10 ( V_21 ) ;
return;
}
F_5 ( V_6 , V_21 , L_6 , F_1 ) ;
}
