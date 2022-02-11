static T_1 F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
while ( V_5 -> V_6 && V_5 -> V_7 != V_3 )
V_5 ++ ;
return V_5 -> V_6 ;
}
static T_1 F_2 ( T_1 V_5 , T_1 V_8 , T_1 V_9 , T_1 V_10 ,
T_1 V_11 , T_1 V_12 )
{
struct V_13 V_14 ;
F_3 ( V_5 , V_8 , V_9 , V_10 , V_11 , V_12 , 0 , 0 , & V_14 ) ;
return V_14 . V_15 ;
}
static void T_2 * F_4 ( T_1 V_16 , unsigned int V_17 )
{
T_1 V_18 ;
V_18 = F_2 ( V_16 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_18 )
return 0 ;
return F_5 ( V_18 , V_17 ) ;
}
int F_6 ( unsigned int V_3 , T_1 * V_19 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_5 , V_20 ;
if ( ! V_21 . V_2 )
return - V_22 ;
V_5 = F_1 ( V_21 . V_2 , V_3 ) ;
if ( ! V_5 )
return - V_23 ;
V_20 = F_2 ( V_5 , V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_19 )
* V_19 = V_20 ;
return 0 ;
}
int F_7 ( void * V_24 , unsigned int V_3 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_17 ;
if ( ! V_21 . V_2 )
return - V_22 ;
if ( ! V_21 . V_2 -> V_25 )
return - V_23 ;
if ( F_6 ( V_3 , & V_17 , V_8 , V_9 , V_10 , V_11 , V_12 ) < 0 )
return - V_23 ;
if ( ! V_17 || V_17 > V_21 . V_2 -> V_26 )
return - V_23 ;
if ( V_24 )
memcpy ( V_24 , V_21 . V_27 , V_17 ) ;
return V_17 ;
}
int F_8 ( void * V_24 , unsigned int V_17 , unsigned int V_3 ,
T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_28 ;
if ( ! V_21 . V_2 )
return - V_22 ;
if ( V_17 > V_21 . V_2 -> V_26 )
return - V_23 ;
if ( ! V_21 . V_2 -> V_29 )
return - V_23 ;
memcpy ( V_21 . V_30 , V_24 , V_17 ) ;
if ( F_6 ( V_3 , & V_28 , V_8 , V_9 , V_10 , V_11 , V_12 ) < 0 )
return - V_23 ;
if ( ! V_28 )
return - V_23 ;
return V_28 ;
}
int T_3 F_9 ( void )
{
const struct V_1 * V_2 ;
const struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_34 = F_10 ( NULL , V_35 , & V_32 ) ;
if ( ! V_34 )
return - V_36 ;
V_2 = V_32 -> V_37 ;
if ( ! V_2 ) {
F_11 ( L_1 ) ;
goto V_38;
}
if ( V_2 -> V_29 ) {
V_21 . V_30 = F_4 ( V_2 -> V_29 ,
V_2 -> V_26 ) ;
if ( F_12 ( ! V_21 . V_30 ) )
goto V_38;
}
if ( V_2 -> V_25 ) {
V_21 . V_27 = F_4 ( V_2 -> V_25 ,
V_2 -> V_26 ) ;
if ( F_12 ( ! V_21 . V_27 ) )
goto V_39;
}
V_21 . V_2 = V_2 ;
F_13 ( L_2 ) ;
return 0 ;
V_39:
F_14 ( V_21 . V_30 ) ;
V_38:
return - V_23 ;
}
