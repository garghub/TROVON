int F_1 ( struct V_1 * V_1 , const char * V_2 ,
const void * V_3 , T_1 V_4 , int V_5 )
{
struct V_6 * V_6 = F_2 ( V_1 ) ;
struct V_7 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 ;
int V_12 ;
if ( ! F_3 ( V_6 -> V_13 ) || F_4 ( V_6 ) )
return - V_14 ;
V_12 = F_5 ( F_6 ( V_6 -> V_15 ) -> V_16 , & V_8 ) ;
if ( V_12 )
return V_12 ;
V_8 . V_17 -> V_18 = F_7 ( V_6 ) -> V_19 ;
V_12 = F_8 ( & V_8 ) ;
if ( V_12 )
goto V_20;
F_9 ( V_8 . V_21 , & V_9 , V_8 . V_22 ,
sizeof( struct V_10 ) ) ;
V_11 = & V_9 . V_11 ;
if ( ! strcmp ( V_2 , L_1 ) ) {
if ( V_4 == 4 )
memcpy ( & V_11 -> V_23 . V_24 , V_3 , 4 ) ;
else
V_12 = - V_25 ;
} else if ( ! strcmp ( V_2 , L_2 ) ) {
if ( V_4 == 4 )
memcpy ( & V_11 -> V_23 . V_26 , V_3 , 4 ) ;
else
V_12 = - V_25 ;
} else
V_12 = - V_14 ;
if ( ! V_12 )
F_10 ( V_8 . V_21 , & V_9 , V_8 . V_22 ,
sizeof( struct V_10 ) ) ;
V_20:
F_11 ( & V_8 ) ;
return V_12 ;
}
T_3 F_12 ( struct V_1 * V_1 , const char * V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_6 * V_6 = F_2 ( V_1 ) ;
struct V_7 V_8 ;
T_2 V_9 ;
struct V_10 * V_11 ;
T_3 V_12 = 0 ;
if ( ! F_3 ( V_6 -> V_13 ) || F_4 ( V_6 ) )
return - V_14 ;
if ( V_4 ) {
V_12 = F_5 ( F_6 ( V_6 -> V_15 ) -> V_16 , & V_8 ) ;
if ( V_12 )
return V_12 ;
V_8 . V_17 -> V_18 = F_7 ( V_6 ) -> V_19 ;
V_12 = F_8 ( & V_8 ) ;
if ( V_12 )
goto V_20;
F_9 ( V_8 . V_21 , & V_9 , V_8 . V_22 ,
sizeof( struct V_10 ) ) ;
}
V_11 = & V_9 . V_11 ;
if ( ! strcmp ( V_2 , L_1 ) ) {
if ( V_4 >= 4 ) {
memcpy ( V_3 , & V_11 -> V_23 . V_24 , 4 ) ;
V_12 = 4 ;
} else
V_12 = V_4 ? - V_25 : 4 ;
} else if ( ! strcmp ( V_2 , L_2 ) ) {
if ( V_4 >= 4 ) {
memcpy ( V_3 , & V_11 -> V_23 . V_26 , 4 ) ;
V_12 = 4 ;
} else
V_12 = V_4 ? - V_25 : 4 ;
} else
V_12 = - V_27 ;
V_20:
if ( V_4 )
F_11 ( & V_8 ) ;
return V_12 ;
}
T_3 F_13 ( struct V_1 * V_1 , char * V_28 , T_1 V_4 )
{
struct V_6 * V_6 = F_2 ( V_1 ) ;
if ( ! F_3 ( V_6 -> V_13 ) || F_4 ( V_6 ) )
return - V_14 ;
if ( ! V_28 || ! V_4 )
return V_29 ;
if ( V_4 < V_29 )
return - V_25 ;
strcpy ( V_28 , L_1 ) ;
strcpy ( V_28 + sizeof( L_1 ) , L_2 ) ;
return V_29 ;
}
