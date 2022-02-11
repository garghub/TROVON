static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 1 ;
if ( ! V_3 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_3 = 0 ;
V_2 -> V_8 = V_9 ;
} else {
V_2 -> V_7 = 3 ;
V_2 -> V_3 = 1 ;
V_2 -> V_8 = V_10 ;
}
V_2 -> V_11 = 1 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 1 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 1 ;
}
int F_2 ( struct V_16 * V_17 , int V_3 )
{
struct V_1 * V_18 = & V_17 -> V_19 ;
struct V_1 * V_20 = & V_17 -> V_21 ;
F_1 ( V_18 , V_3 ) ;
F_1 ( V_20 , V_3 ) ;
V_18 -> V_22 = F_3 ( V_23 ) ;
if ( ! V_18 -> V_22 )
return - V_24 ;
V_18 -> V_25 = F_3 ( V_26 ) ;
if ( ! V_18 -> V_25 )
goto V_27;
V_20 -> V_22 = F_3 ( V_23 ) ;
if ( ! V_20 -> V_22 )
goto V_28;
V_20 -> V_25 = F_3 ( V_26 ) ;
if ( ! V_20 -> V_25 )
goto V_29;
return 0 ;
V_29:
F_4 ( V_20 -> V_22 , V_23 ) ;
V_28:
F_4 ( V_18 -> V_25 , V_26 ) ;
V_27:
F_4 ( V_18 -> V_22 , V_23 ) ;
return - V_24 ;
}
void F_5 ( struct V_16 * V_17 )
{
struct V_1 * V_18 = & V_17 -> V_19 ;
struct V_1 * V_30 = & V_17 -> V_21 ;
F_4 ( V_18 -> V_22 , V_23 ) ;
F_4 ( V_18 -> V_25 , V_26 ) ;
F_4 ( V_30 -> V_22 , V_23 ) ;
F_4 ( V_30 -> V_25 , V_26 ) ;
}
int F_6 ( const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = NULL ;
struct V_35 V_35 ;
struct V_36 * V_37 = NULL ;
int V_38 ;
if ( ! V_17 || ! V_31 || ! V_33 || ! V_34 )
return - V_24 ;
V_37 = F_7 ( F_8 () ) ;
if ( ! V_37 )
return - V_39 ;
memset ( & V_35 , 0 , sizeof( struct V_35 ) ) ;
V_2 = & V_17 -> V_19 ;
V_2 -> V_40 = V_32 ;
V_2 -> V_41 = * V_34 ;
memcpy ( V_2 -> V_22 , V_31 , V_32 ) ;
V_38 = F_9 ( V_2 , & V_35 , V_37 ) ;
if ( ! V_38 ) {
* V_34 = V_2 -> V_41 ;
memcpy ( V_33 , V_2 -> V_25 , * V_34 ) ;
}
return V_38 ;
}
int F_10 ( const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = NULL ;
struct V_35 V_35 ;
struct V_36 * V_37 = NULL ;
int V_38 ;
if ( ! V_17 || ! V_31 || ! V_33 || ! V_34 )
return - V_24 ;
V_37 = F_7 ( F_8 () ) ;
if ( ! V_37 )
return - V_39 ;
memset ( & V_35 , 0 , sizeof( struct V_35 ) ) ;
V_2 = & V_17 -> V_21 ;
memcpy ( V_2 -> V_22 , V_31 , V_32 ) ;
if ( V_2 -> V_7 != 3 )
V_2 -> V_22 [ V_32 ++ ] = 0 ;
V_2 -> V_40 = V_32 ;
V_2 -> V_41 = * V_34 ;
V_38 = F_11 ( V_2 , & V_35 , V_37 ) ;
if ( ! V_38 ) {
* V_34 = V_2 -> V_41 ;
memcpy ( V_33 , V_2 -> V_25 , * V_34 ) ;
}
return V_38 ;
}
int F_12 ( struct V_42 * V_43 )
{
int V_38 ;
struct V_16 * V_17 = F_13 ( V_43 ) ;
V_38 = F_2 ( V_17 , 0 ) ;
return V_38 ;
}
int F_14 ( struct V_42 * V_43 )
{
int V_38 ;
struct V_16 * V_17 = F_13 ( V_43 ) ;
V_38 = F_2 ( V_17 , 1 ) ;
return V_38 ;
}
void F_15 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = F_13 ( V_43 ) ;
F_5 ( V_17 ) ;
}
int F_16 ( struct V_42 * V_43 ,
const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 )
{
int V_38 ;
struct V_16 * V_17 = F_13 ( V_43 ) ;
V_38 = F_6 ( V_31 , V_32 , V_33 , V_34 , V_17 ) ;
return V_38 ;
}
int F_17 ( struct V_42 * V_43 ,
const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 )
{
int V_38 ;
struct V_16 * V_17 = F_13 ( V_43 ) ;
V_38 = F_10 ( V_31 , V_32 , V_33 , V_34 , V_17 ) ;
return V_38 ;
}
void * F_18 ( struct V_44 * V_43 )
{
int V_38 ;
struct V_16 * V_17 ;
V_17 = F_19 ( sizeof( * V_17 ) , V_45 ) ;
if ( ! V_17 )
return F_20 ( - V_24 ) ;
V_38 = F_2 ( V_17 , 0 ) ;
if ( V_38 ) {
F_21 ( V_17 ) ;
return F_20 ( V_38 ) ;
}
return V_17 ;
}
void * F_22 ( struct V_44 * V_43 )
{
int V_38 ;
struct V_16 * V_17 ;
V_17 = F_19 ( sizeof( * V_17 ) , V_45 ) ;
if ( ! V_17 )
return F_20 ( - V_24 ) ;
V_38 = F_2 ( V_17 , 1 ) ;
if ( V_38 ) {
F_21 ( V_17 ) ;
return F_20 ( V_38 ) ;
}
return V_17 ;
}
void F_23 ( struct V_44 * V_43 , void * V_46 )
{
struct V_16 * V_17 = V_46 ;
F_5 ( V_17 ) ;
F_21 ( V_17 ) ;
}
int F_24 ( struct V_44 * V_43 ,
const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 , void * V_46 )
{
int V_38 ;
struct V_16 * V_17 = V_46 ;
V_38 = F_6 ( V_31 , V_32 , V_33 , V_34 , V_17 ) ;
return V_38 ;
}
int F_25 ( struct V_44 * V_43 ,
const T_1 * V_31 , unsigned int V_32 ,
T_1 * V_33 , unsigned int * V_34 , void * V_46 )
{
int V_38 ;
struct V_16 * V_17 = V_46 ;
V_38 = F_10 ( V_31 , V_32 , V_33 , V_34 , V_17 ) ;
return V_38 ;
}
