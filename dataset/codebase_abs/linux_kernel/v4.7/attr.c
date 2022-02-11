int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , const void * V_5 ,
T_1 V_6 , int V_7 )
{
struct V_8 V_9 ;
T_2 V_10 ;
struct V_11 * V_12 ;
int V_13 ;
if ( ! F_2 ( V_3 -> V_14 ) || F_3 ( V_3 ) )
return - V_15 ;
V_13 = F_4 ( F_5 ( V_3 -> V_16 ) -> V_17 , & V_9 ) ;
if ( V_13 )
return V_13 ;
V_9 . V_18 -> V_19 = F_6 ( V_3 ) -> V_20 ;
V_13 = F_7 ( & V_9 ) ;
if ( V_13 )
goto V_21;
F_8 ( V_9 . V_22 , & V_10 , V_9 . V_23 ,
sizeof( struct V_11 ) ) ;
V_12 = & V_10 . V_12 ;
if ( ! strcmp ( V_4 , L_1 ) ) {
if ( V_6 == 4 )
memcpy ( & V_12 -> V_24 . V_25 , V_5 , 4 ) ;
else
V_13 = - V_26 ;
} else if ( ! strcmp ( V_4 , L_2 ) ) {
if ( V_6 == 4 )
memcpy ( & V_12 -> V_24 . V_27 , V_5 , 4 ) ;
else
V_13 = - V_26 ;
} else
V_13 = - V_15 ;
if ( ! V_13 )
F_9 ( V_9 . V_22 , & V_10 , V_9 . V_23 ,
sizeof( struct V_11 ) ) ;
V_21:
F_10 ( & V_9 ) ;
return V_13 ;
}
T_3 F_11 ( struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , void * V_5 , T_1 V_6 )
{
struct V_8 V_9 ;
T_2 V_10 ;
struct V_11 * V_12 ;
T_3 V_13 = 0 ;
if ( ! F_2 ( V_3 -> V_14 ) || F_3 ( V_3 ) )
return - V_15 ;
if ( V_6 ) {
V_13 = F_4 ( F_5 ( V_3 -> V_16 ) -> V_17 , & V_9 ) ;
if ( V_13 )
return V_13 ;
V_9 . V_18 -> V_19 = F_6 ( V_3 ) -> V_20 ;
V_13 = F_7 ( & V_9 ) ;
if ( V_13 )
goto V_21;
F_8 ( V_9 . V_22 , & V_10 , V_9 . V_23 ,
sizeof( struct V_11 ) ) ;
}
V_12 = & V_10 . V_12 ;
if ( ! strcmp ( V_4 , L_1 ) ) {
if ( V_6 >= 4 ) {
memcpy ( V_5 , & V_12 -> V_24 . V_25 , 4 ) ;
V_13 = 4 ;
} else
V_13 = V_6 ? - V_26 : 4 ;
} else if ( ! strcmp ( V_4 , L_2 ) ) {
if ( V_6 >= 4 ) {
memcpy ( V_5 , & V_12 -> V_24 . V_27 , 4 ) ;
V_13 = 4 ;
} else
V_13 = V_6 ? - V_26 : 4 ;
} else
V_13 = - V_28 ;
V_21:
if ( V_6 )
F_10 ( & V_9 ) ;
return V_13 ;
}
T_3 F_12 ( struct V_1 * V_1 , char * V_29 , T_1 V_6 )
{
struct V_3 * V_3 = F_13 ( V_1 ) ;
if ( ! F_2 ( V_3 -> V_14 ) || F_3 ( V_3 ) )
return - V_15 ;
if ( ! V_29 || ! V_6 )
return V_30 ;
if ( V_6 < V_30 )
return - V_26 ;
strcpy ( V_29 , L_1 ) ;
strcpy ( V_29 + sizeof( L_1 ) , L_2 ) ;
return V_30 ;
}
