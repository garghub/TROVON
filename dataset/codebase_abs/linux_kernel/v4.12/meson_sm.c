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
int F_7 ( void * V_24 , unsigned int V_25 , unsigned int V_3 ,
T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_17 ;
int V_19 ;
if ( ! V_21 . V_2 )
return - V_22 ;
if ( ! V_21 . V_2 -> V_26 )
return - V_23 ;
if ( V_25 > V_21 . V_2 -> V_27 )
return - V_23 ;
if ( F_6 ( V_3 , & V_17 , V_8 , V_9 , V_10 , V_11 , V_12 ) < 0 )
return - V_23 ;
if ( V_17 > V_25 )
return - V_23 ;
V_19 = V_17 ;
if ( ! V_17 )
V_17 = V_25 ;
if ( V_24 )
memcpy ( V_24 , V_21 . V_28 , V_17 ) ;
return V_19 ;
}
int F_8 ( void * V_24 , unsigned int V_17 , unsigned int V_3 ,
T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_29 ;
if ( ! V_21 . V_2 )
return - V_22 ;
if ( V_17 > V_21 . V_2 -> V_27 )
return - V_23 ;
if ( ! V_21 . V_2 -> V_30 )
return - V_23 ;
memcpy ( V_21 . V_31 , V_24 , V_17 ) ;
if ( F_6 ( V_3 , & V_29 , V_8 , V_9 , V_10 , V_11 , V_12 ) < 0 )
return - V_23 ;
if ( ! V_29 )
return - V_23 ;
return V_29 ;
}
int T_3 F_9 ( void )
{
const struct V_1 * V_2 ;
const struct V_32 * V_33 ;
struct V_34 * V_35 ;
V_35 = F_10 ( NULL , V_36 , & V_33 ) ;
if ( ! V_35 )
return - V_37 ;
V_2 = V_33 -> V_38 ;
if ( ! V_2 ) {
F_11 ( L_1 ) ;
goto V_39;
}
if ( V_2 -> V_30 ) {
V_21 . V_31 = F_4 ( V_2 -> V_30 ,
V_2 -> V_27 ) ;
if ( F_12 ( ! V_21 . V_31 ) )
goto V_39;
}
if ( V_2 -> V_26 ) {
V_21 . V_28 = F_4 ( V_2 -> V_26 ,
V_2 -> V_27 ) ;
if ( F_12 ( ! V_21 . V_28 ) )
goto V_40;
}
V_21 . V_2 = V_2 ;
F_13 ( L_2 ) ;
return 0 ;
V_40:
F_14 ( V_21 . V_31 ) ;
V_39:
return - V_23 ;
}
