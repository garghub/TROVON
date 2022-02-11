static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
F_3 ( & V_11 -> V_12 ,
L_1 ,
V_6 -> V_13 . V_14 , V_4 , ( unsigned int ) V_8 , V_9 , V_7 ) ;
if ( V_8 != 0 )
return 0 ;
if ( ! V_7 )
return - V_15 ;
F_4 ( & V_11 -> V_16 -> V_17 ) ;
F_3 ( & V_11 -> V_12 , L_2 ) ;
if ( F_5 ( V_11 ) ) {
F_6 ( & V_11 -> V_16 -> V_17 ) ;
return - V_18 ;
}
F_7 ( V_11 -> V_16 , V_19 ) ;
* V_7 = F_8 ( V_11 -> V_16 ) ;
F_6 ( & V_11 -> V_16 -> V_17 ) ;
F_3 ( & V_11 -> V_12 , L_3 ) ;
if ( ( * V_7 & 0x0F ) != ( ( ~ * V_7 >> 4 ) & 0x0F ) )
return - V_18 ;
else
return 1 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
T_4 V_20 [ 3 ] ;
unsigned int V_21 = V_22 ;
if ( V_9 != 1 || V_8 != 0 )
return - V_23 ;
F_3 ( & V_11 -> V_12 , L_4 ) ;
F_4 ( & V_11 -> V_16 -> V_17 ) ;
F_3 ( & V_11 -> V_12 , L_2 ) ;
if ( F_5 ( V_11 ) )
goto error;
* V_7 = * V_7 | 0xFC ;
while ( V_21 -- ) {
V_20 [ 0 ] = V_24 ;
V_20 [ 1 ] = * V_7 ;
V_20 [ 2 ] = ~ ( * V_7 ) ;
F_10 ( V_11 -> V_16 , V_20 , 3 ) ;
if ( F_8 ( V_11 -> V_16 ) == V_25 ) {
F_6 ( & V_11 -> V_16 -> V_17 ) ;
F_3 ( & V_11 -> V_12 , L_5 , V_21 ) ;
return 1 ;
}
if ( F_11 ( V_11 -> V_16 ) )
goto error;
}
error:
F_6 ( & V_11 -> V_16 -> V_17 ) ;
F_3 ( & V_11 -> V_12 , L_6 , V_21 ) ;
return - V_18 ;
}
