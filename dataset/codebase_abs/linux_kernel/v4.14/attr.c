static int F_1 ( struct V_1 * V_1 , enum V_2 type ,
const void * V_3 , T_1 V_4 , int V_5 )
{
struct V_6 V_7 ;
T_2 V_8 ;
struct V_9 * V_10 ;
int V_11 ;
if ( ! F_2 ( V_1 -> V_12 ) || F_3 ( V_1 ) )
return - V_13 ;
V_11 = F_4 ( F_5 ( V_1 -> V_14 ) -> V_15 , & V_7 ) ;
if ( V_11 )
return V_11 ;
V_7 . V_16 -> V_17 = F_6 ( V_1 ) -> V_18 ;
V_11 = F_7 ( & V_7 ) ;
if ( V_11 )
goto V_19;
F_8 ( V_7 . V_20 , & V_8 , V_7 . V_21 ,
sizeof( struct V_9 ) ) ;
V_10 = & V_8 . V_10 ;
switch ( type ) {
case V_22 :
if ( V_4 == 4 )
memcpy ( & V_10 -> V_23 . V_24 , V_3 , 4 ) ;
else
V_11 = - V_25 ;
break;
case V_26 :
if ( V_4 == 4 )
memcpy ( & V_10 -> V_23 . V_27 , V_3 , 4 ) ;
else
V_11 = - V_25 ;
break;
}
if ( ! V_11 )
F_9 ( V_7 . V_20 , & V_8 , V_7 . V_21 ,
sizeof( struct V_9 ) ) ;
V_19:
F_10 ( & V_7 ) ;
return V_11 ;
}
static T_3 F_11 ( struct V_1 * V_1 , enum V_2 type ,
void * V_3 , T_1 V_4 )
{
struct V_6 V_7 ;
T_2 V_8 ;
struct V_9 * V_10 ;
T_3 V_11 = 0 ;
if ( ! F_2 ( V_1 -> V_12 ) || F_3 ( V_1 ) )
return - V_13 ;
if ( V_4 ) {
V_11 = F_4 ( F_5 ( V_1 -> V_14 ) -> V_15 , & V_7 ) ;
if ( V_11 )
return V_11 ;
V_7 . V_16 -> V_17 = F_6 ( V_1 ) -> V_18 ;
V_11 = F_7 ( & V_7 ) ;
if ( V_11 )
goto V_19;
F_8 ( V_7 . V_20 , & V_8 , V_7 . V_21 ,
sizeof( struct V_9 ) ) ;
}
V_10 = & V_8 . V_10 ;
switch ( type ) {
case V_22 :
if ( V_4 >= 4 ) {
memcpy ( V_3 , & V_10 -> V_23 . V_24 , 4 ) ;
V_11 = 4 ;
} else
V_11 = V_4 ? - V_25 : 4 ;
break;
case V_26 :
if ( V_4 >= 4 ) {
memcpy ( V_3 , & V_10 -> V_23 . V_27 , 4 ) ;
V_11 = 4 ;
} else
V_11 = V_4 ? - V_25 : 4 ;
break;
}
V_19:
if ( V_4 )
F_10 ( & V_7 ) ;
return V_11 ;
}
static int F_12 ( const struct V_28 * V_29 ,
struct V_30 * V_31 , struct V_1 * V_1 ,
const char * V_32 , void * V_3 , T_1 V_4 )
{
return F_11 ( V_1 , V_29 -> V_5 , V_3 , V_4 ) ;
}
static int F_13 ( const struct V_28 * V_29 ,
struct V_30 * V_31 , struct V_1 * V_1 ,
const char * V_32 , const void * V_3 , T_1 V_4 ,
int V_5 )
{
if ( ! V_3 )
return - V_13 ;
return F_1 ( V_1 , V_29 -> V_5 , V_3 , V_4 , V_5 ) ;
}
